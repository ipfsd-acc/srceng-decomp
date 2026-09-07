// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/bonusmapsdialog.cpp
// Functions: 34
// ============================================================

#include "game\client\cstrike15\gameui\bonusmapsdialog.h"

//------------------------------------------------------------------------------
// Address: 0x101ECF20
// Name: public: static char const __near * CBonusMapsDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBonusMapsDialog::GetPanelClassName()
{
  return "CBonusMapsDialog";
}

//------------------------------------------------------------------------------
// Address: 0x101ECF30
// Name: bool ConstructFullImagePath(char const __near *,char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl ConstructFullImagePath(const char *pCurrentPath, const char *pchImageName, char *pchImageFileName)
{
  if ( _V_strstr(s1: pchImageName, search: aTga_1) != nullptr )
  {
    if ( *pchImageName == 46 )
      V_snprintf(pDest: pchImageFileName, maxLen: 260, pFormat: "%s/%s", pCurrentPath, pchImageName);
    else
      V_snprintf(pDest: pchImageFileName, maxLen: 260, pFormat: "%s", pchImageName);
    return 1;
  }
  else
  {
    _V_strcpy(dest: pchImageFileName, src: pchImageName);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ECFA0
// Name: public: static char const __near * CBonusMapPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CBonusMapPanel::GetPanelClassName()
{
  return "CBonusMapPanel";
}

//------------------------------------------------------------------------------
// Address: 0x101ECFB0
// Name: public: void CBonusMapPanel::SetBonusMapInfo(char const __near *,struct BonusMapDescription_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBonusMapPanel::SetBonusMapInfo(
        CBonusMapPanel *this,
        const char *pCurrentPath,
        BonusMapDescription_t *map)
{
  char *szImageName; // eax
  char v5; // bl
  char szImpliedTgaName[260]; // [esp+Ch] [ebp-208h] BYREF
  char szImageFileName[260]; // [esp+110h] [ebp-104h] BYREF

  szImageName = map->szImageName;
  if ( !map->bIsFolder )
  {
    if ( *szImageName == 0 )
    {
      V_snprintf(pDest: szImpliedTgaName, maxLen: 0x104u, pFormat: "%s.tga", map->szMapFileName);
      v5 = ConstructFullImagePath(pCurrentPath, pchImageName: szImpliedTgaName, pchImageFileName: szImageFileName);
      if ( !g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: szImageFileName, a3: "MOD") )
      {
        _V_strcpy(dest: szImageFileName, src: "bonusmaps/icon_bonus_map_default");
        goto LABEL_5;
      }
      goto LABEL_11;
    }
LABEL_10:
    v5 = ConstructFullImagePath(pCurrentPath, pchImageName: map->szImageName, pchImageFileName: szImageFileName);
LABEL_11:
    if ( v5 == 0 )
      goto LABEL_5;
LABEL_12:
    CTGAImagePanel::SetTGAFilenameNonMod(this: this->m_pBonusMapTGAImage, filename: szImageFileName);
    vgui::Panel::SetSize(this: this->m_pBonusMapTGAImage, wide: 180, tall: 100);
    this->m_pBonusMapTGAImage->SetVisible(this: this->m_pBonusMapTGAImage, a2: true);
    this->m_pBonusMapImage->SetVisible(this: this->m_pBonusMapImage, a2: false);
    goto LABEL_6;
  }
  if ( *szImageName != 0 )
    goto LABEL_10;
  V_snprintf(pDest: szImageFileName, maxLen: 0x104u, pFormat: "%s/foldericon.tga", map->szFileName);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: szImageFileName, a3: "MOD") )
    goto LABEL_12;
  _V_strcpy(dest: szImageFileName, src: "bonusmaps/icon_bonus_map_folder");
LABEL_5:
  this->m_pBonusMapImage->SetImage(this: this->m_pBonusMapImage, a2: szImageFileName);
  vgui::Panel::SetSize(this: this->m_pBonusMapImage, wide: 180, tall: 100);
  this->m_pBonusMapImage->SetVisible(this: this->m_pBonusMapImage, a2: true);
  this->m_pBonusMapTGAImage->SetVisible(this: this->m_pBonusMapTGAImage, a2: false);
LABEL_6:
  this->m_pLockIcon->SetVisible(this: this->m_pLockIcon, a2: map->bLocked);
  this->m_pCompleteIcon->SetVisible(this: this->m_pCompleteIcon, a2: map->bComplete);
  this->m_pMapNameLabel->SetText(this: this->m_pMapNameLabel, a2: map->szMapName);
}

//------------------------------------------------------------------------------
// Address: 0x101ED1A0
// Name: private: virtual void CBonusMapsDialog::OnTextChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBonusMapsDialog::OnTextChanged(CBonusMapsDialog *this)
{
  this->OnControlModified(this);
}

//------------------------------------------------------------------------------
// Address: 0x101ED1B0
// Name: private: void CBonusMapsDialog::CreateBonusMapsList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBonusMapsDialog::CreateBonusMapsList(CBonusMapsDialog *this)
{
  vgui::PanelListPanel *v2; // eax
  vgui::PanelListPanel *v3; // eax
  vgui::Label *v4; // eax
  vgui::Label *v5; // eax
  vgui::ComboBox *v6; // eax

  v2 = (vgui::PanelListPanel *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v2 != nullptr )
    v3 = vgui::PanelListPanel::PanelListPanel(this: v2, parent: this, panelName: "listpanel_bonusmaps");
  else
    v3 = nullptr;
  this->m_pGameList = v3;
  vgui::PanelListPanel::SetFirstColumnWidth(this: v3, width: 0);
  v4 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v4 != nullptr )
    vgui::Label::Label(this: v4, parent: this, panelName: "FileName", text: "./");
  v5 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v5 != nullptr )
    vgui::Label::Label(this: v5, parent: this, panelName: "CommentLabel", text: prType);
  v6 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v6 != nullptr )
    this->m_pChallengeSelection = vgui::ComboBox::ComboBox(
                                    this: v6,
                                    parent: this,
                                    panelName: "ChallengeSelection",
                                    numLines: 0,
                                    allowEdit: false);
  else
    this->m_pChallengeSelection = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101ED260
// Name: public: int CBonusMapsDialog::GetSelectedChallenge(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBonusMapsDialog::GetSelectedChallenge(CBonusMapsDialog *this)
{
  KeyValues *ActiveItemUserData; // eax

  if ( !this->m_pChallengeSelection->IsEnabled(this: this->m_pChallengeSelection) )
    return -1;
  ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pChallengeSelection);
  return KeyValues::GetInt(this: ActiveItemUserData, keyName: "challenge", defaultValue: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101ED2B0
// Name: public: virtual struct vgui::PanelMessageMap __near * CBonusMapsDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBonusMapsDialog::GetMessageMap(CBonusMapsDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBonusMapsDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBonusMapsDialog::GetMessageMap'::`2'::s_pMap;
  `CBonusMapsDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBonusMapsDialog");
  `CBonusMapsDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101ED2E0
// Name: public: virtual struct PanelAnimationMap __near * CBonusMapsDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBonusMapsDialog::GetAnimMap(CBonusMapsDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CBonusMapsDialog");
}

//------------------------------------------------------------------------------
// Address: 0x101ED2F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBonusMapsDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBonusMapsDialog::GetKBMap(CBonusMapsDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBonusMapsDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBonusMapsDialog::GetKBMap'::`2'::s_pMap;
  `CBonusMapsDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBonusMapsDialog");
  `CBonusMapsDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101ED360
// Name: private: int CBonusMapsDialog::GetSelectedItemBonusMapIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBonusMapsDialog::GetSelectedItemBonusMapIndex(CBonusMapsDialog *this)
{
  vgui::Panel *SelectedPanel; // eax
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  int v4; // edi
  CBonusMapsDatabase *v5; // eax

  SelectedPanel = vgui::PanelListPanel::GetSelectedPanel(this: this->m_pGameList);
  v2 = __RTDynamicCast(
         inptr: SelectedPanel,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &CBonusMapPanel `RTTI Type Descriptor',
         isReference: 0);
  v3 = v2;
  if ( v2 != nullptr )
  {
    v4 = v2[106];
    v5 = BonusMapsDatabase();
    if ( v4 < CBonusMapsDatabase::BonusCount(this: v5) )
      return v3[106];
  }
  BonusMapsDatabase();
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x101ED3C0
// Name: private: void CBonusMapsDialog::RefreshCompletionPercentage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBonusMapsDialog::RefreshCompletionPercentage(CBonusMapsDialog *this)
{
  CBonusMapsDatabase *v2; // eax
  double CompletionPercentage; // st7
  int v4; // eax
  int v5; // ecx
  float v6; // xmm2_4
  int v7; // edx
  float v8; // xmm2_4
  int v9; // eax
  float v10; // xmm3_4
  int v11; // ecx
  float v12; // xmm0_4
  vgui::ImagePanel *m_pPercentageBar; // ecx
  int Wide; // eax
  double v15; // [esp+0h] [ebp-114h]
  char szBuff[256]; // [esp+Ch] [ebp-108h] BYREF
  float fPercentage; // [esp+10Ch] [ebp-8h]
  Color cProgressBar; // [esp+110h] [ebp-4h]

  v2 = BonusMapsDatabase();
  CompletionPercentage = CBonusMapsDatabase::GetCompletionPercentage(this: v2);
  fPercentage = CompletionPercentage;
  if ( CompletionPercentage <= 0.0 )
  {
    this->SetControlVisible(this, a2: "PercentageText", a3: false);
    this->SetControlVisible(this, a2: "CompletionText", a3: false);
    this->SetControlVisible(this, a2: "PercentageBarBackground", a3: false);
  }
  else
  {
    v15 = (float)(fPercentage * 100.0);
    if ( (float)(fPercentage * 100.0) >= 1.0 )
      V_snprintf(pDest: szBuff, maxLen: 0x100u, pFormat: "%.0f%%", v15);
    else
      V_snprintf(pDest: szBuff, maxLen: 0x100u, pFormat: "%.2f%%", v15);
    this->SetControlString_2(this, a2: "PercentageText", a3: szBuff);
    this->SetControlVisible(this, a2: "PercentageText", a3: true);
    this->SetControlVisible(this, a2: "CompletionText", a3: true);
    v4 = this->m_PercentageBarBackgroundColor._color[2];
    v5 = this->m_PercentageBarColor._color[2];
    v6 = (float)((float)this->m_PercentageBarBackgroundColor._color[1] * (float)(1.0 - fPercentage))
       + (float)((float)this->m_PercentageBarColor._color[1] * fPercentage);
    cProgressBar._color[0] = (int)(float)((float)((float)this->m_PercentageBarBackgroundColor._color[0]
                                                * (float)(1.0 - fPercentage))
                                        + (float)((float)this->m_PercentageBarColor._color[0] * fPercentage));
    v7 = (int)v6;
    v8 = (float)v4;
    v9 = this->m_PercentageBarBackgroundColor._color[3];
    v10 = (float)v5;
    v11 = this->m_PercentageBarColor._color[3];
    cProgressBar._color[1] = v7;
    v12 = (float)v11;
    m_pPercentageBar = this->m_pPercentageBar;
    cProgressBar._color[2] = (int)(float)((float)(v8 * (float)(1.0 - fPercentage)) + (float)(v10 * fPercentage));
    cProgressBar._color[3] = (int)(float)((float)((float)v9 * (float)(1.0 - fPercentage)) + (float)(v12 * fPercentage));
    vgui::ProgressBar::SetBarInset(this: (vgui::ProgressBar *)m_pPercentageBar, pixels: *(_DWORD *)&cProgressBar);
    Wide = vgui::Panel::GetWide(this: this->m_pPercentageBarBackground);
    vgui::Panel::SetWide(this: this->m_pPercentageBar, wide: (int)(float)((float)Wide * fPercentage));
    this->SetControlVisible(this, a2: "PercentageBarBackground", a3: true);
  }
  ((void (__thiscall *)(CBonusMapsDialog *, const char *))this->SetControlVisible)(a1: this, a2: "PercentageBar");
}

//------------------------------------------------------------------------------
// Address: 0x101ED5F0
// Name: public: virtual void CBonusMapsDialog::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBonusMapsDialog::ApplySchemeSettings(CBonusMapsDialog *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v3; // edi

  v3 = pScheme;
  this->m_PercentageBarBackgroundColor = (Color)0x40000000;
  this->m_PercentageBarColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, vgui::IScheme **, const char *, int))v3->GetColor)(
                                           a1: v3,
                                           a2: &pScheme,
                                           a3: "NewGame.SelectionColor",
                                           a4: -1);
  vgui::Frame::ApplySchemeSettings(this, pScheme: v3);
}

//------------------------------------------------------------------------------
// Address: 0x101ED640
// Name: private: void CBonusMapsDialog::RefreshMedalDisplay(struct BonusMapDescription_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBonusMapsDialog::RefreshMedalDisplay(CBonusMapsDialog *this, BonusMapDescription_t *pMap)
{
  int ChildIndexByName; // ebx
  int i; // edi
  vgui::Panel *Child; // eax
  KeyValues *ActiveItemUserData; // eax
  int v7; // eax
  vgui::ComboBox *m_pChallengeSelection; // ecx
  vgui::ComboBox_vtbl *v9; // edx
  int (__thiscall *GetItemCount)(vgui::ComboBox *); // eax
  int v11; // ebx
  KeyValues *ItemUserData; // eax
  int Int; // edi
  int v14; // eax
  CUtlVector<ChallengeDescription_t,CUtlMemory<ChallengeDescription_t,int> > *m_pChallenges; // ecx
  int m_Size; // ebx
  ChallengeDescription_t *m_pMemory; // edx
  int iType; // ecx
  vgui::Panel *v19; // eax
  void *v20; // edi
  vgui::ComboBox *v21; // ecx
  int (__thiscall *v22)(vgui::ComboBox *); // edx
  CUtlVector<ChallengeDescription_t,CUtlMemory<ChallengeDescription_t,int> > *v23; // ecx
  int v24; // ebx
  ChallengeDescription_t *v25; // edi
  ChallengeDescription_t *v26; // eax
  ChallengeDescription_t *v27; // edx
  ChallengeDescription_t *v28; // ecx
  ChallengeDescription_t *v29; // ebx
  vgui::Panel *ChildByName; // eax
  void *v31; // edi
  vgui::Panel *v32; // eax
  void *v33; // edi
  vgui::ILocalize_vtbl *v34; // edi
  int v35; // eax
  vgui::ILocalize_vtbl *v36; // edi
  int v37; // eax
  const char *v38; // [esp-4h] [ebp-33Ch]
  int v39; // [esp-4h] [ebp-33Ch]
  int v40; // [esp-4h] [ebp-33Ch]
  wchar_t szWideBuff[64]; // [esp+Ch] [ebp-32Ch] BYREF
  wchar_t szWideBuff2[64]; // [esp+8Ch] [ebp-2ACh] BYREF
  char szBuff[512]; // [esp+10Ch] [ebp-22Ch] BYREF
  int v44; // [esp+30Ch] [ebp-2Ch] BYREF
  int v45; // [esp+310h] [ebp-28h] BYREF
  int v46; // [esp+314h] [ebp-24h] BYREF
  int iNext; // [esp+318h] [ebp-20h] BYREF
  int iEarnedMedal; // [esp+31Ch] [ebp-1Ch] BYREF
  int iFirstChildIndex; // [esp+320h] [ebp-18h]
  int iNextMedal; // [esp+324h] [ebp-14h] BYREF
  int iBest; // [esp+328h] [ebp-10h] BYREF
  int iChallengeIndex; // [esp+32Ch] [ebp-Ch]
  int v53; // [esp+330h] [ebp-8h] BYREF
  ChallengeDescription_t *pChallengeDescription; // [esp+334h] [ebp-4h]

  ChildIndexByName = vgui::Panel::FindChildIndexByName(this, childName: "ChallengeMedalOverview00");
  for ( i = 0; i < 5; ++i )
  {
    Child = vgui::Panel::GetChild(this, index: i + ChildIndexByName);
    Child->SetVisible(this: Child, a2: false);
  }
  if ( pMap == nullptr || pMap->m_pChallenges == nullptr )
  {
    this->SetControlVisible(this, a2: "ChallengeCommentLabel", a3: false);
    this->SetControlVisible(this, a2: "ChallengeEarnedMedal", a3: false);
    this->SetControlVisible(this, a2: "ChallengeBestLabel", a3: false);
    this->SetControlVisible(this, a2: "ChallengeNextMedal", a3: false);
LABEL_48:
    this->SetControlVisible(this, a2: "ChallengeNextLabel", a3: false);
    return;
  }
  if ( !this->m_pChallengeSelection->IsEnabled(this: this->m_pChallengeSelection)
    || (ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pChallengeSelection),
        (int)(pChallengeDescription = (ChallengeDescription_t *)KeyValues::GetInt(
                                                                  this: ActiveItemUserData,
                                                                  keyName: "challenge",
                                                                  defaultValue: 0)) < 0) )
  {
    this->SetControlVisible(this, a2: "ChallengeCommentLabel", a3: false);
    this->SetControlVisible(this, a2: "ChallengeEarnedMedal", a3: false);
    this->SetControlVisible(this, a2: "ChallengeBestLabel", a3: false);
    this->SetControlVisible(this, a2: "ChallengeNextMedal", a3: false);
    this->SetControlVisible(this, a2: "ChallengeNextLabel", a3: false);
    v7 = vgui::Panel::FindChildIndexByName(this, childName: "ChallengeMedalOverview00");
    m_pChallengeSelection = this->m_pChallengeSelection;
    v9 = m_pChallengeSelection->__vftable;
    iFirstChildIndex = v7;
    GetItemCount = v9->GetItemCount;
    v11 = 0;
    iChallengeIndex = 0;
    if ( GetItemCount(this: m_pChallengeSelection) > 0 )
    {
      do
      {
        ItemUserData = vgui::ComboBox::GetItemUserData(this: this->m_pChallengeSelection, itemID: v11);
        Int = KeyValues::GetInt(this: ItemUserData, keyName: "challenge", defaultValue: 0);
        v14 = 0;
        if ( Int >= 0 )
        {
          m_pChallenges = pMap->m_pChallenges;
          m_Size = m_pChallenges->m_Size;
          pChallengeDescription = nullptr;
          if ( m_Size > 0 )
          {
            m_pMemory = m_pChallenges->m_Memory.m_pMemory;
            do
            {
              iType = m_pMemory->iType;
              if ( iType == -1 )
                iType = v14;
              if ( iType == Int )
                pChallengeDescription = m_pMemory;
              ++v14;
              ++m_pMemory;
            }
            while ( v14 < m_Size );
            if ( pChallengeDescription != nullptr )
            {
              GetChallengeMedals(pChallengeDescription, iBest: &v45, iEarnedMedal: &v53, iNext: &v44, iNextMedal: &v46);
              v38 = g_pszMedalNames[v53];
              if ( Int >= 10 )
                V_snprintf(pDest: szBuff, maxLen: 0x100u, pFormat: "medals/medal_%i_%s", Int, v38);
              else
                V_snprintf(pDest: szBuff, maxLen: 0x100u, pFormat: "medals/medal_0%i_%s", Int, v38);
            }
          }
          v19 = vgui::Panel::GetChild(this, index: iFirstChildIndex + Int);
          v20 = __RTDynamicCast(
                  inptr: v19,
                  VfDelta: 0,
                  SrcType: &vgui::Panel `RTTI Type Descriptor',
                  TargetType: &vgui::CBitmapImagePanel `RTTI Type Descriptor',
                  isReference: 0);
          (*(void (__thiscall **)(void *, int))(*(_DWORD *)v20 + 132))(a1: v20, a2: 1);
          (*(void (__thiscall **)(void *, char *, int))(*(_DWORD *)v20 + 844))(a1: v20, a2: szBuff, a3: 1);
          v11 = iChallengeIndex;
        }
        v21 = this->m_pChallengeSelection;
        v22 = v21->GetItemCount;
        iChallengeIndex = ++v11;
      }
      while ( v11 < v22(this: v21) );
    }
    return;
  }
  v23 = pMap->m_pChallenges;
  v24 = v23->m_Size;
  v25 = nullptr;
  v26 = nullptr;
  if ( v24 > 0 )
  {
    v27 = v23->m_Memory.m_pMemory;
    do
    {
      v28 = (ChallengeDescription_t *)v27->iType;
      if ( v28 == (ChallengeDescription_t *)-1 )
        v28 = v26;
      if ( v28 == pChallengeDescription )
        v25 = v27;
      v26 = (ChallengeDescription_t *)((char *)v26 + 1);
      ++v27;
    }
    while ( (int)v26 < v24 );
    if ( v25 != nullptr )
    {
      GetChallengeMedals(pChallengeDescription: v25, &iBest, &iEarnedMedal, &iNext, &iNextMedal);
      this->SetControlString_2(this, a2: "ChallengeCommentLabel", a3: v25->szComment);
      this->SetControlVisible(this, a2: "ChallengeCommentLabel", a3: true);
      v29 = pChallengeDescription;
      if ( iEarnedMedal > -1 )
      {
        if ( (int)pChallengeDescription >= 10 )
          V_snprintf(
            pDest: szBuff,
            maxLen: 0x200u,
            pFormat: "medals/medal_%i_%s",
            pChallengeDescription,
            g_pszMedalNames[iEarnedMedal]);
        else
          V_snprintf(
            pDest: szBuff,
            maxLen: 0x200u,
            pFormat: "medals/medal_0%i_%s",
            pChallengeDescription,
            g_pszMedalNames[iEarnedMedal]);
        ChildByName = vgui::Panel::FindChildByName(this, childName: "ChallengeEarnedMedal", recurseDown: false);
        v31 = __RTDynamicCast(
                inptr: ChildByName,
                VfDelta: 0,
                SrcType: &vgui::Panel `RTTI Type Descriptor',
                TargetType: &vgui::CBitmapImagePanel `RTTI Type Descriptor',
                isReference: 0);
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)v31 + 132))(a1: v31, a2: 1);
        (*(void (__thiscall **)(void *, char *, int))(*(_DWORD *)v31 + 844))(a1: v31, a2: szBuff, a3: 1);
      }
      if ( iNextMedal <= 0 )
      {
        this->SetControlVisible(this, a2: "ChallengeNextMedal", a3: false);
      }
      else
      {
        if ( (int)v29 >= 10 )
          V_snprintf(pDest: szBuff, maxLen: 0x200u, pFormat: "medals/medal_%i_%s", v29, g_pszMedalNames[iNextMedal]);
        else
          V_snprintf(pDest: szBuff, maxLen: 0x200u, pFormat: "medals/medal_0%i_%s", v29, g_pszMedalNames[iNextMedal]);
        v32 = vgui::Panel::FindChildByName(this, childName: "ChallengeNextMedal", recurseDown: false);
        v33 = __RTDynamicCast(
                inptr: v32,
                VfDelta: 0,
                SrcType: &vgui::Panel `RTTI Type Descriptor',
                TargetType: &vgui::CBitmapImagePanel `RTTI Type Descriptor',
                isReference: 0);
        (*(void (__thiscall **)(void *, int))(*(_DWORD *)v33 + 132))(a1: v33, a2: 1);
        (*(void (__thiscall **)(void *, char *, int))(*(_DWORD *)v33 + 844))(a1: v33, a2: szBuff, a3: 1);
      }
      if ( iBest == -1 )
      {
        this->SetControlVisible(this, a2: "ChallengeBestLabel", a3: false);
      }
      else
      {
        V_snprintf(pDest: szBuff, maxLen: 0x200u, pFormat: "%i", iBest);
        g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: szBuff, a3: szWideBuff2, a4: 128);
        v34 = g_pVGuiLocalize->__vftable;
        v35 = ((int (__thiscall *)(vgui::ILocalize *, const char *, int, wchar_t *))g_pVGuiLocalize->Find)(
                a1: g_pVGuiLocalize,
                a2: "#GameUI_BonusMapsBest",
                a3: 1,
                a4: szWideBuff2);
        ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v34->ConstructString_3)(
          a1: g_pVGuiLocalize,
          a2: szWideBuff,
          a3: 128,
          a4: v35);
        ((void (__thiscall *)(vgui::ILocalize *, wchar_t *, char *, int, int))g_pVGuiLocalize->ConvertUnicodeToANSI)(
          a1: g_pVGuiLocalize,
          a2: szWideBuff,
          a3: szBuff,
          a4: 512,
          a5: v39);
        this->SetControlString_2(this, a2: "ChallengeBestLabel", a3: szBuff);
        this->SetControlVisible(this, a2: "ChallengeBestLabel", a3: true);
      }
      if ( iNext != -1 )
      {
        V_snprintf(pDest: szBuff, maxLen: 0x200u, pFormat: "%i", iNext);
        g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: szBuff, a3: szWideBuff2, a4: 128);
        v36 = g_pVGuiLocalize->__vftable;
        v37 = ((int (__thiscall *)(vgui::ILocalize *, const char *, int, wchar_t *))g_pVGuiLocalize->Find)(
                a1: g_pVGuiLocalize,
                a2: "#GameUI_BonusMapsGoal",
                a3: 1,
                a4: szWideBuff2);
        ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v36->ConstructString_3)(
          a1: g_pVGuiLocalize,
          a2: szWideBuff,
          a3: 128,
          a4: v37);
        ((void (__thiscall *)(vgui::ILocalize *, wchar_t *, char *, int, int))g_pVGuiLocalize->ConvertUnicodeToANSI)(
          a1: g_pVGuiLocalize,
          a2: szWideBuff,
          a3: szBuff,
          a4: 512,
          a5: v40);
        this->SetControlString_2(this, a2: "ChallengeNextLabel", a3: szBuff);
        this->SetControlVisible(this, a2: "ChallengeNextLabel", a3: true);
        return;
      }
      goto LABEL_48;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EDC40
// Name: private: void CBonusMapsDialog::RefreshDialog(struct BonusMapDescription_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBonusMapsDialog::RefreshDialog(CBonusMapsDialog *this, BonusMapDescription_t *pMap)
{
  void (__thiscall *SetControlString_2)(vgui::EditablePanel *, const char *, const char *); // edx

  if ( pMap == nullptr
    || pMap->bLocked
    || this->m_pChallengeSelection->IsEnabled(this: this->m_pChallengeSelection)
    && CBonusMapsDialog::GetSelectedChallenge(this) == -1 )
  {
    this->SetControlEnabled(this, a2: "loadbonusmap", a3: false);
  }
  else
  {
    this->SetControlEnabled(this, a2: "loadbonusmap", a3: true);
  }
  CBonusMapsDialog::RefreshMedalDisplay(this, pMap);
  SetControlString_2 = this->SetControlString_2;
  if ( pMap != nullptr )
    SetControlString_2(this, a2: "CommentLabel", a3: pMap->szComment);
  else
    SetControlString_2(this, a2: "CommentLabel", a3: prType);
}

//------------------------------------------------------------------------------
// Address: 0x101EDCD0
// Name: private: virtual void CBonusMapsDialog::OnPanelSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBonusMapsDialog::OnPanelSelected(CBonusMapsDialog *this)
{
  vgui::IBorder *border; // edi
  BonusMapDescription_t *v3; // edi
  int v4; // ebx
  KeyValues *ActiveItemUserData; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  CUtlVector<ChallengeDescription_t,CUtlMemory<ChallengeDescription_t,int> > *m_pChallenges; // eax
  ChallengeDescription_t *v9; // edi
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  int iFoundSimilar; // [esp+Ch] [ebp-14h]
  BonusMapDescription_t *pMap; // [esp+10h] [ebp-10h]
  int iSelectedChallenge; // [esp+14h] [ebp-Ch]
  int iType; // [esp+18h] [ebp-8h]
  int v16; // [esp+1Ch] [ebp-4h]

  border = vgui::PanelListPanel::GetSelectedPanel(this: this->m_pGameList)[1]._border;
  v3 = &BonusMapsDatabase()->m_BonusMaps.m_Memory.m_pMemory[(_DWORD)border];
  pMap = v3;
  this->SetControlString_2(this, a2: "CommentLabel", a3: v3->szComment);
  v4 = 0;
  if ( v3->m_pChallenges == nullptr )
    goto LABEL_21;
  if ( this->m_pChallengeSelection->IsEnabled(this: this->m_pChallengeSelection) )
  {
    ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pChallengeSelection);
    iSelectedChallenge = KeyValues::GetInt(this: ActiveItemUserData, keyName: "challenge", defaultValue: 0);
  }
  else
  {
    iSelectedChallenge = -1;
  }
  vgui::ComboBox::RemoveAll(this: this->m_pChallengeSelection);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "ChallengeSelection", firstKey: "challenge", firstValue: -1);
  else
    v7 = nullptr;
  this->m_pChallengeSelection->AddItem_2(this: this->m_pChallengeSelection, a2: "<Select A Challenge>", a3: v7);
  m_pChallenges = v3->m_pChallenges;
  iFoundSimilar = 0;
  if ( m_pChallenges->m_Size > 0 )
  {
    v16 = 0;
    do
    {
      v9 = &m_pChallenges->m_Memory.m_pMemory[v16];
      iType = v4;
      if ( v9->iType != -1 )
        iType = v9->iType;
      v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v10 != nullptr )
        v11 = KeyValues::KeyValues(this: v10, setName: "ChallengeSelection", firstKey: "challenge", firstValue: iType);
      else
        v11 = nullptr;
      this->m_pChallengeSelection->AddItem_2(this: this->m_pChallengeSelection, a2: (const char *)v9, a3: v11);
      if ( iSelectedChallenge == v4 )
        iFoundSimilar = v4 + 1;
      m_pChallenges = pMap->m_pChallenges;
      ++v16;
      ++v4;
    }
    while ( v4 < m_pChallenges->m_Size );
    v3 = pMap;
  }
  vgui::ComboBox::ActivateItemByRow(this: this->m_pChallengeSelection, row: iFoundSimilar);
  if ( v4 > 0 )
  {
    this->m_pChallengeSelection->SetEnabled(this: this->m_pChallengeSelection, a2: true);
    this->m_pChallengeSelection->SetVisible(this: this->m_pChallengeSelection, a2: true);
    this->m_pChallengeSelection->SetNumberOfEditLines(this: this->m_pChallengeSelection, a2: v4 + 1);
    CBonusMapsDialog::RefreshDialog(this, pMap: v3);
  }
  else
  {
LABEL_21:
    this->m_pChallengeSelection->SetEnabled(this: this->m_pChallengeSelection, a2: false);
    this->m_pChallengeSelection->SetVisible(this: this->m_pChallengeSelection, a2: false);
    CBonusMapsDialog::RefreshDialog(this, pMap: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EDEC0
// Name: private: virtual void CBonusMapsDialog::OnControlModified(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBonusMapsDialog::OnControlModified(CBonusMapsDialog *this)
{
  vgui::IBorder *border; // esi
  CBonusMapsDatabase *v3; // eax

  border = vgui::PanelListPanel::GetSelectedPanel(this: this->m_pGameList)[1]._border;
  v3 = BonusMapsDatabase();
  CBonusMapsDialog::RefreshDialog(this, pMap: &v3->m_BonusMaps.m_Memory.m_pMemory[(_DWORD)border]);
}

//------------------------------------------------------------------------------
// Address: 0x101EDEF0
// Name: public: static void CBonusMapsDialog::PanelMessageFunc_OnPanelSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBonusMapsDialog::PanelMessageFunc_OnPanelSelected::InitVar(int a1@<ebp>)
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
  if ( !`CBonusMapsDialog::PanelMessageFunc_OnPanelSelected::InitVar'::`2'::bAdded )
  {
    `CBonusMapsDialog::PanelMessageFunc_OnPanelSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBonusMapsDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBonusMapsDialog");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PanelSelected";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EDF80
// Name: public: static void CBonusMapsDialog::PanelMessageFunc_OnControlModified::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBonusMapsDialog::PanelMessageFunc_OnControlModified::InitVar(int a1@<ebp>)
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
  if ( !`CBonusMapsDialog::PanelMessageFunc_OnControlModified::InitVar'::`2'::bAdded )
  {
    `CBonusMapsDialog::PanelMessageFunc_OnControlModified::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBonusMapsDialog::`vcall'{1120,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBonusMapsDialog");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ControlModified";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EE010
// Name: public: static void CBonusMapsDialog::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBonusMapsDialog::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
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
  if ( !`CBonusMapsDialog::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CBonusMapsDialog::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBonusMapsDialog::`vcall'{1124,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBonusMapsDialog");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "TextChanged";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EE0A0
// Name: public: static void CBonusMapsDialog::PanelMessageFunc_OnFileSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBonusMapsDialog::PanelMessageFunc_OnFileSelected::InitVar(int a1@<ebp>)
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
  if ( !`CBonusMapsDialog::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded )
  {
    `CBonusMapsDialog::PanelMessageFunc_OnFileSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1128,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBonusMapsDialog");
    v2 = _mm_load_si128(&v5);
    *(_QWORD *)&v4.m[2][0] = 0x100000001LL;
    memset(&v4.m[2][3], 0, 20);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FileSelected";
    *(__m128i *)&v4.m[1][0] = v2;
    LODWORD(v4.m[2][2]) = "fullpath";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EE140
// Name: public: static void CBonusMapPanel::PanelMessageFunc_OnPanelSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CBonusMapPanel::PanelMessageFunc_OnPanelSelected::InitVar(int a1@<ebp>)
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
  if ( !`CBonusMapPanel::PanelMessageFunc_OnPanelSelected::InitVar'::`2'::bAdded )
  {
    `CBonusMapPanel::PanelMessageFunc_OnPanelSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CSaveGamePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CBonusMapPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "PanelSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "state";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EE1E0
// Name: public: CBonusMapPanel::CBonusMapPanel(class vgui::PanelListPanel __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CBonusMapPanel *__thiscall CBonusMapPanel::CBonusMapPanel(
        CBonusMapPanel *this,
        vgui::PanelListPanel *parent,
        const char *name,
        int bonusMapListItemID)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  int v8; // edx
  vgui::PanelListPanel *v9; // eax
  CTGAImagePanel *v10; // eax
  CTGAImagePanel *v11; // eax
  vgui::ImagePanel *v12; // eax
  vgui::ImagePanel *v13; // edi
  vgui::ImagePanel *v14; // eax
  vgui::ImagePanel *v15; // edi
  vgui::Label *v16; // eax
  vgui::Label *v17; // eax
  vgui::ImagePanel *v18; // eax
  vgui::ImagePanel *v19; // eax
  vgui::ImagePanel *v20; // eax
  vgui::ImagePanel *v21; // eax
  CMouseMessageForwardingPanel *v22; // eax
  CMouseMessageForwardingPanel *v23; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent, panelName: name);
  this->__vftable = (CBonusMapPanel_vtbl *)&CBonusMapPanel::`vftable';
  if ( `CBonusMapPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CBonusMapPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CBonusMapPanel");
    v5->pfnClassName = CBonusMapPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CBonusMapPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBonusMapPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CBonusMapPanel");
    v6->pfnClassName = CBonusMapPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CBonusMapPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBonusMapPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CBonusMapPanel");
    v7->pfnClassName = CBonusMapPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CBonusMapPanel::PanelMessageFunc_OnPanelSelected::InitVar(a1: (int)&savedregs);
  v8 = bonusMapListItemID;
  v9 = parent;
  this->m_TextColor = 0;
  this->m_FillColor = 0;
  this->m_SelectedColor = 0;
  this->m_iBonusMapListItemID = v8;
  this->m_pParent = v9;
  v10 = (CTGAImagePanel *)MemAlloc_Alloc(nSize: 0x184u);
  if ( v10 != nullptr )
    v11 = CTGAImagePanel::CTGAImagePanel(this: v10, parent: this, name: "BonusMapTGAImage");
  else
    v11 = nullptr;
  this->m_pBonusMapTGAImage = v11;
  v12 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v12 != nullptr )
    v13 = vgui::ImagePanel::ImagePanel(this: v12, parent: this, name: "BonusMapImage");
  else
    v13 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v13);
  this->m_pBonusMapImage = v13;
  v14 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v14 != nullptr )
    v15 = vgui::ImagePanel::ImagePanel(this: v14, parent: this, name: "BonusMapScreenshotBackground");
  else
    v15 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v15);
  this->m_pBonusMapScreenshotBackground = v15;
  v16 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v16 != nullptr )
    v17 = vgui::Label::Label(this: v16, parent: this, panelName: "MapNameLabel", text: prType);
  else
    v17 = nullptr;
  this->m_pMapNameLabel = v17;
  v18 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v18 != nullptr )
    v19 = vgui::ImagePanel::ImagePanel(this: v18, parent: this, name: "LockIcon");
  else
    v19 = nullptr;
  this->m_pLockIcon = v19;
  v20 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v20 != nullptr )
    v21 = vgui::ImagePanel::ImagePanel(this: v20, parent: this, name: "CompleteIcon");
  else
    v21 = nullptr;
  this->m_pCompleteIcon = v21;
  v22 = (CMouseMessageForwardingPanel *)MemAlloc_Alloc(nSize: 0x150u);
  if ( v22 != nullptr )
    v23 = CMouseMessageForwardingPanel::CMouseMessageForwardingPanel(this: v22, parent: this, name: nullptr);
  else
    v23 = nullptr;
  vgui::Panel::SetZPos(this: v23, z: 2);
  vgui::Panel::SetSize(this, wide: 200, tall: 140);
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "resource/BonusMapPanel.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  this->m_FillColor = *vgui::ImagePanel::GetFillColor(
                         this: this->m_pBonusMapScreenshotBackground,
                         result: (Color *)&parent);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101EE430
// Name: public: virtual void CBonusMapPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBonusMapPanel::OnMouseDoublePressed(CBonusMapPanel *this, ButtonCode_t code)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  CBonusMapPanel_vtbl *v5; // edi
  int v6; // eax

  this->OnMousePressed(this, a2: code);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "Command", firstKey: "command", firstValue: "loadbonusmap");
  else
    v4 = nullptr;
  v5 = this->__vftable;
  v6 = ((int (__thiscall *)(vgui::PanelListPanel *, KeyValues *, _DWORD))this->m_pParent->GetParent)(
         a1: this->m_pParent,
         a2: v4,
         a3: 0);
  ((void (__thiscall *)(CBonusMapPanel *, int))v5->PostMessage)(a1: this, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x101EE4A0
// Name: public: virtual struct vgui::PanelMessageMap __near * CBonusMapPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CBonusMapPanel::GetMessageMap(CBonusMapPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CBonusMapPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CBonusMapPanel::GetMessageMap'::`2'::s_pMap;
  `CBonusMapPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CBonusMapPanel");
  `CBonusMapPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EE4D0
// Name: public: virtual struct PanelAnimationMap __near * CBonusMapPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CBonusMapPanel::GetAnimMap(CBonusMapPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CBonusMapPanel");
}

//------------------------------------------------------------------------------
// Address: 0x101EE4E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CBonusMapPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CBonusMapPanel::GetKBMap(CBonusMapPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CBonusMapPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CBonusMapPanel::GetKBMap'::`2'::s_pMap;
  `CBonusMapPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CBonusMapPanel");
  `CBonusMapPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EE510
// Name: public: virtual void CBonusMapPanel::OnPanelSelected(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBonusMapPanel::OnPanelSelected(CBonusMapPanel *this, int state)
{
  vgui::ImagePanel *m_pBonusMapScreenshotBackground; // ecx
  Color m_TextColor; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  CBonusMapPanel_vtbl *v7; // edi
  int v8; // eax

  m_pBonusMapScreenshotBackground = this->m_pBonusMapScreenshotBackground;
  if ( state != 0 )
  {
    vgui::ProgressBar::SetBarInset(
      this: (vgui::ProgressBar *)m_pBonusMapScreenshotBackground,
      pixels: *(_DWORD *)&this->m_SelectedColor);
    m_TextColor = (Color)-16777216;
  }
  else
  {
    vgui::ProgressBar::SetBarInset(
      this: (vgui::ProgressBar *)m_pBonusMapScreenshotBackground,
      pixels: *(_DWORD *)&this->m_FillColor);
    m_TextColor = this->m_TextColor;
  }
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pMapNameLabel->SetFgColor)(a1: this->m_pMapNameLabel, a2: m_TextColor);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "PanelSelected");
  else
    v6 = nullptr;
  v7 = this->__vftable;
  v8 = ((int (__thiscall *)(vgui::PanelListPanel *, KeyValues *, _DWORD))this->m_pParent->GetVParent)(
         a1: this->m_pParent,
         a2: v6,
         a3: 0);
  ((void (__thiscall *)(CBonusMapPanel *, int))v7->PostMessage_2)(a1: this, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x101EE5B0
// Name: public: virtual void CBonusMapPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBonusMapPanel::ApplySchemeSettings(CBonusMapPanel *this, int pScheme)
{
  vgui::IScheme *v2; // esi
  Color v4; // ecx

  v2 = (vgui::IScheme *)pScheme;
  v4 = *(Color *)(*(int (__thiscall **)(int, int *, const char *, int))(*(_DWORD *)pScheme + 20))(
                   a1: pScheme,
                   a2: &pScheme,
                   a3: "NewGame.TextColor",
                   a4: -1);
  pScheme = -1;
  this->m_TextColor = v4;
  this->m_SelectedColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, int *, const char *, int))v2->GetColor)(
                                      a1: v2,
                                      a2: &pScheme,
                                      a3: "NewGame.SelectionColor",
                                      a4: -1);
  vgui::Panel::ApplySchemeSettings(this, pScheme: (int)v2);
}

//------------------------------------------------------------------------------
// Address: 0x101EE650
// Name: private: void CBonusMapsDialog::BuildMapsList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBonusMapsDialog::BuildMapsList(CBonusMapsDialog *this)
{
  CMoveHelperClient *v2; // eax
  CBonusMapsDatabase *v3; // eax
  CBonusMapsDatabase *v4; // eax
  bool v5; // al
  bool v6; // bl
  CBonusMapsDatabase *v7; // eax
  CBonusMapsDatabase *v8; // eax
  CBonusMapPanel *v9; // eax
  CBonusMapPanel *v10; // ebx
  BonusMapDescription_t *v11; // edi
  CBonusMapsDatabase *v12; // eax
  vgui::Label *v13; // eax
  vgui::Label *v14; // edi
  char szDisplayPath[260]; // [esp+Ch] [ebp-110h] BYREF
  int iMapIndex; // [esp+110h] [ebp-Ch]
  int v17; // [esp+114h] [ebp-8h]
  int bIsRoot; // [esp+118h] [ebp-4h]

  this->m_pGameList->DeleteAllItems(this: this->m_pGameList);
  v2 = (CMoveHelperClient *)BonusMapsDatabase();
  CBonusMapsDatabase::ClearBonusMapsList(this: v2);
  v3 = BonusMapsDatabase();
  CBonusMapsDatabase::ScanBonusMaps(this: v3);
  v4 = BonusMapsDatabase();
  v5 = _V_strcmp(s1: v4->m_szCurrentPath, s2: ".") == 0;
  v6 = !v5;
  LOBYTE(bIsRoot) = v5;
  this->SetControlEnabled(this, a2: "Back", a3: !v5);
  this->SetControlVisible(this, a2: "Back", a3: v6);
  this->SetControlEnabled(this, a2: "ImportBonusMaps", a3: bIsRoot);
  this->SetControlVisible(this, a2: "ImportBonusMaps", a3: bIsRoot);
  v7 = BonusMapsDatabase();
  V_snprintf(pDest: szDisplayPath, maxLen: 0x104u, pFormat: "%s/", v7->m_szCurrentPath);
  this->SetControlString_2(this, a2: "FileName", a3: szDisplayPath);
  this->SetControlString_2(this, a2: "CommentLabel", a3: prType);
  v8 = BonusMapsDatabase();
  bIsRoot = CBonusMapsDatabase::BonusCount(this: v8);
  iMapIndex = 0;
  if ( bIsRoot <= 0 )
    goto LABEL_9;
  v17 = 0;
  do
  {
    if ( v17 >= 115712 )
      break;
    v9 = (CBonusMapPanel *)MemAlloc_Alloc(nSize: 0x1ACu);
    v10 = v9 != nullptr
        ? CBonusMapPanel::CBonusMapPanel(
            this: v9,
            parent: this->m_pGameList,
            name: "BonusMapPanel",
            bonusMapListItemID: iMapIndex)
        : nullptr;
    v11 = &BonusMapsDatabase()->m_BonusMaps.m_Memory.m_pMemory[v17 / 0x388u];
    v12 = BonusMapsDatabase();
    CBonusMapPanel::SetBonusMapInfo(this: v10, pCurrentPath: v12->m_szCurrentPath, map: v11);
    this->m_pGameList->AddItem(this: this->m_pGameList, a2: nullptr, a3: v10);
    v17 += 904;
    ++iMapIndex;
  }
  while ( iMapIndex < bIsRoot );
  if ( bIsRoot > 0 )
  {
    vgui::PanelListPanel::SetNumColumns(this: this->m_pGameList, iNumColumns: 3);
  }
  else
  {
LABEL_9:
    v13 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
    if ( v13 != nullptr )
      v14 = vgui::Label::Label(
              this: v13,
              parent: this->m_pGameList,
              panelName: "NoBonusMapsLabel",
              text: "#GameUI_NoBonusMapsToDisplay");
    else
      v14 = nullptr;
    vgui::Panel::MakeReadyForUse(this: v14);
    v14->SetTextColorState(this: v14, a2: CS_DULL);
    this->m_pGameList->AddItem(this: this->m_pGameList, a2: nullptr, a3: v14);
    vgui::PanelListPanel::SetNumColumns(this: this->m_pGameList, iNumColumns: 1);
  }
  CBonusMapsDialog::RefreshCompletionPercentage(this);
  this->SetControlEnabled(this, a2: "loadbonusmap", a3: false);
  this->m_pChallengeSelection->SetEnabled(this: this->m_pChallengeSelection, a2: false);
  this->m_pChallengeSelection->SetVisible(this: this->m_pChallengeSelection, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x101EE8A0
// Name: public: virtual void CBonusMapsDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBonusMapsDialog::OnCommand(CBonusMapsDialog *this, const char *command)
{
  int SelectedItemBonusMapIndex; // edi
  CBonusMapsDatabase *v4; // eax
  BonusMapDescription_t *v5; // edi
  CBonusMapsDatabase *v6; // eax
  int SelectedChallenge; // eax
  int v8; // esi
  int v9; // esi
  ChallengeDescription_t *m_pMemory; // ecx
  int iGold; // edx
  int iSilver; // eax
  int szName; // esi
  CBonusMapsDatabase *v14; // eax
  CBonusMapsDatabase *v15; // eax
  CBonusMapsDatabase *v16; // esi
  CBonusMapsDatabase *v17; // ebx
  unsigned int v18; // eax
  const char *v19; // eax
  const char *v20; // esi
  unsigned int v21; // eax
  const char *v22; // eax
  CBonusMapsDatabase *v23; // eax
  KeyValues *v24; // eax
  KeyValues *v25; // eax
  vgui::FileOpenDialog *v26; // eax
  vgui::FileOpenDialog *v27; // eax
  int v28; // [esp-Ch] [ebp-114h]
  int v29; // [esp-8h] [ebp-110h]
  int v30; // [esp-4h] [ebp-10Ch]
  char sz[256]; // [esp+8h] [ebp-100h] BYREF

  if ( _V_stricmp(s1: command, s2: "loadbonusmap") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "back") != 0 )
    {
      if ( _V_stricmp(s1: command, s2: "ImportBonusMaps") != 0 )
      {
        vgui::Frame::OnCommand(this, command);
      }
      else
      {
        if ( this->m_hImportBonusMapsDialog == nullptr )
        {
          v26 = (vgui::FileOpenDialog *)MemAlloc_Alloc(nSize: 0x6B0u);
          if ( v26 != nullptr )
            v27 = vgui::FileOpenDialog::FileOpenDialog(
                    this: v26,
                    parent: nullptr,
                    title: "#GameUI_ImportBonusMaps",
                    bOpenOnly: true,
                    pContextKeyValues: nullptr);
          else
            v27 = nullptr;
          this->m_hImportBonusMapsDialog = v27;
          vgui::FileOpenDialog::AddFilter(
            this: v27,
            filter: "*.bmz",
            filterName: "#GameUI_BMZ_Files",
            bActive: true,
            pFilterInfo: nullptr);
          this->m_hImportBonusMapsDialog->AddActionSignalTarget_2(this: this->m_hImportBonusMapsDialog, a2: this);
        }
        vgui::FileOpenDialog::DoModal(this: this->m_hImportBonusMapsDialog, bUnused: false);
        this->m_hImportBonusMapsDialog->Activate(this: this->m_hImportBonusMapsDialog);
      }
    }
    else
    {
      v23 = BonusMapsDatabase();
      CBonusMapsDatabase::BackPath(this: v23);
      CBonusMapsDialog::BuildMapsList(this);
      vgui::ComboBox::RemoveAll(this: this->m_pChallengeSelection);
      v24 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v24 != nullptr )
        v25 = KeyValues::KeyValues(this: v24, setName: "ChallengeSelection", firstKey: "challenge", firstValue: -1);
      else
        v25 = nullptr;
      this->m_pChallengeSelection->AddItem_2(this: this->m_pChallengeSelection, a2: "<Select A Challenge>", a3: v25);
      this->SetControlEnabled(this, a2: "loadbonusmap", a3: false);
      CBonusMapsDialog::RefreshMedalDisplay(this, pMap: nullptr);
      this->SetControlString_2(this, a2: "CommentLabel", a3: prType);
      vgui::PanelListPanel::MoveScrollBarToTop(this: this->m_pGameList);
    }
  }
  else
  {
    SelectedItemBonusMapIndex = CBonusMapsDialog::GetSelectedItemBonusMapIndex(this);
    v4 = BonusMapsDatabase();
    if ( SelectedItemBonusMapIndex >= 0 && SelectedItemBonusMapIndex < v4->m_BonusMaps.m_Size )
    {
      v5 = &BonusMapsDatabase()->m_BonusMaps.m_Memory.m_pMemory[SelectedItemBonusMapIndex];
      if ( !v5->bLocked
        && (!this->m_pChallengeSelection->IsEnabled(this: this->m_pChallengeSelection)
         || CBonusMapsDialog::GetSelectedChallenge(this) != -1)
        && v5 != (BonusMapDescription_t *)-1
        && v5->szShortName[0] != 0 )
      {
        if ( v5->bIsFolder )
        {
          v6 = BonusMapsDatabase();
          CBonusMapsDatabase::AppendPath(this: v6, pchAppend: v5->szShortName);
          CBonusMapsDialog::BuildMapsList(this);
          vgui::PanelListPanel::MoveScrollBarToTop(this: this->m_pGameList);
        }
        else
        {
          SelectedChallenge = CBonusMapsDialog::GetSelectedChallenge(this);
          v8 = SelectedChallenge + 1;
          if ( SelectedChallenge + 1 > 0 )
          {
            V_snprintf(pDest: sz, maxLen: 0x100u, pFormat: "sv_bonus_challenge %i\n", SelectedChallenge + 1);
            engine->ClientCmd_Unrestricted(this: engine, a2: sz);
            v9 = v8;
            m_pMemory = v5->m_pChallenges->m_Memory.m_pMemory;
            iGold = m_pMemory[v9 - 1].iGold;
            iSilver = m_pMemory[v9 - 1].iSilver;
            szName = (int)m_pMemory[v9 - 1].szName;
            v30 = iGold;
            v29 = iSilver;
            v28 = *(_DWORD *)(szName + 292);
            v14 = BonusMapsDatabase();
            CBonusMapsDatabase::SetCurrentChallengeObjectives(this: v14, iBronze: v28, iSilver: v29, iGold: v30);
            v15 = BonusMapsDatabase();
            CBonusMapsDatabase::SetCurrentChallengeNames(
              this: v15,
              pchFileName: v5->szFileName,
              pchMapName: v5->szMapName,
              pchChallengeName: (const char *)szName);
          }
          if ( v5->szMapFileName[0] == 46 )
          {
            v16 = BonusMapsDatabase();
            v17 = BonusMapsDatabase();
            v18 = _V_strlen(str: v16->m_szCurrentPath);
            v19 = V_strnchr(pStr: v17->m_szCurrentPath, c: 47, n: v18);
            v20 = v19;
            if ( v19 != nullptr )
            {
              v21 = _V_strlen(str: v19);
              v22 = V_strnchr(pStr: v20 + 1, c: 47, n: v21);
              if ( v22 != nullptr )
                V_snprintf(pDest: sz, maxLen: 0x100u, pFormat: "map %s/%s\n", v22 + 1, &v5->szMapFileName[2]);
            }
          }
          else
          {
            V_snprintf(pDest: sz, maxLen: 0x100u, pFormat: "map %s\n", v5->szMapFileName);
          }
          engine->ClientCmd_Unrestricted(this: engine, a2: sz);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EEC00
// Name: public: CBonusMapsDialog::CBonusMapsDialog(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CBonusMapsDialog *__thiscall CBonusMapsDialog::CBonusMapsDialog(CBonusMapsDialog *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  CBonusMapsDatabase *v6; // eax
  vgui::Button *v7; // eax
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  vgui::ImagePanel *v10; // eax
  vgui::ImagePanel *v11; // edi
  vgui::ImagePanel *v12; // eax
  vgui::ImagePanel *v13; // edi
  CCStrike15BasePanel *v14; // eax
  CBonusMapsDatabase *v15; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: "BonusMapsDialog", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CBonusMapsDialog_vtbl *)&CBonusMapsDialog::`vftable';
  if ( `CBonusMapsDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CBonusMapsDialog::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CBonusMapsDialog");
    v3->pfnClassName = CBonusMapsDialog::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CBonusMapsDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CBonusMapsDialog::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CBonusMapsDialog");
    v4->pfnClassName = CBonusMapsDialog::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CBonusMapsDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CBonusMapsDialog::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CBonusMapsDialog");
    v5->pfnClassName = CBonusMapsDialog::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CBonusMapsDialog::PanelMessageFunc_OnPanelSelected::InitVar(a1: (int)&savedregs);
  CBonusMapsDialog::PanelMessageFunc_OnControlModified::InitVar(a1: (int)&savedregs);
  CBonusMapsDialog::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  CBonusMapsDialog::PanelMessageFunc_OnFileSelected::InitVar(a1: (int)&savedregs);
  this->m_PercentageBarBackgroundColor = 0;
  this->m_PercentageBarColor = 0;
  g_pBonusMapsDialog = this;
  this->m_hImportBonusMapsDialog = nullptr;
  v6 = BonusMapsDatabase();
  CBonusMapsDatabase::RootPath(this: v6);
  CBonusMapsDialog::CreateBonusMapsList(this);
  CBonusMapsDialog::BuildMapsList(this);
  v7 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v7 != nullptr )
    vgui::Button::Button(
      this: v7,
      parent: this,
      panelName: "loadbonusmap",
      text: prType,
      pActionSignalTarget: nullptr,
      pCmd: nullptr);
  vgui::EditablePanel::SetControlEnabled(this, controlName: "loadbonusmap", enabled: false);
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Frame::SetSizeable(this, state: false);
  vgui::Frame::SetTitle(this, title: "#GameUI_BonusMaps", surfaceTitle: true);
  v8 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v8 != nullptr )
    v9 = vgui::Button::Button(
           this: v8,
           parent: this,
           panelName: "Cancel",
           text: "#GameUI_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v9 = nullptr;
  v9->SetCommand(this: v9, a2: "Close");
  v10 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v10 != nullptr )
    v11 = vgui::ImagePanel::ImagePanel(this: v10, parent: this, name: "PercentageBarBackground");
  else
    v11 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v11);
  this->m_pPercentageBarBackground = v11;
  v12 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v12 != nullptr )
    v13 = vgui::ImagePanel::ImagePanel(this: v12, parent: this, name: "PercentageBar");
  else
    v13 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v13);
  this->m_pPercentageBar = v13;
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "resource/BonusMapsDialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  v14 = BasePanel();
  if ( v14 != nullptr )
    CBaseModPanel::SetMenuItemBlinkingState(this: v14, itemName: "OpenBonusMapsDialog", state: false);
  v15 = BonusMapsDatabase();
  CBonusMapsDatabase::SetBlink(this: v15, bState: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101EEE30
// Name: private: bool CBonusMapsDialog::ImportZippedBonusMaps(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBonusMapsDialog::ImportZippedBonusMaps(CBonusMapsDialog *this, const char *pchZippedFileName)
{
  const char *v2; // eax
  unsigned int v3; // edi
  int v4; // esi
  char szOutFilename[512]; // [esp+0h] [ebp-204h] BYREF
  CBonusMapsDialog *v7; // [esp+200h] [ebp-4h]

  v7 = this;
  v2 = _V_strrchr(s: pchZippedFileName, c: 92);
  if ( v2 != nullptr )
  {
    V_snprintf(pDest: szOutFilename, maxLen: 0x200u, pFormat: "maps%s", v2);
    V_StripExtension(in: szOutFilename, out: szOutFilename, outSize: 512);
    v3 = _V_strlen(str: szOutFilename);
    v4 = 1;
    if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: szOutFilename, a3: "MOD") )
    {
      while ( ++v4 <= 99 )
      {
        szOutFilename[v3] = 0;
        V_snprintf(pDest: szOutFilename, maxLen: 0x200u, pFormat: "%s%02i", szOutFilename, v4);
        if ( !g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: szOutFilename, a3: "MOD") )
          goto LABEL_5;
      }
    }
    else
    {
LABEL_5:
      if ( g_pFullFileSystem->UnzipFile(
             this: &g_pFullFileSystem->IBaseFileSystem,
             a2: pchZippedFileName,
             a3: "MOD",
             a4: szOutFilename) )
      {
        CBonusMapsDialog::BuildMapsList(this: v7);
      }
    }
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x101EEF40
// Name: private: virtual void CBonusMapsDialog::OnFileSelected(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBonusMapsDialog::OnFileSelected(CBonusMapsDialog *this, const char *fullpath)
{
  if ( fullpath != nullptr && *fullpath != 0 )
  {
    g_pVGuiSurface->SetCursor(this: g_pVGuiSurface, a2: 4u);
    CBonusMapsDialog::ImportZippedBonusMaps(this, pchZippedFileName: fullpath);
    g_pVGuiSurface->SetCursor(this: g_pVGuiSurface, a2: 0);
  }
}
