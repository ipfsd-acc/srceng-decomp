// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/toolmorph.cpp
// Functions: 46
// ============================================================

#include "hammer\toolmorph.h"

//------------------------------------------------------------------------------
// Address: 0x1015F9F0
// Name: private: virtual int Morph3D::HitTest(class CMapView __near *,class Vector2D const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall Morph3D::HitTest(Morph3D *this, CMapView *pView, const Vector2D *ptClient, bool bTestHandles)
{
  return this->m_bBoxSelecting && Box3D::HitTest(this, pView, ptClient, bTestHandles);
}

//------------------------------------------------------------------------------
// Address: 0x1015FA10
// Name: private: void Morph3D::StartTranslation(class CMapView __near *,class Vector2D const __near &,struct MORPHHANDLE __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Morph3D::StartTranslation(Morph3D *this, CMapView *pView, const Vector2D *vPoint, MORPHHANDLE *pInfo)
{
  Vector *p_m_OrigHandlePos; // edi
  SSHANDLEINFO v6; // [esp+Ch] [ebp-4Ch] BYREF
  Vector vOrigin; // [esp+28h] [ebp-30h] BYREF
  Vector vecHorz; // [esp+34h] [ebp-24h] BYREF
  Vector vecVert; // [esp+40h] [ebp-18h] BYREF
  Vector vecThird; // [esp+4Ch] [ebp-Ch] BYREF

  if ( this->m_bScaling )
  {
    this->m_bScaling = false;
    CWnd::SetWindowTextA(this: &this->m_ScaleDlg.m_cScale, lpszString: "1.0");
    this->m_bScaling = true;
  }
  p_m_OrigHandlePos = &this->m_OrigHandlePos;
  if ( pInfo->ssh == 1048560 )
  {
    p_m_OrigHandlePos->x = this->m_ScaleOrg.x;
    this->m_OrigHandlePos.y = this->m_ScaleOrg.y;
    this->m_OrigHandlePos.z = this->m_ScaleOrg.z;
  }
  else
  {
    CSSolid::GetHandleInfo(this: pInfo->pStrucSolid, pInfo: &v6, id: pInfo->ssh);
    p_m_OrigHandlePos->x = v6.pos.x;
    this->m_OrigHandlePos.y = v6.pos.y;
    this->m_OrigHandlePos.z = v6.pos.z;
  }
  pView->GetBestTransformPlane(this: pView, a2: &vecHorz, a3: &vecVert, a4: &vecThird);
  Tool3D::SetTransformationPlane(
    this,
    vOrigin: &this->m_OrigHandlePos,
    vHorz: &vecHorz,
    vVert: &vecVert,
    vNormal: &vecThird);
  Tool3D::ProjectOnTranslationPlane(this, vWorld: &vec3_origin, vTransform: &vOrigin, nFlags: 0);
  Tool3D::SetTransformationPlane(this, &vOrigin, vHorz: &vecHorz, vVert: &vecVert, vNormal: &vecThird);
  Tool3D::StartTranslation(this, pView, vClickPoint: vPoint, bUseDefaultPlane: false);
  this->m_DragHandle = *pInfo;
}

//------------------------------------------------------------------------------
// Address: 0x1015FB20
// Name: private: bool Morph3D::StartBoxSelection(class CMapView __near *,class Vector2D const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Morph3D::StartBoxSelection(
        Morph3D *this,
        CMapView *pView,
        const Vector2D *vPoint,
        const Vector *vStart)
{
  Vector vecSize; // [esp+4h] [ebp-Ch] BYREF

  this->m_bBoxSelecting = true;
  Box3D::SetDrawColors(this, dwHandleColor: 0xFFFFFFu, dwBoxColor: 0xFFFF32u);
  memset(&vecSize, 0, sizeof(vecSize));
  Box3D::StartNew(this, pView, vPoint, vecStart: vStart, &vecSize);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015FB80
// Name: public: virtual unsigned int Morph3D::GetConstraints(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall Morph3D::GetConstraints(Morph3D *this, unsigned int nFlags)
{
  unsigned int result; // eax

  result = Tool3D::GetConstraints(this, nKeyFlags: nFlags);
  if ( !this->m_bBoxSelecting )
  {
    if ( (nFlags & 8) != 0 )
      result |= 2u;
    if ( (nFlags & 4) != 0 )
      result |= 1u;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015FBB0
// Name: private: bool Morph3D::CanDeselectList(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Morph3D::CanDeselectList(Morph3D *this)
{
  int v2; // esi
  CSSolid **m_pMemory; // eax
  CSSolid *v4; // edi

  v2 = 0;
  if ( this->m_StrucSolids.m_Size <= 0 )
    return 1;
  while ( 1 )
  {
    m_pMemory = this->m_StrucSolids.m_Memory.m_pMemory;
    v4 = m_pMemory[v2];
    if ( v4 != nullptr && CSSolid::IsValidWithDisps(this: m_pMemory[v2]) == 0 )
    {
      if ( AfxMessageBox(lpszText: "Invalid solid, destroy displacement(s)?", nType: 4u, nIDHelp: 0) != 6 )
        break;
      CSSolid::DestroyDisps(this: v4);
    }
    if ( ++v2 >= this->m_StrucSolids.m_Size )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1015FC10
// Name: public: bool Morph3D::IsSelected(struct MORPHHANDLE __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Morph3D::IsSelected(Morph3D *this, MORPHHANDLE *mh)
{
  int m_Size; // esi
  int v3; // edx
  MORPHHANDLE *i; // eax

  m_Size = this->m_SelectedHandles.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return 0;
  for ( i = this->m_SelectedHandles.m_Memory.m_pMemory;
        i->pMapSolid != mh->pMapSolid || i->pStrucSolid != mh->pStrucSolid || i->ssh != mh->ssh;
        ++i )
  {
    if ( ++v3 >= m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015FC60
// Name: public: void Morph3D::MoveSelectedHandles(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Morph3D::MoveSelectedHandles(Morph3D *this, const Vector *Delta)
{
  int i; // esi

  for ( i = 0; i < this->m_StrucSolids.m_Size; ++i )
    CSSolid::MoveSelectedHandles(this: this->m_StrucSolids.m_Memory.m_pMemory[i], Delta);
}

//------------------------------------------------------------------------------
// Address: 0x1015FCA0
// Name: private: virtual bool Morph3D::UpdateTranslation(class Vector const __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __userpurge Morph3D::UpdateTranslation@<al>(
        Morph3D *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        const Vector *vUpdate,
        unsigned int uFlags)
{
  float v7; // xmm1_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm2_4
  __int128 v11; // xmm0
  SSHANDLEINFO v12; // [esp-28h] [ebp-44h] BYREF
  Vector v13; // [esp-Ch] [ebp-28h] BYREF
  __int128 vDelta; // [esp+0h] [ebp-1Ch] OVERLAPPED BYREF
  int v15; // [esp+10h] [ebp-Ch]
  void *v16; // [esp+14h] [ebp-8h]
  void *retaddr; // [esp+1Ch] [ebp+0h]

  v15 = a2;
  v16 = retaddr;
  if ( this->m_bBoxSelecting )
    return Box3D::UpdateTranslation(this, a2: a3, vUpdate, uConstraints: uFlags);
  if ( Tool3D::UpdateTranslation(this, vUpdate, flags: uFlags) == 0 )
    return 0;
  if ( this->m_DragHandle.ssh == 1048560 )
  {
    v7 = this->m_OrigHandlePos.y + vUpdate->y;
    v8 = this->m_OrigHandlePos.z + vUpdate->z;
    this->m_ScaleOrg.x = vUpdate->x + this->m_OrigHandlePos.x;
    this->m_ScaleOrg.y = v7;
    this->m_ScaleOrg.z = v8;
    if ( (uFlags & 4) != 0 )
      CMapDoc::Snap(this: this->m_pDocument, pt: &this->m_ScaleOrg, nFlags: uFlags);
    this->m_bUpdateOrg = false;
    return 1;
  }
  else
  {
    CSSolid::GetHandleInfo(this: this->m_DragHandle.pStrucSolid, pInfo: &v12, id: this->m_DragHandle.ssh);
    if ( uFlags != 0 )
    {
      *((float *)&vDelta + 1) = this->m_vTranslation.x + this->m_OrigHandlePos.x;
      *((float *)&vDelta + 2) = this->m_OrigHandlePos.y + this->m_vTranslation.y;
      *((float *)&vDelta + 3) = this->m_vTranslation.z + this->m_OrigHandlePos.z;
      Tool3D::ProjectOnTranslationPlane(
        this,
        vWorld: (const Vector *)((char *)&vDelta + 4),
        vTransform: &this->m_vTranslation,
        nFlags: uFlags);
      this->m_vTranslation.x = this->m_vTranslation.x - this->m_OrigHandlePos.x;
      this->m_vTranslation.y = this->m_vTranslation.y - this->m_OrigHandlePos.y;
      this->m_vTranslation.z = this->m_vTranslation.z - this->m_OrigHandlePos.z;
    }
    v9 = (float)(this->m_vTranslation.y + this->m_OrigHandlePos.y) - v12.pos.y;
    v10 = (float)(this->m_vTranslation.z + this->m_OrigHandlePos.z) - v12.pos.z;
    v13.x = (float)(this->m_vTranslation.x + this->m_OrigHandlePos.x) - v12.pos.x;
    v13.y = v9;
    v13.z = v10;
    v11 = 0;
    *(float *)&v11 = fsqrt((float)((float)(v9 * v9) + (float)(v10 * v10)) + (float)(v13.x * v13.x));
    vDelta = v11;
    if ( *(float *)&v11 < 0.5 )
      return 0;
    Morph3D::MoveSelectedHandles(this, Delta: &v13);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015FEA0
// Name: public: bool Morph3D::CanSplitFace(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall Morph3D::CanSplitFace(Morph3D *this)
{
  return this->m_SelectedHandles.m_Size == 2
      && this->m_SelectedType <= (unsigned int)shtEdge
      && this->m_SelectedHandles.m_Memory.m_pMemory->pStrucSolid == this->m_SelectedHandles.m_Memory.m_pMemory[1].pStrucSolid;
}

//------------------------------------------------------------------------------
// Address: 0x1015FED0
// Name: public: void Morph3D::ToggleMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Morph3D::ToggleMode(Morph3D *this)
{
  int m_HandleMode; // eax
  int i; // edi

  m_HandleMode = this->m_HandleMode;
  if ( m_HandleMode == 3 )
    this->m_HandleMode = 1;
  else
    this->m_HandleMode = (m_HandleMode != 1) + 2;
  for ( i = 0; i < this->m_StrucSolids.m_Size; ++i )
    CSSolid::ShowHandles(
      this: this->m_StrucSolids.m_Memory.m_pMemory[i],
      bShowVertices: this->m_HandleMode & 1,
      bShowEdges: this->m_HandleMode & 2);
  CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 16, ub: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1015FF60
// Name: public: void Morph3D::OnScaleCmd(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Morph3D::OnScaleCmd(Morph3D *this, int bReInit)
{
  int v3; // ebx
  int m_Size; // eax
  int v5; // edi
  BoundBox box; // [esp+Ch] [ebp-4Ch] BYREF
  SSHANDLEINFO hi; // [esp+28h] [ebp-30h] BYREF
  CPoint pt; // [esp+44h] [ebp-14h] BYREF
  int v9; // [esp+54h] [ebp-4h]
  Vector *bReInita; // [esp+60h] [ebp+8h]
  CPoint v11; // 0:^4.8

  v3 = 0;
  if ( this->m_pOrigPosList != nullptr )
  {
    operator delete(p: this->m_pOrigPosList);
    this->m_pOrigPosList = nullptr;
  }
  if ( this->m_bScaling )
  {
    if ( bReInit == 0 )
    {
      CWnd::ShowWindow(this: &this->m_ScaleDlg, nCmdShow: 0);
      this->m_ScaleDlg.DestroyWindow(this: &this->m_ScaleDlg);
      this->m_bScaling = false;
      return;
    }
    goto LABEL_8;
  }
  if ( bReInit != 0 )
  {
LABEL_8:
    this->m_bScaling = false;
    CWnd::SetWindowTextA(this: &this->m_ScaleDlg.m_cScale, lpszString: "1.0");
    this->m_bScaling = true;
    goto LABEL_9;
  }
  this->m_ScaleDlg.Create(this: &this->m_ScaleDlg, a2: 233u, a3: nullptr);
  pt.x = 0;
  pt.y = 0;
  GetCursorPos(lpPoint: &pt);
  v11 = pt;
  this->m_bUpdateOrg = true;
  CWnd::SetWindowPos(this: &this->m_ScaleDlg, pWndInsertAfter: nullptr, x: v11.x, y: v11.y, cx: 0, cy: 0, nFlags: 0x45u);
LABEL_9:
  m_Size = this->m_SelectedHandles.m_Size;
  if ( m_Size != 0 )
  {
    bReInita = (Vector *)operator new[](nSize: 12 * m_Size);
    v9 = -1;
    this->m_pOrigPosList = bReInita;
    BoundBox::BoundBox(this: &box);
    if ( this->m_SelectedHandles.m_Size > 0 )
    {
      v5 = 0;
      do
      {
        CSSolid::GetHandleInfo(
          this: this->m_SelectedHandles.m_Memory.m_pMemory[v5].pStrucSolid,
          pInfo: &hi,
          id: this->m_SelectedHandles.m_Memory.m_pMemory[v5].ssh);
        if ( hi.Type == shtVertex )
        {
          this->m_pOrigPosList[v5] = hi.pos;
          BoundBox::UpdateBounds(this: &box, pt: &hi.pos);
        }
        ++v3;
        ++v5;
      }
      while ( v3 < this->m_SelectedHandles.m_Size );
    }
    if ( this->m_bUpdateOrg )
      BoundBox::GetBoundsCenter(this: &box, ptdest: &this->m_ScaleOrg);
    CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 16, ub: nullptr);
  }
  this->m_bScaling = true;
}

//------------------------------------------------------------------------------
// Address: 0x10160140
// Name: public: void Morph3D::UpdateScale(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Morph3D::UpdateScale(Morph3D *this)
{
  char *v2; // esi
  Vector *m_pOrigPosList; // eax
  float v4; // xmm0_4
  float *v5; // eax
  float v6; // xmm0_4
  int v7; // ebx
  float v8; // [esp-10h] [ebp-48h]
  float v9; // [esp-Ch] [ebp-44h]
  float y[5]; // [esp+4h] [ebp-34h] BYREF
  SSHANDLEINFO hi; // [esp+18h] [ebp-20h] BYREF
  CSSEdge **pEdges; // [esp+34h] [ebp-4h]

  if ( this->m_bScaling )
  {
    hi.p2DHandle = (C2DHandle *)LODWORD(this->m_ScaleDlg.m_fScale);
    hi.pos.x = 0.0;
    if ( this->m_SelectedHandles.m_Size > 0 )
    {
      hi.pos.z = 0.0;
      pEdges = nullptr;
      do
      {
        v2 = (char *)pEdges + (unsigned int)this->m_SelectedHandles.m_Memory.m_pMemory;
        CSSolid::GetHandleInfo(this: *((CSSolid **)v2 + 1), pInfo: (SSHANDLEINFO *)y, id: *((_DWORD *)v2 + 2));
        if ( LODWORD(y[0]) == 0 )
        {
          m_pOrigPosList = this->m_pOrigPosList;
          v4 = *(float *)((char *)&m_pOrigPosList->x + LODWORD(hi.pos.z));
          v5 = (float *)((char *)&m_pOrigPosList->x + LODWORD(hi.pos.z));
          v6 = (float)((float)(v4 - this->m_ScaleOrg.x) * *(float *)&hi.p2DHandle) + this->m_ScaleOrg.x;
          v9 = (float)((float)(v5[2] - this->m_ScaleOrg.z) * *(float *)&hi.p2DHandle) + this->m_ScaleOrg.z;
          v8 = (float)((float)(v5[1] - this->m_ScaleOrg.y) * *(float *)&hi.p2DHandle) + this->m_ScaleOrg.y;
          LODWORD(hi.pos.z) += 12;
          CSSolid::SetVertexPosition(this: *((CSSolid **)v2 + 1), iVertex: SLODWORD(y[1]), x: v6, y: v8, z: v9);
          v7 = 0;
          for ( hi.pData = CSSolid::FindAffectedEdges(
                             this: *((CSSolid **)v2 + 1),
                             pHandles: (unsigned int *)v2 + 2,
                             iNumHandles: (unsigned int *)1,
                             iNumEdges: (int *)&hi.pos.y); v7 < SLODWORD(hi.pos.y); ++v7 )
            CSSolid::CalcEdgeCenter(this: *((CSSolid **)v2 + 1), pEdge: *((Vector **)hi.pData + v7));
        }
        pEdges += 3;
        ++LODWORD(hi.pos.x);
      }
      while ( SLODWORD(hi.pos.x) < this->m_SelectedHandles.m_Size );
    }
    CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 16, ub: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10160280
// Name: public: virtual bool Morph3D::CanDeactivate(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
char __thiscall Morph3D::CanDeactivate(Morph3D *this)
{
  return Morph3D::CanDeselectList(this);
}

//------------------------------------------------------------------------------
// Address: 0x10160290
// Name: public: void Morph3D::DeselectHandle(struct MORPHHANDLE __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Morph3D::DeselectHandle(Morph3D *this, MORPHHANDLE *pInfo)
{
  int v3; // edx
  int v4; // esi
  MORPHHANDLE *v5; // eax
  unsigned int i; // ecx

  v3 = 0;
  if ( this->m_SelectedHandles.m_Size > 0 )
  {
    v4 = (char *)this->m_SelectedHandles.m_Memory.m_pMemory - (char *)pInfo;
    while ( 2 )
    {
      v5 = pInfo;
      for ( i = 12; ; i -= 4 )
      {
        if ( i < 4 )
        {
          if ( this->m_SelectedHandles.m_Size - v3 - 1 > 0 )
            _V_memmove(
              dest: &this->m_SelectedHandles.m_Memory.m_pMemory[v3],
              src: &this->m_SelectedHandles.m_Memory.m_pMemory[v3 + 1],
              count: 12 * (this->m_SelectedHandles.m_Size - v3 - 1));
          --this->m_SelectedHandles.m_Size;
          return;
        }
        if ( *(CMapSolid **)((char *)&v5->pMapSolid + v4) != v5->pMapSolid )
          break;
        v5 = (MORPHHANDLE *)((char *)v5 + 4);
      }
      ++v3;
      v4 += 12;
      if ( v3 < this->m_SelectedHandles.m_Size )
        continue;
      break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10160320
// Name: public: Morph3D::Morph3D(void)
// Source: json
//------------------------------------------------------------------------------
Morph3D *__thiscall Morph3D::Morph3D(Morph3D *this)
{
  CSSolid **m_pMemory; // ecx
  MORPHHANDLE *v3; // ecx

  Box3D::Box3D(this);
  this->Box3D::Tool3D::CBaseTool::__vftable = (Morph3D_vtbl *)&Morph3D::`vftable'{for `Tool3D'};
  this->Box3D::BoundBox::__vftable = (BoundBox_vtbl *)&Morph3D::`vftable'{for `BoundBox'};
  this->m_StrucSolids.m_Memory.m_pMemory = nullptr;
  this->m_StrucSolids.m_Memory.m_nAllocationCount = 0;
  this->m_StrucSolids.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_StrucSolids.m_Memory.m_pMemory;
  this->m_StrucSolids.m_Size = 0;
  this->m_StrucSolids.m_pElements = m_pMemory;
  this->m_SelectedHandles.m_Memory.m_pMemory = nullptr;
  this->m_SelectedHandles.m_Memory.m_nAllocationCount = 0;
  this->m_SelectedHandles.m_Memory.m_nGrowSize = 0;
  v3 = this->m_SelectedHandles.m_Memory.m_pMemory;
  this->m_SelectedHandles.m_Size = 0;
  this->m_SelectedHandles.m_pElements = v3;
  BoundBox::BoundBox(this: &this->m_MorphBounds);
  CScaleVerticesDlg::CScaleVerticesDlg(this: &this->m_ScaleDlg, pParent: nullptr);
  this->m_SelectedType = shtNothing;
  this->m_HandleMode = 3;
  *(_WORD *)&this->m_bBoxSelecting = 0;
  this->m_pOrigPosList = nullptr;
  this->m_vLastMouseMovement.x = 0.0;
  this->m_vLastMouseMovement.y = 0.0;
  this->m_bHit = false;
  this->m_bUpdateOrg = false;
  this->m_bLButtonDownControlState = false;
  Box3D::SetDrawColors(this, dwHandleColor: Options.colors.clrToolHandle, dwBoxColor: Options.colors.clrToolMorph);
  *(_QWORD *)&this->m_DragHandle.pMapSolid = 0;
  this->m_DragHandle.ssh = 0;
  *(_WORD *)&this->m_bMorphing = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10160450
// Name: public: virtual bool Morph3D::IsEmpty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall Morph3D::IsEmpty(Morph3D *this)
{
  return this->m_StrucSolids.m_Size == 0 && !this->m_bBoxSelecting;
}

//------------------------------------------------------------------------------
// Address: 0x10160470
// Name: public: virtual Morph3D::~Morph3D(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Morph3D::~Morph3D(Morph3D *this)
{
  CScaleVerticesDlg *p_m_ScaleDlg; // esi
  CUtlVector<MORPHHANDLE,CUtlMemory<MORPHHANDLE,int> > *p_m_SelectedHandles; // esi
  CUtlVector<CSSolid *,CUtlMemory<CSSolid *,int> > *p_m_StrucSolids; // esi

  this->Box3D::Tool3D::CBaseTool::__vftable = (Morph3D_vtbl *)&Morph3D::`vftable'{for `Tool3D'};
  this->Box3D::BoundBox::__vftable = (BoundBox_vtbl *)&Morph3D::`vftable'{for `BoundBox'};
  p_m_ScaleDlg = &this->m_ScaleDlg;
  CEdit::~CEdit(this: &this->m_ScaleDlg.m_cScale);
  CSpinButtonCtrl::~CSpinButtonCtrl(this: &p_m_ScaleDlg->m_cScaleSpin);
  CDialog::~CDialog(this: p_m_ScaleDlg);
  p_m_SelectedHandles = &this->m_SelectedHandles;
  this->m_SelectedHandles.m_Size = 0;
  if ( this->m_SelectedHandles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_SelectedHandles->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_SelectedHandles->m_Memory.m_pMemory);
      p_m_SelectedHandles->m_Memory.m_pMemory = nullptr;
    }
    this->m_SelectedHandles.m_Memory.m_nAllocationCount = 0;
  }
  this->m_SelectedHandles.m_pElements = this->m_SelectedHandles.m_Memory.m_pMemory;
  if ( this->m_SelectedHandles.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_SelectedHandles->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_SelectedHandles->m_Memory.m_pMemory);
      p_m_SelectedHandles->m_Memory.m_pMemory = nullptr;
    }
    this->m_SelectedHandles.m_Memory.m_nAllocationCount = 0;
  }
  p_m_StrucSolids = &this->m_StrucSolids;
  this->m_StrucSolids.m_Size = 0;
  if ( this->m_StrucSolids.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_StrucSolids->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_StrucSolids->m_Memory.m_pMemory);
      p_m_StrucSolids->m_Memory.m_pMemory = nullptr;
    }
    this->m_StrucSolids.m_Memory.m_nAllocationCount = 0;
  }
  this->m_StrucSolids.m_pElements = this->m_StrucSolids.m_Memory.m_pMemory;
  if ( this->m_StrucSolids.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_StrucSolids->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_StrucSolids->m_Memory.m_pMemory);
      p_m_StrucSolids->m_Memory.m_pMemory = nullptr;
    }
    this->m_StrucSolids.m_Memory.m_nAllocationCount = 0;
  }
  this->Box3D::Tool3D::CBaseTool::__vftable = (Morph3D_vtbl *)&CBaseTool::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x101605A0
// Name: public: virtual void Morph3D::RenderTool2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Morph3D::RenderTool2D(Morph3D *this, CRender2D *pRender)
{
  CRender2D *v2; // esi
  Morph3D *v3; // ebx
  int v4; // eax
  CSSolid *v5; // esi
  int v6; // edi
  int v7; // ebx
  unsigned int v8; // esi
  CSSEdge *v9; // esi
  const char *v10; // edi
  int v11; // ebx
  unsigned int v12; // esi
  CSSolid *v13; // ebx
  CSSVertex *v14; // esi
  SSHANDLEINFO hi1; // [esp+Ch] [ebp-50h] BYREF
  SSHANDLEINFO hi2; // [esp+28h] [ebp-34h] BYREF
  const char *v17; // [esp+44h] [ebp-18h]
  int pos; // [esp+48h] [ebp-14h]
  Morph3D *v19; // [esp+4Ch] [ebp-10h]
  int nPass; // [esp+50h] [ebp-Ch]
  CSSolid *pStrucSolid; // [esp+54h] [ebp-8h]
  bool bClientSpace; // [esp+5Bh] [ebp-1h]

  v2 = pRender;
  v3 = this;
  v19 = this;
  CRender::SetHandleStyle(this: pRender, size: 4, type: 1);
  for ( nPass = 0; nPass < 2; ++nPass )
  {
    v4 = 0;
    pos = 0;
    if ( v3->m_StrucSolids.m_Size <= 0 )
      continue;
    do
    {
      v5 = v3->m_StrucSolids.m_Memory.m_pMemory[v4];
      v6 = 0;
      pStrucSolid = v5;
      if ( v5->m_nEdges <= 0 )
        goto LABEL_24;
      do
      {
        if ( v6 >= v5->m_Edges.nCount )
        {
          _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v6, v5->m_Edges.nCount);
          v7 = v6 + 1;
          if ( v6 + 1 != v5->m_Edges.nCount )
          {
            v8 = v7 / 16;
            if ( 16 * (v7 / 16) < v7 )
              ++v8;
            if ( v8 != pStrucSolid->m_Edges.nBlocks )
            {
              if ( v8 > 0x21 )
                _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
              BlockArray<CSSEdge,16,32>::GetBlocks(this: &pStrucSolid->m_Edges, nNewBlocks: v8);
            }
            pStrucSolid->m_Edges.nCount = v7;
          }
        }
        v9 = &pStrucSolid->m_Edges.Blocks[v6 / 16][v6 % 16];
        if ( v9->m_bSelected != 0 )
        {
          if ( nPass == 0 )
            goto LABEL_22;
        }
        else if ( nPass == 1 )
        {
          goto LABEL_22;
        }
        CRender::SetDrawColor(this: pRender, r: 0xFFu, g: 0, b: 0);
        CSSolid::GetHandleInfo(this: pStrucSolid, pInfo: &hi1, id: v9->hvStart);
        CSSolid::GetHandleInfo(this: pStrucSolid, pInfo: &hi2, id: v9->hvEnd);
        CRender::DrawLine(this: pRender, a2: v6, a3: (int)v9, vStart: &hi1.pos, vEnd: &hi2.pos);
        if ( (v19->m_HandleMode & 2) != 0 )
        {
          if ( v9->m_bSelected != 0 )
            CRender::SetHandleColor(
              this: pRender,
              r: Options.colors.clrSelection,
              g: BYTE1(Options.colors.clrSelection),
              b: BYTE2(Options.colors.clrSelection));
          else
            CRender::SetHandleColor(this: pRender, r: 0xFFu, g: 0xFFu, b: 0);
          CRender::DrawHandle(this: pRender, vCenter: &v9->ptCenter, vOffset: nullptr);
        }
LABEL_22:
        v17 = (const char *)++v6;
        v5 = pStrucSolid;
      }
      while ( v6 < pStrucSolid->m_nEdges );
      v3 = v19;
LABEL_24:
      if ( (v3->m_HandleMode & 1) != 0 )
      {
        v10 = nullptr;
        bClientSpace = CRender::BeginClientSpace(this: pRender, a2: (int)v5);
        if ( v5->m_nVertices > 0 )
        {
          while ( 1 )
          {
            if ( (int)v10 >= v5->m_Vertices.nCount )
            {
              _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v10, v5->m_Vertices.nCount);
              v11 = (int)(v10 + 1);
              if ( v10 + 1 != (const char *)v5->m_Vertices.nCount )
              {
                v12 = v11 / 16;
                if ( 16 * (v11 / 16) < v11 )
                  ++v12;
                if ( v12 != pStrucSolid->m_Vertices.nBlocks )
                {
                  if ( v12 > 0x21 )
                    _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
                  BlockArray<CSSVertex,16,32>::GetBlocks(this: &pStrucSolid->m_Vertices, nNewBlocks: v12);
                }
                pStrucSolid->m_Vertices.nCount = v11;
              }
            }
            v13 = pStrucSolid;
            v14 = &pStrucSolid->m_Vertices.Blocks[(int)v10 / 16][(int)v10 % 16];
            if ( v14->m_bSelected != 0 )
            {
              if ( nPass == 0 )
                goto LABEL_43;
              CRender::SetHandleColor(
                this: pRender,
                r: Options.colors.clrSelection,
                g: BYTE1(Options.colors.clrSelection),
                b: BYTE2(Options.colors.clrSelection));
            }
            else
            {
              if ( nPass == 1 )
                goto LABEL_43;
              CRender::SetHandleColor(
                this: pRender,
                r: Options.colors.clrToolHandle,
                g: BYTE1(Options.colors.clrToolHandle),
                b: BYTE2(Options.colors.clrToolHandle));
            }
            CRender::DrawHandle(this: pRender, vCenter: &v14->pos, vOffset: nullptr);
LABEL_43:
            v17 = ++v10;
            if ( (int)v10 >= v13->m_nVertices )
            {
              v3 = v19;
              break;
            }
            v5 = pStrucSolid;
          }
        }
        if ( bClientSpace )
          CRender::EndClientSpace(this: pRender);
      }
      v4 = pos + 1;
      pos = v4;
    }
    while ( v4 < v3->m_StrucSolids.m_Size );
    v2 = pRender;
  }
  if ( v3->m_bScaling && v3->m_SelectedHandles.m_Size != 0 )
  {
    CRender::SetHandleStyle(this: v2, size: 8, type: 2);
    CRender::SetHandleColor(
      this: v2,
      r: Options.colors.clrToolHandle,
      g: BYTE1(Options.colors.clrToolHandle),
      b: BYTE2(Options.colors.clrToolHandle));
    CRender::DrawHandle(this: v2, vCenter: &v3->m_ScaleOrg, vOffset: nullptr);
  }
  if ( v3->m_bBoxSelecting )
    Box3D::RenderTool2D(this: v3, pRender: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10160920
// Name: public: void Morph3D::GetSelectedCenter(class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Morph3D::GetSelectedCenter(Morph3D *this, Vector *pt)
{
  Morph3D *v2; // ebx
  int v3; // esi
  int v4; // edi
  int v5; // eax
  CSSolid *v6; // edi
  const char *v7; // esi
  BlockArray<CSSVertex,16,32> *p_m_Vertices; // ebx
  int v9; // ecx
  unsigned int v10; // edi
  SSHANDLEINFO hi; // [esp+Ch] [ebp-48h] BYREF
  BoundBox box; // [esp+28h] [ebp-2Ch] BYREF
  const char *v13; // [esp+44h] [ebp-10h]
  Morph3D *v14; // [esp+48h] [ebp-Ch]
  CSSolid *pStrucSolid; // [esp+4Ch] [ebp-8h]
  int pos; // [esp+50h] [ebp-4h]

  v2 = this;
  v14 = this;
  BoundBox::BoundBox(this: &box);
  if ( v2->m_SelectedHandles.m_Size <= 0 )
  {
    v5 = 0;
    for ( pos = 0; v5 < v2->m_StrucSolids.m_Size; pos = v5 )
    {
      v6 = v2->m_StrucSolids.m_Memory.m_pMemory[v5];
      v7 = nullptr;
      pStrucSolid = v6;
      if ( v6->m_nVertices > 0 )
      {
        p_m_Vertices = &v6->m_Vertices;
        do
        {
          if ( (int)v7 >= p_m_Vertices->nCount )
          {
            _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v7, p_m_Vertices->nCount);
            v9 = (int)(v7 + 1);
            if ( v7 + 1 != (const char *)p_m_Vertices->nCount )
            {
              v10 = v9 / 16;
              if ( 16 * (v9 / 16) < v9 )
                ++v10;
              if ( v10 != p_m_Vertices->nBlocks )
              {
                if ( v10 > 0x21 )
                  _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
                BlockArray<CSSVertex,16,32>::GetBlocks(this: p_m_Vertices, nNewBlocks: v10);
              }
              v6 = pStrucSolid;
              p_m_Vertices->nCount = (_WORD)v7 + 1;
            }
          }
          BoundBox::UpdateBounds(this: &box, pt: &p_m_Vertices->Blocks[(int)v7 / 16][(int)v7 % 16].pos);
          v13 = ++v7;
        }
        while ( (int)v7 < v6->m_nVertices );
        v5 = pos;
        v2 = v14;
      }
      ++v5;
    }
  }
  else
  {
    v3 = 0;
    v4 = 0;
    do
    {
      CSSolid::GetHandleInfo(
        this: v2->m_SelectedHandles.m_Memory.m_pMemory[v4].pStrucSolid,
        pInfo: &hi,
        id: v2->m_SelectedHandles.m_Memory.m_pMemory[v4].ssh);
      BoundBox::UpdateBounds(this: &box, pt: &hi.pos);
      ++v3;
      ++v4;
    }
    while ( v3 < v2->m_SelectedHandles.m_Size );
  }
  BoundBox::GetBoundsCenter(this: &box, ptdest: pt);
}

//------------------------------------------------------------------------------
// Address: 0x10160AA0
// Name: private: void Morph3D::RenderSolid3D(class CRender3D __near *,class CSSolid __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Morph3D::RenderSolid3D(Morph3D *this, CRender3D *pRender, CSSolid *pSolid)
{
  IMatRenderContext *(__thiscall *GetRenderContext)(IMaterialSystem *); // edx
  int v4; // eax
  CRender3D *v5; // esi
  CCamera *Camera; // eax
  int v7; // edi
  int m_nVertexCount; // esi
  unsigned int v9; // esi
  IMesh *v10; // edi
  int v11; // esi
  IMesh *v12; // edi
  int v13; // esi
  int v14; // edi
  CSSEdge *HandleData; // esi
  CSSEdge *v16; // eax
  CRender3D *v17; // edi
  int v18; // eax
  float v19; // xmm3_4
  float v20; // xmm0_4
  unsigned int v21; // eax
  CSSVertex *v22; // esi
  int v23; // eax
  float v24; // xmm3_4
  float v25; // xmm0_4
  unsigned int ConnectionVertex; // eax
  CSSVertex *v27; // eax
  int v28; // edx
  int v29; // ecx
  int v30; // eax
  int v31; // esi
  VMatrix ViewMatrix; // [esp+10h] [ebp-29Ch] BYREF
  CMeshBuilder meshBuilder; // [esp+50h] [ebp-25Ch] BYREF
  Vector Vertex; // [esp+238h] [ebp-74h] BYREF
  Vector2D vClient; // [esp+244h] [ebp-68h] BYREF
  Vector2D ClientPos; // [esp+24Ch] [ebp-60h] BYREF
  Vector CenterPoint; // [esp+254h] [ebp-58h] BYREF
  Vector vPoint; // [esp+260h] [ebp-4Ch] BYREF
  int nFaceCount; // [esp+26Ch] [ebp-40h]
  CSSFace *pFace; // [esp+270h] [ebp-3Ch]
  unsigned int *Edges; // [esp+274h] [ebp-38h]
  IMesh *pMesh; // [esp+278h] [ebp-34h]
  int nFace; // [esp+27Ch] [ebp-30h]
  int v44; // [esp+280h] [ebp-2Ch]
  CSSEdge *pEdgeNext; // [esp+284h] [ebp-28h]
  int v46; // [esp+288h] [ebp-24h]
  int nPass; // [esp+28Ch] [ebp-20h]
  bool bClientSpace; // [esp+293h] [ebp-19h]
  int nEdgeCount; // [esp+294h] [ebp-18h]
  unsigned __int8 color[8]; // [esp+298h] [ebp-14h]
  int v51; // [esp+2A8h] [ebp-4h]

  GetRenderContext = materials->GetRenderContext;
  bClientSpace = false;
  v4 = (int)GetRenderContext(this: materials);
  v46 = v4;
  v51 = 0;
  if ( v4 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 8))(a1: v4);
  v51 = 1;
  v5 = pRender;
  nPass = 1;
  while ( 1 )
  {
    if ( nPass == 1 )
    {
      CRender::PushRenderMode(this: v5, eRenderMode: RENDER_MODE_SELECTION_OVERLAY);
    }
    else if ( nPass == 2 )
    {
      CRender::PushRenderMode(this: v5, eRenderMode: RENDER_MODE_WIREFRAME);
    }
    else
    {
      CRender::PushRenderMode(this: v5, eRenderMode: RENDER_MODE_FLAT_NOZ);
      CRender::SetHandleStyle(this: v5, size: 4, type: 1);
      bClientSpace = CRender::BeginClientSpace(this: v5, a2: (int)v5);
      Camera = CRender::GetCamera(this: v5);
      CCamera::GetViewMatrix(this: Camera, Matrix: &ViewMatrix);
    }
    pMesh = (IMesh *)(*(int (__thiscall **)(int, int, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v46 + 228))(
                       a1: v46,
                       a2: 1,
                       a3: 0,
                       a4: 0,
                       a5: 0);
    meshBuilder.m_pMesh = nullptr;
    meshBuilder.m_bGenerateIndices = false;
    memset(&meshBuilder.m_IndexBuilder.m_pIndexBuffer, 0, 12);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    meshBuilder.m_IndexBuilder.m_nTotalIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nBufferOffset = -1;
    meshBuilder.m_IndexBuilder.m_nBufferFirstIndex = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_nBufferOffset = -1;
    meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = 0;
    memset(&meshBuilder.m_VertexBuilder.m_nMaxVertexCount, 0, 12);
    meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    LOBYTE(v51) = 4;
    v7 = 0;
    nFaceCount = pSolid->m_nFaces;
    nFace = 0;
    if ( nFaceCount > 0 )
      break;
LABEL_73:
    if ( bClientSpace )
    {
      CRender::EndClientSpace(this: v5);
      bClientSpace = false;
    }
    CRender::PopRenderMode(this: v5);
    LOBYTE(v51) = 14;
    if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
      && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
    {
      meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
    }
    LOBYTE(v51) = 1;
    if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
      && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
    {
      meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
    }
    if ( ++nPass > 3 )
    {
      v51 = 16;
      goto LABEL_83;
    }
  }
  m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
  while ( 1 )
  {
    nEdgeCount = (int)&pSolid->m_Faces;
    if ( v7 >= pSolid->m_Faces.nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v7, pSolid->m_Faces.nCount);
      if ( v7 + 1 != *(__int16 *)(nEdgeCount + 44) )
      {
        v9 = (v7 + 1) / 16;
        if ( (int)(16 * v9) < v7 + 1 )
          ++v9;
        if ( v9 != *(__int16 *)(nEdgeCount + 46) )
        {
          if ( v9 > 0xB )
            _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 10);
          BlockArray<CSSFace,16,10>::GetBlocks(this: (BlockArray<CSSFace,16,10> *)nEdgeCount, nNewBlocks: v9);
        }
        *(_WORD *)(nEdgeCount + 44) = v7 + 1;
      }
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    }
    pFace = (CSSFace *)(*(_DWORD *)(nEdgeCount + 4 * (v7 / 16)) + 912 * (v7 % 16));
    nEdgeCount = pFace->nEdges;
    if ( nPass == 1 )
    {
      v10 = pMesh;
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_pMesh = pMesh;
      meshBuilder.m_Type = MATERIAL_POLYGON;
      v11 = 3 * nEdgeCount - 6;
      pMesh->SetPrimitiveType(this: pMesh, a2: MATERIAL_TRIANGLES);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: nEdgeCount, a3: v11, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v10->IIndexBuffer;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v11;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = v10;
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
      m_nVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = nEdgeCount;
      meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
      meshBuilder.m_VertexBuilder.m_bModify = false;
      if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
      {
        meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
        meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
      }
      meshBuilder.m_VertexBuilder.m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pPosition;
      meshBuilder.m_VertexBuilder.m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pNormal;
      qmemcpy(
        meshBuilder.m_VertexBuilder.m_pCurrTexCoord,
        meshBuilder.m_VertexBuilder.m_pTexCoord,
        sizeof(meshBuilder.m_VertexBuilder.m_pCurrTexCoord));
      meshBuilder.m_VertexBuilder.m_pCurrColor = meshBuilder.m_VertexBuilder.m_pColor;
      *(_DWORD *)color = -2139062144;
    }
    else
    {
      if ( nPass != 2 )
        goto LABEL_31;
      v12 = pMesh;
      meshBuilder.m_pMesh = pMesh;
      meshBuilder.m_bGenerateIndices = true;
      meshBuilder.m_Type = MATERIAL_LINE_LOOP;
      v13 = 2 * nEdgeCount;
      pMesh->SetPrimitiveType(this: pMesh, a2: MATERIAL_LINES);
      meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: nEdgeCount, a3: v13, a4: &meshBuilder, a5: nullptr);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v12->IIndexBuffer;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = v13;
      meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
      meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = v12;
      meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
      meshBuilder.m_IndexBuilder.m_bModify = false;
      meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
      meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
      meshBuilder.m_VertexBuilder.VertexDesc_t = meshBuilder.VertexDesc_t;
      m_nVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_nVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = nEdgeCount;
      meshBuilder.m_VertexBuilder.m_NumBoneWeights = meshBuilder.m_NumBoneWeights != 0 ? 2 : 0;
      meshBuilder.m_VertexBuilder.m_bModify = false;
      if ( meshBuilder.m_VertexBuilder.m_nBufferOffset == -1 )
      {
        meshBuilder.m_VertexBuilder.m_nTotalVertexCount = 0;
        meshBuilder.m_VertexBuilder.m_nBufferOffset = meshBuilder.MeshDesc_t::VertexDesc_t::m_nOffset;
        meshBuilder.m_VertexBuilder.m_nBufferFirstVertex = meshBuilder.m_nFirstVertex;
      }
      meshBuilder.m_VertexBuilder.m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pPosition;
      meshBuilder.m_VertexBuilder.m_pCurrNormal = meshBuilder.m_VertexBuilder.m_pNormal;
      qmemcpy(
        meshBuilder.m_VertexBuilder.m_pCurrTexCoord,
        meshBuilder.m_VertexBuilder.m_pTexCoord,
        sizeof(meshBuilder.m_VertexBuilder.m_pCurrTexCoord));
      meshBuilder.m_VertexBuilder.m_pCurrColor = meshBuilder.m_VertexBuilder.m_pColor;
      *(_DWORD *)color = -1;
    }
    meshBuilder.m_VertexBuilder.m_nCurrentVertex = 0;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
LABEL_31:
    if ( nEdgeCount > 0 )
      break;
LABEL_59:
    if ( nPass == 1 || nPass == 2 )
    {
      if ( meshBuilder.m_bGenerateIndices )
      {
        switch ( meshBuilder.m_Type )
        {
          case MATERIAL_LINE_STRIP:
            v30 = 2 * m_nVertexCount - 2;
            break;
          case MATERIAL_LINE_LOOP:
            v30 = 2 * m_nVertexCount;
            break;
          case MATERIAL_POLYGON:
            v30 = 3 * m_nVertexCount - 6;
            break;
          case MATERIAL_QUADS:
            v30 = 6 * m_nVertexCount / 4;
            break;
          case MATERIAL_INSTANCED_QUADS:
            v30 = 0;
            break;
          default:
            v30 = m_nVertexCount;
            break;
        }
        CIndexBuilder::GenerateIndices(
          this: &meshBuilder.m_IndexBuilder,
          primitiveType: meshBuilder.m_Type,
          nIndexCount: v30);
        m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
      }
      meshBuilder.m_pMesh->UnlockMesh(
        this: meshBuilder.m_pMesh,
        a2: m_nVertexCount,
        a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
        a4: &meshBuilder);
      meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
      meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
      meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
      meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
      meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
      meshBuilder.m_pMesh = nullptr;
      pMesh->Draw_2(this: pMesh, a2: -1, a3: 0);
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
    }
    pEdgeNext = (CSSEdge *)++nFace;
    if ( nFace >= nFaceCount )
    {
      v5 = pRender;
      goto LABEL_73;
    }
    v7 = nFace;
  }
  v44 = 1;
  Edges = pFace->Edges;
  while ( 1 )
  {
    v14 = v44;
    if ( v44 == nEdgeCount )
      v14 = 0;
    HandleData = (CSSEdge *)CSSolid::GetHandleData(this: pSolid, id: *Edges);
    v16 = (CSSEdge *)CSSolid::GetHandleData(this: pSolid, id: pFace->Edges[v14]);
    pEdgeNext = v16;
    if ( HandleData == nullptr || v16 == nullptr )
      break;
    if ( nPass == 1 || nPass == 2 )
    {
      ConnectionVertex = CSSolid::GetConnectionVertex(this: pSolid, pEdge1: HandleData, pEdge2: v16);
      if ( ConnectionVertex == 0 )
      {
        LOBYTE(v51) = 8;
        if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
          && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
        {
          meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
        }
        LOBYTE(v51) = 1;
        if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
          && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
        {
          meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
        }
        v51 = 10;
        goto LABEL_83;
      }
      v27 = (CSSVertex *)CSSolid::GetHandleData(this: pSolid, id: ConnectionVertex);
      if ( v27 == nullptr )
      {
        LOBYTE(v51) = 11;
        if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
          && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
        {
          meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
        }
        LOBYTE(v51) = 1;
        if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
          && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
        {
          meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
        }
        v51 = 13;
        goto LABEL_83;
      }
      CSSVertex::GetPosition(this: v27, Position: &Vertex);
      v28 = color[3];
      v29 = color[1];
      *(Vector *)meshBuilder.m_VertexBuilder.m_pCurrPosition = Vertex;
      *(_DWORD *)meshBuilder.m_VertexBuilder.m_pCurrColor = color[2] | ((v29 | ((color[0] | (v28 << 8)) << 8)) << 8);
      CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    }
    else
    {
      if ( pSolid->m_bShowEdges != 0 )
      {
        CSSEdge::GetCenterPoint(this: HandleData, Point: &CenterPoint);
        v17 = pRender;
        if ( (float)((float)((float)((float)((float)(ViewMatrix.m[2][0] * CenterPoint.x)
                                           + (float)(ViewMatrix.m[2][1] * CenterPoint.y))
                                   + (float)(ViewMatrix.m[2][2] * CenterPoint.z))
                           + ViewMatrix.m[2][3])
                   * (float)(1.0
                           / (float)((float)((float)((float)(ViewMatrix.m[3][0] * CenterPoint.x)
                                                   + (float)(CenterPoint.y * ViewMatrix.m[3][1]))
                                           + (float)(CenterPoint.z * ViewMatrix.m[3][2]))
                                   + ViewMatrix.m[3][3]))) >= 0.0 )
        {
          HandleData->m_bVisible = 0;
        }
        else
        {
          CRender::TransformPoint(this: pRender, vClient: &ClientPos, vWorld: &CenterPoint);
          v18 = (int)(float)(ClientPos.y - 4.0);
          v19 = ClientPos.x + 5.0;
          v20 = ClientPos.y + 5.0;
          HandleData->m_r.left = (int)(float)(ClientPos.x - 4.0);
          HandleData->m_bVisible = 1;
          HandleData->m_r.top = v18;
          HandleData->m_r.right = (int)v19;
          HandleData->m_r.bottom = (int)v20;
          if ( HandleData->m_bSelected != 0 )
          {
            color[0] = -36;
            *(_WORD *)&color[1] = 0;
            color[3] = -1;
          }
          else
          {
            *(_DWORD *)color = -16711681;
          }
          CRender::SetHandleColor(this: pRender, r: color[0], g: color[1], b: 0);
          CRender::DrawHandle(this: pRender, vCenter: &CenterPoint, vOffset: nullptr);
        }
      }
      else
      {
        v17 = pRender;
      }
      if ( pSolid->m_bShowVertices != 0 )
      {
        v21 = CSSolid::GetConnectionVertex(this: pSolid, pEdge1: HandleData, pEdge2: pEdgeNext);
        v22 = (CSSVertex *)CSSolid::GetHandleData(this: pSolid, id: v21);
        CSSVertex::GetPosition(this: v22, Position: &vPoint);
        if ( (float)((float)((float)((float)((float)(ViewMatrix.m[2][0] * vPoint.x)
                                           + (float)(vPoint.y * ViewMatrix.m[2][1]))
                                   + (float)(vPoint.z * ViewMatrix.m[2][2]))
                           + ViewMatrix.m[2][3])
                   * (float)(1.0
                           / (float)((float)((float)((float)(ViewMatrix.m[3][0] * vPoint.x)
                                                   + (float)(vPoint.y * ViewMatrix.m[3][1]))
                                           + (float)(vPoint.z * ViewMatrix.m[3][2]))
                                   + ViewMatrix.m[3][3]))) >= 0.0 )
        {
          v22->m_bVisible = 0;
        }
        else
        {
          CRender::TransformPoint(this: v17, &vClient, vWorld: &vPoint);
          v23 = (int)(float)(vClient.y - 4.0);
          v24 = vClient.x + 5.0;
          v25 = vClient.y + 5.0;
          v22->m_r.left = (int)(float)(vClient.x - 4.0);
          v22->m_bVisible = 1;
          v22->m_r.top = v23;
          v22->m_r.right = (int)v24;
          v22->m_r.bottom = (int)v25;
          color[3] = -1;
          if ( v22->m_bSelected != 0 )
          {
            color[0] = -36;
            *(_WORD *)&color[1] = 0;
          }
          else
          {
            *(_WORD *)&color[1] = -1;
            color[0] = -1;
          }
          CRender::SetHandleColor(this: v17, r: color[0], g: color[1], b: color[2]);
          CRender::DrawHandle(this: v17, vCenter: &vPoint, vOffset: nullptr);
        }
      }
    }
    ++Edges;
    if ( v44++ >= nEdgeCount )
    {
      m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
      goto LABEL_59;
    }
  }
  LOBYTE(v51) = 5;
  if ( meshBuilder.m_VertexBuilder.m_pVertexBuffer != nullptr
    && meshBuilder.m_VertexBuilder.m_pVertexBuffer->IsDynamic(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer) )
  {
    meshBuilder.m_VertexBuilder.m_pVertexBuffer->EndCastBuffer(this: meshBuilder.m_VertexBuilder.m_pVertexBuffer);
  }
  LOBYTE(v51) = 1;
  if ( meshBuilder.m_IndexBuilder.m_pIndexBuffer != nullptr
    && meshBuilder.m_IndexBuilder.m_pIndexBuffer->IsDynamic(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer) )
  {
    meshBuilder.m_IndexBuilder.m_pIndexBuffer->EndCastBuffer(this: meshBuilder.m_IndexBuilder.m_pIndexBuffer);
  }
  v51 = 7;
LABEL_83:
  v31 = v46;
  if ( v46 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v46 + 12))(a1: v46);
  v51 = -1;
  if ( v31 != 0 )
    (*(void (__thiscall **)(int))(*(_DWORD *)v31 + 4))(a1: v31);
}

//------------------------------------------------------------------------------
// Address: 0x10161620
// Name: public: virtual void Morph3D::RenderTool3D(class CRender3D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Morph3D::RenderTool3D(Morph3D *this, CRender3D *pRender)
{
  int i; // edi

  if ( this->m_bBoxSelecting )
    Box3D::RenderTool3D(this, pRender);
  for ( i = 0; i < this->m_StrucSolids.m_Size; ++i )
    Morph3D::RenderSolid3D(this, pRender, pSolid: this->m_StrucSolids.m_Memory.m_pMemory[i]);
}

//------------------------------------------------------------------------------
// Address: 0x10161670
// Name: private: bool Morph3D::NudgeHandles(class CMapView __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Morph3D::NudgeHandles(Morph3D *this, CMapView *pView, unsigned int nChar, bool bSnap)
{
  Vector vThrd; // [esp+4h] [ebp-48h] BYREF
  Vector vHorz; // [esp+10h] [ebp-3Ch] BYREF
  Vector vVert; // [esp+1Ch] [ebp-30h] BYREF
  Vector vWorld; // [esp+28h] [ebp-24h] BYREF
  Vector pos; // [esp+34h] [ebp-18h] BYREF
  Vector vecDelta; // [esp+40h] [ebp-Ch] BYREF

  if ( this->m_SelectedHandles.m_Size < 1 || Options.view2d.bNudge == 0 )
    return 0;
  pView->GetBestTransformPlane(this: pView, a2: &vHorz, a3: &vVert, a4: &vThrd);
  CMapDoc::GetNudgeVector(this: this->m_pDocument, &vHorz, &vVert, nChar, bSnap, vecNudge: &vecDelta);
  if ( bSnap && this->m_SelectedHandles.m_Size == 1 && this->m_SelectedType == shtVertex )
  {
    Morph3D::GetSelectedCenter(this, pt: &pos);
    Tool3D::SetTransformationPlane(this, vOrigin: &pos, &vHorz, &vVert, vNormal: &vThrd);
    vWorld.x = vecDelta.x + pos.x;
    vWorld.y = pos.y + vecDelta.y;
    vWorld.z = vecDelta.z + pos.z;
    Tool3D::ProjectOnTranslationPlane(this, &vWorld, vTransform: &vecDelta, nFlags: 4);
    vecDelta.x = vecDelta.x - pos.x;
    vecDelta.y = vecDelta.y - pos.y;
    vecDelta.z = vecDelta.z - pos.z;
  }
  Morph3D::MoveSelectedHandles(this, Delta: &vecDelta);
  this->FinishTranslation(this, a2: true);
  this->m_pDocument->SetModifiedFlag(this: this->m_pDocument, a2: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101617E0
// Name: private: unsigned long Morph3D::Get2DMatches(class CMapView2D __near *,class CSSolid __near *,struct SSHANDLEINFO __near &,class CUtlVector<unsigned long,class CUtlMemory<unsigned long,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall Morph3D::Get2DMatches(
        Morph3D *this,
        CMapView2D *pView,
        CSSolid *pStrucSolid,
        SSHANDLEINFO *hi,
        CUtlVector<unsigned long,CUtlMemory<unsigned long,int> > *pSimilarList)
{
  int v5; // ebx
  int v6; // esi
  BlockArray<CSSVertex,16,32> *p_m_Vertices; // edi
  int v8; // ebx
  unsigned int v9; // edi
  CSSVertex *v10; // eax
  int v12; // esi
  CSSEdge *v13; // eax
  int axVert; // [esp+10h] [ebp-8h]
  unsigned int hNewMoveHandle; // [esp+14h] [ebp-4h]
  int axHorz; // [esp+20h] [ebp+8h]

  v5 = pView->axHorz;
  axVert = pView->axVert;
  hNewMoveHandle = 0;
  axHorz = v5;
  if ( hi->Type == shtVertex )
  {
    v6 = 0;
    if ( pStrucSolid->m_nVertices > 0 )
    {
      p_m_Vertices = &pStrucSolid->m_Vertices;
      do
      {
        if ( v6 >= p_m_Vertices->nCount )
        {
          _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v6, p_m_Vertices->nCount);
          v8 = v6 + 1;
          if ( v6 + 1 != p_m_Vertices->nCount )
          {
            v9 = v8 / 16;
            if ( 16 * (v8 / 16) < v8 )
              ++v9;
            if ( v9 != pStrucSolid->m_Vertices.nBlocks )
            {
              if ( v9 > 0x21 )
                _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
              BlockArray<CSSVertex,16,32>::GetBlocks(this: &pStrucSolid->m_Vertices, nNewBlocks: v9);
            }
            pStrucSolid->m_Vertices.nCount = v8;
          }
          v5 = axHorz;
        }
        v10 = &pStrucSolid->m_Vertices.Blocks[v6 / 16][v6 % 16];
        p_m_Vertices = &pStrucSolid->m_Vertices;
        if ( fabs(*(&hi->pos.x + v5) - *(&v10->pos.x + v5)) < 0.5
          && fabs(*(&hi->pos.x + axVert) - *(&v10->pos.x + axVert)) < 0.5 )
        {
          if ( v10->m_bSelected != 0 )
            hNewMoveHandle = v10->id;
          if ( pSimilarList != nullptr )
            CUtlVector<CTextureGroup *,CUtlMemory<CTextureGroup *,int>>::InsertBefore(
              this: (CUtlVector<CVisGroup *,CUtlMemory<CVisGroup *,int> > *)pSimilarList,
              elem: pSimilarList->m_Size,
              src: (CVisGroup *const *)&v10->id);
        }
        ++v6;
      }
      while ( v6 < pStrucSolid->m_nVertices );
      return hNewMoveHandle;
    }
    return 0;
  }
  if ( hi->Type != shtEdge )
    return 0;
  v12 = 0;
  if ( pStrucSolid->m_nEdges <= 0 )
    return 0;
  do
  {
    if ( v12 >= pStrucSolid->m_Edges.nCount )
    {
      _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v12, pStrucSolid->m_Edges.nCount);
      BlockArray<CSSEdge,16,32>::SetCount(this: &pStrucSolid->m_Edges, nObjects: v12 + 1);
    }
    v13 = &pStrucSolid->m_Edges.Blocks[v12 / 16][v12 % 16];
    if ( fabs(*(&hi->pos.x + v5) - *(&v13->ptCenter.x + v5)) < 0.5
      && fabs(*(&hi->pos.x + axVert) - *(&v13->ptCenter.x + axVert)) < 0.5 )
    {
      if ( v13->m_bSelected != 0 )
        hNewMoveHandle = v13->id;
      if ( pSimilarList != nullptr )
        CUtlVector<CTextureGroup *,CUtlMemory<CTextureGroup *,int>>::InsertBefore(
          this: (CUtlVector<CVisGroup *,CUtlMemory<CVisGroup *,int> > *)pSimilarList,
          elem: pSimilarList->m_Size,
          src: (CVisGroup *const *)&v13->id);
    }
    ++v12;
  }
  while ( v12 < pStrucSolid->m_nEdges );
  return hNewMoveHandle;
}

//------------------------------------------------------------------------------
// Address: 0x10161A40
// Name: public: void Morph3D::SelectHandle(struct MORPHHANDLE __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Morph3D::SelectHandle(Morph3D *this, MORPHHANDLE *pInfo, CSSolid *cmd)
{
  Morph3D *v3; // edi
  CMapDoc *m_pDocument; // ecx
  char v5; // bl
  int v6; // eax
  CSSolid *v7; // ebx
  const char *v8; // esi
  BlockArray<CSSVertex,16,32> *p_m_Vertices; // edi
  int v10; // ecx
  unsigned int v11; // ebx
  SSHANDLEINFO hi; // [esp+8h] [ebp-30h] BYREF
  MORPHHANDLE mh; // [esp+24h] [ebp-14h] BYREF
  const char *v14; // [esp+30h] [ebp-8h]
  Morph3D *v15; // [esp+34h] [ebp-4h]
  int pos; // [esp+40h] [ebp+8h]
  CSSolid *pStrucSolid; // [esp+44h] [ebp+Ch]

  v3 = this;
  m_pDocument = this->m_pDocument;
  v15 = v3;
  CMapDoc::UpdateAllViews(this: m_pDocument, nFlags: 16, ub: nullptr);
  if ( pInfo == nullptr || pInfo->ssh != 1048560 )
  {
    v5 = (char)cmd;
    if ( ((unsigned __int16)cmd & 0x200) != 0 )
    {
      v6 = 0;
      for ( pos = 0; v6 < v3->m_StrucSolids.m_Size; pos = v6 )
      {
        v7 = v3->m_StrucSolids.m_Memory.m_pMemory[v6];
        v8 = nullptr;
        pStrucSolid = v7;
        if ( v7->m_nVertices > 0 )
        {
          p_m_Vertices = &v7->m_Vertices;
          do
          {
            if ( (int)v8 >= p_m_Vertices->nCount )
            {
              _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v8, p_m_Vertices->nCount);
              v10 = (int)(v8 + 1);
              if ( v8 + 1 != (const char *)p_m_Vertices->nCount )
              {
                v11 = v10 / 16;
                if ( 16 * (v10 / 16) < v10 )
                  ++v11;
                if ( v11 != p_m_Vertices->nBlocks )
                {
                  if ( v11 > 0x21 )
                    _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
                  BlockArray<CSSVertex,16,32>::GetBlocks(this: p_m_Vertices, nNewBlocks: v11);
                }
                v7 = pStrucSolid;
                p_m_Vertices->nCount = (_WORD)v8 + 1;
              }
            }
            mh.ssh = p_m_Vertices->Blocks[(int)v8 / 16][(int)v8 % 16].id;
            mh.pStrucSolid = v7;
            mh.pMapSolid = v7->m_pMapSolid;
            Morph3D::SelectHandle(this: v15, pInfo: &mh, cmd: 2u);
            v14 = ++v8;
          }
          while ( (int)v8 < v7->m_nVertices );
          v6 = pos;
          v3 = v15;
        }
        ++v6;
      }
    }
    else
    {
      if ( ((unsigned __int8)cmd & 0x10) != 0 && v3->m_SelectedHandles.m_Size > 0 )
      {
        do
          Morph3D::SelectHandle(this: v3, pInfo: v3->m_SelectedHandles.m_Memory.m_pMemory, cmd: 4u);
        while ( v3->m_SelectedHandles.m_Size > 0 );
      }
      if ( cmd != (CSSolid *)16 )
      {
        if ( CSSolid::GetHandleInfo(this: pInfo->pStrucSolid, pInfo: &hi, id: pInfo->ssh) == 0 )
        {
          Morph3D::DeselectHandle(this: v3, pInfo);
          return;
        }
        if ( hi.Type != v3->m_SelectedType )
          Morph3D::SelectHandle(this: v3, pInfo: nullptr, cmd: 0x10u);
        v3->m_SelectedType = hi.Type;
        if ( ((unsigned __int8)cmd & 1) != 0 )
          v5 = (2 * (hi.p2DHandle->m_bSelected == 1) + 2) | (unsigned __int8)cmd & 0xFE;
        if ( (v5 & 2) == 0 || hi.p2DHandle->m_bSelected != 0 )
        {
          if ( (v5 & 4) == 0 || hi.p2DHandle->m_bSelected == 0 )
            return;
          hi.p2DHandle->m_bSelected = 0;
        }
        else
        {
          hi.p2DHandle->m_bSelected = 1;
        }
        if ( hi.p2DHandle->m_bSelected != 0 )
          CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
            this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&v3->m_SelectedHandles,
            elem: v3->m_SelectedHandles.m_Size,
            src: (const Vector *)pInfo);
        else
          Morph3D::DeselectHandle(this: v3, pInfo);
      }
      if ( v3->m_bScaling )
        Morph3D::OnScaleCmd(this: v3, bReInit: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10161C90
// Name: private: void Morph3D::SelectInBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Morph3D::SelectInBox(Morph3D *this)
{
  Morph3D *v1; // edi
  bool v2; // zf
  CMapDoc *m_pDocument; // ecx
  int v4; // ecx
  int v5; // eax
  const char *v6; // esi
  int v7; // ebx
  unsigned int v8; // edi
  CSSVertex *v9; // eax
  float *p_x; // edx
  int v11; // ecx
  float *v12; // edi
  CSSolid *v13; // edi
  unsigned int id; // eax
  bool v15; // cc
  MORPHHANDLE mh; // [esp+4h] [ebp-1Ch] BYREF
  const char *v17; // [esp+10h] [ebp-10h]
  int pos; // [esp+14h] [ebp-Ch]
  Morph3D *v19; // [esp+18h] [ebp-8h]
  CSSolid *pStrucSolid; // [esp+1Ch] [ebp-4h]

  v1 = this;
  v2 = !this->m_bBoxSelecting;
  v19 = this;
  if ( !v2 )
  {
    m_pDocument = this->m_pDocument;
    v1->m_bBoxSelecting = false;
    CMapDoc::UpdateAllViews(this: m_pDocument, nFlags: 16, ub: nullptr);
    v4 = 0;
    if ( (float)(v1->bmaxs.x - v1->bmins.x) == 0.0 )
    {
      v1->bmaxs.x = 99999.0;
      v1->bmins.x = -99999.0;
      v4 = 1;
    }
    if ( (float)(v1->bmaxs.y - v1->bmins.y) == 0.0 )
    {
      v1->bmaxs.y = 99999.0;
      v1->bmins.y = -99999.0;
      ++v4;
    }
    if ( (float)(v1->bmaxs.z - v1->bmins.z) == 0.0 )
    {
      v1->bmaxs.z = 99999.0;
      v1->bmins.z = -99999.0;
      ++v4;
    }
    if ( v4 <= 1 )
    {
      v5 = 0;
      for ( pos = 0; v5 < v1->m_StrucSolids.m_Size; pos = v5 )
      {
        v6 = nullptr;
        pStrucSolid = v1->m_StrucSolids.m_Memory.m_pMemory[v5];
        if ( pStrucSolid->m_nVertices > 0 )
        {
          do
          {
            if ( (int)v6 >= pStrucSolid->m_Vertices.nCount )
            {
              _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: v6, pStrucSolid->m_Vertices.nCount);
              v7 = (int)(v6 + 1);
              if ( v6 + 1 != (const char *)pStrucSolid->m_Vertices.nCount )
              {
                v8 = v7 / 16;
                if ( 16 * (v7 / 16) < v7 )
                  ++v8;
                if ( v8 != pStrucSolid->m_Vertices.nBlocks )
                {
                  if ( v8 > 0x21 )
                    _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
                  BlockArray<CSSVertex,16,32>::GetBlocks(this: &pStrucSolid->m_Vertices, nNewBlocks: v8);
                }
                v1 = v19;
                pStrucSolid->m_Vertices.nCount = v7;
              }
            }
            v9 = &pStrucSolid->m_Vertices.Blocks[(int)v6 / 16][(int)v6 % 16];
            p_x = &v1->bmaxs.x;
            v11 = 0;
            v12 = &v9->pos.x;
            do
            {
              if ( *(p_x - 3) > *v12 )
                break;
              if ( *v12 > *p_x )
                break;
              ++v11;
              ++v12;
              ++p_x;
            }
            while ( v11 < 3 );
            v13 = pStrucSolid;
            if ( v11 == 3 )
            {
              id = v9->id;
              mh.pMapSolid = pStrucSolid->m_pMapSolid;
              mh.ssh = id;
              mh.pStrucSolid = pStrucSolid;
              Morph3D::SelectHandle(this: v19, pInfo: &mh, cmd: (CSSolid *)2);
            }
            v15 = (int)++v6 < v13->m_nVertices;
            v1 = v19;
            v17 = v6;
          }
          while ( v15 );
          v5 = pos;
        }
        ++v5;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10161EB0
// Name: public: virtual void Morph3D::FinishTranslation(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Morph3D::FinishTranslation(Morph3D *this, bool bSave)
{
  Morph3D *v2; // edi
  bool v3; // zf
  CSSolid **pData; // esi
  C2DHandle *p2DHandle; // edx
  int v6; // ecx
  int y_low; // ebx
  int m_Size; // eax
  CSSolid *v9; // ecx
  int v10; // eax
  int v11; // edi
  CSSolid **v12; // edi
  CSSolid *v13; // edi
  int v14; // esi
  unsigned int *i; // ebx
  CMapSolid *m_pMapSolid; // eax
  int v17; // esi
  SSHANDLEINFO pInfo; // [esp+4h] [ebp-44h] BYREF
  MORPHHANDLE mh; // [esp+20h] [ebp-28h] BYREF
  int nDeleted; // [esp+2Ch] [ebp-1Ch] BYREF
  CSSolid *pStrucSolid; // [esp+30h] [ebp-18h]
  int pos; // [esp+34h] [ebp-14h]
  Morph3D *v23; // [esp+38h] [ebp-10h]
  int v24; // [esp+44h] [ebp-4h]

  v2 = this;
  v3 = !this->m_bBoxSelecting;
  v23 = this;
  if ( !v3 )
  {
    Box3D::FinishTranslation(this, bSave);
    return;
  }
  if ( !bSave || this->m_DragHandle.ssh == 1048560 )
    goto LABEL_42;
  pData = nullptr;
  memset(&pInfo.pData, 0, 20);
  p2DHandle = nullptr;
  v6 = 0;
  y_low = 0;
  v24 = 1;
  m_Size = v2->m_StrucSolids.m_Size;
  pos = 0;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      v9 = v2->m_StrucSolids.m_Memory.m_pMemory[v6];
      v10 = 0;
      pStrucSolid = v9;
      if ( y_low <= 0 )
        goto LABEL_13;
      while ( pData[v10] != v9 )
      {
        if ( ++v10 >= y_low )
          goto LABEL_13;
      }
      if ( v10 == -1 )
      {
LABEL_13:
        v11 = y_low;
        if ( y_low + 1 > (int)p2DHandle )
        {
          CUtlMemory<CVisGroup *,int>::Grow(
            this: (CUtlMemory<CCullTreeNode *,int> *)&pInfo.pData,
            num: y_low - (_DWORD)p2DHandle + 1);
          y_low = LODWORD(pInfo.pos.y);
          pData = (CSSolid **)pInfo.pData;
          v9 = pStrucSolid;
        }
        LODWORD(pInfo.pos.y) = ++y_low;
        LODWORD(pInfo.pos.z) = pData;
        if ( y_low - v11 - 1 > 0 )
        {
          _V_memmove(dest: &pData[v11 + 1], src: &pData[v11], count: 4 * (y_low - v11 - 1));
          v9 = pStrucSolid;
        }
        v12 = &pData[v11];
        if ( v12 != nullptr )
          *v12 = v9;
        v2 = v23;
      }
      v6 = pos + 1;
      pos = v6;
      if ( v6 >= v2->m_StrucSolids.m_Size )
        break;
      p2DHandle = pInfo.p2DHandle;
    }
  }
  pos = -1;
  pStrucSolid = nullptr;
  if ( y_low <= 0 )
    goto LABEL_34;
  do
  {
    v13 = pData[(_DWORD)pStrucSolid];
    if ( CSSolid::CanMergeVertices(this: v13) != 0 && pos != 0 )
    {
      if ( pos == -1 )
      {
        if ( AfxMessageBox(lpszText: "Merge vertices?", nType: 4u, nIDHelp: 0) != 6 )
        {
          pos = 0;
          goto LABEL_32;
        }
        pos = 1;
      }
      else if ( pos != 1 )
      {
        goto LABEL_32;
      }
      v14 = 0;
      for ( i = CSSolid::MergeSameVertices(this: v13, &nDeleted); v14 < nDeleted; ++v14 )
      {
        m_pMapSolid = v13->m_pMapSolid;
        mh.ssh = i[v14];
        mh.pStrucSolid = v13;
        mh.pMapSolid = m_pMapSolid;
        Morph3D::SelectHandle(this: v23, pInfo: &mh, cmd: (CSSolid *)4);
      }
      pData = (CSSolid **)pInfo.pData;
      y_low = LODWORD(pInfo.pos.y);
    }
LABEL_32:
    pStrucSolid = (CSSolid *)((char *)pStrucSolid + 1);
  }
  while ( (int)pStrucSolid < y_low );
  v2 = v23;
LABEL_34:
  v24 = 2;
  pInfo.pos.y = 0.0;
  if ( pInfo.pos.x >= 0.0 )
  {
    if ( pData != nullptr )
    {
      free(pMem: pData);
      pInfo.pData = nullptr;
      pData = nullptr;
    }
    pInfo.p2DHandle = nullptr;
  }
  LODWORD(pInfo.pos.z) = pData;
  v24 = -1;
  if ( pInfo.pos.x >= 0.0 )
  {
    if ( pData != nullptr )
    {
      free(pMem: pData);
      pInfo.pData = nullptr;
    }
    pInfo.p2DHandle = nullptr;
  }
LABEL_42:
  Tool3D::FinishTranslation(this: v2, bSave);
  if ( bSave )
  {
    if ( v2->m_bScaling )
      Morph3D::OnScaleCmd(this: v2, bReInit: 1);
  }
  else
  {
    CSSolid::GetHandleInfo(this: v2->m_DragHandle.pStrucSolid, &pInfo, id: v2->m_DragHandle.ssh);
    *(float *)&mh.pMapSolid = v2->m_OrigHandlePos.x - pInfo.pos.x;
    *(float *)&mh.pStrucSolid = v2->m_OrigHandlePos.y - pInfo.pos.y;
    v17 = 0;
    for ( *(float *)&mh.ssh = v2->m_OrigHandlePos.z - pInfo.pos.z; v17 < v2->m_StrucSolids.m_Size; ++v17 )
      CSSolid::MoveSelectedHandles(this: v2->m_StrucSolids.m_Memory.m_pMemory[v17], Delta: (const Vector *)&mh);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101621B0
// Name: public: bool Morph3D::SplitFace(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Morph3D::SplitFace(Morph3D *this)
{
  MORPHHANDLE *m_pMemory; // eax

  if ( this->m_SelectedHandles.m_Size != 2 )
    return 0;
  if ( this->m_SelectedType > (unsigned int)shtEdge )
    return 0;
  m_pMemory = this->m_SelectedHandles.m_Memory.m_pMemory;
  if ( m_pMemory->pStrucSolid != m_pMemory[1].pStrucSolid )
    return 0;
  if ( CSSolid::SplitFace(this: m_pMemory->pStrucSolid, h1: m_pMemory->ssh, h2: m_pMemory[1].ssh) != 0 )
  {
    if ( this->m_SelectedType == shtVertex )
    {
      Morph3D::SelectHandle(this, pInfo: nullptr, cmd: (CSSolid *)0x10);
      CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 1, ub: nullptr);
      return 0;
    }
    this->m_SelectedHandles.m_Size = 0;
    CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 1, ub: nullptr);
    return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10162230
// Name: public: void Morph3D::GetMorphingObjects(class CUtlVector<class CMapClass __near *,class CUtlMemory<class CMapClass __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Morph3D::GetMorphingObjects(Morph3D *this, CUtlMemory<CCullTreeNode *,int> *List)
{
  Morph3D *v2; // edx
  int i; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CMapClass **v7; // ecx
  int v8; // eax
  CMapClass **v9; // eax
  CUtlVector<CMapClass *,CUtlMemory<CMapClass *,int> > *Lista; // [esp+10h] [ebp+8h]

  v2 = this;
  for ( i = 0; i < v2->m_StrucSolids.m_Size; ++i )
  {
    m_pMemory = (int)List[1].m_pMemory;
    Lista = (CUtlVector<CMapClass *,CUtlMemory<CMapClass *,int> > *)v2->m_StrucSolids.m_Memory.m_pMemory[i]->m_pMapSolid;
    m_nAllocationCount = List->m_nAllocationCount;
    if ( m_pMemory + 1 > m_nAllocationCount )
    {
      CUtlMemory<CVisGroup *,int>::Grow(this: List, num: m_pMemory - m_nAllocationCount + 1);
      v2 = this;
    }
    ++List[1].m_pMemory;
    v7 = (CMapClass **)List->m_pMemory;
    v8 = (int)List[1].m_pMemory - m_pMemory - 1;
    List[1].m_nAllocationCount = (int)List->m_pMemory;
    if ( v8 > 0 )
    {
      _V_memmove(dest: &v7[m_pMemory + 1], src: &v7[m_pMemory], count: 4 * v8);
      v2 = this;
    }
    v9 = (CMapClass **)&List->m_pMemory[m_pMemory];
    if ( v9 != nullptr )
      *v9 = (CMapClass *)Lista;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101622D0
// Name: public: virtual bool Morph3D::OnLMouseUp3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Morph3D::OnLMouseUp3D(Morph3D *this, CMapView3D *pView, unsigned int nFlags, const Vector2D *vPoint)
{
  int v5; // eax

  Tool3D::OnLMouseUp3D(this, pView, nFlags, vPoint);
  if ( this->m_bHit )
  {
    this->m_bHit = false;
    v5 = 18;
    if ( (nFlags & 8) != 0 )
      v5 = 1;
    Morph3D::SelectHandle(this, pInfo: &this->m_DragHandle, cmd: (CSSolid *)v5);
  }
  if ( this->m_bMorphing )
  {
    this->FinishTranslation(this, a2: true);
    this->m_bMorphing = false;
  }
  ReleaseCapture();
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10162350
// Name: private: void Morph3D::OnEscape(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Morph3D::OnEscape(Morph3D *this)
{
  CMapDoc *m_pDocument; // ecx
  CToolManager *v3; // eax

  if ( this->m_bBoxSelecting )
  {
    m_pDocument = this->m_pDocument;
    this->m_bBoxSelecting = false;
    CMapDoc::UpdateAllViews(this: m_pDocument, nFlags: 16, ub: nullptr);
  }
  else if ( this->IsEmpty(this) || this->m_SelectedHandles.m_Size == 0 )
  {
    v3 = ToolManager();
    CToolManager::SetTool(this: v3, eNewTool: TOOL_POINTER);
  }
  else
  {
    Morph3D::SelectHandle(this, pInfo: nullptr, cmd: (CSSolid *)0x10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101623B0
// Name: public: virtual void Morph3D::OnDeactivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Morph3D::OnDeactivate(Morph3D *this)
{
  CMapClass *v2; // edi
  CMapClass_vtbl *v3; // esi
  CMapClass *ParentWnd; // eax
  CMapClass *v5; // eax
  int m_nGrowSize; // edi
  CMapClass **m_pMemory; // eax
  CUtlVector<CMapClass *,CUtlMemory<CMapClass *,int> > List; // [esp+8h] [ebp-24h] BYREF
  int i; // [esp+1Ch] [ebp-10h]
  int v10; // [esp+28h] [ebp-4h]

  if ( this->m_bScaling )
    Morph3D::OnScaleCmd(this, bReInit: 0);
  if ( !this->IsEmpty(this) )
  {
    memset(&List, 0, sizeof(List));
    v10 = 1;
    Morph3D::GetMorphingObjects(this, (CUtlMemory<CCullTreeNode *,int> *)&List);
    this->SetEmpty(this);
    for ( i = 0; i < List.m_Size; ++i )
    {
      v2 = List.m_Memory.m_pMemory[i];
      v3 = v2->__vftable;
      ParentWnd = CVGuiWnd::GetParentWnd(this: (CMapClass *)this->m_pDocument->m_pSelection);
      v5 = v3->PrepareSelection(this: v2, a2: (SelectMode_t)ParentWnd);
      if ( v5 != nullptr )
        CMapDoc::SelectObject(this: this->m_pDocument, pObj: v5, cmd: 2);
    }
    CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 16, ub: nullptr);
    v10 = 2;
    m_nGrowSize = List.m_Memory.m_nGrowSize;
    m_pMemory = List.m_Memory.m_pMemory;
    List.m_Size = 0;
    if ( List.m_Memory.m_nGrowSize >= 0 )
    {
      if ( List.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: List.m_Memory.m_pMemory);
        List.m_Memory.m_pMemory = nullptr;
        m_pMemory = nullptr;
      }
      List.m_Memory.m_nAllocationCount = 0;
    }
    List.m_pElements = m_pMemory;
    v10 = -1;
    if ( m_nGrowSize >= 0 && m_pMemory != nullptr )
      free(pMem: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101624D0
// Name: private: bool Morph3D::MorphHitTest(class CMapView __near *,class Vector2D const __near &,struct MORPHHANDLE __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Morph3D::MorphHitTest(Morph3D *this, CMapView *pView, const Vector2D *vPoint, MORPHHANDLE *pInfo)
{
  Morph3D *v4; // esi
  bool IsOrthographic; // al
  int v7; // eax
  bool v8; // zf
  CSSolid *v9; // ebx
  int v10; // edi
  int v11; // ecx
  unsigned int v12; // esi
  int v13; // esi
  int v14; // edi
  int v15; // ecx
  unsigned int v16; // esi
  int v17; // esi
  CMapView2D *v18; // eax
  unsigned int v19; // eax
  unsigned int v20; // edx
  SSHANDLEINFO hi; // [esp+Ch] [ebp-34h] BYREF
  int v22; // [esp+28h] [ebp-18h]
  int pos; // [esp+2Ch] [ebp-14h]
  CSSolid *pStrucSolid; // [esp+30h] [ebp-10h]
  unsigned int hnd; // [esp+34h] [ebp-Ch]
  Tool3D *v26; // [esp+38h] [ebp-8h]
  bool bIs2D; // [esp+3Fh] [ebp-1h]

  v4 = this;
  v26 = this;
  hnd = 0;
  IsOrthographic = CMapView::IsOrthographic(this: pView);
  bIs2D = IsOrthographic;
  if ( pInfo != nullptr )
  {
    *(_QWORD *)&pInfo->pMapSolid = 0;
    pInfo->ssh = 0;
  }
  if ( IsOrthographic
    && v4->m_bScaling
    && pInfo != nullptr
    && Tool3D::HitRect(this: v4, pView, vPoint, vCenter: &v4->m_ScaleOrg, extent: 8) )
  {
    pInfo->ssh = 1048560;
    return 1;
  }
  else
  {
    v7 = 0;
    pos = 0;
    if ( v4->m_StrucSolids.m_Size > 0 )
    {
      while ( 1 )
      {
        v8 = (v4->m_HandleMode & 1) == 0;
        v9 = v4->m_StrucSolids.m_Memory.m_pMemory[v7];
        pStrucSolid = v9;
        if ( !v8 )
        {
          v10 = 0;
          if ( v9->m_nVertices > 0 )
          {
            while ( 1 )
            {
              if ( v10 >= v9->m_Vertices.nCount )
              {
                _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v10, v9->m_Vertices.nCount);
                v11 = v10 + 1;
                if ( v10 + 1 != v9->m_Vertices.nCount )
                {
                  v12 = v11 / 16;
                  if ( 16 * (v11 / 16) < v11 )
                    ++v12;
                  if ( v12 != v9->m_Vertices.nBlocks )
                  {
                    if ( v12 > 0x21 )
                      _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
                    BlockArray<CSSVertex,16,32>::GetBlocks(this: &v9->m_Vertices, nNewBlocks: v12);
                  }
                  v9->m_Vertices.nCount = v10 + 1;
                }
              }
              v13 = (int)&v9->m_Vertices.Blocks[v10 / 16][v10 % 16];
              if ( Tool3D::HitRect(this: v26, pView, vPoint, vCenter: (const Vector *)(v13 + 32), extent: 4) )
                break;
              v22 = ++v10;
              if ( v10 >= pStrucSolid->m_nVertices )
                goto LABEL_24;
            }
            hnd = *(_DWORD *)(v13 + 44);
LABEL_24:
            v9 = pStrucSolid;
            v4 = (Morph3D *)v26;
          }
        }
        if ( hnd != 0 )
          break;
        if ( (v4->m_HandleMode & 2) != 0 )
        {
          v14 = 0;
          if ( v9->m_nEdges > 0 )
          {
            while ( 1 )
            {
              if ( v14 >= v9->m_Edges.nCount )
              {
                _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: (const char *)v14, v9->m_Edges.nCount);
                v15 = v14 + 1;
                if ( v14 + 1 != v9->m_Edges.nCount )
                {
                  v16 = v15 / 16;
                  if ( 16 * (v15 / 16) < v15 )
                    ++v16;
                  if ( v16 != v9->m_Edges.nBlocks )
                  {
                    if ( v16 > 0x21 )
                      _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)0x10, 32);
                    BlockArray<CSSEdge,16,32>::GetBlocks(this: &v9->m_Edges, nNewBlocks: v16);
                  }
                  v9->m_Edges.nCount = v14 + 1;
                }
              }
              v17 = (int)&v9->m_Edges.Blocks[v14 / 16][v14 % 16];
              if ( Tool3D::HitRect(this: v26, pView, vPoint, vCenter: (const Vector *)(v17 + 40), extent: 4) )
                break;
              v22 = ++v14;
              if ( v14 >= pStrucSolid->m_nEdges )
                goto LABEL_41;
            }
            hnd = *(_DWORD *)(v17 + 60);
            if ( hnd == 0 )
            {
LABEL_41:
              v4 = (Morph3D *)v26;
              goto LABEL_42;
            }
            v4 = (Morph3D *)v26;
            v9 = pStrucSolid;
            break;
          }
        }
LABEL_42:
        v7 = pos + 1;
        pos = v7;
        if ( v7 >= v4->m_StrucSolids.m_Size )
          return hnd != 0;
      }
      if ( bIs2D )
      {
        CSSolid::GetHandleInfo(this: v9, pInfo: &hi, id: hnd);
        v18 = (CMapView2D *)__RTDynamicCast(
                              inptr: pView,
                              VfDelta: 0,
                              SrcType: &CMapView `RTTI Type Descriptor',
                              TargetType: &CMapView2D `RTTI Type Descriptor',
                              isReference: 0);
        v19 = Morph3D::Get2DMatches(this: v4, pView: v18, pStrucSolid: v9, &hi, pSimilarList: nullptr);
        if ( v19 != 0 )
          hnd = v19;
      }
      if ( pInfo != nullptr )
      {
        v20 = hnd;
        pInfo->pMapSolid = v9->m_pMapSolid;
        pInfo->pStrucSolid = v9;
        pInfo->ssh = v20;
      }
    }
    return hnd != 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101627F0
// Name: public: void Morph3D::SelectHandle2D(class CMapView2D __near *,struct MORPHHANDLE __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Morph3D::SelectHandle2D(Morph3D *this, CMapView2D *pView, MORPHHANDLE *pInfo, unsigned int cmd)
{
  int v4; // esi
  CMapSolid *m_pMapSolid; // ecx
  int m_nGrowSize; // esi
  unsigned int *m_pMemory; // eax
  SSHANDLEINFO hi; // [esp+Ch] [ebp-48h] BYREF
  CUtlVector<unsigned long,CUtlMemory<unsigned long,int> > addSimilarList; // [esp+28h] [ebp-2Ch] BYREF
  MORPHHANDLE mh; // [esp+3Ch] [ebp-18h] BYREF
  int v12; // [esp+50h] [ebp-4h]

  v4 = 0;
  if ( pInfo != nullptr && pInfo->ssh != 1048560 )
  {
    if ( CSSolid::GetHandleInfo(this: pInfo->pStrucSolid, pInfo: &hi, id: pInfo->ssh) != 0 )
    {
      memset(&addSimilarList, 0, sizeof(addSimilarList));
      v12 = 1;
      Morph3D::Get2DMatches(this, pView, pStrucSolid: pInfo->pStrucSolid, &hi, pSimilarList: &addSimilarList);
      if ( addSimilarList.m_Size > 0 )
      {
        do
        {
          mh.ssh = addSimilarList.m_Memory.m_pMemory[v4];
          m_pMapSolid = pInfo->pStrucSolid->m_pMapSolid;
          mh.pStrucSolid = pInfo->pStrucSolid;
          mh.pMapSolid = m_pMapSolid;
          Morph3D::SelectHandle(this, pInfo: &mh, (CSSolid *)cmd);
          if ( v4 == 0 )
            cmd &= ~0x10u;
          ++v4;
        }
        while ( v4 < addSimilarList.m_Size );
      }
      CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 16, ub: nullptr);
      v12 = 2;
      m_nGrowSize = addSimilarList.m_Memory.m_nGrowSize;
      m_pMemory = addSimilarList.m_Memory.m_pMemory;
      addSimilarList.m_Size = 0;
      if ( addSimilarList.m_Memory.m_nGrowSize >= 0 )
      {
        if ( addSimilarList.m_Memory.m_pMemory != nullptr )
        {
          free(pMem: addSimilarList.m_Memory.m_pMemory);
          addSimilarList.m_Memory.m_pMemory = nullptr;
          m_pMemory = nullptr;
        }
        addSimilarList.m_Memory.m_nAllocationCount = 0;
      }
      addSimilarList.m_pElements = m_pMemory;
      v12 = -1;
      if ( m_nGrowSize >= 0 && m_pMemory != nullptr )
        free(pMem: m_pMemory);
    }
    else
    {
      Morph3D::DeselectHandle(this, pInfo);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10162930
// Name: public: virtual bool Morph3D::OnKeyDown2D(class CMapView2D __near *,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Morph3D::OnKeyDown2D(
        Morph3D *this,
        CMapView2D *pView,
        unsigned int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  CMapView *v6; // eax
  bool bSnap; // [esp+8h] [ebp-4h]

  if ( !this->m_pDocument->m_bSnapToGrid || (bSnap = true, GetKeyState(nVirtKey: 17) < 0) )
    bSnap = false;
  if ( nChar == 38 || nChar == 40 || nChar == 37 || nChar == 39 )
  {
    v6 = pView != nullptr ? &pView->CMapView : nullptr;
    if ( Morph3D::NudgeHandles(this, pView: v6, nChar, bSnap) != 0 )
      return 1;
  }
  if ( nChar == 13 )
  {
    if ( this->m_bBoxSelecting )
      Morph3D::SelectInBox(this);
  }
  else if ( nChar == 27 )
  {
    Morph3D::OnEscape(this);
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101629D0
// Name: public: virtual bool Morph3D::OnLMouseUp2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Morph3D::OnLMouseUp2D(Morph3D *this, CMapView2D *pView, unsigned int nFlags, const Vector2D *vPoint)
{
  unsigned int v5; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  Tool3D::OnLMouseUp3D(this, (CMapView3D *)pView, nFlags, vPoint);
  if ( this->IsTranslating(this) )
  {
    this->FinishTranslation(this, a2: true);
    if ( this->m_bBoxSelecting && Options.view2d.bAutoSelect != 0 )
      Morph3D::SelectInBox(this);
  }
  else if ( this->m_DragHandle.ssh != 0 )
  {
    v5 = 18;
    if ( this->m_bLButtonDownControlState )
      v5 = 1;
    Morph3D::SelectHandle2D(this, pView, pInfo: &this->m_DragHandle, cmd: v5);
    CMapDoc::UpdateStatusbar(this: this->m_pDocument, a2: COERCE_FLOAT(&savedregs), a3: (int)pView, a4: (int)this);
    return 1;
  }
  CMapDoc::UpdateStatusbar(this: this->m_pDocument, a2: COERCE_FLOAT(&savedregs), a3: (int)pView, a4: (int)this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10162A70
// Name: public: virtual bool Morph3D::OnMouseMove2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Morph3D::OnMouseMove2D(Morph3D *this, CMapView2D *pView, __int64 nFlags)
{
  CMapView *v4; // edi
  char string[32]; // [esp+18h] [ebp-A0h] BYREF
  char szBuf[128]; // [esp+38h] [ebp-80h] BYREF
  unsigned int vecWorld; // [esp+C4h] [ebp+Ch]

  *(_DWORD *)&szBuf[124] = this->GetConstraints(this, a2: nFlags);
  Tool3D::OnMouseMove2D(this, pView, nFlags, vPoint: (const Vector2D *)HIDWORD(nFlags));
  v4 = &pView->CMapView;
  pView->ClientToWorld(this: &pView->CMapView, a2: (Vector *)&szBuf[112], a3: (const Vector2D *)HIDWORD(nFlags));
  CMapDoc::Snap(this: this->m_pDocument, pt: (Vector *)&szBuf[112], nFlags: szBuf[124]);
  sprintf(
    string: &string[4],
    format: " @%.0f, %.0f ",
    *(float *)&szBuf[4 * pView->axHorz + 112],
    *(float *)&szBuf[4 * pView->axVert + 112]);
  SetStatusText(nIndex: 2, pszText: &string[4]);
  if ( !this->m_bMouseDown[0] )
  {
    vecWorld = 2;
    if ( !this->IsEmpty(this) )
    {
      if ( this->m_bBoxSelecting
        || Morph3D::MorphHitTest(this, pView: v4, vPoint: (const Vector2D *)HIDWORD(nFlags), pInfo: nullptr) == 0 )
      {
        if ( this->HitTest(this, a2: v4, a3: (const Vector2D *)HIDWORD(nFlags), a4: true) != 0 )
        {
          vecWorld = Box3D::UpdateCursor(
                       this,
                       pView: v4,
                       vHandleHit: &this->m_LastHitTestHandle,
                       eTransformMode: this->m_TranslateMode);
          if ( vecWorld == 1 )
            return 1;
        }
      }
      else
      {
        vecWorld = 6;
      }
    }
    CVGuiWnd::SetCursor(this: &pView->CVGuiWnd, cursor: vecWorld);
    return 1;
  }
  if ( this->IsTranslating(this) )
  {
    Tool3D::UpdateTranslation(
      this,
      pView: v4,
      vPoint: (const Vector2D *)HIDWORD(nFlags),
      nFlags: *(unsigned int *)&szBuf[124]);
    return 1;
  }
  if ( !this->m_bMouseDragged[0] )
    return 1;
  if ( this->m_DragHandle.ssh != 0 )
  {
    if ( this->m_bLButtonDownControlState && Morph3D::IsSelected(this, mh: &this->m_DragHandle) == 0 )
      Morph3D::SelectHandle2D(this, pView, pInfo: &this->m_DragHandle, cmd: 2u);
    Morph3D::StartTranslation(this, pView: v4, vPoint: this->m_vMouseStart, pInfo: &this->m_DragHandle);
    return 1;
  }
  if ( this->m_bBoxSelecting )
    return 1;
  if ( (nFlags & 8) == 0 )
    Morph3D::SelectHandle(this, pInfo: nullptr, cmd: (CSSolid *)0x10);
  v4->ClientToWorld(this: v4, a2: (Vector *)&szBuf[100], a3: this->m_vMouseStart);
  *(_DWORD *)&szBuf[4 * pView->axThird + 100] = 1203982208;
  CMapDoc::GetBestVisiblePoint(this: this->m_pDocument, ptOrg: (Vector *)&szBuf[100]);
  Morph3D::StartBoxSelection(this, pView: v4, vPoint: this->m_vMouseStart, vStart: (const Vector *)&szBuf[100]);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10162CA0
// Name: public: virtual bool Morph3D::OnKeyDown3D(class CMapView3D __near *,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Morph3D::OnKeyDown3D(
        Morph3D *this,
        CMapView3D *pView,
        unsigned int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  CMapView *v6; // eax
  bool bSnap; // [esp+4h] [ebp-4h]

  if ( !this->m_pDocument->m_bSnapToGrid || (bSnap = true, GetAsyncKeyState(vKey: 17) < 0) )
    bSnap = false;
  if ( nChar == 27 )
  {
    Morph3D::OnEscape(this);
  }
  else
  {
    if ( nChar <= 0x24 || nChar > 0x28 )
      return 0;
    v6 = pView != nullptr ? &pView->CMapView : nullptr;
    if ( Morph3D::NudgeHandles(this, pView: v6, nChar, bSnap) == 0 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10162D20
// Name: public: virtual bool Morph3D::OnMouseMove3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Morph3D::OnMouseMove3D(Morph3D *this, CMapView3D *pView, unsigned int nFlags, const Vector2D *vPoint)
{
  bool v5; // zf
  CSSolid *pStrucSolid; // ecx
  int v7; // eax
  unsigned int v8; // eax
  CMapView *v9; // ecx
  CMapView *v11; // eax
  HCURSOR CursorA; // eax
  unsigned int ssh; // [esp-4h] [ebp-2Ch]
  SSHANDLEINFO hi; // [esp+Ch] [ebp-1Ch] BYREF

  Tool3D::OnMouseMove3D(this, pView, nFlags, vPoint);
  if ( !this->m_bMorphing )
  {
    if ( pView != nullptr )
      v11 = &pView->CMapView;
    else
      v11 = nullptr;
    if ( Morph3D::MorphHitTest(this, pView: v11, vPoint, pInfo: nullptr) != 0 )
    {
      AfxGetModuleState();
      CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F03);
    }
    else
    {
      AfxGetModuleState();
      CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
    }
    SetCursor(hCursor: CursorA);
    return 1;
  }
  if ( !this->m_bMovingSelected )
  {
    if ( fabs(vPoint->x - this->m_vLastMouseMovement.x) > 3.0 || fabs(vPoint->y - this->m_vLastMouseMovement.y) > 3.0 )
    {
      v5 = !this->m_bHit;
      this->m_bMovingSelected = true;
      if ( !v5 )
      {
        ssh = this->m_DragHandle.ssh;
        pStrucSolid = this->m_DragHandle.pStrucSolid;
        this->m_bHit = false;
        CSSolid::GetHandleInfo(this: pStrucSolid, pInfo: &hi, id: ssh);
        v7 = 2;
        if ( (nFlags & 8) == 0 && hi.p2DHandle->m_bSelected == 0 )
          v7 = 18;
        Morph3D::SelectHandle(this, pInfo: &this->m_DragHandle, cmd: (CSSolid *)v7);
      }
      goto LABEL_10;
    }
    return 1;
  }
LABEL_10:
  v8 = this->GetConstraints(this, a2: nFlags);
  if ( pView != nullptr )
    v9 = &pView->CMapView;
  else
    v9 = nullptr;
  Tool3D::UpdateTranslation(this, pView: v9, vPoint, nFlags: v8);
  this->m_vLastMouseMovement = *vPoint;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10162E80
// Name: public: void Morph3D::SelectObject(class CMapSolid __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Morph3D::SelectObject(Morph3D *this, CMapSolid *pSolid, char cmd)
{
  CChoreoChannel *v3; // ebx
  CUtlReference<CMapClass> *m_pHead; // eax
  int m_Size; // edx
  int v8; // eax
  CSSolid **v9; // ecx
  CSSolid *v10; // ebx
  CSSolid *v11; // eax
  SelectionState_t (__thiscall *SetSelectionState)(CMapAtom *, SelectionState_t); // eax
  int m_nAllocationCount; // eax
  CUtlMemory<CCullTreeNode *,int> *p_m_StrucSolids; // esi
  int v15; // edi
  CCullTreeNode **m_pMemory; // ecx
  int v17; // eax
  CChoreoChannel **v18; // edi
  int v19; // ebx
  int v20; // ecx
  MORPHHANDLE *v21; // edx
  int i; // esi
  CUtlReferenceVector<CMapClass> List; // [esp+Ch] [ebp-3Ch] BYREF
  Vector mins; // [esp+20h] [ebp-28h] BYREF
  Vector maxs; // [esp+2Ch] [ebp-1Ch] BYREF
  CSSolid *pStrucSolid; // [esp+38h] [ebp-10h] BYREF
  int v27; // [esp+44h] [ebp-4h]
  CMapSolid *pSolida; // [esp+50h] [ebp+8h]
  unsigned int cmda; // [esp+54h] [ebp+Ch]

  v3 = nullptr;
  memset(&List, 0, 12);
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &List.m_Memory, nGrowSize: 0, nInitSize: 0);
  List.m_Size = 0;
  List.m_pElements = nullptr;
  v27 = 3;
  maxs.y = 0.0;
  maxs.x = 0.0;
  LODWORD(maxs.z) = pSolid;
  if ( pSolid != nullptr )
  {
    m_pHead = pSolid->m_References.m_pHead;
    LODWORD(maxs.x) = m_pHead;
    if ( m_pHead != nullptr )
      m_pHead->m_pPrev = (CUtlReference<CMapClass> *)&maxs;
    maxs.y = 0.0;
    pSolid->m_References.m_pHead = (CUtlReference<CMapClass> *)&maxs;
  }
  LOBYTE(v27) = 4;
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
    this: &List,
    elem: List.m_Size,
    src: (const CUtlReference<CMapClass> *)&maxs);
  LOBYTE(v27) = 3;
  if ( LODWORD(maxs.z) != 0 )
  {
    if ( LODWORD(maxs.y) != 0 )
    {
      *(_DWORD *)LODWORD(maxs.y) = LODWORD(maxs.x);
      if ( LODWORD(maxs.x) != 0 )
        *(float *)(LODWORD(maxs.x) + 4) = maxs.y;
    }
    else if ( *(Vector **)(LODWORD(maxs.z) + 32) == &maxs )
    {
      *(float *)(LODWORD(maxs.z) + 32) = maxs.x;
      if ( LODWORD(maxs.x) != 0 )
        *(_DWORD *)(LODWORD(maxs.x) + 4) = 0;
    }
    memset(&maxs, 0, sizeof(maxs));
  }
  if ( (cmd & 0x10) != 0 )
    this->SetEmpty(this);
  m_Size = this->m_StrucSolids.m_Size;
  v8 = 0;
  if ( m_Size <= 0 )
  {
LABEL_20:
    v11 = (CSSolid *)operator new(nSize: 0x15Cu);
    LOBYTE(v27) = 8;
    if ( v11 != nullptr )
      v3 = (CChoreoChannel *)CSSolid::CSSolid(this: v11);
    LOBYTE(v27) = 3;
    CChoreoChannel::SetActor(this: v3, actor: (CChoreoActor *)pSolid);
    CSSolid::Convert(this: (CSSolid *)v3, bFromMap: 1, bSkipDisplacementFaces: false);
    CSSolid::ShowHandles(this: (CSSolid *)v3, bShowVertices: this->m_HandleMode & 1, bShowEdges: this->m_HandleMode & 2);
    SetSelectionState = pSolid->SetSelectionState;
    *((_BYTE *)&pSolid->CMapClass + 180) &= ~1u;
    SetSelectionState(this: pSolid, a2: SELECT_MORPH);
    m_nAllocationCount = this->m_StrucSolids.m_Memory.m_nAllocationCount;
    p_m_StrucSolids = (CUtlMemory<CCullTreeNode *,int> *)&this->m_StrucSolids;
    v15 = this->m_StrucSolids.m_Size;
    if ( v15 + 1 > m_nAllocationCount )
      CUtlMemory<CVisGroup *,int>::Grow(this: p_m_StrucSolids, num: v15 - m_nAllocationCount + 1);
    ++p_m_StrucSolids[1].m_pMemory;
    m_pMemory = p_m_StrucSolids->m_pMemory;
    v17 = (int)p_m_StrucSolids[1].m_pMemory - v15 - 1;
    p_m_StrucSolids[1].m_nAllocationCount = (int)p_m_StrucSolids->m_pMemory;
    if ( v17 > 0 )
      _V_memmove(dest: &m_pMemory[v15 + 1], src: &m_pMemory[v15], count: 4 * v17);
    v18 = (CChoreoChannel **)&p_m_StrucSolids->m_pMemory[v15];
    if ( v18 != nullptr )
      *v18 = v3;
    v27 = -1;
    CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &List);
  }
  else
  {
    v9 = this->m_StrucSolids.m_Memory.m_pMemory;
    while ( 1 )
    {
      v10 = *v9;
      pSolida = (CMapSolid *)*v9;
      if ( (*v9)->m_pMapSolid == pSolid )
        break;
      ++v8;
      ++v9;
      if ( v8 >= m_Size )
      {
        v3 = nullptr;
        goto LABEL_20;
      }
    }
    pStrucSolid = *v9;
    if ( (cmd & 5) != 0 )
    {
      CMapClass::GetRender2DBox(this: pSolid, &mins, &maxs);
      BoundBox::UpdateBounds(this: &this->m_MorphBounds, &mins, &maxs);
      CSSolid::Convert(this: v10, bFromMap: 0, bSkipDisplacementFaces: false);
      CMapClass::GetRender2DBox(this: pSolid, &mins, &maxs);
      BoundBox::UpdateBounds(this: &this->m_MorphBounds, &mins, &maxs);
      CSSolid::Detach(this: v10);
      this->m_pDocument->SetModifiedFlag(this: this->m_pDocument, a2: 1);
      *((_BYTE *)&pSolid->CMapClass + 180) |= 1u;
      CUtlVector<CMapView2D *,CUtlMemory<CMapView2D *,int>>::FindAndRemove(
        this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_StrucSolids,
        src: (vgui::TreeNode *const *)&pStrucSolid);
      v19 = this->m_SelectedHandles.m_Size - 1;
      if ( v19 >= 0 )
      {
        v20 = 12 * v19;
        cmda = 12 * v19;
        do
        {
          v21 = this->m_SelectedHandles.m_Memory.m_pMemory;
          if ( *(CMapSolid **)((char *)&v21->pStrucSolid + v20) == pSolida )
          {
            if ( this->m_SelectedHandles.m_Size - v19 - 1 > 0 )
            {
              _V_memmove(
                dest: (char *)v21 + v20,
                src: (char *)&v21[1] + v20,
                count: 12 * (this->m_SelectedHandles.m_Size - v19 - 1));
              v20 = cmda;
            }
            --this->m_SelectedHandles.m_Size;
          }
          v20 -= 12;
          --v19;
          cmda = v20;
        }
        while ( v19 >= 0 );
      }
      CSSolid::~CSSolid(this: (CSSolid *)pSolida);
      operator delete(p: pSolida);
      pSolid->SetSelectionState(this: pSolid, a2: SELECT_NONE);
    }
    v27 = 7;
    CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::RemoveAll(this: &List);
    if ( List.m_Memory.m_pMemory != nullptr )
    {
      for ( i = 0; i < List.m_Memory.m_nBlocks; ++i )
        free(pMem: List.m_Memory.m_pMemory[i]);
      List.m_Memory.m_nBlocks = 0;
      free(pMem: List.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10163200
// Name: public: virtual void Morph3D::SetEmpty(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall Morph3D::SetEmpty(Morph3D *this@<ecx>, int a2@<esi>)
{
  CChoreoChannel *v2; // edi
  Morph3D *v3; // ebx
  CHistory *History; // eax
  CSSolid *v5; // esi
  CHistory *v6; // eax
  CMapClass *v7; // esi
  unsigned int v8; // eax
  int v9; // ecx
  CUtlReference<CMapClass> *m_pHead; // eax
  int m_Size; // edx
  int v12; // eax
  CSSolid **v13; // ecx
  CSSolid *v14; // ebx
  CSSolid *v15; // eax
  SelectionState_t (__thiscall *SetSelectionState)(CMapAtom *, SelectionState_t); // eax
  int v17; // esi
  int m_nAllocationCount; // eax
  CSSolid **m_pMemory; // ecx
  int v20; // eax
  CChoreoChannel **v21; // esi
  CUtlReference<CMapClass> **v22; // edi
  int m_nBlocks; // ebx
  int v24; // esi
  int i; // esi
  Morph3D *v26; // edi
  int v27; // ecx
  int v28; // eax
  CSSolid **v29; // edx
  int v30; // ecx
  int v31; // edi
  int v32; // ebx
  Morph3D *v33; // ecx
  MORPHHANDLE *v34; // edx
  CUtlReference<CMapClass> **v35; // esi
  int v36; // ebx
  int v37; // edi
  int v38; // edi
  CMapClass *m_pMapSolid; // [esp-8h] [ebp-5Ch]
  CUtlReference<CMapClass> **v40; // [esp-8h] [ebp-5Ch]
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > v42; // [esp+8h] [ebp-4Ch] BYREF
  Vector mins; // [esp+1Ch] [ebp-38h] BYREF
  Vector maxs; // [esp+28h] [ebp-2Ch] BYREF
  CUtlReference<CMapClass> src; // [esp+34h] [ebp-20h] BYREF
  void *p; // [esp+40h] [ebp-14h]
  Morph3D *v47; // [esp+44h] [ebp-10h]
  int v48; // [esp+50h] [ebp-4h]

  v2 = nullptr;
  v3 = this;
  v47 = this;
  History = GetHistory();
  CHistory::MarkUndoPosition(this: History, pSelection: nullptr, pszName: "Morphing", bFromOpposite: 0);
  if ( v3->m_StrucSolids.m_Size > 0 )
  {
    while ( 1 )
    {
      v5 = *v3->m_StrucSolids.m_Memory.m_pMemory;
      *((_BYTE *)&v5->m_pMapSolid->CMapClass + 180) |= 1u;
      m_pMapSolid = v5->m_pMapSolid;
      v6 = GetHistory();
      CHistory::Keep(this: v6, pObject: m_pMapSolid);
      *((_BYTE *)&v5->m_pMapSolid->CMapClass + 180) &= ~1u;
      v7 = v5->m_pMapSolid;
      v8 = 15;
      v42.m_Memory.m_pMemory = nullptr;
      v42.m_Memory.m_nBlocks = 0;
      v9 = 16;
      *((_DWORD *)&v42.m_Memory + 2) = 15;
      do
      {
        v9 >>= 1;
        v8 = ((v8 & 0xF8000000) + 0x8000000) ^ v8 & 0x7FFFFFF;
        *((_DWORD *)&v42.m_Memory + 2) = v8;
      }
      while ( v9 > 1 );
      v42.m_Size = 0;
      v42.m_pElements = nullptr;
      v48 = 3;
      src.m_pPrev = nullptr;
      src.m_pNext = nullptr;
      src.m_pObject = v7;
      if ( v7 != nullptr )
      {
        m_pHead = v7->m_References.m_pHead;
        src.m_pNext = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = &src;
        src.m_pPrev = nullptr;
        v7->m_References.m_pHead = &src;
      }
      LOBYTE(v48) = 4;
      CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
        this: &v42,
        elem: 0,
        &src);
      LOBYTE(v48) = 3;
      if ( src.m_pObject != nullptr )
      {
        if ( src.m_pPrev != nullptr )
        {
          src.m_pPrev->m_pNext = src.m_pNext;
          if ( src.m_pNext != nullptr )
            src.m_pNext->m_pPrev = src.m_pPrev;
        }
        else if ( src.m_pObject->m_References.m_pHead == &src )
        {
          src.m_pObject->m_References.m_pHead = src.m_pNext;
          if ( src.m_pNext != nullptr )
            src.m_pNext->m_pPrev = nullptr;
        }
        memset(&src, 0, sizeof(src));
      }
      m_Size = v3->m_StrucSolids.m_Size;
      v12 = 0;
      if ( m_Size <= 0 )
      {
LABEL_23:
        v15 = (CSSolid *)operator new(nSize: 0x15Cu);
        p = v15;
        LOBYTE(v48) = 8;
        if ( v15 != nullptr )
          v2 = (CChoreoChannel *)CSSolid::CSSolid(this: v15);
        LOBYTE(v48) = 3;
        CChoreoChannel::SetActor(this: v2, actor: (CChoreoActor *)v7);
        CSSolid::Convert(this: (CSSolid *)v2, bFromMap: 1, bSkipDisplacementFaces: false);
        CSSolid::ShowHandles(this: (CSSolid *)v2, bShowVertices: v3->m_HandleMode & 1, bShowEdges: v3->m_HandleMode & 2);
        SetSelectionState = v7->SetSelectionState;
        *((_BYTE *)v7 + 180) &= ~1u;
        SetSelectionState(this: v7, a2: SELECT_MORPH);
        v17 = v3->m_StrucSolids.m_Size;
        m_nAllocationCount = v3->m_StrucSolids.m_Memory.m_nAllocationCount;
        if ( v17 + 1 > m_nAllocationCount )
          CUtlMemory<CVisGroup *,int>::Grow(
            this: (CUtlMemory<CCullTreeNode *,int> *)&v3->m_StrucSolids,
            num: v17 - m_nAllocationCount + 1);
        ++v3->m_StrucSolids.m_Size;
        m_pMemory = v3->m_StrucSolids.m_Memory.m_pMemory;
        v20 = v3->m_StrucSolids.m_Size - v17 - 1;
        v3->m_StrucSolids.m_pElements = m_pMemory;
        if ( v20 > 0 )
          _V_memmove(dest: &m_pMemory[v17 + 1], src: &m_pMemory[v17], count: 4 * v20);
        v21 = (CChoreoChannel **)&v3->m_StrucSolids.m_Memory.m_pMemory[v17];
        if ( v21 != nullptr )
          *v21 = v2;
        v48 = 11;
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::RemoveAll(this: &v42);
        v22 = v42.m_Memory.m_pMemory;
        m_nBlocks = v42.m_Memory.m_nBlocks;
        if ( v42.m_Memory.m_pMemory != nullptr )
        {
          v24 = 0;
          if ( v42.m_Memory.m_nBlocks > 0 )
          {
            do
              free(pMem: v22[v24++]);
            while ( v24 < m_nBlocks );
          }
          m_nBlocks = 0;
          v42.m_Memory.m_nBlocks = 0;
          free(pMem: v22);
          v22 = nullptr;
          v42.m_Memory.m_pMemory = nullptr;
        }
        v42.m_pElements = nullptr;
        v48 = -1;
        if ( v22 != nullptr )
        {
          for ( i = 0; i < m_nBlocks; ++i )
            free(pMem: v22[i]);
          v40 = v22;
LABEL_39:
          v42.m_Memory.m_nBlocks = 0;
          free(pMem: v40);
          v42.m_Memory.m_pMemory = nullptr;
        }
      }
      else
      {
        v13 = v3->m_StrucSolids.m_Memory.m_pMemory;
        while ( 1 )
        {
          v14 = *v13;
          p = v14;
          if ( v14->m_pMapSolid == v7 )
            break;
          ++v12;
          ++v13;
          if ( v12 >= m_Size )
          {
            v3 = v47;
            v2 = nullptr;
            goto LABEL_23;
          }
        }
        CMapClass::GetRender2DBox(this: v7, &mins, &maxs);
        v26 = v47;
        BoundBox::UpdateBounds(this: &v47->m_MorphBounds, &mins, &maxs);
        CSSolid::Convert(this: v14, bFromMap: 0, bSkipDisplacementFaces: false);
        CMapClass::GetRender2DBox(this: v7, &mins, &maxs);
        BoundBox::UpdateBounds(this: &v26->m_MorphBounds, &mins, &maxs);
        CSSolid::Detach(this: v14);
        ((void (__thiscall *)(CMapDoc *, int, int))v26->m_pDocument->SetModifiedFlag)(
          a1: v26->m_pDocument,
          a2: 1,
          a3: a2);
        *((_BYTE *)v7 + 180) |= 1u;
        v27 = v26->m_StrucSolids.m_Size;
        v28 = 0;
        if ( v27 > 0 )
        {
          v29 = v26->m_StrucSolids.m_Memory.m_pMemory;
          while ( *v29 != v14 )
          {
            ++v28;
            ++v29;
            if ( v28 >= v27 )
              goto LABEL_51;
          }
          if ( v28 != -1 )
          {
            v30 = v27 - v28 - 1;
            if ( v30 > 0 )
              _V_memmove(
                dest: &v26->m_StrucSolids.m_Memory.m_pMemory[v28],
                src: &v26->m_StrucSolids.m_Memory.m_pMemory[v28 + 1],
                count: 4 * v30);
            --v26->m_StrucSolids.m_Size;
          }
        }
LABEL_51:
        v31 = v26->m_SelectedHandles.m_Size - 1;
        if ( v31 >= 0 )
        {
          v32 = v31;
          do
          {
            v33 = v47;
            v34 = v47->m_SelectedHandles.m_Memory.m_pMemory;
            if ( v34[v32].pStrucSolid == p )
            {
              if ( v47->m_SelectedHandles.m_Size - v31 - 1 > 0 )
              {
                _V_memmove(dest: &v34[v32], src: &v34[v32 + 1], count: 12 * (v47->m_SelectedHandles.m_Size - v31 - 1));
                v33 = v47;
              }
              --v33->m_SelectedHandles.m_Size;
            }
            --v32;
            --v31;
          }
          while ( v31 >= 0 );
          v14 = (CSSolid *)p;
        }
        if ( v14 != nullptr )
        {
          CSSolid::~CSSolid(this: v14);
          operator delete(p: v14);
        }
        a2 = 0;
        ((void (__thiscall *)(CMapClass *))v7->SetSelectionState)(a1: v7);
        v48 = 7;
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::RemoveAll(this: &v42);
        v35 = v42.m_Memory.m_pMemory;
        v36 = v42.m_Memory.m_nBlocks;
        if ( v42.m_Memory.m_pMemory != nullptr )
        {
          v37 = 0;
          if ( v42.m_Memory.m_nBlocks > 0 )
          {
            do
              free(pMem: v35[v37++]);
            while ( v37 < v36 );
          }
          v36 = 0;
          v42.m_Memory.m_nBlocks = 0;
          free(pMem: v35);
          v35 = nullptr;
          v42.m_Memory.m_pMemory = nullptr;
        }
        v38 = 0;
        v42.m_pElements = nullptr;
        v48 = -1;
        if ( v35 != nullptr )
        {
          if ( v36 > 0 )
          {
            do
              free(pMem: v35[v38++]);
            while ( v38 < v36 );
          }
          v40 = v35;
          goto LABEL_39;
        }
      }
      if ( v47->m_StrucSolids.m_Size <= 0 )
        return;
      v3 = v47;
      v2 = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101636B0
// Name: public: bool Morph3D::SelectAt(class CMapView __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Morph3D::SelectAt(Morph3D *this, CMapView *pView, char nFlags, const Vector2D *vPoint)
{
  Morph3D *v4; // esi
  CSelection *m_pSelection; // ecx
  int v6; // edi
  int v8; // eax
  CMapClass **v9; // esi
  CMapClass *v10; // eax
  CUtlReference<CMapClass> *m_pHead; // ecx
  CMapDoc *v12; // eax
  CMapDoc *v13; // eax
  int k; // esi
  CMapClass *ParentWnd; // ebx
  CMapSolid *m_pObject; // esi
  CMapClass *v18; // eax
  CMainFrame *MainWnd; // eax
  int j; // esi
  char v21; // al
  _BYTE v22[38912]; // [esp+Ch] [ebp-9830h] BYREF
  Morph3D *v23; // [esp+980Ch] [ebp-30h]
  CUtlReference<CMapClass> src; // [esp+9810h] [ebp-2Ch] BYREF
  CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int> > v25; // [esp+981Ch] [ebp-20h] BYREF
  int v26; // [esp+9838h] [ebp-4h]
  int i; // [esp+9844h] [ebp+8h]
  char v28; // [esp+9847h] [ebp+Bh]

  v4 = this;
  m_pSelection = this->m_pDocument->m_pSelection;
  v23 = v4;
  CSelection::ClearHitList(this: m_pSelection);
  v6 = 0;
  memset(&v25, 0, 12);
  CUtlBlockMemory<CUtlReference<CMapEntity>,int>::Init(this: &v25.m_Memory, nGrowSize: 0, nInitSize: 0);
  v25.m_Size = 0;
  v25.m_pElements = nullptr;
  v26 = 3;
  v8 = pView->ObjectsAt(this: pView, a2: vPoint, a3: (HitInfo_s *)v22, a4: 512, a5: 0);
  if ( v8 > 0 )
  {
    v9 = (CMapClass **)v22;
    for ( i = v8; i != 0; --i )
    {
      v10 = *v9;
      if ( *v9 != nullptr )
      {
        m_pHead = v10->m_References.m_pHead;
        src.m_pPrev = nullptr;
        src.m_pObject = v10;
        src.m_pNext = m_pHead;
        if ( m_pHead != nullptr )
          m_pHead->m_pPrev = &src;
        src.m_pPrev = nullptr;
        v10->m_References.m_pHead = &src;
        LOBYTE(v26) = 4;
        CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::InsertBefore(
          this: &v25,
          elem: v25.m_Size,
          &src);
        LOBYTE(v26) = 3;
        if ( src.m_pObject != nullptr )
        {
          if ( src.m_pPrev != nullptr )
          {
            src.m_pPrev->m_pNext = src.m_pNext;
            if ( src.m_pNext != nullptr )
              src.m_pNext->m_pPrev = src.m_pPrev;
          }
          else if ( src.m_pObject->m_References.m_pHead == &src )
          {
            src.m_pObject->m_References.m_pHead = src.m_pNext;
            if ( src.m_pNext != nullptr )
              src.m_pNext->m_pPrev = nullptr;
          }
          memset(&src, 0, sizeof(src));
        }
      }
      v9 += 19;
    }
    v4 = v23;
  }
  if ( v25.m_Size != 0 )
  {
    v28 = 1;
    ParentWnd = CVGuiWnd::GetParentWnd(this: (CMapClass *)v4->m_pDocument->m_pSelection);
    if ( Morph3D::CanDeselectList(this: v4) != 0 )
    {
      if ( v25.m_Size > 0 )
      {
        while ( 1 )
        {
          m_pObject = (CMapSolid *)v25.m_Memory.m_pMemory[v6 >> ((unsigned __int64)*((int *)&v25.m_Memory + 2) >> 27)][v6 & ((32 * *((_DWORD *)&v25.m_Memory + 2)) >> 5)].m_pObject;
          v18 = m_pObject->PrepareSelection(this: m_pObject, a2: (SelectMode_t)ParentWnd);
          if ( v18 != nullptr )
          {
            CSelection::AddHit(this: v23->m_pDocument->m_pSelection, pObject: v18);
            if ( v28 != 0 && m_pObject->IsMapClass(this: m_pObject, a2: CMapSolid::__Type) != 0 )
            {
              v21 = 18;
              if ( (nFlags & 8) != 0 )
                v21 = 1;
              Morph3D::SelectObject(this: v23, pSolid: m_pObject, cmd: v21);
              v4 = v23;
LABEL_33:
              MainWnd = GetMainWnd();
              CObjectProperties::MarkDataDirty(this: MainWnd->pObjectProperties);
              CMapDoc::UpdateAllViews(this: v4->m_pDocument, nFlags: 8, ub: nullptr);
              goto LABEL_34;
            }
            v28 = 0;
          }
          if ( ++v6 >= v25.m_Size )
          {
            v4 = v23;
            break;
          }
        }
      }
      if ( !v4->IsEmpty(this: v4) )
      {
        v4->SetEmpty(this: v4);
        goto LABEL_33;
      }
LABEL_34:
      v26 = 12;
      CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::RemoveAll(this: &v25);
      if ( v25.m_Memory.m_pMemory != nullptr )
      {
        for ( j = 0; j < v25.m_Memory.m_nBlocks; ++j )
          free(pMem: v25.m_Memory.m_pMemory[j]);
        v25.m_Memory.m_nBlocks = 0;
        free(pMem: v25.m_Memory.m_pMemory);
        v25.m_Memory.m_pMemory = nullptr;
      }
      v25.m_pElements = nullptr;
      v26 = -1;
    }
    else
    {
      v26 = -1;
      CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::~CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>(this: &v25);
    }
    return 1;
  }
  else
  {
    v12 = pView->GetMapDoc(this: pView);
    CMapDoc::SelectFace(this: v12, pSolid: 0, cmd: 16);
    v13 = pView->GetMapDoc(this: pView);
    CMapDoc::SelectObject(this: v13, pObj: nullptr, cmd: 16);
    v26 = 7;
    CUtlVector<CUtlReference<CMapClass>,CUtlBlockMemory<CUtlReference<CMapClass>,int>>::RemoveAll(this: &v25);
    if ( v25.m_Memory.m_pMemory != nullptr )
    {
      for ( k = 0; k < v25.m_Memory.m_nBlocks; ++k )
        free(pMem: v25.m_Memory.m_pMemory[k]);
      v25.m_Memory.m_nBlocks = 0;
      free(pMem: v25.m_Memory.m_pMemory);
      v25.m_Memory.m_pMemory = nullptr;
    }
    v25.m_pElements = nullptr;
    v26 = -1;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10163A40
// Name: AddToMorph
// Source: json
//------------------------------------------------------------------------------
int __cdecl AddToMorph(CMapSolid *pSolid, Morph3D *pMorph)
{
  Morph3D::SelectObject(this: pMorph, pSolid, cmd: 2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10163A60
// Name: public: virtual void Morph3D::OnActivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Morph3D::OnActivate(Morph3D *this)
{
  Morph3D *v1; // ebx
  bool m_bActiveTool; // al
  const CUtlReferenceVector<CMapClass> *List; // edi
  int v4; // esi
  CMapClass *m_pObject; // eax
  CUtlReference<CMapClass> *v6; // ecx
  CMapSolid *v7; // ebx
  CUtlReference<CMapClass> *m_pHead; // [esp+4h] [ebp-1Ch] BYREF
  CUtlReference<CMapClass> *v9; // [esp+8h] [ebp-18h]
  CMapSolid *pSolid; // [esp+Ch] [ebp-14h]
  Morph3D *v11; // [esp+10h] [ebp-10h]
  int v12; // [esp+1Ch] [ebp-4h]

  v1 = this;
  m_bActiveTool = this->m_bActiveTool;
  v11 = this;
  if ( m_bActiveTool )
  {
    Morph3D::ToggleMode(this);
  }
  else
  {
    List = CSelection::GetList(this: this->m_pDocument->m_pSelection);
    v4 = 0;
    if ( List->m_Size > 0 )
    {
      do
      {
        m_pObject = List->m_Memory.m_pMemory[v4 >> ((unsigned __int64)*((int *)&List->m_Memory + 2) >> 27)][v4 & ((32 * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
        if ( m_pObject != nullptr )
        {
          pSolid = (CMapSolid *)List->m_Memory.m_pMemory[v4 >> ((unsigned __int64)*((int *)&List->m_Memory + 2) >> 27)][v4 & ((32 * *((_DWORD *)&List->m_Memory + 2)) >> 5)].m_pObject;
          m_pHead = m_pObject->m_References.m_pHead;
          v6 = m_pObject->m_References.m_pHead;
          if ( v6 != nullptr )
            v6->m_pPrev = (CUtlReference<CMapClass> *)&m_pHead;
          v9 = nullptr;
          m_pObject->m_References.m_pHead = (CUtlReference<CMapClass> *)&m_pHead;
        }
        v7 = pSolid;
        v12 = -1;
        if ( pSolid != nullptr )
        {
          if ( v9 != nullptr )
          {
            v9->m_pNext = m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = v9;
          }
          else if ( (CUtlReference<CMapClass> **)pSolid->m_References.m_pHead == &m_pHead )
          {
            pSolid->m_References.m_pHead = m_pHead;
            if ( m_pHead != nullptr )
              m_pHead->m_pPrev = nullptr;
          }
          v9 = nullptr;
          m_pHead = nullptr;
          pSolid = nullptr;
        }
        if ( v7->IsMapClass(this: v7, a2: CMapSolid::__Type) != 0 )
          Morph3D::SelectObject(this: v11, pSolid: v7, cmd: 2);
        CMapClass::EnumChildren(
          this: v7,
          pfn: (int (__cdecl *)(CMapClass *, unsigned int))AddToMorph,
          dwParam: (unsigned int)v11,
          Type: CMapSolid::__Type);
        ++v4;
      }
      while ( v4 < List->m_Size );
      v1 = v11;
    }
    CMapDoc::SelectObject(this: v1->m_pDocument, pObj: nullptr, cmd: 1040);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10163BC0
// Name: public: virtual bool Morph3D::OnLMouseDown2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Morph3D::OnLMouseDown2D(Morph3D *this, CMapView2D *pView, unsigned int nFlags, const Vector2D *vPoint)
{
  CMapView *v5; // eax
  CMapView *v6; // ebx
  bool v8; // zf
  CMapView *v9; // eax
  MORPHHANDLE mh; // [esp+Ch] [ebp-Ch] BYREF

  Tool3D::OnLMouseDown2D(this, pView, nFlags, vPoint);
  this->m_bLButtonDownControlState = (nFlags & 8) != 0;
  this->m_vLastMouseMovement = *vPoint;
  v5 = nullptr;
  this->m_DragHandle.ssh = 0;
  if ( !this->m_bBoxSelecting )
  {
    if ( pView != nullptr )
      v5 = &pView->CMapView;
    if ( Morph3D::MorphHitTest(this, pView: v5, vPoint, pInfo: &mh) != 0 )
    {
      v8 = !this->m_bLButtonDownControlState;
      this->m_DragHandle = mh;
      if ( v8 && Morph3D::IsSelected(this, mh: &this->m_DragHandle) == 0 )
      {
        Morph3D::SelectHandle2D(this, pView, pInfo: &this->m_DragHandle, cmd: 0x12u);
        return 1;
      }
    }
    else
    {
      if ( pView != nullptr )
        v9 = &pView->CMapView;
      else
        v9 = nullptr;
      Morph3D::SelectAt(this, pView: v9, nFlags, vPoint);
    }
    return 1;
  }
  if ( pView != nullptr )
    v5 = &pView->CMapView;
  if ( this->HitTest(this, a2: v5, a3: vPoint, a4: true) == 0 )
    return 1;
  if ( pView != nullptr )
    v6 = &pView->CMapView;
  else
    v6 = nullptr;
  Box3D::StartTranslation(
    this,
    a2: (int)vPoint,
    a3: (int)this,
    pView: v6,
    vPoint,
    vHandleOrigin: &this->m_LastHitTestHandle,
    pRefPoint: nullptr,
    pCustomHandleBox: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10163CD0
// Name: public: virtual bool Morph3D::OnLMouseDown3D(class CMapView3D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Morph3D::OnLMouseDown3D(Morph3D *this, CMapView3D *pView, unsigned int nFlags, const Vector2D *vPoint)
{
  CMapView *v5; // eax
  unsigned int ssh; // edx
  CMapView *v7; // ecx
  HCURSOR CursorA; // eax
  CMapView *v10; // eax
  MORPHHANDLE mh; // [esp+Ch] [ebp-Ch] BYREF

  this->m_bHit = false;
  Tool3D::OnLMouseDown3D(this, pView, nFlags, vPoint);
  if ( pView != nullptr )
    v5 = &pView->CMapView;
  else
    v5 = nullptr;
  if ( Morph3D::MorphHitTest(this, pView: v5, vPoint, pInfo: &mh) != 0 )
  {
    ssh = mh.ssh;
    *(_QWORD *)&this->m_DragHandle.pMapSolid = *(_QWORD *)&mh.pMapSolid;
    this->m_bHit = true;
    this->m_DragHandle.ssh = ssh;
    this->m_bMorphing = true;
    this->m_vLastMouseMovement = *vPoint;
    this->m_bMovingSelected = false;
    if ( pView != nullptr )
      v7 = &pView->CMapView;
    else
      v7 = nullptr;
    Morph3D::StartTranslation(this, pView: v7, vPoint, pInfo: &this->m_DragHandle);
    AfxGetModuleState();
    CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F03);
    SetCursor(hCursor: CursorA);
    return 1;
  }
  else
  {
    if ( pView != nullptr )
      v10 = &pView->CMapView;
    else
      v10 = nullptr;
    Morph3D::SelectAt(this, pView: v10, nFlags, vPoint);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1028BF10
// Name: public: virtual enum ToolID_t Morph3D::GetToolID(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall Morph3D::GetToolID(CParticleOperatorDefinition<C_OP_ModelCull> *this)
{
  return 6;
}
