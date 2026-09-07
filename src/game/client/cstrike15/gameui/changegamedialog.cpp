// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/changegamedialog.cpp
// Functions: 8
// ============================================================

#include "game\client\cstrike15\gameui\changegamedialog.h"

//------------------------------------------------------------------------------
// Address: 0x101EEF90
// Name: public: static char const __near * vgui::Frame::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::Frame::GetPanelClassName()
{
  return "Frame";
}

//------------------------------------------------------------------------------
// Address: 0x101EEFA0
// Name: private: void CChangeGameDialog::LoadModList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CChangeGameDialog::LoadModList(CChangeGameDialog *this@<ecx>, char *a2@<edi>)
{
  HANDLE FirstFileA; // esi
  _iobuf *v3; // eax
  _iobuf *v4; // edi
  unsigned int v5; // esi
  char *v6; // ebx
  CModInfo *v7; // eax
  char *GameName; // esi
  KeyValues *v9; // eax
  KeyValues *v10; // esi
  char *v11; // eax
  char szDllDirectory[276]; // [esp+4h] [ebp-56Ch] BYREF
  char szSearchPath[268]; // [esp+118h] [ebp-458h] BYREF
  CModInfo modInfo; // [esp+224h] [ebp-34Ch] BYREF
  _WIN32_FIND_DATAA wfd; // [esp+428h] [ebp-148h] BYREF
  CChangeGameDialog *v17; // [esp+568h] [ebp-8h]
  void *hResult; // [esp+56Ch] [ebp-4h]

  v17 = this;
  V_strncpy(pDest: szSearchPath, pSrc: "*.*", maxLen: 265);
  memset(dst: (int)&wfd, value: nullptr, count: sizeof(wfd));
  FirstFileA = FindFirstFileA(lpFileName: szSearchPath, lpFindFileData: &wfd);
  hResult = FirstFileA;
  if ( FirstFileA != (HANDLE)-1 )
  {
    do
    {
      if ( (wfd.dwFileAttributes & 0x10) != 0 && V_strnicmp(s1: wfd.cFileName, s2: ".", n: 1) != 0 )
      {
        V_snprintf(pDest: szDllDirectory, maxLen: 0x114u, pFormat: "%s\\gameinfo.txt", wfd.cFileName);
        v3 = fopen(file: (_iobuf *)szDllDirectory, mode: "rb");
        v4 = v3;
        if ( v3 != nullptr )
        {
          fseek(stream: v3, offset: 0, whence: 2u);
          v5 = ftell(stream: v4);
          fseek(stream: v4, offset: 0, whence: 0);
          v6 = (char *)((int (__thiscall *)(IMemAlloc *, unsigned int, char *))_g_pMemAlloc->Alloc_2)(
                         a1: _g_pMemAlloc,
                         a2: v5 + 1,
                         a3: a2);
          if ( fread(buffer: (unsigned __int8 *)v6, elementSize: 1u, count: v5, stream: v4) == v5 )
          {
            v6[v5] = 0;
            CModInfo::CModInfo(this: &modInfo);
            CModInfo::LoadGameInfoFromBuffer(this: &modInfo, buffer: v6);
            v7 = ModInfo();
            GameName = CModInfo::GetGameName(this: v7);
            if ( strcmp(CModInfo::GetGameName(this: &modInfo), GameName) != 0 )
            {
              strlwr(string: wfd.cFileName);
              v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
              if ( v9 != nullptr )
                v10 = KeyValues::KeyValues(this: v9, setName: "Mod");
              else
                v10 = nullptr;
              v11 = CModInfo::GetGameName(this: &modInfo);
              KeyValues::SetString(this: v10, keyName: "ModName", value: v11);
              KeyValues::SetString(this: v10, keyName: "ModDir", value: wfd.cFileName);
              v17->m_pModList->AddItem(this: v17->m_pModList, a2: v10, a3: 0, a4: false, a5: false);
            }
            CModInfo::~CModInfo(this: &modInfo);
          }
          a2 = v6;
          ((void (__thiscall *)(IMemAlloc *))_g_pMemAlloc->Free_2)(a1: _g_pMemAlloc);
          fclose(stream: v4);
          FirstFileA = hResult;
        }
      }
    }
    while ( FindNextFileA(hFindFile: FirstFileA, lpFindFileData: &wfd) );
    FindClose(hFindFile: FirstFileA);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EF1D0
// Name: public: virtual void CChangeGameDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChangeGameDialog::OnCommand(CChangeGameDialog *this, const char *command)
{
  vgui::ListPanel_vtbl *v3; // edi
  int v4; // eax
  KeyValues *v5; // eax
  char *String; // eax
  char szCmd[256]; // [esp+8h] [ebp-100h] BYREF

  if ( _V_stricmp(s1: command, s2: "OK") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "Cancel") != 0 )
      vgui::Frame::OnCommand(this, command);
    else
      this->Close(this);
  }
  else if ( this->m_pModList->GetSelectedItemsCount(this: this->m_pModList) > 0 )
  {
    v3 = this->m_pModList->__vftable;
    v4 = v3->GetSelectedItem(this: this->m_pModList, a2: 0);
    v5 = v3->GetItem(this: this->m_pModList, a2: v4);
    if ( v5 != nullptr )
    {
      String = KeyValues::GetString(this: v5, keyName: "ModDir", defaultValue: prType);
      V_snprintf(pDest: szCmd, maxLen: 0x100u, pFormat: "_setgamedir %s\n", String);
      engine->ClientCmd_Unrestricted(this: engine, a2: szCmd);
      engine->ClientCmd_Unrestricted(this: engine, a2: "_restart\n");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EF2D0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Frame::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Frame::GetMessageMap(vgui::Frame *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Frame::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Frame::GetMessageMap'::`2'::s_pMap;
  `vgui::Frame::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Frame");
  `vgui::Frame::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EF300
// Name: public: virtual struct PanelAnimationMap __near * vgui::Frame::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Frame::GetAnimMap(vgui::Frame *this)
{
  return FindOrAddPanelAnimationMap(className: "Frame");
}

//------------------------------------------------------------------------------
// Address: 0x101EF310
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Frame::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Frame::GetKBMap(vgui::Frame *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Frame::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Frame::GetKBMap'::`2'::s_pMap;
  `vgui::Frame::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Frame");
  `vgui::Frame::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101EF340
// Name: public: CChangeGameDialog::CChangeGameDialog(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CChangeGameDialog *__userpurge CChangeGameDialog::CChangeGameDialog@<eax>(
        CChangeGameDialog *this@<ecx>,
        char *a2@<edi>,
        vgui::Panel *parent)
{
  vgui::ListPanel *v4; // eax
  vgui::ListPanel *v5; // eax
  vgui::ListPanel *m_pModList; // ecx
  vgui::ListPanel_vtbl *v7; // edi
  int v8; // eax

  vgui::Frame::Frame(this, parent, panelName: "ChangeGameDialog", showTaskbarIcon: 1, bPopup: true);
  this->__vftable = (CChangeGameDialog_vtbl *)&CChangeGameDialog::`vftable';
  vgui::Panel::SetSize(this, wide: 400, tall: 340);
  vgui::Panel::SetMinimumSize(this, wide: 400, tall: 340);
  vgui::Frame::SetTitle(this, title: "#GameUI_ChangeGame", surfaceTitle: true);
  v4 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v4 != nullptr )
    v5 = vgui::ListPanel::ListPanel(this: v4, parent: this, panelName: "ModList");
  else
    v5 = nullptr;
  this->m_pModList = v5;
  v5->SetEmptyListText_2(this: v5, a2: "#GameUI_NoOtherGamesAvailable");
  this->m_pModList->AddColumnHeader(this: this->m_pModList, a2: 0, a3: "ModName", a4: "#GameUI_Game", a5: 128, a6: 0);
  CChangeGameDialog::LoadModList(this, a2);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource/ChangeGameDialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  if ( this->m_pModList->GetItemCount(this: this->m_pModList) > 0 )
  {
    m_pModList = this->m_pModList;
    v7 = m_pModList->__vftable;
    v8 = m_pModList->GetItemIDFromRow(this: m_pModList, a2: 0);
    v7->SetSingleSelectedItem(this: this->m_pModList, a2: v8);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1038C9C0
// Name: public: virtual class vgui::Menu __near * vgui::Frame::GetSysMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::Frame::GetSysMenu(vgui::Frame *this)
{
  vgui::Menu *v2; // eax
  vgui::Menu *v3; // eax
  vgui::Panel *ChildByName; // edi
  vgui::Panel_vtbl *v5; // ebx
  bool v6; // al
  vgui::Panel *v7; // edi
  vgui::Panel_vtbl *v8; // ebx
  bool v9; // al
  vgui::Panel *v10; // edi
  vgui::Panel_vtbl *v11; // ebx
  bool v12; // al

  if ( this->_sysMenu != nullptr )
    return this->_sysMenu;
  v2 = (vgui::Menu *)MemAlloc_Alloc(nSize: 0x420u);
  if ( v2 != nullptr )
    v3 = vgui::Menu::Menu(this: v2, parent: this, panelName: nullptr);
  else
    v3 = nullptr;
  this->_sysMenu = v3;
  v3->SetVisible(this: v3, a2: false);
  this->_sysMenu->AddActionSignalTarget_2(this: this->_sysMenu, a2: this);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Minimize",
    a3: "#SysMenu_Minimize",
    a4: "Minimize",
    a5: this,
    a6: nullptr);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Maximize",
    a3: "#SysMenu_Maximize",
    a4: "Maximize",
    a5: this,
    a6: nullptr);
  this->_sysMenu->AddMenuItem(
    this: this->_sysMenu,
    a2: "Close",
    a3: "#SysMenu_Close",
    a4: "Close",
    a5: this,
    a6: nullptr);
  ChildByName = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Minimize", recurseDown: false);
  if ( ChildByName != nullptr )
  {
    v5 = ChildByName->__vftable;
    v6 = this->_minimizeButton->IsVisible(this: this->_minimizeButton);
    v5->SetEnabled(this: ChildByName, a2: v6);
  }
  v7 = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Maximize", recurseDown: false);
  if ( v7 != nullptr )
  {
    v8 = v7->__vftable;
    v9 = this->_maximizeButton->IsVisible(this: this->_maximizeButton);
    v8->SetEnabled(this: v7, a2: v9);
  }
  v10 = vgui::Panel::FindChildByName(this: this->_sysMenu, childName: "Close", recurseDown: false);
  if ( v10 != nullptr )
  {
    v11 = v10->__vftable;
    v12 = this->_closeButton->IsVisible(this: this->_closeButton);
    v11->SetEnabled(this: v10, a2: v12);
  }
  return this->_sysMenu;
}
