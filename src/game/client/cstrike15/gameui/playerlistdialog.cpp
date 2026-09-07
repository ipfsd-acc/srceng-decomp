// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/playerlistdialog.cpp
// Functions: 12
// ============================================================

#include "game\client\cstrike15\gameui\playerlistdialog.h"

//------------------------------------------------------------------------------
// Address: 0x101E61A0
// Name: public: static char const __near * CPlayerListDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CPlayerListDialog::GetPanelClassName()
{
  return "CPlayerListDialog";
}

//------------------------------------------------------------------------------
// Address: 0x101E61B0
// Name: private: void CPlayerListDialog::RefreshPlayerProperties(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerListDialog::RefreshPlayerProperties(CPlayerListDialog *this)
{
  CPlayerListDialog *v1; // edi
  vgui::ListPanel *m_pPlayerList; // ecx
  int (__thiscall *GetItemCount)(vgui::ListPanel *); // edx
  int v4; // esi
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  int Int; // edi
  bool v8; // bl
  IGameClientExports *v9; // eax
  vgui::ListPanel *v10; // ecx
  int (__thiscall *v11)(vgui::ListPanel *); // eax
  player_info_s pi; // [esp+8h] [ebp-98h] BYREF
  CPlayerListDialog *v13; // [esp+98h] [ebp-8h]
  int i; // [esp+9Ch] [ebp-4h]

  v1 = this;
  m_pPlayerList = this->m_pPlayerList;
  GetItemCount = m_pPlayerList->GetItemCount;
  v4 = 0;
  v13 = v1;
  i = 0;
  if ( GetItemCount(this: m_pPlayerList) >= 0 )
  {
    do
    {
      v5 = v1->m_pPlayerList->GetItem(this: v1->m_pPlayerList, a2: v4);
      v6 = v5;
      if ( v5 != nullptr )
      {
        Int = KeyValues::GetInt(this: v5, keyName: "index", defaultValue: 0);
        if ( engine->GetPlayerInfo(this: engine, a2: Int, a3: &pi) )
        {
          KeyValues::SetString(this: v6, keyName: "name", value: pi.name);
          v8 = false;
          if ( GameClientExports() != nullptr )
          {
            v9 = GameClientExports();
            v8 = v9->IsPlayerGameVoiceMuted(this: v9, a2: Int);
          }
          if ( pi.fakeplayer )
          {
            KeyValues::SetString(this: v6, keyName: "properties", value: "CPU Player");
          }
          else if ( v8 )
          {
            KeyValues::SetString(this: v6, keyName: "properties", value: "Muted");
          }
          else
          {
            KeyValues::SetString(this: v6, keyName: "properties", value: (char *)prType);
          }
        }
        else
        {
          KeyValues::SetString(this: v6, keyName: "properties", value: "Disconnected");
        }
      }
      v1 = v13;
      v10 = v13->m_pPlayerList;
      v11 = v10->GetItemCount;
      v4 = ++i;
    }
    while ( v4 <= v11(this: v10) );
  }
  v1->m_pPlayerList->RereadAllItems(this: v1->m_pPlayerList);
}

//------------------------------------------------------------------------------
// Address: 0x101E62C0
// Name: private: void CPlayerListDialog::ToggleMuteStateOfSelectedUser(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPlayerListDialog::ToggleMuteStateOfSelectedUser(CPlayerListDialog *this@<ecx>, int a2@<esi>)
{
  int v3; // ebx
  vgui::ListPanel_vtbl *v4; // esi
  int v5; // eax
  KeyValues *v6; // eax
  int v7; // esi
  IGameClientExports *v8; // eax
  IGameClientExports *v9; // ecx
  void (__thiscall *UnmutePlayerGameVoice)(IGameClientExports *, int); // eax
  vgui::ListPanel *m_pPlayerList; // ecx
  int (__thiscall *GetItemCount)(vgui::ListPanel *); // eax
  int v13; // esi
  KeyValues *v14; // eax
  KeyValues *v15; // esi
  int Int; // ebx
  IGameClientExports *v17; // eax
  bool v18; // zf
  char v19; // al
  vgui::ListPanel *v20; // ecx
  int (__thiscall *v21)(vgui::ListPanel *); // eax
  _BYTE v23[8]; // [esp+4h] [ebp-98h] BYREF
  char value[136]; // [esp+Ch] [ebp-90h] BYREF
  int v25; // [esp+94h] [ebp-8h]
  char v26; // [esp+9Bh] [ebp-1h]

  if ( GameClientExports() != nullptr )
  {
    v3 = 0;
    if ( this->m_pPlayerList->GetSelectedItemsCount(this: this->m_pPlayerList) <= 0 )
    {
LABEL_8:
      m_pPlayerList = this->m_pPlayerList;
      GetItemCount = m_pPlayerList->GetItemCount;
      v13 = 0;
      v25 = 0;
      if ( GetItemCount(this: m_pPlayerList) >= 0 )
      {
        do
        {
          v14 = this->m_pPlayerList->GetItem(this: this->m_pPlayerList, a2: v13);
          v15 = v14;
          if ( v14 != nullptr )
          {
            Int = KeyValues::GetInt(this: v14, keyName: "index", defaultValue: 0);
            if ( engine->GetPlayerInfo(this: engine, a2: Int, a3: (player_info_s *)v23) )
            {
              KeyValues::SetString(this: v15, keyName: "name", value);
              v26 = 0;
              if ( GameClientExports() == nullptr
                || (v17 = GameClientExports(), v18 = !v17->IsPlayerGameVoiceMuted(this: v17, a2: Int), v19 = 1, v18) )
              {
                v19 = v26;
              }
              if ( value[108] != 0 )
              {
                KeyValues::SetString(this: v15, keyName: "properties", value: "CPU Player");
              }
              else if ( v19 != 0 )
              {
                KeyValues::SetString(this: v15, keyName: "properties", value: "Muted");
              }
              else
              {
                KeyValues::SetString(this: v15, keyName: "properties", value: (char *)prType);
              }
            }
            else
            {
              KeyValues::SetString(this: v15, keyName: "properties", value: "Disconnected");
            }
          }
          v20 = this->m_pPlayerList;
          v21 = v20->GetItemCount;
          v13 = ++v25;
        }
        while ( v13 <= v21(this: v20) );
      }
      this->m_pPlayerList->RereadAllItems(this: this->m_pPlayerList);
      this->OnItemSelected(this);
    }
    else
    {
      while ( 1 )
      {
        v4 = this->m_pPlayerList->__vftable;
        v5 = v4->GetSelectedItem(this: this->m_pPlayerList, a2: v3);
        v6 = v4->GetItem(this: this->m_pPlayerList, a2: v5);
        if ( v6 == nullptr )
          break;
        v7 = KeyValues::GetInt(this: v6, keyName: "index", defaultValue: 0);
        v8 = GameClientExports();
        if ( ((unsigned __int8 (__thiscall *)(IGameClientExports *, int, int))v8->IsPlayerGameVoiceMuted)(
               a1: v8,
               a2: v7,
               a3: a2) != 0 )
        {
          v9 = GameClientExports();
          UnmutePlayerGameVoice = v9->UnmutePlayerGameVoice;
        }
        else
        {
          v9 = GameClientExports();
          UnmutePlayerGameVoice = v9->MutePlayerGameVoice;
        }
        a2 = v7;
        ((void (__thiscall *)(IGameClientExports *))UnmutePlayerGameVoice)(a1: v9);
        if ( ++v3 >= this->m_pPlayerList->GetSelectedItemsCount(this: this->m_pPlayerList) )
          goto LABEL_8;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E6490
// Name: private: virtual void CPlayerListDialog::OnItemSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CPlayerListDialog::OnItemSelected(CPlayerListDialog *this@<ecx>, int a2@<edi>)
{
  vgui::ListPanel *m_pPlayerList; // ecx
  int (__thiscall *GetSelectedItemsCount)(vgui::ListPanel *); // edx
  vgui::ListPanel *v5; // ecx
  vgui::ListPanel_vtbl *v6; // edi
  int v7; // eax
  KeyValues *v8; // edi
  int Int; // ebx
  IGameClientExports *v10; // eax
  IGameClientExports_vtbl *v11; // ebx
  int v12; // eax
  player_info_s pi; // [esp+4h] [ebp-9Ch] BYREF
  BOOL bMuteButtonEnabled; // [esp+94h] [ebp-Ch]
  int iLocalPlayer; // [esp+98h] [ebp-8h]
  bool isValidPlayer; // [esp+9Fh] [ebp-1h]

  CPlayerListDialog::RefreshPlayerProperties(this);
  m_pPlayerList = this->m_pPlayerList;
  GetSelectedItemsCount = m_pPlayerList->GetSelectedItemsCount;
  LOBYTE(bMuteButtonEnabled) = 0;
  if ( GetSelectedItemsCount(this: m_pPlayerList) <= 0 )
  {
    this->m_pMuteButton->SetText(this: this->m_pMuteButton, a2: "#GameUI_MuteIngameVoice");
  }
  else
  {
    v5 = this->m_pPlayerList;
    v6 = v5->__vftable;
    v7 = ((int (__thiscall *)(vgui::ListPanel *, _DWORD, int))v5->GetSelectedItem)(a1: v5, a2: 0, a3: a2);
    v8 = v6->GetItem(this: this->m_pPlayerList, a2: v7);
    iLocalPlayer = engine->GetLocalPlayer(this: engine);
    Int = KeyValues::GetInt(this: v8, keyName: "index", defaultValue: 0);
    isValidPlayer = engine->GetPlayerInfo(this: engine, a2: Int, a3: &pi);
    if ( pi.fakeplayer || Int == iLocalPlayer )
      isValidPlayer = false;
    if ( v8 != nullptr && isValidPlayer && GameClientExports() != nullptr )
    {
      v10 = GameClientExports();
      v11 = v10->__vftable;
      iLocalPlayer = (int)v10;
      v12 = KeyValues::GetInt(this: v8, keyName: "index", defaultValue: 0);
      v11->IsPlayerGameVoiceMuted(this: (IGameClientExports *)iLocalPlayer, a2: v12);
    }
    ((void (__thiscall *)(vgui::Button *))this->m_pMuteButton->SetText)(a1: this->m_pMuteButton);
    if ( GameClientExports() != nullptr && isValidPlayer )
      LOBYTE(bMuteButtonEnabled) = 1;
  }
  this->m_pMuteButton->SetEnabled(this: this->m_pMuteButton, a2: bMuteButtonEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x101E65D0
// Name: public: virtual struct vgui::PanelMessageMap __near * CPlayerListDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CPlayerListDialog::GetMessageMap(CPlayerListDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CPlayerListDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CPlayerListDialog::GetMessageMap'::`2'::s_pMap;
  `CPlayerListDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CPlayerListDialog");
  `CPlayerListDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E6600
// Name: public: virtual struct PanelAnimationMap __near * CPlayerListDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CPlayerListDialog::GetAnimMap(CPlayerListDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CPlayerListDialog");
}

//------------------------------------------------------------------------------
// Address: 0x101E6610
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CPlayerListDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CPlayerListDialog::GetKBMap(CPlayerListDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CPlayerListDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CPlayerListDialog::GetKBMap'::`2'::s_pMap;
  `CPlayerListDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CPlayerListDialog");
  `CPlayerListDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101E6670
// Name: public: virtual void CPlayerListDialog::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerListDialog::Activate(CPlayerListDialog *this)
{
  int v2; // esi
  int v3; // edi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  vgui::ListPanel *m_pPlayerList; // ecx
  vgui::ListPanel_vtbl *v7; // esi
  int v8; // eax
  player_info_s pi; // [esp+Ch] [ebp-B4h] BYREF
  char szPlayerIndex[32]; // [esp+9Ch] [ebp-24h] BYREF
  int maxClients; // [esp+BCh] [ebp-4h]

  vgui::Frame::Activate(this);
  this->m_pPlayerList->DeleteAllItems(this: this->m_pPlayerList);
  v2 = engine->GetMaxClients(this: engine);
  v3 = 1;
  for ( maxClients = v2; v3 <= v2; ++v3 )
  {
    if ( engine->GetPlayerInfo(this: engine, a2: v3, a3: &pi) )
    {
      V_snprintf(pDest: szPlayerIndex, maxLen: 0x20u, pFormat: "%d", v3);
      v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v4 != nullptr )
        v5 = KeyValues::KeyValues(this: v4, setName: szPlayerIndex);
      else
        v5 = nullptr;
      KeyValues::SetString(this: v5, keyName: "Name", value: pi.name);
      KeyValues::SetInt(this: v5, keyName: "index", value: v3);
      this->m_pPlayerList->AddItem(this: this->m_pPlayerList, a2: v5, a3: 0, a4: false, a5: false);
      v2 = maxClients;
    }
  }
  CPlayerListDialog::RefreshPlayerProperties(this);
  m_pPlayerList = this->m_pPlayerList;
  v7 = m_pPlayerList->__vftable;
  v8 = ((int (__stdcall *)(_DWORD))m_pPlayerList->GetItemIDFromRow)(a1: 0);
  v7->SetSingleSelectedItem(this: this->m_pPlayerList, a2: v8);
  this->OnItemSelected(this);
}

//------------------------------------------------------------------------------
// Address: 0x101E6780
// Name: private: virtual void CPlayerListDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPlayerListDialog::OnCommand(CPlayerListDialog *this, const char *command)
{
  if ( _V_stricmp(s1: command, s2: "Mute") != 0 )
    vgui::Frame::OnCommand(this, command);
  else
    CPlayerListDialog::ToggleMuteStateOfSelectedUser(this, a2: (int)this);
}

//------------------------------------------------------------------------------
// Address: 0x101E67C0
// Name: public: static void CPlayerListDialog::PanelMessageFunc_OnItemSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CPlayerListDialog::PanelMessageFunc_OnItemSelected::InitVar(int a1@<ebp>)
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
  if ( !`CPlayerListDialog::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded )
  {
    `CPlayerListDialog::PanelMessageFunc_OnItemSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBonusMapsDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CPlayerListDialog");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "ItemSelected";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101E6850
// Name: public: CPlayerListDialog::CPlayerListDialog(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CPlayerListDialog *__thiscall CPlayerListDialog::CPlayerListDialog(CPlayerListDialog *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::Button *v6; // eax
  vgui::Button *v7; // eax
  vgui::ListPanel *v8; // eax
  vgui::ListPanel *v9; // eax

  vgui::Frame::Frame(this, parent, panelName: "PlayerListDialog", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CPlayerListDialog_vtbl *)&CPlayerListDialog::`vftable';
  if ( `CPlayerListDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CPlayerListDialog::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CPlayerListDialog");
    v3->pfnClassName = CPlayerListDialog::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CPlayerListDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CPlayerListDialog::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CPlayerListDialog");
    v4->pfnClassName = CPlayerListDialog::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CPlayerListDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CPlayerListDialog::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CPlayerListDialog");
    v5->pfnClassName = CPlayerListDialog::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CPlayerListDialog::PanelMessageFunc_OnItemSelected::InitVar();
  vgui::Panel::SetSize(this, wide: 320, tall: 240);
  vgui::Frame::SetTitle(this, title: "#GameUI_CurrentPlayers", surfaceTitle: true);
  v6 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v6 != nullptr )
    v7 = vgui::Button::Button(
           this: v6,
           parent: this,
           panelName: "MuteButton",
           text: prType,
           pActionSignalTarget: nullptr,
           pCmd: nullptr);
  else
    v7 = nullptr;
  this->m_pMuteButton = v7;
  v8 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v8 != nullptr )
    v9 = vgui::ListPanel::ListPanel(this: v8, parent: this, panelName: "PlayerList");
  else
    v9 = nullptr;
  this->m_pPlayerList = v9;
  v9->AddColumnHeader(this: v9, a2: 0, a3: "Name", a4: "#GameUI_PlayerName", a5: 180, a6: 0);
  this->m_pPlayerList->AddColumnHeader(
    this: this->m_pPlayerList,
    a2: 1,
    a3: "Properties",
    a4: "#GameUI_Properties",
    a5: 80,
    a6: 0);
  this->m_pPlayerList->SetEmptyListText_2(this: this->m_pPlayerList, a2: "#GameUI_NoOtherPlayersInGame");
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "Resource/PlayerListDialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101E6A00
// Name: __CreateCRunGameEngineIRunGameEngine_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CRunGameEngine *__cdecl _CreateCRunGameEngineIRunGameEngine_interface()
{
  return &_g_CRunGameEngine_singleton;
}
