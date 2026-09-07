// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/matsys_controls/particlepicker.cpp
// Functions: 73
// ============================================================

#include "vgui2\matsys_controls\particlepicker.h"

//------------------------------------------------------------------------------
// Address: 0x1020EC70
// Name: public: static char const __near * CParticleSnapshotGrid::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CParticleSnapshotGrid::GetPanelClassName()
{
  return "CParticleSnapshotGrid";
}

//------------------------------------------------------------------------------
// Address: 0x1020EC80
// Name: public: static char const __near * CParticlePicker::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CParticlePicker::GetPanelClassName()
{
  return "CParticlePicker";
}

//------------------------------------------------------------------------------
// Address: 0x1020EC90
// Name: public: static char const __near * CParticleSnapshotPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CParticleSnapshotPanel::GetPanelClassName()
{
  return "CParticleSnapshotPanel";
}

//------------------------------------------------------------------------------
// Address: 0x1020ECA0
// Name: public: virtual void CParticleSnapshotPanel::OnParticleSystemSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSnapshotPanel::OnParticleSystemSelected(CParticleSnapshotPanel *this, const char *SystemName)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(
           this: v3,
           setName: "ParticleSystemSelected",
           firstKey: "SystemName",
           firstValue: SystemName);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020ECF0
// Name: public: virtual void CParticleSnapshotPanel::OnSetFocus(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CParticleSnapshotPanel::OnSetFocus(CParticleSnapshotPanel *this)
{
  vgui::EditablePanel::OnSetFocus(this);
}

//------------------------------------------------------------------------------
// Address: 0x1020ED00
// Name: public: virtual void CParticleSnapshotPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSnapshotPanel::OnMousePressed(CParticleSnapshotPanel *this, ButtonCode_t code)
{
  KeyValues *v3; // edi
  const char *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // edi
  const char *v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // edi
  const char *v10; // eax
  KeyValues *v11; // eax

  CToolEntitySprinkle::RenderTool2D((vgui::TreeView *)this, itemIndex: code);
  if ( code == KEY_COUNT )
  {
    if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LSHIFT)
      || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RSHIFT) )
    {
      v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v9 != nullptr )
      {
        v10 = CUtlString::operator char const *(this: &this->m_SystemName);
        v11 = KeyValues::KeyValues(
                this: v9,
                setName: "ParticleSystemShiftSelected",
                firstKey: "SystemName",
                firstValue: v10);
        this->PostActionSignal(this, a2: v11);
        return;
      }
    }
    else if ( g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_LCONTROL)
           || g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: KEY_RCONTROL) )
    {
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
      {
        v7 = CUtlString::operator char const *(this: &this->m_SystemName);
        v8 = KeyValues::KeyValues(
               this: v6,
               setName: "ParticleSystemCtrlSelected",
               firstKey: "SystemName",
               firstValue: v7);
        this->PostActionSignal(this, a2: v8);
        return;
      }
    }
    else
    {
      v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v3 != nullptr )
      {
        v4 = CUtlString::operator char const *(this: &this->m_SystemName);
        v5 = KeyValues::KeyValues(this: v3, setName: "ParticleSystemSelected", firstKey: "SystemName", firstValue: v4);
        this->PostActionSignal(this, a2: v5);
        return;
      }
    }
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020EE50
// Name: public: virtual void CParticleSnapshotPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSnapshotPanel::OnMouseDoublePressed(CParticleSnapshotPanel *this, ButtonCode_t code)
{
  KeyValues *v3; // edi
  const char *v4; // eax
  KeyValues *v5; // eax

  CToolEntitySprinkle::RenderTool2D((vgui::TreeView *)this, itemIndex: code);
  if ( code == KEY_COUNT )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
    {
      v4 = CUtlString::operator char const *(this: &this->m_SystemName);
      v5 = KeyValues::KeyValues(this: v3, setName: "ParticleSystemPicked", firstKey: "SystemName", firstValue: v4);
      this->PostActionSignal(this, a2: v5);
    }
    else
    {
      this->PostActionSignal(this, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020EED0
// Name: PanelSortHelperI
// Source: json
//------------------------------------------------------------------------------
int __cdecl PanelSortHelperI(CParticleSnapshotPanel *const *a, CParticleSnapshotPanel *const *b)
{
  const char *v2; // esi
  const char *v3; // eax

  v2 = CUtlString::operator char const *(this: &(*b)->m_SystemName);
  v3 = CUtlString::operator char const *(this: &(*a)->m_SystemName);
  return _V_stricmp(s1: v3, s2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1020EF10
// Name: public: virtual void CParticleSnapshotGrid::OnMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSnapshotGrid::OnMouseWheeled(CParticleSnapshotGrid *this, int delta)
{
  int v3; // eax

  v3 = this->m_pScrollBar->GetValue(this: this->m_pScrollBar);
  this->m_pScrollBar->SetValue(this: this->m_pScrollBar, a2: v3 - 30 * delta);
  this->RequestFocus(this, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1020EF60
// Name: private: bool CParticleSnapshotGrid::IsSystemVisible(int)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CParticleSnapshotGrid::IsSystemVisible(CParticleSnapshotGrid *this, int nIndex)
{
  int v3; // ebx
  int v4; // edi
  int v5; // eax
  int v6; // ebx
  int v7; // edi
  int v8; // eax
  int v9; // edi
  int v10; // eax
  int nViewTall; // [esp+Ch] [ebp-4h]

  nViewTall = vgui::Panel::GetTall(this: this->m_pScrollPanel);
  v3 = nIndex / this->m_nCurrentColCount;
  if ( this->m_pPreviewCheckbox->IsSelected(this: this->m_pPreviewCheckbox) )
  {
    v4 = -8 - vgui::Panel::GetWide(this: this->m_pScrollBar);
    v5 = (v4 + vgui::Panel::GetWide(this)) / this->m_nCurrentColCount;
    if ( v5 > 250 )
      v5 = 250;
  }
  else
  {
    v5 = 30;
  }
  v6 = v5 * v3;
  if ( this->m_pPreviewCheckbox->IsSelected(this: this->m_pPreviewCheckbox) )
  {
    v7 = -8 - vgui::Panel::GetWide(this: this->m_pScrollBar);
    v8 = (v7 + vgui::Panel::GetWide(this)) / this->m_nCurrentColCount;
    if ( v8 <= 250 )
      v9 = v8;
    else
      v9 = 250;
  }
  else
  {
    v9 = 30;
  }
  v10 = this->m_pScrollBar->GetValue(this: this->m_pScrollBar);
  return v6 < v10 + nViewTall && v6 + v9 > v10;
}

//------------------------------------------------------------------------------
// Address: 0x1020F060
// Name: public: virtual void CParticleSnapshotGrid::OnParticleSystemPicked(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSnapshotGrid::OnParticleSystemPicked(CParticleSnapshotGrid *this, const char *SystemName)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ParticleSystemPicked", firstKey: "SystemName", firstValue: SystemName);
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020F0B0
// Name: StringSortHelperI
// Source: json
//------------------------------------------------------------------------------
int __cdecl StringSortHelperI(const char **a, const char **b)
{
  return _V_stricmp(s1: *a, s2: *b);
}

//------------------------------------------------------------------------------
// Address: 0x1020F0D0
// Name: public: virtual void CParticlePicker::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticlePicker::PerformLayout(CParticlePicker *this)
{
  int w; // [esp+4h] [ebp-8h] BYREF
  int h; // [esp+8h] [ebp-4h] BYREF

  vgui::EditablePanel::PerformLayout(this);
  vgui::Panel::GetSize(this, wide: &w, tall: &h);
  vgui::Panel::SetBounds(this: this->m_pFileBrowserSplitter, x: 0, y: 0, wide: w, tall: h);
}

//------------------------------------------------------------------------------
// Address: 0x1020F110
// Name: public: void CParticlePicker::SelectParticleSys(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticlePicker::SelectParticleSys(CParticlePicker *this, const char *pRelativePath)
{
  KeyValues *v3; // eax
  const char *v4; // ecx
  KeyValues *v5; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = pRelativePath;
    if ( pRelativePath == nullptr )
      v4 = &var;
    v5 = KeyValues::KeyValues(this: v3, setName: "SelectedParticleSysChanged", firstKey: "particle", firstValue: v4);
    this->PostActionSignal(this, a2: v5);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020F170
// Name: public: void CParticlePicker::GetSelectedParticleSysName(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticlePicker::GetSelectedParticleSysName(CParticlePicker *this, char *pBuffer, int nMaxLen)
{
  const char *SelectedAsset; // eax

  if ( CBaseAssetPicker::GetSelectedAssetCount(this) <= 0 )
  {
    *pBuffer = 0;
  }
  else
  {
    SelectedAsset = CBaseAssetPicker::GetSelectedAsset(this, nSelectionIndex: -1);
    V_snprintf(pDest: pBuffer, maxLen: nMaxLen, pFormat: "%s", SelectedAsset);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020F1B0
// Name: private: virtual void CParticlePicker::OnParticleSystemPicked(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticlePicker::OnParticleSystemPicked(CParticlePicker *this, const char *SystemName)
{
  this->OnKeyCodeTyped(this, a2: KEY_ENTER);
}

//------------------------------------------------------------------------------
// Address: 0x1020F1F0
// Name: public: virtual struct vgui::PanelMessageMap __near * CParticlePicker::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CParticlePicker::GetMessageMap(CParticlePicker *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CParticlePicker::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CParticlePicker::GetMessageMap'::`2'::s_pMap;
  `CParticlePicker::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CParticlePicker");
  `CParticlePicker::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020F220
// Name: public: virtual struct PanelAnimationMap __near * CParticlePicker::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CParticlePicker::GetAnimMap(CParticlePicker *this)
{
  return FindOrAddPanelAnimationMap(className: "CParticlePicker");
}

//------------------------------------------------------------------------------
// Address: 0x1020F230
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CParticlePicker::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CParticlePicker::GetKBMap(CParticlePicker *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CParticlePicker::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CParticlePicker::GetKBMap'::`2'::s_pMap;
  `CParticlePicker::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CParticlePicker");
  `CParticlePicker::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020F260
// Name: public: virtual void CParticleSnapshotPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSnapshotPanel::ApplySchemeSettings(CParticleSnapshotPanel *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  Color *(__thiscall *GetColor)(vgui::IScheme *, Color *, const char *, Color); // eax
  Color v5; // ecx
  Color *(__thiscall *v6)(vgui::IScheme *, Color *, const char *, Color); // edx
  Color *(__thiscall *v7)(vgui::IScheme *, Color *, const char *, Color); // eax
  int v8; // [esp+Ch] [ebp-8h] BYREF
  Color btnFgColor; // [esp+10h] [ebp-4h] BYREF

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, (int)pScheme);
  GetColor = v2->GetColor;
  v8 = 0xFFFFFF;
  v5 = *(Color *)((int (__thiscall *)(vgui::IScheme *, int *, const char *, int))GetColor)(
                   a1: v2,
                   a2: &v8,
                   a3: "ListPanel.SelectedBgColor",
                   a4: 0xFFFFFF);
  v8 = 0xFFFFFF;
  this->m_SelectedBgColor = v5;
  this->m_SelectedTextColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, int *, const char *, int))v2->GetColor)(
                                          a1: v2,
                                          a2: &v8,
                                          a3: "ListPanel.SelectedTextColor",
                                          a4: 0xFFFFFF);
  v6 = v2->GetColor;
  v8 = -1;
  ((void (__thiscall *)(vgui::IScheme *, Color *, const char *, int))v6)(
    a1: v2,
    a2: &btnFgColor,
    a3: "Button.TextColor",
    a4: -1);
  v7 = v2->GetColor;
  v8 = -8355712;
  ((void (__thiscall *)(vgui::IScheme *, vgui::IScheme **, const char *, int))v7)(
    a1: v2,
    a2: &pScheme,
    a3: "ListPanel.BgColor",
    a4: -8355712);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))this->m_pChildrenButton->SetDefaultColor)(
    a1: this->m_pChildrenButton,
    a2: btnFgColor,
    a3: pScheme);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))this->m_pChildrenButton->SetArmedColor)(
    a1: this->m_pChildrenButton,
    a2: btnFgColor,
    a3: pScheme);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))this->m_pChildrenButton->SetDepressedColor)(
    a1: this->m_pChildrenButton,
    a2: btnFgColor,
    a3: pScheme);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))this->m_pParentsButton->SetDefaultColor)(
    a1: this->m_pParentsButton,
    a2: btnFgColor,
    a3: pScheme);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))this->m_pParentsButton->SetArmedColor)(
    a1: this->m_pParentsButton,
    a2: btnFgColor,
    a3: pScheme);
  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))this->m_pParentsButton->SetDepressedColor)(
    a1: this->m_pParentsButton,
    a2: btnFgColor,
    a3: pScheme);
}

//------------------------------------------------------------------------------
// Address: 0x1020F3A0
// Name: public: virtual void CParticleSnapshotPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSnapshotPanel::Paint(CParticleSnapshotPanel *this)
{
  CParticleSnapshotPanel_vtbl *v2; // edi
  int v3; // eax
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // edx
  int v5; // [esp-8h] [ebp-2Ch]
  Color m_SelectedBgColor; // [esp-4h] [ebp-28h]
  int wide; // [esp+10h] [ebp-14h] BYREF
  int v8; // [esp+14h] [ebp-10h] BYREF
  int w; // [esp+18h] [ebp-Ch] BYREF
  int x; // [esp+1Ch] [ebp-8h] BYREF
  int t; // [esp+20h] [ebp-4h]

  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  if ( this->m_bSelected )
  {
    v2 = this->__vftable;
    m_SelectedBgColor = this->m_SelectedBgColor;
    v5 = vgui::Panel::GetTall(this) - 2;
    v3 = vgui::Panel::GetWide(this);
    ((void (__thiscall *)(CParticleSnapshotPanel *, int, int, int, int, Color, int, _DWORD))v2->DrawBox)(
      a1: this,
      a2: 1,
      a3: 1,
      a4: v3 - 2,
      a5: v5,
      a6: m_SelectedBgColor,
      a7: 1065353216,
      a8: 0);
  }
  if ( this->m_bPreviewEnabled )
  {
    vgui::Panel::GetBounds(this: this->m_pParticlePanel, x: &v8, y: &x, &wide, tall: &w);
    DrawSetColor = g_pVGuiSurface->DrawSetColor;
    t = -16777216;
    ((void (__thiscall *)(vgui::ISurface *, int))DrawSetColor)(a1: g_pVGuiSurface, a2: -16777216);
    g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: v8 - 1, a3: x - 1, a4: v8 + wide + 1, a5: x + w + 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020F490
// Name: public: virtual int CParticlePicker::GetAssetCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CParticlePicker::GetAssetCount(CParticlePicker *this)
{
  return sCacheParticleList.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1020F4A0
// Name: public: void CParticleSnapshotPanel::UpdateRelatives(class vgui::IImage __near *,class CUtlVector<struct CParticleSnapshotGrid::PSysRelativeInfo_t,class CUtlMemory<struct CParticleSnapshotGrid::PSysRelativeInfo_t,int>> __near &,class CUtlVector<struct CParticleSnapshotGrid::PSysRelativeInfo_t,class CUtlMemory<struct CParticleSnapshotGrid::PSysRelativeInfo_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSnapshotPanel::UpdateRelatives(
        CParticleSnapshotPanel *this,
        vgui::IImage *pIcon,
        vgui::Menu *sysParents,
        CUtlVector<CParticleSnapshotGrid::PSysRelativeInfo_t,CUtlMemory<CParticleSnapshotGrid::PSysRelativeInfo_t,int> > *sysChildren)
{
  vgui::Menu *v6; // edi
  vgui::Panel *v7; // eax
  vgui::Panel *v8; // eax
  int v9; // edi
  const char *v10; // eax
  KeyValues *v11; // eax
  CUtlString *v12; // ecx
  vgui::Menu_vtbl *v13; // edi
  const char *v14; // eax
  int v15; // eax
  vgui::MenuItem *MenuItem; // eax
  vgui::Menu *v18; // edi
  vgui::Panel *v19; // eax
  vgui::Panel *v20; // eax
  int v21; // edi
  const char *v22; // eax
  KeyValues *v23; // eax
  CUtlString *v24; // ecx
  vgui::Menu_vtbl *v25; // edi
  const char *v26; // eax
  int v27; // eax
  vgui::MenuItem *v28; // eax
  KeyValues *v29; // [esp-Ch] [ebp-2Ch]
  KeyValues *v30; // [esp-Ch] [ebp-2Ch]
  int v31; // [esp+0h] [ebp-20h]
  char countBuf[8]; // [esp+Ch] [ebp-14h] BYREF
  KeyValues *v33; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  int j; // [esp+1Ch] [ebp-4h]
  vgui::Menu *pChildrenMenu; // [esp+2Ch] [ebp+Ch]
  vgui::Menu *pChildrenMenua; // [esp+2Ch] [ebp+Ch]
  CUtlVector<CParticleSnapshotGrid::PSysRelativeInfo_t,CUtlMemory<CParticleSnapshotGrid::PSysRelativeInfo_t,int> > *sysChildrena; // [esp+30h] [ebp+10h]

  if ( *(_DWORD *)&sysParents->m_OnDelete_register != 0 )
  {
    v6 = (vgui::Menu *)operator new(nSize: 0x420u);
    if ( v6 != nullptr )
    {
      v7 = this->GetParent(this);
      v8 = v7->GetParent(this: v7);
      pChildrenMenu = vgui::Menu::Menu(this: v6, parent: v8, panelName: "ParentsMenu");
    }
    else
    {
      pChildrenMenu = nullptr;
    }
    v9 = 0;
    i = 0;
    if ( *(int *)&sysParents->m_OnDelete_register > 0 )
    {
      for ( j = 0; ; v9 = j )
      {
        v33 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v33 != nullptr )
        {
          v10 = CUtlString::operator char const *(this: (CUtlString *)((char *)sysParents->__vftable + v9));
          v11 = KeyValues::KeyValues(
                  this: v33,
                  setName: "ParticleSystemSelected",
                  firstKey: "SystemName",
                  firstValue: v10);
        }
        else
        {
          v11 = nullptr;
        }
        v12 = (CUtlString *)((char *)sysParents->__vftable + v9);
        v13 = pChildrenMenu->__vftable;
        v29 = v11;
        v14 = CUtlString::operator char const *(this: v12);
        v15 = v13->AddMenuItem(this: pChildrenMenu, a2: v14, a3: v29, a4: this, a5: nullptr);
        MenuItem = vgui::Menu::GetMenuItem(this: pChildrenMenu, itemID: v15);
        MenuItem->SetEnabled(this: MenuItem, a2: *((_BYTE *)&sysParents->Repaint + j));
        ++i;
        j += 20;
        if ( i >= *(_DWORD *)&sysParents->m_OnDelete_register )
          break;
      }
    }
    this->m_pParentsButton->SetEnabled(this: this->m_pParentsButton, a2: true);
    V_snprintf(pDest: countBuf, maxLen: 8, pFormat: "%d", *(_DWORD *)&sysParents->m_OnDelete_register);
    this->m_pParentsButton->SetText(this: this->m_pParentsButton, a2: countBuf);
    ((void (__cdecl *)(vgui::Menu *))this->m_pParentsButton->SetMenu)(a1: pChildrenMenu);
  }
  else
  {
    this->m_pParentsButton->SetEnabled(this: this->m_pParentsButton, a2: false);
    this->m_pParentsButton->SetText(this: this->m_pParentsButton, a2: "P");
    ((void (__cdecl *)(_DWORD))this->m_pParentsButton->SetMenu)(a1: 0);
  }
  if ( sysChildren->m_Size != 0 )
  {
    v18 = (vgui::Menu *)operator new(nSize: 0x420u);
    if ( v18 != nullptr )
    {
      v19 = this->GetParent(this);
      v20 = v19->GetParent(this: v19);
      pChildrenMenua = vgui::Menu::Menu(this: v18, parent: v20, panelName: "ChildrenMenu");
    }
    else
    {
      pChildrenMenua = nullptr;
    }
    v21 = 0;
    i = 0;
    if ( sysChildren->m_Size > 0 )
    {
      for ( sysChildrena = nullptr; ; v21 = (int)sysChildrena )
      {
        v33 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v33 != nullptr )
        {
          v22 = CUtlString::operator char const *(this: (CUtlString *)((char *)&sysChildren->m_Memory.m_pMemory->relName
                                                                     + v21));
          v23 = KeyValues::KeyValues(
                  this: v33,
                  setName: "ParticleSystemSelected",
                  firstKey: "SystemName",
                  firstValue: v22);
        }
        else
        {
          v23 = nullptr;
        }
        v24 = (CUtlString *)((char *)&sysChildren->m_Memory.m_pMemory->relName + v21);
        v25 = pChildrenMenua->__vftable;
        v30 = v23;
        v26 = CUtlString::operator char const *(this: v24);
        v27 = v25->AddMenuItem(this: pChildrenMenua, a2: v26, a3: v30, a4: this, a5: nullptr);
        v28 = vgui::Menu::GetMenuItem(this: pChildrenMenua, itemID: v27);
        v28->SetEnabled(
          this: v28,
          a2: *((_BYTE *)&sysChildrena->m_pElements + (unsigned int)sysChildren->m_Memory.m_pMemory));
        ++i;
        ++sysChildrena;
        if ( i >= sysChildren->m_Size )
          break;
      }
    }
    ((void (__thiscall *)(vgui::MenuButton *, int, int))this->m_pChildrenButton->SetEnabled)(
      a1: this->m_pChildrenButton,
      a2: 1,
      a3: v31);
    V_snprintf(pDest: countBuf, maxLen: 8, pFormat: "%d", sysChildren->m_Size);
    this->m_pChildrenButton->SetText(this: this->m_pChildrenButton, a2: countBuf);
    this->m_pChildrenButton->SetMenu(this: this->m_pChildrenButton, a2: pChildrenMenua);
  }
  else
  {
    ((void (__thiscall *)(vgui::MenuButton *, _DWORD, int))this->m_pChildrenButton->SetEnabled)(
      a1: this->m_pChildrenButton,
      a2: 0,
      a3: v31);
    this->m_pChildrenButton->SetText(this: this->m_pChildrenButton, a2: "C");
    this->m_pChildrenButton->SetMenu(this: this->m_pChildrenButton, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020F7A0
// Name: private: void CParticleSnapshotGrid::UpdatePanelRelatives(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSnapshotGrid::UpdatePanelRelatives(CParticleSnapshotGrid *this, int nIndex)
{
  CParticleSnapshotPanel *v3; // ecx
  vgui::IImage *m_pRelativesImgNeither; // ebx
  CUtlVector<CParticleSnapshotGrid::PSysRelativeInfo_t,CUtlMemory<CParticleSnapshotGrid::PSysRelativeInfo_t,int> > *v5; // esi
  CUtlVector<CParticleSnapshotGrid::PSysRelativeInfo_t,CUtlMemory<CParticleSnapshotGrid::PSysRelativeInfo_t,int> > *v6; // edi

  v3 = this->m_Panels.m_Memory.m_pMemory[nIndex];
  m_pRelativesImgNeither = this->m_pRelativesImgNeither;
  v5 = &this->m_ParentsMap.m_Memory.m_pMemory[nIndex];
  v6 = &this->m_ChildrenMap.m_Memory.m_pMemory[nIndex];
  if ( v5->m_Size != 0 )
  {
    if ( v6->m_Size != 0 )
      CParticleSnapshotPanel::UpdateRelatives(
        this: v3,
        pIcon: this->m_pRelativesImgBoth,
        sysParents: (vgui::Menu *)v5,
        sysChildren: &this->m_ChildrenMap.m_Memory.m_pMemory[nIndex]);
    else
      CParticleSnapshotPanel::UpdateRelatives(
        this: v3,
        pIcon: this->m_pRelativesImgPOnly,
        sysParents: (vgui::Menu *)v5,
        sysChildren: &this->m_ChildrenMap.m_Memory.m_pMemory[nIndex]);
  }
  else
  {
    if ( v6->m_Size != 0 )
      m_pRelativesImgNeither = this->m_pRelativesImgCOnly;
    CParticleSnapshotPanel::UpdateRelatives(
      this: v3,
      pIcon: m_pRelativesImgNeither,
      sysParents: (vgui::Menu *)v5,
      sysChildren: &this->m_ChildrenMap.m_Memory.m_pMemory[nIndex]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020F830
// Name: public: void CParticleSnapshotGrid::LayoutScrolled(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSnapshotGrid::LayoutScrolled(CParticleSnapshotGrid *this)
{
  int m_Size; // eax
  int m_nCurrentColCount; // ecx
  int v4; // eax
  vgui::ScrollBar *m_pScrollBar; // ecx
  int v6; // ebx
  int (__thiscall *GetValue)(vgui::ScrollBar *); // edx
  int v8; // eax
  vgui::ScrollBar *v9; // ecx
  int v10; // edi
  int v11; // eax
  int v12; // edi
  int v13; // eax
  vgui::ScrollBar_vtbl *v14; // edi
  int Tall; // eax
  int v16; // eax
  int v17; // edi
  int v18; // ebx
  int v19; // edi
  CParticleSnapshotPanel *v20; // ecx
  vgui::Label *m_pNoSystemsLabel; // ecx
  int v22; // eax
  int Wide; // eax
  int v24; // [esp-4h] [ebp-2Ch]
  int v25; // [esp-4h] [ebp-2Ch]
  int t; // [esp+Ch] [ebp-1Ch] BYREF
  int nPanels; // [esp+10h] [ebp-18h]
  int w; // [esp+14h] [ebp-14h] BYREF
  int r; // [esp+18h] [ebp-10h]
  int x; // [esp+1Ch] [ebp-Ch]
  int nPanelW; // [esp+20h] [ebp-8h]
  int nPanelT; // [esp+24h] [ebp-4h]

  m_Size = this->m_Panels.m_Size;
  m_nCurrentColCount = this->m_nCurrentColCount;
  nPanels = m_Size;
  v4 = (m_nCurrentColCount + m_Size - 1) / m_nCurrentColCount;
  m_pScrollBar = this->m_pScrollBar;
  v6 = v4;
  GetValue = m_pScrollBar->GetValue;
  t = v4;
  v8 = GetValue(this: m_pScrollBar);
  v9 = this->m_pScrollBar;
  w = v8;
  v10 = -8 - vgui::Panel::GetWide(this: v9);
  v11 = (v10 + vgui::Panel::GetWide(this)) / this->m_nCurrentColCount;
  nPanelW = 250;
  if ( v11 <= 250 )
    nPanelW = v11;
  if ( this->m_pPreviewCheckbox->IsSelected(this: this->m_pPreviewCheckbox) )
  {
    v12 = -8 - vgui::Panel::GetWide(this: this->m_pScrollBar);
    v13 = (v12 + vgui::Panel::GetWide(this)) / this->m_nCurrentColCount;
    if ( v13 <= 250 )
      nPanelT = v13;
    else
      nPanelT = 250;
  }
  else
  {
    nPanelT = 30;
  }
  this->m_pScrollBar->SetRange(this: this->m_pScrollBar, a2: 0, a3: v6 * nPanelT + 8);
  v14 = this->m_pScrollBar->__vftable;
  Tall = vgui::Panel::GetTall(this: this->m_pScrollPanel);
  v14->SetRangeWindow(this: this->m_pScrollBar, a2: Tall);
  r = 0;
  if ( v6 > 0 )
  {
    v16 = 4 - w;
    w = 4 - w;
    do
    {
      v17 = this->m_nCurrentColCount;
      v18 = 0;
      if ( v17 > 0 )
      {
        x = 4;
        do
        {
          v19 = v18 + r * v17;
          if ( v19 < nPanels )
          {
            if ( CParticleSnapshotGrid::IsSystemVisible(this, nIndex: v19) )
            {
              vgui::Panel::SetSize(this: this->m_Panels.m_Memory.m_pMemory[v19], wide: nPanelW, tall: nPanelT);
              vgui::Panel::SetPos(this: this->m_Panels.m_Memory.m_pMemory[v19], x, y: w);
              v24 = 1;
            }
            else
            {
              vgui::Panel::SetSize(this: this->m_Panels.m_Memory.m_pMemory[v19], wide: 1, tall: 1);
              vgui::Panel::SetPos(this: this->m_Panels.m_Memory.m_pMemory[v19], x: -10, y: -10);
              v24 = 0;
            }
            v20 = this->m_Panels.m_Memory.m_pMemory[v19];
            v20->SetVisible(this: v20, a2: v24);
          }
          v17 = this->m_nCurrentColCount;
          x += nPanelW;
          ++v18;
        }
        while ( v18 < v17 );
        v16 = w;
      }
      v16 += nPanelT;
      ++r;
      w = v16;
    }
    while ( r < t );
  }
  if ( nPanels != 0 )
  {
    this->m_pNoSystemsLabel->SetVisible(this: this->m_pNoSystemsLabel, a2: false);
  }
  else
  {
    this->m_pNoSystemsLabel->SetVisible(this: this->m_pNoSystemsLabel, a2: true);
    this->m_pNoSystemsLabel->GetContentSize(this: this->m_pNoSystemsLabel, a2: &w, a3: &t);
    m_pNoSystemsLabel = this->m_pNoSystemsLabel;
    w *= 2;
    vgui::Panel::SetWide(this: m_pNoSystemsLabel, wide: w);
    v22 = vgui::Panel::GetTall(this: this->m_pScrollPanel);
    v25 = (v22 - t) / 2;
    Wide = vgui::Panel::GetWide(this: this->m_pScrollPanel);
    vgui::Panel::SetPos(this: this->m_pNoSystemsLabel, x: (Wide - w) / 2, y: v25);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020FAB0
// Name: public: int CParticleSnapshotGrid::GetSelectedSystemId(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CParticleSnapshotGrid::GetSelectedSystemId(CParticleSnapshotGrid *this, int nSelectionIndex)
{
  int m_Size; // edx
  int v3; // eax
  CParticleSnapshotPanel **m_pMemory; // esi
  CParticleSnapshotPanel **i; // ecx

  m_Size = this->m_Panels.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return -1;
  m_pMemory = this->m_Panels.m_Memory.m_pMemory;
  for ( i = m_pMemory; !(*i)->m_bSelected || --nSelectionIndex >= 0; ++i )
  {
    if ( ++v3 >= m_Size )
      return -1;
  }
  return m_pMemory[v3]->m_nSystemId;
}

//------------------------------------------------------------------------------
// Address: 0x1020FB00
// Name: public: void CParticleSnapshotGrid::SelectSystem(char const __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSnapshotGrid::SelectSystem(
        CParticleSnapshotGrid *this,
        const char *pSystemName,
        bool bAddToSelection,
        bool bToggle)
{
  int v5; // edi
  int v6; // ebx
  const char *v7; // eax
  CParticleSnapshotPanel *v8; // eax
  CParticleSnapshotPanel *v9; // ecx
  int v10; // ebx
  int v11; // edi
  int v12; // eax
  int v13; // ebx
  int v14; // edi
  int v15; // eax
  int v16; // edi
  int v17; // eax
  int nViewTall; // [esp+18h] [ebp+Ch]

  v5 = 0;
  v6 = -1;
  if ( this->m_Panels.m_Size <= 0 )
    goto LABEL_25;
  do
  {
    v7 = CUtlString::operator char const *(this: &this->m_Panels.m_Memory.m_pMemory[v5]->m_SystemName);
    if ( _V_strcmp(s1: v7, s2: pSystemName) != 0 )
    {
      if ( !bAddToSelection )
        this->m_Panels.m_Memory.m_pMemory[v5]->m_bSelected = false;
    }
    else
    {
      v8 = this->m_Panels.m_Memory.m_pMemory[v5];
      if ( v8->m_bSelected )
      {
        if ( bAddToSelection && bToggle )
        {
          v8->m_bSelected = false;
          this->m_nMostRecentSelectedIndex = v5;
          goto LABEL_11;
        }
      }
      else
      {
        v8->m_bSelected = true;
        v9 = this->m_Panels.m_Memory.m_pMemory[v5];
        v6 = v5;
        v9->RequestFocus(this: v9, a2: 0);
      }
      this->m_nMostRecentSelectedIndex = v5;
    }
LABEL_11:
    ++v5;
  }
  while ( v5 < this->m_Panels.m_Size );
  if ( v6 != -1 )
  {
    nViewTall = vgui::Panel::GetTall(this: this->m_pScrollPanel);
    v10 = v6 / this->m_nCurrentColCount;
    if ( this->m_pPreviewCheckbox->IsSelected(this: this->m_pPreviewCheckbox) )
    {
      v11 = -8 - vgui::Panel::GetWide(this: this->m_pScrollBar);
      v12 = (v11 + vgui::Panel::GetWide(this)) / this->m_nCurrentColCount;
      if ( v12 > 250 )
        v12 = 250;
    }
    else
    {
      v12 = 30;
    }
    v13 = v12 * v10 + 4;
    if ( this->m_pPreviewCheckbox->IsSelected(this: this->m_pPreviewCheckbox) )
    {
      v14 = -8 - vgui::Panel::GetWide(this: this->m_pScrollBar);
      v15 = (v14 + vgui::Panel::GetWide(this)) / this->m_nCurrentColCount;
      if ( v15 > 250 )
        v15 = 250;
    }
    else
    {
      v15 = 30;
    }
    v16 = v15 + v13 + 4;
    v17 = this->m_pScrollBar->GetValue(this: this->m_pScrollBar);
    if ( v13 >= v17 )
    {
      if ( v16 > nViewTall + v17 )
        this->m_pScrollBar->SetValue(this: this->m_pScrollBar, a2: v16 - nViewTall);
    }
    else
    {
      this->m_pScrollBar->SetValue(this: this->m_pScrollBar, a2: v13);
    }
  }
LABEL_25:
  this->Repaint(this);
}

//------------------------------------------------------------------------------
// Address: 0x1020FCC0
// Name: public: virtual void CParticleSnapshotGrid::OnTick(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSnapshotGrid::OnTick(CParticleSnapshotGrid *this)
{
  int i; // edi
  CParticleSnapshotPanel *v3; // esi
  int v4; // eax
  void (__thiscall *GetClipRect)(vgui::IClientPanel *, int *, int *, int *, int *); // edx
  int v6; // [esp+8h] [ebp-24h] BYREF
  int v7; // [esp+Ch] [ebp-20h] BYREF
  int v8; // [esp+10h] [ebp-1Ch] BYREF
  int v9; // [esp+14h] [ebp-18h] BYREF
  int v10; // [esp+18h] [ebp-14h] BYREF
  int v11; // [esp+1Ch] [ebp-10h] BYREF
  int v12; // [esp+20h] [ebp-Ch] BYREF
  int v13; // [esp+24h] [ebp-8h] BYREF
  int v14; // [esp+28h] [ebp-4h]

  for ( i = 0; i < this->m_Panels.m_Size; ++i )
  {
    v3 = this->m_Panels.m_Memory.m_pMemory[i];
    if ( v3->m_bPreviewEnabled )
    {
      v4 = (int)v3->GetParent(this: v3);
      GetClipRect = v3->GetClipRect;
      v14 = v4;
      GetClipRect(this: v3, a2: &v11, a3: &v7, a4: &v13, a5: &v9);
      (*(void (__thiscall **)(int, int *, int *, int *, int *))(*(_DWORD *)v14 + 28))(
        a1: v14,
        a2: &v12,
        a3: &v8,
        a4: &v10,
        a5: &v6);
      if ( v13 >= v12 && v11 <= v10 && v9 >= v8 && v7 <= v6 )
        CParticleSystemPanel::Simulate(this: v3->m_pParticlePanel);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020FD80
// Name: public: virtual void CParticleSnapshotGrid::OnParticleSystemSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSnapshotGrid::OnParticleSystemSelected(CParticleSnapshotGrid *this, const char *SystemName)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  CParticleSnapshotGrid::SelectSystem(this, pSystemName: SystemName, bAddToSelection: false, bToggle: false);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ParticleSystemSelectionChanged");
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020FDE0
// Name: public: virtual void CParticleSnapshotGrid::OnParticleSystemCtrlSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSnapshotGrid::OnParticleSystemCtrlSelected(
        CParticleSnapshotGrid *this,
        const char *SystemName)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  CParticleSnapshotGrid::SelectSystem(this, pSystemName: SystemName, bAddToSelection: true, bToggle: true);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ParticleSystemSelectionChanged");
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1020FE40
// Name: private: int CParticleSnapshotGrid::InternalFindSystemIndexByName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CParticleSnapshotGrid::InternalFindSystemIndexByName(
        CParticleSnapshotGrid *this,
        const char *pSystemName)
{
  int v3; // esi
  const char *v4; // eax

  v3 = 0;
  if ( this->m_Panels.m_Size <= 0 )
    return -1;
  while ( 1 )
  {
    v4 = CUtlString::operator char const *(this: &this->m_Panels.m_Memory.m_pMemory[v3]->m_SystemName);
    if ( _V_strcmp(s1: v4, s2: pSystemName) == 0 )
      break;
    if ( ++v3 >= this->m_Panels.m_Size )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1020FEA0
// Name: private: virtual void CParticlePicker::OnSelectedAssetPicked(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticlePicker::OnSelectedAssetPicked(CParticlePicker *this, const char *pParticleSysName)
{
  KeyValues *v3; // eax
  const char *v4; // ecx
  KeyValues *v5; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = pParticleSysName;
    if ( pParticleSysName == nullptr )
      v4 = &var;
    v5 = KeyValues::KeyValues(this: v3, setName: "SelectedParticleSysChanged", firstKey: "particle", firstValue: v4);
  }
  else
  {
    v5 = nullptr;
  }
  this->PostActionSignal(this, a2: v5);
  CParticleSnapshotGrid::SelectSystem(
    this: this->m_pSnapshotGrid,
    pSystemName: pParticleSysName,
    bAddToSelection: false,
    bToggle: false);
}

//------------------------------------------------------------------------------
// Address: 0x1020FF00
// Name: public: virtual void CParticlePicker::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticlePicker::OnMousePressed(CParticlePicker *this, ButtonCode_t code)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "SelectedParticleSysChanged", firstKey: "particle", firstValue: &var);
  else
    v4 = nullptr;
  this->PostActionSignal(this, a2: v4);
  CParticleSnapshotGrid::SelectSystem(
    this: this->m_pSnapshotGrid,
    pSystemName: &var,
    bAddToSelection: false,
    bToggle: false);
}

//------------------------------------------------------------------------------
// Address: 0x1020FF50
// Name: public: virtual char const __near * CParticlePicker::GetAssetName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CParticlePicker::GetAssetName(CParticlePicker *this, int nAssetIndex)
{
  return CUtlString::operator char const *(this: &sCacheParticleList.m_Memory.m_pMemory[nAssetIndex].m_AssetInfo.m_AssetName);
}

//------------------------------------------------------------------------------
// Address: 0x1020FF70
// Name: public: virtual struct CachedAssetInfo_t const __near & CParticlePicker::GetCachedAsset(int)
// Source: json
//------------------------------------------------------------------------------
CachedParticleInfo_t *__thiscall CParticlePicker::GetCachedAsset(CParticlePicker *this, int nAssetIndex)
{
  return &sCacheParticleList.m_Memory.m_pMemory[nAssetIndex];
}

//------------------------------------------------------------------------------
// Address: 0x1020FF90
// Name: public: virtual struct vgui::PanelMessageMap __near * CParticleSnapshotPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CParticleSnapshotPanel::GetMessageMap(CParticleSnapshotPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CParticleSnapshotPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CParticleSnapshotPanel::GetMessageMap'::`2'::s_pMap;
  `CParticleSnapshotPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CParticleSnapshotPanel");
  `CParticleSnapshotPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1020FFC0
// Name: public: virtual struct PanelAnimationMap __near * CParticleSnapshotPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CParticleSnapshotPanel::GetAnimMap(CParticleSnapshotPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CParticleSnapshotPanel");
}

//------------------------------------------------------------------------------
// Address: 0x1020FFD0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CParticleSnapshotPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CParticleSnapshotPanel::GetKBMap(CParticleSnapshotPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CParticleSnapshotPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CParticleSnapshotPanel::GetKBMap'::`2'::s_pMap;
  `CParticleSnapshotPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CParticleSnapshotPanel");
  `CParticleSnapshotPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10210000
// Name: public: void CParticleSnapshotPanel::SetParticleSystem(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSnapshotPanel::SetParticleSystem(
        CParticleSnapshotPanel *this,
        const char *szSystemName,
        int nId)
{
  CUtlString *p_m_SystemName; // edi
  const char *v6; // eax
  CParticleSystemPanel *m_pParticlePanel; // eax
  CParticleSystemPanel *v8; // eax
  vgui::Label_vtbl *v9; // ebx
  const char *v10; // eax
  vgui::Label_vtbl *v11; // edi
  const char *v12; // eax
  CUtlString v13; // [esp+10h] [ebp-10h] BYREF
  bool v14; // [esp+2Bh] [ebp+Bh]

  p_m_SystemName = &this->m_SystemName;
  v6 = CUtlString::operator char const *(this: &this->m_SystemName);
  v14 = _V_strcmp(s1: v6, s2: szSystemName) == 0;
  CUtlString::operator=(this: p_m_SystemName, src: szSystemName);
  this->m_nSystemId = nId;
  if ( !v14 || CParticleSystemPanel::GetParticleSystem(this: this->m_pParticlePanel) == nullptr )
  {
    CParticleSystemPanel::SetParticleSystem(this: this->m_pParticlePanel, szParticleSystemName: szSystemName);
    m_pParticlePanel = this->m_pParticlePanel;
    m_pParticlePanel->m_pControlPointValue[0].x = 0.0;
    m_pParticlePanel->m_pControlPointValue[0].y = 0.0;
    m_pParticlePanel->m_pControlPointValue[0].z = 0.0;
    v8 = this->m_pParticlePanel;
    v8->m_pControlPointValue[1].y = 0.0;
    v8->m_pControlPointValue[1].z = 0.0;
    v8->m_pControlPointValue[1].x = 100.0;
    CPotteryWheelPanel::LookAt(this: this->m_pParticlePanel, flRadius: 50.0);
    v9 = this->m_pLabel->__vftable;
    v10 = CUtlString::operator char const *(this: p_m_SystemName);
    v9->SetText(this: this->m_pLabel, a2: v10);
    this->m_pParticlePanel->ResetView(this: this->m_pParticlePanel);
  }
  if ( CParticleSystemPanel::GetParticleSystem(this: this->m_pParticlePanel) != nullptr )
  {
    CPotteryWheelPanel::SetBackgroundColor(this: this->m_pParticlePanel, r: 32, g: 32, b: 32);
  }
  else
  {
    CUtlString::CUtlString(this: &v13, pString: "ERROR: ");
    CUtlString::operator+=(this: &v13, rhs: p_m_SystemName);
    v11 = this->m_pLabel->__vftable;
    v12 = CUtlString::operator char const *(this: &v13);
    v11->SetText(this: this->m_pLabel, a2: v12);
    CPotteryWheelPanel::SetBackgroundColor(this: this->m_pParticlePanel, r: 64, g: 0, b: 0);
    v13.m_Storage.m_nActualLength = 0;
    if ( v13.m_Storage.m_Memory.m_nGrowSize >= 0 && v13.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v13.m_Storage.m_Memory.m_pMemory);
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x102101A0
// Name: public: virtual void CParticleSnapshotGrid::OnScrollBarSliderMoved(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CParticleSnapshotGrid::OnScrollBarSliderMoved(CParticleSnapshotGrid *this)
{
  CParticleSnapshotGrid::LayoutScrolled(this);
}

//------------------------------------------------------------------------------
// Address: 0x102101B0
// Name: public: virtual void CParticleSnapshotGrid::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSnapshotGrid::OnMousePressed(CParticleSnapshotGrid *this, ButtonCode_t code)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  CToolEntitySprinkle::RenderTool2D((vgui::TreeView *)this, itemIndex: code);
  CParticleSnapshotGrid::SelectSystem(this, pSystemName: &var, bAddToSelection: false, bToggle: false);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "ParticleSystemSelectionChanged");
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10210210
// Name: public: virtual void CParticleSnapshotGrid::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSnapshotGrid::PerformLayout(CParticleSnapshotGrid *this)
{
  int v2; // edi
  int v3; // eax

  vgui::EditablePanel::PerformLayout(this);
  v2 = -8 - vgui::Panel::GetWide(this: this->m_pScrollBar);
  v3 = (v2 + vgui::Panel::GetWide(this)) / 200;
  if ( v3 < 1 )
    v3 = 1;
  this->m_nCurrentColCount = v3;
  CParticleSnapshotGrid::LayoutScrolled(this);
}

//------------------------------------------------------------------------------
// Address: 0x10210260
// Name: private: void CParticleSnapshotGrid::SetAllPreviewEnabled(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSnapshotGrid::SetAllPreviewEnabled(CParticleSnapshotGrid *this, BOOL bEnabled)
{
  int i; // edi
  CParticleSnapshotPanel *v4; // esi
  CParticleSystemPanel *m_pParticlePanel; // ecx

  for ( i = 0; i < this->m_Panels.m_Size; ++i )
  {
    v4 = this->m_Panels.m_Memory.m_pMemory[i];
    m_pParticlePanel = v4->m_pParticlePanel;
    v4->m_bPreviewEnabled = bEnabled;
    m_pParticlePanel->SetVisible(this: m_pParticlePanel, a2: bEnabled);
    v4->InvalidateLayout(this: v4, a2: false, a3: false);
  }
  this->InvalidateLayout(this, a2: true, a3: false);
  CParticleSnapshotGrid::LayoutScrolled(this);
}

//------------------------------------------------------------------------------
// Address: 0x102102D0
// Name: public: char const __near * CParticleSnapshotGrid::GetSystemName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CParticleSnapshotGrid::GetSystemName(CParticleSnapshotGrid *this, int nSystemId)
{
  int m_Size; // edx
  int v3; // eax
  CParticleSnapshotPanel **m_pMemory; // edi
  CParticleSnapshotPanel **i; // ecx

  m_Size = this->m_Panels.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return &var;
  m_pMemory = this->m_Panels.m_Memory.m_pMemory;
  for ( i = m_pMemory; (*i)->m_nSystemId != nSystemId; ++i )
  {
    if ( ++v3 >= m_Size )
      return &var;
  }
  if ( v3 < 0 || v3 >= m_Size )
    return &var;
  else
    return CUtlString::operator char const *(this: &m_pMemory[v3]->m_SystemName);
}

//------------------------------------------------------------------------------
// Address: 0x10210330
// Name: public: virtual void CParticleSnapshotGrid::OnParticleSystemShiftSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSnapshotGrid::OnParticleSystemShiftSelected(
        CParticleSnapshotGrid *this,
        const char *SystemName)
{
  int SystemIndexByName; // eax
  int m_nMostRecentSelectedIndex; // ecx
  int v5; // esi
  int v6; // ebx
  const char *v7; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // eax

  SystemIndexByName = CParticleSnapshotGrid::InternalFindSystemIndexByName(this, pSystemName: SystemName);
  if ( SystemIndexByName != -1 )
  {
    m_nMostRecentSelectedIndex = this->m_nMostRecentSelectedIndex;
    if ( m_nMostRecentSelectedIndex != -1 )
    {
      v5 = SystemIndexByName;
      if ( SystemIndexByName < m_nMostRecentSelectedIndex
        || (v5 = this->m_nMostRecentSelectedIndex,
            v6 = SystemIndexByName,
            SystemIndexByName <= m_nMostRecentSelectedIndex) )
      {
        v6 = this->m_nMostRecentSelectedIndex;
      }
      for ( ; v5 <= v6; ++v5 )
      {
        v7 = CUtlString::operator char const *(this: &this->m_Panels.m_Memory.m_pMemory[v5]->m_SystemName);
        CParticleSnapshotGrid::SelectSystem(this, pSystemName: v7, bAddToSelection: true, bToggle: false);
      }
      v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v8 != nullptr )
      {
        v9 = KeyValues::KeyValues(this: v8, setName: "ParticleSystemSelectionChanged");
        this->PostActionSignal(this, a2: v9);
      }
      else
      {
        this->PostActionSignal(this, a2: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102103E0
// Name: public: virtual void CParticleSnapshotGrid::OnKeyCodeTyped(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSnapshotGrid::OnKeyCodeTyped(CParticleSnapshotGrid *this, ButtonCode_t code)
{
  int m_nMostRecentSelectedIndex; // ecx
  int v4; // ecx
  int m_Size; // eax
  const char *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax

  if ( code == KEY_UP || code == KEY_DOWN || code == KEY_LEFT || code == KEY_RIGHT )
  {
    m_nMostRecentSelectedIndex = this->m_nMostRecentSelectedIndex;
    if ( m_nMostRecentSelectedIndex != -1 )
    {
      switch ( code )
      {
        case KEY_UP:
          v4 = m_nMostRecentSelectedIndex - this->m_nCurrentColCount;
          break;
        case KEY_DOWN:
          v4 = this->m_nCurrentColCount + m_nMostRecentSelectedIndex;
          break;
        case KEY_LEFT:
          v4 = m_nMostRecentSelectedIndex - 1;
          break;
        default:
          v4 = m_nMostRecentSelectedIndex + 1;
          break;
      }
      if ( v4 / this->m_nCurrentColCount >= (this->m_nCurrentColCount + this->m_Panels.m_Size - 1)
                                          / this->m_nCurrentColCount
                                          - 1 )
      {
        m_Size = this->m_Panels.m_Size;
        if ( v4 >= m_Size )
          v4 = m_Size - 1;
      }
      if ( v4 >= 0 && v4 < this->m_Panels.m_Size )
      {
        v6 = CUtlString::operator char const *(this: &this->m_Panels.m_Memory.m_pMemory[v4]->m_SystemName);
        CParticleSnapshotGrid::SelectSystem(this, pSystemName: v6, bAddToSelection: false, bToggle: false);
        v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v7 != nullptr )
          v8 = KeyValues::KeyValues(this: v7, setName: "ParticleSystemSelectionChanged");
        else
          v8 = nullptr;
        this->PostActionSignal(this, a2: v8);
        this->RequestFocus(this, a2: 0);
      }
    }
  }
  else
  {
    vgui::EditablePanel::OnKeyCodeTyped(this, code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102104E0
// Name: private: virtual void CParticlePicker::OnParticleSystemSelectionChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticlePicker::OnParticleSystemSelectionChanged(CParticlePicker *this)
{
  CParticleSnapshotGrid *m_pSnapshotGrid; // edi
  int SelectedSystemId; // eax
  const char *SystemName; // eax

  m_pSnapshotGrid = this->m_pSnapshotGrid;
  SelectedSystemId = CParticleSnapshotGrid::GetSelectedSystemId(this: m_pSnapshotGrid, nSelectionIndex: 0);
  SystemName = CParticleSnapshotGrid::GetSystemName(this: m_pSnapshotGrid, nSystemId: SelectedSystemId);
  CBaseAssetPicker::SetSelection(this, pAssetName: SystemName, bInitialSelection: false);
}

//------------------------------------------------------------------------------
// Address: 0x10210510
// Name: public: virtual class CUtlString CParticlePicker::GetSelectedAssetFullPath(int)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__thiscall CParticlePicker::GetSelectedAssetFullPath(
        CParticlePicker *this,
        CUtlString *result,
        int nSelectionIndex)
{
  int SelectedAssetIndex; // eax
  CachedParticleInfo_t *v5; // esi
  const CacheModInfo_t *v6; // edi
  const char *v7; // eax
  const char *v9; // [esp-8h] [ebp-194h]
  const char *v10; // [esp-4h] [ebp-190h]
  char pBuf[388]; // [esp+8h] [ebp-184h] BYREF

  SelectedAssetIndex = CBaseAssetPicker::GetSelectedAssetIndex(this, nSelectionIndex);
  if ( SelectedAssetIndex < 0 || SelectedAssetIndex >= sCacheParticleList.m_Size )
  {
    CUtlString::CUtlString(this: result, pString: "ERROR");
    return result;
  }
  else
  {
    v5 = &sCacheParticleList.m_Memory.m_pMemory[SelectedAssetIndex];
    v6 = CBaseAssetPicker::ModInfo(this, nIndex: v5->m_AssetInfo.m_nModIndex);
    v10 = CUtlString::Get(this: &v5->m_AssetInfo.m_AssetName);
    v9 = CUtlString::Get(this: &v5->m_FileName);
    v7 = CUtlString::operator char const *(this: &v6->m_Path);
    V_snprintf(pDest: pBuf, maxLen: 388, pFormat: "%s\\%s::%s", v7, v9, v10);
    V_FixSlashes(pname: pBuf, separator: 92);
    CUtlString::CUtlString(this: result, pString: pBuf);
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10210640
// Name: public: virtual void CParticleSnapshotGrid::OnCheckButtonChecked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSnapshotGrid::OnCheckButtonChecked(CParticleSnapshotGrid *this, KeyValues *kv)
{
  bool v3; // al

  v3 = this->m_pPreviewCheckbox->IsSelected(this: this->m_pPreviewCheckbox);
  CParticleSnapshotGrid::SetAllPreviewEnabled(this, bEnabled: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10210670
// Name: public: static void CParticleSnapshotGrid::PanelMessageFunc_OnParticleSystemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CParticleSnapshotGrid::PanelMessageFunc_OnParticleSystemSelected::InitVar(int a1@<ebp>)
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
  if ( !`CParticleSnapshotGrid::PanelMessageFunc_OnParticleSystemSelected::InitVar'::`2'::bAdded )
  {
    `CParticleSnapshotGrid::PanelMessageFunc_OnParticleSystemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CParticleSnapshotGrid");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ParticleSystemSelected";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "SystemName";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10210710
// Name: public: static void CParticleSnapshotGrid::PanelMessageFunc_OnParticleSystemCtrlSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CParticleSnapshotGrid::PanelMessageFunc_OnParticleSystemCtrlSelected::InitVar(int a1@<ebp>)
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
  if ( !`CParticleSnapshotGrid::PanelMessageFunc_OnParticleSystemCtrlSelected::InitVar'::`2'::bAdded )
  {
    `CParticleSnapshotGrid::PanelMessageFunc_OnParticleSystemCtrlSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CDmeSourceSkinPanel::`vcall'{948,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CParticleSnapshotGrid");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ParticleSystemCtrlSelected";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "SystemName";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102107B0
// Name: public: static void CParticleSnapshotGrid::PanelMessageFunc_OnParticleSystemShiftSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CParticleSnapshotGrid::PanelMessageFunc_OnParticleSystemShiftSelected::InitVar(int a1@<ebp>)
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
  if ( !`CParticleSnapshotGrid::PanelMessageFunc_OnParticleSystemShiftSelected::InitVar'::`2'::bAdded )
  {
    `CParticleSnapshotGrid::PanelMessageFunc_OnParticleSystemShiftSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSnapshotGrid::`vcall'{952,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CParticleSnapshotGrid");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ParticleSystemShiftSelected";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "SystemName";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10210850
// Name: public: static void CParticleSnapshotGrid::PanelMessageFunc_OnParticleSystemPicked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CParticleSnapshotGrid::PanelMessageFunc_OnParticleSystemPicked::InitVar(int a1@<ebp>)
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
  if ( !`CParticleSnapshotGrid::PanelMessageFunc_OnParticleSystemPicked::InitVar'::`2'::bAdded )
  {
    `CParticleSnapshotGrid::PanelMessageFunc_OnParticleSystemPicked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CColorPickerPanel::`vcall'{956,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CParticleSnapshotGrid");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ParticleSystemPicked";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "SystemName";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102108F0
// Name: public: static void CParticleSnapshotGrid::PanelMessageFunc_OnScrollBarSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CParticleSnapshotGrid::PanelMessageFunc_OnScrollBarSliderMoved::InitVar(int a1@<ebp>)
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
  if ( !`CParticleSnapshotGrid::PanelMessageFunc_OnScrollBarSliderMoved::InitVar'::`2'::bAdded )
  {
    `CParticleSnapshotGrid::PanelMessageFunc_OnScrollBarSliderMoved::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{960,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CParticleSnapshotGrid");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ScrollBarSliderMoved";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10210980
// Name: public: static void CParticleSnapshotGrid::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CParticleSnapshotGrid::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CParticleSnapshotGrid::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `CParticleSnapshotGrid::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeSlider::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CParticleSnapshotGrid");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10210A10
// Name: public: static void CParticlePicker::PanelMessageFunc_OnAssetSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CParticlePicker::PanelMessageFunc_OnAssetSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CParticlePicker::PanelMessageFunc_OnAssetSelected::InitVar'::`2'::bAdded )
  {
    `CParticlePicker::PanelMessageFunc_OnAssetSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CSoundPicker::`vcall'{1012,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CParticlePicker");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "AssetSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10210AA0
// Name: public: static void CParticlePicker::PanelMessageFunc_OnParticleSystemSelectionChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CParticlePicker::PanelMessageFunc_OnParticleSystemSelectionChanged::InitVar(int a1@<ebp>)
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
  if ( !`CParticlePicker::PanelMessageFunc_OnParticleSystemSelectionChanged::InitVar'::`2'::bAdded )
  {
    `CParticlePicker::PanelMessageFunc_OnParticleSystemSelectionChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CElementPropertiesTreeInternal::`vcall'{1016,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CParticlePicker");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ParticleSystemSelectionChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10210B30
// Name: public: static void CParticlePicker::PanelMessageFunc_OnParticleSystemPicked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CParticlePicker::PanelMessageFunc_OnParticleSystemPicked::InitVar(int a1@<ebp>)
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
  if ( !`CParticlePicker::PanelMessageFunc_OnParticleSystemPicked::InitVar'::`2'::bAdded )
  {
    `CParticlePicker::PanelMessageFunc_OnParticleSystemPicked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBaseToolSystem::`vcall'{1020,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CParticlePicker");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ParticleSystemPicked";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "SystemName";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10210BD0
// Name: public: static void CParticleSnapshotPanel::PanelMessageFunc_OnSetFocus::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CParticleSnapshotPanel::PanelMessageFunc_OnSetFocus::InitVar(int a1@<ebp>)
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
  if ( !`CParticleSnapshotPanel::PanelMessageFunc_OnSetFocus::InitVar'::`2'::bAdded )
  {
    `CParticleSnapshotPanel::PanelMessageFunc_OnSetFocus::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CSearchReplaceDlg::`vcall'{392,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CParticleSnapshotPanel");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "SetFocus";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10210C60
// Name: public: static void CParticleSnapshotPanel::PanelMessageFunc_OnParticleSystemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CParticleSnapshotPanel::PanelMessageFunc_OnParticleSystemSelected::InitVar(int a1@<ebp>)
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
  if ( !`CParticleSnapshotPanel::PanelMessageFunc_OnParticleSystemSelected::InitVar'::`2'::bAdded )
  {
    `CParticleSnapshotPanel::PanelMessageFunc_OnParticleSystemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CParticleSystemPreviewPanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CParticleSnapshotPanel");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ParticleSystemSelected";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "SystemName";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10210D00
// Name: public: CParticleSnapshotPanel::CParticleSnapshotPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CParticleSnapshotPanel *__thiscall CParticleSnapshotPanel::CParticleSnapshotPanel(
        CParticleSnapshotPanel *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::CBoxSizer *v7; // edi
  CParticleSystemPanel *v8; // eax
  CParticleSystemPanel *v9; // eax
  vgui::Label *v10; // eax
  vgui::Label *v11; // eax
  vgui::CBoxSizer *v12; // eax
  vgui::CBoxSizer *v13; // ebx
  CParticleSystemPanel *m_pParticlePanel; // edx
  vgui::CBoxSizer *v15; // eax
  vgui::MenuButton *v16; // eax
  vgui::MenuButton *v17; // eax
  vgui::MenuButton *v18; // eax
  vgui::MenuButton *v19; // eax
  vgui::Label *m_pLabel; // ecx
  int v21; // edx
  int v22; // ecx
  int m_Size; // [esp-8h] [ebp-30h]
  int v25; // [esp-8h] [ebp-30h]
  int v26; // [esp-8h] [ebp-30h]
  int v27; // [esp-4h] [ebp-2Ch]
  vgui::SizerAddArgs_t flRadius; // [esp+10h] [ebp-18h] BYREF
  int _28; // [esp+28h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CParticleSnapshotPanel_vtbl *)&CParticleSnapshotPanel::`vftable';
  if ( `CParticleSnapshotPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CParticleSnapshotPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CParticleSnapshotPanel");
    v4->pfnClassName = CParticleSnapshotPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CParticleSnapshotPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CParticleSnapshotPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CParticleSnapshotPanel");
    v5->pfnClassName = CParticleSnapshotPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CParticleSnapshotPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CParticleSnapshotPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CParticleSnapshotPanel");
    v6->pfnClassName = CParticleSnapshotPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CParticleSnapshotPanel::PanelMessageFunc_OnSetFocus::InitVar(a1: (int)&_28);
  CParticleSnapshotPanel::PanelMessageFunc_OnParticleSystemSelected::InitVar(a1: (int)&_28);
  CUtlString::CUtlString(this: &this->m_SystemName);
  v7 = nullptr;
  this->m_SelectedBgColor = 0;
  this->m_SelectedTextColor = 0;
  this->m_bSelected = false;
  this->m_bPreviewEnabled = true;
  v8 = (CParticleSystemPanel *)operator new(nSize: 0x800u);
  if ( v8 != nullptr )
    v9 = CParticleSystemPanel::CParticleSystemPanel(this: v8, pParent: this, pName);
  else
    v9 = nullptr;
  this->m_pParticlePanel = v9;
  CParticleSystemPanel::SetSelfSimulation(this: v9, bSelfSimulate: false);
  CPotteryWheelPanel::SetGridColor(this: this->m_pParticlePanel, r: 128, g: 128, b: 128);
  CParticleSystemPanel::RenderGrid(this: this->m_pParticlePanel, bEnable: true);
  CPotteryWheelPanel::SetParentMouseNotify(this: this->m_pParticlePanel, bParentMouseNotify: true);
  CParticleSystemPanel::EnableAutoViewing(this: this->m_pParticlePanel, bEnable: true);
  v10 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v10 != nullptr )
    v11 = vgui::Label::Label(this: v10, parent: this, panelName: "SystemLabel", text: "Unnamed");
  else
    v11 = nullptr;
  this->m_pLabel = v11;
  v11->SetContentAlignment(this: v11, a2: a_center);
  this->m_pLabel->SetPaintBackgroundEnabled(this: this->m_pLabel, a2: false);
  this->m_pLabel->SetMouseInputEnabled(this: this->m_pLabel, a2: false);
  v12 = (vgui::CBoxSizer *)operator new(nSize: 0x24u);
  if ( v12 != nullptr )
    v13 = vgui::CBoxSizer::CBoxSizer(this: v12, LayoutDirection: ESLD_VERTICAL);
  else
    v13 = nullptr;
  m_pParticlePanel = this->m_pParticlePanel;
  flRadius.m_nMinX = -1;
  flRadius.m_nMinY = -1;
  m_Size = v13->m_Members.m_Size;
  flRadius.m_bMinorExpand = true;
  flRadius.m_bIgnoreMemberMin = false;
  flRadius.m_flExpandFactor = 1.0;
  flRadius.m_nPadding = 5;
  vgui::CSizerBase::InsertPanel(this: v13, nIndex: m_Size, pPanel: m_pParticlePanel, args: &flRadius);
  v15 = (vgui::CBoxSizer *)operator new(nSize: 0x24u);
  if ( v15 != nullptr )
    v7 = vgui::CBoxSizer::CBoxSizer(this: v15, LayoutDirection: ESLD_HORIZONTAL);
  v16 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v16 != nullptr )
    v17 = vgui::MenuButton::MenuButton(this: v16, parent: this, panelName: "ParentsButton", text: "P");
  else
    v17 = nullptr;
  flRadius.m_nMinX = -1;
  flRadius.m_nMinY = -1;
  this->m_pParentsButton = v17;
  v25 = v7->m_Members.m_Size;
  flRadius.m_bMinorExpand = true;
  flRadius.m_bIgnoreMemberMin = false;
  flRadius.m_flExpandFactor = 0.0;
  flRadius.m_nPadding = 0;
  vgui::CSizerBase::InsertPanel(this: v7, nIndex: v25, pPanel: v17, args: &flRadius);
  v18 = (vgui::MenuButton *)operator new(nSize: 0x214u);
  if ( v18 != nullptr )
    v19 = vgui::MenuButton::MenuButton(this: v18, parent: this, panelName: "ChildrenButton", text: "C");
  else
    v19 = nullptr;
  flRadius.m_nMinX = -1;
  flRadius.m_nMinY = -1;
  this->m_pChildrenButton = v19;
  v26 = v7->m_Members.m_Size;
  flRadius.m_bMinorExpand = true;
  flRadius.m_bIgnoreMemberMin = false;
  flRadius.m_flExpandFactor = 0.0;
  flRadius.m_nPadding = 0;
  vgui::CSizerBase::InsertPanel(this: v7, nIndex: v26, pPanel: v19, args: &flRadius);
  m_pLabel = this->m_pLabel;
  v21 = v7->m_Members.m_Size;
  flRadius.m_nMinX = -1;
  flRadius.m_nMinY = -1;
  flRadius.m_bMinorExpand = true;
  flRadius.m_bIgnoreMemberMin = false;
  flRadius.m_flExpandFactor = 0.0;
  flRadius.m_nPadding = 2;
  vgui::CSizerBase::InsertPanel(this: v7, nIndex: v21, pPanel: m_pLabel, args: &flRadius);
  v22 = v13->m_Members.m_Size;
  flRadius.m_nMinX = -1;
  flRadius.m_nMinY = -1;
  flRadius.m_bMinorExpand = true;
  flRadius.m_bIgnoreMemberMin = false;
  flRadius.m_flExpandFactor = 0.0;
  flRadius.m_nPadding = 5;
  vgui::CSizerBase::InsertSizer(this: v13, nIndex: v22, pSizer: v7, args: &flRadius);
  flRadius.m_nMinX = -1;
  flRadius.m_nMinY = -1;
  v27 = v13->m_Members.m_Size;
  flRadius.m_flExpandFactor = 0.0;
  flRadius.m_bMinorExpand = true;
  flRadius.m_bIgnoreMemberMin = false;
  flRadius.m_nPadding = 5;
  vgui::CSizerBase::InsertSpacer(this: v13, nIndex: v27, args: &flRadius);
  vgui::Panel::SetSizer(this, pSizer: v13);
  vgui::Panel::InvalidateLayout(this, layoutNow: 1, reloadScheme: false);
  this->m_pParticlePanel->ResetView(this: this->m_pParticlePanel);
  CPotteryWheelPanel::LookAt(this: this->m_pParticlePanel, flRadius: 50.0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10211280
// Name: private: void CParticlePicker::HandleModParticles(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticlePicker::HandleModParticles(CParticlePicker *this, unsigned __int8 *nModIndex)
{
  const CacheModInfo_t *v2; // eax
  int v3; // edi
  const char *v4; // eax
  int i; // ebx
  int m_Size; // eax
  int v7; // esi
  PCFToLoad_t *m_pMemory; // edx
  int v9; // eax
  int v10; // esi
  CUtlString *p_m_FileName; // esi
  CUtlString *v12; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > pcfList; // [esp+4h] [ebp-24h] BYREF
  CUtlString manifestPath; // [esp+18h] [ebp-10h] BYREF

  v2 = CBaseAssetPicker::ModInfo(this, nIndex: (int)nModIndex);
  CUtlString::CUtlString(this: &manifestPath, string: &v2->m_Path);
  CUtlString::operator+=(this: &manifestPath, rhs: "/particles/particles_manifest.txt");
  v3 = 0;
  memset(&pcfList, 0, sizeof(pcfList));
  v4 = CUtlString::operator char const *(this: &manifestPath);
  GetParticleManifest(list: &pcfList, pFile: v4);
  if ( pcfList.m_Size > 0 )
  {
    for ( i = pcfList.m_Size; i != 0; --i )
    {
      m_Size = sCacheUnloadedPCFs.m_Size;
      v7 = sCacheUnloadedPCFs.m_Size;
      if ( sCacheUnloadedPCFs.m_Size + 1 > sCacheUnloadedPCFs.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
          this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&sCacheUnloadedPCFs,
          num: sCacheUnloadedPCFs.m_Size - sCacheUnloadedPCFs.m_Memory.m_nAllocationCount + 1);
        m_Size = sCacheUnloadedPCFs.m_Size;
      }
      m_pMemory = sCacheUnloadedPCFs.m_Memory.m_pMemory;
      sCacheUnloadedPCFs.m_Size = m_Size + 1;
      v9 = m_Size - v7;
      sCacheUnloadedPCFs.m_pElements = sCacheUnloadedPCFs.m_Memory.m_pMemory;
      if ( v9 > 0 )
      {
        _V_memmove(
          dest: &sCacheUnloadedPCFs.m_Memory.m_pMemory[v7 + 1],
          src: &sCacheUnloadedPCFs.m_Memory.m_pMemory[v7],
          count: 20 * v9);
        m_pMemory = sCacheUnloadedPCFs.m_Memory.m_pMemory;
      }
      v10 = v7;
      if ( &m_pMemory[v10] != nullptr )
      {
        CUtlString::CUtlString(this: &m_pMemory[v10].m_FileName);
        m_pMemory = sCacheUnloadedPCFs.m_Memory.m_pMemory;
      }
      p_m_FileName = &m_pMemory[v10].m_FileName;
      CUtlString::operator=(this: p_m_FileName, src: &pcfList.m_Memory.m_pMemory[v3++]);
      p_m_FileName[1].m_Storage.m_Memory.m_pMemory = nModIndex;
    }
  }
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &pcfList);
  v12 = pcfList.m_Memory.m_pMemory;
  if ( pcfList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( pcfList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pcfList.m_Memory.m_pMemory);
      v12 = nullptr;
      pcfList.m_Memory.m_pMemory = nullptr;
    }
    pcfList.m_Memory.m_nAllocationCount = 0;
  }
  pcfList.m_pElements = v12;
  if ( pcfList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v12 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12);
      pcfList.m_Memory.m_pMemory = nullptr;
    }
    pcfList.m_Memory.m_nAllocationCount = 0;
  }
  manifestPath.m_Storage.m_nActualLength = 0;
  if ( manifestPath.m_Storage.m_Memory.m_nGrowSize >= 0 && manifestPath.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: manifestPath.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10211500
// Name: private: void CParticlePicker::CachePCFInfo(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticlePicker::CachePCFInfo(
        CParticlePicker *this,
        int nModIndex,
        const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *pFileName)
{
  const char *v3; // ebx
  const CacheModInfo_t *v4; // edi
  CUtlString *p_m_Path; // edi
  const char *v6; // eax
  IBaseFileSystem_vtbl *v7; // esi
  const char *v8; // eax
  unsigned __int8 *m_pMemory; // eax
  bool v10; // zf
  const char *TypeString; // eax
  CachedParticleInfo_t *v12; // esi
  const char *v13; // eax
  CDmxAttribute *Attribute; // eax
  int v15; // edi
  CachedParticleInfo_t *v16; // esi
  const char *Name; // eax
  const char *v18; // [esp-14h] [ebp-68h]
  CUtlBuffer buf; // [esp+Ch] [ebp-48h] BYREF
  CUtlString pcfPath; // [esp+3Ch] [ebp-18h] BYREF
  int nCount; // [esp+4Ch] [ebp-8h]
  CDmxElement *pRoot; // [esp+50h] [ebp-4h] BYREF
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *definitions; // [esp+60h] [ebp+Ch]

  v3 = (const char *)pFileName;
  v4 = CBaseAssetPicker::ModInfo(this, nIndex: nModIndex);
  if ( LOBYTE(pFileName->m_Memory.m_pMemory) == 33 )
    v3 = (char *)&pFileName->m_Memory.m_pMemory + 1;
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  p_m_Path = &v4->m_Path;
  CUtlString::CUtlString(this: &pcfPath, string: p_m_Path);
  CUtlString::operator+=(this: &pcfPath, rhs: "/");
  CUtlString::operator+=(this: &pcfPath, rhs: v3);
  v6 = CUtlString::operator char const *(this: &pcfPath);
  CParticleSystemMgr::ReadParticleConfigFile(
    this: g_pParticleSystemMgr,
    pFileName: v6,
    bPrecache: true,
    bDecommitTempMemory: true);
  v7 = g_pFullFileSystem->IBaseFileSystem::__vftable;
  v18 = CUtlString::operator char const *(this: p_m_Path);
  v8 = CUtlString::operator char const *(this: &pcfPath);
  if ( !v7->ReadFile(this: &g_pFullFileSystem->IBaseFileSystem, a2: v8, a3: v18, a4: &buf, a5: 0, a6: 0, a7: nullptr) )
  {
LABEL_4:
    pcfPath.m_Storage.m_nActualLength = 0;
    if ( pcfPath.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( pcfPath.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pcfPath.m_Storage.m_Memory.m_pMemory);
        pcfPath.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      pcfPath.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    if ( buf.m_Memory.m_nGrowSize >= 0 )
    {
      m_pMemory = buf.m_Memory.m_pMemory;
      v10 = buf.m_Memory.m_pMemory == nullptr;
      goto LABEL_10;
    }
    return;
  }
  BeginDMXContext();
  if ( !UnserializeDMX(&buf, ppRoot: &pRoot, pFileName: v3) )
  {
    EndDMXContext(bDecommitMemory: true);
    goto LABEL_4;
  }
  TypeString = CDmxElement::GetTypeString(this: pRoot);
  if ( _V_stricmp(s1: TypeString, s2: "DmeParticleSystemDefinition") != 0 )
  {
    Attribute = (CDmxAttribute *)CDmxElement::GetAttribute(this: pRoot, pAttributeName: "particleSystemDefinitions");
    v15 = 0;
    if ( Attribute == nullptr || Attribute->m_Type != AT_FIRST_ARRAY_TYPE )
    {
      CleanupDMX(pRoot);
      EndDMXContext(bDecommitMemory: true);
      CUtlString::~CUtlString(this: &pcfPath);
      CUtlBuffer::~CUtlBuffer(this: &buf);
      return;
    }
    definitions = CDmxAttribute::GetArray<CDmxElement *>(this: Attribute);
    nCount = definitions->m_Size;
    if ( nCount > 0 )
    {
      do
      {
        v16 = &sCacheParticleList.m_Memory.m_pMemory[CUtlVector<CachedParticleInfo_t,CUtlMemory<CachedParticleInfo_t,int>>::InsertBefore(
                                                       this: &sCacheParticleList,
                                                       elem: sCacheParticleList.m_Size)];
        Name = CDmxElement::GetName(this: definitions->m_Memory.m_pMemory[v15]);
        CUtlString::operator=(this: &v16->m_AssetInfo.m_AssetName, src: Name);
        v16->m_AssetInfo.m_nModIndex = nModIndex;
        CUtlString::operator=(this: &v16->m_FileName, src: v3);
        ++v15;
      }
      while ( v15 < nCount );
    }
    CleanupDMX(pRoot);
    EndDMXContext(bDecommitMemory: true);
    pcfPath.m_Storage.m_nActualLength = 0;
    if ( pcfPath.m_Storage.m_Memory.m_nGrowSize >= 0 )
    {
      if ( pcfPath.m_Storage.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pcfPath.m_Storage.m_Memory.m_pMemory);
        pcfPath.m_Storage.m_Memory.m_pMemory = nullptr;
      }
      pcfPath.m_Storage.m_Memory.m_nAllocationCount = 0;
    }
    if ( buf.m_Memory.m_nGrowSize >= 0 )
    {
      m_pMemory = buf.m_Memory.m_pMemory;
      v10 = buf.m_Memory.m_pMemory == nullptr;
LABEL_10:
      if ( !v10 )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    }
  }
  else
  {
    v12 = &sCacheParticleList.m_Memory.m_pMemory[CUtlVector<CachedParticleInfo_t,CUtlMemory<CachedParticleInfo_t,int>>::InsertBefore(
                                                   this: &sCacheParticleList,
                                                   elem: sCacheParticleList.m_Size)];
    v13 = CDmxElement::GetName(this: pRoot);
    CUtlString::operator=(this: &v12->m_AssetInfo.m_AssetName, src: v13);
    v12->m_AssetInfo.m_nModIndex = nModIndex;
    CUtlString::operator=(this: &v12->m_FileName, src: v3);
    EndDMXContext(bDecommitMemory: true);
    CUtlString::~CUtlString(this: &pcfPath);
    if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102117A0
// Name: public: virtual bool CParticlePicker::BeginCacheAssets(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CParticlePicker::BeginCacheAssets(CParticlePicker *this, bool bForceRecache)
{
  int v4; // edi
  unsigned __int8 *i; // esi

  if ( bForceRecache )
  {
    CUtlVector<CachedParticleInfo_t,CUtlMemory<CachedParticleInfo_t,int>>::RemoveAll(this: &sCacheParticleList);
    CUtlVector<PCFToLoad_t,CUtlMemory<PCFToLoad_t,int>>::RemoveAll(this: &sCacheUnloadedPCFs);
  }
  if ( sCacheParticleList.m_Size != 0 )
    return 1;
  v4 = CBaseAssetPicker::ModCount(this);
  for ( i = nullptr; (int)i < v4; ++i )
    CParticlePicker::HandleModParticles(this, nModIndex: i);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10211800
// Name: public: virtual bool CParticlePicker::IncrementalCacheAssets(float)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10211980
// Name: private: void CParticleSnapshotGrid::MapSystemRelatives(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSnapshotGrid::MapSystemRelatives(CParticleSnapshotGrid *this)
{
  CParticleSnapshotGrid *v1; // esi
  const char *ParticleSystemNameFromIndex; // eax
  int v3; // ebx
  CParticleSystemDefinition *ParticleSystem; // edi
  CParticleCollection *v5; // eax
  int v6; // eax
  unsigned __int8 *v7; // eax
  CParticleSystemDefinition *v8; // edi
  int v9; // ebx
  CParticleCollection *v10; // eax
  const char *Name; // eax
  CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *v12; // esi
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // edi
  int m_nAllocationCount; // eax
  vgui::CTreeViewListControl::CColumnInfo *v15; // ecx
  int v16; // eax
  int v17; // esi
  int v18; // ebx
  const char *v19; // eax
  CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *v20; // esi
  vgui::CTreeViewListControl::CColumnInfo *v21; // edi
  int v22; // eax
  vgui::CTreeViewListControl::CColumnInfo *v23; // ecx
  int v24; // eax
  int v25; // esi
  int v26; // edi
  CParticleSnapshotGrid::PSysRelativeInfo_t childInfo; // [esp+8h] [ebp-34h] BYREF
  int v28; // [esp+1Ch] [ebp-20h]
  int c; // [esp+20h] [ebp-1Ch]
  int nChildVisibleIndex; // [esp+24h] [ebp-18h]
  int i; // [esp+28h] [ebp-14h]
  CParticleSystemDefinition *pPotentialParent; // [esp+2Ch] [ebp-10h]
  int nParentVisibileIndex; // [esp+30h] [ebp-Ch]
  CParticleSnapshotGrid *v34; // [esp+34h] [ebp-8h]
  CParticleSystemDefinition *pChild; // [esp+38h] [ebp-4h]

  v1 = this;
  v34 = this;
  CUtlVector<CUtlVector<CParticleSnapshotGrid::PSysRelativeInfo_t,CUtlMemory<CParticleSnapshotGrid::PSysRelativeInfo_t,int>>,CUtlMemory<CUtlVector<CParticleSnapshotGrid::PSysRelativeInfo_t,CUtlMemory<CParticleSnapshotGrid::PSysRelativeInfo_t,int>>,int>>::RemoveAll(this: &this->m_ParentsMap);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&v1->m_ParentsMap,
    elem: v1->m_ParentsMap.m_Size,
    num: v1->m_Panels.m_Size);
  CUtlVector<CUtlVector<CParticleSnapshotGrid::PSysRelativeInfo_t,CUtlMemory<CParticleSnapshotGrid::PSysRelativeInfo_t,int>>,CUtlMemory<CUtlVector<CParticleSnapshotGrid::PSysRelativeInfo_t,CUtlMemory<CParticleSnapshotGrid::PSysRelativeInfo_t,int>>,int>>::RemoveAll(this: &v1->m_ChildrenMap);
  CUtlVector<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,CUtlMemory<CUtlVector<ikcontextikrule_t,CUtlMemory<ikcontextikrule_t,int>>,int>>::InsertMultipleBefore(
    this: (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)&v1->m_ChildrenMap,
    elem: v1->m_ChildrenMap.m_Size,
    num: v1->m_Panels.m_Size);
  i = 0;
  if ( CParticleSystemMgr::GetParticleSystemCount(this: g_pParticleSystemMgr) > 0 )
  {
    do
    {
      ParticleSystemNameFromIndex = CParticleSystemMgr::GetParticleSystemNameFromIndex(
                                      this: g_pParticleSystemMgr,
                                      iIndex: i);
      v3 = 0;
      ParticleSystem = CParticleSystemMgr::FindParticleSystem(
                         this: g_pParticleSystemMgr,
                         pName: ParticleSystemNameFromIndex);
      pPotentialParent = ParticleSystem;
      nParentVisibileIndex = -1;
      if ( v1->m_Panels.m_Size > 0 )
      {
        while ( 1 )
        {
          v5 = CParticleSystemPanel::GetParticleSystem(this: v1->m_Panels.m_Memory.m_pMemory[v3]->m_pParticlePanel);
          if ( v5 != nullptr && ParticleSystem == v5->m_pDef.m_pObject )
            break;
          if ( ++v3 >= v1->m_Panels.m_Size )
            goto LABEL_8;
        }
        nParentVisibileIndex = v3;
      }
LABEL_8:
      v6 = 0;
      c = 0;
      if ( ParticleSystem->m_Children.m_Size > 0 )
      {
        v28 = 0;
        while ( 1 )
        {
          v7 = &ParticleSystem->m_Children.m_Memory.m_pMemory->m_Id.m_Value[v6];
          if ( v7[20] != 0 )
          {
            v8 = CParticleSystemMgr::FindParticleSystem(
                   this: g_pParticleSystemMgr,
                   hParticleSystem: *((_DWORD *)v7 + 4));
            pChild = v8;
          }
          else
          {
            pChild = CParticleSystemMgr::FindParticleSystem(this: g_pParticleSystemMgr, id: (const UniqueId_t *)v7);
            v8 = pChild;
          }
          if ( v8 != nullptr )
          {
            v9 = 0;
            nChildVisibleIndex = -1;
            if ( v1->m_Panels.m_Size > 0 )
            {
              while ( 1 )
              {
                v10 = CParticleSystemPanel::GetParticleSystem(this: v1->m_Panels.m_Memory.m_pMemory[v9]->m_pParticlePanel);
                if ( v10 != nullptr && v8 == v10->m_pDef.m_pObject )
                  break;
                if ( ++v9 >= v1->m_Panels.m_Size )
                  goto LABEL_30;
              }
              CUtlString::CUtlString(this: &childInfo.relName);
              Name = CParticleSystemDefinition::GetName(this: pPotentialParent);
              CUtlString::operator=(this: &childInfo.relName, src: Name);
              v12 = (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&v1->m_ParentsMap.m_Memory.m_pMemory[v9];
              childInfo.bVisibleInCurrentView = nParentVisibileIndex != -1;
              m_pMemory = v12[1].m_pMemory;
              m_nAllocationCount = v12->m_nAllocationCount;
              if ( (int)&m_pMemory->m_Title.m_Id + 1 > m_nAllocationCount )
                CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
                  this: v12,
                  num: (int)&m_pMemory->m_Title.m_Id - m_nAllocationCount + 1);
              ++v12[1].m_pMemory;
              v15 = v12->m_pMemory;
              v16 = (char *)v12[1].m_pMemory - (char *)m_pMemory - 1;
              v12[1].m_nAllocationCount = (int)v12->m_pMemory;
              if ( v16 > 0 )
                _V_memmove(dest: &v15[(int)m_pMemory + 1], src: &v15[(_DWORD)m_pMemory], count: 20 * v16);
              v17 = (int)&v12->m_pMemory[(_DWORD)m_pMemory];
              if ( v17 != 0 )
              {
                CUtlString::CUtlString(this: (CUtlString *)v17, string: &childInfo.relName);
                *(_BYTE *)(v17 + 16) = childInfo.bVisibleInCurrentView;
              }
              nChildVisibleIndex = v9;
              childInfo.relName.m_Storage.m_nActualLength = 0;
              if ( childInfo.relName.m_Storage.m_Memory.m_nGrowSize >= 0
                && childInfo.relName.m_Storage.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: childInfo.relName.m_Storage.m_Memory.m_pMemory);
              }
              v1 = v34;
              v8 = pChild;
            }
LABEL_30:
            v18 = nParentVisibileIndex;
            if ( nParentVisibileIndex != -1 )
            {
              CUtlString::CUtlString(this: &childInfo.relName);
              v19 = CParticleSystemDefinition::GetName(this: v8);
              CUtlString::operator=(this: &childInfo.relName, src: v19);
              v20 = (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&v1->m_ChildrenMap.m_Memory.m_pMemory[v18];
              childInfo.bVisibleInCurrentView = nChildVisibleIndex != -1;
              v21 = v20[1].m_pMemory;
              v22 = v20->m_nAllocationCount;
              if ( (int)&v21->m_Title.m_Id + 1 > v22 )
                CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
                  this: v20,
                  num: (int)&v21->m_Title.m_Id - v22 + 1);
              ++v20[1].m_pMemory;
              v23 = v20->m_pMemory;
              v24 = (char *)v20[1].m_pMemory - (char *)v21 - 1;
              v20[1].m_nAllocationCount = (int)v20->m_pMemory;
              if ( v24 > 0 )
                _V_memmove(dest: &v23[(int)v21 + 1], src: &v23[(_DWORD)v21], count: 20 * v24);
              v25 = (int)&v20->m_pMemory[(_DWORD)v21];
              if ( v25 != 0 )
              {
                CUtlString::CUtlString(this: (CUtlString *)v25, string: &childInfo.relName);
                *(_BYTE *)(v25 + 16) = childInfo.bVisibleInCurrentView;
              }
              childInfo.relName.m_Storage.m_nActualLength = 0;
              if ( childInfo.relName.m_Storage.m_Memory.m_nGrowSize >= 0
                && childInfo.relName.m_Storage.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: childInfo.relName.m_Storage.m_Memory.m_pMemory);
              }
              v1 = v34;
            }
          }
          v6 = v28 + 32;
          ++c;
          v28 += 32;
          if ( c >= pPotentialParent->m_Children.m_Size )
            break;
          ParticleSystem = pPotentialParent;
        }
      }
      v26 = ++i;
    }
    while ( v26 < CParticleSystemMgr::GetParticleSystemCount(this: g_pParticleSystemMgr) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10211CB0
// Name: public: void CParticleSnapshotGrid::SetParticleList(class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticleSnapshotGrid::SetParticleList(
        CParticleSnapshotGrid *this,
        const CUtlVector<char const *,CUtlMemory<char const *,int> > *ParticleNames)
{
  CParticleSnapshotPanel *v3; // ecx
  CParticleSnapshotPanel *v4; // eax
  CParticleSnapshotPanel *v5; // edi
  CParticleSystemPanel *m_pParticlePanel; // ecx
  int v7; // ecx
  int m_nAllocationCount; // eax
  CParticleSnapshotPanel **m_pMemory; // edx
  int v10; // eax
  CParticleSnapshotPanel **v11; // ecx
  int i; // edi
  CParticleSnapshotPanel *v13; // ecx
  int j; // edi
  void (__thiscall *InvalidateLayout)(vgui::Panel *, bool, bool); // eax
  char szPanelName[32]; // [esp+Ch] [ebp-28h] BYREF
  int m_Size; // [esp+2Ch] [ebp-8h]
  BOOL bPreviewEnabled; // [esp+30h] [ebp-4h]

  for ( LOBYTE(bPreviewEnabled) = this->m_pPreviewCheckbox->IsSelected(this: this->m_pPreviewCheckbox);
        this->m_Panels.m_Size > ParticleNames->m_Size;
        --this->m_Panels.m_Size )
  {
    v3 = this->m_Panels.m_Memory.m_pMemory[this->m_Panels.m_Size - 1];
    if ( v3 != nullptr )
      ((void (__thiscall *)(CParticleSnapshotPanel *, int))v3->dtr_Panel)(a1: v3, a2: 1);
  }
  while ( this->m_Panels.m_Size < ParticleNames->m_Size )
  {
    V_snprintf(pDest: szPanelName, maxLen: 32, pFormat: "ParticlePanel%d", this->m_Panels.m_Size);
    v4 = (CParticleSnapshotPanel *)operator new(nSize: 0x1BCu);
    if ( v4 != nullptr )
      v5 = CParticleSnapshotPanel::CParticleSnapshotPanel(this: v4, pParent: this->m_pScrollPanel, pName: szPanelName);
    else
      v5 = nullptr;
    m_pParticlePanel = v5->m_pParticlePanel;
    v5->m_bPreviewEnabled = bPreviewEnabled;
    m_pParticlePanel->SetVisible(this: m_pParticlePanel, a2: bPreviewEnabled);
    v5->InvalidateLayout(this: v5, a2: false, a3: false);
    v5->AddActionSignalTarget_2(this: v5, a2: this);
    m_nAllocationCount = this->m_Panels.m_Memory.m_nAllocationCount;
    m_Size = this->m_Panels.m_Size;
    v7 = m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
    {
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Panels,
        num: m_Size - m_nAllocationCount + 1);
      v7 = m_Size;
    }
    ++this->m_Panels.m_Size;
    m_pMemory = this->m_Panels.m_Memory.m_pMemory;
    v10 = this->m_Panels.m_Size - v7 - 1;
    this->m_Panels.m_pElements = m_pMemory;
    if ( v10 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v7 + 1], src: &m_pMemory[v7], count: 4 * v10);
      v7 = m_Size;
    }
    v11 = &this->m_Panels.m_Memory.m_pMemory[v7];
    if ( v11 != nullptr )
      *v11 = v5;
  }
  for ( i = 0; i < this->m_Panels.m_Size; v13->m_bSelected = false )
  {
    if ( i >= ParticleNames->m_Size )
      CParticleSnapshotPanel::SetParticleSystem(this: this->m_Panels.m_Memory.m_pMemory[i], szSystemName: &var, nId: i);
    else
      CParticleSnapshotPanel::SetParticleSystem(
        this: this->m_Panels.m_Memory.m_pMemory[i],
        szSystemName: ParticleNames->m_Memory.m_pMemory[i],
        nId: i);
    v13 = this->m_Panels.m_Memory.m_pMemory[i++];
  }
  CUtlVector<mstudioseqdesc_t *,CUtlMemory<mstudioseqdesc_t *,int>>::Sort(
    this: (CUtlVector<vgui::CConsolePanel::CompletionItem *,CUtlMemory<vgui::CConsolePanel::CompletionItem *,int> > *)&this->m_Panels,
    pfnCompare: (int (__cdecl *)(vgui::CConsolePanel::CompletionItem *const *, vgui::CConsolePanel::CompletionItem *const *))PanelSortHelperI);
  CParticleSnapshotGrid::MapSystemRelatives(this);
  for ( j = 0; j < this->m_Panels.m_Size; ++j )
    CParticleSnapshotGrid::UpdatePanelRelatives(this, nIndex: j);
  InvalidateLayout = this->InvalidateLayout;
  this->m_nMostRecentSelectedIndex = -1;
  InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10211EC0
// Name: protected: virtual void CParticlePicker::OnAssetListChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CParticlePicker::OnAssetListChanged(CParticlePicker *this)
{
  int (__thiscall *GetAssetCount)(CBaseAssetPicker *); // edx
  int m_Size; // esi
  const CachedAssetInfo_t *v4; // edi
  int v5; // edi
  const char **m_pMemory; // ecx
  const char **v7; // edi
  CUtlVector<char const *,CUtlMemory<char const *,int> > assetNames; // [esp+Ch] [ebp-20h] BYREF
  int nCount; // [esp+20h] [ebp-Ch]
  const char *v10; // [esp+24h] [ebp-8h]
  int i; // [esp+28h] [ebp-4h]

  GetAssetCount = this->GetAssetCount;
  m_Size = 0;
  memset(&assetNames, 0, sizeof(assetNames));
  v4 = nullptr;
  nCount = GetAssetCount(this);
  i = 0;
  if ( nCount > 0 )
  {
    do
    {
      if ( CBaseAssetPicker::IsAssetVisible(this, nAssetIndex: v4) )
      {
        v10 = this->GetAssetName(this, a2: v4);
        v5 = m_Size;
        if ( m_Size + 1 > assetNames.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CVisGroup *,int>::Grow(
            this: (CUtlMemory<CCullTreeNode *,int> *)&assetNames,
            num: m_Size - assetNames.m_Memory.m_nAllocationCount + 1);
          m_Size = assetNames.m_Size;
        }
        m_pMemory = assetNames.m_Memory.m_pMemory;
        assetNames.m_Size = ++m_Size;
        assetNames.m_pElements = assetNames.m_Memory.m_pMemory;
        if ( m_Size - v5 - 1 > 0 )
        {
          _V_memmove(
            dest: &assetNames.m_Memory.m_pMemory[v5 + 1],
            src: &assetNames.m_Memory.m_pMemory[v5],
            count: 4 * (m_Size - v5 - 1));
          m_pMemory = assetNames.m_Memory.m_pMemory;
        }
        v7 = &m_pMemory[v5];
        if ( v7 != nullptr )
          *v7 = v10;
        v4 = (const CachedAssetInfo_t *)i;
      }
      v4 = (const CachedAssetInfo_t *)((char *)v4 + 1);
      i = (int)v4;
    }
    while ( (int)v4 < nCount );
  }
  CUtlVector<mstudioseqdesc_t *,CUtlMemory<mstudioseqdesc_t *,int>>::Sort(
    this: (CUtlVector<vgui::CConsolePanel::CompletionItem *,CUtlMemory<vgui::CConsolePanel::CompletionItem *,int> > *)&assetNames,
    pfnCompare: (int (__cdecl *)(vgui::CConsolePanel::CompletionItem *const *, vgui::CConsolePanel::CompletionItem *const *))StringSortHelperI);
  CParticleSnapshotGrid::SetParticleList(this: this->m_pSnapshotGrid, ParticleNames: &assetNames);
  if ( assetNames.m_Memory.m_nGrowSize >= 0 && assetNames.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: assetNames.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10212010
// Name: public: CParticleSnapshotGrid::CParticleSnapshotGrid(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CParticleSnapshotGrid *__thiscall CParticleSnapshotGrid::CParticleSnapshotGrid(
        CParticleSnapshotGrid *this,
        vgui::Panel *pParent,
        const char *pName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::ScrollBar *v7; // eax
  vgui::ScrollBar *v8; // eax
  vgui::Panel *v9; // eax
  vgui::Panel *v10; // eax
  vgui::Panel *v11; // eax
  vgui::Panel *v12; // eax
  vgui::CBoxSizer *v13; // eax
  vgui::CBoxSizer *v14; // eax
  vgui::CheckButton *v15; // eax
  vgui::CheckButton *v16; // eax
  vgui::Panel *m_pToolPanel; // ecx
  vgui::CheckButton *m_pPreviewCheckbox; // edi
  vgui::CSizerBase *Sizer; // eax
  vgui::Label *v20; // eax
  vgui::Label *v21; // eax
  unsigned int vpanel; // eax
  vgui::SizerAddArgs_t args; // [esp+Ch] [ebp-18h] BYREF
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pName);
  this->__vftable = (CParticleSnapshotGrid_vtbl *)&CParticleSnapshotGrid::`vftable';
  if ( `CParticleSnapshotGrid::ChainToMap'::`2'::chained == 0 )
  {
    `CParticleSnapshotGrid::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CParticleSnapshotGrid");
    v4->pfnClassName = CParticleSnapshotGrid::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CParticleSnapshotGrid::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CParticleSnapshotGrid::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CParticleSnapshotGrid");
    v5->pfnClassName = CParticleSnapshotGrid::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CParticleSnapshotGrid::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CParticleSnapshotGrid::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CParticleSnapshotGrid");
    v6->pfnClassName = CParticleSnapshotGrid::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CParticleSnapshotGrid::PanelMessageFunc_OnParticleSystemSelected::InitVar(a1: (int)&savedregs);
  CParticleSnapshotGrid::PanelMessageFunc_OnParticleSystemCtrlSelected::InitVar(a1: (int)&savedregs);
  CParticleSnapshotGrid::PanelMessageFunc_OnParticleSystemShiftSelected::InitVar(a1: (int)&savedregs);
  CParticleSnapshotGrid::PanelMessageFunc_OnParticleSystemPicked::InitVar(a1: (int)&savedregs);
  CParticleSnapshotGrid::PanelMessageFunc_OnScrollBarSliderMoved::InitVar(a1: (int)&savedregs);
  CParticleSnapshotGrid::PanelMessageFunc_OnCheckButtonChecked::InitVar(a1: (int)&savedregs);
  this->m_Panels.m_Memory.m_pMemory = nullptr;
  this->m_Panels.m_Memory.m_nAllocationCount = 0;
  this->m_Panels.m_Memory.m_nGrowSize = 0;
  this->m_Panels.m_Size = 0;
  this->m_Panels.m_pElements = nullptr;
  this->m_ParentsMap.m_Memory.m_pMemory = nullptr;
  this->m_ParentsMap.m_Memory.m_nAllocationCount = 0;
  this->m_ParentsMap.m_Memory.m_nGrowSize = 0;
  this->m_ParentsMap.m_Size = 0;
  this->m_ParentsMap.m_pElements = nullptr;
  this->m_ChildrenMap.m_Memory.m_pMemory = nullptr;
  this->m_ChildrenMap.m_Memory.m_nAllocationCount = 0;
  this->m_ChildrenMap.m_Memory.m_nGrowSize = 0;
  this->m_ChildrenMap.m_Size = 0;
  this->m_ChildrenMap.m_pElements = nullptr;
  this->m_pRelativesImgNeither = g_pVGuiSchemeManager->GetImage(
                                   this: g_pVGuiSchemeManager,
                                   a2: "tools/particles/icon_particles_rel_neither",
                                   a3: 0);
  this->m_pRelativesImgPOnly = g_pVGuiSchemeManager->GetImage(
                                 this: g_pVGuiSchemeManager,
                                 a2: "tools/particles/icon_particles_rel_ponly",
                                 a3: 0);
  this->m_pRelativesImgCOnly = g_pVGuiSchemeManager->GetImage(
                                 this: g_pVGuiSchemeManager,
                                 a2: "tools/particles/icon_particles_rel_conly",
                                 a3: 0);
  this->m_pRelativesImgBoth = g_pVGuiSchemeManager->GetImage(
                                this: g_pVGuiSchemeManager,
                                a2: "tools/particles/icon_particles_rel_both",
                                a3: 0);
  v7 = (vgui::ScrollBar *)operator new(nSize: 0x17Cu);
  if ( v7 != nullptr )
    v8 = vgui::ScrollBar::ScrollBar(this: v7, parent: this, panelName: "ScrollBar", vertical: true);
  else
    v8 = nullptr;
  this->m_pScrollBar = v8;
  vgui::Panel::SetWide(this: v8, wide: 16);
  vgui::Panel::SetAutoResize(
    this: this->m_pScrollBar,
    pinCorner: PIN_TOPRIGHT,
    resizeDir: AUTORESIZE_DOWN,
    nPinOffsetX: 0,
    nPinOffsetY: 30,
    nUnpinnedCornerOffsetX: -16,
    nUnpinnedCornerOffsetY: 0);
  this->m_pScrollBar->AddActionSignalTarget_2(this: this->m_pScrollBar, a2: this);
  v9 = (vgui::Panel *)operator new(nSize: 0x14Cu);
  if ( v9 != nullptr )
    v10 = vgui::Panel::Panel(this: v9, parent: this, panelName: "ScrollPanel");
  else
    v10 = nullptr;
  this->m_pScrollPanel = v10;
  vgui::Panel::SetAutoResize(
    this: v10,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 30,
    nUnpinnedCornerOffsetX: -16,
    nUnpinnedCornerOffsetY: 0);
  this->m_pScrollPanel->_flags.m_nFlags |= 0x8000u;
  v11 = (vgui::Panel *)operator new(nSize: 0x14Cu);
  if ( v11 != nullptr )
    v12 = vgui::Panel::Panel(this: v11, parent: this, panelName: "ToolPanel");
  else
    v12 = nullptr;
  this->m_pToolPanel = v12;
  vgui::Panel::SetTall(this: v12, tall: 30);
  vgui::Panel::SetAutoResize(
    this: this->m_pToolPanel,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_RIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: -16,
    nUnpinnedCornerOffsetY: 0);
  v13 = (vgui::CBoxSizer *)operator new(nSize: 0x24u);
  if ( v13 != nullptr )
    v14 = vgui::CBoxSizer::CBoxSizer(this: v13, LayoutDirection: ESLD_HORIZONTAL);
  else
    v14 = nullptr;
  vgui::Panel::SetSizer(this: this->m_pToolPanel, pSizer: v14);
  v15 = (vgui::CheckButton *)operator new(nSize: 0x218u);
  if ( v15 != nullptr )
    v16 = vgui::CheckButton::CheckButton(
            this: v15,
            parent: this->m_pToolPanel,
            panelName: "PreviewCheckbox",
            text: "Show Previews");
  else
    v16 = nullptr;
  this->m_pPreviewCheckbox = v16;
  v16->SetSelected(this: v16, a2: true);
  this->m_pPreviewCheckbox->AddActionSignalTarget_2(this: this->m_pPreviewCheckbox, a2: this);
  m_pToolPanel = this->m_pToolPanel;
  m_pPreviewCheckbox = this->m_pPreviewCheckbox;
  args.m_flExpandFactor = 0.0;
  args.m_nPadding = 5;
  args.m_bMinorExpand = true;
  args.m_nMinX = -1;
  args.m_nMinY = -1;
  args.m_bIgnoreMemberMin = false;
  Sizer = vgui::Panel::GetSizer(this: m_pToolPanel);
  vgui::CSizerBase::InsertPanel(this: Sizer, nIndex: Sizer->m_Members.m_Size, pPanel: m_pPreviewCheckbox, &args);
  v20 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v20 != nullptr )
    v21 = vgui::Label::Label(this: v20, parent: this->m_pScrollPanel, panelName: "NoSystemsLabel", text: "<No Systems>");
  else
    v21 = nullptr;
  this->m_pNoSystemsLabel = v21;
  vpanel = this->_vpanel;
  this->m_nCurrentColCount = 1;
  this->m_nMostRecentSelectedIndex = -1;
  g_pVGui->AddTickSignal(this: g_pVGui, a2: vpanel, a3: 0);
  vgui::Panel::SetKeyBoardInputEnabled(this, state: 1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102123B0
// Name: public: virtual struct vgui::PanelMessageMap __near * CParticleSnapshotGrid::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CParticleSnapshotGrid::GetMessageMap(CParticleSnapshotGrid *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CParticleSnapshotGrid::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CParticleSnapshotGrid::GetMessageMap'::`2'::s_pMap;
  `CParticleSnapshotGrid::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CParticleSnapshotGrid");
  `CParticleSnapshotGrid::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102123E0
// Name: public: virtual struct PanelAnimationMap __near * CParticleSnapshotGrid::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CParticleSnapshotGrid::GetAnimMap(CParticleSnapshotGrid *this)
{
  return FindOrAddPanelAnimationMap(className: "CParticleSnapshotGrid");
}

//------------------------------------------------------------------------------
// Address: 0x102123F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CParticleSnapshotGrid::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CParticleSnapshotGrid::GetKBMap(CParticleSnapshotGrid *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CParticleSnapshotGrid::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CParticleSnapshotGrid::GetKBMap'::`2'::s_pMap;
  `CParticleSnapshotGrid::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CParticleSnapshotGrid");
  `CParticleSnapshotGrid::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10212420
// Name: public: CParticlePicker::CParticlePicker(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CParticlePicker *__thiscall CParticlePicker::CParticlePicker(CParticlePicker *this, vgui::Panel *pParent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::Splitter *v6; // eax
  vgui::Splitter *v7; // eax
  vgui::Panel *Child; // edi
  vgui::Panel *v9; // ebx
  CParticleSnapshotGrid *v10; // eax
  CParticleSnapshotGrid *v11; // eax
  float flFractions[2]; // [esp+Ch] [ebp-8h] BYREF
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  CBaseAssetPicker::CBaseAssetPicker(
    this,
    pParent,
    pAssetType: "Particle Systems",
    pExt: "pcf",
    pSubDir: "particles",
    pTextType: "pcfName",
    pAssetSearchPath: "GAME");
  this->__vftable = (CParticlePicker_vtbl *)&CParticlePicker::`vftable';
  if ( `CParticlePicker::ChainToMap'::`2'::chained == 0 )
  {
    `CParticlePicker::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CParticlePicker");
    v3->pfnClassName = CParticlePicker::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseAssetPicker");
  }
  if ( `CParticlePicker::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CParticlePicker::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CParticlePicker");
    v4->pfnClassName = CParticlePicker::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "CBaseAssetPicker");
  }
  if ( `CParticlePicker::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CParticlePicker::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CParticlePicker");
    v5->pfnClassName = CParticlePicker::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseAssetPicker");
  }
  CParticlePicker::PanelMessageFunc_OnAssetSelected::InitVar(a1: (int)&savedregs);
  CParticlePicker::PanelMessageFunc_OnParticleSystemSelectionChanged::InitVar(a1: (int)&savedregs);
  CParticlePicker::PanelMessageFunc_OnParticleSystemPicked::InitVar(a1: (int)&savedregs);
  v6 = (vgui::Splitter *)operator new(nSize: 0x198u);
  if ( v6 != nullptr )
    v7 = vgui::Splitter::Splitter(
           this: v6,
           parent: this,
           name: "FileBrowserSplitter",
           mode: SPLITTER_MODE_VERTICAL,
           nCount: 1);
  else
    v7 = nullptr;
  flFractions[0] = 0.33000001;
  this->m_pFileBrowserSplitter = v7;
  flFractions[1] = 0.67000002;
  vgui::Splitter::RespaceSplitters(this: v7, flFractions);
  Child = vgui::Panel::GetChild(this: this->m_pFileBrowserSplitter, index: 0);
  v9 = vgui::Panel::GetChild(this: this->m_pFileBrowserSplitter, index: 1);
  Child->RequestFocus(this: Child, a2: 0);
  CBaseAssetPicker::CreateStandardControls(this, pParent: Child, bAllowMultiselect: false);
  CBaseAssetPicker::AutoLayoutStandardControls(this);
  v10 = (CParticleSnapshotGrid *)operator new(nSize: 0x1F4u);
  if ( v10 != nullptr )
    v11 = CParticleSnapshotGrid::CParticleSnapshotGrid(this: v10, pParent: v9, pName: "ParticleSystemPanel");
  else
    v11 = nullptr;
  this->m_pSnapshotGrid = v11;
  vgui::Panel::SetAutoResize(
    this: v11,
    pinCorner: PIN_TOPLEFT,
    resizeDir: AUTORESIZE_DOWNANDRIGHT,
    nPinOffsetX: 0,
    nPinOffsetY: 0,
    nUnpinnedCornerOffsetX: 0,
    nUnpinnedCornerOffsetY: 0);
  this->m_pSnapshotGrid->AddActionSignalTarget_2(this: this->m_pSnapshotGrid, a2: this);
  return this;
}
