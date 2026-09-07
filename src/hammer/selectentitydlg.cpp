// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/selectentitydlg.cpp
// Functions: 6
// ============================================================

#include "hammer\selectentitydlg.h"

//------------------------------------------------------------------------------
// Address: 0x100FFF00
// Name: public: CSelectEntityDlg::CSelectEntityDlg(class CUtlReferenceVector<class CMapClass> const __near *,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CSelectEntityDlg *__thiscall CSelectEntityDlg::CSelectEntityDlg(
        CSelectEntityDlg *this,
        const CUtlReferenceVector<CMapClass> *pList,
        CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0xF8u, pParentWnd: pParent);
  this->__vftable = (CSelectEntityDlg_vtbl *)&CSelectEntityDlg::`vftable';
  CWnd::CWnd(this: &this->m_cEntities);
  this->m_cEntities.__vftable = (CListBox_vtbl *)&CListBox::`vftable';
  this->m_pEntityList = pList;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FFF80
// Name: protected: virtual void CSelectEntityDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectEntityDlg::DoDataExchange(CSelectEntityDlg *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x526, rControl: (HWND__ *)&this->m_cEntities);
}

//------------------------------------------------------------------------------
// Address: 0x100FFFA0
// Name: protected: void CSelectEntityDlg::OnSelchangeEntities(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectEntityDlg::OnSelchangeEntities(CSelectEntityDlg *this)
{
  WPARAM v2; // eax
  CMapClass *v3; // eax

  v2 = SendMessageA(hWnd: this->m_cEntities.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  v3 = (CMapClass *)SendMessageA(hWnd: this->m_cEntities.m_hWnd, Msg: 0x199u, wParam: v2, lParam: 0);
  CMapDoc::SelectObject(this: CMapDoc::m_pMapDoc, pObj: v3, cmd: 1042);
}

//------------------------------------------------------------------------------
// Address: 0x100FFFF0
// Name: protected: virtual void CSelectEntityDlg::OnOK(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectEntityDlg::OnOK(CSelectEntityDlg *this)
{
  WPARAM v2; // eax

  v2 = SendMessageA(hWnd: this->m_cEntities.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  this->m_pFinalEntity = (CMapEntity *)SendMessageA(hWnd: this->m_cEntities.m_hWnd, Msg: 0x199u, wParam: v2, lParam: 0);
  CDialog::OnOK(this);
}

//------------------------------------------------------------------------------
// Address: 0x10100030
// Name: protected: virtual struct AFX_MSGMAP const __near * CSelectEntityDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CSelectEntityDlg::GetMessageMap(CSelectEntityDlg *this)
{
  return (const AFX_MSGMAP *)&off_105F3A94;
}

//------------------------------------------------------------------------------
// Address: 0x10100040
// Name: protected: virtual int CSelectEntityDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSelectEntityDlg::OnInitDialog(CSelectEntityDlg *this)
{
  const CUtlReferenceVector<CMapClass> *m_pEntityList; // edx
  CMapClass *m_pObject; // edi
  WPARAM v4; // eax
  WPARAM v5; // eax
  CMapClass *v6; // eax
  int pos; // [esp+8h] [ebp-4h]

  CDialog::OnInitDialog(this);
  m_pEntityList = this->m_pEntityList;
  for ( pos = 0; pos < m_pEntityList->m_Size; ++pos )
  {
    m_pObject = m_pEntityList->m_Memory.m_pMemory[pos >> (*((int *)&m_pEntityList->m_Memory + 2) >> 27)][pos & ((32 * *((_DWORD *)&m_pEntityList->m_Memory + 2)) >> 5)].m_pObject;
    if ( m_pObject->IsMapClass(this: m_pObject, a2: CMapEntity::__Type) != 0
      && (*((_BYTE *)&m_pObject[1].m_Dependents.m_Memory + 8) & 1) == 0 )
    {
      v4 = SendMessageA(hWnd: this->m_cEntities.m_hWnd, Msg: 0x180u, wParam: 0, lParam: (LPARAM)&m_pObject[1].___u2);
      SendMessageA(hWnd: this->m_cEntities.m_hWnd, Msg: 0x19Au, wParam: v4, lParam: (LPARAM)m_pObject);
    }
    m_pEntityList = this->m_pEntityList;
  }
  SendMessageA(hWnd: this->m_cEntities.m_hWnd, Msg: 0x186u, wParam: 0, lParam: 0);
  v5 = SendMessageA(hWnd: this->m_cEntities.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  v6 = (CMapClass *)SendMessageA(hWnd: this->m_cEntities.m_hWnd, Msg: 0x199u, wParam: v5, lParam: 0);
  CMapDoc::SelectObject(this: CMapDoc::m_pMapDoc, pObj: v6, cmd: 1042);
  return 1;
}
