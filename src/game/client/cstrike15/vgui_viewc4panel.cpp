// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/vgui_viewc4panel.cpp
// Functions: 9
// ============================================================

#include "game\client\cstrike15\vgui_viewc4panel.h"

//------------------------------------------------------------------------------
// Address: 0x100956E0
// Name: public: virtual class vgui::Panel __near * CPanelFactory<class CVGuiScreenPanel,struct VGuiScreenInitData_t>::Create(char const __near *,class KeyValues __near *,void __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::EditablePanel *__thiscall CPanelFactory<CVGuiScreenPanel,VGuiScreenInitData_t>::Create(
        CPanelFactory<CVGuiScreenPanel,VGuiScreenInitData_t> *this,
        const char *pMetaClassName,
        KeyValues *pKeyValues,
        void *pVoidInitData,
        vgui::Panel *pParent)
{
  vgui::EditablePanel *v5; // esi

  v5 = (vgui::EditablePanel *)MemAlloc_Alloc(nSize: 0x180u);
  if ( v5 == nullptr )
    return nullptr;
  vgui::EditablePanel::EditablePanel(this: v5, parent: pParent, panelName: pMetaClassName);
  v5->__vftable = (vgui::EditablePanel_vtbl *)&CVGuiScreenPanel::`vftable';
  v5[1].__vftable = (vgui::EditablePanel_vtbl *)-1;
  if ( ((unsigned __int8 (__thiscall *)(vgui::EditablePanel *, KeyValues *, void *))v5->__vftable[1].GetVPanel)(
         a1: v5,
         a2: pKeyValues,
         a3: pVoidInitData) == 0 )
  {
    ((void (__thiscall *)(vgui::EditablePanel *, int))v5->dtr_Panel)(a1: v5, a2: 1);
    return nullptr;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10186540
// Name: public: virtual class vgui::Panel __near * CPanelFactory<class CMovieDisplayScreen,struct VGuiScreenInitData_t>::Create(char const __near *,class KeyValues __near *,void __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CMovieDisplayScreen *__thiscall CPanelFactory<CMovieDisplayScreen,VGuiScreenInitData_t>::Create(
        CPanelFactory<CMovieDisplayScreen,VGuiScreenInitData_t> *this,
        const char *pMetaClassName,
        KeyValues *pKeyValues,
        VGuiScreenInitData_t *pVoidInitData,
        vgui::Panel *pParent)
{
  CMovieDisplayScreen *v5; // eax
  CMovieDisplayScreen *result; // eax
  vgui::Panel *v7; // esi

  v5 = (CMovieDisplayScreen *)MemAlloc_Alloc(nSize: 0x1B8u);
  if ( v5 == nullptr )
    return nullptr;
  result = CMovieDisplayScreen::CMovieDisplayScreen(this: v5, parent: pParent, panelName: pMetaClassName);
  v7 = result;
  if ( result != nullptr )
  {
    if ( result->Init(this: result, a2: pKeyValues, a3: pVoidInitData) )
    {
      return (CMovieDisplayScreen *)v7;
    }
    else
    {
      ((void (__thiscall *)(vgui::Panel *, int))v7->dtr_Panel)(a1: v7, a2: 1);
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10188F00
// Name: public: virtual class vgui::Panel __near * CPanelFactory<class CSlideshowDisplayScreen,struct VGuiScreenInitData_t>::Create(char const __near *,class KeyValues __near *,void __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CSlideshowDisplayScreen *__thiscall CPanelFactory<CSlideshowDisplayScreen,VGuiScreenInitData_t>::Create(
        CPanelFactory<CSlideshowDisplayScreen,VGuiScreenInitData_t> *this,
        const char *pMetaClassName,
        KeyValues *pKeyValues,
        VGuiScreenInitData_t *pVoidInitData,
        vgui::Panel *pParent)
{
  CSlideshowDisplayScreen *v5; // eax
  CSlideshowDisplayScreen *result; // eax
  vgui::Panel *v7; // esi

  v5 = (CSlideshowDisplayScreen *)MemAlloc_Alloc(nSize: 0x1A8u);
  if ( v5 == nullptr )
    return nullptr;
  result = CSlideshowDisplayScreen::CSlideshowDisplayScreen(this: v5, parent: pParent, panelName: pMetaClassName);
  v7 = result;
  if ( result != nullptr )
  {
    if ( result->Init(this: result, a2: pKeyValues, a3: pVoidInitData) )
    {
      return (CSlideshowDisplayScreen *)v7;
    }
    else
    {
      ((void (__thiscall *)(vgui::Panel *, int))v7->dtr_Panel)(a1: v7, a2: 1);
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10227ED0
// Name: public: virtual class vgui::Panel __near * CPanelFactory<class CC4Panel,struct VGuiScreenInitData_t>::Create(char const __near *,class KeyValues __near *,void __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CC4Panel *__thiscall CPanelFactory<CC4Panel,VGuiScreenInitData_t>::Create(
        CPanelFactory<CC4Panel,VGuiScreenInitData_t> *this,
        const char *pMetaClassName,
        KeyValues *pKeyValues,
        VGuiScreenInitData_t *pVoidInitData,
        vgui::Panel *pParent)
{
  CC4Panel *v5; // eax
  CC4Panel *result; // eax
  vgui::Panel *v7; // esi

  v5 = (CC4Panel *)MemAlloc_Alloc(nSize: 0x19Cu);
  if ( v5 == nullptr )
    return nullptr;
  result = CC4Panel::CC4Panel(this: v5, parent: pParent, panelName: pMetaClassName);
  v7 = result;
  if ( result != nullptr )
  {
    if ( result->Init(this: result, a2: pKeyValues, a3: pVoidInitData) )
    {
      return (CC4Panel *)v7;
    }
    else
    {
      ((void (__thiscall *)(vgui::Panel *, int))v7->dtr_Panel)(a1: v7, a2: 1);
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10228240
// Name: public: virtual void CViewC4Panel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewC4Panel::ApplySchemeSettings(CViewC4Panel *this, vgui::IScheme *pScheme)
{
  vgui::Label_vtbl *v4; // ebx
  Color *v5; // eax
  _DWORD *v6; // eax
  _BYTE v7[4]; // [esp+8h] [ebp-8h] BYREF
  _BYTE v8[4]; // [esp+Ch] [ebp-4h] BYREF
  vgui::IScheme *pSchemea; // [esp+18h] [ebp+8h]

  if ( pScheme != nullptr )
  {
    v4 = this->m_pTimeLabel->__vftable;
    pSchemea = (vgui::IScheme *)pScheme->__vftable;
    v5 = this->GetFgColor(this, result: v8);
    v6 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, _BYTE *, const char *, _DWORD))pSchemea[5].__vftable)(
                     a1: pScheme,
                     a2: v7,
                     a3: "C4Panel_Armed",
                     a4: *v5);
    ((void (__thiscall *)(vgui::Label *, _DWORD))v4->SetFgColor)(a1: this->m_pTimeLabel, a2: *v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102282A0
// Name: public: CViewC4Panel::CViewC4Panel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CViewC4Panel *__thiscall CViewC4Panel::CViewC4Panel(CViewC4Panel *this, vgui::Panel *parent, const char *panelName)
{
  vgui::ISchemeManager *v3; // edi
  vgui::ISchemeManager_vtbl *v4; // ebx
  int v6; // eax
  unsigned int v7; // eax
  vgui::Label *v8; // eax

  v3 = g_pVGuiSchemeManager;
  v4 = g_pVGuiSchemeManager->__vftable;
  v6 = ((int (__thiscall *)(IEngineVGui *, int, const char *, const char *))enginevgui->GetPanel)(
         a1: enginevgui,
         a2: 2,
         a3: "resource/C4Panel.res",
         a4: "ClientScheme");
  v7 = ((int (__thiscall *)(vgui::ISchemeManager *, int))v4->LoadSchemeFromFileEx)(a1: v3, a2: v6);
  CVGuiScreenPanel::CVGuiScreenPanel(this, parent, panelName: "CViewC4Panel", hScheme: v7);
  this->__vftable = (CViewC4Panel_vtbl *)&CViewC4Panel::`vftable';
  vgui::Panel::SetSize(this, wide: 10, tall: 10);
  v8 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v8 != nullptr )
    this->m_pTimeLabel = vgui::Label::Label(this: v8, parent: this, panelName: "TimerLabel", text: prType);
  else
    this->m_pTimeLabel = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10228370
// Name: public: virtual class vgui::Panel __near * CPanelFactory<class CViewC4Panel,struct VGuiScreenInitData_t>::Create(char const __near *,class KeyValues __near *,void __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CViewC4Panel *__thiscall CPanelFactory<CViewC4Panel,VGuiScreenInitData_t>::Create(
        CPanelFactory<CViewC4Panel,VGuiScreenInitData_t> *this,
        const char *pMetaClassName,
        KeyValues *pKeyValues,
        VGuiScreenInitData_t *pVoidInitData,
        vgui::Panel *pParent)
{
  CViewC4Panel *v5; // eax
  CViewC4Panel *result; // eax
  vgui::Panel *v7; // esi

  v5 = (CViewC4Panel *)MemAlloc_Alloc(nSize: 0x184u);
  if ( v5 == nullptr )
    return nullptr;
  result = CViewC4Panel::CViewC4Panel(this: v5, parent: pParent, panelName: pMetaClassName);
  v7 = result;
  if ( result != nullptr )
  {
    if ( result->Init(this: result, a2: pKeyValues, a3: pVoidInitData) )
    {
      return (CViewC4Panel *)v7;
    }
    else
    {
      ((void (__thiscall *)(vgui::Panel *, int))v7->dtr_Panel)(a1: v7, a2: 1);
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102283E0
// Name: public: class C_BaseCombatWeapon __near * CViewC4Panel::GetOwningWeapon(void)
// Source: json
//------------------------------------------------------------------------------
C_BaseCombatWeapon *__thiscall CViewC4Panel::GetOwningWeapon(CViewC4Panel *this)
{
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // eax
  IHandleEntity_vtbl *v4; // ecx
  IHandleEntity *v5; // eax
  int v6; // eax
  int v7; // esi

  m_Index = this->m_hEntity.m_Index;
  if ( m_Index == -1 )
    return nullptr;
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity == nullptr )
    return nullptr;
  v4 = m_pEntity[80].__vftable;
  if ( v4 == (IHandleEntity_vtbl *)-1 )
    return nullptr;
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != (unsigned int)v4 >> 16 )
    return nullptr;
  v5 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_pEntity;
  if ( v5 == nullptr )
    return nullptr;
  v6 = (int)v5->__vftable[14].GetRefEHandle(this: v5);
  v7 = v6;
  if ( v6 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v6 + 844))(a1: v6) != 0 )
    return (*(C_BaseCombatWeapon *(__thiscall **)(int))(*(_DWORD *)v7 + 920))(a1: v7);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10228470
// Name: public: virtual void CViewC4Panel::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewC4Panel::OnTick(CViewC4Panel *this)
{
  C_BaseCombatWeapon *OwningWeapon; // eax
  C_C4 *v3; // eax
  const char *ScreenText; // eax

  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
  this->SetVisible(this, a2: true);
  OwningWeapon = CViewC4Panel::GetOwningWeapon(this);
  v3 = (C_C4 *)__RTDynamicCast(
                 inptr: OwningWeapon,
                 VfDelta: 0,
                 SrcType: &C_BaseEntity `RTTI Type Descriptor',
                 TargetType: &C_C4 `RTTI Type Descriptor',
                 isReference: 0);
  if ( v3 != nullptr )
  {
    ScreenText = C_C4::GetScreenText(this: v3);
    if ( ScreenText != nullptr )
      this->m_pTimeLabel->SetText(this: this->m_pTimeLabel, a2: ScreenText);
  }
}
