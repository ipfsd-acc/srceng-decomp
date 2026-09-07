// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/texturebar.cpp
// Functions: 17
// ============================================================

#include "hammer\texturebar.h"

//------------------------------------------------------------------------------
// Address: 0x10100B00
// Name: void SetDefaultTextureName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetDefaultTextureName(const char *szTexName)
{
  strcpy(szDefaultTexture, szTexName);
}

//------------------------------------------------------------------------------
// Address: 0x10100B20
// Name: char const __near * GetDefaultTextureName(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetDefaultTextureName()
{
  return szDefaultTexture;
}

//------------------------------------------------------------------------------
// Address: 0x10100B30
// Name: char const __near * GetNullTextureName(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetNullTextureName()
{
  return szNullTexture;
}

//------------------------------------------------------------------------------
// Address: 0x10100B40
// Name: public: void CTextureBar::NotifyNewMaterial(class IEditorTexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBar::NotifyNewMaterial(CTextureBar *this, IEditorTexture *pTex)
{
  CTextureBox::NotifyNewMaterial(this: &this->m_TextureList, pTex);
}

//------------------------------------------------------------------------------
// Address: 0x10100B50
// Name: protected: void CTextureBar::UpdateControl(class CCmdUI __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBar::UpdateControl(CTextureBar *this, CCmdUI *pCmdUI)
{
  pCmdUI->Enable(this: pCmdUI, a2: CMapDoc::m_pMapDoc != nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10100B80
// Name: protected: void CTextureBar::OnChangeTextureGroup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBar::OnChangeTextureGroup(CTextureBar *this)
{
  WPARAM v2; // eax
  char szName[260]; // [esp+8h] [ebp-104h] BYREF

  v2 = SendMessageA(hWnd: this->m_TextureGroupList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  SendMessageA(hWnd: this->m_TextureGroupList.m_hWnd, Msg: 0x148u, wParam: v2, lParam: (LPARAM)szName);
  CTextureSystem::SetActiveGroup(this: &g_Textures, pcszName: szName);
  CTextureBox::LoadGraphicList(this: &this->m_TextureList);
}

//------------------------------------------------------------------------------
// Address: 0x10100BE0
// Name: public: void wndTex::SetTexture(class IEditorTexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall wndTex::SetTexture(wndTex *this, IEditorTexture *pTex)
{
  this->m_pTexture = pTex;
  InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
}

//------------------------------------------------------------------------------
// Address: 0x10100C00
// Name: protected: void wndTex::OnPaint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall wndTex::OnPaint(wndTex *this)
{
  HBRUSH StockObject; // eax
  IEditorTexture *m_pTexture; // ecx
  CPalette *p_GDIPalette; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-88h]
  CPaintDC dc; // [esp+8h] [ebp-78h] BYREF
  CRect r; // [esp+5Ch] [ebp-24h] BYREF
  DrawTexData_t DrawTexData; // [esp+6Ch] [ebp-14h] BYREF
  int v9; // [esp+7Ch] [ebp-4h]

  CPaintDC::CPaintDC(this: &dc, pWnd: this);
  v9 = 0;
  m_hWnd = this->m_hWnd;
  memset(&r, 0, sizeof(r));
  GetClientRect(hWnd: m_hWnd, lpRect: &r);
  if ( this->m_pTexture != nullptr )
  {
    this->m_pTexture->Load(this: this->m_pTexture);
    m_pTexture = this->m_pTexture;
    DrawTexData.nFlags = 2;
    if ( m_pTexture->HasPalette(this: m_pTexture) )
      p_GDIPalette = this->m_pTexture->GetPalette(this: this->m_pTexture);
    else
      p_GDIPalette = &g_pGameConfig->Palette.GDIPalette;
    CDC::SelectPalette(this: &dc, pPalette: p_GDIPalette, bForceBackground: false);
    RealizePalette(hdc: dc.m_hDC);
    this->m_pTexture->Draw(this: this->m_pTexture, a2: &dc, a3: &r, a4: 0, a5: 0, a6: &DrawTexData);
  }
  else
  {
    StockObject = (HBRUSH)GetStockObject(i: 4);
    FillRect(hDC: dc.m_hDC, lprc: &r, hbr: StockObject);
  }
  v9 = -1;
  CPaintDC::~CPaintDC(this: &dc);
}

//------------------------------------------------------------------------------
// Address: 0x10100CF0
// Name: protected: void CTextureBar::UpdateTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBar::UpdateTexture(CTextureBar *this)
{
  WPARAM v2; // eax
  IEditorTexture *v3; // eax
  IEditorTexture *m_pCurTex; // ecx
  IEditorTexture *v5; // edi
  int v6; // eax
  int v7; // eax
  CWnd *DlgItem; // eax
  HWND__ *m_hWnd; // [esp-Ch] [ebp-98h]
  int v10; // [esp-4h] [ebp-90h]
  char szBuf[132]; // [esp+8h] [ebp-84h] BYREF

  v2 = SendMessageA(hWnd: this->m_TextureList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v2 == -1 )
  {
    m_hWnd = this->m_TexturePic.m_hWnd;
    this->m_TexturePic.m_pTexture = nullptr;
    InvalidateRect(hWnd: m_hWnd, lpRect: nullptr, bErase: true);
    this->m_pCurTex = nullptr;
  }
  else
  {
    v3 = (IEditorTexture *)SendMessageA(hWnd: this->m_TextureList.m_hWnd, Msg: 0x150u, wParam: v2, lParam: 0);
    this->m_pCurTex = v3;
    this->m_TexturePic.m_pTexture = v3;
    InvalidateRect(hWnd: this->m_TexturePic.m_hWnd, lpRect: nullptr, bErase: true);
    m_pCurTex = this->m_pCurTex;
    if ( m_pCurTex != nullptr )
    {
      m_pCurTex->Load(this: m_pCurTex);
      v5 = this->m_pCurTex;
      v6 = v5->GetHeight(this: v5);
      v7 = ((int (__thiscall *)(IEditorTexture *, int))v5->GetWidth)(a1: v5, a2: v6);
      sprintf(string: szBuf, format: "%dx%d", v7, v10);
      DlgItem = CWnd::GetDlgItem(this, nID: 1027);
      CWnd::SetWindowTextA(this: DlgItem, lpszString: szBuf);
      this->m_pCurTex->GetShortName(this: this->m_pCurTex, a2: szDefaultTexture);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10100DF0
// Name: protected: void CTextureBar::OnBrowse(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBar::OnBrowse(CTextureBar *this)
{
  CTextureBrowser *pTextureBrowser; // edi
  WPARAM v3; // eax
  LRESULT v4; // eax
  WPARAM v5; // edi
  IEditorTexture *v6; // eax
  char sz[128]; // [esp+Ch] [ebp-88h] BYREF
  int iCount; // [esp+8Ch] [ebp-8h]
  IEditorTexture *pTex; // [esp+90h] [ebp-4h]

  pTextureBrowser = GetMainWnd()->pTextureBrowser;
  v3 = SendMessageA(hWnd: this->m_TextureList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  if ( v3 != -1 )
  {
    v4 = SendMessageA(hWnd: this->m_TextureList.m_hWnd, Msg: 0x150u, wParam: v3, lParam: 0);
    if ( v4 != 0 )
    {
      (*(void (__thiscall **)(LRESULT, char *))(*(_DWORD *)v4 + 36))(a1: v4, a2: sz);
      CTextureBrowser::SetInitialTexture(this: pTextureBrowser, pszTexture: sz);
    }
  }
  if ( pTextureBrowser->DoModal(this: pTextureBrowser) == 1 )
  {
    pTex = CTextureSystem::FindActiveTexture(
             this: &g_Textures,
             pszInputName: pTextureBrowser->m_cTextureWindow.szCurTexture,
             piIndex: nullptr,
             bDummy: 1);
    if ( pTex != nullptr )
    {
      v5 = 0;
      iCount = SendMessageA(hWnd: this->m_TextureList.m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0);
      if ( iCount > 0 )
      {
        while ( 1 )
        {
          v6 = (IEditorTexture *)SendMessageA(hWnd: this->m_TextureList.m_hWnd, Msg: 0x150u, wParam: v5, lParam: 0);
          if ( pTex == v6 )
            break;
          if ( (int)++v5 >= iCount )
            return;
        }
        SendMessageA(hWnd: this->m_TextureList.m_hWnd, Msg: 0x14Eu, wParam: v5, lParam: 0);
        CTextureBar::UpdateTexture(this);
        CTextureBox::AddMRU(this: &this->m_TextureList, pTex);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10100F00
// Name: protected: void CTextureBar::OnWindowPosChanged(struct tagWINDOWPOS __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBar::OnWindowPosChanged(CTextureBar *this, tagWINDOWPOS *pPos)
{
  if ( GetMainWnd() != nullptr && (pPos->flags & 0x40) != 0 )
  {
    CTextureBox::RebuildMRU(this: &this->m_TextureList);
    CTextureBar::UpdateTexture(this);
  }
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x10100F50
// Name: public: void CTextureBar::NotifyGraphicsChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBar::NotifyGraphicsChanged(CTextureBar *this)
{
  CAfxStringMgr *StringManager; // eax
  LRESULT v3; // eax
  int v4; // ebx
  TextureContext_t *m_pActiveContext; // eax
  int v6; // ecx
  CTextureGroup *v7; // ebx
  int v8; // eax
  LPARAM v9; // eax
  WPARAM v10; // eax
  char *v11; // eax
  char szName[260]; // [esp+4h] [ebp-120h] BYREF
  int iCurSel; // [esp+108h] [ebp-1Ch]
  int nCount; // [esp+10Ch] [ebp-18h]
  int i; // [esp+110h] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+114h] [ebp-10h] BYREF
  int v17; // [esp+120h] [ebp-4h]

  if ( IsWindow(hWnd: this->m_hWnd) )
  {
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    str.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
    v17 = 1;
    v3 = SendMessageA(hWnd: this->m_TextureGroupList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
    v4 = v3;
    iCurSel = v3;
    if ( v3 != -1 )
      CComboBox::GetLBText(this: &this->m_TextureGroupList, nIndex: v3, rString: &str);
    SendMessageA(hWnd: this->m_TextureGroupList.m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
    SendMessageA(hWnd: this->m_TextureGroupList.m_hWnd, Msg: 0x14Bu, wParam: 0, lParam: 0);
    SendMessageA(hWnd: this->m_TextureGroupList.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"All Textures");
    m_pActiveContext = g_Textures.m_pActiveContext;
    if ( g_Textures.m_pActiveContext != nullptr )
    {
      nCount = g_Textures.m_pActiveContext->Groups.m_Size;
      if ( nCount > 1 )
      {
        v6 = 1;
        i = 1;
        do
        {
          if ( m_pActiveContext != nullptr )
            v7 = m_pActiveContext->Groups.m_Memory.m_pMemory[v6];
          else
            v7 = nullptr;
          if ( v7->m_eTextureFormat == g_pGameConfig->textureformat )
          {
            strstr(str1: (unsigned __int8 *)v7, str2: "textures\\");
            if ( v8 != 0 )
              v9 = v8 + 9;
            else
              v9 = (LPARAM)v7;
            SendMessageA(hWnd: this->m_TextureGroupList.m_hWnd, Msg: 0x143u, wParam: 0, lParam: v9);
            v6 = i;
          }
          m_pActiveContext = g_Textures.m_pActiveContext;
          i = ++v6;
        }
        while ( v6 < nCount );
        v4 = iCurSel;
      }
    }
    SendMessageA(hWnd: this->m_TextureGroupList.m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
    if ( v4 == -1
      || SendMessageA(
           hWnd: this->m_TextureGroupList.m_hWnd,
           Msg: 0x14Du,
           wParam: 0xFFFFFFFF,
           lParam: (LPARAM)str.m_pszData) == -1 )
    {
      SendMessageA(hWnd: this->m_TextureGroupList.m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
    }
    InvalidateRect(hWnd: this->m_TextureGroupList.m_hWnd, lpRect: nullptr, bErase: true);
    v10 = SendMessageA(hWnd: this->m_TextureGroupList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
    SendMessageA(hWnd: this->m_TextureGroupList.m_hWnd, Msg: 0x148u, wParam: v10, lParam: (LPARAM)szName);
    CTextureSystem::SetActiveGroup(this: &g_Textures, pcszName: szName);
    CTextureBox::LoadGraphicList(this: &this->m_TextureList);
    CTextureBar::UpdateTexture(this);
    v17 = -1;
    v11 = str.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v11 + 4))(a1: v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10101180
// Name: protected: virtual void CTextureBar::OnSelChangeTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBar::OnSelChangeTexture(CTextureBar *this)
{
  CTextureBar::UpdateTexture(this);
  if ( this->m_pCurTex != nullptr )
    CTextureBox::AddMRU(this: &this->m_TextureList, pTex: this->m_pCurTex);
}

//------------------------------------------------------------------------------
// Address: 0x101011A0
// Name: protected: virtual struct AFX_MSGMAP const __near * wndTex::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall wndTex::GetMessageMap(wndTex *this)
{
  return (const AFX_MSGMAP *)&off_105F3F5C;
}

//------------------------------------------------------------------------------
// Address: 0x101011B0
// Name: public: int CTextureBar::Create(class CWnd __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTextureBar::Create(CTextureBar *this, CWnd *pParentWnd, unsigned __int16 IDD, unsigned int iBarID)
{
  int result; // eax

  this->m_pCurTex = nullptr;
  result = CHammerBar::Create(this, pParentWnd, nIDTemplate: IDD, nStyle: 0x4100u, nID: iBarID);
  if ( result != 0 )
  {
    CWnd::SetWindowTextA(this, lpszString: "Textures");
    CWnd::SubclassDlgItem(this: &this->m_TextureGroupList, nID: 0x486u, pParent: this);
    CWnd::SubclassDlgItem(this: &this->m_TextureList, nID: 0x3EFu, pParent: this);
    CWnd::SubclassDlgItem(this: &this->m_TexturePic, nID: 0x455u, pParent: this);
    CTextureBar::NotifyGraphicsChanged(this);
    CTextureBar::UpdateTexture(this);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10101240
// Name: protected: void CTextureBar::OnReplace(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureBar::OnReplace(CTextureBar *this)
{
  CMapDoc *v1; // esi
  int ActiveTool; // eax
  CHistory *History; // eax
  const CUtlReferenceVector<CMapClass> *List; // [esp-Ch] [ebp-2A8h]
  CReplaceTexDlg dlg; // [esp+4h] [ebp-298h] BYREF
  int v6; // [esp+298h] [ebp-4h]

  v1 = CMapDoc::m_pMapDoc;
  if ( CMapDoc::m_pMapDoc != nullptr )
  {
    ActiveTool = CToolManager::GetActiveTool(this: CMapDoc::m_pMapDoc->m_pSelection);
    CReplaceTexDlg::CReplaceTexDlg(this: &dlg, nSelected: ActiveTool, pParent: nullptr);
    v6 = 0;
    ATL::CSimpleStringT<char,0>::SetString(
      this: &dlg.m_strFind,
      pszSrc: szDefaultTexture,
      nLength: strlen(szDefaultTexture));
    if ( CDialog::DoModal(this: &dlg) == 1 )
    {
      List = CSelection::GetList(this: v1->m_pSelection);
      History = GetHistory();
      CHistory::MarkUndoPosition(this: History, pSelection: List, pszName: "Replace Textures", bFromOpposite: 0);
      CReplaceTexDlg::DoReplaceTextures(this: &dlg);
    }
    v6 = -1;
    CReplaceTexDlg::~CReplaceTexDlg(this: &dlg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10101310
// Name: protected: virtual struct AFX_MSGMAP const __near * CTextureBar::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CTextureBar::GetMessageMap(CTextureBar *this)
{
  return (const AFX_MSGMAP *)&off_105F3FA0;
}
