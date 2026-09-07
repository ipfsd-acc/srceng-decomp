// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/controls_scaleform.cpp
// Functions: 32
// ============================================================

#include "game\client\cstrike15\scaleform\controls_scaleform.h"

//------------------------------------------------------------------------------
// Address: 0x10208250
// Name: public: CControlsScaleform::OptionBind_t::OptionBind_t(void)
// Source: json
//------------------------------------------------------------------------------
CControlsScaleform::OptionBind_t *__thiscall CControlsScaleform::OptionBind_t::OptionBind_t(
        CControlsScaleform::OptionBind_t *this)
{
  this->__vftable = (CControlsScaleform::OptionBind_t_vtbl *)&CControlsScaleform::Option_t::`vftable';
  this->m_Type = OPTION_TYPE_TOTAL;
  this->m_nPriority = 0;
  _V_memset(dest: (int)this->m_wcLabel, fill: nullptr, count: 0x80u);
  _V_memset(dest: (int)this->m_szConVar, fill: nullptr, count: 0x40u);
  this->__vftable = (CControlsScaleform::OptionBind_t_vtbl *)&CControlsScaleform::OptionBind_t::`vftable';
  _V_memset(dest: (int)this->m_szCommand, fill: nullptr, count: 0x40u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102082B0
// Name: public: CControlsScaleform::OptionSlider_t::OptionSlider_t(void)
// Source: json
//------------------------------------------------------------------------------
CControlsScaleform::OptionSlider_t *__thiscall CControlsScaleform::OptionSlider_t::OptionSlider_t(
        CControlsScaleform::OptionSlider_t *this)
{
  this->__vftable = (CControlsScaleform::OptionSlider_t_vtbl *)&CControlsScaleform::Option_t::`vftable';
  this->m_Type = OPTION_TYPE_TOTAL;
  this->m_nPriority = 0;
  _V_memset(dest: (int)this->m_wcLabel, fill: nullptr, count: 0x80u);
  _V_memset(dest: (int)this->m_szConVar, fill: nullptr, count: 0x40u);
  this->__vftable = (CControlsScaleform::OptionSlider_t_vtbl *)&CControlsScaleform::OptionSlider_t::`vftable';
  this->m_fMinValue = 0.0;
  this->m_fMaxValue = 0.0;
  this->m_fSlideValue = 0.0;
  this->m_bLeftMin = true;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10208350
// Name: int SortByPriority(struct CControlsScaleform::Option_t __near * const __near *,struct CControlsScaleform::Option_t __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SortByPriority(CControlsScaleform::Option_t *const *pLeft, CControlsScaleform::Option_t *const *pRight)
{
  return (*pLeft)->m_nPriority - (*pRight)->m_nPriority;
}

//------------------------------------------------------------------------------
// Address: 0x10208370
// Name: public: virtual void CControlsScaleform::OnResetToDefaults(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CControlsScaleform::OnResetToDefaults(CControlsScaleform *this, IScaleformUI *pui, void *obj)
{
  CCStrike15BasePanel *v4; // eax
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+8h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iSplitScreenSlot);
  v4 = BasePanel();
  v4->OnOpenMessageBox(
    this: v4,
    a2: "#SFUI_Controls_Confirm_Title",
    a3: "#SFUI_Controls_Confirm_Msg_PC",
    a4: "#SFUI_Controls_Confirm_Nav",
    a5: 15u,
    a6: &this->IMessageBoxEventCallback,
    a7: &this->m_pConfirmDialog);
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x102083C0
// Name: protected: void CControlsScaleform::UnbindOption(struct CControlsScaleform::OptionBind_t const __near * const)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CControlsScaleform::UnbindOption(
        CControlsScaleform *this,
        const CControlsScaleform::OptionBind_t *const pOptionBind)
{
  ButtonCode_t i; // ebx
  const char *v3; // eax
  const char *v4; // esi
  char *m_szCommand; // edi
  const char *v6; // eax
  char szCommand[256]; // [esp+Ch] [ebp-104h] BYREF
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+10Ch] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iSplitScreenSlot);
  for ( i = BUTTON_CODE_NONE; i < BUTTON_CODE_LAST; ++i )
  {
    v3 = gameuifuncs->GetBindingForButtonCode(this: gameuifuncs, a2: i);
    v4 = v3;
    if ( v3 != nullptr && *v3 != 0 )
    {
      if ( (m_szCommand = pOptionBind->m_szCommand, _V_stricmp(s1: v3, s2: pOptionBind->m_szCommand) == 0)
        || (_V_stricmp(s1: v4, s2: "+duck") == 0 || _V_stricmp(s1: v4, s2: "toggle_duck") == 0)
        && (_V_stricmp(s1: m_szCommand, s2: "+duck") == 0 || _V_stricmp(s1: m_szCommand, s2: "toggle_duck") == 0)
        || (_V_stricmp(s1: v4, s2: "+zoom") == 0 || _V_stricmp(s1: v4, s2: "toggle_zoom") == 0)
        && (_V_stricmp(s1: m_szCommand, s2: "+zoom") == 0 || _V_stricmp(s1: m_szCommand, s2: "toggle_zoom") == 0) )
      {
        v6 = g_pInputSystem->ButtonCodeToString(this: g_pInputSystem, a2: i);
        V_snprintf(pDest: szCommand, maxLen: 0x100u, pFormat: "unbind %s", v6);
        engine->ExecuteClientCmd(this: engine, a2: szCommand);
      }
    }
  }
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10208510
// Name: public: virtual bool CControlsScaleform::OnMessageBoxEvent(enum MessageBoxFlags_t)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CControlsScaleform::OnMessageBoxEvent(CControlsScaleform *this, MessageBoxFlags_t buttonPressed)
{
  if ( (buttonPressed & 1) != 0 )
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 5) + 32))(a1: (char *)this - 20);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102085A0
// Name: protected: void CControlsScaleform::Show(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CControlsScaleform::Show(CControlsScaleform *this)
{
  bool v2; // zf
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx

  v2 = !this->m_bFlashAPIIsValid;
  this->m_bOptionsChanged = false;
  if ( !v2 )
  {
    for ( i = 1; ; i = 0 )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      if ( i == 0 )
        break;
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      g_pScaleformUI->Value_InvokeWithoutReturn(
        this: g_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "ShowPanel",
        a4: nullptr,
        a5: 0);
    }
    if ( m_pScaleformUI != nullptr )
      m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
    this->m_bVisible = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10208600
// Name: protected: void CControlsScaleform::Hide(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CControlsScaleform::Hide(CControlsScaleform *this)
{
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx

  if ( this->m_bFlashAPIIsValid )
  {
    for ( i = 1; ; i = 0 )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      if ( i == 0 )
        break;
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      g_pScaleformUI->Value_InvokeWithoutReturn(
        this: g_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "HidePanel",
        a4: nullptr,
        a5: 0);
    }
    if ( m_pScaleformUI != nullptr )
      m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
    this->m_bVisible = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10208660
// Name: protected: virtual bool CControlsScaleform::PreUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CControlsScaleform::PreUnloadFlash(CControlsScaleform *this)
{
  ISFTextObject **m_rgTextBySlot; // edi
  int i; // ebx
  char j; // al

  if ( this->m_pScaleformUI != nullptr )
    this->m_pScaleformUI->UnlockInput(this: this->m_pScaleformUI);
  g_pScaleformUI->ShowActionNameWhenActionIsNotBound(this: g_pScaleformUI, a2: true);
  m_rgTextBySlot = this->m_rgTextBySlot;
  for ( i = 13; i != 0; --i )
  {
    if ( *m_rgTextBySlot != nullptr )
    {
      for ( j = 1; j != 0; j = 0 )
      {
        if ( this->m_pScaleformUI != nullptr )
          this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
        (*m_rgTextBySlot)->Release(this: *m_rgTextBySlot);
      }
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      *m_rgTextBySlot = nullptr;
    }
    ++m_rgTextBySlot;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102086F0
// Name: public: void CControlsScaleform::OnCancel(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CControlsScaleform::OnCancel(CControlsScaleform *this, IScaleformUI *pui, IScaleformUI *obj)
{
  CControlsScaleform::Hide(this);
}

//------------------------------------------------------------------------------
// Address: 0x10208700
// Name: public: void CControlsScaleform::OnLayoutComplete(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CControlsScaleform::OnLayoutComplete(CControlsScaleform *this, IScaleformUI *pui, IScaleformUI *obj)
{
  char i; // al

  for ( i = 1; i != 0; i = 0 )
  {
    if ( this->m_pScaleformUI != nullptr )
      this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
    g_pScaleformUI->Value_InvokeWithoutReturn(
      this: g_pScaleformUI,
      a2: this->m_FlashAPI,
      a3: "RefreshWidgetLayout",
      a4: nullptr,
      a5: 0);
  }
  if ( this->m_pScaleformUI != nullptr )
    this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
  CControlsScaleform::Show(this);
}

//------------------------------------------------------------------------------
// Address: 0x10208760
// Name: public: void CControlsScaleform::OnPopulateGlyphRequest(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CControlsScaleform::OnPopulateGlyphRequest(CControlsScaleform *this, IScaleformUI *pui, void *obj)
{
  IScaleformUI *m_pScaleformUI; // ecx
  IScaleformUI_vtbl *v6; // edi
  int v7; // eax
  ISFTextObject *v8; // eax
  ISFTextObject *v9; // edi
  const char *v10; // eax
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+Ch] [ebp-8h] BYREF
  ISFTextObject *pText; // [esp+10h] [ebp-4h] BYREF
  ISFTextObject_vtbl *obja; // [esp+20h] [ebp+Ch]

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iSplitScreenSlot);
  m_pScaleformUI = this->m_pScaleformUI;
  v6 = m_pScaleformUI->__vftable;
  v7 = ((int (__stdcall *)(void *, _DWORD, const char *))m_pScaleformUI->Params_GetArg)(a1: obj, a2: 0, a3: "Text");
  v8 = (ISFTextObject *)((int (__thiscall *)(IScaleformUI *, int))v6->TextObject_MakeTextObjectFromMember)(
                          a1: this->m_pScaleformUI,
                          a2: v7);
  v9 = v8;
  pText = v8;
  if ( v8 != nullptr )
  {
    obja = v8->__vftable;
    v10 = this->m_pScaleformUI->Params_GetArgAsString(this: this->m_pScaleformUI, a2: obj, a3: 1);
    obja->SetTextHTML_2(this: v9, a2: v10);
    ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &pText);
  }
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x102087F0
// Name: public: void CControlsScaleform::OnClearBind(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CControlsScaleform::OnClearBind(CControlsScaleform *this, IScaleformUI *pui, void *obj)
{
  int v4; // eax
  CControlsScaleform::Option_t *v5; // eax
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+4h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iSplitScreenSlot);
  v4 = (int)this->m_pScaleformUI->Params_GetArgAsNumber(this: this->m_pScaleformUI, a2: obj, a3: 0);
  if ( v4 < 13 )
  {
    v5 = this->m_rgOptionsBySlot[v4];
    if ( v5->m_Type == OPTION_TYPE_BIND )
      CControlsScaleform::UnbindOption(this, pOptionBind: (const CControlsScaleform::OptionBind_t *const)v5);
  }
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10208850
// Name: protected: void CControlsScaleform::SetSliderWithConVar(struct CControlsScaleform::OptionSlider_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CControlsScaleform::SetSliderWithConVar(
        CControlsScaleform *this,
        CControlsScaleform::OptionSlider_t *pOption)
{
  int m_iSplitScreenSlot; // esi
  SplitScreenConVarRef varOption; // [esp+8h] [ebp-14h] BYREF
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+18h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iSplitScreenSlot);
  if ( pOption->m_bSystemValue )
    m_iSplitScreenSlot = 0;
  else
    m_iSplitScreenSlot = this->m_iSplitScreenSlot;
  if ( pOption != (CControlsScaleform::OptionSlider_t *)-142 && pOption->m_szConVar[0] != 0 )
  {
    SplitScreenConVarRef::SplitScreenConVarRef(this: &varOption, pName: pOption->m_szConVar);
    pOption->m_fSlideValue = varOption.m_Info[m_iSplitScreenSlot].m_pConVarState->m_Value.m_fValue;
  }
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x102088B0
// Name: public: void CUtlMemory<struct CControlsScaleform::OptionChoiceData_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CControlsScaleform::OptionChoiceData_t,int>::Grow(
        CUtlMemory<CControlsScaleform::OptionChoiceData_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CControlsScaleform::OptionChoiceData_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = m_nAllocationCount << 7;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CControlsScaleform::OptionChoiceData_t *)_g_pMemAlloc->Realloc_2(
                                                                    this: _g_pMemAlloc,
                                                                    a2: m_pMemory,
                                                                    a3: v7);
    else
      this->m_pMemory = (CControlsScaleform::OptionChoiceData_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10208940
// Name: public: static void CControlsScaleform::UnloadDialog(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CControlsScaleform::UnloadDialog()
{
  if ( CControlsScaleform::m_pInstanceControls != nullptr )
    CControlsScaleform::Hide(this: CControlsScaleform::m_pInstanceControls);
}

//------------------------------------------------------------------------------
// Address: 0x10208950
// Name: protected: int CControlsScaleform::FindChoiceFromString(struct CControlsScaleform::OptionChoice_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CControlsScaleform::FindChoiceFromString(
        CControlsScaleform *this,
        CControlsScaleform::OptionChoice_t *pOption,
        const char *szMatch)
{
  int v4; // edi
  int result; // eax
  char v6; // al
  int nChoice; // [esp+8h] [ebp-4h]
  float flVal; // [esp+14h] [ebp+8h]

  v4 = 0;
  result = -1;
  nChoice = 0;
  if ( pOption->m_Choices.m_Size > 0 )
  {
    while ( _V_stricmp(s1: pOption->m_Choices.m_Memory.m_pMemory[v4].m_szValue, s2: szMatch) != 0 )
    {
      if ( (v6 = *szMatch, *szMatch >= 48) && v6 <= 57 || v6 == 45 )
      {
        flVal = V_atof(str: szMatch);
        if ( flVal == V_atof(str: pOption->m_Choices.m_Memory.m_pMemory[v4].m_szValue) )
          break;
      }
      ++v4;
      if ( ++nChoice >= pOption->m_Choices.m_Size )
        return -1;
    }
    return nChoice;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102089F0
// Name: protected: void CControlsScaleform::SetChoiceWithConVar(struct CControlsScaleform::OptionChoice_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CControlsScaleform::SetChoiceWithConVar(
        CControlsScaleform *this,
        CControlsScaleform::OptionChoice_t *pOption)
{
  char *m_szConVar; // ebx
  int m_iSplitScreenSlot; // eax
  int ChoiceFromString; // eax
  SplitScreenConVarRef varOption; // [esp+Ch] [ebp-14h] BYREF
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+1Ch] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iSplitScreenSlot);
  m_szConVar = pOption->m_szConVar;
  SplitScreenConVarRef::SplitScreenConVarRef(this: &varOption, pName: pOption->m_szConVar);
  if ( pOption->m_bSystemValue )
    m_iSplitScreenSlot = 0;
  else
    m_iSplitScreenSlot = this->m_iSplitScreenSlot;
  ChoiceFromString = CControlsScaleform::FindChoiceFromString(
                       this,
                       pOption,
                       szMatch: varOption.m_Info[m_iSplitScreenSlot].m_pConVarState->m_Value.m_pszString);
  if ( ChoiceFromString == -1 )
  {
    _Warning(a1: "ConVar did not match any of the options found in data file: %s\n", m_szConVar);
    ChoiceFromString = CControlsScaleform::FindChoiceFromString(
                         this,
                         pOption,
                         szMatch: varOption.m_Info[0].m_pConVarState->m_pszDefaultValue);
    if ( ChoiceFromString == -1 )
    {
      _Warning(a1: "ConVar default not match any of the options found in data file: %s\n", m_szConVar);
      ChoiceFromString = 0;
    }
  }
  pOption->m_nChoiseIndex = ChoiceFromString;
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10208A90
// Name: protected: void CControlsScaleform::UpdateWidget(int,struct CControlsScaleform::Option_t const __near * const)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CControlsScaleform::UpdateWidget(
        CControlsScaleform *this@<ecx>,
        int a2@<ebx>,
        int nWidgetIndex,
        const CControlsScaleform::Option_t *const pOption)
{
  void *v5; // ebx
  char i; // al
  CControlsScaleform::OptionType_e m_Type; // eax
  __int32 v8; // eax
  const wchar_t *v9; // eax
  CControlsScaleform::Option_t_vtbl *v10; // eax
  float v11; // xmm2_4
  float v12; // xmm0_4
  int v13; // eax
  char j; // al
  char szCommand[32]; // [esp+8h] [ebp-24h] BYREF
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+28h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iSplitScreenSlot);
  if ( nWidgetIndex < 13 )
  {
    v5 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 3);
    if ( v5 != nullptr )
    {
      ((void (__thiscall *)(IScaleformUI *, void *, _DWORD, int, int))this->m_pScaleformUI->ValueArray_SetElement_5)(
        a1: this->m_pScaleformUI,
        a2: v5,
        a3: 0,
        a4: nWidgetIndex,
        a5: a2);
      this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v5, a3: 1, a4: pOption->m_Type);
      if ( this->m_rgTextBySlot[nWidgetIndex] != nullptr )
      {
        for ( i = 1; i != 0; i = 0 )
        {
          if ( this->m_pScaleformUI != nullptr )
            this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
          this->m_rgTextBySlot[nWidgetIndex]->SetText(this: this->m_rgTextBySlot[nWidgetIndex], a2: pOption->m_wcLabel);
        }
        if ( this->m_pScaleformUI != nullptr )
          this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      }
      m_Type = pOption->m_Type;
      if ( m_Type != OPTION_TYPE_SLIDER )
      {
        v8 = m_Type - 1;
        if ( v8 != 0 )
        {
          if ( v8 == 1 )
          {
            szCommand[0] = 0;
            V_snprintf(pDest: szCommand, maxLen: 0x20u, pFormat: "${%s}", (const char *)&pOption[1]);
            v9 = this->m_pScaleformUI->ReplaceGlyphKeywordsWithHTML(this: this->m_pScaleformUI, a2: szCommand, a3: 0);
            this->m_pScaleformUI->ValueArray_SetElement(this: this->m_pScaleformUI, a2: v5, a3: 2, a4: v9);
          }
        }
        else
        {
          v10 = pOption[1].__vftable;
          if ( v10 != (CControlsScaleform::Option_t_vtbl *)-1 && (int)v10 < *(_DWORD *)&pOption[1].m_wcLabel[1] )
            this->m_pScaleformUI->ValueArray_SetElement_2(
              this: this->m_pScaleformUI,
              a2: v5,
              a3: 2,
              a4: (const char *)(pOption[1].m_Type + ((_DWORD)v10 << 7)));
        }
      }
      else if ( *(float *)&pOption[1].m_Type == *(float *)&pOption[1].__vftable )
      {
        _Warning(a1: "Datafile error. maxvalue and minvalue cannot be the same. Control: %s\n", pOption->m_szConVar);
      }
      else
      {
        v11 = *(float *)&pOption[1].m_Type;
        v12 = (float)(*(float *)&pOption[1].m_nPriority - *(float *)&pOption[1].__vftable)
            / (float)(v11 - *(float *)&pOption[1].__vftable);
        if ( v11 <= 0.0 )
          v12 = 1.0 - v12;
        v13 = (int)(float)(v12 * 100.0);
        if ( !pOption[1].m_bSystemValue )
          v13 = 100 - v13;
        this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v5, a3: 2, a4: v13);
      }
      for ( j = 1; j != 0; j = 0 )
      {
        if ( this->m_pScaleformUI != nullptr )
          this->m_pScaleformUI->LockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
        g_pScaleformUI->Value_InvokeWithoutReturn(
          this: g_pScaleformUI,
          a2: this->m_FlashAPI,
          a3: "onUpdateWidget",
          a4: v5,
          a5: 3u);
      }
      if ( this->m_pScaleformUI != nullptr )
        this->m_pScaleformUI->UnlockSlot(this: this->m_pScaleformUI, a2: this->m_iFlashSlot);
      ((void (__thiscall *)(IScaleformUI *, void *))this->m_pScaleformUI->ReleaseValueArray)(
        a1: this->m_pScaleformUI,
        a2: v5);
    }
  }
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10208CE0
// Name: public: virtual void CControlsScaleform::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CControlsScaleform::FireGameEvent(CControlsScaleform *this, IGameEvent *event)
{
  const char *v2; // eax

  v2 = event->GetName(this: event);
  if ( _V_strcmp(s1: v2, s2: "cs_game_disconnected") == 0 && CControlsScaleform::m_pInstanceControls != nullptr )
    CControlsScaleform::Hide(this: CControlsScaleform::m_pInstanceControls);
}

//------------------------------------------------------------------------------
// Address: 0x10208D20
// Name: protected: void CControlsScaleform::LayoutDialog(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CControlsScaleform::LayoutDialog(CControlsScaleform *this, int nVecOptionsOffset)
{
  int m_Size; // ecx
  int v4; // edx
  int v5; // eax
  int v6; // eax
  int v7; // ebx
  int v8; // edi
  CControlsScaleform::Option_t **v9; // eax
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  char m; // al
  IScaleformUI *v13; // ecx
  int m_nScrollPos; // eax
  char k; // al
  char j; // al
  IScaleformUI *v17; // ecx
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+4h] [ebp-10h] BYREF
  int nSize; // [esp+8h] [ebp-Ch]
  int nUpperBound; // [esp+Ch] [ebp-8h]
  CControlsScaleform::Option_t **m_rgOptionsBySlot; // [esp+10h] [ebp-4h]

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iSplitScreenSlot);
  m_Size = this->m_vecOptions.m_Size;
  v4 = nVecOptionsOffset;
  this->m_nScrollPos = nVecOptionsOffset;
  nSize = m_Size;
  v5 = m_Size;
  if ( m_Size >= 13 )
    v5 = 13;
  v6 = nVecOptionsOffset + v5;
  nUpperBound = v6;
  if ( m_Size > 0 && m_Size >= v6 )
  {
    v7 = 0;
    v8 = nVecOptionsOffset;
    if ( nVecOptionsOffset < v6 )
    {
      m_rgOptionsBySlot = this->m_rgOptionsBySlot;
      do
      {
        if ( v7 < 13 )
        {
          CControlsScaleform::UpdateWidget(
            this,
            a2: v7,
            nWidgetIndex: v7,
            pOption: this->m_vecOptions.m_Memory.m_pMemory[v8]);
          v9 = m_rgOptionsBySlot;
          v4 = nVecOptionsOffset;
          *m_rgOptionsBySlot = this->m_vecOptions.m_Memory.m_pMemory[v8];
          m_Size = nSize;
          ++v7;
          m_rgOptionsBySlot = v9 + 1;
          v6 = nUpperBound;
        }
        ++v8;
      }
      while ( v8 < v6 );
    }
  }
  if ( m_Size < 13 )
  {
    for ( i = 1; ; i = 0 )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      if ( i == 0 )
        break;
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      g_pScaleformUI->Value_InvokeWithoutReturn(
        this: g_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "DisableDownNav",
        a4: nullptr,
        a5: 0);
      g_pScaleformUI->Value_InvokeWithoutReturn(
        this: g_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "DisableUpNav",
        a4: nullptr,
        a5: 0);
    }
    if ( m_pScaleformUI != nullptr )
    {
      m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
      return;
    }
    goto LABEL_44;
  }
  if ( v4 != 0 )
  {
    m_nScrollPos = this->m_nScrollPos;
    if ( m_nScrollPos + 13 != m_Size )
    {
      if ( m_nScrollPos > 0 && m_nScrollPos + 13 < m_Size && !this->m_bNavButtonsEnabled )
      {
        for ( j = 1; ; j = 0 )
        {
          v17 = this->m_pScaleformUI;
          if ( j == 0 )
            break;
          if ( v17 != nullptr )
            v17->LockSlot(this: v17, a2: this->m_iFlashSlot);
          g_pScaleformUI->Value_InvokeWithoutReturn(
            this: g_pScaleformUI,
            a2: this->m_FlashAPI,
            a3: "EnableDownNav",
            a4: nullptr,
            a5: 0);
          g_pScaleformUI->Value_InvokeWithoutReturn(
            this: g_pScaleformUI,
            a2: this->m_FlashAPI,
            a3: "EnableUpNav",
            a4: nullptr,
            a5: 0);
        }
        if ( v17 != nullptr )
          v17->UnlockSlot(this: v17, a2: this->m_iFlashSlot);
        this->m_bNavButtonsEnabled = true;
      }
LABEL_44:
      CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
      return;
    }
    for ( k = 1; ; k = 0 )
    {
      v13 = this->m_pScaleformUI;
      if ( k == 0 )
        break;
      if ( v13 != nullptr )
        v13->LockSlot(this: v13, a2: this->m_iFlashSlot);
      g_pScaleformUI->Value_InvokeWithoutReturn(
        this: g_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "DisableDownNav",
        a4: nullptr,
        a5: 0);
      g_pScaleformUI->Value_InvokeWithoutReturn(
        this: g_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "EnableUpNav",
        a4: nullptr,
        a5: 0);
    }
  }
  else
  {
    for ( m = 1; ; m = 0 )
    {
      v13 = this->m_pScaleformUI;
      if ( m == 0 )
        break;
      if ( v13 != nullptr )
        v13->LockSlot(this: v13, a2: this->m_iFlashSlot);
      g_pScaleformUI->Value_InvokeWithoutReturn(
        this: g_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "DisableUpNav",
        a4: nullptr,
        a5: 0);
      g_pScaleformUI->Value_InvokeWithoutReturn(
        this: g_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "EnableDownNav",
        a4: nullptr,
        a5: 0);
    }
  }
  if ( v13 != nullptr )
    v13->UnlockSlot(this: v13, a2: this->m_iFlashSlot);
  this->m_bNavButtonsEnabled = false;
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10209010
// Name: public: CControlsScaleform::OptionChoice_t::OptionChoice_t(void)
// Source: json
//------------------------------------------------------------------------------
CControlsScaleform::OptionChoice_t *__thiscall CControlsScaleform::OptionChoice_t::OptionChoice_t(
        CControlsScaleform::OptionChoice_t *this)
{
  this->__vftable = (CControlsScaleform::OptionChoice_t_vtbl *)&CControlsScaleform::Option_t::`vftable';
  this->m_Type = OPTION_TYPE_TOTAL;
  this->m_nPriority = 0;
  _V_memset(dest: (int)this->m_wcLabel, fill: nullptr, count: 0x80u);
  _V_memset(dest: (int)this->m_szConVar, fill: nullptr, count: 0x40u);
  this->__vftable = (CControlsScaleform::OptionChoice_t_vtbl *)&CControlsScaleform::OptionChoice_t::`vftable';
  this->m_Choices.m_Memory.m_pMemory = nullptr;
  this->m_Choices.m_Memory.m_nAllocationCount = 0;
  this->m_Choices.m_Memory.m_nGrowSize = 0;
  this->m_Choices.m_Size = 0;
  this->m_Choices.m_pElements = nullptr;
  this->m_nChoiseIndex = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10209080
// Name: protected: CControlsScaleform::CControlsScaleform(void)
// Source: json
//------------------------------------------------------------------------------
CControlsScaleform *__thiscall CControlsScaleform::CControlsScaleform(CControlsScaleform *this)
{
  CGameEventListener *v2; // edi

  this->m_bFlashAPIIsValid = false;
  this->m_iFlashSlot = -1;
  this->m_pScaleformUI = nullptr;
  this->m_FlashAPI = nullptr;
  this->IMessageBoxEventCallback::__vftable = (IMessageBoxEventCallback_vtbl *)&IMessageBoxEventCallback::`vftable';
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  this->m_nDebugID = 42;
  v2 = &this->CGameEventListener;
  this->ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable = (CControlsScaleform_vtbl *)&CControlsScaleform::`vftable'{for `ScaleformFlashInterfaceMixin<ScaleformEmptyClass>'};
  this->IMessageBoxEventCallback::__vftable = (IMessageBoxEventCallback_vtbl *)&CControlsScaleform::`vftable'{for `IMessageBoxEventCallback'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CControlsScaleform::`vftable'{for `CGameEventListener'};
  this->m_pConfirmDialog = nullptr;
  *(_WORD *)&this->m_bVisible = 0;
  this->m_bNavButtonsEnabled = false;
  this->m_nScrollPos = 0;
  this->m_vecOptions.m_Memory.m_pMemory = nullptr;
  this->m_vecOptions.m_Memory.m_nAllocationCount = 0;
  this->m_vecOptions.m_Memory.m_nGrowSize = 0;
  this->m_vecOptions.m_Size = 0;
  this->m_vecOptions.m_pElements = nullptr;
  memset(dst: (int)this->m_rgOptionsBySlot, value: nullptr, count: sizeof(this->m_rgOptionsBySlot));
  memset(dst: (int)this->m_rgTextBySlot, value: nullptr, count: sizeof(this->m_rgTextBySlot));
  this->m_iSplitScreenSlot = 0;
  v2->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: v2, a3: "cs_game_disconnected", a4: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10209130
// Name: protected: virtual CControlsScaleform::~CControlsScaleform(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CControlsScaleform::~CControlsScaleform(CControlsScaleform *this)
{
  CGameEventListener *v2; // edi
  IVEngineClient_vtbl *v3; // ebx
  int v4; // eax
  char *v5; // eax
  vgui::CTreeViewListControl *v6; // ecx
  int v7; // eax
  const char *v8; // eax
  CGameUI *v9; // eax
  CCStrike15BasePanel *v10; // eax
  CCStrike15BasePanel *v11; // ecx
  CCStrike15BasePanel *v12; // eax
  CCStrike15BasePanel *v13; // ecx
  bool v14; // zf
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+8h] [ebp-4h] BYREF

  v2 = &this->CGameEventListener;
  this->ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable = (CControlsScaleform_vtbl *)&CControlsScaleform::`vftable'{for `ScaleformFlashInterfaceMixin<ScaleformEmptyClass>'};
  this->IMessageBoxEventCallback::__vftable = (IMessageBoxEventCallback_vtbl *)&CControlsScaleform::`vftable'{for `IMessageBoxEventCallback'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CControlsScaleform::`vftable'{for `CGameEventListener'};
  if ( this->m_bRegisteredForEvents )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: v2);
    v2->m_bRegisteredForEvents = false;
  }
  if ( this->m_bOptionsChanged )
  {
    CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
      this: &g_UISSGuard,
      slot: this->m_iSplitScreenSlot);
    v3 = engine->__vftable;
    v4 = C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass(this: (vgui::CTreeViewListControl *)engine);
    v5 = VarArgs(format: "host_writeconfig_ss %d", v4);
    v3->ClientCmd_Unrestricted(this: engine, a2: v5);
    v7 = C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass(this: v6);
    v8 = VarArgs(format: "USERID: %d", v7);
    _Warning(a1: v8);
    this->m_bOptionsChanged = false;
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
  }
  v9 = GameUI();
  if ( v9->IsInLevel(this: v9) )
  {
    if ( BasePanel()->m_bScaleformPauseMenuEnabled )
    {
      v10 = BasePanel();
      CBaseModPanel::ShowMainMenu(this: v10, bShow: false);
      v11 = BasePanel();
      v11->RestorePauseMenu(this: v11);
    }
  }
  else if ( BasePanel()->m_bScaleformMainMenuEnabled )
  {
    v12 = BasePanel();
    CBaseModPanel::ShowMainMenu(this: v12, bShow: false);
    v13 = BasePanel();
    v13->RestoreMainMenuScreen(this: v13);
  }
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_vecOptions);
  v14 = !v2->m_bRegisteredForEvents;
  v2->__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  v2->m_nDebugID = 13;
  if ( !v14 )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: v2);
    v2->m_bRegisteredForEvents = false;
  }
  v2->__vftable = (CGameEventListener_vtbl *)&IGameEventListener2::`vftable';
  v14 = !this->m_bFlashAPIIsValid;
  this->ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable = (CControlsScaleform_vtbl *)&ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::`vftable';
  if ( !v14 )
    this->m_pScaleformUI->RemoveElement(this: this->m_pScaleformUI, a2: this->m_iFlashSlot, a3: this->m_FlashAPI);
}

//------------------------------------------------------------------------------
// Address: 0x102092A0
// Name: public: static void CControlsScaleform::LoadDialog(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CControlsScaleform::LoadDialog()
{
  CControlsScaleform *v0; // eax
  CControlsScaleform *v1; // eax

  if ( CControlsScaleform::m_pInstanceControls == nullptr )
  {
    g_pScaleformUI->RefreshKeyBindings(this: g_pScaleformUI);
    g_pScaleformUI->ShowActionNameWhenActionIsNotBound(this: g_pScaleformUI, a2: false);
    v0 = (CControlsScaleform *)MemAlloc_Alloc(nSize: 0xB0u);
    if ( v0 != nullptr )
      v1 = CControlsScaleform::CControlsScaleform(this: v0);
    else
      v1 = nullptr;
    CControlsScaleform::m_pInstanceControls = v1;
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: 1,
      a3: "ControlsMenu",
      a4: (ScaleformUIFunctionHandlerObject *)v1,
      a5: pScaleformFunctionHandler_CControlsScaleform_ControlsMenu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10209310
// Name: public: static void CControlsScaleform::ShowMenu(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CControlsScaleform::ShowMenu(bool bShow)
{
  if ( !bShow || CControlsScaleform::m_pInstanceControls != nullptr )
  {
    if ( bShow != CControlsScaleform::m_pInstanceControls->m_bVisible )
    {
      if ( bShow )
        CControlsScaleform::Show(this: CControlsScaleform::m_pInstanceControls);
      else
        CControlsScaleform::Hide(this: CControlsScaleform::m_pInstanceControls);
    }
  }
  else
  {
    CControlsScaleform::LoadDialog();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10209350
// Name: protected: virtual void CControlsScaleform::PostUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CControlsScaleform::PostUnloadFlash(CControlsScaleform *this)
{
  if ( CControlsScaleform::m_pInstanceControls != nullptr )
  {
    CUtlVector<CControlsScaleform::Option_t *,CUtlMemory<CControlsScaleform::Option_t *,int>>::PurgeAndDeleteElements(this: &CControlsScaleform::m_pInstanceControls->m_vecOptions);
    if ( this != nullptr )
      ((void (__thiscall *)(CControlsScaleform *, int))this->dtr_ScaleformFlashInterfaceMixin<ScaleformEmptyClass>)(
        a1: this,
        a2: 1);
    CControlsScaleform::m_pInstanceControls = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10209380
// Name: public: void CControlsScaleform::OnUpdateValue(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CControlsScaleform::OnUpdateValue(CControlsScaleform *this, IScaleformUI *pui, int obj)
{
  IScaleformUI *m_pScaleformUI; // ecx
  long double v5; // st7
  IScaleformUI *v6; // ecx
  int v7; // edi
  long double (__thiscall *Params_GetArgAsNumber)(IScaleformUI *, void *, int); // eax
  long double v9; // st7
  int v10; // ebx
  CControlsScaleform::Option_t *v11; // edi
  CControlsScaleform::OptionType_e m_Type; // eax
  __int32 v13; // eax
  ButtonCode_t v14; // eax
  const char *v15; // eax
  int v16; // eax
  int i; // ebx
  int v18; // ebx
  int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm1_4
  const char *v22; // [esp+Ch] [ebp-130h]
  int v23; // [esp+10h] [ebp-12Ch]
  char szCommand[256]; // [esp+20h] [ebp-11Ch] BYREF
  SplitScreenConVarRef varOption; // [esp+120h] [ebp-1Ch] BYREF
  int nWidgetIndex; // [esp+130h] [ebp-Ch]
  int nValue; // [esp+134h] [ebp-8h]
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+138h] [ebp-4h] BYREF
  int iConVarSlot; // [esp+148h] [ebp+Ch]

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iSplitScreenSlot);
  m_pScaleformUI = this->m_pScaleformUI;
  this->m_bOptionsChanged = true;
  v5 = m_pScaleformUI->Params_GetArgAsNumber(this: m_pScaleformUI, a2: (void *)obj, a3: 0);
  v6 = this->m_pScaleformUI;
  v7 = (int)v5;
  Params_GetArgAsNumber = v6->Params_GetArgAsNumber;
  nWidgetIndex = (int)v5;
  v9 = Params_GetArgAsNumber(this: v6, a2: (void *)obj, a3: 1);
  v10 = (int)v9;
  nValue = (int)v9;
  if ( v7 >= 13 )
  {
    _Warning(
      a1: "Attempted to update widget that is outside of expected index range. Current number of expected widgets: %i\n",
      1);
    goto LABEL_31;
  }
  v11 = this->m_rgOptionsBySlot[v7];
  if ( v11 == nullptr )
  {
LABEL_31:
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
    return;
  }
  if ( v11->m_bSystemValue )
    iConVarSlot = 0;
  else
    iConVarSlot = this->m_iSplitScreenSlot;
  m_Type = v11->m_Type;
  if ( m_Type != OPTION_TYPE_SLIDER )
  {
    v13 = m_Type - 1;
    if ( v13 != 0 )
    {
      if ( v13 != 1 )
      {
        _Warning(a1: "Attempted to update widget of bad type: %s - %i\n", v11->m_szConVar, v11->m_Type);
        CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
        return;
      }
      if ( v10 == 0 )
      {
        CControlsScaleform::UnbindOption(this, pOptionBind: (const CControlsScaleform::OptionBind_t *const)v11);
        v14 = g_pScaleformUI->GetCurrentKey(this: g_pScaleformUI);
        v15 = (const char *)((int (__thiscall *)(IInputSystem *, ButtonCode_t, CControlsScaleform::Option_t *))g_pInputSystem->ButtonCodeToString)(
                              a1: g_pInputSystem,
                              a2: v14,
                              a3: &v11[1]);
        V_snprintf(pDest: szCommand, maxLen: 0x100u, pFormat: "bind \"%s\" \"%s\"", v15, v22);
        ((void (__thiscall *)(IVEngineClient *, char *, int))engine->ExecuteClientCmd)(
          a1: engine,
          a2: szCommand,
          a3: v23);
        this->m_pScaleformUI->RefreshKeyBindings(this: this->m_pScaleformUI);
        CControlsScaleform::LayoutDialog(this, nVecOptionsOffset: this->m_nScrollPos);
        CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
        return;
      }
      goto LABEL_31;
    }
    v16 = *(_DWORD *)&v11[1].m_wcLabel[1];
    for ( i = (int)v11[1].__vftable + nValue; i >= v16; i -= v16 )
      ;
    for ( ; i < 0; i += v16 )
      ;
    if ( i > v16 )
    {
      _Warning(a1: "Widget updated with out of range value: %s - %i\n", v11->m_szConVar, nValue);
      CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
    }
    else
    {
      v11[1].__vftable = (CControlsScaleform::Option_t_vtbl *)i;
      SplitScreenConVarRef::SplitScreenConVarRef(this: &varOption, pName: v11->m_szConVar);
      v18 = i << 7;
      varOption.m_Info[iConVarSlot].m_pConVar->SetValue_4(
        this: varOption.m_Info[iConVarSlot].m_pConVar,
        a2: (const char *)(v18 + v11[1].m_Type + 64));
      CControlsScaleform::UpdateWidget(this, a2: v18, nWidgetIndex, pOption: v11);
      CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
    }
  }
  else
  {
    if ( (unsigned int)v10 > 0x64 )
      _Warning(a1: "Widget updated with out of range value: %s - %i\n", v11->m_szConVar, (int)v9);
    if ( v10 >= 0 )
    {
      if ( v10 > 100 )
        v10 = 100;
    }
    else
    {
      v10 = 0;
    }
    v19 = v10;
    if ( !v11[1].m_bSystemValue )
      v19 = 100 - v10;
    v20 = *(float *)&v11[1].m_Type;
    v21 = (float)v19 * 0.0099999998;
    if ( v20 <= 0.0 )
      v21 = 1.0 - v21;
    *(float *)&v11[1].m_nPriority = (float)((float)(v20 - *(float *)&v11[1].__vftable) * v21)
                                  + *(float *)&v11[1].__vftable;
    SplitScreenConVarRef::SplitScreenConVarRef(this: &varOption, pName: v11->m_szConVar);
    ((void (__stdcall *)(int))varOption.m_Info[iConVarSlot].m_pConVar->SetValue_3)(a1: v11[1].m_nPriority);
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10209660
// Name: public: void CControlsScaleform::OnRequestScroll(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CControlsScaleform::OnRequestScroll(CControlsScaleform *this, IScaleformUI *pui, void *obj)
{
  int v4; // eax
  bool v5; // sf
  int v6; // ecx
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+4h] [ebp-4h] BYREF

  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: this->m_iSplitScreenSlot);
  v4 = (int)this->m_pScaleformUI->Params_GetArgAsNumber(this: this->m_pScaleformUI, a2: obj, a3: 0);
  v5 = v4 < 0;
  if ( v4 > 0 )
  {
    v6 = v4 + this->m_nScrollPos;
    if ( this->m_vecOptions.m_Size >= v6 )
    {
LABEL_6:
      CControlsScaleform::LayoutDialog(this, nVecOptionsOffset: v6);
      goto LABEL_7;
    }
    v5 = v4 < 0;
  }
  if ( v5 )
  {
    v6 = v4 + this->m_nScrollPos;
    if ( v6 >= 0 )
      goto LABEL_6;
  }
LABEL_7:
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x102096C0
// Name: protected: virtual void CControlsScaleform::ResetToDefaults(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CControlsScaleform::ResetToDefaults(CControlsScaleform *this)
{
  CControlsScaleform *v1; // ebx
  int v2; // eax
  CControlsScaleform::Option_t *v3; // esi
  int v4; // ebx
  CControlsScaleform::OptionType_e m_Type; // eax
  CControlsScaleform *v6; // ecx
  CControlsScaleform *v7; // ebx
  int v8; // ebx
  const char *v9; // edi
  void *v10; // esi
  int v11; // edi
  const char *m_pMemory; // esi
  const char *v13; // esi
  int m_iSplitScreenSlot; // [esp-4h] [ebp-3D0h]
  char szCommand[256]; // [esp+Ch] [ebp-3C0h] BYREF
  char szBinding[256]; // [esp+10Ch] [ebp-2C0h] BYREF
  char szKeyName[256]; // [esp+20Ch] [ebp-1C0h] BYREF
  char cmd[64]; // [esp+30Ch] [ebp-C0h] BYREF
  SplitScreenConVarRef v19; // [esp+34Ch] [ebp-80h] BYREF
  CUtlBuffer buf; // [esp+35Ch] [ebp-70h] BYREF
  SplitScreenConVarRef varOption; // [esp+38Ch] [ebp-40h] BYREF
  SplitScreenConVarRef v22; // [esp+39Ch] [ebp-30h] BYREF
  CGameUIConVarRef var; // [esp+3ACh] [ebp-20h] BYREF
  CGameUiSetActiveSplitScreenPlayerGuard v24; // [esp+3BCh] [ebp-10h] BYREF
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+3C0h] [ebp-Ch] BYREF
  int iOption; // [esp+3C4h] [ebp-8h]
  CControlsScaleform *v27; // [esp+3C8h] [ebp-4h]

  v1 = this;
  m_iSplitScreenSlot = this->m_iSplitScreenSlot;
  v27 = this;
  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: m_iSplitScreenSlot);
  v2 = 0;
  v1->m_bOptionsChanged = true;
  iOption = 0;
  if ( v1->m_vecOptions.m_Size > 0 )
  {
    do
    {
      v3 = v1->m_vecOptions.m_Memory.m_pMemory[v2];
      if ( v3->m_bSystemValue )
        v4 = 0;
      else
        v4 = v1->m_iSplitScreenSlot;
      m_Type = v3->m_Type;
      if ( m_Type == OPTION_TYPE_CHOICE )
      {
        if ( v3 != (CControlsScaleform::Option_t *)-142 )
        {
          SplitScreenConVarRef::SplitScreenConVarRef(this: &varOption, pName: v3->m_szConVar);
          varOption.m_Info[v4].m_pConVar->SetValue_4(
            this: varOption.m_Info[v4].m_pConVar,
            a2: varOption.m_Info[0].m_pConVarState->m_pszDefaultValue);
          v6 = v27;
          v3[1].__vftable = (CControlsScaleform::Option_t_vtbl *)-1;
          CControlsScaleform::SetChoiceWithConVar(this: v6, pOption: (CControlsScaleform::OptionChoice_t *)v3);
        }
      }
      else if ( m_Type != OPTION_TYPE_SLIDER )
      {
        if ( m_Type == OPTION_TYPE_BIND )
          CControlsScaleform::UnbindOption(this: v27, pOptionBind: (const CControlsScaleform::OptionBind_t *const)v3);
      }
      else if ( v3 != (CControlsScaleform::Option_t *)-142 )
      {
        SplitScreenConVarRef::SplitScreenConVarRef(this: &v22, pName: v3->m_szConVar);
        v22.m_Info[v4].m_pConVar->SetValue_4(
          this: v22.m_Info[v4].m_pConVar,
          a2: v22.m_Info[0].m_pConVarState->m_pszDefaultValue);
        v7 = v27;
        CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
          this: &v24,
          slot: v27->m_iSplitScreenSlot);
        if ( v3->m_bSystemValue )
          v8 = 0;
        else
          v8 = v7->m_iSplitScreenSlot;
        if ( v3->m_szConVar[0] != 0 )
        {
          SplitScreenConVarRef::SplitScreenConVarRef(this: &v19, pName: v3->m_szConVar);
          *(float *)&v3[1].m_nPriority = v19.m_Info[v8].m_pConVarState->m_Value.m_fValue;
        }
        CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &v24);
      }
      v2 = iOption + 1;
      iOption = v2;
      v1 = v27;
    }
    while ( v2 < v27->m_vecOptions.m_Size );
  }
  v9 = "cfg/controller.cfg";
  CGameUIConVarRef::CGameUIConVarRef(this: &var, pName: "joystick");
  if ( CGameUIConVarRef::IsValid(this: &var)
    && var.m_Info[GetGameUIActiveSplitScreenPlayerSlot()].m_pConVarState->m_Value.m_nValue == 0 )
  {
    v9 = "cfg/config_default.cfg";
  }
  v10 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: v9, a3: "rb", a4: 0);
  if ( v10 != nullptr )
  {
    v11 = g_pFullFileSystem->Size_2(this: &g_pFullFileSystem->IBaseFileSystem, a2: v10);
    CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: v11, nFlags: 1u);
    g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: buf.m_Memory.m_pMemory, a3: v11, a4: v10);
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v10);
    m_pMemory = (const char *)buf.m_Memory.m_pMemory;
    while ( m_pMemory != nullptr )
    {
      m_pMemory = UTIL_Parse(data: m_pMemory, token: cmd, sizeofToken: 64);
      if ( (int)_V_strlen(str: cmd) <= 0 )
        break;
      if ( _V_stricmp(s1: cmd, s2: "bind") == 0 )
      {
        v13 = UTIL_Parse(data: m_pMemory, token: szKeyName, sizeofToken: 256);
        if ( (int)_V_strlen(str: szKeyName) <= 0 )
          break;
        m_pMemory = UTIL_Parse(data: v13, token: szBinding, sizeofToken: 256);
        if ( (int)_V_strlen(str: szKeyName) <= 0 )
          break;
        V_snprintf(pDest: szCommand, maxLen: 0x100u, pFormat: "bind \"%s\" \"%s\"", szKeyName, szBinding);
        engine->ExecuteClientCmd(this: engine, a2: szCommand);
      }
    }
    CControlsScaleform::LayoutDialog(this: v1, nVecOptionsOffset: v1->m_nScrollPos);
    if ( buf.m_Memory.m_nGrowSize >= 0 )
    {
      if ( buf.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
        buf.m_Memory.m_pMemory = nullptr;
      }
      buf.m_Memory.m_nAllocationCount = 0;
    }
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
  }
  else
  {
    _Warning(a1: "Unable to locate config file used for default settings: %s\n", v9);
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10209A70
// Name: protected: void CControlsScaleform::ReadOptionsFromFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CControlsScaleform::ReadOptionsFromFile(CControlsScaleform *this, char *szFileName)
{
  int m_iSplitScreenSlot; // eax
  KeyValues *v3; // eax
  IBaseFileSystem *v4; // eax
  KeyValues *v6; // edi
  bool v7; // bl
  KeyValues *FirstTrueSubKey; // ebx
  int v9; // edi
  char *String; // esi
  char *v11; // eax
  CControlsScaleform::OptionBind_t *v12; // eax
  CControlsScaleform::OptionBind_t *v13; // eax
  CControlsScaleform::OptionChoice_t *v14; // eax
  CControlsScaleform::OptionSlider_t *v15; // eax
  CControlsScaleform::OptionBind_t *v16; // esi
  vgui::ILocalize_vtbl *v17; // edi
  char *v18; // eax
  char *v19; // eax
  CControlsScaleform::OptionType_e m_Type; // eax
  ConVar *m_pConVarState; // eax
  float v22; // xmm1_4
  float v23; // xmm2_4
  float v24; // xmm0_4
  KeyValues *Key; // eax
  const char *Name; // eax
  char *v27; // edi
  KeyValues *i; // edi
  char *v29; // ebx
  char *v30; // eax
  char *v31; // eax
  char *v32; // eax
  CControlsScaleform *v33; // edi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CControlsScaleform::Option_t **m_pMemory; // ecx
  int v37; // eax
  CControlsScaleform::Option_t **v38; // ebx
  const char *v39; // eax
  wchar_t *m_wcLabel; // [esp-14h] [ebp-38h]
  SplitScreenConVarRef varOption; // [esp+0h] [ebp-24h] BYREF
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+10h] [ebp-14h] BYREF
  KeyValues *pChoicesKey; // [esp+14h] [ebp-10h]
  KeyValues *pOptionKeys; // [esp+18h] [ebp-Ch]
  CControlsScaleform *v45; // [esp+1Ch] [ebp-8h]
  KeyValues *pKey; // [esp+20h] [ebp-4h]
  bool bWidescreen_3; // [esp+2Fh] [ebp+Bh]

  m_iSplitScreenSlot = this->m_iSplitScreenSlot;
  v45 = this;
  CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
    this: &g_UISSGuard,
    slot: m_iSplitScreenSlot);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    pOptionKeys = KeyValues::KeyValues(this: v3, setName: "options");
  else
    pOptionKeys = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v4 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v4 = nullptr;
  v6 = pOptionKeys;
  v7 = KeyValues::LoadFromFile(
         this: pOptionKeys,
         filesystem: v4,
         resourceName: szFileName,
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr);
  bWidescreen_3 = IsWidescreen();
  if ( !v7 )
  {
    v39 = VarArgs(format: "Failed to read file: %s\n", szFileName);
    _Warning(a1: v39);
    goto LABEL_63;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: v6);
  pKey = FirstTrueSubKey;
  if ( FirstTrueSubKey == nullptr )
    goto LABEL_61;
  while ( 1 )
  {
    if ( KeyValues::GetInt(this: FirstTrueSubKey, keyName: "disable", defaultValue: 0) != 0 )
      goto LABEL_59;
    v9 = 3;
    String = KeyValues::GetString(this: FirstTrueSubKey, keyName: "type", defaultValue: prType);
    if ( _V_strcmp(s1: String, s2: "slider") != 0 )
    {
      if ( _V_strcmp(s1: String, s2: "choice") != 0 )
      {
        if ( _V_strcmp(s1: String, s2: "bind") == 0 )
          v9 = 2;
      }
      else
      {
        v9 = 1;
      }
    }
    else
    {
      v9 = 0;
    }
    if ( v9 == 0 )
    {
      v15 = (CControlsScaleform::OptionSlider_t *)MemAlloc_Alloc(nSize: 0xE0u);
      if ( v15 == nullptr )
        goto LABEL_59;
      v13 = (CControlsScaleform::OptionBind_t *)CControlsScaleform::OptionSlider_t::OptionSlider_t(this: v15);
LABEL_28:
      v16 = v13;
      if ( v13 == nullptr )
        goto LABEL_59;
      v13->m_Type = v9;
      v17 = g_pVGuiLocalize->__vftable;
      m_wcLabel = v13->m_wcLabel;
      v18 = KeyValues::GetString(this: FirstTrueSubKey, keyName: "name", defaultValue: prType);
      v17->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v18, a3: m_wcLabel, a4: 128);
      v19 = KeyValues::GetString(this: FirstTrueSubKey, keyName: "convar", defaultValue: prType);
      V_strncpy(pDest: v16->m_szConVar, pSrc: v19, maxLen: 64);
      v16->m_bSystemValue = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "systemvalue", defaultValue: 0) != 0;
      v16->m_nPriority = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "priority", defaultValue: 0);
      m_Type = v16->m_Type;
      if ( m_Type == OPTION_TYPE_SLIDER )
      {
        v16->m_szCommand[12] = KeyValues::GetInt(this: FirstTrueSubKey, keyName: "leftmin", defaultValue: 1) != 0;
        SplitScreenConVarRef::SplitScreenConVarRef(this: &varOption, pName: v16->m_szConVar);
        if ( ConVarRef::IsValid(this: &varOption) )
        {
          m_pConVarState = varOption.m_Info[0].m_pConVarState;
          *(float *)v16->m_szCommand = varOption.m_Info[0].m_pConVarState->m_fMinVal;
          *(float *)&v16->m_szCommand[4] = m_pConVarState->m_fMaxVal;
        }
        else
        {
          _Warning(a1: "Data File Error. Convar associated with control not found: %s", v16->m_szConVar);
        }
        CControlsScaleform::SetSliderWithConVar(this: v45, pOption: (CControlsScaleform::OptionSlider_t *)v16);
        v22 = *(float *)&v16->m_szCommand[4];
        v23 = *(float *)v16->m_szCommand;
        if ( v23 < v22 )
        {
          v24 = *(float *)&v16->m_szCommand[8];
          if ( v24 > v22 || v23 > v24 )
            _Warning(
              a1: "Datafile error. maxvalue and minvalue not within range of ConvVar value. ConVar: %s\n",
              v16->m_szConVar);
        }
        else
        {
          _Warning(
            a1: "Datafile error. maxvalue and minvalue cannot be the same. nimvalue cannot be < maxvalue. Control: %s\n",
            v16->m_szConVar);
        }
        goto LABEL_52;
      }
      if ( m_Type != OPTION_TYPE_CHOICE )
      {
        if ( m_Type == OPTION_TYPE_BIND )
        {
          v32 = KeyValues::GetString(this: FirstTrueSubKey, keyName: "command", defaultValue: prType);
          V_strncpy(pDest: v16->m_szCommand, pSrc: v32, maxLen: 64);
        }
        goto LABEL_52;
      }
      Key = KeyValues::FindKey(this: FirstTrueSubKey, keyName: "choices", bCreate: false);
      pChoicesKey = Key;
      if ( Key != nullptr )
      {
        if ( !bWidescreen_3 )
        {
          Name = KeyValues::GetName(this: FirstTrueSubKey);
          if ( _V_strcmp(s1: Name, s2: "SplitScreenMode") == 0 )
          {
            v27 = (char *)(*(_DWORD *)&v16->m_szCommand[4]
                         + (CUtlVector<CControlsScaleform::OptionChoiceData_t,CUtlMemory<CControlsScaleform::OptionChoiceData_t,int>>::AddToTail(this: (CUtlVector<CControlsScaleform::OptionChoiceData_t,CUtlMemory<CControlsScaleform::OptionChoiceData_t,int> > *)&v16->m_szCommand[4]) << 7));
            _V_strcpy(dest: v27, src: "#SFUI_Settings_SplitMode_Horz");
            _V_strcpy(dest: v27 + 64, src: "0");
            CControlsScaleform::SetChoiceWithConVar(this: v45, pOption: (CControlsScaleform::OptionChoice_t *)v16);
LABEL_52:
            v33 = v45;
            m_Size = v45->m_vecOptions.m_Size;
            m_nAllocationCount = v45->m_vecOptions.m_Memory.m_nAllocationCount;
            if ( m_Size + 1 > m_nAllocationCount )
              CUtlMemory<CChoreoActor *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&v45->m_vecOptions,
                num: m_Size - m_nAllocationCount + 1);
            ++v33->m_vecOptions.m_Size;
            m_pMemory = v33->m_vecOptions.m_Memory.m_pMemory;
            v37 = v33->m_vecOptions.m_Size - m_Size - 1;
            v33->m_vecOptions.m_pElements = m_pMemory;
            if ( v37 > 0 )
              _V_memmove(
                dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
                src: (unsigned __int8 *)&m_pMemory[m_Size],
                count: 4 * v37);
            v38 = &v33->m_vecOptions.m_Memory.m_pMemory[m_Size];
            if ( v38 != nullptr )
              *v38 = v16;
            FirstTrueSubKey = pKey;
            goto LABEL_59;
          }
          Key = pChoicesKey;
        }
        for ( i = KeyValues::GetFirstSubKey(this: Key); i != nullptr; i = KeyValues::GetNextKey(this: i) )
        {
          v29 = (char *)(*(_DWORD *)&v16->m_szCommand[4]
                       + (CUtlVector<CControlsScaleform::OptionChoiceData_t,CUtlMemory<CControlsScaleform::OptionChoiceData_t,int>>::AddToTail(this: (CUtlVector<CControlsScaleform::OptionChoiceData_t,CUtlMemory<CControlsScaleform::OptionChoiceData_t,int> > *)&v16->m_szCommand[4]) << 7));
          v30 = (char *)KeyValues::GetName(this: i);
          V_strncpy(pDest: v29, pSrc: v30, maxLen: 64);
          v31 = KeyValues::GetString(this: i, keyName: nullptr, defaultValue: prType);
          V_strncpy(pDest: v29 + 64, pSrc: v31, maxLen: 64);
        }
        if ( *(int *)&v16->m_szCommand[16] < 2 )
          _Warning(a1: "Type is choice but there is only one option: %s\n", v16->m_szConVar);
        CControlsScaleform::SetChoiceWithConVar(this: v45, pOption: (CControlsScaleform::OptionChoice_t *)v16);
        goto LABEL_52;
      }
      _Warning(a1: "\"choices\" key not found for widget: %s\n", v16->m_szConVar);
      goto LABEL_52;
    }
    if ( v9 == 1 )
    {
      v14 = (CControlsScaleform::OptionChoice_t *)MemAlloc_Alloc(nSize: 0xE8u);
      if ( v14 == nullptr )
        goto LABEL_59;
      v13 = (CControlsScaleform::OptionBind_t *)CControlsScaleform::OptionChoice_t::OptionChoice_t(this: v14);
      goto LABEL_28;
    }
    if ( v9 != 2 )
    {
      v11 = KeyValues::GetString(this: FirstTrueSubKey, keyName: "name", defaultValue: prType);
      _Warning(a1: "Bad widget type read from file: %s\n", v11);
      goto LABEL_59;
    }
    v12 = (CControlsScaleform::OptionBind_t *)MemAlloc_Alloc(nSize: 0x110u);
    if ( v12 != nullptr )
    {
      v13 = CControlsScaleform::OptionBind_t::OptionBind_t(this: v12);
      goto LABEL_28;
    }
LABEL_59:
    pKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
    if ( pKey == nullptr )
      break;
    FirstTrueSubKey = pKey;
  }
  v6 = pOptionKeys;
LABEL_61:
  CUtlVector<CBaseAchievement *,CUtlMemory<CBaseAchievement *,int>>::Sort(
    this: (CUtlVector<vgui::CConsolePanel::CompletionItem *,CUtlMemory<vgui::CConsolePanel::CompletionItem *,int> > *)&v45->m_vecOptions,
    pfnCompare: (int (__cdecl *)(const void *, const void *))SortByPriority);
LABEL_63:
  KeyValues::deleteThis(this: v6);
  CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
}

//------------------------------------------------------------------------------
// Address: 0x10209F30
// Name: protected: virtual void CControlsScaleform::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CControlsScaleform::FlashReady(CControlsScaleform *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  IScaleformUI *m_pScaleformUI; // ecx
  int m_iSplitScreenSlot; // eax
  void *v6; // edi
  void *v7; // ebx
  void *v8; // edi
  ISFTextObject *v9; // eax
  IScaleformUI *v10; // ecx
  ISFTextObject *v11; // ebx
  void (__thiscall *ReleaseValue)(IScaleformUI *, void *); // edx
  IMatchSystem *v13; // eax
  int *v14; // eax
  int v15; // edi
  vgui::CTreeViewListControl *v16; // ecx
  int v17; // eax
  int v18; // eax
  const char *v19; // eax
  vgui::ILocalize_vtbl *v20; // edi
  int v21; // eax
  int v22; // edi
  ISFTextObject **m_rgTextBySlot; // ebx
  wchar_t wcTitle[128]; // [esp+4h] [ebp-154h] BYREF
  char szLabelName[64]; // [esp+104h] [ebp-54h] BYREF
  ISFTextObject *pTitleText; // [esp+144h] [ebp-14h] BYREF
  CGameUiSetActiveSplitScreenPlayerGuard g_UISSGuard; // [esp+148h] [ebp-10h] BYREF
  void *topPanel; // [esp+14Ch] [ebp-Ch]
  void *panel; // [esp+150h] [ebp-8h]
  void *textPanel; // [esp+154h] [ebp-4h]

  if ( this->m_FlashAPI != nullptr && this->m_pScaleformUI != nullptr )
  {
    CGameUiSetActiveSplitScreenPlayerGuard::CGameUiSetActiveSplitScreenPlayerGuard(
      this: &g_UISSGuard,
      slot: this->m_iSplitScreenSlot);
    m_pScaleformUI = this->m_pScaleformUI;
    m_iSplitScreenSlot = this->m_iSplitScreenSlot;
    this->m_bLoading = false;
    if ( m_pScaleformUI != nullptr )
    {
      if ( m_iSplitScreenSlot == -1 )
        m_iSplitScreenSlot = this->m_iFlashSlot - 2;
      m_pScaleformUI->LockInputToSlot(this: m_pScaleformUI, a2: m_iSplitScreenSlot);
    }
    v6 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: this->m_FlashAPI, a3: "TopPanel");
    topPanel = v6;
    if ( v6 != nullptr )
    {
      v7 = (void *)((int (__thiscall *)(IScaleformUI *, void *, const char *, int))this->m_pScaleformUI->Value_GetMember)(
                     a1: this->m_pScaleformUI,
                     a2: v6,
                     a3: "Panel",
                     a4: a2);
      panel = v7;
      if ( v7 != nullptr )
      {
        v8 = (void *)((int (__thiscall *)(IScaleformUI *, void *, const char *, int))this->m_pScaleformUI->Value_GetMember)(
                       a1: this->m_pScaleformUI,
                       a2: v7,
                       a3: "TitleText",
                       a4: a3);
        if ( v8 != nullptr )
        {
          v9 = this->m_pScaleformUI->TextObject_MakeTextObjectFromMember(
                 this: this->m_pScaleformUI,
                 a2: v8,
                 a3: "Title");
          v10 = this->m_pScaleformUI;
          v11 = v9;
          ReleaseValue = v10->ReleaseValue;
          pTitleText = v9;
          ReleaseValue(this: v10, a2: v8);
          if ( v11 != nullptr )
          {
            v13 = g_pMatchFramework->GetMatchSystem(this: g_pMatchFramework);
            v14 = (int *)v13->GetPlayerManager(this: v13);
            v15 = *v14;
            textPanel = v14;
            v17 = C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass(this: v16);
            v18 = (*(int (__thiscall **)(void *, int))(v15 + 4))(a1: textPanel, a2: v17);
            if ( v18 == 0 || (v19 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v18 + 8))(a1: v18)) == nullptr )
              v19 = "Player1";
            g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v19, a3: (wchar_t *)szLabelName, a4: 64);
            wcTitle[0] = 0;
            v20 = g_pVGuiLocalize->__vftable;
            v21 = ((int (__thiscall *)(vgui::ILocalize *, const char *, int, char *, _DWORD))g_pVGuiLocalize->Find)(
                    a1: g_pVGuiLocalize,
                    a2: "#SFUI_Controls_Title",
                    a3: 1,
                    a4: szLabelName,
                    a5: *(_DWORD *)wcTitle);
            ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v20->ConstructString_3)(
              a1: g_pVGuiLocalize,
              a2: wcTitle,
              a3: 256,
              a4: v21);
            v11->SetText(this: v11, a2: wcTitle);
            ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &pTitleText);
          }
          v7 = panel;
        }
        textPanel = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v7, a3: "ControlText");
        if ( textPanel != nullptr )
        {
          v22 = 0;
          m_rgTextBySlot = this->m_rgTextBySlot;
          do
          {
            V_snprintf(pDest: szLabelName, maxLen: 0x40u, pFormat: "Control_%i_Text", v22);
            *m_rgTextBySlot = this->m_pScaleformUI->TextObject_MakeTextObjectFromMember(
                                this: this->m_pScaleformUI,
                                a2: textPanel,
                                a3: szLabelName);
            ++v22;
            ++m_rgTextBySlot;
          }
          while ( v22 < 13 );
          this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: textPanel);
          v7 = panel;
        }
        this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v7);
        v6 = topPanel;
      }
      this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v6);
    }
    CControlsScaleform::ReadOptionsFromFile(this, szFileName: "scripts/controller_options.txt");
    CControlsScaleform::LayoutDialog(this, nVecOptionsOffset: 0);
    CGameUiSetActiveSplitScreenPlayerGuard::~CGameUiSetActiveSplitScreenPlayerGuard(this: &g_UISSGuard);
  }
}
