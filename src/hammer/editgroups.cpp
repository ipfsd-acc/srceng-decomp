// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/editgroups.cpp
// Functions: 49
// ============================================================

#include "hammer\editgroups.h"

//------------------------------------------------------------------------------
// Address: 0x100C5280
// Name: UpdateObjectColor
// Source: json
//------------------------------------------------------------------------------
int __cdecl UpdateObjectColor(CMapClass *pObject)
{
  pObject->UpdateObjectColor(this: pObject);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C52A0
// Name: public: virtual int CEditGroups::DestroyWindow(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CEditGroups::DestroyWindow@<eax>(CEditGroups *this@<ecx>, int a2@<edi>)
{
  CMainFrame *MainWnd; // eax

  MainWnd = GetMainWnd();
  CMainFrame::GlobalNotify(this: MainWnd, a2, nCode: 1026);
  return CWnd::DestroyWindow(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C52C0
// Name: public: virtual CCommonDialog::~CCommonDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommonDialog::~CCommonDialog(CCommonDialog *this)
{
  this->__vftable = (CCommonDialog_vtbl *)&CCommonDialog::`vftable';
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C5360
// Name: protected: virtual void CEditGroups::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGroups::DoDataExchange(CEditGroups *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F1, rControl: (HWND__ *)&this->m_cName);
}

//------------------------------------------------------------------------------
// Address: 0x100C5380
// Name: public: virtual CColorDialog::~CColorDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorDialog::~CColorDialog(CColorDialog *this)
{
  this->__vftable = (CColorDialog_vtbl *)&CCommonDialog::`vftable';
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C53C0
// Name: protected: void CEditGroups::UpdateGroupList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGroups::UpdateGroupList(CEditGroups *this)
{
  CMapDoc *v2; // edi
  int v3; // esi
  CVisGroup *VisGroup; // eax
  int nCount; // [esp+4h] [ebp-4h]

  if ( IsWindow(hWnd: this->m_hWnd) )
  {
    SendMessageA(hWnd: this->m_cGroupList.m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
    CTreeList::DeleteAllItems(this: &this->m_cGroupList);
    v2 = CMapDoc::m_pMapDoc;
    if ( CMapDoc::m_pMapDoc != nullptr )
    {
      v3 = 0;
      nCount = CMapDoc::VisGroups_GetCount(this: CMapDoc::m_pMapDoc);
      if ( nCount > 0 )
      {
        do
        {
          VisGroup = CMapDoc::VisGroups_GetVisGroup(this: v2, nIndex: v3);
          if ( VisGroup->m_pParent == nullptr )
            CGroupList::AddVisGroup(this: &this->m_cGroupList, pVisGroup: VisGroup);
          ++v3;
        }
        while ( v3 < nCount );
      }
    }
    CTreeList::ExpandAll(this: &this->m_cGroupList);
    SendMessageA(hWnd: this->m_cGroupList.m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
    InvalidateRect(hWnd: this->m_cGroupList.m_hWnd, lpRect: nullptr, bErase: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C5470
// Name: protected: void CEditGroups::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CEditGroups::OnClose(CEditGroups *this@<ecx>, int a2@<edi>)
{
  CMainFrame *MainWnd; // eax

  MainWnd = GetMainWnd();
  CMainFrame::GlobalNotify(this: MainWnd, a2, nCode: 1026);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C5490
// Name: public: CEditGroups::CEditGroups(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CEditGroups *__thiscall CEditGroups::CEditGroups(CEditGroups *this, CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0xA0u, pParentWnd: pParent);
  this->__vftable = (CEditGroups_vtbl *)&CEditGroups::`vftable';
  CWnd::CWnd(this: &this->m_cName);
  this->m_cName.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CGroupList::CGroupList(this: &this->m_cGroupList);
  CWnd::CWnd(this: &this->m_cColorBox);
  this->m_cColorBox.__vftable = (CColorBox_vtbl *)&CStatic::`vftable';
  this->m_cColorBox.__vftable = (CColorBox_vtbl *)&CColorBox::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100C5540
// Name: public: virtual CEditGroups::~CEditGroups(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGroups::~CEditGroups(CEditGroups *this)
{
  CStatic::~CStatic(this: &this->m_cColorBox);
  CGroupList::~CGroupList(this: &this->m_cGroupList);
  CEdit::~CEdit(this: &this->m_cName);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x100C5650
// Name: protected: void CEditGroups::OnColor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGroups::OnColor(CEditGroups *this)
{
  unsigned int SelectedItem; // eax
  _BYTE *v3; // esi
  unsigned int rgbResult; // eax
  unsigned int rgbResult_high; // ecx
  unsigned int v6; // edx
  CMapWorld *ActiveWorld; // eax
  CColorDialog dlg; // [esp+8h] [ebp-C4h] BYREF
  int v9; // [esp+C8h] [ebp-4h]

  SelectedItem = CTreeList::GetSelectedItem(this: &this->m_cGroupList);
  v3 = (_BYTE *)SelectedItem;
  if ( SelectedItem != 0 )
  {
    CColorDialog::CColorDialog(
      this: &dlg,
      clrInit: (unsigned __int8)*(_DWORD *)(SelectedItem + 153)
    | (((unsigned __int8)BYTE1(*(_DWORD *)(SelectedItem + 153))
      | ((unsigned __int8)BYTE2(*(_DWORD *)(SelectedItem + 153)) << 8)) << 8),
      dwFlags: 2u,
      pParentWnd: nullptr);
    v9 = 0;
    if ( CColorDialog::DoModal(this: &dlg) == 1 )
    {
      rgbResult = dlg.m_cc.rgbResult;
      rgbResult_high = HIWORD(dlg.m_cc.rgbResult);
      v6 = dlg.m_cc.rgbResult >> 8;
      v3[153] = dlg.m_cc.rgbResult;
      v3[154] = v6;
      v3[155] = rgbResult_high;
      v3[156] = 0;
      this->m_cColorBox.m_c = rgbResult;
      RedrawWindow(hWnd: this->m_cColorBox.m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x101u);
      ActiveWorld = GetActiveWorld();
      CMapClass::EnumChildren(
        this: ActiveWorld,
        pfn: (int (__cdecl *)(CMapClass *, unsigned int))UpdateObjectColor,
        dwParam: (unsigned int)v3,
        Type: nullptr);
      CMapDoc::UpdateAllViews(this: CMapDoc::m_pMapDoc, nFlags: 4, ub: nullptr);
    }
    dlg.__vftable = (CColorDialog_vtbl *)&CCommonDialog::`vftable';
    v9 = -1;
    CDialog::~CDialog(this: &dlg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C5770
// Name: protected: void CEditGroups::OnNew(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGroups::OnNew(CEditGroups *this)
{
  CVisGroup *v2; // edi
  HWND v3; // eax

  v2 = CMapDoc::VisGroups_AddGroup(this: CMapDoc::m_pMapDoc, pszName: "new group", bAuto: false);
  v2->m_eVisible = VISGROUP_SHOWN;
  CEditGroups::UpdateGroupList(this);
  CTreeList::SelectItem(this: &this->m_cGroupList, pItem: v2);
  CWnd::EnableWindow(this: &this->m_cName, bEnable: 1);
  v3 = SetActiveWindow(hWnd: this->m_cName.m_hWnd);
  CWnd::FromHandle(hWnd: v3);
}

//------------------------------------------------------------------------------
// Address: 0x100C57D0
// Name: protected: void CEditGroups::OnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGroups::OnRemove(CEditGroups *this)
{
  CParticleOperatorDefinition<C_OP_RenderProjected> *SelectedItem; // eax
  CMapWorld *v3; // edi
  CMapDoc *v4; // esi

  SelectedItem = (CParticleOperatorDefinition<C_OP_RenderProjected> *)CTreeList::GetSelectedItem(this: &this->m_cGroupList);
  v3 = (CMapWorld *)SelectedItem;
  if ( SelectedItem != nullptr && !CParticleOperatorDefinition<C_INIT_RandomTrailLength>::IsObsolete(this: SelectedItem) )
  {
    v4 = CMapDoc::m_pMapDoc;
    if ( CMapDoc::m_pMapDoc != nullptr )
    {
      CMapDoc::VisGroups_RemoveGroup(this: CMapDoc::m_pMapDoc, pGroup: v3);
      if ( CTreeList::GetItemCount(this: (CTreeList *)v3) != 1 )
      {
        CMapDoc::VisGroups_UpdateAll(this: v4);
        CMapDoc::UpdateVisibilityAll(this: v4);
        CMapDoc::UpdateAllViews(this: v4, nFlags: 1, ub: nullptr);
        CEditGroups::UpdateGroupList(this);
        return;
      }
      CMapDoc::UpdateAllViews(this: v4, nFlags: 4, ub: nullptr);
    }
    CEditGroups::UpdateGroupList(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C5850
// Name: protected: void CEditGroups::UpdateControlsForVisGroup(class CVisGroup __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGroups::UpdateControlsForVisGroup(CEditGroups *this, CVisGroup *pVisGroup)
{
  HWND__ *m_hWnd; // [esp-10h] [ebp-18h]

  if ( pVisGroup != nullptr )
  {
    CWnd::SetWindowTextA(this: &this->m_cName, lpszString: pVisGroup->m_szName);
    m_hWnd = this->m_cColorBox.m_hWnd;
    this->m_cColorBox.m_c = (unsigned __int8)*(_DWORD *)&pVisGroup->m_rgbColor
                          | (((unsigned __int8)BYTE1(*(_DWORD *)&pVisGroup->m_rgbColor)
                            | ((unsigned __int8)BYTE2(*(_DWORD *)&pVisGroup->m_rgbColor) << 8)) << 8);
    RedrawWindow(hWnd: m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x101u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100C58C0
// Name: protected: virtual int CEditGroups::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEditGroups::OnInitDialog(CEditGroups *this)
{
  CVisGroup *Output; // ebx

  CDialog::OnInitDialog(this);
  CWnd::SubclassDlgItem(this: &this->m_cGroupList, nID: 0x449u, pParent: this);
  CWnd::SubclassDlgItem(this: &this->m_cColorBox, nID: 0x447u, pParent: this);
  CEditGroups::UpdateGroupList(this);
  if ( CTreeList::GetItemCount(this: &this->m_cGroupList) != 0 )
  {
    Output = (CVisGroup *)GDclass::GetOutput(this: (GDclass *)&this->m_cGroupList, nIndex: 0);
    CTreeList::SelectItem(this: &this->m_cGroupList, pItem: Output);
    CEditGroups::UpdateControlsForVisGroup(this, pVisGroup: Output);
  }
  else
  {
    CWnd::EnableWindow(this: &this->m_cName, bEnable: 0);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100C5950
// Name: protected: void CEditGroups::OnChangeName(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CEditGroups::OnChangeName(CEditGroups *this)
{
  CVisGroup *SelectedItem; // ebx
  CAfxStringMgr *StringManager; // eax
  char *v4; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > szName; // [esp+Ch] [ebp-10h] BYREF
  int v6; // [esp+18h] [ebp-4h]

  SelectedItem = (CVisGroup *)CTreeList::GetSelectedItem(this: &this->m_cGroupList);
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  szName.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v6 = 1;
  CWnd::GetWindowTextA(this: &this->m_cName, rString: &szName);
  if ( szName.m_pszData != nullptr )
    strncpy(dest: (unsigned __int8 *)SelectedItem->m_szName, source: (unsigned __int8 *)szName.m_pszData, count: 0x80u);
  CGroupList::UpdateVisGroup(this: &this->m_cGroupList, pVisGroup: SelectedItem);
  v6 = -1;
  v4 = szName.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)szName.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v4 + 4))(a1: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100C5A20
// Name: protected: long CEditGroups::OnSelChangeGroupList(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CEditGroups::OnSelChangeGroupList(CEditGroups *this, unsigned int wParam, unsigned int lParam)
{
  CVisGroup *SelectedItem; // eax

  SelectedItem = (CVisGroup *)CTreeList::GetSelectedItem(this: &this->m_cGroupList);
  if ( SelectedItem != nullptr )
    CEditGroups::UpdateControlsForVisGroup(this, pVisGroup: SelectedItem);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100C5A40
// Name: protected: virtual struct AFX_MSGMAP const __near * CEditGroups::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CEditGroups::GetMessageMap(CEditGroups *this)
{
  return (const AFX_MSGMAP *)&off_105EA2C8;
}

//------------------------------------------------------------------------------
// Address: 0x100C5A50
// Name: public: void CColorBox::OnPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CColorBox::OnPaint(CColorBox *this)
{
  HWND__ *m_hWnd; // [esp-8h] [ebp-88h]
  CPaintDC dc; // [esp+8h] [ebp-78h] BYREF
  CRect r; // [esp+5Ch] [ebp-24h] BYREF
  CBrush brush; // [esp+6Ch] [ebp-14h] BYREF
  int v6; // [esp+7Ch] [ebp-4h]

  CPaintDC::CPaintDC(this: &dc, pWnd: this);
  v6 = 0;
  m_hWnd = this->m_hWnd;
  memset(&r, 0, sizeof(r));
  GetClientRect(hWnd: m_hWnd, lpRect: &r);
  CBrush::CBrush(this: &brush, crColor: this->m_c);
  LOBYTE(v6) = 1;
  FillRect(hDC: dc.m_hDC, lprc: &r, hbr: (HBRUSH)brush.m_hObject);
  brush.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  LOBYTE(v6) = 0;
  CGdiObject::~CGdiObject(this: &brush);
  v6 = -1;
  CPaintDC::~CPaintDC(this: &dc);
}

//------------------------------------------------------------------------------
// Address: 0x100C5AF0
// Name: protected: virtual struct AFX_MSGMAP const __near * CColorBox::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CColorBox::GetMessageMap(CColorBox *this)
{
  return (const AFX_MSGMAP *)&off_105EA378;
}

//------------------------------------------------------------------------------
// Address: 0x1035A925
// Name: protected: virtual void CCommonDialog::OnOK(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommonDialog::OnOK(CCommonDialog *this)
{
  if ( CWnd::UpdateData(this, bSaveAndValidate: 1) != 0 )
    CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1035A944
// Name: protected: int CCommonDialog::OnHelpInfo(struct tagHELPINFO __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCommonDialog::OnHelpInfo(CCommonDialog *this, tagHELPINFO *__formal)
{
  return CWnd::Default(this) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1035A952
// Name: public: virtual struct CRuntimeClass __near * CCommonDialog::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CCommonDialog::GetRuntimeClass(CCommonDialog *this)
{
  return &CCommonDialog::classCCommonDialog;
}

//------------------------------------------------------------------------------
// Address: 0x1035A958
// Name: protected: virtual struct AFX_MSGMAP const __near * CCommonDialog::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CCommonDialog::GetMessageMap(CCommonDialog *this)
{
  return &messageMap_23;
}

//------------------------------------------------------------------------------
// Address: 0x1035D9F2
// Name: public: virtual struct CRuntimeClass __near * CColorDialog::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CColorDialog::GetRuntimeClass(CColorDialog *this)
{
  return &CColorDialog::classCColorDialog;
}

//------------------------------------------------------------------------------
// Address: 0x1035DB33
// Name: public: virtual int CColorDialog::DoModal(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CColorDialog::DoModal(CColorDialog *this)
{
  int v2; // edi

  this->m_cc.hwndOwner = CDialog::PreModal(this);
  v2 = AfxCtxChooseColorA(unnamed1: &this->m_cc);
  CDialog::PostModal(this);
  if ( v2 != 0 )
    return v2;
  else
    return 2;
}

//------------------------------------------------------------------------------
// Address: 0x1035DB67
// Name: public: static unsigned long __near * CColorDialog::GetSavedCustomColors(void)
// Source: json
//------------------------------------------------------------------------------
CNoTrackObject *__stdcall CColorDialog::GetSavedCustomColors()
{
  CNoTrackObject *Data; // eax

  Data = CProcessLocalObject::GetData(
           this: &_afxClrState,
           pfnCreateObject: CProcessLocal<_AFX_COLOR_STATE>::CreateObject);
  if ( Data == nullptr )
    AfxThrowInvalidArgException();
  return Data + 1;
}

//------------------------------------------------------------------------------
// Address: 0x1035DB83
// Name: public: CColorDialog::CColorDialog(unsigned long,unsigned long,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CColorDialog *__thiscall CColorDialog::CColorDialog(
        CColorDialog *this,
        unsigned int clrInit,
        unsigned int dwFlags,
        CWnd *pParentWnd)
{
  CDialog::CDialog(this, nIDTemplate: 0, pParentWnd);
  this->__vftable = (CColorDialog_vtbl *)&CColorDialog::`vftable';
  memset(dst: (unsigned __int8 *)&this->m_cc, value: 0, count: sizeof(this->m_cc));
  this->m_nIDHelp = 28679;
  this->m_cc.lStructSize = 36;
  this->m_cc.lpCustColors = (unsigned int *)CColorDialog::GetSavedCustomColors();
  this->m_cc.Flags = dwFlags | 0x10;
  this->m_cc.lpfnHook = _AfxCommDlgProc;
  this->m_cc.rgbResult = clrInit;
  if ( clrInit != 0 )
    this->m_cc.Flags = dwFlags | 0x11;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1035A95E
// Name: unsigned int _AfxCommDlgProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _AfxCommDlgProc(HWND__ *hWnd, unsigned int message, unsigned int wParam, unsigned int lParam)
{
  int result; // eax
  CNoTrackObject *Data; // eax
  CNoTrackObject *v6; // esi
  CWnd *v7; // eax
  CMFCRibbonBaseElement *v8; // esi

  if ( hWnd == nullptr )
    return 0;
  Data = CThreadLocalObject::GetData(
           this: &_afxThreadState,
           pfnCreateObject: CThreadLocal<_AFX_THREAD_STATE>::CreateObject);
  v6 = Data;
  if ( Data == nullptr )
    AfxThrowInvalidArgException();
  if ( Data[6].__vftable != nullptr && CWnd::FromHandlePermanent(hWnd) == nullptr )
  {
    CWnd::SubclassWindow(this: (CWnd *)v6[6].__vftable, hWnd);
    v6[6].__vftable = nullptr;
  }
  if ( message == 272 )
  {
    _afxMsgLBSELCHANGE = RegisterWindowMessageA(lpString: "commdlg_LBSelChangedNotify");
    _afxMsgSHAREVI = RegisterWindowMessageA(lpString: "commdlg_ShareViolation");
    _afxMsgFILEOK = RegisterWindowMessageA(lpString: "commdlg_FileNameOK");
    _afxMsgCOLOROK = RegisterWindowMessageA(lpString: "commdlg_ColorOK");
    _afxMsgHELP = RegisterWindowMessageA(lpString: "commdlg_help");
    _afxMsgSETRGB = RegisterWindowMessageA(lpString: "commdlg_SetRGBColor");
    return (int)AfxDlgProc(hWnd, message: 0x110u, __formal: wParam, a4: lParam);
  }
  if ( message == _afxMsgHELP || message == 273 && (_WORD)wParam == 1038 )
  {
    SendMessageA(hWnd, Msg: 0x111u, wParam: 0xE146u, lParam: 0);
    return 1;
  }
  else
  {
    if ( message < 0xC000 )
      return 0;
    v7 = CWnd::FromHandlePermanent(hWnd);
    v8 = (CMFCRibbonBaseElement *)v7;
    if ( v7 == nullptr
      || CObject::IsKindOf(this: v7, pClass: &CFileDialog::classCFileDialog) != 0
      && (*(_DWORD *)(CMFCRibbonBaseElement::IsAlwaysLargeImage(this: v8) + 52) & 0x80000) != 0 )
    {
      return 0;
    }
    if ( message == _afxMsgSHAREVI )
      return ((int (__thiscall *)(CMFCRibbonBaseElement *, unsigned int))v8->NotifyControlCommand)(a1: v8, a2: lParam);
    if ( message == _afxMsgFILEOK )
    {
      v8[2].m_bOnBeforeShowItemMenuIsSent = lParam;
      result = ((int (__thiscall *)(CMFCRibbonBaseElement *))v8->ReplaceByID)(a1: v8);
      v8[2].m_bOnBeforeShowItemMenuIsSent = 0;
      return result;
    }
    if ( message == _afxMsgLBSELCHANGE )
    {
      ((void (__thiscall *)(CMFCRibbonBaseElement *, unsigned int, _DWORD, unsigned int))v8->GetItemIDsList)(
        a1: v8,
        a2: wParam,
        a3: (unsigned __int16)lParam,
        a4: HIWORD(lParam));
      return 0;
    }
    if ( message != _afxMsgCOLOROK )
      return 0;
    return ((int (__thiscall *)(CMFCRibbonBaseElement *))v8->OnUpdateCmdUI)(a1: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035AB08
// Name: public: virtual CPrintingDialog::~CPrintingDialog(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPrintingDialog::~CPrintingDialog(CPrintingDialog *this)
{
  this->__vftable = (CPrintingDialog_vtbl *)&CPrintingDialog::`vftable';
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x1035AB3A
// Name: public: virtual int CPrintingDialog::OnInitDialog(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPrintingDialog::OnInitDialog(CPrintingDialog *this)
{
  AFX_MODULE_STATE *ModuleState; // eax

  ModuleState = AfxGetModuleState();
  CWnd::SetWindowTextA(this, lpszString: ModuleState->m_lpszCurrentAppName);
  CWnd::CenterWindow(this, pAlternateOwner: nullptr);
  return CDialog::OnInitDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x1035AB5F
// Name: public: static class CNoTrackObject __near * CProcessLocal<class _AFX_WIN_STATE>::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CNoTrackObject *__stdcall CProcessLocal<_AFX_WIN_STATE>::CreateObject()
{
  CNoTrackObject *result; // eax

  result = (CNoTrackObject *)CNoTrackObject::operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (CNoTrackObject_vtbl *)&_AFX_WIN_STATE::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1035AB74
// Name: public: CPrintInfo::CPrintInfo(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPrintInfo *__thiscall CPrintInfo::CPrintInfo(CPrintInfo *this)
{
  CAfxStringMgr *StringManager; // eax
  CPrintDialog *v3; // ecx
  CPrintDialog *v4; // eax

  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strPageDesc, pStringMgr: StringManager);
  this->m_rectDraw.left = 0;
  this->m_rectDraw.top = 0;
  this->m_rectDraw.right = 0;
  this->m_rectDraw.bottom = 0;
  v3 = (CPrintDialog *)operator new(nSize: 0xDCu);
  if ( v3 != nullptr )
    v4 = CPrintDialog::CPrintDialog(this: v3, bPrintSetupOnly: 0, dwFlags: 0x40004u, pParentWnd: nullptr);
  else
    v4 = nullptr;
  this->m_pPD = v4;
  v4->m_pd->nMinPage = 1;
  this->m_pPD->m_pd->nMaxPage = -1;
  this->m_nJobNumber = -1;
  this->m_nCurPage = 1;
  this->m_lpUserData = nullptr;
  this->m_bPreview = 0;
  this->m_bDirect = 0;
  this->m_bDocObject = 0;
  this->m_bContinuePrinting = 1;
  this->m_dwFlags = 0;
  this->m_nOffsetPage = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1035AC11
// Name: public: CPrintInfo::~CPrintInfo(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPrintInfo::~CPrintInfo(CPrintInfo *this)
{
  HDC__ *hDC; // eax

  if ( this->m_pPD != nullptr )
  {
    hDC = this->m_pPD->m_pd->hDC;
    if ( hDC != nullptr )
    {
      DeleteDC(hdc: hDC);
      this->m_pPD->m_pd->hDC = nullptr;
    }
  }
  if ( this->m_pPD != nullptr )
    ((void (__thiscall *)(CPrintDialog *, int))this->m_pPD->dtr_CObject)(a1: this->m_pPD, a2: 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strPageDesc.m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x1035AC6A
// Name: public: CPrintingDialog::CPrintingDialog(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPrintingDialog *__thiscall CPrintingDialog::CPrintingDialog(CPrintingDialog *this, CWnd *pParent)
{
  CNoTrackObject *Data; // eax

  CDialog::CDialog(this);
  this->__vftable = (CPrintingDialog_vtbl *)&CPrintingDialog::`vftable';
  CDialog::Create(this, lpszTemplateName: (const char *)0x7802, pParentWnd: pParent);
  Data = CProcessLocalObject::GetData(this: &_afxWinState, pfnCreateObject: CProcessLocal<_AFX_WIN_STATE>::CreateObject);
  if ( Data == nullptr )
    AfxThrowInvalidArgException();
  Data[1].__vftable = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1035ACBF
// Name: int _AfxAbortProc(struct HDC__ __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall _AfxAbortProc(HDC__ *__formal, int a2)
{
  CNoTrackObject *Data; // esi
  tagMSG msg; // [esp+8h] [ebp-1Ch] BYREF

  Data = CProcessLocalObject::GetData(this: &_afxWinState, pfnCreateObject: CProcessLocal<_AFX_WIN_STATE>::CreateObject);
  if ( Data == nullptr )
    AfxThrowInvalidArgException();
  do
  {
    if ( Data[1].__vftable != nullptr
      || !PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 0) )
    {
      return Data[1].__vftable == nullptr;
    }
  }
  while ( AfxPumpMessage() != 0 );
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1035AD17
// Name: public: virtual void CPrintingDialog::OnCancel(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPrintingDialog::OnCancel(CPrintingDialog *this)
{
  CNoTrackObject *Data; // eax

  Data = CProcessLocalObject::GetData(this: &_afxWinState, pfnCreateObject: CProcessLocal<_AFX_WIN_STATE>::CreateObject);
  if ( Data == nullptr )
    AfxThrowInvalidArgException();
  Data[1].__vftable = (CNoTrackObject_vtbl *)1;
  CDialog::OnCancel(this);
}

//------------------------------------------------------------------------------
// Address: 0x1035AD43
// Name: public: int CView::DoPreparePrinting(struct CPrintInfo __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CView::DoPreparePrinting(CView *this, CPrintInfo *pInfo)
{
  tagPDA *m_pd; // eax
  CWinApp *m_pCurrentWinApp; // edi
  HINSTANCE__ *StringResourceHandle; // eax

  m_pd = pInfo->m_pPD->m_pd;
  if ( m_pd->nMinPage > m_pd->nMaxPage )
    pInfo->m_pPD->m_pd->nMaxPage = m_pd->nMinPage;
  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  if ( pInfo->m_bPreview != 0 || pInfo->m_bDirect != 0 || pInfo->m_bDocObject != 0 && (pInfo->m_dwFlags & 2) == 0 )
  {
    if ( pInfo->m_pPD->m_pd->hDC == nullptr
      && (CWinApp::GetPrinterDeviceDefaults(this: m_pCurrentWinApp, pPrintDlg: pInfo->m_pPD->m_pd) == 0
       && (pInfo->m_bDocObject == 0 || (pInfo->m_dwFlags & 1) != 0)
       && CWinApp::DoPrintDialog(this: m_pCurrentWinApp, pPD: pInfo->m_pPD) != 1
       || pInfo->m_pPD->m_pd->hDC == nullptr && CPrintDialog::CreatePrinterDC(this: pInfo->m_pPD) == nullptr) )
    {
      return 0;
    }
    pInfo->m_pPD->m_pd->nFromPage = pInfo->m_pPD->m_pd->nMinPage;
    pInfo->m_pPD->m_pd->nToPage = pInfo->m_pPD->m_pd->nMaxPage;
  }
  else
  {
    pInfo->m_pPD->m_pd->nFromPage = pInfo->m_pPD->m_pd->nMinPage;
    pInfo->m_pPD->m_pd->nToPage = pInfo->m_pPD->m_pd->nMaxPage;
    if ( CWinApp::DoPrintDialog(this: m_pCurrentWinApp, pPD: pInfo->m_pPD) != 1 )
      return 0;
  }
  if ( pInfo->m_pPD->m_pd->hDC == nullptr )
    return 0;
  pInfo->m_nNumPreviewPages = m_pCurrentWinApp->m_nNumPreviewPages;
  StringResourceHandle = AfxFindStringResourceHandle(__formal: 0xF044u);
  if ( StringResourceHandle == nullptr
    || ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
         this: &pInfo->m_strPageDesc,
         hInstance: StringResourceHandle,
         nID: 0xF044u) == 0 )
  {
    AfxThrowInvalidArgException();
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1035AE67
// Name: protected: void CView::OnFilePrint(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CView::OnFilePrint(CView *this)
{
  CView *v1; // ebx
  CCommandLineInfo *m_pCmdInfo; // eax
  HDC__ *DCA; // eax
  CAfxStringMgr *StringManager; // eax
  bool v5; // zf
  char *m_pszData; // esi
  char *v7; // ecx
  ATL::CStringData *PathName; // eax
  CAfxStringMgr *v9; // eax
  ATL::CStringData *m_pDocument; // eax
  CFrameWnd *ParentFrame; // eax
  CAfxStringMgr *v12; // eax
  char *v13; // edi
  int v14; // eax
  ATL::CStringData *PortName; // eax
  char *v16; // eax
  CAfxStringMgr *v17; // eax
  char *v18; // esi
  ATL::CStringData *v19; // ecx
  tagPDA *m_pd; // eax
  unsigned int nToPage; // edx
  char *nFromPage; // esi
  unsigned int nMinPage; // eax
  tagPDA *v24; // eax
  char *nMaxPage; // ecx
  char *v26; // eax
  int v27; // esi
  HINSTANCE__ *StringResourceHandle; // eax
  int *v29; // eax
  int DeviceCaps; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *DeviceName; // eax
  CHAR *Buffer; // eax
  char v33; // bl
  unsigned __int8 *v34; // esi
  char *v35; // [esp-4h] [ebp-3ACh]
  CPrintingDialog v36; // [esp+10h] [ebp-398h] BYREF
  DWORD v37; // [esp+A4h] [ebp-304h] BYREF
  DOCINFOA dst; // [esp+A8h] [ebp-300h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v39; // [esp+BCh] [ebp-2ECh] BYREF
  int v40; // [esp+C0h] [ebp-2E8h]
  int v41; // [esp+C4h] [ebp-2E4h]
  DWORD pcbNeeded; // [esp+C8h] [ebp-2E0h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v43; // [esp+CCh] [ebp-2DCh] BYREF
  ATL::CSimpleStringT<char,0> v44; // [esp+D0h] [ebp-2D8h] BYREF
  CView *v45; // [esp+D4h] [ebp-2D4h]
  CDC v46; // [esp+D8h] [ebp-2D0h] BYREF
  ATL::CSimpleStringT<char,0> v47; // [esp+E8h] [ebp-2C0h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+ECh] [ebp-2BCh] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v49; // [esp+F0h] [ebp-2B8h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v50; // [esp+F4h] [ebp-2B4h] BYREF
  unsigned int v51; // [esp+F8h] [ebp-2B0h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v52; // [esp+FCh] [ebp-2ACh] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v53; // [esp+100h] [ebp-2A8h] BYREF
  CPrintInfo v54; // [esp+104h] [ebp-2A4h] BYREF
  CFileDialog v55; // [esp+144h] [ebp-264h] BYREF
  char string[92]; // [esp+348h] [ebp-60h] BYREF
  int v57; // [esp+3A4h] [ebp-4h]

  v1 = this;
  v45 = this;
  CPrintInfo::CPrintInfo(this: &v54);
  v57 = 0;
  if ( LOWORD(CWnd::GetCurrentMessage()->wParam) != 0xE108 )
  {
LABEL_7:
    if ( v1->OnPreparePrinting(this: v1, a2: &v54) == 0 )
      goto LABEL_74;
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v44, pStringMgr: StringManager);
    v5 = (v54.m_pPD->m_pd->Flags & 0x20) == 0;
    LOBYTE(v57) = 1;
    if ( !v5 && v54.m_bDocObject == 0 )
    {
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
        this: &v52,
        pszSrc: (const char *)0xF045);
      LOBYTE(v57) = 2;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
        this: &v53,
        pszSrc: (const char *)0xF046);
      LOBYTE(v57) = 3;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
        this: &v50,
        pszSrc: (const char *)0xF047);
      LOBYTE(v57) = 4;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
        this: &v49,
        pszSrc: (const char *)0xF048);
      LOBYTE(v57) = 5;
      CFileDialog::CFileDialog(
        this: &v55,
        bOpenFileDialog: 0,
        lpszDefExt: v52.m_pszData,
        lpszFileName: v53.m_pszData,
        dwFlags: 6u,
        lpszFilter: v50.m_pszData,
        pParentWnd: nullptr,
        dwSize: 0,
        bVistaStyle: 1);
      m_pszData = v49.m_pszData;
      LOBYTE(v57) = 6;
      *(_DWORD *)(CMFCRibbonBaseElement::IsAlwaysLargeImage(this: (CMFCRibbonBaseElement *)&v55) + 48) = m_pszData;
      if ( CFileDialog::DoModal(this: &v55) != 1 )
      {
        LOBYTE(v57) = 5;
        CFileDialog::~CFileDialog(this: &v55);
        ATL::CStringData::Release(this: (ATL::CStringData *)v49.m_pszData - 1);
        ATL::CStringData::Release(this: (ATL::CStringData *)v50.m_pszData - 1);
        ATL::CStringData::Release(this: (ATL::CStringData *)v53.m_pszData - 1);
        v7 = v52.m_pszData;
LABEL_72:
        ATL::CStringData::Release(this: (ATL::CStringData *)v7 - 1);
        v19 = (ATL::CStringData *)(v44.m_pszData - 16);
        goto LABEL_73;
      }
      PathName = (ATL::CStringData *)CFileDialog::GetPathName(this: &v55, &result);
      LOBYTE(v57) = 7;
      ATL::CSimpleStringT<char,0>::operator=(this: &v44, strSrc: PathName);
      ATL::CStringData::Release(this: (ATL::CStringData *)result.m_pszData - 1);
      LOBYTE(v57) = 5;
      CFileDialog::~CFileDialog(this: &v55);
      ATL::CStringData::Release(this: (ATL::CStringData *)v49.m_pszData - 1);
      ATL::CStringData::Release(this: (ATL::CStringData *)v50.m_pszData - 1);
      ATL::CStringData::Release(this: (ATL::CStringData *)v53.m_pszData - 1);
      LOBYTE(v57) = 1;
      ATL::CStringData::Release(this: (ATL::CStringData *)v52.m_pszData - 1);
    }
    v9 = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v47, pStringMgr: v9);
    m_pDocument = (ATL::CStringData *)v1->m_pDocument;
    LOBYTE(v57) = 8;
    if ( m_pDocument != nullptr )
    {
      ATL::CSimpleStringT<char,0>::operator=(this: &v47, strSrc: m_pDocument + 2);
    }
    else
    {
      ParentFrame = CWnd::GetParentFrame(this: v1);
      if ( ParentFrame == nullptr )
        AfxThrowInvalidArgException();
      CWnd::GetWindowTextA(
        this: ParentFrame,
        rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v47);
    }
    memset((unsigned __int8 *)&dst, value: 0, count: sizeof(dst));
    dst.cbSize = 20;
    dst.lpszDocName = v47.m_pszData;
    v12 = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v49, pStringMgr: v12);
    v13 = v44.m_pszData;
    v14 = *((_DWORD *)v44.m_pszData - 3);
    LOBYTE(v57) = 9;
    if ( v14 != 0 )
    {
      dst.lpszOutput = v44.m_pszData;
      v16 = ATL::CSimpleStringT<char,0>::PrepareWrite(this: &v49, nLength: 260);
      AfxGetFileTitle(lpszPathName: v13, lpszTitle: v16, nMax: 0x104u);
    }
    else
    {
      dst.lpszOutput = nullptr;
      PortName = (ATL::CStringData *)CPrintDialog::GetPortName(this: v54.m_pPD, &result);
      LOBYTE(v57) = 10;
      ATL::CSimpleStringT<char,0>::operator=(this: &v49, strSrc: PortName);
      LOBYTE(v57) = 9;
      ATL::CStringData::Release(this: (ATL::CStringData *)result.m_pszData - 1);
    }
    CDC::CDC(this: &v46);
    LOBYTE(v57) = 11;
    if ( v54.m_bDocObject == 0 )
    {
      CDC::Attach(this: &v46, hDC: v54.m_pPD->m_pd->hDC);
      v46.m_bPrinting = 1;
    }
    v1->OnBeginPrinting(this: v1, a2: &v46, a3: &v54);
    if ( v54.m_bDocObject == 0 )
      SetAbortProc(hdc: v46.m_hDC, proc: _AfxAbortProc);
    result.m_pszData = (char *)AfxGetMainWnd();
    CWnd::EnableWindow(this: (CWnd *)result.m_pszData, bEnable: 0);
    CPrintingDialog::CPrintingDialog(this: &v36, pParent: v1);
    LOBYTE(v57) = 12;
    v17 = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v50, pStringMgr: v17);
    LOBYTE(v57) = 13;
    CWnd::SetDlgItemTextA(this: &v36, nID: 201, lpszString: v47.m_pszData);
    v35 = CPrintDialog::GetDeviceName(this: v54.m_pPD, result: &v43)->m_pszData;
    LOBYTE(v57) = 14;
    CWnd::SetDlgItemTextA(this: &v36, nID: 202, lpszString: v35);
    LOBYTE(v57) = 13;
    ATL::CStringData::Release(this: (ATL::CStringData *)v43.m_pszData - 1);
    v18 = v49.m_pszData;
    CWnd::SetDlgItemTextA(this: &v36, nID: 203, lpszString: v49.m_pszData);
    CWnd::ShowWindow(this: &v36, nCmdShow: 5);
    UpdateWindow(hWnd: v36.m_hWnd);
    if ( v54.m_bDocObject == 0 )
    {
      v54.m_nJobNumber = StartDocA(hdc: v46.m_hDC, lpdi: &dst);
      if ( v54.m_nJobNumber == -1 )
      {
        CWnd::EnableWindow(this: (CWnd *)result.m_pszData, bEnable: 1);
        v1->OnEndPrinting(this: v1, a2: &v46, a3: &v54);
        CWnd::DestroyWindow(this: &v36);
        CDC::Detach(this: &v46);
        AfxMessageBox(nIDPrompt: 0xF106u, nType: 0, nIDHelp: 0xFFFFFFFF);
        ATL::CStringData::Release(this: (ATL::CStringData *)v50.m_pszData - 1);
        LOBYTE(v57) = 11;
        v36.__vftable = (CPrintingDialog_vtbl *)&CPrintingDialog::`vftable';
        CDialog::~CDialog(this: &v36);
        LOBYTE(v57) = 9;
        CDC::~CDC(this: &v46);
        ATL::CStringData::Release(this: (ATL::CStringData *)v18 - 1);
        ATL::CStringData::Release(this: (ATL::CStringData *)v47.m_pszData - 1);
        v19 = (ATL::CStringData *)(v13 - 16);
LABEL_73:
        ATL::CStringData::Release(this: v19);
        goto LABEL_74;
      }
    }
    m_pd = v54.m_pPD->m_pd;
    nToPage = m_pd->nToPage;
    nFromPage = (char *)m_pd->nFromPage;
    nMinPage = m_pd->nMinPage;
    v51 = nToPage;
    v53.m_pszData = nFromPage;
    if ( nToPage < nMinPage )
      v51 = v54.m_pPD->m_pd->nMinPage;
    v24 = v54.m_pPD->m_pd;
    nMaxPage = (char *)v24->nMaxPage;
    if ( v51 > (unsigned int)nMaxPage )
      v51 = v24->nMaxPage;
    v26 = (char *)v24->nMinPage;
    if ( nFromPage < v26 )
      v53.m_pszData = v26;
    if ( v53.m_pszData > nMaxPage )
      v53.m_pszData = nMaxPage;
    v27 = v51 < (unsigned int)v53.m_pszData ? -1 : 1;
    v41 = v27;
    if ( v51 == 0xFFFF )
      v51 = 0xFFFF;
    else
      v51 += v27;
    StringResourceHandle = AfxFindStringResourceHandle(__formal: 0xF043u);
    if ( StringResourceHandle != nullptr )
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
        this: &v50,
        hInstance: StringResourceHandle,
        nID: 0xF043u);
    v52.m_pszData = nullptr;
    if ( v54.m_bDocObject != 0 )
    {
      v1->OnPrepareDC(this: v1, a2: &v46, a3: &v54);
      v1->OnPrint(this: v1, a2: &v46, a3: &v54);
    }
    else
    {
      v54.m_nCurPage = (unsigned int)v53.m_pszData;
      if ( v53.m_pszData == (char *)v51 )
        goto LABEL_68;
      do
      {
        v1->OnPrepareDC(this: v1, a2: &v46, a3: &v54);
        if ( v54.m_bContinuePrinting == 0 )
          break;
        v53.m_pszData = (char *)*_errno();
        *_errno() = 0;
        _snprintf_s(string, sizeInBytes: 0x50u, count: 0x4Fu, format: v50.m_pszData, v54.m_nCurPage);
        if ( *_errno() != 0 )
        {
          v29 = _errno();
          ATL::AtlCrtErrorCheck(nError: *v29);
        }
        else
        {
          *_errno() = (int)v53.m_pszData;
        }
        CWnd::SetDlgItemTextA(this: &v36, nID: 204, lpszString: string);
        v53.m_pszData = (char *)GetDeviceCaps(hdc: v46.m_hAttribDC, index: 10);
        DeviceCaps = GetDeviceCaps(hdc: v46.m_hAttribDC, index: 8);
        SetRect(lprc: &v54.m_rectDraw, xLeft: 0, yTop: 0, xRight: DeviceCaps, yBottom: (int)v53.m_pszData);
        DPtoLP(hdc: v46.m_hAttribDC, lppt: (LPPOINT)&v54.m_rectDraw, c: 2);
        if ( StartPage(hdc: v46.m_hDC) < 0 )
          goto LABEL_65;
        v1->OnPrepareDC(this: v1, a2: &v46, a3: &v54);
        v1->OnPrint(this: v1, a2: &v46, a3: &v54);
        if ( v27 > 0 && v51 > v27 + (unsigned int)v54.m_pPD->m_pd->nMaxPage )
          v51 = v27 + v54.m_pPD->m_pd->nMaxPage;
        if ( EndPage(hdc: v46.m_hDC) < 0 && GetLastError() != 0 )
        {
          DeviceName = CPrintDialog::GetDeviceName(this: v54.m_pPD, result: &v39);
          LOBYTE(v57) = 15;
          Buffer = ATL::CSimpleStringT<char,0>::GetBuffer(this: DeviceName);
          v33 = -OpenPrinterA(pPrinterName: Buffer, phPrinter: (LPHANDLE)&v43.m_pszData, pDefault: nullptr);
          LOBYTE(v57) = 13;
          ATL::CStringData::Release(this: (ATL::CStringData *)v39.m_pszData - 1);
          if ( v33 != -1 )
          {
            v1 = v45;
LABEL_65:
            v52.m_pszData = (char *)1;
            break;
          }
          if ( !GetJobA(
                  hPrinter: v43.m_pszData,
                  JobId: v54.m_nJobNumber,
                  Level: 1u,
                  pJob: nullptr,
                  cbBuf: 0,
                  &pcbNeeded)
            && GetLastError() != 122
            || (v34 = (unsigned __int8 *)MemAlloc_Alloc(nSize: pcbNeeded)) == nullptr
            || (v53.m_pszData = (char *)GetJobA(
                                          hPrinter: v43.m_pszData,
                                          JobId: v54.m_nJobNumber,
                                          Level: 1u,
                                          pJob: v34,
                                          cbBuf: pcbNeeded,
                                          pcbNeeded: &v37),
                v40 = *((_DWORD *)v34 + 7),
                free(pMem: v34),
                v53.m_pszData == nullptr)
            || (v40 & 0x800) == 0 )
          {
            v52.m_pszData = (char *)1;
            v1 = v45;
            break;
          }
          v27 = v41;
          v1 = v45;
        }
        if ( !_AfxAbortProc(__formal: v46.m_hDC, a2: 0) )
          goto LABEL_65;
        v54.m_nCurPage += v27;
      }
      while ( v54.m_nCurPage != v51 );
    }
    if ( v54.m_bDocObject != 0 )
    {
LABEL_71:
      CWnd::EnableWindow(this: (CWnd *)result.m_pszData, bEnable: 1);
      v1->OnEndPrinting(this: v1, a2: &v46, a3: &v54);
      CWnd::DestroyWindow(this: &v36);
      CDC::Detach(this: &v46);
      ATL::CStringData::Release(this: (ATL::CStringData *)v50.m_pszData - 1);
      LOBYTE(v57) = 11;
      v36.__vftable = (CPrintingDialog_vtbl *)&CPrintingDialog::`vftable';
      CDialog::~CDialog(this: &v36);
      LOBYTE(v57) = 9;
      CDC::~CDC(this: &v46);
      ATL::CStringData::Release(this: (ATL::CStringData *)v49.m_pszData - 1);
      v7 = v47.m_pszData;
      goto LABEL_72;
    }
    if ( v52.m_pszData != nullptr )
    {
      AbortDoc(hdc: v46.m_hDC);
      goto LABEL_71;
    }
LABEL_68:
    EndDoc(hdc: v46.m_hDC);
    goto LABEL_71;
  }
  m_pCmdInfo = AfxGetModuleState()->m_pCurrentWinApp->m_pCmdInfo;
  if ( m_pCmdInfo == nullptr
    || m_pCmdInfo->m_nShellCommand != FilePrintTo
    || (DCA = CreateDCA(
                pwszDriver: m_pCmdInfo->m_strDriverName.m_pszData,
                pwszDevice: m_pCmdInfo->m_strPrinterName.m_pszData,
                pszPort: m_pCmdInfo->m_strPortName.m_pszData,
                pdm: nullptr),
        v54.m_pPD->m_pd->hDC = DCA,
        v54.m_pPD->m_pd->hDC != nullptr) )
  {
    v54.m_bDirect = 1;
    goto LABEL_7;
  }
  AfxMessageBox(nIDPrompt: 0xF106u, nType: 0, nIDHelp: 0xFFFFFFFF);
LABEL_74:
  v57 = -1;
  CPrintInfo::~CPrintInfo(this: &v54);
}

//------------------------------------------------------------------------------
// Address: 0x1035B81B
// Name: protected: int CPreviewView::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPreviewView::OnCreate(CPreviewView *this, tagCREATESTRUCTA *lpCreateStruct)
{
  int result; // eax

  result = CView::OnCreate(this, lpcs: lpCreateStruct);
  if ( result != -1 )
    this->m_pOrigView = *((CView **)lpCreateStruct->lpCreateParams + 3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1035B847
// Name: public: virtual void CPreviewView::OnPrepareDC(class CDC __near *,struct CPrintInfo __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewView::OnPrepareDC(CPreviewView *this, CDC *pDC, CPrintInfo *pInfo)
{
  if ( this->m_nZoomState != 0 )
  {
    if ( this->m_pPageInfo->sizeScaleRatio.cx != 0 )
      CScrollView::OnPrepareDC(this, pDC, pInfo);
  }
  else
  {
    CView::OnPrepareDC(this, pDC, pInfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1035B871
// Name: protected: void CPreviewView::OnHScroll(unsigned int,unsigned int,class CScrollBar __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewView::OnHScroll(
        CPreviewView *this,
        unsigned __int8 nSBCode,
        unsigned int nPos,
        CScrollBar *pScrollBar)
{
  if ( this->m_nZoomState != 0 )
    CScrollView::OnHScroll(this, nSBCode, nPos, pScrollBar);
}

//------------------------------------------------------------------------------
// Address: 0x1035B889
// Name: protected: void CPreviewView::OnUpdateZoomIn(class CCmdUI __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewView::OnUpdateZoomIn(CPreviewView *this, CCmdUI *pCmdUI)
{
  pCmdUI->Enable(this: pCmdUI, a2: this->m_nZoomState != 2);
}

//------------------------------------------------------------------------------
// Address: 0x1035B8AA
// Name: protected: void CPreviewView::OnUpdateZoomOut(class CCmdUI __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPreviewView::OnUpdateZoomOut(CPreviewView *this, CCmdUI *pCmdUI)
{
  pCmdUI->Enable(this: pCmdUI, a2: this->m_nZoomState != 0);
}

//------------------------------------------------------------------------------
// Address: 0x1035B8CA
// Name: public: virtual struct CRuntimeClass __near * CPreviewView::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CPreviewView::GetRuntimeClass(CPreviewView *this)
{
  return &CPreviewView::classCPreviewView;
}

//------------------------------------------------------------------------------
// Address: 0x1035D9F8
// Name: public: _AFX_COLOR_STATE::_AFX_COLOR_STATE(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_AFX_COLOR_STATE *__thiscall _AFX_COLOR_STATE::_AFX_COLOR_STATE(_AFX_COLOR_STATE *this)
{
  this->__vftable = (_AFX_COLOR_STATE_vtbl *)&_AFX_COLOR_STATE::`vftable';
  memset32(this->m_crSavedCustom, 0xFFFFFF, 0x10u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1035DA14
// Name: public: static class CNoTrackObject __near * CProcessLocal<class _AFX_COLOR_STATE>::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_AFX_COLOR_STATE *__stdcall CProcessLocal<_AFX_COLOR_STATE>::CreateObject()
{
  _AFX_COLOR_STATE *v0; // eax

  v0 = (_AFX_COLOR_STATE *)CNoTrackObject::operator new(nSize: 0x44u);
  if ( v0 != nullptr )
    return _AFX_COLOR_STATE::_AFX_COLOR_STATE(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1035DA29
// Name: public: struct CCommDlgWrapper::ChooseColorA_Type CCommDlgWrapper::GetProcAddress_ChooseColorA(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCommDlgWrapper::ChooseColorA_Type *__thiscall CCommDlgWrapper::GetProcAddress_ChooseColorA(
        CCommDlgWrapper *this,
        CCommDlgWrapper::ChooseColorA_Type *result)
{
  HMODULE ModuleHandleA; // eax

  if ( this->m__ChooseColorA.p == nullptr )
  {
    ModuleHandleA = CDllIsolationWrapperBase::GetModuleHandleA(this);
    this->m__ChooseColorA.p = (int (__stdcall *)(tagCHOOSECOLORA *))GetProcAddress(
                                                                      hModule: ModuleHandleA,
                                                                      lpProcName: "ChooseColorA");
  }
  result->p = (int (__stdcall *)(tagCHOOSECOLORA *))this->m__ChooseColorA;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1035DA58
// Name: public: int CCommDlgWrapper::_ChooseColorA(struct tagCHOOSECOLORA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CCommDlgWrapper::_ChooseColorA(CCommDlgWrapper *this, tagCHOOSECOLORA *unnamed1)
{
  AFX_MODULE_STATE *ModuleState; // eax
  BOOL v4; // eax
  int (__stdcall *p)(tagCHOOSECOLORA *); // eax
  BOOL v7; // esi
  DWORD LastError; // edi
  int v9; // [esp+0h] [ebp-34h]
  CCommDlgWrapper::ChooseColorA_Type v10; // [esp+10h] [ebp-24h] BYREF
  unsigned int ulActCtxCookie; // [esp+14h] [ebp-20h] BYREF
  int v12; // [esp+18h] [ebp-1Ch]
  int v13; // [esp+30h] [ebp-4h]

  ulActCtxCookie = 0;
  ModuleState = AfxGetModuleState();
  v4 = ActivateActCtx(hActCtx: ModuleState->m_hActCtx, lpCookie: &ulActCtxCookie);
  v12 = 0;
  if ( !v4 )
    return 0;
  v13 = 0;
  CCommDlgWrapper::GetProcAddress_ChooseColorA(this, result: &v10);
  p = this->m__ChooseColorA.p;
  if ( p == nullptr )
    AfxThrowInvalidArgException();
  v12 = ((int (__stdcall *)(tagCHOOSECOLORA *, int))p)(a1: unnamed1, a2: v9);
  v13 = -2;
  v7 = v12 == 0;
  if ( v12 != 0 )
    LastError = 0;
  else
    LastError = GetLastError();
  DeactivateActCtx(dwFlags: 0, ulCookie: ulActCtxCookie);
  if ( v7 )
    SetLastError(dwErrCode: LastError);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x1035DAFC
// Name: int AfxCtxChooseColorA(struct tagCHOOSECOLORA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall AfxCtxChooseColorA(tagCHOOSECOLORA *unnamed1)
{
  AFX_MODULE_STATE *ModuleState; // eax

  ModuleState = AfxGetModuleState();
  return CCommDlgWrapper::_ChooseColorA(this: *((CCommDlgWrapper **)ModuleState->m_pDllIsolationWrappers + 1), unnamed1);
}
