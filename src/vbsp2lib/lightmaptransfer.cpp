// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vbsp2lib/lightmaptransfer.cpp
// Functions: 10
// ============================================================

#include "vbsp2lib\lightmaptransfer.h"

//------------------------------------------------------------------------------
// Address: 0x0041A5D0
// Name: CalculateLuxelToWorldTransform
// Source: json
//------------------------------------------------------------------------------
void __usercall CalculateLuxelToWorldTransform(
        const Vector *vFaceNormal@<ecx>,
        Vector *pLuxelOrigin@<esi>,
        Vector *pS@<edi>,
        Vector *pT@<edx>,
        const texinfo_s *pTexInfo,
        float flFaceDistance)
{
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm4_4
  float v9; // xmm1_4
  float v10; // xmm3_4
  float v11; // xmm0_4
  float v12; // xmm0_4

  v6 = (float)(pTexInfo->lightmapVecsLuxelsPerWorldUnits[0][2] * pTexInfo->lightmapVecsLuxelsPerWorldUnits[1][1])
     - (float)(pTexInfo->lightmapVecsLuxelsPerWorldUnits[0][1] * pTexInfo->lightmapVecsLuxelsPerWorldUnits[1][2]);
  v7 = pTexInfo->lightmapVecsLuxelsPerWorldUnits[0][0];
  v8 = (float)(pTexInfo->lightmapVecsLuxelsPerWorldUnits[1][0] * pTexInfo->lightmapVecsLuxelsPerWorldUnits[0][1])
     - (float)(v7 * pTexInfo->lightmapVecsLuxelsPerWorldUnits[1][1]);
  v9 = (float)(v7 * pTexInfo->lightmapVecsLuxelsPerWorldUnits[1][2])
     - (float)(pTexInfo->lightmapVecsLuxelsPerWorldUnits[1][0] * pTexInfo->lightmapVecsLuxelsPerWorldUnits[0][2]);
  v10 = -(float)((float)((float)(vFaceNormal->y * v9) + (float)(vFaceNormal->x * v6)) + (float)(vFaceNormal->z * v8));
  if ( COERCE_FLOAT(LODWORD(v10) & _mask__AbsFloat_) >= 0.000001 )
  {
    pS->x = (float)((float)(vFaceNormal->z * pTexInfo->lightmapVecsLuxelsPerWorldUnits[1][1])
                  - (float)(vFaceNormal->y * pTexInfo->lightmapVecsLuxelsPerWorldUnits[1][2]))
          * (float)(1.0 / v10);
    pT->x = (float)((float)(vFaceNormal->y * pTexInfo->lightmapVecsLuxelsPerWorldUnits[0][2])
                  - (float)(vFaceNormal->z * pTexInfo->lightmapVecsLuxelsPerWorldUnits[0][1]))
          * (float)(1.0 / v10);
    pLuxelOrigin->x = -(float)((float)(v6 * flFaceDistance) * (float)(1.0 / v10));
    pS->y = (float)((float)(pTexInfo->lightmapVecsLuxelsPerWorldUnits[1][2] * vFaceNormal->x)
                  - (float)(vFaceNormal->z * pTexInfo->lightmapVecsLuxelsPerWorldUnits[1][0]))
          * (float)(1.0 / v10);
    pT->y = (float)((float)(vFaceNormal->z * pTexInfo->lightmapVecsLuxelsPerWorldUnits[0][0])
                  - (float)(vFaceNormal->x * pTexInfo->lightmapVecsLuxelsPerWorldUnits[0][2]))
          * (float)(1.0 / v10);
    pLuxelOrigin->y = -(float)((float)(v9 * flFaceDistance) * (float)(1.0 / v10));
    pS->z = (float)((float)(vFaceNormal->y * pTexInfo->lightmapVecsLuxelsPerWorldUnits[1][0])
                  - (float)(vFaceNormal->x * pTexInfo->lightmapVecsLuxelsPerWorldUnits[1][1]))
          * (float)(1.0 / v10);
    pT->z = (float)((float)(vFaceNormal->x * pTexInfo->lightmapVecsLuxelsPerWorldUnits[0][1])
                  - (float)(vFaceNormal->y * pTexInfo->lightmapVecsLuxelsPerWorldUnits[0][0]))
          * (float)(1.0 / v10);
    pLuxelOrigin->z = -(float)((float)(v8 * flFaceDistance) * (float)(1.0 / v10));
    v11 = -pTexInfo->lightmapVecsLuxelsPerWorldUnits[0][3];
    pLuxelOrigin->x = (float)(pS->x * v11) + pLuxelOrigin->x;
    pLuxelOrigin->y = (float)(pS->y * v11) + pLuxelOrigin->y;
    pLuxelOrigin->z = (float)(pS->z * v11) + pLuxelOrigin->z;
    v12 = -pTexInfo->lightmapVecsLuxelsPerWorldUnits[1][3];
    pLuxelOrigin->x = (float)(pT->x * v12) + pLuxelOrigin->x;
    pLuxelOrigin->y = (float)(pT->y * v12) + pLuxelOrigin->y;
    pLuxelOrigin->z = (float)(pT->z * v12) + pLuxelOrigin->z;
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
      _LoggingSystem_Log(
        a1: LOG_VBSP2,
        a2: 1,
        a3: "Warning - UV vectors are parallel to face normal, bad lighting will be produced.\n");
    *pLuxelOrigin = vec3_origin;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A840
// Name: public: void CUtlMemory<struct CLuxelHash::LuxelHashEntry_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CLuxelHash::LuxelHashEntry_t,int>::Grow(CUtlMemory<MapBrush_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  MapBrush_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 36 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (MapBrush_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (MapBrush_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A8E0
// Name: private: bool CLuxelHash::FindLuxel(class Vector const __near &,class Vector const __near &,struct ColorRGBExp32 const __near * __near *,int __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CLuxelHash::FindLuxel(
        CLuxelHash *this,
        const Vector *vPosition,
        const Vector *vNormal,
        const ColorRGBExp32 **ppLuxelData,
        int *pDataLength)
{
  int m_nNextEntryIndex; // eax
  CLuxelHash::LuxelHashEntry_t *m_pMemory; // edi
  int v7; // eax
  float x; // xmm4_4
  CLuxelHash::LuxelHashEntry_t *v9; // eax

  m_nNextEntryIndex = this->m_UniformGrid.m_Memory.m_pMemory[(unsigned int)((int)(float)(vPosition->x + 0.001)
                                                                          + 389 * (int)(float)(vPosition->z + 0.001)
                                                                          + 193 * (int)(float)(vPosition->y + 0.001))
                                                           % this->m_UniformGrid.m_Size];
  if ( m_nNextEntryIndex == -1 )
    return 0;
  m_pMemory = this->m_HashEntries.m_Memory.m_pMemory;
  while ( 1 )
  {
    v7 = m_nNextEntryIndex;
    x = m_pMemory[v7].m_vPosition.x;
    v9 = &m_pMemory[v7];
    if ( fabs(x - vPosition->x) <= 0.001
      && fabs(v9->m_vPosition.y - vPosition->y) <= 0.001
      && fabs(v9->m_vPosition.z - vPosition->z) <= 0.001
      && (float)((float)((float)(v9->m_vNormal.y * vNormal->y) + (float)(vNormal->x * v9->m_vNormal.x))
               + (float)(v9->m_vNormal.z * vNormal->z)) > 0.89999998 )
    {
      break;
    }
    m_nNextEntryIndex = v9->m_nNextEntryIndex;
    if ( m_nNextEntryIndex == -1 )
      return 0;
  }
  *ppLuxelData = &this->m_LuxelData.m_Memory.m_pMemory[v9->m_nDataStart];
  *pDataLength = v9->m_nDataLength;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041AA10
// Name: ComputeFacePlane
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeFacePlane(int nFace@<edi>, Vector *p0@<esi>, CMemoryBSPFile *pBSPFile, Vector *pNormal)
{
  int planenum; // eax
  int v5; // edx
  dplane_t *m_pMemory; // eax
  double x; // st7
  dplane_t *v8; // eax
  Vector v0; // [esp+4h] [ebp-Ch] BYREF

  if ( CMemoryBSPFile::TryGetFaceVertex(this: pBSPFile, nFace, nVertexIndex: 0, pPosition: &v0) != 0 )
  {
    *p0 = v0;
    planenum = pBSPFile->m_FaceList.m_Memory.m_pMemory[nFace].planenum;
    if ( planenum < pBSPFile->m_Planes.m_Size )
    {
      v5 = planenum;
      m_pMemory = pBSPFile->m_Planes.m_Memory.m_pMemory;
      x = m_pMemory[v5].normal.x;
      v8 = &m_pMemory[v5];
      pNormal->x = x;
      pNormal->y = v8->normal.y;
      pNormal->z = v8->normal.z;
      return;
    }
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Unable to get normal of face %d.\n", nFace);
  }
  else
  {
    if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
      _LoggingSystem_Log(a1: LOG_VBSP2, a2: 3, a3: "Unable to get position of vertex 0 on source face %d.\n", nFace);
    *p0 = vec3_invalid;
  }
  *pNormal = vec3_invalid;
}

//------------------------------------------------------------------------------
// Address: 0x0041AC00
// Name: public: CLuxelHash::CLuxelHash(int)
// Source: json
//------------------------------------------------------------------------------
CLuxelHash *__thiscall CLuxelHash::CLuxelHash(CLuxelHash *this, int nHashBucketCount)
{
  int v3; // ecx

  v3 = nHashBucketCount;
  this->m_LuxelData.m_Memory.m_pMemory = nullptr;
  this->m_LuxelData.m_Memory.m_nAllocationCount = 0;
  this->m_LuxelData.m_Memory.m_nGrowSize = 0;
  this->m_LuxelData.m_Size = 0;
  this->m_LuxelData.m_pElements = nullptr;
  this->m_HashEntries.m_Memory.m_pMemory = nullptr;
  this->m_HashEntries.m_Memory.m_nAllocationCount = 0;
  this->m_HashEntries.m_Memory.m_nGrowSize = 0;
  this->m_HashEntries.m_Size = 0;
  this->m_HashEntries.m_pElements = nullptr;
  this->m_WorldLightsLDR.m_Memory.m_pMemory = nullptr;
  this->m_WorldLightsLDR.m_Memory.m_nAllocationCount = 0;
  this->m_WorldLightsLDR.m_Memory.m_nGrowSize = 0;
  this->m_WorldLightsLDR.m_Size = 0;
  this->m_WorldLightsLDR.m_pElements = nullptr;
  this->m_WorldLightsHDR.m_Memory.m_pMemory = nullptr;
  this->m_WorldLightsHDR.m_Memory.m_nAllocationCount = 0;
  this->m_WorldLightsHDR.m_Memory.m_nGrowSize = 0;
  this->m_WorldLightsHDR.m_Size = 0;
  this->m_WorldLightsHDR.m_pElements = nullptr;
  this->m_UniformGrid.m_Memory.m_pMemory = nullptr;
  this->m_UniformGrid.m_Memory.m_nAllocationCount = 0;
  this->m_UniformGrid.m_Memory.m_nGrowSize = 0;
  this->m_UniformGrid.m_Size = 0;
  this->m_UniformGrid.m_pElements = nullptr;
  if ( nHashBucketCount <= 1 )
    v3 = 1;
  this->m_UniformGrid.m_Size = 0;
  CUtlVector<dedge_t,CUtlMemory<dedge_t,int>>::InsertMultipleBefore(
    this: (CUtlVector<CPhysCollide *,CUtlMemory<CPhysCollide *,int> > *)&this->m_UniformGrid,
    elem: 0,
    num: v3);
  memset(
    dst: (unsigned __int8 *)this->m_UniformGrid.m_Memory.m_pMemory,
    value: 0xFFu,
    count: 4 * this->m_UniformGrid.m_Size);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0041AC90
// Name: private: void CLuxelHash::AddLuxel(class Vector const __near &,class Vector const __near &,struct ColorRGBExp32 const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLuxelHash::AddLuxel(
        CLuxelHash *this,
        const Vector *vPosition,
        const Vector *vNormal,
        CBSPFace *const *pLuxelData,
        int nDataLength)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CLuxelHash::LuxelHashEntry_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // edi
  int nOldEntry; // [esp+Ch] [ebp-8h]
  unsigned int nGridEntry; // [esp+10h] [ebp-4h]

  m_nAllocationCount = this->m_HashEntries.m_Memory.m_nAllocationCount;
  m_Size = this->m_HashEntries.m_Size;
  nGridEntry = (unsigned int)((int)(float)(vPosition->x + 0.001)
                            + 389 * (int)(float)(vPosition->z + 0.001)
                            + 193 * (int)(float)(vPosition->y + 0.001))
             % this->m_UniformGrid.m_Size;
  nOldEntry = this->m_UniformGrid.m_Memory.m_pMemory[nGridEntry];
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CLuxelHash::LuxelHashEntry_t,int>::Grow(
      this: (CUtlMemory<MapBrush_t,int> *)&this->m_HashEntries,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_HashEntries.m_Size;
  m_pMemory = this->m_HashEntries.m_Memory.m_pMemory;
  v9 = this->m_HashEntries.m_Size - m_Size - 1;
  this->m_HashEntries.m_pElements = m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 36 * v9);
  this->m_UniformGrid.m_Memory.m_pMemory[nGridEntry] = m_Size;
  v10 = m_Size;
  this->m_HashEntries.m_Memory.m_pMemory[v10].m_vPosition = *vPosition;
  this->m_HashEntries.m_Memory.m_pMemory[v10].m_vNormal = *vNormal;
  this->m_HashEntries.m_Memory.m_pMemory[v10].m_nDataStart = this->m_LuxelData.m_Size;
  this->m_HashEntries.m_Memory.m_pMemory[v10].m_nDataLength = nDataLength;
  CUtlVector<ColorRGBExp32,CUtlMemory<ColorRGBExp32,int>>::InsertMultipleBefore(
    (CUtlVector<CBSPFace *,CUtlMemory<CBSPFace *,int> > *)this,
    elem: this->m_LuxelData.m_Size,
    num: nDataLength,
    pToInsert: pLuxelData);
  this->m_HashEntries.m_Memory.m_pMemory[v10].m_nNextEntryIndex = nOldEntry;
}

//------------------------------------------------------------------------------
// Address: 0x0041ADC0
// Name: private: void CLuxelHash::CopyFaceLighting(class CMemoryBSPFile __near *,int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLuxelHash::CopyFaceLighting(CLuxelHash *this, CMemoryBSPFile *pTargetBSPFile, int nFace)
{
  dface_t *v4; // esi
  texinfo_s *m_pMemory; // ecx
  bool v6; // zf
  const texinfo_s *v7; // eax
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *p_m_LightingData; // ebx
  int v9; // ecx
  int m_nAllocationCount; // eax
  unsigned __int8 *v11; // edx
  int v12; // eax
  int v13; // eax
  float v14; // xmm3_4
  const texinfo_s *v15; // esi
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm0_4
  int v19; // edi
  float v20; // xmm0_4
  float v21; // xmm1_4
  int v22; // edx
  const ColorRGBExp32 *v23; // edi
  int m_Size; // esi
  int v25; // eax
  unsigned __int8 *v26; // ecx
  int v27; // eax
  unsigned __int8 *v28; // eax
  int v29; // esi
  int v30; // eax
  unsigned __int8 *v31; // ecx
  int v32; // eax
  unsigned __int8 *v33; // eax
  int v34; // esi
  int v35; // eax
  unsigned __int8 *v36; // ecx
  int v37; // eax
  unsigned __int8 *v38; // eax
  int v39; // esi
  int v40; // eax
  unsigned __int8 *v41; // ecx
  int v42; // eax
  unsigned __int8 *v43; // eax
  int lightofs; // esi
  ColorRGBExp32 tempLuxelData[4]; // [esp+10h] [ebp-88h] BYREF
  Vector vWorldSpaceTextureOrigin; // [esp+20h] [ebp-78h] BYREF
  Vector vColor; // [esp+2Ch] [ebp-6Ch] BYREF
  Vector vS; // [esp+38h] [ebp-60h] BYREF
  Vector vWorldSpaceLuxel; // [esp+44h] [ebp-54h] BYREF
  Vector vT; // [esp+50h] [ebp-48h] BYREF
  Vector vFaceNormal; // [esp+5Ch] [ebp-3Ch] BYREF
  float v52; // [esp+68h] [ebp-30h]
  int nDataLength; // [esp+6Ch] [ebp-2Ch] BYREF
  const ColorRGBExp32 *pLuxelData; // [esp+70h] [ebp-28h] BYREF
  CLuxelHash *v55; // [esp+74h] [ebp-24h]
  ColorRGBExp32 averageColor; // [esp+78h] [ebp-20h] BYREF
  int s; // [esp+7Ch] [ebp-1Ch]
  dface_t *pFace; // [esp+80h] [ebp-18h]
  int nTMax; // [esp+84h] [ebp-14h]
  const texinfo_s *pTexInfo; // [esp+88h] [ebp-10h]
  Vector vAverageColor; // [esp+8Ch] [ebp-Ch] BYREF
  int nSMax; // [esp+A0h] [ebp+8h]
  int nSMaxa; // [esp+A0h] [ebp+8h]
  int t; // [esp+A4h] [ebp+Ch]

  v55 = this;
  v4 = &pTargetBSPFile->m_FaceList.m_Memory.m_pMemory[nFace];
  m_pMemory = pTargetBSPFile->m_TexInfoList.m_Memory.m_pMemory;
  v6 = (m_pMemory[v4->texinfo].flags & 0x400) == 0;
  v7 = &m_pMemory[v4->texinfo];
  pFace = v4;
  pTexInfo = v7;
  if ( v6 )
  {
    v4->lightofs = pTargetBSPFile->m_LightingData.m_Size + 4;
    p_m_LightingData = &pTargetBSPFile->m_LightingData;
    *(_DWORD *)v4->styles = -256;
    m_nAllocationCount = pTargetBSPFile->m_LightingData.m_Memory.m_nAllocationCount;
    nSMax = pTargetBSPFile->m_LightingData.m_Size;
    v9 = nSMax;
    if ( nSMax + 4 > m_nAllocationCount )
    {
      CUtlMemory<char,int>::Grow(this: &pTargetBSPFile->m_LightingData.m_Memory, num: nSMax - m_nAllocationCount + 4);
      v9 = nSMax;
    }
    pTargetBSPFile->m_LightingData.m_Size += 4;
    v11 = p_m_LightingData->m_Memory.m_pMemory;
    v12 = pTargetBSPFile->m_LightingData.m_Size - v9 - 4;
    pTargetBSPFile->m_LightingData.m_pElements = pTargetBSPFile->m_LightingData.m_Memory.m_pMemory;
    if ( v12 > 0 )
      _V_memmove(dest: &v11[v9 + 4], src: &v11[v9], count: v12);
    nSMaxa = v4->m_LightmapTextureSizeInLuxels[0] + 1;
    nTMax = v4->m_LightmapTextureSizeInLuxels[1] + 1;
    ComputeFacePlane(nFace, p0: &vAverageColor, pBSPFile: pTargetBSPFile, pNormal: &vFaceNormal);
    CalculateLuxelToWorldTransform(
      &vFaceNormal,
      pLuxelOrigin: &vWorldSpaceTextureOrigin,
      pS: &vS,
      pT: &vT,
      pTexInfo,
      flFaceDistance: (float)((float)(vFaceNormal.y * vAverageColor.y) + (float)(vAverageColor.x * vFaceNormal.x))
    + (float)(vFaceNormal.z * vAverageColor.z));
    v13 = nTMax;
    v14 = 1.0 / (float)(nSMaxa * nTMax);
    v15 = (const texinfo_s *)((pTexInfo->flags & 0x800) != 0 ? 16 : 4);
    vAverageColor = vec3_origin;
    y = vec3_origin.y;
    x = vec3_origin.x;
    z = vec3_origin.z;
    pTexInfo = v15;
    v52 = v14;
    for ( t = 0; t < v13; ++t )
    {
      v19 = 0;
      s = 0;
      if ( nSMaxa > 0 )
      {
        do
        {
          v20 = (float)(t + pFace->m_LightmapTextureMinsInLuxels[1]);
          v21 = (float)(v19 + pFace->m_LightmapTextureMinsInLuxels[0]);
          vWorldSpaceLuxel.x = (float)((float)(vS.x * v21) + vWorldSpaceTextureOrigin.x) + (float)(vT.x * v20);
          vWorldSpaceLuxel.y = (float)(vWorldSpaceTextureOrigin.y + (float)(vS.y * v21)) + (float)(vT.y * v20);
          vWorldSpaceLuxel.z = (float)(vWorldSpaceTextureOrigin.z + (float)(vS.z * v21)) + (float)(vT.z * v20);
          if ( CLuxelHash::FindLuxel(
                 this: v55,
                 vPosition: &vWorldSpaceLuxel,
                 vNormal: &vFaceNormal,
                 ppLuxelData: &pLuxelData,
                 pDataLength: &nDataLength) != 0 )
          {
            v23 = pLuxelData;
            if ( (const texinfo_s *)(4 * nDataLength) == v15 || 4 * nDataLength > (unsigned int)v15 )
            {
              CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::InsertMultipleBefore(
                this: p_m_LightingData,
                elem: p_m_LightingData->m_Size,
                num: (int)v15,
                pToInsert: (const unsigned __int8 *)pLuxelData);
            }
            else if ( 4 * nDataLength < (unsigned int)v15 )
            {
              m_Size = p_m_LightingData->m_Size;
              v25 = p_m_LightingData->m_Memory.m_nAllocationCount;
              if ( m_Size + 4 > v25 )
                CUtlMemory<char,int>::Grow(this: &p_m_LightingData->m_Memory, num: m_Size - v25 + 4);
              p_m_LightingData->m_Size += 4;
              v26 = p_m_LightingData->m_Memory.m_pMemory;
              v27 = p_m_LightingData->m_Size - m_Size - 4;
              p_m_LightingData->m_pElements = p_m_LightingData->m_Memory.m_pMemory;
              if ( v27 > 0 )
                _V_memmove(dest: &v26[m_Size + 4], src: &v26[m_Size], count: v27);
              if ( v23 != nullptr )
              {
                v28 = &p_m_LightingData->m_Memory.m_pMemory[m_Size];
                if ( v28 != nullptr )
                  *v28 = v23->r;
                if ( &p_m_LightingData->m_Memory.m_pMemory[m_Size] != (unsigned __int8 *)-1 )
                  p_m_LightingData->m_Memory.m_pMemory[m_Size + 1] = v23->g;
                if ( &p_m_LightingData->m_Memory.m_pMemory[m_Size] != (unsigned __int8 *)-2 )
                  p_m_LightingData->m_Memory.m_pMemory[m_Size + 2] = v23->b;
                if ( &p_m_LightingData->m_Memory.m_pMemory[m_Size] != (unsigned __int8 *)-3 )
                  p_m_LightingData->m_Memory.m_pMemory[m_Size + 3] = v23->exponent;
              }
              v29 = p_m_LightingData->m_Size;
              v30 = p_m_LightingData->m_Memory.m_nAllocationCount;
              if ( v29 + 4 > v30 )
                CUtlMemory<char,int>::Grow(this: &p_m_LightingData->m_Memory, num: v29 - v30 + 4);
              p_m_LightingData->m_Size += 4;
              v31 = p_m_LightingData->m_Memory.m_pMemory;
              v32 = p_m_LightingData->m_Size - v29 - 4;
              p_m_LightingData->m_pElements = p_m_LightingData->m_Memory.m_pMemory;
              if ( v32 > 0 )
                _V_memmove(dest: &v31[v29 + 4], src: &v31[v29], count: v32);
              if ( v23 != nullptr )
              {
                v33 = &p_m_LightingData->m_Memory.m_pMemory[v29];
                if ( v33 != nullptr )
                  *v33 = v23->r;
                if ( &p_m_LightingData->m_Memory.m_pMemory[v29] != (unsigned __int8 *)-1 )
                  p_m_LightingData->m_Memory.m_pMemory[v29 + 1] = v23->g;
                if ( &p_m_LightingData->m_Memory.m_pMemory[v29] != (unsigned __int8 *)-2 )
                  p_m_LightingData->m_Memory.m_pMemory[v29 + 2] = v23->b;
                if ( &p_m_LightingData->m_Memory.m_pMemory[v29] != (unsigned __int8 *)-3 )
                  p_m_LightingData->m_Memory.m_pMemory[v29 + 3] = v23->exponent;
              }
              v34 = p_m_LightingData->m_Size;
              v35 = p_m_LightingData->m_Memory.m_nAllocationCount;
              if ( v34 + 4 > v35 )
                CUtlMemory<char,int>::Grow(this: &p_m_LightingData->m_Memory, num: v34 - v35 + 4);
              p_m_LightingData->m_Size += 4;
              v36 = p_m_LightingData->m_Memory.m_pMemory;
              v37 = p_m_LightingData->m_Size - v34 - 4;
              p_m_LightingData->m_pElements = p_m_LightingData->m_Memory.m_pMemory;
              if ( v37 > 0 )
                _V_memmove(dest: &v36[v34 + 4], src: &v36[v34], count: v37);
              if ( v23 != nullptr )
              {
                v38 = &p_m_LightingData->m_Memory.m_pMemory[v34];
                if ( v38 != nullptr )
                  *v38 = v23->r;
                if ( &p_m_LightingData->m_Memory.m_pMemory[v34] != (unsigned __int8 *)-1 )
                  p_m_LightingData->m_Memory.m_pMemory[v34 + 1] = v23->g;
                if ( &p_m_LightingData->m_Memory.m_pMemory[v34] != (unsigned __int8 *)-2 )
                  p_m_LightingData->m_Memory.m_pMemory[v34 + 2] = v23->b;
                if ( &p_m_LightingData->m_Memory.m_pMemory[v34] != (unsigned __int8 *)-3 )
                  p_m_LightingData->m_Memory.m_pMemory[v34 + 3] = v23->exponent;
              }
              v39 = p_m_LightingData->m_Size;
              v40 = p_m_LightingData->m_Memory.m_nAllocationCount;
              if ( v39 + 4 > v40 )
                CUtlMemory<char,int>::Grow(this: &p_m_LightingData->m_Memory, num: v39 - v40 + 4);
              p_m_LightingData->m_Size += 4;
              v41 = p_m_LightingData->m_Memory.m_pMemory;
              v42 = p_m_LightingData->m_Size - v39 - 4;
              p_m_LightingData->m_pElements = p_m_LightingData->m_Memory.m_pMemory;
              if ( v42 > 0 )
                _V_memmove(dest: &v41[v39 + 4], src: &v41[v39], count: v42);
              if ( v23 != nullptr )
              {
                v43 = &p_m_LightingData->m_Memory.m_pMemory[v39];
                if ( v43 != nullptr )
                  *v43 = v23->r;
                if ( &p_m_LightingData->m_Memory.m_pMemory[v39] != (unsigned __int8 *)-1 )
                  p_m_LightingData->m_Memory.m_pMemory[v39 + 1] = v23->g;
                if ( &p_m_LightingData->m_Memory.m_pMemory[v39] != (unsigned __int8 *)-2 )
                  p_m_LightingData->m_Memory.m_pMemory[v39 + 2] = v23->b;
                if ( &p_m_LightingData->m_Memory.m_pMemory[v39] != (unsigned __int8 *)-3 )
                  p_m_LightingData->m_Memory.m_pMemory[v39 + 3] = v23->exponent;
              }
              v15 = pTexInfo;
            }
            ColorRGBExp32ToVector(in: v23, out: &vColor);
            x = vColor.x + vAverageColor.x;
            y = vColor.y + vAverageColor.y;
            z = vColor.z + vAverageColor.z;
            v19 = s;
            vAverageColor.x = vColor.x + vAverageColor.x;
            vAverageColor.y = vColor.y + vAverageColor.y;
            vAverageColor.z = vColor.z + vAverageColor.z;
          }
          else
          {
            v22 = p_m_LightingData->m_Size;
            memset(tempLuxelData, 0, sizeof(tempLuxelData));
            CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::InsertMultipleBefore(
              this: p_m_LightingData,
              elem: v22,
              num: (int)v15,
              pToInsert: (const unsigned __int8 *)tempLuxelData);
            z = vAverageColor.z;
            y = vAverageColor.y;
            x = vAverageColor.x;
          }
          s = ++v19;
        }
        while ( v19 < nSMaxa );
        v14 = v52;
        v13 = nTMax;
      }
    }
    lightofs = pFace->lightofs;
    vAverageColor.x = v14 * x;
    vAverageColor.y = y * v14;
    vAverageColor.z = z * v14;
    VectorToColorRGBExp32(vin: &vAverageColor, c: &averageColor);
    *(ColorRGBExp32 *)&p_m_LightingData->m_Memory.m_pMemory[lightofs - 4] = averageColor;
  }
  else
  {
    v4->lightofs = -1;
    *(_DWORD *)v4->styles = -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B310
// Name: private: void CLuxelHash::CopyWorldLights(class CMemoryBSPFile __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLuxelHash::CopyWorldLights(CLuxelHash *this, CMemoryBSPFile *pTargetBSPFile)
{
  int v4; // ebx
  int v5; // ebx
  int v6; // edi
  int nWorldLight; // [esp+14h] [ebp+8h]

  pTargetBSPFile->m_WorldLightsLDR.m_Size = 0;
  pTargetBSPFile->m_WorldLightsHDR.m_Size = 0;
  CUtlVector<dworldlight_t,CUtlMemory<dworldlight_t,int>>::InsertMultipleBefore(
    this: &pTargetBSPFile->m_WorldLightsLDR,
    elem: pTargetBSPFile->m_WorldLightsLDR.m_Size,
    num: this->m_WorldLightsLDR.m_Size,
    pToInsert: this->m_WorldLightsLDR.m_Memory.m_pMemory);
  CUtlVector<dworldlight_t,CUtlMemory<dworldlight_t,int>>::InsertMultipleBefore(
    this: &pTargetBSPFile->m_WorldLightsHDR,
    elem: pTargetBSPFile->m_WorldLightsHDR.m_Size,
    num: this->m_WorldLightsHDR.m_Size,
    pToInsert: this->m_WorldLightsHDR.m_Memory.m_pMemory);
  v4 = 0;
  for ( nWorldLight = 0; nWorldLight < pTargetBSPFile->m_WorldLightsLDR.m_Size; ++nWorldLight )
  {
    pTargetBSPFile->m_WorldLightsLDR.m_Memory.m_pMemory[v4].cluster = pTargetBSPFile->m_LeafList.m_Memory.m_pMemory[CMemoryBSPFile::GetLeafIndexFromPoint(this: pTargetBSPFile, nNodeIndex: pTargetBSPFile->m_ModelList.m_Memory.m_pMemory->headnode, vPosition: &pTargetBSPFile->m_WorldLightsLDR.m_Memory.m_pMemory[v4].origin)].cluster;
    ++v4;
  }
  v5 = 0;
  if ( pTargetBSPFile->m_WorldLightsHDR.m_Size > 0 )
  {
    v6 = 0;
    do
    {
      pTargetBSPFile->m_WorldLightsHDR.m_Memory.m_pMemory[v6].cluster = pTargetBSPFile->m_LeafList.m_Memory.m_pMemory[CMemoryBSPFile::GetLeafIndexFromPoint(this: pTargetBSPFile, nNodeIndex: pTargetBSPFile->m_ModelList.m_Memory.m_pMemory->headnode, vPosition: &pTargetBSPFile->m_WorldLightsHDR.m_Memory.m_pMemory[v6].origin)].cluster;
      ++v5;
      ++v6;
    }
    while ( v5 < pTargetBSPFile->m_WorldLightsHDR.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B410
// Name: public: void CLuxelHash::AddSourceBSPFile(class CMemoryBSPFile const __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLuxelHash::AddSourceBSPFile(CLuxelHash *this, CMemoryBSPFile *pSourceBSPFile, const Vector *vOffset)
{
  CMemoryBSPFile *v3; // esi
  int v5; // ecx
  dface_t *v6; // ebx
  bool v7; // zf
  const texinfo_s *v8; // edi
  char *v9; // edi
  int v10; // eax
  int v11; // esi
  int v12; // ecx
  float v13; // xmm0_4
  float v14; // xmm4_4
  float v15; // xmm5_4
  float v16; // xmm1_4
  float v17; // xmm6_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  float v20; // xmm2_4
  int m_Size; // edx
  CUtlVector<dworldlight_t,CUtlMemory<dworldlight_t,int> > *p_m_WorldLightsLDR; // ebx
  int v23; // edx
  int v24; // eax
  CUtlVector<dworldlight_t,CUtlMemory<dworldlight_t,int> > *p_m_WorldLightsHDR; // edi
  int v26; // edx
  int v27; // edi
  float *p_x; // eax
  int v29; // edx
  int v30; // ebx
  float *v31; // eax
  CBSPFace *const *v32; // [esp-4h] [ebp-84h]
  const dworldlight_t *flFaceDistance; // [esp+0h] [ebp-80h]
  const dworldlight_t *flFaceDistancea; // [esp+0h] [ebp-80h]
  Vector vPosition; // [esp+10h] [ebp-70h] BYREF
  Vector vWorldSpaceTextureOrigin; // [esp+1Ch] [ebp-64h] BYREF
  Vector vS; // [esp+28h] [ebp-58h] BYREF
  Vector vT; // [esp+34h] [ebp-4Ch] BYREF
  Vector v0; // [esp+40h] [ebp-40h] BYREF
  Vector vFaceNormal; // [esp+4Ch] [ebp-34h] BYREF
  int v41; // [esp+58h] [ebp-28h]
  int nLightStartHDR; // [esp+5Ch] [ebp-24h]
  CLuxelHash *v43; // [esp+60h] [ebp-20h]
  int nFace; // [esp+64h] [ebp-1Ch]
  int nTMax; // [esp+68h] [ebp-18h]
  const texinfo_s *pTexInfo; // [esp+6Ch] [ebp-14h]
  unsigned int v47; // [esp+70h] [ebp-10h]
  int t; // [esp+74h] [ebp-Ch]
  int nSMax; // [esp+78h] [ebp-8h]
  int nLuxelSize; // [esp+7Ch] [ebp-4h]
  int nLightStartLDR; // [esp+88h] [ebp+8h]

  v3 = pSourceBSPFile;
  v5 = 0;
  v43 = this;
  nFace = 0;
  if ( pSourceBSPFile->m_FaceList.m_Size > 0 )
  {
    v47 = 0;
    do
    {
      v6 = &v3->m_FaceList.m_Memory.m_pMemory[v47 / 0x38];
      v7 = v6->lightofs == -1;
      v8 = &v3->m_TexInfoList.m_Memory.m_pMemory[v6->texinfo];
      pTexInfo = v8;
      if ( !v7 )
      {
        nLuxelSize = (v8->flags & 0x800) != 0 ? 16 : 4;
        nSMax = v6->m_LightmapTextureSizeInLuxels[0] + 1;
        nTMax = v6->m_LightmapTextureSizeInLuxels[1] + 1;
        ComputeFacePlane(nFace: v5, p0: &v0, pBSPFile: v3, pNormal: &vFaceNormal);
        CalculateLuxelToWorldTransform(
          &vFaceNormal,
          pLuxelOrigin: &vWorldSpaceTextureOrigin,
          pS: &vS,
          pT: &vT,
          pTexInfo,
          flFaceDistance: (float)((float)(vFaceNormal.y * v0.y) + (float)(v0.x * vFaceNormal.x)) + (float)(vFaceNormal.z * v0.z));
        v9 = nullptr;
        t = 0;
        if ( nTMax > 0 )
        {
          v10 = nLuxelSize * nSMax;
          pTexInfo = nullptr;
          v41 = nLuxelSize * nSMax;
          do
          {
            v11 = 0;
            if ( nSMax > 0 )
            {
              v12 = (unsigned int)nLuxelSize >> 2;
              for ( nLightStartHDR = (unsigned int)nLuxelSize >> 2; ; v12 = nLightStartHDR )
              {
                v13 = (float)(t + v6->m_LightmapTextureMinsInLuxels[1]);
                v14 = vT.y * v13;
                v15 = vT.z * v13;
                v16 = (float)(v11 + v6->m_LightmapTextureMinsInLuxels[0]);
                v17 = vS.z * v16;
                v18 = (float)((float)(vS.x * v16) + vWorldSpaceTextureOrigin.x) + (float)(vT.x * v13);
                v32 = (CBSPFace *const *)&pSourceBSPFile->m_LightingData.m_Memory.m_pMemory[(unsigned int)&v9[v6->lightofs]];
                v19 = (float)((float)(vWorldSpaceTextureOrigin.y + (float)(vS.y * v16)) + v14) + vOffset->y;
                v20 = (float)((float)(vWorldSpaceTextureOrigin.z + v17) + v15) + vOffset->z;
                vPosition.x = vOffset->x + v18;
                vPosition.y = v19;
                vPosition.z = v20;
                CLuxelHash::AddLuxel(this: v43, &vPosition, vNormal: &vFaceNormal, pLuxelData: v32, nDataLength: v12);
                v9 += nLuxelSize;
                if ( ++v11 >= nSMax )
                  break;
              }
              v10 = v41;
            }
            v9 = (char *)pTexInfo + v10;
            ++t;
            pTexInfo = (const texinfo_s *)((char *)pTexInfo + v10);
          }
          while ( t < nTMax );
        }
        v5 = nFace;
        v3 = pSourceBSPFile;
      }
      v47 += 56;
      nFace = ++v5;
    }
    while ( v5 < v3->m_FaceList.m_Size );
    this = v43;
  }
  flFaceDistance = v3->m_WorldLightsLDR.m_Memory.m_pMemory;
  nLightStartLDR = this->m_WorldLightsLDR.m_Size;
  m_Size = v3->m_WorldLightsLDR.m_Size;
  p_m_WorldLightsLDR = &this->m_WorldLightsLDR;
  nLightStartHDR = this->m_WorldLightsHDR.m_Size;
  CUtlVector<dworldlight_t,CUtlMemory<dworldlight_t,int>>::InsertMultipleBefore(
    this: &this->m_WorldLightsLDR,
    elem: this->m_WorldLightsLDR.m_Size,
    num: m_Size,
    pToInsert: flFaceDistance);
  v23 = v3->m_WorldLightsHDR.m_Size;
  v24 = this->m_WorldLightsHDR.m_Size;
  flFaceDistancea = v3->m_WorldLightsHDR.m_Memory.m_pMemory;
  p_m_WorldLightsHDR = &this->m_WorldLightsHDR;
  v41 = (int)p_m_WorldLightsHDR;
  CUtlVector<dworldlight_t,CUtlMemory<dworldlight_t,int>>::InsertMultipleBefore(
    this: p_m_WorldLightsHDR,
    elem: v24,
    num: v23,
    pToInsert: flFaceDistancea);
  v26 = 0;
  if ( v3->m_WorldLightsLDR.m_Size > 0 )
  {
    v27 = nLightStartLDR;
    do
    {
      p_x = &p_m_WorldLightsLDR->m_Memory.m_pMemory[v27].origin.x;
      *p_x = *p_x + vOffset->x;
      p_x[1] = p_x[1] + vOffset->y;
      ++v26;
      p_x[2] = p_x[2] + vOffset->z;
      ++v27;
    }
    while ( v26 < v3->m_WorldLightsLDR.m_Size );
    p_m_WorldLightsHDR = (CUtlVector<dworldlight_t,CUtlMemory<dworldlight_t,int> > *)v41;
  }
  v29 = 0;
  if ( v3->m_WorldLightsHDR.m_Size > 0 )
  {
    v30 = nLightStartHDR;
    do
    {
      v31 = &p_m_WorldLightsHDR->m_Memory.m_pMemory[v30].origin.x;
      *v31 = *v31 + vOffset->x;
      v31[1] = v31[1] + vOffset->y;
      ++v29;
      v31[2] = v31[2] + vOffset->z;
      ++v30;
    }
    while ( v29 < v3->m_WorldLightsHDR.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B710
// Name: public: void CLuxelHash::CopyLighting(class CMemoryBSPFile __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLuxelHash::CopyLighting(CLuxelHash *this, CMemoryBSPFile *pTargetBSPFile)
{
  int v2; // esi

  v2 = 0;
  for ( pTargetBSPFile->m_LightingData.m_Size = 0; v2 < pTargetBSPFile->m_FaceList.m_Size; ++v2 )
    CLuxelHash::CopyFaceLighting(this, pTargetBSPFile, nFace: v2);
  CLuxelHash::CopyWorldLights(this, pTargetBSPFile);
}
