// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/savegamedialog.cpp
// Functions: 9
// ============================================================

#include "game\client\cstrike15\gameui\savegamedialog.h"

//------------------------------------------------------------------------------
// Address: 0x101F47B0
// Name: public: static char const __near * CSaveGameDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CSaveGameDialog::GetPanelClassName()
{
  return "CSaveGameDialog";
}

//------------------------------------------------------------------------------
// Address: 0x101F47C0
// Name: public: virtual void CSaveGameDialog::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameDialog::Activate(CSaveGameDialog *this)
{
  vgui::Frame::Activate(this);
  CBaseSaveGameDialog::ScanSavedGames(this);
}

//------------------------------------------------------------------------------
// Address: 0x101F47D0
// Name: public: static void CSaveGameDialog::FindSaveSlot(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CSaveGameDialog::FindSaveSlot(char *buffer, int bufsize)
{
  int v2; // esi
  void *v3; // eax
  _BYTE *v4; // eax
  char szFileName[512]; // [esp+8h] [ebp-200h] BYREF

  *buffer = 0;
  v2 = 0;
  while ( 1 )
  {
    V_snprintf(pDest: szFileName, maxLen: 0x200u, pFormat: "save/Half-Life-%03i.sav", v2);
    v3 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: szFileName, a3: "rb", a4: 0);
    if ( v3 == nullptr )
      break;
    g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v3);
    if ( ++v2 >= 1000 )
      return;
  }
  V_strncpy(pDest: buffer, pSrc: &szFileName[5], maxLen: bufsize);
  strstr(str1: (unsigned __int8 *)buffer, str2: ".sav");
  if ( v4 != nullptr )
    *v4 = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F4870
// Name: protected: virtual void CSaveGameDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameDialog::OnCommand(CSaveGameDialog *this, const char *command)
{
  int v3; // eax
  vgui::QueryBox *v4; // eax
  vgui::QueryBox *Box; // esi
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  int SelectedItemSaveIndex; // eax
  CGameUI *v9; // eax
  char sz[256]; // [esp+8h] [ebp-180h] BYREF
  char saveName[128]; // [esp+108h] [ebp-80h] BYREF

  if ( _V_stricmp(s1: command, s2: "loadsave") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "SaveOverwriteConfirmed") != 0 )
    {
      vgui::Frame::OnCommand(this, command);
    }
    else
    {
      SelectedItemSaveIndex = CBaseSaveGameDialog::GetSelectedItemSaveIndex(this);
      if ( SelectedItemSaveIndex >= 0 && SelectedItemSaveIndex < this->m_SaveGames.m_Size )
      {
        CBaseSaveGameDialog::DeleteSaveGame(
          this,
          fileName: this->m_SaveGames.m_Memory.m_pMemory[SelectedItemSaveIndex].szFileName);
        CSaveGameDialog::FindSaveSlot(buffer: saveName, bufsize: 128);
        if ( saveName[0] != 0 )
        {
          V_snprintf(pDest: sz, maxLen: 0x100u, pFormat: "save %s\n", saveName);
          engine->ClientCmd_Unrestricted(this: engine, a2: sz);
          this->Close(this);
          v9 = GameUI();
          CGameUI::HideGameUI(this: v9);
        }
      }
    }
  }
  else
  {
    v3 = CBaseSaveGameDialog::GetSelectedItemSaveIndex(this);
    if ( v3 >= 0 && v3 < this->m_SaveGames.m_Size )
    {
      if ( this->m_SaveGames.m_Memory.m_pMemory[v3].iTimestamp == -1 )
      {
        this->OnCommand(this, a2: "SaveOverwriteConfirmed");
      }
      else
      {
        v4 = (vgui::QueryBox *)MemAlloc_Alloc(nSize: 0x244u);
        if ( v4 != nullptr )
          Box = vgui::QueryBox::QueryBox(
                  this: v4,
                  title: "#GameUI_ConfirmOverwriteSaveGame_Title",
                  queryText: "#GameUI_ConfirmOverwriteSaveGame_Info",
                  parent: nullptr);
        else
          Box = nullptr;
        Box->AddActionSignalTarget_2(this: Box, a2: this);
        Box->SetOKButtonText_2(this: Box, a2: "#GameUI_ConfirmOverwriteSaveGame_OK");
        v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v6 != nullptr )
          v7 = KeyValues::KeyValues(
                 this: v6,
                 setName: "Command",
                 firstKey: "command",
                 firstValue: "SaveOverwriteConfirmed");
        else
          v7 = nullptr;
        vgui::QueryBox::SetOKCommand(this: Box, keyValues: v7);
        Box->DoModal_2(this: Box, a2: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F4A30
// Name: public: virtual struct vgui::PanelMessageMap __near * CSaveGameDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CSaveGameDialog::GetMessageMap(CSaveGameDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CSaveGameDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CSaveGameDialog::GetMessageMap'::`2'::s_pMap;
  `CSaveGameDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CSaveGameDialog");
  `CSaveGameDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F4A60
// Name: public: virtual struct PanelAnimationMap __near * CSaveGameDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CSaveGameDialog::GetAnimMap(CSaveGameDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CSaveGameDialog");
}

//------------------------------------------------------------------------------
// Address: 0x101F4A70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CSaveGameDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CSaveGameDialog::GetKBMap(CSaveGameDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CSaveGameDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CSaveGameDialog::GetKBMap'::`2'::s_pMap;
  `CSaveGameDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CSaveGameDialog");
  `CSaveGameDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F4AA0
// Name: protected: virtual void CSaveGameDialog::OnScanningSaveGames(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSaveGameDialog::OnScanningSaveGames(CSaveGameDialog *this)
{
  int m_Size; // edx
  SaveGameDescription_t save; // [esp+0h] [ebp-1B8h] BYREF

  strcpy(save.szShortName, "NewSavedGame");
  memset(&save.szShortName[13], 0, 211);
  strcpy(save.szComment, "#GameUI_NewSaveGame");
  memset(&save.szComment[20], 0, 156);
  strcpy(save.szFileTime, "Current");
  m_Size = this->m_SaveGames.m_Size;
  memset(&save.szFileTime[8], 0, 24);
  save.iTimestamp = -1;
  save.iSize = 0;
  CUtlVector<SaveGameDescription_t,CUtlMemory<SaveGameDescription_t,int>>::InsertBefore(
    this: &this->m_SaveGames,
    elem: m_Size,
    src: &save);
}

//------------------------------------------------------------------------------
// Address: 0x101F4BF0
// Name: public: CSaveGameDialog::CSaveGameDialog(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CSaveGameDialog *__thiscall CSaveGameDialog::CSaveGameDialog(CSaveGameDialog *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::Button *v6; // eax
  vgui::Button *v7; // eax

  CBaseSaveGameDialog::CBaseSaveGameDialog(this, parent, name: "SaveGameDialog");
  this->__vftable = (CSaveGameDialog_vtbl *)&CSaveGameDialog::`vftable';
  if ( `CSaveGameDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CSaveGameDialog::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CSaveGameDialog");
    v3->pfnClassName = CSaveGameDialog::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseSaveGameDialog");
  }
  if ( `CSaveGameDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CSaveGameDialog::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CSaveGameDialog");
    v4->pfnClassName = CSaveGameDialog::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "CBaseSaveGameDialog");
  }
  if ( `CSaveGameDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CSaveGameDialog::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CSaveGameDialog");
    v5->pfnClassName = CSaveGameDialog::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseSaveGameDialog");
  }
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 512, tall: 384);
  vgui::Frame::SetSizeable(this, state: true);
  vgui::Frame::SetTitle(this, title: "#GameUI_SaveGame", surfaceTitle: true);
  v6 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v6 != nullptr )
    v7 = vgui::Button::Button(
           this: v6,
           parent: this,
           panelName: "Cancel",
           text: "#GameUI_Cancel",
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v7 = nullptr;
  v7->SetCommand(this: v7, a2: "Close");
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource\\SaveGameDialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}
