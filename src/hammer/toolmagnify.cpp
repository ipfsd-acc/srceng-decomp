// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/toolmagnify.cpp
// Functions: 4
// ============================================================

#include "hammer\toolmagnify.h"

//------------------------------------------------------------------------------
// Address: 0x1015EA50
// Name: public: CToolMagnify::CToolMagnify(void)
// Source: json
//------------------------------------------------------------------------------
CToolMagnify *__thiscall CToolMagnify::CToolMagnify(CToolMagnify *this)
{
  this->__vftable = (CToolMagnify_vtbl *)&CBaseTool::`vftable';
  *(_WORD *)&this->m_bActiveTool = 256;
  this->m_pDocument = nullptr;
  this->__vftable = (CToolMagnify_vtbl *)&CToolMagnify::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1015EB00
// Name: public: virtual bool CToolMagnify::OnMouseMove2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolMagnify::OnMouseMove2D(
        CToolMagnify *this,
        CMapView2D *pView,
        unsigned int nFlags,
        const Vector2D *vPoint)
{
  CVGuiWnd::SetCursor(this: &pView->CVGuiWnd, filename: "Resource/magnify.cur");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015EB20
// Name: public: virtual bool CToolMagnify::OnRMouseDown2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolMagnify::OnRMouseDown2D(
        CToolMagnify *this,
        CMapView2D *pView,
        CMapView2D *nFlags,
        const Vector2D *vPoint)
{
  CMapView2DBase::SetZoom(this: pView, fNewZoom: pView->m_fZoom * 0.5);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1015EB50
// Name: public: virtual bool CToolMagnify::OnLMouseDown2D(class CMapView2D __near *,unsigned int,class Vector2D const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CToolMagnify::OnLMouseDown2D(
        CToolMagnify *this,
        CMapView2D *pView,
        CMapView2D *nFlags,
        const Vector2D *vPoint)
{
  CMapView2DBase::SetZoom(this: pView, fNewZoom: pView->m_fZoom * 2.0);
  InvalidateRect(hWnd: pView->m_hWnd, lpRect: nullptr, bErase: true);
  return 1;
}
