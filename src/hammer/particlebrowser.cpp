// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/particlebrowser.cpp
// Functions: 12
// ============================================================

#include "hammer\particlebrowser.h"

//------------------------------------------------------------------------------
// Address: 0x1007E620
// Name: public: int CParticleBrowser::OnEraseBkgnd(class CDC __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CParticleBrowser::OnEraseBkgnd(CToolHandler_Disabled *this, unsigned int uMsg)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008CEC0
// Name: public: virtual struct CRuntimeClass __near * CParticleBrowser::GetRuntimeClass(void)const
// Source: json
//------------------------------------------------------------------------------
CRuntimeClass *__thiscall CParticleBrowser::GetRuntimeClass(CParticleBrowser *this)
{
  return &CParticleBrowser::classCParticleBrowser;
}

//------------------------------------------------------------------------------
// Address: 0x1008CED0
// Name: public: virtual CParticleBrowser::~CParticleBrowser(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleBrowser::~CParticleBrowser(CParticleBrowser *this)
{
  CParticlePicker *m_pPicker; // ecx
  vgui::TextEntry *m_pStatusLine; // ecx
  vgui::Button *m_pButtonOK; // ecx
  vgui::Button *m_pButtonCancel; // ecx

  this->__vftable = (CParticleBrowser_vtbl *)&CParticleBrowser::`vftable';
  m_pPicker = this->m_pPicker;
  if ( m_pPicker != nullptr )
    ((void (__thiscall *)(CParticlePicker *, int))m_pPicker->dtr_Panel)(a1: m_pPicker, a2: 1);
  m_pStatusLine = this->m_pStatusLine;
  if ( m_pStatusLine != nullptr )
    ((void (__thiscall *)(vgui::TextEntry *, int))m_pStatusLine->dtr_Panel)(a1: m_pStatusLine, a2: 1);
  m_pButtonOK = this->m_pButtonOK;
  if ( m_pButtonOK != nullptr )
    ((void (__thiscall *)(vgui::Button *, int))m_pButtonOK->dtr_Panel)(a1: m_pButtonOK, a2: 1);
  m_pButtonCancel = this->m_pButtonCancel;
  if ( m_pButtonCancel != nullptr )
    ((void (__thiscall *)(vgui::Button *, int))m_pButtonCancel->dtr_Panel)(a1: m_pButtonCancel, a2: 1);
  CVGuiWnd::~CVGuiWnd(this: &this->m_VGuiWindow.CVGuiWnd);
  CWnd::~CWnd(this: &this->m_VGuiWindow);
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x1008CFA0
// Name: public: void CParticleBrowser::SetParticleSysName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleBrowser::SetParticleSysName(CParticleBrowser *this, const char *pParticleSysName)
{
  const char *v3; // eax
  const char *v4; // esi
  char pTempName[256]; // [esp+Ch] [ebp-100h] BYREF

  strcpy(pTempName, pParticleSysName);
  strchr(string: pTempName, chr: 0x2Fu);
  v4 = v3;
  if ( v3 != nullptr )
  {
    v4 = v3 + 1;
    V_FixSlashes(pname: (char *)v3 + 1, separator: 92);
  }
  CParticlePicker::SelectParticleSys(this: this->m_pPicker, pRelativePath: pParticleSysName);
  CBaseAssetPicker::SetInitialSelection(this: this->m_pPicker, pAssetName: v4);
  this->m_pStatusLine->SetText(this: this->m_pStatusLine, a2: pParticleSysName);
}

//------------------------------------------------------------------------------
// Address: 0x1008D020
// Name: public: void CParticleBrowser::GetParticleSysName(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleBrowser::GetParticleSysName(CParticleBrowser *this, char *pParticleName, int length)
{
  CParticlePicker::GetSelectedParticleSysName(this: this->m_pPicker, pBuffer: pParticleName, nMaxLen: length);
  V_FixSlashes(pname: pParticleName, separator: 47);
}

//------------------------------------------------------------------------------
// Address: 0x1008D050
// Name: public: virtual void CParticleBrowserPanel::OnMessage(class KeyValues const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleBrowserPanel::OnMessage(
        CParticleBrowserPanel *this,
        KeyValues *params,
        unsigned int ifromPanel)
{
  const char *Name; // eax
  CParticleBrowser *m_pBrowser; // esi
  char pBuffer[1024]; // [esp+8h] [ebp-400h] BYREF

  vgui::Panel::OnMessage(this, params, ifromPanel);
  Name = KeyValues::GetName(this: params);
  if ( _V_strcmp(s1: Name, s2: "ParticleSystemSelectionChanged") == 0 )
  {
    m_pBrowser = this->m_pBrowser;
    CParticlePicker::GetSelectedParticleSysName(this: m_pBrowser->m_pPicker, pBuffer, nMaxLen: 1024);
    m_pBrowser->m_pStatusLine->SetText(this: m_pBrowser->m_pStatusLine, a2: pBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008D110
// Name: public: CParticleBrowser::CParticleBrowser(class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CParticleBrowser *__thiscall CParticleBrowser::CParticleBrowser(CParticleBrowser *this, CWnd *pParent)
{
  CParticlePicker *v3; // eax
  CParticlePicker *v4; // eax
  vgui::TextEntry *v5; // eax
  vgui::TextEntry *v6; // eax
  vgui::Button *v7; // eax
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax

  CDialog::CDialog(this, nIDTemplate: 0x15Au, pParentWnd: pParent);
  this->__vftable = (CParticleBrowser_vtbl *)&CParticleBrowser::`vftable';
  CWnd::CWnd(this: &this->m_VGuiWindow);
  CVGuiWnd::CVGuiWnd(this: &this->m_VGuiWindow.CVGuiWnd);
  this->m_VGuiWindow.__vftable = (CVGuiPanelWnd_vtbl *)&CVGuiPanelWnd::`vftable'{for `CWnd'};
  this->m_VGuiWindow.__vftable = (CVGuiWnd_vtbl *)&CVGuiPanelWnd::`vftable'{for `CVGuiWnd'};
  v3 = (CParticlePicker *)operator new(nSize: 0x250u);
  if ( v3 != nullptr )
    v4 = CParticlePicker::CParticlePicker(this: v3, pParent: nullptr);
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
// Address: 0x1008D3B0
// Name: public: void CParticleBrowser::SaveLoadSettings(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleBrowser::SaveLoadSettings(CParticleBrowser *this, int bSave)
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
  CParticleBrowser *v14; // [esp+20h] [ebp-14h]
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
    m_pCurrentWinApp->WriteProfileStringA(
      this: m_pCurrentWinApp,
      a2: pszIniSection_0,
      a3: "Position",
      a4: str.m_pszData);
    v6 = m_pCurrentWinApp->__vftable;
    Filter = CBaseAssetPicker::GetFilter(this: v14->m_pPicker);
    v6->WriteProfileStringA(this: m_pCurrentWinApp, a2: pszIniSection_0, a3: "Filter", a4: Filter);
  }
  else
  {
    v8 = (ATL::CStringData *)m_pCurrentWinApp->GetProfileStringA(
                               this: m_pCurrentWinApp,
                               result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&bSave,
                               a3: pszIniSection_0,
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
      CModelBrowser::Resize((CModelBrowser *)this);
    }
    v10 = (ATL::CStringData *)m_pCurrentWinApp->GetProfileStringA(
                                this: m_pCurrentWinApp,
                                result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&v13,
                                a3: pszIniSection_0,
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
// Address: 0x1008D5E0
// Name: public: virtual int CParticleBrowser::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CParticleBrowser::OnInitDialog(CParticleBrowser *this)
{
  int (__thiscall *Create)(struct CVGuiPanelWnd *, const char *, const char *, unsigned int, const tagRECT *, CWnd *, unsigned int, CCreateContext *); // eax
  vgui::EditablePanel *v3; // edi
  CHammerVGui *v4; // eax
  _DWORD v6[5]; // [esp+Ch] [ebp-20h] BYREF
  int v7; // [esp+28h] [ebp-4h]

  CDialog::OnInitDialog(this);
  v6[2] = 100;
  v6[3] = 100;
  Create = this->m_VGuiWindow.Create;
  v6[0] = 0;
  v6[1] = 0;
  Create(
    this: &this->m_VGuiWindow,
    a2: nullptr,
    a3: "ParticleViewer",
    a4: 1342177280u,
    a5: (const tagRECT *)v6,
    a6: this,
    a7: 346u,
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
      panelName: "ParticleBrowerPanel",
      hScheme: v4->m_hHammerScheme);
    v3->__vftable = (vgui::EditablePanel_vtbl *)&CParticleBrowserPanel::`vftable';
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
  CParticleBrowser::SaveLoadSettings(this, bSave: 0);
  this->m_pPicker->Activate(this: this->m_pPicker);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008D7B0
// Name: public: void CParticleBrowser::OnDestroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleBrowser::OnDestroy(CParticleBrowser *this)
{
  CParticleBrowser::SaveLoadSettings(this, bSave: 1);
  CTextureSystem::RebindDefaultCubeMap(this: &g_Textures);
  CWnd::OnDestroy(this);
}

//------------------------------------------------------------------------------
// Address: 0x1008D7D0
// Name: protected: static struct AFX_MSGMAP const __near * CParticleBrowser::GetThisMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__stdcall CParticleBrowser::GetThisMessageMap()
{
  if ( (_S1_7 & 1) == 0 )
  {
    _S1_7 |= 1u;
    messageEntries_45[0].pfn = (void (__thiscall *)(CCmdTarget *))CModelBrowser::OnSize;
    messageEntries_45[1].nMessage = 2;
    messageEntries_45[1].nCode = 0;
    messageEntries_45[1].nID = 0;
    messageEntries_45[1].nLastID = 0;
    messageEntries_45[1].nSig = 19;
    messageEntries_45[1].pfn = (void (__thiscall *)(CCmdTarget *))CParticleBrowser::OnDestroy;
    messageEntries_45[2].nMessage = 20;
    messageEntries_45[2].nCode = 0;
    messageEntries_45[2].nID = 0;
    messageEntries_45[2].nLastID = 0;
    messageEntries_45[2].nSig = 1;
    messageEntries_45[2].pfn = (void (__thiscall *)(CCmdTarget *))CParticleBrowser::OnEraseBkgnd;
    messageEntries_45[3].nMessage = 0;
    messageEntries_45[3].nCode = 0;
    messageEntries_45[3].nID = 0;
    messageEntries_45[3].nLastID = 0;
    messageEntries_45[3].nSig = 0;
    messageEntries_45[3].pfn = nullptr;
  }
  return &messageMap_4;
}

//------------------------------------------------------------------------------
// Address: 0x1008D8A0
// Name: protected: virtual struct AFX_MSGMAP const __near * CParticleBrowser::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
const AFX_MSGMAP *__thiscall CParticleBrowser::GetMessageMap(CParticleBrowser *this)
{
  return CParticleBrowser::GetThisMessageMap();
}
