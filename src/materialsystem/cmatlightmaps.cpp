// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/cmatlightmaps.cpp
// Functions: 37
// ============================================================

#include "materialsystem\cmatlightmaps.h"

//------------------------------------------------------------------------------
// Address: 0x10035820
// Name: public: void CMatLightmaps::GetLightmapPageSize(int,int __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatLightmaps::GetLightmapPageSize(
        CMatLightmaps *this,
        unsigned int lightmapPageID,
        int *pWidth,
        int *pHeight)
{
  if ( lightmapPageID == -3 )
  {
    *pHeight = 1;
    *pWidth = 1;
  }
  else if ( lightmapPageID < 0xFFFFFFFE )
  {
    *pWidth = this->m_pLightmapPages[lightmapPageID].m_Width;
    *pHeight = this->m_pLightmapPages[lightmapPageID].m_Height;
  }
  else
  {
    *pHeight = 1;
    *pWidth = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035880
// Name: public: int CMatLightmaps::GetLightmapWidth(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatLightmaps::GetLightmapWidth(CMatLightmaps *this, unsigned int lightmapPageID)
{
  if ( lightmapPageID > 0xFFFFFFFC )
    return 1;
  else
    return this->m_pLightmapPages[lightmapPageID].m_Width;
}

//------------------------------------------------------------------------------
// Address: 0x100358B0
// Name: public: int CMatLightmaps::GetLightmapHeight(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatLightmaps::GetLightmapHeight(CMatLightmaps *this, unsigned int lightmapPageID)
{
  if ( lightmapPageID > 0xFFFFFFFC )
    return 1;
  else
    return this->m_pLightmapPages[lightmapPageID].m_Height;
}

//------------------------------------------------------------------------------
// Address: 0x100358E0
// Name: public: int CMatLightmaps::AllocateDynamicLightmap(int __near * const,int __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatLightmaps::AllocateDynamicLightmap(
        CMatLightmaps *this,
        int *lightmapSize,
        int *pOutOffsetIntoPage,
        int frameID)
{
  int m_firstDynamicLightmap; // ebx
  int i; // [esp+Ch] [ebp-4h]

  i = 0;
  while ( 1 )
  {
    m_firstDynamicLightmap = this->m_firstDynamicLightmap;
    if ( this->m_dynamic.lightmapLockFrame[0] != frameID )
    {
      this->m_dynamic.lightmapLockFrame[0] = frameID;
      CImagePacker::Reset(
        this: this->m_dynamic.imagePackers,
        nSortId: 0,
        maxLightmapWidth: this->m_pLightmapPages[m_firstDynamicLightmap].m_Width,
        maxLightmapHeight: this->m_pLightmapPages[m_firstDynamicLightmap].m_Height);
    }
    if ( CImagePacker::AddBlock(
           this: this->m_dynamic.imagePackers,
           width: *lightmapSize,
           height: lightmapSize[1],
           returnX: pOutOffsetIntoPage,
           returnY: pOutOffsetIntoPage + 1) )
    {
      break;
    }
    if ( ++i >= 1 )
      return -1;
  }
  return m_firstDynamicLightmap;
}

//------------------------------------------------------------------------------
// Address: 0x10035960
// Name: public: static unsigned short float16::ConvertFloatTo16bitsNonDefault<0>(float)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __cdecl float16::ConvertFloatTo16bitsNonDefault<0>(float input)
{
  float v1; // xmm0_4
  int v2; // xmm1_4
  int v3; // eax
  int v4; // ecx
  int v5; // ecx
  float16::float16bits output; // [esp+8h] [ebp+8h]

  v1 = input;
  v2 = 1199562752;
  if ( input > 65504.0 || (v2 = -947920896, input < -65504.0) )
    v1 = *(float *)&v2;
  v3 = LOWORD(v1) & 0x7FFF | (LODWORD(v1) >> 31 << 15);
  v4 = (unsigned __int8)(LODWORD(v1) >> 23);
  output.rawWord = LOWORD(v1) & 0x7FFF | (LODWORD(v1) >> 31 << 15);
  if ( (unsigned __int8)(LODWORD(v1) >> 23) != 0 )
  {
    if ( v4 == 255 )
    {
      if ( (LODWORD(v1) & 0x7FFFFF) != 0 )
        LOWORD(v3) = LODWORD(v1) >> 31 << 15;
      else
        LOWORD(v3) = LOWORD(v1) & 0x7BFF | (LODWORD(v1) >> 31 << 15) | 0x7BFF;
    }
    else
    {
      v5 = v4 - 127;
      if ( v5 < -24 )
      {
        LOWORD(v3) = LODWORD(v1) >> 31 << 15;
        output.rawWord = v3;
      }
      if ( v5 >= -14 )
      {
        if ( v5 <= 15 )
          return (((_WORD)v5 + 15) << 10) & 0x7C00 | (LODWORD(v1) >> 13) & 0x3FF | output.rawWord & 0x8000;
        else
          LOWORD(v3) = output.rawWord & 0x8000 | 0x7BFF;
      }
      else
      {
        LOWORD(v3) = v3 & 0x83FF;
        if ( (unsigned int)(-14 - v5 - 1) <= 9 )
          LOWORD(v3) = (v3 ^ ((1 << (10 - (-14 - v5))) + ((LODWORD(v1) & 0x7FFFFFu) >> (-14 - v5 + 13)))) & 0x3FF ^ v3;
      }
    }
  }
  else
  {
    LOWORD(v3) = LODWORD(v1) >> 31 << 15;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10035B20
// Name: public: void FloatBitMap_t::WritePixelRGBAF(int,int,int,struct PixRGBAF)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatBitMap_t::WritePixelRGBAF(FloatBitMap_t *this, int x, int y, int z, PixRGBAF value)
{
  *(float *)&this->m_pAttributePtrs[0][x * this->m_nStrideInBytes[0]
                                     + y * this->m_nRowStrideInBytes[0]
                                     + z * this->m_nSliceStrideInBytes[0]] = value.Red;
  *(float *)&this->m_pAttributePtrs[1][x * this->m_nStrideInBytes[1]
                                     + y * this->m_nRowStrideInBytes[1]
                                     + z * this->m_nSliceStrideInBytes[1]] = value.Green;
  *(float *)&this->m_pAttributePtrs[2][x * this->m_nStrideInBytes[2]
                                     + y * this->m_nRowStrideInBytes[2]
                                     + z * this->m_nSliceStrideInBytes[2]] = value.Blue;
  *(float *)&this->m_pAttributePtrs[3][x * this->m_nStrideInBytes[3]
                                     + y * this->m_nRowStrideInBytes[3]
                                     + z * this->m_nSliceStrideInBytes[3]] = value.Alpha;
}

//------------------------------------------------------------------------------
// Address: 0x10035BF0
// Name: public: int CMatLightmaps::AllocateWhiteLightmap(class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMatLightmaps::AllocateWhiteLightmap(CMatLightmaps *this, IMaterial *iMaterial)
{
  IMaterialInternal *v4; // edi
  IMaterialInternal *m_currentWhiteLightmapMaterial; // eax
  char *v6; // ecx

  if ( iMaterial != nullptr )
  {
    v4 = (IMaterialInternal *)((int (__thiscall *)(IMaterial *))iMaterial->__vftable[1].Refresh)(a1: iMaterial);
    m_currentWhiteLightmapMaterial = this->m_currentWhiteLightmapMaterial;
    if ( m_currentWhiteLightmapMaterial == nullptr || m_currentWhiteLightmapMaterial != v4 )
    {
      v6 = (char *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
      if ( v6 == nullptr )
        v6 = (char *)this + 8420;
      if ( (*(int (__thiscall **)(char *))(*(_DWORD *)v6 + 820))(a1: v6) != 0
        || this->m_currentWhiteLightmapMaterial != nullptr )
      {
        ++this->m_numSortIDs;
      }
      this->m_currentWhiteLightmapMaterial = v4;
      v4->SetNeedsWhiteLightmap(this: v4, a2: true);
    }
    return this->m_numSortIDs;
  }
  else
  {
    _Warning(a1: "Programming error: CMatRenderContext::AllocateWhiteLightmap: NULL material\n");
    return this->m_numSortIDs;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10035C80
// Name: private: void CMatLightmaps::BumpedLightmapBitsToPixelWriter_LDR(float __near *,float __near *,float __near *,float __near *,int __near * const,int __near * const,class FloatBitMap_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatLightmaps::BumpedLightmapBitsToPixelWriter_LDR(
        CMatLightmaps *this,
        float *pFloatImage,
        float *pFloatImageBump1,
        float *pFloatImageBump2,
        float *pFloatImageBump3,
        int *pLightmapSize,
        int *pOffsetIntoLightmapPage,
        FloatBitMap_t *pfmOut)
{
  int m_Size; // eax
  int v10; // edi
  bool v11; // cc
  int v12; // edx
  unsigned __int8 *v13; // edi
  int v14; // ebx
  int v15; // eax
  int v16; // eax
  int v17; // eax
  float v18; // xmm0_4
  float v19; // xmm3_4
  float v20; // xmm6_4
  float v21; // xmm7_4
  float v22; // xmm0_4
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm5_4
  float v26; // xmm4_4
  float v27; // xmm3_4
  float v28; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm6_4
  float v32; // xmm2_4
  float v33; // xmm7_4
  float v34; // xmm0_4
  float v35; // xmm5_4
  float v36; // xmm1_4
  float v37; // xmm4_4
  float v38; // xmm3_4
  float v39; // xmm3_4
  float v40; // xmm3_4
  float v41; // xmm3_4
  int v42; // ecx
  int *v43; // ebx
  float *v44; // eax
  float v45; // xmm0_4
  float v46; // xmm1_4
  float v47; // xmm3_4
  float v48; // xmm0_4
  float v49; // xmm1_4
  float v50; // xmm2_4
  float v51; // xmm3_4
  float v52; // xmm1_4
  float v53; // xmm2_4
  float v54; // xmm3_4
  float *v55; // eax
  float *v56; // eax
  float v57; // xmm1_4
  float v58; // xmm0_4
  float v59; // xmm2_4
  float v60; // xmm4_4
  float v61; // xmm0_4
  float v62; // xmm3_4
  float v63; // xmm1_4
  float v64; // xmm7_4
  float v65; // xmm3_4
  float v66; // xmm0_4
  float v67; // xmm2_4
  float v68; // xmm1_4
  float v69; // xmm2_4
  float v70; // xmm3_4
  float v71; // xmm0_4
  float v72; // xmm4_4
  float v73; // xmm1_4
  unsigned __int8 v74; // bl
  unsigned int v75; // eax
  __int16 v76; // cx
  unsigned int v77; // eax
  unsigned int v78; // edx
  unsigned int v79; // edx
  unsigned int v80; // eax
  unsigned __int64 v81; // kr00_8
  unsigned __int64 v82; // rax
  __int16 m_BShift; // cx
  int v84; // edi
  int v85; // ebx
  signed __int64 v86; // rax
  __int64 v87; // rax
  unsigned __int64 v88; // rax
  int v89; // ebx
  int v90; // edi
  unsigned __int8 v91; // bl
  unsigned int v92; // eax
  __int16 v93; // cx
  unsigned int v94; // eax
  unsigned int v95; // edx
  unsigned int v96; // edx
  unsigned int v97; // eax
  unsigned __int64 v98; // kr08_8
  unsigned __int64 v99; // rax
  __int16 v100; // cx
  int v101; // edi
  int v102; // ebx
  signed __int64 v103; // rax
  __int64 v104; // rax
  unsigned __int64 v105; // rax
  int v106; // ebx
  int v107; // edi
  unsigned __int8 v108; // bl
  unsigned int v109; // eax
  __int16 v110; // cx
  unsigned int v111; // eax
  unsigned int v112; // edx
  unsigned int v113; // edx
  unsigned int v114; // eax
  unsigned __int64 v115; // kr10_8
  unsigned __int64 v116; // rax
  __int16 v117; // cx
  int v118; // edi
  int v119; // ebx
  signed __int64 v120; // rax
  __int64 v121; // rax
  unsigned __int64 v122; // rax
  int v123; // ebx
  int v124; // edi
  unsigned __int8 v125; // bl
  unsigned int v126; // eax
  __int16 v127; // cx
  unsigned int v128; // eax
  unsigned int v129; // edx
  unsigned int v130; // edx
  unsigned int v131; // eax
  unsigned __int64 v132; // kr18_8
  unsigned __int64 v133; // rax
  __int16 v134; // cx
  int v135; // edi
  int v136; // ebx
  signed __int64 v137; // rax
  __int64 v138; // rax
  unsigned __int64 v139; // rax
  int v140; // ebx
  int v141; // edi
  int v142; // eax
  int v144; // ebx
  int v145; // eax
  int v146; // eax
  int v147; // eax
  float v148; // xmm0_4
  float v149; // xmm3_4
  float v150; // xmm6_4
  float v151; // xmm7_4
  float v152; // xmm0_4
  float v153; // xmm1_4
  float v154; // xmm2_4
  float v155; // xmm5_4
  float v156; // xmm4_4
  float v157; // xmm3_4
  float v158; // xmm2_4
  float v159; // xmm0_4
  float v160; // xmm1_4
  float v161; // xmm6_4
  float v162; // xmm2_4
  float v163; // xmm7_4
  float v164; // xmm0_4
  float v165; // xmm5_4
  float v166; // xmm1_4
  float v167; // xmm4_4
  float v168; // xmm3_4
  float v169; // xmm3_4
  float v170; // xmm3_4
  float v171; // xmm3_4
  int v172; // esi
  int *v173; // edi
  float *v174; // eax
  float v175; // xmm2_4
  float v176; // xmm1_4
  float v177; // xmm4_4
  float v178; // xmm0_4
  float v179; // xmm2_4
  float v180; // xmm3_4
  float v181; // xmm1_4
  float v182; // xmm2_4
  float v183; // xmm3_4
  float v184; // xmm1_4
  float *v185; // eax
  float *v186; // eax
  float v187; // xmm2_4
  float v188; // xmm3_4
  float v189; // xmm3_4
  float v190; // xmm6_4
  float v191; // xmm1_4
  float v192; // xmm4_4
  float v193; // xmm2_4
  float v194; // xmm6_4
  float v195; // xmm7_4
  float v196; // xmm1_4
  float v197; // xmm3_4
  float v198; // xmm2_4
  float v199; // xmm2_4
  float v200; // xmm3_4
  float v201; // xmm1_4
  float v202; // xmm4_4
  float v203; // xmm1_4
  float v204; // xmm1_4
  float v205; // xmm3_4
  float v206; // xmm2_4
  char *v207; // eax
  int v208; // edx
  __int64 v209; // [esp+Ch] [ebp-120h]
  __int64 v210; // [esp+14h] [ebp-118h]
  __int64 v211; // [esp+1Ch] [ebp-110h]
  __int64 v212; // [esp+24h] [ebp-108h]
  float v213; // [esp+2Ch] [ebp-100h]
  float v214; // [esp+34h] [ebp-F8h]
  float v215; // [esp+38h] [ebp-F4h]
  float v216; // [esp+40h] [ebp-ECh]
  float v217; // [esp+44h] [ebp-E8h]
  float v218; // [esp+50h] [ebp-DCh]
  float v219; // [esp+58h] [ebp-D4h]
  float *v220; // [esp+68h] [ebp-C4h]
  float *v221; // [esp+6Ch] [ebp-C0h]
  float *v222; // [esp+70h] [ebp-BCh]
  float v223; // [esp+74h] [ebp-B8h]
  float v224; // [esp+78h] [ebp-B4h]
  int nRewindToNextPixel; // [esp+7Ch] [ebp-B0h]
  float v226; // [esp+80h] [ebp-ACh]
  float v227; // [esp+84h] [ebp-A8h]
  float v228; // [esp+88h] [ebp-A4h]
  int nLightmapSize0; // [esp+8Ch] [ebp-A0h]
  int v230; // [esp+90h] [ebp-9Ch]
  int v231; // [esp+94h] [ebp-98h]
  int nLightmap0WriterSizeBytes; // [esp+98h] [ebp-94h]
  int v233; // [esp+9Ch] [ebp-90h]
  int j; // [esp+A0h] [ebp-8Ch]
  int v235; // [esp+A4h] [ebp-88h]
  int v236; // [esp+A8h] [ebp-84h]
  float v237; // [esp+ACh] [ebp-80h]
  int v238; // [esp+B0h] [ebp-7Ch]
  int v239; // [esp+B4h] [ebp-78h]
  int v240; // [esp+B8h] [ebp-74h]
  int s; // [esp+BCh] [ebp-70h]
  int v242; // [esp+C0h] [ebp-6Ch]
  int v243; // [esp+C4h] [ebp-68h]
  int v244; // [esp+C8h] [ebp-64h]
  int srcTexelOffset; // [esp+CCh] [ebp-60h]
  int v246; // [esp+D0h] [ebp-5Ch]
  int t; // [esp+D4h] [ebp-58h]
  __int64 v248; // [esp+D8h] [ebp-54h]
  float v249; // [esp+E0h] [ebp-4Ch]
  int i; // [esp+E4h] [ebp-48h]
  float v251; // [esp+E8h] [ebp-44h]
  __int64 v252; // [esp+ECh] [ebp-40h]
  float v253; // [esp+F4h] [ebp-38h]
  int v254; // [esp+F8h] [ebp-34h]
  int v255; // [esp+FCh] [ebp-30h] BYREF
  int v256; // [esp+100h] [ebp-2Ch]
  int v257; // [esp+104h] [ebp-28h]
  float v258; // [esp+108h] [ebp-24h] BYREF
  float v259; // [esp+10Ch] [ebp-20h]
  float v260; // [esp+110h] [ebp-1Ch]
  float v261; // [esp+114h] [ebp-18h] BYREF
  float v262; // [esp+118h] [ebp-14h]
  float v263; // [esp+11Ch] [ebp-10h]
  float v264; // [esp+120h] [ebp-Ch] BYREF
  float v265; // [esp+124h] [ebp-8h]
  float v266; // [esp+128h] [ebp-4h]
  FloatBitMap_t *pfmOuta; // [esp+14Ch] [ebp+20h]

  m_Size = this->m_LightmapPixelWriter.m_Size;
  v10 = *pLightmapSize;
  nLightmap0WriterSizeBytes = *pLightmapSize * m_Size;
  v11 = pLightmapSize[1] <= 0;
  nLightmapSize0 = v10;
  nRewindToNextPixel = m_Size - 3 * nLightmap0WriterSizeBytes;
  t = 0;
  if ( !v11 )
  {
    while ( 1 )
    {
      v12 = nLightmapSize0;
      srcTexelOffset = 4 * nLightmapSize0 * t;
      v13 = &this->m_LightmapPixelWriter.m_pBase[*pOffsetIntoLightmapPage * this->m_LightmapPixelWriter.m_Size
                                               + this->m_LightmapPixelWriter.m_BytesPerRow
                                               * (t + pOffsetIntoLightmapPage[1])];
      s = 0;
      this->m_LightmapPixelWriter.m_pBits = v13;
      if ( v12 > 0 )
        break;
LABEL_207:
      if ( ++t >= pLightmapSize[1] )
        goto LABEL_208;
    }
    v220 = &v261;
    v221 = &v264;
    v222 = &v258;
    while ( 1 )
    {
      v14 = srcTexelOffset;
      v244 = (int)(float)(pFloatImage[srcTexelOffset] * 1024.0);
      v15 = v244;
      if ( (unsigned int)v244 > 0xFFF )
        v15 = v244 < 0 ? 0 : 0xFFF;
      *(float *)&v252 = lineartovertex[v15];
      v231 = (int)(float)(pFloatImage[v14 + 1] * 1024.0);
      v16 = v231;
      if ( (unsigned int)v231 > 0xFFF )
        v16 = v231 < 0 ? 0 : 0xFFF;
      *((float *)&v252 + 1) = lineartovertex[v16];
      v240 = (int)(float)(pFloatImage[v14 + 2] * 1024.0);
      v17 = v240;
      if ( (unsigned int)v240 > 0xFFF )
        v17 = v240 < 0 ? 0 : 0xFFF;
      v18 = lineartovertex[v17];
      v249 = pFloatImageBump1[v14 + 2];
      v19 = pFloatImageBump2[v14 + 2];
      v20 = pFloatImageBump2[v14];
      v21 = pFloatImageBump2[v14 + 1];
      v253 = v18;
      v248 = *(_QWORD *)&pFloatImageBump1[v14];
      v228 = pFloatImageBump3[v14];
      v214 = pFloatImageBump3[v14 + 1];
      v217 = v19;
      v213 = pFloatImageBump3[v14 + 2];
      v22 = (float)(v228 + (float)(v20 + *(float *)&v248)) * 0.33333334;
      *(float *)&v248 = v22;
      v23 = (float)(v214 + (float)(v21 + *((float *)&v248 + 1))) * 0.33333334;
      v24 = (float)(v213 + (float)(v19 + v249)) * 0.33333334;
      *((float *)&v248 + 1) = v23;
      v249 = v24;
      if ( v22 == 0.0 || HIDWORD(v248) == 0 || v249 == 0.0 )
      {
        v27 = 0.0;
        v25 = 0.0;
        v26 = 0.0;
        if ( v22 != 0.0 )
          v25 = *(float *)&v252 / v22;
        if ( v23 != 0.0 )
          v26 = *((float *)&v252 + 1) / v23;
        if ( v249 != 0.0 )
          v27 = v253 / v249;
      }
      else
      {
        v25 = *(float *)&v252 / v22;
        v26 = *((float *)&v252 + 1) / v23;
        v27 = v253 / v24;
      }
      v28 = pFloatImageBump1[v14];
      v29 = pFloatImageBump1[v14 + 1];
      v30 = pFloatImageBump1[v14 + 2];
      v264 = v20 * v25;
      v31 = v21 * v26;
      v266 = v217 * v27;
      v32 = v28 * v25;
      v33 = v228 * v25;
      v34 = v29 * v26;
      v35 = v214 * v26;
      v36 = v30 * v27;
      v37 = v213 * v27;
      v261 = v32;
      v262 = v34;
      v263 = v36;
      v265 = v31;
      v258 = v33;
      v259 = v35;
      v260 = v213 * v27;
      if ( v34 <= v36 )
        v38 = v36;
      else
        v38 = v34;
      if ( v32 <= v38 )
      {
        if ( v34 > v36 )
          v36 = v34;
      }
      else
      {
        v36 = v32;
      }
      if ( v31 <= v266 )
        v39 = v266;
      else
        v39 = v31;
      if ( v264 <= v39 )
      {
        if ( v31 <= v266 )
          v31 = v266;
      }
      else
      {
        v31 = v264;
      }
      if ( v35 <= v37 )
        v40 = v37;
      else
        v40 = v35;
      if ( v33 <= v40 )
      {
        if ( v35 <= v37 )
          v41 = v37;
        else
          v41 = v35;
      }
      else
      {
        v41 = v33;
      }
      if ( v36 < v31 || v31 < v41 )
      {
        v42 = 2;
      }
      else
      {
        v42 = 2;
        v255 = 0;
        v256 = 1;
        v257 = 2;
      }
      if ( v36 >= v41 && v41 >= v31 )
      {
        v255 = 0;
        v256 = 2;
        v257 = 1;
      }
      if ( v31 >= v36 && v36 >= v41 )
      {
        v255 = 1;
        v256 = 0;
        v257 = 2;
      }
      if ( v31 < v41 )
        goto LABEL_55;
      if ( v41 >= v36 )
        break;
LABEL_58:
      if ( v41 >= v31 && v31 >= v36 )
      {
        v255 = 2;
        v256 = 1;
        v257 = 0;
      }
      v43 = &v255;
      for ( i = 3; i != 0; --i )
      {
        v44 = (&v220)[*v43];
        v45 = v44[1];
        v46 = v44[2];
        if ( v45 <= v46 )
          v47 = v44[2];
        else
          v47 = v44[1];
        if ( *v44 <= v47 )
        {
          if ( v45 > v46 )
            v46 = v44[1];
        }
        else
        {
          v46 = *v44;
        }
        if ( v46 > 1.0 )
        {
          v48 = (float)(v46 - 1.0) / v46;
          v49 = v48 * *v44;
          v50 = v44[1] * v48;
          v51 = v44[2] * v48;
          *v44 = *v44 - v49;
          v44[1] = v44[1] - v50;
          v44[2] = v44[2] - v51;
          v52 = v49 * 0.5;
          v53 = v50 * 0.5;
          v54 = v51 * 0.5;
          v55 = (&v220)[*(&v255 + (v42 - 1) % 3)];
          *v55 = *v55 + v52;
          v55[1] = v53 + v55[1];
          v55[2] = v54 + v55[2];
          v56 = (&v220)[*(&v255 + v42 % 3)];
          v57 = v52 + *v56;
          v56[1] = v56[1] + v53;
          v58 = v56[2] + v54;
          *v56 = v57;
          v56[2] = v58;
        }
        ++v43;
        ++v42;
      }
      v59 = v262;
      v60 = v263;
      if ( v262 <= v263 )
        v61 = v263;
      else
        v61 = v262;
      v62 = v261;
      if ( v261 <= v61 )
      {
        if ( v262 <= v263 )
          v63 = v263;
        else
          v63 = v262;
      }
      else
      {
        v63 = v261;
      }
      if ( v63 > 1.0 )
      {
        v62 = v261 * (float)(1.0 / v63);
        v59 = (float)(1.0 / v63) * v262;
        v60 = (float)(1.0 / v63) * v263;
        v261 = v62;
        v262 = v59;
        v263 = v60;
      }
      if ( v62 < 0.0 )
        v261 = 0.0;
      if ( v59 < 0.0 )
        v262 = 0.0;
      if ( v60 < 0.0 )
        v263 = 0.0;
      v64 = v265;
      v65 = v266;
      if ( v265 <= v266 )
        v66 = v266;
      else
        v66 = v265;
      v67 = v264;
      if ( v264 <= v66 )
      {
        if ( v265 <= v266 )
          v68 = v266;
        else
          v68 = v265;
      }
      else
      {
        v68 = v264;
      }
      if ( v68 > 1.0 )
      {
        v67 = v264 * (float)(1.0 / v68);
        v64 = (float)(1.0 / v68) * v265;
        v65 = (float)(1.0 / v68) * v266;
        v264 = v67;
        v265 = v64;
        v266 = v65;
      }
      if ( v67 < 0.0 )
        v264 = 0.0;
      if ( v64 < 0.0 )
      {
        v64 = 0.0;
        v265 = 0.0;
      }
      if ( v65 < 0.0 )
        v266 = 0.0;
      v69 = v259;
      v70 = v260;
      if ( v259 <= v260 )
        v71 = v260;
      else
        v71 = v259;
      v72 = v258;
      if ( v258 <= v71 )
      {
        if ( v259 <= v260 )
          v73 = v260;
        else
          v73 = v259;
      }
      else
      {
        v73 = v258;
      }
      if ( v73 > 1.0 )
      {
        v72 = v258 * (float)(1.0 / v73);
        v69 = (float)(1.0 / v73) * v259;
        v70 = (float)(1.0 / v73) * v260;
        v258 = v72;
        v259 = v69;
        v260 = v70;
      }
      if ( v72 < 0.0 )
      {
        v72 = 0.0;
        v258 = 0.0;
      }
      if ( v69 < 0.0 )
      {
        v69 = 0.0;
        v259 = 0.0;
      }
      if ( v70 < 0.0 )
      {
        v70 = 0.0;
        v260 = 0.0;
      }
      if ( v261 < 0.0 )
        v261 = 0.0;
      if ( v262 < 0.0 )
        v262 = 0.0;
      if ( v263 < 0.0 )
        v263 = 0.0;
      if ( v264 < 0.0 )
        v264 = 0.0;
      if ( v64 < 0.0 )
        v265 = 0.0;
      if ( v266 < 0.0 )
        v266 = 0.0;
      if ( v72 < 0.0 )
        v258 = 0.0;
      if ( v69 < 0.0 )
        v259 = 0.0;
      if ( v70 < 0.0 )
        v260 = 0.0;
      v226 = *(float *)&v252 * 255.0;
      v238 = (int)(float)(*(float *)&v252 * 255.0);
      v223 = *((float *)&v252 + 1) * 255.0;
      v239 = (int)(float)(*((float *)&v252 + 1) * 255.0);
      v224 = v253 * 255.0;
      v246 = (int)(float)(v253 * 255.0);
      j = (int)(float)(v261 * 255.0);
      LODWORD(v237) = (int)(float)(v262 * 255.0);
      v242 = (int)(float)(v263 * 255.0);
      v236 = (int)(float)(v264 * 255.0);
      v235 = (int)(float)(v265 * 255.0);
      v233 = (int)(float)(v266 * 255.0);
      v243 = (int)(float)(v258 * 255.0);
      v230 = (int)(float)(v259 * 255.0);
      LODWORD(v251) = (int)(float)(v260 * 255.0);
      v227 = pFloatImage[srcTexelOffset + 3] * 255.0;
      v254 = (int)v227;
      v74 = this->m_LightmapPixelWriter.m_Size;
      if ( v74 != 0 )
      {
        v75 = (unsigned __int8)v238 & this->m_LightmapPixelWriter.m_RMask;
        if ( v74 >= 5u )
        {
          v81 = (unsigned __int64)v75 << this->m_LightmapPixelWriter.m_RShift;
          v82 = (unsigned __int64)((unsigned __int8)v239 & this->m_LightmapPixelWriter.m_GMask) << this->m_LightmapPixelWriter.m_GShift;
          m_BShift = this->m_LightmapPixelWriter.m_BShift;
          v84 = HIDWORD(v82) | HIDWORD(v81);
          v85 = v82 | v81;
          v86 = (unsigned __int8)v246 & (unsigned __int64)this->m_LightmapPixelWriter.m_BMask;
          if ( m_BShift <= 0 )
            v87 = v86 >> -(char)m_BShift;
          else
            v87 = v86 << m_BShift;
          v212 = v87;
          v88 = (unsigned __int64)((unsigned __int8)v254 & this->m_LightmapPixelWriter.m_AMask) << this->m_LightmapPixelWriter.m_AShift;
          v89 = v212 | v88 | v85;
          v90 = HIDWORD(v212) | HIDWORD(v88) | v84;
          if ( this->m_LightmapPixelWriter.m_Size == 6 )
          {
            *(_DWORD *)this->m_LightmapPixelWriter.m_pBits = v89;
            *((_WORD *)this->m_LightmapPixelWriter.m_pBits + 2) = v90;
          }
          else if ( this->m_LightmapPixelWriter.m_Size == 8 )
          {
            *(_DWORD *)this->m_LightmapPixelWriter.m_pBits = v89;
            *((_DWORD *)this->m_LightmapPixelWriter.m_pBits + 1) = v90;
          }
        }
        else
        {
          v76 = this->m_LightmapPixelWriter.m_BShift;
          v77 = (((unsigned __int8)v239 & this->m_LightmapPixelWriter.m_GMask) << LOBYTE(this->m_LightmapPixelWriter.m_GShift))
              | (v75 << LOBYTE(this->m_LightmapPixelWriter.m_RShift));
          v78 = (unsigned __int8)v246 & this->m_LightmapPixelWriter.m_BMask;
          if ( v76 <= 0 )
            v79 = v78 >> -(char)v76;
          else
            v79 = v78 << v76;
          v80 = v79
              | (((unsigned __int8)v254 & this->m_LightmapPixelWriter.m_AMask) << LOBYTE(this->m_LightmapPixelWriter.m_AShift))
              | v77;
          switch ( v74 )
          {
            case 1u:
              *this->m_LightmapPixelWriter.m_pBits = v80;
              break;
            case 2u:
              *(_WORD *)this->m_LightmapPixelWriter.m_pBits = v80;
              break;
            case 3u:
              *(_WORD *)this->m_LightmapPixelWriter.m_pBits = v80;
              this->m_LightmapPixelWriter.m_pBits[2] = BYTE2(v80);
              break;
            case 4u:
              *(_DWORD *)this->m_LightmapPixelWriter.m_pBits = v80;
              break;
          }
        }
      }
      this->m_LightmapPixelWriter.m_pBits += nLightmap0WriterSizeBytes;
      v91 = this->m_LightmapPixelWriter.m_Size;
      if ( v91 != 0 )
      {
        v92 = (unsigned __int8)j & this->m_LightmapPixelWriter.m_RMask;
        if ( v91 >= 5u )
        {
          v98 = (unsigned __int64)v92 << this->m_LightmapPixelWriter.m_RShift;
          v99 = (unsigned __int64)(LOBYTE(v237) & this->m_LightmapPixelWriter.m_GMask) << this->m_LightmapPixelWriter.m_GShift;
          v100 = this->m_LightmapPixelWriter.m_BShift;
          v101 = HIDWORD(v99) | HIDWORD(v98);
          v102 = v99 | v98;
          v103 = (unsigned __int8)v242 & (unsigned __int64)this->m_LightmapPixelWriter.m_BMask;
          if ( v100 <= 0 )
            v104 = v103 >> -(char)v100;
          else
            v104 = v103 << v100;
          v209 = v104;
          v105 = (unsigned __int64)((unsigned __int8)v254 & this->m_LightmapPixelWriter.m_AMask) << this->m_LightmapPixelWriter.m_AShift;
          v106 = v209 | v105 | v102;
          v107 = HIDWORD(v209) | HIDWORD(v105) | v101;
          if ( this->m_LightmapPixelWriter.m_Size == 6 )
          {
            *(_DWORD *)this->m_LightmapPixelWriter.m_pBits = v106;
            *((_WORD *)this->m_LightmapPixelWriter.m_pBits + 2) = v107;
          }
          else if ( this->m_LightmapPixelWriter.m_Size == 8 )
          {
            *(_DWORD *)this->m_LightmapPixelWriter.m_pBits = v106;
            *((_DWORD *)this->m_LightmapPixelWriter.m_pBits + 1) = v107;
          }
        }
        else
        {
          v93 = this->m_LightmapPixelWriter.m_BShift;
          v94 = ((LOBYTE(v237) & this->m_LightmapPixelWriter.m_GMask) << LOBYTE(this->m_LightmapPixelWriter.m_GShift))
              | (v92 << LOBYTE(this->m_LightmapPixelWriter.m_RShift));
          v95 = (unsigned __int8)v242 & this->m_LightmapPixelWriter.m_BMask;
          if ( v93 <= 0 )
            v96 = v95 >> -(char)v93;
          else
            v96 = v95 << v93;
          v97 = v96
              | (((unsigned __int8)v254 & this->m_LightmapPixelWriter.m_AMask) << LOBYTE(this->m_LightmapPixelWriter.m_AShift))
              | v94;
          switch ( v91 )
          {
            case 1u:
              *this->m_LightmapPixelWriter.m_pBits = v97;
              break;
            case 2u:
              *(_WORD *)this->m_LightmapPixelWriter.m_pBits = v97;
              break;
            case 3u:
              *(_WORD *)this->m_LightmapPixelWriter.m_pBits = v97;
              this->m_LightmapPixelWriter.m_pBits[2] = BYTE2(v97);
              break;
            case 4u:
              *(_DWORD *)this->m_LightmapPixelWriter.m_pBits = v97;
              break;
          }
        }
      }
      this->m_LightmapPixelWriter.m_pBits += nLightmap0WriterSizeBytes;
      v108 = this->m_LightmapPixelWriter.m_Size;
      if ( v108 != 0 )
      {
        v109 = (unsigned __int8)v236 & this->m_LightmapPixelWriter.m_RMask;
        if ( v108 >= 5u )
        {
          v115 = (unsigned __int64)v109 << this->m_LightmapPixelWriter.m_RShift;
          v116 = (unsigned __int64)((unsigned __int8)v235 & this->m_LightmapPixelWriter.m_GMask) << this->m_LightmapPixelWriter.m_GShift;
          v117 = this->m_LightmapPixelWriter.m_BShift;
          v118 = HIDWORD(v116) | HIDWORD(v115);
          v119 = v116 | v115;
          v120 = (unsigned __int8)v233 & (unsigned __int64)this->m_LightmapPixelWriter.m_BMask;
          if ( v117 <= 0 )
            v121 = v120 >> -(char)v117;
          else
            v121 = v120 << v117;
          v210 = v121;
          v122 = (unsigned __int64)((unsigned __int8)v254 & this->m_LightmapPixelWriter.m_AMask) << this->m_LightmapPixelWriter.m_AShift;
          v123 = v210 | v122 | v119;
          v124 = HIDWORD(v210) | HIDWORD(v122) | v118;
          if ( this->m_LightmapPixelWriter.m_Size == 6 )
          {
            *(_DWORD *)this->m_LightmapPixelWriter.m_pBits = v123;
            *((_WORD *)this->m_LightmapPixelWriter.m_pBits + 2) = v124;
          }
          else if ( this->m_LightmapPixelWriter.m_Size == 8 )
          {
            *(_DWORD *)this->m_LightmapPixelWriter.m_pBits = v123;
            *((_DWORD *)this->m_LightmapPixelWriter.m_pBits + 1) = v124;
          }
        }
        else
        {
          v110 = this->m_LightmapPixelWriter.m_BShift;
          v111 = (((unsigned __int8)v235 & this->m_LightmapPixelWriter.m_GMask) << LOBYTE(this->m_LightmapPixelWriter.m_GShift))
               | (v109 << LOBYTE(this->m_LightmapPixelWriter.m_RShift));
          v112 = (unsigned __int8)v233 & this->m_LightmapPixelWriter.m_BMask;
          if ( v110 <= 0 )
            v113 = v112 >> -(char)v110;
          else
            v113 = v112 << v110;
          v114 = v113
               | (((unsigned __int8)v254 & this->m_LightmapPixelWriter.m_AMask) << LOBYTE(this->m_LightmapPixelWriter.m_AShift))
               | v111;
          switch ( v108 )
          {
            case 1u:
              *this->m_LightmapPixelWriter.m_pBits = v114;
              break;
            case 2u:
              *(_WORD *)this->m_LightmapPixelWriter.m_pBits = v114;
              break;
            case 3u:
              *(_WORD *)this->m_LightmapPixelWriter.m_pBits = v114;
              this->m_LightmapPixelWriter.m_pBits[2] = BYTE2(v114);
              break;
            case 4u:
              *(_DWORD *)this->m_LightmapPixelWriter.m_pBits = v114;
              break;
          }
        }
      }
      this->m_LightmapPixelWriter.m_pBits += nLightmap0WriterSizeBytes;
      v125 = this->m_LightmapPixelWriter.m_Size;
      if ( v125 != 0 )
      {
        v126 = (unsigned __int8)v243 & this->m_LightmapPixelWriter.m_RMask;
        if ( v125 >= 5u )
        {
          v132 = (unsigned __int64)v126 << this->m_LightmapPixelWriter.m_RShift;
          v133 = (unsigned __int64)((unsigned __int8)v230 & this->m_LightmapPixelWriter.m_GMask) << this->m_LightmapPixelWriter.m_GShift;
          v134 = this->m_LightmapPixelWriter.m_BShift;
          v135 = HIDWORD(v133) | HIDWORD(v132);
          v136 = v133 | v132;
          v137 = LOBYTE(v251) & (unsigned __int64)this->m_LightmapPixelWriter.m_BMask;
          if ( v134 <= 0 )
            v138 = v137 >> -(char)v134;
          else
            v138 = v137 << v134;
          v211 = v138;
          v139 = (unsigned __int64)((unsigned __int8)v254 & this->m_LightmapPixelWriter.m_AMask) << this->m_LightmapPixelWriter.m_AShift;
          v140 = v211 | v139 | v136;
          v141 = HIDWORD(v211) | HIDWORD(v139) | v135;
          if ( this->m_LightmapPixelWriter.m_Size == 6 )
          {
            *(_DWORD *)this->m_LightmapPixelWriter.m_pBits = v140;
            *((_WORD *)this->m_LightmapPixelWriter.m_pBits + 2) = v141;
          }
          else if ( this->m_LightmapPixelWriter.m_Size == 8 )
          {
            *(_DWORD *)this->m_LightmapPixelWriter.m_pBits = v140;
            *((_DWORD *)this->m_LightmapPixelWriter.m_pBits + 1) = v141;
          }
        }
        else
        {
          v127 = this->m_LightmapPixelWriter.m_BShift;
          v128 = (((unsigned __int8)v230 & this->m_LightmapPixelWriter.m_GMask) << LOBYTE(this->m_LightmapPixelWriter.m_GShift))
               | (v126 << LOBYTE(this->m_LightmapPixelWriter.m_RShift));
          v129 = LOBYTE(v251) & this->m_LightmapPixelWriter.m_BMask;
          if ( v127 <= 0 )
            v130 = v129 >> -(char)v127;
          else
            v130 = v129 << v127;
          v131 = v130
               | (((unsigned __int8)v254 & this->m_LightmapPixelWriter.m_AMask) << LOBYTE(this->m_LightmapPixelWriter.m_AShift))
               | v128;
          switch ( v125 )
          {
            case 1u:
              *this->m_LightmapPixelWriter.m_pBits = v131;
              break;
            case 2u:
              *(_WORD *)this->m_LightmapPixelWriter.m_pBits = v131;
              break;
            case 3u:
              *(_WORD *)this->m_LightmapPixelWriter.m_pBits = v131;
              this->m_LightmapPixelWriter.m_pBits[2] = BYTE2(v131);
              break;
            case 4u:
              *(_DWORD *)this->m_LightmapPixelWriter.m_pBits = v131;
              break;
          }
        }
      }
      v142 = s;
      this->m_LightmapPixelWriter.m_pBits += nRewindToNextPixel;
      srcTexelOffset += 4;
      s = v142 + 1;
      if ( v142 + 1 >= nLightmapSize0 )
        goto LABEL_207;
    }
    v255 = 1;
    v256 = 2;
    v257 = 0;
LABEL_55:
    if ( v41 >= v36 && v36 >= v31 )
    {
      v255 = 2;
      v256 = 0;
      v257 = 1;
    }
    goto LABEL_58;
  }
LABEL_208:
  if ( pfmOut != nullptr )
  {
    pfmOuta = nullptr;
    if ( pLightmapSize[1] > 0 )
    {
      while ( 1 )
      {
        v144 = 4 * nLightmapSize0 * (_DWORD)pfmOuta;
        v244 = v144;
        t = 0;
        if ( nLightmapSize0 > 0 )
          break;
LABEL_347:
        pfmOuta = (FloatBitMap_t *)((char *)pfmOuta + 1);
        if ( (int)pfmOuta >= pLightmapSize[1] )
          return;
      }
      v220 = &v264;
      v221 = &v261;
      v222 = &v258;
      while ( 1 )
      {
        *(float *)&nRewindToNextPixel = pFloatImage[v144] * 1024.0;
        s = (int)*(float *)&nRewindToNextPixel;
        v145 = s;
        if ( (unsigned int)s > 0xFFF )
          v145 = s < 0 ? 0 : 0xFFF;
        *(float *)&v248 = lineartovertex[v145];
        v227 = pFloatImage[v144 + 1] * 1024.0;
        v243 = (int)v227;
        v146 = v243;
        if ( (unsigned int)v243 > 0xFFF )
          v146 = v243 < 0 ? 0 : 0xFFF;
        *((float *)&v248 + 1) = lineartovertex[v146];
        v236 = (int)(float)(pFloatImage[v144 + 2] * 1024.0);
        v147 = v236;
        if ( (unsigned int)v236 > 0xFFF )
          v147 = v236 < 0 ? 0 : 0xFFF;
        v148 = lineartovertex[v147];
        v253 = pFloatImageBump1[v144 + 2];
        v149 = pFloatImageBump2[v144 + 2];
        v150 = pFloatImageBump2[v144];
        v151 = pFloatImageBump2[v144 + 1];
        v249 = v148;
        v252 = *(_QWORD *)&pFloatImageBump1[v144];
        v216 = pFloatImageBump3[v144];
        v219 = pFloatImageBump3[v144 + 1];
        v218 = v149;
        v215 = pFloatImageBump3[v144 + 2];
        v152 = (float)(v216 + (float)(v150 + *(float *)&v252)) * 0.33333334;
        *(float *)&v252 = v152;
        v153 = (float)(v219 + (float)(v151 + *((float *)&v252 + 1))) * 0.33333334;
        v154 = (float)(v215 + (float)(v149 + v253)) * 0.33333334;
        *((float *)&v252 + 1) = v153;
        v253 = v154;
        if ( v152 == 0.0 || HIDWORD(v252) == 0 || v253 == 0.0 )
        {
          v157 = 0.0;
          v155 = 0.0;
          v156 = 0.0;
          if ( v152 != 0.0 )
            v155 = *(float *)&v248 / v152;
          if ( v153 != 0.0 )
            v156 = *((float *)&v248 + 1) / v153;
          if ( v253 != 0.0 )
            v157 = v249 / v253;
        }
        else
        {
          v155 = *(float *)&v248 / v152;
          v156 = *((float *)&v248 + 1) / v153;
          v157 = v249 / v154;
        }
        v158 = pFloatImageBump1[v144];
        v159 = pFloatImageBump1[v144 + 1];
        v160 = pFloatImageBump1[v144 + 2];
        v261 = v150 * v155;
        v161 = v151 * v156;
        v263 = v218 * v157;
        v162 = v158 * v155;
        v163 = v216 * v155;
        v164 = v159 * v156;
        v165 = v219 * v156;
        v166 = v160 * v157;
        v167 = v215 * v157;
        v264 = v162;
        v265 = v164;
        v266 = v166;
        v262 = v161;
        v258 = v163;
        v259 = v165;
        v260 = v215 * v157;
        if ( v164 <= v166 )
          v168 = v166;
        else
          v168 = v164;
        if ( v162 <= v168 )
        {
          if ( v164 > v166 )
            v166 = v164;
        }
        else
        {
          v166 = v162;
        }
        if ( v161 <= v263 )
          v169 = v263;
        else
          v169 = v161;
        if ( v261 <= v169 )
        {
          if ( v161 <= v263 )
            v161 = v263;
        }
        else
        {
          v161 = v261;
        }
        if ( v165 <= v167 )
          v170 = v167;
        else
          v170 = v165;
        if ( v163 <= v170 )
        {
          if ( v165 <= v167 )
            v171 = v167;
          else
            v171 = v165;
        }
        else
        {
          v171 = v163;
        }
        if ( v166 < v161 || v161 < v171 )
        {
          v172 = 2;
        }
        else
        {
          v172 = 2;
          v255 = 0;
          v256 = 1;
          v257 = 2;
        }
        if ( v166 >= v171 && v171 >= v161 )
        {
          v255 = 0;
          v256 = 2;
          v257 = 1;
        }
        if ( v161 >= v166 && v166 >= v171 )
        {
          v255 = 1;
          v256 = 0;
          v257 = 2;
        }
        if ( v161 < v171 )
          goto LABEL_263;
        if ( v171 >= v166 )
          break;
LABEL_266:
        if ( v171 >= v161 && v161 >= v166 )
        {
          v255 = 2;
          v256 = 1;
          v257 = 0;
        }
        v173 = &v255;
        for ( j = 3; j != 0; --j )
        {
          v174 = (&v220)[*v173];
          v175 = v174[1];
          v176 = v174[2];
          if ( v175 <= v176 )
            v177 = v174[2];
          else
            v177 = v174[1];
          if ( *v174 <= v177 )
          {
            if ( v175 > v176 )
              v176 = v174[1];
          }
          else
          {
            v176 = *v174;
          }
          if ( v176 > 1.0 )
          {
            v178 = (float)(v176 - 1.0) / v176;
            v179 = v174[1] * v178;
            v180 = v174[2] * v178;
            v181 = *v174 * v178;
            *v174 = *v174 - v181;
            v174[1] = v174[1] - v179;
            v174[2] = v174[2] - v180;
            v182 = v179 * 0.5;
            v183 = v180 * 0.5;
            v184 = v181 * 0.5;
            v185 = (&v220)[*(&v255 + (v172 - 1) % 3)];
            *v185 = *v185 + v184;
            v185[1] = v182 + v185[1];
            v185[2] = v183 + v185[2];
            v144 = v244;
            v186 = (&v220)[*(&v255 + v172 % 3)];
            v187 = v182 + v186[1];
            v188 = v183 + v186[2];
            *v186 = *v186 + v184;
            v186[1] = v187;
            v186[2] = v188;
          }
          ++v173;
          ++v172;
        }
        v189 = v265;
        v190 = v266;
        if ( v265 <= v266 )
          v191 = v266;
        else
          v191 = v265;
        v192 = v264;
        if ( v264 <= v191 )
        {
          if ( v265 <= v266 )
            v193 = v266;
          else
            v193 = v265;
        }
        else
        {
          v193 = v264;
        }
        if ( v193 > 1.0 )
        {
          v192 = (float)(1.0 / v193) * v264;
          v189 = v265 * (float)(1.0 / v193);
          v190 = v266 * (float)(1.0 / v193);
          v264 = v192;
          v265 = v189;
          v266 = v190;
        }
        if ( v192 < 0.0 )
          v264 = 0.0;
        if ( v189 < 0.0 )
          v265 = 0.0;
        if ( v190 < 0.0 )
          v266 = 0.0;
        v194 = v262;
        v195 = v263;
        if ( v262 <= v263 )
          v196 = v263;
        else
          v196 = v262;
        v197 = v261;
        if ( v261 <= v196 )
        {
          if ( v262 <= v263 )
            v198 = v263;
          else
            v198 = v262;
        }
        else
        {
          v198 = v261;
        }
        if ( v198 > 1.0 )
        {
          v197 = (float)(1.0 / v198) * v261;
          v194 = v262 * (float)(1.0 / v198);
          v195 = v263 * (float)(1.0 / v198);
          v261 = v197;
          v262 = v194;
          v263 = v195;
        }
        if ( v197 < 0.0 )
          v261 = 0.0;
        if ( v194 < 0.0 )
        {
          v194 = 0.0;
          v262 = 0.0;
        }
        if ( v195 < 0.0 )
        {
          v195 = 0.0;
          v263 = 0.0;
        }
        v199 = v259;
        v200 = v260;
        if ( v259 <= v260 )
          v201 = v260;
        else
          v201 = v259;
        v202 = v258;
        if ( v258 <= v201 )
        {
          if ( v259 <= v260 )
            v203 = v260;
          else
            v203 = v259;
        }
        else
        {
          v203 = v258;
        }
        if ( v203 > 1.0 )
        {
          v202 = v258 * (float)(1.0 / v203);
          v199 = v259 * (float)(1.0 / v203);
          v200 = v260 * (float)(1.0 / v203);
          v258 = v202;
          v259 = v199;
          v260 = v200;
        }
        if ( v202 < 0.0 )
        {
          v202 = 0.0;
          v258 = 0.0;
        }
        if ( v199 < 0.0 )
        {
          v199 = 0.0;
          v259 = 0.0;
        }
        if ( v200 < 0.0 )
        {
          v200 = 0.0;
          v260 = 0.0;
        }
        if ( v264 < 0.0 )
          v264 = 0.0;
        if ( v265 < 0.0 )
          v265 = 0.0;
        if ( v266 < 0.0 )
          v266 = 0.0;
        if ( v261 < 0.0 )
          v261 = 0.0;
        if ( v194 < 0.0 )
          v262 = 0.0;
        if ( v195 < 0.0 )
          v263 = 0.0;
        if ( v202 < 0.0 )
          v258 = 0.0;
        if ( v199 < 0.0 )
          v259 = 0.0;
        if ( v200 < 0.0 )
          v260 = 0.0;
        v238 = (int)(float)(*(float *)&v248 * 255.0);
        i = (int)(float)(*((float *)&v248 + 1) * 255.0);
        v240 = (int)(float)(v249 * 255.0);
        LODWORD(v224) = (int)(float)(v264 * 255.0);
        v223 = v265 * 255.0;
        LODWORD(v226) = (int)(float)(v265 * 255.0);
        v228 = v261 * 255.0;
        v230 = (int)(float)(v263 * 255.0);
        *(float *)&nLightmap0WriterSizeBytes = v258 * 255.0;
        v235 = (int)(float)(v258 * 255.0);
        v237 = v259 * 255.0;
        v239 = (int)(float)(v259 * 255.0);
        *(float *)&srcTexelOffset = v260 * 255.0;
        v246 = (int)(float)(v260 * 255.0);
        v251 = pFloatImage[v144 + 3] * 255.0;
        v231 = (int)v251;
        v204 = (float)(unsigned __int8)i;
        v205 = (float)(unsigned __int8)v231;
        v206 = (float)(unsigned __int8)v240;
        v207 = (char *)pfmOuta + pOffsetIntoLightmapPage[1];
        v208 = t + *pOffsetIntoLightmapPage;
        *(float *)&pfmOut->m_pAttributePtrs[0][(_DWORD)v207 * pfmOut->m_nRowStrideInBytes[0]
                                             + v208 * pfmOut->m_nStrideInBytes[0]] = (float)(unsigned __int8)v238;
        *(float *)&pfmOut->m_pAttributePtrs[1][(_DWORD)v207 * pfmOut->m_nRowStrideInBytes[1]
                                             + v208 * pfmOut->m_nStrideInBytes[1]] = v204;
        *(float *)&pfmOut->m_pAttributePtrs[2][(_DWORD)v207 * pfmOut->m_nRowStrideInBytes[2]
                                             + v208 * pfmOut->m_nStrideInBytes[2]] = v206;
        *(float *)&pfmOut->m_pAttributePtrs[3][(_DWORD)v207 * pfmOut->m_nRowStrideInBytes[3]
                                             + v208 * pfmOut->m_nStrideInBytes[3]] = v205;
        v144 += 4;
        ++t;
        v244 = v144;
        if ( t >= nLightmapSize0 )
          goto LABEL_347;
      }
      v255 = 1;
      v256 = 2;
      v257 = 0;
LABEL_263:
      if ( v171 >= v166 && v166 >= v161 )
      {
        v255 = 2;
        v256 = 0;
        v257 = 1;
      }
      goto LABEL_266;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037450
// Name: private: void CMatLightmaps::LightmapBitsToPixelWriter_LDR(float __near *,int __near * const,int __near * const,class FloatBitMap_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatLightmaps::LightmapBitsToPixelWriter_LDR(
        CMatLightmaps *this,
        float *pFloatImage,
        int *pLightmapSize,
        int *pOffsetIntoLightmapPage,
        FloatBitMap_t *pfmOut)
{
  int v6; // eax
  unsigned __int8 *v8; // edx
  int v9; // edx
  int j; // eax
  int v11; // ecx
  float v12; // xmm2_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm3_4
  float v16; // xmm4_4
  unsigned __int8 m_Size; // al
  bool v18; // cf
  unsigned int m_RMask; // eax
  __int16 m_BShift; // cx
  unsigned int v21; // eax
  unsigned int v22; // edx
  unsigned int v23; // edx
  unsigned int v24; // eax
  unsigned __int64 v25; // rax
  unsigned __int64 v26; // rcx
  __int64 v27; // rax
  __int64 v28; // rax
  unsigned __int64 v29; // rax
  int v30; // eax
  int v31; // ebx
  float v32; // xmm3_4
  int v33; // eax
  int v34; // ecx
  float v35; // [esp+0h] [ebp-5Ch]
  float v36; // [esp+4h] [ebp-58h] BYREF
  float v37; // [esp+8h] [ebp-54h]
  float v38; // [esp+Ch] [ebp-50h]
  int v39; // [esp+10h] [ebp-4Ch]
  int v40; // [esp+18h] [ebp-44h]
  __int64 v41; // [esp+20h] [ebp-3Ch]
  float v42; // [esp+2Ch] [ebp-30h]
  float v43; // [esp+30h] [ebp-2Ch]
  float v44; // [esp+34h] [ebp-28h]
  float v45; // [esp+38h] [ebp-24h]
  float v46; // [esp+3Ch] [ebp-20h]
  int v47; // [esp+40h] [ebp-1Ch]
  int t; // [esp+44h] [ebp-18h]
  int i; // [esp+48h] [ebp-14h]
  int s; // [esp+4Ch] [ebp-10h]
  int v51; // [esp+50h] [ebp-Ch]
  float *pSrc; // [esp+54h] [ebp-8h]
  int v53; // [esp+58h] [ebp-4h]
  float *pFloatImagea; // [esp+64h] [ebp+8h]
  FloatBitMap_t *pfmOuta; // [esp+70h] [ebp+14h]

  pSrc = pFloatImage;
  v6 = 0;
  for ( t = 0; v6 < pLightmapSize[1]; t = v6 )
  {
    v8 = &this->m_LightmapPixelWriter.m_pBase[*pOffsetIntoLightmapPage * this->m_LightmapPixelWriter.m_Size
                                            + this->m_LightmapPixelWriter.m_BytesPerRow
                                            * (v6 + pOffsetIntoLightmapPage[1])];
    s = 0;
    this->m_LightmapPixelWriter.m_pBits = v8;
    if ( *pLightmapSize > 0 )
    {
      v9 = (char *)pSrc - (char *)&v36;
      for ( i = (char *)pSrc - (char *)&v36; ; v9 = i )
      {
        for ( j = 0; j < 3; *(&v35 + j) = g_LinearToVertex[v11] )
        {
          v46 = *(float *)((char *)&v36 + 4 * j + v9) * 1024.0;
          v47 = (int)v46;
          v11 = v47;
          if ( v47 >= 0 )
          {
            if ( v47 > 4091 )
              v11 = 4091;
          }
          else
          {
            v11 = 0;
          }
          ++j;
        }
        v12 = v37;
        v13 = v38;
        if ( v37 <= v38 )
          v14 = v38;
        else
          v14 = v37;
        v15 = v36;
        if ( v36 <= v14 )
        {
          if ( v37 <= v38 )
            v16 = v38;
          else
            v16 = v37;
        }
        else
        {
          v16 = v36;
        }
        if ( v16 > 1.0 )
        {
          v15 = v36 * (float)(1.0 / v16);
          v12 = v37 * (float)(1.0 / v16);
          v13 = v38 * (float)(1.0 / v16);
          v36 = v15;
          v37 = v12;
          v38 = v13;
        }
        if ( v15 < 0.0 )
        {
          v15 = 0.0;
          v36 = 0.0;
        }
        if ( v12 < 0.0 )
        {
          v12 = 0.0;
          v37 = 0.0;
        }
        if ( v13 < 0.0 )
        {
          v13 = 0.0;
          v38 = 0.0;
        }
        v45 = v15 * 255.0;
        v51 = (int)(float)(v15 * 255.0);
        v44 = v12 * 255.0;
        pfmOuta = (FloatBitMap_t *)(int)(float)(v12 * 255.0);
        v43 = v13 * 255.0;
        pFloatImagea = (float *)(int)(float)(v13 * 255.0);
        v42 = pSrc[3] * 255.0;
        v53 = (int)v42;
        m_Size = this->m_LightmapPixelWriter.m_Size;
        if ( m_Size != 0 )
        {
          v18 = m_Size < 5u;
          m_RMask = this->m_LightmapPixelWriter.m_RMask;
          if ( v18 )
          {
            m_BShift = this->m_LightmapPixelWriter.m_BShift;
            v21 = (((unsigned __int8)pfmOuta & this->m_LightmapPixelWriter.m_GMask) << LOBYTE(this->m_LightmapPixelWriter.m_GShift))
                | ((unsigned __int8)(v51 & m_RMask) << LOBYTE(this->m_LightmapPixelWriter.m_RShift));
            v22 = (unsigned __int8)pFloatImagea & this->m_LightmapPixelWriter.m_BMask;
            if ( m_BShift <= 0 )
              v23 = v22 >> -(char)m_BShift;
            else
              v23 = v22 << m_BShift;
            v24 = v23
                | (((unsigned __int8)v53 & this->m_LightmapPixelWriter.m_AMask) << LOBYTE(this->m_LightmapPixelWriter.m_AShift))
                | v21;
            switch ( this->m_LightmapPixelWriter.m_Size )
            {
              case 1u:
                *this->m_LightmapPixelWriter.m_pBits = v24;
                break;
              case 2u:
                *(_WORD *)this->m_LightmapPixelWriter.m_pBits = v24;
                break;
              case 3u:
                *(_WORD *)this->m_LightmapPixelWriter.m_pBits = v24;
                this->m_LightmapPixelWriter.m_pBits[2] = BYTE2(v24);
                break;
              case 4u:
                *(_DWORD *)this->m_LightmapPixelWriter.m_pBits = v24;
                break;
              default:
                break;
            }
          }
          else
          {
            v25 = (unsigned __int64)(unsigned __int8)(v51 & m_RMask) << this->m_LightmapPixelWriter.m_RShift;
            v40 = v25;
            v26 = ((unsigned __int64)((unsigned __int8)pfmOuta & this->m_LightmapPixelWriter.m_GMask) << this->m_LightmapPixelWriter.m_GShift)
                | v25;
            LODWORD(v25) = this->m_LightmapPixelWriter.m_BMask;
            v39 = v26;
            LOWORD(v26) = this->m_LightmapPixelWriter.m_BShift;
            v27 = (unsigned __int8)pFloatImagea & v25;
            if ( (__int16)v26 <= 0 )
              v28 = v27 >> -(char)v26;
            else
              v28 = v27 << v26;
            v41 = v28;
            v29 = (unsigned __int64)((unsigned __int8)v53 & this->m_LightmapPixelWriter.m_AMask) << this->m_LightmapPixelWriter.m_AShift;
            v30 = v41 | v29 | v39;
            v31 = HIDWORD(v41) | HIDWORD(v29) | HIDWORD(v26);
            if ( this->m_LightmapPixelWriter.m_Size == 6 )
            {
              *(_DWORD *)this->m_LightmapPixelWriter.m_pBits = v30;
              *((_WORD *)this->m_LightmapPixelWriter.m_pBits + 2) = v31;
            }
            else if ( this->m_LightmapPixelWriter.m_Size == 8 )
            {
              *(_DWORD *)this->m_LightmapPixelWriter.m_pBits = v30;
              *((_DWORD *)this->m_LightmapPixelWriter.m_pBits + 1) = v31;
            }
          }
        }
        this->m_LightmapPixelWriter.m_pBits += this->m_LightmapPixelWriter.m_Size;
        if ( pfmOut != nullptr )
        {
          v32 = (float)(unsigned __int8)v53;
          v33 = t + pOffsetIntoLightmapPage[1];
          v34 = s + *pOffsetIntoLightmapPage;
          *(float *)&pfmOut->m_pAttributePtrs[0][v34 * pfmOut->m_nStrideInBytes[0]
                                               + v33 * pfmOut->m_nRowStrideInBytes[0]] = (float)(unsigned __int8)v51;
          *(float *)&pfmOut->m_pAttributePtrs[1][v34 * pfmOut->m_nStrideInBytes[1]
                                               + v33 * pfmOut->m_nRowStrideInBytes[1]] = (float)(unsigned __int8)pfmOuta;
          *(float *)&pfmOut->m_pAttributePtrs[2][v34 * pfmOut->m_nStrideInBytes[2]
                                               + v33 * pfmOut->m_nRowStrideInBytes[2]] = (float)(unsigned __int8)pFloatImagea;
          *(float *)&pfmOut->m_pAttributePtrs[3][v34 * pfmOut->m_nStrideInBytes[3]
                                               + v33 * pfmOut->m_nRowStrideInBytes[3]] = v32;
        }
        pSrc += 4;
        i += 16;
        if ( ++s >= *pLightmapSize )
          break;
      }
      v6 = t;
    }
    ++v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037850
// Name: public: void CMatLightmaps::CleanupLightmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatLightmaps::CleanupLightmaps(CMatLightmaps *this)
{
  int i; // edi
  FloatBitMap_t **m_pLightmapDataPtrArray; // eax
  int j; // edi
  FloatBitMap_t **v5; // eax
  FloatBitMap_t *v6; // ebx
  int k; // edi
  char szPFMFileName[260]; // [esp+Ch] [ebp-104h] BYREF

  CMatPaintmaps::CleanupPaintmaps(this: (CMatPaintmaps *)(this + 1));
  if ( mat_lightmap_pfms.m_pParent != nullptr && mat_lightmap_pfms.m_pParent->m_Value.m_nValue != 0 )
  {
    for ( i = 0; i < this->m_NumLightmapPages; ++i )
    {
      m_pLightmapDataPtrArray = this->m_pLightmapDataPtrArray;
      if ( m_pLightmapDataPtrArray != nullptr && m_pLightmapDataPtrArray[i] != nullptr )
      {
        sprintf(string: szPFMFileName, format: "Lightmap-Page-%d.pfm", i);
        FloatBitMap_t::WritePFM(this: this->m_pLightmapDataPtrArray[i], fname: szPFMFileName);
      }
    }
  }
  if ( this->m_pLightmapDataPtrArray != nullptr )
  {
    for ( j = 0; j < this->m_NumLightmapPages; ++j )
    {
      v5 = this->m_pLightmapDataPtrArray;
      v6 = v5[j];
      if ( v6 != nullptr )
      {
        CSOAContainer::~CSOAContainer(this: v5[j]);
        free(pMem: v6);
      }
    }
    free(pMem: this->m_pLightmapDataPtrArray);
    this->m_pLightmapDataPtrArray = nullptr;
  }
  if ( this->m_pLightmapPages != nullptr )
  {
    for ( k = 0; k < this->m_NumLightmapPages; ++k )
      g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: this->m_LightmapPageTextureHandles.m_Memory.m_pMemory[k]);
    free(pMem: this->m_pLightmapPages);
    this->m_pLightmapPages = nullptr;
  }
  this->m_NumLightmapPages = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10037960
// Name: public: void CMatLightmaps::ReleaseLightmapPages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatLightmaps::ReleaseLightmapPages(CMatLightmaps *this)
{
  int i; // edi

  if ( this->m_eLightmapsState != STATE_DEFAULT )
  {
    _Warning(
      a1: "ReleaseLightmapPages is expected in STATE_DEFAULT, current state = %d, discarded.\n",
      this->m_eLightmapsState);
  }
  else
  {
    for ( i = 0; i < this->m_NumLightmapPages; ++i )
      g_pShaderAPI->DeleteTexture(this: g_pShaderAPI, a2: this->m_LightmapPageTextureHandles.m_Memory.m_pMemory[i]);
    CMatPaintmaps::ReleasePaintmaps(this: (CMatPaintmaps *)(this + 1));
    this->m_eLightmapsState = STATE_RELEASED;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100379D0
// Name: private: void CMatLightmaps::InitLightmapBits(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMatLightmaps::InitLightmapBits(
        CMatLightmaps *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        unsigned int lightmap)
{
  int m_Height; // ecx
  int v7; // ebx
  int v8; // esi
  int v9; // eax
  unsigned __int8 *v10; // edi
  unsigned int v11; // edx
  unsigned int v12; // edx
  int v13; // eax
  unsigned __int64 v14; // kr08_8
  unsigned __int64 v15; // rax
  int v16; // ebx
  int v17; // esi
  __int64 v18; // rax
  __int64 v19; // rax
  unsigned __int64 v20; // rax
  int v21; // ebx
  int v22; // esi
  bool v23; // zf
  unsigned __int8 *m_pBits; // edi
  int v25; // eax
  int v26; // ebx
  int v27; // esi
  CPixelWriter writer; // [esp+0h] [ebp-38h] BYREF
  __int64 v29; // [esp+24h] [ebp-14h]
  int j; // [esp+2Ch] [ebp-Ch]
  int v31; // [esp+30h] [ebp-8h]
  int height; // [esp+34h] [ebp-4h]
  int width; // [esp+40h] [ebp+8h]

  if ( lightmap == -3 )
  {
    m_Height = 1;
    width = 1;
LABEL_9:
    height = m_Height;
    goto LABEL_10;
  }
  if ( lightmap < 0xFFFFFFFE )
    width = this->m_pLightmapPages[lightmap].m_Width;
  else
    width = 1;
  if ( lightmap < 0xFFFFFFFE )
  {
    m_Height = this->m_pLightmapPages[lightmap].m_Height;
    goto LABEL_9;
  }
  height = 1;
LABEL_10:
  ((void (__thiscall *)(IShaderAPI *, int, int, int))g_pShaderAPI->ModifyTexture)(
    a1: g_pShaderAPI,
    a2: this->m_LightmapPageTextureHandles.m_Memory.m_pMemory[lightmap],
    a3,
    a4: a2);
  v7 = height;
  v8 = width;
  if ( !g_pShaderAPI->TexLock(this: g_pShaderAPI, a2: 0, a3: 0, a4: 0, a5: 0, a6: width, a7: height, a8: &writer) )
    return;
  v9 = 0;
  if ( (writer.m_nFlags & 1) == 0 )
  {
    v31 = 0;
    if ( v7 > 0 )
    {
      do
      {
        m_pBits = &writer.m_pBase[v9 * writer.m_BytesPerRow];
        writer.m_pBits = m_pBits;
        if ( v8 > 0 )
        {
          j = v8;
          do
          {
            if ( writer.m_Size != 0 )
            {
              v25 = LOBYTE(writer.m_AMask) << SLOBYTE(writer.m_AShift);
              switch ( writer.m_Size )
              {
                case 1u:
                  *m_pBits = v25;
                  goto LABEL_50;
                case 2u:
                  *(_WORD *)m_pBits = v25;
                  goto LABEL_50;
                case 3u:
                  *(_WORD *)m_pBits = v25;
                  writer.m_pBits[2] = BYTE2(v25);
                  goto LABEL_50;
                case 4u:
                  *(_DWORD *)m_pBits = v25;
                  goto LABEL_50;
                default:
                  v29 = 0;
                  v27 = (unsigned __int64)LOBYTE(writer.m_AMask) << SLOBYTE(writer.m_AShift) >> 32;
                  v26 = (unsigned __int64)LOBYTE(writer.m_AMask) << SLOBYTE(writer.m_AShift);
                  if ( writer.m_Size == 6 )
                  {
                    *(_DWORD *)m_pBits = v26;
                    *((_WORD *)writer.m_pBits + 2) = v27;
                  }
                  else
                  {
                    if ( writer.m_Size != 8 )
                      break;
                    *(_DWORD *)m_pBits = v26;
                    *((_DWORD *)writer.m_pBits + 1) = v27;
                  }
LABEL_50:
                  m_pBits = writer.m_pBits;
                  break;
              }
            }
            m_pBits += writer.m_Size;
            v23 = j-- == 1;
            writer.m_pBits = m_pBits;
          }
          while ( !v23 );
          v9 = v31;
          v8 = width;
          v7 = height;
        }
        v31 = ++v9;
      }
      while ( v9 < v7 );
    }
    goto LABEL_54;
  }
  j = 0;
  if ( v7 <= 0 )
    goto LABEL_54;
  do
  {
    v10 = &writer.m_pBase[v9 * writer.m_BytesPerRow];
    writer.m_pBits = v10;
    if ( v8 <= 0 )
      goto LABEL_35;
    v31 = v8;
    do
    {
      if ( writer.m_Size == 0 )
        goto LABEL_33;
      if ( writer.m_Size >= 5u )
      {
        v14 = (unsigned __int64)(writer.m_GMask & 1) << SLOBYTE(writer.m_GShift);
        v15 = (unsigned __int64)(writer.m_RMask & 1) << SLOBYTE(writer.m_RShift);
        v16 = v15 | v14;
        v17 = HIDWORD(v15) | HIDWORD(v14);
        v18 = writer.m_BMask & 1;
        if ( writer.m_BShift <= 0 )
          v19 = v18 >> -LOBYTE(writer.m_BShift);
        else
          v19 = v18 << SLOBYTE(writer.m_BShift);
        v29 = v19;
        v20 = (unsigned __int64)LOBYTE(writer.m_AMask) << SLOBYTE(writer.m_AShift);
        v21 = v29 | v20 | v16;
        v22 = HIDWORD(v29) | HIDWORD(v20) | v17;
        if ( writer.m_Size == 6 )
        {
          *(_DWORD *)v10 = v21;
          *((_WORD *)writer.m_pBits + 2) = v22;
        }
        else
        {
          if ( writer.m_Size != 8 )
            goto LABEL_33;
          *(_DWORD *)v10 = v21;
          *((_DWORD *)writer.m_pBits + 1) = v22;
        }
      }
      else
      {
        v11 = writer.m_BMask & 1;
        if ( writer.m_BShift <= 0 )
          v12 = v11 >> -LOBYTE(writer.m_BShift);
        else
          v12 = v11 << SLOBYTE(writer.m_BShift);
        v13 = v12
            | (LOBYTE(writer.m_AMask) << SLOBYTE(writer.m_AShift))
            | ((writer.m_RMask & 1) << SLOBYTE(writer.m_RShift))
            | ((writer.m_GMask & 1) << SLOBYTE(writer.m_GShift));
        switch ( writer.m_Size )
        {
          case 1u:
            *v10 = v13;
            break;
          case 2u:
            *(_WORD *)v10 = v13;
            break;
          case 3u:
            *(_WORD *)v10 = v13;
            writer.m_pBits[2] = BYTE2(v13);
            break;
          case 4u:
            *(_DWORD *)v10 = v13;
            break;
        }
      }
      v10 = writer.m_pBits;
LABEL_33:
      v10 += writer.m_Size;
      v23 = v31-- == 1;
      writer.m_pBits = v10;
    }
    while ( !v23 );
    v8 = width;
    v9 = j;
    v7 = height;
LABEL_35:
    j = ++v9;
  }
  while ( v9 < v7 );
LABEL_54:
  g_pShaderAPI->TexUnlock(this: g_pShaderAPI);
}

//------------------------------------------------------------------------------
// Address: 0x10037D80
// Name: private: bool CMatLightmaps::LockLightmap(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatLightmaps::LockLightmap(CMatLightmaps *this, int lightmap)
{
  bool result; // al

  if ( (_S1_0 & 1) == 0 )
  {
    _S1_0 |= 1u;
    counter.m_pCounter = CVProfile::FindOrCreateCounter(
                           this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                           a2: "lightmap fullpage texlock",
                           a3: COUNTER_GROUP_DEFAULT);
    atexit(func: CMatLightmaps::LockLightmap_::_4_::_dynamic_atexit_destructor_for___counter__);
  }
  ++*counter.m_pCounter;
  if ( this->m_nLockedLightmap != -1 )
    g_pShaderAPI->TexUnlock(this: g_pShaderAPI);
  g_pShaderAPI->ModifyTexture(this: g_pShaderAPI, a2: this->m_LightmapPageTextureHandles.m_Memory.m_pMemory[lightmap]);
  result = g_pShaderAPI->TexLock(
             this: g_pShaderAPI,
             a2: 0,
             a3: 0,
             a4: 0,
             a5: 0,
             a6: this->m_pLightmapPages[lightmap].m_Width,
             a7: this->m_pLightmapPages[lightmap].m_Height,
             a8: &this->m_LightmapPixelWriter);
  if ( result )
  {
    this->m_nLockedLightmap = lightmap;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10037E80
// Name: public: void CMatLightmaps::EnableLightmapFiltering(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMatLightmaps::EnableLightmapFiltering(CMatLightmaps *this@<ecx>, int a2@<ebx>, bool enabled)
{
  int i; // esi
  void (__thiscall *TexMinFilter)(IShaderAPI *, ShaderTexFilterMode_t); // eax

  for ( i = 0; i < this->m_NumLightmapPages; ++i )
  {
    ((void (__thiscall *)(IShaderAPI *, int, int))g_pShaderAPI->ModifyTexture)(
      a1: g_pShaderAPI,
      a2: this->m_LightmapPageTextureHandles.m_Memory.m_pMemory[i],
      a3: a2);
    TexMinFilter = g_pShaderAPI->TexMinFilter;
    if ( enabled )
    {
      ((void (__stdcall *)(int))TexMinFilter)(a1: 1);
      a2 = 1;
    }
    else
    {
      ((void (__stdcall *)(_DWORD))TexMinFilter)(a1: 0);
      a2 = 0;
    }
    ((void (__thiscall *)(IShaderAPI *))g_pShaderAPI->TexMagFilter)(a1: g_pShaderAPI);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037EF0
// Name: public: void CMatLightmaps::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CMatLightmaps::Shutdown(CMatLightmaps *this)
{
  CMatLightmaps::CleanupLightmaps(this);
}

//------------------------------------------------------------------------------
// Address: 0x10037F00
// Name: private: void CMatLightmaps::BumpedLightmapBitsToPixelWriter_HDRF(float __near *,float __near *,float __near *,float __near *,int __near * const,int __near * const,class FloatBitMap_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatLightmaps::BumpedLightmapBitsToPixelWriter_HDRF(
        CMatLightmaps *this,
        float *pFloatImage,
        float *pFloatImageBump1,
        float *pFloatImageBump2,
        float *pFloatImageBump3,
        int *pLightmapSize,
        int *pOffsetIntoLightmapPage,
        FloatBitMap_t *pfmOut)
{
  int v8; // edx
  int m_Size; // eax
  float *v11; // ecx
  float *v12; // ebx
  float v13; // xmm1_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float input; // xmm0_4
  unsigned __int16 v17; // ax
  int m_RShift; // ecx
  unsigned __int8 *v19; // eax
  __int16 v20; // dx
  int m_GShift; // ecx
  int v22; // eax
  __int16 v23; // dx
  int m_BShift; // ecx
  int v25; // eax
  __int16 v26; // dx
  int m_AShift; // ecx
  unsigned int m_RMask; // edx
  char v29; // cl
  unsigned __int8 *v30; // eax
  int v31; // edx
  int v32; // ecx
  int v33; // eax
  unsigned int v34; // edx
  int v35; // ecx
  int v36; // eax
  unsigned int v37; // edx
  int v38; // ecx
  float *v39; // edx
  float v40; // xmm0_4
  float v41; // xmm1_4
  float v42; // xmm2_4
  float v43; // xmm3_4
  unsigned __int16 v44; // ax
  int v45; // ecx
  unsigned __int8 *v46; // eax
  __int16 v47; // dx
  int v48; // ecx
  int v49; // eax
  __int16 v50; // dx
  int v51; // ecx
  int v52; // eax
  __int16 v53; // dx
  int v54; // ecx
  unsigned int v55; // edx
  char v56; // cl
  unsigned __int8 *v57; // eax
  int v58; // edx
  int v59; // ecx
  int v60; // eax
  unsigned int v61; // edx
  int v62; // ecx
  int v63; // eax
  unsigned int v64; // edx
  int v65; // ecx
  float v66; // xmm1_4
  float v67; // xmm2_4
  float v68; // xmm3_4
  float v69; // xmm0_4
  unsigned __int16 v70; // ax
  __int16 v71; // dx
  int v72; // ecx
  int v73; // eax
  __int16 v74; // dx
  int v75; // ecx
  int v76; // eax
  __int16 v77; // dx
  int v78; // ecx
  int v79; // eax
  __int16 v80; // dx
  int v81; // ecx
  unsigned int v82; // edx
  char v83; // cl
  unsigned __int8 *v84; // eax
  int v85; // edx
  int v86; // ecx
  int v87; // eax
  unsigned int v88; // edx
  int v89; // ecx
  int v90; // eax
  unsigned int v91; // edx
  int v92; // ecx
  float *v93; // ecx
  float v94; // xmm0_4
  float v95; // xmm1_4
  float v96; // xmm2_4
  float v97; // xmm3_4
  unsigned __int16 v98; // ax
  __int16 v99; // dx
  int v100; // ecx
  int v101; // eax
  __int16 v102; // dx
  int v103; // ecx
  int v104; // eax
  __int16 v105; // dx
  int v106; // ecx
  int v107; // eax
  __int16 v108; // dx
  int v109; // ecx
  int v110; // eax
  char v111; // cl
  unsigned int v112; // edx
  unsigned int v113; // edx
  int v114; // ecx
  int v115; // eax
  unsigned int v116; // edx
  int v117; // ecx
  int v118; // eax
  unsigned int v119; // edx
  int v120; // ecx
  char *v121; // [esp+28h] [ebp-12Ch]
  char *v122; // [esp+2Ch] [ebp-128h]
  char *v123; // [esp+5Ch] [ebp-F8h]
  float v124; // [esp+68h] [ebp-ECh]
  int nRewindToNextPixel; // [esp+70h] [ebp-E4h]
  float v126; // [esp+98h] [ebp-BCh]
  unsigned __int8 v127[4]; // [esp+9Ch] [ebp-B8h] BYREF
  int v128; // [esp+A0h] [ebp-B4h]
  int v129; // [esp+A4h] [ebp-B0h]
  int v130; // [esp+A8h] [ebp-ACh]
  unsigned __int8 v131[4]; // [esp+ACh] [ebp-A8h] BYREF
  int v132; // [esp+B0h] [ebp-A4h]
  int v133; // [esp+B4h] [ebp-A0h]
  int v134; // [esp+B8h] [ebp-9Ch]
  unsigned __int8 v135[4]; // [esp+BCh] [ebp-98h] BYREF
  int v136; // [esp+C0h] [ebp-94h]
  int v137; // [esp+C4h] [ebp-90h]
  int v138; // [esp+C8h] [ebp-8Ch]
  unsigned __int8 v139[4]; // [esp+CCh] [ebp-88h] BYREF
  int v140; // [esp+D0h] [ebp-84h]
  int v141; // [esp+D4h] [ebp-80h]
  int v142; // [esp+D8h] [ebp-7Ch]
  int i; // [esp+DCh] [ebp-78h]
  int v144; // [esp+E0h] [ebp-74h]
  int nLightmapSize0; // [esp+E4h] [ebp-70h]
  unsigned __int16 v146; // [esp+E8h] [ebp-6Ch]
  unsigned __int16 v147; // [esp+EAh] [ebp-6Ah]
  unsigned __int16 v148; // [esp+ECh] [ebp-68h]
  int v149; // [esp+EEh] [ebp-66h]
  unsigned __int16 v150; // [esp+F4h] [ebp-60h]
  unsigned __int16 v151; // [esp+F6h] [ebp-5Eh]
  unsigned __int16 v152; // [esp+F8h] [ebp-5Ch]
  int v153; // [esp+FAh] [ebp-5Ah]
  unsigned __int16 v154; // [esp+100h] [ebp-54h]
  unsigned __int16 v155; // [esp+102h] [ebp-52h]
  unsigned __int16 v156; // [esp+104h] [ebp-50h]
  int v157; // [esp+106h] [ebp-4Eh]
  unsigned __int16 v158; // [esp+10Ch] [ebp-48h]
  unsigned __int16 v159; // [esp+10Eh] [ebp-46h]
  unsigned __int16 v160; // [esp+110h] [ebp-44h]
  unsigned __int16 v161; // [esp+112h] [ebp-42h]
  float *v162; // [esp+118h] [ebp-3Ch]
  int nLightmap0WriterSizeBytes; // [esp+11Ch] [ebp-38h]
  float *v164; // [esp+120h] [ebp-34h]
  float *v165; // [esp+124h] [ebp-30h]
  int t; // [esp+128h] [ebp-2Ch]
  unsigned __int8 v167[4]; // [esp+12Ch] [ebp-28h] BYREF
  int v168; // [esp+130h] [ebp-24h]
  unsigned __int8 v169[4]; // [esp+134h] [ebp-20h] BYREF
  int v170; // [esp+138h] [ebp-1Ch]
  unsigned __int8 v171[4]; // [esp+13Ch] [ebp-18h] BYREF
  int v172; // [esp+140h] [ebp-14h]
  unsigned __int8 src[4]; // [esp+144h] [ebp-10h] BYREF
  int v174; // [esp+148h] [ebp-Ch]
  float *v175; // [esp+14Ch] [ebp-8h]
  float *v176; // [esp+150h] [ebp-4h]

  v8 = *pLightmapSize;
  m_Size = this->m_LightmapPixelWriter.m_Size;
  nLightmap0WriterSizeBytes = *pLightmapSize * m_Size;
  nLightmapSize0 = v8;
  nRewindToNextPixel = m_Size - 3 * nLightmap0WriterSizeBytes;
  t = 0;
  if ( pLightmapSize[1] > 0 )
  {
    v11 = pFloatImage;
    v144 = 16 * v8;
    v162 = pFloatImageBump3;
    v165 = pFloatImage + 2;
    v164 = pFloatImageBump2 + 1;
    do
    {
      this->m_LightmapPixelWriter.m_pBits = &this->m_LightmapPixelWriter.m_pBase[*pOffsetIntoLightmapPage
                                                                               * this->m_LightmapPixelWriter.m_Size
                                                                               + this->m_LightmapPixelWriter.m_BytesPerRow
                                                                               * (t + pOffsetIntoLightmapPage[1])];
      if ( nLightmapSize0 > 0 )
      {
        v176 = v164;
        v175 = v162;
        v12 = v165;
        v121 = (char *)((char *)pFloatImageBump1 - (char *)v11);
        v122 = (char *)((char *)pFloatImageBump2 - (char *)v11);
        v123 = (char *)((char *)pFloatImageBump3 - (char *)v11);
        for ( i = nLightmapSize0; i != 0; --i )
        {
          v13 = *(v12 - 1);
          v14 = *v12;
          v15 = v12[1];
          input = *(v12 - 2);
          v124 = *v12;
          if ( (this->m_LightmapPixelWriter.m_nFlags & 2) != 0 )
          {
            v150 = float16::ConvertFloatTo16bitsNonDefault<0>(input);
            v151 = float16::ConvertFloatTo16bitsNonDefault<0>(input: v13);
            v152 = float16::ConvertFloatTo16bitsNonDefault<0>(input: v124);
            v17 = float16::ConvertFloatTo16bitsNonDefault<0>(input: v15);
            *(_DWORD *)src = 0;
            m_RShift = this->m_LightmapPixelWriter.m_RShift;
            LOWORD(v153) = v17;
            v174 = 0;
            v19 = &src[2 * (m_RShift >> 4)];
            v20 = (v150 & this->m_LightmapPixelWriter.m_RMask) << (m_RShift & 0xF);
            m_GShift = this->m_LightmapPixelWriter.m_GShift;
            *(_WORD *)v19 |= v20;
            v22 = m_GShift;
            v23 = (this->m_LightmapPixelWriter.m_GMask & v151) << (m_GShift & 0xF);
            m_BShift = this->m_LightmapPixelWriter.m_BShift;
            *(_WORD *)&src[2 * (v22 >> 4)] |= v23;
            v25 = m_BShift;
            v26 = (this->m_LightmapPixelWriter.m_BMask & v152) << (m_BShift & 0xF);
            m_AShift = this->m_LightmapPixelWriter.m_AShift;
            *(_WORD *)&src[2 * (v25 >> 4)] |= v26;
            *(_WORD *)&src[2 * (m_AShift >> 4)] |= (this->m_LightmapPixelWriter.m_AMask & (unsigned __int16)v153) << (m_AShift & 0xF);
            memcpy(dst: this->m_LightmapPixelWriter.m_pBits, src, count: this->m_LightmapPixelWriter.m_Size);
          }
          else
          {
            m_RMask = this->m_LightmapPixelWriter.m_RMask;
            v29 = this->m_LightmapPixelWriter.m_RShift & 0x1F;
            v30 = &v131[4 * (this->m_LightmapPixelWriter.m_RShift >> 5)];
            *(_DWORD *)v131 = 0;
            v132 = 0;
            v31 = (LODWORD(input) & m_RMask) << v29;
            v32 = this->m_LightmapPixelWriter.m_GShift;
            v133 = 0;
            v134 = 0;
            *(_DWORD *)v30 |= v31;
            v33 = v32;
            v34 = (this->m_LightmapPixelWriter.m_GMask & LODWORD(v13)) << (v32 & 0x1F);
            v35 = this->m_LightmapPixelWriter.m_BShift;
            *(_DWORD *)&v131[4 * (v33 >> 5)] |= v34;
            v36 = v35;
            v37 = (LODWORD(v14) & this->m_LightmapPixelWriter.m_BMask) << (v35 & 0x1F);
            v38 = this->m_LightmapPixelWriter.m_AShift;
            *(_DWORD *)&v131[4 * (v36 >> 5)] |= v37;
            *(_DWORD *)&v131[4 * (v38 >> 5)] |= (this->m_LightmapPixelWriter.m_AMask & LODWORD(v15)) << (v38 & 0x1F);
            memcpy(dst: this->m_LightmapPixelWriter.m_pBits, src: v131, count: this->m_LightmapPixelWriter.m_Size);
          }
          v39 = v175;
          this->m_LightmapPixelWriter.m_pBits += nLightmap0WriterSizeBytes;
          v40 = *(float *)((char *)v39 + (char *)pFloatImageBump1 - (char *)pFloatImageBump3);
          v41 = *(float *)((char *)v176 + (char *)pFloatImageBump1 - (char *)pFloatImageBump2);
          v42 = *(float *)((char *)v12 + (_DWORD)v121);
          v43 = v12[1];
          if ( (this->m_LightmapPixelWriter.m_nFlags & 2) != 0 )
          {
            v154 = float16::ConvertFloatTo16bitsNonDefault<0>(input: v40);
            v155 = float16::ConvertFloatTo16bitsNonDefault<0>(input: v41);
            v156 = float16::ConvertFloatTo16bitsNonDefault<0>(input: v42);
            v44 = float16::ConvertFloatTo16bitsNonDefault<0>(input: v43);
            v45 = this->m_LightmapPixelWriter.m_RShift;
            v172 = 0;
            LOWORD(v157) = v44;
            *(_DWORD *)v171 = 0;
            v46 = &v171[2 * (v45 >> 4)];
            v47 = (v154 & this->m_LightmapPixelWriter.m_RMask) << (v45 & 0xF);
            v48 = this->m_LightmapPixelWriter.m_GShift;
            *(_WORD *)v46 |= v47;
            v49 = v48;
            v50 = (this->m_LightmapPixelWriter.m_GMask & v155) << (v48 & 0xF);
            v51 = this->m_LightmapPixelWriter.m_BShift;
            *(_WORD *)&v171[2 * (v49 >> 4)] |= v50;
            v52 = v51;
            v53 = (this->m_LightmapPixelWriter.m_BMask & v156) << (v51 & 0xF);
            v54 = this->m_LightmapPixelWriter.m_AShift;
            *(_WORD *)&v171[2 * (v52 >> 4)] |= v53;
            *(_WORD *)&v171[2 * (v54 >> 4)] |= (this->m_LightmapPixelWriter.m_AMask & (unsigned __int16)v157) << (v54 & 0xF);
            memcpy(dst: this->m_LightmapPixelWriter.m_pBits, src: v171, count: this->m_LightmapPixelWriter.m_Size);
          }
          else
          {
            v55 = this->m_LightmapPixelWriter.m_RMask;
            v56 = this->m_LightmapPixelWriter.m_RShift & 0x1F;
            v57 = &v135[4 * (this->m_LightmapPixelWriter.m_RShift >> 5)];
            *(_DWORD *)v135 = 0;
            v136 = 0;
            v58 = (LODWORD(v40) & v55) << v56;
            v59 = this->m_LightmapPixelWriter.m_GShift;
            v137 = 0;
            v138 = 0;
            *(_DWORD *)v57 |= v58;
            v60 = v59;
            v61 = (this->m_LightmapPixelWriter.m_GMask & LODWORD(v41)) << (v59 & 0x1F);
            v62 = this->m_LightmapPixelWriter.m_BShift;
            *(_DWORD *)&v135[4 * (v60 >> 5)] |= v61;
            v63 = v62;
            v64 = (LODWORD(v42) & this->m_LightmapPixelWriter.m_BMask) << (v62 & 0x1F);
            v65 = this->m_LightmapPixelWriter.m_AShift;
            *(_DWORD *)&v135[4 * (v63 >> 5)] |= v64;
            *(_DWORD *)&v135[4 * (v65 >> 5)] |= (this->m_LightmapPixelWriter.m_AMask & LODWORD(v43)) << (v65 & 0x1F);
            memcpy(dst: this->m_LightmapPixelWriter.m_pBits, src: v135, count: this->m_LightmapPixelWriter.m_Size);
          }
          this->m_LightmapPixelWriter.m_pBits += nLightmap0WriterSizeBytes;
          v66 = *v176;
          v67 = *(float *)((char *)v12 + (_DWORD)v122);
          v68 = v12[1];
          v69 = *(v176 - 1);
          v126 = *v176;
          if ( (this->m_LightmapPixelWriter.m_nFlags & 2) != 0 )
          {
            v146 = float16::ConvertFloatTo16bitsNonDefault<0>(input: v69);
            v147 = float16::ConvertFloatTo16bitsNonDefault<0>(input: v126);
            v148 = float16::ConvertFloatTo16bitsNonDefault<0>(input: v67);
            v70 = float16::ConvertFloatTo16bitsNonDefault<0>(input: v68);
            *(_DWORD *)v167 = 0;
            v71 = v146 & this->m_LightmapPixelWriter.m_RMask;
            v168 = 0;
            v72 = this->m_LightmapPixelWriter.m_RShift;
            LOWORD(v149) = v70;
            v73 = v72 >> 4;
            v74 = v71 << (v72 & 0xF);
            v75 = this->m_LightmapPixelWriter.m_GShift;
            *(_WORD *)&v167[2 * v73] |= v74;
            v76 = v75;
            v77 = (this->m_LightmapPixelWriter.m_GMask & v147) << (v75 & 0xF);
            v78 = this->m_LightmapPixelWriter.m_BShift;
            *(_WORD *)&v167[2 * (v76 >> 4)] |= v77;
            v79 = v78;
            v80 = (this->m_LightmapPixelWriter.m_BMask & v148) << (v78 & 0xF);
            v81 = this->m_LightmapPixelWriter.m_AShift;
            *(_WORD *)&v167[2 * (v79 >> 4)] |= v80;
            *(_WORD *)&v167[2 * (v81 >> 4)] |= (this->m_LightmapPixelWriter.m_AMask & (unsigned __int16)v149) << (v81 & 0xF);
            memcpy(dst: this->m_LightmapPixelWriter.m_pBits, src: v167, count: this->m_LightmapPixelWriter.m_Size);
          }
          else
          {
            v82 = this->m_LightmapPixelWriter.m_RMask;
            v83 = this->m_LightmapPixelWriter.m_RShift & 0x1F;
            v84 = &v127[4 * (this->m_LightmapPixelWriter.m_RShift >> 5)];
            *(_DWORD *)v127 = 0;
            v128 = 0;
            v85 = (LODWORD(v69) & v82) << v83;
            v86 = this->m_LightmapPixelWriter.m_GShift;
            v129 = 0;
            v130 = 0;
            *(_DWORD *)v84 |= v85;
            v87 = v86;
            v88 = (this->m_LightmapPixelWriter.m_GMask & LODWORD(v66)) << (v86 & 0x1F);
            v89 = this->m_LightmapPixelWriter.m_BShift;
            *(_DWORD *)&v127[4 * (v87 >> 5)] |= v88;
            v90 = v89;
            v91 = (LODWORD(v67) & this->m_LightmapPixelWriter.m_BMask) << (v89 & 0x1F);
            v92 = this->m_LightmapPixelWriter.m_AShift;
            *(_DWORD *)&v127[4 * (v90 >> 5)] |= v91;
            *(_DWORD *)&v127[4 * (v92 >> 5)] |= (this->m_LightmapPixelWriter.m_AMask & LODWORD(v68)) << (v92 & 0x1F);
            memcpy(dst: this->m_LightmapPixelWriter.m_pBits, src: v127, count: this->m_LightmapPixelWriter.m_Size);
          }
          v93 = v175;
          this->m_LightmapPixelWriter.m_pBits += nLightmap0WriterSizeBytes;
          v94 = *v93;
          v95 = *(float *)((char *)v176 + (char *)pFloatImageBump3 - (char *)pFloatImageBump2);
          v96 = *(float *)((char *)v12 + (_DWORD)v123);
          v97 = v12[1];
          if ( (this->m_LightmapPixelWriter.m_nFlags & 2) != 0 )
          {
            v158 = float16::ConvertFloatTo16bitsNonDefault<0>(input: v94);
            v159 = float16::ConvertFloatTo16bitsNonDefault<0>(input: v95);
            v160 = float16::ConvertFloatTo16bitsNonDefault<0>(input: v96);
            v98 = float16::ConvertFloatTo16bitsNonDefault<0>(input: v97);
            *(_DWORD *)v169 = 0;
            v99 = this->m_LightmapPixelWriter.m_RMask & v158;
            v170 = 0;
            v100 = this->m_LightmapPixelWriter.m_RShift;
            v161 = v98;
            v101 = v100 >> 4;
            v102 = v99 << (v100 & 0xF);
            v103 = this->m_LightmapPixelWriter.m_GShift;
            *(_WORD *)&v169[2 * v101] |= v102;
            v104 = v103;
            v105 = (this->m_LightmapPixelWriter.m_GMask & v159) << (v103 & 0xF);
            v106 = this->m_LightmapPixelWriter.m_BShift;
            *(_WORD *)&v169[2 * (v104 >> 4)] |= v105;
            v107 = v106;
            v108 = (this->m_LightmapPixelWriter.m_BMask & v160) << (v106 & 0xF);
            v109 = this->m_LightmapPixelWriter.m_AShift;
            *(_WORD *)&v169[2 * (v107 >> 4)] |= v108;
            *(_WORD *)&v169[2 * (v109 >> 4)] |= (this->m_LightmapPixelWriter.m_AMask & v161) << (v109 & 0xF);
            memcpy(dst: this->m_LightmapPixelWriter.m_pBits, src: v169, count: this->m_LightmapPixelWriter.m_Size);
          }
          else
          {
            v110 = this->m_LightmapPixelWriter.m_RShift >> 5;
            v111 = this->m_LightmapPixelWriter.m_RShift & 0x1F;
            v112 = this->m_LightmapPixelWriter.m_RMask & LODWORD(v94);
            *(_DWORD *)v139 = 0;
            v113 = v112 << v111;
            v114 = this->m_LightmapPixelWriter.m_GShift;
            v140 = 0;
            v141 = 0;
            v142 = 0;
            *(_DWORD *)&v139[4 * v110] |= v113;
            v115 = v114;
            v116 = (this->m_LightmapPixelWriter.m_GMask & LODWORD(v95)) << (v114 & 0x1F);
            v117 = this->m_LightmapPixelWriter.m_BShift;
            *(_DWORD *)&v139[4 * (v115 >> 5)] |= v116;
            v118 = v117;
            v119 = (this->m_LightmapPixelWriter.m_BMask & LODWORD(v96)) << (v117 & 0x1F);
            v120 = this->m_LightmapPixelWriter.m_AShift;
            *(_DWORD *)&v139[4 * (v118 >> 5)] |= v119;
            *(_DWORD *)&v139[4 * (v120 >> 5)] |= (this->m_LightmapPixelWriter.m_AMask & LODWORD(v97)) << (v120 & 0x1F);
            memcpy(dst: this->m_LightmapPixelWriter.m_pBits, src: v139, count: this->m_LightmapPixelWriter.m_Size);
          }
          this->m_LightmapPixelWriter.m_pBits += nRewindToNextPixel;
          v176 += 4;
          v175 += 4;
          v12 += 4;
        }
        v11 = pFloatImage;
      }
      v162 = (float *)((char *)v162 + v144);
      v164 = (float *)((char *)v164 + v144);
      v165 = (float *)((char *)v165 + v144);
      ++t;
    }
    while ( t < pLightmapSize[1] );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038870
// Name: private: void CMatLightmaps::BumpedLightmapBitsToPixelWriter_HDRI(float __near *,float __near *,float __near *,float __near *,int __near * const,int __near * const,class FloatBitMap_t __near *)restrict
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatLightmaps::BumpedLightmapBitsToPixelWriter_HDRI(
        CMatLightmaps *this,
        float *pFloatImage,
        float *pFloatImageBump1,
        float *pFloatImageBump2,
        float *pFloatImageBump3,
        int *pLightmapSize,
        int *pOffsetIntoLightmapPage,
        FloatBitMap_t *pfmOut)
{
  int m_Size; // ecx
  int v10; // eax
  bool v11; // zf
  bool v12; // cc
  float *v13; // ebx
  float *v14; // eax
  float v15; // edx
  float v16; // ecx
  float v17; // edx
  float v18; // eax
  float v19; // xmm1_4
  float v20; // xmm4_4
  float v21; // xmm0_4
  float v22; // xmm3_4
  float v23; // xmm2_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  float v26; // xmm3_4
  float v27; // xmm1_4
  float in; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm1_4
  float v31; // xmm3_4
  float v32; // xmm4_4
  unsigned __int16 v33; // bx
  unsigned __int16 v34; // ax
  int m_RShift; // ecx
  unsigned __int16 v36; // ax
  int v37; // edx
  __int16 v38; // ax
  int v39; // ecx
  int v40; // edx
  __int16 v41; // ax
  int v42; // ecx
  int v43; // edx
  __int16 v44; // ax
  int v45; // ecx
  int v46; // edx
  __int16 v47; // ax
  unsigned int v48; // ecx
  unsigned __int8 *v49; // eax
  unsigned int m_RMask; // edx
  char v51; // cl
  int v52; // edx
  int m_GShift; // ecx
  int v54; // eax
  unsigned int v55; // edx
  int v56; // ecx
  int v57; // eax
  unsigned int v58; // edx
  int v59; // ecx
  float v60; // xmm1_4
  float v61; // xmm2_4
  unsigned __int16 v62; // bx
  unsigned __int16 v63; // ax
  int v64; // ecx
  int v65; // edx
  __int16 v66; // ax
  int v67; // ecx
  int v68; // edx
  __int16 v69; // ax
  int v70; // ecx
  int v71; // edx
  __int16 v72; // ax
  unsigned int v73; // ecx
  unsigned __int8 *v74; // eax
  unsigned int v75; // edx
  char v76; // cl
  unsigned int v77; // edx
  int v78; // ecx
  int v79; // eax
  unsigned int v80; // edx
  int v81; // ecx
  int v82; // eax
  unsigned int v83; // edx
  int v84; // ecx
  float v85; // xmm1_4
  float v86; // xmm2_4
  unsigned __int16 v87; // bx
  unsigned __int16 v88; // ax
  int v89; // ecx
  int v90; // edx
  __int16 v91; // ax
  int v92; // ecx
  int v93; // edx
  __int16 v94; // ax
  int v95; // ecx
  int v96; // edx
  __int16 v97; // ax
  unsigned int v98; // ecx
  unsigned __int8 *v99; // eax
  unsigned int v100; // edx
  char v101; // cl
  unsigned int v102; // edx
  int v103; // ecx
  int v104; // eax
  unsigned int v105; // edx
  int v106; // ecx
  int v107; // eax
  unsigned int v108; // edx
  int v109; // ecx
  float v110; // xmm1_4
  float v111; // xmm2_4
  unsigned __int16 v112; // bx
  unsigned __int16 v113; // ax
  int v114; // ecx
  int v115; // edx
  __int16 v116; // ax
  int v117; // ecx
  int v118; // edx
  __int16 v119; // ax
  int v120; // ecx
  int v121; // edx
  __int16 v122; // ax
  unsigned int v123; // ecx
  _DWORD *v124; // eax
  unsigned int v125; // edx
  char v126; // cl
  unsigned int v127; // edx
  int v128; // ecx
  int v129; // eax
  unsigned int v130; // edx
  int v131; // ecx
  unsigned int m_BMask; // edx
  int v133; // eax
  int v134; // edx
  int v135; // ecx
  unsigned __int8 *v136; // edx
  float v137; // edx
  float v138; // ecx
  float v139; // edx
  float v140; // xmm3_4
  float v141; // xmm0_4
  float v142; // xmm4_4
  float *v143; // edi
  float v144; // xmm1_4
  float v145; // xmm2_4
  float v146; // xmm0_4
  float v147; // xmm3_4
  float v148; // xmm1_4
  float v149; // xmm0_4
  float v150; // xmm1_4
  unsigned __int16 v151; // bx
  unsigned __int16 v152; // ax
  float v153; // xmm0_4
  int v154; // ecx
  unsigned __int8 v155; // bl
  unsigned int v156; // eax
  __int16 v157; // cx
  unsigned int v158; // eax
  unsigned int v159; // edx
  unsigned int v160; // edx
  unsigned int v161; // eax
  unsigned __int8 *v162; // ecx
  unsigned __int64 v163; // kr00_8
  unsigned __int64 v164; // rax
  __int16 m_BShift; // cx
  int v166; // ebx
  int v167; // edi
  __int64 v168; // rax
  __int64 v169; // rax
  __int16 m_AShift; // cx
  unsigned __int64 v171; // rax
  int v172; // ebx
  int v173; // edi
  unsigned __int8 *v174; // eax
  unsigned __int8 *m_pBits; // eax
  float v176; // ecx
  unsigned __int8 v177; // bl
  unsigned int v178; // eax
  __int16 v179; // cx
  unsigned int v180; // eax
  unsigned int v181; // edx
  unsigned int v182; // edx
  unsigned int v183; // eax
  unsigned __int8 *v184; // ecx
  unsigned __int64 v185; // kr08_8
  unsigned __int64 v186; // rax
  __int16 v187; // cx
  int v188; // ebx
  int v189; // edi
  __int64 v190; // rax
  __int64 v191; // rax
  __int16 v192; // cx
  unsigned __int64 v193; // rax
  int v194; // ebx
  int v195; // edi
  unsigned __int8 *v196; // eax
  unsigned __int8 *v197; // eax
  float v198; // ecx
  unsigned __int8 v199; // bl
  unsigned int v200; // eax
  __int16 v201; // cx
  unsigned int v202; // eax
  unsigned int v203; // edx
  unsigned int v204; // edx
  unsigned int v205; // eax
  unsigned __int8 *v206; // ecx
  unsigned __int64 v207; // kr10_8
  unsigned __int64 v208; // rax
  __int16 v209; // cx
  int v210; // ebx
  int v211; // edi
  __int64 v212; // rax
  __int64 v213; // rax
  __int16 v214; // cx
  unsigned __int64 v215; // rax
  int v216; // ebx
  int v217; // edi
  unsigned __int8 *v218; // eax
  unsigned __int8 *v219; // eax
  float v220; // ecx
  unsigned __int8 v221; // bl
  unsigned int v222; // eax
  __int16 v223; // cx
  unsigned int v224; // eax
  unsigned int v225; // edx
  unsigned int v226; // edx
  unsigned int v227; // eax
  unsigned __int8 *v228; // ecx
  unsigned __int64 v229; // kr18_8
  unsigned __int64 v230; // rax
  __int16 v231; // cx
  int v232; // ebx
  int v233; // edi
  __int64 v234; // rax
  __int64 v235; // rax
  __int16 v236; // cx
  unsigned __int64 v237; // rax
  int v238; // ebx
  int v239; // edi
  unsigned __int8 *v240; // eax
  unsigned __int8 *v241; // eax
  int v242; // eax
  unsigned __int8 v243[4]; // [esp+64h] [ebp-128h] BYREF
  int v244; // [esp+68h] [ebp-124h]
  int v245; // [esp+6Ch] [ebp-120h]
  int v246; // [esp+70h] [ebp-11Ch]
  unsigned __int8 v247[4]; // [esp+74h] [ebp-118h] BYREF
  int v248; // [esp+78h] [ebp-114h]
  int v249; // [esp+7Ch] [ebp-110h]
  int v250; // [esp+80h] [ebp-10Ch]
  unsigned __int8 v251[4]; // [esp+84h] [ebp-108h] BYREF
  int v252; // [esp+88h] [ebp-104h]
  int v253; // [esp+8Ch] [ebp-100h]
  int v254; // [esp+90h] [ebp-FCh]
  float v255; // [esp+98h] [ebp-F4h]
  float v256; // [esp+9Ch] [ebp-F0h]
  int nRewindToNextPixel; // [esp+A0h] [ebp-ECh]
  PixRGBAF pixelData; // [esp+A4h] [ebp-E8h] BYREF
  float v259; // [esp+B4h] [ebp-D8h]
  int v260; // [esp+B8h] [ebp-D4h]
  int v261; // [esp+BCh] [ebp-D0h]
  __int64 v262; // [esp+C0h] [ebp-CCh]
  float v263; // [esp+C8h] [ebp-C4h]
  int v264; // [esp+CCh] [ebp-C0h]
  int v265; // [esp+D0h] [ebp-BCh]
  unsigned __int8 v266[4]; // [esp+D4h] [ebp-B8h] BYREF
  int v267; // [esp+D8h] [ebp-B4h]
  unsigned __int8 v268[4]; // [esp+DCh] [ebp-B0h] BYREF
  int v269; // [esp+E0h] [ebp-ACh]
  unsigned __int8 src[4]; // [esp+E4h] [ebp-A8h] BYREF
  int v271; // [esp+E8h] [ebp-A4h]
  int nLightmapSize0; // [esp+ECh] [ebp-A0h]
  int input; // [esp+F0h] [ebp-9Ch]
  unsigned __int16 color[4][4]; // [esp+F4h] [ebp-98h]
  __int64 v275; // [esp+114h] [ebp-78h]
  float v276; // [esp+11Ch] [ebp-70h]
  __int64 v277; // [esp+120h] [ebp-6Ch]
  float *v278; // [esp+128h] [ebp-64h]
  int s; // [esp+12Ch] [ebp-60h]
  __int64 v280; // [esp+130h] [ebp-5Ch]
  __int64 v281; // [esp+138h] [ebp-54h]
  int nLightmap0WriterSizeBytes; // [esp+140h] [ebp-4Ch]
  float *v283; // [esp+144h] [ebp-48h]
  unsigned __int8 v284[8]; // [esp+148h] [ebp-44h] BYREF
  float v285; // [esp+150h] [ebp-3Ch]
  __int64 v286; // [esp+154h] [ebp-38h]
  float v287; // [esp+15Ch] [ebp-30h]
  __int64 v288; // [esp+160h] [ebp-2Ch]
  float v289; // [esp+168h] [ebp-24h]
  int v290; // [esp+16Ch] [ebp-20h]
  float *v291; // [esp+170h] [ebp-1Ch]
  __int64 v292; // [esp+174h] [ebp-18h]
  float v293; // [esp+17Ch] [ebp-10h]
  float *v294; // [esp+180h] [ebp-Ch]
  float v295; // [esp+184h] [ebp-8h]
  int t; // [esp+188h] [ebp-4h]
  float *pFloatImagea; // [esp+194h] [ebp+8h]
  int pFloatImageb; // [esp+194h] [ebp+8h]
  float pfmOuta; // [esp+1ACh] [ebp+20h]

  m_Size = this->m_LightmapPixelWriter.m_Size;
  v10 = *pLightmapSize;
  nLightmap0WriterSizeBytes = *pLightmapSize * m_Size;
  v11 = (this->m_LightmapPixelWriter.m_nFlags & 1) == 0;
  nLightmapSize0 = v10;
  nRewindToNextPixel = m_Size - 3 * nLightmap0WriterSizeBytes;
  if ( v11 )
  {
    v12 = pLightmapSize[1] <= 0;
    v291 = nullptr;
    if ( !v12 )
    {
      v261 = 16 * v10;
      v278 = pFloatImageBump1;
      v283 = pFloatImage + 2;
      while ( 1 )
      {
        v136 = &this->m_LightmapPixelWriter.m_pBase[*pOffsetIntoLightmapPage * this->m_LightmapPixelWriter.m_Size
                                                  + this->m_LightmapPixelWriter.m_BytesPerRow
                                                  * ((_DWORD)v291 + pOffsetIntoLightmapPage[1])];
        s = 0;
        this->m_LightmapPixelWriter.m_pBits = v136;
        if ( v10 > 0 )
        {
          v276 = *(float *)&v278;
          v294 = v283;
          v264 = (char *)pFloatImageBump2 - (char *)pFloatImageBump1;
          v260 = (char *)pFloatImageBump3 - (char *)pFloatImageBump1;
          do
          {
            v137 = *(float *)(LODWORD(v276) + 8);
            v286 = *(_QWORD *)LODWORD(v276);
            v138 = *(float *)(v264 + LODWORD(v276) + 8);
            v288 = *(_QWORD *)(v264 + LODWORD(v276));
            v289 = v138;
            v292 = *(_QWORD *)(v260 + LODWORD(v276));
            *(_QWORD *)v284 = *(_QWORD *)LODWORD(v276);
            v287 = v137;
            v139 = *(float *)(v260 + LODWORD(v276) + 8);
            v285 = *(float *)(LODWORD(v276) + 8);
            v293 = v139;
            v140 = (float)(*(float *)&v292 + (float)(*(float *)&v288 + *(float *)v284)) * 0.33333334;
            *(float *)v284 = v140;
            v141 = (float)(*((float *)&v292 + 1) + (float)(*((float *)&v288 + 1) + *(float *)&v284[4])) * 0.33333334;
            v142 = (float)(v139 + (float)(v138 + v285)) * 0.33333334;
            *(float *)&v284[4] = v141;
            v285 = v142;
            if ( v140 == 0.0 || *(_DWORD *)&v284[4] == 0 || v285 == 0.0 )
            {
              v146 = 0.0;
              v143 = v294;
              v145 = 0.0;
              v144 = 0.0;
              if ( v140 != 0.0 )
                v145 = *(v294 - 2) / v140;
              if ( *(float *)&v284[4] != 0.0 )
                v144 = *(v294 - 1) / *(float *)&v284[4];
              if ( v285 != 0.0 )
                v146 = *v294 / v285;
            }
            else
            {
              v143 = v294;
              v144 = *(v294 - 1) / v141;
              v145 = *(v294 - 2) / v140;
              v146 = *v294 / v142;
            }
            *(float *)&v286 = *(float *)&v286 * v145;
            *((float *)&v286 + 1) = *((float *)&v286 + 1) * v144;
            v287 = v287 * v146;
            *(float *)&v288 = v145 * *(float *)&v288;
            *((float *)&v288 + 1) = v144 * *((float *)&v288 + 1);
            v147 = v146;
            *((float *)&v292 + 1) = v144 * *((float *)&v292 + 1);
            v148 = *(v143 - 1);
            v293 = v146 * v293;
            v149 = *(v143 - 2);
            v255 = v148;
            v150 = *v143;
            v289 = v147 * v289;
            *(float *)&v292 = v145 * *(float *)&v292;
            v256 = v150;
            v151 = ColorSpace::LinearFloatToCorrectedShort(in: v149);
            color[0][1] = ColorSpace::LinearFloatToCorrectedShort(in: v255);
            color[0][2] = ColorSpace::LinearFloatToCorrectedShort(in: v150);
            color[1][0] = ColorSpace::LinearFloatToCorrectedShort(in: *(float *)&v286);
            color[1][1] = ColorSpace::LinearFloatToCorrectedShort(in: *((float *)&v286 + 1));
            color[1][2] = ColorSpace::LinearFloatToCorrectedShort(in: v287);
            color[2][0] = ColorSpace::LinearFloatToCorrectedShort(in: *(float *)&v288);
            color[2][1] = ColorSpace::LinearFloatToCorrectedShort(in: *((float *)&v288 + 1));
            color[2][2] = ColorSpace::LinearFloatToCorrectedShort(in: v289);
            color[3][0] = ColorSpace::LinearFloatToCorrectedShort(in: *(float *)&v292);
            color[3][1] = ColorSpace::LinearFloatToCorrectedShort(in: *((float *)&v292 + 1));
            v152 = ColorSpace::LinearFloatToCorrectedShort(in: v293);
            v153 = v143[1] * 65536.0;
            color[3][2] = v152;
            if ( v153 < 65535.0 )
            {
              if ( v153 <= 0.0 )
                v153 = 0.0;
            }
            else
            {
              v153 = 65535.0;
            }
            pFloatImageb = (unsigned __int16)(int)v153;
            v154 = v151;
            v155 = this->m_LightmapPixelWriter.m_Size;
            v290 = color[0][2];
            input = color[0][1];
            v265 = v154;
            if ( v155 != 0 )
            {
              v156 = v154 & this->m_LightmapPixelWriter.m_RMask;
              if ( v155 >= 5u )
              {
                v163 = (unsigned __int64)v156 << this->m_LightmapPixelWriter.m_RShift;
                v164 = (unsigned __int64)(input & this->m_LightmapPixelWriter.m_GMask) << this->m_LightmapPixelWriter.m_GShift;
                m_BShift = this->m_LightmapPixelWriter.m_BShift;
                v166 = v164 | v163;
                LODWORD(v168) = v290 & this->m_LightmapPixelWriter.m_BMask;
                v167 = HIDWORD(v164) | HIDWORD(v163);
                HIDWORD(v168) = 0;
                if ( m_BShift <= 0 )
                  v169 = v168 >> -(char)m_BShift;
                else
                  v169 = v168 << m_BShift;
                m_AShift = this->m_LightmapPixelWriter.m_AShift;
                v275 = v169;
                v171 = (unsigned __int64)(pFloatImageb & this->m_LightmapPixelWriter.m_AMask) << m_AShift;
                v172 = v275 | v171 | v166;
                v173 = HIDWORD(v275) | HIDWORD(v171) | v167;
                if ( this->m_LightmapPixelWriter.m_Size == 6 )
                {
                  m_pBits = this->m_LightmapPixelWriter.m_pBits;
                  *(_DWORD *)m_pBits = v172;
                  *((_WORD *)m_pBits + 2) = v173;
                }
                else if ( this->m_LightmapPixelWriter.m_Size == 8 )
                {
                  v174 = this->m_LightmapPixelWriter.m_pBits;
                  *(_DWORD *)v174 = v172;
                  *((_DWORD *)v174 + 1) = v173;
                }
              }
              else
              {
                v157 = this->m_LightmapPixelWriter.m_BShift;
                v158 = ((color[0][1] & this->m_LightmapPixelWriter.m_GMask) << LOBYTE(this->m_LightmapPixelWriter.m_GShift))
                     | (v156 << LOBYTE(this->m_LightmapPixelWriter.m_RShift));
                v159 = color[0][2] & this->m_LightmapPixelWriter.m_BMask;
                if ( v157 <= 0 )
                  v160 = v159 >> -(char)v157;
                else
                  v160 = v159 << v157;
                v161 = v160
                     | ((pFloatImageb & this->m_LightmapPixelWriter.m_AMask) << LOBYTE(this->m_LightmapPixelWriter.m_AShift))
                     | v158;
                switch ( v155 )
                {
                  case 1u:
                    *this->m_LightmapPixelWriter.m_pBits = v161;
                    break;
                  case 2u:
                    *(_WORD *)this->m_LightmapPixelWriter.m_pBits = v161;
                    break;
                  case 3u:
                    v162 = this->m_LightmapPixelWriter.m_pBits;
                    *(_WORD *)v162 = v161;
                    v162[2] = BYTE2(v161);
                    break;
                  case 4u:
                    *(_DWORD *)this->m_LightmapPixelWriter.m_pBits = v161;
                    break;
                }
              }
            }
            LODWORD(v176) = color[1][1];
            this->m_LightmapPixelWriter.m_pBits += nLightmap0WriterSizeBytes;
            v177 = this->m_LightmapPixelWriter.m_Size;
            v295 = v176;
            t = color[1][2];
            if ( v177 != 0 )
            {
              v178 = color[1][0] & this->m_LightmapPixelWriter.m_RMask;
              if ( v177 >= 5u )
              {
                v185 = (unsigned __int64)v178 << this->m_LightmapPixelWriter.m_RShift;
                v186 = (unsigned __int64)(LODWORD(v295) & this->m_LightmapPixelWriter.m_GMask) << this->m_LightmapPixelWriter.m_GShift;
                v187 = this->m_LightmapPixelWriter.m_BShift;
                v188 = v186 | v185;
                LODWORD(v190) = t & this->m_LightmapPixelWriter.m_BMask;
                v189 = HIDWORD(v186) | HIDWORD(v185);
                HIDWORD(v190) = 0;
                if ( v187 <= 0 )
                  v191 = v190 >> -(char)v187;
                else
                  v191 = v190 << v187;
                v192 = this->m_LightmapPixelWriter.m_AShift;
                v277 = v191;
                v193 = (unsigned __int64)(pFloatImageb & this->m_LightmapPixelWriter.m_AMask) << v192;
                v194 = v277 | v193 | v188;
                v195 = HIDWORD(v277) | HIDWORD(v193) | v189;
                if ( this->m_LightmapPixelWriter.m_Size == 6 )
                {
                  v197 = this->m_LightmapPixelWriter.m_pBits;
                  *(_DWORD *)v197 = v194;
                  *((_WORD *)v197 + 2) = v195;
                }
                else if ( this->m_LightmapPixelWriter.m_Size == 8 )
                {
                  v196 = this->m_LightmapPixelWriter.m_pBits;
                  *(_DWORD *)v196 = v194;
                  *((_DWORD *)v196 + 1) = v195;
                }
              }
              else
              {
                v179 = this->m_LightmapPixelWriter.m_BShift;
                v180 = ((LODWORD(v295) & this->m_LightmapPixelWriter.m_GMask) << LOBYTE(this->m_LightmapPixelWriter.m_GShift))
                     | (v178 << LOBYTE(this->m_LightmapPixelWriter.m_RShift));
                v181 = t & this->m_LightmapPixelWriter.m_BMask;
                if ( v179 <= 0 )
                  v182 = v181 >> -(char)v179;
                else
                  v182 = v181 << v179;
                v183 = v182
                     | ((pFloatImageb & this->m_LightmapPixelWriter.m_AMask) << LOBYTE(this->m_LightmapPixelWriter.m_AShift))
                     | v180;
                switch ( v177 )
                {
                  case 1u:
                    *this->m_LightmapPixelWriter.m_pBits = v183;
                    break;
                  case 2u:
                    *(_WORD *)this->m_LightmapPixelWriter.m_pBits = v183;
                    break;
                  case 3u:
                    v184 = this->m_LightmapPixelWriter.m_pBits;
                    *(_WORD *)v184 = v183;
                    v184[2] = BYTE2(v183);
                    break;
                  case 4u:
                    *(_DWORD *)this->m_LightmapPixelWriter.m_pBits = v183;
                    break;
                }
              }
            }
            LODWORD(v198) = color[2][1];
            this->m_LightmapPixelWriter.m_pBits += nLightmap0WriterSizeBytes;
            v199 = this->m_LightmapPixelWriter.m_Size;
            v295 = v198;
            t = color[2][2];
            if ( v199 != 0 )
            {
              v200 = color[2][0] & this->m_LightmapPixelWriter.m_RMask;
              if ( v199 >= 5u )
              {
                v207 = (unsigned __int64)v200 << this->m_LightmapPixelWriter.m_RShift;
                v208 = (unsigned __int64)(LODWORD(v295) & this->m_LightmapPixelWriter.m_GMask) << this->m_LightmapPixelWriter.m_GShift;
                v209 = this->m_LightmapPixelWriter.m_BShift;
                v210 = v208 | v207;
                LODWORD(v212) = t & this->m_LightmapPixelWriter.m_BMask;
                v211 = HIDWORD(v208) | HIDWORD(v207);
                HIDWORD(v212) = 0;
                if ( v209 <= 0 )
                  v213 = v212 >> -(char)v209;
                else
                  v213 = v212 << v209;
                v214 = this->m_LightmapPixelWriter.m_AShift;
                v280 = v213;
                v215 = (unsigned __int64)(pFloatImageb & this->m_LightmapPixelWriter.m_AMask) << v214;
                v216 = v280 | v215 | v210;
                v217 = HIDWORD(v280) | HIDWORD(v215) | v211;
                if ( this->m_LightmapPixelWriter.m_Size == 6 )
                {
                  v219 = this->m_LightmapPixelWriter.m_pBits;
                  *(_DWORD *)v219 = v216;
                  *((_WORD *)v219 + 2) = v217;
                }
                else if ( this->m_LightmapPixelWriter.m_Size == 8 )
                {
                  v218 = this->m_LightmapPixelWriter.m_pBits;
                  *(_DWORD *)v218 = v216;
                  *((_DWORD *)v218 + 1) = v217;
                }
              }
              else
              {
                v201 = this->m_LightmapPixelWriter.m_BShift;
                v202 = ((LODWORD(v295) & this->m_LightmapPixelWriter.m_GMask) << LOBYTE(this->m_LightmapPixelWriter.m_GShift))
                     | (v200 << LOBYTE(this->m_LightmapPixelWriter.m_RShift));
                v203 = t & this->m_LightmapPixelWriter.m_BMask;
                if ( v201 <= 0 )
                  v204 = v203 >> -(char)v201;
                else
                  v204 = v203 << v201;
                v205 = v204
                     | ((pFloatImageb & this->m_LightmapPixelWriter.m_AMask) << LOBYTE(this->m_LightmapPixelWriter.m_AShift))
                     | v202;
                switch ( v199 )
                {
                  case 1u:
                    *this->m_LightmapPixelWriter.m_pBits = v205;
                    break;
                  case 2u:
                    *(_WORD *)this->m_LightmapPixelWriter.m_pBits = v205;
                    break;
                  case 3u:
                    v206 = this->m_LightmapPixelWriter.m_pBits;
                    *(_WORD *)v206 = v205;
                    v206[2] = BYTE2(v205);
                    break;
                  case 4u:
                    *(_DWORD *)this->m_LightmapPixelWriter.m_pBits = v205;
                    break;
                }
              }
            }
            LODWORD(v220) = color[3][1];
            this->m_LightmapPixelWriter.m_pBits += nLightmap0WriterSizeBytes;
            v221 = this->m_LightmapPixelWriter.m_Size;
            v295 = v220;
            t = color[3][2];
            if ( v221 != 0 )
            {
              v222 = color[3][0] & this->m_LightmapPixelWriter.m_RMask;
              if ( v221 >= 5u )
              {
                v229 = (unsigned __int64)v222 << this->m_LightmapPixelWriter.m_RShift;
                v230 = (unsigned __int64)(LODWORD(v295) & this->m_LightmapPixelWriter.m_GMask) << this->m_LightmapPixelWriter.m_GShift;
                v231 = this->m_LightmapPixelWriter.m_BShift;
                v232 = v230 | v229;
                LODWORD(v234) = t & this->m_LightmapPixelWriter.m_BMask;
                v233 = HIDWORD(v230) | HIDWORD(v229);
                HIDWORD(v234) = 0;
                if ( v231 <= 0 )
                  v235 = v234 >> -(char)v231;
                else
                  v235 = v234 << v231;
                v236 = this->m_LightmapPixelWriter.m_AShift;
                v281 = v235;
                v237 = (unsigned __int64)(pFloatImageb & this->m_LightmapPixelWriter.m_AMask) << v236;
                v238 = v281 | v237 | v232;
                v239 = HIDWORD(v281) | HIDWORD(v237) | v233;
                if ( this->m_LightmapPixelWriter.m_Size == 6 )
                {
                  v241 = this->m_LightmapPixelWriter.m_pBits;
                  *(_DWORD *)v241 = v238;
                  *((_WORD *)v241 + 2) = v239;
                }
                else if ( this->m_LightmapPixelWriter.m_Size == 8 )
                {
                  v240 = this->m_LightmapPixelWriter.m_pBits;
                  *(_DWORD *)v240 = v238;
                  *((_DWORD *)v240 + 1) = v239;
                }
              }
              else
              {
                v223 = this->m_LightmapPixelWriter.m_BShift;
                v224 = ((LODWORD(v295) & this->m_LightmapPixelWriter.m_GMask) << LOBYTE(this->m_LightmapPixelWriter.m_GShift))
                     | (v222 << LOBYTE(this->m_LightmapPixelWriter.m_RShift));
                v225 = t & this->m_LightmapPixelWriter.m_BMask;
                if ( v223 <= 0 )
                  v226 = v225 >> -(char)v223;
                else
                  v226 = v225 << v223;
                v227 = v226
                     | ((pFloatImageb & this->m_LightmapPixelWriter.m_AMask) << LOBYTE(this->m_LightmapPixelWriter.m_AShift))
                     | v224;
                switch ( v221 )
                {
                  case 1u:
                    *this->m_LightmapPixelWriter.m_pBits = v227;
                    break;
                  case 2u:
                    *(_WORD *)this->m_LightmapPixelWriter.m_pBits = v227;
                    break;
                  case 3u:
                    v228 = this->m_LightmapPixelWriter.m_pBits;
                    *(_WORD *)v228 = v227;
                    v228[2] = BYTE2(v227);
                    break;
                  case 4u:
                    *(_DWORD *)this->m_LightmapPixelWriter.m_pBits = v227;
                    break;
                }
              }
            }
            if ( pfmOut != nullptr )
            {
              pixelData.Red = (float)v265;
              pixelData.Green = (float)input;
              pixelData.Blue = (float)v290;
              pixelData.Alpha = (float)pFloatImageb;
              FloatBitMap_t::WritePixelRGBAF(
                this: pfmOut,
                x: s + *pOffsetIntoLightmapPage,
                y: (int)v291 + pOffsetIntoLightmapPage[1],
                z: 0,
                value: pixelData);
            }
            v242 = s;
            this->m_LightmapPixelWriter.m_pBits += nRewindToNextPixel;
            v294 += 4;
            LODWORD(v276) += 16;
            s = v242 + 1;
          }
          while ( v242 + 1 < nLightmapSize0 );
        }
        v278 = (float *)((char *)v278 + v261);
        v283 = (float *)((char *)v283 + v261);
        v291 = (float *)((char *)v291 + 1);
        if ( (int)v291 >= pLightmapSize[1] )
          break;
        v10 = nLightmapSize0;
      }
    }
  }
  else
  {
    v12 = pLightmapSize[1] <= 0;
    t = 0;
    if ( !v12 )
    {
      v261 = 16 * v10;
      v294 = pFloatImageBump1;
      v290 = (int)(pFloatImage + 2);
      while ( 1 )
      {
        this->m_LightmapPixelWriter.m_pBits = &this->m_LightmapPixelWriter.m_pBase[*pOffsetIntoLightmapPage
                                                                                 * this->m_LightmapPixelWriter.m_Size
                                                                                 + this->m_LightmapPixelWriter.m_BytesPerRow
                                                                                 * (t + pOffsetIntoLightmapPage[1])];
        if ( v10 > 0 )
          break;
LABEL_30:
        v294 = (float *)((char *)v294 + v261);
        v290 += v261;
        if ( ++t >= pLightmapSize[1] )
          return;
        v10 = nLightmapSize0;
      }
      v13 = (float *)v290;
      v291 = v294;
      v264 = (char *)pFloatImageBump2 - (char *)pFloatImageBump1;
      v260 = (char *)pFloatImageBump3 - (char *)pFloatImageBump1;
      v14 = v294;
      pFloatImagea = (float *)v290;
      v283 = (float *)nLightmapSize0;
      while ( 1 )
      {
        v15 = v14[2];
        v286 = *(_QWORD *)v14;
        v16 = *(float *)((char *)v14 + v264 + 8);
        v288 = *(_QWORD *)((char *)v14 + v264);
        v289 = v16;
        v292 = *(_QWORD *)((char *)v14 + v260);
        v262 = *(_QWORD *)v14;
        v287 = v15;
        v17 = *(float *)((char *)v14 + v260 + 8);
        v18 = v14[2];
        v293 = v17;
        v19 = (float)(*(float *)&v292 + (float)(*(float *)&v288 + *(float *)&v262)) * 0.33333334;
        v20 = v19;
        *(float *)&v262 = v19;
        v21 = (float)(*((float *)&v292 + 1) + (float)(*((float *)&v288 + 1) + *((float *)&v262 + 1))) * 0.33333334;
        v22 = (float)(v17 + (float)(v16 + v18)) * 0.33333334;
        *((float *)&v262 + 1) = v21;
        v263 = v22;
        if ( v19 == 0.0 || HIDWORD(v262) == 0 || v263 == 0.0 )
        {
          v25 = 0.0;
          v11 = v19 == 0.0;
          v23 = 0.0;
          v24 = 0.0;
          if ( !v11 )
            v23 = *(v13 - 2) / v20;
          if ( *((float *)&v262 + 1) != 0.0 )
            v24 = *(v13 - 1) / *((float *)&v262 + 1);
          if ( v22 == 0.0 )
            goto LABEL_17;
        }
        else
        {
          v23 = *(v13 - 2) / v19;
          v24 = *(v13 - 1) / v21;
        }
        v25 = *v13 / v22;
LABEL_17:
        *(float *)&v286 = *(float *)&v286 * v23;
        *((float *)&v286 + 1) = *((float *)&v286 + 1) * v24;
        v287 = v287 * v25;
        *(float *)&v288 = v23 * *(float *)&v288;
        *((float *)&v288 + 1) = v24 * *((float *)&v288 + 1);
        v26 = v25 * v289;
        *((float *)&v292 + 1) = v24 * *((float *)&v292 + 1);
        v27 = *(v13 - 1);
        v293 = v25 * v293;
        in = *(v13 - 2);
        v255 = v27;
        v29 = *v13;
        v289 = v26;
        *(float *)&v292 = v23 * *(float *)&v292;
        v256 = v29;
        color[0][0] = ColorSpace::LinearFloatToCorrectedShort(in);
        color[0][1] = ColorSpace::LinearFloatToCorrectedShort(in: v255);
        color[0][2] = ColorSpace::LinearFloatToCorrectedShort(in: v256);
        color[1][0] = ColorSpace::LinearFloatToCorrectedShort(in: *(float *)&v286);
        color[1][1] = ColorSpace::LinearFloatToCorrectedShort(in: *((float *)&v286 + 1));
        color[1][2] = ColorSpace::LinearFloatToCorrectedShort(in: v287);
        color[2][0] = ColorSpace::LinearFloatToCorrectedShort(in: *(float *)&v288);
        color[2][1] = ColorSpace::LinearFloatToCorrectedShort(in: *((float *)&v288 + 1));
        color[2][2] = ColorSpace::LinearFloatToCorrectedShort(in: v289);
        color[3][0] = ColorSpace::LinearFloatToCorrectedShort(in: *(float *)&v292);
        color[3][1] = ColorSpace::LinearFloatToCorrectedShort(in: *((float *)&v292 + 1));
        color[3][2] = ColorSpace::LinearFloatToCorrectedShort(in: v293);
        v11 = (this->m_LightmapPixelWriter.m_nFlags & 2) == 0;
        v30 = (float)(unsigned __int16)(int)v13[1] * 0.000015258789;
        v31 = (float)color[0][1] * 0.000015258789;
        v32 = (float)color[0][2] * 0.000015258789;
        *(float *)&input = v31;
        v295 = v32;
        pfmOuta = v30;
        *(float *)&v278 = v30;
        if ( v11 )
        {
          v49 = &v243[4 * (this->m_LightmapPixelWriter.m_RShift >> 5)];
          m_RMask = this->m_LightmapPixelWriter.m_RMask;
          v51 = this->m_LightmapPixelWriter.m_RShift & 0x1F;
          v276 = (float)color[0][0] * 0.000015258789;
          *(_DWORD *)v243 = 0;
          v244 = 0;
          v52 = (LODWORD(v276) & m_RMask) << v51;
          m_GShift = this->m_LightmapPixelWriter.m_GShift;
          v245 = 0;
          v246 = 0;
          *(_DWORD *)v49 |= v52;
          v54 = m_GShift;
          s = LODWORD(v31);
          v55 = (this->m_LightmapPixelWriter.m_GMask & LODWORD(v31)) << (m_GShift & 0x1F);
          v56 = this->m_LightmapPixelWriter.m_BShift;
          *(_DWORD *)&v243[4 * (v54 >> 5)] |= v55;
          v57 = v56;
          v58 = (LODWORD(v32) & this->m_LightmapPixelWriter.m_BMask) << (v56 & 0x1F);
          v59 = this->m_LightmapPixelWriter.m_AShift;
          *(_DWORD *)&v243[4 * (v57 >> 5)] |= v58;
          *(_DWORD *)&v243[4 * (v59 >> 5)] |= (this->m_LightmapPixelWriter.m_AMask & LODWORD(v30)) << (v59 & 0x1F);
          memcpy(dst: this->m_LightmapPixelWriter.m_pBits, src: v243, count: this->m_LightmapPixelWriter.m_Size);
        }
        else
        {
          v33 = float16::ConvertFloatTo16bitsNonDefault<0>(input: (float)color[0][0] * 0.000015258789);
          WORD1(v281) = float16::ConvertFloatTo16bitsNonDefault<0>(input: *(float *)&input);
          WORD2(v281) = float16::ConvertFloatTo16bitsNonDefault<0>(input: v295);
          v34 = float16::ConvertFloatTo16bitsNonDefault<0>(input: *(float *)&v278);
          m_RShift = this->m_LightmapPixelWriter.m_RShift;
          HIWORD(v281) = v34;
          *(_DWORD *)src = 0;
          v36 = this->m_LightmapPixelWriter.m_RMask;
          v271 = 0;
          v37 = m_RShift >> 4;
          v38 = (v33 & v36) << (m_RShift & 0xF);
          v39 = this->m_LightmapPixelWriter.m_GShift;
          *(_WORD *)&src[2 * v37] |= v38;
          v40 = v39;
          v41 = (WORD1(v281) & this->m_LightmapPixelWriter.m_GMask) << (v39 & 0xF);
          v42 = this->m_LightmapPixelWriter.m_BShift;
          *(_WORD *)&src[2 * (v40 >> 4)] |= v41;
          v43 = v42;
          v44 = (WORD2(v281) & this->m_LightmapPixelWriter.m_BMask) << (v42 & 0xF);
          v45 = this->m_LightmapPixelWriter.m_AShift;
          *(_WORD *)&src[2 * (v43 >> 4)] |= v44;
          v46 = v45;
          v47 = (HIWORD(v281) & this->m_LightmapPixelWriter.m_AMask) << (v45 & 0xF);
          v48 = this->m_LightmapPixelWriter.m_Size;
          *(_WORD *)&src[2 * (v46 >> 4)] |= v47;
          memcpy(dst: this->m_LightmapPixelWriter.m_pBits, src, count: v48);
          v13 = pFloatImagea;
        }
        this->m_LightmapPixelWriter.m_pBits += nLightmap0WriterSizeBytes;
        v60 = (float)color[1][1] * 0.000015258789;
        v61 = (float)color[1][2] * 0.000015258789;
        if ( (this->m_LightmapPixelWriter.m_nFlags & 2) != 0 )
        {
          v62 = float16::ConvertFloatTo16bitsNonDefault<0>(input: (float)color[1][0] * 0.000015258789);
          WORD1(v280) = float16::ConvertFloatTo16bitsNonDefault<0>(input: v60);
          WORD2(v280) = float16::ConvertFloatTo16bitsNonDefault<0>(input: v61);
          HIWORD(v280) = float16::ConvertFloatTo16bitsNonDefault<0>(input: pfmOuta);
          v267 = 0;
          v63 = this->m_LightmapPixelWriter.m_RMask;
          *(_DWORD *)v266 = 0;
          v64 = this->m_LightmapPixelWriter.m_GShift;
          *(_WORD *)&v266[2 * (this->m_LightmapPixelWriter.m_RShift >> 4)] |= (v62 & v63) << (this->m_LightmapPixelWriter.m_RShift
                                                                                            & 0xF);
          v65 = v64;
          v66 = (WORD1(v280) & this->m_LightmapPixelWriter.m_GMask) << (v64 & 0xF);
          v67 = this->m_LightmapPixelWriter.m_BShift;
          *(_WORD *)&v266[2 * (v65 >> 4)] |= v66;
          v68 = v67;
          v69 = (WORD2(v280) & this->m_LightmapPixelWriter.m_BMask) << (v67 & 0xF);
          v70 = this->m_LightmapPixelWriter.m_AShift;
          *(_WORD *)&v266[2 * (v68 >> 4)] |= v69;
          v71 = v70;
          v72 = (HIWORD(v280) & this->m_LightmapPixelWriter.m_AMask) << (v70 & 0xF);
          v73 = this->m_LightmapPixelWriter.m_Size;
          *(_WORD *)&v266[2 * (v71 >> 4)] |= v72;
          memcpy(dst: this->m_LightmapPixelWriter.m_pBits, src: v266, count: v73);
          v13 = pFloatImagea;
        }
        else
        {
          v74 = &v251[4 * (this->m_LightmapPixelWriter.m_RShift >> 5)];
          v75 = this->m_LightmapPixelWriter.m_RMask;
          v76 = this->m_LightmapPixelWriter.m_RShift & 0x1F;
          *(_DWORD *)v251 = 0;
          v252 = 0;
          v77 = (COERCE_UNSIGNED_INT((float)color[1][0] * 0.000015258789) & v75) << v76;
          v78 = this->m_LightmapPixelWriter.m_GShift;
          v253 = 0;
          v254 = 0;
          *(_DWORD *)v74 |= v77;
          v79 = v78;
          v80 = (this->m_LightmapPixelWriter.m_GMask & LODWORD(v60)) << (v78 & 0x1F);
          v81 = this->m_LightmapPixelWriter.m_BShift;
          *(_DWORD *)&v251[4 * (v79 >> 5)] |= v80;
          v82 = v81;
          v83 = (LODWORD(v61) & this->m_LightmapPixelWriter.m_BMask) << (v81 & 0x1F);
          v84 = this->m_LightmapPixelWriter.m_AShift;
          *(_DWORD *)&v251[4 * (v82 >> 5)] |= v83;
          *(_DWORD *)&v251[4 * (v84 >> 5)] |= (this->m_LightmapPixelWriter.m_AMask & LODWORD(pfmOuta)) << (v84 & 0x1F);
          memcpy(dst: this->m_LightmapPixelWriter.m_pBits, src: v251, count: this->m_LightmapPixelWriter.m_Size);
        }
        this->m_LightmapPixelWriter.m_pBits += nLightmap0WriterSizeBytes;
        v85 = (float)color[2][1] * 0.000015258789;
        v86 = (float)color[2][2] * 0.000015258789;
        if ( (this->m_LightmapPixelWriter.m_nFlags & 2) != 0 )
        {
          v87 = float16::ConvertFloatTo16bitsNonDefault<0>(input: (float)color[2][0] * 0.000015258789);
          WORD1(v277) = float16::ConvertFloatTo16bitsNonDefault<0>(input: v85);
          WORD2(v277) = float16::ConvertFloatTo16bitsNonDefault<0>(input: v86);
          HIWORD(v277) = float16::ConvertFloatTo16bitsNonDefault<0>(input: pfmOuta);
          v269 = 0;
          v88 = this->m_LightmapPixelWriter.m_RMask;
          *(_DWORD *)v268 = 0;
          v89 = this->m_LightmapPixelWriter.m_GShift;
          *(_WORD *)&v268[2 * (this->m_LightmapPixelWriter.m_RShift >> 4)] |= (v87 & v88) << (this->m_LightmapPixelWriter.m_RShift
                                                                                            & 0xF);
          v90 = v89;
          v91 = (WORD1(v277) & this->m_LightmapPixelWriter.m_GMask) << (v89 & 0xF);
          v92 = this->m_LightmapPixelWriter.m_BShift;
          *(_WORD *)&v268[2 * (v90 >> 4)] |= v91;
          v93 = v92;
          v94 = (WORD2(v277) & this->m_LightmapPixelWriter.m_BMask) << (v92 & 0xF);
          v95 = this->m_LightmapPixelWriter.m_AShift;
          *(_WORD *)&v268[2 * (v93 >> 4)] |= v94;
          v96 = v95;
          v97 = (HIWORD(v277) & this->m_LightmapPixelWriter.m_AMask) << (v95 & 0xF);
          v98 = this->m_LightmapPixelWriter.m_Size;
          *(_WORD *)&v268[2 * (v96 >> 4)] |= v97;
          memcpy(dst: this->m_LightmapPixelWriter.m_pBits, src: v268, count: v98);
          v13 = pFloatImagea;
        }
        else
        {
          v99 = &v247[4 * (this->m_LightmapPixelWriter.m_RShift >> 5)];
          v100 = this->m_LightmapPixelWriter.m_RMask;
          v101 = this->m_LightmapPixelWriter.m_RShift & 0x1F;
          *(_DWORD *)v247 = 0;
          v248 = 0;
          v102 = (COERCE_UNSIGNED_INT((float)color[2][0] * 0.000015258789) & v100) << v101;
          v103 = this->m_LightmapPixelWriter.m_GShift;
          v249 = 0;
          v250 = 0;
          *(_DWORD *)v99 |= v102;
          v104 = v103;
          v105 = (this->m_LightmapPixelWriter.m_GMask & LODWORD(v85)) << (v103 & 0x1F);
          v106 = this->m_LightmapPixelWriter.m_BShift;
          *(_DWORD *)&v247[4 * (v104 >> 5)] |= v105;
          v107 = v106;
          v108 = (LODWORD(v86) & this->m_LightmapPixelWriter.m_BMask) << (v106 & 0x1F);
          v109 = this->m_LightmapPixelWriter.m_AShift;
          *(_DWORD *)&v247[4 * (v107 >> 5)] |= v108;
          *(_DWORD *)&v247[4 * (v109 >> 5)] |= (this->m_LightmapPixelWriter.m_AMask & LODWORD(pfmOuta)) << (v109 & 0x1F);
          memcpy(dst: this->m_LightmapPixelWriter.m_pBits, src: v247, count: this->m_LightmapPixelWriter.m_Size);
        }
        this->m_LightmapPixelWriter.m_pBits += nLightmap0WriterSizeBytes;
        v110 = (float)color[3][1] * 0.000015258789;
        v111 = (float)color[3][2] * 0.000015258789;
        if ( (this->m_LightmapPixelWriter.m_nFlags & 2) != 0 )
        {
          v112 = float16::ConvertFloatTo16bitsNonDefault<0>(input: (float)color[3][0] * 0.000015258789);
          WORD1(v275) = float16::ConvertFloatTo16bitsNonDefault<0>(input: v110);
          WORD2(v275) = float16::ConvertFloatTo16bitsNonDefault<0>(input: v111);
          HIWORD(v275) = float16::ConvertFloatTo16bitsNonDefault<0>(input: pfmOuta);
          v285 = 0.0;
          v113 = this->m_LightmapPixelWriter.m_RMask;
          *(_DWORD *)&v284[4] = 0;
          v114 = this->m_LightmapPixelWriter.m_GShift;
          *(_WORD *)&v284[2 * (this->m_LightmapPixelWriter.m_RShift >> 4) + 4] |= (v112 & v113) << (this->m_LightmapPixelWriter.m_RShift
                                                                                                  & 0xF);
          v115 = v114;
          v116 = (WORD1(v275) & this->m_LightmapPixelWriter.m_GMask) << (v114 & 0xF);
          v117 = this->m_LightmapPixelWriter.m_BShift;
          *(_WORD *)&v284[2 * (v115 >> 4) + 4] |= v116;
          v118 = v117;
          v119 = (WORD2(v275) & this->m_LightmapPixelWriter.m_BMask) << (v117 & 0xF);
          v120 = this->m_LightmapPixelWriter.m_AShift;
          *(_WORD *)&v284[2 * (v118 >> 4) + 4] |= v119;
          v121 = v120;
          v122 = (HIWORD(v275) & this->m_LightmapPixelWriter.m_AMask) << (v120 & 0xF);
          v123 = this->m_LightmapPixelWriter.m_Size;
          *(_WORD *)&v284[2 * (v121 >> 4) + 4] |= v122;
          memcpy(dst: this->m_LightmapPixelWriter.m_pBits, src: &v284[4], count: v123);
          v13 = pFloatImagea;
        }
        else
        {
          v124 = (_DWORD *)(&pixelData.Red + (this->m_LightmapPixelWriter.m_RShift >> 5));
          v125 = this->m_LightmapPixelWriter.m_RMask;
          v126 = this->m_LightmapPixelWriter.m_RShift & 0x1F;
          memset(&pixelData, 0, sizeof(pixelData));
          v127 = (COERCE_UNSIGNED_INT((float)color[3][0] * 0.000015258789) & v125) << v126;
          v128 = this->m_LightmapPixelWriter.m_GShift;
          *v124 |= v127;
          v129 = v128;
          v130 = (this->m_LightmapPixelWriter.m_GMask & LODWORD(v110)) << (v128 & 0x1F);
          v131 = this->m_LightmapPixelWriter.m_BShift;
          *((_DWORD *)&pixelData.Red + (v129 >> 5)) |= v130;
          m_BMask = this->m_LightmapPixelWriter.m_BMask;
          v133 = v131;
          v265 = LODWORD(v111);
          v134 = (LODWORD(v111) & m_BMask) << (v131 & 0x1F);
          v135 = this->m_LightmapPixelWriter.m_AShift;
          *((_DWORD *)&pixelData.Red + (v133 >> 5)) |= v134;
          v259 = pfmOuta;
          *((_DWORD *)&pixelData.Red + (v135 >> 5)) |= (this->m_LightmapPixelWriter.m_AMask & LODWORD(pfmOuta)) << (v135 & 0x1F);
          memcpy(
            dst: this->m_LightmapPixelWriter.m_pBits,
            src: (unsigned __int8 *)&pixelData,
            count: this->m_LightmapPixelWriter.m_Size);
        }
        this->m_LightmapPixelWriter.m_pBits += nRewindToNextPixel;
        v13 += 4;
        v14 = v291 + 4;
        v11 = v283 == (float *)1;
        v283 = (float *)((char *)v283 - 1);
        pFloatImagea = v13;
        v291 += 4;
        if ( v11 )
          goto LABEL_30;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039F50
// Name: private: void CMatLightmaps::LightmapBitsToPixelWriter_HDRF(float __near *,int __near * const,int __near * const,class FloatBitMap_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatLightmaps::LightmapBitsToPixelWriter_HDRF(
        CMatLightmaps *this,
        float *pFloatImage,
        int *pLightmapSize,
        int *pOffsetIntoLightmapPage,
        FloatBitMap_t *pfmOut)
{
  float *v5; // ebx
  unsigned __int8 *v7; // ecx
  bool v8; // zf
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm3_4
  float input; // xmm0_4
  unsigned __int16 v13; // di
  unsigned __int16 v14; // bx
  unsigned __int16 v15; // ax
  int v16; // ecx
  int v17; // edx
  __int16 v18; // ax
  int v19; // ecx
  int v20; // edx
  __int16 v21; // ax
  int v22; // ecx
  int v23; // edx
  __int16 v24; // ax
  unsigned int m_Size; // ecx
  unsigned __int8 *v26; // eax
  unsigned int m_RMask; // edx
  char v28; // cl
  int v29; // edx
  int m_GShift; // ecx
  unsigned int m_GMask; // edx
  int v32; // eax
  int v33; // edx
  int m_BShift; // ecx
  int v35; // eax
  unsigned int v36; // edx
  int m_AShift; // ecx
  unsigned __int8 v38[4]; // [esp+10h] [ebp-44h] BYREF
  int v39; // [esp+14h] [ebp-40h]
  int v40; // [esp+18h] [ebp-3Ch]
  int v41; // [esp+1Ch] [ebp-38h]
  unsigned __int16 v42; // [esp+24h] [ebp-30h]
  unsigned __int16 v43; // [esp+26h] [ebp-2Eh]
  unsigned __int8 src[4]; // [esp+28h] [ebp-2Ch] BYREF
  int v45; // [esp+2Ch] [ebp-28h]
  float v46; // [esp+30h] [ebp-24h]
  float v47; // [esp+34h] [ebp-20h]
  float v48; // [esp+38h] [ebp-1Ch]
  float v49; // [esp+3Ch] [ebp-18h]
  float v50; // [esp+40h] [ebp-14h]
  float v51; // [esp+44h] [ebp-10h]
  float v52; // [esp+48h] [ebp-Ch]
  float *pSrc; // [esp+4Ch] [ebp-8h]
  int s; // [esp+50h] [ebp-4h]
  int t; // [esp+5Ch] [ebp+8h]

  v5 = pFloatImage;
  pSrc = pFloatImage;
  for ( t = 0; t < pLightmapSize[1]; ++t )
  {
    v7 = &this->m_LightmapPixelWriter.m_pBase[*pOffsetIntoLightmapPage * this->m_LightmapPixelWriter.m_Size
                                            + this->m_LightmapPixelWriter.m_BytesPerRow
                                            * (t + pOffsetIntoLightmapPage[1])];
    s = 0;
    for ( this->m_LightmapPixelWriter.m_pBits = v7; s < *pLightmapSize; pSrc = v5 )
    {
      v8 = (this->m_LightmapPixelWriter.m_nFlags & 2) == 0;
      v9 = v5[1];
      v10 = v5[2];
      v11 = v5[3];
      input = *v5;
      v52 = v9;
      v51 = v10;
      v50 = v11;
      if ( v8 )
      {
        v26 = &v38[4 * (this->m_LightmapPixelWriter.m_RShift >> 5)];
        m_RMask = this->m_LightmapPixelWriter.m_RMask;
        v28 = this->m_LightmapPixelWriter.m_RShift & 0x1F;
        v49 = input;
        *(_DWORD *)v38 = 0;
        v39 = 0;
        v29 = (LODWORD(input) & m_RMask) << v28;
        m_GShift = this->m_LightmapPixelWriter.m_GShift;
        v40 = 0;
        v41 = 0;
        *(_DWORD *)v26 |= v29;
        m_GMask = this->m_LightmapPixelWriter.m_GMask;
        v32 = m_GShift;
        v48 = v9;
        v47 = v10;
        v46 = v11;
        v33 = (LODWORD(v9) & m_GMask) << (m_GShift & 0x1F);
        m_BShift = this->m_LightmapPixelWriter.m_BShift;
        *(_DWORD *)&v38[4 * (v32 >> 5)] |= v33;
        v35 = m_BShift;
        v36 = (LODWORD(v47) & this->m_LightmapPixelWriter.m_BMask) << (m_BShift & 0x1F);
        m_AShift = this->m_LightmapPixelWriter.m_AShift;
        *(_DWORD *)&v38[4 * (v35 >> 5)] |= v36;
        *(_DWORD *)&v38[4 * (m_AShift >> 5)] |= (LODWORD(v46) & this->m_LightmapPixelWriter.m_AMask) << (m_AShift & 0x1F);
        memcpy(dst: this->m_LightmapPixelWriter.m_pBits, src: v38, count: this->m_LightmapPixelWriter.m_Size);
      }
      else
      {
        v13 = float16::ConvertFloatTo16bitsNonDefault<0>(input);
        v14 = float16::ConvertFloatTo16bitsNonDefault<0>(input: v52);
        v42 = float16::ConvertFloatTo16bitsNonDefault<0>(input: v51);
        v43 = float16::ConvertFloatTo16bitsNonDefault<0>(input: v50);
        v45 = 0;
        v15 = this->m_LightmapPixelWriter.m_RMask;
        *(_DWORD *)src = 0;
        v16 = this->m_LightmapPixelWriter.m_GShift;
        *(_WORD *)&src[2 * (this->m_LightmapPixelWriter.m_RShift >> 4)] |= (v13 & v15) << (this->m_LightmapPixelWriter.m_RShift
                                                                                         & 0xF);
        v17 = v16;
        v18 = (v14 & this->m_LightmapPixelWriter.m_GMask) << (v16 & 0xF);
        v19 = this->m_LightmapPixelWriter.m_BShift;
        *(_WORD *)&src[2 * (v17 >> 4)] |= v18;
        v20 = v19;
        v21 = (v42 & this->m_LightmapPixelWriter.m_BMask) << (v19 & 0xF);
        v22 = this->m_LightmapPixelWriter.m_AShift;
        *(_WORD *)&src[2 * (v20 >> 4)] |= v21;
        v23 = v22;
        v24 = (v43 & this->m_LightmapPixelWriter.m_AMask) << (v22 & 0xF);
        m_Size = this->m_LightmapPixelWriter.m_Size;
        *(_WORD *)&src[2 * (v23 >> 4)] |= v24;
        memcpy(dst: this->m_LightmapPixelWriter.m_pBits, src, count: m_Size);
        v5 = pSrc;
      }
      this->m_LightmapPixelWriter.m_pBits += this->m_LightmapPixelWriter.m_Size;
      v5 += 4;
      ++s;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003A1A0
// Name: private: void CMatLightmaps::LightmapBitsToPixelWriter_HDRI(float __near *,int __near * const,int __near * const,class FloatBitMap_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatLightmaps::LightmapBitsToPixelWriter_HDRI(
        CMatLightmaps *this,
        float *pFloatImage,
        int *pLightmapSize,
        int *pOffsetIntoLightmapPage,
        FloatBitMap_t *pfmOut)
{
  float *v6; // edi
  unsigned __int16 v7; // ax
  float in; // xmm0_4
  unsigned __int16 v9; // ax
  float v10; // xmm0_4
  unsigned __int16 v11; // ax
  float v12; // xmm1_4
  float v13; // xmm2_4
  bool v14; // zf
  float v15; // xmm0_4
  float v16; // xmm3_4
  unsigned __int16 v17; // di
  unsigned __int16 v18; // bx
  unsigned __int16 v19; // ax
  int m_RShift; // ecx
  _WORD *v21; // eax
  __int16 v22; // dx
  int v23; // ecx
  int v24; // eax
  __int16 v25; // dx
  int v26; // ecx
  int v27; // eax
  __int16 v28; // dx
  int v29; // ecx
  unsigned int m_RMask; // edx
  char v31; // cl
  _DWORD *v32; // eax
  int v33; // edx
  int m_GShift; // ecx
  int v35; // eax
  unsigned int v36; // edx
  int m_BShift; // ecx
  unsigned int m_BMask; // edx
  int v39; // eax
  int v40; // edx
  int m_AShift; // ecx
  float *v42; // eax
  unsigned __int8 *v43; // edx
  unsigned __int16 v44; // ax
  float v45; // xmm0_4
  int v46; // ebx
  unsigned __int16 v47; // ax
  int v48; // xmm1_4
  float v49; // xmm0_4
  unsigned __int8 m_Size; // al
  bool v51; // cf
  unsigned int m_GMask; // eax
  __int16 v53; // cx
  unsigned int v54; // eax
  unsigned int v55; // edx
  unsigned int v56; // edx
  unsigned int v57; // eax
  unsigned __int64 v58; // kr00_8
  unsigned __int64 v59; // rax
  __int16 v60; // cx
  int v61; // ebx
  int v62; // edi
  __int64 v63; // rax
  __int64 v64; // rax
  __int16 v65; // cx
  unsigned __int64 v66; // rax
  int v67; // ebx
  int v68; // edi
  PixRGBAF pixelData; // [esp+10h] [ebp-4Ch] BYREF
  unsigned __int16 v70; // [esp+22h] [ebp-3Ah]
  unsigned __int16 v71; // [esp+24h] [ebp-38h]
  int v72; // [esp+26h] [ebp-36h]
  _WORD src[4]; // [esp+2Ch] [ebp-30h] BYREF
  float v74; // [esp+34h] [ebp-28h]
  float v75; // [esp+38h] [ebp-24h]
  float v76; // [esp+3Ch] [ebp-20h]
  float v77; // [esp+40h] [ebp-1Ch]
  float v78; // [esp+44h] [ebp-18h]
  int a; // [esp+48h] [ebp-14h]
  int g; // [esp+4Ch] [ebp-10h]
  float *pSrc; // [esp+50h] [ebp-Ch]
  float input; // [esp+54h] [ebp-8h]
  float *v83; // [esp+58h] [ebp-4h]
  int b; // [esp+64h] [ebp+8h]
  int ba; // [esp+64h] [ebp+8h]
  int s; // [esp+70h] [ebp+14h]

  v6 = pFloatImage;
  if ( (this->m_LightmapPixelWriter.m_nFlags & 1) != 0 )
  {
    pSrc = pFloatImage;
    for ( b = 0; b < pLightmapSize[1]; ++b )
    {
      s = 0;
      for ( this->m_LightmapPixelWriter.m_pBits = &this->m_LightmapPixelWriter.m_pBase[*pOffsetIntoLightmapPage
                                                                                     * this->m_LightmapPixelWriter.m_Size
                                                                                     + this->m_LightmapPixelWriter.m_BytesPerRow
                                                                                     * (b + pOffsetIntoLightmapPage[1])];
            s < *pLightmapSize;
            pSrc = v6 )
      {
        v7 = ColorSpace::LinearFloatToCorrectedShort(in: *v6);
        in = v6[1];
        a = v7;
        v9 = ColorSpace::LinearFloatToCorrectedShort(in);
        v10 = v6[2];
        g = v9;
        v11 = ColorSpace::LinearFloatToCorrectedShort(in: v10);
        v12 = (float)g * 0.000015258789;
        v13 = (float)v11 * 0.000015258789;
        v14 = (this->m_LightmapPixelWriter.m_nFlags & 2) == 0;
        v15 = (float)a * 0.000015258789;
        v16 = v6[3];
        input = v12;
        *(float *)&v83 = v13;
        v78 = v16;
        if ( v14 )
        {
          m_RMask = this->m_LightmapPixelWriter.m_RMask;
          v31 = this->m_LightmapPixelWriter.m_RShift & 0x1F;
          v32 = (_DWORD *)(&pixelData.Red + (this->m_LightmapPixelWriter.m_RShift >> 5));
          v77 = (float)a * 0.000015258789;
          memset(&pixelData, 0, sizeof(pixelData));
          v33 = (LODWORD(v15) & m_RMask) << v31;
          m_GShift = this->m_LightmapPixelWriter.m_GShift;
          *v32 |= v33;
          v35 = m_GShift;
          v76 = v12;
          v36 = (this->m_LightmapPixelWriter.m_GMask & LODWORD(v12)) << (m_GShift & 0x1F);
          m_BShift = this->m_LightmapPixelWriter.m_BShift;
          *((_DWORD *)&pixelData.Red + (v35 >> 5)) |= v36;
          m_BMask = this->m_LightmapPixelWriter.m_BMask;
          v39 = m_BShift;
          v75 = v13;
          v40 = (LODWORD(v13) & m_BMask) << (m_BShift & 0x1F);
          m_AShift = this->m_LightmapPixelWriter.m_AShift;
          *((_DWORD *)&pixelData.Red + (v39 >> 5)) |= v40;
          v74 = v16;
          *((_DWORD *)&pixelData.Red + (m_AShift >> 5)) |= (this->m_LightmapPixelWriter.m_AMask & LODWORD(v16)) << (m_AShift & 0x1F);
          memcpy(
            dst: this->m_LightmapPixelWriter.m_pBits,
            src: (unsigned __int8 *)&pixelData,
            count: this->m_LightmapPixelWriter.m_Size);
        }
        else
        {
          v17 = float16::ConvertFloatTo16bitsNonDefault<0>(input: v15);
          v70 = float16::ConvertFloatTo16bitsNonDefault<0>(input);
          v18 = float16::ConvertFloatTo16bitsNonDefault<0>(input: *(float *)&v83);
          v71 = v18;
          v19 = float16::ConvertFloatTo16bitsNonDefault<0>(input: v78);
          m_RShift = this->m_LightmapPixelWriter.m_RShift;
          LOWORD(v72) = v19;
          memset(src, 0, sizeof(src));
          v21 = &src[m_RShift >> 4];
          v22 = (v17 & this->m_LightmapPixelWriter.m_RMask) << (m_RShift & 0xF);
          v23 = this->m_LightmapPixelWriter.m_GShift;
          *v21 |= v22;
          v24 = v23;
          v25 = (this->m_LightmapPixelWriter.m_GMask & v70) << (v23 & 0xF);
          v26 = this->m_LightmapPixelWriter.m_BShift;
          src[v24 >> 4] |= v25;
          v27 = v26;
          v28 = (v18 & this->m_LightmapPixelWriter.m_BMask) << (v26 & 0xF);
          v29 = this->m_LightmapPixelWriter.m_AShift;
          src[v27 >> 4] |= v28;
          src[v29 >> 4] |= (this->m_LightmapPixelWriter.m_AMask & (unsigned __int16)v72) << (v29 & 0xF);
          memcpy(
            dst: this->m_LightmapPixelWriter.m_pBits,
            (unsigned __int8 *)src,
            count: this->m_LightmapPixelWriter.m_Size);
          v6 = pSrc;
        }
        this->m_LightmapPixelWriter.m_pBits += this->m_LightmapPixelWriter.m_Size;
        v6 += 4;
        ++s;
      }
    }
  }
  else
  {
    v42 = nullptr;
    v83 = pFloatImage;
    for ( *(float *)&pSrc = 0.0; (int)v42 < pLightmapSize[1]; pSrc = v42 )
    {
      v43 = &this->m_LightmapPixelWriter.m_pBase[*pOffsetIntoLightmapPage * this->m_LightmapPixelWriter.m_Size
                                               + this->m_LightmapPixelWriter.m_BytesPerRow
                                               * ((_DWORD)v42 + pOffsetIntoLightmapPage[1])];
      input = 0.0;
      this->m_LightmapPixelWriter.m_pBits = v43;
      if ( *pLightmapSize > 0 )
      {
        do
        {
          v44 = ColorSpace::LinearFloatToCorrectedShort(in: *v6);
          v45 = v6[1];
          g = v44;
          v46 = ColorSpace::LinearFloatToCorrectedShort(in: v45);
          v47 = ColorSpace::LinearFloatToCorrectedShort(in: v6[2]);
          *(float *)&v48 = 65535.0;
          v74 = v6[3];
          v49 = v74 * 65536.0;
          ba = v47;
          if ( (float)(v74 * 65536.0) >= 65535.0 || (*(float *)&v48 = 0.0, v49 <= 0.0) )
            v49 = *(float *)&v48;
          m_Size = this->m_LightmapPixelWriter.m_Size;
          a = (unsigned __int16)(int)v49;
          if ( m_Size != 0 )
          {
            v51 = m_Size < 5u;
            m_GMask = this->m_LightmapPixelWriter.m_GMask;
            if ( v51 )
            {
              v53 = this->m_LightmapPixelWriter.m_BShift;
              v54 = ((g & this->m_LightmapPixelWriter.m_RMask) << LOBYTE(this->m_LightmapPixelWriter.m_RShift))
                  | ((v46 & m_GMask) << LOBYTE(this->m_LightmapPixelWriter.m_GShift));
              v55 = ba & this->m_LightmapPixelWriter.m_BMask;
              if ( v53 <= 0 )
                v56 = v55 >> -(char)v53;
              else
                v56 = v55 << v53;
              v57 = v56
                  | ((a & this->m_LightmapPixelWriter.m_AMask) << LOBYTE(this->m_LightmapPixelWriter.m_AShift))
                  | v54;
              switch ( this->m_LightmapPixelWriter.m_Size )
              {
                case 1u:
                  *this->m_LightmapPixelWriter.m_pBits = v57;
                  break;
                case 2u:
                  *(_WORD *)this->m_LightmapPixelWriter.m_pBits = v57;
                  break;
                case 3u:
                  *(_WORD *)this->m_LightmapPixelWriter.m_pBits = v57;
                  this->m_LightmapPixelWriter.m_pBits[2] = BYTE2(v57);
                  break;
                case 4u:
                  *(_DWORD *)this->m_LightmapPixelWriter.m_pBits = v57;
                  break;
                default:
                  break;
              }
            }
            else
            {
              v58 = (unsigned __int64)(v46 & m_GMask) << this->m_LightmapPixelWriter.m_GShift;
              v59 = (unsigned __int64)(g & this->m_LightmapPixelWriter.m_RMask) << this->m_LightmapPixelWriter.m_RShift;
              v60 = this->m_LightmapPixelWriter.m_BShift;
              v61 = v59 | v58;
              LODWORD(v63) = ba & this->m_LightmapPixelWriter.m_BMask;
              v62 = HIDWORD(v59) | HIDWORD(v58);
              HIDWORD(v63) = 0;
              if ( v60 <= 0 )
                v64 = v63 >> -(char)v60;
              else
                v64 = v63 << v60;
              v65 = this->m_LightmapPixelWriter.m_AShift;
              *(_QWORD *)src = v64;
              v66 = (unsigned __int64)(a & this->m_LightmapPixelWriter.m_AMask) << v65;
              v67 = *(_DWORD *)src | v66 | v61;
              v68 = *(_DWORD *)&src[2] | HIDWORD(v66) | v62;
              if ( this->m_LightmapPixelWriter.m_Size == 6 )
              {
                *(_DWORD *)this->m_LightmapPixelWriter.m_pBits = v67;
                *((_WORD *)this->m_LightmapPixelWriter.m_pBits + 2) = v68;
              }
              else if ( this->m_LightmapPixelWriter.m_Size == 8 )
              {
                *(_DWORD *)this->m_LightmapPixelWriter.m_pBits = v67;
                *((_DWORD *)this->m_LightmapPixelWriter.m_pBits + 1) = v68;
              }
              v6 = v83;
            }
          }
          this->m_LightmapPixelWriter.m_pBits += this->m_LightmapPixelWriter.m_Size;
          if ( pfmOut != nullptr )
          {
            *(_QWORD *)&pixelData.Red = *(_QWORD *)v6;
            pixelData.Blue = v6[2];
            pixelData.Alpha = v74;
            FloatBitMap_t::WritePixelRGBAF(
              this: pfmOut,
              x: LODWORD(input) + *pOffsetIntoLightmapPage,
              y: (int)pSrc + pOffsetIntoLightmapPage[1],
              z: 0,
              value: pixelData);
          }
          v6 += 4;
          ++LODWORD(input);
          v83 = v6;
        }
        while ( SLODWORD(input) < *pLightmapSize );
        v42 = pSrc;
      }
      v42 = (float *)((char *)v42 + 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003A6F0
// Name: public: void CMatLightmaps::UpdateLightmap(int,int __near * const,int __near * const,float __near *,float __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatLightmaps::UpdateLightmap(
        CMatLightmaps *this,
        int lightmapPageID,
        int *lightmapSize,
        int *offsetIntoLightmapPage,
        float *pFloatImage,
        float *pFloatImageBump1,
        float *pFloatImageBump2,
        float *pFloatImageBump3)
{
  bool v10; // cl
  FloatBitMap_t *v11; // eax
  FloatBitMap_t *v12; // eax
  FloatBitMap_t *v13; // ecx
  int *p_uSize; // edi
  int (*GetHDRType)(void); // edx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int uSize; // [esp+1Ch] [ebp-1Ch] BYREF
  int v21; // [esp+20h] [ebp-18h]
  FloatBitMap_t *pfmOut; // [esp+24h] [ebp-14h]
  bool hasBump; // [esp+2Bh] [ebp-Dh]
  int v24; // [esp+34h] [ebp-4h]
  bool bDynamic_3; // [esp+43h] [ebp+Bh]
  char bDynamic_3a; // [esp+43h] [ebp+Bh]

  hasBump = false;
  v21 = 1;
  pfmOut = nullptr;
  if ( pFloatImageBump1 != nullptr && pFloatImageBump2 != nullptr && pFloatImageBump3 != nullptr )
  {
    hasBump = true;
    v21 = 4;
  }
  if ( lightmapPageID >= this->m_NumLightmapPages || lightmapPageID < 0 )
  {
    _Error(a1: "MaterialSystem_Interface_t::UpdateLightmap lightmapPageID=%d out of range\n", lightmapPageID);
    return;
  }
  v10 = lightmapPageID >= this->m_firstDynamicLightmap;
  bDynamic_3 = v10;
  if ( v10 )
    this->m_dynamic.currentDynamicIndex = 0;
  if ( mat_lightmap_pfms.m_pParent != nullptr && mat_lightmap_pfms.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( this->m_pLightmapDataPtrArray[lightmapPageID] == nullptr )
    {
      v11 = (FloatBitMap_t *)MemAlloc_Alloc(nSize: 0x324u);
      pfmOut = v11;
      v24 = 0;
      if ( v11 != nullptr )
        v12 = FloatBitMap_t::FloatBitMap_t(
                this: v11,
                nWidth: this->m_pLightmapPages[lightmapPageID].m_Width,
                nHeight: this->m_pLightmapPages[lightmapPageID].m_Height,
                nDepth: 1,
                nAttributeMask: 15);
      else
        v12 = nullptr;
      this->m_pLightmapDataPtrArray[lightmapPageID] = v12;
      v13 = this->m_pLightmapDataPtrArray[lightmapPageID];
      v24 = -1;
      FloatBitMap_t::Clear(this: v13, r: 0.0, g: 0.0, b: 0.0, a: 1.0);
      v10 = bDynamic_3;
    }
    pfmOut = this->m_pLightmapDataPtrArray[lightmapPageID];
  }
  if ( this->m_nUpdatingLightmapsStackDepth > 0 || v10 )
  {
    bDynamic_3a = 0;
    if ( lightmapPageID == this->m_nLockedLightmap || CMatLightmaps::LockLightmap(this, lightmap: lightmapPageID) )
    {
      p_uSize = offsetIntoLightmapPage;
LABEL_28:
      uSize = 0;
      v21 = 0;
      GetHDRType = (int (*)(void))g_pHWConfig->GetHDRType;
      if ( hasBump )
      {
        v16 = GetHDRType();
        if ( v16 != 0 )
        {
          v17 = v16 - 1;
          if ( v17 != 0 )
          {
            if ( v17 == 1 )
            {
              if ( bDynamic_3a != 0 )
                p_uSize = &uSize;
              CMatLightmaps::BumpedLightmapBitsToPixelWriter_HDRF(
                this,
                pFloatImage,
                pFloatImageBump1,
                pFloatImageBump2,
                pFloatImageBump3,
                pLightmapSize: lightmapSize,
                pOffsetIntoLightmapPage: p_uSize,
                pfmOut);
            }
          }
          else
          {
            if ( bDynamic_3a != 0 )
              p_uSize = &uSize;
            CMatLightmaps::BumpedLightmapBitsToPixelWriter_HDRI(
              this,
              pFloatImage,
              pFloatImageBump1,
              pFloatImageBump2,
              pFloatImageBump3,
              pLightmapSize: lightmapSize,
              pOffsetIntoLightmapPage: p_uSize,
              pfmOut);
          }
        }
        else
        {
          if ( bDynamic_3a != 0 )
            p_uSize = &uSize;
          CMatLightmaps::BumpedLightmapBitsToPixelWriter_LDR(
            this,
            pFloatImage,
            pFloatImageBump1,
            pFloatImageBump2,
            pFloatImageBump3,
            pLightmapSize: lightmapSize,
            pOffsetIntoLightmapPage: p_uSize,
            pfmOut);
        }
      }
      else
      {
        v18 = GetHDRType();
        if ( v18 != 0 )
        {
          v19 = v18 - 1;
          if ( v19 != 0 )
          {
            if ( v19 == 1 )
            {
              if ( bDynamic_3a != 0 )
                p_uSize = &uSize;
              CMatLightmaps::LightmapBitsToPixelWriter_HDRF(
                this,
                pFloatImage,
                pLightmapSize: lightmapSize,
                pOffsetIntoLightmapPage: p_uSize,
                pfmOut);
            }
          }
          else
          {
            if ( bDynamic_3a != 0 )
              p_uSize = &uSize;
            CMatLightmaps::LightmapBitsToPixelWriter_HDRI(
              this,
              pFloatImage,
              pLightmapSize: lightmapSize,
              pOffsetIntoLightmapPage: p_uSize,
              pfmOut);
          }
        }
        else
        {
          if ( bDynamic_3a != 0 )
            p_uSize = &uSize;
          CMatLightmaps::LightmapBitsToPixelWriter_LDR(
            this,
            pFloatImage,
            pLightmapSize: lightmapSize,
            pOffsetIntoLightmapPage: p_uSize,
            pfmOut);
        }
      }
      if ( bDynamic_3a != 0 )
        g_pShaderAPI->TexUnlock(this: g_pShaderAPI);
      return;
    }
    if ( _executeCount_1 < 10 )
    {
      ++_executeCount_1;
      _Warning(a1: "Failed to lock lightmap\n");
    }
  }
  else
  {
    bDynamic_3a = 1;
    if ( (_S2 & 1) == 0 )
    {
      _S2 |= 1u;
      counter_0.m_pCounter = CVProfile::FindOrCreateCounter(
                               this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                               a2: "lightmap subrect texlock",
                               a3: COUNTER_GROUP_DEFAULT);
      atexit(func: CMatLightmaps::UpdateLightmap_::_23_::_dynamic_atexit_destructor_for___counter__);
      v24 = -1;
    }
    ++*counter_0.m_pCounter;
    g_pShaderAPI->ModifyTexture(
      this: g_pShaderAPI,
      a2: this->m_LightmapPageTextureHandles.m_Memory.m_pMemory[lightmapPageID]);
    p_uSize = offsetIntoLightmapPage;
    if ( g_pShaderAPI->TexLock(
           this: g_pShaderAPI,
           a2: 0,
           a3: 0,
           a4: *offsetIntoLightmapPage,
           a5: offsetIntoLightmapPage[1],
           a6: v21 * *lightmapSize,
           a7: lightmapSize[1],
           a8: &this->m_LightmapPixelWriter) )
    {
      goto LABEL_28;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003AAE0
// Name: private: void CMatLightmaps::EnumerateMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatLightmaps::EnumerateMaterials(CMatLightmaps *this)
{
  int v2; // edi
  unsigned __int16 i; // si
  int v4; // ecx

  v2 = 0;
  for ( i = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::FirstInorder(this: (CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl*)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short> > *)((char *)this - 64));
        i != 0xFFFF;
        i = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::NextInorder(
              this: (CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl*)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short> > *)((char *)this - 64),
              i) )
  {
    v4 = *(_DWORD *)(*((_DWORD *)this - 15) + 16 * i + 8);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 224))(a1: v4, a2: v2++);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003AB40
// Name: public: void CMatLightmaps::ResetMaterialLightmapPageInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatLightmaps::ResetMaterialLightmapPageInfo(CMatLightmaps *this)
{
  unsigned __int16 i; // di
  int v3; // esi

  for ( i = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::FirstInorder(this: (CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl*)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short> > *)((char *)this - 64));
        i != 0xFFFF;
        i = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::NextInorder(
              this: (CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl*)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short> > *)((char *)this - 64),
              i) )
  {
    v3 = *(_DWORD *)(*((_DWORD *)this - 15) + 16 * i + 8);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 252))(a1: v3, a2: 9999);
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 256))(a1: v3, a2: -9999);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 228))(a1: v3, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003ABC0
// Name: private: void CMatLightmaps::ComputeSortInfo(struct MaterialSystem_SortInfo_t __near *,int __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatLightmaps::ComputeSortInfo(
        CMatLightmaps *this,
        MaterialSystem_SortInfo_t *pInfo,
        int *sortId,
        bool alpha)
{
  CMatLightmaps *v4; // esi
  unsigned __int16 Inorder; // ax
  int v6; // esi
  int v7; // ebx
  int j; // ebx
  unsigned __int16 i; // [esp+8h] [ebp-4h]

  v4 = this;
  Inorder = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::FirstInorder(this: (CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl*)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short> > *)((char *)this - 64));
  for ( i = Inorder; Inorder != 0xFFFF; i = Inorder )
  {
    v6 = *(_DWORD *)(v4[-1].m_dynamic.imagePackers[0].m_pLightmapWavefront[2040] + 16 * Inorder + 8);
    v7 = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 264))(a1: v6);
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 260))(a1: v6) <= v7 )
    {
      for ( j = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 260))(a1: v6);
            j <= (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 264))(a1: v6);
            ++j )
      {
        pInfo[*sortId].material = (IMaterial *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 372))(a1: v6);
        pInfo[(*sortId)++].lightmapPageID = j;
      }
    }
    v4 = this;
    Inorder = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::NextInorder(
                this: (CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl*)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short> > *)((char *)this - 64),
                i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003ACA0
// Name: private: void CMatLightmaps::ComputeWhiteLightmappedSortInfo(struct MaterialSystem_SortInfo_t __near *,int __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatLightmaps::ComputeWhiteLightmappedSortInfo(
        CMatLightmaps *this,
        MaterialSystem_SortInfo_t *pInfo,
        int *sortId,
        bool alpha)
{
  CMatLightmaps *v4; // esi
  unsigned __int16 Inorder; // bx
  int v6; // esi

  v4 = this;
  Inorder = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::FirstInorder(this: (CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl*)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short> > *)((char *)this - 64));
  if ( Inorder != 0xFFFF )
  {
    while ( 1 )
    {
      v6 = *(_DWORD *)(v4[-1].m_dynamic.imagePackers[0].m_pLightmapWavefront[2040] + 16 * Inorder + 8);
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 232))(a1: v6) != 0
        && (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 220))(a1: v6) > 0 )
      {
        pInfo[*sortId].material = (IMaterial *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 372))(a1: v6);
        if ( (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)v6 + 128))(a1: v6, a2: 3) != 0 )
          pInfo[*sortId].lightmapPageID = -2;
        else
          pInfo[*sortId].lightmapPageID = -1;
        ++*sortId;
      }
      Inorder = CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl *)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short>>::NextInorder(
                  this: (CUtlRBTree<CMaterialDict::MaterialLookup_t,unsigned short,bool (__cdecl*)(CMaterialDict::MaterialLookup_t const &,CMaterialDict::MaterialLookup_t const &),CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MaterialLookup_t,unsigned short>,unsigned short> > *)((char *)this - 64),
                  i: Inorder);
      if ( Inorder == 0xFFFF )
        break;
      v4 = this;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003AD70
// Name: public: void CMatLightmaps::GetSortInfo(struct MaterialSystem_SortInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatLightmaps::GetSortInfo(CMatLightmaps *this, MaterialSystem_SortInfo_t *pSortInfoArray)
{
  int sortId; // [esp+8h] [ebp-4h] BYREF

  sortId = 0;
  CMatLightmaps::ComputeSortInfo(this, pInfo: pSortInfoArray, &sortId, alpha: false);
  CMatLightmaps::ComputeWhiteLightmappedSortInfo(this, pInfo: pSortInfoArray, &sortId, alpha: false);
}

//------------------------------------------------------------------------------
// Address: 0x1003AE40
// Name: public: CMatLightmaps::CMatLightmaps(void)
// Source: json
//------------------------------------------------------------------------------
CMatLightmaps *__thiscall CMatLightmaps::CMatLightmaps(CMatLightmaps *this)
{
  this->m_ImagePackers.m_Memory.m_pMemory = nullptr;
  this->m_ImagePackers.m_Memory.m_nAllocationCount = 0;
  this->m_ImagePackers.m_Memory.m_nGrowSize = 0;
  this->m_ImagePackers.m_Size = 0;
  this->m_ImagePackers.m_pElements = nullptr;
  this->m_LightmapPageTextureHandles.m_Memory.m_pMemory = nullptr;
  this->m_LightmapPageTextureHandles.m_Memory.m_nAllocationCount = 0;
  this->m_LightmapPageTextureHandles.m_Memory.m_nGrowSize = 0;
  this->m_LightmapPageTextureHandles.m_Size = 0;
  this->m_LightmapPageTextureHandles.m_pElements = nullptr;
  this->m_currentWhiteLightmapMaterial = nullptr;
  this->m_pLightmapPages = nullptr;
  this->m_NumLightmapPages = 0;
  this->m_numSortIDs = 0;
  this->m_nUpdatingLightmapsStackDepth = 0;
  this->m_pLightmapDataPtrArray = nullptr;
  this->m_eLightmapsState = STATE_DEFAULT;
  this->m_nLockedLightmap = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1003AEB0
// Name: public: void CMatLightmaps::BeginLightmapAllocation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatLightmaps::BeginLightmapAllocation(CMatLightmaps *this)
{
  int m_nAllocationCount; // eax
  CImagePacker *m_pMemory; // ecx
  int v4; // eax
  int v5; // ebx
  int v6; // edi
  char *v7; // eax

  CMatLightmaps::CleanupLightmaps(this);
  m_nAllocationCount = this->m_ImagePackers.m_Memory.m_nAllocationCount;
  this->m_ImagePackers.m_Size = 0;
  if ( m_nAllocationCount < 1 )
    CUtlMemory<CImagePacker,int>::Grow(this: &this->m_ImagePackers.m_Memory, num: 1 - m_nAllocationCount);
  ++this->m_ImagePackers.m_Size;
  m_pMemory = this->m_ImagePackers.m_Memory.m_pMemory;
  v4 = this->m_ImagePackers.m_Size - 1;
  this->m_ImagePackers.m_pElements = this->m_ImagePackers.m_Memory.m_pMemory;
  if ( v4 > 0 )
    _V_memmove(dest: &m_pMemory[1], src: m_pMemory, count: 8220 * v4);
  v5 = 256;
  if ( g_pHWConfig->MaxTextureHeight(this: g_pHWConfig) < 256 )
    v5 = g_pHWConfig->MaxTextureHeight(this: g_pHWConfig);
  v6 = 512;
  if ( g_pHWConfig->MaxTextureWidth(this: g_pHWConfig) < 512 )
    v6 = g_pHWConfig->MaxTextureWidth(this: g_pHWConfig);
  CImagePacker::Reset(
    this: this->m_ImagePackers.m_Memory.m_pMemory,
    nSortId: 0,
    maxLightmapWidth: v6,
    maxLightmapHeight: v5);
  v7 = (char *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( v7 == nullptr )
    v7 = (char *)this + 8420;
  (*(void (__thiscall **)(char *, _DWORD))(*(_DWORD *)v7 + 816))(a1: v7, a2: 0);
  this->m_currentWhiteLightmapMaterial = nullptr;
  this->m_numSortIDs = 0;
  CMatLightmaps::ResetMaterialLightmapPageInfo(this);
  CMatLightmaps::EnumerateMaterials(this);
}

//------------------------------------------------------------------------------
// Address: 0x1003AF90
// Name: public: int CMatLightmaps::AllocateLightmap(int,int,int __near * const,class IMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CMatLightmaps::AllocateLightmap@<eax>(
        CMatLightmaps *this@<ecx>,
        int a2@<edi>,
        int width,
        int height,
        int *offsetIntoLightmapPage,
        IMaterial *iMaterial)
{
  int v8; // eax
  int m_Size; // edi
  void *(__thiscall *v10)(GenericThreadLocals::CThreadLocalBase *__hidden); // ebx
  char *v11; // eax
  int v12; // edi
  int v13; // ebx
  char *v14; // eax
  char *v15; // ecx
  char *v16; // ecx
  int v17; // eax
  char *v18; // eax
  int v19; // eax
  int v20; // edi
  int v21; // edi
  int m_nAllocationCount; // eax
  CImagePacker *m_pMemory; // ecx
  int v24; // eax
  int v25; // eax
  int v26; // edi
  CImagePacker *v27; // ecx
  int v29; // edi
  char *v30; // ecx
  int v31; // eax
  int v32; // [esp-8h] [ebp-10h]
  int i; // [esp+4h] [ebp-4h]
  int ia; // [esp+4h] [ebp-4h]
  int heighta; // [esp+14h] [ebp+Ch]
  int nPackCount; // [esp+1Ch] [ebp+14h]
  int nPackCounta; // [esp+1Ch] [ebp+14h]

  if ( iMaterial != nullptr )
  {
    v32 = a2;
    v8 = ((int (__thiscall *)(IMaterial *))iMaterial->__vftable[1].Refresh)(a1: iMaterial);
    m_Size = this->m_ImagePackers.m_Size;
    v10 = GenericThreadLocals::CThreadLocalBase::Get;
    i = v8;
    nPackCount = m_Size;
    v11 = (char *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
    if ( v11 == nullptr )
      v11 = (char *)this + 8420;
    if ( (*(int (__thiscall **)(char *))(*(_DWORD *)v11 + 820))(a1: v11) != i )
    {
      v12 = m_Size - 2;
      if ( v12 >= 0 )
      {
        v13 = v12;
        nPackCount += -1 - v12;
        do
        {
          if ( this->m_ImagePackers.m_Size - v12 - 1 > 0 )
            _V_memmove(
              dest: &this->m_ImagePackers.m_Memory.m_pMemory[v13],
              src: &this->m_ImagePackers.m_Memory.m_pMemory[v13 + 1],
              count: 8220 * (this->m_ImagePackers.m_Size - v12 - 1));
          --this->m_ImagePackers.m_Size;
          --v13;
          --v12;
        }
        while ( v12 >= 0 );
        v10 = GenericThreadLocals::CThreadLocalBase::Get;
      }
      v14 = (char *)v10(this: &CMaterialSystem::m_pRenderContext);
      if ( v14 == nullptr )
        v14 = (char *)this + 8420;
      if ( (*(int (__thiscall **)(char *))(*(_DWORD *)v14 + 820))(a1: v14) != 0 )
      {
        ++this->m_ImagePackers.m_Memory.m_pMemory->m_nSortID;
        ++this->m_numSortIDs;
      }
      v15 = (char *)v10(this: &CMaterialSystem::m_pRenderContext);
      if ( v15 == nullptr )
        v15 = (char *)this + 8420;
      (*(void (__thiscall **)(char *, int))(*(_DWORD *)v15 + 816))(a1: v15, a2: i);
      v16 = (char *)v10(this: &CMaterialSystem::m_pRenderContext);
      if ( v16 == nullptr )
        v16 = (char *)this + 8420;
      v17 = (*(int (__thiscall **)(char *))(*(_DWORD *)v16 + 820))(a1: v16);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v17 + 252))(a1: v17, a2: this->m_NumLightmapPages);
      v18 = (char *)v10(this: &CMaterialSystem::m_pRenderContext);
      if ( v18 == nullptr )
        v18 = (char *)this + 8420;
      v19 = (*(int (__thiscall **)(char *))(*(_DWORD *)v18 + 820))(a1: v18);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v19 + 256))(a1: v19, a2: this->m_NumLightmapPages);
      m_Size = nPackCount;
    }
    ia = 0;
    if ( m_Size <= 0 )
    {
LABEL_27:
      v21 = this->m_ImagePackers.m_Size;
      m_nAllocationCount = this->m_ImagePackers.m_Memory.m_nAllocationCount;
      ++this->m_numSortIDs;
      if ( v21 + 1 > m_nAllocationCount )
        CUtlMemory<CImagePacker,int>::Grow(this: &this->m_ImagePackers.m_Memory, num: v21 - m_nAllocationCount + 1);
      ++this->m_ImagePackers.m_Size;
      m_pMemory = this->m_ImagePackers.m_Memory.m_pMemory;
      v24 = this->m_ImagePackers.m_Size - v21 - 1;
      this->m_ImagePackers.m_pElements = this->m_ImagePackers.m_Memory.m_pMemory;
      if ( v24 > 0 )
        _V_memmove(dest: &m_pMemory[v21 + 1], src: &m_pMemory[v21], count: 8220 * v24);
      ia = v21;
      nPackCounta = 256;
      if ( ((int (__thiscall *)(IHardwareConfigInternal *, int))g_pHWConfig->MaxTextureHeight)(a1: g_pHWConfig, a2: v32) < 256 )
        nPackCounta = g_pHWConfig->MaxTextureHeight(this: g_pHWConfig);
      if ( g_pHWConfig->MaxTextureWidth(this: g_pHWConfig) >= 512 )
        v25 = 512;
      else
        v25 = g_pHWConfig->MaxTextureWidth(this: g_pHWConfig);
      v26 = v21;
      CImagePacker::Reset(
        this: &this->m_ImagePackers.m_Memory.m_pMemory[v26],
        nSortId: this->m_numSortIDs,
        maxLightmapWidth: v25,
        maxLightmapHeight: nPackCounta);
      v27 = this->m_ImagePackers.m_Memory.m_pMemory;
      ++this->m_NumLightmapPages;
      if ( !CImagePacker::AddBlock(
              this: &v27[v26],
              width,
              height,
              returnX: offsetIntoLightmapPage,
              returnY: offsetIntoLightmapPage + 1) )
      {
        heighta = 256;
        if ( g_pHWConfig->MaxTextureHeight(this: g_pHWConfig) < 256 )
          heighta = g_pHWConfig->MaxTextureHeight(this: g_pHWConfig);
        v29 = 512;
        if ( g_pHWConfig->MaxTextureWidth(this: g_pHWConfig) < 512 )
          v29 = g_pHWConfig->MaxTextureWidth(this: g_pHWConfig);
        _Error(
          a1: "MaterialSystem_Interface_t::AllocateLightmap: lightmap (%dx%d) too big to fit in page (%dx%d)\n",
          width,
          height,
          v29,
          heighta);
      }
      v30 = (char *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
      if ( v30 == nullptr )
        v30 = (char *)this + 8420;
      v31 = (*(int (__thiscall **)(char *))(*(_DWORD *)v30 + 820))(a1: v30);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v31 + 256))(a1: v31, a2: this->m_NumLightmapPages);
    }
    else
    {
      v20 = 0;
      while ( !CImagePacker::AddBlock(
                 this: &this->m_ImagePackers.m_Memory.m_pMemory[v20],
                 width,
                 height,
                 returnX: offsetIntoLightmapPage,
                 returnY: offsetIntoLightmapPage + 1) )
      {
        ++v20;
        if ( ++ia >= nPackCount )
          goto LABEL_27;
      }
    }
    return this->m_ImagePackers.m_Memory.m_pMemory[ia].m_nSortID;
  }
  else
  {
    _Warning(a1: "Programming error: CMatRenderContext::AllocateLightmap: NULL material\n");
    return this->m_numSortIDs;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003B2D0
// Name: public: void CMatLightmaps::BeginUpdateLightmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatLightmaps::BeginUpdateLightmaps(CMatLightmaps *this)
{
  char *v2; // ecx
  CMatCallQueue *v3; // eax

  v2 = (char *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( v2 == nullptr )
    v2 = (char *)this + 8420;
  v3 = (CMatCallQueue *)(*(int (__thiscall **)(char *))(*(_DWORD *)v2 + 912))(a1: v2);
  if ( v3 != nullptr )
    CMatCallQueue::QueueCall<CMatLightmaps *,CMatLightmaps,void>(
      this: v3,
      pObject: this,
      pfnProxied: (unsigned int)CMatLightmaps::BeginUpdateLightmaps);
  else
    ++this->m_nUpdatingLightmapsStackDepth;
}

//------------------------------------------------------------------------------
// Address: 0x1003B350
// Name: public: void CMatLightmaps::EndUpdateLightmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatLightmaps::EndUpdateLightmaps(CMatLightmaps *this)
{
  char *v2; // ecx
  CMatCallQueue *v3; // eax

  v2 = (char *)GenericThreadLocals::CThreadLocalBase::Get(this: &CMaterialSystem::m_pRenderContext);
  if ( v2 == nullptr )
    v2 = (char *)this + 8420;
  v3 = (CMatCallQueue *)(*(int (__thiscall **)(char *))(*(_DWORD *)v2 + 912))(a1: v2);
  if ( v3 != nullptr )
  {
    CMatCallQueue::QueueCall<CMatLightmaps *,CMatLightmaps,void>(
      this: v3,
      pObject: this,
      pfnProxied: (unsigned int)CMatLightmaps::EndUpdateLightmaps);
  }
  else if ( --this->m_nUpdatingLightmapsStackDepth <= 0 && this->m_nLockedLightmap != -1 )
  {
    g_pShaderAPI->TexUnlock(this: g_pShaderAPI);
    this->m_nLockedLightmap = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003B3F0
// Name: private: void CMatLightmaps::AllocateLightmapTexture(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatLightmaps::AllocateLightmapTexture(CMatLightmaps *this, ImageFormat lightmap)
{
  bool (__thiscall *PreferDynamicTextures)(struct IHardwareConfigInternal *); // edx
  HDRType_t v5; // eax
  int m_Height; // edx
  __int32 v7; // eax
  CMatLightmaps::LightmapsState m_eLightmapsState; // eax
  int (__thiscall *CreateTexture)(IShaderAPI *, int, int, int, ImageFormat, int, int, int, const char *, const char *); // eax
  int *m_pMemory; // esi
  char debugName[256]; // [esp+Ch] [ebp-114h] BYREF
  CMatLightmaps *v12; // [esp+10Ch] [ebp-14h]
  int iWidth; // [esp+110h] [ebp-10h]
  int iHeight; // [esp+114h] [ebp-Ch]
  int flags; // [esp+118h] [ebp-8h]
  bool bUseDynamicTextures; // [esp+11Fh] [ebp-1h]
  ImageFormat imageFormat; // [esp+128h] [ebp+8h]

  PreferDynamicTextures = g_pHWConfig->PreferDynamicTextures;
  v12 = this;
  if ( PreferDynamicTextures(this: g_pHWConfig)
    && mat_dynamiclightmaps.m_pParent != nullptr
    && mat_dynamiclightmaps.m_pParent->m_Value.m_nValue != 0 )
  {
    bUseDynamicTextures = true;
    flags = 16;
  }
  else
  {
    bUseDynamicTextures = false;
    flags = 4;
  }
  if ( this->m_LightmapPageTextureHandles.m_Size < lightmap + 1 )
    CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int>>::InsertMultipleBefore(
      this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&this->m_LightmapPageTextureHandles,
      elem: this->m_LightmapPageTextureHandles.m_Size,
      num: lightmap + 1 - this->m_LightmapPageTextureHandles.m_Size);
  V_snprintf(pDest: debugName, maxLen: 256, pFormat: "[lightmap %d]", lightmap);
  v5 = g_pHWConfig->GetHDRType(this: g_pHWConfig);
  m_Height = 1;
  if ( v5 != HDR_TYPE_NONE )
  {
    v7 = v5 - 1;
    if ( v7 == 0 )
    {
      imageFormat = IMAGE_FORMAT_RGBA16161616;
      goto LABEL_14;
    }
    if ( v7 == 1 )
    {
      imageFormat = IMAGE_FORMAT_RGBA16161616F;
      goto LABEL_14;
    }
  }
  flags |= 0x20000u;
  imageFormat = IMAGE_FORMAT_RGBA8888;
LABEL_14:
  m_eLightmapsState = this->m_eLightmapsState;
  if ( m_eLightmapsState != STATE_DEFAULT )
  {
    if ( m_eLightmapsState == STATE_RELEASED )
      DevMsg(
        a1: "AllocateLightmapTexture(%d) in released lightmap state (STATE_RELEASED), delayed till \"Restore\".\n",
        lightmap);
    else
      _Warning(
        a1: "AllocateLightmapTexture(%d) in unknown lightmap state (%d), skipped.\n",
        lightmap,
        this->m_eLightmapsState);
  }
  else
  {
    if ( lightmap == -3 )
    {
      iWidth = 1;
    }
    else
    {
      if ( (unsigned int)lightmap < 0xFFFFFFFE )
        iWidth = this->m_pLightmapPages[lightmap].m_Width;
      else
        iWidth = 1;
      if ( (unsigned int)lightmap <= 0xFFFFFFFD )
        m_Height = this->m_pLightmapPages[lightmap].m_Height;
    }
    CreateTexture = g_pShaderAPI->CreateTexture;
    m_pMemory = this->m_LightmapPageTextureHandles.m_Memory.m_pMemory;
    iHeight = m_Height;
    m_pMemory[lightmap] = CreateTexture(
                            this: g_pShaderAPI,
                            a2: iWidth,
                            a3: m_Height,
                            a4: 1,
                            a5: imageFormat,
                            a6: 1,
                            a7: 1,
                            a8: flags,
                            a9: debugName,
                            a10: "Lightmaps");
    g_pShaderAPI->ModifyTexture(this: g_pShaderAPI, a2: v12->m_LightmapPageTextureHandles.m_Memory.m_pMemory[lightmap]);
    g_pShaderAPI->TexMinFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
    g_pShaderAPI->TexMagFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
    if ( !bUseDynamicTextures )
      g_pShaderAPI->TexSetPriority(this: g_pShaderAPI, a2: 1);
    CMatLightmaps::InitLightmapBits(this: v12, a2: lightmap, a3: (int)m_pMemory, lightmap);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003B5E0
// Name: public: void CMatLightmaps::RestoreLightmapPages(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatLightmaps::RestoreLightmapPages(CMatLightmaps *this)
{
  CMatLightmaps *v1; // esi
  CMatLightmaps::LightmapsState m_eLightmapsState; // ecx
  int v3; // edi
  CUtlMemory<S3RGBA,int> *p_m_LightmapPageTextureHandles; // ebx
  S3RGBA *m_pMemory; // ecx
  int v6; // eax
  int v7; // esi
  S3RGBA *v8; // edi
  int m_nAllocationCount; // ecx
  S3RGBA *v10; // ecx
  int v11; // eax
  HDRType_t v12; // eax
  __int32 v13; // eax
  CMatLightmaps::LightmapsState v14; // eax
  int v15; // esi
  int v16; // edi
  char pDest[256]; // [esp+4h] [ebp-120h] BYREF
  int v18; // [esp+104h] [ebp-20h]
  int m_Height; // [esp+108h] [ebp-1Ch]
  ImageFormat v20; // [esp+10Ch] [ebp-18h]
  CMatLightmaps *v21; // [esp+110h] [ebp-14h]
  int v22; // [esp+114h] [ebp-10h]
  int m_Width; // [esp+118h] [ebp-Ch]
  int i; // [esp+11Ch] [ebp-8h]
  char v25; // [esp+123h] [ebp-1h]

  v1 = this;
  m_eLightmapsState = this->m_eLightmapsState;
  v21 = v1;
  if ( m_eLightmapsState != STATE_RELEASED )
  {
    _Warning(
      a1: "RestoreLightmapPages is expected in STATE_RELEASED, current state = %d, discarded.\n",
      m_eLightmapsState);
    return;
  }
  v1->m_eLightmapsState = STATE_DEFAULT;
  if ( CMatPaintmaps::IsEnabled(this: (CMatPaintmaps *)&v1[1]) )
    CMatPaintmaps::RestorePaintmaps(this: (CMatPaintmaps *)&v1[1], nNumLightmaps: v1->m_NumLightmapPages);
  v3 = 0;
  i = 0;
  if ( v1->m_NumLightmapPages > 0 )
  {
    p_m_LightmapPageTextureHandles = (CUtlMemory<S3RGBA,int> *)&v1->m_LightmapPageTextureHandles;
    while ( 1 )
    {
      if ( g_pHWConfig->PreferDynamicTextures(this: g_pHWConfig)
        && mat_dynamiclightmaps.m_pParent != nullptr
        && mat_dynamiclightmaps.m_pParent->m_Value.m_nValue != 0 )
      {
        v25 = 1;
        v22 = 16;
      }
      else
      {
        v25 = 0;
        v22 = 4;
      }
      m_pMemory = p_m_LightmapPageTextureHandles[1].m_pMemory;
      v6 = v3 + 1;
      v18 = v3 + 1;
      if ( (int)m_pMemory < v3 + 1 )
      {
        v7 = v6 - (_DWORD)m_pMemory;
        v8 = m_pMemory;
        if ( (S3RGBA *)v6 != m_pMemory )
        {
          m_nAllocationCount = p_m_LightmapPageTextureHandles->m_nAllocationCount;
          m_Width = (int)v8 + v7;
          if ( (int)v8 + v7 > m_nAllocationCount )
            CUtlMemory<IMaterialVar *,int>::Grow(
              this: p_m_LightmapPageTextureHandles,
              num: (int)v8 + v7 - m_nAllocationCount);
          p_m_LightmapPageTextureHandles[1].m_pMemory = (S3RGBA *)((char *)p_m_LightmapPageTextureHandles[1].m_pMemory
                                                                 + v7);
          v10 = p_m_LightmapPageTextureHandles->m_pMemory;
          v11 = (char *)p_m_LightmapPageTextureHandles[1].m_pMemory - (char *)v8 - v7;
          p_m_LightmapPageTextureHandles[1].m_nAllocationCount = (int)p_m_LightmapPageTextureHandles->m_pMemory;
          if ( v11 > 0 && v7 > 0 )
            _V_memmove(dest: &v10[m_Width], src: &v10[(_DWORD)v8], count: 4 * v11);
        }
        v3 = i;
        v1 = v21;
      }
      V_snprintf(pDest, maxLen: 256, pFormat: "[lightmap %d]", v3);
      v12 = g_pHWConfig->GetHDRType(this: g_pHWConfig);
      if ( v12 != HDR_TYPE_NONE )
      {
        v13 = v12 - 1;
        if ( v13 == 0 )
        {
          v20 = IMAGE_FORMAT_RGBA16161616;
          goto LABEL_27;
        }
        if ( v13 == 1 )
        {
          v20 = IMAGE_FORMAT_RGBA16161616F;
          goto LABEL_27;
        }
      }
      v22 |= 0x20000u;
      v20 = IMAGE_FORMAT_RGBA8888;
LABEL_27:
      v14 = v1->m_eLightmapsState;
      if ( v14 != STATE_DEFAULT )
      {
        if ( v14 == STATE_RELEASED )
          DevMsg(
            a1: "AllocateLightmapTexture(%d) in released lightmap state (STATE_RELEASED), delayed till \"Restore\".\n",
            v3);
        else
          _Warning(
            a1: "AllocateLightmapTexture(%d) in unknown lightmap state (%d), skipped.\n",
            v3,
            v1->m_eLightmapsState);
        goto LABEL_42;
      }
      if ( v3 == -3 )
      {
        m_Width = 1;
LABEL_38:
        m_Height = 1;
        goto LABEL_39;
      }
      if ( (unsigned int)(v3 + 2) > 1 )
        m_Width = v1->m_pLightmapPages[v3].m_Width;
      else
        m_Width = 1;
      if ( (unsigned int)(v3 + 2) <= 1 )
        goto LABEL_38;
      m_Height = v1->m_pLightmapPages[v3].m_Height;
LABEL_39:
      v15 = (int)p_m_LightmapPageTextureHandles->m_pMemory;
      v16 = v3;
      *(_DWORD *)(v15 + v16 * 4) = g_pShaderAPI->CreateTexture(
                                     this: g_pShaderAPI,
                                     a2: m_Width,
                                     a3: m_Height,
                                     a4: 1,
                                     a5: v20,
                                     a6: 1,
                                     a7: 1,
                                     a8: v22,
                                     a9: pDest,
                                     a10: "Lightmaps");
      g_pShaderAPI->ModifyTexture(this: g_pShaderAPI, a2: *(_DWORD *)&p_m_LightmapPageTextureHandles->m_pMemory[v16]);
      g_pShaderAPI->TexMinFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
      g_pShaderAPI->TexMagFilter(this: g_pShaderAPI, a2: SHADER_TEXFILTERMODE_LINEAR);
      if ( v25 == 0 )
        g_pShaderAPI->TexSetPriority(this: g_pShaderAPI, a2: 1);
      CMatLightmaps::InitLightmapBits(this: v21, a2: (int)p_m_LightmapPageTextureHandles, a3: v15, lightmap: i);
      v1 = v21;
LABEL_42:
      i = v18;
      if ( v18 >= v1->m_NumLightmapPages )
        return;
      v3 = i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003B880
// Name: public: void CMatLightmaps::EndLightmapAllocation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatLightmaps::EndLightmapAllocation(CMatLightmaps *this)
{
  int v2; // eax
  ImageFormat v3; // edi
  int m_NumLightmapPages; // eax
  CMatPaintmaps *v5; // ebx
  int v6; // eax
  int *m_pMemory; // edx
  int *v8; // eax
  int v9; // edx
  bool v10; // bl
  unsigned __int16 v11; // ax
  int (__thiscall *MaxTextureWidth)(struct IHardwareConfigInternal *); // edx
  unsigned __int16 v13; // ax
  __int16 v14; // bx
  int m_Height; // ecx
  int m_Width; // eax
  unsigned int v17; // [esp-4h] [ebp-20h]
  int lastLightmapPageHeight; // [esp+Ch] [ebp-10h] BYREF
  int v19; // [esp+10h] [ebp-Ch]
  int lastLightmapPageWidth; // [esp+14h] [ebp-8h] BYREF
  CMatPaintmaps *v21; // [esp+18h] [ebp-4h]

  v2 = ++this->m_NumLightmapPages;
  ++this->m_numSortIDs;
  this->m_firstDynamicLightmap = v2;
  v3 = IMAGE_FORMAT_RGBA8888;
  this->m_dynamic.lightmapLocked = -1;
  this->m_dynamic.frameID = 0;
  this->m_dynamic.currentDynamicIndex = 0;
  this->m_dynamic.lightmapLockFrame[0] = 0;
  CImagePacker::GetMinimumDimensions(
    this: &this->m_ImagePackers.m_Memory.m_pMemory[this->m_ImagePackers.m_Size - 1],
    pReturnWidth: &lastLightmapPageWidth,
    pReturnHeight: &lastLightmapPageHeight);
  this->m_ImagePackers.m_Size = 0;
  if ( this->m_ImagePackers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_ImagePackers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ImagePackers.m_Memory.m_pMemory);
      this->m_ImagePackers.m_Memory.m_pMemory = nullptr;
    }
    this->m_ImagePackers.m_Memory.m_nAllocationCount = 0;
  }
  m_NumLightmapPages = this->m_NumLightmapPages;
  this->m_ImagePackers.m_pElements = this->m_ImagePackers.m_Memory.m_pMemory;
  this->m_pLightmapPages = (CMatLightmaps::LightmapPageInfo_t *)MemAlloc_Alloc(
                                                                  nSize: (unsigned __int64)(unsigned int)m_NumLightmapPages >> 29 != 0
                                                                ? -1
                                                                : 8 * m_NumLightmapPages);
  if ( mat_lightmap_pfms.m_pParent != nullptr && mat_lightmap_pfms.m_pParent->m_Value.m_nValue != 0 )
    this->m_pLightmapDataPtrArray = (FloatBitMap_t **)MemAlloc_Alloc(
                                                        nSize: (unsigned __int64)(unsigned int)this->m_NumLightmapPages >> 30 != 0
                                                      ? -1
                                                      : 4 * this->m_NumLightmapPages);
  v5 = (CMatPaintmaps *)(this + 1);
  v21 = (CMatPaintmaps *)(this + 1);
  if ( CMatPaintmaps::IsEnabled(this: (CMatPaintmaps *)(this + 1)) )
    CMatPaintmaps::BeginPaintTextureAllocation(
      this: (CMatPaintmaps *)(this + 1),
      iPaintmapCount: this->m_NumLightmapPages);
  v6 = this->m_NumLightmapPages;
  if ( this->m_LightmapPageTextureHandles.m_Memory.m_nAllocationCount < v6
    && this->m_LightmapPageTextureHandles.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_LightmapPageTextureHandles.m_Memory.m_pMemory;
    this->m_LightmapPageTextureHandles.m_Memory.m_nAllocationCount = v6;
    v17 = 4 * v6;
    if ( m_pMemory != nullptr )
    {
      v8 = (int *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v17);
      v5 = v21;
    }
    else
    {
      v8 = (int *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v17);
    }
    this->m_LightmapPageTextureHandles.m_Memory.m_pMemory = v8;
  }
  this->m_LightmapPageTextureHandles.m_pElements = this->m_LightmapPageTextureHandles.m_Memory.m_pMemory;
  if ( this->m_NumLightmapPages > 0 )
  {
    do
    {
      v9 = this->m_firstDynamicLightmap - 1;
      v10 = v3 == v9;
      if ( v3 == v9 )
      {
        v11 = lastLightmapPageWidth;
      }
      else
      {
        MaxTextureWidth = g_pHWConfig->MaxTextureWidth;
        v19 = 512;
        if ( MaxTextureWidth(this: g_pHWConfig) >= 512 )
          v11 = v19;
        else
          v11 = g_pHWConfig->MaxTextureWidth(this: g_pHWConfig);
      }
      this->m_pLightmapPages[v3].m_Width = v11;
      if ( v10 )
      {
        v13 = lastLightmapPageHeight;
      }
      else
      {
        v14 = 256;
        if ( g_pHWConfig->MaxTextureHeight(this: g_pHWConfig) < 256 )
          v14 = g_pHWConfig->MaxTextureHeight(this: g_pHWConfig);
        v13 = v14;
      }
      this->m_pLightmapPages[v3].m_Height = v13;
      this->m_pLightmapPages[v3].m_Flags = 0;
      CMatLightmaps::AllocateLightmapTexture(this, lightmap: v3);
      v5 = v21;
      if ( CMatPaintmaps::IsEnabled(this: v21) )
      {
        if ( v3 == -3 )
        {
          m_Height = 1;
          m_Width = 1;
        }
        else
        {
          if ( (unsigned int)(v3 + 2) > 1 )
            m_Height = this->m_pLightmapPages[v3].m_Height;
          else
            m_Height = 1;
          if ( (unsigned int)(v3 + 2) > 1 )
            m_Width = this->m_pLightmapPages[v3].m_Width;
          else
            m_Width = 1;
        }
        CMatPaintmaps::AllocatePaintmap(this: v5, paintmap: v3, iWidth: m_Width, iHeight: m_Height);
      }
      if ( mat_lightmap_pfms.m_pParent != nullptr && mat_lightmap_pfms.m_pParent->m_Value.m_nValue != 0 )
        this->m_pLightmapDataPtrArray[v3] = nullptr;
      ++v3;
    }
    while ( v3 < this->m_NumLightmapPages );
  }
  if ( CMatPaintmaps::IsEnabled(this: v5) )
    CDummyMaterialSystem::EndBatch();
}

//------------------------------------------------------------------------------
// Address: 0x1028C5D0
// Name: _CMatLightmaps::LockLightmap_::_4_::_dynamic_atexit_destructor_for___counter__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMatLightmaps::LockLightmap_::_4_::_dynamic_atexit_destructor_for___counter__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1028C5E0
// Name: _CMatLightmaps::UpdateLightmap_::_23_::_dynamic_atexit_destructor_for___counter__
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMatLightmaps::UpdateLightmap_::_23_::_dynamic_atexit_destructor_for___counter__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1028C5F0
// Name: _dynamic_atexit_destructor_for__mat_dynamicPaintmaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_dynamicPaintmaps__()
{
  ConVar::~ConVar(this: &mat_dynamicPaintmaps);
}

//------------------------------------------------------------------------------
// Address: 0x1028C600
// Name: _dynamic_atexit_destructor_for__mat_report_queue_status__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mat_report_queue_status__()
{
  ConVar::~ConVar(this: &mat_report_queue_status);
}
