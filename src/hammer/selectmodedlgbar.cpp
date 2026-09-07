// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/selectmodedlgbar.cpp
// Functions: 8
// ============================================================

#include "hammer\selectmodedlgbar.h"

//------------------------------------------------------------------------------
// Address: 0x10100140
// Name: public: int CSelectModeDlgBar::Create(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSelectModeDlgBar::Create(CSelectModeDlgBar *this, CWnd *pParentWnd)
{
  int result; // eax

  result = CHammerBar::Create(this, pParentWnd, nIDTemplate: 0x13Bu, nStyle: 0x4100u, nID: 0xE80Fu);
  if ( result != 0 )
  {
    CWnd::SetWindowTextA(this, lpszString: "Selection Mode");
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10100180
// Name: protected: void CSelectModeDlgBar::UpdateControlGroups(class CCmdUI __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectModeDlgBar::UpdateControlGroups(CSelectModeDlgBar *this, CCmdUI *pCmdUI)
{
  CMapDoc *v2; // edi
  CMapClass *m_pSelection; // ecx
  CCmdUI_vtbl *v4; // edi
  CMapClass *ParentWnd; // eax

  v2 = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    pCmdUI->Enable(this: pCmdUI, a2: 1);
    m_pSelection = (CMapClass *)v2->m_pSelection;
    v4 = pCmdUI->__vftable;
    ParentWnd = CVGuiWnd::GetParentWnd(this: m_pSelection);
    v4->SetCheck(this: pCmdUI, a2: ParentWnd == nullptr);
  }
  else
  {
    pCmdUI->Enable(this: pCmdUI, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101001D0
// Name: protected: void CSelectModeDlgBar::UpdateControlObjects(class CCmdUI __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectModeDlgBar::UpdateControlObjects(CSelectModeDlgBar *this, CCmdUI *pCmdUI)
{
  CMapDoc *v2; // edi
  CMapClass *m_pSelection; // ecx
  CCmdUI_vtbl *v4; // edi
  CMapClass *ParentWnd; // eax

  v2 = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    pCmdUI->Enable(this: pCmdUI, a2: 1);
    m_pSelection = (CMapClass *)v2->m_pSelection;
    v4 = pCmdUI->__vftable;
    ParentWnd = CVGuiWnd::GetParentWnd(this: m_pSelection);
    v4->SetCheck(this: pCmdUI, a2: ParentWnd == (CMapClass *)1);
  }
  else
  {
    pCmdUI->Enable(this: pCmdUI, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10100220
// Name: protected: void CSelectModeDlgBar::UpdateControlSolids(class CCmdUI __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectModeDlgBar::UpdateControlSolids(CSelectModeDlgBar *this, CCmdUI *pCmdUI)
{
  CMapDoc *v2; // edi
  CMapClass *m_pSelection; // ecx
  CCmdUI_vtbl *v4; // edi
  CMapClass *ParentWnd; // eax

  v2 = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    pCmdUI->Enable(this: pCmdUI, a2: 1);
    m_pSelection = (CMapClass *)v2->m_pSelection;
    v4 = pCmdUI->__vftable;
    ParentWnd = CVGuiWnd::GetParentWnd(this: m_pSelection);
    v4->SetCheck(this: pCmdUI, a2: ParentWnd == (CMapClass *)2);
  }
  else
  {
    pCmdUI->Enable(this: pCmdUI, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10100270
// Name: protected: void CSelectModeDlgBar::OnGroups(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectModeDlgBar::OnGroups(CSelectModeDlgBar *this)
{
  CWnd *DlgItem; // eax

  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    CSelection::SetMode(this: CMapDoc::m_pMapDoc->m_pSelection, eNewSelectMode: selectGroups);
    DlgItem = CWnd::GetDlgItem(this, nID: 1097);
    SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101002B0
// Name: protected: void CSelectModeDlgBar::OnObjects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectModeDlgBar::OnObjects(CSelectModeDlgBar *this)
{
  CWnd *DlgItem; // eax

  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    CSelection::SetMode(this: CMapDoc::m_pMapDoc->m_pSelection, eNewSelectMode: selectObjects);
    DlgItem = CWnd::GetDlgItem(this, nID: 1194);
    SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101002F0
// Name: protected: void CSelectModeDlgBar::OnSolids(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectModeDlgBar::OnSolids(CSelectModeDlgBar *this)
{
  CWnd *DlgItem; // eax

  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    CSelection::SetMode(this: CMapDoc::m_pMapDoc->m_pSelection, eNewSelectMode: selectSolids);
    DlgItem = CWnd::GetDlgItem(this, nID: 1164);
    SendMessageA(hWnd: DlgItem->m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10100330
// Name: protected: virtual struct AFX_MSGMAP const __near * CSelectModeDlgBar::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CSelectModeDlgBar::GetMessageMap(CSelectModeDlgBar *this)
{
  return (const AFX_MSGMAP *)&off_105F3AE0;
}
