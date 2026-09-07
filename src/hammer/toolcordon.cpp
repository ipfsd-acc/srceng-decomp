// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/toolcordon.cpp
// Functions: 9
// ============================================================

#include "hammer\toolcordon.h"

//------------------------------------------------------------------------------
// Address: 0x1015A790
// Name: public: virtual void Cordon3D::OnActivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Cordon3D::OnActivate(Cordon3D *this)
{
  this->RefreshToolState(this);
}

//------------------------------------------------------------------------------
// Address: 0x1015A7A0
// Name: public: virtual bool Cordon3D::OnLMouseUp2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Cordon3D::OnLMouseUp2D(Cordon3D *this, CMapView2D *pView, unsigned int nFlags, const Vector2D *vPoint)
{
  Vector *p_bmaxs; // edi
  CMapDoc *m_pDocument; // ecx
  BoundBox *SelectedCordonForEditing; // edi
  BoundBox *v8; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  p_bmaxs = (Vector *)nFlags;
  Tool3D::OnLMouseUp3D(this, (CMapView3D *)pView, nFlags, vPoint);
  if ( this->IsTranslating(this) )
  {
    this->FinishTranslation(this, a2: true);
    m_pDocument = this->m_pDocument;
    if ( (nFlags & 4) != 0 )
    {
      SelectedCordonForEditing = (BoundBox *)CMapDoc::Cordon_GetSelectedCordonForEditing(
                                               this: m_pDocument,
                                               ppBox: nullptr);
      v8 = CMapDoc::Cordon_AddBox(this: this->m_pDocument, cordon: SelectedCordonForEditing);
      v8->bmins = this->bmins;
      v8->bmaxs = this->bmaxs;
      CMapDoc::Cordon_SelectCordonForEditing(
        this: this->m_pDocument,
        cordon: (Cordon_t *)SelectedCordonForEditing,
        box: v8,
        nFlags: 1);
      this->RefreshToolState(this);
      CMapDoc::UpdateStatusbar(
        this: this->m_pDocument,
        a2: COERCE_FLOAT(&savedregs),
        a3: (int)SelectedCordonForEditing,
        a4: (int)this);
      return 1;
    }
    p_bmaxs = &this->bmaxs;
    CMapDoc::Cordon_SetEditCordon(this: m_pDocument, mins: &this->bmins, maxs: &this->bmaxs);
    Cordon3D::m_vecLastMins = this->bmins;
    Cordon3D::m_vecLastMaxs = this->bmaxs;
  }
  CMapDoc::UpdateStatusbar(this: this->m_pDocument, a2: COERCE_FLOAT(&savedregs), a3: (int)p_bmaxs, a4: (int)this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015A8C0
// Name: public: virtual bool Cordon3D::OnMouseMove2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall Cordon3D::OnMouseMove2D(Cordon3D *this, CMapView2D *pView, __int64 nFlags)
{
  unsigned int updated; // eax
  char string[32]; // [esp+18h] [ebp-94h] BYREF
  __int128 szBuf_100; // [esp+9Ch] [ebp-10h] OVERLAPPED BYREF

  HIDWORD(szBuf_100) = 2;
  Tool3D::OnMouseMove2D(this, pView, nFlags, vPoint: (const Vector2D *)HIDWORD(nFlags));
  LODWORD(nFlags) = this->GetConstraints(this, a2: nFlags);
  pView->ClientToWorld(this: &pView->CMapView, a2: (Vector *)&szBuf_100, a3: (const Vector2D *)HIDWORD(nFlags));
  CMapDoc::Snap(this: this->m_pDocument, pt: (Vector *)&szBuf_100, nFlags);
  sprintf(
    string: &string[4],
    format: " @%.0f, %.0f ",
    *((float *)&szBuf_100 + pView->axHorz),
    *((float *)&szBuf_100 + pView->axVert));
  SetStatusText(nIndex: 2, pszText: &string[4]);
  if ( this->IsTranslating(this) )
  {
    Tool3D::UpdateTranslation(this, pView: &pView->CMapView, vPoint: (const Vector2D *)HIDWORD(nFlags), nFlags);
    return 1;
  }
  if ( this->HitTest(this, a2: &pView->CMapView, a3: (const Vector2D *)HIDWORD(nFlags), a4: true) == 0 )
  {
    updated = HIDWORD(szBuf_100);
LABEL_7:
    CVGuiWnd::SetCursor(this: &pView->CVGuiWnd, cursor: updated);
    return 1;
  }
  updated = Box3D::UpdateCursor(
              this,
              pView: &pView->CMapView,
              vHandleHit: &this->m_LastHitTestHandle,
              eTransformMode: this->m_TranslateMode);
  if ( updated != 1 )
    goto LABEL_7;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015A9E0
// Name: public: virtual void Cordon3D::RefreshToolState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Cordon3D::RefreshToolState(Cordon3D *this)
{
  float v1; // xmm0_4
  CMapDoc *m_pDocument; // ecx
  float x; // xmm1_4
  float y; // xmm2_4
  float z; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  Vector maxs; // [esp+0h] [ebp-18h] BYREF
  Vector mins; // [esp+Ch] [ebp-Ch] BYREF

  v1 = 99999.0;
  m_pDocument = this->m_pDocument;
  x = 99999.0;
  y = 99999.0;
  z = 99999.0;
  v7 = 99999.0;
  v8 = 99999.0;
  mins.x = 99999.0;
  mins.y = 99999.0;
  mins.z = 99999.0;
  maxs.x = 99999.0;
  maxs.y = 99999.0;
  maxs.z = 99999.0;
  if ( m_pDocument->m_Cordons.m_Size > 0 )
  {
    CMapDoc::Cordon_GetEditCordon(this: m_pDocument, &mins, &maxs);
    x = mins.x;
    y = mins.y;
    z = mins.z;
    v7 = maxs.x;
    v8 = maxs.y;
    v1 = maxs.z;
    Cordon3D::m_vecLastMins = mins;
    Cordon3D::m_vecLastMaxs = maxs;
  }
  this->bmins.x = x;
  this->bmins.y = y;
  this->bmins.z = z;
  this->bmaxs.x = v7;
  this->bmaxs.y = v8;
  this->bmaxs.z = v1;
  this->m_bEmpty = !BoundBox::IsValidBox(this: &this->BoundBox);
  Box3D::EnableHandles(this, bEnable: true);
}

//------------------------------------------------------------------------------
// Address: 0x1015AAD0
// Name: private: void Cordon3D::OnDelete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Cordon3D::OnDelete(Cordon3D *this)
{
  CMapDoc *m_pDocument; // ecx
  Cordon_t *SelectedCordonForEditing; // eax
  BoundBox *pBox; // [esp+4h] [ebp-4h] BYREF

  m_pDocument = this->m_pDocument;
  pBox = nullptr;
  SelectedCordonForEditing = CMapDoc::Cordon_GetSelectedCordonForEditing(this: m_pDocument, ppBox: &pBox);
  if ( SelectedCordonForEditing != nullptr && pBox != nullptr )
  {
    if ( SelectedCordonForEditing->m_Boxes.m_Size <= 1 )
      CMapDoc::Cordon_RemoveCordon(this: this->m_pDocument, cordon: SelectedCordonForEditing);
    else
      CMapDoc::Cordon_RemoveBox(this: this->m_pDocument, cordon: SelectedCordonForEditing, box: pBox);
    CMapDoc::UpdateVisibilityAll(this: this->m_pDocument);
    this->m_pDocument->SetModifiedFlag(this: this->m_pDocument, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015AB30
// Name: public: virtual bool Cordon3D::OnKeyDown2D(class CMapView2D __near *,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Cordon3D::OnKeyDown2D(
        Cordon3D *this,
        CMapView3D *pView,
        unsigned int nChar,
        unsigned int nRepCnt,
        unsigned int nFlags)
{
  if ( nChar == 27 )
  {
    if ( this->IsTranslating(this) )
      this->FinishTranslation(this, a2: false);
    else
      CToolManager::SetTool(this: this->m_pDocument->m_pToolManager, eNewTool: TOOL_POINTER);
    return 1;
  }
  else
  {
    if ( nChar == 46 )
      Cordon3D::OnDelete(this);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015AB90
// Name: public: Cordon3D::Cordon3D(void)
// Source: json
//------------------------------------------------------------------------------
Cordon3D *__thiscall Cordon3D::Cordon3D(Cordon3D *this)
{
  Box3D::Box3D(this);
  this->Box3D::Tool3D::CBaseTool::__vftable = (Cordon3D_vtbl *)&Cordon3D::`vftable'{for `Tool3D'};
  this->Box3D::BoundBox::__vftable = (BoundBox_vtbl *)&Cordon3D::`vftable'{for `BoundBox'};
  Box3D::SetDrawColors(this, dwHandleColor: 0xFFFF00u, dwBoxColor: 0xFFu);
  Cordon3D::m_vecLastMins.x = 99999.0;
  Cordon3D::m_vecLastMins.y = 99999.0;
  Cordon3D::m_vecLastMins.z = 99999.0;
  Cordon3D::m_vecLastMaxs.x = 99999.0;
  Cordon3D::m_vecLastMaxs.y = 99999.0;
  Cordon3D::m_vecLastMaxs.z = 99999.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1015AC80
// Name: public: virtual bool Cordon3D::OnLMouseDown2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall Cordon3D::OnLMouseDown2D(Cordon3D *this, CMapView2D *pView, BoundBox *nFlags, Cordon_t *vPoint)
{
  const Vector2D *v4; // edi
  Cordon3D *v5; // esi
  CMapView *v6; // ebx
  CMapDoc *v8; // eax
  float x; // xmm0_4
  float v10; // xmm1_4
  Cordon_t *v11; // edi
  BoundBox *v12; // esi
  Vector2D *SelectedCordonForEditing; // eax
  CMapDoc *m_pDocument; // ecx
  BoundBox *v15; // eax
  double v16; // st7
  BoundBox *v17; // ecx
  float v18; // xmm1_4
  int v19; // ecx
  int m_nGridSpacing; // eax
  CMapDoc *v21; // esi
  Vector vecSize; // [esp+Ch] [ebp-54h] BYREF
  Vector vecWorld; // [esp+18h] [ebp-48h] BYREF
  Vector2D selMins; // [esp+24h] [ebp-3Ch]
  Vector2D vecClientMaxs; // [esp+2Ch] [ebp-34h] BYREF
  Vector2D vecClientMins; // [esp+34h] [ebp-2Ch] BYREF
  Vector2D selMaxs; // [esp+3Ch] [ebp-24h]
  unsigned int uConstraints; // [esp+44h] [ebp-1Ch]
  Cordon3D *v29; // [esp+48h] [ebp-18h]
  int i; // [esp+4Ch] [ebp-14h]
  int j; // [esp+50h] [ebp-10h]
  unsigned int v32; // [esp+54h] [ebp-Ch]
  unsigned int v33; // [esp+58h] [ebp-8h]
  CMapDoc *pDoc; // [esp+5Ch] [ebp-4h]

  v4 = (const Vector2D *)vPoint;
  v5 = this;
  v29 = this;
  Tool3D::OnLMouseDown2D(this, pView, (unsigned int)nFlags, (const Vector2D *)vPoint);
  v6 = &pView->CMapView;
  pView->ClientToWorld(this: &pView->CMapView, a2: &vecWorld, a3: v4);
  uConstraints = v5->GetConstraints(this: v5, a2: (unsigned int)nFlags);
  if ( v5->HitTest(this: v5, a2: &pView->CMapView, a3: v4, a4: true) != 0 )
  {
    v5->StartTranslation(this: v5, a2: v6, a3: v4, a4: &v5->m_LastHitTestHandle, a5: nullptr, a6: nullptr);
    return 1;
  }
  v8 = v6->GetMapDoc(this: v6);
  pDoc = v8;
  if ( v8 == nullptr )
    return 1;
  x = v4->x;
  selMins.x = v4->x - 2.0;
  v10 = v4->y + 2.0;
  selMins.y = v4->y - 2.0;
  selMaxs.x = x + 2.0;
  selMaxs.y = v10;
  i = 0;
  if ( v8->m_Cordons.m_Size <= 0 )
  {
LABEL_19:
    *(&vecWorld.x + pView->axThird) = *(&Cordon3D::m_vecLastMins.x + pView->axThird);
    CMapDoc::GetBestVisiblePoint(this: v5->m_pDocument, ptOrg: &vecWorld);
    if ( (uConstraints & 4) != 0 )
      CMapDoc::Snap(this: v5->m_pDocument, pt: &vecWorld, nFlags: uConstraints);
    SelectedCordonForEditing = (Vector2D *)CMapDoc::Cordon_GetSelectedCordonForEditing(
                                             this: v5->m_pDocument,
                                             ppBox: nullptr);
    m_pDocument = v5->m_pDocument;
    vPoint = (Cordon_t *)SelectedCordonForEditing;
    nFlags = nullptr;
    if ( SelectedCordonForEditing != nullptr )
      nFlags = CMapDoc::Cordon_AddBox(this: m_pDocument, cordon: (BoundBox *)SelectedCordonForEditing);
    else
      vPoint = CMapDoc::Cordon_CreateNewCordon(this: m_pDocument, name: "cordon", ppBox: &nFlags);
    v15 = nFlags;
    nFlags->bmaxs.x = vecWorld.x;
    v16 = v15->bmaxs.x;
    v15->bmaxs.y = vecWorld.y;
    v15->bmaxs.z = vecWorld.z;
    v17 = nFlags;
    nFlags->bmins.x = v16;
    v17->bmins.y = v15->bmaxs.y;
    v17->bmins.z = v15->bmaxs.z;
    v18 = *(&Cordon3D::m_vecLastMins.x + pView->axThird);
    v19 = 4 * pView->axThird;
    memset(&vecSize, 0, sizeof(vecSize));
    if ( v18 == 99999.0 || *(float *)((char *)&Cordon3D::m_vecLastMaxs.x + v19) == 99999.0 )
    {
      m_nGridSpacing = pDoc->m_nGridSpacing;
      if ( m_nGridSpacing <= 1 )
        m_nGridSpacing = 1;
      *(float *)((char *)&vecSize.x + v19) = (float)m_nGridSpacing;
    }
    else
    {
      *(&vecSize.x + pView->axThird) = *(&Cordon3D::m_vecLastMaxs.x + pView->axThird)
                                     - *(&Cordon3D::m_vecLastMins.x + pView->axThird);
    }
    Box3D::StartNew(this: v5, pView: v6, vPoint: v4, vecStart: &vecWorld, &vecSize);
    CMapDoc::Cordon_SelectCordonForEditing(this: v5->m_pDocument, cordon: vPoint, box: nFlags, nFlags: 1);
    v21 = pDoc;
    if ( pDoc->m_bIsCordoning )
      CMapDoc::UpdateVisibilityAll(this: pDoc);
    v21->SetModifiedFlag(this: v21, a2: 1);
    return 1;
  }
  v32 = 0;
  while ( 1 )
  {
    v11 = &v8->m_Cordons.m_Memory.m_pMemory[v32 / 0x28];
    if ( v11->m_bActive )
    {
      j = 0;
      if ( v11->m_Boxes.m_Size > 0 )
        break;
    }
LABEL_15:
    v32 += 40;
    if ( ++i >= pDoc->m_Cordons.m_Size )
    {
      v4 = (const Vector2D *)vPoint;
      goto LABEL_19;
    }
    v8 = pDoc;
  }
  v33 = 0;
  while ( 1 )
  {
    v12 = &v11->m_Boxes.m_Memory.m_pMemory[v33 / 0x1C];
    v6->WorldToClient(this: v6, a2: &vecClientMins, a3: &v12->bmins);
    v6->WorldToClient(this: v6, a2: &vecClientMaxs, a3: &v12->bmaxs);
    NormalizeBox(mins: &vecClientMins, maxs: &vecClientMaxs);
    if ( selMaxs.x > vecClientMins.x
      && vecClientMaxs.x > selMins.x
      && selMaxs.y > vecClientMins.y
      && vecClientMaxs.y > selMins.y )
    {
      break;
    }
    v33 += 28;
    if ( ++j >= v11->m_Boxes.m_Size )
    {
      v5 = v29;
      goto LABEL_15;
    }
  }
  CMapDoc::Cordon_SelectCordonForEditing(this: pDoc, cordon: v11, box: v12, nFlags: 1);
  v29->RefreshToolState(this: v29);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015AFC0
// Name: public: virtual void Cordon3D::RenderTool2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Cordon3D::RenderTool2D(Cordon3D *this, CRender2D *pRender)
{
  CRender2D *v2; // esi
  Cordon3D *v3; // ebx
  CMapDoc *m_pDocument; // eax
  int m_Size; // eax
  Cordon_t *v6; // esi
  int v7; // edi
  int v8; // ebx
  int i; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]

  v2 = pRender;
  v3 = this;
  CRender::PushRenderMode(this: pRender, eRenderMode: RENDER_MODE_DOTTED);
  CRender::SetDrawColor(this: pRender, r: 0xFFu, g: 0xFFu, b: 0);
  m_pDocument = v3->m_pDocument;
  if ( !m_pDocument->m_bIsCordoning )
  {
    m_Size = m_pDocument->m_Cordons.m_Size;
    if ( m_Size > 0 )
    {
      v11 = 0;
      for ( i = m_Size; i != 0; --i )
      {
        v6 = &v3->m_pDocument->m_Cordons.m_Memory.m_pMemory[v11];
        if ( v6->m_bActive )
        {
          v7 = 0;
          if ( v6->m_Boxes.m_Size > 0 )
          {
            v8 = 0;
            do
            {
              CRender2D::DrawRectangle(
                this: pRender,
                vMins: &v6->m_Boxes.m_Memory.m_pMemory[v8].bmins,
                vMaxs: &v6->m_Boxes.m_Memory.m_pMemory[v8].bmaxs,
                bFill: false,
                extent: 0);
              ++v7;
              ++v8;
            }
            while ( v7 < v6->m_Boxes.m_Size );
            v3 = this;
          }
        }
        ++v11;
      }
      v2 = pRender;
    }
  }
  CRender::PopRenderMode(this: v2);
  Box3D::RenderTool2D(this: v3, pRender: v2);
}
