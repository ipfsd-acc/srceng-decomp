// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/hud/sfhud_deathnotice.cpp
// Functions: 40
// ============================================================

#include "game\client\cstrike15\scaleform\hud\sfhud_deathnotice.h"

//------------------------------------------------------------------------------
// Address: 0x10205E30
// Name: public: void ScaleformFlashInterfaceMixin<class ScaleformEmptyClass>::LockScaleformSlot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::LockScaleformSlot(
        ScaleformFlashInterfaceMixin<ScaleformEmptyClass> *this)
{
  if ( this->m_pScaleformUI != nullptr )
    this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
}

//------------------------------------------------------------------------------
// Address: 0x10205E50
// Name: public: void ScaleformFlashInterfaceMixin<class ScaleformEmptyClass>::UnlockScaleformSlot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::UnlockScaleformSlot(
        ScaleformFlashInterfaceMixin<ScaleformEmptyClass> *this)
{
  if ( this->m_pScaleformUI != nullptr )
    this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
}

//------------------------------------------------------------------------------
// Address: 0x10205E70
// Name: public: void ScaleformFlashInterfaceMixin<class ScaleformEmptyClass>::SafeReleaseSFVALUE(void __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFVALUE(
        ScaleformFlashInterfaceMixin<ScaleformEmptyClass> *this,
        void **value)
{
  if ( this->m_pScaleformUI != nullptr && *value != nullptr )
  {
    this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: *value);
    *value = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10205EA0
// Name: public: void ScaleformFlashInterfaceMixin<class ScaleformEmptyClass>::OnLoadFinished(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::OnLoadFinished(
        ScaleformFlashInterfaceMixin<ScaleformEmptyClass> *this,
        IScaleformUI *pui,
        void *params)
{
  IScaleformUI_vtbl *v4; // edi
  void *v5; // eax
  void *v6; // eax
  IScaleformUI *m_pScaleformUI; // ecx
  int v8; // eax
  IScaleformUI *v9; // ecx
  void (__thiscall *FlashLoaded)(ScaleformFlashInterfaceMixin<ScaleformEmptyClass> *); // eax

  this->m_pScaleformUI = pui;
  v4 = pui->__vftable;
  v5 = pui->Params_GetArg(this: pui, a2: params, a3: 0);
  v6 = v4->CreateValue_6(this: this->m_pScaleformUI, a2: v5);
  m_pScaleformUI = this->m_pScaleformUI;
  this->m_FlashAPI = v6;
  v8 = (int)m_pScaleformUI->Params_GetArgAsNumber(this: m_pScaleformUI, a2: params, a3: 1);
  v9 = this->m_pScaleformUI;
  this->m_iFlashSlot = v8;
  v9->SlotAddRef(this: v9, a2: v8);
  FlashLoaded = this->FlashLoaded;
  this->m_bFlashAPIIsValid = true;
  FlashLoaded(this);
}

//------------------------------------------------------------------------------
// Address: 0x10205F10
// Name: public: void ScaleformFlashInterfaceMixin<class ScaleformEmptyClass>::OnReady(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::OnReady(
        ScaleformFlashInterfaceMixin<ScaleformEmptyClass> *this,
        IScaleformUI *pui,
        IScaleformUI *params)
{
  this->FlashReady(this);
}

//------------------------------------------------------------------------------
// Address: 0x10205F20
// Name: public: void ScaleformFlashInterfaceMixin<class ScaleformEmptyClass>::OnLoadProgress(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::OnLoadProgress(
        ScaleformFlashInterfaceMixin<ScaleformEmptyClass> *this,
        IScaleformUI *pui,
        void *params)
{
  long double v5; // st7
  int loadedBytes; // [esp+14h] [ebp+8h]

  loadedBytes = (int)pui->Params_GetArgAsNumber(this: pui, a2: params, a3: 1);
  v5 = pui->Params_GetArgAsNumber(this: pui, a2: params, a3: 2);
  this->FlashLoadProgress(this, a2: loadedBytes, a3: (int)v5);
}

//------------------------------------------------------------------------------
// Address: 0x10205F70
// Name: public: void ScaleformFlashInterfaceMixin<class ScaleformEmptyClass>::OnLoadError(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::OnLoadError(
        ScaleformFlashInterfaceMixin<ScaleformEmptyClass> *this,
        IScaleformUI *pui,
        IScaleformUI *params)
{
  this->FlashLoadError(this);
}

//------------------------------------------------------------------------------
// Address: 0x10205F80
// Name: public: void ScaleformFlashInterfaceMixin<class ScaleformEmptyClass>::OnUnload(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::OnUnload(
        ScaleformFlashInterfaceMixin<ScaleformEmptyClass> *this,
        IScaleformUI *pui,
        void *params)
{
  bool v4; // al
  IScaleformUI *m_pScaleformUI; // ecx
  IScaleformUI *v6; // ecx
  void *m_FlashAPI; // eax
  IScaleformUI *v8; // ecx
  int m_iFlashSlot; // edx
  void (__thiscall *PostUnloadFlash)(ScaleformFlashInterfaceMixin<ScaleformEmptyClass> *); // eax

  v4 = this->PreUnloadFlash(this);
  m_pScaleformUI = this->m_pScaleformUI;
  if ( v4 )
  {
    m_pScaleformUI->Params_SetResult_3(this: m_pScaleformUI, a2: params, a3: true);
    v6 = this->m_pScaleformUI;
    m_FlashAPI = this->m_FlashAPI;
    this->m_bFlashAPIIsValid = false;
    v6->ReleaseValue(this: v6, a2: m_FlashAPI);
    v8 = this->m_pScaleformUI;
    m_iFlashSlot = this->m_iFlashSlot;
    this->m_FlashAPI = nullptr;
    v8->SlotRelease(this: v8, a2: m_iFlashSlot);
    PostUnloadFlash = this->PostUnloadFlash;
    this->m_pScaleformUI = nullptr;
    PostUnloadFlash(this);
  }
  else
  {
    m_pScaleformUI->Params_SetResult_3(this: m_pScaleformUI, a2: params, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10207250
// Name: public: void ScaleformFlashInterfaceMixin<class ScaleformEmptyClass>::RemoveFlashElement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::RemoveFlashElement(
        ScaleformFlashInterfaceMixin<ScaleformEmptyClass> *this)
{
  if ( this->m_bFlashAPIIsValid )
    this->m_pScaleformUI->RemoveElement(this: this->m_pScaleformUI, a2: this->m_iFlashSlot, a3: this->m_FlashAPI);
}

//------------------------------------------------------------------------------
// Address: 0x10207270
// Name: public: void __near * ScaleformFlashInterfaceMixin<class ScaleformEmptyClass>::CreateFlashObject(void)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::CreateFlashObject(
        ScaleformFlashInterfaceMixin<ScaleformEmptyClass> *this)
{
  void *v2; // edi
  char i; // al

  v2 = nullptr;
  if ( this->m_bFlashAPIIsValid )
  {
    for ( i = 1; i != 0; i = 0 )
    {
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      v2 = this->m_pScaleformUI->CreateNewObject(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
    }
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x102072D0
// Name: public: void __near * ScaleformFlashInterfaceMixin<class ScaleformEmptyClass>::CreateFlashArray(int)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::CreateFlashArray(
        ScaleformFlashInterfaceMixin<ScaleformEmptyClass> *this,
        int length)
{
  void *v3; // edi
  char i; // al

  v3 = nullptr;
  if ( this->m_bFlashAPIIsValid )
  {
    for ( i = 1; i != 0; i = 0 )
    {
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      v3 = this->m_pScaleformUI->CreateNewArray(this: this->m_pScaleformUI, a2: this->m_iFlashSlot, a3: length);
    }
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10207340
// Name: public: void __near * ScaleformFlashInterfaceMixin<class ScaleformEmptyClass>::CreateFlashString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::CreateFlashString(
        ScaleformFlashInterfaceMixin<ScaleformEmptyClass> *this,
        const char *value)
{
  void *v3; // edi
  char i; // al

  v3 = nullptr;
  if ( this->m_bFlashAPIIsValid )
  {
    for ( i = 1; i != 0; i = 0 )
    {
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      v3 = this->m_pScaleformUI->CreateNewString_2(this: this->m_pScaleformUI, a2: this->m_iFlashSlot, a3: value);
    }
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10208530
// Name: public: void ScaleformFlashInterfaceMixin<class ScaleformEmptyClass>::SafeReleaseSFTextObject(class ISFTextObject __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(
        ScaleformFlashInterfaceMixin<ScaleformEmptyClass> *this,
        ISFTextObject **value)
{
  char i; // al

  if ( *value != nullptr )
  {
    for ( i = 1; i != 0; i = 0 )
    {
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      (*value)->Release(this: *value);
    }
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
    *value = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020DF40
// Name: public: void ScaleformFlashInterfaceMixin<class CGameEventListener>::OnLoadFinished(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformFlashInterfaceMixin<CGameEventListener>::OnLoadFinished(
        ScaleformFlashInterfaceMixin<CGameEventListener> *this,
        IScaleformUI *pui,
        void *params)
{
  IScaleformUI_vtbl *v4; // edi
  void *v5; // eax
  void *v6; // eax
  IScaleformUI *m_pScaleformUI; // ecx
  int v8; // eax
  IScaleformUI *v9; // ecx
  void (__thiscall *FlashLoaded)(ScaleformFlashInterfaceMixin<CGameEventListener> *); // eax

  this->m_pScaleformUI = pui;
  v4 = pui->__vftable;
  v5 = pui->Params_GetArg(this: pui, a2: params, a3: 0);
  v6 = v4->CreateValue_6(this: this->m_pScaleformUI, a2: v5);
  m_pScaleformUI = this->m_pScaleformUI;
  this->m_FlashAPI = v6;
  v8 = (int)m_pScaleformUI->Params_GetArgAsNumber(this: m_pScaleformUI, a2: params, a3: 1);
  v9 = this->m_pScaleformUI;
  this->m_iFlashSlot = v8;
  v9->SlotAddRef(this: v9, a2: v8);
  FlashLoaded = this->FlashLoaded;
  this->m_bFlashAPIIsValid = true;
  FlashLoaded(this);
}

//------------------------------------------------------------------------------
// Address: 0x1020DFB0
// Name: public: void ScaleformFlashInterfaceMixin<class CGameEventListener>::OnReady(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformFlashInterfaceMixin<CGameEventListener>::OnReady(
        ScaleformFlashInterfaceMixin<CGameEventListener> *this,
        IScaleformUI *pui,
        IScaleformUI *params)
{
  this->FlashReady(this);
}

//------------------------------------------------------------------------------
// Address: 0x1020DFC0
// Name: public: void ScaleformFlashInterfaceMixin<class CGameEventListener>::OnLoadProgress(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformFlashInterfaceMixin<CGameEventListener>::OnLoadProgress(
        ScaleformFlashInterfaceMixin<CGameEventListener> *this,
        IScaleformUI *pui,
        void *params)
{
  long double v5; // st7
  int loadedBytes; // [esp+14h] [ebp+8h]

  loadedBytes = (int)pui->Params_GetArgAsNumber(this: pui, a2: params, a3: 1);
  v5 = pui->Params_GetArgAsNumber(this: pui, a2: params, a3: 2);
  this->FlashLoadProgress(this, a2: loadedBytes, a3: (int)v5);
}

//------------------------------------------------------------------------------
// Address: 0x1020E010
// Name: public: void ScaleformFlashInterfaceMixin<class CGameEventListener>::OnLoadError(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformFlashInterfaceMixin<CGameEventListener>::OnLoadError(
        ScaleformFlashInterfaceMixin<CGameEventListener> *this,
        IScaleformUI *pui,
        IScaleformUI *params)
{
  this->FlashLoadError(this);
}

//------------------------------------------------------------------------------
// Address: 0x1020E020
// Name: public: void ScaleformFlashInterfaceMixin<class CGameEventListener>::OnUnload(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformFlashInterfaceMixin<CGameEventListener>::OnUnload(
        ScaleformFlashInterfaceMixin<CGameEventListener> *this,
        IScaleformUI *pui,
        void *params)
{
  bool v4; // al
  IScaleformUI *m_pScaleformUI; // ecx
  IScaleformUI *v6; // ecx
  void *m_FlashAPI; // eax
  IScaleformUI *v8; // ecx
  int m_iFlashSlot; // edx
  void (__thiscall *PostUnloadFlash)(ScaleformFlashInterfaceMixin<CGameEventListener> *); // eax

  v4 = this->PreUnloadFlash(this);
  m_pScaleformUI = this->m_pScaleformUI;
  if ( v4 )
  {
    m_pScaleformUI->Params_SetResult_3(this: m_pScaleformUI, a2: params, a3: true);
    v6 = this->m_pScaleformUI;
    m_FlashAPI = this->m_FlashAPI;
    this->m_bFlashAPIIsValid = false;
    v6->ReleaseValue(this: v6, a2: m_FlashAPI);
    v8 = this->m_pScaleformUI;
    m_iFlashSlot = this->m_iFlashSlot;
    this->m_FlashAPI = nullptr;
    v8->SlotRelease(this: v8, a2: m_iFlashSlot);
    PostUnloadFlash = this->PostUnloadFlash;
    this->m_pScaleformUI = nullptr;
    PostUnloadFlash(this);
  }
  else
  {
    m_pScaleformUI->Params_SetResult_3(this: m_pScaleformUI, a2: params, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10215C90
// Name: protected: void SFHudDeathNoticeAndBotStatus::GetIconHTML(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudDeathNoticeAndBotStatus::GetIconHTML(
        SFHudDeathNoticeAndBotStatus *this,
        const char *szIcon,
        char *szBuffer,
        unsigned int nBufferSize)
{
  if ( _V_strcmp(s1: szIcon, s2: "ump45") == 0 )
  {
    V_snprintf(
      pDest: szBuffer,
      maxLen: nBufferSize,
      pFormat: "<img src='icon-%s.png' width='%d' height='%d'/>",
      szIcon,
      38,
      16);
    return;
  }
  if ( _V_strcmp(s1: szIcon, s2: "suicide") == 0 )
    goto LABEL_4;
  if ( _V_strcmp(s1: szIcon, s2: "smokegrenade") == 0 )
    goto LABEL_20;
  if ( _V_strcmp(s1: szIcon, s2: "revenge") == 0 )
  {
    V_snprintf(
      pDest: szBuffer,
      maxLen: nBufferSize,
      pFormat: "<img src='icon-%s.png' width='%d' height='%d'/>",
      szIcon,
      36,
      16);
    return;
  }
  if ( _V_strcmp(s1: szIcon, s2: "p90") == 0 )
  {
    V_snprintf(
      pDest: szBuffer,
      maxLen: nBufferSize,
      pFormat: "<img src='icon-%s.png' width='%d' height='%d'/>",
      szIcon,
      43,
      16);
    return;
  }
  if ( _V_strcmp(s1: szIcon, s2: "mac10") == 0
    || _V_strcmp(s1: szIcon, s2: "headshot") == 0
    || _V_strcmp(s1: szIcon, s2: "penetrate") == 0 )
  {
    V_snprintf(
      pDest: szBuffer,
      maxLen: nBufferSize,
      pFormat: "<img src='icon-%s.png' width='%d' height='%d'/>",
      szIcon,
      23,
      16);
    return;
  }
  if ( _V_strcmp(s1: szIcon, s2: "hegrenade") == 0 )
    goto LABEL_20;
  if ( _V_strcmp(s1: szIcon, s2: "glock") == 0 )
  {
    V_snprintf(
      pDest: szBuffer,
      maxLen: nBufferSize,
      pFormat: "<img src='icon-%s.png' width='%d' height='%d'/>",
      szIcon,
      32,
      16);
    return;
  }
  if ( _V_strcmp(s1: szIcon, s2: "flashbang") == 0 )
  {
LABEL_20:
    V_snprintf(
      pDest: szBuffer,
      maxLen: nBufferSize,
      pFormat: "<img src='icon-%s.png' width='%d' height='%d'/>",
      szIcon,
      20,
      16);
    return;
  }
  if ( _V_strcmp(s1: szIcon, s2: "fiveseven") == 0 )
  {
LABEL_4:
    V_snprintf(
      pDest: szBuffer,
      maxLen: nBufferSize,
      pFormat: "<img src='icon-%s.png' width='%d' height='%d'/>",
      szIcon,
      30,
      16);
    return;
  }
  if ( _V_strcmp(s1: szIcon, s2: "domination") == 0 )
  {
    V_snprintf(
      pDest: szBuffer,
      maxLen: nBufferSize,
      pFormat: "<img src='icon-%s.png' width='%d' height='%d'/>",
      szIcon,
      21,
      16);
    return;
  }
  if ( _V_strcmp(s1: szIcon, s2: "deagle") == 0 )
  {
    V_snprintf(
      pDest: szBuffer,
      maxLen: nBufferSize,
      pFormat: "<img src='icon-%s.png' width='%d' height='%d'/>",
      szIcon,
      33,
      16);
    return;
  }
  if ( _V_strcmp(s1: szIcon, s2: "bizon") != 0
    && _V_strcmp(s1: szIcon, s2: "mag7") != 0
    && _V_strcmp(s1: szIcon, s2: "negev") != 0
    && _V_strcmp(s1: szIcon, s2: "sawedoff") != 0
    && _V_strcmp(s1: szIcon, s2: "tec9") != 0
    && _V_strcmp(s1: szIcon, s2: "taser") != 0 )
  {
    if ( _V_strcmp(s1: szIcon, s2: "inferno") == 0 )
    {
      V_snprintf(
        pDest: szBuffer,
        maxLen: nBufferSize,
        pFormat: "<img src='icon-%s.png' width='%d' height='%d'/>",
        "molotov",
        48,
        16);
      return;
    }
    if ( _V_strcmp(s1: szIcon, s2: "decoy") != 0
      && _V_strcmp(s1: szIcon, s2: "hkp2000") != 0
      && _V_strcmp(s1: szIcon, s2: "mp7") != 0
      && _V_strcmp(s1: szIcon, s2: "mp9") != 0
      && _V_strcmp(s1: szIcon, s2: "nova") != 0
      && _V_strcmp(s1: szIcon, s2: "p250") != 0
      && _V_strcmp(s1: szIcon, s2: "scar20") != 0
      && _V_strcmp(s1: szIcon, s2: "sg556") != 0 )
    {
      _V_strcmp(s1: szIcon, s2: "ssg08");
    }
  }
  V_snprintf(
    pDest: szBuffer,
    maxLen: nBufferSize,
    pFormat: "<img src='icon-%s.png' width='%d' height='%d'/>",
    szIcon,
    48,
    16);
}

//------------------------------------------------------------------------------
// Address: 0x10216080
// Name: public: void ScaleformFlashInterfaceMixin<class CHudElement>::LockScaleformSlot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformFlashInterfaceMixin<CHudElement>::LockScaleformSlot(
        ScaleformFlashInterfaceMixin<CHudElement> *this)
{
  if ( this->m_pScaleformUI != nullptr )
    this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
}

//------------------------------------------------------------------------------
// Address: 0x102160A0
// Name: public: void ScaleformFlashInterfaceMixin<class CHudElement>::UnlockScaleformSlot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformFlashInterfaceMixin<CHudElement>::UnlockScaleformSlot(
        ScaleformFlashInterfaceMixin<CHudElement> *this)
{
  if ( this->m_pScaleformUI != nullptr )
    this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
}

//------------------------------------------------------------------------------
// Address: 0x102160C0
// Name: public: void ScaleformFlashInterfaceMixin<class CHudElement>::SafeReleaseSFVALUE(void __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformFlashInterfaceMixin<CHudElement>::SafeReleaseSFVALUE(
        ScaleformFlashInterfaceMixin<CHudElement> *this,
        void **value)
{
  if ( this->m_pScaleformUI != nullptr && *value != nullptr )
  {
    this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: *value);
    *value = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102160F0
// Name: public: void ScaleformFlashInterfaceMixin<class CHudElement>::SafeReleaseSFTextObject(class ISFTextObject __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformFlashInterfaceMixin<CHudElement>::SafeReleaseSFTextObject(
        ScaleformFlashInterfaceMixin<CHudElement> *this,
        ISFTextObject **value)
{
  char i; // al

  if ( *value != nullptr )
  {
    for ( i = 1; i != 0; i = 0 )
    {
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      (*value)->Release(this: *value);
    }
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
    *value = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10216150
// Name: public: void ScaleformFlashInterfaceMixin<class CHudElement>::OnLoadFinished(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformFlashInterfaceMixin<CHudElement>::OnLoadFinished(
        ScaleformFlashInterfaceMixin<CHudElement> *this,
        IScaleformUI *pui,
        void *params)
{
  IScaleformUI_vtbl *v4; // edi
  void *v5; // eax
  void *v6; // eax
  IScaleformUI *m_pScaleformUI; // ecx
  int v8; // eax
  IScaleformUI *v9; // ecx
  void (__thiscall *FlashLoaded)(ScaleformFlashInterfaceMixin<CHudElement> *); // eax

  this->m_pScaleformUI = pui;
  v4 = pui->__vftable;
  v5 = pui->Params_GetArg(this: pui, a2: params, a3: 0);
  v6 = v4->CreateValue_6(this: this->m_pScaleformUI, a2: v5);
  m_pScaleformUI = this->m_pScaleformUI;
  this->m_FlashAPI = v6;
  v8 = (int)m_pScaleformUI->Params_GetArgAsNumber(this: m_pScaleformUI, a2: params, a3: 1);
  v9 = this->m_pScaleformUI;
  this->m_iFlashSlot = v8;
  v9->SlotAddRef(this: v9, a2: v8);
  FlashLoaded = this->FlashLoaded;
  this->m_bFlashAPIIsValid = true;
  FlashLoaded(this);
}

//------------------------------------------------------------------------------
// Address: 0x102161C0
// Name: public: void ScaleformFlashInterfaceMixin<class CHudElement>::OnReady(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformFlashInterfaceMixin<CHudElement>::OnReady(
        ScaleformFlashInterfaceMixin<CHudElement> *this,
        IScaleformUI *pui,
        IScaleformUI *params)
{
  this->FlashReady(this);
}

//------------------------------------------------------------------------------
// Address: 0x102161D0
// Name: public: void ScaleformFlashInterfaceMixin<class CHudElement>::OnLoadProgress(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformFlashInterfaceMixin<CHudElement>::OnLoadProgress(
        ScaleformFlashInterfaceMixin<CHudElement> *this,
        IScaleformUI *pui,
        void *params)
{
  long double v5; // st7
  int loadedBytes; // [esp+14h] [ebp+8h]

  loadedBytes = (int)pui->Params_GetArgAsNumber(this: pui, a2: params, a3: 1);
  v5 = pui->Params_GetArgAsNumber(this: pui, a2: params, a3: 2);
  this->FlashLoadProgress(this, a2: loadedBytes, a3: (int)v5);
}

//------------------------------------------------------------------------------
// Address: 0x10216220
// Name: public: void ScaleformFlashInterfaceMixin<class CHudElement>::OnLoadError(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformFlashInterfaceMixin<CHudElement>::OnLoadError(
        ScaleformFlashInterfaceMixin<CHudElement> *this,
        IScaleformUI *pui,
        IScaleformUI *params)
{
  this->FlashLoadError(this);
}

//------------------------------------------------------------------------------
// Address: 0x10216230
// Name: public: void ScaleformFlashInterfaceMixin<class CHudElement>::OnUnload(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ScaleformFlashInterfaceMixin<CHudElement>::OnUnload(
        ScaleformFlashInterfaceMixin<CHudElement> *this,
        IScaleformUI *pui,
        void *params)
{
  bool v4; // al
  IScaleformUI *m_pScaleformUI; // ecx
  IScaleformUI *v6; // ecx
  void *m_FlashAPI; // eax
  IScaleformUI *v8; // ecx
  int m_iFlashSlot; // edx
  void (__thiscall *PostUnloadFlash)(ScaleformFlashInterfaceMixin<CHudElement> *); // eax

  v4 = this->PreUnloadFlash(this);
  m_pScaleformUI = this->m_pScaleformUI;
  if ( v4 )
  {
    m_pScaleformUI->Params_SetResult_3(this: m_pScaleformUI, a2: params, a3: true);
    v6 = this->m_pScaleformUI;
    m_FlashAPI = this->m_FlashAPI;
    this->m_bFlashAPIIsValid = false;
    v6->ReleaseValue(this: v6, a2: m_FlashAPI);
    v8 = this->m_pScaleformUI;
    m_iFlashSlot = this->m_iFlashSlot;
    this->m_FlashAPI = nullptr;
    v8->SlotRelease(this: v8, a2: m_iFlashSlot);
    PostUnloadFlash = this->PostUnloadFlash;
    this->m_pScaleformUI = nullptr;
    PostUnloadFlash(this);
  }
  else
  {
    m_pScaleformUI->Params_SetResult_3(this: m_pScaleformUI, a2: params, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102162C0
// Name: public: virtual void SFHudDeathNoticeAndBotStatus::LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudDeathNoticeAndBotStatus::LevelInit(SFHudDeathNoticeAndBotStatus *this)
{
  if ( !this->m_bFlashAPIIsValid )
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: 2,
      a3: "DeathNotice",
      a4: (ScaleformUIFunctionHandlerObject *)this,
      a5: pScaleformFunctionHandler_SFHudDeathNoticeAndBotStatus_DeathNotice);
}

//------------------------------------------------------------------------------
// Address: 0x10216390
// Name: protected: void SFHudDeathNoticeAndBotStatus::Show(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudDeathNoticeAndBotStatus::Show(SFHudDeathNoticeAndBotStatus *this)
{
  int v2; // eax
  int v3; // edx
  int v4; // ecx
  int v5; // edi
  SFHudDeathNoticeAndBotStatus::NoticeText_t *m_pMemory; // eax
  bool v7; // zf
  void **p_m_pPanel; // eax
  IScaleformUI *m_pScaleformUI; // ecx
  IScaleformUI *v10; // ecx
  SFHudDeathNoticeAndBotStatus::NoticeText_t *v11; // edx
  ScaleformDisplayInfo dinfo; // [esp+4h] [ebp-40h] BYREF
  int nLowerBound; // [esp+3Ch] [ebp-8h]
  int nPos; // [esp+40h] [ebp-4h]

  if ( !this->m_bVisible )
  {
    v2 = this->m_vecNoticeText.m_Size - 1;
    v3 = v2 - this->m_nNotificationDisplayMax;
    v4 = v2;
    nLowerBound = this->m_vecNoticeText.m_Size - 1 - this->m_nNotificationDisplayMax;
    nPos = v2;
    if ( v2 >= 0 )
    {
      v5 = v2;
      do
      {
        if ( v4 < v3 )
          break;
        m_pMemory = this->m_vecNoticeText.m_Memory.m_pMemory;
        v7 = m_pMemory[v5].m_pPanel == nullptr;
        p_m_pPanel = &m_pMemory[v5].m_pPanel;
        if ( !v7 )
        {
          m_pScaleformUI = this->m_pScaleformUI;
          dinfo.m_iSetFlags = 0;
          m_pScaleformUI->Value_GetDisplayInfo(this: m_pScaleformUI, a2: *p_m_pPanel, a3: &dinfo);
          dinfo.m_iSetFlags |= 0x10u;
          v10 = this->m_pScaleformUI;
          v11 = this->m_vecNoticeText.m_Memory.m_pMemory;
          dinfo.m_bVisibility = true;
          v10->Value_SetDisplayInfo(this: v10, a2: v11[v5].m_pPanel, a3: &dinfo);
          v4 = nPos;
          v3 = nLowerBound;
        }
        --v4;
        --v5;
        nPos = v4;
      }
      while ( v4 >= 0 );
    }
    this->m_bVisible = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10216440
// Name: protected: void SFHudDeathNoticeAndBotStatus::Hide(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudDeathNoticeAndBotStatus::Hide(SFHudDeathNoticeAndBotStatus *this)
{
  int v2; // eax
  int v3; // edx
  int v4; // ecx
  int v5; // edi
  SFHudDeathNoticeAndBotStatus::NoticeText_t *m_pMemory; // eax
  bool v7; // zf
  void **p_m_pPanel; // eax
  IScaleformUI *m_pScaleformUI; // ecx
  IScaleformUI *v10; // ecx
  SFHudDeathNoticeAndBotStatus::NoticeText_t *v11; // edx
  ScaleformDisplayInfo dinfo; // [esp+4h] [ebp-40h] BYREF
  int nLowerBound; // [esp+3Ch] [ebp-8h]
  int nPos; // [esp+40h] [ebp-4h]

  if ( this->m_bVisible )
  {
    v2 = this->m_vecNoticeText.m_Size - 1;
    v3 = v2 - this->m_nNotificationDisplayMax;
    v4 = v2;
    nLowerBound = v3;
    nPos = v2;
    if ( v2 >= 0 )
    {
      v5 = v2;
      do
      {
        if ( v4 < v3 )
          break;
        m_pMemory = this->m_vecNoticeText.m_Memory.m_pMemory;
        v7 = m_pMemory[v5].m_pPanel == nullptr;
        p_m_pPanel = &m_pMemory[v5].m_pPanel;
        if ( !v7 )
        {
          m_pScaleformUI = this->m_pScaleformUI;
          dinfo.m_iSetFlags = 0;
          m_pScaleformUI->Value_GetDisplayInfo(this: m_pScaleformUI, a2: *p_m_pPanel, a3: &dinfo);
          dinfo.m_iSetFlags |= 0x10u;
          v10 = this->m_pScaleformUI;
          v11 = this->m_vecNoticeText.m_Memory.m_pMemory;
          dinfo.m_bVisibility = false;
          v10->Value_SetDisplayInfo(this: v10, a2: v11[v5].m_pPanel, a3: &dinfo);
          v4 = nPos;
          v3 = nLowerBound;
        }
        --v4;
        --v5;
        nPos = v4;
      }
      while ( v4 >= 0 );
    }
    this->m_bVisible = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102164F0
// Name: protected: void SFHudDeathNoticeAndBotStatus::RecalculateEndingYPos(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudDeathNoticeAndBotStatus::RecalculateEndingYPos(SFHudDeathNoticeAndBotStatus *this)
{
  int v1; // eax
  int v2; // edi
  int v3; // edx
  int v4; // eax
  int i; // ebx
  SFHudDeathNoticeAndBotStatus::NoticeText_t *m_pMemory; // esi
  int v7; // ebx

  v1 = this->m_vecNoticeText.m_Size - 1;
  v2 = v1 - this->m_nNotificationDisplayMax;
  v3 = v1;
  if ( v1 >= 0 )
  {
    v4 = v1;
    for ( i = 1 - v2; v3 >= v2; i = 1 - v2 )
    {
      m_pMemory = this->m_vecNoticeText.m_Memory.m_pMemory;
      if ( m_pMemory[v4].m_pPanel != nullptr )
      {
        if ( v3 >= this->m_nNotificationDisplayMax )
          v7 = v3 + i;
        else
          v7 = v3 + 1;
        m_pMemory[v4].m_nYEnd = this->m_nPanelSize * v7;
      }
      --v4;
      if ( --v3 < 0 )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102165B0
// Name: public: virtual void SFHudDeathNoticeAndBotStatus::SetActive(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudDeathNoticeAndBotStatus::SetActive(SFHudDeathNoticeAndBotStatus *this, bool bActive)
{
  if ( this->m_bFlashAPIIsValid && bActive != this->m_bVisible && this->m_FlashAPI != nullptr )
  {
    if ( !bActive )
    {
      SFHudDeathNoticeAndBotStatus::Hide(this);
LABEL_7:
      if ( this->m_bActive )
        return;
      goto LABEL_8;
    }
    SFHudDeathNoticeAndBotStatus::Show(this);
  }
  if ( !bActive )
    goto LABEL_7;
LABEL_8:
  CHudElement::SetActive(this, bActive);
}

//------------------------------------------------------------------------------
// Address: 0x10216600
// Name: public: virtual void SFHudDeathNoticeAndBotStatus::ProcessInput(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall SFHudDeathNoticeAndBotStatus::ProcessInput(
        SFHudDeathNoticeAndBotStatus *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        void *a4@<esi>)
{
  float v4; // xmm0_4
  int m_Size; // edi
  float v7; // xmm2_4
  float v8; // xmm0_4
  float v9; // xmm1_4
  int v10; // edi
  ISFTextObject *v11; // ecx
  int v12; // eax
  int v13; // edx
  int v14; // ebx
  SFHudDeathNoticeAndBotStatus::NoticeText_t *v15; // ecx
  bool v16; // zf
  IScaleformUI *v17; // ecx
  int m_fY; // ecx
  float m_fAlpha; // xmm0_4
  SFHudDeathNoticeAndBotStatus::NoticeText_t *v20; // eax
  SFHudDeathNoticeAndBotStatus::NoticeText_t *v21; // eax
  float v22; // xmm0_4
  IScaleformUI *v23; // ecx
  void (__thiscall *Value_SetDisplayInfo)(IScaleformUI *, void *, const ScaleformDisplayInfo *); // edx
  IScaleformUI *v25; // ecx
  void *(__thiscall *CreateValueArray)(IScaleformUI *, unsigned int); // edx
  int v27; // eax
  IScaleformUI *v28; // ecx
  int v29; // edi
  void (__thiscall *ValueArray_SetElement_6)(IScaleformUI *, void *, int, void *); // eax
  IScaleformUI *v31; // ecx
  void *m_FlashAPI; // eax
  bool (__thiscall *Value_InvokeWithoutReturn)(IScaleformUI *, void *, const char *, void *, unsigned int); // edx
  char *v34; // eax
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  SFHudDeathNoticeAndBotStatus::NoticeText_t *m_pMemory; // eax
  ISFTextObject *v38; // ecx
  void *v39; // ebx
  int v40; // eax
  void *v41; // edi
  IScaleformUI *v42; // ecx
  ScaleformDisplayInfo dinfoPrevious; // [esp+0h] [ebp-8Ch] BYREF
  ScaleformDisplayInfo dinfo; // [esp+38h] [ebp-54h] BYREF
  int nUpperBound; // [esp+70h] [ebp-1Ch]
  float fAlpha; // [esp+74h] [ebp-18h]
  int v50; // [esp+78h] [ebp-14h]
  ISFTextObject *text; // [esp+7Ch] [ebp-10h] BYREF
  int nPos; // [esp+80h] [ebp-Ch]
  int nYPos; // [esp+84h] [ebp-8h]
  bool bAnimateNotices; // [esp+89h] [ebp-3h]
  bool bFadeNotices; // [esp+8Ah] [ebp-2h]
  bool bOkToAnimate; // [esp+8Bh] [ebp-1h]

  v4 = *(float *)(gpGlobals.m_Index + 12);
  m_Size = this->m_vecNoticeText.m_Size;
  v7 = v4 - this->m_fLastUpdateTime;
  this->m_fLastUpdateTime = v4;
  if ( m_Size > 0 )
  {
    v8 = this->m_fAnimationTracker - v7;
    v9 = this->m_fScrollFadeTracker - v7;
    bAnimateNotices = false;
    bFadeNotices = false;
    this->m_fAnimationTracker = v8;
    this->m_fScrollFadeTracker = v9;
    if ( v8 <= 0.0 )
    {
      this->m_fAnimationTracker = this->m_fNotificationScrollRate + v8;
      bAnimateNotices = true;
    }
    if ( v9 <= 0.0 )
    {
      this->m_fScrollFadeTracker = this->m_fNotificationFadeRate + v9;
      bFadeNotices = true;
    }
    if ( bAnimateNotices || bFadeNotices )
    {
      v10 = m_Size - 1;
      v11 = (ISFTextObject *)(v10 - this->m_nNotificationDisplayMax);
      v12 = v10;
      nUpperBound = v10;
      text = v11;
      nPos = v10;
      if ( v10 >= 0 )
      {
        v13 = 544 * v10;
        v50 = 544 * v10;
        v14 = v10;
        while ( 1 )
        {
          if ( v12 < (int)v11 )
          {
LABEL_33:
            v34 = (char *)this->m_vecNoticeText.m_Memory.m_pMemory + v13;
            if ( *((_DWORD *)v34 + 129) != 0 && v34[512] != 0 )
            {
              for ( i = 1; ; i = 0 )
              {
                m_pScaleformUI = this->m_pScaleformUI;
                if ( i == 0 )
                  break;
                if ( m_pScaleformUI != nullptr )
                {
                  m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
                  v13 = v50;
                }
                m_pMemory = this->m_vecNoticeText.m_Memory.m_pMemory;
                v38 = *(ISFTextObject **)((char *)&m_pMemory->m_pText + v13);
                v39 = *(void **)((char *)&m_pMemory->m_pPanel + v13);
                v40 = this->m_vecNoticeText.m_Size - v10 - 1;
                text = v38;
                if ( v40 > 0 )
                  _V_memmove(
                    dest: (unsigned __int8 *)this->m_vecNoticeText.m_Memory.m_pMemory + v13,
                    src: (unsigned __int8 *)&this->m_vecNoticeText.m_Memory.m_pMemory[1] + v13,
                    count: 544 * v40);
                --this->m_vecNoticeText.m_Size;
                v41 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
                this->m_pScaleformUI->ValueArray_SetElement_6(this: this->m_pScaleformUI, a2: v41, a3: 0, a4: v39);
                this->m_pScaleformUI->Value_InvokeWithoutReturn(
                  this: this->m_pScaleformUI,
                  a2: this->m_FlashAPI,
                  a3: "RemovePanel",
                  a4: v41,
                  a5: 1u);
                this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v41, a3: 1u);
                v42 = this->m_pScaleformUI;
                if ( v42 != nullptr && v39 != nullptr )
                  v42->ReleaseValue(this: v42, a2: v39);
                ScaleformFlashInterfaceMixin<CHudElement>::SafeReleaseSFTextObject(this, value: &text);
                v10 = nUpperBound;
                v13 = v50;
              }
              if ( m_pScaleformUI != nullptr )
                m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
              SFHudDeathNoticeAndBotStatus::RecalculateEndingYPos(this);
            }
            return;
          }
          v15 = this->m_vecNoticeText.m_Memory.m_pMemory;
          v16 = v15[v14].m_pPanel == nullptr;
          nYPos = (int)&v15[v14].m_pPanel;
          if ( !v16 )
            break;
LABEL_32:
          --v12;
          --v14;
          nPos = v12;
          if ( v12 < 0 )
            goto LABEL_33;
          v11 = text;
        }
        v17 = this->m_pScaleformUI;
        dinfo.m_iSetFlags = 0;
        ((void (__thiscall *)(IScaleformUI *, _DWORD, ScaleformDisplayInfo *, int, int, void *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v17->Value_GetDisplayInfo)(
          a1: v17,
          a2: *(_DWORD *)nYPos,
          a3: &dinfo,
          a4: a2,
          a5: a3,
          a6: a4,
          a7: LODWORD(dinfoPrevious.m_fX),
          a8: HIDWORD(dinfoPrevious.m_fX),
          a9: LODWORD(dinfoPrevious.m_fY),
          a10: HIDWORD(dinfoPrevious.m_fY),
          a11: LODWORD(dinfoPrevious.m_fRotation),
          a12: HIDWORD(dinfoPrevious.m_fRotation),
          a13: LODWORD(dinfoPrevious.m_fAlpha),
          a14: HIDWORD(dinfoPrevious.m_fAlpha),
          a15: LODWORD(dinfoPrevious.m_fXScale));
        m_fY = (int)dinfo.m_fY;
        m_fAlpha = dinfo.m_fAlpha;
        nYPos = (int)dinfo.m_fY;
        fAlpha = m_fAlpha;
        bOkToAnimate = true;
        if ( nPos >= v10 )
        {
          if ( m_fY != 0 )
            goto LABEL_19;
        }
        else
        {
          if ( m_fY != 0 )
            goto LABEL_19;
          dinfoPrevious.m_iSetFlags = 0;
          this->m_pScaleformUI->Value_GetDisplayInfo(
            this: this->m_pScaleformUI,
            a2: this->m_vecNoticeText.m_Memory.m_pMemory[v14 + 1].m_pPanel,
            a3: &dinfoPrevious);
          m_fY = nYPos;
          m_fAlpha = fAlpha;
          if ( (double)this->m_nPanelSize >= dinfoPrevious.m_fY )
          {
            bOkToAnimate = false;
            goto LABEL_19;
          }
        }
        dinfo.m_iSetFlags |= 8u;
        v20 = this->m_vecNoticeText.m_Memory.m_pMemory;
        dinfo.m_fAlpha = 100.0;
        v20[v14].m_fFadeStartTime = *(float *)(gpGlobals.m_Index + 12) + this->m_fNotificationLifetime;
        this->m_vecNoticeText.m_Memory.m_pMemory[v14].m_bFadeOut = true;
LABEL_19:
        if ( bAnimateNotices )
        {
          if ( !bOkToAnimate )
          {
LABEL_31:
            v23 = this->m_pScaleformUI;
            Value_SetDisplayInfo = v23->Value_SetDisplayInfo;
            LODWORD(dinfoPrevious.m_fXScale) = &dinfo;
            HIDWORD(dinfoPrevious.m_fAlpha) = this->m_vecNoticeText.m_Memory.m_pMemory[v14].m_pPanel;
            ((void (__thiscall *)(IScaleformUI *))Value_SetDisplayInfo)(a1: v23);
            v25 = this->m_pScaleformUI;
            CreateValueArray = v25->CreateValueArray;
            LODWORD(dinfoPrevious.m_fAlpha) = 1;
            v27 = ((int (__thiscall *)(IScaleformUI *))CreateValueArray)(a1: v25);
            v28 = this->m_pScaleformUI;
            v29 = v27;
            ValueArray_SetElement_6 = v28->ValueArray_SetElement_6;
            HIDWORD(dinfoPrevious.m_fRotation) = this->m_vecNoticeText.m_Memory.m_pMemory[v14].m_pPanel;
            LODWORD(dinfoPrevious.m_fRotation) = 0;
            HIDWORD(dinfoPrevious.m_fY) = v29;
            ((void (__thiscall *)(IScaleformUI *))ValueArray_SetElement_6)(a1: v28);
            v31 = this->m_pScaleformUI;
            m_FlashAPI = this->m_FlashAPI;
            Value_InvokeWithoutReturn = v31->Value_InvokeWithoutReturn;
            LODWORD(dinfoPrevious.m_fY) = 1;
            HIDWORD(dinfoPrevious.m_fX) = v29;
            LODWORD(dinfoPrevious.m_fX) = "UpdateWidth";
            a4 = m_FlashAPI;
            ((void (__thiscall *)(IScaleformUI *))Value_InvokeWithoutReturn)(a1: v31);
            a3 = 1;
            a2 = v29;
            ((void (__thiscall *)(IScaleformUI *))this->m_pScaleformUI->ReleaseValueArray)(a1: this->m_pScaleformUI);
            v10 = nUpperBound;
            v12 = nPos;
            v13 = v50;
            goto LABEL_32;
          }
          if ( m_fY + 1 <= this->m_vecNoticeText.m_Memory.m_pMemory[v14].m_nYEnd )
          {
            dinfo.m_iSetFlags |= 2u;
            dinfo.m_fY = (double)(m_fY + 1);
          }
        }
        if ( bOkToAnimate && bFadeNotices && m_fY != 0 )
        {
          v21 = this->m_vecNoticeText.m_Memory.m_pMemory;
          if ( v21[v14].m_bFadeOut && *(float *)(gpGlobals.m_Index + 12) > v21[v14].m_fFadeStartTime && m_fAlpha > 0.0 )
          {
            v22 = m_fAlpha - 2.0;
            dinfo.m_iSetFlags |= 8u;
            dinfo.m_fAlpha = v22;
            if ( v22 < 0.0 )
              v21[v14].m_bRemove = true;
          }
        }
        goto LABEL_31;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102169D0
// Name: public: virtual void SFHudDeathNoticeAndBotStatus::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SFHudDeathNoticeAndBotStatus::FlashReady(SFHudDeathNoticeAndBotStatus *this)
{
  if ( this->m_FlashAPI != nullptr && this->m_pScaleformUI != nullptr )
  {
    this->m_bRegisteredForEvents = true;
    gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "player_death", a4: false);
    if ( this->m_FlashAPI != nullptr )
      SFHudDeathNoticeAndBotStatus::Hide(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10216A10
// Name: public: virtual bool SFHudDeathNoticeAndBotStatus::PreUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall SFHudDeathNoticeAndBotStatus::PreUnloadFlash(SFHudDeathNoticeAndBotStatus *this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // edi
  IScaleformUI *m_pScaleformUI; // ecx
  void **p_m_pPanel; // ebx
  int nLowerBound; // [esp+8h] [ebp-8h]
  int nPos; // [esp+Ch] [ebp-4h]

  if ( this->m_bRegisteredForEvents )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: this);
    this->m_bRegisteredForEvents = false;
  }
  v2 = this->m_vecNoticeText.m_Size - 1;
  v3 = v2 - this->m_nNotificationDisplayMax;
  nPos = v2;
  nLowerBound = v3;
  if ( v2 >= 0 )
  {
    v4 = v2;
    while ( nPos >= v3 )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      p_m_pPanel = &this->m_vecNoticeText.m_Memory.m_pMemory[v4].m_pPanel;
      if ( m_pScaleformUI != nullptr && *p_m_pPanel != nullptr )
      {
        m_pScaleformUI->ReleaseValue(this: m_pScaleformUI, a2: *p_m_pPanel);
        *p_m_pPanel = nullptr;
      }
      ScaleformFlashInterfaceMixin<CHudElement>::SafeReleaseSFTextObject(
        this,
        value: &this->m_vecNoticeText.m_Memory.m_pMemory[v4--].m_pText);
      if ( --nPos < 0 )
        break;
      v3 = nLowerBound;
    }
  }
  this->m_vecNoticeText.m_Size = 0;
  if ( this->m_vecNoticeText.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_vecNoticeText.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_vecNoticeText.m_Memory.m_pMemory);
      this->m_vecNoticeText.m_Memory.m_pMemory = nullptr;
    }
    this->m_vecNoticeText.m_Memory.m_nAllocationCount = 0;
  }
  this->m_vecNoticeText.m_pElements = this->m_vecNoticeText.m_Memory.m_pMemory;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10216AE0
// Name: public: SFHudDeathNoticeAndBotStatus::SFHudDeathNoticeAndBotStatus(char const __near *)
// Source: json
//------------------------------------------------------------------------------
SFHudDeathNoticeAndBotStatus *__thiscall SFHudDeathNoticeAndBotStatus::SFHudDeathNoticeAndBotStatus(
        SFHudDeathNoticeAndBotStatus *this,
        const char *value)
{
  int v3; // eax
  SFHudDeathNoticeAndBotStatus::NoticeText_t *m_pMemory; // edx
  unsigned int v5; // eax
  SFHudDeathNoticeAndBotStatus::NoticeText_t *v6; // eax

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
  this->__vftable = (SFHudDeathNoticeAndBotStatus_vtbl *)&SFHudFlashInterface::`vftable';
  CHudElement::InitCHudElementAfterConstruction(this, pElementName: value);
  this->__vftable = (SFHudDeathNoticeAndBotStatus_vtbl *)&SFHudDeathNoticeAndBotStatus::`vftable';
  this->m_nNotificationDisplayMax = 0;
  this->m_fNotificationScrollRate = 0.0;
  this->m_fNotificationFadeRate = 0.0;
  this->m_fNotificationLifetime = 0.0;
  this->m_fHideAndShowFadeRate = 0.0;
  this->m_nPanelSize = 0;
  this->m_fLastUpdateTime = 0.0;
  this->m_fAnimationTracker = 0.0;
  this->m_fScrollFadeTracker = 0.0;
  this->m_vecNoticeText.m_Memory.m_pMemory = nullptr;
  this->m_vecNoticeText.m_Memory.m_nAllocationCount = 0;
  this->m_vecNoticeText.m_Memory.m_nGrowSize = 0;
  this->m_vecNoticeText.m_Size = 0;
  this->m_vecNoticeText.m_pElements = nullptr;
  this->m_bVisible = false;
  v3 = engine->GetMaxClients(this: engine);
  if ( this->m_vecNoticeText.m_Memory.m_nAllocationCount < v3 && this->m_vecNoticeText.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_vecNoticeText.m_Memory.m_pMemory;
    this->m_vecNoticeText.m_Memory.m_nAllocationCount = v3;
    v5 = 544 * v3;
    if ( m_pMemory != nullptr )
      v6 = (SFHudDeathNoticeAndBotStatus::NoticeText_t *)_g_pMemAlloc->Realloc_2(
                                                           this: _g_pMemAlloc,
                                                           a2: m_pMemory,
                                                           a3: v5);
    else
      v6 = (SFHudDeathNoticeAndBotStatus::NoticeText_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v5);
    this->m_vecNoticeText.m_Memory.m_pMemory = v6;
  }
  this->m_vecNoticeText.m_pElements = this->m_vecNoticeText.m_Memory.m_pMemory;
  CTraceFilterSkipTwoEntities::SetPassEntity2(
    (CTraceFilterSkipTwoEntities *)this,
    pPassEntity2: (const IHandleEntity *)0x40);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10216BD0
// Name: protected: void SFHudDeathNoticeAndBotStatus::PushNotice(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SFHudDeathNoticeAndBotStatus::PushNotice(
        SFHudDeathNoticeAndBotStatus *this@<ecx>,
        int a2@<ebx>,
        void *m_pPanel@<edi>,
        ScaleformDisplayInfo *p_dinfo@<esi>,
        const char *szNoticeText,
        BOOL isVictim,
        BOOL isKiller)
{
  char v8; // al
  void *v9; // esi
  void *v10; // edi
  IScaleformUI *m_pScaleformUI; // ecx
  ISFTextObject *v12; // eax
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  SFHudDeathNoticeAndBotStatus::NoticeText_t *m_pMemory; // ecx
  int v16; // eax
  SFHudDeathNoticeAndBotStatus::NoticeText_t *v17; // edi
  IScaleformUI *v18; // ecx
  bool v19; // zf
  SFHudDeathNoticeAndBotStatus::NoticeText_t *v20; // edx
  SFHudDeathNoticeAndBotStatus::NoticeText_t notice; // [esp+0h] [ebp-258h] BYREF
  ScaleformDisplayInfo dinfo; // [esp+220h] [ebp-38h] BYREF

  memset(&notice.m_pPanel, 0, 13);
  memset(&notice.m_nYEnd, 0, 12);
  notice.m_bRemove = false;
  _V_memset(dest: (int)&notice, fill: nullptr, count: 0x200u);
  ((void (__thiscall *)(vgui::ILocalize *, const char *, SFHudDeathNoticeAndBotStatus::NoticeText_t *, int, int))g_pVGuiLocalize->ConvertANSIToUnicode)(
    a1: g_pVGuiLocalize,
    a2: szNoticeText,
    a3: &notice,
    a4: 512,
    a5: a2);
  v8 = 1;
  while ( v8 != 0 )
  {
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
    v9 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 2);
    this->m_pScaleformUI->ValueArray_SetElement_3(this: this->m_pScaleformUI, a2: v9, a3: 0, a4: isVictim);
    this->m_pScaleformUI->ValueArray_SetElement_3(this: this->m_pScaleformUI, a2: v9, a3: 1, a4: isKiller);
    v10 = this->m_pScaleformUI->Value_Invoke(
            this: this->m_pScaleformUI,
            a2: this->m_FlashAPI,
            a3: "AddPanel",
            a4: v9,
            a5: 2);
    this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v9, a3: 2u);
    if ( this->m_pScaleformUI->Value_GetType(this: this->m_pScaleformUI, a2: v10) == VT_DisplayObject )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      notice.m_pPanel = v10;
      v12 = (ISFTextObject *)((int (__thiscall *)(IScaleformUI *, void *, const char *, void *, ScaleformDisplayInfo *))m_pScaleformUI->TextObject_MakeTextObjectFromMember)(
                               a1: m_pScaleformUI,
                               a2: v10,
                               a3: "Text",
                               a4: m_pPanel,
                               a5: p_dinfo);
      if ( v12 != nullptr )
      {
        notice.m_pText = v12;
        v12->SetTextHTML(this: v12, a2: notice.m_szNotice);
      }
      m_Size = this->m_vecNoticeText.m_Size;
      m_nAllocationCount = this->m_vecNoticeText.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<SFHudDeathNoticeAndBotStatus::NoticeText_t,int>::Grow(
          this: &this->m_vecNoticeText.m_Memory,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_vecNoticeText.m_Size;
      m_pMemory = this->m_vecNoticeText.m_Memory.m_pMemory;
      v16 = this->m_vecNoticeText.m_Size - 1;
      this->m_vecNoticeText.m_pElements = m_pMemory;
      if ( v16 > 0 )
        _V_memmove(dest: (unsigned __int8 *)&m_pMemory[1], src: (unsigned __int8 *)m_pMemory, count: 544 * v16);
      v17 = this->m_vecNoticeText.m_Memory.m_pMemory;
      if ( v17 != nullptr )
        *v17 = notice;
      v18 = this->m_pScaleformUI;
      dinfo.m_iSetFlags = 0;
      v18->Value_GetDisplayInfo(this: v18, a2: notice.m_pPanel, a3: &dinfo);
      v19 = this->m_vecNoticeText.m_Size == 1;
      dinfo.m_fAlpha = 0.0;
      if ( v19 )
      {
        v20 = this->m_vecNoticeText.m_Memory.m_pMemory;
        dinfo.m_fY = (double)this->m_nPanelSize;
        dinfo.m_iSetFlags |= 0xAu;
        dinfo.m_fAlpha = 100.0;
        v20->m_fFadeStartTime = *(float *)(gpGlobals.m_Index + 12) + this->m_fNotificationLifetime;
        this->m_vecNoticeText.m_Memory.m_pMemory->m_bFadeOut = true;
      }
      else
      {
        dinfo.m_iSetFlags |= 0xAu;
        dinfo.m_fY = 0.0;
      }
      if ( !this->m_bVisible )
      {
        dinfo.m_iSetFlags |= 0x10u;
        dinfo.m_bVisibility = false;
      }
      p_dinfo = &dinfo;
      m_pPanel = notice.m_pPanel;
      ((void (__thiscall *)(IScaleformUI *))this->m_pScaleformUI->Value_SetDisplayInfo)(a1: this->m_pScaleformUI);
      SFHudDeathNoticeAndBotStatus::RecalculateEndingYPos(this);
      v8 = 0;
    }
    else
    {
      if ( this->m_pScaleformUI != nullptr && v10 != nullptr )
        this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v10);
      v8 = 0;
    }
  }
  if ( this->m_pScaleformUI != nullptr )
    this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
}

//------------------------------------------------------------------------------
// Address: 0x10216E50
// Name: Create_SFHudDeathNoticeAndBotStatus
// Source: json
//------------------------------------------------------------------------------
SFHudDeathNoticeAndBotStatus *__cdecl Create_SFHudDeathNoticeAndBotStatus()
{
  unsigned __int8 *v0; // esi

  v0 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 132);
  memset(dst: v0, value: 0, count: 0x84u);
  if ( v0 != nullptr )
    return SFHudDeathNoticeAndBotStatus::SFHudDeathNoticeAndBotStatus(
             this: (SFHudDeathNoticeAndBotStatus *)v0,
             value: "SFHudDeathNoticeAndBotStatus");
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10216EF0
// Name: public: virtual void SFHudDeathNoticeAndBotStatus::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge SFHudDeathNoticeAndBotStatus::FireGameEvent(
        SFHudDeathNoticeAndBotStatus *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        IGameEvent *event)
{
  bool v5; // zf
  const char *v7; // eax
  IVEngineClient_vtbl *v8; // edi
  int v9; // eax
  int v10; // edi
  IVEngineClient_vtbl *v11; // ebx
  int v12; // eax
  int v13; // ebx
  const char *(__thiscall *GetString)(IGameEvent *, const char *, const char *); // edx
  int LocalPlayerIndex; // eax
  int (__thiscall *GetInt)(IGameEvent *, const char *, int); // edx
  int v17; // eax
  C_BaseEntity *BaseEntity; // eax
  C_CSPlayer *v19; // edi
  SFHudDeathNoticeAndBotStatus *v20; // esi
  char v21; // bl
  const char *v22; // ecx
  const char *v23; // eax
  const char *v24; // eax
  char *v25; // edi
  char *v26; // edx
  char *v27; // ecx
  char *v28; // eax
  const char *v29; // ebx
  char szNotice[256]; // [esp+0h] [ebp-328h] BYREF
  char szSuicide[64]; // [esp+100h] [ebp-228h] BYREF
  char szAttackerHTML[64]; // [esp+140h] [ebp-1E8h] BYREF
  char szPenetration[64]; // [esp+180h] [ebp-1A8h] BYREF
  char szVictimHTML[64]; // [esp+1C0h] [ebp-168h] BYREF
  char szHeadshot[64]; // [esp+200h] [ebp-128h] BYREF
  char szRevenge[64]; // [esp+240h] [ebp-E8h] BYREF
  char szDomination[64]; // [esp+280h] [ebp-A8h] BYREF
  char szWeaponHTML[64]; // [esp+2C0h] [ebp-68h] BYREF
  BOOL isVictim; // [esp+300h] [ebp-28h]
  const char *szWeapon; // [esp+304h] [ebp-24h]
  SFHudDeathNoticeAndBotStatus *v43; // [esp+308h] [ebp-20h]
  BOOL isKiller; // [esp+30Ch] [ebp-1Ch]
  int nVictimTeam; // [esp+310h] [ebp-18h]
  const char *szAttackerName; // [esp+314h] [ebp-14h]
  int nVictim; // [esp+318h] [ebp-10h]
  int nAtackerTeam; // [esp+31Ch] [ebp-Ch]
  const char *szVictimName; // [esp+320h] [ebp-8h]
  bool bHeadshot; // [esp+324h] [ebp-4h]
  bool bPenetrated; // [esp+325h] [ebp-3h]
  bool bRevenge; // [esp+326h] [ebp-2h]
  bool bDomniated; // [esp+327h] [ebp-1h]
  char *bSuicide; // [esp+330h] [ebp+8h]
  char bSuicide_3; // [esp+333h] [ebp+Bh]

  v5 = !this->m_bFlashAPIIsValid;
  v43 = this;
  if ( !v5 )
  {
    v7 = event->GetName(this: event);
    if ( _V_strcmp(s1: v7, s2: "player_death") == 0 )
    {
      nAtackerTeam = (int)__RTDynamicCast(
                            inptr: g_PR,
                            VfDelta: 0,
                            SrcType: &C_PlayerResource `RTTI Type Descriptor',
                            TargetType: &C_CS_PlayerResource `RTTI Type Descriptor',
                            isReference: 0);
      if ( nAtackerTeam != 0 )
      {
        v8 = engine->__vftable;
        v9 = ((int (__thiscall *)(IGameEvent *, const char *, _DWORD, int, int, int))event->GetInt)(
               a1: event,
               a2: "attacker",
               a3: 0,
               a4: a3,
               a5: a2,
               a6: a4);
        v10 = v8->GetPlayerForUserID(this: engine, a2: v9);
        v11 = engine->__vftable;
        v12 = event->GetInt(this: event, a2: "userid", a3: 0);
        v13 = v11->GetPlayerForUserID(this: engine, a2: v12);
        GetString = event->GetString;
        nVictim = v13;
        szWeapon = GetString(this: event, a2: "weapon", a3: prType);
        bHeadshot = event->GetInt(this: event, a2: "headshot", a3: 0) > 0;
        if ( v10 == 0 || (bSuicide_3 = 0, v10 == v13) )
          bSuicide_3 = 1;
        bDomniated = false;
        bRevenge = false;
        LocalPlayerIndex = GetLocalPlayerIndex();
        GetInt = event->GetInt;
        LOBYTE(isVictim) = LocalPlayerIndex == v13;
        bPenetrated = ((int (__thiscall *)(IGameEvent *, const char *))GetInt)(a1: event, a2: "penetrated") > 0;
        if ( isVictim || (LOBYTE(isKiller) = 1, GetLocalPlayerIndex() != v10) )
          LOBYTE(isKiller) = 0;
        if ( v10 <= 0 )
          szAttackerName = prType;
        else
          szAttackerName = (const char *)(*(int (__thiscall **)(int, int))(*(_DWORD *)(nAtackerTeam + 2432) + 32))(
                                           a1: nAtackerTeam + 2432,
                                           a2: v10);
        v17 = nVictim;
        if ( nVictim <= 0 )
        {
          szVictimName = prType;
        }
        else
        {
          szVictimName = (const char *)(*(int (__thiscall **)(int, int))(*(_DWORD *)(nAtackerTeam + 2432) + 32))(
                                         a1: nAtackerTeam + 2432,
                                         a2: nVictim);
          v17 = nVictim;
        }
        if ( v17 <= 0 )
          nVictimTeam = 0;
        else
          nVictimTeam = (*(int (__thiscall **)(int, int))(*(_DWORD *)(nAtackerTeam + 2432) + 52))(
                          a1: nAtackerTeam + 2432,
                          a2: v17);
        if ( v10 <= 0 )
          nAtackerTeam = 0;
        else
          nAtackerTeam = (*(int (__thiscall **)(int, int))(*(_DWORD *)(nAtackerTeam + 2432) + 52))(
                           a1: nAtackerTeam + 2432,
                           a2: v10);
        BaseEntity = CClientEntityList::GetBaseEntity(this: (CClientEntityList *)cl_entitylist.m_Index, entnum: v10);
        v19 = (C_CSPlayer *)BaseEntity;
        if ( BaseEntity == nullptr || !BaseEntity->IsPlayer(this: BaseEntity) )
          v19 = nullptr;
        if ( event->GetInt(this: event, a2: "dominated", a3: 0) > 0
          || v19 != nullptr && C_CSPlayer::IsPlayerDominated(this: v19, iPlayerIndex: nVictim) )
        {
          bDomniated = true;
        }
        else if ( event->GetInt(this: event, a2: "revenge", a3: 0) > 0 )
        {
          bRevenge = true;
        }
        v20 = v43;
        SFHudDeathNoticeAndBotStatus::GetIconHTML(
          this: v43,
          szIcon: "domination",
          szBuffer: szDomination,
          nBufferSize: 0x40u);
        SFHudDeathNoticeAndBotStatus::GetIconHTML(
          this: v20,
          szIcon: "headshot",
          szBuffer: szHeadshot,
          nBufferSize: 0x40u);
        SFHudDeathNoticeAndBotStatus::GetIconHTML(
          this: v20,
          szIcon: "penetration",
          szBuffer: szPenetration,
          nBufferSize: 0x40u);
        SFHudDeathNoticeAndBotStatus::GetIconHTML(this: v20, szIcon: "revenge", szBuffer: szRevenge, nBufferSize: 0x40u);
        SFHudDeathNoticeAndBotStatus::GetIconHTML(this: v20, szIcon: "suicide", szBuffer: szSuicide, nBufferSize: 0x40u);
        v21 = bSuicide_3;
        v22 = szAttackerName;
        if ( bSuicide_3 != 0 )
          v22 = prType;
        v23 = "#6e7d5c";
        if ( nAtackerTeam != 3 )
          v23 = "#9d511b";
        V_snprintf(pDest: szAttackerHTML, maxLen: 0x40u, pFormat: "<font color=\"%s\">%s</font>", v23, v22);
        v24 = "#6e7d5c";
        if ( nVictimTeam != 3 )
          v24 = "#9d511b";
        V_snprintf(pDest: szVictimHTML, maxLen: 0x40u, pFormat: "<font color=\"%s\">%s</font>", v24, szVictimName);
        SFHudDeathNoticeAndBotStatus::GetIconHTML(
          this: v20,
          szIcon: szWeapon,
          szBuffer: szWeaponHTML,
          nBufferSize: 0x40u);
        if ( bSuicide_3 != 0 )
          bSuicide = szSuicide;
        else
          bSuicide = (char *)prType;
        if ( bPenetrated )
          szVictimName = szPenetration;
        else
          szVictimName = prType;
        v25 = szHeadshot;
        if ( !bHeadshot )
          v25 = (char *)prType;
        v26 = (char *)prType;
        if ( v21 == 0 )
          v26 = szWeaponHTML;
        v27 = szDomination;
        if ( !bDomniated )
          v27 = (char *)prType;
        v28 = szRevenge;
        if ( !bRevenge )
          v28 = (char *)prType;
        v29 = szVictimName;
        V_snprintf(
          pDest: szNotice,
          maxLen: 0x100u,
          pFormat: "%s%s%s%s%s%s%s%s",
          v28,
          v27,
          szAttackerHTML,
          v26,
          v25,
          szVictimName,
          bSuicide,
          szVictimHTML);
        SFHudDeathNoticeAndBotStatus::PushNotice(
          this: v20,
          a2: (int)v29,
          m_pPanel: v25,
          p_dinfo: (ScaleformDisplayInfo *)v20,
          szNoticeText: szNotice,
          isVictim,
          isKiller);
      }
    }
  }
}
