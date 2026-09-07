// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/createsingleplayergamedialog_scaleform.cpp
// Functions: 8
// ============================================================

#include "game\client\cstrike15\scaleform\createsingleplayergamedialog_scaleform.h"

//------------------------------------------------------------------------------
// Address: 0x1020AB80
// Name: public: void CCreateSinglePlayerGameDialogScaleform::SetMatchmakingQuery(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateSinglePlayerGameDialogScaleform::SetMatchmakingQuery(
        CCreateSinglePlayerGameDialogScaleform *this,
        IScaleformUI *pui,
        void *obj)
{
  char *v4; // eax

  v4 = (char *)pui->Params_GetArgAsString(this: pui, a2: obj, a3: 0);
  V_strncpy(pDest: this->m_szMatchmakingQuery, pSrc: v4, maxLen: 2048);
}

//------------------------------------------------------------------------------
// Address: 0x1020ABB0
// Name: public: void CCreateSinglePlayerGameDialogScaleform::SetFreestyleBotDifficulty(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateSinglePlayerGameDialogScaleform::SetFreestyleBotDifficulty(
        CCreateSinglePlayerGameDialogScaleform *this,
        IScaleformUI *pui,
        void *obj)
{
  long double v3; // st7

  v3 = pui->Params_GetArgAsNumber(this: pui, a2: obj, a3: 0);
  g_pGameTypes->SetFreestyleBotDifficulty(this: g_pGameTypes, a2: (int)v3);
}

//------------------------------------------------------------------------------
// Address: 0x1020ABE0
// Name: protected: virtual void CCreateSinglePlayerGameDialogScaleform::FlashLoaded(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateSinglePlayerGameDialogScaleform::FlashLoaded(CCreateSinglePlayerGameDialogScaleform *this)
{
  void *v2; // edi

  v2 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: nInitDialogDataSize);
  this->m_pScaleformUI->ValueArray_SetElement_3(this: this->m_pScaleformUI, a2: v2, a3: 0, a4: this->m_bOnlineGame);
  this->m_pScaleformUI->Value_InvokeWithoutReturn(
    this: this->m_pScaleformUI,
    a2: this->m_FlashAPI,
    a3: "InitDialogData",
    a4: v2,
    a5: nInitDialogDataSize);
  this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v2, a3: nInitDialogDataSize);
}

//------------------------------------------------------------------------------
// Address: 0x1020AC50
// Name: public: void CCreateSinglePlayerGameDialogScaleform::OnOk(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateSinglePlayerGameDialogScaleform::OnOk(
        CCreateSinglePlayerGameDialogScaleform *this,
        IScaleformUI *pui,
        IScaleformUI *obj)
{
  IVEngineClient_vtbl *v3; // esi
  int v4; // eax
  char *v5; // eax

  v3 = engine->__vftable;
  v4 = C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass((vgui::CTreeViewListControl *)this);
  v5 = VarArgs(format: "host_writeconfig_ss %d", v4);
  v3->ClientCmd_Unrestricted(this: engine, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1020AC90
// Name: public: static void CCreateSinglePlayerGameDialogScaleform::UnloadDialog(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CCreateSinglePlayerGameDialogScaleform::UnloadDialog()
{
  if ( CCreateSinglePlayerGameDialogScaleform::m_pInstance != nullptr
    && CCreateSinglePlayerGameDialogScaleform::m_pInstance->m_bFlashAPIIsValid )
  {
    CCreateSinglePlayerGameDialogScaleform::m_pInstance->m_pScaleformUI->RemoveElement(
      this: CCreateSinglePlayerGameDialogScaleform::m_pInstance->m_pScaleformUI,
      a2: CCreateSinglePlayerGameDialogScaleform::m_pInstance->m_iFlashSlot,
      a3: CCreateSinglePlayerGameDialogScaleform::m_pInstance->m_FlashAPI);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020ACC0
// Name: protected: virtual void CCreateSinglePlayerGameDialogScaleform::PostUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateSinglePlayerGameDialogScaleform::PostUnloadFlash(CCreateSinglePlayerGameDialogScaleform *this)
{
  CCStrike15BasePanel *v2; // eax
  CCStrike15BasePanel *v3; // eax
  KeyValues *v4; // ebx
  CCStrike15BasePanel *v5; // eax
  IMatchSession *v6; // edi
  KeyValues *v7; // eax
  KeyValues *v8; // ebx
  CCStrike15BasePanel *v9; // eax
  KeyValues *pSettings; // [esp+8h] [ebp-8h]
  bool v11; // [esp+Ch] [ebp-4h]

  g_pScaleformUI->RefreshKeyBindings(this: g_pScaleformUI);
  if ( this->m_szMatchmakingQuery[0] == 0 )
  {
    v2 = BasePanel();
    v2->RestoreMainMenuScreen(this: v2);
  }
  if ( this->m_bOnlineGame )
  {
    v3 = BasePanel();
    v3->RestoreMainMenuScreen(this: v3);
  }
  else if ( this->m_szMatchmakingQuery[0] != 0 )
  {
    v4 = KeyValues::FromString(
           szName: "Settings",
           szStringVal: (KeyValues *)this->m_szMatchmakingQuery,
           ppEndOfParse: nullptr);
    pSettings = v4;
    v11 = !this->m_bOnlineGame;
    BasePanel()->m_bSinglePlayer = v11;
    if ( this->m_bOnlineGame )
    {
      v5 = BasePanel();
      v5->ShowMatchmakingStatus(this: v5);
      g_pMatchFramework->MatchSession(this: g_pMatchFramework, a2: v4);
    }
    else
    {
      g_pMatchFramework->CreateSession(this: g_pMatchFramework, a2: v4);
      v6 = g_pMatchFramework->GetMatchSession(this: g_pMatchFramework);
      if ( v6 != nullptr )
      {
        v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v7 != nullptr )
          v8 = KeyValues::KeyValues(this: v7, setName: "Start");
        else
          v8 = nullptr;
        v6->Command(this: v6, a2: v8);
        if ( v8 != nullptr )
          KeyValues::deleteThis(this: v8);
        v4 = pSettings;
      }
      else
      {
        _Warning(a1: "CCreateSinglePlayerGameDialogScaleform: unable to create single player session.\n");
        v9 = BasePanel();
        v9->RestoreMainMenuScreen(this: v9);
      }
    }
    if ( v4 != nullptr )
      KeyValues::deleteThis(this: v4);
  }
  CCreateSinglePlayerGameDialogScaleform::m_pInstance = nullptr;
  ((void (__thiscall *)(CCreateSinglePlayerGameDialogScaleform *, int))this->dtr_ScaleformFlashInterfaceMixin<ScaleformEmptyClass>)(
    a1: this,
    a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1020AE20
// Name: public: static void CCreateSinglePlayerGameDialogScaleform::LoadDialog(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CCreateSinglePlayerGameDialogScaleform::LoadDialog(bool bMatchmakingFilter)
{
  CCreateSinglePlayerGameDialogScaleform *v1; // eax

  if ( CCreateSinglePlayerGameDialogScaleform::m_pInstance == nullptr )
  {
    v1 = (CCreateSinglePlayerGameDialogScaleform *)MemAlloc_Alloc(nSize: 0x818u);
    if ( v1 != nullptr )
    {
      v1->m_bFlashAPIIsValid = false;
      v1->m_iFlashSlot = -1;
      v1->m_pScaleformUI = nullptr;
      v1->m_FlashAPI = nullptr;
      v1->__vftable = (CCreateSinglePlayerGameDialogScaleform_vtbl *)&CCreateSinglePlayerGameDialogScaleform::`vftable';
      v1->m_szMatchmakingQuery[0] = 0;
      v1->m_bOnlineGame = bMatchmakingFilter;
    }
    else
    {
      v1 = nullptr;
    }
    CCreateSinglePlayerGameDialogScaleform::m_pInstance = v1;
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: 1,
      a3: "StartSinglePlayer",
      a4: (ScaleformUIFunctionHandlerObject *)v1,
      a5: pScaleformFunctionHandler_CCreateSinglePlayerGameDialogScaleform_StartSinglePlayer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020B180
// Name: protected: void CCreateSinglePlayerGameDialogScaleform::Show(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateSinglePlayerGameDialogScaleform::Show(CCreateSinglePlayerGameDialogScaleform *this)
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
