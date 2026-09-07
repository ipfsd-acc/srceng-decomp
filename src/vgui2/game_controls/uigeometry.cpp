// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/game_controls/uigeometry.cpp
// Functions: 14
// ============================================================

#include "vgui2\game_controls\uigeometry.h"

//------------------------------------------------------------------------------
// Address: 0x00417050
// Name: private: void CGeometry::CalculateExtentsMatrix(struct StageRenderInfo_t const __near &,class CGraphicGroup const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGeometry::CalculateExtentsMatrix(
        CGeometry *this,
        const StageRenderInfo_t *stageRenderInfo,
        CGraphicGroup *pGroup)
{
  float x; // xmm0_4
  float y; // xmm1_4
  Vector position; // [esp+18h] [ebp-184h] BYREF
  Vector axis; // [esp+24h] [ebp-178h] BYREF
  Vector centerVec; // [esp+30h] [ebp-16Ch] BYREF
  Vector centerInScreen; // [esp+3Ch] [ebp-160h] BYREF
  matrix3x4_t transmat; // [esp+48h] [ebp-154h] BYREF
  matrix3x4_t rotmat; // [esp+78h] [ebp-124h] BYREF
  matrix3x4_t temp; // [esp+A8h] [ebp-F4h] BYREF
  matrix3x4_t scalemat; // [esp+D8h] [ebp-C4h] BYREF
  matrix3x4_t rawToLocal; // [esp+108h] [ebp-94h] BYREF
  matrix3x4_t screenScalemat; // [esp+138h] [ebp-64h] BYREF
  matrix3x4_t groupToScreen; // [esp+168h] [ebp-34h] BYREF

  if ( !this->m_bMaintainAspectRatio || pGroup->MaintainAspectRatio(this: pGroup) )
  {
    x = this->m_Center.x;
    y = this->m_Center.y;
    LOBYTE(position.x) = 0;
  }
  else
  {
    LOBYTE(position.x) = 1;
    SetScaleMatrix(
      x: stageRenderInfo->parentScale.x,
      y: stageRenderInfo->parentScale.y,
      z: 1.0,
      dst: (matrix3x4_t *)&screenScalemat.m_flMatVal[0][1]);
    centerVec.y = this->m_Center.x;
    centerVec.z = this->m_Center.y;
    centerInScreen.x = 0.0;
    VectorTransform(in1: &centerVec.y, in2: (matrix3x4_t *)&screenScalemat.m_flMatVal[0][1], out: &centerInScreen.y);
    x = centerInScreen.y;
    y = centerInScreen.z;
  }
  position.y = x;
  position.z = y;
  axis.x = 0.0;
  SetIdentityMatrix(matrix: (matrix3x4_t *)&transmat.m_flMatVal[0][1]);
  MatrixSetColumn(in: (Vector *)&position.y, column: 3, out: (matrix3x4_t *)&transmat.m_flMatVal[0][1]);
  SetScaleMatrix(x: this->m_Scale.x, y: this->m_Scale.y, z: 1.0, dst: (matrix3x4_t *)&scalemat.m_flMatVal[0][1]);
  axis.y = 0.0;
  axis.z = 0.0;
  centerVec.x = 1.0;
  MatrixBuildRotationAboutAxis(
    vAxisOfRot: (Vector *)&axis.y,
    angleDegrees: 0.0,
    dst: (matrix3x4_t *)&rotmat.m_flMatVal[0][1]);
  ConcatTransforms(
    in1: (matrix3x4_t *)&rotmat.m_flMatVal[0][1],
    in2: (matrix3x4_t *)&scalemat.m_flMatVal[0][1],
    out: (matrix3x4_t *)&temp.m_flMatVal[0][1]);
  ConcatTransforms(
    in1: (matrix3x4_t *)&transmat.m_flMatVal[0][1],
    in2: (matrix3x4_t *)&temp.m_flMatVal[0][1],
    out: (matrix3x4_t *)&rawToLocal.m_flMatVal[0][1]);
  pGroup->GetRenderTransform(this: pGroup, a2: (matrix3x4_t *)&groupToScreen.m_flMatVal[0][1], a3: LOBYTE(position.x));
  ConcatTransforms(
    in1: (matrix3x4_t *)&groupToScreen.m_flMatVal[0][1],
    in2: (matrix3x4_t *)&rawToLocal.m_flMatVal[0][1],
    out: &this->m_ExtentsMatrix);
}

//------------------------------------------------------------------------------
// Address: 0x00417210
// Name: public: class DmeTime_t CRenderGeometry::GetAnimStartTime(void)
// Source: json
//------------------------------------------------------------------------------
DmeTime_t *__thiscall CRenderGeometry::GetAnimStartTime(CRenderGeometry *this, DmeTime_t *result)
{
  result->m_tms = (int)this->m_AnimStartTime;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00417220
// Name: bool PointTriangleHitTest(class Vector2D,class Vector2D,class Vector2D,class Vector2D)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl PointTriangleHitTest(Vector2D tringleVert0, Vector2D tringleVert1, Vector2D tringleVert2, Vector2D point)
{
  float v4; // xmm0_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm4_4
  float v10; // xmm0_4
  float v11; // xmm1_4

  v4 = tringleVert2.x - tringleVert0.x;
  tringleVert2.x = (float)(v4 * v4)
                 + (float)((float)(tringleVert2.y - tringleVert0.y) * (float)(tringleVert2.y - tringleVert0.y));
  v5 = (float)((float)(tringleVert1.x - tringleVert0.x) * v4)
     + (float)((float)(tringleVert1.y - tringleVert0.y) * (float)(tringleVert2.y - tringleVert0.y));
  v6 = (float)((float)(point.y - tringleVert0.y) * (float)(tringleVert2.y - tringleVert0.y))
     + (float)((float)(point.x - tringleVert0.x) * v4);
  v7 = (float)((float)(point.y - tringleVert0.y) * (float)(tringleVert1.y - tringleVert0.y))
     + (float)((float)(point.x - tringleVert0.x) * (float)(tringleVert1.x - tringleVert0.x));
  v8 = (float)((float)(tringleVert1.x - tringleVert0.x) * (float)(tringleVert1.x - tringleVert0.x))
     + (float)((float)(tringleVert1.y - tringleVert0.y) * (float)(tringleVert1.y - tringleVert0.y));
  v9 = 1.0 / (float)((float)(v8 * tringleVert2.x) - (float)(v5 * v5));
  v10 = (float)((float)(v8 * v6) - (float)(v7 * v5)) * v9;
  v11 = (float)((float)(v7 * tringleVert2.x) - (float)(v6 * v5)) * v9;
  return v10 > 0.0 && v11 > 0.0 && (float)(v11 + v10) < 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x00417330
// Name: public: void CGeometry::UpdateRenderTransforms(struct StageRenderInfo_t const __near &,class CGraphicGroup const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGeometry::UpdateRenderTransforms(
        CGeometry *this,
        const StageRenderInfo_t *stageRenderInfo,
        CGraphicGroup *pGroup)
{
  float x; // xmm0_4
  float v5; // xmm1_4
  float y; // [esp+4h] [ebp-1ACh]
  float z; // [esp+8h] [ebp-1A8h]
  float bUseMaintainedMatrix; // [esp+1Ch] [ebp-194h]
  Vector centerVec; // [esp+20h] [ebp-190h] BYREF
  Vector axis; // [esp+2Ch] [ebp-184h] BYREF
  Vector position; // [esp+38h] [ebp-178h] BYREF
  Vector tempCenter; // [esp+44h] [ebp-16Ch] BYREF
  Vector centerInScreen; // [esp+50h] [ebp-160h] BYREF
  matrix3x4_t screenScalemat; // [esp+5Ch] [ebp-154h] BYREF
  matrix3x4_t transmat; // [esp+8Ch] [ebp-124h] BYREF
  matrix3x4_t rotmat; // [esp+BCh] [ebp-F4h] BYREF
  matrix3x4_t temp; // [esp+ECh] [ebp-C4h] BYREF
  matrix3x4_t rawToLocal; // [esp+11Ch] [ebp-94h] BYREF
  matrix3x4_t scalemat; // [esp+14Ch] [ebp-64h] BYREF
  matrix3x4_t groupToScreen; // [esp+17Ch] [ebp-34h] BYREF

  pGroup->IsStageGroup(this: pGroup);
  if ( this->m_bVisible )
  {
    if ( !this->m_bMaintainAspectRatio || pGroup->MaintainAspectRatio(this: pGroup) )
    {
      x = this->m_Center.x;
      v5 = this->m_Center.y;
      LOBYTE(centerVec.x) = 0;
    }
    else
    {
      LOBYTE(centerVec.x) = 1;
      SetScaleMatrix(
        x: stageRenderInfo->parentScale.x,
        y: stageRenderInfo->parentScale.y,
        z: 1.0,
        dst: (matrix3x4_t *)&screenScalemat.m_flMatVal[0][1]);
      centerVec.y = this->m_Center.x;
      centerVec.z = this->m_Center.y;
      axis.x = 0.0;
      VectorTransform(in1: &centerVec.y, in2: (matrix3x4_t *)&screenScalemat.m_flMatVal[0][1], out: &centerInScreen.y);
      if ( stageRenderInfo->parentScale.x <= stageRenderInfo->parentScale.y )
        bUseMaintainedMatrix = stageRenderInfo->parentScale.x;
      else
        bUseMaintainedMatrix = stageRenderInfo->parentScale.y;
      y = 1.0 / bUseMaintainedMatrix;
      SetScaleMatrix(x: y, y, z: 1.0, dst: (matrix3x4_t *)&screenScalemat.m_flMatVal[0][1]);
      VectorTransform(in1: &centerInScreen.y, in2: (matrix3x4_t *)&screenScalemat.m_flMatVal[0][1], out: &tempCenter.y);
      x = tempCenter.y;
      v5 = tempCenter.z;
    }
    position.y = x;
    position.z = v5;
    tempCenter.x = 0.0;
    SetIdentityMatrix(matrix: (matrix3x4_t *)&transmat.m_flMatVal[0][1]);
    MatrixSetColumn(in: (Vector *)&position.y, column: 3, out: (matrix3x4_t *)&transmat.m_flMatVal[0][1]);
    SetScaleMatrix(x: this->m_Scale.x, y: this->m_Scale.y, z: 1.0, dst: (matrix3x4_t *)&scalemat.m_flMatVal[0][1]);
    z = this->m_Rotation;
    axis.y = 0.0;
    axis.z = 0.0;
    position.x = 1.0;
    MatrixBuildRotationAboutAxis(
      vAxisOfRot: (Vector *)&axis.y,
      angleDegrees: z,
      dst: (matrix3x4_t *)&rotmat.m_flMatVal[0][1]);
    ConcatTransforms(
      in1: (matrix3x4_t *)&rotmat.m_flMatVal[0][1],
      in2: (matrix3x4_t *)&scalemat.m_flMatVal[0][1],
      out: (matrix3x4_t *)&temp.m_flMatVal[0][1]);
    ConcatTransforms(
      in1: (matrix3x4_t *)&transmat.m_flMatVal[0][1],
      in2: (matrix3x4_t *)&temp.m_flMatVal[0][1],
      out: (matrix3x4_t *)&rawToLocal.m_flMatVal[0][1]);
    pGroup->GetRenderTransform(
      this: pGroup,
      a2: (matrix3x4_t *)&groupToScreen.m_flMatVal[0][1],
      a3: LOBYTE(centerVec.x));
    ConcatTransforms(
      in1: (matrix3x4_t *)&groupToScreen.m_flMatVal[0][1],
      in2: (matrix3x4_t *)&rawToLocal.m_flMatVal[0][1],
      out: &this->m_RenderToScreen);
    if ( this->m_bDirtyExtents )
      CGeometry::CalculateExtentsMatrix(this, stageRenderInfo, pGroup);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417610
// Name: private: void CGeometry::SetTopVerticesColor(struct color32_s)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGeometry::SetTopVerticesColor(CGeometry *this, color32_s c)
{
  int v2; // eax

  v2 = 0;
  if ( this->m_bHorizontalGradient )
  {
    if ( this->m_VertexColors.m_Size > 0 )
    {
      do
      {
        this->m_VertexColors.m_Memory.m_pMemory[v2] = c;
        this->m_VertexColors.m_Memory.m_pMemory[v2 + 3] = c;
        v2 += 4;
      }
      while ( v2 < this->m_VertexColors.m_Size );
    }
  }
  else if ( this->m_VertexColors.m_Size > 0 )
  {
    do
    {
      this->m_VertexColors.m_Memory.m_pMemory[v2] = c;
      this->m_VertexColors.m_Memory.m_pMemory[v2 + 1] = c;
      v2 += 4;
    }
    while ( v2 < this->m_VertexColors.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417660
// Name: private: void CGeometry::SetBottomVerticesColor(struct color32_s)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGeometry::SetBottomVerticesColor(CGeometry *this, color32_s c)
{
  int i; // eax
  int v3; // edx
  int v4; // eax

  if ( this->m_bHorizontalGradient )
  {
    for ( i = 0; i < this->m_VertexColors.m_Size; i += 4 )
    {
      this->m_VertexColors.m_Memory.m_pMemory[i + 1] = c;
      this->m_VertexColors.m_Memory.m_pMemory[i + 2] = c;
    }
  }
  else
  {
    v3 = 0;
    if ( this->m_VertexColors.m_Size > 0 )
    {
      v4 = 3;
      do
      {
        this->m_VertexColors.m_Memory.m_pMemory[v4 - 1] = c;
        this->m_VertexColors.m_Memory.m_pMemory[v4] = c;
        v3 += 4;
        v4 += 4;
      }
      while ( v3 < this->m_VertexColors.m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004176C0
// Name: private: void CGeometry::SetResultantColor(bool,struct color32_s)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGeometry::SetResultantColor(CGeometry *this, bool bTop, unsigned int parentColor)
{
  float v3; // xmm1_4
  int v4; // edx
  float v5; // xmm1_4
  int v6; // ebx
  float v7; // xmm1_4
  float v8; // xmm1_4
  float v9; // xmm1_4
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  int v13; // eax
  float v14; // xmm1_4
  int v15; // edx
  float v16; // xmm1_4
  int v17; // ebx
  float v18; // xmm1_4
  float v19; // xmm1_4
  float v20; // xmm1_4
  float v21; // xmm1_4
  float v22; // xmm0_4
  unsigned __int8 v23; // [esp+6h] [ebp-2h]
  unsigned __int8 v24; // [esp+7h] [ebp-1h]
  unsigned __int8 v25; // [esp+7h] [ebp-1h]
  color32_s resultantColor; // [esp+Ch] [ebp+4h]
  color32_s resultantColora; // [esp+Ch] [ebp+4h]

  v3 = (double)this->m_Color.r * 0.00392156862745098;
  if ( bTop )
  {
    v4 = (int)(float)(v3 * (float)this->m_TopColor.r);
    v5 = (double)this->m_Color.g * 0.00392156862745098;
    v6 = (int)(float)(v5 * (float)this->m_TopColor.g);
    v7 = (double)this->m_Color.b * 0.00392156862745098;
    v23 = (int)(float)(v7 * (float)this->m_TopColor.b);
    v8 = (double)this->m_Color.a * 0.00392156862745098;
    v24 = (int)(float)(v8 * (float)this->m_TopColor.a);
    v9 = (double)(unsigned __int8)parentColor * 0.00392156862745098;
    resultantColor.r = (int)(float)(v9 * (float)(unsigned __int8)v4);
    v10 = (double)BYTE1(parentColor) * 0.00392156862745098;
    resultantColor.g = (int)(float)(v10 * (float)(unsigned __int8)v6);
    v11 = (double)BYTE2(parentColor) * 0.00392156862745098;
    v12 = (double)HIBYTE(parentColor) * 0.00392156862745098;
    resultantColor.b = (int)(float)(v11 * (float)v23);
    resultantColor.a = (int)(float)(v12 * (float)v24);
    CGeometry::SetTopVerticesColor(this, c: resultantColor);
  }
  else
  {
    v13 = (int)(float)(v3 * (float)this->m_BottomColor.r);
    v14 = (double)this->m_Color.g * 0.00392156862745098;
    v15 = (int)(float)(v14 * (float)this->m_BottomColor.g);
    v16 = (double)this->m_Color.b * 0.00392156862745098;
    v17 = (int)(float)(v16 * (float)this->m_BottomColor.b);
    v18 = (double)this->m_Color.a * 0.00392156862745098;
    v25 = (int)(float)(v18 * (float)this->m_BottomColor.a);
    v19 = (double)(unsigned __int8)parentColor * 0.00392156862745098;
    resultantColora.r = (int)(float)(v19 * (float)(unsigned __int8)v13);
    v20 = (double)BYTE1(parentColor) * 0.00392156862745098;
    resultantColora.g = (int)(float)(v20 * (float)(unsigned __int8)v15);
    v21 = (double)BYTE2(parentColor) * 0.00392156862745098;
    resultantColora.b = (int)(float)(v21 * (float)(unsigned __int8)v17);
    v22 = (double)HIBYTE(parentColor) * 0.00392156862745098;
    resultantColora.a = (int)(float)(v22 * (float)v25);
    CGeometry::SetBottomVerticesColor(this, c: resultantColora);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417A30
// Name: public: CGeometry::CGeometry(void)
// Source: json
//------------------------------------------------------------------------------
CGeometry *__thiscall CGeometry::CGeometry(CGeometry *this)
{
  this->m_RelativePositions.m_Memory.m_pMemory = nullptr;
  this->m_RelativePositions.m_Memory.m_nAllocationCount = 0;
  this->m_RelativePositions.m_Memory.m_nGrowSize = 0;
  this->m_RelativePositions.m_Size = 0;
  this->m_RelativePositions.m_pElements = nullptr;
  this->m_TextureCoords.m_Memory.m_pMemory = nullptr;
  this->m_TextureCoords.m_Memory.m_nAllocationCount = 0;
  this->m_TextureCoords.m_Memory.m_nGrowSize = 0;
  this->m_TextureCoords.m_Size = 0;
  this->m_TextureCoords.m_pElements = nullptr;
  this->m_VertexColors.m_Memory.m_pMemory = nullptr;
  this->m_VertexColors.m_Memory.m_nAllocationCount = 0;
  this->m_VertexColors.m_Memory.m_nGrowSize = 0;
  this->m_VertexColors.m_Size = 0;
  this->m_VertexColors.m_pElements = nullptr;
  this->m_Triangles.m_Memory.m_pMemory = nullptr;
  this->m_Triangles.m_Memory.m_nAllocationCount = 0;
  this->m_Triangles.m_Memory.m_nGrowSize = 0;
  this->m_Triangles.m_Size = 0;
  this->m_Triangles.m_pElements = nullptr;
  this->m_AnimStartTime.m_tms = 0x80000000;
  this->m_Color.r = -1;
  this->m_Color.g = -1;
  this->m_Color.b = -1;
  this->m_Color.a = -1;
  this->m_TopColor.r = -1;
  this->m_TopColor.g = -1;
  this->m_TopColor.b = -1;
  this->m_TopColor.a = -1;
  this->m_BottomColor.r = -1;
  this->m_BottomColor.g = -1;
  this->m_BottomColor.b = -1;
  this->m_BottomColor.a = -1;
  this->m_Center.x = 0.0;
  this->m_Center.y = 0.0;
  this->m_Scale.x = 1.0;
  this->m_Scale.y = 1.0;
  this->m_Rotation = 0.0;
  this->m_bHorizontalGradient = false;
  this->m_SheetSequenceNumber = 0;
  this->m_AnimationRate = 1.0;
  this->m_Sublayer = -1;
  this->m_bMaintainAspectRatio = true;
  this->m_bVisible = true;
  this->m_AnimStartTime.m_tms = 0;
  this->m_bAnimate = false;
  this->m_bDirtyExtents = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00417B00
// Name: public: void CGeometry::SetResultantColor(struct color32_s)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGeometry::SetResultantColor(CGeometry *this, color32_s parentColor)
{
  CGeometry::SetResultantColor(this, bTop: true, parentColor: *(_DWORD *)&parentColor);
  CGeometry::SetResultantColor(this, bTop: false, parentColor: *(_DWORD *)&parentColor);
}

//------------------------------------------------------------------------------
// Address: 0x00417B70
// Name: public: void CGeometry::CalculateExtents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGeometry::CalculateExtents(CGeometry *this)
{
  int m_Size; // ebx
  int v3; // edi
  float *m_nAllocationCount; // edx
  Vector2D *m_pElements; // ebp
  float x; // xmm1_4
  int v7; // eax
  float v8; // xmm0_4
  float *v9; // eax
  Vector2D *i; // ecx
  int v11; // eax
  float v12; // xmm0_4
  float *v13; // eax
  bool v14; // sf
  Vector2D src; // [esp+4h] [ebp-34h] BYREF
  float v16[2]; // [esp+Ch] [ebp-2Ch] BYREF
  Vector screenpos; // [esp+14h] [ebp-24h] BYREF
  CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > screenPositions; // [esp+20h] [ebp-18h] BYREF
  int v19; // [esp+34h] [ebp-4h]

  if ( this->m_bDirtyExtents )
  {
    m_Size = this->m_RelativePositions.m_Size;
    v3 = 0;
    m_nAllocationCount = nullptr;
    m_pElements = nullptr;
    memset(&screenPositions.m_Memory.m_nAllocationCount, 0, 16);
    v19 = 0;
    if ( m_Size > 0 )
    {
      do
      {
        x = this->m_RelativePositions.m_Memory.m_pMemory[v3].x;
        v16[1] = this->m_RelativePositions.m_Memory.m_pMemory[v3].y;
        v16[0] = x;
        screenpos.x = 0.0;
        VectorTransform(in1: v16, in2: &this->m_ExtentsMatrix, out: &screenpos.y);
        src = *(Vector2D *)&screenpos.y;
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
          this: (CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)&screenPositions.m_Memory.m_nAllocationCount,
          elem: (int)m_pElements,
          &src);
        m_pElements = screenPositions.m_pElements;
        ++v3;
      }
      while ( v3 < m_Size );
      m_nAllocationCount = (float *)screenPositions.m_Memory.m_nAllocationCount;
    }
    v7 = 0;
    for ( this->m_Extents.m_TopLeft.x = 2147483600.0; v7 < (int)m_pElements; ++v7 )
    {
      v8 = m_nAllocationCount[2 * v7];
      if ( this->m_Extents.m_TopLeft.x > v8 )
        this->m_Extents.m_TopLeft.x = v8;
    }
    this->m_Extents.m_TopLeft.y = 2147483600.0;
    if ( (int)m_pElements > 0 )
    {
      v9 = m_nAllocationCount + 1;
      for ( i = m_pElements; i != nullptr; i = (Vector2D *)((char *)i - 1) )
      {
        if ( this->m_Extents.m_TopLeft.y > *v9 )
          this->m_Extents.m_TopLeft.y = *v9;
        v9 += 2;
      }
    }
    v11 = 0;
    for ( this->m_Extents.m_BottomRight.x = -2147483600.0; v11 < (int)m_pElements; ++v11 )
    {
      v12 = m_nAllocationCount[2 * v11];
      if ( v12 > this->m_Extents.m_BottomRight.x )
        this->m_Extents.m_BottomRight.x = v12;
    }
    this->m_Extents.m_BottomRight.y = -2147483600.0;
    if ( (int)m_pElements > 0 )
    {
      v13 = m_nAllocationCount + 1;
      do
      {
        if ( *v13 > this->m_Extents.m_BottomRight.y )
          this->m_Extents.m_BottomRight.y = *v13;
        v13 += 2;
        m_pElements = (Vector2D *)((char *)m_pElements - 1);
      }
      while ( m_pElements != nullptr );
    }
    v14 = screenPositions.m_Size < 0;
    this->m_bDirtyExtents = false;
    if ( !v14 && m_nAllocationCount != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417DB0
// Name: public: void CGeometry::UpdateRenderData(class CUtlVector<class CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>>,class CUtlMemory<class CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>>,int>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGeometry::UpdateRenderData(
        CGeometry *this,
        CUtlVector<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,CUtlMemory<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,int> > *renderGeometryLists,
        int firstListIndex)
{
  int v4; // edi
  CRenderGeometry *v5; // ebx
  float x; // xmm1_4
  int m_Size; // eax
  int v8; // edi
  Vector2D src; // [esp+4h] [ebp-20h] BYREF
  float v10[2]; // [esp+Ch] [ebp-18h] BYREF
  Vector screenpos; // [esp+14h] [ebp-10h] BYREF
  int nCount; // [esp+2Ch] [ebp+8h]
  int nCounta; // [esp+2Ch] [ebp+8h]

  if ( this->m_bVisible )
  {
    v4 = 0;
    v5 = &renderGeometryLists->m_Memory.m_pMemory[firstListIndex].m_Memory.m_pMemory[CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int>>::InsertBefore(
                                                                                       this: &renderGeometryLists->m_Memory.m_pMemory[firstListIndex],
                                                                                       elem: renderGeometryLists->m_Memory.m_pMemory[firstListIndex].m_Size)];
    nCount = this->m_RelativePositions.m_Size;
    if ( nCount > 0 )
    {
      do
      {
        x = this->m_RelativePositions.m_Memory.m_pMemory[v4].x;
        v10[1] = this->m_RelativePositions.m_Memory.m_pMemory[v4].y;
        v10[0] = x;
        screenpos.x = 0.0;
        VectorTransform(in1: v10, in2: &this->m_RenderToScreen, out: &screenpos.y);
        m_Size = v5->m_Positions.m_Size;
        src = *(Vector2D *)&screenpos.y;
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(this: &v5->m_Positions, elem: m_Size, &src);
        CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
          this: &v5->m_TextureCoords,
          elem: v5->m_TextureCoords.m_Size,
          src: &this->m_TextureCoords.m_Memory.m_pMemory[v4]);
        CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
          this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v5->m_VertexColors,
          elem: v5->m_VertexColors.m_Size,
          src: (vgui::TreeNode **)&this->m_VertexColors.m_Memory.m_pMemory[v4++]);
      }
      while ( v4 < nCount );
    }
    if ( this->m_Triangles.m_Size > 0 )
    {
      v8 = 0;
      nCounta = this->m_Triangles.m_Size;
      do
      {
        CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
          this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v5->m_Triangles,
          elem: v5->m_Triangles.m_Size,
          src: (const CVTFTexture::ResourceMemorySection *)&this->m_Triangles.m_Memory.m_pMemory[v8++]);
        --nCounta;
      }
      while ( nCounta != 0 );
    }
    v5->m_SheetSequenceNumber = this->m_SheetSequenceNumber;
    v5->m_AnimationRate = this->m_AnimationRate;
    v5->m_bAnimate = this->m_bAnimate;
    v5->m_AnimStartTime.m_tms = this->m_AnimStartTime.m_tms;
    v5->m_pImageAlias = nullptr;
    CGeometry::CalculateExtents(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417F10
// Name: public: void CGeometry::DrawExtents(class CUtlVector<class CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>>,class CUtlMemory<class CUtlVector<class CRenderGeometry,class CUtlMemory<class CRenderGeometry,int>>,int>> __near &,int,struct color32_s)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGeometry::DrawExtents(
        CGeometry *this,
        CUtlVector<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,CUtlMemory<CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int> >,int> > *renderGeometryLists,
        int firstListIndex,
        color32_s extentLineColor)
{
  int v5; // ebx
  CRenderGeometry *v6; // edi
  int m_Size; // eax
  int v8; // edx
  int v9; // edx
  int v10; // ecx
  int v11; // ecx
  int v12; // eax
  CRenderGeometry *v13; // eax
  CRenderGeometry *v14; // edi
  int v15; // eax
  int v16; // edx
  int v17; // edx
  int v18; // ecx
  int v19; // ecx
  int v20; // eax
  CRenderGeometry *v21; // edi
  int v22; // eax
  int v23; // edx
  int v24; // ecx
  int v25; // ecx
  int v26; // eax
  int v27; // edx
  CRenderGeometry *v28; // edi
  int v29; // eax
  int v30; // ecx
  int v31; // eax
  int v32; // ecx
  int v33; // ecx
  int v34; // eax
  int v35; // [esp-8h] [ebp-20h]
  int v36; // [esp-8h] [ebp-20h]
  int v37; // [esp-8h] [ebp-20h]
  int v38; // [esp-8h] [ebp-20h]
  int v39; // [esp-8h] [ebp-20h]
  int v40; // [esp-8h] [ebp-20h]
  int v41; // [esp-8h] [ebp-20h]
  int v42; // [esp-8h] [ebp-20h]
  int v43; // [esp-8h] [ebp-20h]
  int v44; // [esp-8h] [ebp-20h]
  int v45; // [esp-8h] [ebp-20h]
  int v46; // [esp-8h] [ebp-20h]
  int v47; // [esp-8h] [ebp-20h]
  int v48; // [esp-8h] [ebp-20h]
  int v49; // [esp-8h] [ebp-20h]
  CTriangle tri; // [esp+Ch] [ebp-Ch] BYREF

  if ( this->m_bVisible )
  {
    v5 = firstListIndex;
    v6 = &renderGeometryLists->m_Memory.m_pMemory[firstListIndex].m_Memory.m_pMemory[CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int>>::InsertBefore(
                                                                                       this: &renderGeometryLists->m_Memory.m_pMemory[firstListIndex],
                                                                                       elem: renderGeometryLists->m_Memory.m_pMemory[firstListIndex].m_Size)];
    m_Size = v6->m_Positions.m_Size;
    tri.m_PointIndex[0] = LODWORD(this->m_Extents.m_TopLeft.x);
    tri.m_PointIndex[1] = LODWORD(this->m_Extents.m_TopLeft.y);
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v6->m_Positions,
      elem: m_Size,
      src: (const Vector2D *)&tri);
    v35 = v6->m_TextureCoords.m_Size;
    tri.m_PointIndex[0] = 0;
    tri.m_PointIndex[1] = 0;
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v6->m_TextureCoords,
      elem: v35,
      src: (const Vector2D *)&tri);
    CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v6->m_VertexColors,
      elem: v6->m_VertexColors.m_Size,
      src: (vgui::TreeNode **)&extentLineColor);
    v8 = v6->m_Positions.m_Size;
    tri.m_PointIndex[0] = LODWORD(this->m_Extents.m_BottomRight.x);
    tri.m_PointIndex[1] = LODWORD(this->m_Extents.m_TopLeft.y);
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v6->m_Positions,
      elem: v8,
      src: (const Vector2D *)&tri);
    v9 = v6->m_TextureCoords.m_Size;
    tri.m_PointIndex[0] = 1065353216;
    tri.m_PointIndex[1] = 0;
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v6->m_TextureCoords,
      elem: v9,
      src: (const Vector2D *)&tri);
    CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v6->m_VertexColors,
      elem: v6->m_VertexColors.m_Size,
      src: (vgui::TreeNode **)&extentLineColor);
    v10 = v6->m_Positions.m_Size;
    tri.m_PointIndex[0] = LODWORD(this->m_Extents.m_BottomRight.x);
    *(float *)&tri.m_PointIndex[1] = this->m_Extents.m_TopLeft.y + 2.0;
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v6->m_Positions,
      elem: v10,
      src: (const Vector2D *)&tri);
    tri.m_PointIndex[0] = 1065353216;
    tri.m_PointIndex[1] = 1065353216;
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v6->m_TextureCoords,
      elem: v6->m_TextureCoords.m_Size,
      src: (const Vector2D *)&tri);
    CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v6->m_VertexColors,
      elem: v6->m_VertexColors.m_Size,
      src: (vgui::TreeNode **)&extentLineColor);
    v11 = v6->m_Positions.m_Size;
    tri.m_PointIndex[0] = LODWORD(this->m_Extents.m_TopLeft.x);
    *(float *)&tri.m_PointIndex[1] = this->m_Extents.m_TopLeft.y + 2.0;
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v6->m_Positions,
      elem: v11,
      src: (const Vector2D *)&tri);
    v12 = v6->m_TextureCoords.m_Size;
    tri.m_PointIndex[0] = 0;
    tri.m_PointIndex[1] = 1065353216;
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v6->m_TextureCoords,
      elem: v12,
      src: (const Vector2D *)&tri);
    CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v6->m_VertexColors,
      elem: v6->m_VertexColors.m_Size,
      src: (vgui::TreeNode **)&extentLineColor);
    v36 = v6->m_Triangles.m_Size;
    tri.m_PointIndex[0] = 0;
    tri.m_PointIndex[1] = 1;
    tri.m_PointIndex[2] = 2;
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v6->m_Triangles,
      elem: v36,
      src: (const CVTFTexture::ResourceMemorySection *)&tri);
    v37 = v6->m_Triangles.m_Size;
    tri.m_PointIndex[0] = 0;
    tri.m_PointIndex[1] = 2;
    tri.m_PointIndex[2] = 3;
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v6->m_Triangles,
      elem: v37,
      src: (const CVTFTexture::ResourceMemorySection *)&tri);
    v6->m_SheetSequenceNumber = 0;
    v6->m_AnimationRate = this->m_AnimationRate;
    v6->m_bAnimate = false;
    v6->m_AnimStartTime.m_tms = this->m_AnimStartTime.m_tms;
    v6->m_pImageAlias = nullptr;
    v13 = &renderGeometryLists->m_Memory.m_pMemory[v5].m_Memory.m_pMemory[CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int>>::InsertBefore(
                                                                            this: &renderGeometryLists->m_Memory.m_pMemory[v5],
                                                                            elem: renderGeometryLists->m_Memory.m_pMemory[v5].m_Size)];
    *(float *)tri.m_PointIndex = this->m_Extents.m_BottomRight.x - 2.0;
    v14 = v13;
    v15 = v13->m_Positions.m_Size;
    tri.m_PointIndex[1] = LODWORD(this->m_Extents.m_TopLeft.y);
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v14->m_Positions,
      elem: v15,
      src: (const Vector2D *)&tri);
    v38 = v14->m_TextureCoords.m_Size;
    tri.m_PointIndex[0] = 0;
    tri.m_PointIndex[1] = 0;
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v14->m_TextureCoords,
      elem: v38,
      src: (const Vector2D *)&tri);
    CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v14->m_VertexColors,
      elem: v14->m_VertexColors.m_Size,
      src: (vgui::TreeNode **)&extentLineColor);
    v16 = v14->m_Positions.m_Size;
    tri.m_PointIndex[0] = LODWORD(this->m_Extents.m_BottomRight.x);
    tri.m_PointIndex[1] = LODWORD(this->m_Extents.m_TopLeft.y);
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v14->m_Positions,
      elem: v16,
      src: (const Vector2D *)&tri);
    v17 = v14->m_TextureCoords.m_Size;
    tri.m_PointIndex[0] = 1065353216;
    tri.m_PointIndex[1] = 0;
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v14->m_TextureCoords,
      elem: v17,
      src: (const Vector2D *)&tri);
    CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v14->m_VertexColors,
      elem: v14->m_VertexColors.m_Size,
      src: (vgui::TreeNode **)&extentLineColor);
    v18 = v14->m_Positions.m_Size;
    tri.m_PointIndex[0] = LODWORD(this->m_Extents.m_BottomRight.x);
    tri.m_PointIndex[1] = LODWORD(this->m_Extents.m_BottomRight.y);
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v14->m_Positions,
      elem: v18,
      src: (const Vector2D *)&tri);
    v39 = v14->m_TextureCoords.m_Size;
    tri.m_PointIndex[0] = 1065353216;
    tri.m_PointIndex[1] = 1065353216;
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v14->m_TextureCoords,
      elem: v39,
      src: (const Vector2D *)&tri);
    CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v14->m_VertexColors,
      elem: v14->m_VertexColors.m_Size,
      src: (vgui::TreeNode **)&extentLineColor);
    v19 = v14->m_Positions.m_Size;
    *(float *)tri.m_PointIndex = this->m_Extents.m_BottomRight.x - 2.0;
    tri.m_PointIndex[1] = LODWORD(this->m_Extents.m_BottomRight.y);
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v14->m_Positions,
      elem: v19,
      src: (const Vector2D *)&tri);
    v20 = v14->m_TextureCoords.m_Size;
    tri.m_PointIndex[0] = 0;
    tri.m_PointIndex[1] = 1065353216;
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v14->m_TextureCoords,
      elem: v20,
      src: (const Vector2D *)&tri);
    CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v14->m_VertexColors,
      elem: v14->m_VertexColors.m_Size,
      src: (vgui::TreeNode **)&extentLineColor);
    v40 = v14->m_Triangles.m_Size;
    tri.m_PointIndex[0] = 0;
    tri.m_PointIndex[1] = 1;
    tri.m_PointIndex[2] = 2;
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v14->m_Triangles,
      elem: v40,
      src: (const CVTFTexture::ResourceMemorySection *)&tri);
    v41 = v14->m_Triangles.m_Size;
    tri.m_PointIndex[0] = 0;
    tri.m_PointIndex[1] = 2;
    tri.m_PointIndex[2] = 3;
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v14->m_Triangles,
      elem: v41,
      src: (const CVTFTexture::ResourceMemorySection *)&tri);
    v14->m_SheetSequenceNumber = 0;
    v14->m_AnimationRate = this->m_AnimationRate;
    v14->m_bAnimate = false;
    v14->m_AnimStartTime.m_tms = this->m_AnimStartTime.m_tms;
    v14->m_pImageAlias = nullptr;
    v21 = &renderGeometryLists->m_Memory.m_pMemory[v5].m_Memory.m_pMemory[CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int>>::InsertBefore(
                                                                            this: &renderGeometryLists->m_Memory.m_pMemory[v5],
                                                                            elem: renderGeometryLists->m_Memory.m_pMemory[v5].m_Size)];
    v22 = v21->m_Positions.m_Size;
    tri.m_PointIndex[0] = LODWORD(this->m_Extents.m_TopLeft.x);
    *(float *)&tri.m_PointIndex[1] = this->m_Extents.m_BottomRight.y - 2.0;
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v21->m_Positions,
      elem: v22,
      src: (const Vector2D *)&tri);
    v42 = v21->m_TextureCoords.m_Size;
    tri.m_PointIndex[0] = 0;
    tri.m_PointIndex[1] = 0;
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v21->m_TextureCoords,
      elem: v42,
      src: (const Vector2D *)&tri);
    CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v21->m_VertexColors,
      elem: v21->m_VertexColors.m_Size,
      src: (vgui::TreeNode **)&extentLineColor);
    tri.m_PointIndex[0] = LODWORD(this->m_Extents.m_BottomRight.x);
    v43 = v21->m_Positions.m_Size;
    *(float *)&tri.m_PointIndex[1] = this->m_Extents.m_BottomRight.y - 2.0;
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v21->m_Positions,
      elem: v43,
      src: (const Vector2D *)&tri);
    v23 = v21->m_TextureCoords.m_Size;
    tri.m_PointIndex[0] = 1065353216;
    tri.m_PointIndex[1] = 0;
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v21->m_TextureCoords,
      elem: v23,
      src: (const Vector2D *)&tri);
    CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v21->m_VertexColors,
      elem: v21->m_VertexColors.m_Size,
      src: (vgui::TreeNode **)&extentLineColor);
    v24 = v21->m_Positions.m_Size;
    tri.m_PointIndex[0] = LODWORD(this->m_Extents.m_BottomRight.x);
    tri.m_PointIndex[1] = LODWORD(this->m_Extents.m_BottomRight.y);
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v21->m_Positions,
      elem: v24,
      src: (const Vector2D *)&tri);
    v44 = v21->m_TextureCoords.m_Size;
    tri.m_PointIndex[0] = 1065353216;
    tri.m_PointIndex[1] = 1065353216;
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v21->m_TextureCoords,
      elem: v44,
      src: (const Vector2D *)&tri);
    CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v21->m_VertexColors,
      elem: v21->m_VertexColors.m_Size,
      src: (vgui::TreeNode **)&extentLineColor);
    v25 = v21->m_Positions.m_Size;
    tri.m_PointIndex[0] = LODWORD(this->m_Extents.m_TopLeft.x);
    tri.m_PointIndex[1] = LODWORD(this->m_Extents.m_BottomRight.y);
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v21->m_Positions,
      elem: v25,
      src: (const Vector2D *)&tri);
    v26 = v21->m_TextureCoords.m_Size;
    tri.m_PointIndex[0] = 0;
    tri.m_PointIndex[1] = 1065353216;
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v21->m_TextureCoords,
      elem: v26,
      src: (const Vector2D *)&tri);
    CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v21->m_VertexColors,
      elem: v21->m_VertexColors.m_Size,
      src: (vgui::TreeNode **)&extentLineColor);
    v27 = v21->m_Triangles.m_Size;
    tri.m_PointIndex[0] = 0;
    tri.m_PointIndex[1] = 1;
    tri.m_PointIndex[2] = 2;
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v21->m_Triangles,
      elem: v27,
      src: (const CVTFTexture::ResourceMemorySection *)&tri);
    v45 = v21->m_Triangles.m_Size;
    tri.m_PointIndex[0] = 0;
    tri.m_PointIndex[1] = 2;
    tri.m_PointIndex[2] = 3;
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v21->m_Triangles,
      elem: v45,
      src: (const CVTFTexture::ResourceMemorySection *)&tri);
    v21->m_SheetSequenceNumber = 0;
    v21->m_AnimationRate = this->m_AnimationRate;
    v21->m_bAnimate = false;
    v21->m_AnimStartTime.m_tms = this->m_AnimStartTime.m_tms;
    v21->m_pImageAlias = nullptr;
    v28 = &renderGeometryLists->m_Memory.m_pMemory[v5].m_Memory.m_pMemory[CUtlVector<CRenderGeometry,CUtlMemory<CRenderGeometry,int>>::InsertBefore(
                                                                            this: &renderGeometryLists->m_Memory.m_pMemory[v5],
                                                                            elem: renderGeometryLists->m_Memory.m_pMemory[v5].m_Size)];
    v29 = v28->m_Positions.m_Size;
    tri.m_PointIndex[0] = LODWORD(this->m_Extents.m_TopLeft.x);
    tri.m_PointIndex[1] = LODWORD(this->m_Extents.m_TopLeft.y);
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v28->m_Positions,
      elem: v29,
      src: (const Vector2D *)&tri);
    v46 = v28->m_TextureCoords.m_Size;
    tri.m_PointIndex[0] = 0;
    tri.m_PointIndex[1] = 0;
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v28->m_TextureCoords,
      elem: v46,
      src: (const Vector2D *)&tri);
    CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v28->m_VertexColors,
      elem: v28->m_VertexColors.m_Size,
      src: (vgui::TreeNode **)&extentLineColor);
    v30 = v28->m_Positions.m_Size;
    *(float *)tri.m_PointIndex = this->m_Extents.m_TopLeft.x + 2.0;
    tri.m_PointIndex[1] = LODWORD(this->m_Extents.m_TopLeft.y);
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v28->m_Positions,
      elem: v30,
      src: (const Vector2D *)&tri);
    v31 = v28->m_TextureCoords.m_Size;
    tri.m_PointIndex[0] = 1065353216;
    tri.m_PointIndex[1] = 0;
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v28->m_TextureCoords,
      elem: v31,
      src: (const Vector2D *)&tri);
    CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v28->m_VertexColors,
      elem: v28->m_VertexColors.m_Size,
      src: (vgui::TreeNode **)&extentLineColor);
    v32 = v28->m_Positions.m_Size;
    *(float *)tri.m_PointIndex = this->m_Extents.m_TopLeft.x + 2.0;
    tri.m_PointIndex[1] = LODWORD(this->m_Extents.m_BottomRight.y);
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v28->m_Positions,
      elem: v32,
      src: (const Vector2D *)&tri);
    v47 = v28->m_TextureCoords.m_Size;
    tri.m_PointIndex[0] = 1065353216;
    tri.m_PointIndex[1] = 1065353216;
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v28->m_TextureCoords,
      elem: v47,
      src: (const Vector2D *)&tri);
    CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v28->m_VertexColors,
      elem: v28->m_VertexColors.m_Size,
      src: (vgui::TreeNode **)&extentLineColor);
    v33 = v28->m_Positions.m_Size;
    tri.m_PointIndex[0] = LODWORD(this->m_Extents.m_TopLeft.x);
    tri.m_PointIndex[1] = LODWORD(this->m_Extents.m_BottomRight.y);
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v28->m_Positions,
      elem: v33,
      src: (const Vector2D *)&tri);
    v34 = v28->m_TextureCoords.m_Size;
    tri.m_PointIndex[0] = 0;
    tri.m_PointIndex[1] = 1065353216;
    CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
      this: &v28->m_TextureCoords,
      elem: v34,
      src: (const Vector2D *)&tri);
    CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
      this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v28->m_VertexColors,
      elem: v28->m_VertexColors.m_Size,
      src: (vgui::TreeNode **)&extentLineColor);
    v48 = v28->m_Triangles.m_Size;
    tri.m_PointIndex[0] = 0;
    tri.m_PointIndex[1] = 1;
    tri.m_PointIndex[2] = 2;
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v28->m_Triangles,
      elem: v48,
      src: (const CVTFTexture::ResourceMemorySection *)&tri);
    v49 = v28->m_Triangles.m_Size;
    tri.m_PointIndex[0] = 0;
    tri.m_PointIndex[1] = 2;
    tri.m_PointIndex[2] = 3;
    CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
      this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v28->m_Triangles,
      elem: v49,
      src: (const CVTFTexture::ResourceMemorySection *)&tri);
    v28->m_SheetSequenceNumber = 0;
    v28->m_AnimationRate = this->m_AnimationRate;
    v28->m_bAnimate = false;
    v28->m_AnimStartTime.m_tms = this->m_AnimStartTime.m_tms;
    v28->m_pImageAlias = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004698F0
// Name: public: int CRenderGeometry::GetTriangleCount(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CRenderGeometry::GetTriangleCount(vgui::Panel *this)
{
  return this->_vpanel;
}

//------------------------------------------------------------------------------
// Address: 0x00417B20
// Name: class CRenderGeometry __near * Construct<class CRenderGeometry>(class CRenderGeometry __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRenderGeometry *__cdecl Construct<CRenderGeometry>(CRenderGeometry *pMemory)
{
  CRenderGeometry *result; // eax

  result = pMemory;
  if ( pMemory == nullptr )
    return nullptr;
  pMemory->m_Positions.m_Memory.m_pMemory = nullptr;
  pMemory->m_Positions.m_Memory.m_nAllocationCount = 0;
  pMemory->m_Positions.m_Memory.m_nGrowSize = 0;
  pMemory->m_Positions.m_Size = 0;
  pMemory->m_Positions.m_pElements = nullptr;
  pMemory->m_TextureCoords.m_Memory.m_pMemory = nullptr;
  pMemory->m_TextureCoords.m_Memory.m_nAllocationCount = 0;
  pMemory->m_TextureCoords.m_Memory.m_nGrowSize = 0;
  pMemory->m_TextureCoords.m_Size = 0;
  pMemory->m_TextureCoords.m_pElements = nullptr;
  pMemory->m_VertexColors.m_Memory.m_pMemory = nullptr;
  pMemory->m_VertexColors.m_Memory.m_nAllocationCount = 0;
  pMemory->m_VertexColors.m_Memory.m_nGrowSize = 0;
  pMemory->m_VertexColors.m_Size = 0;
  pMemory->m_VertexColors.m_pElements = nullptr;
  pMemory->m_Triangles.m_Memory.m_pMemory = nullptr;
  pMemory->m_Triangles.m_Memory.m_nAllocationCount = 0;
  pMemory->m_Triangles.m_Memory.m_nGrowSize = 0;
  pMemory->m_Triangles.m_Size = 0;
  pMemory->m_Triangles.m_pElements = nullptr;
  pMemory->m_AnimStartTime.m_tms = 0x80000000;
  return result;
}
