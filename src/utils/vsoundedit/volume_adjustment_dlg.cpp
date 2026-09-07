// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vsoundedit/volume_adjustment_dlg.cpp
// Functions: 48
// ============================================================

#include "utils\vsoundedit\volume_adjustment_dlg.h"

//------------------------------------------------------------------------------
// Address: 0x00405EC0
// Name: public: CVolumeAdjustmentDlg::CVolumeAdjustmentDlg(class CUtlVector<struct ScriptDefinition_t __near *,class CUtlMemory<struct ScriptDefinition_t __near *,int>> __near *,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CVolumeAdjustmentDlg *__thiscall CVolumeAdjustmentDlg::CVolumeAdjustmentDlg(
        CVolumeAdjustmentDlg *this,
        CUtlVector<ScriptDefinition_t *,CUtlMemory<ScriptDefinition_t *,int> > *pScriptList,
        CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0x84u, pParentWnd: nullptr);
  this->__vftable = (CVolumeAdjustmentDlg_vtbl *)&CVolumeAdjustmentDlg::`vftable';
  this->m_pScriptList = pScriptList;
  CWnd::CWnd(this: &this->m_SoundList);
  this->m_SoundList.__vftable = (CListCtrl_vtbl *)&CListCtrl::`vftable';
  CWnd::CWnd(this: &this->m_VolumeAdjSlider);
  this->m_VolumeAdjSlider.__vftable = (CSliderCtrl_vtbl *)&CSliderCtrl::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00405F20
// Name: protected: virtual void CVolumeAdjustmentDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVolumeAdjustmentDlg::DoDataExchange(CVolumeAdjustmentDlg *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x40D, rControl: (HWND__ *)&this->m_SoundList);
  DDX_Control(pDX, nIDC: (HWND__ *)0x40E, rControl: (HWND__ *)&this->m_VolumeAdjSlider);
}

//------------------------------------------------------------------------------
// Address: 0x00405FB0
// Name: protected: virtual struct AFX_MSGMAP const __near * CVolumeAdjustmentDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CVolumeAdjustmentDlg::GetMessageMap(CVolumeAdjustmentDlg *this)
{
  return (const AFX_MSGMAP *)&off_5357C0;
}

//------------------------------------------------------------------------------
// Address: 0x00406060
// Name: protected: void CVolumeAdjustmentDlg::UpdateListValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVolumeAdjustmentDlg::UpdateListValues(CVolumeAdjustmentDlg *this)
{
  CUtlVector<ScriptDefinition_t *,CUtlMemory<ScriptDefinition_t *,int> > *m_pScriptList; // ebx
  CAfxStringMgr *StringManager; // eax
  char *m_pszData; // eax
  int v5; // esi
  int v6; // xmm1_4
  float v7; // xmm0_4
  int v8; // xmm1_4
  float v9; // xmm0_4
  volatile signed __int32 *v10; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-54h]
  HWND__ *v12; // [esp-8h] [ebp-54h]
  HWND__ *v13; // [esp-8h] [ebp-54h]
  tagLVITEMA item; // [esp+14h] [ebp-38h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strVol; // [esp+48h] [ebp-4h] BYREF

  m_pScriptList = this->m_pScriptList;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v5 = 0;
  strVol.m_pszData = m_pszData;
  if ( m_pScriptList->m_Size > 0 )
  {
    do
    {
      item.iItem = v5;
      item.iSubItem = 0;
      m_hWnd = this->m_SoundList.m_hWnd;
      item.pszText = m_pScriptList->m_Memory.m_pMemory[v5]->m_strName.m_pszData;
      item.mask = 1;
      SendMessageA(hWnd: m_hWnd, Msg: 0x1006u, wParam: 0, lParam: (LPARAM)&item);
      v6 = 0;
      item.iItem = v5;
      item.iSubItem = 1;
      v7 = m_pScriptList->m_Memory.m_pMemory[v5]->m_flVolumeLow + this->m_flVolumeAdjustment;
      if ( v7 < 0.0 || (v6 = 1065353216, v7 > 1.0) )
        v7 = *(float *)&v6;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(this: &strVol, pszFormat: "%.2f", v7);
      v12 = this->m_SoundList.m_hWnd;
      item.pszText = strVol.m_pszData;
      item.mask = 1;
      SendMessageA(hWnd: v12, Msg: 0x1006u, wParam: 0, lParam: (LPARAM)&item);
      v8 = 0;
      item.iItem = v5;
      item.iSubItem = 2;
      v9 = m_pScriptList->m_Memory.m_pMemory[v5]->m_flVolumeHigh + this->m_flVolumeAdjustment;
      if ( v9 < 0.0 || (v8 = 1065353216, v9 > 1.0) )
        v9 = *(float *)&v8;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(this: &strVol, pszFormat: "%.2f", v9);
      v13 = this->m_SoundList.m_hWnd;
      item.pszText = strVol.m_pszData;
      item.mask = 1;
      SendMessageA(hWnd: v13, Msg: 0x1006u, wParam: 0, lParam: (LPARAM)&item);
      ++v5;
    }
    while ( v5 < m_pScriptList->m_Size );
    m_pszData = strVol.m_pszData;
  }
  v10 = (volatile signed __int32 *)(m_pszData - 16);
  if ( _InterlockedDecrement(v10 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v10 + 4))(a1: v10);
}

//------------------------------------------------------------------------------
// Address: 0x004061F0
// Name: protected: virtual int CVolumeAdjustmentDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CVolumeAdjustmentDlg::OnInitDialog(CVolumeAdjustmentDlg *this)
{
  int v2; // esi
  HWND__ *m_hWnd; // ecx
  CUtlVector<ScriptDefinition_t *,CUtlMemory<ScriptDefinition_t *,int> > *m_pScriptList; // edi
  CAfxStringMgr *StringManager; // eax
  int v7; // eax
  char *v8; // eax
  int v9; // edi
  double v10; // st7
  HWND__ *v11; // [esp-4h] [ebp-6Ch]
  HWND__ *v12; // [esp-4h] [ebp-6Ch]
  HWND__ *v13; // [esp-4h] [ebp-6Ch]
  double X; // [esp+4h] [ebp-64h]
  tagLVITEMA item; // [esp+18h] [ebp-50h] BYREF
  CRect wRect; // [esp+4Ch] [ebp-1Ch] BYREF
  float flMaxValue; // [esp+5Ch] [ebp-Ch]
  float flMinValue; // [esp+60h] [ebp-8h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strVol; // [esp+64h] [ebp-4h] BYREF

  CDialog::OnInitDialog(this);
  v2 = 0;
  if ( this->m_pScriptList == nullptr )
    return 0;
  m_hWnd = this->m_SoundList.m_hWnd;
  memset(&wRect, 0, sizeof(wRect));
  GetWindowRect(hWnd: m_hWnd, lpRect: &wRect);
  CListCtrl::InsertColumn(
    this: &this->m_SoundList,
    nCol: 0,
    lpszColumnHeading: "Sound Name",
    nFormat: 0,
    nWidth: (wRect.right - wRect.left) / 2,
    nSubItem: -1);
  CListCtrl::InsertColumn(
    this: &this->m_SoundList,
    nCol: 1,
    lpszColumnHeading: "Volume Min",
    nFormat: 0,
    nWidth: (wRect.right - wRect.left) / 4,
    nSubItem: 1);
  CListCtrl::InsertColumn(
    this: &this->m_SoundList,
    nCol: 2,
    lpszColumnHeading: "Volume Max",
    nFormat: 0,
    nWidth: (wRect.right - wRect.left) / 4,
    nSubItem: 2);
  m_pScriptList = this->m_pScriptList;
  flMinValue = 0.0;
  flMaxValue = 1.0;
  if ( m_pScriptList->m_Size > 0 )
  {
    do
    {
      item.iItem = v2;
      item.iSubItem = 0;
      v11 = this->m_SoundList.m_hWnd;
      item.pszText = m_pScriptList->m_Memory.m_pMemory[v2]->m_strName.m_pszData;
      item.mask = 1;
      SendMessageA(hWnd: v11, Msg: 0x1007u, wParam: 0, lParam: (LPARAM)&item);
      item.iItem = v2;
      item.iSubItem = 1;
      StringManager = AfxGetStringManager();
      if ( StringManager == nullptr )
        ATL::AtlThrowImpl(hr: -2147467259);
      v7 = (int)StringManager->GetNilString(this: StringManager);
      X = m_pScriptList->m_Memory.m_pMemory[v2]->m_flVolumeLow;
      strVol.m_pszData = (char *)(v7 + 16);
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(this: &strVol, pszFormat: "%.2f", X);
      v12 = this->m_SoundList.m_hWnd;
      item.pszText = strVol.m_pszData;
      item.mask = 1;
      SendMessageA(hWnd: v12, Msg: 0x1006u, wParam: 0, lParam: (LPARAM)&item);
      if ( m_pScriptList->m_Memory.m_pMemory[v2]->m_flVolumeLow > flMinValue )
        flMinValue = m_pScriptList->m_Memory.m_pMemory[v2]->m_flVolumeLow;
      item.iItem = v2;
      item.iSubItem = 2;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
        this: &strVol,
        pszFormat: "%.2f",
        m_pScriptList->m_Memory.m_pMemory[v2]->m_flVolumeHigh);
      v13 = this->m_SoundList.m_hWnd;
      item.pszText = strVol.m_pszData;
      item.mask = 1;
      SendMessageA(hWnd: v13, Msg: 0x1006u, wParam: 0, lParam: (LPARAM)&item);
      if ( flMaxValue > m_pScriptList->m_Memory.m_pMemory[v2]->m_flVolumeHigh )
        flMaxValue = m_pScriptList->m_Memory.m_pMemory[v2]->m_flVolumeHigh;
      v8 = strVol.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)strVol.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v8 + 4))(a1: v8);
      ++v2;
    }
    while ( v2 < m_pScriptList->m_Size );
  }
  SendMessageA(hWnd: this->m_VolumeAdjSlider.m_hWnd, Msg: 0x414u, wParam: 0xAu, lParam: 0);
  CSliderCtrl::SetRange(this: &this->m_VolumeAdjSlider, nMin: -100, nMax: 100, bRedraw: 1);
  SendMessageA(hWnd: this->m_VolumeAdjSlider.m_hWnd, Msg: 0x405u, wParam: 1u, lParam: 0);
  v9 = (int)ceil(X: COERCE_FLOAT(COERCE_UNSIGNED_INT(flMinValue * 100.0) ^ _mask__NegFloat_));
  v10 = ceil(X: (float)(100.0 - (float)(flMaxValue * 100.0)));
  CSliderCtrl::SetSelection(this: &this->m_VolumeAdjSlider, nMin: v9, nMax: (int)v10);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004064D0
// Name: protected: virtual void CVolumeAdjustmentDlg::OnHScroll(unsigned int,unsigned int,class CScrollBar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVolumeAdjustmentDlg::OnHScroll(
        CVolumeAdjustmentDlg *this,
        unsigned int nSBCode,
        unsigned int nPos,
        CScrollBar *pScrollBar)
{
  CWnd::OnHScroll(this, __formal: nSBCode, a3: nPos, pScrollBar);
  if ( (nSBCode == 4 || nSBCode == 5)
    && CObject::IsKindOf(this: pScrollBar, pClass: &CSliderCtrl::classCSliderCtrl) != 0
    && pScrollBar == (CScrollBar *)&this->m_VolumeAdjSlider )
  {
    this->m_flVolumeAdjustment = (float)SendMessageA(
                                          hWnd: this->m_VolumeAdjSlider.m_hWnd,
                                          Msg: 0x400u,
                                          wParam: 0,
                                          lParam: 0)
                               * 0.0099999998;
    CVolumeAdjustmentDlg::UpdateListValues(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004213BF
// Name: public: virtual CListCtrl::~CListCtrl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CListCtrl::~CListCtrl(CListCtrl *this)
{
  this->__vftable = (CListCtrl_vtbl *)&CListCtrl::`vftable';
  CWnd::DestroyWindow(this);
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x004213F0
// Name: public: int CListCtrl::GetItemRect(int,struct tagRECT __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CListCtrl::GetItemRect(CListCtrl *this, WPARAM nItem, tagRECT *lpRect, unsigned int nCode)
{
  lpRect->left = nCode;
  return SendMessageA(hWnd: this->m_hWnd, Msg: 0x100Eu, wParam: nItem, lParam: (LPARAM)lpRect);
}

//------------------------------------------------------------------------------
// Address: 0x00421413
// Name: public: int CListCtrl::HitTest(class CPoint,unsigned int __near *)const
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CListCtrl::HitTest(CListCtrl *this, tagPOINT pt, unsigned int *pFlags)
{
  LRESULT result; // eax
  tagLVHITTESTINFO hti; // [esp+4h] [ebp-1Ch] BYREF

  hti.pt = pt;
  result = SendMessageA(hWnd: this->m_hWnd, Msg: 0x1012u, wParam: 0, lParam: (LPARAM)&hti);
  if ( pFlags != nullptr )
    *pFlags = hti.flags;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00421463
// Name: public: int CListCtrl::SetItem(int,int,unsigned int,char const __near *,int,unsigned int,unsigned int,long,int)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CListCtrl::SetItem(
        CListCtrl *this,
        int nItem,
        int nSubItem,
        unsigned int nMask,
        char *lpszItem,
        int nImage,
        unsigned int nState,
        unsigned int nStateMask,
        int lParam,
        int nIndent)
{
  tagLVITEMA lvi; // [esp+0h] [ebp-3Ch] BYREF

  lvi.mask = nMask;
  lvi.iItem = nItem;
  lvi.iSubItem = nSubItem;
  lvi.stateMask = nStateMask;
  lvi.state = nState;
  lvi.pszText = lpszItem;
  lvi.iImage = nImage;
  lvi.lParam = lParam;
  lvi.iIndent = nIndent;
  return SendMessageA(hWnd: this->m_hWnd, Msg: 0x1006u, wParam: 0, lParam: (LPARAM)&lvi);
}

//------------------------------------------------------------------------------
// Address: 0x004214B9
// Name: public: int CListCtrl::SetItemState(int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CListCtrl::SetItemState(CListCtrl *this, WPARAM nItem, unsigned int nState, unsigned int nStateMask)
{
  tagLVITEMA lvi; // [esp+0h] [ebp-3Ch] BYREF

  lvi.stateMask = nStateMask;
  lvi.state = nState;
  return SendMessageA(hWnd: this->m_hWnd, Msg: 0x102Bu, wParam: nItem, lParam: (LPARAM)&lvi);
}

//------------------------------------------------------------------------------
// Address: 0x004214E6
// Name: public: int CListCtrl::SetItemText(int,int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CListCtrl::SetItemText(CListCtrl *this, WPARAM nItem, int nSubItem, char *lpszText)
{
  tagLVITEMA lvi; // [esp+0h] [ebp-3Ch] BYREF

  lvi.iSubItem = nSubItem;
  lvi.pszText = lpszText;
  return SendMessageA(hWnd: this->m_hWnd, Msg: 0x102Eu, wParam: nItem, lParam: (LPARAM)&lvi);
}

//------------------------------------------------------------------------------
// Address: 0x00421513
// Name: public: unsigned long CListCtrl::GetItemData(int)const
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
unsigned int __thiscall CListCtrl::GetItemData(CListCtrl *this, int nItem)
{
  HWND__ *m_hWnd; // [esp-10h] [ebp-50h]
  _BYTE lvi[60]; // [esp+4h] [ebp-3Ch] OVERLAPPED BYREF

  memset(dst: (int)lvi, value: nullptr, count: sizeof(lvi));
  *(_DWORD *)&lvi[4] = nItem;
  m_hWnd = this->m_hWnd;
  *(_DWORD *)lvi = 4;
  SendMessageA(hWnd: m_hWnd, Msg: 0x1005u, wParam: 0, lParam: (LPARAM)lvi);
  return *(_DWORD *)&lvi[32];
}

//------------------------------------------------------------------------------
// Address: 0x00421557
// Name: protected: virtual int CListCtrl::OnChildNotify(unsigned int,unsigned int,long,long __near *)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CListCtrl::OnChildNotify(
        CListCtrl *this,
        unsigned int message,
        unsigned int wParam,
        tagNMHDR *lParam,
        int *pResult)
{
  if ( message != 43 )
    return CWnd::OnChildNotify(this, uMsg: message, wParam, lParam, pResult);
  this->DrawItem(this, a2: (tagDRAWITEMSTRUCT *)lParam);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00421791
// Name: public: virtual int CSliderCtrl::Create(unsigned long,struct tagRECT const __near &,class CWnd __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSliderCtrl::Create(
        CSliderCtrl *this,
        unsigned int dwStyle,
        const tagRECT *rect,
        CWnd *pParentWnd,
        unsigned int nID)
{
  AfxEndDeferRegisterClass(fToRegister: 4096);
  return this->Create(
           this,
           a2: "msctls_trackbar32",
           a3: nullptr,
           a4: dwStyle,
           a5: rect,
           a6: pParentWnd,
           a7: nID,
           a8: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004217C4
// Name: public: virtual CSliderCtrl::~CSliderCtrl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSliderCtrl::~CSliderCtrl(CSliderCtrl *this)
{
  this->__vftable = (CSliderCtrl_vtbl *)&CSliderCtrl::`vftable';
  CWnd::DestroyWindow(this);
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x004217F5
// Name: public: void CSliderCtrl::SetSelection(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSliderCtrl::SetSelection(CSliderCtrl *this, LPARAM nMin, LPARAM nMax)
{
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x40Bu, wParam: 0, lParam: nMin);
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x40Cu, wParam: 0, lParam: nMax);
}

//------------------------------------------------------------------------------
// Address: 0x00421982
// Name: public: virtual struct CRuntimeClass __near * CSliderCtrl::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CSliderCtrl::GetRuntimeClass(CSliderCtrl *this)
{
  return &CSliderCtrl::classCSliderCtrl;
}

//------------------------------------------------------------------------------
// Address: 0x0042199A
// Name: public: virtual struct CRuntimeClass __near * CListCtrl::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CListCtrl::GetRuntimeClass(CListCtrl *this)
{
  return &CListCtrl::classCListCtrl;
}

//------------------------------------------------------------------------------
// Address: 0x00421A0F
// Name: public: int CListCtrl::InsertColumn(int,char const __near *,int,int,int)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CListCtrl::InsertColumn(
        CListCtrl *this,
        WPARAM nCol,
        char *lpszColumnHeading,
        int nFormat,
        int nWidth,
        int nSubItem)
{
  tagLVCOLUMNA column; // [esp+0h] [ebp-2Ch] BYREF

  column.pszText = lpszColumnHeading;
  column.fmt = nFormat;
  column.mask = 5;
  if ( nWidth != -1 )
  {
    column.mask = 7;
    column.cx = nWidth;
  }
  if ( nSubItem != -1 )
  {
    column.mask |= 8u;
    column.iSubItem = nSubItem;
  }
  return SendMessageA(hWnd: this->m_hWnd, Msg: 0x101Bu, wParam: nCol, lParam: (LPARAM)&column);
}

//------------------------------------------------------------------------------
// Address: 0x00421A64
// Name: public: int CListCtrl::InsertItem(unsigned int,int,char const __near *,unsigned int,unsigned int,int,long)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CListCtrl::InsertItem(
        CListCtrl *this,
        unsigned int nMask,
        int nItem,
        char *lpszItem,
        unsigned int nState,
        unsigned int nStateMask,
        int nImage,
        int lParam)
{
  tagLVITEMA item; // [esp+0h] [ebp-3Ch] BYREF

  item.mask = nMask;
  item.iItem = nItem;
  item.iSubItem = 0;
  item.pszText = lpszItem;
  item.state = nState;
  item.stateMask = nStateMask;
  item.iImage = nImage;
  item.lParam = lParam;
  return SendMessageA(hWnd: this->m_hWnd, Msg: 0x1007u, wParam: 0, lParam: (LPARAM)&item);
}

//------------------------------------------------------------------------------
// Address: 0x00421AB2
// Name: public: int CListCtrl::SetItem(int,int,unsigned int,char const __near *,int,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CListCtrl::SetItem(
        CListCtrl *this,
        int nItem,
        int nSubItem,
        unsigned int nMask,
        char *lpszItem,
        int nImage,
        unsigned int nState,
        unsigned int nStateMask,
        int lParam)
{
  return CListCtrl::SetItem(this, nItem, nSubItem, nMask, lpszItem, nImage, nState, nStateMask, lParam, nIndent: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00421ADA
// Name: public: void CSliderCtrl::SetRange(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSliderCtrl::SetRange(CSliderCtrl *this, LPARAM nMin, LPARAM nMax, WPARAM bRedraw)
{
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x407u, wParam: bRedraw, lParam: nMin);
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x408u, wParam: bRedraw, lParam: nMax);
}

//------------------------------------------------------------------------------
// Address: 0x00421F34
// Name: protected: void CListCtrl::RemoveImageList(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CListCtrl::RemoveImageList(CListCtrl *this, WPARAM nImageList)
{
  _IMAGELIST *v3; // eax

  v3 = (_IMAGELIST *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x1002u, wParam: nImageList, lParam: 0);
  if ( CImageList::FromHandlePermanent(h: v3) != nullptr )
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x1003u, wParam: nImageList, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00421F71
// Name: protected: void CListCtrl::OnNcDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CListCtrl::OnNcDestroy(CListCtrl *this)
{
  CListCtrl::RemoveImageList(this, nImageList: 0);
  CListCtrl::RemoveImageList(this, nImageList: 1u);
  CListCtrl::RemoveImageList(this, nImageList: 2u);
  CWnd::OnNcDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x004220A3
// Name: protected: virtual struct AFX_MSGMAP const __near * CListCtrl::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CListCtrl::GetMessageMap(CListCtrl *this)
{
  return &messageMap_2;
}

//------------------------------------------------------------------------------
// Address: 0x00431CAE
// Name: public: class CImageList __near * CListCtrl::SetImageList(class CImageList __near *,int)
// Source: json
//------------------------------------------------------------------------------
CImageList *__thiscall CListCtrl::SetImageList(CListCtrl *this, CImageList *pImageList, WPARAM nImageList)
{
  _IMAGELIST *m_hImageList; // eax
  _IMAGELIST *v4; // eax

  m_hImageList = (_IMAGELIST *)pImageList;
  if ( pImageList != nullptr )
    m_hImageList = pImageList->m_hImageList;
  v4 = (_IMAGELIST *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x1003u, wParam: nImageList, lParam: (LPARAM)m_hImageList);
  return CImageList::FromHandle(h: v4);
}

//------------------------------------------------------------------------------
// Address: 0x0043347B
// Name: public: class CEdit __near * CListCtrl::EditLabel(int)
// Source: json
//------------------------------------------------------------------------------
CEdit *__thiscall CListCtrl::EditLabel(CListCtrl *this, WPARAM nItem)
{
  HWND__ *v2; // eax

  v2 = (HWND__ *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x1017u, wParam: nItem, lParam: 0);
  return (CEdit *)CWnd::FromHandle(hWnd: v2);
}

//------------------------------------------------------------------------------
// Address: 0x0043349D
// Name: public: class CEdit __near * CListCtrl::GetEditControl(void)const
// Source: json
//------------------------------------------------------------------------------
CEdit *__thiscall CListCtrl::GetEditControl(CListCtrl *this)
{
  HWND__ *v1; // eax

  v1 = (HWND__ *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x1018u, wParam: 0, lParam: 0);
  return (CEdit *)CWnd::FromHandle(hWnd: v1);
}

//------------------------------------------------------------------------------
// Address: 0x0047667A
// Name: public: void CMFCAcceleratorKey::Format(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCAcceleratorKey::Format(
        CMFCAcceleratorKey *this,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *str)
{
  tagACCEL *m_lpAccel; // eax
  tagACCEL *v4; // eax

  ATL::CSimpleStringT<char,0>::Empty(this: str);
  m_lpAccel = this->m_lpAccel;
  if ( m_lpAccel != nullptr )
  {
    if ( (m_lpAccel->fVirt & 8) != 0 )
      CMFCAcceleratorKey::AddVirtKeyStr(this, str, uiVirtKey: 0x11u, bLast: 0);
    if ( (this->m_lpAccel->fVirt & 4) != 0 )
      CMFCAcceleratorKey::AddVirtKeyStr(this, str, uiVirtKey: 0x10u, bLast: 0);
    if ( (this->m_lpAccel->fVirt & 0x10) != 0 )
      CMFCAcceleratorKey::AddVirtKeyStr(this, str, uiVirtKey: 0x12u, bLast: 0);
    v4 = this->m_lpAccel;
    if ( (v4->fVirt & 1) != 0 )
    {
      CMFCAcceleratorKey::AddVirtKeyStr(this, str, uiVirtKey: v4->key, bLast: 1);
    }
    else if ( v4->key != 27 )
    {
      ATL::CSimpleStringT<char,0>::AppendChar(this: str, ch: v4->key);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421B0F
// Name: public: CImageList::CImageList(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CImageList *__thiscall CImageList::CImageList(CImageList *this)
{
  this->m_hImageList = nullptr;
  this->__vftable = (CImageList_vtbl *)&CImageList::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00421B1C
// Name: public: static class CObject __near * CImageList::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CObject *__stdcall CImageList::CreateObject()
{
  CObject *result; // eax

  result = (CObject *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (CObject_vtbl *)&CImageList::`vftable';
  result[1].__vftable = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00421B36
// Name: public: static void ConstructDestruct<class CImageList>::Construct(class CObject __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall ConstructDestruct<CImageList>::Construct(CObject *pObject)
{
  if ( pObject != nullptr )
  {
    pObject[1].__vftable = nullptr;
    pObject->__vftable = (CObject_vtbl *)&CImageList::`vftable';
  }
}

//------------------------------------------------------------------------------
// Address: 0x00431CD9
// Name: public: virtual unsigned long CMFCListCtrl::OnGetCellTextColor(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LRESULT __thiscall CMFCListCtrl::OnGetCellTextColor(CMFCListCtrl *this, int __formal, int __formala)
{
  return SendMessageA(hWnd: this->m_hWnd, Msg: 0x1023u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00431CEE
// Name: public: virtual unsigned long CMFCListCtrl::OnGetCellBkColor(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LRESULT __thiscall CMFCListCtrl::OnGetCellBkColor(CMFCListCtrl *this, int __formal, int __formala)
{
  return SendMessageA(hWnd: this->m_hWnd, Msg: 0x1000u, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00431D2A
// Name: protected: virtual void CMFCShellListCtrl::DoDefault(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CMFCShellListCtrl::DoDefault(CMFCShellListCtrl *this@<ecx>, int a2@<edi>, const _ITEMIDLIST **iItem)
{
  IShellFolder *v4; // ecx
  HMENU PopupMenu; // edi
  UINT MenuDefaultItem; // eax
  HWND Parent; // eax
  CWnd *v8; // eax
  HWND v9; // eax
  HWND v10; // eax
  CWnd *v11; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-84h]
  HWND__ *v13; // [esp-4h] [ebp-78h]
  _BYTE lvItem[60]; // [esp+8h] [ebp-6Ch] OVERLAPPED BYREF
  _CMINVOKECOMMANDINFO cmi; // [esp+44h] [ebp-30h] BYREF
  unsigned int idCmd; // [esp+68h] [ebp-Ch]
  unsigned int ulAttrs; // [esp+6Ch] [ebp-8h] BYREF
  IShellFolder *psfFolder; // [esp+70h] [ebp-4h] BYREF

  memset(dst: (int)lvItem, value: nullptr, count: sizeof(lvItem));
  *(_DWORD *)&lvItem[4] = iItem;
  m_hWnd = this->m_hWnd;
  *(_DWORD *)lvItem = 4;
  if ( SendMessageA(hWnd: m_hWnd, Msg: 0x1005u, wParam: 0, lParam: (LPARAM)lvItem) != 0 )
  {
    idCmd = *(_DWORD *)&lvItem[32];
    if ( *(_DWORD *)&lvItem[32] != 0 )
    {
      v4 = **(IShellFolder ***)&lvItem[32];
      if ( **(_DWORD **)&lvItem[32] != 0 )
      {
        iItem = (const _ITEMIDLIST **)(*(_DWORD *)&lvItem[32] + 8);
        if ( *(_DWORD *)(*(_DWORD *)&lvItem[32] + 8) != 0 )
        {
          psfFolder = v4;
          if ( v4 != nullptr )
          {
            v4->AddRef(this: v4);
          }
          else if ( SHGetDesktopFolder(ppshf: &psfFolder) < 0 )
          {
            return;
          }
          if ( psfFolder != nullptr )
          {
            ulAttrs = 0x20000000;
            ((void (__stdcall *)(IShellFolder *, int, const _ITEMIDLIST **, unsigned int *, int))psfFolder->GetAttributesOf)(
              a1: psfFolder,
              a2: 1,
              a3: iItem,
              a4: &ulAttrs,
              a5: a2);
            if ( (ulAttrs & 0x20000000) != 0 )
            {
              this->DisplayFolder(this, a2: (_AFX_SHELLITEMINFO *)idCmd);
            }
            else if ( psfFolder->GetUIObjectOf(
                        this: psfFolder,
                        a2: this->m_hWnd,
                        a3: 1u,
                        a4: iItem,
                        a5: &IID_IContextMenu,
                        a6: nullptr,
                        a7: (void **)&iItem) >= 0 )
            {
              PopupMenu = CreatePopupMenu();
              if ( PopupMenu != nullptr
                && (*(int (__stdcall **)(const _ITEMIDLIST **, HMENU, _DWORD, int, int, int))&(*iItem)[4].mkid.cb)(
                     a1: iItem,
                     a2: PopupMenu,
                     a3: 0,
                     a4: 1,
                     a5: 0x7FFF,
                     a6: 5) >= 0 )
              {
                MenuDefaultItem = GetMenuDefaultItem(hMenu: PopupMenu, fByPos: 0, gmdiFlags: 0);
                idCmd = MenuDefaultItem;
                if ( MenuDefaultItem != 0 && MenuDefaultItem != -1 )
                {
                  v13 = this->m_hWnd;
                  cmi.cbSize = 36;
                  cmi.fMask = 0;
                  Parent = GetParent(hWnd: v13);
                  v8 = CWnd::FromHandle(hWnd: Parent);
                  if ( v8 != nullptr )
                    cmi.hwnd = v8->m_hWnd;
                  else
                    cmi.hwnd = nullptr;
                  cmi.lpVerb = (const char *)(idCmd - 1);
                  cmi.lpParameters = nullptr;
                  cmi.lpDirectory = nullptr;
                  cmi.nShow = 1;
                  cmi.dwHotKey = 0;
                  cmi.hIcon = nullptr;
                  if ( (*(int (__stdcall **)(const _ITEMIDLIST **, _CMINVOKECOMMANDINFO *))((char *)&(*iItem)[5].mkid.cb
                                                                                          + 1))(
                         a1: iItem,
                         a2: &cmi) >= 0 )
                  {
                    v9 = GetParent(hWnd: this->m_hWnd);
                    if ( CWnd::FromHandle(hWnd: v9) != nullptr )
                    {
                      v10 = GetParent(hWnd: this->m_hWnd);
                      v11 = CWnd::FromHandle(hWnd: v10);
                      SendMessageA(hWnd: v11->m_hWnd, Msg: AFX_WM_ON_AFTER_SHELL_COMMAND, wParam: idCmd, lParam: 0);
                    }
                  }
                }
              }
              (*(void (__stdcall **)(const _ITEMIDLIST **))(*iItem)[2].mkid.abID)(a1: iItem);
            }
            ((void (__cdecl *)(IShellFolder *))psfFolder->Release)(a1: psfFolder);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00431EF8
// Name: protected: void CMFCShellListCtrl::OnReturn(struct tagNMHDR __near *,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCShellListCtrl::OnReturn(CMFCShellListCtrl *this, tagNMHDR *__formal, int *pResult)
{
  LRESULT v4; // eax

  v4 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x100Cu, wParam: 0xFFFFFFFF, lParam: 1);
  if ( v4 != -1 )
    this->DoDefault(this, a2: v4);
  *pResult = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00431F2D
// Name: public: virtual int CMFCShellListCtrl::OnCompareItems(long,long,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCShellListCtrl::OnCompareItems(CMFCShellListCtrl *this, _DWORD *lParam1, int lParam2, int iColumn)
{
  int v4; // ecx
  int v5; // eax
  _SHFILEINFOA sfi2; // [esp+10h] [ebp-71Ch] BYREF
  _SHFILEINFOA sfi1; // [esp+170h] [ebp-5BCh] BYREF
  CFileStatus fs1; // [esp+2D0h] [ebp-45Ch] BYREF
  CFileStatus fs2; // [esp+3F8h] [ebp-334h] BYREF
  char szPath1[260]; // [esp+520h] [ebp-20Ch] BYREF
  char szPath2[260]; // [esp+624h] [ebp-108h] BYREF

  if ( lParam1 == nullptr || lParam2 == 0 )
    AfxThrowInvalidArgException();
  v4 = 0;
  memset(&fs1, 0, 24);
  memset(&fs2, 0, 24);
  if ( iColumn != 0 )
  {
    switch ( iColumn )
    {
      case 1:
        goto LABEL_9;
      case 2:
        if ( SHGetFileInfoA(
               pszPath: (LPCSTR)lParam1[1],
               dwFileAttributes: 0,
               psfi: &sfi1,
               cbFileInfo: 0x160u,
               uFlags: 0x408u) != 0
          && SHGetFileInfoA(
               pszPath: *(LPCSTR *)(lParam2 + 4),
               dwFileAttributes: 0,
               psfi: &sfi2,
               cbFileInfo: 0x160u,
               uFlags: 0x408u) != 0 )
        {
          return lstrcmpiA(lpString1: sfi1.szTypeName, lpString2: sfi2.szTypeName);
        }
        else
        {
          return 0;
        }
      case 3:
LABEL_9:
        if ( SHGetPathFromIDListA(pidl: (LPCITEMIDLIST)lParam1[1], pszPath: szPath1)
          && CFile::GetStatus(lpszFileName: szPath1, rStatus: &fs1, pTM: nullptr) != 0 )
        {
          if ( !SHGetPathFromIDListA(pidl: *(LPCITEMIDLIST *)(lParam2 + 4), pszPath: szPath2)
            || CFile::GetStatus(lpszFileName: szPath2, rStatus: &fs2, pTM: nullptr) == 0 )
          {
            return 1;
          }
          v4 = 1;
          if ( iColumn == 1 )
          {
            if ( (fs1.m_attribute & 0x10) == 0 )
            {
              if ( (fs2.m_attribute & 0x10) != 0 || HIDWORD(fs1.m_size) > HIDWORD(fs2.m_size) )
                return v4;
              if ( HIDWORD(fs1.m_size) >= HIDWORD(fs2.m_size) && LODWORD(fs1.m_size) >= LODWORD(fs2.m_size) )
                return fs1.m_size > fs2.m_size;
            }
          }
          else if ( !ATL::CTime::operator<(this: &fs1.m_mtime, time: fs2.m_mtime) )
          {
            return ATL::CTime::operator>(this: &fs1.m_mtime, time: fs2.m_mtime);
          }
        }
        return -1;
      default:
        break;
    }
  }
  else
  {
    v5 = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)*lParam1 + 28))(
           a1: *lParam1,
           a2: 0,
           a3: lParam1[2],
           a4: *(_DWORD *)(lParam2 + 8));
    if ( v5 < 0 )
      return 0;
    return (__int16)v5;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0043216E
// Name: public: virtual void CMFCShellListCtrl::OnSetColumns(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCShellListCtrl::OnSetColumns(CMFCShellListCtrl *this)
{
  CMFCHeaderCtrl *v2; // eax
  LRESULT v3; // eax
  int j; // edi
  const char *szName[4]; // [esp+8h] [ebp-14h]
  LRESULT i; // [esp+18h] [ebp-4h]

  v2 = this->GetHeaderCtrl(this);
  v3 = SendMessageA(hWnd: v2->m_hWnd, Msg: 0x1200u, wParam: 0, lParam: 0);
  if ( v3 > 0 )
  {
    for ( i = v3; i != 0; --i )
      SendMessageA(hWnd: this->m_hWnd, Msg: 0x101Cu, wParam: 0, lParam: 0);
  }
  szName[0] = "Name";
  szName[1] = "Size";
  szName[2] = "Type";
  szName[3] = "Modified";
  for ( j = 0; j < 4; ++j )
    CListCtrl::InsertColumn(
      this,
      nCol: j,
      lpszColumnHeading: (char *)szName[j],
      nFormat: j == 1,
      nWidth: 100,
      nSubItem: j);
}

//------------------------------------------------------------------------------
// Address: 0x004321F0
// Name: protected: int CMFCShellListCtrl::InitList(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCShellListCtrl::InitList(CMFCShellListCtrl *this)
{
  _IMAGELIST *ShellImageList; // eax
  CImageList *v4; // eax
  _IMAGELIST *v5; // eax
  CImageList *v6; // eax
  _AFX_SHELLITEMINFO info; // [esp+8h] [ebp-Ch] BYREF

  if ( afxShellManager == nullptr )
    return 0;
  CWnd::ModifyStyle(this, dwRemove: 0, dwAdd: 0x40u, nFlags: 0);
  ShellImageList = CMFCShellListCtrl::GetShellImageList(this, bLarge: 1);
  v4 = CImageList::FromHandle(h: ShellImageList);
  CListCtrl::SetImageList(this, pImageList: v4, nImageList: 0);
  v5 = CMFCShellListCtrl::GetShellImageList(this, bLarge: 0);
  v6 = CImageList::FromHandle(h: v5);
  CListCtrl::SetImageList(this, pImageList: v6, nImageList: 1u);
  this->OnSetColumns(this);
  if ( this->m_psfCurFolder == nullptr )
  {
    memset(&info, 0, sizeof(info));
    if ( SHGetSpecialFolderLocation(hwnd: nullptr, csidl: 0, ppidl: &info.pidlFQ) >= 0 )
    {
      this->DisplayFolder(this, a2: &info);
      CShellManager::FreeItem(this: afxShellManager, pidl: info.pidlFQ);
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00432294
// Name: protected: void CMFCShellListCtrl::OnContextMenu(class CWnd __near *,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge CMFCShellListCtrl::OnContextMenu(
        CMFCShellListCtrl *this@<ecx>,
        int a2@<edi>,
        CWnd *__formal,
        CPoint point)
{
  _ITEMIDLIST **v5; // edx
  WPARAM v6; // eax
  unsigned int v7; // eax
  HMENU__ *v8; // eax
  UINT MenuDefaultItem; // eax
  IShellFolder *m_psfCurFolder; // eax
  HWND Parent; // eax
  HWND v12; // eax
  HWND v13; // eax
  CWnd *v14; // eax
  HWND__ *v15; // [esp-14h] [ebp-A0h]
  HWND__ *m_hWnd; // [esp-Ch] [ebp-98h]
  HWND__ *v17; // [esp-4h] [ebp-90h]
  _BYTE lvItem[60]; // [esp+8h] [ebp-84h] OVERLAPPED BYREF
  _AFX_SHELLITEMINFO *pInfo; // [esp+44h] [ebp-48h]
  IContextMenu *pcm; // [esp+48h] [ebp-44h] BYREF
  _AFX_SHELLITEMINFO *pClickedInfo; // [esp+4Ch] [ebp-40h]
  unsigned int nSelItems; // [esp+50h] [ebp-3Ch]
  unsigned int ulAttrs; // [esp+54h] [ebp-38h] BYREF
  _ITEMIDLIST **pPidls; // [esp+58h] [ebp-34h]
  HMENU__ *hPopup; // [esp+5Ch] [ebp-30h]
  unsigned int idCmd; // [esp+60h] [ebp-2Ch]
  _DWORD v27[3]; // [esp+64h] [ebp-28h] BYREF
  tagPOINT Point; // [esp+70h] [ebp-1Ch] BYREF
  CRect rectItem; // [esp+78h] [ebp-14h] BYREF

  if ( afxShellManager->m_pMalloc == nullptr )
LABEL_2:
    AfxThrowInvalidArgException();
  if ( CMFCShellListCtrl::m_pContextMenu2 == nullptr )
  {
    if ( this->m_bContextMenu == 0 )
    {
      CWnd::Default(this);
      return;
    }
    if ( this->m_psfCurFolder != nullptr )
    {
      v5 = (_ITEMIDLIST **)SendMessageA(hWnd: this->m_hWnd, Msg: 0x1032u, wParam: 0, lParam: 0);
      v6 = -1;
      nSelItems = (unsigned int)v5;
      hPopup = (HMENU__ *)-1;
      if ( point.x == -1 && point.y == -1 )
      {
        if ( v5 == nullptr )
          return;
        for ( pPidls = v5; pPidls != nullptr; pPidls = (_ITEMIDLIST **)((char *)pPidls - 1) )
          v6 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x100Cu, wParam: v6, lParam: 2);
        memset(&rectItem, 0, sizeof(rectItem));
        if ( CListCtrl::GetItemRect(this, nItem: v6, lpRect: &rectItem, nCode: 0) != 0 )
        {
          point.x = rectItem.left;
          point.y = rectItem.bottom + 1;
          ClientToScreen(hWnd: this->m_hWnd, lpPoint: &point);
        }
      }
      else
      {
        Point.y = point.y;
        m_hWnd = this->m_hWnd;
        Point.x = point.x;
        ScreenToClient(hWnd: m_hWnd, lpPoint: &Point);
        v15 = this->m_hWnd;
        rectItem.left = 1;
        SendMessageA(hWnd: v15, Msg: 0x1012u, wParam: 0, lParam: (LPARAM)&Point);
        if ( (rectItem.left & 0xE) == 0 )
          return;
        hPopup = (HMENU__ *)rectItem.top;
      }
      pPidls = (_ITEMIDLIST **)((int (__stdcall *)(IMalloc *, unsigned int, int))afxShellManager->m_pMalloc->Alloc)(
                                 a1: afxShellManager->m_pMalloc,
                                 a2: 4 * nSelItems,
                                 a3: a2);
      if ( pPidls == nullptr )
        goto LABEL_2;
      memset(dst: (int)lvItem, value: nullptr, count: sizeof(lvItem));
      pClickedInfo = *(_AFX_SHELLITEMINFO **)&lvItem[32];
      *(_DWORD *)lvItem = 4;
      if ( (int)hPopup >= 0 )
      {
        *(_DWORD *)&lvItem[4] = hPopup;
        if ( SendMessageA(hWnd: this->m_hWnd, Msg: 0x1005u, wParam: 0, lParam: (LPARAM)lvItem) != 0 )
        {
          pClickedInfo = *(_AFX_SHELLITEMINFO **)&lvItem[32];
          *pPidls = *(_ITEMIDLIST **)(*(_DWORD *)&lvItem[32] + 8);
        }
      }
      ulAttrs = -1;
      v7 = (int)hPopup >= 0;
      idCmd = v7;
      while ( v7 < nSelItems )
      {
        v8 = (HMENU__ *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x100Cu, wParam: ulAttrs, lParam: 2);
        ulAttrs = (unsigned int)v8;
        if ( v8 == hPopup )
        {
          --idCmd;
        }
        else
        {
          *(_DWORD *)&lvItem[4] = v8;
          if ( SendMessageA(hWnd: this->m_hWnd, Msg: 0x1005u, wParam: 0, lParam: (LPARAM)lvItem) != 0 )
          {
            pInfo = *(_AFX_SHELLITEMINFO **)&lvItem[32];
            pPidls[idCmd] = *(_ITEMIDLIST **)(*(_DWORD *)&lvItem[32] + 8);
            if ( pClickedInfo == nullptr )
              pClickedInfo = pInfo;
          }
        }
        v7 = ++idCmd;
      }
      if ( *pPidls != nullptr
        && this->m_psfCurFolder->GetUIObjectOf(
             this: this->m_psfCurFolder,
             a2: this->m_hWnd,
             a3: nSelItems,
             a4: (const _ITEMIDLIST **)pPidls,
             a5: &IID_IContextMenu,
             a6: nullptr,
             a7: (void **)&pcm) >= 0 )
      {
        if ( pcm->QueryInterface(this: pcm, a2: &IID_IContextMenu2, a3: (void **)&CMFCShellListCtrl::m_pContextMenu2) >= 0 )
        {
          hPopup = CreatePopupMenu();
          if ( hPopup != nullptr
            && CMFCShellListCtrl::m_pContextMenu2->QueryContextMenu(
                 this: CMFCShellListCtrl::m_pContextMenu2,
                 a2: hPopup,
                 a3: 0,
                 a4: 1u,
                 a5: 0x7FFFu,
                 a6: 4u) >= 0 )
          {
            idCmd = TrackPopupMenu(
                      hMenu: hPopup,
                      uFlags: 0x102u,
                      x: point.x,
                      y: point.y,
                      nReserved: 0,
                      hWnd: this->m_hWnd,
                      prcRect: nullptr);
            if ( idCmd != 0 )
            {
              if ( nSelItems == 1
                && (MenuDefaultItem = GetMenuDefaultItem(hMenu: hPopup, fByPos: 0, gmdiFlags: 0),
                    idCmd == MenuDefaultItem)
                && (m_psfCurFolder = this->m_psfCurFolder,
                    ulAttrs = 0x20000000,
                    m_psfCurFolder->GetAttributesOf(
                      this: m_psfCurFolder,
                      a2: 1u,
                      a3: (const _ITEMIDLIST **)&pClickedInfo->pidlRel,
                      a4: &ulAttrs),
                    (ulAttrs & 0x20000000) != 0) )
              {
                this->DisplayFolder(this, a2: pClickedInfo);
              }
              else
              {
                v17 = this->m_hWnd;
                v27[0] = 36;
                v27[1] = 0;
                Parent = GetParent(hWnd: v17);
                v27[2] = CWnd::FromHandle(hWnd: Parent);
                Point.x = idCmd - 1;
                Point.y = 0;
                rectItem.left = 0;
                rectItem.top = 1;
                rectItem.right = 0;
                rectItem.bottom = 0;
                if ( pcm->InvokeCommand(this: pcm, a2: (_CMINVOKECOMMANDINFO *)v27) >= 0 )
                {
                  v12 = GetParent(hWnd: this->m_hWnd);
                  if ( CWnd::FromHandle(hWnd: v12) != nullptr )
                  {
                    v13 = GetParent(hWnd: this->m_hWnd);
                    v14 = CWnd::FromHandle(hWnd: v13);
                    SendMessageA(hWnd: v14->m_hWnd, Msg: AFX_WM_ON_AFTER_SHELL_COMMAND, wParam: idCmd, lParam: 0);
                  }
                }
              }
            }
          }
          if ( CMFCShellListCtrl::m_pContextMenu2 != nullptr )
          {
            CMFCShellListCtrl::m_pContextMenu2->Release(this: CMFCShellListCtrl::m_pContextMenu2);
            CMFCShellListCtrl::m_pContextMenu2 = nullptr;
          }
        }
        pcm->Release(this: pcm);
      }
      ((void (__stdcall *)(IMalloc *))afxShellManager->m_pMalloc->Free)(a1: afxShellManager->m_pMalloc);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00432640
// Name: protected: void CMFCShellListCtrl::OnDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCShellListCtrl::OnDestroy(CMFCShellListCtrl *this)
{
  CMFCShellTreeCtrl *RelatedTree; // eax

  RelatedTree = CMFCShellListCtrl::GetRelatedTree(this);
  if ( RelatedTree != nullptr )
    RelatedTree->m_hwndRelatedList = nullptr;
  CMFCShellListCtrl::ReleaseCurrFolder(this);
  CWnd::OnDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x004334B6
// Name: protected: virtual void CVSListBoxEditCtrl::OnBrowse(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVSListBoxEditCtrl::OnBrowse(CVSListBoxEditCtrl *this)
{
  CVSListBoxBase *m_pParentList; // ecx
  HWND m_hWnd; // esi

  m_pParentList = this->m_pParentList;
  if ( m_pParentList != nullptr )
  {
    m_hWnd = m_pParentList->m_hWnd;
    m_pParentList->OnBrowse(this: m_pParentList);
    if ( IsWindow(hWnd: m_hWnd) )
      SetFocus(hWnd: m_hWnd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433509
// Name: protected: void CVSListBoxEditCtrl::OnWindowPosChanging(struct tagWINDOWPOS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CVSListBoxEditCtrl::OnWindowPosChanging(CVSListBoxEditCtrl *this, tagWINDOWPOS *lpwndpos)
{
  if ( this->m_bLocked != 0 )
    lpwndpos->flags |= 1u;
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x004766FF
// Name: public: static int CMFCMenuBar::IsShowAllCommands(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall CMFCMenuBar::IsShowAllCommands()
{
  return CMFCMenuBar::m_bShowAllCommands != 0
      || CMFCMenuBar::m_bRecentlyUsedMenus == 0
      || !CMFCCmdUsageCount::HasEnoughInformation(this: &CMFCToolBar::m_UsageCount);
}

//------------------------------------------------------------------------------
// Address: 0x00476726
// Name: public: void CMFCPopupMenuBar::SetOffset(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenuBar::SetOffset(CMFCPopupMenuBar *this, int iOffset)
{
  CMFCPopupMenuBar_vtbl *v2; // eax

  if ( this->m_iOffset != iOffset )
  {
    v2 = this->__vftable;
    this->m_iOffset = iOffset;
    ((void (*)(void))v2->AdjustLocations)();
  }
}

//------------------------------------------------------------------------------
// Address: 0x00476748
// Name: private: CMFCShadowWnd::CMFCShadowWnd(class CMFCPopupMenu __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCShadowWnd *__thiscall CMFCShadowWnd::CMFCShadowWnd(CMFCShadowWnd *this, CMFCPopupMenu *pOwner, int nOffset)
{
  CMiniFrameWnd::CMiniFrameWnd(this);
  this->__vftable = (CMFCShadowWnd_vtbl *)&CMFCShadowWnd::`vftable';
  CMFCShadowRenderer::CMFCShadowRenderer(this: &this->m_Shadow);
  this->m_bIsRTL = 0;
  this->m_pOwner = pOwner;
  this->m_nOffset = nOffset;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00476796
// Name: private: virtual CMFCShadowWnd::~CMFCShadowWnd(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCShadowWnd::~CMFCShadowWnd(CMFCShadowWnd *this)
{
  this->__vftable = (CMFCShadowWnd_vtbl *)&CMFCShadowWnd::`vftable';
  CMFCShadowRenderer::~CMFCShadowRenderer(this: &this->m_Shadow);
  CMiniFrameWnd::~CMiniFrameWnd(this);
}
