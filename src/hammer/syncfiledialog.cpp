// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/syncfiledialog.cpp
// Functions: 9
// ============================================================

#include "hammer\syncfiledialog.h"

//------------------------------------------------------------------------------
// Address: 0x101006A0
// Name: public: virtual struct CRuntimeClass __near * CSyncFileDialog::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CSyncFileDialog::GetRuntimeClass(CSyncFileDialog *this)
{
  return &CSyncFileDialog::classCSyncFileDialog;
}

//------------------------------------------------------------------------------
// Address: 0x101006B0
// Name: public: virtual CSyncFileDialog::~CSyncFileDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSyncFileDialog::~CSyncFileDialog(CSyncFileDialog *this)
{
  this->__vftable = (CSyncFileDialog_vtbl *)&CSyncFileDialog::`vftable';
  CStatic::~CStatic(this: &this->m_IconControl);
  CButton::~CButton(this: &this->m_DoOperationControl);
  CStatic::~CStatic(this: &this->m_RevisionControl);
  CStatic::~CStatic(this: &this->m_FileNameControl);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x10100740
// Name: public: CSyncFileDialog::CSyncFileDialog(struct P4File_t __near *,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CSyncFileDialog *__thiscall CSyncFileDialog::CSyncFileDialog(CSyncFileDialog *this, P4File_t *pFileInfo, CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0x166u, pParentWnd: pParent);
  this->__vftable = (CSyncFileDialog_vtbl *)&CSyncFileDialog::`vftable';
  CWnd::CWnd(this: &this->m_FileNameControl);
  this->m_FileNameControl.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_RevisionControl);
  this->m_RevisionControl.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_DoOperationControl);
  this->m_DoOperationControl.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_IconControl);
  this->m_IconControl.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  this->m_pFileInfo = pFileInfo;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10100850
// Name: protected: virtual void CSyncFileDialog::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSyncFileDialog::DoDataExchange(CSyncFileDialog *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F1, rControl: (HWND__ *)&this->m_FileNameControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x6B3, rControl: (HWND__ *)&this->m_RevisionControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x670, rControl: (HWND__ *)&this->m_DoOperationControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x6B4, rControl: (HWND__ *)&this->m_IconControl);
}

//------------------------------------------------------------------------------
// Address: 0x101008B0
// Name: public: void CSyncFileDialog::OnBnClickedOk(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSyncFileDialog::OnBnClickedOk(CSyncFileDialog *this)
{
  CSyncFileDialog::m_bRepeatOperation = SendMessageA(
                                          hWnd: this->m_DoOperationControl.m_hWnd,
                                          Msg: 0xF0u,
                                          wParam: 0,
                                          lParam: 0) != 0;
  CSyncFileDialog::m_bDoSync = true;
  this->OnOK(this);
}

//------------------------------------------------------------------------------
// Address: 0x101008F0
// Name: public: void CSyncFileDialog::OnBnClickedCancel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSyncFileDialog::OnBnClickedCancel(CSyncFileDialog *this)
{
  CSyncFileDialog::m_bRepeatOperation = SendMessageA(
                                          hWnd: this->m_DoOperationControl.m_hWnd,
                                          Msg: 0xF0u,
                                          wParam: 0,
                                          lParam: 0) != 0;
  CSyncFileDialog::m_bDoSync = false;
  this->OnCancel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10100930
// Name: public: virtual int CSyncFileDialog::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSyncFileDialog::OnInitDialog(CSyncFileDialog *this)
{
  __int16 v2; // ecx^2
  const char *v3; // eax
  HICON IconA; // eax
  int v6; // [esp-4h] [ebp-10Ch]
  char temp[256]; // [esp+8h] [ebp-100h] BYREF

  CDialog::OnInitDialog(this);
  HIWORD(v6) = v2;
  LOWORD(v6) = this->m_pFileInfo->m_sLocalFile.m_Id;
  v3 = (const char *)((int (__thiscall *)(IP4 *, int))p4->String)(a1: p4, a2: v6);
  CWnd::SetWindowTextA(this: &this->m_FileNameControl, lpszString: v3);
  sprintf(
    string: temp,
    format: "Local Revision: %d  Head Revision: %d",
    this->m_pFileInfo->m_iHaveRevision,
    this->m_pFileInfo->m_iHeadRevision);
  CWnd::SetWindowTextA(this: &this->m_RevisionControl, lpszString: temp);
  SendMessageA(
    hWnd: this->m_DoOperationControl.m_hWnd,
    Msg: 0xF1u,
    wParam: CSyncFileDialog::m_bRepeatOperation,
    lParam: 0);
  IconA = LoadIconA(hInstance: nullptr, lpIconName: (LPCSTR)0x7F01);
  SendMessageA(hWnd: this->m_IconControl.m_hWnd, Msg: 0x170u, wParam: (WPARAM)IconA, lParam: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101009F0
// Name: void CheckForFileSync(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CheckForFileSync(const char *pszFileName, bool bClearRepeat)
{
  CSyncFileDialog SyncFileDialog; // [esp+4h] [ebp-294h] BYREF
  P4File_t FileInfo; // [esp+26Ch] [ebp-2Ch] BYREF
  int v4; // [esp+294h] [ebp-4h]

  if ( bClearRepeat )
    CSyncFileDialog::m_bRepeatOperation = false;
  if ( p4 != nullptr && Options.general.bEnablePerforceIntegration == 1 )
  {
    memset(&FileInfo, 255, 10);
    if ( ((unsigned __int8 (__stdcall *)(const char *, P4File_t *))p4->GetFileInfo)(a1: pszFileName, a2: &FileInfo) == 1
      && FileInfo.m_iHeadRevision != FileInfo.m_iHaveRevision )
    {
      if ( bClearRepeat || !CSyncFileDialog::m_bRepeatOperation )
      {
        CSyncFileDialog::CSyncFileDialog(this: &SyncFileDialog, pFileInfo: &FileInfo, pParent: nullptr);
        v4 = 0;
        CDialog::DoModal(this: &SyncFileDialog);
        v4 = -1;
        CSyncFileDialog::~CSyncFileDialog(this: &SyncFileDialog);
      }
      if ( CSyncFileDialog::m_bDoSync && !p4->SyncFile(this: p4, a2: pszFileName, a3: -1) )
        AfxMessageBox(lpszText: "Sync operation was NOT successful!", nType: 0, nIDHelp: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10100AF0
// Name: protected: virtual struct AFX_MSGMAP const __near * CSyncFileDialog::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CSyncFileDialog::GetMessageMap(CSyncFileDialog *this)
{
  return (const AFX_MSGMAP *)&off_105F3F04;
}
