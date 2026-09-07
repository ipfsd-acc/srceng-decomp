// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/disppaint.cpp
// Functions: 8
// ============================================================

#include "hammer\disppaint.h"

//------------------------------------------------------------------------------
// Address: 0x100221A0
// Name: protected: bool CDispPaintMgr::DoPaintSmoothOneOverExp(struct SpatialPaintData_t const __near &,class Vector const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CDispPaintMgr::DoPaintSmoothOneOverExp@<al>(
        CDispPaintMgr *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        const SpatialPaintData_t *spatialData,
        const Vector *vNewCenter,
        Vector *vPaintPos)
{
  IWorldEditDispMgr *ActiveWorldEditDispManager; // esi
  int (__thiscall *SelectCount)(IWorldEditDispMgr *); // edx
  float y; // xmm0_4
  float z; // xmm4_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm0_4
  float v16; // xmm5_4
  float v17; // xmm4_4
  float v18; // xmm3_4
  int v19; // eax
  int v20; // esi
  int v21; // ecx
  int v22; // esi
  float v23; // xmm3_4
  float *v24; // esi
  float v25; // xmm1_4
  float v26; // xmm2_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm2_4
  long double v31; // [esp+4h] [ebp-58h]
  Vector radius; // [esp+10h] [ebp-4Ch] BYREF
  Vector boxMax; // [esp+1Ch] [ebp-40h] BYREF
  float v34; // [esp+28h] [ebp-34h]
  Vector vBBoxMax; // [esp+2Ch] [ebp-30h]
  Vector vVert; // [esp+38h] [ebp-24h]
  int nDispCount; // [esp+44h] [ebp-18h]
  float flPaintDist; // [esp+48h] [ebp-14h]
  IWorldEditDispMgr *v39; // [esp+4Ch] [ebp-10h]
  int v40; // [esp+50h] [ebp-Ch]
  float v41; // [esp+54h] [ebp-8h]
  float flNewRadius; // [esp+58h] [ebp-4h]
  int flNewRadius2; // [esp+64h] [ebp+8h]
  float flWeight; // [esp+68h] [ebp+Ch]

  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  v39 = ActiveWorldEditDispManager;
  if ( ActiveWorldEditDispManager == nullptr )
    return 0;
  SelectCount = ActiveWorldEditDispManager->SelectCount;
  HIDWORD(v31) = a2;
  y = vNewCenter->y;
  z = vNewCenter->z;
  LODWORD(v31) = a3;
  v13 = vNewCenter->x * spatialData->m_vPaintAxis.x;
  v14 = spatialData->m_vCenter.y - y;
  v15 = y * spatialData->m_vPaintAxis.y;
  v16 = spatialData->m_vCenter.z - z;
  v17 = z * spatialData->m_vPaintAxis.z;
  v18 = (float)((float)((float)(v14 * v14)
                      + (float)((float)(spatialData->m_vCenter.x - vNewCenter->x)
                              * (float)(spatialData->m_vCenter.x - vNewCenter->x)))
              + (float)(v16 * v16))
      / spatialData->m_flRadius2;
  v41 = (float)((float)(1.0 - v18) * spatialData->m_flRadius) * (float)((float)(1.0 - v18) * spatialData->m_flRadius);
  flPaintDist = fsqrt(v41);
  flNewRadius = 0.0;
  flWeight = 0.0;
  vVert.x = (float)(v15 + v13) + v17;
  LODWORD(vBBoxMax.z) = SelectCount(this: ActiveWorldEditDispManager);
  flNewRadius2 = 0;
  if ( SLODWORD(vBBoxMax.z) > 0 )
  {
    while ( 1 )
    {
      v19 = (int)ActiveWorldEditDispManager->GetFromSelect(this: ActiveWorldEditDispManager, a2: flNewRadius2);
      v20 = v19;
      if ( v19 != 0 )
      {
        radius = *(Vector *)(v19 + 1064);
        boxMax = *(Vector *)(v19 + 1076);
        if ( IsBoxIntersectingSphere(boxMin: &radius, &boxMax, center: vNewCenter, radius: flPaintDist) )
        {
          v21 = *(_DWORD *)(v20 + 36);
          if ( ((1 << v21) + 1) * ((1 << v21) + 1) > 0 )
          {
            v22 = *(_DWORD *)(v20 + 784);
            v23 = v41;
            nDispCount = SLODWORD(vNewCenter->x);
            vVert.z = vNewCenter->y;
            vVert.y = vNewCenter->z;
            v24 = (float *)(v22 + 48);
            v40 = ((1 << v21) + 1) * ((1 << v21) + 1);
            do
            {
              v25 = *(v24 - 2);
              v26 = *v24;
              vBBoxMax.x = *(v24 - 1);
              v34 = v25;
              vBBoxMax.y = v26;
              v27 = (float)((float)((float)(vBBoxMax.x - vVert.z) * (float)(vBBoxMax.x - vVert.z))
                          + (float)((float)(v25 - *(float *)&nDispCount) * (float)(v25 - *(float *)&nDispCount)))
                  + (float)((float)(v26 - vVert.y) * (float)(v26 - vVert.y));
              if ( v23 > v27 )
              {
                __libm_sse2_exp(x: v31);
                v28 = 1.0 / (float)(v27 / v23);
                if ( v28 != 1.0 )
                  v28 = v28 / (float)(spatialData->m_flScalar * 2.0);
                v23 = v41;
                flWeight = (float)((float)((float)((float)((float)(spatialData->m_vPaintAxis.y * vBBoxMax.x)
                                                         + (float)(spatialData->m_vPaintAxis.x * v34))
                                                 + (float)(spatialData->m_vPaintAxis.z * vBBoxMax.y))
                                         - vVert.x)
                                 * v28)
                         + flWeight;
                flNewRadius = v28 + flNewRadius;
              }
              v24 += 56;
              --v40;
            }
            while ( v40 != 0 );
          }
        }
      }
      if ( ++flNewRadius2 >= SLODWORD(vBBoxMax.z) )
        break;
      ActiveWorldEditDispManager = v39;
    }
  }
  v29 = (float)(spatialData->m_vPaintAxis.y * (float)(flWeight / flNewRadius)) + vNewCenter->y;
  v30 = vNewCenter->z + (float)(spatialData->m_vPaintAxis.z * (float)(flWeight / flNewRadius));
  vPaintPos->x = vNewCenter->x + (float)(spatialData->m_vPaintAxis.x * (float)(flWeight / flNewRadius));
  vPaintPos->y = v29;
  vPaintPos->z = v30;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10022490
// Name: protected: void CDispPaintMgr::DoPaintEqual(struct SpatialPaintData_t __near &,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintMgr::DoPaintEqual(CDispPaintMgr *this, SpatialPaintData_t *spatialData, CMapDisp *pDisp)
{
  CMapDisp *v3; // edi
  int v4; // ebx
  float *v6; // eax
  float v7; // xmm0_4
  float m_flScalar; // xmm3_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax
  int m_EditHandle; // edi
  CEditDispMgr *v13; // eax
  Vector vPaintPos; // [esp+8h] [ebp-Ch] BYREF
  SpatialPaintData_t *spatialDataa; // [esp+1Ch] [ebp+8h]
  int iVert; // [esp+20h] [ebp+Ch]

  v3 = pDisp;
  v4 = ((1 << pDisp->m_CoreDispInfo.m_Power) + 1) * ((1 << pDisp->m_CoreDispInfo.m_Power) + 1);
  iVert = 0;
  if ( v4 > 0 )
  {
    spatialDataa = nullptr;
    do
    {
      v6 = (float *)((char *)&spatialDataa->m_nEffect + (unsigned int)v3->m_CoreDispInfo.m_pVerts);
      v7 = v6[10] - spatialData->m_vCenter.x;
      if ( spatialData->m_flRadius2 > (float)((float)((float)((float)(v6[11] - spatialData->m_vCenter.y)
                                                            * (float)(v6[11] - spatialData->m_vCenter.y))
                                                    + (float)(v7 * v7))
                                            + (float)((float)(v6[12] - spatialData->m_vCenter.z)
                                                    * (float)(v6[12] - spatialData->m_vCenter.z))) )
      {
        m_flScalar = spatialData->m_flScalar;
        v9 = (float)(spatialData->m_vPaintAxis.y * m_flScalar) + v6[14];
        v10 = (float)(spatialData->m_vPaintAxis.z * m_flScalar) + v6[15];
        vPaintPos.x = (float)(m_flScalar * spatialData->m_vPaintAxis.x) + v6[13];
        vPaintPos.y = v9;
        vPaintPos.z = v10;
        if ( !v3->m_Canvas.m_bDirty )
        {
          ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
          if ( ActiveWorldEditDispManager != nullptr )
          {
            m_EditHandle = v3->m_EditHandle;
            ActiveWorldEditDispManager->Undo(this: ActiveWorldEditDispManager, a2: m_EditHandle, a3: false);
            v13 = EditDispMgr();
            v3 = v13->GetDisp(this: v13, a2: m_EditHandle);
          }
        }
        CMapDisp::Paint_SetValue(this: v3, iVert, vPaint: &vPaintPos);
      }
      spatialDataa = (SpatialPaintData_t *)((char *)spatialDataa + 224);
      ++iVert;
    }
    while ( iVert < v4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100225B0
// Name: protected: void CDispPaintMgr::DoPaintSmooth(struct SpatialPaintData_t __near &,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintMgr::DoPaintSmooth(CDispPaintMgr *this, SpatialPaintData_t *spatialData, CMapDisp *pDisp)
{
  CMapDisp *v3; // esi
  int v4; // ebx
  CoreDispVert_t *m_pVerts; // eax
  float v7; // xmm0_4
  int v8; // eax
  float v9; // xmm0_4
  float v10; // xmm1_4
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax
  int m_EditHandle; // esi
  CEditDispMgr *v13; // eax
  Vector vPaintPos; // [esp+8h] [ebp-1Ch] BYREF
  Vector vVert; // [esp+14h] [ebp-10h] BYREF
  CDispPaintMgr *v16; // [esp+20h] [ebp-4h]
  SpatialPaintData_t *spatialDataa; // [esp+2Ch] [ebp+8h]
  int iVert; // [esp+30h] [ebp+Ch]

  v3 = pDisp;
  v16 = this;
  v4 = ((1 << pDisp->m_CoreDispInfo.m_Power) + 1) * ((1 << pDisp->m_CoreDispInfo.m_Power) + 1);
  iVert = 0;
  if ( v4 > 0 )
  {
    spatialDataa = nullptr;
    do
    {
      m_pVerts = v3->m_CoreDispInfo.m_pVerts;
      v7 = *(float *)(&spatialDataa->m_bNudge + (_DWORD)m_pVerts);
      v8 = (int)(&spatialDataa->m_bNudge + (_DWORD)m_pVerts);
      vVert.x = v7;
      v9 = v7 - spatialData->m_vCenter.x;
      vVert.y = *(float *)(v8 + 4);
      v10 = vVert.y - spatialData->m_vCenter.y;
      vVert.z = *(float *)(v8 + 8);
      if ( spatialData->m_flRadius2 > (float)((float)((float)(v10 * v10) + (float)(v9 * v9))
                                            + (float)((float)(vVert.z - spatialData->m_vCenter.z)
                                                    * (float)(vVert.z - spatialData->m_vCenter.z)))
        && CDispPaintMgr::DoPaintSmoothOneOverExp(
             this: v16,
             a2: v4,
             a3: (int)spatialData,
             spatialData,
             vNewCenter: &vVert,
             &vPaintPos) != 0 )
      {
        if ( !v3->m_Canvas.m_bDirty )
        {
          ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
          if ( ActiveWorldEditDispManager != nullptr )
          {
            m_EditHandle = v3->m_EditHandle;
            ActiveWorldEditDispManager->Undo(this: ActiveWorldEditDispManager, a2: m_EditHandle, a3: false);
            v13 = EditDispMgr();
            v3 = v13->GetDisp(this: v13, a2: m_EditHandle);
          }
        }
        CMapDisp::Paint_SetValue(this: v3, iVert, vPaint: &vPaintPos);
      }
      spatialDataa = (SpatialPaintData_t *)((char *)spatialDataa + 224);
      ++iVert;
    }
    while ( iVert < v4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100226C0
// Name: protected: void CDispPaintMgr::DoNudgeAdd(struct SpatialPaintData_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintMgr::DoNudgeAdd(CDispPaintMgr *this, SpatialPaintData_t *spatialData)
{
  int m_Size; // eax
  CDispPaintMgr::DispVertPair_t *v3; // ebx
  CEditDispMgr *v4; // eax
  CMapDisp *v5; // edi
  CoreDispVert_t *m_pVerts; // ecx
  int m_iVert; // eax
  float x; // xmm4_4
  float y; // xmm5_4
  float z; // xmm6_4
  float v11; // xmm0_4
  unsigned int m_uiBrushType; // eax
  float v13; // xmm0_4
  float v14; // xmm2_4
  float v15; // xmm3_4
  float m_flScalar; // xmm3_4
  float v17; // xmm1_4
  float v18; // xmm2_4
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax
  int m_EditHandle; // edi
  CEditDispMgr *v21; // eax
  Vector vPaintPos; // [esp+0h] [ebp-18h] BYREF
  int nNudgeCount; // [esp+Ch] [ebp-Ch]
  CDispPaintMgr *v24; // [esp+10h] [ebp-8h]
  int iNudge; // [esp+14h] [ebp-4h]

  m_Size = this->m_aNudgeData.m_Size;
  v24 = this;
  nNudgeCount = m_Size;
  iNudge = 0;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      v3 = &this->m_aNudgeData.m_Memory.m_pMemory[iNudge];
      v4 = EditDispMgr();
      v5 = v4->GetDisp(this: v4, a2: v3->m_hDisp);
      m_pVerts = v5->m_CoreDispInfo.m_pVerts;
      m_iVert = v3->m_iVert;
      x = m_pVerts[m_iVert].m_Vert.x;
      y = m_pVerts[m_iVert].m_Vert.y;
      z = m_pVerts[m_iVert].m_Vert.z;
      v11 = (float)((float)((float)(y - spatialData->m_vCenter.y) * (float)(y - spatialData->m_vCenter.y))
                  + (float)((float)(x - spatialData->m_vCenter.x) * (float)(x - spatialData->m_vCenter.x)))
          + (float)((float)(z - spatialData->m_vCenter.z) * (float)(z - spatialData->m_vCenter.z));
      if ( spatialData->m_flRadius2 > v11 )
      {
        m_uiBrushType = spatialData->m_uiBrushType;
        if ( m_uiBrushType != 0 )
        {
          if ( m_uiBrushType == 1 )
          {
            m_flScalar = spatialData->m_flScalar;
            v17 = (float)(spatialData->m_vPaintAxis.y * m_flScalar) + y;
            v18 = (float)(spatialData->m_vPaintAxis.z * m_flScalar) + z;
            vPaintPos.x = (float)(spatialData->m_vPaintAxis.x * m_flScalar) + x;
            vPaintPos.y = v17;
            vPaintPos.z = v18;
          }
        }
        else
        {
          v13 = (float)(1.0 - (float)(spatialData->m_flOORadius2 * v11)) * spatialData->m_flScalar;
          v14 = (float)(spatialData->m_vPaintAxis.y * v13) + y;
          v15 = (float)(spatialData->m_vPaintAxis.z * v13) + z;
          vPaintPos.x = (float)(spatialData->m_vPaintAxis.x * v13) + x;
          vPaintPos.y = v14;
          vPaintPos.z = v15;
        }
        if ( !v5->m_Canvas.m_bDirty )
        {
          ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
          if ( ActiveWorldEditDispManager != nullptr )
          {
            m_EditHandle = v5->m_EditHandle;
            ActiveWorldEditDispManager->Undo(this: ActiveWorldEditDispManager, a2: m_EditHandle, a3: false);
            v21 = EditDispMgr();
            v5 = v21->GetDisp(this: v21, a2: m_EditHandle);
          }
        }
        CMapDisp::Paint_SetValue(this: v5, iVert: v3->m_iVert, vPaint: &vPaintPos);
      }
      if ( ++iNudge >= nNudgeCount )
        break;
      this = v24;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022860
// Name: public: CDispPaintMgr::~CDispPaintMgr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintMgr::~CDispPaintMgr(CDispPaintMgr *this)
{
  this->m_aNudgeData.m_Size = 0;
  if ( this->m_aNudgeData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aNudgeData.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_aNudgeData.m_Memory.m_pMemory);
      this->m_aNudgeData.m_Memory.m_pMemory = nullptr;
    }
    this->m_aNudgeData.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aNudgeData.m_pElements = this->m_aNudgeData.m_Memory.m_pMemory;
  this->m_aNudgeData.m_Size = 0;
  if ( this->m_aNudgeData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aNudgeData.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_aNudgeData.m_Memory.m_pMemory);
      this->m_aNudgeData.m_Memory.m_pMemory = nullptr;
    }
    this->m_aNudgeData.m_Memory.m_nAllocationCount = 0;
  }
  this->m_aNudgeData.m_pElements = this->m_aNudgeData.m_Memory.m_pMemory;
  if ( this->m_aNudgeData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_aNudgeData.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_aNudgeData.m_Memory.m_pMemory);
      this->m_aNudgeData.m_Memory.m_pMemory = nullptr;
    }
    this->m_aNudgeData.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022900
// Name: protected: void CDispPaintMgr::DoPaintAdd(struct SpatialPaintData_t __near &,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDispPaintMgr::DoPaintAdd(CDispPaintMgr *this, SpatialPaintData_t *spatialData, CMapDisp *pDisp)
{
  CMapDisp *v3; // edi
  int v5; // ecx
  int v6; // ecx
  CoreDispVert_t *m_pVerts; // edx
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  float v12; // xmm0_4
  unsigned int m_uiBrushType; // eax
  float v14; // xmm0_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  float m_flScalar; // xmm3_4
  float v18; // xmm1_4
  float v19; // xmm2_4
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax
  int m_EditHandle; // edi
  CEditDispMgr *v22; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDispPaintMgr::DispVertPair_t *m_pMemory; // ecx
  int v26; // eax
  int v27; // edx
  Vector vPaintPos; // [esp+8h] [ebp-14h] BYREF
  int nVertCount; // [esp+14h] [ebp-8h]
  int iVert; // [esp+18h] [ebp-4h]
  SpatialPaintData_t *spatialDataa; // [esp+24h] [ebp+8h]

  v3 = pDisp;
  v5 = (1 << pDisp->m_CoreDispInfo.m_Power) + 1;
  v6 = v5 * v5;
  nVertCount = v6;
  iVert = 0;
  if ( v6 > 0 )
  {
    spatialDataa = nullptr;
    do
    {
      m_pVerts = v3->m_CoreDispInfo.m_pVerts;
      v9 = *(float *)(&spatialDataa->m_bNudge + (_DWORD)m_pVerts);
      v10 = *(float *)((char *)&spatialDataa->m_flRadius2 + (_DWORD)m_pVerts);
      v11 = *(float *)((char *)&spatialDataa->m_flOORadius2 + (_DWORD)m_pVerts);
      v12 = (float)((float)((float)(v10 - spatialData->m_vCenter.y) * (float)(v10 - spatialData->m_vCenter.y))
                  + (float)((float)(v9 - spatialData->m_vCenter.x) * (float)(v9 - spatialData->m_vCenter.x)))
          + (float)((float)(v11 - spatialData->m_vCenter.z) * (float)(v11 - spatialData->m_vCenter.z));
      if ( spatialData->m_flRadius2 > v12 )
      {
        m_uiBrushType = spatialData->m_uiBrushType;
        if ( m_uiBrushType != 0 )
        {
          if ( m_uiBrushType == 1 )
          {
            m_flScalar = spatialData->m_flScalar;
            v18 = (float)(spatialData->m_vPaintAxis.y * m_flScalar) + v10;
            v19 = (float)(spatialData->m_vPaintAxis.z * m_flScalar) + v11;
            vPaintPos.x = (float)(m_flScalar * spatialData->m_vPaintAxis.x) + v9;
            vPaintPos.y = v18;
            vPaintPos.z = v19;
          }
        }
        else
        {
          v14 = (float)(1.0 - (float)(spatialData->m_flOORadius2 * v12)) * spatialData->m_flScalar;
          v15 = (float)(spatialData->m_vPaintAxis.y * v14) + v10;
          v16 = (float)(spatialData->m_vPaintAxis.z * v14) + v11;
          vPaintPos.x = (float)(v14 * spatialData->m_vPaintAxis.x) + v9;
          vPaintPos.y = v15;
          vPaintPos.z = v16;
        }
        if ( !v3->m_Canvas.m_bDirty )
        {
          ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
          if ( ActiveWorldEditDispManager != nullptr )
          {
            m_EditHandle = v3->m_EditHandle;
            ActiveWorldEditDispManager->Undo(this: ActiveWorldEditDispManager, a2: m_EditHandle, a3: false);
            v22 = EditDispMgr();
            pDisp = v22->GetDisp(this: v22, a2: m_EditHandle);
            v3 = pDisp;
          }
        }
        CMapDisp::Paint_SetValue(this: v3, iVert, vPaint: &vPaintPos);
        if ( spatialData->m_bNudgeInit )
        {
          m_Size = this->m_aNudgeData.m_Size;
          m_nAllocationCount = this->m_aNudgeData.m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<UsedTexture_t,int>::Grow(
              this: &this->m_aNudgeData.m_Memory,
              num: m_Size - m_nAllocationCount + 1);
          ++this->m_aNudgeData.m_Size;
          m_pMemory = this->m_aNudgeData.m_Memory.m_pMemory;
          v26 = this->m_aNudgeData.m_Size - m_Size - 1;
          this->m_aNudgeData.m_pElements = this->m_aNudgeData.m_Memory.m_pMemory;
          if ( v26 > 0 )
            _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v26);
          v27 = iVert;
          this->m_aNudgeData.m_Memory.m_pMemory[m_Size].m_hDisp = pDisp->m_EditHandle;
          this->m_aNudgeData.m_Memory.m_pMemory[m_Size].m_iVert = v27;
          v3 = pDisp;
        }
        v6 = nVertCount;
      }
      spatialDataa = (SpatialPaintData_t *)((char *)spatialDataa + 224);
      ++iVert;
    }
    while ( iVert < v6 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022B00
// Name: protected: bool CDispPaintMgr::DoPaint(struct SpatialPaintData_t __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispPaintMgr::DoPaint(CDispPaintMgr *this, SpatialPaintData_t *spatialData)
{
  IWorldEditDispMgr *ActiveWorldEditDispManager; // ebx
  int v6; // eax
  CMapDisp *v7; // esi
  Vector boxMin; // [esp+10h] [ebp-20h] BYREF
  Vector vBBoxMin; // [esp+1Ch] [ebp-14h] BYREF
  Vector vBBoxMax; // [esp+28h] [ebp-8h]
  CDispPaintMgr *i; // [esp+38h] [ebp+8h]

  LODWORD(vBBoxMax.y) = this;
  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  if ( ActiveWorldEditDispManager == nullptr )
    return 0;
  if ( !spatialData->m_bNudge || spatialData->m_bNudgeInit )
  {
    LODWORD(vBBoxMax.x) = ActiveWorldEditDispManager->SelectCount(this: ActiveWorldEditDispManager);
    for ( i = nullptr; (int)i < SLODWORD(vBBoxMax.x); i = (CDispPaintMgr *)((char *)i + 1) )
    {
      v6 = (int)ActiveWorldEditDispManager->GetFromSelect(this: ActiveWorldEditDispManager, a2: (int)i);
      v7 = (CMapDisp *)v6;
      if ( v6 != 0 )
      {
        boxMin = *(Vector *)(v6 + 1064);
        vBBoxMin = *(Vector *)(v6 + 1076);
        if ( IsBoxIntersectingSphere(
               &boxMin,
               boxMax: &vBBoxMin,
               center: &spatialData->m_vCenter,
               radius: spatialData->m_flRadius) )
        {
          if ( spatialData->m_nEffect != 0 )
          {
            if ( spatialData->m_nEffect == 1 )
            {
              CDispPaintMgr::DoPaintEqual(this: (CDispPaintMgr *)LODWORD(vBBoxMax.y), spatialData, pDisp: v7);
            }
            else if ( spatialData->m_nEffect == 2 )
            {
              CDispPaintMgr::DoPaintSmooth(this: (CDispPaintMgr *)LODWORD(vBBoxMax.y), spatialData, pDisp: v7);
            }
          }
          else
          {
            CDispPaintMgr::DoPaintAdd(this: (CDispPaintMgr *)LODWORD(vBBoxMax.y), spatialData, pDisp: v7);
          }
        }
      }
    }
    return 1;
  }
  else
  {
    CDispPaintMgr::DoNudgeAdd(this, spatialData);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10022C40
// Name: public: bool CDispPaintMgr::Paint(struct SpatialPaintData_t __near &,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDispPaintMgr::Paint(CDispPaintMgr *this, SpatialPaintData_t *spatialData, bool bAutoSew)
{
  bool v3; // zf
  float v4; // xmm0_4
  char result; // al

  v3 = !spatialData->m_bNudgeInit;
  v4 = spatialData->m_flRadius * spatialData->m_flRadius;
  spatialData->m_flRadius2 = v4;
  spatialData->m_flOORadius2 = 1.0 / v4;
  if ( !v3 )
    this->m_aNudgeData.m_Size = 0;
  result = CDispPaintMgr::DoPaint(this, spatialData);
  if ( result != 0 )
    return CDispMapImageFilterManager::PostApply((CDispMapImageFilterManager *)this, bSew: bAutoSew) != 0;
  return result;
}
