// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/tooldisplace.cpp
// Functions: 32
// ============================================================

#include "hammer\tooldisplace.h"

//------------------------------------------------------------------------------
// Address: 0x1015B300
// Name: public: virtual void CToolDisplace::OnActivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolDisplace::OnActivate(CToolDisplace *this)
{
  CMapDisp::SetSelectMask(bSelectMask: this->m_bSelectMaskTool);
  CMapDisp::SetGridMask(bGridMask: this->m_bGridMaskTool);
}

//------------------------------------------------------------------------------
// Address: 0x1015B330
// Name: public: virtual void CToolDisplace::OnDeactivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolDisplace::OnDeactivate(CToolDisplace *this)
{
  CMapDisp::SetSelectMask(bSelectMask: false);
  CMapDisp::SetGridMask(bGridMask: false);
  if ( CToolManager::GetActiveToolID(this: this->m_pDocument->m_pToolManager) != TOOL_FACEEDIT_MATERIAL )
    CMapDoc::SelectFace(this: this->m_pDocument, pSolid: 0, cmd: 16);
}

//------------------------------------------------------------------------------
// Address: 0x1015B370
// Name: private: void CToolDisplace::UpdateMapViews(class CMapView3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolDisplace::UpdateMapViews(CToolDisplace *this, CMapView3D *pView)
{
  CMapDoc *v2; // eax

  v2 = pView->GetMapDoc(this: &pView->CMapView);
  if ( v2 != nullptr )
    v2->SetModifiedFlag(this: v2, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1015B3A0
// Name: public: virtual bool CToolDisplace::OnRMouseUp3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolDisplace::OnRMouseUp3D(
        CToolDisplace *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  bool v4; // zf
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax

  v4 = this->m_uiTool == 6;
  this->m_bRMBDown = false;
  if ( v4 )
  {
    this->m_SculptTool->OnRMouseUp3D(this: this->m_SculptTool, a2: pView, a3: nFlags, a4: vPoint);
    return 1;
  }
  else
  {
    ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
    if ( ActiveWorldEditDispManager != nullptr )
      ActiveWorldEditDispManager->PostUndo(this: ActiveWorldEditDispManager);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015B3F0
// Name: protected: void CToolDisplace::ApplyPaintTool(unsigned int,class Vector2D const __near &,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolDisplace::ApplyPaintTool(
        CToolDisplace *this,
        unsigned int nFlags,
        const Vector2D *vPoint,
        CMapDisp *pDisp)
{
  CDispMapImageFilter *v5; // edx
  CDispMapImageFilterManager *p_m_FilterRaiseLowerMgr; // ecx
  double m_flPaintValueData; // st7
  CDispMapImageFilter *v8; // esi
  int v9; // edx
  float v10; // xmm1_4
  double m_flPaintValueGeo; // st7

  switch ( this->m_uiEffect )
  {
    case 0u:
      v5 = this->m_FilterRaiseLowerMgr.m_pFilterList[this->m_FilterRaiseLowerMgr.m_ActiveFilter];
      p_m_FilterRaiseLowerMgr = &this->m_FilterRaiseLowerMgr;
      if ( v5 == nullptr )
        return;
      v5->m_DataType = this->m_iPaintChannel;
      if ( this->m_iPaintChannel != 0 )
      {
        if ( this->m_iPaintChannel != 1 )
          goto LABEL_8;
        m_flPaintValueData = this->m_flPaintValueData;
      }
      else
      {
        m_flPaintValueData = this->m_flPaintValueGeo;
      }
      v5->m_Scale = m_flPaintValueData;
LABEL_8:
      if ( this->m_bRMBDown )
        LODWORD(v5->m_Scale) ^= _mask__NegFloat_;
      goto LABEL_26;
    case 1u:
      v5 = this->m_FilterRaiseToMgr.m_pFilterList[this->m_FilterRaiseToMgr.m_ActiveFilter];
      p_m_FilterRaiseLowerMgr = &this->m_FilterRaiseToMgr;
      if ( v5 == nullptr )
        return;
      v5->m_DataType = this->m_iPaintChannel;
      if ( this->m_iPaintChannel != 0 )
      {
        if ( this->m_iPaintChannel != 1 )
          goto LABEL_26;
        m_flPaintValueGeo = this->m_flPaintValueData;
      }
      else
      {
        m_flPaintValueGeo = this->m_flPaintValueGeo;
      }
      v5->m_Scale = m_flPaintValueGeo;
LABEL_26:
      CDispMapImageFilterManager::Apply(
        this: p_m_FilterRaiseLowerMgr,
        pFilter: v5,
        pDisp,
        paintDirType: this->m_iPaintAxis,
        vPaintDir: &this->m_vecPaintAxis,
        bSew: this->m_bAutoSew);
      return;
    case 2u:
      v8 = this->m_FilterSmoothMgr.m_pFilterList[this->m_FilterSmoothMgr.m_ActiveFilter];
      if ( v8 == nullptr )
        return;
      v8->m_DataType = this->m_iPaintChannel;
      v8->m_Scale = 1.0;
      v9 = 3;
      if ( this->m_iPaintChannel != 0 )
      {
        if ( this->m_iPaintChannel != 1 )
          goto LABEL_19;
        v10 = this->m_flPaintValueData;
      }
      else
      {
        v10 = this->m_flPaintValueGeo;
      }
      v9 = (int)(float)((float)(v10 * 2.0) + 1.0);
      if ( v9 >= 3 )
      {
        if ( v9 > 7 )
          v9 = 7;
      }
      else
      {
        v9 = 3;
      }
LABEL_19:
      v8->m_AreaHeight = v9;
      v8->m_AreaWidth = v9;
      CDispMapImageFilterManager::Apply(
        this: &this->m_FilterSmoothMgr,
        pFilter: v8,
        pDisp,
        paintDirType: this->m_iPaintAxis,
        vPaintDir: &this->m_vecPaintAxis,
        bSew: this->m_bAutoSew);
      return;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015B5A0
// Name: protected: void CToolDisplace::ApplySpatialPaintTool(unsigned int,class Vector2D const __near &,class CMapDisp __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolDisplace::ApplySpatialPaintTool(
        CToolDisplace *this,
        unsigned int nFlags,
        const Vector2D *vPoint,
        CMapDisp *pDisp)
{
  int m_HitTexelIndex; // eax
  bool v5; // zf
  float m_flSpatialRadius; // xmm0_4
  unsigned int m_uiBrushType; // edx
  float m_flPaintValueGeo; // xmm0_4
  CoreDispVert_t *m_pVerts; // edx
  int v10; // eax
  float x; // xmm0_4
  int p_m_Vert; // eax
  float v13; // xmm0_4
  SpatialPaintData_t spatialData; // [esp+0h] [ebp-34h] BYREF

  if ( this->m_uiEffect == 0 || !this->m_bRMBDown )
  {
    m_HitTexelIndex = pDisp->m_HitTexelIndex;
    if ( m_HitTexelIndex != -1 )
    {
      v5 = !this->m_bRMBDown;
      m_flSpatialRadius = this->m_flSpatialRadius;
      spatialData.m_nEffect = this->m_uiEffect;
      m_uiBrushType = this->m_uiBrushType;
      spatialData.m_flRadius = m_flSpatialRadius;
      m_flPaintValueGeo = this->m_flPaintValueGeo;
      spatialData.m_uiBrushType = m_uiBrushType;
      spatialData.m_flScalar = m_flPaintValueGeo;
      spatialData.m_bNudge = false;
      if ( !v5 )
        LODWORD(spatialData.m_flScalar) = LODWORD(m_flPaintValueGeo) ^ _mask__NegFloat_;
      m_pVerts = pDisp->m_CoreDispInfo.m_pVerts;
      v10 = m_HitTexelIndex;
      x = m_pVerts[v10].m_Vert.x;
      p_m_Vert = (int)&m_pVerts[v10].m_Vert;
      spatialData.m_vCenter.x = x;
      spatialData.m_vCenter.y = *(float *)(p_m_Vert + 4);
      v13 = *(float *)(p_m_Vert + 8);
      LOBYTE(p_m_Vert) = this->m_bAutoSew;
      spatialData.m_vCenter.z = v13;
      spatialData.m_vPaintAxis = this->m_vecPaintAxis;
      CDispPaintMgr::Paint(this: &this->m_DispPaintMgr, &spatialData, bAutoSew: p_m_Vert);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015B680
// Name: protected: void CToolDisplace::ResizeSpatialRadius_Do(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolDisplace::ResizeSpatialRadius_Do(CToolDisplace *this)
{
  float v2; // xmm0_4
  CFaceEditSheet *m_pFaceEditSheet; // eax
  int x; // [esp-8h] [ebp-24h]
  int y; // [esp-4h] [ebp-20h]
  CPoint cursorPos; // [esp+Ch] [ebp-10h] BYREF

  cursorPos.x = 0;
  cursorPos.y = 0;
  GetCursorPos(lpPoint: &cursorPos);
  if ( (int)abs32(cursorPos.x - this->m_viewCenter.x) >= (int)abs32(cursorPos.y - this->m_viewCenter.y) )
    v2 = (float)(cursorPos.x - this->m_viewCenter.x);
  else
    v2 = (float)(cursorPos.y - this->m_viewCenter.y);
  y = this->m_viewCenter.y;
  x = this->m_viewCenter.x;
  this->m_flSpatialRadius = COERCE_FLOAT(LODWORD(v2) ^ _mask__NegFloat_) + this->m_flSpatialRadius;
  SetCursorPos(X: x, Y: y);
  m_pFaceEditSheet = GetMainWnd()->m_pFaceEditSheet;
  if ( m_pFaceEditSheet != nullptr )
    CFaceEditDispPage::UpdatePaintDialogs(this: &m_pFaceEditSheet->m_DispPage);
}

//------------------------------------------------------------------------------
// Address: 0x1015B720
// Name: protected: void CToolDisplace::HandleSelection(class CMapView3D __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolDisplace::HandleSelection(CToolDisplace *this, CMapView3D *pView, const Vector2D *vPoint)
{
  CMapClass *v3; // esi
  int v4; // ebx
  CMapDoc *v5; // ecx
  unsigned int ulFace; // [esp+8h] [ebp-8h] BYREF
  bool bShift; // [esp+Fh] [ebp-1h]

  bShift = GetAsyncKeyState(vKey: 16) < 0;
  v3 = CMapView3D::NearestObjectAt(this: pView, vPoint, &ulFace, nFlags: 0, pLocalMatrix: nullptr);
  if ( v3 != nullptr && v3->IsMapClass(this: v3, a2: CMapSolid::__Type) != 0 )
  {
    v4 = 17;
    if ( GetAsyncKeyState(vKey: 17) < 0 )
      v4 = 1;
    v5 = pView->GetMapDoc(this: &pView->CMapView);
    if ( v5 != nullptr )
    {
      if ( bShift )
        CMapDoc::SelectFace(this: v5, pSolid: (unsigned int)v3 | 0xFFFFFFFF00000000uLL, cmd: v4);
      else
        CMapDoc::SelectFace(this: v5, pSolid: __PAIR64__(ulFace, (unsigned int)v3), cmd: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015B7D0
// Name: private: void CToolDisplace::BuildParallelepiped(class Vector const __near &,class Vector const __near &,struct PLANE __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolDisplace::BuildParallelepiped(
        CToolDisplace *this,
        const Vector *boxMin,
        const Vector *boxMax,
        PLANE *planes)
{
  int v4; // esi
  int i; // edi
  int v6; // ecx
  float *p_dist; // eax
  float *v8; // edx

  v4 = 0;
  for ( i = 0; i < 3; ++i )
  {
    v6 = -1;
    p_dist = &planes[v4].dist;
    v8 = &planes[v4].normal.x + i;
    do
    {
      *(p_dist - 1) = 0.0;
      *(p_dist - 2) = 0.0;
      *(p_dist - 3) = 0.0;
      *v8 = (float)v6;
      if ( v6 == 1 )
        *p_dist = *(&boxMax->x + i);
      else
        *p_dist = -*(&boxMin->x + i);
      v6 += 2;
      ++v4;
      v8 += 13;
      p_dist += 13;
    }
    while ( v6 < 2 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015B860
// Name: private: void CToolDisplace::AddFiltersToManagers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolDisplace::AddFiltersToManagers(CToolDisplace *this)
{
  int v2; // edi
  int i; // ebx
  _DWORD *v4; // eax
  CDispMapImageFilterManager *p_m_FilterRaiseLowerMgr; // ecx
  int count; // [esp+8h] [ebp-4h]

  v2 = 0;
  count = this->m_FilterLoaderMgr.m_FilterCount;
  if ( count > 0 )
  {
    for ( i = 8; ; i += 4 )
    {
      if ( v2 >= 0 )
      {
        if ( v2 >= this->m_FilterLoaderMgr.m_FilterCount )
          goto LABEL_13;
        v4 = *(_DWORD **)((char *)&this->m_FilterLoaderMgr.m_ActiveFilter + i);
        if ( v4 == nullptr )
          goto LABEL_13;
        if ( *v4 == 0 )
        {
          p_m_FilterRaiseLowerMgr = &this->m_FilterRaiseLowerMgr;
          goto LABEL_12;
        }
        if ( *v4 == 1 )
          break;
        if ( *v4 == 2 )
        {
          p_m_FilterRaiseLowerMgr = &this->m_FilterSmoothMgr;
LABEL_12:
          CDispMapImageFilterManager::Add(
            this: p_m_FilterRaiseLowerMgr,
            pFilter: *(CDispMapImageFilter **)((char *)&this->m_FilterLoaderMgr.m_ActiveFilter + i));
        }
      }
LABEL_13:
      if ( ++v2 >= count )
        return;
    }
    p_m_FilterRaiseLowerMgr = &this->m_FilterRaiseToMgr;
    goto LABEL_12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015B8D0
// Name: private: static enum ChunkFileResult_t CToolDisplace::LoadFiltersCallback(class CChunkFile __near *,class CToolDisplace __near *)
// Source: json
//------------------------------------------------------------------------------
ChunkFileResult_t __cdecl CToolDisplace::LoadFiltersCallback(CChunkFile *pFile, CToolDisplace *pDisplaceTool)
{
  CDispMapImageFilter *v2; // eax

  v2 = CDispMapImageFilterManager::Create(this: &pDisplaceTool->m_FilterLoaderMgr);
  if ( v2 != nullptr )
    return CDispMapImageFilter::LoadFilter(this: v2, pFile);
  else
    return ChunkFile_Fail;
}

//------------------------------------------------------------------------------
// Address: 0x1015B900
// Name: private: void CToolDisplace::RenderPaintSphere(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolDisplace::RenderPaintSphere(CToolDisplace *this, CRender3D *pRender)
{
  CEditDispMgr *v3; // eax
  int v4; // eax
  int v5; // ebx
  int v6; // esi
  int v7; // eax
  int v8; // esi
  float v9; // xmm0_4
  int v10; // eax
  float m_flSpatialRadius; // xmm0_4
  int v12; // eax
  float v15; // xmm2_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  int v18; // eax
  float v19; // xmm0_4
  Vector Mins; // [esp+24h] [ebp-38h] BYREF
  Vector Maxs; // [esp+30h] [ebp-2Ch] BYREF
  Vector v22; // [esp+3Ch] [ebp-20h] BYREF
  Vector vBoxMin; // [esp+48h] [ebp-14h] BYREF
  Vector vBoxMax; // [esp+54h] [ebp-8h]
  float v25; // [esp+64h] [ebp+8h]

  LODWORD(vBoxMax.y) = this;
  if ( this->m_EditDispHandle != 0xFFFF )
  {
    v3 = EditDispMgr();
    v4 = (int)v3->GetDisp(this: v3, a2: this->m_EditDispHandle);
    v5 = v4;
    if ( v4 != 0 )
    {
      v6 = *(_DWORD *)(v4 + 868);
      if ( v6 != -1 )
      {
        v7 = *(_DWORD *)(v4 + 784);
        v8 = 224 * v6;
        v9 = *(float *)(v7 + v8 + 40);
        v10 = v7 + v8 + 40;
        vBoxMin.x = v9;
        vBoxMin.y = *(float *)(v10 + 4);
        vBoxMin.z = *(float *)(v10 + 8);
        m_flSpatialRadius = this->m_flSpatialRadius;
        v12 = (int)(float)(m_flSpatialRadius * 0.050000001);
        vBoxMax.x = m_flSpatialRadius;
        if ( v12 >= 6 )
        {
          if ( v12 > 12 )
            v12 = 12;
        }
        else
        {
          v12 = 6;
        }
        if ( !this->m_bNudge )
          CRender3D::RenderWireframeSphere(
            this: pRender,
            vCenter: &vBoxMin,
            flRadius: m_flSpatialRadius,
            nTheta: v12,
            nPhi: v12,
            chRed: 0,
            chGreen: 0xFFu,
            chBlue: 0);
        else
          CRender3D::RenderWireframeSphere(
            this: pRender,
            vCenter: &vBoxMin,
            flRadius: m_flSpatialRadius,
            nTheta: v12,
            nPhi: v12,
            chRed: 0xFFu,
            chGreen: 0xFFu,
            chBlue: 0);
        v15 = *(float *)(LODWORD(vBoxMax.y) + 1160);
        v16 = *(float *)(LODWORD(vBoxMax.y) + 1164);
        v17 = *(float *)(LODWORD(vBoxMax.y) + 1168);
        if ( *(_DWORD *)(LODWORD(vBoxMax.y) + 1156) == 3 )
        {
          v18 = *(_DWORD *)(v5 + 784);
          v15 = *(float *)(v18 + v8 + 16);
          v16 = *(float *)(v18 + v8 + 20);
          v17 = *(float *)(v18 + v8 + 24);
        }
        v25 = vBoxMax.x * 0.15000001;
        v19 = (float)(vBoxMax.x * 0.15000001) + vBoxMax.x;
        v22.x = (float)(v15 * v19) + vBoxMin.x;
        v22.y = (float)(v19 * v16) + vBoxMin.y;
        v22.z = (float)(v19 * v17) + vBoxMin.z;
        CRender3D::RenderArrow(this: pRender, vStartPt: &vBoxMin, vEndPt: &v22, chRed: 255, chGreen: 255, chBlue: 0);
        Mins.x = vBoxMin.x - (float)(v25 * 0.25);
        Maxs.x = (float)(v25 * 0.25) + vBoxMin.x;
        Mins.y = vBoxMin.y - (float)(v25 * 0.25);
        Maxs.y = (float)(v25 * 0.25) + vBoxMin.y;
        Mins.z = vBoxMin.z - (float)(v25 * 0.25);
        Maxs.z = (float)(v25 * 0.25) + vBoxMin.z;
        CRender3D::RenderBox(
          this: pRender,
          &Mins,
          &Maxs,
          chRed: 0xFFu,
          chGreen: 0xFFu,
          chBlue: 0,
          eBoxSelectionState: SELECT_NONE);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015BB10
// Name: private: void CToolDisplace::RenderHitBox(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CToolDisplace::RenderHitBox(CToolDisplace *this@<ecx>, float a2@<ebp>, CRender3D *pRender)
{
  CEditDispMgr *v4; // eax
  CMapDisp *v5; // eax
  CMapDisp *v6; // edi
  int m_HitTexelIndex; // esi
  int v8; // esi
  int v9; // ecx
  float *p_x; // eax
  float v11; // xmm6_4
  float v12; // xmm7_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  int v15; // edx
  float v16; // xmm4_4
  float v17; // xmm5_4
  bool v18; // zf
  float v19; // xmm2_4
  float v20; // xmm3_4
  CoreDispVert_t *m_pVerts; // eax
  float v22; // xmm4_4
  float x; // xmm1_4
  float v24; // xmm5_4
  float y; // xmm2_4
  float v26; // xmm3_4
  __int128 v27; // xmm0
  float v28; // xmm4_4
  float z; // xmm3_4
  CoreDispVert_t *v30; // ecx
  float v31; // xmm4_4
  float v32; // xmm3_4
  float v33; // xmm5_4
  float v34; // xmm6_4
  float v35; // xmm0_4
  float v36; // xmm1_4
  float v37; // xmm2_4
  CoreDispVert_t *v38; // edx
  Vector v39; // [esp-Ch] [ebp-58h] BYREF
  _BYTE hbOrigin[36]; // [esp+0h] [ebp-4Ch] OVERLAPPED BYREF
  float v41; // [esp+24h] [ebp-28h]
  float v42; // [esp+28h] [ebp-24h]
  Vector minb; // [esp+2Ch] [ebp-20h] BYREF
  Vector maxb; // [esp+38h] [ebp-14h]
  float length; // [esp+44h] [ebp-8h]
  float retaddr; // [esp+4Ch] [ebp+0h]

  maxb.z = a2;
  length = retaddr;
  LODWORD(maxb.y) = this;
  if ( this->m_EditDispHandle != 0xFFFF )
  {
    v4 = EditDispMgr();
    v5 = v4->GetDisp(this: v4, a2: this->m_EditDispHandle);
    v6 = v5;
    if ( v5 != nullptr )
    {
      m_HitTexelIndex = v5->m_HitTexelIndex;
      if ( m_HitTexelIndex != -1 )
      {
        v8 = m_HitTexelIndex;
        v9 = (1 << v5->m_CoreDispInfo.m_Power) + 1;
        p_x = &v5->m_CoreDispInfo.m_pVerts->m_FieldVector.x;
        v11 = p_x[10];
        v12 = p_x[11];
        v13 = p_x[56 * v9 - 46];
        v14 = p_x[56 * v9 - 45];
        v15 = 56 * v9 * (v9 - 1);
        v16 = p_x[v15 + 11];
        v17 = p_x[v15 + 12];
        v18 = *(_BYTE *)(LODWORD(maxb.y) + 1183) == 0;
        v19 = p_x[56 * v9 - 44] - p_x[12];
        *(float *)&hbOrigin[8] = p_x[12];
        v20 = p_x[v15 + 10];
        m_pVerts = v6->m_CoreDispInfo.m_pVerts;
        v22 = (float)(v16 - v12) + (float)(v14 - v12);
        x = m_pVerts[v8].m_Vert.x;
        v24 = (float)(v17 - *(float *)&hbOrigin[8]) + v19;
        y = m_pVerts[v8].m_Vert.y;
        v26 = (float)((float)((float)(v20 - v11) + (float)(v13 - v11)) * 0.5)
            * (float)((float)((float)(v20 - v11) + (float)(v13 - v11)) * 0.5);
        v27 = 0;
        v28 = (float)((float)((float)(v22 * 0.5) * (float)(v22 * 0.5)) + (float)((float)(v24 * 0.5) * (float)(v24 * 0.5)))
            + v26;
        z = m_pVerts[v8].m_Vert.z;
        *(float *)&v27 = fsqrt(v28);
        *(_OWORD *)hbOrigin = v27;
        *(float *)&v27 = *(float *)&v27 * 0.025;
        *(float *)&hbOrigin[32] = x - *(float *)&v27;
        v41 = y - *(float *)&v27;
        LODWORD(maxb.x) = v27;
        v42 = z - *(float *)&v27;
        minb.x = x + *(float *)&v27;
        minb.y = y + *(float *)&v27;
        minb.z = z + *(float *)&v27;
        if ( v18 )
          pRender->RenderWireframeBox(
            this: pRender,
            a2: (const Vector *)&hbOrigin[32],
            a3: &minb,
            a4: 0,
            a5: 255u,
            a6: 0);
        else
          pRender->RenderWireframeBox(
            this: pRender,
            a2: (const Vector *)&hbOrigin[32],
            a3: &minb,
            a4: 255u,
            a5: 255u,
            a6: 0);
        v30 = v6->m_CoreDispInfo.m_pVerts;
        v31 = v30[v8].m_Vert.x;
        v32 = maxb.x * 4.0;
        v39.x = v31;
        v33 = v30[v8].m_Vert.y;
        v39.y = v33;
        v34 = v30[v8].m_Vert.z;
        v18 = *(_DWORD *)(LODWORD(maxb.y) + 1156) == 3;
        v35 = *(float *)(LODWORD(maxb.y) + 1160);
        v36 = *(float *)(LODWORD(maxb.y) + 1164);
        v37 = *(float *)(LODWORD(maxb.y) + 1168);
        v39.z = v34;
        if ( v18 )
        {
          v38 = v6->m_CoreDispInfo.m_pVerts;
          v35 = v38[v8].m_SubdivNormal.x;
          v36 = v38[v8].m_SubdivNormal.y;
          v37 = v38[v8].m_SubdivNormal.z;
        }
        *(float *)&hbOrigin[12] = (float)(v35 * v32) + v31;
        *(float *)&hbOrigin[16] = (float)(v36 * v32) + v33;
        *(float *)&hbOrigin[20] = (float)(v37 * v32) + v34;
        CRender3D::RenderArrow(
          this: pRender,
          vStartPt: &v39,
          vEndPt: (const Vector *)&hbOrigin[12],
          chRed: 255,
          chGreen: 255,
          chBlue: 0);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015BDC0
// Name: public: virtual void CToolDisplace::RenderTool3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CToolDisplace::RenderTool3D(CToolDisplace *this, CRender3D *pRender)
{
  unsigned int m_uiTool; // eax
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  m_uiTool = this->m_uiTool;
  if ( m_uiTool == 2 )
  {
    if ( this->m_bSpatial )
      CToolDisplace::RenderPaintSphere(this, pRender);
    else
      CToolDisplace::RenderHitBox(this, a2: COERCE_FLOAT(&savedregs), pRender);
  }
  else if ( m_uiTool == 6 )
  {
    this->m_SculptTool->RenderTool3D(this: this->m_SculptTool, a2: pRender);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015BE90
// Name: public: virtual bool CToolDisplace::OnLMouseUp3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolDisplace::OnLMouseUp3D(
        CToolDisplace *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  bool v5; // zf
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax

  v5 = this->m_uiTool == 6;
  this->m_bLMBDown = false;
  if ( v5 )
  {
    this->m_SculptTool->OnLMouseUp3D(this: this->m_SculptTool, a2: pView, a3: nFlags, a4: vPoint);
    return 1;
  }
  else
  {
    if ( this->m_bNudge )
    {
      ReleaseCapture();
      this->m_bNudge = false;
    }
    if ( this->m_bSpatialRadius )
    {
      ReleaseCapture();
      this->m_bSpatialRadius = false;
    }
    ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
    if ( ActiveWorldEditDispManager != nullptr )
      ActiveWorldEditDispManager->PostUndo(this: ActiveWorldEditDispManager);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015BF10
// Name: protected: void CToolDisplace::Nudge_Activate(class CMapView3D __near *,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolDisplace::Nudge_Activate(CToolDisplace *this, CMapView3D *pView, int dispHandle)
{
  IWorldEditDispMgr *ActiveWorldEditDispManager; // edi
  int v5; // ebx
  IWorldEditDispMgr_vtbl *v6; // eax
  CMapDisp *v7; // eax
  HWND v8; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-24h]
  int v10; // [esp-8h] [ebp-24h]
  int v11; // [esp-4h] [ebp-20h]
  tagRECT Rect; // [esp+Ch] [ebp-10h] BYREF
  int nDispCount; // [esp+28h] [ebp+Ch]

  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  v5 = 0;
  if ( ActiveWorldEditDispManager != nullptr )
  {
    ActiveWorldEditDispManager->PreUndo(this: ActiveWorldEditDispManager, a2: "Displacement Nudge");
    v6 = ActiveWorldEditDispManager->__vftable;
    if ( this->m_bSpatial )
    {
      nDispCount = v6->SelectCount(this: ActiveWorldEditDispManager);
      if ( nDispCount > 0 )
      {
        do
        {
          v7 = ActiveWorldEditDispManager->GetFromSelect(this: ActiveWorldEditDispManager, a2: v5);
          if ( v7 != nullptr )
            CMapDisp::Paint_Init(this: v7, nType: 0);
          ++v5;
        }
        while ( v5 < nDispCount );
      }
    }
    else
    {
      v6->Undo(this: ActiveWorldEditDispManager, a2: dispHandle, a3: true);
    }
    m_hWnd = pView->m_hWnd;
    memset(&Rect, 0, sizeof(Rect));
    GetWindowRect(hWnd: m_hWnd, lpRect: &Rect);
    v11 = (Rect.top + Rect.bottom) / 2;
    v10 = (Rect.right + Rect.left) / 2;
    this->m_viewCenter.x = v10;
    this->m_viewCenter.y = v11;
    SetCursorPos(X: v10, Y: v11);
    v8 = SetCapture(hWnd: pView->m_hWnd);
    CWnd::FromHandle(hWnd: v8);
    *(_WORD *)&this->m_bNudge = 257;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015BFF0
// Name: protected: void CToolDisplace::Nudge_Do(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolDisplace::Nudge_Do(CToolDisplace *this)
{
  CEditDispMgr *v2; // eax
  float v3; // xmm0_4
  float v4; // xmm0_4
  CDispMapImageFilter *v5; // eax
  int m_HitTexelIndex; // eax
  CoreDispVert_t *m_pVerts; // ecx
  float m_flSpatialRadius; // xmm1_4
  bool m_bNudgeInit; // dl
  bool m_bAutoSew; // dl
  SpatialPaintData_t spatialData; // [esp+4h] [ebp-40h] BYREF
  CPoint nudgePos; // [esp+38h] [ebp-Ch] BYREF
  CMapDisp *pNudgeDisp; // [esp+40h] [ebp-4h]

  if ( this->m_EditDispHandle != 0xFFFF )
  {
    v2 = EditDispMgr();
    pNudgeDisp = v2->GetDisp(this: v2, a2: this->m_EditDispHandle);
    if ( pNudgeDisp != nullptr )
    {
      nudgePos.x = 0;
      nudgePos.y = 0;
      GetCursorPos(lpPoint: &nudgePos);
      if ( (int)abs32(nudgePos.x - this->m_viewCenter.x) >= (int)abs32(nudgePos.y - this->m_viewCenter.y) )
        v3 = (float)(nudgePos.x - this->m_viewCenter.x);
      else
        v3 = (float)(nudgePos.y - this->m_viewCenter.y);
      LODWORD(v4) = LODWORD(v3) ^ _mask__NegFloat_;
      if ( this->m_bSpatial )
      {
        m_HitTexelIndex = pNudgeDisp->m_HitTexelIndex;
        if ( m_HitTexelIndex != -1 )
        {
          m_pVerts = pNudgeDisp->m_CoreDispInfo.m_pVerts;
          m_flSpatialRadius = this->m_flSpatialRadius;
          spatialData.m_uiBrushType = this->m_uiBrushType;
          m_bNudgeInit = this->m_bNudgeInit;
          spatialData.m_flScalar = v4;
          spatialData.m_bNudgeInit = m_bNudgeInit;
          m_bAutoSew = this->m_bAutoSew;
          spatialData.m_nEffect = 0;
          spatialData.m_flRadius = m_flSpatialRadius;
          spatialData.m_bNudge = true;
          spatialData.m_vCenter = m_pVerts[m_HitTexelIndex].m_Vert;
          spatialData.m_vPaintAxis = this->m_vecPaintAxis;
          CDispPaintMgr::Paint(this: &this->m_DispPaintMgr, &spatialData, bAutoSew: m_bAutoSew);
          this->m_bNudgeInit = false;
        }
      }
      else
      {
        v5 = this->m_FilterRaiseLowerMgr.m_pFilterList[this->m_FilterRaiseLowerMgr.m_ActiveFilter];
        if ( v5 == nullptr )
          return;
        v5->m_DataType = 0;
        v5->m_Scale = (float)(1 - (int)(float)(this->m_flPaintValueGeo * -0.1)) * (float)(v4 * 0.25);
        CDispMapImageFilterManager::Apply(
          this: &this->m_FilterRaiseLowerMgr,
          pFilter: v5,
          pDisp: pNudgeDisp,
          paintDirType: this->m_iPaintAxis,
          vPaintDir: &this->m_vecPaintAxis,
          bSew: this->m_bAutoSew);
      }
      SetCursorPos(X: this->m_viewCenter.x, Y: this->m_viewCenter.y);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015C1C0
// Name: protected: void CToolDisplace::ResizeSpatialRadius_Activate(class CMapView3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolDisplace::ResizeSpatialRadius_Activate(CToolDisplace *this, CMapView3D *pView)
{
  HWND v3; // eax
  tagRECT Rect; // [esp+8h] [ebp-10h] BYREF
  CPoint v5; // 0:^0.8

  memset(&Rect, 0, sizeof(Rect));
  GetWindowRect(hWnd: pView->m_hWnd, lpRect: &Rect);
  v5.y = (Rect.top + Rect.bottom) / 2;
  v5.x = (Rect.right + Rect.left) / 2;
  this->m_viewCenter = v5;
  SetCursorPos(X: v5.x, Y: v5.y);
  v3 = SetCapture(hWnd: pView->m_hWnd);
  CWnd::FromHandle(hWnd: v3);
  this->m_bSpatialRadius = true;
}

//------------------------------------------------------------------------------
// Address: 0x1015C240
// Name: private: bool CToolDisplace::RayAABBTest(class CMapDisp __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolDisplace::RayAABBTest(
        CToolDisplace *this,
        CMapDisp *pDisp,
        const Vector *rayStart,
        const Vector *rayEnd)
{
  float z; // xmm0_4
  int v7; // eax
  float *i; // ecx
  PLANE planes[6]; // [esp+0h] [ebp-15Ch] BYREF
  Vector boxMin; // [esp+138h] [ebp-24h] BYREF
  Vector boxMax; // [esp+144h] [ebp-18h] BYREF
  float v13; // [esp+150h] [ebp-Ch]
  float y; // [esp+154h] [ebp-8h]
  float v15; // [esp+158h] [ebp-4h]
  float pDispa; // [esp+164h] [ebp+8h]
  float rayStarta; // [esp+168h] [ebp+Ch]
  float rayEnda; // [esp+16Ch] [ebp+10h]

  boxMin.x = pDisp->m_BBox[0].x;
  boxMin.y = pDisp->m_BBox[0].y;
  boxMin.z = pDisp->m_BBox[0].z;
  boxMax = pDisp->m_BBox[1];
  CToolDisplace::BuildParallelepiped(this, &boxMin, &boxMax, planes);
  rayStarta = rayStart->y;
  pDispa = rayStart->x;
  z = rayStart->z;
  v13 = z;
  y = rayEnd->y;
  rayEnda = rayEnd->x;
  v7 = 0;
  v15 = rayEnd->z;
  for ( i = &planes[0].normal.z;
        (float)((float)((float)((float)(*(i - 2) * pDispa) + (float)(*(i - 1) * rayStarta)) + (float)(*i * v13)) - i[1]) <= 0.0
     || (float)((float)((float)((float)(*(i - 2) * rayEnda) + (float)(*(i - 1) * y)) + (float)(*i * v15)) - i[1]) <= 0.0;
        i += 13 )
  {
    if ( ++v7 >= 6 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1015C380
// Name: private: bool CToolDisplace::LoadFilters(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CToolDisplace::LoadFilters(CToolDisplace *this, const char *filename)
{
  int v3; // esi
  ChunkFileResult_t v4; // eax
  CChunkFile File; // [esp+Ch] [ebp-35Ch] BYREF
  CChunkHandlerMap Handlers; // [esp+350h] [ebp-18h] BYREF
  int v8; // [esp+364h] [ebp-4h]

  CChunkFile::CChunkFile(this: &File);
  v8 = 0;
  v3 = CChunkFile::Open(this: &File, pszFileName: filename, eMode: ChunkFile_Read);
  if ( v3 != 0 )
  {
    Msg(type: mwError, fmt: "Couldn't load filter file %s!\n", filename);
  }
  else
  {
    CTextureReference::CTextureReference(this: (CTextureReference *)&Handlers);
    LOBYTE(v8) = 1;
    CChunkHandlerMap::AddHandler(
      this: &Handlers,
      pszChunkName: "Filter",
      pfnHandler: (ChunkFileResult_t (__cdecl *)(CChunkFile *, void *))CToolDisplace::LoadFiltersCallback,
      pData: this);
    CChunkFile::PushHandlers(this: &File, pHandlerMap: &Handlers);
    do
    {
      v4 = CChunkFile::ReadChunk(this: &File, pfnKeyHandler: nullptr, pData: nullptr);
      v3 = v4;
    }
    while ( v4 == ChunkFile_Ok );
    if ( v4 == ChunkFile_EOF )
      v3 = 0;
    CChunkFile::PopHandlers(this: &File);
    LOBYTE(v8) = 0;
    CChunkHandlerMap::~CChunkHandlerMap(this: &Handlers);
  }
  v8 = -1;
  CChunkFile::~CChunkFile(this: &File);
  return v3 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1015C470
// Name: public: CToolDisplace::CToolDisplace(void)
// Source: json
//------------------------------------------------------------------------------
CToolDisplace *__thiscall CToolDisplace::CToolDisplace(CToolDisplace *this)
{
  AFX_MODULE_STATE *ModuleState; // eax

  this->__vftable = (CToolDisplace_vtbl *)&CBaseTool::`vftable';
  *(_WORD *)&this->m_bActiveTool = 256;
  this->m_pDocument = nullptr;
  this->__vftable = (CToolDisplace_vtbl *)&CToolDisplace::`vftable';
  CDispMapImageFilterManager::CDispMapImageFilterManager(this: &this->m_FilterLoaderMgr);
  CDispMapImageFilterManager::CDispMapImageFilterManager(this: &this->m_FilterRaiseLowerMgr);
  CDispMapImageFilterManager::CDispMapImageFilterManager(this: &this->m_FilterRaiseToMgr);
  CDispMapImageFilterManager::CDispMapImageFilterManager(this: &this->m_FilterSmoothMgr);
  this->m_viewCenter.x = 0;
  this->m_viewCenter.y = 0;
  CAnchorMgr::CAnchorMgr(this: (CAnchorMgr *)&this->m_DispPaintMgr);
  this->m_flPaintValueGeo = 5.0;
  this->m_flPaintValueData = 25.0;
  this->m_uiTool = 1;
  this->m_uiEffect = 0;
  this->m_uiBrushType = 0;
  this->m_iPaintChannel = 0;
  this->m_iPaintAxis = 4;
  this->m_vecPaintAxis.x = 0.0;
  this->m_vecPaintAxis.y = 0.0;
  this->m_vecPaintAxis.z = 1.0;
  *(_WORD *)&this->m_bAutoSew = 0;
  this->m_flSpatialRadius = 15.0;
  *(_WORD *)&this->m_bLMBDown = 0;
  *(_DWORD *)&this->m_bSpatialRadius = 256;
  this->m_bNudgeInit = false;
  this->m_EditDispHandle = -1;
  ModuleState = AfxGetModuleState();
  CHammer::GetDirectory(this: (CHammer *)ModuleState->m_pCurrentWinApp, dir: DIR_PROGRAM, p: szProgramDir);
  strcat(szProgramDir, "filters\\dispfilters.txt");
  CToolDisplace::LoadFilters(this, filename: szProgramDir);
  CToolDisplace::AddFiltersToManagers(this);
  this->m_SculptTool = nullptr;
  this->m_MousePoint.x = 0.0;
  this->m_MousePoint.y = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1015C630
// Name: public: int CToolDisplace::GetSelectedDisps(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolDisplace::GetSelectedDisps(CToolDisplace *this)
{
  IWorldEditDispMgr *ActiveWorldEditDispManager; // edi
  CFaceEditSheet *m_pFaceEditSheet; // ecx
  int v4; // ebx
  CMapFace *pMapFace; // eax
  int m_DispHandle; // eax
  int v7; // esi
  CEditDispMgr *v8; // eax
  CFaceEditSheet *pSheet; // [esp+4h] [ebp-8h]
  int m_Size; // [esp+8h] [ebp-4h]

  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  if ( ActiveWorldEditDispManager == nullptr )
    return 0;
  ActiveWorldEditDispManager->SelectClear(this: ActiveWorldEditDispManager);
  m_pFaceEditSheet = GetMainWnd()->m_pFaceEditSheet;
  pSheet = m_pFaceEditSheet;
  if ( m_pFaceEditSheet == nullptr )
    return 0;
  if ( m_pFaceEditSheet->m_Faces.m_Size > 0 )
  {
    v4 = 0;
    m_Size = m_pFaceEditSheet->m_Faces.m_Size;
    do
    {
      pMapFace = m_pFaceEditSheet->m_Faces.m_Memory.m_pMemory[v4].pMapFace;
      if ( pMapFace != nullptr )
      {
        m_DispHandle = pMapFace->m_DispHandle;
        if ( (_WORD)m_DispHandle != 0xFFFF )
        {
          v7 = m_DispHandle;
          v8 = EditDispMgr();
          v8->GetDisp(this: v8, a2: v7)->m_HitTexelIndex = -1;
          ActiveWorldEditDispManager->AddToSelect(this: ActiveWorldEditDispManager, a2: v7);
          m_pFaceEditSheet = pSheet;
        }
      }
      ++v4;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  return ActiveWorldEditDispManager->SelectCount(this: ActiveWorldEditDispManager);
}

//------------------------------------------------------------------------------
// Address: 0x1015C6E0
// Name: private: unsigned short CToolDisplace::CollideWithSelectedDisps(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
unsigned __int16 __userpurge CToolDisplace::CollideWithSelectedDisps@<ax>(
        CToolDisplace *this@<ecx>,
        int a2@<ebp>,
        const Vector *rayStart,
        const Vector *rayEnd)
{
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax
  int v5; // edi
  CMapDisp *v6; // edi
  int m_Power; // ecx
  CoreDispVert_t *m_pVerts; // ecx
  float v9; // xmm3_4
  float v10; // xmm4_4
  float v11; // xmm5_4
  float v12; // xmm0_4
  CEditDispMgr *v13; // eax
  int v14; // eax
  float v16; // [esp-1Ch] [ebp-5Ch]
  float x; // [esp-Ch] [ebp-4Ch]
  float y; // [esp-8h] [ebp-48h]
  float z; // [esp-4h] [ebp-44h]
  Vector point; // [esp+0h] [ebp-40h] BYREF
  int v21; // [esp+Ch] [ebp-34h]
  int v22; // [esp+10h] [ebp-30h]
  CToolDisplace *v23; // [esp+14h] [ebp-2Ch]
  int dispCount; // [esp+18h] [ebp-28h]
  int size; // [esp+1Ch] [ebp-24h]
  float v26; // [esp+20h] [ebp-20h]
  IWorldEditDispMgr *pDispMgr; // [esp+24h] [ebp-1Ch]
  int minIndex; // [esp+28h] [ebp-18h]
  int minDist; // [esp+2Ch] [ebp-14h]
  int i; // [esp+30h] [ebp-10h]
  int v31; // [esp+34h] [ebp-Ch]
  int j; // [esp+38h] [ebp-8h]
  int retaddr; // [esp+40h] [ebp+0h]

  v31 = a2;
  j = retaddr;
  v23 = this;
  i = 0xFFFF;
  v26 = 99999.898;
  size = -1;
  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  v5 = (int)ActiveWorldEditDispManager;
  dispCount = (int)ActiveWorldEditDispManager;
  if ( ActiveWorldEditDispManager != nullptr )
  {
    v21 = ActiveWorldEditDispManager->SelectCount(this: ActiveWorldEditDispManager);
    pDispMgr = nullptr;
    if ( v21 > 0 )
    {
      while ( 1 )
      {
        v6 = (CMapDisp *)(*(int (__thiscall **)(int, IWorldEditDispMgr *))(*(_DWORD *)v5 + 36))(a1: v5, a2: pDispMgr);
        if ( v6 != nullptr && CToolDisplace::RayAABBTest(this: v23, pDisp: v6, rayStart, rayEnd) != 0 )
        {
          m_Power = v6->m_CoreDispInfo.m_Power;
          minDist = 0;
          v22 = ((1 << m_Power) + 1) * ((1 << m_Power) + 1);
          if ( v22 > 0 )
          {
            minIndex = 0;
            do
            {
              m_pVerts = v6->m_CoreDispInfo.m_pVerts;
              x = m_pVerts[minIndex / 0xE0u].m_Vert.x;
              y = m_pVerts[minIndex / 0xE0u].m_Vert.y;
              z = m_pVerts[minIndex / 0xE0u].m_Vert.z;
              point.x = rayEnd->x - rayStart->x;
              point.y = rayEnd->y - rayStart->y;
              point.z = rayEnd->z - rayStart->z;
              VectorNormalize(vec: &point);
              v9 = rayStart->x;
              v10 = rayStart->y;
              v11 = rayStart->z;
              v12 = (float)((float)((float)(x - rayStart->x) * point.x) + (float)((float)(y - v10) * point.y))
                  + (float)((float)(z - v11) * point.z);
              point.y = v10 + (float)(v12 * point.y);
              point.z = v11 + (float)(v12 * point.z);
              point.x = v9 + (float)(point.x * v12);
              v16 = fsqrt(
                      (float)((float)((float)(point.y - y) * (float)(point.y - y))
                            + (float)((float)(point.z - z) * (float)(point.z - z)))
                    + (float)((float)(point.x - x) * (float)(point.x - x)));
              if ( v26 > v16 )
              {
                i = LOWORD(v6->GetParent(this: v6)[21].__vftable);
                v26 = v16;
                size = minDist;
              }
              minIndex += 224;
              ++minDist;
            }
            while ( minDist < v22 );
          }
        }
        pDispMgr = (IWorldEditDispMgr *)((char *)pDispMgr + 1);
        if ( (int)pDispMgr >= v21 )
          break;
        v5 = dispCount;
      }
      if ( (_WORD)i != 0xFFFF )
      {
        v13 = EditDispMgr();
        v14 = (int)v13->GetDisp(this: v13, a2: i);
        *(_DWORD *)(v14 + 868) = size;
      }
    }
    LOWORD(ActiveWorldEditDispManager) = i;
  }
  return (unsigned __int16)ActiveWorldEditDispManager;
}

//------------------------------------------------------------------------------
// Address: 0x1015C940
// Name: protected: unsigned short CToolDisplace::GetHitPos(class CMapView3D __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CToolDisplace::GetHitPos(CToolDisplace *this, CMapView3D *pView, const Vector2D *vPoint)
{
  int SelectedDisps; // eax
  Vector rayStart; // [esp+4h] [ebp-18h] BYREF
  Vector rayEnd; // [esp+10h] [ebp-Ch] BYREF
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  CCamera::BuildRay(this: pView->m_pCamera, vView: vPoint, vStart: &rayStart, vEnd: &rayEnd);
  SelectedDisps = CToolDisplace::GetSelectedDisps(this);
  if ( SelectedDisps != 0 )
    LOWORD(SelectedDisps) = CToolDisplace::CollideWithSelectedDisps(this, a2: (int)&savedregs, &rayStart, &rayEnd);
  return SelectedDisps;
}

//------------------------------------------------------------------------------
// Address: 0x1015C990
// Name: protected: void CToolDisplace::LiftFaceNormal(class CMapView3D __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolDisplace::LiftFaceNormal(CToolDisplace *this, CMapView3D *pView, const Vector2D *vPoint)
{
  const Vector2D *v3; // ebx
  CMapSolid *v5; // esi
  CMapFace *Face; // esi
  Vector vHitPos; // [esp+Ch] [ebp-30h] BYREF
  Vector vRayStart; // [esp+18h] [ebp-24h] BYREF
  Vector vRayEnd; // [esp+24h] [ebp-18h] BYREF
  Vector vHitNormal; // [esp+30h] [ebp-Ch] BYREF

  v3 = vPoint;
  v5 = (CMapSolid *)CMapView3D::NearestObjectAt(
                      this: pView,
                      vPoint,
                      ulFace: (unsigned int *)&vPoint,
                      nFlags: 0,
                      pLocalMatrix: nullptr);
  if ( v5 != nullptr && v5->IsMapClass(this: v5, a2: CMapSolid::__Type) != 0 )
  {
    Face = CMapSolid::GetFace(this: v5, nFace: (int)vPoint);
    if ( Face != nullptr )
    {
      CCamera::BuildRay(this: pView->m_pCamera, vView: v3, vStart: &vRayStart, vEnd: &vRayEnd);
      if ( CMapFace::TraceLine(this: Face, HitPos: &vHitPos, HitNormal: &vHitNormal, Start: &vRayStart, End: &vRayEnd) != 0 )
      {
        this->m_vecPaintAxis = vHitNormal;
      }
      else
      {
        this->m_vecPaintAxis.x = 0.0;
        this->m_vecPaintAxis.y = 0.0;
        this->m_vecPaintAxis.z = 1.0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015CA80
// Name: protected: void CToolDisplace::ApplySculptSpatialPaintTool(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolDisplace::ApplySculptSpatialPaintTool(
        CToolDisplace *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  CCamera *m_pCamera; // ecx
  int v6; // edi
  unsigned __int16 v7; // ax
  CEditDispMgr *v8; // eax
  int v9; // eax
  int v10; // ecx
  bool v11; // zf
  unsigned int m_uiEffect; // eax
  unsigned int m_uiBrushType; // ecx
  float m_flPaintValueGeo; // xmm0_4
  CSculptTool *m_SculptTool; // ecx
  SpatialPaintData_t spatialData; // [esp+0h] [ebp-4Ch] BYREF
  Vector vStart; // [esp+34h] [ebp-18h] BYREF
  Vector vEnd; // [esp+40h] [ebp-Ch] BYREF
  int savedregs; // [esp+4Ch] [ebp+0h] BYREF

  m_pCamera = pView->m_pCamera;
  memset(&spatialData.m_vCenter, 0, sizeof(spatialData.m_vCenter));
  CCamera::BuildRay(this: m_pCamera, vView: vPoint, &vStart, &vEnd);
  if ( CToolDisplace::GetSelectedDisps(this) != 0 )
  {
    v7 = CToolDisplace::CollideWithSelectedDisps(this, a2: (int)&savedregs, rayStart: &vStart, rayEnd: &vEnd);
    v6 = v7;
    if ( v7 == 0xFFFF )
      goto LABEL_6;
  }
  else
  {
    v6 = 0;
  }
  this->m_EditDispHandle = v6;
  v8 = EditDispMgr();
  v9 = (int)v8->GetDisp(this: v8, a2: v6);
  v10 = *(_DWORD *)(v9 + 868);
  if ( v10 != -1 )
    spatialData.m_vCenter = *(Vector *)(*(_DWORD *)(v9 + 784) + 224 * v10 + 40);
LABEL_6:
  v11 = !this->m_bRMBDown;
  m_uiEffect = this->m_uiEffect;
  m_uiBrushType = this->m_uiBrushType;
  spatialData.m_flRadius = this->m_flSpatialRadius;
  m_flPaintValueGeo = this->m_flPaintValueGeo;
  spatialData.m_nEffect = m_uiEffect;
  spatialData.m_uiBrushType = m_uiBrushType;
  spatialData.m_flScalar = m_flPaintValueGeo;
  spatialData.m_bNudge = false;
  if ( !v11 )
    LODWORD(spatialData.m_flScalar) = LODWORD(m_flPaintValueGeo) ^ _mask__NegFloat_;
  m_SculptTool = this->m_SculptTool;
  spatialData.m_vPaintAxis = this->m_vecPaintAxis;
  m_SculptTool->Paint(this: m_SculptTool, a2: pView, a3: vPoint, a4: &spatialData);
}

//------------------------------------------------------------------------------
// Address: 0x1015CBC0
// Name: protected: void CToolDisplace::HandleTagging(class CMapView3D __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolDisplace::HandleTagging(CToolDisplace *this, CMapView3D *pView, const Vector2D *vPoint)
{
  CMapView3D *v3; // ebx
  const Vector2D *v4; // edi
  CMapSolid *v5; // esi
  CMapFace *Face; // eax
  int m_DispHandle; // eax
  int v8; // esi
  CEditDispMgr *v9; // eax
  CMapDisp *v10; // esi
  int v11; // eax
  unsigned int m_uiTool; // ecx
  CoreDispTri_t *m_pTris; // edx
  CoreDispTri_t *v14; // edx
  bool v15; // zf
  unsigned __int16 *p_m_uiTags; // eax
  CoreDispTri_t *v17; // edx
  CoreDispTri_t *v18; // edx
  char v19; // cl
  unsigned __int16 *v20; // eax
  Vector vecStart; // [esp+Ch] [ebp-1Ch] BYREF
  Vector vecEnd; // [esp+18h] [ebp-10h] BYREF
  CToolDisplace *v23; // [esp+24h] [ebp-4h]
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  v3 = pView;
  v4 = vPoint;
  v23 = this;
  v5 = (CMapSolid *)CMapView3D::NearestObjectAt(
                      this: pView,
                      vPoint,
                      ulFace: (unsigned int *)&vPoint,
                      nFlags: 0,
                      pLocalMatrix: nullptr);
  if ( v5 != nullptr && v5->IsMapClass(this: v5, a2: CMapSolid::__Type) != 0 )
  {
    Face = CMapSolid::GetFace(this: v5, nFace: (int)vPoint);
    if ( Face != nullptr )
    {
      m_DispHandle = Face->m_DispHandle;
      if ( (_WORD)m_DispHandle != 0xFFFF )
      {
        v8 = m_DispHandle;
        v9 = EditDispMgr();
        v10 = v9->GetDisp(this: v9, a2: v8);
        CCamera::BuildRay(this: v3->m_pCamera, vView: v4, vStart: &vecStart, vEnd: &vecEnd);
        v11 = CMapDisp::CollideWithDispTri(
                this: v10,
                a2: (int)&savedregs,
                rayStart: &vecStart,
                rayEnd: &vecEnd,
                flFraction: (float *)&pView,
                OneSided: 0);
        if ( v11 != -1 )
        {
          m_uiTool = v23->m_uiTool;
          if ( m_uiTool == 4 )
          {
            m_pTris = v10->m_CoreDispInfo.m_pTris;
            if ( (m_pTris[v11].m_uiTags & 2) != 0 )
            {
              m_pTris[v11].m_uiTags ^= 4u;
              CMapDisp::UpdateWalkable(this: v10);
            }
            else
            {
              m_pTris[v11].m_uiTags |= 2u;
              v14 = v10->m_CoreDispInfo.m_pTris;
              v15 = (v14[v11].m_uiTags & 1) == 0;
              p_m_uiTags = &v14[v11].m_uiTags;
              if ( v15 )
                *p_m_uiTags |= 4u;
              else
                *p_m_uiTags &= ~4u;
              CMapDisp::UpdateWalkable(this: v10);
            }
          }
          else if ( m_uiTool == 5 )
          {
            v17 = v10->m_CoreDispInfo.m_pTris;
            if ( (v17[v11].m_uiTags & 0x10) != 0 )
            {
              v17[v11].m_uiTags ^= 0x20u;
              CMapDisp::UpdateBuildable(this: v10);
            }
            else
            {
              v17[v11].m_uiTags |= 0x10u;
              v18 = v10->m_CoreDispInfo.m_pTris;
              v19 = LOBYTE(v18[v11].m_uiTags) >> 3;
              v20 = &v18[v11].m_uiTags;
              if ( (v19 & 1) != 0 )
                *v20 &= ~0x20u;
              else
                *v20 |= 0x20u;
              CMapDisp::UpdateBuildable(this: v10);
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015CD70
// Name: protected: void CToolDisplace::HandleTaggingReset(class CMapView3D __near *,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolDisplace::HandleTaggingReset(CToolDisplace *this, CMapView3D *pView, const Vector2D *vPoint)
{
  CMapView3D *v3; // ebx
  const Vector2D *v4; // edi
  CMapSolid *v5; // esi
  CMapFace *Face; // eax
  int m_DispHandle; // eax
  int v8; // esi
  CEditDispMgr *v9; // eax
  CMapDisp *v10; // esi
  int v11; // eax
  unsigned int m_uiTool; // ecx
  unsigned __int16 *p_m_uiTags; // eax
  unsigned __int16 *v14; // eax
  Vector vecStart; // [esp+Ch] [ebp-1Ch] BYREF
  Vector vecEnd; // [esp+18h] [ebp-10h] BYREF
  CToolDisplace *v17; // [esp+24h] [ebp-4h]
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  v3 = pView;
  v4 = vPoint;
  v17 = this;
  v5 = (CMapSolid *)CMapView3D::NearestObjectAt(
                      this: pView,
                      vPoint,
                      ulFace: (unsigned int *)&vPoint,
                      nFlags: 0,
                      pLocalMatrix: nullptr);
  if ( v5 != nullptr && v5->IsMapClass(this: v5, a2: CMapSolid::__Type) != 0 )
  {
    Face = CMapSolid::GetFace(this: v5, nFace: (int)vPoint);
    if ( Face != nullptr )
    {
      m_DispHandle = Face->m_DispHandle;
      if ( (_WORD)m_DispHandle != 0xFFFF )
      {
        v8 = m_DispHandle;
        v9 = EditDispMgr();
        v10 = v9->GetDisp(this: v9, a2: v8);
        CCamera::BuildRay(this: v3->m_pCamera, vView: v4, vStart: &vecStart, vEnd: &vecEnd);
        v11 = CMapDisp::CollideWithDispTri(
                this: v10,
                a2: (int)&savedregs,
                rayStart: &vecStart,
                rayEnd: &vecEnd,
                flFraction: (float *)&pView,
                OneSided: 0);
        if ( v11 != -1 )
        {
          m_uiTool = v17->m_uiTool;
          if ( m_uiTool == 4 )
          {
            p_m_uiTags = &v10->m_CoreDispInfo.m_pTris[v11].m_uiTags;
            *p_m_uiTags &= ~2u;
            CMapDisp::UpdateWalkable(this: v10);
          }
          else if ( m_uiTool == 5 )
          {
            v14 = &v10->m_CoreDispInfo.m_pTris[v11].m_uiTags;
            *v14 &= ~0x10u;
            CMapDisp::UpdateBuildable(this: v10);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015CE80
// Name: public: virtual bool CToolDisplace::OnLMouseDown3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolDisplace::OnLMouseDown3D(
        CToolDisplace *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  unsigned int m_uiTool; // eax
  CMapView3D *v6; // edi
  unsigned int v7; // eax
  CMapView3D *v9; // edi
  unsigned __int16 HitPos; // ax
  int v11; // ebx
  CEditDispMgr *v12; // eax
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax
  IWorldEditDispMgr *v14; // edi
  IWorldEditDispMgr_vtbl *v15; // edx
  int v16; // ebx
  CMapDisp *v17; // eax
  CEditDispMgr *v18; // eax
  CMapDisp *v19; // eax
  int v20; // eax
  CMapDisp *pDisp; // [esp+Ch] [ebp-8h]
  int nDispCount; // [esp+10h] [ebp-4h]

  m_uiTool = this->m_uiTool;
  this->m_bLMBDown = true;
  if ( m_uiTool == 6 )
  {
    v6 = pView;
    this->m_SculptTool->OnLMouseDown3D(this: this->m_SculptTool, a2: pView, a3: nFlags, a4: vPoint);
    this->m_SculptTool->BeginPaint(this: this->m_SculptTool, a2: pView, a3: vPoint);
    CToolDisplace::ApplySculptSpatialPaintTool(this, pView, nFlags, vPoint);
    goto LABEL_30;
  }
  if ( m_uiTool == 1 || GetAsyncKeyState(vKey: 17) < 0 )
  {
    v6 = pView;
    CToolDisplace::HandleSelection(this, pView, vPoint);
LABEL_30:
    v20 = (int)v6->GetMapDoc(this: &v6->CMapView);
    if ( v20 != 0 )
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v20 + 100))(a1: v20, a2: 1);
    return 1;
  }
  v7 = this->m_uiTool;
  if ( v7 == 4 || v7 == 5 )
  {
    CToolDisplace::HandleTagging(this, pView, vPoint);
    return 1;
  }
  if ( v7 == 2 && this->m_bSpatial && GetAsyncKeyState(vKey: 18) < 0 )
  {
    CToolDisplace::ResizeSpatialRadius_Activate(this, pView);
    return 1;
  }
  if ( this->m_uiTool != 2 || GetAsyncKeyState(vKey: 16) >= 0 || this->m_uiEffect != 0 )
  {
    v9 = pView;
  }
  else
  {
    v9 = pView;
    HitPos = CToolDisplace::GetHitPos(this, pView, vPoint);
    if ( HitPos != 0xFFFF )
    {
      this->m_EditDispHandle = HitPos;
      CToolDisplace::Nudge_Activate(this, pView, dispHandle: HitPos);
      CToolDisplace::UpdateMapViews(this, pView);
      return 1;
    }
  }
  if ( this->m_uiTool != 2 )
    return 1;
  v11 = CToolDisplace::GetHitPos(this, pView: v9, vPoint);
  if ( (_WORD)v11 == 0xFFFF )
    return 0;
  this->m_EditDispHandle = v11;
  v12 = EditDispMgr();
  pDisp = v12->GetDisp(this: v12, a2: v11);
  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  v14 = ActiveWorldEditDispManager;
  if ( ActiveWorldEditDispManager == nullptr )
    return 0;
  ActiveWorldEditDispManager->PreUndo(this: ActiveWorldEditDispManager, a2: "Displacement Modifier");
  v15 = v14->__vftable;
  if ( this->m_bSpatial )
  {
    v16 = 0;
    nDispCount = v15->SelectCount(this: v14);
    if ( nDispCount > 0 )
    {
      do
      {
        v17 = v14->GetFromSelect(this: v14, a2: v16);
        if ( v17 != nullptr )
          CMapDisp::Paint_Init(this: v17, nType: 0);
        ++v16;
      }
      while ( v16 < nDispCount );
    }
    CToolDisplace::ApplySpatialPaintTool(this, nFlags, vPoint, pDisp);
    CToolDisplace::UpdateMapViews(this, pView);
    return 1;
  }
  else
  {
    v15->Undo(this: v14, a2: v11, a3: true);
    v18 = EditDispMgr();
    v19 = v18->GetDisp(this: v18, a2: v11);
    CToolDisplace::ApplyPaintTool(this, nFlags, vPoint, pDisp: v19);
    CToolDisplace::UpdateMapViews(this, pView);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015D0F0
// Name: public: virtual bool CToolDisplace::OnRMouseDown3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolDisplace::OnRMouseDown3D(
        CToolDisplace *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  unsigned int m_uiTool; // eax
  CMapDoc *v6; // eax
  unsigned int v8; // eax
  int HitPos; // ebx
  CEditDispMgr *v10; // eax
  IWorldEditDispMgr *ActiveWorldEditDispManager; // eax
  IWorldEditDispMgr *v12; // edi
  IWorldEditDispMgr_vtbl *v13; // edx
  int v14; // ebx
  CMapDisp *v15; // eax
  CEditDispMgr *v16; // eax
  CMapDisp *v17; // eax
  CMapDisp *pDisp; // [esp+Ch] [ebp-8h]
  int nDispCount; // [esp+10h] [ebp-4h]

  m_uiTool = this->m_uiTool;
  this->m_bRMBDown = true;
  if ( m_uiTool == 6 )
  {
    this->m_SculptTool->OnRMouseDown3D(this: this->m_SculptTool, a2: pView, a3: nFlags, a4: vPoint);
    this->m_SculptTool->BeginPaint(this: this->m_SculptTool, a2: pView, a3: vPoint);
    CToolDisplace::ApplySculptSpatialPaintTool(this, pView, nFlags, vPoint);
    v6 = pView->GetMapDoc(this: &pView->CMapView);
    if ( v6 != nullptr )
    {
      v6->SetModifiedFlag(this: v6, a2: 1);
      return 1;
    }
    return 1;
  }
  if ( m_uiTool == 2 && this->m_iPaintAxis == 4 && GetAsyncKeyState(vKey: 18) < 0 )
  {
    CToolDisplace::LiftFaceNormal(this, pView, vPoint);
    return 1;
  }
  v8 = this->m_uiTool;
  if ( v8 == 4 || v8 == 5 )
  {
    CToolDisplace::HandleTaggingReset(this, pView, vPoint);
    return 1;
  }
  if ( v8 != 2 )
    return 1;
  HitPos = CToolDisplace::GetHitPos(this, pView, vPoint);
  if ( (_WORD)HitPos == 0xFFFF )
    return 0;
  this->m_EditDispHandle = HitPos;
  v10 = EditDispMgr();
  pDisp = v10->GetDisp(this: v10, a2: HitPos);
  ActiveWorldEditDispManager = GetActiveWorldEditDispManager();
  v12 = ActiveWorldEditDispManager;
  if ( ActiveWorldEditDispManager == nullptr )
    return 0;
  ActiveWorldEditDispManager->PreUndo(this: ActiveWorldEditDispManager, a2: "Displacement Modifier");
  v13 = v12->__vftable;
  if ( this->m_bSpatial )
  {
    v14 = 0;
    nDispCount = v13->SelectCount(this: v12);
    if ( nDispCount > 0 )
    {
      do
      {
        v15 = v12->GetFromSelect(this: v12, a2: v14);
        if ( v15 != nullptr )
          CMapDisp::Paint_Init(this: v15, nType: 0);
        ++v14;
      }
      while ( v14 < nDispCount );
    }
    CToolDisplace::ApplySpatialPaintTool(this, nFlags, vPoint, pDisp);
    CToolDisplace::UpdateMapViews(this, pView);
    return 1;
  }
  else
  {
    v13->Undo(this: v12, a2: HitPos, a3: true);
    v16 = EditDispMgr();
    v17 = v16->GetDisp(this: v16, a2: HitPos);
    CToolDisplace::ApplyPaintTool(this, nFlags, vPoint, pDisp: v17);
    CToolDisplace::UpdateMapViews(this, pView);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015D2D0
// Name: public: virtual bool CToolDisplace::OnMouseMove3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolDisplace::OnMouseMove3D(
        CToolDisplace *this,
        CMapView3D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  unsigned int m_uiTool; // eax
  CMapView *v6; // ecx
  int v7; // edi
  CEditDispMgr *v8; // eax
  CMapDisp *v9; // edi
  unsigned __int16 v10; // ax
  int v12; // eax
  Vector vStart; // [esp+Ch] [ebp-18h] BYREF
  Vector vEnd; // [esp+18h] [ebp-Ch] BYREF
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  this->m_MousePoint = *vPoint;
  m_uiTool = this->m_uiTool;
  if ( m_uiTool == 6 )
  {
    this->m_SculptTool->OnMouseMove3D(this: this->m_SculptTool, a2: pView, a3: nFlags, a4: vPoint);
    if ( this->m_bLMBDown || this->m_bRMBDown )
      CToolDisplace::ApplySculptSpatialPaintTool(this, pView, nFlags, vPoint);
    v6 = &pView->CMapView;
  }
  else
  {
    if ( m_uiTool == 2 && GetAsyncKeyState(vKey: 16) < 0 && this->m_bLMBDown && this->m_bNudge )
    {
      CToolDisplace::Nudge_Do(this);
    }
    else if ( this->m_uiTool == 2 && GetAsyncKeyState(vKey: 18) < 0 && this->m_bLMBDown && this->m_bSpatialRadius )
    {
      CToolDisplace::ResizeSpatialRadius_Do(this);
    }
    else
    {
      CCamera::BuildRay(this: pView->m_pCamera, vView: vPoint, &vStart, &vEnd);
      if ( CToolDisplace::GetSelectedDisps(this) != 0 )
      {
        v10 = CToolDisplace::CollideWithSelectedDisps(this, a2: (int)&savedregs, rayStart: &vStart, rayEnd: &vEnd);
        v7 = v10;
        if ( v10 == 0xFFFF )
          return 0;
      }
      else
      {
        v7 = 0;
      }
      this->m_EditDispHandle = v7;
      v8 = EditDispMgr();
      v9 = v8->GetDisp(this: v8, a2: v7);
      if ( (this->m_bLMBDown || this->m_bRMBDown) && GetAsyncKeyState(vKey: 17) >= 0 && this->m_uiTool == 2 )
      {
        if ( this->m_bSpatial )
          CToolDisplace::ApplySpatialPaintTool(this, nFlags, vPoint, pDisp: v9);
        else
          CToolDisplace::ApplyPaintTool(this, nFlags, vPoint, pDisp: v9);
      }
      if ( this->m_bNudge )
      {
        ReleaseCapture();
        this->m_bNudge = false;
      }
      if ( this->m_bSpatialRadius )
      {
        ReleaseCapture();
        this->m_bSpatialRadius = false;
      }
    }
    v6 = &pView->CMapView;
  }
  v12 = (int)v6->GetMapDoc(this: v6);
  if ( v12 != 0 )
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v12 + 100))(a1: v12, a2: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104F46E0
// Name: public: virtual enum ToolID_t CToolDisplace::GetToolID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CToolDisplace::GetToolID(CDmeTypedLog<Vector> *this)
{
  return 10;
}
