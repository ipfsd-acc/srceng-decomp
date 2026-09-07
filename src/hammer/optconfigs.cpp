// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/optconfigs.cpp
// Functions: 149
// ============================================================

#include "hammer\optconfigs.h"

//------------------------------------------------------------------------------
// Address: 0x100ED3E0
// Name: public: virtual struct CRuntimeClass __near * COPTConfigs::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall COPTConfigs::GetRuntimeClass(COPTConfigs *this)
{
  return &COPTConfigs::classCOPTConfigs;
}

//------------------------------------------------------------------------------
// Address: 0x100ED3F0
// Name: void SetPersistentEnvironmentVariable(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetPersistentEnvironmentVariable(const char *pName, const char *pValue)
{
  unsigned int dwReturnValue; // [esp+0h] [ebp-8h] BYREF
  HKEY__ *hregkey; // [esp+4h] [ebp-4h] BYREF

  dwReturnValue = 0;
  if ( RegOpenKeyExA(
         hKey: HKEY_LOCAL_MACHINE,
         lpSubKey: "SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment",
         ulOptions: 0,
         samDesired: 0xF003Fu,
         phkResult: &hregkey) == 0 )
  {
    RegSetValueExA(
      hKey: hregkey,
      lpValueName: pName,
      Reserved: 0,
      dwType: 1u,
      lpData: (const BYTE *)pValue,
      cbData: strlen(pValue));
    SendMessageTimeoutA(
      hWnd: HWND_BROADCAST,
      Msg: 0x1Au,
      wParam: 0,
      lParam: (LPARAM)"Environment",
      fuFlags: 2u,
      uTimeout: 0x1388u,
      lpdwResult: &dwReturnValue);
    RegCloseKey(hKey: hregkey);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED470
// Name: protected: virtual void COPTConfigs::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTConfigs::DoDataExchange(COPTConfigs *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F3, rControl: (HWND__ *)&this->m_cMapDir);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F5, rControl: (HWND__ *)&this->m_cPrefabDir);
  DDX_Control(pDX, nIDC: (HWND__ *)0x5AD, rControl: (HWND__ *)&this->m_cGameExeDir);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F4, rControl: (HWND__ *)&this->m_cModDir);
  DDX_Control(pDX, nIDC: (HWND__ *)0x574, rControl: (HWND__ *)&this->m_cMapFormat);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F1, rControl: (HWND__ *)&this->m_cCordonTexture);
  DDX_Control(pDX, nIDC: (HWND__ *)0x573, rControl: (HWND__ *)&this->m_cTextureFormat);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3EF, rControl: (HWND__ *)&this->m_cDefaultPoint);
  DDX_Control(pDX, nIDC: (HWND__ *)0x3F0, rControl: (HWND__ *)&this->m_cDefaultSolid);
  DDX_Control(pDX, nIDC: (HWND__ *)0x4B9, rControl: (HWND__ *)&this->m_cGDFiles);
  DDX_Control(pDX, nIDC: (HWND__ *)0x4BC, rControl: (HWND__ *)&this->m_cConfigs);
  DDX_Control(pDX, nIDC: (HWND__ *)0x5BB, rControl: (HWND__ *)&this->m_cDefaultTextureScale);
}

//------------------------------------------------------------------------------
// Address: 0x100ED560
// Name: void SelectActiveConfig(class CComboBox __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SelectActiveConfig(CComboBox *combo)
{
  WPARAM v1; // esi
  LRESULT v2; // eax
  char szGameDir[260]; // [esp+0h] [ebp-10Ch] BYREF
  CGameConfig *pConfig; // [esp+104h] [ebp-8h] BYREF
  int nCount; // [esp+108h] [ebp-4h] BYREF

  if ( RegOpenKeyExA(
         hKey: HKEY_LOCAL_MACHINE,
         lpSubKey: "SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment",
         ulOptions: 0,
         samDesired: 1u,
         phkResult: (PHKEY)&nCount) == 0 )
  {
    pConfig = (CGameConfig *)260;
    if ( RegQueryValueExA(
           hKey: (HKEY)nCount,
           lpValueName: "VProject",
           lpReserved: nullptr,
           lpType: nullptr,
           lpData: (LPBYTE)szGameDir,
           lpcbData: (LPDWORD)&pConfig) == 0 )
    {
      RegCloseKey(hKey: (HKEY)nCount);
      pConfig = COptionsConfigs::FindConfigForGame(this: &Options.configs, szGame: szGameDir);
      if ( pConfig != nullptr )
      {
        v1 = 0;
        nCount = SendMessageA(hWnd: combo->m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0);
        if ( nCount > 0 )
        {
          while ( 1 )
          {
            v2 = SendMessageA(hWnd: combo->m_hWnd, Msg: 0x150u, wParam: v1, lParam: 0);
            if ( pConfig->dwID == v2 )
              break;
            if ( (int)++v1 >= nCount )
              return;
          }
          if ( v1 != -1 )
            SendMessageA(hWnd: combo->m_hWnd, Msg: 0x14Eu, wParam: v1, lParam: 0);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED640
// Name: protected: void COPTConfigs::UpdateEntityLists(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTConfigs::UpdateEntityLists(COPTConfigs *this)
{
  CGameConfig *m_pLastSelConfig; // ecx
  int v3; // ebx
  GDclass *v4; // eax
  int nCount; // [esp+4h] [ebp-8h]
  CGameConfig *pConfig; // [esp+8h] [ebp-4h]

  if ( this->m_pLastSelConfig != nullptr )
  {
    SendMessageA(hWnd: this->m_cDefaultPoint.m_hWnd, Msg: 0x14Bu, wParam: 0, lParam: 0);
    SendMessageA(hWnd: this->m_cDefaultSolid.m_hWnd, Msg: 0x14Bu, wParam: 0, lParam: 0);
    m_pLastSelConfig = this->m_pLastSelConfig;
    v3 = 0;
    pConfig = m_pLastSelConfig;
    nCount = m_pLastSelConfig->GD.m_Classes.m_Size;
    if ( nCount > 0 )
    {
      do
      {
        if ( v3 < m_pLastSelConfig->GD.m_Classes.m_Size )
          v4 = m_pLastSelConfig->GD.m_Classes.m_Memory.m_pMemory[v3];
        else
          v4 = nullptr;
        if ( !v4->m_bBase )
        {
          if ( v4->m_bSolid )
            SendMessageA(hWnd: this->m_cDefaultSolid.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)v4->m_szName);
          else
            SendMessageA(hWnd: this->m_cDefaultPoint.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)v4->m_szName);
          m_pLastSelConfig = pConfig;
        }
        ++v3;
      }
      while ( v3 < nCount );
    }
    if ( m_pLastSelConfig->szDefaultSolid[0] != 0 )
      CWnd::SetWindowTextA(this: &this->m_cDefaultSolid, lpszString: m_pLastSelConfig->szDefaultSolid);
    else
      SendMessageA(hWnd: this->m_cDefaultSolid.m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
    if ( pConfig->szDefaultPoint[0] != 0 )
      CWnd::SetWindowTextA(this: &this->m_cDefaultPoint, lpszString: pConfig->szDefaultPoint);
    else
      SendMessageA(hWnd: this->m_cDefaultPoint.m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100ED760
// Name: void UpdateConfigList(class CComboBox __near &)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100ED870
// Name: protected: bool COPTConfigs::ConfigChanged(class CGameConfig __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall COPTConfigs::ConfigChanged(COPTConfigs *this, CGameConfig *pConfig)
{
  CGameConfig *m_pInitialSelectedConfig; // eax

  m_pInitialSelectedConfig = this->m_pInitialSelectedConfig;
  if ( m_pInitialSelectedConfig != pConfig )
    return true;
  if ( pConfig == nullptr || m_pInitialSelectedConfig == nullptr )
    return false;
  if ( m_pInitialSelectedConfig->dwID != pConfig->dwID )
    return true;
  if ( pConfig == (CGameConfig *)-1312 )
    ATL::AtlThrowImpl(hr: -2147467259);
  return _mbsicmp(
           s1: (const unsigned __int8 *)this->m_strInitialGameDir.m_pszData,
           s2: (const unsigned __int8 *)pConfig->m_szModDir) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100ED8D0
// Name: public: COPTConfigs::COPTConfigs(void)
// Source: json
//------------------------------------------------------------------------------
COPTConfigs *__thiscall COPTConfigs::COPTConfigs(COPTConfigs *this)
{
  CAfxStringMgr *StringManager; // eax

  CPropertyPage::CPropertyPage(this, nIDTemplate: 0xCFu, nIDCaption: 0, dwSize: 0x38u);
  this->__vftable = (COPTConfigs_vtbl *)&COPTConfigs::`vftable';
  CWnd::CWnd(this: &this->m_cMapDir);
  this->m_cMapDir.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_cPrefabDir);
  this->m_cPrefabDir.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_cGameExeDir);
  this->m_cGameExeDir.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_cModDir);
  this->m_cModDir.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_cCordonTexture);
  this->m_cCordonTexture.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_cDefaultTextureScale);
  this->m_cDefaultTextureScale.__vftable = (CEdit_vtbl *)&CEdit::`vftable';
  CWnd::CWnd(this: &this->m_cMapFormat);
  this->m_cMapFormat.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  CWnd::CWnd(this: &this->m_cTextureFormat);
  this->m_cTextureFormat.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  CAutoSelComboBox::CAutoSelComboBox(this: &this->m_cDefaultPoint);
  CAutoSelComboBox::CAutoSelComboBox(this: &this->m_cDefaultSolid);
  CWnd::CWnd(this: &this->m_cGDFiles);
  this->m_cGDFiles.__vftable = (CListBox_vtbl *)&CListBox::`vftable';
  CWnd::CWnd(this: &this->m_cConfigs);
  this->m_cConfigs.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_strInitialGameDir.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  this->m_pLastSelConfig = nullptr;
  this->m_pInitialSelectedConfig = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100EDAC0
// Name: public: virtual COPTConfigs::~COPTConfigs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTConfigs::~COPTConfigs(COPTConfigs *this)
{
  volatile signed __int32 *v2; // eax

  this->__vftable = (COPTConfigs_vtbl *)&COPTConfigs::`vftable';
  v2 = (volatile signed __int32 *)(this->m_strInitialGameDir.m_pszData - 16);
  if ( _InterlockedDecrement(v2 + 3) <= 0 )
    (*(void (__stdcall **)(volatile signed __int32 *))(**(_DWORD **)v2 + 4))(a1: v2);
  CComboBox::~CComboBox(this: &this->m_cConfigs);
  CListBox::~CListBox(this: &this->m_cGDFiles);
  CComboBox::~CComboBox(this: &this->m_cDefaultSolid);
  CComboBox::~CComboBox(this: &this->m_cDefaultPoint);
  CComboBox::~CComboBox(this: &this->m_cTextureFormat);
  CComboBox::~CComboBox(this: &this->m_cMapFormat);
  CEdit::~CEdit(this: &this->m_cDefaultTextureScale);
  CEdit::~CEdit(this: &this->m_cCordonTexture);
  CEdit::~CEdit(this: &this->m_cModDir);
  CEdit::~CEdit(this: &this->m_cGameExeDir);
  CEdit::~CEdit(this: &this->m_cPrefabDir);
  CEdit::~CEdit(this: &this->m_cMapDir);
  CPropertyPage::~CPropertyPage(this);
}

//------------------------------------------------------------------------------
// Address: 0x100EDC00
// Name: protected: void COPTConfigs::OnBrowseCordonTexture(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COPTConfigs::OnBrowseCordonTexture(COPTConfigs *this)
{
  char *v2; // eax
  CTextureBrowser *v3; // esi
  LRESULT v4; // ebx
  WPARAM v5; // eax
  CAfxStringMgr *StringManager; // eax
  char *v7; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strTex; // [esp+8h] [ebp-10h] BYREF
  int v9; // [esp+14h] [ebp-4h]

  v2 = (char *)operator new(nSize: 0xD00u);
  strTex.m_pszData = v2;
  v9 = 0;
  if ( v2 != nullptr )
    v3 = CTextureBrowser::CTextureBrowser(this: (CTextureBrowser *)v2, pParent: this);
  else
    v3 = nullptr;
  v9 = -1;
  if ( v3 != nullptr )
  {
    v4 = 5;
    v5 = SendMessageA(hWnd: this->m_cTextureFormat.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
    if ( v5 != -1 )
      v4 = SendMessageA(hWnd: this->m_cTextureFormat.m_hWnd, Msg: 0x150u, wParam: v5, lParam: 0);
    CTextureBrowser::SetTextureFormat(this: v3, eTextureFormat: (TEXTUREFORMAT)v4);
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    strTex.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
    v9 = 2;
    CWnd::GetWindowTextA(this: &this->m_cCordonTexture, rString: &strTex);
    CTextureBrowser::SetInitialTexture(this: v3, pszTexture: strTex.m_pszData);
    if ( v3->DoModal(this: v3) == 1 )
      CWnd::SetWindowTextA(this: &this->m_cCordonTexture, lpszString: v3->m_cTextureWindow.szCurTexture);
    ((void (__thiscall *)(CTextureBrowser *, int))v3->dtr_CObject)(a1: v3, a2: 1);
    v9 = -1;
    v7 = strTex.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)strTex.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v7 + 4))(a1: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EDD50
// Name: public: static class CObject __near * COPTConfigs::CreateObject(void)
// Source: json
//------------------------------------------------------------------------------
COPTConfigs *__stdcall COPTConfigs::CreateObject()
{
  COPTConfigs *v0; // eax

  v0 = (COPTConfigs *)operator new(nSize: 0x83Cu);
  if ( v0 != nullptr )
    return COPTConfigs::COPTConfigs(this: v0);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100EDDE0
// Name: void EditorUtil_ConvertPath(class ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char>>> __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall EditorUtil_ConvertPath(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *str,
        bool bExpand)
{
  CAfxStringMgr *StringManager; // eax
  int v6; // eax
  CAfxStringMgr *v7; // eax
  int v8; // eax
  char *m_pszData; // ebx
  char *v10; // edi
  char *v11; // eax
  char *v12; // eax
  char szPathOut[260]; // [esp+0h] [ebp-118h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strSteamDir; // [esp+104h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strSteamUserDir; // [esp+108h] [ebp-10h] BYREF
  int v16; // [esp+114h] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  strSteamDir.m_pszData = (char *)(((int (__thiscall *)(CAfxStringMgr *, int, int, int))StringManager->GetNilString)(
                                     a1: StringManager,
                                     a2,
                                     a3,
                                     a4: a1)
                                 + 16);
  v16 = 1;
  if ( g_pGameConfig == (CGameConfig *)-2220 )
    v6 = 0;
  else
    v6 = &g_pGameConfig->m_szSteamDir[strlen(g_pGameConfig->m_szSteamDir) + 1] - &g_pGameConfig->m_szSteamDir[1];
  ATL::CSimpleStringT<char,0>::SetString(this: &strSteamDir, pszSrc: g_pGameConfig->m_szSteamDir, nLength: v6);
  v7 = AfxGetStringManager();
  if ( v7 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  strSteamUserDir.m_pszData = (char *)&v7->GetNilString(this: v7)[1];
  LOBYTE(v16) = 3;
  if ( g_pGameConfig == (CGameConfig *)-2480 )
    v8 = 0;
  else
    v8 = &g_pGameConfig->m_szSteamUserDir[strlen(g_pGameConfig->m_szSteamUserDir) + 1]
       - &g_pGameConfig->m_szSteamUserDir[1];
  ATL::CSimpleStringT<char,0>::SetString(this: &strSteamUserDir, pszSrc: g_pGameConfig->m_szSteamUserDir, nLength: v8);
  m_pszData = strSteamDir.m_pszData;
  v10 = strSteamUserDir.m_pszData;
  if ( *((_DWORD *)strSteamDir.m_pszData - 3) == 0 && *((_DWORD *)strSteamUserDir.m_pszData - 3) == 0 )
  {
    LOBYTE(v16) = 1;
    v11 = strSteamUserDir.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)strSteamUserDir.m_pszData - 1) <= 0 )
      (*(void (__thiscall **)(_DWORD, char *))(**(_DWORD **)v11 + 4))(a1: *(_DWORD *)v11, a2: v10 - 16);
    goto LABEL_27;
  }
  v12 = str->m_pszData;
  if ( bExpand )
  {
    if ( V_StrSubst(
           pIn: v12,
           pMatch: "$SteamUserDir",
           pReplaceWith: strSteamUserDir.m_pszData,
           pOut: szPathOut,
           outLen: 260,
           bCaseSensitive: false) )
    {
      ATL::CSimpleStringT<char,0>::SetString(this: str, pszSrc: szPathOut, nLength: strlen(szPathOut));
    }
    if ( !V_StrSubst(
            pIn: str->m_pszData,
            pMatch: "$SteamDir",
            pReplaceWith: m_pszData,
            pOut: szPathOut,
            outLen: 260,
            bCaseSensitive: false) )
      goto LABEL_25;
  }
  else
  {
    if ( V_StrSubst(
           pIn: v12,
           pMatch: strSteamUserDir.m_pszData,
           pReplaceWith: "$SteamUserDir",
           pOut: szPathOut,
           outLen: 260,
           bCaseSensitive: false) )
    {
      ATL::CSimpleStringT<char,0>::SetString(this: str, pszSrc: szPathOut, nLength: strlen(szPathOut));
    }
    if ( !V_StrSubst(
            pIn: str->m_pszData,
            pMatch: m_pszData,
            pReplaceWith: "$SteamDir",
            pOut: szPathOut,
            outLen: 260,
            bCaseSensitive: false) )
      goto LABEL_25;
  }
  ATL::CSimpleStringT<char,0>::SetString(
    this: str,
    pszSrc: szPathOut,
    nLength: &szPathOut[strlen(szPathOut) + 1] - &szPathOut[1]);
LABEL_25:
  LOBYTE(v16) = 1;
  if ( _InterlockedDecrement((volatile signed __int32 *)v10 - 1) <= 0 )
    (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)v10 - 4) + 4))(a1: *((_DWORD *)v10 - 4), a2: v10 - 16);
LABEL_27:
  v16 = -1;
  if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
    (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
      a1: *((_DWORD *)m_pszData - 4),
      a2: m_pszData - 16);
}

//------------------------------------------------------------------------------
// Address: 0x100EE040
// Name: void EditorUtil_TransferPath(class CDialog __near *,int,char __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __usercall EditorUtil_TransferPath(
        int a1@<ebx>,
        int a2@<esi>,
        CDialog *pDlg,
        int nIDC,
        char *szDest,
        bool bExpand)
{
  CWnd *DlgItem; // edi
  CAfxStringMgr *StringManager; // eax
  char *m_pszData; // eax
  int v9; // edx
  char v10; // cl
  int v11; // eax
  char *v12; // eax
  int v13; // [esp-4h] [ebp-18h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+4h] [ebp-10h] BYREF
  int v15; // [esp+10h] [ebp-4h]

  DlgItem = CWnd::GetDlgItem(this: pDlg, nID: nIDC);
  if ( DlgItem != nullptr )
  {
    StringManager = AfxGetStringManager();
    if ( StringManager == nullptr )
      ATL::AtlThrowImpl(hr: -2147467259);
    str.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
    v15 = 1;
    if ( bExpand )
    {
      CWnd::GetWindowTextA(this: DlgItem, rString: &str);
      EditorUtil_ConvertPath(a1, a2: (int)DlgItem, a3: a2, &str, bExpand: true);
      m_pszData = str.m_pszData;
      v9 = szDest - str.m_pszData;
      do
      {
        v10 = *m_pszData;
        m_pszData[v9] = *m_pszData;
        ++m_pszData;
      }
      while ( v10 != 0 );
    }
    else
    {
      if ( szDest != nullptr )
      {
        v13 = a2;
        v11 = strlen(szDest);
        a2 = v13;
      }
      else
      {
        v11 = 0;
      }
      ATL::CSimpleStringT<char,0>::SetString(this: &str, pszSrc: szDest, nLength: v11);
      EditorUtil_ConvertPath(a1, a2: (int)DlgItem, a3: a2, &str, bExpand: false);
      CWnd::SetWindowTextA(this: DlgItem, lpszString: str.m_pszData);
    }
    v15 = -1;
    v12 = str.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v12 + 4))(a1: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EE150
// Name: protected: void COPTConfigs::OnGdfileEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall COPTConfigs::OnGdfileEdit(COPTConfigs *this@<ecx>, int a2@<ebx>)
{
  LRESULT v3; // edi
  CAfxStringMgr *StringManager; // eax
  char *v5; // eax
  char v6; // cl
  char *v7; // eax
  char v8; // [esp+3h] [ebp-115h] BYREF
  char szBuf[260]; // [esp+4h] [ebp-114h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+108h] [ebp-10h] BYREF
  int v11; // [esp+114h] [ebp-4h]

  if ( this->m_pLastSelConfig != nullptr )
  {
    v3 = SendMessageA(hWnd: this->m_cGDFiles.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
    if ( v3 != -1 )
    {
      StringManager = AfxGetStringManager();
      if ( StringManager == nullptr )
        ATL::AtlThrowImpl(hr: -2147467259);
      str.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
      v11 = 1;
      CListBox::GetText(this: &this->m_cGDFiles, nIndex: v3, rString: &str);
      EditorUtil_ConvertPath(a1: a2, a2: v3, a3: (int)this, &str, bExpand: true);
      GetWindowsDirectoryA(lpBuffer: szBuf, uSize: 0x104u);
      v5 = &v8;
      do
        v6 = *++v5;
      while ( v6 != 0 );
      strcpy(v5, "\\notepad.exe");
      _spawnl(modeflag: 0, pathname: szBuf, arglist: szBuf, str.m_pszData, 0);
      CGameConfig::LoadGDFiles(this: this->m_pLastSelConfig);
      COPTConfigs::UpdateEntityLists(this);
      v11 = -1;
      v7 = str.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v7 + 4))(a1: v7);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EE2A0
// Name: protected: void COPTConfigs::SaveInfo(class CGameConfig __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge COPTConfigs::SaveInfo(COPTConfigs *this@<ecx>, int a2@<ebx>, float pConfig)
{
  CGameConfig *v3; // esi
  CStringArray *v5; // ecx
  CAfxStringMgr *StringManager; // eax
  char *v7; // eax
  WPARAM v8; // eax
  WPARAM v9; // eax
  const char *m_szPrefabDir; // ebx
  char *v11; // eax
  char v12; // cl
  long double v13; // st7
  float v14; // xmm0_4
  char szCordonTexture[260]; // [esp+8h] [ebp-1FCh] BYREF
  char szOldPrefabDir[128]; // [esp+10Ch] [ebp-F8h] BYREF
  char szText[100]; // [esp+18Ch] [ebp-78h] BYREF
  int iSize; // [esp+1F0h] [ebp-14h]
  int i; // [esp+1F4h] [ebp-10h]
  int v20; // [esp+200h] [ebp-4h]

  v3 = (CGameConfig *)LODWORD(pConfig);
  if ( pConfig != 0.0 )
  {
    v5 = (CStringArray *)(LODWORD(pConfig) + 1572);
    *(_DWORD *)(LODWORD(pConfig) + 152) = 0;
    CStringArray::SetSize(this: v5, nNewSize: 0, nGrowBy: -1);
    iSize = SendMessageA(hWnd: this->m_cGDFiles.m_hWnd, Msg: 0x18Bu, wParam: 0, lParam: 0);
    for ( i = 0; i < iSize; ++i )
    {
      StringManager = AfxGetStringManager();
      if ( StringManager == nullptr )
        ATL::AtlThrowImpl(hr: -2147467259);
      LODWORD(pConfig) = &StringManager->GetNilString(this: StringManager)[1];
      v20 = 1;
      CListBox::GetText(
        this: &this->m_cGDFiles,
        nIndex: i,
        rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pConfig);
      EditorUtil_ConvertPath(
        a1: a2,
        a2: (int)this,
        a3: (int)v3,
        str: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pConfig,
        bExpand: true);
      CStringArray::SetAtGrow(this: &v3->GDFiles, nIndex: v3->GDFiles.m_nSize, newElement: (ATL::CStringData *)&pConfig);
      ++v3->nGDFiles;
      v20 = -1;
      v7 = (char *)(LODWORD(pConfig) - 16);
      if ( _InterlockedDecrement((volatile signed __int32 *)(LODWORD(pConfig) - 16 + 12)) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v7 + 4))(a1: v7);
    }
    v8 = SendMessageA(hWnd: this->m_cMapFormat.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
    if ( v8 == -1 )
      v3->mapformat = mfHalfLife2;
    else
      v3->mapformat = SendMessageA(hWnd: this->m_cMapFormat.m_hWnd, Msg: 0x150u, wParam: v8, lParam: 0);
    v9 = SendMessageA(hWnd: this->m_cTextureFormat.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
    if ( v9 == -1 )
      v3->textureformat = tfVMT;
    else
      v3->textureformat = SendMessageA(hWnd: this->m_cTextureFormat.m_hWnd, Msg: 0x150u, wParam: v9, lParam: 0);
    CWnd::GetWindowTextA(this: &this->m_cDefaultSolid, lpszString: v3->szDefaultSolid, nMaxCount: 128);
    CWnd::GetWindowTextA(this: &this->m_cDefaultPoint, lpszString: v3->szDefaultPoint, nMaxCount: 128);
    EditorUtil_TransferPath(
      a1: (int)SendMessageA,
      a2: (int)v3,
      pDlg: this,
      nIDC: 1453,
      szDest: v3->m_szGameExeDir,
      bExpand: true);
    EditorUtil_TransferPath(
      a1: (int)SendMessageA,
      a2: (int)v3,
      pDlg: this,
      nIDC: 1012,
      szDest: v3->m_szModDir,
      bExpand: true);
    EditorUtil_TransferPath(
      a1: (int)SendMessageA,
      a2: (int)v3,
      pDlg: this,
      nIDC: 1011,
      szDest: v3->szMapDir,
      bExpand: true);
    m_szPrefabDir = v3->m_szPrefabDir;
    v11 = v3->m_szPrefabDir;
    do
    {
      v12 = *v11;
      v11[szOldPrefabDir - v3->m_szPrefabDir] = *v11;
      ++v11;
    }
    while ( v12 != 0 );
    EditorUtil_TransferPath(
      a1: (int)m_szPrefabDir,
      a2: (int)v3,
      pDlg: this,
      nIDC: 1013,
      szDest: v3->m_szPrefabDir,
      bExpand: true);
    if ( strcmp(szOldPrefabDir, m_szPrefabDir) != 0 )
      AfxMessageBox(
        lpszText: "Your changes to the prefab path will not take effect until the next time you run Hammer.",
        nType: 0,
        nIDHelp: 0);
    CWnd::GetWindowTextA(this: &this->m_cCordonTexture, lpszString: szCordonTexture, nMaxCount: 260);
    V_strncpy(pDest: v3->m_szCordonTexture, pSrc: szCordonTexture, maxLen: 260);
    CWnd::GetWindowTextA(this: &this->m_cDefaultTextureScale, lpszString: szText, nMaxCount: 100);
    v13 = atof(nptr: szText);
    pConfig = v13;
    if ( v13 == 0.0 )
      v14 = 1.0;
    else
      v14 = pConfig;
    v3->m_fDefaultTextureScale = v14;
    v3->m_nDefaultLightmapScale = CWnd::GetDlgItemInt(this, nID: 1468, lpTrans: nullptr, bSigned: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EE5B0
// Name: protected: void COPTConfigs::OnSelchangeConfigurations(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall COPTConfigs::OnSelchangeConfigurations(COPTConfigs *this@<ecx>, int a2@<ebx>)
{
  LRESULT (__stdcall *v3)(HWND, UINT, WPARAM, LPARAM); // edi
  WPARAM v4; // eax
  LRESULT v5; // eax
  CGameConfig *Config; // ebx
  int v7; // eax
  char *m_pszData; // edi
  int v9; // ecx
  char *v10; // edi
  int (__thiscall ***v11)(_DWORD, _DWORD, int); // eax
  int v12; // eax
  int v13; // ecx
  int v14; // edi
  HWND__ *m_hWnd; // [esp-8h] [ebp-98h]
  HWND__ *v16; // [esp-8h] [ebp-98h]
  HWND__ *v17; // [esp-8h] [ebp-98h]
  char string[8]; // [esp+14h] [ebp-7Ch] BYREF
  char szText[100]; // [esp+1Ch] [ebp-74h] BYREF
  int bEnable; // [esp+80h] [ebp-10h]
  int v21; // [esp+8Ch] [ebp-4h]

  COPTConfigs::SaveInfo(this, a2, pConfig: *(float *)&this->m_pLastSelConfig);
  v3 = SendMessageA;
  m_hWnd = this->m_cConfigs.m_hWnd;
  this->m_pLastSelConfig = nullptr;
  v4 = SendMessageA(hWnd: m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  v5 = SendMessageA(hWnd: this->m_cConfigs.m_hWnd, Msg: 0x150u, wParam: v4, lParam: 0);
  Config = COptionsConfigs::FindConfig(this: &Options.configs, dwID: v5, piIndex: nullptr);
  bEnable = Config != nullptr;
  CWnd::EnableWindow(this: &this->m_cGDFiles, bEnable);
  CWnd::EnableWindow(this: &this->m_cDefaultPoint, bEnable);
  CWnd::EnableWindow(this: &this->m_cDefaultSolid, bEnable);
  CWnd::EnableWindow(this: &this->m_cTextureFormat, bEnable);
  CWnd::EnableWindow(this: &this->m_cMapFormat, bEnable);
  CWnd::EnableWindow(this: &this->m_cGameExeDir, bEnable);
  CWnd::EnableWindow(this: &this->m_cModDir, bEnable);
  CWnd::EnableWindow(this: &this->m_cMapDir, bEnable);
  CWnd::EnableWindow(this: &this->m_cPrefabDir, bEnable);
  CWnd::EnableWindow(this: &this->m_cCordonTexture, bEnable);
  if ( Config != nullptr )
  {
    v16 = this->m_cGDFiles.m_hWnd;
    this->m_pLastSelConfig = Config;
    SendMessageA(hWnd: v16, Msg: 0x184u, wParam: 0, lParam: 0);
    v7 = 0;
    bEnable = 0;
    if ( Config->nGDFiles > 0 )
    {
      while ( 1 )
      {
        if ( v7 < 0 || v7 >= Config->GDFiles.m_nSize )
          AfxThrowInvalidArgException();
        m_pszData = Config->GDFiles.m_pData[v7].m_pszData;
        v9 = *((_DWORD *)m_pszData - 4);
        v10 = m_pszData - 16;
        v11 = (int (__thiscall ***)(_DWORD, _DWORD, int))(*(int (__thiscall **)(int))(*(_DWORD *)v9 + 16))(a1: v9);
        if ( *((int *)v10 + 3) >= 0 && v11 == *(int (__thiscall ****)(_DWORD, _DWORD, int))v10 )
        {
          _InterlockedExchangeAdd((volatile signed __int32 *)v10 + 3, 1u);
        }
        else
        {
          v12 = (**v11)(a1: v11, a2: *((_DWORD *)v10 + 1), a3: 1);
          *(_DWORD *)&szText[92] = v12;
          if ( v12 == 0 )
            ATL::CSimpleStringT<char,0>::ThrowMemoryException(a1: v13);
          *(_DWORD *)(v12 + 4) = *((_DWORD *)v10 + 1);
          memcpy_s(
            dst: (void *)(v12 + 16),
            sizeInBytes: *((_DWORD *)v10 + 1) + 1,
            src: v10 + 16,
            count: *((_DWORD *)v10 + 1) + 1);
          v10 = *(char **)&szText[92];
        }
        *(_DWORD *)&szText[96] = v10 + 16;
        v21 = 1;
        EditorUtil_ConvertPath(
          a1: (int)Config,
          a2: (int)(v10 + 16),
          a3: (int)this,
          str: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&szText[96],
          bExpand: false);
        v14 = *(_DWORD *)&szText[96];
        SendMessageA(hWnd: this->m_cGDFiles.m_hWnd, Msg: 0x180u, wParam: 0, lParam: *(LPARAM *)&szText[96]);
        v21 = -1;
        if ( _InterlockedDecrement((volatile signed __int32 *)(v14 - 16 + 12)) <= 0 )
          (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(v14 - 16) + 4))(a1: *(_DWORD *)(v14 - 16), a2: v14 - 16);
        if ( ++bEnable >= Config->nGDFiles )
          break;
        v7 = bEnable;
      }
      v3 = SendMessageA;
      SendMessageA(hWnd: this->m_cMapFormat.m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
    }
    else
    {
      SendMessageA(hWnd: this->m_cMapFormat.m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
    }
    *(_DWORD *)&szText[96] = v3(hWnd: this->m_cMapFormat.m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0);
    bEnable = 0;
    if ( *(int *)&szText[96] > 0 )
    {
      while ( Config->mapformat != v3(hWnd: this->m_cMapFormat.m_hWnd, Msg: 0x150u, wParam: bEnable, lParam: 0) )
      {
        if ( ++bEnable >= *(int *)&szText[96] )
          goto LABEL_23;
      }
      v3(hWnd: this->m_cMapFormat.m_hWnd, Msg: 0x14Eu, wParam: bEnable, lParam: 0);
    }
LABEL_23:
    v3(hWnd: this->m_cTextureFormat.m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
    *(_DWORD *)&szText[96] = v3(hWnd: this->m_cTextureFormat.m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0);
    bEnable = 0;
    if ( *(int *)&szText[96] > 0 )
    {
      while ( 1 )
      {
        v17 = this->m_cTextureFormat.m_hWnd;
        *(_DWORD *)&szText[92] = Config->textureformat;
        if ( *(_DWORD *)&szText[92] == v3(hWnd: v17, Msg: 0x150u, wParam: bEnable, lParam: 0) )
          break;
        if ( ++bEnable >= *(int *)&szText[96] )
          goto LABEL_28;
      }
      v3(hWnd: this->m_cTextureFormat.m_hWnd, Msg: 0x14Eu, wParam: bEnable, lParam: 0);
    }
LABEL_28:
    EditorUtil_TransferPath(
      a1: (int)Config,
      a2: (int)this,
      pDlg: this,
      nIDC: 1453,
      szDest: Config->m_szGameExeDir,
      bExpand: false);
    EditorUtil_TransferPath(
      a1: (int)Config,
      a2: (int)this,
      pDlg: this,
      nIDC: 1012,
      szDest: Config->m_szModDir,
      bExpand: false);
    EditorUtil_TransferPath(
      a1: (int)Config,
      a2: (int)this,
      pDlg: this,
      nIDC: 1011,
      szDest: Config->szMapDir,
      bExpand: false);
    EditorUtil_TransferPath(
      a1: (int)Config,
      a2: (int)this,
      pDlg: this,
      nIDC: 1013,
      szDest: Config->m_szPrefabDir,
      bExpand: false);
    CWnd::SetWindowTextA(this: &this->m_cCordonTexture, lpszString: Config->m_szCordonTexture);
    sprintf(string, format: "%g", Config->m_fDefaultTextureScale);
    CWnd::SetWindowTextA(this: &this->m_cDefaultTextureScale, lpszString: string);
    CWnd::SetDlgItemInt(this, nID: 1468, nValue: Config->m_nDefaultLightmapScale, bSigned: 0);
    COPTConfigs::UpdateEntityLists(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EE9C0
// Name: protected: virtual int COPTConfigs::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall COPTConfigs::OnInitDialog(COPTConfigs *this)
{
  WPARAM v2; // eax
  WPARAM v3; // eax
  WPARAM v4; // eax
  WPARAM v5; // eax
  WPARAM v6; // eax
  LRESULT v7; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *p_m_strInitialGameDir; // edi
  CGameConfig *m_pInitialSelectedConfig; // esi
  const char *m_szModDir; // edx

  CDialog::OnInitDialog(this);
  v2 = SendMessageA(hWnd: this->m_cMapFormat.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"Half-Life 2");
  SendMessageA(hWnd: this->m_cMapFormat.m_hWnd, Msg: 0x151u, wParam: v2, lParam: 4);
  v3 = SendMessageA(hWnd: this->m_cMapFormat.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)"Half-Life / TFC");
  SendMessageA(hWnd: this->m_cMapFormat.m_hWnd, Msg: 0x151u, wParam: v3, lParam: 3);
  v4 = SendMessageA(
         hWnd: this->m_cTextureFormat.m_hWnd,
         Msg: 0x143u,
         wParam: 0,
         lParam: (LPARAM)"Materials (Half-Life 2)");
  SendMessageA(hWnd: this->m_cTextureFormat.m_hWnd, Msg: 0x151u, wParam: v4, lParam: 5);
  v5 = SendMessageA(
         hWnd: this->m_cTextureFormat.m_hWnd,
         Msg: 0x143u,
         wParam: 0,
         lParam: (LPARAM)"WAD3 (Half-Life / TFC)");
  SendMessageA(hWnd: this->m_cTextureFormat.m_hWnd, Msg: 0x151u, wParam: v5, lParam: 2);
  this->m_pLastSelConfig = nullptr;
  UpdateConfigList(combo: &this->m_cConfigs);
  SelectActiveConfig(combo: &this->m_cConfigs);
  COPTConfigs::OnSelchangeConfigurations(this, a2: (int)&this->m_cConfigs);
  CPropertyPage::SetModified(this, bChanged: 1);
  v6 = SendMessageA(hWnd: this->m_cConfigs.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  v7 = SendMessageA(hWnd: this->m_cConfigs.m_hWnd, Msg: 0x150u, wParam: v6, lParam: 0);
  p_m_strInitialGameDir = &this->m_strInitialGameDir;
  this->m_pInitialSelectedConfig = COptionsConfigs::FindConfig(this: &Options.configs, dwID: v7, piIndex: nullptr);
  ATL::CSimpleStringT<char,0>::Empty(this: &this->m_strInitialGameDir);
  m_pInitialSelectedConfig = this->m_pInitialSelectedConfig;
  if ( m_pInitialSelectedConfig != nullptr )
  {
    m_szModDir = m_pInitialSelectedConfig->m_szModDir;
    if ( m_pInitialSelectedConfig == (CGameConfig *)-1312 )
    {
      ATL::CSimpleStringT<char,0>::SetString(this: p_m_strInitialGameDir, pszSrc: m_szModDir, nLength: 0);
      return 1;
    }
    ATL::CSimpleStringT<char,0>::SetString(
      this: p_m_strInitialGameDir,
      pszSrc: m_szModDir,
      nLength: strlen(m_pInitialSelectedConfig->m_szModDir));
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100EEB30
// Name: public: virtual int COPTConfigs::OnApply(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall COPTConfigs::OnApply@<eax>(COPTConfigs *this@<ecx>, int a2@<ebx>)
{
  WPARAM v3; // eax
  LRESULT v4; // eax
  CGameConfig *Config; // eax
  CGameConfig *v6; // edi

  COPTConfigs::SaveInfo(this, a2, pConfig: *(float *)&this->m_pLastSelConfig);
  v3 = SendMessageA(hWnd: this->m_cConfigs.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  v4 = SendMessageA(hWnd: this->m_cConfigs.m_hWnd, Msg: 0x150u, wParam: v3, lParam: 0);
  Config = COptionsConfigs::FindConfig(this: &Options.configs, dwID: v4, piIndex: nullptr);
  v6 = Config;
  if ( Config != nullptr && COPTConfigs::ConfigChanged(this, pConfig: Config) )
  {
    SetPersistentEnvironmentVariable(pName: "vproject", pValue: v6->m_szModDir);
    AfxMessageBox(
      lpszText: "Your changes to the active configuration will not take effect until the next time you run Hammer.",
      nType: 0,
      nIDHelp: 0);
  }
  COptions::PerformChanges(this: &Options, dwOptionsChanged: 16);
  return CPropertyPage::OnApply(this);
}

//------------------------------------------------------------------------------
// Address: 0x100EEBC0
// Name: protected: long COPTConfigs::OnSettingChange(unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __userpurge COPTConfigs::OnSettingChange@<eax>(
        COPTConfigs *this@<ecx>,
        int a2@<ebx>,
        unsigned int wParam,
        const char *lParam)
{
  if ( _V_stricmp(s1: lParam, s2: "Environment") == 0 )
  {
    this->m_pLastSelConfig = nullptr;
    UpdateConfigList(combo: &this->m_cConfigs);
    SelectActiveConfig(combo: &this->m_cConfigs);
    COPTConfigs::OnSelchangeConfigurations(this, a2);
    CPropertyPage::SetModified(this, bChanged: 1);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100EEC10
// Name: protected: void COPTConfigs::OnEditconfigs(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall COPTConfigs::OnEditconfigs(COPTConfigs *this@<ecx>, int a2@<ebx>)
{
  CEditGameConfigs dlg; // [esp+8h] [ebp-11Ch] BYREF
  int v4; // [esp+120h] [ebp-4h]

  COPTConfigs::SaveInfo(this, a2, pConfig: *(float *)&this->m_pLastSelConfig);
  CEditGameConfigs::CEditGameConfigs(this: &dlg, bSelectOnly: 0, pParent: nullptr);
  v4 = 0;
  CDialog::DoModal(this: &dlg);
  this->m_pLastSelConfig = nullptr;
  UpdateConfigList(combo: &this->m_cConfigs);
  SelectActiveConfig(combo: &this->m_cConfigs);
  COPTConfigs::OnSelchangeConfigurations(this, a2);
  CPropertyPage::SetModified(this, bChanged: 1);
  v4 = 1;
  CListBox::~CListBox(this: &dlg.m_cConfigs);
  v4 = -1;
  CDialog::~CDialog(this: &dlg);
}

//------------------------------------------------------------------------------
// Address: 0x100EECC0
// Name: protected: void COPTConfigs::OnGdfileAdd(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall COPTConfigs::OnGdfileAdd(COPTConfigs *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  AFX_MODULE_STATE *ModuleState; // eax
  char *v5; // eax
  char szAppDir[260]; // [esp+4h] [ebp-318h] BYREF
  CFileDialog dlg; // [esp+108h] [ebp-214h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+30Ch] [ebp-10h] BYREF
  int v9; // [esp+318h] [ebp-4h]

  if ( this->m_pLastSelConfig != nullptr )
  {
    ModuleState = AfxGetModuleState();
    CHammer::GetDirectory(this: (CHammer *)ModuleState->m_pCurrentWinApp, dir: DIR_PROGRAM, p: szAppDir);
    CFileDialog::CFileDialog(
      this: &dlg,
      bOpenFileDialog: 1,
      lpszDefExt: ".fgd",
      lpszFileName: nullptr,
      dwFlags: 0x100Cu,
      lpszFilter: "Game Data Files (*.fgd)|*.fgd||",
      pParentWnd: nullptr,
      dwSize: 0,
      bVistaStyle: 1);
    v9 = 0;
    *(_DWORD *)(CMFCRibbonBaseElement::IsAlwaysLargeImage(this: (CMFCRibbonBaseElement *)&dlg) + 44) = szAppDir;
    if ( CFileDialog::DoModal(this: &dlg) == 1 )
    {
      CFileDialog::GetPathName(this: &dlg, result: &str);
      LOBYTE(v9) = 1;
      EditorUtil_ConvertPath(a1: a2, a2: a3, a3: (int)this, &str, bExpand: false);
      SendMessageA(hWnd: this->m_cGDFiles.m_hWnd, Msg: 0x180u, wParam: 0, lParam: (LPARAM)str.m_pszData);
      COPTConfigs::SaveInfo(this, a2, pConfig: *(float *)&this->m_pLastSelConfig);
      CGameConfig::LoadGDFiles(this: this->m_pLastSelConfig);
      COPTConfigs::UpdateEntityLists(this);
      LOBYTE(v9) = 0;
      v5 = str.m_pszData - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
        (*(void (__stdcall **)(char *))(**(_DWORD **)v5 + 4))(a1: v5);
    }
    v9 = -1;
    CFileDialog::~CFileDialog(this: &dlg);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EEE00
// Name: protected: void COPTConfigs::OnGdfileRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall COPTConfigs::OnGdfileRemove(COPTConfigs *this@<ecx>, int a2@<ebx>)
{
  WPARAM v3; // eax

  if ( this->m_pLastSelConfig != nullptr )
  {
    v3 = SendMessageA(hWnd: this->m_cGDFiles.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
    if ( v3 != -1 )
    {
      SendMessageA(hWnd: this->m_cGDFiles.m_hWnd, Msg: 0x182u, wParam: v3, lParam: 0);
      COPTConfigs::SaveInfo(this, a2, pConfig: *(float *)&this->m_pLastSelConfig);
      CGameConfig::LoadGDFiles(this: this->m_pLastSelConfig);
      COPTConfigs::UpdateEntityLists(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EEE60
// Name: protected: void COPTConfigs::OnBrowseGameExeDir(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall COPTConfigs::OnBrowseGameExeDir(COPTConfigs *this@<ecx>, int a2@<ebx>)
{
  HWND__ *m_hWnd; // eax
  _ITEMIDLIST *v4; // esi
  char *v5; // eax
  char v6; // [esp+8h] [ebp-238h] BYREF
  char szTmp[260]; // [esp+10Ch] [ebp-134h] BYREF
  _browseinfoA bi; // [esp+210h] [ebp-30h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+230h] [ebp-10h] BYREF
  int v10; // [esp+23Ch] [ebp-4h]

  m_hWnd = this->m_hWnd;
  bi.pidlRoot = nullptr;
  memset(&bi.lpfn, 0, 12);
  bi.hwndOwner = m_hWnd;
  bi.pszDisplayName = &v6;
  bi.lpszTitle = "Select Game Executable Directory";
  bi.ulFlags = 1;
  v4 = SHBrowseForFolderA(lpbi: &bi);
  if ( v4 != nullptr )
  {
    SHGetPathFromIDListA(pidl: v4, pszPath: szTmp);
    CoTaskMemFree(pv: v4);
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
      this: &str,
      pszSrc: szTmp);
    v10 = 0;
    EditorUtil_ConvertPath(a1: a2, a2: (int)this, a3: (int)v4, &str, bExpand: false);
    CWnd::SetWindowTextA(this: &this->m_cGameExeDir, lpszString: str.m_pszData);
    v10 = -1;
    v5 = str.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v5 + 4))(a1: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EEF50
// Name: protected: void COPTConfigs::OnBrowseModDir(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall COPTConfigs::OnBrowseModDir(COPTConfigs *this@<ecx>, int a2@<ebx>)
{
  HWND__ *m_hWnd; // eax
  _ITEMIDLIST *v4; // esi
  char *v5; // eax
  char v6; // [esp+8h] [ebp-238h] BYREF
  char szTmp[260]; // [esp+10Ch] [ebp-134h] BYREF
  _browseinfoA bi; // [esp+210h] [ebp-30h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+230h] [ebp-10h] BYREF
  int v10; // [esp+23Ch] [ebp-4h]

  m_hWnd = this->m_hWnd;
  bi.pidlRoot = nullptr;
  memset(&bi.lpfn, 0, 12);
  bi.hwndOwner = m_hWnd;
  bi.pszDisplayName = &v6;
  bi.lpszTitle = "Select Mod Directory";
  bi.ulFlags = 1;
  v4 = SHBrowseForFolderA(lpbi: &bi);
  if ( v4 != nullptr )
  {
    SHGetPathFromIDListA(pidl: v4, pszPath: szTmp);
    CoTaskMemFree(pv: v4);
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
      this: &str,
      pszSrc: szTmp);
    v10 = 0;
    EditorUtil_ConvertPath(a1: a2, a2: (int)this, a3: (int)v4, &str, bExpand: false);
    CWnd::SetWindowTextA(this: &this->m_cModDir, lpszString: str.m_pszData);
    v10 = -1;
    v5 = str.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v5 + 4))(a1: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EF040
// Name: protected: void COPTConfigs::OnBrowsemapdir(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall COPTConfigs::OnBrowsemapdir(COPTConfigs *this@<ecx>, int a2@<ebx>)
{
  HWND__ *m_hWnd; // eax
  _ITEMIDLIST *v4; // esi
  char *v5; // eax
  char v6; // [esp+8h] [ebp-238h] BYREF
  char szTmp[260]; // [esp+10Ch] [ebp-134h] BYREF
  _browseinfoA bi; // [esp+210h] [ebp-30h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+230h] [ebp-10h] BYREF
  int v10; // [esp+23Ch] [ebp-4h]

  m_hWnd = this->m_hWnd;
  bi.pidlRoot = nullptr;
  memset(&bi.lpfn, 0, 12);
  bi.hwndOwner = m_hWnd;
  bi.pszDisplayName = &v6;
  bi.lpszTitle = "Select Map Directory";
  bi.ulFlags = 1;
  v4 = SHBrowseForFolderA(lpbi: &bi);
  if ( v4 != nullptr )
  {
    SHGetPathFromIDListA(pidl: v4, pszPath: szTmp);
    CoTaskMemFree(pv: v4);
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
      this: &str,
      pszSrc: szTmp);
    v10 = 0;
    EditorUtil_ConvertPath(a1: a2, a2: (int)this, a3: (int)v4, &str, bExpand: false);
    CWnd::SetWindowTextA(this: &this->m_cMapDir, lpszString: str.m_pszData);
    v10 = -1;
    v5 = str.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v5 + 4))(a1: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EF130
// Name: protected: void COPTConfigs::OnBrowsePrefabDir(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall COPTConfigs::OnBrowsePrefabDir(COPTConfigs *this@<ecx>, int a2@<ebx>)
{
  HWND__ *m_hWnd; // eax
  _ITEMIDLIST *v4; // esi
  char *v5; // eax
  char v6; // [esp+8h] [ebp-238h] BYREF
  char szTmp[260]; // [esp+10Ch] [ebp-134h] BYREF
  _browseinfoA bi; // [esp+210h] [ebp-30h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+230h] [ebp-10h] BYREF
  int v10; // [esp+23Ch] [ebp-4h]

  m_hWnd = this->m_hWnd;
  bi.pidlRoot = nullptr;
  memset(&bi.lpfn, 0, 12);
  bi.hwndOwner = m_hWnd;
  bi.pszDisplayName = &v6;
  bi.lpszTitle = "Select Map Directory";
  bi.ulFlags = 1;
  v4 = SHBrowseForFolderA(lpbi: &bi);
  if ( v4 != nullptr )
  {
    SHGetPathFromIDListA(pidl: v4, pszPath: szTmp);
    CoTaskMemFree(pv: v4);
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
      this: &str,
      pszSrc: szTmp);
    v10 = 0;
    EditorUtil_ConvertPath(a1: a2, a2: (int)this, a3: (int)v4, &str, bExpand: false);
    CWnd::SetWindowTextA(this: &this->m_cPrefabDir, lpszString: str.m_pszData);
    v10 = -1;
    v5 = str.m_pszData - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
      (*(void (__stdcall **)(char *))(**(_DWORD **)v5 + 4))(a1: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EF220
// Name: protected: virtual struct AFX_MSGMAP const __near * COPTConfigs::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall COPTConfigs::GetMessageMap(COPTConfigs *this)
{
  return (const AFX_MSGMAP *)&off_105F02B0;
}

//------------------------------------------------------------------------------
// Address: 0x10365E30
// Name: public: void AFX_GLOBAL_DATA::OnSettingChange(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall AFX_GLOBAL_DATA::OnSettingChange(AFX_GLOBAL_DATA *this)
{
  int m_bSysUnderlineKeyboardShortcuts; // eax

  this->m_bInSettingChange = 1;
  this->m_sizeSmallIcon.cx = GetSystemMetrics(nIndex: 49);
  this->m_sizeSmallIcon.cy = GetSystemMetrics(nIndex: 50);
  SetRectEmpty(lprc: &this->m_rectVirtual);
  if ( !EnumDisplayMonitors(
          hdc: nullptr,
          lprcClip: nullptr,
          lpfnEnum: InfoEnumProc,
          dwData: (LPARAM)&this->m_rectVirtual) )
    SystemParametersInfoA(uiAction: 0x30u, uiParam: 0, pvParam: &this->m_rectVirtual, fWinIni: 0);
  this->m_bMenuAnimation = 0;
  this->m_bMenuFadeEffect = 0;
  if ( this->bIsRemoteSession == 0 )
  {
    SystemParametersInfoA(uiAction: 0x1002u, uiParam: 0, pvParam: &this->m_bMenuAnimation, fWinIni: 0);
    if ( this->m_bMenuAnimation != 0 )
      SystemParametersInfoA(uiAction: 0x1012u, uiParam: 0, pvParam: &this->m_bMenuFadeEffect, fWinIni: 0);
  }
  this->m_nShellAutohideBars = 0;
  this->m_bRefreshAutohideBars = 1;
  SystemParametersInfoA(uiAction: 0x100Au, uiParam: 0, pvParam: &this->m_bSysUnderlineKeyboardShortcuts, fWinIni: 0);
  m_bSysUnderlineKeyboardShortcuts = this->m_bSysUnderlineKeyboardShortcuts;
  this->m_bInSettingChange = 0;
  this->m_bUnderlineKeyboardShortcuts = m_bSysUnderlineKeyboardShortcuts;
}

//------------------------------------------------------------------------------
// Address: 0x10391DE3
// Name: protected: void CPaneFrameWnd::OnSettingChange(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPaneFrameWnd::OnSettingChange(CPaneFrameWnd *this, unsigned int uFlags, const char *lpszSection)
{
  CWnd::OnSettingChange(this, uFlags, lpszSection);
  this->RecalcCaptionHeight(this);
}

//------------------------------------------------------------------------------
// Address: 0x103AB2C2
// Name: protected: void CMFCToolBar::OnSettingChange(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnSettingChange(CMFCToolBar *this, unsigned int uFlags, const char *lpszSection)
{
  CBasePane::OnSettingChange(this, uFlags, lpszSection);
  if ( uFlags == 42 || uFlags == 47 || uFlags == 34 )
  {
    AFX_GLOBAL_DATA::UpdateFonts(this: &afxGlobalData);
    this->AdjustLayout(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103E12A3
// Name: protected: void CBasePane::OnSettingChange(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBasePane::OnSettingChange(CBasePane *this, unsigned int uFlags, const char *lpszSection)
{
  CWnd::OnSettingChange(this, uFlags, lpszSection);
  AFX_GLOBAL_DATA::OnSettingChange(this: &afxGlobalData);
}

//------------------------------------------------------------------------------
// Address: 0x103E4B0F
// Name: protected: void CMFCMenuBar::OnSettingChange(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCMenuBar::OnSettingChange(CMFCMenuBar *this, unsigned int uFlags, const char *lpszSection)
{
  CMFCToolBar::OnSettingChange(this, uFlags, lpszSection);
  CMFCMenuBar::CalcSysButtonSize(this);
  InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
  UpdateWindow(hWnd: this->m_hWnd);
}

//------------------------------------------------------------------------------
// Address: 0x103E726A
// Name: protected: void CDockablePane::OnSettingChange(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDockablePane::OnSettingChange(CDockablePane *this, unsigned int uFlags, const char *lpszSection)
{
  CDockablePane_vtbl *v4; // eax

  CBasePane::OnSettingChange(this: &this->CPane, uFlags, lpszSection);
  if ( this->m_cyGripper > 0 )
  {
    v4 = this->__vftable;
    this->m_cyGripper = 0;
    v4->EnableGripper(this: &this->CPane, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103EEC3F
// Name: protected: void CDialogEx::OnSettingChange(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDialogEx::OnSettingChange(CDialogEx *this, unsigned int uFlags, const char *lpszSection)
{
  CWnd::OnSettingChange(this, uFlags, lpszSection);
  if ( AfxGetMainWnd() == this )
    AFX_GLOBAL_DATA::OnSettingChange(this: &afxGlobalData);
}

//------------------------------------------------------------------------------
// Address: 0x104045E6
// Name: protected: void CMFCTabCtrl::OnSettingChange(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCTabCtrl::OnSettingChange(CMFCTabCtrl *this, unsigned int uFlags, const char *lpszSection)
{
  CWnd::OnSettingChange(this, uFlags, lpszSection);
  if ( this->m_bFlat != 0 )
  {
    this->SetTabsHeight(this);
    this->RecalcLayout(this);
    CMFCTabCtrl::SynchronizeScrollBar(this, pScrollInfo: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104304E3
// Name: protected: void CMFCTasksPane::OnSettingChange(unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCTasksPane::OnSettingChange(CMFCTasksPane *this, unsigned int uFlags, const char *lpszSection)
{
  CWnd::OnSettingChange(this, uFlags, lpszSection);
  CMFCTasksPane::AdjustScroll(this);
  this->ReposTasks(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10365EF7
// Name: protected: struct HBITMAP__ __near * AFX_GLOBAL_DATA::CreateDitherBitmap(struct HDC__ __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HBITMAP __thiscall AFX_GLOBAL_DATA::CreateDitherBitmap(AFX_GLOBAL_DATA *this, HDC__ *hDC)
{
  DWORD SysColor; // eax
  int i; // eax
  AFX_GLOBAL_DATA::CreateDitherBitmap::__l2::<unnamed_type_bmi> bmi; // [esp+8h] [ebp-8Ch] BYREF
  int patGray[8]; // [esp+70h] [ebp-24h] BYREF

  memset(dst: (unsigned __int8 *)&bmi, value: 0, count: sizeof(bmi));
  bmi.bmiHeader.biCompression = 0;
  bmi.bmiHeader.biPlanes = 1;
  bmi.bmiHeader.biBitCount = 1;
  bmi.bmiColors[0].rgbBlue = BYTE2(afxGlobalData.clrBtnFace);
  bmi.bmiHeader.biSize = 40;
  bmi.bmiHeader.biWidth = 8;
  bmi.bmiHeader.biHeight = 8;
  bmi.bmiColors[0].rgbGreen = BYTE1(afxGlobalData.clrBtnFace);
  bmi.bmiColors[0].rgbRed = afxGlobalData.clrBtnFace;
  SysColor = GetSysColor(nIndex: 20);
  bmi.bmiColors[1].rgbBlue = BYTE2(SysColor);
  bmi.bmiColors[1].rgbGreen = BYTE1(SysColor);
  bmi.bmiColors[1].rgbRed = SysColor;
  for ( i = 0; i < 8; ++i )
    patGray[i] = (i & 1) != 0 ? -1431677611 : 1431677610;
  return CreateDIBitmap(
           hdc: hDC,
           pbmih: &bmi.bmiHeader,
           flInit: 4u,
           pjBits: patGray,
           pbmi: (const BITMAPINFO *)&bmi,
           iUsage: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10365FCF
// Name: public: void AFX_GLOBAL_DATA::ReleaseTaskBarRefs(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall AFX_GLOBAL_DATA::ReleaseTaskBarRefs(AFX_GLOBAL_DATA *this)
{
  ITaskbarList **p_m_pTaskbarList; // edi

  p_m_pTaskbarList = &this->m_pTaskbarList;
  this->m_bTaskBarInterfacesAvailable = 0;
  if ( this->m_pTaskbarList != nullptr )
  {
    _AfxRelease(lplpUnknown: &this->m_pTaskbarList);
    *p_m_pTaskbarList = nullptr;
  }
  if ( this->m_pTaskbarList3 != nullptr )
  {
    _AfxRelease(lplpUnknown: &this->m_pTaskbarList3);
    this->m_pTaskbarList3 = nullptr;
  }
  if ( this->m_bComInitialized != 0 )
  {
    CoUninitialize();
    this->m_bComInitialized = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036601A
// Name: public: unsigned long AFX_GLOBAL_DATA::GetColor(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall AFX_GLOBAL_DATA::GetColor(AFX_GLOBAL_DATA *this, int nColor)
{
  unsigned int result; // eax

  switch ( nColor )
  {
    case 2:
      result = this->clrActiveCaption;
      break;
    case 3:
      result = this->clrInactiveCaption;
      break;
    case 5:
      result = this->clrWindow;
      break;
    case 6:
      result = this->clrWindowFrame;
      break;
    case 7:
      result = this->clrMenuText;
      break;
    case 8:
      result = this->clrWindowText;
      break;
    case 9:
      result = this->clrCaptionText;
      break;
    case 10:
      result = this->clrActiveBorder;
      break;
    case 11:
      result = this->clrInactiveBorder;
      break;
    case 13:
      result = this->clrHilite;
      break;
    case 14:
      result = this->clrTextHilite;
      break;
    case 15:
      result = this->clrBtnFace;
      break;
    case 16:
      result = this->clrBtnShadow;
      break;
    case 17:
      result = this->clrGrayedText;
      break;
    case 18:
      result = this->clrBtnText;
      break;
    case 19:
      result = this->clrInactiveCaptionText;
      break;
    case 20:
      result = this->clrBtnHilite;
      break;
    case 21:
      result = this->clrBtnDkShadow;
      break;
    case 22:
      result = this->clrBtnLight;
      break;
    default:
      result = GetSysColor(nIndex: nColor);
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103660F6
// Name: public: int AFX_GLOBAL_DATA::SetLayeredAttrib(struct HWND__ __near *,unsigned long,unsigned char,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall AFX_GLOBAL_DATA::SetLayeredAttrib(
        AFX_GLOBAL_DATA *this,
        HWND__ *hwnd,
        COLORREF crKey,
        BYTE bAlpha,
        DWORD dwFlags)
{
  return SetLayeredWindowAttributes(hwnd, crKey, bAlpha, dwFlags);
}

//------------------------------------------------------------------------------
// Address: 0x10366102
// Name: public: long AFX_GLOBAL_DATA::DwmDefWindowProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall AFX_GLOBAL_DATA::DwmDefWindowProc(
        AFX_GLOBAL_DATA *this,
        HWND__ *hWnd,
        unsigned int message,
        unsigned int wp,
        int lp)
{
  HRESULT (__stdcall *m_pfDwmDefWindowProc)(HWND__ *, unsigned int, unsigned int, int, int *); // eax
  int lres; // [esp+0h] [ebp-4h] BYREF

  lres = (int)this;
  m_pfDwmDefWindowProc = this->m_pfDwmDefWindowProc;
  if ( m_pfDwmDefWindowProc == nullptr )
    return -1;
  lres = 0;
  m_pfDwmDefWindowProc(a1: hWnd, a2: message, a3: wp, a4: lp, a5: &lres);
  return lres;
}

//------------------------------------------------------------------------------
// Address: 0x10366134
// Name: public: int AFX_GLOBAL_DATA::DwmIsCompositionEnabled(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall AFX_GLOBAL_DATA::DwmIsCompositionEnabled(AFX_GLOBAL_DATA *this)
{
  HRESULT (__stdcall *m_pfDwmIsCompositionEnabled)(int *); // eax
  int bEnabled; // [esp+0h] [ebp-4h] BYREF

  bEnabled = (int)this;
  m_pfDwmIsCompositionEnabled = this->m_pfDwmIsCompositionEnabled;
  if ( m_pfDwmIsCompositionEnabled == nullptr || this->bDisableAero != 0 )
    return 0;
  bEnabled = 0;
  m_pfDwmIsCompositionEnabled(a1: &bEnabled);
  return bEnabled;
}

//------------------------------------------------------------------------------
// Address: 0x10366160
// Name: public: struct HICON__ __near * AFX_GLOBAL_DATA::GetHandCursor(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HICON__ *__thiscall AFX_GLOBAL_DATA::GetHandCursor(AFX_GLOBAL_DATA *this)
{
  HICON__ **p_m_hcurHand; // esi

  p_m_hcurHand = &this->m_hcurHand;
  if ( this->m_hcurHand == nullptr )
    *p_m_hcurHand = LoadCursorW(hInstance: nullptr, lpCursorName: (LPCWSTR)0x7F89);
  return *p_m_hcurHand;
}

//------------------------------------------------------------------------------
// Address: 0x10366181
// Name: public: int AFX_GLOBAL_DATA::GetNonClientMetrics(struct tagNONCLIENTMETRICSA __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall AFX_GLOBAL_DATA::GetNonClientMetrics(AFX_GLOBAL_DATA *this, tagNONCLIENTMETRICSA *info)
{
  unsigned int v3; // [esp-Ch] [ebp-Ch]

  v3 = (unsigned int)_AfxGetComCtlVersion() < 0x60001 ? 340 : 344;
  info->cbSize = v3;
  return SystemParametersInfoA(uiAction: 0x29u, uiParam: v3, pvParam: info, fWinIni: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103661AF
// Name: int AfxIsExtendedFrameClass(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall AfxIsExtendedFrameClass(CWnd *pWnd)
{
  if ( pWnd == nullptr )
    AfxThrowInvalidArgException();
  return CObject::IsKindOf(this: pWnd, pClass: &CFrameWndEx::classCFrameWndEx) != 0
      || CObject::IsKindOf(this: pWnd, pClass: &CMDIFrameWndEx::classCMDIFrameWndEx) != 0
      || CObject::IsKindOf(this: pWnd, pClass: &COleIPFrameWndEx::classCOleIPFrameWndEx) != 0
      || CObject::IsKindOf(this: pWnd, pClass: &COleDocIPFrameWndEx::classCOleDocIPFrameWndEx) != 0
      || CObject::IsKindOf(this: pWnd, pClass: &CMDIChildWndEx::classCMDIChildWndEx) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1036621D
// Name: struct HINSTANCE__ __near * AfxLoadSystemLibraryUsingFullPath(wchar_t const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HINSTANCE__ *__cdecl AfxLoadSystemLibraryUsingFullPath(const wchar_t *pszLibrary)
{
  wchar_t wszLoadPath[262]; // [esp+8h] [ebp-210h] BYREF

  if ( GetSystemDirectoryW(lpBuffer: wszLoadPath, uSize: 0x105u) == 0
    || wszLoadPath[wcslen(wcs: wszLoadPath) - 1] != 92
    && wcscat_s(_Dst: wszLoadPath, _SizeInWords: 0x105u, _Src: L"\\") != 0
    || wcscat_s(_Dst: wszLoadPath, _SizeInWords: 0x105u, _Src: pszLibrary) != 0 )
  {
    return nullptr;
  }
  else
  {
    return AfxCtxLoadLibraryW(lpLibFileName: wszLoadPath);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103662B3
// Name: protected: void AFX_GLOBAL_DATA::UpdateTextMetrics(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall AFX_GLOBAL_DATA::UpdateTextMetrics(AFX_GLOBAL_DATA *this)
{
  CFont *v2; // ebx
  int v3; // eax
  int v4; // eax
  CWindowDC v5; // [esp+10h] [ebp-5Ch] BYREF
  tagTEXTMETRICA tm; // [esp+24h] [ebp-48h] BYREF
  int v7; // [esp+68h] [ebp-4h]

  CWindowDC::CWindowDC(this: &v5, pWnd: nullptr);
  v7 = 0;
  v2 = CDC::SelectObject(this: &v5, pFont: &this->fontRegular);
  if ( v2 == nullptr )
    AfxThrowInvalidArgException();
  GetTextMetricsA(hdc: v5.m_hAttribDC, lptm: &tm);
  v3 = tm.tmHeight >= 15 ? 5 : 2;
  this->m_nTextHeightHorz = v3 + tm.tmHeight;
  this->m_nTextWidthHorz = v3 + tm.tmMaxCharWidth;
  CDC::SelectObject(this: &v5, pFont: &this->fontVert);
  GetTextMetricsA(hdc: v5.m_hAttribDC, lptm: &tm);
  v4 = tm.tmHeight >= 15 ? 5 : 2;
  this->m_nTextHeightVert = v4 + tm.tmHeight;
  this->m_nTextWidthVert = v4 + tm.tmMaxCharWidth;
  CDC::SelectObject(this: &v5, pFont: v2);
  v7 = -1;
  CWindowDC::~CWindowDC(this: &v5);
}

//------------------------------------------------------------------------------
// Address: 0x1036637C
// Name: public: struct ITaskbarList3 __near * AFX_GLOBAL_DATA::GetITaskbarList3(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ITaskbarList3 *__thiscall AFX_GLOBAL_DATA::GetITaskbarList3(AFX_GLOBAL_DATA *this)
{
  ITaskbarList3 **p_m_pTaskbarList3; // edi
  ITaskbarList3 *result; // eax
  int *p_m_bComInitialized; // esi

  if ( this->bIsWindows7 != 0 && this->m_bTaskBarInterfacesAvailable != 0 )
  {
    p_m_pTaskbarList3 = &this->m_pTaskbarList3;
    result = this->m_pTaskbarList3;
    if ( result != nullptr )
      return result;
    p_m_bComInitialized = &this->m_bComInitialized;
    if ( this->m_bComInitialized == 0 )
    {
      if ( CoInitialize(pvReserved: nullptr) < 0 )
        return *p_m_pTaskbarList3;
      *p_m_bComInitialized = 1;
    }
    CoCreateInstance(
      rclsid: &CLSID_TaskbarList,
      pUnkOuter: nullptr,
      dwClsContext: 1u,
      riid: &_GUID_ea1afb91_9e28_4b86_90e9_9e9f8a5eefaf,
      ppv: (LPVOID *)p_m_pTaskbarList3);
    return *p_m_pTaskbarList3;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10391E05
// Name: protected: virtual void CPaneFrameWnd::RecalcCaptionHeight(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CPaneFrameWnd::RecalcCaptionHeight(CPaneFrameWnd *this)
{
  CMFCVisualManager *Instance; // eax
  int *p_cy; // edi
  int v4; // eax
  CSize v5; // [esp+8h] [ebp-8h] BYREF

  Instance = CMFCVisualManager::GetInstance();
  p_cy = &Instance->GetCaptionButtonExtraBorder(this: Instance, result: &v5)->cy;
  v4 = *p_cy + GetSystemMetrics(nIndex: 51);
  this->m_nCaptionHeight = v4;
  v4 += 15;
  this->m_sizeMinSize.cy = v4;
  this->m_sizeMinSize.cx = v4;
}

//------------------------------------------------------------------------------
// Address: 0x10391E49
// Name: protected: virtual int CPaneFrameWnd::OnCloseMiniFrame(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CPaneFrameWnd::OnCloseMiniFrame(CPaneFrameWnd *this)
{
  CFrameWnd *TopLevelFrame; // eax
  int v2; // ebx
  CObject *v4; // esi
  CObject *v5; // eax
  CObject *v7; // eax
  CObject *v8; // eax

  TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame;
  v2 = 1;
  if ( g_pTopLevelFrame == nullptr )
    TopLevelFrame = CWnd::GetTopLevelFrame(this);
  v4 = TopLevelFrame;
  if ( TopLevelFrame != nullptr )
  {
    v5 = AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: TopLevelFrame);
    if ( v5 != nullptr )
      return ((int (__thiscall *)(CObject *, CPaneFrameWnd *))v5->__vftable[43].Serialize)(a1: v5, a2: this);
    v7 = AfxDynamicDownCast(pClass: &CFrameWndEx::classCFrameWndEx, pObject: v4);
    if ( v7 != nullptr )
      return ((int (__thiscall *)(CObject *, CPaneFrameWnd *))v7->__vftable[41].GetRuntimeClass)(a1: v7, a2: this);
    v8 = AfxDynamicDownCast(pClass: &COleIPFrameWndEx::classCOleIPFrameWndEx, pObject: v4);
    if ( v8 != nullptr )
      return ((int (__thiscall *)(CObject *, CPaneFrameWnd *))v8->__vftable[43].GetRuntimeClass)(a1: v8, a2: this);
    v8 = AfxDynamicDownCast(pClass: &COleDocIPFrameWndEx::classCOleDocIPFrameWndEx, pObject: v4);
    if ( v8 != nullptr )
      return ((int (__thiscall *)(CObject *, CPaneFrameWnd *))v8->__vftable[43].GetRuntimeClass)(a1: v8, a2: this);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x103AB300
// Name: public: int CMFCToolBar::IsUserDefined(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCToolBar::IsUserDefined(CMFCToolBar *this)
{
  CFrameWnd *TopLevelFrame; // eax
  CObject *v3; // esi
  CObject *v4; // eax
  CFrameImpl *v5; // ecx
  CObject *v7; // eax
  CObject *v8; // eax

  TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame;
  if ( g_pTopLevelFrame == nullptr )
    TopLevelFrame = CWnd::GetTopLevelFrame(this);
  v3 = TopLevelFrame;
  if ( TopLevelFrame != nullptr )
  {
    v4 = AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: TopLevelFrame);
    if ( v4 != nullptr )
    {
      v5 = (CFrameImpl *)&v4[207];
      return CFrameImpl::IsUserDefinedToolbar(this: v5, pToolBar: this);
    }
    v7 = AfxDynamicDownCast(pClass: &CFrameWndEx::classCFrameWndEx, pObject: v3);
    if ( v7 != nullptr )
    {
      v5 = (CFrameImpl *)&v7[73];
      return CFrameImpl::IsUserDefinedToolbar(this: v5, pToolBar: this);
    }
    v8 = AfxDynamicDownCast(pClass: &COleIPFrameWndEx::classCOleIPFrameWndEx, pObject: nullptr);
    if ( v8 != nullptr )
    {
      v5 = (CFrameImpl *)&v8[102];
      return CFrameImpl::IsUserDefinedToolbar(this: v5, pToolBar: this);
    }
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x103AB36F
// Name: protected: long CMFCToolBar::OnGetButtonCount(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::OnGetButtonCount(CMFCToolBar *this, unsigned int __formal, unsigned int __formala)
{
  return this->m_Buttons.m_nCount;
}

//------------------------------------------------------------------------------
// Address: 0x103AB378
// Name: protected: long CMFCToolBar::OnGetItemRect(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::OnGetItemRect(CMFCToolBar *this, unsigned int wParam, tagRECT *lParam)
{
  this->GetItemRect(this, a2: wParam, a3: lParam);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103AB392
// Name: protected: virtual void CMFCToolBar::OnAfterFloat(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnAfterFloat(CMFCToolBar *this)
{
  CPaneFrameWnd *v2; // eax
  _BYTE v3[8]; // [esp+4h] [ebp-8h] BYREF

  CPane::OnAfterFloat(this);
  this->StretchPane(this, result: (CSize *)v3, a3: this->m_nMRUWidth, a4: 0);
  v2 = this->GetParentMiniFrame(this, a2: 0);
  if ( v2 != nullptr )
    v2->SizeToContent(this: v2);
  this->m_bFloating = 1;
}

//------------------------------------------------------------------------------
// Address: 0x103AB3DE
// Name: protected: virtual void CMFCToolBar::OnBeforeChangeParent(class CWnd __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnBeforeChangeParent(CMFCToolBar *this, CWnd *pWndNewParent, CWnd *bDelay)
{
  BOOL v4; // eax

  CPane::OnBeforeChangeParent(this, pWndNewParent, bDelay);
  v4 = pWndNewParent != nullptr
    && CObject::IsKindOf(this: pWndNewParent, pClass: &CPaneFrameWnd::classCPaneFrameWnd) != 0;
  this->m_bFloating = v4;
}

//------------------------------------------------------------------------------
// Address: 0x103AB41A
// Name: public: virtual void CMFCToolBar::EnableDocking(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::EnableDocking(CMFCToolBar *this, unsigned int dwAlignment)
{
  this->m_dwControlBarStyle = 1;
  this->m_dwEnabledAlignment = dwAlignment;
}

//------------------------------------------------------------------------------
// Address: 0x103AB436
// Name: protected: virtual void CMFCToolBar::SaveOriginalState(class CSettingsStore __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::SaveOriginalState(CMFCToolBar *this, CSettingsStore *reg)
{
  if ( this->m_OrigButtons.m_nCount != 0 )
    reg->Write_2(this: reg, a2: "OriginalItems", a3: &this->m_OrigButtons);
}

//------------------------------------------------------------------------------
// Address: 0x103AB45D
// Name: protected: virtual int CMFCToolBar::LoadLastOriginalState(class CSettingsStore __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::LoadLastOriginalState(CMFCToolBar *this, CSettingsStore *reg)
{
  int v3; // ebx
  CSettingsStore_vtbl *v4; // eax
  CObject *v5; // eax
  CObList lstOrigButtons; // [esp+10h] [ebp-28h] BYREF
  int v8; // [esp+34h] [ebp-4h]

  v3 = 0;
  CObList::CObList(this: &lstOrigButtons, nBlockSize: 10);
  v4 = reg->__vftable;
  v8 = 0;
  if ( v4->Read_2(this: reg, a2: "OriginalItems", a3: &lstOrigButtons) != 0 )
    v3 = this->SmartUpdate(this, a2: &lstOrigButtons);
  while ( lstOrigButtons.m_nCount != 0 )
  {
    v5 = CObList::RemoveHead(this: &lstOrigButtons);
    if ( v5 != nullptr )
      ((void (__thiscall *)(CObject *, int))v5->dtr_CObject)(a1: v5, a2: 1);
  }
  v8 = -1;
  CObList::~CObList(this: &lstOrigButtons);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x103AB4CF
// Name: public: static void CMFCToolBar::AddCommandUsage(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall CMFCToolBar::AddCommandUsage(unsigned int uiCommand)
{
  CMFCCmdUsageCount::AddCmd(this: &CMFCToolBar::m_UsageCount, uiCmd: uiCommand);
}

//------------------------------------------------------------------------------
// Address: 0x103AB4DF
// Name: protected: class CMFCToolBarImages __near * CMFCToolBar::GetImageList(class CMFCToolBarImages __near &,class CMFCToolBarImages __near &,class CMFCToolBarImages __near &,class CMFCToolBarImages __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarImages *__thiscall CMFCToolBar::GetImageList(
        CMFCToolBar *this,
        CMFCToolBarImages *images,
        CMFCToolBarImages *imagesLocked,
        CMFCToolBarImages *largeImages,
        CMFCToolBarImages *largeImagesLocked)
{
  CMFCToolBarImages *result; // eax

  if ( this->m_bLocked != 0 )
  {
    if ( this->m_bMenuMode != 0 )
      return imagesLocked;
    if ( CMFCToolBar::m_bLargeIcons == 0 )
      return imagesLocked;
    result = largeImagesLocked;
    if ( largeImagesLocked->m_iCount <= 0 )
      return imagesLocked;
  }
  else
  {
    if ( this->m_bMenuMode != 0 )
      return images;
    if ( CMFCToolBar::m_bLargeIcons == 0 )
      return images;
    result = largeImages;
    if ( largeImages->m_iCount <= 0 )
      return images;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103AB52E
// Name: protected: void CMFCToolBar::SaveResetOriginalState(class CSettingsStore __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::SaveResetOriginalState(CMFCToolBar *this, CSettingsStore *reg)
{
  if ( this->m_OrigResetButtons.m_nCount != 0 )
    reg->Write_2(this: reg, a2: "OrigResetItems", a3: &this->m_OrigResetButtons);
}

//------------------------------------------------------------------------------
// Address: 0x103AB555
// Name: protected: int CMFCToolBar::LoadResetOriginalState(class CSettingsStore __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::LoadResetOriginalState(CMFCToolBar *this, CSettingsStore *reg)
{
  CSettingsStore_vtbl *v3; // eax
  CObject *v5; // eax
  CObList::CNode *m_pNodeHead; // esi
  CObject *data; // edi
  CObList lstOrigButtons; // [esp+10h] [ebp-28h] BYREF
  int v9; // [esp+34h] [ebp-4h]

  CObList::CObList(this: &lstOrigButtons, nBlockSize: 10);
  v3 = reg->__vftable;
  v9 = 0;
  if ( v3->Read_2(this: reg, a2: "OrigResetItems", a3: &lstOrigButtons) != 0 && lstOrigButtons.m_nCount > 0 )
  {
    while ( this->m_OrigResetButtons.m_nCount != 0 )
    {
      v5 = CObList::RemoveHead(this: &this->m_OrigResetButtons);
      if ( v5 != nullptr )
        ((void (__thiscall *)(CObject *, int))v5->dtr_CObject)(a1: v5, a2: 1);
    }
    m_pNodeHead = lstOrigButtons.m_pNodeHead;
    while ( m_pNodeHead != nullptr )
    {
      if ( m_pNodeHead == nullptr )
        AfxThrowInvalidArgException();
      data = m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      if ( data != nullptr && CObject::IsKindOf(this: data, pClass: &CMFCToolBarButton::classCMFCToolBarButton) != 0 )
        CPtrList::AddTail(this: &this->m_OrigResetButtons, newElement: data);
    }
  }
  v9 = -1;
  CObList::~CObList(this: &lstOrigButtons);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103AB601
// Name: public: int CMFCToolBar::IsOneRowWithSibling(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCToolBar::IsOneRowWithSibling(CMFCToolBar *this)
{
  return this->m_pBrotherToolBar->m_pDockBarRow == this->m_pDockBarRow;
}

//------------------------------------------------------------------------------
// Address: 0x103AB619
// Name: public: void CMFCToolBar::SetOneRowWithSibling(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CMFCToolBar::SetOneRowWithSibling(CMFCToolBar *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  CMFCToolBar *m_pBrotherToolBar; // eax
  CDockingPanesRow *m_pDockBarRow; // ebx
  CDockingPanesRow *v6; // edi

  if ( this->m_bHasBrother != 0 )
  {
    m_pBrotherToolBar = this->m_pBrotherToolBar;
    if ( m_pBrotherToolBar != nullptr )
    {
      m_pDockBarRow = m_pBrotherToolBar->m_pDockBarRow;
      v6 = this->m_pDockBarRow;
      if ( v6 != m_pDockBarRow )
      {
        if ( this->m_bElderBrother != 0 )
        {
          ((void (__thiscall *)(CDockingPanesRow *, CMFCToolBar *, int, int))m_pDockBarRow->RemovePane)(
            a1: m_pDockBarRow,
            a2: m_pBrotherToolBar,
            a3,
            a4: a2);
          ((void (__thiscall *)(CDockingPanesRow *, CMFCToolBar *))v6->AddPane)(a1: v6, a2: this->m_pBrotherToolBar);
        }
        else
        {
          ((void (__thiscall *)(CDockingPanesRow *, CMFCToolBar *, int, int))v6->RemovePane)(
            a1: v6,
            a2: this,
            a3,
            a4: a2);
          ((void (__thiscall *)(CDockingPanesRow *, CMFCToolBar *))m_pDockBarRow->AddPane)(a1: m_pDockBarRow, a2: this);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AB680
// Name: public: void CMFCToolBar::SetTwoRowsWithSibling(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::SetTwoRowsWithSibling(CMFCToolBar *this)
{
  CMFCToolBar *m_pBrotherToolBar; // eax
  CDockSite *m_pDockBarRow; // ecx
  CDockingPanesRow *v4; // ebx
  CDockSite *v5; // ebx
  __POSITION *v6; // eax
  CDockingPanesRow *v7; // ebx
  CDockSite *v8; // eax
  CMFCToolBar *v9; // ecx
  CDockSite *v10; // ebx
  __POSITION *v11; // eax
  CDockingPanesRow *v12; // ebx
  CObject *v13; // [esp-Ch] [ebp-24h]
  CSize szBarSize; // [esp+8h] [ebp-10h] BYREF
  CDockSite *pDockBar; // [esp+10h] [ebp-8h]
  void *hdwp; // [esp+14h] [ebp-4h] BYREF

  if ( this->m_bHasBrother != 0 )
  {
    m_pBrotherToolBar = this->m_pBrotherToolBar;
    if ( m_pBrotherToolBar != nullptr )
    {
      m_pDockBarRow = (CDockSite *)m_pBrotherToolBar->m_pDockBarRow;
      v4 = this->m_pDockBarRow;
      pDockBar = m_pDockBarRow;
      if ( v4 == (CDockingPanesRow *)m_pDockBarRow )
      {
        if ( this->m_bElderBrother != 0 )
        {
          ((void (__thiscall *)(CDockSite *, CMFCToolBar *))m_pDockBarRow->GetTypeLib)(a1: m_pDockBarRow, a2: this);
          v5 = this->m_pBrotherToolBar->GetParentDockSite(this: this->m_pBrotherToolBar);
          this->CalcFixedLayout(this, result: &szBarSize, a3: 0, a4: 1);
          v6 = (__POSITION *)CPtrList::Find(this: &v5->m_lstDockBarRows, searchValue: pDockBar, startAfter: nullptr);
          v7 = CDockSite::AddRow(this: v5, posRowBefore: v6, nRowHeight: szBarSize.cy);
          v7->AddPane(this: v7, a2: this, a3: DM_STANDARD, a4: nullptr, a5: 0);
          hdwp = BeginDeferWindowPos(nNumWindows: 10);
          CDockingPanesRow::MovePane(this: v7, pControlBar: this->m_pBrotherToolBar, nAbsolutOffset: 0, __formal: &hdwp);
        }
        else
        {
          v4->RemovePane(this: v4, a2: m_pBrotherToolBar);
          v8 = this->GetParentDockSite(this);
          v9 = this->m_pBrotherToolBar;
          pDockBar = v8;
          v9->CalcFixedLayout(this: v9, result: &szBarSize, a3: 0, a4: 1);
          v13 = v4;
          v10 = pDockBar;
          v11 = (__POSITION *)CPtrList::Find(this: &pDockBar->m_lstDockBarRows, searchValue: v13, startAfter: nullptr);
          v12 = CDockSite::AddRow(this: v10, posRowBefore: v11, nRowHeight: szBarSize.cy);
          v12->AddPane(this: v12, a2: this->m_pBrotherToolBar, a3: DM_STANDARD, a4: nullptr, a5: 0);
          hdwp = BeginDeferWindowPos(nNumWindows: 10);
          CDockingPanesRow::MovePane(this: v12, pControlBar: this, nAbsolutOffset: 0, __formal: &hdwp);
        }
        EndDeferWindowPos(hWinPosInfo: hdwp);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AB7AD
// Name: public: int CMFCToolBar::CanHandleSiblings(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCToolBar::CanHandleSiblings(CMFCToolBar *this)
{
  CMFCToolBar **p_m_pBrotherToolBar; // esi
  CDockSite *v2; // edi
  int v3; // eax
  BOOL result; // eax

  result = false;
  if ( this->m_bHasBrother != 0 )
  {
    p_m_pBrotherToolBar = &this->m_pBrotherToolBar;
    if ( this->m_pBrotherToolBar != nullptr )
    {
      v2 = this->GetParentDockSite(this);
      v3 = (int)(*p_m_pBrotherToolBar)->GetParentDockSite(this: *p_m_pBrotherToolBar);
      if ( v3 != 0 && v2 == (CDockSite *)v3 )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103AB7E9
// Name: public: virtual void CMFCToolBar::OnGlobalFontsChanged(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBar::OnGlobalFontsChanged(CMFCToolBar *this)
{
  CObList::CNode *m_pNodeHead; // esi
  CObject *data; // ecx

  m_pNodeHead = this->m_Buttons.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( data == nullptr )
      AfxThrowInvalidArgException();
    ((void (__thiscall *)(CObject *))data->__vftable[7].Serialize)(a1: data);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103AB814
// Name: protected: int CMFCToolBar::RemoveResetStateButton(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBar::RemoveResetStateButton(CMFCToolBar *this, CObject_vtbl *uiCmdId)
{
  CObList::CNode *m_pNodeHead; // eax
  int i; // edi
  CObject *data; // edx
  CObList *p_m_OrigResetButtons; // esi
  __POSITION *Index; // eax

  m_pNodeHead = this->m_OrigResetButtons.m_pNodeHead;
  for ( i = 0; ; ++i )
  {
    if ( m_pNodeHead == nullptr )
      return 0;
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( data == nullptr )
      AfxThrowInvalidArgException();
    if ( i >= 0 && data[8].__vftable == uiCmdId )
      break;
  }
  if ( i >= this->m_OrigResetButtons.m_nCount )
    return 0;
  p_m_OrigResetButtons = &this->m_OrigResetButtons;
  Index = CStringList::FindIndex(this: (CList<unsigned long,unsigned long> *)&this->m_OrigResetButtons, nIndex: i);
  if ( Index == nullptr )
    return 0;
  CPtrList::RemoveAt(this: p_m_OrigResetButtons, position: Index);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103AB879
// Name: protected: int CMFCToolBar::InsertResetStateButton(class CMFCToolBarButton const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge CMFCToolBar::InsertResetStateButton@<eax>(
        CMFCToolBar *this@<ecx>,
        int a2@<ebx>,
        CMFCToolBarButton *button,
        int iInsertAt)
{
  int result; // eax
  CRuntimeClass *v6; // eax
  CObject *Object; // ebx
  __POSITION *Index; // eax

  result = -1;
  if ( iInsertAt == -1 || iInsertAt >= 0 && iInsertAt <= this->m_OrigResetButtons.m_nCount )
  {
    v6 = (CRuntimeClass *)button->GetRuntimeClass(this: button);
    if ( v6 == nullptr )
      goto LABEL_5;
    Object = CRuntimeClass::CreateObject(this: v6);
    if ( Object == nullptr )
      goto LABEL_5;
    ((void (__thiscall *)(CObject *, CMFCToolBarButton *, int))Object->__vftable[1].Serialize)(
      a1: Object,
      a2: button,
      a3: a2);
    if ( iInsertAt != -1 && iInsertAt != this->m_OrigResetButtons.m_nCount )
    {
      Index = CStringList::FindIndex(
                this: (CList<unsigned long,unsigned long> *)&this->m_OrigResetButtons,
                nIndex: iInsertAt);
      if ( Index != nullptr )
      {
        CObList::InsertBefore(this: &this->m_OrigResetButtons, position: Index, newElement: Object);
        return iInsertAt;
      }
LABEL_5:
      AfxThrowInvalidArgException();
    }
    CPtrList::AddTail(this: &this->m_OrigResetButtons, newElement: Object);
    return this->m_OrigResetButtons.m_nCount - 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103AB908
// Name: public: CList<unsigned int,unsigned int>::CList<unsigned int,unsigned int>(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CList<unsigned int,unsigned int> *__thiscall CList<unsigned int,unsigned int>::CList<unsigned int,unsigned int>(
        CList<unsigned int,unsigned int> *this,
        int nBlockSize)
{
  this->m_nCount = 0;
  this->m_pNodeFree = nullptr;
  this->m_pNodeTail = nullptr;
  this->m_pNodeHead = nullptr;
  this->m_pBlocks = nullptr;
  this->__vftable = (CList<unsigned int,unsigned int>_vtbl *)&CList<unsigned int,unsigned int>::`vftable';
  this->m_nBlockSize = nBlockSize;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103AB930
// Name: public: virtual CList<unsigned int,unsigned int>::~CList<unsigned int,unsigned int>(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CList<unsigned int,unsigned int>::~CList<unsigned int,unsigned int>(
        CList<unsigned int,unsigned int> *this)
{
  this->__vftable = (CList<unsigned int,unsigned int>_vtbl *)&CList<unsigned int,unsigned int>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll((CList<HWND__ *,HWND__ * &> *)this);
}

//------------------------------------------------------------------------------
// Address: 0x103E12C1
// Name: public: virtual long CBasePane::get_accChild(struct tagVARIANT,struct IDispatch __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CBasePane::get_accChild(CBasePane *this, tagVARIANT varChild, IDispatch **ppdispChild)
{
  if ( *ppdispChild == nullptr || varChild.vt == 3 && varChild.decVal.Lo32 == 0 )
    return -2147024809;
  *ppdispChild = this->m_pStdObject;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103E12ED
// Name: public: virtual long CBasePane::get_accRole(struct tagVARIANT,struct tagVARIANT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CBasePane::get_accRole(CBasePane *this, tagVARIANT varChild, tagVARIANT *pvarRole)
{
  if ( varChild.vt == 3 && varChild.decVal.Lo32 == 0 )
  {
    pvarRole->vt = 3;
    pvarRole->decVal.Lo32 = 22;
    return 0;
  }
  if ( pvarRole != nullptr )
  {
    if ( varChild.vt == 3 )
    {
      if ( varChild.lVal > 0 )
      {
        pvarRole->vt = 3;
        this->OnSetAccData(this, a2: varChild.decVal.Lo32);
        pvarRole->decVal.Lo32 = this->m_AccData.m_nAccRole;
        return 0;
      }
LABEL_7:
      pvarRole->vt = 3;
      pvarRole->decVal.Lo32 = 43;
      return 0;
    }
    if ( varChild.decVal.Lo32 == 0 )
      goto LABEL_7;
  }
  return -2147024809;
}

//------------------------------------------------------------------------------
// Address: 0x103E1360
// Name: public: virtual long CBasePane::get_accState(struct tagVARIANT,struct tagVARIANT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CBasePane::get_accState(CBasePane *this, tagVARIANT varChild, tagVARIANT *pvarState)
{
  if ( varChild.vt != 3 || varChild.decVal.Lo32 != 0 )
  {
    if ( pvarState != nullptr && varChild.vt == 3 && varChild.lVal > 0 )
    {
      this->OnSetAccData(this, a2: varChild.decVal.Lo32);
      pvarState->vt = 3;
      pvarState->decVal.Lo32 = this->m_AccData.m_bAccState;
      return 0;
    }
    else
    {
      return -2147024809;
    }
  }
  else
  {
    pvarState->vt = 3;
    pvarState->decVal.Lo32 = 256;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103E13C1
// Name: public: virtual long CBasePane::get_accSelection(struct tagVARIANT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CBasePane::get_accSelection(CBasePane *this, tagVARIANT *pvarChildren)
{
  return pvarChildren != nullptr ? -2147352573 : -2147024809;
}

//------------------------------------------------------------------------------
// Address: 0x103E13DB
// Name: public: virtual long CBasePane::accHitTest(long,long,struct tagVARIANT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HRESULT __thiscall CBasePane::accHitTest(
        CBasePane *this,
        unsigned __int16 xLeft,
        unsigned __int16 yTop,
        tagVARIANT *pvarChild)
{
  bool v6; // zf

  if ( pvarChild == nullptr )
    return -2147024809;
  this->OnSetAccData(this, a2: xLeft | (yTop << 16));
  v6 = this->m_AccData.m_nAccHit == 0;
  pvarChild->vt = 3;
  if ( v6 )
    pvarChild->decVal.Lo32 = 0;
  else
    pvarChild->decVal.Lo32 = xLeft | (yTop << 16);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x103E142A
// Name: public: virtual int CBasePane::CreateEx(unsigned long,char const __near *,char const __near *,unsigned long,struct tagRECT const __near &,class CWnd __near *,unsigned int,unsigned long,struct CCreateContext __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CBasePane::CreateEx(
        CBasePane *this,
        unsigned int dwStyleEx,
        const char *lpszClassName,
        char *lpszWindowName,
        unsigned int dwStyle,
        tagRECT *rect,
        CWnd *pParentWnd,
        unsigned int nID,
        unsigned int dwControlBarStyle,
        CCreateContext *pContext)
{
  int IsKindOf; // eax
  bool v12; // zf
  CFrameWnd *v13; // eax
  CDockingManager *DockingManager; // eax
  CBasePane_vtbl *v15; // eax
  int v16; // eax
  HBRUSH SysColorBrush; // eax
  int v19; // ecx
  CWnd *v20; // eax
  CFrameWnd *v21; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-70h]
  tagCREATESTRUCTA v23; // [esp+Ch] [ebp-5Ch] BYREF
  tagRECT *v24; // [esp+3Ch] [ebp-2Ch]
  void *lpParam; // [esp+40h] [ebp-28h]
  CBasePane_vtbl *v26; // [esp+44h] [ebp-24h]
  char *v27; // [esp+48h] [ebp-20h]
  unsigned int v28; // [esp+4Ch] [ebp-1Ch]
  int bResult; // [esp+50h] [ebp-18h]
  CRect rectWindow; // [esp+54h] [ebp-14h] BYREF

  bResult = (int)lpszClassName;
  v27 = lpszWindowName;
  v24 = rect;
  v28 = nID;
  lpParam = pContext;
  IsKindOf = CObject::IsKindOf(this: pParentWnd, pClass: &CDialog::classCDialog);
  v12 = this->m_bEnableIDChecking == 0;
  this->m_bIsDlgControl = IsKindOf;
  if ( !v12 && CGlobalUtils::GetDockingManager(this: &afxGlobalUtils, pWnd: pParentWnd) == nullptr )
  {
    v13 = AFXGetParentFrame(pWnd: pParentWnd);
    DockingManager = CGlobalUtils::GetDockingManager(this: &afxGlobalUtils, pWnd: v13);
    if ( DockingManager != nullptr )
      DockingManager->FindPaneByID(this: DockingManager, a2: v28, a3: 1);
  }
  v15 = this->__vftable;
  this->m_bVisible &= 0x10000000u;
  v26 = v15;
  v16 = v15->GetPaneStyle(this);
  v26->SetPaneStyle(this, a2: dwStyle | v16);
  v12 = this->m_lpszBarTemplateName == nullptr;
  this->m_dwControlBarStyle = dwControlBarStyle;
  if ( !v12 )
  {
    memset(dst: (unsigned __int8 *)&v23, value: 0, count: sizeof(v23));
    v23.lpszClass = (const char *)bResult;
    v23.lpszName = v27;
    v23.style = dwStyle | 0x40000000;
    v23.hMenu = (HMENU__ *)v28;
    v23.hInstance = AfxGetModuleState()->m_hCurrentInstanceHandle;
    if ( pParentWnd != nullptr )
      v23.hwndParent = pParentWnd->m_hWnd;
    else
      v23.hwndParent = nullptr;
    if ( this->PreCreateWindow(this, a2: &v23) == 0
      || !CWnd::CreateDlg(this, lpszTemplateName: this->m_lpszBarTemplateName, pParentWnd) )
    {
      return 0;
    }
    SysColorBrush = GetSysColorBrush(nIndex: 15);
    SetClassLongA(hWnd: this->m_hWnd, nIndex: -10, dwNewLong: (LONG)SysColorBrush);
    CWnd::SetDlgCtrlID(this, nID: v28);
    m_hWnd = this->m_hWnd;
    memset(&rectWindow, 0, sizeof(rectWindow));
    GetWindowRect(hWnd: m_hWnd, lpRect: &rectWindow);
    v19 = rectWindow.bottom - rectWindow.top;
    this->m_sizeDialog.cx = rectWindow.right - rectWindow.left;
    this->m_sizeDialog.cy = v19;
    bResult = 1;
    goto LABEL_14;
  }
  bResult = CWnd::CreateEx(
              this,
              dwExStyle: dwStyleEx,
              lpszClassName: (const char *)bResult,
              lpszWindowName: v27,
              dwStyle,
              rect: v24,
              pParentWnd,
              nID: (HMENU__ *)v28,
              lpParam);
  if ( bResult != 0 )
  {
LABEL_14:
    if ( CObject::IsKindOf(this: pParentWnd, pClass: &CFrameWnd::classCFrameWnd) != 0 )
    {
      v20 = (CWnd *)AfxDynamicDownCast(pClass: &CFrameWnd::classCFrameWnd, pObject: pParentWnd);
    }
    else
    {
      v21 = AFXGetParentFrame(pWnd: pParentWnd);
      v20 = (CWnd *)AfxDynamicDownCast(pClass: &CFrameWnd::classCFrameWnd, pObject: v21);
    }
    this->m_pDockSite = v20;
    this->m_bIsDlgControl = CObject::IsKindOf(this: pParentWnd, pClass: &CDialog::classCDialog);
  }
  return bResult;
}

//------------------------------------------------------------------------------
// Address: 0x103E1628
// Name: protected: virtual void CBasePane::DoPaint(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CBasePane::DoPaint(CBasePane *this, CDC *pDC)
{
  CDC_vtbl *v2; // eax
  CMFCVisualManager *Instance; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-3Ch]
  CRect rect; // [esp+10h] [ebp-24h] BYREF
  CRect rectClip; // [esp+20h] [ebp-14h] BYREF

  v2 = pDC->__vftable;
  memset(&rectClip, 0, sizeof(rectClip));
  v2->GetClipBox(this: pDC, a2: &rectClip);
  m_hWnd = this->m_hWnd;
  memset(&rect, 0, sizeof(rect));
  GetClientRect(hWnd: m_hWnd, lpRect: &rect);
  Instance = CMFCVisualManager::GetInstance();
  ((void (__thiscall *)(CMFCVisualManager *, CDC *, CBasePane *, int, int, int, int, int, int, int, int, _DWORD))Instance->OnFillBarBackground)(
    a1: Instance,
    a2: pDC,
    a3: this,
    a4: rect.left,
    a5: rect.top,
    a6: rect.right,
    a7: rect.bottom,
    a8: rectClip.left,
    a9: rectClip.top,
    a10: rectClip.right,
    a11: rectClip.bottom,
    a12: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103E16B1
// Name: public: virtual int CBasePane::IsTabbed(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CBasePane::IsTabbed(CBasePane *this)
{
  HWND Parent; // eax
  CWnd *v2; // eax

  Parent = GetParent(hWnd: this->m_hWnd);
  v2 = CWnd::FromHandle(hWnd: Parent);
  return CObject::IsKindOf(this: v2, pClass: &CMFCBaseTabCtrl::classCMFCBaseTabCtrl);
}

//------------------------------------------------------------------------------
// Address: 0x103E16CD
// Name: public: virtual class CPaneFrameWnd __near * CBasePane::GetParentMiniFrame(int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPaneFrameWnd *__thiscall CBasePane::GetParentMiniFrame(CBasePane *this, int bNoAssert)
{
  HWND Parent; // eax
  CWnd *v3; // esi
  HWND v4; // eax
  CPaneFrameWnd *pMiniFrame; // [esp+8h] [ebp-4h]

  pMiniFrame = nullptr;
  Parent = GetParent(hWnd: this->m_hWnd);
  v3 = CWnd::FromHandle(hWnd: Parent);
  if ( v3 != nullptr )
  {
    while ( CObject::IsKindOf(this: v3, pClass: &CPaneFrameWnd::classCPaneFrameWnd) == 0 )
    {
      v4 = GetParent(hWnd: v3->m_hWnd);
      v3 = CWnd::FromHandle(hWnd: v4);
      if ( v3 == nullptr )
        return pMiniFrame;
    }
    return (CPaneFrameWnd *)AfxDynamicDownCast(pClass: &CPaneFrameWnd::classCPaneFrameWnd, pObject: v3);
  }
  return pMiniFrame;
}

//------------------------------------------------------------------------------
// Address: 0x103E172B
// Name: protected: void CBasePane::OnPaint(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CBasePane::OnPaint(CBasePane *this)
{
  CPaintDC v2; // [esp+10h] [ebp-64h] BYREF
  int v3; // [esp+70h] [ebp-4h]

  if ( CBasePane::m_bMultiThreaded != 0 )
    EnterCriticalSection(lpCriticalSection: &CBasePane::m_CriticalSection.m_sect);
  CPaintDC::CPaintDC(this: &v2, pWnd: this);
  v3 = 0;
  if ( (CWnd::GetStyle(this) & 0x10000000) != 0 )
    this->DoPaint(this, a2: &v2);
  if ( CBasePane::m_bMultiThreaded != 0 )
    LeaveCriticalSection(lpCriticalSection: &CBasePane::m_CriticalSection.m_sect);
  v3 = -1;
  CPaintDC::~CPaintDC(this: &v2);
}

//------------------------------------------------------------------------------
// Address: 0x103E4B44
// Name: public: CHelpComboBoxButton::CHelpComboBoxButton(unsigned int,int,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CHelpComboBoxButton *__thiscall CHelpComboBoxButton::CHelpComboBoxButton(
        CHelpComboBoxButton *this,
        unsigned int uiId,
        int iWidth,
        const char *lpszPromt)
{
  CAfxStringMgr *StringManager; // eax
  const char *v6; // eax

  CMFCToolBarComboBoxButton::CMFCToolBarComboBoxButton(this, uiId, iImage: -1, dwStyle: 2u, iWidth);
  this->__vftable = (CHelpComboBoxButton_vtbl *)&CHelpComboBoxButton::`vftable';
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strPrompt, pStringMgr: StringManager);
  v6 = lpszPromt;
  if ( lpszPromt == nullptr )
    v6 = &var;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strPrompt, pszSrc: v6);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103E4BA5
// Name: public: virtual class CEdit __near * CMFCToolBarComboBoxButton::GetEditCtrl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CEdit *__thiscall CMFCToolBarComboBoxButton::GetEditCtrl(CMFCToolBarComboBoxButton *this)
{
  return this->m_pWndEdit;
}

//------------------------------------------------------------------------------
// Address: 0x103E4BAC
// Name: public: virtual struct HWND__ __near * CMFCToolBarComboBoxButton::GetHwnd(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CComboBox *__thiscall CMFCToolBarComboBoxButton::GetHwnd(CMFCToolBarComboBoxButton *this)
{
  CComboBox *result; // eax

  result = this->m_pWndCombo;
  if ( result != nullptr )
    return (CComboBox *)result->m_hWnd;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103E729E
// Name: protected: void CDockablePane::OnContextMenu(class CWnd __near *,class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockablePane::OnContextMenu(CDockablePane *this, CWnd *pWnd, CPoint point)
{
  if ( !this->m_bPrepareToFloat )
  {
    if ( this->m_bCaptionButtonsCaptured != 0 )
      this->StopCaptionButtonsTracking(this);
    CPane::OnContextMenu(this: &this->CPane, __formal: pWnd, point);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103E72D5
// Name: public: virtual void CDockablePane::ToggleAutoHide(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockablePane::ToggleAutoHide(CDockablePane *this)
{
  CPaneDivider *DefaultPaneDivider; // ebx
  CDockablePane_vtbl *v3; // edi
  int v4; // eax

  DefaultPaneDivider = CDockablePane::GetDefaultPaneDivider(this);
  if ( this->CanAutoHide((CBasePane *)this) != 0 && DefaultPaneDivider != nullptr )
  {
    v3 = this->__vftable;
    v4 = ((int (__thiscall *)(CPaneDivider *, _DWORD, int))DefaultPaneDivider->GetCurrentAlignment)(
           a1: DefaultPaneDivider,
           a2: 0,
           a3: 1);
    ((void (__thiscall *)(CDockablePane *, bool, int))v3->SetAutoHideMode)(a1: this, a2: this->m_bPinState == 0, a3: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103E731E
// Name: public: virtual void CDockablePane::CopyState(class CDockablePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockablePane::CopyState(CDockablePane *this, CDockablePane *pOrgBar)
{
  CDockablePane *v2; // edi

  v2 = this;
  CPane::CopyState(this: &this->CPane, pOrgBar: &pOrgBar->CPane);
  v2 = (CDockablePane *)((char *)v2 + 760);
  v2->__vftable = (CDockablePane_vtbl *)pOrgBar->m_rectRestored.left;
  v2 = (CDockablePane *)((char *)v2 + 4);
  v2->__vftable = (CDockablePane_vtbl *)pOrgBar->m_rectRestored.top;
  v2 = (CDockablePane *)((char *)v2 + 4);
  v2->__vftable = (CDockablePane_vtbl *)pOrgBar->m_rectRestored.right;
  v2->m_dwRef = pOrgBar->m_rectRestored.bottom;
  this->m_ahSlideMode = pOrgBar->GetAHSlideMode(this: pOrgBar);
  this->m_nLastPercent = pOrgBar->m_nLastPercent;
  this->m_bEnableAutoHideAll = pOrgBar->IsAutohideAllEnabled(this: pOrgBar);
}

//------------------------------------------------------------------------------
// Address: 0x103EEC6A
// Name: public: virtual CDialogEx::~CDialogEx(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDialogEx::~CDialogEx(CDialogEx *this)
{
  CDialogImpl::~CDialogImpl(this: &this->m_Impl);
  this->m_brBkgr.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  CGdiObject::~CGdiObject(this: &this->m_brBkgr);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x103EECB3
// Name: public: CDialogEx::CDialogEx(unsigned int,class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDialogEx *__thiscall CDialogEx::CDialogEx(CDialogEx *this, unsigned int nIDTemplate, CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate, pParentWnd: pParent);
  this->__vftable = (CDialogEx_vtbl *)&CDialogEx::`vftable';
  this->m_sizeBkgrBitmap.cx = 0;
  this->m_sizeBkgrBitmap.cy = 0;
  this->m_brBkgr.m_hObject = nullptr;
  this->m_brBkgr.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
  CDialogImpl::CDialogImpl(this: &this->m_Impl, dlg: this);
  CDialogEx::CommonConstruct(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103EED38
// Name: protected: struct HBRUSH__ __near * CDialogEx::OnCtlColor(class CDC __near *,class CWnd __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWnd *__thiscall CDialogEx::OnCtlColor(CDialogEx *this, CDC *pDC, CWnd *pWnd, unsigned int nCtlColor)
{
  HWND__ *m_hWnd; // eax
  void *m_hObject; // esi
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v8; // [esp+18h] [ebp-114h] BYREF
  CHAR ClassName[268]; // [esp+1Ch] [ebp-110h] BYREF
  int v10; // [esp+128h] [ebp-4h]

  m_hWnd = nullptr;
  if ( (this == (CDialogEx *)-160 || this->m_brBkgr.m_hObject == nullptr) && this->m_hBkgrBitmap == nullptr
    || nCtlColor != 6 )
  {
    return CWnd::OnCtlColor(this, __formal: pDC, pWnd, a4: nCtlColor);
  }
  if ( pWnd != nullptr )
    m_hWnd = pWnd->m_hWnd;
  GetClassNameA(hWnd: m_hWnd, lpClassName: ClassName, nMaxCount: 255);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &v8,
    pszSrc: ClassName);
  v10 = 0;
  if ( ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(this: &v8, psz: "Button") != 0
    && ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Compare(this: &v8, psz: "Static") != 0 )
  {
    v10 = -1;
    ATL::CStringData::Release(this: (ATL::CStringData *)v8.m_pszData - 1);
    return CWnd::OnCtlColor(this, __formal: pDC, pWnd, a4: nCtlColor);
  }
  CDC::SetBkMode(this: pDC, nBkMode: 1);
  if ( this != (CDialogEx *)-160 && this->m_brBkgr.m_hObject != nullptr && CThemeHelper::IsAppThemed() != 0 )
    m_hObject = this->m_brBkgr.m_hObject;
  else
    m_hObject = GetStockObject(i: 5);
  ATL::CStringData::Release(this: (ATL::CStringData *)v8.m_pszData - 1);
  return (CWnd *)m_hObject;
}

//------------------------------------------------------------------------------
// Address: 0x103EEE43
// Name: protected: static struct AFX_MSGMAP const __near * CDialogEx::GetThisMessageMap(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CDialogEx::GetThisMessageMap(CDialogEx *this)
{
  return &messageMap_43;
}

//------------------------------------------------------------------------------
// Address: 0x103EEE49
// Name: public: virtual struct CRuntimeClass __near * CMFCCustomizeMenuButton::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCCustomizeMenuButton::GetRuntimeClass(CMFCCustomizeMenuButton *this)
{
  return &CMFCCustomizeMenuButton::classCMFCCustomizeMenuButton;
}

//------------------------------------------------------------------------------
// Address: 0x103EEE4F
// Name: public: CMFCCustomizeMenuButton::CMFCCustomizeMenuButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCCustomizeMenuButton *__thiscall CMFCCustomizeMenuButton::CMFCCustomizeMenuButton(CMFCCustomizeMenuButton *this)
{
  CMFCToolBarMenuButton::CMFCToolBarMenuButton(this);
  this->__vftable = (CMFCCustomizeMenuButton_vtbl *)&CMFCCustomizeMenuButton::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103EEE63
// Name: public: virtual CMFCCustomizeMenuButton::~CMFCCustomizeMenuButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCCustomizeMenuButton::~CMFCCustomizeMenuButton(CMFCCustomizeMenuButton *this)
{
  this->__vftable = (CMFCCustomizeMenuButton_vtbl *)&CMFCCustomizeMenuButton::`vftable';
  CMFCToolBarMenuButton::~CMFCToolBarMenuButton(this);
}

//------------------------------------------------------------------------------
// Address: 0x103EEE6E
// Name: public: CMFCCustomizeMenuButton::CMFCCustomizeMenuButton(unsigned int,struct HMENU__ __near *,int,char const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCCustomizeMenuButton *__thiscall CMFCCustomizeMenuButton::CMFCCustomizeMenuButton(
        CMFCCustomizeMenuButton *this,
        unsigned int uiID,
        HMENU__ *hMenu,
        int iImage,
        const char *lpszText,
        int bUserButton)
{
  CMFCToolBarMenuButton::CMFCToolBarMenuButton(this, uiID, hMenu, iImage, lpszText, bUserButton);
  this->m_uiIndex = -1;
  this->bSeparator = 0;
  this->m_bAddSpr = 0;
  this->m_bBrothersBtn = 0;
  this->__vftable = (CMFCCustomizeMenuButton_vtbl *)&CMFCCustomizeMenuButton::`vftable';
  this->m_bIsEnabled = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103EEEBC
// Name: public: void CMFCCustomizeMenuButton::SetItemIndex(unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCCustomizeMenuButton::SetItemIndex(
        CMFCCustomizeMenuButton *this,
        unsigned int uiIndex,
        int bExist,
        int bAddSpr)
{
  this->m_bAddSpr = bAddSpr;
  this->m_uiIndex = uiIndex;
  this->m_bExist = bExist;
  if ( uiIndex == 17016 || this->bSeparator != 0 || bExist == 0 )
  {
    this->m_bShow = 0;
    if ( uiIndex == 17016 && CMFCToolBar::IsUserDefined(this: CMFCCustomizeMenuButton::m_pWndToolBar) )
      this->m_bIsEnabled = 0;
  }
  else
  {
    this->m_bShow = CMFCToolBar::GetButton(this: CMFCCustomizeMenuButton::m_pWndToolBar, nIndex: uiIndex)->m_bVisible;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103EEF32
// Name: protected: virtual void CMFCCustomizeMenuButton::CopyFrom(class CMFCToolBarButton const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCCustomizeMenuButton::CopyFrom(CMFCCustomizeMenuButton *this, const CMFCToolBarButton *s)
{
  CMFCToolBarButton::CopyFrom(this, src: s);
  this->m_uiIndex = s[2].m_bText;
  this->m_bShow = s[2].m_bImage;
  this->bSeparator = s[2].m_bWrap;
  this->m_bExist = s[2].m_bWholeText;
  this->m_bAddSpr = s[2].m_bTextBelow;
  this->m_bIsEnabled = s[2].m_bDragFromCollection;
  this->m_bBrothersBtn = s[2].m_nID;
}

//------------------------------------------------------------------------------
// Address: 0x103EEF9E
// Name: protected: virtual void CMFCCustomizeMenuButton::OnDraw(class CDC __near *,class CRect const __near &,class CMFCToolBarImages __near *,int,int,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCCustomizeMenuButton::OnDraw(
        CMFCCustomizeMenuButton *this,
        CDC *pDC,
        const CRect *rect,
        CMFCToolBarImages *pImages,
        int bHorz,
        int bCustomizeMode,
        int bHighlight,
        int bDrawBorder,
        int bGrayDisabledButtons)
{
  CMFCVisualManager *Instance; // esi
  CSize *MenuImageSize; // edi
  int v12; // eax
  CWnd *m_pWndParent; // ebx
  CMFCVisualManager *v14; // eax
  CMFCVisualManager *v15; // eax
  CMFCVisualManager *v16; // eax
  int v17; // esi
  CSize *v18; // eax
  CMFCVisualManager *v19; // eax
  CMFCVisualManager *v20; // eax
  int v21; // eax
  CMFCVisualManager *v22; // eax
  int v23; // eax
  unsigned int v24; // [esp-4h] [ebp-78h]
  CSize v25; // [esp+Ch] [ebp-68h] BYREF
  CSize result; // [esp+14h] [ebp-60h] BYREF
  CSize sizeMenuImage; // [esp+1Ch] [ebp-58h] BYREF
  CRect rcHighlight; // [esp+24h] [ebp-50h]
  CMFCToolBarImages *v29; // [esp+34h] [ebp-40h]
  CRect rcSeparator; // [esp+38h] [ebp-3Ch]
  int bIsResetItem; // [esp+48h] [ebp-2Ch]
  CDC *v32; // [esp+4Ch] [ebp-28h]
  CRect rectStdMenu; // [esp+50h] [ebp-24h] BYREF
  CRect rectCheck; // [esp+60h] [ebp-14h] BYREF

  v29 = pImages;
  v32 = pDC;
  if ( this->bSeparator != 0 )
  {
    rcSeparator = *rect;
    Instance = CMFCVisualManager::GetInstance();
    MenuImageSize = CMFCToolBar::GetMenuImageSize(&result);
    v12 = Instance->GetMenuImageMargin(this: Instance);
    m_pWndParent = this->m_pWndParent;
    rcSeparator.left = v12 + 2 * MenuImageSize->cx;
    if ( m_pWndParent == nullptr )
      AfxThrowInvalidArgException();
    v14 = CMFCVisualManager::GetInstance();
    ((void (__thiscall *)(CMFCVisualManager *, CDC *, CWnd *, int, int, int, int, _DWORD))v14->OnDrawSeparator)(
      a1: v14,
      a2: v32,
      a3: m_pWndParent,
      a4: rcSeparator.left,
      a5: rcSeparator.top,
      a6: rcSeparator.right,
      a7: rcSeparator.bottom,
      a8: 0);
  }
  else if ( this->m_bBrothersBtn != 0 )
  {
    CMFCToolBarMenuButton::OnDraw(
      this,
      pDC,
      rect,
      pImages: nullptr,
      bHorz,
      bCustomizeMode,
      bHighlight,
      bDrawBorder,
      bGrayDisabledButtons);
  }
  else
  {
    rcSeparator.left = rect->left;
    rcSeparator.top = rect->top;
    rcSeparator.right = rect->right;
    rcSeparator.bottom = rect->bottom - 1;
    if ( this->m_bIsEnabled != 0 )
    {
      if ( this->m_bShow != 0 && bHighlight != 0 )
        v24 = 0x10000;
      else
        v24 = 0;
      this->SetStyle(this, a2: v24);
    }
    else
    {
      this->SetStyle(this, a2: 0x40000u);
      bGrayDisabledButtons = 1;
      bHighlight = 0;
    }
    bIsResetItem = this->m_uiIndex == 17016;
    if ( bIsResetItem != 0 )
    {
      this->m_iImage = -1;
      this->m_bImage = 0;
    }
    if ( bHighlight != 0 && this->m_bIsEnabled != 0 )
    {
      rcHighlight.top = rcSeparator.top;
      rcHighlight.bottom = rcSeparator.bottom;
      rcHighlight.right = rcSeparator.right - 1;
      rcHighlight.left = rcSeparator.left + 2;
      v15 = CMFCVisualManager::GetInstance();
      if ( v15->IsHighlightWholeMenuItem(this: v15) == 0 && bIsResetItem == 0 )
      {
        v16 = CMFCVisualManager::GetInstance();
        v17 = 5 * v16->GetMenuImageMargin(this: v16);
        v18 = CMFCToolBar::GetMenuImageSize(result: &v25);
        rcHighlight.left += v17 + 2 * v18->cx;
      }
      v19 = CMFCVisualManager::GetInstance();
      ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCCustomizeMenuButton *, int, int, int, int, int *))v19->OnHighlightMenuItem)(
        a1: v19,
        a2: v32,
        a3: this,
        a4: rcHighlight.left,
        a5: rcHighlight.top,
        a6: rcHighlight.right,
        a7: rcHighlight.bottom,
        a8: &result.cy);
    }
    CMFCToolBar::GetMenuImageSize(result: &sizeMenuImage);
    rectCheck = rcSeparator;
    v20 = CMFCVisualManager::GetInstance();
    v21 = v20->GetMenuImageMargin(this: v20);
    rectCheck.left += v21 + 1;
    v22 = CMFCVisualManager::GetInstance();
    v23 = v22->GetMenuImageMargin(this: v22);
    --rectCheck.bottom;
    rectCheck.right = sizeMenuImage.cx + v23 + rectCheck.left + 2;
    this->DrawCheckBox(this, a2: v32, a3: &rectCheck, a4: bHighlight);
    if ( bHighlight != 0 && (this->m_nStyle & 0x40000) == 0 && bIsResetItem == 0 )
      this->SetStyle(this, a2: 0);
    rectStdMenu.top = rcSeparator.top;
    rectStdMenu.right = rcSeparator.right;
    rectStdMenu.bottom = rcSeparator.bottom;
    rectStdMenu.left = rectCheck.right;
    CMFCToolBarMenuButton::DrawMenuItem(
      this,
      pDC: v32,
      rect: &rectStdMenu,
      pImages: v29,
      bCustomizeMode,
      bHighlight,
      bGrayDisabledButtons,
      bContentOnly: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103EF1F8
// Name: protected: virtual void CMFCCustomizeMenuButton::DrawCheckBox(class CDC __near *,class CRect const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCCustomizeMenuButton::DrawCheckBox(
        CMFCCustomizeMenuButton *this,
        CDC *pDC,
        const CRect *rect,
        int bHighlight)
{
  CMFCVisualManager *Instance; // eax
  CMFCVisualManager *v6; // eax
  CMFCVisualManager *v7; // eax
  unsigned int m_nStyle; // [esp+Ch] [ebp-1Ch]
  CRect rectCheck; // [esp+14h] [ebp-14h] BYREF

  if ( this->m_bShow != 0 )
  {
    rectCheck = *rect;
    ++rectCheck.top;
    --rectCheck.right;
    --rectCheck.bottom;
    Instance = CMFCVisualManager::GetInstance();
    if ( Instance->IsOwnerDrawMenuCheck(this: Instance) == 0 )
    {
      m_nStyle = this->m_nStyle;
      this->m_nStyle = m_nStyle | 0x10000;
      CMFCToolBarButton::FillInterior(this, pDC, rect: &rectCheck, bHighlight, bMenuImage: 1);
      if ( bHighlight != 0 && CMFCVisualManager::GetInstance()->m_bFrameMenuCheckedItems != 0 )
        this->m_nStyle |= 0x800000u;
      v6 = CMFCVisualManager::GetInstance();
      ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCCustomizeMenuButton *, int, int, int, int, int))v6->OnDrawButtonBorder)(
        a1: v6,
        a2: pDC,
        a3: this,
        a4: rectCheck.left,
        a5: rectCheck.top,
        a6: rectCheck.right,
        a7: rectCheck.bottom,
        a8: 1);
      this->m_nStyle = m_nStyle;
    }
    v7 = CMFCVisualManager::GetInstance();
    ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCCustomizeMenuButton *, int, int, int, int, int, _DWORD))v7->OnDrawMenuCheck)(
      a1: v7,
      a2: pDC,
      a3: this,
      a4: rectCheck.left,
      a5: rectCheck.top,
      a6: rectCheck.right,
      a7: rectCheck.bottom,
      a8: bHighlight,
      a9: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103EF2E0
// Name: public: static class CObject __near * CMFCCustomizeMenuButton::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCCustomizeMenuButton *__stdcall CMFCCustomizeMenuButton::CreateObject()
{
  CMFCCustomizeMenuButton *v0; // ecx
  CMFCCustomizeMenuButton *result; // eax

  v0 = (CMFCCustomizeMenuButton *)operator new(nSize: 0x104u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCCustomizeMenuButton::CMFCCustomizeMenuButton(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103EF337
// Name: protected: void CMFCCustomizeMenuButton::UpdateCustomizeButton(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCCustomizeMenuButton::UpdateCustomizeButton(CMFCCustomizeMenuButton *this)
{
  HWND Parent; // eax
  CWnd *v2; // eax
  HWND v3; // eax
  CWnd *v4; // eax

  Parent = GetParent(hWnd: CMFCCustomizeMenuButton::m_pWndToolBar->m_hWnd);
  v2 = CWnd::FromHandle(hWnd: Parent);
  if ( v2 != nullptr && v2->m_hWnd != nullptr )
  {
    v3 = GetParent(hWnd: CMFCCustomizeMenuButton::m_pWndToolBar->m_hWnd);
    v4 = CWnd::FromHandle(hWnd: v3);
    RedrawWindow(hWnd: v4->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x505u);
  }
  CMFCToolBar::RedrawCustomizeButton(this: CMFCCustomizeMenuButton::m_pWndToolBar);
}

//------------------------------------------------------------------------------
// Address: 0x103EF386
// Name: protected: virtual int CMFCCustomizeMenuButton::OnClickMenuItem(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCCustomizeMenuButton::OnClickMenuItem(CMFCCustomizeMenuButton *this)
{
  CMFCToolBar *m_pWndParent; // ebx
  int v3; // eax
  __POSITION *Index; // eax
  const CMFCToolBarButton *v6; // eax
  CMFCToolBarButton *v7; // eax
  unsigned int m_bText; // edx
  bool v9; // zf
  CMFCToolBarButton *Button; // eax
  BOOL v11; // ecx
  unsigned int v12; // edi
  int v13; // edi
  CMFCToolBarButton *v14; // eax
  CWnd *v15; // edi
  HWND Parent; // eax
  CWnd *v17; // eax
  CMFCPopupMenu *ParentPopupMenu; // eax
  HWND m_hWnd; // [esp-8h] [ebp-34h]
  unsigned int m_uiIndex; // [esp-4h] [ebp-30h]
  int nCount; // [esp+Ch] [ebp-20h]
  int nCounta; // [esp+Ch] [ebp-20h]
  unsigned int nNewIndex; // [esp+10h] [ebp-1Ch]
  const CMFCToolBarButton *i; // [esp+14h] [ebp-18h]
  int ia; // [esp+14h] [ebp-18h]
  CRect rectScreen; // [esp+18h] [ebp-14h] BYREF

  if ( this->bSeparator != 0 || this->m_bIsEnabled == 0 )
    return 1;
  m_pWndParent = (CMFCToolBar *)this->m_pWndParent;
  if ( m_pWndParent == nullptr )
    goto LABEL_4;
  v3 = CMFCToolBar::ButtonToIndex(this: m_pWndParent, pButton: this);
  if ( v3 != -1 && m_pWndParent->m_iHighlighted != v3 )
  {
    m_pWndParent->m_iHighlighted = v3;
    InvalidateRect(hWnd: m_pWndParent->m_hWnd, lpRect: &this->m_rect, bErase: true);
  }
  if ( this->m_bBrothersBtn != 0 )
  {
    if ( CMFCToolBar::IsOneRowWithSibling(this: CMFCCustomizeMenuButton::m_pWndToolBar) )
      CMFCToolBar::SetTwoRowsWithSibling(this: CMFCCustomizeMenuButton::m_pWndToolBar);
    else
      CMFCToolBar::SetOneRowWithSibling(this: CMFCCustomizeMenuButton::m_pWndToolBar, a2: (int)m_pWndParent, a3: 1);
    return 0;
  }
  if ( this->m_uiIndex == 17016 )
  {
    PostMessageA(hWnd: CMFCCustomizeMenuButton::m_pWndToolBar->m_hWnd, Msg: AFX_WM_RESETRPROMPT, wParam: 0, lParam: 0);
    return 0;
  }
  m_uiIndex = this->m_uiIndex;
  if ( this->m_bExist != 0 )
  {
    Button = CMFCToolBar::GetButton(this: CMFCCustomizeMenuButton::m_pWndToolBar, nIndex: m_uiIndex);
    v11 = Button->m_bVisible == 0;
    Button->m_bVisible = v11;
    v12 = this->m_uiIndex;
    nCounta = v11;
    this->m_bShow = v11;
    v13 = v12 + 1;
    if ( v13 < CMFCToolBar::GetCount(this: CMFCCustomizeMenuButton::m_pWndToolBar) )
    {
      v14 = CMFCToolBar::GetButton(this: CMFCCustomizeMenuButton::m_pWndToolBar, nIndex: v13);
      if ( (v14->m_nStyle & 1) != 0 )
        v14->m_bVisible = nCounta;
    }
    v15 = nullptr;
    Parent = GetParent(hWnd: m_pWndParent->m_hWnd);
    v17 = CWnd::FromHandle(hWnd: Parent);
    ParentPopupMenu = (CMFCPopupMenu *)AfxDynamicDownCast(pClass: &CMFCPopupMenu::classCMFCPopupMenu, pObject: v17);
    if ( ParentPopupMenu != nullptr )
    {
      do
      {
        v15 = ParentPopupMenu;
        ParentPopupMenu = CMFCPopupMenu::GetParentPopupMenu(this: ParentPopupMenu);
      }
      while ( ParentPopupMenu != nullptr );
      CWnd::ShowWindow(this: v15, nCmdShow: 0);
    }
    CMFCCustomizeMenuButton::m_pWndToolBar->AdjustLayout(this: CMFCCustomizeMenuButton::m_pWndToolBar);
    CMFCCustomizeMenuButton::m_pWndToolBar->AdjustSizeImmediate(this: CMFCCustomizeMenuButton::m_pWndToolBar, a2: 1);
    CMFCCustomizeMenuButton::UpdateCustomizeButton(this);
    InvalidateRect(hWnd: m_pWndParent->m_hWnd, lpRect: nullptr, bErase: true);
    if ( v15 != nullptr )
    {
      CWnd::ShowWindow(this: v15, nCmdShow: 4);
      m_hWnd = v15->m_hWnd;
      memset(&rectScreen, 0, sizeof(rectScreen));
      GetWindowRect(hWnd: m_hWnd, lpRect: &rectScreen);
      CMFCPopupMenu::UpdateAllShadows(lprectScreen: &rectScreen);
    }
    return 1;
  }
  Index = CStringList::FindIndex(
            this: (CList<unsigned long,unsigned long> *)&CMFCCustomizeMenuButton::m_pWndToolBar->m_OrigResetButtons,
            nIndex: m_uiIndex);
  if ( Index == nullptr )
LABEL_4:
    AfxThrowInvalidArgException();
  v6 = *(const CMFCToolBarButton **)&Index[8];
  i = v6;
  if ( v6 != nullptr )
  {
    nNewIndex = CMFCCustomizeMenuButton::m_pWndToolBar->InsertButton(
                  this: CMFCCustomizeMenuButton::m_pWndToolBar,
                  a2: v6,
                  a3: this->m_uiIndex);
    if ( nNewIndex == -1 )
    {
      nNewIndex = CMFCCustomizeMenuButton::m_pWndToolBar->InsertButton(
                    this: CMFCCustomizeMenuButton::m_pWndToolBar,
                    a2: i,
                    a3: -1);
    }
    else
    {
      ia = 0;
      nCount = CMFCToolBar::GetCount(this: m_pWndParent);
      if ( nCount > 0 )
      {
        do
        {
          v7 = CMFCToolBar::GetButton(this: m_pWndParent, nIndex: ia);
          m_bText = v7[2].m_bText;
          if ( m_bText >= nNewIndex && m_bText != 17016 && v7[2].m_bWholeText != 0 )
            v7[2].m_bText = m_bText + 1;
          ++ia;
        }
        while ( ia < nCount );
      }
    }
    v9 = this->m_bAddSpr == 0;
    this->m_uiIndex = nNewIndex;
    if ( !v9
      && (nNewIndex >= CMFCToolBar::GetCount(this: CMFCCustomizeMenuButton::m_pWndToolBar)
       || (CMFCToolBar::GetButton(this: CMFCCustomizeMenuButton::m_pWndToolBar, nIndex: nNewIndex + 1)->m_nStyle & 1) == 0) )
    {
      CMFCCustomizeMenuButton::m_pWndToolBar->InsertSeparator(this: CMFCCustomizeMenuButton::m_pWndToolBar, a2: -1);
    }
    CMFCCustomizeMenuButton::m_pWndToolBar->AdjustLayout(this: CMFCCustomizeMenuButton::m_pWndToolBar);
    CMFCCustomizeMenuButton::m_pWndToolBar->AdjustSizeImmediate(this: CMFCCustomizeMenuButton::m_pWndToolBar, a2: 1);
    CMFCCustomizeMenuButton::UpdateCustomizeButton(this);
    this->m_bExist = 1;
    this->m_bShow = 1;
    InvalidateRect(hWnd: m_pWndParent->m_hWnd, lpRect: nullptr, bErase: true);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103EF684
// Name: protected: virtual struct tagSIZE CMFCCustomizeMenuButton::OnCalculateSize(class CDC __near *,class CSize const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDC *__thiscall CMFCCustomizeMenuButton::OnCalculateSize(
        CMFCCustomizeMenuButton *this,
        CDC *pDC,
        CSize *sizeDefault,
        HDC__ *bHorz,
        int a5)
{
  CDC *result; // eax
  CAfxStringMgr *StringManager; // eax
  unsigned int m_nID; // ebx
  HINSTANCE__ *StringResourceHandle; // eax
  int v10; // eax
  ATL::CStringData *v11; // eax
  int v12; // eax
  ATL::CStringData *v13; // eax
  unsigned int v14; // eax
  int v15; // eax
  ATL::CStringData *v16; // eax
  CAfxStringMgr *v17; // eax
  CWnd *m_pWndParent; // ecx
  CWnd *MainWnd; // eax
  CFrameWnd *TopLevelFrame; // eax
  CFrameWnd *v21; // ebx
  CFrameWnd *v22; // eax
  int v23; // ebx
  int v24; // esi
  int v25; // esi
  CMFCVisualManager *Instance; // eax
  int v27; // ebx
  int cx; // eax
  int v29; // esi
  bool v30; // zf
  CMFCVisualManager *v31; // eax
  CSize v32; // [esp+10h] [ebp-70h] BYREF
  CDC v33; // [esp+18h] [ebp-68h] BYREF
  CDC *v34; // [esp+28h] [ebp-58h]
  CSize *v35; // [esp+2Ch] [ebp-54h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v36; // [esp+30h] [ebp-50h] BYREF
  ATL::CSimpleStringT<char,0> v37; // [esp+34h] [ebp-4Ch] BYREF
  tagTEXTMETRICA tm; // [esp+38h] [ebp-48h] BYREF
  int v39; // [esp+7Ch] [ebp-4h]

  v34 = pDC;
  v35 = sizeDefault;
  v33.m_hDC = bHorz;
  v33.m_bPrinting = a5;
  if ( this->bSeparator != 0 )
  {
    pDC->__vftable = nullptr;
    pDC->m_hDC = (HDC__ *)4;
    return pDC;
  }
  if ( this->m_bBrothersBtn != 0 )
  {
    CMFCToolBarMenuButton::OnCalculateSize(this, pDC, sizeDefault, (int)bHorz);
    return pDC;
  }
  if ( *((_DWORD *)this->m_strText.m_pszData - 3) != 0 )
  {
    v12 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(this: &this->m_strText, ch: 9u, iStart: 0);
    if ( v12 != -1 )
    {
      v13 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Left(
                                  this: &this->m_strText,
                                  result: &v36,
                                  nCount: v12);
      v39 = 2;
      ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strText, strSrc: v13);
      v39 = -1;
      ATL::CStringData::Release(this: (ATL::CStringData *)v36.m_pszData - 1);
    }
  }
  else
  {
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v37, pStringMgr: StringManager);
    v39 = 0;
    m_nID = this->m_nID;
    StringResourceHandle = AfxFindStringResourceHandle(__formal: m_nID);
    if ( StringResourceHandle != nullptr
      && ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
           this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v37,
           hInstance: StringResourceHandle,
           nID: m_nID) != 0 )
    {
      v10 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(
              this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v37,
              ch: 0xAu,
              iStart: 0);
      if ( v10 != -1 )
      {
        v11 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Mid(
                                    this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v37,
                                    result: &v36,
                                    iFirst: v10 + 1);
        LOBYTE(v39) = 1;
        ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strText, strSrc: v11);
        ATL::CStringData::Release(this: (ATL::CStringData *)v36.m_pszData - 1);
      }
    }
    v39 = -1;
    ATL::CStringData::Release(this: (ATL::CStringData *)v37.m_pszData - 1);
  }
  if ( afxKeyboardManager != nullptr && this->m_bMenuMode != 0 )
  {
    v14 = this->m_nID;
    if ( v14 < 0xF000 || v14 >= 0xF1F0 )
    {
      v15 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Find(
              this: &this->m_strText,
              ch: 9u,
              iStart: 0);
      if ( v15 >= 0 )
      {
        v16 = (ATL::CStringData *)ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Left(
                                    this: &this->m_strText,
                                    result: &v36,
                                    nCount: v15);
        v39 = 3;
        ATL::CSimpleStringT<char,0>::operator=(this: &this->m_strText, strSrc: v16);
        v39 = -1;
        ATL::CStringData::Release(this: (ATL::CStringData *)v36.m_pszData - 1);
      }
      v17 = AfxGetStringManager();
      ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v37, pStringMgr: v17);
      m_pWndParent = this->m_pWndParent;
      v39 = 4;
      if ( m_pWndParent != nullptr )
      {
        TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame;
        if ( g_pTopLevelFrame == nullptr )
          TopLevelFrame = CWnd::GetTopLevelFrame(this: m_pWndParent);
      }
      else
      {
        MainWnd = AfxGetMainWnd();
        TopLevelFrame = (CFrameWnd *)AfxDynamicDownCast(pClass: &CFrameWnd::classCFrameWnd, pObject: MainWnd);
      }
      v21 = TopLevelFrame;
      if ( TopLevelFrame != nullptr )
      {
        if ( CKeyboardManager::FindDefaultAccelerator(
               uiCmd: this->m_nID,
               str: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v37,
               pWndFrame: TopLevelFrame,
               bIsDefaultFrame: (char *)1) != 0
          || (v22 = v21->GetActiveFrame(this: v21),
              CKeyboardManager::FindDefaultAccelerator(
                uiCmd: this->m_nID,
                str: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v37,
                pWndFrame: v22,
                bIsDefaultFrame: nullptr) != 0) )
        {
          ATL::CSimpleStringT<char,0>::AppendChar(this: &this->m_strText, ch: 9);
          ATL::CSimpleStringT<char,0>::Append(
            this: &this->m_strText,
            pszSrc: v37.m_pszData,
            nLength: *((_DWORD *)v37.m_pszData - 3));
        }
      }
      v39 = -1;
      ATL::CStringData::Release(this: (ATL::CStringData *)v37.m_pszData - 1);
    }
  }
  v23 = *((_DWORD *)this->m_strText.m_pszData - 3);
  GetTextMetricsA(hdc: (HDC)v35[1].cx, lptm: &tm);
  v24 = v23 * tm.tmAveCharWidth;
  CMFCToolBar::GetMenuButtonSize(result: &v32);
  v25 = v24 + 2 * v32.cx;
  Instance = CMFCVisualManager::GetInstance();
  v27 = v25 + 3 * Instance->GetMenuImageMargin(this: Instance) + 50;
  cx = CMFCToolBarMenuButton::OnCalculateSize(this, pDC: &v33, sizeDefault: v35, bHorz: (int)v33.m_hDC).cx;
  v29 = *(_DWORD *)(cx + 4) + 2;
  v30 = this->m_bMenuMode == 0;
  v33.m_hAttribDC = *(HDC__ **)cx;
  if ( v30 )
  {
    v31 = CMFCVisualManager::GetInstance();
    v29 += v31->GetMenuImageMargin(this: v31);
  }
  result = v34;
  v34->__vftable = (CDC_vtbl *)v27;
  result->m_hDC = (HDC__ *)v29;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103EF923
// Name: public: virtual struct CRuntimeClass __near * CMFCRibbonMiniToolBar::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCRibbonMiniToolBar::GetRuntimeClass(CMFCRibbonMiniToolBar *this)
{
  return &CMFCRibbonMiniToolBar::classCMFCRibbonMiniToolBar;
}

//------------------------------------------------------------------------------
// Address: 0x103EF929
// Name: public: virtual CMFCRibbonMiniToolBar::~CMFCRibbonMiniToolBar(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonMiniToolBar::~CMFCRibbonMiniToolBar(CMFCRibbonMiniToolBar *this)
{
  this->__vftable = (CMFCRibbonMiniToolBar_vtbl *)&CMFCRibbonMiniToolBar::`vftable';
  CMFCRibbonMiniToolBar::m_pCurrent = nullptr;
  if ( this->m_bContextMenuMode != 0 )
    afxContextMenuManager->m_bDontCloseActiveMenu = 0;
  CMFCRibbonPanelMenu::~CMFCRibbonPanelMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x103EF94C
// Name: public: virtual class CMFCPopupMenuBar __near * CMFCRibbonPanelMenu::GetMenuBar(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCColorBar *__thiscall CMFCRibbonPanelMenu::GetMenuBar(CMFCColorPopupMenu *this)
{
  return &this->m_wndColorBar;
}

//------------------------------------------------------------------------------
// Address: 0x103EF953
// Name: public: virtual int CMFCRibbonPanelMenu::DefaultMouseClickOnClose(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __thiscall CMFCRibbonPanelMenu::DefaultMouseClickOnClose(CMFCRibbonPanelMenu *this)
{
  BOOL result; // eax

  result = false;
  if ( this->m_wndRibbonBar.m_bIsFloaty != 0 )
    return this->m_wndRibbonBar.m_bIsQATPopup == 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103EF967
// Name: public: CMFCRibbonMiniToolBar::CMFCRibbonMiniToolBar(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonMiniToolBar *__thiscall CMFCRibbonMiniToolBar::CMFCRibbonMiniToolBar(CMFCRibbonMiniToolBar *this)
{
  CMFCRibbonPanelMenu::CMFCRibbonPanelMenu(this);
  this->__vftable = (CMFCRibbonMiniToolBar_vtbl *)&CMFCRibbonMiniToolBar::`vftable';
  if ( CMFCRibbonMiniToolBar::m_pCurrent != nullptr )
  {
    SendMessageA(hWnd: CMFCRibbonMiniToolBar::m_pCurrent->m_hWnd, Msg: 0x10u, wParam: 0, lParam: 0);
    CMFCRibbonMiniToolBar::m_pCurrent = nullptr;
  }
  this->m_wndRibbonBar.m_bIsFloaty = 1;
  this->m_bDisableAnimation = 1;
  this->m_bContextMenuMode = 0;
  this->m_nTransparency = 0;
  this->m_bWasHovered = 0;
  this->m_bWasDroppedDown = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103EF9E3
// Name: protected: int CMFCRibbonMiniToolBar::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonMiniToolBar::OnCreate(CMFCRibbonMiniToolBar *this, tagCREATESTRUCTA *lpCreateStruct)
{
  int result; // eax

  if ( this->m_bContextMenuMode == 0 && (CWnd::GetExStyle(this) & 0x400000) != 0 )
    this->m_iShadowSize = 0;
  result = CMFCPopupMenu::OnCreate(this, lpCreateStruct);
  if ( result != -1 )
  {
    if ( this->m_bContextMenuMode == 0 )
      SetTimer(hWnd: this->m_hWnd, nIDEvent: 1u, uElapse: 0x64u, lpTimerFunc: nullptr);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103EFA39
// Name: protected: int CMFCRibbonMiniToolBar::UpdateTransparency(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonMiniToolBar::UpdateTransparency(CMFCRibbonMiniToolBar *this)
{
  CMFCRibbonPanel *m_pPanel; // ecx
  int v3; // edi
  int v4; // edx
  int v5; // ecx
  int v6; // eax
  int result; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-3Ch]
  CPoint ptCursor; // [esp+Ch] [ebp-28h] BYREF
  int nDistance; // [esp+14h] [ebp-20h]
  int fMaxShowDistance; // [esp+18h] [ebp-1Ch]
  unsigned __int8 nTransparency; // [esp+1Fh] [ebp-15h]
  CRect rect; // [esp+20h] [ebp-14h] BYREF

  m_hWnd = this->m_hWnd;
  memset(&rect, 0, sizeof(rect));
  GetWindowRect(hWnd: m_hWnd, lpRect: &rect);
  ptCursor.x = 0;
  ptCursor.y = 0;
  GetCursorPos(lpPoint: &ptCursor);
  m_pPanel = this->m_wndRibbonBar.m_pPanel;
  nTransparency = 0;
  if ( CMFCRibbonPanel::GetDroppedDown(this: m_pPanel) != nullptr
    || CMFCRibbonPanel::GetHighlighted(this: this->m_wndRibbonBar.m_pPanel) != nullptr
    || CMFCRibbonPanel::GetPressed(this: this->m_wndRibbonBar.m_pPanel) != nullptr )
  {
    nTransparency = -1;
    if ( this->m_bWasDroppedDown == 0 || !PtInRect(lprc: &rect, pt: ptCursor.tagPOINT) )
      goto LABEL_25;
    goto LABEL_24;
  }
  if ( PtInRect(lprc: &rect, pt: ptCursor.tagPOINT) )
  {
    this->m_bWasHovered = 1;
    nTransparency = -1;
LABEL_24:
    this->m_bWasDroppedDown = 0;
    goto LABEL_25;
  }
  if ( this->m_bWasDroppedDown != 0 )
  {
    nTransparency = -1;
  }
  else
  {
    v3 = 0;
    v4 = 0;
    if ( ptCursor.x >= rect.left )
    {
      if ( ptCursor.x > rect.right )
        v3 = ptCursor.x - rect.right;
    }
    else
    {
      v3 = rect.left - ptCursor.x;
    }
    if ( ptCursor.y >= rect.top )
    {
      if ( ptCursor.y > rect.bottom )
        v4 = ptCursor.y - rect.bottom;
    }
    else
    {
      v4 = rect.top - ptCursor.y;
    }
    nDistance = v3;
    if ( v3 <= v4 )
      nDistance = v4;
    v5 = this->m_bWasHovered != 0 ? 66 : 22;
    v6 = this->m_bWasHovered != 0 ? 176 : 44;
    fMaxShowDistance = v5;
    if ( nDistance > v6 )
    {
      PostMessageA(hWnd: this->m_hWnd, Msg: 0x10u, wParam: 0, lParam: 0);
      return 0;
    }
    if ( nDistance < v5 )
    {
      *(float *)&fMaxShowDistance = (float)fMaxShowDistance;
      *(float *)&fMaxShowDistance = (*(float *)&fMaxShowDistance - (double)nDistance) / *(float *)&fMaxShowDistance;
      nTransparency = (unsigned __int64)(*(float *)&fMaxShowDistance * 255.0);
    }
  }
LABEL_25:
  result = 0;
  if ( this->m_nTransparency != nTransparency )
  {
    this->m_nTransparency = nTransparency;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103EFBDB
// Name: public: static class CObject __near * CMFCRibbonMiniToolBar::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCRibbonMiniToolBar *__stdcall CMFCRibbonMiniToolBar::CreateObject()
{
  CMFCRibbonMiniToolBar *v0; // ecx
  CMFCRibbonMiniToolBar *result; // eax

  v0 = (CMFCRibbonMiniToolBar *)operator new(nSize: 0x1F10u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCRibbonMiniToolBar::CMFCRibbonMiniToolBar(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103EFC0B
// Name: protected: void CMFCRibbonMiniToolBar::OnTimer(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonMiniToolBar::OnTimer(CMFCRibbonMiniToolBar *this, unsigned int nIDEvent)
{
  CMFCRibbonPanel *m_pPanel; // ecx

  CMFCPopupMenu::OnTimer(this, nIDEvent);
  if ( nIDEvent == 1 )
  {
    if ( this->m_bContextMenuMode != 0 )
    {
      KillTimer(hWnd: this->m_hWnd, uIDEvent: 1u);
    }
    else
    {
      m_pPanel = this->m_wndRibbonBar.m_pPanel;
      if ( m_pPanel != nullptr && CMFCRibbonPanel::GetDroppedDown(this: m_pPanel) != nullptr )
      {
        this->m_bWasDroppedDown = 1;
      }
      else if ( CMFCRibbonMiniToolBar::UpdateTransparency(this) != 0 )
      {
        SetLayeredWindowAttributes(hwnd: this->m_hWnd, crKey: 0, bAlpha: this->m_nTransparency, dwFlags: 2u);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103EFC7B
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCRibbonMiniToolBar::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCRibbonMiniToolBar::GetMessageMap(CMFCRibbonMiniToolBar *this)
{
  return (const AFX_MSGMAP *)&off_10688734;
}

//------------------------------------------------------------------------------
// Address: 0x103EFC81
// Name: public: virtual struct CRuntimeClass __near * CMFCToolBarsMenuPropertyPage::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCToolBarsMenuPropertyPage::GetRuntimeClass(CMFCToolBarsMenuPropertyPage *this)
{
  return &CMFCToolBarsMenuPropertyPage::classCMFCToolBarsMenuPropertyPage;
}

//------------------------------------------------------------------------------
// Address: 0x103EFC87
// Name: protected: virtual void CMFCToolBarsMenuPropertyPage::DoDataExchange(class CDataExchange __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsMenuPropertyPage::DoDataExchange(CMFCToolBarsMenuPropertyPage *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x409F, rControl: (HWND__ *)&this->m_wndMenuAnimationsLabel);
  DDX_Control(pDX, nIDC: (HWND__ *)0x40F1, rControl: (HWND__ *)&this->m_wndMenuAnimations);
  DDX_Control(pDX, nIDC: (HWND__ *)0x40F2, rControl: (HWND__ *)&this->m_wndMenuShadows);
  DDX_Control(pDX, nIDC: (HWND__ *)0x4088, rControl: (HWND__ *)&this->m_wndContextFrame);
  DDX_Control(pDX, nIDC: (HWND__ *)0x4087, rControl: (HWND__ *)&this->m_wndContextHint);
  DDX_Control(pDX, nIDC: (HWND__ *)0x40EF, rControl: (HWND__ *)&this->m_wndResetMenuButton);
  DDX_Control(pDX, nIDC: (HWND__ *)0x407C, rControl: (HWND__ *)&this->m_wndContextMenuCaption);
  DDX_Control(pDX, nIDC: (HWND__ *)0x40EE, rControl: (HWND__ *)&this->m_wndContextMenus);
  DDX_Control(pDX, nIDC: (HWND__ *)0x407B, rControl: (HWND__ *)&this->m_wndIcon);
  DDX_Control(pDX, nIDC: (HWND__ *)0x40ED, rControl: (HWND__ *)&this->m_wndMenuesList);
  DDX_Text(pDX, nIDC: (HWND__ *)0x407A, value: &this->m_strMenuDescr);
  DDX_CBString((HWND__ *)pDX, nIDC: (HWND__ *)0x40EE, value: &this->m_strContextMenuName);
  DDX_CBString((HWND__ *)pDX, nIDC: (HWND__ *)0x40ED, value: &this->m_strMenuName);
  DDX_CBIndex((HWND__ *)pDX, nIDC: (HWND__ *)0x40F1, index: &this->m_iMenuAnimationType);
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x40F2, value: &this->m_bMenuShadows);
}

//------------------------------------------------------------------------------
// Address: 0x103EFDA6
// Name: protected: void CMFCToolBarsMenuPropertyPage::SaveMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsMenuPropertyPage::SaveMenu(CMFCToolBarsMenuPropertyPage *this)
{
  CMFCPopupMenu *m_pContextMenu; // eax
  CMFCPopupMenuBar *v3; // eax
  CRect rectMenu; // [esp+4h] [ebp-14h] BYREF

  m_pContextMenu = this->m_pContextMenu;
  if ( m_pContextMenu != nullptr )
  {
    memset(&rectMenu, 0, sizeof(rectMenu));
    GetWindowRect(hWnd: m_pContextMenu->m_hWnd, lpRect: &rectMenu);
    CMFCToolBarsMenuPropertyPage::m_ptMenuLastPos.x = rectMenu.left;
    CMFCToolBarsMenuPropertyPage::m_ptMenuLastPos.y = rectMenu.top;
    v3 = this->m_pContextMenu->GetMenuBar(this: this->m_pContextMenu);
    CMenuHash::SaveMenuBar(this: &afxMenuHash, hMenu: this->m_pContextMenu->m_hMenu, pBar: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103EFE22
// Name: protected: void CMFCToolBarsMenuPropertyPage::OnDestroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsMenuPropertyPage::OnDestroy(CMFCToolBarsMenuPropertyPage *this)
{
  LRESULT v2; // eax
  CMFCPopupMenu::ANIMATION_TYPE m_iMenuAnimationType; // ecx
  CMFCMenuBar *m_pMenuBar; // eax
  HMENU__ *m_hmenuCurr; // eax
  CMFCPopupMenuBar *v6; // eax

  CWnd::UpdateData(this, bSaveAndValidate: 1);
  v2 = SendMessageA(hWnd: this->m_wndMenuAnimations.m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0);
  m_iMenuAnimationType = this->m_iMenuAnimationType;
  CMFCPopupMenu::m_AnimationType = SYSTEM_DEFAULT_ANIMATION;
  if ( m_iMenuAnimationType != v2 - 1 )
    CMFCPopupMenu::m_AnimationType = m_iMenuAnimationType;
  m_pMenuBar = this->m_pMenuBar;
  if ( m_pMenuBar != nullptr )
  {
    m_pMenuBar->m_pMenuPage = nullptr;
    if ( this->m_hmenuSelected != nullptr )
    {
      this->m_pMenuBar->OnChangeHot(this: this->m_pMenuBar, a2: -1);
      CMenuHash::SaveMenuBar(this: &afxMenuHash, hMenu: this->m_hmenuSelected, pBar: this->m_pMenuBar);
    }
    m_hmenuCurr = this->m_hmenuCurr;
    if ( m_hmenuCurr != nullptr )
      this->m_pMenuBar->CreateFromMenu(this: this->m_pMenuBar, a2: m_hmenuCurr, a3: 0, a4: 0);
  }
  if ( this->m_pContextMenu != nullptr )
  {
    v6 = this->m_pContextMenu->GetMenuBar(this: this->m_pContextMenu);
    SendMessageA(hWnd: v6->m_hWnd, Msg: 0x1Fu, wParam: 0, lParam: 0);
    CMFCToolBarsMenuPropertyPage::SaveMenu(this);
    SendMessageA(hWnd: this->m_pContextMenu->m_hWnd, Msg: 0x10u, wParam: 0, lParam: 0);
  }
  CMFCMenuBar::m_bMenuShadows = this->m_bMenuShadows;
  CWnd::OnDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x103EFF05
// Name: protected: void CMFCToolBarsMenuPropertyPage::OnSelchangeContextMenuList(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsMenuPropertyPage::OnSelchangeContextMenuList(CMFCToolBarsMenuPropertyPage *this)
{
  CMFCPopupMenu *m_pContextMenu; // eax
  HMENU__ *MenuByName; // eax
  CMFCPopupMenu *v4; // ecx
  CMFCPopupMenu *v5; // eax
  CMFCPopupMenu_vtbl *v6; // ebx
  CFrameWnd *TopLevelFrame; // eax
  CButton *p_m_wndResetMenuButton; // [esp+14h] [ebp-14h]
  HMENU__ *hmenuPopup; // [esp+18h] [ebp-10h]
  CPoint v10; // 0:^4.8

  p_m_wndResetMenuButton = &this->m_wndResetMenuButton;
  CWnd::EnableWindow(this: &this->m_wndResetMenuButton, bEnable: 0);
  if ( afxContextMenuManager != nullptr )
  {
    this->m_uiContextMenuResId = 0;
    if ( this->m_pContextMenu != nullptr )
    {
      CMFCToolBarsMenuPropertyPage::SaveMenu(this);
      m_pContextMenu = this->m_pContextMenu;
      this->m_pContextMenu = nullptr;
      SendMessageA(hWnd: m_pContextMenu->m_hWnd, Msg: 0x10u, wParam: 0, lParam: 0);
    }
    if ( SendMessageA(hWnd: this->m_wndContextMenus.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0) > 0 )
    {
      CWnd::UpdateData(this, bSaveAndValidate: 1);
      MenuByName = CContextMenuManager::GetMenuByName(
                     this: afxContextMenuManager,
                     lpszName: (__POSITION *)this->m_strContextMenuName.m_pszData,
                     puiOrigResID: (HMENU__ *)&this->m_uiContextMenuResId);
      if ( MenuByName != nullptr )
      {
        hmenuPopup = GetSubMenu(hMenu: MenuByName, nPos: 0);
        if ( hmenuPopup != nullptr )
        {
          v4 = (CMFCPopupMenu *)operator new(nSize: 0x10C4u);
          if ( v4 != nullptr )
            v5 = CMFCPopupMenu::CMFCPopupMenu(
                   this: v4,
                   pCustPage: this,
                   lpszTitle: this->m_strContextMenuName.m_pszData);
          else
            v5 = nullptr;
          this->m_pContextMenu = v5;
          if ( v5 == nullptr )
            AfxThrowInvalidArgException();
          v5->m_bAutoDestroy = 0;
          v10 = CMFCToolBarsMenuPropertyPage::m_ptMenuLastPos;
          v6 = this->m_pContextMenu->__vftable;
          TopLevelFrame = CWnd::GetTopLevelFrame(this);
          if ( v6->Create(
                 this: this->m_pContextMenu,
                 a2: TopLevelFrame,
                 a3: v10.x,
                 a4: v10.y,
                 a5: hmenuPopup,
                 a6: 0,
                 a7: 0) != 0 )
            CWnd::EnableWindow(this: p_m_wndResetMenuButton, bEnable: 1);
          else
            AfxMessageBox(lpszText: "Can't create context menu!", nType: 0, nIDHelp: 0);
        }
      }
      else
      {
        MessageBeep(uType: 0xFFFFFFFF);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F004C
// Name: public: void CMFCToolBarsMenuPropertyPage::CloseContextMenu(class CMFCPopupMenu __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsMenuPropertyPage::CloseContextMenu(
        CMFCToolBarsMenuPropertyPage *this,
        CMFCPopupMenu *pMenu)
{
  CMFCPopupMenu *m_pContextMenu; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-18h]

  m_pContextMenu = this->m_pContextMenu;
  if ( m_pContextMenu != nullptr )
  {
    if ( m_pContextMenu != pMenu )
      AfxThrowInvalidArgException();
    CMFCToolBarsMenuPropertyPage::SaveMenu(this);
    if ( this->m_pContextMenu != nullptr )
    {
      m_hWnd = this->m_wndContextMenus.m_hWnd;
      this->m_pContextMenu = nullptr;
      SendMessageA(hWnd: m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
      CWnd::EnableWindow(this: &this->m_wndResetMenuButton, bEnable: 0);
    }
    this->m_uiContextMenuResId = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F00A9
// Name: public: virtual CMFCToolBarsMenuPropertyPage::~CMFCToolBarsMenuPropertyPage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsMenuPropertyPage::~CMFCToolBarsMenuPropertyPage(CMFCToolBarsMenuPropertyPage *this)
{
  this->__vftable = (CMFCToolBarsMenuPropertyPage_vtbl *)&CMFCToolBarsMenuPropertyPage::`vftable';
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strMenuName.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strContextMenuName.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)this->m_strMenuDescr.m_pszData - 1);
  CComboBox::~CComboBox(this: &this->m_wndMenuesList);
  CComboBox::~CComboBox(this: &this->m_wndContextMenus);
  CComboBox::~CComboBox(this: &this->m_wndMenuAnimations);
  CButton::~CButton(this: &this->m_wndResetMenuButton);
  CButton::~CButton(this: &this->m_wndContextFrame);
  CButton::~CButton(this: &this->m_wndMenuShadows);
  CStatic::~CStatic(this: &this->m_wndIcon);
  CStatic::~CStatic(this: &this->m_wndContextMenuCaption);
  CStatic::~CStatic(this: &this->m_wndContextHint);
  CStatic::~CStatic(this: &this->m_wndMenuAnimationsLabel);
  CPropertyPage::~CPropertyPage(this);
}

//------------------------------------------------------------------------------
// Address: 0x103F01B5
// Name: protected: void CMFCToolBarsMenuPropertyPage::OnResetMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsMenuPropertyPage::OnResetMenu(CMFCToolBarsMenuPropertyPage *this)
{
  CAfxStringMgr *StringManager; // eax
  char *v3; // edi
  int v4; // eax
  ATL::CStringData *v5; // ecx
  CMFCPopupMenuBar *v6; // ebx
  CMFCPopupMenuBar_vtbl *v7; // edi
  HMENU SubMenu; // eax
  CFrameWnd *m_pParentFrame; // eax
  CMFCPopupMenuBar *v10; // eax
  char *m_pszData; // [esp-4h] [ebp-24h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strPrompt; // [esp+10h] [ebp-10h] BYREF
  int v13; // [esp+1Ch] [ebp-4h]

  if ( afxContextMenuManager != nullptr )
  {
    if ( this->m_pContextMenu == nullptr )
      AfxThrowInvalidArgException();
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strPrompt, pStringMgr: StringManager);
    m_pszData = this->m_strContextMenuName.m_pszData;
    v13 = 0;
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: &strPrompt,
      nFormatID: 0x3EF1u,
      m_pszData);
    v3 = strPrompt.m_pszData;
    v4 = AfxMessageBox(lpszText: strPrompt.m_pszData, nType: 0x24u, nIDHelp: 0);
    v5 = (ATL::CStringData *)(v3 - 16);
    if ( v4 == 6 )
    {
      v13 = -1;
      ATL::CStringData::Release(this: v5);
      strPrompt.m_pszData = (char *)CContextMenuManager::GetMenuByName(
                                      this: afxContextMenuManager,
                                      lpszName: (__POSITION *)this->m_strContextMenuName.m_pszData,
                                      puiOrigResID: (HMENU__ *)&this->m_uiContextMenuResId);
      if ( strPrompt.m_pszData != nullptr )
      {
        v6 = this->m_pContextMenu->GetMenuBar(this: this->m_pContextMenu);
        v7 = v6->__vftable;
        SubMenu = GetSubMenu(hMenu: (HMENU)strPrompt.m_pszData, nPos: 0);
        v7->ImportFromMenu(this: v6, a2: SubMenu, a3: 0);
        m_pParentFrame = this->m_pParentFrame;
        if ( m_pParentFrame != nullptr )
          SendMessageA(
            hWnd: m_pParentFrame->m_hWnd,
            Msg: AFX_WM_RESETCONTEXTMENU,
            wParam: this->m_uiContextMenuResId,
            lParam: (LPARAM)this->m_pContextMenu);
        CMFCToolBarsMenuPropertyPage::OnSelchangeContextMenuList(this);
        this->m_pContextMenu->RecalcLayout(this: this->m_pContextMenu, a2: 1);
        v10 = this->m_pContextMenu->GetMenuBar(this: this->m_pContextMenu);
        InvalidateRect(hWnd: v10->m_hWnd, lpRect: nullptr, bErase: true);
      }
      else
      {
        MessageBeep(uType: 0xFFFFFFFF);
      }
    }
    else
    {
      ATL::CStringData::Release(this: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F02E3
// Name: protected: void CMFCToolBarsMenuPropertyPage::OnResetFrameMenu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsMenuPropertyPage::OnResetFrameMenu(CMFCToolBarsMenuPropertyPage *this)
{
  CAfxStringMgr *StringManager; // eax
  int v3; // eax
  ATL::CStringData *v4; // ecx
  LRESULT v5; // edi
  HINSTANCE__ *m_hCurrentResourceHandle; // eax
  bool v7; // zf
  HMENU MenuW; // eax
  CFrameWnd *m_pParentFrame; // eax
  unsigned int m_uiDefMenuResId; // edi
  HINSTANCE__ *v11; // eax
  HMENU__ *v12; // edi
  CFrameWnd *v13; // eax
  CFrameWnd *v14; // ecx
  HMENU__ *v15; // edi
  char *m_pszData; // [esp-4h] [ebp-28h]
  WPARAM uiDefMenuResId; // [esp+10h] [ebp-14h]
  unsigned int uiDefMenuResIda; // [esp+10h] [ebp-14h]
  WPARAM uiDefMenuResIdb; // [esp+10h] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strPrompt; // [esp+14h] [ebp-10h] BYREF
  int v21; // [esp+20h] [ebp-4h]

  CWnd::UpdateData(this, bSaveAndValidate: 1);
  if ( this->m_pMenuBar != nullptr )
  {
    uiDefMenuResId = SendMessageA(hWnd: this->m_wndMenuesList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
    if ( uiDefMenuResId != -1 )
    {
      StringManager = AfxGetStringManager();
      ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strPrompt, pStringMgr: StringManager);
      m_pszData = this->m_strMenuName.m_pszData;
      v21 = 0;
      ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
        this: &strPrompt,
        nFormatID: 0x3EF1u,
        m_pszData);
      v3 = AfxMessageBox(lpszText: strPrompt.m_pszData, nType: 0x24u, nIDHelp: 0);
      v4 = (ATL::CStringData *)(strPrompt.m_pszData - 16);
      if ( v3 == 6 )
      {
        v21 = -1;
        ATL::CStringData::Release(this: v4);
        strPrompt.m_pszData = nullptr;
        v5 = SendMessageA(hWnd: this->m_wndMenuesList.m_hWnd, Msg: 0x150u, wParam: uiDefMenuResId, lParam: 0);
        if ( v5 != 0 )
        {
          m_hCurrentResourceHandle = AfxGetModuleState()->m_hCurrentResourceHandle;
          v7 = *(HMENU__ **)(v5 + 136) == this->m_hmenuCurr;
          strPrompt.m_pszData = *(char **)(v5 + 136);
          uiDefMenuResIda = v7;
          MenuW = LoadMenuW(hInstance: m_hCurrentResourceHandle, lpMenuName: (LPCWSTR)*(unsigned __int16 *)(v5 + 84));
          *(_DWORD *)(v5 + 136) = MenuW;
          this->m_pMenuBar->CreateFromMenu(this: this->m_pMenuBar, a2: MenuW, a3: 0, a4: 0);
          CMFCMenuBar::UpdateMDIChildrenMenus(pTemplate: (CMultiDocTemplate *)v5);
          m_pParentFrame = this->m_pParentFrame;
          if ( m_pParentFrame != nullptr
            && SendMessageA(
                 hWnd: m_pParentFrame->m_hWnd,
                 Msg: AFX_WM_RESETMENU,
                 wParam: *(_DWORD *)(v5 + 84),
                 lParam: 0) != 0 )
          {
            this->m_pMenuBar->AdjustLayout(this: this->m_pMenuBar);
          }
          CMenuHash::SaveMenuBar(this: &afxMenuHash, hMenu: *(HMENU__ **)(v5 + 136), pBar: this->m_pMenuBar);
          if ( uiDefMenuResIda != 0 )
            this->m_hmenuCurr = *(HMENU__ **)(v5 + 136);
        }
        else
        {
          m_uiDefMenuResId = this->m_pMenuBar->m_uiDefMenuResId;
          uiDefMenuResIdb = m_uiDefMenuResId;
          if ( m_uiDefMenuResId != 0 )
          {
            v11 = AfxGetModuleState()->m_hCurrentResourceHandle;
            strPrompt.m_pszData = (char *)this->m_pMenuBar->m_hDefaultMenu;
            v12 = LoadMenuW(hInstance: v11, lpMenuName: (LPCWSTR)(unsigned __int16)m_uiDefMenuResId);
            this->m_pMenuBar->OnDefaultMenuLoaded(this: this->m_pMenuBar, a2: v12);
            this->m_pMenuBar->CreateFromMenu(this: this->m_pMenuBar, a2: v12, a3: 1, a4: 0);
            v13 = this->m_pParentFrame;
            if ( v13 != nullptr )
            {
              if ( SendMessageA(hWnd: v13->m_hWnd, Msg: AFX_WM_RESETMENU, wParam: uiDefMenuResIdb, lParam: 0) != 0 )
                this->m_pMenuBar->AdjustLayout(this: this->m_pMenuBar);
              this->m_pParentFrame->m_hMenuDefault = v12;
            }
            CMenuHash::SaveMenuBar(this: &afxMenuHash, hMenu: v12, pBar: this->m_pMenuBar);
            if ( this->m_bIsDefaultMDIMenu != 0 )
              this->m_hmenuCurr = v12;
          }
        }
        v14 = this->m_pParentFrame;
        if ( v14 != nullptr )
          v14->OnUpdateFrameMenu(this: v14, a2: this->m_hmenuCurr);
        v15 = (HMENU__ *)strPrompt.m_pszData;
        if ( strPrompt.m_pszData != nullptr )
        {
          if ( !IsMenu(hMenu: (HMENU)strPrompt.m_pszData) )
            AfxThrowInvalidArgException();
          CMenuHash::RemoveMenu(this: &afxMenuHash, hMenu: v15);
          DestroyMenu(hMenu: v15);
        }
        InvalidateRect(hWnd: this->m_pMenuBar->m_hWnd, lpRect: nullptr, bErase: true);
        UpdateWindow(hWnd: this->m_pMenuBar->m_hWnd);
      }
      else
      {
        ATL::CStringData::Release(this: v4);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F0559
// Name: public: CMFCToolBarsMenuPropertyPage::CMFCToolBarsMenuPropertyPage(class CFrameWnd __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarsMenuPropertyPage *__thiscall CMFCToolBarsMenuPropertyPage::CMFCToolBarsMenuPropertyPage(
        CMFCToolBarsMenuPropertyPage *this,
        CFrameWnd *pParentFrame,
        int bAutoSet)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v5; // eax
  CAfxStringMgr *v6; // eax

  CPropertyPage::CPropertyPage(this, nIDTemplate: 0x3F06u, nIDCaption: 0, dwSize: 0x38u);
  this->__vftable = (CMFCToolBarsMenuPropertyPage_vtbl *)&CMFCToolBarsMenuPropertyPage::`vftable';
  CWnd::CWnd(this: &this->m_wndMenuAnimationsLabel);
  this->m_wndMenuAnimationsLabel.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_wndContextHint);
  this->m_wndContextHint.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_wndContextMenuCaption);
  this->m_wndContextMenuCaption.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_wndIcon);
  this->m_wndIcon.__vftable = (CStatic_vtbl *)&CStatic::`vftable';
  CWnd::CWnd(this: &this->m_wndMenuShadows);
  this->m_wndMenuShadows.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_wndContextFrame);
  this->m_wndContextFrame.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_wndResetMenuButton);
  this->m_wndResetMenuButton.__vftable = (CButton_vtbl *)&CButton::`vftable';
  CWnd::CWnd(this: &this->m_wndMenuAnimations);
  this->m_wndMenuAnimations.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  CWnd::CWnd(this: &this->m_wndContextMenus);
  this->m_wndContextMenus.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  CWnd::CWnd(this: &this->m_wndMenuesList);
  this->m_wndMenuesList.__vftable = (CComboBox_vtbl *)&CComboBox::`vftable';
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strMenuDescr, pStringMgr: StringManager);
  v5 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strContextMenuName, pStringMgr: v5);
  v6 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &this->m_strMenuName, pStringMgr: v6);
  this->m_pParentFrame = pParentFrame;
  this->m_bAutoSet = bAutoSet;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strMenuDescr, pszSrc: &var);
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strContextMenuName, pszSrc: &var);
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strMenuName, pszSrc: &var);
  this->m_iMenuAnimationType = CMFCPopupMenu::m_AnimationType;
  this->m_bMenuShadows = CMFCMenuBar::m_bMenuShadows;
  this->m_pMenuBar = nullptr;
  this->m_hmenuCurr = nullptr;
  this->m_hmenuSelected = nullptr;
  this->m_pContextMenu = nullptr;
  this->m_bIsDefaultMDIMenu = 0;
  this->m_uiContextMenuResId = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103F0721
// Name: protected: void CMFCToolBarsMenuPropertyPage::OnSelchangeMenuList(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarsMenuPropertyPage::OnSelchangeMenuList(CMFCToolBarsMenuPropertyPage *this)
{
  CMFCMenuBar *m_pMenuBar; // ecx
  WPARAM v3; // eax
  LRESULT v4; // eax
  LRESULT v5; // edi
  AFX_MODULE_STATE *ModuleState; // eax
  HMENU__ *m_hDefaultMenu; // edi
  HINSTANCE__ *StringResourceHandle; // eax
  CWnd *MainWnd; // eax
  HICON__ *hicon; // [esp+8h] [ebp-4h]
  HICON__ *hicona; // [esp+8h] [ebp-4h]

  CWnd::UpdateData(this, bSaveAndValidate: 1);
  m_pMenuBar = this->m_pMenuBar;
  if ( m_pMenuBar != nullptr )
  {
    if ( this->m_hmenuSelected != nullptr )
    {
      m_pMenuBar->OnChangeHot(this: m_pMenuBar, a2: -1);
      CMenuHash::SaveMenuBar(this: &afxMenuHash, hMenu: this->m_hmenuSelected, pBar: this->m_pMenuBar);
    }
    v3 = SendMessageA(hWnd: this->m_wndMenuesList.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
    if ( v3 == -1 )
    {
      ATL::CSimpleStringT<char,0>::SetString(this: &this->m_strMenuDescr, pszSrc: &var);
      SendMessageA(hWnd: this->m_wndIcon.m_hWnd, Msg: 0x170u, wParam: 0, lParam: 0);
      CWnd::UpdateData(this, bSaveAndValidate: 0);
      this->m_hmenuSelected = nullptr;
      return;
    }
    hicon = nullptr;
    v4 = SendMessageA(hWnd: this->m_wndMenuesList.m_hWnd, Msg: 0x150u, wParam: v3, lParam: 0);
    v5 = v4;
    if ( v4 != 0 )
    {
      (*(void (__thiscall **)(LRESULT, ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *, int))(*(_DWORD *)v4 + 100))(
        a1: v4,
        a2: &this->m_strMenuDescr,
        a3: 6);
      hicona = *(HICON__ **)(v5 + 84);
      AfxGetModuleState();
      ModuleState = AfxGetModuleState();
      hicon = LoadIconW(hInstance: ModuleState->m_hCurrentResourceHandle, lpIconName: (LPCWSTR)(unsigned __int16)hicona);
      if ( hicon == nullptr )
        hicon = LoadIconA(hInstance: nullptr, lpIconName: (LPCSTR)0x7F00);
      m_hDefaultMenu = *(HMENU__ **)(v5 + 136);
    }
    else
    {
      StringResourceHandle = AfxFindStringResourceHandle(__formal: 0x3EEBu);
      if ( StringResourceHandle == nullptr
        || ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
             this: &this->m_strMenuDescr,
             hInstance: StringResourceHandle,
             nID: 0x3EEBu) == 0 )
      {
        goto LABEL_12;
      }
      MainWnd = AfxGetMainWnd();
      if ( MainWnd != nullptr )
        hicon = (HICON__ *)GetClassLongA(hWnd: MainWnd->m_hWnd, nIndex: -14);
      m_hDefaultMenu = this->m_pMenuBar->m_hDefaultMenu;
    }
    if ( m_hDefaultMenu != nullptr )
    {
      this->m_pMenuBar->CreateFromMenu(this: this->m_pMenuBar, a2: m_hDefaultMenu, a3: 0, a4: 0);
      SendMessageA(hWnd: this->m_wndIcon.m_hWnd, Msg: 0x170u, wParam: (WPARAM)hicon, lParam: 0);
      this->m_hmenuSelected = m_hDefaultMenu;
      CWnd::UpdateData(this, bSaveAndValidate: 0);
      return;
    }
LABEL_12:
    AfxThrowInvalidArgException();
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F08A2
// Name: public: int CMFCToolBarsMenuPropertyPage::SelectMenu(class CDocTemplate __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarsMenuPropertyPage::SelectMenu(
        CMFCToolBarsMenuPropertyPage *this,
        CDocTemplate *pTemplate,
        int bSaveCurr)
{
  CMFCMenuBar *m_pMenuBar; // eax
  WPARAM i; // [esp+Ch] [ebp-4h]

  i = 0;
  if ( SendMessageA(hWnd: this->m_wndMenuesList.m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0) <= 0 )
    return 0;
  while ( (CDocTemplate *)SendMessageA(hWnd: this->m_wndMenuesList.m_hWnd, Msg: 0x150u, wParam: i, lParam: 0) != pTemplate )
  {
    if ( (int)++i >= SendMessageA(hWnd: this->m_wndMenuesList.m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0) )
      return 0;
  }
  if ( bSaveCurr == 0 )
    this->m_hmenuSelected = nullptr;
  m_pMenuBar = this->m_pMenuBar;
  if ( m_pMenuBar != nullptr )
    this->m_hmenuCurr = m_pMenuBar->m_hMenu;
  SendMessageA(hWnd: this->m_wndMenuesList.m_hWnd, Msg: 0x14Eu, wParam: i, lParam: 0);
  CMFCToolBarsMenuPropertyPage::OnSelchangeMenuList(this);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103F0941
// Name: public: static class CObject __near * CMFCToolBarsMenuPropertyPage::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCToolBarsMenuPropertyPage *__stdcall CMFCToolBarsMenuPropertyPage::CreateObject()
{
  CMFCToolBarsMenuPropertyPage *v0; // ecx
  CMFCToolBarsMenuPropertyPage *result; // eax

  v0 = (CMFCToolBarsMenuPropertyPage *)operator new(nSize: 0x564u);
  result = nullptr;
  if ( v0 != nullptr )
    return CMFCToolBarsMenuPropertyPage::CMFCToolBarsMenuPropertyPage(this: v0, pParentFrame: nullptr, bAutoSet: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103F0973
// Name: protected: virtual int CMFCToolBarsMenuPropertyPage::OnInitDialog(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCToolBarsMenuPropertyPage::OnInitDialog(CMFCToolBarsMenuPropertyPage *this)
{
  __POSITION **m_pNodeHead; // eax
  CMFCMenuBar *m_pMenuBar; // eax
  CMFCMenuBar *v4; // ecx
  char *m_pDocManager; // eax
  LRESULT v6; // eax
  LRESULT v7; // eax
  int v8; // eax
  CAfxStringMgr *StringManager; // eax
  CMultiDocTemplateEx_vtbl *v10; // eax
  CAfxStringMgr *v11; // eax
  HINSTANCE__ *StringResourceHandle; // eax
  int v13; // eax
  __POSITION *v14; // eax
  char *v15; // eax
  char *m_pszData; // eax
  CAfxStringMgr *v17; // eax
  HINSTANCE__ *v18; // eax
  int v19; // eax
  HINSTANCE__ *v20; // eax
  int v21; // eax
  HINSTANCE__ *v22; // eax
  int v23; // eax
  HINSTANCE__ *v24; // eax
  int v25; // eax
  HINSTANCE__ *v26; // eax
  int v27; // eax
  CWnd *DlgItem; // eax
  HINSTANCE__ *v29; // eax
  int StringA; // eax
  CAfxStringMgr *v31; // eax
  HINSTANCE__ *v32; // eax
  int v33; // eax
  __POSITION **v34; // eax
  ATL::CStringData *v35; // eax
  LRESULT v36; // eax
  LRESULT v37; // eax
  HWND Parent; // eax
  CWnd *v39; // eax
  CObject *v40; // eax
  CObject *v41; // edi
  HWND__ *m_hWnd; // [esp-10h] [ebp-64h]
  HWND__ *v44; // [esp-10h] [ebp-64h]
  WPARAM v45; // [esp-8h] [ebp-5Ch]
  CStringList listOfNames; // [esp+10h] [ebp-44h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strName; // [esp+2Ch] [ebp-28h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strNoContextMenu; // [esp+30h] [ebp-24h] BYREF
  int iCurrMenu; // [esp+34h] [ebp-20h]
  int bIsAlreadyExist; // [esp+38h] [ebp-1Ch]
  int i; // [esp+3Ch] [ebp-18h]
  __POSITION *pos; // [esp+40h] [ebp-14h] BYREF
  CMultiDocTemplateEx *pTemplate; // [esp+44h] [ebp-10h] BYREF
  int v54; // [esp+50h] [ebp-4h]

  CDialog::OnInitDialog(this);
  if ( this->m_iMenuAnimationType == 999 )
  {
    this->m_iMenuAnimationType = SendMessageA(hWnd: this->m_wndMenuAnimations.m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0)
                               - 1;
    CWnd::UpdateData(this, bSaveAndValidate: 0);
  }
  m_pNodeHead = (__POSITION **)afxAllToolBars.m_pNodeHead;
  pos = (__POSITION *)afxAllToolBars.m_pNodeHead;
  if ( this->m_pMenuBar == nullptr )
  {
    while ( m_pNodeHead != nullptr )
    {
      pos = *m_pNodeHead;
      v14 = m_pNodeHead[2];
      strNoContextMenu.m_pszData = (char *)v14;
      if ( v14 == nullptr )
        goto LABEL_30;
      if ( CWnd::FromHandlePermanent(hWnd: *(CDocument **)&v14[32]) != nullptr )
        this->m_pMenuBar = (CMFCMenuBar *)AfxDynamicDownCast(
                                            pClass: &CMFCMenuBar::classCMFCMenuBar,
                                            pObject: (CObject *)strNoContextMenu.m_pszData);
      if ( this->m_pMenuBar != nullptr )
        break;
      m_pNodeHead = (__POSITION **)pos;
    }
  }
  m_pMenuBar = this->m_pMenuBar;
  if ( m_pMenuBar != nullptr )
  {
    iCurrMenu = -1;
    m_pMenuBar->m_pMenuPage = this;
    v4 = this->m_pMenuBar;
    this->m_hmenuCurr = v4->m_hMenu;
    v4->OnChangeHot(this: v4, a2: -1);
    CMenuHash::SaveMenuBar(this: &afxMenuHash, hMenu: this->m_hmenuCurr, pBar: this->m_pMenuBar);
    m_pDocManager = (char *)AfxGetModuleState()->m_pCurrentWinApp->m_pDocManager;
    strName.m_pszData = m_pDocManager;
    if ( this->m_bAutoSet != 0 && m_pDocManager != nullptr )
    {
      pos = (__POSITION *)(*(int (__thiscall **)(char *))(*(_DWORD *)m_pDocManager + 16))(a1: m_pDocManager);
      while ( pos != nullptr )
      {
        pTemplate = (CMultiDocTemplateEx *)(*(int (__thiscall **)(char *, __POSITION **))(*(_DWORD *)strName.m_pszData
                                                                                        + 20))(
                                             a1: strName.m_pszData,
                                             a2: &pos);
        if ( CObject::IsKindOf(this: pTemplate, pClass: &CMultiDocTemplate::classCMultiDocTemplate) != 0
          && pTemplate->m_hMenuShared != nullptr )
        {
          bIsAlreadyExist = 0;
          i = 0;
          do
          {
            v6 = SendMessageA(hWnd: this->m_wndMenuesList.m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0);
            if ( i >= v6 )
              break;
            v7 = SendMessageA(hWnd: this->m_wndMenuesList.m_hWnd, Msg: 0x150u, wParam: i, lParam: 0);
            if ( v7 != 0 )
            {
              v8 = *(_DWORD *)(v7 + 84);
              bIsAlreadyExist = 1;
              if ( v8 == pTemplate->m_nIDResource )
                continue;
            }
            bIsAlreadyExist = 0;
            ++i;
          }
          while ( bIsAlreadyExist == 0 );
          if ( bIsAlreadyExist == 0 )
          {
            StringManager = AfxGetStringManager();
            ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strNoContextMenu, pStringMgr: StringManager);
            v10 = pTemplate->__vftable;
            v54 = 0;
            v10->GetDocString(this: pTemplate, a2: &strNoContextMenu, a3: fileNewName);
            bIsAlreadyExist = SendMessageA(
                                hWnd: this->m_wndMenuesList.m_hWnd,
                                Msg: 0x143u,
                                wParam: 0,
                                lParam: (LPARAM)strNoContextMenu.m_pszData);
            SendMessageA(
              hWnd: this->m_wndMenuesList.m_hWnd,
              Msg: 0x151u,
              wParam: bIsAlreadyExist,
              lParam: (LPARAM)pTemplate);
            if ( pTemplate->m_hMenuShared == this->m_hmenuCurr )
              iCurrMenu = bIsAlreadyExist;
            v54 = -1;
            ATL::CStringData::Release(this: (ATL::CStringData *)strNoContextMenu.m_pszData - 1);
          }
        }
      }
    }
    v11 = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strNoContextMenu, pStringMgr: v11);
    v54 = 1;
    StringResourceHandle = AfxFindStringResourceHandle(__formal: 0x3EEAu);
    if ( StringResourceHandle != nullptr )
      v13 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
              this: &strNoContextMenu,
              hInstance: StringResourceHandle,
              nID: 0x3EEAu);
    else
      v13 = 0;
    if ( v13 != 0 )
    {
      v15 = (char *)SendMessageA(
                      hWnd: this->m_wndMenuesList.m_hWnd,
                      Msg: 0x143u,
                      wParam: 0,
                      lParam: (LPARAM)strNoContextMenu.m_pszData);
      m_hWnd = this->m_wndMenuesList.m_hWnd;
      strName.m_pszData = v15;
      SendMessageA(hWnd: m_hWnd, Msg: 0x151u, wParam: (WPARAM)v15, lParam: 0);
      if ( iCurrMenu == -1 )
      {
        m_pszData = strName.m_pszData;
        this->m_bIsDefaultMDIMenu = 1;
        iCurrMenu = (int)m_pszData;
      }
      v45 = iCurrMenu;
      this->m_hmenuSelected = this->m_hmenuCurr;
      SendMessageA(hWnd: this->m_wndMenuesList.m_hWnd, Msg: 0x14Eu, wParam: v45, lParam: 0);
      v17 = AfxGetStringManager();
      ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(
        this: (ATL::CSimpleStringT<char,0> *)&pTemplate,
        pStringMgr: v17);
      LOBYTE(v54) = 2;
      v18 = AfxFindStringResourceHandle(__formal: 0x42D6u);
      v19 = v18 != nullptr
          ? ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
              this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pTemplate,
              hInstance: v18,
              nID: 0x42D6u)
          : 0;
      if ( v19 != 0 )
      {
        SendMessageA(hWnd: this->m_wndMenuAnimations.m_hWnd, Msg: 0x14Au, wParam: 0xFFFFFFFF, lParam: (LPARAM)pTemplate);
        v20 = AfxFindStringResourceHandle(__formal: 0x42D7u);
        v21 = v20 != nullptr
            ? ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pTemplate,
                hInstance: v20,
                nID: 0x42D7u)
            : 0;
        if ( v21 != 0 )
        {
          SendMessageA(
            hWnd: this->m_wndMenuAnimations.m_hWnd,
            Msg: 0x14Au,
            wParam: 0xFFFFFFFF,
            lParam: (LPARAM)pTemplate);
          v22 = AfxFindStringResourceHandle(__formal: 0x42D8u);
          v23 = v22 != nullptr
              ? ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                  this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pTemplate,
                  hInstance: v22,
                  nID: 0x42D8u)
              : 0;
          if ( v23 != 0 )
          {
            SendMessageA(
              hWnd: this->m_wndMenuAnimations.m_hWnd,
              Msg: 0x14Au,
              wParam: 0xFFFFFFFF,
              lParam: (LPARAM)pTemplate);
            v24 = AfxFindStringResourceHandle(__formal: 0x42D9u);
            v25 = v24 != nullptr
                ? ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                    this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pTemplate,
                    hInstance: v24,
                    nID: 0x42D9u)
                : 0;
            if ( v25 != 0 )
            {
              SendMessageA(
                hWnd: this->m_wndMenuAnimations.m_hWnd,
                Msg: 0x14Au,
                wParam: 0xFFFFFFFF,
                lParam: (LPARAM)pTemplate);
              v26 = AfxFindStringResourceHandle(__formal: 0x42DAu);
              v27 = v26 != nullptr
                  ? ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                      this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pTemplate,
                      hInstance: v26,
                      nID: 0x42DAu)
                  : 0;
              if ( v27 != 0 )
              {
                SendMessageA(
                  hWnd: this->m_wndMenuAnimations.m_hWnd,
                  Msg: 0x14Au,
                  wParam: 0xFFFFFFFF,
                  lParam: (LPARAM)pTemplate);
                CWnd::UpdateData(this, bSaveAndValidate: 0);
                CMFCToolBarsMenuPropertyPage::OnSelchangeMenuList(this);
                ATL::CStringData::Release(this: (ATL::CStringData *)&pTemplate[-1].m_docList.m_pNodeFree);
                v54 = -1;
                ATL::CStringData::Release(this: (ATL::CStringData *)strNoContextMenu.m_pszData - 1);
                goto LABEL_61;
              }
            }
          }
        }
      }
    }
LABEL_30:
    AfxThrowInvalidArgException();
  }
  CWnd::EnableWindow(this: &this->m_wndMenuesList, bEnable: 0);
  DlgItem = CWnd::GetDlgItem(this, nID: 16624);
  CWnd::EnableWindow(this: DlgItem, bEnable: 0);
  v29 = AfxFindStringResourceHandle(__formal: 0x3E87u);
  if ( v29 != nullptr )
    StringA = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                this: &this->m_strMenuDescr,
                hInstance: v29,
                nID: 0x3E87u);
  else
    StringA = 0;
  if ( StringA == 0 )
    goto LABEL_30;
  CWnd::UpdateData(this, bSaveAndValidate: 0);
LABEL_61:
  v31 = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strNoContextMenu, pStringMgr: v31);
  v54 = 3;
  v32 = AfxFindStringResourceHandle(__formal: 0x3EECu);
  if ( v32 != nullptr )
    v33 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
            this: &strNoContextMenu,
            hInstance: v32,
            nID: 0x3EECu);
  else
    v33 = 0;
  if ( v33 == 0 )
    goto LABEL_30;
  SendMessageA(hWnd: this->m_wndContextMenus.m_hWnd, Msg: 0x143u, wParam: 0, lParam: (LPARAM)strNoContextMenu.m_pszData);
  SendMessageA(hWnd: this->m_wndContextMenus.m_hWnd, Msg: 0x14Eu, wParam: 0, lParam: 0);
  v54 = -1;
  ATL::CStringData::Release(this: (ATL::CStringData *)strNoContextMenu.m_pszData - 1);
  if ( afxContextMenuManager != nullptr )
  {
    CStringList::CStringList(this: &listOfNames, nBlockSize: 10);
    v54 = 4;
    CContextMenuManager::GetMenuNames(this: afxContextMenuManager, &listOfNames);
    v34 = (__POSITION **)listOfNames.m_pNodeHead;
    pos = (__POSITION *)listOfNames.m_pNodeHead;
    while ( v34 != nullptr )
    {
      pos = *v34;
      v35 = ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)&v34[2][-16]);
      v44 = this->m_wndContextMenus.m_hWnd;
      strName.m_pszData = (char *)&v35[1];
      SendMessageA(hWnd: v44, Msg: 0x143u, wParam: 0, lParam: (LPARAM)&v35[1]);
      ATL::CStringData::Release(this: (ATL::CStringData *)strName.m_pszData - 1);
      v34 = (__POSITION **)pos;
    }
    v36 = SendMessageA(hWnd: this->m_wndContextMenus.m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0);
    CWnd::EnableWindow(this: &this->m_wndContextMenuCaption, bEnable: v36 > 1);
    v37 = SendMessageA(hWnd: this->m_wndContextMenus.m_hWnd, Msg: 0x146u, wParam: 0, lParam: 0);
    CWnd::EnableWindow(this: &this->m_wndContextMenus, bEnable: v37 > 1);
    v54 = -1;
    CStringList::~CStringList(this: &listOfNames);
  }
  else
  {
    CWnd::ShowWindow(this: &this->m_wndContextMenuCaption, nCmdShow: 0);
    CWnd::ShowWindow(this: &this->m_wndContextMenus, nCmdShow: 0);
    CWnd::ShowWindow(this: &this->m_wndContextHint, nCmdShow: 0);
    CWnd::ShowWindow(this: &this->m_wndContextFrame, nCmdShow: 0);
    CWnd::ShowWindow(this: &this->m_wndResetMenuButton, nCmdShow: 0);
  }
  Parent = GetParent(hWnd: this->m_hWnd);
  v39 = CWnd::FromHandle(hWnd: Parent);
  v40 = AfxDynamicDownCast(pClass: &CMFCToolBarsCustomizeDialog::classCMFCToolBarsCustomizeDialog, pObject: v39);
  if ( v40 == nullptr )
    goto LABEL_30;
  v41 = v40 + 82;
  if ( ((int)v40[82].__vftable & 1) == 0 )
    CWnd::ShowWindow(this: &this->m_wndMenuShadows, nCmdShow: 0);
  if ( ((int)v41->__vftable & 4) == 0 )
  {
    CWnd::ShowWindow(this: &this->m_wndMenuAnimationsLabel, nCmdShow: 0);
    CWnd::ShowWindow(this: &this->m_wndMenuAnimations, nCmdShow: 0);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x103F0FD7
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCToolBarsMenuPropertyPage::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCToolBarsMenuPropertyPage::GetMessageMap(CMFCToolBarsMenuPropertyPage *this)
{
  return (const AFX_MSGMAP *)&off_10688990;
}

//------------------------------------------------------------------------------
// Address: 0x103F0FDD
// Name: void AFXSoundThreadProc(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn AFXSoundThreadProc()
{
  int v0; // eax
  int v1; // eax

  v0 = g_nSoundState;
  if ( g_nSoundState == -1 )
  {
LABEL_8:
    PlaySoundA(pszSound: nullptr, hmod: nullptr, fdwSound: 0x40u);
    _endthread();
  }
  while ( 1 )
  {
    v1 = v0 - 1;
    if ( v1 == 0 )
      break;
    if ( v1 == 1 )
    {
      PlaySoundA(pszSound: "MenuPopup", hmod: nullptr, fdwSound: 0x12002u);
LABEL_6:
      g_nSoundState = 0;
    }
    Sleep(dwMilliseconds: 5u);
    v0 = g_nSoundState;
    if ( g_nSoundState == -1 )
      goto LABEL_8;
  }
  PlaySoundA(pszSound: "MenuCommand", hmod: nullptr, fdwSound: 0x12002u);
  goto LABEL_6;
}

//------------------------------------------------------------------------------
// Address: 0x103F1035
// Name: void AFXPlaySystemSound(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl AFXPlaySystemSound(int nSound)
{
  void *v1; // eax

  if ( CMFCPopupMenu::m_bMenuSound != 0 )
  {
    if ( g_nSoundState == -2 )
    {
      if ( nSound != -1 )
      {
        if ( (_S1_44 & 1) == 0 )
        {
          _S1_44 |= 1u;
          CCriticalSection::CCriticalSection(this: &stru_1083CC40);
          atexit(func: AFXPlaySystemSound_::_11_::_dynamic_atexit_destructor_for__cs__);
        }
        EnterCriticalSection(lpCriticalSection: &stru_1083CC40.m_sect);
        if ( g_hThreadSound != nullptr )
          AfxThrowInvalidArgException();
        v1 = (void *)_beginthread(
                       initialcode: (void (__cdecl *)(void *))AFXSoundThreadProc,
                       stacksize: 0,
                       argument: nullptr);
        g_hThreadSound = v1;
        if ( v1 == nullptr || v1 == (void *)-1 )
        {
          g_hThreadSound = nullptr;
        }
        else
        {
          SetThreadPriority(hThread: v1, nPriority: -1);
          g_nSoundState = nSound;
        }
        LeaveCriticalSection(lpCriticalSection: &stru_1083CC40.m_sect);
      }
    }
    else
    {
      g_nSoundState = nSound;
      if ( nSound == -1 )
        g_hThreadSound = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103F1103
// Name: protected: unsigned int CMenuTearOffManager::GetFreeTearOffID(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __thiscall CMenuTearOffManager::GetFreeTearOffID(CMenuTearOffManager *this)
{
  unsigned int m_uiTearOffMenuFirst; // edx
  unsigned int m_uiTearOffMenuLast; // eax
  int v3; // eax
  int v4; // edx
  int *m_pData; // esi

  m_uiTearOffMenuFirst = this->m_uiTearOffMenuFirst;
  if ( m_uiTearOffMenuFirst == 0 )
    return 0;
  m_uiTearOffMenuLast = this->m_uiTearOffMenuLast;
  if ( m_uiTearOffMenuLast == 0 )
    return 0;
  v3 = m_uiTearOffMenuLast - m_uiTearOffMenuFirst + 1;
  v4 = 0;
  if ( v3 <= 0 )
    return 0;
  while ( 1 )
  {
    if ( v4 < 0 || v4 >= this->m_arTearOffIDsUsage.m_nSize )
      goto LABEL_11;
    m_pData = this->m_arTearOffIDsUsage.m_pData;
    if ( m_pData[v4] == 0 )
      break;
    if ( ++v4 >= v3 )
      return 0;
  }
  if ( v4 >= this->m_arTearOffIDsUsage.m_nSize )
LABEL_11:
    AfxThrowInvalidArgException();
  m_pData[v4] = 1;
  return v4 + this->m_uiTearOffMenuFirst;
}

//------------------------------------------------------------------------------
// Address: 0x103F1151
// Name: public: void CMenuTearOffManager::SetInUse(unsigned int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMenuTearOffManager::SetInUse(CMenuTearOffManager *this, unsigned int uiCmdId, int bUse)
{
  unsigned int m_uiTearOffMenuFirst; // eax
  int v4; // esi
  int *v5; // eax

  m_uiTearOffMenuFirst = this->m_uiTearOffMenuFirst;
  if ( uiCmdId >= m_uiTearOffMenuFirst && uiCmdId <= this->m_uiTearOffMenuLast )
  {
    v4 = uiCmdId - m_uiTearOffMenuFirst;
    if ( (int)(uiCmdId - m_uiTearOffMenuFirst) < 0
      || v4 >= this->m_arTearOffIDsUsage.m_nSize
      || (this->m_arTearOffIDsUsage.m_pData[v4] += 2 * (bUse != 0) - 1, v4 >= this->m_arTearOffIDsUsage.m_nSize) )
    {
      AfxThrowInvalidArgException();
    }
    v5 = &this->m_arTearOffIDsUsage.m_pData[v4];
    if ( *v5 < 0 )
      *v5 = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10404624
// Name: protected: virtual int CMFCTabCtrl::OnNotify(unsigned int,long,long __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCTabCtrl::OnNotify(CMFCTabCtrl *this, unsigned int wParam, tagNMHDR *lParam, int *pResult)
{
  CToolTipCtrl *m_pToolTip; // ecx
  CToolTipCtrl *m_pToolTipClose; // ecx
  int bRes; // [esp+18h] [ebp+10h]

  bRes = CWnd::OnNotify(this, __formal: wParam, lParam, pResult);
  if ( lParam == nullptr )
    AfxThrowInvalidArgException();
  if ( lParam->code == -521 )
  {
    m_pToolTip = this->m_pToolTip;
    if ( m_pToolTip != nullptr && m_pToolTip->m_hWnd != nullptr )
      CWnd::SetWindowPos(this: m_pToolTip, pWndInsertAfter: &CWnd::wndTop, x: -1, y: -1, cx: -1, cy: -1, nFlags: 0x13u);
    m_pToolTipClose = this->m_pToolTipClose;
    if ( m_pToolTipClose != nullptr && m_pToolTipClose->m_hWnd != nullptr && lParam->hwndFrom == m_pToolTipClose->m_hWnd )
      CWnd::SetWindowPos(
        this: m_pToolTipClose,
        pWndInsertAfter: &CWnd::wndTop,
        x: -1,
        y: -1,
        cx: -1,
        cy: -1,
        nFlags: 0x13u);
  }
  if ( lParam->code == -301 )
    CMFCTabCtrl::SynchronizeScrollBar(this, pScrollInfo: nullptr);
  return bRes;
}

//------------------------------------------------------------------------------
// Address: 0x104046C0
// Name: public: void CMFCTabCtrl::HideNoTabs(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTabCtrl::HideNoTabs(CMFCTabCtrl *this, int bHide)
{
  HWND__ *m_hWnd; // eax

  if ( this->m_bHideNoTabs != bHide )
  {
    m_hWnd = this->m_hWnd;
    this->m_bHideNoTabs = bHide;
    if ( m_hWnd != nullptr )
    {
      this->RecalcLayout(this);
      CMFCTabCtrl::SynchronizeScrollBar(this, pScrollInfo: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104046F8
// Name: protected: virtual int CMFCTabCtrl::OnCommand(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCTabCtrl::OnCommand(CMFCTabCtrl *this, unsigned int wParam, HWND__ *lParam)
{
  int m_nTabsHorzOffset; // edx
  HWND__ *m_hWnd; // eax
  int v6; // edx
  int v7; // ecx
  int v8; // edx
  int m_nFirstVisibleTab; // ecx
  int v10; // ecx
  _DWORD *v11; // eax
  int v12; // eax
  HWND__ *v13; // eax
  int left; // ebx
  HWND__ *v15; // edi
  int v17; // ecx
  _DWORD *v18; // eax
  HWND__ *v19; // eax
  HWND__ *v20; // eax
  HWND__ *v21; // eax
  CWnd *v22; // eax
  int m_nTabsHorzOffsetMax; // eax
  HWND__ *v24; // [esp-8h] [ebp-30h]
  int nPrevOffset; // [esp+10h] [ebp-18h]
  int nPrevOffseta; // [esp+10h] [ebp-18h]
  CRect rectButton; // [esp+14h] [ebp-14h] BYREF

  m_nTabsHorzOffset = this->m_nTabsHorzOffset;
  nPrevOffset = m_nTabsHorzOffset;
  if ( this == (CMFCTabCtrl *)-852 )
    m_hWnd = nullptr;
  else
    m_hWnd = this->m_btnScrollLeft.m_hWnd;
  if ( lParam == m_hWnd )
  {
    if ( this->m_bIsOneNoteStyle == 0 && this->m_bIsVS2005Style == 0 && this->m_bLeftRightRounded == 0 )
    {
      v6 = m_nTabsHorzOffset - 20;
LABEL_9:
      this->m_nTabsHorzOffset = v6;
LABEL_10:
      if ( this->m_bIsOneNoteStyle != 0 || this->m_bIsVS2005Style != 0 || this->m_bLeftRightRounded != 0 )
      {
        m_nTabsHorzOffsetMax = this->m_nTabsHorzOffset;
        if ( m_nTabsHorzOffsetMax >= 0 )
          goto LABEL_62;
      }
      else
      {
        v7 = this->m_nTabsHorzOffset;
        if ( v7 >= 0 )
          v8 = this->m_nTabsHorzOffset;
        else
          v8 = 0;
        m_nTabsHorzOffsetMax = this->m_nTabsHorzOffsetMax;
        if ( v8 >= m_nTabsHorzOffsetMax )
          goto LABEL_62;
        if ( v7 >= 0 )
        {
          m_nTabsHorzOffsetMax = this->m_nTabsHorzOffset;
          goto LABEL_62;
        }
      }
      m_nTabsHorzOffsetMax = 0;
LABEL_62:
      this->m_nTabsHorzOffset = m_nTabsHorzOffsetMax;
      if ( nPrevOffset != this->m_nTabsHorzOffset )
      {
        this->AdjustTabs(this);
        CMFCTabCtrl::UpdateScrollButtonsState(this);
        InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
        UpdateWindow(hWnd: this->m_hWnd);
      }
      return 1;
    }
    m_nFirstVisibleTab = this->m_nFirstVisibleTab;
    if ( m_nFirstVisibleTab <= 0 )
      goto LABEL_10;
    v10 = m_nFirstVisibleTab - 1;
    if ( v10 >= 0 && v10 < this->m_arTabs.m_nSize )
    {
      v11 = this->m_arTabs.m_pData[v10];
      v12 = m_nTabsHorzOffset
          + this->m_rectTabsArea.bottom
          - this->m_rectTabsArea.top
          - v11[6]
          - CMFCBaseTabCtrl::AFX_TAB_IMAGE_MARGIN
          + v11[4]
          - 2;
LABEL_19:
      this->m_nTabsHorzOffset = v12;
      this->m_nFirstVisibleTab = v10;
      goto LABEL_10;
    }
    goto LABEL_20;
  }
  if ( this == (CMFCTabCtrl *)-2724 )
    v13 = nullptr;
  else
    v13 = this->m_btnScrollRight.m_hWnd;
  if ( lParam == v13 )
  {
    if ( this->m_bTabDocumentsMenu == 0 )
    {
      if ( this->m_bIsOneNoteStyle == 0 && this->m_bIsVS2005Style == 0 && this->m_bLeftRightRounded == 0 )
      {
        v6 = m_nTabsHorzOffset + 20;
        goto LABEL_9;
      }
      v17 = this->m_nFirstVisibleTab;
      if ( v17 >= this->m_iTabsNum )
        goto LABEL_10;
      if ( v17 >= 0 && v17 < this->m_arTabs.m_nSize )
      {
        v18 = this->m_arTabs.m_pData[v17];
        v12 = m_nTabsHorzOffset
            + v18[6]
            + this->m_rectTabsArea.top
            - this->m_rectTabsArea.bottom
            - v18[4]
            + CMFCBaseTabCtrl::AFX_TAB_IMAGE_MARGIN
            + 1;
        v10 = v17 + 1;
        goto LABEL_19;
      }
LABEL_20:
      AfxThrowInvalidArgException();
    }
    v24 = this->m_btnScrollRight.m_hWnd;
    memset(&rectButton, 0, sizeof(rectButton));
    GetWindowRect(hWnd: v24, lpRect: &rectButton);
    CMFCTabButton::SetPressed(this: &this->m_btnScrollRight, bOn: 1);
    left = rectButton.left;
    nPrevOffseta = rectButton.bottom;
    if ( (CWnd::GetExStyle(this) & 0x400000) != 0 )
      left += rectButton.right - rectButton.left;
    SendMessageA(hWnd: this->m_btnScrollRight.m_hWnd, Msg: 0x1Fu, wParam: 0, lParam: 0);
    v15 = this->m_hWnd;
    CMFCTabButton::SetPressed(this: &this->m_btnScrollRight, bOn: 1);
    ((void (__thiscall *)(CMFCTabCtrl *, int, int))this->OnShowTabDocumentsMenu)(a1: this, a2: left, a3: nPrevOffseta);
    if ( !IsWindow(hWnd: v15) )
      return 1;
    CMFCTabButton::SetPressed(this: &this->m_btnScrollRight, bOn: 0);
  }
  else
  {
    if ( this == (CMFCTabCtrl *)-4596 )
      v19 = nullptr;
    else
      v19 = this->m_btnScrollFirst.m_hWnd;
    if ( lParam == v19 )
    {
      this->m_nTabsHorzOffset = 0;
      goto LABEL_10;
    }
    if ( this == (CMFCTabCtrl *)-6468 )
      v20 = nullptr;
    else
      v20 = this->m_btnScrollLast.m_hWnd;
    if ( lParam == v20 )
    {
      this->m_nTabsHorzOffset = this->m_nTabsHorzOffsetMax;
      goto LABEL_10;
    }
    if ( this == (CMFCTabCtrl *)-8340 )
      v21 = nullptr;
    else
      v21 = this->m_btnClose.m_hWnd;
    if ( lParam == v21 )
    {
      v22 = this->GetActiveWnd(this);
      if ( v22 != nullptr )
        SendMessageA(hWnd: v22->m_hWnd, Msg: 0x10u, wParam: 0, lParam: 0);
      return 1;
    }
  }
  return CWnd::OnCommand(this, wParam, lParam);
}

//------------------------------------------------------------------------------
// Address: 0x10404A0B
// Name: public: void CMFCTabCtrl::SetActiveTabBoldFont(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTabCtrl::SetActiveTabBoldFont(CMFCTabCtrl *this, int bIsBold)
{
  this->m_bIsActiveTabBold = bIsBold;
  if ( this->m_hWnd != nullptr )
  {
    this->RecalcLayout(this);
    CMFCTabCtrl::SynchronizeScrollBar(this, pScrollInfo: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10404A39
// Name: public: virtual void CMFCTabCtrl::HideSingleTab(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTabCtrl::HideSingleTab(CMFCTabCtrl *this, int bHide)
{
  HWND__ *m_hWnd; // eax

  if ( this->m_bHideSingleTab != bHide )
  {
    m_hWnd = this->m_hWnd;
    this->m_bHideSingleTab = bHide;
    if ( m_hWnd != nullptr )
    {
      this->RecalcLayout(this);
      CMFCTabCtrl::SynchronizeScrollBar(this, pScrollInfo: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10404A71
// Name: public: int CMFCTabCtrl::Create(enum CMFCTabCtrl::Style,struct tagRECT const __near &,class CWnd __near *,unsigned int,enum CMFCBaseTabCtrl::Location,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCTabCtrl::Create(
        CMFCTabCtrl *this,
        CMFCTabCtrl::Style style,
        const tagRECT *rect,
        CWnd *pParentWnd,
        HMENU__ *nID,
        CMFCBaseTabCtrl::Location location,
        int bCloseBtn)
{
  CMFCTabCtrl::Style v8; // ecx
  BOOL v9; // edi
  BOOL v10; // ebx
  BOOL v11; // eax
  BOOL v12; // edx
  BOOL v13; // edx
  CMFCBaseTabCtrl::Location v14; // eax
  BOOL v15; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v16; // eax
  int v17; // esi

  v8 = style;
  v9 = true;
  if ( style != STYLE_FLAT )
    v9 = style == STYLE_FLAT_SHARED_HORZ_SCROLL;
  v10 = style == STYLE_FLAT_SHARED_HORZ_SCROLL;
  v11 = style == STYLE_3D_ONENOTE;
  v12 = style == STYLE_3D_VS2005;
  this->m_bFlat = v9;
  this->m_bSharedScroll = v10;
  this->m_bIsOneNoteStyle = v11;
  this->m_bIsVS2005Style = v12;
  v13 = v8 == STYLE_3D_ROUNDED || v8 == STYLE_3D_ROUNDED_SCROLL;
  this->m_bHighLightTabs = v11;
  v14 = location;
  this->m_bLeftRightRounded = v13;
  this->m_location = v14;
  v15 = v9
     || v8 == STYLE_3D_SCROLLED
     || v8 == STYLE_3D_ONENOTE
     || v8 == STYLE_3D_VS2005
     || v8 == STYLE_3D_ROUNDED_SCROLL;
  this->m_bScroll = v15;
  this->m_bCloseBtn = bCloseBtn;
  if ( !v9 && v8 == STYLE_FLAT_SHARED_HORZ_SCROLL )
    this->m_bSharedScroll = 0;
  v16 = AFX_GLOBAL_DATA::RegisterWindowClass(
          this: &afxGlobalData,
          result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&style,
          lpszClassNamePrefix: "Afx:TabWnd");
  v17 = CWnd::Create(
          this,
          lpszClassName: v16->m_pszData,
          lpszWindowName: &var,
          dwStyle: 0x56000000u,
          rect,
          pParentWnd,
          nID,
          pContext: nullptr);
  ATL::CStringData::Release(this: (ATL::CStringData *)(style - 16));
  return v17;
}

//------------------------------------------------------------------------------
// Address: 0x10404B6C
// Name: protected: void CMFCTabCtrl::OnSize(unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTabCtrl::OnSize(CMFCTabCtrl *this, unsigned int nType, int cx, int cy)
{
  int v5; // edi
  int v6; // edi
  HWND__ *m_hWnd; // [esp-10h] [ebp-1Ch]

  CWnd::Default(this);
  v5 = this->GetTabBorderSize(this);
  v6 = cx - 2 * (v5 + 2 * GetSystemMetrics(nIndex: 2));
  if ( v6 > 2 * GetSystemMetrics(nIndex: 21) )
  {
    if ( v6 / 2 <= 2 * GetSystemMetrics(nIndex: 21) )
      this->m_nHorzScrollWidth = v6;
    else
      this->m_nHorzScrollWidth = v6 / 2;
  }
  else
  {
    this->m_nHorzScrollWidth = 0;
  }
  if ( this->m_bIsOneNoteStyle != 0 || this->m_bIsVS2005Style != 0 || this->m_bLeftRightRounded != 0 )
  {
    m_hWnd = this->m_hWnd;
    this->m_nTabsHorzOffset = 0;
    this->m_nFirstVisibleTab = 0;
    SendMessageA(hWnd: m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
    this->RecalcLayout(this);
    if ( this->m_iActiveTab >= 0 )
      this->EnsureVisible(this, a2: this->m_iActiveTab);
    SendMessageA(hWnd: this->m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
    RedrawWindow(hWnd: this->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x585u);
  }
  else
  {
    this->RecalcLayout(this);
  }
  CMFCTabCtrl::SynchronizeScrollBar(this, pScrollInfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10404C60
// Name: public: virtual int CMFCTabCtrl::SetActiveTab(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCTabCtrl::SetActiveTab(CMFCTabCtrl *this, int iTab)
{
  int m_iActiveTab; // eax
  BOOL v4; // ecx
  bool v5; // zf
  CMFCTabCtrl_vtbl *v6; // eax
  CFrameWnd *ParentFrame; // eax
  CObject *v9; // eax
  HWND Parent; // eax
  CWnd *v11; // eax
  bool v12; // cc
  CWnd *v13; // eax
  CWnd *v14; // eax
  CWnd *v15; // ebx
  HWND v16; // eax
  CWnd *v17; // eax
  CWnd *v18; // ebx
  CAfxStringMgr *StringManager; // eax
  CMFCTabCtrl_vtbl *v20; // eax
  HWND v21; // eax
  const CWnd *v22; // eax
  CView *v23; // ebx
  CFrameWnd *v24; // eax
  HMENU SystemMenu; // eax
  CMenu *v26; // eax
  HMENU m_hMenu; // ebx
  CWnd *v28; // ebx
  HWND v29; // eax
  CWnd *v30; // eax
  CWnd *v31; // eax
  CObject *v32; // eax
  CObject *v33; // esi
  int v34; // ebx
  int v35; // [esp-8h] [ebp-80h]
  CObject_vtbl *v36; // [esp-8h] [ebp-80h]
  HWND__ *m_hWnd; // [esp-8h] [ebp-80h]
  tagMENUITEMINFOA dst; // [esp+10h] [ebp-68h] BYREF
  BOOL v39; // [esp+40h] [ebp-38h]
  CWnd *v40; // [esp+44h] [ebp-34h]
  CObject *pObject; // [esp+48h] [ebp-30h]
  int v42; // [esp+4Ch] [ebp-2Ch]
  CWnd *v43; // [esp+50h] [ebp-28h]
  ATL::CSimpleStringT<char,0> v44; // [esp+54h] [ebp-24h] BYREF
  tagRECT Rect; // [esp+58h] [ebp-20h] BYREF
  int v46; // [esp+74h] [ebp-4h]

  if ( iTab >= 0 && iTab < this->m_iTabsNum && iTab < this->m_arTabs.m_nSize )
  {
    m_iActiveTab = this->m_iActiveTab;
    v4 = m_iActiveTab == -1;
    v5 = m_iActiveTab == iTab;
    v6 = this->__vftable;
    v39 = v4;
    if ( v5 )
    {
      if ( v6->IsMDITabGroup(this) != 0 )
        CMFCTabCtrl::ActivateMDITab(this, nTab: this->m_iActiveTab);
      return 1;
    }
    if ( v6->FireChangingActiveTab(this, a2: iTab) == 0 )
    {
      ParentFrame = CWnd::GetParentFrame(this);
      v9 = AfxDynamicDownCast(pClass: &CMDIFrameWndEx::classCMDIFrameWndEx, pObject: ParentFrame);
      v42 = 0;
      if ( v9 != nullptr && this->m_bIsMDITab != 0 )
      {
        if ( v9[80].__vftable != nullptr || (v42 = 1, CMDIFrameWndEx::m_bDisableSetRedraw != 0) )
          v42 = 0;
      }
      Parent = GetParent(hWnd: this->m_hWnd);
      v11 = CWnd::FromHandle(hWnd: Parent);
      v12 = this->m_iTabsNum <= 1;
      v40 = v11;
      if ( !v12 && v42 != 0 )
        SendMessageA(hWnd: v11->m_hWnd, Msg: 0xBu, wParam: 0, lParam: 0);
      if ( this->m_iActiveTab != -1 && this->m_bHideInactiveWnd != 0 )
      {
        v13 = this->GetActiveWnd(this);
        if ( v13 != nullptr )
          CWnd::ShowWindow(this: v13, nCmdShow: 0);
      }
      this->m_iActiveTab = iTab;
      CMFCTabCtrl::HideActiveWindowHorzScrollBar(this);
      v14 = this->GetActiveWnd(this);
      v15 = v14;
      pObject = v14;
      if ( v14 != nullptr )
      {
        CWnd::ShowWindow(this: v14, nCmdShow: 5);
        if ( this->m_bHideInactiveWnd == 0 )
          BringWindowToTop(hWnd: v15->m_hWnd);
        if ( this->m_bAutoSizeWindow != 0 )
        {
          CWnd::SetWindowPos(
            this: v15,
            pWndInsertAfter: nullptr,
            x: -1,
            y: -1,
            cx: this->m_rectWndArea.right - this->m_rectWndArea.left + 1,
            cy: this->m_rectWndArea.bottom - this->m_rectWndArea.top,
            nFlags: 0x16u);
          CWnd::SetWindowPos(
            this: v15,
            pWndInsertAfter: nullptr,
            x: -1,
            y: -1,
            cx: this->m_rectWndArea.right - this->m_rectWndArea.left,
            cy: this->m_rectWndArea.bottom - this->m_rectWndArea.top,
            nFlags: 0x16u);
        }
        this->EnsureVisible(this, a2: this->m_iActiveTab);
        if ( this->m_bFlat != 0 )
          CMFCTabCtrl::SynchronizeScrollBar(this, pScrollInfo: nullptr);
        v16 = GetParent(hWnd: this->m_hWnd);
        v17 = CWnd::FromHandle(hWnd: v16);
        v18 = (CWnd *)AfxDynamicDownCast(pClass: &CTabbedPane::classCTabbedPane, pObject: v17);
        v43 = v18;
        if ( v18 != nullptr && ((int (__thiscall *)(CWnd *))v18->__vftable[2].OnTouchInputs)(a1: v18) != 0 )
        {
          StringManager = AfxGetStringManager();
          ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v44, pStringMgr: StringManager);
          v20 = this->__vftable;
          v35 = this->m_iActiveTab;
          v46 = 0;
          v20->GetTabLabel(this, a2: v35, a3: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v44);
          CWnd::SetWindowTextA(this: v18, lpszString: v44.m_pszData);
          if ( ((int (__thiscall *)(CWnd *))v18->__vftable[1].dtr_CObject)(a1: v18) == 0 )
          {
            v21 = GetParent(hWnd: v18->m_hWnd);
            v18 = CWnd::FromHandle(hWnd: v21);
          }
          if ( v18 != nullptr )
            RedrawWindow(hWnd: v18->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x401u);
          v46 = -1;
          ATL::CStringData::Release(this: (ATL::CStringData *)v44.m_pszData - 1);
        }
        if ( this->m_bIsActiveTabBold != 0 || this->m_bActiveTabCloseButton != 0 )
          this->RecalcLayout(this);
        InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
        UpdateWindow(hWnd: this->m_hWnd);
        if ( !v39 )
        {
          v22 = (const CWnd *)AfxDynamicDownCast(pClass: &CView::classCView, pObject);
          v23 = (CView *)v22;
          if ( v22 != nullptr )
          {
            v24 = AFXGetParentFrame(pWnd: v22);
            CFrameWnd::SetActiveView(this: v24, pViewNew: v23, bNotify: 1);
          }
          else if ( CMFCTabCtrl::m_bEnableActivate != 0 )
          {
            CWnd::SetFocus(this: (CWnd *)pObject);
          }
        }
        if ( this != (CMFCTabCtrl *)-8340 && this->m_btnClose.m_hWnd != nullptr )
        {
          v36 = pObject[8].__vftable;
          v44.m_pszData = (char *)1;
          SystemMenu = GetSystemMenu(hWnd: (HWND)v36, bRevert: false);
          v26 = CMenu::FromHandle(hMenu: SystemMenu);
          if ( v26 != nullptr )
          {
            m_hMenu = v26->m_hMenu;
            if ( m_hMenu != nullptr )
            {
              memset((unsigned __int8 *)&dst, value: 0, count: sizeof(dst));
              dst.cbSize = 48;
              dst.fMask = 1;
              if ( !GetMenuItemInfoA(hmenu: m_hMenu, item: 0xF060u, fByPosition: false, lpmii: &dst)
                || (dst.fState & 3) != 0 )
              {
                v44.m_pszData = nullptr;
              }
            }
          }
          CWnd::EnableWindow(this: &this->m_btnClose, bEnable: (int)v44.m_pszData);
        }
        this->FireChangeActiveTab(this, a2: this->m_iActiveTab);
        if ( this->m_iTabsNum > 1 && v42 != 0 )
        {
          v28 = v40;
          SendMessageA(hWnd: v40->m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
          if ( this->m_bSetActiveTabByMouseClick != 0 )
          {
            m_hWnd = this->m_hWnd;
            memset(&Rect, 0, sizeof(Rect));
            GetWindowRect(hWnd: m_hWnd, lpRect: &Rect);
            v29 = GetParent(hWnd: this->m_hWnd);
            v30 = CWnd::FromHandle(hWnd: v29);
            CWnd::ScreenToClient(this: v30, lpRect: (tagPOINT *)&Rect);
            RedrawWindow(hWnd: v28->m_hWnd, lprcUpdate: &Rect, hrgnUpdate: nullptr, flags: 0x185u);
          }
          else
          {
            RedrawWindow(hWnd: v28->m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x185u);
          }
        }
        if ( this->m_iActiveTab != -1 && v43 != nullptr )
        {
          v31 = this->GetTabWnd(this, a2: this->m_iActiveTab);
          v32 = AfxDynamicDownCast(pClass: &CBasePane::classCBasePane, pObject: v31);
          v33 = v32;
          if ( v32 != nullptr )
          {
            v34 = ((int (__thiscall *)(CObject *, _DWORD))v32->__vftable[45].Serialize)(a1: v32, a2: 0);
            if ( (((int (__thiscall *)(CObject *))v33->__vftable[37].dtr_CObject)(a1: v33) & 0x10) != 0 )
            {
              v43[1].m_hWnd = (HWND__ *)((int)v43[1].m_hWnd | 0x10);
              if ( v34 != 0 )
                (*(void (__thiscall **)(int))(*(_DWORD *)v34 + 496))(a1: v34);
            }
            else
            {
              v43[1].m_hWnd = (HWND__ *)((int)v43[1].m_hWnd & ~0x10u);
              if ( v34 != 0 )
                (*(void (__thiscall **)(int))(*(_DWORD *)v34 + 500))(a1: v34);
            }
          }
        }
        return 1;
      }
      SendMessageA(hWnd: v40->m_hWnd, Msg: 0xBu, wParam: 1u, lParam: 0);
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x104050E6
// Name: protected: virtual void CMFCTabCtrl::AdjustTabs(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTabCtrl::AdjustTabs(CMFCTabCtrl *this)
{
  int v2; // esi
  CToolTipCtrl *m_pToolTipClose; // eax
  CToolTipCtrl *v4; // ecx
  CFont *p_m_fntTabsBold; // eax
  int v6; // eax
  const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v7; // esi
  int cx; // edi
  int v9; // eax
  char *v10; // ecx
  int v11; // eax
  int m_pszData; // esi
  int m_nTabMaxWidth; // eax
  int top; // ecx
  tagRECT *v15; // eax
  bool v16; // zf
  tagRECT *v17; // edx
  tagRECT *v18; // edi
  CToolTipCtrl *m_pToolTip; // ecx
  int right; // esi
  CToolTipCtrl *v21; // eax
  BOOL v22; // edi
  const tagRECT *v23; // eax
  int v24; // esi
  int v25; // edx
  int m_nTabsTotalWidth; // eax
  int v27; // esi
  int v28; // ecx
  __int64 v29; // rax
  int v30; // edx
  _DWORD *v31; // eax
  int v32; // eax
  tagRECT *cy; // esi
  int v34; // eax
  tagRECT *v35; // eax
  CToolTipCtrl *v36; // ecx
  tagRECT *v37; // ecx
  int v38; // eax
  int v39; // eax
  int v40; // ecx
  char *v41; // edx
  tagRECT *v42; // edi
  CToolTipCtrl *v43; // ecx
  int v44; // esi
  const tagRECT *v45; // eax
  int m_iActiveTab; // eax
  CMFCVisualManager *Instance; // eax
  CMFCVisualManager_vtbl *v48; // edx
  int v49; // eax
  CToolTipCtrl *v50; // ecx
  int v51; // eax
  CToolTipCtrl *v52; // eax
  CToolTipCtrl *v53; // ecx
  unsigned int v54; // [esp-8h] [ebp-B4h]
  tagRECT *v55; // [esp-4h] [ebp-B0h]
  CClientDC v56; // [esp+10h] [ebp-9Ch] BYREF
  CSize result; // [esp+24h] [ebp-88h] BYREF
  CFont *pFont; // [esp+2Ch] [ebp-80h]
  int v59; // [esp+30h] [ebp-7Ch]
  void *v60; // [esp+34h] [ebp-78h]
  tagRECT *v61; // [esp+38h] [ebp-74h]
  LPRECT lprc; // [esp+3Ch] [ebp-70h]
  int v63; // [esp+40h] [ebp-6Ch]
  int left; // [esp+44h] [ebp-68h]
  LPRECT v65; // [esp+48h] [ebp-64h]
  RECT rc; // [esp+4Ch] [ebp-60h] BYREF
  tagRECT Rect; // [esp+5Ch] [ebp-50h] BYREF
  tagRECT RectTool; // [esp+6Ch] [ebp-40h] BYREF
  tagRECT v69; // [esp+7Ch] [ebp-30h] BYREF
  tagRECT v70; // [esp+8Ch] [ebp-20h] BYREF
  int v71; // [esp+A8h] [ebp-4h]

  this->m_bHiddenDocuments = 0;
  SetRectEmpty(lprc: &this->m_rectCloseButton);
  v59 = this->GetVisibleTabsNum(this);
  if ( v59 == 0 || this->GetTabsHeight(this) == 0 )
    return;
  if ( this->m_bHideSingleTab == 0 || v59 > 1 )
  {
    m_pToolTipClose = this->m_pToolTipClose;
    if ( m_pToolTipClose != nullptr
      && m_pToolTipClose->m_hWnd != nullptr
      && SendMessageA(hWnd: m_pToolTipClose->m_hWnd, Msg: 0x40Du, wParam: 0, lParam: 0) == 0 )
    {
      v4 = this->m_pToolTipClose;
      memset(&RectTool, 0, sizeof(RectTool));
      CToolTipCtrl::AddTool(this: v4, pWnd: this, lpszText: (char *)0xFFFFFFFF, lpRectTool: &RectTool, nIDTool: 1u);
    }
    memset(&rc, 0, sizeof(rc));
    CClientDC::CClientDC(this: &v56, pWnd: this);
    v71 = 0;
    p_m_fntTabsBold = &this->m_fntTabsBold;
    if ( this->m_bFlat == 0 )
      p_m_fntTabsBold = &afxGlobalData.fontRegular;
    pFont = CDC::SelectObject(this: &v56, pFont: p_m_fntTabsBold);
    if ( pFont == nullptr )
      goto LABEL_10;
    v6 = this->m_rectTabsArea.left - this->m_nTabsHorzOffset;
    this->m_nTabsTotalWidth = 0;
    left = v6;
    v63 = 0;
    if ( this->m_iTabsNum > 0 )
    {
      while ( 1 )
      {
        if ( v63 < 0 || v63 >= this->m_arTabs.m_nSize )
          goto LABEL_10;
        v7 = (const ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)this->m_arTabs.m_pData[v63];
        cx = 0;
        v61 = (tagRECT *)v7;
        if ( v7[3].m_pszData != nullptr || v7[2].m_pszData != (char *)-1 )
        {
          cx = this->m_sizeImage.cx;
          RectTool.bottom = this->m_sizeImage.cy;
        }
        if ( this->m_bIsActiveTabBold != 0
          && (this->m_bIsOneNoteStyle != 0 || this->m_bIsVS2005Style != 0 || v63 == this->m_iActiveTab) )
        {
          CDC::SelectObject(this: &v56, pFont: &afxGlobalData.fontBold);
        }
        v9 = 0;
        v65 = nullptr;
        if ( v7[13].m_pszData == nullptr )
        {
          v7[9].m_pszData = nullptr;
          goto LABEL_44;
        }
        if ( v7[15].m_pszData == nullptr )
          v9 = CDC::GetTextExtent(this: &v56, &result, str: v7 + 1)->cx;
        v10 = (char *)(cx + CMFCBaseTabCtrl::AFX_TAB_IMAGE_MARGIN + v9 + 2 * CMFCBaseTabCtrl::AFX_TAB_TEXT_MARGIN);
        v7[9].m_pszData = v10;
        if ( this->m_bLeftRightRounded != 0 )
          break;
        if ( this->m_bIsOneNoteStyle != 0 )
        {
          v7[9].m_pszData = &v10[2 * CMFCBaseTabCtrl::AFX_TAB_IMAGE_MARGIN
                               - this->m_rectTabsArea.top
                               + this->m_rectTabsArea.bottom];
          goto LABEL_38;
        }
        if ( this->m_bIsVS2005Style != 0 )
        {
          v7[9].m_pszData = &v10[-this->m_rectTabsArea.top
                               - CMFCBaseTabCtrl::AFX_TAB_IMAGE_MARGIN
                               + this->m_rectTabsArea.bottom];
LABEL_38:
          v11 = this->m_rectTabsArea.bottom - this->m_rectTabsArea.top - CMFCBaseTabCtrl::AFX_TAB_IMAGE_MARGIN - 1;
LABEL_39:
          v65 = (LPRECT)v11;
        }
        if ( this->m_bActiveTabCloseButton != 0 && v63 == this->m_iActiveTab )
          v7[9].m_pszData += this->m_rectTabsArea.bottom - this->m_rectTabsArea.top - 2;
LABEL_44:
        if ( this->m_bIsActiveTabBold != 0 && v63 == this->m_iActiveTab )
          CDC::SelectObject(this: &v56, pFont: &afxGlobalData.fontRegular);
        m_pszData = (int)v7[9].m_pszData;
        if ( this->m_bScroll != 0 )
        {
          m_nTabMaxWidth = this->m_nTabMaxWidth;
          if ( m_nTabMaxWidth > 0 && m_pszData >= m_nTabMaxWidth )
            m_pszData = this->m_nTabMaxWidth;
        }
        top = this->m_rectTabsArea.top;
        v69.bottom = this->m_rectTabsArea.bottom - 2;
        v15 = v61;
        v16 = v61[3].top == 0;
        v69.left = left;
        v69.right = left + m_pszData;
        v17 = v61 + 1;
        v69.top = top;
        v18 = v61 + 1;
        v61[1].left = left;
        v18 = (tagRECT *)((char *)v18 + 4);
        v18->left = v69.top;
        v18 = (tagRECT *)((char *)v18 + 4);
        v18->left = v69.right;
        lprc = v17;
        v18->top = v69.bottom;
        if ( v16 )
        {
          m_pToolTip = this->m_pToolTip;
          if ( m_pToolTip != nullptr && m_pToolTip->m_hWnd != nullptr )
          {
            memset(&Rect, 0, sizeof(Rect));
            CToolTipCtrl::SetToolRect(this: m_pToolTip, pWnd: this, nIDTool: v61[2].right, lpRect: &Rect);
          }
        }
        else
        {
          if ( this->m_location == LOCATION_TOP )
          {
            OffsetRect(lprc, dx: 0, dy: 2);
            v17 = lprc;
            v15 = v61;
          }
          if ( this->m_bTabDocumentsMenu == 0 )
            goto LABEL_63;
          right = this->m_rectTabsArea.right;
          if ( v15[1].right <= right )
            goto LABEL_63;
          if ( v63 == this->m_iActiveTab
            && v63 == 0
            && right - v17->left >= (int)v65 + 2 * CMFCBaseTabCtrl::AFX_TAB_TEXT_MARGIN )
          {
            v15[1].right = right;
LABEL_63:
            v21 = this->m_pToolTip;
            if ( v21 != nullptr && v21->m_hWnd != nullptr )
            {
              v22 = v61[4].left != 0 || this->m_bCustomToolTips != 0;
              v23 = lprc;
              if ( lprc->left < this->m_rectTabsArea.left || v61[1].right > this->m_rectTabsArea.right )
                v22 = true;
              if ( this->m_bScroll != 0 && this->m_nTabMaxWidth > 0 && lprc->right - lprc->left < v61[2].top )
                v22 = true;
              if ( !v22 )
              {
                memset(&v70, 0, sizeof(v70));
                v23 = &v70;
              }
              CToolTipCtrl::SetToolRect(this: this->m_pToolTip, pWnd: this, nIDTool: v61[2].right, lpRect: v23);
              if ( v22 && v63 == this->m_iActiveTab )
                rc = *lprc;
            }
            v24 = left;
            v25 = lprc->right - lprc->left - (_DWORD)v65;
            this->m_nTabsTotalWidth += lprc->right - lprc->left + 1;
            m_nTabsTotalWidth = this->m_nTabsTotalWidth;
            left = v24 + v25 + 1;
            if ( v63 > 0 )
              this->m_nTabsTotalWidth = m_nTabsTotalWidth - (_DWORD)v65;
            if ( this->m_bFlat != 0 )
              v61[1].right += this->m_nTabsHeight / 2;
            goto LABEL_86;
          }
          v55 = lprc;
          v61[2].top = 0;
          SetRectEmpty(lprc: v55);
          this->m_bHiddenDocuments = 1;
        }
LABEL_86:
        if ( ++v63 >= this->m_iTabsNum )
        {
          v6 = left;
          goto LABEL_88;
        }
      }
      v7[9].m_pszData = &v10[(this->m_rectTabsArea.bottom - this->m_rectTabsArea.top) / 2];
      v11 = (this->m_rectTabsArea.bottom - this->m_rectTabsArea.top) / 2;
      goto LABEL_39;
    }
LABEL_88:
    if ( this->m_bScroll != 0 || v6 < this->m_rectTabsArea.right )
    {
      this->m_nTabsTotalWidth += this->m_nTabsHeight / 2;
    }
    else
    {
      v27 = (this->m_rectTabsArea.right - this->m_rectTabsArea.left) / v59 - 1;
      if ( this->m_bLeftRightRounded != 0 )
      {
        v28 = this->m_sizeImage.cx;
        if ( v28 + (this->m_rectTabsArea.bottom - this->m_rectTabsArea.top) / 2 <= (this->m_rectTabsArea.right
                                                                                  - this->m_rectTabsArea.left
                                                                                  - (this->m_rectTabsArea.bottom
                                                                                   - this->m_rectTabsArea.top)
                                                                                  / 3)
                                                                                 / v59 )
        {
          v27 = (this->m_rectTabsArea.right
               - this->m_rectTabsArea.left
               - (this->m_rectTabsArea.bottom - this->m_rectTabsArea.top) / 3)
              / v59;
        }
        else
        {
          v29 = this->m_rectTabsArea.bottom - this->m_rectTabsArea.top;
          v27 = v28 + (((int)v29 - HIDWORD(v29)) >> 1);
        }
      }
      v30 = 0;
      lprc = nullptr;
      v65 = (LPRECT)v59;
      if ( this->m_iTabsNum > 0 )
      {
        while ( v30 >= 0 && v30 < this->m_arTabs.m_nSize )
        {
          v31 = this->m_arTabs.m_pData[v30];
          if ( v31[13] != 0 )
          {
            v32 = v31[9];
            if ( v32 < v27 )
            {
              lprc = (LPRECT)((char *)lprc + v27 - v32);
              v65 = (LPRECT)((char *)v65 - 1);
            }
          }
          if ( ++v30 >= this->m_iTabsNum )
            goto LABEL_101;
        }
LABEL_10:
        AfxThrowInvalidArgException();
      }
LABEL_101:
      if ( (int)v65 > 0 )
      {
        cy = (tagRECT *)((int)lprc / (int)v65 + v27);
        left = this->m_rectTabsArea.left;
        v34 = 0;
        result.cy = (int)cy;
        v63 = 0;
        if ( this->m_iTabsNum > 0 )
        {
          while ( 1 )
          {
            if ( v34 < 0 || v34 >= this->m_arTabs.m_nSize )
              goto LABEL_10;
            v35 = (tagRECT *)this->m_arTabs.m_pData[v34];
            v61 = v35;
            if ( v35[3].top == 0 )
            {
              v36 = this->m_pToolTip;
              if ( v36 != nullptr && v36->m_hWnd != nullptr )
              {
                v54 = v35[2].right;
                memset(&v70, 0, sizeof(v70));
                CToolTipCtrl::SetToolRect(this: v36, pWnd: this, nIDTool: v54, lpRect: &v70);
              }
              goto LABEL_140;
            }
            RectTool.right = 0;
            if ( v35->bottom != 0 || v35->right != -1 )
            {
              RectTool.right = this->m_sizeImage.cx;
              RectTool.bottom = this->m_sizeImage.cy;
            }
            v37 = (tagRECT *)v35[2].top;
            v65 = cy;
            v60 = (void *)((int)v37 > (int)cy);
            if ( (int)v37 <= (int)cy )
              v65 = v37;
            if ( (int)cy >= RectTool.right + CMFCBaseTabCtrl::AFX_TAB_IMAGE_MARGIN )
            {
              if ( *(_DWORD *)(v35->top - 12) != 0 && v35[3].bottom == 0 )
                goto LABEL_122;
              v38 = RectTool.right + 2 * CMFCBaseTabCtrl::AFX_TAB_TEXT_MARGIN;
            }
            else
            {
              v38 = (this->m_rectTabsArea.right + 2 * this->m_nTabBorderSize - this->m_rectTabsArea.left) / v59;
            }
            v65 = (LPRECT)v38;
LABEL_122:
            if ( this->m_bLeftRightRounded != 0 )
              v65 = (LPRECT)((char *)v65 + (this->m_rectTabsArea.bottom - this->m_rectTabsArea.top) / 2 - 1);
            v39 = this->m_rectTabsArea.bottom - this->m_rectTabsArea.top;
            v40 = this->m_rectTabsArea.top;
            Rect.left = left;
            v41 = (char *)v65 + left;
            v42 = v61 + 1;
            Rect.right = (int)v65 + left;
            Rect.top = v40;
            v65 = v61 + 1;
            Rect.bottom = v39 + v40 - 2;
            v61[1].left = left;
            v42 = (tagRECT *)((char *)v42 + 4);
            v42->left = Rect.top;
            v42 = (tagRECT *)((char *)v42 + 4);
            v42->left = Rect.right;
            v42->top = Rect.bottom;
            v16 = this->m_bFlat == 0;
            left = (int)v41;
            if ( v16 )
            {
              if ( this->m_location == LOCATION_TOP )
                OffsetRect(lprc: v65, dx: 0, dy: 2);
              v43 = this->m_pToolTip;
              if ( v43 != nullptr && v43->m_hWnd != nullptr )
              {
                if ( v60 != nullptr || v61[4].left != 0 || this->m_bCustomToolTips != 0 )
                {
                  v45 = v65;
                  v44 = 1;
                }
                else
                {
                  memset(&v69, 0, sizeof(v69));
                  v44 = 0;
                  v45 = &v69;
                }
                CToolTipCtrl::SetToolRect(this: v43, pWnd: this, nIDTool: v61[2].right, lpRect: v45);
                if ( v44 != 0 && v63 == this->m_iActiveTab )
                  rc = *v65;
              }
            }
            if ( this->m_bLeftRightRounded != 0 )
              left += (this->m_rectTabsArea.bottom - this->m_rectTabsArea.top) / -2;
            if ( (int)lprc > 0 )
              ++left;
LABEL_140:
            v34 = v63 + 1;
            v63 = v34;
            if ( v34 >= this->m_iTabsNum )
              break;
            cy = (tagRECT *)result.cy;
          }
        }
      }
    }
    CDC::SelectObject(this: &v56, pFont);
    if ( this->m_bActiveTabCloseButton != 0 )
    {
      m_iActiveTab = this->m_iActiveTab;
      if ( m_iActiveTab >= 0 )
      {
        this->GetTabRect(this, a2: m_iActiveTab, a3: &this->m_rectCloseButton);
        this->m_rectCloseButton.left = this->m_rectCloseButton.right
                                     + this->m_rectCloseButton.top
                                     - this->m_rectCloseButton.bottom;
        InflateRect(lprc: &this->m_rectCloseButton, dx: -2, dy: -2);
        Instance = CMFCVisualManager::GetInstance();
        v48 = Instance->__vftable;
        pFont = (CFont *)this->m_location;
        v49 = v48->GetTabHorzMargin(this: Instance, a2: this);
        OffsetRect(lprc: &this->m_rectCloseButton, dx: -v49, dy: 2 * (pFont == (CFont *)1) - 1);
        v50 = this->m_pToolTipClose;
        if ( v50 != nullptr && v50->m_hWnd != nullptr )
        {
          CToolTipCtrl::SetToolRect(this: v50, pWnd: this, nIDTool: 1u, lpRect: &this->m_rectCloseButton);
          v51 = this->m_iActiveTab;
          if ( v51 < 0 || v51 >= this->m_arTabs.m_nSize )
            goto LABEL_10;
          v60 = this->m_arTabs.m_pData[v51];
          v52 = this->m_pToolTip;
          if ( v52 != nullptr && v52->m_hWnd != nullptr && v60 != nullptr && !IsRectEmpty(lprc: &rc) )
          {
            v53 = this->m_pToolTip;
            rc.right = this->m_rectCloseButton.left - 1;
            CToolTipCtrl::SetToolRect(this: v53, pWnd: this, nIDTool: *((_DWORD *)v60 + 10), lpRect: &rc);
          }
        }
      }
    }
    v71 = -1;
    CClientDC::~CClientDC(this: &v56);
    return;
  }
  v2 = 0;
  if ( this->m_iTabsNum > 0 )
  {
    while ( v2 >= 0 && v2 < this->m_arTabs.m_nSize )
    {
      SetRectEmpty(lprc: (LPRECT)this->m_arTabs.m_pData[v2++] + 1);
      if ( v2 >= this->m_iTabsNum )
        return;
    }
    goto LABEL_10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10405A13
// Name: public: static struct HICON__ __near * CMFCTabCtrl::GetDocumentIcon(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HICON__ *__stdcall CMFCTabCtrl::GetDocumentIcon(CDocument *nCmdID)
{
  HICON__ *hIcon; // [esp+0h] [ebp-4h] BYREF

  hIcon = nullptr;
  CMap<CWnd *,CWnd *,CImageList *,CImageList *>::Lookup(
    this: (CMap<unsigned int,unsigned int,CPane *,CPane *> *)&CMFCTabCtrl::m_mapDocIcons,
    key: nCmdID,
    rValue: (CPane **)&hIcon);
  return hIcon;
}

//------------------------------------------------------------------------------
// Address: 0x10405A35
// Name: protected: int CMFCTabCtrl::OnCreate(struct tagCREATESTRUCTA __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCTabCtrl::OnCreate(CMFCTabCtrl *this, tagCREATESTRUCTA *lpCreateStruct)
{
  int result; // eax
  HWND__ *m_hWnd; // ebx
  CMenuImages::IMAGE_STATE v5; // ecx
  HWND__ *v6; // ebx
  CMenuImages::IMAGE_STATE v7; // ecx
  HWND__ *v8; // ebx
  HWND__ *v9; // ebx
  CMenuImages::IMAGE_STATE v10; // eax
  HWND__ *v11; // eax
  CAfxStringMgr *StringManager; // eax
  HINSTANCE__ *StringResourceHandle; // eax
  int StringA; // eax
  HINSTANCE__ *v15; // eax
  int v16; // eax
  HINSTANCE__ *v17; // eax
  int v18; // eax
  char *m_pszData; // ebx
  COLORREF v20; // eax
  HBRUSH SolidBrush; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v23; // eax
  ATL::CSimpleStringT<char,0> v24; // [esp+10h] [ebp-24h] BYREF
  _DWORD v25[7]; // [esp+14h] [ebp-20h] BYREF
  int v26; // [esp+30h] [ebp-4h]

  result = CMFCBaseTabCtrl::OnCreate(this, lpCreateStruct);
  if ( result != -1 )
  {
    memset(v25, 0, 16);
    if ( this->m_bScroll != 0 )
    {
      if ( this->m_bFlat != 0 )
      {
        this->m_btnScrollFirst.Create_2(
          this: &this->m_btnScrollFirst,
          a2: &var,
          a3: 1342177280u,
          a4: (const tagRECT *)v25,
          a5: this,
          a6: -1u);
        CMFCButton::SetStdImage(
          this: &this->m_btnScrollFirst,
          id: IdArrowFirst,
          state: ImageBlack,
          idDisabled: IdArrowDown);
        this->m_btnScrollFirst.m_bDrawFocus = 0;
        this->m_btnScrollFirst.m_nFlatStyle = BUTTONSTYLE_FLAT;
        if ( this == (CMFCTabCtrl *)-4596 )
          m_hWnd = nullptr;
        else
          m_hWnd = this->m_btnScrollFirst.m_hWnd;
        CList<CFrameWnd *,CFrameWnd *>::AddTail(
          this: (CList<CFrameWnd *,CFrameWnd *> *)&this->m_lstButtons,
          newElement: (CFrameWnd *)m_hWnd);
      }
      this->m_btnScrollLeft.Create_2(
        this: &this->m_btnScrollLeft,
        a2: &var,
        a3: 1342177280u,
        a4: (const tagRECT *)v25,
        a5: this,
        a6: -1u);
      if ( this->m_bIsOneNoteStyle != 0 || this->m_bIsVS2005Style != 0 || this->m_bFlat != 0 )
        v5 = ImageBlack;
      else
        v5 = ImageDkGray;
      CMFCButton::SetStdImage(
        this: &this->m_btnScrollLeft,
        id: (CMenuImages::IMAGES_IDS)(4 * (this->m_bFlat == 0) + 17),
        state: v5,
        idDisabled: this->m_bFlat != 0 ? IdArrowDown : IdArrowLeftDsbldTab3d);
      this->m_btnScrollLeft.m_bDrawFocus = 0;
      this->m_btnScrollLeft.m_nFlatStyle = BUTTONSTYLE_FLAT;
      if ( this->m_bIsOneNoteStyle == 0 && this->m_bIsVS2005Style == 0 )
        CMFCButton::SetAutorepeatMode(this: &this->m_btnScrollLeft, nTimeDelay: 50);
      if ( this == (CMFCTabCtrl *)-852 )
        v6 = nullptr;
      else
        v6 = this->m_btnScrollLeft.m_hWnd;
      CList<CFrameWnd *,CFrameWnd *>::AddTail(
        this: (CList<CFrameWnd *,CFrameWnd *> *)&this->m_lstButtons,
        newElement: (CFrameWnd *)v6);
      this->m_btnScrollRight.Create_2(
        this: &this->m_btnScrollRight,
        a2: &var,
        a3: 1342177280u,
        a4: (const tagRECT *)v25,
        a5: this,
        a6: -1u);
      if ( this->m_bIsOneNoteStyle != 0 || this->m_bIsVS2005Style != 0 || this->m_bFlat != 0 )
        v7 = ImageBlack;
      else
        v7 = ImageDkGray;
      CMFCButton::SetStdImage(
        this: &this->m_btnScrollRight,
        id: (CMenuImages::IMAGES_IDS)(this->m_bFlat != 0 ? IdArrowRightLarge : IdArrowRightTab3d),
        state: v7,
        idDisabled: this->m_bFlat != 0 ? IdArrowDown : IdArrowRightDsbldTab3d);
      this->m_btnScrollRight.m_bDrawFocus = 0;
      this->m_btnScrollRight.m_nFlatStyle = BUTTONSTYLE_FLAT;
      if ( this->m_bIsOneNoteStyle == 0 && this->m_bIsVS2005Style == 0 )
        CMFCButton::SetAutorepeatMode(this: &this->m_btnScrollRight, nTimeDelay: 50);
      if ( this == (CMFCTabCtrl *)-2724 )
        v8 = nullptr;
      else
        v8 = this->m_btnScrollRight.m_hWnd;
      CList<CFrameWnd *,CFrameWnd *>::AddTail(
        this: (CList<CFrameWnd *,CFrameWnd *> *)&this->m_lstButtons,
        newElement: (CFrameWnd *)v8);
      if ( this->m_bFlat != 0 )
      {
        this->m_btnScrollLast.Create_2(
          this: &this->m_btnScrollLast,
          a2: &var,
          a3: 1342177280u,
          a4: (const tagRECT *)v25,
          a5: this,
          a6: -1u);
        CMFCButton::SetStdImage(
          this: &this->m_btnScrollLast,
          id: IdArrowLast,
          state: ImageBlack,
          idDisabled: IdArrowDown);
        this->m_btnScrollLast.m_bDrawFocus = 0;
        this->m_btnScrollLast.m_nFlatStyle = BUTTONSTYLE_FLAT;
        if ( this == (CMFCTabCtrl *)-6468 )
          v9 = nullptr;
        else
          v9 = this->m_btnScrollLast.m_hWnd;
        CList<CFrameWnd *,CFrameWnd *>::AddTail(
          this: (CList<CFrameWnd *,CFrameWnd *> *)&this->m_lstButtons,
          newElement: (CFrameWnd *)v9);
      }
      this->m_btnClose.Create_2(
        this: &this->m_btnClose,
        a2: &var,
        a3: 1342177280u,
        a4: (const tagRECT *)v25,
        a5: this,
        a6: -1u);
      if ( this->m_bIsOneNoteStyle != 0 || this->m_bIsVS2005Style != 0 || this->m_bFlat != 0 )
        v10 = ImageBlack;
      else
        v10 = ImageDkGray;
      CMFCButton::SetStdImage(this: &this->m_btnClose, id: IdClose, state: v10, idDisabled: IdArrowDown);
      this->m_btnClose.m_bDrawFocus = 0;
      this->m_btnClose.m_nFlatStyle = BUTTONSTYLE_FLAT;
      if ( this == (CMFCTabCtrl *)-8340 )
        v11 = nullptr;
      else
        v11 = this->m_btnClose.m_hWnd;
      CList<CFrameWnd *,CFrameWnd *>::AddTail(
        this: (CList<CFrameWnd *,CFrameWnd *> *)&this->m_lstButtons,
        newElement: (CFrameWnd *)v11);
      if ( this->m_bFlat == 0 && this->m_bScroll != 0 )
      {
        StringManager = AfxGetStringManager();
        ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v24, pStringMgr: StringManager);
        v26 = 0;
        StringResourceHandle = AfxFindStringResourceHandle(__formal: 0x3EA0u);
        if ( StringResourceHandle != nullptr )
          StringA = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                      this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v24,
                      hInstance: StringResourceHandle,
                      nID: 0x3EA0u);
        else
          StringA = 0;
        if ( StringA == 0
          || ((CMFCButton::SetTooltip(this: &this->m_btnClose, lpszToolTipText: v24.m_pszData),
               (v15 = AfxFindStringResourceHandle(__formal: 0x3EA2u)) != nullptr)
            ? (v16 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                       this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v24,
                       hInstance: v15,
                       nID: 0x3EA2u))
            : (v16 = 0),
              v16 == 0
           || ((CMFCButton::SetTooltip(this: &this->m_btnScrollLeft, lpszToolTipText: v24.m_pszData),
                (v17 = AfxFindStringResourceHandle(__formal: 0x3EA3u)) != nullptr)
             ? (v18 = ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
                        this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v24,
                        hInstance: v17,
                        nID: 0x3EA3u))
             : (v18 = 0),
               v18 == 0)) )
        {
          AfxThrowInvalidArgException();
        }
        m_pszData = v24.m_pszData;
        CMFCButton::SetTooltip(this: &this->m_btnScrollRight, lpszToolTipText: v24.m_pszData);
        v26 = -1;
        ATL::CStringData::Release(this: (ATL::CStringData *)m_pszData - 1);
      }
    }
    if ( this->m_bSharedScroll != 0 )
      this->m_wndScrollWnd.Create(
        this: &this->m_wndScrollWnd,
        a2: 1342177280u,
        a3: (const tagRECT *)v25,
        a4: this,
        a5: -1u);
    if ( this->m_bFlat != 0 )
    {
      v20 = this->GetActiveTabColor(this);
      SolidBrush = CreateSolidBrush(color: v20);
      CGdiObject::Attach(this: &this->m_brActiveTab, hObject: SolidBrush);
    }
    else if ( CTooltipManager::CreateToolTip(pToolTip: &this->m_pToolTip, pWndParent: this, nType: 4u) != 0 )
    {
      CWnd::SetWindowPos(
        this: this->m_pToolTip,
        pWndInsertAfter: &CWnd::wndTop,
        x: -1,
        y: -1,
        cx: -1,
        cy: -1,
        nFlags: 0x13u);
    }
    CTooltipManager::CreateToolTip(pToolTip: &this->m_pToolTipClose, pWndParent: this, nType: 4u);
    if ( afxGlobalData.m_hcurStretch == nullptr )
    {
      AfxGetModuleState();
      ModuleState = AfxGetModuleState();
      afxGlobalData.m_hcurStretch = LoadCursorW(
                                      hInstance: ModuleState->m_hCurrentResourceHandle,
                                      lpCursorName: (LPCWSTR)0x7904);
    }
    if ( afxGlobalData.m_hcurStretchVert == nullptr )
    {
      AfxGetModuleState();
      v23 = AfxGetModuleState();
      afxGlobalData.m_hcurStretchVert = LoadCursorW(
                                          hInstance: v23->m_hCurrentResourceHandle,
                                          lpCursorName: (LPCWSTR)0x7905);
    }
    this->SetTabsHeight(this);
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405EA4
// Name: public: void CMFCTabCtrl::EnableTabDocumentsMenu(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTabCtrl::EnableTabDocumentsMenu(CMFCTabCtrl *this, char *bEnable)
{
  CAfxStringMgr *StringManager; // eax
  unsigned int v4; // esi
  HINSTANCE__ *StringResourceHandle; // eax
  char *v6; // esi
  int m_iActiveTab; // eax

  if ( this->m_bFlat == 0 || this->m_bScroll != 0 )
  {
    this->m_bTabDocumentsMenu = (int)bEnable;
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(
      this: (ATL::CSimpleStringT<char,0> *)&bEnable,
      pStringMgr: StringManager);
    v4 = this->m_bTabDocumentsMenu != 0 ? 17043 : 16035;
    StringResourceHandle = AfxFindStringResourceHandle(__formal: v4);
    if ( StringResourceHandle == nullptr
      || ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
           this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&bEnable,
           hInstance: StringResourceHandle,
           nID: v4) == 0 )
    {
      AfxThrowInvalidArgException();
    }
    v6 = bEnable;
    if ( this->m_bScroll != 0 )
      CMFCButton::SetTooltip(this: &this->m_btnScrollRight, lpszToolTipText: bEnable);
    CMFCTabCtrl::SetScrollButtons(this);
    this->RecalcLayout(this);
    m_iActiveTab = this->m_iActiveTab;
    this->m_nTabsHorzOffset = 0;
    this->m_nFirstVisibleTab = 0;
    if ( m_iActiveTab >= 0 )
      this->EnsureVisible(this, a2: m_iActiveTab);
    ATL::CStringData::Release(this: (ATL::CStringData *)v6 - 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10405F6E
// Name: protected: void CMFCTabCtrl::OnPaint(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTabCtrl::OnPaint(CMFCTabCtrl *this)
{
  CDC *p_m_dcMem; // edi
  CMFCVisualManager *Instance; // eax
  void *v4; // eax
  bool v5; // zf
  CMFCVisualManager *v6; // eax
  int v7; // eax
  HBRUSH m_hObject; // eax
  CMFCVisualManager *v9; // eax
  HBRUSH v10; // eax
  CMFCBaseTabCtrl::Location m_location; // ecx
  void *bottom; // eax
  int m_bFlat; // eax
  void *v14; // esi
  tagRECT *p_rect; // eax
  int v16; // esi
  void *v17; // esi
  CDC *v18; // edi
  CFont *p_m_fntTabs; // eax
  HRGN v20; // eax
  int m_iTabsNum; // edi
  CDC *v22; // esi
  int m_iActiveTab; // eax
  CMFCTabInfo *v24; // edi
  CDC_vtbl *v25; // edi
  unsigned int v26; // eax
  _DWORD *v27; // edi
  int v28; // ecx
  int v29; // eax
  COLORREF v30; // eax
  int v31; // esi
  int v32; // eax
  CMFCVisualManager *v33; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-150h]
  COLORREF v35; // [esp-8h] [ebp-150h]
  COLORREF v36; // [esp-4h] [ebp-14Ch]
  int top; // [esp-4h] [ebp-14Ch]
  int v38; // [esp-4h] [ebp-14Ch]
  unsigned int v39; // [esp+14h] [ebp-134h] BYREF
  CPen v40; // [esp+18h] [ebp-130h] BYREF
  CFont *v41; // [esp+20h] [ebp-128h]
  unsigned int v42; // [esp+24h] [ebp-124h] BYREF
  CFont *v43; // [esp+28h] [ebp-120h]
  HBRUSH hbr; // [esp+2Ch] [ebp-11Ch] BYREF
  CPen v45; // [esp+30h] [ebp-118h] BYREF
  CPoint result; // [esp+38h] [ebp-110h] BYREF
  CPen v47; // [esp+40h] [ebp-108h] BYREF
  unsigned int clrBottomRight; // [esp+48h] [ebp-100h] BYREF
  unsigned int clrTopLeft; // [esp+4Ch] [ebp-FCh] BYREF
  unsigned int v50; // [esp+50h] [ebp-F8h] BYREF
  CPen v51; // [esp+54h] [ebp-F4h] BYREF
  CFont *pFont; // [esp+5Ch] [ebp-ECh] BYREF
  unsigned int crColor; // [esp+60h] [ebp-E8h] BYREF
  CPoint v54; // [esp+64h] [ebp-E4h] BYREF
  CGdiObject v55; // [esp+6Ch] [ebp-DCh] BYREF
  CDC *v56; // [esp+74h] [ebp-D4h]
  CPaintDC v57; // [esp+78h] [ebp-D0h] BYREF
  CMemDC v58; // [esp+CCh] [ebp-7Ch] BYREF
  tagRECT Rect; // [esp+108h] [ebp-40h] BYREF
  tagRECT rect; // [esp+118h] [ebp-30h] BYREF
  RECT rc; // [esp+128h] [ebp-20h] BYREF
  int v62; // [esp+144h] [ebp-4h]

  CPaintDC::CPaintDC(this: &v57, pWnd: this);
  v62 = 0;
  CMemDC::CMemDC(this: &v58, dc: &v57, pWnd: (HDC__ *)this);
  LOBYTE(v62) = 1;
  p_m_dcMem = &v58.m_dcMem;
  if ( v58.m_bMemDC == 0 )
    p_m_dcMem = v58.m_dc;
  v56 = p_m_dcMem;
  CDC::GetClipBox(this: &v57, lpRect: &this->m_rectCurrClip);
  pFont = nullptr;
  hbr = nullptr;
  Instance = CMFCVisualManager::GetInstance();
  Instance->GetTabFrameColors(
    this: Instance,
    a2: this,
    a3: &crColor,
    a4: &v42,
    a5: &v50,
    a6: &clrTopLeft,
    a7: &clrBottomRight,
    a8: &v39,
    a9: (CBrush **)&pFont,
    a10: (CBrush **)&hbr);
  m_hWnd = this->m_hWnd;
  memset(&Rect, 0, sizeof(Rect));
  GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
  v41 = CDC::SelectObject(this: p_m_dcMem, pFont);
  if ( v41 == nullptr )
    goto LABEL_4;
  CPen::CPen(this: &v45, nPenStyle: 0, nWidth: 1, crColor);
  LOBYTE(v62) = 2;
  CPen::CPen(this: &v47, nPenStyle: 0, nWidth: 1, crColor: v42);
  LOBYTE(v62) = 3;
  CPen::CPen(this: &v40, nPenStyle: 0, nWidth: 1, crColor: v50);
  LOBYTE(v62) = 4;
  v43 = CDC::SelectObject(this: p_m_dcMem, pFont: (CFont *)&v45);
  if ( v43 == nullptr )
    goto LABEL_4;
  v4 = (void *)this->GetTabBorderSize(this);
  v5 = this->m_location == LOCATION_BOTTOM;
  rect = Rect;
  v55.m_hObject = v4;
  if ( v5 )
    rect.top = this->m_rectTabsArea.top;
  else
    rect.bottom = this->m_rectTabsArea.bottom;
  CDC::ExcludeClipRect(this: v56, lpRect: &this->m_rectWndArea);
  v6 = CMFCVisualManager::GetInstance();
  v7 = ((int (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int, CMFCTabCtrl *))v6->OnEraseTabsFrame)(
         a1: v6,
         a2: v56,
         a3: Rect.left,
         a4: Rect.top,
         a5: Rect.right,
         a6: Rect.bottom,
         a7: this);
  v5 = this->m_bDrawFrame == 0;
  v54.y = v7;
  if ( v5 && v7 == 0 )
  {
    m_hObject = (HBRUSH)pFont;
    if ( pFont != nullptr )
      m_hObject = (HBRUSH)pFont->m_hObject;
    FillRect(hDC: v56->m_hDC, lprc: &Rect, hbr: m_hObject);
  }
  v9 = CMFCVisualManager::GetInstance();
  ((void (__thiscall *)(CMFCVisualManager *, CDC *, int, int, int, int, CMFCTabCtrl *))v9->OnEraseTabsArea)(
    a1: v9,
    a2: v56,
    a3: rect.left,
    a4: rect.top,
    a5: rect.right,
    a6: rect.bottom,
    a7: this);
  rc = Rect;
  if ( v55.m_hObject == nullptr )
  {
    if ( this->m_location != LOCATION_BOTTOM )
      rc.top = this->m_rectTabsArea.bottom - 1;
    else
      rc.bottom = this->m_rectTabsArea.top + 1;
    v10 = hbr;
    if ( this->m_bFlat == 0 )
      v10 = (HBRUSH)pFont;
    if ( v10 != nullptr )
      v10 = *((HBRUSH *)v10 + 1);
    FrameRect(hDC: v56->m_hDC, lprc: &rc, hbr: v10);
    goto LABEL_71;
  }
  m_location = this->m_location;
  if ( m_location != LOCATION_BOTTOM )
    bottom = (void *)this->m_rectTabsArea.bottom;
  else
    bottom = (void *)this->m_rectTabsArea.top;
  v51.m_hObject = bottom;
  m_bFlat = this->m_bFlat;
  if ( m_bFlat == 0 )
  {
    if ( m_location != LOCATION_BOTTOM )
      rc.top = this->m_rectTabsArea.bottom;
    else
      rc.bottom = this->m_rectTabsArea.top;
  }
  if ( this->m_bFlatFrame != 0 )
  {
    rect = rc;
    if ( m_bFlat != 0 )
    {
      if ( m_location != LOCATION_BOTTOM )
        rect.top = this->m_rectTabsArea.bottom - 1;
      else
        rect.bottom = this->m_rectTabsArea.top + 1;
    }
    InflateRect(lprc: &rc, dx: -1, dy: -1);
    if ( this->m_bDrawFrame != 0 && v54.y == 0 && rc.right - rc.left > 0 && rc.bottom - rc.top > 0 )
    {
      PatBlt(hdc: v56->m_hDC, x: rc.left, y: rc.top, w: (int)v55.m_hObject, h: rc.bottom - rc.top, rop: 0xF00021u);
      PatBlt(hdc: v56->m_hDC, x: rc.left, y: rc.top, w: rc.right - rc.left, h: (int)v55.m_hObject, rop: 0xF00021u);
      PatBlt(
        hdc: v56->m_hDC,
        x: rc.right - (unsigned int)v55.m_hObject - 1,
        y: rc.top,
        w: (int)v55.m_hObject + 1,
        h: rc.bottom - rc.top,
        rop: 0xF00021u);
      PatBlt(
        hdc: v56->m_hDC,
        x: rc.left,
        y: rc.bottom - (unsigned int)v55.m_hObject,
        w: rc.right - rc.left,
        h: (int)v55.m_hObject,
        rop: 0xF00021u);
      if ( this->m_location != LOCATION_BOTTOM )
        PatBlt(
          hdc: v56->m_hDC,
          x: rc.left,
          y: rc.top,
          w: rc.right - rc.left,
          h: this->m_rectWndArea.top - rc.top,
          rop: 0xF00021u);
      else
        PatBlt(
          hdc: v56->m_hDC,
          x: rc.left,
          y: this->m_rectWndArea.bottom,
          w: rc.right - rc.left,
          h: rc.bottom - this->m_rectWndArea.bottom,
          rop: 0xF00021u);
    }
    if ( this->m_bFlat != 0 )
    {
      CDC::SelectObject(this: v56, pFont: (CFont *)&v47);
      v14 = v55.m_hObject;
      CDC::MoveTo(this: v56, &result, x: (int)v55.m_hObject + rc.left, y: (int)v51.m_hObject);
      CDC::LineTo(this: v56, x: rc.right - (_DWORD)v14, y: (int)v51.m_hObject);
    }
    CDC::Draw3dRect(this: v56, lpRect: &rect, clrTopLeft, clrBottomRight: clrTopLeft);
    if ( this->GetTabsHeight(this) == 0 )
    {
      v36 = clrTopLeft;
      p_rect = &rect;
      v35 = clrTopLeft;
LABEL_69:
      CDC::Draw3dRect(this: v56, lpRect: p_rect, clrTopLeft: v35, clrBottomRight: v36);
      goto LABEL_71;
    }
    if ( this->m_bDrawFrame != 0 )
      CDC::Draw3dRect(this: v56, lpRect: &rect, clrTopLeft: crColor, clrBottomRight: crColor);
    if ( this->m_bIsOneNoteStyle == 0 )
    {
      v16 = rect.right - 1;
      if ( this->m_bDrawFrame == 0 )
        v16 -= (int)v55.m_hObject;
      if ( this->m_location != LOCATION_BOTTOM )
      {
        CDC::SelectObject(this: v56, pFont: (CFont *)&v40);
        CDC::MoveTo(this: v56, &result, x: rect.left, y: rect.top);
        top = rect.top;
      }
      else
      {
        CDC::SelectObject(this: v56, pFont: (CFont *)&v47);
        CDC::MoveTo(this: v56, &result, x: rect.left, y: rect.bottom - 1);
        top = rect.bottom - 1;
      }
      CDC::LineTo(this: v56, x: v16, y: top);
    }
  }
  else if ( this->m_bDrawFrame != 0 )
  {
    CDC::Draw3dRect(this: v56, lpRect: &rc, clrTopLeft: v50, clrBottomRight);
    InflateRect(lprc: &rc, dx: -1, dy: -1);
    CDC::Draw3dRect(this: v56, lpRect: &rc, clrTopLeft: v39, clrBottomRight: crColor);
    InflateRect(lprc: &rc, dx: -1, dy: -1);
    if ( v54.y != 0 || rc.right - rc.left <= 0 || rc.bottom - rc.top <= 0 )
    {
      InflateRect(lprc: &rc, dx: -2, dy: -2);
      goto LABEL_71;
    }
    PatBlt(hdc: v56->m_hDC, x: rc.left, y: rc.top, w: (int)v55.m_hObject, h: rc.bottom - rc.top, rop: 0xF00021u);
    PatBlt(hdc: v56->m_hDC, x: rc.left, y: rc.top, w: rc.right - rc.left, h: (int)v55.m_hObject, rop: 0xF00021u);
    PatBlt(
      hdc: v56->m_hDC,
      x: rc.right - (unsigned int)v55.m_hObject,
      y: rc.top,
      w: (int)v55.m_hObject,
      h: rc.bottom - rc.top,
      rop: 0xF00021u);
    PatBlt(
      hdc: v56->m_hDC,
      x: rc.left,
      y: rc.bottom - (unsigned int)v55.m_hObject,
      w: rc.right - rc.left,
      h: (int)v55.m_hObject,
      rop: 0xF00021u);
    if ( this->m_location != LOCATION_BOTTOM )
      PatBlt(
        hdc: v56->m_hDC,
        x: rc.left,
        y: rc.top,
        w: rc.right - rc.left,
        h: this->m_rectWndArea.top - rc.top,
        rop: 0xF00021u);
    else
      PatBlt(
        hdc: v56->m_hDC,
        x: rc.left,
        y: this->m_rectWndArea.bottom,
        w: rc.right - rc.left,
        h: rc.bottom - this->m_rectWndArea.bottom,
        rop: 0xF00021u);
    if ( this->m_bFlat != 0 )
    {
      CDC::SelectObject(this: v56, pFont: (CFont *)&v47);
      v17 = v55.m_hObject;
      CDC::MoveTo(this: v56, &result, x: (int)v55.m_hObject + rc.left, y: (int)v51.m_hObject);
      CDC::LineTo(this: v56, x: rc.right - (_DWORD)v17, y: (int)v51.m_hObject);
    }
    if ( (int)v55.m_hObject > 2 )
      InflateRect(lprc: &rc, dx: 2 - (unsigned int)v55.m_hObject, dy: 2 - (unsigned int)v55.m_hObject);
    if ( rc.right - rc.left > 0 && rc.bottom - rc.top > 0 )
    {
      v36 = v50;
      p_rect = &rc;
      v35 = clrBottomRight;
      goto LABEL_69;
    }
  }
LABEL_71:
  v18 = v56;
  if ( this->m_bTopEdge != 0 && this->m_location == LOCATION_TOP )
  {
    CDC::SelectObject(this: v56, pFont: (CFont *)&v45);
    CDC::MoveTo(this: v18, &result, x: Rect.left, y: this->m_rectTabsArea.bottom);
    CDC::LineTo(this: v18, x: Rect.left, y: Rect.top);
    CDC::LineTo(this: v18, x: Rect.right - 1, y: Rect.top);
    CDC::LineTo(this: v18, x: Rect.right - 1, y: this->m_rectTabsArea.bottom);
  }
  p_m_fntTabs = &this->m_fntTabs;
  if ( this->m_bFlat == 0 )
    p_m_fntTabs = &afxGlobalData.fontRegular;
  result.y = (int)v18->SelectObject(this: v18, a2: p_m_fntTabs);
  if ( result.y == 0 )
    goto LABEL_4;
  CDC::SetBkMode(this: v18, nBkMode: 1);
  v18->SetTextColor(this: v18, a2: afxGlobalData.clrBtnText);
  if ( this->m_rectTabsArea.right - this->m_rectTabsArea.left > 5
    && this->m_rectTabsArea.bottom - this->m_rectTabsArea.top > 5 )
  {
    rect = (tagRECT)this->m_rectTabsArea;
    InflateRect(lprc: &rect, dx: 1, dy: (int)v55.m_hObject);
    v55.m_hObject = nullptr;
    v55.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
    LOBYTE(v62) = 5;
    v20 = CreateRectRgnIndirect(lprect: &rect);
    CGdiObject::Attach(this: &v55, hObject: v20);
    m_iTabsNum = this->m_iTabsNum;
    v22 = v56;
    while ( --m_iTabsNum >= 0 )
    {
      if ( m_iTabsNum >= this->m_arTabs.m_nSize )
        goto LABEL_4;
      v5 = *((_DWORD *)this->m_arTabs.m_pData[m_iTabsNum] + 13) == 0;
      v54.y = (int)this->m_arTabs.m_pData[m_iTabsNum];
      if ( !v5 )
      {
        this->m_iCurTab = m_iTabsNum;
        if ( m_iTabsNum != this->m_iActiveTab )
        {
          CDC::SelectClipRgn(this: v22, pRgn: (CRgn *)&v55);
          if ( this->m_bFlat != 0 )
          {
            CDC::SelectObject(this: v22, pFont: (CFont *)&v47);
            this->DrawFlatTab(this, a2: v22, a3: (CMFCTabInfo *)v54.y, a4: 0);
          }
          else
          {
            this->Draw3DTab(this, a2: v22, a3: (CMFCTabInfo *)v54.y, a4: 0);
          }
        }
      }
    }
    if ( this->m_iActiveTab < 0 )
      goto LABEL_103;
    v22->SetTextColor(this: v22, a2: afxGlobalData.clrWindowText);
    m_iActiveTab = this->m_iActiveTab;
    if ( m_iActiveTab >= 0 && m_iActiveTab < this->m_arTabs.m_nSize )
    {
      v24 = (CMFCTabInfo *)this->m_arTabs.m_pData[m_iActiveTab];
      this->m_iCurTab = m_iActiveTab;
      v51.m_hObject = v24;
      CDC::SelectClipRgn(this: v22, pRgn: (CRgn *)&v55);
      if ( this->m_bFlat != 0 )
      {
        CDC::SelectObject(this: v22, pFont: (CFont *)&this->m_brActiveTab);
        v22->SelectObject(this: v22, a2: &this->m_fntTabsBold);
        v25 = v22->__vftable;
        v26 = this->GetActiveTabTextColor(this);
        v25->SetTextColor(this: v22, a2: v26);
        CDC::SelectObject(this: v22, pFont: (CFont *)&v47);
        v27 = v51.m_hObject;
        this->DrawFlatTab(this, a2: v22, a3: (CMFCTabInfo *)v51.m_hObject, a4: 1);
        v28 = this->m_rectTabsArea.left + 1;
        v29 = v27[4] + 1;
        v54.y = v28;
        if ( v28 <= v29 )
          v54.y = v29;
        if ( v27[6] > v28 )
        {
          v30 = this->GetActiveTabColor(this);
          CPen::CPen(this: &v51, nPenStyle: 0, nWidth: 1, crColor: v30);
          LOBYTE(v62) = 6;
          CDC::SelectObject(this: v22, pFont: (CFont *)&v51);
          if ( this->m_location != LOCATION_BOTTOM )
          {
            CDC::MoveTo(this: v22, result: &v54, x: v54.y, y: v27[7]);
            v38 = v27[7];
          }
          else
          {
            CDC::MoveTo(this: v22, result: &v54, x: v54.y, y: v27[5]);
            v38 = v27[5];
          }
          CDC::LineTo(this: v22, x: v27[6], y: v38);
          CDC::SelectObject(this: v22, pFont: v43);
          LOBYTE(v62) = 5;
          v51.__vftable = (CPen_vtbl *)&CPen::`vftable';
          CGdiObject::~CGdiObject(this: &v51);
        }
      }
      else
      {
        if ( this->m_bIsActiveTabBold != 0 && (this->IsMDITabGroup(this) == 0 || this->m_bIsActiveInMDITabGroup != 0) )
          v22->SelectObject(this: v22, a2: &afxGlobalData.fontBold);
        this->Draw3DTab(this, a2: v22, a3: v24, a4: 1);
      }
LABEL_103:
      CDC::SelectClipRgn(this: v22, pRgn: nullptr);
      LOBYTE(v62) = 4;
      v55.__vftable = (CGdiObject_vtbl *)&CRgn::`vftable';
      CGdiObject::~CGdiObject(this: &v55);
      v18 = v56;
      goto LABEL_104;
    }
LABEL_4:
    AfxThrowInvalidArgException();
  }
LABEL_104:
  if ( !IsRectEmpty(lprc: &this->m_rectTabSplitter) )
  {
    CDC::FillRect(this: v56, lpRect: &this->m_rectTabSplitter, pBrush: (CBrush *)pFont);
    rect = (tagRECT)this->m_rectTabSplitter;
    CDC::Draw3dRect(this: v56, lpRect: &rect, clrTopLeft: clrBottomRight, clrBottomRight: crColor);
    InflateRect(lprc: &rect, dx: -1, dy: -1);
    CDC::Draw3dRect(this: v56, lpRect: &rect, clrTopLeft: v50, clrBottomRight: crColor);
    v18 = v56;
  }
  if ( this->m_bFlat != 0 && this->m_nTabsHorzOffset > 0 )
  {
    CDC::SelectObject(this: v18, pFont: (CFont *)&v45);
    v31 = this->m_rectTabsArea.left - 1;
    if ( this->m_location != LOCATION_BOTTOM )
    {
      CDC::MoveTo(this: v18, result: &v54, x: v31, y: this->m_rectTabsArea.bottom);
      v32 = this->m_rectTabsArea.top + 2;
    }
    else
    {
      CDC::MoveTo(this: v18, result: &v54, x: v31, y: this->m_rectTabsArea.top + 1);
      v32 = this->m_rectTabsArea.bottom - 2;
    }
    CDC::LineTo(this: v18, x: v31, y: v32);
  }
  if ( !IsRectEmpty(lprc: &this->m_rectResize) )
  {
    v33 = CMFCVisualManager::GetInstance();
    ((void (__thiscall *)(CMFCVisualManager *, CDC *, CMFCTabCtrl *, bool, int, int, int, int, CFont *, CPen *))v33->OnDrawTabResizeBar)(
      a1: v33,
      a2: v56,
      a3: this,
      a4: this->m_ResizeMode == RESIZE_VERT,
      a5: this->m_rectResize.left,
      a6: this->m_rectResize.top,
      a7: this->m_rectResize.right,
      a8: this->m_rectResize.bottom,
      a9: pFont,
      a10: &v45);
    v18 = v56;
  }
  v18->SelectObject(this: v18, a2: (CFont *)result.y);
  CDC::SelectObject(this: v18, pFont: v41);
  CDC::SelectObject(this: v18, pFont: v43);
  if ( v58.m_bMemDC != 0 )
    CDC::ExcludeClipRect(this: &v57, lpRect: &this->m_rectWndArea);
  LOBYTE(v62) = 3;
  v40.__vftable = (CPen_vtbl *)&CPen::`vftable';
  CGdiObject::~CGdiObject(this: &v40);
  LOBYTE(v62) = 2;
  v47.__vftable = (CPen_vtbl *)&CPen::`vftable';
  CGdiObject::~CGdiObject(this: &v47);
  LOBYTE(v62) = 1;
  v45.__vftable = (CPen_vtbl *)&CPen::`vftable';
  CGdiObject::~CGdiObject(this: &v45);
  LOBYTE(v62) = 0;
  CMemDC::~CMemDC(this: &v58);
  v62 = -1;
  CPaintDC::~CPaintDC(this: &v57);
}

//------------------------------------------------------------------------------
// Address: 0x10406C2A
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCTabCtrl::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCTabCtrl::GetMessageMap(CMFCTabCtrl *this)
{
  return (const AFX_MSGMAP *)&off_1068B0C8;
}

//------------------------------------------------------------------------------
// Address: 0x10406C30
// Name: public: virtual void CMFCTabCtrl::OnShowTabDocumentsMenu(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCTabCtrl::OnShowTabDocumentsMenu(CMFCTabCtrl *this, CPoint point)
{
  CMFCTabCtrl *v2; // edi
  HMENU PopupMenu; // eax
  int v4; // eax
  int v5; // ecx
  int v6; // ebx
  CDocument *v7; // edi
  CAfxStringMgr *StringManager; // eax
  int MenuItemCount; // eax
  int v10; // eax
  HWND v11; // ebx
  unsigned int *v12; // eax
  HWND m_hWnd; // esi
  CMFCTabCtrl_vtbl *v14; // edx
  char *v15; // [esp+0h] [ebp-40h]
  CMenu v16; // [esp+14h] [ebp-2Ch] BYREF
  CMFCTabCtrl *v17; // [esp+1Ch] [ebp-24h]
  int nMenuResult; // [esp+20h] [ebp-20h]
  int i; // [esp+24h] [ebp-1Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strDummyAmpSeq; // [esp+28h] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strMenuItem; // [esp+2Ch] [ebp-14h]
  HICON__ *hIcon; // [esp+30h] [ebp-10h] BYREF
  int v23; // [esp+3Ch] [ebp-4h]

  v2 = this;
  v17 = this;
  if ( afxContextMenuManager != nullptr )
  {
    v16.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
    v16.m_hMenu = nullptr;
    v23 = 0;
    PopupMenu = CreatePopupMenu();
    CMenu::Attach(this: &v16, hMenu: PopupMenu);
    v4 = 0;
    for ( nMenuResult = 0; v4 < v2->m_iTabsNum; nMenuResult = v4 )
    {
      if ( v4 < 0 || v4 >= v2->m_arTabs.m_nSize )
        AfxThrowInvalidArgException();
      v5 = (int)&v2->m_arTabs.m_pData[v4];
      v6 = *(_DWORD *)v5;
      if ( *(_DWORD *)(*(_DWORD *)v5 + 52) != 0 )
      {
        v7 = (CDocument *)(-100 - v4);
        hIcon = (HICON__ *)&ATL::CSimpleStringT<char,0>::CloneData(pData: (ATL::CStringData *)(*(_DWORD *)(v6 + 4) - 16))[1];
        LOBYTE(v23) = 1;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
          this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&i,
          pszSrc: &byte_10682EAC);
        LOBYTE(v23) = 2;
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Replace(
          this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&hIcon,
          pszOld: "&&",
          pszNew: (char *)i);
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Replace(
          this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&hIcon,
          pszOld: "&",
          pszNew: "&&");
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Replace(
          this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&hIcon,
          pszOld: (char *)i,
          pszNew: "&&");
        strMenuItem.m_pszData = nullptr;
        if ( GetMenuItemCount(hMenu: v16.m_hMenu) <= 0 )
        {
LABEL_9:
          AppendMenuA(hMenu: v16.m_hMenu, uFlags: 0, uIDNewItem: (UINT_PTR)v7, lpNewItem: (LPCSTR)hIcon);
        }
        else
        {
          while ( 1 )
          {
            StringManager = AfxGetStringManager();
            ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strDummyAmpSeq, pStringMgr: StringManager);
            LOBYTE(v23) = 3;
            CMenu::GetMenuStringA(
              this: &v16,
              nIDItem: (UINT)strMenuItem.m_pszData,
              rString: &strDummyAmpSeq,
              nFlags: 0x400u);
            if ( ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CompareNoCase(
                   this: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&hIcon,
                   psz: strDummyAmpSeq.m_pszData) < 0 )
              break;
            LOBYTE(v23) = 2;
            ATL::CStringData::Release(this: (ATL::CStringData *)strDummyAmpSeq.m_pszData - 1);
            ++strMenuItem.m_pszData;
            MenuItemCount = GetMenuItemCount(hMenu: v16.m_hMenu);
            if ( (int)strMenuItem.m_pszData >= MenuItemCount )
              goto LABEL_9;
          }
          InsertMenuA(
            hMenu: v16.m_hMenu,
            uPosition: (UINT)strMenuItem.m_pszData,
            uFlags: 0x400u,
            uIDNewItem: (UINT_PTR)v7,
            lpNewItem: (LPCSTR)hIcon);
          LOBYTE(v23) = 2;
          ATL::CStringData::Release(this: (ATL::CStringData *)strDummyAmpSeq.m_pszData - 1);
        }
        v10 = *(_DWORD *)(v6 + 32);
        if ( v10 != 0 && *(_DWORD *)(v10 + 32) != 0 )
        {
          strMenuItem.m_pszData = (char *)SendMessageA(hWnd: *(HWND *)(v10 + 32), Msg: 0x7Fu, wParam: 0, lParam: 0);
          if ( strMenuItem.m_pszData == nullptr )
          {
            v11 = *(HWND *)(v6 + 32);
            if ( v11 != nullptr )
              v11 = *((HWND *)v11 + 8);
            strMenuItem.m_pszData = (char *)GetClassLongA(hWnd: v11, nIndex: -34);
          }
          v12 = CMap<unsigned int,unsigned int,unsigned long,unsigned long>::operator[](
                  this: (CMap<unsigned int,unsigned int,unsigned long,unsigned long> *)&CMFCTabCtrl::m_mapDocIcons,
                  key: v7);
          *v12 = (unsigned int)strMenuItem.m_pszData;
        }
        ATL::CStringData::Release(this: (ATL::CStringData *)(i - 16));
        LOBYTE(v23) = 0;
        ATL::CStringData::Release(this: (ATL::CStringData *)hIcon - 1);
        v4 = nMenuResult;
        v2 = v17;
      }
      ++v4;
    }
    m_hWnd = v2->m_hWnd;
    v17 = (CMFCTabCtrl *)afxContextMenuManager->TrackPopupMenu(
                           this: afxContextMenuManager,
                           a2: v16.m_hMenu,
                           a3: point.x,
                           a4: point.y,
                           a5: v2,
                           a6: 0);
    if ( IsWindow(hWnd: m_hWnd) )
    {
      if ( -100 - (int)v17 >= 0 && -100 - (int)v17 < v2->m_iTabsNum )
      {
        v14 = v2->__vftable;
        v15 = (char *)(-100 - (_DWORD)v17);
        v2->m_bUserSelectedTab = 1;
        v14->SetActiveTab(this: v2, a2: (int)v15);
        v2->m_bUserSelectedTab = 0;
      }
      CMap<unsigned int,unsigned int,CPane *,CPane *>::RemoveAll(this: (CMap<unsigned int,unsigned int,unsigned long,unsigned long> *)&CMFCTabCtrl::m_mapDocIcons);
    }
    v23 = -1;
    v16.__vftable = (CMenu_vtbl *)&CMenu::`vftable';
    CMenu::DestroyMenu(this: &v16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1043050E
// Name: protected: class CMFCTasksPaneTask __near * CMFCTasksPane::TaskHitTest(class CPoint)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCTasksPaneTask *__thiscall CMFCTasksPane::TaskHitTest(CMFCTasksPane *this, CPoint pt)
{
  CMFCTasksPaneTask *result; // eax
  int m_iActivePage; // eax
  __POSITION *Index; // eax
  CObList::CNode *m_pNodeHead; // ebx
  CObject *data; // eax
  CObject_vtbl *v8; // edi
  void (__thiscall *Serialize)(CObject *, CArchive *); // esi
  CMFCTasksPanePropertyPage *pActivePage; // [esp+4h] [ebp-4h]

  result = (CMFCTasksPaneTask *)PtInRect(lprc: &this->m_rectTasks, pt: pt.tagPOINT);
  if ( result != nullptr )
  {
    m_iActivePage = this->m_iActivePage;
    if ( m_iActivePage < 0
      || m_iActivePage >= this->m_arrHistoryStack.m_nSize
      || (Index = CStringList::FindIndex(
                    this: (CList<unsigned long,unsigned long> *)&this->m_lstTasksPanes,
                    nIndex: this->m_arrHistoryStack.m_pData[m_iActivePage])) == nullptr )
    {
      AfxThrowInvalidArgException();
    }
    m_pNodeHead = this->m_lstTaskGroups.m_pNodeHead;
    pActivePage = *(CMFCTasksPanePropertyPage **)&Index[8];
    while ( m_pNodeHead != nullptr )
    {
      data = m_pNodeHead->data;
      m_pNodeHead = m_pNodeHead->pNext;
      if ( (CMFCTasksPanePropertyPage *)data[1].__vftable == pActivePage )
      {
        v8 = data[4].__vftable;
        while ( v8 != nullptr )
        {
          Serialize = v8->Serialize;
          v8 = (CObject_vtbl *)v8->GetRuntimeClass;
          if ( *((_DWORD *)Serialize + 13) != 0
            && PtInRect(lprc: (const RECT *)((char *)Serialize + 12), pt: pt.tagPOINT)
            && *((_DWORD *)Serialize + 9) != 0 )
          {
            return (CMFCTasksPaneTask *)Serialize;
          }
        }
      }
    }
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104305CB
// Name: protected: virtual class CMFCTasksPaneTaskGroup __near * CMFCTasksPane::GroupCaptionHitTest(class CPoint)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCTasksPaneTaskGroup *__thiscall CMFCTasksPane::GroupCaptionHitTest(CMFCTasksPane *this, CPoint pt)
{
  int m_iActivePage; // eax
  __POSITION *Index; // eax
  CObList::CNode *m_pNodeHead; // esi
  CObject_vtbl *v7; // ebx
  CObject *data; // edi

  if ( this->m_bCanCollapse == 0 || !PtInRect(lprc: &this->m_rectTasks, pt: pt.tagPOINT) )
    return nullptr;
  m_iActivePage = this->m_iActivePage;
  if ( m_iActivePage < 0
    || m_iActivePage >= this->m_arrHistoryStack.m_nSize
    || (Index = CStringList::FindIndex(
                  this: (CList<unsigned long,unsigned long> *)&this->m_lstTasksPanes,
                  nIndex: this->m_arrHistoryStack.m_pData[m_iActivePage])) == nullptr )
  {
    AfxThrowInvalidArgException();
  }
  m_pNodeHead = this->m_lstTaskGroups.m_pNodeHead;
  v7 = *(CObject_vtbl **)&Index[8];
  do
  {
    if ( m_pNodeHead == nullptr )
      return nullptr;
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
  }
  while ( data[1].__vftable != v7 || !PtInRect(lprc: (const RECT *)&data[13], pt: pt.tagPOINT) );
  return (CMFCTasksPaneTaskGroup *)data;
}
