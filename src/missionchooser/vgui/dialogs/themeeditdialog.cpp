// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/vgui/dialogs/themeeditdialog.cpp
// Functions: 6
// ============================================================

#include "missionchooser\vgui\dialogs\themeeditdialog.h"

//------------------------------------------------------------------------------
// Address: 0x10030650
// Name: public: static char const __near * CThemeEditDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CThemeEditDialog::GetPanelClassName()
{
  return "CThemeEditDialog";
}

//------------------------------------------------------------------------------
// Address: 0x10030660
// Name: public: virtual struct vgui::PanelMessageMap __near * CThemeEditDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CThemeEditDialog::GetMessageMap(CThemeEditDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CThemeEditDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CThemeEditDialog::GetMessageMap'::`2'::s_pMap;
  `CThemeEditDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CThemeEditDialog");
  `CThemeEditDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10030690
// Name: public: virtual struct PanelAnimationMap __near * CThemeEditDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CThemeEditDialog::GetAnimMap(CThemeEditDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CThemeEditDialog");
}

//------------------------------------------------------------------------------
// Address: 0x100306A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CThemeEditDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CThemeEditDialog::GetKBMap(CThemeEditDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CThemeEditDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CThemeEditDialog::GetKBMap'::`2'::s_pMap;
  `CThemeEditDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CThemeEditDialog");
  `CThemeEditDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100306D0
// Name: public: CThemeEditDialog::CThemeEditDialog(class vgui::Panel __near *,char const __near *,class CLevelTheme __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CThemeEditDialog *__thiscall CThemeEditDialog::CThemeEditDialog(
        CThemeEditDialog *this,
        vgui::Panel *parent,
        const char *name,
        CLevelTheme *pTheme,
        bool bCreatingNew)
{
  vgui::PanelMessageMap *v6; // edi
  PanelAnimationMap *v7; // edi
  vgui::PanelKeyBindingMap *v8; // edi
  vgui::TextEntry *v9; // eax
  vgui::TextEntry *v10; // eax
  vgui::TextEntry *v11; // eax
  vgui::TextEntry *v12; // eax
  vgui::TextEntry *v13; // eax
  vgui::TextEntry *v14; // eax
  vgui::CheckButton *v15; // eax
  vgui::CheckButton *v16; // eax
  char buffer[128]; // [esp+Ch] [ebp-80h] BYREF

  vgui::Frame::Frame(this, parent, panelName: name, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CThemeEditDialog_vtbl *)&CThemeEditDialog::`vftable';
  if ( `CThemeEditDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CThemeEditDialog::ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelMessageMap(className: "CThemeEditDialog");
    v6->pfnClassName = CThemeEditDialog::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CThemeEditDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CThemeEditDialog::ChainToAnimationMap'::`2'::chained = 1;
    v7 = FindOrAddPanelAnimationMap(className: "CThemeEditDialog");
    v7->pfnClassName = CThemeEditDialog::GetPanelClassName;
    v7->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CThemeEditDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CThemeEditDialog::KB_ChainToMap'::`2'::chained = 1;
    v8 = vgui::FindOrAddPanelKeyBindingMap(className: "CThemeEditDialog");
    v8->pfnClassName = CThemeEditDialog::GetPanelClassName;
    v8->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  g_pThemeEditDialog = this;
  this->m_bCreatingNew = bCreatingNew;
  this->m_pLevelTheme = pTheme;
  v9 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v9 != nullptr )
    v10 = vgui::TextEntry::TextEntry(this: v9, parent: this, panelName: "ThemeNameEdit");
  else
    v10 = nullptr;
  this->m_pThemeNameEdit = v10;
  v11 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v11 != nullptr )
    v12 = vgui::TextEntry::TextEntry(this: v11, parent: this, panelName: "ThemeDescriptionEdit");
  else
    v12 = nullptr;
  this->m_pThemeDescriptionEdit = v12;
  v13 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v13 != nullptr )
    v14 = vgui::TextEntry::TextEntry(this: v13, parent: this, panelName: "ThemeAmbientEdit");
  else
    v14 = nullptr;
  this->m_pThemeAmbientEdit = v14;
  v15 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v15 != nullptr )
    v16 = vgui::CheckButton::CheckButton(this: v15, parent: this, panelName: "VMFTweakCheck", text: "VMF Tweak");
  else
    v16 = nullptr;
  this->m_pVMFTweakCheck = v16;
  if ( !bCreatingNew )
  {
    this->m_pThemeNameEdit->SetText(this: this->m_pThemeNameEdit, a2: (const char *)pTheme);
    this->m_pThemeDescriptionEdit->SetText(this: this->m_pThemeDescriptionEdit, a2: pTheme->m_szDescription);
    V_snprintf(
      pDest: buffer,
      maxLen: 128,
      pFormat: "%d %d %d",
      (int)pTheme->m_vecAmbientLight.x,
      (int)pTheme->m_vecAmbientLight.y,
      (int)pTheme->m_vecAmbientLight.z);
    this->m_pThemeAmbientEdit->SetText(this: this->m_pThemeAmbientEdit, a2: buffer);
    this->m_pVMFTweakCheck->SetSelected(this: this->m_pVMFTweakCheck, a2: pTheme->m_bRequiresVMFTweak);
  }
  vgui::Panel::SetSize(this, wide: 384, tall: 420);
  vgui::Panel::SetMinimumSize(this, wide: 200, tall: 50);
  vgui::Frame::SetMinimizeButtonVisible(this, state: false);
  vgui::Frame::SetCloseButtonVisible(this, state: false);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "ThemeEditDialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::MoveToCenterOfScreen(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10030980
// Name: public: virtual void CThemeEditDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CThemeEditDialog::OnCommand(CThemeEditDialog *this, const char *command)
{
  vgui::MessageBox *v3; // eax
  vgui::MessageBox *v4; // eax
  CLevelTheme *v5; // ecx
  int m_Size; // eax
  int v7; // edi
  CLevelTheme **m_pMemory; // ecx
  int v9; // eax
  CLevelTheme **v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  CLevelTheme *m_pLevelTheme; // edi
  char buffer[128]; // [esp+Ch] [ebp-C0h] BYREF
  char name[64]; // [esp+8Ch] [ebp-40h] BYREF

  if ( _V_stricmp(s1: command, s2: "Okay") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "Close") == 0 && this->m_bCreatingNew )
    {
      m_pLevelTheme = this->m_pLevelTheme;
      if ( m_pLevelTheme != nullptr )
      {
        CLevelTheme::~CLevelTheme(this: this->m_pLevelTheme);
        free(pMem: m_pLevelTheme);
      }
      this->m_pLevelTheme = nullptr;
      CLevelTheme::SetCurrentTheme(pTheme: CLevelTheme::s_pPreviousTheme);
    }
    vgui::Frame::OnCommand(this, command);
  }
  else
  {
    this->m_pThemeNameEdit->GetText_2(this: this->m_pThemeNameEdit, a2: name, a3: 64);
    if ( _V_strlen(str: name) > 0 )
    {
      this->m_pThemeNameEdit->GetText_2(this: this->m_pThemeNameEdit, a2: (char *)this->m_pLevelTheme, a3: 64);
      this->m_pThemeDescriptionEdit->GetText_2(
        this: this->m_pThemeDescriptionEdit,
        a2: this->m_pLevelTheme->m_szDescription,
        a3: 512);
      this->m_pThemeAmbientEdit->GetText_2(this: this->m_pThemeAmbientEdit, a2: buffer, a3: 128);
      sscanf(
        string: buffer,
        format: "%f %f %f",
        &this->m_pLevelTheme->m_vecAmbientLight,
        &this->m_pLevelTheme->m_vecAmbientLight.y,
        &this->m_pLevelTheme->m_vecAmbientLight.z);
      v5 = this->m_pLevelTheme;
      if ( vec3_origin.x == v5->m_vecAmbientLight.x
        && vec3_origin.y == v5->m_vecAmbientLight.y
        && vec3_origin.z == v5->m_vecAmbientLight.z )
      {
        v5->m_vecAmbientLight.x = 1.0;
        this->m_pLevelTheme->m_vecAmbientLight.y = 1.0;
        this->m_pLevelTheme->m_vecAmbientLight.z = 1.0;
      }
      this->m_pLevelTheme->m_bRequiresVMFTweak = this->m_pVMFTweakCheck->IsSelected(this: this->m_pVMFTweakCheck);
      if ( this->m_bCreatingNew )
      {
        m_Size = CLevelTheme::s_LevelThemes.m_Size;
        v7 = CLevelTheme::s_LevelThemes.m_Size;
        if ( CLevelTheme::s_LevelThemes.m_Size + 1 > CLevelTheme::s_LevelThemes.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&CLevelTheme::s_LevelThemes,
            num: CLevelTheme::s_LevelThemes.m_Size - CLevelTheme::s_LevelThemes.m_Memory.m_nAllocationCount + 1);
          m_Size = CLevelTheme::s_LevelThemes.m_Size;
        }
        m_pMemory = CLevelTheme::s_LevelThemes.m_Memory.m_pMemory;
        CLevelTheme::s_LevelThemes.m_Size = m_Size + 1;
        v9 = m_Size - v7;
        CLevelTheme::s_LevelThemes.m_pElements = CLevelTheme::s_LevelThemes.m_Memory.m_pMemory;
        if ( v9 > 0 )
        {
          _V_memmove(
            dest: &CLevelTheme::s_LevelThemes.m_Memory.m_pMemory[v7 + 1],
            src: &CLevelTheme::s_LevelThemes.m_Memory.m_pMemory[v7],
            count: 4 * v9);
          m_pMemory = CLevelTheme::s_LevelThemes.m_Memory.m_pMemory;
        }
        v10 = &m_pMemory[v7];
        if ( v10 != nullptr )
          *v10 = this->m_pLevelTheme;
      }
      if ( CLevelTheme::SaveTheme(this: this->m_pLevelTheme, pszThemeName: this->m_pLevelTheme->m_szName) != 0 )
      {
        v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v11 != nullptr )
          v12 = KeyValues::KeyValues(
                  this: v11,
                  setName: "ThemeChanged",
                  firstKey: "themename",
                  firstValue: this->m_pLevelTheme->m_szName);
        else
          v12 = nullptr;
        this->PostActionSignal(this, a2: v12);
        this->OnClose(this);
        vgui::Frame::OnCommand(this, command);
      }
      else
      {
        VGUIMessageBox(
          pParent: this,
          pTitle: "Save Error",
          pMsg: "Failed to save %s.theme.  Make sure file is checked out from Perforce.",
          this->m_pLevelTheme->m_szName);
      }
    }
    else
    {
      v3 = (vgui::MessageBox *)operator new(nSize: 0x234u);
      if ( v3 != nullptr )
      {
        v4 = vgui::MessageBox::MessageBox(
               this: v3,
               title: "Bad Theme Name",
               text: "Please enter a valid theme name",
               parent: this);
        v4->DoModal_2(this: v4, a2: nullptr);
      }
      else
      {
        (*(void (__thiscall **)(_DWORD, _DWORD))(MEMORY[0] + 1116))(a1: 0, a2: 0);
      }
    }
  }
}
