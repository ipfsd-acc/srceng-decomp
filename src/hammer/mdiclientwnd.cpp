// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/mdiclientwnd.cpp
// Functions: 5
// ============================================================

#include "hammer\mdiclientwnd.h"

//------------------------------------------------------------------------------
// Address: 0x100862C0
// Name: public: CMDIClientWnd::CMDIClientWnd(void)
// Source: json
//------------------------------------------------------------------------------
CMDIClientWnd *__thiscall CMDIClientWnd::CMDIClientWnd(CMDIClientWnd *this)
{
  CWnd::CWnd(this);
  this->__vftable = (CMDIClientWnd_vtbl *)&CMDIClientWnd::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10086310
// Name: public: virtual CMDIClientWnd::~CMDIClientWnd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDIClientWnd::~CMDIClientWnd(CMDIClientWnd *this)
{
  this->__vftable = (CMDIClientWnd_vtbl *)&CMDIClientWnd::`vftable';
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x10086350
// Name: protected: void CMDIClientWnd::OnLButtonDown(unsigned int,class CPoint)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMDIClientWnd::OnLButtonDown(CMDIClientWnd *this, unsigned int nFlags, CPoint point)
{
  AFX_MODULE_STATE *ModuleState; // eax

  ModuleState = AfxGetModuleState();
  CHammer::OnFileOpen(this: (CHammer *)ModuleState->m_pCurrentWinApp);
}

//------------------------------------------------------------------------------
// Address: 0x100863C0
// Name: protected: int CMDIClientWnd::OnEraseBkgnd(class CDC __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMDIClientWnd::OnEraseBkgnd(CMDIClientWnd *this, CDC *pDC)
{
  CFont *v2; // eax
  int (__thiscall *GetClipBox)(CDC *, tagRECT *); // edx
  CFont *v4; // ebx
  CRect rect; // [esp+Ch] [ebp-24h] BYREF
  CBrush backBrush; // [esp+1Ch] [ebp-14h] BYREF
  int v8; // [esp+2Ch] [ebp-4h]

  CBrush::CBrush(this: &backBrush, crColor: 0x82888Du);
  v8 = 0;
  v2 = CDC::SelectObject(this: pDC, pFont: (CFont *)&backBrush);
  GetClipBox = pDC->GetClipBox;
  v4 = v2;
  memset(&rect, 0, sizeof(rect));
  GetClipBox(this: pDC, a2: &rect);
  PatBlt(
    hdc: pDC->m_hDC,
    x: rect.left,
    y: rect.top,
    w: rect.right - rect.left,
    h: rect.bottom - rect.top,
    rop: 0xF00021u);
  CDC::SelectObject(this: pDC, pFont: v4);
  backBrush.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  v8 = -1;
  CGdiObject::~CGdiObject(this: &backBrush);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10086480
// Name: protected: virtual struct AFX_MSGMAP const __near * CMDIClientWnd::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMDIClientWnd::GetMessageMap(CMDIClientWnd *this)
{
  return (const AFX_MSGMAP *)&off_105E34FC;
}
