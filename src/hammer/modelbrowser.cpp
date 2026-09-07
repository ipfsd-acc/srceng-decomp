// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/modelbrowser.cpp
// Functions: 133
// ============================================================

#include "hammer\modelbrowser.h"

//------------------------------------------------------------------------------
// Address: 0x10087770
// Name: public: virtual void CModelBrowserPanel::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelBrowserPanel::OnKeyCodeTyped(CModelBrowserPanel *this, ButtonCode_t code)
{
  vgui::EditablePanel::OnKeyCodeTyped(this, code);
  if ( code == KEY_ENTER )
  {
    CDialog::EndDialog(this: this->m_pBrowser, nResult: 1);
  }
  else if ( code == KEY_ESCAPE )
  {
    CDialog::EndDialog(this: this->m_pBrowser, nResult: 2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100877B0
// Name: public: virtual struct CRuntimeClass __near * CModelBrowser::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CModelBrowser::GetRuntimeClass(CModelBrowser *this)
{
  return &CModelBrowser::classCModelBrowser;
}

//------------------------------------------------------------------------------
// Address: 0x100877C0
// Name: public: CVGuiPanelWnd::CVGuiPanelWnd(void)
// Source: json
//------------------------------------------------------------------------------
CVGuiPanelWnd *__thiscall CVGuiPanelWnd::CVGuiPanelWnd(CVGuiPanelWnd *this)
{
  CWnd::CWnd(this);
  CVGuiWnd::CVGuiWnd(this: &this->CVGuiWnd);
  this->CWnd::CCmdTarget::CObject::__vftable = (CVGuiPanelWnd_vtbl *)&CVGuiPanelWnd::`vftable'{for `CWnd'};
  this->CVGuiWnd::__vftable = (CVGuiWnd_vtbl *)&CVGuiPanelWnd::`vftable'{for `CVGuiWnd'};
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10087820
// Name: public: virtual CVGuiPanelWnd::~CVGuiPanelWnd(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVGuiPanelWnd::~CVGuiPanelWnd(CVGuiPanelWnd *this)
{
  CVGuiWnd::~CVGuiWnd(this: &this->CVGuiWnd);
  CWnd::~CWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x100878D0
// Name: public: void CModelBrowser::SetUsedModelList(class CUtlVector<struct AssetUsageInfo_t,class CUtlMemory<struct AssetUsageInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelBrowser::SetUsedModelList(
        CModelBrowser *this,
        CUtlVector<AssetUsageInfo_t,CUtlMemory<AssetUsageInfo_t,int> > *usedModels)
{
  CBaseAssetPicker::SetUsedAssetList(this: this->m_pPicker, usedAssets: usedModels);
}

//------------------------------------------------------------------------------
// Address: 0x100878E0
// Name: public: void CModelBrowser::SetModelName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelBrowser::SetModelName(CModelBrowser *this, const char *pModelName)
{
  const char *v3; // eax
  const char *v4; // esi
  char pszTempModelName[256]; // [esp+Ch] [ebp-100h] BYREF

  strcpy(pszTempModelName, pModelName);
  strchr(string: pszTempModelName, chr: 0x2Fu);
  v4 = v3;
  if ( v3 != nullptr )
  {
    v4 = v3 + 1;
    V_FixSlashes(pname: (char *)v3 + 1, separator: 92);
  }
  CMDLPicker::SelectMDL(this: this->m_pPicker, pRelativePath: pModelName);
  CBaseAssetPicker::SetInitialSelection(this: this->m_pPicker, pAssetName: v4);
  this->m_pStatusLine->SetText(this: this->m_pStatusLine, a2: pModelName);
}

//------------------------------------------------------------------------------
// Address: 0x10087960
// Name: public: void CModelBrowser::GetModelName(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelBrowser::GetModelName(CModelBrowser *this, char *pModelName, int length)
{
  CMDLPicker::GetSelectedMDLName(this: this->m_pPicker, pBuffer: pModelName, nMaxLen: length);
  V_FixSlashes(pname: pModelName, separator: 47);
}

//------------------------------------------------------------------------------
// Address: 0x10087990
// Name: public: void CModelBrowser::GetSkin(int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelBrowser::GetSkin(CModelBrowser *this, int *nSkin)
{
  *nSkin = CMDLPicker::GetSelectedSkin(this: this->m_pPicker);
}

//------------------------------------------------------------------------------
// Address: 0x100879B0
// Name: public: void CModelBrowser::SetSkin(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelBrowser::SetSkin(CModelBrowser *this, int nSkin)
{
  CMDLPicker::SelectSkin(this: this->m_pPicker, nSkin);
}

//------------------------------------------------------------------------------
// Address: 0x100879C0
// Name: protected: virtual int CModelBrowser::PreTranslateMessage(struct tagMSG __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelBrowser::PreTranslateMessage(CModelBrowser *this, tagMSG *pMsg)
{
  return CWnd::PreTranslateMessage(this, pMsg);
}

//------------------------------------------------------------------------------
// Address: 0x100879D0
// Name: public: void CModelBrowser::Show(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelBrowser::Show(CModelBrowser *this)
{
  if ( this->m_pPicker != nullptr )
    this->m_pPicker->SetVisible(this: this->m_pPicker, a2: true);
  if ( this->m_pStatusLine != nullptr )
    this->m_pStatusLine->SetVisible(this: this->m_pStatusLine, a2: true);
  if ( this->m_pButtonOK != nullptr )
    this->m_pButtonOK->SetVisible(this: this->m_pButtonOK, a2: true);
  if ( this->m_pButtonCancel != nullptr )
    this->m_pButtonCancel->SetVisible(this: this->m_pButtonCancel, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x10087A50
// Name: public: void CModelBrowser::Hide(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelBrowser::Hide(CModelBrowser *this)
{
  if ( this->m_pPicker != nullptr )
    this->m_pPicker->SetVisible(this: this->m_pPicker, a2: false);
  if ( this->m_pStatusLine != nullptr )
    this->m_pStatusLine->SetVisible(this: this->m_pStatusLine, a2: false);
  if ( this->m_pButtonOK != nullptr )
    this->m_pButtonOK->SetVisible(this: this->m_pButtonOK, a2: false);
  if ( this->m_pButtonCancel != nullptr )
    this->m_pButtonCancel->SetVisible(this: this->m_pButtonCancel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x10087AD0
// Name: public: virtual void CModelBrowserPanel::OnMessage(class KeyValues const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelBrowserPanel::OnMessage(CModelBrowserPanel *this, KeyValues *params, unsigned int ifromPanel)
{
  const char *Name; // eax
  CModelBrowser *m_pBrowser; // esi
  const char *v6; // eax
  char pBuffer[1024]; // [esp+8h] [ebp-400h] BYREF

  vgui::Panel::OnMessage(this, params, ifromPanel);
  Name = KeyValues::GetName(this: params);
  if ( _V_strcmp(s1: Name, s2: "MDLPreviewChanged") != 0 )
  {
    v6 = KeyValues::GetName(this: params);
    if ( _V_stricmp(s1: v6, s2: "AssetPickerFind") == 0 )
      CDialog::EndDialog(this: this->m_pBrowser, nResult: 100);
  }
  else
  {
    m_pBrowser = this->m_pBrowser;
    CMDLPicker::GetSelectedMDLName(this: m_pBrowser->m_pPicker, pBuffer, nMaxLen: 1024);
    m_pBrowser->m_pStatusLine->SetText(this: m_pBrowser->m_pStatusLine, a2: pBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087B70
// Name: public: CModelBrowser::CModelBrowser(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CModelBrowser *__thiscall CModelBrowser::CModelBrowser(CModelBrowser *this, CWnd *pParent)
{
  CMDLPicker *v3; // eax
  CMDLPicker *v4; // eax
  vgui::TextEntry *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::Button *v7; // eax
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax

  CDialog::CDialog(this, nIDTemplate: 0x14Cu, pParentWnd: pParent);
  this->__vftable = (CModelBrowser_vtbl *)&CModelBrowser::`vftable';
  CWnd::CWnd(this: &this->m_VGuiWindow);
  CVGuiWnd::CVGuiWnd(this: &this->m_VGuiWindow.CVGuiWnd);
  this->m_VGuiWindow.__vftable = (CVGuiPanelWnd_vtbl *)&CVGuiPanelWnd::`vftable'{for `CWnd'};
  this->m_VGuiWindow.__vftable = (CVGuiWnd_vtbl *)&CVGuiPanelWnd::`vftable'{for `CVGuiWnd'};
  v3 = (CMDLPicker *)operator new(nSize: 0x284u);
  if ( v3 != nullptr )
    v4 = CMDLPicker::CMDLPicker(this: v3, pParent: nullptr, nFlags: -1);
  else
    v4 = nullptr;
  this->m_pPicker = v4;
  v5 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v5 != nullptr )
    v6 = vgui::TextEntry::TextEntry(this: v5, parent: nullptr, panelName: "StatusLine");
  else
    v6 = nullptr;
  this->m_pStatusLine = v6;
  v7 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v7 != nullptr )
    v8 = vgui::Button::Button(
           this: v7,
           parent: nullptr,
           panelName: "OpenButton",
           text: "OK",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v8 = nullptr;
  this->m_pButtonOK = v8;
  v9 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: nullptr,
            panelName: "CancelButton",
            text: "Cancel",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v10 = nullptr;
  this->m_pButtonCancel = v10;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10087D60
// Name: public: void CModelBrowser::SaveLoadSettings(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelBrowser::SaveLoadSettings(CModelBrowser *this, int bSave)
{
  CAfxStringMgr *StringManager; // eax
  CWinApp *m_pCurrentWinApp; // esi
  char *m_pszData; // edi
  CWinApp_vtbl *v6; // ebx
  const char *Filter; // eax
  ATL::CStringData *v8; // eax
  int v9; // eax
  ATL::CStringData *v10; // eax
  int v11; // eax
  CRect rect; // [esp+Ch] [ebp-28h] BYREF
  int v13; // [esp+1Ch] [ebp-18h] BYREF
  CModelBrowser *v14; // [esp+20h] [ebp-14h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+24h] [ebp-10h] BYREF
  int v16; // [esp+30h] [ebp-4h]

  v14 = this;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  str.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v16 = 1;
  memset(&rect, 0, sizeof(rect));
  m_pCurrentWinApp = AfxGetModuleState()->m_pCurrentWinApp;
  if ( (_BYTE)bSave != 0 )
  {
    GetWindowRect(hWnd: this->m_hWnd, lpRect: &rect);
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: &str,
      pszFormat: "%d %d %d %d",
      rect.left,
      rect.top,
      rect.right,
      rect.bottom);
    m_pszData = str.m_pszData;
    m_pCurrentWinApp->WriteProfileStringA(this: m_pCurrentWinApp, a2: pszIniSection, a3: "Position", a4: str.m_pszData);
    v6 = m_pCurrentWinApp->__vftable;
    Filter = CBaseAssetPicker::GetFilter(this: v14->m_pPicker);
    v6->WriteProfileStringA(this: m_pCurrentWinApp, a2: pszIniSection, a3: "Filter", a4: Filter);
  }
  else
  {
    v8 = (ATL::CStringData *)m_pCurrentWinApp->GetProfileStringA(
                               this: m_pCurrentWinApp,
                               result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&bSave,
                               a3: pszIniSection,
                               a4: "Position",
                               a5: nullptr);
    LOBYTE(v16) = 2;
    ATL::CSimpleStringT<char,0>::operator=(this: &str, strSrc: v8);
    LOBYTE(v16) = 1;
    v9 = bSave - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)(bSave - 16 + 12)) <= 0 )
      (*(void (__stdcall **)(int))(**(_DWORD **)v9 + 4))(a1: v9);
    if ( *((_DWORD *)str.m_pszData - 3) != 0 )
    {
      sscanf(string: str.m_pszData, format: "%d %d %d %d", &rect, &rect.top, &rect.right, &rect.bottom);
      if ( rect.left >= 0 )
        CWnd::MoveWindow(
          this,
          x: rect.left,
          y: rect.top,
          nWidth: rect.right - rect.left,
          nHeight: rect.bottom - rect.top,
          bRepaint: false);
      else
        CWnd::ShowWindow(this, nCmdShow: 3);
      CModelBrowser::Resize(this);
    }
    v10 = (ATL::CStringData *)m_pCurrentWinApp->GetProfileStringA(
                                this: m_pCurrentWinApp,
                                result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v13,
                                a3: pszIniSection,
                                a4: "Filter",
                                a5: nullptr);
    LOBYTE(v16) = 4;
    ATL::CSimpleStringT<char,0>::operator=(this: &str, strSrc: v10);
    LOBYTE(v16) = 1;
    v11 = v13 - 16;
    if ( _InterlockedDecrement((volatile signed __int32 *)(v13 - 16 + 12)) <= 0 )
      (*(void (__stdcall **)(int))(**(_DWORD **)v11 + 4))(a1: v11);
    m_pszData = str.m_pszData;
    if ( *((_DWORD *)str.m_pszData - 3) != 0 )
      CBaseAssetPicker::SetFilter(this: v14->m_pPicker, pFilter: str.m_pszData);
  }
  v16 = -1;
  if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
    (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
      a1: *((_DWORD *)m_pszData - 4),
      a2: m_pszData - 16);
}

//------------------------------------------------------------------------------
// Address: 0x10087F90
// Name: public: virtual int CModelBrowser::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CModelBrowser::OnInitDialog(CModelBrowser *this)
{
  int (__thiscall *Create)(struct CVGuiPanelWnd *, const char *, const char *, unsigned int, const tagRECT *, CWnd *, unsigned int, CCreateContext *); // eax
  vgui::EditablePanel *v3; // edi
  CHammerVGui *v4; // eax
  void *v6[5]; // [esp+Ch] [ebp-20h] BYREF
  int v7; // [esp+28h] [ebp-4h]

  CDialog::OnInitDialog(this);
  v6[2] = (void *)100;
  v6[3] = (void *)100;
  Create = this->m_VGuiWindow.Create;
  v6[0] = nullptr;
  v6[1] = nullptr;
  Create(
    this: &this->m_VGuiWindow,
    a2: nullptr,
    a3: "ModelViewer",
    a4: 1342177280u,
    a5: (const tagRECT *)v6,
    a6: this,
    a7: 1001u,
    a8: nullptr);
  v3 = (vgui::EditablePanel *)operator new(nSize: 0x180u);
  v6[4] = v3;
  v7 = 0;
  if ( v3 != nullptr )
  {
    v4 = HammerVGui();
    vgui::EditablePanel::EditablePanel(
      this: v3,
      parent: nullptr,
      panelName: "ModelBrowerPanel",
      hScheme: v4->m_hHammerScheme);
    v3->__vftable = (vgui::EditablePanel_vtbl *)&CModelBrowserPanel::`vftable';
    v3[1].__vftable = (vgui::EditablePanel_vtbl *)this;
    LOBYTE(v7) = 0;
  }
  else
  {
    v3 = nullptr;
  }
  v7 = -1;
  CVGuiWnd::SetParentWindow(this: &this->m_VGuiWindow.CVGuiWnd, pParent: &this->m_VGuiWindow);
  CVGuiWnd::SetMainPanel(this: &this->m_VGuiWindow.CVGuiWnd, pPanel: v3);
  vgui::Panel::MakePopup(this: v3, showTaskbarIcon: false, disabled: false);
  CVGuiWnd::SetRepaintInterval(this: &this->m_VGuiWindow.CVGuiWnd, msecs: 75);
  this->m_pPicker->SetParent_2(this: this->m_pPicker, a2: v3);
  this->m_pPicker->AddActionSignalTarget_2(this: this->m_pPicker, a2: v3);
  this->m_pButtonOK->SetParent_2(this: this->m_pButtonOK, a2: v3);
  this->m_pButtonOK->AddActionSignalTarget_2(this: this->m_pButtonOK, a2: v3);
  this->m_pButtonOK->SetCommand(this: this->m_pButtonOK, a2: "OK");
  this->m_pButtonCancel->SetParent_2(this: this->m_pButtonCancel, a2: v3);
  this->m_pButtonCancel->AddActionSignalTarget_2(this: this->m_pButtonCancel, a2: v3);
  this->m_pButtonCancel->SetCommand(this: this->m_pButtonCancel, a2: "Cancel");
  this->m_pStatusLine->SetParent_2(this: this->m_pStatusLine, a2: v3);
  this->m_pStatusLine->SetEditable(this: this->m_pStatusLine, a2: false);
  CModelBrowser::SaveLoadSettings(this, bSave: 0);
  this->m_pPicker->Activate(this: this->m_pPicker);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10088160
// Name: public: void CModelBrowser::OnDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelBrowser::OnDestroy(CModelBrowser *this)
{
  CModelBrowser::SaveLoadSettings(this, bSave: 1);
  CTextureSystem::RebindDefaultCubeMap(this: &g_Textures);
  CWnd::OnDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x10088180
// Name: protected: static struct AFX_MSGMAP const __near * CModelBrowser::GetThisMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__stdcall CModelBrowser::GetThisMessageMap()
{
  if ( (_S1_6 & 1) == 0 )
  {
    _S1_6 |= 1u;
    messageEntries_44[0].pfn = (void (__thiscall *)(CCmdTarget *))CModelBrowser::OnSize;
    messageEntries_44[1].nMessage = 2;
    messageEntries_44[1].nCode = 0;
    messageEntries_44[1].nID = 0;
    messageEntries_44[1].nLastID = 0;
    messageEntries_44[1].nSig = 19;
    messageEntries_44[1].pfn = (void (__thiscall *)(CCmdTarget *))CModelBrowser::OnDestroy;
    messageEntries_44[2].nMessage = 20;
    messageEntries_44[2].nCode = 0;
    messageEntries_44[2].nID = 0;
    messageEntries_44[2].nLastID = 0;
    messageEntries_44[2].nSig = 1;
    messageEntries_44[2].pfn = (void (__thiscall *)(CCmdTarget *))CParticleBrowser::OnEraseBkgnd;
    messageEntries_44[3].nMessage = 0;
    messageEntries_44[3].nCode = 0;
    messageEntries_44[3].nID = 0;
    messageEntries_44[3].nLastID = 0;
    messageEntries_44[3].nSig = 0;
    messageEntries_44[3].pfn = nullptr;
  }
  return &messageMap_3;
}

//------------------------------------------------------------------------------
// Address: 0x10088250
// Name: protected: virtual struct AFX_MSGMAP const __near * CModelBrowser::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
const AFX_MSGMAP *__thiscall CModelBrowser::GetMessageMap(CModelBrowser *this)
{
  return CModelBrowser::GetThisMessageMap();
}

//------------------------------------------------------------------------------
// Address: 0x1008CE60
// Name: public: virtual void CModelBrowserPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelBrowserPanel::OnCommand(CModelBrowserPanel *this, const char *pCommand)
{
  if ( _V_strcmp(s1: pCommand, s2: "OK") != 0 )
  {
    if ( _V_strcmp(s1: pCommand, s2: "Cancel") == 0 )
      CDialog::EndDialog(this: this->m_pBrowser, nResult: 2);
  }
  else
  {
    CDialog::EndDialog(this: this->m_pBrowser, nResult: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D2B0
// Name: public: void CModelBrowser::Resize(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelBrowser::Resize(CModelBrowser *this)
{
  int v2; // eax
  HWND__ *m_hWnd; // [esp-8h] [ebp-20h]
  CRect rect; // [esp+8h] [ebp-10h] BYREF

  m_hWnd = this->m_hWnd;
  memset(&rect, 0, sizeof(rect));
  GetClientRect(hWnd: m_hWnd, lpRect: &rect);
  CWnd::MoveWindow(
    this: &this->m_VGuiWindow,
    x: rect.left,
    y: rect.top,
    nWidth: rect.right - rect.left,
    nHeight: rect.bottom - rect.top,
    bRepaint: true);
  vgui::Panel::SetBounds(
    this: this->m_pPicker,
    x: 0,
    y: 0,
    wide: rect.right - rect.left,
    tall: rect.bottom - rect.top - 32);
  vgui::Panel::SetPos(this: this->m_pButtonCancel, x: 8, y: rect.bottom - rect.top - 30);
  vgui::Panel::SetPos(this: this->m_pButtonOK, x: 84, y: rect.bottom - rect.top - 30);
  v2 = rect.right - rect.left - 166;
  if ( v2 < 100 )
    v2 = 100;
  vgui::Panel::SetBounds(this: this->m_pStatusLine, x: 160, y: rect.bottom - rect.top - 30, wide: v2, tall: 24);
}

//------------------------------------------------------------------------------
// Address: 0x1008D380
// Name: public: void CModelBrowser::OnSize(unsigned int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CModelBrowser::OnSize(CModelBrowser *this, unsigned int nType, int cx, int cy)
{
  if ( nType != 1 && IsWindow(hWnd: this->m_VGuiWindow.m_hWnd) )
    CModelBrowser::Resize(this);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x103A9E31
// Name: public: void CMFCToolBarButton::Show(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCToolBarButton::Show(CMFCToolBarButton *this, int bShow)
{
  int v2; // eax

  v2 = bShow == 0;
  if ( this->m_bIsHidden != v2 )
  {
    this->m_bIsHidden = v2;
    this->OnShow(this, a2: bShow);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104070C4
// Name: public: void CSmartDockingManager::Show(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSmartDockingManager::Show(CSmartDockingManager *this, int bShow)
{
  int v3; // ebx
  CSmartDockingStandaloneGuide **m_arMarkers; // edi
  unsigned int m_dwEnabledAlignment; // eax

  v3 = 0;
  if ( this->m_bStarted != 0 && this->m_bShown != bShow )
  {
    this->m_bShown = bShow;
    if ( this->m_bCentralGroupShown != 0 )
      this->m_pCentralGroup->Show(this: this->m_pCentralGroup, a2: bShow);
    m_arMarkers = this->m_arMarkers;
    do
    {
      m_dwEnabledAlignment = this->m_dwEnabledAlignment;
      if ( (m_dwEnabledAlignment & 0x1000) != 0 && v3 == 0
        || (m_dwEnabledAlignment & 0x4000) != 0 && v3 == 1
        || (m_dwEnabledAlignment & 0x2000) != 0 && v3 == 2
        || (m_dwEnabledAlignment & 0x8000) != 0 && v3 == 3 )
      {
        (*m_arMarkers)->Show(this: *m_arMarkers, a2: bShow);
      }
      ++v3;
      ++m_arMarkers;
    }
    while ( v3 <= 3 );
    if ( bShow == 0 && this->m_wndPlaceMarker.m_bTabbed == 0 )
      CSmartDockingHighlighterWnd::Hide(this: &this->m_wndPlaceMarker);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040C3E6
// Name: public: void CMFCPropertyGridToolTipCtrl::Hide(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCPropertyGridToolTipCtrl::Hide(CMFCPropertyGridToolTipCtrl *this)
{
  if ( this != nullptr && this->m_hWnd != nullptr )
    CWnd::ShowWindow(this, nCmdShow: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1041EB78
// Name: public: void CMFCRibbonKeyTip::Hide(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMFCRibbonKeyTip::Hide(CMFCRibbonKeyTip *this)
{
  if ( this != nullptr && this->m_hWnd != nullptr && IsWindowVisible(hWnd: this->m_hWnd) )
  {
    CWnd::ShowWindow(this, nCmdShow: 0);
    CMFCRibbonKeyTip::UpdateMenuShadow(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041EBAC
// Name: public: int CMFCRibbonKeyTip::Show(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMFCRibbonKeyTip::Show(CMFCRibbonKeyTip *this, int bRepos)
{
  CWnd *v3; // eax
  CWnd *v4; // esi
  HMONITOR v6; // eax
  int v7; // eax
  HCURSOR CursorA; // eax
  const char *v9; // eax
  CMFCRibbonBaseElement *m_pElement; // ecx
  CMFCRibbonBaseElement_vtbl *v11; // eax
  CMFCVisualManager *Instance; // eax
  CRect *p_m_rectScreen; // edi
  bool v14; // zf
  CClientDC v15; // [esp+10h] [ebp-74h] BYREF
  CWnd *v16; // [esp+24h] [ebp-60h]
  CFont *pFont; // [esp+28h] [ebp-5Ch]
  tagMONITORINFO mi; // [esp+2Ch] [ebp-58h] BYREF
  tagRECT rcDst; // [esp+54h] [ebp-30h] BYREF
  RECT rc; // [esp+64h] [ebp-20h] BYREF
  int v21; // [esp+80h] [ebp-4h]

  v16 = this;
  if ( this == nullptr || this->m_hWnd == nullptr || bRepos != 0 )
  {
    v3 = this->m_pElement->GetParentWnd(this: this->m_pElement);
    v4 = v3;
    if ( v3 == nullptr || v3->m_hWnd == nullptr )
      return 0;
    CClientDC::CClientDC(this: &v15, pWnd: nullptr);
    v21 = 0;
    pFont = CDC::SelectObject(this: &v15, pFont: &afxGlobalData.fontRegular);
    if ( pFont == nullptr )
      AfxThrowInvalidArgException();
    this->m_pElement->GetKeyTipRect(this: this->m_pElement, result: (CRect *)&rc, a3: &v15, a4: this->m_bIsMenu);
    CDC::SelectObject(this: &v15, pFont);
    if ( IsRectEmpty(lprc: &rc) )
    {
LABEL_11:
      v21 = -1;
      CClientDC::~CClientDC(this: &v15);
      return 0;
    }
    CWnd::ClientToScreen(this: v4, lpRect: &rc);
    memset(&rcDst, 0, sizeof(rcDst));
    mi.cbSize = 40;
    v6 = MonitorFromPoint(pt: *(POINT *)&rc.left, dwFlags: 2u);
    if ( GetMonitorInfoA(hMonitor: v6, lpmi: &mi) )
      CopyRect(lprcDst: &rcDst, lprcSrc: &mi.rcWork);
    else
      SystemParametersInfoA(uiAction: 0x30u, uiParam: 0, pvParam: &rcDst, fWinIni: 0);
    if ( rc.right <= rcDst.right )
    {
      if ( rc.left >= rcDst.left )
        goto LABEL_20;
      v7 = rcDst.left - rc.left;
    }
    else
    {
      v7 = rcDst.right - rc.right;
    }
    OffsetRect(lprc: &rc, dx: v7, dy: 0);
LABEL_20:
    if ( rc.bottom <= rcDst.bottom )
    {
      if ( rc.top < rcDst.top )
        OffsetRect(lprc: &rc, dx: rcDst.top - rc.top, dy: 0);
    }
    else
    {
      OffsetRect(lprc: &rc, dx: 0, dy: rcDst.bottom - rc.bottom);
    }
    if ( *((_DWORD *)CMFCRibbonKeyTip::m_strClassName.m_pszData - 3) == 0 )
    {
      CursorA = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
      v9 = AfxRegisterWndClass(nClassStyle: 0x800u, hCursor: CursorA, hbrBackground: (HBRUSH__ *)0x10, hIcon: nullptr);
      ATL::CSimpleStringT<char,0>::SetString(this: &CMFCRibbonKeyTip::m_strClassName, pszSrc: v9);
    }
    m_pElement = this->m_pElement;
    v11 = m_pElement->__vftable;
    pFont = (CFont *)136;
    if ( v11->IsDisabled(this: m_pElement) != 0 )
    {
      Instance = CMFCVisualManager::GetInstance();
      if ( Instance->IsLayeredRibbonKeyTip(this: Instance) != 0 )
        pFont = (CFont *)524424;
    }
    if ( this->CreateEx(
           this,
           a2: (unsigned int)pFont,
           a3: CMFCRibbonKeyTip::m_strClassName.m_pszData,
           a4: &var,
           a5: 0x80000000,
           a6: &rc,
           a7: nullptr,
           a8: 0,
           a9: nullptr) != 0 )
    {
      p_m_rectScreen = &this->m_rectScreen;
      v14 = ((unsigned int)pFont & 0x80000) == 0;
      p_m_rectScreen->left = rc.left;
      p_m_rectScreen = (CRect *)((char *)p_m_rectScreen + 4);
      p_m_rectScreen->left = rc.top;
      p_m_rectScreen = (CRect *)((char *)p_m_rectScreen + 4);
      p_m_rectScreen->left = rc.right;
      p_m_rectScreen->top = rc.bottom;
      if ( !v14 )
        SetLayeredWindowAttributes(hwnd: v16->m_hWnd, crKey: 0, bAlpha: 0x80u, dwFlags: 2u);
      CWnd::ShowWindow(this: v16, nCmdShow: 4);
      v21 = -1;
      CClientDC::~CClientDC(this: &v15);
      return 1;
    }
    goto LABEL_11;
  }
  CWnd::ShowWindow(this, nCmdShow: 4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104283BB
// Name: public: void CSmartDockingHighlighterWnd::Hide(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSmartDockingHighlighterWnd::Hide(CSmartDockingHighlighterWnd *this)
{
  CWnd *m_pWndOwner; // eax
  CWnd *m_pDockingWnd; // eax

  if ( this->m_bShown != 0 )
  {
    CWnd::ShowWindow(this, nCmdShow: 0);
    m_pWndOwner = this->m_pWndOwner;
    this->m_bShown = 0;
    if ( m_pWndOwner != nullptr )
      UpdateWindow(hWnd: m_pWndOwner->m_hWnd);
    m_pDockingWnd = this->m_pDockingWnd;
    if ( m_pDockingWnd != nullptr )
      UpdateWindow(hWnd: m_pDockingWnd->m_hWnd);
    SetRectEmpty(lprc: &this->m_rectLast);
    SetRectEmpty(lprc: &this->m_rectTab);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104288B6
// Name: public: virtual void CSmartDockingStandaloneGuide::Show(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSmartDockingStandaloneGuide::Show(CSmartDockingStandaloneGuide *this, int bShow)
{
  if ( IsWindow(hWnd: this->m_wndBmp.m_hWnd) )
    CWnd::ShowWindow(this: &this->m_wndBmp, nCmdShow: bShow != 0 ? 5 : 0);
}

//------------------------------------------------------------------------------
// Address: 0x10428937
// Name: public: virtual void CSmartDockingGroupGuidesManager::Show(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSmartDockingGroupGuidesManager::Show(CSmartDockingGroupGuidesManager *this, int bShow)
{
  if ( IsWindow(hWnd: this->m_Wnd.m_hWnd) )
    CWnd::ShowWindow(this: &this->m_Wnd, nCmdShow: bShow != 0 ? 5 : 0);
}

//------------------------------------------------------------------------------
// Address: 0x103A9E53
// Name: public: virtual void CBasePane::EnableDocking(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CBasePane::EnableDocking(CBasePane *this, unsigned int dwAlignment)
{
  this->m_dwEnabledAlignment = dwAlignment;
}

//------------------------------------------------------------------------------
// Address: 0x103A9E65
// Name: public: virtual class CSize CControlBar::CalcFixedLayout(int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CControlBar::CalcFixedLayout(CBasePane *this, CSize *result, int bStretch, int bHorz)
{
  CSize *v4; // eax
  int v5; // ecx
  int v6; // ecx

  v4 = result;
  result->cx = 0;
  result->cy = 0;
  if ( bStretch != 0 && bHorz != 0 )
    v5 = 0x7FFF;
  else
    v5 = 0;
  result->cx = v5;
  if ( bStretch == 0 || bHorz != 0 )
    v6 = 0;
  else
    v6 = 0x7FFF;
  result->cy = v6;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x103A9EA4
// Name: public: class CFont __near * CBasePane::SelectDefaultFont(class CDC __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFont *__thiscall CBasePane::SelectDefaultFont(CBasePane *this, CDC *pDC)
{
  CDC_vtbl *v2; // eax

  v2 = pDC->__vftable;
  if ( this->m_bIsDlgControl != 0 )
    return ((CFont *(__stdcall *)(int))v2->SelectStockObject)(a1: 17);
  else
    return ((CFont *(__stdcall *)(CFont *))v2->SelectObject)(a1: &afxGlobalData.fontRegular);
}

//------------------------------------------------------------------------------
// Address: 0x103A9ECA
// Name: protected: virtual void CFileDialog::OnLBSelChangedNotify(unsigned int,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CFileDialog::OnLBSelChangedNotify(CMFCEditBrowseCtrl *this, unsigned int __formal, CPoint __formala)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1040715E
// Name: public: void CSmartDockingManager::OnMouseMove(class CPoint)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSmartDockingManager::OnMouseMove(CSmartDockingManager *this, CPoint point)
{
  CSmartDockingStandaloneGuide::SDMarkerPlace v3; // ebx
  CSmartDockingStandaloneGuide **v4; // edi
  int bFound; // [esp+4h] [ebp-4h]

  if ( this->m_bStarted != 0 )
  {
    this->m_nHiliteSideNo = sdNONE;
    bFound = 0;
    v3 = (this->m_pCentralGroup->m_bMiddleIsOn != 0) + 7;
    v4 = &this->m_arMarkers[v3];
    while ( bFound == 0 )
    {
      if ( *v4 != nullptr )
      {
        if ( ((int (__thiscall *)(CSmartDockingStandaloneGuide *, int, int))(*v4)->IsPtIn)(
               a1: *v4,
               a2: point.x,
               a3: point.y) == 0 )
          break;
        bFound = 1;
        (*v4)->Highlight(this: *v4, a2: 1);
        this->m_nHiliteSideNo = v3;
      }
LABEL_9:
      --v4;
      if ( --v3 < sdLEFT )
        return;
    }
    if ( *v4 != nullptr )
      (*v4)->Highlight(this: *v4, a2: 0);
    goto LABEL_9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104071E2
// Name: public: void CSmartDockingManager::SetOuterRect(class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSmartDockingManager::SetOuterRect(CSmartDockingManager *this, CRect rcOuter)
{
  CWnd *m_pwndOwner; // ecx
  CSmartDockingStandaloneGuide **m_arMarkers; // esi
  tagRECT v5; // [esp-14h] [ebp-24h] BYREF
  CRect *p_m_rcOuter; // [esp-4h] [ebp-14h]
  int i; // [esp+Ch] [ebp-4h]

  m_pwndOwner = this->m_pwndOwner;
  this->m_rcOuter.left = rcOuter.left;
  this->m_rcOuter.top = rcOuter.top;
  this->m_rcOuter.right = rcOuter.right;
  p_m_rcOuter = &this->m_rcOuter;
  this->m_rcOuter.bottom = rcOuter.bottom;
  CWnd::ClientToScreen(this: m_pwndOwner, lpRect: p_m_rcOuter);
  if ( this->m_bStarted != 0 )
  {
    m_arMarkers = this->m_arMarkers;
    for ( i = 4; i != 0; --i )
    {
      CopyRect(lprcDst: (LPRECT)&v5.top, lprcSrc: &this->m_rcOuter);
      ((void (__thiscall *)(CSmartDockingStandaloneGuide *, int, int, int, CRect *))(*m_arMarkers)->AdjustPos)(
        a1: *m_arMarkers,
        a2: v5.top,
        a3: v5.right,
        a4: v5.bottom,
        a5: p_m_rcOuter);
      (*m_arMarkers)->Show(this: *m_arMarkers, a2: 1);
      ++m_arMarkers;
    }
    p_m_rcOuter = (CRect *)-1;
    CopyRect(lprcDst: &v5, lprcSrc: &this->m_rcOuter);
    ((void (__thiscall *)(CSmartDockingGroupGuidesManager *, int, int, int, int, CRect *))this->m_pCentralGroup->AdjustPos)(
      a1: this->m_pCentralGroup,
      a2: v5.left,
      a3: v5.top,
      a4: v5.right,
      a5: v5.bottom,
      a6: p_m_rcOuter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10407261
// Name: public: void CSmartDockingManager::ShowPlaceAt(class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSmartDockingManager::ShowPlaceAt(CSmartDockingManager *this, CRect rect)
{
  if ( this->m_bStarted != 0 && this->m_bShown != 0 && this->m_nHiliteSideNo != sdNONE )
    CSmartDockingHighlighterWnd::ShowAt(this: &this->m_wndPlaceMarker, rect);
}

//------------------------------------------------------------------------------
// Address: 0x10407297
// Name: public: void CSmartDockingManager::HidePlace(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSmartDockingManager::HidePlace(CSmartDockingManager *this)
{
  if ( this->m_bStarted != 0 )
    CSmartDockingHighlighterWnd::Hide(this: &this->m_wndPlaceMarker);
}

//------------------------------------------------------------------------------
// Address: 0x104072A6
// Name: public: void CSmartDockingManager::ShowTabbedPlaceAt(class CRect,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSmartDockingManager::ShowTabbedPlaceAt(
        CSmartDockingManager *this,
        CRect rect,
        int nTabXOffset,
        int nTabWidth,
        int nTabHeight)
{
  int v6; // edx
  CRect rectTab; // [esp+Ch] [ebp-14h] BYREF

  if ( this->m_bStarted != 0 )
  {
    memset(&rectTab, 0, sizeof(rectTab));
    v6 = nTabWidth + nTabXOffset;
    if ( CTabbedPane::m_bTabsAlwaysTop != 0 )
      SetRect(lprc: &rectTab, xLeft: nTabXOffset, yTop: rect.top - nTabHeight, xRight: v6, yBottom: rect.top);
    else
      SetRect(
        lprc: &rectTab,
        xLeft: nTabXOffset,
        yTop: rect.bottom - rect.top,
        xRight: v6,
        yBottom: rect.bottom - rect.top + nTabHeight);
    CSmartDockingHighlighterWnd::ShowTabbedAt(this: &this->m_wndPlaceMarker, rect, rectTab);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10407336
// Name: public: void CSmartDockingManager::MoveCentralGroup(class CRect,int,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSmartDockingManager::MoveCentralGroup(
        CSmartDockingManager *this,
        CRect rect,
        int nMiddleIsOn,
        __int16 dwEnabledAlignment)
{
  CSmartDockingGroupGuidesManager *m_pCentralGroup; // ecx
  __int16 v6; // si
  CRect rectGroup; // [esp+Ch] [ebp-14h] BYREF

  if ( this->m_bStarted != 0 )
  {
    m_pCentralGroup = this->m_pCentralGroup;
    if ( m_pCentralGroup != nullptr )
    {
      memset(&rectGroup, 0, sizeof(rectGroup));
      CSmartDockingGroupGuidesManager::GetWindowRect(this: m_pCentralGroup, rect: &rectGroup);
      if ( !EqualRect(lprc1: &rectGroup, lprc2: &rect) )
      {
        v6 = dwEnabledAlignment;
        CSmartDockingGroupGuidesManager::ShowGuide(
          this: this->m_pCentralGroup,
          nMarkerNo: sdCLEFT,
          bShow: (dwEnabledAlignment & 0x1000) != 0,
          bRedraw: 1);
        CSmartDockingGroupGuidesManager::ShowGuide(
          this: this->m_pCentralGroup,
          nMarkerNo: sdCTOP,
          bShow: (v6 & 0x2000) != 0,
          bRedraw: 1);
        CSmartDockingGroupGuidesManager::ShowGuide(
          this: this->m_pCentralGroup,
          nMarkerNo: sdCRIGHT,
          bShow: (v6 & 0x4000) != 0,
          bRedraw: 1);
        CSmartDockingGroupGuidesManager::ShowGuide(
          this: this->m_pCentralGroup,
          nMarkerNo: sdCBOTTOM,
          bShow: v6 < 0,
          bRedraw: 1);
        if ( ((int (__thiscall *)(CSmartDockingGroupGuidesManager *, int, int, int, int, int))this->m_pCentralGroup->AdjustPos)(
               a1: this->m_pCentralGroup,
               a2: rect.left,
               a3: rect.top,
               a4: rect.right,
               a5: rect.bottom,
               a6: nMiddleIsOn) != 0 )
          this->m_nHiliteSideNo = sdNONE;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10407423
// Name: public: void CSmartDockingManager::ShowCentralGroup(int,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSmartDockingManager::ShowCentralGroup(
        CSmartDockingManager *this,
        int bShow,
        __int16 dwEnabledAlignment)
{
  CSmartDockingGroupGuidesManager *m_pCentralGroup; // ecx

  if ( this->m_bStarted != 0 )
  {
    m_pCentralGroup = this->m_pCentralGroup;
    if ( m_pCentralGroup != nullptr && this->m_bShown != 0 && this->m_bCentralGroupShown != bShow )
    {
      CSmartDockingGroupGuidesManager::ShowGuide(
        this: m_pCentralGroup,
        nMarkerNo: sdCLEFT,
        bShow: (dwEnabledAlignment & 0x1000) != 0,
        bRedraw: 1);
      CSmartDockingGroupGuidesManager::ShowGuide(
        this: this->m_pCentralGroup,
        nMarkerNo: sdCTOP,
        bShow: (dwEnabledAlignment & 0x2000) != 0,
        bRedraw: 1);
      CSmartDockingGroupGuidesManager::ShowGuide(
        this: this->m_pCentralGroup,
        nMarkerNo: sdCRIGHT,
        bShow: (dwEnabledAlignment & 0x4000) != 0,
        bRedraw: 1);
      CSmartDockingGroupGuidesManager::ShowGuide(
        this: this->m_pCentralGroup,
        nMarkerNo: sdCBOTTOM,
        bShow: dwEnabledAlignment < 0,
        bRedraw: 1);
      this->m_pCentralGroup->Show(this: this->m_pCentralGroup, a2: bShow);
    }
  }
  this->m_bCentralGroupShown = bShow;
}

//------------------------------------------------------------------------------
// Address: 0x104074C0
// Name: public: void CSmartDockingManager::Destroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSmartDockingManager::Destroy(CSmartDockingManager *this)
{
  CSmartDockingStandaloneGuide **m_arMarkers; // edi
  int i; // ebx
  CSmartDockingGroupGuidesManager *m_pCentralGroup; // ecx

  if ( this->m_bCreated != 0 )
  {
    CSmartDockingManager::Stop(this);
    m_arMarkers = this->m_arMarkers;
    for ( i = 4; i != 0; --i )
    {
      if ( *m_arMarkers != nullptr )
        ((void (__thiscall *)(CSmartDockingStandaloneGuide *, int))(*m_arMarkers)->dtr_CObject)(a1: *m_arMarkers, a2: 1);
      *m_arMarkers++ = nullptr;
    }
    this->m_pCentralGroup->Destroy(this: this->m_pCentralGroup);
    m_pCentralGroup = this->m_pCentralGroup;
    if ( m_pCentralGroup != nullptr )
      ((void (__thiscall *)(CSmartDockingGroupGuidesManager *, int))m_pCentralGroup->dtr_CObject)(
        a1: m_pCentralGroup,
        a2: 1);
    this->m_pCentralGroup = nullptr;
    this->m_bCreated = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1040751C
// Name: public: void CSmartDockingManager::CauseCancelMode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSmartDockingManager::CauseCancelMode(CSmartDockingManager *this)
{
  if ( this->m_bStarted != 0 )
    SendMessageA(hWnd: this->m_pDockingWnd->m_hWnd, Msg: 0x1Fu, wParam: 0, lParam: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10407534
// Name: public: virtual CSmartDockingManager::~CSmartDockingManager(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSmartDockingManager::~CSmartDockingManager(CSmartDockingManager *this)
{
  this->__vftable = (CSmartDockingManager_vtbl *)&CSmartDockingManager::`vftable';
  CSmartDockingManager::Destroy(this);
  CSmartDockingHighlighterWnd::~CSmartDockingHighlighterWnd(this: &this->m_wndPlaceMarker);
}

//------------------------------------------------------------------------------
// Address: 0x10407566
// Name: public: void CSmartDockingManager::Create(class CWnd __near *,struct CRuntimeClass __near *,struct CRuntimeClass __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSmartDockingManager::Create(
        CSmartDockingManager *this,
        CWnd *pwndOwner,
        CRuntimeClass *prtMarker,
        CRuntimeClass *prtCentralGroup)
{
  CRuntimeClass *v5; // edi
  int v6; // ebx
  CSmartDockingStandaloneGuide **m_arMarkers; // edi
  CObject *v8; // eax
  CSmartDockingStandaloneGuide::SDMarkerPlace v9; // ebx
  CSmartDockingStandaloneGuide **v10; // edi

  if ( prtMarker == nullptr )
    prtMarker = &CSmartDockingStandaloneGuide::classCSmartDockingStandaloneGuide;
  v5 = prtCentralGroup;
  if ( prtCentralGroup == nullptr )
    v5 = &CSmartDockingGroupGuidesManager::classCSmartDockingGroupGuidesManager;
  if ( prtMarker == nullptr
    || CRuntimeClass::IsDerivedFrom(
         this: prtMarker,
         pBaseClass: &CSmartDockingStandaloneGuide::classCSmartDockingStandaloneGuide) == nullptr
    || v5 == nullptr
    || CRuntimeClass::IsDerivedFrom(
         this: v5,
         pBaseClass: &CSmartDockingGroupGuidesManager::classCSmartDockingGroupGuidesManager) == nullptr )
  {
    AfxThrowInvalidArgException();
  }
  CSmartDockingManager::Destroy(this);
  this->m_pCentralGroup = (CSmartDockingGroupGuidesManager *)v5->m_pfnCreateObject();
  v6 = 0;
  m_arMarkers = this->m_arMarkers;
  do
  {
    v8 = prtMarker->m_pfnCreateObject();
    *m_arMarkers = (CSmartDockingStandaloneGuide *)v8;
    ((void (__thiscall *)(CObject *, int, CWnd *))v8->__vftable[1].GetRuntimeClass)(a1: v8, a2: v6++, a3: pwndOwner);
    ++m_arMarkers;
  }
  while ( v6 <= 3 );
  this->m_pCentralGroup->Create(this: this->m_pCentralGroup, a2: pwndOwner);
  v9 = sdCLEFT;
  v10 = &this->m_arMarkers[4];
  do
    *v10++ = this->m_pCentralGroup->GetGuide(this: this->m_pCentralGroup, a2: v9++);
  while ( v9 <= sdCMIDDLE );
  this->m_pwndOwner = pwndOwner;
  CSmartDockingHighlighterWnd::Create(this: &this->m_wndPlaceMarker, pwndOwner);
  this->m_bCreated = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10407652
// Name: public: struct HMENU__ __near * CContextMenuManager::GetMenuByName(char const __near *,unsigned int __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HMENU__ *__thiscall CContextMenuManager::GetMenuByName(
        CContextMenuManager *this,
        __POSITION *lpszName,
        HMENU__ *puiOrigResID)
{
  HMENU__ *result; // eax
  unsigned int *v5; // ebx
  HMENU__ *v6; // edi
  bool v7; // zf
  unsigned int uiResId; // [esp+4h] [ebp-4h] BYREF

  result = (HMENU__ *)CMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,char const *,int,int>::Lookup(
                        this: &this->m_MenuNames,
                        key: (const char *)lpszName,
                        rValue: (HMENU__ **)&lpszName);
  if ( result != nullptr )
  {
    v5 = (unsigned int *)lpszName;
    v6 = puiOrigResID;
    if ( puiOrigResID != nullptr )
    {
      *(_DWORD *)puiOrigResID = 0;
      v7 = this->m_Menus.m_nCount == 0;
      lpszName = (__POSITION *)-(this->m_Menus.m_nCount != 0);
      if ( !v7 )
      {
        while ( 1 )
        {
          CMap<unsigned int,unsigned int,HMENU__ *,HMENU__ *>::GetNextAssoc(
            this: &this->m_Menus,
            rNextPosition: &lpszName,
            rKey: &uiResId,
            rValue: &puiOrigResID);
          if ( puiOrigResID == (HMENU__ *)v5 )
            break;
          if ( lpszName == nullptr )
            return (HMENU__ *)v5;
        }
        *(_DWORD *)v6 = uiResId;
      }
    }
    return (HMENU__ *)v5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104076B8
// Name: public: void CContextMenuManager::GetMenuNames(class CStringList __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CContextMenuManager::GetMenuNames(CContextMenuManager *this, CStringList *listOfNames)
{
  bool v3; // zf
  CAfxStringMgr *StringManager; // eax
  HMENU__ *hMenu; // [esp+10h] [ebp-18h] BYREF
  __POSITION *pos; // [esp+14h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strName; // [esp+18h] [ebp-10h] BYREF
  int v8; // [esp+24h] [ebp-4h]

  CStringList::RemoveAll(this: listOfNames);
  v3 = this->m_MenuNames.m_nCount == 0;
  pos = (__POSITION *)-(this->m_MenuNames.m_nCount != 0);
  if ( !v3 )
  {
    do
    {
      StringManager = AfxGetStringManager();
      ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strName, pStringMgr: StringManager);
      v8 = 0;
      CMap<ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>,char const *,HMENU__ *,HMENU__ *>::GetNextAssoc(
        this: &this->m_MenuNames,
        rNextPosition: &pos,
        rKey: &strName,
        rValue: &hMenu);
      CStringList::AddTail(this: listOfNames, newElement: &strName);
      v8 = -1;
      ATL::CStringData::Release(this: (ATL::CStringData *)strName.m_pszData - 1);
    }
    while ( pos != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10407729
// Name: public: virtual struct CRuntimeClass __near * COleCntrFrameWndEx::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall COleCntrFrameWndEx::GetRuntimeClass(COleCntrFrameWndEx *this)
{
  return &COleCntrFrameWndEx::classCOleCntrFrameWndEx;
}

//------------------------------------------------------------------------------
// Address: 0x1040772F
// Name: public: COleCntrFrameWndEx::COleCntrFrameWndEx(class COleIPFrameWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
COleCntrFrameWndEx *__thiscall COleCntrFrameWndEx::COleCntrFrameWndEx(
        COleCntrFrameWndEx *this,
        COleIPFrameWnd *pInPlaceFrame)
{
  COleCntrFrameWnd::COleCntrFrameWnd(this, pInPlaceFrame);
  this->__vftable = (COleCntrFrameWndEx_vtbl *)&COleCntrFrameWndEx::`vftable';
  CDockingManager::CDockingManager(this: &this->m_dockManager);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10407767
// Name: protected: void COleCntrFrameWndEx::OnSize(unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleCntrFrameWndEx::OnSize(COleCntrFrameWndEx *this, unsigned int nType, int cx, int cy)
{
  CFrameWnd::OnSize(this, nType, cx, cy);
  if ( nType != 1 )
    this->AdjustDockingLayout(this, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10407794
// Name: protected: virtual int COleCntrFrameWndEx::PreCreateWindow(struct tagCREATESTRUCTA __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleCntrFrameWndEx::PreCreateWindow(COleCntrFrameWndEx *this, tagCREATESTRUCTA *cs)
{
  CDockingManager::Create(this: &this->m_dockManager, pParentWnd: this);
  return CFrameWnd::PreCreateWindow(this, cs);
}

//------------------------------------------------------------------------------
// Address: 0x104077B7
// Name: public: int COleCntrFrameWndEx::AddPane(class CBasePane __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleCntrFrameWndEx::AddPane(COleCntrFrameWndEx *this, CBasePane *pControlBar, int bTail)
{
  return CDockingManager::AddPane(
           this: &this->m_dockManager,
           pWnd: pControlBar,
           bTail,
           bAutoHide: 0,
           bInsertForOuterEdge: 0);
}

//------------------------------------------------------------------------------
// Address: 0x104077D5
// Name: public: int COleCntrFrameWndEx::InsertPane(class CBasePane __near *,class CBasePane __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleCntrFrameWndEx::InsertPane(
        COleCntrFrameWndEx *this,
        CBasePane *pControlBar,
        CBasePane *pTarget,
        int bAfter)
{
  return CDockingManager::InsertPane(this: &this->m_dockManager, pControlBar, pTarget, bAfter);
}

//------------------------------------------------------------------------------
// Address: 0x104077E6
// Name: public: void COleCntrFrameWndEx::RemovePaneFromDockManager(class CBasePane __near *,int,int,int,class CBasePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleCntrFrameWndEx::RemovePaneFromDockManager(
        COleCntrFrameWndEx *this,
        CBasePane *pControlBar,
        int bDestroy,
        int bAdjustLayout,
        int bAutoHide,
        CBasePane *pBarReplacement)
{
  CDockingManager::RemovePaneFromDockManager(
    this: &this->m_dockManager,
    pWnd: pControlBar,
    bDestroy,
    bAdjustLayout,
    bAutoHide,
    pBarReplacement);
  this->AdjustDockingLayout(this, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10407819
// Name: public: void COleCntrFrameWndEx::DockPane(class CBasePane __near *,unsigned int,struct tagRECT const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleCntrFrameWndEx::DockPane(
        COleCntrFrameWndEx *this,
        CBasePane *pBar,
        unsigned int nDockBarID,
        const tagRECT *lpRect)
{
  CDockingManager::DockPane(this: &this->m_dockManager, pBar, nDockBarID, lpRect);
  this->AdjustDockingLayout(this, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10407846
// Name: public: class CBasePane __near * COleCntrFrameWndEx::PaneFromPoint(class CPoint,int,bool,struct CRuntimeClass __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBasePane *__thiscall COleCntrFrameWndEx::PaneFromPoint(
        COleCntrFrameWndEx *this,
        CPoint point,
        int nSensitivity,
        int bExactBar,
        CRuntimeClass *pRTCBarType)
{
  return ((CBasePane *(__thiscall *)(CDockingManager *, int, int, int, int, CRuntimeClass *, _DWORD, _DWORD))this->m_dockManager.PaneFromPoint_2)(
           a1: &this->m_dockManager,
           a2: point.x,
           a3: point.y,
           a4: nSensitivity,
           a5: bExactBar,
           a6: pRTCBarType,
           a7: 0,
           a8: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1040786D
// Name: public: int COleCntrFrameWndEx::IsPointNearDockSite(class CPoint,unsigned long __near &,int __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleCntrFrameWndEx::IsPointNearDockSite(
        COleCntrFrameWndEx *this,
        CPoint point,
        unsigned int *dwBarAlignment,
        int *bOuterEdge)
{
  return CDockingManager::IsPointNearDockSite(this: &this->m_dockManager, point, dwBarAlignment, bOuterEdge);
}

//------------------------------------------------------------------------------
// Address: 0x1040788D
// Name: public: virtual int COleCntrFrameWndEx::OnMoveMiniFrame(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleCntrFrameWndEx::OnMoveMiniFrame(COleCntrFrameWndEx *this, CWnd *pFrame)
{
  return this->m_dockManager.OnMoveMiniFrame(this: &this->m_dockManager, a2: pFrame);
}

//------------------------------------------------------------------------------
// Address: 0x1040789E
// Name: public: virtual int COleCntrFrameWndEx::OnShowPanes(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall COleCntrFrameWndEx::OnShowPanes(COleCntrFrameWndEx *this, int bShow)
{
  int v3; // edi

  v3 = this->m_dockManager.ShowPanes(this: &this->m_dockManager, a2: bShow);
  this->AdjustDockingLayout(this, a2: nullptr);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x104078CB
// Name: public: void COleCntrFrameWndEx::AdjustClientArea(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleCntrFrameWndEx::AdjustClientArea(COleCntrFrameWndEx *this)
{
  CDocument *v2; // eax

  v2 = this->m_pInPlaceFrame->GetActiveDocument(this: this->m_pInPlaceFrame);
  if ( v2 != nullptr )
    ((void (__thiscall *)(CDocument *, _DWORD, IOleInPlaceFrame *, int))v2->__vftable[1].OnOpenDocument)(
      a1: v2,
      a2: 0,
      a3: this->m_pInPlaceFrame->m_lpFrame,
      a4: 1);
}

//------------------------------------------------------------------------------
// Address: 0x104078FE
// Name: public: virtual void COleCntrFrameWndEx::AdjustDockingLayout(void __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall COleCntrFrameWndEx::AdjustDockingLayout(COleCntrFrameWndEx *this, void *__formal)
{
  COleCntrFrameWndEx::AdjustClientArea(this);
}

//------------------------------------------------------------------------------
// Address: 0x10407906
// Name: public: virtual void COleCntrFrameWndEx::RecalcLayout(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleCntrFrameWndEx::RecalcLayout(COleCntrFrameWndEx *this, int bNotify)
{
  CView *ActiveView; // ecx
  CView *pView; // [esp+18h] [ebp-4h]

  COleCntrFrameWndEx::AdjustClientArea(this);
  this->m_dockManager.AdjustDockingLayout(this: &this->m_dockManager, a2: nullptr);
  this->m_dockManager.RecalcLayout(this: &this->m_dockManager, a2: bNotify);
  ActiveView = CFrameWnd::GetActiveView(this);
  pView = ActiveView;
  if ( ActiveView != nullptr
    && CObject::IsKindOf(this: ActiveView, pClass: &CPreviewViewEx::classCPreviewViewEx) != 0
    && this->m_dockManager.m_bIsPrintPreviewMode != 0 )
  {
    CWnd::SetWindowPos(
      this: pView,
      pWndInsertAfter: nullptr,
      x: this->m_dockManager.m_rectClientAreaBounds.left,
      y: this->m_dockManager.m_rectClientAreaBounds.top,
      cx: this->m_dockManager.m_rectClientAreaBounds.right - this->m_dockManager.m_rectClientAreaBounds.left,
      cy: this->m_dockManager.m_rectClientAreaBounds.bottom - this->m_dockManager.m_rectClientAreaBounds.top,
      nFlags: 0x14u);
  }
  this->m_pInPlaceFrame->RecalcLayout(this: this->m_pInPlaceFrame, a2: bNotify);
}

//------------------------------------------------------------------------------
// Address: 0x104079A9
// Name: protected: void COleCntrFrameWndEx::OnSizing(unsigned int,struct tagRECT __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleCntrFrameWndEx::OnSizing(COleCntrFrameWndEx *this, unsigned int fwSide, tagRECT *pRect)
{
  HWND__ *m_hWnd; // [esp-8h] [ebp-38h]
  tagRECT rcDst; // [esp+Ch] [ebp-24h] BYREF
  CRect rect; // [esp+1Ch] [ebp-14h] BYREF

  CWnd::Default(this);
  m_hWnd = this->m_hWnd;
  memset(&rect, 0, sizeof(rect));
  GetWindowRect(hWnd: m_hWnd, lpRect: &rect);
  CopyRect(lprcDst: &rcDst, lprcSrc: pRect);
  if ( rect.right - rect.left != rcDst.right - rcDst.left || rect.bottom - rect.top != rcDst.bottom - rcDst.top )
    this->AdjustDockingLayout(this, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10407A2A
// Name: protected: void COleCntrFrameWndEx::OnIdleUpdateCmdUI(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleCntrFrameWndEx::OnIdleUpdateCmdUI(COleCntrFrameWndEx *this)
{
  CObList::CNode *m_pNodeHead; // esi
  CObject *data; // eax

  COleCntrFrameWnd::OnIdleUpdateCmdUI(this);
  CDockingManager::SendMessageToMiniFrames(this: &this->m_dockManager, uMessage: 0x363u, wParam: 0, lParam: 0);
  m_pNodeHead = this->m_dockManager.m_lstControlBars.m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    if ( data == nullptr )
      AfxThrowInvalidArgException();
    CWnd::SendMessageToDescendants(
      hWnd: (HWND__ *)data[8].__vftable,
      message: 0x363u,
      wParam: 1u,
      lParam: 0,
      bDeep: 1,
      bOnlyPerm: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10407A7F
// Name: protected: virtual COleCntrFrameWndEx::~COleCntrFrameWndEx(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall COleCntrFrameWndEx::~COleCntrFrameWndEx(COleCntrFrameWndEx *this)
{
  CObList::CNode *m_pNodeHead; // esi
  CObject *v3; // eax
  HWND i; // eax
  CWnd *v5; // eax
  CWnd *v6; // esi
  CList<HWND__ *,HWND__ *>::CNode *v7; // esi
  HWND v8; // edi
  CObList *AllToolbars; // eax
  CObList::CNode *v10; // esi
  CObject *v11; // eax
  CObject *data; // [esp-4h] [ebp-48h]
  HWND__ *m_hWnd; // [esp-4h] [ebp-48h]
  CList<HWND__ *,HWND__ *> lstChildren; // [esp+10h] [ebp-34h] BYREF
  COleCntrFrameWndEx *v15; // [esp+2Ch] [ebp-18h]
  CObList *afxAllToolBars; // [esp+30h] [ebp-14h]
  __POSITION *posSave; // [esp+34h] [ebp-10h]
  int v18; // [esp+40h] [ebp-4h]

  v15 = this;
  this->__vftable = (COleCntrFrameWndEx_vtbl *)&COleCntrFrameWndEx::`vftable';
  m_pNodeHead = this->m_dockManager.m_lstMiniFrames.m_pNodeHead;
  v18 = 1;
  while ( m_pNodeHead != nullptr )
  {
    data = m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    v3 = AfxDynamicDownCast(pClass: &CPaneFrameWnd::classCPaneFrameWnd, pObject: data);
    if ( v3 != nullptr )
      v3->__vftable[8].GetRuntimeClass(this: v3);
  }
  lstChildren.__vftable = (CList<HWND__ *,HWND__ *>_vtbl *)&CList<HWND__ *,HWND__ *>::`vftable';
  memset(&lstChildren.m_pNodeHead, 0, 20);
  lstChildren.m_nBlockSize = 10;
  m_hWnd = this->m_hWnd;
  LOBYTE(v18) = 2;
  for ( i = GetTopWindow(hWnd: m_hWnd); ; i = GetWindow(hWnd: v6->m_hWnd, uCmd: 2u) )
  {
    v5 = CWnd::FromHandle(hWnd: i);
    v6 = v5;
    if ( v5 == nullptr )
      break;
    CList<CFrameWnd *,CFrameWnd *>::AddTail(
      this: (CList<CFrameWnd *,CFrameWnd *> *)&lstChildren,
      newElement: (CFrameWnd *)v5->m_hWnd);
  }
  v7 = lstChildren.m_pNodeHead;
  while ( v7 != nullptr )
  {
    v8 = v7->data;
    v7 = v7->pNext;
    if ( IsWindow(hWnd: v8) && GetParent(hWnd: v8) == this->m_hWnd )
      DestroyWindow(hWnd: v8);
  }
  AllToolbars = (CObList *)CMFCToolBar::GetAllToolbars();
  v10 = AllToolbars->m_pNodeHead;
  afxAllToolBars = AllToolbars;
  while ( v10 != nullptr )
  {
    posSave = (__POSITION *)v10;
    v11 = v10->data;
    v10 = v10->pNext;
    if ( v11 == nullptr )
      AfxThrowInvalidArgException();
    if ( CWnd::FromHandlePermanent(hWnd: (HWND__ *)v11[8].__vftable) == nullptr )
      CPtrList::RemoveAt(this: afxAllToolBars, position: posSave);
  }
  LOBYTE(v18) = 1;
  lstChildren.__vftable = (CList<HWND__ *,HWND__ *>_vtbl *)&CList<HWND__ *,HWND__ *>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&lstChildren);
  LOBYTE(v18) = 0;
  CDockingManager::~CDockingManager(this: &this->m_dockManager);
  v18 = -1;
  COleCntrFrameWnd::~COleCntrFrameWnd(this);
}

//------------------------------------------------------------------------------
// Address: 0x10407BE6
// Name: protected: virtual struct AFX_MSGMAP const __near * COleCntrFrameWndEx::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall COleCntrFrameWndEx::GetMessageMap(COleCntrFrameWndEx *this)
{
  return (const AFX_MSGMAP *)&off_1068B588;
}

//------------------------------------------------------------------------------
// Address: 0x10407BEC
// Name: public: CMFCDragFrameImpl::CMFCDragFrameImpl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CMFCDragFrameImpl *__thiscall CMFCDragFrameImpl::CMFCDragFrameImpl(CMFCDragFrameImpl *this)
{
  CRect *p_m_rectExpectedDocked; // ebx
  int m_nDragFrameThicknessFloat; // eax

  this->__vftable = (CMFCDragFrameImpl_vtbl *)&CMFCDragFrameImpl::`vftable';
  this->m_ptHot.x = 0;
  this->m_ptHot.y = 0;
  this->m_rectDrag.left = 0;
  this->m_rectDrag.top = 0;
  this->m_rectDrag.right = 0;
  this->m_rectDrag.bottom = 0;
  p_m_rectExpectedDocked = &this->m_rectExpectedDocked;
  this->m_rectExpectedDocked.left = 0;
  this->m_rectExpectedDocked.top = 0;
  this->m_rectExpectedDocked.right = 0;
  this->m_rectExpectedDocked.bottom = 0;
  SetRectEmpty(lprc: &this->m_rectDrag);
  SetRectEmpty(lprc: p_m_rectExpectedDocked);
  this->m_ptHot.y = 0;
  this->m_ptHot.x = 0;
  m_nDragFrameThicknessFloat = afxGlobalData.m_nDragFrameThicknessFloat;
  this->m_nInsertedTabID = -1;
  this->m_pDraggedWnd = nullptr;
  this->m_pDockManager = nullptr;
  this->m_pTargetBar = nullptr;
  this->m_bDockToTab = 0;
  this->m_pFinalTargetBar = nullptr;
  this->m_bDragStarted = 0;
  this->m_bFrameTabDrawn = 0;
  this->m_pOldTargetBar = nullptr;
  this->m_pWndDummy = nullptr;
  this->m_nOldThickness = m_nDragFrameThicknessFloat;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10407C5E
// Name: public: virtual CMFCDragFrameImpl::~CMFCDragFrameImpl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDragFrameImpl::~CMFCDragFrameImpl(CMFCDragFrameImpl *this)
{
  CDockablePane *m_pWndDummy; // ecx
  CDockablePane *v3; // ecx

  m_pWndDummy = this->m_pWndDummy;
  this->__vftable = (CMFCDragFrameImpl_vtbl *)&CMFCDragFrameImpl::`vftable';
  if ( m_pWndDummy != nullptr )
  {
    m_pWndDummy->DestroyWindow(this: &m_pWndDummy->CPane);
    v3 = this->m_pWndDummy;
    if ( v3 != nullptr )
      ((void (__thiscall *)(CDockablePane *, int))v3->dtr_CObject)(a1: v3, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10407C85
// Name: public: void CMFCDragFrameImpl::Init(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDragFrameImpl::Init(CMFCDragFrameImpl *this, CWnd *pDraggedWnd)
{
  CWnd *v3; // ebx
  CObject *v4; // eax
  CWnd *v5; // eax
  CObject *v6; // edi
  CDockingManager *DockingManager; // eax

  this->m_pDraggedWnd = pDraggedWnd;
  v3 = nullptr;
  if ( CObject::IsKindOf(this: pDraggedWnd, pClass: &CPaneFrameWnd::classCPaneFrameWnd) != 0 )
  {
    v4 = AfxDynamicDownCast(pClass: &CPaneFrameWnd::classCPaneFrameWnd, pObject: this->m_pDraggedWnd);
  }
  else
  {
    if ( CObject::IsKindOf(this: this->m_pDraggedWnd, pClass: &CPane::classCPane) == 0 )
      goto LABEL_8;
    v6 = AfxDynamicDownCast(pClass: &CPane::classCPane, pObject: this->m_pDraggedWnd);
    v4 = (CObject *)((int (__thiscall *)(CObject *, _DWORD))v6->__vftable[45].Serialize)(a1: v6, a2: 0);
    if ( v4 == nullptr )
    {
      v5 = (CWnd *)v6->__vftable[34].GetRuntimeClass(this: v6);
      goto LABEL_7;
    }
  }
  v5 = CWnd::FromHandlePermanent(hWnd: (HWND__ *)v4[47].__vftable);
LABEL_7:
  v3 = v5;
LABEL_8:
  DockingManager = CGlobalUtils::GetDockingManager(this: &afxGlobalUtils, pWnd: v3);
  this->m_pDockManager = DockingManager;
  if ( afxGlobalUtils.m_bDialogApp == 0 && DockingManager == nullptr )
    AfxThrowInvalidArgException();
}

//------------------------------------------------------------------------------
// Address: 0x10407D20
// Name: public: void CMFCDragFrameImpl::ResetState(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDragFrameImpl::ResetState(CMFCDragFrameImpl *this)
{
  this->m_ptHot.x = -1;
  this->m_ptHot.y = -1;
  SetRectEmpty(lprc: &this->m_rectDrag);
  SetRectEmpty(lprc: &this->m_rectExpectedDocked);
  this->m_nInsertedTabID = -1;
  this->m_pFinalTargetBar = nullptr;
  this->m_pOldTargetBar = nullptr;
  this->m_bDockToTab = 0;
  this->m_bDragStarted = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10407D58
// Name: protected: virtual struct AFX_MSGMAP const __near * CDummyDockablePane::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CDummyDockablePane::GetMessageMap(CDummyDockablePane *this)
{
  return (const AFX_MSGMAP *)&off_1068B61C;
}

//------------------------------------------------------------------------------
// Address: 0x10407DA0
// Name: protected: void CMFCDragFrameImpl::DrawDragFrame(struct tagRECT const __near *,struct tagRECT const __near *,int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDragFrameImpl::DrawDragFrame(
        CMFCDragFrameImpl *this,
        const tagRECT *lpRectOld,
        const tagRECT *lpRectNew,
        int bFirstTime,
        int nNewThickness,
        int nOldThikness)
{
  HWND DesktopWindow; // eax
  CWnd *v8; // eax
  CDockingManager *m_pDockManager; // eax
  CSmartDockingManager *m_pSDManager; // esi
  tagSIZE v11; // [esp-1Ch] [ebp-4Ch]
  const tagRECT *v12; // [esp-14h] [ebp-44h]
  CRect v13; // [esp-10h] [ebp-40h] BYREF
  CWindowDC dc; // [esp+10h] [ebp-20h] BYREF
  int v15; // [esp+2Ch] [ebp-4h]

  DesktopWindow = GetDesktopWindow();
  v8 = CWnd::FromHandle(hWnd: DesktopWindow);
  CWindowDC::CWindowDC(this: &dc, pWnd: v8);
  m_pDockManager = this->m_pDockManager;
  v15 = 0;
  if ( m_pDockManager != nullptr
    && (m_pSDManager = m_pDockManager->m_pSDManager) != nullptr
    && m_pSDManager->m_bCreated != 0
    && m_pSDManager->m_bStarted != 0 )
  {
    CopyRect(lprcDst: &v13, lprcSrc: lpRectNew);
    CSmartDockingManager::ShowPlaceAt(this: m_pSDManager, rect: v13);
  }
  else
  {
    v13.bottom = 0;
    v13.right = 0;
    v13.top = nOldThikness;
    v13.left = nOldThikness;
    if ( bFirstTime != 0 )
      v12 = nullptr;
    else
      v12 = lpRectOld;
    v11.cy = nNewThickness;
    v11.cx = nNewThickness;
    CDC::DrawDragRect(
      this: &dc,
      lpRect: lpRectNew,
      size: v11,
      lpRectLast: v12,
      sizeLast: *(tagSIZE *)&v13.left,
      pBrush: (CFont *)v13.right,
      pBrushLast: (CFont *)v13.bottom);
  }
  v15 = -1;
  CWindowDC::~CWindowDC(this: &dc);
}

//------------------------------------------------------------------------------
// Address: 0x10407E34
// Name: protected: void CMFCDragFrameImpl::DrawFrameTab(class CDockablePane __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDragFrameImpl::DrawFrameTab(CMFCDragFrameImpl *this, CDockablePane *pTargetBar, int bErase)
{
  CDockingManager *m_pDockManager; // eax
  CSmartDockingManager *m_pSDManager; // eax
  int m_nDragFrameThicknessDock; // ebx
  int v7; // edi
  int bottom; // eax
  CRect v9; // [esp-1Ch] [ebp-78h] BYREF
  int v10; // [esp-Ch] [ebp-68h]
  HWND m_hWnd; // [esp-8h] [ebp-64h]
  CRect *p_rectWnd; // [esp-4h] [ebp-60h]
  CMFCDragFrameImpl *v13; // [esp+Ch] [ebp-50h]
  int bSDockingIsOn; // [esp+10h] [ebp-4Ch]
  CSmartDockingManager *pSDManager; // [esp+14h] [ebp-48h]
  CRect rectLine; // [esp+18h] [ebp-44h] BYREF
  CRect rectEmpty; // [esp+28h] [ebp-34h] BYREF
  CRect rectWnd; // [esp+38h] [ebp-24h] BYREF
  CRect rectSmallTab; // [esp+48h] [ebp-14h] BYREF

  p_rectWnd = &rectWnd;
  m_hWnd = pTargetBar->m_hWnd;
  v13 = this;
  memset(&rectWnd, 0, sizeof(rectWnd));
  GetWindowRect(hWnd: m_hWnd, lpRect: &rectWnd);
  m_pDockManager = this->m_pDockManager;
  pSDManager = nullptr;
  bSDockingIsOn = 0;
  if ( m_pDockManager != nullptr )
  {
    m_pSDManager = m_pDockManager->m_pSDManager;
    pSDManager = m_pSDManager;
    if ( m_pSDManager != nullptr && m_pSDManager->m_bCreated != 0 )
      bSDockingIsOn = m_pSDManager->m_bStarted != 0;
  }
  m_nDragFrameThicknessDock = afxGlobalData.m_nDragFrameThicknessDock;
  rectSmallTab.top = rectWnd.top;
  rectSmallTab.right = rectWnd.right;
  rectSmallTab.bottom = rectWnd.bottom;
  rectSmallTab.left = rectWnd.left + 10;
  v7 = 0;
  if ( CTabbedPane::m_bTabsAlwaysTop != 0 )
  {
    rectWnd.top += afxGlobalData.m_nTextHeightHorz;
    rectSmallTab.bottom = rectSmallTab.top + afxGlobalData.m_nTextHeightHorz;
  }
  else
  {
    rectWnd.bottom -= afxGlobalData.m_nTextHeightHorz;
    rectSmallTab.top = rectSmallTab.bottom - afxGlobalData.m_nTextHeightHorz;
  }
  rectSmallTab.right = rectSmallTab.left + 40;
  if ( rectSmallTab.left + 40 >= rectWnd.right )
    rectSmallTab.right = rectWnd.right - afxGlobalData.m_nDragFrameThicknessDock - 4;
  memset(&rectEmpty, 0, sizeof(rectEmpty));
  SetRectEmpty(lprc: &rectEmpty);
  bottom = rectSmallTab.bottom;
  memset(&rectLine, 0, sizeof(rectLine));
  if ( CTabbedPane::m_bTabsAlwaysTop == 0 )
    bottom = rectSmallTab.top;
  SetRect(
    lprc: &rectLine,
    xLeft: m_nDragFrameThicknessDock + rectSmallTab.left,
    yTop: bottom - m_nDragFrameThicknessDock,
    xRight: rectSmallTab.right - m_nDragFrameThicknessDock,
    yBottom: bottom + m_nDragFrameThicknessDock);
  if ( bErase != 0 )
  {
    if ( bSDockingIsOn != 0 )
    {
      CSmartDockingManager::HidePlace(this: pSDManager);
      return;
    }
  }
  else
  {
    if ( bSDockingIsOn != 0 )
    {
      p_rectWnd = (CRect *)(rectSmallTab.bottom - rectSmallTab.top);
      m_hWnd = (HWND)(rectSmallTab.right - rectSmallTab.left);
      v10 = 10;
      CopyRect(lprcDst: &v9, lprcSrc: &rectWnd);
      CSmartDockingManager::ShowTabbedPlaceAt(
        this: pSDManager,
        rect: v9,
        nTabXOffset: v10,
        nTabWidth: (int)m_hWnd,
        nTabHeight: (int)p_rectWnd);
      return;
    }
    v7 = 1;
  }
  CMFCDragFrameImpl::DrawDragFrame(
    this: v13,
    lpRectOld: &rectEmpty,
    lpRectNew: &rectSmallTab,
    bFirstTime: v7,
    nNewThickness: m_nDragFrameThicknessDock,
    nOldThikness: m_nDragFrameThicknessDock);
  CMFCDragFrameImpl::DrawDragFrame(
    this: v13,
    lpRectOld: &rectEmpty,
    lpRectNew: &rectWnd,
    bFirstTime: v7,
    nNewThickness: m_nDragFrameThicknessDock,
    nOldThikness: m_nDragFrameThicknessDock);
  CMFCDragFrameImpl::DrawDragFrame(
    this: v13,
    lpRectOld: &rectEmpty,
    lpRectNew: &rectLine,
    bFirstTime: v7,
    nNewThickness: m_nDragFrameThicknessDock,
    nOldThikness: m_nDragFrameThicknessDock);
  v13->m_bFrameTabDrawn = v7;
}

//------------------------------------------------------------------------------
// Address: 0x10407FC8
// Name: public: void CMFCDragFrameImpl::RemoveTabPreDocking(class CDockablePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDragFrameImpl::RemoveTabPreDocking(CMFCDragFrameImpl *this, CDockablePane *pOldTargetBar)
{
  CDockablePane *m_pOldTargetBar; // ebx
  CObject *v4; // edi
  CDockablePane *m_pWndDummy; // ecx
  CDockingManager *m_pDockManager; // eax
  BOOL v7; // ebx
  CSmartDockingManager *m_pSDManager; // eax
  int v9; // eax
  int v10; // eax
  CSmartDockingManager *v11; // eax

  m_pOldTargetBar = pOldTargetBar;
  if ( (pOldTargetBar != nullptr || (m_pOldTargetBar = this->m_pOldTargetBar) != nullptr)
    && this->m_nInsertedTabID != -1 )
  {
    v4 = AfxDynamicDownCast(pClass: &CBaseTabbedPane::classCBaseTabbedPane, pObject: &m_pOldTargetBar->CPane);
    if ( v4 != nullptr
      && this->m_bFrameTabDrawn == 0
      && (m_pWndDummy = this->m_pWndDummy) != nullptr
      && m_pWndDummy->m_hWnd != nullptr )
    {
      m_pDockManager = this->m_pDockManager;
      v7 = false;
      if ( m_pDockManager != nullptr )
      {
        m_pSDManager = m_pDockManager->m_pSDManager;
        if ( m_pSDManager != nullptr && m_pSDManager->m_bCreated != 0 )
          v7 = m_pSDManager->m_bStarted != 0;
      }
      CWnd::ShowWindow(this: &m_pWndDummy->CPane, nCmdShow: 0);
      if ( !v7 )
        CDockingManager::LockUpdate(this: this->m_pDockManager, bLock: 0);
      v9 = ((int (__thiscall *)(CObject *))v4->__vftable[77].Serialize)(a1: v4);
      if ( (CDockablePane *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v9 + 428))(a1: v9, a2: this->m_nInsertedTabID) == this->m_pWndDummy )
      {
        v10 = ((int (__thiscall *)(CObject *))v4->__vftable[77].Serialize)(a1: v4);
        (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v10 + 404))(a1: v10, a2: this->m_nInsertedTabID, a3: 1);
      }
      if ( !v7 )
        CDockingManager::LockUpdate(this: this->m_pDockManager, bLock: 1);
    }
    else
    {
      CMFCDragFrameImpl::DrawFrameTab(this, pTargetBar: m_pOldTargetBar, bErase: 1);
    }
    v11 = this->m_pDockManager->m_pSDManager;
    if ( v11 != nullptr && v11->m_bCreated != 0 && v11->m_bStarted != 0 )
      CWnd::ShowWindow(this: this->m_pDraggedWnd, nCmdShow: 5);
  }
  this->m_nInsertedTabID = -1;
  this->m_pOldTargetBar = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104080CE
// Name: public: void CMFCDragFrameImpl::EndDrawDragFrame(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDragFrameImpl::EndDrawDragFrame(CMFCDragFrameImpl *this, int bClearInternalRects)
{
  CDockingManager *m_pDockManager; // eax
  CSmartDockingManager *m_pSDManager; // ecx
  CRect *p_m_rectExpectedDocked; // esi
  int *p_top; // esi
  CDockingManager *v7; // ebx
  int bSDockingIsOn; // [esp+8h] [ebp-28h]
  CRect rectDocked; // [esp+Ch] [ebp-24h] BYREF
  CRect rectEmpty; // [esp+1Ch] [ebp-14h] BYREF

  m_pDockManager = this->m_pDockManager;
  if ( m_pDockManager != nullptr )
  {
    m_pSDManager = m_pDockManager->m_pSDManager;
    bSDockingIsOn = 0;
    if ( m_pSDManager != nullptr && m_pSDManager->m_bCreated != 0 && m_pSDManager->m_bStarted != 0 )
    {
      bSDockingIsOn = 1;
      CSmartDockingManager::HidePlace(this: m_pSDManager);
    }
    memset(&rectEmpty, 0, sizeof(rectEmpty));
    SetRectEmpty(lprc: &rectEmpty);
    p_m_rectExpectedDocked = &this->m_rectExpectedDocked;
    if ( IsRectEmpty(lprc: &this->m_rectExpectedDocked) )
      p_m_rectExpectedDocked = &this->m_rectDrag;
    rectDocked.left = p_m_rectExpectedDocked->left;
    p_top = &p_m_rectExpectedDocked->top;
    rectDocked.top = *p_top++;
    rectDocked.right = *p_top;
    rectDocked.bottom = p_top[1];
    if ( this->m_nInsertedTabID == -1 )
    {
      if ( bSDockingIsOn == 0 )
        CMFCDragFrameImpl::DrawDragFrame(
          this,
          lpRectOld: &rectEmpty,
          lpRectNew: &rectDocked,
          bFirstTime: 0,
          nNewThickness: this->m_nOldThickness,
          nOldThikness: 4);
    }
    else
    {
      this->m_bDockToTab = 1;
    }
    if ( bClearInternalRects != 0 )
    {
      CMFCDragFrameImpl::RemoveTabPreDocking(this, pOldTargetBar: nullptr);
      SetRectEmpty(lprc: &this->m_rectExpectedDocked);
      SetRectEmpty(lprc: &this->m_rectDrag);
      this->m_pFinalTargetBar = this->m_pTargetBar;
      this->m_pTargetBar = nullptr;
    }
    this->m_bDragStarted = 0;
    v7 = this->m_pDockManager;
    if ( v7 == nullptr )
      AfxThrowInvalidArgException();
    if ( bSDockingIsOn == 0 )
      CDockingManager::LockUpdate(this: v7, bLock: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104081C3
// Name: public: void CMFCDragFrameImpl::PlaceTabPreDocking(class CBaseTabbedPane __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDragFrameImpl::PlaceTabPreDocking(
        CMFCDragFrameImpl *this,
        CBaseTabbedPane *pTabbedBar,
        int bFirstTime)
{
  HWND__ *m_hWnd; // ebx
  CAfxStringMgr *StringManager; // eax
  CWnd *m_pDraggedWnd; // ecx
  CObject *v7; // eax
  CWnd *v8; // eax
  CDockablePane *v9; // eax
  CDockablePane *v10; // edi
  CDockablePane *v11; // eax
  CWnd *v12; // ecx
  CFrameWnd *TopLevelFrame; // eax
  CMFCBaseTabCtrl *v14; // eax
  CSmartDockingManager *m_pSDManager; // eax
  CMFCBaseTabCtrl *v16; // eax
  CDockablePane *m_pWndDummy; // edx
  int v18; // eax
  ATL::CStringData *v19; // ecx
  ATL::CSimpleStringT<char,0> v20; // [esp+18h] [ebp-24h] BYREF
  _DWORD v21[7]; // [esp+1Ch] [ebp-20h] BYREF
  int v22; // [esp+38h] [ebp-4h]

  if ( this->m_nInsertedTabID == -1 )
  {
    m_hWnd = nullptr;
    if ( bFirstTime == 0 )
      CMFCDragFrameImpl::EndDrawDragFrame(this, bClearInternalRects: 0);
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &v20, pStringMgr: StringManager);
    m_pDraggedWnd = this->m_pDraggedWnd;
    v22 = 0;
    if ( CObject::IsKindOf(this: m_pDraggedWnd, pClass: &CMultiPaneFrameWnd::classCMultiPaneFrameWnd) != 0 )
    {
      v7 = AfxDynamicDownCast(pClass: &CMultiPaneFrameWnd::classCMultiPaneFrameWnd, pObject: this->m_pDraggedWnd);
      if ( v7 != nullptr )
      {
        v8 = (CWnd *)((int (__thiscall *)(CObject *))v7->__vftable[35].dtr_CObject)(a1: v7);
        if ( v8 != nullptr )
          CWnd::GetWindowTextA(
            this: v8,
            rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v20);
      }
    }
    else
    {
      CWnd::GetWindowTextA(
        this: this->m_pDraggedWnd,
        rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v20);
    }
    if ( this->m_pWndDummy == nullptr )
    {
      v9 = (CDockablePane *)operator new(nSize: 0x350u);
      v10 = v9;
      LOBYTE(v22) = 1;
      if ( v9 != nullptr )
      {
        CDockablePane::CDockablePane(this: v9);
        v10->__vftable = (CDockablePane_vtbl *)&CDummyDockablePane::`vftable';
        v11 = v10;
      }
      else
      {
        v11 = nullptr;
      }
      v12 = this->m_pDraggedWnd;
      this->m_pWndDummy = v11;
      TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame;
      LOBYTE(v22) = 0;
      memset(v21, 0, 16);
      if ( g_pTopLevelFrame == nullptr )
        TopLevelFrame = CWnd::GetTopLevelFrame(this: v12);
      this->m_pWndDummy->CreateEx(
        this: this->m_pWndDummy,
        a2: 0,
        a3: &var,
        a4: TopLevelFrame,
        a5: (const tagRECT *)v21,
        a6: 0,
        a7: AFX_DUMMY_WND_ID,
        a8: 0x40000000u,
        a9: 32u,
        a10: 15u,
        a11: nullptr);
    }
    v14 = pTabbedBar->GetUnderlyingWindow(this: pTabbedBar);
    v14->AddTab_2(this: v14, a2: &this->m_pWndDummy->CPane, a3: v20.m_pszData, a4: -1u, a5: 1);
    m_pSDManager = this->m_pDockManager->m_pSDManager;
    if ( m_pSDManager != nullptr && m_pSDManager->m_bCreated != 0 && m_pSDManager->m_bStarted != 0 )
      CWnd::ShowWindow(this: this->m_pDraggedWnd, nCmdShow: 0);
    v16 = pTabbedBar->GetUnderlyingWindow(this: pTabbedBar);
    m_pWndDummy = this->m_pWndDummy;
    if ( m_pWndDummy != nullptr )
      m_hWnd = m_pWndDummy->m_hWnd;
    v18 = v16->GetTabFromHwnd(this: v16, a2: m_hWnd);
    v19 = (ATL::CStringData *)(v20.m_pszData - 16);
    this->m_nInsertedTabID = v18;
    this->m_pOldTargetBar = pTabbedBar;
    ATL::CStringData::Release(this: v19);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10408335
// Name: public: void CMFCDragFrameImpl::PlaceTabPreDocking(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDragFrameImpl::PlaceTabPreDocking(CMFCDragFrameImpl *this, CWnd *pCBarToPlaceOn)
{
  CBaseTabbedPane *v3; // edi
  CDockablePane *v4; // eax
  CDockablePane *v5; // edi

  v3 = (CBaseTabbedPane *)AfxDynamicDownCast(pClass: &CBaseTabbedPane::classCBaseTabbedPane, pObject: pCBarToPlaceOn);
  if ( v3 != nullptr
    && (v3->GetVisibleTabsNum(this: v3) > 1 && v3->IsHideSingleTab(this: v3) != 0
     || v3->GetVisibleTabsNum(this: v3) > 0 && v3->IsHideSingleTab(this: v3) == 0) )
  {
    this->m_pTargetBar = v3;
    CMFCDragFrameImpl::PlaceTabPreDocking(this, pTabbedBar: v3, bFirstTime: 1);
  }
  else if ( this->m_nInsertedTabID == -1 )
  {
    v4 = (CDockablePane *)AfxDynamicDownCast(pClass: &CDockablePane::classCDockablePane, pObject: pCBarToPlaceOn);
    v5 = v4;
    if ( v4 != nullptr )
    {
      CMFCDragFrameImpl::DrawFrameTab(this, pTargetBar: v4, bErase: 0);
      this->m_pTargetBar = v5;
      this->m_pOldTargetBar = v5;
      this->m_nInsertedTabID = 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104083D3
// Name: public: void CMFCDragFrameImpl::MoveDragFrame(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCDragFrameImpl::MoveDragFrame(CMFCDragFrameImpl *this, int bForceMove)
{
  CDockablePane *v3; // eax
  CDockablePane *v4; // esi
  CDockablePane *v5; // eax
  CWnd *m_pDraggedWnd; // ecx
  CFrameWnd *TopLevelFrame; // eax
  int v8; // esi
  CDockingManager *m_pDockManager; // ecx
  CRect *p_m_rectExpectedDocked; // esi
  int *p_top; // esi
  CObject *v12; // esi
  CDockablePane **p_m_pTargetBar; // edi
  CDockingManager *v14; // ecx
  CSmartDockingManager *m_pSDManager; // eax
  CWnd *v16; // ecx
  CObject *v17; // eax
  CBaseTabbedPane *v18; // esi
  bool v19; // zf
  CDockablePane *m_nDragFrameThicknessFloat; // eax
  CRect *p_m_rectDrag; // esi
  int *v22; // esi
  CDockablePane *v23; // esi
  int v24; // [esp+10h] [ebp-74h]
  int dy; // [esp+14h] [ebp-70h]
  BOOL pData; // [esp+1Ch] [ebp-68h]
  int bDrawTab; // [esp+20h] [ebp-64h] BYREF
  int bFirstTime; // [esp+24h] [ebp-60h]
  tagPOINT Point; // [esp+28h] [ebp-5Ch] BYREF
  CDockablePane *pOldTargetBar; // [esp+30h] [ebp-54h]
  tagRECT RectOld; // [esp+34h] [ebp-50h] BYREF
  _DWORD v32[4]; // [esp+44h] [ebp-40h] BYREF
  tagRECT RectNew; // [esp+54h] [ebp-30h] BYREF
  tagRECT rc; // [esp+64h] [ebp-20h] BYREF
  int v35; // [esp+80h] [ebp-4h]
  CSize v36; // 0:^40.8

  this->m_pFinalTargetBar = nullptr;
  if ( this->m_pDraggedWnd != nullptr && this->m_pDockManager != nullptr )
  {
    if ( this->m_pWndDummy == nullptr )
    {
      v3 = (CDockablePane *)operator new(nSize: 0x350u);
      v4 = v3;
      v35 = 0;
      if ( v3 != nullptr )
      {
        CDockablePane::CDockablePane(this: v3);
        v4->__vftable = (CDockablePane_vtbl *)&CDummyDockablePane::`vftable';
        v5 = v4;
      }
      else
      {
        v5 = nullptr;
      }
      v35 = -1;
      m_pDraggedWnd = this->m_pDraggedWnd;
      this->m_pWndDummy = v5;
      TopLevelFrame = (CFrameWnd *)g_pTopLevelFrame;
      memset(v32, 0, sizeof(v32));
      if ( g_pTopLevelFrame == nullptr )
        TopLevelFrame = CWnd::GetTopLevelFrame(this: m_pDraggedWnd);
      this->m_pWndDummy->CreateEx(
        this: this->m_pWndDummy,
        a2: 0,
        a3: &var,
        a4: TopLevelFrame,
        a5: (const tagRECT *)v32,
        a6: 0,
        a7: AFX_DUMMY_WND_ID,
        a8: 0x40000000u,
        a9: 32u,
        a10: 15u,
        a11: nullptr);
    }
    v36 = CDockablePane::m_sizeDragSensitivity;
    Point.x = 0;
    Point.y = 0;
    GetCursorPos(lpPoint: &Point);
    v8 = Point.y - this->m_ptHot.y;
    v24 = Point.x - this->m_ptHot.x;
    dy = v8;
    if ( abs(lnumber: v24) >= v36.cx
      || abs(lnumber: v8) >= v36.cy
      || !IsRectEmpty(lprc: &this->m_rectDrag)
      || bForceMove != 0 )
    {
      m_pDockManager = this->m_pDockManager;
      this->m_bDragStarted = 1;
      CDockingManager::LockUpdate(this: m_pDockManager, bLock: 1);
      p_m_rectExpectedDocked = &this->m_rectExpectedDocked;
      if ( IsRectEmpty(lprc: &this->m_rectExpectedDocked) )
        p_m_rectExpectedDocked = &this->m_rectDrag;
      bFirstTime = 0;
      RectOld.left = p_m_rectExpectedDocked->left;
      p_top = &p_m_rectExpectedDocked->top;
      RectOld.top = *p_top++;
      RectOld.right = *p_top;
      RectOld.bottom = p_top[1];
      if ( IsRectEmpty(lprc: &this->m_rectDrag) )
      {
        if ( CObject::IsKindOf(this: this->m_pDraggedWnd, pClass: &CPaneFrameWnd::classCPaneFrameWnd) != 0 )
        {
          GetWindowRect(hWnd: this->m_pDraggedWnd->m_hWnd, lpRect: &this->m_rectDrag);
        }
        else if ( CObject::IsKindOf(this: this->m_pDraggedWnd, pClass: &CPane::classCPane) != 0 )
        {
          v12 = AfxDynamicDownCast(pClass: &CPane::classCPane, pObject: this->m_pDraggedWnd);
          GetWindowRect(hWnd: this->m_pDraggedWnd->m_hWnd, lpRect: &this->m_rectDrag);
          if ( ((int (__thiscall *)(CObject *, _DWORD))v12->__vftable[45].Serialize)(a1: v12, a2: 0) == 0 )
          {
            this->m_rectDrag.right = this->m_rectDrag.left + (char *)v12[120].__vftable - (char *)v12[118].__vftable;
            this->m_rectDrag.bottom = this->m_rectDrag.top + (char *)v12[121].__vftable - (char *)v12[119].__vftable;
          }
          if ( !PtInRect(lprc: &this->m_rectDrag, pt: this->m_ptHot.tagPOINT) )
            OffsetRect(lprc: &this->m_rectDrag, dx: this->m_ptHot.x - this->m_rectDrag.left - 5, dy: 0);
        }
        bFirstTime = 1;
      }
      bDrawTab = 0;
      p_m_pTargetBar = &this->m_pTargetBar;
      pOldTargetBar = this->m_pTargetBar;
      memset(&rc, 0, sizeof(rc));
      SetRectEmpty(lprc: &rc);
      v14 = this->m_pDockManager;
      pData = false;
      if ( v14 != nullptr )
      {
        m_pSDManager = v14->m_pSDManager;
        if ( m_pSDManager != nullptr && m_pSDManager->m_bCreated != 0 )
          pData = m_pSDManager->m_bStarted != 0;
      }
      CDockingManager::CalcExpectedDockedRect(
        this: v14,
        pWnd: this->m_pDraggedWnd,
        ptMouse: (CPoint)Point,
        rectResult: (CRect *)&rc,
        &bDrawTab,
        ppTargetBar: p_m_pTargetBar);
      if ( pOldTargetBar != nullptr
        && this->m_nInsertedTabID != -1
        && (pOldTargetBar != *p_m_pTargetBar || bDrawTab == 0) )
      {
        CMFCDragFrameImpl::RemoveTabPreDocking(this, pOldTargetBar);
        bFirstTime = 1;
      }
      v16 = this->m_pDraggedWnd;
      pOldTargetBar = (CDockablePane *)1;
      if ( CObject::IsKindOf(this: v16, pClass: &CPaneFrameWnd::classCPaneFrameWnd) == 0
        && CObject::IsKindOf(this: this->m_pDraggedWnd, pClass: &CPane::classCPane) != 0 )
      {
        v17 = AfxDynamicDownCast(pClass: &CPane::classCPane, pObject: this->m_pDraggedWnd);
        pOldTargetBar = (CDockablePane *)((int (__thiscall *)(CObject *))v17->__vftable[32].Serialize)(a1: v17);
      }
      if ( *p_m_pTargetBar != nullptr && pOldTargetBar != nullptr )
      {
        v18 = (CBaseTabbedPane *)AfxDynamicDownCast(
                                   pClass: &CBaseTabbedPane::classCBaseTabbedPane,
                                   pObject: &(*p_m_pTargetBar)->CPane);
        if ( v18 == nullptr )
          goto LABEL_46;
        if ( bDrawTab != 0 )
        {
          if ( v18->GetVisibleTabsNum(this: v18) > 1 && v18->IsHideSingleTab(this: v18) != 0
            || v18->GetVisibleTabsNum(this: v18) > 0 && v18->IsHideSingleTab(this: v18) == 0 )
          {
            CMFCDragFrameImpl::PlaceTabPreDocking(this, pTabbedBar: v18, bFirstTime);
            return;
          }
LABEL_46:
          if ( bDrawTab != 0 )
          {
            if ( this->m_nInsertedTabID == -1 )
            {
              if ( bFirstTime == 0 )
                CMFCDragFrameImpl::EndDrawDragFrame(this, bClearInternalRects: 0);
              CMFCDragFrameImpl::DrawFrameTab(this, pTargetBar: *p_m_pTargetBar, bErase: 0);
              this->m_nInsertedTabID = 1;
            }
            return;
          }
        }
      }
      OffsetRect(lprc: &this->m_rectDrag, dx: v24, dy);
      this->m_ptHot = (CPoint)Point;
      this->m_rectExpectedDocked = (CRect)rc;
      v19 = !IsRectEmpty(lprc: &this->m_rectExpectedDocked);
      m_nDragFrameThicknessFloat = (CDockablePane *)afxGlobalData.m_nDragFrameThicknessFloat;
      if ( v19 )
        m_nDragFrameThicknessFloat = (CDockablePane *)afxGlobalData.m_nDragFrameThicknessDock;
      pOldTargetBar = m_nDragFrameThicknessFloat;
      p_m_rectDrag = &this->m_rectExpectedDocked;
      memset(&RectNew, 0, sizeof(RectNew));
      if ( IsRectEmpty(lprc: &this->m_rectExpectedDocked) )
      {
        p_m_rectDrag = &this->m_rectDrag;
        if ( !PtInRect(lprc: &this->m_rectDrag, pt: Point) )
          OffsetRect(
            lprc: &this->m_rectDrag,
            dx: Point.x - (p_m_rectDrag->left + (this->m_rectDrag.right - this->m_rectDrag.left) / 2),
            dy: Point.y - (this->m_rectDrag.top + 5));
      }
      RectNew.left = p_m_rectDrag->left;
      v22 = &p_m_rectDrag->top;
      RectNew.top = *v22++;
      RectNew.right = *v22;
      RectNew.bottom = v22[1];
      if ( !pData || !IsRectEmpty(lprc: &this->m_rectExpectedDocked) )
      {
        v23 = pOldTargetBar;
        CMFCDragFrameImpl::DrawDragFrame(
          this,
          lpRectOld: &RectOld,
          lpRectNew: &RectNew,
          bFirstTime,
          nNewThickness: (int)pOldTargetBar,
          nOldThikness: this->m_nOldThickness);
        this->m_nOldThickness = (int)v23;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10408806
// Name: public: virtual struct CRuntimeClass __near * CMFCToolBarColorButton::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCToolBarColorButton::GetRuntimeClass(CMFCToolBarColorButton *this)
{
  return &CMFCToolBarColorButton::classCMFCToolBarColorButton;
}

//------------------------------------------------------------------------------
// Address: 0x1040880C
// Name: public: virtual struct CRuntimeClass __near * CMFCColorBar::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCColorBar::GetRuntimeClass(CMFCColorBar *this)
{
  return &CMFCColorBar::classCMFCColorBar;
}

//------------------------------------------------------------------------------
// Address: 0x10408812
// Name: protected: void CMFCColorBar::OnNcCalcSize(int,struct tagNCCALCSIZE_PARAMS __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCColorBar::OnNcCalcSize(
        CMFCColorBar *this,
        CFrameWnd *bCalcValidRects,
        tagNCCALCSIZE_PARAMS *lpncsp)
{
  if ( this->m_bIsTearOff != 0 )
    CMFCToolBar::OnNcCalcSize(this, __formal: (int)bCalcValidRects, lpncsp);
  else
    CBasePane::OnBeforeChangeParent((CMFCCaptionBar *)this, __formal: bCalcValidRects, __formal: (int)lpncsp);
}

//------------------------------------------------------------------------------
// Address: 0x1040C3F8
// Name: protected: long CMFCPropertyGridToolTipCtrl::OnSetFont(unsigned int,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPropertyGridToolTipCtrl::OnSetFont(
        CMFCPropertyGridToolTipCtrl *this,
        HFONT__ *wParam,
        __int16 lParam)
{
  this->m_hFont = wParam;
  if ( lParam != 0 )
  {
    InvalidateRect(hWnd: this->m_hWnd, lpRect: nullptr, bErase: true);
    UpdateWindow(hWnd: this->m_hWnd);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1040C42D
// Name: public: virtual int CMFCPropertyGridToolTipCtrl::PreTranslateMessage(struct tagMSG __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CMFCPropertyGridToolTipCtrl::PreTranslateMessage(CMFCPropertyGridToolTipCtrl *this, tagMSG *pMsg)
{
  unsigned int message; // ecx
  CWnd *m_pWndParent; // eax
  CPoint pt; // [esp+8h] [ebp-8h] BYREF

  message = pMsg->message;
  if ( message < 0x200 || message > 0x20E )
    return CWnd::PreTranslateMessage(this, pMsg);
  if ( message != 512 )
    CMFCPropertyGridToolTipCtrl::Hide(this);
  pt.x = LOWORD(pMsg->lParam);
  pt.y = HIWORD(pMsg->lParam);
  m_pWndParent = this->m_pWndParent;
  if ( m_pWndParent != nullptr )
    m_pWndParent = (CWnd *)m_pWndParent->m_hWnd;
  MapWindowPoints(hWndFrom: this->m_hWnd, hWndTo: (HWND)m_pWndParent, lpPoints: &pt, cPoints: 1u);
  SendMessageA(
    hWnd: this->m_pWndParent->m_hWnd,
    Msg: pMsg->message,
    wParam: pMsg->wParam,
    lParam: LOWORD(pt.x) | (LOWORD(pt.y) << 16));
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1041EBA6
// Name: protected: virtual struct AFX_MSGMAP const __near * CMFCRibbonKeyTip::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CMFCRibbonKeyTip::GetMessageMap(CMFCRibbonKeyTip *this)
{
  return (const AFX_MSGMAP *)&off_1068FBF4;
}

//------------------------------------------------------------------------------
// Address: 0x1041EDD0
// Name: public: void CRecentPaneContainerInfo::Init(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CRecentPaneContainerInfo::Init(CRecentPaneContainerInfo *this)
{
  this->m_pRecentBarContainer = nullptr;
  SetRect(lprc: &this->m_rectDockedRect, xLeft: 0, yTop: 0, xRight: 30, yBottom: 30);
  this->m_pRecentContainerOfTabWnd = nullptr;
  this->m_nRecentPercent = 50;
  this->m_bIsRecentLeftBar = 1;
}

//------------------------------------------------------------------------------
// Address: 0x1041EDFF
// Name: public: void CRecentDockSiteInfo::Init(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CRecentDockSiteInfo::Init(CRecentDockSiteInfo *this)
{
  SetRect(lprc: &this->m_rectRecentFloatingRect, xLeft: 10, yTop: 10, xRight: 110, yBottom: 110);
  this->m_nRecentTabNumber = -1;
  this->m_nRecentRowIndex = 0;
  this->m_pRecentDockBar = nullptr;
  this->m_pRecentDockBarRow = nullptr;
  this->m_hRecentDefaultSlider = nullptr;
  this->m_hRecentMiniFrame = nullptr;
  this->m_dwRecentAlignmentToFrame = 4096;
}

//------------------------------------------------------------------------------
// Address: 0x1041EE34
// Name: public: class CPaneContainer __near * CRecentDockSiteInfo::GetRecentPaneContainer(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPaneContainer *__thiscall CRecentDockSiteInfo::GetRecentPaneContainer(CRecentDockSiteInfo *this, int bForSlider)
{
  if ( bForSlider != 0 )
    return this->m_recentSliderInfo.m_pRecentBarContainer;
  else
    return this->m_recentMiniFrameInfo.m_pRecentBarContainer;
}

//------------------------------------------------------------------------------
// Address: 0x1041EE4E
// Name: public: class CPaneContainer __near * CRecentDockSiteInfo::GetRecentTabContainer(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPaneContainer *__thiscall CRecentDockSiteInfo::GetRecentTabContainer(CRecentDockSiteInfo *this, int bForSlider)
{
  if ( bForSlider != 0 )
    return this->m_recentSliderInfo.m_pRecentContainerOfTabWnd;
  else
    return this->m_recentMiniFrameInfo.m_pRecentContainerOfTabWnd;
}

//------------------------------------------------------------------------------
// Address: 0x1041EE68
// Name: public: class CRect __near & CRecentDockSiteInfo::GetRecentDockedRect(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRect *__thiscall CRecentDockSiteInfo::GetRecentDockedRect(CRecentDockSiteInfo *this, int bForSlider)
{
  CRect *result; // eax

  result = &this->m_recentSliderInfo.m_rectDockedRect;
  if ( bForSlider == 0 )
    return &this->m_recentMiniFrameInfo.m_rectDockedRect;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041EE7D
// Name: public: int CRecentDockSiteInfo::GetRecentDockedPercent(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CRecentDockSiteInfo::GetRecentDockedPercent(CRecentDockSiteInfo *this, int bForSlider)
{
  if ( bForSlider != 0 )
    return this->m_recentSliderInfo.m_nRecentPercent;
  else
    return this->m_recentMiniFrameInfo.m_nRecentPercent;
}

//------------------------------------------------------------------------------
// Address: 0x1041EE97
// Name: public: int CRecentDockSiteInfo::IsRecentLeftPane(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CRecentDockSiteInfo::IsRecentLeftPane(CRecentDockSiteInfo *this, int bForSlider)
{
  if ( bForSlider != 0 )
    return this->m_recentSliderInfo.m_bIsRecentLeftBar;
  else
    return this->m_recentMiniFrameInfo.m_bIsRecentLeftBar;
}

//------------------------------------------------------------------------------
// Address: 0x1041EEB1
// Name: public: class CList<struct HWND__ __near *,struct HWND__ __near *> __near & CRecentDockSiteInfo::GetRecentListOfPanes(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CList<HWND__ *,HWND__ *> *__thiscall CRecentDockSiteInfo::GetRecentListOfPanes(
        CRecentDockSiteInfo *this,
        int bForSlider)
{
  CList<HWND__ *,HWND__ *> *result; // eax

  result = &this->m_recentSliderInfo.m_lstRecentListOfBars;
  if ( bForSlider == 0 )
    return &this->m_recentMiniFrameInfo.m_lstRecentListOfBars;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041EEC9
// Name: public: class CPaneDivider __near * CRecentDockSiteInfo::GetRecentDefaultPaneDivider(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CPaneDivider *__thiscall CRecentDockSiteInfo::GetRecentDefaultPaneDivider(CRecentDockSiteInfo *this)
{
  CWnd *v1; // eax

  v1 = CWnd::FromHandlePermanent(hWnd: this->m_hRecentDefaultSlider);
  return (CPaneDivider *)AfxDynamicDownCast(pClass: &CPaneDivider::classCPaneDivider, pObject: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1041EEDF
// Name: public: virtual void CRecentDockSiteInfo::SetInfo(int,class CRecentDockSiteInfo __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CRecentDockSiteInfo::SetInfo(CRecentDockSiteInfo *this, int bForSlider, CRecentDockSiteInfo *srcInfo)
{
  if ( bForSlider != 0 )
  {
    this->m_dwRecentAlignmentToFrame = srcInfo->m_dwRecentAlignmentToFrame;
    this->m_hRecentDefaultSlider = srcInfo->m_hRecentDefaultSlider;
    this->m_recentSliderInfo.SetInfo(this: &this->m_recentSliderInfo, a2: &srcInfo->m_recentSliderInfo);
  }
  else
  {
    this->m_rectRecentFloatingRect = srcInfo->m_rectRecentFloatingRect;
    this->m_hRecentMiniFrame = srcInfo->m_hRecentMiniFrame;
    this->m_recentMiniFrameInfo.SetInfo(this: &this->m_recentMiniFrameInfo, a2: &srcInfo->m_recentMiniFrameInfo);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041EF2B
// Name: public: CRecentPaneContainerInfo::CRecentPaneContainerInfo(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRecentPaneContainerInfo *__thiscall CRecentPaneContainerInfo::CRecentPaneContainerInfo(CRecentPaneContainerInfo *this)
{
  this->__vftable = (CRecentPaneContainerInfo_vtbl *)&CRecentPaneContainerInfo::`vftable';
  this->m_rectDockedRect.left = 0;
  this->m_rectDockedRect.top = 0;
  this->m_rectDockedRect.right = 0;
  this->m_rectDockedRect.bottom = 0;
  CList<HWND__ *,HWND__ *>::CList<HWND__ *,HWND__ *>(this: &this->m_lstRecentListOfBars, nBlockSize: 10);
  CRecentPaneContainerInfo::Init(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1041EF59
// Name: public: virtual CRecentPaneContainerInfo::~CRecentPaneContainerInfo(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CRecentPaneContainerInfo::~CRecentPaneContainerInfo(CRecentPaneContainerInfo *this)
{
  CList<HWND__ *,HWND__ * &> *p_m_lstRecentListOfBars; // ecx

  this->__vftable = (CRecentPaneContainerInfo_vtbl *)&CRecentPaneContainerInfo::`vftable';
  p_m_lstRecentListOfBars = (CList<HWND__ *,HWND__ * &> *)&this->m_lstRecentListOfBars;
  p_m_lstRecentListOfBars->__vftable = (CList<HWND__ *,HWND__ * &>_vtbl *)&CList<HWND__ *,HWND__ *>::`vftable';
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: p_m_lstRecentListOfBars);
}

//------------------------------------------------------------------------------
// Address: 0x1041EF6D
// Name: public: virtual void CRecentPaneContainerInfo::StoreDockInfo(class CPaneContainer __near *,class CDockablePane __near *,class CDockablePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CRecentPaneContainerInfo::StoreDockInfo(
        CRecentPaneContainerInfo *this,
        CPaneContainer *pRecentContainer,
        CDockablePane *pBar,
        CDockablePane *pTabbedBar)
{
  BOOL IsLeftPane; // eax
  CPaneContainer *m_pRecentBarContainer; // eax
  CPaneContainerManager *m_pContainerManager; // ecx
  CPaneContainer *m_pRecentContainerOfTabWnd; // eax
  CPaneContainerManager *v9; // ecx
  CDockablePane *v10; // eax

  if ( pRecentContainer != nullptr )
  {
    CPaneContainer::AddRef(this: pRecentContainer);
    if ( pTabbedBar != nullptr )
      IsLeftPane = CPaneContainer::IsLeftPane(this: pRecentContainer, pBar: pTabbedBar);
    else
      IsLeftPane = CPaneContainer::IsLeftPane(this: pRecentContainer, pBar);
    this->m_bIsRecentLeftBar = IsLeftPane;
  }
  m_pRecentBarContainer = this->m_pRecentBarContainer;
  if ( m_pRecentBarContainer != nullptr && m_pRecentBarContainer->m_bDisposed == 0 )
  {
    m_pContainerManager = m_pRecentBarContainer->m_pContainerManager;
    --m_pRecentBarContainer->m_dwRefCount;
    if ( this->m_pRecentBarContainer->m_dwRefCount <= 0 )
      CPaneContainer::ReleaseEmptyPaneContainer(this: m_pContainerManager->m_pRootContainer);
    this->m_pRecentBarContainer = nullptr;
  }
  m_pRecentContainerOfTabWnd = this->m_pRecentContainerOfTabWnd;
  if ( m_pRecentContainerOfTabWnd != nullptr && m_pRecentContainerOfTabWnd->m_bDisposed == 0 )
  {
    v9 = m_pRecentContainerOfTabWnd->m_pContainerManager;
    --m_pRecentContainerOfTabWnd->m_dwRefCount;
    if ( this->m_pRecentContainerOfTabWnd->m_dwRefCount <= 0 )
      CPaneContainer::ReleaseEmptyPaneContainer(this: v9->m_pRootContainer);
    this->m_pRecentContainerOfTabWnd = nullptr;
  }
  GetWindowRect(hWnd: pBar->m_hWnd, lpRect: &this->m_rectDockedRect);
  v10 = pTabbedBar;
  if ( pTabbedBar != nullptr )
  {
    this->m_pRecentContainerOfTabWnd = pRecentContainer;
  }
  else
  {
    v10 = pBar;
    this->m_pRecentBarContainer = pRecentContainer;
  }
  this->m_nRecentPercent = v10->m_nLastPercent;
}

//------------------------------------------------------------------------------
// Address: 0x1041F02A
// Name: public: CRecentDockSiteInfo::CRecentDockSiteInfo(class CPane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRecentDockSiteInfo *__thiscall CRecentDockSiteInfo::CRecentDockSiteInfo(CRecentDockSiteInfo *this, CPane *pBar)
{
  this->__vftable = (CRecentDockSiteInfo_vtbl *)&CRecentDockSiteInfo::`vftable';
  this->m_rectRecentFloatingRect.left = 0;
  this->m_rectRecentFloatingRect.top = 0;
  this->m_rectRecentFloatingRect.right = 0;
  this->m_rectRecentFloatingRect.bottom = 0;
  CRecentPaneContainerInfo::CRecentPaneContainerInfo(this: &this->m_recentSliderInfo);
  CRecentPaneContainerInfo::CRecentPaneContainerInfo(this: &this->m_recentMiniFrameInfo);
  this->m_pBar = pBar;
  CRecentDockSiteInfo::Init(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1041F06D
// Name: public: virtual CRecentDockSiteInfo::~CRecentDockSiteInfo(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CRecentDockSiteInfo::~CRecentDockSiteInfo(CRecentDockSiteInfo *this)
{
  this->__vftable = (CRecentDockSiteInfo_vtbl *)&CRecentDockSiteInfo::`vftable';
  CRecentPaneContainerInfo::~CRecentPaneContainerInfo(this: &this->m_recentMiniFrameInfo);
  CRecentPaneContainerInfo::~CRecentPaneContainerInfo(this: &this->m_recentSliderInfo);
}

//------------------------------------------------------------------------------
// Address: 0x1041F0A2
// Name: public: virtual void CRecentDockSiteInfo::StoreDockInfo(class CPaneContainer __near *,class CDockablePane __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CRecentDockSiteInfo::StoreDockInfo(
        CRecentDockSiteInfo *this,
        CPaneContainer *pRecentContainer,
        CDockablePane *pTabbedBar)
{
  CObject *v4; // eax
  CDockablePane *v5; // ecx
  CDockablePane *v6; // ebx
  CWnd *v7; // edi
  CWnd *v8; // eax
  CWnd *v9; // eax
  CRecentPaneContainerInfo_vtbl *v10; // edx
  CPaneFrameWnd *pRecentMiniFrame; // [esp+Ch] [ebp-4h]
  CPaneFrameWnd *pRecentMiniFramea; // [esp+Ch] [ebp-4h]

  v4 = AfxDynamicDownCast(pClass: &CDockablePane::classCDockablePane, pObject: this->m_pBar);
  v5 = pTabbedBar;
  v6 = (CDockablePane *)v4;
  if ( pTabbedBar == nullptr )
    v5 = (CDockablePane *)v4;
  pRecentMiniFrame = (CPaneFrameWnd *)CDockablePane::GetDefaultPaneDivider(this: v5);
  v7 = v6->GetParentMiniFrame(this: &v6->CPane, a2: 0);
  if ( v7 != nullptr )
  {
    v8 = CWnd::FromHandlePermanent(hWnd: this->m_hRecentMiniFrame);
    pRecentMiniFramea = (CPaneFrameWnd *)AfxDynamicDownCast(pClass: &CPaneFrameWnd::classCPaneFrameWnd, pObject: v8);
    this->m_hRecentMiniFrame = v7->m_hWnd;
    this->m_recentMiniFrameInfo.StoreDockInfo(
      this: &this->m_recentMiniFrameInfo,
      a2: pRecentContainer,
      a3: v6,
      a4: pTabbedBar);
    CWnd::ScreenToClient(this: v7, lpRect: &this->m_recentMiniFrameInfo.m_rectDockedRect);
    GetWindowRect(hWnd: v7->m_hWnd, lpRect: &this->m_rectRecentFloatingRect);
    if ( pRecentMiniFramea != nullptr )
      PostMessageA(hWnd: pRecentMiniFramea->m_hWnd, Msg: AFX_WM_CHECKEMPTYMINIFRAME, wParam: 0, lParam: 0);
  }
  else if ( pRecentMiniFrame != nullptr )
  {
    ((void (__thiscall *)(CRecentPaneContainerInfo *, CPaneContainer *, CDockablePane *))this->m_recentSliderInfo.StoreDockInfo)(
      a1: &this->m_recentSliderInfo,
      a2: pRecentContainer,
      a3: v6);
    v9 = (CWnd *)((int (__thiscall *)(CDockablePane *, CRect *))v6->GetDockSiteFrameWnd)(
                   a1: v6,
                   a2: &this->m_recentSliderInfo.m_rectDockedRect);
    CWnd::ScreenToClient(this: v9, lpRect: (tagRECT *)pTabbedBar);
    this->m_hRecentDefaultSlider = pRecentMiniFrame->m_hWnd;
    this->m_dwRecentAlignmentToFrame = ((int (__thiscall *)(CPaneFrameWnd *))pRecentMiniFrame->OnMovePane)(a1: pRecentMiniFrame);
  }
  else
  {
    v10 = this->m_recentMiniFrameInfo.__vftable;
    this->m_hRecentMiniFrame = nullptr;
    ((void (__stdcall *)(_DWORD, CDockablePane *, _DWORD))v10->StoreDockInfo)(a1: 0, a2: v6, a3: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041F1DE
// Name: public: void CList<struct HWND__ __near *,struct HWND__ __near *>::AddTail(class CList<struct HWND__ __near *,struct HWND__ __near *> __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CList<HWND__ *,HWND__ *>::AddTail(
        CList<unsigned long,unsigned long> *this,
        CList<unsigned long,unsigned long> *pNewList)
{
  CList<unsigned long,unsigned long>::CNode *m_pNodeHead; // esi
  CFrameWnd *data; // [esp-4h] [ebp-Ch]

  if ( pNewList == nullptr )
    AfxThrowInvalidArgException();
  m_pNodeHead = pNewList->m_pNodeHead;
  while ( m_pNodeHead != nullptr )
  {
    data = (CFrameWnd *)m_pNodeHead->data;
    m_pNodeHead = m_pNodeHead->pNext;
    CList<CFrameWnd *,CFrameWnd *>::AddTail((CList<CFrameWnd *,CFrameWnd *> *)this, newElement: data);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041F20E
// Name: public: virtual void CRecentPaneContainerInfo::SetInfo(class CRecentPaneContainerInfo __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CRecentPaneContainerInfo::SetInfo(CRecentPaneContainerInfo *this, CRecentPaneContainerInfo *srcInfo)
{
  CPaneContainer *m_pRecentBarContainer; // ecx
  CPaneContainer *v4; // ecx
  CPaneContainer *m_pRecentContainerOfTabWnd; // ecx
  CPaneContainer *v6; // ecx

  m_pRecentBarContainer = srcInfo->m_pRecentBarContainer;
  if ( m_pRecentBarContainer != nullptr )
    CPaneContainer::AddRef(this: m_pRecentBarContainer);
  v4 = this->m_pRecentBarContainer;
  if ( v4 != nullptr )
    CPaneContainer::Release(this: v4);
  this->m_pRecentBarContainer = srcInfo->m_pRecentBarContainer;
  this->m_rectDockedRect = srcInfo->m_rectDockedRect;
  this->m_nRecentPercent = srcInfo->m_nRecentPercent;
  m_pRecentContainerOfTabWnd = srcInfo->m_pRecentContainerOfTabWnd;
  if ( m_pRecentContainerOfTabWnd != nullptr )
    CPaneContainer::AddRef(this: m_pRecentContainerOfTabWnd);
  v6 = this->m_pRecentContainerOfTabWnd;
  if ( v6 != nullptr )
    CPaneContainer::Release(this: v6);
  this->m_pRecentContainerOfTabWnd = srcInfo->m_pRecentContainerOfTabWnd;
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&this->m_lstRecentListOfBars);
  CList<HWND__ *,HWND__ *>::AddTail(
    this: (CList<unsigned long,unsigned long> *)&this->m_lstRecentListOfBars,
    pNewList: (CList<unsigned long,unsigned long> *)&srcInfo->m_lstRecentListOfBars);
}

//------------------------------------------------------------------------------
// Address: 0x1041F285
// Name: public: void CRecentDockSiteInfo::SaveListOfRecentPanes(class CList<struct HWND__ __near *,struct HWND__ __near *> __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CRecentDockSiteInfo::SaveListOfRecentPanes(
        CRecentDockSiteInfo *this,
        CList<HWND__ *,HWND__ *> *lstOrg,
        int bForSlider)
{
  CList<HWND__ *,HWND__ * &> *p_m_lstRecentListOfBars; // esi

  p_m_lstRecentListOfBars = (CList<HWND__ *,HWND__ * &> *)&this->m_recentSliderInfo.m_lstRecentListOfBars;
  if ( bForSlider == 0 )
    p_m_lstRecentListOfBars = (CList<HWND__ *,HWND__ * &> *)&this->m_recentMiniFrameInfo.m_lstRecentListOfBars;
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: p_m_lstRecentListOfBars);
  CList<HWND__ *,HWND__ *>::AddTail(
    this: (CList<unsigned long,unsigned long> *)p_m_lstRecentListOfBars,
    pNewList: (CList<unsigned long,unsigned long> *)lstOrg);
}

//------------------------------------------------------------------------------
// Address: 0x1041F2B0
// Name: public: class CRecentPaneContainerInfo __near & CRecentPaneContainerInfo::operator=(class CRecentPaneContainerInfo __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRecentPaneContainerInfo *__thiscall CRecentPaneContainerInfo::operator=(
        CRecentPaneContainerInfo *this,
        CRecentPaneContainerInfo *src)
{
  this->m_pRecentBarContainer = src->m_pRecentBarContainer;
  this->m_rectDockedRect = src->m_rectDockedRect;
  this->m_nRecentPercent = src->m_nRecentPercent;
  this->m_bIsRecentLeftBar = src->m_bIsRecentLeftBar;
  this->m_pRecentContainerOfTabWnd = src->m_pRecentContainerOfTabWnd;
  CList<HWND__ *,HWND__ * &>::RemoveAll(this: (CList<HWND__ *,HWND__ * &> *)&this->m_lstRecentListOfBars);
  CList<HWND__ *,HWND__ *>::AddTail(
    this: (CList<unsigned long,unsigned long> *)&this->m_lstRecentListOfBars,
    pNewList: (CList<unsigned long,unsigned long> *)&src->m_lstRecentListOfBars);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1041F2FF
// Name: public: class CRecentDockSiteInfo __near & CRecentDockSiteInfo::operator=(class CRecentDockSiteInfo __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRecentDockSiteInfo *__thiscall CRecentDockSiteInfo::operator=(CRecentDockSiteInfo *this, CRecentDockSiteInfo *src)
{
  this->m_rectRecentFloatingRect = src->m_rectRecentFloatingRect;
  this->m_dwRecentAlignmentToFrame = src->m_dwRecentAlignmentToFrame;
  this->m_nRecentRowIndex = src->m_nRecentRowIndex;
  this->m_pRecentDockBar = src->m_pRecentDockBar;
  this->m_pRecentDockBarRow = src->m_pRecentDockBarRow;
  this->m_nRecentTabNumber = src->m_nRecentTabNumber;
  this->m_hRecentDefaultSlider = src->m_hRecentDefaultSlider;
  this->m_hRecentMiniFrame = src->m_hRecentMiniFrame;
  CRecentPaneContainerInfo::operator=(this: &this->m_recentSliderInfo, src: &src->m_recentSliderInfo);
  CRecentPaneContainerInfo::operator=(this: &this->m_recentMiniFrameInfo, src: &src->m_recentMiniFrameInfo);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1041F364
// Name: public: virtual struct CRuntimeClass __near * CDockablePaneAdapter::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CDockablePaneAdapter::GetRuntimeClass(CDockablePaneAdapter *this)
{
  return &CDockablePaneAdapter::classCDockablePaneAdapter;
}

//------------------------------------------------------------------------------
// Address: 0x1041F36A
// Name: public: CDockablePaneAdapter::CDockablePaneAdapter(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDockablePaneAdapter *__thiscall CDockablePaneAdapter::CDockablePaneAdapter(CDockablePaneAdapter *this)
{
  CDockablePane::CDockablePane(this);
  this->__vftable = (CDockablePaneAdapter_vtbl *)&CDockablePaneAdapter::`vftable';
  this->m_rectInitial.left = 0;
  this->m_rectInitial.top = 0;
  this->m_rectInitial.right = 0;
  this->m_rectInitial.bottom = 0;
  this->m_pWnd = nullptr;
  this->m_dwEnabledAlignmentInitial = 61440;
  SetRect(lprc: &this->m_rectInitial, xLeft: 30, yTop: 30, xRight: 180, yBottom: 180);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1041F3B3
// Name: public: virtual class CWnd __near * CDockablePaneAdapter::GetWrappedWnd(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CWnd *__thiscall CDockablePaneAdapter::GetWrappedWnd(CDockablePaneAdapter *this)
{
  return this->m_pWnd;
}

//------------------------------------------------------------------------------
// Address: 0x1041F3BA
// Name: public: virtual CDockablePaneAdapter::~CDockablePaneAdapter(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockablePaneAdapter::~CDockablePaneAdapter(CDockablePaneAdapter *this)
{
  this->__vftable = (CDockablePaneAdapter_vtbl *)&CDockablePaneAdapter::`vftable';
  CDockablePane::~CDockablePane(this);
}

//------------------------------------------------------------------------------
// Address: 0x1041F3C5
// Name: protected: void CDockablePaneAdapter::OnSize(unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockablePaneAdapter::OnSize(CDockablePaneAdapter *this, unsigned int nType, int cx, int cy)
{
  CWnd *m_pWnd; // ecx

  CBasePane::OnSize(this, nType, cx, cy);
  m_pWnd = this->m_pWnd;
  if ( m_pWnd != nullptr )
    CWnd::SetWindowPos(this: m_pWnd, pWndInsertAfter: nullptr, x: 0, y: 0, cx, cy, nFlags: 0x14u);
}

//------------------------------------------------------------------------------
// Address: 0x1041F3FC
// Name: public: static class CObject __near * CDockablePaneAdapter::CreateObject(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDockablePaneAdapter *__stdcall CDockablePaneAdapter::CreateObject()
{
  CDockablePaneAdapter *v0; // ecx
  CDockablePaneAdapter *result; // eax

  v0 = (CDockablePaneAdapter *)operator new(nSize: 0x368u);
  result = nullptr;
  if ( v0 != nullptr )
    return CDockablePaneAdapter::CDockablePaneAdapter(this: v0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041F453
// Name: public: virtual int CDockablePaneAdapter::SetWrappedWnd(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockablePaneAdapter::SetWrappedWnd(CDockablePaneAdapter *this, CWnd *pWnd)
{
  CDockablePaneAdapter_vtbl *v3; // ebx
  const AFX_CONNECTIONMAP *v4; // eax
  int v5; // eax
  CDockablePaneAdapter_vtbl *v6; // ebx
  int v7; // eax
  CRect *p_m_rectSavedDockedRect; // edi

  CWnd::SetParent(this: pWnd, pWndNewParent: this);
  this->m_pWnd = pWnd;
  if ( CObject::IsKindOf(this: pWnd, pClass: &CBasePane::classCBasePane) != 0 )
  {
    v3 = this->__vftable;
    v4 = pWnd->__vftable[1].GetConnectionMap(this: pWnd);
    v3->EnableDocking(this, a2: (unsigned int)v4);
    v5 = ((int (__thiscall *)(CWnd *))pWnd->__vftable[1].GetExtraConnectionPoints)(a1: pWnd);
    v6 = this->__vftable;
    this->m_bRecentVisibleState = v5;
    v7 = ((int (__thiscall *)(CWnd *))pWnd->__vftable[1].GetConnectionHook)(a1: pWnd);
    v6->SetRestoredFromRegistry(this, a2: v7);
    if ( CObject::IsKindOf(this: pWnd, pClass: &CPane::classCPane) != 0 )
    {
      p_m_rectSavedDockedRect = &this->m_rectSavedDockedRect;
      p_m_rectSavedDockedRect->left = pWnd[5].m_ulGestureArg;
      p_m_rectSavedDockedRect = (CRect *)((char *)p_m_rectSavedDockedRect + 4);
      p_m_rectSavedDockedRect->left = HIDWORD(pWnd[5].m_ulGestureArg);
      p_m_rectSavedDockedRect = (CRect *)((char *)p_m_rectSavedDockedRect + 4);
      p_m_rectSavedDockedRect->left = pWnd[5].m_bGestureInited;
      p_m_rectSavedDockedRect->top = (int)pWnd[5].m_pCurrentGestureInfo;
    }
  }
  else
  {
    this->EnableDocking(this, a2: this->m_dwEnabledAlignmentInitial);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1041F4F1
// Name: protected: virtual struct AFX_MSGMAP const __near * CDockablePaneAdapter::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CDockablePaneAdapter::GetMessageMap(CDockablePaneAdapter *this)
{
  return &messageMap_49;
}

//------------------------------------------------------------------------------
// Address: 0x1041F4F7
// Name: public: virtual int CDockablePaneAdapter::SaveState(char const __near *,int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockablePaneAdapter::SaveState(
        CDockablePaneAdapter *this,
        const char *lpszProfileName,
        int nIndex,
        unsigned int uiID)
{
  CAfxStringMgr *StringManager; // eax
  CSettingsStore *v6; // esi
  CAfxStringMgr *v7; // eax
  int v8; // esi
  CSettingsStoreSP regSP; // [esp+10h] [ebp-20h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strProfileName; // [esp+18h] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strName; // [esp+1Ch] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strSection; // [esp+20h] [ebp-10h] BYREF
  int v14; // [esp+2Ch] [ebp-4h]

  AFXGetRegPath(result: &strProfileName, lpszPostFix: strControlBarProfile_0.m_pszData, lpszProfileName);
  v14 = 0;
  if ( nIndex == -1 )
    nIndex = CWnd::GetDlgCtrlID(this);
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strSection, pStringMgr: StringManager);
  LOBYTE(v14) = 1;
  if ( uiID == -1 )
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: &strSection,
      pszFormat: "%sDockablePaneAdapter-%d",
      strProfileName.m_pszData,
      nIndex);
  else
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: &strSection,
      pszFormat: "%sDockablePaneAdapter-%d%x",
      strProfileName.m_pszData,
      nIndex,
      uiID);
  regSP.m_pRegistry = nullptr;
  regSP.m_dwUserData = 0;
  LOBYTE(v14) = 2;
  v6 = CSettingsStoreSP::Create(this: &regSP, bAdmin: 0, bReadOnly: 0);
  if ( v6->CreateKey(this: v6, a2: strSection.m_pszData) != 0 )
  {
    v7 = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strName, pStringMgr: v7);
    LOBYTE(v14) = 3;
    CWnd::GetWindowTextA(this, rString: &strName);
    v6->Write_5(this: v6, a2: "BarName", a3: strName.m_pszData);
    LOBYTE(v14) = 2;
    ATL::CStringData::Release(this: (ATL::CStringData *)strName.m_pszData - 1);
  }
  v8 = CDockablePane::SaveState(this, lpszProfileName, nIndex, uiID);
  LOBYTE(v14) = 1;
  if ( regSP.m_pRegistry != nullptr )
    ((void (__thiscall *)(CSettingsStore *, int))regSP.m_pRegistry->dtr_CObject)(a1: regSP.m_pRegistry, a2: 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)strSection.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)strProfileName.m_pszData - 1);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x1041F61A
// Name: public: virtual int CDockablePaneAdapter::LoadState(char const __near *,int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall CDockablePaneAdapter::LoadState(
        CDockablePaneAdapter *this,
        const char *lpszProfileName,
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > nIndex,
        unsigned int uiID)
{
  int m_pszData; // edi
  CAfxStringMgr *StringManager; // eax
  CSettingsStore *v7; // esi
  int State; // esi
  CAfxStringMgr *v10; // eax
  CSettingsStore_vtbl *v11; // eax
  CSettingsStoreSP regSP; // [esp+10h] [ebp-1Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strName; // [esp+18h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strProfileName; // [esp+1Ch] [ebp-10h] BYREF
  int v15; // [esp+28h] [ebp-4h]

  AFXGetRegPath(result: &strProfileName, lpszPostFix: strControlBarProfile_0.m_pszData, lpszProfileName);
  m_pszData = (int)nIndex.m_pszData;
  v15 = 0;
  if ( nIndex.m_pszData == (char *)-1 )
    m_pszData = CWnd::GetDlgCtrlID(this);
  StringManager = AfxGetStringManager();
  ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &nIndex, pStringMgr: StringManager);
  LOBYTE(v15) = 1;
  if ( uiID == -1 )
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: &nIndex,
      pszFormat: "%sDockablePaneAdapter-%d",
      strProfileName.m_pszData,
      m_pszData);
  else
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::Format(
      this: &nIndex,
      pszFormat: "%sDockablePaneAdapter-%d%x",
      strProfileName.m_pszData,
      m_pszData,
      uiID);
  regSP.m_pRegistry = nullptr;
  regSP.m_dwUserData = 0;
  LOBYTE(v15) = 2;
  v7 = CSettingsStoreSP::Create(this: &regSP, bAdmin: 0, bReadOnly: 0);
  if ( ((int (__thiscall *)(CSettingsStore *, ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > >))v7->Open)(
         a1: v7,
         a2: nIndex) != 0 )
  {
    v10 = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(this: &strName, pStringMgr: v10);
    v11 = v7->__vftable;
    LOBYTE(v15) = 3;
    v11->Read_5(this: v7, a2: "BarName", a3: &strName);
    if ( *((_DWORD *)strName.m_pszData - 3) != 0 )
      CWnd::SetWindowTextA(this, lpszString: strName.m_pszData);
    State = CDockablePane::LoadState(this, lpszProfileName, nIndex: m_pszData, uiID);
    ATL::CStringData::Release(this: (ATL::CStringData *)strName.m_pszData - 1);
    LOBYTE(v15) = 1;
    if ( regSP.m_pRegistry != nullptr )
      ((void (__thiscall *)(CSettingsStore *, int))regSP.m_pRegistry->dtr_CObject)(a1: regSP.m_pRegistry, a2: 1);
  }
  else
  {
    LOBYTE(v15) = 1;
    if ( regSP.m_pRegistry != nullptr )
      ((void (__thiscall *)(CSettingsStore *, int))regSP.m_pRegistry->dtr_CObject)(a1: regSP.m_pRegistry, a2: 1);
    State = 0;
  }
  ATL::CStringData::Release(this: (ATL::CStringData *)nIndex.m_pszData - 1);
  ATL::CStringData::Release(this: (ATL::CStringData *)strProfileName.m_pszData - 1);
  return State;
}

//------------------------------------------------------------------------------
// Address: 0x1041F754
// Name: public: virtual struct CRuntimeClass __near * CMFCToolTipCtrl::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CMFCToolTipCtrl::GetRuntimeClass(CMFCToolTipCtrl *this)
{
  return &CMFCToolTipCtrl::classCMFCToolTipCtrl;
}

//------------------------------------------------------------------------------
// Address: 0x1041F75A
// Name: public: virtual class CSize CMFCToolTipCtrl::GetIconSize(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSize *__thiscall CMFCToolTipCtrl::GetIconSize(CMFCToolTipCtrl *this, CSize *result)
{
  CMFCRibbonButton *m_pRibbonButton; // ecx
  int v4; // edi
  CMFCRibbonButton *v5; // ecx
  CSize *v6; // eax
  int v7; // edx
  int v8; // ebx
  int *v9; // eax
  CMFCRibbonButton *v10; // ecx
  int v11; // edx
  int *v12; // eax
  CMFCToolBarButton *m_pHotButton; // eax
  CMFCToolBarImages *m_pToolBarImages; // esi
  int m_iUserImage; // eax
  int cx; // ecx
  int cy; // esi
  BOOL v18; // [esp-4h] [ebp-18h]
  CSize v19; // [esp+Ch] [ebp-8h] BYREF

  m_pRibbonButton = this->m_pRibbonButton;
  v4 = 0;
  if ( m_pRibbonButton != nullptr )
  {
    if ( m_pRibbonButton->IsDrawTooltipImage(this: m_pRibbonButton) != 0 )
    {
      v5 = this->m_pRibbonButton;
      if ( v5->m_hIcon != nullptr )
      {
        v18 = v5->m_bIsLargeImage == 0;
        this->m_nRibbonImageType = v18;
        v5->GetImageSize(this: v5, result, a3: (CMFCRibbonBaseElement::RibbonImageType)v18);
        return result;
      }
      v7 = 0;
      v8 = 0;
      if ( v5->m_bIsLargeImage != 0 && v5->m_nLargeImageIndex >= 0 )
      {
        v9 = (int *)v5->GetImageSize(this: v5, result: &v19, a3: RibbonImageLarge);
        v7 = *v9;
        v8 = v9[1];
      }
      if ( v7 != 0 || v8 != 0 )
      {
        this->m_nRibbonImageType = 0;
        result->cx = v7;
        result->cy = v8;
        return result;
      }
      v10 = this->m_pRibbonButton;
      v11 = 0;
      if ( v10->m_nSmallImageIndex >= 0 )
      {
        v12 = (int *)v10->GetImageSize(this: v10, result: &v19, a3: RibbonImageSmall);
        v11 = *v12;
        v4 = v12[1];
      }
      v6 = result;
      this->m_nRibbonImageType = 1;
      result->cx = v11;
      goto LABEL_25;
    }
LABEL_24:
    v6 = result;
    result->cx = 0;
LABEL_25:
    v6->cy = v4;
    return v6;
  }
  m_pHotButton = this->m_pHotButton;
  if ( m_pHotButton == nullptr )
    goto LABEL_24;
  m_pToolBarImages = this->m_pToolBarImages;
  if ( m_pToolBarImages == nullptr || m_pToolBarImages->m_iCount == 0 )
    goto LABEL_24;
  if ( m_pHotButton->m_bUserButton != 0 )
    m_iUserImage = m_pHotButton->m_iUserImage;
  else
    m_iUserImage = m_pHotButton->m_iImage;
  if ( m_iUserImage < 0 )
  {
    cx = 0;
    cy = 0;
  }
  else
  {
    cx = m_pToolBarImages->m_sizeImage.cx;
    cy = m_pToolBarImages->m_sizeImage.cy;
  }
  result->cx = cx;
  result->cy = cy;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041F86F
// Name: public: virtual void CMFCToolTipCtrl::OnDrawBorder(class CDC __near *,class CRect,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CMFCToolTipCtrl::OnDrawBorder(CMFCToolTipCtrl *this, CDC *pDC, CRect rect, COLORREF clrLine)
{
  CPoint result; // [esp+4h] [ebp-8h] BYREF

  if ( this->m_Params.m_bRoundedCorners != 0 )
  {
    CDC::MoveTo(this: pDC, &result, x: rect.left + 2, y: rect.top);
    CDC::LineTo(this: pDC, x: rect.right - 3, y: rect.top);
    CDC::LineTo(this: pDC, x: rect.right - 1, y: rect.top + 2);
    CDC::LineTo(this: pDC, x: rect.right - 1, y: rect.bottom - 3);
    CDC::LineTo(this: pDC, x: rect.right - 3, y: rect.bottom - 1);
    CDC::LineTo(this: pDC, x: rect.left + 2, y: rect.bottom - 1);
    CDC::LineTo(this: pDC, x: rect.left, y: rect.bottom - 3);
    CDC::LineTo(this: pDC, x: rect.left, y: rect.top + 2);
    CDC::LineTo(this: pDC, x: rect.left + 2, y: rect.top);
  }
  else
  {
    CDC::Draw3dRect(this: pDC, lpRect: &rect, clrTopLeft: clrLine, clrBottomRight: clrLine);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1042840E
// Name: public: void CSmartDockingHighlighterWnd::ShowAt(class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSmartDockingHighlighterWnd::ShowAt(CSmartDockingHighlighterWnd *this, CRect rect)
{
  HWND__ *m_hWnd; // [esp-14h] [ebp-1Ch]

  if ( this->m_bTabbed != 0 || !EqualRect(lprc1: &this->m_rectLast, lprc2: &rect) )
  {
    CSmartDockingHighlighterWnd::Hide(this);
    if ( this->m_bTabbed != 0 )
    {
      SetWindowRgn(hWnd: this->m_hWnd, hRgn: nullptr, bRedraw: false);
      this->m_bTabbed = 0;
    }
    CWnd::SetWindowPos(
      this,
      pWndInsertAfter: &CWnd::wndTop,
      x: rect.left,
      y: rect.top,
      cx: rect.right - rect.left,
      cy: rect.bottom - rect.top,
      nFlags: 0x58u);
    this->m_rectLast.left = rect.left;
    this->m_rectLast.top = rect.top;
    this->m_rectLast.right = rect.right;
    m_hWnd = this->m_hWnd;
    this->m_rectLast.bottom = rect.bottom;
    this->m_bShown = 1;
    RedrawWindow(hWnd: m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104284A3
// Name: public: void CSmartDockingHighlighterWnd::ShowTabbedAt(class CRect,class CRect)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSmartDockingHighlighterWnd::ShowTabbedAt(CSmartDockingHighlighterWnd *this, CRect rect, CRect rectTab)
{
  HRGN RectRgn; // eax
  HRGN v5; // eax
  int v6; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-3Ch]
  int v8; // [esp-8h] [ebp-34h]
  CRgn rgnTab; // [esp+10h] [ebp-1Ch] BYREF
  CRgn rgnMain; // [esp+18h] [ebp-14h] BYREF
  int v11; // [esp+28h] [ebp-4h]

  if ( this->m_bTabbed == 0
    || !EqualRect(lprc1: &this->m_rectLast, lprc2: &rect)
    || !EqualRect(lprc1: &this->m_rectTab, lprc2: &rectTab) )
  {
    CSmartDockingHighlighterWnd::Hide(this);
    rgnMain.m_hObject = nullptr;
    rgnMain.__vftable = (CRgn_vtbl *)&CRgn::`vftable';
    v11 = 0;
    if ( CTabbedPane::m_bTabsAlwaysTop != 0 )
      RectRgn = CreateRectRgn(
                  x1: 0,
                  y1: rectTab.bottom - rectTab.top,
                  x2: rect.right - rect.left,
                  y2: rectTab.bottom - rectTab.top + rect.bottom - rect.top);
    else
      RectRgn = CreateRectRgn(x1: 0, y1: 0, x2: rect.right - rect.left, y2: rect.bottom - rect.top);
    CGdiObject::Attach(this: &rgnMain, hObject: RectRgn);
    rgnTab.m_hObject = nullptr;
    rgnTab.__vftable = (CRgn_vtbl *)&CRgn::`vftable';
    LOBYTE(v11) = 1;
    if ( CTabbedPane::m_bTabsAlwaysTop != 0 )
      v5 = CreateRectRgn(x1: rectTab.left, y1: 0, x2: rectTab.right - rectTab.left, y2: rectTab.bottom - rectTab.top);
    else
      v5 = CreateRectRgnIndirect(lprect: &rectTab);
    CGdiObject::Attach(this: &rgnTab, hObject: v5);
    CRgn::CombineRgn(this: &rgnMain, pRgn1: &rgnMain, pRgn2: &rgnTab, nCombineMode: 2);
    SetWindowRgn(hWnd: this->m_hWnd, hRgn: (HRGN)rgnMain.m_hObject, bRedraw: false);
    this->m_rectLast = rect;
    v6 = rect.right - rect.left;
    this->m_rectTab = rectTab;
    this->m_bTabbed = 1;
    v8 = rect.bottom + this->m_rectTab.bottom - this->m_rectTab.top - rect.top;
    if ( CTabbedPane::m_bTabsAlwaysTop != 0 )
      CWnd::SetWindowPos(
        this,
        pWndInsertAfter: &CWnd::wndTop,
        x: rect.left,
        y: rectTab.top,
        cx: v6,
        cy: v8,
        nFlags: 0x58u);
    else
      CWnd::SetWindowPos(this, pWndInsertAfter: &CWnd::wndTop, x: rect.left, y: rect.top, cx: v6, cy: v8, nFlags: 0x58u);
    m_hWnd = this->m_hWnd;
    this->m_bShown = 1;
    RedrawWindow(hWnd: m_hWnd, lprcUpdate: nullptr, hrgnUpdate: nullptr, flags: 0x105u);
    LOBYTE(v11) = 0;
    rgnTab.__vftable = (CRgn_vtbl *)&CRgn::`vftable';
    CGdiObject::~CGdiObject(this: &rgnTab);
    v11 = -1;
    rgnMain.__vftable = (CRgn_vtbl *)&CRgn::`vftable';
    CGdiObject::~CGdiObject(this: &rgnMain);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10428639
// Name: protected: void CSmartDockingHighlighterWnd::OnPaint(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSmartDockingHighlighterWnd::OnPaint(CSmartDockingHighlighterWnd *this)
{
  unsigned int clrActiveCaption; // eax
  COLORREF v3; // eax
  CBrush *v4; // ecx
  COLORREF v5; // eax
  CFont *v6; // eax
  char m_hObject; // bl
  CFont *v8; // esi
  HWND__ *m_hWnd; // [esp-8h] [ebp-9Ch]
  CBrush v10; // [esp+10h] [ebp-84h] BYREF
  CBrush v11; // [esp+18h] [ebp-7Ch] BYREF
  CPaintDC v12; // [esp+20h] [ebp-74h] BYREF
  tagRECT Rect; // [esp+74h] [ebp-20h] BYREF
  int v14; // [esp+90h] [ebp-4h]

  CPaintDC::CPaintDC(this: &v12, pWnd: this);
  v14 = 0;
  if ( this->m_bShown != 0 )
  {
    m_hWnd = this->m_hWnd;
    memset(&Rect, 0, sizeof(Rect));
    GetClientRect(hWnd: m_hWnd, lpRect: &Rect);
    clrActiveCaption = afxGlobalData.clrActiveCaption;
    if ( this->m_bUseThemeColorInShading == 0 )
      clrActiveCaption = 12478255;
    if ( afxGlobalData.m_nBitsPerPixel <= 8 )
    {
      v11.m_hObject = nullptr;
      v5 = CDrawingManager::PixelAlpha(
             srcPixel: (unsigned __int8)(-1 - clrActiveCaption)
           | (((unsigned __int8)(-1 - BYTE1(clrActiveCaption)) | ((unsigned __int8)(-1 - BYTE2(clrActiveCaption)) << 8)) << 8),
             percent: 50);
      CBrush::CBrush(this: &v10, crColor: v5);
      LOBYTE(v14) = 1;
      v6 = CDC::SelectObject(this: &v12, pFont: (CFont *)&v10);
      m_hObject = (char)v11.m_hObject;
      v8 = v6;
      PatBlt(
        hdc: v12.m_hDC,
        x: (int)v11.m_hObject,
        y: (int)v11.m_hObject,
        w: Rect.right - Rect.left,
        h: Rect.bottom - Rect.top,
        rop: 0x5A0049u);
      CDC::SelectObject(this: &v12, pFont: v8);
      LOBYTE(v14) = m_hObject;
      v10.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
      v4 = &v10;
    }
    else
    {
      v3 = CDrawingManager::PixelAlpha(srcPixel: clrActiveCaption, percent: 105);
      CBrush::CBrush(this: &v11, crColor: v3);
      FillRect(hDC: v12.m_hDC, lprc: &Rect, hbr: (HBRUSH)v11.m_hObject);
      v11.__vftable = (CBrush_vtbl *)&CBrush::`vftable';
      v4 = &v11;
    }
    CGdiObject::~CGdiObject(this: v4);
  }
  v14 = -1;
  CPaintDC::~CPaintDC(this: &v12);
}

//------------------------------------------------------------------------------
// Address: 0x10428771
// Name: char const __near * GetSmartDockingWndClassName<0>(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl GetSmartDockingWndClassName<0>()
{
  CAfxStringMgr *StringManager; // eax
  const char *v1; // eax

  if ( (`GetSmartDockingWndClassName<0>'::`2'::`local static guard' & 1) == 0 )
  {
    `GetSmartDockingWndClassName<0>'::`2'::`local static guard' |= 1u;
    StringManager = AfxGetStringManager();
    ATL::CSimpleStringT<char,0>::CSimpleStringT<char,0>(
      this: &`GetSmartDockingWndClassName<0>'::`2'::strSDWndClassName,
      pStringMgr: StringManager);
    atexit(func: GetSmartDockingWndClassName_0__::_2_::_dynamic_atexit_destructor_for__strSDWndClassName__);
  }
  if ( *((_DWORD *)`GetSmartDockingWndClassName<0>'::`2'::strSDWndClassName.m_pszData - 3) == 0 )
  {
    v1 = AfxRegisterWndClass(nClassStyle: 0, hCursor: nullptr, hbrBackground: nullptr, hIcon: nullptr);
    ATL::CSimpleStringT<char,0>::SetString(this: &`GetSmartDockingWndClassName<0>'::`2'::strSDWndClassName, pszSrc: v1);
  }
  return `GetSmartDockingWndClassName<0>'::`2'::strSDWndClassName.m_pszData;
}

//------------------------------------------------------------------------------
// Address: 0x104287C4
// Name: public: void CSmartDockingHighlighterWnd::Create(class CWnd __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSmartDockingHighlighterWnd::Create(CSmartDockingHighlighterWnd *this, CWnd *pwndOwner)
{
  CSmartDockingHighlighterWnd_vtbl *v3; // edi
  char *SmartDockingWndClass; // eax
  unsigned int dwExStyle; // [esp+Ch] [ebp-18h]
  CRect rect; // [esp+10h] [ebp-14h] BYREF

  this->m_pWndOwner = pwndOwner;
  memset(&rect, 0, sizeof(rect));
  SetRectEmpty(lprc: &rect);
  dwExStyle = 0x80000;
  if ( afxGlobalData.m_nBitsPerPixel <= 8 )
    dwExStyle = 0;
  v3 = this->__vftable;
  SmartDockingWndClass = GetSmartDockingWndClassName<0>();
  v3->CreateEx(
    this,
    a2: dwExStyle,
    a3: SmartDockingWndClass,
    a4: &var,
    a5: 0x80000000,
    a6: &rect,
    a7: pwndOwner,
    a8: 0,
    a9: nullptr);
  if ( dwExStyle == 0x80000 )
    SetLayeredWindowAttributes(hwnd: this->m_hWnd, crKey: 0, bAlpha: 0x64u, dwFlags: 2u);
  this->m_bUseThemeColorInShading = CDockingManager::m_SDParams.m_bUseThemeColorInShading;
}

//------------------------------------------------------------------------------
// Address: 0x10428863
// Name: protected: virtual struct AFX_MSGMAP const __near * CSmartDockingHighlighterWnd::GetMessageMap(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CSmartDockingHighlighterWnd::GetMessageMap(CSmartDockingHighlighterWnd *this)
{
  return (const AFX_MSGMAP *)&off_1069301C;
}

//------------------------------------------------------------------------------
// Address: 0x10428869
// Name: public: virtual struct CRuntimeClass __near * CSmartDockingStandaloneGuide::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CSmartDockingStandaloneGuide::GetRuntimeClass(CSmartDockingStandaloneGuide *this)
{
  return &CSmartDockingStandaloneGuide::classCSmartDockingStandaloneGuide;
}

//------------------------------------------------------------------------------
// Address: 0x1042886F
// Name: public: virtual struct CRuntimeClass __near * CSmartDockingGroupGuidesManager::GetRuntimeClass(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CSmartDockingGroupGuidesManager::GetRuntimeClass(CSmartDockingGroupGuidesManager *this)
{
  return &CSmartDockingGroupGuidesManager::classCSmartDockingGroupGuidesManager;
}

//------------------------------------------------------------------------------
// Address: 0x10428875
// Name: GetVMTheme
// Source: linker_block_proximity
//------------------------------------------------------------------------------
AFX_SMARTDOCK_THEME __stdcall GetVMTheme()
{
  AFX_SMARTDOCK_THEME result; // eax
  CMFCVisualManager *Instance; // eax

  if ( CDockingManager::m_SDParams.m_uiMarkerBmpResID[0] != 0 )
    return AFX_SDT_DEFAULT;
  result = CDockingManager::m_SDTheme;
  if ( CDockingManager::m_SDTheme == AFX_SDT_DEFAULT )
  {
    Instance = CMFCVisualManager::GetInstance();
    return Instance->GetSmartDockingTheme(this: Instance);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10428899
// Name: public: virtual void CSmartDockingStandaloneGuide::Destroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSmartDockingStandaloneGuide::Destroy(CSmartDockingStandaloneGuide *this)
{
  if ( IsWindow(hWnd: this->m_wndBmp.m_hWnd) )
    this->m_wndBmp.DestroyWindow(this: &this->m_wndBmp);
}

//------------------------------------------------------------------------------
// Address: 0x104288E3
// Name: public: virtual void CDockSite::OnSizeParent(class CRect __near &,unsigned int,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CDockSite::OnSizeParent(
        CDockSite *this,
        CRect *rectAvailable,
        CRect *nSide,
        unsigned int bExpand,
        int nOffset)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x104288E6
// Name: protected: virtual void CSmartDockingGroupGuide::DestroyImages(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSmartDockingGroupGuide::DestroyImages(CSmartDockingGroupGuide *this)
{
  CGdiObject::DeleteObject(this: &this->m_Rgn);
}

//------------------------------------------------------------------------------
// Address: 0x104288F1
// Name: public: virtual void CSmartDockingGroupGuidesManager::Destroy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSmartDockingGroupGuidesManager::Destroy(CSmartDockingGroupGuidesManager *this)
{
  CSmartDockingGroupGuide *m_arMarkers; // edi
  int i; // ebx

  if ( this->m_bCreated != 0 )
  {
    m_arMarkers = this->m_arMarkers;
    for ( i = 5; i != 0; --i )
    {
      m_arMarkers->DestroyImages(this: m_arMarkers);
      ++m_arMarkers;
    }
    this->m_Wnd.DestroyWindow(this: &this->m_Wnd);
    CGdiObject::DeleteObject(this: &this->m_rgnBase);
    this->m_bCreated = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10428964
// Name: public: CSmartDockingStandaloneGuideWnd::CSmartDockingStandaloneGuideWnd(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSmartDockingStandaloneGuideWnd *__thiscall CSmartDockingStandaloneGuideWnd::CSmartDockingStandaloneGuideWnd(
        CSmartDockingStandaloneGuideWnd *this)
{
  CWnd::CWnd(this);
  this->m_clrFrame = -1;
  this->m_bIsHighlighted = 0;
  this->m_bIsDefaultImage = 0;
  this->m_bIsVert = 0;
  this->__vftable = (CSmartDockingStandaloneGuideWnd_vtbl *)&CSmartDockingStandaloneGuideWnd::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1042898D
// Name: public: virtual CSmartDockingStandaloneGuideWnd::~CSmartDockingStandaloneGuideWnd(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall CSmartDockingStandaloneGuideWnd::~CSmartDockingStandaloneGuideWnd(
        CSmartDockingStandaloneGuideWnd *this)
{
  this->__vftable = (CSmartDockingStandaloneGuideWnd_vtbl *)&CSmartDockingStandaloneGuideWnd::`vftable';
  CWnd::~CWnd(this);
}
