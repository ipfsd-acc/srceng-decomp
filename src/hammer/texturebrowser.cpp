// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/texturebrowser.cpp
// Functions: 31
// ============================================================

#include "hammer\texturebrowser.h"

//------------------------------------------------------------------------------
// Address: 0x10101320
// Name: public: void CTextureBrowser::SetInitialTexture(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBrowser::SetInitialTexture(CTextureBrowser *this, const char *pszTexture)
{
  const char *v2; // eax
  int v3; // edx
  char v4; // cl

  v2 = pszTexture;
  v3 = this->szInitialTexture - pszTexture;
  do
  {
    v4 = *v2;
    v2[v3] = *v2;
    ++v2;
  }
  while ( v4 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x10101340
// Name: protected: void CTextureBrowser::OnChangeFilterOrKeywords(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBrowser::OnChangeFilterOrKeywords(CTextureBrowser *this)
{
  this->m_uLastFilterChange = _time64(timeptr: nullptr);
  this->m_bFilterChanged = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10101360
// Name: public: void CTextureBrowser::SetFilter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBrowser::SetFilter(CTextureBrowser *this, const char *pszFilter)
{
  const char *v2; // eax
  int v3; // edx
  char v4; // cl

  v2 = pszFilter;
  if ( pszFilter != nullptr )
  {
    v3 = this->m_szNameFilter - pszFilter;
    do
    {
      v4 = *v2;
      v2[v3] = *v2;
      ++v2;
    }
    while ( v4 != 0 );
  }
  else
  {
    this->m_szNameFilter[0] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10101390
// Name: protected: void CTextureBrowser::OnOpenSource(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBrowser::OnOpenSource(CTextureBrowser *this)
{
  if ( this->m_cTextureWindow.szCurTexture[0] != 0 )
    CTextureSystem::OpenSource(this: &g_Textures, pMaterialName: this->m_cTextureWindow.szCurTexture);
}

//------------------------------------------------------------------------------
// Address: 0x101013B0
// Name: protected: void CTextureBrowser::OnExploreToSource(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBrowser::OnExploreToSource(CTextureBrowser *this)
{
  if ( this->m_cTextureWindow.szCurTexture[0] != 0 )
    CTextureSystem::ExploreToSource(this: &g_Textures, pMaterialName: this->m_cTextureWindow.szCurTexture);
}

//------------------------------------------------------------------------------
// Address: 0x101013D0
// Name: protected: void CTextureBrowser::OnMark(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBrowser::OnMark(CTextureBrowser *this)
{
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    CMapDoc::ReplaceTextures(
      this: CMapDoc::m_pMapDoc,
      pszFind: this->m_cTextureWindow.szCurTexture,
      pszReplace: &var,
      bEverything: 1,
      iAction: 0x100u,
      bHidden: 0,
      bRescaleTextureCoordinates: nullptr);
    CDialog::EndDialog(this, nResult: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10101410
// Name: public: void CTextureBrowser::SetTextureFormat(enum TEXTUREFORMAT)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBrowser::SetTextureFormat(CTextureBrowser *this, TEXTUREFORMAT eTextureFormat)
{
  CTextureWindow::SetTextureFormat(this: &this->m_cTextureWindow, eTextureFormat);
}

//------------------------------------------------------------------------------
// Address: 0x10101420
// Name: protected: void CTextureBrowser::OnSize(unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBrowser::OnSize(CTextureBrowser *this, int nType, int cx, int cy)
{
  CWnd *DlgItem; // eax
  int v6; // edi
  int v7; // eax
  CWnd *v8; // eax
  CWnd *v9; // ebx
  int v10; // eax
  CWnd *v11; // eax
  CWnd *v12; // ebx
  int v13; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-60h]
  int v15; // [esp+4h] [ebp-4Ch]
  int iIDList2[10]; // [esp+8h] [ebp-48h]
  CRect clientrect; // [esp+30h] [ebp-20h] BYREF
  CRect CtrlRect; // [esp+40h] [ebp-10h] BYREF
  int i; // [esp+58h] [ebp+8h]
  int ia; // [esp+58h] [ebp+8h]

  if ( nType == 1 || !IsWindow(hWnd: this->m_cTextureWindow.m_hWnd) )
  {
    CWnd::Default(this);
  }
  else
  {
    m_hWnd = this->m_hWnd;
    memset(&clientrect, 0, sizeof(clientrect));
    GetClientRect(hWnd: m_hWnd, lpRect: &clientrect);
    memset(&CtrlRect, 0, sizeof(CtrlRect));
    DlgItem = CWnd::GetDlgItem(this, nID: 1010);
    GetWindowRect(hWnd: DlgItem->m_hWnd, lpRect: &CtrlRect);
    v6 = CtrlRect.bottom - CtrlRect.top;
    *(_QWORD *)&CtrlRect.left = *(_QWORD *)&clientrect.left;
    CtrlRect.right = _mm_loadl_epi64((const __m128i *)&clientrect.right).m128i_u32[0];
    CtrlRect.bottom = clientrect.bottom - v6;
    CWnd::MoveWindow(
      this: &this->m_cTextureWindow,
      x: clientrect.left,
      y: clientrect.top,
      nWidth: CtrlRect.right - clientrect.left,
      nHeight: clientrect.bottom - v6 - clientrect.top,
      bRepaint: true);
    clientrect.top = clientrect.bottom - v6 + 4;
    v7 = 1027;
    v15 = 1027;
    iIDList2[0] = 1265;
    iIDList2[1] = 1266;
    iIDList2[2] = 1269;
    iIDList2[3] = 1267;
    iIDList2[4] = 1528;
    iIDList2[5] = 1530;
    iIDList2[6] = 1532;
    iIDList2[7] = 1305;
    iIDList2[8] = 1681;
    iIDList2[9] = -1;
    i = 0;
    do
    {
      v8 = CWnd::GetDlgItem(this, nID: v7);
      v9 = v8;
      if ( v8 != nullptr )
      {
        GetWindowRect(hWnd: v8->m_hWnd, lpRect: &CtrlRect);
        CWnd::ScreenToClient(this, lpRect: (tagPOINT *)&CtrlRect);
        CtrlRect.bottom = clientrect.top + CtrlRect.bottom - CtrlRect.top;
        CtrlRect.top = clientrect.top;
        CWnd::MoveWindow(
          this: v9,
          x: CtrlRect.left,
          y: clientrect.top,
          nWidth: CtrlRect.right - CtrlRect.left,
          nHeight: CtrlRect.bottom - clientrect.top,
          bRepaint: true);
      }
      v7 = iIDList2[i++];
    }
    while ( v7 != -1 );
    v10 = 1487;
    iIDList2[0] = 1487;
    iIDList2[1] = 1007;
    iIDList2[2] = 1289;
    iIDList2[3] = 1303;
    iIDList2[4] = 1257;
    iIDList2[5] = 1268;
    iIDList2[6] = 1529;
    iIDList2[7] = 1531;
    iIDList2[8] = 1304;
    iIDList2[9] = -1;
    ia = 0;
    do
    {
      v11 = CWnd::GetDlgItem(this, nID: v10);
      v12 = v11;
      if ( v11 != nullptr )
      {
        GetWindowRect(hWnd: v11->m_hWnd, lpRect: &CtrlRect);
        CWnd::ScreenToClient(this, lpRect: (tagPOINT *)&CtrlRect);
        v13 = v6 / 2 + clientrect.top + 2;
        CtrlRect.bottom = v13 + CtrlRect.bottom - CtrlRect.top;
        CtrlRect.top = v13;
        CWnd::MoveWindow(
          this: v12,
          x: CtrlRect.left,
          y: v13,
          nWidth: CtrlRect.right - CtrlRect.left,
          nHeight: CtrlRect.bottom - v13,
          bRepaint: true);
      }
      v10 = iIDList2[++ia];
    }
    while ( v10 != -1 );
    CWnd::Default(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10101660
// Name: protected: void CTextureBrowser::OnSelendokTexturesize(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTextureBrowser::OnSelendokTexturesize(CTextureBrowser *this@<ecx>, int a2@<edi>)
{
  LRESULT v3; // eax
  int v4; // eax

  v3 = SendMessageA(hWnd: this->m_cSizeList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v3 != 0 )
  {
    v4 = v3 - 1;
    if ( v4 != 0 )
    {
      if ( v4 == 1 )
        CTextureWindow::SetDisplaySize(this: &this->m_cTextureWindow, a2, iSize: 512);
    }
    else
    {
      CTextureWindow::SetDisplaySize(this: &this->m_cTextureWindow, a2, iSize: 256);
    }
  }
  else
  {
    CTextureWindow::SetDisplaySize(this: &this->m_cTextureWindow, a2, iSize: 128);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101016C0
// Name: protected: void CTextureBrowser::OnFilterOpaque(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTextureBrowser::OnFilterOpaque(CTextureBrowser *this@<ecx>, int a2@<edi>)
{
  bool checked; // [esp+4h] [ebp-4h]

  checked = SendMessageA(hWnd: this->m_FilterOpaque.m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0) != 0;
  CTextureWindow::SetTypeFilter(this: &this->m_cTextureWindow, a2, filter: 1, enable: checked);
}

//------------------------------------------------------------------------------
// Address: 0x10101700
// Name: protected: void CTextureBrowser::OnFilterTranslucent(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTextureBrowser::OnFilterTranslucent(CTextureBrowser *this@<ecx>, int a2@<edi>)
{
  bool checked; // [esp+4h] [ebp-4h]

  checked = SendMessageA(hWnd: this->m_FilterTranslucent.m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0) != 0;
  CTextureWindow::SetTypeFilter(this: &this->m_cTextureWindow, a2, filter: 2, enable: checked);
}

//------------------------------------------------------------------------------
// Address: 0x10101740
// Name: protected: void CTextureBrowser::OnFilterSelfIllum(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTextureBrowser::OnFilterSelfIllum(CTextureBrowser *this@<ecx>, int a2@<edi>)
{
  bool checked; // [esp+4h] [ebp-4h]

  checked = SendMessageA(hWnd: this->m_FilterSelfIllum.m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0) != 0;
  CTextureWindow::SetTypeFilter(this: &this->m_cTextureWindow, a2, filter: 4, enable: checked);
}

//------------------------------------------------------------------------------
// Address: 0x10101780
// Name: protected: void CTextureBrowser::OnFilterEnvmask(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTextureBrowser::OnFilterEnvmask(CTextureBrowser *this@<ecx>, int a2@<edi>)
{
  bool checked; // [esp+4h] [ebp-4h]

  checked = SendMessageA(hWnd: this->m_FilterEnvMask.m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0) != 0;
  CTextureWindow::SetTypeFilter(this: &this->m_cTextureWindow, a2, filter: 8, enable: checked);
}

//------------------------------------------------------------------------------
// Address: 0x101017C0
// Name: protected: void CTextureBrowser::OnShowErrors(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBrowser::OnShowErrors(CTextureBrowser *this)
{
  SendMessageA(hWnd: this->m_ShowErrors.m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0);
  this->m_cTextureWindow.m_bShowErrors = true;
}

//------------------------------------------------------------------------------
// Address: 0x101017F0
// Name: protected: void CTextureBrowser::OnReload(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBrowser::OnReload(CTextureBrowser *this)
{
  CMainFrame *MainWnd; // eax
  CMainFrame *v3; // eax

  if ( this->m_cTextureWindow.szCurTexture[0] != 0 )
  {
    CTextureSystem::ReloadTextures(this: &g_Textures, pFilterName: this->m_cTextureWindow.szCurTexture);
    InvalidateRect(hWnd: this->m_cTextureWindow.m_hWnd, lpRect: nullptr, bErase: true);
    if ( GetMainWnd() != nullptr )
    {
      MainWnd = GetMainWnd();
      CTextureBar::NotifyGraphicsChanged(this: &MainWnd->m_TextureBar);
      v3 = GetMainWnd();
      CFaceEditMaterialPage::NotifyGraphicsChanged(this: &v3->m_pFaceEditSheet->m_MaterialPage);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10101850
// Name: protected: void CTextureBrowser::OnUpdateFiltersNOW(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTextureBrowser::OnUpdateFiltersNOW(CTextureBrowser *this@<ecx>, int a2@<edi>)
{
  CAfxStringMgr *StringManager; // eax
  WPARAM v4; // eax
  char *v5; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+4h] [ebp-10h] BYREF
  int v7; // [esp+10h] [ebp-4h]

  this->m_uLastFilterChange = _time64(timeptr: nullptr);
  this->m_bFilterChanged = 0;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  str.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v7 = 1;
  v4 = SendMessageA(hWnd: this->m_cFilter.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  CComboBox::GetLBText(this: &this->m_cFilter, nIndex: v4, rString: &str);
  CTextureWindow::SetNameFilter(this: &this->m_cTextureWindow, a2, pszFilter: str.m_pszData);
  v7 = -1;
  v5 = str.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v5 + 4))(a1: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10101920
// Name: protected: void CTextureBrowser::OnUpdateKeywordsNOW(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTextureBrowser::OnUpdateKeywordsNOW(CTextureBrowser *this@<ecx>, int a2@<edi>)
{
  CAfxStringMgr *StringManager; // eax
  WPARAM v4; // eax
  char *v5; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+4h] [ebp-10h] BYREF
  int v7; // [esp+10h] [ebp-4h]

  this->m_uLastFilterChange = _time64(timeptr: nullptr);
  this->m_bFilterChanged = 0;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  str.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v7 = 1;
  v4 = SendMessageA(hWnd: this->m_cKeywords.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  CComboBox::GetLBText(this: &this->m_cKeywords, nIndex: v4, rString: &str);
  CTextureWindow::SetKeywords(this: &this->m_cTextureWindow, a2, pszKeywords: str.m_pszData);
  v7 = -1;
  v5 = str.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v5 + 4))(a1: v5);
}

//------------------------------------------------------------------------------
// Address: 0x101019F0
// Name: protected: void CTextureBrowser::OnTimer(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBrowser::OnTimer(CTextureBrowser *this, const char *nIDEvent)
{
  __int64 v3; // rax
  bool v4; // of
  __int64 v5; // rax
  UINT_PTR v6; // ebx
  CAfxStringMgr *StringManager; // eax
  const char *v8; // eax

  if ( this->m_bFilterChanged != 0 )
  {
    v3 = _time64(timeptr: nullptr);
    v4 = __OFSUB__(v3, this->m_uLastFilterChange);
    v5 = v3 - this->m_uLastFilterChange;
    if ( v5 >= 0 && (!((v5 < 0) ^ v4 | (HIDWORD(v5) == 0)) || (_DWORD)v5 != 0) )
    {
      v6 = (UINT_PTR)nIDEvent;
      KillTimer(hWnd: this->m_hWnd, uIDEvent: (UINT_PTR)nIDEvent);
      this->m_bFilterChanged = 0;
      CTextureWindow::EnableUpdate(this: &this->m_cTextureWindow, bEnable: false);
      StringManager = AfxGetStringManager();
      if ( StringManager == nullptr )
        ATL::AtlThrowImpl(hr: -2147467259);
      nIDEvent = (const char *)&StringManager->GetNilString(this: StringManager)[1];
      CWnd::GetWindowTextA(
        this: &this->m_cFilter,
        rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&nIDEvent);
      CTextureWindow::SetNameFilter(this: &this->m_cTextureWindow, a2: 0, pszFilter: nIDEvent);
      CTextureWindow::EnableUpdate(this: &this->m_cTextureWindow, bEnable: true);
      CWnd::GetWindowTextA(
        this: &this->m_cKeywords,
        rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&nIDEvent);
      CTextureWindow::SetKeywords(this: &this->m_cTextureWindow, a2: 0, pszKeywords: nIDEvent);
      SetTimer(hWnd: this->m_hWnd, nIDEvent: v6, uElapse: 0x1F4u, lpTimerFunc: nullptr);
      v8 = nIDEvent - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)nIDEvent - 1) <= 0 )
        (*(void (__stdcall **)(const char *))(**(_DWORD **)v8 + 4))(a1: v8);
    }
    CWnd::Default(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10101B30
// Name: public: void CTextureBrowser::SaveAndExit(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10101C70
// Name: public: CTextureBrowser::CTextureBrowser(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CTextureBrowser *__thiscall CTextureBrowser::CTextureBrowser(CTextureBrowser *this, CWnd *pParent)
{
  TextureWindowTex_t *m_pMemory; // ecx

  CDialog::CDialog(this, nIDTemplate: 0x91u, pParentWnd: pParent);
  this->__vftable = (CTextureBrowser_vtbl *)&CTextureBrowser::`vftable';
  CTextureWindow::CTextureWindow(this: &this->m_cTextureWindow);
  CWnd::CWnd(this: &this->m_cSizeList);
  this->m_cSizeList.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  CWnd::CWnd(this: &this->m_cCurName);
  this->m_cCurName.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_cCurDescription);
  this->m_cCurDescription.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_cUsed);
  this->m_cUsed.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CAutoSelComboBox::CAutoSelComboBox(this: &this->m_cFilter);
  CAutoSelComboBox::CAutoSelComboBox(this: &this->m_cKeywords);
  CWnd::CWnd(this: &this->m_FilterOpaque);
  this->m_FilterOpaque.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_FilterTranslucent);
  this->m_FilterTranslucent.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_FilterSelfIllum);
  this->m_FilterSelfIllum.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_FilterEnvMask);
  this->m_FilterEnvMask.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_ShowErrors);
  this->m_ShowErrors.__vftable = (CButton_vtbl *)&CButton::`vftable';
  this->m_TextureSubList.m_Memory.m_pMemory = nullptr;
  this->m_TextureSubList.m_Memory.m_nAllocationCount = 0;
  this->m_TextureSubList.m_Memory.m_nGrowSize = 0;
  m_pMemory = this->m_TextureSubList.m_Memory.m_pMemory;
  this->m_TextureSubList.m_Size = 0;
  this->m_TextureSubList.m_pElements = m_pMemory;
  this->m_szNameFilter[0] = 0;
  this->szInitialTexture[0] = 0;
  this->m_bFilterChanged = 0;
  this->m_uLastFilterChange = -1;
  this->m_bUsed = 0;
  CTextureBrowser::m_szLastKeywords[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10101E80
// Name: public: void CTextureBrowser::SetUsed(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBrowser::SetUsed(CTextureBrowser *this, int bUsed)
{
  CTextureBrowser *v2; // edi
  int v3; // ebx
  CMapWorld *ActiveWorld; // eax
  CUtlMemory<CDispPaintMgr::DispVertPair_t,int> *p_m_TextureSubList; // esi
  IEditorTexture *pTex; // edx
  CDispPaintMgr::DispVertPair_t *m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDispPaintMgr::DispVertPair_t *v9; // ecx
  int v10; // eax
  TextureWindowTex_t *v11; // eax
  UsedTexture_t *v12; // eax
  CUsedTextureList Used; // [esp+8h] [ebp-2Ch] BYREF
  TextureWindowTex_t Tex; // [esp+1Ch] [ebp-18h]
  CTextureBrowser *v15; // [esp+24h] [ebp-10h]
  int v16; // [esp+30h] [ebp-4h]

  v2 = this;
  v3 = 0;
  v15 = this;
  this->m_bUsed = bUsed;
  if ( bUsed != 0 )
  {
    memset(&Used, 0, sizeof(Used));
    v16 = 2;
    ActiveWorld = GetActiveWorld();
    CMapWorld::GetUsedTextures(this: ActiveWorld, List: &Used);
    p_m_TextureSubList = (CUtlMemory<CDispPaintMgr::DispVertPair_t,int> *)&v2->m_TextureSubList;
    v2->m_TextureSubList.m_Size = 0;
    if ( Used.m_Size > 0 )
    {
      do
      {
        pTex = Used.m_Memory.m_pMemory[v3].pTex;
        m_pMemory = p_m_TextureSubList[1].m_pMemory;
        Tex.nUsageCount = Used.m_Memory.m_pMemory[v3].nUsageCount;
        m_nAllocationCount = p_m_TextureSubList->m_nAllocationCount;
        Tex.pTex = pTex;
        if ( (int)&m_pMemory->m_hDisp + 1 > m_nAllocationCount )
          CUtlMemory<UsedTexture_t,int>::Grow(
            this: p_m_TextureSubList,
            num: (int)&m_pMemory->m_hDisp - m_nAllocationCount + 1);
        ++p_m_TextureSubList[1].m_pMemory;
        v9 = p_m_TextureSubList->m_pMemory;
        v10 = (char *)p_m_TextureSubList[1].m_pMemory - (char *)m_pMemory - 1;
        p_m_TextureSubList[1].m_nAllocationCount = (int)p_m_TextureSubList->m_pMemory;
        if ( v10 > 0 )
          _V_memmove(dest: &v9[(int)m_pMemory + 1], src: &v9[(_DWORD)m_pMemory], count: 8 * v10);
        v11 = (TextureWindowTex_t *)&p_m_TextureSubList->m_pMemory[(_DWORD)m_pMemory];
        if ( v11 != nullptr )
          *v11 = Tex;
        ++v3;
      }
      while ( v3 < Used.m_Size );
      v2 = v15;
    }
    CTextureWindow::SetSpecificList(
      this: &v2->m_cTextureWindow,
      a2: (int)v2,
      pList: (TextureWindowTexList *)p_m_TextureSubList);
    v16 = 4;
    v12 = Used.m_Memory.m_pMemory;
    Used.m_Size = 0;
    if ( Used.m_Memory.m_nGrowSize >= 0 )
    {
      if ( Used.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: Used.m_Memory.m_pMemory);
        v12 = nullptr;
        Used.m_Memory.m_pMemory = nullptr;
      }
      Used.m_Memory.m_nAllocationCount = 0;
    }
    Used.m_pElements = v12;
    v16 = -1;
    if ( Used.m_Memory.m_nGrowSize >= 0 )
    {
      if ( Used.m_Memory.m_pMemory != nullptr )
      {
        free(pMem: Used.m_Memory.m_pMemory);
        Used.m_Memory.m_pMemory = nullptr;
      }
      Used.m_Memory.m_nAllocationCount = 0;
    }
  }
  else
  {
    CTextureWindow::SetSpecificList(this: &this->m_cTextureWindow, a2: (int)this, pList: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10101FF0
// Name: protected: void CTextureBrowser::OnUsed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBrowser::OnUsed(CTextureBrowser *this)
{
  LRESULT v2; // eax

  if ( GetActiveWorld() != nullptr )
  {
    v2 = SendMessageA(hWnd: this->m_cUsed.m_hWnd, Msg: 0xF0u, wParam: 0, lParam: 0);
    CTextureBrowser::SetUsed(this, bUsed: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10102020
// Name: protected: virtual int CTextureBrowser::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTextureBrowser::OnInitDialog(CTextureBrowser *this)
{
  CWnd *DlgItem; // eax
  int i; // ebx
  int j; // ebx
  const char *Keyword; // eax
  CWinApp *m_pCurrentWinApp; // ebx
  WPARAM v7; // eax
  LRESULT v8; // eax
  int v9; // eax
  char *v10; // eax
  tagRECT r; // [esp+Ch] [ebp-34h] BYREF
  int x; // [esp+1Ch] [ebp-24h] BYREF
  int y; // [esp+20h] [ebp-20h] BYREF
  int v15; // [esp+24h] [ebp-1Ch] BYREF
  int v16; // [esp+28h] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+2Ch] [ebp-14h] BYREF
  CWnd *p_m_cFilter; // [esp+30h] [ebp-10h]
  int v19; // [esp+3Ch] [ebp-4h]

  CDialog::OnInitDialog(this);
  CWnd::SubclassDlgItem(this: &this->m_cSizeList, nID: 0x403u, pParent: this);
  p_m_cFilter = &this->m_cFilter;
  CAutoSelComboBox::SubclassDlgItem(this: &this->m_cFilter, nID: 0x4F5u, pParent: this);
  CAutoSelComboBox::SubclassDlgItem(this: &this->m_cKeywords, nID: 0x3EFu, pParent: this);
  CWnd::SubclassDlgItem(this: &this->m_cCurName, nID: 0x4F3u, pParent: this);
  CWnd::SubclassDlgItem(this: &this->m_cCurDescription, nID: 0x4F4u, pParent: this);
  CWnd::SubclassDlgItem(this: &this->m_cUsed, nID: 0x509u, pParent: this);
  CWnd::SubclassDlgItem(this: &this->m_FilterOpaque, nID: 0x5F8u, pParent: this);
  CWnd::SubclassDlgItem(this: &this->m_FilterTranslucent, nID: 0x5F9u, pParent: this);
  CWnd::SubclassDlgItem(this: &this->m_FilterSelfIllum, nID: 0x5FAu, pParent: this);
  CWnd::SubclassDlgItem(this: &this->m_FilterEnvMask, nID: 0x5FBu, pParent: this);
  CWnd::SubclassDlgItem(this: &this->m_ShowErrors, nID: 0x5FCu, pParent: this);
  SendMessageA(hWnd: this->m_FilterOpaque.m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
  SendMessageA(hWnd: this->m_FilterTranslucent.m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
  SendMessageA(hWnd: this->m_FilterSelfIllum.m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
  SendMessageA(hWnd: this->m_FilterEnvMask.m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
  SendMessageA(hWnd: this->m_ShowErrors.m_hWnd, Msg: 0xF1u, wParam: 1u, lParam: 0);
  DlgItem = CWnd::GetDlgItem(this, nID: 1028);
  GetClientRect(hWnd: DlgItem->m_hWnd, lpRect: &r);
  CTextureWindow::Create(this: &this->m_cTextureWindow, a2: (int)SendMessageA, pParentWnd: this, rect: &r);
  CTextureWindow::SetTypeFilter(this: &this->m_cTextureWindow, a2: (int)SendMessageA, filter: -1, enable: true);
  for ( i = 0; i < CTextureBrowser::m_nFilterHistory; ++i )
  {
    if ( i < 0 || i >= CTextureBrowser::m_FilterHistory.m_nSize )
      AfxThrowInvalidArgException();
    SendMessageA(
      hWnd: this->m_cFilter.m_hWnd,
      Msg: 0x143u,
      wParam: 0,
      lParam: (LPARAM)CTextureBrowser::m_FilterHistory.m_pData[i].m_pszData);
  }
  if ( this->m_szNameFilter[0] == 0 && SendMessageA(hWnd: this->m_cFilter.m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0) > 0 )
  {
    SendMessageA(hWnd: this->m_cFilter.m_hWnd, Msg: 0x148u, wParam: 0, lParam: (LPARAM)this->m_szNameFilter);
    SendMessageA(hWnd: this->m_cFilter.m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
  }
  CWnd::SetWindowTextA(this: p_m_cFilter, lpszString: this->m_szNameFilter);
  CTextureWindow::SetNameFilter(this: &this->m_cTextureWindow, a2: (int)SendMessageA, pszFilter: this->m_szNameFilter);
  this->m_szNameFilter[0] = 0;
  for ( j = 0; j < CTextureSystem::GetNumKeywords(this: &g_Textures); ++j )
  {
    Keyword = CTextureSystem::GetKeyword(this: &g_Textures, pos: j);
    SendMessageA(hWnd: this->m_cKeywords.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)Keyword);
  }
  CWnd::SetWindowTextA(this: &this->m_cKeywords, lpszString: CTextureBrowser::m_szLastKeywords);
  CTextureWindow::SetKeywords(
    this: &this->m_cTextureWindow,
    a2: (int)SendMessageA,
    pszKeywords: CTextureBrowser::m_szLastKeywords);
  SendMessageA(hWnd: this->m_cUsed.m_hWnd, Msg: 0xF1u, wParam: this->m_bUsed, lParam: 0);
  if ( this->m_bUsed != 0 )
    CTextureBrowser::SetUsed(this, bUsed: 1);
  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  m_pCurrentWinApp->GetProfileStringA(
    this: m_pCurrentWinApp,
    result: &str,
    a3: pszIniSection_2,
    a4: "Position",
    a5: nullptr);
  v19 = 0;
  if ( *((_DWORD *)str.m_pszData - 3) != 0 )
  {
    x = 0;
    y = 0;
    v15 = 0;
    v16 = 0;
    sscanf(string: str.m_pszData, format: "%d %d %d %d", &x, &y, &v15, &v16);
    if ( x >= 0 )
      CWnd::MoveWindow(this, x, y, nWidth: v15 - x, nHeight: v16 - y, bRepaint: false);
    else
      CWnd::ShowWindow(this, nCmdShow: 3);
  }
  v7 = m_pCurrentWinApp->GetProfileIntA(this: m_pCurrentWinApp, a2: pszIniSection_2, a3: "ShowSize", a4: 0);
  SendMessageA(hWnd: this->m_cSizeList.m_hWnd, Msg: 0x14Eu, wParam: v7, lParam: 0);
  v8 = SendMessageA(hWnd: this->m_cSizeList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v8 != 0 )
  {
    v9 = v8 - 1;
    if ( v9 != 0 )
    {
      if ( v9 == 1 )
        CTextureWindow::SetDisplaySize(this: &this->m_cTextureWindow, a2: (int)SendMessageA, iSize: 512);
    }
    else
    {
      CTextureWindow::SetDisplaySize(this: &this->m_cTextureWindow, a2: (int)SendMessageA, iSize: 256);
    }
  }
  else
  {
    CTextureWindow::SetDisplaySize(this: &this->m_cTextureWindow, a2: (int)SendMessageA, iSize: 128);
  }
  if ( this->szInitialTexture[0] != 0 )
    CTextureWindow::SelectTexture(
      this: &this->m_cTextureWindow,
      pszTexture: (IEditorTexture *)this->szInitialTexture,
      bAllowRedraw: 1);
  CWnd::ShowWindow(this: &this->m_cTextureWindow, nCmdShow: 5);
  SetTimer(hWnd: this->m_hWnd, nIDEvent: 1u, uElapse: 0x1F4u, lpTimerFunc: nullptr);
  CWnd::SetFocus(this: p_m_cFilter);
  v19 = -1;
  v10 = str.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v10 + 4))(a1: v10);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10102440
// Name: protected: long CTextureBrowser::OnTexturewindowSelchange(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTextureBrowser::OnTexturewindowSelchange(CTextureBrowser *this, unsigned int wParam, int lParam)
{
  IEditorTexture *ActiveTexture; // esi
  CAfxStringMgr *StringManager; // eax
  char *m_pszData; // ebx
  int v7; // eax
  int v8; // eax
  int v10; // [esp-4h] [ebp-124h]
  char szName[260]; // [esp+Ch] [ebp-114h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+110h] [ebp-10h] BYREF
  int v13; // [esp+11Ch] [ebp-4h]

  ActiveTexture = CTextureSystem::FindActiveTexture(
                    this: &g_Textures,
                    pszInputName: this->m_cTextureWindow.szCurTexture,
                    piIndex: nullptr,
                    bDummy: 1);
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  str.m_pszData = m_pszData;
  v13 = 1;
  if ( ActiveTexture != nullptr )
  {
    v7 = ActiveTexture->GetHeight(this: ActiveTexture);
    v8 = ((int (__thiscall *)(IEditorTexture *, int))ActiveTexture->GetWidth)(a1: ActiveTexture, a2: v7);
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(this: &str, pszFormat: "%dx%d", v8, v10);
    ActiveTexture->GetShortName(this: ActiveTexture, a2: szName);
    m_pszData = str.m_pszData;
  }
  else
  {
    szName[0] = 0;
  }
  CWnd::SetWindowTextA(this: &this->m_cCurName, lpszString: szName);
  CWnd::SetWindowTextA(this: &this->m_cCurDescription, lpszString: m_pszData);
  v13 = -1;
  if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
    (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
      a1: *((_DWORD *)m_pszData - 4),
      a2: m_pszData - 16);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10102550
// Name: public: void CTextureBrowser::WriteSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBrowser::WriteSettings(CTextureBrowser *this)
{
  CWinApp *m_pCurrentWinApp; // esi
  CAfxStringMgr *StringManager; // eax
  char *m_pszData; // ebx
  LRESULT v5; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-34h]
  CRect r; // [esp+Ch] [ebp-20h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+1Ch] [ebp-10h] BYREF
  int v9; // [esp+28h] [ebp-4h]

  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  str.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v9 = 1;
  m_hWnd = this->m_hWnd;
  memset(&r, 0, sizeof(r));
  GetWindowRect(hWnd: m_hWnd, lpRect: &r);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
    this: &str,
    pszFormat: "%d %d %d %d",
    r.left,
    r.top,
    r.right,
    r.bottom);
  m_pszData = str.m_pszData;
  m_pCurrentWinApp->WriteProfileStringA(this: m_pCurrentWinApp, a2: pszIniSection_2, a3: "Position", a4: str.m_pszData);
  v5 = SendMessageA(hWnd: this->m_cSizeList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  m_pCurrentWinApp->WriteProfileInt(this: m_pCurrentWinApp, a2: pszIniSection_2, a3: "ShowSize", a4: v5);
  v9 = -1;
  if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
    (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
      a1: *((_DWORD *)m_pszData - 4),
      a2: m_pszData - 16);
}

//------------------------------------------------------------------------------
// Address: 0x10102670
// Name: protected: void CTextureBrowser::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBrowser::OnClose(CTextureBrowser *this)
{
  CTextureBrowser::WriteSettings(this);
  CTextureBrowser::SaveAndExit(this);
  CDialog::OnCancel(this);
}

//------------------------------------------------------------------------------
// Address: 0x10102690
// Name: protected: long CTextureBrowser::OnTextureWindowDblClk(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTextureBrowser::OnTextureWindowDblClk(CTextureBrowser *this, unsigned int wParam, unsigned int lParam)
{
  CTextureBrowser::WriteSettings(this);
  CTextureBrowser::SaveAndExit(this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101026B0
// Name: protected: void CTextureBrowser::OnReplace(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBrowser::OnReplace(CTextureBrowser *this)
{
  CMapDoc *v1; // esi
  int ActiveTool; // eax
  int v4; // eax
  CHistory *History; // eax
  const CUtlReferenceVector<CMapClass> *List; // [esp-Ch] [ebp-2ACh]
  CReplaceTexDlg dlg; // [esp+8h] [ebp-298h] BYREF
  int v8; // [esp+29Ch] [ebp-4h]

  v1 = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    ActiveTool = CToolManager::GetActiveTool(this: CMapDoc::m_pMapDoc->m_pSelection);
    CReplaceTexDlg::CReplaceTexDlg(this: &dlg, nSelected: ActiveTool, pParent: nullptr);
    v8 = 0;
    if ( this == (CTextureBrowser *)-264 )
      v4 = 0;
    else
      v4 = strlen(this->m_cTextureWindow.szCurTexture);
    ATL::CSimpleStringT<char,0>::SetString(
      this: &dlg.m_strFind,
      pszSrc: this->m_cTextureWindow.szCurTexture,
      nLength: v4);
    if ( CDialog::DoModal(this: &dlg) == 1 )
    {
      List = CSelection::GetList(this: v1->m_pSelection);
      History = GetHistory();
      CHistory::MarkUndoPosition(this: History, pSelection: List, pszName: "Replace Textures", bFromOpposite: 0);
      if ( dlg.m_bMarkOnly != 0 )
        CMapDoc::SelectObject(this: v1, pObj: nullptr, cmd: 16);
      CReplaceTexDlg::DoReplaceTextures(this: &dlg);
      if ( this->m_bUsed != 0 )
        CTextureBrowser::SetUsed(this, bUsed: 1);
    }
    v8 = -1;
    CReplaceTexDlg::~CReplaceTexDlg(this: &dlg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101027B0
// Name: protected: virtual struct AFX_MSGMAP const __near * CTextureBrowser::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CTextureBrowser::GetMessageMap(CTextureBrowser *this)
{
  return (const AFX_MSGMAP *)&off_105F4248;
}

//------------------------------------------------------------------------------
// Address: 0x105C12B0
// Name: _dynamic_initializer_for__CTextureBrowser::m_FilterHistory__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CTextureBrowser::m_FilterHistory__()
{
  CStringArray::CStringArray(this: &CTextureBrowser::m_FilterHistory);
  return atexit(func: dynamic_atexit_destructor_for__CTextureBrowser::m_FilterHistory__);
}

//------------------------------------------------------------------------------
// Address: 0x105CB250
// Name: _dynamic_atexit_destructor_for__CTextureBrowser::m_FilterHistory__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CTextureBrowser::m_FilterHistory__()
{
  CStringArray::~CStringArray(this: &CTextureBrowser::m_FilterHistory);
}
