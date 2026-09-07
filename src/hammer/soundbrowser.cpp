// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/soundbrowser.cpp
// Functions: 44
// ============================================================

#include "hammer\soundbrowser.h"

//------------------------------------------------------------------------------
// Address: 0x100A4090
// Name: protected: void CSoundBrowser::OnChangeFilter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::OnChangeFilter(CSoundBrowser *this)
{
  this->m_uLastFilterChange = _time64(timeptr: nullptr);
  this->m_bFilterChanged = 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A40B0
// Name: protected: void CSoundBrowser::OnPreview(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::OnPreview(CSoundBrowser *this)
{
  int m_SoundType; // eax

  if ( this->m_nSelectedSoundIndex >= 0 )
  {
    m_SoundType = this->m_SoundType;
    if ( m_SoundType != 0 )
      CSoundSystem::Play(
        this: &g_Sounds,
        type: m_SoundType != 1 ? SOUND_TYPE_SCENE : SOUND_TYPE_RAW,
        nIndex: this->m_nSelectedSoundIndex);
    else
      CSoundSystem::Play(this: &g_Sounds, type: SOUND_TYPE_GAMESOUND, nIndex: this->m_nSelectedSoundIndex);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A40F0
// Name: protected: void CSoundBrowser::OnAutoplay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::OnAutoplay(CSoundBrowser *this)
{
  CWnd::UpdateData(this, bSaveAndValidate: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100A4100
// Name: protected: void CSoundBrowser::OnOpenSource(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::OnOpenSource(CSoundBrowser *this)
{
  int m_SoundType; // eax

  if ( this->m_nSelectedSoundIndex >= 0 )
  {
    m_SoundType = this->m_SoundType;
    if ( m_SoundType != 0 )
      CSoundSystem::OpenSource(
        this: &g_Sounds,
        type: m_SoundType != 1 ? SOUND_TYPE_SCENE : SOUND_TYPE_RAW,
        nIndex: this->m_nSelectedSoundIndex);
    else
      CSoundSystem::OpenSource(this: &g_Sounds, type: SOUND_TYPE_GAMESOUND, nIndex: this->m_nSelectedSoundIndex);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4140
// Name: protected: void CSoundBrowser::OnBnClickedStopsound(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::OnBnClickedStopsound(CSoundBrowser *this)
{
  CSoundSystem::StopSound(this: &g_Sounds);
}

//------------------------------------------------------------------------------
// Address: 0x100A4150
// Name: protected: void CSoundBrowser::SaveValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::SaveValues(CSoundBrowser *this)
{
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v3; // eax
  AFX_MODULE_STATE *v4; // eax

  ModuleState = AfxGetModuleState();
  ModuleState->m_pCurrentWinApp->WriteProfileInt(
    this: ModuleState->m_pCurrentWinApp,
    a2: s_pszSection,
    a3: "Sound Type",
    a4: this->m_SoundType);
  v3 = AfxGetModuleState();
  v3->m_pCurrentWinApp->WriteProfileInt(
    this: v3->m_pCurrentWinApp,
    a2: s_pszSection,
    a3: "Sound Autoplay",
    a4: this->m_Autoplay);
  v4 = AfxGetModuleState();
  v4->m_pCurrentWinApp->WriteProfileStringA(
    this: v4->m_pCurrentWinApp,
    a2: s_pszSection,
    a3: "Sound Filter",
    a4: this->m_szFilter);
}

//------------------------------------------------------------------------------
// Address: 0x100A41D0
// Name: protected: virtual void CSoundBrowser::DoDataExchange(class CDataExchange __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::DoDataExchange(CSoundBrowser *this, CDataExchange *pDX)
{
  DDX_Control(pDX, nIDC: (HWND__ *)0x668, rControl: (HWND__ *)&this->m_SoundList);
  DDX_Text(pDX, nIDC: (HWND__ *)0x3F1, value: &this->m_SoundNameSelected);
  DDX_CBIndex((HWND__ *)pDX, nIDC: (HWND__ *)0x664, index: &this->m_SoundType);
  DDX_Check((HWND__ *)pDX, nIDC: (HWND__ *)0x669, value: &this->m_Autoplay);
  DDX_Text(pDX, nIDC: (HWND__ *)0x66A, value: &this->m_SoundFile);
  DDX_Text(pDX, nIDC: (HWND__ *)0x66B, value: &this->m_SoundSource);
}

//------------------------------------------------------------------------------
// Address: 0x100A4250
// Name: private: void CSoundBrowser::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100A4300
// Name: public: virtual int CSoundBrowser::DoModal(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundBrowser::DoModal(CSoundBrowser *this)
{
  int v2; // edi

  v2 = CDialog::DoModal(this);
  CSoundBrowser::Shutdown(this);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x100A4320
// Name: protected: void CSoundBrowser::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::OnClose(CSoundBrowser *this)
{
  CSoundBrowser::Shutdown(this);
  CWnd::Default(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A4330
// Name: private: void CSoundBrowser::PopulateSoundList(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100A44E0
// Name: private: void CSoundBrowser::OnFilterChanged(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::OnFilterChanged(CSoundBrowser *this, const char *pFilter)
{
  char *m_szFilter; // edi
  char *i; // eax

  m_szFilter = this->m_szFilter;
  V_strncpy(pDest: this->m_szFilter, pSrc: pFilter, maxLen: 256);
  this->m_nFilters = 0;
  for ( i = strtok(string: m_szFilter, control: " ,;"); i != nullptr; i = strtok(string: nullptr, control: " ,;") )
    this->m_Filters[this->m_nFilters++] = i;
  CSoundBrowser::PopulateSoundList(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A4560
// Name: protected: void CSoundBrowser::OnTimer(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::OnTimer(CSoundBrowser *this, const char *nIDEvent)
{
  __int64 v3; // rax
  bool v4; // of
  __int64 v5; // rax
  UINT_PTR v6; // edi
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
      StringManager = AfxGetStringManager();
      if ( StringManager == nullptr )
        ATL::AtlThrowImpl(hr: -2147467259);
      nIDEvent = (const char *)&StringManager->GetNilString(this: StringManager)[1];
      CWnd::GetWindowTextA(
        this: &this->m_cFilter,
        rString: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&nIDEvent);
      CSoundBrowser::OnFilterChanged(this, pFilter: nIDEvent);
      SetTimer(hWnd: this->m_hWnd, nIDEvent: v6, uElapse: 0x1F4u, lpTimerFunc: nullptr);
      v8 = nIDEvent - 16;
      if ( _InterlockedDecrement((volatile signed __int32 *)nIDEvent - 1) <= 0 )
        (*(void (__stdcall **)(const char *))(**(_DWORD **)v8 + 4))(a1: v8);
    }
    CWnd::Default(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4670
// Name: protected: void CSoundBrowser::OnUpdateFilterNOW(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::OnUpdateFilterNOW(CSoundBrowser *this)
{
  CAfxStringMgr *StringManager; // eax
  WPARAM v3; // eax
  char *v4; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+4h] [ebp-10h] BYREF
  int v6; // [esp+10h] [ebp-4h]

  this->m_uLastFilterChange = _time64(timeptr: nullptr);
  this->m_bFilterChanged = 0;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  str.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v6 = 1;
  v3 = SendMessageA(hWnd: this->m_cFilter.m_hWnd, Msg: 0x147u, wParam: 0, lParam: 0);
  CComboBox::GetLBText(this: &this->m_cFilter, nIndex: v3, rString: &str);
  CSoundBrowser::OnFilterChanged(this, pFilter: str.m_pszData);
  v6 = -1;
  v4 = str.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v4 + 4))(a1: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100A4740
// Name: protected: void CSoundBrowser::OnSelchangeSoundType(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::OnSelchangeSoundType(CSoundBrowser *this)
{
  CWnd::UpdateData(this, bSaveAndValidate: 1);
  CSoundBrowser::PopulateSoundList(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A4760
// Name: protected: void CSoundBrowser::OnRefreshSounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::OnRefreshSounds(CSoundBrowser *this)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v3; // eax
  char *m_pszData; // edi
  HINSTANCE__ *StringResourceHandle; // eax
  char *v6; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > newTitle; // [esp+8h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > oldTitle; // [esp+Ch] [ebp-10h] BYREF
  int v9; // [esp+18h] [ebp-4h]

  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  oldTitle.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v9 = 1;
  v3 = AfxGetStringManager();
  if ( v3 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  m_pszData = (char *)&v3->GetNilString(this: v3)[1];
  newTitle.m_pszData = m_pszData;
  LOBYTE(v9) = 3;
  StringResourceHandle = AfxFindStringResourceHandle(__formal: 0xE143u);
  if ( StringResourceHandle != nullptr )
  {
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
      this: &newTitle,
      hInstance: StringResourceHandle,
      nID: 0xE143u);
    m_pszData = newTitle.m_pszData;
  }
  CWnd::GetWindowTextA(this, rString: &oldTitle);
  CWnd::SetWindowTextA(this, lpszString: m_pszData);
  CSoundSystem::Initialize(this: &g_Sounds);
  CSoundBrowser::PopulateSoundList(this);
  CWnd::SetWindowTextA(this, lpszString: oldTitle.m_pszData);
  LOBYTE(v9) = 1;
  if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
    (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
      a1: *((_DWORD *)m_pszData - 4),
      a2: m_pszData - 16);
  v9 = -1;
  v6 = oldTitle.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)oldTitle.m_pszData - 1) <= 0 )
    (*(void (__thiscall **)(_DWORD, char *))(**(_DWORD **)v6 + 4))(a1: *(_DWORD *)v6, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x100A4880
// Name: public: CSoundBrowser::CSoundBrowser(char const __near *,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CSoundBrowser *__thiscall CSoundBrowser::CSoundBrowser(
        CSoundBrowser *this,
        const char *pCurrentSoundName,
        CWnd *pParent)
{
  CAfxStringMgr *StringManager; // eax
  CAfxStringMgr *v5; // eax
  CAfxStringMgr *v6; // eax
  int v7; // eax
  int v8; // eax
  AFX_MODULE_STATE *ModuleState; // eax
  AFX_MODULE_STATE *v10; // eax
  AFX_MODULE_STATE *v11; // eax
  const char **v12; // eax
  COleDropTarget **p_m_pDropTarget; // eax

  CDialog::CDialog(this, nIDTemplate: 0x143u, pParentWnd: pParent);
  this->__vftable = (CSoundBrowser_vtbl *)&CSoundBrowser::`vftable';
  pParent = &this->m_SoundList;
  CWnd::CWnd(this: &this->m_SoundList);
  this->m_SoundList.__vftable = (CListBox_vtbl *)&CListBox::`vftable';
  pParent = (CWnd *)&this->m_SoundNameSelected;
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_SoundNameSelected.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  pParent = (CWnd *)&this->m_SoundFile;
  v5 = AfxGetStringManager();
  if ( v5 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  this->m_SoundFile.m_pszData = (char *)&v5->GetNilString(this: v5)[1];
  pParent = (CWnd *)&this->m_SoundSource;
  v6 = AfxGetStringManager();
  if ( v6 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  v7 = (int)v6->GetNilString(this: v6);
  pParent->__vftable = (CWnd_vtbl *)(v7 + 16);
  CAutoSelComboBox::CAutoSelComboBox(this: &this->m_cFilter);
  this->m_Autoplay = 0;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_SoundFile, pszSrc: &var, nLength: 0);
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_SoundSource, pszSrc: &var, nLength: 0);
  if ( pCurrentSoundName != nullptr )
    v8 = strlen(pCurrentSoundName);
  else
    v8 = 0;
  ATL::CSimpleStringT<char,0>::SetString(this: &this->m_SoundNameSelected, pszSrc: pCurrentSoundName, nLength: v8);
  ModuleState = AfxGetModuleState();
  this->m_SoundType = ModuleState->m_pCurrentWinApp->GetProfileIntA(
                        this: ModuleState->m_pCurrentWinApp,
                        a2: s_pszSection,
                        a3: "Sound Type",
                        a4: 0);
  v10 = AfxGetModuleState();
  this->m_Autoplay = v10->m_pCurrentWinApp->GetProfileIntA(
                       this: v10->m_pCurrentWinApp,
                       a2: s_pszSection,
                       a3: "Sound Autoplay",
                       a4: 0);
  v11 = AfxGetModuleState();
  v12 = (const char **)v11->m_pCurrentWinApp->GetProfileStringA(
                         this: v11->m_pCurrentWinApp,
                         result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&pParent,
                         a3: s_pszSection,
                         a4: "Sound Filter",
                         a5: &var);
  V_strncpy(pDest: this->m_szFilter, pSrc: *v12, maxLen: 256);
  p_m_pDropTarget = &pParent[-1].m_pDropTarget;
  if ( _InterlockedDecrement((volatile signed __int32 *)&pParent[-1].m_pMFCCtrlContainer) <= 0 )
    ((void (__stdcall *)(COleDropTarget **))(*p_m_pDropTarget)->dtr_CObject)(a1: p_m_pDropTarget);
  this->m_nSelectedSoundIndex = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A4AE0
// Name: private: void CSoundBrowser::CopySoundNameToSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::CopySoundNameToSelected(CSoundBrowser *this)
{
  WPARAM v2; // eax
  LRESULT v3; // edi
  int m_SoundType; // eax
  int v5; // eax
  unsigned int v6; // edi
  char *m_pSoundName; // edx
  int v8; // eax
  int v9; // eax
  int v10; // eax
  CSoundSystem::SoundInfo_t *m_pMemory; // eax
  const char *m_pSoundFile; // edx
  int v13; // eax
  int v14; // eax
  int v15; // eax
  CSoundSystem::SoundInfo_t *v16; // eax
  const char *m_pSourceFile; // edx
  int v18; // eax
  int nSoundIndex; // [esp+8h] [ebp-8h]

  CWnd::UpdateData(this, bSaveAndValidate: 1);
  v2 = SendMessageA(hWnd: this->m_SoundList.m_hWnd, Msg: 0x188u, wParam: 0, lParam: 0);
  if ( v2 != -1 )
  {
    v3 = SendMessageA(hWnd: this->m_SoundList.m_hWnd, Msg: 0x199u, wParam: v2, lParam: 0);
    m_SoundType = this->m_SoundType;
    nSoundIndex = v3;
    if ( m_SoundType != 0 )
      v5 = m_SoundType != 1 ? 2 : 0;
    else
      v5 = 1;
    v6 = v3;
    m_pSoundName = g_Sounds.m_SoundList[v5].m_Sounds.m_Memory.m_pMemory[v6].m_pSoundName;
    if ( m_pSoundName != nullptr )
      v8 = strlen(m_pSoundName);
    else
      v8 = 0;
    ATL::CSimpleStringT<char,0>::SetString(this: &this->m_SoundNameSelected, pszSrc: m_pSoundName, nLength: v8);
    v9 = this->m_SoundType;
    if ( v9 != 0 )
      v10 = v9 != 1 ? 2 : 0;
    else
      v10 = 1;
    m_pMemory = g_Sounds.m_SoundList[v10].m_Sounds.m_Memory.m_pMemory;
    m_pSoundFile = m_pMemory[v6].m_pSoundFile;
    if ( m_pSoundFile != nullptr )
      v13 = strlen(m_pMemory[v6].m_pSoundFile);
    else
      v13 = 0;
    ATL::CSimpleStringT<char,0>::SetString(this: &this->m_SoundFile, pszSrc: m_pSoundFile, nLength: v13);
    v14 = this->m_SoundType;
    if ( v14 != 0 )
      v15 = v14 != 1 ? 2 : 0;
    else
      v15 = 1;
    v16 = g_Sounds.m_SoundList[v15].m_Sounds.m_Memory.m_pMemory;
    m_pSourceFile = v16[v6].m_pSourceFile;
    if ( m_pSourceFile != nullptr )
      v18 = strlen(v16[v6].m_pSourceFile);
    else
      v18 = 0;
    ATL::CSimpleStringT<char,0>::SetString(this: &this->m_SoundSource, pszSrc: m_pSourceFile, nLength: v18);
    this->m_nSelectedSoundIndex = nSoundIndex;
    CWnd::UpdateData(this, bSaveAndValidate: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4C30
// Name: protected: void CSoundBrowser::OnSelchangeSoundList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::OnSelchangeSoundList(CSoundBrowser *this)
{
  int m_SoundType; // eax

  CSoundBrowser::CopySoundNameToSelected(this);
  if ( this->m_Autoplay != 0 && this->m_nSelectedSoundIndex >= 0 )
  {
    m_SoundType = this->m_SoundType;
    if ( m_SoundType != 0 )
      CSoundSystem::Play(
        this: &g_Sounds,
        type: m_SoundType != 1 ? SOUND_TYPE_SCENE : SOUND_TYPE_RAW,
        nIndex: this->m_nSelectedSoundIndex);
    else
      CSoundSystem::Play(this: &g_Sounds, type: SOUND_TYPE_GAMESOUND, nIndex: this->m_nSelectedSoundIndex);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A4C80
// Name: protected: void CSoundBrowser::OnDblclkSoundList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSoundBrowser::OnDblclkSoundList(CSoundBrowser *this)
{
  CSoundBrowser::CopySoundNameToSelected(this);
  this->OnOK(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A4CA0
// Name: protected: virtual int CSoundBrowser::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSoundBrowser::OnInitDialog(CSoundBrowser *this)
{
  int i; // edi
  WPARAM v3; // eax
  WPARAM v4; // edi
  LRESULT v5; // eax
  int m_SoundType; // ecx
  int v7; // ecx
  LRESULT v8; // edi
  char *m_pSoundFile; // edx
  int v10; // eax
  int v11; // eax
  int v12; // eax
  const char *m_pSourceFile; // edi
  int v14; // eax
  char *v15; // eax
  HWND__ *m_hWnd; // [esp-10h] [ebp-30h]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > temp; // [esp+10h] [ebp-10h] BYREF
  int v19; // [esp+1Ch] [ebp-4h]

  CDialog::OnInitDialog(this);
  CAutoSelComboBox::SubclassDlgItem(this: &this->m_cFilter, nID: 0x663u, pParent: this);
  for ( i = 0; i < CSoundBrowser::m_nFilterHistory; ++i )
  {
    if ( i < 0 || i >= CSoundBrowser::m_FilterHistory.m_nSize )
      AfxThrowInvalidArgException();
    SendMessageA(
      hWnd: this->m_cFilter.m_hWnd,
      Msg: 0x143u,
      wParam: 0,
      lParam: (LPARAM)CSoundBrowser::m_FilterHistory.m_pData[i].m_pszData);
  }
  CWnd::SetWindowTextA(this: &this->m_cFilter, lpszString: this->m_szFilter);
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
    this: &temp,
    pszSrc: this->m_szFilter);
  v19 = 0;
  CSoundBrowser::OnFilterChanged(this, pFilter: temp.m_pszData);
  v3 = SendMessageA(
         hWnd: this->m_SoundList.m_hWnd,
         Msg: 0x18Fu,
         wParam: 0xFFFFFFFF,
         lParam: (LPARAM)this->m_SoundNameSelected.m_pszData);
  v4 = v3;
  if ( v3 != -1 )
  {
    SendMessageA(hWnd: this->m_SoundList.m_hWnd, Msg: 0x186u, wParam: v3, lParam: 0);
    m_hWnd = this->m_SoundList.m_hWnd;
    this->m_nSelectedSoundIndex = v4;
    v5 = SendMessageA(hWnd: m_hWnd, Msg: 0x199u, wParam: v4, lParam: 0);
    m_SoundType = this->m_SoundType;
    if ( m_SoundType != 0 )
      v7 = m_SoundType != 1 ? 2 : 0;
    else
      v7 = 1;
    v8 = v5;
    m_pSoundFile = g_Sounds.m_SoundList[v7].m_Sounds.m_Memory.m_pMemory[v5].m_pSoundFile;
    if ( m_pSoundFile != nullptr )
      v10 = strlen(m_pSoundFile);
    else
      v10 = 0;
    ATL::CSimpleStringT<char,0>::SetString(this: &this->m_SoundFile, pszSrc: m_pSoundFile, nLength: v10);
    v11 = this->m_SoundType;
    if ( v11 != 0 )
      v12 = v11 != 1 ? 2 : 0;
    else
      v12 = 1;
    m_pSourceFile = g_Sounds.m_SoundList[v12].m_Sounds.m_Memory.m_pMemory[v8].m_pSourceFile;
    if ( m_pSourceFile != nullptr )
      v14 = strlen(m_pSourceFile);
    else
      v14 = 0;
    ATL::CSimpleStringT<char,0>::SetString(this: &this->m_SoundSource, pszSrc: m_pSourceFile, nLength: v14);
    CWnd::UpdateData(this, bSaveAndValidate: 0);
  }
  SetTimer(hWnd: this->m_hWnd, nIDEvent: 1u, uElapse: 0x1F4u, lpTimerFunc: nullptr);
  v19 = -1;
  v15 = temp.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)temp.m_pszData - 1) <= 0 )
    (*(void (__stdcall **)(char *))(**(_DWORD **)v15 + 4))(a1: v15);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A4EA0
// Name: protected: virtual struct AFX_MSGMAP const __near * CSoundBrowser::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CSoundBrowser::GetMessageMap(CSoundBrowser *this)
{
  return (const AFX_MSGMAP *)&off_105E622C;
}

//------------------------------------------------------------------------------
// Address: 0x1012FF90
// Name: public: char const __near * CSoundBrowser::GetSelectedSound(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CSoundBrowser::GetSelectedSound(CSoundBrowser *this)
{
  return this->m_SoundNameSelected.m_pszData;
}

//------------------------------------------------------------------------------
// Address: 0x105C0910
// Name: _dynamic_initializer_for__CSoundBrowser::m_FilterHistory__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CSoundBrowser::m_FilterHistory__()
{
  CStringArray::CStringArray(this: &CSoundBrowser::m_FilterHistory);
  return atexit(func: dynamic_atexit_destructor_for__CSoundBrowser::m_FilterHistory__);
}

//------------------------------------------------------------------------------
// Address: 0x105CAB40
// Name: _dynamic_atexit_destructor_for__CSoundBrowser::m_FilterHistory__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CSoundBrowser::m_FilterHistory__()
{
  CStringArray::~CStringArray(this: &CSoundBrowser::m_FilterHistory);
}

//------------------------------------------------------------------------------
// Address: 0x105C0930
// Name: _dynamic_initializer_for__g_SoundPlayData__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SoundPlayData__()
{
  g_SoundPlayData.m_Size = 0;
  g_SoundPlayData.m_pElements = g_SoundPlayData.m_Memory.m_pMemory;
  return atexit(func: dynamic_atexit_destructor_for__g_SoundPlayData__);
}

//------------------------------------------------------------------------------
// Address: 0x105C0980
// Name: _dynamic_initializer_for__g_Sounds__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Sounds__()
{
  `eh vector constructor iterator'(
    ptr: g_Sounds.m_SoundList,
    size: 0x18u,
    count: 3,
    pCtor: (void (__thiscall *)(void *))CAnchorMgr::CAnchorMgr,
    pDtor: (void (__thiscall *)(void *))CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>::~CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>);
  return atexit(func: dynamic_atexit_destructor_for__g_Sounds__);
}

//------------------------------------------------------------------------------
// Address: 0x105C09E0
// Name: _dynamic_initializer_for__g_SpriteDataCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_SpriteDataCache__()
{
  g_SpriteDataCache.m_Elements.m_Tree.m_Root = -1;
  g_SpriteDataCache.m_Elements.m_Tree.m_NumElements = 0;
  g_SpriteDataCache.m_Elements.m_Tree.m_FirstFree = -1;
  g_SpriteDataCache.m_Elements.m_Tree.m_LastAlloc.index = -1;
  g_SpriteDataCache.m_Elements.m_Tree.m_pElements = g_SpriteDataCache.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( g_SpriteDataCache.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    g_SpriteDataCache.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  return atexit(func: dynamic_atexit_destructor_for__g_SpriteDataCache__);
}

//------------------------------------------------------------------------------
// Address: 0x105C0A60
// Name: _dynamic_initializer_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_preload__()
{
  ConVar::ConVar(
    this: &mod_load_preload,
    pName: "mod_load_preload",
    pDefaultValue: "1.0",
    flags: 0,
    pHelpString: "Indicates how far ahead in seconds to preload animations.");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_preload__);
}

//------------------------------------------------------------------------------
// Address: 0x105C0A90
// Name: _dynamic_initializer_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mod_load_showstall__()
{
  ConVar::ConVar(
    this: &mod_load_showstall,
    pName: "mod_load_showstall",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "1 - show hitches , 2 - show stalls");
  return atexit(func: dynamic_atexit_destructor_for__mod_load_showstall__);
}

//------------------------------------------------------------------------------
// Address: 0x105C0AC0
// Name: _dynamic_initializer_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::CUtlSymbolTable(this: &g_ActivityModifiersTable, growSize: 0, initSize: 16, caseInsensitive: false);
  return atexit(func: dynamic_atexit_destructor_for__g_ActivityModifiersTable__);
}

//------------------------------------------------------------------------------
// Address: 0x105C0AE0
// Name: _dynamic_initializer_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall dynamic_initializer_for__emptyMapping__(char a1)
{
  int v2; // [esp-4h] [ebp-18h] BYREF
  CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs v3; // [esp+0h] [ebp-14h]
  int *v4; // [esp+4h] [ebp-10h]
  int v5; // [esp+10h] [ebp-4h]

  v4 = &v2;
  CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>::CUtlHash<CStudioHdr::CActivityToSequenceMapping::HashValueType,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs,CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs>(
    this: &emptyMapping.m_ActToSeqHash,
    bucketCount: 8,
    growCount: 0,
    initCount: 0,
    compareFunc: (CStudioHdr::CActivityToSequenceMapping::HashValueType::HashFuncs)a1,
    keyFunc: v3);
  emptyMapping.m_pStudioHdr = nullptr;
  emptyMapping.m_expectedVModel = nullptr;
  v5 = -1;
  return atexit(func: dynamic_atexit_destructor_for__emptyMapping__);
}

//------------------------------------------------------------------------------
// Address: 0x105C0B60
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMaps__()
{
  *(_DWORD *)&g_StudioHdrToActivityMaps.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&g_StudioHdrToActivityMaps.m_Tree.m_FirstFree = -1;
  g_StudioHdrToActivityMaps.m_Tree.m_pElements = g_StudioHdrToActivityMaps.m_Tree.m_Elements.m_pMemory;
  return atexit(func: dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__);
}

//------------------------------------------------------------------------------
// Address: 0x105C0BD0
// Name: _dynamic_initializer_for__g_StudioHdrToActivityMapsLock__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioHdrToActivityMapsLock__()
{
  g_StudioHdrToActivityMapsLock.m_ownerID = 0;
  g_StudioHdrToActivityMapsLock.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x105C0BE0
// Name: _dynamic_initializer_for__g_StudioFileChangeWatcher__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioFileChangeWatcher__()
{
  g_StudioFileChangeWatcher.__vftable = (CStudioFileChangeWatcher_vtbl *)&CStudioFileChangeWatcher::`vftable';
  CFileChangeWatcher::CFileChangeWatcher(this: &g_StudioFileChangeWatcher.m_Watcher);
  g_StudioFileChangeWatcher.m_ChangedModels.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  g_StudioFileChangeWatcher.m_ChangedModels.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  g_StudioFileChangeWatcher.m_ChangedModels.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  g_StudioFileChangeWatcher.m_ChangedModels.m_Elements.m_Tree.m_Root = -1;
  g_StudioFileChangeWatcher.m_ChangedModels.m_Elements.m_Tree.m_NumElements = 0;
  g_StudioFileChangeWatcher.m_ChangedModels.m_Elements.m_Tree.m_FirstFree = -1;
  g_StudioFileChangeWatcher.m_ChangedModels.m_Elements.m_Tree.m_LastAlloc.index = -1;
  g_StudioFileChangeWatcher.m_ChangedModels.m_Elements.m_Tree.m_pElements = nullptr;
  g_StudioFileChangeWatcher.m_ChangedModels.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  return atexit(func: dynamic_atexit_destructor_for__g_StudioFileChangeWatcher__);
}

//------------------------------------------------------------------------------
// Address: 0x105CAB50
// Name: _dynamic_atexit_destructor_for__g_SoundPlayData__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SoundPlayData__()
{
  char *m_pMemory; // eax

  m_pMemory = g_SoundPlayData.m_Memory.m_pMemory;
  g_SoundPlayData.m_Size = 0;
  if ( g_SoundPlayData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_SoundPlayData.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: g_SoundPlayData.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_SoundPlayData.m_Memory.m_pMemory = nullptr;
    }
    g_SoundPlayData.m_Memory.m_nAllocationCount = 0;
  }
  g_SoundPlayData.m_pElements = m_pMemory;
  if ( g_SoundPlayData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_SoundPlayData.m_Memory.m_pMemory != nullptr )
    {
      free(pMem: g_SoundPlayData.m_Memory.m_pMemory);
      g_SoundPlayData.m_Memory.m_pMemory = nullptr;
    }
    g_SoundPlayData.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x105CABE0
// Name: _dynamic_atexit_destructor_for__g_Sounds__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_Sounds__()
{
  g_Sounds.__vftable = (CSoundSystem_vtbl *)&CSoundSystem::`vftable';
  CSoundSystem::ShutDown(this: &g_Sounds);
  `eh vector destructor iterator'(
    ptr: g_Sounds.m_SoundList,
    size: 0x18u,
    count: 3,
    pDtor: (void (__thiscall *)(void *))CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>::~CUtlPriorityQueue<TranslucentObjects_s,CDefUtlPriorityQueueLessFunc<TranslucentObjects_s>,CUtlMemory<TranslucentObjects_s,int>>);
}

//------------------------------------------------------------------------------
// Address: 0x105CAC40
// Name: _dynamic_atexit_destructor_for__g_SpriteDataCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_SpriteDataCache__()
{
  CUtlDict<CSpriteDataCache *,int>::RemoveAll(this: &g_SpriteDataCache);
  CUtlRBTree<CUtlMap<char const *,CSpriteDataCache *,int>::Node_t,int,CUtlMap<char const *,CSpriteDataCache *,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CSpriteDataCache *,int>::Node_t,int>,int>>::RemoveAll(this: &g_SpriteDataCache.m_Elements.m_Tree);
  g_SpriteDataCache.m_Elements.m_Tree.m_FirstFree = -1;
  if ( g_SpriteDataCache.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( g_SpriteDataCache.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      free(pMem: g_SpriteDataCache.m_Elements.m_Tree.m_Elements.m_pMemory);
      g_SpriteDataCache.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    g_SpriteDataCache.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  g_SpriteDataCache.m_Elements.m_Tree.m_LastAlloc.index = -1;
  if ( g_SpriteDataCache.m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( g_SpriteDataCache.m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
    {
      free(pMem: g_SpriteDataCache.m_Elements.m_Tree.m_Elements.m_pMemory);
      g_SpriteDataCache.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
    }
    g_SpriteDataCache.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x105CACF0
// Name: _dynamic_atexit_destructor_for__mod_load_preload__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_preload__()
{
  ConVar::~ConVar(this: &mod_load_preload);
}

//------------------------------------------------------------------------------
// Address: 0x105CAD00
// Name: _dynamic_atexit_destructor_for__mod_load_showstall__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__mod_load_showstall__()
{
  ConVar::~ConVar(this: &mod_load_showstall);
}

//------------------------------------------------------------------------------
// Address: 0x105CAD10
// Name: _dynamic_atexit_destructor_for__g_ActivityModifiersTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ActivityModifiersTable__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ActivityModifiersTable);
}

//------------------------------------------------------------------------------
// Address: 0x105CAD20
// Name: _dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioHdrToActivityMaps__()
{
  CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short,CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<studiohdr_t const *,StudioHdrToActivityMapEntry_t,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &g_StudioHdrToActivityMaps.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x105CAD60
// Name: _dynamic_atexit_destructor_for__emptyMapping__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__emptyMapping__()
{
  CStudioHdr::CActivityToSequenceMapping::SequenceTuple *m_pSequenceTuples; // ecx

  m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
  if ( emptyMapping.m_pSequenceTuples != nullptr )
  {
    if ( emptyMapping.m_pSequenceTuples->pActivityModifiers != nullptr )
    {
      operator delete(p: emptyMapping.m_pSequenceTuples->pActivityModifiers);
      m_pSequenceTuples = emptyMapping.m_pSequenceTuples;
    }
    operator delete(p: m_pSequenceTuples);
  }
  CUtlHash<CDataModel::ElementIdHandlePair_t,bool (__cdecl *)(CDataModel::ElementIdHandlePair_t const &,CDataModel::ElementIdHandlePair_t const &),unsigned int (__cdecl *)(CDataModel::ElementIdHandlePair_t const &)>::Purge(this: (CUtlHash<CDmElementDictionary::DmIdPair_t,bool (__cdecl*)(CDmElementDictionary::DmIdPair_t const &,CDmElementDictionary::DmIdPair_t const &),unsigned int (__cdecl*)(CDmElementDictionary::DmIdPair_t const &)> *)&emptyMapping.m_ActToSeqHash);
  CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>::~CUtlVector<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,CUtlMemory<CUtlVector<CStudioHdr::CActivityToSequenceMapping::HashValueType,CUtlMemory<CStudioHdr::CActivityToSequenceMapping::HashValueType,int>>,int>>(this: &emptyMapping.m_ActToSeqHash.m_Buckets);
}

//------------------------------------------------------------------------------
// Address: 0x105CADF0
// Name: _dynamic_atexit_destructor_for__g_StudioFileChangeWatcher__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioFileChangeWatcher__()
{
  CUtlDict<int,int>::RemoveAll(this: &g_StudioFileChangeWatcher.m_ChangedModels);
  CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,int,int>::Node_t,int,CUtlMap<char const *,int,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,int>::Node_t,int>,int>>(this: &g_StudioFileChangeWatcher.m_ChangedModels.m_Elements.m_Tree);
  CFileChangeWatcher::~CFileChangeWatcher(this: &g_StudioFileChangeWatcher.m_Watcher);
}
