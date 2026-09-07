// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/hud/sfhudreticle.cpp
// Functions: 12
// ============================================================

#include "game\client\cstrike15\scaleform\hud\sfhudreticle.h"

//------------------------------------------------------------------------------
// Address: 0x10221580
// Name: protected: bool SFHudReticle::SetReticleGap(int,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SFHudReticle::SetReticleGap(SFHudReticle *this, int distance, int crosshairGap)
{
  char v4; // bl
  IScaleformUI *m_pScaleformUI; // ecx
  IScaleformUI *v6; // ecx
  double m_ULBoxY; // xmm1_8
  void *m_ULBox; // eax
  void (__thiscall *Value_SetDisplayInfo)(IScaleformUI *, void *, const ScaleformDisplayInfo *); // edx
  IScaleformUI *v10; // ecx
  long double v11; // xmm1_8
  void *m_URBox; // edx
  IScaleformUI *v13; // ecx
  long double v14; // xmm1_8
  void *m_LLBox; // eax
  IScaleformUI *v16; // ecx
  long double v17; // xmm1_8
  void *m_LRBox; // edx
  IScaleformUI *v19; // ecx
  IScaleformUI *v20; // ecx
  long double v21; // xmm1_8
  void *m_TopPip; // edx
  void (__thiscall *v23)(IScaleformUI *, void *, const ScaleformDisplayInfo *); // eax
  long double v24; // xmm0_8
  IScaleformUI *v25; // ecx
  void *m_BottomPip; // eax
  long double v27; // xmm0_8
  IScaleformUI *v28; // ecx
  void *m_LeftPip; // edx
  long double v30; // xmm0_8
  IScaleformUI *v31; // ecx
  void *m_RightPip; // eax
  IScaleformUI *v33; // ecx
  ScaleformDisplayInfo dinfo; // [esp+8h] [ebp-44h] BYREF
  double v36; // [esp+40h] [ebp-Ch]
  bool bSlotIsLocked; // [esp+4Bh] [ebp-1h]

  v4 = 0;
  if ( this->m_WeaponCrosshairHandle != nullptr )
  {
    dinfo.m_iSetFlags = 0;
    bSlotIsLocked = false;
    if ( distance != this->m_iLastSpread )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      v6 = this->m_pScaleformUI;
      dinfo.m_fX = this->m_ULBoxX - (double)distance;
      m_ULBoxY = this->m_ULBoxY;
      dinfo.m_iSetFlags |= 3u;
      m_ULBox = this->m_ULBox;
      dinfo.m_fY = m_ULBoxY - (double)distance;
      Value_SetDisplayInfo = v6->Value_SetDisplayInfo;
      bSlotIsLocked = true;
      v36 = (double)distance;
      Value_SetDisplayInfo(this: v6, a2: m_ULBox, a3: &dinfo);
      v10 = this->m_pScaleformUI;
      dinfo.m_fX = this->m_URBoxX + v36;
      v11 = this->m_URBoxY - v36;
      dinfo.m_iSetFlags |= 3u;
      m_URBox = this->m_URBox;
      dinfo.m_fY = v11;
      v10->Value_SetDisplayInfo(this: v10, a2: m_URBox, a3: &dinfo);
      v13 = this->m_pScaleformUI;
      dinfo.m_fX = this->m_LLBoxX - v36;
      v14 = this->m_LLBoxY + v36;
      dinfo.m_iSetFlags |= 3u;
      m_LLBox = this->m_LLBox;
      dinfo.m_fY = v14;
      v13->Value_SetDisplayInfo(this: v13, a2: m_LLBox, a3: &dinfo);
      v16 = this->m_pScaleformUI;
      dinfo.m_fX = this->m_LRBoxX + v36;
      v17 = this->m_LRBoxY + v36;
      dinfo.m_iSetFlags |= 3u;
      m_LRBox = this->m_LRBox;
      dinfo.m_fY = v17;
      v16->Value_SetDisplayInfo(this: v16, a2: m_LRBox, a3: &dinfo);
      this->m_iLastSpread = distance;
      v4 = 1;
    }
    if ( crosshairGap != this->m_iLastGap )
    {
      if ( !bSlotIsLocked )
      {
        v19 = this->m_pScaleformUI;
        if ( v19 != nullptr )
          v19->LockSlot(this: v19, a2: this->m_iFlashSlot);
        bSlotIsLocked = true;
      }
      v20 = this->m_pScaleformUI;
      v4 = 1;
      v21 = this->m_TopPipY - (double)crosshairGap;
      m_TopPip = this->m_TopPip;
      dinfo.m_iSetFlags = 2;
      dinfo.m_fY = v21;
      v23 = v20->Value_SetDisplayInfo;
      v36 = (double)crosshairGap;
      v23(this: v20, a2: m_TopPip, a3: &dinfo);
      v24 = this->m_BottomPipY + v36;
      v25 = this->m_pScaleformUI;
      dinfo.m_iSetFlags |= 2u;
      m_BottomPip = this->m_BottomPip;
      dinfo.m_fY = v24;
      v25->Value_SetDisplayInfo(this: v25, a2: m_BottomPip, a3: &dinfo);
      v27 = this->m_LeftPipX - v36;
      v28 = this->m_pScaleformUI;
      m_LeftPip = this->m_LeftPip;
      dinfo.m_iSetFlags = 1;
      dinfo.m_fX = v27;
      v28->Value_SetDisplayInfo(this: v28, a2: m_LeftPip, a3: &dinfo);
      v30 = this->m_RightPipX + v36;
      v31 = this->m_pScaleformUI;
      dinfo.m_iSetFlags |= 1u;
      m_RightPip = this->m_RightPip;
      dinfo.m_fX = v30;
      v31->Value_SetDisplayInfo(this: v31, a2: m_RightPip, a3: &dinfo);
    }
    if ( bSlotIsLocked )
    {
      v33 = this->m_pScaleformUI;
      if ( v33 != nullptr )
        v33->UnlockSlot(this: v33, a2: this->m_iFlashSlot);
    }
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10221820
// Name: public: virtual bool SFHudReticle::PreUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SFHudReticle::PreUnloadFlash(SFHudReticle *this)
{
  if ( this->m_pScaleformUI != nullptr )
  {
    if ( this->m_WeaponCrosshairHandle != nullptr )
    {
      this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_WeaponCrosshairHandle);
      this->m_WeaponCrosshairHandle = nullptr;
    }
    if ( this->m_pScaleformUI != nullptr )
    {
      if ( this->m_ObserverCrosshairHandle != nullptr )
      {
        this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_ObserverCrosshairHandle);
        this->m_ObserverCrosshairHandle = nullptr;
      }
      if ( this->m_pScaleformUI != nullptr )
      {
        if ( this->m_TopPip != nullptr )
        {
          this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_TopPip);
          this->m_TopPip = nullptr;
        }
        if ( this->m_pScaleformUI != nullptr )
        {
          if ( this->m_BottomPip != nullptr )
          {
            this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_BottomPip);
            this->m_BottomPip = nullptr;
          }
          if ( this->m_pScaleformUI != nullptr )
          {
            if ( this->m_LeftPip != nullptr )
            {
              this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_LeftPip);
              this->m_LeftPip = nullptr;
            }
            if ( this->m_pScaleformUI != nullptr )
            {
              if ( this->m_RightPip != nullptr )
              {
                this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_RightPip);
                this->m_RightPip = nullptr;
              }
              if ( this->m_pScaleformUI != nullptr )
              {
                if ( this->m_ULBox != nullptr )
                {
                  this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_ULBox);
                  this->m_ULBox = nullptr;
                }
                if ( this->m_pScaleformUI != nullptr )
                {
                  if ( this->m_URBox != nullptr )
                  {
                    this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_URBox);
                    this->m_URBox = nullptr;
                  }
                  if ( this->m_pScaleformUI != nullptr )
                  {
                    if ( this->m_LLBox != nullptr )
                    {
                      this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_LLBox);
                      this->m_LLBox = nullptr;
                    }
                    if ( this->m_pScaleformUI != nullptr )
                    {
                      if ( this->m_LRBox != nullptr )
                      {
                        this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_LRBox);
                        this->m_LRBox = nullptr;
                      }
                      if ( this->m_pScaleformUI != nullptr )
                      {
                        if ( this->m_FriendCrosshair != nullptr )
                        {
                          this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_FriendCrosshair);
                          this->m_FriendCrosshair = nullptr;
                        }
                        if ( this->m_pScaleformUI != nullptr )
                        {
                          if ( this->m_IDMovie != nullptr )
                          {
                            this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_IDMovie);
                            this->m_IDMovie = nullptr;
                          }
                          if ( this->m_pScaleformUI != nullptr && this->m_IDText != nullptr )
                          {
                            this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: this->m_IDText);
                            this->m_IDText = nullptr;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10221A20
// Name: protected: void SFHudReticle::ResetDisplay(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudReticle::ResetDisplay(SFHudReticle *this)
{
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  void *m_IDMovie; // eax
  void *m_FriendCrosshair; // eax
  void *m_WeaponCrosshairHandle; // eax
  void *m_ObserverCrosshairHandle; // eax

  for ( i = 1; ; i = 0 )
  {
    m_pScaleformUI = this->m_pScaleformUI;
    if ( i == 0 )
      break;
    if ( m_pScaleformUI != nullptr )
      m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
    m_IDMovie = this->m_IDMovie;
    if ( m_IDMovie != nullptr )
      this->m_pScaleformUI->Value_InvokeWithoutReturn(
        this: this->m_pScaleformUI,
        a2: m_IDMovie,
        a3: "HideNow",
        a4: nullptr,
        a5: 0);
    m_FriendCrosshair = this->m_FriendCrosshair;
    if ( m_FriendCrosshair != nullptr )
      this->m_pScaleformUI->Value_SetVisible(this: this->m_pScaleformUI, a2: m_FriendCrosshair, a3: false);
    m_WeaponCrosshairHandle = this->m_WeaponCrosshairHandle;
    if ( m_WeaponCrosshairHandle != nullptr )
      this->m_pScaleformUI->Value_SetVisible(this: this->m_pScaleformUI, a2: m_WeaponCrosshairHandle, a3: false);
    m_ObserverCrosshairHandle = this->m_ObserverCrosshairHandle;
    if ( m_ObserverCrosshairHandle != nullptr )
      this->m_pScaleformUI->Value_SetVisible(this: this->m_pScaleformUI, a2: m_ObserverCrosshairHandle, a3: false);
  }
  if ( m_pScaleformUI != nullptr )
    m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
  this->m_fIDTimer = 0.0;
  *(_WORD *)&this->m_bTextIDVisible = 0;
  this->m_iReticleMode = RETICLE_MODE_NONE;
}

//------------------------------------------------------------------------------
// Address: 0x10221AF0
// Name: public: virtual void SFHudReticle::LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudReticle::LevelInit(SFHudReticle *this)
{
  if ( this->m_bFlashAPIIsValid )
    SFHudReticle::ResetDisplay(this);
  else
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: 2,
      a3: "Reticle",
      a4: (ScaleformUIFunctionHandlerObject *)this,
      a5: pScaleformFunctionHandler_SFHudReticle_Reticle);
}

//------------------------------------------------------------------------------
// Address: 0x10221B20
// Name: public: virtual void SFHudReticle::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SFHudReticle::SetActive(SFHudReticle *this@<ecx>, int a2@<edi>, bool bActive)
{
  void *v4; // edi
  char i; // al
  SplitScreenSlottedConVarRef convar; // [esp+14h] [ebp-18h] BYREF
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+28h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iFlashSlot - 2);
  if ( bActive )
  {
    if ( !this->m_bActive )
    {
      v4 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
      if ( v4 != nullptr )
      {
        SplitScreenConVarRef::SplitScreenConVarRef(this: &convar, pName: "cl_crosshaircolor");
        convar.m_iSlot = 0;
        ((void (__thiscall *)(IScaleformUI *, void *, _DWORD, _DWORD, int))g_pScaleformUI->ValueArray_SetElement_4)(
          a1: g_pScaleformUI,
          a2: v4,
          a3: 0,
          a4: LODWORD(convar.m_Info[0].m_pConVarState->m_Value.m_fValue),
          a5: a2);
        for ( i = 1; i != 0; i = 0 )
        {
          if ( this->m_pScaleformUI != nullptr )
            this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
          g_pScaleformUI->Value_InvokeWithoutReturn(
            this: g_pScaleformUI,
            a2: this->m_FlashAPI,
            a3: "onUpdateColor",
            a4: v4,
            a5: 1u);
        }
        if ( this->m_pScaleformUI != nullptr )
          this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
        ((void (__thiscall *)(IScaleformUI *, void *))this->m_pScaleformUI->ReleaseValueArray)(
          a1: this->m_pScaleformUI,
          a2: v4);
      }
    }
  }
  else if ( this->m_bActive )
  {
    SFHudReticle::ResetDisplay(this);
  }
  CHudElement::SetActive(this, bActive);
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10221C30
// Name: protected: void SFHudReticle::PerformSwapReticle(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SFHudReticle::PerformSwapReticle(SFHudReticle *this@<ecx>, int a2@<edi>, const char *szReticleName)
{
  IScaleformUI *m_pScaleformUI; // ecx
  IScaleformUI *v5; // ecx
  IScaleformUI *v6; // ecx
  IScaleformUI *v7; // ecx
  IScaleformUI *v8; // ecx
  IScaleformUI *v9; // ecx
  IScaleformUI *v10; // ecx
  IScaleformUI *v11; // ecx
  IScaleformUI *v12; // ecx
  IScaleformUI *v13; // ecx
  void *v14; // eax
  IScaleformUI *v15; // ecx
  void *v16; // eax
  IScaleformUI *v17; // ecx
  void *v18; // eax
  void *v19; // eax
  void *v20; // eax
  void *v21; // eax
  void *v22; // eax
  void *v23; // eax
  void *v24; // eax
  void *v25; // eax
  void *m_FriendCrosshair; // eax
  int m_iLastSpread; // [esp-8h] [ebp-48h]
  int m_iLastGap; // [esp-4h] [ebp-44h]
  ScaleformDisplayInfo dinfo; // [esp+8h] [ebp-38h] BYREF

  m_pScaleformUI = this->m_pScaleformUI;
  if ( m_pScaleformUI != nullptr && this->m_WeaponCrosshairHandle != nullptr )
  {
    m_pScaleformUI->ReleaseValue(this: m_pScaleformUI, a2: this->m_WeaponCrosshairHandle);
    this->m_WeaponCrosshairHandle = nullptr;
  }
  v5 = this->m_pScaleformUI;
  if ( v5 != nullptr && this->m_FriendCrosshair != nullptr )
  {
    v5->ReleaseValue(this: v5, a2: this->m_FriendCrosshair);
    this->m_FriendCrosshair = nullptr;
  }
  v6 = this->m_pScaleformUI;
  if ( v6 != nullptr && this->m_TopPip != nullptr )
  {
    v6->ReleaseValue(this: v6, a2: this->m_TopPip);
    this->m_TopPip = nullptr;
  }
  v7 = this->m_pScaleformUI;
  if ( v7 != nullptr && this->m_BottomPip != nullptr )
  {
    v7->ReleaseValue(this: v7, a2: this->m_BottomPip);
    this->m_BottomPip = nullptr;
  }
  v8 = this->m_pScaleformUI;
  if ( v8 != nullptr && this->m_LeftPip != nullptr )
  {
    v8->ReleaseValue(this: v8, a2: this->m_LeftPip);
    this->m_LeftPip = nullptr;
  }
  v9 = this->m_pScaleformUI;
  if ( v9 != nullptr && this->m_RightPip != nullptr )
  {
    v9->ReleaseValue(this: v9, a2: this->m_RightPip);
    this->m_RightPip = nullptr;
  }
  v10 = this->m_pScaleformUI;
  if ( v10 != nullptr && this->m_ULBox != nullptr )
  {
    v10->ReleaseValue(this: v10, a2: this->m_ULBox);
    this->m_ULBox = nullptr;
  }
  v11 = this->m_pScaleformUI;
  if ( v11 != nullptr && this->m_URBox != nullptr )
  {
    v11->ReleaseValue(this: v11, a2: this->m_URBox);
    this->m_URBox = nullptr;
  }
  v12 = this->m_pScaleformUI;
  if ( v12 != nullptr && this->m_LLBox != nullptr )
  {
    v12->ReleaseValue(this: v12, a2: this->m_LLBox);
    this->m_LLBox = nullptr;
  }
  v13 = this->m_pScaleformUI;
  if ( v13 != nullptr && this->m_LRBox != nullptr )
  {
    v13->ReleaseValue(this: v13, a2: this->m_LRBox);
    this->m_LRBox = nullptr;
  }
  v14 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: this->m_FlashAPI, a3: szReticleName);
  this->m_WeaponCrosshairHandle = v14;
  if ( v14 != nullptr )
  {
    v15 = this->m_pScaleformUI;
    dinfo.m_iSetFlags = 0;
    v16 = (void *)((int (__thiscall *)(IScaleformUI *, void *, const char *, int))v15->Value_GetMember)(
                    a1: v15,
                    a2: v14,
                    a3: "FriendCrosshair",
                    a4: a2);
    v17 = this->m_pScaleformUI;
    this->m_FriendCrosshair = v16;
    v18 = v17->Value_GetMember(this: v17, a2: this->m_WeaponCrosshairHandle, a3: "TopPip");
    this->m_TopPip = v18;
    if ( v18 != nullptr )
    {
      this->m_pScaleformUI->Value_GetDisplayInfo(this: this->m_pScaleformUI, a2: v18, a3: &dinfo);
      this->m_TopPipY = 0.0;
    }
    v19 = this->m_pScaleformUI->Value_GetMember(
            this: this->m_pScaleformUI,
            a2: this->m_WeaponCrosshairHandle,
            a3: "BottomPip");
    this->m_BottomPip = v19;
    if ( v19 != nullptr )
    {
      this->m_pScaleformUI->Value_GetDisplayInfo(this: this->m_pScaleformUI, a2: v19, a3: &dinfo);
      this->m_BottomPipY = 0.0;
    }
    v20 = this->m_pScaleformUI->Value_GetMember(
            this: this->m_pScaleformUI,
            a2: this->m_WeaponCrosshairHandle,
            a3: "LeftPip");
    this->m_LeftPip = v20;
    if ( v20 != nullptr )
    {
      this->m_pScaleformUI->Value_GetDisplayInfo(this: this->m_pScaleformUI, a2: v20, a3: &dinfo);
      this->m_LeftPipX = 0.0;
    }
    v21 = this->m_pScaleformUI->Value_GetMember(
            this: this->m_pScaleformUI,
            a2: this->m_WeaponCrosshairHandle,
            a3: "RightPip");
    this->m_RightPip = v21;
    if ( v21 != nullptr )
    {
      this->m_pScaleformUI->Value_GetDisplayInfo(this: this->m_pScaleformUI, a2: v21, a3: &dinfo);
      this->m_RightPipX = 0.0;
    }
    v22 = this->m_pScaleformUI->Value_GetMember(
            this: this->m_pScaleformUI,
            a2: this->m_WeaponCrosshairHandle,
            a3: "ULBox");
    this->m_ULBox = v22;
    if ( v22 != nullptr )
    {
      this->m_pScaleformUI->Value_GetDisplayInfo(this: this->m_pScaleformUI, a2: v22, a3: &dinfo);
      this->m_ULBoxX = 0.0;
      this->m_ULBoxY = 0.0;
    }
    v23 = this->m_pScaleformUI->Value_GetMember(
            this: this->m_pScaleformUI,
            a2: this->m_WeaponCrosshairHandle,
            a3: "URBox");
    this->m_URBox = v23;
    if ( v23 != nullptr )
    {
      this->m_pScaleformUI->Value_GetDisplayInfo(this: this->m_pScaleformUI, a2: v23, a3: &dinfo);
      this->m_URBoxX = 0.0;
      this->m_URBoxY = 0.0;
    }
    v24 = this->m_pScaleformUI->Value_GetMember(
            this: this->m_pScaleformUI,
            a2: this->m_WeaponCrosshairHandle,
            a3: "LLBox");
    this->m_LLBox = v24;
    if ( v24 != nullptr )
    {
      this->m_pScaleformUI->Value_GetDisplayInfo(this: this->m_pScaleformUI, a2: v24, a3: &dinfo);
      this->m_LLBoxX = 0.0;
      this->m_LLBoxY = 0.0;
    }
    v25 = (void *)((int (__thiscall *)(IScaleformUI *, void *))this->m_pScaleformUI->Value_GetMember)(
                    a1: this->m_pScaleformUI,
                    a2: this->m_WeaponCrosshairHandle);
    this->m_LRBox = v25;
    if ( v25 != nullptr )
    {
      this->m_pScaleformUI->Value_GetDisplayInfo(this: this->m_pScaleformUI, a2: v25, a3: &dinfo);
      this->m_LRBoxX = 0.0;
      this->m_LRBoxY = 0.0;
    }
  }
  m_FriendCrosshair = this->m_FriendCrosshair;
  if ( m_FriendCrosshair != nullptr )
    this->m_pScaleformUI->Value_SetVisible(this: this->m_pScaleformUI, a2: m_FriendCrosshair, a3: false);
  m_iLastGap = this->m_iLastGap;
  m_iLastSpread = this->m_iLastSpread;
  this->m_bFriendlyCrosshairVisible = false;
  this->m_iReticleMode = RETICLE_MODE_NONE;
  SFHudReticle::SetReticleGap(this, distance: m_iLastSpread, crosshairGap: m_iLastGap);
}

//------------------------------------------------------------------------------
// Address: 0x10222040
// Name: public: virtual void SFHudReticle::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudReticle::FireGameEvent(SFHudReticle *this, IGameEvent *event)
{
  const char *v3; // eax
  int v4; // eax
  C_BasePlayer *v5; // eax
  int v6; // edi
  char i; // al

  v3 = event->GetName(this: event);
  if ( _V_strcmp(s1: v3, s2: "player_death") == 0 )
  {
    v4 = event->GetInt(this: event, a2: "userid", a3: 0);
    v5 = UTIL_PlayerByUserId(userID: v4);
    if ( v5 != nullptr )
    {
      v6 = v5->entindex(this: &v5->IClientNetworkable);
      if ( v6 == GetLocalPlayerIndex() && this->m_IDMovie != nullptr )
      {
        for ( i = 1; i != 0; i = 0 )
        {
          if ( this->m_pScaleformUI != nullptr )
            this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
          this->m_pScaleformUI->Value_InvokeWithoutReturn(
            this: this->m_pScaleformUI,
            a2: this->m_IDMovie,
            a3: "HideNow",
            a4: nullptr,
            a5: 0);
        }
        if ( this->m_pScaleformUI != nullptr )
          this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10222100
// Name: public: virtual void SFHudReticle::ProcessInput(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudReticle::ProcessInput(SFHudReticle *this)
{
  C_CSPlayer *LocalPlayer; // ebx
  int v3; // eax
  C_WeaponCSBase *v4; // eax
  C_WeaponCSBase *v5; // edi
  int IDTarget; // eax
  int v7; // edi
  C_BasePlayer *BaseEntity; // ebx
  bool v9; // al
  bool IsControllingBot; // bl
  C_CS_PlayerResource *v11; // eax
  vgui::ILocalize_vtbl *v12; // edi
  const char *PlayerName; // eax
  const char *v14; // ebx
  C_BasePlayer *v15; // edi
  int (__thiscall *GetHealth)(C_BaseEntity *); // edx
  int v17; // eax
  int (__thiscall *v18)(C_BaseEntity *); // edx
  int v19; // eax
  vgui::ILocalize_vtbl *v20; // edi
  int v21; // eax
  C_BasePlayer *v22; // edi
  IScaleformUI *m_pScaleformUI; // ecx
  void *(__thiscall *CreateValueArray)(IScaleformUI *, unsigned int); // eax
  void *v25; // edi
  char i; // al
  IScaleformUI *v27; // ecx
  C_CHostage *v28; // eax
  int v29; // ecx
  C_CHostage *v30; // edi
  float v31; // xmm0_4
  int (__thiscall *GetMaxHealth)(C_BaseEntity *); // eax
  int v33; // eax
  int v34; // eax
  IScaleformUI *v35; // ecx
  void *v36; // edi
  IConVar *m_pConVar; // eax
  char j; // al
  IScaleformUI *v39; // ecx
  int TargetedWeapon; // eax
  C_BaseEntity *v41; // eax
  C_BaseEntity *v42; // edi
  const char *v43; // eax
  char v44; // bl
  IScaleformUI *v45; // ecx
  IScaleformUI *v46; // ecx
  bool v47; // zf
  IScaleformUI *v48; // ecx
  IScaleformUI *v49; // ecx
  IScaleformUI *v50; // ecx
  SFHudReticle::RETICLE_MODE v51; // edi
  IScaleformUI *v52; // ecx
  void *m_WeaponCrosshairHandle; // eax
  void *m_ObserverCrosshairHandle; // eax
  IScaleformUI *v55; // ecx
  void *p_convar; // [esp+18h] [ebp-288h]
  wchar_t wcNewString[256]; // [esp+28h] [ebp-278h] BYREF
  wchar_t wszPlayerName[32]; // [esp+228h] [ebp-78h] BYREF
  CGameUIConVarRef convar; // [esp+268h] [ebp-38h] BYREF
  __int16 v60; // [esp+27Ah] [ebp-26h]
  C_CSPlayer *pCSPlayer; // [esp+27Ch] [ebp-24h]
  int iDesiredGap; // [esp+280h] [ebp-20h]
  int iDesiredSpread; // [esp+284h] [ebp-1Ch]
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+288h] [ebp-18h] BYREF
  C_BasePlayer *pPlayer; // [esp+28Ch] [ebp-14h]
  SFHudReticle::RETICLE_MODE iDesiredReticleMode; // [esp+290h] [ebp-10h]
  C_BasePlayer *pLocalPlayer; // [esp+294h] [ebp-Ch]
  BOOL bShowFriendlyCrosshair; // [esp+298h] [ebp-8h]
  bool bShowDroppedWeaponNames; // [esp+29Ch] [ebp-4h]
  bool bPlayerIsBot; // [esp+29Dh] [ebp-3h]
  bool bShowHealth; // [esp+29Eh] [ebp-2h]
  bool bFriendlyCrosshairOkay; // [esp+29Fh] [ebp-1h]

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iFlashSlot - 2);
  LOBYTE(bShowFriendlyCrosshair) = 0;
  iDesiredReticleMode = RETICLE_MODE_NONE;
  wcNewString[0] = 0;
  LocalPlayer = CClientTools::GetLocalPlayer();
  pCSPlayer = LocalPlayer;
  bFriendlyCrosshairOkay = false;
  bShowDroppedWeaponNames = false;
  iDesiredGap = -1;
  iDesiredSpread = -1;
  if ( LocalPlayer == nullptr
    || crosshair.m_pParent == nullptr
    || crosshair.m_pParent->m_Value.m_nValue == 0
    || sfcrosshair.m_pParent == nullptr
    || sfcrosshair.m_pParent->m_Value.m_nValue == 0 )
  {
    goto LABEL_78;
  }
  v3 = LocalPlayer->GetObserverMode(this: LocalPlayer);
  if ( v3 != 0 )
  {
    if ( v3 != 4 && v3 != 6 )
      goto LABEL_78;
    if ( v3 == 6 )
    {
      iDesiredReticleMode = RETICLE_MODE_OBSERVER;
      goto LABEL_15;
    }
  }
  else
  {
    bFriendlyCrosshairOkay = true;
    bShowDroppedWeaponNames = true;
  }
  if ( C_BasePlayer::IsInVGuiInputMode(this: LocalPlayer) )
    goto LABEL_78;
  if ( C_BasePlayer::IsInViewModelVGuiInputMode(this: LocalPlayer) )
    goto LABEL_78;
  v4 = (C_WeaponCSBase *)LocalPlayer->GetActiveWeapon(this: LocalPlayer);
  v5 = v4;
  if ( v4 == nullptr || !C_WeaponCSBase::WantReticleShown(this: v4) )
    goto LABEL_78;
  iDesiredSpread = C_WeaponCSBase::GetReticleWeaponSpread(this: v5);
  iDesiredGap = C_WeaponCSBase::GetReticleCrosshairGap(this: v5);
  iDesiredReticleMode = RETICLE_MODE_WEAPON;
LABEL_15:
  if ( hud_showtargetid.m_pParent == nullptr || hud_showtargetid.m_pParent->m_Value.m_nValue == 0 )
    goto LABEL_78;
  if ( LocalPlayer->m_flFlashBangTime > (float)(*(float *)(gpGlobals.m_Index + 12) + 0.5) )
    goto LABEL_130;
  IDTarget = C_CSPlayer::GetIDTarget(this: LocalPlayer);
  v7 = IDTarget;
  if ( IDTarget != 0 )
  {
    BaseEntity = (C_BasePlayer *)CClientEntityList::GetBaseEntity(
                                   this: (CClientEntityList *)cl_entitylist.m_Index,
                                   entnum: IDTarget);
    pPlayer = BaseEntity;
    *(float *)&pLocalPlayer = COERCE_FLOAT(C_BasePlayer::GetLocalPlayer(nSlot: -1));
    bShowHealth = false;
    if ( !IsPlayerIndex(index: v7) )
    {
      v28 = (C_CHostage *)CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: v7);
      v29 = 0;
      if ( g_Hostages.m_Size > 0 )
      {
        while ( g_Hostages.m_Memory.m_pMemory[v29] != v28 )
        {
          if ( ++v29 >= g_Hostages.m_Size )
            goto LABEL_71;
        }
        v30 = g_Hostages.m_Memory.m_pMemory[v29];
        if ( v30 != nullptr )
        {
          v31 = (float)v30->GetHealth(this: v30);
          GetMaxHealth = v30->GetMaxHealth;
          *(float *)&pLocalPlayer = v31;
          v33 = GetMaxHealth(this: v30);
          V_snwprintf(
            pDest: (wchar_t *)&convar,
            maxLen: 9,
            pFormat: L"%.0f%%",
            (float)((float)(*(float *)&pLocalPlayer / (float)v33) * 100.0));
          LOBYTE(bShowFriendlyCrosshair) = bFriendlyCrosshairOkay;
          p_convar = &convar;
          v60 = 0;
          v20 = g_pVGuiLocalize->__vftable;
          v34 = ((int (__stdcall *)(const char *))g_pVGuiLocalize->Find)(a1: "#SFUIHUD_playerid_hostage");
LABEL_59:
          v20->ConstructString_3(
            this: g_pVGuiLocalize,
            a2: wcNewString,
            a3: 512,
            a4: (const wchar_t *)v34,
            a5: 1,
            p_convar);
          goto LABEL_78;
        }
      }
      goto LABEL_71;
    }
    if ( BaseEntity != nullptr )
    {
      if ( g_PR == nullptr || (v9 = g_PR->IsFakePlayer(this: &g_PR->IGameResources, a2: v7), bPlayerIsBot = true, !v9) )
        bPlayerIsBot = false;
      IsControllingBot = false;
      v11 = (C_CS_PlayerResource *)__RTDynamicCast(
                                     inptr: g_PR,
                                     VfDelta: 0,
                                     SrcType: &C_PlayerResource `RTTI Type Descriptor',
                                     TargetType: &C_CS_PlayerResource `RTTI Type Descriptor',
                                     isReference: 0);
      if ( v11 != nullptr )
        IsControllingBot = C_CS_PlayerResource::IsControllingBot(this: v11, index: v7);
      v12 = g_pVGuiLocalize->__vftable;
      PlayerName = C_BasePlayer::GetPlayerName(this: pPlayer);
      v12->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: PlayerName, a3: wszPlayerName, a4: 64);
      if ( pPlayer->InSameTeam(this: pPlayer, a2: pLocalPlayer) )
      {
        if ( IsControllingBot )
        {
          v14 = "#SFUIHUD_playerid_sameteam_controlled_bot";
        }
        else
        {
          v14 = "#SFUIHUD_playerid_sameteam_bot";
          if ( !bPlayerIsBot )
            v14 = "#SFUIHUD_playerid_sameteam";
        }
      }
      else
      {
        v22 = pLocalPlayer;
        if ( pLocalPlayer->GetTeamNumber(this: pLocalPlayer) == 3 || v22->GetTeamNumber(this: v22) == 2 )
        {
          if ( IsControllingBot )
          {
            v14 = "#SFUIHUD_playerid_diffteam_controlled_bot";
          }
          else
          {
            v14 = "#SFUIHUD_playerid_diffteam_bot";
            if ( !bPlayerIsBot )
              v14 = "#SFUIHUD_playerid_diffteam";
          }
          m_pScaleformUI = this->m_pScaleformUI;
          this->m_bEnemyCrosshairVisible = true;
          CreateValueArray = m_pScaleformUI->CreateValueArray;
          LOBYTE(bShowFriendlyCrosshair) = 0;
          v25 = CreateValueArray(this: m_pScaleformUI, a2: 1u);
          if ( v25 != nullptr )
          {
            this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v25, a3: 0, a4: 99);
            for ( i = 1; ; i = 0 )
            {
              v27 = this->m_pScaleformUI;
              if ( i == 0 )
                break;
              if ( v27 != nullptr )
                v27->LockSlot(this: v27, a2: this->m_iFlashSlot);
              g_pScaleformUI->Value_InvokeWithoutReturn(
                this: g_pScaleformUI,
                a2: this->m_FlashAPI,
                a3: "onUpdateColor",
                a4: v25,
                a5: 1u);
            }
            if ( v27 != nullptr )
              v27->UnlockSlot(this: v27, a2: this->m_iFlashSlot);
            this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v25, a3: 1u);
          }
LABEL_30:
          if ( v14 != nullptr )
          {
            v20 = g_pVGuiLocalize->__vftable;
            if ( bShowHealth )
            {
              v21 = ((int (__stdcall *)(const char *))v20->Find)(a1: v14);
              ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v20->ConstructString_3)(
                a1: g_pVGuiLocalize,
                a2: wcNewString,
                a3: 512,
                a4: v21);
              goto LABEL_78;
            }
            p_convar = wszPlayerName;
            v34 = ((int (__stdcall *)(const char *))v20->Find)(a1: v14);
            goto LABEL_59;
          }
          goto LABEL_71;
        }
        v14 = "#SFUIHUD_playerid_noteam";
      }
      v15 = pPlayer;
      GetHealth = pPlayer->GetHealth;
      LOBYTE(bShowFriendlyCrosshair) = bFriendlyCrosshairOkay;
      bShowHealth = true;
      v17 = GetHealth(this: pPlayer);
      v18 = v15->GetMaxHealth;
      *(float *)&pLocalPlayer = (float)v17;
      v19 = v18(this: v15);
      V_snwprintf(
        pDest: (wchar_t *)&convar,
        maxLen: 9,
        pFormat: L"%.0f%%",
        (float)((float)(*(float *)&pLocalPlayer / (float)v19) * 100.0));
      v60 = 0;
      goto LABEL_30;
    }
  }
  else if ( this->m_bEnemyCrosshairVisible )
  {
    v35 = this->m_pScaleformUI;
    this->m_bEnemyCrosshairVisible = false;
    v36 = v35->CreateValueArray(this: v35, a2: 1u);
    if ( v36 != nullptr )
    {
      CGameUIConVarRef::CGameUIConVarRef(
        this: (CGameUIConVarRef *)&convar.m_Info[0].m_pConVarState,
        pName: "cl_crosshaircolor");
      m_pConVar = convar.m_Info[GetGameUIActiveSplitScreenPlayerSlot() + 1].m_pConVar;
      ((void (__stdcall *)(void *, _DWORD, IConVar_vtbl *))g_pScaleformUI->ValueArray_SetElement_4)(
        a1: v36,
        a2: 0,
        a3: m_pConVar[11].__vftable);
      for ( j = 1; ; j = 0 )
      {
        v39 = this->m_pScaleformUI;
        if ( j == 0 )
          break;
        if ( v39 != nullptr )
          v39->LockSlot(this: v39, a2: this->m_iFlashSlot);
        g_pScaleformUI->Value_InvokeWithoutReturn(
          this: g_pScaleformUI,
          a2: this->m_FlashAPI,
          a3: "onUpdateColor",
          a4: v36,
          a5: 1u);
      }
      if ( v39 != nullptr )
        v39->UnlockSlot(this: v39, a2: this->m_iFlashSlot);
      this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v36, a3: 1u);
    }
  }
LABEL_71:
  if ( bShowDroppedWeaponNames )
  {
    TargetedWeapon = C_CSPlayer::GetTargetedWeapon(this: pCSPlayer);
    if ( TargetedWeapon > 0 )
    {
      v41 = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: TargetedWeapon);
      v42 = v41;
      if ( v41 != nullptr
        && (v41->IClientEntity::IClientUnknown::IHandleEntity::__vftable[2].BloodColor(this: v41) != 22
         || (unsigned __int8)v42->IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].GetSolid(this: v42) != SOLID_NONE)
        && ((int (__thiscall *)(C_BaseEntity *))v42->IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].IsBaseCombatWeapon)(a1: v42) != 0 )
      {
        v43 = (const char *)((int (__thiscall *)(C_BaseEntity *))v42->IClientEntity::IClientUnknown::IHandleEntity::__vftable[1].IsBaseCombatWeapon)(a1: v42);
        V_strtowcs(pString: v43, nInSize: -1, pWString: wcNewString, nOutSize: 256);
      }
    }
  }
LABEL_78:
  v44 = 0;
  if ( wcNewString[0] != 0 )
  {
    if ( _V_wcscmp(s1: wcNewString, s2: this->m_wcIDString) != 0 )
    {
      v45 = this->m_pScaleformUI;
      if ( v45 != nullptr )
        v45->LockSlot(this: v45, a2: this->m_iFlashSlot);
      v44 = 1;
      this->m_pScaleformUI->Value_SetTextHTML(this: this->m_pScaleformUI, a2: this->m_IDText, a3: wcNewString);
      V_wcsncpy(pDest: this->m_wcIDString, pSrc: wcNewString, maxLenInBytes: 0x200u);
    }
    if ( this->m_FriendCrosshair != nullptr && bShowFriendlyCrosshair != this->m_bFriendlyCrosshairVisible )
    {
      if ( v44 != 1 )
      {
        v46 = this->m_pScaleformUI;
        if ( v46 != nullptr )
          v46->LockSlot(this: v46, a2: this->m_iFlashSlot);
        v44 = 1;
      }
      this->m_pScaleformUI->Value_SetVisible(
        this: this->m_pScaleformUI,
        a2: this->m_FriendCrosshair,
        a3: bShowFriendlyCrosshair);
      this->m_bFriendlyCrosshairVisible = bShowFriendlyCrosshair;
    }
    v47 = !this->m_bTextIDVisible;
    this->m_fIDTimer = *(float *)(gpGlobals.m_Index + 12) + 0.5;
    if ( v47 )
    {
      if ( v44 != 1 )
      {
        v48 = this->m_pScaleformUI;
        if ( v48 != nullptr )
          v48->LockSlot(this: v48, a2: this->m_iFlashSlot);
        v44 = 1;
      }
      this->m_pScaleformUI->Value_InvokeWithoutReturn(
        this: this->m_pScaleformUI,
        a2: this->m_IDMovie,
        a3: "Show",
        a4: nullptr,
        a5: 0);
      this->m_bTextIDVisible = true;
    }
  }
  else
  {
    if ( this->m_bFriendlyCrosshairVisible )
    {
      v49 = this->m_pScaleformUI;
      if ( v49 != nullptr )
        v49->LockSlot(this: v49, a2: this->m_iFlashSlot);
      v44 = 1;
      this->m_pScaleformUI->Value_SetVisible(this: this->m_pScaleformUI, a2: this->m_FriendCrosshair, a3: false);
      this->m_bFriendlyCrosshairVisible = false;
    }
    if ( this->m_bTextIDVisible && *(float *)(gpGlobals.m_Index + 12) > this->m_fIDTimer )
    {
      if ( v44 != 1 )
      {
        v50 = this->m_pScaleformUI;
        if ( v50 != nullptr )
          v50->LockSlot(this: v50, a2: this->m_iFlashSlot);
        v44 = 1;
      }
      this->m_pScaleformUI->Value_InvokeWithoutReturn(
        this: this->m_pScaleformUI,
        a2: this->m_IDMovie,
        a3: "Hide",
        a4: nullptr,
        a5: 0);
      this->m_bTextIDVisible = false;
    }
  }
  v51 = iDesiredReticleMode;
  if ( iDesiredReticleMode == this->m_iReticleMode )
    goto LABEL_125;
  if ( v44 != 1 )
  {
    v52 = this->m_pScaleformUI;
    if ( v52 != nullptr )
      v52->LockSlot(this: v52, a2: this->m_iFlashSlot);
    v44 = 1;
  }
  if ( this->m_iReticleMode == RETICLE_MODE_WEAPON )
  {
    m_WeaponCrosshairHandle = this->m_WeaponCrosshairHandle;
  }
  else
  {
    if ( this->m_iReticleMode != RETICLE_MODE_OBSERVER )
      goto LABEL_118;
    m_WeaponCrosshairHandle = this->m_ObserverCrosshairHandle;
  }
  if ( m_WeaponCrosshairHandle != nullptr )
    this->m_pScaleformUI->Value_SetVisible(this: this->m_pScaleformUI, a2: m_WeaponCrosshairHandle, a3: false);
LABEL_118:
  if ( v51 == RETICLE_MODE_WEAPON )
  {
    m_ObserverCrosshairHandle = this->m_WeaponCrosshairHandle;
LABEL_122:
    if ( m_ObserverCrosshairHandle != nullptr )
      this->m_pScaleformUI->Value_SetVisible(this: this->m_pScaleformUI, a2: m_ObserverCrosshairHandle, a3: true);
    goto LABEL_124;
  }
  if ( v51 == RETICLE_MODE_OBSERVER )
  {
    m_ObserverCrosshairHandle = this->m_ObserverCrosshairHandle;
    goto LABEL_122;
  }
LABEL_124:
  this->m_iReticleMode = v51;
LABEL_125:
  if ( this->m_iReticleMode == RETICLE_MODE_WEAPON )
    SFHudReticle::SetReticleGap(this, distance: iDesiredSpread, crosshairGap: iDesiredGap);
  if ( v44 != 0 )
  {
    v55 = this->m_pScaleformUI;
    if ( v55 != nullptr )
      v55->UnlockSlot(this: v55, a2: this->m_iFlashSlot);
  }
LABEL_130:
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10222990
// Name: public: virtual void SFHudReticle::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall SFHudReticle::FlashReady(SFHudReticle *this@<ecx>, int a2@<edi>)
{
  void *v3; // eax
  void *v4; // edi
  void *v5; // eax
  IScaleformUI *m_pScaleformUI; // ecx

  this->m_ObserverCrosshairHandle = this->m_pScaleformUI->Value_GetMember(
                                      this: this->m_pScaleformUI,
                                      a2: this->m_FlashAPI,
                                      a3: "Observer");
  SFHudReticle::PerformSwapReticle(this, a2, szReticleName: "Crosshair1");
  v3 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: this->m_FlashAPI, a3: "TargetID");
  this->m_IDMovie = v3;
  if ( v3 != nullptr )
  {
    v4 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v3, a3: "IDAnimated");
    if ( v4 != nullptr )
    {
      v5 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v4, a3: "TextBox");
      m_pScaleformUI = this->m_pScaleformUI;
      this->m_IDText = v5;
      m_pScaleformUI->ReleaseValue(this: m_pScaleformUI, a2: v4);
    }
  }
  SFHudReticle::ResetDisplay(this);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "player_death", a4: false);
}

//------------------------------------------------------------------------------
// Address: 0x10222A70
// Name: public: void SFHudReticle::OnSwapReticle(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SFHudReticle::OnSwapReticle(SFHudReticle *this@<ecx>, int a2@<edi>, IScaleformUI *pui, void *obj)
{
  const char *v5; // eax
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+4h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iFlashSlot - 2);
  v5 = this->m_pScaleformUI->Params_GetArgAsString(this: this->m_pScaleformUI, a2: obj, a3: 0);
  SFHudReticle::PerformSwapReticle(this, a2, szReticleName: v5);
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10222AB0
// Name: public: SFHudReticle::SFHudReticle(char const __near *)
// Source: json
//------------------------------------------------------------------------------
SFHudReticle *__thiscall SFHudReticle::SFHudReticle(SFHudReticle *this, const char *value)
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
  this->__vftable = (SFHudReticle_vtbl *)&SFHudFlashInterface::`vftable';
  CHudElement::InitCHudElementAfterConstruction(this, pElementName: value);
  this->__vftable = (SFHudReticle_vtbl *)&SFHudReticle::`vftable';
  this->m_WeaponCrosshairHandle = nullptr;
  this->m_TopPip = nullptr;
  this->m_BottomPip = nullptr;
  this->m_LeftPip = nullptr;
  this->m_RightPip = nullptr;
  this->m_ULBox = nullptr;
  this->m_URBox = nullptr;
  this->m_LLBox = nullptr;
  this->m_LRBox = nullptr;
  this->m_FriendCrosshair = nullptr;
  this->m_IDMovie = nullptr;
  this->m_IDText = nullptr;
  this->m_iReticleMode = RETICLE_MODE_NONE;
  this->m_fIDTimer = 0.0;
  this->m_iLastGap = -1;
  this->m_iLastSpread = -1;
  *(_WORD *)&this->m_bTextIDVisible = 256;
  this->m_bEnemyCrosshairVisible = false;
  CTraceFilterSkipTwoEntities::SetPassEntity2(
    (CTraceFilterSkipTwoEntities *)this,
    pPassEntity2: (const IHandleEntity *)0x110);
  this->m_wcIDString[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10222B90
// Name: Create_SFHudReticle
// Source: json
//------------------------------------------------------------------------------
SFHudReticle *__cdecl Create_SFHudReticle()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 752);
  memset(dst: v0, value: 0, count: 0x2F0u);
  if ( v0 != nullptr )
    return SFHudReticle::SFHudReticle(this: (SFHudReticle *)v0, value: "SFHudReticle");
  else
    return nullptr;
}
