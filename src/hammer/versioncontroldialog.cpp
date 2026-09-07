// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/versioncontroldialog.cpp
// Functions: 22
// ============================================================

#include "hammer\versioncontroldialog.h"

//------------------------------------------------------------------------------
// Address: 0x10104080
// Name: public: virtual struct CRuntimeClass __near * CMapDocCheckin::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMapDocCheckin::GetRuntimeClass(CMapDocCheckin *this)
{
  return &CMapDocCheckin::classCMapDocCheckin;
}

//------------------------------------------------------------------------------
// Address: 0x10104090
// Name: public: virtual struct CRuntimeClass __near * CMapDocStatus::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMapDocStatus::GetRuntimeClass(CMapDocStatus *this)
{
  return &CMapDocStatus::classCMapDocStatus;
}

//------------------------------------------------------------------------------
// Address: 0x101040A0
// Name: public: virtual CMapDocStatus::~CMapDocStatus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDocStatus::~CMapDocStatus(CMapDocStatus *this)
{
  this->__vftable = (CMapDocStatus_vtbl *)&CMapDocStatus::`vftable';
  CButton::~CButton(this: &this->m_RevertControl);
  CButton::~CButton(this: &this->m_DoneControl);
  CButton::~CButton(this: &this->m_CheckOutControl);
  CButton::~CButton(this: &this->m_AddControl);
  CButton::~CButton(this: &this->m_SyncControl);
  CStatic::~CStatic(this: &this->m_StatusTextControl);
  CListCtrl::~CListCtrl(this: &this->m_FileListCtrl);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x10104150
// Name: protected: virtual void CMapDocCheckin::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDocCheckin::DoDataExchange(CMapDocCheckin *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x6A5, rControl: (HWND__ *)&this->m_CheckinListCtrl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F1, rControl: (HWND__ *)&this->m_DescriptionCtrl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x6A6, rControl: (HWND__ *)&this->m_CheckInStatusControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x6BF, rControl: (HWND__ *)&this->m_SubmitButtonControl);
}

//------------------------------------------------------------------------------
// Address: 0x101041B0
// Name: public: void CMapDocCheckin::OnNMRclickCheckinList(struct tagNMHDR __near *,long __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDocCheckin::OnNMRclickCheckinList(CMapDocCheckin *this, tagNMHDR *pNMHDR, int *pResult)
{
  signed int v3; // esi
  CListCtrl *p_m_CheckinListCtrl; // ecx

  v3 = 0;
  for ( *pResult = 0; v3 < SendMessageA(hWnd: this->m_CheckinListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0); ++v3 )
  {
    p_m_CheckinListCtrl = &this->m_CheckinListCtrl;
    if ( this->m_bSelectAll )
      CListCtrl::SetItemState(this: p_m_CheckinListCtrl, nItem: v3, nState: 0x2000u, nStateMask: 0xF000u);
    else
      CListCtrl::SetItemState(this: p_m_CheckinListCtrl, nItem: v3, nState: 0x1000u, nStateMask: 0xF000u);
  }
  this->m_bSelectAll = !this->m_bSelectAll;
}

//------------------------------------------------------------------------------
// Address: 0x10104240
// Name: public: CMapDocStatus::CMapDocStatus(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CMapDocStatus *__thiscall CMapDocStatus::CMapDocStatus(CMapDocStatus *this, CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0x6BCu, pParentWnd: pParent);
  this->__vftable = (CMapDocStatus_vtbl *)&CMapDocStatus::`vftable';
  CWnd::CWnd(this: &this->m_FileListCtrl);
  this->m_FileListCtrl.__vftable = (CListCtrl_vtbl *)&CListCtrl::`vftable';
  CWnd::CWnd(this: &this->m_StatusTextControl);
  this->m_StatusTextControl.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_SyncControl);
  this->m_SyncControl.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_AddControl);
  this->m_AddControl.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_CheckOutControl);
  this->m_CheckOutControl.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_DoneControl);
  this->m_DoneControl.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_RevertControl);
  this->m_RevertControl.__vftable = (CButton_vtbl *)&CButton::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101043A0
// Name: protected: virtual void CMapDocStatus::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDocStatus::DoDataExchange(CMapDocStatus *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x44A, rControl: (HWND__ *)&this->m_FileListCtrl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x6B0, rControl: (HWND__ *)&this->m_StatusTextControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x6AF, rControl: (HWND__ *)&this->m_SyncControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x6BE, rControl: (HWND__ *)&this->m_AddControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x6BD, rControl: (HWND__ *)&this->m_CheckOutControl);
  DDX_Control(pDX, nIDC: (HWND__ *)2, rControl: (HWND__ *)&this->m_DoneControl);
  DDX_Control(pDX, nIDC: (HWND__ *)0x6B2, rControl: (HWND__ *)&this->m_RevertControl);
}

//------------------------------------------------------------------------------
// Address: 0x10104430
// Name: public: void CMapDocStatus::OnNMRclickFileList(struct tagNMHDR __near *,long __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDocStatus::OnNMRclickFileList(CMapDocStatus *this, tagNMHDR *pNMHDR, int *pResult)
{
  signed int v3; // esi
  CListCtrl *p_m_FileListCtrl; // ecx

  v3 = 0;
  for ( *pResult = 0; v3 < SendMessageA(hWnd: this->m_FileListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0); ++v3 )
  {
    p_m_FileListCtrl = &this->m_FileListCtrl;
    if ( this->m_bSelectAll )
      CListCtrl::SetItemState(this: p_m_FileListCtrl, nItem: v3, nState: 0x2000u, nStateMask: 0xF000u);
    else
      CListCtrl::SetItemState(this: p_m_FileListCtrl, nItem: v3, nState: 0x1000u, nStateMask: 0xF000u);
  }
  this->m_bSelectAll = !this->m_bSelectAll;
}

//------------------------------------------------------------------------------
// Address: 0x101044C0
// Name: public: void CMapDocStatus::OnShowWindow(int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDocStatus::OnShowWindow(CMapDocStatus *this, int bShow, int nStatus)
{
  CWnd::Default(this);
  this->m_bSelectAll = true;
}

//------------------------------------------------------------------------------
// Address: 0x10104610
// Name: public: CMapDocCheckin::CMapDocCheckin(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CMapDocCheckin *__thiscall CMapDocCheckin::CMapDocCheckin(CMapDocCheckin *this, CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0x6BBu, pParentWnd: pParent);
  this->__vftable = (CMapDocCheckin_vtbl *)&CMapDocCheckin::`vftable';
  this->m_FileList.m_Memory.m_pMemory = nullptr;
  this->m_FileList.m_Memory.m_nAllocationCount = 0;
  this->m_FileList.m_Memory.m_nGrowSize = 0;
  this->m_FileList.m_Size = 0;
  this->m_FileList.m_pElements = this->m_FileList.m_Memory.m_pMemory;
  CWnd::CWnd(this: &this->m_CheckinListCtrl);
  this->m_CheckinListCtrl.__vftable = (CListCtrl_vtbl *)&CListCtrl::`vftable';
  CWnd::CWnd(this: &this->m_DescriptionCtrl);
  this->m_DescriptionCtrl.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_CheckInStatusControl);
  this->m_CheckInStatusControl.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_SubmitButtonControl);
  this->m_SubmitButtonControl.__vftable = (CButton_vtbl *)&CButton::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10104700
// Name: public: virtual CMapDocCheckin::~CMapDocCheckin(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDocCheckin::~CMapDocCheckin(CMapDocCheckin *this)
{
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int> > *p_m_FileList; // esi

  this->__vftable = (CMapDocCheckin_vtbl *)&CMapDocCheckin::`vftable';
  CButton::~CButton(this: &this->m_SubmitButtonControl);
  CStatic::~CStatic(this: &this->m_CheckInStatusControl);
  CEdit::~CEdit(this: &this->m_DescriptionCtrl);
  CListCtrl::~CListCtrl(this: &this->m_CheckinListCtrl);
  p_m_FileList = &this->m_FileList;
  this->m_FileList.m_Size = 0;
  if ( this->m_FileList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_FileList->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_FileList->m_Memory.m_pMemory);
      p_m_FileList->m_Memory.m_pMemory = nullptr;
    }
    this->m_FileList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_FileList.m_pElements = this->m_FileList.m_Memory.m_pMemory;
  if ( this->m_FileList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_FileList->m_Memory.m_pMemory != nullptr )
    {
      free(pMem: p_m_FileList->m_Memory.m_pMemory);
      p_m_FileList->m_Memory.m_pMemory = nullptr;
    }
    this->m_FileList.m_Memory.m_nAllocationCount = 0;
  }
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x101047E0
// Name: protected: void CMapDocStatus::UpdateMapList(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDocStatus::UpdateMapList(CMapDocStatus *this, bool RedoList)
{
  AFX_MODULE_STATE *ModuleState; // eax
  CListCtrl *p_m_FileListCtrl; // edi
  AFX_MODULE_STATE *v5; // eax
  void *v6; // eax
  CMapDoc *v7; // ebx
  LRESULT inserted; // eax
  WPARAM v9; // esi
  __int16 v10; // ecx^2
  const char *(__thiscall *String)(IP4 *, CUtlSymbol); // eax
  char *v12; // eax
  __int16 v13; // ecx^2
  const char *(__thiscall *v14)(IP4 *, CUtlSymbol); // eax
  char *v15; // eax
  char *m_pszData; // ebx
  int v17; // ecx
  char **v18; // ebx
  char *v19; // eax
  int v20; // eax
  int v21; // ecx
  char *v22; // ebx
  int v23; // eax
  int v24; // eax
  int v25; // ebx
  int v26; // eax
  int v27; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v28; // eax
  char *v29; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v30; // eax
  char *v31; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-E0h]
  char *v33[4]; // [esp-4h] [ebp-D4h] BYREF
  char temp[128]; // [esp+Ch] [ebp-C4h] BYREF
  P4File_t FileInfo; // [esp+8Ch] [ebp-44h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v36; // [esp+ACh] [ebp-24h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+B0h] [ebp-20h] BYREF
  __POSITION *pos; // [esp+B4h] [ebp-1Ch] BYREF
  int nCount; // [esp+B8h] [ebp-18h]
  char **v40; // [esp+BCh] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strMapFilename; // [esp+C0h] [ebp-10h] BYREF
  int v42; // [esp+CCh] [ebp-4h]

  v33[0] = nullptr;
  m_hWnd = this->m_FileListCtrl.m_hWnd;
  memset(&FileInfo, 255, 10);
  SendMessageA(hWnd: m_hWnd, Msg: 0x1009u, wParam: 0, lParam: 0);
  nCount = 0;
  ModuleState = AfxGetModuleState();
  pos = (__POSITION *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)ModuleState->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl
                                                          + 84))(a1: ModuleState->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl);
  if ( pos != nullptr )
  {
    p_m_FileListCtrl = &this->m_FileListCtrl;
    while ( 1 )
    {
      v5 = AfxGetModuleState();
      v6 = (void *)(*(int (__thiscall **)(unsigned int, __POSITION **))(*(_DWORD *)v5->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl
                                                                      + 88))(
                     a1: v5->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl,
                     a2: &pos);
      v7 = (CMapDoc *)__RTDynamicCast(
                        inptr: v6,
                        VfDelta: 0,
                        SrcType: &CDocument `RTTI Type Descriptor',
                        TargetType: &CMapDoc `RTTI Type Descriptor',
                        isReference: 0);
      CMapDoc::CheckFileStatus(this: v7);
      inserted = CListCtrl::InsertItem(
                   this: p_m_FileListCtrl,
                   nMask: 1u,
                   nItem: nCount++,
                   lpszItem: (char *)&var,
                   nState: 0,
                   nStateMask: 0,
                   nImage: 0,
                   lParam: 0);
      v9 = inserted;
      CListCtrl::SetItem(
        this: p_m_FileListCtrl,
        nItem: inserted,
        nSubItem: 0,
        nMask: 4u,
        lpszItem: nullptr,
        nImage: 0,
        nState: 0,
        nStateMask: 0,
        lParam: (int)v7);
      if ( p4 == nullptr
        || Options.general.bEnablePerforceIntegration != 1
        || ((unsigned __int8 (__stdcall *)(char *, P4File_t *))p4->GetFileInfo)(
             a1: v7->m_strPathName.m_pszData,
             a2: &FileInfo) != 1 )
      {
        if ( v7->m_bReadOnly )
          v33[0] = "Read Only";
        else
          v33[0] = "Writeable";
        CListCtrl::SetItemText(this: p_m_FileListCtrl, nItem: v9, nSubItem: 1, lpszText: v33[0]);
        m_pszData = v7->m_strPathName.m_pszData;
        v17 = *((_DWORD *)m_pszData - 4);
        v18 = (char **)(m_pszData - 16);
        v19 = (char *)(*(int (__thiscall **)(int))(*(_DWORD *)v17 + 16))(a1: v17);
        if ( (int)v18[3] >= 0 && v19 == *v18 )
        {
          _InterlockedExchangeAdd((volatile signed __int32 *)v18 + 3, 1u);
        }
        else
        {
          v20 = (**(int (__thiscall ***)(char *, char *, int))v19)(a1: v19, a2: v18[1], a3: 1);
          v40 = (char **)v20;
          if ( v20 == 0 )
            ATL::CSimpleStringT<char,0>::ThrowMemoryException(a1: v21);
          *(_DWORD *)(v20 + 4) = v18[1];
          memcpy_s(
            dst: (void *)(v20 + 16),
            sizeInBytes: (unsigned int)(v18[1] + 1),
            src: v18 + 4,
            count: (unsigned int)(v18[1] + 1));
          v18 = v40;
        }
        v22 = (char *)(v18 + 4);
        strMapFilename.m_pszData = v22;
        v42 = 1;
        if ( *((_DWORD *)v22 - 3) != 0 )
        {
          _mbsrchr(str: (unsigned __int8 *)v22, c: 0x5Cu);
          if ( v23 != 0 )
            v24 = v23 - (_DWORD)v22;
          else
            v24 = -1;
          v25 = v24 + 1;
          if ( *((int *)strMapFilename.m_pszData - 3) > 0 )
          {
            _mbschr(string: strMapFilename.m_pszData, c: 0x2Eu);
            if ( v27 != 0 )
              v26 = v27 - (unsigned int)strMapFilename.m_pszData;
            else
              v26 = -1;
          }
          else
          {
            v26 = -1;
          }
          v28 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Mid(
                  this: &strMapFilename,
                  &result,
                  iFirst: v25,
                  nCount: v26 - v25);
          LOBYTE(v42) = 2;
          CListCtrl::SetItemText(this: p_m_FileListCtrl, nItem: v9, nSubItem: 3, lpszText: v28->m_pszData);
          LOBYTE(v42) = 1;
          v29 = result.m_pszData - 16;
          if ( _InterlockedDecrement((volatile signed __int32 *)result.m_pszData - 1) <= 0 )
            (*(void (__stdcall **)(char *))(**(_DWORD **)v29 + 4))(a1: v29);
          v30 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Mid(
                  this: &strMapFilename,
                  result: &v36,
                  iFirst: 0,
                  nCount: v25 - 1);
          LOBYTE(v42) = 4;
          CListCtrl::SetItemText(this: p_m_FileListCtrl, nItem: v9, nSubItem: 4, lpszText: v30->m_pszData);
          LOBYTE(v42) = 1;
          v31 = v36.m_pszData - 16;
          if ( _InterlockedDecrement((volatile signed __int32 *)v36.m_pszData - 1) <= 0 )
            (*(void (__stdcall **)(char *))(**(_DWORD **)v31 + 4))(a1: v31);
          v22 = strMapFilename.m_pszData;
        }
        else
        {
          CListCtrl::SetItemText(this: p_m_FileListCtrl, nItem: v9, nSubItem: 3, lpszText: "not saved");
          CListCtrl::SetItemText(this: p_m_FileListCtrl, nItem: v9, nSubItem: 4, lpszText: (char *)&var);
        }
        v42 = -1;
        if ( _InterlockedDecrement((volatile signed __int32 *)v22 - 1) <= 0 )
          (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)v22 - 4) + 4))(a1: *((_DWORD *)v22 - 4), a2: v22 - 16);
        goto LABEL_44;
      }
      if ( FileInfo.m_eOpenState == P4FILE_UNOPENED )
      {
        if ( v7->m_bReadOnly )
          v33[0] = "Read Only";
        else
          v33[0] = "Writeable";
        goto LABEL_14;
      }
      if ( FileInfo.m_eOpenState == P4FILE_OPENED_FOR_ADD )
        break;
      if ( FileInfo.m_eOpenState == P4FILE_OPENED_FOR_EDIT )
      {
        v33[0] = "Edit";
LABEL_14:
        CListCtrl::SetItemText(this: p_m_FileListCtrl, nItem: v9, nSubItem: 1, lpszText: v33[0]);
      }
      if ( FileInfo.m_iHaveRevision == FileInfo.m_iHeadRevision )
        sprintf(string: temp, format: "%d", FileInfo.m_iHaveRevision);
      else
        sprintf(string: temp, format: "%d / %d", FileInfo.m_iHaveRevision, FileInfo.m_iHeadRevision);
      CListCtrl::SetItemText(this: p_m_FileListCtrl, nItem: v9, nSubItem: 2, lpszText: temp);
      HIWORD(v33[0]) = v10;
      LOWORD(v33[0]) = FileInfo.m_sName.m_Id;
      String = p4->String;
      v40 = v33;
      v12 = (char *)((int (__thiscall *)(IP4 *, char *))String)(a1: p4, a2: v33[0]);
      CListCtrl::SetItemText(this: p_m_FileListCtrl, nItem: v9, nSubItem: 3, lpszText: v12);
      HIWORD(v33[0]) = v13;
      LOWORD(v33[0]) = FileInfo.m_sPath.m_Id;
      v14 = p4->String;
      v40 = v33;
      v15 = (char *)((int (__thiscall *)(IP4 *, char *))v14)(a1: p4, a2: v33[0]);
      CListCtrl::SetItemText(this: p_m_FileListCtrl, nItem: v9, nSubItem: 4, lpszText: v15);
LABEL_44:
      if ( pos == nullptr )
        return;
    }
    v33[0] = "Add";
    goto LABEL_14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10104BB0
// Name: public: void CMapDocStatus::OnBnClickedCheckout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDocStatus::OnBnClickedCheckout(CMapDocStatus *this)
{
  signed int v1; // edi
  int v3; // edi
  void *v4; // esp
  HWND__ *v5; // eax
  LRESULT v6; // edi
  const char *v7; // edx
  int v8; // eax
  int v9; // edi
  const char *v10; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-83Ch]
  int v12; // [esp+0h] [ebp-82Ch] BYREF
  char temp[2048]; // [esp+Ch] [ebp-820h] BYREF
  CWnd *p_m_SyncControl; // [esp+80Ch] [ebp-20h]
  CWnd *p_m_DoneControl; // [esp+810h] [ebp-1Ch]
  const char **ppFileNames; // [esp+814h] [ebp-18h]
  CWnd *p_m_RevertControl; // [esp+818h] [ebp-14h]
  CWnd *p_m_StatusTextControl; // [esp+81Ch] [ebp-10h]
  CWnd *p_m_CheckOutControl; // [esp+820h] [ebp-Ch]
  CWnd *p_m_AddControl; // [esp+824h] [ebp-8h]
  int nFileCount; // [esp+828h] [ebp-4h]

  v1 = 0;
  if ( p4 != nullptr && Options.general.bEnablePerforceIntegration != 0 )
  {
    m_hWnd = this->m_FileListCtrl.m_hWnd;
    nFileCount = 0;
    if ( SendMessageA(hWnd: m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) > 0 )
    {
      do
      {
        if ( SendMessageA(hWnd: this->m_FileListCtrl.m_hWnd, Msg: 0x102Cu, wParam: v1, lParam: 61440) == 0x2000 )
          ++nFileCount;
        ++v1;
      }
      while ( v1 < SendMessageA(hWnd: this->m_FileListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) );
      v3 = nFileCount;
      if ( nFileCount > 0 )
      {
        sprintf(string: temp, format: "Checking out %d file(s).  Please wait...", nFileCount);
        p_m_StatusTextControl = &this->m_StatusTextControl;
        CWnd::SetWindowTextA(this: &this->m_StatusTextControl, lpszString: temp);
        p_m_SyncControl = &this->m_SyncControl;
        CWnd::EnableWindow(this: &this->m_SyncControl, bEnable: 0);
        p_m_AddControl = &this->m_AddControl;
        CWnd::EnableWindow(this: &this->m_AddControl, bEnable: 0);
        p_m_CheckOutControl = &this->m_CheckOutControl;
        CWnd::EnableWindow(this: &this->m_CheckOutControl, bEnable: 0);
        p_m_RevertControl = &this->m_RevertControl;
        CWnd::EnableWindow(this: &this->m_RevertControl, bEnable: 0);
        p_m_DoneControl = &this->m_DoneControl;
        CWnd::EnableWindow(this: &this->m_DoneControl, bEnable: 0);
        v4 = alloca(4 * v3);
        v5 = this->m_FileListCtrl.m_hWnd;
        ppFileNames = (const char **)&v12;
        v6 = 0;
        nFileCount = 0;
        if ( SendMessageA(hWnd: v5, Msg: 0x1004u, wParam: 0, lParam: 0) > 0 )
        {
          do
          {
            if ( SendMessageA(hWnd: this->m_FileListCtrl.m_hWnd, Msg: 0x102Cu, wParam: v6, lParam: 61440) == 0x2000 )
            {
              v7 = *(const char **)(CListCtrl::GetItemData(this: &this->m_FileListCtrl, nItem: v6) + 36);
              v8 = nFileCount;
              ppFileNames[nFileCount] = v7;
              nFileCount = v8 + 1;
            }
            ++v6;
          }
          while ( v6 < SendMessageA(hWnd: this->m_FileListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) );
        }
        v9 = nFileCount;
        if ( p4->OpenFilesForEdit(this: p4, a2: nFileCount, a3: ppFileNames) )
        {
          CMapDocStatus::UpdateMapList(this, RedoList: false);
          sprintf(string: temp, format: "Checked out %d file(s).", v9);
          CWnd::SetWindowTextA(this: p_m_StatusTextControl, lpszString: temp);
          CWnd::EnableWindow(this: p_m_SyncControl, bEnable: 1);
          CWnd::EnableWindow(this: p_m_AddControl, bEnable: 1);
          CWnd::EnableWindow(this: p_m_CheckOutControl, bEnable: 1);
          CWnd::EnableWindow(this: p_m_RevertControl, bEnable: 1);
          CWnd::EnableWindow(this: p_m_DoneControl, bEnable: 1);
        }
        else
        {
          CWnd::SetWindowTextA(this: p_m_StatusTextControl, lpszString: "Checkout FAILED.");
          CWnd::EnableWindow(this: p_m_SyncControl, bEnable: 1);
          CWnd::EnableWindow(this: p_m_AddControl, bEnable: 1);
          CWnd::EnableWindow(this: p_m_CheckOutControl, bEnable: 1);
          CWnd::EnableWindow(this: p_m_RevertControl, bEnable: 1);
          CWnd::EnableWindow(this: p_m_DoneControl, bEnable: 1);
          v10 = p4->GetLastError(this: p4);
          sprintf(string: temp, format: "Could not check out map(s): %s", v10);
          AfxMessageBox(lpszText: temp, nType: 0x10u, nIDHelp: 0);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10104E60
// Name: public: void CMapDocStatus::OnBnClickedAdd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDocStatus::OnBnClickedAdd(CMapDocStatus *this)
{
  signed int v1; // edi
  int v3; // edi
  void *v4; // esp
  HWND__ *v5; // eax
  LRESULT v6; // edi
  const char *v7; // edx
  int v8; // eax
  int v9; // edi
  const char *v10; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-83Ch]
  int v12; // [esp+0h] [ebp-82Ch] BYREF
  char temp[2048]; // [esp+Ch] [ebp-820h] BYREF
  CWnd *p_m_SyncControl; // [esp+80Ch] [ebp-20h]
  CWnd *p_m_DoneControl; // [esp+810h] [ebp-1Ch]
  const char **ppFileNames; // [esp+814h] [ebp-18h]
  CWnd *p_m_RevertControl; // [esp+818h] [ebp-14h]
  CWnd *p_m_StatusTextControl; // [esp+81Ch] [ebp-10h]
  CWnd *p_m_CheckOutControl; // [esp+820h] [ebp-Ch]
  CWnd *p_m_AddControl; // [esp+824h] [ebp-8h]
  int nFileCount; // [esp+828h] [ebp-4h]

  v1 = 0;
  if ( p4 != nullptr && Options.general.bEnablePerforceIntegration != 0 )
  {
    m_hWnd = this->m_FileListCtrl.m_hWnd;
    nFileCount = 0;
    if ( SendMessageA(hWnd: m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) > 0 )
    {
      do
      {
        if ( SendMessageA(hWnd: this->m_FileListCtrl.m_hWnd, Msg: 0x102Cu, wParam: v1, lParam: 61440) == 0x2000 )
          ++nFileCount;
        ++v1;
      }
      while ( v1 < SendMessageA(hWnd: this->m_FileListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) );
      v3 = nFileCount;
      if ( nFileCount > 0 )
      {
        sprintf(string: temp, format: "Adding %d file(s).  Please wait...", nFileCount);
        p_m_StatusTextControl = &this->m_StatusTextControl;
        CWnd::SetWindowTextA(this: &this->m_StatusTextControl, lpszString: temp);
        p_m_SyncControl = &this->m_SyncControl;
        CWnd::EnableWindow(this: &this->m_SyncControl, bEnable: 0);
        p_m_AddControl = &this->m_AddControl;
        CWnd::EnableWindow(this: &this->m_AddControl, bEnable: 0);
        p_m_CheckOutControl = &this->m_CheckOutControl;
        CWnd::EnableWindow(this: &this->m_CheckOutControl, bEnable: 0);
        p_m_RevertControl = &this->m_RevertControl;
        CWnd::EnableWindow(this: &this->m_RevertControl, bEnable: 0);
        p_m_DoneControl = &this->m_DoneControl;
        CWnd::EnableWindow(this: &this->m_DoneControl, bEnable: 0);
        v4 = alloca(4 * v3);
        v5 = this->m_FileListCtrl.m_hWnd;
        ppFileNames = (const char **)&v12;
        v6 = 0;
        nFileCount = 0;
        if ( SendMessageA(hWnd: v5, Msg: 0x1004u, wParam: 0, lParam: 0) > 0 )
        {
          do
          {
            if ( SendMessageA(hWnd: this->m_FileListCtrl.m_hWnd, Msg: 0x102Cu, wParam: v6, lParam: 61440) == 0x2000 )
            {
              v7 = *(const char **)(CListCtrl::GetItemData(this: &this->m_FileListCtrl, nItem: v6) + 36);
              v8 = nFileCount;
              ppFileNames[nFileCount] = v7;
              nFileCount = v8 + 1;
            }
            ++v6;
          }
          while ( v6 < SendMessageA(hWnd: this->m_FileListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) );
        }
        v9 = nFileCount;
        if ( p4->OpenFilesForAdd(this: p4, a2: nFileCount, a3: ppFileNames) )
        {
          CMapDocStatus::UpdateMapList(this, RedoList: false);
          sprintf(string: temp, format: "Added %d file(s).", v9);
          CWnd::SetWindowTextA(this: p_m_StatusTextControl, lpszString: temp);
          CWnd::EnableWindow(this: p_m_SyncControl, bEnable: 1);
          CWnd::EnableWindow(this: p_m_AddControl, bEnable: 1);
          CWnd::EnableWindow(this: p_m_CheckOutControl, bEnable: 1);
          CWnd::EnableWindow(this: p_m_RevertControl, bEnable: 1);
          CWnd::EnableWindow(this: p_m_DoneControl, bEnable: 1);
        }
        else
        {
          CWnd::SetWindowTextA(this: p_m_StatusTextControl, lpszString: "Adding FAILED.");
          CWnd::EnableWindow(this: p_m_SyncControl, bEnable: 1);
          CWnd::EnableWindow(this: p_m_AddControl, bEnable: 1);
          CWnd::EnableWindow(this: p_m_CheckOutControl, bEnable: 1);
          CWnd::EnableWindow(this: p_m_RevertControl, bEnable: 1);
          CWnd::EnableWindow(this: p_m_DoneControl, bEnable: 1);
          v10 = p4->GetLastError(this: p4);
          sprintf(string: temp, format: "Could not add map(s): %s", v10);
          AfxMessageBox(lpszText: temp, nType: 0x10u, nIDHelp: 0);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10105100
// Name: public: void CMapDocStatus::OnBnClickedSync(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDocStatus::OnBnClickedSync(CMapDocStatus *this)
{
  signed int v1; // ebx
  HWND__ *m_hWnd; // eax
  LRESULT v4; // ebx
  CMapDoc *ItemData; // eax
  HWND__ *v6; // [esp-14h] [ebp-83Ch]
  char temp[2048]; // [esp+8h] [ebp-820h] BYREF
  CWnd *p_m_SyncControl; // [esp+808h] [ebp-20h]
  CWnd *p_m_DoneControl; // [esp+80Ch] [ebp-1Ch]
  CWnd *p_m_StatusTextControl; // [esp+810h] [ebp-18h]
  CWnd *p_m_RevertControl; // [esp+814h] [ebp-14h]
  CWnd *p_m_CheckOutControl; // [esp+818h] [ebp-10h]
  CWnd *p_m_AddControl; // [esp+81Ch] [ebp-Ch]
  int nSyncFileCount; // [esp+820h] [ebp-8h]
  int nFileCount; // [esp+824h] [ebp-4h]

  v1 = 0;
  if ( p4 != nullptr && Options.general.bEnablePerforceIntegration != 0 )
  {
    m_hWnd = this->m_FileListCtrl.m_hWnd;
    nFileCount = 0;
    if ( SendMessageA(hWnd: m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) > 0 )
    {
      do
      {
        if ( SendMessageA(hWnd: this->m_FileListCtrl.m_hWnd, Msg: 0x102Cu, wParam: v1, lParam: 61440) == 0x2000 )
          ++nFileCount;
        ++v1;
      }
      while ( v1 < SendMessageA(hWnd: this->m_FileListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) );
      v4 = 0;
      if ( nFileCount > 0 )
      {
        sprintf(string: temp, format: "Syncing %d file(s).  Please wait...", nFileCount);
        p_m_StatusTextControl = &this->m_StatusTextControl;
        CWnd::SetWindowTextA(this: &this->m_StatusTextControl, lpszString: temp);
        p_m_SyncControl = &this->m_SyncControl;
        CWnd::EnableWindow(this: &this->m_SyncControl, bEnable: 0);
        p_m_AddControl = &this->m_AddControl;
        CWnd::EnableWindow(this: &this->m_AddControl, bEnable: 0);
        p_m_CheckOutControl = &this->m_CheckOutControl;
        CWnd::EnableWindow(this: &this->m_CheckOutControl, bEnable: 0);
        p_m_RevertControl = &this->m_RevertControl;
        CWnd::EnableWindow(this: &this->m_RevertControl, bEnable: 0);
        p_m_DoneControl = &this->m_DoneControl;
        CWnd::EnableWindow(this: &this->m_DoneControl, bEnable: 0);
        v6 = this->m_FileListCtrl.m_hWnd;
        nSyncFileCount = 0;
        if ( SendMessageA(hWnd: v6, Msg: 0x1004u, wParam: 0, lParam: 0) > 0 )
        {
          do
          {
            if ( SendMessageA(hWnd: this->m_FileListCtrl.m_hWnd, Msg: 0x102Cu, wParam: v4, lParam: 61440) == 0x2000 )
            {
              ItemData = (CMapDoc *)CListCtrl::GetItemData(this: &this->m_FileListCtrl, nItem: v4);
              if ( CMapDoc::SyncToHeadRevision(this: ItemData) == 1 )
                ++nSyncFileCount;
            }
            ++v4;
          }
          while ( v4 < SendMessageA(hWnd: this->m_FileListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) );
        }
        CMapDocStatus::UpdateMapList(this, RedoList: false);
        if ( CMapDoc::m_pMapDoc != nullptr )
          CMapDoc::UpdateAllViews(this: CMapDoc::m_pMapDoc, nFlags: 2072, ub: nullptr);
        if ( nSyncFileCount == nFileCount )
          sprintf(string: temp, format: "Synced %d file(s).", nSyncFileCount);
        else
          sprintf(
            string: temp,
            format: "Synced %d file(s).  %d file(s) were not synced!",
            nSyncFileCount,
            nFileCount - nSyncFileCount);
        CWnd::SetWindowTextA(this: p_m_StatusTextControl, lpszString: temp);
        CWnd::EnableWindow(this: p_m_SyncControl, bEnable: 1);
        CWnd::EnableWindow(this: p_m_AddControl, bEnable: 1);
        CWnd::EnableWindow(this: p_m_CheckOutControl, bEnable: 1);
        CWnd::EnableWindow(this: p_m_RevertControl, bEnable: 1);
        CWnd::EnableWindow(this: p_m_DoneControl, bEnable: 1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10105310
// Name: public: void CMapDocStatus::OnBnClickedRevert(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDocStatus::OnBnClickedRevert(CMapDocStatus *this)
{
  signed int v1; // ebx
  HWND__ *m_hWnd; // eax
  LRESULT v4; // ebx
  CMapDoc *ItemData; // eax
  HWND__ *v6; // [esp-14h] [ebp-83Ch]
  char temp[2048]; // [esp+8h] [ebp-820h] BYREF
  CWnd *p_m_SyncControl; // [esp+808h] [ebp-20h]
  CWnd *p_m_DoneControl; // [esp+80Ch] [ebp-1Ch]
  CWnd *p_m_StatusTextControl; // [esp+810h] [ebp-18h]
  CWnd *p_m_RevertControl; // [esp+814h] [ebp-14h]
  CWnd *p_m_CheckOutControl; // [esp+818h] [ebp-10h]
  CWnd *p_m_AddControl; // [esp+81Ch] [ebp-Ch]
  int nRevertFileCount; // [esp+820h] [ebp-8h]
  int nFileCount; // [esp+824h] [ebp-4h]

  v1 = 0;
  if ( p4 != nullptr && Options.general.bEnablePerforceIntegration != 0 )
  {
    m_hWnd = this->m_FileListCtrl.m_hWnd;
    nFileCount = 0;
    if ( SendMessageA(hWnd: m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) > 0 )
    {
      do
      {
        if ( SendMessageA(hWnd: this->m_FileListCtrl.m_hWnd, Msg: 0x102Cu, wParam: v1, lParam: 61440) == 0x2000 )
          ++nFileCount;
        ++v1;
      }
      while ( v1 < SendMessageA(hWnd: this->m_FileListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) );
      if ( nFileCount > 0
        && AfxMessageBox(lpszText: "Are you sure you want to revert these file(s)?", nType: 0x24u, nIDHelp: 0) != 7 )
      {
        sprintf(string: temp, format: "Reverting %d file(s).  Please wait...", nFileCount);
        p_m_StatusTextControl = &this->m_StatusTextControl;
        CWnd::SetWindowTextA(this: &this->m_StatusTextControl, lpszString: temp);
        v4 = 0;
        p_m_SyncControl = &this->m_SyncControl;
        CWnd::EnableWindow(this: &this->m_SyncControl, bEnable: 0);
        p_m_AddControl = &this->m_AddControl;
        CWnd::EnableWindow(this: &this->m_AddControl, bEnable: 0);
        p_m_CheckOutControl = &this->m_CheckOutControl;
        CWnd::EnableWindow(this: &this->m_CheckOutControl, bEnable: 0);
        p_m_RevertControl = &this->m_RevertControl;
        CWnd::EnableWindow(this: &this->m_RevertControl, bEnable: 0);
        p_m_DoneControl = &this->m_DoneControl;
        CWnd::EnableWindow(this: &this->m_DoneControl, bEnable: 0);
        v6 = this->m_FileListCtrl.m_hWnd;
        nRevertFileCount = 0;
        if ( SendMessageA(hWnd: v6, Msg: 0x1004u, wParam: 0, lParam: 0) > 0 )
        {
          do
          {
            if ( SendMessageA(hWnd: this->m_FileListCtrl.m_hWnd, Msg: 0x102Cu, wParam: v4, lParam: 61440) == 0x2000 )
            {
              ItemData = (CMapDoc *)CListCtrl::GetItemData(this: &this->m_FileListCtrl, nItem: v4);
              if ( CMapDoc::Revert(this: ItemData) == 1 )
                ++nRevertFileCount;
            }
            ++v4;
          }
          while ( v4 < SendMessageA(hWnd: this->m_FileListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) );
        }
        CMapDocStatus::UpdateMapList(this, RedoList: false);
        if ( CMapDoc::m_pMapDoc != nullptr )
          CMapDoc::UpdateAllViews(this: CMapDoc::m_pMapDoc, nFlags: 2072, ub: nullptr);
        if ( nRevertFileCount == nFileCount )
          sprintf(string: temp, format: "Reverted %d file(s).", nRevertFileCount);
        else
          sprintf(
            string: temp,
            format: "Reverted %d file(s).  %d file(s) were not reverted!",
            nRevertFileCount,
            nFileCount - nRevertFileCount);
        CWnd::SetWindowTextA(this: p_m_StatusTextControl, lpszString: temp);
        CWnd::EnableWindow(this: p_m_SyncControl, bEnable: 1);
        CWnd::EnableWindow(this: p_m_AddControl, bEnable: 1);
        CWnd::EnableWindow(this: p_m_CheckOutControl, bEnable: 1);
        CWnd::EnableWindow(this: p_m_RevertControl, bEnable: 1);
        CWnd::EnableWindow(this: p_m_DoneControl, bEnable: 1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10105570
// Name: protected: void CMapDocCheckin::AddFileToList(class CMapDoc __near *,struct P4File_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDocCheckin::AddFileToList(CMapDocCheckin *this, CMapDoc *pMapDoc, P4File_t *FileInfo)
{
  LRESULT v4; // eax
  CListCtrl *p_m_CheckinListCtrl; // esi
  LRESULT inserted; // edi
  __int16 v7; // ecx^2
  char *v8; // eax
  __int16 v9; // ecx^2
  char *v10; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-5Ch]
  HWND v12; // [esp-10h] [ebp-5Ch]
  int v13; // [esp-4h] [ebp-50h]
  int v14; // [esp-4h] [ebp-50h]
  tagLVITEMA _macro_lvi; // [esp+Ch] [ebp-40h] BYREF
  CMapDocCheckin *v16; // [esp+48h] [ebp-4h]

  m_hWnd = this->m_CheckinListCtrl.m_hWnd;
  v16 = this;
  v4 = SendMessageA(hWnd: m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0);
  p_m_CheckinListCtrl = &this->m_CheckinListCtrl;
  inserted = CListCtrl::InsertItem(
               this: p_m_CheckinListCtrl,
               nMask: 1u,
               nItem: v4,
               lpszItem: (char *)&var,
               nState: 0,
               nStateMask: 0,
               nImage: 0,
               lParam: 0);
  CListCtrl::SetItem(
    this: p_m_CheckinListCtrl,
    nItem: inserted,
    nSubItem: 0,
    nMask: 4u,
    lpszItem: nullptr,
    nImage: 0,
    nState: 0,
    nStateMask: 0,
    lParam: (int)pMapDoc);
  if ( FileInfo->m_eOpenState == P4FILE_OPENED_FOR_ADD )
  {
    CListCtrl::SetItemText(this: p_m_CheckinListCtrl, nItem: inserted, nSubItem: 1, lpszText: "Add");
  }
  else if ( FileInfo->m_eOpenState == P4FILE_OPENED_FOR_EDIT )
  {
    CListCtrl::SetItemText(this: p_m_CheckinListCtrl, nItem: inserted, nSubItem: 1, lpszText: "Edit");
  }
  HIWORD(v13) = v7;
  LOWORD(v13) = FileInfo->m_sName.m_Id;
  v8 = (char *)((int (__thiscall *)(IP4 *, int))p4->String)(a1: p4, a2: v13);
  CListCtrl::SetItemText(this: p_m_CheckinListCtrl, nItem: inserted, nSubItem: 2, lpszText: v8);
  HIWORD(v14) = v9;
  LOWORD(v14) = FileInfo->m_sPath.m_Id;
  v10 = (char *)((int (__thiscall *)(IP4 *, int))p4->String)(a1: p4, a2: v14);
  CListCtrl::SetItemText(this: p_m_CheckinListCtrl, nItem: inserted, nSubItem: 3, lpszText: v10);
  CUtlVector<CUtlSymbol,CUtlMemory<CUtlSymbol,int>>::InsertBefore(
    this: &v16->m_FileList,
    elem: v16->m_FileList.m_Size,
    src: &FileInfo->m_sLocalFile);
  if ( pMapDoc != nullptr && pMapDoc->m_bDefaultCheckin )
  {
    v12 = v16->m_CheckinListCtrl.m_hWnd;
    _macro_lvi.stateMask = 61440;
    _macro_lvi.state = 0x2000;
    SendMessageA(hWnd: v12, Msg: 0x102Bu, wParam: inserted, lParam: (LPARAM)&_macro_lvi);
    pMapDoc->m_bDefaultCheckin = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101056A0
// Name: public: virtual int CMapDocCheckin::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapDocCheckin::OnInitDialog(CMapDocCheckin *this)
{
  int v2; // edi
  LRESULT v3; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v5; // eax
  void *v6; // eax
  CMapDoc *v7; // eax
  CMapDoc *v8; // esi
  int m_Size; // edx
  int v10; // ecx
  CUtlSymbol *p_m_sClientFile; // eax
  int v12; // esi
  P4File_t *m_pMemory; // eax
  P4File_t FileInfo; // [esp+Ch] [ebp-44h] BYREF
  CUtlVector<P4File_t,CUtlMemory<P4File_t,int> > FileList; // [esp+2Ch] [ebp-24h] BYREF
  __POSITION *pos; // [esp+40h] [ebp-10h] BYREF
  int v18; // [esp+4Ch] [ebp-4h]

  CDialog::OnInitDialog(this);
  v2 = 0;
  v3 = SendMessageA(hWnd: this->m_CheckinListCtrl.m_hWnd, Msg: 0x1037u, wParam: 0, lParam: 0);
  SendMessageA(hWnd: this->m_CheckinListCtrl.m_hWnd, Msg: 0x1036u, wParam: 0, lParam: v3 | 0x24);
  CListCtrl::InsertColumn(
    this: &this->m_CheckinListCtrl,
    nCol: 0,
    lpszColumnHeading: (char *)&var,
    nFormat: 0,
    nWidth: 30,
    nSubItem: -1);
  CListCtrl::InsertColumn(
    this: &this->m_CheckinListCtrl,
    nCol: 1u,
    lpszColumnHeading: "Status",
    nFormat: 0,
    nWidth: 50,
    nSubItem: -1);
  CListCtrl::InsertColumn(
    this: &this->m_CheckinListCtrl,
    nCol: 2u,
    lpszColumnHeading: "Name",
    nFormat: 0,
    nWidth: 180,
    nSubItem: -1);
  CListCtrl::InsertColumn(
    this: &this->m_CheckinListCtrl,
    nCol: 3u,
    lpszColumnHeading: "Folder",
    nFormat: 0,
    nWidth: 360,
    nSubItem: -1);
  if ( p4 != nullptr )
  {
    memset(&FileInfo, 255, 10);
    memset(&FileList, 0, sizeof(FileList));
    v18 = 1;
    p4->GetOpenedFileList_2(this: p4, a2: &FileList, a3: true);
    ModuleState = AfxGetModuleState();
    for ( pos = (__POSITION *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)ModuleState->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl
                                                                  + 84))(a1: ModuleState->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl);
          pos != nullptr;
          v2 = 0 )
    {
      v5 = AfxGetModuleState();
      v6 = (void *)(*(int (__thiscall **)(unsigned int, __POSITION **))(*(_DWORD *)v5->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl
                                                                      + 88))(
                     a1: v5->m_pCurrentWinApp[1].m_xConnPtContainer.m_vtbl,
                     a2: &pos);
      v7 = (CMapDoc *)__RTDynamicCast(
                        inptr: v6,
                        VfDelta: 0,
                        SrcType: &CDocument `RTTI Type Descriptor',
                        TargetType: &CMapDoc `RTTI Type Descriptor',
                        isReference: 0);
      v8 = v7;
      if ( v7 != nullptr
        && v7->m_bCheckedOut
        && p4->GetFileInfo(this: p4, a2: v7->m_strPathName.m_pszData, a3: &FileInfo) )
      {
        m_Size = FileList.m_Size;
        v10 = 0;
        if ( FileList.m_Size > 0 )
        {
          p_m_sClientFile = &FileList.m_Memory.m_pMemory->m_sClientFile;
          while ( p_m_sClientFile->m_Id != FileInfo.m_sClientFile.m_Id )
          {
            ++v10;
            p_m_sClientFile += 16;
            if ( v10 >= FileList.m_Size )
              goto LABEL_14;
          }
          if ( FileList.m_Size - v10 - 1 > 0 )
          {
            _V_memmove(
              dest: &FileList.m_Memory.m_pMemory[v10],
              src: &FileList.m_Memory.m_pMemory[v10 + 1],
              count: 32 * (FileList.m_Size - v10 - 1));
            m_Size = FileList.m_Size;
          }
          FileList.m_Size = m_Size - 1;
        }
LABEL_14:
        CMapDocCheckin::AddFileToList(this, pMapDoc: v8, &FileInfo);
      }
    }
    if ( FileList.m_Size > 0 )
    {
      v12 = 0;
      do
      {
        CMapDocCheckin::AddFileToList(this, pMapDoc: nullptr, FileInfo: &FileList.m_Memory.m_pMemory[v12]);
        ++v2;
        ++v12;
      }
      while ( v2 < FileList.m_Size );
    }
    v18 = 2;
    m_pMemory = FileList.m_Memory.m_pMemory;
    FileList.m_Size = 0;
    if ( FileList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( FileList.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: FileList.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        FileList.m_Memory.m_pMemory = nullptr;
      }
      FileList.m_Memory.m_nAllocationCount = 0;
    }
    FileList.m_pElements = m_pMemory;
    v18 = -1;
    if ( FileList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( FileList.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: FileList.m_Memory.m_pMemory);
        FileList.m_Memory.m_pMemory = nullptr;
      }
      FileList.m_Memory.m_nAllocationCount = 0;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10105920
// Name: public: void CMapDocCheckin::OnBnClickedSubmit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMapDocCheckin::OnBnClickedSubmit(CMapDocCheckin *this)
{
  LRESULT (__stdcall *v1)(HWND, UINT, WPARAM, LPARAM); // ebx
  signed int v2; // edi
  int v4; // edi
  CAfxStringMgr *StringManager; // eax
  int v6; // eax
  char *v7; // eax
  bool v8; // cc
  void *v9; // esp
  HWND__ *v10; // eax
  int v11; // edi
  _DWORD *ItemData; // ebx
  unsigned __int16 m_Id; // ax
  __int16 v14; // ecx^2
  const char *(__thiscall *String)(IP4 *, CUtlSymbol); // eax
  const char *v16; // eax
  const char *v17; // eax
  int i; // edi
  CMapDoc *v19; // eax
  char *v20; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-840h]
  int v22; // [esp-4h] [ebp-834h] BYREF
  int v23; // [esp+0h] [ebp-830h] BYREF
  char temp[2048]; // [esp+Ch] [ebp-824h] BYREF
  int *v25; // [esp+80Ch] [ebp-24h]
  CWnd *p_m_CheckInStatusControl; // [esp+810h] [ebp-20h]
  CWnd *p_m_SubmitButtonControl; // [esp+814h] [ebp-1Ch]
  const char **ppFileNames; // [esp+818h] [ebp-18h]
  int nFileCount; // [esp+81Ch] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > Description; // [esp+820h] [ebp-10h] BYREF
  int v31; // [esp+82Ch] [ebp-4h]

  v1 = SendMessageA;
  v2 = 0;
  v22 = 0;
  m_hWnd = this->m_CheckinListCtrl.m_hWnd;
  nFileCount = 0;
  if ( SendMessageA(hWnd: m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) <= 0 )
    goto LABEL_31;
  do
  {
    if ( SendMessageA(hWnd: this->m_CheckinListCtrl.m_hWnd, Msg: 0x102Cu, wParam: v2, lParam: 61440) == 0x2000 )
      ++nFileCount;
    ++v2;
  }
  while ( v2 < SendMessageA(hWnd: this->m_CheckinListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) );
  v4 = nFileCount;
  if ( nFileCount <= 0 )
    goto LABEL_31;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  Description.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v31 = 1;
  CWnd::GetWindowTextA(this: &this->m_DescriptionCtrl, rString: &Description);
  v6 = *((_DWORD *)Description.m_pszData - 3);
  if ( v6 < 2 )
  {
    CWnd::SetWindowTextA(this: &this->m_CheckInStatusControl, lpszString: "Checkin FAILED!");
    AfxMessageBox(
      lpszText: "Please put in something descriptive for the description.  I took the time to type this dialog, the least you could"
      " do is type something!",
      nType: 0x10u,
      nIDHelp: 0);
LABEL_10:
    v31 = -1;
    v7 = Description.m_pszData - 16;
    v8 = _InterlockedDecrement((volatile signed __int32 *)Description.m_pszData - 1) <= 0;
    goto LABEL_11;
  }
  if ( v6 >= 0x4000 )
  {
    CWnd::SetWindowTextA(this: &this->m_CheckInStatusControl, lpszString: "Checkin FAILED!");
    sprintf(
      string: temp,
      format: "Your description is too long.  Please shorten it down by %d characters.",
      *((_DWORD *)Description.m_pszData - 3) - 0x3FFF);
    AfxMessageBox(lpszText: temp, nType: 0x10u, nIDHelp: 0);
    goto LABEL_10;
  }
  p_m_SubmitButtonControl = &this->m_SubmitButtonControl;
  CWnd::EnableWindow(this: &this->m_SubmitButtonControl, bEnable: 0);
  sprintf(string: temp, format: "Checking in %d file(s).  Please wait...", nFileCount);
  p_m_CheckInStatusControl = &this->m_CheckInStatusControl;
  CWnd::SetWindowTextA(this: &this->m_CheckInStatusControl, lpszString: temp);
  v9 = alloca(4 * v4);
  v10 = this->m_CheckinListCtrl.m_hWnd;
  ppFileNames = (const char **)&v23;
  v11 = 0;
  nFileCount = 0;
  if ( SendMessageA(hWnd: v10, Msg: 0x1004u, wParam: 0, lParam: 0) > 0 )
  {
    do
    {
      if ( v1(hWnd: this->m_CheckinListCtrl.m_hWnd, Msg: 0x102Cu, wParam: v11, lParam: 61440) == 0x2000 )
      {
        ItemData = (_DWORD *)CListCtrl::GetItemData(this: &this->m_CheckinListCtrl, nItem: v11);
        m_Id = this->m_FileList.m_Memory.m_pMemory[v11].m_Id;
        HIWORD(v22) = v14;
        LOWORD(v22) = m_Id;
        String = p4->String;
        v25 = &v22;
        v16 = (const char *)((int (__thiscall *)(IP4 *, int))String)(a1: p4, a2: v22);
        if ( ItemData != nullptr )
        {
          ppFileNames[nFileCount] = (const char *)ItemData[9];
          (*(void (__thiscall **)(_DWORD *, _DWORD))(*ItemData + 128))(a1: ItemData, a2: ItemData[9]);
        }
        else
        {
          ppFileNames[nFileCount] = v16;
        }
        ++nFileCount;
        v1 = SendMessageA;
      }
      ++v11;
    }
    while ( v11 < v1(hWnd: this->m_CheckinListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0) );
  }
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Replace(this: &Description, chOld: 10, chNew: 9);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Replace(this: &Description, chOld: 13, chNew: 10);
  if ( p4->SubmitFiles(this: p4, a2: nFileCount, a3: ppFileNames, a4: Description.m_pszData) )
  {
    for ( i = 0; i < v1(hWnd: this->m_CheckinListCtrl.m_hWnd, Msg: 0x1004u, wParam: 0, lParam: 0); ++i )
    {
      if ( v1(hWnd: this->m_CheckinListCtrl.m_hWnd, Msg: 0x102Cu, wParam: i, lParam: 61440) == 0x2000 )
      {
        v19 = (CMapDoc *)CListCtrl::GetItemData(this: &this->m_CheckinListCtrl, nItem: i);
        if ( v19 != nullptr )
          CMapDoc::CheckFileStatus(this: v19);
      }
    }
    CWnd::EnableWindow(this: p_m_SubmitButtonControl, bEnable: 1);
    CWnd::SetWindowTextA(this: p_m_CheckInStatusControl, lpszString: &var);
    v31 = -1;
    v20 = Description.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)Description.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v20 + 4))(a1: v20);
LABEL_31:
    CDialog::EndDialog(this, nResult: 1);
    return;
  }
  CWnd::SetWindowTextA(this: p_m_CheckInStatusControl, lpszString: "Checkin FAILED!");
  CWnd::EnableWindow(this: p_m_SubmitButtonControl, bEnable: 1);
  v17 = p4->GetLastError(this: p4);
  sprintf(string: temp, format: "Could not check in map(s): %s", v17);
  AfxMessageBox(lpszText: temp, nType: 0x10u, nIDHelp: 0);
  v31 = -1;
  v7 = Description.m_pszData - 16;
  v8 = _InterlockedDecrement((volatile signed __int32 *)Description.m_pszData - 1) <= 0;
LABEL_11:
  if ( v8 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v7 + 4))(a1: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10105D00
// Name: public: virtual int CMapDocStatus::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMapDocStatus::OnInitDialog(CMapDocStatus *this)
{
  LRESULT v2; // eax
  CWnd *DlgItem; // eax
  CWnd *v4; // eax

  CDialog::OnInitDialog(this);
  v2 = SendMessageA(hWnd: this->m_FileListCtrl.m_hWnd, Msg: 0x1037u, wParam: 0, lParam: 0);
  SendMessageA(hWnd: this->m_FileListCtrl.m_hWnd, Msg: 0x1036u, wParam: 0, lParam: v2 | 0x24);
  CListCtrl::InsertColumn(
    this: &this->m_FileListCtrl,
    nCol: 0,
    lpszColumnHeading: (char *)&var,
    nFormat: 0,
    nWidth: 30,
    nSubItem: -1);
  CListCtrl::InsertColumn(
    this: &this->m_FileListCtrl,
    nCol: 1u,
    lpszColumnHeading: "Status",
    nFormat: 0,
    nWidth: 80,
    nSubItem: -1);
  CListCtrl::InsertColumn(
    this: &this->m_FileListCtrl,
    nCol: 2u,
    lpszColumnHeading: "Revision",
    nFormat: 0,
    nWidth: 70,
    nSubItem: -1);
  CListCtrl::InsertColumn(
    this: &this->m_FileListCtrl,
    nCol: 3u,
    lpszColumnHeading: "Name",
    nFormat: 0,
    nWidth: 150,
    nSubItem: -1);
  CListCtrl::InsertColumn(
    this: &this->m_FileListCtrl,
    nCol: 4u,
    lpszColumnHeading: "Folder",
    nFormat: 0,
    nWidth: 300,
    nSubItem: -1);
  CWnd::SetWindowTextA(this: &this->m_StatusTextControl, lpszString: &var);
  CWnd::EnableWindow(this: &this->m_SyncControl, bEnable: 1);
  CWnd::EnableWindow(this: &this->m_AddControl, bEnable: 1);
  CWnd::EnableWindow(this: &this->m_CheckOutControl, bEnable: 1);
  CWnd::EnableWindow(this: &this->m_RevertControl, bEnable: 1);
  CWnd::EnableWindow(this: &this->m_DoneControl, bEnable: 1);
  CMapDocStatus::UpdateMapList(this, RedoList: false);
  if ( Options.general.bEnablePerforceIntegration == 0 )
  {
    DlgItem = CWnd::GetDlgItem(this, nID: 1725);
    CWnd::EnableWindow(this: DlgItem, bEnable: 0);
    v4 = CWnd::GetDlgItem(this, nID: 1726);
    CWnd::EnableWindow(this: v4, bEnable: 0);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10105E50
// Name: protected: virtual struct AFX_MSGMAP const __near * CMapDocStatus::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMapDocStatus::GetMessageMap(CMapDocStatus *this)
{
  return (const AFX_MSGMAP *)&off_105F4EB0;
}

//------------------------------------------------------------------------------
// Address: 0x10105E60
// Name: protected: virtual struct AFX_MSGMAP const __near * CMapDocCheckin::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMapDocCheckin::GetMessageMap(CMapDocCheckin *this)
{
  return (const AFX_MSGMAP *)&off_105F4F6C;
}
