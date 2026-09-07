// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/toolaxishandle.cpp
// Functions: 6
// ============================================================

#include "hammer\toolaxishandle.h"

//------------------------------------------------------------------------------
// Address: 0x101574F0
// Name: public: CToolAxisHandle::CToolAxisHandle(void)
// Source: json
//------------------------------------------------------------------------------
CToolAxisHandle *__thiscall CToolAxisHandle::CToolAxisHandle(CToolAxisHandle *this)
{
  this->__vftable = (CToolAxisHandle_vtbl *)&CBaseTool::`vftable';
  *(_WORD *)&this->m_bActiveTool = 256;
  this->m_pDocument = nullptr;
  this->__vftable = (CToolAxisHandle_vtbl *)&CToolAxisHandle::`vftable';
  this->m_pAxis = nullptr;
  this->m_nPointIndex = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10157550
// Name: public: virtual bool CToolAxisHandle::OnMouseMove2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolAxisHandle::OnMouseMove2D(
        CToolAxisHandle *this,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  CMapDoc *v6; // edi
  CMapPointHandle *v7; // ecx
  int m_nPointIndex; // eax
  int axVert; // ebx
  CMapPointHandle *v10; // ecx
  char string[40]; // [esp+24h] [ebp-A4h] BYREF
  char szBuf[128]; // [esp+4Ch] [ebp-7Ch] BYREF

  CMapView2DBase::ToolScrollToPoint(this: pView, ptClient: vPoint);
  pView->ClientToWorld(this: &pView->CMapView, a2: (Vector *)&szBuf[88], a3: vPoint);
  v6 = pView->GetMapDoc(this: &pView->CMapView);
  CMapDoc::Snap(this: v6, pt: (Vector *)&szBuf[88], nFlags: 16);
  v7 = &this->m_pAxis->m_Point[this->m_nPointIndex];
  v7->GetOrigin(this: v7, a2: (Vector *)&szBuf[12 * this->m_nPointIndex + 100]);
  m_nPointIndex = this->m_nPointIndex;
  axVert = pView->axVert;
  *(float *)&szBuf[12 * m_nPointIndex + 100 + 4 * pView->axHorz] = *(float *)&szBuf[4 * pView->axHorz + 88];
  *(float *)&szBuf[12 * m_nPointIndex + 100 + 4 * axVert] = *(float *)&szBuf[4 * axVert + 88];
  CMapAxisHandle::UpdateEndPoint(
    this: this->m_pAxis,
    vecPos: (Vector *)&szBuf[12 * m_nPointIndex + 100],
    nPointIndex: m_nPointIndex);
  v10 = &this->m_pAxis->m_Point[this->m_nPointIndex == 0];
  v10->GetOrigin(this: v10, a2: (Vector *)&szBuf[12 * (this->m_nPointIndex == 0) + 100]);
  sprintf(
    string,
    format: " (%.0f %.0f %0.f) ",
    *(float *)&szBuf[12 * this->m_nPointIndex + 100],
    *(float *)&szBuf[12 * this->m_nPointIndex + 104],
    *(float *)&szBuf[12 * this->m_nPointIndex + 108]);
  SetStatusText(nIndex: 2, pszText: string);
  CMapDoc::UpdateAllViews(this: v6, nFlags: 16, ub: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101576A0
// Name: public: virtual void CToolAxisHandle::RenderTool2D(class CRender2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolAxisHandle::RenderTool2D(CToolAxisHandle *this, CRender2D *pRender)
{
  SelectionState_t v3; // edi

  v3 = CMapAxisHandle::SetSelectionState(
         this: this->m_pAxis,
         eSelectionState: SELECT_MODIFY,
         nHandle: this->m_nPointIndex);
  this->m_pAxis->Render2D(this: this->m_pAxis, a2: pRender);
  this->m_pAxis->SetSelectionState(this: this->m_pAxis, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x101576E0
// Name: public: virtual bool CToolAxisHandle::OnLMouseDown2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolAxisHandle::OnLMouseDown2D(
        CToolAxisHandle *this,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  CToolManager *v5; // eax
  HWND v6; // eax
  CMapDoc *v7; // eax
  CHistory *History; // eax
  CHistory *v9; // eax
  const CUtlReferenceVector<CMapClass> *List; // [esp-Ch] [ebp-14h]
  CMapAxisHandle *m_pAxis; // [esp-4h] [ebp-Ch]

  v5 = ToolManager();
  CToolManager::PushTool(this: v5, eToolID: TOOL_AXIS_HANDLE);
  v6 = SetCapture(hWnd: pView->m_hWnd);
  CWnd::FromHandle(hWnd: v6);
  v7 = pView->GetMapDoc(this: &pView->CMapView);
  List = CSelection::GetList(this: v7->m_pSelection);
  History = GetHistory();
  CHistory::MarkUndoPosition(this: History, pSelection: List, pszName: "Modify Axis", bFromOpposite: 0);
  m_pAxis = this->m_pAxis;
  v9 = GetHistory();
  CHistory::Keep(this: v9, pObject: m_pAxis);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016BEB0
// Name: public: void CToolAxisHandle::Attach(class CMapAxisHandle __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolAxisHandle::Attach(CToolAxisHandle *this, CMapAxisHandle *pAxis, int nPointIndex)
{
  if ( pAxis != nullptr && nPointIndex < 2 )
  {
    this->m_pAxis = pAxis;
    this->m_nPointIndex = nPointIndex;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1016BED0
// Name: public: virtual bool CToolAxisHandle::OnLMouseUp2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolAxisHandle::OnLMouseUp2D(
        CToolAxisHandle *this,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  CToolManager *v4; // eax
  CMapDoc *v5; // eax

  v4 = ToolManager();
  CToolManager::PopTool(this: v4);
  ReleaseCapture();
  v5 = pView->GetMapDoc(this: &pView->CMapView);
  CMapDoc::UpdateAllViews(this: v5, nFlags: 16, ub: nullptr);
  return 1;
}
