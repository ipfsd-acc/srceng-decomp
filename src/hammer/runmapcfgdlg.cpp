// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/runmapcfgdlg.cpp
// Functions: 9
// ============================================================

#include "hammer\runmapcfgdlg.h"

//------------------------------------------------------------------------------
// Address: 0x100F4C00
// Name: public: CRunMapCfgDlg::CRunMapCfgDlg(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CRunMapCfgDlg *__thiscall CRunMapCfgDlg::CRunMapCfgDlg(CRunMapCfgDlg *this, CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0xD8u, pParentWnd: pParent);
  this->__vftable = (CRunMapCfgDlg_vtbl *)&CRunMapCfgDlg::`vftable';
  CWnd::CWnd(this: &this->m_cConfigurations);
  this->m_cConfigurations.__vftable = (CListBox_vtbl *)&CListBox::`vftable';
  this->m_pApp = (CHammer *)AfxGetModuleState()->m_pCurrentWinApp;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F4C90
// Name: protected: virtual void CRunMapCfgDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMapCfgDlg::DoDataExchange(CRunMapCfgDlg *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x4BC, rControl: (HWND__ *)&this->m_cConfigurations);
}

//------------------------------------------------------------------------------
// Address: 0x100F4CB0
// Name: protected: void CRunMapCfgDlg::AddSequenceToList(int,class CCommandSequence __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMapCfgDlg::AddSequenceToList(CRunMapCfgDlg *this, WPARAM iIndex, CCommandSequence *pSeq)
{
  WPARAM v4; // ebx

  v4 = SendMessageA(hWnd: this->m_cConfigurations.m_hWnd, Msg: 0x181u, wParam: iIndex, lParam: (LPARAM)pSeq->m_szName);
  SendMessageA(hWnd: this->m_cConfigurations.m_hWnd, Msg: 0x19Au, wParam: v4, lParam: (LPARAM)pSeq);
  SendMessageA(hWnd: this->m_cConfigurations.m_hWnd, Msg: 0x186u, wParam: v4, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100F4D10
// Name: protected: virtual int CRunMapCfgDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100F4DA0
// Name: protected: void CRunMapCfgDlg::OnRename(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMapCfgDlg::OnRename(CRunMapCfgDlg *this)
{
  WPARAM v2; // eax
  WPARAM v3; // edi
  CCommandSequence *v4; // eax
  char *m_szName; // ebx
  char *m_pszData; // ecx
  char *v7; // edx
  char v8; // al
  CStrDlg dlg; // [esp+Ch] [ebp-21Ch] BYREF
  CCommandSequence *pSeq; // [esp+218h] [ebp-10h]
  int v11; // [esp+224h] [ebp-4h]

  v2 = SendMessageA(hWnd: this->m_cConfigurations.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  v3 = v2;
  if ( v2 != -1 )
  {
    v4 = (CCommandSequence *)SendMessageA(hWnd: this->m_cConfigurations.m_hWnd, Msg: 0x199u, wParam: v2, lParam: 0);
    m_szName = v4->m_szName;
    pSeq = v4;
    CStrDlg::CStrDlg(
      this: &dlg,
      dwFlags: 0,
      pszString: v4->m_szName,
      pszPrompt: "Name:",
      pszTitle: "Rename Configuration");
    v11 = 0;
    if ( CDialog::DoModal(this: &dlg) != 2 )
    {
      m_pszData = dlg.m_string.m_pszData;
      v7 = m_szName;
      do
      {
        v8 = *m_pszData;
        *v7++ = *m_pszData++;
      }
      while ( v8 != 0 );
      SendMessageA(hWnd: this->m_cConfigurations.m_hWnd, Msg: 0x182u, wParam: v3, lParam: 0);
      CRunMapCfgDlg::AddSequenceToList(this, iIndex: v3, pSeq);
    }
    v11 = -1;
    CStrDlg::~CStrDlg(this: &dlg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F4E90
// Name: protected: void CRunMapCfgDlg::OnCopy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMapCfgDlg::OnCopy(CRunMapCfgDlg *this)
{
  CArray<CCOMMAND,CCOMMAND &> *v1; // edi
  WPARAM v3; // ebx
  CArray<CCOMMAND,CCOMMAND &> *v4; // eax
  char *m_pszData; // ecx
  CArray<CCOMMAND,CCOMMAND &> *v6; // edx
  char v7; // al
  LRESULT v8; // eax
  LRESULT v9; // ebx
  int m_nSize; // esi
  CRunMapCfgDlg *v11; // ebx
  WPARAM v12; // esi
  HWND__ *m_hWnd; // [esp-10h] [ebp-23Ch]
  CStrDlg dlg; // [esp+Ch] [ebp-220h] BYREF
  void *p; // [esp+218h] [ebp-14h]
  CRunMapCfgDlg *v16; // [esp+21Ch] [ebp-10h]
  int v17; // [esp+228h] [ebp-4h]

  v1 = nullptr;
  m_hWnd = this->m_cConfigurations.m_hWnd;
  v16 = this;
  v3 = SendMessageA(hWnd: m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  if ( v3 != -1 )
  {
    CStrDlg::CStrDlg(this: &dlg, dwFlags: 0, pszString: &var, pszPrompt: "Name:", pszTitle: "Copy Configuration");
    v17 = 0;
    if ( CDialog::DoModal(this: &dlg) != 2 )
    {
      v4 = (CArray<CCOMMAND,CCOMMAND &> *)operator new(nSize: 0x94u);
      p = v4;
      LOBYTE(v17) = 1;
      if ( v4 != nullptr )
      {
        v4->__vftable = (CArray<CCOMMAND,CCOMMAND &>_vtbl *)&CArray<CCOMMAND,CCOMMAND &>::`vftable';
        v4->m_pData = nullptr;
        v4->m_nGrowBy = 0;
        v4->m_nMaxSize = 0;
        v4->m_nSize = 0;
        LOBYTE(v17) = 1;
        v1 = v4;
      }
      LOBYTE(v17) = 0;
      m_pszData = dlg.m_string.m_pszData;
      v6 = v1 + 1;
      do
      {
        v7 = *m_pszData;
        LOBYTE(v6->__vftable) = *m_pszData++;
        v6 = (CArray<CCOMMAND,CCOMMAND &> *)((char *)v6 + 1);
      }
      while ( v7 != 0 );
      CUIntArray::SetAtGrow(
        this: &this->m_pApp->m_CmdSequences,
        nIndex: this->m_pApp->m_CmdSequences.m_nSize,
        newElement: v1);
      v8 = SendMessageA(hWnd: this->m_cConfigurations.m_hWnd, Msg: 0x199u, wParam: v3, lParam: 0);
      v9 = v8;
      if ( v1 == (CArray<CCOMMAND,CCOMMAND &> *)v8 )
        AfxThrowInvalidArgException();
      m_nSize = v1->m_nSize;
      CArray<CCOMMAND,CCOMMAND &>::SetSize(this: v1, nNewSize: m_nSize + *(_DWORD *)(v8 + 8), nGrowBy: -1);
      CopyElements<CCOMMAND>(
        pDest: &v1->m_pData[m_nSize],
        pSrc: *(const CCOMMAND **)(v9 + 4),
        nCount: *(_DWORD *)(v9 + 8));
      v11 = v16;
      v12 = SendMessageA(hWnd: v16->m_cConfigurations.m_hWnd, Msg: 0x181u, wParam: 0xFFFFFFFF, lParam: (LPARAM)&v1[1]);
      SendMessageA(hWnd: v11->m_cConfigurations.m_hWnd, Msg: 0x19Au, wParam: v12, lParam: (LPARAM)v1);
      SendMessageA(hWnd: v11->m_cConfigurations.m_hWnd, Msg: 0x186u, wParam: v12, lParam: 0);
    }
    v17 = -1;
    CStrDlg::~CStrDlg(this: &dlg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F5020
// Name: protected: void CRunMapCfgDlg::OnNew(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRunMapCfgDlg::OnNew(CRunMapCfgDlg *this)
{
  _DWORD *v2; // eax
  char *v3; // edx
  char *m_pszData; // ecx
  LPARAM v5; // edi
  _BYTE *v6; // esi
  char v7; // al
  WPARAM v8; // edi
  CStrDlg dlg; // [esp+8h] [ebp-220h] BYREF
  _DWORD *v10; // [esp+214h] [ebp-14h]
  LPARAM lParam; // [esp+218h] [ebp-10h]
  int v12; // [esp+224h] [ebp-4h]

  CStrDlg::CStrDlg(this: &dlg, dwFlags: 0, pszString: &var, pszPrompt: "Name:", pszTitle: "New Configuration");
  v12 = 0;
  if ( CDialog::DoModal(this: &dlg) == 2 )
  {
    v12 = -1;
    CStrDlg::~CStrDlg(this: &dlg);
  }
  else
  {
    v2 = operator new(nSize: 0x94u);
    v10 = v2;
    LOBYTE(v12) = 1;
    if ( v2 != nullptr )
    {
      *v2 = &CArray<CCOMMAND,CCOMMAND &>::`vftable';
      v2[1] = 0;
      v2[4] = 0;
      v2[3] = 0;
      v2[2] = 0;
      LOBYTE(v12) = 1;
      v3 = (char *)v2;
      lParam = (LPARAM)v2;
    }
    else
    {
      lParam = 0;
      v3 = nullptr;
    }
    LOBYTE(v12) = 0;
    m_pszData = dlg.m_string.m_pszData;
    v5 = (LPARAM)(v3 + 20);
    v6 = v3 + 20;
    do
    {
      v7 = *m_pszData;
      *v6++ = *m_pszData++;
    }
    while ( v7 != 0 );
    CUIntArray::SetAtGrow(
      this: &this->m_pApp->m_CmdSequences,
      nIndex: this->m_pApp->m_CmdSequences.m_nSize,
      newElement: v3);
    v8 = SendMessageA(hWnd: this->m_cConfigurations.m_hWnd, Msg: 0x181u, wParam: 0xFFFFFFFF, lParam: v5);
    SendMessageA(hWnd: this->m_cConfigurations.m_hWnd, Msg: 0x19Au, wParam: v8, lParam);
    SendMessageA(hWnd: this->m_cConfigurations.m_hWnd, Msg: 0x186u, wParam: v8, lParam: 0);
    v12 = -1;
    CStrDlg::~CStrDlg(this: &dlg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F5170
// Name: protected: void CRunMapCfgDlg::OnRemove(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100F52A0
// Name: protected: virtual struct AFX_MSGMAP const __near * CRunMapCfgDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CRunMapCfgDlg::GetMessageMap(CRunMapCfgDlg *this)
{
  return (const AFX_MSGMAP *)&off_105F2058;
}
