// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/vgui/dialogs/themesdialog.cpp
// Functions: 24
// ============================================================

#include "missionchooser\vgui\dialogs\themesdialog.h"

//------------------------------------------------------------------------------
// Address: 0x10030C90
// Name: public: static char const __near * CThemesDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CThemesDialog::GetPanelClassName()
{
  return "CThemesDialog";
}

//------------------------------------------------------------------------------
// Address: 0x10030CA0
// Name: public: static char const __near * CThemeDetails::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CThemeDetails::GetPanelClassName()
{
  return "CThemeDetails";
}

//------------------------------------------------------------------------------
// Address: 0x10030CB0
// Name: public: virtual CThemesDialog::~CThemesDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThemesDialog::~CThemesDialog(CThemesDialog *this)
{
  this->__vftable = (CThemesDialog_vtbl *)&CThemesDialog::`vftable';
  if ( g_pThemesDialog == this )
    g_pThemesDialog = nullptr;
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x10030CD0
// Name: public: virtual void CThemesDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThemesDialog::OnCommand(CThemesDialog *this, const char *command)
{
  CThemeEditDialog *v3; // eax
  CThemeEditDialog *v4; // esi
  CLevelTheme *v5; // eax
  CLevelTheme *v6; // eax
  CThemeEditDialog *v7; // eax
  CThemeEditDialog *v8; // esi

  if ( _V_stricmp(s1: command, s2: "Edit") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "New") == 0 )
    {
      v5 = (CLevelTheme *)operator new(nSize: 0x26Cu);
      if ( v5 != nullptr )
      {
        v6 = CLevelTheme::CLevelTheme(
               this: v5,
               szName: szDescription,
               szDescription: szDescription,
               bRequiresVMFTweak: false);
        if ( v6 != nullptr )
        {
          CLevelTheme::SetCurrentTheme(pTheme: v6);
          if ( CLevelTheme::s_pCurrentTheme != nullptr )
          {
            v7 = (CThemeEditDialog *)operator new(nSize: 0x22Cu);
            if ( v7 != nullptr )
              v8 = CThemeEditDialog::CThemeEditDialog(
                     this: v7,
                     parent: this,
                     name: "ThemeEditDialog",
                     pTheme: CLevelTheme::s_pCurrentTheme,
                     bCreatingNew: true);
            else
              v8 = nullptr;
            v8->AddActionSignalTarget_2(this: v8, a2: this);
            v8->DoModal(this: v8);
          }
        }
      }
    }
    goto LABEL_15;
  }
  if ( CLevelTheme::s_pCurrentTheme == nullptr )
  {
LABEL_15:
    vgui::Frame::OnCommand(this, command);
    return;
  }
  v3 = (CThemeEditDialog *)operator new(nSize: 0x22Cu);
  if ( v3 != nullptr )
    v4 = CThemeEditDialog::CThemeEditDialog(
           this: v3,
           parent: this,
           name: "ThemeEditDialog",
           pTheme: CLevelTheme::s_pCurrentTheme,
           bCreatingNew: false);
  else
    v4 = nullptr;
  v4->AddActionSignalTarget_2(this: v4, a2: this);
  v4->DoModal(this: v4);
  this->PopulateThemeList(this);
  vgui::Frame::OnCommand(this, command);
}

//------------------------------------------------------------------------------
// Address: 0x10030E00
// Name: public: virtual void CThemesDialog::OnThemeChanged(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThemesDialog::OnThemeChanged(CThemesDialog *this, KeyValues *params)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  this->PopulateThemeList(this);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "UpdateCurrentTheme");
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030E50
// Name: public: virtual void CThemesDialog::OnThemeDetailsClicked(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThemesDialog::OnThemeDetailsClicked(CThemesDialog *this, vgui::Panel *pPanel)
{
  CThemeDetails *v3; // eax

  if ( pPanel != nullptr )
  {
    v3 = (CThemeDetails *)__RTDynamicCast(
                            inptr: pPanel,
                            VfDelta: 0,
                            SrcType: &vgui::Panel `RTTI Type Descriptor',
                            TargetType: &CThemeDetails `RTTI Type Descriptor',
                            isReference: 0);
    if ( v3 != nullptr )
      this->ThemeClicked(this, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10030E90
// Name: public: virtual void CThemesDialog::ThemeClicked(class CThemeDetails __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThemesDialog::ThemeClicked(CThemesDialog *this, CThemeDetails *pThemeDetails)
{
  vgui::PanelListPanel *m_pThemePanelList; // ecx
  int v4; // edi
  vgui::Panel *v5; // esi
  int iPanels; // [esp+Ch] [ebp+8h]

  CLevelTheme::SetCurrentTheme(pTheme: pThemeDetails->m_pTheme);
  this->m_pCurrentThemeLabel->SetText(this: this->m_pCurrentThemeLabel, a2: (const char *)CLevelTheme::s_pCurrentTheme);
  m_pThemePanelList = this->m_pThemePanelList;
  if ( m_pThemePanelList != nullptr )
  {
    v4 = 0;
    iPanels = vgui::PanelListPanel::GetItemCount(this: (vgui::TextEntry *)m_pThemePanelList);
    if ( iPanels > 0 )
    {
      do
      {
        v5 = this->m_pThemePanelList->GetItemPanel(this: this->m_pThemePanelList, a2: v4);
        if ( v5 != nullptr )
        {
          v5->InvalidateLayout(this: v5, a2: false, a3: false);
          v5->OnThink(this: v5);
        }
        ++v4;
      }
      while ( v4 < iPanels );
    }
  }
  this->OnThemeChanged(this, a2: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10030F30
// Name: public: virtual bool CThemesDialog::ShouldHighlight(class CThemeDetails __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CThemesDialog::ShouldHighlight(CThemesDialog *this, CThemeDetails *pDetails)
{
  return pDetails != nullptr && CLevelTheme::s_pCurrentTheme == pDetails->m_pTheme;
}

//------------------------------------------------------------------------------
// Address: 0x10030F60
// Name: public: void CThemeDetails::SetTheme(class CLevelTheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThemeDetails::SetTheme(CThemeDetails *this, CLevelTheme *pTheme)
{
  void (__thiscall *SetText)(vgui::Label *, const char *); // eax
  int v4; // [esp+0h] [ebp-10Ch]
  char buffer[260]; // [esp+8h] [ebp-104h] BYREF

  if ( this->m_pTheme != pTheme )
  {
    this->m_pTheme = pTheme;
    buffer[0] = 0;
    if ( pTheme != nullptr )
      V_snprintf(pDest: buffer, maxLen: 260, pFormat: "tilegen/themes/%s.tga", pTheme->m_szName);
    CMissionChooserTGAImagePanel::SetTGA(this: this->m_pTGAImagePanel, filename: buffer, pPathID: nullptr);
    SetText = this->m_pNameLabel->SetText;
    if ( pTheme != nullptr )
    {
      ((void (__stdcall *)(CLevelTheme *, int))SetText)(a1: pTheme, a2: v4);
      this->m_pDescriptionLabel->SetText(this: this->m_pDescriptionLabel, a2: pTheme->m_szDescription);
    }
    else
    {
      ((void (__stdcall *)(const char *, int))SetText)(a1: "No theme selected", a2: v4);
      this->m_pDescriptionLabel->SetText(this: this->m_pDescriptionLabel, a2: szDescription);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031000
// Name: public: virtual void CThemeDetails::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThemeDetails::ApplySchemeSettings(CThemeDetails *this, vgui::IScheme *pScheme)
{
  void (__thiscall *SetPaintBackgroundEnabled)(vgui::Panel *, bool); // eax

  vgui::Panel::ApplySchemeSettings(this, pScheme);
  this->m_pNameLabel->SetPaintBackgroundEnabled(this: this->m_pNameLabel, a2: false);
  this->m_pDescriptionLabel->SetPaintBackgroundEnabled(this: this->m_pDescriptionLabel, a2: false);
  SetPaintBackgroundEnabled = this->m_pNameLabel->SetPaintBackgroundEnabled;
  if ( this->m_bCurrentTheme )
    ((void (__stdcall *)(int))SetPaintBackgroundEnabled)(a1: 1);
  else
    ((void (__stdcall *)(_DWORD))SetPaintBackgroundEnabled)(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10031060
// Name: public: virtual void CThemeDetails::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThemeDetails::PerformLayout(CThemeDetails *this)
{
  int m_iDesiredWidth; // edi
  int v3; // ebx
  int v4; // edi
  int m_iDesiredHeight; // [esp-Ch] [ebp-10h]

  vgui::Panel::PerformLayout(this);
  if ( this->GetParent(this) != nullptr )
  {
    vgui::Panel::SetSize(this, wide: this->m_iDesiredWidth, tall: this->m_iDesiredHeight);
    m_iDesiredWidth = this->m_iDesiredWidth;
    m_iDesiredHeight = this->m_iDesiredHeight;
    v3 = (int)(float)((float)m_iDesiredHeight * 1.3333334);
    vgui::Panel::SetBounds(this: this->m_pTGAImagePanel, x: 0, y: 0, wide: v3, tall: m_iDesiredHeight);
    v4 = m_iDesiredWidth - v3 + 8;
    v3 += 8;
    vgui::Panel::SetBounds(this: this->m_pNameLabel, x: v3, y: 0, wide: v4, tall: 24);
    vgui::Panel::SetBounds(this: this->m_pDescriptionLabel, x: v3, y: 24, wide: v4, tall: this->m_iDesiredHeight - 24);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031100
// Name: public: virtual void CThemeDetails::OnMouseReleased(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThemeDetails::OnMouseReleased(CThemeDetails *this, ButtonCode_t code)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ThemeDetailsClicked");
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031150
// Name: public: virtual void CThemeDetails::OnThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThemeDetails::OnThink(CThemeDetails *this)
{
  CThemesDialog *m_pThemesDialog; // ecx
  bool v3; // al
  vgui::Label *m_pNameLabel; // ecx
  void (__thiscall *SetPaintBackgroundEnabled)(vgui::Panel *, bool); // edx

  m_pThemesDialog = this->m_pThemesDialog;
  v3 = m_pThemesDialog != nullptr && m_pThemesDialog->ShouldHighlight(this: m_pThemesDialog, a2: this);
  m_pNameLabel = this->m_pNameLabel;
  this->m_bCurrentTheme = v3;
  SetPaintBackgroundEnabled = m_pNameLabel->SetPaintBackgroundEnabled;
  if ( v3 )
    ((void (__stdcall *)(int))SetPaintBackgroundEnabled)(a1: 1);
  else
    ((void (__stdcall *)(_DWORD))SetPaintBackgroundEnabled)(a1: 0);
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x100311C0
// Name: public: virtual struct vgui::PanelMessageMap __near * CThemesDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CThemesDialog::GetMessageMap(CThemesDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CThemesDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CThemesDialog::GetMessageMap'::`2'::s_pMap;
  `CThemesDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CThemesDialog");
  `CThemesDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100311F0
// Name: public: virtual struct PanelAnimationMap __near * CThemesDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CThemesDialog::GetAnimMap(CThemesDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CThemesDialog");
}

//------------------------------------------------------------------------------
// Address: 0x10031200
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CThemesDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CThemesDialog::GetKBMap(CThemesDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CThemesDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CThemesDialog::GetKBMap'::`2'::s_pMap;
  `CThemesDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CThemesDialog");
  `CThemesDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10031230
// Name: public: virtual struct vgui::PanelMessageMap __near * CThemeDetails::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CThemeDetails::GetMessageMap(CThemeDetails *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CThemeDetails::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CThemeDetails::GetMessageMap'::`2'::s_pMap;
  `CThemeDetails::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CThemeDetails");
  `CThemeDetails::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10031260
// Name: public: virtual struct PanelAnimationMap __near * CThemeDetails::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CThemeDetails::GetAnimMap(CThemeDetails *this)
{
  return FindOrAddPanelAnimationMap(className: "CThemeDetails");
}

//------------------------------------------------------------------------------
// Address: 0x10031270
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CThemeDetails::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CThemeDetails::GetKBMap(CThemeDetails *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CThemeDetails::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CThemeDetails::GetKBMap'::`2'::s_pMap;
  `CThemeDetails::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CThemeDetails");
  `CThemeDetails::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100312E0
// Name: public: CThemeDetails::CThemeDetails(class vgui::Panel __near *,char const __near *,class CThemesDialog __near *)
// Source: json
//------------------------------------------------------------------------------
CThemeDetails *__thiscall CThemeDetails::CThemeDetails(
        CThemeDetails *this,
        vgui::Panel *parent,
        const char *name,
        CThemesDialog *pThemesDialog)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  CMissionChooserTGAImagePanel *v8; // eax
  CMissionChooserTGAImagePanel *v9; // eax
  vgui::Label *v10; // eax
  vgui::Label *v11; // eax
  vgui::Label *v12; // eax
  vgui::Label *v13; // eax

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (CThemeDetails_vtbl *)&CThemeDetails::`vftable';
  if ( `CThemeDetails::ChainToMap'::`2'::chained == 0 )
  {
    `CThemeDetails::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CThemeDetails");
    v5->pfnClassName = CThemeDetails::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CThemeDetails::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CThemeDetails::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CThemeDetails");
    v6->pfnClassName = CThemeDetails::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CThemeDetails::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CThemeDetails::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CThemeDetails");
    v7->pfnClassName = CThemeDetails::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  this->m_pThemesDialog = pThemesDialog;
  this->m_pTheme = nullptr;
  v8 = (CMissionChooserTGAImagePanel *)operator new(nSize: 0x258u);
  if ( v8 != nullptr )
    v9 = CMissionChooserTGAImagePanel::CMissionChooserTGAImagePanel(this: v8, parent: this, name: "TGAThemeImage");
  else
    v9 = nullptr;
  this->m_pTGAImagePanel = v9;
  v9->SetMouseInputEnabled(this: v9, a2: false);
  this->m_pTGAImagePanel->SetKeyBoardInputEnabled(this: this->m_pTGAImagePanel, a2: false);
  v10 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v10 != nullptr )
    v11 = vgui::Label::Label(this: v10, parent: this, panelName: "ThemeName", text: "Theme");
  else
    v11 = nullptr;
  this->m_pNameLabel = v11;
  v11->SetMouseInputEnabled(this: v11, a2: false);
  this->m_pNameLabel->SetKeyBoardInputEnabled(this: this->m_pNameLabel, a2: false);
  this->m_pNameLabel->SetPaintBackgroundEnabled(this: this->m_pNameLabel, a2: false);
  v12 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v12 != nullptr )
    v13 = vgui::Label::Label(this: v12, parent: this, panelName: "ThemeDesc", text: "Desc");
  else
    v13 = nullptr;
  this->m_pDescriptionLabel = v13;
  v13->SetMouseInputEnabled(this: v13, a2: false);
  this->m_pDescriptionLabel->SetKeyBoardInputEnabled(this: this->m_pDescriptionLabel, a2: false);
  vgui::Label::SetWrap(this: this->m_pDescriptionLabel, bWrap: true);
  vgui::Panel::SetMouseInputEnabled(this, state: true);
  this->m_iDesiredHeight = 80;
  this->m_iDesiredWidth = 400;
  this->m_bCurrentTheme = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10031510
// Name: public: virtual void CThemesDialog::PopulateThemeList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThemesDialog::PopulateThemeList(CThemesDialog *this)
{
  int i; // ebx
  CThemeDetails *v3; // eax
  CThemeDetails *v4; // esi
  int Wide; // eax
  CThemeDetails_vtbl *v6; // edx
  vgui::Label_vtbl *v7; // edx

  vgui::PanelListPanel::RemoveAll(this: this->m_pThemePanelList);
  for ( i = 0; i < CLevelTheme::s_LevelThemes.m_Size; ++i )
  {
    v3 = (CThemeDetails *)operator new(nSize: 0x170u);
    if ( v3 != nullptr )
      v4 = CThemeDetails::CThemeDetails(this: v3, parent: this, name: "ThemeDetails", pThemesDialog: this);
    else
      v4 = nullptr;
    CThemeDetails::SetTheme(this: v4, pTheme: CLevelTheme::s_LevelThemes.m_Memory.m_pMemory[i]);
    Wide = vgui::Panel::GetWide(this);
    v6 = v4->__vftable;
    v4->m_iDesiredWidth = Wide - 55;
    v6->InvalidateLayout(this: v4, a2: true, a3: false);
    this->m_pThemePanelList->AddItem(this: this->m_pThemePanelList, a2: nullptr, a3: v4);
  }
  v7 = this->m_pCurrentThemeLabel->__vftable;
  if ( CLevelTheme::s_pCurrentTheme != nullptr )
    ((void (__stdcall *)(CLevelTheme *))v7->SetText)(a1: CLevelTheme::s_pCurrentTheme);
  else
    ((void (__stdcall *)(const char *))v7->SetText)(a1: "None");
}

//------------------------------------------------------------------------------
// Address: 0x100315D0
// Name: public: static void CThemesDialog::PanelMessageFunc_OnThemeChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CThemesDialog::PanelMessageFunc_OnThemeChanged::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CThemesDialog::PanelMessageFunc_OnThemeChanged::InitVar'::`2'::bAdded )
  {
    `CThemesDialog::PanelMessageFunc_OnThemeChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1128,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CThemesDialog");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "ThemeChanged";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031660
// Name: public: static void CThemesDialog::PanelMessageFunc_OnThemeDetailsClicked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CThemesDialog::PanelMessageFunc_OnThemeDetailsClicked::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CThemesDialog::PanelMessageFunc_OnThemeDetailsClicked::InitVar'::`2'::bAdded )
  {
    `CThemesDialog::PanelMessageFunc_OnThemeDetailsClicked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1132,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CThemesDialog");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "ThemeDetailsClicked";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_PTR;
    v4.firstParamName = "panel";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10031700
// Name: public: CThemesDialog::CThemesDialog(class vgui::Panel __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CThemesDialog *__thiscall CThemesDialog::CThemesDialog(
        CThemesDialog *this,
        vgui::Panel *parent,
        const char *name,
        bool bGlobal)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  vgui::PanelListPanel *v8; // eax
  vgui::PanelListPanel *v9; // eax
  vgui::Label *v10; // eax
  vgui::Label *v11; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: name, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CThemesDialog_vtbl *)&CThemesDialog::`vftable';
  if ( `CThemesDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CThemesDialog::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CThemesDialog");
    v5->pfnClassName = CThemesDialog::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CThemesDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CThemesDialog::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CThemesDialog");
    v6->pfnClassName = CThemesDialog::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CThemesDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CThemesDialog::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CThemesDialog");
    v7->pfnClassName = CThemesDialog::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CThemesDialog::PanelMessageFunc_OnThemeChanged::InitVar(a1: (int)&savedregs);
  CThemesDialog::PanelMessageFunc_OnThemeDetailsClicked::InitVar(a1: (int)&savedregs);
  if ( bGlobal )
    g_pThemesDialog = this;
  v8 = (vgui::PanelListPanel *)operator new(nSize: 0x1ACu);
  if ( v8 != nullptr )
    v9 = vgui::PanelListPanel::PanelListPanel(this: v8, parent: this, panelName: "ThemePanelListPanel");
  else
    v9 = nullptr;
  this->m_pThemePanelList = v9;
  vgui::PanelListPanel::SetFirstColumnWidth(this: v9, width: 0);
  vgui::Panel::SetSize(this, wide: 384, tall: 420);
  vgui::Panel::SetMinimumSize(this, wide: 200, tall: 50);
  vgui::Frame::SetMinimizeButtonVisible(this, state: false);
  v10 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v10 != nullptr )
    v11 = vgui::Label::Label(this: v10, parent: this, panelName: "CurrentThemePanel", text: "None");
  else
    v11 = nullptr;
  this->m_pCurrentThemeLabel = v11;
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "ThemesDialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::MoveToCenterOfScreen(this);
  CThemesDialog::PopulateThemeList(this);
  return this;
}
