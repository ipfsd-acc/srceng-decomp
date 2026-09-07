// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/toolclipper.cpp
// Functions: 22
// ============================================================

#include "hammer\toolclipper.h"

//------------------------------------------------------------------------------
// Address: 0x101593B0
// Name: public: virtual void Clipper3D::OnDeactivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Clipper3D::OnDeactivate(Clipper3D *this)
{
  this->SetEmpty(this);
}

//------------------------------------------------------------------------------
// Address: 0x101593C0
// Name: private: void Clipper3D::BuildClipPlane(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Clipper3D::BuildClipPlane(Clipper3D *this)
{
  float v2; // xmm2_4
  float v3; // xmm1_4
  float v4; // xmm0_4
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  Vector forwardVect; // [esp+10h] [ebp-Ch] BYREF
  Vector upVect; // 0:^8.12

  v2 = this->m_ClipPoints[1].y - this->m_ClipPoints[0].y;
  v3 = this->m_ClipPoints[1].x - this->m_ClipPoints[0].x;
  upVect = this->m_vPlaneNormal;
  v4 = this->m_ClipPoints[1].z - this->m_ClipPoints[0].z;
  forwardVect.x = (float)(upVect.y * v4) - (float)(upVect.z * v2);
  forwardVect.y = (float)(upVect.z * v3) - (float)(v4 * upVect.x);
  forwardVect.z = (float)(upVect.x * v2) - (float)(upVect.y * v3);
  VectorNormalize(vec: &forwardVect);
  x = forwardVect.x;
  y = forwardVect.y;
  z = forwardVect.z;
  this->m_ClipPlane.normal = forwardVect;
  this->m_ClipPlane.dist = (float)((float)(this->m_ClipPoints[0].y * y) + (float)(this->m_ClipPoints[0].x * x))
                         + (float)(this->m_ClipPoints[0].z * z);
}

//------------------------------------------------------------------------------
// Address: 0x101594C0
// Name: private: void Clipper3D::SaveClipSolid(class CMapSolid __near *,class CMapSolid __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Clipper3D::SaveClipSolid(Clipper3D *this, CMapSolid *pSolid, CMapSolid *pOrigSolid)
{
  CMapClass *v5; // eax
  CHistory *History; // eax
  CMapSolid *pSolida; // [esp+14h] [ebp+8h]

  pSolid->m_bTemporary = false;
  pSolida = (CMapSolid *)this->m_pDocument->Tool3D::CBaseTool::__vftable;
  v5 = pOrigSolid->GetParent(this: pOrigSolid);
  ((void (__thiscall *)(CMapDoc *, CMapSolid *, CMapClass *))pSolida->Faces.Blocks[17])(
    a1: this->m_pDocument,
    a2: pSolid,
    a3: v5);
  if ( CSelection::IsSelected(this: this->m_pDocument->m_pSelection, pobj: pOrigSolid) )
    CMapDoc::SelectObject(this: this->m_pDocument, pObj: pSolid, cmd: 2);
  else
    pSolid->SetSelectionState(this: pSolid, a2: SELECT_NORMAL);
  History = GetHistory();
  CHistory::KeepNew(this: History, pObject: pSolid, bKeepChildren: true);
}

//------------------------------------------------------------------------------
// Address: 0x10159540
// Name: private: void Clipper3D::DrawBrushExtents(class CRender2D __near *,class CMapSolid __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Clipper3D::DrawBrushExtents(Clipper3D *this, CRender2D *pRender, CMapSolid *pSolid, char nFlags)
{
  float z; // edx
  char v6; // bl
  char v7; // bl
  Vector Mins; // [esp+4h] [ebp-2Ch] BYREF
  Vector Maxs; // [esp+10h] [ebp-20h] BYREF
  Vector normal; // [esp+1Ch] [ebp-14h] BYREF
  Vector2D planeNormal; // [esp+28h] [ebp-8h] BYREF

  CMapClass::GetRender2DBox(this: pSolid, mins: &Mins, maxs: &Maxs);
  if ( this->m_ClipPlane.normal.x != 0.0 || this->m_ClipPlane.normal.y != 0.0 || this->m_ClipPlane.normal.z != 0.0 )
  {
    z = this->m_ClipPlane.normal.z;
    *(_QWORD *)&normal.x = *(_QWORD *)&this->m_ClipPlane.normal.x;
    normal.z = z;
    if ( (nFlags & 0x10) != 0 )
    {
      normal.x = -normal.x;
      normal.y = -normal.y;
      normal.z = -normal.z;
    }
    CRender::TransformNormal(this: pRender, vClient: &planeNormal, vWorld: &normal);
    if ( planeNormal.x > 0.0 )
      v6 = nFlags & 0xF3 | 8;
    else
      v6 = nFlags & 0xF3 | 4;
    if ( planeNormal.y > 0.0 )
      v7 = v6 & 0xFC | 2;
    else
      v7 = v6 & 0xFC | 1;
    DrawBoundsText(pRender, &Mins, (CRender2D *)&Maxs, nFlags: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159650
// Name: public: virtual int Clipper3D::HitTest(class CMapView __near *,class Vector2D const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall Clipper3D::HitTest(Clipper3D *this, CMapView *pView, const Vector2D *ptClient, bool bTestHandles)
{
  int v5; // edi
  Vector *i; // esi

  v5 = 0;
  for ( i = this->m_ClipPoints; !Tool3D::HitRect(this, pView, vPoint: ptClient, vCenter: i, extent: 4); ++i )
  {
    if ( ++v5 >= 2 )
      return 0;
  }
  return v5 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x101596A0
// Name: public: virtual unsigned int Clipper3D::GetConstraints(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall Clipper3D::GetConstraints(Camera3D *this, unsigned int nKeyFlags)
{
  unsigned int result; // eax

  result = Tool3D::GetConstraints(this, nKeyFlags);
  if ( (nKeyFlags & 8) != 0 )
    result |= 0x40u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101596C0
// Name: public: virtual bool Clipper3D::OnMouseMove2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall Clipper3D::OnMouseMove2D(
        Clipper3D *this,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  unsigned int (__thiscall *GetConstraints)(struct Clipper3D *, unsigned int); // edx
  int v6; // ebx
  CMapView *v7; // edi
  bool v9; // zf
  unsigned int v10; // eax
  char string[32]; // [esp+18h] [ebp-94h] BYREF
  __int128 szBuf_100; // [esp+9Ch] [ebp-10h] OVERLAPPED BYREF

  GetConstraints = this->GetConstraints;
  HIDWORD(szBuf_100) = 2;
  v6 = GetConstraints(this, a2: nFlags);
  Tool3D::OnMouseMove2D(this, pView, nFlags, vPoint);
  v7 = &pView->CMapView;
  pView->ClientToWorld(this: &pView->CMapView, a2: (Vector *)&szBuf_100, a3: vPoint);
  if ( (v6 & 4) != 0 )
    CMapDoc::Snap(this: this->m_pDocument, pt: (Vector *)&szBuf_100, nFlags: v6);
  sprintf(
    string: &string[4],
    format: " @%.0f, %.0f ",
    *((float *)&szBuf_100 + pView->axHorz),
    *((float *)&szBuf_100 + pView->axVert));
  SetStatusText(nIndex: 2, pszText: &string[4]);
  if ( this->IsTranslating(this) )
  {
    Tool3D::UpdateTranslation(this, pView: v7, vPoint, nFlags: v6);
    return 1;
  }
  else
  {
    if ( this->IsEmpty(this) || (v9 = this->HitTest(this, a2: v7, a3: vPoint, a4: true) == 0, v10 = 6, v9) )
      v10 = HIDWORD(szBuf_100);
    CVGuiWnd::SetCursor(this: &pView->CVGuiWnd, cursor: v10);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101597E0
// Name: private: void Clipper3D::CalcClipResults(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Clipper3D::CalcClipResults(Clipper3D *this)
{
  int i; // ebx
  CClipGroup *v3; // edi
  CMapSolid *m_pOrigSolid; // ecx
  int m_Mode; // eax
  CMapSolid *pBack; // [esp+4h] [ebp-8h] BYREF
  CMapSolid *pFront; // [esp+8h] [ebp-4h] BYREF

  if ( !this->IsEmpty(this) )
  {
    for ( i = 0; i < this->m_ClipResults.m_Size; ++i )
    {
      v3 = this->m_ClipResults.m_Memory.m_pMemory[i];
      m_pOrigSolid = v3->m_pOrigSolid;
      if ( v3->m_pOrigSolid != nullptr )
      {
        m_Mode = this->m_Mode;
        pFront = nullptr;
        pBack = nullptr;
        switch ( m_Mode )
        {
          case 0:
            CMapSolid::Split(this: m_pOrigSolid, pPlane: &this->m_ClipPlane, &pFront, pBack: nullptr);
LABEL_10:
            if ( pFront != nullptr )
            {
              pFront->m_bTemporary = true;
              v3->m_pClipSolids[0] = pFront;
            }
            if ( pBack != nullptr )
            {
              pBack->m_bTemporary = true;
              v3->m_pClipSolids[1] = pBack;
            }
            break;
          case 1:
            CMapSolid::Split(this: m_pOrigSolid, pPlane: &this->m_ClipPlane, pFront: nullptr, &pBack);
            goto LABEL_10;
          case 2:
            CMapSolid::Split(this: m_pOrigSolid, pPlane: &this->m_ClipPlane, &pFront, &pBack);
            goto LABEL_10;
          default:
            break;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159890
// Name: public: virtual void Clipper3D::RenderTool3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Clipper3D::RenderTool3D(Clipper3D *this, CRender3D *pRender)
{
  Clipper3D *v2; // esi
  bool v3; // zf
  int v4; // ebx
  CClipGroup *v5; // edi
  CMapSolid *v6; // esi
  CMapSolid *v7; // esi
  int v8; // [esp+4h] [ebp-Ch] BYREF
  color32_s rgbColor; // [esp+8h] [ebp-8h] BYREF
  Clipper3D *v10; // [esp+Ch] [ebp-4h]

  v2 = this;
  v3 = !this->m_bEmpty;
  v10 = this;
  if ( v3 )
  {
    CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_WIREFRAME);
    v4 = 0;
    if ( v2->m_ClipResults.m_Size > 0 )
    {
      while ( 1 )
      {
        v5 = v2->m_ClipResults.m_Memory.m_pMemory[v4];
        v6 = v5->m_pClipSolids[0];
        if ( v6 != nullptr )
        {
          ((void (__thiscall *)(CMapSolid *, color32_s *))v6->GetRenderColor)(a1: v6, a2: &rgbColor);
          v6->SetRenderColor_2(this: v6, a2: 255u, a3: 255u, a4: 255u);
          v6->Render3D(this: v6, a2: pRender);
          v6->SetRenderColor(this: v6, a2: rgbColor);
        }
        v7 = v5->m_pClipSolids[1];
        if ( v7 != nullptr )
        {
          ((void (__thiscall *)(CMapSolid *, int *))v7->GetRenderColor)(a1: v7, a2: &v8);
          v7->SetRenderColor_2(this: v7, a2: 255u, a3: 255u, a4: 255u);
          v7->Render3D(this: v7, a2: pRender);
          ((void (__thiscall *)(CMapSolid *, int))v7->SetRenderColor)(a1: v7, a2: v8);
        }
        if ( ++v4 >= v10->m_ClipResults.m_Size )
          break;
        v2 = v10;
      }
    }
    CRender::PopRenderMode(this: pRender);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159980
// Name: private: void Clipper3D::ResetClipResults(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Clipper3D::ResetClipResults(Clipper3D *this)
{
  int i; // ebx
  CClipGroup *v3; // esi
  CMapSolid *v4; // ecx
  CMapSolid *v5; // ecx

  for ( i = 0; i < this->m_ClipResults.m_Size; ++i )
  {
    v3 = this->m_ClipResults.m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      v4 = v3->m_pClipSolids[0];
      if ( v4 != nullptr )
        ((void (__thiscall *)(CMapSolid *, int))v4->~CMapClass)(a1: v4, a2: 1);
      v5 = v3->m_pClipSolids[1];
      if ( v5 != nullptr )
        ((void (__thiscall *)(CMapSolid *, int))v5->~CMapClass)(a1: v5, a2: 1);
      operator delete(p: v3);
    }
  }
  this->m_ClipResults.m_Size = 0;
  this->SetEmpty(this);
}

//------------------------------------------------------------------------------
// Address: 0x101599F0
// Name: private: void Clipper3D::SaveClipResults(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Clipper3D::SaveClipResults(Clipper3D *this)
{
  CHistory *History; // eax
  int v3; // eax
  CClipGroup *v4; // edi
  CMapSolid *v5; // eax
  CMapSolid *v6; // ecx
  CMapSolid *m_pOrigSolid; // esi
  CSelection *m_pSelection; // edi
  CMapSolid *pBackSolid; // [esp+4h] [ebp-8h]
  int pos; // [esp+8h] [ebp-4h]

  if ( !this->IsEmpty(this) )
  {
    History = GetHistory();
    CHistory::MarkUndoPosition(this: History, pSelection: nullptr, pszName: "Clip Objects", bFromOpposite: 0);
    v3 = 0;
    for ( pos = 0; v3 < this->m_ClipResults.m_Size; pos = v3 )
    {
      v4 = this->m_ClipResults.m_Memory.m_pMemory[v3];
      if ( v4 != nullptr )
      {
        v5 = v4->m_pClipSolids[0];
        v6 = v4->m_pClipSolids[1];
        m_pOrigSolid = v4->m_pOrigSolid;
        pBackSolid = v6;
        if ( v5 != nullptr )
        {
          Clipper3D::SaveClipSolid(this, pSolid: v5, pOrigSolid: m_pOrigSolid);
          v6 = pBackSolid;
          v4->m_pClipSolids[0] = nullptr;
        }
        if ( v6 != nullptr )
        {
          Clipper3D::SaveClipSolid(this, pSolid: v6, pOrigSolid: m_pOrigSolid);
          v4->m_pClipSolids[1] = nullptr;
        }
        m_pOrigSolid->PostUpdate(this: m_pOrigSolid, a2: Notify_Clipped);
        CMapDoc::DeleteObject(this: this->m_pDocument, pObject: m_pOrigSolid);
        m_pSelection = this->m_pDocument->m_pSelection;
        if ( CSelection::IsSelected(this: m_pSelection, pobj: m_pOrigSolid) )
          CSelection::SelectObject(this: m_pSelection, pObj: m_pOrigSolid, cmd: 4);
        else
          m_pOrigSolid->SetSelectionState(this: m_pOrigSolid, a2: SELECT_NONE);
      }
      v3 = pos + 1;
    }
    Clipper3D::ResetClipResults(this);
    this->m_pDocument->SetModifiedFlag(this: this->m_pDocument, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159AE0
// Name: public: virtual bool Clipper3D::OnKeyDown2D(class CMapView2D __near *,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Clipper3D::OnKeyDown2D(
        Clipper3D *this,
        CMapView2D *pView,
        unsigned int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  bool v7; // zf
  CMapDoc *m_pDocument; // ecx

  switch ( nChar )
  {
    case 0xDu:
      if ( !this->IsEmpty(this) )
        Clipper3D::SaveClipResults(this);
      return 1;
    case 0x1Bu:
      if ( this->IsEmpty(this) )
        CToolManager::SetTool(this: this->m_pDocument->m_pToolManager, eNewTool: TOOL_POINTER);
      else
        this->SetEmpty(this);
      return 1;
    case 0x4Fu:
      v7 = !this->m_bDrawMeasurements;
      m_pDocument = this->m_pDocument;
      this->m_bDrawMeasurements = v7;
      CMapDoc::UpdateAllViews(this: m_pDocument, nFlags: 16, ub: nullptr);
      return 1;
    default:
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159B70
// Name: public: virtual bool Clipper3D::OnKeyDown3D(class CMapView3D __near *,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Clipper3D::OnKeyDown3D(
        Clipper3D *this,
        CMapView3D *pView,
        unsigned int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  if ( nChar == 13 )
  {
    if ( !this->IsEmpty(this) )
      Clipper3D::SaveClipResults(this);
    return 1;
  }
  else if ( nChar == 27 )
  {
    if ( this->IsEmpty(this) )
      CToolManager::SetTool(this: this->m_pDocument->m_pToolManager, eNewTool: TOOL_POINTER);
    else
      this->SetEmpty(this);
    return 1;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159BE0
// Name: public: Clipper3D::Clipper3D(void)
// Source: json
//------------------------------------------------------------------------------
Clipper3D *__thiscall Clipper3D::Clipper3D(Clipper3D *this)
{
  CClipGroup **m_pMemory; // ecx

  Tool3D::Tool3D(this);
  this->__vftable = (Clipper3D_vtbl *)&Clipper3D::`vftable';
  this->m_ClipResults.m_Memory.m_pMemory = nullptr;
  this->m_ClipResults.m_Memory.m_nAllocationCount = 0;
  this->m_ClipResults.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_ClipResults.m_Memory.m_pMemory;
  this->m_ClipResults.m_Size = 0;
  this->m_ClipResults.m_pElements = m_pMemory;
  CRender2D::CRender2D(this: &this->m_Render2D);
  this->m_Mode = 0;
  this->m_ClipPlane.normal.x = 0.0;
  this->m_ClipPlane.normal.y = 0.0;
  this->m_ClipPlane.normal.z = 0.0;
  this->m_ClipPlane.dist = 0.0;
  this->m_ClipPoints[0].x = 0.0;
  this->m_ClipPoints[0].y = 0.0;
  this->m_ClipPoints[0].z = 0.0;
  this->m_ClipPoints[1].x = 0.0;
  this->m_ClipPoints[1].y = 0.0;
  this->m_ClipPoints[1].z = 0.0;
  this->m_ClipPointHit = -1;
  this->m_pOrigObjects = nullptr;
  this->m_bDrawMeasurements = false;
  this->m_bEmpty = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10159CC0
// Name: public: virtual Clipper3D::~Clipper3D(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Clipper3D::~Clipper3D(Clipper3D *this)
{
  CUtlVector<CClipGroup *,CUtlMemory<CClipGroup *,int> > *p_m_ClipResults; // esi

  this->__vftable = (Clipper3D_vtbl *)&Clipper3D::`vftable';
  CRender2D::~CRender2D(this: &this->m_Render2D);
  p_m_ClipResults = &this->m_ClipResults;
  this->m_ClipResults.m_Size = 0;
  if ( this->m_ClipResults.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_ClipResults->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_ClipResults->m_Memory.m_pMemory);
      p_m_ClipResults->m_Memory.m_pMemory = nullptr;
    }
    this->m_ClipResults.m_Memory.m_nAllocationCount = 0;
  }
  this->m_ClipResults.m_pElements = this->m_ClipResults.m_Memory.m_pMemory;
  if ( this->m_ClipResults.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_ClipResults->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_ClipResults->m_Memory.m_pMemory);
      p_m_ClipResults->m_Memory.m_pMemory = nullptr;
    }
    this->m_ClipResults.m_Memory.m_nAllocationCount = 0;
  }
  this->__vftable = (Clipper3D_vtbl *)&CBaseTool::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10159D70
// Name: public: virtual void Clipper3D::RenderTool2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Clipper3D::RenderTool2D(Clipper3D *this, CRender2D *pRender)
{
  Clipper3D *v2; // ebx
  bool (__thiscall *IsEmpty)(struct Clipper3D *); // edx
  CRender2D *v4; // edi
  int v5; // eax
  CClipGroup *v6; // ecx
  CMapSolid *v7; // eax
  CMapSolid *v8; // esi
  int v9; // edi
  BlockArray<CMapFace,6,86> *p_Faces; // esi
  int nCount; // eax
  int v12; // ebx
  unsigned int v13; // esi
  CMapFace *v14; // esi
  int v15; // edi
  int v16; // ebx
  unsigned int v17; // esi
  CMapFace *v18; // esi
  Clipper3D *v19; // ebx
  char v20; // si
  __int64 v21; // xmm0_8
  char v22; // si
  const Vector *v23; // esi
  const Vector *m_ClipPoints; // ebx
  const Vector *v25; // [esp-Ch] [ebp-58h]
  Vector mins; // [esp+4h] [ebp-48h] BYREF
  Vector maxs; // [esp+10h] [ebp-3Ch] BYREF
  Vector vWorld; // [esp+1Ch] [ebp-30h] BYREF
  Vector2D vClient; // [esp+28h] [ebp-24h] BYREF
  int v30; // [esp+30h] [ebp-1Ch]
  int faceCount; // [esp+34h] [ebp-18h]
  int pos; // [esp+38h] [ebp-14h]
  Clipper3D *v33; // [esp+3Ch] [ebp-10h]
  CMapSolid *pClipBack; // [esp+40h] [ebp-Ch]
  CMapSolid *pClipFront; // [esp+44h] [ebp-8h]
  bool bDrawVerts; // [esp+4Bh] [ebp-1h]

  v2 = this;
  IsEmpty = this->IsEmpty;
  v33 = this;
  if ( ((unsigned __int8 (__fastcall *)(Clipper3D *))IsEmpty)(a1: this) == 0 )
  {
    v4 = pRender;
    bDrawVerts = Options.view2d.bDrawVertices == 1;
    CRender::SetDrawColor(this: pRender, r: 0xFFu, g: 0xFFu, b: 0xFFu);
    v5 = 0;
    pos = 0;
    if ( v2->m_ClipResults.m_Size > 0 )
    {
      while ( 1 )
      {
        v6 = v2->m_ClipResults.m_Memory.m_pMemory[v5];
        v7 = v6->m_pClipSolids[1];
        v8 = v6->m_pClipSolids[0];
        pClipBack = v7;
        pClipFront = v8;
        if ( v7 != nullptr )
          break;
        if ( v8 != nullptr )
          goto LABEL_25;
LABEL_52:
        v5 = pos + 1;
        pos = v5;
        if ( v5 >= v2->m_ClipResults.m_Size )
          goto LABEL_53;
      }
      v9 = 0;
      faceCount = v7->Faces.nCount;
      if ( faceCount > 0 )
      {
        while ( 1 )
        {
          p_Faces = &v7->Faces;
          nCount = v7->Faces.nCount;
          if ( v9 >= nCount )
          {
            _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v9, nCount);
            v12 = v9 + 1;
            if ( v9 + 1 != p_Faces->nCount )
            {
              v13 = v12 / 6;
              if ( 6 * (v12 / 6) < v12 )
                ++v13;
              if ( v13 != pClipBack->Faces.nBlocks )
              {
                if ( v13 > 0x57 )
                  _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
                BlockArray<CMapFace,6,86>::GetBlocks(this: &pClipBack->Faces, nNewBlocks: v13);
              }
              pClipBack->Faces.nCount = v12;
            }
          }
          v14 = &pClipBack->Faces.Blocks[v9 / 6u][v9 % 6u];
          CRender::DrawPolyLine(this: pRender, nPoints: v14->nPoints, Points: v14->Points);
          if ( bDrawVerts )
            BlankImage::SetSize(this: (vgui::TreeView *)pRender, itemIndex: v14->nPoints, msg: (KeyValues *)v14->Points);
          if ( v33->m_bDrawMeasurements )
            Clipper3D::DrawBrushExtents(this: v33, pRender, pSolid: pClipBack, nFlags: 21);
          v30 = ++v9;
          if ( v9 >= faceCount )
            break;
          v7 = pClipBack;
        }
        v8 = pClipFront;
        v2 = v33;
      }
      if ( v8 != nullptr )
      {
LABEL_25:
        v15 = 0;
        faceCount = v8->Faces.nCount;
        if ( faceCount > 0 )
        {
          while ( 1 )
          {
            if ( v15 >= v8->Faces.nCount )
            {
              _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v15, v8->Faces.nCount);
              v16 = v15 + 1;
              if ( v15 + 1 != v8->Faces.nCount )
              {
                v17 = v16 / 6;
                if ( 6 * (v16 / 6) < v16 )
                  ++v17;
                if ( v17 != pClipFront->Faces.nBlocks )
                {
                  if ( v17 > 0x57 )
                    _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
                  BlockArray<CMapFace,6,86>::GetBlocks(this: &pClipFront->Faces, nNewBlocks: v17);
                }
                pClipFront->Faces.nCount = v16;
              }
            }
            v18 = &pClipFront->Faces.Blocks[v15 / 6u][v15 % 6u];
            CRender::DrawPolyLine(this: pRender, nPoints: v18->nPoints, Points: v18->Points);
            if ( bDrawVerts )
              BlankImage::SetSize(
                this: (vgui::TreeView *)pRender,
                itemIndex: v18->nPoints,
                msg: (KeyValues *)v18->Points);
            v19 = v33;
            if ( v33->m_bDrawMeasurements )
            {
              v20 = 10;
              CMapClass::GetRender2DBox(this: pClipFront, &mins, &maxs);
              if ( v19->m_ClipPlane.normal.x != 0.0
                || v19->m_ClipPlane.normal.y != 0.0
                || v19->m_ClipPlane.normal.z != 0.0 )
              {
                v21 = *(_QWORD *)&v19->m_ClipPlane.normal.x;
                vWorld.z = v19->m_ClipPlane.normal.z;
                *(_QWORD *)&vWorld.x = v21;
                CRender::TransformNormal(this: pRender, &vClient, &vWorld);
                if ( vClient.x <= 0.0 )
                  v20 = 6;
                if ( vClient.y > 0.0 )
                  v22 = v20 & 0xFC | 2;
                else
                  v22 = v20 & 0xFC | 1;
                DrawBoundsText(pRender, Mins: &mins, Maxs: (CRender2D *)&maxs, nFlags: v22);
              }
            }
            v30 = ++v15;
            if ( v15 >= faceCount )
              break;
            v8 = pClipFront;
          }
          v2 = v33;
        }
      }
      v4 = pRender;
      goto LABEL_52;
    }
LABEL_53:
    CRender::SetDrawColor(this: v4, r: 0, g: 0xFFu, b: 0xFFu);
    v23 = &v2->m_ClipPoints[1];
    v25 = &v2->m_ClipPoints[1];
    m_ClipPoints = v2->m_ClipPoints;
    CRender::DrawLine(this: v4, a2: (int)v4, a3: (int)v23, vStart: m_ClipPoints, vEnd: v25);
    CRender::SetHandleStyle(this: v4, size: 4, type: 1);
    CRender::SetHandleColor(this: v4, r: 0xFFu, g: 0xFFu, b: 0xFFu);
    CRender::DrawHandle(this: v4, vCenter: m_ClipPoints, vOffset: nullptr);
    CRender::DrawHandle(this: v4, vCenter: v23, vOffset: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015A160
// Name: int AddToClipList(class CMapSolid __near *,class Clipper3D __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl AddToClipList(CMapSolid *pSolid, Clipper3D *pClipper)
{
  CClipGroup *v2; // eax
  CClipGroup *v3; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CClipGroup **m_pMemory; // ecx
  int v8; // eax
  CClipGroup **v9; // eax

  v2 = (CClipGroup *)operator new(nSize: 0xCu);
  if ( v2 != nullptr )
  {
    v2->m_pOrigSolid = nullptr;
    v2->m_pClipSolids[0] = nullptr;
    v2->m_pClipSolids[1] = nullptr;
    v3 = v2;
  }
  else
  {
    v3 = nullptr;
  }
  if ( v3 == nullptr )
    return 0;
  v3->m_pOrigSolid = pSolid;
  m_nAllocationCount = pClipper->m_ClipResults.m_Memory.m_nAllocationCount;
  m_Size = pClipper->m_ClipResults.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CVisGroup *,int>::Grow(
      this: (CUtlMemory<CCullTreeNode *,int> *)&pClipper->m_ClipResults,
      num: m_Size - m_nAllocationCount + 1);
  ++pClipper->m_ClipResults.m_Size;
  m_pMemory = pClipper->m_ClipResults.m_Memory.m_pMemory;
  v8 = pClipper->m_ClipResults.m_Size - m_Size - 1;
  pClipper->m_ClipResults.m_pElements = m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
  v9 = &pClipper->m_ClipResults.m_Memory.m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = v3;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015A280
// Name: private: void Clipper3D::SetClipObjects(class CUtlReferenceVector<class CMapClass> const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Clipper3D::SetClipObjects(Clipper3D *this, const CUtlReferenceVector<CMapClass> *pList)
{
  int i; // edi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v5; // ecx
  CMapSolid *v6; // ebx
  CUtlReference<CMapClass> *m_pHead; // [esp+4h] [ebp-18h] BYREF
  CUtlReference<CMapClass> *v8; // [esp+8h] [ebp-14h]
  CMapSolid *pSolid; // [esp+Ch] [ebp-10h]
  int v10; // [esp+18h] [ebp-4h]

  if ( pList != nullptr )
  {
    this->m_pOrigObjects = pList;
    Clipper3D::ResetClipResults(this);
    for ( i = 0; i < this->m_pOrigObjects->m_Size; ++i )
    {
      m_pObject = this->m_pOrigObjects->m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_pOrigObjects->m_Memory
                                                                                   + 2) >> 27)][i
                                                                                              & ((32
                                                                                                * *((_DWORD *)&this->m_pOrigObjects->m_Memory
                                                                                                  + 2)) >> 5)].m_pObject;
      if ( m_pObject != nullptr )
      {
        pSolid = (CMapSolid *)this->m_pOrigObjects->m_Memory.m_pMemory[i >> ((unsigned __int64)*((int *)&this->m_pOrigObjects->m_Memory
                                                                                               + 2) >> 27)][i & ((32 * *((_DWORD *)&this->m_pOrigObjects->m_Memory + 2)) >> 5)].m_pObject;
        m_pHead = m_pObject->m_References.m_pHead;
        v5 = m_pObject->m_References.m_pHead;
        if ( v5 != nullptr )
          v5->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
        v8 = nullptr;
        m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
      }
      v6 = pSolid;
      v10 = -1;
      if ( pSolid != nullptr )
      {
        if ( v8 != nullptr )
        {
          v8->m_pNext = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = v8;
        }
        else if ( (CUtlReference<CMapClass> **)pSolid->m_References.m_pHead == &m_pHead )
        {
          pSolid->m_References.m_pHead = m_pHead;
          if ( m_pHead != nullptr )
            m_pHead->m_pPrev = nullptr;
        }
        v8 = nullptr;
        m_pHead = nullptr;
        pSolid = nullptr;
      }
      if ( v6 != nullptr )
      {
        if ( v6->IsMapClass(this: v6, a2: CMapSolid::__Type) != 0 )
          AddToClipList(pSolid: v6, pClipper: this);
        CMapClass::EnumChildren(
          this: v6,
          pfn: (int (__cdecl *)(CMapClass *, unsigned int))AddToClipList,
          dwParam: (unsigned int)this,
          Type: CMapSolid::__Type);
      }
    }
    this->m_bEmpty = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015A3D0
// Name: public: virtual bool Clipper3D::OnLMouseDown2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Clipper3D::OnLMouseDown2D(
        Clipper3D *this,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  CMapView *v6; // edi
  char v7; // bl
  int v8; // eax
  int v9; // eax
  double v10; // st7
  float *v11; // eax
  float *v12; // ecx
  const CUtlReferenceVector<CMapClass> *List; // eax
  float x; // xmm0_4
  float y; // xmm1_4
  float z; // xmm2_4
  Vector vecWorld; // [esp+Ch] [ebp-Ch] BYREF
  char uConstraints; // [esp+20h] [ebp+8h]

  Tool3D::OnLMouseDown2D(this, pView, nFlags, vPoint);
  uConstraints = this->GetConstraints(this, a2: nFlags);
  v6 = &pView->CMapView;
  pView->ClientToWorld(this: &pView->CMapView, a2: &vecWorld, a3: vPoint);
  *((_DWORD *)&vecWorld.x + pView->axThird) = 1203982208;
  CMapDoc::GetBestVisiblePoint(this: this->m_pDocument, ptOrg: &vecWorld);
  if ( (uConstraints & 4) != 0 )
    CMapDoc::Snap(this: this->m_pDocument, pt: &vecWorld, nFlags: uConstraints);
  v7 = 0;
  if ( !this->IsEmpty(this) )
  {
    v8 = this->HitTest(this, a2: v6, a3: vPoint, a4: false);
    if ( v8 > 0 )
    {
      v9 = v8 - 1;
      this->m_ClipPointHit = v9;
      v9 *= 3;
      v10 = *(&this->m_ClipPoints[0].x + v9);
      v11 = &this->m_ClipPoints[0].x + v9;
      this->m_vOrgPos.x = v10;
      this->m_vOrgPos.y = v11[1];
      this->m_vOrgPos.z = v11[2];
      Tool3D::StartTranslation(this, pView: v6, vClickPoint: vPoint, bUseDefaultPlane: true);
      goto LABEL_12;
    }
    v12 = (float *)v6->GetViewAxis(this: v6);
    if ( *v12 == this->m_vPlaneNormal.x
      && v12[1] == this->m_vPlaneNormal.y
      && v12[2] == this->m_vPlaneNormal.z
      && (nFlags & 4) == 0 )
    {
      return 1;
    }
    this->SetEmpty(this);
  }
  v7 = 1;
LABEL_12:
  List = CSelection::GetList(this: this->m_pDocument->m_pSelection);
  Clipper3D::SetClipObjects(this, pList: List);
  if ( v7 != 0 )
  {
    Tool3D::StartTranslation(this, pView: v6, vClickPoint: vPoint, bUseDefaultPlane: true);
    x = vecWorld.x;
    y = vecWorld.y;
    z = vecWorld.z;
    this->m_ClipPointHit = 0;
    this->m_ClipPoints[0].x = x;
    this->m_ClipPoints[0].y = y;
    this->m_ClipPoints[0].z = z;
    this->m_ClipPoints[1].x = x;
    this->m_ClipPoints[1].y = y;
    this->m_ClipPoints[1].z = z;
    this->m_vOrgPos.x = x;
    this->m_vOrgPos.y = y;
    this->m_vOrgPos.z = z;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015A5A0
// Name: protected: virtual bool Clipper3D::UpdateTranslation(class Vector const __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Clipper3D::UpdateTranslation(Clipper3D *this, const Vector *vUpdate, char uFlags)
{
  float x; // xmm2_4
  float y; // xmm1_4
  float z; // xmm0_4
  int m_ClipPointHit; // eax
  int v9; // eax
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm0_4
  int v13; // eax
  float v14; // xmm3_4
  Vector *v15; // eax
  float v16; // xmm3_4
  float v17; // xmm2_4
  float v18; // xmm1_4
  Vector *v19; // eax
  Vector vNewPos; // [esp+4h] [ebp-Ch] BYREF

  if ( this->IsEmpty(this) )
    return 0;
  x = this->m_vOrgPos.x + vUpdate->x;
  y = this->m_vOrgPos.y + vUpdate->y;
  z = this->m_vOrgPos.z + vUpdate->z;
  vNewPos.x = x;
  vNewPos.y = y;
  vNewPos.z = z;
  if ( (uFlags & 4) != 0 )
  {
    CMapDoc::Snap(this: this->m_pDocument, pt: &vNewPos, nFlags: uFlags);
    z = vNewPos.z;
    y = vNewPos.y;
    x = vNewPos.x;
  }
  m_ClipPointHit = this->m_ClipPointHit;
  if ( x == this->m_ClipPoints[m_ClipPointHit].x
    && y == this->m_ClipPoints[m_ClipPointHit].y
    && z == this->m_ClipPoints[m_ClipPointHit].z )
  {
    return 0;
  }
  if ( (uFlags & 0x40) != 0 )
  {
    v9 = this->m_ClipPointHit;
    v10 = x - this->m_ClipPoints[v9].x;
    v11 = y - this->m_ClipPoints[v9].y;
    v12 = z - this->m_ClipPoints[v9].z;
    v13 = (v9 + 1) % 2;
    v14 = this->m_ClipPoints[v13].x;
    v15 = &this->m_ClipPoints[v13];
    v16 = v14 + v10;
    v17 = v15->y + v11;
    v18 = v15->z + v12;
    v15->x = v16;
    v15->y = v17;
    v15->z = v18;
    x = vNewPos.x;
  }
  v19 = &this->m_ClipPoints[this->m_ClipPointHit];
  v19->x = x;
  v19->y = vNewPos.y;
  v19->z = vNewPos.z;
  Clipper3D::BuildClipPlane(this);
  Clipper3D::SetClipObjects(this, pList: this->m_pOrigObjects);
  Clipper3D::CalcClipResults(this);
  CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 16, ub: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015A730
// Name: protected: virtual void Clipper3D::FinishTranslation(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Clipper3D::FinishTranslation(Clipper3D *this, bool bSave)
{
  Clipper3D::SetClipObjects(this, pList: this->m_pOrigObjects);
  Clipper3D::CalcClipResults(this);
  Tool3D::FinishTranslation(this, bSave);
}

//------------------------------------------------------------------------------
// Address: 0x1015A760
// Name: public: virtual void Clipper3D::OnActivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Clipper3D::OnActivate(Clipper3D *this)
{
  if ( this->m_bActiveTool )
  {
    if ( ++this->m_Mode > 2 )
      this->m_Mode = 0;
    Clipper3D::SetClipObjects(this, pList: this->m_pOrigObjects);
    Clipper3D::CalcClipResults(this);
  }
}
