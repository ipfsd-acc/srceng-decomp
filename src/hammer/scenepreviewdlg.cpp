// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/scenepreviewdlg.cpp
// Functions: 10
// ============================================================

#include "hammer\scenepreviewdlg.h"

//------------------------------------------------------------------------------
// Address: 0x100A0310
// Name: public: CScenePreviewDlg::CScenePreviewDlg(class CChoreoScene __near *,char const __near *,class CWnd __near *)
// Source: json
//------------------------------------------------------------------------------
CScenePreviewDlg *__thiscall CScenePreviewDlg::CScenePreviewDlg(
        CScenePreviewDlg *this,
        CChoreoScene *pScene,
        const char *pFilename,
        CWnd *pParent)
{
  CDialog::CDialog(this, nIDTemplate: 0x152u, pParentWnd: pParent);
  this->m_hExitThreadEvent = nullptr;
  this->m_hIdleEventHandledEvent = nullptr;
  this->m_hIdleThread = nullptr;
  this->__vftable = (CScenePreviewDlg_vtbl *)&CScenePreviewDlg::`vftable';
  this->m_pScene = pScene;
  this->m_iLastEventPlayed = -2;
  V_strncpy(pDest: this->m_SceneFilename, pSrc: pFilename, maxLen: 260);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100A03A0
// Name: private: void CScenePreviewDlg::EndThread(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScenePreviewDlg::EndThread(CScenePreviewDlg *this)
{
  if ( this->m_hIdleThread != nullptr )
  {
    SetEvent(hEvent: this->m_hExitThreadEvent);
    WaitForSingleObject(hHandle: this->m_hIdleThread, dwMilliseconds: 0xFFFFFFFF);
    CloseHandle(hObject: this->m_hIdleThread);
    CloseHandle(hObject: this->m_hExitThreadEvent);
    CloseHandle(hObject: this->m_hIdleEventHandledEvent);
    this->m_hIdleEventHandledEvent = nullptr;
    this->m_hExitThreadEvent = nullptr;
    this->m_hIdleThread = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A0410
// Name: protected: virtual void CScenePreviewDlg::OnCancel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScenePreviewDlg::OnCancel(CScenePreviewDlg *this)
{
  CSoundSystem::StopSound(this: &g_Sounds);
  CScenePreviewDlg::EndThread(this);
  CDialog::EndDialog(this, nResult: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100A0430
// Name: public: virtual CScenePreviewDlg::~CScenePreviewDlg(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScenePreviewDlg::~CScenePreviewDlg(CScenePreviewDlg *this)
{
  CChoreoScene *m_pScene; // edi

  this->__vftable = (CScenePreviewDlg_vtbl *)&CScenePreviewDlg::`vftable';
  CScenePreviewDlg::EndThread(this);
  m_pScene = this->m_pScene;
  if ( m_pScene != nullptr )
  {
    CChoreoScene::~CChoreoScene(this: this->m_pScene);
    operator delete(p: m_pScene);
  }
  CDialog::~CDialog(this);
}

//------------------------------------------------------------------------------
// Address: 0x100A04A0
// Name: private: unsigned long CScenePreviewDlg::IdleThread(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CScenePreviewDlg::IdleThread(CScenePreviewDlg *this)
{
  HWND__ *m_hWnd; // edx
  void *m_hExitThreadEvent; // eax
  void *m_hIdleEventHandledEvent; // ecx
  DWORD i; // eax
  void *handles[2]; // [esp+Ch] [ebp-8h] BYREF

  m_hWnd = this->m_hWnd;
  m_hExitThreadEvent = this->m_hExitThreadEvent;
  m_hIdleEventHandledEvent = this->m_hIdleEventHandledEvent;
  handles[0] = m_hExitThreadEvent;
  handles[1] = m_hIdleEventHandledEvent;
  PostMessageA(hWnd: m_hWnd, Msg: 0x401u, wParam: 0, lParam: 0);
  for ( i = WaitForMultipleObjects(nCount: 2u, lpHandles: handles, bWaitAll: false, dwMilliseconds: 0xFFFFFFFF);
        i != 0;
        i = WaitForMultipleObjects(nCount: 2u, lpHandles: handles, bWaitAll: false, dwMilliseconds: 0xFFFFFFFF) )
  {
    if ( i == 258 )
      break;
    Sleep(dwMilliseconds: 0x64u);
    PostMessageA(hWnd: this->m_hWnd, Msg: 0x401u, wParam: 0, lParam: 0);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100A0520
// Name: protected: virtual struct AFX_MSGMAP const __near * CScenePreviewDlg::GetMessageMap(void)const
// Source: json
//------------------------------------------------------------------------------
const AFX_MSGMAP *__thiscall CScenePreviewDlg::GetMessageMap(CScenePreviewDlg *this)
{
  return (const AFX_MSGMAP *)&off_105E5E94;
}

//------------------------------------------------------------------------------
// Address: 0x100A05B0
// Name: private: static unsigned long CScenePreviewDlg::StaticIdleThread(void __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __stdcall CScenePreviewDlg::StaticIdleThread(CScenePreviewDlg *pParameter)
{
  return CScenePreviewDlg::IdleThread(this: pParameter);
}

//------------------------------------------------------------------------------
// Address: 0x100A05C0
// Name: protected: virtual int CScenePreviewDlg::OnInitDialog(void)
// Source: json
//------------------------------------------------------------------------------
int __usercall CScenePreviewDlg::OnInitDialog@<eax>(CScenePreviewDlg *this@<ecx>, int a2@<edi>)
{
  CAfxStringMgr *StringManager; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v4; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v5; // eax
  char *v6; // eax
  char *v7; // eax
  CAfxStringMgr *v8; // eax
  HINSTANCE__ *StringResourceHandle; // eax
  char *m_pszData; // edi
  int v11; // edi
  CChoreoEvent *Event; // eax
  CChoreoEvent *v13; // ebx
  char *v14; // eax
  char *v15; // eax
  char *v17; // [esp-8h] [ebp-2Ch]
  char *v18; // [esp-4h] [ebp-28h]
  int v19; // [esp+0h] [ebp-24h]
  int v20; // [esp+4h] [ebp-20h]
  int v21; // [esp+8h] [ebp-1Ch]
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > v22; // [esp+Ch] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strNone; // [esp+10h] [ebp-14h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > str; // [esp+14h] [ebp-10h] BYREF
  int v25; // [esp+20h] [ebp-4h]

  CDialog::OnInitDialog(this);
  StringManager = AfxGetStringManager();
  if ( StringManager == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  str.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
  v25 = 1;
  CWnd::GetDlgItemTextA(this, nID: 1666, rString: &str);
  v4 = ATL::operator+(a1: a2, a2: (int)this, result: &v22, str1: &str, psz2: " ");
  LOBYTE(v25) = 2;
  v5 = ATL::operator+(a1: a2, a2: (int)this, result: &strNone, str1: v4, psz2: this->m_SceneFilename);
  LOBYTE(v25) = 3;
  ATL::CSimpleStringT<char,0>::operator=(this: &str, strSrc: (ATL::CStringData *)v5);
  LOBYTE(v25) = 2;
  v6 = strNone.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)strNone.m_pszData - 1) <= 0 )
  {
    v18 = v6;
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)v6 + 4))(a1: *(_DWORD *)v6);
  }
  LOBYTE(v25) = 1;
  v7 = v22.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)v22.m_pszData - 1) <= 0 )
  {
    v17 = v7;
    (*(void (__thiscall **)(_DWORD))(**(_DWORD **)v7 + 4))(a1: *(_DWORD *)v7);
  }
  CWnd::SetDlgItemTextA(this, nID: 1666, lpszString: str.m_pszData);
  v8 = AfxGetStringManager();
  if ( v8 == nullptr )
    ATL::AtlThrowImpl(hr: -2147467259);
  strNone.m_pszData = (char *)&v8->GetNilString(this: v8)[1];
  LOBYTE(v25) = 7;
  StringResourceHandle = AfxFindStringResourceHandle(__formal: 0x83u);
  if ( StringResourceHandle != nullptr )
    ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
      this: &strNone,
      hInstance: StringResourceHandle,
      nID: 0x83u);
  m_pszData = strNone.m_pszData;
  CWnd::SetDlgItemTextA(this, nID: 1667, lpszString: strNone.m_pszData);
  CWnd::SetDlgItemTextA(this, nID: 245, lpszString: m_pszData);
  this->m_iLastEventPlayed = -1;
  this->m_flStartTime = _Plat_FloatTime(a1: v17, a2: v18, a3: v19, a4: v20, a5: v21);
  v11 = 0;
  if ( CParticleOperatorDefinition<C_OP_RemapModelVolumetoCP>::GetName(this: (vgui::Image *)this->m_pScene) > 0 )
  {
    while ( 1 )
    {
      Event = (CChoreoEvent *)CChoreoScene::GetEvent(this: (CToolDictionary *)this->m_pScene, index: v11);
      v13 = Event;
      if ( Event != nullptr && CChoreoEvent::GetType(this: Event) == SPEAK )
        break;
      if ( ++v11 >= CParticleOperatorDefinition<C_OP_RemapModelVolumetoCP>::GetName(this: (vgui::Image *)this->m_pScene) )
        goto LABEL_17;
    }
    this->m_flStartTime = this->m_flStartTime - CChoreoEvent::GetStartTime(this: v13);
  }
LABEL_17:
  this->m_hExitThreadEvent = CreateEventA(
                               lpEventAttributes: nullptr,
                               bManualReset: false,
                               bInitialState: false,
                               lpName: nullptr);
  this->m_hIdleEventHandledEvent = CreateEventA(
                                     lpEventAttributes: nullptr,
                                     bManualReset: false,
                                     bInitialState: false,
                                     lpName: nullptr);
  this->m_hIdleThread = CreateThread(
                          lpThreadAttributes: nullptr,
                          dwStackSize: 0,
                          lpStartAddress: (LPTHREAD_START_ROUTINE)CScenePreviewDlg::StaticIdleThread,
                          lpParameter: this,
                          dwCreationFlags: 0,
                          lpThreadId: nullptr);
  LOBYTE(v25) = 1;
  v14 = strNone.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)strNone.m_pszData - 1) <= 0 )
    (*(void (__thiscall **)(_DWORD, char *))(**(_DWORD **)v14 + 4))(a1: *(_DWORD *)v14, a2: v14);
  v25 = -1;
  v15 = str.m_pszData - 16;
  if ( _InterlockedDecrement((volatile signed __int32 *)str.m_pszData - 1) <= 0 )
    (*(void (__thiscall **)(_DWORD, char *))(**(_DWORD **)v15 + 4))(a1: *(_DWORD *)v15, a2: v15);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100A0830
// Name: private: void CScenePreviewDlg::OnIdle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScenePreviewDlg::OnIdle(CScenePreviewDlg *this)
{
  long double v2; // st7
  vgui::Image *m_pScene; // ecx
  int v4; // esi
  CChoreoEvent *Event; // eax
  CChoreoEvent *v6; // ebx
  int v7; // ebx
  CChoreoScene *v8; // ecx
  CChoreoEvent *v9; // eax
  const char *Parameters; // esi
  bool v11; // bl
  CAfxStringMgr *StringManager; // eax
  HINSTANCE__ *StringResourceHandle; // eax
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *v14; // eax
  int v15; // eax
  char *v16; // eax
  char *v17; // eax
  CAfxStringMgr *v18; // eax
  HINSTANCE__ *v19; // eax
  int v20; // esi
  CChoreoEvent *v21; // eax
  CChoreoEvent *v22; // ebx
  const char *v23; // eax
  int v24; // ecx
  char *m_pszData; // esi
  int v26; // [esp-8h] [ebp-38h]
  int v27; // [esp+0h] [ebp-30h]
  int v28; // [esp+4h] [ebp-2Ch]
  long double flElapsed; // [esp+8h] [ebp-28h] BYREF
  SoundType_t soundType; // [esp+10h] [ebp-20h] BYREF
  int nIndex; // [esp+14h] [ebp-1Ch] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > curSound; // [esp+18h] [ebp-18h] BYREF
  ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > strErrorPlaying; // [esp+1Ch] [ebp-14h] BYREF
  int iLastSound; // [esp+20h] [ebp-10h]
  int v35; // [esp+2Ch] [ebp-4h]

  v2 = _Plat_FloatTime(a1: v27, a2: v28, a3: LODWORD(flElapsed), a4: HIDWORD(flElapsed), a5: soundType)
     - this->m_flStartTime;
  m_pScene = (vgui::Image *)this->m_pScene;
  iLastSound = -1;
  flElapsed = v2;
  v4 = 0;
  if ( CParticleOperatorDefinition<C_OP_RemapModelVolumetoCP>::GetName(this: m_pScene) > 0 )
  {
    do
    {
      Event = (CChoreoEvent *)CChoreoScene::GetEvent(this: (CToolDictionary *)this->m_pScene, index: v4);
      v6 = Event;
      if ( Event != nullptr
        && CChoreoEvent::GetType(this: Event) == SPEAK
        && flElapsed > CChoreoEvent::GetStartTime(this: v6) )
      {
        iLastSound = v4;
      }
      ++v4;
    }
    while ( v4 < CParticleOperatorDefinition<C_OP_RemapModelVolumetoCP>::GetName(this: (vgui::Image *)this->m_pScene) );
    v7 = iLastSound;
    if ( iLastSound >= 0 && iLastSound != this->m_iLastEventPlayed )
    {
      v8 = this->m_pScene;
      v26 = iLastSound;
      this->m_iLastEventPlayed = iLastSound;
      v9 = (CChoreoEvent *)CChoreoScene::GetEvent(this: (CToolDictionary *)v8, index: v26);
      Parameters = CChoreoEvent::GetParameters(this: v9);
      if ( CSoundSystem::FindSoundByName(this: &g_Sounds, pFilename: Parameters, type: &soundType, &nIndex) )
      {
        v11 = CSoundSystem::Play(this: &g_Sounds, type: soundType, nIndex);
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>(
          this: &curSound,
          pszSrc: Parameters);
        v35 = 0;
        if ( !v11 )
        {
          StringManager = AfxGetStringManager();
          if ( StringManager == nullptr )
            ATL::AtlThrowImpl(hr: -2147467259);
          strErrorPlaying.m_pszData = (char *)&StringManager->GetNilString(this: StringManager)[1];
          LOBYTE(v35) = 2;
          StringResourceHandle = AfxFindStringResourceHandle(__formal: 1u);
          if ( StringResourceHandle != nullptr )
            ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
              this: &strErrorPlaying,
              hInstance: StringResourceHandle,
              nID: 1u);
          v14 = ATL::operator+(
                  result: (ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char> > > *)&flElapsed + 1,
                  psz1: " ",
                  str2: &strErrorPlaying);
          LOBYTE(v35) = 3;
          ATL::CSimpleStringT<char,0>::Append(
            this: &curSound,
            pszSrc: v14->m_pszData,
            nLength: *((_DWORD *)v14->m_pszData - 3));
          LOBYTE(v35) = 2;
          v15 = HIDWORD(flElapsed) - 16;
          if ( _InterlockedDecrement((volatile signed __int32 *)(HIDWORD(flElapsed) - 16 + 12)) <= 0 )
            (*(void (__stdcall **)(int))(**(_DWORD **)v15 + 4))(a1: v15);
          LOBYTE(v35) = 0;
          v16 = strErrorPlaying.m_pszData - 16;
          if ( _InterlockedDecrement((volatile signed __int32 *)strErrorPlaying.m_pszData - 1) <= 0 )
            (*(void (__stdcall **)(char *))(**(_DWORD **)v16 + 4))(a1: v16);
        }
        CWnd::SetDlgItemTextA(this, nID: 1667, lpszString: curSound.m_pszData);
        v35 = -1;
        v17 = curSound.m_pszData - 16;
        if ( _InterlockedDecrement((volatile signed __int32 *)curSound.m_pszData - 1) <= 0 )
          (*(void (__stdcall **)(char *))(**(_DWORD **)v17 + 4))(a1: v17);
        v7 = iLastSound;
      }
      v18 = AfxGetStringManager();
      if ( v18 == nullptr )
        ATL::AtlThrowImpl(hr: -2147467259);
      curSound.m_pszData = (char *)&v18->GetNilString(this: v18)[1];
      v35 = 8;
      v19 = AfxFindStringResourceHandle(__formal: 0x83u);
      if ( v19 != nullptr )
        ATL::CStringT<char,StrTraitMFC<char,ATL::ChTraitsCRT<char>>>::LoadStringA(
          this: &curSound,
          hInstance: v19,
          nID: 0x83u);
      v20 = v7 + 1;
      if ( v7 + 1 < CParticleOperatorDefinition<C_OP_RemapModelVolumetoCP>::GetName(this: (vgui::Image *)this->m_pScene) )
      {
        while ( 1 )
        {
          v21 = (CChoreoEvent *)CChoreoScene::GetEvent(this: (CToolDictionary *)this->m_pScene, index: v20);
          v22 = v21;
          if ( v21 != nullptr && CChoreoEvent::GetType(this: v21) == SPEAK )
            break;
          if ( ++v20 >= CParticleOperatorDefinition<C_OP_RemapModelVolumetoCP>::GetName(this: (vgui::Image *)this->m_pScene) )
            goto LABEL_35;
        }
        v23 = CChoreoEvent::GetParameters(this: v22);
        if ( v23 != nullptr )
          v24 = strlen(v23);
        else
          v24 = 0;
        ATL::CSimpleStringT<char,0>::SetString(this: &curSound, pszSrc: v23, nLength: v24);
      }
LABEL_35:
      m_pszData = curSound.m_pszData;
      CWnd::SetDlgItemTextA(this, nID: 245, lpszString: curSound.m_pszData);
      v35 = -1;
      if ( _InterlockedDecrement((volatile signed __int32 *)m_pszData - 1) <= 0 )
        (*(void (__thiscall **)(_DWORD, char *))(**((_DWORD **)m_pszData - 4) + 4))(
          a1: *((_DWORD *)m_pszData - 4),
          a2: m_pszData - 16);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A0B20
// Name: protected: virtual long CScenePreviewDlg::DefWindowProcA(unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CScenePreviewDlg::DefWindowProcA(
        CScenePreviewDlg *this,
        unsigned int message,
        unsigned int wParam,
        int lParam)
{
  if ( message != 1025 )
    return CWnd::DefWindowProcA(this, nMsg: message, wParam, lParam);
  CScenePreviewDlg::OnIdle(this);
  SetEvent(hEvent: this->m_hIdleEventHandledEvent);
  return 0;
}
