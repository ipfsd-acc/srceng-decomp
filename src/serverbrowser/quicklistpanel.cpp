// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: serverbrowser/quicklistpanel.cpp
// Functions: 24
// ============================================================

#include "serverbrowser\quicklistpanel.h"

//------------------------------------------------------------------------------
// Address: 0x10013F40
// Name: public: static char const __near * CQuickListPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CQuickListPanel::GetPanelClassName()
{
  return "CQuickListPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10013F50
// Name: public: static char const __near * CMouseMessageForwardingPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CMouseMessageForwardingPanel::GetPanelClassName()
{
  return "CMouseMessageForwardingPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10013F60
// Name: public: virtual void CMouseMessageForwardingPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMouseMessageForwardingPanel::PerformLayout(CMouseMessageForwardingPanel *this)
{
  vgui::Panel *v2; // eax
  int w; // [esp+4h] [ebp-8h] BYREF
  int t; // [esp+8h] [ebp-4h] BYREF

  v2 = this->GetParent(this);
  vgui::Panel::GetSize(this: v2, wide: &w, tall: &t);
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: w, tall: t);
}

//------------------------------------------------------------------------------
// Address: 0x10013FA0
// Name: public: virtual void CMouseMessageForwardingPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMouseMessageForwardingPanel::OnMousePressed(CMouseMessageForwardingPanel *this, ButtonCode_t code)
{
  vgui::Panel *v3; // eax

  if ( this->GetParent(this) != nullptr )
  {
    v3 = this->GetParent(this);
    v3->OnMousePressed(this: v3, a2: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013FE0
// Name: public: virtual void CMouseMessageForwardingPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMouseMessageForwardingPanel::OnMouseDoublePressed(
        CMouseMessageForwardingPanel *this,
        ButtonCode_t code)
{
  vgui::Panel *v3; // eax

  if ( this->GetParent(this) != nullptr )
  {
    v3 = this->GetParent(this);
    v3->OnMouseDoublePressed(this: v3, a2: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014020
// Name: public: virtual void CMouseMessageForwardingPanel::OnMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMouseMessageForwardingPanel::OnMouseWheeled(CMouseMessageForwardingPanel *this, int delta)
{
  vgui::Panel *v3; // eax

  if ( this->GetParent(this) != nullptr )
  {
    v3 = this->GetParent(this);
    v3->OnMouseWheeled(this: v3, a2: delta);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014060
// Name: public: void CQuickListPanel::SetRefreshing(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQuickListPanel::SetRefreshing(CQuickListPanel *this)
{
  vgui::Label_vtbl *v2; // edi
  int v3; // eax

  if ( this->m_pServerNameLabel != nullptr )
  {
    v2 = this->m_pServerNameLabel->__vftable;
    v3 = ((int (__thiscall *)(vgui::ILocalize *, const char *, _DWORD))g_pVGuiLocalize->Find)(
           a1: g_pVGuiLocalize,
           a2: "#ServerBrowser_QuickListRefreshing",
           a3: 0);
    ((void (__thiscall *)(vgui::Label *, int))v2->SetText)(a1: this->m_pServerNameLabel, a2: v3);
  }
  if ( this->m_pPlayerCountLabel != nullptr )
    this->m_pPlayerCountLabel->SetVisible(this: this->m_pPlayerCountLabel, a2: false);
  if ( this->m_pLatencyImage != nullptr )
    this->m_pLatencyImage->SetVisible(this: this->m_pLatencyImage, a2: false);
  if ( this->m_pLatencyLabel != nullptr )
    this->m_pLatencyLabel->SetVisible(this: this->m_pLatencyLabel, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x100140F0
// Name: public: void CQuickListPanel::SetMapName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQuickListPanel::SetMapName(CQuickListPanel *this, const char *pMapName)
{
  V_strncpy(pDest: this->m_szMapName, pSrc: pMapName, maxLen: 64);
  if ( this->m_pMapNameLabel != nullptr )
  {
    this->m_pMapNameLabel->SetText_2(this: this->m_pMapNameLabel, a2: pMapName);
    this->m_pMapNameLabel->SizeToContents(this: this->m_pMapNameLabel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014140
// Name: public: void CQuickListPanel::SetGameType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQuickListPanel::SetGameType(CQuickListPanel *this, const char *pGameType)
{
  char gametype[512]; // [esp+8h] [ebp-200h] BYREF

  if ( strlen(pGameType) != 0 )
  {
    V_snprintf(pDest: gametype, maxLen: 512, pFormat: "(%s)", pGameType);
    this->m_pGameTypeLabel->SetText_2(this: this->m_pGameTypeLabel, a2: gametype);
  }
  else
  {
    this->m_pGameTypeLabel->SetVisible(this: this->m_pGameTypeLabel, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100141C0
// Name: public: void CQuickListPanel::SetServerInfo(class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CQuickListPanel::SetServerInfo(CQuickListPanel *this@<ecx>, int a2@<ebx>, KeyValues *pKV, int iListID)
{
  vgui::Label *m_pServerNameLabel; // ecx
  vgui::Label_vtbl *v6; // ebx
  const char *String; // eax
  int Int; // edi
  wchar_t *v9; // edi
  vgui::ILocalize_vtbl *v10; // ebx
  const char *v11; // eax
  wchar_t players[512]; // [esp+8h] [ebp-620h] BYREF
  char ping[512]; // [esp+408h] [ebp-220h] BYREF
  wchar_t playercount[16]; // [esp+608h] [ebp-20h] BYREF

  if ( pKV != nullptr )
  {
    m_pServerNameLabel = this->m_pServerNameLabel;
    this->m_iListID = iListID;
    v6 = m_pServerNameLabel->__vftable;
    String = KeyValues::GetString(this: pKV, keyName: "name", defaultValue: " ");
    ((void (__thiscall *)(vgui::Label *, const char *, int))v6->SetText_2)(
      a1: this->m_pServerNameLabel,
      a2: String,
      a3: a2);
    Int = KeyValues::GetInt(this: pKV, keyName: "ping", defaultValue: 0);
    ((void (__thiscall *)(vgui::ImagePanel *))this->m_pLatencyImage->SetImage)(a1: this->m_pLatencyImage);
    this->m_pLatencyImage->SetVisible(this: this->m_pLatencyImage, a2: false);
    V_snprintf(pDest: ping, maxLen: 512, pFormat: "%d ms", Int);
    this->m_pLatencyLabel->SetText_2(this: this->m_pLatencyLabel, a2: ping);
    this->m_pLatencyLabel->SetVisible(this: this->m_pLatencyLabel, a2: true);
    v9 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: "#ServerBrowser_Players");
    v10 = g_pVGuiLocalize->__vftable;
    v11 = KeyValues::GetString(this: pKV, keyName: "players", defaultValue: " ");
    v10->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: v11, a3: playercount, a4: 32);
    _snwprintf(string: players, count: 0x200u, format: L"%ls %ls", playercount, v9);
    this->m_pPlayerCountLabel->SetText(this: this->m_pPlayerCountLabel, a2: players, a3: false);
    this->m_pPlayerCountLabel->SetVisible(this: this->m_pPlayerCountLabel, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014330
// Name: public: void CQuickListPanel::SetImage(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQuickListPanel::SetImage(CQuickListPanel *this, const char *pMapName)
{
  const char *v2; // esi
  char imagename[512]; // [esp+8h] [ebp-600h] BYREF
  char map[512]; // [esp+208h] [ebp-400h] BYREF
  char path[512]; // [esp+408h] [ebp-200h] BYREF

  v2 = pMapName;
  V_snprintf(pDest: path, maxLen: 512, pFormat: "materials/vgui/maps/menu_thumb_%s.vmt", pMapName);
  V_snprintf(pDest: map, maxLen: 512, pFormat: "maps/%s.bsp", pMapName);
  if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: map, a3: "MOD") )
  {
    if ( !g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: path, a3: "MOD") )
      v2 = "default";
  }
  else
  {
    v2 = "default_download";
  }
  if ( this->m_pMapImage != nullptr )
  {
    V_snprintf(pDest: imagename, maxLen: 512, pFormat: "..\\vgui\\maps\\menu_thumb_%s", v2);
    this->m_pMapImage->SetImage(this: this->m_pMapImage, a2: imagename);
    this->m_pMapImage->SetMouseInputEnabled(this: this->m_pMapImage, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014420
// Name: public: virtual void CQuickListPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQuickListPanel::OnMousePressed(CQuickListPanel *this, ButtonCode_t code)
{
  vgui::Panel *m_pListPanelParent; // eax
  vgui::PanelListPanel *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax

  m_pListPanelParent = this->m_pListPanelParent;
  if ( m_pListPanelParent != nullptr )
  {
    v4 = (vgui::PanelListPanel *)__RTDynamicCast(
                                   inptr: m_pListPanelParent,
                                   VfDelta: 0,
                                   SrcType: &vgui::Panel `RTTI Type Descriptor',
                                   TargetType: &vgui::PanelListPanel `RTTI Type Descriptor',
                                   isReference: 0);
    if ( v4 != nullptr )
    {
      vgui::PanelListPanel::SetSelectedPanel(this: v4, panel: this);
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(this: v5, setName: "ItemSelected", firstKey: "itemID", firstValue: -1);
      else
        v6 = nullptr;
      vgui::Panel::CallParentFunction(this: this->m_pListPanelParent, message: v6);
    }
    if ( code == MOUSE_RIGHT )
    {
      v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v7 != nullptr )
      {
        v8 = KeyValues::KeyValues(this: v7, setName: "OpenContextMenu", firstKey: "itemID", firstValue: -1);
        vgui::Panel::CallParentFunction(this: this->m_pListPanelParent, message: v8);
      }
      else
      {
        vgui::Panel::CallParentFunction(this: this->m_pListPanelParent, message: nullptr);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100144E0
// Name: public: virtual void CQuickListPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQuickListPanel::OnMouseDoublePressed(CQuickListPanel *this, ButtonCode_t code)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax

  if ( code != MOUSE_RIGHT )
  {
    this->OnMousePressed(this, a2: code);
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
    {
      v4 = KeyValues::KeyValues(this: v3, setName: "ConnectToServer", firstKey: "code", firstValue: code);
      vgui::Panel::CallParentFunction(this: this->m_pListPanelParent, message: v4);
    }
    else
    {
      vgui::Panel::CallParentFunction(this: this->m_pListPanelParent, message: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014550
// Name: public: CMouseMessageForwardingPanel::CMouseMessageForwardingPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CMouseMessageForwardingPanel *__thiscall CMouseMessageForwardingPanel::CMouseMessageForwardingPanel(
        CMouseMessageForwardingPanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (CMouseMessageForwardingPanel_vtbl *)&CMouseMessageForwardingPanel::`vftable';
  if ( `CMouseMessageForwardingPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CMouseMessageForwardingPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CMouseMessageForwardingPanel");
    v4->pfnClassName = CMouseMessageForwardingPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CMouseMessageForwardingPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CMouseMessageForwardingPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CMouseMessageForwardingPanel");
    v5->pfnClassName = CMouseMessageForwardingPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CMouseMessageForwardingPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CMouseMessageForwardingPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CMouseMessageForwardingPanel");
    v6->pfnClassName = CMouseMessageForwardingPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  vgui::Panel::SetPaintEnabled(this, state: false);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: false);
  vgui::Panel::SetPaintBorderEnabled(this, state: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10014630
// Name: public: virtual struct vgui::PanelMessageMap __near * CMouseMessageForwardingPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CMouseMessageForwardingPanel::GetMessageMap(CMouseMessageForwardingPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CMouseMessageForwardingPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CMouseMessageForwardingPanel::GetMessageMap'::`2'::s_pMap;
  `CMouseMessageForwardingPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CMouseMessageForwardingPanel");
  `CMouseMessageForwardingPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014660
// Name: public: virtual struct PanelAnimationMap __near * CMouseMessageForwardingPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CMouseMessageForwardingPanel::GetAnimMap(CMouseMessageForwardingPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CMouseMessageForwardingPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10014670
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CMouseMessageForwardingPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CMouseMessageForwardingPanel::GetKBMap(CMouseMessageForwardingPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CMouseMessageForwardingPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CMouseMessageForwardingPanel::GetKBMap'::`2'::s_pMap;
  `CMouseMessageForwardingPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CMouseMessageForwardingPanel");
  `CMouseMessageForwardingPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100146A0
// Name: public: virtual void CQuickListPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQuickListPanel::ApplySchemeSettings(CQuickListPanel *this, int pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::Panel *m_pBGroundPanel; // eax
  Color *(__thiscall *GetColor)(vgui::IScheme *, Color *, const char *, Color); // edx
  vgui::Panel_vtbl *v6; // ebx
  _DWORD *v7; // eax

  v2 = (vgui::IScheme *)pScheme;
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  if ( v2 != nullptr && this->m_pBGroundPanel != nullptr )
  {
    m_pBGroundPanel = this->m_pBGroundPanel;
    GetColor = v2->GetColor;
    pScheme = 0xFFFFFF;
    v6 = m_pBGroundPanel->__vftable;
    v7 = (_DWORD *)((int (__thiscall *)(vgui::IScheme *, int *, const char *, int))GetColor)(
                     a1: v2,
                     a2: &pScheme,
                     a3: "QuickListBGDeselected",
                     a4: 0xFFFFFF);
    ((void (__thiscall *)(vgui::Panel *, _DWORD))v6->SetBgColor)(a1: this->m_pBGroundPanel, a2: *v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10014700
// Name: public: static void CQuickListPanel::PanelMessageFunc_OnPanelSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CQuickListPanel::PanelMessageFunc_OnPanelSelected::InitVar(int a1@<ebp>)
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
  if ( !`CQuickListPanel::PanelMessageFunc_OnPanelSelected::InitVar'::`2'::bAdded )
  {
    `CQuickListPanel::PanelMessageFunc_OnPanelSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::PropertyPage::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CQuickListPanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.secondParamType, 0, 20);
    v4.name = "PanelSelected";
    v4.func = v3;
    v4.numParams = 1;
    v4.firstParamType = DATATYPE_INT;
    v4.firstParamName = "state";
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100147A0
// Name: public: CQuickListPanel::CQuickListPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CQuickListPanel *__thiscall CQuickListPanel::CQuickListPanel(
        CQuickListPanel *this,
        vgui::Panel *pParent,
        const char *pElementName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CMouseMessageForwardingPanel *v7; // eax
  CMouseMessageForwardingPanel *v8; // eax
  vgui::ImagePanel *v9; // eax
  vgui::ImagePanel *v10; // eax
  vgui::Label *v11; // eax
  vgui::Label *v12; // eax
  vgui::Label *v13; // eax
  vgui::Label *v14; // eax
  vgui::Panel *v15; // eax
  vgui::Panel *v16; // eax
  vgui::ImagePanel *v17; // eax
  vgui::ImagePanel *v18; // eax
  vgui::Label *v19; // eax
  vgui::Label *v20; // eax
  vgui::Label *v21; // eax
  vgui::Label *v22; // eax
  vgui::Label *v23; // eax
  vgui::Label *v24; // eax
  const char *v25; // edi
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent: pParent, panelName: pElementName);
  this->__vftable = (CQuickListPanel_vtbl *)&CQuickListPanel::`vftable';
  if ( `CQuickListPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CQuickListPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CQuickListPanel");
    v4->pfnClassName = CQuickListPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CQuickListPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CQuickListPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CQuickListPanel");
    v5->pfnClassName = CQuickListPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CQuickListPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CQuickListPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CQuickListPanel");
    v6->pfnClassName = CQuickListPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CQuickListPanel::PanelMessageFunc_OnPanelSelected::InitVar(a1: (int)&savedregs);
  vgui::Panel::SetParent(this, newParent: pParent);
  this->m_pListPanelParent = pParent;
  v7 = (CMouseMessageForwardingPanel *)operator new(nSize: 0x150u);
  if ( v7 != nullptr )
    v8 = CMouseMessageForwardingPanel::CMouseMessageForwardingPanel(this: v7, parent: this, name: nullptr);
  else
    v8 = nullptr;
  vgui::Panel::SetZPos(this: v8, z: 3);
  v9 = (vgui::ImagePanel *)operator new(nSize: 0x17Cu);
  if ( v9 != nullptr )
    v10 = vgui::ImagePanel::ImagePanel(this: v9, parent: this, name: "latencyimage");
  else
    v10 = nullptr;
  this->m_pLatencyImage = v10;
  v11 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v11 != nullptr )
    v12 = vgui::Label::Label(this: v11, parent: this, panelName: "playercount", text: defaultValue);
  else
    v12 = nullptr;
  this->m_pPlayerCountLabel = v12;
  v13 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v13 != nullptr )
    v14 = vgui::Label::Label(this: v13, parent: this, panelName: "servername", text: defaultValue);
  else
    v14 = nullptr;
  this->m_pServerNameLabel = v14;
  v15 = (vgui::Panel *)operator new(nSize: 0x14Cu);
  if ( v15 != nullptr )
    v16 = vgui::Panel::Panel(this: v15, parent: this, panelName: "background");
  else
    v16 = nullptr;
  this->m_pBGroundPanel = v16;
  v17 = (vgui::ImagePanel *)operator new(nSize: 0x17Cu);
  if ( v17 != nullptr )
    v18 = vgui::ImagePanel::ImagePanel(this: v17, parent: this, name: "mapimage");
  else
    v18 = nullptr;
  this->m_pMapImage = v18;
  v19 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v19 != nullptr )
    v20 = vgui::Label::Label(this: v19, parent: this, panelName: "gametype", text: defaultValue);
  else
    v20 = nullptr;
  this->m_pGameTypeLabel = v20;
  v21 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v21 != nullptr )
    v22 = vgui::Label::Label(this: v21, parent: this, panelName: "mapname", text: defaultValue);
  else
    v22 = nullptr;
  this->m_pMapNameLabel = v22;
  v23 = (vgui::Label *)operator new(nSize: 0x1A4u);
  if ( v23 != nullptr )
    v24 = vgui::Label::Label(this: v23, parent: this, panelName: "latencytext", text: defaultValue);
  else
    v24 = nullptr;
  this->m_pLatencyLabel = v24;
  v25 = "PLATFORM";
  if ( g_pFullFileSystem->FileExists(
         this: &g_pFullFileSystem->IBaseFileSystem,
         a2: "servers/QuickListPanel.res",
         a3: "MOD") )
  {
    v25 = "MOD";
  }
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "servers/QuickListPanel.res",
    pathID: v25,
    pKeyValues: nullptr,
    pConditions: nullptr);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10014A30
// Name: public: virtual struct vgui::PanelMessageMap __near * CQuickListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CQuickListPanel::GetMessageMap(CQuickListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CQuickListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CQuickListPanel::GetMessageMap'::`2'::s_pMap;
  `CQuickListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CQuickListPanel");
  `CQuickListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014A60
// Name: public: virtual struct PanelAnimationMap __near * CQuickListPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CQuickListPanel::GetAnimMap(CQuickListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CQuickListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10014A70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CQuickListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CQuickListPanel::GetKBMap(CQuickListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CQuickListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CQuickListPanel::GetKBMap'::`2'::s_pMap;
  `CQuickListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CQuickListPanel");
  `CQuickListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014AA0
// Name: public: virtual void CQuickListPanel::OnPanelSelected(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CQuickListPanel::OnPanelSelected(CQuickListPanel *this, int state)
{
  vgui::ISchemeManager *v3; // edi
  vgui::ISchemeManager_vtbl *v4; // ebx
  unsigned int v5; // eax
  int v6; // eax
  vgui::Panel *m_pBGroundPanel; // ecx
  vgui::Panel_vtbl *v8; // edi
  _DWORD *v9; // eax
  vgui::Panel *v10; // ecx
  KeyValues *v11; // eax
  KeyValues *v12; // ebx
  vgui::Panel *v13; // eax
  CQuickListPanel_vtbl *v14; // edi
  int v15; // eax

  v3 = g_pVGuiSchemeManager;
  v4 = g_pVGuiSchemeManager->__vftable;
  v5 = this->GetScheme(this);
  v6 = (int)v4->GetIScheme(this: v3, a2: v5);
  if ( state != 0 )
  {
    if ( v6 == 0 || this->m_pBGroundPanel == nullptr )
      goto LABEL_9;
    m_pBGroundPanel = this->m_pBGroundPanel;
    state = 0xFFFFFF;
    v8 = m_pBGroundPanel->__vftable;
    v9 = (_DWORD *)(*(int (__thiscall **)(int, int *, const char *, int))(*(_DWORD *)v6 + 20))(
                     a1: v6,
                     a2: &state,
                     a3: "QuickListBGSelected",
                     a4: 0xFFFFFF);
  }
  else
  {
    if ( v6 == 0 || this->m_pBGroundPanel == nullptr )
      goto LABEL_9;
    v10 = this->m_pBGroundPanel;
    state = 0xFFFFFF;
    v8 = v10->__vftable;
    v9 = (_DWORD *)(*(int (__thiscall **)(int, int *, const char *, int))(*(_DWORD *)v6 + 20))(
                     a1: v6,
                     a2: &state,
                     a3: "QuickListBGDeselected",
                     a4: 0xFFFFFF);
  }
  ((void (__thiscall *)(vgui::Panel *, _DWORD))v8->SetBgColor)(a1: this->m_pBGroundPanel, a2: *v9);
LABEL_9:
  v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v11 != nullptr )
    v12 = KeyValues::KeyValues(this: v11, setName: "PanelSelected");
  else
    v12 = nullptr;
  v13 = this->GetParent(this);
  v14 = this->__vftable;
  v15 = ((int (__thiscall *)(vgui::Panel *, KeyValues *, _DWORD))v13->GetVParent)(a1: v13, a2: v12, a3: 0);
  ((void (__thiscall *)(CQuickListPanel *, int))v14->PostMessage_2)(a1: this, a2: v15);
}
