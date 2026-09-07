// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vbsp/overlay.cpp
// Functions: 9
// ============================================================

#include "utils\vbsp\overlay.h"

//------------------------------------------------------------------------------
// Address: 0x00420ED0
// Name: public: bool VMatrix::IsIdentity(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall VMatrix::IsIdentity(VMatrix *this)
{
  return this->m[0][0] == 1.0
      && this->m[0][1] == 0.0
      && this->m[0][2] == 0.0
      && this->m[0][3] == 0.0
      && this->m[1][0] == 0.0
      && this->m[1][1] == 1.0
      && this->m[1][2] == 0.0
      && this->m[1][3] == 0.0
      && this->m[2][0] == 0.0
      && this->m[2][1] == 0.0
      && this->m[2][2] == 1.0
      && this->m[2][3] == 0.0
      && this->m[3][0] == 0.0
      && this->m[3][1] == 0.0
      && this->m[3][2] == 0.0
      && this->m[3][3] == 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x00420FE0
// Name: void Overlay_Translate(struct mapoverlay_t __near *,class Vector __near &,class QAngle __near &,struct matrix3x4_t __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall Overlay_Translate(
        int a1@<ebp>,
        mapoverlay_t *pOverlay,
        Vector *OriginOffset,
        QAngle *AngleOffset,
        matrix3x4_t *Matrix)
{
  float z; // edx
  Vector *vecBasis; // edi
  float v7; // ecx
  float v8; // edx
  float v9; // xmm5_4
  float v10; // xmm1_4
  float v11; // xmm2_4
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // eax
  __int128 v15; // xmm7
  float v16; // xmm5_4
  __int128 v17; // xmm7
  bool v18; // cl
  float v19; // xmm6_4
  float v20; // xmm6_4
  float v21; // xmm6_4
  bool v22; // al
  float v23; // xmm0_4
  float x; // xmm5_4
  float v25; // xmm6_4
  float v26; // xmm4_4
  float v27; // ecx
  float v28; // xmm3_4
  float v29; // xmm3_4
  float v30; // xmm6_4
  float v31; // xmm2_4
  float v32; // xmm4_4
  float v33; // xmm5_4
  float v34; // xmm5_4
  float v35; // xmm6_4
  float v36; // xmm4_4
  float v37; // eax
  float v38; // xmm4_4
  float v39; // xmm3_4
  float v40; // xmm4_4
  float v41; // xmm5_4
  float v42; // xmm5_4
  float v43; // xmm6_4
  float v44; // xmm4_4
  float v45; // edx
  float v46; // xmm7_4
  float v47; // xmm3_4
  float v48; // xmm4_4
  float v49; // xmm5_4
  float v50; // xmm4_4
  float v51; // xmm5_4
  float v52; // xmm6_4
  float v53; // ecx
  float v54; // xmm0_4
  float v55; // xmm1_4
  float v56; // xmm3_4
  float v57; // xmm1_4
  float v58; // xmm4_4
  float v59; // [esp-1Ch] [ebp-BCh]
  __int64 v60; // [esp-Ch] [ebp-ACh] BYREF
  _BYTE v61[68]; // [esp-4h] [ebp-A4h] OVERLAPPED BYREF
  float y; // [esp+40h] [ebp-60h]
  __int128 v63; // [esp+44h] [ebp-5Ch] BYREF
  Vector vecPos; // [esp+54h] [ebp-4Ch]
  float v65; // [esp+60h] [ebp-40h]
  float v66; // [esp+64h] [ebp-3Ch]
  Vector vecV; // [esp+68h] [ebp-38h]
  __int128 vecNormal; // [esp+74h] [ebp-2Ch] OVERLAPPED
  Vector vecUV; // [esp+84h] [ebp-1Ch]
  float v70; // [esp+90h] [ebp-10h]
  int v71; // [esp+94h] [ebp-Ch]
  void *v72; // [esp+98h] [ebp-8h]
  void *retaddr; // [esp+A0h] [ebp+0h]

  v71 = a1;
  v72 = retaddr;
  v60 = *(_QWORD *)&Matrix->m_flMatVal[0][0];
  *(_QWORD *)v61 = *(_QWORD *)&Matrix->m_flMatVal[0][2];
  *(_QWORD *)&v61[8] = *(_QWORD *)&Matrix->m_flMatVal[1][0];
  z = pOverlay->vecOrigin.z;
  *(_QWORD *)&v61[16] = *(_QWORD *)&Matrix->m_flMatVal[1][2];
  *(_QWORD *)&v61[24] = *(_QWORD *)&Matrix->m_flMatVal[2][0];
  *(_QWORD *)&v61[32] = *(_QWORD *)&Matrix->m_flMatVal[2][2];
  memset(&v61[40], 0, 12);
  *(_DWORD *)&v61[52] = 1065353216;
  *(_QWORD *)((char *)&v63 + 4) = *(_QWORD *)&pOverlay->vecOrigin.x;
  *((float *)&v63 + 3) = z;
  VectorTransform(in1: (const float *)&v63 + 1, in2: Matrix, out: &pOverlay->vecOrigin.x);
  *(float *)&v61[4] = vec3_origin.x;
  *(float *)&v61[20] = vec3_origin.y;
  *(float *)&v61[36] = vec3_origin.z;
  if ( !VMatrix::IsIdentity(this: (VMatrix *)&v60) )
  {
    vecBasis = pOverlay->vecBasis;
    VectorNormalize(vec: pOverlay->vecBasis);
    VectorNormalize(vec: &pOverlay->vecBasis[1]);
    v7 = pOverlay->vecBasis[0].z;
    *(_QWORD *)((char *)&vecNormal + 4) = *(_QWORD *)&pOverlay->vecBasis[0].x;
    v8 = pOverlay->vecBasis[1].z;
    *((float *)&vecNormal + 3) = v7;
    v9 = 1.0
       / (float)((float)((float)((float)(*((float *)&vecNormal + 2) + *((float *)&vecNormal + 1)) + v7) * 0.0) + 1.0);
    v10 = *(float *)&v61[24];
    v11 = (float)((float)((float)((float)(*((float *)&v60 + 1) * *((float *)&vecNormal + 2))
                                + (float)(*(float *)&v60 * *((float *)&vecNormal + 1)))
                        + (float)(*(float *)v61 * v7))
                + *(float *)&v61[4])
        * v9;
    v12 = (float)((float)((float)((float)(*(float *)&v61[12] * *((float *)&vecNormal + 2))
                                + (float)(*(float *)&v61[8] * *((float *)&vecNormal + 1)))
                        + (float)(*(float *)&v61[16] * v7))
                + *(float *)&v61[20])
        * v9;
    v13 = (float)((float)((float)((float)(*(float *)&v61[28] * *((float *)&vecNormal + 2))
                                + (float)(*(float *)&v61[24] * *((float *)&vecNormal + 1)))
                        + (float)(*(float *)&v61[32] * v7))
                + *(float *)&v61[36])
        * v9;
    *(_QWORD *)((char *)&vecNormal + 4) = *(_QWORD *)&pOverlay->vecBasis[1].x;
    *((float *)&vecNormal + 3) = v8;
    vecUV.z = 1.0
            / (float)((float)((float)((float)(*((float *)&vecNormal + 2) + *((float *)&vecNormal + 1)) + v8) * 0.0) + 1.0);
    vecPos.z = (float)((float)((float)((float)(*((float *)&vecNormal + 2) * *((float *)&v60 + 1))
                                     + (float)(*((float *)&vecNormal + 1) * *(float *)&v60))
                             + (float)(v8 * *(float *)v61))
                     + *(float *)&v61[4])
             * vecUV.z;
    v70 = (float)(*((float *)&vecNormal + 2) * *(float *)&v61[12])
        + (float)(*(float *)&v61[8] * *((float *)&vecNormal + 1));
    v65 = (float)((float)(v70 + (float)(v8 * *(float *)&v61[16])) + *(float *)&v61[20]) * vecUV.z;
    v14 = pOverlay->vecBasis[2].z;
    v70 = (float)(*(float *)&v61[24] * *((float *)&vecNormal + 1))
        + (float)(*((float *)&vecNormal + 2) * *(float *)&v61[28]);
    v66 = (float)((float)(v70 + (float)(v8 * *(float *)&v61[32])) + *(float *)&v61[36]) * vecUV.z;
    *(_QWORD *)((char *)&vecNormal + 4) = *(_QWORD *)&pOverlay->vecBasis[2].x;
    vecUV.z = 1.0
            / (float)((float)((float)((float)(*((float *)&vecNormal + 2) + *((float *)&vecNormal + 1)) + v14) * 0.0)
                    + 1.0);
    v70 = (float)(*((float *)&vecNormal + 2) * *((float *)&v60 + 1))
        + (float)(*((float *)&vecNormal + 1) * *(float *)&v60);
    vecV.x = (float)((float)(v70 + (float)(v14 * *(float *)v61)) + *(float *)&v61[4]) * vecUV.z;
    v70 = (float)(*((float *)&vecNormal + 2) * *(float *)&v61[12])
        + (float)(*(float *)&v61[8] * *((float *)&vecNormal + 1));
    vecV.y = (float)((float)(v70 + (float)(v14 * *(float *)&v61[16])) + *(float *)&v61[20]) * vecUV.z;
    v70 = (float)(*(float *)&v61[24] * *((float *)&vecNormal + 1))
        + (float)(*((float *)&vecNormal + 2) * *(float *)&v61[28]);
    vecV.z = (float)((float)(v70 + (float)(v14 * *(float *)&v61[32])) + *(float *)&v61[36]) * vecUV.z;
    v15 = 0;
    v59 = fsqrt((float)((float)(vecPos.z * vecPos.z) + (float)(v65 * v65)) + (float)(v66 * v66));
    v70 = vecV.x * vecV.x;
    *(float *)&v15 = fsqrt((float)((float)(v11 * v11) + (float)(v12 * v12)) + (float)(v13 * v13));
    vecNormal = v15;
    v16 = vecV.z;
    v17 = 0;
    *(float *)&v17 = fsqrt((float)((float)(vecV.x * vecV.x) + (float)(vecV.y * vecV.y)) + (float)(v16 * v16));
    v63 = v17;
    v18 = *(float *)&vecNormal < 1.0001
       && *(float *)&vecNormal > 0.99989998
       && v59 < 1.0001
       && v59 > 0.99989998
       && *(float *)&v63 < 1.0001
       && *(float *)&v63 > 0.99989998;
    v19 = (float)((float)(v65 * v12) + (float)(vecPos.z * v11)) + (float)(v66 * v13);
    v22 = false;
    if ( v19 < 0.0024999999 && v19 > -0.0024999999 )
    {
      v20 = (float)((float)(vecV.y * v12) + (float)(vecV.x * v11)) + (float)(vecV.z * v13);
      if ( v20 < 0.0024999999 && v20 > -0.0024999999 )
      {
        v70 = (float)(vecV.x * vecPos.z) + (float)(vecV.y * v65);
        v21 = v70 + (float)(vecV.z * v66);
        if ( v21 < 0.0024999999 && v21 > -0.0024999999 )
          v22 = true;
      }
    }
    if ( v18 && v22 )
    {
      v23 = vecPos.z;
      vecBasis->x = v11;
      pOverlay->vecBasis[0].y = v12;
      pOverlay->vecBasis[0].z = v13;
      pOverlay->vecBasis[1].x = v23;
      pOverlay->vecBasis[1].y = v65;
      pOverlay->vecBasis[1].z = v66;
      pOverlay->vecBasis[2].x = vecV.x;
      pOverlay->vecBasis[2].y = vecV.y;
      pOverlay->vecBasis[2].z = v16;
    }
    else
    {
      x = pOverlay->vecBasis[1].x;
      *(_QWORD *)((char *)&vecNormal + 4) = *(_QWORD *)&pOverlay->vecUVPoints[0].x;
      v25 = vecBasis->x;
      v26 = pOverlay->vecBasis[0].z;
      vecPos.z = x * *((float *)&vecNormal + 2);
      *(float *)&v61[60] = pOverlay->vecBasis[1].y;
      v65 = *(float *)&v61[60] * *((float *)&vecNormal + 2);
      vecUV.z = pOverlay->vecBasis[1].z;
      v66 = vecUV.z * *((float *)&vecNormal + 2);
      y = pOverlay->vecBasis[0].y;
      *(float *)&v61[64] = v26;
      *((float *)&v63 + 2) = (float)(y * *((float *)&vecNormal + 1))
                           + (float)(*(float *)&v61[60] * *((float *)&vecNormal + 2));
      v27 = pOverlay->vecUVPoints[0].z;
      *((float *)&v63 + 1) = (float)(v25 * *((float *)&vecNormal + 1)) + (float)(x * *((float *)&vecNormal + 2));
      *((float *)&v63 + 3) = (float)(v26 * *((float *)&vecNormal + 1)) + (float)(vecUV.z * *((float *)&vecNormal + 2));
      v70 = (float)((float)((float)(*((float *)&v63 + 2) + *((float *)&v63 + 1)) + *((float *)&v63 + 3)) * 0.0) + 1.0;
      vecV = *(Vector *)((char *)&v63 + 4);
      v28 = (float)((float)((float)(*((float *)&v63 + 2) * *(float *)&v61[12])
                          + (float)(*(float *)&v61[8] * *((float *)&v63 + 1)))
                  + (float)(*((float *)&v63 + 3) * *(float *)&v61[16]))
          + *(float *)&v61[20];
      *((float *)&v63 + 1) = (float)((float)((float)((float)(*((float *)&v63 + 2) * *((float *)&v60 + 1))
                                                   + (float)(*((float *)&v63 + 1) * *(float *)&v60))
                                           + (float)(*((float *)&v63 + 3) * *(float *)v61))
                                   + *(float *)&v61[4])
                           * (float)(1.0 / v70);
      v29 = v28 * (float)(1.0 / v70);
      v30 = (float)(v25 * *((float *)&v63 + 1)) + (float)(y * v29);
      v31 = v26;
      v32 = (float)((float)((float)((float)(*(float *)&v61[24] * vecV.x) + (float)(vecV.y * *(float *)&v61[28]))
                          + (float)(*((float *)&v63 + 3) * *(float *)&v61[32]))
                  + *(float *)&v61[36])
          * (float)(1.0 / v70);
      *((float *)&vecNormal + 3) = v27;
      v70 = 1.0 / v70;
      v33 = (float)((float)(x * *((float *)&v63 + 1)) + (float)(*(float *)&v61[60] * v29)) + (float)(vecUV.z * v32);
      pOverlay->vecUVPoints[0].z = v27;
      pOverlay->vecUVPoints[0].x = v30 + (float)(v31 * v32);
      pOverlay->vecUVPoints[0].y = v33;
      v34 = pOverlay->vecBasis[1].x;
      v35 = vecBasis->x;
      v36 = pOverlay->vecBasis[0].z;
      *(_QWORD *)((char *)&vecNormal + 4) = *(_QWORD *)&pOverlay->vecUVPoints[1].x;
      vecPos.z = v34 * *((float *)&vecNormal + 2);
      *(float *)&v61[60] = pOverlay->vecBasis[1].y;
      v65 = *(float *)&v61[60] * *((float *)&vecNormal + 2);
      vecUV.z = pOverlay->vecBasis[1].z;
      v66 = vecUV.z * *((float *)&vecNormal + 2);
      v37 = pOverlay->vecUVPoints[1].z;
      y = pOverlay->vecBasis[0].y;
      *(float *)&v61[64] = v36;
      *((float *)&v63 + 2) = (float)(y * *((float *)&vecNormal + 1))
                           + (float)(*(float *)&v61[60] * *((float *)&vecNormal + 2));
      *((float *)&v63 + 1) = (float)(v35 * *((float *)&vecNormal + 1)) + (float)(v34 * *((float *)&vecNormal + 2));
      *((float *)&v63 + 3) = (float)(v36 * *((float *)&vecNormal + 1)) + (float)(vecUV.z * *((float *)&vecNormal + 2));
      v38 = 1.0
          / (float)((float)((float)((float)(*((float *)&v63 + 2) + *((float *)&v63 + 1)) + *((float *)&v63 + 3)) * 0.0)
                  + 1.0);
      vecV = *(Vector *)((char *)&v63 + 4);
      v70 = v38;
      v39 = (float)((float)((float)((float)(*((float *)&v63 + 2) * *(float *)&v61[12])
                                  + (float)(*(float *)&v61[8] * *((float *)&v63 + 1)))
                          + (float)(*((float *)&v63 + 3) * *(float *)&v61[16]))
                  + *(float *)&v61[20])
          * v38;
      *((float *)&v63 + 1) = (float)((float)((float)((float)(*((float *)&v63 + 2) * *((float *)&v60 + 1))
                                                   + (float)(*((float *)&v63 + 1) * *(float *)&v60))
                                           + (float)(*((float *)&v63 + 3) * *(float *)v61))
                                   + *(float *)&v61[4])
                           * v38;
      *((float *)&vecNormal + 3) = v37;
      v40 = (float)((float)((float)((float)(v10 * vecV.x) + (float)(vecV.y * *(float *)&v61[28]))
                          + (float)(*((float *)&v63 + 3) * *(float *)&v61[32]))
                  + *(float *)&v61[36])
          * v38;
      v41 = (float)((float)(v34 * *((float *)&v63 + 1)) + (float)(*(float *)&v61[60] * v39)) + (float)(vecUV.z * v40);
      pOverlay->vecUVPoints[1].x = (float)((float)(v35 * *((float *)&v63 + 1)) + (float)(y * v39))
                                 + (float)(*(float *)&v61[64] * v40);
      pOverlay->vecUVPoints[1].y = v41;
      pOverlay->vecUVPoints[1].z = v37;
      v42 = pOverlay->vecBasis[1].x;
      v43 = vecBasis->x;
      v44 = pOverlay->vecBasis[0].z;
      *(_QWORD *)((char *)&vecNormal + 4) = *(_QWORD *)&pOverlay->vecUVPoints[2].x;
      v45 = pOverlay->vecUVPoints[2].z;
      vecPos.z = v42 * *((float *)&vecNormal + 2);
      *(float *)&v61[60] = pOverlay->vecBasis[1].y;
      v65 = *(float *)&v61[60] * *((float *)&vecNormal + 2);
      vecUV.z = pOverlay->vecBasis[1].z;
      v66 = vecUV.z * *((float *)&vecNormal + 2);
      y = pOverlay->vecBasis[0].y;
      *((float *)&v63 + 2) = (float)(y * *((float *)&vecNormal + 1))
                           + (float)(*(float *)&v61[60] * *((float *)&vecNormal + 2));
      *(float *)&v61[64] = v44;
      *((float *)&v63 + 1) = (float)(v43 * *((float *)&vecNormal + 1)) + (float)(v42 * *((float *)&vecNormal + 2));
      *((float *)&v63 + 3) = (float)(v44 * *((float *)&vecNormal + 1)) + (float)(vecUV.z * *((float *)&vecNormal + 2));
      v46 = *(float *)&v61[8] * *((float *)&v63 + 1);
      *((float *)&vecNormal + 3) = v45;
      vecV = *(Vector *)((char *)&v63 + 4);
      v70 = 1.0
          / (float)((float)((float)((float)(*((float *)&v63 + 2) + *((float *)&v63 + 1)) + *((float *)&v63 + 3)) * 0.0)
                  + 1.0);
      *((float *)&v63 + 1) = (float)((float)((float)((float)(*((float *)&v63 + 2) * *((float *)&v60 + 1))
                                                   + (float)(*((float *)&v63 + 1) * *(float *)&v60))
                                           + (float)(*((float *)&v63 + 3) * *(float *)v61))
                                   + *(float *)&v61[4])
                           * v70;
      v47 = (float)((float)((float)((float)(*((float *)&v63 + 2) * *(float *)&v61[12]) + v46)
                          + (float)(*((float *)&v63 + 3) * *(float *)&v61[16]))
                  + *(float *)&v61[20])
          * v70;
      v48 = (float)((float)((float)((float)(v10 * vecV.x) + (float)(vecV.y * *(float *)&v61[28]))
                          + (float)(*((float *)&v63 + 3) * *(float *)&v61[32]))
                  + *(float *)&v61[36])
          * v70;
      v49 = (float)((float)(v42 * *((float *)&v63 + 1)) + (float)(*(float *)&v61[60] * v47)) + (float)(vecUV.z * v48);
      pOverlay->vecUVPoints[2].x = (float)((float)(v43 * *((float *)&v63 + 1)) + (float)(y * v47))
                                 + (float)(*(float *)&v61[64] * v48);
      pOverlay->vecUVPoints[2].y = v49;
      pOverlay->vecUVPoints[2].z = v45;
      v50 = pOverlay->vecBasis[1].x;
      v51 = vecBasis->x;
      v52 = pOverlay->vecBasis[0].z;
      *(_QWORD *)((char *)&vecNormal + 4) = *(_QWORD *)&pOverlay->vecUVPoints[3].x;
      v53 = pOverlay->vecUVPoints[3].z;
      vecPos.z = v50 * *((float *)&vecNormal + 2);
      *(float *)&v61[60] = pOverlay->vecBasis[1].y;
      v65 = *(float *)&v61[60] * *((float *)&vecNormal + 2);
      vecUV.z = pOverlay->vecBasis[1].z;
      v66 = vecUV.z * *((float *)&vecNormal + 2);
      y = pOverlay->vecBasis[0].y;
      *((float *)&v63 + 2) = (float)(y * *((float *)&vecNormal + 1))
                           + (float)(*(float *)&v61[60] * *((float *)&vecNormal + 2));
      *((float *)&v63 + 1) = (float)(v51 * *((float *)&vecNormal + 1)) + (float)(v50 * *((float *)&vecNormal + 2));
      vecV.x = *((float *)&v63 + 1);
      *((float *)&v63 + 3) = (float)(v52 * *((float *)&vecNormal + 1)) + (float)(vecUV.z * *((float *)&vecNormal + 2));
      v54 = 1.0
          / (float)((float)((float)((float)(*((float *)&v63 + 2) + *((float *)&v63 + 1)) + *((float *)&v63 + 3)) * 0.0)
                  + 1.0);
      v55 = v10 * *((float *)&v63 + 1);
      *((float *)&v63 + 1) = (float)((float)((float)((float)(*((float *)&v63 + 2) * *((float *)&v60 + 1))
                                                   + (float)(*((float *)&v63 + 1) * *(float *)&v60))
                                           + (float)(*((float *)&v63 + 3) * *(float *)v61))
                                   + *(float *)&v61[4])
                           * v54;
      v56 = (float)((float)((float)((float)(*((float *)&v63 + 2) * *(float *)&v61[12])
                                  + (float)(*(float *)&v61[8] * vecV.x))
                          + (float)(*((float *)&v63 + 3) * *(float *)&v61[16]))
                  + *(float *)&v61[20])
          * v54;
      v57 = (float)((float)((float)(v55 + (float)(*((float *)&v63 + 2) * *(float *)&v61[28]))
                          + (float)(*((float *)&v63 + 3) * *(float *)&v61[32]))
                  + *(float *)&v61[36])
          * v54;
      v58 = (float)((float)(v50 * *((float *)&v63 + 1)) + (float)(*(float *)&v61[60] * v56)) + (float)(vecUV.z * v57);
      pOverlay->vecUVPoints[3].x = (float)((float)(v51 * *((float *)&v63 + 1)) + (float)(y * v56)) + (float)(v52 * v57);
      pOverlay->vecUVPoints[3].y = v58;
      pOverlay->vecUVPoints[3].z = v53;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421D90
// Name: void Overlay_EmitOverlayFaces(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Overlay_EmitOverlayFaces()
{
  int v0; // esi
  char *v1; // esi
  doverlayfade_t *v2; // ecx
  doverlaysystemlevel_t *v3; // eax
  bool v4; // zf
  doverlay_t *v5; // edi
  float *v6; // ecx
  int i; // ebx
  float *v8; // eax
  int j; // edx
  int v10; // ecx
  int k; // eax
  texinfo_s searchTexInfo; // [esp+24h] [ebp-5Ch] BYREF
  const char *v13; // [esp+6Ch] [ebp-14h]
  int m_Size; // [esp+70h] [ebp-10h]
  int v15; // [esp+74h] [ebp-Ch]
  doverlaysystemlevel_t *v16; // [esp+78h] [ebp-8h]
  doverlayfade_t *v17; // [esp+7Ch] [ebp-4h]

  if ( g_aMapOverlays.m_Size > 0 )
  {
    v0 = 0;
    v15 = 0;
    m_Size = g_aMapOverlays.m_Size;
    do
    {
      v1 = (char *)g_aMapOverlays.m_Memory.m_pMemory + v0;
      if ( g_nOverlayCount < 512 )
      {
        v2 = &g_OverlayFades[g_nOverlayCount];
        v3 = &g_OverlaySystemLevels[g_nOverlayCount];
        v4 = &g_Overlays[g_nOverlayCount] == nullptr;
        v5 = &g_Overlays[g_nOverlayCount];
        v17 = v2;
        v16 = v3;
        ++g_nOverlayCount;
        if ( v4 )
          goto LABEL_17;
        v5->nId = *(_DWORD *)v1;
        v5->flU[0] = *((float *)v1 + 66);
        v5->flU[1] = *((float *)v1 + 67);
        v5->flV[0] = *((float *)v1 + 68);
        v5->flV[1] = *((float *)v1 + 69);
        v5->vecUVPoints[0].x = *((float *)v1 + 73);
        v5->vecUVPoints[0].y = *((float *)v1 + 74);
        v5->vecUVPoints[0].z = *((float *)v1 + 75);
        v5->vecUVPoints[1].x = *((float *)v1 + 76);
        v5->vecUVPoints[1].y = *((float *)v1 + 77);
        v5->vecUVPoints[1].z = *((float *)v1 + 78);
        v5->vecUVPoints[2].x = *((float *)v1 + 79);
        v5->vecUVPoints[2].y = *((float *)v1 + 80);
        v5->vecUVPoints[2].z = *((float *)v1 + 81);
        v5->vecUVPoints[3].x = *((float *)v1 + 82);
        v5->vecUVPoints[3].y = *((float *)v1 + 83);
        v5->vecUVPoints[3].z = *((float *)v1 + 84);
        v5->vecOrigin.x = *((float *)v1 + 85);
        v5->vecOrigin.y = *((float *)v1 + 86);
        v5->vecOrigin.z = *((float *)v1 + 87);
        v5->vecBasisNormal.x = *((float *)v1 + 94);
        v5->vecBasisNormal.y = *((float *)v1 + 95);
        v5->vecBasisNormal.z = *((float *)v1 + 96);
        v5->m_nFaceCountAndRenderOrder = (*((_WORD *)v1 + 2) << 14) | v5->m_nFaceCountAndRenderOrder & 0x3FFF;
        v5->vecUVPoints[0].z = *((float *)v1 + 88);
        v5->vecUVPoints[1].z = *((float *)v1 + 89);
        v5->vecUVPoints[2].z = *((float *)v1 + 90);
        if ( (float)((float)((float)(*((float *)v1 + 92)
                                   * (float)((float)(*((float *)v1 + 88) * *((float *)v1 + 96))
                                           - (float)(*((float *)v1 + 90) * *((float *)v1 + 94))))
                           + (float)(*((float *)v1 + 91)
                                   * (float)((float)(*((float *)v1 + 95) * *((float *)v1 + 90))
                                           - (float)(*((float *)v1 + 96) * *((float *)v1 + 89)))))
                   + (float)(*((float *)v1 + 93)
                           * (float)((float)(*((float *)v1 + 89) * *((float *)v1 + 94))
                                   - (float)(*((float *)v1 + 88) * *((float *)v1 + 95))))) < 0.0 )
          v5->vecUVPoints[3].z = 1.0;
        searchTexInfo.flags = 0;
        v13 = v1 + 6;
        searchTexInfo.texdata = FindOrCreateTexData(pName_: v1 + 6);
        v6 = &searchTexInfo.lightmapVecsLuxelsPerWorldUnits[0][3];
        for ( i = 2; i != 0; --i )
        {
          v8 = v6 - 11;
          for ( j = 3; j != 0; --j )
          {
            v8[8] = 0.0;
            *v8++ = 0.0;
          }
          *v6 = -99999.0;
          *(v6 - 8) = -99999.0;
          v6 += 4;
        }
        v5->nTexInfo = FindOrCreateTexInfo(&searchTexInfo);
        v10 = *((_DWORD *)v1 + 105);
        if ( v10 < 64 )
        {
          v5->m_nFaceCountAndRenderOrder ^= (v10 ^ v5->m_nFaceCountAndRenderOrder) & 0x3FFF;
          for ( k = 0; k < v10; ++k )
            v5->aFaces[k] = *(_DWORD *)(*((_DWORD *)v1 + 102) + 4 * k);
          v3 = v16;
          v2 = v17;
LABEL_17:
          if ( v2 != nullptr )
          {
            v2->flFadeDistMinSq = *((float *)v1 + 70);
            v2->flFadeDistMaxSq = *((float *)v1 + 71);
          }
          if ( v3 != nullptr )
          {
            v3->nMinCPULevel = v1[288];
            v3->nMaxCPULevel = v1[289];
            v3->nMinGPULevel = v1[290];
            v3->nMaxGPULevel = v1[291];
          }
          goto LABEL_21;
        }
        _Error(
          a1: "Overlay touching too many faces (touching %d, max %d)\nOverlay %s at %.1f %.1f %.1f",
          v10,
          64,
          v13,
          *((float *)v1 + 85),
          *((float *)v1 + 86),
          *((float *)v1 + 87));
      }
      else
      {
        _Error(a1: "Too Many Overlays!\nMAX_MAP_OVERLAYS = %d", 512);
      }
LABEL_21:
      v0 = v15 + 428;
      v4 = m_Size-- == 1;
      v15 += 428;
    }
    while ( !v4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422150
// Name: void OverlayTransition_EmitOverlayFaces(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OverlayTransition_EmitOverlayFaces()
{
  int v0; // esi
  char *v1; // esi
  bool v2; // zf
  dwateroverlay_t *v3; // edi
  float *v4; // ecx
  int i; // ebx
  float *v6; // eax
  int j; // edx
  int v8; // ecx
  int k; // eax
  texinfo_s searchTexInfo; // [esp+24h] [ebp-54h] BYREF
  const char *v11; // [esp+6Ch] [ebp-Ch]
  int m_Size; // [esp+70h] [ebp-8h]
  int v13; // [esp+74h] [ebp-4h]

  if ( g_aMapWaterOverlays.m_Size > 0 )
  {
    v0 = 0;
    v13 = 0;
    m_Size = g_aMapWaterOverlays.m_Size;
    do
    {
      v1 = (char *)g_aMapWaterOverlays.m_Memory.m_pMemory + v0;
      if ( g_nWaterOverlayCount < 0x4000 )
      {
        v2 = &g_WaterOverlays[g_nWaterOverlayCount] == nullptr;
        v3 = &g_WaterOverlays[g_nWaterOverlayCount++];
        if ( !v2 )
        {
          v3->nId = *(_DWORD *)v1;
          v3->flU[0] = *((float *)v1 + 66);
          v3->flU[1] = *((float *)v1 + 67);
          v3->flV[0] = *((float *)v1 + 68);
          v3->flV[1] = *((float *)v1 + 69);
          v3->vecUVPoints[0].x = *((float *)v1 + 73);
          v3->vecUVPoints[0].y = *((float *)v1 + 74);
          v3->vecUVPoints[0].z = *((float *)v1 + 75);
          v3->vecUVPoints[1].x = *((float *)v1 + 76);
          v3->vecUVPoints[1].y = *((float *)v1 + 77);
          v3->vecUVPoints[1].z = *((float *)v1 + 78);
          v3->vecUVPoints[2].x = *((float *)v1 + 79);
          v3->vecUVPoints[2].y = *((float *)v1 + 80);
          v3->vecUVPoints[2].z = *((float *)v1 + 81);
          v3->vecUVPoints[3].x = *((float *)v1 + 82);
          v3->vecUVPoints[3].y = *((float *)v1 + 83);
          v3->vecUVPoints[3].z = *((float *)v1 + 84);
          v3->vecOrigin.x = *((float *)v1 + 85);
          v3->vecOrigin.y = *((float *)v1 + 86);
          v3->vecOrigin.z = *((float *)v1 + 87);
          v3->vecBasisNormal.x = *((float *)v1 + 94);
          v3->vecBasisNormal.y = *((float *)v1 + 95);
          v3->vecBasisNormal.z = *((float *)v1 + 96);
          v3->m_nFaceCountAndRenderOrder = (*((_WORD *)v1 + 2) << 14) | v3->m_nFaceCountAndRenderOrder & 0x3FFF;
          v3->vecUVPoints[0].z = *((float *)v1 + 88);
          v3->vecUVPoints[1].z = *((float *)v1 + 89);
          v3->vecUVPoints[2].z = *((float *)v1 + 90);
          if ( (float)((float)((float)(*((float *)v1 + 92)
                                     * (float)((float)(*((float *)v1 + 88) * *((float *)v1 + 96))
                                             - (float)(*((float *)v1 + 90) * *((float *)v1 + 94))))
                             + (float)(*((float *)v1 + 91)
                                     * (float)((float)(*((float *)v1 + 95) * *((float *)v1 + 90))
                                             - (float)(*((float *)v1 + 96) * *((float *)v1 + 89)))))
                     + (float)(*((float *)v1 + 93)
                             * (float)((float)(*((float *)v1 + 89) * *((float *)v1 + 94))
                                     - (float)(*((float *)v1 + 88) * *((float *)v1 + 95))))) < 0.0 )
            v3->vecUVPoints[3].z = 1.0;
          searchTexInfo.flags = 0;
          v11 = v1 + 6;
          searchTexInfo.texdata = FindOrCreateTexData(pName_: v1 + 6);
          v4 = &searchTexInfo.lightmapVecsLuxelsPerWorldUnits[0][3];
          for ( i = 2; i != 0; --i )
          {
            v6 = v4 - 11;
            for ( j = 3; j != 0; --j )
            {
              v6[8] = 0.0;
              *v6++ = 0.0;
            }
            *v4 = -99999.0;
            *(v4 - 8) = -99999.0;
            v4 += 4;
          }
          v3->nTexInfo = FindOrCreateTexInfo(&searchTexInfo);
          v8 = *((_DWORD *)v1 + 105);
          if ( v8 < 256 )
          {
            v3->m_nFaceCountAndRenderOrder ^= (v8 ^ v3->m_nFaceCountAndRenderOrder) & 0x3FFF;
            for ( k = 0; k < v8; ++k )
              v3->aFaces[k] = *(_DWORD *)(*((_DWORD *)v1 + 102) + 4 * k);
          }
          else
          {
            _Error(
              a1: "Water Overlay touching too many faces (touching %d, max %d)\nOverlay %s at %.1f %.1f %.1f",
              v8,
              64,
              v11,
              *((float *)v1 + 85),
              *((float *)v1 + 86),
              *((float *)v1 + 87));
          }
        }
      }
      else
      {
        _Error(a1: "Too many water overlays!\nMAX_MAP_WATEROVERLAYS = %d", 0x4000);
      }
      v0 = v13 + 428;
      v2 = m_Size-- == 1;
      v13 += 428;
    }
    while ( !v2 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004224B0
// Name: void Overlay_UpdateSideLists(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Overlay_UpdateSideLists(int StartIndex)
{
  int v1; // edx
  CMapFile *v2; // ebx
  mapoverlay_t *v3; // edi
  int v4; // ecx
  int nummapbrushsides; // edx
  int v6; // eax
  int v7; // esi
  int *p_id; // ecx
  int v9; // eax
  int v10; // edx
  CUtlMemory<S3RGBA,int> *v11; // esi
  int v12; // eax
  int nId; // edi
  S3RGBA *m_pMemory; // ecx
  int m_nAllocationCount; // eax
  int v16; // edi
  S3RGBA *v17; // ecx
  int v18; // eax
  int *v19; // eax
  bool v20; // zf
  int nSideCount; // [esp+0h] [ebp-10h]
  int v22; // [esp+4h] [ebp-Ch]
  int v23; // [esp+8h] [ebp-8h]
  int iSide; // [esp+Ch] [ebp-4h]
  mapoverlay_t *pMapOverlay; // [esp+18h] [ebp+8h]

  if ( StartIndex < g_aMapOverlays.m_Size )
  {
    v1 = 428 * StartIndex;
    v2 = g_LoadingMap;
    v23 = 428 * StartIndex;
    v22 = g_aMapOverlays.m_Size - StartIndex;
    do
    {
      v3 = (mapoverlay_t *)((char *)g_aMapOverlays.m_Memory.m_pMemory + v1);
      pMapOverlay = (mapoverlay_t *)((char *)g_aMapOverlays.m_Memory.m_pMemory + v1);
      if ( (mapoverlay_t *)((char *)g_aMapOverlays.m_Memory.m_pMemory + v1) != nullptr )
      {
        v4 = 0;
        nSideCount = v3->aSideList.m_Size;
        iSide = 0;
        if ( nSideCount > 0 )
        {
          while ( 1 )
          {
            nummapbrushsides = v2->nummapbrushsides;
            v6 = 0;
            if ( nummapbrushsides > 0 )
            {
              v7 = v3->aSideList.m_Memory.m_pMemory[v4];
              p_id = &v2->brushsides[0].id;
              while ( *p_id != v7 )
              {
                ++v6;
                p_id += 23;
                if ( v6 >= nummapbrushsides )
                  goto LABEL_26;
              }
              v9 = (int)&v2->brushsides[v6];
              if ( v9 != 0 )
              {
                v10 = *(_DWORD *)(v9 + 60);
                v11 = (CUtlMemory<S3RGBA,int> *)(v9 + 48);
                v12 = 0;
                if ( v10 <= 0 )
                  goto LABEL_19;
                nId = v3->nId;
                m_pMemory = v11->m_pMemory;
                while ( *m_pMemory != nId )
                {
                  ++v12;
                  ++m_pMemory;
                  if ( v12 >= v10 )
                    goto LABEL_19;
                }
                if ( v12 == -1 )
                {
LABEL_19:
                  m_nAllocationCount = v11->m_nAllocationCount;
                  v16 = v10;
                  if ( v10 + 1 > m_nAllocationCount )
                    CUtlMemory<CClassInput *,int>::Grow(this: v11, num: v10 - m_nAllocationCount + 1);
                  ++v11[1].m_pMemory;
                  v17 = v11->m_pMemory;
                  v18 = (int)v11[1].m_pMemory - v16 - 1;
                  v11[1].m_nAllocationCount = (int)v11->m_pMemory;
                  if ( v18 > 0 )
                    _V_memmove(dest: &v17[v16 + 1], src: &v17[v16], count: 4 * v18);
                  v19 = (int *)&v11->m_pMemory[v16];
                  if ( v19 != nullptr )
                    *v19 = pMapOverlay->nId;
                  v2 = g_LoadingMap;
                }
              }
            }
LABEL_26:
            v4 = iSide + 1;
            iSide = v4;
            if ( v4 >= nSideCount )
              break;
            v3 = pMapOverlay;
          }
          v1 = v23;
        }
      }
      v1 += 428;
      v20 = v22-- == 1;
      v23 = v1;
    }
    while ( !v20 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422600
// Name: void OverlayTransition_UpdateSideLists(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OverlayTransition_UpdateSideLists(int StartIndex)
{
  int v1; // edx
  CMapFile *v2; // ebx
  mapoverlay_t *v3; // edi
  int v4; // ecx
  int nummapbrushsides; // edx
  int v6; // eax
  int v7; // esi
  int *p_id; // ecx
  int v9; // eax
  int v10; // edx
  CUtlMemory<S3RGBA,int> *v11; // esi
  int v12; // eax
  int nId; // edi
  S3RGBA *m_pMemory; // ecx
  int m_nAllocationCount; // eax
  int v16; // edi
  S3RGBA *v17; // ecx
  int v18; // eax
  int *v19; // eax
  bool v20; // zf
  int nSideCount; // [esp+0h] [ebp-10h]
  int v22; // [esp+4h] [ebp-Ch]
  int v23; // [esp+8h] [ebp-8h]
  int iSide; // [esp+Ch] [ebp-4h]
  mapoverlay_t *pOverlay; // [esp+18h] [ebp+8h]

  if ( StartIndex < g_aMapWaterOverlays.m_Size )
  {
    v1 = 428 * StartIndex;
    v2 = g_LoadingMap;
    v23 = 428 * StartIndex;
    v22 = g_aMapWaterOverlays.m_Size - StartIndex;
    do
    {
      v3 = (mapoverlay_t *)((char *)g_aMapWaterOverlays.m_Memory.m_pMemory + v1);
      pOverlay = (mapoverlay_t *)((char *)g_aMapWaterOverlays.m_Memory.m_pMemory + v1);
      if ( (mapoverlay_t *)((char *)g_aMapWaterOverlays.m_Memory.m_pMemory + v1) != nullptr )
      {
        v4 = 0;
        nSideCount = v3->aSideList.m_Size;
        iSide = 0;
        if ( nSideCount > 0 )
        {
          while ( 1 )
          {
            nummapbrushsides = v2->nummapbrushsides;
            v6 = 0;
            if ( nummapbrushsides > 0 )
            {
              v7 = v3->aSideList.m_Memory.m_pMemory[v4];
              p_id = &v2->brushsides[0].id;
              while ( *p_id != v7 )
              {
                ++v6;
                p_id += 23;
                if ( v6 >= nummapbrushsides )
                  goto LABEL_26;
              }
              v9 = (int)&v2->brushsides[v6];
              if ( v9 != 0 )
              {
                v10 = *(_DWORD *)(v9 + 80);
                v11 = (CUtlMemory<S3RGBA,int> *)(v9 + 68);
                v12 = 0;
                if ( v10 <= 0 )
                  goto LABEL_19;
                nId = v3->nId;
                m_pMemory = v11->m_pMemory;
                while ( *m_pMemory != nId )
                {
                  ++v12;
                  ++m_pMemory;
                  if ( v12 >= v10 )
                    goto LABEL_19;
                }
                if ( v12 == -1 )
                {
LABEL_19:
                  m_nAllocationCount = v11->m_nAllocationCount;
                  v16 = v10;
                  if ( v10 + 1 > m_nAllocationCount )
                    CUtlMemory<CClassInput *,int>::Grow(this: v11, num: v10 - m_nAllocationCount + 1);
                  ++v11[1].m_pMemory;
                  v17 = v11->m_pMemory;
                  v18 = (int)v11[1].m_pMemory - v16 - 1;
                  v11[1].m_nAllocationCount = (int)v11->m_pMemory;
                  if ( v18 > 0 )
                    _V_memmove(dest: &v17[v16 + 1], src: &v17[v16], count: 4 * v18);
                  v19 = (int *)&v11->m_pMemory[v16];
                  if ( v19 != nullptr )
                    *v19 = pOverlay->nId;
                  v2 = g_LoadingMap;
                }
              }
            }
LABEL_26:
            v4 = iSide + 1;
            iSide = v4;
            if ( v4 >= nSideCount )
              break;
            v3 = pOverlay;
          }
          v1 = v23;
        }
      }
      v1 += 428;
      v20 = v22-- == 1;
      v23 = v1;
    }
    while ( !v20 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422750
// Name: void Overlay_AddFaceToLists(int,struct side_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Overlay_AddFaceToLists(int iFace, side_t *pSide)
{
  int v2; // eax
  mapoverlay_t *v3; // eax
  int m_Size; // ecx
  CUtlMemory<S3RGBA,int> *p_aFaceList; // esi
  int v6; // eax
  S3RGBA *m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v9; // edi
  S3RGBA *v10; // ecx
  int v11; // eax
  S3RGBA *v12; // eax
  int nOverlayIdCount; // [esp+0h] [ebp-8h]
  int iOverlayId; // [esp+4h] [ebp-4h]

  v2 = 0;
  nOverlayIdCount = pSide->aOverlayIds.m_Size;
  iOverlayId = 0;
  if ( nOverlayIdCount > 0 )
  {
    do
    {
      v3 = &g_aMapOverlays.m_Memory.m_pMemory[pSide->aOverlayIds.m_Memory.m_pMemory[v2]];
      if ( v3 != nullptr )
      {
        m_Size = v3->aFaceList.m_Size;
        p_aFaceList = (CUtlMemory<S3RGBA,int> *)&v3->aFaceList;
        v6 = 0;
        if ( m_Size <= 0 )
          goto LABEL_9;
        m_pMemory = p_aFaceList->m_pMemory;
        while ( *m_pMemory != iFace )
        {
          ++v6;
          ++m_pMemory;
          if ( v6 >= m_Size )
            goto LABEL_9;
        }
        if ( v6 == -1 )
        {
LABEL_9:
          m_nAllocationCount = p_aFaceList->m_nAllocationCount;
          v9 = m_Size;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<CClassInput *,int>::Grow(this: p_aFaceList, num: m_Size - m_nAllocationCount + 1);
          ++p_aFaceList[1].m_pMemory;
          v10 = p_aFaceList->m_pMemory;
          v11 = (int)p_aFaceList[1].m_pMemory - v9 - 1;
          p_aFaceList[1].m_nAllocationCount = (int)p_aFaceList->m_pMemory;
          if ( v11 > 0 )
            _V_memmove(dest: &v10[v9 + 1], src: &v10[v9], count: 4 * v11);
          v12 = &p_aFaceList->m_pMemory[v9];
          if ( v12 != nullptr )
            *v12 = (S3RGBA)iFace;
        }
      }
      v2 = iOverlayId + 1;
      iOverlayId = v2;
    }
    while ( v2 < nOverlayIdCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422820
// Name: void OverlayTransition_AddFaceToLists(int,struct side_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OverlayTransition_AddFaceToLists(int iFace, side_t *pSide)
{
  int v2; // ebx
  mapoverlay_t *v3; // eax
  int m_Size; // ecx
  CUtlMemory<S3RGBA,int> *p_aFaceList; // esi
  int v6; // eax
  S3RGBA *m_pMemory; // edx
  int m_nAllocationCount; // eax
  int v9; // edi
  S3RGBA *v10; // ecx
  int v11; // eax
  S3RGBA *v12; // eax
  int nOverlayIdCount; // [esp+4h] [ebp-4h]

  v2 = 0;
  nOverlayIdCount = pSide->aWaterOverlayIds.m_Size;
  if ( nOverlayIdCount > 0 )
  {
    do
    {
      v3 = &g_aMapWaterOverlays.m_Memory.m_pMemory[pSide->aWaterOverlayIds.m_Memory.m_pMemory[v2] - 513];
      if ( v3 != nullptr )
      {
        m_Size = v3->aFaceList.m_Size;
        p_aFaceList = (CUtlMemory<S3RGBA,int> *)&v3->aFaceList;
        v6 = 0;
        if ( m_Size <= 0 )
          goto LABEL_9;
        m_pMemory = p_aFaceList->m_pMemory;
        while ( *m_pMemory != iFace )
        {
          ++v6;
          ++m_pMemory;
          if ( v6 >= m_Size )
            goto LABEL_9;
        }
        if ( v6 == -1 )
        {
LABEL_9:
          m_nAllocationCount = p_aFaceList->m_nAllocationCount;
          v9 = m_Size;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<CClassInput *,int>::Grow(this: p_aFaceList, num: m_Size - m_nAllocationCount + 1);
          ++p_aFaceList[1].m_pMemory;
          v10 = p_aFaceList->m_pMemory;
          v11 = (int)p_aFaceList[1].m_pMemory - v9 - 1;
          p_aFaceList[1].m_nAllocationCount = (int)p_aFaceList->m_pMemory;
          if ( v11 > 0 )
            _V_memmove(dest: &v10[v9 + 1], src: &v10[v9], count: 4 * v11);
          v12 = &p_aFaceList->m_pMemory[v9];
          if ( v12 != nullptr )
            *v12 = (S3RGBA)iFace;
        }
      }
      ++v2;
    }
    while ( v2 < nOverlayIdCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422A20
// Name: int Overlay_GetFromEntity(struct entity_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Overlay_GetFromEntity(entity_t *pMapEnt)
{
  mapoverlay_t *v1; // edi
  double v2; // st7
  double v3; // st7
  unsigned __int16 v4; // ax
  const char *v5; // eax
  char *v6; // eax
  int v8; // edx
  char v9; // cl
  const char *v10; // esi
  void *v11; // esp
  const char *v12; // ebx
  CUtlMemory<S3RGBA,int> *p_aSideList; // esi
  S3RGBA *m_pMemory; // edi
  int m_nAllocationCount; // eax
  S3RGBA *v16; // ecx
  int v17; // eax
  float *v18; // edi
  double v19; // [esp-Ch] [ebp-20h]
  double v20[2]; // [esp-4h] [ebp-18h] BYREF
  int nSideId; // [esp+Ch] [ebp-8h] BYREF
  int iAccessorID; // [esp+10h] [ebp-4h]

  iAccessorID = -1;
  v1 = &g_aMapOverlays.m_Memory.m_pMemory[CUtlVector<mapoverlay_t,CUtlMemory<mapoverlay_t,int>>::InsertBefore(
                                            this: &g_aMapOverlays,
                                            elem: g_aMapOverlays.m_Size)];
  v1->nId = g_aMapOverlays.m_Size - 1;
  if ( *ValueForKey(ent: pMapEnt, key: "targetname") != 0 )
    iAccessorID = v1->nId;
  v1->flU[0] = FloatForKey(ent: pMapEnt, key: "StartU");
  v1->flU[1] = FloatForKey(ent: pMapEnt, key: "EndU");
  v1->flV[0] = FloatForKey(ent: pMapEnt, key: "StartV");
  v1->flV[1] = FloatForKey(ent: pMapEnt, key: "EndV");
  v2 = FloatForKey(ent: pMapEnt, key: "fademindist");
  *(float *)&nSideId = v2;
  v1->flFadeDistMinSq = v2;
  if ( v2 > 0.0 )
    v1->flFadeDistMinSq = *(float *)&nSideId * *(float *)&nSideId;
  v3 = FloatForKey(ent: pMapEnt, key: "fademaxdist");
  *(float *)&nSideId = v3;
  v1->flFadeDistMaxSq = v3;
  if ( v3 > 0.0 )
    v1->flFadeDistMaxSq = *(float *)&nSideId * *(float *)&nSideId;
  v1->nMinCPULevel = IntForKey(ent: pMapEnt, key: "mincpulevel");
  v1->nMaxCPULevel = IntForKey(ent: pMapEnt, key: "maxcpulevel");
  v1->nMinGPULevel = IntForKey(ent: pMapEnt, key: "mingpulevel");
  v1->nMaxGPULevel = IntForKey(ent: pMapEnt, key: "maxgpulevel");
  GetVectorForKey(ent: pMapEnt, key: "BasisOrigin", angle: (QAngle *)&v1->vecOrigin);
  v4 = IntForKey(ent: pMapEnt, key: "RenderOrder");
  v1->m_nRenderOrder = v4;
  if ( v4 >= 4u )
  {
    v19 = *(double *)&v1->vecOrigin.x;
    *(float *)v20 = v1->vecOrigin.z;
    v5 = ValueForKey(ent: pMapEnt, key: "material");
    _Error(a1: "Overlay (%s) at %f %f %f has invalid render order (%d).\n", v5, v19, v20[0], v20[1], nSideId);
  }
  GetVectorForKey(ent: pMapEnt, key: "uv0", angle: (QAngle *)v1->vecUVPoints);
  GetVectorForKey(ent: pMapEnt, key: "uv1", angle: (QAngle *)&v1->vecUVPoints[1]);
  GetVectorForKey(ent: pMapEnt, key: "uv2", angle: (QAngle *)&v1->vecUVPoints[2]);
  GetVectorForKey(ent: pMapEnt, key: "uv3", angle: (QAngle *)&v1->vecUVPoints[3]);
  GetVectorForKey(ent: pMapEnt, key: "BasisU", angle: (QAngle *)v1->vecBasis);
  GetVectorForKey(ent: pMapEnt, key: "BasisV", angle: (QAngle *)&v1->vecBasis[1]);
  GetVectorForKey(ent: pMapEnt, key: "BasisNormal", angle: (QAngle *)&v1->vecBasis[2]);
  v6 = ValueForKey(ent: pMapEnt, key: "material");
  if ( strlen(v6) < 0x100 )
  {
    v8 = (char *)v1 - v6;
    do
    {
      v9 = *v6;
      v6[v8 + 6] = *v6;
      ++v6;
    }
    while ( v9 != 0 );
    v10 = ValueForKey(ent: pMapEnt, key: "sides");
    v11 = alloca(strlen(v10) + 1);
    strcpy((char *)v20 + 4, v10);
    v12 = strtok(string: (char *)v20 + 4, control: " ");
    if ( v12 != nullptr )
    {
      p_aSideList = (CUtlMemory<S3RGBA,int> *)&v1->aSideList;
      CUtlVector<int,CUtlMemory<int,int>>::Purge(this: &v1->aSideList);
      CUtlVector<int,CUtlMemory<int,int>>::Purge(this: &v1->aFaceList);
      do
      {
        if ( sscanf(string: v12, format: "%d", &nSideId) == 1 )
        {
          m_pMemory = p_aSideList[1].m_pMemory;
          m_nAllocationCount = p_aSideList->m_nAllocationCount;
          if ( (int)&m_pMemory->g > m_nAllocationCount )
            CUtlMemory<CClassInput *,int>::Grow(this: p_aSideList, num: (int)(&m_pMemory->g - m_nAllocationCount));
          ++p_aSideList[1].m_pMemory;
          v16 = p_aSideList->m_pMemory;
          v17 = (char *)p_aSideList[1].m_pMemory - (char *)m_pMemory - 1;
          p_aSideList[1].m_nAllocationCount = (int)p_aSideList->m_pMemory;
          if ( v17 > 0 )
            _V_memmove(dest: &v16[(_DWORD)m_pMemory + 1], src: &v16[(_DWORD)m_pMemory], count: 4 * v17);
          v18 = (float *)&p_aSideList->m_pMemory[(_DWORD)m_pMemory];
          if ( v18 != nullptr )
            *v18 = *(float *)&nSideId;
        }
        v12 = strtok(string: nullptr, control: " ");
      }
      while ( v12 != nullptr );
    }
    return iAccessorID;
  }
  else
  {
    _Error(a1: "Overlay Material Name (%s) too long! > OVERLAY_MAP_STRLEN (%d)", v6, 256);
    return -1;
  }
}
