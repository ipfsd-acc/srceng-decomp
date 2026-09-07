// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/leaderboardsdialog_scaleform.cpp
// Functions: 9
// ============================================================

#include "game\client\cstrike15\scaleform\leaderboardsdialog_scaleform.h"

//------------------------------------------------------------------------------
// Address: 0x1020B2C0
// Name: public: static void CCreateLeaderboardsDialogScaleform::UpdateDialog(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CCreateLeaderboardsDialogScaleform::UpdateDialog()
{
  if ( CCreateLeaderboardsDialogScaleform::m_pInstance != nullptr )
    CCreateLeaderboardsDialogScaleform::m_pInstance->Tick(this: CCreateLeaderboardsDialogScaleform::m_pInstance);
}

//------------------------------------------------------------------------------
// Address: 0x1020B2E0
// Name: protected: virtual void CCreateLeaderboardsDialogScaleform::PostUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateLeaderboardsDialogScaleform::PostUnloadFlash(CCreateLeaderboardsDialogScaleform *this)
{
  CGameUI *v2; // eax
  CCStrike15BasePanel *v3; // ecx
  CCStrike15BasePanel *v4; // ecx

  v2 = GameUI();
  if ( v2->IsInLevel(this: v2) )
  {
    v3 = BasePanel();
    v3->RestorePauseMenu(this: v3);
  }
  else
  {
    v4 = BasePanel();
    v4->RestoreMainMenuScreen(this: v4);
  }
  CCreateLeaderboardsDialogScaleform::m_pInstance = nullptr;
  if ( this != nullptr )
    ((void (__thiscall *)(CCreateLeaderboardsDialogScaleform *, int))this->dtr_ScaleformFlashInterfaceMixin<ScaleformEmptyClass>)(
      a1: this,
      a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1020B340
// Name: public: void CCreateLeaderboardsDialogScaleform::Query_GetCurrentPlayerRow(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateLeaderboardsDialogScaleform::Query_GetCurrentPlayerRow(
        CCreateLeaderboardsDialogScaleform *this,
        IScaleformUI *pui,
        void *obj)
{
  this->m_pScaleformUI->Params_SetResult_5(this: this->m_pScaleformUI, a2: obj, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1020B370
// Name: protected: virtual void CCreateLeaderboardsDialogScaleform::FlashLoaded(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateLeaderboardsDialogScaleform::FlashLoaded(CCreateLeaderboardsDialogScaleform *this)
{
  if ( this->m_bFlashAPIIsValid )
    this->m_pScaleformUI->Value_InvokeWithoutReturn(
      this: this->m_pScaleformUI,
      a2: this->m_FlashAPI,
      a3: "InitDialogData",
      a4: nullptr,
      a5: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1020B400
// Name: public: static void CCreateLeaderboardsDialogScaleform::UnloadDialog(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CCreateLeaderboardsDialogScaleform::UnloadDialog()
{
  if ( CCreateLeaderboardsDialogScaleform::m_pInstance != nullptr
    && CCreateLeaderboardsDialogScaleform::m_pInstance->m_bFlashAPIIsValid )
  {
    CCreateLeaderboardsDialogScaleform::m_pInstance->m_pScaleformUI->RemoveElement(
      this: CCreateLeaderboardsDialogScaleform::m_pInstance->m_pScaleformUI,
      a2: CCreateLeaderboardsDialogScaleform::m_pInstance->m_iFlashSlot,
      a3: CCreateLeaderboardsDialogScaleform::m_pInstance->m_FlashAPI);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020B430
// Name: public: void CCreateLeaderboardsDialogScaleform::OnOk(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateLeaderboardsDialogScaleform::OnOk(
        CCreateLeaderboardsDialogScaleform *this,
        IScaleformUI *pui,
        IScaleformUI *obj)
{
  if ( CCreateLeaderboardsDialogScaleform::m_pInstance != nullptr
    && CCreateLeaderboardsDialogScaleform::m_pInstance->m_bFlashAPIIsValid )
  {
    CCreateLeaderboardsDialogScaleform::m_pInstance->m_pScaleformUI->RemoveElement(
      this: CCreateLeaderboardsDialogScaleform::m_pInstance->m_pScaleformUI,
      a2: CCreateLeaderboardsDialogScaleform::m_pInstance->m_iFlashSlot,
      a3: CCreateLeaderboardsDialogScaleform::m_pInstance->m_FlashAPI);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020B460
// Name: protected: virtual void CCreateLeaderboardsDialogScaleform::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateLeaderboardsDialogScaleform::FlashReady(CCreateLeaderboardsDialogScaleform *this)
{
  void *v2; // edi
  void *v3; // eax

  v2 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: this->m_FlashAPI, a3: "ScoreBoard");
  if ( v2 != nullptr )
  {
    v3 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v2, a3: "Panel");
    if ( v3 != nullptr )
      this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v3);
    this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v2);
  }
  *(_WORD *)&this->m_bCheckForQueryResults = 0;
  this->m_iNumFriends = 0;
  this->m_iNextFriend = -1;
  CCreateMedalStatsDialogScaleform::Show(this);
}

//------------------------------------------------------------------------------
// Address: 0x1020B4D0
// Name: protected: CCreateLeaderboardsDialogScaleform::CCreateLeaderboardsDialogScaleform(void)
// Source: json
//------------------------------------------------------------------------------
CCreateLeaderboardsDialogScaleform *__thiscall CCreateLeaderboardsDialogScaleform::CCreateLeaderboardsDialogScaleform(
        CCreateLeaderboardsDialogScaleform *this)
{
  this->m_bFlashAPIIsValid = false;
  this->m_iFlashSlot = -1;
  this->m_pScaleformUI = nullptr;
  this->m_FlashAPI = nullptr;
  this->__vftable = (CCreateLeaderboardsDialogScaleform_vtbl *)&CCreateLeaderboardsDialogScaleform::`vftable';
  this->m_hAsyncQuery = nullptr;
  *(_WORD *)&this->m_bCheckForQueryResults = 0;
  this->m_iTotalViewRows = 0;
  this->m_iNumFriends = 0;
  this->m_iNextFriend = -1;
  this->m_bEnumeratingFriends = false;
  this->m_currentFilterType = eLBFilter_Overall;
  this->m_startingRowIndex = -1;
  this->m_rowsPerPage = 0;
  this->m_iPlayerSlot = C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass(this: (vgui::CTreeViewListControl *)0xFFFFFFFF);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1020B520
// Name: public: static void CCreateLeaderboardsDialogScaleform::LoadDialog(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CCreateLeaderboardsDialogScaleform::LoadDialog()
{
  CCreateLeaderboardsDialogScaleform *v0; // eax
  CCreateLeaderboardsDialogScaleform *v1; // eax

  if ( CCreateLeaderboardsDialogScaleform::m_pInstance == nullptr )
  {
    v0 = (CCreateLeaderboardsDialogScaleform *)MemAlloc_Alloc(nSize: 0x40u);
    if ( v0 != nullptr )
      v1 = CCreateLeaderboardsDialogScaleform::CCreateLeaderboardsDialogScaleform(this: v0);
    else
      v1 = nullptr;
    CCreateLeaderboardsDialogScaleform::m_pInstance = v1;
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: 1,
      a3: "LeaderBoards",
      a4: (ScaleformUIFunctionHandlerObject *)v1,
      a5: pScaleformFunctionHandler_CCreateLeaderboardsDialogScaleform_LeaderBoards);
  }
}
