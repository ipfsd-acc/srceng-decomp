// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/loadgamedialog.cpp
// Functions: 6
// ============================================================

#include "game\client\cstrike15\gameui\loadgamedialog.h"

//------------------------------------------------------------------------------
// Address: 0x101F0D30
// Name: public: static char const __near * CLoadGameDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CLoadGameDialog::GetPanelClassName()
{
  return "CLoadGameDialog";
}

//------------------------------------------------------------------------------
// Address: 0x101F0D40
// Name: public: virtual void CLoadGameDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoadGameDialog::OnCommand(CLoadGameDialog *this, const char *command)
{
  int v3; // eax
  SaveGameDescription_t *v4; // eax
  int v5; // eax
  vgui::QueryBox *v6; // eax
  vgui::QueryBox *Box; // edi
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  int SelectedItemSaveIndex; // eax
  char sz[256]; // [esp+8h] [ebp-100h] BYREF

  if ( _V_stricmp(s1: command, s2: "loadsave") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "Delete") != 0 )
    {
      if ( _V_stricmp(s1: command, s2: "DeleteConfirmed") != 0 )
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
          CBaseSaveGameDialog::ScanSavedGames(this);
          vgui::PanelListPanel::MoveScrollBarToTop(this: this->m_pGameList);
        }
      }
    }
    else
    {
      v5 = CBaseSaveGameDialog::GetSelectedItemSaveIndex(this);
      if ( v5 >= 0 && v5 < this->m_SaveGames.m_Size )
      {
        v6 = (vgui::QueryBox *)MemAlloc_Alloc(nSize: 0x244u);
        if ( v6 != nullptr )
          Box = vgui::QueryBox::QueryBox(
                  this: v6,
                  title: "#GameUI_ConfirmDeleteSaveGame_Title",
                  queryText: "#GameUI_ConfirmDeleteSaveGame_Info",
                  parent: nullptr);
        else
          Box = nullptr;
        Box->AddActionSignalTarget_2(this: Box, a2: this);
        Box->SetOKButtonText_2(this: Box, a2: "#GameUI_ConfirmDeleteSaveGame_OK");
        v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v8 != nullptr )
          v9 = KeyValues::KeyValues(this: v8, setName: "Command", firstKey: "command", firstValue: "DeleteConfirmed");
        else
          v9 = nullptr;
        vgui::QueryBox::SetOKCommand(this: Box, keyValues: v9);
        Box->DoModal_2(this: Box, a2: nullptr);
      }
    }
  }
  else
  {
    v3 = CBaseSaveGameDialog::GetSelectedItemSaveIndex(this);
    if ( v3 >= 0 && v3 < this->m_SaveGames.m_Size )
    {
      v4 = &this->m_SaveGames.m_Memory.m_pMemory[v3];
      if ( v4 != nullptr && v4->szShortName[0] != 0 )
      {
        V_snprintf(pDest: sz, maxLen: 0x100u, pFormat: "progress_enable\nload %s\n", v4->szShortName);
        engine->ClientCmd_Unrestricted(this: engine, a2: sz);
        this->OnClose(this);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F0F10
// Name: public: virtual struct vgui::PanelMessageMap __near * CLoadGameDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CLoadGameDialog::GetMessageMap(CLoadGameDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CLoadGameDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CLoadGameDialog::GetMessageMap'::`2'::s_pMap;
  `CLoadGameDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CLoadGameDialog");
  `CLoadGameDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F0F40
// Name: public: virtual struct PanelAnimationMap __near * CLoadGameDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CLoadGameDialog::GetAnimMap(CLoadGameDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CLoadGameDialog");
}

//------------------------------------------------------------------------------
// Address: 0x101F0F50
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CLoadGameDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CLoadGameDialog::GetKBMap(CLoadGameDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CLoadGameDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CLoadGameDialog::GetKBMap'::`2'::s_pMap;
  `CLoadGameDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CLoadGameDialog");
  `CLoadGameDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F0F80
// Name: public: CLoadGameDialog::CLoadGameDialog(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CLoadGameDialog *__thiscall CLoadGameDialog::CLoadGameDialog(CLoadGameDialog *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::Button *v6; // eax
  vgui::Button *v7; // eax

  CBaseSaveGameDialog::CBaseSaveGameDialog(this, parent, name: "LoadGameDialog");
  this->__vftable = (CLoadGameDialog_vtbl *)&CLoadGameDialog::`vftable';
  if ( `CLoadGameDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CLoadGameDialog::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CLoadGameDialog");
    v3->pfnClassName = CLoadGameDialog::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "CBaseSaveGameDialog");
  }
  if ( `CLoadGameDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CLoadGameDialog::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CLoadGameDialog");
    v4->pfnClassName = CLoadGameDialog::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "CBaseSaveGameDialog");
  }
  if ( `CLoadGameDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CLoadGameDialog::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CLoadGameDialog");
    v5->pfnClassName = CLoadGameDialog::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CBaseSaveGameDialog");
  }
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 512, tall: 384);
  vgui::Panel::SetMinimumSize(this, wide: 256, tall: 300);
  vgui::Frame::SetSizeable(this, state: true);
  vgui::Frame::SetTitle(this, title: "#GameUI_LoadGame", surfaceTitle: true);
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
    dialogResourceName: "resource/LoadGameDialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  vgui::EditablePanel::SetControlEnabled(this, controlName: "delete", enabled: false);
  return this;
}
