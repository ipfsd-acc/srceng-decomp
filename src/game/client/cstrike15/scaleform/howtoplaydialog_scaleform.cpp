// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/howtoplaydialog_scaleform.cpp
// Functions: 5
// ============================================================

#include "game\client\cstrike15\scaleform\howtoplaydialog_scaleform.h"

//------------------------------------------------------------------------------
// Address: 0x1020B0F0
// Name: protected: virtual void CHowToPlayDialogScaleform::FlashLoaded(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHowToPlayDialogScaleform::FlashLoaded(CHowToPlayDialogScaleform *this)
{
  this->m_pScaleformUI->Value_InvokeWithoutReturn(
    this: this->m_pScaleformUI,
    a2: this->m_FlashAPI,
    a3: "InitDialogData",
    a4: nullptr,
    a5: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1020B110
// Name: protected: virtual void CHowToPlayDialogScaleform::PostUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHowToPlayDialogScaleform::PostUnloadFlash(CHowToPlayDialogScaleform *this)
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
  CHowToPlayDialogScaleform::m_pInstance = nullptr;
  if ( this != nullptr )
    ((void (__thiscall *)(CHowToPlayDialogScaleform *, int))this->dtr_ScaleformFlashInterfaceMixin<ScaleformEmptyClass>)(
      a1: this,
      a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1020B1E0
// Name: public: static void CHowToPlayDialogScaleform::UnloadDialog(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHowToPlayDialogScaleform::UnloadDialog()
{
  if ( CHowToPlayDialogScaleform::m_pInstance != nullptr && CHowToPlayDialogScaleform::m_pInstance->m_bFlashAPIIsValid )
    CHowToPlayDialogScaleform::m_pInstance->m_pScaleformUI->RemoveElement(
      this: CHowToPlayDialogScaleform::m_pInstance->m_pScaleformUI,
      a2: CHowToPlayDialogScaleform::m_pInstance->m_iFlashSlot,
      a3: CHowToPlayDialogScaleform::m_pInstance->m_FlashAPI);
}

//------------------------------------------------------------------------------
// Address: 0x1020B210
// Name: protected: virtual void CHowToPlayDialogScaleform::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CHowToPlayDialogScaleform::FlashReady(CCreateSinglePlayerGameDialogScaleform *this)
{
  CCreateSinglePlayerGameDialogScaleform::Show(this);
}

//------------------------------------------------------------------------------
// Address: 0x1020B220
// Name: public: static void CHowToPlayDialogScaleform::LoadDialog(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CHowToPlayDialogScaleform::LoadDialog()
{
  CHowToPlayDialogScaleform *v0; // eax

  if ( CHowToPlayDialogScaleform::m_pInstance == nullptr )
  {
    v0 = (CHowToPlayDialogScaleform *)MemAlloc_Alloc(nSize: 0x14u);
    if ( v0 != nullptr )
    {
      v0->m_bFlashAPIIsValid = false;
      v0->m_iFlashSlot = -1;
      v0->m_pScaleformUI = nullptr;
      v0->m_FlashAPI = nullptr;
      v0->__vftable = (CHowToPlayDialogScaleform_vtbl *)&CHowToPlayDialogScaleform::`vftable';
    }
    else
    {
      v0 = nullptr;
    }
    CHowToPlayDialogScaleform::m_pInstance = v0;
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: 1,
      a3: "HowToPlay",
      a4: (ScaleformUIFunctionHandlerObject *)v0,
      a5: pScaleformFunctionHandler_CHowToPlayDialogScaleform_HowToPlay);
  }
}
