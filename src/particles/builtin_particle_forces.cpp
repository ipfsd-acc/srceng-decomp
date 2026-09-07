// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: particles/builtin_particle_forces.cpp
// Functions: 24
// ============================================================

#include "particles\builtin_particle_forces.h"

//------------------------------------------------------------------------------
// Address: 0x10226120
// Name: private: virtual void C_OP_RandomForce::AddForces(class FourVectors __near *,class CParticleCollection __near *,int,float,void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_OP_RandomForce::AddForces(
        C_OP_RandomForce *this@<ecx>,
        int a2@<ebp>,
        FourVectors *pAccumulatedForces,
        CParticleCollection *pParticles,
        int nBlocks,
        float flStrength,
        void *pContext)
{
  __m128 v7; // xmm4
  __m128 v8; // xmm1
  __m128 v9; // xmm4
  __m128 v10; // xmm2
  __m128 v11; // xmm4
  __m128 v12; // xmm3
  __m128 v13; // xmm0
  __m128 v14; // xmm4
  __m128 v15; // xmm5
  __m128 v16; // xmm1
  __m128 v17; // xmm0
  __m128 *SIMDRandContext; // edi
  __m128 *p_z; // esi
  __m128 box_min_4; // [esp+4h] [ebp-6Ch]
  __m128 box_min_20; // [esp+14h] [ebp-5Ch]
  __m128 box_max_4; // [esp+34h] [ebp-3Ch]
  __m128 box_max_20; // [esp+44h] [ebp-2Ch]
  int i; // [esp+60h] [ebp-10h]
  _DWORD v25[3]; // [esp+64h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+70h] [ebp+0h]

  v25[0] = a2;
  v25[1] = retaddr;
  v7 = 0;
  v7.m128_f32[0] = this->m_MinForce.x * flStrength;
  v8 = v7;
  v9 = 0;
  v9.m128_f32[0] = this->m_MinForce.y * flStrength;
  v10 = v9;
  v11 = 0;
  v11.m128_f32[0] = this->m_MinForce.z * flStrength;
  v12 = v11;
  v13 = 0;
  v13.m128_f32[0] = this->m_MaxForce.x * flStrength;
  v14 = 0;
  v14.m128_f32[0] = this->m_MaxForce.y * flStrength;
  v15 = 0;
  v15.m128_f32[0] = this->m_MaxForce.z * flStrength;
  v16 = _mm_shuffle_ps(v8, v8, 0);
  v17 = _mm_sub_ps(_mm_shuffle_ps(v13, v13, 0), v16);
  box_min_4 = _mm_shuffle_ps(v10, v10, 0);
  box_min_20 = _mm_shuffle_ps(v12, v12, 0);
  box_max_4 = _mm_sub_ps(_mm_shuffle_ps(v14, v14, 0), box_min_4);
  box_max_20 = _mm_sub_ps(_mm_shuffle_ps(v15, v15, 0), box_min_20);
  SIMDRandContext = (__m128 *)GetSIMDRandContext();
  if ( nBlocks > 0 )
  {
    p_z = &pAccumulatedForces->z;
    for ( i = nBlocks; i != 0; --i )
    {
      RandSIMD(a1: (int)v25, result: SIMDRandContext);
      p_z[-2] = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v17, v17), v16), p_z[-2]);
      RandSIMD(a1: (int)v25, result: SIMDRandContext);
      p_z[-1] = _mm_add_ps(_mm_add_ps(_mm_mul_ps(box_max_4, v17), box_min_4), p_z[-1]);
      RandSIMD(a1: (int)v25, result: SIMDRandContext);
      *p_z = _mm_add_ps(_mm_add_ps(_mm_mul_ps(box_max_20, v17), box_min_20), *p_z);
      p_z += 3;
    }
  }
  ReleaseSIMDRandContext(nContext: (int)SIMDRandContext);
}

//------------------------------------------------------------------------------
// Address: 0x102267D0
// Name: private: virtual void C_OP_ParentVortices::AddForces(class FourVectors __near *,class CParticleCollection __near *,int,float,void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_OP_ParentVortices::AddForces(
        C_OP_ParentVortices *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        FourVectors *pAccumulatedForces,
        CParticleCollection *pParticles,
        int nBlocks,
        float flStrength,
        void *pContext)
{
  CParticleCollection *v9; // edi
  CParticleCollection *m_pParent; // eax
  int m_nActiveParticles; // eax
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm0
  __m128 v16; // xmm4
  __m128 v17; // xmm0
  void *v18; // esp
  unsigned int v19; // esi
  __m128 v20; // xmm6
  __m128 v21; // xmm5
  __m128 v22; // xmm4
  __m128 *v23; // eax
  CParticleCollection *v24; // edx
  unsigned int v25; // ecx
  int v26; // edi
  int v27; // esi
  float v28; // xmm0_4
  __m128 v29; // xmm7
  __m128 v30; // xmm0
  CParticleCollection *v31; // edx
  unsigned int v32; // edi
  float *v33; // edx
  __m128 v34; // xmm7
  CParticleCollection *v35; // edx
  unsigned int v36; // esi
  float *v37; // edx
  unsigned int v38; // esi
  __m128 v39; // xmm0
  float *v40; // edx
  __m128 v41; // xmm0
  C_OP_ParentVortices *v42; // edx
  unsigned int v43; // kr00_4
  __m128 *v44; // edi
  __m128 v46; // xmm0
  int v47; // edx
  __m128 v48; // xmm5
  __m128 v49; // xmm1
  __m128 *v50; // eax
  __m128 v51; // xmm4
  __m128 v52; // xmm0
  __m128 v53; // xmm1
  __m128 v54; // xmm6
  __m128 v55; // xmm7
  __m128 v56; // xmm2
  __m128 v57; // xmm3
  __m128 v58; // xmm2
  __m128 v59; // xmm0
  __m128 v60; // xmm1
  __m128 v61; // xmm3
  __m128 v62; // xmm2
  __m128 v63; // xmm5
  __m128 v64; // xmm3
  __m128 v65; // xmm4
  __m128 v66; // xmm0
  __m128 v67; // xmm2
  __m128 v68; // xmm1
  __m128 v69; // xmm0
  __m128 v70; // xmm1
  __m128 v71; // xmm4
  __m128 v72; // xmm3
  __m128 v73; // xmm0
  __m128 v74; // xmm5
  __m128 v75; // xmm3
  FourVectors *v76; // eax
  __m128 v77; // xmm2
  __m128 z; // xmm0
  bool v79; // zf
  int v80; // [esp-100h] [ebp-10Ch]
  int v81; // [esp-FCh] [ebp-108h]
  __m128 v82; // [esp-F0h] [ebp-FCh]
  int v83; // [esp-C0h] [ebp-CCh] BYREF
  __m128 v84; // [esp-B0h] [ebp-BCh] BYREF
  __m128 v85; // [esp-90h] [ebp-9Ch]
  __m128 v86; // [esp-80h] [ebp-8Ch]
  __m128 v87; // [esp-70h] [ebp-7Ch]
  __m128 v88; // [esp-60h] [ebp-6Ch]
  __m128 v89; // [esp-50h] [ebp-5Ch]
  __m128 v90; // [esp-40h] [ebp-4Ch]
  __m128 v91; // [esp-30h] [ebp-3Ch]
  C_OP_ParentVortices *v92; // [esp-10h] [ebp-1Ch]
  int v93; // [esp-Ch] [ebp-18h]
  int v94; // [esp-8h] [ebp-14h]
  int v95; // [esp-4h] [ebp-10h]
  int v96; // [esp+0h] [ebp-Ch]
  void *v97; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v96 = a2;
  v97 = retaddr;
  v81 = a4;
  v80 = a3;
  v9 = pParticles;
  m_pParent = pParticles->m_pParent;
  v92 = this;
  if ( m_pParent != nullptr )
  {
    m_nActiveParticles = m_pParent->m_nActiveParticles;
    v94 = m_nActiveParticles;
    if ( m_nActiveParticles != 0 )
    {
      v12 = _mm_shuffle_ps((__m128)LODWORD(this->m_vecTwistAxis.x), (__m128)LODWORD(this->m_vecTwistAxis.x), 0);
      v13 = _mm_shuffle_ps((__m128)LODWORD(this->m_vecTwistAxis.y), (__m128)LODWORD(this->m_vecTwistAxis.y), 0);
      v14 = _mm_shuffle_ps((__m128)LODWORD(this->m_vecTwistAxis.z), (__m128)LODWORD(this->m_vecTwistAxis.z), 0);
      v15 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v12, v12), _mm_mul_ps(v13, v13)), _mm_mul_ps(v14, v14));
      v16 = _mm_rsqrt_ps(v15);
      v17 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(Four_Threes, _mm_mul_ps(_mm_mul_ps(v16, v16), v15)), v16), Four_PointFives);
      v89 = _mm_mul_ps(v17, v12);
      v90 = _mm_mul_ps(v13, v17);
      v91 = _mm_mul_ps(v14, v17);
      v18 = alloca(m_nActiveParticles << 7);
      v19 = 0;
      v95 = 0;
      if ( v94 > 0 )
      {
        v20 = v91;
        v21 = v90;
        v22 = v89;
        v23 = &v84;
        do
        {
          v23[-2] = v22;
          v23[-1] = v21;
          *v23 = v20;
          v24 = v9->m_pParent;
          v25 = v19 >> 2;
          v26 = (v19 >> 2) * v24->m_ParticleAttributes.m_nFloatStrides[3];
          v27 = v19 & 3;
          v28 = 1.0 / (v24->m_ParticleAttributes.m_pAttributes[3][v27 + v26] + 0.00001);
          v29 = 0;
          v29.m128_f32[0] = v28;
          v30 = _mm_shuffle_ps(v29, v29, 0);
          v23[1] = _mm_mul_ps(v30, v30);
          v31 = pParticles->m_pParent;
          v32 = v31->m_ParticleAttributes.m_nFloatStrides[7];
          v33 = v31->m_ParticleAttributes.m_pAttributes[7];
          v93 = v27;
          v34 = 0;
          v34.m128_f32[0] = (float)(v92->m_flForceScale * flStrength) * v33[v27 + v25 * v32];
          v23[2] = _mm_shuffle_ps(v34, v34, 0);
          v35 = pParticles->m_pParent;
          v36 = v35->m_ParticleAttributes.m_nFloatStrides[0];
          v37 = v35->m_ParticleAttributes.m_pAttributes[0];
          v38 = v93 + v25 * v36;
          v39 = (__m128)LODWORD(v37[v38]);
          v9 = pParticles;
          v40 = &v37[v38];
          v23[-5] = _mm_shuffle_ps(v39, v39, 0);
          v23[-4] = _mm_shuffle_ps((__m128)*((unsigned int *)v40 + 4), (__m128)*((unsigned int *)v40 + 4), 0);
          v41 = (__m128)*((unsigned int *)v40 + 8);
          v42 = v92;
          v23[-3] = _mm_shuffle_ps(v41, v41, 0);
          if ( v42->m_bFlipBasedOnYaw
            && pParticles->m_pParent->m_ParticleAttributes.m_pAttributes[12][v93
                                                                           + v25
                                                                           * pParticles->m_pParent->m_ParticleAttributes.m_nFloatStrides[12]] >= 3.141592653589793 )
          {
            v23[-5] = _mm_mul_ps(v23[-5], Four_NegativeOnes);
            v23[-4] = _mm_mul_ps(v23[-4], Four_NegativeOnes);
            v23[-3] = _mm_mul_ps(v23[-3], Four_NegativeOnes);
          }
          v19 = v95 + 1;
          v23 += 8;
          v95 = v19;
        }
        while ( (int)v19 < v94 );
      }
      v43 = v9->m_ParticleAttributes.m_nFloatStrides[0];
      v44 = (__m128 *)v9->m_ParticleAttributes.m_pAttributes[0];
      if ( nBlocks > 0 )
      {
        v95 = nBlocks;
        do
        {
          v46 = Four_Zeros;
          v47 = v94;
          v48 = Four_Zeros;
          v49 = Four_Zeros;
          v89 = Four_Zeros;
          v90 = Four_Zeros;
          v91 = Four_Zeros;
          if ( v94 > 0 )
          {
            v87 = *v44;
            v86 = v44[1];
            v85 = v44[2];
            v50 = (__m128 *)&v83;
            do
            {
              v51 = _mm_sub_ps(v87, v50[-4]);
              v52 = _mm_sub_ps(v86, v50[-3]);
              v53 = _mm_sub_ps(v85, v50[-2]);
              v54 = *v50;
              v55 = v50[1];
              v56 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v51, v51), _mm_mul_ps(v52, v52)), _mm_mul_ps(v53, v53));
              v57 = _mm_rsqrt_ps(v56);
              v88 = v56;
              v58 = _mm_mul_ps(
                      _mm_mul_ps(_mm_sub_ps(Four_Threes, _mm_mul_ps(_mm_mul_ps(v57, v57), v56)), v57),
                      Four_PointFives);
              v59 = _mm_mul_ps(v52, v58);
              v60 = _mm_mul_ps(v53, v58);
              v61 = _mm_mul_ps(v58, v51);
              v62 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v59, v54), _mm_mul_ps(v61, v50[-1])), _mm_mul_ps(v60, v55));
              v84 = _mm_mul_ps(v59, v62);
              v63 = _mm_sub_ps(v60, _mm_mul_ps(v60, v62));
              v64 = _mm_sub_ps(v61, _mm_mul_ps(v61, v62));
              v65 = _mm_sub_ps(v59, v84);
              v66 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v64, v64), _mm_mul_ps(v65, v65)), _mm_mul_ps(v63, v63));
              v82 = v64;
              v67 = _mm_and_ps(_mm_cmplt_ps(Four_Epsilons, v66), _mm_cmplt_ps(Four_Epsilons, v88));
              v68 = _mm_rsqrt_ps(v66);
              v69 = _mm_mul_ps(
                      _mm_mul_ps(_mm_sub_ps(Four_Threes, _mm_mul_ps(_mm_mul_ps(v68, v68), v66)), v68),
                      Four_PointFives);
              v70 = _mm_mul_ps(v69, v64);
              v71 = _mm_mul_ps(v65, v69);
              v72 = _mm_mul_ps(v63, v69);
              v73 = _mm_sub_ps(_mm_mul_ps(v71, v55), _mm_mul_ps(v72, v54));
              v74 = _mm_sub_ps(_mm_mul_ps(v72, v50[-1]), _mm_mul_ps(v70, v55));
              v75 = _mm_mul_ps(_mm_max_ps(Four_Zeros, _mm_sub_ps(Four_Ones, _mm_mul_ps(v50[2], v88))), v50[3]);
              v46 = _mm_add_ps(_mm_and_ps(_mm_mul_ps(v73, v75), v67), v89);
              v48 = _mm_add_ps(_mm_and_ps(_mm_mul_ps(v74, v75), v67), v90);
              v49 = _mm_add_ps(
                      _mm_and_ps(_mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v70, v54), _mm_mul_ps(v71, v50[-1])), v75), v67),
                      v91);
              v50 += 8;
              --v47;
              v89 = v46;
              v90 = v48;
              v91 = v49;
            }
            while ( v47 != 0 );
          }
          v76 = pAccumulatedForces;
          v77 = _mm_add_ps(pAccumulatedForces->x, v46);
          pAccumulatedForces->y = _mm_add_ps(pAccumulatedForces->y, v48);
          z = pAccumulatedForces->z;
          ++pAccumulatedForces;
          v44 += 3 * (v43 / 0xC);
          v79 = v95-- == 1;
          v76->x = v77;
          v76->z = _mm_add_ps(z, v49);
        }
        while ( !v79 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10227220
// Name: private: virtual void C_OP_TwistAroundAxis::AddForces(class FourVectors __near *,class CParticleCollection __near *,int,float,void __near *)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge C_OP_TwistAroundAxis::AddForces(
        C_OP_TwistAroundAxis *this@<ecx>,
        int a2@<ebp>,
        FourVectors *pAccumulatedForces,
        CParticleCollection *pParticles,
        int nBlocks,
        float flStrength,
        void *pContext)
{
  Vector *v8; // eax
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm0
  __m128 v13; // xmm4
  __m128 v14; // xmm4
  __m128 *v15; // ecx
  int v16; // edi
  __m128 v17; // xmm1
  unsigned int v19; // esi
  __m128 v20; // xmm7
  __m128 v21; // xmm3
  __m128 v22; // xmm4
  __m128 v23; // xmm2
  __m128 v24; // xmm5
  __m128 v25; // xmm0
  __m128 v26; // xmm0
  __m128 v27; // xmm3
  __m128 v28; // xmm1
  __m128 v29; // xmm7
  __m128 v30; // xmm0
  __m128 v31; // xmm4
  __m128 v32; // xmm1
  __m128 v33; // xmm0
  __m128 v34; // xmm3
  __m128 v35; // xmm2
  __m128 v36; // xmm3
  __m128 v37; // xmm6
  __m128 v38; // xmm2
  __m128 v39; // xmm4
  __m128 v40; // xmm1
  __m128 v41; // xmm5
  FourVectors *v42; // eax
  __m128 v43; // xmm0
  __m128 v44; // xmm1
  __m128 v45; // xmm2
  __m128 z; // xmm0
  float m_flCurTime; // [esp+0h] [ebp-114h]
  __m128 v48; // [esp+18h] [ebp-FCh]
  __m128 ofs; // [esp+48h] [ebp-CCh]
  __m128 parallel_comp; // [esp+88h] [ebp-8Ch]
  __m128 parallel_comp_16; // [esp+98h] [ebp-7Ch]
  __m128 parallel_comp_32; // [esp+A8h] [ebp-6Ch]
  FourVectors Center; // [esp+B8h] [ebp-5Ch] BYREF
  __m128 v54; // [esp+E8h] [ebp-2Ch]
  _BYTE Twist_AxisInWorldSpace_4[20]; // [esp+FCh] [ebp-18h] OVERLAPPED BYREF
  int Twist_AxisInWorldSpace_28; // [esp+114h] [ebp+0h]

  *(_DWORD *)&Twist_AxisInWorldSpace_4[12] = a2;
  *(_DWORD *)&Twist_AxisInWorldSpace_4[16] = Twist_AxisInWorldSpace_28;
  v8 = CParticleCollection::TransformAxis(
         this: pParticles,
         result: (Vector *)&Center.x.m128_i16[2],
         SrcAxis: &this->m_TwistAxis,
         bLocalSpace: this->m_bLocalSpace,
         nControlPointNumber: 0);
  v9 = _mm_shuffle_ps((__m128)LODWORD(v8->x), (__m128)LODWORD(v8->x), 0);
  v10 = _mm_shuffle_ps((__m128)LODWORD(v8->y), (__m128)LODWORD(v8->y), 0);
  v11 = _mm_shuffle_ps((__m128)LODWORD(v8->z), (__m128)LODWORD(v8->z), 0);
  v12 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v10, v10), _mm_mul_ps(v9, v9)), _mm_mul_ps(v11, v11));
  v13 = _mm_rsqrt_ps(v12);
  v14 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(Four_Threes, _mm_mul_ps(_mm_mul_ps(v13, v13), v12)), v13), Four_PointFives);
  m_flCurTime = pParticles->m_flCurTime;
  Center.y = _mm_mul_ps(v14, v9);
  Center.z = _mm_mul_ps(v10, v14);
  v54 = _mm_mul_ps(v11, v14);
  CParticleCollection::GetControlPointAtTime(
    this: pParticles,
    nControlPoint: 0,
    flTime: m_flCurTime,
    pControlPoint: (Vector *)Twist_AxisInWorldSpace_4);
  v15 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  parallel_comp = _mm_shuffle_ps(
                    (__m128)*(unsigned int *)Twist_AxisInWorldSpace_4,
                    (__m128)*(unsigned int *)Twist_AxisInWorldSpace_4,
                    0);
  parallel_comp_16 = _mm_shuffle_ps(
                       (__m128)*(unsigned int *)&Twist_AxisInWorldSpace_4[4],
                       (__m128)*(unsigned int *)&Twist_AxisInWorldSpace_4[4],
                       0);
  parallel_comp_32 = _mm_shuffle_ps(
                       (__m128)*(unsigned int *)&Twist_AxisInWorldSpace_4[8],
                       (__m128)*(unsigned int *)&Twist_AxisInWorldSpace_4[8],
                       0);
  v12.m128_f32[0] = this->m_fForceAmount * flStrength;
  v16 = nBlocks;
  v17 = 0;
  v17.m128_f32[0] = v12.m128_f32[0];
  ofs = _mm_shuffle_ps(v17, v17, 0);
  if ( nBlocks > 0 )
  {
    v19 = 48 * (pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC);
    do
    {
      v20 = _mm_sub_ps(*v15, parallel_comp);
      v21 = _mm_sub_ps(v15[1], parallel_comp_16);
      v22 = _mm_sub_ps(v15[2], parallel_comp_32);
      v23 = _mm_mul_ps(v22, v22);
      v24 = _mm_add_ps(_mm_mul_ps(v20, v20), _mm_mul_ps(v21, v21));
      v25 = _mm_add_ps(v23, v24);
      Center.x = _mm_rsqrt_ps(v25);
      v26 = _mm_mul_ps(
              _mm_mul_ps(_mm_sub_ps(Four_Threes, _mm_mul_ps(_mm_mul_ps(Center.x, Center.x), v25)), Center.x),
              Four_PointFives);
      v27 = _mm_mul_ps(v21, v26);
      v28 = _mm_mul_ps(v26, v20);
      v29 = _mm_mul_ps(v22, v26);
      v30 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v27, Center.z), _mm_mul_ps(v28, Center.y)), _mm_mul_ps(v29, v54));
      v48 = _mm_sub_ps(v28, _mm_mul_ps(v28, v30));
      v31 = _mm_sub_ps(v27, _mm_mul_ps(v27, v30));
      v32 = _mm_sub_ps(v29, _mm_mul_ps(v29, v30));
      v33 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v48, v48), _mm_mul_ps(v31, v31)), _mm_mul_ps(v32, v32));
      v34 = _mm_cmplt_ps(Four_Epsilons, _mm_add_ps(v23, v24));
      v35 = _mm_rsqrt_ps(v33);
      v36 = _mm_and_ps(v34, _mm_cmplt_ps(Four_Epsilons, v33));
      v37 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(Four_Threes, _mm_mul_ps(_mm_mul_ps(v35, v35), v33)), v35), Four_PointFives);
      v38 = _mm_mul_ps(v37, v48);
      v39 = _mm_mul_ps(v31, v37);
      v40 = _mm_mul_ps(v32, v37);
      v41 = _mm_sub_ps(_mm_mul_ps(v40, Center.y), _mm_mul_ps(v54, v38));
      v42 = pAccumulatedForces;
      v43 = _mm_sub_ps(_mm_mul_ps(v39, v54), _mm_mul_ps(v40, Center.z));
      v44 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(Center.z, v38), _mm_mul_ps(v39, Center.y)), ofs);
      v45 = _mm_add_ps(pAccumulatedForces->x, _mm_and_ps(_mm_mul_ps(v43, ofs), v36));
      pAccumulatedForces->y = _mm_add_ps(pAccumulatedForces->y, _mm_and_ps(_mm_mul_ps(v41, ofs), v36));
      z = pAccumulatedForces->z;
      ++pAccumulatedForces;
      v15 = (__m128 *)((char *)v15 + v19);
      --v16;
      v42->x = v45;
      v42->z = _mm_add_ps(z, _mm_and_ps(v44, v36));
    }
    while ( v16 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10227AB0
// Name: private: virtual void C_OP_AttractToControlPoint::AddForces(class FourVectors __near *,class CParticleCollection __near *,int,float,void __near *)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge C_OP_AttractToControlPoint::AddForces(
        C_OP_AttractToControlPoint *this@<ecx>,
        unsigned int a2@<ebp>,
        FourVectors *pAccumulatedForces,
        CParticleCollection *pParticles,
        int nBlocks,
        float flStrength,
        void *pContext)
{
  __m128 v7; // xmm1
  __m128 *v8; // esi
  __m128 v10; // xmm2
  __m128 v11; // xmm3
  __m128 v12; // xmm4
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 v15; // xmm0
  __m128 v16; // xmm0
  __m128 v17; // xmm0
  FourVectors *v18; // eax
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm3
  __m128 v22; // xmm0
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  __m128 v25; // xmm3
  bool v26; // zf
  __m128 v27; // [esp+18h] [ebp-ACh]
  __m128 v28; // [esp+28h] [ebp-9Ch]
  __m128 v29; // [esp+38h] [ebp-8Ch]
  __m128 ofs; // [esp+48h] [ebp-7Ch]
  __m128 ofs_16; // [esp+58h] [ebp-6Ch]
  __m128 ofs_32; // [esp+68h] [ebp-5Ch]
  FourVectors Center; // [esp+78h] [ebp-4Ch] BYREF
  __m128 fForceScale; // [esp+A8h] [ebp-1Ch]
  unsigned __int64 len; // [esp+B8h] [ebp-Ch] OVERLAPPED
  unsigned int len_12; // [esp+C4h] [ebp+0h]

  len = __PAIR64__(len_12, a2);
  v7 = 0;
  v7.m128_i32[0] = COERCE_UNSIGNED_INT(this->m_fForceAmount * flStrength) ^ _mask__NegFloat_;
  fForceScale.m128_i32[2] = (int)(float)(this->m_fFalloffPower * -4.0);
  Center.x = _mm_shuffle_ps(v7, v7, 0);
  CParticleCollection::GetControlPointAtTime(
    this: pParticles,
    nControlPoint: this->m_nControlPointNumber,
    flTime: pParticles->m_flCurTime,
    pControlPoint: (Vector *)&Center.z.m128_u16[4]);
  v8 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  ofs = _mm_shuffle_ps((__m128)Center.z.m128_u32[2], (__m128)Center.z.m128_u32[2], 0);
  ofs_16 = _mm_shuffle_ps((__m128)Center.z.m128_u32[3], (__m128)Center.z.m128_u32[3], 0);
  ofs_32 = _mm_shuffle_ps((__m128)fForceScale.m128_u32[0], (__m128)fForceScale.m128_u32[0], 0);
  if ( nBlocks > 0 )
  {
    fForceScale.m128_i32[1] = 48 * (pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC);
    fForceScale.m128_i32[3] = nBlocks;
    do
    {
      v10 = _mm_sub_ps(*v8, ofs);
      v11 = _mm_sub_ps(v8[1], ofs_16);
      v12 = _mm_sub_ps(v8[2], ofs_32);
      v13 = _mm_sqrt_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v11, v11), _mm_mul_ps(v10, v10)), _mm_mul_ps(v12, v12)));
      v14 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(Four_Zeros, v13), Four_Epsilons), v13);
      Center.y = v13;
      v15 = _mm_rcp_ps(v14);
      v16 = _mm_mul_ps(_mm_sub_ps(_mm_add_ps(v15, v15), _mm_mul_ps(_mm_mul_ps(v15, v15), v14)), Center.x);
      v27 = _mm_mul_ps(v10, v16);
      v28 = _mm_mul_ps(v11, v16);
      v29 = _mm_mul_ps(v12, v16);
      v17 = Pow_FixedPoint_Exponent_SIMD(result: &Center.y, x: (const __m128 *)fForceScale.m128_i32[2]);
      v8 = (__m128 *)((char *)v8 + fForceScale.m128_i32[1]);
      v18 = pAccumulatedForces;
      v19 = _mm_mul_ps(v27, v17);
      v20 = _mm_mul_ps(v28, v17);
      v21 = _mm_mul_ps(v29, v17);
      v22 = _mm_cmplt_ps(Four_Epsilons, Center.y);
      v23 = _mm_add_ps(_mm_and_ps(v19, v22), pAccumulatedForces->x);
      v24 = _mm_add_ps(_mm_and_ps(v20, v22), pAccumulatedForces->y);
      v25 = _mm_add_ps(_mm_and_ps(v21, v22), pAccumulatedForces->z);
      ++pAccumulatedForces;
      v26 = fForceScale.m128_i32[3]-- == 1;
      v18->x = v23;
      v18->y = v24;
      v18->z = v25;
    }
    while ( !v26 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102295F0
// Name: void AddBuiltInParticleForceGenerators(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddBuiltInParticleForceGenerators()
{
  CParticleSystemMgr::AddParticleOperator(
    this: g_pParticleSystemMgr,
    nOpType: FUNCTION_FORCEGENERATOR,
    pOpFactory: (vgui::TreeNode *)&s_C_OP_RandomForceFactory);
  CParticleSystemMgr::AddParticleOperator(
    this: g_pParticleSystemMgr,
    nOpType: FUNCTION_FORCEGENERATOR,
    pOpFactory: (vgui::TreeNode *)&s_C_OP_TwistAroundAxisFactory);
  CParticleSystemMgr::AddParticleOperator(
    this: g_pParticleSystemMgr,
    nOpType: FUNCTION_FORCEGENERATOR,
    pOpFactory: (vgui::TreeNode *)&s_C_OP_ParentVorticesFactory);
  CParticleSystemMgr::AddParticleOperator(
    this: g_pParticleSystemMgr,
    nOpType: FUNCTION_FORCEGENERATOR,
    pOpFactory: (vgui::TreeNode *)&s_C_OP_AttractToControlPointFactory);
  CParticleSystemMgr::AddParticleOperator(
    this: g_pParticleSystemMgr,
    nOpType: FUNCTION_FORCEGENERATOR,
    pOpFactory: (vgui::TreeNode *)&s_C_OP_TimeVaryingForceFactory);
  CParticleSystemMgr::AddParticleOperator(
    this: g_pParticleSystemMgr,
    nOpType: FUNCTION_FORCEGENERATOR,
    pOpFactory: (vgui::TreeNode *)&s_C_OP_TurbulenceForceFactory);
  CParticleSystemMgr::AddParticleOperator(
    this: g_pParticleSystemMgr,
    nOpType: FUNCTION_FORCEGENERATOR,
    pOpFactory: (vgui::TreeNode *)&s_C_OP_ForceBasedOnDistanceToPlaneFactory);
}

//------------------------------------------------------------------------------
// Address: 0x10229670
// Name: private: virtual void C_OP_ForceBasedOnDistanceToPlane::AddForces(class FourVectors __near *,class CParticleCollection __near *,int,float,void __near *)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge C_OP_ForceBasedOnDistanceToPlane::AddForces(
        C_OP_ForceBasedOnDistanceToPlane *this@<ecx>,
        int a2@<ebp>,
        FourVectors *pAccumulatedForces,
        CParticleCollection *pParticles,
        int nBlocks,
        float flStrength,
        void *pContext)
{
  float m_flMinDist; // xmm1_4
  __m128 v8; // xmm3
  float v9; // xmm0_4
  float v10; // xmm0_4
  __m128 v11; // xmm2
  int m_nControlPointNumber; // eax
  CParticleCPInfo *v13; // eax
  float z; // xmm2_4
  float v15; // xmm2_4
  unsigned int v16; // kr00_4
  __m128 v17; // xmm0
  float y; // xmm1_4
  __m128 *v19; // esi
  __m128 v20; // xmm4
  __m128 v21; // xmm0
  __m128 v22; // xmm0
  __m128 v24; // xmm0
  FourVectors *v25; // eax
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm0
  bool v29; // zf
  __m128 v30; // [esp-Ch] [ebp-10Ch]
  __m128 v4Force0_4; // [esp+4h] [ebp-FCh]
  __m128 v4Force0_20; // [esp+14h] [ebp-ECh]
  __m128 v4Force0_36; // [esp+24h] [ebp-DCh]
  __m128 v4PointOnPlane_4; // [esp+34h] [ebp-CCh]
  __m128 v4PointOnPlane_20; // [esp+44h] [ebp-BCh]
  _BYTE v4PointOnPlane_36[144]; // [esp+54h] [ebp-ACh] OVERLAPPED BYREF
  Vector vecPointOnPlane; // [esp+E4h] [ebp-1Ch]
  int v38; // [esp+F0h] [ebp-10h]
  int v39; // [esp+F4h] [ebp-Ch]
  int nPowValue; // [esp+F8h] [ebp-8h]
  int retaddr; // [esp+100h] [ebp+0h]

  v39 = a2;
  nPowValue = retaddr;
  m_flMinDist = this->m_flMinDist;
  v8 = Four_Zeros;
  v9 = this->m_flMaxDist - m_flMinDist;
  *(__m128 *)&v4PointOnPlane_36[112] = Four_Zeros;
  if ( v9 != 0.0 )
  {
    v10 = 1.0 / v9;
    v11 = 0;
    v11.m128_f32[0] = v10;
    *(__m128 *)&v4PointOnPlane_36[112] = _mm_shuffle_ps(v11, v11, 0);
  }
  m_nControlPointNumber = this->m_nControlPointNumber;
  if ( m_nControlPointNumber >= pParticles->m_nNumControlPointsAllocated - 1 )
    m_nControlPointNumber = pParticles->m_nNumControlPointsAllocated - 1;
  v13 = &pParticles->m_pCPInfo[m_nControlPointNumber];
  z = this->m_vecForceAtMaxDist.z;
  *(_QWORD *)&v4PointOnPlane_36[132] = *(_QWORD *)&v13->m_ControlPoint.m_Position.x;
  *(float *)&v4PointOnPlane_36[140] = v13->m_ControlPoint.m_Position.z;
  v15 = z - this->m_vecForceAtMinDist.z;
  v16 = pParticles->m_ParticleAttributes.m_nFloatStrides[0];
  v4Force0_36 = _mm_shuffle_ps(
                  (__m128)*(unsigned int *)&v4PointOnPlane_36[132],
                  (__m128)*(unsigned int *)&v4PointOnPlane_36[132],
                  0);
  v4PointOnPlane_4 = _mm_shuffle_ps(
                       (__m128)*(unsigned int *)&v4PointOnPlane_36[136],
                       (__m128)*(unsigned int *)&v4PointOnPlane_36[136],
                       0);
  v4PointOnPlane_20 = _mm_shuffle_ps(
                        (__m128)*(unsigned int *)&v4PointOnPlane_36[140],
                        (__m128)*(unsigned int *)&v4PointOnPlane_36[140],
                        0);
  *(__m128 *)&v4PointOnPlane_36[64] = _mm_shuffle_ps(
                                        (__m128)LODWORD(this->m_vecPlaneNormal.x),
                                        (__m128)LODWORD(this->m_vecPlaneNormal.x),
                                        0);
  *(__m128 *)&v4PointOnPlane_36[80] = _mm_shuffle_ps(
                                        (__m128)LODWORD(this->m_vecPlaneNormal.y),
                                        (__m128)LODWORD(this->m_vecPlaneNormal.y),
                                        0);
  *(__m128 *)&v4PointOnPlane_36[96] = _mm_shuffle_ps(
                                        (__m128)LODWORD(this->m_vecPlaneNormal.z),
                                        (__m128)LODWORD(this->m_vecPlaneNormal.z),
                                        0);
  v17 = 0;
  v17.m128_f32[0] = m_flMinDist;
  y = this->m_vecForceAtMaxDist.y;
  *(__m128 *)&v4PointOnPlane_36[128] = _mm_shuffle_ps(v17, v17, 0);
  v30 = _mm_shuffle_ps((__m128)LODWORD(this->m_vecForceAtMinDist.x), (__m128)LODWORD(this->m_vecForceAtMinDist.x), 0);
  v4Force0_4 = _mm_shuffle_ps(
                 (__m128)LODWORD(this->m_vecForceAtMinDist.y),
                 (__m128)LODWORD(this->m_vecForceAtMinDist.y),
                 0);
  v19 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  v4Force0_20 = _mm_shuffle_ps(
                  (__m128)LODWORD(this->m_vecForceAtMinDist.z),
                  (__m128)LODWORD(this->m_vecForceAtMinDist.z),
                  0);
  v20 = 0;
  v20.m128_f32[0] = this->m_vecForceAtMaxDist.x - this->m_vecForceAtMinDist.x;
  *(__m128 *)v4PointOnPlane_36 = _mm_shuffle_ps(v20, v20, 0);
  v21 = 0;
  v21.m128_f32[0] = y - this->m_vecForceAtMinDist.y;
  *(__m128 *)&v4PointOnPlane_36[16] = _mm_shuffle_ps(v21, v21, 0);
  v22 = 0;
  v22.m128_f32[0] = v15;
  *(__m128 *)&v4PointOnPlane_36[32] = _mm_shuffle_ps(v22, v22, 0);
  LODWORD(vecPointOnPlane.z) = (int)(float)(this->m_flExponent * 4.0);
  if ( nBlocks > 0 )
  {
    LODWORD(vecPointOnPlane.y) = 48 * (v16 / 0xC);
    v38 = nBlocks;
    while ( 1 )
    {
      *(__m128 *)&v4PointOnPlane_36[48] = _mm_max_ps(
                                            v8,
                                            _mm_min_ps(
                                              Four_Ones,
                                              _mm_mul_ps(
                                                _mm_sub_ps(
                                                  _mm_add_ps(
                                                    _mm_add_ps(
                                                      _mm_mul_ps(
                                                        _mm_sub_ps(v19[1], v4PointOnPlane_4),
                                                        *(__m128 *)&v4PointOnPlane_36[80]),
                                                      _mm_mul_ps(
                                                        _mm_sub_ps(*v19, v4Force0_36),
                                                        *(__m128 *)&v4PointOnPlane_36[64])),
                                                    _mm_mul_ps(
                                                      _mm_sub_ps(v19[2], v4PointOnPlane_20),
                                                      *(__m128 *)&v4PointOnPlane_36[96])),
                                                  *(__m128 *)&v4PointOnPlane_36[128]),
                                                *(__m128 *)&v4PointOnPlane_36[112])));
      v24 = Pow_FixedPoint_Exponent_SIMD(
              result: (__m128 *)&v4PointOnPlane_36[48],
              x: (const __m128 *)LODWORD(vecPointOnPlane.z));
      v19 = (__m128 *)((char *)v19 + LODWORD(vecPointOnPlane.y));
      v25 = pAccumulatedForces;
      v26 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(*(__m128 *)v4PointOnPlane_36, v24), v30), pAccumulatedForces->x);
      v27 = _mm_add_ps(_mm_mul_ps(*(__m128 *)&v4PointOnPlane_36[32], v24), v4Force0_20);
      pAccumulatedForces->y = _mm_add_ps(
                                pAccumulatedForces->y,
                                _mm_add_ps(_mm_mul_ps(*(__m128 *)&v4PointOnPlane_36[16], v24), v4Force0_4));
      v28 = pAccumulatedForces->z;
      ++pAccumulatedForces;
      v29 = v38-- == 1;
      v25->x = v26;
      v25->z = _mm_add_ps(v28, v27);
      if ( v29 )
        break;
      v8 = Four_Zeros;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10229910
// Name: private: virtual void C_OP_TimeVaryingForce::AddForces(class FourVectors __near *,class CParticleCollection __near *,int,float,void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_TimeVaryingForce::AddForces(
        C_OP_TimeVaryingForce *this,
        FourVectors *pAccumulatedForces,
        CParticleCollection *pParticles,
        int nBlocks,
        float flStrength,
        void *pContext)
{
  __m128 v6; // xmm4
  __m128 v7; // xmm4
  __m128 v8; // xmm1
  __m128 v9; // xmm5
  float v10; // xmm2_4
  __m128 v11; // xmm1
  float v12; // xmm3_4
  __m128 v13; // xmm6
  __m128 v14; // xmm0
  __m128 v15; // xmm7
  int v16; // ecx
  __m128 v17; // xmm1
  __m128 *v18; // edx
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  unsigned int v21; // esi
  __m128 *p_z; // eax
  __m128 v23; // xmm0
  __m128 v24; // xmm1
  __m128 v25; // xmm0
  __m128 box_max_4; // [esp+4h] [ebp-5Ch]
  __m128 box_max_20; // [esp+14h] [ebp-4Ch]
  __m128 box_max_36; // [esp+24h] [ebp-3Ch]
  __m128 fl4OODuration_4; // [esp+34h] [ebp-2Ch]
  __m128 fl4StartTime_4; // [esp+44h] [ebp-1Ch]

  v6 = 0;
  v6.m128_f32[0] = this->m_StartingForce.x * flStrength;
  v7 = _mm_shuffle_ps(v6, v6, 0);
  v8 = 0;
  v8.m128_f32[0] = this->m_StartingForce.y * flStrength;
  v9 = _mm_shuffle_ps(v8, v8, 0);
  v10 = this->m_EndingForce.y * flStrength;
  v11 = 0;
  v11.m128_f32[0] = this->m_StartingForce.z * flStrength;
  v12 = this->m_EndingForce.z * flStrength;
  v13 = _mm_shuffle_ps(v11, v11, 0);
  v14 = 0;
  v14.m128_f32[0] = this->m_EndingForce.x * flStrength;
  v15 = _mm_sub_ps(_mm_shuffle_ps(v14, v14, 0), v7);
  fl4OODuration_4 = _mm_shuffle_ps(
                      (__m128)LODWORD(this->m_flStartLerpTime),
                      (__m128)LODWORD(this->m_flStartLerpTime),
                      0);
  v14.m128_f32[0] = this->m_flEndLerpTime - this->m_flStartLerpTime;
  v16 = nBlocks;
  v17 = 0;
  v17.m128_f32[0] = v10;
  box_max_4 = _mm_sub_ps(_mm_shuffle_ps(v17, v17, 0), v9);
  v14.m128_f32[0] = 1.0 / v14.m128_f32[0];
  v18 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[8];
  v19 = 0;
  v20 = 0;
  v20.m128_f32[0] = v14.m128_f32[0];
  v19.m128_f32[0] = v12;
  box_max_36 = _mm_shuffle_ps(v20, v20, 0);
  box_max_20 = _mm_sub_ps(_mm_shuffle_ps(v19, v19, 0), v13);
  fl4StartTime_4 = pParticles->m_fl4CurTime;
  if ( nBlocks > 0 )
  {
    v21 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[8] >> 2);
    p_z = &pAccumulatedForces->z;
    do
    {
      v23 = _mm_max_ps(
              Four_Zeros,
              _mm_min_ps(
                Four_Ones,
                _mm_mul_ps(_mm_sub_ps(_mm_sub_ps(fl4StartTime_4, *v18), fl4OODuration_4), box_max_36)));
      p_z[-1] = _mm_add_ps(p_z[-1], _mm_add_ps(_mm_mul_ps(box_max_4, v23), v9));
      v24 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v15, v23), v7), p_z[-2]);
      v25 = _mm_add_ps(*p_z, _mm_add_ps(_mm_mul_ps(box_max_20, v23), v13));
      p_z[-2] = v24;
      *p_z = v25;
      p_z += 3;
      v18 = (__m128 *)((char *)v18 + v21);
      --v16;
    }
    while ( v16 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10229AA0
// Name: private: virtual void C_OP_TurbulenceForce::AddForces(class FourVectors __near *,class CParticleCollection __near *,int,float,void __near *)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge C_OP_TurbulenceForce::AddForces(
        C_OP_TurbulenceForce *this@<ecx>,
        int a2@<ebp>,
        FourVectors *pAccumulatedForces,
        CParticleCollection *pParticles,
        int nBlocks,
        float flStrength,
        void *pContext)
{
  __m128 *v8; // ecx
  __m128 *v9; // esi
  float *m_flNoiseCoordScale; // edx
  float *p_z; // eax
  const FourVectors *m_pData; // edi
  bool v13; // zf
  int *v15; // edi
  __m128 v16; // xmm1
  __m128 v17; // xmm0
  FourVectors *v18; // eax
  __m128 x; // xmm0
  __m128 v20; // xmm2
  __m128 v21; // xmm1
  __m128 v22; // xmm1
  __m128 v23; // xmm0
  __m128 v24; // xmm0
  __m128 v25; // xmm3
  __m128 y; // xmm1
  __m128 v27; // xmm1
  FourVectors v4Amounts[4]; // [esp+0h] [ebp-190h] BYREF
  _BYTE v29[12]; // [esp+E4h] [ebp-ACh] BYREF
  _BYTE fl4Scales_52[48]; // [esp+124h] [ebp-6Ch] OVERLAPPED BYREF
  int v31; // [esp+160h] [ebp-30h]
  int v32; // [esp+164h] [ebp-2Ch]
  __m128 *v33; // [esp+168h] [ebp-28h]
  unsigned int v34; // [esp+16Ch] [ebp-24h]
  int v35; // [esp+170h] [ebp-20h]
  C4VAttributeIterator pXYZ; // [esp+174h] [ebp-1Ch]
  int v37; // [esp+184h] [ebp-Ch]
  void *v38; // [esp+188h] [ebp-8h]
  void *retaddr; // [esp+190h] [ebp+0h]

  v37 = a2;
  v38 = retaddr;
  v8 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  v34 = pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC;
  pXYZ.m_pData = (const FourVectors *)v29;
  v33 = v8;
  v9 = (__m128 *)&v4Amounts[0].y.m128_i16[2];
  m_flNoiseCoordScale = this->m_flNoiseCoordScale;
  p_z = &this->m_vecNoiseAmount[0].z;
  v35 = 4;
  do
  {
    m_pData = pXYZ.m_pData;
    pXYZ.m_pData->x = _mm_shuffle_ps(
                        (__m128)*(unsigned int *)m_flNoiseCoordScale,
                        (__m128)*(unsigned int *)m_flNoiseCoordScale,
                        0);
    v9[-2] = _mm_shuffle_ps((__m128)*((unsigned int *)p_z - 2), (__m128)*((unsigned int *)p_z - 2), 0);
    v9[-1] = _mm_shuffle_ps((__m128)*((unsigned int *)p_z - 1), (__m128)*((unsigned int *)p_z - 1), 0);
    *v9 = _mm_shuffle_ps((__m128)*(unsigned int *)p_z, (__m128)*(unsigned int *)p_z, 0);
    ++m_flNoiseCoordScale;
    p_z += 3;
    v9 += 3;
    v13 = v35-- == 1;
    pXYZ.m_pData = (const FourVectors *)&m_pData->y;
  }
  while ( !v13 );
  if ( nBlocks > 0 )
  {
    v31 = 48 * v34;
    v32 = nBlocks;
    while ( 1 )
    {
      pXYZ.m_pData = (const FourVectors *)v29;
      v15 = &v4Amounts[0].y.m128_i32[1];
      v35 = 4;
      while ( 1 )
      {
        v16 = _mm_mul_ps(pXYZ.m_pData->x, v8[1]);
        v17 = _mm_mul_ps(pXYZ.m_pData->x, v8[2]);
        *(__m128 *)fl4Scales_52 = _mm_mul_ps(pXYZ.m_pData->x, *v8);
        *(__m128 *)&fl4Scales_52[16] = v16;
        *(__m128 *)&fl4Scales_52[32] = v17;
        v18 = DNoiseSIMD(result: (FourVectors *)&v4Amounts[3].z.m128_i16[2], pos: (const FourVectors *)fl4Scales_52);
        x = v18->x;
        v20 = *((__m128 *)v15 - 1);
        v21 = *((__m128 *)v15 - 2);
        pXYZ.m_pData = (const FourVectors *)((char *)pXYZ.m_pData + 16);
        *(__m128 *)fl4Scales_52 = x;
        v22 = _mm_mul_ps(v21, x);
        v23 = *(__m128 *)v15;
        *(__m128 *)&fl4Scales_52[16] = v18->y;
        v24 = _mm_add_ps(_mm_mul_ps(v23, v18->z), pAccumulatedForces->z);
        v25 = _mm_add_ps(pAccumulatedForces->x, v22);
        y = pAccumulatedForces->y;
        v15 += 12;
        v13 = v35-- == 1;
        v27 = _mm_add_ps(y, _mm_mul_ps(v20, *(__m128 *)&fl4Scales_52[16]));
        pAccumulatedForces->x = v25;
        pAccumulatedForces->y = v27;
        pAccumulatedForces->z = v24;
        if ( v13 )
          break;
        v8 = v33;
      }
      v33 = (__m128 *)((char *)v33 + v31);
      ++pAccumulatedForces;
      if ( --v32 == 0 )
        break;
      v8 = v33;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10229CB0
// Name: private: virtual unsigned __int64 C_OP_ForceBasedOnDistanceToPlane::GetReadControlPointMask(void)const
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall C_OP_ForceBasedOnDistanceToPlane::GetReadControlPointMask(C_OP_ForceBasedOnDistanceToPlane *this)
{
  return 1LL << this->m_nControlPointNumber;
}

//------------------------------------------------------------------------------
// Address: 0x10289020
// Name: private: virtual unsigned __int64 C_OP_AttractToControlPoint::GetReadControlPointMask(void)const
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall C_OP_AttractToControlPoint::GetReadControlPointMask(C_OP_RemapControlPointDirectionToVector *this)
{
  return 1LL << this->m_nControlPointNumber;
}

//------------------------------------------------------------------------------
// Address: 0x105C2D10
// Name: C_OP_RandomForce_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *C_OP_RandomForce_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<C_OP_RandomForce>(__formal: nullptr);
  s_pUnpack_11 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C2D30
// Name: C_OP_ParentVortices_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *C_OP_ParentVortices_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<C_OP_ParentVortices>(__formal: nullptr);
  s_pUnpack_7 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C2D50
// Name: C_OP_TwistAroundAxis_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *C_OP_TwistAroundAxis_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<C_OP_TwistAroundAxis>(__formal: nullptr);
  s_pUnpack_9 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C2D70
// Name: C_OP_AttractToControlPoint_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *C_OP_AttractToControlPoint_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<C_OP_AttractToControlPoint>(__formal: nullptr);
  s_pUnpack_13 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C2D90
// Name: C_OP_ForceBasedOnDistanceToPlane_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *C_OP_ForceBasedOnDistanceToPlane_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<C_OP_ForceBasedOnDistanceToPlane>(__formal: nullptr);
  s_pUnpack_12 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C2DB0
// Name: C_OP_TimeVaryingForce_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *C_OP_TimeVaryingForce_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<C_OP_TimeVaryingForce>(__formal: nullptr);
  s_pUnpack_10 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105C2DD0
// Name: C_OP_TurbulenceForce_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *C_OP_TurbulenceForce_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<C_OP_TurbulenceForce>(__formal: nullptr);
  s_pUnpack_8 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10226270
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class C_OP_RandomForce>(class C_OP_RandomForce __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<C_OP_RandomForce>()
{
  if ( (_S2_12 & 1) == 0 )
  {
    _S2_12 |= 1u;
    dword_1073D558 = 3;
    dword_1073D55C = 4;
    dword_1073D560 = 4;
    dword_1073D564 = -1;
    dword_1073D568 = 0;
    dword_1073D56C = 0;
    dword_1073D570 = 0;
    dword_1073D574 = 0;
    dword_1073D578 = 0;
    dword_1073D57C = (int)"operator end fadein";
    dword_1073D580 = (int)"0";
    dword_1073D584 = 3;
    dword_1073D588 = 8;
    dword_1073D58C = 4;
    dword_1073D590 = -1;
    dword_1073D594 = 0;
    dword_1073D598 = 0;
    dword_1073D59C = 0;
    dword_1073D5A0 = 0;
    dword_1073D5A4 = 0;
    dword_1073D5A8 = (int)"operator start fadeout";
    dword_1073D5AC = (int)"0";
    dword_1073D5B0 = 3;
    dword_1073D5B4 = 12;
    dword_1073D5B8 = 4;
    dword_1073D5BC = -1;
    dword_1073D5C0 = 0;
    dword_1073D5C4 = 0;
    dword_1073D5C8 = 0;
    dword_1073D5CC = 0;
    dword_1073D5D0 = 0;
    dword_1073D5D4 = (int)"operator end fadeout";
    dword_1073D5D8 = (int)"0";
    dword_1073D5DC = 3;
    dword_1073D5E0 = 16;
    dword_1073D5E4 = 4;
    dword_1073D5E8 = -1;
    dword_1073D5EC = 0;
    dword_1073D5F0 = 0;
    dword_1073D5F4 = 0;
    dword_1073D5F8 = 0;
    dword_1073D5FC = 0;
    dword_1073D600 = (int)"operator fade oscillate";
    dword_1073D604 = (int)"0";
    dword_1073D608 = 3;
    dword_1073D60C = 20;
    dword_1073D610 = 4;
    dword_1073D614 = -1;
    dword_1073D618 = 0;
    dword_1073D61C = 0;
    dword_1073D620 = 0;
    dword_1073D624 = 0;
    dword_1073D628 = 0;
    dword_1073D62C = (int)"operator time offset seed";
    dword_1073D630 = (int)"0";
    dword_1073D634 = 2;
    dword_1073D638 = 32;
    dword_1073D63C = 4;
    dword_1073D640 = -1;
    dword_1073D644 = 0;
    dword_1073D648 = 0;
    dword_1073D64C = 0;
    dword_1073D650 = 0;
    dword_1073D654 = 0;
    dword_1073D658 = (int)"operator time offset min";
    dword_1073D65C = (int)"0";
    dword_1073D660 = 3;
    dword_1073D664 = 24;
    dword_1073D668 = 4;
    dword_1073D66C = -1;
    dword_1073D670 = 0;
    dword_1073D688 = (int)"0";
    dword_1073D6B4 = (int)"0";
    dword_1073D6B8 = 2;
    dword_1073D764 = (int)"0";
    dword_1073D674 = 0;
    dword_1073D678 = 0;
    dword_1073D67C = 0;
    dword_1073D680 = 0;
    dword_1073D684 = (int)"operator time offset max";
    dword_1073D68C = 3;
    dword_1073D690 = 28;
    dword_1073D694 = 4;
    dword_1073D698 = -1;
    dword_1073D69C = 0;
    dword_1073D6A0 = 0;
    dword_1073D6A4 = 0;
    dword_1073D6A8 = 0;
    dword_1073D6AC = 0;
    dword_1073D6B0 = (int)"operator time scale seed";
    dword_1073D6BC = 48;
    dword_1073D6C0 = 4;
    dword_1073D6C4 = -1;
    dword_1073D6C8 = 0;
    dword_1073D6CC = 0;
    dword_1073D6D0 = 0;
    dword_1073D6D4 = 0;
    dword_1073D6D8 = 0;
    dword_1073D6DC = (int)"operator time scale min";
    dword_1073D6E0 = (int)"1";
    dword_1073D6E4 = 3;
    dword_1073D6E8 = 52;
    dword_1073D6EC = 4;
    dword_1073D6F0 = -1;
    dword_1073D6F4 = 0;
    dword_1073D6F8 = 0;
    dword_1073D6FC = 0;
    dword_1073D700 = 0;
    dword_1073D704 = 0;
    dword_1073D708 = (int)"operator time scale max";
    dword_1073D70C = (int)"1";
    dword_1073D710 = 3;
    dword_1073D714 = 56;
    dword_1073D718 = 4;
    dword_1073D71C = -1;
    dword_1073D720 = 0;
    dword_1073D724 = 0;
    dword_1073D728 = 0;
    dword_1073D72C = 0;
    dword_1073D730 = 0;
    dword_1073D734 = (int)"operator time strength random scale max";
    dword_1073D738 = (int)"1";
    dword_1073D73C = 3;
    dword_1073D740 = 44;
    dword_1073D744 = 4;
    dword_1073D748 = -1;
    dword_1073D74C = 0;
    dword_1073D750 = 0;
    dword_1073D754 = 0;
    dword_1073D758 = 0;
    dword_1073D75C = 0;
    dword_1073D760 = (int)"operator strength scale seed";
    dword_1073D768 = 2;
    dword_1073D76C = 36;
    dword_1073D770 = 4;
    dword_1073D774 = -1;
    dword_1073D778 = 0;
    dword_1073D77C = 0;
    dword_1073D780 = 0;
    dword_1073D784 = 0;
    dword_1073D788 = 0;
    dword_1073D78C = (int)"operator strength random scale min";
    dword_1073D790 = (int)"1";
    dword_1073D794 = 3;
    dword_1073D798 = 40;
    dword_1073D79C = 4;
    dword_1073D7A0 = -1;
    dword_1073D7A4 = 0;
    dword_1073D7A8 = 0;
    dword_1073D7AC = 0;
    dword_1073D7EC = 2;
    dword_1073D7C0 = 3;
    dword_1073D814 = (int)"0 0 0";
    dword_1073D840 = (int)"0 0 0";
    dword_1073D7C8 = 4;
    dword_1073D7F4 = 4;
    dword_1073D818 = 10;
    dword_1073D844 = 10;
    dword_1073D7BC = (int)"1";
    dword_1073D7B0 = 0;
    dword_1073D7B4 = 0;
    dword_1073D7B8 = (int)"operator strength random scale max";
    dword_1073D7C4 = 44;
    dword_1073D7CC = -1;
    dword_1073D7D0 = 0;
    dword_1073D7D4 = 0;
    dword_1073D7D8 = 0;
    dword_1073D7DC = 0;
    dword_1073D7E0 = 0;
    dword_1073D7E4 = (int)"operator end cap state";
    dword_1073D7E8 = (int)"-1";
    dword_1073D7F0 = 64;
    dword_1073D7F8 = -1;
    dword_1073D7FC = 0;
    dword_1073D800 = 0;
    dword_1073D804 = 0;
    dword_1073D808 = 0;
    dword_1073D80C = 0;
    dword_1073D810 = (int)"min force";
    dword_1073D81C = 88;
    dword_1073D820 = 12;
    dword_1073D824 = -1;
    dword_1073D828 = 0;
    dword_1073D82C = 0;
    dword_1073D830 = 0;
    dword_1073D834 = 0;
    dword_1073D838 = 0;
    dword_1073D83C = (int)"max force";
    dword_1073D848 = 100;
    dword_1073D84C = 12;
    dword_1073D850 = -1;
    dword_1073D854 = 0;
    dword_1073D858 = 0;
    dword_1073D85C = 0;
    dword_1073D860 = 0;
    dword_1073D864 = 0;
    dword_1073D868 = 0;
    dword_1073D86C = 0;
    dword_1073D870 = 0;
    dword_1073D874 = 0;
    dword_1073D878 = 0;
    dword_1073D87C = -1;
    dword_1073D880 = 0;
    dword_1073D884 = 0;
    dword_1073D888 = 0;
    dword_1073D88C = 0;
    dword_1073D890 = 0;
  }
  return unpack_7;
}

//------------------------------------------------------------------------------
// Address: 0x10226C80
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class C_OP_ParentVortices>(class C_OP_ParentVortices __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<C_OP_ParentVortices>()
{
  if ( (_S3_5 & 1) == 0 )
  {
    _S3_5 |= 1u;
    dword_1073D8A0 = 3;
    dword_1073D8A4 = 4;
    dword_1073D8A8 = 4;
    dword_1073D8AC = -1;
    dword_1073D8B0 = 0;
    dword_1073D8B4 = 0;
    dword_1073D8B8 = 0;
    dword_1073D8BC = 0;
    dword_1073D8C0 = 0;
    dword_1073D8C4 = (int)"operator end fadein";
    dword_1073D8C8 = (int)"0";
    dword_1073D8CC = 3;
    dword_1073D8D0 = 8;
    dword_1073D8D4 = 4;
    dword_1073D8D8 = -1;
    dword_1073D8DC = 0;
    dword_1073D8E0 = 0;
    dword_1073D8E4 = 0;
    dword_1073D8E8 = 0;
    dword_1073D8EC = 0;
    dword_1073D8F0 = (int)"operator start fadeout";
    dword_1073D8F4 = (int)"0";
    dword_1073D8F8 = 3;
    dword_1073D8FC = 12;
    dword_1073D900 = 4;
    dword_1073D904 = -1;
    dword_1073D908 = 0;
    dword_1073D90C = 0;
    dword_1073D910 = 0;
    dword_1073D914 = 0;
    dword_1073D918 = 0;
    dword_1073D91C = (int)"operator end fadeout";
    dword_1073D920 = (int)"0";
    dword_1073D924 = 3;
    dword_1073D928 = 16;
    dword_1073D92C = 4;
    dword_1073D930 = -1;
    dword_1073D934 = 0;
    dword_1073D938 = 0;
    dword_1073D93C = 0;
    dword_1073D940 = 0;
    dword_1073D944 = 0;
    dword_1073D948 = (int)"operator fade oscillate";
    dword_1073D94C = (int)"0";
    dword_1073D950 = 3;
    dword_1073D954 = 20;
    dword_1073D958 = 4;
    dword_1073D95C = -1;
    dword_1073D960 = 0;
    dword_1073D964 = 0;
    dword_1073D968 = 0;
    dword_1073D96C = 0;
    dword_1073D970 = 0;
    dword_1073D974 = (int)"operator time offset seed";
    dword_1073D978 = (int)"0";
    dword_1073D97C = 2;
    dword_1073D980 = 32;
    dword_1073D984 = 4;
    dword_1073D988 = -1;
    dword_1073D98C = 0;
    dword_1073D990 = 0;
    dword_1073D994 = 0;
    dword_1073D998 = 0;
    dword_1073D99C = 0;
    dword_1073D9A0 = (int)"operator time offset min";
    dword_1073D9A4 = (int)"0";
    dword_1073D9A8 = 3;
    dword_1073D9AC = 24;
    dword_1073D9B0 = 4;
    dword_1073D9B4 = -1;
    dword_1073D9B8 = 0;
    dword_1073DA00 = 2;
    dword_1073D9BC = 0;
    dword_1073D9C0 = 0;
    dword_1073D9C4 = 0;
    dword_1073D9C8 = 0;
    dword_1073D9CC = (int)"operator time offset max";
    dword_1073D9D0 = (int)"0";
    dword_1073D9D4 = 3;
    dword_1073D9D8 = 28;
    dword_1073D9DC = 4;
    dword_1073D9E0 = -1;
    dword_1073D9E4 = 0;
    dword_1073D9E8 = 0;
    dword_1073D9EC = 0;
    dword_1073D9F0 = 0;
    dword_1073D9F4 = 0;
    dword_1073D9F8 = (int)"operator time scale seed";
    dword_1073D9FC = (int)"0";
    dword_1073DA04 = 48;
    dword_1073DA08 = 4;
    dword_1073DA0C = -1;
    dword_1073DA10 = 0;
    dword_1073DA14 = 0;
    dword_1073DA18 = 0;
    dword_1073DA1C = 0;
    dword_1073DA20 = 0;
    dword_1073DA24 = (int)"operator time scale min";
    dword_1073DA28 = (int)"1";
    dword_1073DA2C = 3;
    dword_1073DA30 = 52;
    dword_1073DA34 = 4;
    dword_1073DA38 = -1;
    dword_1073DA3C = 0;
    dword_1073DA40 = 0;
    dword_1073DA44 = 0;
    dword_1073DA48 = 0;
    dword_1073DA4C = 0;
    dword_1073DA50 = (int)"operator time scale max";
    dword_1073DA54 = (int)"1";
    dword_1073DA58 = 3;
    dword_1073DA5C = 56;
    dword_1073DA60 = 4;
    dword_1073DA64 = -1;
    dword_1073DA68 = 0;
    dword_1073DA6C = 0;
    dword_1073DA70 = 0;
    dword_1073DA74 = 0;
    dword_1073DA78 = 0;
    dword_1073DA7C = (int)"operator time strength random scale max";
    dword_1073DA80 = (int)"1";
    dword_1073DA84 = 3;
    dword_1073DA88 = 44;
    dword_1073DA8C = 4;
    dword_1073DA90 = -1;
    dword_1073DA94 = 0;
    dword_1073DA98 = 0;
    dword_1073DA9C = 0;
    dword_1073DAA0 = 0;
    dword_1073DAA4 = 0;
    dword_1073DAA8 = (int)"operator strength scale seed";
    dword_1073DAAC = (int)"0";
    dword_1073DAB0 = 2;
    dword_1073DAB4 = 36;
    dword_1073DAB8 = 4;
    dword_1073DABC = -1;
    dword_1073DAC0 = 0;
    dword_1073DAC4 = 0;
    dword_1073DAC8 = 0;
    dword_1073DACC = 0;
    dword_1073DAD0 = 0;
    dword_1073DAD4 = (int)"operator strength random scale min";
    dword_1073DAD8 = (int)"1";
    dword_1073DADC = 3;
    dword_1073DAE0 = 40;
    dword_1073DAE4 = 4;
    dword_1073DAE8 = -1;
    dword_1073DAEC = 0;
    dword_1073DAF0 = 0;
    dword_1073DAF4 = 0;
    dword_1073DAF8 = 0;
    dword_1073DB5C = (int)"0";
    dword_1073DBB4 = (int)"0";
    dword_1073DB08 = 3;
    dword_1073DB60 = 3;
    dword_1073DB04 = (int)"1";
    dword_1073DAFC = 0;
    dword_1073DB00 = (int)"operator strength random scale max";
    dword_1073DB0C = 44;
    dword_1073DB10 = 4;
    dword_1073DB14 = -1;
    dword_1073DB18 = 0;
    dword_1073DB1C = 0;
    dword_1073DB20 = 0;
    dword_1073DB24 = 0;
    dword_1073DB28 = 0;
    dword_1073DB2C = (int)"operator end cap state";
    dword_1073DB30 = (int)"-1";
    dword_1073DB34 = 2;
    dword_1073DB38 = 64;
    dword_1073DB3C = 4;
    dword_1073DB40 = -1;
    dword_1073DB44 = 0;
    dword_1073DB48 = 0;
    dword_1073DB4C = 0;
    dword_1073DB50 = 0;
    dword_1073DB54 = 0;
    dword_1073DB58 = (int)"amount of force";
    dword_1073DB64 = 88;
    dword_1073DB68 = 4;
    dword_1073DB6C = -1;
    dword_1073DB70 = 0;
    dword_1073DB74 = 0;
    dword_1073DB78 = 0;
    dword_1073DB7C = 0;
    dword_1073DB80 = 0;
    dword_1073DB84 = (int)"twist axis";
    dword_1073DB88 = (int)"0 0 1";
    dword_1073DB8C = 10;
    dword_1073DB90 = 92;
    dword_1073DB94 = 12;
    dword_1073DB98 = -1;
    dword_1073DB9C = 0;
    dword_1073DBA0 = 0;
    dword_1073DBA4 = 0;
    dword_1073DBA8 = 0;
    dword_1073DBAC = 0;
    dword_1073DBB0 = (int)"flip twist axis with yaw";
    dword_1073DBB8 = 4;
    dword_1073DBBC = 104;
    dword_1073DBC0 = 1;
    dword_1073DBC4 = -1;
    dword_1073DBC8 = 0;
    dword_1073DBCC = 0;
    dword_1073DBD0 = 0;
    dword_1073DBD4 = 0;
    dword_1073DBD8 = 0;
    dword_1073DBDC = 0;
    dword_1073DBE0 = 0;
    dword_1073DBE4 = 0;
    dword_1073DBE8 = 0;
    dword_1073DBEC = 0;
    dword_1073DBF0 = -1;
    dword_1073DBF4 = 0;
    dword_1073DBF8 = 0;
    dword_1073DBFC = 0;
    dword_1073DC00 = 0;
    dword_1073DC04 = 0;
  }
  return unpack_8;
}

//------------------------------------------------------------------------------
// Address: 0x10227510
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class C_OP_TwistAroundAxis>(class C_OP_TwistAroundAxis __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<C_OP_TwistAroundAxis>()
{
  if ( (_S4_2 & 1) == 0 )
  {
    _S4_2 |= 1u;
    dword_1073DC10 = 3;
    dword_1073DC14 = 4;
    dword_1073DC18 = 4;
    dword_1073DC1C = -1;
    dword_1073DC20 = 0;
    dword_1073DC24 = 0;
    dword_1073DC28 = 0;
    dword_1073DC2C = 0;
    dword_1073DC30 = 0;
    dword_1073DC34 = (int)"operator end fadein";
    dword_1073DC38 = (int)"0";
    dword_1073DC3C = 3;
    dword_1073DC40 = 8;
    dword_1073DC44 = 4;
    dword_1073DC48 = -1;
    dword_1073DC4C = 0;
    dword_1073DC50 = 0;
    dword_1073DC54 = 0;
    dword_1073DC58 = 0;
    dword_1073DC5C = 0;
    dword_1073DC60 = (int)"operator start fadeout";
    dword_1073DC64 = (int)"0";
    dword_1073DC68 = 3;
    dword_1073DC6C = 12;
    dword_1073DC70 = 4;
    dword_1073DC74 = -1;
    dword_1073DC78 = 0;
    dword_1073DC7C = 0;
    dword_1073DC80 = 0;
    dword_1073DC84 = 0;
    dword_1073DC88 = 0;
    dword_1073DC8C = (int)"operator end fadeout";
    dword_1073DC90 = (int)"0";
    dword_1073DC94 = 3;
    dword_1073DC98 = 16;
    dword_1073DC9C = 4;
    dword_1073DCA0 = -1;
    dword_1073DCA4 = 0;
    dword_1073DCA8 = 0;
    dword_1073DCAC = 0;
    dword_1073DCB0 = 0;
    dword_1073DCB4 = 0;
    dword_1073DCB8 = (int)"operator fade oscillate";
    dword_1073DCBC = (int)"0";
    dword_1073DCC0 = 3;
    dword_1073DCC4 = 20;
    dword_1073DCC8 = 4;
    dword_1073DCCC = -1;
    dword_1073DCD0 = 0;
    dword_1073DCD4 = 0;
    dword_1073DCD8 = 0;
    dword_1073DCDC = 0;
    dword_1073DCE0 = 0;
    dword_1073DCE4 = (int)"operator time offset seed";
    dword_1073DCE8 = (int)"0";
    dword_1073DCEC = 2;
    dword_1073DCF0 = 32;
    dword_1073DCF4 = 4;
    dword_1073DCF8 = -1;
    dword_1073DCFC = 0;
    dword_1073DD00 = 0;
    dword_1073DD04 = 0;
    dword_1073DD08 = 0;
    dword_1073DD0C = 0;
    dword_1073DD10 = (int)"operator time offset min";
    dword_1073DD14 = (int)"0";
    dword_1073DD18 = 3;
    dword_1073DD1C = 24;
    dword_1073DD20 = 4;
    dword_1073DD24 = -1;
    dword_1073DD28 = 0;
    dword_1073DD70 = 2;
    dword_1073DD2C = 0;
    dword_1073DD30 = 0;
    dword_1073DD34 = 0;
    dword_1073DD38 = 0;
    dword_1073DD3C = (int)"operator time offset max";
    dword_1073DD40 = (int)"0";
    dword_1073DD44 = 3;
    dword_1073DD48 = 28;
    dword_1073DD4C = 4;
    dword_1073DD50 = -1;
    dword_1073DD54 = 0;
    dword_1073DD58 = 0;
    dword_1073DD5C = 0;
    dword_1073DD60 = 0;
    dword_1073DD64 = 0;
    dword_1073DD68 = (int)"operator time scale seed";
    dword_1073DD6C = (int)"0";
    dword_1073DD74 = 48;
    dword_1073DD78 = 4;
    dword_1073DD7C = -1;
    dword_1073DD80 = 0;
    dword_1073DD84 = 0;
    dword_1073DD88 = 0;
    dword_1073DD8C = 0;
    dword_1073DD90 = 0;
    dword_1073DD94 = (int)"operator time scale min";
    dword_1073DD98 = (int)"1";
    dword_1073DD9C = 3;
    dword_1073DDA0 = 52;
    dword_1073DDA4 = 4;
    dword_1073DDA8 = -1;
    dword_1073DDAC = 0;
    dword_1073DDB0 = 0;
    dword_1073DDB4 = 0;
    dword_1073DDB8 = 0;
    dword_1073DDBC = 0;
    dword_1073DDC0 = (int)"operator time scale max";
    dword_1073DDC4 = (int)"1";
    dword_1073DDC8 = 3;
    dword_1073DDCC = 56;
    dword_1073DDD0 = 4;
    dword_1073DDD4 = -1;
    dword_1073DDD8 = 0;
    dword_1073DDDC = 0;
    dword_1073DDE0 = 0;
    dword_1073DDE4 = 0;
    dword_1073DDE8 = 0;
    dword_1073DDEC = (int)"operator time strength random scale max";
    dword_1073DDF0 = (int)"1";
    dword_1073DDF4 = 3;
    dword_1073DDF8 = 44;
    dword_1073DDFC = 4;
    dword_1073DE00 = -1;
    dword_1073DE04 = 0;
    dword_1073DE08 = 0;
    dword_1073DE0C = 0;
    dword_1073DE10 = 0;
    dword_1073DE14 = 0;
    dword_1073DE18 = (int)"operator strength scale seed";
    dword_1073DE1C = (int)"0";
    dword_1073DE20 = 2;
    dword_1073DE24 = 36;
    dword_1073DE28 = 4;
    dword_1073DE2C = -1;
    dword_1073DE30 = 0;
    dword_1073DE34 = 0;
    dword_1073DE38 = 0;
    dword_1073DE3C = 0;
    dword_1073DE40 = 0;
    dword_1073DE44 = (int)"operator strength random scale min";
    dword_1073DE48 = (int)"1";
    dword_1073DE4C = 3;
    dword_1073DE50 = 40;
    dword_1073DE54 = 4;
    dword_1073DE58 = -1;
    dword_1073DE5C = 0;
    dword_1073DE60 = 0;
    dword_1073DE64 = 0;
    dword_1073DE68 = 0;
    dword_1073DECC = (int)"0";
    dword_1073DF24 = (int)"0";
    dword_1073DE78 = 3;
    dword_1073DED0 = 3;
    dword_1073DE74 = (int)"1";
    dword_1073DE6C = 0;
    dword_1073DE70 = (int)"operator strength random scale max";
    dword_1073DE7C = 44;
    dword_1073DE80 = 4;
    dword_1073DE84 = -1;
    dword_1073DE88 = 0;
    dword_1073DE8C = 0;
    dword_1073DE90 = 0;
    dword_1073DE94 = 0;
    dword_1073DE98 = 0;
    dword_1073DE9C = (int)"operator end cap state";
    dword_1073DEA0 = (int)"-1";
    dword_1073DEA4 = 2;
    dword_1073DEA8 = 64;
    dword_1073DEAC = 4;
    dword_1073DEB0 = -1;
    dword_1073DEB4 = 0;
    dword_1073DEB8 = 0;
    dword_1073DEBC = 0;
    dword_1073DEC0 = 0;
    dword_1073DEC4 = 0;
    dword_1073DEC8 = (int)"amount of force";
    dword_1073DED4 = 88;
    dword_1073DED8 = 4;
    dword_1073DEDC = -1;
    dword_1073DEE0 = 0;
    dword_1073DEE4 = 0;
    dword_1073DEE8 = 0;
    dword_1073DEEC = 0;
    dword_1073DEF0 = 0;
    dword_1073DEF4 = (int)"twist axis";
    dword_1073DEF8 = (int)"0 0 1";
    dword_1073DEFC = 10;
    dword_1073DF00 = 92;
    dword_1073DF04 = 12;
    dword_1073DF08 = -1;
    dword_1073DF0C = 0;
    dword_1073DF10 = 0;
    dword_1073DF14 = 0;
    dword_1073DF18 = 0;
    dword_1073DF1C = 0;
    dword_1073DF20 = (int)"object local space axis 0/1";
    dword_1073DF28 = 4;
    dword_1073DF2C = 104;
    dword_1073DF30 = 1;
    dword_1073DF34 = -1;
    dword_1073DF38 = 0;
    dword_1073DF3C = 0;
    dword_1073DF40 = 0;
    dword_1073DF44 = 0;
    dword_1073DF48 = 0;
    dword_1073DF4C = 0;
    dword_1073DF50 = 0;
    dword_1073DF54 = 0;
    dword_1073DF58 = 0;
    dword_1073DF5C = 0;
    dword_1073DF60 = -1;
    dword_1073DF64 = 0;
    dword_1073DF68 = 0;
    dword_1073DF6C = 0;
    dword_1073DF70 = 0;
    dword_1073DF74 = 0;
  }
  return unpack_9;
}

//------------------------------------------------------------------------------
// Address: 0x10227C70
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class C_OP_AttractToControlPoint>(class C_OP_AttractToControlPoint __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<C_OP_AttractToControlPoint>()
{
  if ( (_S5_1 & 1) == 0 )
  {
    _S5_1 |= 1u;
    dword_1073DF80 = 3;
    dword_1073DF84 = 4;
    dword_1073DF88 = 4;
    dword_1073DF8C = -1;
    dword_1073DF90 = 0;
    dword_1073DF94 = 0;
    dword_1073DF98 = 0;
    dword_1073DF9C = 0;
    dword_1073DFA0 = 0;
    dword_1073DFA4 = (int)"operator end fadein";
    dword_1073DFA8 = (int)"0";
    dword_1073DFAC = 3;
    dword_1073DFB0 = 8;
    dword_1073DFB4 = 4;
    dword_1073DFB8 = -1;
    dword_1073DFBC = 0;
    dword_1073DFC0 = 0;
    dword_1073DFC4 = 0;
    dword_1073DFC8 = 0;
    dword_1073DFCC = 0;
    dword_1073DFD0 = (int)"operator start fadeout";
    dword_1073DFD4 = (int)"0";
    dword_1073DFD8 = 3;
    dword_1073DFDC = 12;
    dword_1073DFE0 = 4;
    dword_1073DFE4 = -1;
    dword_1073DFE8 = 0;
    dword_1073DFEC = 0;
    dword_1073DFF0 = 0;
    dword_1073DFF4 = 0;
    dword_1073DFF8 = 0;
    dword_1073DFFC = (int)"operator end fadeout";
    dword_1073E000 = (int)"0";
    dword_1073E004 = 3;
    dword_1073E008 = 16;
    dword_1073E00C = 4;
    dword_1073E010 = -1;
    dword_1073E014 = 0;
    dword_1073E018 = 0;
    dword_1073E01C = 0;
    dword_1073E020 = 0;
    dword_1073E024 = 0;
    dword_1073E028 = (int)"operator fade oscillate";
    dword_1073E02C = (int)"0";
    dword_1073E030 = 3;
    dword_1073E034 = 20;
    dword_1073E038 = 4;
    dword_1073E03C = -1;
    dword_1073E040 = 0;
    dword_1073E044 = 0;
    dword_1073E048 = 0;
    dword_1073E04C = 0;
    dword_1073E050 = 0;
    dword_1073E054 = (int)"operator time offset seed";
    dword_1073E058 = (int)"0";
    dword_1073E05C = 2;
    dword_1073E060 = 32;
    dword_1073E064 = 4;
    dword_1073E068 = -1;
    dword_1073E06C = 0;
    dword_1073E070 = 0;
    dword_1073E074 = 0;
    dword_1073E078 = 0;
    dword_1073E07C = 0;
    dword_1073E080 = (int)"operator time offset min";
    dword_1073E084 = (int)"0";
    dword_1073E088 = 3;
    dword_1073E08C = 24;
    dword_1073E090 = 4;
    dword_1073E094 = -1;
    dword_1073E098 = 0;
    dword_1073E0E0 = 2;
    dword_1073E09C = 0;
    dword_1073E0A0 = 0;
    dword_1073E0A4 = 0;
    dword_1073E0A8 = 0;
    dword_1073E0AC = (int)"operator time offset max";
    dword_1073E0B0 = (int)"0";
    dword_1073E0B4 = 3;
    dword_1073E0B8 = 28;
    dword_1073E0BC = 4;
    dword_1073E0C0 = -1;
    dword_1073E0C4 = 0;
    dword_1073E0C8 = 0;
    dword_1073E0CC = 0;
    dword_1073E0D0 = 0;
    dword_1073E0D4 = 0;
    dword_1073E0D8 = (int)"operator time scale seed";
    dword_1073E0DC = (int)"0";
    dword_1073E0E4 = 48;
    dword_1073E0E8 = 4;
    dword_1073E0EC = -1;
    dword_1073E0F0 = 0;
    dword_1073E0F4 = 0;
    dword_1073E0F8 = 0;
    dword_1073E0FC = 0;
    dword_1073E100 = 0;
    dword_1073E104 = (int)"operator time scale min";
    dword_1073E108 = (int)"1";
    dword_1073E10C = 3;
    dword_1073E110 = 52;
    dword_1073E114 = 4;
    dword_1073E118 = -1;
    dword_1073E11C = 0;
    dword_1073E120 = 0;
    dword_1073E124 = 0;
    dword_1073E128 = 0;
    dword_1073E12C = 0;
    dword_1073E130 = (int)"operator time scale max";
    dword_1073E134 = (int)"1";
    dword_1073E138 = 3;
    dword_1073E13C = 56;
    dword_1073E140 = 4;
    dword_1073E144 = -1;
    dword_1073E148 = 0;
    dword_1073E14C = 0;
    dword_1073E150 = 0;
    dword_1073E154 = 0;
    dword_1073E158 = 0;
    dword_1073E15C = (int)"operator time strength random scale max";
    dword_1073E160 = (int)"1";
    dword_1073E164 = 3;
    dword_1073E168 = 44;
    dword_1073E16C = 4;
    dword_1073E170 = -1;
    dword_1073E174 = 0;
    dword_1073E178 = 0;
    dword_1073E17C = 0;
    dword_1073E180 = 0;
    dword_1073E184 = 0;
    dword_1073E188 = (int)"operator strength scale seed";
    dword_1073E18C = (int)"0";
    dword_1073E190 = 2;
    dword_1073E194 = 36;
    dword_1073E198 = 4;
    dword_1073E19C = -1;
    dword_1073E1A0 = 0;
    dword_1073E1A4 = 0;
    dword_1073E1A8 = 0;
    dword_1073E1AC = 0;
    dword_1073E1B0 = 0;
    dword_1073E1B4 = (int)"operator strength random scale min";
    dword_1073E1B8 = (int)"1";
    dword_1073E1BC = 3;
    dword_1073E1C0 = 40;
    dword_1073E1C4 = 4;
    dword_1073E1C8 = -1;
    dword_1073E1CC = 0;
    dword_1073E1D0 = 0;
    dword_1073E1D4 = 0;
    dword_1073E1D8 = 0;
    dword_1073E1E4 = (int)"1";
    dword_1073E23C = (int)"0";
    dword_1073E294 = (int)"0";
    dword_1073E1E8 = 3;
    dword_1073E240 = 3;
    dword_1073E26C = 3;
    dword_1073E214 = 2;
    dword_1073E298 = 2;
    dword_1073E1DC = 0;
    dword_1073E1E0 = (int)"operator strength random scale max";
    dword_1073E1EC = 44;
    dword_1073E1F0 = 4;
    dword_1073E1F4 = -1;
    dword_1073E1F8 = 0;
    dword_1073E1FC = 0;
    dword_1073E200 = 0;
    dword_1073E204 = 0;
    dword_1073E208 = 0;
    dword_1073E20C = (int)"operator end cap state";
    dword_1073E210 = (int)"-1";
    dword_1073E218 = 64;
    dword_1073E21C = 4;
    dword_1073E220 = -1;
    dword_1073E224 = 0;
    dword_1073E228 = 0;
    dword_1073E22C = 0;
    dword_1073E230 = 0;
    dword_1073E234 = 0;
    dword_1073E238 = (int)"amount of force";
    dword_1073E244 = 88;
    dword_1073E248 = 4;
    dword_1073E24C = -1;
    dword_1073E250 = 0;
    dword_1073E254 = 0;
    dword_1073E258 = 0;
    dword_1073E25C = 0;
    dword_1073E260 = 0;
    dword_1073E264 = (int)"falloff power";
    dword_1073E268 = (int)"2";
    dword_1073E270 = 92;
    dword_1073E274 = 4;
    dword_1073E278 = -1;
    dword_1073E27C = 0;
    dword_1073E280 = 0;
    dword_1073E284 = 0;
    dword_1073E288 = 0;
    dword_1073E28C = 0;
    dword_1073E290 = (int)"control point number";
    dword_1073E29C = 96;
    dword_1073E2A0 = 4;
    dword_1073E2A4 = -1;
    dword_1073E2A8 = 0;
    dword_1073E2AC = 0;
    dword_1073E2B0 = 0;
    dword_1073E2B4 = 0;
    dword_1073E2B8 = 0;
    dword_1073E2BC = 0;
    dword_1073E2C0 = 0;
    dword_1073E2C4 = 0;
    dword_1073E2C8 = 0;
    dword_1073E2CC = 0;
    dword_1073E2D0 = -1;
    dword_1073E2D4 = 0;
    dword_1073E2D8 = 0;
    dword_1073E2DC = 0;
    dword_1073E2E0 = 0;
    dword_1073E2E4 = 0;
  }
  return unpack_10;
}

//------------------------------------------------------------------------------
// Address: 0x10228210
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class C_OP_ForceBasedOnDistanceToPlane>(class C_OP_ForceBasedOnDistanceToPlane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<C_OP_ForceBasedOnDistanceToPlane>()
{
  if ( (_S6_1 & 1) == 0 )
  {
    _S6_1 |= 1u;
    dword_1073E2F0 = 3;
    dword_1073E2F4 = 4;
    dword_1073E2F8 = 4;
    dword_1073E2FC = -1;
    dword_1073E300 = 0;
    dword_1073E304 = 0;
    dword_1073E308 = 0;
    dword_1073E30C = 0;
    dword_1073E310 = 0;
    dword_1073E314 = (int)"operator end fadein";
    dword_1073E318 = (int)"0";
    dword_1073E31C = 3;
    dword_1073E320 = 8;
    dword_1073E324 = 4;
    dword_1073E328 = -1;
    dword_1073E32C = 0;
    dword_1073E330 = 0;
    dword_1073E334 = 0;
    dword_1073E338 = 0;
    dword_1073E33C = 0;
    dword_1073E340 = (int)"operator start fadeout";
    dword_1073E344 = (int)"0";
    dword_1073E348 = 3;
    dword_1073E34C = 12;
    dword_1073E350 = 4;
    dword_1073E354 = -1;
    dword_1073E358 = 0;
    dword_1073E35C = 0;
    dword_1073E360 = 0;
    dword_1073E364 = 0;
    dword_1073E368 = 0;
    dword_1073E36C = (int)"operator end fadeout";
    dword_1073E370 = (int)"0";
    dword_1073E374 = 3;
    dword_1073E378 = 16;
    dword_1073E37C = 4;
    dword_1073E380 = -1;
    dword_1073E384 = 0;
    dword_1073E388 = 0;
    dword_1073E38C = 0;
    dword_1073E390 = 0;
    dword_1073E394 = 0;
    dword_1073E398 = (int)"operator fade oscillate";
    dword_1073E39C = (int)"0";
    dword_1073E3A0 = 3;
    dword_1073E3A4 = 20;
    dword_1073E3A8 = 4;
    dword_1073E3AC = -1;
    dword_1073E3B0 = 0;
    dword_1073E3B4 = 0;
    dword_1073E3B8 = 0;
    dword_1073E3BC = 0;
    dword_1073E3C0 = 0;
    dword_1073E3C4 = (int)"operator time offset seed";
    dword_1073E3C8 = (int)"0";
    dword_1073E3CC = 2;
    dword_1073E3D0 = 32;
    dword_1073E3D4 = 4;
    dword_1073E3D8 = -1;
    dword_1073E3DC = 0;
    dword_1073E3E0 = 0;
    dword_1073E3E4 = 0;
    dword_1073E3E8 = 0;
    dword_1073E3EC = 0;
    dword_1073E3F0 = (int)"operator time offset min";
    dword_1073E3F4 = (int)"0";
    dword_1073E3F8 = 3;
    dword_1073E3FC = 24;
    dword_1073E400 = 4;
    dword_1073E404 = -1;
    dword_1073E408 = 0;
    dword_1073E450 = 2;
    dword_1073E40C = 0;
    dword_1073E410 = 0;
    dword_1073E414 = 0;
    dword_1073E418 = 0;
    dword_1073E41C = (int)"operator time offset max";
    dword_1073E420 = (int)"0";
    dword_1073E424 = 3;
    dword_1073E428 = 28;
    dword_1073E42C = 4;
    dword_1073E430 = -1;
    dword_1073E434 = 0;
    dword_1073E438 = 0;
    dword_1073E43C = 0;
    dword_1073E440 = 0;
    dword_1073E444 = 0;
    dword_1073E448 = (int)"operator time scale seed";
    dword_1073E44C = (int)"0";
    dword_1073E454 = 48;
    dword_1073E458 = 4;
    dword_1073E45C = -1;
    dword_1073E460 = 0;
    dword_1073E464 = 0;
    dword_1073E468 = 0;
    dword_1073E46C = 0;
    dword_1073E470 = 0;
    dword_1073E474 = (int)"operator time scale min";
    dword_1073E478 = (int)"1";
    dword_1073E47C = 3;
    dword_1073E480 = 52;
    dword_1073E484 = 4;
    dword_1073E488 = -1;
    dword_1073E48C = 0;
    dword_1073E490 = 0;
    dword_1073E494 = 0;
    dword_1073E498 = 0;
    dword_1073E49C = 0;
    dword_1073E4A0 = (int)"operator time scale max";
    dword_1073E4A4 = (int)"1";
    dword_1073E4A8 = 3;
    dword_1073E4AC = 56;
    dword_1073E4B0 = 4;
    dword_1073E4B4 = -1;
    dword_1073E4B8 = 0;
    dword_1073E4BC = 0;
    dword_1073E4C0 = 0;
    dword_1073E4C4 = 0;
    dword_1073E4C8 = 0;
    dword_1073E4CC = (int)"operator time strength random scale max";
    dword_1073E4D0 = (int)"1";
    dword_1073E4D4 = 3;
    dword_1073E4D8 = 44;
    dword_1073E4DC = 4;
    dword_1073E4E0 = -1;
    dword_1073E4E4 = 0;
    dword_1073E4E8 = 0;
    dword_1073E4EC = 0;
    dword_1073E4F0 = 0;
    dword_1073E4F4 = 0;
    dword_1073E4F8 = (int)"operator strength scale seed";
    dword_1073E4FC = (int)"0";
    dword_1073E500 = 2;
    dword_1073E504 = 36;
    dword_1073E508 = 4;
    dword_1073E50C = -1;
    dword_1073E510 = 0;
    dword_1073E514 = 0;
    dword_1073E518 = 0;
    dword_1073E51C = 0;
    dword_1073E520 = 0;
    dword_1073E524 = (int)"operator strength random scale min";
    dword_1073E528 = (int)"1";
    dword_1073E52C = 3;
    dword_1073E530 = 40;
    dword_1073E534 = 4;
    dword_1073E538 = -1;
    dword_1073E53C = 0;
    dword_1073E540 = 0;
    dword_1073E544 = 0;
    dword_1073E548 = 0;
    dword_1073E54C = 0;
    dword_1073E550 = (int)"operator strength random scale max";
    dword_1073E554 = (int)"1";
    dword_1073E558 = 3;
    dword_1073E55C = 44;
    dword_1073E560 = 4;
    dword_1073E564 = -1;
    dword_1073E568 = 0;
    dword_1073E56C = 0;
    dword_1073E570 = 0;
    dword_1073E574 = 0;
    dword_1073E578 = 0;
    dword_1073E57C = (int)"operator end cap state";
    dword_1073E580 = (int)"-1";
    dword_1073E584 = 2;
    dword_1073E588 = 64;
    dword_1073E58C = 4;
    dword_1073E590 = -1;
    dword_1073E594 = 0;
    dword_1073E598 = 0;
    dword_1073E59C = 0;
    dword_1073E5A0 = 0;
    dword_1073E5A4 = 0;
    dword_1073E5A8 = (int)"Min distance from plane";
    dword_1073E5AC = (int)"0";
    dword_1073E5B0 = 3;
    dword_1073E5B4 = 88;
    dword_1073E5B8 = 4;
    dword_1073E5BC = -1;
    dword_1073E5C0 = 0;
    dword_1073E5C4 = 0;
    dword_1073E5C8 = 0;
    dword_1073E5CC = 0;
    dword_1073E5D0 = 0;
    dword_1073E5D4 = (int)"Force at Min distance";
    dword_1073E5D8 = (int)"0 0 0";
    dword_1073E5DC = 10;
    dword_1073E5E0 = 92;
    dword_1073E5E4 = 12;
    dword_1073E5E8 = -1;
    dword_1073E5EC = 0;
    dword_1073E5F0 = 0;
    dword_1073E5F4 = 0;
    dword_1073E5F8 = 0;
    dword_1073E5FC = 0;
    dword_1073E600 = (int)"Max Distance from plane";
    dword_1073E604 = (int)"1";
    dword_1073E608 = 3;
    dword_1073E60C = 104;
    dword_1073E610 = 4;
    dword_1073E614 = -1;
    dword_1073E618 = 0;
    dword_1073E61C = 0;
    dword_1073E620 = 0;
    dword_1073E624 = 0;
    dword_1073E628 = 0;
    dword_1073E62C = (int)"Force at Max distance";
    dword_1073E630 = (int)"0 0 0";
    dword_1073E634 = 10;
    dword_1073E638 = 108;
    dword_1073E63C = 12;
    dword_1073E640 = -1;
    dword_1073E644 = 0;
    dword_1073E648 = 0;
    dword_1073E64C = 0;
    dword_1073E650 = 0;
    dword_1073E654 = 0;
    dword_1073E658 = (int)"Plane Normal";
    dword_1073E65C = (int)"0 0 1";
    dword_1073E660 = 10;
    dword_1073E664 = 120;
    dword_1073E668 = 12;
    dword_1073E66C = -1;
    dword_1073E670 = 0;
    dword_1073E674 = 0;
    dword_1073E678 = 0;
    dword_1073E67C = 0;
    dword_1073E680 = 0;
    dword_1073E684 = (int)"Control point number";
    dword_1073E688 = (int)"0";
    dword_1073E68C = 2;
    dword_1073E6B8 = 3;
    dword_1073E6B4 = (int)"1";
    dword_1073E690 = 132;
    dword_1073E694 = 4;
    dword_1073E698 = -1;
    dword_1073E69C = 0;
    dword_1073E6A0 = 0;
    dword_1073E6A4 = 0;
    dword_1073E6A8 = 0;
    dword_1073E6AC = 0;
    dword_1073E6B0 = (int)"Exponent";
    dword_1073E6BC = 136;
    dword_1073E6C0 = 4;
    dword_1073E6C4 = -1;
    dword_1073E6C8 = 0;
    dword_1073E6CC = 0;
    dword_1073E6D0 = 0;
    dword_1073E6D4 = 0;
    dword_1073E6D8 = 0;
    dword_1073E6DC = 0;
    dword_1073E6E0 = 0;
    dword_1073E6E4 = 0;
    dword_1073E6E8 = 0;
    dword_1073E6EC = 0;
    dword_1073E6F0 = -1;
    dword_1073E6F4 = 0;
    dword_1073E6F8 = 0;
    dword_1073E6FC = 0;
    dword_1073E700 = 0;
    dword_1073E704 = 0;
  }
  return unpack_11;
}

//------------------------------------------------------------------------------
// Address: 0x102288E0
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class C_OP_TimeVaryingForce>(class C_OP_TimeVaryingForce __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<C_OP_TimeVaryingForce>()
{
  if ( (_S7_0 & 1) == 0 )
  {
    _S7_0 |= 1u;
    dword_1073E710 = 3;
    dword_1073E714 = 4;
    dword_1073E718 = 4;
    dword_1073E71C = -1;
    dword_1073E720 = 0;
    dword_1073E724 = 0;
    dword_1073E728 = 0;
    dword_1073E72C = 0;
    dword_1073E730 = 0;
    dword_1073E734 = (int)"operator end fadein";
    dword_1073E738 = (int)"0";
    dword_1073E73C = 3;
    dword_1073E740 = 8;
    dword_1073E744 = 4;
    dword_1073E748 = -1;
    dword_1073E74C = 0;
    dword_1073E750 = 0;
    dword_1073E754 = 0;
    dword_1073E758 = 0;
    dword_1073E75C = 0;
    dword_1073E760 = (int)"operator start fadeout";
    dword_1073E764 = (int)"0";
    dword_1073E768 = 3;
    dword_1073E76C = 12;
    dword_1073E770 = 4;
    dword_1073E774 = -1;
    dword_1073E778 = 0;
    dword_1073E77C = 0;
    dword_1073E780 = 0;
    dword_1073E784 = 0;
    dword_1073E788 = 0;
    dword_1073E78C = (int)"operator end fadeout";
    dword_1073E790 = (int)"0";
    dword_1073E794 = 3;
    dword_1073E798 = 16;
    dword_1073E79C = 4;
    dword_1073E7A0 = -1;
    dword_1073E7A4 = 0;
    dword_1073E7A8 = 0;
    dword_1073E7AC = 0;
    dword_1073E7B0 = 0;
    dword_1073E7B4 = 0;
    dword_1073E7B8 = (int)"operator fade oscillate";
    dword_1073E7BC = (int)"0";
    dword_1073E7C0 = 3;
    dword_1073E7C4 = 20;
    dword_1073E7C8 = 4;
    dword_1073E7CC = -1;
    dword_1073E7D0 = 0;
    dword_1073E7D4 = 0;
    dword_1073E7D8 = 0;
    dword_1073E7DC = 0;
    dword_1073E7E0 = 0;
    dword_1073E7E4 = (int)"operator time offset seed";
    dword_1073E7E8 = (int)"0";
    dword_1073E7EC = 2;
    dword_1073E7F0 = 32;
    dword_1073E7F4 = 4;
    dword_1073E7F8 = -1;
    dword_1073E7FC = 0;
    dword_1073E800 = 0;
    dword_1073E804 = 0;
    dword_1073E808 = 0;
    dword_1073E80C = 0;
    dword_1073E810 = (int)"operator time offset min";
    dword_1073E814 = (int)"0";
    dword_1073E818 = 3;
    dword_1073E81C = 24;
    dword_1073E820 = 4;
    dword_1073E824 = -1;
    dword_1073E828 = 0;
    dword_1073E870 = 2;
    dword_1073E82C = 0;
    dword_1073E830 = 0;
    dword_1073E834 = 0;
    dword_1073E838 = 0;
    dword_1073E83C = (int)"operator time offset max";
    dword_1073E840 = (int)"0";
    dword_1073E844 = 3;
    dword_1073E848 = 28;
    dword_1073E84C = 4;
    dword_1073E850 = -1;
    dword_1073E854 = 0;
    dword_1073E858 = 0;
    dword_1073E85C = 0;
    dword_1073E860 = 0;
    dword_1073E864 = 0;
    dword_1073E868 = (int)"operator time scale seed";
    dword_1073E86C = (int)"0";
    dword_1073E874 = 48;
    dword_1073E878 = 4;
    dword_1073E87C = -1;
    dword_1073E880 = 0;
    dword_1073E884 = 0;
    dword_1073E888 = 0;
    dword_1073E88C = 0;
    dword_1073E890 = 0;
    dword_1073E894 = (int)"operator time scale min";
    dword_1073E898 = (int)"1";
    dword_1073E89C = 3;
    dword_1073E8A0 = 52;
    dword_1073E8A4 = 4;
    dword_1073E8A8 = -1;
    dword_1073E8AC = 0;
    dword_1073E8B0 = 0;
    dword_1073E8B4 = 0;
    dword_1073E8B8 = 0;
    dword_1073E8BC = 0;
    dword_1073E8C0 = (int)"operator time scale max";
    dword_1073E8C4 = (int)"1";
    dword_1073E8C8 = 3;
    dword_1073E8CC = 56;
    dword_1073E8D0 = 4;
    dword_1073E8D4 = -1;
    dword_1073E8D8 = 0;
    dword_1073E8DC = 0;
    dword_1073E8E0 = 0;
    dword_1073E8E4 = 0;
    dword_1073E8E8 = 0;
    dword_1073E8EC = (int)"operator time strength random scale max";
    dword_1073E8F0 = (int)"1";
    dword_1073E8F4 = 3;
    dword_1073E8F8 = 44;
    dword_1073E8FC = 4;
    dword_1073E900 = -1;
    dword_1073E904 = 0;
    dword_1073E908 = 0;
    dword_1073E90C = 0;
    dword_1073E910 = 0;
    dword_1073E914 = 0;
    dword_1073E918 = (int)"operator strength scale seed";
    dword_1073E91C = (int)"0";
    dword_1073E920 = 2;
    dword_1073E924 = 36;
    dword_1073E928 = 4;
    dword_1073E92C = -1;
    dword_1073E930 = 0;
    dword_1073E934 = 0;
    dword_1073E938 = 0;
    dword_1073E93C = 0;
    dword_1073E940 = 0;
    dword_1073E944 = (int)"operator strength random scale min";
    dword_1073E948 = (int)"1";
    dword_1073E94C = 3;
    dword_1073E950 = 40;
    dword_1073E954 = 4;
    dword_1073E958 = -1;
    dword_1073E95C = 0;
    dword_1073E960 = 0;
    dword_1073E964 = 0;
    dword_1073E968 = 0;
    dword_1073E9CC = (int)"0";
    dword_1073E974 = (int)"1";
    dword_1073E9FC = 10;
    dword_1073EA54 = 10;
    dword_1073E96C = 0;
    dword_1073E970 = (int)"operator strength random scale max";
    dword_1073E978 = 3;
    dword_1073E97C = 44;
    dword_1073E980 = 4;
    dword_1073E984 = -1;
    dword_1073E988 = 0;
    dword_1073E98C = 0;
    dword_1073E990 = 0;
    dword_1073E994 = 0;
    dword_1073E998 = 0;
    dword_1073E99C = (int)"operator end cap state";
    dword_1073E9A0 = (int)"-1";
    dword_1073E9A4 = 2;
    dword_1073E9A8 = 64;
    dword_1073E9AC = 4;
    dword_1073E9B0 = -1;
    dword_1073E9B4 = 0;
    dword_1073E9B8 = 0;
    dword_1073E9BC = 0;
    dword_1073E9C0 = 0;
    dword_1073E9C4 = 0;
    dword_1073E9C8 = (int)"time to start transition";
    dword_1073E9D0 = 3;
    dword_1073E9D4 = 88;
    dword_1073E9D8 = 4;
    dword_1073E9DC = -1;
    dword_1073E9E0 = 0;
    dword_1073E9E4 = 0;
    dword_1073E9E8 = 0;
    dword_1073E9EC = 0;
    dword_1073E9F0 = 0;
    dword_1073E9F4 = (int)"starting force";
    dword_1073E9F8 = (int)"0 0 0";
    dword_1073EA00 = 92;
    dword_1073EA04 = 12;
    dword_1073EA08 = -1;
    dword_1073EA0C = 0;
    dword_1073EA10 = 0;
    dword_1073EA14 = 0;
    dword_1073EA18 = 0;
    dword_1073EA1C = 0;
    dword_1073EA20 = (int)"time to end transition";
    dword_1073EA24 = (int)"10";
    dword_1073EA28 = 3;
    dword_1073EA2C = 104;
    dword_1073EA30 = 4;
    dword_1073EA34 = -1;
    dword_1073EA38 = 0;
    dword_1073EA3C = 0;
    dword_1073EA40 = 0;
    dword_1073EA44 = 0;
    dword_1073EA48 = 0;
    dword_1073EA4C = (int)"ending force";
    dword_1073EA50 = (int)"0 0 0";
    dword_1073EA58 = 108;
    dword_1073EA5C = 12;
    dword_1073EA60 = -1;
    dword_1073EA64 = 0;
    dword_1073EA68 = 0;
    dword_1073EA6C = 0;
    dword_1073EA70 = 0;
    dword_1073EA74 = 0;
    dword_1073EA78 = 0;
    dword_1073EA7C = 0;
    dword_1073EA80 = 0;
    dword_1073EA84 = 0;
    dword_1073EA88 = 0;
    dword_1073EA8C = -1;
    dword_1073EA90 = 0;
    dword_1073EA94 = 0;
    dword_1073EA98 = 0;
    dword_1073EA9C = 0;
    dword_1073EAA0 = 0;
  }
  return unpack_12;
}

//------------------------------------------------------------------------------
// Address: 0x10228EE0
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class C_OP_TurbulenceForce>(class C_OP_TurbulenceForce __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<C_OP_TurbulenceForce>()
{
  if ( (_S8 & 1) == 0 )
  {
    _S8 |= 1u;
    dword_1073EAB0 = 3;
    dword_1073EAB4 = 4;
    dword_1073EAB8 = 4;
    dword_1073EABC = -1;
    dword_1073EAC0 = 0;
    dword_1073EAC4 = 0;
    dword_1073EAC8 = 0;
    dword_1073EACC = 0;
    dword_1073EAD0 = 0;
    dword_1073EAD4 = (int)"operator end fadein";
    dword_1073EAD8 = (int)"0";
    dword_1073EADC = 3;
    dword_1073EAE0 = 8;
    dword_1073EAE4 = 4;
    dword_1073EAE8 = -1;
    dword_1073EAEC = 0;
    dword_1073EAF0 = 0;
    dword_1073EAF4 = 0;
    dword_1073EAF8 = 0;
    dword_1073EAFC = 0;
    dword_1073EB00 = (int)"operator start fadeout";
    dword_1073EB04 = (int)"0";
    dword_1073EB08 = 3;
    dword_1073EB0C = 12;
    dword_1073EB10 = 4;
    dword_1073EB14 = -1;
    dword_1073EB18 = 0;
    dword_1073EB1C = 0;
    dword_1073EB20 = 0;
    dword_1073EB24 = 0;
    dword_1073EB28 = 0;
    dword_1073EB2C = (int)"operator end fadeout";
    dword_1073EB30 = (int)"0";
    dword_1073EB34 = 3;
    dword_1073EB38 = 16;
    dword_1073EB3C = 4;
    dword_1073EB40 = -1;
    dword_1073EB44 = 0;
    dword_1073EB48 = 0;
    dword_1073EB4C = 0;
    dword_1073EB50 = 0;
    dword_1073EB54 = 0;
    dword_1073EB58 = (int)"operator fade oscillate";
    dword_1073EB5C = (int)"0";
    dword_1073EB60 = 3;
    dword_1073EB64 = 20;
    dword_1073EB68 = 4;
    dword_1073EB6C = -1;
    dword_1073EB70 = 0;
    dword_1073EB74 = 0;
    dword_1073EB78 = 0;
    dword_1073EB7C = 0;
    dword_1073EB80 = 0;
    dword_1073EB84 = (int)"operator time offset seed";
    dword_1073EB88 = (int)"0";
    dword_1073EB8C = 2;
    dword_1073EB90 = 32;
    dword_1073EB94 = 4;
    dword_1073EB98 = -1;
    dword_1073EB9C = 0;
    dword_1073EBA0 = 0;
    dword_1073EBA4 = 0;
    dword_1073EBA8 = 0;
    dword_1073EBAC = 0;
    dword_1073EBB0 = (int)"operator time offset min";
    dword_1073EBB4 = (int)"0";
    dword_1073EBB8 = 3;
    dword_1073EBBC = 24;
    dword_1073EBC0 = 4;
    dword_1073EBC4 = -1;
    dword_1073EBC8 = 0;
    dword_1073EC10 = 2;
    dword_1073EBCC = 0;
    dword_1073EBD0 = 0;
    dword_1073EBD4 = 0;
    dword_1073EBD8 = 0;
    dword_1073EBDC = (int)"operator time offset max";
    dword_1073EBE0 = (int)"0";
    dword_1073EBE4 = 3;
    dword_1073EBE8 = 28;
    dword_1073EBEC = 4;
    dword_1073EBF0 = -1;
    dword_1073EBF4 = 0;
    dword_1073EBF8 = 0;
    dword_1073EBFC = 0;
    dword_1073EC00 = 0;
    dword_1073EC04 = 0;
    dword_1073EC08 = (int)"operator time scale seed";
    dword_1073EC0C = (int)"0";
    dword_1073EC14 = 48;
    dword_1073EC18 = 4;
    dword_1073EC1C = -1;
    dword_1073EC20 = 0;
    dword_1073EC24 = 0;
    dword_1073EC28 = 0;
    dword_1073EC2C = 0;
    dword_1073EC30 = 0;
    dword_1073EC34 = (int)"operator time scale min";
    dword_1073EC38 = (int)"1";
    dword_1073EC3C = 3;
    dword_1073EC40 = 52;
    dword_1073EC44 = 4;
    dword_1073EC48 = -1;
    dword_1073EC4C = 0;
    dword_1073EC50 = 0;
    dword_1073EC54 = 0;
    dword_1073EC58 = 0;
    dword_1073EC5C = 0;
    dword_1073EC60 = (int)"operator time scale max";
    dword_1073EC64 = (int)"1";
    dword_1073EC68 = 3;
    dword_1073EC6C = 56;
    dword_1073EC70 = 4;
    dword_1073EC74 = -1;
    dword_1073EC78 = 0;
    dword_1073EC7C = 0;
    dword_1073EC80 = 0;
    dword_1073EC84 = 0;
    dword_1073EC88 = 0;
    dword_1073EC8C = (int)"operator time strength random scale max";
    dword_1073EC90 = (int)"1";
    dword_1073EC94 = 3;
    dword_1073EC98 = 44;
    dword_1073EC9C = 4;
    dword_1073ECA0 = -1;
    dword_1073ECA4 = 0;
    dword_1073ECA8 = 0;
    dword_1073ECAC = 0;
    dword_1073ECB0 = 0;
    dword_1073ECB4 = 0;
    dword_1073ECB8 = (int)"operator strength scale seed";
    dword_1073ECBC = (int)"0";
    dword_1073ECC0 = 2;
    dword_1073ECC4 = 36;
    dword_1073ECC8 = 4;
    dword_1073ECCC = -1;
    dword_1073ECD0 = 0;
    dword_1073ECD4 = 0;
    dword_1073ECD8 = 0;
    dword_1073ECDC = 0;
    dword_1073ECE0 = 0;
    dword_1073ECE4 = (int)"operator strength random scale min";
    dword_1073ECE8 = (int)"1";
    dword_1073ECEC = 3;
    dword_1073ECF0 = 40;
    dword_1073ECF4 = 4;
    dword_1073ECF8 = -1;
    dword_1073ECFC = 0;
    dword_1073ED00 = 0;
    dword_1073ED04 = 0;
    dword_1073ED08 = 0;
    dword_1073ED14 = (int)"1";
    dword_1073ED6C = (int)"1";
    dword_1073ED0C = 0;
    dword_1073ED10 = (int)"operator strength random scale max";
    dword_1073ED18 = 3;
    dword_1073ED1C = 44;
    dword_1073ED20 = 4;
    dword_1073ED24 = -1;
    dword_1073ED28 = 0;
    dword_1073ED2C = 0;
    dword_1073ED30 = 0;
    dword_1073ED34 = 0;
    dword_1073ED38 = 0;
    dword_1073ED3C = (int)"operator end cap state";
    dword_1073ED40 = (int)"-1";
    dword_1073ED44 = 2;
    dword_1073ED48 = 64;
    dword_1073ED4C = 4;
    dword_1073ED50 = -1;
    dword_1073ED54 = 0;
    dword_1073ED58 = 0;
    dword_1073ED5C = 0;
    dword_1073ED60 = 0;
    dword_1073ED64 = 0;
    dword_1073ED68 = (int)"Noise scale 0";
    dword_1073ED70 = 3;
    dword_1073ED74 = 88;
    dword_1073ED78 = 4;
    dword_1073ED7C = -1;
    dword_1073ED80 = 0;
    dword_1073ED84 = 0;
    dword_1073ED88 = 0;
    dword_1073ED8C = 0;
    dword_1073ED90 = 0;
    dword_1073ED94 = (int)"Noise amount 0";
    dword_1073ED98 = (int)"1 1 1";
    dword_1073ED9C = 10;
    dword_1073EDA0 = 104;
    dword_1073EDA4 = 12;
    dword_1073EDA8 = -1;
    dword_1073EDAC = 0;
    dword_1073EDB0 = 0;
    dword_1073EDB4 = 0;
    dword_1073EDB8 = 0;
    dword_1073EDBC = 0;
    dword_1073EDC0 = (int)"Noise scale 1";
    dword_1073EDC4 = (int)"0";
    dword_1073EDC8 = 3;
    dword_1073EDCC = 92;
    dword_1073EDD0 = 4;
    dword_1073EDD4 = -1;
    dword_1073EDD8 = 0;
    dword_1073EDDC = 0;
    dword_1073EDE0 = 0;
    dword_1073EDE4 = 0;
    dword_1073EDE8 = 0;
    dword_1073EDEC = (int)"Noise amount 1";
    dword_1073EDF0 = (int)".5 .5 .5";
    dword_1073EDF4 = 10;
    dword_1073EDF8 = 116;
    dword_1073EDFC = 12;
    dword_1073EE00 = -1;
    dword_1073EE04 = 0;
    dword_1073EE08 = 0;
    dword_1073EE0C = 0;
    dword_1073EE10 = 0;
    dword_1073EE14 = 0;
    dword_1073EE18 = (int)"Noise scale 2";
    dword_1073EE1C = (int)"0";
    dword_1073EE20 = 3;
    dword_1073EE24 = 96;
    dword_1073EE28 = 4;
    dword_1073EE2C = -1;
    dword_1073EE30 = 0;
    dword_1073EE34 = 0;
    dword_1073EE38 = 0;
    dword_1073EE3C = 0;
    dword_1073EE40 = 0;
    dword_1073EE44 = (int)"Noise amount 2";
    dword_1073EE48 = (int)".25 .25 .25";
    dword_1073EE74 = (int)"0";
    dword_1073EE78 = 3;
    dword_1073EE4C = 10;
    dword_1073EEA4 = 10;
    dword_1073EE50 = 128;
    dword_1073EE54 = 12;
    dword_1073EE58 = -1;
    dword_1073EE5C = 0;
    dword_1073EE60 = 0;
    dword_1073EE64 = 0;
    dword_1073EE68 = 0;
    dword_1073EE6C = 0;
    dword_1073EE70 = (int)"Noise scale 3";
    dword_1073EE7C = 100;
    dword_1073EE80 = 4;
    dword_1073EE84 = -1;
    dword_1073EE88 = 0;
    dword_1073EE8C = 0;
    dword_1073EE90 = 0;
    dword_1073EE94 = 0;
    dword_1073EE98 = 0;
    dword_1073EE9C = (int)"Noise amount 3";
    dword_1073EEA0 = (int)".125 .125 .125";
    dword_1073EEA8 = 140;
    dword_1073EEAC = 12;
    dword_1073EEB0 = -1;
    dword_1073EEB4 = 0;
    dword_1073EEB8 = 0;
    dword_1073EEBC = 0;
    dword_1073EEC0 = 0;
    dword_1073EEC4 = 0;
    dword_1073EEC8 = 0;
    dword_1073EECC = 0;
    dword_1073EED0 = 0;
    dword_1073EED4 = 0;
    dword_1073EED8 = 0;
    dword_1073EEDC = -1;
    dword_1073EEE0 = 0;
    dword_1073EEE4 = 0;
    dword_1073EEE8 = 0;
    dword_1073EEEC = 0;
    dword_1073EEF0 = 0;
  }
  return unpack_13;
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x102DFFC0
// Name: private: virtual void C_OP_RandomForce::AddForces(class FourVectors __near *,class CParticleCollection __near *,int,float,void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_OP_RandomForce::AddForces(
        C_OP_RandomForce *this@<ecx>,
        int a2@<ebp>,
        FourVectors *pAccumulatedForces,
        CParticleCollection *pParticles,
        int nBlocks,
        float flStrength,
        void *pContext)
{
  __m128 v7; // xmm4
  __m128 v8; // xmm1
  __m128 v9; // xmm4
  __m128 v10; // xmm2
  __m128 v11; // xmm4
  __m128 v12; // xmm3
  __m128 v13; // xmm0
  __m128 v14; // xmm4
  __m128 v15; // xmm5
  __m128 v16; // xmm1
  __m128 v17; // xmm0
  __m128 *SIMDRandContext; // edi
  __m128 *p_z; // esi
  __m128 box_min_4; // [esp+4h] [ebp-6Ch]
  __m128 box_min_20; // [esp+14h] [ebp-5Ch]
  __m128 box_max_4; // [esp+34h] [ebp-3Ch]
  __m128 box_max_20; // [esp+44h] [ebp-2Ch]
  int i; // [esp+60h] [ebp-10h]
  _DWORD v25[3]; // [esp+64h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+70h] [ebp+0h]

  v25[0] = a2;
  v25[1] = retaddr;
  v7 = 0;
  v7.m128_f32[0] = this->m_MinForce.x * flStrength;
  v8 = v7;
  v9 = 0;
  v9.m128_f32[0] = this->m_MinForce.y * flStrength;
  v10 = v9;
  v11 = 0;
  v11.m128_f32[0] = this->m_MinForce.z * flStrength;
  v12 = v11;
  v13 = 0;
  v13.m128_f32[0] = this->m_MaxForce.x * flStrength;
  v14 = 0;
  v14.m128_f32[0] = this->m_MaxForce.y * flStrength;
  v15 = 0;
  v15.m128_f32[0] = this->m_MaxForce.z * flStrength;
  v16 = _mm_shuffle_ps(v8, v8, 0);
  v17 = _mm_sub_ps(_mm_shuffle_ps(v13, v13, 0), v16);
  box_min_4 = _mm_shuffle_ps(v10, v10, 0);
  box_min_20 = _mm_shuffle_ps(v12, v12, 0);
  box_max_4 = _mm_sub_ps(_mm_shuffle_ps(v14, v14, 0), box_min_4);
  box_max_20 = _mm_sub_ps(_mm_shuffle_ps(v15, v15, 0), box_min_20);
  SIMDRandContext = (__m128 *)GetSIMDRandContext();
  if ( nBlocks > 0 )
  {
    p_z = &pAccumulatedForces->z;
    for ( i = nBlocks; i != 0; --i )
    {
      RandSIMD(a1: (int)v25, result: SIMDRandContext);
      p_z[-2] = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v17, v17), v16), p_z[-2]);
      RandSIMD(a1: (int)v25, result: SIMDRandContext);
      p_z[-1] = _mm_add_ps(_mm_add_ps(_mm_mul_ps(box_max_4, v17), box_min_4), p_z[-1]);
      RandSIMD(a1: (int)v25, result: SIMDRandContext);
      *p_z = _mm_add_ps(_mm_add_ps(_mm_mul_ps(box_max_20, v17), box_min_20), *p_z);
      p_z += 3;
    }
  }
  ReleaseSIMDRandContext(nContext: (int)SIMDRandContext);
}

//------------------------------------------------------------------------------
// Address: 0x102E0670
// Name: private: virtual void C_OP_ParentVortices::AddForces(class FourVectors __near *,class CParticleCollection __near *,int,float,void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge C_OP_ParentVortices::AddForces(
        C_OP_ParentVortices *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        FourVectors *pAccumulatedForces,
        CParticleCollection *pParticles,
        int nBlocks,
        float flStrength,
        void *pContext)
{
  CParticleCollection *v9; // edi
  CParticleCollection *m_pParent; // eax
  int m_nActiveParticles; // eax
  __m128 v12; // xmm3
  __m128 v13; // xmm1
  __m128 v14; // xmm2
  __m128 v15; // xmm0
  __m128 v16; // xmm4
  __m128 v17; // xmm0
  void *v18; // esp
  unsigned int v19; // esi
  __m128 v20; // xmm6
  __m128 v21; // xmm5
  __m128 v22; // xmm4
  __m128 *v23; // eax
  CParticleCollection *v24; // edx
  unsigned int v25; // ecx
  int v26; // edi
  int v27; // esi
  float v28; // xmm0_4
  __m128 v29; // xmm7
  __m128 v30; // xmm0
  CParticleCollection *v31; // edx
  unsigned int v32; // edi
  float *v33; // edx
  __m128 v34; // xmm7
  CParticleCollection *v35; // edx
  unsigned int v36; // esi
  float *v37; // edx
  unsigned int v38; // esi
  __m128 v39; // xmm0
  float *v40; // edx
  __m128 v41; // xmm0
  C_OP_ParentVortices *v42; // edx
  unsigned int v43; // kr00_4
  __m128 *v44; // edi
  __m128 v46; // xmm0
  int v47; // edx
  __m128 v48; // xmm5
  __m128 v49; // xmm1
  __m128 *v50; // eax
  __m128 v51; // xmm4
  __m128 v52; // xmm0
  __m128 v53; // xmm1
  __m128 v54; // xmm6
  __m128 v55; // xmm7
  __m128 v56; // xmm2
  __m128 v57; // xmm3
  __m128 v58; // xmm2
  __m128 v59; // xmm0
  __m128 v60; // xmm1
  __m128 v61; // xmm3
  __m128 v62; // xmm2
  __m128 v63; // xmm5
  __m128 v64; // xmm3
  __m128 v65; // xmm4
  __m128 v66; // xmm0
  __m128 v67; // xmm2
  __m128 v68; // xmm1
  __m128 v69; // xmm0
  __m128 v70; // xmm1
  __m128 v71; // xmm4
  __m128 v72; // xmm3
  __m128 v73; // xmm0
  __m128 v74; // xmm5
  __m128 v75; // xmm3
  FourVectors *v76; // eax
  __m128 v77; // xmm2
  __m128 z; // xmm0
  bool v79; // zf
  int v80; // [esp-100h] [ebp-10Ch]
  int v81; // [esp-FCh] [ebp-108h]
  __m128 v82; // [esp-F0h] [ebp-FCh]
  int v83; // [esp-C0h] [ebp-CCh] BYREF
  __m128 v84; // [esp-B0h] [ebp-BCh] BYREF
  __m128 v85; // [esp-90h] [ebp-9Ch]
  __m128 v86; // [esp-80h] [ebp-8Ch]
  __m128 v87; // [esp-70h] [ebp-7Ch]
  __m128 v88; // [esp-60h] [ebp-6Ch]
  __m128 v89; // [esp-50h] [ebp-5Ch]
  __m128 v90; // [esp-40h] [ebp-4Ch]
  __m128 v91; // [esp-30h] [ebp-3Ch]
  C_OP_ParentVortices *v92; // [esp-10h] [ebp-1Ch]
  int v93; // [esp-Ch] [ebp-18h]
  int v94; // [esp-8h] [ebp-14h]
  int v95; // [esp-4h] [ebp-10h]
  int v96; // [esp+0h] [ebp-Ch]
  void *v97; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v96 = a2;
  v97 = retaddr;
  v81 = a4;
  v80 = a3;
  v9 = pParticles;
  m_pParent = pParticles->m_pParent;
  v92 = this;
  if ( m_pParent != nullptr )
  {
    m_nActiveParticles = m_pParent->m_nActiveParticles;
    v94 = m_nActiveParticles;
    if ( m_nActiveParticles != 0 )
    {
      v12 = _mm_shuffle_ps((__m128)LODWORD(this->m_vecTwistAxis.x), (__m128)LODWORD(this->m_vecTwistAxis.x), 0);
      v13 = _mm_shuffle_ps((__m128)LODWORD(this->m_vecTwistAxis.y), (__m128)LODWORD(this->m_vecTwistAxis.y), 0);
      v14 = _mm_shuffle_ps((__m128)LODWORD(this->m_vecTwistAxis.z), (__m128)LODWORD(this->m_vecTwistAxis.z), 0);
      v15 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v12, v12), _mm_mul_ps(v13, v13)), _mm_mul_ps(v14, v14));
      v16 = _mm_rsqrt_ps(v15);
      v17 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(Four_Threes, _mm_mul_ps(_mm_mul_ps(v16, v16), v15)), v16), Four_PointFives);
      v89 = _mm_mul_ps(v17, v12);
      v90 = _mm_mul_ps(v13, v17);
      v91 = _mm_mul_ps(v14, v17);
      v18 = alloca(m_nActiveParticles << 7);
      v19 = 0;
      v95 = 0;
      if ( v94 > 0 )
      {
        v20 = v91;
        v21 = v90;
        v22 = v89;
        v23 = &v84;
        do
        {
          v23[-2] = v22;
          v23[-1] = v21;
          *v23 = v20;
          v24 = v9->m_pParent;
          v25 = v19 >> 2;
          v26 = (v19 >> 2) * v24->m_ParticleAttributes.m_nFloatStrides[3];
          v27 = v19 & 3;
          v28 = 1.0 / (v24->m_ParticleAttributes.m_pAttributes[3][v27 + v26] + 0.00001);
          v29 = 0;
          v29.m128_f32[0] = v28;
          v30 = _mm_shuffle_ps(v29, v29, 0);
          v23[1] = _mm_mul_ps(v30, v30);
          v31 = pParticles->m_pParent;
          v32 = v31->m_ParticleAttributes.m_nFloatStrides[7];
          v33 = v31->m_ParticleAttributes.m_pAttributes[7];
          v93 = v27;
          v34 = 0;
          v34.m128_f32[0] = (float)(v92->m_flForceScale * flStrength) * v33[v27 + v25 * v32];
          v23[2] = _mm_shuffle_ps(v34, v34, 0);
          v35 = pParticles->m_pParent;
          v36 = v35->m_ParticleAttributes.m_nFloatStrides[0];
          v37 = v35->m_ParticleAttributes.m_pAttributes[0];
          v38 = v93 + v25 * v36;
          v39 = (__m128)LODWORD(v37[v38]);
          v9 = pParticles;
          v40 = &v37[v38];
          v23[-5] = _mm_shuffle_ps(v39, v39, 0);
          v23[-4] = _mm_shuffle_ps((__m128)*((unsigned int *)v40 + 4), (__m128)*((unsigned int *)v40 + 4), 0);
          v41 = (__m128)*((unsigned int *)v40 + 8);
          v42 = v92;
          v23[-3] = _mm_shuffle_ps(v41, v41, 0);
          if ( v42->m_bFlipBasedOnYaw
            && pParticles->m_pParent->m_ParticleAttributes.m_pAttributes[12][v93
                                                                           + v25
                                                                           * pParticles->m_pParent->m_ParticleAttributes.m_nFloatStrides[12]] >= 3.141592653589793 )
          {
            v23[-5] = _mm_mul_ps(v23[-5], Four_NegativeOnes);
            v23[-4] = _mm_mul_ps(v23[-4], Four_NegativeOnes);
            v23[-3] = _mm_mul_ps(v23[-3], Four_NegativeOnes);
          }
          v19 = v95 + 1;
          v23 += 8;
          v95 = v19;
        }
        while ( (int)v19 < v94 );
      }
      v43 = v9->m_ParticleAttributes.m_nFloatStrides[0];
      v44 = (__m128 *)v9->m_ParticleAttributes.m_pAttributes[0];
      if ( nBlocks > 0 )
      {
        v95 = nBlocks;
        do
        {
          v46 = Four_Zeros;
          v47 = v94;
          v48 = Four_Zeros;
          v49 = Four_Zeros;
          v89 = Four_Zeros;
          v90 = Four_Zeros;
          v91 = Four_Zeros;
          if ( v94 > 0 )
          {
            v87 = *v44;
            v86 = v44[1];
            v85 = v44[2];
            v50 = (__m128 *)&v83;
            do
            {
              v51 = _mm_sub_ps(v87, v50[-4]);
              v52 = _mm_sub_ps(v86, v50[-3]);
              v53 = _mm_sub_ps(v85, v50[-2]);
              v54 = *v50;
              v55 = v50[1];
              v56 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v51, v51), _mm_mul_ps(v52, v52)), _mm_mul_ps(v53, v53));
              v57 = _mm_rsqrt_ps(v56);
              v88 = v56;
              v58 = _mm_mul_ps(
                      _mm_mul_ps(_mm_sub_ps(Four_Threes, _mm_mul_ps(_mm_mul_ps(v57, v57), v56)), v57),
                      Four_PointFives);
              v59 = _mm_mul_ps(v52, v58);
              v60 = _mm_mul_ps(v53, v58);
              v61 = _mm_mul_ps(v58, v51);
              v62 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v59, v54), _mm_mul_ps(v61, v50[-1])), _mm_mul_ps(v60, v55));
              v84 = _mm_mul_ps(v59, v62);
              v63 = _mm_sub_ps(v60, _mm_mul_ps(v60, v62));
              v64 = _mm_sub_ps(v61, _mm_mul_ps(v61, v62));
              v65 = _mm_sub_ps(v59, v84);
              v66 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v64, v64), _mm_mul_ps(v65, v65)), _mm_mul_ps(v63, v63));
              v82 = v64;
              v67 = _mm_and_ps(_mm_cmplt_ps(Four_Epsilons, v66), _mm_cmplt_ps(Four_Epsilons, v88));
              v68 = _mm_rsqrt_ps(v66);
              v69 = _mm_mul_ps(
                      _mm_mul_ps(_mm_sub_ps(Four_Threes, _mm_mul_ps(_mm_mul_ps(v68, v68), v66)), v68),
                      Four_PointFives);
              v70 = _mm_mul_ps(v69, v64);
              v71 = _mm_mul_ps(v65, v69);
              v72 = _mm_mul_ps(v63, v69);
              v73 = _mm_sub_ps(_mm_mul_ps(v71, v55), _mm_mul_ps(v72, v54));
              v74 = _mm_sub_ps(_mm_mul_ps(v72, v50[-1]), _mm_mul_ps(v70, v55));
              v75 = _mm_mul_ps(_mm_max_ps(Four_Zeros, _mm_sub_ps(Four_Ones, _mm_mul_ps(v50[2], v88))), v50[3]);
              v46 = _mm_add_ps(_mm_and_ps(_mm_mul_ps(v73, v75), v67), v89);
              v48 = _mm_add_ps(_mm_and_ps(_mm_mul_ps(v74, v75), v67), v90);
              v49 = _mm_add_ps(
                      _mm_and_ps(_mm_mul_ps(_mm_sub_ps(_mm_mul_ps(v70, v54), _mm_mul_ps(v71, v50[-1])), v75), v67),
                      v91);
              v50 += 8;
              --v47;
              v89 = v46;
              v90 = v48;
              v91 = v49;
            }
            while ( v47 != 0 );
          }
          v76 = pAccumulatedForces;
          v77 = _mm_add_ps(pAccumulatedForces->x, v46);
          pAccumulatedForces->y = _mm_add_ps(pAccumulatedForces->y, v48);
          z = pAccumulatedForces->z;
          ++pAccumulatedForces;
          v44 += 3 * (v43 / 0xC);
          v79 = v95-- == 1;
          v76->x = v77;
          v76->z = _mm_add_ps(z, v49);
        }
        while ( !v79 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E10B0
// Name: private: virtual void C_OP_TwistAroundAxis::AddForces(class FourVectors __near *,class CParticleCollection __near *,int,float,void __near *)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge C_OP_TwistAroundAxis::AddForces(
        C_OP_TwistAroundAxis *this@<ecx>,
        float a2@<ebp>,
        FourVectors *pAccumulatedForces,
        CParticleCollection *pParticles,
        int nBlocks,
        float flStrength,
        void *pContext)
{
  Vector *v8; // eax
  __m128 v9; // xmm3
  __m128 v10; // xmm1
  __m128 v11; // xmm2
  __m128 v12; // xmm0
  __m128 v13; // xmm4
  __m128 v14; // xmm4
  __m128 *v15; // ecx
  int v16; // edi
  __m128 v17; // xmm1
  unsigned int v19; // esi
  __m128 v20; // xmm7
  __m128 v21; // xmm3
  __m128 v22; // xmm4
  __m128 v23; // xmm2
  __m128 v24; // xmm5
  __m128 v25; // xmm0
  __m128 v26; // xmm0
  __m128 v27; // xmm3
  __m128 v28; // xmm1
  __m128 v29; // xmm7
  __m128 v30; // xmm0
  __m128 v31; // xmm4
  __m128 v32; // xmm1
  __m128 v33; // xmm0
  __m128 v34; // xmm3
  __m128 v35; // xmm2
  __m128 v36; // xmm3
  __m128 v37; // xmm6
  __m128 v38; // xmm2
  __m128 v39; // xmm4
  __m128 v40; // xmm1
  __m128 v41; // xmm5
  FourVectors *v42; // eax
  __m128 v43; // xmm0
  __m128 v44; // xmm1
  __m128 v45; // xmm2
  __m128 z; // xmm0
  float flTime; // [esp+0h] [ebp-114h]
  __m128 v48; // [esp+18h] [ebp-FCh]
  __m128 ofs_36; // [esp+48h] [ebp-CCh]
  _BYTE parallel_comp_36[64]; // [esp+88h] [ebp-8Ch] OVERLAPPED BYREF
  _BYTE v51[60]; // [esp+C8h] [ebp-4Ch] OVERLAPPED BYREF
  unsigned int v52; // [esp+104h] [ebp-10h]
  Vector vecCenter; // [esp+108h] [ebp-Ch]
  float retaddr; // [esp+114h] [ebp+0h]

  vecCenter.x = a2;
  vecCenter.y = retaddr;
  v8 = CParticleCollection::TransformAxis(
         this: pParticles,
         result: (Vector *)&parallel_comp_36[52],
         SrcAxis: &this->m_TwistAxis,
         bLocalSpace: this->m_bLocalSpace,
         nControlPointNumber: 0);
  v9 = _mm_shuffle_ps((__m128)LODWORD(v8->x), (__m128)LODWORD(v8->x), 0);
  v10 = _mm_shuffle_ps((__m128)LODWORD(v8->y), (__m128)LODWORD(v8->y), 0);
  v11 = _mm_shuffle_ps((__m128)LODWORD(v8->z), (__m128)LODWORD(v8->z), 0);
  v12 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v10, v10), _mm_mul_ps(v9, v9)), _mm_mul_ps(v11, v11));
  v13 = _mm_rsqrt_ps(v12);
  v14 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(Four_Threes, _mm_mul_ps(_mm_mul_ps(v13, v13), v12)), v13), Four_PointFives);
  flTime = pParticles->m_flCurTime;
  *(__m128 *)v51 = _mm_mul_ps(v14, v9);
  *(__m128 *)&v51[16] = _mm_mul_ps(v10, v14);
  *(__m128 *)&v51[32] = _mm_mul_ps(v11, v14);
  CParticleCollection::GetControlPointAtTime(
    this: pParticles,
    nControlPoint: 0,
    flTime,
    pControlPoint: (Vector *)&v51[52]);
  v15 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  *(__m128 *)parallel_comp_36 = _mm_shuffle_ps((__m128)*(unsigned int *)&v51[52], (__m128)*(unsigned int *)&v51[52], 0);
  *(__m128 *)&parallel_comp_36[16] = _mm_shuffle_ps(
                                       (__m128)*(unsigned int *)&v51[56],
                                       (__m128)*(unsigned int *)&v51[56],
                                       0);
  *(__m128 *)&parallel_comp_36[32] = _mm_shuffle_ps((__m128)v52, (__m128)v52, 0);
  v12.m128_f32[0] = this->m_fForceAmount * flStrength;
  v16 = nBlocks;
  v17 = 0;
  v17.m128_f32[0] = v12.m128_f32[0];
  ofs_36 = _mm_shuffle_ps(v17, v17, 0);
  if ( nBlocks > 0 )
  {
    v19 = 48 * (pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC);
    do
    {
      v20 = _mm_sub_ps(*v15, *(__m128 *)parallel_comp_36);
      v21 = _mm_sub_ps(v15[1], *(__m128 *)&parallel_comp_36[16]);
      v22 = _mm_sub_ps(v15[2], *(__m128 *)&parallel_comp_36[32]);
      v23 = _mm_mul_ps(v22, v22);
      v24 = _mm_add_ps(_mm_mul_ps(v20, v20), _mm_mul_ps(v21, v21));
      v25 = _mm_add_ps(v23, v24);
      *(__m128 *)&parallel_comp_36[48] = _mm_rsqrt_ps(v25);
      v26 = _mm_mul_ps(
              _mm_mul_ps(
                _mm_sub_ps(
                  Four_Threes,
                  _mm_mul_ps(_mm_mul_ps(*(__m128 *)&parallel_comp_36[48], *(__m128 *)&parallel_comp_36[48]), v25)),
                *(__m128 *)&parallel_comp_36[48]),
              Four_PointFives);
      v27 = _mm_mul_ps(v21, v26);
      v28 = _mm_mul_ps(v26, v20);
      v29 = _mm_mul_ps(v22, v26);
      v30 = _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(v27, *(__m128 *)&v51[16]), _mm_mul_ps(v28, *(__m128 *)v51)),
              _mm_mul_ps(v29, *(__m128 *)&v51[32]));
      v48 = _mm_sub_ps(v28, _mm_mul_ps(v28, v30));
      v31 = _mm_sub_ps(v27, _mm_mul_ps(v27, v30));
      v32 = _mm_sub_ps(v29, _mm_mul_ps(v29, v30));
      v33 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v48, v48), _mm_mul_ps(v31, v31)), _mm_mul_ps(v32, v32));
      v34 = _mm_cmplt_ps(Four_Epsilons, _mm_add_ps(v23, v24));
      v35 = _mm_rsqrt_ps(v33);
      v36 = _mm_and_ps(v34, _mm_cmplt_ps(Four_Epsilons, v33));
      v37 = _mm_mul_ps(_mm_mul_ps(_mm_sub_ps(Four_Threes, _mm_mul_ps(_mm_mul_ps(v35, v35), v33)), v35), Four_PointFives);
      v38 = _mm_mul_ps(v37, v48);
      v39 = _mm_mul_ps(v31, v37);
      v40 = _mm_mul_ps(v32, v37);
      v41 = _mm_sub_ps(_mm_mul_ps(v40, *(__m128 *)v51), _mm_mul_ps(*(__m128 *)&v51[32], v38));
      v42 = pAccumulatedForces;
      v43 = _mm_sub_ps(_mm_mul_ps(v39, *(__m128 *)&v51[32]), _mm_mul_ps(v40, *(__m128 *)&v51[16]));
      v44 = _mm_mul_ps(_mm_sub_ps(_mm_mul_ps(*(__m128 *)&v51[16], v38), _mm_mul_ps(v39, *(__m128 *)v51)), ofs_36);
      v45 = _mm_add_ps(pAccumulatedForces->x, _mm_and_ps(_mm_mul_ps(v43, ofs_36), v36));
      pAccumulatedForces->y = _mm_add_ps(pAccumulatedForces->y, _mm_and_ps(_mm_mul_ps(v41, ofs_36), v36));
      z = pAccumulatedForces->z;
      ++pAccumulatedForces;
      v15 = (__m128 *)((char *)v15 + v19);
      --v16;
      v42->x = v45;
      v42->z = _mm_add_ps(z, _mm_and_ps(v44, v36));
    }
    while ( v16 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E1940
// Name: private: virtual void C_OP_AttractToControlPoint::AddForces(class FourVectors __near *,class CParticleCollection __near *,int,float,void __near *)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge C_OP_AttractToControlPoint::AddForces(
        C_OP_AttractToControlPoint *this@<ecx>,
        int a2@<ebp>,
        FourVectors *pAccumulatedForces,
        CParticleCollection *pParticles,
        int nBlocks,
        float flStrength,
        void *pContext)
{
  __m128 v7; // xmm1
  __m128 *v8; // esi
  __m128 v10; // xmm2
  __m128 v11; // xmm3
  __m128 v12; // xmm4
  __m128 v13; // xmm0
  __m128 v14; // xmm1
  __m128 v15; // xmm0
  __m128 v16; // xmm0
  __m128 v17; // xmm0
  FourVectors *v18; // eax
  __m128 v19; // xmm1
  __m128 v20; // xmm2
  __m128 v21; // xmm3
  __m128 v22; // xmm0
  __m128 v23; // xmm1
  __m128 v24; // xmm2
  __m128 v25; // xmm3
  bool v26; // zf
  __m128 v27; // [esp+18h] [ebp-ACh]
  __m128 ofs_4; // [esp+28h] [ebp-9Ch]
  __m128 ofs_20; // [esp+38h] [ebp-8Ch]
  __m128 ofs_36; // [esp+48h] [ebp-7Ch]
  __m128 Center_4; // [esp+58h] [ebp-6Ch]
  __m128 Center_20; // [esp+68h] [ebp-5Ch]
  _BYTE Center_36[44]; // [esp+78h] [ebp-4Ch] OVERLAPPED BYREF
  unsigned int v34; // [esp+A4h] [ebp-20h]
  unsigned int v35; // [esp+A8h] [ebp-1Ch]
  Vector vecCenter; // [esp+ACh] [ebp-18h]
  int v37; // [esp+B8h] [ebp-Ch]
  int power_frac; // [esp+BCh] [ebp-8h]
  int retaddr; // [esp+C4h] [ebp+0h]

  v37 = a2;
  power_frac = retaddr;
  v7 = 0;
  v7.m128_i32[0] = COERCE_UNSIGNED_INT(this->m_fForceAmount * flStrength) ^ _mask__NegFloat_;
  LODWORD(vecCenter.y) = (int)(float)(this->m_fFalloffPower * -4.0);
  *(__m128 *)Center_36 = _mm_shuffle_ps(v7, v7, 0);
  CParticleCollection::GetControlPointAtTime(
    this: pParticles,
    nControlPoint: this->m_nControlPointNumber,
    flTime: pParticles->m_flCurTime,
    pControlPoint: (Vector *)&Center_36[40]);
  v8 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  ofs_36 = _mm_shuffle_ps((__m128)*(unsigned int *)&Center_36[40], (__m128)*(unsigned int *)&Center_36[40], 0);
  Center_4 = _mm_shuffle_ps((__m128)v34, (__m128)v34, 0);
  Center_20 = _mm_shuffle_ps((__m128)v35, (__m128)v35, 0);
  if ( nBlocks > 0 )
  {
    LODWORD(vecCenter.x) = 48 * (pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC);
    LODWORD(vecCenter.z) = nBlocks;
    do
    {
      v10 = _mm_sub_ps(*v8, ofs_36);
      v11 = _mm_sub_ps(v8[1], Center_4);
      v12 = _mm_sub_ps(v8[2], Center_20);
      v13 = _mm_sqrt_ps(_mm_add_ps(_mm_add_ps(_mm_mul_ps(v11, v11), _mm_mul_ps(v10, v10)), _mm_mul_ps(v12, v12)));
      v14 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(Four_Zeros, v13), Four_Epsilons), v13);
      *(__m128 *)&Center_36[16] = v13;
      v15 = _mm_rcp_ps(v14);
      v16 = _mm_mul_ps(_mm_sub_ps(_mm_add_ps(v15, v15), _mm_mul_ps(_mm_mul_ps(v15, v15), v14)), *(__m128 *)Center_36);
      v27 = _mm_mul_ps(v10, v16);
      ofs_4 = _mm_mul_ps(v11, v16);
      ofs_20 = _mm_mul_ps(v12, v16);
      v17 = Pow_FixedPoint_Exponent_SIMD(result: (__m128 *)&Center_36[16], x: (const __m128 *)LODWORD(vecCenter.y));
      v8 = (__m128 *)((char *)v8 + LODWORD(vecCenter.x));
      v18 = pAccumulatedForces;
      v19 = _mm_mul_ps(v27, v17);
      v20 = _mm_mul_ps(ofs_4, v17);
      v21 = _mm_mul_ps(ofs_20, v17);
      v22 = _mm_cmplt_ps(Four_Epsilons, *(__m128 *)&Center_36[16]);
      v23 = _mm_add_ps(_mm_and_ps(v19, v22), pAccumulatedForces->x);
      v24 = _mm_add_ps(_mm_and_ps(v20, v22), pAccumulatedForces->y);
      v25 = _mm_add_ps(_mm_and_ps(v21, v22), pAccumulatedForces->z);
      ++pAccumulatedForces;
      v26 = LODWORD(vecCenter.z)-- == 1;
      v18->x = v23;
      v18->y = v24;
      v18->z = v25;
    }
    while ( !v26 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E3470
// Name: void AddBuiltInParticleForceGenerators(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddBuiltInParticleForceGenerators()
{
  CParticleSystemMgr::AddParticleOperator(
    this: g_pParticleSystemMgr,
    nOpType: FUNCTION_FORCEGENERATOR,
    pOpFactory: &s_C_OP_RandomForceFactory);
  CParticleSystemMgr::AddParticleOperator(
    this: g_pParticleSystemMgr,
    nOpType: FUNCTION_FORCEGENERATOR,
    pOpFactory: &s_C_OP_TwistAroundAxisFactory);
  CParticleSystemMgr::AddParticleOperator(
    this: g_pParticleSystemMgr,
    nOpType: FUNCTION_FORCEGENERATOR,
    pOpFactory: &s_C_OP_ParentVorticesFactory);
  CParticleSystemMgr::AddParticleOperator(
    this: g_pParticleSystemMgr,
    nOpType: FUNCTION_FORCEGENERATOR,
    pOpFactory: &s_C_OP_AttractToControlPointFactory);
  CParticleSystemMgr::AddParticleOperator(
    this: g_pParticleSystemMgr,
    nOpType: FUNCTION_FORCEGENERATOR,
    pOpFactory: &s_C_OP_TimeVaryingForceFactory);
  CParticleSystemMgr::AddParticleOperator(
    this: g_pParticleSystemMgr,
    nOpType: FUNCTION_FORCEGENERATOR,
    pOpFactory: &s_C_OP_TurbulenceForceFactory);
  CParticleSystemMgr::AddParticleOperator(
    this: g_pParticleSystemMgr,
    nOpType: FUNCTION_FORCEGENERATOR,
    pOpFactory: &s_C_OP_ForceBasedOnDistanceToPlaneFactory);
}

//------------------------------------------------------------------------------
// Address: 0x102E34F0
// Name: private: virtual void C_OP_ForceBasedOnDistanceToPlane::AddForces(class FourVectors __near *,class CParticleCollection __near *,int,float,void __near *)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge C_OP_ForceBasedOnDistanceToPlane::AddForces(
        C_OP_ForceBasedOnDistanceToPlane *this@<ecx>,
        int a2@<ebp>,
        FourVectors *pAccumulatedForces,
        CParticleCollection *pParticles,
        int nBlocks,
        float flStrength,
        void *pContext)
{
  float m_flMinDist; // xmm1_4
  __m128 v8; // xmm3
  float v9; // xmm0_4
  float v10; // xmm0_4
  __m128 v11; // xmm2
  int m_nControlPointNumber; // eax
  CParticleCPInfo *v13; // eax
  float z; // xmm2_4
  float v15; // xmm2_4
  unsigned int v16; // kr00_4
  __m128 v17; // xmm0
  float y; // xmm1_4
  __m128 *v19; // esi
  __m128 v20; // xmm4
  __m128 v21; // xmm0
  __m128 v22; // xmm0
  __m128 v24; // xmm0
  FourVectors *v25; // eax
  __m128 v26; // xmm1
  __m128 v27; // xmm3
  __m128 v28; // xmm0
  bool v29; // zf
  __m128 v30; // [esp-Ch] [ebp-10Ch]
  __m128 v4Force0_4; // [esp+4h] [ebp-FCh]
  __m128 v4Force0_20; // [esp+14h] [ebp-ECh]
  __m128 v4Force0_36; // [esp+24h] [ebp-DCh]
  __m128 v4PointOnPlane_4; // [esp+34h] [ebp-CCh]
  __m128 v4PointOnPlane_20; // [esp+44h] [ebp-BCh]
  _BYTE v4PointOnPlane_36[144]; // [esp+54h] [ebp-ACh] OVERLAPPED BYREF
  Vector vecPointOnPlane; // [esp+E4h] [ebp-1Ch]
  int v38; // [esp+F0h] [ebp-10h]
  int v39; // [esp+F4h] [ebp-Ch]
  int nPowValue; // [esp+F8h] [ebp-8h]
  int retaddr; // [esp+100h] [ebp+0h]

  v39 = a2;
  nPowValue = retaddr;
  m_flMinDist = this->m_flMinDist;
  v8 = Four_Zeros;
  v9 = this->m_flMaxDist - m_flMinDist;
  *(__m128 *)&v4PointOnPlane_36[112] = Four_Zeros;
  if ( v9 != 0.0 )
  {
    v10 = 1.0 / v9;
    v11 = 0;
    v11.m128_f32[0] = v10;
    *(__m128 *)&v4PointOnPlane_36[112] = _mm_shuffle_ps(v11, v11, 0);
  }
  m_nControlPointNumber = this->m_nControlPointNumber;
  if ( m_nControlPointNumber >= pParticles->m_nNumControlPointsAllocated - 1 )
    m_nControlPointNumber = pParticles->m_nNumControlPointsAllocated - 1;
  v13 = &pParticles->m_pCPInfo[m_nControlPointNumber];
  z = this->m_vecForceAtMaxDist.z;
  *(_QWORD *)&v4PointOnPlane_36[132] = *(_QWORD *)&v13->m_ControlPoint.m_Position.x;
  *(float *)&v4PointOnPlane_36[140] = v13->m_ControlPoint.m_Position.z;
  v15 = z - this->m_vecForceAtMinDist.z;
  v16 = pParticles->m_ParticleAttributes.m_nFloatStrides[0];
  v4Force0_36 = _mm_shuffle_ps(
                  (__m128)*(unsigned int *)&v4PointOnPlane_36[132],
                  (__m128)*(unsigned int *)&v4PointOnPlane_36[132],
                  0);
  v4PointOnPlane_4 = _mm_shuffle_ps(
                       (__m128)*(unsigned int *)&v4PointOnPlane_36[136],
                       (__m128)*(unsigned int *)&v4PointOnPlane_36[136],
                       0);
  v4PointOnPlane_20 = _mm_shuffle_ps(
                        (__m128)*(unsigned int *)&v4PointOnPlane_36[140],
                        (__m128)*(unsigned int *)&v4PointOnPlane_36[140],
                        0);
  *(__m128 *)&v4PointOnPlane_36[64] = _mm_shuffle_ps(
                                        (__m128)LODWORD(this->m_vecPlaneNormal.x),
                                        (__m128)LODWORD(this->m_vecPlaneNormal.x),
                                        0);
  *(__m128 *)&v4PointOnPlane_36[80] = _mm_shuffle_ps(
                                        (__m128)LODWORD(this->m_vecPlaneNormal.y),
                                        (__m128)LODWORD(this->m_vecPlaneNormal.y),
                                        0);
  *(__m128 *)&v4PointOnPlane_36[96] = _mm_shuffle_ps(
                                        (__m128)LODWORD(this->m_vecPlaneNormal.z),
                                        (__m128)LODWORD(this->m_vecPlaneNormal.z),
                                        0);
  v17 = 0;
  v17.m128_f32[0] = m_flMinDist;
  y = this->m_vecForceAtMaxDist.y;
  *(__m128 *)&v4PointOnPlane_36[128] = _mm_shuffle_ps(v17, v17, 0);
  v30 = _mm_shuffle_ps((__m128)LODWORD(this->m_vecForceAtMinDist.x), (__m128)LODWORD(this->m_vecForceAtMinDist.x), 0);
  v4Force0_4 = _mm_shuffle_ps(
                 (__m128)LODWORD(this->m_vecForceAtMinDist.y),
                 (__m128)LODWORD(this->m_vecForceAtMinDist.y),
                 0);
  v19 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  v4Force0_20 = _mm_shuffle_ps(
                  (__m128)LODWORD(this->m_vecForceAtMinDist.z),
                  (__m128)LODWORD(this->m_vecForceAtMinDist.z),
                  0);
  v20 = 0;
  v20.m128_f32[0] = this->m_vecForceAtMaxDist.x - this->m_vecForceAtMinDist.x;
  *(__m128 *)v4PointOnPlane_36 = _mm_shuffle_ps(v20, v20, 0);
  v21 = 0;
  v21.m128_f32[0] = y - this->m_vecForceAtMinDist.y;
  *(__m128 *)&v4PointOnPlane_36[16] = _mm_shuffle_ps(v21, v21, 0);
  v22 = 0;
  v22.m128_f32[0] = v15;
  *(__m128 *)&v4PointOnPlane_36[32] = _mm_shuffle_ps(v22, v22, 0);
  LODWORD(vecPointOnPlane.z) = (int)(float)(this->m_flExponent * 4.0);
  if ( nBlocks > 0 )
  {
    LODWORD(vecPointOnPlane.y) = 48 * (v16 / 0xC);
    v38 = nBlocks;
    while ( 1 )
    {
      *(__m128 *)&v4PointOnPlane_36[48] = _mm_max_ps(
                                            v8,
                                            _mm_min_ps(
                                              Four_Ones,
                                              _mm_mul_ps(
                                                _mm_sub_ps(
                                                  _mm_add_ps(
                                                    _mm_add_ps(
                                                      _mm_mul_ps(
                                                        _mm_sub_ps(v19[1], v4PointOnPlane_4),
                                                        *(__m128 *)&v4PointOnPlane_36[80]),
                                                      _mm_mul_ps(
                                                        _mm_sub_ps(*v19, v4Force0_36),
                                                        *(__m128 *)&v4PointOnPlane_36[64])),
                                                    _mm_mul_ps(
                                                      _mm_sub_ps(v19[2], v4PointOnPlane_20),
                                                      *(__m128 *)&v4PointOnPlane_36[96])),
                                                  *(__m128 *)&v4PointOnPlane_36[128]),
                                                *(__m128 *)&v4PointOnPlane_36[112])));
      v24 = Pow_FixedPoint_Exponent_SIMD(
              result: (__m128 *)&v4PointOnPlane_36[48],
              x: (const __m128 *)LODWORD(vecPointOnPlane.z));
      v19 = (__m128 *)((char *)v19 + LODWORD(vecPointOnPlane.y));
      v25 = pAccumulatedForces;
      v26 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(*(__m128 *)v4PointOnPlane_36, v24), v30), pAccumulatedForces->x);
      v27 = _mm_add_ps(_mm_mul_ps(*(__m128 *)&v4PointOnPlane_36[32], v24), v4Force0_20);
      pAccumulatedForces->y = _mm_add_ps(
                                pAccumulatedForces->y,
                                _mm_add_ps(_mm_mul_ps(*(__m128 *)&v4PointOnPlane_36[16], v24), v4Force0_4));
      v28 = pAccumulatedForces->z;
      ++pAccumulatedForces;
      v29 = v38-- == 1;
      v25->x = v26;
      v25->z = _mm_add_ps(v28, v27);
      if ( v29 )
        break;
      v8 = Four_Zeros;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E3790
// Name: private: virtual void C_OP_TimeVaryingForce::AddForces(class FourVectors __near *,class CParticleCollection __near *,int,float,void __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_OP_TimeVaryingForce::AddForces(
        C_OP_TimeVaryingForce *this,
        FourVectors *pAccumulatedForces,
        CParticleCollection *pParticles,
        int nBlocks,
        float flStrength,
        void *pContext)
{
  __m128 v6; // xmm4
  __m128 v7; // xmm4
  __m128 v8; // xmm1
  __m128 v9; // xmm5
  float v10; // xmm2_4
  __m128 v11; // xmm1
  float v12; // xmm3_4
  __m128 v13; // xmm6
  __m128 v14; // xmm0
  __m128 v15; // xmm7
  int v16; // ecx
  __m128 v17; // xmm1
  __m128 *v18; // edx
  __m128 v19; // xmm2
  __m128 v20; // xmm1
  unsigned int v21; // esi
  __m128 *p_z; // eax
  __m128 v23; // xmm0
  __m128 v24; // xmm1
  __m128 v25; // xmm0
  __m128 box_max_4; // [esp+4h] [ebp-5Ch]
  __m128 box_max_20; // [esp+14h] [ebp-4Ch]
  __m128 box_max_36; // [esp+24h] [ebp-3Ch]
  __m128 fl4OODuration_4; // [esp+34h] [ebp-2Ch]
  __m128 fl4StartTime_4; // [esp+44h] [ebp-1Ch]

  v6 = 0;
  v6.m128_f32[0] = this->m_StartingForce.x * flStrength;
  v7 = _mm_shuffle_ps(v6, v6, 0);
  v8 = 0;
  v8.m128_f32[0] = this->m_StartingForce.y * flStrength;
  v9 = _mm_shuffle_ps(v8, v8, 0);
  v10 = this->m_EndingForce.y * flStrength;
  v11 = 0;
  v11.m128_f32[0] = this->m_StartingForce.z * flStrength;
  v12 = this->m_EndingForce.z * flStrength;
  v13 = _mm_shuffle_ps(v11, v11, 0);
  v14 = 0;
  v14.m128_f32[0] = this->m_EndingForce.x * flStrength;
  v15 = _mm_sub_ps(_mm_shuffle_ps(v14, v14, 0), v7);
  fl4OODuration_4 = _mm_shuffle_ps(
                      (__m128)LODWORD(this->m_flStartLerpTime),
                      (__m128)LODWORD(this->m_flStartLerpTime),
                      0);
  v14.m128_f32[0] = this->m_flEndLerpTime - this->m_flStartLerpTime;
  v16 = nBlocks;
  v17 = 0;
  v17.m128_f32[0] = v10;
  box_max_4 = _mm_sub_ps(_mm_shuffle_ps(v17, v17, 0), v9);
  v14.m128_f32[0] = 1.0 / v14.m128_f32[0];
  v18 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[8];
  v19 = 0;
  v20 = 0;
  v20.m128_f32[0] = v14.m128_f32[0];
  v19.m128_f32[0] = v12;
  box_max_36 = _mm_shuffle_ps(v20, v20, 0);
  box_max_20 = _mm_sub_ps(_mm_shuffle_ps(v19, v19, 0), v13);
  fl4StartTime_4 = pParticles->m_fl4CurTime;
  if ( nBlocks > 0 )
  {
    v21 = 16 * (pParticles->m_ParticleAttributes.m_nFloatStrides[8] >> 2);
    p_z = &pAccumulatedForces->z;
    do
    {
      v23 = _mm_max_ps(
              Four_Zeros,
              _mm_min_ps(
                Four_Ones,
                _mm_mul_ps(_mm_sub_ps(_mm_sub_ps(fl4StartTime_4, *v18), fl4OODuration_4), box_max_36)));
      p_z[-1] = _mm_add_ps(p_z[-1], _mm_add_ps(_mm_mul_ps(box_max_4, v23), v9));
      v24 = _mm_add_ps(_mm_add_ps(_mm_mul_ps(v15, v23), v7), p_z[-2]);
      v25 = _mm_add_ps(*p_z, _mm_add_ps(_mm_mul_ps(box_max_20, v23), v13));
      p_z[-2] = v24;
      *p_z = v25;
      p_z += 3;
      v18 = (__m128 *)((char *)v18 + v21);
      --v16;
    }
    while ( v16 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E3920
// Name: private: virtual void C_OP_TurbulenceForce::AddForces(class FourVectors __near *,class CParticleCollection __near *,int,float,void __near *)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge C_OP_TurbulenceForce::AddForces(
        C_OP_TurbulenceForce *this@<ecx>,
        int a2@<ebp>,
        FourVectors *pAccumulatedForces,
        CParticleCollection *pParticles,
        int nBlocks,
        float flStrength,
        void *pContext)
{
  __m128 *v8; // ecx
  __m128 *v9; // esi
  float *m_flNoiseCoordScale; // edx
  float *p_z; // eax
  const FourVectors *m_pData; // edi
  bool v13; // zf
  int *v15; // edi
  __m128 v16; // xmm1
  __m128 v17; // xmm0
  FourVectors *v18; // eax
  __m128 x; // xmm0
  __m128 v20; // xmm2
  __m128 v21; // xmm1
  __m128 v22; // xmm1
  __m128 v23; // xmm0
  __m128 v24; // xmm0
  __m128 v25; // xmm3
  __m128 y; // xmm1
  __m128 v27; // xmm1
  FourVectors v4Amounts[4]; // [esp+0h] [ebp-190h] BYREF
  _BYTE v29[12]; // [esp+E4h] [ebp-ACh] BYREF
  _BYTE fl4Scales_52[48]; // [esp+124h] [ebp-6Ch] OVERLAPPED BYREF
  int v31; // [esp+160h] [ebp-30h]
  int v32; // [esp+164h] [ebp-2Ch]
  __m128 *v33; // [esp+168h] [ebp-28h]
  unsigned int v34; // [esp+16Ch] [ebp-24h]
  int v35; // [esp+170h] [ebp-20h]
  C4VAttributeIterator pXYZ; // [esp+174h] [ebp-1Ch]
  int v37; // [esp+184h] [ebp-Ch]
  void *v38; // [esp+188h] [ebp-8h]
  void *retaddr; // [esp+190h] [ebp+0h]

  v37 = a2;
  v38 = retaddr;
  v8 = (__m128 *)pParticles->m_ParticleAttributes.m_pAttributes[0];
  v34 = pParticles->m_ParticleAttributes.m_nFloatStrides[0] / 0xC;
  pXYZ.m_pData = (const FourVectors *)v29;
  v33 = v8;
  v9 = (__m128 *)&v4Amounts[0].y.m128_i16[2];
  m_flNoiseCoordScale = this->m_flNoiseCoordScale;
  p_z = &this->m_vecNoiseAmount[0].z;
  v35 = 4;
  do
  {
    m_pData = pXYZ.m_pData;
    pXYZ.m_pData->x = _mm_shuffle_ps(
                        (__m128)*(unsigned int *)m_flNoiseCoordScale,
                        (__m128)*(unsigned int *)m_flNoiseCoordScale,
                        0);
    v9[-2] = _mm_shuffle_ps((__m128)*((unsigned int *)p_z - 2), (__m128)*((unsigned int *)p_z - 2), 0);
    v9[-1] = _mm_shuffle_ps((__m128)*((unsigned int *)p_z - 1), (__m128)*((unsigned int *)p_z - 1), 0);
    *v9 = _mm_shuffle_ps((__m128)*(unsigned int *)p_z, (__m128)*(unsigned int *)p_z, 0);
    ++m_flNoiseCoordScale;
    p_z += 3;
    v9 += 3;
    v13 = v35-- == 1;
    pXYZ.m_pData = (const FourVectors *)&m_pData->y;
  }
  while ( !v13 );
  if ( nBlocks > 0 )
  {
    v31 = 48 * v34;
    v32 = nBlocks;
    while ( 1 )
    {
      pXYZ.m_pData = (const FourVectors *)v29;
      v15 = &v4Amounts[0].y.m128_i32[1];
      v35 = 4;
      while ( 1 )
      {
        v16 = _mm_mul_ps(pXYZ.m_pData->x, v8[1]);
        v17 = _mm_mul_ps(pXYZ.m_pData->x, v8[2]);
        *(__m128 *)fl4Scales_52 = _mm_mul_ps(pXYZ.m_pData->x, *v8);
        *(__m128 *)&fl4Scales_52[16] = v16;
        *(__m128 *)&fl4Scales_52[32] = v17;
        v18 = DNoiseSIMD(result: (FourVectors *)&v4Amounts[3].z.m128_i16[2], pos: (const FourVectors *)fl4Scales_52);
        x = v18->x;
        v20 = *((__m128 *)v15 - 1);
        v21 = *((__m128 *)v15 - 2);
        pXYZ.m_pData = (const FourVectors *)((char *)pXYZ.m_pData + 16);
        *(__m128 *)fl4Scales_52 = x;
        v22 = _mm_mul_ps(v21, x);
        v23 = *(__m128 *)v15;
        *(__m128 *)&fl4Scales_52[16] = v18->y;
        v24 = _mm_add_ps(_mm_mul_ps(v23, v18->z), pAccumulatedForces->z);
        v25 = _mm_add_ps(pAccumulatedForces->x, v22);
        y = pAccumulatedForces->y;
        v15 += 12;
        v13 = v35-- == 1;
        v27 = _mm_add_ps(y, _mm_mul_ps(v20, *(__m128 *)&fl4Scales_52[16]));
        pAccumulatedForces->x = v25;
        pAccumulatedForces->y = v27;
        pAccumulatedForces->z = v24;
        if ( v13 )
          break;
        v8 = v33;
      }
      v33 = (__m128 *)((char *)v33 + v31);
      ++pAccumulatedForces;
      if ( --v32 == 0 )
        break;
      v8 = v33;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E3B30
// Name: private: virtual unsigned __int64 C_OP_ForceBasedOnDistanceToPlane::GetReadControlPointMask(void)const
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall C_OP_ForceBasedOnDistanceToPlane::GetReadControlPointMask(C_OP_ForceBasedOnDistanceToPlane *this)
{
  return 1LL << this->m_nControlPointNumber;
}

//------------------------------------------------------------------------------
// Address: 0x10342B70
// Name: private: virtual unsigned __int64 C_OP_AttractToControlPoint::GetReadControlPointMask(void)const
// Source: json
//------------------------------------------------------------------------------
__int64 __thiscall C_OP_AttractToControlPoint::GetReadControlPointMask(C_OP_RemapControlPointDirectionToVector *this)
{
  return 1LL << this->m_nControlPointNumber;
}

//------------------------------------------------------------------------------
// Address: 0x10419890
// Name: _dynamic_initializer_for__force_centerview__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__force_centerview__()
{
  ConCommand::ConCommand(
    this: &force_centerview,
    pName: "force_centerview",
    callback: IN_CenterView_f,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__force_centerview__);
}

//------------------------------------------------------------------------------
// Address: 0x1042D930
// Name: C_OP_RandomForce_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *C_OP_RandomForce_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<C_OP_RandomForce>();
  s_pUnpack_12 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042D950
// Name: C_OP_ParentVortices_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *C_OP_ParentVortices_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<C_OP_ParentVortices>();
  s_pUnpack_8 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042D970
// Name: C_OP_TwistAroundAxis_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *C_OP_TwistAroundAxis_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<C_OP_TwistAroundAxis>();
  s_pUnpack_10 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042D990
// Name: C_OP_AttractToControlPoint_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *C_OP_AttractToControlPoint_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<C_OP_AttractToControlPoint>();
  s_pUnpack_14 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042D9B0
// Name: C_OP_ForceBasedOnDistanceToPlane_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *C_OP_ForceBasedOnDistanceToPlane_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<C_OP_ForceBasedOnDistanceToPlane>();
  s_pUnpack_13 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042D9D0
// Name: C_OP_TimeVaryingForce_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *C_OP_TimeVaryingForce_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<C_OP_TimeVaryingForce>();
  s_pUnpack_11 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042D9F0
// Name: C_OP_TurbulenceForce_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *C_OP_TurbulenceForce_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<C_OP_TurbulenceForce>();
  s_pUnpack_9 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104329D0
// Name: _dynamic_atexit_destructor_for__force_centerview__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__force_centerview__()
{
  ConCommand::~ConCommand(this: &force_centerview);
}

//------------------------------------------------------------------------------
// Address: 0x102E0110
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class C_OP_RandomForce>(class C_OP_RandomForce __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<C_OP_RandomForce>()
{
  if ( (_S2_5 & 1) == 0 )
  {
    _S2_5 |= 1u;
    dword_105C0B88 = 3;
    dword_105C0B8C = 4;
    dword_105C0B90 = 4;
    dword_105C0B94 = -1;
    dword_105C0B98 = 0;
    dword_105C0B9C = 0;
    dword_105C0BA0 = 0;
    dword_105C0BA4 = 0;
    dword_105C0BA8 = 0;
    dword_105C0BAC = (int)"operator end fadein";
    dword_105C0BB0 = (int)"0";
    dword_105C0BB4 = 3;
    dword_105C0BB8 = 8;
    dword_105C0BBC = 4;
    dword_105C0BC0 = -1;
    dword_105C0BC4 = 0;
    dword_105C0BC8 = 0;
    dword_105C0BCC = 0;
    dword_105C0BD0 = 0;
    dword_105C0BD4 = 0;
    dword_105C0BD8 = (int)"operator start fadeout";
    dword_105C0BDC = (int)"0";
    dword_105C0BE0 = 3;
    dword_105C0BE4 = 12;
    dword_105C0BE8 = 4;
    dword_105C0BEC = -1;
    dword_105C0BF0 = 0;
    dword_105C0BF4 = 0;
    dword_105C0BF8 = 0;
    dword_105C0BFC = 0;
    dword_105C0C00 = 0;
    dword_105C0C04 = (int)"operator end fadeout";
    dword_105C0C08 = (int)"0";
    dword_105C0C0C = 3;
    dword_105C0C10 = 16;
    dword_105C0C14 = 4;
    dword_105C0C18 = -1;
    dword_105C0C1C = 0;
    dword_105C0C20 = 0;
    dword_105C0C24 = 0;
    dword_105C0C28 = 0;
    dword_105C0C2C = 0;
    dword_105C0C30 = (int)"operator fade oscillate";
    dword_105C0C34 = (int)"0";
    dword_105C0C38 = 3;
    dword_105C0C3C = 20;
    dword_105C0C40 = 4;
    dword_105C0C44 = -1;
    dword_105C0C48 = 0;
    dword_105C0C4C = 0;
    dword_105C0C50 = 0;
    dword_105C0C54 = 0;
    dword_105C0C58 = 0;
    dword_105C0C5C = (int)"operator time offset seed";
    dword_105C0C60 = (int)"0";
    dword_105C0C64 = 2;
    dword_105C0C68 = 32;
    dword_105C0C6C = 4;
    dword_105C0C70 = -1;
    dword_105C0C74 = 0;
    dword_105C0C78 = 0;
    dword_105C0C7C = 0;
    dword_105C0C80 = 0;
    dword_105C0C84 = 0;
    dword_105C0C88 = (int)"operator time offset min";
    dword_105C0C8C = (int)"0";
    dword_105C0C90 = 3;
    dword_105C0C94 = 24;
    dword_105C0C98 = 4;
    dword_105C0C9C = -1;
    dword_105C0CA0 = 0;
    dword_105C0CB8 = (int)"0";
    dword_105C0CE4 = (int)"0";
    dword_105C0CE8 = 2;
    dword_105C0D94 = (int)"0";
    dword_105C0CA4 = 0;
    dword_105C0CA8 = 0;
    dword_105C0CAC = 0;
    dword_105C0CB0 = 0;
    dword_105C0CB4 = (int)"operator time offset max";
    dword_105C0CBC = 3;
    dword_105C0CC0 = 28;
    dword_105C0CC4 = 4;
    dword_105C0CC8 = -1;
    dword_105C0CCC = 0;
    dword_105C0CD0 = 0;
    dword_105C0CD4 = 0;
    dword_105C0CD8 = 0;
    dword_105C0CDC = 0;
    dword_105C0CE0 = (int)"operator time scale seed";
    dword_105C0CEC = 48;
    dword_105C0CF0 = 4;
    dword_105C0CF4 = -1;
    dword_105C0CF8 = 0;
    dword_105C0CFC = 0;
    dword_105C0D00 = 0;
    dword_105C0D04 = 0;
    dword_105C0D08 = 0;
    dword_105C0D0C = (int)"operator time scale min";
    dword_105C0D10 = (int)"1";
    dword_105C0D14 = 3;
    dword_105C0D18 = 52;
    dword_105C0D1C = 4;
    dword_105C0D20 = -1;
    dword_105C0D24 = 0;
    dword_105C0D28 = 0;
    dword_105C0D2C = 0;
    dword_105C0D30 = 0;
    dword_105C0D34 = 0;
    dword_105C0D38 = (int)"operator time scale max";
    dword_105C0D3C = (int)"1";
    dword_105C0D40 = 3;
    dword_105C0D44 = 56;
    dword_105C0D48 = 4;
    dword_105C0D4C = -1;
    dword_105C0D50 = 0;
    dword_105C0D54 = 0;
    dword_105C0D58 = 0;
    dword_105C0D5C = 0;
    dword_105C0D60 = 0;
    dword_105C0D64 = (int)"operator time strength random scale max";
    dword_105C0D68 = (int)"1";
    dword_105C0D6C = 3;
    dword_105C0D70 = 44;
    dword_105C0D74 = 4;
    dword_105C0D78 = -1;
    dword_105C0D7C = 0;
    dword_105C0D80 = 0;
    dword_105C0D84 = 0;
    dword_105C0D88 = 0;
    dword_105C0D8C = 0;
    dword_105C0D90 = (int)"operator strength scale seed";
    dword_105C0D98 = 2;
    dword_105C0D9C = 36;
    dword_105C0DA0 = 4;
    dword_105C0DA4 = -1;
    dword_105C0DA8 = 0;
    dword_105C0DAC = 0;
    dword_105C0DB0 = 0;
    dword_105C0DB4 = 0;
    dword_105C0DB8 = 0;
    dword_105C0DBC = (int)"operator strength random scale min";
    dword_105C0DC0 = (int)"1";
    dword_105C0DC4 = 3;
    dword_105C0DC8 = 40;
    dword_105C0DCC = 4;
    dword_105C0DD0 = -1;
    dword_105C0DD4 = 0;
    dword_105C0DD8 = 0;
    dword_105C0DDC = 0;
    dword_105C0E1C = 2;
    dword_105C0DF0 = 3;
    dword_105C0E44 = (int)"0 0 0";
    dword_105C0E70 = (int)"0 0 0";
    dword_105C0DF8 = 4;
    dword_105C0E24 = 4;
    dword_105C0E48 = 10;
    dword_105C0E74 = 10;
    dword_105C0DEC = (int)"1";
    dword_105C0DE0 = 0;
    dword_105C0DE4 = 0;
    dword_105C0DE8 = (int)"operator strength random scale max";
    dword_105C0DF4 = 44;
    dword_105C0DFC = -1;
    dword_105C0E00 = 0;
    dword_105C0E04 = 0;
    dword_105C0E08 = 0;
    dword_105C0E0C = 0;
    dword_105C0E10 = 0;
    dword_105C0E14 = (int)"operator end cap state";
    dword_105C0E18 = (int)"-1";
    dword_105C0E20 = 64;
    dword_105C0E28 = -1;
    dword_105C0E2C = 0;
    dword_105C0E30 = 0;
    dword_105C0E34 = 0;
    dword_105C0E38 = 0;
    dword_105C0E3C = 0;
    dword_105C0E40 = (int)"min force";
    dword_105C0E4C = 88;
    dword_105C0E50 = 12;
    dword_105C0E54 = -1;
    dword_105C0E58 = 0;
    dword_105C0E5C = 0;
    dword_105C0E60 = 0;
    dword_105C0E64 = 0;
    dword_105C0E68 = 0;
    dword_105C0E6C = (int)"max force";
    dword_105C0E78 = 100;
    dword_105C0E7C = 12;
    dword_105C0E80 = -1;
    dword_105C0E84 = 0;
    dword_105C0E88 = 0;
    dword_105C0E8C = 0;
    dword_105C0E90 = 0;
    dword_105C0E94 = 0;
    dword_105C0E98 = 0;
    dword_105C0E9C = 0;
    dword_105C0EA0 = 0;
    dword_105C0EA4 = 0;
    dword_105C0EA8 = 0;
    dword_105C0EAC = -1;
    dword_105C0EB0 = 0;
    dword_105C0EB4 = 0;
    dword_105C0EB8 = 0;
    dword_105C0EBC = 0;
    dword_105C0EC0 = 0;
  }
  return unpack_8;
}

//------------------------------------------------------------------------------
// Address: 0x102E0B10
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class C_OP_ParentVortices>(class C_OP_ParentVortices __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<C_OP_ParentVortices>()
{
  if ( (_S3_2 & 1) == 0 )
  {
    _S3_2 |= 1u;
    dword_105C0ED0 = 3;
    dword_105C0ED4 = 4;
    dword_105C0ED8 = 4;
    dword_105C0EDC = -1;
    dword_105C0EE0 = 0;
    dword_105C0EE4 = 0;
    dword_105C0EE8 = 0;
    dword_105C0EEC = 0;
    dword_105C0EF0 = 0;
    dword_105C0EF4 = (int)"operator end fadein";
    dword_105C0EF8 = (int)"0";
    dword_105C0EFC = 3;
    dword_105C0F00 = 8;
    dword_105C0F04 = 4;
    dword_105C0F08 = -1;
    dword_105C0F0C = 0;
    dword_105C0F10 = 0;
    dword_105C0F14 = 0;
    dword_105C0F18 = 0;
    dword_105C0F1C = 0;
    dword_105C0F20 = (int)"operator start fadeout";
    dword_105C0F24 = (int)"0";
    dword_105C0F28 = 3;
    dword_105C0F2C = 12;
    dword_105C0F30 = 4;
    dword_105C0F34 = -1;
    dword_105C0F38 = 0;
    dword_105C0F3C = 0;
    dword_105C0F40 = 0;
    dword_105C0F44 = 0;
    dword_105C0F48 = 0;
    dword_105C0F4C = (int)"operator end fadeout";
    dword_105C0F50 = (int)"0";
    dword_105C0F54 = 3;
    dword_105C0F58 = 16;
    dword_105C0F5C = 4;
    dword_105C0F60 = -1;
    dword_105C0F64 = 0;
    dword_105C0F68 = 0;
    dword_105C0F6C = 0;
    dword_105C0F70 = 0;
    dword_105C0F74 = 0;
    dword_105C0F78 = (int)"operator fade oscillate";
    dword_105C0F7C = (int)"0";
    dword_105C0F80 = 3;
    dword_105C0F84 = 20;
    dword_105C0F88 = 4;
    dword_105C0F8C = -1;
    dword_105C0F90 = 0;
    dword_105C0F94 = 0;
    dword_105C0F98 = 0;
    dword_105C0F9C = 0;
    dword_105C0FA0 = 0;
    dword_105C0FA4 = (int)"operator time offset seed";
    dword_105C0FA8 = (int)"0";
    dword_105C0FAC = 2;
    dword_105C0FB0 = 32;
    dword_105C0FB4 = 4;
    dword_105C0FB8 = -1;
    dword_105C0FBC = 0;
    dword_105C0FC0 = 0;
    dword_105C0FC4 = 0;
    dword_105C0FC8 = 0;
    dword_105C0FCC = 0;
    dword_105C0FD0 = (int)"operator time offset min";
    dword_105C0FD4 = (int)"0";
    dword_105C0FD8 = 3;
    dword_105C0FDC = 24;
    dword_105C0FE0 = 4;
    dword_105C0FE4 = -1;
    dword_105C0FE8 = 0;
    dword_105C1030 = 2;
    dword_105C0FEC = 0;
    dword_105C0FF0 = 0;
    dword_105C0FF4 = 0;
    dword_105C0FF8 = 0;
    dword_105C0FFC = (int)"operator time offset max";
    dword_105C1000 = (int)"0";
    dword_105C1004 = 3;
    dword_105C1008 = 28;
    dword_105C100C = 4;
    dword_105C1010 = -1;
    dword_105C1014 = 0;
    dword_105C1018 = 0;
    dword_105C101C = 0;
    dword_105C1020 = 0;
    dword_105C1024 = 0;
    dword_105C1028 = (int)"operator time scale seed";
    dword_105C102C = (int)"0";
    dword_105C1034 = 48;
    dword_105C1038 = 4;
    dword_105C103C = -1;
    dword_105C1040 = 0;
    dword_105C1044 = 0;
    dword_105C1048 = 0;
    dword_105C104C = 0;
    dword_105C1050 = 0;
    dword_105C1054 = (int)"operator time scale min";
    dword_105C1058 = (int)"1";
    dword_105C105C = 3;
    dword_105C1060 = 52;
    dword_105C1064 = 4;
    dword_105C1068 = -1;
    dword_105C106C = 0;
    dword_105C1070 = 0;
    dword_105C1074 = 0;
    dword_105C1078 = 0;
    dword_105C107C = 0;
    dword_105C1080 = (int)"operator time scale max";
    dword_105C1084 = (int)"1";
    dword_105C1088 = 3;
    dword_105C108C = 56;
    dword_105C1090 = 4;
    dword_105C1094 = -1;
    dword_105C1098 = 0;
    dword_105C109C = 0;
    dword_105C10A0 = 0;
    dword_105C10A4 = 0;
    dword_105C10A8 = 0;
    dword_105C10AC = (int)"operator time strength random scale max";
    dword_105C10B0 = (int)"1";
    dword_105C10B4 = 3;
    dword_105C10B8 = 44;
    dword_105C10BC = 4;
    dword_105C10C0 = -1;
    dword_105C10C4 = 0;
    dword_105C10C8 = 0;
    dword_105C10CC = 0;
    dword_105C10D0 = 0;
    dword_105C10D4 = 0;
    dword_105C10D8 = (int)"operator strength scale seed";
    dword_105C10DC = (int)"0";
    dword_105C10E0 = 2;
    dword_105C10E4 = 36;
    dword_105C10E8 = 4;
    dword_105C10EC = -1;
    dword_105C10F0 = 0;
    dword_105C10F4 = 0;
    dword_105C10F8 = 0;
    dword_105C10FC = 0;
    dword_105C1100 = 0;
    dword_105C1104 = (int)"operator strength random scale min";
    dword_105C1108 = (int)"1";
    dword_105C110C = 3;
    dword_105C1110 = 40;
    dword_105C1114 = 4;
    dword_105C1118 = -1;
    dword_105C111C = 0;
    dword_105C1120 = 0;
    dword_105C1124 = 0;
    dword_105C1128 = 0;
    dword_105C118C = (int)"0";
    dword_105C11E4 = (int)"0";
    dword_105C1138 = 3;
    dword_105C1190 = 3;
    dword_105C1134 = (int)"1";
    dword_105C112C = 0;
    dword_105C1130 = (int)"operator strength random scale max";
    dword_105C113C = 44;
    dword_105C1140 = 4;
    dword_105C1144 = -1;
    dword_105C1148 = 0;
    dword_105C114C = 0;
    dword_105C1150 = 0;
    dword_105C1154 = 0;
    dword_105C1158 = 0;
    dword_105C115C = (int)"operator end cap state";
    dword_105C1160 = (int)"-1";
    dword_105C1164 = 2;
    dword_105C1168 = 64;
    dword_105C116C = 4;
    dword_105C1170 = -1;
    dword_105C1174 = 0;
    dword_105C1178 = 0;
    dword_105C117C = 0;
    dword_105C1180 = 0;
    dword_105C1184 = 0;
    dword_105C1188 = (int)"amount of force";
    dword_105C1194 = 88;
    dword_105C1198 = 4;
    dword_105C119C = -1;
    dword_105C11A0 = 0;
    dword_105C11A4 = 0;
    dword_105C11A8 = 0;
    dword_105C11AC = 0;
    dword_105C11B0 = 0;
    dword_105C11B4 = (int)"twist axis";
    dword_105C11B8 = (int)"0 0 1";
    dword_105C11BC = 10;
    dword_105C11C0 = 92;
    dword_105C11C4 = 12;
    dword_105C11C8 = -1;
    dword_105C11CC = 0;
    dword_105C11D0 = 0;
    dword_105C11D4 = 0;
    dword_105C11D8 = 0;
    dword_105C11DC = 0;
    dword_105C11E0 = (int)"flip twist axis with yaw";
    dword_105C11E8 = 4;
    dword_105C11EC = 104;
    dword_105C11F0 = 1;
    dword_105C11F4 = -1;
    dword_105C11F8 = 0;
    dword_105C11FC = 0;
    dword_105C1200 = 0;
    dword_105C1204 = 0;
    dword_105C1208 = 0;
    dword_105C120C = 0;
    dword_105C1210 = 0;
    dword_105C1214 = 0;
    dword_105C1218 = 0;
    dword_105C121C = 0;
    dword_105C1220 = -1;
    dword_105C1224 = 0;
    dword_105C1228 = 0;
    dword_105C122C = 0;
    dword_105C1230 = 0;
    dword_105C1234 = 0;
  }
  return unpack_9;
}

//------------------------------------------------------------------------------
// Address: 0x102E13A0
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class C_OP_TwistAroundAxis>(class C_OP_TwistAroundAxis __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<C_OP_TwistAroundAxis>()
{
  if ( (_S4_0 & 1) == 0 )
  {
    _S4_0 |= 1u;
    dword_105C1240 = 3;
    dword_105C1244 = 4;
    dword_105C1248 = 4;
    dword_105C124C = -1;
    dword_105C1250 = 0;
    dword_105C1254 = 0;
    dword_105C1258 = 0;
    dword_105C125C = 0;
    dword_105C1260 = 0;
    dword_105C1264 = (int)"operator end fadein";
    dword_105C1268 = (int)"0";
    dword_105C126C = 3;
    dword_105C1270 = 8;
    dword_105C1274 = 4;
    dword_105C1278 = -1;
    dword_105C127C = 0;
    dword_105C1280 = 0;
    dword_105C1284 = 0;
    dword_105C1288 = 0;
    dword_105C128C = 0;
    dword_105C1290 = (int)"operator start fadeout";
    dword_105C1294 = (int)"0";
    dword_105C1298 = 3;
    dword_105C129C = 12;
    dword_105C12A0 = 4;
    dword_105C12A4 = -1;
    dword_105C12A8 = 0;
    dword_105C12AC = 0;
    dword_105C12B0 = 0;
    dword_105C12B4 = 0;
    dword_105C12B8 = 0;
    dword_105C12BC = (int)"operator end fadeout";
    dword_105C12C0 = (int)"0";
    dword_105C12C4 = 3;
    dword_105C12C8 = 16;
    dword_105C12CC = 4;
    dword_105C12D0 = -1;
    dword_105C12D4 = 0;
    dword_105C12D8 = 0;
    dword_105C12DC = 0;
    dword_105C12E0 = 0;
    dword_105C12E4 = 0;
    dword_105C12E8 = (int)"operator fade oscillate";
    dword_105C12EC = (int)"0";
    dword_105C12F0 = 3;
    dword_105C12F4 = 20;
    dword_105C12F8 = 4;
    dword_105C12FC = -1;
    dword_105C1300 = 0;
    dword_105C1304 = 0;
    dword_105C1308 = 0;
    dword_105C130C = 0;
    dword_105C1310 = 0;
    dword_105C1314 = (int)"operator time offset seed";
    dword_105C1318 = (int)"0";
    dword_105C131C = 2;
    dword_105C1320 = 32;
    dword_105C1324 = 4;
    dword_105C1328 = -1;
    dword_105C132C = 0;
    dword_105C1330 = 0;
    dword_105C1334 = 0;
    dword_105C1338 = 0;
    dword_105C133C = 0;
    dword_105C1340 = (int)"operator time offset min";
    dword_105C1344 = (int)"0";
    dword_105C1348 = 3;
    dword_105C134C = 24;
    dword_105C1350 = 4;
    dword_105C1354 = -1;
    dword_105C1358 = 0;
    dword_105C13A0 = 2;
    dword_105C135C = 0;
    dword_105C1360 = 0;
    dword_105C1364 = 0;
    dword_105C1368 = 0;
    dword_105C136C = (int)"operator time offset max";
    dword_105C1370 = (int)"0";
    dword_105C1374 = 3;
    dword_105C1378 = 28;
    dword_105C137C = 4;
    dword_105C1380 = -1;
    dword_105C1384 = 0;
    dword_105C1388 = 0;
    dword_105C138C = 0;
    dword_105C1390 = 0;
    dword_105C1394 = 0;
    dword_105C1398 = (int)"operator time scale seed";
    dword_105C139C = (int)"0";
    dword_105C13A4 = 48;
    dword_105C13A8 = 4;
    dword_105C13AC = -1;
    dword_105C13B0 = 0;
    dword_105C13B4 = 0;
    dword_105C13B8 = 0;
    dword_105C13BC = 0;
    dword_105C13C0 = 0;
    dword_105C13C4 = (int)"operator time scale min";
    dword_105C13C8 = (int)"1";
    dword_105C13CC = 3;
    dword_105C13D0 = 52;
    dword_105C13D4 = 4;
    dword_105C13D8 = -1;
    dword_105C13DC = 0;
    dword_105C13E0 = 0;
    dword_105C13E4 = 0;
    dword_105C13E8 = 0;
    dword_105C13EC = 0;
    dword_105C13F0 = (int)"operator time scale max";
    dword_105C13F4 = (int)"1";
    dword_105C13F8 = 3;
    dword_105C13FC = 56;
    dword_105C1400 = 4;
    dword_105C1404 = -1;
    dword_105C1408 = 0;
    dword_105C140C = 0;
    dword_105C1410 = 0;
    dword_105C1414 = 0;
    dword_105C1418 = 0;
    dword_105C141C = (int)"operator time strength random scale max";
    dword_105C1420 = (int)"1";
    dword_105C1424 = 3;
    dword_105C1428 = 44;
    dword_105C142C = 4;
    dword_105C1430 = -1;
    dword_105C1434 = 0;
    dword_105C1438 = 0;
    dword_105C143C = 0;
    dword_105C1440 = 0;
    dword_105C1444 = 0;
    dword_105C1448 = (int)"operator strength scale seed";
    dword_105C144C = (int)"0";
    dword_105C1450 = 2;
    dword_105C1454 = 36;
    dword_105C1458 = 4;
    dword_105C145C = -1;
    dword_105C1460 = 0;
    dword_105C1464 = 0;
    dword_105C1468 = 0;
    dword_105C146C = 0;
    dword_105C1470 = 0;
    dword_105C1474 = (int)"operator strength random scale min";
    dword_105C1478 = (int)"1";
    dword_105C147C = 3;
    dword_105C1480 = 40;
    dword_105C1484 = 4;
    dword_105C1488 = -1;
    dword_105C148C = 0;
    dword_105C1490 = 0;
    dword_105C1494 = 0;
    dword_105C1498 = 0;
    dword_105C14FC = (int)"0";
    dword_105C1554 = (int)"0";
    dword_105C14A8 = 3;
    dword_105C1500 = 3;
    dword_105C14A4 = (int)"1";
    dword_105C149C = 0;
    dword_105C14A0 = (int)"operator strength random scale max";
    dword_105C14AC = 44;
    dword_105C14B0 = 4;
    dword_105C14B4 = -1;
    dword_105C14B8 = 0;
    dword_105C14BC = 0;
    dword_105C14C0 = 0;
    dword_105C14C4 = 0;
    dword_105C14C8 = 0;
    dword_105C14CC = (int)"operator end cap state";
    dword_105C14D0 = (int)"-1";
    dword_105C14D4 = 2;
    dword_105C14D8 = 64;
    dword_105C14DC = 4;
    dword_105C14E0 = -1;
    dword_105C14E4 = 0;
    dword_105C14E8 = 0;
    dword_105C14EC = 0;
    dword_105C14F0 = 0;
    dword_105C14F4 = 0;
    dword_105C14F8 = (int)"amount of force";
    dword_105C1504 = 88;
    dword_105C1508 = 4;
    dword_105C150C = -1;
    dword_105C1510 = 0;
    dword_105C1514 = 0;
    dword_105C1518 = 0;
    dword_105C151C = 0;
    dword_105C1520 = 0;
    dword_105C1524 = (int)"twist axis";
    dword_105C1528 = (int)"0 0 1";
    dword_105C152C = 10;
    dword_105C1530 = 92;
    dword_105C1534 = 12;
    dword_105C1538 = -1;
    dword_105C153C = 0;
    dword_105C1540 = 0;
    dword_105C1544 = 0;
    dword_105C1548 = 0;
    dword_105C154C = 0;
    dword_105C1550 = (int)"object local space axis 0/1";
    dword_105C1558 = 4;
    dword_105C155C = 104;
    dword_105C1560 = 1;
    dword_105C1564 = -1;
    dword_105C1568 = 0;
    dword_105C156C = 0;
    dword_105C1570 = 0;
    dword_105C1574 = 0;
    dword_105C1578 = 0;
    dword_105C157C = 0;
    dword_105C1580 = 0;
    dword_105C1584 = 0;
    dword_105C1588 = 0;
    dword_105C158C = 0;
    dword_105C1590 = -1;
    dword_105C1594 = 0;
    dword_105C1598 = 0;
    dword_105C159C = 0;
    dword_105C15A0 = 0;
    dword_105C15A4 = 0;
  }
  return unpack_10;
}

//------------------------------------------------------------------------------
// Address: 0x102E1B00
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class C_OP_AttractToControlPoint>(class C_OP_AttractToControlPoint __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<C_OP_AttractToControlPoint>()
{
  if ( (_S5_240 & 1) == 0 )
  {
    _S5_240 |= 1u;
    dword_105C15B0 = 3;
    dword_105C15B4 = 4;
    dword_105C15B8 = 4;
    dword_105C15BC = -1;
    dword_105C15C0 = 0;
    dword_105C15C4 = 0;
    dword_105C15C8 = 0;
    dword_105C15CC = 0;
    dword_105C15D0 = 0;
    dword_105C15D4 = (int)"operator end fadein";
    dword_105C15D8 = (int)"0";
    dword_105C15DC = 3;
    dword_105C15E0 = 8;
    dword_105C15E4 = 4;
    dword_105C15E8 = -1;
    dword_105C15EC = 0;
    dword_105C15F0 = 0;
    dword_105C15F4 = 0;
    dword_105C15F8 = 0;
    dword_105C15FC = 0;
    dword_105C1600 = (int)"operator start fadeout";
    dword_105C1604 = (int)"0";
    dword_105C1608 = 3;
    dword_105C160C = 12;
    dword_105C1610 = 4;
    dword_105C1614 = -1;
    dword_105C1618 = 0;
    dword_105C161C = 0;
    dword_105C1620 = 0;
    dword_105C1624 = 0;
    dword_105C1628 = 0;
    dword_105C162C = (int)"operator end fadeout";
    dword_105C1630 = (int)"0";
    dword_105C1634 = 3;
    dword_105C1638 = 16;
    dword_105C163C = 4;
    dword_105C1640 = -1;
    dword_105C1644 = 0;
    dword_105C1648 = 0;
    dword_105C164C = 0;
    dword_105C1650 = 0;
    dword_105C1654 = 0;
    dword_105C1658 = (int)"operator fade oscillate";
    dword_105C165C = (int)"0";
    dword_105C1660 = 3;
    dword_105C1664 = 20;
    dword_105C1668 = 4;
    dword_105C166C = -1;
    dword_105C1670 = 0;
    dword_105C1674 = 0;
    dword_105C1678 = 0;
    dword_105C167C = 0;
    dword_105C1680 = 0;
    dword_105C1684 = (int)"operator time offset seed";
    dword_105C1688 = (int)"0";
    dword_105C168C = 2;
    dword_105C1690 = 32;
    dword_105C1694 = 4;
    dword_105C1698 = -1;
    dword_105C169C = 0;
    dword_105C16A0 = 0;
    dword_105C16A4 = 0;
    dword_105C16A8 = 0;
    dword_105C16AC = 0;
    dword_105C16B0 = (int)"operator time offset min";
    dword_105C16B4 = (int)"0";
    dword_105C16B8 = 3;
    dword_105C16BC = 24;
    dword_105C16C0 = 4;
    dword_105C16C4 = -1;
    dword_105C16C8 = 0;
    dword_105C1710 = 2;
    dword_105C16CC = 0;
    dword_105C16D0 = 0;
    dword_105C16D4 = 0;
    dword_105C16D8 = 0;
    dword_105C16DC = (int)"operator time offset max";
    dword_105C16E0 = (int)"0";
    dword_105C16E4 = 3;
    dword_105C16E8 = 28;
    dword_105C16EC = 4;
    dword_105C16F0 = -1;
    dword_105C16F4 = 0;
    dword_105C16F8 = 0;
    dword_105C16FC = 0;
    dword_105C1700 = 0;
    dword_105C1704 = 0;
    dword_105C1708 = (int)"operator time scale seed";
    dword_105C170C = (int)"0";
    dword_105C1714 = 48;
    dword_105C1718 = 4;
    dword_105C171C = -1;
    dword_105C1720 = 0;
    dword_105C1724 = 0;
    dword_105C1728 = 0;
    dword_105C172C = 0;
    dword_105C1730 = 0;
    dword_105C1734 = (int)"operator time scale min";
    dword_105C1738 = (int)"1";
    dword_105C173C = 3;
    dword_105C1740 = 52;
    dword_105C1744 = 4;
    dword_105C1748 = -1;
    dword_105C174C = 0;
    dword_105C1750 = 0;
    dword_105C1754 = 0;
    dword_105C1758 = 0;
    dword_105C175C = 0;
    dword_105C1760 = (int)"operator time scale max";
    dword_105C1764 = (int)"1";
    dword_105C1768 = 3;
    dword_105C176C = 56;
    dword_105C1770 = 4;
    dword_105C1774 = -1;
    dword_105C1778 = 0;
    dword_105C177C = 0;
    dword_105C1780 = 0;
    dword_105C1784 = 0;
    dword_105C1788 = 0;
    dword_105C178C = (int)"operator time strength random scale max";
    dword_105C1790 = (int)"1";
    dword_105C1794 = 3;
    dword_105C1798 = 44;
    dword_105C179C = 4;
    dword_105C17A0 = -1;
    dword_105C17A4 = 0;
    dword_105C17A8 = 0;
    dword_105C17AC = 0;
    dword_105C17B0 = 0;
    dword_105C17B4 = 0;
    dword_105C17B8 = (int)"operator strength scale seed";
    dword_105C17BC = (int)"0";
    dword_105C17C0 = 2;
    dword_105C17C4 = 36;
    dword_105C17C8 = 4;
    dword_105C17CC = -1;
    dword_105C17D0 = 0;
    dword_105C17D4 = 0;
    dword_105C17D8 = 0;
    dword_105C17DC = 0;
    dword_105C17E0 = 0;
    dword_105C17E4 = (int)"operator strength random scale min";
    dword_105C17E8 = (int)"1";
    dword_105C17EC = 3;
    dword_105C17F0 = 40;
    dword_105C17F4 = 4;
    dword_105C17F8 = -1;
    dword_105C17FC = 0;
    dword_105C1800 = 0;
    dword_105C1804 = 0;
    dword_105C1808 = 0;
    dword_105C1814 = (int)"1";
    dword_105C186C = (int)"0";
    dword_105C18C4 = (int)"0";
    dword_105C1818 = 3;
    dword_105C1870 = 3;
    dword_105C189C = 3;
    dword_105C1844 = 2;
    dword_105C18C8 = 2;
    dword_105C180C = 0;
    dword_105C1810 = (int)"operator strength random scale max";
    dword_105C181C = 44;
    dword_105C1820 = 4;
    dword_105C1824 = -1;
    dword_105C1828 = 0;
    dword_105C182C = 0;
    dword_105C1830 = 0;
    dword_105C1834 = 0;
    dword_105C1838 = 0;
    dword_105C183C = (int)"operator end cap state";
    dword_105C1840 = (int)"-1";
    dword_105C1848 = 64;
    dword_105C184C = 4;
    dword_105C1850 = -1;
    dword_105C1854 = 0;
    dword_105C1858 = 0;
    dword_105C185C = 0;
    dword_105C1860 = 0;
    dword_105C1864 = 0;
    dword_105C1868 = (int)"amount of force";
    dword_105C1874 = 88;
    dword_105C1878 = 4;
    dword_105C187C = -1;
    dword_105C1880 = 0;
    dword_105C1884 = 0;
    dword_105C1888 = 0;
    dword_105C188C = 0;
    dword_105C1890 = 0;
    dword_105C1894 = (int)"falloff power";
    dword_105C1898 = (int)"2";
    dword_105C18A0 = 92;
    dword_105C18A4 = 4;
    dword_105C18A8 = -1;
    dword_105C18AC = 0;
    dword_105C18B0 = 0;
    dword_105C18B4 = 0;
    dword_105C18B8 = 0;
    dword_105C18BC = 0;
    dword_105C18C0 = (int)"control point number";
    dword_105C18CC = 96;
    dword_105C18D0 = 4;
    dword_105C18D4 = -1;
    dword_105C18D8 = 0;
    dword_105C18DC = 0;
    dword_105C18E0 = 0;
    dword_105C18E4 = 0;
    dword_105C18E8 = 0;
    dword_105C18EC = 0;
    dword_105C18F0 = 0;
    dword_105C18F4 = 0;
    dword_105C18F8 = 0;
    dword_105C18FC = 0;
    dword_105C1900 = -1;
    dword_105C1904 = 0;
    dword_105C1908 = 0;
    dword_105C190C = 0;
    dword_105C1910 = 0;
    dword_105C1914 = 0;
  }
  return unpack_11;
}

//------------------------------------------------------------------------------
// Address: 0x102E20A0
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class C_OP_ForceBasedOnDistanceToPlane>(class C_OP_ForceBasedOnDistanceToPlane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<C_OP_ForceBasedOnDistanceToPlane>()
{
  if ( (_S6_64 & 1) == 0 )
  {
    _S6_64 |= 1u;
    dword_105C1920 = 3;
    dword_105C1924 = 4;
    dword_105C1928 = 4;
    dword_105C192C = -1;
    dword_105C1930 = 0;
    dword_105C1934 = 0;
    dword_105C1938 = 0;
    dword_105C193C = 0;
    dword_105C1940 = 0;
    dword_105C1944 = (int)"operator end fadein";
    dword_105C1948 = (int)"0";
    dword_105C194C = 3;
    dword_105C1950 = 8;
    dword_105C1954 = 4;
    dword_105C1958 = -1;
    dword_105C195C = 0;
    dword_105C1960 = 0;
    dword_105C1964 = 0;
    dword_105C1968 = 0;
    dword_105C196C = 0;
    dword_105C1970 = (int)"operator start fadeout";
    dword_105C1974 = (int)"0";
    dword_105C1978 = 3;
    dword_105C197C = 12;
    dword_105C1980 = 4;
    dword_105C1984 = -1;
    dword_105C1988 = 0;
    dword_105C198C = 0;
    dword_105C1990 = 0;
    dword_105C1994 = 0;
    dword_105C1998 = 0;
    dword_105C199C = (int)"operator end fadeout";
    dword_105C19A0 = (int)"0";
    dword_105C19A4 = 3;
    dword_105C19A8 = 16;
    dword_105C19AC = 4;
    dword_105C19B0 = -1;
    dword_105C19B4 = 0;
    dword_105C19B8 = 0;
    dword_105C19BC = 0;
    dword_105C19C0 = 0;
    dword_105C19C4 = 0;
    dword_105C19C8 = (int)"operator fade oscillate";
    dword_105C19CC = (int)"0";
    dword_105C19D0 = 3;
    dword_105C19D4 = 20;
    dword_105C19D8 = 4;
    dword_105C19DC = -1;
    dword_105C19E0 = 0;
    dword_105C19E4 = 0;
    dword_105C19E8 = 0;
    dword_105C19EC = 0;
    dword_105C19F0 = 0;
    dword_105C19F4 = (int)"operator time offset seed";
    dword_105C19F8 = (int)"0";
    dword_105C19FC = 2;
    dword_105C1A00 = 32;
    dword_105C1A04 = 4;
    dword_105C1A08 = -1;
    dword_105C1A0C = 0;
    dword_105C1A10 = 0;
    dword_105C1A14 = 0;
    dword_105C1A18 = 0;
    dword_105C1A1C = 0;
    dword_105C1A20 = (int)"operator time offset min";
    dword_105C1A24 = (int)"0";
    dword_105C1A28 = 3;
    dword_105C1A2C = 24;
    dword_105C1A30 = 4;
    dword_105C1A34 = -1;
    dword_105C1A38 = 0;
    dword_105C1A80 = 2;
    dword_105C1A3C = 0;
    dword_105C1A40 = 0;
    dword_105C1A44 = 0;
    dword_105C1A48 = 0;
    dword_105C1A4C = (int)"operator time offset max";
    dword_105C1A50 = (int)"0";
    dword_105C1A54 = 3;
    dword_105C1A58 = 28;
    dword_105C1A5C = 4;
    dword_105C1A60 = -1;
    dword_105C1A64 = 0;
    dword_105C1A68 = 0;
    dword_105C1A6C = 0;
    dword_105C1A70 = 0;
    dword_105C1A74 = 0;
    dword_105C1A78 = (int)"operator time scale seed";
    dword_105C1A7C = (int)"0";
    dword_105C1A84 = 48;
    dword_105C1A88 = 4;
    dword_105C1A8C = -1;
    dword_105C1A90 = 0;
    dword_105C1A94 = 0;
    dword_105C1A98 = 0;
    dword_105C1A9C = 0;
    dword_105C1AA0 = 0;
    dword_105C1AA4 = (int)"operator time scale min";
    dword_105C1AA8 = (int)"1";
    dword_105C1AAC = 3;
    dword_105C1AB0 = 52;
    dword_105C1AB4 = 4;
    dword_105C1AB8 = -1;
    dword_105C1ABC = 0;
    dword_105C1AC0 = 0;
    dword_105C1AC4 = 0;
    dword_105C1AC8 = 0;
    dword_105C1ACC = 0;
    dword_105C1AD0 = (int)"operator time scale max";
    dword_105C1AD4 = (int)"1";
    dword_105C1AD8 = 3;
    dword_105C1ADC = 56;
    dword_105C1AE0 = 4;
    dword_105C1AE4 = -1;
    dword_105C1AE8 = 0;
    dword_105C1AEC = 0;
    dword_105C1AF0 = 0;
    dword_105C1AF4 = 0;
    dword_105C1AF8 = 0;
    dword_105C1AFC = (int)"operator time strength random scale max";
    dword_105C1B00 = (int)"1";
    dword_105C1B04 = 3;
    dword_105C1B08 = 44;
    dword_105C1B0C = 4;
    dword_105C1B10 = -1;
    dword_105C1B14 = 0;
    dword_105C1B18 = 0;
    dword_105C1B1C = 0;
    dword_105C1B20 = 0;
    dword_105C1B24 = 0;
    dword_105C1B28 = (int)"operator strength scale seed";
    dword_105C1B2C = (int)"0";
    dword_105C1B30 = 2;
    dword_105C1B34 = 36;
    dword_105C1B38 = 4;
    dword_105C1B3C = -1;
    dword_105C1B40 = 0;
    dword_105C1B44 = 0;
    dword_105C1B48 = 0;
    dword_105C1B4C = 0;
    dword_105C1B50 = 0;
    dword_105C1B54 = (int)"operator strength random scale min";
    dword_105C1B58 = (int)"1";
    dword_105C1B5C = 3;
    dword_105C1B60 = 40;
    dword_105C1B64 = 4;
    dword_105C1B68 = -1;
    dword_105C1B6C = 0;
    dword_105C1B70 = 0;
    dword_105C1B74 = 0;
    dword_105C1B78 = 0;
    dword_105C1B7C = 0;
    dword_105C1B80 = (int)"operator strength random scale max";
    dword_105C1B84 = (int)"1";
    dword_105C1B88 = 3;
    dword_105C1B8C = 44;
    dword_105C1B90 = 4;
    dword_105C1B94 = -1;
    dword_105C1B98 = 0;
    dword_105C1B9C = 0;
    dword_105C1BA0 = 0;
    dword_105C1BA4 = 0;
    dword_105C1BA8 = 0;
    dword_105C1BAC = (int)"operator end cap state";
    dword_105C1BB0 = (int)"-1";
    dword_105C1BB4 = 2;
    dword_105C1BB8 = 64;
    dword_105C1BBC = 4;
    dword_105C1BC0 = -1;
    dword_105C1BC4 = 0;
    dword_105C1BC8 = 0;
    dword_105C1BCC = 0;
    dword_105C1BD0 = 0;
    dword_105C1BD4 = 0;
    dword_105C1BD8 = (int)"Min distance from plane";
    dword_105C1BDC = (int)"0";
    dword_105C1BE0 = 3;
    dword_105C1BE4 = 88;
    dword_105C1BE8 = 4;
    dword_105C1BEC = -1;
    dword_105C1BF0 = 0;
    dword_105C1BF4 = 0;
    dword_105C1BF8 = 0;
    dword_105C1BFC = 0;
    dword_105C1C00 = 0;
    dword_105C1C04 = (int)"Force at Min distance";
    dword_105C1C08 = (int)"0 0 0";
    dword_105C1C0C = 10;
    dword_105C1C10 = 92;
    dword_105C1C14 = 12;
    dword_105C1C18 = -1;
    dword_105C1C1C = 0;
    dword_105C1C20 = 0;
    dword_105C1C24 = 0;
    dword_105C1C28 = 0;
    dword_105C1C2C = 0;
    dword_105C1C30 = (int)"Max Distance from plane";
    dword_105C1C34 = (int)"1";
    dword_105C1C38 = 3;
    dword_105C1C3C = 104;
    dword_105C1C40 = 4;
    dword_105C1C44 = -1;
    dword_105C1C48 = 0;
    dword_105C1C4C = 0;
    dword_105C1C50 = 0;
    dword_105C1C54 = 0;
    dword_105C1C58 = 0;
    dword_105C1C5C = (int)"Force at Max distance";
    dword_105C1C60 = (int)"0 0 0";
    dword_105C1C64 = 10;
    dword_105C1C68 = 108;
    dword_105C1C6C = 12;
    dword_105C1C70 = -1;
    dword_105C1C74 = 0;
    dword_105C1C78 = 0;
    dword_105C1C7C = 0;
    dword_105C1C80 = 0;
    dword_105C1C84 = 0;
    dword_105C1C88 = (int)"Plane Normal";
    dword_105C1C8C = (int)"0 0 1";
    dword_105C1C90 = 10;
    dword_105C1C94 = 120;
    dword_105C1C98 = 12;
    dword_105C1C9C = -1;
    dword_105C1CA0 = 0;
    dword_105C1CA4 = 0;
    dword_105C1CA8 = 0;
    dword_105C1CAC = 0;
    dword_105C1CB0 = 0;
    dword_105C1CB4 = (int)"Control point number";
    dword_105C1CB8 = (int)"0";
    dword_105C1CBC = 2;
    dword_105C1CE8 = 3;
    dword_105C1CE4 = (int)"1";
    dword_105C1CC0 = 132;
    dword_105C1CC4 = 4;
    dword_105C1CC8 = -1;
    dword_105C1CCC = 0;
    dword_105C1CD0 = 0;
    dword_105C1CD4 = 0;
    dword_105C1CD8 = 0;
    dword_105C1CDC = 0;
    dword_105C1CE0 = (int)"Exponent";
    dword_105C1CEC = 136;
    dword_105C1CF0 = 4;
    dword_105C1CF4 = -1;
    dword_105C1CF8 = 0;
    dword_105C1CFC = 0;
    dword_105C1D00 = 0;
    dword_105C1D04 = 0;
    dword_105C1D08 = 0;
    dword_105C1D0C = 0;
    dword_105C1D10 = 0;
    dword_105C1D14 = 0;
    dword_105C1D18 = 0;
    dword_105C1D1C = 0;
    dword_105C1D20 = -1;
    dword_105C1D24 = 0;
    dword_105C1D28 = 0;
    dword_105C1D2C = 0;
    dword_105C1D30 = 0;
    dword_105C1D34 = 0;
  }
  return unpack_12;
}

//------------------------------------------------------------------------------
// Address: 0x102E2770
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class C_OP_TimeVaryingForce>(class C_OP_TimeVaryingForce __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<C_OP_TimeVaryingForce>()
{
  if ( (_S7_28 & 1) == 0 )
  {
    _S7_28 |= 1u;
    dword_105C1D40 = 3;
    dword_105C1D44 = 4;
    dword_105C1D48 = 4;
    dword_105C1D4C = -1;
    dword_105C1D50 = 0;
    dword_105C1D54 = 0;
    dword_105C1D58 = 0;
    dword_105C1D5C = 0;
    dword_105C1D60 = 0;
    dword_105C1D64 = (int)"operator end fadein";
    dword_105C1D68 = (int)"0";
    dword_105C1D6C = 3;
    dword_105C1D70 = 8;
    dword_105C1D74 = 4;
    dword_105C1D78 = -1;
    dword_105C1D7C = 0;
    dword_105C1D80 = 0;
    dword_105C1D84 = 0;
    dword_105C1D88 = 0;
    dword_105C1D8C = 0;
    dword_105C1D90 = (int)"operator start fadeout";
    dword_105C1D94 = (int)"0";
    dword_105C1D98 = 3;
    dword_105C1D9C = 12;
    dword_105C1DA0 = 4;
    dword_105C1DA4 = -1;
    dword_105C1DA8 = 0;
    dword_105C1DAC = 0;
    dword_105C1DB0 = 0;
    dword_105C1DB4 = 0;
    dword_105C1DB8 = 0;
    dword_105C1DBC = (int)"operator end fadeout";
    dword_105C1DC0 = (int)"0";
    dword_105C1DC4 = 3;
    dword_105C1DC8 = 16;
    dword_105C1DCC = 4;
    dword_105C1DD0 = -1;
    dword_105C1DD4 = 0;
    dword_105C1DD8 = 0;
    dword_105C1DDC = 0;
    dword_105C1DE0 = 0;
    dword_105C1DE4 = 0;
    dword_105C1DE8 = (int)"operator fade oscillate";
    dword_105C1DEC = (int)"0";
    dword_105C1DF0 = 3;
    dword_105C1DF4 = 20;
    dword_105C1DF8 = 4;
    dword_105C1DFC = -1;
    dword_105C1E00 = 0;
    dword_105C1E04 = 0;
    dword_105C1E08 = 0;
    dword_105C1E0C = 0;
    dword_105C1E10 = 0;
    dword_105C1E14 = (int)"operator time offset seed";
    dword_105C1E18 = (int)"0";
    dword_105C1E1C = 2;
    dword_105C1E20 = 32;
    dword_105C1E24 = 4;
    dword_105C1E28 = -1;
    dword_105C1E2C = 0;
    dword_105C1E30 = 0;
    dword_105C1E34 = 0;
    dword_105C1E38 = 0;
    dword_105C1E3C = 0;
    dword_105C1E40 = (int)"operator time offset min";
    dword_105C1E44 = (int)"0";
    dword_105C1E48 = 3;
    dword_105C1E4C = 24;
    dword_105C1E50 = 4;
    dword_105C1E54 = -1;
    dword_105C1E58 = 0;
    dword_105C1EA0 = 2;
    dword_105C1E5C = 0;
    dword_105C1E60 = 0;
    dword_105C1E64 = 0;
    dword_105C1E68 = 0;
    dword_105C1E6C = (int)"operator time offset max";
    dword_105C1E70 = (int)"0";
    dword_105C1E74 = 3;
    dword_105C1E78 = 28;
    dword_105C1E7C = 4;
    dword_105C1E80 = -1;
    dword_105C1E84 = 0;
    dword_105C1E88 = 0;
    dword_105C1E8C = 0;
    dword_105C1E90 = 0;
    dword_105C1E94 = 0;
    dword_105C1E98 = (int)"operator time scale seed";
    dword_105C1E9C = (int)"0";
    dword_105C1EA4 = 48;
    dword_105C1EA8 = 4;
    dword_105C1EAC = -1;
    dword_105C1EB0 = 0;
    dword_105C1EB4 = 0;
    dword_105C1EB8 = 0;
    dword_105C1EBC = 0;
    dword_105C1EC0 = 0;
    dword_105C1EC4 = (int)"operator time scale min";
    dword_105C1EC8 = (int)"1";
    dword_105C1ECC = 3;
    dword_105C1ED0 = 52;
    dword_105C1ED4 = 4;
    dword_105C1ED8 = -1;
    dword_105C1EDC = 0;
    dword_105C1EE0 = 0;
    dword_105C1EE4 = 0;
    dword_105C1EE8 = 0;
    dword_105C1EEC = 0;
    dword_105C1EF0 = (int)"operator time scale max";
    dword_105C1EF4 = (int)"1";
    dword_105C1EF8 = 3;
    dword_105C1EFC = 56;
    dword_105C1F00 = 4;
    dword_105C1F04 = -1;
    dword_105C1F08 = 0;
    dword_105C1F0C = 0;
    dword_105C1F10 = 0;
    dword_105C1F14 = 0;
    dword_105C1F18 = 0;
    dword_105C1F1C = (int)"operator time strength random scale max";
    dword_105C1F20 = (int)"1";
    dword_105C1F24 = 3;
    dword_105C1F28 = 44;
    dword_105C1F2C = 4;
    dword_105C1F30 = -1;
    dword_105C1F34 = 0;
    dword_105C1F38 = 0;
    dword_105C1F3C = 0;
    dword_105C1F40 = 0;
    dword_105C1F44 = 0;
    dword_105C1F48 = (int)"operator strength scale seed";
    dword_105C1F4C = (int)"0";
    dword_105C1F50 = 2;
    dword_105C1F54 = 36;
    dword_105C1F58 = 4;
    dword_105C1F5C = -1;
    dword_105C1F60 = 0;
    dword_105C1F64 = 0;
    dword_105C1F68 = 0;
    dword_105C1F6C = 0;
    dword_105C1F70 = 0;
    dword_105C1F74 = (int)"operator strength random scale min";
    dword_105C1F78 = (int)"1";
    dword_105C1F7C = 3;
    dword_105C1F80 = 40;
    dword_105C1F84 = 4;
    dword_105C1F88 = -1;
    dword_105C1F8C = 0;
    dword_105C1F90 = 0;
    dword_105C1F94 = 0;
    dword_105C1F98 = 0;
    dword_105C1FFC = (int)"0";
    dword_105C1FA4 = (int)"1";
    dword_105C202C = 10;
    dword_105C2084 = 10;
    dword_105C1F9C = 0;
    dword_105C1FA0 = (int)"operator strength random scale max";
    dword_105C1FA8 = 3;
    dword_105C1FAC = 44;
    dword_105C1FB0 = 4;
    dword_105C1FB4 = -1;
    dword_105C1FB8 = 0;
    dword_105C1FBC = 0;
    dword_105C1FC0 = 0;
    dword_105C1FC4 = 0;
    dword_105C1FC8 = 0;
    dword_105C1FCC = (int)"operator end cap state";
    dword_105C1FD0 = (int)"-1";
    dword_105C1FD4 = 2;
    dword_105C1FD8 = 64;
    dword_105C1FDC = 4;
    dword_105C1FE0 = -1;
    dword_105C1FE4 = 0;
    dword_105C1FE8 = 0;
    dword_105C1FEC = 0;
    dword_105C1FF0 = 0;
    dword_105C1FF4 = 0;
    dword_105C1FF8 = (int)"time to start transition";
    dword_105C2000 = 3;
    dword_105C2004 = 88;
    dword_105C2008 = 4;
    dword_105C200C = -1;
    dword_105C2010 = 0;
    dword_105C2014 = 0;
    dword_105C2018 = 0;
    dword_105C201C = 0;
    dword_105C2020 = 0;
    dword_105C2024 = (int)"starting force";
    dword_105C2028 = (int)"0 0 0";
    dword_105C2030 = 92;
    dword_105C2034 = 12;
    dword_105C2038 = -1;
    dword_105C203C = 0;
    dword_105C2040 = 0;
    dword_105C2044 = 0;
    dword_105C2048 = 0;
    dword_105C204C = 0;
    dword_105C2050 = (int)"time to end transition";
    dword_105C2054 = (int)"10";
    dword_105C2058 = 3;
    dword_105C205C = 104;
    dword_105C2060 = 4;
    dword_105C2064 = -1;
    dword_105C2068 = 0;
    dword_105C206C = 0;
    dword_105C2070 = 0;
    dword_105C2074 = 0;
    dword_105C2078 = 0;
    dword_105C207C = (int)"ending force";
    dword_105C2080 = (int)"0 0 0";
    dword_105C2088 = 108;
    dword_105C208C = 12;
    dword_105C2090 = -1;
    dword_105C2094 = 0;
    dword_105C2098 = 0;
    dword_105C209C = 0;
    dword_105C20A0 = 0;
    dword_105C20A4 = 0;
    dword_105C20A8 = 0;
    dword_105C20AC = 0;
    dword_105C20B0 = 0;
    dword_105C20B4 = 0;
    dword_105C20B8 = 0;
    dword_105C20BC = -1;
    dword_105C20C0 = 0;
    dword_105C20C4 = 0;
    dword_105C20C8 = 0;
    dword_105C20CC = 0;
    dword_105C20D0 = 0;
  }
  return unpack_13;
}

//------------------------------------------------------------------------------
// Address: 0x102E2D60
// Name: struct DmxElementUnpackStructure_t __near * DmxElementUnpackInit<class C_OP_TurbulenceForce>(class C_OP_TurbulenceForce __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *__cdecl DmxElementUnpackInit<C_OP_TurbulenceForce>()
{
  if ( (_S8_17 & 1) == 0 )
  {
    _S8_17 |= 1u;
    dword_105C20E0 = 3;
    dword_105C20E4 = 4;
    dword_105C20E8 = 4;
    dword_105C20EC = -1;
    dword_105C20F0 = 0;
    dword_105C20F4 = 0;
    dword_105C20F8 = 0;
    dword_105C20FC = 0;
    dword_105C2100 = 0;
    dword_105C2104 = (int)"operator end fadein";
    dword_105C2108 = (int)"0";
    dword_105C210C = 3;
    dword_105C2110 = 8;
    dword_105C2114 = 4;
    dword_105C2118 = -1;
    dword_105C211C = 0;
    dword_105C2120 = 0;
    dword_105C2124 = 0;
    dword_105C2128 = 0;
    dword_105C212C = 0;
    dword_105C2130 = (int)"operator start fadeout";
    dword_105C2134 = (int)"0";
    dword_105C2138 = 3;
    dword_105C213C = 12;
    dword_105C2140 = 4;
    dword_105C2144 = -1;
    dword_105C2148 = 0;
    dword_105C214C = 0;
    dword_105C2150 = 0;
    dword_105C2154 = 0;
    dword_105C2158 = 0;
    dword_105C215C = (int)"operator end fadeout";
    dword_105C2160 = (int)"0";
    dword_105C2164 = 3;
    dword_105C2168 = 16;
    dword_105C216C = 4;
    dword_105C2170 = -1;
    dword_105C2174 = 0;
    dword_105C2178 = 0;
    dword_105C217C = 0;
    dword_105C2180 = 0;
    dword_105C2184 = 0;
    dword_105C2188 = (int)"operator fade oscillate";
    dword_105C218C = (int)"0";
    dword_105C2190 = 3;
    dword_105C2194 = 20;
    dword_105C2198 = 4;
    dword_105C219C = -1;
    dword_105C21A0 = 0;
    dword_105C21A4 = 0;
    dword_105C21A8 = 0;
    dword_105C21AC = 0;
    dword_105C21B0 = 0;
    dword_105C21B4 = (int)"operator time offset seed";
    dword_105C21B8 = (int)"0";
    dword_105C21BC = 2;
    dword_105C21C0 = 32;
    dword_105C21C4 = 4;
    dword_105C21C8 = -1;
    dword_105C21CC = 0;
    dword_105C21D0 = 0;
    dword_105C21D4 = 0;
    dword_105C21D8 = 0;
    dword_105C21DC = 0;
    dword_105C21E0 = (int)"operator time offset min";
    dword_105C21E4 = (int)"0";
    dword_105C21E8 = 3;
    dword_105C21EC = 24;
    dword_105C21F0 = 4;
    dword_105C21F4 = -1;
    dword_105C21F8 = 0;
    dword_105C2240 = 2;
    dword_105C21FC = 0;
    dword_105C2200 = 0;
    dword_105C2204 = 0;
    dword_105C2208 = 0;
    dword_105C220C = (int)"operator time offset max";
    dword_105C2210 = (int)"0";
    dword_105C2214 = 3;
    dword_105C2218 = 28;
    dword_105C221C = 4;
    dword_105C2220 = -1;
    dword_105C2224 = 0;
    dword_105C2228 = 0;
    dword_105C222C = 0;
    dword_105C2230 = 0;
    dword_105C2234 = 0;
    dword_105C2238 = (int)"operator time scale seed";
    dword_105C223C = (int)"0";
    dword_105C2244 = 48;
    dword_105C2248 = 4;
    dword_105C224C = -1;
    dword_105C2250 = 0;
    dword_105C2254 = 0;
    dword_105C2258 = 0;
    dword_105C225C = 0;
    dword_105C2260 = 0;
    dword_105C2264 = (int)"operator time scale min";
    dword_105C2268 = (int)"1";
    dword_105C226C = 3;
    dword_105C2270 = 52;
    dword_105C2274 = 4;
    dword_105C2278 = -1;
    dword_105C227C = 0;
    dword_105C2280 = 0;
    dword_105C2284 = 0;
    dword_105C2288 = 0;
    dword_105C228C = 0;
    dword_105C2290 = (int)"operator time scale max";
    dword_105C2294 = (int)"1";
    dword_105C2298 = 3;
    dword_105C229C = 56;
    dword_105C22A0 = 4;
    dword_105C22A4 = -1;
    dword_105C22A8 = 0;
    dword_105C22AC = 0;
    dword_105C22B0 = 0;
    dword_105C22B4 = 0;
    dword_105C22B8 = 0;
    dword_105C22BC = (int)"operator time strength random scale max";
    dword_105C22C0 = (int)"1";
    dword_105C22C4 = 3;
    dword_105C22C8 = 44;
    dword_105C22CC = 4;
    dword_105C22D0 = -1;
    dword_105C22D4 = 0;
    dword_105C22D8 = 0;
    dword_105C22DC = 0;
    dword_105C22E0 = 0;
    dword_105C22E4 = 0;
    dword_105C22E8 = (int)"operator strength scale seed";
    dword_105C22EC = (int)"0";
    dword_105C22F0 = 2;
    dword_105C22F4 = 36;
    dword_105C22F8 = 4;
    dword_105C22FC = -1;
    dword_105C2300 = 0;
    dword_105C2304 = 0;
    dword_105C2308 = 0;
    dword_105C230C = 0;
    dword_105C2310 = 0;
    dword_105C2314 = (int)"operator strength random scale min";
    dword_105C2318 = (int)"1";
    dword_105C231C = 3;
    dword_105C2320 = 40;
    dword_105C2324 = 4;
    dword_105C2328 = -1;
    dword_105C232C = 0;
    dword_105C2330 = 0;
    dword_105C2334 = 0;
    dword_105C2338 = 0;
    dword_105C2344 = (int)"1";
    dword_105C239C = (int)"1";
    dword_105C233C = 0;
    dword_105C2340 = (int)"operator strength random scale max";
    dword_105C2348 = 3;
    dword_105C234C = 44;
    dword_105C2350 = 4;
    dword_105C2354 = -1;
    dword_105C2358 = 0;
    dword_105C235C = 0;
    dword_105C2360 = 0;
    dword_105C2364 = 0;
    dword_105C2368 = 0;
    dword_105C236C = (int)"operator end cap state";
    dword_105C2370 = (int)"-1";
    dword_105C2374 = 2;
    dword_105C2378 = 64;
    dword_105C237C = 4;
    dword_105C2380 = -1;
    dword_105C2384 = 0;
    dword_105C2388 = 0;
    dword_105C238C = 0;
    dword_105C2390 = 0;
    dword_105C2394 = 0;
    dword_105C2398 = (int)"Noise scale 0";
    dword_105C23A0 = 3;
    dword_105C23A4 = 88;
    dword_105C23A8 = 4;
    dword_105C23AC = -1;
    dword_105C23B0 = 0;
    dword_105C23B4 = 0;
    dword_105C23B8 = 0;
    dword_105C23BC = 0;
    dword_105C23C0 = 0;
    dword_105C23C4 = (int)"Noise amount 0";
    dword_105C23C8 = (int)"1 1 1";
    dword_105C23CC = 10;
    dword_105C23D0 = 104;
    dword_105C23D4 = 12;
    dword_105C23D8 = -1;
    dword_105C23DC = 0;
    dword_105C23E0 = 0;
    dword_105C23E4 = 0;
    dword_105C23E8 = 0;
    dword_105C23EC = 0;
    dword_105C23F0 = (int)"Noise scale 1";
    dword_105C23F4 = (int)"0";
    dword_105C23F8 = 3;
    dword_105C23FC = 92;
    dword_105C2400 = 4;
    dword_105C2404 = -1;
    dword_105C2408 = 0;
    dword_105C240C = 0;
    dword_105C2410 = 0;
    dword_105C2414 = 0;
    dword_105C2418 = 0;
    dword_105C241C = (int)"Noise amount 1";
    dword_105C2420 = (int)".5 .5 .5";
    dword_105C2424 = 10;
    dword_105C2428 = 116;
    dword_105C242C = 12;
    dword_105C2430 = -1;
    dword_105C2434 = 0;
    dword_105C2438 = 0;
    dword_105C243C = 0;
    dword_105C2440 = 0;
    dword_105C2444 = 0;
    dword_105C2448 = (int)"Noise scale 2";
    dword_105C244C = (int)"0";
    dword_105C2450 = 3;
    dword_105C2454 = 96;
    dword_105C2458 = 4;
    dword_105C245C = -1;
    dword_105C2460 = 0;
    dword_105C2464 = 0;
    dword_105C2468 = 0;
    dword_105C246C = 0;
    dword_105C2470 = 0;
    dword_105C2474 = (int)"Noise amount 2";
    dword_105C2478 = (int)".25 .25 .25";
    dword_105C24A4 = (int)"0";
    dword_105C24A8 = 3;
    dword_105C247C = 10;
    dword_105C24D4 = 10;
    dword_105C2480 = 128;
    dword_105C2484 = 12;
    dword_105C2488 = -1;
    dword_105C248C = 0;
    dword_105C2490 = 0;
    dword_105C2494 = 0;
    dword_105C2498 = 0;
    dword_105C249C = 0;
    dword_105C24A0 = (int)"Noise scale 3";
    dword_105C24AC = 100;
    dword_105C24B0 = 4;
    dword_105C24B4 = -1;
    dword_105C24B8 = 0;
    dword_105C24BC = 0;
    dword_105C24C0 = 0;
    dword_105C24C4 = 0;
    dword_105C24C8 = 0;
    dword_105C24CC = (int)"Noise amount 3";
    dword_105C24D0 = (int)".125 .125 .125";
    dword_105C24D8 = 140;
    dword_105C24DC = 12;
    dword_105C24E0 = -1;
    dword_105C24E4 = 0;
    dword_105C24E8 = 0;
    dword_105C24EC = 0;
    dword_105C24F0 = 0;
    dword_105C24F4 = 0;
    dword_105C24F8 = 0;
    dword_105C24FC = 0;
    dword_105C2500 = 0;
    dword_105C2504 = 0;
    dword_105C2508 = 0;
    dword_105C250C = -1;
    dword_105C2510 = 0;
    dword_105C2514 = 0;
    dword_105C2518 = 0;
    dword_105C251C = 0;
    dword_105C2520 = 0;
  }
  return unpack_14;
}

//------------------------------------------------------------------------------
// Address: 0x104198C0
// Name: _dynamic_initializer_for__joyadvancedupdate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__joyadvancedupdate__()
{
  ConCommand::ConCommand(
    this: &joyadvancedupdate,
    pName: "joyadvancedupdate",
    callback: (void (__cdecl *)())IN_Joystick_Advanced_f,
    pHelpString: prType,
    flags: 0x40000000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__joyadvancedupdate__);
}

//------------------------------------------------------------------------------
// Address: 0x104198F0
// Name: _dynamic_initializer_for__startzoom__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startzoom__()
{
  ConCommand::ConCommand(
    this: &startzoom,
    pName: "+zoom",
    callback: (void (__cdecl *)())IN_ZoomDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startzoom__);
}

//------------------------------------------------------------------------------
// Address: 0x10419920
// Name: _dynamic_initializer_for__endzoom__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endzoom__()
{
  ConCommand::ConCommand(
    this: &endzoom,
    pName: "-zoom",
    callback: (void (__cdecl *)())IN_ZoomUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endzoom__);
}

//------------------------------------------------------------------------------
// Address: 0x10419950
// Name: _dynamic_initializer_for__endgrenade1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endgrenade1__()
{
  ConCommand::ConCommand(
    this: &endgrenade1,
    pName: "-grenade1",
    callback: (void (__cdecl *)())IN_Grenade1Up,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endgrenade1__);
}

//------------------------------------------------------------------------------
// Address: 0x10419980
// Name: _dynamic_initializer_for__startgrenade1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startgrenade1__()
{
  ConCommand::ConCommand(
    this: &startgrenade1,
    pName: "+grenade1",
    callback: (void (__cdecl *)())IN_Grenade1Down,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startgrenade1__);
}

//------------------------------------------------------------------------------
// Address: 0x104199B0
// Name: _dynamic_initializer_for__endgrenade2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endgrenade2__()
{
  ConCommand::ConCommand(
    this: &endgrenade2,
    pName: "-grenade2",
    callback: (void (__cdecl *)())IN_Grenade2Up,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endgrenade2__);
}

//------------------------------------------------------------------------------
// Address: 0x104199E0
// Name: _dynamic_initializer_for__startgrenade2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startgrenade2__()
{
  ConCommand::ConCommand(
    this: &startgrenade2,
    pName: "+grenade2",
    callback: (void (__cdecl *)())IN_Grenade2Down,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startgrenade2__);
}

//------------------------------------------------------------------------------
// Address: 0x10419A10
// Name: _dynamic_initializer_for__startlookspin__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__startlookspin__()
{
  ConCommand::ConCommand(
    this: &startlookspin,
    pName: "+lookspin",
    callback: (void (__cdecl *)())IN_LookSpinDown,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__startlookspin__);
}

//------------------------------------------------------------------------------
// Address: 0x10419A40
// Name: _dynamic_initializer_for__endlookspin__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__endlookspin__()
{
  ConCommand::ConCommand(
    this: &endlookspin,
    pName: "-lookspin",
    callback: (void (__cdecl *)())IN_LookSpinUp,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__endlookspin__);
}

//------------------------------------------------------------------------------
// Address: 0x10419A70
// Name: _dynamic_initializer_for__xboxmove__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__xboxmove__()
{
  ConCommand::ConCommand(
    this: &xboxmove,
    pName: "xmove",
    callback: (void (__cdecl *)())C_BaseAnimating::ShutdownBoneSetupThreadPool,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__xboxmove__);
}

//------------------------------------------------------------------------------
// Address: 0x10419AA0
// Name: _dynamic_initializer_for__xboxlook__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__xboxlook__()
{
  ConCommand::ConCommand(
    this: &xboxlook,
    pName: "xlook",
    callback: (void (__cdecl *)())C_BaseAnimating::ShutdownBoneSetupThreadPool,
    pHelpString: nullptr,
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__xboxlook__);
}

//------------------------------------------------------------------------------
// Address: 0x104329E0
// Name: _dynamic_atexit_destructor_for__joyadvancedupdate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__joyadvancedupdate__()
{
  ConCommand::~ConCommand(this: &joyadvancedupdate);
}

//------------------------------------------------------------------------------
// Address: 0x104329F0
// Name: _dynamic_atexit_destructor_for__startzoom__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startzoom__()
{
  ConCommand::~ConCommand(this: &startzoom);
}

//------------------------------------------------------------------------------
// Address: 0x10432A00
// Name: _dynamic_atexit_destructor_for__endzoom__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endzoom__()
{
  ConCommand::~ConCommand(this: &endzoom);
}

//------------------------------------------------------------------------------
// Address: 0x10432A10
// Name: _dynamic_atexit_destructor_for__endgrenade1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endgrenade1__()
{
  ConCommand::~ConCommand(this: &endgrenade1);
}

//------------------------------------------------------------------------------
// Address: 0x10432A20
// Name: _dynamic_atexit_destructor_for__startgrenade1__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startgrenade1__()
{
  ConCommand::~ConCommand(this: &startgrenade1);
}

//------------------------------------------------------------------------------
// Address: 0x10432A30
// Name: _dynamic_atexit_destructor_for__endgrenade2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endgrenade2__()
{
  ConCommand::~ConCommand(this: &endgrenade2);
}

//------------------------------------------------------------------------------
// Address: 0x10432A40
// Name: _dynamic_atexit_destructor_for__startgrenade2__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startgrenade2__()
{
  ConCommand::~ConCommand(this: &startgrenade2);
}

//------------------------------------------------------------------------------
// Address: 0x10432A50
// Name: _dynamic_atexit_destructor_for__startlookspin__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__startlookspin__()
{
  ConCommand::~ConCommand(this: &startlookspin);
}

//------------------------------------------------------------------------------
// Address: 0x10432A60
// Name: _dynamic_atexit_destructor_for__endlookspin__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__endlookspin__()
{
  ConCommand::~ConCommand(this: &endlookspin);
}

//------------------------------------------------------------------------------
// Address: 0x10432A70
// Name: _dynamic_atexit_destructor_for__xboxmove__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__xboxmove__()
{
  ConCommand::~ConCommand(this: &xboxmove);
}

//------------------------------------------------------------------------------
// Address: 0x10432A80
// Name: _dynamic_atexit_destructor_for__xboxlook__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__xboxlook__()
{
  ConCommand::~ConCommand(this: &xboxlook);
}

} // namespace client
