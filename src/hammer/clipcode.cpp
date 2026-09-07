// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/clipcode.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1000D4F0
// Name: int CreateClippedPoly(class CMapFace __near *,class IEditorTexture __near *,class Vector __near &,float (__near *)[5],int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __cdecl CreateClippedPoly(
        CMapFace *pFace,
        IEditorTexture *pDecalTex,
        Vector *org,
        float (*pOutPoints)[5],
        int nOutSize)
{
  int v6; // eax
  int (__thiscall *GetHeight)(IEditorTexture *); // edx
  int v8; // eax
  float x; // xmm1_4
  float z; // xmm2_4
  float y; // xmm0_4
  float v13; // xmm5_4
  float v14; // xmm6_4
  float v15; // xmm3_4
  float v16; // xmm5_4
  float v17; // xmm7_4
  Vector *Points; // eax
  float v19; // xmm2_4
  float v20; // xmm6_4
  int v21; // edx
  float *v22; // ecx
  double v23; // st7
  float v24; // xmm4_4
  float v25; // xmm6_4
  float v26; // xmm3_4
  float v27; // xmm1_4
  float v28; // xmm6_4
  int nPoints; // edi
  int v30; // esi
  _BYTE *v31; // eax
  float *v32; // edx
  float *v33; // ecx
  float v34; // xmm0_4
  float v35; // xmm1_4
  int v36; // edx
  float v37; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm2_4
  int v40; // edx
  float v41; // xmm2_4
  __int64 v42; // xmm0_8
  float v43; // xmm2_4
  float v44; // xmm1_4
  float v45; // xmm0_4
  float v46; // xmm2_4
  int v47; // edi
  int v48; // ebx
  float *v49; // eax
  float *v50; // edx
  float *v51; // ecx
  float v52; // xmm1_4
  float v53; // xmm2_4
  int v54; // edx
  float v55; // xmm2_4
  float v56; // xmm1_4
  float v57; // xmm0_4
  float v58; // xmm2_4
  int v59; // edx
  float v60; // xmm2_4
  __int64 v61; // xmm0_8
  float v62; // xmm0_4
  float v63; // xmm1_4
  float v64; // xmm2_4
  int v65; // esi
  _BYTE *v66; // eax
  float *v67; // edx
  float *v68; // ecx
  float v69; // xmm0_4
  float v70; // xmm1_4
  float v71; // edx
  float v72; // xmm0_4
  float v73; // xmm1_4
  float v74; // xmm2_4
  float v75; // edx
  float v76; // xmm2_4
  __int64 v77; // xmm0_8
  float v78; // xmm2_4
  float v79; // xmm1_4
  float v80; // xmm0_4
  float v81; // xmm2_4
  int v82; // edi
  int v83; // ebx
  float *v84; // eax
  float *v85; // edx
  float *v86; // ecx
  float v87; // xmm1_4
  float v88; // xmm2_4
  float v89; // edx
  float v90; // xmm2_4
  float v91; // xmm1_4
  float v92; // xmm0_4
  float v93; // xmm2_4
  float v94; // edx
  float v95; // xmm2_4
  __int64 v96; // xmm0_8
  float v97; // xmm0_4
  float v98; // xmm1_4
  float v99; // xmm2_4
  _DWORD v101[2]; // [esp-8h] [ebp-540h] BYREF
  _BYTE v102[8]; // [esp+Ch] [ebp-52Ch] BYREF
  float outvert[64][5]; // [esp+14h] [ebp-524h] BYREF
  float decalWidth; // [esp+514h] [ebp-24h] BYREF
  float decalHeight; // [esp+518h] [ebp-20h]
  _BYTE textureSpaceBasis[28]; // [esp+51Ch] [ebp-1Ch] OVERLAPPED BYREF
  float v107; // [esp+540h] [ebp+8h]
  int v108; // [esp+540h] [ebp+8h]
  int v109; // [esp+540h] [ebp+8h]
  float v110; // [esp+544h] [ebp+Ch]
  float v111; // [esp+544h] [ebp+Ch]
  int v112; // [esp+544h] [ebp+Ch]
  float v; // [esp+548h] [ebp+10h]

  v110 = pDecalTex->GetDecalScale(this: pDecalTex);
  v6 = pDecalTex->GetWidth(this: pDecalTex);
  GetHeight = pDecalTex->GetHeight;
  outvert[63][3] = (float)v6;
  v8 = GetHeight(this: pDecalTex);
  x = pFace->plane.normal.x;
  z = pFace->plane.normal.z;
  outvert[63][4] = (float)v8;
  y = pFace->plane.normal.y;
  *(float *)&textureSpaceBasis[16] = x;
  *(float *)&textureSpaceBasis[20] = y;
  *(float *)&textureSpaceBasis[24] = z;
  if ( COERCE_FLOAT(LODWORD(z) & _mask__AbsFloat_) <= 0.70710677 )
  {
    v15 = (float)(z * 0.0) - (float)(x * -1.0);
    v16 = (float)(x * 0.0) - (float)(y * 0.0);
    *(float *)&textureSpaceBasis[4] = (float)(z * v15) - (float)(y * v16);
    decalWidth = (float)(y * -1.0) - (float)(z * 0.0);
    decalHeight = v15;
    *(float *)textureSpaceBasis = v16;
    *(float *)&textureSpaceBasis[8] = (float)(x * v16) - (float)(z * decalWidth);
    *(float *)&textureSpaceBasis[12] = (float)(y * decalWidth) - (float)(x * v15);
  }
  else
  {
    v13 = (float)(x * 0.0) - z;
    v14 = y - (float)(x * 0.0);
    decalWidth = (float)(y * v14) - (float)(z * v13);
    *(float *)&textureSpaceBasis[4] = (float)(z * 0.0) - (float)(y * 0.0);
    *(float *)&textureSpaceBasis[8] = v13;
    *(float *)&textureSpaceBasis[12] = v14;
    decalHeight = (float)(z * *(float *)&textureSpaceBasis[4]) - (float)(x * v14);
    *(float *)textureSpaceBasis = (float)(x * v13) - (float)(y * *(float *)&textureSpaceBasis[4]);
  }
  VectorNormalize(vec: (Vector *)&decalWidth);
  VectorNormalize(vec: (Vector *)&textureSpaceBasis[4]);
  v17 = *(float *)&textureSpaceBasis[4];
  Points = pFace->Points;
  v19 = (float)((float)((float)(org->x * decalWidth) + (float)(org->y * decalHeight))
              + (float)(org->z * *(float *)textureSpaceBasis))
      - (float)((float)(outvert[63][3] * v110) * 0.5);
  v20 = outvert[63][4] * v110;
  v107 = (float)((float)((float)(org->y * *(float *)&textureSpaceBasis[8])
                       + (float)(org->x * *(float *)&textureSpaceBasis[4]))
               + (float)(*(float *)&textureSpaceBasis[12] * org->z))
       - (float)((float)(outvert[63][4] * v110) * 0.5);
  v111 = 1.0 / (float)(outvert[63][3] * v110);
  v21 = 0;
  v = 1.0 / v20;
  if ( pFace->nPoints > 0 )
  {
    v22 = &g_vert[0][1];
    do
    {
      ++v21;
      *(v22 - 1) = Points->x;
      v22 += 5;
      v23 = Points->y;
      ++Points;
      *(v22 - 5) = v23;
      *(v22 - 4) = Points[-1].z;
      v24 = Points[-1].z;
      v25 = Points[-1].x;
      v26 = v25 * decalWidth;
      v27 = (float)(Points[-1].y * *(float *)&textureSpaceBasis[8]) + (float)(v25 * v17);
      v28 = *(float *)&textureSpaceBasis[12] * v24;
      *(v22 - 3) = (float)((float)((float)((float)(Points[-1].y * decalHeight) + v26)
                                 + (float)(v24 * *(float *)textureSpaceBasis))
                         - v19)
                 * v111;
      *(v22 - 2) = (float)((float)(v27 + v28) - v107) * v;
    }
    while ( v21 < pFace->nPoints );
  }
  v112 = nOutSize;
  if ( nOutSize >= 64 )
    v112 = 64;
  nPoints = pFace->nPoints;
  v30 = 0;
  v31 = v102;
  v32 = &vec4_origin_7.w + 5 * nPoints;
  v108 = 0;
  if ( nPoints > 0 )
  {
    v33 = &g_vert[0][3];
    do
    {
      v34 = *v33;
      v35 = v32[3];
      if ( *v33 <= 0.0 )
      {
        if ( v35 > 0.0 )
        {
          v43 = v34 - v35;
          v44 = *(v33 - 1);
          v45 = v34 / v43;
          *((float *)v31 + 4) = (float)((float)(v32[4] - v33[1]) * v45) + v33[1];
          *(float *)v31 = (float)((float)(*v32 - *(v33 - 3)) * v45) + *(v33 - 3);
          *((float *)v31 + 1) = (float)((float)(v32[1] - *(v33 - 2)) * v45) + *(v33 - 2);
          v46 = (float)((float)(v32[2] - v44) * v45) + v44;
          *((_DWORD *)v31 + 3) = 0;
          *((float *)v31 + 2) = v46;
          v31 += 20;
          ++v30;
        }
      }
      else if ( v35 <= 0.0 )
      {
        v37 = v35 / (float)(v35 - v34);
        v38 = v32[2];
        *((float *)v31 + 4) = (float)((float)(v33[1] - v32[4]) * v37) + v32[4];
        *(float *)v31 = (float)((float)(*(v33 - 3) - *v32) * v37) + *v32;
        v39 = (float)((float)(*(v33 - 2) - v32[1]) * v37) + v32[1];
        v40 = *((_DWORD *)v33 + 1);
        *((float *)v31 + 1) = v39;
        v41 = (float)(*(v33 - 1) - v38) * v37;
        v42 = *(_QWORD *)(v33 - 3);
        *((_DWORD *)v31 + 3) = 0;
        *((float *)v31 + 2) = v41 + v38;
        *(_QWORD *)(v31 + 20) = v42;
        *(_QWORD *)(v31 + 28) = *(_QWORD *)(v33 - 1);
        *((_DWORD *)v31 + 9) = v40;
        v30 += 2;
        v31 += 40;
      }
      else
      {
        v36 = *((_DWORD *)v33 + 1);
        *(_QWORD *)v31 = *(_QWORD *)(v33 - 3);
        *((_QWORD *)v31 + 1) = *(_QWORD *)(v33 - 1);
        *((_DWORD *)v31 + 4) = v36;
        ++v30;
        v31 += 20;
      }
      if ( v30 >= v112 )
        break;
      ++v108;
      v32 = v33 - 3;
      v33 += 5;
    }
    while ( v108 < nPoints );
  }
  v47 = 0;
  v48 = 0;
  v49 = g_vert[0];
  v50 = (float *)&v101[5 * v30];
  if ( v30 > 0 )
  {
    v51 = &outvert[0][1];
    do
    {
      v52 = *v51;
      v53 = v50[3];
      if ( *v51 >= 1.0 )
      {
        if ( v53 < 1.0 )
        {
          v62 = (float)(v52 - 1.0) / (float)(v52 - v53);
          v63 = *(v51 - 1);
          v49[4] = (float)((float)(v50[4] - v51[1]) * v62) + v51[1];
          *v49 = (float)((float)(*v50 - *(v51 - 3)) * v62) + *(v51 - 3);
          v49[1] = (float)((float)(v50[1] - *(v51 - 2)) * v62) + *(v51 - 2);
          v64 = (float)((float)(v50[2] - v63) * v62) + v63;
          v49[3] = 1.0;
          v49[2] = v64;
          v49 += 5;
          ++v47;
        }
      }
      else if ( v53 >= 1.0 )
      {
        v55 = v53 - v52;
        v56 = v50[2];
        v57 = (float)(v50[3] - 1.0) / v55;
        v49[4] = (float)((float)(v51[1] - v50[4]) * v57) + v50[4];
        *v49 = (float)((float)(*(v51 - 3) - *v50) * v57) + *v50;
        v58 = (float)((float)(*(v51 - 2) - v50[1]) * v57) + v50[1];
        v59 = *((_DWORD *)v51 + 1);
        v49[1] = v58;
        v60 = (float)(*(v51 - 1) - v56) * v57;
        v61 = *(_QWORD *)(v51 - 3);
        v49[3] = 1.0;
        v49[2] = v60 + v56;
        *(_QWORD *)(v49 + 5) = v61;
        *(_QWORD *)(v49 + 7) = *(_QWORD *)(v51 - 1);
        *((_DWORD *)v49 + 9) = v59;
        v47 += 2;
        v49 += 10;
      }
      else
      {
        v54 = *((_DWORD *)v51 + 1);
        *(_QWORD *)v49 = *(_QWORD *)(v51 - 3);
        *((_QWORD *)v49 + 1) = *(_QWORD *)(v51 - 1);
        *((_DWORD *)v49 + 4) = v54;
        ++v47;
        v49 += 5;
      }
      if ( v47 >= v112 )
        break;
      v50 = v51 - 3;
      ++v48;
      v51 += 5;
    }
    while ( v48 < v30 );
  }
  v65 = 0;
  v66 = v102;
  v67 = &vec4_origin_7.w + 5 * v47;
  v109 = 0;
  if ( v47 > 0 )
  {
    v68 = &g_vert[0][4];
    do
    {
      v69 = *v68;
      v70 = v67[4];
      if ( *v68 <= 0.0 )
      {
        if ( v70 > 0.0 )
        {
          v78 = v69 - v70;
          v79 = *(v68 - 2);
          v80 = v69 / v78;
          *((float *)v66 + 3) = (float)((float)(v67[3] - *(v68 - 1)) * v80) + *(v68 - 1);
          *(float *)v66 = (float)((float)(*v67 - *(v68 - 4)) * v80) + *(v68 - 4);
          *((float *)v66 + 1) = (float)((float)(v67[1] - *(v68 - 3)) * v80) + *(v68 - 3);
          v81 = (float)((float)(v67[2] - v79) * v80) + v79;
          *((_DWORD *)v66 + 4) = 0;
          *((float *)v66 + 2) = v81;
          v66 += 20;
          ++v65;
        }
      }
      else if ( v70 <= 0.0 )
      {
        v72 = v70 / (float)(v70 - v69);
        v73 = v67[2];
        *((float *)v66 + 3) = (float)((float)(*(v68 - 1) - v67[3]) * v72) + v67[3];
        *(float *)v66 = (float)((float)(*(v68 - 4) - *v67) * v72) + *v67;
        v74 = (float)((float)(*(v68 - 3) - v67[1]) * v72) + v67[1];
        v75 = *v68;
        *((float *)v66 + 1) = v74;
        v76 = (float)(*(v68 - 2) - v73) * v72;
        v77 = *((_QWORD *)v68 - 2);
        *((_DWORD *)v66 + 4) = 0;
        *((float *)v66 + 2) = v76 + v73;
        *(_QWORD *)(v66 + 20) = v77;
        *(_QWORD *)(v66 + 28) = *((_QWORD *)v68 - 1);
        *((float *)v66 + 9) = v75;
        v65 += 2;
        v66 += 40;
      }
      else
      {
        v71 = *v68;
        *(_QWORD *)v66 = *((_QWORD *)v68 - 2);
        *((_QWORD *)v66 + 1) = *((_QWORD *)v68 - 1);
        *((float *)v66 + 4) = v71;
        ++v65;
        v66 += 20;
      }
      if ( v65 >= v112 )
        break;
      ++v109;
      v67 = v68 - 4;
      v68 += 5;
    }
    while ( v109 < v47 );
  }
  v82 = 0;
  v83 = 0;
  v84 = g_vert[0];
  v85 = (float *)&v101[5 * v65];
  if ( v65 > 0 )
  {
    v86 = &outvert[0][2];
    do
    {
      v87 = *v86;
      v88 = v85[4];
      if ( *v86 >= 1.0 )
      {
        if ( v88 < 1.0 )
        {
          v97 = (float)(v87 - 1.0) / (float)(v87 - v88);
          v98 = *(v86 - 2);
          v84[3] = (float)((float)(v85[3] - *(v86 - 1)) * v97) + *(v86 - 1);
          *v84 = (float)((float)(*v85 - *(v86 - 4)) * v97) + *(v86 - 4);
          v84[1] = (float)((float)(v85[1] - *(v86 - 3)) * v97) + *(v86 - 3);
          v99 = (float)((float)(v85[2] - v98) * v97) + v98;
          v84[4] = 1.0;
          v84[2] = v99;
          v84 += 5;
          ++v82;
        }
      }
      else if ( v88 >= 1.0 )
      {
        v90 = v88 - v87;
        v91 = v85[2];
        v92 = (float)(v85[4] - 1.0) / v90;
        v84[3] = (float)((float)(*(v86 - 1) - v85[3]) * v92) + v85[3];
        *v84 = (float)((float)(*(v86 - 4) - *v85) * v92) + *v85;
        v93 = (float)((float)(*(v86 - 3) - v85[1]) * v92) + v85[1];
        v94 = *v86;
        v84[1] = v93;
        v95 = (float)(*(v86 - 2) - v91) * v92;
        v96 = *((_QWORD *)v86 - 2);
        v84[4] = 1.0;
        v84[2] = v95 + v91;
        *(_QWORD *)(v84 + 5) = v96;
        *(_QWORD *)(v84 + 7) = *((_QWORD *)v86 - 1);
        v84[9] = v94;
        v82 += 2;
        v84 += 10;
      }
      else
      {
        v89 = *v86;
        *(_QWORD *)v84 = *((_QWORD *)v86 - 2);
        *((_QWORD *)v84 + 1) = *((_QWORD *)v86 - 1);
        v84[4] = v89;
        ++v82;
        v84 += 5;
      }
      if ( v82 >= v112 )
        break;
      v85 = v86 - 4;
      ++v83;
      v86 += 5;
    }
    while ( v83 < v65 );
  }
  g_outCount = v82;
  memcpy(dst: (unsigned __int8 *)pOutPoints, src: (unsigned __int8 *)g_vert, count: 20 * v82);
  return v82;
}
