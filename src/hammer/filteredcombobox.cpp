// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/filteredcombobox.cpp
// Functions: 93
// ============================================================

#include "hammer\filteredcombobox.h"

//------------------------------------------------------------------------------
// Address: 0x100346B0
// Name: public: void CFilteredComboBox::ForceEditControlText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilteredComboBox::ForceEditControlText(CFilteredComboBox *this, const char *pStr)
{
  CWnd::SetWindowTextA(this, lpszString: pStr);
}

//------------------------------------------------------------------------------
// Address: 0x100346C0
// Name: public: bool CFilteredComboBox::IsWindowEnabled(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CFilteredComboBox::IsWindowEnabled(CFilteredComboBox *this)
{
  return CWnd::IsWindowEnabled(this) == 1;
}

//------------------------------------------------------------------------------
// Address: 0x100346D0
// Name: public: void CFilteredComboBox::EnableWindow(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilteredComboBox::EnableWindow(CFilteredComboBox *this, bool bEnable)
{
  CWnd::EnableWindow(this, bEnable);
}

//------------------------------------------------------------------------------
// Address: 0x100346F0
// Name: public: void CFilteredComboBox::SetOnlyProvideSuggestions(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilteredComboBox::SetOnlyProvideSuggestions(CFilteredComboBox *this, bool bOnlyProvideSuggestions)
{
  this->m_bOnlyProvideSuggestions = bOnlyProvideSuggestions;
}

//------------------------------------------------------------------------------
// Address: 0x10034700
// Name: protected: virtual int CFilteredComboBox::PreCreateWindow(struct tagCREATESTRUCTA __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFilteredComboBox::PreCreateWindow(CFilteredComboBox *this, tagCREATESTRUCTA *cs)
{
  cs->style = cs->style & 0xFFFFFCEF | 0x210;
  return CWnd::PreCreateWindow(this, cs);
}

//------------------------------------------------------------------------------
// Address: 0x10034730
// Name: public: void CFilteredComboBox::SubclassDlgItem(unsigned int,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilteredComboBox::SubclassDlgItem(CFilteredComboBox *this, unsigned int nID, CWnd *pParent)
{
  this->m_bNotifyParent = CObject::IsKindOf(this: pParent, pClass: &CControlBar::classCControlBar) == 0;
  CWnd::SubclassDlgItem(this, nID, pParent);
}

//------------------------------------------------------------------------------
// Address: 0x10034760
// Name: protected: int CFilteredComboBox::OnSelEndOK(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CFilteredComboBox::OnSelEndOK(CFilteredComboBox *this)
{
  return !this->m_bNotifyParent;
}

//------------------------------------------------------------------------------
// Address: 0x10034770
// Name: public: bool CFilteredComboBox::MatchString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFilteredComboBox::MatchString(
        CFilteredComboBox *this,
        const char *pStringToMatchStart,
        const char *pTestStringStart)
{
  const char *v3; // esi
  const char *v4; // edi
  unsigned int v6; // ebx

  v3 = pStringToMatchStart;
  if ( pStringToMatchStart == nullptr || *pStringToMatchStart == 0 )
    return 1;
  v4 = pTestStringStart;
  if ( *pTestStringStart == 0 )
    return 0;
  while ( 1 )
  {
    for ( ; *v3 == 95; ++v3 )
      ;
    for ( ; *v4 == 95; ++v4 )
      ;
    if ( *v3 == 0 )
      break;
    if ( *v4 != 0 && (v6 = toupper(c: *v4), toupper(c: *v3) == v6) )
    {
      ++v3;
      ++v4;
    }
    else
    {
      v4 = pTestStringStart + 1;
      if ( *++pTestStringStart == 0 )
        return 0;
      v3 = pStringToMatchStart;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10034810
// Name: protected: struct HBRUSH__ __near * CFilteredComboBox::OnCtlColor(class CDC __near *,class CWnd __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
HBRUSH__ *__thiscall CFilteredComboBox::OnCtlColor(CFilteredComboBox *this, CDC *pDC, CWnd *pWnd, HBRUSH__ *nCtlColor)
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
// Address: 0x10034860
// Name: public: virtual int CDC::DrawTextA(char const __near *,int,struct tagRECT __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDC::DrawTextA(CDC *this, const char *lpszString, int nCount, tagRECT *lpRect, UINT nFormat)
{
  return DrawTextA(hdc: this->m_hDC, lpchText: lpszString, cchText: nCount, lprc: lpRect, format: nFormat);
}

//------------------------------------------------------------------------------
// Address: 0x10034890
// Name: public: class CFont __near * CWnd::GetFont(void)const
// Source: json
//------------------------------------------------------------------------------
CFont *__thiscall CWnd::GetFont(CWnd *this)
{
  void *v1; // eax

  v1 = (void *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x31u, wParam: 0, lParam: 0);
  return (CFont *)CGdiObject::FromHandle(h: v1);
}

//------------------------------------------------------------------------------
// Address: 0x100348B0
// Name: public: void CWnd::MoveWindow(struct tagRECT const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::MoveWindow(CWnd *this, const tagRECT *lpRect, int bRepaint)
{
  CWnd::MoveWindow(
    this,
    x: lpRect->left,
    y: lpRect->top,
    nWidth: lpRect->right - lpRect->left,
    nHeight: lpRect->bottom - lpRect->top,
    bRepaint);
}

//------------------------------------------------------------------------------
// Address: 0x10034910
// Name: public: int CComboBox::SetEditSel(int,int)
// Source: json
//------------------------------------------------------------------------------
LRESULT __thiscall CComboBox::SetEditSel(CComboBox *this, unsigned __int16 nStartChar, unsigned __int16 nEndChar)
{
  return SendMessageA(hWnd: this->m_hWnd, Msg: 0x142u, wParam: 0, lParam: nStartChar | (nEndChar << 16));
}

//------------------------------------------------------------------------------
// Address: 0x10034940
// Name: private: void CFilteredComboBox::InternalSetEditControlFont(struct HFONT__ __near *,char const __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilteredComboBox::InternalSetEditControlFont(
        CFilteredComboBox *this,
        HFONT__ *hFont,
        const char *pEditText,
        LPARAM sel)
{
  HWND Parent; // eax
  CWnd *v6; // eax
  CWnd *v7; // ebx
  CGdiObject *v8; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-28h]
  CRect rcMyRect; // [esp+4h] [ebp-14h] BYREF
  int bWasDropped; // [esp+14h] [ebp-4h]

  if ( hFont != this->m_hEditControlFont )
  {
    SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
    m_hWnd = this->m_hWnd;
    memset(&rcMyRect, 0, sizeof(rcMyRect));
    GetWindowRect(hWnd: m_hWnd, lpRect: &rcMyRect);
    Parent = GetParent(hWnd: this->m_hWnd);
    v6 = CWnd::FromHandle(hWnd: Parent);
    v7 = v6;
    if ( v6 != nullptr )
      CWnd::ScreenToClient(this: v6, lpRect: &rcMyRect);
    bWasDropped = SendMessageA(hWnd: this->m_hWnd, Msg: 0x157u, wParam: 0, lParam: 0);
    this->m_hEditControlFont = hFont;
    v8 = CGdiObject::FromHandle(h: hFont);
    if ( v8 != nullptr )
      v8 = (CGdiObject *)v8->m_hObject;
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x30u, wParam: (WPARAM)v8, lParam: 0);
    CWnd::SetWindowTextA(this, lpszString: pEditText);
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x142u, wParam: 0, lParam: sel);
    if ( v7 != nullptr )
      CWnd::MoveWindow(
        this,
        x: rcMyRect.left,
        y: rcMyRect.top,
        nWidth: rcMyRect.right - rcMyRect.left,
        nHeight: rcMyRect.bottom - rcMyRect.top,
        bRepaint: 1);
    if ( bWasDropped != 0 )
      SendMessageA(hWnd: this->m_hWnd, Msg: 0x14Fu, wParam: 1u, lParam: 0);
    SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
    InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034A60
// Name: protected: int CFilteredComboBox::OnDropDown(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CFilteredComboBox::OnDropDown(CFilteredComboBox *this)
{
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x20u, wParam: 0, lParam: 0);
  return !this->m_bNotifyParent;
}

//------------------------------------------------------------------------------
// Address: 0x10034A80
// Name: protected: static int CFilteredComboBox::SortFn(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near *,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CFilteredComboBox::SortFn(
        const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *pItem1,
        const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *pItem2)
{
  bool v2; // bl

  if ( s_pStringToMatch != nullptr
    && (v2 = V_strnistr(pStr: pItem1->m_pszData, pSearch: s_pStringToMatch, n: s_iStringToMatchLen) != nullptr) != (V_strnistr(pStr: pItem2->m_pszData, pSearch: s_pStringToMatch, n: s_iStringToMatchLen) != nullptr) )
  {
    return 2 * !v2 - 1;
  }
  else
  {
    return _V_stricmp(s1: pItem1->m_pszData, s2: pItem2->m_pszData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034AF0
// Name: protected: virtual void CFilteredComboBox::MeasureItem(struct tagMEASUREITEMSTRUCT __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilteredComboBox::MeasureItem(CFilteredComboBox *this, tagMEASUREITEMSTRUCT *pStruct)
{
  void *v2; // eax
  CGdiObject *v3; // eax
  HGDIOBJ m_hObject; // eax
  CGdiObject *v5; // eax
  tagLOGFONTA logFont; // [esp+0h] [ebp-3Ch] BYREF

  v2 = (void *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x31u, wParam: 0, lParam: 0);
  v3 = CGdiObject::FromHandle(h: v2);
  if ( v3 != nullptr )
    m_hObject = v3->m_hObject;
  else
    m_hObject = GetStockObject(i: 17);
  v5 = CGdiObject::FromHandle(h: m_hObject);
  if ( v5 != nullptr )
  {
    GetObjectA(h: v5->m_hObject, c: 60, pv: &logFont);
    pStruct->itemHeight = abs32(logFont.lfHeight) + 5;
  }
  else
  {
    pStruct->itemHeight = 16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034B60
// Name: public: int CFilteredComboBox::FindSuggestion(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFilteredComboBox::FindSuggestion(CFilteredComboBox *this, const char *pTest)
{
  int v3; // esi

  v3 = 0;
  if ( this->m_Suggestions.m_Size <= 0 )
    return -1;
  while ( _V_stricmp(s1: this->m_Suggestions.m_Memory.m_pMemory[v3].m_pszData, s2: pTest) != 0 )
  {
    if ( ++v3 >= this->m_Suggestions.m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10034BB0
// Name: protected: class CFont __near & CFilteredComboBox::GetNormalFont(void)
// Source: json
//------------------------------------------------------------------------------
CFont *__thiscall CFilteredComboBox::GetNormalFont(CFilteredComboBox *this)
{
  void *v2; // eax
  CGdiObject *v3; // eax
  HFONT v4; // eax
  LOGFONTA pv; // [esp+4h] [ebp-3Ch] BYREF

  if ( this->m_NormalFont.m_hObject == nullptr )
  {
    v2 = (void *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x31u, wParam: 0, lParam: 0);
    v3 = CGdiObject::FromHandle(h: v2);
    if ( v3 != nullptr )
    {
      GetObjectA(h: v3->m_hObject, c: 60, &pv);
      v4 = CreateFontIndirectA(lplf: &pv);
      CGdiObject::Attach(this: &this->m_NormalFont, hObject: v4);
    }
  }
  return &this->m_NormalFont;
}

//------------------------------------------------------------------------------
// Address: 0x10034C70
// Name: public: void CFilteredComboBox::SetEditControlFont(struct HFONT__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilteredComboBox::SetEditControlFont(CFilteredComboBox *this, HFONT__ *hFont)
{
  HFONT__ *v2; // edi
  ATL::IAtlStringMgr *StringManager; // eax
  LPARAM v5; // eax
  HFONT__ *v6; // eax

  v2 = hFont;
  if ( hFont != nullptr )
  {
    if ( this->m_bInSelChange )
    {
      this->m_hQueuedFont = hFont;
    }
    else
    {
      StringManager = AfxGetStringManager();
      if ( StringManager == nullptr )
        ATL::AtlThrowImpl(hr: -2147467259);
      hFont = (HFONT__ *)&StringManager->GetNilString(this: StringManager)[1];
      CWnd::GetWindowTextA(this, rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&hFont);
      v5 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x140u, wParam: 0, lParam: 0);
      CFilteredComboBox::InternalSetEditControlFont(this, hFont: v2, pEditText: (const char *)hFont, sel: v5);
      v6 = hFont - 4;
      if ( _InterlockedDecrement((volatile signed __int32 *)hFont - 1) <= 0 )
        (*(void (__stdcall **)(HFONT__ *))(**(_DWORD **)v6 + 4))(a1: v6);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034DD0
// Name: protected: virtual void CFilteredComboBox::DrawItem(struct tagDRAWITEMSTRUCT __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilteredComboBox::DrawItem(CFilteredComboBox *this, tagDRAWITEMSTRUCT *lpDrawItemStruct)
{
  ATL::IAtlStringMgr *StringManager; // eax
  COLORREF BkColor; // ebx
  COLORREF SysColor; // eax
  COLORREF v7; // eax
  tagRECT *p_rcItem; // esi
  CFont *v9; // edi
  __int64 v10; // xmm0_8
  char *v11; // eax
  COLORREF v12; // [esp-Ch] [ebp-40h]
  tagRECT rcDraw; // [esp+4h] [ebp-30h] BYREF
  CDC dc; // [esp+14h] [ebp-20h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+24h] [ebp-10h] BYREF
  int v16; // [esp+30h] [ebp-4h]
  unsigned int crOldTextColor; // [esp+3Ch] [ebp+8h]

  if ( SendMessageA(hWnd: this->m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0) != 0 )
  {
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    str.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
    v16 = 1;
    CComboBox::GetLBText(this, nIndex: lpDrawItemStruct->itemID, rString: &str);
    CDC::CDC(this: &dc);
    LOBYTE(v16) = 2;
    CDC::Attach(this: &dc, hDC: lpDrawItemStruct->hDC);
    crOldTextColor = GetTextColor(hdc: dc.m_hAttribDC);
    BkColor = GetBkColor(hdc: dc.m_hAttribDC);
    if ( (lpDrawItemStruct->itemState & 1) != 0 )
    {
      SysColor = GetSysColor(nIndex: 14);
      CDC::SetTextColor(this: &dc, crColor: SysColor);
      v7 = GetSysColor(nIndex: 13);
      CDC::SetBkColor(this: &dc, crColor: v7);
      p_rcItem = &lpDrawItemStruct->rcItem;
      v12 = GetSysColor(nIndex: 13);
      CDC::FillSolidRect(this: &dc, lpRect: p_rcItem, clr: v12);
    }
    else
    {
      p_rcItem = &lpDrawItemStruct->rcItem;
      CDC::FillSolidRect(this: &dc, lpRect: p_rcItem, clr: BkColor);
    }
    v9 = CDC::SelectObject(this: &dc, pFont: &this->m_NormalFont);
    *(_QWORD *)&rcDraw.left = *(_QWORD *)&p_rcItem->left;
    v10 = *(_QWORD *)&p_rcItem->right;
    ++rcDraw.left;
    *(_QWORD *)&rcDraw.right = v10;
    DrawTextA(hdc: dc.m_hDC, lpchText: str.m_pszData, cchText: -1, lprc: &rcDraw, format: 0x24u);
    CDC::SelectObject(this: &dc, pFont: v9);
    CDC::SetTextColor(this: &dc, crColor: crOldTextColor);
    CDC::SetBkColor(this: &dc, crColor: BkColor);
    CDC::Detach(this: &dc);
    LOBYTE(v16) = 1;
    CDC::~CDC(this: &dc);
    v16 = -1;
    v11 = str.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v11 + 4))(a1: v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10034F80
// Name: private: bool CFilteredComboBox::InternalSelectItemByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CFilteredComboBox::InternalSelectItemByName(CFilteredComboBox *this, const char *pName)
{
  const char *v2; // ebx
  WPARAM v4; // eax
  ATL::IAtlStringMgr *StringManager; // eax
  const char *v7; // eax

  v2 = pName;
  v4 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x158u, wParam: 0xFFFFFFFF, lParam: (LPARAM)pName);
  if ( v4 == -1 )
    return 0;
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x14Eu, wParam: v4, lParam: 0);
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  pName = (const char *)&StringManager->GetNilString(this: StringManager)[1];
  CWnd::GetWindowTextA(this, rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pName);
  if ( _V_stricmp(s1: pName, s2: v2) != 0 )
    CWnd::SetWindowTextA(this, lpszString: v2);
  v7 = pName - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)pName - 1) <= 0 )
    (*(void (__stdcall **)(const char *))(**(_DWORD **)v7 + 4))(a1: v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100352A0
// Name: public: virtual CGdiObject::~CGdiObject(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CGdiObject::~CGdiObject(CGdiObject *this)
{
  int v1; // [esp+0h] [ebp-224h] BYREF
  int *v2; // [esp+214h] [ebp-10h]
  int v3; // [esp+220h] [ebp-4h]

  v2 = &v1;
  this->__vftable = (CGdiObject_vtbl *)&CGdiObject::`vftable';
  v3 = 0;
  CGdiObject::DeleteObject(this);
}

//------------------------------------------------------------------------------
// Address: 0x10035390
// Name: public: virtual CFont::~CFont(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFont::~CFont(CFont *this)
{
  this->__vftable = (CFont_vtbl *)&CFont::`vftable';
  CGdiObject::~CGdiObject(this);
}

//------------------------------------------------------------------------------
// Address: 0x100353D0
// Name: public: void CFilteredComboBox::AddSuggestion(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilteredComboBox::AddSuggestion(
        CFilteredComboBox *this,
        const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *suggestion)
{
  if ( CFilteredComboBox::FindSuggestion(this, pTest: suggestion->m_pszData) == -1 )
    CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>::InsertBefore(
      this: &this->m_Suggestions,
      elem: this->m_Suggestions.m_Size,
      src: suggestion);
}

//------------------------------------------------------------------------------
// Address: 0x10035490
// Name: public: void CFilteredComboBox::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilteredComboBox::Clear(CFilteredComboBox *this)
{
  CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>::RemoveAll(this: &this->m_Suggestions);
  if ( this->m_Suggestions.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Suggestions.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: this->m_Suggestions.m_Memory.m_pMemory);
      this->m_Suggestions.m_Memory.m_pMemory = nullptr;
    }
    this->m_Suggestions.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Suggestions.m_pElements = this->m_Suggestions.m_Memory.m_pMemory;
  CWnd::SetWindowTextA(this, lpszString: &var);
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_LastTextChangedValue, pszSrc: &var, nLength: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100354F0
// Name: protected: void CFilteredComboBox::DoTextChangedCallback(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilteredComboBox::DoTextChangedCallback(CFilteredComboBox *this, const char *pText)
{
  int v3; // eax

  if ( _V_stricmp(s1: pText, s2: this->m_LastTextChangedValue.m_pszData) != 0 )
  {
    if ( pText != nullptr )
      v3 = strlen(pText);
    else
      v3 = 0;
    ATL::CSimpleStringT<char,0>::SetString(this: &this->m_LastTextChangedValue, pszSrc: pText, nLength: v3);
    this->m_pCallbacks->OnTextChanged(this: this->m_pCallbacks, a2: pText);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100357E0
// Name: public: CFilteredComboBox::CFilteredComboBox(class CFilteredComboBox::ICallbacks __near *)
// Source: json
//------------------------------------------------------------------------------
CFilteredComboBox *__thiscall CFilteredComboBox::CFilteredComboBox(
        CFilteredComboBox *this,
        CFilteredComboBox::ICallbacks *pCallbacks)
{
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *m_pMemory; // ecx
  ATL::IAtlStringMgr *StringManager; // eax

  CWnd::CWnd(this);
  this->__vftable = (CFilteredComboBox_vtbl *)&CComboBox::`vftable';
  this->__vftable = (CFilteredComboBox_vtbl *)&CFilteredComboBox::`vftable';
  this->m_Suggestions.m_Memory.m_pMemory = nullptr;
  this->m_Suggestions.m_Memory.m_nAllocationCount = 0;
  this->m_Suggestions.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_Suggestions.m_Memory.m_pMemory;
  this->m_Suggestions.m_Size = 0;
  this->m_Suggestions.m_pElements = m_pMemory;
  this->m_NormalFont.__vftable = (CFont_vtbl *)&CGdiObject::`vftable';
  this->m_NormalFont.m_hObject = nullptr;
  this->m_NormalFont.__vftable = (CFont_vtbl *)&CFont::`vftable';
  this->m_pCallbacks = pCallbacks;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_LastTextChangedValue.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  this->m_hQueuedFont = nullptr;
  this->m_bInSelChange = false;
  this->m_bNotifyParent = true;
  this->m_dwTextColor = 0;
  this->m_hEditControlFont = nullptr;
  *(_WORD *)&this->m_bOnlyProvideSuggestions = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100358E0
// Name: public: virtual CFilteredComboBox::~CFilteredComboBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilteredComboBox::~CFilteredComboBox(CFilteredComboBox *this)
{
  volatile signed __int32 *v2; // eax

  v2 = (volatile signed __int32 *)(this->m_LastTextChangedValue.m_pszData - 16);
  if ( _InterlockedDecrement(v2 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v2 + 4))(a1: v2);
  this->m_NormalFont.__vftable = (CFont_vtbl *)&CFont::`vftable';
  CGdiObject::~CGdiObject(this: &this->m_NormalFont);
  CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>::~CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>(this: &this->m_Suggestions);
  CComboBox::~CComboBox(this);
}

//------------------------------------------------------------------------------
// Address: 0x10035980
// Name: protected: int CFilteredComboBox::OnSelChange(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CFilteredComboBox::OnSelChange(CFilteredComboBox *this)
{
  ATL::IAtlStringMgr *StringManager; // eax
  LRESULT v3; // edi
  ATL::IAtlStringMgr *v4; // eax
  char *v5; // eax
  HFONT__ *m_hQueuedFont; // eax
  char *v7; // eax
  HWND__ *m_hWnd; // [esp-14h] [ebp-30h]
  char *m_pszData; // [esp-8h] [ebp-24h]
  LPARAM dwOriginalEditSel; // [esp+4h] [ebp-18h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strOriginalText; // [esp+8h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+Ch] [ebp-10h] BYREF
  int v14; // [esp+18h] [ebp-4h]

  if ( !this->m_bInSelChange )
  {
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    strOriginalText.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
    v14 = 1;
    CWnd::GetWindowTextA(this, rString: &strOriginalText);
    dwOriginalEditSel = SendMessageA(hWnd: this->m_hWnd, Msg: 0x140u, wParam: 0, lParam: 0);
    m_hWnd = this->m_hWnd;
    this->m_bInSelChange = true;
    v3 = SendMessageA(hWnd: m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
    if ( v3 != -1 )
    {
      v4 = AfxGetStringManager();
      if ( v4 == nullptr )
        ATL::AtlThrowImpl(hr: -2147467259);
      str.m_pszData = (char *)&v4->GetNilString(this: v4)[1];
      LOBYTE(v14) = 3;
      CComboBox::GetLBText(this, nIndex: v3, rString: &str);
      ATL::CSimpleStringT<char,0>::operator=(this: &strOriginalText, strSrc: (ATL::CStringData *)&str);
      CFilteredComboBox::DoTextChangedCallback(this, pText: str.m_pszData);
      LOBYTE(v14) = 1;
      v5 = str.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v5 + 4))(a1: v5);
    }
    m_hQueuedFont = this->m_hQueuedFont;
    this->m_bInSelChange = false;
    if ( m_hQueuedFont != nullptr )
    {
      m_pszData = strOriginalText.m_pszData;
      this->m_hQueuedFont = nullptr;
      this->m_bInSelChange = false;
      CFilteredComboBox::InternalSetEditControlFont(
        this,
        hFont: m_hQueuedFont,
        pEditText: m_pszData,
        sel: dwOriginalEditSel);
    }
    v14 = -1;
    v7 = strOriginalText.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)strOriginalText.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v7 + 4))(a1: v7);
  }
  return !this->m_bNotifyParent;
}

//------------------------------------------------------------------------------
// Address: 0x10035B00
// Name: protected: virtual int CFilteredComboBox::OnEditChange(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CFilteredComboBox::OnEditChange(CFilteredComboBox *this)
{
  ATL::IAtlStringMgr *StringManager; // eax
  int v3; // edi
  void (__stdcall *v4)(HWND, UINT, WPARAM, LPARAM); // ebx
  int v5; // edi
  char *m_pszData; // ebx
  int v7; // edi
  int i; // esi
  volatile signed __int32 *v9; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *m_pMemory; // eax
  char *v11; // eax
  char *v13; // edi
  int v14; // eax
  char *v15; // edi
  int v16; // eax
  CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int> > items; // [esp+Ch] [ebp-2Ch] BYREF
  unsigned int dwEditSel; // [esp+20h] [ebp-18h]
  char *s2; // [esp+24h] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > szTypedText; // [esp+28h] [ebp-10h] BYREF
  int v21; // [esp+34h] [ebp-4h]

  StringManager = AfxGetStringManager();
  v3 = 0;
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  szTypedText.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v21 = 1;
  CWnd::GetWindowTextA(this, rString: &szTypedText);
  v4 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageA;
  dwEditSel = SendMessageA(hWnd: this->m_hWnd, Msg: 0x140u, wParam: 0, lParam: 0);
  memset(&items, 0, sizeof(items));
  LOBYTE(v21) = 3;
  this->GetItemsMatchingString(this, a2: szTypedText.m_pszData, a3: &items);
  SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x14Bu, wParam: 0, lParam: 0);
  if ( items.m_Size > 0 )
  {
    do
      SendMessageA(hWnd: this->m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)items.m_Memory.m_pMemory[v3++].m_pszData);
    while ( v3 < items.m_Size );
  }
  if ( !this->m_bOnlyProvideSuggestions )
  {
    v5 = 0;
    s2 = szTypedText.m_pszData;
    if ( this->m_Suggestions.m_Size <= 0 )
      goto LABEL_11;
    while ( _V_stricmp(s1: this->m_Suggestions.m_Memory.m_pMemory[v5].m_pszData, s2) != 0 )
    {
      if ( ++v5 >= this->m_Suggestions.m_Size )
        goto LABEL_11;
    }
    if ( v5 == -1 )
LABEL_11:
      SendMessageA(hWnd: this->m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)szTypedText.m_pszData);
  }
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x14Fu, wParam: 1u, lParam: 0);
  SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
  InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
  if ( this->m_bOnlyProvideSuggestions )
  {
    m_pszData = szTypedText.m_pszData;
    v7 = 0;
    if ( this->m_Suggestions.m_Size > 0 )
    {
      while ( _V_stricmp(s1: this->m_Suggestions.m_Memory.m_pMemory[v7].m_pszData, s2: m_pszData) != 0 )
      {
        if ( ++v7 >= this->m_Suggestions.m_Size )
          goto LABEL_16;
      }
      if ( v7 != -1 )
      {
        v13 = szTypedText.m_pszData;
        if ( _V_stricmp(s1: szTypedText.m_pszData, s2: this->m_LastTextChangedValue.m_pszData) != 0 )
        {
          if ( v13 != nullptr )
            v14 = strlen(v13);
          else
            v14 = 0;
          ATL::CSimpleStringT<char,0>::SetString(this: &this->m_LastTextChangedValue, pszSrc: v13, nLength: v14);
          this->m_pCallbacks->OnTextChanged(this: this->m_pCallbacks, a2: v13);
        }
      }
    }
LABEL_16:
    v4 = (void (__stdcall *)(HWND, UINT, WPARAM, LPARAM))SendMessageA;
  }
  else
  {
    v15 = szTypedText.m_pszData;
    if ( _V_stricmp(s1: szTypedText.m_pszData, s2: this->m_LastTextChangedValue.m_pszData) != 0 )
    {
      if ( v15 != nullptr )
        v16 = strlen(v15);
      else
        v16 = 0;
      ATL::CSimpleStringT<char,0>::SetString(this: &this->m_LastTextChangedValue, pszSrc: v15, nLength: v16);
      this->m_pCallbacks->OnTextChanged(this: this->m_pCallbacks, a2: v15);
    }
  }
  CWnd::SetWindowTextA(this, lpszString: szTypedText.m_pszData);
  v4(hWnd: this->m_hWnd, Msg: 0x142u, wParam: 0, lParam: dwEditSel);
  dwEditSel = !this->m_bNotifyParent;
  LOBYTE(v21) = 4;
  for ( i = items.m_Size - 1; i >= 0; --i )
  {
    s2 = (char *)&items.m_Memory.m_pMemory[i];
    LOBYTE(v21) = 4;
    v9 = (volatile signed __int32 *)(*(_DWORD *)s2 - 16);
    if ( _InterlockedDecrement(v9 + 3) <= 0 )
      (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v9 + 4))(a1: v9);
  }
  m_pMemory = items.m_Memory.m_pMemory;
  items.m_Size = 0;
  if ( items.m_Memory.m_nGrowSize >= 0 )
  {
    if ( items.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: items.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      items.m_Memory.m_pMemory = nullptr;
    }
    items.m_Memory.m_nAllocationCount = 0;
  }
  items.m_pElements = m_pMemory;
  LOBYTE(v21) = 1;
  if ( items.m_Memory.m_nGrowSize >= 0 )
  {
    if ( items.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: items.m_Memory.m_pMemory);
      items.m_Memory.m_pMemory = nullptr;
    }
    items.m_Memory.m_nAllocationCount = 0;
  }
  v21 = -1;
  v11 = szTypedText.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)szTypedText.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v11 + 4))(a1: v11);
  return dwEditSel;
}

//------------------------------------------------------------------------------
// Address: 0x10035F30
// Name: protected: virtual void CFilteredComboBox::GetItemsMatchingString(char const __near *,class CUtlVector<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class CUtlMemory<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilteredComboBox::GetItemsMatchingString(
        CFilteredComboBox *this,
        const char *pStringToMatch,
        CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int> > *matchingItems)
{
  int i; // ebx

  for ( i = 0; i < this->m_Suggestions.m_Size; ++i )
  {
    if ( CFilteredComboBox::MatchString(
           this,
           pStringToMatchStart: pStringToMatch,
           pTestStringStart: this->m_Suggestions.m_Memory.m_pMemory[i].m_pszData) != 0 )
      CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>::InsertBefore(
        this: matchingItems,
        elem: matchingItems->m_Size,
        src: &this->m_Suggestions.m_Memory.m_pMemory[i]);
  }
  s_pStringToMatch = pStringToMatch;
  s_iStringToMatchLen = std::char_traits<char>::length(str: pStringToMatch);
  CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>::Sort(
    this: matchingItems,
    pfnCompare: CFilteredComboBox::SortFn);
  s_pStringToMatch = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10036090
// Name: protected: void CFilteredComboBox::FillDropdownList(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilteredComboBox::FillDropdownList(
        CFilteredComboBox *this,
        const char *pInitialSel,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *bEnableRedraw)
{
  int v3; // edi
  const char *v5; // edi
  ATL::CStringData *BestSuggestion; // eax
  char *v7; // eax
  const char *v8; // edi
  int v9; // eax
  const char *v10; // eax
  int i; // esi
  volatile signed __int32 *v12; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *m_pMemory; // eax
  CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int> > items; // [esp+Ch] [ebp-24h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+20h] [ebp-10h] BYREF
  int v16; // [esp+2Ch] [ebp-4h]

  v3 = 0;
  SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x14Bu, wParam: 0, lParam: 0);
  memset(&items, 0, sizeof(items));
  v16 = 1;
  this->GetItemsMatchingString(this, a2: &var, a3: &items);
  if ( items.m_Size > 0 )
  {
    do
      SendMessageA(hWnd: this->m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)items.m_Memory.m_pMemory[v3++].m_pszData);
    while ( v3 < items.m_Size );
  }
  v5 = pInitialSel;
  if ( pInitialSel != nullptr )
  {
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
      this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pInitialSel,
      pszSrc: pInitialSel);
    LOBYTE(v16) = 2;
    if ( this->m_bOnlyProvideSuggestions )
    {
      BestSuggestion = (ATL::CStringData *)CFilteredComboBox::GetBestSuggestion(this, &result, pTest: v5);
      LOBYTE(v16) = 3;
      ATL::CSimpleStringT<char,0>::operator=(this: (ATL::CSimpleStringT<char,0> *)&pInitialSel, strSrc: BestSuggestion);
      LOBYTE(v16) = 2;
      v7 = result.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)result.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v7 + 4))(a1: v7);
      CFilteredComboBox::InternalSelectItemByName(this, pName: v5);
    }
    else if ( CFilteredComboBox::InternalSelectItemByName(this, pName: pInitialSel) == 0 )
    {
      SendMessageA(hWnd: this->m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)pInitialSel);
      CFilteredComboBox::InternalSelectItemByName(this, pName: pInitialSel);
    }
    v8 = pInitialSel;
    if ( _V_stricmp(s1: pInitialSel, s2: this->m_LastTextChangedValue.m_pszData) != 0 )
    {
      if ( v8 != nullptr )
        v9 = strlen(v8);
      else
        v9 = 0;
      ATL::CSimpleStringT<char,0>::SetString(this: &this->m_LastTextChangedValue, pszSrc: v8, nLength: v9);
      this->m_pCallbacks->OnTextChanged(this: this->m_pCallbacks, a2: v8);
    }
    LOBYTE(v16) = 1;
    v10 = pInitialSel - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)pInitialSel - 1) <= 0 )
      (*(void (__stdcall **)(const char *))(**(_DWORD **)v10 + 4))(a1: v10);
  }
  if ( (_BYTE)bEnableRedraw != 0 )
  {
    SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
    InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
  }
  v16 = 6;
  for ( i = items.m_Size - 1; i >= 0; --i )
  {
    bEnableRedraw = &items.m_Memory.m_pMemory[i];
    LOBYTE(v16) = 6;
    v12 = (volatile signed __int32 *)(bEnableRedraw->m_pszData - 16);
    if ( _InterlockedDecrement(v12 + 3) <= 0 )
      (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v12 + 4))(a1: v12);
  }
  m_pMemory = items.m_Memory.m_pMemory;
  items.m_Size = 0;
  if ( items.m_Memory.m_nGrowSize >= 0 )
  {
    if ( items.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: items.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      items.m_Memory.m_pMemory = nullptr;
    }
    items.m_Memory.m_nAllocationCount = 0;
  }
  items.m_pElements = m_pMemory;
  v16 = -1;
  if ( items.m_Memory.m_nGrowSize >= 0 && items.m_Memory.m_pMemory != nullptr )
    free(pMem: items.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100362E0
// Name: protected: void CFilteredComboBox::OnEnterKeyPressed(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilteredComboBox::OnEnterKeyPressed(CFilteredComboBox *this, const char *pForceText)
{
  ATL::IAtlStringMgr *StringManager; // eax
  LPARAM v4; // edi
  HWND__ *m_hWnd; // ecx
  HWND Parent; // eax
  CWnd *v7; // eax
  ATL::IAtlStringMgr *v8; // eax
  ATL::CStringData *BestSuggestion; // eax
  char *v10; // eax
  const char *v11; // edi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *EditControlText; // eax
  const char *v13; // eax
  char *v14; // eax
  CRect rcMyRect; // [esp+4h] [ebp-28h] BYREF
  CWnd *pParent; // [esp+14h] [ebp-18h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+18h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > szTypedText; // [esp+1Ch] [ebp-10h] BYREF
  int v19; // [esp+28h] [ebp-4h]

  if ( !this->m_bInEnterKeyPressedHandler )
  {
    this->m_bInEnterKeyPressedHandler = true;
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    szTypedText.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
    v19 = 1;
    if ( pForceText != nullptr )
    {
      ATL::CSimpleStringT<char,0>::SetString(this: &szTypedText, pszSrc: pForceText, nLength: strlen(pForceText));
      v4 = 0;
    }
    else
    {
      CWnd::GetWindowTextA(this, rString: &szTypedText);
      v4 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x140u, wParam: 0, lParam: 0);
    }
    m_hWnd = this->m_hWnd;
    memset(&rcMyRect, 0, sizeof(rcMyRect));
    GetWindowRect(hWnd: m_hWnd, lpRect: &rcMyRect);
    Parent = GetParent(hWnd: this->m_hWnd);
    v7 = CWnd::FromHandle(hWnd: Parent);
    pParent = v7;
    if ( v7 != nullptr )
      CWnd::ScreenToClient(this: v7, lpRect: &rcMyRect);
    SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x14Fu, wParam: 0, lParam: 0);
    if ( this->m_bOnlyProvideSuggestions )
    {
      v8 = AfxGetStringManager();
      if ( v8 == nullptr )
        ATL::AtlThrowImpl(hr: -2147467259);
      pForceText = (const char *)&v8->GetNilString(this: v8)[1];
      LOBYTE(v19) = 3;
      if ( CFilteredComboBox::FindSuggestion(this, pTest: szTypedText.m_pszData) == -1
        && this->m_pCallbacks->OnUnknownEntry(this: this->m_pCallbacks, a2: szTypedText.m_pszData) )
      {
        CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>::InsertBefore(
          this: &this->m_Suggestions,
          elem: this->m_Suggestions.m_Size,
          src: &szTypedText);
        ATL::CSimpleStringT<char,0>::operator=(
          this: (ATL::CSimpleStringT<char,0> *)&pForceText,
          strSrc: (ATL::CStringData *)&szTypedText);
      }
      else
      {
        BestSuggestion = (ATL::CStringData *)CFilteredComboBox::GetBestSuggestion(
                                               this,
                                               &result,
                                               pTest: szTypedText.m_pszData);
        LOBYTE(v19) = 4;
        ATL::CSimpleStringT<char,0>::operator=(this: (ATL::CSimpleStringT<char,0> *)&pForceText, strSrc: BestSuggestion);
        LOBYTE(v19) = 3;
        v10 = result.m_pszData - 16;
        if ( _InterlockedDecrement((volatile signed __int32 *)result.m_pszData - 1) <= 0 )
          (*(void (__stdcall **)(char *))(**(_DWORD **)v10 + 4))(a1: v10);
      }
      v11 = pForceText;
      CFilteredComboBox::DoTextChangedCallback(this, pText: pForceText);
      CFilteredComboBox::FillDropdownList(this, pInitialSel: v11, bEnableRedraw: nullptr);
      if ( SendMessageA(hWnd: this->m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0) == -1 )
        SendMessageA(hWnd: this->m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
      LOBYTE(v19) = 1;
      if ( _InterlockedDecrement((volatile signed __int32 *)v11 - 1) <= 0 )
        (*(void (__thiscall **)(_DWORD, const char *))(**((_DWORD **)v11 - 4) + 4))(
          a1: *((_DWORD *)v11 - 4),
          a2: v11 - 16);
    }
    else
    {
      CFilteredComboBox::FillDropdownList(this, pInitialSel: szTypedText.m_pszData, bEnableRedraw: nullptr);
      CWnd::SetWindowTextA(this, lpszString: szTypedText.m_pszData);
      SendMessageA(hWnd: this->m_hWnd, Msg: 0x142u, wParam: 0, lParam: v4);
    }
    if ( pParent != nullptr )
      CWnd::MoveWindow(
        this,
        x: rcMyRect.left,
        y: rcMyRect.top,
        nWidth: rcMyRect.right - rcMyRect.left,
        nHeight: rcMyRect.bottom - rcMyRect.top,
        bRepaint: 1);
    SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
    InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
    EditControlText = CFilteredComboBox::GetEditControlText(
                        this,
                        result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pForceText);
    LOBYTE(v19) = 7;
    CFilteredComboBox::DoTextChangedCallback(this, pText: EditControlText->m_pszData);
    LOBYTE(v19) = 1;
    v13 = pForceText - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)pForceText - 1) <= 0 )
      (*(void (__stdcall **)(const char *))(**(_DWORD **)v13 + 4))(a1: v13);
    this->m_bInEnterKeyPressedHandler = false;
    v19 = -1;
    v14 = szTypedText.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)szTypedText.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v14 + 4))(a1: v14);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100365F0
// Name: protected: void CFilteredComboBox::OnEscapeKeyPressed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilteredComboBox::OnEscapeKeyPressed(CFilteredComboBox *this)
{
  HWND__ *m_hWnd; // [esp-10h] [ebp-14h]
  char *m_pszData; // [esp-8h] [ebp-Ch]

  m_hWnd = this->m_hWnd;
  this->m_bInEnterKeyPressedHandler = true;
  SendMessageA(hWnd: m_hWnd, Msg: 0x14Fu, wParam: 0, lParam: 0);
  m_pszData = this->m_LastTextChangedValue.m_pszData;
  this->m_bInEnterKeyPressedHandler = false;
  CFilteredComboBox::FillDropdownList(
    this,
    pInitialSel: m_pszData,
    bEnableRedraw: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)1);
}

//------------------------------------------------------------------------------
// Address: 0x10036630
// Name: protected: int CFilteredComboBox::OnCloseUp(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CFilteredComboBox::OnCloseUp(CFilteredComboBox *this)
{
  ATL::IAtlStringMgr *StringManager; // eax
  LRESULT v3; // eax
  char *v4; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+4h] [ebp-10h] BYREF
  int v7; // [esp+10h] [ebp-4h]

  if ( !this->m_bInEnterKeyPressedHandler )
  {
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    str.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
    v7 = 1;
    if ( SendMessageA(hWnd: this->m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0) == -1
      || SendMessageA(hWnd: this->m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0) == 0 )
    {
      ATL::CSimpleStringT<char,0>::operator=(this: &str, strSrc: (ATL::CStringData *)&this->m_LastTextChangedValue);
    }
    else
    {
      v3 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
      CComboBox::GetLBText(this, nIndex: v3, rString: &str);
    }
    CFilteredComboBox::OnEnterKeyPressed(this, pForceText: str.m_pszData);
    v7 = -1;
    v4 = str.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v4 + 4))(a1: v4);
  }
  return !this->m_bNotifyParent;
}

//------------------------------------------------------------------------------
// Address: 0x10036730
// Name: public: void CFilteredComboBox::SetSuggestions(class CUtlVector<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,class CUtlMemory<class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>>,int>> __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilteredComboBox::SetSuggestions(
        CFilteredComboBox *this,
        CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >,int> > *suggestions,
        int flags)
{
  void *v4; // eax
  CGdiObject *v5; // eax
  HFONT v6; // eax
  ATL::IAtlStringMgr *StringManager; // eax
  char v8; // bl
  bool v9; // al
  ATL::IAtlStringMgr *v10; // eax
  int v11; // eax
  char *v12; // eax
  LOGFONTA pv; // [esp+8h] [ebp-50h] BYREF
  unsigned int sel; // [esp+44h] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+48h] [ebp-10h] BYREF
  int v16; // [esp+54h] [ebp-4h]
  bool bCallback_3; // [esp+63h] [ebp+Bh]

  if ( this->m_NormalFont.m_hObject == nullptr )
  {
    v4 = (void *)SendMessageA(hWnd: this->m_hWnd, Msg: 0x31u, wParam: 0, lParam: 0);
    v5 = CGdiObject::FromHandle(h: v4);
    if ( v5 != nullptr )
    {
      GetObjectA(h: v5->m_hObject, c: 60, &pv);
      v6 = CreateFontIndirectA(lplf: &pv);
      CGdiObject::Attach(this: &this->m_NormalFont, hObject: v6);
    }
  }
  CUtlVector<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,CUtlMemory<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,int>>::operator=(
    this: &this->m_Suggestions,
    other: suggestions);
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  str.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v16 = 1;
  CWnd::GetWindowTextA(this, rString: &str);
  sel = SendMessageA(hWnd: this->m_hWnd, Msg: 0x140u, wParam: 0, lParam: 0);
  CFilteredComboBox::FillDropdownList(this, pInitialSel: nullptr, bEnableRedraw: nullptr);
  v8 = flags & 1;
  bCallback_3 = (flags & 2) != 0;
  v9 = this->m_bOnlyProvideSuggestions && CFilteredComboBox::FindSuggestion(this, pTest: str.m_pszData) == -1;
  if ( v8 != 0 || v9 )
  {
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
    if ( SendMessageA(hWnd: this->m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0) <= 0 )
    {
      ATL::CSimpleStringT<char,0>::SetString(this: &this->m_LastTextChangedValue, pszSrc: &var, nLength: 0);
    }
    else
    {
      v10 = AfxGetStringManager();
      if ( v10 == nullptr )
        ATL::AtlThrowImpl(hr: -2147467259);
      flags = (int)&v10->GetNilString(this: v10)[1];
      LOBYTE(v16) = 3;
      CComboBox::GetLBText(
        this,
        nIndex: 0,
        rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&flags);
      if ( bCallback_3 )
        CFilteredComboBox::DoTextChangedCallback(this, pText: (const char *)flags);
      LOBYTE(v16) = 1;
      v11 = flags - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)(flags - 16 + 12)) <= 0 )
        (*(void (__stdcall **)(int))(**(_DWORD **)v11 + 4))(a1: v11);
    }
  }
  else
  {
    CWnd::SetWindowTextA(this, lpszString: str.m_pszData);
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x142u, wParam: 0, lParam: sel);
    if ( bCallback_3 )
      CFilteredComboBox::DoTextChangedCallback(this, pText: str.m_pszData);
  }
  SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
  InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
  v16 = -1;
  v12 = str.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v12 + 4))(a1: v12);
}

//------------------------------------------------------------------------------
// Address: 0x10036970
// Name: public: void CFilteredComboBox::SelectItem(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFilteredComboBox::SelectItem(CFilteredComboBox *this, const char *pStr)
{
  const char *v2; // edi
  LRESULT v4; // ebx
  ATL::IAtlStringMgr *StringManager; // eax
  char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > rString; // [esp+8h] [ebp-10h] BYREF
  int v10; // [esp+14h] [ebp-4h]

  v2 = pStr;
  if ( pStr == nullptr )
  {
    CWnd::SetWindowTextA(this, lpszString: &var);
    return;
  }
  v4 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v4 == -1 )
    goto LABEL_15;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  pStr = (const char *)&StringManager->GetNilString(this: StringManager)[1];
  v10 = 1;
  CComboBox::GetLBText(
    this,
    nIndex: v4,
    rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pStr);
  if ( _V_stricmp(s1: v2, s2: pStr) != 0 )
  {
    v10 = -1;
    v8 = pStr - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)pStr - 1) <= 0 )
      (*(void (__stdcall **)(const char *))(**(_DWORD **)v8 + 4))(a1: v8);
LABEL_15:
    if ( this->m_bOnlyProvideSuggestions && CFilteredComboBox::FindSuggestion(this, pTest: v2) == -1 )
      CWnd::SetWindowTextA(this, lpszString: v2);
    else
      CFilteredComboBox::FillDropdownList(
        this,
        pInitialSel: v2,
        bEnableRedraw: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)1);
    return;
  }
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(this: &rString);
  LOBYTE(v10) = 2;
  CWnd::GetWindowTextA(this, &rString);
  if ( _V_stricmp(s1: rString.m_pszData, s2: v2) != 0 )
    CWnd::SetWindowTextA(this, lpszString: v2);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::operator=(
    this: &this->m_LastTextChangedValue,
    pszSrc: v2);
  LOBYTE(v10) = 1;
  v6 = rString.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)rString.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v6 + 4))(a1: v6);
  v10 = -1;
  v7 = pStr - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)pStr - 1) <= 0 )
    (*(void (__stdcall **)(const char *))(**(_DWORD **)v7 + 4))(a1: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10036B30
// Name: protected: virtual long CFilteredComboBox::DefWindowProcA(unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFilteredComboBox::DefWindowProcA(
        CFilteredComboBox *this,
        unsigned int message,
        unsigned int wParam,
        int lParam)
{
  if ( message != 256 )
    return CWnd::DefWindowProcA(this, nMsg: message, wParam, lParam);
  if ( wParam == 13 )
  {
    CFilteredComboBox::OnEnterKeyPressed(this, pForceText: nullptr);
    return 0;
  }
  if ( wParam != 27 )
    return CWnd::DefWindowProcA(this, nMsg: message, wParam, lParam);
  CFilteredComboBox::OnEscapeKeyPressed(this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10036B80
// Name: protected: virtual struct AFX_MSGMAP const __near * CFilteredComboBox::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CFilteredComboBox::GetMessageMap(CFilteredComboBox *this)
{
  return &messageMap;
}

//------------------------------------------------------------------------------
// Address: 0x1033F6E2
// Name: public: void CWnd::MoveWindow(int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWnd::MoveWindow(CWnd *this, int x, int y, int nWidth, int nHeight, BOOL bRepaint)
{
  if ( this->m_pCtrlSite != nullptr )
    this->m_pCtrlSite->MoveWindow(this: this->m_pCtrlSite, a2: x, a3: y, a4: nWidth, a5: nHeight);
  else
    MoveWindow(hWnd: this->m_hWnd, X: x, Y: y, nWidth, nHeight, bRepaint);
}

//------------------------------------------------------------------------------
// Address: 0x103439CC
// Name: public: virtual struct CRuntimeClass __near * CGdiObject::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CGdiObject::GetRuntimeClass(CGdiObject *this)
{
  return &CGdiObject::classCGdiObject;
}

//------------------------------------------------------------------------------
// Address: 0x103439DE
// Name: public: virtual struct CRuntimeClass __near * CFont::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CFont::GetRuntimeClass(CFont *this)
{
  return &CFont::classCFont;
}

//------------------------------------------------------------------------------
// Address: 0x10343F35
// Name: public: static class CObject __near * CGdiObject::CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
CObject *__stdcall CGdiObject::CreateObject()
{
  CObject *result; // eax

  result = (CObject *)operator new(nSize: 8u);
  if ( result == nullptr )
    return nullptr;
  result->__vftable = (CObject_vtbl *)&CGdiObject::`vftable';
  result[1].__vftable = nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103442D2
// Name: public: static class CGdiObject __near * CGdiObject::FromHandle(void __near *)
// Source: json
//------------------------------------------------------------------------------
CGdiObject *__stdcall CGdiObject::FromHandle(void *h)
{
  CHandleMap *v1; // eax

  v1 = afxMapHGDIOBJ(bCreate: 1);
  return (CGdiObject *)CHandleMap::FromHandle(this: v1, h);
}

//------------------------------------------------------------------------------
// Address: 0x103442E6
// Name: public: int CGdiObject::Attach(void __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGdiObject::Attach(CGdiObject *this, void *hObject)
{
  int result; // eax
  CHandleMap *v4; // eax

  result = (int)hObject;
  if ( hObject != nullptr )
  {
    this->m_hObject = hObject;
    v4 = afxMapHGDIOBJ(bCreate: 1);
    *CMapPtrToPtr::operator[](this: &v4->m_permanentMap, key: this->m_hObject) = this;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10344314
// Name: public: void __near * CGdiObject::Detach(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CGdiObject::Detach(CGdiObject *this)
{
  void *m_hObject; // edi
  CHandleMap *v3; // eax

  m_hObject = this->m_hObject;
  if ( m_hObject != nullptr )
  {
    v3 = afxMapHGDIOBJ(bCreate: 0);
    if ( v3 != nullptr )
      CMapPtrToPtr::RemoveKey(this: &v3->m_permanentMap, key: this->m_hObject);
  }
  this->m_hObject = nullptr;
  return m_hObject;
}

//------------------------------------------------------------------------------
// Address: 0x10344340
// Name: public: int CGdiObject::DeleteObject(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CGdiObject::DeleteObject(CGdiObject *this)
{
  void *v2; // eax

  if ( this->m_hObject == nullptr )
    return false;
  v2 = CGdiObject::Detach(this);
  return DeleteObject(ho: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10348796
// Name: public: virtual int CComboBox::Create(unsigned long,struct tagRECT const __near &,class CWnd __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CComboBox::Create(
        CComboBox *this,
        unsigned int dwStyle,
        const tagRECT *rect,
        CWnd *pParentWnd,
        unsigned int nID)
{
  return this->Create(this, a2: "COMBOBOX", a3: nullptr, a4: dwStyle, a5: rect, a6: pParentWnd, a7: nID, a8: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x103487B9
// Name: public: virtual CComboBox::~CComboBox(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CComboBox::~CComboBox(CComboBox *this)
{
  this->__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  CWnd::DestroyWindow(this);
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x103487EA
// Name: protected: virtual int CComboBox::OnChildNotify(unsigned int,unsigned int,long,long __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CComboBox::OnChildNotify(
        CComboBox *this,
        unsigned int message,
        unsigned int wParam,
        tagDRAWITEMSTRUCT *lParam,
        int *pResult)
{
  switch ( message )
  {
    case '+':
      this->DrawItem(this, a2: lParam);
      break;
    case ',':
      this->MeasureItem(this, a2: (tagMEASUREITEMSTRUCT *)lParam);
      break;
    case '-':
      this->DeleteItem(this, a2: (tagDELETEITEMSTRUCT *)lParam);
      break;
    case '9':
      *pResult = this->CompareItem(this, a2: (tagCOMPAREITEMSTRUCT *)lParam);
      break;
    default:
      return CWnd::OnChildNotify(this, uMsg: message, wParam, (int)lParam, pResult);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10348900
// Name: public: virtual struct CRuntimeClass __near * CComboBox::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CComboBox::GetRuntimeClass(CComboBox *this)
{
  return &CComboBox::classCComboBox;
}

//------------------------------------------------------------------------------
// Address: 0x10348978
// Name: public: void CComboBox::GetLBText(int,class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CComboBox::GetLBText(
        CComboBox *this,
        WPARAM nIndex,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *rString)
{
  LRESULT v4; // eax
  char *BufferSetLength; // eax

  v4 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x149u, wParam: nIndex, lParam: 0);
  BufferSetLength = ATL::CSimpleStringT<char,0>::GetBufferSetLength(this: rString, nLength: v4);
  SendMessageA(hWnd: this->m_hWnd, Msg: 0x148u, wParam: nIndex, lParam: (LPARAM)BufferSetLength);
  ATL::CSimpleStringT<char,0>::ReleaseBuffer(this: rString, nNewLength: -1);
}

//------------------------------------------------------------------------------
// Address: 0x1034B78C
// Name: public: int CFont::CreatePointFontIndirect(struct tagLOGFONTA const __near *,class CDC __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFont::CreatePointFontIndirect(CFont *this, const tagLOGFONTA *lpLogFont, CDC *pDC)
{
  HDC__ *m_hAttribDC; // ebx
  int DeviceCaps; // eax
  HFONT v5; // eax
  int lfHeight; // [esp-8h] [ebp-6Ch]
  tagPOINT ptOrg; // [esp+14h] [ebp-50h] BYREF
  tagPOINT pt; // [esp+1Ch] [ebp-48h] BYREF
  tagLOGFONTA logFont; // [esp+24h] [ebp-40h] BYREF

  if ( pDC != nullptr )
    m_hAttribDC = pDC->m_hAttribDC;
  else
    m_hAttribDC = GetDC(hWnd: nullptr);
  logFont = *lpLogFont;
  lfHeight = logFont.lfHeight;
  DeviceCaps = GetDeviceCaps(hdc: m_hAttribDC, index: 90);
  pt.y = MulDiv(nNumber: DeviceCaps, nNumerator: lfHeight, nDenominator: 720);
  pt.x = 0;
  DPtoLP(hdc: m_hAttribDC, lppt: &pt, c: 1);
  ptOrg.x = 0;
  ptOrg.y = 0;
  DPtoLP(hdc: m_hAttribDC, lppt: &ptOrg, c: 1);
  logFont.lfHeight = -abs(lnumber: pt.y - ptOrg.y);
  if ( pDC == nullptr )
    ReleaseDC(hWnd: nullptr, hDC: m_hAttribDC);
  v5 = CreateFontIndirectA(lplf: &logFont);
  return CGdiObject::Attach(this, hObject: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1034B877
// Name: public: int CFont::CreatePointFont(int,char const __near *,class CDC __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFont::CreatePointFont(CFont *this, int nPointSize, const char *lpszFaceName, CDC *pDC)
{
  int v5; // eax
  tagLOGFONTA logFont; // [esp+Ch] [ebp-40h] BYREF

  memset(dst: (unsigned __int8 *)&logFont, value: 0, count: sizeof(logFont));
  logFont.lfHeight = nPointSize;
  logFont.lfCharSet = 1;
  v5 = _mbsnbcpy_s(
         _Arg1: (unsigned __int8 *)logFont.lfFaceName,
         _Arg2: 0x20u,
         _Arg3: (const unsigned __int8 *)lpszFaceName,
         _Arg4: 0xFFFFFFFF);
  AfxCrtErrorCheck(error: v5);
  return CFont::CreatePointFontIndirect(this, lpLogFont: &logFont, pDC);
}

//------------------------------------------------------------------------------
// Address: 0x103BF3B1
// Name: public: virtual void CMFCToolBarButton::EnableWindow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarButton::EnableWindow(CMFCToolBarButton *this, BOOL bEnable)
{
  HWND v3; // eax

  if ( this->GetHwnd(this) != nullptr )
  {
    v3 = this->GetHwnd(this);
    EnableWindow(hWnd: v3, bEnable);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103E1799
// Name: public: virtual void __near * CBasePane::MoveWindow(class CRect __near &,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
HDWP __thiscall CBasePane::MoveWindow(CBasePane *this, CRect *rect, int bRepaint, void *hdwp)
{
  CPaneFrameWnd *v5; // eax
  CWnd *m_pDockSite; // ecx
  HWND__ *m_hWnd; // [esp-8h] [ebp-2Ch]
  CRect rectOld; // [esp+10h] [ebp-14h] BYREF

  m_hWnd = this->m_hWnd;
  memset(&rectOld, 0, sizeof(rectOld));
  GetWindowRect(hWnd: m_hWnd, lpRect: &rectOld);
  if ( this->IsFloating(this) != 0 )
  {
    v5 = this->GetParentMiniFrame(this, a2: 0);
    CWnd::ScreenToClient(this: v5, lpRect: &rectOld);
  }
  else
  {
    m_pDockSite = this->m_pDockSite;
    if ( m_pDockSite != nullptr )
      CWnd::ScreenToClient(this: m_pDockSite, lpRect: &rectOld);
  }
  if ( EqualRect(lprc1: &rectOld, lprc2: rect) )
    return hdwp;
  if ( hdwp != nullptr )
    return DeferWindowPos(
             hWinPosInfo: hdwp,
             hWnd: this->m_hWnd,
             hWndInsertAfter: nullptr,
             x: rect->left,
             y: rect->top,
             cx: rect->right - rect->left,
             cy: rect->bottom - rect->top,
             uFlags: 0x14u);
  CWnd::MoveWindow(this, lpRect: rect, bRepaint);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103E4BBB
// Name: public: virtual void CMFCToolBarComboBoxButton::EnableWindow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarComboBoxButton::EnableWindow(CMFCToolBarComboBoxButton *this, int bEnable)
{
  CComboBox *m_pWndCombo; // ecx
  CEdit *m_pWndEdit; // ecx

  m_pWndCombo = this->m_pWndCombo;
  if ( m_pWndCombo != nullptr && m_pWndCombo->m_hWnd != nullptr )
    CWnd::EnableWindow(this: m_pWndCombo, bEnable);
  m_pWndEdit = this->m_pWndEdit;
  if ( m_pWndEdit != nullptr && m_pWndEdit->m_hWnd != nullptr )
    CWnd::EnableWindow(this: m_pWndEdit, bEnable);
}

//------------------------------------------------------------------------------
// Address: 0x10343F4F
// Name: public: static void ConstructDestruct<class CDC>::Construct(class CObject __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall ConstructDestruct<CDC>::Construct(CObject *pObject)
{
  if ( pObject != nullptr )
  {
    pObject->__vftable = (CObject_vtbl *)&CDC::`vftable';
    pObject[1].__vftable = nullptr;
    pObject[2].__vftable = nullptr;
    pObject[3].__vftable = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10343F70
// Name: public: static void ConstructDestruct<class CGdiObject>::Construct(class CObject __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall ConstructDestruct<CGdiObject>::Construct(CObject *pObject)
{
  if ( pObject != nullptr )
  {
    pObject[1].__vftable = nullptr;
    pObject->__vftable = (CObject_vtbl *)&CGdiObject::`vftable';
  }
}

//------------------------------------------------------------------------------
// Address: 0x10343F8A
// Name: class CHandleMap __near * afxMapHDC(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHandleMap *__stdcall afxMapHDC(int bCreate)
{
  AFX_MODULE_THREAD_STATE *ModuleThreadState; // esi
  int (__cdecl *v2)(unsigned int); // ebx
  CHandleMap *v3; // ecx
  CHandleMap *v4; // eax

  ModuleThreadState = AfxGetModuleThreadState();
  if ( ModuleThreadState->m_pmapHDC == nullptr && bCreate != 0 )
  {
    v2 = AfxSetNewHandler(pfnNewHandler: AfxCriticalNewHandler);
    v3 = (CHandleMap *)operator new(nSize: 0x60u);
    if ( v3 != nullptr )
      v4 = CHandleMap::CHandleMap(
             this: v3,
             pClass: &CDC::classCDC,
             pfnConstructObject: ConstructDestruct<CDC>::Construct,
             pfnDestructObject: ConstructDestruct<CGdiObject>::Destruct,
             nOffset: 4u,
             nHandles: 2);
    else
      v4 = nullptr;
    ModuleThreadState->m_pmapHDC = v4;
    AfxSetNewHandler(pfnNewHandler: v2);
  }
  return ModuleThreadState->m_pmapHDC;
}

//------------------------------------------------------------------------------
// Address: 0x103489BD
// Name: int AfxDlgProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__stdcall AfxDlgProc(HWND__ *hWnd, unsigned int message, unsigned int __formal, int a4)
{
  CWnd *v4; // eax
  CObject *v5; // eax

  if ( message != 272 )
    return nullptr;
  v4 = CWnd::FromHandlePermanent(hWnd);
  v5 = AfxDynamicDownCast(pClass: &CDialog::classCDialog, pObject: v4);
  if ( v5 != nullptr )
    return v5->__vftable[31].GetRuntimeClass(this: v5);
  else
    return (CRuntimeClass *)1;
}

//------------------------------------------------------------------------------
// Address: 0x103BF3D8
// Name: public: virtual int CMFCToolBarButton::IsWindowVisible(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCToolBarButton::IsWindowVisible(CMFCToolBarButton *this)
{
  HWND__ *v2; // eax
  CWnd *v3; // eax

  if ( this->GetHwnd(this) != nullptr )
  {
    v2 = this->GetHwnd(this);
    v3 = CWnd::FromHandle(hWnd: v2);
  }
  else
  {
    v3 = nullptr;
  }
  return v3 != nullptr && (CWnd::GetStyle(this: v3) & 0x10000000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x103BF411
// Name: public: virtual int CMFCToolBarButton::IsOwnerOf(struct HWND__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCToolBarButton::IsOwnerOf(CMFCToolBarButton *this, HWND__ *hwnd)
{
  HWND v3; // eax
  BOOL result; // eax

  result = false;
  if ( this->GetHwnd(this) != nullptr )
  {
    if ( this->GetHwnd(this) == hwnd )
      return true;
    v3 = this->GetHwnd(this);
    if ( IsChild(hWndParent: v3, hWnd: hwnd) )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103BF44F
// Name: public: virtual int CMFCToolBarButton::HasFocus(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCToolBarButton::HasFocus(CMFCToolBarButton *this)
{
  HWND v1; // edi
  HWND Focus; // eax
  BOOL result; // eax

  v1 = this->GetHwnd(this);
  result = false;
  if ( v1 != nullptr )
  {
    if ( v1 == GetFocus() )
      return true;
    Focus = GetFocus();
    if ( IsChild(hWndParent: v1, hWnd: Focus) )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103BF480
// Name: public: virtual void CMFCOutlookBarPaneButton::OnChangeParentWnd(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarPaneButton::OnChangeParentWnd(CMFCOutlookBarPaneButton *this, CWnd *pWndParent)
{
  CMFCToolBarButton::OnChangeParentWnd(this, pWndParent);
  this->m_pWndParentBar = (CMFCOutlookBarPane *)AfxDynamicDownCast(
                                                  pClass: &CMFCOutlookBarPane::classCMFCOutlookBarPane,
                                                  pObject: pWndParent);
}

//------------------------------------------------------------------------------
// Address: 0x103BF4A7
// Name: public: virtual int CMFCOutlookBarPaneButton::CanBeDropped(class CMFCToolBar __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCOutlookBarPaneButton::CanBeDropped(CMFCOutlookBarPaneButton *this, CMFCToolBar *pToolbar)
{
  return CObject::IsKindOf(this: pToolbar, pClass: &CMFCOutlookBarPane::classCMFCOutlookBarPane);
}

//------------------------------------------------------------------------------
// Address: 0x103BF4BD
// Name: public: virtual void CMFCOutlookBarPaneButton::SetImage(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarPaneButton::SetImage(CMFCOutlookBarPaneButton *this, int iImage)
{
  this->m_iImage = iImage;
}

//------------------------------------------------------------------------------
// Address: 0x103BF4CC
// Name: public: static class CObject __near * CMFCOutlookBarPaneButton::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCOutlookBarPaneButton *__stdcall CMFCOutlookBarPaneButton::CreateObject()
{
  CMFCOutlookBarPaneButton *v0; // ecx
  CMFCOutlookBarPaneButton *result; // eax

  v0 = (CMFCOutlookBarPaneButton *)operator new(nSize: 0x80u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCOutlookBarPaneButton::CMFCOutlookBarPaneButton(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103BF523
// Name: public: virtual int CMFCToolBarButton::IsEditable(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCToolBarButton::IsEditable(CMFCToolBarButton *this)
{
  HWND__ *m_nID; // esi

  m_nID = (HWND__ *)this->m_nID;
  return IsStandardCommand(uiCmd: (unsigned int)m_nID) == 0
      && CList<unsigned int,unsigned int>::Find(
           this: (CList<HWND__ *,HWND__ *> *)&CMFCToolBarButton::m_lstProtectedCommands,
           searchValue: m_nID,
           startAfter: nullptr) == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x103BF54B
// Name: public: virtual void CMFCOutlookBarPaneButton::OnDraw(class CDC __near *,class CRect const __near &,class CMFCToolBarImages __near *,int,int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCOutlookBarPaneButton::OnDraw(
        CMFCOutlookBarPaneButton *this,
        CDC *pDC,
        const CRect *rect,
        CMFCToolBarImages *pImages,
        int bHorz,
        int bCustomizeMode,
        int bHighlight,
        int __formal,
        int a9)
{
  bool v10; // zf
  CMFCVisualManager *Instance; // eax
  int m_iImage; // eax
  CDrawingManager_vtbl *cx; // ecx
  CDC *cy; // esi
  int v15; // eax
  int v16; // edx
  char *m_pszData; // eax
  CDC_vtbl *v18; // esi
  int v19; // eax
  CMFCVisualManager *v20; // eax
  int m_iUserImage; // eax
  unsigned int m_nStyle; // eax
  CMFCVisualManager *v23; // eax
  CMFCVisualManager *v24; // eax
  int v25; // esi
  CMFCOutlookBarPane *m_pWndParentBar; // ecx
  int clrGrayedText; // eax
  CMFCVisualManager *v28; // eax
  char *v29; // ebx
  CDC_vtbl *v30; // eax
  CMap<unsigned int,unsigned int,int,int>::CAssoc *m_pFreeList; // [esp-8h] [ebp-98h]
  int v32; // [esp+14h] [ebp-7Ch]
  int v33; // [esp+18h] [ebp-78h]
  int v34; // [esp+1Ch] [ebp-74h]
  CMFCToolBarImages *v35; // [esp+20h] [ebp-70h]
  CDrawingManager v36; // [esp+2Ch] [ebp-64h] BYREF
  int v37; // [esp+34h] [ebp-5Ch] BYREF
  int v38; // [esp+38h] [ebp-58h]
  CDC *pDCa; // [esp+3Ch] [ebp-54h]
  tagRECT v40; // [esp+40h] [ebp-50h] BYREF
  tagRECT v41; // [esp+50h] [ebp-40h] BYREF
  tagRECT v42; // [esp+60h] [ebp-30h] BYREF
  tagRECT v43; // [esp+70h] [ebp-20h] BYREF
  tagRECT v44; // [esp+80h] [ebp-10h]

  pDCa = pDC;
  v32 = 0;
  v33 = 0;
  if ( bCustomizeMode == 0 && bHighlight != 0 && (this->m_nStyle & 0x20000) != 0 )
  {
    v32 = 1;
    v33 = 1;
  }
  v10 = this->m_bExtraSize == 0;
  v42 = rect->tagRECT;
  v43 = rect->tagRECT;
  if ( !v10 )
  {
    Instance = CMFCVisualManager::GetInstance();
    Instance->GetButtonExtraBorder(this: Instance, result: (CSize *)&v37);
    if ( v37 != 0 || v38 != 0 )
    {
      InflateRect(lprc: &v42, dx: -(v37 / 2 + 1), dy: -(v38 / 2 + 1));
      if ( bHorz != 0 )
        OffsetRect(lprc: &v43, dx: v37, dy: 0);
      else
        OffsetRect(lprc: &v43, dx: 0, dy: v38);
    }
  }
  v43.top += 5;
  v41 = v42;
  if ( pImages != nullptr
    && (this->m_bUserButton == 0 ? (m_iImage = this->m_iImage) : (m_iImage = this->m_iUserImage), m_iImage >= 0) )
  {
    cx = (CDrawingManager_vtbl *)pImages->m_sizeImage.cx;
    cy = (CDC *)pImages->m_sizeImage.cy;
    v36.__vftable = cx;
    v36.m_dc = cy;
    if ( bHorz != 0 )
    {
      v34 = v42.top + (v42.bottom - (int)cy - v42.top) / 2;
      v43.left += (int)&cx->Serialize + 2;
      m_pszData = this->m_strText.m_pszData;
      v40 = v43;
      v18 = pDCa->__vftable;
      v38 = v42.left + 5;
      v19 = v18->DrawTextA(this: pDCa, a2: m_pszData, a3: *((_DWORD *)m_pszData - 3), a4: &v40, a5: 1040u);
      cy = v36.m_dc;
      cx = v36.__vftable;
      v16 = v34;
      v43.top = v42.top + (v42.bottom - v19 - v42.top) / 2;
      v15 = v38;
    }
    else
    {
      v15 = v42.left + (v42.right - v42.left - (int)cx) / 2;
      v16 = v42.top + 5;
      v38 = v15;
      v34 = v42.top + 5;
      v43.top += (int)&cy->__vftable + 2;
    }
    v36.m_dc = (CDC *)((char *)cy + v16);
    v36.__vftable = (CDrawingManager_vtbl *)((char *)cx + v15);
    v41.left = v15;
    v41.top = v16;
    v41.right = (int)cx + v15;
    v41.bottom = (int)cy + v16;
    InflateRect(lprc: &v41, dx: 2, dy: 2);
    if ( this->m_pWndParentBar->m_bDrawShadedHighlight != 0 )
    {
      if ( bHighlight != 0 && bCustomizeMode == 0 )
      {
        CDrawingManager::CDrawingManager(this: &v36, m_dc: pDCa);
        v44.bottom = 0;
        CDrawingManager::HighlightRect(
          this: &v36,
          rect: (CRect)v41,
          nPercentage: 85,
          clrTransparent: -1,
          nTolerance: 0,
          clrBlend: 0xFFFFFFFF);
        v44.bottom = -1;
        CDrawingManager::~CDrawingManager(this: &v36);
      }
    }
    else
    {
      if ( this->m_bExtraSize != 0 )
      {
        v20 = CMFCVisualManager::GetInstance();
        v20->GetButtonExtraBorder(this: v20, result: (CSize *)&v36);
        if ( v36.__vftable != nullptr || v36.m_dc != nullptr )
          InflateRect(lprc: &v41, dx: (int)v36.__vftable / 2 - 1, dy: (int)v36.m_dc / 2 - 1);
      }
      CMFCToolBarButton::FillInterior(this, pDC: pDCa, rect: (const CRect *)&v41, bHighlight, bMenuImage: 0);
    }
    if ( this->m_bUserButton != 0 )
      m_iUserImage = this->m_iUserImage;
    else
      m_iUserImage = this->m_iImage;
    CMFCToolBarImages::Draw(
      this: pImages,
      pDCDest: pDCa,
      xDest: v38 + v32,
      yDest: v34 + v33,
      iImage: m_iUserImage,
      bHilite: 0,
      bDisabled: this->m_nStyle & 0x40000,
      bIndeterminate: 0,
      bShadow: 0,
      bInactive: 0,
      alphaSrc: 0xFFu);
  }
  else if ( bHighlight != 0 && this->m_pWndParentBar->m_bDrawShadedHighlight != 0 )
  {
    if ( bCustomizeMode != 0 )
      goto LABEL_44;
    CDrawingManager::CDrawingManager(this: &v36, m_dc: pDCa);
    v44.bottom = 1;
    CDrawingManager::HighlightRect(
      this: &v36,
      rect: (CRect)v41,
      nPercentage: 85,
      clrTransparent: -1,
      nTolerance: 0,
      clrBlend: 0xFFFFFFFF);
    v44.bottom = -1;
    CDrawingManager::~CDrawingManager(this: &v36);
  }
  if ( bCustomizeMode == 0 && (bHighlight != 0 || (this->m_nStyle & 0x30000) != 0) )
  {
    m_nStyle = this->m_nStyle;
    if ( (m_nStyle & 0x20000) != 0 && bHighlight != 0 || (m_nStyle & 0x10000) != 0 )
    {
      v23 = CMFCVisualManager::GetInstance();
      ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCOutlookBarPaneButton *, int, int, int, int, int))v23->OnDrawButtonBorder)(
        a1: v23,
        a2: pDCa,
        a3: this,
        a4: v41.left,
        a5: v41.top,
        a6: v41.right,
        a7: v41.bottom,
        a8: 1);
    }
    else
    {
      v24 = CMFCVisualManager::GetInstance();
      ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCOutlookBarPaneButton *, int, int, int, int, int))v24->OnDrawButtonBorder)(
        a1: v24,
        a2: pDCa,
        a3: this,
        a4: v41.left,
        a5: v41.top,
        a6: v41.right,
        a7: v41.bottom,
        a8: 2);
    }
  }
LABEL_44:
  if ( this->m_bTextBelow != 0 && *((_DWORD *)this->m_strText.m_pszData - 3) != 0 )
  {
    if ( bHighlight != 0 )
      v25 = 2;
    else
      v25 = (this->m_nStyle & 0x30000) != 0;
    m_pWndParentBar = this->m_pWndParentBar;
    if ( (this->m_nStyle & 0x40000) != 0 )
    {
      if ( m_pWndParentBar->m_bmpBack.m_iCount == 0 )
        goto LABEL_56;
      clrGrayedText = afxGlobalData.clrGrayedText;
    }
    else
    {
      clrGrayedText = m_pWndParentBar->m_clrRegText;
    }
    if ( clrGrayedText == -1 )
    {
      if ( m_pWndParentBar->m_bmpBack.m_iCount != 0 )
      {
        clrGrayedText = afxGlobalData.clrWindowText;
        goto LABEL_57;
      }
LABEL_56:
      v28 = CMFCVisualManager::GetInstance();
      clrGrayedText = v28->GetToolbarButtonTextColor(this: v28, a2: this, a3: (CMFCVisualManager::AFX_BUTTON_STATE)v25);
    }
LABEL_57:
    pDCa->SetTextColor(this: pDCa, a2: clrGrayedText);
    v10 = this->m_bIsWholeText == 0;
    v29 = this->m_strText.m_pszData;
    if ( v10 )
    {
      v35 = (CMFCToolBarImages *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)v29 - 1)[1];
      v30 = pDCa->__vftable;
      m_pFreeList = v35[-1].m_mapOrigResOffsets.m_pFreeList;
      v44.bottom = 2;
      v30->DrawTextA(this: pDCa, a2: (const char *)v35, a3: (int)m_pFreeList, a4: &v43, a5: 32784u);
      ATL::CStringData::Release(this: (ATL::CStringData *)&v35[-1].m_mapOrigResOffsets.m_nCount);
    }
    else
    {
      pDCa->DrawTextA(this: pDCa, a2: v29, a3: *((_DWORD *)v29 - 3), a4: &v43, a5: 17u);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BF965
// Name: public: virtual struct tagSIZE CMFCOutlookBarPaneButton::OnCalculateSize(class CDC __near *,class CSize const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall CMFCOutlookBarPaneButton::OnCalculateSize(
        CMFCOutlookBarPaneButton *this,
        CDC *pDC,
        CDC *sizeDefault,
        const CSize *bHorz,
        int bHorza)
{
  int right; // ecx
  int v7; // eax
  int cx; // esi
  int v9; // edi
  int v10; // ecx
  int v11; // edx
  int cy; // ecx
  char *m_pszData; // eax
  CSize *TextExtent; // eax
  int v15; // esi
  int v16; // edi
  _DWORD *result; // eax
  CSize v18; // [esp+Ch] [ebp-30h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+14h] [ebp-28h] BYREF
  CDC *v20; // [esp+18h] [ebp-24h]
  CSize sizeResult; // [esp+1Ch] [ebp-20h]
  int iTextHeight; // [esp+24h] [ebp-18h]
  CRect rectText; // [esp+28h] [ebp-14h] BYREF

  v20 = pDC;
  sizeResult.cx = bHorz->cx;
  sizeResult.cy = bHorz->cy;
  if ( bHorza != 0 )
  {
    cy = bHorz->cy;
    memset(&rectText, 0, 12);
    rectText.bottom = cy;
    if ( this->m_bTextBelow != 0 )
    {
      do
      {
        m_pszData = this->m_strText.m_pszData;
        ++rectText.right;
        iTextHeight = sizeDefault->DrawTextA(
                        this: sizeDefault,
                        a2: m_pszData,
                        a3: *((_DWORD *)m_pszData - 3),
                        a4: &rectText,
                        a5: 1040u);
        TextExtent = CDC::GetTextExtent(this: sizeDefault, result: &v18, str: &this->m_strText);
      }
      while ( iTextHeight < TextExtent->cy && rectText.bottom - rectText.top > bHorz->cy );
    }
    v15 = bHorz->cy;
    v11 = bHorz->cx - rectText.left + rectText.right + 10;
    v16 = v15;
    if ( v15 >= rectText.bottom - rectText.top )
      v16 = rectText.bottom - rectText.top;
    if ( this->m_sizeImage.cy <= v16 )
    {
      sizeResult.cy = bHorz->cy;
      if ( v15 >= rectText.bottom - rectText.top )
        sizeResult.cy = rectText.bottom - rectText.top;
    }
    else
    {
      sizeResult.cy = this->m_sizeImage.cy;
    }
    this->m_bIsWholeText = 1;
  }
  else
  {
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
      this: &str,
      pszSrc: "   ");
    iTextHeight = CDC::GetTextExtent(this: sizeDefault, result: &v18, &str)->cx;
    ATL::CStringData::Release(this: (ATL::CStringData *)str.m_pszData - 1);
    right = bHorz->cx - iTextHeight;
    v7 = 0;
    rectText.left = 0;
    rectText.top = 0;
    rectText.right = right;
    rectText.bottom = 1;
    if ( this->m_bTextBelow != 0 )
    {
      v7 = sizeDefault->DrawTextA(
             this: sizeDefault,
             a2: this->m_strText.m_pszData,
             a3: *((_DWORD *)this->m_strText.m_pszData - 3),
             a4: &rectText,
             a5: 1040u);
      right = rectText.right;
    }
    cx = bHorz->cx;
    v9 = right - rectText.left;
    sizeResult.cy = bHorz->cy + v7 + 10;
    v10 = cx;
    if ( cx >= v9 )
      v10 = v9;
    v11 = this->m_sizeImage.cx + 4;
    if ( v11 <= v10 )
    {
      v11 = cx;
      if ( cx >= v9 )
        v11 = v9;
    }
    this->m_bIsWholeText = v9 <= cx;
  }
  result = &v20->__vftable;
  v20->m_hDC = (HDC__ *)sizeResult.cy;
  *result = v11;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103BFAE3
// Name: public: virtual struct CRuntimeClass __near * CMFCPopupMenuBar::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCPopupMenuBar::GetRuntimeClass(CMFCPopupMenuBar *this)
{
  return &CMFCPopupMenuBar::classCMFCPopupMenuBar;
}

//------------------------------------------------------------------------------
// Address: 0x103BFAE9
// Name: protected: virtual void CMFCPopupMenuBar::DrawSeparator(class CDC __near *,class CRect const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenuBar::DrawSeparator(CMFCPopupMenuBar *this, CDC *pDC, const CRect *rect, int __formal)
{
  CMFCVisualManager *Instance; // eax

  Instance = CMFCVisualManager::GetInstance();
  ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCPopupMenuBar *, int, int, int, int, _DWORD))Instance->OnDrawSeparator)(
    a1: Instance,
    a2: pDC,
    a3: this,
    a4: rect->left,
    a5: rect->top,
    a6: rect->right,
    a7: rect->bottom,
    a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103BFB18
// Name: protected: virtual void CMFCPopupMenuBar::DrawDragCursor(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenuBar::DrawDragCursor(CMFCPopupMenuBar *this, CDC *pDC)
{
  int v3; // edi
  CPoint v5; // [esp+8h] [ebp-18h] BYREF
  CPoint v6; // [esp+10h] [ebp-10h] BYREF
  CPoint result; // [esp+18h] [ebp-8h] BYREF
  CFont *pOldPen; // [esp+28h] [ebp+8h]

  v3 = 0;
  if ( this->m_bPaletteMode == 0 )
  {
    pOldPen = CDC::SelectObject(this: pDC, pFont: (CFont *)&this->m_penDrag);
    do
    {
      CDC::MoveTo(
        this: pDC,
        &result,
        x: this->m_rectDrag.left,
        y: this->m_rectDrag.top + (this->m_rectDrag.bottom - this->m_rectDrag.top) / 2 + v3 - 1);
      CDC::LineTo(
        this: pDC,
        x: this->m_rectDrag.right,
        y: this->m_rectDrag.top + (this->m_rectDrag.bottom - this->m_rectDrag.top) / 2 + v3 - 1);
      CDC::MoveTo(this: pDC, result: &v6, x: v3 + this->m_rectDrag.left, y: v3 + this->m_rectDrag.top);
      CDC::LineTo(this: pDC, x: v3 + this->m_rectDrag.left, y: this->m_rectDrag.bottom - v3);
      CDC::MoveTo(this: pDC, result: &v5, x: this->m_rectDrag.right - v3 - 1, y: v3 + this->m_rectDrag.top);
      CDC::LineTo(this: pDC, x: this->m_rectDrag.right - v3 - 1, y: this->m_rectDrag.bottom - v3);
      ++v3;
    }
    while ( v3 < 2 );
    CDC::SelectObject(this: pDC, pFont: pOldPen);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103BFC26
// Name: protected: long CMFCPopupMenuBar::OnIdleUpdateCmdUI(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge CMFCPopupMenuBar::OnIdleUpdateCmdUI@<eax>(
        CMFCPopupMenuBar *this@<ecx>,
        int a2@<esi>,
        unsigned int __formal,
        unsigned int __formala)
{
  CFrameWnd *v5; // esi

  if ( this->m_bTrackMode == 0 && (CWnd::GetStyle(this) & 0x10000000) != 0 )
  {
    v5 = (CFrameWnd *)this->GetCommandTarget(this);
    if ( v5 == nullptr || v5->IsFrameWnd(this: v5) == 0 )
      v5 = AFXGetParentFrame(pWnd: this);
    if ( v5 != nullptr )
    {
      ((void (__thiscall *)(CFrameWnd *, int))v5->IsFrameWnd)(a1: v5, a2);
      ((void (__thiscall *)(CMFCPopupMenuBar *, CFrameWnd *))this->OnUpdateCmdUI)(a1: this, a2: v5);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103BFC93
// Name: protected: void CMFCPopupMenuBar::OnToolbarImageAndText(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenuBar::OnToolbarImageAndText(CMFCPopupMenuBar *this)
{
  CMFCToolBarButton *Button; // eax
  int m_bUserButton; // edx
  int m_iUserImage; // ecx
  _STATIC_CREATOR_ *CmdMgr; // eax
  unsigned int m_nID; // [esp-Ch] [ebp-10h]
  int v7; // [esp-4h] [ebp-8h]

  Button = CMFCToolBar::GetButton(this, nIndex: this->m_iSelected);
  if ( Button == nullptr )
    AfxThrowInvalidArgException();
  m_bUserButton = Button->m_bUserButton;
  if ( m_bUserButton != 0 )
    m_iUserImage = Button->m_iUserImage;
  else
    m_iUserImage = Button->m_iImage;
  if ( m_iUserImage >= 0 )
  {
    if ( m_bUserButton == 0 )
      m_iUserImage = -1;
    v7 = m_iUserImage;
    m_nID = Button->m_nID;
    CmdMgr = GetCmdMgr();
    CCommandManager::EnableMenuItemImage(this: &CmdMgr->s_TheCmdMgr, uiCmd: m_nID, bEnable: 1, iUserImage: v7);
  }
  else
  {
    CMFCToolBar::OnToolbarAppearance(this);
  }
  this->AdjustLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x103BFCEC
// Name: protected: void CMFCPopupMenuBar::OnToolbarText(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCPopupMenuBar::OnToolbarText(CMFCPopupMenuBar *this)
{
  CMFCToolBarButton *Button; // eax
  _STATIC_CREATOR_ *CmdMgr; // eax
  unsigned int m_nID; // [esp-Ch] [ebp-10h]

  Button = CMFCToolBar::GetButton(this, nIndex: this->m_iSelected);
  if ( Button == nullptr )
    AfxThrowInvalidArgException();
  m_nID = Button->m_nID;
  CmdMgr = GetCmdMgr();
  CCommandManager::EnableMenuItemImage(this: &CmdMgr->s_TheCmdMgr, uiCmd: m_nID, bEnable: 0, iUserImage: -1);
  this->AdjustLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x103E1864
// Name: public: virtual void __near * CBasePane::SetWindowPos(class CWnd const __near *,int,int,int,int,unsigned int,void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HDWP __thiscall CBasePane::SetWindowPos(
        CBasePane *this,
        const CWnd *pWndInsertAfter,
        int x,
        int y,
        int cx,
        int cy,
        UINT nFlags,
        void *hdwp)
{
  HDWP result; // eax
  HWND__ *m_hWnd; // eax

  if ( hdwp != nullptr )
  {
    if ( this != nullptr )
      m_hWnd = this->m_hWnd;
    else
      m_hWnd = nullptr;
    result = DeferWindowPos(hWinPosInfo: hdwp, hWnd: m_hWnd, hWndInsertAfter: nullptr, x, y, cx, cy, uFlags: nFlags);
    if ( result == nullptr )
    {
      GetLastError();
      this->SetWindowPos(this, a2: nullptr, a3: x, a4: y, a5: cx, a6: cy, a7: nFlags, a8: nullptr);
      return hdwp;
    }
  }
  else
  {
    CWnd::SetWindowPos(this, pWndInsertAfter, x, y, cx, cy, nFlags);
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103E18E2
// Name: protected: void CBasePane::OnSize(unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CBasePane::OnSize(CBasePane *this, unsigned int nType, unsigned int cx, int cy)
{
  CWnd::Default(this);
  if ( this->m_pDockBarRow != nullptr )
    this->m_pDockBarRow->OnResizePane(this: this->m_pDockBarRow, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x103E1905
// Name: public: virtual class CWnd __near * CBasePane::GetDockSiteFrameWnd(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWnd *__thiscall CBasePane::GetDockSiteFrameWnd(CBasePane *this)
{
  HWND Parent; // eax
  CWnd *v3; // eax
  HWND v4; // eax
  CWnd *v5; // eax
  CWnd *m_hWnd; // esi
  CWnd *MainWnd; // eax

  if ( this->m_pDockSite == nullptr )
  {
    Parent = GetParent(hWnd: this->m_hWnd);
    v3 = CWnd::FromHandle(hWnd: Parent);
    if ( CObject::IsKindOf(this: v3, pClass: &CDialog::classCDialog) != 0 )
    {
      v4 = GetParent(hWnd: this->m_hWnd);
      v5 = CWnd::FromHandle(hWnd: v4);
      if ( v5 != nullptr )
        m_hWnd = (CWnd *)v5->m_hWnd;
      else
        m_hWnd = nullptr;
      MainWnd = AfxGetMainWnd();
      if ( MainWnd != nullptr )
        MainWnd = (CWnd *)MainWnd->m_hWnd;
      if ( m_hWnd == MainWnd )
        afxGlobalUtils.m_bDialogApp = 1;
    }
  }
  return this->m_pDockSite;
}

//------------------------------------------------------------------------------
// Address: 0x103E196E
// Name: public: class CMFCBaseTabCtrl __near * CBasePane::GetParentTabWnd(struct HWND__ __near * __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCBaseTabCtrl *__thiscall CBasePane::GetParentTabWnd(CBasePane *this, HWND__ **hWndTab)
{
  HWND__ **p_m_hWnd; // esi
  HWND Parent; // eax
  CWnd *v4; // eax
  CObject *v5; // eax
  HWND v6; // eax
  CWnd *v7; // eax
  CObject *v8; // ebx
  HWND v9; // eax
  CWnd *v10; // eax
  CObject *v11; // eax

  p_m_hWnd = &this->m_hWnd;
  Parent = GetParent(hWnd: this->m_hWnd);
  v4 = CWnd::FromHandle(hWnd: Parent);
  v5 = AfxDynamicDownCast(pClass: &CDockablePaneAdapter::classCDockablePaneAdapter, pObject: v4);
  if ( v5 != nullptr )
    p_m_hWnd = (HWND__ **)&v5[8];
  *hWndTab = *p_m_hWnd;
  v6 = GetParent(hWnd: *p_m_hWnd);
  v7 = CWnd::FromHandle(hWnd: v6);
  v8 = AfxDynamicDownCast(pClass: &CMFCBaseTabCtrl::classCMFCBaseTabCtrl, pObject: v7);
  if ( v8 != nullptr )
    return (CMFCBaseTabCtrl *)v8;
  v9 = GetParent(hWnd: *p_m_hWnd);
  v10 = CWnd::FromHandle(hWnd: v9);
  v11 = AfxDynamicDownCast(pClass: &CBaseTabbedPane::classCBaseTabbedPane, pObject: v10);
  if ( v11 == nullptr )
    return (CMFCBaseTabCtrl *)v8;
  else
    return ((CMFCBaseTabCtrl *(__thiscall *)(CObject *))v11->__vftable[77].Serialize)(a1: v11);
}

//------------------------------------------------------------------------------
// Address: 0x103E19F1
// Name: public: class CBaseTabbedPane __near * CBasePane::GetParentTabbedPane(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseTabbedPane *__thiscall CBasePane::GetParentTabbedPane(CBasePane *this)
{
  CMFCBaseTabCtrl *ParentTabWnd; // eax
  HWND Parent; // eax
  CWnd *v4; // eax
  HWND__ *hWndTab; // [esp+4h] [ebp-4h] BYREF

  hWndTab = nullptr;
  if ( this->IsTabbed(this) == 0 )
    return nullptr;
  ParentTabWnd = CBasePane::GetParentTabWnd(this, &hWndTab);
  if ( hWndTab == nullptr || ParentTabWnd == nullptr )
    return nullptr;
  Parent = GetParent(hWnd: ParentTabWnd->m_hWnd);
  v4 = CWnd::FromHandle(hWnd: Parent);
  return (CBaseTabbedPane *)AfxDynamicDownCast(pClass: &CBaseTabbedPane::classCBaseTabbedPane, pObject: v4);
}

//------------------------------------------------------------------------------
// Address: 0x103E1A42
// Name: protected: long CBasePane::OnSetIcon(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CBasePane::OnSetIcon(CBasePane *this, unsigned int __formal, int a3)
{
  CMFCBaseTabCtrl *ParentTabWnd; // esi
  int v5; // ebx
  LRESULT v6; // eax
  int lres; // [esp+4h] [ebp-8h]
  HWND__ *hWndTab; // [esp+8h] [ebp-4h] BYREF

  lres = CWnd::Default(this);
  if ( this->IsTabbed(this) != 0 )
  {
    hWndTab = nullptr;
    ParentTabWnd = CBasePane::GetParentTabWnd(this, &hWndTab);
    v5 = ParentTabWnd->GetTabFromHwnd(this: ParentTabWnd, a2: hWndTab);
    if ( v5 >= 0 && v5 < ParentTabWnd->GetTabsNum(this: ParentTabWnd) )
    {
      v6 = SendMessageA(hWnd: this->m_hWnd, Msg: 0x7Fu, wParam: 0, lParam: 0);
      ParentTabWnd->SetTabHicon(this: ParentTabWnd, a2: v5, a3: (HICON__ *)v6);
    }
  }
  return lres;
}

//------------------------------------------------------------------------------
// Address: 0x103E1ABB
// Name: public: virtual void CBasePane::OnPaneContextMenu(class CWnd __near *,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CBasePane::OnPaneContextMenu(CBasePane *this, CWnd *pParentFrame, CPoint point)
{
  HWND__ *m_hWnd; // eax
  CFrameWnd *ParentFrame; // eax
  CDockingManager *DockingManager; // eax

  if ( this != nullptr )
    m_hWnd = this->m_hWnd;
  else
    m_hWnd = nullptr;
  if ( SendMessageA(
         hWnd: pParentFrame->m_hWnd,
         Msg: AFX_WM_TOOLBARMENU,
         wParam: (WPARAM)m_hWnd,
         lParam: LOWORD(point.x) | (LOWORD(point.y) << 16)) != 0 )
  {
    ParentFrame = CWnd::GetParentFrame(this);
    DockingManager = CGlobalUtils::GetDockingManager(this: &afxGlobalUtils, pWnd: ParentFrame);
    if ( DockingManager != nullptr )
      CDockingManager::OnPaneContextMenu(this: DockingManager, point);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103E1B1B
// Name: public: virtual long CBasePane::get_accParent(struct IDispatch __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CBasePane::get_accParent(CBasePane *this, IDispatch **ppdispParent)
{
  int v2; // edi
  HWND Parent; // eax
  CWnd *v4; // eax

  v2 = -2147024809;
  if ( ppdispParent != nullptr )
  {
    Parent = GetParent(hWnd: this->m_hWnd);
    v4 = CWnd::FromHandle(hWnd: Parent);
    if ( v4 != nullptr )
    {
      AccessibleObjectFromWindow(
        hwnd: v4->m_hWnd,
        dwId: 0xFFFFFFFC,
        riid: &IID_IAccessible,
        ppvObject: (void **)ppdispParent);
      return *ppdispParent == nullptr;
    }
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x103E1B63
// Name: public: virtual long CBasePane::accLocation(long __near *,long __near *,long __near *,long __near *,struct tagVARIANT)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CBasePane::accLocation(
        CBasePane *this,
        int *pxLeft,
        int *pyTop,
        int *pcxWidth,
        int *pcyHeight,
        tagVARIANT varChild)
{
  int left; // eax
  int top; // ecx
  int right; // edx
  CRect rc; // [esp+14h] [ebp-14h] BYREF

  if ( pxLeft == nullptr || pyTop == nullptr || pcxWidth == nullptr || pcyHeight == nullptr )
    return -2147024809;
  if ( varChild.vt == 3 )
  {
    if ( varChild.decVal.Lo32 != 0 )
    {
      if ( varChild.lVal > 0 )
      {
        this->OnSetAccData(this, a2: varChild.decVal.Lo32);
        *pxLeft = this->m_AccData.m_rectAccLocation.left;
        *pyTop = this->m_AccData.m_rectAccLocation.top;
        *pcxWidth = this->m_AccData.m_rectAccLocation.right - this->m_AccData.m_rectAccLocation.left;
        *pcyHeight = this->m_AccData.m_rectAccLocation.bottom - this->m_AccData.m_rectAccLocation.top;
      }
    }
    else
    {
      memset(&rc, 0, sizeof(rc));
      GetWindowRect(hWnd: this->m_hWnd, lpRect: &rc);
      left = rc.left;
      top = rc.top;
      right = rc.right;
      *pxLeft = rc.left;
      *pyTop = top;
      *pcxWidth = right - left;
      *pcyHeight = rc.bottom - top;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103E1C4E
// Name: protected: long CBasePane::OnPrintClient(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CBasePane::OnPrintClient(CBasePane *this, HDC__ *wp, char lp)
{
  CDC *v4; // eax

  if ( (lp & 8) != 0 )
    SendMessageA(hWnd: this->m_hWnd, Msg: 0x14u, wParam: (WPARAM)wp, lParam: 0);
  if ( (lp & 4) != 0 )
  {
    v4 = CDC::FromHandle(hDC: wp);
    this->DoPaint(this, a2: v4);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103E1C8C
// Name: public: virtual int CBasePane::IsVisible(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CBasePane::IsVisible(CBasePane *this)
{
  int result; // eax
  CMFCBaseTabCtrl *ParentTabWnd; // esi
  int v4; // edi
  HWND__ *hWndTab; // [esp+4h] [ebp-4h] BYREF

  if ( this->IsTabbed(this) != 0 )
  {
    hWndTab = nullptr;
    ParentTabWnd = CBasePane::GetParentTabWnd(this, &hWndTab);
    result = IsWindowVisible(hWnd: ParentTabWnd->m_hWnd);
    if ( result != 0 )
    {
      v4 = ParentTabWnd->GetTabFromHwnd(this: ParentTabWnd, a2: hWndTab);
      if ( v4 < 0 || v4 >= ParentTabWnd->GetTabsNum(this: ParentTabWnd) )
        return 0;
      else
        return ParentTabWnd->IsTabVisible(this: ParentTabWnd, a2: v4);
    }
  }
  else if ( CDockingManager::m_bRestoringDockState != 0 )
  {
    return ((int (__fastcall *)(CBasePane *))this->GetRecentVisibleState)(a1: this);
  }
  else
  {
    return (CWnd::GetStyle(this) & 0x10000000) != 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103E1D13
// Name: public: virtual void CBasePane::ShowPane(int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CBasePane::ShowPane(CBasePane *this, int bShow, int bDelay, int bActivate)
{
  int v5; // edi
  HWND v6; // eax
  CWnd *v7; // eax
  CWnd *v8; // ebx
  CMFCBaseTabCtrl *ParentTabWnd; // edi
  HWND Parent; // eax
  CWnd *v11; // eax
  CWnd *v12; // eax
  CWnd *v13; // ebx
  int v14; // eax
  CDockingPanesRow *m_pDockBarRow; // esi
  HWND__ *hWndTab; // [esp+Ch] [ebp-4h] BYREF

  v5 = bShow != 0 ? 4 : 0;
  if ( this->IsFloating(this) == 0 || this->IsTabbed(this) != 0 )
  {
    if ( this->m_pParentDockBar != nullptr )
    {
      this->m_pParentDockBar->ShowPane(this: this->m_pParentDockBar, a2: this, a3: bShow, a4: bDelay, a5: bActivate);
    }
    else if ( this->IsTabbed(this) != 0 )
    {
      ParentTabWnd = CBasePane::GetParentTabWnd(this, &hWndTab);
      Parent = GetParent(hWnd: ParentTabWnd->m_hWnd);
      v11 = CWnd::FromHandle(hWnd: Parent);
      v12 = (CWnd *)AfxDynamicDownCast(pClass: &CBaseTabbedPane::classCBaseTabbedPane, pObject: v11);
      v13 = v12;
      if ( v12 != nullptr )
      {
        if ( (CWnd::GetStyle(this: v12) & 0x10000000) == 0
          && ((int (__thiscall *)(CWnd *))v13->__vftable[2].put_accValue)(a1: v13) > 1
          && bShow != 0 )
        {
          ((void (__thiscall *)(CWnd *, CBasePane *, int, int, int))v13->__vftable[2].EndModalState)(
            a1: v13,
            a2: this,
            a3: 1,
            a4: bDelay,
            a5: bActivate);
          return;
        }
        ((void (__thiscall *)(CWnd *, CBasePane *, int, int, int))v13->__vftable[2].EndModalState)(
          a1: v13,
          a2: this,
          a3: bShow,
          a4: bDelay,
          a5: bActivate);
        if ( ParentTabWnd->GetVisibleTabsNum(this: ParentTabWnd) == 0 )
          ((void (__thiscall *)(CWnd *, int, int, int))v13->__vftable[1].get_accKeyboardShortcut)(
            a1: v13,
            a2: bShow,
            a3: bDelay,
            a4: bActivate);
      }
      else
      {
        v14 = ParentTabWnd->GetTabFromHwnd(this: ParentTabWnd, a2: this->m_hWnd);
        ParentTabWnd->ShowTab(this: ParentTabWnd, a2: v14, a3: bShow, a4: bDelay == 0, a5: 0);
      }
    }
    else
    {
      CWnd::ShowWindow(this, nCmdShow: v5);
      if ( bDelay == 0 )
        this->AdjustDockingLayout(this, a2: nullptr);
    }
  }
  else
  {
    CWnd::ShowWindow(this, nCmdShow: v5);
    v6 = GetParent(hWnd: this->m_hWnd);
    v7 = CWnd::FromHandle(hWnd: v6);
    v8 = v7;
    if ( bDelay == 0 || bShow == 0 )
      CWnd::ShowWindow(this: v7, nCmdShow: v5);
    PostMessageA(hWnd: v8->m_hWnd, Msg: AFX_WM_CHECKEMPTYMINIFRAME, wParam: 0, lParam: 0);
  }
  m_pDockBarRow = this->m_pDockBarRow;
  if ( m_pDockBarRow != nullptr )
    CDockingPanesRow::FixupVirtualRects(this: m_pDockBarRow, bMoveBackToVirtualRect: false, pBarToExclude: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x103E1EBF
// Name: protected: long CBasePane::OnIdleUpdateCmdUI(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CBasePane::OnIdleUpdateCmdUI(CBasePane *this, unsigned int wParam, int __formal)
{
  CDockSite *m_pParentDockBar; // ecx
  CFrameWnd *Owner; // edi

  if ( (CWnd::GetStyle(this) & 0x10000000) != 0 )
  {
    m_pParentDockBar = this->m_pParentDockBar;
    if ( m_pParentDockBar == nullptr || (CWnd::GetStyle(this: m_pParentDockBar) & 0x10000000) != 0 )
    {
      Owner = (CFrameWnd *)CWnd::GetOwner(this);
      if ( Owner == nullptr || Owner->IsFrameWnd(this: Owner) == 0 )
        Owner = AFXGetParentFrame(pWnd: this);
      if ( Owner != nullptr )
        this->OnUpdateCmdUI(this, a2: Owner, a3: wParam);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103E4BF6
// Name: public: virtual int CMFCToolBarComboBoxButton::IsWindowVisible(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCToolBarComboBoxButton::IsWindowVisible(CMFCToolBarComboBoxButton *this)
{
  CComboBox *m_pWndCombo; // ecx
  CEdit *m_pWndEdit; // ecx
  BOOL result; // eax

  m_pWndCombo = this->m_pWndCombo;
  result = true;
  if ( m_pWndCombo == nullptr || m_pWndCombo->m_hWnd == nullptr || (CWnd::GetStyle(this: m_pWndCombo) & 0x10000000) == 0 )
  {
    m_pWndEdit = this->m_pWndEdit;
    if ( m_pWndEdit == nullptr || m_pWndEdit->m_hWnd == nullptr || (CWnd::GetStyle(this: m_pWndEdit) & 0x10000000) == 0 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103E4C3D
// Name: public: virtual int CMFCToolBarComboBoxButton::IsOwnerOf(struct HWND__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCToolBarComboBoxButton::IsOwnerOf(CMFCToolBarComboBoxButton *this, HWND hwnd)
{
  CComboBox *m_pWndCombo; // eax
  BOOL result; // eax
  CEdit *m_pWndEdit; // eax

  m_pWndCombo = this->m_pWndCombo;
  result = true;
  if ( m_pWndCombo == nullptr
    || m_pWndCombo->m_hWnd == nullptr
    || m_pWndCombo->m_hWnd != hwnd && !IsChild(hWndParent: m_pWndCombo->m_hWnd, hWnd: hwnd) )
  {
    m_pWndEdit = this->m_pWndEdit;
    if ( m_pWndEdit == nullptr
      || m_pWndEdit->m_hWnd == nullptr
      || m_pWndEdit->m_hWnd != hwnd && !IsChild(hWndParent: m_pWndEdit->m_hWnd, hWnd: hwnd) )
    {
      return false;
    }
  }
  return result;
}
