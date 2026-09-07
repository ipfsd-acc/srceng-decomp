// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/cubelight/cubelight.cpp
// Functions: 6
// ============================================================

#include "utils\cubelight\cubelight.h"

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: public: void FloatBitMap_t::Init(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::Init(FloatBitMap_t *this, int nXSize, int nYSize, int nZSize, char nAttributeMask)
{
  CSOAContainer::PurgeData(this);
  CSOAContainer::SetAttributeType(this, nAttrIdx: 0, nDataType: ATTRDATATYPE_FLOAT, bAllocateMemory: nAttributeMask & 1);
  CSOAContainer::SetAttributeType(
    this,
    nAttrIdx: 1,
    nDataType: ATTRDATATYPE_FLOAT,
    bAllocateMemory: (nAttributeMask & 2) != 0);
  CSOAContainer::SetAttributeType(
    this,
    nAttrIdx: 2,
    nDataType: ATTRDATATYPE_FLOAT,
    bAllocateMemory: (nAttributeMask & 4) != 0);
  CSOAContainer::SetAttributeType(
    this,
    nAttrIdx: 3,
    nDataType: ATTRDATATYPE_FLOAT,
    bAllocateMemory: (nAttributeMask & 8) != 0);
  CSOAContainer::AllocateData(this, nNCols: nXSize, nNRows: nYSize, nSlices: nZSize);
  if ( (nAttributeMask & 8) == 0 )
    CSOAContainer::FillAttr(this, nAttr: 3, flValue: 1.0);
}

//------------------------------------------------------------------------------
// Address: 0x004010A0
// Name: public: float FloatCubeMap_t::BrightestColor(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall FloatCubeMap_t::BrightestColor(FloatCubeMap_t *this)
{
  int i; // edi
  float ret; // [esp+0h] [ebp-4h]

  ret = 0.0;
  for ( i = 6; i != 0; --i )
  {
    if ( this->face_maps[0].m_nColumns * this->face_maps[0].m_nRows * this->face_maps[0].m_nSlices != 0
      && (double)ret <= FloatBitMap_t::BrightestColor(this: this->face_maps) )
    {
      ret = FloatBitMap_t::BrightestColor(this: this->face_maps);
    }
    this = (FloatCubeMap_t *)((char *)this + 804);
  }
  return ret;
}

//------------------------------------------------------------------------------
// Address: 0x004010F0
// Name: public: FloatCubeMap_t::FloatCubeMap_t(int,int)
// Source: json
//------------------------------------------------------------------------------
FloatCubeMap_t *__thiscall FloatCubeMap_t::FloatCubeMap_t(FloatCubeMap_t *this, int xfsize, int yfsize)
{
  int v3; // ebx
  unsigned __int8 **m_pSeparateDataMemory; // esi
  FloatCubeMap_t *v5; // esi
  int i; // ebx

  v3 = 5;
  m_pSeparateDataMemory = this->face_maps[0].m_pSeparateDataMemory;
  do
  {
    memset(dst: (unsigned __int8 *)m_pSeparateDataMemory - 520, value: 0xFFu, count: 0x80u);
    memset(dst: (unsigned __int8 *)m_pSeparateDataMemory, value: 0, count: 0x80u);
    *(m_pSeparateDataMemory - 1) = nullptr;
    *(m_pSeparateDataMemory - 163) = nullptr;
    *(m_pSeparateDataMemory - 164) = nullptr;
    *(m_pSeparateDataMemory - 166) = nullptr;
    *(m_pSeparateDataMemory - 167) = nullptr;
    *(m_pSeparateDataMemory - 165) = nullptr;
    *(m_pSeparateDataMemory - 168) = nullptr;
    *(m_pSeparateDataMemory - 2) = nullptr;
    m_pSeparateDataMemory[32] = nullptr;
    m_pSeparateDataMemory += 201;
    --v3;
  }
  while ( v3 >= 0 );
  v5 = this;
  for ( i = 6; i != 0; --i )
  {
    CSOAContainer::PurgeData(this: (CSOAContainer *)v5);
    CSOAContainer::SetAttributeType(
      this: (CSOAContainer *)v5,
      nAttrIdx: 0,
      nDataType: ATTRDATATYPE_FLOAT,
      bAllocateMemory: true);
    CSOAContainer::SetAttributeType(
      this: (CSOAContainer *)v5,
      nAttrIdx: 1,
      nDataType: ATTRDATATYPE_FLOAT,
      bAllocateMemory: true);
    CSOAContainer::SetAttributeType(
      this: (CSOAContainer *)v5,
      nAttrIdx: 2,
      nDataType: ATTRDATATYPE_FLOAT,
      bAllocateMemory: true);
    CSOAContainer::SetAttributeType(
      this: (CSOAContainer *)v5,
      nAttrIdx: 3,
      nDataType: ATTRDATATYPE_FLOAT,
      bAllocateMemory: true);
    CSOAContainer::AllocateData(this: (CSOAContainer *)v5, nNCols: xfsize, nNRows: yfsize, nSlices: 1);
    v5 = (FloatCubeMap_t *)((char *)v5 + 804);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004011E0
// Name: _main
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
int __cdecl main(int argc, const char **argv, const char **envp)
{
  int v3; // ebp
  double v4; // rdi
  void *v5; // esp
  float v7; // xmm4_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  int *p_m_nRows; // esi
  bool v12; // cc
  int v13; // eax
  int i; // edi
  float v15; // xmm5_4
  float v16; // xmm6_4
  float v17; // xmm3_4
  __int128 v18; // xmm5
  float z; // xmm1_4
  float v20; // xmm0_4
  float v21; // xmm4_4
  float v22; // xmm3_4
  int *v23; // esi
  int v24; // eax
  int j; // edi
  float v26; // xmm0_4
  float v27; // xmm1_4
  float v28; // xmm2_4
  __int128 v29; // xmm5
  __int128 v30; // xmm0
  double v31; // xmm0_8
  double y; // xmm0_8
  double x; // xmm0_8
  float v34; // xmm0_4
  float v35; // xmm1_4
  float v36; // xmm2_4
  float v37; // xmm5_4
  float v38; // xmm5_4
  float v39; // xmm4_4
  float v40; // xmm1_4
  unsigned int *m_nRowStrideInBytes; // esi
  int v42; // edi
  float v43; // xmm0_4
  int v44; // ecx
  int v45; // edx
  float v46; // xmm1_4
  int v47; // ecx
  int v48; // edx
  float v49; // xmm1_4
  int v50; // ecx
  int v51; // edx
  int v52; // eax
  float v53; // xmm2_4
  float v54; // xmm0_4
  float v55; // xmm1_4
  float v56; // xmm2_4
  float v57; // xmm3_4
  int v58; // eax
  float v59; // ecx
  int v60; // edx
  float v61; // xmm7_4
  float v62; // xmm0_4
  float v63; // xmm7_4
  float v64; // xmm3_4
  double v65; // xmm0_8
  double v66; // xmm0_8
  double v67; // xmm0_8
  int *v68; // esi
  int m; // edi
  float v70; // xmm0_4
  float v71; // xmm1_4
  float v72; // xmm0_4
  unsigned int v73; // eax
  int v74; // eax
  int v75; // edx
  CSOAContainer *v76; // esi
  int n; // edi
  FloatCubeMap_t *v78; // esi
  int ii; // edi
  long double v80; // [esp+10h] [ebp-2654h]
  int v81; // [esp+10h] [ebp-2654h]
  long double v82; // [esp+10h] [ebp-2654h]
  int v83; // [esp+10h] [ebp-2654h]
  long double v84; // [esp+14h] [ebp-2650h]
  int v85; // [esp+14h] [ebp-2650h]
  long double v86; // [esp+14h] [ebp-2650h]
  int v87; // [esp+14h] [ebp-2650h]
  long double v88; // [esp+18h] [ebp-264Ch]
  long double v89; // [esp+18h] [ebp-264Ch]
  long double v90; // [esp+18h] [ebp-264Ch]
  long double v91; // [esp+18h] [ebp-264Ch]
  long double v92; // [esp+1Ch] [ebp-2648h]
  long double v93; // [esp+20h] [ebp-2644h]
  long double v94; // [esp+20h] [ebp-2644h] OVERLAPPED
  FloatCubeMap_t v95; // [esp+28h] [ebp-263Ch] BYREF
  FloatCubeMap_t v96; // [esp+1300h] [ebp-1364h] BYREF
  __int128 v97; // [esp+25D8h] [ebp-8Ch] BYREF
  float v98; // [esp+25ECh] [ebp-78h]
  Vector v99; // [esp+25F0h] [ebp-74h] BYREF
  float v100; // [esp+25FCh] [ebp-68h]
  int v101; // [esp+2600h] [ebp-64h]
  int v102; // [esp+2604h] [ebp-60h]
  float v103; // [esp+2608h] [ebp-5Ch]
  Vector v104; // [esp+260Ch] [ebp-58h] BYREF
  Vector v105; // [esp+2618h] [ebp-4Ch] BYREF
  Vector v106; // [esp+2624h] [ebp-40h] BYREF
  Vector v107; // [esp+2630h] [ebp-34h] BYREF
  float v108; // [esp+263Ch] [ebp-28h]
  float v109; // [esp+2640h] [ebp-24h]
  float v110; // [esp+2644h] [ebp-20h]
  float v111; // [esp+2648h] [ebp-1Ch]
  int v112; // [esp+264Ch] [ebp-18h]
  int k; // [esp+2650h] [ebp-14h]
  int v114; // [esp+2654h] [ebp-10h]
  int v115; // [esp+2658h] [ebp-Ch]
  void *v116; // [esp+265Ch] [ebp-8h]
  void *retaddr; // [esp+2664h] [ebp+0h]

  v115 = v3;
  v116 = retaddr;
  v5 = alloca(9784);
  v88 = v4;
  InitCommandLineProgram(&argc, (char ***)&argv);
  if ( argc == 2 )
  {
    FloatCubeMap_t::FloatCubeMap_t(this: &v95, basename: argv[1]);
    v7 = 0.0;
    v8 = 0.0;
    v108 = FloatCubeMap_t::BrightestColor(this: &v95) * 0.9;
    v9 = 0.0;
    v10 = 0.0;
    *(float *)&v112 = 0.0;
    v109 = 0.0;
    v110 = 0.0;
    v111 = 0.0;
    v114 = 0;
    p_m_nRows = &v95.face_maps[0].m_nRows;
    do
    {
      v12 = *p_m_nRows <= 0;
      k = 0;
      if ( !v12 )
      {
        v13 = k;
        do
        {
          for ( i = 0; i < *(p_m_nRows - 1); ++i )
          {
            v15 = *(float *)(i * p_m_nRows[70] + v13 * p_m_nRows[102] + p_m_nRows[6]);
            v16 = *(float *)(i * p_m_nRows[71] + v13 * p_m_nRows[103] + p_m_nRows[7]);
            v106.x = *(float *)(v13 * p_m_nRows[101] + i * p_m_nRows[69] + p_m_nRows[5]);
            v106.y = v15;
            v106.z = v16;
            v17 = (float)((float)(v106.x * v106.x) + (float)(v15 * v15)) + (float)(v16 * v16);
            v18 = 0;
            *(float *)&v18 = fsqrt(v17);
            v97 = v18;
            if ( v108 > *(float *)&v18 )
            {
              z = FloatCubeMap_t::PixelDirection(this: &v95, result: &v99, face: v114, x: i, y: k)->z;
              if ( z <= 0.2 )
              {
                if ( z <= 0.0 )
                  v20 = 0.2;
                else
                  v20 = 1.0 - (float)((float)((float)(z - 0.2) * 0.80000001) * -5.0);
              }
              else
              {
                v20 = 1.0;
              }
              v13 = k;
              v7 = v20 + *(float *)&v112;
              v8 = (float)(v106.x * v20) + v109;
              v9 = (float)(v106.y * v20) + v110;
              v10 = (float)(v20 * v106.z) + v111;
              *(float *)&v112 = v7;
              v109 = v8;
              v110 = v9;
              v111 = v10;
            }
          }
          k = ++v13;
        }
        while ( v13 < *p_m_nRows );
      }
      p_m_nRows += 201;
      ++v114;
    }
    while ( v114 < 6 );
    v21 = 1.0 / v7;
    v22 = v21 * v8;
    v109 = v21 * v8;
    v110 = v9 * v21;
    v111 = v10 * v21;
    memset(&v107, 0, sizeof(v107));
    memset(&v105, 0, sizeof(v105));
    v114 = 0;
    v23 = &v95.face_maps[0].m_nRows;
    do
    {
      *(float *)&v24 = 0.0;
      *(float *)&v112 = 0.0;
      if ( *v23 > 0 )
      {
        do
        {
          for ( j = 0; j < *(v23 - 1); ++j )
          {
            v26 = *(float *)(v24 * v23[101] + j * v23[69] + v23[5]);
            v27 = *(float *)(j * v23[70] + v24 * v23[102] + v23[6]);
            v28 = *(float *)(j * v23[71] + v24 * v23[103] + v23[7]);
            v29 = 0;
            *(float *)&v29 = fsqrt((float)((float)(v27 * v27) + (float)(v28 * v28)) + (float)(v26 * v26));
            v97 = v29;
            if ( *(float *)&v29 > v108 )
            {
              v106.x = v26 - v22;
              v106.y = v27 - v110;
              v106.z = v28 - v111;
              v105.x = (float)(v26 - v22) + v105.x;
              v105.y = (float)(v27 - v110) + v105.y;
              v105.z = (float)(v28 - v111) + v105.z;
              FloatCubeMap_t::PixelDirection(this: &v95, result: &v104, face: v114, x: j, y: v24);
              v22 = v109;
              v24 = v112;
              v103 = v106.y * v106.y;
              v30 = 0;
              *(float *)&v30 = fsqrt((float)((float)(v106.y * v106.y) + (float)(v106.z * v106.z)) + (float)(v106.x * v106.x));
              v97 = v30;
              v104.x = v104.x * *(float *)&v30;
              v104.y = v104.y * *(float *)&v30;
              v104.z = v104.z * *(float *)&v30;
              v107.x = v104.x + v107.x;
              v107.y = v104.y + v107.y;
              v107.z = v104.z + v107.z;
            }
          }
          v112 = ++v24;
        }
        while ( v24 < *v23 );
      }
      v23 += 201;
      ++v114;
    }
    while ( v114 < 6 );
    VectorNormalize(vec: &v105);
    VectorNormalize(vec: &v107);
    printf(format: "Point light dir=%f %f %f\n", v107.x, v107.y, v107.z);
    v31 = v105.z;
    __libm_sse2_pow(x: v88, y: v93);
    *(float *)&v31 = v31;
    LODWORD(v84) = (int)(float)(*(float *)&v31 * 255.0);
    y = v105.y;
    __libm_sse2_pow(x: v84, y: *(long double *)((char *)&v94 - 4));
    *(float *)&y = y;
    LODWORD(v80) = (int)(float)(*(float *)&y * 255.0);
    x = v105.x;
    __libm_sse2_pow(x: v80, y: v89);
    *(float *)&x = x;
    printf(format: "Point light color=%d %d %d 255\n", (int)(float)(*(float *)&x * 255.0), v81, v85);
    FloatCubeMap_t::FloatCubeMap_t(this: &v96, xfsize: 32, yfsize: 32);
    v34 = 0.0;
    v35 = 0.0;
    v36 = 0.0;
    v37 = 0.0;
    v109 = 0.0;
    v110 = 0.0;
    v111 = 0.0;
    v103 = 0.0;
    *(float *)&v112 = 0.0;
    for ( k = 0; k < 4824; k += 804 )
    {
      v12 = *(int *)((char *)&v96.face_maps[0].m_nRows + k) <= 0;
      v114 = 0;
      if ( !v12 )
      {
        do
        {
          v12 = *(int *)((char *)&v96.face_maps[0].m_nColumns + k) <= 0;
          v108 = 0.0;
          if ( !v12 )
          {
            do
            {
              FloatCubeMap_t::PixelDirection(this: &v96, result: &v106, face: v112, x: SLODWORD(v108), y: v114);
              v38 = v106.z;
              v39 = (float)((float)(v106.y * v107.y) + (float)(v106.x * v107.x)) + (float)(v106.z * v107.z);
              v98 = v39;
              if ( v39 < 0.0 )
              {
                v39 = 0.0;
                v98 = 0.0;
              }
              v40 = 0.0;
              v100 = 0.0;
              memset(&v104, 0, sizeof(v104));
              v101 = 0;
              m_nRowStrideInBytes = v95.face_maps[0].m_nRowStrideInBytes;
              do
              {
                v12 = *(int *)((char *)&v95.face_maps[0].m_nRows + k) <= 0;
                v102 = 0;
                if ( !v12 )
                {
                  do
                  {
                    v42 = 0;
                    if ( *(int *)((char *)&v95.face_maps[0].m_nColumns + k) > 0 )
                    {
                      do
                      {
                        FloatCubeMap_t::PixelDirection(this: &v95, result: &v99, face: v101, x: v42, y: v102);
                        v38 = v106.z;
                        v43 = (float)((float)(v99.y * v106.y) + (float)(v99.x * v106.x)) + (float)(v99.z * v106.z);
                        if ( v43 > 0.0 )
                        {
                          v44 = v102 * *m_nRowStrideInBytes + v42 * *(m_nRowStrideInBytes - 32);
                          v45 = *(m_nRowStrideInBytes - 96);
                          v100 = v43 + v100;
                          v46 = *(float *)(v44 + v45);
                          v47 = v102 * m_nRowStrideInBytes[1] + v42 * *(m_nRowStrideInBytes - 31);
                          v48 = *(m_nRowStrideInBytes - 95);
                          v104.x = (float)(v46 * v43) + v104.x;
                          v49 = *(float *)(v47 + v48);
                          v50 = v42 * *(m_nRowStrideInBytes - 30);
                          v51 = v102 * m_nRowStrideInBytes[2];
                          v52 = *(m_nRowStrideInBytes - 94);
                          v104.y = (float)(v49 * v43) + v104.y;
                          v104.z = (float)(*(float *)(v51 + v50 + v52) * v43) + v104.z;
                        }
                        v42 += 20;
                      }
                      while ( v42 < *(int *)((char *)&v95.face_maps[0].m_nColumns + k) );
                      v39 = v98;
                    }
                    v102 += 20;
                  }
                  while ( v102 < *(int *)((char *)&v95.face_maps[0].m_nRows + k) );
                  v40 = v104.y;
                }
                m_nRowStrideInBytes += 201;
                ++v101;
              }
              while ( v101 < 6 );
              v53 = 1.0 / v100;
              v54 = v53 * v104.x;
              v55 = v40 * v53;
              v56 = v53 * v104.z;
              if ( v38 <= 0.2 )
              {
                if ( v38 <= 0.0 )
                  v57 = 0.2;
                else
                  v57 = 1.0 - (float)((float)((float)(v38 - 0.2) * 0.80000001) * -5.0);
              }
              else
              {
                v57 = 1.0;
              }
              v58 = k;
              v59 = v108;
              v60 = v114;
              *(float *)&(*(unsigned __int8 **)((char *)v96.face_maps[0].m_pAttributePtrs + k))[LODWORD(v108)
                                                                                              * *(unsigned int *)((char *)v96.face_maps[0].m_nStrideInBytes + k)
                                                                                              + v114
                                                                                              * *(unsigned int *)((char *)v96.face_maps[0].m_nRowStrideInBytes + k)] = v54;
              v61 = v39 * v105.x;
              *(float *)&(*(unsigned __int8 **)((char *)&v96.face_maps[0].m_pAttributePtrs[1] + v58))[LODWORD(v59) * *(unsigned int *)((char *)&v96.face_maps[0].m_nStrideInBytes[1] + v58) + v60 * *(unsigned int *)((char *)&v96.face_maps[0].m_nRowStrideInBytes[1] + v58)] = v55;
              v62 = v54 - v61;
              v63 = v39 * v105.y;
              *(float *)&(*(unsigned __int8 **)((char *)&v96.face_maps[0].m_pAttributePtrs[2] + v58))[LODWORD(v59) * *(unsigned int *)((char *)&v96.face_maps[0].m_nStrideInBytes[2] + v58) + v60 * *(unsigned int *)((char *)&v96.face_maps[0].m_nRowStrideInBytes[2] + v58)] = v56;
              v37 = v57 + v103;
              v34 = (float)(v62 * v57) + v109;
              v35 = (float)((float)(v55 - v63) * v57) + v110;
              v36 = (float)((float)(v56 - (float)(v39 * v105.z)) * v57) + v111;
              v103 = v57 + v103;
              v109 = v34;
              v110 = v35;
              v111 = v36;
              LODWORD(v108) = LODWORD(v59) + 1;
            }
            while ( LODWORD(v59) + 1 < *(int *)((char *)&v96.face_maps[0].m_nColumns + v58) );
          }
          ++v114;
        }
        while ( v114 < *(int *)((char *)&v96.face_maps[0].m_nRows + k) );
      }
      ++v112;
    }
    v64 = 1.0 / v37;
    v109 = v64 * v34;
    v110 = v64 * v35;
    v111 = v64 * v36;
    FloatCubeMap_t::WritePFMs(this: &v96, basename: "ambient_cube_");
    v65 = v111;
    __libm_sse2_pow(x: v90, y: v94);
    *(float *)&v65 = v65;
    LODWORD(v86) = (int)(float)(*(float *)&v65 * 255.0);
    v66 = v110;
    __libm_sse2_pow(x: v86, y: v92);
    *(float *)&v66 = v66;
    LODWORD(v82) = (int)(float)(*(float *)&v66 * 255.0);
    v67 = v109;
    __libm_sse2_pow(x: v82, y: v91);
    *(float *)&v67 = v67;
    printf(format: "Ambient color=%d %d %d 255\n", (int)(float)(*(float *)&v67 * 255.0), v83, v87);
    *(float *)&v112 = 0.0;
    v68 = &v95.face_maps[0].m_nRows;
    do
    {
      v12 = *v68 <= 0;
      v114 = 0;
      if ( !v12 )
      {
        do
        {
          for ( m = 0; m < *(v68 - 1); *(float *)(v75 + v68[7]) = (float)(v72 * v105.z) + v111 )
          {
            FloatCubeMap_t::PixelDirection(this: &v95, result: &v99, face: v112, x: m, y: v114);
            v70 = (float)((float)(v99.y * v107.y) + (float)(v99.x * v107.x)) + (float)(v99.z * v107.z);
            if ( v70 < 0.0 )
              v70 = 0.0;
            v71 = v70;
            v72 = 1.0;
            v73 = 7;
            while ( 1 )
            {
              if ( (v73 & 1) != 0 )
                v72 = v72 * v71;
              v73 >>= 1;
              if ( v73 == 0 )
                break;
              v71 = v71 * v71;
            }
            v74 = v114;
            *(float *)(m * v68[69] + v114 * v68[101] + v68[5]) = (float)(v72 * v105.x) + v109;
            *(float *)(v74 * v68[102] + m * v68[70] + v68[6]) = (float)(v72 * v105.y) + v110;
            v75 = m * v68[71] + v74 * v68[103];
            ++m;
          }
          ++v114;
        }
        while ( v114 < *v68 );
      }
      v68 += 201;
      ++v112;
    }
    while ( v112 < 6 );
    FloatCubeMap_t::WritePFMs(this: &v95, basename: "directional_plus_ambient_");
    v76 = (CSOAContainer *)&v97;
    for ( n = 5; n >= 0; --n )
      CSOAContainer::~CSOAContainer(this: --v76);
    v78 = &v96;
    for ( ii = 5; ii >= 0; --ii )
    {
      v78 = (FloatCubeMap_t *)((char *)v78 - 804);
      CSOAContainer::~CSOAContainer(this: (CSOAContainer *)v78);
    }
    return 0;
  }
  else
  {
    printf(format: "format is %s basename\n", *argv);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004046B0
// Name: public: FloatCubeMap_t::FloatCubeMap_t(char const __near *)
// Source: json
//------------------------------------------------------------------------------
FloatCubeMap_t *__thiscall FloatCubeMap_t::FloatCubeMap_t(FloatCubeMap_t *this, const char *basename)
{
  int v2; // ebx
  unsigned __int8 **m_pSeparateDataMemory; // esi
  FloatBitMap_t *v4; // edi
  const char **v5; // esi
  char fnamebuf[512]; // [esp+Ch] [ebp-204h] BYREF
  FloatBitMap_t *v8; // [esp+20Ch] [ebp-4h]

  v8 = (FloatBitMap_t *)this;
  v2 = 5;
  m_pSeparateDataMemory = this->face_maps[0].m_pSeparateDataMemory;
  do
  {
    memset(dst: (unsigned __int8 *)m_pSeparateDataMemory - 520, value: 0xFFu, count: 0x80u);
    memset(dst: (unsigned __int8 *)m_pSeparateDataMemory, value: 0, count: 0x80u);
    *(m_pSeparateDataMemory - 1) = nullptr;
    *(m_pSeparateDataMemory - 163) = nullptr;
    *(m_pSeparateDataMemory - 164) = nullptr;
    *(m_pSeparateDataMemory - 166) = nullptr;
    *(m_pSeparateDataMemory - 167) = nullptr;
    *(m_pSeparateDataMemory - 165) = nullptr;
    *(m_pSeparateDataMemory - 168) = nullptr;
    *(m_pSeparateDataMemory - 2) = nullptr;
    m_pSeparateDataMemory[32] = nullptr;
    m_pSeparateDataMemory += 201;
    --v2;
  }
  while ( v2 >= 0 );
  v4 = v8;
  v5 = namepts;
  do
  {
    sprintf(string: fnamebuf, format: *v5, basename);
    FloatBitMap_t::LoadFromPFM(this: v4, fname: fnamebuf);
    ++v5;
    ++v4;
  }
  while ( (int)v5 < (int)&vec2_invalid_1 );
  return (FloatCubeMap_t *)v8;
}

//------------------------------------------------------------------------------
// Address: 0x00401D60
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}
