// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/replacetexdlg.cpp
// Functions: 11
// ============================================================

#include "hammer\replacetexdlg.h"

//------------------------------------------------------------------------------
// Address: 0x100F4580
// Name: protected: virtual void CReplaceTexDlg::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CReplaceTexDlg::DoDataExchange(CReplaceTexDlg *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x4E8, rControl: (HWND__ *)&this->m_cFind);
  DDX_Control(pDX, nIDC: (HWND__ *)0x4E9, rControl: (HWND__ *)&this->m_cReplace);
  DDX_Control(pDX, nIDC: (HWND__ *)0x4E3, rControl: (HWND__ *)&this->m_cReplacePic);
  DDX_Control(pDX, nIDC: (HWND__ *)0x4E2, rControl: (HWND__ *)&this->m_cFindPic);
  DDX_Radio((HWND__ *)pDX, nIDC: (HWND__ *)0x4A8, value: (HWND__ **)&this->m_iSearchAll);
  DDX_Text(pDX, nIDC: (HWND__ *)0x4E8, value: &this->m_strFind);
  DDX_Text(pDX, nIDC: (HWND__ *)0x4E9, value: &this->m_strReplace);
  DDX_Radio((HWND__ *)pDX, nIDC: (HWND__ *)0x4EC, value: (HWND__ **)&this->m_iAction);
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x508, value: &this->m_bMarkOnly);
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x546, value: &this->m_bHidden);
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x509, value: &this->m_bRescaleTextureCoordinates);
}

//------------------------------------------------------------------------------
// Address: 0x100F4660
// Name: public: void CReplaceTexDlg::DoReplaceTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CReplaceTexDlg::DoReplaceTextures(CReplaceTexDlg *this)
{
  if ( CMapDoc::m_pMapDoc != nullptr )
    CMapDoc::ReplaceTextures(
      this: CMapDoc::m_pMapDoc,
      pszFind: this->m_strFind.m_pszData,
      pszReplace: this->m_strReplace.m_pszData,
      bEverything: this->m_iSearchAll,
      iAction: this->m_iAction | (this->m_bMarkOnly != 0 ? 0x100 : 0),
      bHidden: this->m_bHidden,
      bRescaleTextureCoordinates: (const char *)(this->m_bRescaleTextureCoordinates != 0));
}

//------------------------------------------------------------------------------
// Address: 0x100F46C0
// Name: protected: void CReplaceTexDlg::BrowseTex(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CReplaceTexDlg::BrowseTex(CReplaceTexDlg *this, int iEdit)
{
  CAfxStringMgr *StringManager; // eax
  CWnd *DlgItem; // edi
  CTextureBrowser *v5; // esi
  CMainFrame *MainWnd; // eax
  CTextureBrowser *v7; // esi
  IEditorTexture *ActiveTexture; // eax
  char *v9; // eax
  char szName[260]; // [esp+8h] [ebp-114h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strTex; // [esp+10Ch] [ebp-10h] BYREF
  int v12; // [esp+118h] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  strTex.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v12 = 1;
  DlgItem = CWnd::GetDlgItem(this, nID: iEdit);
  CWnd::GetWindowTextA(this: DlgItem, rString: &strTex);
  v5 = (CTextureBrowser *)operator new(nSize: 0xD00u);
  LOBYTE(v12) = 2;
  if ( v5 != nullptr )
  {
    MainWnd = GetMainWnd();
    v7 = CTextureBrowser::CTextureBrowser(this: v5, pParent: MainWnd);
  }
  else
  {
    v7 = nullptr;
  }
  LOBYTE(v12) = 1;
  CTextureBrowser::SetUsed(this: v7, bUsed: iEdit == 1256);
  CTextureBrowser::SetInitialTexture(this: v7, pszTexture: strTex.m_pszData);
  if ( v7->DoModal(this: v7) == 1 )
  {
    ActiveTexture = CTextureSystem::FindActiveTexture(
                      this: &g_Textures,
                      pszInputName: v7->m_cTextureWindow.szCurTexture,
                      piIndex: nullptr,
                      bDummy: 1);
    if ( ActiveTexture != nullptr )
      ActiveTexture->GetShortName(this: ActiveTexture, a2: szName);
    else
      szName[0] = 0;
    CWnd::SetWindowTextA(this: DlgItem, lpszString: szName);
  }
  ((void (__thiscall *)(CTextureBrowser *, int))v7->dtr_CObject)(a1: v7, a2: 1);
  v12 = -1;
  v9 = strTex.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)strTex.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v9 + 4))(a1: v9);
}

//------------------------------------------------------------------------------
// Address: 0x100F4810
// Name: protected: void CReplaceTexDlg::OnBrowsereplace(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CReplaceTexDlg::OnBrowsereplace(CReplaceTexDlg *this)
{
  CReplaceTexDlg::BrowseTex(this, iEdit: 1257);
}

//------------------------------------------------------------------------------
// Address: 0x100F4820
// Name: protected: void CReplaceTexDlg::OnBrowsefind(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CReplaceTexDlg::OnBrowsefind(CReplaceTexDlg *this)
{
  CReplaceTexDlg::BrowseTex(this, iEdit: 1256);
}

//------------------------------------------------------------------------------
// Address: 0x100F4830
// Name: protected: void CReplaceTexDlg::OnUpdateFind(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CReplaceTexDlg::OnUpdateFind(CReplaceTexDlg *this)
{
  CAfxStringMgr *StringManager; // eax
  IEditorTexture *ActiveTexture; // eax
  char *v4; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strTex; // [esp+4h] [ebp-10h] BYREF
  int v6; // [esp+10h] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  strTex.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v6 = 1;
  CWnd::GetWindowTextA(this: &this->m_cFind, rString: &strTex);
  ActiveTexture = CTextureSystem::FindActiveTexture(
                    this: &g_Textures,
                    pszInputName: strTex.m_pszData,
                    piIndex: nullptr,
                    bDummy: 1);
  wndTex::SetTexture(this: &this->m_cFindPic, pTex: ActiveTexture);
  v6 = -1;
  v4 = strTex.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)strTex.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v4 + 4))(a1: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100F48E0
// Name: protected: void CReplaceTexDlg::OnUpdateReplace(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CReplaceTexDlg::OnUpdateReplace(CReplaceTexDlg *this)
{
  CAfxStringMgr *StringManager; // eax
  IEditorTexture *ActiveTexture; // eax
  char *v4; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strTex; // [esp+4h] [ebp-10h] BYREF
  int v6; // [esp+10h] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  strTex.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v6 = 1;
  CWnd::GetWindowTextA(this: &this->m_cReplace, rString: &strTex);
  ActiveTexture = CTextureSystem::FindActiveTexture(
                    this: &g_Textures,
                    pszInputName: strTex.m_pszData,
                    piIndex: nullptr,
                    bDummy: 1);
  wndTex::SetTexture(this: &this->m_cReplacePic, pTex: ActiveTexture);
  v6 = -1;
  v4 = strTex.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)strTex.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v4 + 4))(a1: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100F4990
// Name: protected: virtual int CReplaceTexDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CReplaceTexDlg::OnInitDialog(CReplaceTexDlg *this)
{
  CWnd *DlgItem; // eax

  CDialog::OnInitDialog(this);
  if ( this->m_nSelected == 0 )
  {
    DlgItem = CWnd::GetDlgItem(this, nID: 1192);
    CWnd::EnableWindow(this: DlgItem, bEnable: 0);
  }
  CReplaceTexDlg::OnUpdateFind(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F49D0
// Name: protected: virtual struct AFX_MSGMAP const __near * CReplaceTexDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CReplaceTexDlg::GetMessageMap(CReplaceTexDlg *this)
{
  return (const AFX_MSGMAP *)&off_105F1C50;
}

//------------------------------------------------------------------------------
// Address: 0x100F49E0
// Name: public: CReplaceTexDlg::CReplaceTexDlg(int,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CReplaceTexDlg *__thiscall CReplaceTexDlg::CReplaceTexDlg(CReplaceTexDlg *this, int nSelected, CWnd *pParent)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v5; // eax

  CDialog::CDialog(this, nIDTemplate: 0xD9u, pParentWnd: pParent);
  this->__vftable = (CReplaceTexDlg_vtbl *)&CReplaceTexDlg::`vftable';
  CWnd::CWnd(this: &this->m_cFind);
  this->m_cFind.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_cReplace);
  this->m_cReplace.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_cReplacePic);
  this->m_cReplacePic.__vftable = (wndTex_vtbl *)&CStatic::`vftable';
  this->m_cReplacePic.__vftable = (wndTex_vtbl *)&wndTex::`vftable';
  this->m_cReplacePic.m_pTexture = nullptr;
  CWnd::CWnd(this: &this->m_cFindPic);
  this->m_cFindPic.__vftable = (wndTex_vtbl *)&CStatic::`vftable';
  this->m_cFindPic.__vftable = (wndTex_vtbl *)&wndTex::`vftable';
  this->m_cFindPic.m_pTexture = nullptr;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strFind.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v5 = AfxGetStringManager();
  if ( v5 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strReplace.m_pszData = (char *)&v5->GetNilString(this: v5)[1];
  this->m_iSearchAll = nSelected == 0;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strFind, pszSrc: &var, nLength: 0);
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strReplace, pszSrc: &var, nLength: 0);
  this->m_iAction = 0;
  this->m_bMarkOnly = 0;
  this->m_bHidden = 0;
  this->m_bRescaleTextureCoordinates = 0;
  this->m_nSelected = nSelected;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F4BC0
// Name: void CopyElements<struct CCOMMAND>(struct CCOMMAND __near *,struct CCOMMAND const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CopyElements<CCOMMAND>(CCOMMAND *pDest, const CCOMMAND *pSrc, int nCount)
{
  int v3; // ebx
  CCOMMAND *v4; // eax
  const CCOMMAND *v5; // edx
  const CCOMMAND *v6; // esi
  CCOMMAND *v7; // edi

  v3 = nCount;
  if ( nCount != 0 )
  {
    v4 = pDest;
    if ( pDest == nullptr || (v5 = pSrc, pSrc == nullptr) )
      AfxThrowInvalidArgException();
    do
    {
      v6 = v5;
      v7 = v4;
      ++v5;
      ++v4;
      --v3;
      qmemcpy(v7, v6, sizeof(CCOMMAND));
    }
    while ( v3 != 0 );
  }
}
