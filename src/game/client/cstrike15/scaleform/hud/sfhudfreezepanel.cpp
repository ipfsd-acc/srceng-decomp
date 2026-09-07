// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/hud/sfhudfreezepanel.cpp
// Functions: 8
// ============================================================

#include "game\client\cstrike15\scaleform\hud\sfhudfreezepanel.h"

//------------------------------------------------------------------------------
// Address: 0x10219B10
// Name: private: void SFHudFreezePanel::SetIcon(enum DominationIconType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudFreezePanel::SetIcon(SFHudFreezePanel *this, DominationIconType iconType)
{
  int v2; // esi
  ISFTextObject **m_dominationIcons; // edi

  v2 = 0;
  m_dominationIcons = this->m_dominationIcons;
  do
  {
    if ( *m_dominationIcons != nullptr )
      (*m_dominationIcons)->SetVisible(this: *m_dominationIcons, a2: v2 == iconType);
    ++v2;
    ++m_dominationIcons;
  }
  while ( v2 < 3 );
}

//------------------------------------------------------------------------------
// Address: 0x10219B60
// Name: public: virtual void SFHudFreezePanel::LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudFreezePanel::LevelInit(SFHudFreezePanel *this)
{
  if ( !this->m_bFlashAPIIsValid )
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: 2,
      a3: "FreezePanel",
      a4: (ScaleformUIFunctionHandlerObject *)this,
      a5: pScaleformFunctionHandler_SFHudFreezePanel_FreezePanel);
}

//------------------------------------------------------------------------------
// Address: 0x10219B90
// Name: public: virtual void SFHudFreezePanel::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SFHudFreezePanel::FlashReady(SFHudFreezePanel *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  void *m_FlashAPI; // eax
  void *v5; // ebx
  void *v6; // eax
  IScaleformUI *m_pScaleformUI; // ecx
  void *v8; // edi
  ISFTextObject *v9; // eax
  IScaleformUI *v10; // ecx
  char i; // al
  IScaleformUI *v12; // ecx

  m_FlashAPI = this->m_FlashAPI;
  if ( m_FlashAPI != nullptr )
  {
    v5 = g_pScaleformUI->Value_GetMember(this: g_pScaleformUI, a2: m_FlashAPI, a3: "FreezePanel");
    if ( v5 != nullptr )
    {
      v6 = g_pScaleformUI->Value_GetMember(this: g_pScaleformUI, a2: v5, a3: "FreezePanel");
      m_pScaleformUI = this->m_pScaleformUI;
      v8 = v6;
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->ReleaseValue(this: m_pScaleformUI, a2: v5);
      if ( v8 != nullptr )
      {
        this->m_dominationText1 = (ISFTextObject *)((int (__thiscall *)(IScaleformUI *, void *, const char *, int, int))g_pScaleformUI->TextObject_MakeTextObjectFromMember)(
                                                     a1: g_pScaleformUI,
                                                     a2: v8,
                                                     a3: "DescriptionText",
                                                     a4: a3,
                                                     a5: a2);
        this->m_dominationText2 = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                    this: g_pScaleformUI,
                                    a2: v8,
                                    a3: "DescriptionTextTitle");
        this->m_killerName = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                               this: g_pScaleformUI,
                               a2: v8,
                               a3: "NameText");
        this->m_dominationIcons[1] = g_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                       this: g_pScaleformUI,
                                       a2: v8,
                                       a3: "NemesisIcon");
        v9 = g_pScaleformUI->TextObject_MakeTextObjectFromMember(this: g_pScaleformUI, a2: v8, a3: "RevengeIcon");
        v10 = this->m_pScaleformUI;
        this->m_dominationIcons[2] = v9;
        if ( v10 != nullptr )
          v10->ReleaseValue(this: v10, a2: v8);
        SFHudFreezePanel::SetIcon(this, iconType: None);
        this->m_bRegisteredForEvents = true;
        ((void (__thiscall *)(IGameEventManager2 *, SFHudFreezePanel *))gameeventmanager->AddListener)(
          a1: gameeventmanager,
          a2: this);
        this->m_bRegisteredForEvents = true;
        gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "hide_freezepanel", a4: false);
        this->m_bRegisteredForEvents = true;
        gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "player_death", a4: false);
        for ( i = 1; ; i = 0 )
        {
          v12 = this->m_pScaleformUI;
          if ( i == 0 )
            break;
          if ( v12 != nullptr )
            v12->LockSlot(this: v12, a2: this->m_iFlashSlot);
          this->m_pScaleformUI->Value_InvokeWithoutReturn(
            this: this->m_pScaleformUI,
            a2: this->m_FlashAPI,
            a3: "hide",
            a4: nullptr,
            a5: 0);
        }
        if ( v12 != nullptr )
          v12->UnlockSlot(this: v12, a2: this->m_iFlashSlot);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10219D20
// Name: public: virtual bool SFHudFreezePanel::PreUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SFHudFreezePanel::PreUnloadFlash(SFHudFreezePanel *this)
{
  ISFTextObject **m_dominationIcons; // edi
  int i; // ebx
  char j; // al
  char k; // al
  char m; // al
  bool result; // al

  m_dominationIcons = this->m_dominationIcons;
  for ( i = 3; i != 0; --i )
  {
    if ( *m_dominationIcons != nullptr )
    {
      for ( j = 1; j != 0; j = 0 )
      {
        if ( this->m_pScaleformUI != nullptr )
          this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
        (*m_dominationIcons)->Release(this: *m_dominationIcons);
      }
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      *m_dominationIcons = nullptr;
    }
    ++m_dominationIcons;
  }
  if ( this->m_dominationText1 != nullptr )
  {
    for ( k = 1; k != 0; k = 0 )
    {
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      this->m_dominationText1->Release(this: this->m_dominationText1);
    }
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
    this->m_dominationText1 = nullptr;
  }
  if ( this->m_dominationText2 != nullptr )
  {
    for ( m = 1; m != 0; m = 0 )
    {
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      this->m_dominationText2->Release(this: this->m_dominationText2);
    }
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
    this->m_dominationText2 = nullptr;
  }
  result = true;
  if ( this->m_killerName != nullptr )
  {
    while ( result )
    {
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      this->m_killerName->Release(this: this->m_killerName);
      result = false;
    }
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
    this->m_killerName = nullptr;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10219E70
// Name: private: void SFHudFreezePanel::PopulateDominationInfo(enum DominationIconType,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudFreezePanel::PopulateDominationInfo(
        SFHudFreezePanel *this,
        DominationIconType iconType,
        const char *localizationToken1,
        const char *localizationToken2)
{
  char i; // al
  int v6; // esi
  ISFTextObject **m_dominationIcons; // edi

  for ( i = 1; i != 0; i = 0 )
  {
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
    v6 = 0;
    m_dominationIcons = this->m_dominationIcons;
    do
    {
      if ( *m_dominationIcons != nullptr )
        (*m_dominationIcons)->SetVisible(this: *m_dominationIcons, a2: v6 == iconType);
      ++v6;
      ++m_dominationIcons;
    }
    while ( v6 < 3 );
    if ( this->m_dominationText1 != nullptr && this->m_dominationText2 != nullptr )
    {
      this->m_dominationText1->SetText_2(this: this->m_dominationText1, a2: localizationToken1);
      this->m_dominationText2->SetText_2(this: this->m_dominationText2, a2: localizationToken2);
    }
  }
  if ( this->m_pScaleformUI != nullptr )
    this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
}

//------------------------------------------------------------------------------
// Address: 0x10219F10
// Name: public: virtual void SFHudFreezePanel::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudFreezePanel::FireGameEvent(SFHudFreezePanel *this, IGameEvent *event)
{
  const char *v4; // ebx
  IVEngineClient_vtbl *v5; // ebx
  int v6; // eax
  IVEngineClient_vtbl *v7; // ebx
  int v8; // eax
  int v9; // ebx
  C_BaseEntity *v10; // eax
  C_CSPlayer *v11; // ebx
  char k; // al
  int v13; // ebx
  C_BasePlayer *LocalPlayer; // eax
  char i; // al
  int v16; // ebx
  C_BaseEntity *BaseEntity; // eax
  C_CSPlayer *v18; // edi
  const char *v19; // eax
  char j; // al
  void *v21; // edi
  void *v22; // edi
  IScaleformUI_vtbl *v23; // ebx
  int v24; // eax
  char xuidAsText[256]; // [esp+Ch] [ebp-18Ch] BYREF
  char killerName[128]; // [esp+10Ch] [ebp-8Ch] BYREF
  int iKillerIndex; // [esp+18Ch] [ebp-Ch]
  C_CSPlayer *pKiller; // [esp+190h] [ebp-8h] BYREF
  C_BasePlayer *pLocalPlayer; // [esp+194h] [ebp-4h] BYREF
  int iKillerHealth; // [esp+1A0h] [ebp+8h]
  int iKillerHealtha; // [esp+1A0h] [ebp+8h]

  v4 = event->GetName(this: event);
  if ( _V_strcmp(s1: "player_death", s2: v4) != 0 )
  {
    if ( _V_strcmp(s1: "hide_freezepanel", s2: v4) != 0 )
    {
      if ( _V_strcmp(s1: "show_freezepanel", s2: v4) == 0 )
      {
        CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
          this: (CGameUiSetActiveSplitScreenPlayerGuard *)&pLocalPlayer,
          slot: this->m_iFlashSlot - 2);
        v13 = event->GetInt(this: event, a2: "victim", a3: 0);
        LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
        if ( LocalPlayer != nullptr
          && v13 == LocalPlayer->entindex(this: &LocalPlayer->IClientNetworkable)
          && __RTDynamicCast(
               inptr: g_PR,
               VfDelta: 0,
               SrcType: &C_PlayerResource `RTTI Type Descriptor',
               TargetType: &C_CS_PlayerResource `RTTI Type Descriptor',
               isReference: 0) != nullptr )
        {
          if ( this->m_FlashAPI != nullptr )
          {
            for ( i = 1; i != 0; i = 0 )
            {
              ScaleformFlashInterfaceMixin<CHudElement>::LockScaleformSlot(this);
              this->m_pScaleformUI->Value_InvokeWithoutReturn(
                this: this->m_pScaleformUI,
                a2: this->m_FlashAPI,
                a3: "show",
                a4: nullptr,
                a5: 0);
            }
            ScaleformFlashInterfaceMixin<CHudElement>::UnlockScaleformSlot(this);
          }
          v16 = event->GetInt(this: event, a2: "killer", a3: 0);
          iKillerIndex = v16;
          BaseEntity = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: v16);
          v18 = ToBasePlayer(pEntity: BaseEntity);
          pKiller = v18;
          if ( v18 != nullptr )
          {
            iKillerHealtha = v18->GetHealth(this: v18);
            if ( !v18->IsAlive(this: v18) )
              iKillerHealtha = 0;
            v19 = g_PR->GetPlayerName(this: &g_PR->IGameResources, a2: v16);
            V_snprintf(pDest: killerName, maxLen: 0x80u, pFormat: "%s", v19);
            if ( this->m_FlashAPI != nullptr )
            {
              for ( j = 1; j != 0; j = 0 )
              {
                if ( this->m_pScaleformUI != nullptr )
                  this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
                v21 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
                this->m_pScaleformUI->ValueArray_SetElement_5(
                  this: this->m_pScaleformUI,
                  a2: v21,
                  a3: 0,
                  a4: iKillerHealtha);
                this->m_pScaleformUI->Value_InvokeWithoutReturn(
                  this: this->m_pScaleformUI,
                  a2: this->m_FlashAPI,
                  a3: "setKillerHealth",
                  a4: v21,
                  a5: 1u);
                this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v21, a3: 1u);
                if ( this->m_killerName != nullptr )
                  this->m_killerName->SetText_2(this: this->m_killerName, a2: killerName);
                memset(xuidAsText, 0, sizeof(xuidAsText));
                C_PlayerResource::FillXuidText(this: g_PR, iIndex: v16, buf: xuidAsText, bufSize: 0x100u);
                v22 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 2);
                this->m_pScaleformUI->ValueArray_SetElement_2(
                  this: this->m_pScaleformUI,
                  a2: v22,
                  a3: 0,
                  a4: xuidAsText);
                v23 = this->m_pScaleformUI->SFHudFlashInterface::ScaleformFlashInterfaceMixin<CHudElement>::__vftable;
                v24 = pKiller->GetTeamNumber(this: pKiller);
                v23->ValueArray_SetElement_3(this: this->m_pScaleformUI, a2: v22, a3: 1, a4: v24 == 3);
                this->m_pScaleformUI->Value_InvokeWithoutReturn(
                  this: this->m_pScaleformUI,
                  a2: this->m_FlashAPI,
                  a3: "showAvatar",
                  a4: v22,
                  a5: 2u);
                this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v22, a3: 2u);
                v16 = iKillerIndex;
              }
              if ( this->m_pScaleformUI != nullptr )
                this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
            }
          }
        }
        CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: (CGameUiSetActiveSplitScreenPlayerGuard *)&pLocalPlayer);
      }
    }
    else if ( this->m_FlashAPI != nullptr )
    {
      for ( k = 1; k != 0; k = 0 )
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
  else
  {
    v5 = engine->__vftable;
    v6 = event->GetInt(this: event, a2: "userid", a3: 0);
    iKillerHealth = v5->GetPlayerForUserID(this: engine, a2: v6);
    v7 = engine->__vftable;
    v8 = event->GetInt(this: event, a2: "attacker", a3: 0);
    v9 = v7->GetPlayerForUserID(this: engine, a2: v8);
    CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
      this: (CGameUiSetActiveSplitScreenPlayerGuard *)&pKiller,
      slot: this->m_iFlashSlot - 2);
    pLocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    v10 = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: v9);
    v11 = (C_CSPlayer *)v10;
    if ( v10 == nullptr || !v10->IsPlayer(this: v10) )
      v11 = nullptr;
    if ( pLocalPlayer != nullptr && iKillerHealth == pLocalPlayer->entindex(this: &pLocalPlayer->IClientNetworkable) )
    {
      if ( event->GetInt(this: event, a2: "dominated", a3: 0) > 0 )
      {
        SFHudFreezePanel::PopulateDominationInfo(
          this,
          iconType: Nemesis,
          localizationToken1: "#FreezePanel_NewNemesis1",
          localizationToken2: "#FreezePanel_NewNemesis2");
        CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: (CGameUiSetActiveSplitScreenPlayerGuard *)&pKiller);
        return;
      }
      if ( v11 != nullptr && C_CSPlayer::IsPlayerDominated(this: v11, iPlayerIndex: iKillerHealth) )
      {
        SFHudFreezePanel::PopulateDominationInfo(
          this,
          iconType: Nemesis,
          localizationToken1: "#FreezePanel_OldNemesis1",
          localizationToken2: "#FreezePanel_OldNemesis2");
        CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: (CGameUiSetActiveSplitScreenPlayerGuard *)&pKiller);
        return;
      }
      if ( event->GetInt(this: event, a2: "revenge", a3: 0) > 0 )
      {
        SFHudFreezePanel::PopulateDominationInfo(
          this,
          iconType: Revenge,
          localizationToken1: "#FreezePanel_Revenge1",
          localizationToken2: "#FreezePanel_Revenge2");
        CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: (CGameUiSetActiveSplitScreenPlayerGuard *)&pKiller);
        return;
      }
      SFHudFreezePanel::PopulateDominationInfo(
        this,
        iconType: None,
        localizationToken1: "#FreezePanel_Killer2",
        localizationToken2: "#FreezePanel_Killer1");
    }
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: (CGameUiSetActiveSplitScreenPlayerGuard *)&pKiller);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1021A3F0
// Name: public: SFHudFreezePanel::SFHudFreezePanel(char const __near *)
// Source: json
//------------------------------------------------------------------------------
SFHudFreezePanel *__thiscall SFHudFreezePanel::SFHudFreezePanel(SFHudFreezePanel *this, const char *value)
{
  this->m_bRegisteredForEvents = false;
  this->m_nDebugID = 42;
  this->m_HudRenderGroups.m_Memory.m_pMemory = nullptr;
  this->m_HudRenderGroups.m_Memory.m_nAllocationCount = 0;
  this->m_HudRenderGroups.m_Memory.m_nGrowSize = 0;
  this->m_HudRenderGroups.m_Size = 0;
  this->m_HudRenderGroups.m_pElements = nullptr;
  this->m_bFlashAPIIsValid = false;
  this->m_iFlashSlot = -1;
  this->m_pScaleformUI = nullptr;
  this->m_FlashAPI = nullptr;
  this->__vftable = (SFHudFreezePanel_vtbl *)&SFHudFlashInterface::`vftable';
  CHudElement::InitCHudElementAfterConstruction(this, pElementName: value);
  this->__vftable = (SFHudFreezePanel_vtbl *)&SFHudFreezePanel::`vftable';
  CTraceFilterSkipTwoEntities::SetPassEntity2(
    (CTraceFilterSkipTwoEntities *)this,
    pPassEntity2: (const IHandleEntity *)0x40);
  this->m_dominationIcons[0] = nullptr;
  this->m_dominationIcons[1] = nullptr;
  this->m_dominationIcons[2] = nullptr;
  this->m_dominationText1 = nullptr;
  this->m_dominationText2 = nullptr;
  this->m_killerName = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1021A460
// Name: Create_SFHudFreezePanel
// Source: json
//------------------------------------------------------------------------------
SFHudFreezePanel *__cdecl Create_SFHudFreezePanel()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 96);
  memset(dst: v0, value: 0, count: 0x60u);
  if ( v0 != nullptr )
    return SFHudFreezePanel::SFHudFreezePanel(this: (SFHudFreezePanel *)v0, value: "SFHudFreezePanel");
  else
    return nullptr;
}
