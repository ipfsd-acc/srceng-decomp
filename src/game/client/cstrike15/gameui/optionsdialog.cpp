// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/optionsdialog.cpp
// Functions: 13
// ============================================================

#include "game\client\cstrike15\gameui\optionsdialog.h"

//------------------------------------------------------------------------------
// Address: 0x101D7EE0
// Name: public: static char const __near * COptionsDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COptionsDialog::GetPanelClassName()
{
  return "COptionsDialog";
}

//------------------------------------------------------------------------------
// Address: 0x101D7EF0
// Name: public: virtual void COptionsDialog::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsDialog::Activate(COptionsDialog *this)
{
  vgui::Frame::Activate(this);
  vgui::PropertyDialog::EnableApplyButton(this, bEnable: false);
}

//------------------------------------------------------------------------------
// Address: 0x101D7F10
// Name: protected: virtual void COptionsDialog::OnFinishedClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsDialog::OnFinishedClose(COptionsDialog *this)
{
  CCStrike15BasePanel *v2; // eax

  v2 = BasePanel();
  CBaseModPanel::NotifyVguiDialogClosed(this: v2);
  C_BaseAnimating::ShutdownBoneSetupThreadPool((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x101D7F30
// Name: public: virtual void COptionsDialog::OnGameUIHidden(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall COptionsDialog::OnGameUIHidden(COptionsDialog *this)
{
  int i; // ebx
  vgui::Panel *Child; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  for ( i = 0; i < vgui::Panel::GetChildCount(this); ++i )
  {
    Child = vgui::Panel::GetChild(this, index: i);
    if ( Child != nullptr )
    {
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: "GameUIHidden");
      else
        v5 = nullptr;
      ((void (__thiscall *)(COptionsDialog *, vgui::Panel *, KeyValues *, _DWORD))this->PostMessage)(
        a1: this,
        a2: Child,
        a3: v5,
        a4: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D7FA0
// Name: public: virtual struct vgui::PanelMessageMap __near * COptionsDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall COptionsDialog::GetMessageMap(COptionsDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`COptionsDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `COptionsDialog::GetMessageMap'::`2'::s_pMap;
  `COptionsDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "COptionsDialog");
  `COptionsDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D7FD0
// Name: public: virtual struct PanelAnimationMap __near * COptionsDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall COptionsDialog::GetAnimMap(COptionsDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "COptionsDialog");
}

//------------------------------------------------------------------------------
// Address: 0x101D7FE0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * COptionsDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall COptionsDialog::GetKBMap(COptionsDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`COptionsDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `COptionsDialog::GetKBMap'::`2'::s_pMap;
  `COptionsDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "COptionsDialog");
  `COptionsDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D8040
// Name: public: static void COptionsDialog::PanelMessageFunc_OnGameUIHidden::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall COptionsDialog::PanelMessageFunc_OnGameUIHidden::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  __m128i v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`COptionsDialog::PanelMessageFunc_OnGameUIHidden::InitVar'::`2'::bAdded )
  {
    `COptionsDialog::PanelMessageFunc_OnGameUIHidden::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "COptionsDialog");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "GameUIHidden";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D80D0
// Name: public: COptionsDialog::COptionsDialog(class vgui::Panel __near *,enum OptionsDialogTabStyle)
// Source: json
//------------------------------------------------------------------------------
COptionsDialog *__thiscall COptionsDialog::COptionsDialog(
        COptionsDialog *this,
        vgui::Panel *parent,
        OptionsDialogTabStyle iTabStyle)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CModInfo *v7; // eax
  CModInfo *v8; // eax
  COptionsSubDifficulty *v9; // eax
  COptionsSubDifficulty *v10; // eax
  CModInfo *v11; // eax
  COptionsSubPortal *v12; // eax
  COptionsSubPortal *v13; // eax
  COptionsSubKeyboard *v14; // eax
  COptionsSubKeyboard *v15; // eax
  COptionsSubMouse *v16; // eax
  COptionsSubMouse *v17; // eax
  COptionsSubAudio *v18; // eax
  COptionsSubAudio *v19; // eax
  COptionsSubVideo *v20; // eax
  COptionsSubVideo *v21; // eax
  CModInfo *v22; // eax
  COptionsSubVoice *v23; // eax
  COptionsSubVoice *v24; // eax
  CModInfo *v25; // eax
  CModInfo *v26; // eax
  CModInfo *v27; // eax
  CModInfo *v28; // eax
  COptionsSubMultiplayer *v29; // eax
  COptionsSubMultiplayer *v30; // eax
  COptionsSubKeyboard *v31; // eax
  COptionsSubKeyboard *v32; // eax
  vgui::PropertySheet *PropertySheet; // eax

  vgui::PropertyDialog::PropertyDialog(this, parent, panelName: "OptionsDialog");
  this->__vftable = (COptionsDialog_vtbl *)&COptionsDialog::`vftable';
  if ( `COptionsDialog::ChainToMap'::`2'::chained == 0 )
  {
    `COptionsDialog::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "COptionsDialog");
    v4->pfnClassName = COptionsDialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::PropertyDialog");
  }
  if ( `COptionsDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `COptionsDialog::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "COptionsDialog");
    v5->pfnClassName = COptionsDialog::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::PropertyDialog");
  }
  if ( `COptionsDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `COptionsDialog::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "COptionsDialog");
    v6->pfnClassName = COptionsDialog::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::PropertyDialog");
  }
  COptionsDialog::PanelMessageFunc_OnGameUIHidden::InitVar();
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 512, tall: 406);
  vgui::Frame::SetSizeable(this, state: false);
  if ( iTabStyle != OPTIONS_DIALOG_ALL_TABS )
  {
    if ( iTabStyle == OPTIONS_DIALOG_ONLY_BINDING_TABS )
    {
      vgui::Frame::SetTitle(this, title: "#L4D360UI_Controller_Edit_Keys_Buttons", surfaceTitle: true);
      v31 = (COptionsSubKeyboard *)MemAlloc_Alloc(nSize: 0x67Cu);
      if ( v31 != nullptr )
        v32 = COptionsSubKeyboard::COptionsSubKeyboard(this: v31, parent: this);
      else
        v32 = nullptr;
      vgui::PropertyDialog::AddPage(this, page: v32, title: "#GameUI_Console_UserSettings");
    }
  }
  else
  {
    vgui::Frame::SetTitle(this, title: "#GameUI_Options", surfaceTitle: true);
    v7 = ModInfo();
    if ( CModInfo::IsSinglePlayerOnly(this: v7) )
    {
      v8 = ModInfo();
      if ( !CModInfo::NoDifficulty(this: v8) )
      {
        v9 = (COptionsSubDifficulty *)MemAlloc_Alloc(nSize: 0x198u);
        if ( v9 != nullptr )
          v10 = COptionsSubDifficulty::COptionsSubDifficulty(this: v9, parent: this);
        else
          v10 = nullptr;
        vgui::PropertyDialog::AddPage(this, page: v10, title: "#GameUI_Difficulty");
      }
    }
    v11 = ModInfo();
    if ( CModInfo::HasPortals(this: v11) )
    {
      v12 = (COptionsSubPortal *)MemAlloc_Alloc(nSize: 0x198u);
      if ( v12 != nullptr )
        v13 = COptionsSubPortal::COptionsSubPortal(this: v12, parent: this);
      else
        v13 = nullptr;
      vgui::PropertyDialog::AddPage(this, page: v13, title: "#GameUI_Portal");
    }
    v14 = (COptionsSubKeyboard *)MemAlloc_Alloc(nSize: 0x67Cu);
    if ( v14 != nullptr )
      v15 = COptionsSubKeyboard::COptionsSubKeyboard(this: v14, parent: this);
    else
      v15 = nullptr;
    vgui::PropertyDialog::AddPage(this, page: v15, title: "#GameUI_Keyboard");
    v16 = (COptionsSubMouse *)MemAlloc_Alloc(nSize: 0x1D0u);
    if ( v16 != nullptr )
      v17 = COptionsSubMouse::COptionsSubMouse(this: v16, parent: this);
    else
      v17 = nullptr;
    vgui::PropertyDialog::AddPage(this, page: v17, title: "#GameUI_Mouse");
    v18 = (COptionsSubAudio *)MemAlloc_Alloc(nSize: 0x1B8u);
    if ( v18 != nullptr )
      v19 = COptionsSubAudio::COptionsSubAudio(this: v18, parent: this);
    else
      v19 = nullptr;
    this->m_pOptionsSubAudio = v19;
    vgui::PropertyDialog::AddPage(this, page: v19, title: "#GameUI_Audio");
    v20 = (COptionsSubVideo *)MemAlloc_Alloc(nSize: 0x1BCu);
    if ( v20 != nullptr )
      v21 = COptionsSubVideo::COptionsSubVideo(this: v20, parent: this);
    else
      v21 = nullptr;
    this->m_pOptionsSubVideo = v21;
    vgui::PropertyDialog::AddPage(this, page: v21, title: "#GameUI_Video");
    v22 = ModInfo();
    if ( !CModInfo::IsSinglePlayerOnly(this: v22) )
    {
      v23 = (COptionsSubVoice *)MemAlloc_Alloc(nSize: 0x1DCu);
      if ( v23 != nullptr )
        v24 = COptionsSubVoice::COptionsSubVoice(this: v23, parent: this);
      else
        v24 = nullptr;
      vgui::PropertyDialog::AddPage(this, page: v24, title: "#GameUI_Voice");
    }
    v25 = ModInfo();
    if ( CModInfo::IsMultiplayerOnly(this: v25) && (v26 = ModInfo(), !CModInfo::IsSinglePlayerOnly(this: v26))
      || (v27 = ModInfo(), !CModInfo::IsMultiplayerOnly(this: v27))
      && (v28 = ModInfo(), !CModInfo::IsSinglePlayerOnly(this: v28)) )
    {
      v29 = (COptionsSubMultiplayer *)MemAlloc_Alloc(nSize: 0x308u);
      if ( v29 != nullptr )
      {
        v30 = COptionsSubMultiplayer::COptionsSubMultiplayer(this: v29, parent: this);
        vgui::PropertyDialog::AddPage(this, page: v30, title: "#GameUI_Multiplayer");
      }
      else
      {
        vgui::PropertyDialog::AddPage(this, page: nullptr, title: "#GameUI_Multiplayer");
      }
    }
  }
  vgui::PropertyDialog::SetApplyButtonVisible(this, state: true);
  PropertySheet = vgui::PropertyDialog::GetPropertySheet(this);
  PropertySheet->SetTabWidth(this: PropertySheet, a2: 84);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103B19A0
// Name: public: class vgui::Menu __near * vgui::MenuItem::GetParentMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuItem::GetParentMenu(vgui::MenuItem *this)
{
  return (vgui::Menu *)this->GetParent(this);
}

//------------------------------------------------------------------------------
// Address: 0x103B2300
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuItem::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuItem::GetMessageMap(vgui::MenuItem *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuItem::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuItem::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuItem");
  `vgui::MenuItem::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103B2330
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuItem::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuItem::GetAnimMap(vgui::MenuItem *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuItem");
}

//------------------------------------------------------------------------------
// Address: 0x103B2340
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuItem::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuItem::GetKBMap(vgui::MenuItem *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuItem::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuItem::GetKBMap'::`2'::s_pMap;
  `vgui::MenuItem::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuItem");
  `vgui::MenuItem::GetKBMap'::`2'::s_pMap = result;
  return result;
}
