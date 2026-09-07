// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/toolsphere.cpp
// Functions: 5
// ============================================================

#include "hammer\toolsphere.h"

//------------------------------------------------------------------------------
// Address: 0x10166400
// Name: public: void CToolSphere::Attach(class CMapSphere __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CToolSphere::Attach(CToolPointHandle *this, CMapPointHandle *pPoint)
{
  this->m_pPoint = pPoint;
}

//------------------------------------------------------------------------------
// Address: 0x1016A080
// Name: public: CToolSphere::CToolSphere(void)
// Source: json
//------------------------------------------------------------------------------
CToolSphere *__thiscall CToolSphere::CToolSphere(CToolSphere *this)
{
  this->__vftable = (CToolSphere_vtbl *)&CBaseTool::`vftable';
  *(_WORD *)&this->m_bActiveTool = 256;
  this->m_pDocument = nullptr;
  this->__vftable = (CToolSphere_vtbl *)&CToolSphere::`vftable';
  this->m_pSphere = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1016A0E0
// Name: public: virtual bool CToolSphere::OnLMouseUp2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolSphere::OnLMouseUp2D(
        CToolSphere *this,
        CMapView2D *pView,
        CMapView2D *nFlags,
        const Vector2D *vPoint)
{
  CToolManager *v5; // eax

  v5 = ToolManager();
  CToolManager::PopTool(this: v5);
  ReleaseCapture();
  this->m_pDocument->SetModifiedFlag(this: this->m_pDocument, a2: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016A110
// Name: public: virtual bool CToolSphere::OnMouseMove2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolSphere::OnMouseMove2D(
        CToolSphere *this,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  CMapSphere *m_pSphere; // ecx
  float v6; // xmm0_4
  char string[20]; // [esp+20h] [ebp-8Ch] BYREF
  char szBuf_108[128]; // [esp+A0h] [ebp-Ch] BYREF

  CMapView2DBase::ToolScrollToPoint(this: pView, ptClient: vPoint);
  pView->ClientToWorld(this: &pView->CMapView, a2: (Vector *)szBuf_108, a3: vPoint);
  CMapDoc::Snap(this: this->m_pDocument, pt: (Vector *)szBuf_108, nFlags: 4);
  m_pSphere = this->m_pSphere;
  LODWORD(v6) = COERCE_UNSIGNED_INT(*(float *)&szBuf_108[4 * pView->axHorz] - *(&m_pSphere->m_Origin.x + pView->axHorz))
              & _mask__AbsFloat_;
  if ( v6 <= COERCE_FLOAT(
               COERCE_UNSIGNED_INT(*(float *)&szBuf_108[4 * pView->axVert] - *(&m_pSphere->m_Origin.x + pView->axVert))
             & _mask__AbsFloat_) )
    LODWORD(v6) = COERCE_UNSIGNED_INT(*(float *)&szBuf_108[4 * pView->axVert] - *(&m_pSphere->m_Origin.x + pView->axVert))
                & _mask__AbsFloat_;
  ((void (__stdcall *)(float))m_pSphere->SetRadius)(a1: COERCE_FLOAT(LODWORD(v6)));
  sprintf(string, format: " %s = %g ", this->m_pSphere->m_szKeyName, this->m_pSphere->m_flRadius);
  SetStatusText(nIndex: 2, pszText: string);
  CMapDoc::UpdateAllViews(this: this->m_pDocument, nFlags: 16, ub: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1016A1F0
// Name: public: virtual bool CToolSphere::OnLMouseDown2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolSphere::OnLMouseDown2D(
        CToolSphere *this,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  CToolManager *v5; // eax
  HWND v6; // eax
  CHistory *History; // eax
  CHistory *v8; // eax
  const CUtlReferenceVector<CMapClass> *List; // [esp-Ch] [ebp-10h]
  CMapSphere *m_pSphere; // [esp-4h] [ebp-8h]

  v5 = ToolManager();
  CToolManager::PushTool(this: v5, eToolID: TOOL_SPHERE);
  v6 = SetCapture(hWnd: pView->m_hWnd);
  CWnd::FromHandle(hWnd: v6);
  List = CSelection::GetList(this: this->m_pDocument->m_pSelection);
  History = GetHistory();
  CHistory::MarkUndoPosition(this: History, pSelection: List, pszName: "Modify Radius", bFromOpposite: 0);
  m_pSphere = this->m_pSphere;
  v8 = GetHistory();
  CHistory::Keep(this: v8, pObject: m_pSphere);
  return 1;
}
