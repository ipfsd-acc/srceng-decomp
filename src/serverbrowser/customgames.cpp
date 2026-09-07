// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: serverbrowser/customgames.cpp
// Functions: 56
// ============================================================

#include "serverbrowser\customgames.h"

//------------------------------------------------------------------------------
// Address: 0x1000D2E0
// Name: bool IsSteamGameServerBrowsingEnabled(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl IsSteamGameServerBrowsingEnabled()
{
  BOOL result; // eax
  int v1; // [esp+0h] [ebp-4h] BYREF

  v1 = 0;
  g_pVGuiSystem->GetRegistryInteger(
    this: g_pVGuiSystem,
    a2: "HKEY_CURRENT_USER\\Software\\Valve\\Steam\\OfflineAFS",
    a3: &v1);
  result = true;
  if ( v1 != 1 )
  {
    v1 = 0;
    g_pVGuiSystem->GetRegistryInteger(
      this: g_pVGuiSystem,
      a2: "HKEY_CURRENT_USER\\Software\\Valve\\Steam\\Offline",
      a3: &v1);
    if ( v1 == 1 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000D340
// Name: public: static char const __near * TagInfoLabel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl TagInfoLabel::GetPanelClassName()
{
  return "TagInfoLabel";
}

//------------------------------------------------------------------------------
// Address: 0x1000D350
// Name: public: static char const __near * TagMenuButton::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl TagMenuButton::GetPanelClassName()
{
  return "TagMenuButton";
}

//------------------------------------------------------------------------------
// Address: 0x1000D360
// Name: public: static char const __near * CCustomGames::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CCustomGames::GetPanelClassName()
{
  return "CCustomGames";
}

//------------------------------------------------------------------------------
// Address: 0x1000D370
// Name: public: virtual void TagMenuButton::OnShowMenu(class vgui::Menu __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TagMenuButton::OnShowMenu(TagMenuButton *this, vgui::Menu *menu)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
  {
    v4 = KeyValues::KeyValues(this: v3, setName: "TagMenuButtonOpened");
    this->PostActionSignal(this, a2: v4);
  }
  else
  {
    this->PostActionSignal(this, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D3C0
// Name: public: static char const __near * CCustomServerInfoURLQuery::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CCustomServerInfoURLQuery::GetPanelClassName()
{
  return "CCustomServerInfoURLQuery";
}

//------------------------------------------------------------------------------
// Address: 0x1000D3D0
// Name: public: virtual void TagInfoLabel::DoOpenCustomServerInfoURL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TagInfoLabel::DoOpenCustomServerInfoURL(TagInfoLabel *this)
{
  char *m_pszURL; // eax

  m_pszURL = this->m_pszURL;
  if ( m_pszURL != nullptr )
    g_pVGuiSystem->ShellExecute(this: g_pVGuiSystem, a2: "open", a3: m_pszURL);
}

//------------------------------------------------------------------------------
// Address: 0x1000D3F0
// Name: protected: virtual char const __near * CInternetGames::GetStringNoUnfilteredServers(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CInternetGames::GetStringNoUnfilteredServers(CInternetGames *this)
{
  return "#ServerBrowser_NoInternetGames";
}

//------------------------------------------------------------------------------
// Address: 0x1000D400
// Name: protected: virtual char const __near * CInternetGames::GetStringNoUnfilteredServersOnMaster(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CInternetGames::GetStringNoUnfilteredServersOnMaster(CInternetGames *this)
{
  return "#ServerBrowser_MasterServerHasNoServersListed";
}

//------------------------------------------------------------------------------
// Address: 0x1000D410
// Name: protected: virtual char const __near * CInternetGames::GetStringNoServersResponded(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CInternetGames::GetStringNoServersResponded(CInternetGames *this)
{
  return "#ServerBrowser_NoInternetGamesResponded";
}

//------------------------------------------------------------------------------
// Address: 0x1000D420
// Name: public: virtual void CCustomGames::UpdateDerivedLayouts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCustomGames::UpdateDerivedLayouts(CCustomGames *this)
{
  const char *v2; // edi
  bool v3; // al
  bool (__thiscall *FileExists)(IBaseFileSystem *, const char *, const char *); // edx

  v2 = "PLATFORM";
  v3 = this->m_pFilter->IsSelected(this: this->m_pFilter);
  FileExists = g_pFullFileSystem->FileExists;
  if ( v3 )
  {
    if ( ((unsigned __int8 (__stdcall *)(const char *))FileExists)(a1: "servers/CustomGamesPage_Filters.res") != 0 )
      v2 = "MOD";
    this->LoadControlSettings(this, a2: "servers/CustomGamesPage_Filters.res", a3: v2, a4: nullptr, a5: nullptr);
  }
  else
  {
    if ( ((unsigned __int8 (__stdcall *)(const char *))FileExists)(a1: "servers/CustomGamesPage.res") != 0 )
      v2 = "MOD";
    this->LoadControlSettings(this, a2: "servers/CustomGamesPage.res", a3: v2, a4: nullptr, a5: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D4B0
// Name: public: virtual void CCustomGames::OnLoadFilter(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCustomGames::OnLoadFilter(CCustomGames *this, KeyValues *filter)
{
  const char *String; // eax

  vgui::Panel::OnMousePressed((vgui::TreeView *)this, itemIndex: (int)filter);
  String = KeyValues::GetString(this: filter, keyName: "gametype", defaultValue: defaultValue);
  V_strncpy(pDest: this->m_szTagFilter, pSrc: String, maxLen: 128);
  if ( this->m_pTagFilter != nullptr )
    this->m_pTagFilter->SetText(this: this->m_pTagFilter, a2: this->m_szTagFilter);
}

//------------------------------------------------------------------------------
// Address: 0x1000D510
// Name: public: virtual void CCustomGames::SetRefreshing(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCustomGames::SetRefreshing(CCustomGames *this, bool state)
{
  if ( state )
    this->m_pAddTagList->SetEnabled(this: this->m_pAddTagList, a2: false);
  CBaseGamesPage::SetRefreshing(this, state);
}

//------------------------------------------------------------------------------
// Address: 0x1000D540
// Name: public: virtual void CCustomGames::ServerResponded(int,class gameserveritem_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCustomGames::ServerResponded(CCustomGames *this, int iServer, gameserveritem_t *pServerItem)
{
  CBaseGamesPage::ServerResponded(this, iServer, pServerItem);
  if ( pServerItem->m_szGameTags[0] != 0 )
    this->m_pAddTagList->SetEnabled(this: this->m_pAddTagList, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x1000D580
// Name: int SortTagsInUse(struct tagentry_t const __near *,struct tagentry_t const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl SortTagsInUse(const tagentry_t *pTag1, const tagentry_t *pTag2)
{
  return pTag1->iCount < pTag2->iCount;
}

//------------------------------------------------------------------------------
// Address: 0x1000D5A0
// Name: int SortServerTags(char __near * const __near *,char __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl SortServerTags(const char **p1, const char **p2)
{
  return _V_strcmp(s1: *p1, s2: *p2) > 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000D5F0
// Name: public: virtual struct vgui::PanelMessageMap __near * CCustomGames::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CCustomGames::GetMessageMap(CCustomGames *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CCustomGames::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CCustomGames::GetMessageMap'::`2'::s_pMap;
  `CCustomGames::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CCustomGames");
  `CCustomGames::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000D620
// Name: public: virtual struct PanelAnimationMap __near * CCustomGames::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CCustomGames::GetAnimMap(CCustomGames *this)
{
  return FindOrAddPanelAnimationMap(className: "CCustomGames");
}

//------------------------------------------------------------------------------
// Address: 0x1000D630
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CCustomGames::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CCustomGames::GetKBMap(CCustomGames *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CCustomGames::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CCustomGames::GetKBMap'::`2'::s_pMap;
  `CCustomGames::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CCustomGames");
  `CCustomGames::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000D660
// Name: public: TagMenuButton::TagMenuButton(class vgui::Panel __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
TagMenuButton *__thiscall TagMenuButton::TagMenuButton(
        TagMenuButton *this,
        vgui::Panel *parent,
        const char *panelName,
        const char *text)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi

  vgui::MenuButton::MenuButton(this, parent, panelName, text);
  this->__vftable = (TagMenuButton_vtbl *)&TagMenuButton::`vftable';
  if ( `TagMenuButton::ChainToMap'::`2'::chained == 0 )
  {
    `TagMenuButton::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "TagMenuButton");
    v5->pfnClassName = TagMenuButton::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::MenuButton");
  }
  if ( `TagMenuButton::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `TagMenuButton::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "TagMenuButton");
    v6->pfnClassName = TagMenuButton::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::MenuButton");
  }
  if ( `TagMenuButton::KB_ChainToMap'::`2'::chained == 0 )
  {
    `TagMenuButton::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "TagMenuButton");
    v7->pfnClassName = TagMenuButton::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::MenuButton");
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000D750
// Name: public: virtual void vgui::Button::OnHotkey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::Button::OnHotkey(vgui::Button *this)
{
  this->DoClick(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000D760
// Name: public: virtual struct vgui::PanelMessageMap __near * TagMenuButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall TagMenuButton::GetMessageMap(TagMenuButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`TagMenuButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `TagMenuButton::GetMessageMap'::`2'::s_pMap;
  `TagMenuButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "TagMenuButton");
  `TagMenuButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000D790
// Name: public: virtual struct PanelAnimationMap __near * TagMenuButton::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall TagMenuButton::GetAnimMap(TagMenuButton *this)
{
  return FindOrAddPanelAnimationMap(className: "TagMenuButton");
}

//------------------------------------------------------------------------------
// Address: 0x1000D7A0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * TagMenuButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall TagMenuButton::GetKBMap(TagMenuButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`TagMenuButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `TagMenuButton::GetKBMap'::`2'::s_pMap;
  `TagMenuButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "TagMenuButton");
  `TagMenuButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000D800
// Name: public: CCustomServerInfoURLQuery::CCustomServerInfoURLQuery(char const __near *,char const __near *,class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CCustomServerInfoURLQuery *__thiscall CCustomServerInfoURLQuery::CCustomServerInfoURLQuery(
        CCustomServerInfoURLQuery *this,
        const char *title,
        const char *queryText,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v5; // esi
  PanelAnimationMap *v6; // esi
  vgui::PanelKeyBindingMap *v7; // esi

  vgui::QueryBox::QueryBox(this, title, queryText, parent);
  this->__vftable = (CCustomServerInfoURLQuery_vtbl *)&CCustomServerInfoURLQuery::`vftable';
  if ( `CCustomServerInfoURLQuery::ChainToMap'::`2'::chained == 0 )
  {
    `CCustomServerInfoURLQuery::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CCustomServerInfoURLQuery");
    v5->pfnClassName = CCustomServerInfoURLQuery::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::QueryBox");
  }
  if ( `CCustomServerInfoURLQuery::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CCustomServerInfoURLQuery::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CCustomServerInfoURLQuery");
    v6->pfnClassName = CCustomServerInfoURLQuery::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::QueryBox");
  }
  if ( `CCustomServerInfoURLQuery::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CCustomServerInfoURLQuery::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CCustomServerInfoURLQuery");
    v7->pfnClassName = CCustomServerInfoURLQuery::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::QueryBox");
  }
  vgui::MessageBox::SetOKButtonText(this, buttonText: "#ServerBrowser_CustomServerURLButton");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000D8D0
// Name: public: virtual struct vgui::PanelMessageMap __near * CCustomServerInfoURLQuery::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CCustomServerInfoURLQuery::GetMessageMap(CCustomServerInfoURLQuery *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CCustomServerInfoURLQuery::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CCustomServerInfoURLQuery::GetMessageMap'::`2'::s_pMap;
  `CCustomServerInfoURLQuery::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CCustomServerInfoURLQuery");
  `CCustomServerInfoURLQuery::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000D900
// Name: public: virtual struct PanelAnimationMap __near * CCustomServerInfoURLQuery::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CCustomServerInfoURLQuery::GetAnimMap(CCustomServerInfoURLQuery *this)
{
  return FindOrAddPanelAnimationMap(className: "CCustomServerInfoURLQuery");
}

//------------------------------------------------------------------------------
// Address: 0x1000D910
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CCustomServerInfoURLQuery::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CCustomServerInfoURLQuery::GetKBMap(CCustomServerInfoURLQuery *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CCustomServerInfoURLQuery::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CCustomServerInfoURLQuery::GetKBMap'::`2'::s_pMap;
  `CCustomServerInfoURLQuery::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CCustomServerInfoURLQuery");
  `CCustomServerInfoURLQuery::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000D970
// Name: public: virtual void TagInfoLabel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TagInfoLabel::OnMousePressed(TagInfoLabel *this, ButtonCode_t code)
{
  CCustomServerInfoURLQuery *v3; // eax
  CCustomServerInfoURLQuery *v4; // esi
  KeyValues *v5; // eax
  KeyValues *v6; // eax

  if ( code == KEY_COUNT && this->m_pszURL != nullptr )
  {
    v3 = (CCustomServerInfoURLQuery *)operator new(nSize: 0x248u);
    if ( v3 != nullptr )
    {
      v4 = CCustomServerInfoURLQuery::CCustomServerInfoURLQuery(
             this: v3,
             title: "#ServerBrowser_CustomServerURLWarning",
             queryText: "#ServerBrowser_CustomServerURLOpen",
             parent: this);
      if ( v4 != nullptr )
      {
        v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v5 != nullptr )
          v6 = KeyValues::KeyValues(this: v5, setName: "DoOpenCustomServerInfoURL");
        else
          v6 = nullptr;
        vgui::QueryBox::SetOKCommand(this: v4, keyValues: v6);
        v4->AddActionSignalTarget_2(this: v4, a2: this);
        v4->MoveToFront(this: v4);
        v4->DoModal_2(this: v4, a2: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DAF0
// Name: public: virtual bool CCustomGames::CheckTagFilter(class gameserveritem_t __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCustomGames::CheckTagFilter(CCustomGames *this, gameserveritem_t *server)
{
  char *m_szTagFilter; // esi
  int v4; // edi
  BOOL v5; // esi
  CSplitString TagList; // [esp+8h] [ebp-1Ch] BYREF
  bool bRetVal; // [esp+23h] [ebp-1h]
  char *servera; // [esp+2Ch] [ebp+8h]

  m_szTagFilter = this->m_szTagFilter;
  bRetVal = true;
  if ( _V_strlen(str: this->m_szTagFilter) != 0 )
  {
    CSplitString::CSplitString(this: &TagList, pString: m_szTagFilter, pSeparator: ",");
    v4 = 0;
    if ( TagList.m_Size > 0 )
    {
      servera = server->m_szGameTags;
      while ( 1 )
      {
        v5 = V_strnistr(pStr: servera, pSearch: TagList.m_Memory.m_pMemory[v4], n: 128) != nullptr;
        if ( v5 == CBaseGamesPage::TagsExclude(this) )
          break;
        if ( ++v4 >= TagList.m_Size )
        {
          CSplitString::~CSplitString(this: &TagList);
          return bRetVal;
        }
      }
      bRetVal = false;
    }
    CSplitString::~CSplitString(this: &TagList);
  }
  return bRetVal;
}

//------------------------------------------------------------------------------
// Address: 0x1000DD20
// Name: public: static void TagInfoLabel::PanelMessageFunc_DoOpenCustomServerInfoURL::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall TagInfoLabel::PanelMessageFunc_DoOpenCustomServerInfoURL::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`TagInfoLabel::PanelMessageFunc_DoOpenCustomServerInfoURL::InitVar'::`2'::bAdded )
  {
    `TagInfoLabel::PanelMessageFunc_DoOpenCustomServerInfoURL::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall TagInfoLabel::`vcall'{1000,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "TagInfoLabel");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "DoOpenCustomServerInfoURL";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DDB0
// Name: public: static void CCustomGames::PanelMessageFunc_OnAddTag::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CCustomGames::PanelMessageFunc_OnAddTag::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  int m_Size; // edx
  __int128 v3; // xmm0
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CCustomGames::PanelMessageFunc_OnAddTag::InitVar'::`2'::bAdded )
  {
    `CCustomGames::PanelMessageFunc_OnAddTag::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::Button::`vcall'{1072,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CCustomGames");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "AddTag";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_KEYVALUES;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DE40
// Name: public: static void CCustomGames::PanelMessageFunc_OnTagMenuButtonOpened::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CCustomGames::PanelMessageFunc_OnTagMenuButtonOpened::InitVar(int a1@<ebp>)
{
  vgui::PanelMessageMap *v1; // eax
  __int128 v2; // xmm0
  int m_Size; // [esp-58h] [ebp-64h]
  vgui::MessageMapItem_t v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CCustomGames::PanelMessageFunc_OnTagMenuButtonOpened::InitVar'::`2'::bAdded )
  {
    `CCustomGames::PanelMessageFunc_OnTagMenuButtonOpened::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::TreeView::`vcall'{1076,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CCustomGames");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "TagMenuButtonOpened";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DED0
// Name: public: TagInfoLabel::TagInfoLabel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
TagInfoLabel *__thiscall TagInfoLabel::TagInfoLabel(TagInfoLabel *this, vgui::Panel *parent, const char *panelName)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::URLLabel::URLLabel(this, parent, panelName, text: nullptr, pszURL: nullptr);
  this->__vftable = (TagInfoLabel_vtbl *)&TagInfoLabel::`vftable';
  if ( `TagInfoLabel::ChainToMap'::`2'::chained == 0 )
  {
    `TagInfoLabel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "TagInfoLabel");
    v4->pfnClassName = TagInfoLabel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::URLLabel");
  }
  if ( `TagInfoLabel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `TagInfoLabel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "TagInfoLabel");
    v5->pfnClassName = TagInfoLabel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::URLLabel");
  }
  if ( `TagInfoLabel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `TagInfoLabel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "TagInfoLabel");
    v6->pfnClassName = TagInfoLabel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::URLLabel");
  }
  TagInfoLabel::PanelMessageFunc_DoOpenCustomServerInfoURL::InitVar(a1: (int)&savedregs);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000DFB0
// Name: public: virtual struct vgui::PanelMessageMap __near * TagInfoLabel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall TagInfoLabel::GetMessageMap(TagInfoLabel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`TagInfoLabel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `TagInfoLabel::GetMessageMap'::`2'::s_pMap;
  `TagInfoLabel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "TagInfoLabel");
  `TagInfoLabel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000DFE0
// Name: public: virtual struct PanelAnimationMap __near * TagInfoLabel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall TagInfoLabel::GetAnimMap(TagInfoLabel *this)
{
  return FindOrAddPanelAnimationMap(className: "TagInfoLabel");
}

//------------------------------------------------------------------------------
// Address: 0x1000E000
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * TagInfoLabel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall TagInfoLabel::GetKBMap(TagInfoLabel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`TagInfoLabel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `TagInfoLabel::GetKBMap'::`2'::s_pMap;
  `TagInfoLabel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "TagInfoLabel");
  `TagInfoLabel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000E060
// Name: public: CCustomGames::CCustomGames(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CCustomGames *__thiscall CCustomGames::CCustomGames(CCustomGames *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::TextEntry *v6; // eax
  vgui::TextEntry *v7; // eax
  TagMenuButton *v8; // eax
  TagMenuButton *v9; // eax
  vgui::Menu *v10; // eax
  vgui::Menu *v11; // eax
  TagMenuButton *m_pAddTagList; // ecx
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CInternetGames::CInternetGames(this, parent, panelName: "CustomGames", eType: eInternetServer);
  this->CInternetGames::CBaseGamesPage::vgui::PropertyPage::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable = (CCustomGames_vtbl *)&CCustomGames::`vftable'{for `vgui::PropertyPage'};
  this->CInternetGames::CBaseGamesPage::IGameList::__vftable = (IGameList_vtbl *)&CCustomGames::`vftable'{for `IGameList'};
  this->CInternetGames::CBaseGamesPage::ISteamMatchmakingServerListResponse::__vftable = (ISteamMatchmakingServerListResponse_vtbl *)&CCustomGames::`vftable'{for `ISteamMatchmakingServerListResponse'};
  this->CInternetGames::CBaseGamesPage::ISteamMatchmakingPingResponse::__vftable = (ISteamMatchmakingPingResponse_vtbl *)&CCustomGames::`vftable'{for `ISteamMatchmakingPingResponse'};
  if ( `CCustomGames::ChainToMap'::`2'::chained == 0 )
  {
    `CCustomGames::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CCustomGames");
    v3->pfnClassName = CCustomGames::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "CInternetGames");
  }
  if ( `CCustomGames::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CCustomGames::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CCustomGames");
    v4->pfnClassName = CCustomGames::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "CInternetGames");
  }
  if ( `CCustomGames::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CCustomGames::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CCustomGames");
    v5->pfnClassName = CCustomGames::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CInternetGames");
  }
  CCustomGames::PanelMessageFunc_OnAddTag::InitVar(a1: (int)&savedregs);
  CCustomGames::PanelMessageFunc_OnTagMenuButtonOpened::InitVar(a1: (int)&savedregs);
  this->m_pGameList->AddColumnHeader(
    this: this->m_pGameList,
    a2: 9,
    a3: "Tags",
    a4: "#ServerBrowser_Tags",
    a5: 200,
    a6: 0);
  this->m_pGameList->SetSortFunc(this: this->m_pGameList, a2: 9, a3: TagsCompare);
  this->m_pGameList->SetSortColumn(this: this->m_pGameList, a2: 9);
  if ( !IsSteamGameServerBrowsingEnabled() )
  {
    this->m_pGameList->SetEmptyListText_2(this: this->m_pGameList, a2: "#ServerBrowser_OfflineMode");
    this->m_pConnect->SetEnabled(this: this->m_pConnect, a2: false);
    this->m_pRefreshAll->SetEnabled(this: this->m_pRefreshAll, a2: false);
    this->m_pRefreshQuick->SetEnabled(this: this->m_pRefreshQuick, a2: false);
    this->m_pAddServer->SetEnabled(this: this->m_pAddServer, a2: false);
    this->m_pFilter->SetEnabled(this: this->m_pFilter, a2: false);
  }
  this->m_szTagFilter[0] = 0;
  v6 = (vgui::TextEntry *)operator new(nSize: 0x43Cu);
  if ( v6 != nullptr )
    v7 = vgui::TextEntry::TextEntry(this: v6, parent: this, panelName: "TagFilter");
  else
    v7 = nullptr;
  this->m_pTagFilter = v7;
  v7->SetEnabled(this: v7, a2: false);
  this->m_pTagFilter->SetMaximumCharCount(this: this->m_pTagFilter, a2: 128);
  v8 = (TagMenuButton *)operator new(nSize: 0x218u);
  if ( v8 != nullptr )
    v9 = TagMenuButton::TagMenuButton(
           this: v8,
           parent: this,
           panelName: "AddTagList",
           text: "#ServerBrowser_AddCommonTags");
  else
    v9 = nullptr;
  this->m_pAddTagList = v9;
  v10 = (vgui::Menu *)operator new(nSize: 0x420u);
  if ( v10 != nullptr )
    v11 = vgui::Menu::Menu(this: v10, parent: this->m_pAddTagList, panelName: "TagList");
  else
    v11 = nullptr;
  m_pAddTagList = this->m_pAddTagList;
  this->m_pTagListMenu = v11;
  m_pAddTagList->SetMenu(this: m_pAddTagList, a2: v11);
  this->m_pAddTagList->SetOpenDirection(this: this->m_pAddTagList, a2: (vgui::Menu::MenuDirection_e)2);
  this->m_pAddTagList->SetEnabled(this: this->m_pAddTagList, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000E2F0
// Name: public: void CCustomGames::RecalculateCommonTags(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCustomGames::RecalculateCommonTags(CCustomGames *this)
{
  CCustomGames *v1; // esi
  vgui::Menu *m_pTagListMenu; // ecx
  CGameListPanel *m_pGameList; // ecx
  int (__thiscall *GetItemCount)(vgui::ListPanel *); // edx
  int m_Size; // edi
  tagentry_t *m_pMemory; // ebx
  int v7; // eax
  int v8; // eax
  const char *v9; // eax
  int *p_iCount; // esi
  int v11; // esi
  int v12; // eax
  int v13; // edi
  const char *pszTag; // esi
  KeyValues *v15; // eax
  KeyValues *v16; // ebx
  KeyValues *v17; // eax
  KeyValues *v18; // eax
  vgui::Menu_vtbl *v19; // esi
  CCustomGames *v20; // edi
  int Wide; // eax
  CSplitString TagList; // [esp+Ch] [ebp-44h] BYREF
  CUtlVector<tagentry_t,CUtlMemory<tagentry_t,int> > aTagsInUse; // [esp+24h] [ebp-2Ch] BYREF
  int iCount; // [esp+38h] [ebp-18h]
  int j; // [esp+3Ch] [ebp-14h]
  int i; // [esp+40h] [ebp-10h]
  int iTag; // [esp+44h] [ebp-Ch]
  CCustomGames *v28; // [esp+48h] [ebp-8h]
  bool bFound; // [esp+4Fh] [ebp-1h]

  v1 = this;
  m_pTagListMenu = this->m_pTagListMenu;
  v28 = v1;
  vgui::Menu::DeleteAllItems(this: m_pTagListMenu);
  m_pGameList = v1->m_pGameList;
  GetItemCount = m_pGameList->GetItemCount;
  m_Size = 0;
  m_pMemory = nullptr;
  memset(&aTagsInUse, 0, sizeof(aTagsInUse));
  iCount = GetItemCount(this: m_pGameList);
  for ( i = 0; i < iCount; ++i )
  {
    v7 = v1->m_pGameList->GetItemUserData(this: v1->m_pGameList, a2: i);
    v8 = (int)v1->GetServer(this: &v1->IGameList, a2: v7);
    if ( v8 != 0 )
    {
      v9 = (const char *)(v8 + 236);
      if ( v9 != nullptr && *v9 != 0 )
      {
        CSplitString::CSplitString(this: &TagList, pString: v9, pSeparator: ",");
        iTag = 0;
        if ( TagList.m_Size > 0 )
        {
          do
          {
            bFound = false;
            if ( m_Size <= 0 )
              goto LABEL_12;
            p_iCount = &m_pMemory->iCount;
            for ( j = m_Size; j != 0; --j )
            {
              if ( V_strnicmp(s1: TagList.m_Memory.m_pMemory[iTag], s2: (const char *)*(p_iCount - 1), n: 128) == 0 )
              {
                ++*p_iCount;
                bFound = true;
              }
              p_iCount += 2;
            }
            if ( !bFound )
            {
LABEL_12:
              v11 = m_Size;
              if ( m_Size + 1 > aTagsInUse.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<vgui::AnimationController::RanEvent_t,int>::Grow(
                  this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&aTagsInUse,
                  num: m_Size - aTagsInUse.m_Memory.m_nAllocationCount + 1);
                m_Size = aTagsInUse.m_Size;
                m_pMemory = aTagsInUse.m_Memory.m_pMemory;
              }
              aTagsInUse.m_Size = ++m_Size;
              aTagsInUse.m_pElements = m_pMemory;
              if ( m_Size - v11 - 1 > 0 )
                _V_memmove(dest: &m_pMemory[v11 + 1], src: &m_pMemory[v11], count: 8 * (m_Size - v11 - 1));
              m_pMemory[v11].pszTag = TagList.m_Memory.m_pMemory[iTag];
              m_pMemory[v11].iCount = 0;
            }
            ++iTag;
          }
          while ( iTag < TagList.m_Size );
          v1 = v28;
        }
        CSplitString::~CSplitString(this: &TagList);
      }
    }
  }
  CUtlVector<tagentry_t,CUtlMemory<tagentry_t,int>>::Sort(
    this: &aTagsInUse,
    pfnCompare: (int (__cdecl *)(const void *, const void *))SortTagsInUse);
  if ( m_Size >= 20 )
  {
    v12 = 20;
    j = 20;
  }
  else
  {
    v12 = m_Size;
    j = m_Size;
  }
  v13 = 0;
  if ( v12 > 0 )
  {
    do
    {
      pszTag = m_pMemory[v13].pszTag;
      v15 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v15 != nullptr )
        v16 = KeyValues::KeyValues(this: v15, setName: "data", firstKey: "tag", firstValue: pszTag);
      else
        v16 = nullptr;
      v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v17 != nullptr )
        v18 = KeyValues::KeyValues(this: v17, setName: "AddTag", firstKey: "tag", firstValue: pszTag);
      else
        v18 = nullptr;
      v28->m_pTagListMenu->AddMenuItem(this: v28->m_pTagListMenu, a2: pszTag, a3: v18, a4: v28, a5: v16);
      m_pMemory = aTagsInUse.m_Memory.m_pMemory;
      ++v13;
    }
    while ( v13 < j );
    v1 = v28;
  }
  v19 = v1->m_pTagListMenu->__vftable;
  v20 = v28;
  Wide = vgui::Panel::GetWide(this: v28->m_pAddTagList);
  v19->SetFixedWidth(this: v20->m_pTagListMenu, a2: Wide);
  v20->m_pTagListMenu->InvalidateLayout(this: v20->m_pTagListMenu, a2: true, a3: false);
  v20->m_pTagListMenu->PositionRelativeToPanel(
    this: v20->m_pTagListMenu,
    a2: v20->m_pAddTagList,
    a3: (vgui::Menu::MenuDirection_e)2,
    a4: 0,
    a5: false);
  if ( aTagsInUse.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1000E580
// Name: public: virtual void CCustomGames::OnTagMenuButtonOpened(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CCustomGames::OnTagMenuButtonOpened(CCustomGames *this)
{
  CCustomGames::RecalculateCommonTags(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000E590
// Name: public: void CCustomGames::AddTagToFilterList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCustomGames::AddTagToFilterList(CCustomGames *this, const char *pszTag)
{
  int v2; // esi
  char *v3; // esi
  int m_Size; // eax
  char **m_pMemory; // ecx
  int v6; // esi
  CBaseGamesPage *v7; // edi
  int i; // esi
  char **v9; // eax
  CBaseGamesPage_vtbl *v10; // edx
  char **v11; // eax
  char txt[128]; // [esp+Ch] [ebp-118h] BYREF
  char tmptags[128]; // [esp+8Ch] [ebp-98h] BYREF
  CBaseGamesPage *v14; // [esp+10Ch] [ebp-18h]
  CUtlVector<char *,CUtlMemory<char *,int> > TagList; // [esp+110h] [ebp-14h] BYREF

  v14 = this;
  this->m_pTagFilter->GetText_2(this: this->m_pTagFilter, a2: txt, a3: 128);
  memset(&TagList, 0, sizeof(TagList));
  V_SplitString(pString: txt, pSeparator: ",", outStrings: &TagList);
  if ( txt[0] != 0 && (v2 = 0, TagList.m_Size > 0) )
  {
    while ( _V_stricmp(s1: TagList.m_Memory.m_pMemory[v2], s2: pszTag) != 0 )
    {
      if ( ++v2 >= TagList.m_Size )
        goto LABEL_5;
    }
    CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &TagList);
    CUtlVector<blacklisted_server_t,CUtlMemory<blacklisted_server_t,int>>::~CUtlVector<blacklisted_server_t,CUtlMemory<blacklisted_server_t,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&TagList);
  }
  else
  {
LABEL_5:
    v3 = (char *)operator new(nSize: 0x40u);
    V_strncpy(pDest: v3, pSrc: pszTag, maxLen: 64);
    m_Size = TagList.m_Size;
    if ( TagList.m_Size + 1 > TagList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<unsigned long,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&TagList,
        num: TagList.m_Size - TagList.m_Memory.m_nAllocationCount + 1);
      m_Size = TagList.m_Size;
    }
    m_pMemory = TagList.m_Memory.m_pMemory;
    TagList.m_Size = m_Size + 1;
    TagList.m_pElements = TagList.m_Memory.m_pMemory;
    if ( m_Size > 0 )
    {
      _V_memmove(dest: TagList.m_Memory.m_pMemory + 1, src: TagList.m_Memory.m_pMemory, count: 4 * m_Size);
      m_pMemory = TagList.m_Memory.m_pMemory;
    }
    if ( m_pMemory != nullptr )
      *m_pMemory = v3;
    CUtlVector<char *,CUtlMemory<char *,int>>::Sort(
      this: &TagList,
      pfnCompare: (int (__cdecl *)(const void *, const void *))SortServerTags);
    v6 = 0;
    for ( tmptags[0] = 0; v6 < TagList.m_Size; ++v6 )
    {
      if ( v6 > 0 )
        V_strncat(pDest: tmptags, pSrc: ",", destBufferSize: 0x80u, max_chars_to_copy: -1);
      V_strncat(pDest: tmptags, pSrc: TagList.m_Memory.m_pMemory[v6], destBufferSize: 0x80u, max_chars_to_copy: -1);
    }
    v7 = v14;
    (*(void (__thiscall **)(int, char *))(*(_DWORD *)v14[1].m_lLastDoublePressTime + 844))(
      a1: v14[1].m_lLastDoublePressTime,
      a2: tmptags);
    for ( i = 0; i < TagList.m_Size; ++i )
      free(pMem: TagList.m_Memory.m_pMemory[i]);
    v9 = TagList.m_Memory.m_pMemory;
    TagList.m_Size = 0;
    if ( TagList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( TagList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: TagList.m_Memory.m_pMemory);
        v9 = nullptr;
        TagList.m_Memory.m_pMemory = nullptr;
      }
      TagList.m_Memory.m_nAllocationCount = 0;
    }
    v10 = v7->vgui::PropertyPage::vgui::EditablePanel::vgui::Panel::vgui::IClientPanel::__vftable;
    TagList.m_pElements = v9;
    v10->UpdateFilterSettings(this: v7);
    CBaseGamesPage::ApplyGameFilters(this: v7, a2: (serverdisplay_t *)v7);
    v11 = TagList.m_Memory.m_pMemory;
    TagList.m_Size = 0;
    if ( TagList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( TagList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: TagList.m_Memory.m_pMemory);
        v11 = nullptr;
        TagList.m_Memory.m_pMemory = nullptr;
      }
      TagList.m_Memory.m_nAllocationCount = 0;
    }
    TagList.m_pElements = v11;
    if ( TagList.m_Memory.m_nGrowSize >= 0 && v11 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E7B0
// Name: Create_TagInfoLabel
// Source: json
//------------------------------------------------------------------------------
TagInfoLabel *__cdecl Create_TagInfoLabel()
{
  TagInfoLabel *v0; // eax

  v0 = (TagInfoLabel *)operator new(nSize: 0x1B8u);
  if ( v0 != nullptr )
    return TagInfoLabel::TagInfoLabel(this: v0, parent: nullptr, panelName: nullptr);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000E7D0
// Name: public: virtual void CCustomGames::OnSaveFilter(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCustomGames::OnSaveFilter(CCustomGames *this, KeyValues *filter)
{
  bool v3; // zf
  unsigned __int8 *m_szTagFilter; // ebx
  int v5; // edi
  int v6; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  MatchMakingKeyValuePair_t *m_pMemory; // ecx
  int v10; // eax
  MatchMakingKeyValuePair_t *v11; // edi
  unsigned __int8 dest[512]; // [esp+Ch] [ebp-204h] BYREF
  char *v13; // [esp+20Ch] [ebp-4h]

  vgui::Panel::OnMousePressed((vgui::TreeView *)this, itemIndex: (int)filter);
  if ( this->m_pTagFilter != nullptr )
    this->m_pTagFilter->GetText_2(this: this->m_pTagFilter, a2: this->m_szTagFilter, a3: 127);
  v3 = this->m_szTagFilter[0] == 0;
  m_szTagFilter = (unsigned __int8 *)this->m_szTagFilter;
  v13 = this->m_szTagFilter;
  if ( !v3 )
    _V_strlower(start: this->m_szTagFilter);
  v5 = 0;
  if ( this->m_vecServerFilters.m_Size > 0 )
  {
    v6 = 0;
    while ( V_strnicmp(s1: this->m_vecServerFilters.m_Memory.m_pMemory[v6].m_szKey, s2: "gametype", n: 8) != 0 )
    {
      ++v5;
      ++v6;
      if ( v5 >= this->m_vecServerFilters.m_Size )
        goto LABEL_13;
    }
    if ( this->m_vecServerFilters.m_Size - v5 - 1 > 0 )
      _V_memmove(
        dest: &this->m_vecServerFilters.m_Memory.m_pMemory[v5],
        src: &this->m_vecServerFilters.m_Memory.m_pMemory[v5 + 1],
        count: (this->m_vecServerFilters.m_Size - v5 - 1) << 9);
    --this->m_vecServerFilters.m_Size;
LABEL_13:
    m_szTagFilter = (unsigned __int8 *)v13;
  }
  if ( CBaseGamesPage::TagsExclude(this) )
  {
    strncpy(dest, source: "gametype", count: 0x100u);
    strncpy(dest: &dest[256], source: (unsigned __int8 *)defaultValue, count: 0x100u);
  }
  else
  {
    strncpy(dest, source: "gametype", count: 0x100u);
    strncpy(dest: &dest[256], source: m_szTagFilter, count: 0x100u);
  }
  m_Size = this->m_vecServerFilters.m_Size;
  m_nAllocationCount = this->m_vecServerFilters.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<MatchMakingKeyValuePair_t,int>::Grow(
      this: &this->m_vecServerFilters.m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_vecServerFilters.m_Size;
  m_pMemory = this->m_vecServerFilters.m_Memory.m_pMemory;
  v10 = this->m_vecServerFilters.m_Size - m_Size - 1;
  this->m_vecServerFilters.m_pElements = m_pMemory;
  if ( v10 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: v10 << 9);
  v11 = &this->m_vecServerFilters.m_Memory.m_pMemory[m_Size];
  if ( v11 != nullptr )
    qmemcpy(v11, dest, sizeof(MatchMakingKeyValuePair_t));
  KeyValues::SetString(this: filter, keyName: "gametype", value: (const char *)m_szTagFilter);
}

//------------------------------------------------------------------------------
// Address: 0x1000E970
// Name: public: virtual void CCustomGames::OnAddTag(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCustomGames::OnAddTag(CCustomGames *this, KeyValues *params)
{
  KeyValues *Key; // eax
  const char *String; // eax

  Key = KeyValues::FindKey(this: params, keyName: "tag", bCreate: false);
  if ( Key != nullptr )
  {
    String = KeyValues::GetString(this: Key, keyName: nullptr, defaultValue: defaultValue);
    CCustomGames::AddTagToFilterList(this, pszTag: String);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100205E0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Button::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Button::GetMessageMap(vgui::Button *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Button::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Button::GetMessageMap'::`2'::s_pMap;
  `vgui::Button::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Button");
  `vgui::Button::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10020620
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Button::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Button::GetKBMap(vgui::Button *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Button::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Button::GetKBMap'::`2'::s_pMap;
  `vgui::Button::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Button");
  `vgui::Button::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10049470
// Name: public: virtual class vgui::Panel __near * vgui::Label::HasHotkey(wchar_t)
// Source: json
//------------------------------------------------------------------------------
vgui::Label *__thiscall vgui::Label::HasHotkey(vgui::Label *this, wchar_t key)
{
  wchar_t v2; // si

  v2 = key;
  if ( iswalnum(c: key) != 0 )
    v2 = towlower(c: key);
  return this->_hotkey != v2 ? nullptr : this;
}

//------------------------------------------------------------------------------
// Address: 0x1004AA90
// Name: public: virtual class vgui::IImage __near * vgui::Label::GetImageAtIndex(int)
// Source: json
//------------------------------------------------------------------------------
vgui::IImage *__thiscall vgui::Label::GetImageAtIndex(vgui::Label *this, int index)
{
  if ( index < 0 || index >= this->_imageDar.m_Size )
    return nullptr;
  else
    return this->_imageDar.m_Memory.m_pMemory[index].image;
}

//------------------------------------------------------------------------------
// Address: 0x1004AFB0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::Label::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::Label::GetMessageMap(vgui::Label *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::Label::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Label::GetMessageMap'::`2'::s_pMap;
  `vgui::Label::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "Label");
  `vgui::Label::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004AFE0
// Name: public: virtual struct PanelAnimationMap __near * vgui::Label::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::Label::GetAnimMap(vgui::Label *this)
{
  return FindOrAddPanelAnimationMap(className: "Label");
}

//------------------------------------------------------------------------------
// Address: 0x1004B000
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::Label::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::Label::GetKBMap(vgui::Label *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::Label::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::Label::GetKBMap'::`2'::s_pMap;
  `vgui::Label::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "Label");
  `vgui::Label::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004CB10
// Name: protected: virtual class vgui::IBorder __near * vgui::Button::GetBorder(bool,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
vgui::IBorder *__thiscall vgui::Button::GetBorder(
        vgui::Button *this,
        bool depressed,
        bool armed,
        bool selected,
        bool keyfocus)
{
  if ( (this->_buttonFlags.m_nFlags & 8) != 0 )
  {
    if ( depressed )
      return this->_depressedBorder;
    if ( keyfocus || this->IsEnabled(this) && (this->_buttonFlags.m_nFlags & 0x40) != 0 )
      return this->_keyFocusBorder;
  }
  else if ( depressed )
  {
    return this->_depressedBorder;
  }
  return this->_defaultBorder;
}

//------------------------------------------------------------------------------
// Address: 0x100567E0
// Name: public: class vgui::Menu __near * vgui::MenuButton::GetMenu(void)
// Source: json
//------------------------------------------------------------------------------
vgui::Menu *__thiscall vgui::MenuButton::GetMenu(vgui::MenuItem *this)
{
  return this->m_pCascadeMenu;
}

//------------------------------------------------------------------------------
// Address: 0x100567F0
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::MenuButton::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::MenuButton::GetMessageMap(vgui::MenuButton *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::MenuButton::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuButton::GetMessageMap'::`2'::s_pMap;
  `vgui::MenuButton::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "MenuButton");
  `vgui::MenuButton::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10056820
// Name: public: virtual struct PanelAnimationMap __near * vgui::MenuButton::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::MenuButton::GetAnimMap(vgui::MenuButton *this)
{
  return FindOrAddPanelAnimationMap(className: "MenuButton");
}

//------------------------------------------------------------------------------
// Address: 0x10056830
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::MenuButton::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::MenuButton::GetKBMap(vgui::MenuButton *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::MenuButton::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::MenuButton::GetKBMap'::`2'::s_pMap;
  `vgui::MenuButton::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "MenuButton");
  `vgui::MenuButton::GetKBMap'::`2'::s_pMap = result;
  return result;
}
