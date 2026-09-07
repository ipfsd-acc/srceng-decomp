// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/opttextures.cpp
// Functions: 49
// ============================================================

#include "hammer\opttextures.h"

//------------------------------------------------------------------------------
// Address: 0x100EFFA0
// Name: wchar_t __near * AtlA2WHelper(wchar_t __near *,char const __near *,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__stdcall AtlA2WHelper(wchar_t *lpw, const char *lpa, int nChars, UINT acp)
{
  if ( lpw == nullptr || lpa == nullptr )
    return nullptr;
  *lpw = 0;
  return MultiByteToWideChar(
           CodePage: acp,
           dwFlags: 0,
           lpMultiByteStr: lpa,
           cbMultiByte: -1,
           lpWideCharStr: lpw,
           cchWideChar: nChars) != 0
       ? lpw
       : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100EFFE0
// Name: public: virtual struct CRuntimeClass __near * COPTTextures::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall COPTTextures::GetRuntimeClass(COPTTextures *this)
{
  return &COPTTextures::classCOPTTextures;
}

//------------------------------------------------------------------------------
// Address: 0x100EFFF0
// Name: public: virtual COPTTextures::~COPTTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTTextures::~COPTTextures(COPTTextures *this)
{
  this->__vftable = (COPTTextures_vtbl *)&COPTTextures::`vftable';
  CWnd::Detach(this: &this->m_MaterialExcludeList);
  CListBox::~CListBox(this: &this->m_MaterialExcludeList);
  CSliderCtrl::~CSliderCtrl(this: &this->m_cBrightness);
  CListBox::~CListBox(this: &this->m_TextureFiles);
  CPropertyPage::~CPropertyPage(this);
}

//------------------------------------------------------------------------------
// Address: 0x100F0080
// Name: protected: void COPTTextures::OnHScroll(unsigned int,unsigned int,class CScrollBar __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTTextures::OnHScroll(
        COPTTextures *this,
        unsigned int nSBCode,
        unsigned int nPos,
        CScrollBar *pScrollBar)
{
  if ( pScrollBar == (CScrollBar *)&this->m_cBrightness )
    CPropertyPage::SetModified(this, bChanged: 1);
  CWnd::OnHScroll(this, __formal: nSBCode, a3: nPos, pScrollBar);
}

//------------------------------------------------------------------------------
// Address: 0x100F00C0
// Name: BrowseCallbackProc
// Source: json
//------------------------------------------------------------------------------
int __stdcall BrowseCallbackProc(HWND__ *hwnd, unsigned int uMsg, int lParam, int lpData)
{
  if ( uMsg == 1 && lpData != 0 )
    SendMessageA(hWnd: hwnd, Msg: 0x466u, wParam: 1u, lParam: (LPARAM)s_szStartFolder);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100F00F0
// Name: public: COPTTextures::COPTTextures(void)
// Source: json
//------------------------------------------------------------------------------
COPTTextures *__thiscall COPTTextures::COPTTextures(COPTTextures *this)
{
  CPropertyPage::CPropertyPage(this, nIDTemplate: 0xF6u, nIDCaption: 0, dwSize: 0x38u);
  this->__vftable = (COPTTextures_vtbl *)&COPTTextures::`vftable';
  CWnd::CWnd(this: &this->m_TextureFiles);
  this->m_TextureFiles.__vftable = (CListBox_vtbl *)&CListBox::`vftable';
  CWnd::CWnd(this: &this->m_cBrightness);
  this->m_cBrightness.__vftable = (CSliderCtrl_vtbl *)&CSliderCtrl::`vftable';
  CWnd::CWnd(this: &this->m_MaterialExcludeList);
  this->m_MaterialExcludeList.__vftable = (CListBox_vtbl *)&CListBox::`vftable';
  this->m_pMaterialConfig = nullptr;
  this->m_bDeleted = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100F01F0
// Name: protected: virtual void COPTTextures::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTTextures::DoDataExchange(COPTTextures *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F2, rControl: (HWND__ *)&this->m_TextureFiles);
  DDX_Control(pDX, nIDC: (HWND__ *)0x487, rControl: (HWND__ *)&this->m_cBrightness);
}

//------------------------------------------------------------------------------
// Address: 0x100F0230
// Name: protected: virtual int COPTTextures::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100F02F0
// Name: protected: void COPTTextures::OnExtract(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTTextures::OnExtract(COPTTextures *this)
{
  int i; // esi

  SendMessageA(hWnd: this->m_TextureFiles.m_hWnd, Msg: 0x184u, wParam: 0, lParam: 0);
  for ( i = 0; i < Options.textures.nTextureFiles; ++i )
  {
    if ( i < 0 || i >= Options.textures.TextureFiles.m_nSize )
      AfxThrowInvalidArgException();
    SendMessageA(
      hWnd: this->m_TextureFiles.m_hWnd,
      Msg: 0x180u,
      wParam: 0,
      lParam: (LPARAM)Options.textures.TextureFiles.m_pData[i].m_pszData);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F0350
// Name: protected: void COPTTextures::OnRemovetexfile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTTextures::OnRemovetexfile(COPTTextures *this)
{
  signed int i; // esi

  for ( i = SendMessageA(hWnd: this->m_TextureFiles.m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0) - 1; i >= 0; --i )
  {
    if ( SendMessageA(hWnd: this->m_TextureFiles.m_hWnd, Msg: 0x187u, wParam: i, lParam: 0) != 0 )
      SendMessageA(hWnd: this->m_TextureFiles.m_hWnd, Msg: 0x182u, wParam: i, lParam: 0);
  }
  this->m_bDeleted = 1;
}

//------------------------------------------------------------------------------
// Address: 0x100F03B0
// Name: protected: void COPTTextures::OnAddtexfile2(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTTextures::OnAddtexfile2(COPTTextures *this)
{
  LPITEMIDLIST v2; // ebx
  int v3; // eax
  char v4; // cl
  char *v5; // eax
  char v6; // cl
  HANDLE FirstFileA; // ebx
  char *v8; // eax
  char szDisplayName[260]; // [esp+Ch] [ebp-470h] BYREF
  _WIN32_FIND_DATAA FindData; // [esp+110h] [ebp-36Ch] BYREF
  char szPathName[260]; // [esp+250h] [ebp-22Ch] BYREF
  char szNewPath[260]; // [esp+354h] [ebp-128h] BYREF
  _browseinfoA bi; // [esp+458h] [ebp-24h] BYREF
  _ITEMIDLIST *pidlNew; // [esp+478h] [ebp-4h]

  bi.hwndOwner = this->m_hWnd;
  bi.pidlRoot = nullptr;
  bi.pszDisplayName = szDisplayName;
  bi.lpszTitle = "Select your Quake II directory.";
  bi.ulFlags = 1;
  bi.lpfn = nullptr;
  bi.lParam = 0;
  v2 = SHBrowseForFolderA(lpbi: &bi);
  pidlNew = v2;
  if ( v2 != nullptr )
  {
    SHGetPathFromIDListA(pidl: v2, pszPath: szPathName);
    if ( AfxMessageBox(lpszText: "Add all subdirectories as separate Texture Groups?", nType: 4u, nIDHelp: 0) == 6 )
    {
      v3 = 0;
      do
      {
        v4 = szPathName[v3];
        szNewPath[v3++] = v4;
      }
      while ( v4 != 0 );
      v5 = &szPathName[259];
      do
        v6 = *++v5;
      while ( v6 != 0 );
      strcpy(v5, "\\*.*");
      FirstFileA = FindFirstFileA(lpFileName: szNewPath, lpFindFileData: &FindData);
      if ( FirstFileA != (HANDLE)-1 )
      {
        do
        {
          if ( (FindData.dwFileAttributes & 0x10) != 0 && FindData.cFileName[0] != 46 )
          {
            sprintf(string: szNewPath, format: "%s\\%s", szPathName, FindData.cFileName);
            strlwr(string: szNewPath);
            if ( SendMessageA(
                   hWnd: this->m_TextureFiles.m_hWnd,
                   Msg: 0x1A2u,
                   wParam: 0xFFFFFFFF,
                   lParam: (LPARAM)szNewPath) == -1 )
              SendMessageA(hWnd: this->m_TextureFiles.m_hWnd, Msg: 0x180u, wParam: 0, lParam: (LPARAM)szNewPath);
          }
        }
        while ( FindNextFileA(hFindFile: FirstFileA, lpFindFileData: &FindData) );
      }
      v2 = pidlNew;
    }
    else
    {
      strlwr(string: szPathName);
      if ( SendMessageA(hWnd: this->m_TextureFiles.m_hWnd, Msg: 0x1A2u, wParam: 0xFFFFFFFF, lParam: (LPARAM)szPathName) == -1 )
      {
        v8 = strlwr(string: szPathName);
        SendMessageA(hWnd: this->m_TextureFiles.m_hWnd, Msg: 0x180u, wParam: 0, lParam: (LPARAM)v8);
      }
    }
    CPropertyPage::SetModified(this, bChanged: 1);
    CoTaskMemFree(pv: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F0590
// Name: protected: int COPTTextures::BrowseForFolder(char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
LPITEMIDLIST __thiscall COPTTextures::BrowseForFolder(COPTTextures *this, char *pszTitle, char *pszDirectory)
{
  AFX_MODULE_STATE *ModuleState; // eax
  int v5; // esi
  wchar_t *v6; // eax
  void *v7; // esp
  HWND__ *m_hWnd; // ecx
  LPITEMIDLIST result; // eax
  void *v10; // esi
  wchar_t v11[4]; // [esp+0h] [ebp-13Ch] BYREF
  char szTmp[260]; // [esp+8h] [ebp-134h] BYREF
  unsigned int ulEaten; // [esp+10Ch] [ebp-30h] BYREF
  unsigned int ulAttributes; // [esp+110h] [ebp-2Ch] BYREF
  _browseinfoA bi; // [esp+114h] [ebp-28h] BYREF
  _ITEMIDLIST *pidlStartFolder; // [esp+134h] [ebp-8h] BYREF
  IShellFolder *pshDesktop; // [esp+138h] [ebp-4h] BYREF

  if ( s_bFirst )
  {
    ModuleState = AfxGetModuleState();
    CHammer::GetDirectory(this: (CHammer *)ModuleState->m_pCurrentWinApp, dir: DIR_MATERIALS, p: s_szStartFolder);
    s_bFirst = false;
  }
  pidlStartFolder = nullptr;
  pshDesktop = nullptr;
  SHGetDesktopFolder(ppshf: &pshDesktop);
  if ( pshDesktop != nullptr )
  {
    v5 = lstrlenA(lpString: s_szStartFolder) + 1;
    if ( v5 <= 0x3FFFFFFF )
    {
      v7 = alloca(2 * v5);
      v6 = AtlA2WHelper(lpw: v11, lpa: s_szStartFolder, nChars: v5, acp: 3u);
    }
    else
    {
      v6 = nullptr;
    }
    pshDesktop->ParseDisplayName(
      this: pshDesktop,
      a2: nullptr,
      a3: nullptr,
      a4: v6,
      a5: &ulEaten,
      a6: &pidlStartFolder,
      a7: &ulAttributes);
  }
  m_hWnd = this->m_hWnd;
  bi.pidlRoot = nullptr;
  bi.hwndOwner = m_hWnd;
  bi.lpszTitle = pszTitle;
  bi.iImage = 0;
  bi.pszDisplayName = szTmp;
  bi.ulFlags = 1;
  bi.lpfn = BrowseCallbackProc;
  bi.lParam = 1;
  result = SHBrowseForFolderA(lpbi: &bi);
  v10 = result;
  if ( result != nullptr )
  {
    SHGetPathFromIDListA(pidl: result, pszPath: pszDirectory);
    V_strncpy(pDest: s_szStartFolder, pSrc: pszDirectory, maxLen: 260);
    CoTaskMemFree(pv: pidlStartFolder);
    CoTaskMemFree(pv: v10);
    return (LPITEMIDLIST)1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F06D0
// Name: protected: void COPTTextures::OnMaterialExcludeListSel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTTextures::OnMaterialExcludeListSel(COPTTextures *this)
{
  WPARAM v2; // eax
  WPARAM v3; // edi
  CWnd *DlgItem; // eax
  BOOL v5; // [esp-4h] [ebp-114h]
  char szTmp[260]; // [esp+Ch] [ebp-104h] BYREF

  v2 = SendMessageA(hWnd: this->m_MaterialExcludeList.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  v3 = v2;
  if ( v2 != -1 )
  {
    SendMessageA(hWnd: this->m_MaterialExcludeList.m_hWnd, Msg: 0x189u, wParam: v2, lParam: (LPARAM)szTmp);
    v5 = SendMessageA(hWnd: this->m_MaterialExcludeList.m_hWnd, Msg: 0x199u, wParam: v3, lParam: 0) != 0;
    DlgItem = CWnd::GetDlgItem(this, nID: 1523);
    CWnd::EnableWindow(this: DlgItem, bEnable: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F0750
// Name: public: static class CObject __near * COPTTextures::CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
COPTTextures *__stdcall COPTTextures::CreateObject()
{
  COPTTextures *v0; // eax

  v0 = (COPTTextures *)operator new(nSize: 0x20Cu);
  if ( v0 != nullptr )
    return COPTTextures::COPTTextures(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100F07B0
// Name: protected: void COPTTextures::MaterialExcludeUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTTextures::MaterialExcludeUpdate(COPTTextures *this)
{
  CGameConfig *m_pMaterialConfig; // eax
  WPARAM v3; // edi
  GameData *v4; // eax
  FGDMatExlcusions_s *v5; // eax
  char *v6; // edx
  char v7; // cl
  char *v8; // eax
  char v9; // cl
  WPARAM v10; // edi
  char v11; // [esp+Bh] [ebp-10Dh] BYREF
  char szFolder[260]; // [esp+Ch] [ebp-10Ch] BYREF
  int i; // [esp+110h] [ebp-8h]
  unsigned int v14; // [esp+114h] [ebp-4h]

  SendMessageA(hWnd: this->m_MaterialExcludeList.m_hWnd, Msg: 0x184u, wParam: 0, lParam: 0);
  m_pMaterialConfig = this->m_pMaterialConfig;
  i = 0;
  if ( m_pMaterialConfig->m_MaterialExcludeCount <= 0 )
  {
LABEL_6:
    v4 = pGD;
    if ( pGD != nullptr )
    {
      i = 0;
      if ( pGD->m_FGDMaterialExclusions.m_Size > 0 )
      {
        v14 = 0;
        do
        {
          v5 = &v4->m_FGDMaterialExclusions.m_Memory.m_pMemory[v14 / 0x105];
          v6 = szFolder;
          do
          {
            v7 = v5->szDirectory[0];
            *v6 = v5->szDirectory[0];
            v5 = (FGDMatExlcusions_s *)((char *)v5 + 1);
            ++v6;
          }
          while ( v7 != 0 );
          v8 = &v11;
          do
            v9 = *++v8;
          while ( v9 != 0 );
          strcpy(v8, " (default)");
          v10 = SendMessageA(hWnd: this->m_MaterialExcludeList.m_hWnd, Msg: 0x180u, wParam: 0, lParam: (LPARAM)szFolder);
          SendMessageA(hWnd: this->m_MaterialExcludeList.m_hWnd, Msg: 0x19Au, wParam: v10, lParam: 0);
          if ( v10 == -1 )
            break;
          if ( v10 == -2 )
            break;
          v4 = pGD;
          v14 += 261;
          ++i;
        }
        while ( i < pGD->m_FGDMaterialExclusions.m_Size );
      }
    }
  }
  else
  {
    v14 = 0;
    while ( 1 )
    {
      v3 = SendMessageA(
             hWnd: this->m_MaterialExcludeList.m_hWnd,
             Msg: 0x180u,
             wParam: 0,
             lParam: (LPARAM)m_pMaterialConfig->m_MaterialExclusions.m_Memory.m_pMemory[v14 / 0x105].szDirectory);
      SendMessageA(hWnd: this->m_MaterialExcludeList.m_hWnd, Msg: 0x19Au, wParam: v3, lParam: 1);
      if ( v3 == -1 || v3 == -2 )
        break;
      m_pMaterialConfig = this->m_pMaterialConfig;
      v14 += 261;
      if ( ++i >= m_pMaterialConfig->m_MaterialExcludeCount )
        goto LABEL_6;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F0910
// Name: public: virtual int COPTTextures::OnApply(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COPTTextures::OnApply(COPTTextures *this)
{
  LRESULT v2; // edi
  CAfxStringMgr *StringManager; // eax
  signed int i; // esi
  int v5; // esi
  char *v6; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+Ch] [ebp-10h] BYREF
  int v9; // [esp+18h] [ebp-4h]

  Options.textures.fBrightness = (float)SendMessageA(
                                          hWnd: this->m_cBrightness.m_hWnd,
                                          Msg: 0x400u,
                                          wParam: 0,
                                          lParam: 0)
                               * 0.1;
  v2 = SendMessageA(hWnd: this->m_TextureFiles.m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0);
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  str.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v9 = 1;
  Options.textures.nTextureFiles = v2;
  CStringArray::SetSize(this: &Options.textures.TextureFiles, nNewSize: 0, nGrowBy: -1);
  for ( i = 0; i < v2; ++i )
  {
    CListBox::GetText(this: &this->m_TextureFiles, nIndex: i, rString: &str);
    CStringArray::SetAtGrow(
      this: &Options.textures.TextureFiles,
      nIndex: Options.textures.TextureFiles.m_nSize,
      newElement: (ATL::CStringData *)&str);
  }
  if ( this->m_bDeleted != 0 )
    CWnd::MessageBoxA(
      this,
      lpszText: "You have removed some texture files from the list. These texture files will continue to be used during this sessio"
      "n, but will not be loaded the next time you run Hammer.",
      lpszCaption: "A Quick Note",
      nType: 0);
  COptions::PerformChanges(this: &Options, dwOptionsChanged: 1);
  v5 = CPropertyPage::OnApply(this);
  v9 = -1;
  v6 = str.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v6 + 4))(a1: v6);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x100F0A60
// Name: public: virtual int COPTTextures::OnSetActive(void)
// Source: json
//------------------------------------------------------------------------------
CWnd *__thiscall COPTTextures::OnSetActive(COPTTextures *this)
{
  HWND Parent; // eax
  CWnd *result; // eax
  CGameConfig *m_pCtrlCont; // edi

  Parent = GetParent(hWnd: this->m_hWnd);
  result = CWnd::FromHandle(hWnd: Parent);
  if ( result != nullptr )
  {
    m_pCtrlCont = (CGameConfig *)result[53].m_pCtrlCont;
    if ( m_pCtrlCont != nullptr )
    {
      if ( this->m_pMaterialConfig != m_pCtrlCont )
      {
        this->m_pMaterialConfig = m_pCtrlCont;
        COPTTextures::MaterialExcludeUpdate(this);
        this->m_pMaterialConfig = m_pCtrlCont;
      }
      return (CWnd *)CPropertyPage::OnSetActive(this);
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F0AB0
// Name: protected: void COPTTextures::OnMaterialExcludeRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTTextures::OnMaterialExcludeRemove(COPTTextures *this)
{
  WPARAM v2; // eax
  WPARAM v3; // esi
  CGameConfig *m_pMaterialConfig; // esi
  int m_MaterialExcludeCount; // edi
  int v6; // ebx
  HWND__ *m_hWnd; // [esp-10h] [ebp-128h]
  char szTmp[260]; // [esp+Ch] [ebp-10Ch] BYREF
  COPTTextures *v9; // [esp+110h] [ebp-8h]
  unsigned int v10; // [esp+114h] [ebp-4h]

  m_hWnd = this->m_MaterialExcludeList.m_hWnd;
  v9 = this;
  v2 = SendMessageA(hWnd: m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  v3 = v2;
  if ( v2 != -1 )
  {
    SendMessageA(hWnd: this->m_MaterialExcludeList.m_hWnd, Msg: 0x189u, wParam: v2, lParam: (LPARAM)szTmp);
    if ( SendMessageA(hWnd: this->m_MaterialExcludeList.m_hWnd, Msg: 0x182u, wParam: v3, lParam: 0) != -1 )
    {
      m_pMaterialConfig = v9->m_pMaterialConfig;
      m_MaterialExcludeCount = m_pMaterialConfig->m_MaterialExcludeCount;
      v6 = 0;
      if ( m_MaterialExcludeCount > 0 )
      {
        v10 = 0;
        do
        {
          if ( strcmp(szTmp, m_pMaterialConfig->m_MaterialExclusions.m_Memory.m_pMemory[v10 / 0x105].szDirectory) == 0 )
          {
            if ( v6 != m_MaterialExcludeCount - 1 )
            {
              if ( m_pMaterialConfig->m_MaterialExclusions.m_Size - v6 - 1 > 0 )
                _V_memmove(
                  dest: &m_pMaterialConfig->m_MaterialExclusions.m_Memory.m_pMemory[v10 / 0x105],
                  src: &m_pMaterialConfig->m_MaterialExclusions.m_Memory.m_pMemory[v10 / 0x105 + 1],
                  count: 261 * (m_pMaterialConfig->m_MaterialExclusions.m_Size - v6 - 1));
              --m_pMaterialConfig->m_MaterialExclusions.m_Size;
            }
            --v9->m_pMaterialConfig->m_MaterialExcludeCount;
          }
          m_pMaterialConfig = v9->m_pMaterialConfig;
          m_MaterialExcludeCount = m_pMaterialConfig->m_MaterialExcludeCount;
          v10 += 261;
          ++v6;
        }
        while ( v6 < m_MaterialExcludeCount );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F0BD0
// Name: protected: void COPTTextures::OnAddtexfile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTTextures::OnAddtexfile(COPTTextures *this)
{
  COPTTextures *v1; // ebx
  CAfxStringMgr *StringManager; // eax
  char *v3; // esi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *NextPathName; // eax
  const char *m_pszData; // ecx
  ATL::CStringData *v6; // eax
  volatile signed __int32 *v7; // edi
  ATL::CStringData *v8; // ebx
  char *v9; // eax
  int v10; // edi
  int v11; // eax
  int v12; // eax
  CFileDialog dlg; // [esp+4h] [ebp-220h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > result; // [esp+208h] [ebp-1Ch] BYREF
  COPTTextures *v15; // [esp+20Ch] [ebp-18h]
  __POSITION *pos; // [esp+210h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+214h] [ebp-10h] BYREF
  int v18; // [esp+220h] [ebp-4h]

  v1 = this;
  v15 = this;
  CFileDialog::CFileDialog(
    this: &dlg,
    bOpenFileDialog: 1,
    lpszDefExt: "wad",
    lpszFileName: nullptr,
    dwFlags: 0x120Cu,
    lpszFilter: "Texture files (*.wad;*.pak)|*.wad; *.pak||",
    pParentWnd: nullptr,
    dwSize: 0,
    bVistaStyle: 1);
  v18 = 0;
  if ( szInitialDir_5[0] == 0 )
    V_snprintf(pDest: szInitialDir_5, maxLen: 260, pFormat: "%s\\wads\\", g_pGameConfig->m_szModDir);
  *(_DWORD *)(CMFCRibbonBaseElement::IsAlwaysLargeImage(this: (CMFCRibbonBaseElement *)&dlg) + 44) = szInitialDir_5;
  if ( CFileDialog::DoModal(this: &dlg) == 1 )
  {
    pos = *(__POSITION **)(CMFCRibbonBaseElement::IsAlwaysLargeImage(this: (CMFCRibbonBaseElement *)&dlg) + 28);
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    v3 = (char *)&StringManager->GetNilString(this: StringManager)[1];
    str.m_pszData = v3;
    LOBYTE(v18) = 2;
    if ( pos != nullptr )
    {
      while ( 2 )
      {
        NextPathName = CFileDialog::GetNextPathName(this: &dlg, &result, &pos);
        LOBYTE(v18) = 3;
        m_pszData = NextPathName->m_pszData;
        v6 = (ATL::CStringData *)(NextPathName->m_pszData - 16);
        v7 = (volatile signed __int32 *)(v3 - 16);
        if ( v6 != (ATL::CStringData *)(v3 - 16) )
        {
          if ( *((int *)v7 + 3) >= 0 && v6->pStringMgr == (ATL::IAtlStringMgr *)*v7 )
          {
            v8 = ATL::CSimpleStringT<char,0>::CloneData(pData: v6);
            if ( _InterlockedDecrement(v7 + 3) <= 0 )
              (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v7 + 4))(a1: v7);
            v3 = (char *)&v8[1];
            v1 = v15;
            str.m_pszData = v3;
          }
          else
          {
            ATL::CSimpleStringT<char,0>::SetString(this: &str, pszSrc: m_pszData, nLength: *((_DWORD *)m_pszData - 3));
            v3 = str.m_pszData;
          }
        }
        LOBYTE(v18) = 2;
        v9 = result.m_pszData - 16;
        if ( _InterlockedDecrement((volatile signed __int32 *)result.m_pszData - 1) <= 0 )
          (*(void (__stdcall **)(char *))(**(_DWORD **)v9 + 4))(a1: v9);
        v10 = *((_DWORD *)v3 - 3);
        if ( v10 >= 0 )
        {
          if ( ((1 - *((_DWORD *)v3 - 1)) | (*((_DWORD *)v3 - 2) - v10)) < 0 )
          {
            ATL::CSimpleStringT<char,0>::PrepareWrite2(this: &str, nLength: *((_DWORD *)v3 - 3));
            v3 = str.m_pszData;
          }
          switch ( _mbslwr_s(string: (unsigned __int8 *)v3, sizeInBytes: v10 + 1) )
          {
            case 0:
            case 80:
              if ( v10 > *((_DWORD *)v3 - 2) )
                break;
              *((_DWORD *)v3 - 3) = v10;
              v3[v10] = 0;
              SendMessageA(hWnd: v1->m_TextureFiles.m_hWnd, Msg: 0x180u, wParam: 0, lParam: (LPARAM)v3);
              CPropertyPage::SetModified(this: v1, bChanged: 1);
              if ( pos == nullptr )
                goto LABEL_22;
              continue;
            case 12:
              AfxThrowMemoryException();
            default:
              AfxThrowInvalidArgException();
          }
        }
        break;
      }
      ATL::AtlThrowImpl(hr: -2147024809);
    }
LABEL_22:
    _mbsrchr(str: (unsigned __int8 *)v3, c: 0x5Cu);
    if ( v11 != 0 )
    {
      v12 = v11 - (_DWORD)v3;
      if ( v12 != -1 )
        lstrcpynA(lpString1: szInitialDir_5, lpString2: v3, iMaxLength: v12 + 1);
    }
    LOBYTE(v18) = 0;
    if ( _InterlockedDecrement((volatile signed __int32 *)v3 - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**((_DWORD **)v3 - 4) + 4))(a1: v3 - 16);
  }
  v18 = -1;
  CFileDialog::~CFileDialog(this: &dlg);
}

//------------------------------------------------------------------------------
// Address: 0x100F0EC0
// Name: protected: void COPTTextures::OnMaterialExcludeAdd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTTextures::OnMaterialExcludeAdd(COPTTextures *this)
{
  char *v2; // eax
  unsigned __int8 *v3; // esi
  int v4; // eax
  char *v5; // eax
  char *v6; // edx
  char v7; // cl
  WPARAM v8; // esi
  CGameConfig *m_pMaterialConfig; // edx
  int v10; // eax
  char szTmp[260]; // [esp+4h] [ebp-208h] BYREF
  char szSubDirName[260]; // [esp+108h] [ebp-104h] BYREF

  if ( COPTTextures::BrowseForFolder(this, pszTitle: "Select Game Executable Directory", pszDirectory: szTmp) != nullptr )
  {
    szSubDirName[0] = 0;
    v2 = _strdup(string: szTmp);
    v3 = (unsigned __int8 *)strlwr(string: v2);
    strstr(str1: v3, str2: "materials");
    if ( v4 != 0 )
    {
      v5 = (char *)(v4 + 10);
      v6 = (char *)(szSubDirName - v5);
      do
      {
        v7 = *v5;
        v5[(_DWORD)v6] = *v5;
        ++v5;
      }
      while ( v7 != 0 );
      free(pMem: v3);
    }
    if ( szSubDirName[0] != 0 )
    {
      v8 = SendMessageA(hWnd: this->m_MaterialExcludeList.m_hWnd, Msg: 0x180u, wParam: 0, lParam: (LPARAM)szSubDirName);
      SendMessageA(hWnd: this->m_MaterialExcludeList.m_hWnd, Msg: 0x19Au, wParam: v8, lParam: 1);
      if ( v8 != -1 && v8 != -2 )
      {
        m_pMaterialConfig = this->m_pMaterialConfig;
        if ( m_pMaterialConfig->m_MaterialExcludeCount < 32 )
        {
          ++m_pMaterialConfig->m_MaterialExcludeCount;
          v10 = CUtlVector<MatExlcusions_s,CUtlMemory<MatExlcusions_s,int>>::AddToTail(this: &this->m_pMaterialConfig->m_MaterialExclusions);
          V_strncpy(
            pDest: this->m_pMaterialConfig->m_MaterialExclusions.m_Memory.m_pMemory[v10].szDirectory,
            pSrc: szSubDirName,
            maxLen: 260);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F0FD0
// Name: protected: virtual struct AFX_MSGMAP const __near * COPTTextures::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall COPTTextures::GetMessageMap(COPTTextures *this)
{
  return (const AFX_MSGMAP *)&off_105F0C34;
}

//------------------------------------------------------------------------------
// Address: 0x1040B853
// Name: protected: static int CShellManager::BrowseCallbackProc(struct HWND__ __near *,unsigned int,long,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall CShellManager::BrowseCallbackProc(HWND__ *hwnd, unsigned int uMsg, int __formal, int lpData)
{
  if ( uMsg == 1 && *(_DWORD *)(lpData + 8) != 0 )
    SendMessageA(hWnd: hwnd, Msg: 0x466u, wParam: 1u, lParam: *(_DWORD *)(lpData + 8));
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1040BB20
// Name: public: int CShellManager::BrowseForFolder(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &,class CWnd __near *,char const __near *,char const __near *,unsigned int,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShellManager::BrowseForFolder(
        CShellManager *this,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *strFolder,
        CWnd *pWndParent,
        const char *lplszInitialFolder,
        const char *lpszTitle,
        unsigned int ulFlags,
        int *piFolderImage)
{
  int v8; // ebx
  LPITEMIDLIST v9; // edi
  _browseinfoA bi; // [esp+Ch] [ebp-234h] BYREF
  ATL::CSimpleStringT<char,0> *v12; // [esp+2Ch] [ebp-214h]
  int *v13; // [esp+30h] [ebp-210h]
  char szDisplayName[260]; // [esp+34h] [ebp-20Ch] BYREF
  char szPath[260]; // [esp+138h] [ebp-108h] BYREF

  v12 = strFolder;
  v13 = piFolderImage;
  memset(dst: (unsigned __int8 *)&bi, value: 0, count: sizeof(bi));
  bi.lpszTitle = lpszTitle;
  if ( lpszTitle == nullptr )
    bi.lpszTitle = &var;
  bi.pszDisplayName = szDisplayName;
  if ( pWndParent != nullptr )
    bi.hwndOwner = pWndParent->m_hWnd;
  else
    bi.hwndOwner = nullptr;
  bi.pidlRoot = nullptr;
  bi.iImage = -1;
  bi.ulFlags = ulFlags;
  this->m_lpszInitialPath = lplszInitialFolder;
  bi.lpfn = CShellManager::BrowseCallbackProc;
  bi.lParam = (int)this;
  v8 = 0;
  v9 = SHBrowseForFolderA(lpbi: &bi);
  if ( v9 != nullptr )
  {
    if ( SHGetPathFromIDListA(pidl: v9, pszPath: szPath) )
    {
      ATL::CSimpleStringT<char,0>::SetString(this: v12, pszSrc: szPath);
      if ( v13 != nullptr )
        *v13 = bi.iImage;
      v8 = 1;
    }
    CShellManager::FreeItem(this, pidl: v9);
  }
  this->m_lpszInitialPath = nullptr;
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1040B87F
// Name: public: struct _ITEMIDLIST __near * CShellManager::GetNextItem(struct _ITEMIDLIST const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_ITEMIDLIST *__thiscall CShellManager::GetNextItem(CShellManager *this, const _ITEMIDLIST *pidl)
{
  if ( pidl != nullptr )
    return (_ITEMIDLIST *)((char *)pidl + pidl->mkid.cb);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1040B898
// Name: public: struct _ITEMIDLIST __near * CShellManager::CreateItem(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_ITEMIDLIST *__thiscall CShellManager::CreateItem(CShellManager *this, unsigned int cbSize)
{
  unsigned __int8 *v2; // eax
  unsigned __int8 *v3; // esi

  if ( this->m_pMalloc == nullptr )
    AfxThrowInvalidArgException();
  v2 = (unsigned __int8 *)this->m_pMalloc->Alloc(this: this->m_pMalloc, a2: cbSize);
  v3 = v2;
  if ( v2 != nullptr )
    memset(dst: v2, value: 0, count: cbSize);
  return (_ITEMIDLIST *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x1040B8D0
// Name: public: unsigned int CShellManager::GetItemCount(struct _ITEMIDLIST const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const _ITEMIDLIST *__thiscall CShellManager::GetItemCount(CShellManager *this, const _ITEMIDLIST *pidl)
{
  const _ITEMIDLIST *result; // eax
  int v4; // edx
  int v5; // edx

  result = pidl;
  if ( pidl != nullptr )
  {
    v4 = 0;
    if ( pidl->mkid.cb != 0 )
    {
      do
      {
        result = CShellManager::GetNextItem(this, pidl: result);
        v4 = v5 + 1;
      }
      while ( result->mkid.cb != 0 );
    }
    return (const _ITEMIDLIST *)v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040B8FC
// Name: public: unsigned int CShellManager::GetItemSize(struct _ITEMIDLIST const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CShellManager::GetItemSize(CShellManager *this, const _ITEMIDLIST *pidl)
{
  const _ITEMIDLIST *NextItem; // eax
  int v3; // edx

  NextItem = pidl;
  v3 = 0;
  if ( pidl != nullptr )
  {
    while ( NextItem->mkid.cb != 0 )
      NextItem = CShellManager::GetNextItem(this, pidl: NextItem);
    v3 += 2;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1040B92E
// Name: public: struct _ITEMIDLIST __near * CShellManager::ConcatenateItem(struct _ITEMIDLIST const __near *,struct _ITEMIDLIST const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_ITEMIDLIST *__thiscall CShellManager::ConcatenateItem(CShellManager *this, _ITEMIDLIST *pidl1, _ITEMIDLIST *pidl2)
{
  unsigned int v3; // esi
  unsigned int ItemSize; // ebx
  unsigned __int8 *Item; // eax
  unsigned __int8 *v7; // edi

  v3 = 0;
  if ( pidl1 != nullptr )
    v3 = CShellManager::GetItemSize(this, pidl: pidl1) - 2;
  ItemSize = CShellManager::GetItemSize(this, pidl: pidl2);
  Item = (unsigned __int8 *)CShellManager::CreateItem(this, cbSize: ItemSize + v3);
  v7 = Item;
  if ( Item != nullptr )
  {
    if ( pidl1 != nullptr )
      memcpy(dst: Item, src: (unsigned __int8 *)pidl1, count: v3);
    memcpy(dst: &v7[v3], src: (unsigned __int8 *)pidl2, count: ItemSize);
  }
  return (_ITEMIDLIST *)v7;
}

//------------------------------------------------------------------------------
// Address: 0x1040B993
// Name: public: struct _ITEMIDLIST __near * CShellManager::CopyItem(struct _ITEMIDLIST const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_ITEMIDLIST *__thiscall CShellManager::CopyItem(CShellManager *this, _ITEMIDLIST *pidlSource)
{
  _ITEMIDLIST *result; // eax
  unsigned int ItemSize; // edi
  _ITEMIDLIST *v5; // esi

  if ( this->m_pMalloc == nullptr )
    AfxThrowInvalidArgException();
  if ( pidlSource == nullptr )
    return nullptr;
  ItemSize = CShellManager::GetItemSize(this, pidl: pidlSource);
  result = (_ITEMIDLIST *)this->m_pMalloc->Alloc(this: this->m_pMalloc, a2: ItemSize);
  v5 = result;
  if ( result != nullptr )
  {
    memcpy(dst: (unsigned __int8 *)result, src: (unsigned __int8 *)pidlSource, count: ItemSize);
    return v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040B9E0
// Name: public: void CShellManager::FreeItem(struct _ITEMIDLIST __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CShellManager::FreeItem(CShellManager *this, _ITEMIDLIST *pidl)
{
  if ( this->m_pMalloc == nullptr )
    AfxThrowInvalidArgException();
  if ( pidl != nullptr )
    this->m_pMalloc->Free(this: this->m_pMalloc, a2: pidl);
}

//------------------------------------------------------------------------------
// Address: 0x1040BA06
// Name: public: long CShellManager::ItemFromPath(char const __near *,struct _ITEMIDLIST __near * __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CShellManager::ItemFromPath(CShellManager *this, const char *lpszPath, _ITEMIDLIST **pidl)
{
  HRESULT result; // eax
  HRESULT v4; // esi
  unsigned int chEaten; // [esp+Ch] [ebp-218h] BYREF
  unsigned int dwAttributes; // [esp+10h] [ebp-214h] BYREF
  IShellFolder *pDesktopFolder; // [esp+14h] [ebp-210h] BYREF
  wchar_t olePath[260]; // [esp+18h] [ebp-20Ch] BYREF

  if ( lpszPath == nullptr )
    AfxThrowInvalidArgException();
  result = SHGetDesktopFolder(ppshf: &pDesktopFolder);
  if ( result >= 0 )
  {
    MultiByteToWideChar(
      CodePage: 0,
      dwFlags: 1u,
      lpMultiByteStr: lpszPath,
      cbMultiByte: -1,
      lpWideCharStr: olePath,
      cchWideChar: 260);
    v4 = pDesktopFolder->ParseDisplayName(
           this: pDesktopFolder,
           a2: nullptr,
           a3: nullptr,
           a4: olePath,
           a5: &chEaten,
           a6: pidl,
           a7: &dwAttributes);
    pDesktopFolder->Release(this: pDesktopFolder);
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040BA9D
// Name: public: int CShellManager::GetParentItem(struct _ITEMIDLIST const __near *,struct _ITEMIDLIST __near * __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall CShellManager::GetParentItem(
        CShellManager *this,
        _ITEMIDLIST *lpidl,
        _ITEMIDLIST **lpidlParent)
{
  const _ITEMIDLIST *ItemCount; // eax
  const _ITEMIDLIST *NextItem; // ecx
  unsigned __int8 *abID; // edi
  unsigned __int8 *v8; // esi
  unsigned __int16 v9; // dx
  unsigned int v10; // esi
  _ITEMIDLIST *Item; // eax

  ItemCount = CShellManager::GetItemCount(this, pidl: lpidl);
  if ( ItemCount == nullptr )
    return (unsigned __int8 *)-1;
  if ( ItemCount == (const _ITEMIDLIST *)1 )
  {
    if ( SHGetSpecialFolderLocation(hwnd: nullptr, csidl: 0, ppidl: lpidlParent) < 0 )
      AfxThrowInvalidArgException();
    return nullptr;
  }
  else
  {
    NextItem = lpidl;
    abID = ItemCount[-1].mkid.abID;
    v8 = ItemCount[-1].mkid.abID;
    do
    {
      --v8;
      NextItem = CShellManager::GetNextItem(this, pidl: NextItem);
    }
    while ( v8 != nullptr );
    v10 = v9;
    Item = CShellManager::CreateItem(this, cbSize: v9 + 2);
    *lpidlParent = Item;
    memcpy(dst: (unsigned __int8 *)Item, src: (unsigned __int8 *)lpidl, count: v10);
    return abID;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040BC34
// Name: public: CMFCAcceleratorKey::CMFCAcceleratorKey(struct tagACCEL __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCAcceleratorKey *__thiscall CMFCAcceleratorKey::CMFCAcceleratorKey(CMFCAcceleratorKey *this, tagACCEL *lpAccel)
{
  this->__vftable = (CMFCAcceleratorKey_vtbl *)&CMFCAcceleratorKey::`vftable';
  this->m_lpAccel = lpAccel;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1040BC4B
// Name: public: virtual CMFCAcceleratorKey::~CMFCAcceleratorKey(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCAcceleratorKey::~CMFCAcceleratorKey(CMFCAcceleratorKey *this)
{
  this->__vftable = (CMFCAcceleratorKey_vtbl *)&CMFCAcceleratorKey::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1040BC74
// Name: protected: void CMFCAcceleratorKey::AddVirtKeyStr(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &,unsigned int,int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCAcceleratorKey::AddVirtKeyStr(
        CMFCAcceleratorKey *this,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *str,
        UINT uiVirtKey,
        int bLast)
{
  CAfxStringMgr *StringManager; // eax
  int v5; // edi
  int v6; // eax
  HKL KeyboardLayout; // eax
  LONG v8; // eax
  int v9; // eax
  char *m_pszData; // esi
  int v11; // eax
  CHAR v12; // bl
  char v13; // [esp+14h] [ebp-4Ch]
  ATL::CSimpleStringT<char,0> v14; // [esp+18h] [ebp-48h] BYREF
  unsigned __int8 dst[64]; // [esp+1Ch] [ebp-44h] BYREF
  int v16; // [esp+5Ch] [ebp-4h]

  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v14, pStringMgr: StringManager);
  v5 = 0;
  v16 = 0;
  if ( uiVirtKey == 19 )
  {
    strlen(buf: "Pause");
    ATL::CSimpleStringT<char,0>::SetString(this: &v14, pszSrc: "Pause", nLength: v6);
  }
  else
  {
    memset(dst, value: 0, count: 0x33u);
    KeyboardLayout = GetKeyboardLayout(idThread: 0);
    v8 = (MapVirtualKeyExA(uCode: uiVirtKey, uMapType: 0, dwhkl: KeyboardLayout) << 16) | 1;
    if ( uiVirtKey >= 0x21 && uiVirtKey <= 0x2F || uiVirtKey == 111 )
      v8 |= 0x1000000u;
    GetKeyNameTextA(lParam: v8, lpString: (LPSTR)dst, cchSize: 50);
    strlen(buf: dst);
    ATL::CSimpleStringT<char,0>::SetString(this: &v14, pszSrc: (const char *)dst, nLength: v9);
  }
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::MakeLower(this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v14);
  m_pszData = v14.m_pszData;
  v11 = *((_DWORD *)v14.m_pszData - 3);
  if ( v11 > 0 )
  {
    while ( 1 )
    {
      if ( v5 < 0 || v5 > v11 )
        ATL::AtlThrowImpl(hr: -2147024809);
      v12 = m_pszData[v5];
      if ( IsCharLowerA(ch: v12) )
        break;
      v11 = *((_DWORD *)m_pszData - 3);
      if ( ++v5 >= v11 )
        goto LABEL_13;
    }
    v13 = toupper(c: v12);
    ATL::CSimpleStringT<char,0>::SetAt(this: &v14, iChar: v5, ch: v13);
    m_pszData = v14.m_pszData;
  }
LABEL_13:
  ATL::CSimpleStringT<char,0>::Append(this: str, pszSrc: m_pszData, nLength: *((_DWORD *)m_pszData - 3));
  if ( bLast == 0 )
    ATL::CSimpleStringT<char,0>::AppendChar(this: str, ch: 43);
  ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
}

//------------------------------------------------------------------------------
// Address: 0x1040BD98
// Name: public: void CMFCAcceleratorKey::Format(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &)const
// Source: linker_block_proximity
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
// Address: 0x1040BE1D
// Name: public: virtual struct CRuntimeClass __near * CMFCColorPopupMenu::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCColorPopupMenu::GetRuntimeClass(CMFCColorPopupMenu *this)
{
  return &CMFCColorPopupMenu::classCMFCColorPopupMenu;
}

//------------------------------------------------------------------------------
// Address: 0x1040BE23
// Name: public: virtual CMFCColorPopupMenu::~CMFCColorPopupMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorPopupMenu::~CMFCColorPopupMenu(CMFCColorPopupMenu *this)
{
  this->__vftable = (CMFCColorPopupMenu_vtbl *)&CMFCColorPopupMenu::`vftable';
  CMFCColorBar::~CMFCColorBar(this: &this->m_wndColorBar);
  CMFCPopupMenu::~CMFCPopupMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x1040BE5A
// Name: public: virtual class CPane __near * CMFCColorPopupMenu::CreateTearOffBar(class CFrameWnd __near *,unsigned int,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCColorBar *__thiscall CMFCColorPopupMenu::CreateTearOffBar(
        CMFCColorPopupMenu *this,
        CFrameWnd *pWndMain,
        unsigned int uiID,
        const char *lpszName)
{
  CObject *v5; // edi
  CMFCColorBar *v7; // ecx
  CMFCColorBar *v8; // esi
  CMFCColorBar_vtbl *v9; // edi
  int v10; // eax

  if ( lpszName == nullptr || uiID == 0 )
    AfxThrowInvalidArgException();
  v5 = AfxDynamicDownCast(pClass: &CMFCColorMenuButton::classCMFCColorMenuButton, pObject: this->m_pParentBtn);
  if ( v5 == nullptr )
    return nullptr;
  v7 = (CMFCColorBar *)operator new(nSize: 0xDF0u);
  if ( v7 != nullptr )
    v8 = CMFCColorBar::CMFCColorBar(this: v7, src: &this->m_wndColorBar, uiCommandID: (unsigned int)v5[8].__vftable);
  else
    v8 = nullptr;
  if ( v8->Create(this: v8, a2: pWndMain, a3: 1346381832u, a4: uiID, a5: nullptr, a6: 0, a7: 0, a8: 0) == 0 )
  {
    ((void (__thiscall *)(CMFCColorBar *, int))v8->dtr_CObject)(a1: v8, a2: 1);
    return nullptr;
  }
  CWnd::SetWindowTextA(this: v8, lpszString: lpszName);
  v9 = v8->__vftable;
  v10 = v8->GetPaneStyle(this: v8);
  v9->SetPaneStyle(this: v8, a2: v10 | 0x30);
  v8->EnableDocking(this: v8, a2: 61440u);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1040BF35
// Name: protected: int CMFCColorPopupMenu::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge CMFCColorPopupMenu::OnCreate@<eax>(CMFCColorPopupMenu *this@<ecx>, int a2@<ebx>, CWnd *lpCreateStruct)
{
  int v5; // ebx
  HWND Parent; // eax
  CWnd *v7; // eax
  HWND__ *m_hWnd; // eax
  CMFCColorBar_vtbl *v9; // ebx
  int v10; // eax
  CFrameWnd *TopLevelFrame; // eax
  CWnd *pWndParent; // [esp+10h] [ebp+8h]

  if ( CMFCToolBar::m_bCustomizeMode != 0 && this->m_bEnabledInCustomizeMode == 0
    || CFrameWnd::OnCreate(this, lpcs: (tagCREATESTRUCTA *)lpCreateStruct) == -1 )
  {
    return -1;
  }
  v5 = 1346381832;
  if ( CMFCPopupMenu::GetAnimationType(bNoSystem: 0) != NO_ANIMATION && CMFCToolBar::m_bCustomizeMode == 0 )
    v5 = 1077946376;
  if ( this->m_wndColorBar.Create(
         this: &this->m_wndColorBar,
         a2: this,
         a3: v5 | 0x30,
         a4: 1u,
         a5: nullptr,
         a6: 0,
         a7: 0,
         a8: 0) == 0 )
    return -1;
  Parent = GetParent(hWnd: this->m_hWnd);
  v7 = CWnd::FromHandle(hWnd: Parent);
  pWndParent = v7;
  if ( v7 != nullptr )
    m_hWnd = v7->m_hWnd;
  else
    m_hWnd = nullptr;
  v9 = this->m_wndColorBar.__vftable;
  this->m_wndColorBar.m_hWndOwner = m_hWnd;
  v10 = ((int (__thiscall *)(CMFCColorBar *, int))v9->GetPaneStyle)(a1: &this->m_wndColorBar, a2);
  v9->SetPaneStyle(this: &this->m_wndColorBar, a2: v10 | 0x10);
  TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame;
  if ( g_pTopLevelFrame == nullptr )
    TopLevelFrame = CWnd::GetTopLevelFrame(this: pWndParent);
  CMFCPopupMenu::ActivatePopupMenu(pTopFrame: TopLevelFrame, pPopupMenu: this);
  this->RecalcLayout(this, a2: 1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1040C01C
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCColorPopupMenu::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCColorPopupMenu::GetMessageMap(CMFCColorPopupMenu *this)
{
  return (const AFX_MSGMAP *)&off_1068C3D0;
}

//------------------------------------------------------------------------------
// Address: 0x1040C022
// Name: public: virtual CMFCSpinButtonCtrl::~CMFCSpinButtonCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCSpinButtonCtrl::~CMFCSpinButtonCtrl(CMFCSpinButtonCtrl *this)
{
  this->__vftable = (CMFCSpinButtonCtrl_vtbl *)&CMFCSpinButtonCtrl::`vftable';
  CSpinButtonCtrl::~CSpinButtonCtrl(this);
}

//------------------------------------------------------------------------------
// Address: 0x1040C02D
// Name: protected: void CMFCSpinButtonCtrl::OnPaint(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCSpinButtonCtrl::OnPaint(CMFCSpinButtonCtrl *this)
{
  CDC *p_m_dcMem; // eax
  CPaintDC v3; // [esp+10h] [ebp-A0h] BYREF
  CMemDC v4; // [esp+64h] [ebp-4Ch] BYREF
  int v5; // [esp+ACh] [ebp-4h]

  CPaintDC::CPaintDC(this: &v3, pWnd: this);
  v5 = 0;
  CMemDC::CMemDC(this: &v4, dc: &v3, pWnd: (HDC__ *)this);
  LOBYTE(v5) = 1;
  p_m_dcMem = &v4.m_dcMem;
  if ( v4.m_bMemDC == 0 )
    p_m_dcMem = v4.m_dc;
  this->OnDraw(this, a2: p_m_dcMem);
  LOBYTE(v5) = 0;
  CMemDC::~CMemDC(this: &v4);
  v5 = -1;
  CPaintDC::~CPaintDC(this: &v3);
}

//------------------------------------------------------------------------------
// Address: 0x1040C09A
// Name: public: CMFCSpinButtonCtrl::CMFCSpinButtonCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCSpinButtonCtrl *__thiscall CMFCSpinButtonCtrl::CMFCSpinButtonCtrl(CMFCSpinButtonCtrl *this)
{
  CWnd::CWnd(this);
  this->m_bTracked = 0;
  this->m_bIsButtonPressedUp = 0;
  this->m_bIsButtonPressedDown = 0;
  this->m_bIsButtonHighligtedUp = 0;
  this->m_bIsButtonHighligtedDown = 0;
  this->__vftable = (CMFCSpinButtonCtrl_vtbl *)&CMFCSpinButtonCtrl::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1040C0EC
// Name: public: virtual void CMFCSpinButtonCtrl::OnDraw(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCSpinButtonCtrl::OnDraw(CMFCSpinButtonCtrl *this, CDC *pDC)
{
  CMFCVisualManager *Instance; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-44h]
  CDrawingManager v5; // [esp+10h] [ebp-2Ch] BYREF
  int v6; // [esp+18h] [ebp-24h]
  tagRECT Rect; // [esp+1Ch] [ebp-20h] BYREF
  int v8; // [esp+38h] [ebp-4h]

  m_hWnd = this->m_hWnd;
  memset(&Rect, 0, sizeof(Rect));
  GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
  if ( CMFCToolBarImages::m_bIsDrawOnGlass != 0 )
  {
    CDrawingManager::CDrawingManager(this: &v5, m_dc: pDC);
    v8 = 0;
    CDrawingManager::DrawRect(this: &v5, rect: (int)&Rect, clrFill: afxGlobalData.clrWindow, clrLine: 0xFFFFFFFF);
    v8 = -1;
    CDrawingManager::~CDrawingManager(this: &v5);
  }
  else
  {
    FillRect(hDC: pDC->m_hDC, lprc: &Rect, hbr: (HBRUSH)afxGlobalData.brWindow.m_hObject);
  }
  v6 = this->m_bIsButtonPressedUp != 0;
  if ( this->m_bIsButtonPressedDown != 0 )
    v6 |= 2u;
  if ( this->m_bIsButtonHighligtedUp != 0 )
    v6 |= 4u;
  if ( this->m_bIsButtonHighligtedDown != 0 )
    v6 |= 8u;
  if ( CWnd::IsWindowEnabled(this) == 0 )
    v6 |= 0x10u;
  Instance = CMFCVisualManager::GetInstance();
  ((void (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int, int, _DWORD, CMFCSpinButtonCtrl *))Instance->OnDrawSpinButtons)(
    a1: Instance,
    a2: pDC,
    a3: Rect.left,
    a4: Rect.top,
    a5: Rect.right,
    a6: Rect.bottom,
    a7: v6,
    a8: 0,
    a9: this);
}

//------------------------------------------------------------------------------
// Address: 0x1040C1C6
// Name: protected: void CMFCSpinButtonCtrl::OnLButtonDown(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCSpinButtonCtrl::OnLButtonDown(CMFCSpinButtonCtrl *this, unsigned int nFlags, CPoint point)
{
  CRect rectDown; // [esp+Ch] [ebp-34h] BYREF
  CRect rectUp; // [esp+1Ch] [ebp-24h] BYREF
  CRect rect; // [esp+2Ch] [ebp-14h] BYREF

  memset(&rect, 0, sizeof(rect));
  GetClientRect(hWnd: this->m_hWnd, lpRect: &rect);
  rectUp.left = rect.left;
  rectUp.top = rect.top;
  rectUp.right = rect.right;
  rectDown.left = rect.left;
  rectDown.right = rect.right;
  rectDown.bottom = rect.bottom;
  rectUp.bottom = (rect.bottom + rect.top) / 2;
  rectDown.top = rectUp.bottom;
  this->m_bIsButtonPressedUp = PtInRect(lprc: &rectUp, pt: point.tagPOINT);
  this->m_bIsButtonPressedDown = PtInRect(lprc: &rectDown, pt: point.tagPOINT);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1040C259
// Name: protected: void CMFCSpinButtonCtrl::OnLButtonUp(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCSpinButtonCtrl::OnLButtonUp(CMFCSpinButtonCtrl *this, unsigned int nFlags, CPoint point)
{
  this->m_bIsButtonPressedUp = 0;
  this->m_bIsButtonPressedDown = 0;
  this->m_bIsButtonHighligtedUp = 0;
  this->m_bIsButtonHighligtedDown = 0;
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x1040C272
// Name: protected: void CMFCSpinButtonCtrl::OnCancelMode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCSpinButtonCtrl::OnCancelMode(CMFCSpinButtonCtrl *this)
{
  CWnd::Default(this);
  this->m_bIsButtonPressedUp = 0;
  this->m_bIsButtonPressedDown = 0;
  this->m_bIsButtonHighligtedUp = 0;
  this->m_bIsButtonHighligtedDown = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1040C28F
// Name: protected: void CMFCSpinButtonCtrl::OnMouseMove(unsigned int,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCSpinButtonCtrl::OnMouseMove(CMFCSpinButtonCtrl *this, char nFlags, CPoint point)
{
  BOOL v4; // eax
  HWND__ *m_hWnd; // eax
  tagTRACKMOUSEEVENT trackmouseevent; // [esp+Ch] [ebp-4Ch] BYREF
  int bIsButtonHighligtedDown; // [esp+1Ch] [ebp-3Ch]
  int bIsButtonHighligtedUp; // [esp+20h] [ebp-38h]
  CRect rectDown; // [esp+24h] [ebp-34h] BYREF
  CRect rectUp; // [esp+34h] [ebp-24h] BYREF
  CRect rect; // [esp+44h] [ebp-14h] BYREF

  bIsButtonHighligtedUp = this->m_bIsButtonHighligtedUp;
  bIsButtonHighligtedDown = this->m_bIsButtonHighligtedDown;
  memset(&rect, 0, sizeof(rect));
  GetClientRect(hWnd: this->m_hWnd, lpRect: &rect);
  rectUp.left = rect.left;
  rectUp.top = rect.top;
  rectUp.right = rect.right;
  rectDown.left = rect.left;
  rectDown.right = rect.right;
  rectDown.bottom = rect.bottom;
  rectUp.bottom = (rect.bottom + rect.top) / 2;
  rectDown.top = rectUp.bottom;
  this->m_bIsButtonHighligtedUp = PtInRect(lprc: &rectUp, pt: point.tagPOINT);
  v4 = PtInRect(lprc: &rectDown, pt: point.tagPOINT);
  this->m_bIsButtonHighligtedDown = v4;
  if ( (nFlags & 1) != 0 )
  {
    this->m_bIsButtonPressedUp = this->m_bIsButtonHighligtedUp;
    this->m_bIsButtonPressedDown = v4;
  }
  CWnd::Default(this);
  if ( bIsButtonHighligtedUp != this->m_bIsButtonHighligtedUp
    || bIsButtonHighligtedDown != this->m_bIsButtonHighligtedDown )
  {
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  }
  if ( this->m_bTracked == 0 )
  {
    m_hWnd = this->m_hWnd;
    trackmouseevent.dwHoverTime = -1;
    trackmouseevent.hwndTrack = m_hWnd;
    this->m_bTracked = 1;
    trackmouseevent.cbSize = 16;
    trackmouseevent.dwFlags = 2;
    AFXTrackMouse(ptme: &trackmouseevent);
  }
}
