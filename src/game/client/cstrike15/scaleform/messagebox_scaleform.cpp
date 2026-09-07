// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/messagebox_scaleform.cpp
// Functions: 30
// ============================================================

#include "game\client\cstrike15\scaleform\messagebox_scaleform.h"

//------------------------------------------------------------------------------
// Address: 0x1020DE30
// Name: protected: virtual void CMessageBoxScaleform::PostUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageBoxScaleform::PostUnloadFlash(CMessageBoxScaleform *this)
{
  this->m_pEventCallback = nullptr;
  ((void (__thiscall *)(CMessageBoxScaleform *, int))this->dtr_IGameEventListener2)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1020DE50
// Name: public: void CMessageBoxScaleform::OnMessageBoxClosed(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageBoxScaleform::OnMessageBoxClosed(
        CMessageBoxScaleform *this,
        IScaleformUI *pui,
        IScaleformUI *obj)
{
  if ( this->m_pEventCallback != nullptr && (this->m_dwFlags & 4) != 0 )
    this->m_pEventCallback->OnMessageBoxEvent(this: this->m_pEventCallback, a2: MESSAGEBOX_FLAG_BOX_CLOSED);
}

//------------------------------------------------------------------------------
// Address: 0x1020DE80
// Name: public: CMatchmakingStatus::~CMatchmakingStatus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchmakingStatus::~CMatchmakingStatus(CMatchmakingStatus *this)
{
  IMatchEventsSubscription *v2; // eax
  CGameUI *v3; // eax
  CCStrike15BasePanel *v4; // eax
  CCStrike15BasePanel *v5; // eax

  this->IMatchEventsSink::__vftable = (CMatchmakingStatus_vtbl *)&CMatchmakingStatus::`vftable'{for `IMatchEventsSink'};
  this->IMessageBoxEventCallback::__vftable = (IMessageBoxEventCallback_vtbl *)&CMatchmakingStatus::`vftable'{for `IMessageBoxEventCallback'};
  v2 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v2->Unsubscribe(this: v2, a2: this);
  if ( this->m_bErrorEncountered )
  {
    v3 = GameUI();
    if ( v3->IsInLevel(this: v3) )
    {
      v4 = BasePanel();
      v4->RestorePauseMenu(this: v4);
    }
    else
    {
      v5 = BasePanel();
      v5->RestoreMainMenuScreen(this: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020DEF0
// Name: protected: virtual bool CMatchmakingStatus::OnMessageBoxEvent(enum MessageBoxFlags_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMatchmakingStatus::OnMessageBoxEvent(CMatchmakingStatus *this, MessageBoxFlags_t buttonPressed)
{
  bool v3; // zf
  CMatchmakingStatus *v4; // esi

  if ( buttonPressed != MESSAGEBOX_FLAG_CANCEL )
    return 0;
  LOBYTE(this->m_pMessageBoxInstance) = 1;
  g_pMatchFramework->CloseSession(this: g_pMatchFramework);
  v3 = this == (CMatchmakingStatus *)4;
  v4 = (CMatchmakingStatus *)((char *)this - 4);
  v4->m_pMessageBoxInstance = nullptr;
  if ( !v3 )
  {
    CMatchmakingStatus::~CMatchmakingStatus(this: v4);
    C_BaseEntity::operator delete(pMem: v4);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1020E0B0
// Name: public: void CMessageBoxScaleform::Show(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageBoxScaleform::Show(CMessageBoxScaleform *this)
{
  char i; // al
  IScaleformUI *v3; // eax

  for ( i = 1; i != 0; i = 0 )
  {
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
    v3 = ScaleformUI();
    v3->Value_InvokeWithoutReturn(this: v3, a2: this->m_FlashAPI, a3: "showPanel", a4: nullptr, a5: 0);
  }
  if ( this->m_pScaleformUI != nullptr )
    this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
}

//------------------------------------------------------------------------------
// Address: 0x1020E110
// Name: public: void CMessageBoxScaleform::Hide(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageBoxScaleform::Hide(CMessageBoxScaleform *this)
{
  char i; // al
  IScaleformUI *v3; // eax

  for ( i = 1; i != 0; i = 0 )
  {
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
    v3 = ScaleformUI();
    v3->Value_InvokeWithoutReturn(this: v3, a2: this->m_FlashAPI, a3: "hidePanel", a4: nullptr, a5: 0);
  }
  if ( this->m_pScaleformUI != nullptr )
    this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
}

//------------------------------------------------------------------------------
// Address: 0x1020E170
// Name: public: void CMessageBoxScaleform::HideImmediate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageBoxScaleform::HideImmediate(CMessageBoxScaleform *this)
{
  char i; // al
  IScaleformUI *v3; // eax

  for ( i = 1; i != 0; i = 0 )
  {
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
    v3 = ScaleformUI();
    v3->Value_InvokeWithoutReturn(this: v3, a2: this->m_FlashAPI, a3: "hidePanelImmediate", a4: nullptr, a5: 0);
  }
  if ( this->m_pScaleformUI != nullptr )
    this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
}

//------------------------------------------------------------------------------
// Address: 0x1020E1D0
// Name: public: void CMessageBoxScaleform::SetMessage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageBoxScaleform::SetMessage(CMessageBoxScaleform *this, const char *pszMessage)
{
  char i; // al
  void *v4; // edi

  for ( i = 1; i != 0; i = 0 )
  {
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
    v4 = this->m_pScaleformUI->CreateValue_5(this: this->m_pScaleformUI, a2: 0);
    this->m_pScaleformUI->Value_SetValue_2(this: this->m_pScaleformUI, a2: v4, a3: pszMessage);
    this->m_pScaleformUI->Value_InvokeWithoutReturn(
      this: this->m_pScaleformUI,
      a2: this->m_FlashAPI,
      a3: "SetMessage",
      a4: v4,
      a5: 1u);
    this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v4);
  }
  if ( this->m_pScaleformUI != nullptr )
    this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
}

//------------------------------------------------------------------------------
// Address: 0x1020E260
// Name: public: void CMessageBoxScaleform::SetFlags(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageBoxScaleform::SetFlags(CMessageBoxScaleform *this, unsigned int dwFlags)
{
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  void *v5; // edi

  for ( i = 1; ; i = 0 )
  {
    m_pScaleformUI = this->m_pScaleformUI;
    if ( i == 0 )
      break;
    if ( m_pScaleformUI != nullptr )
      m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
    v5 = this->m_pScaleformUI->CreateValue_5(this: this->m_pScaleformUI, a2: 0);
    this->m_pScaleformUI->Value_SetValue_3(this: this->m_pScaleformUI, a2: v5, a3: this->m_dwFlags & 1);
    this->m_pScaleformUI->Value_InvokeWithoutReturn(
      this: this->m_pScaleformUI,
      a2: this->m_FlashAPI,
      a3: "SetFlagOk",
      a4: v5,
      a5: 1u);
    this->m_pScaleformUI->Value_SetValue_3(this: this->m_pScaleformUI, a2: v5, a3: (this->m_dwFlags & 2) != 0);
    this->m_pScaleformUI->Value_InvokeWithoutReturn(
      this: this->m_pScaleformUI,
      a2: this->m_FlashAPI,
      a3: "SetFlagCancel",
      a4: v5,
      a5: 1u);
    this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v5);
    if ( (this->m_dwFlags & 8) != 0 )
    {
      this->m_bRegisteredForEvents = true;
      gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "cs_game_disconnected", a4: false);
    }
  }
  if ( m_pScaleformUI != nullptr )
    m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
}

//------------------------------------------------------------------------------
// Address: 0x1020E350
// Name: public: void CMessageBoxScaleform::OnButtonPress(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CMessageBoxScaleform::OnButtonPress(
        CMessageBoxScaleform *this@<ecx>,
        int a2@<esi>,
        IScaleformUI *pui,
        void *obj)
{
  if ( this->m_pEventCallback == nullptr
    || (((void (__thiscall *)(IScaleformUI *, void *, _DWORD, int))pui->Params_GetArgAsNumber)(
          a1: pui,
          a2: obj,
          a3: 0,
          a4: a2),
        ((int (__thiscall *)(IMessageBoxEventCallback *))this->m_pEventCallback->OnMessageBoxEvent)(a1: this->m_pEventCallback) != 0) )
  {
    CMessageBoxScaleform::Hide(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020E3B0
// Name: public: virtual void CMessageBoxScaleform::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageBoxScaleform::FireGameEvent(CMessageBoxScaleform *this, IGameEvent *event)
{
  const char *v3; // eax

  if ( (this->m_dwFlags & 8) != 0 )
  {
    v3 = event->GetName(this: event);
    if ( _V_stricmp(s1: v3, s2: "cs_game_disconnected") == 0 && this->m_bFlashAPIIsValid )
    {
      if ( this->m_pEventCallback != nullptr )
        this->m_pEventCallback->OnMessageBoxEvent(
          this: this->m_pEventCallback,
          a2: MESSAGEBOX_FLAG_AUTO_CLOSE_ON_DISCONNECT);
      CMessageBoxScaleform::Hide(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020E410
// Name: protected: virtual bool CCommandMsgBox::OnMessageBoxEvent(enum MessageBoxFlags_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCommandMsgBox::OnMessageBoxEvent(CCommandMsgBox *this, MessageBoxFlags_t buttonPressed)
{
  char result; // al
  unsigned int m_iExitCommand; // eax
  char *v5; // eax
  IVEngineClient_vtbl *v6; // edx
  char *v7; // eax
  IVEngineClient_vtbl *v8; // edx
  void **m_pCommands; // esi
  int i; // ebx

  result = buttonPressed;
  if ( buttonPressed == MESSAGEBOX_FLAG_BOX_CLOSED )
  {
    m_iExitCommand = this->m_iExitCommand;
    if ( m_iExitCommand <= 2 )
    {
      v5 = this->m_pCommands[m_iExitCommand];
      if ( v5 != nullptr )
      {
        v6 = engine->__vftable;
        if ( *v5 == 33 )
          ((void (__stdcall *)(char *))v6->ClientCmd)(a1: v5 + 1);
        else
          ((void (__stdcall *)(char *))v6->ClientCmd_Unrestricted)(a1: v5);
      }
    }
    v7 = this->m_pCommands[2];
    if ( v7 != nullptr )
    {
      v8 = engine->__vftable;
      if ( *v7 == 33 )
        ((void (__stdcall *)(char *))v8->ClientCmd)(a1: v7 + 1);
      else
        ((void (__stdcall *)(char *))v8->ClientCmd_Unrestricted)(a1: this->m_pCommands[2]);
    }
    this->__vftable = (CCommandMsgBox_vtbl *)&CCommandMsgBox::`vftable';
    m_pCommands = (void **)this->m_pCommands;
    for ( i = 3; i != 0; --i )
    {
      if ( *m_pCommands != nullptr )
        C_BaseEntity::operator delete(pMem: *m_pCommands);
      ++m_pCommands;
    }
    C_BaseEntity::operator delete(pMem: this);
    return 0;
  }
  else if ( buttonPressed == MESSAGEBOX_FLAG_OK )
  {
    this->m_iExitCommand = 0;
  }
  else
  {
    if ( buttonPressed == MESSAGEBOX_FLAG_CANCEL )
      this->m_iExitCommand = 1;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020E4D0
// Name: protected: virtual void CMatchmakingStatus::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchmakingStatus::OnEvent(CMatchmakingStatus *this, KeyValues *pEvent)
{
  CMessageBoxScaleform *m_pMessageBoxInstance; // eax
  const char *Name; // ebx
  char *String; // esi
  char *v6; // esi
  char *v7; // esi
  const wchar_t *v8; // eax
  CModInfo *v9; // eax
  char *GameName; // eax
  bool v11; // zf
  const char *v12; // eax
  char pszMessageBuffer[1024]; // [esp+4h] [ebp-804h] BYREF
  char ansiLocString[1024]; // [esp+404h] [ebp-404h] BYREF
  CMatchmakingStatus *v15; // [esp+804h] [ebp-4h]

  m_pMessageBoxInstance = this->m_pMessageBoxInstance;
  v15 = this;
  if ( m_pMessageBoxInstance != nullptr && m_pMessageBoxInstance->m_bIsReady )
  {
    Name = KeyValues::GetName(this: pEvent);
    if ( _V_stricmp(s1: "OnEngineLevelLoadingStarted", s2: Name) != 0
      && _V_stricmp(s1: "LoadingScreenOpened", s2: Name) != 0 )
    {
      if ( _V_stricmp(s1: "OnMatchSessionUpdate", s2: Name) != 0 )
        return;
      String = KeyValues::GetString(this: pEvent, keyName: "state", defaultValue: prType);
      DevMsg(a1: "Matchmaking Status State = %s\n", String);
      if ( _V_stricmp(s1: String, s2: "progress") != 0 )
      {
        if ( _V_stricmp(s1: String, s2: "created") == 0 )
        {
LABEL_10:
          CMessageBoxScaleform::SetMessage(this: v15->m_pMessageBoxInstance, pszMessage: "#SFUI_MMStatus_Creating");
          return;
        }
        if ( _V_stricmp(s1: String, s2: "ready") != 0 )
        {
          if ( _V_stricmp(s1: String, s2: "closed") != 0 && _V_stricmp(s1: String, s2: "error") == 0 )
          {
            v7 = KeyValues::GetString(this: pEvent, keyName: String, defaultValue: prType);
            DevMsg(a1: "Matchmaking Error Details = %s\n", v7);
            v15->m_bErrorEncountered = true;
            if ( _V_stricmp(s1: v7, s2: "connect") != 0 )
            {
              v11 = _V_stricmp(s1: v7, s2: "nomap") == 0;
              v12 = "#SFUI_GameUI_DedicatedSearchFailed";
              if ( !v11 )
                v12 = "#SFUI_MMStatus_JoinFailed";
              CMessageBoxScaleform::SetMessage(this: v15->m_pMessageBoxInstance, pszMessage: v12);
            }
            else
            {
              v8 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#SFUI_GameUI_LostServerXLSP");
              g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v8, a3: ansiLocString, a4: 1024);
              v9 = ModInfo();
              GameName = CModInfo::GetGameName(this: v9);
              V_snprintf(pDest: pszMessageBuffer, maxLen: 0x400u, pFormat: ansiLocString, GameName);
              CMessageBoxScaleform::SetMessage(this: v15->m_pMessageBoxInstance, pszMessage: pszMessageBuffer);
            }
          }
        }
        else
        {
          CMessageBoxScaleform::SetMessage(this: v15->m_pMessageBoxInstance, pszMessage: "#SFUI_MMStatus_Joining");
        }
      }
      else
      {
        v6 = KeyValues::GetString(this: pEvent, keyName: String, defaultValue: prType);
        DevMsg(a1: "Matchmaking Status Details = %s\n", v6);
        if ( _V_stricmp(s1: v6, s2: "searching") == 0 )
        {
          CMessageBoxScaleform::SetMessage(this: v15->m_pMessageBoxInstance, pszMessage: "#SFUI_MMStatus_Searching");
          return;
        }
        if ( _V_stricmp(s1: v6, s2: "creating") == 0 )
          goto LABEL_10;
        _V_stricmp(s1: v6, s2: "searchresult");
      }
    }
    else
    {
      CMessageBoxScaleform::HideImmediate(this: this->m_pMessageBoxInstance);
      this->m_pMessageBoxInstance = nullptr;
      CMatchmakingStatus::~CMatchmakingStatus(this);
      C_BaseEntity::operator delete(pMem: this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020E760
// Name: public: static void CMessageBoxScaleform::UnloadAllDialogs(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CMessageBoxScaleform::UnloadAllDialogs()
{
  int i; // edi
  CMessageBoxScaleform *v1; // esi
  char j; // al
  IScaleformUI *v3; // eax

  for ( i = 0; i < CMessageBoxScaleform::m_sMessageBoxes.m_Size; ++i )
  {
    v1 = CMessageBoxScaleform::m_sMessageBoxes.m_Memory.m_pMemory[i];
    for ( j = 1; j != 0; j = 0 )
    {
      if ( v1->m_pScaleformUI != nullptr )
        v1->m_pScaleformUI->LockSlot(this: v1->m_pScaleformUI, a2: v1->m_iFlashSlot);
      v3 = ScaleformUI();
      v3->Value_InvokeWithoutReturn(this: v3, a2: v1->m_FlashAPI, a3: "hidePanel", a4: nullptr, a5: 0);
    }
    if ( v1->m_pScaleformUI != nullptr )
      v1->m_pScaleformUI->UnlockSlot(this: v1->m_pScaleformUI, a2: v1->m_iFlashSlot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020E7E0
// Name: protected: virtual void CMessageBoxScaleform::FlashLoaded(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageBoxScaleform::FlashLoaded(CMessageBoxScaleform *this)
{
  void *v2; // edi

  v2 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 3);
  this->m_pScaleformUI->ValueArray_SetElement_2(this: this->m_pScaleformUI, a2: v2, a3: 0, a4: this->m_szTitle);
  this->m_pScaleformUI->ValueArray_SetElement_2(this: this->m_pScaleformUI, a2: v2, a3: 1, a4: this->m_szMessage);
  this->m_pScaleformUI->ValueArray_SetElement_2(this: this->m_pScaleformUI, a2: v2, a3: 2, a4: this->m_szButtonLegend);
  this->m_pScaleformUI->Value_InvokeWithoutReturn(
    this: this->m_pScaleformUI,
    a2: this->m_FlashAPI,
    a3: "InitDialogData",
    a4: v2,
    a5: 3u);
  this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v2, a3: 3u);
  CMessageBoxScaleform::SetFlags(this, dwFlags: this->m_dwFlags);
}

//------------------------------------------------------------------------------
// Address: 0x1020E880
// Name: protected: virtual void CMessageBoxScaleform::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageBoxScaleform::FlashReady(CMessageBoxScaleform *this)
{
  this->m_bIsReady = true;
  CMessageBoxScaleform::Show(this);
}

//------------------------------------------------------------------------------
// Address: 0x1020E890
// Name: protected: virtual CMessageBoxScaleform::~CMessageBoxScaleform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMessageBoxScaleform::~CMessageBoxScaleform(CMessageBoxScaleform *this)
{
  int m_Size; // ecx
  int v3; // eax
  bool v4; // zf

  this->__vftable = (CMessageBoxScaleform_vtbl *)&CMessageBoxScaleform::`vftable';
  m_Size = CMessageBoxScaleform::m_sMessageBoxes.m_Size;
  v3 = 0;
  if ( CMessageBoxScaleform::m_sMessageBoxes.m_Size > 0 )
  {
    while ( CMessageBoxScaleform::m_sMessageBoxes.m_Memory.m_pMemory[v3] != this )
    {
      if ( ++v3 >= CMessageBoxScaleform::m_sMessageBoxes.m_Size )
        goto LABEL_10;
    }
    if ( v3 != -1 && CMessageBoxScaleform::m_sMessageBoxes.m_Size > 0 )
    {
      if ( v3 != CMessageBoxScaleform::m_sMessageBoxes.m_Size - 1 )
      {
        CMessageBoxScaleform::m_sMessageBoxes.m_Memory.m_pMemory[v3] = CMessageBoxScaleform::m_sMessageBoxes.m_Memory.m_pMemory[CMessageBoxScaleform::m_sMessageBoxes.m_Size - 1];
        m_Size = CMessageBoxScaleform::m_sMessageBoxes.m_Size;
      }
      CMessageBoxScaleform::m_sMessageBoxes.m_Size = m_Size - 1;
    }
  }
LABEL_10:
  v4 = !this->m_bFlashAPIIsValid;
  this->__vftable = (CMessageBoxScaleform_vtbl *)&ScaleformFlashInterfaceMixin<CGameEventListener>::`vftable';
  if ( !v4 )
    this->m_pScaleformUI->RemoveElement(this: this->m_pScaleformUI, a2: this->m_iFlashSlot, a3: this->m_FlashAPI);
  v4 = !this->m_bRegisteredForEvents;
  this->__vftable = (CMessageBoxScaleform_vtbl *)&CGameEventListener::`vftable';
  this->m_nDebugID = 13;
  if ( !v4 )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: this);
    this->m_bRegisteredForEvents = false;
  }
  this->__vftable = (CMessageBoxScaleform_vtbl *)&IGameEventListener2::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1020E940
// Name: protected: CMessageBoxScaleform::CMessageBoxScaleform(char const __near *,char const __near *,char const __near *,unsigned long,class IMessageBoxEventCallback __near *)
// Source: json
//------------------------------------------------------------------------------
CMessageBoxScaleform *__thiscall CMessageBoxScaleform::CMessageBoxScaleform(
        CMessageBoxScaleform *this,
        char *pszTitle,
        char *pszMessage,
        char *pszButtonLegend,
        unsigned int dwFlags,
        IMessageBoxEventCallback *pEventCallback)
{
  int m_Size; // eax
  int v8; // edi
  CMessageBoxScaleform **m_pMemory; // ecx
  int v10; // eax
  CMessageBoxScaleform **v11; // eax

  this->m_bRegisteredForEvents = false;
  this->m_nDebugID = 42;
  this->m_bFlashAPIIsValid = false;
  this->m_iFlashSlot = -1;
  this->m_pScaleformUI = nullptr;
  this->m_FlashAPI = nullptr;
  this->__vftable = (CMessageBoxScaleform_vtbl *)&CMessageBoxScaleform::`vftable';
  m_Size = CMessageBoxScaleform::m_sMessageBoxes.m_Size;
  v8 = CMessageBoxScaleform::m_sMessageBoxes.m_Size;
  if ( CMessageBoxScaleform::m_sMessageBoxes.m_Size + 1 > CMessageBoxScaleform::m_sMessageBoxes.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&CMessageBoxScaleform::m_sMessageBoxes,
      num: CMessageBoxScaleform::m_sMessageBoxes.m_Size
    - CMessageBoxScaleform::m_sMessageBoxes.m_Memory.m_nAllocationCount
    + 1);
    m_Size = CMessageBoxScaleform::m_sMessageBoxes.m_Size;
  }
  m_pMemory = CMessageBoxScaleform::m_sMessageBoxes.m_Memory.m_pMemory;
  CMessageBoxScaleform::m_sMessageBoxes.m_Size = m_Size + 1;
  v10 = m_Size - v8;
  CMessageBoxScaleform::m_sMessageBoxes.m_pElements = CMessageBoxScaleform::m_sMessageBoxes.m_Memory.m_pMemory;
  if ( v10 > 0 )
  {
    _V_memmove(
      dest: (unsigned __int8 *)&CMessageBoxScaleform::m_sMessageBoxes.m_Memory.m_pMemory[v8 + 1],
      src: (unsigned __int8 *)&CMessageBoxScaleform::m_sMessageBoxes.m_Memory.m_pMemory[v8],
      count: 4 * v10);
    m_pMemory = CMessageBoxScaleform::m_sMessageBoxes.m_Memory.m_pMemory;
  }
  v11 = &m_pMemory[v8];
  if ( v11 != nullptr )
    *v11 = this;
  this->m_bIsReady = false;
  this->m_szTitle[0] = 0;
  if ( pszTitle != nullptr )
    V_strncpy(pDest: this->m_szTitle, pSrc: pszTitle, maxLen: 1024);
  this->m_szMessage[0] = 0;
  if ( this != (CMessageBoxScaleform *)-1053 )
    V_strncpy(pDest: this->m_szMessage, pSrc: pszMessage, maxLen: 1024);
  this->m_szButtonLegend[0] = 0;
  if ( this != (CMessageBoxScaleform *)-2077 )
    V_strncpy(pDest: this->m_szButtonLegend, pSrc: pszButtonLegend, maxLen: 2048);
  this->m_dwFlags = dwFlags;
  this->m_pEventCallback = pEventCallback;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020EA80
// Name: public: static void CMessageBoxScaleform::LoadDialogInSlot(int,char const __near *,char const __near *,char const __near *,unsigned long,class IMessageBoxEventCallback __near *,class CMessageBoxScaleform __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMessageBoxScaleform::LoadDialogInSlot(
        int slot,
        char *pszTitle,
        char *pszMessage,
        char *pszButtonLegend,
        unsigned int dwFlags,
        IMessageBoxEventCallback *pEventCallback,
        ScaleformUIFunctionHandlerObject **ppMessageBoxInstance)
{
  CMessageBoxScaleform *v7; // eax
  ScaleformUIFunctionHandlerObject *v8; // esi

  if ( ppMessageBoxInstance != nullptr )
    *ppMessageBoxInstance = nullptr;
  v7 = (CMessageBoxScaleform *)MemAlloc_Alloc(nSize: 0x1028u);
  if ( v7 != nullptr )
    v8 = (ScaleformUIFunctionHandlerObject *)CMessageBoxScaleform::CMessageBoxScaleform(
                                               this: v7,
                                               pszTitle,
                                               pszMessage,
                                               pszButtonLegend,
                                               dwFlags,
                                               pEventCallback);
  else
    v8 = nullptr;
  g_pScaleformUI->RequestElement(
    this: g_pScaleformUI,
    a2: slot,
    a3: "MessageBox",
    a4: v8,
    a5: pScaleformFunctionHandler_CMessageBoxScaleform_MessageBox);
  if ( ppMessageBoxInstance != nullptr )
    *ppMessageBoxInstance = v8;
}

//------------------------------------------------------------------------------
// Address: 0x1020EAF0
// Name: protected: CCommandMsgBox::CCommandMsgBox(enum ECommandMsgBoxSlot,char const __near *,char const __near *,bool,bool,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CCommandMsgBox *__thiscall CCommandMsgBox::CCommandMsgBox(
        CCommandMsgBox *this,
        ECommandMsgBoxSlot slot,
        char *pszTitle,
        char *pszMessage,
        bool showOk,
        bool showCancel,
        const char *okCommand,
        const char *cancelCommand,
        const char *closedCommand,
        char *pszLegend)
{
  char **m_pCommands; // edi
  unsigned int v13; // eax
  char *v14; // eax
  unsigned int v15; // eax
  char *v16; // eax
  unsigned int v17; // eax
  char *v18; // eax
  int v19; // eax
  unsigned int dwFlags; // [esp+4h] [ebp-4h]
  char *plegend; // [esp+1Ch] [ebp+14h]

  this->__vftable = (CCommandMsgBox_vtbl *)&CCommandMsgBox::`vftable';
  this->m_iExitCommand = -1;
  this->m_pMessageBox = nullptr;
  dwFlags = 4;
  if ( showOk )
    dwFlags = 5;
  if ( showCancel )
    dwFlags |= 2u;
  plegend = pszLegend;
  if ( pszLegend == nullptr )
  {
    if ( showOk )
    {
      if ( showCancel )
      {
        plegend = "#SFUI_Legend_OkCancel";
        goto LABEL_11;
      }
    }
    else
    {
      plegend = "#SFUI_Legend_Cancel";
      if ( showCancel )
        goto LABEL_11;
    }
    plegend = "#SFUI_Legend_Ok";
  }
LABEL_11:
  m_pCommands = this->m_pCommands;
  _V_memset(dest: (int)this->m_pCommands, fill: nullptr, count: 0xCu);
  if ( okCommand != nullptr )
  {
    v13 = _V_strlen(str: okCommand);
    v14 = (char *)MemAlloc_Alloc(nSize: v13 + 1);
    *m_pCommands = v14;
    _V_strcpy(dest: v14, src: okCommand);
  }
  else
  {
    *m_pCommands = nullptr;
  }
  if ( cancelCommand != nullptr )
  {
    v15 = _V_strlen(str: cancelCommand);
    v16 = (char *)MemAlloc_Alloc(nSize: v15 + 1);
    this->m_pCommands[1] = v16;
    _V_strcpy(dest: v16, src: cancelCommand);
  }
  else
  {
    this->m_pCommands[1] = nullptr;
  }
  if ( closedCommand != nullptr )
  {
    v17 = _V_strlen(str: closedCommand);
    v18 = (char *)MemAlloc_Alloc(nSize: v17 + 1);
    this->m_pCommands[2] = v18;
    _V_strcpy(dest: v18, src: closedCommand);
  }
  else
  {
    this->m_pCommands[2] = nullptr;
  }
  if ( slot != CMB_SLOT_PLAYER_0 )
  {
    if ( slot == CMB_SLOT_PLAYER_1 )
      v19 = 3;
    else
      v19 = 1;
  }
  else
  {
    v19 = 2;
  }
  CMessageBoxScaleform::LoadDialogInSlot(
    slot: v19,
    pszTitle,
    pszMessage,
    pszButtonLegend: plegend,
    dwFlags,
    pEventCallback: this,
    ppMessageBoxInstance: (ScaleformUIFunctionHandlerObject **)&this->m_pMessageBox);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020EC30
// Name: public: static void CMessageBoxScaleform::LoadDialog(char const __near *,char const __near *,char const __near *,unsigned long,class IMessageBoxEventCallback __near *,class CMessageBoxScaleform __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CMessageBoxScaleform::LoadDialog(
        char *pszTitle,
        char *pszMessage,
        char *pszButtonLegend,
        unsigned int dwFlags,
        IMessageBoxEventCallback *pEventCallback,
        ScaleformUIFunctionHandlerObject **ppMessageBoxInstance)
{
  CMessageBoxScaleform::LoadDialogInSlot(
    slot: 1,
    pszTitle,
    pszMessage,
    pszButtonLegend,
    dwFlags,
    pEventCallback,
    ppMessageBoxInstance);
}

//------------------------------------------------------------------------------
// Address: 0x1020EC60
// Name: public: static void CCommandMsgBox::CreateAndShowInSlot(enum ECommandMsgBoxSlot,char const __near *,char const __near *,bool,bool,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CCommandMsgBox::CreateAndShowInSlot(
        ECommandMsgBoxSlot slot,
        char *pszTitle,
        char *pszMessage,
        bool showOk,
        bool showCancel,
        const char *okCommand,
        const char *cancelCommand,
        const char *closedCommand,
        char *pszLegend)
{
  CCommandMsgBox *v9; // eax

  v9 = (CCommandMsgBox *)MemAlloc_Alloc(nSize: 0x18u);
  if ( v9 != nullptr )
    CCommandMsgBox::CCommandMsgBox(
      this: v9,
      slot,
      pszTitle,
      pszMessage,
      showOk,
      showCancel,
      okCommand,
      cancelCommand,
      closedCommand,
      pszLegend);
}

//------------------------------------------------------------------------------
// Address: 0x1020ECA0
// Name: public: CMatchmakingStatus::CMatchmakingStatus(void)
// Source: json
//------------------------------------------------------------------------------
CMatchmakingStatus *__thiscall CMatchmakingStatus::CMatchmakingStatus(CMatchmakingStatus *this)
{
  IMessageBoxEventCallback *v2; // ebx
  CMessageBoxScaleform **p_m_pMessageBoxInstance; // edi
  IMatchEventsSubscription *v4; // eax
  CMessageBoxScaleform *v5; // eax
  ScaleformUIFunctionHandlerObject *v6; // ebx
  CMatchmakingStatus *result; // eax

  this->IMessageBoxEventCallback::__vftable = (IMessageBoxEventCallback_vtbl *)&IMessageBoxEventCallback::`vftable';
  v2 = &this->IMessageBoxEventCallback;
  this->IMatchEventsSink::__vftable = (CMatchmakingStatus_vtbl *)&CMatchmakingStatus::`vftable'{for `IMatchEventsSink'};
  this->IMessageBoxEventCallback::__vftable = (IMessageBoxEventCallback_vtbl *)&CMatchmakingStatus::`vftable'{for `IMessageBoxEventCallback'};
  p_m_pMessageBoxInstance = &this->m_pMessageBoxInstance;
  this->m_pMessageBoxInstance = nullptr;
  this->m_bErrorEncountered = false;
  v4 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v4->Subscribe(this: v4, a2: this);
  if ( p_m_pMessageBoxInstance != nullptr )
    *p_m_pMessageBoxInstance = nullptr;
  v5 = (CMessageBoxScaleform *)MemAlloc_Alloc(nSize: 0x1028u);
  if ( v5 != nullptr )
    v6 = (ScaleformUIFunctionHandlerObject *)CMessageBoxScaleform::CMessageBoxScaleform(
                                               this: v5,
                                               pszTitle: "#SFUI_MMStatus_Title",
                                               pszMessage: "#SFUI_MMStatus_Searching",
                                               pszButtonLegend: "#SFUI_MMStatus_Legend",
                                               dwFlags: 2u,
                                               pEventCallback: v2);
  else
    v6 = nullptr;
  g_pScaleformUI->RequestElement(
    this: g_pScaleformUI,
    a2: 1,
    a3: "MessageBox",
    a4: v6,
    a5: pScaleformFunctionHandler_CMessageBoxScaleform_MessageBox);
  result = this;
  if ( p_m_pMessageBoxInstance != nullptr )
    *p_m_pMessageBoxInstance = (CMessageBoxScaleform *)v6;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020ED40
// Name: public: static void CCommandMsgBox::CreateAndShow(char const __near *,char const __near *,bool,bool,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CCommandMsgBox::CreateAndShow(
        char *pszTitle,
        char *pszMessage,
        bool showOk,
        bool showCancel,
        const char *okCommand,
        const char *cancelCommand,
        const char *closedCommand,
        const char *pszLegend)
{
  CCommandMsgBox *v8; // eax

  v8 = (CCommandMsgBox *)MemAlloc_Alloc(nSize: 0x18u);
  if ( v8 != nullptr )
    CCommandMsgBox::CCommandMsgBox(
      this: v8,
      slot: CMB_SLOT_FULL_SCREEN,
      pszTitle,
      pszMessage,
      showOk,
      showCancel,
      okCommand,
      cancelCommand,
      closedCommand: pszLegend,
      pszLegend: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x104256A0
// Name: _dynamic_initializer_for__CMessageBoxScaleform::m_sMessageBoxes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CMessageBoxScaleform::m_sMessageBoxes__()
{
  return atexit(func: dynamic_atexit_destructor_for__CMessageBoxScaleform::m_sMessageBoxes__);
}

//------------------------------------------------------------------------------
// Address: 0x10435CF0
// Name: _dynamic_atexit_destructor_for__CMessageBoxScaleform::m_sMessageBoxes__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CMessageBoxScaleform::m_sMessageBoxes__()
{
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&CMessageBoxScaleform::m_sMessageBoxes);
}

//------------------------------------------------------------------------------
// Address: 0x10435D00
// Name: _dynamic_atexit_destructor_for__cl_disablefreezecam__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_disablefreezecam__()
{
  ConVar::~ConVar(this: &cl_disablefreezecam);
}

//------------------------------------------------------------------------------
// Address: 0x10435D10
// Name: _dynamic_atexit_destructor_for__cl_show_scaleform_achievement_popups__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_show_scaleform_achievement_popups__()
{
  ConVar::~ConVar(this: &cl_show_scaleform_achievement_popups);
}

//------------------------------------------------------------------------------
// Address: 0x10435D20
// Name: _dynamic_atexit_destructor_for__drawradar_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__drawradar_command__()
{
  ConCommand::~ConCommand(this: &drawradar_command);
}

//------------------------------------------------------------------------------
// Address: 0x10435D30
// Name: _dynamic_atexit_destructor_for__hideradar_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__hideradar_command__()
{
  ConCommand::~ConCommand(this: &hideradar_command);
}
