// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/hud/sfhudvotepanel.cpp
// Functions: 8
// ============================================================

#include "game\client\cstrike15\scaleform\hud\sfhudvotepanel.h"

//------------------------------------------------------------------------------
// Address: 0x10224B20
// Name: public: static void SFHudVotePanel::SetVoteString(enum VoteType,int,int,char __near *,class ISFTextObject __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SFHudVotePanel::SetVoteString(
        VoteType voteIssue,
        int kickTargetIndex,
        int callingPlayerIndex,
        char *stringId,
        ISFTextObject *textObject)
{
  int v5; // ebx
  C_CS_PlayerResource *v6; // eax
  int v7; // esi
  IGameResources *v8; // edi
  int v9; // eax
  wchar_t *(__thiscall *Find)(ILocalize *, const char *); // eax
  const wchar_t *v11; // esi
  const wchar_t *v12; // edi
  const char *v13; // eax
  const char *v14; // eax
  wchar_t labelText[256]; // [esp+4h] [ebp-3E4h] BYREF
  wchar_t voteTypeText[128]; // [esp+204h] [ebp-1E4h] BYREF
  wchar_t kickTargetWideName[32]; // [esp+304h] [ebp-E4h] BYREF
  wchar_t callerWideName[32]; // [esp+344h] [ebp-A4h] BYREF
  wchar_t numVotersText[16]; // [esp+384h] [ebp-64h] BYREF
  wchar_t numYesVotesText[16]; // [esp+3A4h] [ebp-44h] BYREF
  const char *voteStrings[7]; // [esp+3C4h] [ebp-24h]
  C_CS_PlayerResource *cs_PR; // [esp+3E0h] [ebp-8h]
  int numYesVotes; // [esp+3E4h] [ebp-4h]

  v5 = 0;
  if ( textObject != nullptr )
  {
    textObject->SetText_2(this: textObject, a2: prType);
    v6 = (C_CS_PlayerResource *)__RTDynamicCast(
                                  inptr: g_PR,
                                  VfDelta: 0,
                                  SrcType: &C_PlayerResource `RTTI Type Descriptor',
                                  TargetType: &C_CS_PlayerResource `RTTI Type Descriptor',
                                  isReference: 0);
    cs_PR = v6;
    if ( (unsigned int)(voteIssue - 1) <= 5 && v6 != nullptr )
    {
      numYesVotes = 0;
      v7 = 1;
      v8 = &v6->IGameResources;
      do
      {
        if ( v8->IsConnected(this: v8, a2: v7) )
        {
          v9 = v8->GetTeam(this: v8, a2: v7);
          if ( (v9 == 3 || v9 == 2) && !v8->IsFakePlayer(this: v8, a2: v7) )
          {
            ++v5;
            if ( C_CS_PlayerResource::GetVote(this: cs_PR, iIndex: v7) )
              ++numYesVotes;
          }
        }
        ++v7;
      }
      while ( v7 <= 64 );
      numYesVotesText[0] = 0;
      numVotersText[0] = 0;
      V_snwprintf(pDest: numYesVotesText, maxLen: 16, pFormat: L"%i", numYesVotes);
      V_snwprintf(pDest: numVotersText, maxLen: 16, pFormat: L"%i", v5);
      Find = g_pVGuiLocalize->Find;
      voteStrings[0] = "#SFUI_Vote_None";
      voteStrings[1] = "#SFUI_Vote_KickPlayer";
      voteStrings[2] = "#SFUI_Vote_TeamSwitch";
      voteStrings[3] = "#SFUI_Vote_ScrambleTeams";
      voteStrings[4] = "#SFUI_Vote_Surrender";
      voteStrings[5] = "#SFUI_Vote_RestartMatch";
      voteStrings[6] = "#SFUI_Vote_ChangeMap";
      v11 = Find(this: g_pVGuiLocalize, a2: stringId);
      if ( v11 != nullptr )
      {
        v12 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: voteStrings[voteIssue]);
        if ( v12 != nullptr )
        {
          kickTargetWideName[0] = 0;
          if ( voteIssue == VoteType_KickPlayer )
          {
            v13 = g_PR->GetPlayerName(this: &g_PR->IGameResources, a2: kickTargetIndex);
            _V_UTF8ToUnicode(a1: v13, a2: kickTargetWideName, a3: 64);
          }
          callerWideName[0] = 0;
          v14 = g_PR->GetPlayerName(this: &g_PR->IGameResources, a2: callingPlayerIndex);
          _V_UTF8ToUnicode(a1: v14, a2: callerWideName, a3: 64);
          g_pVGuiLocalize->ConstructString_3(
            this: g_pVGuiLocalize,
            a2: voteTypeText,
            a3: 256,
            a4: v12,
            a5: 1,
            kickTargetWideName);
          g_pVGuiLocalize->ConstructString_3(
            this: g_pVGuiLocalize,
            a2: labelText,
            a3: 512,
            a4: v11,
            a5: 4,
            numYesVotesText,
            numVotersText,
            voteTypeText,
            callerWideName);
          textObject->SetText(this: textObject, a2: labelText);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10224D60
// Name: public: virtual void SFHudVotePanel::LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudVotePanel::LevelInit(SFHudVotePanel *this)
{
  if ( !this->m_bFlashAPIIsValid )
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: 2,
      a3: "VotePanel",
      a4: (ScaleformUIFunctionHandlerObject *)this,
      a5: pScaleformFunctionHandler_SFHudVotePanel_VotePanel);
}

//------------------------------------------------------------------------------
// Address: 0x10224D90
// Name: public: virtual void SFHudVotePanel::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SFHudVotePanel::FlashReady(SFHudVotePanel *this@<ecx>, int a2@<edi>)
{
  void *m_FlashAPI; // eax
  void *v4; // edi
  ISFTextObject *v5; // eax
  IScaleformUI *m_pScaleformUI; // ecx
  char i; // al
  IScaleformUI *v8; // ecx

  m_FlashAPI = this->m_FlashAPI;
  if ( m_FlashAPI != nullptr )
  {
    v4 = g_pScaleformUI->Value_GetMember(this: g_pScaleformUI, a2: m_FlashAPI, a3: "VotePanel");
    if ( v4 != nullptr )
    {
      v5 = (ISFTextObject *)((int (__thiscall *)(IScaleformUI *, void *, const char *, int))g_pScaleformUI->TextObject_MakeTextObjectFromMember)(
                              a1: g_pScaleformUI,
                              a2: v4,
                              a3: "VoteText",
                              a4: a2);
      m_pScaleformUI = this->m_pScaleformUI;
      this->m_voteText = v5;
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->ReleaseValue(this: m_pScaleformUI, a2: v4);
      this->m_bRegisteredForEvents = true;
      ((void (__thiscall *)(IGameEventManager2 *, SFHudVotePanel *, const char *))gameeventmanager->AddListener)(
        a1: gameeventmanager,
        a2: this,
        a3: "start_vote");
      for ( i = 1; ; i = 0 )
      {
        v8 = this->m_pScaleformUI;
        if ( i == 0 )
          break;
        if ( v8 != nullptr )
          v8->LockSlot(this: v8, a2: this->m_iFlashSlot);
        this->m_pScaleformUI->Value_InvokeWithoutReturn(
          this: this->m_pScaleformUI,
          a2: this->m_FlashAPI,
          a3: "hide",
          a4: nullptr,
          a5: 0);
      }
      if ( v8 != nullptr )
        v8->UnlockSlot(this: v8, a2: this->m_iFlashSlot);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10224E50
// Name: public: virtual bool SFHudVotePanel::PreUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SFHudVotePanel::PreUnloadFlash(SFHudTrialTimer *this)
{
  ScaleformFlashInterfaceMixin<CHudElement>::SafeReleaseSFTextObject(this, value: &this->m_pTimerMessage);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10224E60
// Name: public: virtual void SFHudVotePanel::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudVotePanel::FireGameEvent(SFHudVotePanel *this, IGameEvent *event)
{
  const char *v4; // eax
  IVEngineClient_vtbl *v5; // edi
  int v6; // eax
  IVEngineClient_vtbl *v7; // edi
  int v8; // eax
  int v9; // edi
  C_CSPlayer *LocalPlayer; // esi
  char i; // al
  const char *v12; // eax
  int kickTarget; // [esp+8h] [ebp-4h]
  VoteType voteIssue; // [esp+14h] [ebp+8h]

  v4 = event->GetName(this: event);
  if ( _V_strcmp(s1: "start_vote", s2: v4) == 0 && this->m_FlashAPI != nullptr )
  {
    voteIssue = event->GetInt(this: event, a2: "type", a3: 0);
    v5 = engine->__vftable;
    v6 = event->GetInt(this: event, a2: "playerToKick", a3: 0);
    kickTarget = v5->GetPlayerForUserID(this: engine, a2: v6);
    v7 = engine->__vftable;
    v8 = event->GetInt(this: event, a2: "userid", a3: 0);
    v9 = v7->GetPlayerForUserID(this: engine, a2: v8);
    LocalPlayer = CClientTools::GetLocalPlayer();
    if ( LocalPlayer != nullptr
      && LocalPlayer->GetTeamNumber(this: LocalPlayer) != 0
      && LocalPlayer->GetTeamNumber(this: LocalPlayer) != 1 )
    {
      for ( i = 1; i != 0; i = 0 )
      {
        if ( this->m_pScaleformUI != nullptr )
          this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
        v12 = "hide";
        if ( voteIssue != VoteType_None )
          v12 = "show";
        this->m_pScaleformUI->Value_InvokeWithoutReturn(
          this: this->m_pScaleformUI,
          a2: this->m_FlashAPI,
          a3: v12,
          a4: nullptr,
          a5: 0);
        if ( voteIssue != VoteType_None )
          SFHudVotePanel::SetVoteString(
            voteIssue,
            kickTargetIndex: kickTarget,
            callingPlayerIndex: v9,
            stringId: "#SFUI_Vote_VoteStatus",
            textObject: this->m_voteText);
      }
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10224FD0
// Name: public: void SFHudVotePanel::Vote(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudVotePanel::Vote(SFHudVotePanel *this, IScaleformUI *pui, IScaleformUI *obj)
{
  C_CSPlayer *LocalPlayer; // edi
  C_CS_PlayerResource *v5; // edi
  int LocalPlayerIndex; // eax
  char i; // al

  LocalPlayer = CClientTools::GetLocalPlayer();
  if ( LocalPlayer != nullptr
    && LocalPlayer->GetTeamNumber(this: LocalPlayer) != 0
    && LocalPlayer->GetTeamNumber(this: LocalPlayer) != 1
    && LocalPlayer->m_currentVoteIssue != VoteType_None
    && g_pMatchFramework->IsOnlineGame(this: g_pMatchFramework) )
  {
    v5 = (C_CS_PlayerResource *)__RTDynamicCast(
                                  inptr: g_PR,
                                  VfDelta: 0,
                                  SrcType: &C_PlayerResource `RTTI Type Descriptor',
                                  TargetType: &C_CS_PlayerResource `RTTI Type Descriptor',
                                  isReference: 0);
    if ( v5 != nullptr )
    {
      LocalPlayerIndex = GetLocalPlayerIndex();
      if ( !C_CS_PlayerResource::GetVote(this: v5, iIndex: LocalPlayerIndex) )
        engine->ClientCmd(this: engine, a2: "player_vote 1");
    }
  }
  if ( this->m_FlashAPI != nullptr )
  {
    for ( i = 1; i != 0; i = 0 )
    {
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      this->m_pScaleformUI->Value_InvokeWithoutReturn(
        this: this->m_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "hide",
        a4: nullptr,
        a5: 0);
    }
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102250C0
// Name: Create_SFHudVotePanel
// Source: json
//------------------------------------------------------------------------------
CHudElement *__cdecl Create_SFHudVotePanel()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 76);
  memset(dst: v0, value: 0, count: 0x4Cu);
  if ( v0 == nullptr )
    return nullptr;
  v0[8] = 0;
  *((_DWORD *)v0 + 1) = 42;
  *((_DWORD *)v0 + 8) = 0;
  *((_DWORD *)v0 + 9) = 0;
  *((_DWORD *)v0 + 10) = 0;
  *((_DWORD *)v0 + 11) = 0;
  *((_DWORD *)v0 + 12) = 0;
  v0[68] = 0;
  *((_DWORD *)v0 + 16) = -1;
  *((_DWORD *)v0 + 14) = 0;
  *((_DWORD *)v0 + 15) = 0;
  *(_DWORD *)v0 = &SFHudFlashInterface::`vftable';
  CHudElement::InitCHudElementAfterConstruction(this: (CHudElement *)v0, pElementName: "SFHudVotePanel");
  *(_DWORD *)v0 = &SFHudVotePanel::`vftable';
  CTraceFilterSkipTwoEntities::SetPassEntity2(
    this: (CTraceFilterSkipTwoEntities *)v0,
    pPassEntity2: (const IHandleEntity *)0x40);
  *((_DWORD *)v0 + 18) = 0;
  return (CHudElement *)v0;
}

//------------------------------------------------------------------------------
// Address: 0x102267A0
// Name: public: virtual void SFHudVotePanel::LevelShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudVotePanel::LevelShutdown(SFHudDeathNoticeAndBotStatus *this)
{
  if ( this->m_bFlashAPIIsValid )
    this->m_pScaleformUI->RemoveElement(this: this->m_pScaleformUI, a2: this->m_iFlashSlot, a3: this->m_FlashAPI);
}
