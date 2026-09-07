// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/savegamebrowserdialog.cpp
// Functions: 63
// ============================================================

#include "game\client\cstrike15\gameui\savegamebrowserdialog.h"

//------------------------------------------------------------------------------
// Address: 0x101FEB50
// Name: public: static char const __near * CGameSavePanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CGameSavePanel::GetPanelClassName()
{
  return "CGameSavePanel";
}

//------------------------------------------------------------------------------
// Address: 0x101FEB60
// Name: public: static char const __near * CSaveGameBrowserDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSaveGameBrowserDialog::GetPanelClassName()
{
  return "CSaveGameBrowserDialog";
}

//------------------------------------------------------------------------------
// Address: 0x101FEB70
// Name: public: virtual CGameSavePanel::~CGameSavePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameSavePanel::~CGameSavePanel(CGameSavePanel *this)
{
  vgui::ImagePanel *m_pLevelPicBorder; // ecx
  vgui::ImagePanel *m_pLevelPic; // ecx
  vgui::Label *m_pChapterTitle; // ecx
  vgui::Label *m_pTime; // ecx
  vgui::Label *m_pElapsedTime; // ecx
  vgui::Label *m_pType; // ecx

  m_pLevelPicBorder = this->m_pLevelPicBorder;
  this->__vftable = (CGameSavePanel_vtbl *)&CGameSavePanel::`vftable';
  if ( m_pLevelPicBorder != nullptr )
    ((void (__thiscall *)(vgui::ImagePanel *, int))m_pLevelPicBorder->dtr_Panel)(a1: m_pLevelPicBorder, a2: 1);
  m_pLevelPic = this->m_pLevelPic;
  if ( m_pLevelPic != nullptr )
    ((void (__thiscall *)(vgui::ImagePanel *, int))m_pLevelPic->dtr_Panel)(a1: m_pLevelPic, a2: 1);
  m_pChapterTitle = this->m_pChapterTitle;
  if ( m_pChapterTitle != nullptr )
    ((void (__thiscall *)(vgui::Label *, int))m_pChapterTitle->dtr_Panel)(a1: m_pChapterTitle, a2: 1);
  m_pTime = this->m_pTime;
  if ( m_pTime != nullptr )
    ((void (__thiscall *)(vgui::Label *, int))m_pTime->dtr_Panel)(a1: m_pTime, a2: 1);
  m_pElapsedTime = this->m_pElapsedTime;
  if ( m_pElapsedTime != nullptr )
    ((void (__thiscall *)(vgui::Label *, int))m_pElapsedTime->dtr_Panel)(a1: m_pElapsedTime, a2: 1);
  m_pType = this->m_pType;
  if ( m_pType != nullptr )
    ((void (__thiscall *)(vgui::Label *, int))m_pType->dtr_Panel)(a1: m_pType, a2: 1);
  vgui::EditablePanel::~EditablePanel(this);
}

//------------------------------------------------------------------------------
// Address: 0x101FEC10
// Name: public: void CGameSavePanel::SetDescription(struct SaveGameDescription_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameSavePanel::SetDescription(CGameSavePanel *this, SaveGameDescription_t *pDesc)
{
  const char *v3; // ecx
  char *v4; // eax
  const char *v5; // eax
  char *v6; // eax
  char szChapterImage[256]; // [esp+Ch] [ebp-100h] BYREF

  qmemcpy(&this->m_SaveInfo, pDesc, sizeof(this->m_SaveInfo));
  this->m_pChapterTitle->SetText(this: this->m_pChapterTitle, a2: this->m_SaveInfo.szComment);
  this->m_pTime->SetText(this: this->m_pTime, a2: this->m_SaveInfo.szFileTime);
  this->m_pElapsedTime->SetText(this: this->m_pElapsedTime, a2: this->m_SaveInfo.szElapsedTime);
  this->m_pType->SetText(this: this->m_pType, a2: this->m_SaveInfo.szType);
  v4 = V_stristr(a1: v3, a2: (const char *)this, pStr: this->m_SaveInfo.szComment, pSearch: "chapter");
  if ( v4 != nullptr )
  {
    v5 = _V_strlower(start: v4);
    V_snprintf(pDest: szChapterImage, maxLen: 0x100u, pFormat: "chapters/%s", v5);
    v6 = _V_strrchr(s: szChapterImage, c: 95);
    if ( v6 != nullptr )
      *v6 = 0;
    this->m_pLevelPic->SetImage(this: this->m_pLevelPic, a2: szChapterImage);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FED00
// Name: private: void CSaveGameBrowserDialog::ShowNoSaveGameUI(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameBrowserDialog::ShowNoSaveGameUI(CSaveGameBrowserDialog *this)
{
  vgui::Panel *ChildByName; // eax
  void *v3; // edi
  void (__stdcall *v4)(const char *); // edx
  vgui::Panel *v5; // eax
  vgui::Panel *v6; // eax

  ChildByName = vgui::Panel::FindChildByName(this, childName: "NoSavesLabel", recurseDown: false);
  v3 = __RTDynamicCast(
         inptr: ChildByName,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &vgui::Label `RTTI Type Descriptor',
         isReference: 0);
  if ( v3 != nullptr )
  {
    v4 = *(void (__stdcall **)(const char *))(*(_DWORD *)v3 + 848);
    if ( (*((_BYTE *)this + 1132) & 2) != 0 )
      v4(a1: "#GameUI_SaveGame_CorruptFile");
    else
      v4(a1: "#GameUI_NoSaveGamesToDisplay");
    (*(void (__thiscall **)(void *, int))(*(_DWORD *)v3 + 132))(a1: v3, a2: 1);
  }
  if ( this->m_pCenterBg != nullptr )
    this->m_pCenterBg->SetVisible(this: this->m_pCenterBg, a2: false);
  v5 = vgui::Panel::FindChildByName(this, childName: "LeftArrow", recurseDown: false);
  if ( v5 != nullptr )
    v5->SetVisible(this: v5, a2: false);
  v6 = vgui::Panel::FindChildByName(this, childName: "RightArrow", recurseDown: false);
  if ( v6 != nullptr )
    v6->SetVisible(this: v6, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x101FEDC0
// Name: public: virtual void CSaveGameBrowserDialog::CloseAfterSave(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameBrowserDialog::CloseAfterSave(CSaveGameBrowserDialog *this)
{
  this->OnCommand(this, a2: "CloseAndSelectResume");
}

//------------------------------------------------------------------------------
// Address: 0x101FEDD0
// Name: public: virtual void CSaveGameBrowserDialog::OnClose(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameBrowserDialog::OnClose(CSaveGameBrowserDialog *this)
{
  CCStrike15BasePanel *v2; // eax

  *((_BYTE *)this + 1132) |= 4u;
  v2 = BasePanel();
  CBaseModPanel::RunCloseAnimation(this: v2, animName: "CloseNewGameDialog_OpenMainMenu");
  vgui::Frame::OnClose(this);
}

//------------------------------------------------------------------------------
// Address: 0x101FEE00
// Name: public: virtual void CSaveGameBrowserDialog::PaintBackground(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameBrowserDialog::PaintBackground(CSaveGameBrowserDialog *this)
{
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // edx
  int wide; // [esp+10h] [ebp-10h] BYREF
  int tall; // [esp+14h] [ebp-Ch] BYREF
  Color col; // [esp+18h] [ebp-8h] BYREF
  Color darkColor; // [esp+1Ch] [ebp-4h]

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
  darkColor = (Color)(unsigned __int8)(int)(float)((float)col._color[0] * 0.69999999);
  darkColor._color[1] = (int)(float)((float)col._color[1] * 0.69999999);
  darkColor._color[3] = col._color[3];
  DrawSetColor = g_pVGuiSurface->DrawSetColor;
  darkColor._color[2] = (int)(float)((float)col._color[2] * 0.69999999);
  ((void (__thiscall *)(_DWORD, _DWORD))DrawSetColor)(a1: g_pVGuiSurface, a2: darkColor);
  g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: 8, a3: 32, a4: wide - 8, a5: tall - 8);
}

//------------------------------------------------------------------------------
// Address: 0x101FEEF0
// Name: protected: bool CSaveGameBrowserDialog::ParseSaveData(char const __near *,char const __near *,struct SaveGameDescription_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CSaveGameBrowserDialog::ParseSaveData@<al>(
        CSaveGameBrowserDialog *this@<ecx>,
        int a2@<esi>,
        char *pszFileName,
        char *pszShortName,
        SaveGameDescription_t *save)
{
  unsigned __int8 *v5; // ebx
  void *v6; // esi
  int v8; // kr00_4
  int v9; // ebx
  int v10; // esi
  int v11; // ebx
  bool v12; // zf
  vgui::ILocalize_vtbl *v13; // esi
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int (__thiscall *ConvertUnicodeToANSI)(ILocalize *, const wchar_t *, char *, int); // eax
  char *v18; // eax
  char *v19; // esi
  int v20; // eax
  int v21; // eax
  int v22; // esi
  _BYTE *v23; // eax
  int v24; // [esp-1Eh] [ebp-118h]
  char pSrc[6]; // [esp+0h] [ebp-FAh] BYREF
  char szComment[80]; // [esp+6h] [ebp-F4h] BYREF
  char szMapName[32]; // [esp+56h] [ebp-A4h] BYREF
  char szFileTime[32]; // [esp+76h] [ebp-84h] BYREF
  wchar_t buf[20]; // [esp+96h] [ebp-64h] BYREF
  wchar_t wzHours[6]; // [esp+BEh] [ebp-3Ch] BYREF
  char szElapsedTime[32]; // [esp+CAh] [ebp-30h] BYREF
  wchar_t wzSecs[4]; // [esp+EAh] [ebp-10h] BYREF
  wchar_t wzMins[4]; // [esp+F2h] [ebp-8h] BYREF
  BOOL seconds; // [esp+106h] [ebp+Ch]
  int secondsa; // [esp+106h] [ebp+Ch]

  v5 = (unsigned __int8 *)pszFileName;
  if ( pszFileName == nullptr || pszShortName == nullptr )
    return 0;
  *(_WORD *)pSrc = HIWORD(a2);
  V_strncpy(pDest: save->szShortName, pSrc: pszShortName, maxLen: 64);
  V_strncpy(pDest: save->szFileName, pSrc: pszFileName, maxLen: 128);
  v6 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: pszFileName, a3: "rb", a4: "MOD");
  if ( v6 == nullptr )
    return 0;
  save->iSize = g_pFullFileSystem->Size_2(this: &g_pFullFileSystem->IBaseFileSystem, a2: v6);
  seconds = SaveReadNameAndComment(f: v6, name: szMapName, comment: szComment);
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v6);
  if ( !seconds )
    return 0;
  V_strncpy(pDest: save->szMapName, pSrc: szMapName, maxLen: 32);
  v8 = strlen(szComment);
  V_strncpy(pDest: szElapsedTime, pSrc: "??", maxLen: 32);
  if ( v8 >= 6 )
  {
    V_strncpy(pDest: szElapsedTime, pSrc: &pSrc[v8], maxLen: 7);
    szElapsedTime[6] = 0;
    v9 = atoi(nptr: szElapsedTime);
    secondsa = atoi(nptr: &szElapsedTime[4]);
    v10 = v9 / 60;
    v24 = v9 / 60;
    v11 = v9 % 60;
    _snwprintf(string: wzHours, count: 0xCu, format: L"%d", v24);
    _snwprintf(string: wzMins, count: 8u, format: L"%d", v11);
    _snwprintf(string: wzSecs, count: 8u, format: L"%d", secondsa);
    v12 = v10 == 0;
    v13 = g_pVGuiLocalize->__vftable;
    if ( v12 )
    {
      if ( v11 != 0 )
      {
        v15 = ((int (__stdcall *)(const char *, int, wchar_t *))v13->Find)(
                a1: "#GameUI_LoadDialog_Min_Sec",
                a2: 2,
                a3: wzMins);
        ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v13->ConstructString_3)(
          a1: g_pVGuiLocalize,
          a2: buf,
          a3: 40,
          a4: v15);
      }
      else
      {
        v16 = ((int (__stdcall *)(const char *, int, wchar_t *))v13->Find)(
                a1: "#GameUI_LoadDialog_Sec",
                a2: 1,
                a3: wzSecs);
        ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v13->ConstructString_3)(
          a1: g_pVGuiLocalize,
          a2: buf,
          a3: 40,
          a4: v16);
      }
    }
    else
    {
      v14 = ((int (__stdcall *)(const char *, int, wchar_t *))v13->Find)(
              a1: "#GameUI_LoadDialog_Hr_Min",
              a2: 2,
              a3: wzHours);
      ((void (__cdecl *)(vgui::ILocalize *, wchar_t *, int, int))v13->ConstructString_3)(
        a1: g_pVGuiLocalize,
        a2: buf,
        a3: 40,
        a4: v14);
    }
    ConvertUnicodeToANSI = g_pVGuiLocalize->ConvertUnicodeToANSI;
    *(_WORD *)pSrc = 0;
    ((void (__thiscall *)(vgui::ILocalize *, wchar_t *))ConvertUnicodeToANSI)(a1: g_pVGuiLocalize, a2: buf);
    v18 = V_stristr(a1: szComment, a2: (const char *)v11, pStr: szComment, pSearch: " ");
    v5 = (unsigned __int8 *)pszFileName;
    if ( v18 != nullptr )
      *v18 = 0;
  }
  v19 = (char *)prType;
  strstr(str1: v5, str2: "quick");
  if ( v20 != 0 )
  {
    v19 = "#GameUI_QuickSave";
  }
  else
  {
    strstr(str1: v5, str2: "autosave");
    if ( v21 != 0 )
      v19 = "#GameUI_AutoSave";
  }
  V_strncpy(pDest: save->szType, pSrc: v19, maxLen: 64);
  V_strncpy(pDest: save->szComment, pSrc: szComment, maxLen: 80);
  V_strncpy(pDest: save->szElapsedTime, pSrc: szElapsedTime, maxLen: 32);
  v22 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: (const char *)v5, a3: nullptr);
  g_pFullFileSystem->FileTimeToString(this: g_pFullFileSystem, a2: szFileTime, a3: 32, a4: v22);
  strstr(str1: (unsigned __int8 *)szFileTime, str2: "\n");
  if ( v23 != nullptr )
    *v23 = 0;
  V_strncpy(pDest: save->szFileTime, pSrc: szFileTime, maxLen: 32);
  save->iTimestamp = v22;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101FF220
// Name: public: virtual void CSaveGameBrowserDialog::SortSaveGames(struct SaveGameDescription_t __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameBrowserDialog::SortSaveGames(
        CSaveGameBrowserDialog *this,
        SaveGameDescription_t *pSaves,
        unsigned int nNumSaves)
{
  qsort(base: pSaves, num: nNumSaves, width: 0x1B8u, comp: CBaseSaveGameDialog::SaveGameSortFunc);
}

//------------------------------------------------------------------------------
// Address: 0x101FF260
// Name: public: virtual struct vgui::PanelMessageMap __near * CGameSavePanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CGameSavePanel::GetMessageMap(CGameSavePanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CGameSavePanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CGameSavePanel::GetMessageMap'::`2'::s_pMap;
  `CGameSavePanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CGameSavePanel");
  `CGameSavePanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FF290
// Name: public: virtual struct PanelAnimationMap __near * CGameSavePanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CGameSavePanel::GetAnimMap(CGameSavePanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CGameSavePanel");
}

//------------------------------------------------------------------------------
// Address: 0x101FF2A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CGameSavePanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CGameSavePanel::GetKBMap(CGameSavePanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CGameSavePanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CGameSavePanel::GetKBMap'::`2'::s_pMap;
  `CGameSavePanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CGameSavePanel");
  `CGameSavePanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101FF2D0
// Name: public: CGameSavePanel::CGameSavePanel(class CSaveGameBrowserDialog __near *,struct SaveGameDescription_t __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CGameSavePanel *__thiscall CGameSavePanel::CGameSavePanel(
        CGameSavePanel *this,
        CSaveGameBrowserDialog *parent,
        SaveGameDescription_t *pSaveDesc,
        bool bCommandPanel)
{
  vgui::PanelMessageMap *v5; // esi
  PanelAnimationMap *v6; // esi
  vgui::PanelKeyBindingMap *v7; // esi
  SaveGameDescription_t *v8; // esi
  vgui::ImagePanel *v9; // eax
  vgui::ImagePanel *v10; // esi
  vgui::ImagePanel *v11; // eax
  vgui::ImagePanel *v12; // esi
  vgui::Label *v13; // eax
  vgui::Label *v14; // eax
  vgui::Label *v15; // eax
  vgui::Label *v16; // eax
  vgui::Label *v17; // eax
  vgui::Label *v18; // eax
  vgui::Label *v19; // eax
  const char *v20; // ecx
  vgui::Label *v21; // eax
  char *v22; // eax
  const char *v23; // eax
  char *v24; // eax
  KeyValues *Key; // esi
  CGameUI *v26; // eax
  vgui::MenuItem *v27; // eax
  KeyValues *ConsoleControlSettings; // eax
  int Tall; // esi
  int v30; // eax
  int Wide; // eax
  vgui::Panel::PanelMessageFunc_OnNavigateFrom *v33; // [esp-4h] [ebp-114h]
  char szChapterImage[256]; // [esp+Ch] [ebp-104h] BYREF
  int px; // [esp+10Ch] [ebp-4h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent, panelName: "SaveGamePanel");
  this->__vftable = (CGameSavePanel_vtbl *)&CGameSavePanel::`vftable';
  if ( `CGameSavePanel::ChainToMap'::`2'::chained == 0 )
  {
    `CGameSavePanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CGameSavePanel");
    v5->pfnClassName = CGameSavePanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CGameSavePanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CGameSavePanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CGameSavePanel");
    v6->pfnClassName = CGameSavePanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CGameSavePanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CGameSavePanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CGameSavePanel");
    v7->pfnClassName = CGameSavePanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  v8 = pSaveDesc;
  this->m_TextColor = 0;
  this->m_DisabledColor = 0;
  this->m_SelectedColor = 0;
  this->m_FillColor = 0;
  qmemcpy(&this->m_SaveInfo, v8, sizeof(this->m_SaveInfo));
  this->m_bNewSavePanel = bCommandPanel;
  v9 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v9 != nullptr )
    v10 = vgui::ImagePanel::ImagePanel(this: v9, parent: this, name: "LevelPicBorder");
  else
    v10 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v10);
  this->m_pLevelPicBorder = v10;
  v11 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v11 != nullptr )
    v12 = vgui::ImagePanel::ImagePanel(this: v11, parent: this, name: "LevelPic");
  else
    v12 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v12);
  this->m_pLevelPic = v12;
  v13 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v13 != nullptr )
    v14 = vgui::Label::Label(this: v13, parent: this, panelName: "ChapterLabel", text: this->m_SaveInfo.szComment);
  else
    v14 = nullptr;
  this->m_pChapterTitle = v14;
  v15 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v15 != nullptr )
    v16 = vgui::Label::Label(this: v15, parent: this, panelName: "TimeLabel", text: this->m_SaveInfo.szFileTime);
  else
    v16 = nullptr;
  this->m_pTime = v16;
  v17 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v17 != nullptr )
    v18 = vgui::Label::Label(this: v17, parent: this, panelName: "ElapsedLabel", text: this->m_SaveInfo.szElapsedTime);
  else
    v18 = nullptr;
  this->m_pElapsedTime = v18;
  v19 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v19 != nullptr )
    v21 = vgui::Label::Label(this: v19, parent: this, panelName: "TypeLabel", text: this->m_SaveInfo.szType);
  else
    v21 = nullptr;
  this->m_pType = v21;
  v22 = V_stristr(a1: v20, a2: (const char *)this, pStr: this->m_SaveInfo.szComment, pSearch: "chapter");
  if ( v22 != nullptr )
  {
    v23 = _V_strlower(start: v22);
    V_snprintf(pDest: szChapterImage, maxLen: 0x100u, pFormat: "chapters/%s", v23);
    v24 = _V_strrchr(s: szChapterImage, c: 95);
    if ( v24 != nullptr )
      *v24 = 0;
    ((void (__stdcall *)(char *))this->m_pLevelPic->SetImage)(a1: szChapterImage);
  }
  else
  {
    ((void (__stdcall *)(const char *))this->m_pLevelPic->SetImage)(a1: "ui_logo");
  }
  Key = nullptr;
  v26 = GameUI();
  if ( CGameUI::IsConsoleUI(this: v26) )
  {
    v27 = (vgui::MenuItem *)BasePanel();
    ConsoleControlSettings = (KeyValues *)CBaseModPanel::GetConsoleControlSettings(this: v27);
    Key = KeyValues::FindKey(this: ConsoleControlSettings, keyName: "SaveGamePanel.res", bCreate: false);
  }
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "Resource/SaveGamePanel.res",
    pathID: nullptr,
    pKeyValues: Key,
    pConditions: nullptr);
  vgui::Panel::GetPos(this: this->m_pLevelPicBorder, x: &px, y: (int *)&parent);
  Tall = vgui::Panel::GetTall(this: this->m_pType);
  v30 = vgui::Panel::GetTall(this: this->m_pLevelPicBorder);
  v33 = &parent->m_OnNavigateFrom_register + Tall + v30;
  Wide = vgui::Panel::GetWide(this: this->m_pLevelPicBorder);
  vgui::Panel::SetSize(this, wide: Wide, tall: (int)v33);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101FF610
// Name: public: virtual void CGameSavePanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGameSavePanel::ApplySchemeSettings(CGameSavePanel *this, float pScheme)
{
  vgui::IScheme *v2; // edi
  Color *(__thiscall *v3)(vgui::IScheme *, Color *, const char *, Color); // eax
  Color v5; // ecx
  Color *(__thiscall *GetColor)(vgui::IScheme *, Color *, const char *, Color); // edx
  Color *(__thiscall *v7)(vgui::IScheme *, Color *, const char *, Color); // edx
  vgui::ImagePanel *m_pLevelPic; // ecx
  double ScaleAmount; // st7
  int Wide; // ebx
  int Tall; // eax
  vgui::ImagePanel *m_pLevelPicBorder; // ecx
  int borderX; // [esp+Ch] [ebp-Ch] BYREF
  int borderY; // [esp+10h] [ebp-8h] BYREF
  int borderTall; // [esp+14h] [ebp-4h]

  v2 = (vgui::IScheme *)LODWORD(pScheme);
  v3 = *(Color *(__thiscall **)(vgui::IScheme *, Color *, const char *, Color))(*(_DWORD *)LODWORD(pScheme) + 20);
  borderTall = -1;
  v5 = *(Color *)((int (__thiscall *)(_DWORD, float *, const char *, int))v3)(
                   a1: LODWORD(pScheme),
                   a2: &pScheme,
                   a3: "NewGame.TextColor",
                   a4: -1);
  pScheme = NAN;
  this->m_TextColor = v5;
  this->m_FillColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, float *, const char *, int))v2->GetColor)(
                                  a1: v2,
                                  a2: &pScheme,
                                  a3: "NewGame.FillColor",
                                  a4: -1);
  GetColor = v2->GetColor;
  pScheme = 6.0185307e-36;
  this->m_DisabledColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, float *, const char *, int))GetColor)(
                                      a1: v2,
                                      a2: &pScheme,
                                      a3: "NewGame.DisabledColor",
                                      a4: 83886079);
  v7 = v2->GetColor;
  pScheme = NAN;
  this->m_SelectedColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, float *, const char *, int))v7)(
                                      a1: v2,
                                      a2: &pScheme,
                                      a3: "NewGame.SelectionColor",
                                      a4: -1);
  if ( this->m_bNewSavePanel )
  {
    this->m_pTime->SetVisible(this: this->m_pTime, a2: false);
    this->m_pElapsedTime->SetVisible(this: this->m_pElapsedTime, a2: false);
    this->m_pType->SetVisible(this: this->m_pType, a2: false);
  }
  ((void (__thiscall *)(vgui::Label *, _DWORD))this->m_pChapterTitle->SetFgColor)(
    a1: this->m_pChapterTitle,
    a2: *(_DWORD *)&this->m_TextColor);
  ((void (__thiscall *)(vgui::Label *, _DWORD))this->m_pTime->SetFgColor)(
    a1: this->m_pTime,
    a2: *(_DWORD *)&this->m_TextColor);
  ((void (__thiscall *)(vgui::Label *, _DWORD))this->m_pElapsedTime->SetFgColor)(
    a1: this->m_pElapsedTime,
    a2: *(_DWORD *)&this->m_TextColor);
  m_pLevelPic = this->m_pLevelPic;
  pScheme = -1.7014118e38;
  vgui::ProgressBar::SetBarInset(this: (vgui::ProgressBar *)m_pLevelPic, pixels: -16777216);
  pScheme = -1.7014118e38;
  vgui::ProgressBar::SetBarInset(this: (vgui::ProgressBar *)this->m_pLevelPicBorder, pixels: -16777216);
  if ( this->m_bNewSavePanel )
  {
    ScaleAmount = vgui::ImagePanel::GetScaleAmount(this: this->m_pLevelPic);
    pScheme = ScaleAmount;
    if ( ScaleAmount <= 0.0 )
      pScheme = 1.0;
    Wide = vgui::Panel::GetWide(this: this->m_pLevelPicBorder);
    Tall = vgui::Panel::GetTall(this: this->m_pLevelPicBorder);
    m_pLevelPicBorder = this->m_pLevelPicBorder;
    borderTall = Tall;
    vgui::Panel::GetPos(this: m_pLevelPicBorder, x: &borderX, y: &borderY);
    vgui::Panel::SetPos(
      this: this->m_pLevelPic,
      x: borderX + (Wide - (int)(float)(pScheme * 64.0)) / 2,
      y: borderY + (borderTall - (int)(float)(pScheme * 64.0)) / 2);
    pScheme = 0.0;
    vgui::ProgressBar::SetBarInset(this: (vgui::ProgressBar *)this->m_pLevelPic, pixels: 0);
  }
  vgui::Panel::ApplySchemeSettings(this, pScheme: (int)v2);
}

//------------------------------------------------------------------------------
// Address: 0x101FF830
// Name: public: virtual void CSaveGameBrowserDialog::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameBrowserDialog::ApplySettings(CSaveGameBrowserDialog *this, KeyValues *inResourceData)
{
  int Int; // eax
  int v4; // eax
  vgui::Panel *m_pCenterBg; // ecx

  vgui::Frame::ApplySettings(this, inResourceData);
  Int = KeyValues::GetInt(this: inResourceData, keyName: "chapterypos", defaultValue: 20);
  this->m_PanelYPos[0] = Int;
  this->m_PanelYPos[1] = Int;
  this->m_PanelYPos[2] = Int;
  this->m_PanelYPos[3] = Int;
  this->m_PanelYPos[4] = Int;
  v4 = KeyValues::GetInt(this: inResourceData, keyName: "centerbgtall", defaultValue: 0);
  m_pCenterBg = this->m_pCenterBg;
  this->m_nCenterBgTallDefault = v4;
  vgui::Panel::SetTall(this: m_pCenterBg, tall: v4);
  this->m_ScrollSpeedSlow = KeyValues::GetFloat(this: inResourceData, keyName: "scrollslow", defaultValue: 0.0);
  this->m_ScrollSpeedFast = KeyValues::GetFloat(this: inResourceData, keyName: "scrollfast", defaultValue: 0.0);
  this->m_ScrollSpeed = this->m_ScrollSpeedSlow;
}

//------------------------------------------------------------------------------
// Address: 0x101FF8E0
// Name: private: void CSaveGameBrowserDialog::UpdateMenuComponents(enum CSaveGameBrowserDialog::EScrollDirection)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSaveGameBrowserDialog::UpdateMenuComponents(
        CSaveGameBrowserDialog *this@<ecx>,
        int a2@<esi>,
        CSaveGameBrowserDialog::EScrollDirection dir)
{
  vgui::Panel *ChildByName; // esi
  vgui::Panel *v5; // edi
  int centerIdx; // [esp+8h] [ebp-4h]

  centerIdx = 2;
  if ( dir == SCROLL_LEFT )
  {
    centerIdx = 3;
  }
  else if ( dir == SCROLL_RIGHT )
  {
    centerIdx = 1;
  }
  ChildByName = vgui::Panel::FindChildByName(this, childName: "LeftArrow", recurseDown: false);
  v5 = vgui::Panel::FindChildByName(this, childName: "RightArrow", recurseDown: false);
  if ( ChildByName != nullptr )
  {
    ((void (__thiscall *)(vgui::Panel *, int, int))ChildByName->SetVisible)(a1: ChildByName, a2: 1, a3: a2);
    ((void (__thiscall *)(vgui::Panel *))ChildByName->SetFgColor)(a1: ChildByName);
  }
  if ( v5 != nullptr )
  {
    v5->SetVisible(this: v5, a2: true);
    if ( this->m_PanelIndex[centerIdx + 1] == -1 )
      ((void (__thiscall *)(vgui::Panel *, int))v5->SetFgColor)(a1: v5, a2: 1082163328);
    else
      ((void (__thiscall *)(vgui::Panel *, int))v5->SetFgColor)(a1: v5, a2: -1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101FF9E0
// Name: private: bool CSaveGameBrowserDialog::IsValidPanel(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSaveGameBrowserDialog::IsValidPanel(CSaveGameBrowserDialog *this, int idx)
{
  return idx >= 0 && idx < this->m_SavePanels.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x101FFA00
// Name: private: void CSaveGameBrowserDialog::LayoutPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameBrowserDialog::LayoutPanels(CSaveGameBrowserDialog *this)
{
  vgui::Panel *ChildByName; // eax
  int v3; // edi
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  vgui::Panel **m_pMemory; // eax
  vgui::Panel *m_pCenterBg; // ecx
  void (__thiscall *SetBgColor)(vgui::Panel *, Color); // edx
  int panelHeight; // [esp+4h] [ebp-Ch] BYREF
  int panelWidth; // [esp+8h] [ebp-8h] BYREF
  int v12; // [esp+Ch] [ebp-4h]

  if ( this->m_SavePanels.m_Size != 0 )
  {
    ChildByName = vgui::Panel::FindChildByName(this, childName: "NoSavesLabel", recurseDown: false);
    if ( ChildByName != nullptr )
      ChildByName->SetVisible(this: ChildByName, a2: false);
    panelWidth = vgui::Panel::GetWide(this: *this->m_SavePanels.m_Memory.m_pMemory) + 16;
    v3 = panelWidth;
    v4 = (vgui::Panel::GetWide(this) - panelWidth) / 2 + 8;
    v5 = v4 - panelWidth;
    this->m_PanelXPos[2] = v4;
    v6 = v3 + v4;
    this->m_PanelXPos[1] = v5;
    this->m_PanelXPos[0] = v5;
    this->m_PanelXPos[3] = v6;
    this->m_PanelXPos[4] = v6;
    m_pMemory = this->m_SavePanels.m_Memory.m_pMemory;
    this->m_PanelAlpha[0] = 0.0;
    this->m_PanelAlpha[1] = 64.0;
    this->m_PanelAlpha[2] = 255.0;
    this->m_PanelAlpha[3] = 64.0;
    this->m_PanelAlpha[4] = 0.0;
    vgui::Panel::GetSize(this: *m_pMemory, wide: &panelWidth, tall: &panelHeight);
    this->m_pCenterBg->SetVisible(this: this->m_pCenterBg, a2: true);
    vgui::Panel::SetWide(this: this->m_pCenterBg, wide: panelWidth + 16);
    vgui::Panel::SetPos(
      this: this->m_pCenterBg,
      x: this->m_PanelXPos[2] - 8,
      y: this->m_nCenterBgTallDefault + this->m_PanelYPos[2] - panelHeight + 8);
    m_pCenterBg = this->m_pCenterBg;
    SetBgColor = m_pCenterBg->SetBgColor;
    v12 = -16747586;
    ((void (__thiscall *)(vgui::Panel *, int))SetBgColor)(a1: m_pCenterBg, a2: -16747586);
  }
  else
  {
    CSaveGameBrowserDialog::ShowNoSaveGameUI(this);
  }
  CSaveGameBrowserDialog::UpdateMenuComponents(this, a2: (int)this, dir: SCROLL_NONE);
  this->UpdateFooterOptions(this);
}

//------------------------------------------------------------------------------
// Address: 0x101FFB60
// Name: public: virtual void CSaveGameBrowserDialog::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameBrowserDialog::ApplySchemeSettings(CSaveGameBrowserDialog *this, vgui::IScheme *pScheme)
{
  vgui::Frame::ApplySchemeSettings(this, pScheme);
  CSaveGameBrowserDialog::UpdateMenuComponents(this, a2: (int)this, dir: SCROLL_NONE);
}

//------------------------------------------------------------------------------
// Address: 0x101FFB80
// Name: public: void CSaveGameBrowserDialog::RemoveActivePanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameBrowserDialog::RemoveActivePanel(CSaveGameBrowserDialog *this)
{
  CGameSavePanel **m_pMemory; // ecx
  int v3; // eax
  vgui::AnimationController *AnimationController; // eax
  vgui::AnimationController *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  vgui::Panel *v8; // [esp-8h] [ebp-20h]
  vgui::Panel *m_pCenterBg; // [esp-8h] [ebp-20h]
  float duration; // [esp+8h] [ebp-10h]
  float durationa; // [esp+8h] [ebp-10h]

  m_pMemory = this->m_SavePanels.m_Memory.m_pMemory;
  v3 = this->m_PanelIndex[2];
  duration = this->m_ScrollSpeedFast;
  this->m_nDeletedPanel = v3;
  v8 = m_pMemory[v3];
  AnimationController = vgui::GetAnimationController();
  vgui::AnimationController::RunAnimationCommand(
    this: AnimationController,
    panel: v8,
    variable: "alpha",
    targetValue: 0.0,
    startDelaySeconds: 0.0,
    duration,
    interpolator: (vgui::AnimationController::Interpolators_e)1,
    animParameter: 0.0);
  durationa = this->m_ScrollSpeedFast;
  m_pCenterBg = this->m_pCenterBg;
  v5 = vgui::GetAnimationController();
  vgui::AnimationController::RunAnimationCommand(
    this: v5,
    panel: m_pCenterBg,
    variable: "alpha",
    targetValue: 0.0,
    startDelaySeconds: 0.0,
    duration: durationa,
    interpolator: (vgui::AnimationController::Interpolators_e)1,
    animParameter: 0.0);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "FinishDelete");
  else
    v7 = nullptr;
  ((void (__thiscall *)(CSaveGameBrowserDialog *, CSaveGameBrowserDialog *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v7,
    a4: LODWORD(this->m_ScrollSpeed));
}

//------------------------------------------------------------------------------
// Address: 0x101FFC50
// Name: public: virtual void CSaveGameBrowserDialog::FinishInsert(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameBrowserDialog::FinishInsert(CSaveGameBrowserDialog *this)
{
  CGameSavePanel *v2; // edi
  vgui::AnimationController *AnimationController; // eax
  vgui::AnimationController *v4; // eax
  vgui::AnimationController *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  float targetValue; // [esp+0h] [ebp-1Ch]
  float targetValuea; // [esp+0h] [ebp-1Ch]

  v2 = this->m_SavePanels.m_Memory.m_pMemory[this->m_nAddedPanel];
  targetValue = (float)this->m_PanelXPos[3];
  AnimationController = vgui::GetAnimationController();
  vgui::AnimationController::RunAnimationCommand(
    this: AnimationController,
    panel: v2,
    variable: "xpos",
    targetValue,
    startDelaySeconds: 0.0,
    duration: 0.75,
    interpolator: INTERPOLATOR_SIMPLESPLINE,
    animParameter: 0.0);
  targetValuea = (float)this->m_PanelYPos[3];
  v4 = vgui::GetAnimationController();
  vgui::AnimationController::RunAnimationCommand(
    this: v4,
    panel: v2,
    variable: "ypos",
    targetValue: targetValuea,
    startDelaySeconds: 0.0,
    duration: 0.75,
    interpolator: INTERPOLATOR_SIMPLESPLINE,
    animParameter: 0.0);
  v5 = vgui::GetAnimationController();
  vgui::AnimationController::RunAnimationCommand(
    this: v5,
    panel: v2,
    variable: "alpha",
    targetValue: 255.0,
    startDelaySeconds: 0.0,
    duration: 0.75,
    interpolator: INTERPOLATOR_SIMPLESPLINE,
    animParameter: 0.0);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "CloseAfterSave");
  else
    v7 = nullptr;
  ((void (__thiscall *)(CSaveGameBrowserDialog *, CSaveGameBrowserDialog *, KeyValues *, int))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v7,
    a4: 1069547520);
}

//------------------------------------------------------------------------------
// Address: 0x101FFD70
// Name: private: void CSaveGameBrowserDialog::PerformSlideAction(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameBrowserDialog::PerformSlideAction(
        CSaveGameBrowserDialog *this,
        int nPanelIndex,
        int nNextPanelIndex)
{
  CGameSavePanel *v4; // edi
  vgui::AnimationController *AnimationController; // eax
  vgui::AnimationController *v6; // eax
  vgui::AnimationController *v7; // eax
  float targetValue; // [esp+0h] [ebp-20h]
  float targetValuea; // [esp+0h] [ebp-20h]
  float targetValueb; // [esp+0h] [ebp-20h]
  float duration; // [esp+8h] [ebp-18h]
  float durationa; // [esp+8h] [ebp-18h]
  float durationb; // [esp+8h] [ebp-18h]

  v4 = this->m_SavePanels.m_Memory.m_pMemory[this->m_PanelIndex[nPanelIndex]];
  duration = this->m_ScrollSpeed;
  targetValue = (float)this->m_PanelXPos[nNextPanelIndex];
  AnimationController = vgui::GetAnimationController();
  vgui::AnimationController::RunAnimationCommand(
    this: AnimationController,
    panel: v4,
    variable: "xpos",
    targetValue,
    startDelaySeconds: 0.0,
    duration,
    interpolator: INTERPOLATOR_SIMPLESPLINE,
    animParameter: 0.0);
  durationa = this->m_ScrollSpeed;
  targetValuea = (float)this->m_PanelYPos[nNextPanelIndex];
  v6 = vgui::GetAnimationController();
  vgui::AnimationController::RunAnimationCommand(
    this: v6,
    panel: v4,
    variable: "ypos",
    targetValue: targetValuea,
    startDelaySeconds: 0.0,
    duration: durationa,
    interpolator: INTERPOLATOR_SIMPLESPLINE,
    animParameter: 0.0);
  durationb = this->m_ScrollSpeed;
  targetValueb = this->m_PanelAlpha[nNextPanelIndex];
  v7 = vgui::GetAnimationController();
  vgui::AnimationController::RunAnimationCommand(
    this: v7,
    panel: v4,
    variable: "alpha",
    targetValue: targetValueb,
    startDelaySeconds: 0.0,
    duration: durationb,
    interpolator: INTERPOLATOR_SIMPLESPLINE,
    animParameter: 0.0);
}

//------------------------------------------------------------------------------
// Address: 0x101FFE70
// Name: private: void CSaveGameBrowserDialog::AnimateSelectionPanels(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameBrowserDialog::AnimateSelectionPanels(CSaveGameBrowserDialog *this)
{
  int m_ScrollCt; // eax
  int v3; // edi
  int *v4; // ebx
  vgui::AnimationController *AnimationController; // eax
  CSaveGameBrowserDialog_vtbl *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  vgui::Panel *m_pCenterBg; // [esp-4h] [ebp-30h]
  float duration; // [esp+Ch] [ebp-20h]
  int endIdx; // [esp+24h] [ebp-8h]
  int idxOffset; // [esp+28h] [ebp-4h]

  m_ScrollCt = this->m_ScrollCt;
  v3 = 1;
  endIdx = 3;
  if ( m_ScrollCt < 1 || this->m_PanelIndex[2] >= this->m_SavePanels.m_Size - 1 )
  {
    if ( m_ScrollCt > -1 || this->m_PanelIndex[2] <= 0 )
    {
      *((_BYTE *)this + 1132) &= ~1u;
      this->m_ScrollCt = 0;
      this->m_ScrollDirection = SCROLL_NONE;
      g_pVGuiSurface->PlaySound(this: g_pVGuiSurface, a2: "player/suit_denydevice.wav");
      return;
    }
    idxOffset = 1;
    v3 = 0;
    this->m_ScrollDirection = SCROLL_RIGHT;
  }
  else
  {
    if ( this->m_nDeletedPanel != -1 )
      v3 = 3;
    idxOffset = -1;
    endIdx = 4;
    this->m_ScrollDirection = SCROLL_LEFT;
  }
  v4 = &this->m_PanelIndex[v3];
  do
  {
    if ( *v4 != this->m_nDeletedPanel && *v4 != -1 )
      CSaveGameBrowserDialog::PerformSlideAction(this, nPanelIndex: v3, nNextPanelIndex: v3 + idxOffset);
    ++v3;
    ++v4;
  }
  while ( v3 <= endIdx );
  g_pVGuiSurface->PlaySound(this: g_pVGuiSurface, a2: "UI/buttonclick.wav");
  duration = this->m_ScrollSpeed * 0.25;
  m_pCenterBg = this->m_pCenterBg;
  AnimationController = vgui::GetAnimationController();
  vgui::AnimationController::RunAnimationCommand(
    this: AnimationController,
    panel: m_pCenterBg,
    variable: "alpha",
    targetValue: 0.0,
    startDelaySeconds: 0.0,
    duration,
    interpolator: INTERPOLATOR_SIMPLESPLINE,
    animParameter: 0.0);
  v6 = this->__vftable;
  this->m_iSelectedSave -= idxOffset;
  v6->UpdateFooterOptions(this);
  v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v7 != nullptr )
    v8 = KeyValues::KeyValues(this: v7, setName: "FinishScroll");
  else
    v8 = nullptr;
  ((void (__thiscall *)(CSaveGameBrowserDialog *, CSaveGameBrowserDialog *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v8,
    a4: LODWORD(this->m_ScrollSpeed));
}

//------------------------------------------------------------------------------
// Address: 0x10200010
// Name: private: void CSaveGameBrowserDialog::InitPanelIndexForDisplay(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameBrowserDialog::InitPanelIndexForDisplay(CSaveGameBrowserDialog *this, int idx)
{
  CGameSavePanel *v3; // esi

  v3 = this->m_SavePanels.m_Memory.m_pMemory[this->m_PanelIndex[idx]];
  if ( v3 != nullptr )
  {
    vgui::Panel::SetPos(this: v3, x: this->m_PanelXPos[idx], y: this->m_PanelYPos[idx]);
    vgui::Panel::SetAlpha(this: v3, alpha: (int)this->m_PanelAlpha[idx]);
    v3->SetVisible(this: v3, a2: true);
    v3->SetEnabled(this: v3, a2: true);
    if ( this->m_PanelAlpha[idx] != 0.0 )
      vgui::Panel::SetZPos(this: v3, z: 5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102000A0
// Name: public: class CGameSavePanel __near * CSaveGameBrowserDialog::GetActivePanel(void)
// Source: json
//------------------------------------------------------------------------------
CGameSavePanel *__thiscall CSaveGameBrowserDialog::GetActivePanel(CSaveGameBrowserDialog *this)
{
  int m_iSelectedSave; // eax

  m_iSelectedSave = this->m_iSelectedSave;
  if ( m_iSelectedSave >= 0 && m_iSelectedSave < this->m_SavePanels.m_Size )
    return this->m_SavePanels.m_Memory.m_pMemory[m_iSelectedSave];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102000C0
// Name: private: void CSaveGameBrowserDialog::AnimateDialogStart(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameBrowserDialog::AnimateDialogStart(CSaveGameBrowserDialog *this)
{
  const char *m_PanelIndex; // ebx
  CGameSavePanel *v3; // esi
  vgui::AnimationController *AnimationController; // eax
  vgui::AnimationController *v5; // eax
  vgui::AnimationController *v6; // eax
  int Wide; // eax
  vgui::AnimationController *v8; // eax
  vgui::AnimationController *v9; // eax
  const char *v10; // ecx
  int m_iSelectedSave; // eax
  CGameSavePanel *v12; // eax
  vgui::Panel *m_pCenterBg; // [esp+0h] [ebp-3Ch]
  vgui::Panel *v14; // [esp+0h] [ebp-3Ch]
  float targetValue; // [esp+8h] [ebp-34h]
  float targetValuea; // [esp+8h] [ebp-34h]
  float targetValueb; // [esp+8h] [ebp-34h]
  float targetValuec; // [esp+8h] [ebp-34h]
  int animParameter; // [esp+18h] [ebp-24h]
  int nY; // [esp+28h] [ebp-14h] BYREF
  int nX; // [esp+2Ch] [ebp-10h] BYREF
  float duration; // [esp+30h] [ebp-Ch]
  int z; // [esp+34h] [ebp-8h]
  int i; // [esp+38h] [ebp-4h]

  i = 0;
  z = 5;
  m_PanelIndex = (const char *)this->m_PanelIndex;
  do
  {
    if ( *(_DWORD *)m_PanelIndex != -1 )
    {
      v3 = this->m_SavePanels.m_Memory.m_pMemory[*(_DWORD *)m_PanelIndex];
      if ( v3 != nullptr )
      {
        vgui::Panel::SetPos(this: v3, x: this->m_PanelXPos[0], y: this->m_PanelYPos[0]);
        vgui::Panel::SetAlpha(this: v3, alpha: (int)this->m_PanelAlpha[0]);
        v3->SetVisible(this: v3, a2: true);
        v3->SetEnabled(this: v3, a2: true);
        vgui::Panel::SetZPos(this: v3, z);
      }
      duration = (float)((float)i * 0.1) + 0.5;
      targetValue = (float)*((int *)m_PanelIndex - 15);
      AnimationController = vgui::GetAnimationController();
      vgui::AnimationController::RunAnimationCommand(
        this: AnimationController,
        panel: v3,
        variable: "xpos",
        targetValue,
        startDelaySeconds: 0.0,
        duration,
        interpolator: INTERPOLATOR_SIMPLESPLINE,
        animParameter: 0.0);
      targetValuea = (float)*((int *)m_PanelIndex - 10);
      v5 = vgui::GetAnimationController();
      vgui::AnimationController::RunAnimationCommand(
        this: v5,
        panel: v3,
        variable: "ypos",
        targetValue: targetValuea,
        startDelaySeconds: 0.0,
        duration,
        interpolator: INTERPOLATOR_SIMPLESPLINE,
        animParameter: 0.0);
      targetValueb = *((float *)m_PanelIndex - 5);
      v6 = vgui::GetAnimationController();
      vgui::AnimationController::RunAnimationCommand(
        this: v6,
        panel: v3,
        variable: "alpha",
        targetValue: targetValueb,
        startDelaySeconds: 0.0,
        duration,
        interpolator: INTERPOLATOR_SIMPLESPLINE,
        animParameter: 0.0);
    }
    ++i;
    m_PanelIndex += 4;
    --z;
  }
  while ( z > 0 );
  vgui::Panel::SetAlpha(this: this->m_pCenterBg, alpha: 0);
  vgui::Panel::GetPos(this: this->m_pCenterBg, x: &nX, y: &nY);
  animParameter = nY;
  Wide = vgui::Panel::GetWide(this: this->m_pCenterBg);
  vgui::Panel::SetPos(this: this->m_pCenterBg, x: nX - Wide, y: animParameter);
  targetValuec = (float)nX;
  m_pCenterBg = this->m_pCenterBg;
  v8 = vgui::GetAnimationController();
  vgui::AnimationController::RunAnimationCommand(
    this: v8,
    panel: m_pCenterBg,
    variable: "xpos",
    targetValue: targetValuec,
    startDelaySeconds: 0.0,
    duration: 0.69999999,
    interpolator: INTERPOLATOR_SIMPLESPLINE,
    animParameter: 0.0);
  v14 = this->m_pCenterBg;
  v9 = vgui::GetAnimationController();
  vgui::AnimationController::RunAnimationCommand(
    this: v9,
    panel: v14,
    variable: "alpha",
    targetValue: 255.0,
    startDelaySeconds: 0.0,
    duration: 1.4,
    interpolator: INTERPOLATOR_SIMPLESPLINE,
    animParameter: 0.0);
  m_iSelectedSave = this->m_iSelectedSave;
  if ( m_iSelectedSave >= 0
    && m_iSelectedSave < this->m_SavePanels.m_Size
    && (v12 = this->m_SavePanels.m_Memory.m_pMemory[m_iSelectedSave]) != nullptr
    && V_stristr(a1: v10, a2: m_PanelIndex, pStr: v12->m_SaveInfo.szType, pSearch: "autosave") != nullptr )
  {
    vgui::Panel::SetTall(this: this->m_pCenterBg, tall: this->m_nCenterBgTallDefault + 20);
  }
  else
  {
    vgui::Panel::SetTall(this: this->m_pCenterBg, tall: this->m_nCenterBgTallDefault);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10200370
// Name: public: void CSaveGameBrowserDialog::SetSelectedSaveIndex(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameBrowserDialog::SetSelectedSaveIndex(CSaveGameBrowserDialog *this, int index)
{
  bool v3; // zf
  int v4; // esi
  int *v5; // edi
  int v6; // eax
  int v7; // eax
  int *v8; // edi
  int i; // [esp+4h] [ebp-4h]
  int currIdx; // [esp+10h] [ebp+8h]

  v3 = this->m_SavePanels.m_Size == 0;
  this->m_iSelectedSave = index;
  if ( !v3 )
  {
    v4 = 2;
    v5 = &this->m_PanelIndex[2];
    do
    {
      v6 = index + v4 - 2;
      if ( v6 < 0 )
        break;
      *v5 = v6;
      CSaveGameBrowserDialog::InitPanelIndexForDisplay(this, idx: v4);
      --v5;
      --v4;
    }
    while ( v4 >= 0 );
    v7 = index + 1;
    i = 3;
    v8 = &this->m_PanelIndex[3];
    do
    {
      if ( v7 >= this->m_SavePanels.m_Size )
        break;
      *v8 = v7;
      v4 = (int)this->m_SavePanels.m_Memory.m_pMemory[*v8];
      currIdx = ++v7;
      if ( v4 != 0 )
      {
        vgui::Panel::SetPos(this: (vgui::Panel *)v4, x: *(v8 - 15), y: *(v8 - 10));
        vgui::Panel::SetAlpha(this: (vgui::Panel *)v4, alpha: (int)*((float *)v8 - 5));
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 132))(a1: v4, a2: 1);
        (*(void (__thiscall **)(int, int))(*(_DWORD *)v4 + 220))(a1: v4, a2: 1);
        if ( *((float *)v8 - 5) != 0.0 )
          vgui::Panel::SetZPos(this: (vgui::Panel *)v4, z: 5);
        v7 = currIdx;
      }
      ++v8;
      ++i;
    }
    while ( i < 5 );
    CSaveGameBrowserDialog::UpdateMenuComponents(this, a2: v4, dir: SCROLL_NONE);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10200470
// Name: public: virtual void CSaveGameBrowserDialog::FinishOverwriteFadeDown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameBrowserDialog::FinishOverwriteFadeDown(CSaveGameBrowserDialog *this)
{
  int m_iSelectedSave; // eax
  CGameSavePanel *v3; // edi
  vgui::AnimationController *AnimationController; // eax
  vgui::AnimationController *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  vgui::Panel *m_pCenterBg; // [esp-4h] [ebp-20h]
  float targetValue; // [esp+0h] [ebp-1Ch]

  m_iSelectedSave = this->m_iSelectedSave;
  if ( m_iSelectedSave >= 0 && m_iSelectedSave < this->m_SavePanels.m_Size )
  {
    v3 = this->m_SavePanels.m_Memory.m_pMemory[m_iSelectedSave];
    if ( v3 != nullptr )
    {
      CGameSavePanel::SetDescription(this: v3, pDesc: &this->m_NewSaveGameDesc);
      targetValue = this->m_PanelAlpha[2];
      AnimationController = vgui::GetAnimationController();
      vgui::AnimationController::RunAnimationCommand(
        this: AnimationController,
        panel: v3,
        variable: "alpha",
        targetValue,
        startDelaySeconds: 0.0,
        duration: 0.25,
        interpolator: INTERPOLATOR_SIMPLESPLINE,
        animParameter: 0.0);
    }
  }
  m_pCenterBg = this->m_pCenterBg;
  v5 = vgui::GetAnimationController();
  vgui::AnimationController::RunAnimationCommand(
    this: v5,
    panel: m_pCenterBg,
    variable: "alpha",
    targetValue: 255.0,
    startDelaySeconds: 0.0,
    duration: 0.25,
    interpolator: INTERPOLATOR_SIMPLESPLINE,
    animParameter: 0.0);
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
    v7 = KeyValues::KeyValues(this: v6, setName: "CloseAfterSave");
  else
    v7 = nullptr;
  ((void (__thiscall *)(CSaveGameBrowserDialog *, CSaveGameBrowserDialog *, KeyValues *, int))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v7,
    a4: 1051931443);
}

//------------------------------------------------------------------------------
// Address: 0x10200570
// Name: public: void CSaveGameBrowserDialog::AnimateOverwriteActivePanel(struct SaveGameDescription_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameBrowserDialog::AnimateOverwriteActivePanel(
        CSaveGameBrowserDialog *this,
        const SaveGameDescription_t *pNewDesc)
{
  int m_iSelectedSave; // eax
  CGameSavePanel *v4; // eax
  vgui::AnimationController *AnimationController; // eax
  vgui::AnimationController *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  vgui::Panel *v9; // [esp-8h] [ebp-28h]
  vgui::Panel *m_pCenterBg; // [esp-8h] [ebp-28h]

  m_iSelectedSave = this->m_iSelectedSave;
  qmemcpy(&this->m_NewSaveGameDesc, pNewDesc, sizeof(this->m_NewSaveGameDesc));
  if ( m_iSelectedSave >= 0 && m_iSelectedSave < this->m_SavePanels.m_Size )
  {
    v4 = this->m_SavePanels.m_Memory.m_pMemory[m_iSelectedSave];
    if ( v4 != nullptr )
    {
      v9 = v4;
      AnimationController = vgui::GetAnimationController();
      vgui::AnimationController::RunAnimationCommand(
        this: AnimationController,
        panel: v9,
        variable: "alpha",
        targetValue: 0.0,
        startDelaySeconds: 0.0,
        duration: 0.5,
        interpolator: INTERPOLATOR_SIMPLESPLINE,
        animParameter: 0.0);
    }
  }
  m_pCenterBg = this->m_pCenterBg;
  v6 = vgui::GetAnimationController();
  vgui::AnimationController::RunAnimationCommand(
    this: v6,
    panel: m_pCenterBg,
    variable: "alpha",
    targetValue: 0.0,
    startDelaySeconds: 0.0,
    duration: 0.5,
    interpolator: INTERPOLATOR_SIMPLESPLINE,
    animParameter: 0.0);
  v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v7 != nullptr )
    v8 = KeyValues::KeyValues(this: v7, setName: "FinishOverwriteFadeDown");
  else
    v8 = nullptr;
  ((void (__thiscall *)(CSaveGameBrowserDialog *, CSaveGameBrowserDialog *, KeyValues *, int))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v8,
    a4: 1061158912);
}

//------------------------------------------------------------------------------
// Address: 0x10200660
// Name: private: void CSaveGameBrowserDialog::ScrollSelectionPanels(enum CSaveGameBrowserDialog::EScrollDirection)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameBrowserDialog::ScrollSelectionPanels(
        CSaveGameBrowserDialog *this,
        CSaveGameBrowserDialog::EScrollDirection dir)
{
  int m_nDeletedPanel; // eax

  if ( (*((_BYTE *)this + 1132) & 1) != 0 )
    return;
  m_nDeletedPanel = this->m_nDeletedPanel;
  if ( m_nDeletedPanel != -1 )
    goto LABEL_8;
  if ( dir == SCROLL_LEFT )
  {
    m_nDeletedPanel = this->m_PanelIndex[1];
  }
  else
  {
    if ( dir != SCROLL_RIGHT )
      goto LABEL_9;
    m_nDeletedPanel = this->m_PanelIndex[3];
  }
  if ( m_nDeletedPanel != -1 )
LABEL_8:
    vgui::Panel::SetZPos(this: this->m_SavePanels.m_Memory.m_pMemory[m_nDeletedPanel], z: 0);
LABEL_9:
  if ( dir == SCROLL_LEFT )
  {
    ++this->m_ScrollCt;
  }
  else if ( dir == SCROLL_RIGHT && this->m_PanelIndex[2] != 0 )
  {
    --this->m_ScrollCt;
  }
  *((_BYTE *)this + 1132) |= 1u;
  CSaveGameBrowserDialog::AnimateSelectionPanels(this);
  CSaveGameBrowserDialog::UpdateMenuComponents(this, a2: (int)this, dir: this->m_ScrollDirection);
}

//------------------------------------------------------------------------------
// Address: 0x102006F0
// Name: private: void CSaveGameBrowserDialog::ShiftPanelIndices(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameBrowserDialog::ShiftPanelIndices(CSaveGameBrowserDialog *this, int offset)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  CGameSavePanel *v6; // ecx
  int v7; // eax
  int v8; // eax
  int v9; // eax
  CGameSavePanel *v10; // ecx
  int *m_PanelIndex; // edi
  int v12; // eax

  if ( this->m_nDeletedPanel == -1 )
  {
    if ( offset <= 0 )
    {
      v9 = this->m_PanelIndex[4];
      if ( v9 >= 0 && v9 < this->m_SavePanels.m_Size )
      {
        v10 = this->m_SavePanels.m_Memory.m_pMemory[v9];
        v10->SetVisible(this: v10, a2: false);
      }
      m_PanelIndex = this->m_PanelIndex;
      _V_memmove(
        dest: (unsigned __int8 *)&this->m_PanelIndex[1],
        src: (unsigned __int8 *)this->m_PanelIndex,
        count: 0x10u);
      if ( this->m_PanelIndex[0] != -1 )
      {
        v12 = this->m_PanelIndex[0] - 1;
        if ( v12 < 0 || v12 >= this->m_SavePanels.m_Size )
        {
          *m_PanelIndex = -1;
        }
        else
        {
          *m_PanelIndex = v12;
          CSaveGameBrowserDialog::InitPanelIndexForDisplay(this, idx: 0);
        }
      }
    }
    else
    {
      v5 = this->m_PanelIndex[0];
      if ( v5 >= 0 && v5 < this->m_SavePanels.m_Size )
      {
        v6 = this->m_SavePanels.m_Memory.m_pMemory[v5];
        v6->SetVisible(this: v6, a2: false);
      }
      _V_memmove(
        dest: (unsigned __int8 *)this->m_PanelIndex,
        src: (unsigned __int8 *)&this->m_PanelIndex[1],
        count: 0x10u);
      v7 = this->m_PanelIndex[4];
      if ( v7 != -1 )
      {
        v8 = v7 + 1;
        if ( v8 < 0 || v8 >= this->m_SavePanels.m_Size )
        {
          this->m_PanelIndex[4] = -1;
        }
        else
        {
          this->m_PanelIndex[4] = v8;
          CSaveGameBrowserDialog::InitPanelIndexForDisplay(this, idx: 4);
        }
      }
    }
  }
  else
  {
    _V_memmove(
      dest: (unsigned __int8 *)&this->m_PanelIndex[2],
      src: (unsigned __int8 *)&this->m_PanelIndex[3],
      count: 8u);
    v3 = this->m_PanelIndex[4];
    if ( v3 != -1 )
    {
      v4 = v3 + 1;
      if ( v4 < 0 || v4 >= this->m_SavePanels.m_Size )
      {
        this->m_PanelIndex[4] = -1;
      }
      else
      {
        this->m_PanelIndex[4] = v4;
        CSaveGameBrowserDialog::InitPanelIndexForDisplay(this, idx: 4);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10200850
// Name: public: virtual void CSaveGameBrowserDialog::FinishScroll(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSaveGameBrowserDialog::FinishScroll(CSaveGameBrowserDialog *this@<ecx>, const char *a2@<ebx>)
{
  vgui::AnimationController *AnimationController; // eax
  int m_nDeletedPanel; // ecx
  int v5; // ebx
  CGameSavePanel **m_pMemory; // edx
  int v7; // eax
  CGameSavePanel *v8; // edi
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int m_iSelectedSave; // eax
  CGameSavePanel **v15; // ecx
  CGameSavePanel *v16; // eax
  CGameUI *v17; // eax
  CSaveGameBrowserDialog::EScrollDirection m_ButtonPressed; // eax
  vgui::Panel *m_pCenterBg; // [esp-8h] [ebp-20h]
  float duration; // [esp+8h] [ebp-10h]
  const char *animParameter; // [esp+10h] [ebp-8h]
  CSaveGameBrowserDialog::EScrollDirection animParametera; // [esp+10h] [ebp-8h]

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
  CSaveGameBrowserDialog::ShiftPanelIndices(this, offset: this->m_ScrollDirection);
  m_nDeletedPanel = this->m_nDeletedPanel;
  *((_BYTE *)this + 1132) &= ~1u;
  this->m_ScrollCt = 0;
  if ( m_nDeletedPanel != -1 )
  {
    animParameter = a2;
    v5 = m_nDeletedPanel;
    if ( m_nDeletedPanel + 1 < 0 || m_nDeletedPanel + 1 >= this->m_SavePanels.m_Size )
      v5 = m_nDeletedPanel - 1;
    m_pMemory = this->m_SavePanels.m_Memory.m_pMemory;
    v7 = this->m_SavePanels.m_Size - m_nDeletedPanel - 1;
    v8 = m_pMemory[m_nDeletedPanel];
    if ( v7 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_nDeletedPanel],
        src: (unsigned __int8 *)&m_pMemory[m_nDeletedPanel + 1],
        count: 4 * v7);
    --this->m_SavePanels.m_Size;
    if ( v8 != nullptr )
      ((void (__thiscall *)(CGameSavePanel *, int))v8->dtr_Panel)(a1: v8, a2: 1);
    v9 = this->m_PanelIndex[0];
    if ( v9 > this->m_nDeletedPanel )
      this->m_PanelIndex[0] = v9 - 1;
    v10 = this->m_PanelIndex[1];
    if ( v10 > this->m_nDeletedPanel )
      this->m_PanelIndex[1] = v10 - 1;
    v11 = this->m_PanelIndex[2];
    if ( v11 > this->m_nDeletedPanel )
      this->m_PanelIndex[2] = v11 - 1;
    v12 = this->m_PanelIndex[3];
    if ( v12 > this->m_nDeletedPanel )
      this->m_PanelIndex[3] = v12 - 1;
    v13 = this->m_PanelIndex[4];
    if ( v13 > this->m_nDeletedPanel )
      this->m_PanelIndex[4] = v13 - 1;
    CSaveGameBrowserDialog::SetSelectedSaveIndex(this, index: v5);
    this->m_nDeletedPanel = -1;
    CSaveGameBrowserDialog::UpdateMenuComponents(this, a2: (int)this, dir: SCROLL_NONE);
    a2 = animParameter;
  }
  m_iSelectedSave = this->m_iSelectedSave;
  if ( m_iSelectedSave >= 0
    && m_iSelectedSave < this->m_SavePanels.m_Size
    && (v15 = this->m_SavePanels.m_Memory.m_pMemory, (v16 = v15[m_iSelectedSave]) != nullptr)
    && V_stristr(a1: (const char *)v15, a2, pStr: v16->m_SaveInfo.szType, pSearch: "autosave") != nullptr )
  {
    vgui::Panel::SetTall(this: this->m_pCenterBg, tall: this->m_nCenterBgTallDefault + 20);
  }
  else
  {
    vgui::Panel::SetTall(this: this->m_pCenterBg, tall: this->m_nCenterBgTallDefault);
  }
  v17 = GameUI();
  if ( CGameUI::IsConsoleUI(this: v17) )
  {
    m_ButtonPressed = this->m_ButtonPressed;
    if ( m_ButtonPressed == this->m_ScrollDirection )
    {
      animParametera = this->m_ScrollDirection;
      this->m_ScrollSpeed = this->m_ScrollSpeedFast;
      CSaveGameBrowserDialog::ScrollSelectionPanels(this, dir: animParametera);
    }
    else
    {
      this->m_ScrollSpeed = this->m_ScrollSpeedSlow;
      if ( m_ButtonPressed != SCROLL_NONE )
        CSaveGameBrowserDialog::ScrollSelectionPanels(this, dir: m_ButtonPressed);
    }
  }
  else if ( this->m_PanelIndex[1] % 3 != 0 )
  {
    CSaveGameBrowserDialog::ScrollSelectionPanels(this, dir: this->m_ScrollDirection);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10200A80
// Name: public: virtual void CSaveGameBrowserDialog::OnKeyCodePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameBrowserDialog::OnKeyCodePressed(CSaveGameBrowserDialog *this, ButtonCode_t code)
{
  CCStrike15BasePanel *v3; // eax
  char v4; // cl
  CCStrike15BasePanel *v5; // eax
  int m_nDeletedPanel; // eax

  v3 = BasePanel();
  if ( !v3->m_bWaitingForStorageDeviceHandle
    && !v3->m_bWaitingForUserSignIn
    && !v3->m_bXUIVisible
    && vgui::Panel::GetAlpha(this) == 255 )
  {
    v4 = *((_BYTE *)this + 1132);
    if ( (v4 & 4) == 0 )
    {
      switch ( code )
      {
        case JOYSTICK_FIRST:
          this->PerformSelectedAction(this);
          break;
        case KEY_XBUTTON_B:
          this->OnClose(this);
          break;
        case KEY_XBUTTON_X:
          this->PerformDeletion(this);
          break;
        case KEY_XBUTTON_Y:
          v5 = BasePanel();
          CBaseModPanel::OnChangeStorageDevice(this: v5);
          break;
        case KEY_XBUTTON_RIGHT:
        case JOYSTICK_FIRST_AXIS_BUTTON:
          CSaveGameBrowserDialog::ScrollSelectionPanels(this, dir: SCROLL_LEFT);
          break;
        case KEY_XBUTTON_LEFT:
        case KEY_XSTICK1_LEFT:
          if ( (v4 & 1) == 0 )
          {
            m_nDeletedPanel = this->m_nDeletedPanel;
            if ( m_nDeletedPanel != -1 || (m_nDeletedPanel = this->m_PanelIndex[3]) != -1 )
              vgui::Panel::SetZPos(this: this->m_SavePanels.m_Memory.m_pMemory[m_nDeletedPanel], z: 0);
            if ( this->m_PanelIndex[2] != 0 )
              --this->m_ScrollCt;
            *((_BYTE *)this + 1132) |= 1u;
            CSaveGameBrowserDialog::AnimateSelectionPanels(this);
            CSaveGameBrowserDialog::UpdateMenuComponents(this, a2: (int)this, dir: this->m_ScrollDirection);
          }
          break;
        default:
          return;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10200CC0
// Name: public: virtual CSaveGameBrowserDialog::~CSaveGameBrowserDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameBrowserDialog::~CSaveGameBrowserDialog(CSaveGameBrowserDialog *this)
{
  vgui::CFooterPanel *m_pFooter; // ecx
  vgui::Panel *m_pCenterBg; // ecx

  this->__vftable = (CSaveGameBrowserDialog_vtbl *)&CSaveGameBrowserDialog::`vftable';
  CUtlVector<CGameSavePanel *,CUtlMemory<CGameSavePanel *,int>>::PurgeAndDeleteElements(this: &this->m_SavePanels);
  m_pFooter = this->m_pFooter;
  if ( m_pFooter != nullptr )
  {
    ((void (__thiscall *)(vgui::CFooterPanel *, int))m_pFooter->dtr_Panel)(a1: m_pFooter, a2: 1);
    this->m_pFooter = nullptr;
  }
  m_pCenterBg = this->m_pCenterBg;
  if ( m_pCenterBg != nullptr )
  {
    ((void (__thiscall *)(vgui::Panel *, int))m_pCenterBg->dtr_Panel)(a1: m_pCenterBg, a2: 1);
    this->m_pCenterBg = nullptr;
  }
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_SavePanels);
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x10200D30
// Name: public: virtual struct vgui::PanelMessageMap __near * CSaveGameBrowserDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSaveGameBrowserDialog::GetMessageMap(CSaveGameBrowserDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSaveGameBrowserDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSaveGameBrowserDialog::GetMessageMap'::`2'::s_pMap;
  `CSaveGameBrowserDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSaveGameBrowserDialog");
  `CSaveGameBrowserDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10200D60
// Name: public: virtual struct PanelAnimationMap __near * CSaveGameBrowserDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSaveGameBrowserDialog::GetAnimMap(CSaveGameBrowserDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CSaveGameBrowserDialog");
}

//------------------------------------------------------------------------------
// Address: 0x10200D70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSaveGameBrowserDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSaveGameBrowserDialog::GetKBMap(CSaveGameBrowserDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSaveGameBrowserDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSaveGameBrowserDialog::GetKBMap'::`2'::s_pMap;
  `CSaveGameBrowserDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSaveGameBrowserDialog");
  `CSaveGameBrowserDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10200DA0
// Name: public: virtual void CSaveGameBrowserDialog::FinishDelete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameBrowserDialog::FinishDelete(CSaveGameBrowserDialog *this)
{
  int m_Size; // ecx
  int v3; // eax
  bool v4; // al

  m_Size = this->m_SavePanels.m_Size;
  if ( m_Size == 1 )
  {
    this->m_nDeletedPanel = -1;
    CUtlVector<CGameSavePanel *,CUtlMemory<CGameSavePanel *,int>>::PurgeAndDeleteElements(this: &this->m_SavePanels);
    this->m_PanelIndex[0] = -1;
    this->m_PanelIndex[1] = -1;
    this->m_PanelIndex[2] = -1;
    this->m_PanelIndex[3] = -1;
    this->m_PanelIndex[4] = -1;
    CSaveGameBrowserDialog::LayoutPanels(this);
  }
  else
  {
    v3 = this->m_nDeletedPanel + 1;
    v4 = v3 >= 0 && v3 < m_Size;
    CSaveGameBrowserDialog::ScrollSelectionPanels(this, dir: (CSaveGameBrowserDialog::EScrollDirection)(2 * v4 - 1));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10200E20
// Name: public: static void CSaveGameBrowserDialog::PanelMessageFunc_FinishScroll::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSaveGameBrowserDialog::PanelMessageFunc_FinishScroll::InitVar(int a1@<ebp>)
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
  if ( !`CSaveGameBrowserDialog::PanelMessageFunc_FinishScroll::InitVar'::`2'::bAdded )
  {
    `CSaveGameBrowserDialog::PanelMessageFunc_FinishScroll::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBonusMapsDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSaveGameBrowserDialog");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FinishScroll";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10200EB0
// Name: public: static void CSaveGameBrowserDialog::PanelMessageFunc_FinishDelete::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSaveGameBrowserDialog::PanelMessageFunc_FinishDelete::InitVar(int a1@<ebp>)
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
  if ( !`CSaveGameBrowserDialog::PanelMessageFunc_FinishDelete::InitVar'::`2'::bAdded )
  {
    `CSaveGameBrowserDialog::PanelMessageFunc_FinishDelete::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBonusMapsDialog::`vcall'{1120,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSaveGameBrowserDialog");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FinishDelete";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10200F40
// Name: public: static void CSaveGameBrowserDialog::PanelMessageFunc_FinishInsert::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSaveGameBrowserDialog::PanelMessageFunc_FinishInsert::InitVar(int a1@<ebp>)
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
  if ( !`CSaveGameBrowserDialog::PanelMessageFunc_FinishInsert::InitVar'::`2'::bAdded )
  {
    `CSaveGameBrowserDialog::PanelMessageFunc_FinishInsert::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBonusMapsDialog::`vcall'{1124,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSaveGameBrowserDialog");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FinishInsert";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10200FD0
// Name: public: static void CSaveGameBrowserDialog::PanelMessageFunc_FinishOverwriteFadeDown::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSaveGameBrowserDialog::PanelMessageFunc_FinishOverwriteFadeDown::InitVar(int a1@<ebp>)
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
  if ( !`CSaveGameBrowserDialog::PanelMessageFunc_FinishOverwriteFadeDown::InitVar'::`2'::bAdded )
  {
    `CSaveGameBrowserDialog::PanelMessageFunc_FinishOverwriteFadeDown::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::BuildModeDialog::`vcall'{1128,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSaveGameBrowserDialog");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "FinishOverwriteFadeDown";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10201060
// Name: public: static void CSaveGameBrowserDialog::PanelMessageFunc_CloseAfterSave::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CSaveGameBrowserDialog::PanelMessageFunc_CloseAfterSave::InitVar(int a1@<ebp>)
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
  if ( !`CSaveGameBrowserDialog::PanelMessageFunc_CloseAfterSave::InitVar'::`2'::bAdded )
  {
    `CSaveGameBrowserDialog::PanelMessageFunc_CloseAfterSave::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::FileOpenDialog::`vcall'{1132,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CSaveGameBrowserDialog");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CloseAfterSave";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102010F0
// Name: public: CSaveGameBrowserDialog::CSaveGameBrowserDialog(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CSaveGameBrowserDialog *__thiscall CSaveGameBrowserDialog::CSaveGameBrowserDialog(
        CSaveGameBrowserDialog *this,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::Panel *v6; // eax
  vgui::Panel *v7; // edi
  vgui::CFooterPanel *v8; // eax
  vgui::CFooterPanel *v9; // eax
  KeyValues *Key; // edi
  CGameUI *v11; // eax
  vgui::MenuItem *v12; // eax
  KeyValues *ConsoleControlSettings; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: "SaveGameDialog", showTaskbarIcon: 1, bPopup: true);
  this->__vftable = (CSaveGameBrowserDialog_vtbl *)&CSaveGameBrowserDialog::`vftable';
  if ( `CSaveGameBrowserDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CSaveGameBrowserDialog::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CSaveGameBrowserDialog");
    v3->pfnClassName = CSaveGameBrowserDialog::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CSaveGameBrowserDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSaveGameBrowserDialog::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CSaveGameBrowserDialog");
    v4->pfnClassName = CSaveGameBrowserDialog::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CSaveGameBrowserDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSaveGameBrowserDialog::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CSaveGameBrowserDialog");
    v5->pfnClassName = CSaveGameBrowserDialog::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CSaveGameBrowserDialog::PanelMessageFunc_FinishScroll::InitVar(a1: (int)&savedregs);
  CSaveGameBrowserDialog::PanelMessageFunc_FinishDelete::InitVar();
  CSaveGameBrowserDialog::PanelMessageFunc_FinishInsert::InitVar();
  CSaveGameBrowserDialog::PanelMessageFunc_FinishOverwriteFadeDown::InitVar();
  CSaveGameBrowserDialog::PanelMessageFunc_CloseAfterSave::InitVar();
  this->m_ScrollDirection = SCROLL_NONE;
  this->m_bFilterAutosaves = false;
  this->m_SavePanels.m_Memory.m_pMemory = nullptr;
  this->m_SavePanels.m_Memory.m_nAllocationCount = 0;
  this->m_SavePanels.m_Memory.m_nGrowSize = 0;
  this->m_SavePanels.m_Size = 0;
  this->m_SavePanels.m_pElements = nullptr;
  *((_BYTE *)this + 1132) &= 0xFAu;
  this->m_iSelectedSave = -1;
  this->m_nDeletedPanel = -1;
  this->m_nAddedPanel = -1;
  this->m_nUsedStorageSpace = 0;
  this->m_ScrollSpeed = 0.0;
  this->m_ButtonPressed = 0;
  this->m_ScrollCt = 0;
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Frame::SetSizeable(this, state: false);
  v6 = (vgui::Panel *)MemAlloc_Alloc(nSize: 0x14Cu);
  if ( v6 != nullptr )
    v7 = vgui::Panel::Panel(this: v6, parent: this, panelName: "CenterBG");
  else
    v7 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v7);
  this->m_pCenterBg = v7;
  v7->SetPaintBackgroundType(this: v7, a2: 2);
  this->m_pCenterBg->SetVisible(this: this->m_pCenterBg, a2: true);
  v8 = (vgui::CFooterPanel *)MemAlloc_Alloc(nSize: 0x2C4u);
  if ( v8 != nullptr )
    v9 = vgui::CFooterPanel::CFooterPanel(this: v8, parent, panelName: "SaveGameFooter");
  else
    v9 = nullptr;
  this->m_pFooter = v9;
  Key = nullptr;
  v11 = GameUI();
  if ( CGameUI::IsConsoleUI(this: v11) )
  {
    v12 = (vgui::MenuItem *)BasePanel();
    ConsoleControlSettings = (KeyValues *)CBaseModPanel::GetConsoleControlSettings(this: v12);
    Key = KeyValues::FindKey(this: ConsoleControlSettings, keyName: "SaveGameDialog.res", bCreate: false);
  }
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource/SaveGameDialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: Key,
    pConditions: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10201300
// Name: public: void CSaveGameBrowserDialog::AnimateInsertNewPanel(struct SaveGameDescription_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameBrowserDialog::AnimateInsertNewPanel(
        CSaveGameBrowserDialog *this,
        SaveGameDescription_t *pDesc)
{
  CGameSavePanel *v3; // eax
  CGameSavePanel *v4; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CGameSavePanel **m_pMemory; // eax
  int v8; // ecx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  CGameSavePanel *v15; // edi
  vgui::AnimationController *AnimationController; // eax
  vgui::AnimationController *v17; // eax
  vgui::AnimationController *v18; // eax
  KeyValues *v19; // eax
  KeyValues *v20; // eax
  float m_ScrollSpeed; // xmm0_4
  KeyValues *v22; // eax
  float targetValue; // [esp+Ch] [ebp-20h]
  float targetValuea; // [esp+Ch] [ebp-20h]
  float targetValueb; // [esp+Ch] [ebp-20h]
  float duration; // [esp+14h] [ebp-18h]
  float durationa; // [esp+14h] [ebp-18h]
  float durationb; // [esp+14h] [ebp-18h]
  int v29; // [esp+18h] [ebp-14h]
  int animParameter; // [esp+1Ch] [ebp-10h]

  v3 = (CGameSavePanel *)MemAlloc_Alloc(nSize: 0x368u);
  if ( v3 != nullptr )
    v4 = CGameSavePanel::CGameSavePanel(this: v3, parent: this, pSaveDesc: pDesc, bCommandPanel: false);
  else
    v4 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v4);
  v4->SetVisible(this: v4, a2: false);
  m_Size = this->m_SavePanels.m_Size;
  m_nAllocationCount = this->m_SavePanels.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_SavePanels,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_SavePanels.m_Size;
  m_pMemory = this->m_SavePanels.m_Memory.m_pMemory;
  v8 = this->m_SavePanels.m_Size - 2;
  this->m_SavePanels.m_pElements = m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: (unsigned __int8 *)m_pMemory + 8, src: (unsigned __int8 *)m_pMemory + 4, count: 4 * v8);
  if ( this->m_SavePanels.m_Memory.m_pMemory != (CGameSavePanel **)-4 )
    *((_DWORD *)this->m_SavePanels.m_Memory.m_pMemory + 1) = v4;
  animParameter = this->m_PanelYPos[2];
  v29 = this->m_PanelXPos[2];
  this->m_nAddedPanel = 1;
  vgui::Panel::SetPos(this: v4, x: v29, y: animParameter);
  v4->SetVisible(this: v4, a2: true);
  v4->SetEnabled(this: v4, a2: true);
  vgui::Panel::SetZPos(this: v4, z: 0);
  vgui::Panel::SetAlpha(this: v4, alpha: 0);
  v9 = this->m_PanelIndex[0];
  if ( v9 > 0 )
    this->m_PanelIndex[0] = v9 + 1;
  v10 = this->m_PanelIndex[1];
  if ( v10 > 0 )
    this->m_PanelIndex[1] = v10 + 1;
  v11 = this->m_PanelIndex[2];
  if ( v11 > 0 )
    this->m_PanelIndex[2] = v11 + 1;
  v12 = this->m_PanelIndex[3];
  if ( v12 > 0 )
    this->m_PanelIndex[3] = v12 + 1;
  v13 = this->m_PanelIndex[4];
  if ( v13 > 0 )
    this->m_PanelIndex[4] = v13 + 1;
  v14 = this->m_PanelIndex[3];
  if ( v14 < 0 || v14 >= this->m_SavePanels.m_Size )
  {
    v22 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v22 != nullptr )
      v20 = KeyValues::KeyValues(this: v22, setName: "FinishInsert");
    else
      v20 = nullptr;
    m_ScrollSpeed = 0.1;
  }
  else
  {
    v15 = this->m_SavePanels.m_Memory.m_pMemory[v14];
    duration = this->m_ScrollSpeed;
    targetValue = (float)this->m_PanelXPos[4];
    AnimationController = vgui::GetAnimationController();
    vgui::AnimationController::RunAnimationCommand(
      this: AnimationController,
      panel: v15,
      variable: "xpos",
      targetValue,
      startDelaySeconds: 0.0,
      duration,
      interpolator: INTERPOLATOR_SIMPLESPLINE,
      animParameter: 0.0);
    durationa = this->m_ScrollSpeed;
    targetValuea = (float)this->m_PanelYPos[4];
    v17 = vgui::GetAnimationController();
    vgui::AnimationController::RunAnimationCommand(
      this: v17,
      panel: v15,
      variable: "ypos",
      targetValue: targetValuea,
      startDelaySeconds: 0.0,
      duration: durationa,
      interpolator: INTERPOLATOR_SIMPLESPLINE,
      animParameter: 0.0);
    durationb = this->m_ScrollSpeed;
    targetValueb = this->m_PanelAlpha[4];
    v18 = vgui::GetAnimationController();
    vgui::AnimationController::RunAnimationCommand(
      this: v18,
      panel: v15,
      variable: "alpha",
      targetValue: targetValueb,
      startDelaySeconds: 0.0,
      duration: durationb,
      interpolator: INTERPOLATOR_SIMPLESPLINE,
      animParameter: 0.0);
    v19 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v19 != nullptr )
    {
      v20 = KeyValues::KeyValues(this: v19, setName: "FinishInsert");
      m_ScrollSpeed = this->m_ScrollSpeed;
    }
    else
    {
      m_ScrollSpeed = this->m_ScrollSpeed;
      v20 = nullptr;
    }
  }
  ((void (__thiscall *)(CSaveGameBrowserDialog *, CSaveGameBrowserDialog *, KeyValues *, _DWORD))this->PostMessage)(
    a1: this,
    a2: this,
    a3: v20,
    a4: LODWORD(m_ScrollSpeed));
}

//------------------------------------------------------------------------------
// Address: 0x102015C0
// Name: private: void CSaveGameBrowserDialog::ScanSavedGames(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameBrowserDialog::ScanSavedGames(CSaveGameBrowserDialog *this, bool bIgnoreAutosave)
{
  signed int m_Size; // edi
  char *i; // esi
  signed int v5; // esi
  SaveGameDescription_t *m_pMemory; // ecx
  SaveGameDescription_t *v7; // eax
  SaveGameDescription_t *v8; // esi
  CGameSavePanel *v9; // eax
  CGameSavePanel *v10; // esi
  int v11; // edi
  int m_nAllocationCount; // eax
  CGameSavePanel **v13; // ecx
  int v14; // eax
  CGameSavePanel **v15; // edi
  SaveGameDescription_t save; // [esp+Ch] [ebp-3E0h] BYREF
  char szFileName[260]; // [esp+1C4h] [ebp-228h] BYREF
  char szDirectory[260]; // [esp+2C8h] [ebp-124h] BYREF
  signed int j; // [esp+3CCh] [ebp-20h]
  CUtlVector<SaveGameDescription_t,CUtlMemory<SaveGameDescription_t,int> > saveGames; // [esp+3D0h] [ebp-1Ch] BYREF
  SaveGameDescription_t *pSaveDesc; // [esp+3E4h] [ebp-8h]
  int handle; // [esp+3E8h] [ebp-4h] BYREF
  CGameSavePanel *bIgnoreAutosavea; // [esp+3F4h] [ebp+8h]

  *((_BYTE *)this + 1132) &= ~2u;
  m_Size = 0;
  this->m_nUsedStorageSpace = 0;
  CUtlVector<CGameSavePanel *,CUtlMemory<CGameSavePanel *,int>>::PurgeAndDeleteElements(this: &this->m_SavePanels);
  this->m_PanelIndex[0] = -1;
  this->m_PanelIndex[1] = -1;
  this->m_PanelIndex[2] = -1;
  this->m_PanelIndex[3] = -1;
  this->m_PanelIndex[4] = -1;
  memset(&saveGames, 0, sizeof(saveGames));
  V_snprintf(pDest: szDirectory, maxLen: 0x104u, pFormat: "save/*");
  V_DefaultExtension(path: szDirectory, extension: ".sav", pathStringLength: 0x104u);
  V_FixSlashes(pname: szDirectory, separator: 92);
  for ( i = (char *)g_pFullFileSystem->FindFirst(this: g_pFullFileSystem, a2: szDirectory, a3: &handle);
        i != nullptr;
        i = (char *)g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: handle) )
  {
    if ( V_strnicmp(s1: i, s2: "HLSave", n: 6) != 0 )
    {
      V_snprintf(pDest: szFileName, maxLen: 0x104u, pFormat: "save/%s", i);
      V_FixSlashes(pname: szFileName, separator: 92);
      if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: szFileName, a3: "MOD")
        && CSaveGameBrowserDialog::ParseSaveData(this, a2: (int)i, pszFileName: szFileName, pszShortName: i, &save) != 0 )
      {
        this->m_nUsedStorageSpace += save.iSize;
        if ( V_stristr(a1: save.szShortName, a2: (const char *)this, pStr: save.szShortName, pSearch: "dangerous") == nullptr
          && (!bIgnoreAutosave || _V_stricmp(s1: save.szType, s2: "#GameUI_Autosave") != 0) )
        {
          v5 = m_Size;
          if ( m_Size + 1 > saveGames.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<SaveGameDescription_t,int>::Grow(
              this: &saveGames.m_Memory,
              num: m_Size - saveGames.m_Memory.m_nAllocationCount + 1);
            m_Size = saveGames.m_Size;
          }
          m_pMemory = saveGames.m_Memory.m_pMemory;
          saveGames.m_Size = ++m_Size;
          saveGames.m_pElements = saveGames.m_Memory.m_pMemory;
          if ( m_Size - v5 - 1 > 0 )
          {
            _V_memmove(
              dest: (unsigned __int8 *)&saveGames.m_Memory.m_pMemory[v5 + 1],
              src: (unsigned __int8 *)&saveGames.m_Memory.m_pMemory[v5],
              count: 440 * (m_Size - v5 - 1));
            m_pMemory = saveGames.m_Memory.m_pMemory;
          }
          v7 = &m_pMemory[v5];
          if ( v7 != nullptr )
          {
            *v7 = save;
            m_Size = saveGames.m_Size;
          }
        }
      }
    }
  }
  g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: handle);
  v8 = saveGames.m_Memory.m_pMemory;
  this->SortSaveGames(this, a2: saveGames.m_Memory.m_pMemory, a3: m_Size);
  if ( m_Size > 0 )
  {
    pSaveDesc = v8;
    for ( j = m_Size; j != 0; --j )
    {
      v9 = (CGameSavePanel *)MemAlloc_Alloc(nSize: 0x368u);
      if ( v9 != nullptr )
      {
        v10 = CGameSavePanel::CGameSavePanel(this: v9, parent: this, pSaveDesc, bCommandPanel: false);
        bIgnoreAutosavea = v10;
      }
      else
      {
        bIgnoreAutosavea = nullptr;
        v10 = nullptr;
      }
      vgui::Panel::MakeReadyForUse(this: v10);
      v10->SetVisible(this: v10, a2: false);
      v11 = this->m_SavePanels.m_Size;
      m_nAllocationCount = this->m_SavePanels.m_Memory.m_nAllocationCount;
      if ( v11 + 1 > m_nAllocationCount )
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_SavePanels,
          num: v11 - m_nAllocationCount + 1);
      ++this->m_SavePanels.m_Size;
      v13 = this->m_SavePanels.m_Memory.m_pMemory;
      v14 = this->m_SavePanels.m_Size - v11 - 1;
      this->m_SavePanels.m_pElements = v13;
      if ( v14 > 0 )
        _V_memmove(dest: (unsigned __int8 *)&v13[v11 + 1], src: (unsigned __int8 *)&v13[v11], count: 4 * v14);
      v15 = &this->m_SavePanels.m_Memory.m_pMemory[v11];
      if ( v15 != nullptr )
        *v15 = bIgnoreAutosavea;
      ++pSaveDesc;
    }
    v8 = saveGames.m_Memory.m_pMemory;
  }
  this->OnDoneScanningSaveGames(this);
  CSaveGameBrowserDialog::SetSelectedSaveIndex(this, index: 0);
  if ( saveGames.m_Memory.m_nGrowSize >= 0 && v8 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x10201910
// Name: public: virtual void CSaveGameBrowserDialog::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameBrowserDialog::Activate(CSaveGameBrowserDialog *this)
{
  CSaveGameBrowserDialog::ScanSavedGames(this, bIgnoreAutosave: this->m_bFilterAutosaves);
  CSaveGameBrowserDialog::LayoutPanels(this);
  CSaveGameBrowserDialog::AnimateDialogStart(this);
  vgui::Frame::Activate(this);
}

//------------------------------------------------------------------------------
// Address: 0x10201940
// Name: public: virtual void CSaveGameBrowserDialog::RefreshSaveGames(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameBrowserDialog::RefreshSaveGames(CSaveGameBrowserDialog *this)
{
  CCStrike15BasePanel *v2; // eax
  bool m_bFilterAutosaves; // al

  v2 = BasePanel();
  CBaseModPanel::CloseMessageDialog(this: v2, nType: 1u);
  m_bFilterAutosaves = this->m_bFilterAutosaves;
  *((_BYTE *)this + 1132) &= ~4u;
  CSaveGameBrowserDialog::ScanSavedGames(this, bIgnoreAutosave: m_bFilterAutosaves);
  CSaveGameBrowserDialog::LayoutPanels(this);
  CSaveGameBrowserDialog::AnimateDialogStart(this);
}

//------------------------------------------------------------------------------
// Address: 0x10423940
// Name: _dynamic_initializer_for__game_type__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__game_type__()
{
  ConVar::ConVar(
    this: &game_type,
    pName: "game_type",
    pDefaultValue: "0",
    flags: 8204,
    pHelpString: "The current game type. See GameModes.txt.");
  return atexit(func: dynamic_atexit_destructor_for__game_type__);
}

//------------------------------------------------------------------------------
// Address: 0x10423970
// Name: _dynamic_initializer_for__game_mode__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__game_mode__()
{
  ConVar::ConVar(
    this: &game_mode,
    pName: "game_mode",
    pDefaultValue: "0",
    flags: 8204,
    pHelpString: "The current game mode (based on game type). See GameModes.txt.");
  return atexit(func: dynamic_atexit_destructor_for__game_mode__);
}

//------------------------------------------------------------------------------
// Address: 0x104239D0
// Name: _dynamic_initializer_for__game_mode_convars__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__game_mode_convars__()
{
  ConCommand::ConCommand(
    this: &game_mode_convars,
    pName: "game_mode_convars",
    callback: DisplayGameModeConvars,
    pHelpString: "Display the values of the convars for the current game_mode.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__game_mode_convars__);
}

//------------------------------------------------------------------------------
// Address: 0x10435870
// Name: _dynamic_atexit_destructor_for__game_type__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__game_type__()
{
  ConVar::~ConVar(this: &game_type);
}

//------------------------------------------------------------------------------
// Address: 0x10435880
// Name: _dynamic_atexit_destructor_for__game_mode__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__game_mode__()
{
  ConVar::~ConVar(this: &game_mode);
}

//------------------------------------------------------------------------------
// Address: 0x104358A0
// Name: _dynamic_atexit_destructor_for__game_mode_convars__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__game_mode_convars__()
{
  ConCommand::~ConCommand(this: &game_mode_convars);
}

//------------------------------------------------------------------------------
// Address: 0x104239A0
// Name: _dynamic_initializer_for__freestyle_bot_difficulty__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__freestyle_bot_difficulty__()
{
  ConVar::ConVar(
    this: &freestyle_bot_difficulty,
    pName: "freestyle_bot_difficulty",
    pDefaultValue: "0",
    flags: 8204,
    pHelpString: "Bot difficulty for freestyle.");
  return atexit(func: dynamic_atexit_destructor_for__freestyle_bot_difficulty__);
}

//------------------------------------------------------------------------------
// Address: 0x10423A00
// Name: _dynamic_initializer_for__s_GameTypes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_GameTypes__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_GameTypes__);
}

//------------------------------------------------------------------------------
// Address: 0x10423A10
// Name: _dynamic_initializer_for____g_CreateGameTypesIGameTypes_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateGameTypesIGameTypes_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateGameTypesIGameTypes_reg,
           fn: (void *(__cdecl *)())_CreateGameTypesIGameTypes_interface,
           pName: "VENGINE_GAMETYPES_VERSION001");
}

//------------------------------------------------------------------------------
// Address: 0x10435890
// Name: _dynamic_atexit_destructor_for__freestyle_bot_difficulty__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__freestyle_bot_difficulty__()
{
  ConVar::~ConVar(this: &freestyle_bot_difficulty);
}

//------------------------------------------------------------------------------
// Address: 0x104358B0
// Name: _dynamic_atexit_destructor_for__s_GameTypes__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_GameTypes__()
{
  s_GameTypes.__vftable = (GameTypes_vtbl *)&GameTypes::`vftable';
  CUtlVector<GameTypes::GameType *,CUtlMemory<GameTypes::GameType *,int>>::PurgeAndDeleteElements(this: &s_GameTypes.m_GameTypes);
  CUtlVector<GameTypes::Map *,CUtlMemory<GameTypes::Map *,int>>::PurgeAndDeleteElements(this: &s_GameTypes.m_Maps);
  CUtlVector<GameTypes::FreestyleBotDifficulty *,CUtlMemory<GameTypes::FreestyleBotDifficulty *,int>>::PurgeAndDeleteElements(this: &s_GameTypes.m_FreestyleBotDifficulties);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_GameTypes.m_FreestyleBotDifficulties);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_GameTypes.m_Maps);
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&s_GameTypes.m_GameTypes);
  s_GameTypes.__vftable = (GameTypes_vtbl *)&IGameTypes::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10435910
// Name: _dynamic_atexit_destructor_for__InfernoDlightSpacing__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__InfernoDlightSpacing__()
{
  ConVar::~ConVar(this: &InfernoDlightSpacing);
}

//------------------------------------------------------------------------------
// Address: 0x10435920
// Name: _dynamic_atexit_destructor_for__InfernoDlights__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__InfernoDlights__()
{
  ConVar::~ConVar(this: &InfernoDlights);
}

//------------------------------------------------------------------------------
// Address: 0x10435930
// Name: _dynamic_atexit_destructor_for__InfernoFire__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__InfernoFire__()
{
  ConVar::~ConVar(this: &InfernoFire);
}
