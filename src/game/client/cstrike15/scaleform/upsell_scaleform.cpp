// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/scaleform/upsell_scaleform.cpp
// Functions: 11
// ============================================================

#include "game\client\cstrike15\scaleform\upsell_scaleform.h"

//------------------------------------------------------------------------------
// Address: 0x10215640
// Name: public: void CUpsellScaleform::OnBasePanelRunCommand(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUpsellScaleform::OnBasePanelRunCommand(CUpsellScaleform *this, IScaleformUI *pui, void *obj)
{
  char *v3; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // ebx
  CCStrike15BasePanel *v6; // edi
  CCStrike15BasePanel_vtbl *v7; // esi
  CCStrike15BasePanel *v8; // eax
  char RunCommandStr[1024]; // [esp+18h] [ebp-400h] BYREF

  v3 = (char *)pui->Params_GetArgAsString(this: pui, a2: obj, a3: 0);
  V_strncpy(pDest: RunCommandStr, pSrc: v3, maxLen: 1024);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "RunMenuCommand", firstKey: "command", firstValue: RunCommandStr);
  else
    v5 = nullptr;
  v6 = BasePanel();
  v7 = v6->CBaseModPanel::vgui::Panel::vgui::IClientPanel::__vftable;
  v8 = BasePanel();
  ((void (__thiscall *)(CCStrike15BasePanel *, CCStrike15BasePanel *, KeyValues *, _DWORD))v7->PostMessage)(
    a1: v6,
    a2: v8,
    a3: v5,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x102156D0
// Name: protected: void CUpsellScaleform::PopulateAchievements(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CUpsellScaleform::PopulateAchievements(CUpsellScaleform *this@<ecx>, int a2@<ebx>)
{
  IAchievementMgr *v3; // edi
  int v4; // eax
  int v5; // ecx
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // ecx
  unsigned __int8 (*v10)(void); // eax
  void *v11; // edi
  IScaleformUI_vtbl *v12; // ebx
  int v13; // eax
  int v14; // ebx
  void *v15; // edi
  wchar_t wcCount[32]; // [esp+8h] [ebp-5Ch] BYREF
  IAchievementMgr *pAchievementMgr; // [esp+48h] [ebp-1Ch]
  int v18; // [esp+4Ch] [ebp-18h]
  int nID; // [esp+50h] [ebp-14h]
  int nAchievementMax; // [esp+54h] [ebp-10h]
  int i; // [esp+58h] [ebp-Ch]
  int nSlot; // [esp+5Ch] [ebp-8h]
  int nAchievmentCount; // [esp+60h] [ebp-4h]

  nID = C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass((vgui::CTreeViewListControl *)this);
  v3 = engine->GetAchievementMgr(this: engine);
  pAchievementMgr = v3;
  if ( v3 != nullptr )
  {
    v4 = ((int (__thiscall *)(IAchievementMgr *, _DWORD, int))v3->GetAchievementCount)(a1: v3, a2: 0, a3: a2);
    v5 = 0;
    v6 = 0;
    nAchievementMax = v4;
    nAchievmentCount = 0;
    nSlot = 0;
    i = 0;
    if ( v4 > 0 )
    {
      do
      {
        v7 = v3->GetAchievementByIndex(this: v3, a2: i, a3: nID);
        if ( v7 != 0 )
        {
          v8 = v7 - 12;
          if ( v8 != 0 )
          {
            v9 = v8 + 12;
            v10 = *(unsigned __int8 (**)(void))(*(_DWORD *)(v8 + 12) + 20);
            v18 = v9;
            if ( v10() != 0 )
            {
              ++nAchievmentCount;
              if ( v6 < 10 )
              {
                v11 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 2);
                this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v11, a3: 0, a4: v6);
                v12 = this->m_pScaleformUI->ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::__vftable;
                v13 = (*(int (__thiscall **)(int))(*(_DWORD *)v18 + 4))(a1: v18);
                v12->ValueArray_SetElement_2(this: this->m_pScaleformUI, a2: v11, a3: 1, a4: (const char *)v13);
                this->m_pScaleformUI->Value_InvokeWithoutReturn(
                  this: this->m_pScaleformUI,
                  a2: this->m_FlashAPI,
                  a3: "SetMedal",
                  a4: v11,
                  a5: 2u);
                this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v11, a3: 2u);
                ++nSlot;
                v3 = pAchievementMgr;
                v6 = nSlot;
              }
            }
          }
        }
        ++i;
      }
      while ( i < nAchievementMax );
      v5 = nAchievmentCount;
      v4 = nAchievementMax;
    }
    v14 = 0;
    if ( v5 > 0 && v4 != 0 )
      v14 = (int)(float)((float)((float)v5 / (float)v4) * 100.0);
    v15 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
    this->m_pScaleformUI->ValueArray_SetElement_5(this: this->m_pScaleformUI, a2: v15, a3: 0, a4: v14);
    this->m_pScaleformUI->Value_InvokeWithoutReturn(
      this: this->m_pScaleformUI,
      a2: this->m_FlashAPI,
      a3: "SetProgressBar",
      a4: v15,
      a5: 1u);
    this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v15, a3: 1u);
    V_snwprintf(pDest: wcCount, maxLen: 32, pFormat: L"%d / %d", nAchievmentCount, nAchievementMax);
    if ( this->m_pTextMedalsCount != nullptr )
      this->m_pTextMedalsCount->SetText(this: this->m_pTextMedalsCount, a2: wcCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102158B0
// Name: protected: void CUpsellScaleform::Show(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUpsellScaleform::Show(CUpsellScaleform *this)
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
// Address: 0x10215910
// Name: protected: void CUpsellScaleform::Hide(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUpsellScaleform::Hide(CUpsellScaleform *this, const char *szPostHideCommand)
{
  char i; // al
  IScaleformUI *m_pScaleformUI; // ecx
  void *v5; // edi

  if ( this->m_bFlashAPIIsValid )
  {
    for ( i = 1; ; i = 0 )
    {
      m_pScaleformUI = this->m_pScaleformUI;
      if ( i == 0 )
        break;
      if ( m_pScaleformUI != nullptr )
        m_pScaleformUI->LockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
      v5 = this->m_pScaleformUI->CreateValueArray(this: this->m_pScaleformUI, a2: 1);
      this->m_pScaleformUI->ValueArray_SetElement_2(this: this->m_pScaleformUI, a2: v5, a3: 0, a4: szPostHideCommand);
      g_pScaleformUI->Value_InvokeWithoutReturn(
        this: g_pScaleformUI,
        a2: this->m_FlashAPI,
        a3: "HidePanel",
        a4: v5,
        a5: 1u);
      this->m_pScaleformUI->ReleaseValueArray(this: this->m_pScaleformUI, a2: v5, a3: 1u);
    }
    if ( m_pScaleformUI != nullptr )
      m_pScaleformUI->UnlockSlot(this: m_pScaleformUI, a2: this->m_iFlashSlot);
    this->m_bVisible = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102159B0
// Name: protected: virtual void CUpsellScaleform::PostUnloadFlash(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUpsellScaleform::PostUnloadFlash(CUpsellScaleform *this)
{
  if ( CUpsellScaleform::m_pInstance != nullptr )
  {
    ScaleformFlashInterfaceMixin<ScaleformEmptyClass>::SafeReleaseSFTextObject(this, value: &this->m_pTextMedalsCount);
    if ( this != nullptr )
      ((void (__thiscall *)(CUpsellScaleform *, int))this->dtr_ScaleformFlashInterfaceMixin<ScaleformEmptyClass>)(
        a1: this,
        a2: 1);
    CUpsellScaleform::m_pInstance = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102159E0
// Name: public: void CUpsellScaleform::OnQuitPressed(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUpsellScaleform::OnQuitPressed(CUpsellScaleform *this, IScaleformUI *pui, IScaleformUI *obj)
{
  CUpsellScaleform::Hide(this, szPostHideCommand: "QuitNoConfirm");
}

//------------------------------------------------------------------------------
// Address: 0x102159F0
// Name: public: void CUpsellScaleform::OnBackPressed(class IScaleformUI __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUpsellScaleform::OnBackPressed(CUpsellScaleform *this, IScaleformUI *pui, IScaleformUI *obj)
{
  CUpsellScaleform::Hide(this, szPostHideCommand: "RestoreMainMenu");
}

//------------------------------------------------------------------------------
// Address: 0x10215A00
// Name: public: static void CUpsellScaleform::LoadDialog(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CUpsellScaleform::LoadDialog()
{
  CUpsellScaleform *v0; // eax

  if ( CUpsellScaleform::m_pInstance == nullptr )
  {
    v0 = (CUpsellScaleform *)MemAlloc_Alloc(nSize: 0x1Cu);
    if ( v0 != nullptr )
    {
      v0->m_bFlashAPIIsValid = false;
      v0->m_iFlashSlot = -1;
      v0->m_pScaleformUI = nullptr;
      v0->m_FlashAPI = nullptr;
      v0->__vftable = (CUpsellScaleform_vtbl *)&CUpsellScaleform::`vftable';
      *(_WORD *)&v0->m_bVisible = 0;
      v0->m_pTextMedalsCount = nullptr;
    }
    else
    {
      v0 = nullptr;
    }
    CUpsellScaleform::m_pInstance = v0;
    g_pScaleformUI->RequestElement(
      this: g_pScaleformUI,
      a2: 1,
      a3: "UpsellMenu",
      a4: (ScaleformUIFunctionHandlerObject *)v0,
      a5: pScaleformFunctionHandler_CUpsellScaleform_UpsellMenu);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10215A60
// Name: public: static void CUpsellScaleform::UnloadDialog(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CUpsellScaleform::UnloadDialog()
{
  if ( CUpsellScaleform::m_pInstance != nullptr )
    CUpsellScaleform::Hide(this: CUpsellScaleform::m_pInstance, szPostHideCommand: "None");
}

//------------------------------------------------------------------------------
// Address: 0x10215A80
// Name: public: static void CUpsellScaleform::ShowMenu(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CUpsellScaleform::ShowMenu(bool bShow)
{
  if ( !bShow || CUpsellScaleform::m_pInstance != nullptr )
  {
    if ( bShow != CUpsellScaleform::m_pInstance->m_bVisible )
    {
      if ( bShow )
        CUpsellScaleform::Show(this: CUpsellScaleform::m_pInstance);
      else
        CUpsellScaleform::Hide(this: CUpsellScaleform::m_pInstance, szPostHideCommand: "None");
    }
  }
  else
  {
    CUpsellScaleform::LoadDialog();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10215AC0
// Name: protected: virtual void CUpsellScaleform::FlashReady(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CUpsellScaleform::FlashReady(CUpsellScaleform *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  void *m_FlashAPI; // eax
  IScaleformUI *m_pScaleformUI; // ecx
  void *v6; // ebx
  void *v7; // edi
  void *v8; // ebx
  void *v9; // edi
  ISFTextObject *v10; // eax
  IScaleformUI *v11; // ecx
  void *topPanel; // [esp+4h] [ebp-8h]
  void *panel; // [esp+8h] [ebp-4h]

  m_FlashAPI = this->m_FlashAPI;
  if ( m_FlashAPI != nullptr )
  {
    m_pScaleformUI = this->m_pScaleformUI;
    if ( m_pScaleformUI != nullptr )
    {
      this->m_bLoading = false;
      v6 = m_pScaleformUI->Value_GetMember(this: m_pScaleformUI, a2: m_FlashAPI, a3: "TopPanel");
      topPanel = v6;
      if ( v6 != nullptr )
      {
        v7 = (void *)((int (__thiscall *)(IScaleformUI *, void *, const char *, int))this->m_pScaleformUI->Value_GetMember)(
                       a1: this->m_pScaleformUI,
                       a2: v6,
                       a3: "Panel",
                       a4: a3);
        panel = v7;
        if ( v7 != nullptr )
        {
          v8 = (void *)((int (__thiscall *)(IScaleformUI *, void *, const char *, int))this->m_pScaleformUI->Value_GetMember)(
                         a1: this->m_pScaleformUI,
                         a2: v7,
                         a3: "TextPanel",
                         a4: a2);
          if ( v8 != nullptr )
          {
            v9 = this->m_pScaleformUI->Value_GetMember(this: this->m_pScaleformUI, a2: v8, a3: "TotalCountPanel");
            if ( v9 != nullptr )
            {
              v10 = this->m_pScaleformUI->TextObject_MakeTextObjectFromMember(
                      this: this->m_pScaleformUI,
                      a2: v9,
                      a3: "TotalCount");
              v11 = this->m_pScaleformUI;
              this->m_pTextMedalsCount = v10;
              v11->ReleaseValue(this: v11, a2: v9);
            }
            this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v8);
            v7 = panel;
          }
          this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v7);
          v6 = topPanel;
        }
        this->m_pScaleformUI->ReleaseValue(this: this->m_pScaleformUI, a2: v6);
      }
      CUpsellScaleform::PopulateAchievements(this, a2: (int)v6);
      CUpsellScaleform::Show(this);
    }
  }
}
