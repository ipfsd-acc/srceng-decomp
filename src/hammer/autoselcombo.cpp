// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/autoselcombo.cpp
// Functions: 7
// ============================================================

#include "hammer\autoselcombo.h"

//------------------------------------------------------------------------------
// Address: 0x100BCF50
// Name: public: void CAutoSelComboBox::SubclassDlgItem(unsigned int,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAutoSelComboBox::SubclassDlgItem(CAutoSelComboBox *this, unsigned int nID, CWnd *pParent)
{
  this->m_bNotifyParent = CObject::IsKindOf(this: pParent, pClass: &CControlBar::classCControlBar) == 0;
  CWnd::SubclassDlgItem(this, nID, pParent);
}

//------------------------------------------------------------------------------
// Address: 0x100BCF90
// Name: protected: int CAutoSelComboBox::OnEditUpdate(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAutoSelComboBox::OnEditUpdate(CAutoSelComboBox *this)
{
  this->OnUpdateText(this);
  return !this->m_bNotifyParent;
}

//------------------------------------------------------------------------------
// Address: 0x100BCFB0
// Name: protected: struct HBRUSH__ __near * CAutoSelComboBox::OnCtlColor(class CDC __near *,class CWnd __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
HBRUSH__ *__thiscall CAutoSelComboBox::OnCtlColor(CAutoSelComboBox *this, CDC *pDC, CWnd *pWnd, HBRUSH__ *nCtlColor)
{
  HBRUSH__ *result; // eax
  HBRUSH__ *hBrush; // [esp+1Ch] [ebp+10h]

  result = CWnd::OnCtlColor(this, __formal: pDC, pWnd, __formal: (unsigned int)nCtlColor);
  hBrush = result;
  if ( nCtlColor == (HBRUSH__ *)1 )
  {
    pDC->SetTextColor(this: pDC, a2: this->m_dwTextColor);
    return hBrush;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100BCFF0
// Name: public: CAutoSelComboBox::CAutoSelComboBox(void)
// Source: json
//------------------------------------------------------------------------------
CAutoSelComboBox *__thiscall CAutoSelComboBox::CAutoSelComboBox(CAutoSelComboBox *this)
{
  CWnd::CWnd(this);
  this->__vftable = (CAutoSelComboBox_vtbl *)&CComboBox::`vftable';
  this->m_szLastText[0] = 0;
  this->m_dwTextColor = 0;
  this->__vftable = (CAutoSelComboBox_vtbl *)&CAutoSelComboBox::`vftable';
  this->m_bNotifyParent = true;
  this->m_nLastSel = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100BD060
// Name: protected: virtual void CAutoSelComboBox::OnUpdateText(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAutoSelComboBox::OnUpdateText(CAutoSelComboBox *this)
{
  LRESULT v2; // eax
  unsigned int v3; // eax
  signed int v4; // kr00_4
  WPARAM v5; // eax
  int v6; // edi
  int v7; // ecx
  HWND Parent; // eax
  CWnd *v9; // eax
  CWnd *v10; // edi
  unsigned __int16 DlgCtrlID; // ax
  HWND__ *m_hWnd; // [esp-10h] [ebp-130h]
  char szTypedText[260]; // [esp+Ch] [ebp-114h] BYREF
  int nEditEnd; // [esp+110h] [ebp-10h]
  int nEditStart; // [esp+114h] [ebp-Ch]
  int nLastLen; // [esp+118h] [ebp-8h]
  int nNewSel; // [esp+11Ch] [ebp-4h]

  v2 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  m_hWnd = this->m_hWnd;
  nNewSel = v2;
  v3 = SendMessageA(hWnd: m_hWnd, Msg: 0x140u, wParam: 0, lParam: 0);
  nEditEnd = HIWORD(v3);
  nEditStart = (unsigned __int16)v3;
  CWnd::GetWindowTextA(this, lpszString: szTypedText, nMaxCount: 260);
  v4 = strlen(szTypedText);
  nLastLen = strlen(this->m_szLastText);
  if ( V_strncasecmp(s1: szTypedText, s2: this->m_szLastText, n: v4) != 0 )
  {
    v5 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x14Cu, wParam: 0xFFFFFFFF, lParam: (LPARAM)szTypedText);
  }
  else
  {
    if ( v4 >= nLastLen )
      goto LABEL_14;
    v5 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x158u, wParam: 0xFFFFFFFF, lParam: (LPARAM)szTypedText);
  }
  v6 = v5;
  if ( nNewSel != v5 )
  {
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x14Eu, wParam: v5, lParam: 0);
    nNewSel = v6;
  }
  if ( v6 == -1 )
  {
    CWnd::SetWindowTextA(this, lpszString: szTypedText);
    v7 = (unsigned __int16)nEditEnd;
  }
  else
  {
    if ( nEditEnd == -1 || nEditEnd == strlen(szTypedText) )
    {
      SendMessageA(hWnd: this->m_hWnd, Msg: 0x142u, wParam: 0, lParam: strlen(szTypedText) | 0xFFFF0000);
      goto LABEL_14;
    }
    v7 = (unsigned __int16)nEditEnd;
  }
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x142u, wParam: 0, lParam: (unsigned __int16)nEditStart | (v7 << 16));
LABEL_14:
  strcpy(this->m_szLastText, szTypedText);
  if ( nNewSel != this->m_nLastSel )
  {
    Parent = GetParent(hWnd: this->m_hWnd);
    v9 = CWnd::FromHandle(hWnd: Parent);
    nLastLen = (int)this->m_hWnd;
    v10 = v9;
    DlgCtrlID = CWnd::GetDlgCtrlID(this);
    SendMessageA(hWnd: v10->m_hWnd, Msg: 0x111u, wParam: DlgCtrlID | 0x10000, lParam: nLastLen);
    this->m_nLastSel = nNewSel;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100BD230
// Name: protected: virtual struct AFX_MSGMAP const __near * CAutoSelComboBox::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CAutoSelComboBox::GetMessageMap(CAutoSelComboBox *this)
{
  return (const AFX_MSGMAP *)&off_105E8360;
}

//------------------------------------------------------------------------------
// Address: 0x1014DDD0
// Name: public: void CAutoSelComboBox::SetTextColor(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAutoSelComboBox::SetTextColor(CAutoSelComboBox *this, unsigned int dwColor)
{
  this->m_dwTextColor = dwColor;
}
