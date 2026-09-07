// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/createmultiplayergameserverpage.cpp
// Functions: 14
// ============================================================

#include "game\client\cstrike15\gameui\createmultiplayergameserverpage.h"

//------------------------------------------------------------------------------
// Address: 0x101D3220
// Name: public: static char const __near * CCreateMultiplayerGameServerPage::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CCreateMultiplayerGameServerPage::GetPanelClassName()
{
  return "CCreateMultiplayerGameServerPage";
}

//------------------------------------------------------------------------------
// Address: 0x101D3230
// Name: public: void CCreateMultiplayerGameServerPage::EnableBots(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMultiplayerGameServerPage::EnableBots(CCreateMultiplayerGameServerPage *this, KeyValues *data)
{
  int Int; // ebx
  int v4; // eax
  int v5; // eax
  vgui::Panel *ChildByName; // eax
  void *v7; // eax
  char buttonName[64]; // [esp+Ch] [ebp-40h] BYREF

  this->m_pSavedData = data;
  Int = KeyValues::GetInt(this: data, keyName: "bot_quota", defaultValue: 0);
  this->SetControlInt(this, a2: "BotQuotaCombo", a3: Int);
  this->m_pEnableBotsCheck->SetSelected(this: this->m_pEnableBotsCheck, a2: Int > 0);
  v4 = KeyValues::GetInt(this: data, keyName: "bot_difficulty", defaultValue: 0);
  v5 = v4 <= 0 ? 0 : v4;
  if ( v5 > 3 )
    v5 = 3;
  V_snprintf(pDest: buttonName, maxLen: 0x40u, pFormat: "SkillLevel%d", v5);
  ChildByName = vgui::Panel::FindChildByName(this, childName: buttonName, recurseDown: false);
  v7 = __RTDynamicCast(
         inptr: ChildByName,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &vgui::RadioButton `RTTI Type Descriptor',
         isReference: 0);
  if ( v7 != nullptr )
    (*(void (__thiscall **)(void *, int))(*(_DWORD *)v7 + 1020))(a1: v7, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x101D3300
// Name: protected: virtual void CCreateMultiplayerGameServerPage::OnApplyChanges(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCreateMultiplayerGameServerPage::OnApplyChanges(
        CCreateMultiplayerGameServerPage *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>)
{
  KeyValues *ActiveItemUserData; // eax
  char *String; // eax
  int v6; // edi
  int v7; // ebx
  int v8; // edi
  vgui::Panel *ChildByName; // eax
  void *v10; // eax
  char buttonName[64]; // [esp+4h] [ebp-50h] BYREF
  ConVarRef bot_difficulty; // [esp+44h] [ebp-10h] BYREF
  ConVarRef bot_quota; // [esp+4Ch] [ebp-8h] BYREF

  ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pMapList);
  String = KeyValues::GetString(this: ActiveItemUserData, keyName: "mapname", defaultValue: prType);
  V_strncpy(pDest: this->m_szMapName, pSrc: String, maxLen: 64);
  if ( this->m_pSavedData != nullptr )
  {
    v6 = ((int (__thiscall *)(CCreateMultiplayerGameServerPage *, const char *, _DWORD, int, int))this->GetControlInt)(
           a1: this,
           a2: "BotQuotaCombo",
           a3: 0,
           a4: a3,
           a5: a2);
    if ( !this->m_pEnableBotsCheck->IsSelected(this: this->m_pEnableBotsCheck) )
      v6 = 0;
    KeyValues::SetInt(this: this->m_pSavedData, keyName: "bot_quota", value: v6);
    ConVarRef::ConVarRef(this: &bot_quota, pName: "bot_quota");
    bot_quota.m_pConVar->SetValue_2(this: bot_quota.m_pConVar, a2: v6);
    v7 = 0;
    v8 = 0;
    while ( 1 )
    {
      V_snprintf(pDest: buttonName, maxLen: 0x40u, pFormat: "SkillLevel%d", v8);
      ChildByName = vgui::Panel::FindChildByName(this, childName: buttonName, recurseDown: false);
      v10 = __RTDynamicCast(
              inptr: ChildByName,
              VfDelta: 0,
              SrcType: &vgui::Panel `RTTI Type Descriptor',
              TargetType: &vgui::RadioButton `RTTI Type Descriptor',
              isReference: 0);
      if ( v10 != nullptr && (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)v10 + 1024))(a1: v10) != 0 )
        break;
      if ( ++v8 >= 4 )
        goto LABEL_10;
    }
    v7 = v8;
LABEL_10:
    KeyValues::SetInt(this: this->m_pSavedData, keyName: "bot_difficulty", value: v7);
    ConVarRef::ConVarRef(this: &bot_difficulty, pName: "bot_difficulty");
    bot_difficulty.m_pConVar->SetValue_2(this: bot_difficulty.m_pConVar, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D3430
// Name: private: void CCreateMultiplayerGameServerPage::LoadMaps(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCreateMultiplayerGameServerPage::LoadMaps(
        CCreateMultiplayerGameServerPage *this@<ecx>,
        int a2@<edi>,
        const char *pszPathID)
{
  CModInfo *v3; // eax
  KeyValues *HiddenMaps; // ebx
  char *i; // esi
  int v6; // eax
  _BYTE *v7; // eax
  CModInfo *v8; // eax
  const char *GameName; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  char mapname[256]; // [esp+8h] [ebp-108h] BYREF
  CCreateMultiplayerGameServerPage *v14; // [esp+108h] [ebp-8h]
  int findHandle; // [esp+10Ch] [ebp-4h] BYREF

  v14 = this;
  findHandle = 0;
  v3 = ModInfo();
  HiddenMaps = CModInfo::GetHiddenMaps(this: v3);
  for ( i = (char *)g_pFullFileSystem->FindFirst(this: g_pFullFileSystem, a2: "maps/*.bsp", a3: &findHandle);
        i != nullptr;
        i = (char *)((int (__thiscall *)(IFileSystem *))g_pFullFileSystem->FindNext)(a1: g_pFullFileSystem) )
  {
    V_snprintf(pDest: mapname, maxLen: 0x100u, pFormat: "maps/%s", i);
    if ( ((unsigned __int8 (__thiscall *)(IBaseFileSystem *, char *, const char *, int))g_pFullFileSystem->FileExists)(
           a1: &g_pFullFileSystem->IBaseFileSystem,
           a2: mapname,
           a3: pszPathID,
           a4: a2) != 0 )
    {
      _V_strstr(s1: i, search: "maps");
      if ( v6 != 0 )
        V_strncpy(pDest: mapname, pSrc: (char *)(v6 + 5), maxLen: 255);
      else
        V_strncpy(pDest: mapname, pSrc: i, maxLen: 255);
      _V_strstr(s1: mapname, search: ".bsp");
      if ( v7 != nullptr )
        *v7 = 0;
      v8 = ModInfo();
      GameName = CModInfo::GetGameName(this: v8);
      if ( (_V_stricmp(s1: GameName, s2: "Half-Life") != 0
         || mapname[0] != 99 && mapname[0] != 116
         || mapname[2] != 97
         || mapname[1] < 48
         || mapname[1] > 53)
        && (HiddenMaps == nullptr || KeyValues::GetInt(this: HiddenMaps, keyName: mapname, defaultValue: 0) == 0) )
      {
        v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v10 != nullptr )
          v11 = KeyValues::KeyValues(this: v10, setName: "data", firstKey: "mapname", firstValue: mapname);
        else
          v11 = nullptr;
        v14->m_pMapList->AddItem_2(this: v14->m_pMapList, a2: mapname, a3: v11);
      }
    }
    a2 = findHandle;
  }
  g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: findHandle);
}

//------------------------------------------------------------------------------
// Address: 0x101D35F0
// Name: private: void CCreateMultiplayerGameServerPage::LoadMapList(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CCreateMultiplayerGameServerPage::LoadMapList(
        CCreateMultiplayerGameServerPage *this@<ecx>,
        int a2@<edi>)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  const char *v5; // edi
  CModInfo *v6; // eax
  const char *GameName; // eax
  CModInfo *v8; // eax
  const char *FallbackDir; // eax

  vgui::ComboBox::RemoveAll(this: this->m_pMapList);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "data", firstKey: "mapname", firstValue: "#GameUI_RandomMap");
  else
    v4 = nullptr;
  this->m_pMapList->AddItem_2(this: this->m_pMapList, a2: "#GameUI_RandomMap", a3: v4);
  v5 = "MOD";
  v6 = ModInfo();
  GameName = CModInfo::GetGameName(this: v6);
  if ( _V_stricmp(s1: GameName, s2: "Half-Life") == 0 )
    v5 = nullptr;
  CCreateMultiplayerGameServerPage::LoadMaps(this, a2: (int)v5, pszPathID: v5);
  v8 = ModInfo();
  FallbackDir = CModInfo::GetFallbackDir(this: v8);
  if ( v5 != nullptr && *FallbackDir != 0 )
    CCreateMultiplayerGameServerPage::LoadMaps(this, a2, pszPathID: "GAME_FALLBACK");
  this->m_pMapList->ActivateItem(this: this->m_pMapList, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101D36A0
// Name: public: bool CCreateMultiplayerGameServerPage::IsRandomMapSelected(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCreateMultiplayerGameServerPage::IsRandomMapSelected(CCreateMultiplayerGameServerPage *this)
{
  KeyValues *ActiveItemUserData; // eax
  char *String; // eax

  ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pMapList);
  String = KeyValues::GetString(this: ActiveItemUserData, keyName: "mapname", defaultValue: prType);
  return _V_stricmp(s1: String, s2: "#GameUI_RandomMap") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101D36D0
// Name: public: char const __near * CCreateMultiplayerGameServerPage::GetMapName(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
const char *__thiscall CCreateMultiplayerGameServerPage::GetMapName(CCreateMultiplayerGameServerPage *this)
{
  int v2; // edi
  const char *result; // eax
  KeyValues *ActiveItemUserData; // eax
  int v5; // eax
  KeyValues *ItemUserData; // eax

  v2 = this->m_pMapList->GetItemCount(this: this->m_pMapList);
  if ( v2 <= 1 )
    return nullptr;
  ActiveItemUserData = vgui::ComboBox::GetActiveItemUserData(this: this->m_pMapList);
  result = KeyValues::GetString(this: ActiveItemUserData, keyName: "mapname", defaultValue: prType);
  if ( strcmp(result, "#GameUI_RandomMap") == 0 )
  {
    v5 = _RandomInt(this: nullptr, a2: 1, a3: v2 - 1);
    ItemUserData = vgui::ComboBox::GetItemUserData(this: this->m_pMapList, itemID: v5);
    return KeyValues::GetString(this: ItemUserData, keyName: "mapname", defaultValue: prType);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D3770
// Name: public: void CCreateMultiplayerGameServerPage::SetMap(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMultiplayerGameServerPage::SetMap(CCreateMultiplayerGameServerPage *this, const char *mapName)
{
  int v3; // esi
  KeyValues *ItemUserData; // eax
  char *String; // eax

  v3 = 0;
  if ( this->m_pMapList->GetItemCount(this: this->m_pMapList) > 0 )
  {
    while ( 1 )
    {
      if ( this->m_pMapList->IsItemIDValid(this: this->m_pMapList, a2: v3) )
      {
        ItemUserData = vgui::ComboBox::GetItemUserData(this: this->m_pMapList, itemID: v3);
        String = KeyValues::GetString(this: ItemUserData, keyName: "mapname", defaultValue: prType);
        if ( _V_stricmp(s1: String, s2: mapName) == 0 )
          break;
      }
      if ( ++v3 >= this->m_pMapList->GetItemCount(this: this->m_pMapList) )
        return;
    }
    this->m_pMapList->ActivateItem(this: this->m_pMapList, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D3810
// Name: protected: virtual void CCreateMultiplayerGameServerPage::OnCheckButtonChecked(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCreateMultiplayerGameServerPage::OnCheckButtonChecked(CCreateMultiplayerGameServerPage *this)
{
  CCreateMultiplayerGameServerPage_vtbl *v2; // edi
  bool v3; // al
  CCreateMultiplayerGameServerPage_vtbl *v4; // edi
  bool v5; // al
  CCreateMultiplayerGameServerPage_vtbl *v6; // edi
  bool v7; // al
  CCreateMultiplayerGameServerPage_vtbl *v8; // edi
  bool v9; // al
  CCreateMultiplayerGameServerPage_vtbl *v10; // edi
  bool v11; // al
  CCreateMultiplayerGameServerPage_vtbl *v12; // edi
  bool v13; // al
  CCreateMultiplayerGameServerPage_vtbl *v14; // edi
  bool v15; // al

  v2 = this->__vftable;
  v3 = this->m_pEnableBotsCheck->IsSelected(this: this->m_pEnableBotsCheck);
  v2->SetControlEnabled(this, a2: "SkillLevel0", a3: v3);
  v4 = this->__vftable;
  v5 = this->m_pEnableBotsCheck->IsSelected(this: this->m_pEnableBotsCheck);
  v4->SetControlEnabled(this, a2: "SkillLevel1", a3: v5);
  v6 = this->__vftable;
  v7 = this->m_pEnableBotsCheck->IsSelected(this: this->m_pEnableBotsCheck);
  v6->SetControlEnabled(this, a2: "SkillLevel2", a3: v7);
  v8 = this->__vftable;
  v9 = this->m_pEnableBotsCheck->IsSelected(this: this->m_pEnableBotsCheck);
  v8->SetControlEnabled(this, a2: "SkillLevel3", a3: v9);
  v10 = this->__vftable;
  v11 = this->m_pEnableBotsCheck->IsSelected(this: this->m_pEnableBotsCheck);
  v10->SetControlEnabled(this, a2: "BotQuotaCombo", a3: v11);
  v12 = this->__vftable;
  v13 = this->m_pEnableBotsCheck->IsSelected(this: this->m_pEnableBotsCheck);
  v12->SetControlEnabled(this, a2: "BotQuotaLabel", a3: v13);
  v14 = this->__vftable;
  v15 = this->m_pEnableBotsCheck->IsSelected(this: this->m_pEnableBotsCheck);
  v14->SetControlEnabled(this, a2: "BotDifficultyLabel", a3: v15);
}

//------------------------------------------------------------------------------
// Address: 0x101D3920
// Name: public: virtual struct vgui::PanelMessageMap __near * CCreateMultiplayerGameServerPage::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CCreateMultiplayerGameServerPage::GetMessageMap(
        CCreateMultiplayerGameServerPage *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CCreateMultiplayerGameServerPage::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CCreateMultiplayerGameServerPage::GetMessageMap'::`2'::s_pMap;
  `CCreateMultiplayerGameServerPage::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CCreateMultiplayerGameServerPage");
  `CCreateMultiplayerGameServerPage::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D3950
// Name: public: virtual struct PanelAnimationMap __near * CCreateMultiplayerGameServerPage::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CCreateMultiplayerGameServerPage::GetAnimMap(CCreateMultiplayerGameServerPage *this)
{
  return FindOrAddPanelAnimationMap(className: "CCreateMultiplayerGameServerPage");
}

//------------------------------------------------------------------------------
// Address: 0x101D3960
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CCreateMultiplayerGameServerPage::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CCreateMultiplayerGameServerPage::GetKBMap(CCreateMultiplayerGameServerPage *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CCreateMultiplayerGameServerPage::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CCreateMultiplayerGameServerPage::GetKBMap'::`2'::s_pMap;
  `CCreateMultiplayerGameServerPage::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CCreateMultiplayerGameServerPage");
  `CCreateMultiplayerGameServerPage::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101D39C0
// Name: public: static void CCreateMultiplayerGameServerPage::PanelMessageFunc_OnCheckButtonChecked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CCreateMultiplayerGameServerPage::PanelMessageFunc_OnCheckButtonChecked::InitVar(int a1@<ebp>)
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
  if ( !`CCreateMultiplayerGameServerPage::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded )
  {
    `CCreateMultiplayerGameServerPage::PanelMessageFunc_OnCheckButtonChecked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall COptionsSubMultiplayer::`vcall'{964,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CCreateMultiplayerGameServerPage");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "CheckButtonChecked";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101D3A50
// Name: public: CCreateMultiplayerGameServerPage::CCreateMultiplayerGameServerPage(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CCreateMultiplayerGameServerPage *__userpurge CCreateMultiplayerGameServerPage::CCreateMultiplayerGameServerPage@<eax>(
        CCreateMultiplayerGameServerPage *this@<ecx>,
        vgui::PanelMessageMap *a2@<edi>,
        vgui::Panel *parent,
        const char *name)
{
  vgui::ComboBox *v5; // eax
  vgui::ComboBox *v6; // eax
  vgui::CheckButton *v7; // eax
  vgui::CheckButton *v8; // eax
  CModInfo *v9; // eax
  const char *GameName; // eax
  ConVarRef var; // [esp+8h] [ebp-8h] BYREF

  vgui::PropertyPage::PropertyPage(this, parent, panelName: name);
  this->__vftable = (CCreateMultiplayerGameServerPage_vtbl *)&CCreateMultiplayerGameServerPage::`vftable';
  if ( `CCreateMultiplayerGameServerPage::ChainToMap'::`2'::chained == 0 )
  {
    `CCreateMultiplayerGameServerPage::ChainToMap'::`2'::chained = 1;
    a2 = vgui::FindOrAddPanelMessageMap(className: "CCreateMultiplayerGameServerPage");
    a2->pfnClassName = CCreateMultiplayerGameServerPage::GetPanelClassName;
    a2->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::PropertyPage");
  }
  if ( `CCreateMultiplayerGameServerPage::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CCreateMultiplayerGameServerPage::ChainToAnimationMap'::`2'::chained = 1;
    a2 = (vgui::PanelMessageMap *)FindOrAddPanelAnimationMap(className: "CCreateMultiplayerGameServerPage");
    a2->baseMap = (vgui::PanelMessageMap *)CCreateMultiplayerGameServerPage::GetPanelClassName;
    *(_DWORD *)&a2->processed = FindOrAddPanelAnimationMap(className: "vgui::PropertyPage");
  }
  if ( `CCreateMultiplayerGameServerPage::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CCreateMultiplayerGameServerPage::KB_ChainToMap'::`2'::chained = 1;
    a2 = (vgui::PanelMessageMap *)vgui::FindOrAddPanelKeyBindingMap(className: "CCreateMultiplayerGameServerPage");
    a2[2].entries.m_Memory.m_nAllocationCount = (int)CCreateMultiplayerGameServerPage::GetPanelClassName;
    a2->baseMap = (vgui::PanelMessageMap *)vgui::FindOrAddPanelKeyBindingMap(className: "vgui::PropertyPage");
  }
  CCreateMultiplayerGameServerPage::PanelMessageFunc_OnCheckButtonChecked::InitVar();
  this->m_pSavedData = nullptr;
  v5 = (vgui::ComboBox *)MemAlloc_Alloc(nSize: 0x458u);
  if ( v5 != nullptr )
    v6 = vgui::ComboBox::ComboBox(this: v5, parent: this, panelName: "MapList", numLines: 12, allowEdit: false);
  else
    v6 = nullptr;
  this->m_pMapList = v6;
  v7 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v7 != nullptr )
    v8 = vgui::CheckButton::CheckButton(this: v7, parent: this, panelName: "EnableBotsCheck", text: prType);
  else
    v8 = nullptr;
  this->m_pEnableBotsCheck = v8;
  v8->SetVisible(this: v8, a2: false);
  this->m_pEnableBotsCheck->SetEnabled(this: this->m_pEnableBotsCheck, a2: false);
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "Resource/CreateMultiplayerGameServerPage.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  CCreateMultiplayerGameServerPage::LoadMapList(this, (int)a2);
  this->m_szMapName[0] = 0;
  v9 = ModInfo();
  GameName = CModInfo::GetGameName(this: v9);
  vgui::EditablePanel::SetControlString(this, controlName: "ServerNameEdit", string: GameName);
  ConVarRef::ConVarRef(this: &var, pName: "sv_password");
  if ( ConVarRef::IsValid(this: (SplitScreenConVarRef *)&var) )
    vgui::EditablePanel::SetControlString(
      this,
      controlName: "PasswordEdit",
      string: var.m_pConVarState->m_Value.m_pszString);
  return this;
}
