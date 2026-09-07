// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/newgamedialog.cpp
// Functions: 41
// ============================================================

#include "game\client\cstrike15\gameui\newgamedialog.h"

//------------------------------------------------------------------------------
// Address: 0x101F16A0
// Name: public: static char const __near * CNewGameDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CNewGameDialog::GetPanelClassName()
{
  return "CNewGameDialog";
}

//------------------------------------------------------------------------------
// Address: 0x101F16B0
// Name: ChapterSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl ChapterSortFunc(const char *elem1, const char *elem2)
{
  int v2; // esi
  int v4; // esi

  if ( (_S1_4 & 1) == 0 )
  {
    _S1_4 |= 1u;
    chapterlen = 7;
  }
  v2 = atoi(nptr: &elem1[chapterlen]);
  if ( v2 > atoi(nptr: &elem2[chapterlen]) )
    return 1;
  v4 = atoi(nptr: &elem1[chapterlen]);
  if ( v4 < atoi(nptr: &elem2[chapterlen]) )
    return -1;
  if ( strlen(elem1) > strlen(elem2) )
    return 1;
  if ( strlen(elem1) < strlen(elem2) )
    return -1;
  else
    return strcmp(elem1, elem2);
}

//------------------------------------------------------------------------------
// Address: 0x101F17B0
// Name: public: static char const __near * CSelectionOverlayPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSelectionOverlayPanel::GetPanelClassName()
{
  return "CSelectionOverlayPanel";
}

//------------------------------------------------------------------------------
// Address: 0x101F17C0
// Name: public: static char const __near * CGameChapterPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CGameChapterPanel::GetPanelClassName()
{
  return "CGameChapterPanel";
}

//------------------------------------------------------------------------------
// Address: 0x101F17D0
// Name: public: virtual void CNewGameDialog::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewGameDialog::OnClose(CNewGameDialog *this)
{
  CGameUI *v2; // eax
  CCStrike15BasePanel *v3; // eax
  CBonusMapsDatabase *v4; // eax

  v2 = GameUI();
  if ( CGameUI::IsConsoleUI(this: v2) && !this->m_bMapStarting )
  {
    v3 = BasePanel();
    CBaseModPanel::RunCloseAnimation(this: v3, animName: "CloseNewGameDialog_OpenMainMenu");
    v4 = BonusMapsDatabase();
    CBonusMapsDatabase::WriteSaveData(this: v4);
  }
  vgui::Frame::OnClose(this);
}

//------------------------------------------------------------------------------
// Address: 0x101F1820
// Name: public: virtual void CNewGameDialog::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewGameDialog::PaintBackground(CNewGameDialog *this)
{
  CGameUI *v2; // eax
  vgui::Label *v3; // ecx
  int v4; // esi
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // edx
  int titleX; // [esp+10h] [ebp-1Ch] BYREF
  int titleWide; // [esp+14h] [ebp-18h] BYREF
  int titleY; // [esp+18h] [ebp-14h] BYREF
  int wide; // [esp+1Ch] [ebp-10h] BYREF
  int tall; // [esp+20h] [ebp-Ch] BYREF
  Color col; // [esp+24h] [ebp-8h] BYREF
  int titleTall; // [esp+28h] [ebp-4h] BYREF

  v2 = GameUI();
  if ( CGameUI::IsConsoleUI(this: v2) )
  {
    vgui::Panel::GetSize(this, &wide, &tall);
    this->GetBgColor(this, result: &col);
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))this->DrawBox)(
      a1: this,
      a2: 0,
      a3: 0,
      a4: wide,
      a5: tall,
      a6: col,
      a7: 1065353216,
      a8: 0);
    v3 = this->m_pChapterTitleLabels[0];
    if ( v3 != nullptr )
    {
      vgui::Panel::GetBounds(this: v3, x: &titleX, y: &titleY, wide: &titleWide, tall: &titleTall);
      v4 = titleTall + titleY;
    }
    else
    {
      v4 = 8;
    }
    titleTall = (unsigned __int8)(int)(float)((float)col._color[0] * 0.69999999);
    BYTE1(titleTall) = (int)(float)((float)col._color[1] * 0.69999999);
    BYTE2(titleTall) = (int)(float)((float)col._color[2] * 0.69999999);
    DrawSetColor = g_pVGuiSurface->DrawSetColor;
    HIBYTE(titleTall) = col._color[3];
    ((void (__thiscall *)(vgui::ISurface *, int))DrawSetColor)(a1: g_pVGuiSurface, a2: titleTall);
    g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 8, a3: v4, a4: wide - 8, a5: tall - 8);
  }
  else
  {
    vgui::Frame::PaintBackground(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F1950
// Name: public: CSelectionOverlayPanel::CSelectionOverlayPanel(class vgui::Panel __near *,class CNewGameDialog __near *,int)
// Source: json
//------------------------------------------------------------------------------
CSelectionOverlayPanel *__thiscall CSelectionOverlayPanel::CSelectionOverlayPanel(
        CSelectionOverlayPanel *this,
        vgui::Panel *parent,
        CNewGameDialog *selectionTarget,
        int chapterIndex)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::Panel::Panel(this, parent, panelName: nullptr);
  this->__vftable = (CSelectionOverlayPanel_vtbl *)&CSelectionOverlayPanel::`vftable';
  if ( `CSelectionOverlayPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CSelectionOverlayPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CSelectionOverlayPanel");
    v5->pfnClassName = CSelectionOverlayPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `CSelectionOverlayPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSelectionOverlayPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CSelectionOverlayPanel");
    v6->pfnClassName = CSelectionOverlayPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `CSelectionOverlayPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSelectionOverlayPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CSelectionOverlayPanel");
    v7->pfnClassName = CSelectionOverlayPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  this->m_iChapterIndex = chapterIndex;
  this->m_pSelectionTarget = selectionTarget;
  vgui::Panel::SetPaintEnabled(this, state: false);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F1A30
// Name: public: virtual void CSelectionOverlayPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectionOverlayPanel::OnMouseDoublePressed(CSelectionOverlayPanel *this, ButtonCode_t code)
{
  vgui::Panel *v3; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  this->OnMousePressed(this, a2: code);
  v3 = this->GetParent(this);
  if ( v3->IsEnabled(this: v3) )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "Command", firstKey: "command", firstValue: "play");
    else
      v5 = nullptr;
    ((void (__thiscall *)(CSelectionOverlayPanel *, CNewGameDialog *, KeyValues *, _DWORD))this->PostMessage)(
      a1: this,
      a2: this->m_pSelectionTarget,
      a3: v5,
      a4: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F1AB0
// Name: public: virtual struct vgui::PanelMessageMap __near * CSelectionOverlayPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSelectionOverlayPanel::GetMessageMap(CSelectionOverlayPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSelectionOverlayPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSelectionOverlayPanel::GetMessageMap'::`2'::s_pMap;
  `CSelectionOverlayPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSelectionOverlayPanel");
  `CSelectionOverlayPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F1AE0
// Name: public: virtual struct PanelAnimationMap __near * CSelectionOverlayPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSelectionOverlayPanel::GetAnimMap(CSelectionOverlayPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CSelectionOverlayPanel");
}

//------------------------------------------------------------------------------
// Address: 0x101F1AF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSelectionOverlayPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSelectionOverlayPanel::GetKBMap(CSelectionOverlayPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSelectionOverlayPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSelectionOverlayPanel::GetKBMap'::`2'::s_pMap;
  `CSelectionOverlayPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSelectionOverlayPanel");
  `CSelectionOverlayPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F1B20
// Name: public: CGameChapterPanel::CGameChapterPanel(class CNewGameDialog __near *,char const __near *,char const __near *,int,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CGameChapterPanel *__thiscall CGameChapterPanel::CGameChapterPanel(
        CGameChapterPanel *this,
        CNewGameDialog *parent,
        const char *name,
        const char *chapterName,
        int chapterIndex,
        char *chapterNumber,
        char *chapterConfigFile,
        bool bCommentary)
{
  vgui::PanelMessageMap *v9; // edi
  PanelAnimationMap *v10; // edi
  vgui::PanelKeyBindingMap *v11; // edi
  char *v12; // edx
  vgui::ImagePanel *v13; // edi
  const char *v14; // ebx
  vgui::ImagePanel *v15; // eax
  vgui::ImagePanel *v16; // eax
  vgui::ImagePanel *v17; // edi
  const wchar_t *v18; // edi
  CModInfo *v19; // eax
  vgui::Label *v20; // eax
  vgui::Label *v21; // eax
  vgui::Label *v22; // eax
  vgui::Label *v23; // eax
  vgui::Label *v24; // eax
  vgui::Label *v25; // eax
  vgui::Label *v26; // eax
  _BYTE *v27; // eax
  CGameUI *v28; // eax
  int Tall; // eax
  int Wide; // eax
  CSelectionOverlayPanel *v31; // eax
  CSelectionOverlayPanel *v32; // edi
  int v33; // eax
  const char *v35; // [esp-4h] [ebp-398h]
  int v36; // [esp-4h] [ebp-398h]
  wchar_t w_szStrTemp[256]; // [esp+Ch] [ebp-388h] BYREF
  char szMaterial[260]; // [esp+20Ch] [ebp-188h] BYREF
  wchar_t num[32]; // [esp+310h] [ebp-84h] BYREF
  wchar_t text[32]; // [esp+350h] [ebp-44h] BYREF
  int px; // [esp+390h] [ebp-4h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent, panelName: name);
  this->__vftable = (CGameChapterPanel_vtbl *)&CGameChapterPanel::`vftable';
  if ( `CGameChapterPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CGameChapterPanel::ChainToMap'::`2'::chained = 1;
    v9 = vgui::FindOrAddPanelMessageMap(className: "CGameChapterPanel");
    v9->pfnClassName = CGameChapterPanel::GetPanelClassName;
    v9->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CGameChapterPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CGameChapterPanel::ChainToAnimationMap'::`2'::chained = 1;
    v10 = FindOrAddPanelAnimationMap(className: "CGameChapterPanel");
    v10->pfnClassName = CGameChapterPanel::GetPanelClassName;
    v10->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CGameChapterPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CGameChapterPanel::KB_ChainToMap'::`2'::chained = 1;
    v11 = vgui::FindOrAddPanelKeyBindingMap(className: "CGameChapterPanel");
    v11->pfnClassName = CGameChapterPanel::GetPanelClassName;
    v11->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  v12 = chapterConfigFile;
  v13 = nullptr;
  this->m_TextColor = 0;
  this->m_DisabledColor = 0;
  this->m_SelectedColor = 0;
  this->m_FillColor = 0;
  V_strncpy(pDest: this->m_szConfigFile, pSrc: v12, maxLen: 260);
  v14 = chapterNumber;
  V_strncpy(pDest: this->m_szChapter, pSrc: chapterNumber, maxLen: 32);
  v15 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v15 != nullptr )
    v13 = vgui::ImagePanel::ImagePanel(this: v15, parent: this, name: "LevelPicBorder");
  vgui::Panel::MakeReadyForUse(this: v13);
  this->m_pLevelPicBorder = v13;
  v16 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v16 != nullptr )
    v17 = vgui::ImagePanel::ImagePanel(this: v16, parent: this, name: "LevelPic");
  else
    v17 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v17);
  this->m_bCommentaryMode = bCommentary;
  this->m_pLevelPic = v17;
  this->m_pCommentaryIcon = nullptr;
  v18 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#GameUI_Chapter");
  g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v14, a3: num, a4: 64);
  if ( v18 == nullptr )
    v18 = L"CHAPTER";
  _snwprintf(string: text, count: 0x40u, format: L"%s %s", v18, num);
  v19 = ModInfo();
  if ( CModInfo::IsSinglePlayerOnly(this: v19) )
  {
    v20 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
    if ( v20 != nullptr )
      v21 = vgui::Label::Label(this: v20, parent: this, panelName: "ChapterLabel", wszText: text);
    else
      v21 = nullptr;
    this->m_pChapterLabel = v21;
    v22 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
    if ( v22 != nullptr )
      v23 = vgui::Label::Label(this: v22, parent: this, panelName: "ChapterNameLabel", text: chapterName);
    else
      v23 = nullptr;
  }
  else
  {
    v24 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
    if ( v24 != nullptr )
      v25 = vgui::Label::Label(this: v24, parent: this, panelName: "ChapterLabel", text: chapterName);
    else
      v25 = nullptr;
    this->m_pChapterLabel = v25;
    v26 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
    if ( v26 != nullptr )
      v23 = vgui::Label::Label(this: v26, parent: this, panelName: "ChapterNameLabel", text: "#GameUI_LoadCommentary");
    else
      v23 = nullptr;
  }
  this->m_pChapterNameLabel = v23;
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  V_snprintf(pDest: szMaterial, maxLen: 0x104u, pFormat: "chapters/%s", chapterConfigFile);
  strstr(str1: (unsigned __int8 *)szMaterial, str2: ".");
  if ( v27 != nullptr )
    *v27 = 0;
  this->m_pLevelPic->SetImage(this: this->m_pLevelPic, a2: szMaterial);
  v28 = GameUI();
  CGameUI::IsConsoleUI(this: v28);
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "Resource/NewGameChapterPanel.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  vgui::Panel::GetPos(this: this->m_pLevelPicBorder, x: &px, y: (int *)&name);
  Tall = vgui::Panel::GetTall(this: this->m_pLevelPicBorder);
  v35 = &name[Tall];
  Wide = vgui::Panel::GetWide(this: this->m_pLevelPicBorder);
  vgui::Panel::SetSize(this, wide: Wide, tall: (int)v35);
  v31 = (CSelectionOverlayPanel *)MemAlloc_Alloc(nSize: 0x158u);
  if ( v31 != nullptr )
    v32 = CSelectionOverlayPanel::CSelectionOverlayPanel(this: v31, parent: this, selectionTarget: parent, chapterIndex);
  else
    v32 = nullptr;
  v36 = vgui::Panel::GetTall(this);
  v33 = vgui::Panel::GetWide(this);
  vgui::Panel::SetBounds(this: v32, x: 0, y: 0, wide: v33, tall: v36);
  v32->MoveToFront(this: v32);
  this->m_pChapterNameLabel->GetText(this: this->m_pChapterNameLabel, a2: w_szStrTemp, a3: 512);
  this->m_bTeaserChapter = wcscmp(w_szStrTemp, L"Coming Soon") == 0;
  this->m_bHasBonus = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F1EF0
// Name: public: virtual struct vgui::PanelMessageMap __near * CGameChapterPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CGameChapterPanel::GetMessageMap(CGameChapterPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CGameChapterPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CGameChapterPanel::GetMessageMap'::`2'::s_pMap;
  `CGameChapterPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CGameChapterPanel");
  `CGameChapterPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F1F20
// Name: public: virtual struct PanelAnimationMap __near * CGameChapterPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CGameChapterPanel::GetAnimMap(CGameChapterPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CGameChapterPanel");
}

//------------------------------------------------------------------------------
// Address: 0x101F1F30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CGameChapterPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CGameChapterPanel::GetKBMap(CGameChapterPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CGameChapterPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CGameChapterPanel::GetKBMap'::`2'::s_pMap;
  `CGameChapterPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CGameChapterPanel");
  `CGameChapterPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F1F60
// Name: public: virtual void CGameChapterPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameChapterPanel::ApplySchemeSettings(CGameChapterPanel *this, int pScheme)
{
  vgui::IScheme *v2; // esi
  Color v4; // ecx
  Color *(__thiscall *GetColor)(vgui::IScheme *, Color *, const char *, Color); // edx
  Color *(__thiscall *v6)(vgui::IScheme *, Color *, const char *, Color); // edx
  CGameUI *v7; // eax
  vgui::Panel *ChildByName; // eax
  vgui::ImagePanel *v9; // eax

  v2 = (vgui::IScheme *)pScheme;
  v4 = *(Color *)(*(int (__thiscall **)(int, int *, const char *, int))(*(_DWORD *)pScheme + 20))(
                   a1: pScheme,
                   a2: &pScheme,
                   a3: "NewGame.TextColor",
                   a4: -1);
  pScheme = -1;
  this->m_TextColor = v4;
  this->m_FillColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, int *, const char *, int))v2->GetColor)(
                                  a1: v2,
                                  a2: &pScheme,
                                  a3: "NewGame.FillColor",
                                  a4: -1);
  GetColor = v2->GetColor;
  pScheme = -1;
  this->m_DisabledColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, int *, const char *, int))GetColor)(
                                      a1: v2,
                                      a2: &pScheme,
                                      a3: "NewGame.DisabledColor",
                                      a4: -1);
  v6 = v2->GetColor;
  pScheme = -1;
  this->m_SelectedColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, int *, const char *, int))v6)(
                                      a1: v2,
                                      a2: &pScheme,
                                      a3: "NewGame.SelectionColor",
                                      a4: -1);
  vgui::Panel::ApplySchemeSettings(this, pScheme: (int)v2);
  if ( this->m_bTeaserChapter )
    this->m_pChapterLabel->SetVisible(this: this->m_pChapterLabel, a2: false);
  v7 = GameUI();
  if ( CGameUI::IsConsoleUI(this: v7) )
    this->m_pChapterNameLabel->SetVisible(this: this->m_pChapterNameLabel, a2: false);
  ChildByName = vgui::Panel::FindChildByName(this, childName: "CommentaryIcon", recurseDown: false);
  v9 = (vgui::ImagePanel *)__RTDynamicCast(
                             inptr: ChildByName,
                             VfDelta: 0,
                             SrcType: &vgui::Panel `RTTI Type Descriptor',
                             TargetType: &vgui::ImagePanel `RTTI Type Descriptor',
                             isReference: 0);
  this->m_pCommentaryIcon = v9;
  if ( v9 != nullptr )
    v9->SetVisible(this: v9, a2: this->m_bCommentaryMode);
}

//------------------------------------------------------------------------------
// Address: 0x101F20A0
// Name: public: void CGameChapterPanel::SetSelected(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameChapterPanel::SetSelected(CGameChapterPanel *this, bool state)
{
  CGameUI *v3; // eax
  bool IsConsoleUI; // al
  CGameUI *v5; // eax
  int m_SelectedColor; // ecx

  if ( this->IsEnabled(this) )
  {
    if ( state )
    {
      v5 = GameUI();
      if ( !CGameUI::IsConsoleUI(this: v5) )
      {
        ((void (__thiscall *)(vgui::Label *, _DWORD))this->m_pChapterLabel->SetFgColor)(
          a1: this->m_pChapterLabel,
          a2: *(_DWORD *)&this->m_SelectedColor);
        ((void (__thiscall *)(vgui::Label *, _DWORD))this->m_pChapterNameLabel->SetFgColor)(
          a1: this->m_pChapterNameLabel,
          a2: *(_DWORD *)&this->m_SelectedColor);
      }
      m_SelectedColor = (int)this->m_SelectedColor;
    }
    else
    {
      ((void (__thiscall *)(vgui::Label *, _DWORD))this->m_pChapterLabel->SetFgColor)(
        a1: this->m_pChapterLabel,
        a2: *(_DWORD *)&this->m_TextColor);
      ((void (__thiscall *)(vgui::Label *, _DWORD))this->m_pChapterNameLabel->SetFgColor)(
        a1: this->m_pChapterNameLabel,
        a2: *(_DWORD *)&this->m_TextColor);
      m_SelectedColor = (int)this->m_FillColor;
    }
    vgui::ProgressBar::SetBarInset(this: (vgui::ProgressBar *)this->m_pLevelPicBorder, pixels: m_SelectedColor);
    vgui::Panel::SetAlpha(this: this->m_pLevelPic, alpha: 255);
  }
  else
  {
    ((void (__thiscall *)(vgui::Label *, _DWORD))this->m_pChapterLabel->SetFgColor)(
      a1: this->m_pChapterLabel,
      a2: *(_DWORD *)&this->m_DisabledColor);
    ((void (__thiscall *)(vgui::Label *, _DWORD))this->m_pChapterNameLabel->SetFgColor)(
      a1: this->m_pChapterNameLabel,
      a2: 0);
    vgui::ProgressBar::SetBarInset(
      this: (vgui::ProgressBar *)this->m_pLevelPicBorder,
      pixels: *(_DWORD *)&this->m_DisabledColor);
    v3 = GameUI();
    IsConsoleUI = CGameUI::IsConsoleUI(this: v3);
    vgui::Panel::SetAlpha(this: this->m_pLevelPic, alpha: IsConsoleUI ? 64 : 128);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F21D0
// Name: public: virtual void CNewGameDialog::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewGameDialog::ApplySettings(CNewGameDialog *this, KeyValues *inResourceData)
{
  int Int; // eax
  int v4; // eax

  vgui::Frame::ApplySettings(this, inResourceData);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "chapterypos", defaultValue: 40);
  this->m_PanelYPos[0] = Int;
  this->m_PanelYPos[1] = Int;
  this->m_PanelYPos[2] = Int;
  this->m_PanelYPos[3] = Int;
  this->m_PanelYPos[4] = Int;
  v4 = KeyValues::GetInt(this: inResourceData, keyName: "centerbgtall", defaultValue: 0);
  vgui::Panel::SetTall(this: this->m_pCenterBg, tall: v4);
  g_ScrollSpeedSlow = KeyValues::GetFloat(this: inResourceData, keyName: "scrollslow", defaultValue: 0.0);
  g_ScrollSpeedFast = KeyValues::GetFloat(this: inResourceData, keyName: "scrollfast", defaultValue: 0.0);
  this->m_ScrollSpeed = g_ScrollSpeedSlow;
}

//------------------------------------------------------------------------------
// Address: 0x101F2270
// Name: public: virtual void CNewGameDialog::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewGameDialog::Activate(CNewGameDialog *this)
{
  CGameUI *v2; // eax
  CCStrike15BasePanel *v3; // eax
  CBonusMapsDatabase *v4; // eax
  const char *v5; // eax
  vgui::Label *m_pCommentaryLabel; // ecx
  char *m_pszString; // eax
  int v8; // eax
  bool v9; // cc
  int v10; // ebx
  CGameChapterPanel *v11; // edi
  BOOL m_bCommentaryMode; // eax
  vgui::ImagePanel *m_pCommentaryIcon; // ecx
  int v14; // ecx
  bool v15; // al
  ConVarRef var; // [esp+4h] [ebp-10h] BYREF
  int iUnlockedChapter; // [esp+Ch] [ebp-8h]
  unsigned int v18; // [esp+10h] [ebp-4h]

  this->m_bMapStarting = false;
  v2 = GameUI();
  if ( CGameUI::IsConsoleUI(this: v2) )
  {
    v3 = BasePanel();
    if ( v3 != nullptr )
      CBaseModPanel::SetMenuItemBlinkingState(this: v3, itemName: "OpenNewGameDialog", state: false);
    v4 = BonusMapsDatabase();
    CBonusMapsDatabase::SetBlink(this: v4, bState: false);
  }
  v5 = "#GameUI_LoadCommentary";
  if ( !this->m_bCommentaryMode )
    v5 = "#GameUI_NewGame";
  this->SetTitle_2(this, a2: v5, a3: true);
  m_pCommentaryLabel = this->m_pCommentaryLabel;
  if ( m_pCommentaryLabel != nullptr )
    m_pCommentaryLabel->SetVisible(this: m_pCommentaryLabel, a2: this->m_bCommentaryMode);
  ConVarRef::ConVarRef(this: &var, pName: "sv_unlockedchapters");
  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&var) )
    m_pszString = var.m_pConVarState->m_Value.m_pszString;
  else
    m_pszString = "1";
  v8 = atoi(nptr: m_pszString);
  v9 = this->m_ChapterPanels.m_Size <= 0;
  iUnlockedChapter = v8;
  if ( !v9 )
  {
    v10 = 1;
    v18 = 0;
    do
    {
      v11 = this->m_ChapterPanels.m_Memory.m_pMemory[v18 / 4];
      if ( v11 != nullptr )
      {
        m_bCommentaryMode = this->m_bCommentaryMode;
        m_pCommentaryIcon = v11->m_pCommentaryIcon;
        v11->m_bCommentaryMode = m_bCommentaryMode;
        if ( m_pCommentaryIcon != nullptr )
          m_pCommentaryIcon->SetVisible(this: m_pCommentaryIcon, a2: m_bCommentaryMode);
        v14 = iUnlockedChapter;
        if ( iUnlockedChapter <= 0 )
          v14 = 1;
        v15 = false;
        if ( this->m_bCommentaryMode )
        {
          v15 = v14 <= v10;
        }
        else if ( v14 < v10 )
        {
          v15 = v10 != 0;
        }
        v11->SetEnabled(this: v11, a2: !v15);
      }
      v18 += 4;
      ++v10;
    }
    while ( v10 - 1 < this->m_ChapterPanels.m_Size );
  }
  vgui::Frame::Activate(this);
}

//------------------------------------------------------------------------------
// Address: 0x101F23D0
// Name: private: void CNewGameDialog::UpdateBonusSelection(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __usercall CNewGameDialog::UpdateBonusSelection(CNewGameDialog *this@<ecx>, int a2@<ebx>)
{
  BonusMapDescription_t *m_pBonusMapDescription; // eax
  int m_Size; // edx
  CUtlVector<ChallengeDescription_t,CUtlMemory<ChallengeDescription_t,int> > *m_pChallenges; // ecx
  int m_iBonusSelection; // ecx
  int v7; // ebx
  CNewGameDialog_vtbl *v8; // eax
  BonusMapDescription_t *v9; // eax
  CBonusMapsDatabase *v10; // eax
  int v11; // ebx
  BonusMapDescription_t *v12; // edi
  CBonusMapsDatabase *v13; // eax
  int v14; // eax
  vgui::Panel *v15; // eax
  void *v16; // esi
  int v17; // ebx
  ChallengeDescription_t *v18; // edi
  vgui::Panel *v19; // eax
  void *v20; // edi
  vgui::Panel *ChildByName; // eax
  void *v22; // eax
  vgui::Panel *v23; // eax
  void *v24; // edi
  vgui::ILocalize_vtbl *v25; // edi
  int v26; // eax
  vgui::ILocalize_vtbl *v27; // edi
  int v28; // eax
  int v30; // [esp-4h] [ebp-39Ch]
  int v31; // [esp-4h] [ebp-39Ch]
  char szBuff[512]; // [esp+8h] [ebp-390h] BYREF
  _BYTE szWideBuff[256]; // [esp+208h] [ebp-190h] OVERLAPPED BYREF
  wchar_t szWideBuff2[64]; // [esp+308h] [ebp-90h] BYREF
  int iEarnedMedal; // [esp+388h] [ebp-10h] BYREF
  int iNextMedal; // [esp+38Ch] [ebp-Ch] BYREF
  int iNext; // [esp+390h] [ebp-8h] BYREF
  int iBest; // [esp+394h] [ebp-4h] BYREF

  m_pBonusMapDescription = this->m_pBonusMapDescription;
  m_Size = 0;
  if ( m_pBonusMapDescription == nullptr )
  {
    this->SetControlVisible(this, a2: "ChallengeEarnedMedal", a3: false);
    this->SetControlVisible(this, a2: "ChallengeBestLabel", a3: false);
    this->SetControlVisible(this, a2: "ChallengeNextMedal", a3: false);
    this->SetControlVisible(this, a2: "ChallengeNextLabel", a3: false);
    return;
  }
  m_pChallenges = m_pBonusMapDescription->m_pChallenges;
  if ( m_pChallenges != nullptr )
    m_Size = m_pChallenges->m_Size;
  m_iBonusSelection = this->m_iBonusSelection;
  if ( m_iBonusSelection >= 0 )
  {
    if ( m_iBonusSelection >= m_Size + 2 )
      this->m_iBonusSelection = 0;
  }
  else
  {
    this->m_iBonusSelection = m_Size + 1;
  }
  v7 = this->m_iBonusSelection;
  if ( v7 == 0 )
  {
    ((void (__thiscall *)(vgui::Label *, const char *, int))this->m_pBonusSelection->SetText)(
      a1: this->m_pBonusSelection,
      a2: "#GameUI_BonusMapsStandard",
      a3: a2);
    this->SetControlVisible(this, a2: "ChallengeEarnedMedal", a3: false);
    this->SetControlVisible(this, a2: "ChallengeBestLabel", a3: false);
    this->SetControlVisible(this, a2: "ChallengeNextMedal", a3: false);
    v8 = this->__vftable;
LABEL_10:
    ((void (__thiscall *)(CNewGameDialog *, const char *))v8->SetControlVisible)(a1: this, a2: "ChallengeNextLabel");
    return;
  }
  if ( v7 != 1 )
  {
    v17 = v7 - 2;
    v18 = &m_pBonusMapDescription->m_pChallenges->m_Memory.m_pMemory[v17];
    ((void (__thiscall *)(vgui::Label *, ChallengeDescription_t *, int))this->m_pBonusSelection->SetText)(
      a1: this->m_pBonusSelection,
      a2: v18,
      a3: a2);
    GetChallengeMedals(pChallengeDescription: v18, &iBest, &iEarnedMedal, &iNext, &iNextMedal);
    if ( iEarnedMedal <= -1 || iBest == -1 )
    {
      ChildByName = vgui::Panel::FindChildByName(this, childName: "ChallengeEarnedMedal", recurseDown: false);
      v22 = __RTDynamicCast(
              inptr: ChildByName,
              VfDelta: 0,
              SrcType: &vgui::Panel `RTTI Type Descriptor',
              TargetType: &vgui::CBitmapImagePanel `RTTI Type Descriptor',
              isReference: 0);
      (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)v22 + 132))(a1: v22, a2: 0);
    }
    else
    {
      if ( v17 >= 10 )
        V_snprintf(pDest: szBuff, maxLen: 0x200u, pFormat: "medals/medal_%i_%s", v17, g_pszMedalNames[iEarnedMedal]);
      else
        V_snprintf(pDest: szBuff, maxLen: 0x200u, pFormat: "medals/medal_0%i_%s", v17, g_pszMedalNames[iEarnedMedal]);
      v19 = vgui::Panel::FindChildByName(this, childName: "ChallengeEarnedMedal", recurseDown: false);
      v20 = __RTDynamicCast(
              inptr: v19,
              VfDelta: 0,
              SrcType: &vgui::Panel `RTTI Type Descriptor',
              TargetType: &vgui::CBitmapImagePanel `RTTI Type Descriptor',
              isReference: 0);
      (*(void (__thiscall **)(void *, int))(*(_DWORD *)v20 + 132))(a1: v20, a2: 1);
      (*(void (__thiscall **)(void *, char *, int))(*(_DWORD *)v20 + 844))(a1: v20, a2: szBuff, a3: 1);
    }
    if ( iNextMedal <= 0 )
    {
      this->SetControlVisible(this, a2: "ChallengeNextMedal", a3: false);
    }
    else
    {
      if ( v17 >= 10 )
        V_snprintf(pDest: szBuff, maxLen: 0x200u, pFormat: "medals/medal_%i_%s", v17, g_pszMedalNames[iNextMedal]);
      else
        V_snprintf(pDest: szBuff, maxLen: 0x200u, pFormat: "medals/medal_0%i_%s", v17, g_pszMedalNames[iNextMedal]);
      v23 = vgui::Panel::FindChildByName(this, childName: "ChallengeNextMedal", recurseDown: false);
      v24 = __RTDynamicCast(
              inptr: v23,
              VfDelta: 0,
              SrcType: &vgui::Panel `RTTI Type Descriptor',
              TargetType: &vgui::CBitmapImagePanel `RTTI Type Descriptor',
              isReference: 0);
      (*(void (__thiscall **)(void *, int))(*(_DWORD *)v24 + 132))(a1: v24, a2: 1);
      (*(void (__thiscall **)(void *, char *, int))(*(_DWORD *)v24 + 844))(a1: v24, a2: szBuff, a3: 1);
    }
    if ( iBest == -1 )
    {
      this->SetControlVisible(this, a2: "ChallengeBestLabel", a3: false);
    }
    else
    {
      V_snprintf(pDest: szBuff, maxLen: 0x200u, pFormat: "%i", iBest);
      g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: szBuff, a3: szWideBuff2, a4: 128);
      v25 = g_pVGuiLocalize->__vftable;
      v26 = ((int (__thiscall *)(vgui::ILocalize *, const char *, int, wchar_t *))g_pVGuiLocalize->Find)(
              a1: g_pVGuiLocalize,
              a2: "#GameUI_BonusMapsBest",
              a3: 1,
              a4: szWideBuff2);
      ((void (__cdecl *)(vgui::ILocalize *, _BYTE *, int, int))v25->ConstructString_3)(
        a1: g_pVGuiLocalize,
        a2: &szWideBuff[128],
        a3: 128,
        a4: v26);
      ((void (__thiscall *)(vgui::ILocalize *, _BYTE *, char *, int, int))g_pVGuiLocalize->ConvertUnicodeToANSI)(
        a1: g_pVGuiLocalize,
        a2: &szWideBuff[128],
        a3: szBuff,
        a4: 512,
        a5: v30);
      this->SetControlString_2(this, a2: "ChallengeBestLabel", a3: szBuff);
      this->SetControlVisible(this, a2: "ChallengeBestLabel", a3: true);
    }
    if ( iNext != -1 )
    {
      V_snprintf(pDest: szBuff, maxLen: 0x200u, pFormat: "%i", iNext);
      g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: szBuff, a3: szWideBuff2, a4: 128);
      v27 = g_pVGuiLocalize->__vftable;
      v28 = ((int (__thiscall *)(vgui::ILocalize *, const char *, int, wchar_t *))g_pVGuiLocalize->Find)(
              a1: g_pVGuiLocalize,
              a2: "#GameUI_BonusMapsGoal",
              a3: 1,
              a4: szWideBuff2);
      ((void (__cdecl *)(vgui::ILocalize *, _BYTE *, int, int))v27->ConstructString_3)(
        a1: g_pVGuiLocalize,
        a2: &szWideBuff[128],
        a3: 128,
        a4: v28);
      ((void (__thiscall *)(vgui::ILocalize *, _BYTE *, char *, int, int))g_pVGuiLocalize->ConvertUnicodeToANSI)(
        a1: g_pVGuiLocalize,
        a2: &szWideBuff[128],
        a3: szBuff,
        a4: 512,
        a5: v31);
      this->SetControlString_2(this, a2: "ChallengeNextLabel", a3: szBuff);
    }
    v8 = this->__vftable;
    goto LABEL_10;
  }
  this->m_pBonusSelection->SetText(this: this->m_pBonusSelection, a2: "#GameUI_BonusMapsAdvanced");
  this->SetControlVisible(this, a2: "ChallengeEarnedMedal", a3: false);
  this->SetControlVisible(this, a2: "ChallengeBestLabel", a3: false);
  this->SetControlVisible(this, a2: "ChallengeNextMedal", a3: false);
  this->SetControlVisible(this, a2: "ChallengeNextLabel", a3: false);
  memset(szWideBuff, 0, sizeof(szWideBuff));
  v9 = this->m_pBonusMapDescription;
  if ( v9 != nullptr )
    V_snprintf(pDest: szWideBuff, maxLen: 0x100u, pFormat: "%s_advanced", v9->szMapFileName);
  iBest = 0;
  v10 = BonusMapsDatabase();
  if ( CBonusMapsDatabase::BonusCount(this: v10) > 0 )
  {
    v11 = 0;
    do
    {
      v12 = &BonusMapsDatabase()->m_BonusMaps.m_Memory.m_pMemory[v11];
      if ( _V_stricmp(s1: szWideBuff, s2: v12->szMapFileName) == 0 )
        break;
      ++iBest;
      ++v11;
      v13 = BonusMapsDatabase();
      v14 = CBonusMapsDatabase::BonusCount(this: v13);
    }
    while ( iBest < v14 );
    if ( v12 != nullptr && v12->bComplete )
    {
      v15 = vgui::Panel::FindChildByName(this, childName: "ChallengeEarnedMedal", recurseDown: false);
      v16 = __RTDynamicCast(
              inptr: v15,
              VfDelta: 0,
              SrcType: &vgui::Panel `RTTI Type Descriptor',
              TargetType: &vgui::CBitmapImagePanel `RTTI Type Descriptor',
              isReference: 0);
      (*(void (__thiscall **)(void *, int))(*(_DWORD *)v16 + 132))(a1: v16, a2: 1);
      (*(void (__thiscall **)(void *, const char *, int))(*(_DWORD *)v16 + 844))(
        a1: v16,
        a2: "hud/icon_complete",
        a3: 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F29A0
// Name: public: void CNewGameDialog::SetSelectedChapter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewGameDialog::SetSelectedChapter(CNewGameDialog *this, const char *chapter)
{
  int i; // edi
  CGameChapterPanel **m_pMemory; // ecx
  vgui::Button *m_pPlayButton; // ecx

  for ( i = 0; i < this->m_ChapterPanels.m_Size; ++i )
  {
    if ( chapter == nullptr
      || _V_stricmp(s1: this->m_ChapterPanels.m_Memory.m_pMemory[i]->m_szChapter, s2: chapter) != 0 )
    {
      CGameChapterPanel::SetSelected(this: this->m_ChapterPanels.m_Memory.m_pMemory[i], state: false);
    }
    else
    {
      m_pMemory = this->m_ChapterPanels.m_Memory.m_pMemory;
      this->m_iSelectedChapter = i;
      CGameChapterPanel::SetSelected(this: m_pMemory[i], state: true);
    }
  }
  m_pPlayButton = this->m_pPlayButton;
  if ( m_pPlayButton != nullptr )
    m_pPlayButton->SetEnabled(this: m_pPlayButton, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x101F2A20
// Name: private: void CNewGameDialog::ScrollBonusSelection(enum CNewGameDialog::EScrollDirection)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CNewGameDialog::ScrollBonusSelection(
        CNewGameDialog *this@<ecx>,
        int a2@<ebx>,
        CNewGameDialog::EScrollDirection dir)
{
  if ( this->m_pBonusMapDescription != nullptr )
  {
    this->m_iBonusSelection += dir;
    g_pVGuiSurface->PlaySound(this: g_pVGuiSurface, a2: "UI/buttonclick.wav");
    CNewGameDialog::UpdateBonusSelection(this, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F2A60
// Name: private: void CNewGameDialog::AnimateSelectionPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewGameDialog::AnimateSelectionPanels(CNewGameDialog *this)
{
  int v1; // ebx
  int v3; // edi
  CGameUI *v4; // eax
  int *v5; // ebx
  CGameChapterPanel *v6; // edi
  vgui::AnimationController *AnimationController; // eax
  vgui::AnimationController *v8; // eax
  vgui::AnimationController *v9; // eax
  CGameUI *v10; // eax
  vgui::AnimationController *v11; // eax
  int m_ActiveTitleIdx; // eax
  int v13; // edi
  vgui::AnimationController *v14; // eax
  vgui::AnimationController *v15; // eax
  KeyValues *v16; // eax
  KeyValues *v17; // eax
  CGameUI *v18; // eax
  vgui::Panel *m_pCenterBg; // [esp-4h] [ebp-34h]
  vgui::Label *v20; // [esp-4h] [ebp-34h]
  vgui::Label *v21; // [esp-4h] [ebp-34h]
  float targetValue; // [esp+4h] [ebp-2Ch]
  float targetValuea; // [esp+4h] [ebp-2Ch]
  float targetValueb; // [esp+4h] [ebp-2Ch]
  float duration; // [esp+Ch] [ebp-24h]
  float durationa; // [esp+Ch] [ebp-24h]
  float durationb; // [esp+Ch] [ebp-24h]
  float durationc; // [esp+Ch] [ebp-24h]
  float durationd; // [esp+Ch] [ebp-24h]
  float duratione; // [esp+Ch] [ebp-24h]
  int idxOffset; // [esp+24h] [ebp-Ch]
  int *v32; // [esp+28h] [ebp-8h]
  int startIdx; // [esp+2Ch] [ebp-4h]
  int startIdxa; // [esp+2Ch] [ebp-4h]

  v1 = 1;
  startIdx = 1;
  v3 = 3;
  if ( this->m_ScrollCt < 1
    || this->m_PanelIndex[2] >= this->m_ChapterPanels.m_Size - 1 && (v4 = GameUI(), CGameUI::IsConsoleUI(this: v4)) )
  {
    v1 = 0;
    if ( this->m_ScrollCt > -1 || this->m_PanelIndex[2] <= 0 && (v18 = GameUI(), CGameUI::IsConsoleUI(this: v18)) )
    {
      this->m_ScrollCt = 0;
      this->m_bScrolling = false;
      this->m_ScrollDirection = SCROLL_NONE;
      g_pVGuiSurface->PlaySound(this: g_pVGuiSurface, a2: "player/suit_denydevice.wav");
      return;
    }
    idxOffset = 1;
    startIdx = 0;
    this->m_ScrollDirection = SCROLL_RIGHT;
  }
  else
  {
    idxOffset = -1;
    v3 = 4;
    this->m_ScrollDirection = SCROLL_LEFT;
  }
  v32 = &this->m_PanelIndex[v1];
  v5 = &this->m_PanelYPos[idxOffset + v1];
  startIdxa = v3 - startIdx + 1;
  do
  {
    if ( *v32 != -1 )
    {
      v6 = this->m_ChapterPanels.m_Memory.m_pMemory[*v32];
      duration = this->m_ScrollSpeed;
      targetValue = (float)*(v5 - 5);
      AnimationController = vgui::GetAnimationController();
      vgui::AnimationController::RunAnimationCommand(
        this: AnimationController,
        panel: v6,
        variable: "xpos",
        targetValue,
        startDelaySeconds: 0.0,
        duration,
        interpolator: (vgui::AnimationController::Interpolators_e)0,
        animParameter: 0.0);
      durationa = this->m_ScrollSpeed;
      targetValuea = (float)*v5;
      v8 = vgui::GetAnimationController();
      vgui::AnimationController::RunAnimationCommand(
        this: v8,
        panel: v6,
        variable: "ypos",
        targetValue: targetValuea,
        startDelaySeconds: 0.0,
        duration: durationa,
        interpolator: (vgui::AnimationController::Interpolators_e)0,
        animParameter: 0.0);
      durationb = this->m_ScrollSpeed;
      targetValueb = *((float *)v5 + 5);
      v9 = vgui::GetAnimationController();
      vgui::AnimationController::RunAnimationCommand(
        this: v9,
        panel: v6,
        variable: "alpha",
        targetValue: targetValueb,
        startDelaySeconds: 0.0,
        duration: durationb,
        interpolator: (vgui::AnimationController::Interpolators_e)0,
        animParameter: 0.0);
    }
    ++v32;
    ++v5;
    --startIdxa;
  }
  while ( startIdxa != 0 );
  v10 = GameUI();
  if ( CGameUI::IsConsoleUI(this: v10) )
  {
    g_pVGuiSurface->PlaySound(this: g_pVGuiSurface, a2: "UI/buttonclick.wav");
    durationc = this->m_ScrollSpeed * 0.25;
    m_pCenterBg = this->m_pCenterBg;
    v11 = vgui::GetAnimationController();
    vgui::AnimationController::RunAnimationCommand(
      this: v11,
      panel: m_pCenterBg,
      variable: "alpha",
      targetValue: 0.0,
      startDelaySeconds: 0.0,
      duration: durationc,
      interpolator: (vgui::AnimationController::Interpolators_e)0,
      animParameter: 0.0);
    m_ActiveTitleIdx = this->m_ActiveTitleIdx;
    durationd = this->m_ScrollSpeed;
    v20 = this->m_pChapterTitleLabels[m_ActiveTitleIdx];
    v13 = m_ActiveTitleIdx ^ 1;
    v14 = vgui::GetAnimationController();
    vgui::AnimationController::RunAnimationCommand(
      this: v14,
      panel: v20,
      variable: "alpha",
      targetValue: 255.0,
      startDelaySeconds: 0.0,
      duration: durationd,
      interpolator: (vgui::AnimationController::Interpolators_e)0,
      animParameter: 0.0);
    duratione = this->m_ScrollSpeed;
    v21 = this->m_pChapterTitleLabels[v13];
    v15 = vgui::GetAnimationController();
    vgui::AnimationController::RunAnimationCommand(
      this: v15,
      panel: v21,
      variable: "alpha",
      targetValue: 0.0,
      startDelaySeconds: 0.0,
      duration: duratione,
      interpolator: (vgui::AnimationController::Interpolators_e)0,
      animParameter: 0.0);
    this->m_iSelectedChapter -= idxOffset;
  }
  v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v16 != nullptr )
    v17 = KeyValues::KeyValues(this: v16, setName: "FinishScroll");
  else
    v17 = nullptr;
  ((void (__thiscall *)(CNewGameDialog *, CNewGameDialog *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v17,
    a4: LODWORD(this->m_ScrollSpeed));
}

//------------------------------------------------------------------------------
// Address: 0x101F2D80
// Name: private: void CNewGameDialog::InitPanelIndexForDisplay(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewGameDialog::InitPanelIndexForDisplay(CNewGameDialog *this, int idx)
{
  CGameChapterPanel *v3; // esi

  v3 = this->m_ChapterPanels.m_Memory.m_pMemory[this->m_PanelIndex[idx]];
  if ( v3 != nullptr )
  {
    vgui::Panel::SetPos(this: v3, x: this->m_PanelXPos[idx], y: this->m_PanelYPos[idx]);
    vgui::Panel::SetAlpha(this: v3, alpha: (int)this->m_PanelAlpha[idx]);
    v3->SetVisible(this: v3, a2: true);
    if ( this->m_PanelAlpha[idx] != 0.0 )
      vgui::Panel::SetZPos(this: v3, z: 50);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F2E00
// Name: public: virtual void CNewGameDialog::StartGame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewGameDialog::StartGame(CNewGameDialog *this)
{
  int m_iSelectedChapter; // eax
  CGameChapterPanel **m_pMemory; // ecx
  CCommentaryExplanationDialog *v4; // edi
  CCStrike15BasePanel *v5; // eax
  CCommentaryExplanationDialog *v6; // eax
  vgui::Panel *v7; // eax
  CCStrike15BasePanel *v8; // eax
  char mapcommand[512]; // [esp+4h] [ebp-214h] BYREF
  ConVarRef sv_cheats; // [esp+204h] [ebp-14h] BYREF
  ConVarRef commentary; // [esp+20Ch] [ebp-Ch] BYREF
  vgui::DHANDLE<CCommentaryExplanationDialog> hCommentaryExplanationDialog; // [esp+214h] [ebp-4h] BYREF

  m_iSelectedChapter = this->m_iSelectedChapter;
  if ( m_iSelectedChapter >= 0 && m_iSelectedChapter < this->m_ChapterPanels.m_Size )
  {
    m_pMemory = this->m_ChapterPanels.m_Memory.m_pMemory;
    mapcommand[0] = 0;
    V_snprintf(
      pDest: mapcommand,
      maxLen: 0x200u,
      pFormat: "disconnect\ndeathmatch 0\nprogress_enable\nexec %s\n",
      m_pMemory[m_iSelectedChapter]->m_szConfigFile);
    ConVarRef::ConVarRef(this: &commentary, pName: "commentary");
    ((void (__stdcall *)(bool))commentary.m_pConVar->SetValue_2)(a1: this->m_bCommentaryMode);
    ConVarRef::ConVarRef(this: &sv_cheats, pName: "sv_cheats");
    ((void (__stdcall *)(bool))sv_cheats.m_pConVar->SetValue_2)(a1: this->m_bCommentaryMode);
    if ( !this->m_bCommentaryMode
      || this->m_ChapterPanels.m_Memory.m_pMemory[this->m_iSelectedChapter]->m_bTeaserChapter )
    {
      v8 = BasePanel();
      CBaseModPanel::FadeToBlackAndRunEngineCommand(this: v8, engineCommand: mapcommand);
      this->OnClose(this);
    }
    else
    {
      hCommentaryExplanationDialog.m_iPanelID = -1;
      if ( vgui::PHandle::Get(this: &hCommentaryExplanationDialog) == nullptr )
      {
        v4 = (CCommentaryExplanationDialog *)MemAlloc_Alloc(nSize: 0x414u);
        if ( v4 != nullptr )
        {
          v5 = BasePanel();
          v6 = CCommentaryExplanationDialog::CCommentaryExplanationDialog(
                 this: v4,
                 parent: v5,
                 pszFinishCommand: mapcommand);
        }
        else
        {
          v6 = nullptr;
        }
        vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &hCommentaryExplanationDialog, pPanel: v6);
      }
      v7 = vgui::PHandle::Get(this: &hCommentaryExplanationDialog);
      v7->__vftable[1].OnTick(this: v7);
      this->OnClose(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F2F60
// Name: private: void CNewGameDialog::UpdateMenuComponents(enum CNewGameDialog::EScrollDirection)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewGameDialog::UpdateMenuComponents(CNewGameDialog *this, CNewGameDialog::EScrollDirection dir)
{
  int v3; // ebx
  CGameUI *v4; // eax
  int v5; // eax
  vgui::Label *m_pChapterNameLabel; // ecx
  vgui::Label *v7; // ecx
  vgui::Panel *ChildByName; // edi
  vgui::Panel *v9; // ecx
  void (__thiscall *SetFgColor)(vgui::Panel *, Color); // edx
  void (__thiscall *v11)(vgui::Panel *, Color); // eax
  void (__thiscall *v12)(vgui::Panel *, Color); // edx
  CBonusMapsDatabase *v13; // eax
  int v14; // edi
  BonusMapDescription_t *m_pMemory; // ecx
  CGameChapterPanel **v16; // eax
  BonusMapDescription_t *v17; // ecx
  CBonusMapsDatabase *v18; // eax
  int v19; // eax
  vgui::Panel *v20; // edi
  vgui::Panel *v21; // eax
  CGameUI *v22; // eax
  float v23; // eax
  int m_Size; // eax
  int v25; // ebx
  int v26; // [esp+0h] [ebp-218h]
  wchar_t buffer[260]; // [esp+8h] [ebp-210h] BYREF
  vgui::Panel *rightArrow; // [esp+210h] [ebp-8h]
  int iBonus; // [esp+214h] [ebp-4h]

  v3 = 2;
  if ( dir == SCROLL_LEFT )
  {
    v3 = 3;
  }
  else if ( dir == SCROLL_RIGHT )
  {
    v3 = 1;
  }
  v4 = GameUI();
  if ( CGameUI::IsConsoleUI(this: v4) )
  {
    v5 = this->m_PanelIndex[v3];
    LOBYTE(dir) = 0;
    if ( v5 != -1 )
    {
      m_pChapterNameLabel = this->m_ChapterPanels.m_Memory.m_pMemory[v5]->m_pChapterNameLabel;
      m_pChapterNameLabel->GetText(this: m_pChapterNameLabel, a2: buffer, a3: 520);
      v7 = this->m_pChapterTitleLabels[this->m_ActiveTitleIdx];
      v7->SetText(this: v7, a2: buffer, a3: false);
      LOBYTE(dir) = this->m_ChapterPanels.m_Memory.m_pMemory[this->m_PanelIndex[v3]]->m_bHasBonus;
    }
    ChildByName = vgui::Panel::FindChildByName(this, childName: "LeftArrow", recurseDown: false);
    v9 = vgui::Panel::FindChildByName(this, childName: "RightArrow", recurseDown: false);
    rightArrow = v9;
    if ( ChildByName != nullptr )
    {
      SetFgColor = ChildByName->SetFgColor;
      if ( LODWORD(this->m_PanelAlpha[v3 + 4]) == -1 )
      {
        iBonus = 1082163328;
        ((void (__thiscall *)(vgui::Panel *, int))SetFgColor)(a1: ChildByName, a2: 1082163328);
      }
      else
      {
        iBonus = -1;
        ((void (__thiscall *)(vgui::Panel *, int))SetFgColor)(a1: ChildByName, a2: -1);
      }
      v9 = rightArrow;
    }
    if ( v9 != nullptr )
    {
      if ( this->m_PanelIndex[v3 + 1] == -1 )
      {
        v12 = v9->SetFgColor;
        iBonus = 1082163328;
        ((void (__thiscall *)(vgui::Panel *, int))v12)(a1: v9, a2: 1082163328);
      }
      else
      {
        v11 = v9->SetFgColor;
        iBonus = -1;
        ((void (__thiscall *)(vgui::Panel *, int))v11)(a1: v9, a2: -1);
      }
    }
    if ( (_BYTE)dir != SCROLL_NONE )
    {
      iBonus = 0;
      v13 = BonusMapsDatabase();
      if ( CBonusMapsDatabase::BonusCount(this: v13) > 0 )
      {
        v14 = 0;
        do
        {
          m_pMemory = BonusMapsDatabase()->m_BonusMaps.m_Memory.m_pMemory;
          v16 = this->m_ChapterPanels.m_Memory.m_pMemory;
          v17 = &m_pMemory[v14];
          this->m_pBonusMapDescription = v17;
          if ( _V_stricmp(s1: v17->szChapterName, s2: v16[this->m_PanelIndex[v3]]->m_szConfigFile) == 0 )
            break;
          ++iBonus;
          ++v14;
          v18 = BonusMapsDatabase();
          v19 = CBonusMapsDatabase::BonusCount(this: v18);
        }
        while ( iBonus < v19 );
      }
    }
    else
    {
      this->m_pBonusMapDescription = nullptr;
    }
    v20 = vgui::Panel::FindChildByName(this, childName: "UpArrow", recurseDown: false);
    v21 = vgui::Panel::FindChildByName(this, childName: "DownArrow", recurseDown: false);
    rightArrow = v21;
    if ( v20 != nullptr )
    {
      v20->SetVisible(this: v20, a2: dir);
      v21 = rightArrow;
    }
    if ( v21 != nullptr )
      v21->SetVisible(this: v21, a2: dir);
    this->m_pBonusSelection->SetVisible(this: this->m_pBonusSelection, a2: dir);
    this->m_pBonusSelectionBorder->SetVisible(this: this->m_pBonusSelectionBorder, a2: dir);
    CNewGameDialog::UpdateBonusSelection(this, a2: v3);
  }
  v22 = GameUI();
  if ( !CGameUI::IsConsoleUI(this: v22) )
  {
    v23 = this->m_PanelAlpha[v3 + 4];
    if ( v23 == NAN || v23 == 0.0 )
    {
      this->m_pPrevButton->SetVisible(this: this->m_pPrevButton, a2: false);
      this->m_pPrevButton->SetEnabled(this: this->m_pPrevButton, a2: false);
    }
    else
    {
      this->m_pPrevButton->SetVisible(this: this->m_pPrevButton, a2: true);
      this->m_pPrevButton->SetEnabled(this: this->m_pPrevButton, a2: true);
    }
    m_Size = this->m_ChapterPanels.m_Size;
    if ( m_Size >= 4 )
    {
      v25 = this->m_PanelIndex[v3 + 1];
      if ( v25 != -1 && v25 != m_Size - 1 )
      {
        ((void (__thiscall *)(vgui::Button *, int, int))this->m_pNextButton->SetVisible)(
          a1: this->m_pNextButton,
          a2: 1,
          a3: v26);
        this->m_pNextButton->SetEnabled(this: this->m_pNextButton, a2: true);
        return;
      }
      ((void (__thiscall *)(vgui::Button *, _DWORD, int))this->m_pNextButton->SetVisible)(
        a1: this->m_pNextButton,
        a2: 0,
        a3: v26);
    }
    else
    {
      ((void (__thiscall *)(vgui::Button *, int, int))this->m_pNextButton->SetVisible)(
        a1: this->m_pNextButton,
        a2: 1,
        a3: v26);
    }
    this->m_pNextButton->SetEnabled(this: this->m_pNextButton, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F3260
// Name: public: void CNewGameDialog::SetSelectedChapterIndex(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewGameDialog::SetSelectedChapterIndex(CNewGameDialog *this, int index)
{
  int v2; // esi
  int v4; // edi
  vgui::Button *m_pPlayButton; // ecx
  CGameUI *v6; // eax
  int v7; // eax
  int *v8; // edi
  CGameChapterPanel *v9; // esi
  int v10; // eax
  vgui::Panel::Panel_RegisterMap *v11; // edi
  CGameChapterPanel *v12; // esi
  int i; // [esp+Ch] [ebp-Ch]
  int selectedSlot; // [esp+10h] [ebp-8h]
  int currIdx; // [esp+14h] [ebp-4h]
  int currIdxa; // [esp+14h] [ebp-4h]
  int indexa; // [esp+20h] [ebp+8h]

  v2 = index;
  v4 = 0;
  for ( this->m_iSelectedChapter = index; v4 < this->m_ChapterPanels.m_Size; ++v4 )
  {
    if ( v4 == index )
      CGameChapterPanel::SetSelected(this: this->m_ChapterPanels.m_Memory.m_pMemory[v4], state: true);
    else
      CGameChapterPanel::SetSelected(this: this->m_ChapterPanels.m_Memory.m_pMemory[v4], state: false);
  }
  m_pPlayButton = this->m_pPlayButton;
  if ( m_pPlayButton != nullptr )
    m_pPlayButton->SetEnabled(this: m_pPlayButton, a2: true);
  v6 = GameUI();
  if ( CGameUI::IsConsoleUI(this: v6) )
    selectedSlot = 2;
  else
    selectedSlot = index % 3 + 1;
  v7 = index;
  i = selectedSlot;
  if ( selectedSlot >= 0 )
  {
    v8 = &this->m_PanelIndex[selectedSlot];
    do
    {
      if ( v7 < 0 )
        break;
      *v8 = v7;
      v9 = this->m_ChapterPanels.m_Memory.m_pMemory[*v8];
      currIdx = --v7;
      if ( v9 != nullptr )
      {
        vgui::Panel::SetPos(this: v9, x: *(v8 - 15), y: *(v8 - 10));
        vgui::Panel::SetAlpha(this: v9, alpha: (int)*((float *)v8 - 5));
        v9->SetVisible(this: v9, a2: true);
        if ( *((float *)v8 - 5) != 0.0 )
          vgui::Panel::SetZPos(this: v9, z: 50);
        v7 = currIdx;
      }
      v2 = index;
      --v8;
      --i;
    }
    while ( i >= 0 );
  }
  v10 = v2 + 1;
  indexa = selectedSlot + 1;
  if ( selectedSlot + 1 < 5 )
  {
    v11 = &this->vgui::Frame::vgui::EditablePanel::vgui::Panel::m_RegisterClass + 4 * selectedSlot + 672;
    do
    {
      if ( v10 >= this->m_ChapterPanels.m_Size )
        break;
      *(_DWORD *)v11 = v10;
      v12 = this->m_ChapterPanels.m_Memory.m_pMemory[*(_DWORD *)v11];
      currIdxa = ++v10;
      if ( v12 != nullptr )
      {
        vgui::Panel::SetPos(this: v12, x: *(_DWORD *)&v11[-60], y: *(_DWORD *)&v11[-40]);
        vgui::Panel::SetAlpha(this: v12, alpha: *(_DWORD *)&v11[-20]);
        v12->SetVisible(this: v12, a2: true);
        if ( *(float *)&v11[-20] != 0.0 )
          vgui::Panel::SetZPos(this: v12, z: 50);
        v10 = currIdxa;
      }
      v11 += 4;
      ++indexa;
    }
    while ( indexa < 5 );
  }
  CNewGameDialog::UpdateMenuComponents(this, dir: SCROLL_NONE);
}

//------------------------------------------------------------------------------
// Address: 0x101F3420
// Name: private: void CNewGameDialog::ScrollSelectionPanels(enum CNewGameDialog::EScrollDirection)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewGameDialog::ScrollSelectionPanels(CNewGameDialog *this, CNewGameDialog::EScrollDirection dir)
{
  int v3; // eax

  if ( this->m_bScrolling )
    return;
  if ( dir == SCROLL_LEFT )
  {
    v3 = this->m_PanelIndex[1];
    goto LABEL_6;
  }
  if ( dir == SCROLL_RIGHT )
  {
    v3 = this->m_PanelIndex[3];
LABEL_6:
    if ( v3 != -1 )
      vgui::Panel::SetZPos(this: this->m_ChapterPanels.m_Memory.m_pMemory[v3], z: 0);
  }
  this->m_ActiveTitleIdx ^= 1u;
  if ( dir == SCROLL_LEFT )
  {
    ++this->m_ScrollCt;
  }
  else if ( dir == SCROLL_RIGHT && this->m_PanelIndex[2] != 0 )
  {
    --this->m_ScrollCt;
  }
  this->m_bScrolling = true;
  CNewGameDialog::AnimateSelectionPanels(this);
  CNewGameDialog::UpdateMenuComponents(this, dir: this->m_ScrollDirection);
}

//------------------------------------------------------------------------------
// Address: 0x101F34B0
// Name: private: void CNewGameDialog::ShiftPanelIndices(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewGameDialog::ShiftPanelIndices(CNewGameDialog *this, int offset)
{
  int v3; // eax
  CGameChapterPanel *v4; // ecx
  int v5; // eax
  int v6; // eax
  int v7; // eax
  CGameChapterPanel *v8; // ecx
  int *m_PanelIndex; // edi
  int v10; // eax

  if ( offset <= 0 )
  {
    v7 = this->m_PanelIndex[4];
    if ( v7 >= 0 && v7 < this->m_ChapterPanels.m_Size )
    {
      v8 = this->m_ChapterPanels.m_Memory.m_pMemory[v7];
      v8->SetVisible(this: v8, a2: false);
    }
    m_PanelIndex = this->m_PanelIndex;
    _V_memmove(
      dest: (unsigned __int8 *)&this->m_PanelIndex[1],
      src: (unsigned __int8 *)this->m_PanelIndex,
      count: 0x10u);
    if ( this->m_PanelIndex[0] != -1 )
    {
      v10 = this->m_PanelIndex[0] - 1;
      if ( v10 < 0 || v10 >= this->m_ChapterPanels.m_Size )
      {
        *m_PanelIndex = -1;
      }
      else
      {
        *m_PanelIndex = v10;
        CNewGameDialog::InitPanelIndexForDisplay(this, idx: 0);
      }
    }
  }
  else
  {
    v3 = this->m_PanelIndex[0];
    if ( v3 >= 0 && v3 < this->m_ChapterPanels.m_Size )
    {
      v4 = this->m_ChapterPanels.m_Memory.m_pMemory[v3];
      v4->SetVisible(this: v4, a2: false);
    }
    _V_memmove(
      dest: (unsigned __int8 *)this->m_PanelIndex,
      src: (unsigned __int8 *)&this->m_PanelIndex[1],
      count: 0x10u);
    v5 = this->m_PanelIndex[4];
    if ( v5 != -1 )
    {
      v6 = v5 + 1;
      if ( v6 < 0 || v6 >= this->m_ChapterPanels.m_Size )
      {
        this->m_PanelIndex[4] = -1;
      }
      else
      {
        this->m_PanelIndex[4] = v6;
        CNewGameDialog::InitPanelIndexForDisplay(this, idx: 4);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F35B0
// Name: private: void CNewGameDialog::ContinueScrolling(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewGameDialog::ContinueScrolling(CNewGameDialog *this)
{
  CGameUI *v2; // eax
  CNewGameDialog::EScrollDirection m_ButtonPressed; // eax
  CNewGameDialog::EScrollDirection m_ScrollDirection; // [esp-4h] [ebp-8h]

  v2 = GameUI();
  if ( CGameUI::IsConsoleUI(this: v2) )
  {
    m_ButtonPressed = this->m_ButtonPressed;
    if ( m_ButtonPressed == this->m_ScrollDirection )
    {
      m_ScrollDirection = this->m_ScrollDirection;
      this->m_ScrollSpeed = g_ScrollSpeedFast;
      CNewGameDialog::ScrollSelectionPanels(this, dir: m_ScrollDirection);
    }
    else
    {
      this->m_ScrollSpeed = g_ScrollSpeedSlow;
      if ( m_ButtonPressed != SCROLL_NONE )
        CNewGameDialog::ScrollSelectionPanels(this, dir: m_ButtonPressed);
    }
  }
  else if ( this->m_PanelIndex[1] % 3 != 0 )
  {
    CNewGameDialog::ScrollSelectionPanels(this, dir: this->m_ScrollDirection);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F3630
// Name: public: virtual void CNewGameDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CNewGameDialog::OnCommand(CNewGameDialog *this@<ecx>, int a2@<ebx>, const char *command)
{
  CGameUI *v4; // eax
  CGameChapterPanel *v5; // ecx
  CGameUI *v6; // eax
  CGameUI *v7; // eax
  CCStrike15BasePanel *v8; // eax
  CCStrike15BasePanel *v9; // eax
  int v10; // eax
  int v11; // eax

  if ( _V_stricmp(s1: command, s2: "Play") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "Next") != 0 )
    {
      if ( _V_stricmp(s1: command, s2: "Prev") != 0 )
      {
        if ( _V_stricmp(s1: command, s2: "Mode_Next") != 0 )
        {
          if ( _V_stricmp(s1: command, s2: "Mode_Prev") != 0 )
          {
            if ( _V_stricmp(s1: command, s2: "ReleaseModalWindow") != 0 )
              vgui::Frame::OnCommand(this, command);
            else
              g_pVGuiSurface->RestrictPaintToSinglePanel(this: g_pVGuiSurface, a2: 0, a3: false);
          }
          else if ( !this->m_bMapStarting )
          {
            CNewGameDialog::ScrollBonusSelection(this, a2, dir: SCROLL_RIGHT);
          }
        }
        else if ( !this->m_bMapStarting )
        {
          CNewGameDialog::ScrollBonusSelection(this, a2, dir: SCROLL_LEFT);
        }
      }
      else if ( !this->m_bMapStarting && !this->m_bScrolling )
      {
        v11 = this->m_PanelIndex[3];
        if ( v11 != -1 )
          vgui::Panel::SetZPos(this: this->m_ChapterPanels.m_Memory.m_pMemory[v11], z: 0);
        this->m_ActiveTitleIdx ^= 1u;
        if ( this->m_PanelIndex[2] != 0 )
          --this->m_ScrollCt;
        this->m_bScrolling = true;
        CNewGameDialog::AnimateSelectionPanels(this);
        CNewGameDialog::UpdateMenuComponents(this, dir: this->m_ScrollDirection);
      }
    }
    else if ( !this->m_bMapStarting && !this->m_bScrolling )
    {
      v10 = this->m_PanelIndex[1];
      if ( v10 != -1 )
        vgui::Panel::SetZPos(this: this->m_ChapterPanels.m_Memory.m_pMemory[v10], z: 0);
      this->m_ActiveTitleIdx ^= 1u;
      ++this->m_ScrollCt;
      this->m_bScrolling = true;
      CNewGameDialog::AnimateSelectionPanels(this);
      CNewGameDialog::UpdateMenuComponents(this, dir: this->m_ScrollDirection);
    }
  }
  else if ( !this->m_bMapStarting )
  {
    v4 = GameUI();
    if ( CGameUI::IsConsoleUI(this: v4) )
    {
      v5 = this->m_ChapterPanels.m_Memory.m_pMemory[this->m_iSelectedChapter];
      if ( v5->IsEnabled(this: v5) )
      {
        v6 = GameUI();
        if ( !CGameUI::HasSavedThisMenuSession(this: v6)
          && (v7 = GameUI(), v7->IsInLevel(this: v7))
          && engine->GetMaxClients(this: engine) == 1 )
        {
          g_pVGuiSurface->PlaySound(this: g_pVGuiSurface, a2: "UI/buttonclickrelease.wav");
          v8 = BasePanel();
          CBaseModPanel::ShowMessageDialog(this: v8, nType: 0x1Cu, pOwner: this);
        }
        else
        {
          this->OnCommand(this, a2: "StartNewGame");
        }
      }
      else
      {
        this->m_bMapStarting = false;
        g_pVGuiSurface->PlaySound(this: g_pVGuiSurface, a2: "player/suit_denydevice.wav");
        if ( this->m_bCommentaryMode )
        {
          v9 = BasePanel();
          CBaseModPanel::ShowMessageDialog(this: v9, nType: 0x1Au, pOwner: this);
        }
      }
    }
    else
    {
      this->StartGame(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F38E0
// Name: public: virtual void CSelectionOverlayPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSelectionOverlayPanel::OnMousePressed(CSelectionOverlayPanel *this, ButtonCode_t code)
{
  vgui::Panel *v3; // eax

  v3 = this->GetParent(this);
  if ( v3->IsEnabled(this: v3) )
    CNewGameDialog::SetSelectedChapterIndex(this: this->m_pSelectionTarget, index: this->m_iChapterIndex);
}

//------------------------------------------------------------------------------
// Address: 0x101F3920
// Name: public: virtual struct vgui::PanelMessageMap __near * CNewGameDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CNewGameDialog::GetMessageMap(CNewGameDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CNewGameDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CNewGameDialog::GetMessageMap'::`2'::s_pMap;
  `CNewGameDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CNewGameDialog");
  `CNewGameDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F3950
// Name: public: virtual struct PanelAnimationMap __near * CNewGameDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CNewGameDialog::GetAnimMap(CNewGameDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CNewGameDialog");
}

//------------------------------------------------------------------------------
// Address: 0x101F3960
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CNewGameDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CNewGameDialog::GetKBMap(CNewGameDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CNewGameDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CNewGameDialog::GetKBMap'::`2'::s_pMap;
  `CNewGameDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CNewGameDialog");
  `CNewGameDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F3990
// Name: public: virtual void CNewGameDialog::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewGameDialog::ApplySchemeSettings(CNewGameDialog *this, vgui::IScheme *pScheme)
{
  vgui::MenuItem *v3; // eax
  KeyValues *ConsoleControlSettings; // eax
  KeyValues *Key; // eax
  vgui::Panel *ChildByName; // eax
  vgui::Label *v7; // eax
  CGameUI *v8; // eax
  CBonusMapsDatabase *v9; // eax
  CGameChapterPanel **m_pMemory; // ecx
  int v11; // eax

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  if ( this->m_pFooter != nullptr )
  {
    v3 = (vgui::MenuItem *)BasePanel();
    ConsoleControlSettings = (KeyValues *)CBaseModPanel::GetConsoleControlSettings(this: v3);
    Key = KeyValues::FindKey(this: ConsoleControlSettings, keyName: "NewGameFooter.res", bCreate: false);
    this->m_pFooter->LoadControlSettings(this: this->m_pFooter, a2: "null", a3: nullptr, a4: Key, a5: nullptr);
  }
  CNewGameDialog::UpdateMenuComponents(this, dir: SCROLL_NONE);
  ChildByName = vgui::Panel::FindChildByName(this, childName: "CommentaryUnlock", recurseDown: false);
  v7 = (vgui::Label *)__RTDynamicCast(
                        inptr: ChildByName,
                        VfDelta: 0,
                        SrcType: &vgui::Panel `RTTI Type Descriptor',
                        TargetType: &vgui::Label `RTTI Type Descriptor',
                        isReference: 0);
  this->m_pCommentaryLabel = v7;
  if ( v7 != nullptr )
    v7->SetVisible(this: v7, a2: this->m_bCommentaryMode);
  v8 = GameUI();
  if ( CGameUI::IsConsoleUI(this: v8) && !this->m_bCommentaryMode )
  {
    v9 = BonusMapsDatabase();
    if ( CBonusMapsDatabase::BonusesUnlocked(this: v9) )
    {
      m_pMemory = this->m_ChapterPanels.m_Memory.m_pMemory;
      if ( !m_pMemory[this->m_PanelIndex[2]]->m_bHasBonus )
      {
        if ( !this->m_bScrolling )
        {
          v11 = this->m_PanelIndex[1];
          if ( v11 != -1 )
            vgui::Panel::SetZPos(this: m_pMemory[v11], z: 0);
          this->m_ActiveTitleIdx ^= 1u;
          ++this->m_ScrollCt;
          this->m_bScrolling = true;
          CNewGameDialog::AnimateSelectionPanels(this);
          CNewGameDialog::UpdateMenuComponents(this, dir: this->m_ScrollDirection);
        }
        this->m_bScrollToFirstBonusMap = true;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F3AD0
// Name: private: void CNewGameDialog::PostScroll(enum CNewGameDialog::EScrollDirection)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewGameDialog::PostScroll(CNewGameDialog *this, CNewGameDialog::EScrollDirection dir)
{
  int v3; // eax
  CGameChapterPanel *v4; // edi
  vgui::AnimationController *AnimationController; // eax
  CGameUI *v6; // eax
  CBonusMapsDatabase *v7; // eax
  CGameChapterPanel **m_pMemory; // ecx
  int v9; // eax
  float duration; // [esp+8h] [ebp-14h]

  if ( dir == SCROLL_LEFT )
  {
    v3 = this->m_PanelIndex[3];
  }
  else
  {
    if ( dir != SCROLL_RIGHT )
      goto LABEL_7;
    v3 = this->m_PanelIndex[1];
  }
  if ( v3 != -1 )
  {
    v4 = this->m_ChapterPanels.m_Memory.m_pMemory[v3];
    vgui::Panel::SetZPos(this: v4, z: 50);
    duration = this->m_ScrollSpeed;
    AnimationController = vgui::GetAnimationController();
    vgui::AnimationController::RunAnimationCommand(
      this: AnimationController,
      panel: v4,
      variable: "alpha",
      targetValue: 255.0,
      startDelaySeconds: 0.0,
      duration,
      interpolator: (vgui::AnimationController::Interpolators_e)0,
      animParameter: 0.0);
  }
LABEL_7:
  v6 = GameUI();
  if ( CGameUI::IsConsoleUI(this: v6) )
  {
    v7 = BonusMapsDatabase();
    if ( CBonusMapsDatabase::BonusesUnlocked(this: v7) && this->m_bScrollToFirstBonusMap )
    {
      m_pMemory = this->m_ChapterPanels.m_Memory.m_pMemory;
      if ( m_pMemory[this->m_PanelIndex[2]]->m_bHasBonus )
      {
        this->m_bScrollToFirstBonusMap = false;
      }
      else if ( !this->m_bScrolling )
      {
        v9 = this->m_PanelIndex[1];
        if ( v9 != -1 )
          vgui::Panel::SetZPos(this: m_pMemory[v9], z: 0);
        this->m_ActiveTitleIdx ^= 1u;
        ++this->m_ScrollCt;
        this->m_bScrolling = true;
        CNewGameDialog::AnimateSelectionPanels(this);
        CNewGameDialog::UpdateMenuComponents(this, dir: this->m_ScrollDirection);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F3BF0
// Name: public: virtual void CNewGameDialog::FinishScroll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNewGameDialog::FinishScroll(CNewGameDialog *this)
{
  vgui::AnimationController *AnimationController; // eax
  vgui::Panel *m_pCenterBg; // [esp-8h] [ebp-20h]
  float duration; // [esp+8h] [ebp-10h]
  CNewGameDialog::EScrollDirection animParameter; // [esp+10h] [ebp-8h]

  duration = this->m_ScrollSpeed * 0.25;
  m_pCenterBg = this->m_pCenterBg;
  AnimationController = vgui::GetAnimationController();
  vgui::AnimationController::RunAnimationCommand(
    this: AnimationController,
    panel: m_pCenterBg,
    variable: "alpha",
    targetValue: 255.0,
    startDelaySeconds: 0.0,
    duration,
    interpolator: (vgui::AnimationController::Interpolators_e)0,
    animParameter: 0.0);
  CNewGameDialog::ShiftPanelIndices(this, offset: this->m_ScrollDirection);
  animParameter = this->m_ScrollDirection;
  this->m_bScrolling = false;
  this->m_ScrollCt = 0;
  CNewGameDialog::PostScroll(this, dir: animParameter);
  CNewGameDialog::ContinueScrolling(this);
}

//------------------------------------------------------------------------------
// Address: 0x101F3C80
// Name: public: static void CNewGameDialog::PanelMessageFunc_FinishScroll::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CNewGameDialog::PanelMessageFunc_FinishScroll::InitVar(int a1@<ebp>)
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
  if ( !`CNewGameDialog::PanelMessageFunc_FinishScroll::InitVar'::`2'::bAdded )
  {
    `CNewGameDialog::PanelMessageFunc_FinishScroll::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBonusMapsDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CNewGameDialog");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FinishScroll";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F3D10
// Name: public: static void CNewGameDialog::PanelMessageFunc_StartGame::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CNewGameDialog::PanelMessageFunc_StartGame::InitVar(int a1@<ebp>)
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
  if ( !`CNewGameDialog::PanelMessageFunc_StartGame::InitVar'::`2'::bAdded )
  {
    `CNewGameDialog::PanelMessageFunc_StartGame::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBonusMapsDialog::`vcall'{1120,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CNewGameDialog");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "StartGame";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F3DA0
// Name: public: CNewGameDialog::CNewGameDialog(class vgui::Panel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CNewGameDialog *__thiscall CNewGameDialog::CNewGameDialog(
        CNewGameDialog *this,
        vgui::Panel *parent,
        bool bCommentaryMode)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::Panel *v7; // ebx
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  vgui::Button *v10; // eax
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  vgui::Button *v14; // eax
  vgui::Button *v15; // edi
  vgui::Panel *v16; // eax
  CGameUI *v17; // eax
  vgui::Label *v18; // eax
  vgui::Label *v19; // edi
  vgui::Label *v20; // eax
  vgui::Label *v21; // edi
  vgui::Label *v22; // eax
  vgui::Label *v23; // edi
  vgui::ImagePanel *v24; // eax
  vgui::ImagePanel *v25; // edi
  vgui::CFooterPanel *v26; // eax
  vgui::CFooterPanel *v27; // eax
  signed int v28; // ebx
  char *v29; // edi
  void *v30; // ebx
  CGameUI *v31; // eax
  CBonusMapsDatabase *v32; // eax
  char *m_pszString; // eax
  int v34; // edi
  chapter_t *v35; // ebx
  const char *v36; // ecx
  char *v37; // eax
  char *ModDirectory; // eax
  CGameChapterPanel *v39; // eax
  CGameChapterPanel *v40; // ebx
  int v41; // ecx
  bool v42; // al
  CGameUI *v43; // eax
  CBonusMapsDatabase *v44; // eax
  BonusMapDescription_t *v45; // edi
  void (__thiscall *SetControlVisible)(vgui::EditablePanel *, const char *, bool); // eax
  int v47; // edi
  CBonusMapsDatabase *v48; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CGameChapterPanel **m_pMemory; // ecx
  int v52; // eax
  CGameChapterPanel **v53; // edi
  CGameUI *v54; // eax
  int Wide; // eax
  int v57; // edi
  vgui::Panel **v58; // edx
  int v59; // eax
  int v60; // ecx
  int v61; // eax
  int v62; // ecx
  int Tall; // eax
  chapter_t chapters[32]; // [esp+Ch] [ebp-58Ch] BYREF
  char szFullFileName[260]; // [esp+40Ch] [ebp-18Ch] BYREF
  char chapterName[64]; // [esp+510h] [ebp-88h] BYREF
  char chapterID[32]; // [esp+550h] [ebp-48h] BYREF
  ConVarRef var; // [esp+570h] [ebp-28h] BYREF
  int panelHeight; // [esp+578h] [ebp-20h] BYREF
  int iUnlockedChapter; // [esp+57Ch] [ebp-1Ch]
  int iBonusMap; // [esp+580h] [ebp-18h]
  unsigned int v72; // [esp+584h] [ebp-14h]
  int panelWidth; // [esp+588h] [ebp-10h] BYREF
  CGameChapterPanel *v74; // [esp+58Ch] [ebp-Ch]
  chapter_t *v75; // [esp+590h] [ebp-8h]
  int findHandle; // [esp+594h] [ebp-4h] BYREF
  int chapterIndex; // [esp+5A0h] [ebp+8h]
  chapter_t *bCommentaryModea; // [esp+5A4h] [ebp+Ch]
  bool bCommentaryMode_3; // [esp+5A7h] [ebp+Fh]

  vgui::Frame::Frame(this, parent, panelName: "NewGameDialog", showTaskbarIcon: 1, bPopup: true);
  this->__vftable = (CNewGameDialog_vtbl *)&CNewGameDialog::`vftable';
  if ( `CNewGameDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CNewGameDialog::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CNewGameDialog");
    v4->pfnClassName = CNewGameDialog::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CNewGameDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CNewGameDialog::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CNewGameDialog");
    v5->pfnClassName = CNewGameDialog::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CNewGameDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CNewGameDialog::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CNewGameDialog");
    v6->pfnClassName = CNewGameDialog::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CNewGameDialog::PanelMessageFunc_FinishScroll::InitVar();
  CNewGameDialog::PanelMessageFunc_StartGame::InitVar();
  v7 = nullptr;
  this->m_ChapterPanels.m_Memory.m_pMemory = nullptr;
  this->m_ChapterPanels.m_Memory.m_nAllocationCount = 0;
  this->m_ChapterPanels.m_Memory.m_nGrowSize = 0;
  this->m_ChapterPanels.m_Size = 0;
  this->m_ChapterPanels.m_pElements = nullptr;
  this->m_hSkillSelectionDialog.m_iPanelID = -1;
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 372, tall: 160);
  vgui::Frame::SetSizeable(this, state: false);
  this->m_bCommentaryMode = bCommentaryMode;
  this->m_iSelectedChapter = -1;
  *(_WORD *)&this->m_ActiveTitleIdx = 0;
  this->m_bScrolling = false;
  this->m_ScrollCt = 0;
  this->m_ScrollSpeed = 0.0;
  this->m_ButtonPressed = 0;
  this->m_ScrollDirection = SCROLL_NONE;
  this->m_pCommentaryLabel = nullptr;
  this->m_iBonusSelection = 0;
  this->m_bScrollToFirstBonusMap = false;
  vgui::Frame::SetTitle(this, title: "#GameUI_NewGame", surfaceTitle: true);
  v8 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v8 != nullptr )
    v9 = vgui::Button::Button(
           this: v8,
           parent: this,
           panelName: "Next",
           text: "#gameui_next",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v9 = nullptr;
  this->m_pNextButton = v9;
  v10 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v10 != nullptr )
    v11 = vgui::Button::Button(
            this: v10,
            parent: this,
            panelName: "Prev",
            text: "#gameui_prev",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v11 = nullptr;
  this->m_pPrevButton = v11;
  v12 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v12 != nullptr )
    v13 = vgui::Button::Button(
            this: v12,
            parent: this,
            panelName: "Play",
            text: "#GameUI_Play",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v13 = nullptr;
  this->m_pPlayButton = v13;
  v13->SetCommand(this: v13, a2: "Play");
  v14 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v14 != nullptr )
    v15 = vgui::Button::Button(
            this: v14,
            parent: this,
            panelName: "Cancel",
            text: "#GameUI_Cancel",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v15 = nullptr;
  v15->SetCommand(this: v15, a2: "Close");
  v16 = (vgui::Panel *)MemAlloc_Alloc(nSize: 0x14Cu);
  if ( v16 != nullptr )
    v7 = vgui::Panel::Panel(this: v16, parent: this, panelName: "CenterBG");
  vgui::Panel::MakeReadyForUse(this: v7);
  this->m_pCenterBg = v7;
  v7->SetVisible(this: v7, a2: false);
  v17 = GameUI();
  if ( CGameUI::IsConsoleUI(this: v17) )
  {
    this->m_pNextButton->SetVisible(this: this->m_pNextButton, a2: false);
    this->m_pPrevButton->SetVisible(this: this->m_pPrevButton, a2: false);
    this->m_pPlayButton->SetVisible(this: this->m_pPlayButton, a2: false);
    v15->SetVisible(this: v15, a2: false);
    this->m_pCenterBg->SetPaintBackgroundType(this: this->m_pCenterBg, a2: 2);
    this->m_pCenterBg->SetVisible(this: this->m_pCenterBg, a2: true);
    v18 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
    if ( v18 != nullptr )
      v19 = vgui::Label::Label(this: v18, parent: this, panelName: "ChapterTitleLabel", text: prType);
    else
      v19 = nullptr;
    vgui::Panel::MakeReadyForUse(this: v19);
    this->m_pChapterTitleLabels[0] = v19;
    v19->SetVisible(this: v19, a2: true);
    ((void (__thiscall *)(vgui::Label *, int))this->m_pChapterTitleLabels[0]->SetFgColor)(
      a1: this->m_pChapterTitleLabels[0],
      a2: -1);
    v20 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
    if ( v20 != nullptr )
      v21 = vgui::Label::Label(this: v20, parent: this, panelName: "ChapterTitleLabel2", text: prType);
    else
      v21 = nullptr;
    vgui::Panel::MakeReadyForUse(this: v21);
    this->m_pChapterTitleLabels[1] = v21;
    v21->SetVisible(this: v21, a2: true);
    vgui::Panel::SetAlpha(this: this->m_pChapterTitleLabels[1], alpha: 0);
    ((void (__thiscall *)(vgui::Label *, int))this->m_pChapterTitleLabels[1]->SetFgColor)(
      a1: this->m_pChapterTitleLabels[1],
      a2: -1);
    v22 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
    if ( v22 != nullptr )
      v23 = vgui::Label::Label(
              this: v22,
              parent: this,
              panelName: "BonusSelectionLabel",
              text: "#GameUI_BonusMapsStandard");
    else
      v23 = nullptr;
    vgui::Panel::MakeReadyForUse(this: v23);
    this->m_pBonusSelection = v23;
    v24 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
    if ( v24 != nullptr )
      v25 = vgui::ImagePanel::ImagePanel(this: v24, parent: this, name: "BonusSelectionBorder");
    else
      v25 = nullptr;
    vgui::Panel::MakeReadyForUse(this: v25);
    this->m_pBonusSelectionBorder = v25;
    v26 = (vgui::CFooterPanel *)MemAlloc_Alloc(nSize: 0x2C4u);
    if ( v26 != nullptr )
      v27 = vgui::CFooterPanel::CFooterPanel(this: v26, parent, panelName: "NewGameFooter");
    else
      v27 = nullptr;
    this->m_pFooter = v27;
    vgui::CFooterPanel::AddNewButtonLabel(this: v27, text: "#GameUI_Play", icon: "#GameUI_Icons_A_BUTTON");
    vgui::CFooterPanel::AddNewButtonLabel(this: this->m_pFooter, text: "#GameUI_Close", icon: "#GameUI_Icons_B_BUTTON");
  }
  else
  {
    this->m_pFooter = nullptr;
  }
  findHandle = -1;
  v28 = 0;
  chapterIndex = 0;
  v29 = (char *)g_pFullFileSystem->FindFirst(this: g_pFullFileSystem, a2: "cfg/chapter*.cfg", a3: &findHandle);
  if ( v29 != nullptr )
  {
    bCommentaryModea = chapters;
    do
    {
      if ( v28 >= 32 )
        break;
      V_snprintf(pDest: szFullFileName, maxLen: 0x104u, pFormat: "cfg/%s", v29);
      v30 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: szFullFileName, a3: "rb", a4: "MOD");
      if ( v30 != nullptr )
      {
        if ( g_pFullFileSystem->Size_2(this: &g_pFullFileSystem->IBaseFileSystem, a2: v30) != 0 )
        {
          V_strncpy(pDest: bCommentaryModea->filename, pSrc: v29, maxLen: 32);
          ++chapterIndex;
          ++bCommentaryModea;
        }
        g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v30);
      }
      v28 = chapterIndex;
      v29 = (char *)g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: findHandle);
    }
    while ( v29 != nullptr );
  }
  bCommentaryMode_3 = false;
  v31 = GameUI();
  if ( CGameUI::IsConsoleUI(this: v31) && !this->m_bCommentaryMode )
  {
    v32 = BonusMapsDatabase();
    bCommentaryMode_3 = CBonusMapsDatabase::BonusesUnlocked(this: v32);
  }
  qsort(base: chapters, num: v28, width: 0x20u, comp: (int (__cdecl *)(const void *, const void *))ChapterSortFunc);
  ConVarRef::ConVarRef(this: &var, pName: "sv_unlockedchapters");
  if ( bCommentaryMode_3 )
    var.m_pConVar->SetValue_2(this: var.m_pConVar, a2: 15);
  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&var) )
    m_pszString = var.m_pConVarState->m_Value.m_pszString;
  else
    m_pszString = "1";
  iUnlockedChapter = atoi(nptr: m_pszString);
  if ( v28 > 0 )
  {
    v34 = 1;
    v35 = chapters;
    findHandle = 1;
    v75 = chapters;
    while ( 1 )
    {
      memset(chapterID, 0, sizeof(chapterID));
      sscanf(string: v35->filename, format: "chapter%s", chapterID);
      v37 = V_stristr(a1: v36, a2: v35->filename, pStr: chapterID, pSearch: ".cfg");
      if ( v37 != nullptr )
        *v37 = 0;
      ModDirectory = COM_GetModDirectory();
      V_snprintf(pDest: chapterName, maxLen: 0x40u, pFormat: "#%s_Chapter%s_Title", ModDirectory, chapterID);
      V_snprintf(pDest: szFullFileName, maxLen: 0x104u, pFormat: "%s", v35->filename);
      v39 = (CGameChapterPanel *)MemAlloc_Alloc(nSize: 0x2CCu);
      if ( v39 != nullptr )
      {
        v40 = CGameChapterPanel::CGameChapterPanel(
                this: v39,
                parent: this,
                name: nullptr,
                chapterName,
                chapterIndex: v34 - 1,
                chapterNumber: chapterID,
                chapterConfigFile: szFullFileName,
                bCommentary: this->m_bCommentaryMode);
        v74 = v40;
      }
      else
      {
        v74 = nullptr;
        v40 = nullptr;
      }
      vgui::Panel::MakeReadyForUse(this: v40);
      v40->SetVisible(this: v40, a2: false);
      v41 = iUnlockedChapter;
      if ( iUnlockedChapter <= 0 )
        v41 = 1;
      v42 = false;
      if ( this->m_bCommentaryMode )
      {
        v42 = v41 <= v34;
      }
      else if ( v41 < v34 )
      {
        v42 = v34 != 0;
      }
      v40->SetEnabled(this: v40, a2: !v42);
      v43 = GameUI();
      if ( CGameUI::IsConsoleUI(this: v43) && bCommentaryMode_3 )
      {
        iBonusMap = 0;
        v44 = BonusMapsDatabase();
        if ( CBonusMapsDatabase::BonusCount(this: v44) > 0 )
        {
          v72 = 0;
          do
          {
            v45 = &BonusMapsDatabase()->m_BonusMaps.m_Memory.m_pMemory[v72 / 0x388];
            if ( _V_stricmp(s1: v45->szChapterName, s2: szFullFileName) == 0 && !v45->bLocked )
            {
              SetControlVisible = v40->SetControlVisible;
              v40->m_bHasBonus = true;
              SetControlVisible(this: v40, a2: "HasBonusLabel", a3: true);
            }
            v72 += 904;
            v47 = ++iBonusMap;
            v48 = BonusMapsDatabase();
          }
          while ( v47 < CBonusMapsDatabase::BonusCount(this: v48) );
        }
      }
      m_Size = this->m_ChapterPanels.m_Size;
      m_nAllocationCount = this->m_ChapterPanels.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_ChapterPanels,
          num: m_Size - m_nAllocationCount + 1);
      ++this->m_ChapterPanels.m_Size;
      m_pMemory = this->m_ChapterPanels.m_Memory.m_pMemory;
      v52 = this->m_ChapterPanels.m_Size - m_Size - 1;
      this->m_ChapterPanels.m_pElements = m_pMemory;
      if ( v52 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v52);
      v53 = &this->m_ChapterPanels.m_Memory.m_pMemory[m_Size];
      if ( v53 != nullptr )
        *v53 = v74;
      ++v75;
      if ( findHandle++ >= chapterIndex )
        break;
      v35 = v75;
      v34 = findHandle;
    }
  }
  v54 = GameUI();
  CGameUI::IsConsoleUI(this: v54);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource/NewGameDialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  this->m_PanelIndex[0] = -1;
  this->m_PanelIndex[1] = -1;
  this->m_PanelIndex[2] = -1;
  this->m_PanelIndex[3] = -1;
  this->m_PanelIndex[4] = -1;
  if ( this->m_ChapterPanels.m_Size != 0 )
  {
    panelWidth = vgui::Panel::GetWide(this: *this->m_ChapterPanels.m_Memory.m_pMemory) + 16;
    Wide = vgui::Panel::GetWide(this);
    v57 = panelWidth;
    v58 = this->m_ChapterPanels.m_Memory.m_pMemory;
    v59 = (Wide - panelWidth) / 2 + 8;
    this->m_PanelXPos[2] = v59;
    v60 = v59;
    v61 = v57 + v59;
    v62 = v60 - v57;
    this->m_PanelXPos[3] = v61;
    this->m_PanelXPos[4] = v61;
    this->m_PanelXPos[1] = v62;
    this->m_PanelXPos[0] = v62;
    this->m_PanelAlpha[0] = 0.0;
    this->m_PanelAlpha[1] = 255.0;
    this->m_PanelAlpha[2] = 255.0;
    this->m_PanelAlpha[3] = 255.0;
    this->m_PanelAlpha[4] = 0.0;
    vgui::Panel::GetSize(this: *v58, wide: &panelWidth, tall: &panelHeight);
    vgui::Panel::SetWide(this: this->m_pCenterBg, wide: panelWidth + 16);
    Tall = vgui::Panel::GetTall(this: this->m_pCenterBg);
    vgui::Panel::SetPos(
      this: this->m_pCenterBg,
      x: this->m_PanelXPos[2] - 8,
      y: panelHeight + this->m_PanelYPos[2] - Tall + 8);
    ((void (__thiscall *)(vgui::Panel *, int))this->m_pCenterBg->SetBgColor)(a1: this->m_pCenterBg, a2: -16747586);
    CNewGameDialog::SetSelectedChapterIndex(this, index: 0);
  }
  else
  {
    CNewGameDialog::UpdateMenuComponents(this, dir: SCROLL_NONE);
  }
  return this;
}
