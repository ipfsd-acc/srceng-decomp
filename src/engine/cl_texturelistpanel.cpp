// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/cl_texturelistpanel.cpp
// Functions: 93
// ============================================================

#include "engine\cl_texturelistpanel.h"

//------------------------------------------------------------------------------
// Address: 0x10091470
// Name: public: static char const __near * vgui::TileViewPanelEx::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::TileViewPanelEx::GetPanelClassName()
{
  return "TileViewPanelEx";
}

//------------------------------------------------------------------------------
// Address: 0x10091480
// Name: public: virtual void vgui::TileViewPanelEx::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TileViewPanelEx::SetFont(vgui::TileViewPanelEx *this, unsigned int hFont)
{
  vgui::TileViewPanelEx_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_hFont = hFont;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x100914A0
// Name: public: virtual int vgui::TileViewPanelEx::HitTest(int,int,int __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::TileViewPanelEx::HitTest(vgui::TileViewPanelEx *this, int x, int y, int *iTile)
{
  int m_li_colVisible; // ecx
  int v7; // edi
  int v8; // eax
  int v9; // ecx

  *iTile = -1;
  if ( !this->ComputeLayoutInfo(this) )
    return 0;
  m_li_colVisible = this->m_li_colVisible;
  v7 = x / this->m_li_wideItem;
  v8 = y / this->m_li_tallItem;
  if ( v7 >= m_li_colVisible )
    return 0;
  if ( v8 > this->m_li_rowVisible )
    return 0;
  v9 = v7 + this->m_li_startTile + v8 * m_li_colVisible;
  if ( v9 >= this->m_li_endTile )
    return 0;
  *iTile = v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10091520
// Name: public: virtual bool vgui::TileViewPanelEx::GetTileOrg(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::TileViewPanelEx::GetTileOrg(vgui::TileViewPanelEx *this, int iTile, int *x, int *y)
{
  if ( this->m_li_colVisible <= 0 )
    return 0;
  if ( iTile < this->m_li_startTile || iTile >= this->m_li_endTile )
    return 0;
  *x = this->m_li_wideItem * ((iTile - this->m_li_startTile) % this->m_li_colVisible);
  *y = this->m_li_tallItem * ((iTile - this->m_li_startTile) / this->m_li_colVisible);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10091590
// Name: protected: virtual void vgui::TileViewPanelEx::OnMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TileViewPanelEx::OnMouseWheeled(vgui::TileViewPanelEx *this, int delta)
{
  int v3; // eax

  if ( this->m_hbar->IsVisible(this: this->m_hbar) )
  {
    v3 = this->m_hbar->GetValue(this: this->m_hbar);
    this->m_hbar->SetValue(this: this->m_hbar, a2: v3 - delta);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100915E0
// Name: protected: virtual void vgui::TileViewPanelEx::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TileViewPanelEx::PerformLayout(vgui::TileViewPanelEx *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // ecx
  int v5; // edi
  int v6; // eax
  int tall; // [esp+8h] [ebp-10h] BYREF
  int tallItem; // [esp+Ch] [ebp-Ch] BYREF
  int wideItem; // [esp+10h] [ebp-8h] BYREF
  int wide; // [esp+14h] [ebp-4h] BYREF

  v2 = this->GetNumTiles(this);
  this->m_hbar->SetVisible(this: this->m_hbar, a2: false);
  vgui::Panel::GetSize(this, &wide, &tall);
  v3 = vgui::Panel::GetWide(this: this->m_hbar);
  wide -= v3;
  vgui::Panel::SetPos(this: this->m_hbar, x: wide - 2, y: 0);
  vgui::Panel::SetTall(this: this->m_hbar, tall);
  if ( v2 != 0 )
  {
    wideItem = 1;
    tallItem = 1;
    this->GetTileSize(this, a2: &wideItem, a3: &tallItem);
    if ( wideItem != 0 && tallItem != 0 )
    {
      v4 = wide / wideItem;
      v5 = tall / tallItem;
      if ( tall / tallItem > 0 && v4 > 0 )
      {
        v6 = (v4 + v2 - 1) / v4;
        if ( v6 > v5 )
        {
          this->m_hbar->SetRange(this: this->m_hbar, a2: 0, a3: v6);
          this->m_hbar->SetRangeWindow(this: this->m_hbar, a2: v5);
          this->m_hbar->SetButtonPressedScrollValue(this: this->m_hbar, a2: 1);
          this->m_hbar->SetVisible(this: this->m_hbar, a2: true);
          this->m_hbar->InvalidateLayout(this: this->m_hbar, a2: false, a3: false);
          this->m_hbar->GetValue(this: this->m_hbar);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10091720
// Name: protected: virtual bool vgui::TileViewPanelEx::ComputeLayoutInfo(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::TileViewPanelEx::ComputeLayoutInfo(vgui::TileViewPanelEx *this)
{
  int v2; // eax
  vgui::TileViewPanelEx_vtbl *v4; // edx
  void (__thiscall *GetTileSize)(vgui::TileViewPanelEx *, int *, int *); // eax
  int m_li_wideItem; // ecx
  int m_li_tallItem; // ebx
  int v8; // ecx
  int v9; // eax
  int v10; // edi
  int v11; // eax
  int m_li_numTiles; // ecx
  int v13; // eax

  v2 = this->GetNumTiles(this);
  this->m_li_numTiles = v2;
  if ( v2 == 0 )
    return 0;
  vgui::Panel::GetSize(this, wide: &this->m_li_wide, tall: &this->m_li_tall);
  this->m_li_wide -= vgui::Panel::GetWide(this: this->m_hbar);
  v4 = this->__vftable;
  this->m_li_tallItem = 1;
  GetTileSize = v4->GetTileSize;
  this->m_li_wideItem = 1;
  GetTileSize(this, a2: &this->m_li_wideItem, a3: &this->m_li_tallItem);
  m_li_wideItem = this->m_li_wideItem;
  if ( m_li_wideItem == 0 )
    return 0;
  m_li_tallItem = this->m_li_tallItem;
  if ( m_li_tallItem == 0 )
    return 0;
  v8 = this->m_li_wide / m_li_wideItem;
  v9 = this->m_li_tall / m_li_tallItem;
  this->m_li_colVisible = v8;
  v10 = v9;
  this->m_li_rowVisible = v9;
  if ( v9 <= 0 || v8 <= 0 )
    return 0;
  v11 = (this->m_li_numTiles + v8 - 1) / v8;
  this->m_li_numVisibleTiles = v8 * v10;
  this->m_li_startTile = 0;
  this->m_li_rowNeeded = v11;
  if ( v11 > v10 )
    this->m_li_startTile = this->m_hbar->GetValue(this: this->m_hbar) * this->m_li_colVisible;
  m_li_numTiles = this->m_li_numTiles;
  if ( this->m_li_startTile >= m_li_numTiles )
    this->m_li_startTile = m_li_numTiles - this->m_li_numVisibleTiles;
  if ( this->m_li_startTile < 0 )
    this->m_li_startTile = 0;
  v13 = this->m_li_startTile + this->m_li_colVisible + this->m_li_numVisibleTiles;
  this->m_li_endTile = v13;
  if ( v13 > m_li_numTiles )
    this->m_li_endTile = m_li_numTiles;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10091870
// Name: protected: virtual void vgui::TileViewPanelEx::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TileViewPanelEx::Paint(vgui::TileViewPanelEx *this)
{
  int i; // edi

  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  if ( this->ComputeLayoutInfo(this) )
  {
    for ( i = this->m_li_startTile; i < this->m_li_endTile; ++i )
      this->RenderTile(
        this,
        a2: i,
        a3: (i - this->m_li_startTile) % this->m_li_colVisible * this->m_li_wideItem,
        a4: (i - this->m_li_startTile) / this->m_li_colVisible * this->m_li_tallItem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100918E0
// Name: protected: virtual void vgui::TileViewPanelEx::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TileViewPanelEx::ApplySchemeSettings(vgui::TileViewPanelEx *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::TileViewPanelEx_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::TileViewPanelEx_vtbl *v6; // ebx
  int v7; // eax
  vgui::TileViewPanelEx_vtbl *v8; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // edx
  bool v10; // al
  int v11; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ListPanel.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::TileViewPanelEx *, _DWORD))v4->SetBgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v6->SetBorder(this, a2: (vgui::IBorder *)v7);
  v8 = this->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (vgui::IScheme *)v2->__vftable;
  v10 = IsProportional(this);
  v11 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(a1: v2, a2: "Default", a3: v10);
  v8->SetFont(this, a2: v11);
}

//------------------------------------------------------------------------------
// Address: 0x10091970
// Name: ShallWarnTx
// Source: json
//------------------------------------------------------------------------------
bool __usercall ShallWarnTx@<al>(KeyValues *kv@<esi>, ITexture *tx@<ecx>)
{
  char *String; // eax
  char *v4; // eax
  char *v5; // eax
  char *v6; // eax

  if ( tx == nullptr )
    return false;
  if ( (tx->GetFlags(this: tx) & 0x1300) != 0 )
    return true;
  String = KeyValues::GetString(this: kv, keyName: "Format", defaultValue: defaultValue);
  if ( _V_stricmp(s1: "DXT1", s2: String) != 0 )
  {
    v4 = KeyValues::GetString(this: kv, keyName: "Format", defaultValue: defaultValue);
    if ( _V_stricmp(s1: "DXT5", s2: v4) != 0 )
    {
      v5 = KeyValues::GetString(this: kv, keyName: "Format", defaultValue: defaultValue);
      if ( _V_stricmp(s1: "ATI1N", s2: v5) != 0 )
      {
        v6 = KeyValues::GetString(this: kv, keyName: "Format", defaultValue: defaultValue);
        if ( _V_stricmp(s1: "ATI2N", s2: v6) != 0 )
          return true;
      }
    }
  }
  if ( KeyValues::GetInt(this: kv, keyName: "Size", defaultValue: 0) > g_warn_texkbytes
    || KeyValues::GetInt(this: kv, keyName: "Width", defaultValue: 0) > g_warn_texdimensions )
  {
    return true;
  }
  return KeyValues::GetInt(this: kv, keyName: "Height", defaultValue: 0) > g_warn_texdimensions;
}

//------------------------------------------------------------------------------
// Address: 0x10091A70
// Name: FmtCommaNumber
// Source: json
//------------------------------------------------------------------------------
void __cdecl FmtCommaNumber(char *pchBuffer, unsigned int uiNumber)
{
  char *v2; // edi
  unsigned int i; // esi
  const char *v4; // edx
  unsigned int v5; // eax

  v2 = pchBuffer;
  *pchBuffer = 0;
  for ( i = 1000000000; i != 0; i /= 0x3E8u )
  {
    if ( uiNumber > i )
    {
      v4 = "%d,";
      if ( uiNumber / i >= 0x3E8 )
        v4 = "%03d,";
      sprintf(string: &pchBuffer[strlen(v2)], format: v4, uiNumber / i % 0x3E8);
      v2 = pchBuffer;
    }
  }
  v5 = strlen(v2);
  if ( v5 != 0 )
  {
    if ( v2[v5 - 1] == 44 )
      v2[v5 - 1] = 0;
  }
  else
  {
    sprintf(string: v2, format: "0");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10091B10
// Name: public: static char const __near * CVmtTextEntry::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVmtTextEntry::GetPanelClassName()
{
  return "CVmtTextEntry";
}

//------------------------------------------------------------------------------
// Address: 0x10091B20
// Name: public: virtual void CVmtTextEntry::OpenEditMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVmtTextEntry::OpenEditMenu(CVmtTextEntry *this)
{
  vgui::Menu *EventDebugID; // esi
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  int v5; // eax
  vgui::Menu_vtbl *v6; // ebx
  bool v7; // al
  int x0; // [esp+Ch] [ebp-8h] BYREF
  int x1; // [esp+10h] [ebp-4h] BYREF

  EventDebugID = CHLTVServer::GetEventDebugID(this);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "DoOpenVmtSelected");
  else
    v4 = nullptr;
  v5 = EventDebugID->AddMenuItem(this: EventDebugID, a2: "Open VMT", a3: v4, a4: this, a5: nullptr);
  EventDebugID->MoveMenuItem(this: EventDebugID, a2: v5, a3: 0);
  v6 = EventDebugID->__vftable;
  v7 = this->GetSelectedRange(this, a2: &x0, a3: &x1);
  v6->SetItemEnabled(this: EventDebugID, a2: "Open VMT", a3: v7);
  vgui::TextEntry::OpenEditMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x10091BB0
// Name: public: static char const __near * CRenderTextureEditor::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CRenderTextureEditor::GetPanelClassName()
{
  return "CRenderTextureEditor";
}

//------------------------------------------------------------------------------
// Address: 0x10091BC0
// Name: public: virtual void CRenderTextureEditor::Activate(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CRenderTextureEditor::Activate(CRenderTextureEditor *this)
{
  vgui::Frame::Activate(this);
}

//------------------------------------------------------------------------------
// Address: 0x10091BD0
// Name: public: virtual void CRenderTextureEditor::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRenderTextureEditor::ApplySchemeSettings(CRenderTextureEditor *this, vgui::IScheme *pScheme)
{
  CRenderTextureEditor_vtbl *v4; // ebx
  bool v5; // al
  int v6; // eax
  vgui::IScheme *pSchemea; // [esp+14h] [ebp+8h]

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  v4 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v5 = this->IsProportional(this);
  v6 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemea[3].__vftable)(
         a1: pScheme,
         a2: "Default",
         a3: v5);
  v4->SetFont(this, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10091C20
// Name: public: virtual void CRenderTextureEditor::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRenderTextureEditor::OnMousePressed(CRenderTextureEditor *this, ButtonCode_t code)
{
  this->Close(this);
}

//------------------------------------------------------------------------------
// Address: 0x10091C30
// Name: public: static char const __near * CRenderTexturesListViewPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CRenderTexturesListViewPanel::GetPanelClassName()
{
  return "CRenderTexturesListViewPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10091C40
// Name: protected: virtual void CRenderTexturesListViewPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CRenderTexturesListViewPanel::PerformLayout(CRenderTexturesListViewPanel *this)
{
  vgui::TileViewPanelEx::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x10091C50
// Name: protected: virtual int CRenderTexturesListViewPanel::GetNumTiles(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRenderTexturesListViewPanel::GetNumTiles(CRenderTexturesListViewPanel *this)
{
  if ( this->m_pListPanel != nullptr )
    return this->m_pListPanel->GetItemCount(this: this->m_pListPanel);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10091C70
// Name: protected: virtual void CRenderTexturesListViewPanel::GetTileSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRenderTexturesListViewPanel::GetTileSize(CRenderTexturesListViewPanel *this, int *wide, int *tall)
{
  *wide = 232;
  *tall = 267;
}

//------------------------------------------------------------------------------
// Address: 0x10091C90
// Name: public: static char const __near * CTextureListPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CTextureListPanel::GetPanelClassName()
{
  return "CTextureListPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10091CA0
// Name: KilobytesSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl KilobytesSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  char *String; // esi
  char *v4; // edi
  int v5; // esi
  int v6; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "Size", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "Size", defaultValue: defaultValue);
  v5 = atoi(nptr: String);
  v6 = atoi(nptr: v4);
  if ( v5 >= v6 )
    return (v5 <= v6) - 1;
  else
    return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10091D00
// Name: public: CSmartTextureKeyValues::CSmartTextureKeyValues(void)
// Source: json
//------------------------------------------------------------------------------
CSmartTextureKeyValues *__thiscall CSmartTextureKeyValues::CSmartTextureKeyValues(CSmartTextureKeyValues *this)
{
  KeyValues *v2; // eax

  this->m_p = nullptr;
  v2 = g_pMaterialSystemDebugTextureInfo->LockDebugTextureList(this: g_pMaterialSystemDebugTextureInfo);
  if ( v2 != nullptr )
  {
    this->m_p = KeyValues::MakeCopy(this: v2);
    g_pMaterialSystemDebugTextureInfo->UnlockDebugTextureList(this: g_pMaterialSystemDebugTextureInfo);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10091D40
// Name: public: virtual void CTextureListPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureListPanel::ApplySchemeSettings(CTextureListPanel *this, vgui::IScheme *pScheme)
{
  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->m_hFont = pScheme->GetFont(this: pScheme, a2: "DefaultVerySmall", a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10091D70
// Name: public: virtual bool CTextureListPanel::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTextureListPanel::ShouldDraw(CTextureListPanel *this)
{
  return mat_texture_list.m_pParent != nullptr && mat_texture_list.m_pParent->m_Value.m_nValue != 0
      || s_eTxListPanelRequest == TXR_SHOW
      || s_eTxListPanelRequest == TXR_RUNNING;
}

//------------------------------------------------------------------------------
// Address: 0x10091DA0
// Name: ToLowerInplace
// Source: json
//------------------------------------------------------------------------------
void __usercall ToLowerInplace(char *chBuffer@<eax>)
{
  char *i; // esi

  for ( i = chBuffer; *i != 0; ++i )
  {
    if ( isupper(c: *i) != 0 )
      *i = tolower(c: *i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10091DE0
// Name: void KeepSpecialKeys(class KeyValues __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl KeepSpecialKeys(KeyValues *textureList, bool bServiceKeys)
{
  KeyValues *FirstSubKey; // edi
  char v3; // bl
  char *String; // esi
  KeyValues *pNext; // [esp+4h] [ebp-4h]

  FirstSubKey = KeyValues::GetFirstSubKey(this: textureList);
  if ( FirstSubKey != nullptr )
  {
    do
    {
      pNext = KeyValues::GetNextKey(this: FirstSubKey);
      v3 = 0;
      String = KeyValues::GetString(this: FirstSubKey, keyName: "Name", defaultValue: defaultValue);
      if ( StringAfterPrefix(str: String, prefix: "_") != nullptr
        || StringAfterPrefix(str: String, prefix: "[") != nullptr
        || _V_stricmp(s1: String, s2: "backbuffer") == 0
        || StringAfterPrefix(str: String, prefix: "colorcorrection") != nullptr
        || _V_stricmp(s1: String, s2: "depthbuffer") == 0
        || _V_stricmp(s1: String, s2: "frontbuffer") == 0
        || _V_stricmp(s1: String, s2: "normalize") == 0
        || *String == 0 )
      {
        v3 = 1;
      }
      if ( v3 == bServiceKeys )
      {
        if ( v3 != 0 )
          KeyValues::SetInt(this: FirstSubKey, keyName: "SpecialTx", value: 1);
      }
      else
      {
        KeyValues::RemoveSubKey(this: textureList, subKey: FirstSubKey);
      }
      FirstSubKey = pNext;
    }
    while ( pNext != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10091EE0
// Name: void KeepKeysMatchingFilter(class KeyValues __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl KeepKeysMatchingFilter(KeyValues *textureList, const char *szFilter)
{
  KeyValues *FirstSubKey; // edi
  KeyValues *NextKey; // ebx
  char *String; // eax
  char *i; // esi
  int v6; // eax
  char chFilter[260]; // [esp+4h] [ebp-208h] BYREF
  char chName[260]; // [esp+108h] [ebp-104h] BYREF

  if ( szFilter != nullptr && *szFilter != 0 )
  {
    memset(chFilter, 0, sizeof(chFilter));
    memset(chName, 0, sizeof(chName));
    V_strncpy(pDest: chFilter, pSrc: szFilter, maxLen: 259);
    ToLowerInplace(chBuffer: chFilter);
    FirstSubKey = KeyValues::GetFirstSubKey(this: textureList);
    if ( FirstSubKey != nullptr )
    {
      do
      {
        NextKey = KeyValues::GetNextKey(this: FirstSubKey);
        String = KeyValues::GetString(this: FirstSubKey, keyName: "Name", defaultValue: defaultValue);
        V_strncpy(pDest: chName, pSrc: String, maxLen: 259);
        for ( i = chName; *i != 0; ++i )
        {
          if ( isupper(c: *i) != 0 )
            *i = tolower(c: *i);
        }
        strstr(str1: (unsigned __int8 *)chName, str2: (unsigned __int8 *)chFilter);
        if ( v6 == 0 )
          KeyValues::RemoveSubKey(this: textureList, subKey: FirstSubKey);
        FirstSubKey = NextKey;
      }
      while ( NextKey != nullptr );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10092000
// Name: private: void CTextureListPanel::UpdateTotalUsageLabel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureListPanel::UpdateTotalUsageLabel(CTextureListPanel *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  wchar_t unicodeString[1024]; // [esp+4h] [ebp-C64h] BYREF
  char data[1024]; // [esp+804h] [ebp-464h] BYREF
  char kbMip1[20]; // [esp+C04h] [ebp-64h] BYREF
  char kbMip2[20]; // [esp+C18h] [ebp-50h] BYREF
  char kb1[20]; // [esp+C2Ch] [ebp-3Ch] BYREF
  char kb3[20]; // [esp+C40h] [ebp-28h] BYREF
  char kb2[20]; // [esp+C54h] [ebp-14h] BYREF

  v2 = g_pMaterialSystemDebugTextureInfo->GetTextureMemoryUsed(
         this: g_pMaterialSystemDebugTextureInfo,
         a2: MEMORY_BOUND_LAST_FRAME);
  FmtCommaNumber(pchBuffer: kb1, uiNumber: (v2 + 511) / 1024);
  v3 = g_pMaterialSystemDebugTextureInfo->GetTextureMemoryUsed(
         this: g_pMaterialSystemDebugTextureInfo,
         a2: MEMORY_TOTAL_LOADED);
  FmtCommaNumber(pchBuffer: kb2, uiNumber: (v3 + 511) / 1024);
  FmtCommaNumber(pchBuffer: kb3, uiNumber: this->m_numDisplayedSizeKB);
  if ( this->m_pCollapse->IsSelected(this: this->m_pCollapse) )
  {
    V_snprintf(pDest: data, maxLen: 1024, pFormat: "%s[F %s Kb] / [T %s Kb] / [S %s Kb]", defaultValue, kb1, kb2, kb3);
  }
  else
  {
    v4 = g_pMaterialSystemDebugTextureInfo->GetTextureMemoryUsed(
           this: g_pMaterialSystemDebugTextureInfo,
           a2: MEMORY_ESTIMATE_PICMIP_1);
    FmtCommaNumber(pchBuffer: kbMip1, uiNumber: (v4 + 511) / 1024);
    v5 = g_pMaterialSystemDebugTextureInfo->GetTextureMemoryUsed(
           this: g_pMaterialSystemDebugTextureInfo,
           a2: MEMORY_ESTIMATE_PICMIP_2);
    FmtCommaNumber(pchBuffer: kbMip2, uiNumber: (v5 + 511) / 1024);
    V_snprintf(
      pDest: data,
      maxLen: 1024,
      pFormat: "%s:  frame %s Kb  /  total %s Kb ( picmip1 = %s Kb, picmip2 = %s Kb )  /  shown %s Kb",
      "Texture Memory Usage",
      kb1,
      kb2,
      kbMip1,
      kbMip2,
      kb3);
  }
  g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: data, a3: unicodeString, a4: 2048);
  this->m_pTotalUsageLabel->SetText(this: this->m_pTotalUsageLabel, a2: unicodeString, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10092180
// Name: private: virtual void CTextureListPanel::OnTextChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureListPanel::OnTextChanged(CTextureListPanel *this)
{
  this->OnCommand(this, a2: "FilteringTxt");
}

//------------------------------------------------------------------------------
// Address: 0x10092190
// Name: private: bool CTextureListPanel::UpdateDisplayedItem(class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTextureListPanel::UpdateDisplayedItem(CTextureListPanel *this, KeyValues *pDispData, KeyValues *kv)
{
  int Int; // ebx
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  int v7; // ebx
  int v8; // ebx
  int v9; // ebx
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // eax
  const char *String; // [esp-4h] [ebp-14h]
  const char *v21; // [esp-4h] [ebp-14h]
  const char *v22; // [esp-4h] [ebp-14h]
  bool bUpdate; // [esp+Fh] [ebp-1h]

  bUpdate = false;
  Int = KeyValues::GetInt(this: pDispData, keyName: "BindsFrame", defaultValue: 0);
  if ( Int != KeyValues::GetInt(this: kv, keyName: "BindsFrame", defaultValue: 0) )
  {
    v4 = KeyValues::GetInt(this: kv, keyName: "BindsFrame", defaultValue: 0);
    KeyValues::SetInt(this: pDispData, keyName: "BindsFrame", value: v4);
    bUpdate = true;
  }
  v5 = KeyValues::GetInt(this: pDispData, keyName: "BindsMax", defaultValue: 0);
  if ( v5 != KeyValues::GetInt(this: kv, keyName: "BindsMax", defaultValue: 0) )
  {
    v6 = KeyValues::GetInt(this: kv, keyName: "BindsMax", defaultValue: 0);
    KeyValues::SetInt(this: pDispData, keyName: "BindsMax", value: v6);
    bUpdate = true;
  }
  v7 = KeyValues::GetInt(this: pDispData, keyName: "Size", defaultValue: 0);
  if ( v7 == KeyValues::GetInt(this: kv, keyName: "Size", defaultValue: 0) )
  {
    v8 = KeyValues::GetInt(this: pDispData, keyName: "Width", defaultValue: 0);
    if ( v8 == KeyValues::GetInt(this: kv, keyName: "Width", defaultValue: 0) )
    {
      v9 = KeyValues::GetInt(this: pDispData, keyName: "Height", defaultValue: 0);
      if ( v9 == KeyValues::GetInt(this: kv, keyName: "Height", defaultValue: 0) )
      {
        String = KeyValues::GetString(this: kv, keyName: "Format", defaultValue: defaultValue);
        v10 = KeyValues::GetString(this: pDispData, keyName: "Format", defaultValue: defaultValue);
        if ( _V_stricmp(s1: v10, s2: String) == 0 )
        {
          v21 = KeyValues::GetString(this: kv, keyName: "Path", defaultValue: defaultValue);
          v11 = KeyValues::GetString(this: pDispData, keyName: "Path", defaultValue: defaultValue);
          if ( _V_stricmp(s1: v11, s2: v21) == 0 )
          {
            v22 = KeyValues::GetString(this: kv, keyName: "TexGroup", defaultValue: defaultValue);
            v12 = KeyValues::GetString(this: pDispData, keyName: "TexGroup", defaultValue: defaultValue);
            if ( _V_stricmp(s1: v12, s2: v22) == 0 )
              return bUpdate;
          }
        }
      }
    }
  }
  v13 = KeyValues::GetInt(this: kv, keyName: "Size", defaultValue: 0);
  KeyValues::SetInt(this: pDispData, keyName: "Size", value: v13);
  v14 = KeyValues::GetInt(this: kv, keyName: "Width", defaultValue: 0);
  KeyValues::SetInt(this: pDispData, keyName: "Width", value: v14);
  v15 = KeyValues::GetInt(this: kv, keyName: "Height", defaultValue: 0);
  KeyValues::SetInt(this: pDispData, keyName: "Height", value: v15);
  v16 = KeyValues::GetString(this: kv, keyName: "Format", defaultValue: defaultValue);
  KeyValues::SetString(this: pDispData, keyName: "Format", value: v16);
  v17 = KeyValues::GetString(this: kv, keyName: "Path", defaultValue: defaultValue);
  KeyValues::SetString(this: pDispData, keyName: "Path", value: v17);
  v18 = KeyValues::GetString(this: kv, keyName: "TexGroup", defaultValue: defaultValue);
  KeyValues::SetString(this: pDispData, keyName: "TexGroup", value: v18);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100923F0
// Name: private: int CTextureListPanel::AddListItem(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTextureListPanel::AddListItem(CTextureListPanel *this, KeyValues *kv)
{
  vgui::ListPanel_vtbl *v3; // ebx
  const char *String; // eax
  int v5; // ebx
  const char *v6; // eax
  int v7; // edi
  KeyValues *v9; // eax

  v3 = this->m_pListPanel->__vftable;
  String = KeyValues::GetString(this: kv, keyName: "Name", defaultValue: defaultValue);
  v5 = v3->GetItem_2(this: this->m_pListPanel, a2: String);
  if ( v5 == -1 )
  {
    v6 = KeyValues::GetString(this: kv, keyName: "Name", defaultValue: defaultValue);
    KeyValues::SetName(this: kv, setName: v6);
    v7 = this->m_pListPanel->AddItem(this: this->m_pListPanel, a2: kv, a3: 0, a4: false, a5: false);
    this->m_pViewPanel->InvalidateLayout(this: this->m_pViewPanel, a2: false, a3: false);
    return v7;
  }
  else
  {
    v9 = this->m_pListPanel->GetItem(this: this->m_pListPanel, a2: v5);
    if ( CTextureListPanel::UpdateDisplayedItem(this, pDispData: v9, kv) != 0 )
    {
      this->m_pListPanel->ApplyItemChanges(this: this->m_pListPanel, a2: v5);
      this->m_pViewPanel->Repaint(this: this->m_pViewPanel);
    }
    return v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100924C0
// Name: void mat_texture_list_off_f(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall mat_texture_list_off_f(CTextureListPanel *this)
{
  unsigned int v1; // [esp-8h] [ebp-8h]
  int v2; // [esp-4h] [ebp-4h]

  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_texture_list.IConVar, value: 0, a2: v1, a3: v2);
  s_eTxListPanelRequest = TXR_HIDE;
}

//------------------------------------------------------------------------------
// Address: 0x100924E0
// Name: public: void CUtlMemory<bool,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<bool,int>::Grow(CUtlMemory<char,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  char *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 32;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (char *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: m_nAllocationCount);
    else
      this->m_pMemory = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10092580
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::TileViewPanelEx::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::TileViewPanelEx::GetMessageMap(vgui::TileViewPanelEx *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::TileViewPanelEx::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TileViewPanelEx::GetMessageMap'::`2'::s_pMap;
  `vgui::TileViewPanelEx::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "TileViewPanelEx");
  `vgui::TileViewPanelEx::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100925B0
// Name: public: virtual struct PanelAnimationMap __near * vgui::TileViewPanelEx::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::TileViewPanelEx::GetAnimMap(vgui::TileViewPanelEx *this)
{
  return FindOrAddPanelAnimationMap(className: "TileViewPanelEx");
}

//------------------------------------------------------------------------------
// Address: 0x100925C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::TileViewPanelEx::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::TileViewPanelEx::GetKBMap(vgui::TileViewPanelEx *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::TileViewPanelEx::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TileViewPanelEx::GetKBMap'::`2'::s_pMap;
  `vgui::TileViewPanelEx::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "TileViewPanelEx");
  `vgui::TileViewPanelEx::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10092630
// Name: bool CanAdjustTextureSize(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CanAdjustTextureSize(const char *szTextureName, bool bMoveSizeUp)
{
  ITexture *v2; // esi
  int v4; // eax
  int v5; // edi
  MaterialTextureInfo_t txInfo; // [esp+8h] [ebp-4h] BYREF

  v2 = materials->FindTexture(this: materials, a2: szTextureName, a3: defaultValue, a4: 0, a5: 0);
  if ( v2 == nullptr
    || mat_texture_list_exclude_editing.m_pParent != nullptr
    && mat_texture_list_exclude_editing.m_pParent->m_Value.m_nValue > 0
    && (!materials->GetTextureInformation(this: materials, a2: szTextureName, a3: &txInfo)
     || txInfo.iExcludeInformation == 0) )
  {
    return 0;
  }
  v4 = v2->GetActualWidth(this: v2);
  if ( bMoveSizeUp )
  {
    if ( v4 < v2->GetMappingWidth(this: v2) )
      return 1;
    v5 = v2->GetActualHeight(this: v2);
    if ( v5 < v2->GetMappingHeight(this: v2) )
      return 1;
  }
  else if ( v4 > 4 || v2->GetActualHeight(this: v2) > 4 )
  {
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100926F0
// Name: bool AdjustTextureSize(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl AdjustTextureSize(const char *szTextureName, bool bMoveSizeUp)
{
  ITexture *v2; // esi
  int v4; // edi
  int v5; // eax
  ITexture_vtbl *v6; // edx
  int v7; // eax

  v2 = materials->FindTexture(this: materials, a2: szTextureName, a3: defaultValue, a4: 0, a5: 0);
  if ( v2 == nullptr )
    return 0;
  if ( mat_texture_list_exclude_editing.m_pParent != nullptr
    && mat_texture_list_exclude_editing.m_pParent->m_Value.m_nValue > 0 )
  {
    v4 = v2->GetActualHeight(this: v2);
    v5 = v2->GetActualWidth(this: v2);
    v6 = v2->__vftable;
    if ( v5 <= v4 )
      v7 = ((int (__fastcall *)(ITexture *))v6->GetActualHeight)(a1: v2);
    else
      v7 = ((int (__fastcall *)(ITexture *))v6->GetActualWidth)(a1: v2);
    if ( bMoveSizeUp )
      v2->ForceExcludeOverride(this: v2, a2: 2 * v7);
    else
      v2->ForceExcludeOverride(this: v2, a2: v7 >> 1);
    return 1;
  }
  else
  {
    v2->ForceLODOverride(this: v2, a2: 2 * bMoveSizeUp - 1);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100927A0
// Name: bool AdjustTextureExclude(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl AdjustTextureExclude(const char *szTextureName, bool bExclude)
{
  ITexture *v2; // eax

  v2 = materials->FindTexture(this: materials, a2: szTextureName, a3: defaultValue, a4: 0, a5: 0);
  if ( v2 == nullptr
    || mat_texture_list_exclude_editing.m_pParent == nullptr
    || mat_texture_list_exclude_editing.m_pParent->m_Value.m_nValue <= 0 )
  {
    return 0;
  }
  v2->ForceExcludeOverride(this: v2, a2: bExclude - 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100927F0
// Name: bool IsTextureExcluded(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __usercall IsTextureExcluded@<al>(int a1@<esi>, const char *szTextureName)
{
  MaterialTextureInfo_t txInfo; // [esp+0h] [ebp-4h] BYREF

  if ( mat_texture_list_exclude_editing.m_pParent == nullptr
    || mat_texture_list_exclude_editing.m_pParent->m_Value.m_nValue <= 0 )
  {
    return false;
  }
  if ( ((int (__thiscall *)(IMaterialSystem *, const char *, const char *, _DWORD, _DWORD, int))materials->FindTexture)(
         a1: materials,
         a2: szTextureName,
         a3: defaultValue,
         a4: 0,
         a5: 0,
         a6: a1) != 0
    && materials->GetTextureInformation(this: materials, a2: szTextureName, a3: &txInfo) )
  {
    return txInfo.iExcludeInformation == 0;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10092860
// Name: mat_texture_list_txlod
// Source: json
//------------------------------------------------------------------------------
void __cdecl mat_texture_list_txlod(const CCommand *args)
{
  const char *v1; // esi
  int v2; // eax
  int v3; // esi
  bool v4; // bl
  bool v5; // bl
  bool v6; // zf
  const char *v7; // eax

  if ( args->m_nArgc != 2 )
    goto LABEL_22;
  v1 = args->m_ppArgv[1];
  if ( _V_stricmp(s1: v1, s2: "exclude") != 0 && _V_stricmp(s1: v1, s2: "noexclude") != 0 )
  {
    v2 = atoi(nptr: v1);
    v3 = v2;
    if ( v2 == -1 || v2 == 1 )
    {
      v4 = v2 > 0;
      if ( CanAdjustTextureSize(szTextureName: `anonymous namespace'::s_chLastViewedTextureBuffer, bMoveSizeUp: v2 > 0) != 0 )
      {
        if ( AdjustTextureSize(szTextureName: `anonymous namespace'::s_chLastViewedTextureBuffer, bMoveSizeUp: v4) != 0 )
          _Msg(
            a1: "mat_texture_list_txlod adjusted lod %c1 for '%s'\n",
            2 * (v3 <= 0) + 43,
            `anonymous namespace'::s_chLastViewedTextureBuffer);
        else
          _Warning(
            a1: "mat_texture_list_txlod failed adjusting lod for '%s'\n",
            `anonymous namespace'::s_chLastViewedTextureBuffer);
      }
      else
      {
        _Warning(
          a1: "mat_texture_list_txlod cannot adjust lod for '%s'\n",
          `anonymous namespace'::s_chLastViewedTextureBuffer);
      }
      return;
    }
LABEL_22:
    _Warning(a1: "Usage: 'mat_texture_list_txlod +1' to inc lod | 'mat_texture_list_txlod -1' to dec lod\n");
    return;
  }
  v5 = _V_stricmp(s1: v1, s2: "exclude") == 0;
  if ( mat_texture_list_exclude_editing.m_pParent != nullptr
    && mat_texture_list_exclude_editing.m_pParent->m_Value.m_nValue > 0
    && materials->FindTexture(
         this: materials,
         a2: `anonymous namespace'::s_chLastViewedTextureBuffer,
         a3: defaultValue,
         a4: 0,
         a5: 0) != nullptr )
  {
    v6 = AdjustTextureExclude(szTextureName: `anonymous namespace'::s_chLastViewedTextureBuffer, bExclude: v5) == 0;
    v7 = defaultValue;
    if ( v6 )
    {
      if ( !v5 )
        v7 = "no";
      _Warning(
        a1: "mat_texture_list_txlod failed %sexcluding '%s'\n",
        v7,
        `anonymous namespace'::s_chLastViewedTextureBuffer);
    }
    else
    {
      if ( !v5 )
        v7 = "no";
      _Msg(a1: "mat_texture_list_txlod %sexcluded '%s'\n", v7, `anonymous namespace'::s_chLastViewedTextureBuffer);
    }
  }
  else
  {
    _Warning(
      a1: "mat_texture_list_txlod cannot adjust exclude for '%s'\n",
      `anonymous namespace'::s_chLastViewedTextureBuffer);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10092A00
// Name: public: virtual void CRenderTextureEditor::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CRenderTextureEditor::PerformLayout(CRenderTextureEditor *this@<ecx>, int a2@<ebx>)
{
  KeyValues *m_pInfo; // edi
  const char *String; // eax
  const char *v5; // edi
  vgui::Button_vtbl *v6; // ebx
  bool v7; // al
  vgui::Button_vtbl *v8; // ebx
  bool v9; // al
  vgui::Button_vtbl *v10; // ebx
  bool v11; // al
  int Tall; // eax
  int Wide; // eax
  int v14; // eax
  int v15; // eax
  int v16; // edi
  int v17; // eax
  int v18; // eax
  int v19; // eax
  vgui::Button *m_pExplore; // ecx
  int v21; // eax
  vgui::Button *m_pCopyImg; // ecx
  vgui::Button *m_pCopyTxt; // ecx
  vgui::Button *m_pFlashBtn; // ecx
  int v25; // [esp-8h] [ebp-218h]
  char chResolveName[256]; // [esp+8h] [ebp-208h] BYREF
  char chResolveNameArg[256]; // [esp+108h] [ebp-108h] BYREF
  int posY; // [esp+208h] [ebp-8h] BYREF
  int posX; // [esp+20Ch] [ebp-4h] BYREF

  vgui::Frame::PerformLayout(this);
  vgui::Panel::SetSize(this, wide: 590, tall: 760);
  vgui::Panel::SetPos(this: this->m_pMaterials, x: 10, y: 662);
  vgui::Panel::SetSize(this: this->m_pMaterials, wide: 570, tall: 90);
  vgui::Panel::SetPos(this: this->m_pExplore, x: 520, y: 20);
  vgui::Panel::SetWide(this: this->m_pExplore, wide: 50);
  vgui::Panel::SetPos(this: this->m_pReload, x: 455, y: 20);
  vgui::Panel::SetWide(this: this->m_pReload, wide: 60);
  this->m_pReload->SetVisible(this: this->m_pReload, a2: this->m_lstMaterials.m_Size > 0);
  this->m_pExplore->SetVisible(this: this->m_pExplore, a2: false);
  this->m_pSizeControls[0]->SetVisible(this: this->m_pSizeControls[0], a2: false);
  this->m_pSizeControls[1]->SetVisible(this: this->m_pSizeControls[1], a2: false);
  this->m_pSizeControls[2]->SetVisible(this: this->m_pSizeControls[2], a2: false);
  m_pInfo = this->m_pInfo;
  if ( m_pInfo != nullptr )
  {
    memset(chResolveName, 0, sizeof(chResolveName));
    memset(chResolveNameArg, 0, sizeof(chResolveNameArg));
    String = KeyValues::GetString(this: m_pInfo, keyName: "Name", defaultValue: defaultValue);
    V_snprintf(pDest: chResolveNameArg, maxLen: 255, pFormat: "materials/%s.vtf", String);
    if ( g_pFileSystem->RelativePathToFullPath(
           this: g_pFileSystem,
           a2: chResolveNameArg,
           a3: "game",
           a4: chResolveName,
           a5: 255,
           a6: 0,
           a7: 0) != nullptr )
      this->m_pExplore->SetVisible(this: this->m_pExplore, a2: true);
    v5 = KeyValues::GetString(this: this->m_pInfo, keyName: "Name", defaultValue: defaultValue);
    if ( KeyValues::GetInt(this: this->m_pInfo, keyName: "SpecialTx", defaultValue: 0) == 0 )
    {
      ((void (__thiscall *)(vgui::Button *, int, int))this->m_pSizeControls[0]->SetVisible)(
        a1: this->m_pSizeControls[0],
        a2: 1,
        a3: a2);
      this->m_pSizeControls[1]->SetVisible(this: this->m_pSizeControls[1], a2: true);
      if ( mat_texture_list_exclude_editing.m_pParent != nullptr
        && mat_texture_list_exclude_editing.m_pParent->m_Value.m_nValue > 0
        && materials->FindTexture(this: materials, a2: v5, a3: defaultValue, a4: 0, a5: 0) != nullptr )
      {
        this->m_pSizeControls[2]->SetVisible(this: this->m_pSizeControls[2], a2: true);
        v6 = this->m_pSizeControls[2]->__vftable;
        v7 = IsTextureExcluded(szTextureName: v5);
        v6->SetSelected(this: this->m_pSizeControls[2], a2: v7);
      }
      v8 = this->m_pSizeControls[0]->__vftable;
      v9 = CanAdjustTextureSize(szTextureName: v5, bMoveSizeUp: false);
      v8->SetEnabled(this: this->m_pSizeControls[0], a2: v9);
      v10 = this->m_pSizeControls[1]->__vftable;
      v11 = CanAdjustTextureSize(szTextureName: v5, bMoveSizeUp: true);
      v10->SetEnabled(this: this->m_pSizeControls[1], a2: v11);
      vgui::Panel::GetPos(this: this->m_pExplore, x: &posX, y: &posY);
      Tall = vgui::Panel::GetTall(this: this->m_pExplore);
      vgui::Panel::SetPos(this: this->m_pSizeControls[0], x: posX, y: Tall + posY + 1);
      Wide = vgui::Panel::GetWide(this: this->m_pExplore);
      vgui::Panel::SetWide(this: this->m_pSizeControls[0], wide: Wide / 2);
      v14 = vgui::Panel::GetTall(this: this->m_pExplore);
      v25 = v14 + posY + 1;
      v15 = vgui::Panel::GetWide(this: this->m_pSizeControls[0]);
      vgui::Panel::SetPos(this: this->m_pSizeControls[1], x: v15 + posX + 1, y: v25);
      v16 = vgui::Panel::GetWide(this: this->m_pExplore);
      v17 = vgui::Panel::GetWide(this: this->m_pSizeControls[0]);
      vgui::Panel::SetWide(this: this->m_pSizeControls[1], wide: v16 - v17 - 1);
      v18 = vgui::Panel::GetTall(this: this->m_pExplore);
      vgui::Panel::SetPos(this: this->m_pSizeControls[2], x: posX - 81, y: v18 + posY + 1);
      vgui::Panel::SetWide(this: this->m_pSizeControls[2], wide: 80);
    }
  }
  vgui::Panel::GetPos(this: this->m_pExplore, x: &posX, y: &posY);
  v19 = vgui::Panel::GetTall(this: this->m_pExplore);
  m_pExplore = this->m_pExplore;
  posY += 2 * v19 + 2;
  v21 = vgui::Panel::GetWide(this: m_pExplore);
  m_pCopyImg = this->m_pCopyImg;
  posX = posX + v21 - 80;
  vgui::Panel::SetPos(this: m_pCopyImg, x: posX, y: posY);
  vgui::Panel::SetWide(this: this->m_pCopyImg, wide: 80);
  m_pCopyTxt = this->m_pCopyTxt;
  posX -= 85;
  vgui::Panel::SetPos(this: m_pCopyTxt, x: posX, y: posY);
  vgui::Panel::SetWide(this: this->m_pCopyTxt, wide: 80);
  m_pFlashBtn = this->m_pFlashBtn;
  posX -= 100;
  vgui::Panel::SetPos(this: m_pFlashBtn, x: posX, y: posY);
  vgui::Panel::SetWide(this: this->m_pFlashBtn, wide: 95);
}

//------------------------------------------------------------------------------
// Address: 0x10092E30
// Name: public: virtual struct vgui::PanelMessageMap __near * CTextureListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CTextureListPanel::GetMessageMap(CTextureListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CTextureListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CTextureListPanel::GetMessageMap'::`2'::s_pMap;
  `CTextureListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTextureListPanel");
  `CTextureListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10092E60
// Name: public: virtual struct PanelAnimationMap __near * CTextureListPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CTextureListPanel::GetAnimMap(CTextureListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CTextureListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10092E70
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CTextureListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CTextureListPanel::GetKBMap(CTextureListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CTextureListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CTextureListPanel::GetKBMap'::`2'::s_pMap;
  `CTextureListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTextureListPanel");
  `CTextureListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10092EE0
// Name: public: virtual void CTextureListPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureListPanel::PerformLayout(CTextureListPanel *this)
{
  bool v2; // bl
  void (__thiscall *GetClientArea)(vgui::Frame *, int *, int *, int *, int *); // eax
  int v4; // edi
  int Tall; // eax
  vgui::Label *m_pTotalUsageLabel; // ecx
  vgui::Label_vtbl *v7; // edx
  int v8; // edi
  CConVarCheckButton *m_pShowTextureMemoryUsageOption; // edx
  CConVarCheckButton *m_pAllTextures; // eax
  CConVarCheckButton *m_pViewTextures; // ecx
  vgui::CheckButton *m_pFilteringChk; // edx
  vgui::Button *m_pCopyToClipboardButton; // ecx
  vgui::Panel *v14; // ebx
  CConVarCheckButton *v15; // ecx
  int v16; // eax
  int v17; // eax
  vgui::CheckButton *v18; // ecx
  int v19; // eax
  int v20; // eax
  vgui::Label *v21; // ecx
  CConVarCheckButton *v22; // edx
  CConVarCheckButton *v23; // ecx
  vgui::CheckButton *v24; // edx
  vgui::TextEntry *m_pFilteringText; // eax
  int v26; // edi
  vgui::Panel *v27; // ebx
  int v28; // edi
  vgui::CheckButton_vtbl *v29; // ebx
  bool v30; // al
  int v31; // eax
  int m_nValue; // eax
  int v33; // eax
  vgui::Panel *v34; // [esp+Ch] [ebp-4Ch]
  _DWORD v35[4]; // [esp+10h] [ebp-48h]
  vgui::Panel *buttons[7]; // [esp+20h] [ebp-38h]
  int t; // [esp+3Ch] [ebp-1Ch] BYREF
  int k; // [esp+40h] [ebp-18h]
  int y; // [esp+44h] [ebp-14h] BYREF
  int xOffset; // [esp+48h] [ebp-10h]
  int w; // [esp+4Ch] [ebp-Ch] BYREF
  int x; // [esp+50h] [ebp-8h] BYREF
  bool bCollapsed; // [esp+57h] [ebp-1h]

  vgui::Frame::PerformLayout(this);
  vgui::Panel::SetPos(this: this->m_pCollapse, x: 2, y: 10);
  vgui::Panel::SetSize(this: this->m_pCollapse, wide: 10, tall: 10);
  this->m_pCollapse->SetVisible(this: this->m_pCollapse, a2: true);
  v2 = this->m_pCollapse->IsSelected(this: this->m_pCollapse);
  GetClientArea = this->GetClientArea;
  bCollapsed = v2;
  GetClientArea(this, a2: &x, a3: &y, a4: &w, a5: &t);
  v4 = y;
  vgui::Panel::SetPos(this: this->m_pCVarListLabel, x, y);
  vgui::Panel::SetWide(this: this->m_pCVarListLabel, wide: w);
  this->m_pCVarListLabel->SetVisible(this: this->m_pCVarListLabel, a2: false);
  vgui::Panel::SetPos(this: this->m_pTotalUsageLabel, x, y: v4);
  vgui::Panel::SetWide(this: this->m_pTotalUsageLabel, wide: w);
  Tall = vgui::Panel::GetTall(this: this->m_pTotalUsageLabel);
  m_pTotalUsageLabel = this->m_pTotalUsageLabel;
  v7 = m_pTotalUsageLabel->__vftable;
  v8 = Tall + v4;
  LOBYTE(Tall) = !v2;
  LOBYTE(k) = !v2;
  v7->SetVisible(this: m_pTotalUsageLabel, a2: Tall);
  m_pShowTextureMemoryUsageOption = this->m_pShowTextureMemoryUsageOption;
  m_pAllTextures = this->m_pAllTextures;
  buttons[0] = this->m_pSpecialTexs;
  m_pViewTextures = this->m_pViewTextures;
  buttons[1] = m_pShowTextureMemoryUsageOption;
  m_pFilteringChk = this->m_pFilteringChk;
  buttons[2] = m_pAllTextures;
  buttons[3] = m_pViewTextures;
  buttons[4] = m_pFilteringChk;
  m_pCopyToClipboardButton = this->m_pCopyToClipboardButton;
  buttons[5] = this->m_pResolveTexturePath;
  buttons[6] = m_pCopyToClipboardButton;
  for ( xOffset = 0; (unsigned int)xOffset < 7; ++xOffset )
  {
    v14 = buttons[xOffset];
    vgui::Panel::SetPos(this: v14, x, y: v8);
    vgui::Panel::SetWide(this: v14, wide: w / 2);
    v8 += vgui::Panel::GetTall(this: v14);
    v14->SetVisible(this: v14, a2: k);
    v15 = this->m_pViewTextures;
    if ( v14 == v15 )
    {
      vgui::Panel::SetWide(this: v15, wide: 170);
      v16 = vgui::Panel::GetTall(this: this->m_pViewTextures);
      vgui::Panel::SetPos(this: this->m_pAlpha, x: x + 175, y: v8 - v16);
      vgui::Panel::SetWide(this: this->m_pAlpha, wide: 85);
      v17 = vgui::Panel::GetTall(this: this->m_pViewTextures);
      vgui::Panel::SetPos(this: this->m_pThumbWarnings, x: x + 260, y: v8 - v17);
      vgui::Panel::SetWide(this: this->m_pThumbWarnings, wide: 85);
    }
    v18 = this->m_pFilteringChk;
    if ( v14 == v18 )
    {
      vgui::Panel::SetWide(this: v18, wide: 60);
      v19 = vgui::Panel::GetTall(this: this->m_pFilteringChk);
      vgui::Panel::SetPos(this: this->m_pFilteringText, x: x + 65, y: v8 - v19);
      vgui::Panel::SetWide(this: this->m_pFilteringText, wide: 170);
      v20 = vgui::Panel::GetTall(this: this->m_pFilteringChk);
      vgui::Panel::SetTall(this: this->m_pFilteringText, tall: v20);
      this->m_pFilteringText->SetVisible(this: this->m_pFilteringText, a2: k);
    }
  }
  if ( bCollapsed )
  {
    v21 = this->m_pTotalUsageLabel;
    v22 = this->m_pViewTextures;
    v35[3] = this->m_pAlpha;
    v34 = v21;
    v23 = this->m_pAllTextures;
    v35[1] = v22;
    v24 = this->m_pFilteringChk;
    buttons[0] = (vgui::Panel *)60;
    buttons[4] = (vgui::Panel *)60;
    m_pFilteringText = this->m_pFilteringText;
    v26 = 0;
    xOffset = 85;
    v35[0] = 290;
    v35[2] = 170;
    buttons[1] = v23;
    buttons[2] = (vgui::Panel *)135;
    buttons[3] = v24;
    buttons[5] = m_pFilteringText;
    buttons[6] = (vgui::Panel *)130;
    for ( k = 0; ; v26 = k )
    {
      v27 = (vgui::Panel *)v35[2 * v26 - 1];
      vgui::Panel::SetPos(this: v27, x: xOffset, y: 2);
      v28 = v35[2 * v26];
      if ( w - xOffset - 30 < v28 )
        v28 = w - xOffset - 30;
      vgui::Panel::SetWide(this: v27, wide: v28);
      v27->SetVisible(this: v27, a2: v28 > 50);
      if ( v28 > 50 )
        xOffset += v28 + 5;
      if ( (unsigned int)++k >= 6 )
        break;
    }
    v8 = y;
  }
  v29 = this->m_pAlpha->__vftable;
  v30 = this->m_pViewTextures->IsSelected(this: this->m_pViewTextures);
  v31 = ((int (__thiscall *)(vgui::CheckButton *, bool))v29->SetVisible)(a1: this->m_pAlpha, a2: v30);
  LOBYTE(v31) = !bCollapsed
             && (_BYTE)(v31 = ((int (__thiscall *)(CConVarCheckButton *))this->m_pViewTextures->IsSelected)(a1: this->m_pViewTextures)) != 0;
  this->m_pThumbWarnings->SetVisible(this: this->m_pThumbWarnings, a2: v31);
  vgui::Panel::SetBounds(this: this->m_pListPanel, x, y: v8, wide: w, tall: t + y - v8);
  vgui::Panel::SetBounds(this: this->m_pViewPanel, x, y: v8, wide: w, tall: t + y - v8);
  if ( mat_texture_list_view.m_pParent != nullptr )
    m_nValue = mat_texture_list_view.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  this->m_pListPanel->SetVisible(this: this->m_pListPanel, a2: m_nValue == 0);
  if ( mat_texture_list_view.m_pParent != nullptr )
    v33 = mat_texture_list_view.m_pParent->m_Value.m_nValue;
  else
    v33 = 0;
  this->m_pViewPanel->SetVisible(this: this->m_pViewPanel, a2: v33 != 0);
}

//------------------------------------------------------------------------------
// Address: 0x10093510
// Name: void mat_texture_list_on_f(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl mat_texture_list_on_f()
{
  CTextureListPanel *v0; // esi
  CRenderTextureEditor *m_pRenderTxEditor; // ecx
  unsigned int v2; // [esp-8h] [ebp-Ch]
  int v3; // [esp-4h] [ebp-8h]

  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_texture_list.IConVar, value: 1, a2: v2, a3: v3);
  s_eTxListPanelRequest = TXR_SHOW;
  v0 = g_pTextureListPanel;
  if ( !g_bRecursiveRequestToShowTextureList )
  {
    if ( g_pTextureListPanel->m_pListPanel != nullptr )
      g_pTextureListPanel->m_pListPanel->DeleteAllItems(this: g_pTextureListPanel->m_pListPanel);
    m_pRenderTxEditor = v0->m_pViewPanel->m_pRenderTxEditor;
    if ( m_pRenderTxEditor != nullptr )
      m_pRenderTxEditor->Close(this: m_pRenderTxEditor);
  }
  MatViewOverride::s_viewParamsReq.lstMaterials.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100948B0
// Name: private: virtual void CTextureListPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureListPanel::OnCommand(CTextureListPanel *this, const char *command)
{
  bool v3; // al
  CRenderTexturesListViewPanel *m_pViewPanel; // ecx

  if ( _V_stricmp(s1: command, s2: "Close") == 0 )
  {
    vgui::Frame::OnCommand(this, command);
    return;
  }
  if ( _V_stricmp(s1: command, s2: "Collapse") == 0 )
    goto LABEL_4;
  if ( _V_stricmp(s1: command, s2: "ShowAlpha") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "ThumbWarnings") != 0 )
    {
      if ( _V_stricmp(s1: command, s2: "ViewThumbnails") == 0 )
      {
LABEL_4:
        this->InvalidateLayout(this, a2: false, a3: false);
        return;
      }
      if ( _V_stricmp(s1: command, s2: "CopyToClipboard") != 0 )
      {
        mat_texture_list_on_f();
        this->InvalidateLayout(this, a2: false, a3: false);
      }
      else
      {
        CopyListPanelToClipboard(pListPanel: this->m_pListPanel);
      }
    }
    else
    {
      g_warn_enable = this->m_pThumbWarnings->IsSelected(this: this->m_pThumbWarnings);
    }
  }
  else
  {
    v3 = this->m_pAlpha->IsSelected(this: this->m_pAlpha);
    m_pViewPanel = this->m_pViewPanel;
    m_pViewPanel->m_bPaintAlpha = v3;
    m_pViewPanel->Repaint(this: m_pViewPanel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100966D0
// Name: public: virtual void CRenderTextureEditor::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRenderTextureEditor::OnCommand(CRenderTextureEditor *this, const char *command)
{
  const char *v2; // ebx
  KeyValues *m_pInfo; // esi
  const char *String; // eax
  const char *v6; // eax
  int v7; // esi
  int v8; // ebx
  int m_Put; // eax
  unsigned __int16 v10; // dx
  const char *v11; // eax
  const char *v12; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v14; // edx
  void *v15; // eax
  vgui::ISystem *v16; // ebx
  vgui::ISystem_vtbl *v17; // esi
  KeyValues *v18; // ecx
  const char *v19; // eax
  bool v20; // bl
  bool v21; // bl
  const char *v22; // eax
  ITexture *v23; // eax
  bool v24; // bl
  unsigned int v25; // [esp-44h] [ebp-38Ch]
  int v26; // [esp-40h] [ebp-388h]
  bool v27; // [esp-40h] [ebp-388h]
  unsigned __int8 *m_pMemory; // [esp-2Ch] [ebp-374h]
  char params[256]; // [esp+Ch] [ebp-33Ch] BYREF
  char chResolveName[256]; // [esp+10Ch] [ebp-23Ch] BYREF
  char chResolveNameArg[256]; // [esp+20Ch] [ebp-13Ch] BYREF
  CUtlBuffer bufCommand; // [esp+30Ch] [ebp-3Ch] BYREF
  unsigned int bSizeUp; // [esp+33Ch] [ebp-Ch]
  int x; // [esp+340h] [ebp-8h] BYREF
  int y; // [esp+344h] [ebp-4h] BYREF

  v2 = command;
  vgui::Frame::OnCommand(this, command);
  if ( _V_stricmp(s1: command, s2: "Explore") == 0 )
  {
    m_pInfo = this->m_pInfo;
    if ( m_pInfo != nullptr )
    {
      memset(chResolveName, 0, sizeof(chResolveName));
      memset(chResolveNameArg, 0, sizeof(chResolveNameArg));
      String = KeyValues::GetString(this: m_pInfo, keyName: "Name", defaultValue: defaultValue);
      V_snprintf(pDest: chResolveNameArg, maxLen: 255, pFormat: "materials/%s.vtf", String);
      v6 = g_pFileSystem->RelativePathToFullPath(
             this: g_pFileSystem,
             a2: chResolveNameArg,
             a3: "game",
             a4: chResolveName,
             a5: 255,
             a6: 0,
             a7: 0);
      V_snprintf(pDest: params, maxLen: 255, pFormat: "/E,/SELECT,%s", v6);
      g_pVGuiSystem->ShellExecuteEx(this: g_pVGuiSystem, a2: "open", a3: "explorer.exe", a4: params);
    }
  }
  if ( _V_stricmp(s1: command, s2: "Reload") == 0 && this->m_lstMaterials.m_Size != 0 )
  {
    CUtlBuffer::CUtlBuffer(this: &bufCommand, growSize: 0, initSize: 0, nFlags: 1);
    v7 = 0;
    Cbuf_Execute();
    if ( this->m_lstMaterials.m_Size > 0 )
    {
      do
      {
        v8 = v7;
        CUtlBuffer::Printf(this: &bufCommand, pFmt: "mat_reloadmaterial \"");
        if ( v7 < this->m_lstMaterials.m_Size )
        {
          m_Put = bufCommand.m_Put;
          while ( 1 )
          {
            v10 = this->m_lstMaterials.m_Memory.m_pMemory[v7];
            x = m_Put;
            HIWORD(y) = v10;
            v11 = CUtlSymbol::String(this: (CUtlSymbol *)&y + 1);
            v12 = "*";
            if ( v7 <= v8 )
              v12 = defaultValue;
            CUtlBuffer::Printf(this: &bufCommand, pFmt: "%s%s", v12, v11);
            m_Put = bufCommand.m_Put;
            if ( bufCommand.m_Put > 508 && v7 > v8 )
              break;
            if ( ++v7 >= this->m_lstMaterials.m_Size )
              goto LABEL_16;
          }
          CUtlBuffer::SeekPut(this: &bufCommand, type: SEEK_HEAD, offset: x);
        }
LABEL_16:
        CUtlBuffer::Printf(this: &bufCommand, pFmt: "\"\n");
        if ( (bufCommand.m_Flags & 1) != 0
          && bufCommand.m_Put != 0
          && bufCommand.m_Memory.m_pMemory[bufCommand.m_Put - bufCommand.m_nOffset - 1] == 10 )
        {
          CUtlBuffer::PutTabs(this: &bufCommand);
        }
        if ( CUtlBuffer::CheckPut(this: &bufCommand, nSize: 1) )
        {
          bufCommand.m_Memory.m_pMemory[bufCommand.m_Put - bufCommand.m_nOffset] = 0;
          CUtlBuffer::AddNullTermination(this: &bufCommand, nPut: ++bufCommand.m_Put);
        }
        m_pMemory = bufCommand.m_Memory.m_pMemory;
        TraceType = CTraceFilter::GetTraceType(this: (vgui::CTreeViewListControl *)bufCommand.m_Memory.m_pMemory);
        Cbuf_AddText(eTarget: TraceType, pText: (const char *)m_pMemory, nTickDelay: 0);
        memset(&bufCommand.m_Get, 0, 9);
        bufCommand.m_nOffset = 0;
        bufCommand.m_nMaxPut = -1;
        CUtlBuffer::AddNullTermination(this: &bufCommand, nPut: 0);
        Cbuf_Execute();
      }
      while ( v7 < this->m_lstMaterials.m_Size );
      v2 = command;
    }
    if ( bufCommand.m_Memory.m_nGrowSize >= 0 && bufCommand.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufCommand.m_Memory.m_pMemory);
  }
  if ( _V_stricmp(s1: v2, s2: "CopyTxt") == 0 )
  {
    v14 = (const char *)this->m_bufInfoText.m_Memory.m_pMemory;
    if ( this->m_bufInfoText.m_Put == 0 || v14 == nullptr )
      v14 = defaultValue;
    g_pVGuiSystem->SetClipboardText_2(this: g_pVGuiSystem, a2: v14, a3: strlen(v14) + 1);
  }
  if ( _V_stricmp(s1: v2, s2: "CopyImg") == 0 )
  {
    x = 0;
    y = 0;
    vgui::Panel::LocalToScreen(this, &x, &y);
    v15 = game->GetMainWindow(this: game);
    v16 = g_pVGuiSystem;
    v17 = g_pVGuiSystem->__vftable;
    bSizeUp = (unsigned int)v15;
    vgui::Panel::GetTall(this);
    vgui::Panel::GetWide(this);
    v26 = x;
    v25 = bSizeUp;
    ((void (__thiscall *)(vgui::ISystem *))v17->SetClipboardImage)(a1: v16);
    v2 = command;
  }
  if ( _V_stricmp(s1: v2, s2: "FlashBtn") == 0 )
  {
    MatViewOverride::s_viewParamsReq.lstMaterials.m_Size = 0;
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
      this: &MatViewOverride::s_viewParamsReq.lstMaterials,
      elem: 0,
      num: this->m_lstMaterials.m_Size,
      pToInsert: this->m_lstMaterials.m_Memory.m_pMemory);
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_texture_list.IConVar, value: 0, a2: v25, a3: v26);
    s_eTxListPanelRequest = TXR_HIDE;
  }
  if ( _V_stricmp(s1: v2, s2: "size-") == 0 || _V_stricmp(s1: v2, s2: "size+") == 0 )
  {
    v18 = this->m_pInfo;
    if ( v18 != nullptr )
    {
      LOBYTE(bSizeUp) = v2[4] == 43;
      v27 = bSizeUp;
      v19 = KeyValues::GetString(this: v18, keyName: "Name", defaultValue: defaultValue);
      if ( AdjustTextureSize(szTextureName: v19, bMoveSizeUp: v27) )
      {
        v20 = g_bRecursiveRequestToShowTextureList;
        g_bRecursiveRequestToShowTextureList = true;
        mat_texture_list_on_f();
        g_bRecursiveRequestToShowTextureList = v20;
        v2 = command;
      }
      this->InvalidateLayout(this, a2: false, a3: false);
    }
  }
  if ( _V_stricmp(s1: v2, s2: "Exclude") == 0 )
  {
    v21 = this->m_pSizeControls[2]->IsSelected(this: this->m_pSizeControls[2]);
    v22 = KeyValues::GetString(this: this->m_pInfo, keyName: "Name", defaultValue: defaultValue);
    v23 = materials->FindTexture(this: materials, a2: v22, a3: defaultValue, a4: 0, a5: 0);
    if ( v23 != nullptr
      && mat_texture_list_exclude_editing.m_pParent != nullptr
      && mat_texture_list_exclude_editing.m_pParent->m_Value.m_nValue > 0 )
    {
      v23->ForceExcludeOverride(this: v23, a2: v21 - 1);
      v24 = g_bRecursiveRequestToShowTextureList;
      g_bRecursiveRequestToShowTextureList = true;
      mat_texture_list_on_f();
      g_bRecursiveRequestToShowTextureList = v24;
    }
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096F50
// Name: public: static void vgui::TileViewPanelEx::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::TileViewPanelEx::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`vgui::TileViewPanelEx::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `vgui::TileViewPanelEx::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "TileViewPanelEx");
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "ScrollBarSliderMoved";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::RichText::`vcall'{872,{flat}};
    memset(&v3.m[1][1], 0, 44);
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096FF0
// Name: public: vgui::TileViewPanelEx::TileViewPanelEx(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TileViewPanelEx *__thiscall vgui::TileViewPanelEx::TileViewPanelEx(
        vgui::TileViewPanelEx *this,
        vgui::Panel *parent,
        char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::ScrollBar *v7; // eax
  vgui::ScrollBar *v8; // eax

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::TileViewPanelEx_vtbl *)&vgui::TileViewPanelEx::`vftable';
  if ( `vgui::TileViewPanelEx::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::TileViewPanelEx::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "TileViewPanelEx");
    v4->pfnClassName = vgui::TileViewPanelEx::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::TileViewPanelEx::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::TileViewPanelEx::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "TileViewPanelEx");
    v5->pfnClassName = vgui::TileViewPanelEx::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::TileViewPanelEx::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::TileViewPanelEx::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "TileViewPanelEx");
    v6->pfnClassName = vgui::TileViewPanelEx::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::TileViewPanelEx::PanelMessageFunc_OnSliderMoved::InitVar();
  this->m_hbar = nullptr;
  this->m_hFont = 0;
  v7 = (vgui::ScrollBar *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v7 != nullptr )
    v8 = vgui::ScrollBar::ScrollBar(this: v7, parent: this, panelName: "VerticalScrollBar", vertical: true);
  else
    v8 = nullptr;
  this->m_hbar = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  this->m_hbar->SetVisible(this: this->m_hbar, a2: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10097110
// Name: public: static void CVmtTextEntry::PanelMessageFunc_OpenVmtSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVmtTextEntry::PanelMessageFunc_OpenVmtSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CVmtTextEntry::PanelMessageFunc_OpenVmtSelected::InitVar'::`2'::bAdded )
  {
    `CVmtTextEntry::PanelMessageFunc_OpenVmtSelected::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CVmtTextEntry");
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "DoOpenVmtSelected";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset(&v3.m[1][1], 0, 44);
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100971A0
// Name: public: static void CTextureListPanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CTextureListPanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CTextureListPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CTextureListPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CTextureListPanel");
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "TextChanged";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::BuildModeDialog::`vcall'{1120,{flat}};
    memset(&v3.m[1][1], 0, 44);
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10097300
// Name: public: CAutoMatSysDebugMode::~CAutoMatSysDebugMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAutoMatSysDebugMode::~CAutoMatSysDebugMode(CAutoMatSysDebugMode *this)
{
  unsigned int i; // edi
  IMaterialVar *m_Data; // ecx

  g_pMaterialSystem->Flush(this: g_pMaterialSystem, a2: false);
  ((void (__stdcall *)(bool))g_pMaterialSystemDebugTextureInfo->SetDebugTextureRendering)(a1: this->bOldDebugMode);
  for ( i = 0; i < this->arrCleanupVars.m_NumElements; ++i )
  {
    m_Data = this->arrCleanupVars.m_Elements.m_pMemory[(unsigned __int16)i].m_Data;
    m_Data->SetUndefined(this: m_Data);
  }
  CUtlRBTree<IMaterialVar *,unsigned short,bool (__cdecl *)(IMaterialVar * const &,IMaterialVar * const &),CUtlMemory<UtlRBTreeNode_t<IMaterialVar *,unsigned short>,unsigned short>>::RemoveAll(this: &this->arrCleanupVars);
  this->arrCleanupVars.m_FirstFree = -1;
  if ( this->arrCleanupVars.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->arrCleanupVars.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->arrCleanupVars.m_Elements.m_pMemory);
      this->arrCleanupVars.m_Elements.m_pMemory = nullptr;
    }
    this->arrCleanupVars.m_Elements.m_nAllocationCount = 0;
  }
  this->arrCleanupVars.m_LastAlloc.index = -1;
  if ( this->arrCleanupVars.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->arrCleanupVars.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->arrCleanupVars.m_Elements.m_pMemory);
      this->arrCleanupVars.m_Elements.m_pMemory = nullptr;
    }
    this->arrCleanupVars.m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100973C0
// Name: RenderTexturedRect
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderTexturedRect(
        vgui::Panel *pPanel@<ecx>,
        int yoff@<eax>,
        IMaterial *pMaterial,
        int x,
        int y,
        int x1,
        int y1,
        int xoff)
{
  void (__thiscall *Flush)(IMaterialSystem *, bool); // eax
  int Tall; // eax
  int v12; // ecx
  IMatRenderContext *v13; // eax
  IMatRenderContext *v14; // edi
  IMesh *v15; // esi
  float *m_pCurrPosition; // eax
  float v17; // xmm0_4
  float *v18; // eax
  float *v19; // eax
  __m128i v20; // xmm0
  float *v21; // eax
  float *v22; // eax
  float *v23; // eax
  float *v24; // eax
  float *v25; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-20Ch] BYREF
  CAutoMatSysDebugMode auto_matsysdebugmode; // [esp+1F4h] [ebp-24h] BYREF
  float fHeightUV; // [esp+214h] [ebp-4h]

  Flush = g_pMaterialSystem->Flush;
  auto_matsysdebugmode.arrCleanupVars.m_LessFunc = (bool (__cdecl *)(IMaterialVar *const *, IMaterialVar *const *))CDmxSerializationDictionary::LessFunc;
  memset(&auto_matsysdebugmode.arrCleanupVars.m_Elements, 0, sizeof(auto_matsysdebugmode.arrCleanupVars.m_Elements));
  *(_DWORD *)&auto_matsysdebugmode.arrCleanupVars.m_Root = 0xFFFF;
  *(_DWORD *)&auto_matsysdebugmode.arrCleanupVars.m_FirstFree = -1;
  auto_matsysdebugmode.arrCleanupVars.m_pElements = nullptr;
  Flush(this: g_pMaterialSystem, a2: false);
  auto_matsysdebugmode.bOldDebugMode = g_pMaterialSystemDebugTextureInfo->SetDebugTextureRendering(
                                         this: g_pMaterialSystemDebugTextureInfo,
                                         a2: true);
  Tall = vgui::Panel::GetTall(this: pPanel);
  v12 = y1;
  fHeightUV = 1.0;
  if ( y1 > Tall )
  {
    v12 = Tall;
    fHeightUV = (float)(Tall - y) / (float)(y1 - y);
    y1 = Tall;
  }
  if ( v12 > y )
  {
    vgui::Panel::LocalToScreen(this: pPanel, &x, &y);
    vgui::Panel::LocalToScreen(this: pPanel, x: &x1, y: &y1);
    x += xoff;
    x1 += xoff;
    y += yoff;
    y1 += yoff;
    v13 = materials->GetRenderContext(this: materials);
    v14 = v13;
    if ( v13 != nullptr )
      v13->BeginRender(this: v13);
    v14->Bind(this: v14, a2: pMaterial, a3: nullptr);
    v15 = v14->GetDynamicMesh(this: v14, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v15;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_QUADS;
    v15->SetPrimitiveType(this: v15, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v15->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v15, nMaxVertexCount: 4, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v17 = (float)y;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)x;
    m_pCurrPosition[1] = v17;
    m_pCurrPosition[2] = 0.0;
    v18 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v18[1] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v19 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v20 = _mm_cvtsi32_si128(y);
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)x1;
    v19[1] = _mm_cvtepi32_ps(v20).m128_f32[0];
    v19[2] = 0.0;
    v21 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
    v21[1] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v22 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *(float *)v20.m128i_i32 = (float)y1;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)x1;
    v22[1] = *(float *)v20.m128i_i32;
    v22[2] = 0.0;
    v23 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
    v23[1] = fHeightUV;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v24 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *(float *)v20.m128i_i32 = (float)y1;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)x;
    v24[1] = *(float *)v20.m128i_i32;
    v24[2] = 0.0;
    v25 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v25[1] = fHeightUV;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v15->Draw_2(this: v15, a2: -1, a3: 0);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    v14->EndRender(this: v14);
    v14->Release(this: v14);
  }
  CAutoMatSysDebugMode::~CAutoMatSysDebugMode(this: &auto_matsysdebugmode);
}

//------------------------------------------------------------------------------
// Address: 0x10097780
// Name: public: CVmtTextEntry::CVmtTextEntry(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVmtTextEntry *__thiscall CVmtTextEntry::CVmtTextEntry(CVmtTextEntry *this, vgui::Panel *parent, const char *szName)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi

  vgui::TextEntry::TextEntry(this, parent, panelName: szName);
  this->__vftable = (CVmtTextEntry_vtbl *)&CVmtTextEntry::`vftable';
  if ( `CVmtTextEntry::ChainToMap'::`2'::chained == 0 )
  {
    `CVmtTextEntry::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CVmtTextEntry");
    v4->pfnClassName = CVmtTextEntry::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::TextEntry");
  }
  if ( `CVmtTextEntry::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CVmtTextEntry::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CVmtTextEntry");
    v5->pfnClassName = CVmtTextEntry::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::TextEntry");
  }
  if ( `CVmtTextEntry::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CVmtTextEntry::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CVmtTextEntry");
    v6->pfnClassName = CVmtTextEntry::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::TextEntry");
  }
  CVmtTextEntry::PanelMessageFunc_OpenVmtSelected::InitVar();
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10097850
// Name: public: virtual int vgui::TextEntry::GetTextCursorPos(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextEntry::GetTextCursorPos(vgui::TreeView *this)
{
  return this->m_Font;
}

//------------------------------------------------------------------------------
// Address: 0x10097860
// Name: public: virtual void vgui::TextEntry::SetAutoLocalize(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextEntry::SetAutoLocalize(vgui::TextEntry *this, bool bState)
{
  this->m_bAutoLocalize = bState;
}

//------------------------------------------------------------------------------
// Address: 0x10097870
// Name: public: virtual struct vgui::PanelMessageMap __near * CVmtTextEntry::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVmtTextEntry::GetMessageMap(CVmtTextEntry *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVmtTextEntry::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVmtTextEntry::GetMessageMap'::`2'::s_pMap;
  `CVmtTextEntry::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVmtTextEntry");
  `CVmtTextEntry::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100978A0
// Name: public: virtual struct PanelAnimationMap __near * CVmtTextEntry::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVmtTextEntry::GetAnimMap(CVmtTextEntry *this)
{
  return FindOrAddPanelAnimationMap(className: "CVmtTextEntry");
}

//------------------------------------------------------------------------------
// Address: 0x100978B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVmtTextEntry::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVmtTextEntry::GetKBMap(CVmtTextEntry *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVmtTextEntry::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVmtTextEntry::GetKBMap'::`2'::s_pMap;
  `CVmtTextEntry::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVmtTextEntry");
  `CVmtTextEntry::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100978E0
// Name: public: CRenderTextureEditor::CRenderTextureEditor(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CRenderTextureEditor *__thiscall CRenderTextureEditor::CRenderTextureEditor(
        CRenderTextureEditor *this,
        vgui::Panel *parent,
        const char *szName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CVmtTextEntry *v7; // eax
  CVmtTextEntry *v8; // edi
  vgui::Button *v9; // eax
  vgui::Button *v10; // edi
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::Button *v13; // eax
  vgui::Button *v14; // edi
  vgui::Button *v15; // eax
  vgui::Button *v16; // edi
  vgui::Button *v17; // eax
  vgui::Button *v18; // edi
  vgui::Button *v19; // eax
  vgui::Button *v20; // edi
  vgui::Button *v21; // eax
  vgui::Button *v22; // edi
  vgui::CheckButton *v23; // eax
  vgui::CheckButton *v24; // edi

  vgui::Frame::Frame(this, parent, panelName: szName, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CRenderTextureEditor_vtbl *)&CRenderTextureEditor::`vftable';
  if ( `CRenderTextureEditor::ChainToMap'::`2'::chained == 0 )
  {
    `CRenderTextureEditor::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CRenderTextureEditor");
    v4->pfnClassName = CRenderTextureEditor::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CRenderTextureEditor::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CRenderTextureEditor::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CRenderTextureEditor");
    v5->pfnClassName = CRenderTextureEditor::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CRenderTextureEditor::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CRenderTextureEditor::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CRenderTextureEditor");
    v6->pfnClassName = CRenderTextureEditor::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  this->m_hFont = 0;
  this->m_pInfo = nullptr;
  CUtlBuffer::CUtlBuffer(this: &this->m_bufInfoText, growSize: 0, initSize: 0, nFlags: 1);
  this->m_lstMaterials.m_Memory.m_pMemory = nullptr;
  this->m_lstMaterials.m_Memory.m_nAllocationCount = 0;
  this->m_lstMaterials.m_Memory.m_nGrowSize = 0;
  this->m_lstMaterials.m_Size = 0;
  this->m_lstMaterials.m_pElements = nullptr;
  this->m_iInfoHint = 0;
  v7 = (CVmtTextEntry *)MemAlloc_Alloc(nSize: 0x440u);
  if ( v7 != nullptr )
    v8 = CVmtTextEntry::CVmtTextEntry(this: v7, parent: this, szName: "Materials");
  else
    v8 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v8);
  this->m_pMaterials = v8;
  v8->SetMultiline(this: v8, a2: true);
  this->m_pMaterials->SetEditable(this: this->m_pMaterials, a2: false);
  this->m_pMaterials->SetEnabled(this: this->m_pMaterials, a2: false);
  this->m_pMaterials->SetVerticalScrollbar(this: this->m_pMaterials, a2: true);
  this->m_pMaterials->SetVisible(this: this->m_pMaterials, a2: true);
  v9 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "Explore",
            text: "Open",
            pActionSignalTarget: this,
            pCmd: "Explore");
  else
    v10 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v10);
  this->m_pExplore = v10;
  v10->SetVisible(this: v10, a2: true);
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "Reload",
            text: "Reload",
            pActionSignalTarget: this,
            pCmd: "Reload");
  else
    v12 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v12);
  this->m_pReload = v12;
  v12->SetVisible(this: v12, a2: true);
  v13 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v13 != nullptr )
    v14 = vgui::Button::Button(
            this: v13,
            parent: this,
            panelName: "CopyTxt",
            text: "Copy Text",
            pActionSignalTarget: this,
            pCmd: "CopyTxt");
  else
    v14 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v14);
  this->m_pCopyTxt = v14;
  v14->SetVisible(this: v14, a2: true);
  v15 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v15 != nullptr )
    v16 = vgui::Button::Button(
            this: v15,
            parent: this,
            panelName: "CopyImg",
            text: "Copy Image",
            pActionSignalTarget: this,
            pCmd: "CopyImg");
  else
    v16 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v16);
  this->m_pCopyImg = v16;
  v16->SetVisible(this: v16, a2: true);
  v17 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v17 != nullptr )
    v18 = vgui::Button::Button(
            this: v17,
            parent: this,
            panelName: "FlashBtn",
            text: "Flash in Game",
            pActionSignalTarget: this,
            pCmd: "FlashBtn");
  else
    v18 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v18);
  this->m_pFlashBtn = v18;
  v18->SetVisible(this: v18, a2: true);
  v19 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v19 != nullptr )
    v20 = vgui::Button::Button(
            this: v19,
            parent: this,
            panelName: "--",
            text: "--",
            pActionSignalTarget: this,
            pCmd: "size-");
  else
    v20 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v20);
  this->m_pSizeControls[0] = v20;
  v21 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v21 != nullptr )
    v22 = vgui::Button::Button(
            this: v21,
            parent: this,
            panelName: "+",
            text: "+",
            pActionSignalTarget: this,
            pCmd: "size+");
  else
    v22 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v22);
  this->m_pSizeControls[1] = v22;
  v23 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v23 != nullptr )
    v24 = vgui::CheckButton::CheckButton(this: v23, parent: this, panelName: "Exclude", text: "Exclude");
  else
    v24 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v24);
  this->m_pSizeControls[2] = v24;
  v24->AddActionSignalTarget_2(this: v24, a2: this);
  this->m_pSizeControls[2]->SetCommand(this: this->m_pSizeControls[2], a2: "Exclude");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10097CB0
// Name: public: virtual void CRenderTextureEditor::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRenderTextureEditor::SetFont(CRenderTextureEditor *this, unsigned int hFont)
{
  CRenderTextureEditor_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_hFont = hFont;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x10097CD0
// Name: public: virtual struct vgui::PanelMessageMap __near * CRenderTextureEditor::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CRenderTextureEditor::GetMessageMap(CRenderTextureEditor *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CRenderTextureEditor::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CRenderTextureEditor::GetMessageMap'::`2'::s_pMap;
  `CRenderTextureEditor::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CRenderTextureEditor");
  `CRenderTextureEditor::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10097D00
// Name: public: virtual struct PanelAnimationMap __near * CRenderTextureEditor::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CRenderTextureEditor::GetAnimMap(CRenderTextureEditor *this)
{
  return FindOrAddPanelAnimationMap(className: "CRenderTextureEditor");
}

//------------------------------------------------------------------------------
// Address: 0x10097D10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CRenderTextureEditor::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CRenderTextureEditor::GetKBMap(CRenderTextureEditor *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CRenderTextureEditor::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CRenderTextureEditor::GetKBMap'::`2'::s_pMap;
  `CRenderTextureEditor::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CRenderTextureEditor");
  `CRenderTextureEditor::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10097D40
// Name: public: CRenderTexturesListViewPanel::CRenderTexturesListViewPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CRenderTexturesListViewPanel *__thiscall CRenderTexturesListViewPanel::CRenderTexturesListViewPanel(
        CRenderTexturesListViewPanel *this,
        vgui::Panel *parent,
        const char *szName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CRenderTextureEditor *v7; // eax
  CRenderTextureEditor *v8; // eax

  vgui::TileViewPanelEx::TileViewPanelEx(this, parent, panelName: szName);
  this->__vftable = (CRenderTexturesListViewPanel_vtbl *)&CRenderTexturesListViewPanel::`vftable';
  if ( `CRenderTexturesListViewPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CRenderTexturesListViewPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CRenderTexturesListViewPanel");
    v4->pfnClassName = CRenderTexturesListViewPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::TileViewPanelEx");
  }
  if ( `CRenderTexturesListViewPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CRenderTexturesListViewPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CRenderTexturesListViewPanel");
    v5->pfnClassName = CRenderTexturesListViewPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::TileViewPanelEx");
  }
  if ( `CRenderTexturesListViewPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CRenderTexturesListViewPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CRenderTexturesListViewPanel");
    v6->pfnClassName = CRenderTexturesListViewPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::TileViewPanelEx");
  }
  this->m_pListPanel = nullptr;
  this->m_bPaintAlpha = false;
  v7 = (CRenderTextureEditor *)MemAlloc_Alloc(nSize: 0x288u);
  if ( v7 != nullptr )
    v8 = CRenderTextureEditor::CRenderTextureEditor(this: v7, parent: this, szName: "TxEdt");
  else
    v8 = nullptr;
  this->m_pRenderTxEditor = v8;
  vgui::Panel::SetPos(this: v8, x: 10, y: 10);
  this->m_pRenderTxEditor->PerformLayout(this: this->m_pRenderTxEditor);
  this->m_pRenderTxEditor->SetMoveable(this: this->m_pRenderTxEditor, a2: true);
  this->m_pRenderTxEditor->SetSizeable(this: this->m_pRenderTxEditor, a2: false);
  this->m_pRenderTxEditor->SetClipToParent(this: this->m_pRenderTxEditor, a2: true);
  this->m_pRenderTxEditor->SetTitle_2(this: this->m_pRenderTxEditor, a2: defaultValue, a3: true);
  this->m_pRenderTxEditor->SetCloseButtonVisible(this: this->m_pRenderTxEditor, a2: false);
  this->m_pRenderTxEditor->SetVisible(this: this->m_pRenderTxEditor, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10097ED0
// Name: public: virtual struct vgui::PanelMessageMap __near * CRenderTexturesListViewPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CRenderTexturesListViewPanel::GetMessageMap(CRenderTexturesListViewPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CRenderTexturesListViewPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CRenderTexturesListViewPanel::GetMessageMap'::`2'::s_pMap;
  `CRenderTexturesListViewPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CRenderTexturesListViewPanel");
  `CRenderTexturesListViewPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10097F00
// Name: public: virtual struct PanelAnimationMap __near * CRenderTexturesListViewPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CRenderTexturesListViewPanel::GetAnimMap(CRenderTexturesListViewPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CRenderTexturesListViewPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10097F10
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CRenderTexturesListViewPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CRenderTexturesListViewPanel::GetKBMap(CRenderTexturesListViewPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CRenderTexturesListViewPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CRenderTexturesListViewPanel::GetKBMap'::`2'::s_pMap;
  `CRenderTexturesListViewPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CRenderTexturesListViewPanel");
  `CRenderTexturesListViewPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10097F40
// Name: public: CTextureListPanel::CTextureListPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CTextureListPanel *__thiscall CTextureListPanel::CTextureListPanel(CTextureListPanel *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  int v6; // eax
  vgui::Label *v7; // eax
  vgui::Label *v8; // edi
  vgui::Label *v9; // eax
  vgui::Label *v10; // edi
  vgui::CheckButton *v11; // eax
  vgui::CheckButton *v12; // edi
  vgui::CheckButton *v13; // eax
  vgui::CheckButton *v14; // edi
  CConVarCheckButton *v15; // eax
  CConVarCheckButton *v16; // edi
  CConVarCheckButton *v17; // eax
  CConVarCheckButton *v18; // edi
  CConVarCheckButton *v19; // eax
  CConVarCheckButton *v20; // edi
  vgui::Button *v21; // eax
  vgui::Button *v22; // edi
  vgui::ToggleButton *v23; // eax
  vgui::ToggleButton *v24; // edi
  vgui::CheckButton *v25; // eax
  vgui::CheckButton *v26; // edi
  vgui::CheckButton *v27; // eax
  vgui::CheckButton *v28; // edi
  vgui::CheckButton *v29; // eax
  vgui::CheckButton *v30; // edi
  vgui::TextEntry *v31; // eax
  vgui::TextEntry *v32; // edi
  vgui::ListPanel *v33; // eax
  vgui::ListPanel *v34; // edi
  int m_nValue; // eax
  CRenderTexturesListViewPanel *v36; // eax
  CRenderTexturesListViewPanel *v37; // edi
  int v38; // eax
  CRenderTexturesListViewPanel *m_pViewPanel; // ecx
  void (*Repaint)(void); // eax
  CRenderTexturesListViewPanel *v41; // ecx
  CRenderTexturesListViewPanel_vtbl *v42; // eax
  int v44; // [esp+0h] [ebp-10h]

  vgui::Frame::Frame(this, parent, panelName: "CTextureListPanel", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CTextureListPanel_vtbl *)&CTextureListPanel::`vftable';
  if ( `CTextureListPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CTextureListPanel::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CTextureListPanel");
    v3->pfnClassName = CTextureListPanel::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CTextureListPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CTextureListPanel::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CTextureListPanel");
    v4->pfnClassName = CTextureListPanel::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CTextureListPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CTextureListPanel::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CTextureListPanel");
    v5->pfnClassName = CTextureListPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CTextureListPanel::PanelMessageFunc_OnTextChanged::InitVar();
  this->m_numDisplayedSizeKB = 0;
  v44 = videomode->GetModeHeight(this: videomode) - 20;
  v6 = videomode->GetModeWidth(this: videomode);
  vgui::Panel::SetSize(this, wide: v6 - 20, tall: v44);
  vgui::Panel::SetPos(this, x: 10, y: 10);
  vgui::Panel::SetVisible(this, state: 1);
  vgui::Panel::SetCursor(this, cursor: 0);
  vgui::Frame::SetTitle(this, title: "Texture list", surfaceTitle: false);
  vgui::Frame::SetMenuButtonVisible(this, state: false);
  this->m_hFont = 0;
  CBaseDemoAction::SetTimingType(this, color: (Color)-16777216);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: true);
  v7 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v7 != nullptr )
    v8 = vgui::Label::Label(
           this: v7,
           parent: this,
           panelName: "m_pCVarListLabel",
           text: "cvars: mat_texture_limit, mat_texture_list, mat_picmip, mat_texture_list_txlod, mat_texture_list_txlod_sync");
  else
    v8 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v8);
  this->m_pCVarListLabel = v8;
  v8->SetVisible(this: v8, a2: false);
  v9 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v9 != nullptr )
    v10 = vgui::Label::Label(this: v9, parent: this, panelName: "m_pTotalUsageLabel", text: defaultValue);
  else
    v10 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v10);
  this->m_pTotalUsageLabel = v10;
  v10->SetVisible(this: v10, a2: true);
  v11 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v11 != nullptr )
    v12 = vgui::CheckButton::CheckButton(
            this: v11,
            parent: this,
            panelName: "service",
            text: "Render Targets and Special Textures");
  else
    v12 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v12);
  this->m_pSpecialTexs = v12;
  v12->SetVisible(this: v12, a2: true);
  this->m_pSpecialTexs->AddActionSignalTarget_2(this: this->m_pSpecialTexs, a2: this);
  this->m_pSpecialTexs->SetCommand(this: this->m_pSpecialTexs, a2: "service");
  v13 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v13 != nullptr )
    v14 = vgui::CheckButton::CheckButton(
            this: v13,
            parent: this,
            panelName: "resolvepath",
            text: "Resolve Full Texture Path");
  else
    v14 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v14);
  this->m_pResolveTexturePath = v14;
  v14->SetVisible(this: v14, a2: true);
  this->m_pResolveTexturePath->AddActionSignalTarget_2(this: this->m_pResolveTexturePath, a2: this);
  this->m_pResolveTexturePath->SetCommand(this: this->m_pResolveTexturePath, a2: "resolvepath");
  v15 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v15 != nullptr )
    v16 = CConVarCheckButton::CConVarCheckButton(
            this: v15,
            parent: this,
            panelName: "m_pShowTextureMemoryUsageOption",
            text: "Show Memory Usage on HUD");
  else
    v16 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v16);
  this->m_pShowTextureMemoryUsageOption = v16;
  v16->SetVisible(this: v16, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pShowTextureMemoryUsageOption, pVar: &mat_show_texture_memory_usage);
  v17 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v17 != nullptr )
    v18 = CConVarCheckButton::CConVarCheckButton(
            this: v17,
            parent: this,
            panelName: "m_pAllTextures",
            text: "Show ALL textures");
  else
    v18 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v18);
  this->m_pAllTextures = v18;
  v18->SetVisible(this: v18, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pAllTextures, pVar: &mat_texture_list_all);
  this->m_pAllTextures->AddActionSignalTarget_2(this: this->m_pAllTextures, a2: this);
  this->m_pAllTextures->SetCommand(this: this->m_pAllTextures, a2: "AllTextures");
  v19 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v19 != nullptr )
    v20 = CConVarCheckButton::CConVarCheckButton(
            this: v19,
            parent: this,
            panelName: "m_pViewTextures",
            text: "View textures thumbnails");
  else
    v20 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v20);
  this->m_pViewTextures = v20;
  v20->SetVisible(this: v20, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pViewTextures, pVar: &mat_texture_list_view);
  this->m_pViewTextures->AddActionSignalTarget_2(this: this->m_pViewTextures, a2: this);
  this->m_pViewTextures->SetCommand(this: this->m_pViewTextures, a2: "ViewThumbnails");
  v21 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v21 != nullptr )
    v22 = vgui::Button::Button(
            this: v21,
            parent: this,
            panelName: "CopyToClipboard",
            text: "Copy to Clipboard",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v22 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v22);
  this->m_pCopyToClipboardButton = v22;
  if ( v22 != nullptr )
  {
    v22->AddActionSignalTarget_2(this: v22, a2: this);
    this->m_pCopyToClipboardButton->SetCommand(this: this->m_pCopyToClipboardButton, a2: "CopyToClipboard");
  }
  v23 = (vgui::ToggleButton *)MemAlloc_Alloc(nSize: 0x1FCu);
  if ( v23 != nullptr )
    v24 = vgui::ToggleButton::ToggleButton(this: v23, parent: this, panelName: "Collapse", text: " ");
  else
    v24 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v24);
  this->m_pCollapse = v24;
  v24->AddActionSignalTarget_2(this: v24, a2: this);
  this->m_pCollapse->SetCommand(this: this->m_pCollapse, a2: "Collapse");
  this->m_pCollapse->SetSelected(this: this->m_pCollapse, a2: true);
  v25 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v25 != nullptr )
    v26 = vgui::CheckButton::CheckButton(this: v25, parent: this, panelName: "ShowAlpha", text: "Alpha");
  else
    v26 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v26);
  this->m_pAlpha = v26;
  v26->AddActionSignalTarget_2(this: v26, a2: this);
  this->m_pAlpha->SetCommand(this: this->m_pAlpha, a2: "ShowAlpha");
  this->m_pAlpha->SetSelected(this: this->m_pAlpha, a2: true);
  v27 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v27 != nullptr )
    v28 = vgui::CheckButton::CheckButton(this: v27, parent: this, panelName: "ThumbWarnings", text: "Warns");
  else
    v28 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v28);
  this->m_pThumbWarnings = v28;
  v28->AddActionSignalTarget_2(this: v28, a2: this);
  this->m_pThumbWarnings->SetCommand(this: this->m_pThumbWarnings, a2: "ThumbWarnings");
  this->m_pThumbWarnings->SetSelected(this: this->m_pThumbWarnings, a2: g_warn_enable);
  v29 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v29 != nullptr )
    v30 = vgui::CheckButton::CheckButton(this: v29, parent: this, panelName: "FilteringChk", text: "Filter: ");
  else
    v30 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v30);
  this->m_pFilteringChk = v30;
  v30->AddActionSignalTarget_2(this: v30, a2: this);
  this->m_pFilteringChk->SetCommand(this: this->m_pFilteringChk, a2: "FilteringChk");
  this->m_pFilteringChk->SetSelected(this: this->m_pFilteringChk, a2: true);
  v31 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v31 != nullptr )
    v32 = vgui::TextEntry::TextEntry(this: v31, parent: this, panelName: "FilteringTxt");
  else
    v32 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v32);
  this->m_pFilteringText = v32;
  v32->AddActionSignalTarget_2(this: v32, a2: this);
  v33 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v33 != nullptr )
    v34 = vgui::ListPanel::ListPanel(this: v33, parent: this, panelName: "List Panel");
  else
    v34 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v34);
  this->m_pListPanel = v34;
  if ( mat_texture_list_view.m_pParent != nullptr )
    m_nValue = mat_texture_list_view.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v34->SetVisible(this: v34, a2: m_nValue == 0);
  this->m_pListPanel->AddColumnHeader_2(
    this: this->m_pListPanel,
    a2: 0,
    a3: "Name",
    a4: "Texture Name",
    a5: 200,
    a6: 100,
    a7: 700,
    a8: 2);
  this->m_pListPanel->AddColumnHeader_2(
    this: this->m_pListPanel,
    a2: 1,
    a3: "Path",
    a4: "Path",
    a5: 50,
    a6: 50,
    a7: 300,
    a8: 0);
  this->m_pListPanel->AddColumnHeader_2(
    this: this->m_pListPanel,
    a2: 2,
    a3: "Size",
    a4: "Kilobytes",
    a5: 50,
    a6: 50,
    a7: 50,
    a8: 0);
  this->m_pListPanel->SetSortFunc(this: this->m_pListPanel, a2: 2, a3: KilobytesSortFunc);
  this->m_pListPanel->SetSortColumnEx(this: this->m_pListPanel, a2: 2, a3: 0, a4: true);
  this->m_pListPanel->AddColumnHeader_2(
    this: this->m_pListPanel,
    a2: 3,
    a3: "TexGroup",
    a4: "Group",
    a5: 100,
    a6: 100,
    a7: 300,
    a8: 0);
  this->m_pListPanel->AddColumnHeader_2(
    this: this->m_pListPanel,
    a2: 4,
    a3: "Format",
    a4: "Format",
    a5: 250,
    a6: 50,
    a7: 300,
    a8: 0);
  this->m_pListPanel->AddColumnHeader_2(
    this: this->m_pListPanel,
    a2: 5,
    a3: "Width",
    a4: "Width",
    a5: 50,
    a6: 50,
    a7: 50,
    a8: 0);
  this->m_pListPanel->AddColumnHeader_2(
    this: this->m_pListPanel,
    a2: 6,
    a3: "Height",
    a4: "Height",
    a5: 50,
    a6: 50,
    a7: 50,
    a8: 0);
  this->m_pListPanel->AddColumnHeader_2(
    this: this->m_pListPanel,
    a2: 7,
    a3: "BindsFrame",
    a4: "# Binds",
    a5: 50,
    a6: 50,
    a7: 50,
    a8: 0);
  this->m_pListPanel->AddColumnHeader_2(
    this: this->m_pListPanel,
    a2: 8,
    a3: "BindsMax",
    a4: "BindsMax",
    a5: 50,
    a6: 50,
    a7: 50,
    a8: 0);
  CBaseDemoAction::SetStartTick(this, color: (Color)1677721600);
  ((void (__thiscall *)(vgui::ListPanel *, int))this->m_pListPanel->SetBgColor)(a1: this->m_pListPanel, a2: 1677721600);
  v36 = (CRenderTexturesListViewPanel *)MemAlloc_Alloc(nSize: 0x194u);
  if ( v36 != nullptr )
    v37 = CRenderTexturesListViewPanel::CRenderTexturesListViewPanel(this: v36, parent: this, szName: "View Panel");
  else
    v37 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v37);
  this->m_pViewPanel = v37;
  if ( mat_texture_list_view.m_pParent != nullptr )
    v38 = mat_texture_list_view.m_pParent->m_Value.m_nValue;
  else
    v38 = 0;
  v37->SetVisible(this: v37, a2: v38 != 0);
  ((void (__thiscall *)(CRenderTexturesListViewPanel *, int))this->m_pViewPanel->SetBgColor)(
    a1: this->m_pViewPanel,
    a2: -16777216);
  this->m_pViewPanel->SetDragEnabled(this: this->m_pViewPanel, a2: false);
  ((void (__stdcall *)(_DWORD, _DWORD))this->m_pViewPanel->SetDropEnabled)(a1: 0, a2: 0.0);
  m_pViewPanel = this->m_pViewPanel;
  Repaint = (void (*)(void))m_pViewPanel->Repaint;
  m_pViewPanel->m_bPaintAlpha = true;
  Repaint();
  v41 = this->m_pViewPanel;
  v42 = v41->__vftable;
  v41->m_pListPanel = this->m_pListPanel;
  ((void (__stdcall *)(_DWORD, _DWORD))v42->InvalidateLayout)(a1: 0, a2: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10098840
// Name: void CL_CreateTextureListPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_CreateTextureListPanel(vgui::Panel *parent)
{
  CTextureListPanel *v1; // eax

  v1 = (CTextureListPanel *)MemAlloc_Alloc(nSize: 0x258u);
  if ( v1 != nullptr )
    g_pTextureListPanel = CTextureListPanel::CTextureListPanel(this: v1, parent);
  else
    g_pTextureListPanel = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10098AA0
// Name: UseDebugMaterial
// Source: json
//------------------------------------------------------------------------------
IMaterial *__usercall UseDebugMaterial@<eax>(
        const char *szMaterial@<eax>,
        int a2@<edi>,
        int a3@<esi>,
        ITexture *pMatTexture,
        CAutoMatSysDebugMode *pRestoreVars)
{
  ITexture *v5; // ebx
  IMaterial *result; // eax
  IMaterial *v7; // esi
  IMaterialVar *v8; // eax
  IMaterialVar *v9; // edi
  IMaterialVar *v10; // eax
  int v11; // ebx
  int v12; // edx
  IMaterialVar *FrameVar; // [esp+4h] [ebp-8h] BYREF
  bool foundVar; // [esp+Bh] [ebp-1h] BYREF

  if ( szMaterial == nullptr )
    return nullptr;
  v5 = pMatTexture;
  if ( pMatTexture == nullptr )
    return nullptr;
  result = materials->FindMaterial(this: materials, a2: szMaterial, a3: "Other textures", a4: 0, a5: 0);
  v7 = result;
  if ( result != nullptr )
  {
    v8 = result->FindVar(this: result, a2: "$basetexture", a3: &foundVar, a4: 0);
    v9 = v8;
    if ( foundVar && v8 != nullptr )
    {
      v10 = (IMaterialVar *)((int (__thiscall *)(IMaterial *, const char *, bool *, _DWORD, int))v7->FindVar)(
                              a1: v7,
                              a2: "$frame",
                              a3: &foundVar,
                              a4: 0,
                              a5: a2);
      FrameVar = v10;
      if ( foundVar && v10 != nullptr )
      {
        v11 = ((int (__thiscall *)(ITexture *, int))pMatTexture->GetNumAnimationFrames)(a1: pMatTexture, a2: a3);
        if ( pMatTexture->IsRenderTarget(this: pMatTexture) || pMatTexture->IsProcedural(this: pMatTexture) || v11 <= 0 )
          v12 = 0;
        else
          v12 = g_ClientGlobalVariables.tickcount % v11;
        FrameVar->SetIntValue(this: FrameVar, a2: v12);
        v5 = pMatTexture;
      }
      v9->SetTextureValue(this: v9, a2: v5);
      if ( pRestoreVars != nullptr )
      {
        FrameVar = v9;
        CUtlRBTree<IMaterialVar *,unsigned short,bool (__cdecl *)(IMaterialVar * const &,IMaterialVar * const &),CUtlMemory<UtlRBTreeNode_t<IMaterialVar *,unsigned short>,unsigned short>>::InsertIfNotFound(
          this: &pRestoreVars->arrCleanupVars,
          insert: &FrameVar);
      }
      return v7;
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10098BB0
// Name: public: virtual void CVmtTextEntry::OpenVmtSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVmtTextEntry::OpenVmtSelected(CVmtTextEntry *this)
{
  bool (__thiscall *GetSelectedRange)(vgui::TextEntry *, int *, int *); // eax
  int v2; // ecx
  char *m_pMemory; // ebx
  int v4; // esi
  int m_Size; // eax
  unsigned __int8 *v6; // edi
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // esi
  const char *v9; // eax
  char chResolveName[256]; // [esp+0h] [ebp-220h] BYREF
  char chResolveNameArg[256]; // [esp+100h] [ebp-120h] BYREF
  CUtlVector<char,CUtlMemory<char,int> > buf; // [esp+200h] [ebp-20h] BYREF
  CVmtTextEntry *v13; // [esp+214h] [ebp-Ch]
  int x0; // [esp+218h] [ebp-8h] BYREF
  int x1; // [esp+21Ch] [ebp-4h] BYREF

  GetSelectedRange = this->GetSelectedRange;
  v13 = this;
  if ( ((unsigned __int8 (__stdcall *)(int *, int *))GetSelectedRange)(a1: &x0, a2: &x1) != 0 )
  {
    v2 = x1;
    m_pMemory = nullptr;
    v4 = x1 - x0 + 1;
    m_Size = 0;
    memset(&buf, 0, sizeof(buf));
    if ( x1 - x0 != -1 )
    {
      if ( v4 > 0 )
      {
        CUtlMemory<bool,int>::Grow(this: &buf.m_Memory, num: x1 - x0 + 1);
        v2 = x1;
        m_Size = buf.m_Size;
        m_pMemory = buf.m_Memory.m_pMemory;
      }
      if ( m_Size > 0 && v4 > 0 )
      {
        _V_memmove(dest: &m_pMemory[v4], src: m_pMemory, count: m_Size);
        v2 = x1;
      }
    }
    v13->GetTextRange(this: v13, a2: m_pMemory, a3: x0, a4: v2 - x0);
    v6 = (unsigned __int8 *)m_pMemory;
    if ( m_pMemory != nullptr )
    {
      do
      {
        strchr(string: v6, chr: 0xAu);
        v8 = v7;
        if ( v7 != nullptr )
        {
          *v7 = 0;
          v8 = v7 + 1;
        }
        memset(chResolveName, 0, sizeof(chResolveName));
        memset(chResolveNameArg, 0, sizeof(chResolveNameArg));
        V_snprintf(pDest: chResolveNameArg, maxLen: 255, pFormat: "materials/%s.vmt", (const char *)v6);
        v9 = g_pFileSystem->RelativePathToFullPath(
               this: g_pFileSystem,
               a2: chResolveNameArg,
               a3: "game",
               a4: chResolveName,
               a5: 255,
               a6: 0,
               a7: 0);
        if ( v9 != nullptr )
          g_pVGuiSystem->ShellExecuteEx(this: g_pVGuiSystem, a2: "open", a3: v9, a4: defaultValue);
        v6 = v8;
      }
      while ( v8 != nullptr );
    }
    if ( buf.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10098D30
// Name: public: void CRenderTextureEditor::SetDispInfo(class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRenderTextureEditor::SetDispInfo(CRenderTextureEditor *this, KeyValues *kv, int iHint)
{
  KeyValues *m_pInfo; // ecx
  int v5; // edi
  KeyValues *v6; // esi
  KeyValues *Copy; // eax
  const char *String; // eax
  IMaterialSystem_vtbl *v9; // edx
  int v10; // esi
  unsigned __int16 (__thiscall *InvalidMaterial)(IMaterialSystem *); // eax
  IMaterial *v12; // esi
  int v13; // ebx
  IMaterialVar **(__thiscall *GetShaderParams)(IMaterial *); // edx
  IMaterialVar **v15; // eax
  IMaterialVar *v16; // ecx
  int v17; // ebx
  const char *v18; // eax
  const char *v19; // eax
  bool v20; // bl
  const char *v21; // eax
  int v22; // eax
  int v23; // eax
  unsigned __int8 *v24; // edi
  int i; // ebx
  _BYTE *v26; // eax
  int v27; // edi
  const char *v28; // eax
  int v29; // esi
  const char *v30; // eax
  int m_Id; // edi
  const char *v32; // eax
  int v33; // esi
  int v34; // esi
  unsigned __int16 (__thiscall *v35)(IMaterialSystem *); // eax
  const char *v36; // eax
  unsigned __int16 m_NumElements; // ax
  int v38; // esi
  const char *v39; // eax
  CRenderTextureEditor *v40; // esi
  int v41; // eax
  unsigned __int16 *m_pMemory; // edx
  unsigned __int16 *v43; // eax
  int v44; // ebx
  const char *v45; // eax
  CUtlSymbol *v46; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  unsigned __int16 *v49; // ecx
  int v50; // eax
  unsigned __int16 *v51; // edi
  bool *v52; // eax
  bool *v53; // eax
  const char *v54; // [esp-4h] [ebp-1F8h]
  unsigned int v55; // [esp-4h] [ebp-1F8h]
  char chName[260]; // [esp+Ch] [ebp-1E8h] BYREF
  CUtlBuffer bufText; // [esp+110h] [ebp-E4h] BYREF
  CUtlStringMap<bool> arrMaterials; // [esp+140h] [ebp-B4h] BYREF
  CUtlStringMap<bool> arrMaterialsFullNames; // [esp+18Ch] [ebp-68h] BYREF
  const char *szTextureName; // [esp+1D8h] [ebp-1Ch]
  IMaterialVar **arrVars; // [esp+1DCh] [ebp-18h]
  int numParams; // [esp+1E0h] [ebp-14h]
  CRenderTextureEditor *v63; // [esp+1E4h] [ebp-10h]
  CUtlSymbol result; // [esp+1E8h] [ebp-Ch] BYREF
  int hm; // [esp+1ECh] [ebp-8h]
  CUtlSymbol v66; // [esp+1F0h] [ebp-4h] BYREF

  m_pInfo = this->m_pInfo;
  v5 = 0;
  v63 = this;
  this->m_iInfoHint = iHint;
  if ( m_pInfo != nullptr )
    KeyValues::deleteThis(this: m_pInfo);
  v6 = kv;
  if ( kv != nullptr )
    Copy = KeyValues::MakeCopy(this: kv);
  else
    Copy = nullptr;
  this->m_pInfo = Copy;
  arrMaterials.m_Vector.m_Memory.m_pMemory = nullptr;
  arrMaterials.m_Vector.m_Memory.m_nAllocationCount = 0;
  arrMaterials.m_Vector.m_Memory.m_nGrowSize = 32;
  arrMaterials.m_Vector.m_Size = 0;
  arrMaterials.m_Vector.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(this: &arrMaterials.m_SymbolTable, growSize: 0, initSize: 32, caseInsensitive: true);
  arrMaterialsFullNames.m_Vector.m_Memory.m_pMemory = nullptr;
  arrMaterialsFullNames.m_Vector.m_Memory.m_nAllocationCount = 0;
  arrMaterialsFullNames.m_Vector.m_Memory.m_nGrowSize = 32;
  arrMaterialsFullNames.m_Vector.m_Size = 0;
  arrMaterialsFullNames.m_Vector.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(
    this: &arrMaterialsFullNames.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  if ( v6 == nullptr )
    goto LABEL_37;
  String = KeyValues::GetString(this: v6, keyName: "Name", defaultValue: defaultValue);
  v9 = materials->__vftable;
  szTextureName = String;
  v10 = v9->FirstMaterial(this: materials);
  InvalidMaterial = materials->InvalidMaterial;
  hm = v10;
  if ( (_WORD)v10 == InvalidMaterial(this: materials) )
    goto LABEL_37;
  do
  {
    v12 = materials->GetMaterial(this: materials, a2: hm);
    if ( v12 == nullptr )
      goto LABEL_36;
    v13 = v12->ShaderParamCount(this: v12);
    GetShaderParams = v12->GetShaderParams;
    numParams = v13;
    v15 = GetShaderParams(this: v12);
    arrVars = v15;
    if ( v13 <= 0 )
      goto LABEL_35;
    while ( 1 )
    {
      v16 = v15[v5];
      if ( (*((_BYTE *)v16 + 28) & 0xF) == 3 )
        break;
LABEL_15:
      if ( ++v5 >= v13 )
        goto LABEL_35;
    }
    v17 = v16->GetTextureValue(this: v16);
    if ( v17 == 0
      || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v17 + 60))(a1: v17) != 0
      || (v54 = szTextureName,
          v18 = (const char *)(**(int (__thiscall ***)(int))v17)(a1: v17),
          _V_stricmp(s1: v18, s2: v54) != 0) )
    {
      v13 = numParams;
      v15 = arrVars;
      goto LABEL_15;
    }
    v19 = (const char *)v12->GetName(this: v12);
    v20 = StringAfterPrefix(str: v19, prefix: "debug/debugtexture") == nullptr;
    v21 = (const char *)v12->GetName(this: v12);
    if ( StringAfterPrefix(str: v21, prefix: "maps/") != nullptr )
    {
      v22 = v12->GetName(this: v12);
      V_strncpy(pDest: chName, pSrc: (const char *)(v22 + 5), maxLen: 259);
      strchr(string: (unsigned __int8 *)chName, chr: 0x2Fu);
      if ( v23 != 0 )
      {
        v24 = (unsigned __int8 *)(v23 + 1);
        for ( i = 3; i != 0; --i )
        {
          strrchr(string: v24, chr: 0x5Fu);
          if ( v26 != nullptr )
            *v26 = 0;
        }
        sprintf(string: (char *)&v24[strlen((const char *)v24)], format: " (cubemap)");
        CUtlSymbolTable::AddString(
          this: &arrMaterials.m_SymbolTable,
          result: (CUtlSymbol *)&iHint,
          pString: (const char *)v24);
        v27 = (unsigned __int16)iHint;
        if ( arrMaterials.m_Vector.m_Size <= (unsigned __int16)iHint )
          CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCount(
            this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&arrMaterials,
            num: (unsigned __int16)iHint + 1);
        arrMaterials.m_Vector.m_Memory.m_pMemory[v27] = true;
      }
      v28 = (const char *)v12->GetName(this: v12);
      CUtlSymbolTable::AddString(this: &arrMaterialsFullNames.m_SymbolTable, result: (CUtlSymbol *)&kv, pString: v28);
      v29 = (unsigned __int16)kv;
      if ( arrMaterialsFullNames.m_Vector.m_Size <= (unsigned __int16)kv )
        CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCount(
          this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&arrMaterialsFullNames,
          num: (unsigned __int16)kv + 1);
      arrMaterialsFullNames.m_Vector.m_Memory.m_pMemory[v29] = true;
    }
    else if ( v20 )
    {
      v30 = (const char *)v12->GetName(this: v12);
      CUtlSymbolTable::AddString(this: &arrMaterials.m_SymbolTable, &result, pString: v30);
      m_Id = result.m_Id;
      if ( arrMaterials.m_Vector.m_Size <= result.m_Id )
        CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCount(
          this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&arrMaterials,
          num: result.m_Id + 1);
      arrMaterials.m_Vector.m_Memory.m_pMemory[m_Id] = true;
      v32 = (const char *)v12->GetName(this: v12);
      CUtlSymbolTable::AddString(this: &arrMaterialsFullNames.m_SymbolTable, result: &v66, pString: v32);
      v33 = v66.m_Id;
      if ( arrMaterialsFullNames.m_Vector.m_Size <= v66.m_Id )
        CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCount(
          this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&arrMaterialsFullNames,
          num: v66.m_Id + 1);
      arrMaterialsFullNames.m_Vector.m_Memory.m_pMemory[v33] = true;
    }
LABEL_35:
    v5 = 0;
LABEL_36:
    v34 = materials->NextMaterial(this: materials, a2: hm);
    v35 = materials->InvalidMaterial;
    hm = v34;
  }
  while ( (_WORD)v34 != v35(this: materials) );
LABEL_37:
  CUtlBuffer::CUtlBuffer(this: &bufText, growSize: 0, initSize: 0, nFlags: 1);
  if ( arrMaterials.m_SymbolTable.m_Lookup.m_NumElements != 0 )
  {
    if ( arrMaterials.m_SymbolTable.m_Lookup.m_NumElements % 10 != 1
      || (v36 = defaultValue, arrMaterials.m_SymbolTable.m_Lookup.m_NumElements == 11) )
    {
      v36 = "s";
    }
    CUtlBuffer::Printf(this: &bufText, pFmt: "  %d material%s:", arrMaterials.m_SymbolTable.m_Lookup.m_NumElements, v36);
  }
  else
  {
    CUtlBuffer::Printf(this: &bufText, pFmt: "-- no materials --");
  }
  m_NumElements = arrMaterials.m_SymbolTable.m_Lookup.m_NumElements;
  v38 = 0;
  if ( arrMaterials.m_SymbolTable.m_Lookup.m_NumElements != 0 )
  {
    do
    {
      v39 = CUtlSymbolTable::String(this: &arrMaterials.m_SymbolTable, id: (CUtlSymbol)v38);
      CUtlBuffer::Printf(this: &bufText, pFmt: "\n%s", v39);
      m_NumElements = arrMaterials.m_SymbolTable.m_Lookup.m_NumElements;
      ++v38;
    }
    while ( v38 < arrMaterials.m_SymbolTable.m_Lookup.m_NumElements );
  }
  v40 = v63;
  if ( v63->m_pInfo == nullptr || m_NumElements != 0 )
  {
    v63->m_pMaterials->SetText(this: v63->m_pMaterials, a2: (const char *)bufText.m_Memory.m_pMemory);
    v41 = arrMaterialsFullNames.m_SymbolTable.m_Lookup.m_NumElements;
    v40->m_lstMaterials.m_Size = 0;
    if ( v40->m_lstMaterials.m_Memory.m_nAllocationCount < v41 && v40->m_lstMaterials.m_Memory.m_nGrowSize >= 0 )
    {
      m_pMemory = v40->m_lstMaterials.m_Memory.m_pMemory;
      v40->m_lstMaterials.m_Memory.m_nAllocationCount = v41;
      v55 = 2 * v41;
      if ( m_pMemory != nullptr )
        v43 = (unsigned __int16 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v55);
      else
        v43 = (unsigned __int16 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v55);
      v40->m_lstMaterials.m_Memory.m_pMemory = v43;
    }
    v44 = 0;
    v40->m_lstMaterials.m_pElements = v40->m_lstMaterials.m_Memory.m_pMemory;
    if ( arrMaterialsFullNames.m_SymbolTable.m_Lookup.m_NumElements != 0 )
    {
      do
      {
        v45 = CUtlSymbolTable::String(this: &arrMaterialsFullNames.m_SymbolTable, id: (CUtlSymbol)v44);
        v46 = CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&iHint + 1, pStr: v45);
        m_Size = v40->m_lstMaterials.m_Size;
        kv = (KeyValues *)v46->m_Id;
        m_nAllocationCount = v40->m_lstMaterials.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<wchar_t,int>::Grow(
            this: (CUtlMemory<wchar_t,int> *)&v40->m_lstMaterials,
            num: m_Size - m_nAllocationCount + 1);
        ++v40->m_lstMaterials.m_Size;
        v49 = v40->m_lstMaterials.m_Memory.m_pMemory;
        v50 = v40->m_lstMaterials.m_Size - m_Size - 1;
        v40->m_lstMaterials.m_pElements = v49;
        if ( v50 > 0 )
          _V_memmove(dest: &v49[m_Size + 1], src: &v49[m_Size], count: 2 * v50);
        v51 = &v40->m_lstMaterials.m_Memory.m_pMemory[m_Size];
        if ( v51 != nullptr )
          *v51 = (unsigned __int16)kv;
        ++v44;
      }
      while ( v44 < arrMaterialsFullNames.m_SymbolTable.m_Lookup.m_NumElements );
    }
  }
  v40->m_bufInfoText.m_Get = 0;
  v40->m_bufInfoText.m_Put = 0;
  v40->m_bufInfoText.m_Error = 0;
  v40->m_bufInfoText.m_nOffset = 0;
  v40->m_bufInfoText.m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: &v40->m_bufInfoText, nPut: 0);
  v40->InvalidateLayout(this: v40, a2: false, a3: false);
  if ( bufText.m_Memory.m_nGrowSize >= 0 )
  {
    if ( bufText.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufText.m_Memory.m_pMemory);
      bufText.m_Memory.m_pMemory = nullptr;
    }
    bufText.m_Memory.m_nAllocationCount = 0;
  }
  CUtlSymbolTable::~CUtlSymbolTable(this: &arrMaterialsFullNames.m_SymbolTable);
  v52 = arrMaterialsFullNames.m_Vector.m_Memory.m_pMemory;
  arrMaterialsFullNames.m_Vector.m_Size = 0;
  if ( arrMaterialsFullNames.m_Vector.m_Memory.m_nGrowSize >= 0 )
  {
    if ( arrMaterialsFullNames.m_Vector.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: arrMaterialsFullNames.m_Vector.m_Memory.m_pMemory);
      v52 = nullptr;
      arrMaterialsFullNames.m_Vector.m_Memory.m_pMemory = nullptr;
    }
    arrMaterialsFullNames.m_Vector.m_Memory.m_nAllocationCount = 0;
  }
  arrMaterialsFullNames.m_Vector.m_pElements = v52;
  if ( arrMaterialsFullNames.m_Vector.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v52 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v52);
      arrMaterialsFullNames.m_Vector.m_Memory.m_pMemory = nullptr;
    }
    arrMaterialsFullNames.m_Vector.m_Memory.m_nAllocationCount = 0;
  }
  CUtlSymbolTable::~CUtlSymbolTable(this: &arrMaterials.m_SymbolTable);
  v53 = arrMaterials.m_Vector.m_Memory.m_pMemory;
  arrMaterials.m_Vector.m_Size = 0;
  if ( arrMaterials.m_Vector.m_Memory.m_nGrowSize >= 0 )
  {
    if ( arrMaterials.m_Vector.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: arrMaterials.m_Vector.m_Memory.m_pMemory);
      v53 = nullptr;
      arrMaterials.m_Vector.m_Memory.m_pMemory = nullptr;
    }
    arrMaterials.m_Vector.m_Memory.m_nAllocationCount = 0;
  }
  arrMaterials.m_Vector.m_pElements = v53;
  if ( arrMaterials.m_Vector.m_Memory.m_nGrowSize >= 0 && v53 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v53);
}

//------------------------------------------------------------------------------
// Address: 0x10099370
// Name: public: virtual void CRenderTextureEditor::Close(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRenderTextureEditor::Close(CRenderTextureEditor *this)
{
  vgui::Frame::Close(this);
  CRenderTextureEditor::SetDispInfo(this, kv: nullptr, iHint: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10099390
// Name: public: virtual void CRenderTextureEditor::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CRenderTextureEditor::Paint(CRenderTextureEditor *this@<ecx>, int a2@<edi>)
{
  void (__thiscall *Flush)(IMaterialSystem *, bool); // eax
  void (__thiscall *SetBgColor)(vgui::Panel *, Color); // edx
  KeyValues *m_pInfo; // esi
  const char *String; // edi
  const char *v7; // eax
  ITexture *v8; // edi
  const char *v9; // eax
  int v10; // ebx
  int v11; // esi
  float v12; // xmm1_4
  const char *v13; // ebx
  const char *v14; // eax
  IMatSystemSurface_vtbl *v15; // esi
  int v16; // eax
  const char *v17; // esi
  int v18; // eax
  ITexture v19; // edx
  IMaterial *v20; // eax
  ITexture v21; // edx
  int v22; // eax
  ITexture v23; // edx
  int v24; // ebx
  int v25; // esi
  int (__thiscall *GetActualDepth)(ITexture *); // eax
  int v27; // eax
  ITexture v28; // edx
  int v29; // ecx
  int v30; // ecx
  int v31; // esi
  int v32; // eax
  int MemRequired; // eax
  int v34; // eax
  int v35; // edx
  IMaterial *v36; // ecx
  int v37; // eax
  int v38; // eax
  IMatSystemSurface_vtbl *v39; // esi
  int v40; // eax
  IMatSystemSurface_vtbl *v41; // esi
  int v42; // eax
  int v43; // eax
  int v44; // esi
  int v45; // ebx
  int v46; // edi
  int v47; // ebx
  int v48; // esi
  int v49; // ebx
  IMatSystemSurface_vtbl *v50; // esi
  int v51; // eax
  int v52; // [esp-4h] [ebp-4B4h]
  char chResolveName[256]; // [esp+8h] [ebp-4A8h] BYREF
  char chResolveNameArg[256]; // [esp+108h] [ebp-3A8h] BYREF
  char chLine2[256]; // [esp+208h] [ebp-2A8h] BYREF
  char chLine1[256]; // [esp+308h] [ebp-1A8h] BYREF
  char chbuf[52]; // [esp+408h] [ebp-A8h] BYREF
  CAutoMatSysDebugMode auto_matsysdebugmode; // [esp+43Ch] [ebp-74h] BYREF
  char chSizeBuf[20]; // [esp+45Ch] [ebp-54h] BYREF
  const char *szTextureFile; // [esp+470h] [ebp-40h]
  IMaterial *pMaterial; // [esp+474h] [ebp-3Ch]
  ITexture *pMatTexture; // [esp+478h] [ebp-38h]
  int wmap; // [esp+47Ch] [ebp-34h]
  ImageFormat fmt; // [esp+480h] [ebp-30h]
  int iDrawWidth; // [esp+484h] [ebp-2Ch]
  bool bHasAlpha; // [esp+48Bh] [ebp-25h]
  vgui::Panel *pPanel; // [esp+48Ch] [ebp-24h]
  int iTxWidth; // [esp+490h] [ebp-20h]
  int dmap; // [esp+494h] [ebp-1Ch]
  int orgTxXA; // [esp+498h] [ebp-18h]
  int hact; // [esp+49Ch] [ebp-14h]
  int iTxHeight; // [esp+4A0h] [ebp-10h]
  int iDrawHeight; // [esp+4A4h] [ebp-Ch]
  int extTxHeight; // [esp+4A8h] [ebp-8h]
  int dact; // [esp+4ACh] [ebp-4h]

  Flush = g_pMaterialSystem->Flush;
  pPanel = this;
  auto_matsysdebugmode.arrCleanupVars.m_LessFunc = (bool (__cdecl *)(IMaterialVar *const *, IMaterialVar *const *))CDmxSerializationDictionary::LessFunc;
  memset(&auto_matsysdebugmode.arrCleanupVars.m_Elements, 0, sizeof(auto_matsysdebugmode.arrCleanupVars.m_Elements));
  *(_DWORD *)&auto_matsysdebugmode.arrCleanupVars.m_Root = 0xFFFF;
  *(_DWORD *)&auto_matsysdebugmode.arrCleanupVars.m_FirstFree = -1;
  auto_matsysdebugmode.arrCleanupVars.m_pElements = nullptr;
  Flush(this: g_pMaterialSystem, a2: false);
  auto_matsysdebugmode.bOldDebugMode = g_pMaterialSystemDebugTextureInfo->SetDebugTextureRendering(
                                         this: g_pMaterialSystemDebugTextureInfo,
                                         a2: true);
  vgui::Frame::DisableFadeEffect(this);
  SetBgColor = this->SetBgColor;
  extTxHeight = -16109046;
  ((void (__thiscall *)(CRenderTextureEditor *, int))SetBgColor)(a1: this, a2: -16109046);
  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  m_pInfo = this->m_pInfo;
  orgTxXA = (int)m_pInfo;
  if ( m_pInfo == nullptr )
  {
    CAutoMatSysDebugMode::~CAutoMatSysDebugMode(this: &auto_matsysdebugmode);
    return;
  }
  v52 = a2;
  String = KeyValues::GetString(this: m_pInfo, keyName: "Name", defaultValue: defaultValue);
  szTextureFile = String;
  V_strncpy(pDest: `anonymous namespace'::s_chLastViewedTextureBuffer, pSrc: String, maxLen: 512);
  v7 = KeyValues::GetString(this: m_pInfo, keyName: "TexGroup", defaultValue: defaultValue);
  if ( *String == 0
    || (v8 = materials->FindTexture(this: materials, a2: String, a3: v7, a4: 0, a5: 0), pMatTexture = v8, v8 == nullptr) )
  {
    v8 = materials->FindTexture(this: materials, a2: "debugempty", a3: defaultValue, a4: 0, a5: 0);
    pMatTexture = v8;
  }
  iTxWidth = KeyValues::GetInt(this: m_pInfo, keyName: "Width", defaultValue: 0);
  iTxHeight = KeyValues::GetInt(this: m_pInfo, keyName: "Height", defaultValue: 0);
  dmap = KeyValues::GetInt(this: m_pInfo, keyName: "Size", defaultValue: 0);
  v9 = KeyValues::GetString(this: m_pInfo, keyName: "Format", defaultValue: defaultValue);
  v10 = iTxWidth;
  v11 = iTxHeight;
  extTxHeight = (int)v9;
  if ( v8 != nullptr && ((unsigned __int8 (__thiscall *)(ITexture *, int))v8->IsCubeMap)(a1: v8, a2: v52) != 0 )
  {
    v10 = 1024;
    v11 = 1024;
LABEL_11:
    v10 = (int)(float)((float)(256.0 / (float)v11) * (float)v10);
    v11 = 256;
    goto LABEL_19;
  }
  if ( iTxHeight < iTxWidth )
  {
    if ( iTxWidth <= 256 )
    {
      if ( iTxWidth >= 64 )
        goto LABEL_19;
      v12 = 64.0;
      v10 = 64;
    }
    else
    {
      v12 = 256.0;
      v10 = 256;
    }
    v11 = (int)(float)((float)(v12 / (float)iTxWidth) * (float)iTxHeight);
  }
  else
  {
    if ( iTxHeight > 256 )
      goto LABEL_11;
    if ( iTxHeight < 64 )
    {
      v10 = (int)(float)((float)(64.0 / (float)iTxHeight) * (float)iTxWidth);
      v11 = 64;
    }
  }
LABEL_19:
  iDrawHeight = (int)(float)((float)v11 * 2.1484375);
  iDrawWidth = (int)(float)((float)v10 * 2.1484375);
  if ( iDrawHeight <= 4 )
    iDrawHeight = 4;
  if ( (int)(float)((float)v10 * 2.1484375) <= 4 )
    iDrawWidth = 4;
  ((void (__thiscall *)(IMatSystemSurface *, int, int, int, int, int))g_pMatSystemSurface->DrawSetColor_2)(
    a1: g_pMatSystemSurface,
    a2: 255,
    a3: 255,
    a4: 255,
    a5: 255,
    a6: v52);
  g_pMatSystemSurface->DrawOutlinedRect(this: g_pMatSystemSurface, a2: 11, a3: 11, a4: 578, a5: 658);
  memset(chResolveName, 0, sizeof(chResolveName));
  memset(chResolveNameArg, 0, sizeof(chResolveNameArg));
  v13 = szTextureFile;
  V_snprintf(pDest: chResolveNameArg, maxLen: 255, pFormat: "materials/%s.vtf", szTextureFile);
  v14 = g_pFileSystem->RelativePathToFullPath(
          this: g_pFileSystem,
          a2: chResolveNameArg,
          a3: "game",
          a4: chResolveName,
          a5: 255,
          a6: 0,
          a7: 0);
  if ( v14 != nullptr )
  {
    dact = (int)defaultValue;
    v13 = v14;
  }
  else
  {
    dact = (int)"[?]/";
  }
  memset(chSizeBuf, 0, sizeof(chSizeBuf));
  if ( dmap < 0 )
    chSizeBuf[0] = 45;
  else
    FmtCommaNumber(pchBuffer: chSizeBuf, uiNumber: dmap);
  v15 = g_pMatSystemSurface->__vftable;
  v16 = ((int (__thiscall *)(vgui::Panel *, int, int, int, int, int, int, int, int, const char *, int, const char *, char *, int, int, int))pPanel->__vftable[1].GetBorder)(
          a1: pPanel,
          a2: 20,
          a3: 20,
          a4: 550,
          a5: 35,
          a6: 255,
          a7: 255,
          a8: 255,
          a9: 255,
          a10: "%s%s\n%s Kb    %dx%d    %s",
          a11: dact,
          a12: v13,
          a13: chSizeBuf,
          a14: iTxWidth,
          a15: iTxHeight,
          a16: extTxHeight);
  ((void (__cdecl *)(IMatSystemSurface *, int))v15->DrawColoredTextRect)(a1: g_pMatSystemSurface, a2: v16);
  if ( pPanel[1].m_sNavRightName.m_Storage.m_Memory.m_nAllocationCount == 0 )
    CUtlBuffer::Printf(
      this: (CUtlBuffer *)&pPanel[1].m_sNavLeftName.m_Storage.m_Memory.m_nGrowSize,
      pFmt: "%s%s\r\n%s Kb    %dx%d    %s",
      (const char *)dact,
      v13,
      chSizeBuf,
      iTxWidth,
      iTxHeight,
      (const char *)extTxHeight);
  if ( KeyValues::GetInt(this: (KeyValues *)orgTxXA, keyName: "SpecialTx", defaultValue: 0) != 0 )
    goto LABEL_79;
  memset(chLine1, 0, sizeof(chLine1));
  memset(chLine2, 0, sizeof(chLine2));
  if ( dmap > g_warn_texkbytes )
    sprintf(string: &chLine1[strlen(chLine1)], format: "  Size(%s Kb)", chSizeBuf);
  if ( iTxWidth > g_warn_texdimensions || iTxHeight > g_warn_texdimensions )
    sprintf(string: &chLine1[strlen(chLine1)], format: "  Dimensions(%dx%d)", iTxWidth, iTxHeight);
  v17 = (const char *)extTxHeight;
  if ( _V_stricmp(s1: (const char *)extTxHeight, s2: "DXT1") != 0 && _V_stricmp(s1: v17, s2: "DXT5") != 0 )
    sprintf(string: &chLine1[strlen(chLine1)], format: "  Format(%s)", v17);
  if ( (v8->GetFlags(this: v8) & 0x200) != 0 )
    sprintf(string: &chLine1[strlen(chLine1)], format: "  NoLod");
  if ( (v8->GetFlags(this: v8) & 0x100) != 0 )
    sprintf(string: &chLine1[strlen(chLine1)], format: "  NoMip");
  if ( (v8->GetFlags(this: v8) & 0x1000) != 0 )
    sprintf(string: &chLine1[strlen(chLine1)], format: "  OneBitAlpha");
  v18 = v8->GetMappingWidth(this: v8);
  v19.__vftable = v8->__vftable;
  wmap = v18;
  v20 = (IMaterial *)v19.GetMappingHeight(this: v8);
  v21.__vftable = v8->__vftable;
  pMaterial = v20;
  v22 = v21.GetMappingDepth(this: v8);
  v23.__vftable = v8->__vftable;
  dmap = v22;
  v24 = v23.GetActualWidth(this: v8);
  v25 = v8->GetActualHeight(this: v8);
  GetActualDepth = v8->GetActualDepth;
  hact = v25;
  v27 = GetActualDepth(this: v8);
  v28.__vftable = v8->__vftable;
  dact = v27;
  fmt = v28.GetImageFormat(this: v8);
  if ( v24 > 4 || v25 > 4 )
  {
    orgTxXA = 1;
    if ( dact / 2 >= 1 )
      orgTxXA = dact / 2;
    v29 = v25;
    if ( v25 >= 4 )
      v29 = 4;
    if ( v29 <= v25 / 2 )
    {
      v30 = v25 / 2;
    }
    else if ( v25 >= 4 )
    {
      v30 = 4;
    }
    else
    {
      v30 = v25;
    }
    v31 = v24;
    if ( v24 >= 4 )
      v31 = 4;
    v32 = v24 / 2;
    if ( v31 > v24 / 2 )
    {
      v32 = v24;
      if ( v24 >= 4 )
        v32 = 4;
    }
    MemRequired = ImageLoader::GetMemRequired(
                    width: v32,
                    height: v30,
                    depth: orgTxXA,
                    imageFormat: fmt,
                    mipmap: true,
                    pAdjustedHeight: nullptr);
    FmtCommaNumber(pchBuffer: chbuf, uiNumber: (MemRequired + 511) / 1024);
    sprintf(string: &chLine2[strlen(chLine2)], format: "  %s Kb @ lower mip", chbuf);
    v25 = hact;
  }
  if ( wmap > v24 || (int)pMaterial > v25 )
  {
    v34 = dmap;
LABEL_68:
    v35 = 2 * dact;
    if ( v34 < 2 * dact )
      v35 = v34;
    v36 = (IMaterial *)(2 * v25);
    if ( (int)pMaterial < 2 * v25 )
      v36 = pMaterial;
    v37 = 2 * v24;
    if ( wmap < 2 * v24 )
      v37 = wmap;
    v38 = ImageLoader::GetMemRequired(
            width: v37,
            height: (int)v36,
            depth: v35,
            imageFormat: fmt,
            mipmap: true,
            pAdjustedHeight: nullptr);
    FmtCommaNumber(pchBuffer: chbuf, uiNumber: (v38 + 511) / 1024);
    sprintf(string: &chLine2[strlen(chLine2)], format: "      %s Kb @ higher mip", chbuf);
    goto LABEL_75;
  }
  v34 = dmap;
  if ( dmap > dact )
    goto LABEL_68;
LABEL_75:
  if ( chLine1[0] != 0 )
  {
    g_pMatSystemSurface->DrawSetColor_2(this: g_pMatSystemSurface, a2: 200, a3: 0, a4: 0, a5: 255);
    g_pMatSystemSurface->DrawFilledRect(this: g_pMatSystemSurface, a2: 15, a3: 55, a4: 575, a5: 72);
    v39 = g_pMatSystemSurface->__vftable;
    v40 = ((int (__thiscall *)(vgui::Panel *, int, int, int, int, int, int, int, int, const char *, char *))pPanel->__vftable[1].GetBorder)(
            a1: pPanel,
            a2: 20,
            a3: 55,
            a4: 550,
            a5: 17,
            a6: 255,
            a7: 255,
            a8: 255,
            a9: 255,
            a10: "%s",
            a11: chLine1);
    ((void (__cdecl *)(IMatSystemSurface *, int))v39->DrawColoredTextRect)(a1: g_pMatSystemSurface, a2: v40);
  }
  if ( chLine2[0] != 0 )
  {
    v41 = g_pMatSystemSurface->__vftable;
    v42 = ((int (__thiscall *)(vgui::Panel *, int, int, int, int, int, int, int, int, const char *, char *))pPanel->__vftable[1].GetBorder)(
            a1: pPanel,
            a2: 20,
            a3: 72,
            a4: 550,
            a5: 17,
            a6: 255,
            a7: 255,
            a8: 255,
            a9: 255,
            a10: "%s",
            a11: chLine2);
    ((void (__cdecl *)(IMatSystemSurface *, int))v41->DrawColoredTextRect)(a1: g_pMatSystemSurface, a2: v42);
  }
LABEL_79:
  v43 = _V_stricmp(s1: (const char *)extTxHeight, s2: "DXT1");
  v44 = 0;
  bHasAlpha = v43 != 0;
  dact = 550;
  extTxHeight = 550;
  orgTxXA = 0;
  dmap = 0;
  if ( v43 != 0 )
  {
    if ( iTxWidth < 2 * iTxHeight )
    {
      if ( iTxHeight < 2 * iTxWidth )
      {
        dmap = 280;
        v44 = 137;
        if ( iDrawWidth > 275 )
        {
          iDrawWidth /= 2;
          iDrawHeight /= 2;
        }
        dact = 274;
        extTxHeight = 274;
      }
      else
      {
        orgTxXA = 280;
        dact = 272;
      }
    }
    else
    {
      dmap = 280;
      extTxHeight = 274;
    }
  }
  pMaterial = UseDebugMaterial(
                szMaterial: "debug/debugtexturecolor",
                pMatTexture: v8,
                pRestoreVars: &auto_matsysdebugmode);
  if ( pMaterial != nullptr )
  {
    ((void (__thiscall *)(IMatSystemSurface *, int, int, int))g_pMatSystemSurface->DrawSetColor_2)(
      a1: g_pMatSystemSurface,
      a2: 255,
      a3: 255,
      a4: 255);
    v45 = dact;
    iTxWidth = (extTxHeight + iDrawHeight) / 2;
    v46 = (dact + iDrawWidth) / 2;
    fmt = v46 + v44 + 20;
    iTxHeight = (extTxHeight - iDrawHeight) / 2;
    dact = iTxHeight + 100;
    hact = iTxWidth + 100;
    v47 = (v45 - iDrawWidth) / 2;
    wmap = v47 + v44 + 20;
    g_pMatSystemSurface->DrawOutlinedRect(
      this: g_pMatSystemSurface,
      a2: v47 + v44 + 18,
      a3: iTxHeight + 98,
      a4: v46 + v44 + 22,
      a5: iTxWidth + 102);
    RenderTexturedRect(pPanel, pMaterial, x: wmap, y: dact, x1: fmt, y1: hact, xoff: 0, yoff: 0);
    if ( bHasAlpha )
    {
      v48 = orgTxXA + v44;
      fmt = (ImageFormat)UseDebugMaterial(
                           szMaterial: "debug/debugtexturealpha",
                           pMatTexture,
                           pRestoreVars: &auto_matsysdebugmode);
      if ( fmt != IMAGE_FORMAT_RGBA8888 )
      {
        hact = iTxWidth + dmap + 100;
        pMatTexture = (ITexture *)(iTxHeight + dmap + 100);
        g_pMatSystemSurface->DrawOutlinedRect(
          this: g_pMatSystemSurface,
          a2: v47 + v48 + 18,
          a3: iTxHeight + dmap + 98,
          a4: v46 + v48 + 22,
          a5: iTxWidth + dmap + 102);
        RenderTexturedRect(
          pPanel,
          pMaterial: (IMaterial *)fmt,
          x: v47 + v48 + 20,
          y: (int)pMatTexture,
          x1: v46 + v48 + 20,
          y1: hact,
          xoff: 0,
          yoff: 0);
      }
      v44 = v48 - orgTxXA;
    }
  }
  else
  {
    ((void (__thiscall *)(IMatSystemSurface *, int, _DWORD, int))g_pMatSystemSurface->DrawSetColor_2)(
      a1: g_pMatSystemSurface,
      a2: 255,
      a3: 0,
      a4: 255);
    hact = (int)g_pMatSystemSurface->__vftable;
    v46 = (dact + iDrawWidth) / 2;
    v47 = (dact - iDrawWidth) / 2;
    (*(void (__thiscall **)(IMatSystemSurface *, int, int, int, int))(hact + 60))(
      a1: g_pMatSystemSurface,
      a2: v47 + v44 + 20,
      a3: (dact - iDrawHeight) / 2 + 100,
      a4: v46 + v44 + 20,
      a5: (dact + iDrawHeight) / 2 + 100);
  }
  if ( IsTextureExcluded(szTextureName: szTextureFile) )
  {
    g_pMatSystemSurface->DrawSetColor_2(this: g_pMatSystemSurface, a2: 200, a3: 0, a4: 0, a5: 255);
    v49 = v47 + v44 + 20;
    dact = (extTxHeight - iDrawHeight) / 2 + 100;
    hact = (int)g_pMatSystemSurface->__vftable;
    (*(void (__thiscall **)(IMatSystemSurface *, int, int, int, int))(hact + 60))(
      a1: g_pMatSystemSurface,
      a2: v49 - 2,
      a3: (extTxHeight - iDrawHeight) / 2 + 98,
      a4: v46 + v44 + 22,
      a5: (extTxHeight + iDrawHeight) / 2 + 102);
    v50 = g_pMatSystemSurface->__vftable;
    v51 = ((int (__thiscall *)(vgui::Panel *, int, int, int, int, int, int, int, int, const char *))pPanel->__vftable[1].GetBorder)(
            a1: pPanel,
            a2: v49,
            a3: dact,
            a4: iDrawWidth,
            a5: iDrawHeight,
            a6: 255,
            a7: 255,
            a8: 255,
            a9: 255,
            a10: "EXCLUDED");
    ((void (__cdecl *)(IMatSystemSurface *, int))v50->DrawColoredTextRect)(a1: g_pMatSystemSurface, a2: v51);
  }
  CAutoMatSysDebugMode::~CAutoMatSysDebugMode(this: &auto_matsysdebugmode);
}

//------------------------------------------------------------------------------
// Address: 0x10099F50
// Name: protected: virtual void CRenderTexturesListViewPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRenderTexturesListViewPanel::OnMousePressed(CRenderTexturesListViewPanel *this, const char *code)
{
  int v3; // edi
  KeyValues *v4; // eax
  int Wide; // eax
  int Tall; // eax
  vgui::Panel *i; // edi
  ButtonCode_t v8; // ecx
  int v9; // eax
  int iTile; // [esp+8h] [ebp-18h] BYREF
  int x; // [esp+Ch] [ebp-14h] BYREF
  int y; // [esp+10h] [ebp-10h] BYREF
  int iTopLeftY; // [esp+14h] [ebp-Ch] BYREF
  int iTopLeftX; // [esp+18h] [ebp-8h] BYREF
  int tileY; // [esp+1Ch] [ebp-4h] BYREF

  CBaseServer::RemoveClientFromGame(this, panelName: code);
  this->m_pRenderTxEditor->Close(this: this->m_pRenderTxEditor);
  if ( this->m_pListPanel != nullptr )
  {
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
    vgui::Panel::ScreenToLocal(this, &x, &y);
    if ( this->HitTest(this, a2: x, a3: y, a4: &iTile) != 0
      && this->GetTileOrg(this, a2: iTile, a3: (int *)&code, a4: &tileY) )
    {
      v3 = this->m_pListPanel->GetItemIDFromRow(this: this->m_pListPanel, a2: iTile);
      if ( v3 >= 0 )
      {
        v4 = this->m_pListPanel->GetItem(this: this->m_pListPanel, a2: v3);
        if ( v4 != nullptr )
        {
          CRenderTextureEditor::SetDispInfo(this: this->m_pRenderTxEditor, kv: v4, iHint: v3);
          Wide = vgui::Panel::GetWide(this: this->m_pRenderTxEditor);
          if ( (int)&code[Wide] > this->m_li_wide - 2 )
            code = (const char *)(this->m_li_wide - vgui::Panel::GetWide(this: this->m_pRenderTxEditor) - 2);
          Tall = vgui::Panel::GetTall(this: this->m_pRenderTxEditor);
          if ( tileY + Tall > this->m_li_tall - 2 )
            tileY = this->m_li_tall - vgui::Panel::GetTall(this: this->m_pRenderTxEditor) - 2;
          iTopLeftX = 0;
          iTopLeftY = 0;
          for ( i = this->GetParent(this); i != nullptr; i = i->GetParent(this: i) )
          {
            iTopLeftY = 0;
            iTopLeftX = 0;
            vgui::Panel::LocalToScreen(this: i, x: &iTopLeftX, y: &iTopLeftY);
          }
          vgui::Panel::LocalToScreen(this, x: (int *)&code, y: &tileY);
          v8 = (ButtonCode_t)code;
          if ( (int)code < iTopLeftX )
          {
            v8 = iTopLeftX;
            code = (const char *)iTopLeftX;
          }
          v9 = tileY;
          if ( tileY < iTopLeftY )
          {
            v9 = iTopLeftY;
            tileY = iTopLeftY;
          }
          vgui::Panel::SetPos(this: this->m_pRenderTxEditor, x: v8, y: v9);
          this->m_pRenderTxEditor->Activate(this: this->m_pRenderTxEditor);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009A130
// Name: protected: virtual void CRenderTexturesListViewPanel::RenderTile(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CRenderTexturesListViewPanel::RenderTile(
        CRenderTexturesListViewPanel *this@<ecx>,
        BOOL a2@<edi>,
        IMatSystemSurface_vtbl *iTile,
        int x,
        int y)
{
  void (__thiscall *Flush)(IMaterialSystem *, bool); // eax
  bool v7; // al
  vgui::ListPanel *m_pListPanel; // ecx
  int (__thiscall *GetItemIDFromRow)(vgui::ListPanel *, int); // edx
  int v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  const char *String; // edi
  const char *v14; // eax
  int Int; // ebx
  int v16; // edi
  const char *v17; // edx
  int v18; // eax
  const char *v19; // esi
  int v20; // esi
  float v21; // xmm1_4
  int v22; // ebx
  int v23; // edi
  int v24; // edi
  int v25; // ebx
  int v26; // eax
  unsigned int v27; // eax
  Color v28; // eax
  bool v29; // zf
  const char *v30; // eax
  const char *v31; // esi
  IMatSystemSurface_vtbl *v32; // ebx
  void (__thiscall *Think)(vgui::IClientPanel *); // eax
  int v34; // eax
  int v35; // eax
  int i; // eax
  int j; // esi
  IMatSystemSurface_vtbl *v38; // ebx
  int v39; // eax
  int v40; // ebx
  int v41; // esi
  int v42; // ebx
  IMatSystemSurface_vtbl *v43; // ebx
  int v44; // eax
  int v45; // eax
  int v46; // esi
  int v47; // ebx
  int v48; // esi
  IMatSystemSurface_vtbl *v49; // esi
  int v50; // eax
  BOOL v51; // [esp-4h] [ebp-19Ch]
  char chInfoText[256]; // [esp+8h] [ebp-190h] BYREF
  CAutoMatSysDebugMode auto_matsysdebugmode; // [esp+108h] [ebp-90h] BYREF
  int iTextLen[4]; // [esp+128h] [ebp-70h] BYREF
  int v55; // [esp+138h] [ebp-60h]
  char chSizeBuf[20]; // [esp+13Ch] [ebp-5Ch] BYREF
  int iTextMargins[4]; // [esp+150h] [ebp-48h] BYREF
  const char *szTextureFile; // [esp+160h] [ebp-38h]
  int y1; // [esp+164h] [ebp-34h]
  IMaterial *pMaterial; // [esp+168h] [ebp-30h] BYREF
  int iTxSize; // [esp+16Ch] [ebp-2Ch]
  int orgTxXA; // [esp+170h] [ebp-28h]
  ITexture *pMatTexture; // [esp+174h] [ebp-24h]
  int tileHeight; // [esp+178h] [ebp-20h] BYREF
  int iTxWidth; // [esp+17Ch] [ebp-1Ch]
  int iDrawWidth; // [esp+180h] [ebp-18h]
  int iDrawHeight; // [esp+184h] [ebp-14h]
  vgui::Panel *pPanel; // [esp+188h] [ebp-10h]
  int iTxHeight; // [esp+18Ch] [ebp-Ch]
  const char *szTxFormat; // [esp+190h] [ebp-8h]
  int extTxHeight; // [esp+194h] [ebp-4h]

  Flush = g_pMaterialSystem->Flush;
  pPanel = this;
  auto_matsysdebugmode.arrCleanupVars.m_LessFunc = (bool (__cdecl *)(IMaterialVar *const *, IMaterialVar *const *))CDmxSerializationDictionary::LessFunc;
  memset(&auto_matsysdebugmode.arrCleanupVars.m_Elements, 0, sizeof(auto_matsysdebugmode.arrCleanupVars.m_Elements));
  *(_DWORD *)&auto_matsysdebugmode.arrCleanupVars.m_Root = 0xFFFF;
  *(_DWORD *)&auto_matsysdebugmode.arrCleanupVars.m_FirstFree = -1;
  auto_matsysdebugmode.arrCleanupVars.m_pElements = nullptr;
  Flush(this: g_pMaterialSystem, a2: false);
  v7 = g_pMaterialSystemDebugTextureInfo->SetDebugTextureRendering(this: g_pMaterialSystemDebugTextureInfo, a2: true);
  m_pListPanel = this->m_pListPanel;
  GetItemIDFromRow = m_pListPanel->GetItemIDFromRow;
  auto_matsysdebugmode.bOldDebugMode = v7;
  v10 = GetItemIDFromRow(this: m_pListPanel, a2: (int)iTile);
  if ( v10 < 0
    || (v11 = this->m_pListPanel->GetItem(this: this->m_pListPanel, a2: v10),
        v12 = v11,
        iTile = (IMatSystemSurface_vtbl *)v11,
        v11 == nullptr) )
  {
    CAutoMatSysDebugMode::~CAutoMatSysDebugMode(this: &auto_matsysdebugmode);
    return;
  }
  v51 = a2;
  String = KeyValues::GetString(this: v11, keyName: "Name", defaultValue: defaultValue);
  szTextureFile = String;
  v14 = KeyValues::GetString(this: v12, keyName: "TexGroup", defaultValue: defaultValue);
  if ( *String == 0
    || (pMatTexture = materials->FindTexture(this: materials, a2: String, a3: v14, a4: 0, a5: 0)) == nullptr )
  {
    pMatTexture = materials->FindTexture(this: materials, a2: "debugempty", a3: defaultValue, a4: 0, a5: 0);
  }
  Int = KeyValues::GetInt(this: v12, keyName: "Width", defaultValue: 0);
  iTxWidth = Int;
  v16 = KeyValues::GetInt(this: v12, keyName: "Height", defaultValue: 0);
  iTxHeight = v16;
  iTxSize = KeyValues::GetInt(this: v12, keyName: "Size", defaultValue: 0);
  v17 = KeyValues::GetString(this: v12, keyName: "Format", defaultValue: defaultValue);
  szTxFormat = v17;
  v18 = strlen(v17);
  v19 = defaultValue;
  extTxHeight = v18;
  orgTxXA = (int)defaultValue;
  if ( v18 > 4 )
  {
    while ( v17[v18 - 1] != 54 )
    {
      if ( v17[v18 - 1] == 56 )
      {
        extTxHeight = v18;
        if ( v18 <= 4 )
          goto LABEL_22;
        do
        {
          if ( v17[v18 - 2] != 56 )
            break;
          --v18;
        }
        while ( v18 > 4 );
        goto LABEL_21;
      }
      if ( v17[v18 - 1] != 70 || *v19 != 0 )
        goto LABEL_21;
      v19 = "F";
      --v18;
      orgTxXA = (int)"F";
    }
    extTxHeight = v18;
    if ( v18 <= 4 )
      goto LABEL_22;
    do
    {
      if ( v17[v18 - 2] != 49 )
        break;
      if ( v17[v18 - 3] != 54 )
        break;
      v18 -= 2;
    }
    while ( v18 > 4 );
LABEL_21:
    extTxHeight = v18;
  }
LABEL_22:
  v20 = Int;
  if ( pMatTexture != nullptr
    && ((unsigned __int8 (__thiscall *)(ITexture *, BOOL))pMatTexture->IsCubeMap)(a1: pMatTexture, a2: v51) != 0 )
  {
    v20 = 1024;
    v16 = 1024;
  }
  else
  {
    if ( iTxHeight < Int )
    {
      if ( Int <= 256 )
      {
        if ( Int >= 64 )
          goto LABEL_35;
        v21 = 64.0;
        v20 = 64;
      }
      else
      {
        v21 = 256.0;
        v20 = 256;
      }
      v16 = (int)(float)((float)(v21 / (float)Int) * (float)iTxHeight);
      goto LABEL_35;
    }
    if ( iTxHeight <= 256 )
    {
      if ( iTxHeight < 64 )
      {
        v20 = (int)(float)((float)(64.0 / (float)iTxHeight) * (float)Int);
        v16 = 64;
      }
      goto LABEL_35;
    }
  }
  v20 = (int)(float)((float)(256.0 / (float)v16) * (float)v20);
  v16 = 256;
LABEL_35:
  iDrawHeight = (int)(float)((float)v16 * 0.75);
  iDrawWidth = (int)(float)((float)v20 * 0.75);
  if ( iDrawHeight <= 4 )
    iDrawHeight = 4;
  if ( (int)(float)((float)v20 * 0.75) <= 4 )
    iDrawWidth = 4;
  pPanel->__vftable[1].IsWithinTraverse(this: pPanel, a2: (int)&pMaterial, a3: (int)&tileHeight, a4: v51);
  g_pMatSystemSurface->DrawSetColor_2(this: g_pMatSystemSurface, a2: 255, a3: 255, a4: 255, a5: 255);
  v22 = y;
  v23 = x;
  g_pMatSystemSurface->DrawOutlinedRect(
    this: g_pMatSystemSurface,
    a2: x + 1,
    a3: y + 1,
    a4: (int)pMaterial + x - 2,
    a5: tileHeight + y - 2);
  v24 = v23 + 20;
  v25 = v22 + 10;
  y = v25;
  v26 = strlen(szTextureFile);
  tileHeight = (int)"...";
  if ( v26 > 22 )
  {
    pMaterial = (IMaterial *)&szTextureFile[v26 - 22];
  }
  else
  {
    tileHeight = (int)defaultValue;
    pMaterial = (IMaterial *)szTextureFile;
  }
  memset(chSizeBuf, 0, sizeof(chSizeBuf));
  if ( iTxSize < 0 )
    chSizeBuf[0] = 45;
  else
    FmtCommaNumber(pchBuffer: chSizeBuf, uiNumber: iTxSize);
  v27 = _S2_1;
  if ( (_S2_1 & 1) == 0 )
  {
    v27 = _S2_1 | 1;
    _S2_1 |= 1u;
    clrLblNormal = (Color)-15125991;
  }
  if ( (v27 & 2) == 0 )
  {
    v27 |= 2u;
    _S2_1 = v27;
    clrLblWarn = (Color)-16757941;
  }
  if ( (v27 & 4) == 0 )
  {
    _S2_1 = v27 | 4;
    clrLblError = (Color)-16777016;
  }
  if ( KeyValues::GetInt(this: (KeyValues *)iTile, keyName: "SpecialTx", defaultValue: 0) == 0
    && g_warn_enable
    && ShallWarnTx(kv: (KeyValues *)iTile, tx: pMatTexture) )
  {
    v28 = clrLblWarn;
    HIBYTE(iTile) = 1;
  }
  else
  {
    v28 = clrLblNormal;
    HIBYTE(iTile) = 0;
  }
  ((void (__thiscall *)(_DWORD, _DWORD))g_pMatSystemSurface->DrawSetColor)(a1: g_pMatSystemSurface, a2: v28);
  g_pMatSystemSurface->DrawFilledRect(this: g_pMatSystemSurface, a2: v24 - 10, a3: v25, a4: v24 + 202, a5: v25 + 35);
  memset(chInfoText, 0, sizeof(chInfoText));
  v29 = (pMatTexture->GetFlags(this: pMatTexture) & 0x1300) == 0;
  v30 = "***";
  if ( v29 )
    v30 = defaultValue;
  v31 = (const char *)orgTxXA;
  sprintf(
    string: chInfoText,
    format: "%s Kb  %dx%d  %.*s%s  %s",
    chSizeBuf,
    iTxWidth,
    iTxHeight,
    extTxHeight,
    szTxFormat,
    (const char *)orgTxXA,
    v30);
  v32 = g_pMatSystemSurface->__vftable;
  Think = pPanel->__vftable[1].Think;
  memset(iTextMargins, 0, sizeof(iTextMargins));
  v34 = ((int (__thiscall *)(vgui::Panel *))Think)(a1: pPanel);
  x = v32->GetFontTall(this: g_pMatSystemSurface, a2: v34);
  memset(&iTextLen[1], 0, 12);
  iTextLen[0] = strlen(chSizeBuf) + 5;
  strchr(string: (unsigned __int8 *)chInfoText, chr: 0x78u);
  for ( i = 1 - (_DWORD)chInfoText + v35; chInfoText[i] != 32; ++i )
    ;
  iTextLen[1] = i + 1;
  iTextLen[2] = i + 1 + strlen(v31) + extTxHeight + 2;
  iTextLen[3] = strlen(chInfoText);
  for ( j = 0; j < 4; ++j )
  {
    v38 = g_pMatSystemSurface->__vftable;
    v39 = ((int (__thiscall *)(vgui::Panel *, const char *, int, char *))pPanel->__vftable[1].Think)(
            a1: pPanel,
            a2: "%.*s",
            a3: iTextLen[j],
            a4: chInfoText);
    iTextMargins[j] = ((int (__cdecl *)(IMatSystemSurface *, int))v38->DrawTextLen)(a1: g_pMatSystemSurface, a2: v39);
  }
  if ( HIBYTE(iTile) != 0 )
  {
    ((void (__thiscall *)(_DWORD, _DWORD))g_pMatSystemSurface->DrawSetColor)(a1: g_pMatSystemSurface, a2: clrLblError);
    v40 = iTextMargins[0];
    v41 = y;
    if ( iTxSize > g_warn_texkbytes )
      g_pMatSystemSurface->DrawFilledRect(
        this: g_pMatSystemSurface,
        a2: v24 - 2,
        a3: x + y + 1,
        a4: iTextMargins[0] + v24 - 5,
        a5: y + 35);
    if ( iTxWidth > g_warn_texdimensions || iTxHeight > g_warn_texdimensions )
      g_pMatSystemSurface->DrawFilledRect(
        this: g_pMatSystemSurface,
        a2: v40 + v24 - 2,
        a3: x + v41 + 1,
        a4: iTextMargins[1] + v24 - 1,
        a5: v41 + 35);
    v42 = iTextMargins[2];
    if ( strcmp(szTxFormat, "DXT1") != 0 && strcmp(szTxFormat, "DXT5") != 0 )
      g_pMatSystemSurface->DrawFilledRect(
        this: g_pMatSystemSurface,
        a2: iTextMargins[1] + v24 + 2,
        a3: x + v41 + 1,
        a4: iTextMargins[2] + v24 - 1,
        a5: v41 + 35);
    if ( (pMatTexture->GetFlags(this: pMatTexture) & 0x1300) != 0 )
      g_pMatSystemSurface->DrawFilledRect(
        this: g_pMatSystemSurface,
        a2: v42 + v24 + 3,
        a3: x + v41 + 1,
        a4: iTextMargins[3] + v24 + 2,
        a5: v41 + 35);
  }
  else
  {
    v41 = y;
  }
  v43 = g_pMatSystemSurface->__vftable;
  v44 = ((int (__thiscall *)(vgui::Panel *, int, int, int, int, int, int, int, int, const char *, int, IMaterial *, char *))pPanel->__vftable[1].Think)(
          a1: pPanel,
          a2: v24,
          a3: v41,
          a4: 192,
          a5: 35,
          a6: 255,
          a7: 255,
          a8: 255,
          a9: 255,
          a10: "%s%s\n%s",
          a11: tileHeight,
          a12: pMaterial,
          a13: chInfoText);
  ((void (__cdecl *)(IMatSystemSurface *, int))v43->DrawColoredTextRect)(a1: g_pMatSystemSurface, a2: v44);
  v29 = LOBYTE(pPanel[1].m_hKeyBindingsContext) == 0;
  y = v41 + 45;
  if ( v29 || (v45 = _V_stricmp(s1: szTxFormat, s2: "DXT1"), HIBYTE(iTile) = 1, v45 == 0) )
    HIBYTE(iTile) = 0;
  v46 = 0;
  x = 192;
  extTxHeight = 192;
  orgTxXA = 0;
  iTxSize = 0;
  if ( HIBYTE(iTile) != 0 )
  {
    if ( iTxWidth < 2 * iTxHeight )
    {
      v24 -= 6;
      if ( iTxHeight < 2 * iTxWidth )
      {
        extTxHeight = 96;
        iTxSize = 106;
        v46 = 48;
        x = 96;
        if ( iDrawWidth > 96 )
        {
          iDrawWidth /= 2;
          iDrawHeight /= 2;
        }
      }
      else
      {
        x = 96;
        orgTxXA = 106;
      }
    }
    else
    {
      extTxHeight = 96;
      iTxSize = 106;
    }
  }
  pMaterial = UseDebugMaterial(szMaterial: "debug/debugtexturecolor", pMatTexture, pRestoreVars: &auto_matsysdebugmode);
  if ( pMaterial != nullptr )
  {
    ((void (__thiscall *)(IMatSystemSurface *, int, int, int))g_pMatSystemSurface->DrawSetColor_2)(
      a1: g_pMatSystemSurface,
      a2: 255,
      a3: 255,
      a4: 255);
    y1 = (iDrawHeight + extTxHeight) / 2;
    tileHeight = y1 + y;
    v47 = (iDrawWidth + x) / 2;
    iTxHeight = v24 + v47 + v46;
    v55 = (extTxHeight - iDrawHeight) / 2;
    szTxFormat = (const char *)(y + v55);
    iTxWidth = (x - iDrawWidth) / 2;
    x = v24 + v46 + iTxWidth;
    g_pMatSystemSurface->DrawOutlinedRect(
      this: g_pMatSystemSurface,
      a2: x - 2,
      a3: y + v55 - 2,
      a4: iTxHeight + 2,
      a5: y1 + y + 2);
    RenderTexturedRect(pPanel, pMaterial, x, y: (int)szTxFormat, x1: iTxHeight, y1: tileHeight, xoff: 2, yoff: 1);
    if ( HIBYTE(iTile) != 0 )
    {
      v48 = orgTxXA + v46;
      tileHeight = (int)UseDebugMaterial(
                          szMaterial: "debug/debugtexturealpha",
                          pMatTexture,
                          pRestoreVars: &auto_matsysdebugmode);
      if ( tileHeight != 0 )
      {
        y1 += iTxSize + y;
        iTxHeight = v24 + v47 + v48;
        iTile = (IMatSystemSurface_vtbl *)(y + iTxSize + v55);
        x = v24 + v48 + iTxWidth;
        g_pMatSystemSurface->DrawOutlinedRect(
          this: g_pMatSystemSurface,
          a2: x - 2,
          a3: (int)&iTile[-1].DrawTexturedSubRectGradient + 2,
          a4: iTxHeight + 2,
          a5: y1 + 2);
        RenderTexturedRect(
          pPanel,
          pMaterial: (IMaterial *)tileHeight,
          x,
          y: (int)iTile,
          x1: iTxHeight,
          y1,
          xoff: 2,
          yoff: 1);
      }
      v46 = v48 - orgTxXA;
    }
  }
  else
  {
    ((void (__thiscall *)(IMatSystemSurface *, int, _DWORD, int))g_pMatSystemSurface->DrawSetColor_2)(
      a1: g_pMatSystemSurface,
      a2: 255,
      a3: 0,
      a4: 255);
    v47 = (x + iDrawWidth) / 2;
    iTxWidth = (x - iDrawWidth) / 2;
    iTile = g_pMatSystemSurface->__vftable;
    iTile->DrawFilledRect(
      this: g_pMatSystemSurface,
      a2: v24 + v46 + iTxWidth,
      a3: y + (x - iDrawHeight) / 2,
      a4: v24 + v47 + v46,
      a5: y + (x + iDrawHeight) / 2);
  }
  if ( mat_texture_list_exclude_editing.m_pParent != nullptr
    && mat_texture_list_exclude_editing.m_pParent->m_Value.m_nValue > 0
    && materials->FindTexture(this: materials, a2: szTextureFile, a3: defaultValue, a4: 0, a5: 0) != nullptr
    && materials->GetTextureInformation(this: materials, a2: szTextureFile, a3: (MaterialTextureInfo_t *)&iTile)
    && iTile == nullptr )
  {
    g_pMatSystemSurface->DrawSetColor_2(this: g_pMatSystemSurface, a2: 200, a3: 0, a4: 0, a5: 255);
    szTxFormat = (const char *)(y + (extTxHeight - iDrawHeight) / 2);
    x = v24 + v46 + iTxWidth;
    iTile = g_pMatSystemSurface->__vftable;
    iTile->DrawFilledRect(
      this: g_pMatSystemSurface,
      a2: x - 2,
      a3: (int)(szTxFormat - 2),
      a4: v46 + v47 + v24 + 2,
      a5: (extTxHeight + iDrawHeight) / 2 + y + 2);
    v49 = g_pMatSystemSurface->__vftable;
    v50 = ((int (__thiscall *)(vgui::Panel *, int, const char *, int, int, int, int, int, int, const char *))pPanel->__vftable[1].Think)(
            a1: pPanel,
            a2: x,
            a3: szTxFormat,
            a4: iDrawWidth,
            a5: iDrawHeight,
            a6: 255,
            a7: 255,
            a8: 255,
            a9: 255,
            a10: "-X-");
    ((void (__cdecl *)(IMatSystemSurface *, int))v49->DrawColoredTextRect)(a1: g_pMatSystemSurface, a2: v50);
  }
  CAutoMatSysDebugMode::~CAutoMatSysDebugMode(this: &auto_matsysdebugmode);
}

//------------------------------------------------------------------------------
// Address: 0x1009ACB0
// Name: public: virtual void CTextureListPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTextureListPanel::Paint(CTextureListPanel *this@<ecx>, int a2@<edi>)
{
  CTextureListPanel *v2; // ebx
  KeyValues *m_p; // esi
  CRenderTextureEditor *m_pRenderTxEditor; // edi
  int m_iInfoHint; // esi
  KeyValues *m_pInfo; // edi
  const char *String; // esi
  KeyValues *FirstValue; // edi
  KeyValues *NextValue; // eax
  const char *v10; // esi
  bool v11; // al
  KeyValues *i; // esi
  int Int; // edi
  int v14; // eax
  const char *v15; // eax
  const char *v16; // eax
  int v17; // eax
  vgui::ListPanel *m_pListPanel; // ecx
  int (__thiscall *FirstItem)(vgui::ListPanel *); // eax
  int v20; // esi
  int v21; // edi
  vgui::ListPanel *v22; // ecx
  unsigned int v23; // [esp-14h] [ebp-1230h]
  int v24; // [esp-10h] [ebp-122Ch]
  _DWORD dst[1024]; // [esp+4h] [ebp-1218h] BYREF
  char pDest[256]; // [esp+1004h] [ebp-218h] BYREF
  char szFilter[4]; // [esp+1104h] [ebp-118h] BYREF
  unsigned __int8 v29[256]; // [esp+1108h] [ebp-114h] BYREF
  CRenderTextureEditor *v30; // [esp+1208h] [ebp-14h] BYREF
  int iHint; // [esp+120Ch] [ebp-10h] BYREF
  KeyValues *kv; // [esp+1210h] [ebp-Ch] BYREF
  CSmartTextureKeyValues v33; // [esp+1214h] [ebp-8h] BYREF
  KeyValues *v34; // [esp+1218h] [ebp-4h]

  v2 = this;
  if ( this->m_hFont == 0 )
    return;
  if ( mat_texture_list.m_pParent == nullptr || mat_texture_list.m_pParent->m_Value.m_nValue == 0 )
    goto LABEL_6;
  if ( !g_pMaterialSystemDebugTextureInfo->IsDebugTextureListFresh(this: g_pMaterialSystemDebugTextureInfo, a2: 1) )
  {
    this = v2;
LABEL_6:
    CTextureListPanel::UpdateTotalUsageLabel(this);
    return;
  }
  CSmartTextureKeyValues::CSmartTextureKeyValues(this: &v33);
  m_p = v33.m_p;
  if ( v33.m_p == nullptr )
  {
    CTextureListPanel::UpdateTotalUsageLabel(this: v2);
    return;
  }
  m_pRenderTxEditor = v2->m_pViewPanel->m_pRenderTxEditor;
  v30 = m_pRenderTxEditor;
  if ( s_eTxListPanelRequest == TXR_RUNNING
    && ((unsigned __int8 (__thiscall *)(CRenderTextureEditor *, int))m_pRenderTxEditor->IsVisible)(
         a1: m_pRenderTxEditor,
         a2) != 0 )
  {
    m_iInfoHint = m_pRenderTxEditor->m_iInfoHint;
    m_pInfo = m_pRenderTxEditor->m_pInfo;
    iHint = m_iInfoHint;
    v34 = m_pInfo;
    if ( m_pInfo == nullptr )
      goto LABEL_24;
    if ( m_iInfoHint == 0 )
      goto LABEL_24;
    v24 = m_iInfoHint;
    if ( ((unsigned __int8 (__thiscall *)(vgui::ListPanel *))v2->m_pListPanel->IsValidItemID)(a1: v2->m_pListPanel) == 0 )
      goto LABEL_24;
    v23 = m_iInfoHint;
    kv = (KeyValues *)((int (__thiscall *)(vgui::ListPanel *))v2->m_pListPanel->GetItem)(a1: v2->m_pListPanel);
    if ( kv == nullptr )
      goto LABEL_24;
    String = KeyValues::GetString(this: m_pInfo, keyName: "Name", defaultValue: defaultValue);
    if ( strcmp(KeyValues::GetString(this: kv, keyName: "Name", defaultValue: defaultValue), String) != 0 )
      goto LABEL_24;
    FirstValue = KeyValues::GetFirstValue(this: kv);
    NextValue = KeyValues::GetFirstValue(this: v34);
    v34 = NextValue;
    if ( FirstValue != nullptr )
    {
      while ( NextValue != nullptr )
      {
        v10 = KeyValues::GetString(this: NextValue, keyName: nullptr, defaultValue: defaultValue);
        if ( strcmp(KeyValues::GetString(this: FirstValue, keyName: nullptr, defaultValue: defaultValue), v10) != 0 )
          break;
        FirstValue = KeyValues::GetNextValue(this: FirstValue);
        NextValue = KeyValues::GetNextValue(this: v34);
        v34 = NextValue;
        if ( FirstValue == nullptr )
          goto LABEL_22;
      }
    }
    else
    {
LABEL_22:
      if ( NextValue == nullptr )
      {
LABEL_24:
        m_p = v33.m_p;
        goto LABEL_25;
      }
    }
    CRenderTextureEditor::SetDispInfo(this: v30, kv, iHint);
    goto LABEL_24;
  }
LABEL_25:
  if ( mat_texture_list_all.m_pParent != nullptr && mat_texture_list_all.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( s_eTxListPanelRequest == TXR_RUNNING )
    {
      if ( --s_nFramesForAllTextures <= 0 )
      {
        CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_texture_list.IConVar, value: 0, a2: v23, a3: v24);
        s_eTxListPanelRequest = TXR_SHOW;
      }
    }
    else
    {
      s_eTxListPanelRequest = TXR_RUNNING;
      if ( mat_texture_list_all_frames.m_pParent != nullptr )
        s_nFramesForAllTextures = mat_texture_list_all_frames.m_pParent->m_Value.m_nValue;
      else
        s_nFramesForAllTextures = 0;
    }
  }
  else if ( s_eTxListPanelRequest == TXR_SHOW )
  {
    v2->m_pListPanel->RemoveAll(this: v2->m_pListPanel);
    v2->m_pViewPanel->InvalidateLayout(this: v2->m_pViewPanel, a2: false, a3: false);
    s_eTxListPanelRequest = TXR_RUNNING;
    KeyValues::deleteThis(this: m_p);
    CTextureListPanel::UpdateTotalUsageLabel(this: v2);
    return;
  }
  memset((unsigned __int8 *)dst, value: 0, count: sizeof(dst));
  v11 = v2->m_pSpecialTexs->IsSelected(this: v2->m_pSpecialTexs);
  KeepSpecialKeys(textureList: m_p, bServiceKeys: v11);
  if ( v2->m_pFilteringChk->IsSelected(this: v2->m_pFilteringChk)
    && v2->m_pFilteringText->GetTextLength(this: v2->m_pFilteringText) != 0 )
  {
    v2->m_pFilteringText->GetText_2(this: v2->m_pFilteringText, a2: szFilter, a3: 259);
    v29[255] = 0;
    KeepKeysMatchingFilter(textureList: m_p, szFilter);
  }
  v34 = nullptr;
  for ( i = KeyValues::GetFirstSubKey(this: m_p); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Int = KeyValues::GetInt(this: i, keyName: "Size", defaultValue: 0);
    v34 = (KeyValues *)((char *)v34 + Int);
    v14 = KeyValues::GetInt(this: i, keyName: "Count", defaultValue: 0);
    if ( v14 > 1 )
      Int *= v14;
    KeyValues::SetInt(this: i, keyName: "Size", value: (Int + 511) / 1024);
    if ( v2->m_pResolveTexturePath->IsSelected(this: v2->m_pResolveTexturePath) )
    {
      memset(v29, 0, sizeof(v29));
      memset(pDest, 0, sizeof(pDest));
      v15 = KeyValues::GetString(this: i, keyName: "Name", defaultValue: defaultValue);
      V_snprintf(pDest, maxLen: 255, pFormat: "materials/%s.vtf", v15);
      v16 = g_pFileSystem->RelativePathToFullPath(
              this: g_pFileSystem,
              a2: pDest,
              a3: "game",
              a4: v29,
              a5: 255,
              a6: 0,
              a7: 0);
      if ( v16 != nullptr )
        KeyValues::SetString(this: i, keyName: "Path", value: v16);
    }
    v17 = CTextureListPanel::AddListItem(this: v2, kv: i);
    if ( v17 < 0x8000 )
      dst[v17 >> 5] |= 1 << (v17 & 0x1F);
  }
  m_pListPanel = v2->m_pListPanel;
  v2->m_numDisplayedSizeKB = ((int)&v34[14].m_sValue + 3) / 1024;
  FirstItem = m_pListPanel->FirstItem;
  v34 = nullptr;
  v20 = FirstItem(this: m_pListPanel);
  if ( v20 != v2->m_pListPanel->InvalidItemID(this: v2->m_pListPanel) )
  {
    do
    {
      v21 = v2->m_pListPanel->NextItem(this: v2->m_pListPanel, a2: v20);
      if ( v20 >= 0x8000 || ((1 << (v20 & 0x1F)) & dst[(unsigned int)v20 >> 5]) == 0 )
      {
        v2->m_pListPanel->RemoveItem(this: v2->m_pListPanel, a2: v20);
        v34 = (KeyValues *)((char *)v34 + 1);
      }
      v20 = v21;
    }
    while ( v21 != v2->m_pListPanel->InvalidItemID(this: v2->m_pListPanel) );
  }
  vgui::ListPanel::GetSortColumnEx(
    this: v2->m_pListPanel,
    iPrimarySortColumn: (int *)&kv,
    iSecondarySortColumn: (int *)&v30,
    bSortAscending: (bool *)&iHint);
  v22 = v2->m_pListPanel;
  v30 = nullptr;
  v22->SetSortColumnEx(this: v22, a2: (int)kv, a3: 0, a4: iHint);
  v2->m_pListPanel->SortList(this: v2->m_pListPanel);
  if ( v34 != nullptr )
    v2->m_pViewPanel->InvalidateLayout(this: v2->m_pViewPanel, a2: false, a3: false);
  KeyValues::deleteThis(this: v33.m_p);
  CTextureListPanel::UpdateTotalUsageLabel(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1009B250
// Name: public: virtual CRenderTextureEditor::~CRenderTextureEditor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRenderTextureEditor::~CRenderTextureEditor(CRenderTextureEditor *this)
{
  this->__vftable = (CRenderTextureEditor_vtbl *)&CRenderTextureEditor::`vftable';
  CRenderTextureEditor::SetDispInfo(this, kv: nullptr, iHint: 0);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_lstMaterials);
  if ( this->m_bufInfoText.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_bufInfoText.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_bufInfoText.m_Memory.m_pMemory);
      this->m_bufInfoText.m_Memory.m_pMemory = nullptr;
    }
    this->m_bufInfoText.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x1009B610
// Name: void MatViewOverride::DisplaySelectedTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MatViewOverride::DisplaySelectedTextures(CStatTime *ecx0)
{
  double v1; // st7
  ITexture *v2; // eax
  int m_Size; // esi
  unsigned __int16 v4; // si
  unsigned __int16 v5; // bx
  UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  int v7; // edi
  UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t,unsigned short> *v8; // eax
  const char *v9; // eax
  IMaterial *v10; // eax
  IMaterial *v11; // esi
  int v12; // eax
  IMaterial_vtbl *v13; // edx
  int v14; // edi
  int i; // ebx
  int v16; // ecx
  ITexture *v17; // esi
  const char *v18; // eax
  CUtlSymbol *v19; // eax
  int *v20; // ecx
  int v21; // edx
  const char *v22; // eax
  float v23; // eax
  int v24; // edx
  MatViewOverride::ViewParamsLast::VarMap *p_elem; // ebx
  int v26; // eax
  const char *v27; // eax
  IMaterial *v28; // eax
  IMaterial *v29; // esi
  int v30; // eax
  IMaterial_vtbl *v31; // edx
  int v32; // eax
  int v33; // esi
  int j; // edi
  const char *v35; // eax
  unsigned __int16 v36; // ax
  MatViewOverride::ViewParamsLast::TxInfo *v37; // eax
  ITexture *pTx; // eax
  int v39; // edi
  int v40; // ebx
  MatViewOverride::ViewParamsLast::VarMap *v41; // esi
  CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t search; // [esp+4h] [ebp-54h] BYREF
  CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t insert; // [esp+28h] [ebp-30h] BYREF
  MatViewOverride::ViewParamsLast::TxInfo txinfo; // [esp+34h] [ebp-24h]
  ITexture *txEmpty; // [esp+3Ch] [ebp-1Ch]
  int kEnd; // [esp+40h] [ebp-18h]
  MatViewOverride::ViewParamsLast::VarMap *vars; // [esp+44h] [ebp-14h]
  int idx; // [esp+48h] [ebp-10h]
  CUtlSymbol symVarName; // [esp+4Ch] [ebp-Ch] BYREF
  int numParams; // [esp+50h] [ebp-8h] BYREF
  int bRemovedSelection; // [esp+54h] [ebp-4h] BYREF

  if ( MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree.m_NumElements != 0 )
  {
    v1 = _Plat_FloatTime(this: ecx0);
    *(float *)&idx = v1;
    if ( v1 >= MatViewOverride::s_viewParamsLast.flTime
      && MatViewOverride::s_viewParamsLast.flTime + 0.4 > v1
      && MatViewOverride::s_viewParamsReq.lstMaterials.m_Size != 0 )
    {
      return;
    }
    LODWORD(MatViewOverride::s_viewParamsLast.flTime) = idx;
    MatViewOverride::s_viewParamsLast.bHighlighted = !MatViewOverride::s_viewParamsLast.bHighlighted;
  }
  else
  {
    if ( MatViewOverride::s_viewParamsReq.lstMaterials.m_Size == 0 )
      return;
    MatViewOverride::s_viewParamsLast.flTime = _Plat_FloatTime(this: ecx0);
    MatViewOverride::s_viewParamsLast.bHighlighted = false;
  }
  v2 = materials->FindTexture(this: materials, a2: "debugempty", a3: defaultValue, a4: 0, a5: 0);
  m_Size = MatViewOverride::s_viewParamsReq.lstMaterials.m_Size;
  txEmpty = v2;
  *(float *)&idx = 0.0;
  kEnd = MatViewOverride::s_viewParamsReq.lstMaterials.m_Size;
  if ( MatViewOverride::s_viewParamsReq.lstMaterials.m_Size > 0 )
  {
    do
    {
      v4 = MatViewOverride::s_viewParamsReq.lstMaterials.m_Memory.m_pMemory[idx];
      search.elem.m_Tree.m_LessFunc.m_LessFunc = CDefOps<unsigned short>::LessFunc;
      memset(&search.elem.m_Tree.m_Elements, 0, sizeof(search.elem.m_Tree.m_Elements));
      *(_DWORD *)&search.elem.m_Tree.m_Root = 0xFFFF;
      *(_DWORD *)&search.elem.m_Tree.m_FirstFree = -1;
      search.elem.m_Tree.m_pElements = nullptr;
      search.key = v4;
      v5 = CUtlRBTree<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
             this: &MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree,
             &search);
      CUtlRBTree<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &search.elem.m_Tree);
      m_pMemory = search.elem.m_Tree.m_Elements.m_pMemory;
      search.elem.m_Tree.m_FirstFree = -1;
      if ( search.elem.m_Tree.m_Elements.m_nGrowSize >= 0 )
      {
        if ( search.elem.m_Tree.m_Elements.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.elem.m_Tree.m_Elements.m_pMemory);
          m_pMemory = nullptr;
          search.elem.m_Tree.m_Elements.m_pMemory = nullptr;
        }
        search.elem.m_Tree.m_Elements.m_nAllocationCount = 0;
      }
      search.elem.m_Tree.m_LastAlloc.index = -1;
      if ( search.elem.m_Tree.m_Elements.m_nGrowSize >= 0 && m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      if ( v5 == 0xFFFF )
      {
        *(_DWORD *)&search.elem.m_Tree.m_Root = 0xFFFF;
        search.elem.m_Tree.m_LessFunc.m_LessFunc = CDefOps<unsigned short>::LessFunc;
        memset(&search.elem.m_Tree.m_Elements, 0, sizeof(search.elem.m_Tree.m_Elements));
        *(_DWORD *)&search.elem.m_Tree.m_FirstFree = -1;
        search.elem.m_Tree.m_pElements = nullptr;
        search.key = v4;
        v7 = CUtlRBTree<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
               this: &MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree,
               insert: &search);
        CUtlRBTree<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &search.elem.m_Tree);
        v8 = search.elem.m_Tree.m_Elements.m_pMemory;
        search.elem.m_Tree.m_FirstFree = -1;
        if ( search.elem.m_Tree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( search.elem.m_Tree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.elem.m_Tree.m_Elements.m_pMemory);
            v8 = nullptr;
            search.elem.m_Tree.m_Elements.m_pMemory = nullptr;
          }
          search.elem.m_Tree.m_Elements.m_nAllocationCount = 0;
        }
        search.elem.m_Tree.m_LastAlloc.index = -1;
        if ( search.elem.m_Tree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v8 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
            search.elem.m_Tree.m_Elements.m_pMemory = nullptr;
          }
          search.elem.m_Tree.m_Elements.m_nAllocationCount = 0;
        }
        vars = &MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem;
        HIWORD(bRemovedSelection) = v4;
        v9 = CUtlSymbol::String(this: (CUtlSymbol *)&bRemovedSelection + 1);
        v10 = materials->FindMaterial(this: materials, a2: v9, a3: "Other textures", a4: 0, a5: 0);
        v11 = v10;
        if ( v10 != nullptr )
        {
          v12 = v10->ShaderParamCount(this: v10);
          v13 = v11->__vftable;
          bRemovedSelection = v12;
          v14 = 0;
          for ( i = (int)v13->GetShaderParams(this: v11); v14 < bRemovedSelection; ++v14 )
          {
            v16 = *(_DWORD *)(i + 4 * v14);
            if ( (*(_BYTE *)(v16 + 28) & 0xF) == 3 )
            {
              v17 = (ITexture *)(**(int (__thiscall ***)(int))v16)(a1: v16);
              if ( v17 != nullptr && !v17->IsError(this: v17) )
              {
                v18 = (const char *)v17->GetName(this: v17);
                v19 = CUtlSymbol::CUtlSymbol(this: &symVarName, pStr: v18);
                v20 = *(int **)(i + 4 * v14);
                v21 = *v20;
                txinfo.name = (CUtlSymbol)v19->m_Id;
                v22 = (const char *)(*(int (__thiscall **)(int *))(v21 + 8))(a1: v20);
                insert.key = CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&numParams + 1, pStr: v22)->m_Id;
                insert.elem.pTx = v17;
                insert.elem.name.m_Id = txinfo.name.m_Id;
                CUtlRBTree<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
                  this: &vars->m_Tree,
                  &insert);
              }
            }
          }
        }
      }
      ++idx;
    }
    while ( idx < kEnd );
    m_Size = MatViewOverride::s_viewParamsReq.lstMaterials.m_Size;
  }
  LODWORD(v23) = CUtlRBTree<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree);
  *(float *)&idx = v23;
  if ( LOWORD(v23) != 0xFFFF )
  {
    while ( 1 )
    {
      v24 = LOWORD(v23);
      p_elem = &MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree.m_Elements.m_pMemory[v24].m_Data.elem;
      v26 = 0;
      if ( m_Size <= 0 )
      {
LABEL_40:
        v26 = -1;
      }
      else
      {
        while ( MatViewOverride::s_viewParamsReq.lstMaterials.m_Memory.m_pMemory[v26] != MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree.m_Elements.m_pMemory[v24].m_Data.key )
        {
          if ( ++v26 >= m_Size )
            goto LABEL_40;
        }
      }
      HIWORD(numParams) = MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree.m_Elements.m_pMemory[v24].m_Data.key;
      HIBYTE(bRemovedSelection) = v26 < 0;
      v27 = CUtlSymbol::String(this: (CUtlSymbol *)&numParams + 1);
      v28 = materials->FindMaterial(this: materials, a2: v27, a3: "Other textures", a4: 0, a5: 0);
      v29 = v28;
      if ( v28 != nullptr )
      {
        v30 = v28->ShaderParamCount(this: v28);
        v31 = v29->__vftable;
        numParams = v30;
        v32 = (int)v31->GetShaderParams(this: v29);
        v33 = 0;
        for ( j = v32; v33 < numParams; ++v33 )
        {
          v35 = (const char *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(j + 4 * v33) + 8))(a1: *(_DWORD *)(j + 4 * v33));
          CUtlSymbol::CUtlSymbol(this: &symVarName, pStr: v35);
          insert.elem.name.m_Id = -1;
          insert.key = symVarName.m_Id;
          v36 = CUtlRBTree<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                  this: &p_elem->m_Tree,
                  search: &insert);
          if ( v36 != 0xFFFF )
          {
            v37 = &p_elem->m_Tree.m_Elements.m_pMemory[v36].m_Data.elem;
            if ( !MatViewOverride::s_viewParamsLast.bHighlighted || HIBYTE(bRemovedSelection) != 0 )
              pTx = v37->pTx;
            else
              pTx = txEmpty;
            (*(void (__thiscall **)(_DWORD, ITexture *))(**(_DWORD **)(j + 4 * v33) + 60))(
              a1: *(_DWORD *)(j + 4 * v33),
              a2: pTx);
          }
        }
      }
      if ( HIBYTE(bRemovedSelection) != 0 )
      {
        v39 = (unsigned __int16)idx;
        idx = CUtlRBTree<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                this: &MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree,
                i: idx);
        if ( (_WORD)v39 != 0xFFFF )
        {
          CUtlRBTree<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
            this: &MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree,
            elem: v39);
          v40 = v39;
          v41 = &MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree.m_Elements.m_pMemory[v39].m_Data.elem;
          CUtlRBTree<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &v41->m_Tree);
          v41->m_Tree.m_FirstFree = -1;
          if ( v41->m_Tree.m_Elements.m_nGrowSize >= 0 )
          {
            if ( v41->m_Tree.m_Elements.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41->m_Tree.m_Elements.m_pMemory);
              v41->m_Tree.m_Elements.m_pMemory = nullptr;
            }
            v41->m_Tree.m_Elements.m_nAllocationCount = 0;
          }
          v41->m_Tree.m_LastAlloc.index = -1;
          if ( v41->m_Tree.m_Elements.m_nGrowSize >= 0 )
          {
            if ( v41->m_Tree.m_Elements.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41->m_Tree.m_Elements.m_pMemory);
              v41->m_Tree.m_Elements.m_pMemory = nullptr;
            }
            v41->m_Tree.m_Elements.m_nAllocationCount = 0;
          }
          MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree.m_Elements.m_pMemory[v40].m_Left = v39;
          MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree.m_Elements.m_pMemory[v40].m_Right = MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree.m_FirstFree;
          --MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree.m_NumElements;
          MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree.m_FirstFree = v39;
        }
      }
      else
      {
        idx = CUtlRBTree<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                this: &MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree,
                i: idx);
      }
      if ( (_WORD)idx == 0xFFFF )
        break;
      m_Size = MatViewOverride::s_viewParamsReq.lstMaterials.m_Size;
      LOWORD(v23) = idx;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009BB40
// Name: void CL_TextureListPanel_ClearState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CL_TextureListPanel_ClearState(CStatTime *ecx0)
{
  MatViewOverride::s_viewParamsReq.lstMaterials.m_Size = 0;
  MatViewOverride::DisplaySelectedTextures(ecx0);
}

//------------------------------------------------------------------------------
// Address: 0x1009BB50
// Name: void VGui_UpdateTextureListPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VGui_UpdateTextureListPanel(CStatTime *this)
{
  int v1; // eax
  int v2; // eax
  int m_nValue; // eax
  int v4; // eax
  bool v5; // bl
  bool (__thiscall *IsVisible)(vgui::Panel *); // edx
  unsigned int v7; // [esp-18h] [ebp-5Ch]
  BOOL v8; // [esp-14h] [ebp-58h]
  con_nprint_s info; // [esp+0h] [ebp-44h] BYREF
  char kb1[20]; // [esp+18h] [ebp-2Ch] BYREF
  char kb2[20]; // [esp+2Ch] [ebp-18h] BYREF
  unsigned int bShouldDrawTxListPanel; // [esp+40h] [ebp-4h]

  if ( mat_show_texture_memory_usage.m_pParent != nullptr
    && mat_show_texture_memory_usage.m_pParent->m_Value.m_nValue != 0 )
  {
    info.fixed_width_font = true;
    v1 = ((int (__thiscall *)(IDebugTextureInfo *, int, int, int, int, int, _DWORD, _DWORD))g_pMaterialSystemDebugTextureInfo->GetTextureMemoryUsed)(
           a1: g_pMaterialSystemDebugTextureInfo,
           a2: 1,
           a3: 4,
           a4: 1045220557,
           a5: 1065353216,
           a6: 1056964608,
           a7: 0,
           a8: *(_DWORD *)&info.fixed_width_font);
    FmtCommaNumber(pchBuffer: kb1, uiNumber: (v1 + 511) / 1024);
    v2 = g_pMaterialSystemDebugTextureInfo->GetTextureMemoryUsed(
           this: g_pMaterialSystemDebugTextureInfo,
           a2: MEMORY_TOTAL_LOADED);
    FmtCommaNumber(pchBuffer: kb2, uiNumber: (v2 + 511) / 1024);
    Con_NXPrintf(&info, fmt: "Texture Memory Usage: %s Kb / %s Kb", kb1, kb2);
  }
  MatViewOverride::DisplaySelectedTextures(ecx0: this);
  if ( mat_texture_list_all.m_pParent != nullptr )
    m_nValue = mat_texture_list_all.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  g_pMaterialSystemDebugTextureInfo->EnableGetAllTextures(this: g_pMaterialSystemDebugTextureInfo, a2: m_nValue != 0);
  if ( mat_texture_list.m_pParent != nullptr )
    v4 = mat_texture_list.m_pParent->m_Value.m_nValue;
  else
    v4 = 0;
  v8 = v4 > 0;
  ((void (__thiscall *)(IDebugTextureInfo *))g_pMaterialSystemDebugTextureInfo->EnableDebugTextureList)(a1: g_pMaterialSystemDebugTextureInfo);
  v5 = g_pTextureListPanel->ShouldDraw(this: g_pTextureListPanel);
  IsVisible = g_pTextureListPanel->IsVisible;
  LOBYTE(bShouldDrawTxListPanel) = v5;
  if ( IsVisible(this: g_pTextureListPanel) != v5 )
  {
    v7 = bShouldDrawTxListPanel;
    ((void (__thiscall *)(CTextureListPanel *))g_pTextureListPanel->SetVisible)(a1: g_pTextureListPanel);
    if ( v5 )
    {
      mat_texture_list_on_f();
    }
    else
    {
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_texture_list.IConVar, value: 0, a2: v7, a3: v8);
      s_eTxListPanelRequest = TXR_HIDE;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10165820
// Name: public: static bool CDefOps<unsigned short>::LessFunc(unsigned short const __near &,unsigned short const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDefOps<unsigned short>::LessFunc(const unsigned __int16 *lhs, const unsigned __int16 *rhs)
{
  return *lhs < *rhs;
}

//------------------------------------------------------------------------------
// Address: 0x102ACC00
// Name: public: virtual unsigned long vgui::TileViewPanelEx::GetFont(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::TileViewPanelEx::GetFont(vgui::Menu *this)
{
  return this->m_MenuItems.m_ElementCount;
}

//------------------------------------------------------------------------------
// Address: 0x102D2480
// Name: public: virtual unsigned long CRenderTextureEditor::GetFont(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PropertySheet *__thiscall CRenderTextureEditor::GetFont(vgui::PropertyDialog *this)
{
  return this->_propertySheet;
}

//------------------------------------------------------------------------------
// Address: 0x10313D80
// Name: MatViewOverride::_dynamic_initializer_for__s_viewParamsReq__
// Source: json
//------------------------------------------------------------------------------
int MatViewOverride::_dynamic_initializer_for__s_viewParamsReq__()
{
  return atexit(func: MatViewOverride::_dynamic_atexit_destructor_for__s_viewParamsReq__);
}

//------------------------------------------------------------------------------
// Address: 0x10313D90
// Name: MatViewOverride::_dynamic_initializer_for__s_viewParamsLast__
// Source: json
//------------------------------------------------------------------------------
int MatViewOverride::_dynamic_initializer_for__s_viewParamsLast__()
{
  return atexit(func: MatViewOverride::_dynamic_atexit_destructor_for__s_viewParamsLast__);
}

//------------------------------------------------------------------------------
// Address: 0x10322A20
// Name: MatViewOverride::_dynamic_atexit_destructor_for__s_viewParamsReq__
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatViewOverride::_dynamic_atexit_destructor_for__s_viewParamsReq__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&MatViewOverride::s_viewParamsReq);
}

//------------------------------------------------------------------------------
// Address: 0x10322A30
// Name: MatViewOverride::_dynamic_atexit_destructor_for__s_viewParamsLast__
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatViewOverride::_dynamic_atexit_destructor_for__s_viewParamsLast__()
{
  CUtlRBTree<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10058410
// Name: public: void CUtlMemory<bool,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<bool,int>::Grow(CUtlMemory<char,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  char *m_pMemory; // edx

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 32;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (char *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: m_nAllocationCount);
    else
      this->m_pMemory = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10091160
// Name: public: static char const __near * vgui::TileViewPanelEx::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl vgui::TileViewPanelEx::GetPanelClassName()
{
  return "TileViewPanelEx";
}

//------------------------------------------------------------------------------
// Address: 0x10091170
// Name: public: virtual void vgui::TileViewPanelEx::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TileViewPanelEx::SetFont(vgui::TileViewPanelEx *this, unsigned int hFont)
{
  vgui::TileViewPanelEx_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_hFont = hFont;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x10091190
// Name: public: virtual int vgui::TileViewPanelEx::HitTest(int,int,int __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::TileViewPanelEx::HitTest(vgui::TileViewPanelEx *this, int x, int y, int *iTile)
{
  int m_li_colVisible; // ecx
  int v7; // edi
  int v8; // eax
  int v9; // ecx

  *iTile = -1;
  if ( !this->ComputeLayoutInfo(this) )
    return 0;
  m_li_colVisible = this->m_li_colVisible;
  v7 = x / this->m_li_wideItem;
  v8 = y / this->m_li_tallItem;
  if ( v7 >= m_li_colVisible )
    return 0;
  if ( v8 > this->m_li_rowVisible )
    return 0;
  v9 = v7 + this->m_li_startTile + v8 * m_li_colVisible;
  if ( v9 >= this->m_li_endTile )
    return 0;
  *iTile = v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10091210
// Name: public: virtual bool vgui::TileViewPanelEx::GetTileOrg(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::TileViewPanelEx::GetTileOrg(vgui::TileViewPanelEx *this, int iTile, int *x, int *y)
{
  if ( this->m_li_colVisible <= 0 )
    return 0;
  if ( iTile < this->m_li_startTile || iTile >= this->m_li_endTile )
    return 0;
  *x = this->m_li_wideItem * ((iTile - this->m_li_startTile) % this->m_li_colVisible);
  *y = this->m_li_tallItem * ((iTile - this->m_li_startTile) / this->m_li_colVisible);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10091280
// Name: protected: virtual void vgui::TileViewPanelEx::OnMouseWheeled(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TileViewPanelEx::OnMouseWheeled(vgui::TileViewPanelEx *this, int delta)
{
  int v3; // eax

  if ( this->m_hbar->IsVisible(this: this->m_hbar) )
  {
    v3 = this->m_hbar->GetValue(this: this->m_hbar);
    this->m_hbar->SetValue(this: this->m_hbar, a2: v3 - delta);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100912D0
// Name: protected: virtual void vgui::TileViewPanelEx::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TileViewPanelEx::PerformLayout(vgui::TileViewPanelEx *this)
{
  int v2; // ebx
  int v3; // eax
  int v4; // ecx
  int v5; // edi
  int v6; // eax
  int tall; // [esp+8h] [ebp-10h] BYREF
  int tallItem; // [esp+Ch] [ebp-Ch] BYREF
  int wideItem; // [esp+10h] [ebp-8h] BYREF
  int wide; // [esp+14h] [ebp-4h] BYREF

  v2 = this->GetNumTiles(this);
  this->m_hbar->SetVisible(this: this->m_hbar, a2: false);
  vgui::Panel::GetSize(this, &wide, &tall);
  v3 = vgui::Panel::GetWide(this: this->m_hbar);
  wide -= v3;
  vgui::Panel::SetPos(this: this->m_hbar, x: wide - 2, y: 0);
  vgui::Panel::SetTall(this: this->m_hbar, tall);
  if ( v2 != 0 )
  {
    wideItem = 1;
    tallItem = 1;
    this->GetTileSize(this, a2: &wideItem, a3: &tallItem);
    if ( wideItem != 0 && tallItem != 0 )
    {
      v4 = wide / wideItem;
      v5 = tall / tallItem;
      if ( tall / tallItem > 0 && v4 > 0 )
      {
        v6 = (v4 + v2 - 1) / v4;
        if ( v6 > v5 )
        {
          this->m_hbar->SetRange(this: this->m_hbar, a2: 0, a3: v6);
          this->m_hbar->SetRangeWindow(this: this->m_hbar, a2: v5);
          this->m_hbar->SetButtonPressedScrollValue(this: this->m_hbar, a2: 1);
          this->m_hbar->SetVisible(this: this->m_hbar, a2: true);
          this->m_hbar->InvalidateLayout(this: this->m_hbar, a2: false, a3: false);
          this->m_hbar->GetValue(this: this->m_hbar);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10091410
// Name: protected: virtual bool vgui::TileViewPanelEx::ComputeLayoutInfo(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall vgui::TileViewPanelEx::ComputeLayoutInfo(vgui::TileViewPanelEx *this)
{
  int v2; // eax
  vgui::TileViewPanelEx_vtbl *v4; // edx
  void (__thiscall *GetTileSize)(vgui::TileViewPanelEx *, int *, int *); // eax
  int m_li_wideItem; // ecx
  int m_li_tallItem; // ebx
  int v8; // ecx
  int v9; // eax
  int v10; // edi
  int v11; // eax
  int m_li_numTiles; // ecx
  int v13; // eax

  v2 = this->GetNumTiles(this);
  this->m_li_numTiles = v2;
  if ( v2 == 0 )
    return 0;
  vgui::Panel::GetSize(this, wide: &this->m_li_wide, tall: &this->m_li_tall);
  this->m_li_wide -= vgui::Panel::GetWide(this: this->m_hbar);
  v4 = this->__vftable;
  this->m_li_tallItem = 1;
  GetTileSize = v4->GetTileSize;
  this->m_li_wideItem = 1;
  GetTileSize(this, a2: &this->m_li_wideItem, a3: &this->m_li_tallItem);
  m_li_wideItem = this->m_li_wideItem;
  if ( m_li_wideItem == 0 )
    return 0;
  m_li_tallItem = this->m_li_tallItem;
  if ( m_li_tallItem == 0 )
    return 0;
  v8 = this->m_li_wide / m_li_wideItem;
  v9 = this->m_li_tall / m_li_tallItem;
  this->m_li_colVisible = v8;
  v10 = v9;
  this->m_li_rowVisible = v9;
  if ( v9 <= 0 || v8 <= 0 )
    return 0;
  v11 = (this->m_li_numTiles + v8 - 1) / v8;
  this->m_li_numVisibleTiles = v8 * v10;
  this->m_li_startTile = 0;
  this->m_li_rowNeeded = v11;
  if ( v11 > v10 )
    this->m_li_startTile = this->m_hbar->GetValue(this: this->m_hbar) * this->m_li_colVisible;
  m_li_numTiles = this->m_li_numTiles;
  if ( this->m_li_startTile >= m_li_numTiles )
    this->m_li_startTile = m_li_numTiles - this->m_li_numVisibleTiles;
  if ( this->m_li_startTile < 0 )
    this->m_li_startTile = 0;
  v13 = this->m_li_startTile + this->m_li_colVisible + this->m_li_numVisibleTiles;
  this->m_li_endTile = v13;
  if ( v13 > m_li_numTiles )
    this->m_li_endTile = m_li_numTiles;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10091560
// Name: protected: virtual void vgui::TileViewPanelEx::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TileViewPanelEx::Paint(vgui::TileViewPanelEx *this)
{
  int i; // edi

  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  if ( this->ComputeLayoutInfo(this) )
  {
    for ( i = this->m_li_startTile; i < this->m_li_endTile; ++i )
      this->RenderTile(
        this,
        a2: i,
        a3: (i - this->m_li_startTile) % this->m_li_colVisible * this->m_li_wideItem,
        a4: (i - this->m_li_startTile) / this->m_li_colVisible * this->m_li_tallItem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100915D0
// Name: protected: virtual void vgui::TileViewPanelEx::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TileViewPanelEx::ApplySchemeSettings(vgui::TileViewPanelEx *this, vgui::IScheme *pScheme)
{
  vgui::IScheme *v2; // edi
  vgui::TileViewPanelEx_vtbl *v4; // ebx
  Color *v5; // eax
  vgui::TileViewPanelEx_vtbl *v6; // ebx
  int v7; // eax
  vgui::TileViewPanelEx_vtbl *v8; // ebx
  bool (__thiscall *IsProportional)(vgui::IClientPanel *); // edx
  bool v10; // al
  int v11; // eax

  v2 = pScheme;
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  v4 = this->__vftable;
  v5 = this->GetSchemeColor_2(this, result: &pScheme, a3: "ListPanel.BgColor", a4: v2);
  ((void (__thiscall *)(vgui::TileViewPanelEx *, _DWORD))v4->SetBgColor)(a1: this, a2: *v5);
  v6 = this->__vftable;
  v7 = (int)v2->GetBorder(this: v2, a2: "ButtonDepressedBorder");
  v6->SetBorder(this, a2: (vgui::IBorder *)v7);
  v8 = this->__vftable;
  IsProportional = this->IsProportional;
  pScheme = (vgui::IScheme *)v2->__vftable;
  v10 = IsProportional(this);
  v11 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pScheme[3].__vftable)(a1: v2, a2: "Default", a3: v10);
  v8->SetFont(this, a2: v11);
}

//------------------------------------------------------------------------------
// Address: 0x10091660
// Name: ShallWarnTx
// Source: json
//------------------------------------------------------------------------------
bool __usercall ShallWarnTx@<al>(KeyValues *kv@<esi>, ITexture *tx@<ecx>)
{
  const char *String; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax

  if ( tx == nullptr )
    return false;
  if ( (tx->GetFlags(this: tx) & 0x1300) != 0 )
    return true;
  String = KeyValues::GetString(this: kv, keyName: "Format", defaultValue: defaultValue);
  if ( _V_stricmp(s1: "DXT1", s2: String) != 0 )
  {
    v4 = KeyValues::GetString(this: kv, keyName: "Format", defaultValue: defaultValue);
    if ( _V_stricmp(s1: "DXT5", s2: v4) != 0 )
    {
      v5 = KeyValues::GetString(this: kv, keyName: "Format", defaultValue: defaultValue);
      if ( _V_stricmp(s1: "ATI1N", s2: v5) != 0 )
      {
        v6 = KeyValues::GetString(this: kv, keyName: "Format", defaultValue: defaultValue);
        if ( _V_stricmp(s1: "ATI2N", s2: v6) != 0 )
          return true;
      }
    }
  }
  if ( KeyValues::GetInt(this: kv, keyName: "Size", defaultValue: 0) > g_warn_texkbytes
    || KeyValues::GetInt(this: kv, keyName: "Width", defaultValue: 0) > g_warn_texdimensions )
  {
    return true;
  }
  return KeyValues::GetInt(this: kv, keyName: "Height", defaultValue: 0) > g_warn_texdimensions;
}

//------------------------------------------------------------------------------
// Address: 0x10091760
// Name: FmtCommaNumber
// Source: json
//------------------------------------------------------------------------------
void __cdecl FmtCommaNumber(char *pchBuffer, unsigned int uiNumber)
{
  char *v2; // edi
  unsigned int i; // esi
  const char *v4; // edx
  unsigned int v5; // eax

  v2 = pchBuffer;
  *pchBuffer = 0;
  for ( i = 1000000000; i != 0; i /= 0x3E8u )
  {
    if ( uiNumber > i )
    {
      v4 = "%d,";
      if ( uiNumber / i >= 0x3E8 )
        v4 = "%03d,";
      sprintf(string: &pchBuffer[strlen(v2)], format: v4, uiNumber / i % 0x3E8);
      v2 = pchBuffer;
    }
  }
  v5 = strlen(v2);
  if ( v5 != 0 )
  {
    if ( v2[v5 - 1] == 44 )
      v2[v5 - 1] = 0;
  }
  else
  {
    sprintf(string: v2, format: "0");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10091800
// Name: public: static char const __near * CVmtTextEntry::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CVmtTextEntry::GetPanelClassName()
{
  return "CVmtTextEntry";
}

//------------------------------------------------------------------------------
// Address: 0x10091810
// Name: public: virtual void CVmtTextEntry::OpenEditMenu(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVmtTextEntry::OpenEditMenu(CVmtTextEntry *this)
{
  vgui::Menu *EventDebugID; // esi
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  int v5; // eax
  vgui::Menu_vtbl *v6; // ebx
  bool v7; // al
  int x0; // [esp+Ch] [ebp-8h] BYREF
  int x1; // [esp+10h] [ebp-4h] BYREF

  EventDebugID = CHLTVServer::GetEventDebugID(this);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "DoOpenVmtSelected");
  else
    v4 = nullptr;
  v5 = EventDebugID->AddMenuItem(this: EventDebugID, a2: "Open VMT", a3: v4, a4: this, a5: nullptr);
  EventDebugID->MoveMenuItem(this: EventDebugID, a2: v5, a3: 0);
  v6 = EventDebugID->__vftable;
  v7 = this->GetSelectedRange(this, a2: &x0, a3: &x1);
  v6->SetItemEnabled(this: EventDebugID, a2: "Open VMT", a3: v7);
  vgui::TextEntry::OpenEditMenu(this);
}

//------------------------------------------------------------------------------
// Address: 0x100918A0
// Name: public: static char const __near * CRenderTextureEditor::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CRenderTextureEditor::GetPanelClassName()
{
  return "CRenderTextureEditor";
}

//------------------------------------------------------------------------------
// Address: 0x100918B0
// Name: public: virtual void CRenderTextureEditor::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRenderTextureEditor::ApplySchemeSettings(CRenderTextureEditor *this, vgui::IScheme *pScheme)
{
  CRenderTextureEditor_vtbl *v4; // ebx
  bool v5; // al
  int v6; // eax
  vgui::IScheme *pSchemea; // [esp+14h] [ebp+8h]

  vgui::Frame::ApplySchemeSettings(this, pScheme);
  v4 = this->__vftable;
  pSchemea = (vgui::IScheme *)pScheme->__vftable;
  v5 = this->IsProportional(this);
  v6 = ((int (__thiscall *)(vgui::IScheme *, const char *, bool))pSchemea[3].__vftable)(
         a1: pScheme,
         a2: "Default",
         a3: v5);
  v4->SetFont(this, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x10091900
// Name: public: virtual void CRenderTextureEditor::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRenderTextureEditor::OnMousePressed(CRenderTextureEditor *this, ButtonCode_t code)
{
  this->Close(this);
}

//------------------------------------------------------------------------------
// Address: 0x10091910
// Name: public: static char const __near * CRenderTexturesListViewPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CRenderTexturesListViewPanel::GetPanelClassName()
{
  return "CRenderTexturesListViewPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10091920
// Name: protected: virtual void CRenderTexturesListViewPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CRenderTexturesListViewPanel::PerformLayout(CRenderTexturesListViewPanel *this)
{
  vgui::TileViewPanelEx::PerformLayout(this);
}

//------------------------------------------------------------------------------
// Address: 0x10091930
// Name: protected: virtual int CRenderTexturesListViewPanel::GetNumTiles(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRenderTexturesListViewPanel::GetNumTiles(CRenderTexturesListViewPanel *this)
{
  if ( this->m_pListPanel != nullptr )
    return this->m_pListPanel->GetItemCount(this: this->m_pListPanel);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10091950
// Name: protected: virtual void CRenderTexturesListViewPanel::GetTileSize(int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRenderTexturesListViewPanel::GetTileSize(CRenderTexturesListViewPanel *this, int *wide, int *tall)
{
  *wide = 232;
  *tall = 267;
}

//------------------------------------------------------------------------------
// Address: 0x10091980
// Name: KilobytesSortFunc
// Source: json
//------------------------------------------------------------------------------
int __cdecl KilobytesSortFunc(
        vgui::ListPanel *pPanel,
        const vgui::ListPanelItem *item1,
        const vgui::ListPanelItem *item2)
{
  const char *String; // esi
  const char *v4; // edi
  int v5; // esi
  int v6; // eax

  String = KeyValues::GetString(this: item1->kv, keyName: "Size", defaultValue: defaultValue);
  v4 = KeyValues::GetString(this: item2->kv, keyName: "Size", defaultValue: defaultValue);
  v5 = atoi(nptr: String);
  v6 = atoi(nptr: v4);
  if ( v5 >= v6 )
    return (v5 <= v6) - 1;
  else
    return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100919E0
// Name: public: CSmartTextureKeyValues::CSmartTextureKeyValues(void)
// Source: json
//------------------------------------------------------------------------------
CSmartTextureKeyValues *__thiscall CSmartTextureKeyValues::CSmartTextureKeyValues(CSmartTextureKeyValues *this)
{
  KeyValues *v2; // eax

  this->m_p = nullptr;
  v2 = g_pMaterialSystemDebugTextureInfo->LockDebugTextureList(this: g_pMaterialSystemDebugTextureInfo);
  if ( v2 != nullptr )
  {
    this->m_p = KeyValues::MakeCopy(this: v2);
    g_pMaterialSystemDebugTextureInfo->UnlockDebugTextureList(this: g_pMaterialSystemDebugTextureInfo);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10091A20
// Name: public: virtual void CTextureListPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureListPanel::ApplySchemeSettings(CTextureListPanel *this, vgui::IScheme *pScheme)
{
  vgui::Frame::ApplySchemeSettings(this, pScheme);
  this->m_hFont = pScheme->GetFont(this: pScheme, a2: "DefaultVerySmall", a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10091A50
// Name: public: virtual bool CTextureListPanel::ShouldDraw(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTextureListPanel::ShouldDraw(CTextureListPanel *this)
{
  return mat_texture_list.m_pParent != nullptr && mat_texture_list.m_pParent->m_Value.m_nValue != 0
      || s_eTxListPanelRequest == TXR_SHOW
      || s_eTxListPanelRequest == TXR_RUNNING;
}

//------------------------------------------------------------------------------
// Address: 0x10091A80
// Name: ToLowerInplace
// Source: json
//------------------------------------------------------------------------------
void __usercall ToLowerInplace(char *chBuffer@<eax>)
{
  char *i; // esi

  for ( i = chBuffer; *i != 0; ++i )
  {
    if ( isupper(c: *i) != 0 )
      *i = tolower(c: *i);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10091AC0
// Name: void KeepSpecialKeys(class KeyValues __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl KeepSpecialKeys(KeyValues *textureList, bool bServiceKeys)
{
  KeyValues *FirstSubKey; // edi
  char v3; // bl
  const char *String; // esi
  KeyValues *pNext; // [esp+4h] [ebp-4h]

  FirstSubKey = KeyValues::GetFirstSubKey(this: textureList);
  if ( FirstSubKey != nullptr )
  {
    do
    {
      pNext = KeyValues::GetNextKey(this: FirstSubKey);
      v3 = 0;
      String = KeyValues::GetString(this: FirstSubKey, keyName: "Name", defaultValue: defaultValue);
      if ( StringAfterPrefix(str: String, prefix: "_") != nullptr
        || StringAfterPrefix(str: String, prefix: "[") != nullptr
        || _V_stricmp(s1: String, s2: "backbuffer") == 0
        || StringAfterPrefix(str: String, prefix: "colorcorrection") != nullptr
        || _V_stricmp(s1: String, s2: "depthbuffer") == 0
        || _V_stricmp(s1: String, s2: "frontbuffer") == 0
        || _V_stricmp(s1: String, s2: "normalize") == 0
        || *String == 0 )
      {
        v3 = 1;
      }
      if ( v3 == bServiceKeys )
      {
        if ( v3 != 0 )
          KeyValues::SetInt(this: FirstSubKey, keyName: "SpecialTx", value: 1);
      }
      else
      {
        KeyValues::RemoveSubKey(this: textureList, subKey: FirstSubKey);
      }
      FirstSubKey = pNext;
    }
    while ( pNext != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10091CE0
// Name: private: void CTextureListPanel::UpdateTotalUsageLabel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureListPanel::UpdateTotalUsageLabel(CTextureListPanel *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  wchar_t unicodeString[1024]; // [esp+4h] [ebp-C64h] BYREF
  char data[1024]; // [esp+804h] [ebp-464h] BYREF
  char kbMip1[20]; // [esp+C04h] [ebp-64h] BYREF
  char kbMip2[20]; // [esp+C18h] [ebp-50h] BYREF
  char kb1[20]; // [esp+C2Ch] [ebp-3Ch] BYREF
  char kb3[20]; // [esp+C40h] [ebp-28h] BYREF
  char kb2[20]; // [esp+C54h] [ebp-14h] BYREF

  v2 = g_pMaterialSystemDebugTextureInfo->GetTextureMemoryUsed(
         this: g_pMaterialSystemDebugTextureInfo,
         a2: MEMORY_BOUND_LAST_FRAME);
  FmtCommaNumber(pchBuffer: kb1, uiNumber: (v2 + 511) / 1024);
  v3 = g_pMaterialSystemDebugTextureInfo->GetTextureMemoryUsed(
         this: g_pMaterialSystemDebugTextureInfo,
         a2: MEMORY_TOTAL_LOADED);
  FmtCommaNumber(pchBuffer: kb2, uiNumber: (v3 + 511) / 1024);
  FmtCommaNumber(pchBuffer: kb3, uiNumber: this->m_numDisplayedSizeKB);
  if ( this->m_pCollapse->IsSelected(this: this->m_pCollapse) )
  {
    V_snprintf(pDest: data, maxLen: 1024, pFormat: "%s[F %s Kb] / [T %s Kb] / [S %s Kb]", defaultValue, kb1, kb2, kb3);
  }
  else
  {
    v4 = g_pMaterialSystemDebugTextureInfo->GetTextureMemoryUsed(
           this: g_pMaterialSystemDebugTextureInfo,
           a2: MEMORY_ESTIMATE_PICMIP_1);
    FmtCommaNumber(pchBuffer: kbMip1, uiNumber: (v4 + 511) / 1024);
    v5 = g_pMaterialSystemDebugTextureInfo->GetTextureMemoryUsed(
           this: g_pMaterialSystemDebugTextureInfo,
           a2: MEMORY_ESTIMATE_PICMIP_2);
    FmtCommaNumber(pchBuffer: kbMip2, uiNumber: (v5 + 511) / 1024);
    V_snprintf(
      pDest: data,
      maxLen: 1024,
      pFormat: "%s:  frame %s Kb  /  total %s Kb ( picmip1 = %s Kb, picmip2 = %s Kb )  /  shown %s Kb",
      "Texture Memory Usage",
      kb1,
      kb2,
      kbMip1,
      kbMip2,
      kb3);
  }
  g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: data, a3: unicodeString, a4: 2048);
  this->m_pTotalUsageLabel->SetText(this: this->m_pTotalUsageLabel, a2: unicodeString, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10091E60
// Name: private: virtual void CTextureListPanel::OnTextChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureListPanel::OnTextChanged(CTextureListPanel *this)
{
  this->OnCommand(this, a2: "FilteringTxt");
}

//------------------------------------------------------------------------------
// Address: 0x10091E70
// Name: private: bool CTextureListPanel::UpdateDisplayedItem(class KeyValues __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTextureListPanel::UpdateDisplayedItem(CTextureListPanel *this, KeyValues *pDispData, KeyValues *kv)
{
  int Int; // ebx
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  int v7; // ebx
  int v8; // ebx
  int v9; // ebx
  const char *v10; // eax
  const char *v11; // eax
  const char *v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  const char *v16; // eax
  const char *v17; // eax
  const char *v18; // eax
  const char *String; // [esp-4h] [ebp-14h]
  const char *v21; // [esp-4h] [ebp-14h]
  const char *v22; // [esp-4h] [ebp-14h]
  bool bUpdate; // [esp+Fh] [ebp-1h]

  bUpdate = false;
  Int = KeyValues::GetInt(this: pDispData, keyName: "BindsFrame", defaultValue: 0);
  if ( Int != KeyValues::GetInt(this: kv, keyName: "BindsFrame", defaultValue: 0) )
  {
    v4 = KeyValues::GetInt(this: kv, keyName: "BindsFrame", defaultValue: 0);
    KeyValues::SetInt(this: pDispData, keyName: "BindsFrame", value: v4);
    bUpdate = true;
  }
  v5 = KeyValues::GetInt(this: pDispData, keyName: "BindsMax", defaultValue: 0);
  if ( v5 != KeyValues::GetInt(this: kv, keyName: "BindsMax", defaultValue: 0) )
  {
    v6 = KeyValues::GetInt(this: kv, keyName: "BindsMax", defaultValue: 0);
    KeyValues::SetInt(this: pDispData, keyName: "BindsMax", value: v6);
    bUpdate = true;
  }
  v7 = KeyValues::GetInt(this: pDispData, keyName: "Size", defaultValue: 0);
  if ( v7 == KeyValues::GetInt(this: kv, keyName: "Size", defaultValue: 0) )
  {
    v8 = KeyValues::GetInt(this: pDispData, keyName: "Width", defaultValue: 0);
    if ( v8 == KeyValues::GetInt(this: kv, keyName: "Width", defaultValue: 0) )
    {
      v9 = KeyValues::GetInt(this: pDispData, keyName: "Height", defaultValue: 0);
      if ( v9 == KeyValues::GetInt(this: kv, keyName: "Height", defaultValue: 0) )
      {
        String = KeyValues::GetString(this: kv, keyName: "Format", defaultValue: defaultValue);
        v10 = KeyValues::GetString(this: pDispData, keyName: "Format", defaultValue: defaultValue);
        if ( _V_stricmp(s1: v10, s2: String) == 0 )
        {
          v21 = KeyValues::GetString(this: kv, keyName: "Path", defaultValue: defaultValue);
          v11 = KeyValues::GetString(this: pDispData, keyName: "Path", defaultValue: defaultValue);
          if ( _V_stricmp(s1: v11, s2: v21) == 0 )
          {
            v22 = KeyValues::GetString(this: kv, keyName: "TexGroup", defaultValue: defaultValue);
            v12 = KeyValues::GetString(this: pDispData, keyName: "TexGroup", defaultValue: defaultValue);
            if ( _V_stricmp(s1: v12, s2: v22) == 0 )
              return bUpdate;
          }
        }
      }
    }
  }
  v13 = KeyValues::GetInt(this: kv, keyName: "Size", defaultValue: 0);
  KeyValues::SetInt(this: pDispData, keyName: "Size", value: v13);
  v14 = KeyValues::GetInt(this: kv, keyName: "Width", defaultValue: 0);
  KeyValues::SetInt(this: pDispData, keyName: "Width", value: v14);
  v15 = KeyValues::GetInt(this: kv, keyName: "Height", defaultValue: 0);
  KeyValues::SetInt(this: pDispData, keyName: "Height", value: v15);
  v16 = KeyValues::GetString(this: kv, keyName: "Format", defaultValue: defaultValue);
  KeyValues::SetString(this: pDispData, keyName: "Format", value: v16);
  v17 = KeyValues::GetString(this: kv, keyName: "Path", defaultValue: defaultValue);
  KeyValues::SetString(this: pDispData, keyName: "Path", value: v17);
  v18 = KeyValues::GetString(this: kv, keyName: "TexGroup", defaultValue: defaultValue);
  KeyValues::SetString(this: pDispData, keyName: "TexGroup", value: v18);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100920D0
// Name: private: int CTextureListPanel::AddListItem(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTextureListPanel::AddListItem(CTextureListPanel *this, KeyValues *kv)
{
  vgui::ListPanel_vtbl *v3; // ebx
  const char *String; // eax
  int v5; // ebx
  const char *v6; // eax
  int v7; // edi
  KeyValues *v9; // eax

  v3 = this->m_pListPanel->__vftable;
  String = KeyValues::GetString(this: kv, keyName: "Name", defaultValue: defaultValue);
  v5 = v3->GetItem_2(this: this->m_pListPanel, a2: String);
  if ( v5 == -1 )
  {
    v6 = KeyValues::GetString(this: kv, keyName: "Name", defaultValue: defaultValue);
    KeyValues::SetName(this: kv, setName: v6);
    v7 = this->m_pListPanel->AddItem(this: this->m_pListPanel, a2: kv, a3: 0, a4: false, a5: false);
    this->m_pViewPanel->InvalidateLayout(this: this->m_pViewPanel, a2: false, a3: false);
    return v7;
  }
  else
  {
    v9 = this->m_pListPanel->GetItem(this: this->m_pListPanel, a2: v5);
    if ( CTextureListPanel::UpdateDisplayedItem(this, pDispData: v9, kv) != 0 )
    {
      this->m_pListPanel->ApplyItemChanges(this: this->m_pListPanel, a2: v5);
      this->m_pViewPanel->Repaint(this: this->m_pViewPanel);
    }
    return v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10092240
// Name: public: virtual struct vgui::PanelMessageMap __near * vgui::TileViewPanelEx::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall vgui::TileViewPanelEx::GetMessageMap(vgui::TileViewPanelEx *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`vgui::TileViewPanelEx::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TileViewPanelEx::GetMessageMap'::`2'::s_pMap;
  `vgui::TileViewPanelEx::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "TileViewPanelEx");
  `vgui::TileViewPanelEx::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10092270
// Name: public: virtual struct PanelAnimationMap __near * vgui::TileViewPanelEx::GetAnimMap(void)
// Source: rtti_class
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall vgui::TileViewPanelEx::GetAnimMap(vgui::TileViewPanelEx *this)
{
  return FindOrAddPanelAnimationMap(className: "TileViewPanelEx");
}

//------------------------------------------------------------------------------
// Address: 0x10092280
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * vgui::TileViewPanelEx::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall vgui::TileViewPanelEx::GetKBMap(vgui::TileViewPanelEx *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`vgui::TileViewPanelEx::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `vgui::TileViewPanelEx::GetKBMap'::`2'::s_pMap;
  `vgui::TileViewPanelEx::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "TileViewPanelEx");
  `vgui::TileViewPanelEx::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100922B0
// Name: bool CanAdjustTextureSize(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CanAdjustTextureSize(const char *szTextureName, bool bMoveSizeUp)
{
  ITexture *v2; // esi
  int v4; // eax
  int v5; // edi
  MaterialTextureInfo_t txInfo; // [esp+8h] [ebp-4h] BYREF

  v2 = materials->FindTexture(this: materials, a2: szTextureName, a3: defaultValue, a4: 0, a5: 0);
  if ( v2 == nullptr
    || mat_texture_list_exclude_editing.m_pParent != nullptr
    && mat_texture_list_exclude_editing.m_pParent->m_Value.m_nValue > 0
    && (!materials->GetTextureInformation(this: materials, a2: szTextureName, a3: &txInfo)
     || txInfo.iExcludeInformation == 0) )
  {
    return 0;
  }
  v4 = v2->GetActualWidth(this: v2);
  if ( bMoveSizeUp )
  {
    if ( v4 < v2->GetMappingWidth(this: v2) )
      return 1;
    v5 = v2->GetActualHeight(this: v2);
    if ( v5 < v2->GetMappingHeight(this: v2) )
      return 1;
  }
  else if ( v4 > 4 || v2->GetActualHeight(this: v2) > 4 )
  {
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10092370
// Name: bool AdjustTextureSize(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl AdjustTextureSize(const char *szTextureName, bool bMoveSizeUp)
{
  ITexture *v2; // esi
  int v4; // edi
  int v5; // eax
  ITexture_vtbl *v6; // edx
  int v7; // eax

  v2 = materials->FindTexture(this: materials, a2: szTextureName, a3: defaultValue, a4: 0, a5: 0);
  if ( v2 == nullptr )
    return 0;
  if ( mat_texture_list_exclude_editing.m_pParent != nullptr
    && mat_texture_list_exclude_editing.m_pParent->m_Value.m_nValue > 0 )
  {
    v4 = v2->GetActualHeight(this: v2);
    v5 = v2->GetActualWidth(this: v2);
    v6 = v2->__vftable;
    if ( v5 <= v4 )
      v7 = ((int (__fastcall *)(ITexture *))v6->GetActualHeight)(a1: v2);
    else
      v7 = ((int (__fastcall *)(ITexture *))v6->GetActualWidth)(a1: v2);
    if ( bMoveSizeUp )
      v2->ForceExcludeOverride(this: v2, a2: 2 * v7);
    else
      v2->ForceExcludeOverride(this: v2, a2: v7 >> 1);
    return 1;
  }
  else
  {
    v2->ForceLODOverride(this: v2, a2: 2 * bMoveSizeUp - 1);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10092420
// Name: bool AdjustTextureExclude(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl AdjustTextureExclude(const char *szTextureName, bool bExclude)
{
  ITexture *v2; // eax

  v2 = materials->FindTexture(this: materials, a2: szTextureName, a3: defaultValue, a4: 0, a5: 0);
  if ( v2 == nullptr
    || mat_texture_list_exclude_editing.m_pParent == nullptr
    || mat_texture_list_exclude_editing.m_pParent->m_Value.m_nValue <= 0 )
  {
    return 0;
  }
  v2->ForceExcludeOverride(this: v2, a2: bExclude - 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10092470
// Name: bool IsTextureExcluded(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __usercall IsTextureExcluded@<al>(int a1@<esi>, const char *szTextureName)
{
  MaterialTextureInfo_t txInfo; // [esp+0h] [ebp-4h] BYREF

  if ( mat_texture_list_exclude_editing.m_pParent == nullptr
    || mat_texture_list_exclude_editing.m_pParent->m_Value.m_nValue <= 0 )
  {
    return false;
  }
  if ( ((int (__thiscall *)(IMaterialSystem *, const char *, const char *, _DWORD, _DWORD, int))materials->FindTexture)(
         a1: materials,
         a2: szTextureName,
         a3: defaultValue,
         a4: 0,
         a5: 0,
         a6: a1) != 0
    && materials->GetTextureInformation(this: materials, a2: szTextureName, a3: &txInfo) )
  {
    return txInfo.iExcludeInformation == 0;
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10092680
// Name: public: virtual void CRenderTextureEditor::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CRenderTextureEditor::PerformLayout(CRenderTextureEditor *this@<ecx>, int a2@<ebx>)
{
  KeyValues *m_pInfo; // edi
  const char *String; // eax
  const char *v5; // edi
  vgui::Button_vtbl *v6; // ebx
  bool v7; // al
  vgui::Button_vtbl *v8; // ebx
  unsigned __int8 v9; // al
  vgui::Button_vtbl *v10; // ebx
  unsigned __int8 v11; // al
  int Tall; // eax
  int Wide; // eax
  int v14; // eax
  int v15; // eax
  int v16; // edi
  int v17; // eax
  int v18; // eax
  int v19; // eax
  vgui::Button *m_pExplore; // ecx
  int v21; // eax
  vgui::Button *m_pCopyImg; // ecx
  vgui::Button *m_pCopyTxt; // ecx
  vgui::Button *m_pFlashBtn; // ecx
  int v25; // [esp-8h] [ebp-218h]
  char chResolveName[256]; // [esp+8h] [ebp-208h] BYREF
  char chResolveNameArg[256]; // [esp+108h] [ebp-108h] BYREF
  int posY; // [esp+208h] [ebp-8h] BYREF
  int posX; // [esp+20Ch] [ebp-4h] BYREF

  vgui::Frame::PerformLayout(this);
  vgui::Panel::SetSize(this, wide: 590, tall: 760);
  vgui::Panel::SetPos(this: this->m_pMaterials, x: 10, y: 662);
  vgui::Panel::SetSize(this: this->m_pMaterials, wide: 570, tall: 90);
  vgui::Panel::SetPos(this: this->m_pExplore, x: 520, y: 20);
  vgui::Panel::SetWide(this: this->m_pExplore, wide: 50);
  vgui::Panel::SetPos(this: this->m_pReload, x: 455, y: 20);
  vgui::Panel::SetWide(this: this->m_pReload, wide: 60);
  this->m_pReload->SetVisible(this: this->m_pReload, a2: this->m_lstMaterials.m_Size > 0);
  this->m_pExplore->SetVisible(this: this->m_pExplore, a2: false);
  this->m_pSizeControls[0]->SetVisible(this: this->m_pSizeControls[0], a2: false);
  this->m_pSizeControls[1]->SetVisible(this: this->m_pSizeControls[1], a2: false);
  this->m_pSizeControls[2]->SetVisible(this: this->m_pSizeControls[2], a2: false);
  m_pInfo = this->m_pInfo;
  if ( m_pInfo != nullptr )
  {
    memset(chResolveName, 0, sizeof(chResolveName));
    memset(chResolveNameArg, 0, sizeof(chResolveNameArg));
    String = KeyValues::GetString(this: m_pInfo, keyName: "Name", defaultValue: defaultValue);
    V_snprintf(pDest: chResolveNameArg, maxLen: 255, pFormat: "materials/%s.vtf", String);
    if ( g_pFileSystem->RelativePathToFullPath(
           this: g_pFileSystem,
           a2: chResolveNameArg,
           a3: "game",
           a4: chResolveName,
           a5: 255,
           a6: 0,
           a7: 0) != nullptr )
      this->m_pExplore->SetVisible(this: this->m_pExplore, a2: true);
    v5 = KeyValues::GetString(this: this->m_pInfo, keyName: "Name", defaultValue: defaultValue);
    if ( KeyValues::GetInt(this: this->m_pInfo, keyName: "SpecialTx", defaultValue: 0) == 0 )
    {
      ((void (__thiscall *)(vgui::Button *, int, int))this->m_pSizeControls[0]->SetVisible)(
        a1: this->m_pSizeControls[0],
        a2: 1,
        a3: a2);
      this->m_pSizeControls[1]->SetVisible(this: this->m_pSizeControls[1], a2: true);
      if ( mat_texture_list_exclude_editing.m_pParent != nullptr
        && mat_texture_list_exclude_editing.m_pParent->m_Value.m_nValue > 0
        && materials->FindTexture(this: materials, a2: v5, a3: defaultValue, a4: 0, a5: 0) != nullptr )
      {
        this->m_pSizeControls[2]->SetVisible(this: this->m_pSizeControls[2], a2: true);
        v6 = this->m_pSizeControls[2]->__vftable;
        v7 = IsTextureExcluded(a1: (int)this, szTextureName: v5);
        v6->SetSelected(this: this->m_pSizeControls[2], a2: v7);
      }
      v8 = this->m_pSizeControls[0]->__vftable;
      v9 = CanAdjustTextureSize(szTextureName: v5, bMoveSizeUp: false);
      v8->SetEnabled(this: this->m_pSizeControls[0], a2: v9);
      v10 = this->m_pSizeControls[1]->__vftable;
      v11 = CanAdjustTextureSize(szTextureName: v5, bMoveSizeUp: true);
      v10->SetEnabled(this: this->m_pSizeControls[1], a2: v11);
      vgui::Panel::GetPos(this: this->m_pExplore, x: &posX, y: &posY);
      Tall = vgui::Panel::GetTall(this: this->m_pExplore);
      vgui::Panel::SetPos(this: this->m_pSizeControls[0], x: posX, y: Tall + posY + 1);
      Wide = vgui::Panel::GetWide(this: this->m_pExplore);
      vgui::Panel::SetWide(this: this->m_pSizeControls[0], wide: Wide / 2);
      v14 = vgui::Panel::GetTall(this: this->m_pExplore);
      v25 = v14 + posY + 1;
      v15 = vgui::Panel::GetWide(this: this->m_pSizeControls[0]);
      vgui::Panel::SetPos(this: this->m_pSizeControls[1], x: v15 + posX + 1, y: v25);
      v16 = vgui::Panel::GetWide(this: this->m_pExplore);
      v17 = vgui::Panel::GetWide(this: this->m_pSizeControls[0]);
      vgui::Panel::SetWide(this: this->m_pSizeControls[1], wide: v16 - v17 - 1);
      v18 = vgui::Panel::GetTall(this: this->m_pExplore);
      vgui::Panel::SetPos(this: this->m_pSizeControls[2], x: posX - 81, y: v18 + posY + 1);
      vgui::Panel::SetWide(this: this->m_pSizeControls[2], wide: 80);
    }
  }
  vgui::Panel::GetPos(this: this->m_pExplore, x: &posX, y: &posY);
  v19 = vgui::Panel::GetTall(this: this->m_pExplore);
  m_pExplore = this->m_pExplore;
  posY += 2 * v19 + 2;
  v21 = vgui::Panel::GetWide(this: m_pExplore);
  m_pCopyImg = this->m_pCopyImg;
  posX = posX + v21 - 80;
  vgui::Panel::SetPos(this: m_pCopyImg, x: posX, y: posY);
  vgui::Panel::SetWide(this: this->m_pCopyImg, wide: 80);
  m_pCopyTxt = this->m_pCopyTxt;
  posX -= 85;
  vgui::Panel::SetPos(this: m_pCopyTxt, x: posX, y: posY);
  vgui::Panel::SetWide(this: this->m_pCopyTxt, wide: 80);
  m_pFlashBtn = this->m_pFlashBtn;
  posX -= 100;
  vgui::Panel::SetPos(this: m_pFlashBtn, x: posX, y: posY);
  vgui::Panel::SetWide(this: this->m_pFlashBtn, wide: 95);
}

//------------------------------------------------------------------------------
// Address: 0x10092AB0
// Name: public: virtual struct vgui::PanelMessageMap __near * CTextureListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CTextureListPanel::GetMessageMap(CTextureListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CTextureListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CTextureListPanel::GetMessageMap'::`2'::s_pMap;
  `CTextureListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CTextureListPanel");
  `CTextureListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10092AE0
// Name: public: virtual struct PanelAnimationMap __near * CTextureListPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CTextureListPanel::GetAnimMap(CTextureListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CTextureListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10092AF0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CTextureListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CTextureListPanel::GetKBMap(CTextureListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CTextureListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CTextureListPanel::GetKBMap'::`2'::s_pMap;
  `CTextureListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CTextureListPanel");
  `CTextureListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10092B60
// Name: public: virtual void CTextureListPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureListPanel::PerformLayout(CTextureListPanel *this)
{
  bool v2; // bl
  void (__thiscall *GetClientArea)(vgui::Frame *, int *, int *, int *, int *); // eax
  int v4; // edi
  int Tall; // eax
  vgui::Label *m_pTotalUsageLabel; // ecx
  vgui::Label_vtbl *v7; // edx
  int v8; // edi
  CConVarCheckButton *m_pShowTextureMemoryUsageOption; // edx
  CConVarCheckButton *m_pAllTextures; // eax
  CConVarCheckButton *m_pViewTextures; // ecx
  vgui::CheckButton *m_pFilteringChk; // edx
  vgui::Button *m_pCopyToClipboardButton; // ecx
  vgui::Panel *v14; // ebx
  CConVarCheckButton *v15; // ecx
  int v16; // eax
  int v17; // eax
  vgui::CheckButton *v18; // ecx
  int v19; // eax
  int v20; // eax
  vgui::Label *v21; // ecx
  CConVarCheckButton *v22; // edx
  CConVarCheckButton *v23; // ecx
  vgui::CheckButton *v24; // edx
  vgui::TextEntry *m_pFilteringText; // eax
  int v26; // edi
  vgui::Panel *v27; // ebx
  int v28; // edi
  vgui::CheckButton_vtbl *v29; // ebx
  bool v30; // al
  int v31; // eax
  int m_nValue; // eax
  int v33; // eax
  vgui::Panel *v34; // [esp+Ch] [ebp-4Ch]
  _DWORD v35[4]; // [esp+10h] [ebp-48h]
  vgui::Panel *buttons[7]; // [esp+20h] [ebp-38h]
  int t; // [esp+3Ch] [ebp-1Ch] BYREF
  int k; // [esp+40h] [ebp-18h]
  int y; // [esp+44h] [ebp-14h] BYREF
  int xOffset; // [esp+48h] [ebp-10h]
  int w; // [esp+4Ch] [ebp-Ch] BYREF
  int x; // [esp+50h] [ebp-8h] BYREF
  bool bCollapsed; // [esp+57h] [ebp-1h]

  vgui::Frame::PerformLayout(this);
  vgui::Panel::SetPos(this: this->m_pCollapse, x: 2, y: 10);
  vgui::Panel::SetSize(this: this->m_pCollapse, wide: 10, tall: 10);
  this->m_pCollapse->SetVisible(this: this->m_pCollapse, a2: true);
  v2 = this->m_pCollapse->IsSelected(this: this->m_pCollapse);
  GetClientArea = this->GetClientArea;
  bCollapsed = v2;
  GetClientArea(this, a2: &x, a3: &y, a4: &w, a5: &t);
  v4 = y;
  vgui::Panel::SetPos(this: this->m_pCVarListLabel, x, y);
  vgui::Panel::SetWide(this: this->m_pCVarListLabel, wide: w);
  this->m_pCVarListLabel->SetVisible(this: this->m_pCVarListLabel, a2: false);
  vgui::Panel::SetPos(this: this->m_pTotalUsageLabel, x, y: v4);
  vgui::Panel::SetWide(this: this->m_pTotalUsageLabel, wide: w);
  Tall = vgui::Panel::GetTall(this: this->m_pTotalUsageLabel);
  m_pTotalUsageLabel = this->m_pTotalUsageLabel;
  v7 = m_pTotalUsageLabel->__vftable;
  v8 = Tall + v4;
  LOBYTE(Tall) = !v2;
  LOBYTE(k) = !v2;
  v7->SetVisible(this: m_pTotalUsageLabel, a2: Tall);
  m_pShowTextureMemoryUsageOption = this->m_pShowTextureMemoryUsageOption;
  m_pAllTextures = this->m_pAllTextures;
  buttons[0] = this->m_pSpecialTexs;
  m_pViewTextures = this->m_pViewTextures;
  buttons[1] = m_pShowTextureMemoryUsageOption;
  m_pFilteringChk = this->m_pFilteringChk;
  buttons[2] = m_pAllTextures;
  buttons[3] = m_pViewTextures;
  buttons[4] = m_pFilteringChk;
  m_pCopyToClipboardButton = this->m_pCopyToClipboardButton;
  buttons[5] = this->m_pResolveTexturePath;
  buttons[6] = m_pCopyToClipboardButton;
  for ( xOffset = 0; (unsigned int)xOffset < 7; ++xOffset )
  {
    v14 = buttons[xOffset];
    vgui::Panel::SetPos(this: v14, x, y: v8);
    vgui::Panel::SetWide(this: v14, wide: w / 2);
    v8 += vgui::Panel::GetTall(this: v14);
    v14->SetVisible(this: v14, a2: k);
    v15 = this->m_pViewTextures;
    if ( v14 == v15 )
    {
      vgui::Panel::SetWide(this: v15, wide: 170);
      v16 = vgui::Panel::GetTall(this: this->m_pViewTextures);
      vgui::Panel::SetPos(this: this->m_pAlpha, x: x + 175, y: v8 - v16);
      vgui::Panel::SetWide(this: this->m_pAlpha, wide: 85);
      v17 = vgui::Panel::GetTall(this: this->m_pViewTextures);
      vgui::Panel::SetPos(this: this->m_pThumbWarnings, x: x + 260, y: v8 - v17);
      vgui::Panel::SetWide(this: this->m_pThumbWarnings, wide: 85);
    }
    v18 = this->m_pFilteringChk;
    if ( v14 == v18 )
    {
      vgui::Panel::SetWide(this: v18, wide: 60);
      v19 = vgui::Panel::GetTall(this: this->m_pFilteringChk);
      vgui::Panel::SetPos(this: this->m_pFilteringText, x: x + 65, y: v8 - v19);
      vgui::Panel::SetWide(this: this->m_pFilteringText, wide: 170);
      v20 = vgui::Panel::GetTall(this: this->m_pFilteringChk);
      vgui::Panel::SetTall(this: this->m_pFilteringText, tall: v20);
      this->m_pFilteringText->SetVisible(this: this->m_pFilteringText, a2: k);
    }
  }
  if ( bCollapsed )
  {
    v21 = this->m_pTotalUsageLabel;
    v22 = this->m_pViewTextures;
    v35[3] = this->m_pAlpha;
    v34 = v21;
    v23 = this->m_pAllTextures;
    v35[1] = v22;
    v24 = this->m_pFilteringChk;
    buttons[0] = (vgui::Panel *)60;
    buttons[4] = (vgui::Panel *)60;
    m_pFilteringText = this->m_pFilteringText;
    v26 = 0;
    xOffset = 85;
    v35[0] = 290;
    v35[2] = 170;
    buttons[1] = v23;
    buttons[2] = (vgui::Panel *)135;
    buttons[3] = v24;
    buttons[5] = m_pFilteringText;
    buttons[6] = (vgui::Panel *)130;
    for ( k = 0; ; v26 = k )
    {
      v27 = (vgui::Panel *)v35[2 * v26 - 1];
      vgui::Panel::SetPos(this: v27, x: xOffset, y: 2);
      v28 = v35[2 * v26];
      if ( w - xOffset - 30 < v28 )
        v28 = w - xOffset - 30;
      vgui::Panel::SetWide(this: v27, wide: v28);
      v27->SetVisible(this: v27, a2: v28 > 50);
      if ( v28 > 50 )
        xOffset += v28 + 5;
      if ( (unsigned int)++k >= 6 )
        break;
    }
    v8 = y;
  }
  v29 = this->m_pAlpha->__vftable;
  v30 = this->m_pViewTextures->IsSelected(this: this->m_pViewTextures);
  v31 = ((int (__thiscall *)(vgui::CheckButton *, bool))v29->SetVisible)(a1: this->m_pAlpha, a2: v30);
  LOBYTE(v31) = !bCollapsed
             && (_BYTE)(v31 = ((int (__thiscall *)(CConVarCheckButton *))this->m_pViewTextures->IsSelected)(a1: this->m_pViewTextures)) != 0;
  this->m_pThumbWarnings->SetVisible(this: this->m_pThumbWarnings, a2: v31);
  vgui::Panel::SetBounds(this: this->m_pListPanel, x, y: v8, wide: w, tall: t + y - v8);
  vgui::Panel::SetBounds(this: this->m_pViewPanel, x, y: v8, wide: w, tall: t + y - v8);
  if ( mat_texture_list_view.m_pParent != nullptr )
    m_nValue = mat_texture_list_view.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  this->m_pListPanel->SetVisible(this: this->m_pListPanel, a2: m_nValue == 0);
  if ( mat_texture_list_view.m_pParent != nullptr )
    v33 = mat_texture_list_view.m_pParent->m_Value.m_nValue;
  else
    v33 = 0;
  this->m_pViewPanel->SetVisible(this: this->m_pViewPanel, a2: v33 != 0);
}

//------------------------------------------------------------------------------
// Address: 0x10092FA0
// Name: void mat_texture_list_off_f(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall mat_texture_list_off_f(CTextureListPanel *this)
{
  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_texture_list.IConVar, value: 0);
  s_eTxListPanelRequest = TXR_HIDE;
}

//------------------------------------------------------------------------------
// Address: 0x100931B0
// Name: void mat_texture_list_on_f(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl mat_texture_list_on_f()
{
  CTextureListPanel *v0; // esi
  CRenderTextureEditor *m_pRenderTxEditor; // ecx

  CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_texture_list.IConVar, value: 1);
  s_eTxListPanelRequest = TXR_SHOW;
  v0 = g_pTextureListPanel;
  if ( !g_bRecursiveRequestToShowTextureList )
  {
    if ( g_pTextureListPanel->m_pListPanel != nullptr )
      g_pTextureListPanel->m_pListPanel->DeleteAllItems(this: g_pTextureListPanel->m_pListPanel);
    m_pRenderTxEditor = v0->m_pViewPanel->m_pRenderTxEditor;
    if ( m_pRenderTxEditor != nullptr )
      m_pRenderTxEditor->Close(this: m_pRenderTxEditor);
  }
  MatViewOverride::s_viewParamsReq.lstMaterials.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10094550
// Name: private: virtual void CTextureListPanel::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTextureListPanel::OnCommand(CTextureListPanel *this, const char *command)
{
  bool v3; // al
  CRenderTexturesListViewPanel *m_pViewPanel; // ecx

  if ( _V_stricmp(s1: command, s2: "Close") == 0 )
  {
    vgui::Frame::OnCommand(this, command);
    return;
  }
  if ( _V_stricmp(s1: command, s2: "Collapse") == 0 )
    goto LABEL_4;
  if ( _V_stricmp(s1: command, s2: "ShowAlpha") != 0 )
  {
    if ( _V_stricmp(s1: command, s2: "ThumbWarnings") != 0 )
    {
      if ( _V_stricmp(s1: command, s2: "ViewThumbnails") == 0 )
      {
LABEL_4:
        this->InvalidateLayout(this, a2: false, a3: false);
        return;
      }
      if ( _V_stricmp(s1: command, s2: "CopyToClipboard") != 0 )
      {
        mat_texture_list_on_f();
        this->InvalidateLayout(this, a2: false, a3: false);
      }
      else
      {
        CopyListPanelToClipboard(pListPanel: this->m_pListPanel);
      }
    }
    else
    {
      g_warn_enable = this->m_pThumbWarnings->IsSelected(this: this->m_pThumbWarnings);
    }
  }
  else
  {
    v3 = this->m_pAlpha->IsSelected(this: this->m_pAlpha);
    m_pViewPanel = this->m_pViewPanel;
    m_pViewPanel->m_bPaintAlpha = v3;
    m_pViewPanel->Repaint(this: m_pViewPanel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096370
// Name: public: virtual void CRenderTextureEditor::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRenderTextureEditor::OnCommand(CRenderTextureEditor *this, const char *command)
{
  const char *v2; // ebx
  KeyValues *m_pInfo; // esi
  const char *String; // eax
  const char *v6; // eax
  int v7; // esi
  int v8; // ebx
  int m_Put; // eax
  unsigned __int16 v10; // dx
  const char *v11; // eax
  const char *v12; // ecx
  ECommandTarget_t TraceType; // eax
  const char *v14; // edx
  void *v15; // eax
  vgui::ISystem *v16; // ebx
  vgui::ISystem_vtbl *v17; // esi
  int Tall; // eax
  int Wide; // eax
  KeyValues *v20; // ecx
  const char *v21; // eax
  bool v22; // bl
  bool v23; // bl
  const char *v24; // eax
  ITexture *v25; // eax
  bool v26; // bl
  bool v27; // [esp-40h] [ebp-388h]
  int v28; // [esp-34h] [ebp-37Ch]
  unsigned __int8 *m_pMemory; // [esp-2Ch] [ebp-374h]
  char params[256]; // [esp+Ch] [ebp-33Ch] BYREF
  char chResolveName[256]; // [esp+10Ch] [ebp-23Ch] BYREF
  char chResolveNameArg[256]; // [esp+20Ch] [ebp-13Ch] BYREF
  CUtlBuffer bufCommand; // [esp+30Ch] [ebp-3Ch] BYREF
  void *bSizeUp; // [esp+33Ch] [ebp-Ch]
  int x; // [esp+340h] [ebp-8h] BYREF
  int y; // [esp+344h] [ebp-4h] BYREF

  v2 = command;
  vgui::Frame::OnCommand(this, command);
  if ( _V_stricmp(s1: command, s2: "Explore") == 0 )
  {
    m_pInfo = this->m_pInfo;
    if ( m_pInfo != nullptr )
    {
      memset(chResolveName, 0, sizeof(chResolveName));
      memset(chResolveNameArg, 0, sizeof(chResolveNameArg));
      String = KeyValues::GetString(this: m_pInfo, keyName: "Name", defaultValue: defaultValue);
      V_snprintf(pDest: chResolveNameArg, maxLen: 255, pFormat: "materials/%s.vtf", String);
      v6 = g_pFileSystem->RelativePathToFullPath(
             this: g_pFileSystem,
             a2: chResolveNameArg,
             a3: "game",
             a4: chResolveName,
             a5: 255,
             a6: 0,
             a7: 0);
      V_snprintf(pDest: params, maxLen: 255, pFormat: "/E,/SELECT,%s", v6);
      g_pVGuiSystem->ShellExecuteEx(this: g_pVGuiSystem, a2: "open", a3: "explorer.exe", a4: params);
    }
  }
  if ( _V_stricmp(s1: command, s2: "Reload") == 0 && this->m_lstMaterials.m_Size != 0 )
  {
    CUtlBuffer::CUtlBuffer(this: &bufCommand, growSize: 0, initSize: 0, nFlags: 1);
    v7 = 0;
    Cbuf_Execute();
    if ( this->m_lstMaterials.m_Size > 0 )
    {
      do
      {
        v8 = v7;
        CUtlBuffer::Printf(this: &bufCommand, pFmt: "mat_reloadmaterial \"");
        if ( v7 < this->m_lstMaterials.m_Size )
        {
          m_Put = bufCommand.m_Put;
          while ( 1 )
          {
            v10 = this->m_lstMaterials.m_Memory.m_pMemory[v7];
            x = m_Put;
            HIWORD(y) = v10;
            v11 = CUtlSymbol::String(this: (CUtlSymbol *)&y + 1);
            v12 = "*";
            if ( v7 <= v8 )
              v12 = defaultValue;
            CUtlBuffer::Printf(this: &bufCommand, pFmt: "%s%s", v12, v11);
            m_Put = bufCommand.m_Put;
            if ( bufCommand.m_Put > 508 && v7 > v8 )
              break;
            if ( ++v7 >= this->m_lstMaterials.m_Size )
              goto LABEL_16;
          }
          CUtlBuffer::SeekPut(this: &bufCommand, type: SEEK_HEAD, offset: x);
        }
LABEL_16:
        CUtlBuffer::Printf(this: &bufCommand, pFmt: "\"\n");
        if ( (bufCommand.m_Flags & 1) != 0
          && bufCommand.m_Put != 0
          && bufCommand.m_Memory.m_pMemory[bufCommand.m_Put - bufCommand.m_nOffset - 1] == 10 )
        {
          CUtlBuffer::PutTabs(this: &bufCommand);
        }
        if ( CUtlBuffer::CheckPut(this: &bufCommand, nSize: 1) )
        {
          bufCommand.m_Memory.m_pMemory[bufCommand.m_Put - bufCommand.m_nOffset] = 0;
          CUtlBuffer::AddNullTermination(this: &bufCommand, nPut: ++bufCommand.m_Put);
        }
        m_pMemory = bufCommand.m_Memory.m_pMemory;
        TraceType = CTraceFilter::GetTraceType(this: (vgui::CTreeViewListControl *)bufCommand.m_Memory.m_pMemory);
        Cbuf_AddText(eTarget: TraceType, pText: (const char *)m_pMemory, nTickDelay: 0);
        memset(&bufCommand.m_Get, 0, 9);
        bufCommand.m_nOffset = 0;
        bufCommand.m_nMaxPut = -1;
        CUtlBuffer::AddNullTermination(this: &bufCommand, nPut: 0);
        Cbuf_Execute();
      }
      while ( v7 < this->m_lstMaterials.m_Size );
      v2 = command;
    }
    if ( bufCommand.m_Memory.m_nGrowSize >= 0 && bufCommand.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufCommand.m_Memory.m_pMemory);
  }
  if ( _V_stricmp(s1: v2, s2: "CopyTxt") == 0 )
  {
    v14 = (const char *)this->m_bufInfoText.m_Memory.m_pMemory;
    if ( this->m_bufInfoText.m_Put == 0 || v14 == nullptr )
      v14 = defaultValue;
    g_pVGuiSystem->SetClipboardText_2(this: g_pVGuiSystem, a2: v14, a3: strlen(v14) + 1);
  }
  if ( _V_stricmp(s1: v2, s2: "CopyImg") == 0 )
  {
    x = 0;
    y = 0;
    vgui::Panel::LocalToScreen(this, &x, &y);
    v15 = game->GetMainWindow(this: game);
    v16 = g_pVGuiSystem;
    v17 = g_pVGuiSystem->__vftable;
    bSizeUp = v15;
    Tall = vgui::Panel::GetTall(this);
    v28 = y + Tall;
    Wide = vgui::Panel::GetWide(this);
    v17->SetClipboardImage(this: v16, a2: bSizeUp, a3: x, a4: y, a5: x + Wide, a6: v28);
    v2 = command;
  }
  if ( _V_stricmp(s1: v2, s2: "FlashBtn") == 0 )
  {
    MatViewOverride::s_viewParamsReq.lstMaterials.m_Size = 0;
    CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
      this: &MatViewOverride::s_viewParamsReq.lstMaterials,
      elem: 0,
      num: this->m_lstMaterials.m_Size,
      pToInsert: this->m_lstMaterials.m_Memory.m_pMemory);
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_texture_list.IConVar, value: 0);
    s_eTxListPanelRequest = TXR_HIDE;
  }
  if ( _V_stricmp(s1: v2, s2: "size-") == 0 || _V_stricmp(s1: v2, s2: "size+") == 0 )
  {
    v20 = this->m_pInfo;
    if ( v20 != nullptr )
    {
      LOBYTE(bSizeUp) = v2[4] == 43;
      v27 = (char)bSizeUp;
      v21 = KeyValues::GetString(this: v20, keyName: "Name", defaultValue: defaultValue);
      if ( AdjustTextureSize(szTextureName: v21, bMoveSizeUp: v27) != 0 )
      {
        v22 = g_bRecursiveRequestToShowTextureList;
        g_bRecursiveRequestToShowTextureList = true;
        mat_texture_list_on_f();
        g_bRecursiveRequestToShowTextureList = v22;
        v2 = command;
      }
      this->InvalidateLayout(this, a2: false, a3: false);
    }
  }
  if ( _V_stricmp(s1: v2, s2: "Exclude") == 0 )
  {
    v23 = this->m_pSizeControls[2]->IsSelected(this: this->m_pSizeControls[2]);
    v24 = KeyValues::GetString(this: this->m_pInfo, keyName: "Name", defaultValue: defaultValue);
    v25 = materials->FindTexture(this: materials, a2: v24, a3: defaultValue, a4: 0, a5: 0);
    if ( v25 != nullptr
      && mat_texture_list_exclude_editing.m_pParent != nullptr
      && mat_texture_list_exclude_editing.m_pParent->m_Value.m_nValue > 0 )
    {
      v25->ForceExcludeOverride(this: v25, a2: v23 - 1);
      v26 = g_bRecursiveRequestToShowTextureList;
      g_bRecursiveRequestToShowTextureList = true;
      mat_texture_list_on_f();
      g_bRecursiveRequestToShowTextureList = v26;
    }
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096BF0
// Name: public: static void vgui::TileViewPanelEx::PanelMessageFunc_OnSliderMoved::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall vgui::TileViewPanelEx::PanelMessageFunc_OnSliderMoved::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`vgui::TileViewPanelEx::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded )
  {
    `vgui::TileViewPanelEx::PanelMessageFunc_OnSliderMoved::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "TileViewPanelEx");
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "ScrollBarSliderMoved";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::RichText::`vcall'{872,{flat}};
    memset(&v3.m[1][1], 0, 44);
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096C80
// Name: public: vgui::TileViewPanelEx::TileViewPanelEx(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
vgui::TileViewPanelEx *__thiscall vgui::TileViewPanelEx::TileViewPanelEx(
        vgui::TileViewPanelEx *this,
        vgui::Panel *parent,
        const char *panelName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  vgui::ScrollBar *v7; // eax
  vgui::ScrollBar *v8; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName);
  this->__vftable = (vgui::TileViewPanelEx_vtbl *)&vgui::TileViewPanelEx::`vftable';
  if ( `vgui::TileViewPanelEx::ChainToMap'::`2'::chained == 0 )
  {
    `vgui::TileViewPanelEx::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "TileViewPanelEx");
    v4->pfnClassName = vgui::TileViewPanelEx::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "Panel");
  }
  if ( `vgui::TileViewPanelEx::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `vgui::TileViewPanelEx::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "TileViewPanelEx");
    v5->pfnClassName = vgui::TileViewPanelEx::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "Panel");
  }
  if ( `vgui::TileViewPanelEx::KB_ChainToMap'::`2'::chained == 0 )
  {
    `vgui::TileViewPanelEx::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "TileViewPanelEx");
    v6->pfnClassName = vgui::TileViewPanelEx::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "Panel");
  }
  vgui::TileViewPanelEx::PanelMessageFunc_OnSliderMoved::InitVar(a1: (int)&savedregs);
  this->m_hbar = nullptr;
  this->m_hFont = 0;
  v7 = (vgui::ScrollBar *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v7 != nullptr )
    v8 = vgui::ScrollBar::ScrollBar(this: v7, parent: this, panelName: "VerticalScrollBar", vertical: true);
  else
    v8 = nullptr;
  this->m_hbar = v8;
  v8->AddActionSignalTarget_2(this: v8, a2: this);
  this->m_hbar->SetVisible(this: this->m_hbar, a2: true);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10096DA0
// Name: public: static void CVmtTextEntry::PanelMessageFunc_OpenVmtSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CVmtTextEntry::PanelMessageFunc_OpenVmtSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CVmtTextEntry::PanelMessageFunc_OpenVmtSelected::InitVar'::`2'::bAdded )
  {
    `CVmtTextEntry::PanelMessageFunc_OpenVmtSelected::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CVmtTextEntry");
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "DoOpenVmtSelected";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::MessageBox::`vcall'{1148,{flat}};
    memset(&v3.m[1][1], 0, 44);
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096E30
// Name: public: static void CTextureListPanel::PanelMessageFunc_OnTextChanged::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CTextureListPanel::PanelMessageFunc_OnTextChanged::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // [esp-68h] [ebp-74h]
  VMatrix v3; // [esp-50h] [ebp-5Ch] BYREF
  int v4; // [esp-4h] [ebp-10h]
  int v5; // [esp+0h] [ebp-Ch]
  void *v6; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v5 = a1;
  v6 = retaddr;
  if ( !`CTextureListPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded )
  {
    `CTextureListPanel::PanelMessageFunc_OnTextChanged::InitVar'::`2'::bAdded = true;
    v4 = 0;
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CTextureListPanel");
    m_Size = v1->m_Size;
    LODWORD(v3.m[0][0]) = "TextChanged";
    LODWORD(v3.m[1][0]) =  __thiscall vgui::BuildModeDialog::`vcall'{1120,{flat}};
    memset(&v3.m[1][1], 0, 44);
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10096FA0
// Name: public: CAutoMatSysDebugMode::~CAutoMatSysDebugMode(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAutoMatSysDebugMode::~CAutoMatSysDebugMode(CAutoMatSysDebugMode *this)
{
  unsigned int i; // edi
  IMaterialVar *m_Data; // ecx

  g_pMaterialSystem->Flush(this: g_pMaterialSystem, a2: false);
  ((void (__stdcall *)(bool))g_pMaterialSystemDebugTextureInfo->SetDebugTextureRendering)(a1: this->bOldDebugMode);
  for ( i = 0; i < this->arrCleanupVars.m_NumElements; ++i )
  {
    m_Data = this->arrCleanupVars.m_Elements.m_pMemory[(unsigned __int16)i].m_Data;
    m_Data->SetUndefined(this: m_Data);
  }
  CUtlRBTree<IMaterialVar *,unsigned short,bool (__cdecl *)(IMaterialVar * const &,IMaterialVar * const &),CUtlMemory<UtlRBTreeNode_t<IMaterialVar *,unsigned short>,unsigned short>>::RemoveAll(this: &this->arrCleanupVars);
  this->arrCleanupVars.m_FirstFree = -1;
  if ( this->arrCleanupVars.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->arrCleanupVars.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->arrCleanupVars.m_Elements.m_pMemory);
      this->arrCleanupVars.m_Elements.m_pMemory = nullptr;
    }
    this->arrCleanupVars.m_Elements.m_nAllocationCount = 0;
  }
  this->arrCleanupVars.m_LastAlloc.index = -1;
  if ( this->arrCleanupVars.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->arrCleanupVars.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->arrCleanupVars.m_Elements.m_pMemory);
      this->arrCleanupVars.m_Elements.m_pMemory = nullptr;
    }
    this->arrCleanupVars.m_Elements.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10097060
// Name: RenderTexturedRect
// Source: json
//------------------------------------------------------------------------------
void __usercall RenderTexturedRect(
        vgui::Panel *pPanel@<ecx>,
        int yoff@<eax>,
        IMaterial *pMaterial,
        int x,
        int y,
        int x1,
        int y1,
        int xoff)
{
  void (__thiscall *Flush)(IMaterialSystem *, bool); // eax
  int Tall; // eax
  int v12; // ecx
  IMatRenderContext *v13; // eax
  IMatRenderContext *v14; // edi
  IMesh *v15; // esi
  float *m_pCurrPosition; // eax
  float v17; // xmm0_4
  float *v18; // eax
  float *v19; // eax
  __m128i v20; // xmm0
  float *v21; // eax
  float *v22; // eax
  float *v23; // eax
  float *v24; // eax
  float *v25; // eax
  int m_nVertexCount; // eax
  CMeshBuilder meshBuilder; // [esp+Ch] [ebp-20Ch] BYREF
  CAutoMatSysDebugMode auto_matsysdebugmode; // [esp+1F4h] [ebp-24h] BYREF
  float fHeightUV; // [esp+214h] [ebp-4h]

  Flush = g_pMaterialSystem->Flush;
  auto_matsysdebugmode.arrCleanupVars.m_LessFunc = (bool (__cdecl *)(IMaterialVar *const *, IMaterialVar *const *))CDmxSerializationDictionary::LessFunc;
  memset(&auto_matsysdebugmode.arrCleanupVars.m_Elements, 0, sizeof(auto_matsysdebugmode.arrCleanupVars.m_Elements));
  *(_DWORD *)&auto_matsysdebugmode.arrCleanupVars.m_Root = 0xFFFF;
  *(_DWORD *)&auto_matsysdebugmode.arrCleanupVars.m_FirstFree = -1;
  auto_matsysdebugmode.arrCleanupVars.m_pElements = nullptr;
  Flush(this: g_pMaterialSystem, a2: false);
  auto_matsysdebugmode.bOldDebugMode = g_pMaterialSystemDebugTextureInfo->SetDebugTextureRendering(
                                         this: g_pMaterialSystemDebugTextureInfo,
                                         a2: true);
  Tall = vgui::Panel::GetTall(this: pPanel);
  v12 = y1;
  fHeightUV = 1.0;
  if ( y1 > Tall )
  {
    v12 = Tall;
    fHeightUV = (float)(Tall - y) / (float)(y1 - y);
    y1 = Tall;
  }
  if ( v12 > y )
  {
    vgui::Panel::LocalToScreen(this: pPanel, &x, &y);
    vgui::Panel::LocalToScreen(this: pPanel, x: &x1, y: &y1);
    x += xoff;
    x1 += xoff;
    y += yoff;
    y1 += yoff;
    v13 = materials->GetRenderContext(this: materials);
    v14 = v13;
    if ( v13 != nullptr )
      v13->BeginRender(this: v13);
    v14->Bind(this: v14, a2: pMaterial, a3: nullptr);
    v15 = v14->GetDynamicMesh(this: v14, a2: true, a3: nullptr, a4: nullptr, a5: nullptr);
    CMeshBuilder::CMeshBuilder(this: &meshBuilder);
    meshBuilder.m_pMesh = v15;
    meshBuilder.m_bGenerateIndices = true;
    meshBuilder.m_Type = MATERIAL_QUADS;
    v15->SetPrimitiveType(this: v15, a2: MATERIAL_TRIANGLES);
    meshBuilder.m_pMesh->LockMesh(this: meshBuilder.m_pMesh, a2: 4, a3: 6, a4: &meshBuilder, a5: nullptr);
    meshBuilder.m_IndexBuilder.m_nIndexOffset = meshBuilder.m_nFirstVertex;
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = &v15->IIndexBuffer;
    meshBuilder.m_IndexBuilder.m_nIndexSize = meshBuilder.m_nIndexSize;
    meshBuilder.m_IndexBuilder.m_nIndexCount = 0;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 6;
    meshBuilder.m_IndexBuilder.m_bModify = false;
    meshBuilder.m_IndexBuilder.m_pIndices = meshBuilder.m_pIndices;
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::AttachBegin(this: &meshBuilder.m_VertexBuilder, pMesh: v15, nMaxVertexCount: 4, desc: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_nCurrentIndex = 0;
    CVertexBuilder::Reset(this: &meshBuilder.m_VertexBuilder);
    m_pCurrPosition = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v17 = (float)y;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)x;
    m_pCurrPosition[1] = v17;
    m_pCurrPosition[2] = 0.0;
    v18 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v18[1] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v19 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    v20 = _mm_cvtsi32_si128(y);
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)x1;
    v19[1] = _mm_cvtepi32_ps(v20).m128_f32[0];
    v19[2] = 0.0;
    v21 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
    v21[1] = 0.0;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v22 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *(float *)v20.m128i_i32 = (float)y1;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)x1;
    v22[1] = *(float *)v20.m128i_i32;
    v22[2] = 0.0;
    v23 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 1.0;
    v23[1] = fHeightUV;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    v24 = meshBuilder.m_VertexBuilder.m_pCurrPosition;
    *(float *)v20.m128i_i32 = (float)y1;
    *meshBuilder.m_VertexBuilder.m_pCurrPosition = (float)x;
    v24[1] = *(float *)v20.m128i_i32;
    v24[2] = 0.0;
    v25 = meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0];
    *meshBuilder.m_VertexBuilder.m_pCurrTexCoord[0] = 0.0;
    v25[1] = fHeightUV;
    CVertexBuilder::AdvanceVertex(this: &meshBuilder.m_VertexBuilder);
    if ( meshBuilder.m_bGenerateIndices )
    {
      switch ( meshBuilder.m_Type )
      {
        case MATERIAL_LINE_STRIP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount - 2;
          break;
        case MATERIAL_LINE_LOOP:
          m_nVertexCount = 2 * meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
        case MATERIAL_POLYGON:
          m_nVertexCount = 3 * meshBuilder.m_VertexBuilder.m_nVertexCount - 6;
          break;
        case MATERIAL_QUADS:
          m_nVertexCount = 6 * meshBuilder.m_VertexBuilder.m_nVertexCount / 4;
          break;
        case MATERIAL_INSTANCED_QUADS:
          m_nVertexCount = 0;
          break;
        default:
          m_nVertexCount = meshBuilder.m_VertexBuilder.m_nVertexCount;
          break;
      }
      CIndexBuilder::GenerateIndices(
        this: &meshBuilder.m_IndexBuilder,
        primitiveType: meshBuilder.m_Type,
        nIndexCount: m_nVertexCount);
    }
    meshBuilder.m_pMesh->UnlockMesh(
      this: meshBuilder.m_pMesh,
      a2: meshBuilder.m_VertexBuilder.m_nVertexCount,
      a3: meshBuilder.m_IndexBuilder.m_nIndexCount,
      a4: &meshBuilder);
    meshBuilder.m_IndexBuilder.m_pIndexBuffer = nullptr;
    meshBuilder.m_IndexBuilder.m_nMaxIndexCount = 0;
    meshBuilder.m_VertexBuilder.m_nMaxVertexCount = 0;
    meshBuilder.m_VertexBuilder.m_pVertexBuffer = nullptr;
    meshBuilder.m_VertexBuilder.m_CompressionType = VERTEX_COMPRESSION_INVALID;
    meshBuilder.m_pMesh = nullptr;
    v15->Draw_2(this: v15, a2: -1, a3: 0);
    CMeshBuilder::~CMeshBuilder(this: &meshBuilder);
    v14->EndRender(this: v14);
    v14->Release(this: v14);
  }
  CAutoMatSysDebugMode::~CAutoMatSysDebugMode(this: &auto_matsysdebugmode);
}

//------------------------------------------------------------------------------
// Address: 0x10097420
// Name: public: CVmtTextEntry::CVmtTextEntry(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CVmtTextEntry *__thiscall CVmtTextEntry::CVmtTextEntry(CVmtTextEntry *this, vgui::Panel *parent, const char *szName)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::TextEntry::TextEntry(this, parent, panelName: szName);
  this->__vftable = (CVmtTextEntry_vtbl *)&CVmtTextEntry::`vftable';
  if ( `CVmtTextEntry::ChainToMap'::`2'::chained == 0 )
  {
    `CVmtTextEntry::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CVmtTextEntry");
    v4->pfnClassName = CVmtTextEntry::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::TextEntry");
  }
  if ( `CVmtTextEntry::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CVmtTextEntry::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CVmtTextEntry");
    v5->pfnClassName = CVmtTextEntry::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::TextEntry");
  }
  if ( `CVmtTextEntry::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CVmtTextEntry::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CVmtTextEntry");
    v6->pfnClassName = CVmtTextEntry::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::TextEntry");
  }
  CVmtTextEntry::PanelMessageFunc_OpenVmtSelected::InitVar(a1: (int)&savedregs);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100974F0
// Name: public: virtual void vgui::TextEntry::SetAutoLocalize(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall vgui::TextEntry::SetAutoLocalize(vgui::TextEntry *this, bool bState)
{
  this->m_bAutoLocalize = bState;
}

//------------------------------------------------------------------------------
// Address: 0x10097500
// Name: public: virtual struct vgui::PanelMessageMap __near * CVmtTextEntry::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CVmtTextEntry::GetMessageMap(CVmtTextEntry *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CVmtTextEntry::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CVmtTextEntry::GetMessageMap'::`2'::s_pMap;
  `CVmtTextEntry::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CVmtTextEntry");
  `CVmtTextEntry::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10097530
// Name: public: virtual struct PanelAnimationMap __near * CVmtTextEntry::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CVmtTextEntry::GetAnimMap(CVmtTextEntry *this)
{
  return FindOrAddPanelAnimationMap(className: "CVmtTextEntry");
}

//------------------------------------------------------------------------------
// Address: 0x10097540
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CVmtTextEntry::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CVmtTextEntry::GetKBMap(CVmtTextEntry *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CVmtTextEntry::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CVmtTextEntry::GetKBMap'::`2'::s_pMap;
  `CVmtTextEntry::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CVmtTextEntry");
  `CVmtTextEntry::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10097570
// Name: public: CRenderTextureEditor::CRenderTextureEditor(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CRenderTextureEditor *__thiscall CRenderTextureEditor::CRenderTextureEditor(
        CRenderTextureEditor *this,
        vgui::Panel *parent,
        const char *szName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CVmtTextEntry *v7; // eax
  CVmtTextEntry *v8; // edi
  vgui::Button *v9; // eax
  vgui::Button *v10; // edi
  vgui::Button *v11; // eax
  vgui::Button *v12; // edi
  vgui::Button *v13; // eax
  vgui::Button *v14; // edi
  vgui::Button *v15; // eax
  vgui::Button *v16; // edi
  vgui::Button *v17; // eax
  vgui::Button *v18; // edi
  vgui::Button *v19; // eax
  vgui::Button *v20; // edi
  vgui::Button *v21; // eax
  vgui::Button *v22; // edi
  vgui::CheckButton *v23; // eax
  vgui::CheckButton *v24; // edi

  vgui::Frame::Frame(this, parent, panelName: szName, showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CRenderTextureEditor_vtbl *)&CRenderTextureEditor::`vftable';
  if ( `CRenderTextureEditor::ChainToMap'::`2'::chained == 0 )
  {
    `CRenderTextureEditor::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CRenderTextureEditor");
    v4->pfnClassName = CRenderTextureEditor::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CRenderTextureEditor::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CRenderTextureEditor::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CRenderTextureEditor");
    v5->pfnClassName = CRenderTextureEditor::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CRenderTextureEditor::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CRenderTextureEditor::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CRenderTextureEditor");
    v6->pfnClassName = CRenderTextureEditor::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  this->m_hFont = 0;
  this->m_pInfo = nullptr;
  CUtlBuffer::CUtlBuffer(this: &this->m_bufInfoText, growSize: 0, initSize: 0, nFlags: 1);
  this->m_lstMaterials.m_Memory.m_pMemory = nullptr;
  this->m_lstMaterials.m_Memory.m_nAllocationCount = 0;
  this->m_lstMaterials.m_Memory.m_nGrowSize = 0;
  this->m_lstMaterials.m_Size = 0;
  this->m_lstMaterials.m_pElements = nullptr;
  this->m_iInfoHint = 0;
  v7 = (CVmtTextEntry *)MemAlloc_Alloc(nSize: 0x440u);
  if ( v7 != nullptr )
    v8 = CVmtTextEntry::CVmtTextEntry(this: v7, parent: this, szName: "Materials");
  else
    v8 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v8);
  this->m_pMaterials = v8;
  v8->SetMultiline(this: v8, a2: true);
  this->m_pMaterials->SetEditable(this: this->m_pMaterials, a2: false);
  this->m_pMaterials->SetEnabled(this: this->m_pMaterials, a2: false);
  this->m_pMaterials->SetVerticalScrollbar(this: this->m_pMaterials, a2: true);
  this->m_pMaterials->SetVisible(this: this->m_pMaterials, a2: true);
  v9 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v9 != nullptr )
    v10 = vgui::Button::Button(
            this: v9,
            parent: this,
            panelName: "Explore",
            text: "Open",
            pActionSignalTarget: this,
            pCmd: "Explore");
  else
    v10 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v10);
  this->m_pExplore = v10;
  v10->SetVisible(this: v10, a2: true);
  v11 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v11 != nullptr )
    v12 = vgui::Button::Button(
            this: v11,
            parent: this,
            panelName: "Reload",
            text: "Reload",
            pActionSignalTarget: this,
            pCmd: "Reload");
  else
    v12 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v12);
  this->m_pReload = v12;
  v12->SetVisible(this: v12, a2: true);
  v13 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v13 != nullptr )
    v14 = vgui::Button::Button(
            this: v13,
            parent: this,
            panelName: "CopyTxt",
            text: "Copy Text",
            pActionSignalTarget: this,
            pCmd: "CopyTxt");
  else
    v14 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v14);
  this->m_pCopyTxt = v14;
  v14->SetVisible(this: v14, a2: true);
  v15 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v15 != nullptr )
    v16 = vgui::Button::Button(
            this: v15,
            parent: this,
            panelName: "CopyImg",
            text: "Copy Image",
            pActionSignalTarget: this,
            pCmd: "CopyImg");
  else
    v16 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v16);
  this->m_pCopyImg = v16;
  v16->SetVisible(this: v16, a2: true);
  v17 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v17 != nullptr )
    v18 = vgui::Button::Button(
            this: v17,
            parent: this,
            panelName: "FlashBtn",
            text: "Flash in Game",
            pActionSignalTarget: this,
            pCmd: "FlashBtn");
  else
    v18 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v18);
  this->m_pFlashBtn = v18;
  v18->SetVisible(this: v18, a2: true);
  v19 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v19 != nullptr )
    v20 = vgui::Button::Button(
            this: v19,
            parent: this,
            panelName: "--",
            text: "--",
            pActionSignalTarget: this,
            pCmd: "size-");
  else
    v20 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v20);
  this->m_pSizeControls[0] = v20;
  v21 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v21 != nullptr )
    v22 = vgui::Button::Button(
            this: v21,
            parent: this,
            panelName: "+",
            text: "+",
            pActionSignalTarget: this,
            pCmd: "size+");
  else
    v22 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v22);
  this->m_pSizeControls[1] = v22;
  v23 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v23 != nullptr )
    v24 = vgui::CheckButton::CheckButton(this: v23, parent: this, panelName: "Exclude", text: "Exclude");
  else
    v24 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v24);
  this->m_pSizeControls[2] = v24;
  v24->AddActionSignalTarget_2(this: v24, a2: this);
  this->m_pSizeControls[2]->SetCommand(this: this->m_pSizeControls[2], a2: "Exclude");
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10097940
// Name: public: virtual void CRenderTextureEditor::SetFont(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRenderTextureEditor::SetFont(CRenderTextureEditor *this, unsigned int hFont)
{
  CRenderTextureEditor_vtbl *v2; // edx

  v2 = this->__vftable;
  this->m_hFont = hFont;
  ((void (*)(void))v2->Repaint)();
}

//------------------------------------------------------------------------------
// Address: 0x10097970
// Name: public: virtual struct vgui::PanelMessageMap __near * CRenderTextureEditor::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CRenderTextureEditor::GetMessageMap(CRenderTextureEditor *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CRenderTextureEditor::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CRenderTextureEditor::GetMessageMap'::`2'::s_pMap;
  `CRenderTextureEditor::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CRenderTextureEditor");
  `CRenderTextureEditor::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100979A0
// Name: public: virtual struct PanelAnimationMap __near * CRenderTextureEditor::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CRenderTextureEditor::GetAnimMap(CRenderTextureEditor *this)
{
  return FindOrAddPanelAnimationMap(className: "CRenderTextureEditor");
}

//------------------------------------------------------------------------------
// Address: 0x100979B0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CRenderTextureEditor::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CRenderTextureEditor::GetKBMap(CRenderTextureEditor *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CRenderTextureEditor::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CRenderTextureEditor::GetKBMap'::`2'::s_pMap;
  `CRenderTextureEditor::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CRenderTextureEditor");
  `CRenderTextureEditor::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100979E0
// Name: public: CRenderTexturesListViewPanel::CRenderTexturesListViewPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CRenderTexturesListViewPanel *__thiscall CRenderTexturesListViewPanel::CRenderTexturesListViewPanel(
        CRenderTexturesListViewPanel *this,
        vgui::Panel *parent,
        const char *szName)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CRenderTextureEditor *v7; // eax
  CRenderTextureEditor *v8; // eax

  vgui::TileViewPanelEx::TileViewPanelEx(this, parent, panelName: szName);
  this->__vftable = (CRenderTexturesListViewPanel_vtbl *)&CRenderTexturesListViewPanel::`vftable';
  if ( `CRenderTexturesListViewPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CRenderTexturesListViewPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CRenderTexturesListViewPanel");
    v4->pfnClassName = CRenderTexturesListViewPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::TileViewPanelEx");
  }
  if ( `CRenderTexturesListViewPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CRenderTexturesListViewPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CRenderTexturesListViewPanel");
    v5->pfnClassName = CRenderTexturesListViewPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::TileViewPanelEx");
  }
  if ( `CRenderTexturesListViewPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CRenderTexturesListViewPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CRenderTexturesListViewPanel");
    v6->pfnClassName = CRenderTexturesListViewPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::TileViewPanelEx");
  }
  this->m_pListPanel = nullptr;
  this->m_bPaintAlpha = false;
  v7 = (CRenderTextureEditor *)MemAlloc_Alloc(nSize: 0x288u);
  if ( v7 != nullptr )
    v8 = CRenderTextureEditor::CRenderTextureEditor(this: v7, parent: this, szName: "TxEdt");
  else
    v8 = nullptr;
  this->m_pRenderTxEditor = v8;
  vgui::Panel::SetPos(this: v8, x: 10, y: 10);
  this->m_pRenderTxEditor->PerformLayout(this: this->m_pRenderTxEditor);
  this->m_pRenderTxEditor->SetMoveable(this: this->m_pRenderTxEditor, a2: true);
  this->m_pRenderTxEditor->SetSizeable(this: this->m_pRenderTxEditor, a2: false);
  this->m_pRenderTxEditor->SetClipToParent(this: this->m_pRenderTxEditor, a2: true);
  this->m_pRenderTxEditor->SetTitle_2(this: this->m_pRenderTxEditor, a2: defaultValue, a3: true);
  this->m_pRenderTxEditor->SetCloseButtonVisible(this: this->m_pRenderTxEditor, a2: false);
  this->m_pRenderTxEditor->SetVisible(this: this->m_pRenderTxEditor, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10097B70
// Name: public: virtual struct vgui::PanelMessageMap __near * CRenderTexturesListViewPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CRenderTexturesListViewPanel::GetMessageMap(CRenderTexturesListViewPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CRenderTexturesListViewPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CRenderTexturesListViewPanel::GetMessageMap'::`2'::s_pMap;
  `CRenderTexturesListViewPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CRenderTexturesListViewPanel");
  `CRenderTexturesListViewPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10097BA0
// Name: public: virtual struct PanelAnimationMap __near * CRenderTexturesListViewPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CRenderTexturesListViewPanel::GetAnimMap(CRenderTexturesListViewPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CRenderTexturesListViewPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10097BB0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CRenderTexturesListViewPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CRenderTexturesListViewPanel::GetKBMap(CRenderTexturesListViewPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CRenderTexturesListViewPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CRenderTexturesListViewPanel::GetKBMap'::`2'::s_pMap;
  `CRenderTexturesListViewPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CRenderTexturesListViewPanel");
  `CRenderTexturesListViewPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10097C20
// Name: public: CTextureListPanel::CTextureListPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CTextureListPanel *__thiscall CTextureListPanel::CTextureListPanel(CTextureListPanel *this, vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  int v6; // eax
  vgui::Label *v7; // eax
  vgui::Label *v8; // edi
  vgui::Label *v9; // eax
  vgui::Label *v10; // edi
  vgui::CheckButton *v11; // eax
  vgui::CheckButton *v12; // edi
  vgui::CheckButton *v13; // eax
  vgui::CheckButton *v14; // edi
  CConVarCheckButton *v15; // eax
  CConVarCheckButton *v16; // edi
  CConVarCheckButton *v17; // eax
  CConVarCheckButton *v18; // edi
  CConVarCheckButton *v19; // eax
  CConVarCheckButton *v20; // edi
  vgui::Button *v21; // eax
  vgui::Button *v22; // edi
  vgui::ToggleButton *v23; // eax
  vgui::ToggleButton *v24; // edi
  vgui::CheckButton *v25; // eax
  vgui::CheckButton *v26; // edi
  vgui::CheckButton *v27; // eax
  vgui::CheckButton *v28; // edi
  vgui::CheckButton *v29; // eax
  vgui::CheckButton *v30; // edi
  vgui::TextEntry *v31; // eax
  vgui::TextEntry *v32; // edi
  vgui::ListPanel *v33; // eax
  vgui::ListPanel *v34; // edi
  int m_nValue; // eax
  CRenderTexturesListViewPanel *v36; // eax
  CRenderTexturesListViewPanel *v37; // edi
  int v38; // eax
  CRenderTexturesListViewPanel *m_pViewPanel; // ecx
  void (*Repaint)(void); // eax
  CRenderTexturesListViewPanel *v41; // ecx
  CRenderTexturesListViewPanel_vtbl *v42; // eax
  int v44; // [esp+19Ch] [ebp-10h]
  int savedregs; // [esp+1ACh] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: "CTextureListPanel", showTaskbarIcon: true, bPopup: true);
  this->__vftable = (CTextureListPanel_vtbl *)&CTextureListPanel::`vftable';
  if ( `CTextureListPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CTextureListPanel::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CTextureListPanel");
    v3->pfnClassName = CTextureListPanel::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CTextureListPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CTextureListPanel::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CTextureListPanel");
    v4->pfnClassName = CTextureListPanel::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CTextureListPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CTextureListPanel::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CTextureListPanel");
    v5->pfnClassName = CTextureListPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  CTextureListPanel::PanelMessageFunc_OnTextChanged::InitVar(a1: (int)&savedregs);
  this->m_numDisplayedSizeKB = 0;
  v44 = videomode->GetModeHeight(this: videomode) - 20;
  v6 = videomode->GetModeWidth(this: videomode);
  vgui::Panel::SetSize(this, wide: v6 - 20, tall: v44);
  vgui::Panel::SetPos(this, x: 10, y: 10);
  vgui::Panel::SetVisible(this, state: true);
  vgui::Panel::SetCursor(this, cursor: 0);
  vgui::Frame::SetTitle(this, title: "Texture list", surfaceTitle: false);
  vgui::Frame::SetMenuButtonVisible(this, state: false);
  this->m_hFont = 0;
  CBaseDemoAction::SetTimingType(this, color: (Color)-16777216);
  vgui::Panel::SetPaintBackgroundEnabled(this, state: true);
  v7 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v7 != nullptr )
    v8 = vgui::Label::Label(
           this: v7,
           parent: this,
           panelName: "m_pCVarListLabel",
           text: "cvars: mat_texture_limit, mat_texture_list, mat_picmip, mat_texture_list_txlod, mat_texture_list_txlod_sync");
  else
    v8 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v8);
  this->m_pCVarListLabel = v8;
  v8->SetVisible(this: v8, a2: false);
  v9 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v9 != nullptr )
    v10 = vgui::Label::Label(this: v9, parent: this, panelName: "m_pTotalUsageLabel", text: defaultValue);
  else
    v10 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v10);
  this->m_pTotalUsageLabel = v10;
  v10->SetVisible(this: v10, a2: true);
  v11 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v11 != nullptr )
    v12 = vgui::CheckButton::CheckButton(
            this: v11,
            parent: this,
            panelName: "service",
            text: "Render Targets and Special Textures");
  else
    v12 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v12);
  this->m_pSpecialTexs = v12;
  v12->SetVisible(this: v12, a2: true);
  this->m_pSpecialTexs->AddActionSignalTarget_2(this: this->m_pSpecialTexs, a2: this);
  this->m_pSpecialTexs->SetCommand(this: this->m_pSpecialTexs, a2: "service");
  v13 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v13 != nullptr )
    v14 = vgui::CheckButton::CheckButton(
            this: v13,
            parent: this,
            panelName: "resolvepath",
            text: "Resolve Full Texture Path");
  else
    v14 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v14);
  this->m_pResolveTexturePath = v14;
  v14->SetVisible(this: v14, a2: true);
  this->m_pResolveTexturePath->AddActionSignalTarget_2(this: this->m_pResolveTexturePath, a2: this);
  this->m_pResolveTexturePath->SetCommand(this: this->m_pResolveTexturePath, a2: "resolvepath");
  v15 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v15 != nullptr )
    v16 = CConVarCheckButton::CConVarCheckButton(
            this: v15,
            parent: this,
            panelName: "m_pShowTextureMemoryUsageOption",
            text: "Show Memory Usage on HUD");
  else
    v16 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v16);
  this->m_pShowTextureMemoryUsageOption = v16;
  v16->SetVisible(this: v16, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pShowTextureMemoryUsageOption, pVar: &mat_show_texture_memory_usage);
  v17 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v17 != nullptr )
    v18 = CConVarCheckButton::CConVarCheckButton(
            this: v17,
            parent: this,
            panelName: "m_pAllTextures",
            text: "Show ALL textures");
  else
    v18 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v18);
  this->m_pAllTextures = v18;
  v18->SetVisible(this: v18, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pAllTextures, pVar: &mat_texture_list_all);
  this->m_pAllTextures->AddActionSignalTarget_2(this: this->m_pAllTextures, a2: this);
  this->m_pAllTextures->SetCommand(this: this->m_pAllTextures, a2: "AllTextures");
  v19 = (CConVarCheckButton *)MemAlloc_Alloc(nSize: 0x21Cu);
  if ( v19 != nullptr )
    v20 = CConVarCheckButton::CConVarCheckButton(
            this: v19,
            parent: this,
            panelName: "m_pViewTextures",
            text: "View textures thumbnails");
  else
    v20 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v20);
  this->m_pViewTextures = v20;
  v20->SetVisible(this: v20, a2: true);
  CConVarCheckButton::SetConVar(this: this->m_pViewTextures, pVar: &mat_texture_list_view);
  this->m_pViewTextures->AddActionSignalTarget_2(this: this->m_pViewTextures, a2: this);
  this->m_pViewTextures->SetCommand(this: this->m_pViewTextures, a2: "ViewThumbnails");
  v21 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v21 != nullptr )
    v22 = vgui::Button::Button(
            this: v21,
            parent: this,
            panelName: "CopyToClipboard",
            text: "Copy to Clipboard",
            pActionSignalTarget: nullptr,
            pCmd: nullptr);
  else
    v22 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v22);
  this->m_pCopyToClipboardButton = v22;
  if ( v22 != nullptr )
  {
    v22->AddActionSignalTarget_2(this: v22, a2: this);
    this->m_pCopyToClipboardButton->SetCommand(this: this->m_pCopyToClipboardButton, a2: "CopyToClipboard");
  }
  v23 = (vgui::ToggleButton *)MemAlloc_Alloc(nSize: 0x1FCu);
  if ( v23 != nullptr )
    v24 = vgui::ToggleButton::ToggleButton(this: v23, parent: this, panelName: "Collapse", text: " ");
  else
    v24 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v24);
  this->m_pCollapse = v24;
  v24->AddActionSignalTarget_2(this: v24, a2: this);
  this->m_pCollapse->SetCommand(this: this->m_pCollapse, a2: "Collapse");
  this->m_pCollapse->SetSelected(this: this->m_pCollapse, a2: true);
  v25 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v25 != nullptr )
    v26 = vgui::CheckButton::CheckButton(this: v25, parent: this, panelName: "ShowAlpha", text: "Alpha");
  else
    v26 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v26);
  this->m_pAlpha = v26;
  v26->AddActionSignalTarget_2(this: v26, a2: this);
  this->m_pAlpha->SetCommand(this: this->m_pAlpha, a2: "ShowAlpha");
  this->m_pAlpha->SetSelected(this: this->m_pAlpha, a2: true);
  v27 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v27 != nullptr )
    v28 = vgui::CheckButton::CheckButton(this: v27, parent: this, panelName: "ThumbWarnings", text: "Warns");
  else
    v28 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v28);
  this->m_pThumbWarnings = v28;
  v28->AddActionSignalTarget_2(this: v28, a2: this);
  this->m_pThumbWarnings->SetCommand(this: this->m_pThumbWarnings, a2: "ThumbWarnings");
  this->m_pThumbWarnings->SetSelected(this: this->m_pThumbWarnings, a2: g_warn_enable);
  v29 = (vgui::CheckButton *)MemAlloc_Alloc(nSize: 0x218u);
  if ( v29 != nullptr )
    v30 = vgui::CheckButton::CheckButton(this: v29, parent: this, panelName: "FilteringChk", text: "Filter: ");
  else
    v30 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v30);
  this->m_pFilteringChk = v30;
  v30->AddActionSignalTarget_2(this: v30, a2: this);
  this->m_pFilteringChk->SetCommand(this: this->m_pFilteringChk, a2: "FilteringChk");
  this->m_pFilteringChk->SetSelected(this: this->m_pFilteringChk, a2: true);
  v31 = (vgui::TextEntry *)MemAlloc_Alloc(nSize: 0x43Cu);
  if ( v31 != nullptr )
    v32 = vgui::TextEntry::TextEntry(this: v31, parent: this, panelName: "FilteringTxt");
  else
    v32 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v32);
  this->m_pFilteringText = v32;
  v32->AddActionSignalTarget_2(this: v32, a2: this);
  v33 = (vgui::ListPanel *)MemAlloc_Alloc(nSize: 0x24Cu);
  if ( v33 != nullptr )
    v34 = vgui::ListPanel::ListPanel(this: v33, parent: this, panelName: "List Panel");
  else
    v34 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v34);
  this->m_pListPanel = v34;
  if ( mat_texture_list_view.m_pParent != nullptr )
    m_nValue = mat_texture_list_view.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v34->SetVisible(this: v34, a2: m_nValue == 0);
  this->m_pListPanel->AddColumnHeader_2(
    this: this->m_pListPanel,
    a2: 0,
    a3: "Name",
    a4: "Texture Name",
    a5: 200,
    a6: 100,
    a7: 700,
    a8: 2);
  this->m_pListPanel->AddColumnHeader_2(
    this: this->m_pListPanel,
    a2: 1,
    a3: "Path",
    a4: "Path",
    a5: 50,
    a6: 50,
    a7: 300,
    a8: 0);
  this->m_pListPanel->AddColumnHeader_2(
    this: this->m_pListPanel,
    a2: 2,
    a3: "Size",
    a4: "Kilobytes",
    a5: 50,
    a6: 50,
    a7: 50,
    a8: 0);
  this->m_pListPanel->SetSortFunc(this: this->m_pListPanel, a2: 2, a3: KilobytesSortFunc);
  this->m_pListPanel->SetSortColumnEx(this: this->m_pListPanel, a2: 2, a3: 0, a4: true);
  this->m_pListPanel->AddColumnHeader_2(
    this: this->m_pListPanel,
    a2: 3,
    a3: "TexGroup",
    a4: "Group",
    a5: 100,
    a6: 100,
    a7: 300,
    a8: 0);
  this->m_pListPanel->AddColumnHeader_2(
    this: this->m_pListPanel,
    a2: 4,
    a3: "Format",
    a4: "Format",
    a5: 250,
    a6: 50,
    a7: 300,
    a8: 0);
  this->m_pListPanel->AddColumnHeader_2(
    this: this->m_pListPanel,
    a2: 5,
    a3: "Width",
    a4: "Width",
    a5: 50,
    a6: 50,
    a7: 50,
    a8: 0);
  this->m_pListPanel->AddColumnHeader_2(
    this: this->m_pListPanel,
    a2: 6,
    a3: "Height",
    a4: "Height",
    a5: 50,
    a6: 50,
    a7: 50,
    a8: 0);
  this->m_pListPanel->AddColumnHeader_2(
    this: this->m_pListPanel,
    a2: 7,
    a3: "BindsFrame",
    a4: "# Binds",
    a5: 50,
    a6: 50,
    a7: 50,
    a8: 0);
  this->m_pListPanel->AddColumnHeader_2(
    this: this->m_pListPanel,
    a2: 8,
    a3: "BindsMax",
    a4: "BindsMax",
    a5: 50,
    a6: 50,
    a7: 50,
    a8: 0);
  CBaseDemoAction::SetStartTick(this, color: (Color)1677721600);
  ((void (__thiscall *)(vgui::ListPanel *, int))this->m_pListPanel->SetBgColor)(a1: this->m_pListPanel, a2: 1677721600);
  v36 = (CRenderTexturesListViewPanel *)MemAlloc_Alloc(nSize: 0x194u);
  if ( v36 != nullptr )
    v37 = CRenderTexturesListViewPanel::CRenderTexturesListViewPanel(this: v36, parent: this, szName: "View Panel");
  else
    v37 = nullptr;
  vgui::Panel::MakeReadyForUse(this: v37);
  this->m_pViewPanel = v37;
  if ( mat_texture_list_view.m_pParent != nullptr )
    v38 = mat_texture_list_view.m_pParent->m_Value.m_nValue;
  else
    v38 = 0;
  v37->SetVisible(this: v37, a2: v38 != 0);
  ((void (__thiscall *)(CRenderTexturesListViewPanel *, int))this->m_pViewPanel->SetBgColor)(
    a1: this->m_pViewPanel,
    a2: -16777216);
  this->m_pViewPanel->SetDragEnabled(this: this->m_pViewPanel, a2: false);
  ((void (__stdcall *)(_DWORD, _DWORD))this->m_pViewPanel->SetDropEnabled)(a1: 0, a2: 0.0);
  m_pViewPanel = this->m_pViewPanel;
  Repaint = (void (*)(void))m_pViewPanel->Repaint;
  m_pViewPanel->m_bPaintAlpha = true;
  Repaint();
  v41 = this->m_pViewPanel;
  v42 = v41->__vftable;
  v41->m_pListPanel = this->m_pListPanel;
  ((void (__stdcall *)(_DWORD, _DWORD))v42->InvalidateLayout)(a1: 0, a2: 0);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10098520
// Name: void CL_CreateTextureListPanel(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_CreateTextureListPanel(vgui::Panel *parent)
{
  CTextureListPanel *v1; // eax

  v1 = (CTextureListPanel *)MemAlloc_Alloc(nSize: 0x258u);
  if ( v1 != nullptr )
    g_pTextureListPanel = CTextureListPanel::CTextureListPanel(this: v1, parent);
  else
    g_pTextureListPanel = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10098780
// Name: UseDebugMaterial
// Source: json
//------------------------------------------------------------------------------
IMaterial *__usercall UseDebugMaterial@<eax>(
        const char *szMaterial@<eax>,
        int a2@<edi>,
        int a3@<esi>,
        ITexture *pMatTexture,
        CAutoMatSysDebugMode *pRestoreVars)
{
  ITexture *v5; // ebx
  IMaterial *result; // eax
  IMaterial *v7; // esi
  IMaterialVar *v8; // eax
  IMaterialVar *v9; // edi
  IMaterialVar *v10; // eax
  int v11; // ebx
  int v12; // edx
  IMaterialVar *FrameVar; // [esp+4h] [ebp-8h] BYREF
  bool foundVar; // [esp+Bh] [ebp-1h] BYREF

  if ( szMaterial == nullptr )
    return nullptr;
  v5 = pMatTexture;
  if ( pMatTexture == nullptr )
    return nullptr;
  result = materials->FindMaterial(this: materials, a2: szMaterial, a3: "Other textures", a4: 0, a5: 0);
  v7 = result;
  if ( result != nullptr )
  {
    v8 = result->FindVar(this: result, a2: "$basetexture", a3: &foundVar, a4: 0);
    v9 = v8;
    if ( foundVar && v8 != nullptr )
    {
      v10 = (IMaterialVar *)((int (__thiscall *)(IMaterial *, const char *, bool *, _DWORD, int))v7->FindVar)(
                              a1: v7,
                              a2: "$frame",
                              a3: &foundVar,
                              a4: 0,
                              a5: a2);
      FrameVar = v10;
      if ( foundVar && v10 != nullptr )
      {
        v11 = ((int (__thiscall *)(ITexture *, int))pMatTexture->GetNumAnimationFrames)(a1: pMatTexture, a2: a3);
        if ( pMatTexture->IsRenderTarget(this: pMatTexture) || pMatTexture->IsProcedural(this: pMatTexture) || v11 <= 0 )
          v12 = 0;
        else
          v12 = g_ClientGlobalVariables.tickcount % v11;
        FrameVar->SetIntValue(this: FrameVar, a2: v12);
        v5 = pMatTexture;
      }
      v9->SetTextureValue(this: v9, a2: v5);
      if ( pRestoreVars != nullptr )
      {
        FrameVar = v9;
        CUtlRBTree<IMaterialVar *,unsigned short,bool (__cdecl *)(IMaterialVar * const &,IMaterialVar * const &),CUtlMemory<UtlRBTreeNode_t<IMaterialVar *,unsigned short>,unsigned short>>::InsertIfNotFound(
          this: &pRestoreVars->arrCleanupVars,
          insert: &FrameVar);
      }
      return v7;
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10098890
// Name: public: virtual void CVmtTextEntry::OpenVmtSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVmtTextEntry::OpenVmtSelected(CVmtTextEntry *this)
{
  bool (__thiscall *GetSelectedRange)(vgui::TextEntry *, int *, int *); // eax
  int v2; // ecx
  char *m_pMemory; // ebx
  int v4; // esi
  int m_Size; // eax
  char *v6; // edi
  char *v7; // eax
  char *v8; // esi
  const char *v9; // eax
  char chResolveName[256]; // [esp+0h] [ebp-220h] BYREF
  char chResolveNameArg[256]; // [esp+100h] [ebp-120h] BYREF
  CUtlVector<char,CUtlMemory<char,int> > buf; // [esp+200h] [ebp-20h] BYREF
  CVmtTextEntry *v13; // [esp+214h] [ebp-Ch]
  int x0; // [esp+218h] [ebp-8h] BYREF
  int x1; // [esp+21Ch] [ebp-4h] BYREF

  GetSelectedRange = this->GetSelectedRange;
  v13 = this;
  if ( ((unsigned __int8 (__stdcall *)(int *, int *))GetSelectedRange)(a1: &x0, a2: &x1) != 0 )
  {
    v2 = x1;
    m_pMemory = nullptr;
    v4 = x1 - x0 + 1;
    m_Size = 0;
    memset(&buf, 0, sizeof(buf));
    if ( x1 - x0 != -1 )
    {
      if ( v4 > 0 )
      {
        CUtlMemory<bool,int>::Grow(this: &buf.m_Memory, num: x1 - x0 + 1);
        v2 = x1;
        m_Size = buf.m_Size;
        m_pMemory = buf.m_Memory.m_pMemory;
      }
      if ( m_Size > 0 && v4 > 0 )
      {
        _V_memmove(dest: &m_pMemory[v4], src: m_pMemory, count: m_Size);
        v2 = x1;
      }
    }
    v13->GetTextRange(this: v13, a2: m_pMemory, a3: x0, a4: v2 - x0);
    v6 = m_pMemory;
    if ( m_pMemory != nullptr )
    {
      do
      {
        strchr(string: v6, chr: 0xAu);
        v8 = v7;
        if ( v7 != nullptr )
        {
          *v7 = 0;
          v8 = v7 + 1;
        }
        memset(chResolveName, 0, sizeof(chResolveName));
        memset(chResolveNameArg, 0, sizeof(chResolveNameArg));
        V_snprintf(pDest: chResolveNameArg, maxLen: 255, pFormat: "materials/%s.vmt", v6);
        v9 = g_pFileSystem->RelativePathToFullPath(
               this: g_pFileSystem,
               a2: chResolveNameArg,
               a3: "game",
               a4: chResolveName,
               a5: 255,
               a6: 0,
               a7: 0);
        if ( v9 != nullptr )
          g_pVGuiSystem->ShellExecuteEx(this: g_pVGuiSystem, a2: "open", a3: v9, a4: defaultValue);
        v6 = v8;
      }
      while ( v8 != nullptr );
    }
    if ( buf.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10098A20
// Name: public: void CRenderTextureEditor::SetDispInfo(class KeyValues __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRenderTextureEditor::SetDispInfo(CRenderTextureEditor *this, KeyValues *kv, int iHint)
{
  KeyValues *m_pInfo; // ecx
  int v5; // edi
  KeyValues *v6; // esi
  KeyValues *Copy; // eax
  const char *String; // eax
  IMaterialSystem_vtbl *v9; // edx
  int v10; // esi
  unsigned __int16 (__thiscall *InvalidMaterial)(IMaterialSystem *); // eax
  IMaterial *v12; // esi
  int v13; // ebx
  IMaterialVar **(__thiscall *GetShaderParams)(IMaterial *); // edx
  IMaterialVar **v15; // eax
  IMaterialVar *v16; // ecx
  int v17; // ebx
  const char *v18; // eax
  const char *v19; // eax
  bool v20; // bl
  const char *v21; // eax
  int v22; // eax
  int v23; // eax
  unsigned __int8 *v24; // edi
  int i; // ebx
  _BYTE *v26; // eax
  int v27; // edi
  const char *v28; // eax
  int v29; // esi
  const char *v30; // eax
  int m_Id; // edi
  const char *v32; // eax
  int v33; // esi
  int v34; // esi
  unsigned __int16 (__thiscall *v35)(IMaterialSystem *); // eax
  const char *v36; // eax
  unsigned __int16 m_NumElements; // ax
  int v38; // esi
  const char *v39; // eax
  CRenderTextureEditor *v40; // esi
  int v41; // eax
  unsigned __int16 *m_pMemory; // edx
  unsigned __int16 *v43; // eax
  int v44; // ebx
  const char *v45; // eax
  CUtlSymbol *v46; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  unsigned __int16 *v49; // ecx
  int v50; // eax
  unsigned __int16 *v51; // edi
  bool *v52; // eax
  bool *v53; // eax
  const char *v54; // [esp-4h] [ebp-1F8h]
  unsigned int v55; // [esp-4h] [ebp-1F8h]
  char chName[260]; // [esp+Ch] [ebp-1E8h] BYREF
  CUtlBuffer bufText; // [esp+110h] [ebp-E4h] BYREF
  CUtlStringMap<bool> arrMaterials; // [esp+140h] [ebp-B4h] BYREF
  CUtlStringMap<bool> arrMaterialsFullNames; // [esp+18Ch] [ebp-68h] BYREF
  const char *szTextureName; // [esp+1D8h] [ebp-1Ch]
  IMaterialVar **arrVars; // [esp+1DCh] [ebp-18h]
  int numParams; // [esp+1E0h] [ebp-14h]
  CRenderTextureEditor *v63; // [esp+1E4h] [ebp-10h]
  CUtlSymbol result; // [esp+1E8h] [ebp-Ch] BYREF
  int hm; // [esp+1ECh] [ebp-8h]
  CUtlSymbol v66; // [esp+1F0h] [ebp-4h] BYREF

  m_pInfo = this->m_pInfo;
  v5 = 0;
  v63 = this;
  this->m_iInfoHint = iHint;
  if ( m_pInfo != nullptr )
    KeyValues::deleteThis(this: m_pInfo);
  v6 = kv;
  if ( kv != nullptr )
    Copy = KeyValues::MakeCopy(this: kv);
  else
    Copy = nullptr;
  this->m_pInfo = Copy;
  arrMaterials.m_Vector.m_Memory.m_pMemory = nullptr;
  arrMaterials.m_Vector.m_Memory.m_nAllocationCount = 0;
  arrMaterials.m_Vector.m_Memory.m_nGrowSize = 32;
  arrMaterials.m_Vector.m_Size = 0;
  arrMaterials.m_Vector.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(this: &arrMaterials.m_SymbolTable, growSize: 0, initSize: 32, caseInsensitive: true);
  arrMaterialsFullNames.m_Vector.m_Memory.m_pMemory = nullptr;
  arrMaterialsFullNames.m_Vector.m_Memory.m_nAllocationCount = 0;
  arrMaterialsFullNames.m_Vector.m_Memory.m_nGrowSize = 32;
  arrMaterialsFullNames.m_Vector.m_Size = 0;
  arrMaterialsFullNames.m_Vector.m_pElements = nullptr;
  CUtlSymbolTable::CUtlSymbolTable(
    this: &arrMaterialsFullNames.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  if ( v6 == nullptr )
    goto LABEL_37;
  String = KeyValues::GetString(this: v6, keyName: "Name", defaultValue: defaultValue);
  v9 = materials->__vftable;
  szTextureName = String;
  v10 = v9->FirstMaterial(this: materials);
  InvalidMaterial = materials->InvalidMaterial;
  hm = v10;
  if ( (_WORD)v10 == InvalidMaterial(this: materials) )
    goto LABEL_37;
  do
  {
    v12 = materials->GetMaterial(this: materials, a2: hm);
    if ( v12 == nullptr )
      goto LABEL_36;
    v13 = v12->ShaderParamCount(this: v12);
    GetShaderParams = v12->GetShaderParams;
    numParams = v13;
    v15 = GetShaderParams(this: v12);
    arrVars = v15;
    if ( v13 <= 0 )
      goto LABEL_35;
    while ( 1 )
    {
      v16 = v15[v5];
      if ( (*((_BYTE *)v16 + 28) & 0xF) == 3 )
        break;
LABEL_15:
      if ( ++v5 >= v13 )
        goto LABEL_35;
    }
    v17 = v16->GetTextureValue(this: v16);
    if ( v17 == 0
      || (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v17 + 60))(a1: v17) != 0
      || (v54 = szTextureName,
          v18 = (const char *)(**(int (__thiscall ***)(int))v17)(a1: v17),
          _V_stricmp(s1: v18, s2: v54) != 0) )
    {
      v13 = numParams;
      v15 = arrVars;
      goto LABEL_15;
    }
    v19 = (const char *)v12->GetName(this: v12);
    v20 = StringAfterPrefix(str: v19, prefix: "debug/debugtexture") == nullptr;
    v21 = (const char *)v12->GetName(this: v12);
    if ( StringAfterPrefix(str: v21, prefix: "maps/") != nullptr )
    {
      v22 = v12->GetName(this: v12);
      V_strncpy(pDest: chName, pSrc: (const char *)(v22 + 5), maxLen: 259);
      strchr(string: chName, chr: 0x2Fu);
      if ( v23 != 0 )
      {
        v24 = (unsigned __int8 *)(v23 + 1);
        for ( i = 3; i != 0; --i )
        {
          strrchr(string: v24, chr: 0x5Fu);
          if ( v26 != nullptr )
            *v26 = 0;
        }
        sprintf(string: (char *)&v24[strlen((const char *)v24)], format: " (cubemap)");
        CUtlSymbolTable::AddString(
          this: &arrMaterials.m_SymbolTable,
          result: (CUtlSymbol *)&iHint,
          pString: (const char *)v24);
        v27 = (unsigned __int16)iHint;
        if ( arrMaterials.m_Vector.m_Size <= (unsigned __int16)iHint )
          CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCount(
            this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&arrMaterials,
            num: (unsigned __int16)iHint + 1);
        arrMaterials.m_Vector.m_Memory.m_pMemory[v27] = true;
      }
      v28 = (const char *)v12->GetName(this: v12);
      CUtlSymbolTable::AddString(this: &arrMaterialsFullNames.m_SymbolTable, result: (CUtlSymbol *)&kv, pString: v28);
      v29 = (unsigned __int16)kv;
      if ( arrMaterialsFullNames.m_Vector.m_Size <= (unsigned __int16)kv )
        CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCount(
          this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&arrMaterialsFullNames,
          num: (unsigned __int16)kv + 1);
      arrMaterialsFullNames.m_Vector.m_Memory.m_pMemory[v29] = true;
    }
    else if ( v20 )
    {
      v30 = (const char *)v12->GetName(this: v12);
      CUtlSymbolTable::AddString(this: &arrMaterials.m_SymbolTable, &result, pString: v30);
      m_Id = result.m_Id;
      if ( arrMaterials.m_Vector.m_Size <= result.m_Id )
        CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCount(
          this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&arrMaterials,
          num: result.m_Id + 1);
      arrMaterials.m_Vector.m_Memory.m_pMemory[m_Id] = true;
      v32 = (const char *)v12->GetName(this: v12);
      CUtlSymbolTable::AddString(this: &arrMaterialsFullNames.m_SymbolTable, result: &v66, pString: v32);
      v33 = v66.m_Id;
      if ( arrMaterialsFullNames.m_Vector.m_Size <= v66.m_Id )
        CUtlVector<bool,CUtlMemory<bool,int>>::EnsureCount(
          this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&arrMaterialsFullNames,
          num: v66.m_Id + 1);
      arrMaterialsFullNames.m_Vector.m_Memory.m_pMemory[v33] = true;
    }
LABEL_35:
    v5 = 0;
LABEL_36:
    v34 = materials->NextMaterial(this: materials, a2: hm);
    v35 = materials->InvalidMaterial;
    hm = v34;
  }
  while ( (_WORD)v34 != v35(this: materials) );
LABEL_37:
  CUtlBuffer::CUtlBuffer(this: &bufText, growSize: 0, initSize: 0, nFlags: 1);
  if ( arrMaterials.m_SymbolTable.m_Lookup.m_NumElements != 0 )
  {
    if ( arrMaterials.m_SymbolTable.m_Lookup.m_NumElements % 10 != 1
      || (v36 = defaultValue, arrMaterials.m_SymbolTable.m_Lookup.m_NumElements == 11) )
    {
      v36 = "s";
    }
    CUtlBuffer::Printf(this: &bufText, pFmt: "  %d material%s:", arrMaterials.m_SymbolTable.m_Lookup.m_NumElements, v36);
  }
  else
  {
    CUtlBuffer::Printf(this: &bufText, pFmt: "-- no materials --");
  }
  m_NumElements = arrMaterials.m_SymbolTable.m_Lookup.m_NumElements;
  v38 = 0;
  if ( arrMaterials.m_SymbolTable.m_Lookup.m_NumElements != 0 )
  {
    do
    {
      v39 = CUtlSymbolTable::String(this: &arrMaterials.m_SymbolTable, id: (CUtlSymbol)v38);
      CUtlBuffer::Printf(this: &bufText, pFmt: "\n%s", v39);
      m_NumElements = arrMaterials.m_SymbolTable.m_Lookup.m_NumElements;
      ++v38;
    }
    while ( v38 < arrMaterials.m_SymbolTable.m_Lookup.m_NumElements );
  }
  v40 = v63;
  if ( v63->m_pInfo == nullptr || m_NumElements != 0 )
  {
    v63->m_pMaterials->SetText(this: v63->m_pMaterials, a2: (const char *)bufText.m_Memory.m_pMemory);
    v41 = arrMaterialsFullNames.m_SymbolTable.m_Lookup.m_NumElements;
    v40->m_lstMaterials.m_Size = 0;
    if ( v40->m_lstMaterials.m_Memory.m_nAllocationCount < v41 && v40->m_lstMaterials.m_Memory.m_nGrowSize >= 0 )
    {
      m_pMemory = v40->m_lstMaterials.m_Memory.m_pMemory;
      v40->m_lstMaterials.m_Memory.m_nAllocationCount = v41;
      v55 = 2 * v41;
      if ( m_pMemory != nullptr )
        v43 = (unsigned __int16 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v55);
      else
        v43 = (unsigned __int16 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v55);
      v40->m_lstMaterials.m_Memory.m_pMemory = v43;
    }
    v44 = 0;
    v40->m_lstMaterials.m_pElements = v40->m_lstMaterials.m_Memory.m_pMemory;
    if ( arrMaterialsFullNames.m_SymbolTable.m_Lookup.m_NumElements != 0 )
    {
      do
      {
        v45 = CUtlSymbolTable::String(this: &arrMaterialsFullNames.m_SymbolTable, id: (CUtlSymbol)v44);
        v46 = CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&iHint + 1, pStr: v45);
        m_Size = v40->m_lstMaterials.m_Size;
        kv = (KeyValues *)v46->m_Id;
        m_nAllocationCount = v40->m_lstMaterials.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<wchar_t,int>::Grow(
            this: (CUtlMemory<wchar_t,int> *)&v40->m_lstMaterials,
            num: m_Size - m_nAllocationCount + 1);
        ++v40->m_lstMaterials.m_Size;
        v49 = v40->m_lstMaterials.m_Memory.m_pMemory;
        v50 = v40->m_lstMaterials.m_Size - m_Size - 1;
        v40->m_lstMaterials.m_pElements = v49;
        if ( v50 > 0 )
          _V_memmove(dest: &v49[m_Size + 1], src: &v49[m_Size], count: 2 * v50);
        v51 = &v40->m_lstMaterials.m_Memory.m_pMemory[m_Size];
        if ( v51 != nullptr )
          *v51 = (unsigned __int16)kv;
        ++v44;
      }
      while ( v44 < arrMaterialsFullNames.m_SymbolTable.m_Lookup.m_NumElements );
    }
  }
  v40->m_bufInfoText.m_Get = 0;
  v40->m_bufInfoText.m_Put = 0;
  v40->m_bufInfoText.m_Error = 0;
  v40->m_bufInfoText.m_nOffset = 0;
  v40->m_bufInfoText.m_nMaxPut = -1;
  CUtlBuffer::AddNullTermination(this: &v40->m_bufInfoText, nPut: 0);
  v40->InvalidateLayout(this: v40, a2: false, a3: false);
  if ( bufText.m_Memory.m_nGrowSize >= 0 )
  {
    if ( bufText.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: bufText.m_Memory.m_pMemory);
      bufText.m_Memory.m_pMemory = nullptr;
    }
    bufText.m_Memory.m_nAllocationCount = 0;
  }
  CUtlSymbolTable::~CUtlSymbolTable(this: &arrMaterialsFullNames.m_SymbolTable);
  v52 = arrMaterialsFullNames.m_Vector.m_Memory.m_pMemory;
  arrMaterialsFullNames.m_Vector.m_Size = 0;
  if ( arrMaterialsFullNames.m_Vector.m_Memory.m_nGrowSize >= 0 )
  {
    if ( arrMaterialsFullNames.m_Vector.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: arrMaterialsFullNames.m_Vector.m_Memory.m_pMemory);
      v52 = nullptr;
      arrMaterialsFullNames.m_Vector.m_Memory.m_pMemory = nullptr;
    }
    arrMaterialsFullNames.m_Vector.m_Memory.m_nAllocationCount = 0;
  }
  arrMaterialsFullNames.m_Vector.m_pElements = v52;
  if ( arrMaterialsFullNames.m_Vector.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v52 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v52);
      arrMaterialsFullNames.m_Vector.m_Memory.m_pMemory = nullptr;
    }
    arrMaterialsFullNames.m_Vector.m_Memory.m_nAllocationCount = 0;
  }
  CUtlSymbolTable::~CUtlSymbolTable(this: &arrMaterials.m_SymbolTable);
  v53 = arrMaterials.m_Vector.m_Memory.m_pMemory;
  arrMaterials.m_Vector.m_Size = 0;
  if ( arrMaterials.m_Vector.m_Memory.m_nGrowSize >= 0 )
  {
    if ( arrMaterials.m_Vector.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: arrMaterials.m_Vector.m_Memory.m_pMemory);
      v53 = nullptr;
      arrMaterials.m_Vector.m_Memory.m_pMemory = nullptr;
    }
    arrMaterials.m_Vector.m_Memory.m_nAllocationCount = 0;
  }
  arrMaterials.m_Vector.m_pElements = v53;
  if ( arrMaterials.m_Vector.m_Memory.m_nGrowSize >= 0 && v53 != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v53);
}

//------------------------------------------------------------------------------
// Address: 0x10099060
// Name: public: virtual void CRenderTextureEditor::Close(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRenderTextureEditor::Close(CRenderTextureEditor *this)
{
  vgui::Frame::Close(this);
  CRenderTextureEditor::SetDispInfo(this, kv: nullptr, iHint: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10099080
// Name: public: virtual void CRenderTextureEditor::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CRenderTextureEditor::Paint(CRenderTextureEditor *this@<ecx>, int a2@<edi>)
{
  void (__thiscall *Flush)(IMaterialSystem *, bool); // eax
  void (__thiscall *SetBgColor)(vgui::Panel *, Color); // edx
  KeyValues *m_pInfo; // esi
  const char *String; // edi
  const char *v7; // eax
  ITexture *v8; // edi
  const char *v9; // eax
  int v10; // ebx
  int v11; // esi
  float v12; // xmm1_4
  const char *v13; // ebx
  const char *v14; // eax
  IMatSystemSurface_vtbl *v15; // esi
  int v16; // eax
  const char *v17; // esi
  int v18; // eax
  ITexture v19; // edx
  IMaterial *v20; // eax
  ITexture v21; // edx
  int v22; // eax
  ITexture v23; // edx
  int v24; // ebx
  int v25; // esi
  int (__thiscall *GetActualDepth)(ITexture *); // eax
  int v27; // eax
  ITexture v28; // edx
  int v29; // ecx
  int v30; // ecx
  int v31; // esi
  int v32; // eax
  int MemRequired; // eax
  int v34; // eax
  int v35; // edx
  IMaterial *v36; // ecx
  int v37; // eax
  int v38; // eax
  IMatSystemSurface_vtbl *v39; // esi
  int v40; // eax
  IMatSystemSurface_vtbl *v41; // esi
  int v42; // eax
  int v43; // eax
  int v44; // esi
  int v45; // ebx
  int v46; // edi
  int v47; // ebx
  int v48; // esi
  int v49; // ebx
  IMatSystemSurface_vtbl *v50; // esi
  int v51; // eax
  int v52; // [esp-4h] [ebp-4B4h]
  char chResolveName[256]; // [esp+8h] [ebp-4A8h] BYREF
  char chResolveNameArg[256]; // [esp+108h] [ebp-3A8h] BYREF
  char chLine2[256]; // [esp+208h] [ebp-2A8h] BYREF
  char chLine1[256]; // [esp+308h] [ebp-1A8h] BYREF
  char chbuf[52]; // [esp+408h] [ebp-A8h] BYREF
  CAutoMatSysDebugMode auto_matsysdebugmode; // [esp+43Ch] [ebp-74h] BYREF
  char chSizeBuf[20]; // [esp+45Ch] [ebp-54h] BYREF
  const char *szTextureFile; // [esp+470h] [ebp-40h]
  IMaterial *pMaterial; // [esp+474h] [ebp-3Ch]
  ITexture *pMatTexture; // [esp+478h] [ebp-38h]
  int wmap; // [esp+47Ch] [ebp-34h]
  ImageFormat fmt; // [esp+480h] [ebp-30h]
  int iDrawWidth; // [esp+484h] [ebp-2Ch]
  bool bHasAlpha; // [esp+48Bh] [ebp-25h]
  vgui::Panel *pPanel; // [esp+48Ch] [ebp-24h]
  int iTxWidth; // [esp+490h] [ebp-20h]
  int dmap; // [esp+494h] [ebp-1Ch]
  int orgTxXA; // [esp+498h] [ebp-18h]
  int hact; // [esp+49Ch] [ebp-14h]
  int iTxHeight; // [esp+4A0h] [ebp-10h]
  int iDrawHeight; // [esp+4A4h] [ebp-Ch]
  int extTxHeight; // [esp+4A8h] [ebp-8h]
  int dact; // [esp+4ACh] [ebp-4h]

  Flush = g_pMaterialSystem->Flush;
  pPanel = this;
  auto_matsysdebugmode.arrCleanupVars.m_LessFunc = (bool (__cdecl *)(IMaterialVar *const *, IMaterialVar *const *))CDmxSerializationDictionary::LessFunc;
  memset(&auto_matsysdebugmode.arrCleanupVars.m_Elements, 0, sizeof(auto_matsysdebugmode.arrCleanupVars.m_Elements));
  *(_DWORD *)&auto_matsysdebugmode.arrCleanupVars.m_Root = 0xFFFF;
  *(_DWORD *)&auto_matsysdebugmode.arrCleanupVars.m_FirstFree = -1;
  auto_matsysdebugmode.arrCleanupVars.m_pElements = nullptr;
  Flush(this: g_pMaterialSystem, a2: false);
  auto_matsysdebugmode.bOldDebugMode = g_pMaterialSystemDebugTextureInfo->SetDebugTextureRendering(
                                         this: g_pMaterialSystemDebugTextureInfo,
                                         a2: true);
  vgui::Frame::DisableFadeEffect(this);
  SetBgColor = this->SetBgColor;
  extTxHeight = -16109046;
  ((void (__thiscall *)(CRenderTextureEditor *, int))SetBgColor)(a1: this, a2: -16109046);
  CColorBalanceUIPanel::Init((vgui::PropertyPage *)this);
  m_pInfo = this->m_pInfo;
  orgTxXA = (int)m_pInfo;
  if ( m_pInfo == nullptr )
  {
    CAutoMatSysDebugMode::~CAutoMatSysDebugMode(this: &auto_matsysdebugmode);
    return;
  }
  v52 = a2;
  String = KeyValues::GetString(this: m_pInfo, keyName: "Name", defaultValue: defaultValue);
  szTextureFile = String;
  V_strncpy(pDest: `anonymous namespace'::s_chLastViewedTextureBuffer, pSrc: String, maxLen: 512);
  v7 = KeyValues::GetString(this: m_pInfo, keyName: "TexGroup", defaultValue: defaultValue);
  if ( *String == 0
    || (v8 = materials->FindTexture(this: materials, a2: String, a3: v7, a4: 0, a5: 0), pMatTexture = v8, v8 == nullptr) )
  {
    v8 = materials->FindTexture(this: materials, a2: "debugempty", a3: defaultValue, a4: 0, a5: 0);
    pMatTexture = v8;
  }
  iTxWidth = KeyValues::GetInt(this: m_pInfo, keyName: "Width", defaultValue: 0);
  iTxHeight = KeyValues::GetInt(this: m_pInfo, keyName: "Height", defaultValue: 0);
  dmap = KeyValues::GetInt(this: m_pInfo, keyName: "Size", defaultValue: 0);
  v9 = KeyValues::GetString(this: m_pInfo, keyName: "Format", defaultValue: defaultValue);
  v10 = iTxWidth;
  v11 = iTxHeight;
  extTxHeight = (int)v9;
  if ( v8 != nullptr && ((unsigned __int8 (__thiscall *)(ITexture *, int))v8->IsCubeMap)(a1: v8, a2: v52) != 0 )
  {
    v10 = 1024;
    v11 = 1024;
LABEL_11:
    v10 = (int)(float)((float)(256.0 / (float)v11) * (float)v10);
    v11 = 256;
    goto LABEL_19;
  }
  if ( iTxHeight < iTxWidth )
  {
    if ( iTxWidth <= 256 )
    {
      if ( iTxWidth >= 64 )
        goto LABEL_19;
      v12 = 64.0;
      v10 = 64;
    }
    else
    {
      v12 = 256.0;
      v10 = 256;
    }
    v11 = (int)(float)((float)(v12 / (float)iTxWidth) * (float)iTxHeight);
  }
  else
  {
    if ( iTxHeight > 256 )
      goto LABEL_11;
    if ( iTxHeight < 64 )
    {
      v10 = (int)(float)((float)(64.0 / (float)iTxHeight) * (float)iTxWidth);
      v11 = 64;
    }
  }
LABEL_19:
  iDrawHeight = (int)(float)((float)v11 * 2.1484375);
  iDrawWidth = (int)(float)((float)v10 * 2.1484375);
  if ( iDrawHeight <= 4 )
    iDrawHeight = 4;
  if ( (int)(float)((float)v10 * 2.1484375) <= 4 )
    iDrawWidth = 4;
  ((void (__thiscall *)(IMatSystemSurface *, int, int, int, int, int))g_pMatSystemSurface->DrawSetColor_2)(
    a1: g_pMatSystemSurface,
    a2: 255,
    a3: 255,
    a4: 255,
    a5: 255,
    a6: v52);
  g_pMatSystemSurface->DrawOutlinedRect(this: g_pMatSystemSurface, a2: 11, a3: 11, a4: 578, a5: 658);
  memset(chResolveName, 0, sizeof(chResolveName));
  memset(chResolveNameArg, 0, sizeof(chResolveNameArg));
  v13 = szTextureFile;
  V_snprintf(pDest: chResolveNameArg, maxLen: 255, pFormat: "materials/%s.vtf", szTextureFile);
  v14 = g_pFileSystem->RelativePathToFullPath(
          this: g_pFileSystem,
          a2: chResolveNameArg,
          a3: "game",
          a4: chResolveName,
          a5: 255,
          a6: 0,
          a7: 0);
  if ( v14 != nullptr )
  {
    dact = (int)defaultValue;
    v13 = v14;
  }
  else
  {
    dact = (int)"[?]/";
  }
  memset(chSizeBuf, 0, sizeof(chSizeBuf));
  if ( dmap < 0 )
    chSizeBuf[0] = 45;
  else
    FmtCommaNumber(pchBuffer: chSizeBuf, uiNumber: dmap);
  v15 = g_pMatSystemSurface->__vftable;
  v16 = ((int (__thiscall *)(vgui::Panel *, int, int, int, int, int, int, int, int, const char *, int, const char *, char *, int, int, int))pPanel->__vftable[1].GetBorder)(
          a1: pPanel,
          a2: 20,
          a3: 20,
          a4: 550,
          a5: 35,
          a6: 255,
          a7: 255,
          a8: 255,
          a9: 255,
          a10: "%s%s\n%s Kb    %dx%d    %s",
          a11: dact,
          a12: v13,
          a13: chSizeBuf,
          a14: iTxWidth,
          a15: iTxHeight,
          a16: extTxHeight);
  ((void (__cdecl *)(IMatSystemSurface *, int))v15->DrawColoredTextRect)(a1: g_pMatSystemSurface, a2: v16);
  if ( pPanel[1].m_sNavRightName.m_Storage.m_Memory.m_nAllocationCount == 0 )
    CUtlBuffer::Printf(
      this: (CUtlBuffer *)&pPanel[1].m_sNavLeftName.m_Storage.m_Memory.m_nGrowSize,
      pFmt: "%s%s\r\n%s Kb    %dx%d    %s",
      (const char *)dact,
      v13,
      chSizeBuf,
      iTxWidth,
      iTxHeight,
      (const char *)extTxHeight);
  if ( KeyValues::GetInt(this: (KeyValues *)orgTxXA, keyName: "SpecialTx", defaultValue: 0) != 0 )
    goto LABEL_79;
  memset(chLine1, 0, sizeof(chLine1));
  memset(chLine2, 0, sizeof(chLine2));
  if ( dmap > g_warn_texkbytes )
    sprintf(string: &chLine1[strlen(chLine1)], format: "  Size(%s Kb)", chSizeBuf);
  if ( iTxWidth > g_warn_texdimensions || iTxHeight > g_warn_texdimensions )
    sprintf(string: &chLine1[strlen(chLine1)], format: "  Dimensions(%dx%d)", iTxWidth, iTxHeight);
  v17 = (const char *)extTxHeight;
  if ( _V_stricmp(s1: (const char *)extTxHeight, s2: "DXT1") != 0 && _V_stricmp(s1: v17, s2: "DXT5") != 0 )
    sprintf(string: &chLine1[strlen(chLine1)], format: "  Format(%s)", v17);
  if ( (v8->GetFlags(this: v8) & 0x200) != 0 )
    sprintf(string: &chLine1[strlen(chLine1)], format: "  NoLod");
  if ( (v8->GetFlags(this: v8) & 0x100) != 0 )
    sprintf(string: &chLine1[strlen(chLine1)], format: "  NoMip");
  if ( (v8->GetFlags(this: v8) & 0x1000) != 0 )
    sprintf(string: &chLine1[strlen(chLine1)], format: "  OneBitAlpha");
  v18 = v8->GetMappingWidth(this: v8);
  v19.__vftable = v8->__vftable;
  wmap = v18;
  v20 = (IMaterial *)v19.GetMappingHeight(this: v8);
  v21.__vftable = v8->__vftable;
  pMaterial = v20;
  v22 = v21.GetMappingDepth(this: v8);
  v23.__vftable = v8->__vftable;
  dmap = v22;
  v24 = v23.GetActualWidth(this: v8);
  v25 = v8->GetActualHeight(this: v8);
  GetActualDepth = v8->GetActualDepth;
  hact = v25;
  v27 = GetActualDepth(this: v8);
  v28.__vftable = v8->__vftable;
  dact = v27;
  fmt = v28.GetImageFormat(this: v8);
  if ( v24 > 4 || v25 > 4 )
  {
    orgTxXA = 1;
    if ( dact / 2 >= 1 )
      orgTxXA = dact / 2;
    v29 = v25;
    if ( v25 >= 4 )
      v29 = 4;
    if ( v29 <= v25 / 2 )
    {
      v30 = v25 / 2;
    }
    else if ( v25 >= 4 )
    {
      v30 = 4;
    }
    else
    {
      v30 = v25;
    }
    v31 = v24;
    if ( v24 >= 4 )
      v31 = 4;
    v32 = v24 / 2;
    if ( v31 > v24 / 2 )
    {
      v32 = v24;
      if ( v24 >= 4 )
        v32 = 4;
    }
    MemRequired = ImageLoader::GetMemRequired(
                    width: v32,
                    height: v30,
                    depth: orgTxXA,
                    imageFormat: fmt,
                    mipmap: true,
                    pAdjustedHeight: nullptr);
    FmtCommaNumber(pchBuffer: chbuf, uiNumber: (MemRequired + 511) / 1024);
    sprintf(string: &chLine2[strlen(chLine2)], format: "  %s Kb @ lower mip", chbuf);
    v25 = hact;
  }
  if ( wmap > v24 || (int)pMaterial > v25 )
  {
    v34 = dmap;
LABEL_68:
    v35 = 2 * dact;
    if ( v34 < 2 * dact )
      v35 = v34;
    v36 = (IMaterial *)(2 * v25);
    if ( (int)pMaterial < 2 * v25 )
      v36 = pMaterial;
    v37 = 2 * v24;
    if ( wmap < 2 * v24 )
      v37 = wmap;
    v38 = ImageLoader::GetMemRequired(
            width: v37,
            height: (int)v36,
            depth: v35,
            imageFormat: fmt,
            mipmap: true,
            pAdjustedHeight: nullptr);
    FmtCommaNumber(pchBuffer: chbuf, uiNumber: (v38 + 511) / 1024);
    sprintf(string: &chLine2[strlen(chLine2)], format: "      %s Kb @ higher mip", chbuf);
    goto LABEL_75;
  }
  v34 = dmap;
  if ( dmap > dact )
    goto LABEL_68;
LABEL_75:
  if ( chLine1[0] != 0 )
  {
    g_pMatSystemSurface->DrawSetColor_2(this: g_pMatSystemSurface, a2: 200, a3: 0, a4: 0, a5: 255);
    g_pMatSystemSurface->DrawFilledRect(this: g_pMatSystemSurface, a2: 15, a3: 55, a4: 575, a5: 72);
    v39 = g_pMatSystemSurface->__vftable;
    v40 = ((int (__thiscall *)(vgui::Panel *, int, int, int, int, int, int, int, int, const char *, char *))pPanel->__vftable[1].GetBorder)(
            a1: pPanel,
            a2: 20,
            a3: 55,
            a4: 550,
            a5: 17,
            a6: 255,
            a7: 255,
            a8: 255,
            a9: 255,
            a10: "%s",
            a11: chLine1);
    ((void (__cdecl *)(IMatSystemSurface *, int))v39->DrawColoredTextRect)(a1: g_pMatSystemSurface, a2: v40);
  }
  if ( chLine2[0] != 0 )
  {
    v41 = g_pMatSystemSurface->__vftable;
    v42 = ((int (__thiscall *)(vgui::Panel *, int, int, int, int, int, int, int, int, const char *, char *))pPanel->__vftable[1].GetBorder)(
            a1: pPanel,
            a2: 20,
            a3: 72,
            a4: 550,
            a5: 17,
            a6: 255,
            a7: 255,
            a8: 255,
            a9: 255,
            a10: "%s",
            a11: chLine2);
    ((void (__cdecl *)(IMatSystemSurface *, int))v41->DrawColoredTextRect)(a1: g_pMatSystemSurface, a2: v42);
  }
LABEL_79:
  v43 = _V_stricmp(s1: (const char *)extTxHeight, s2: "DXT1");
  v44 = 0;
  bHasAlpha = v43 != 0;
  dact = 550;
  extTxHeight = 550;
  orgTxXA = 0;
  dmap = 0;
  if ( v43 != 0 )
  {
    if ( iTxWidth < 2 * iTxHeight )
    {
      if ( iTxHeight < 2 * iTxWidth )
      {
        dmap = 280;
        v44 = 137;
        if ( iDrawWidth > 275 )
        {
          iDrawWidth /= 2;
          iDrawHeight /= 2;
        }
        dact = 274;
        extTxHeight = 274;
      }
      else
      {
        orgTxXA = 280;
        dact = 272;
      }
    }
    else
    {
      dmap = 280;
      extTxHeight = 274;
    }
  }
  pMaterial = UseDebugMaterial(
                szMaterial: "debug/debugtexturecolor",
                a2: (int)v8,
                a3: v44,
                pMatTexture: v8,
                pRestoreVars: &auto_matsysdebugmode);
  if ( pMaterial != nullptr )
  {
    ((void (__thiscall *)(IMatSystemSurface *, int, int, int))g_pMatSystemSurface->DrawSetColor_2)(
      a1: g_pMatSystemSurface,
      a2: 255,
      a3: 255,
      a4: 255);
    v45 = dact;
    iTxWidth = (extTxHeight + iDrawHeight) / 2;
    v46 = (dact + iDrawWidth) / 2;
    fmt = v46 + v44 + 20;
    iTxHeight = (extTxHeight - iDrawHeight) / 2;
    dact = iTxHeight + 100;
    hact = iTxWidth + 100;
    v47 = (v45 - iDrawWidth) / 2;
    wmap = v47 + v44 + 20;
    g_pMatSystemSurface->DrawOutlinedRect(
      this: g_pMatSystemSurface,
      a2: v47 + v44 + 18,
      a3: iTxHeight + 98,
      a4: v46 + v44 + 22,
      a5: iTxWidth + 102);
    RenderTexturedRect(pPanel, yoff: 0, pMaterial, x: wmap, y: dact, x1: fmt, y1: hact, xoff: 0);
    if ( bHasAlpha )
    {
      v48 = orgTxXA + v44;
      fmt = (ImageFormat)UseDebugMaterial(
                           szMaterial: "debug/debugtexturealpha",
                           a2: v46,
                           a3: v48,
                           pMatTexture,
                           pRestoreVars: &auto_matsysdebugmode);
      if ( fmt != IMAGE_FORMAT_RGBA8888 )
      {
        hact = iTxWidth + dmap + 100;
        pMatTexture = (ITexture *)(iTxHeight + dmap + 100);
        g_pMatSystemSurface->DrawOutlinedRect(
          this: g_pMatSystemSurface,
          a2: v47 + v48 + 18,
          a3: iTxHeight + dmap + 98,
          a4: v46 + v48 + 22,
          a5: iTxWidth + dmap + 102);
        RenderTexturedRect(
          pPanel,
          yoff: 0,
          pMaterial: (IMaterial *)fmt,
          x: v47 + v48 + 20,
          y: (int)pMatTexture,
          x1: v46 + v48 + 20,
          y1: hact,
          xoff: 0);
      }
      v44 = v48 - orgTxXA;
    }
  }
  else
  {
    ((void (__thiscall *)(IMatSystemSurface *, int, _DWORD, int))g_pMatSystemSurface->DrawSetColor_2)(
      a1: g_pMatSystemSurface,
      a2: 255,
      a3: 0,
      a4: 255);
    hact = (int)g_pMatSystemSurface->__vftable;
    v46 = (dact + iDrawWidth) / 2;
    v47 = (dact - iDrawWidth) / 2;
    (*(void (__thiscall **)(IMatSystemSurface *, int, int, int, int))(hact + 60))(
      a1: g_pMatSystemSurface,
      a2: v47 + v44 + 20,
      a3: (dact - iDrawHeight) / 2 + 100,
      a4: v46 + v44 + 20,
      a5: (dact + iDrawHeight) / 2 + 100);
  }
  if ( IsTextureExcluded(a1: v44, szTextureName: szTextureFile) )
  {
    g_pMatSystemSurface->DrawSetColor_2(this: g_pMatSystemSurface, a2: 200, a3: 0, a4: 0, a5: 255);
    v49 = v47 + v44 + 20;
    dact = (extTxHeight - iDrawHeight) / 2 + 100;
    hact = (int)g_pMatSystemSurface->__vftable;
    (*(void (__thiscall **)(IMatSystemSurface *, int, int, int, int))(hact + 60))(
      a1: g_pMatSystemSurface,
      a2: v49 - 2,
      a3: (extTxHeight - iDrawHeight) / 2 + 98,
      a4: v46 + v44 + 22,
      a5: (extTxHeight + iDrawHeight) / 2 + 102);
    v50 = g_pMatSystemSurface->__vftable;
    v51 = ((int (__thiscall *)(vgui::Panel *, int, int, int, int, int, int, int, int, const char *))pPanel->__vftable[1].GetBorder)(
            a1: pPanel,
            a2: v49,
            a3: dact,
            a4: iDrawWidth,
            a5: iDrawHeight,
            a6: 255,
            a7: 255,
            a8: 255,
            a9: 255,
            a10: "EXCLUDED");
    ((void (__cdecl *)(IMatSystemSurface *, int))v50->DrawColoredTextRect)(a1: g_pMatSystemSurface, a2: v51);
  }
  CAutoMatSysDebugMode::~CAutoMatSysDebugMode(this: &auto_matsysdebugmode);
}

//------------------------------------------------------------------------------
// Address: 0x10099C40
// Name: protected: virtual void CRenderTexturesListViewPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRenderTexturesListViewPanel::OnMousePressed(CRenderTexturesListViewPanel *this, const char *code)
{
  int v3; // edi
  KeyValues *v4; // eax
  int Wide; // eax
  int Tall; // eax
  vgui::Panel *i; // edi
  ButtonCode_t v8; // ecx
  int v9; // eax
  int iTile; // [esp+8h] [ebp-18h] BYREF
  int x; // [esp+Ch] [ebp-14h] BYREF
  int y; // [esp+10h] [ebp-10h] BYREF
  int iTopLeftY; // [esp+14h] [ebp-Ch] BYREF
  int iTopLeftX; // [esp+18h] [ebp-8h] BYREF
  int tileY; // [esp+1Ch] [ebp-4h] BYREF

  CBaseServer::RemoveClientFromGame(this, panelName: code);
  this->m_pRenderTxEditor->Close(this: this->m_pRenderTxEditor);
  if ( this->m_pListPanel != nullptr )
  {
    g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
    vgui::Panel::ScreenToLocal(this, &x, &y);
    if ( this->HitTest(this, a2: x, a3: y, a4: &iTile) != 0
      && this->GetTileOrg(this, a2: iTile, a3: (int *)&code, a4: &tileY) )
    {
      v3 = this->m_pListPanel->GetItemIDFromRow(this: this->m_pListPanel, a2: iTile);
      if ( v3 >= 0 )
      {
        v4 = this->m_pListPanel->GetItem(this: this->m_pListPanel, a2: v3);
        if ( v4 != nullptr )
        {
          CRenderTextureEditor::SetDispInfo(this: this->m_pRenderTxEditor, kv: v4, iHint: v3);
          Wide = vgui::Panel::GetWide(this: this->m_pRenderTxEditor);
          if ( (int)&code[Wide] > this->m_li_wide - 2 )
            code = (const char *)(this->m_li_wide - vgui::Panel::GetWide(this: this->m_pRenderTxEditor) - 2);
          Tall = vgui::Panel::GetTall(this: this->m_pRenderTxEditor);
          if ( tileY + Tall > this->m_li_tall - 2 )
            tileY = this->m_li_tall - vgui::Panel::GetTall(this: this->m_pRenderTxEditor) - 2;
          iTopLeftX = 0;
          iTopLeftY = 0;
          for ( i = this->GetParent(this); i != nullptr; i = i->GetParent(this: i) )
          {
            iTopLeftY = 0;
            iTopLeftX = 0;
            vgui::Panel::LocalToScreen(this: i, x: &iTopLeftX, y: &iTopLeftY);
          }
          vgui::Panel::LocalToScreen(this, x: (int *)&code, y: &tileY);
          v8 = (ButtonCode_t)code;
          if ( (int)code < iTopLeftX )
          {
            v8 = iTopLeftX;
            code = (const char *)iTopLeftX;
          }
          v9 = tileY;
          if ( tileY < iTopLeftY )
          {
            v9 = iTopLeftY;
            tileY = iTopLeftY;
          }
          vgui::Panel::SetPos(this: this->m_pRenderTxEditor, x: v8, y: v9);
          this->m_pRenderTxEditor->Activate(this: this->m_pRenderTxEditor);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10099E20
// Name: protected: virtual void CRenderTexturesListViewPanel::RenderTile(int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CRenderTexturesListViewPanel::RenderTile(
        CRenderTexturesListViewPanel *this@<ecx>,
        BOOL a2@<edi>,
        IMatSystemSurface_vtbl *iTile,
        int x,
        int y)
{
  void (__thiscall *Flush)(IMaterialSystem *, bool); // eax
  bool v7; // al
  vgui::ListPanel *m_pListPanel; // ecx
  int (__thiscall *GetItemIDFromRow)(vgui::ListPanel *, int); // edx
  int v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  const char *String; // edi
  const char *v14; // eax
  int Int; // ebx
  int v16; // edi
  const char *v17; // edx
  int v18; // eax
  const char *v19; // esi
  int v20; // esi
  float v21; // xmm1_4
  int v22; // ebx
  int v23; // edi
  int v24; // edi
  int v25; // ebx
  int v26; // eax
  unsigned int v27; // eax
  Color v28; // eax
  bool v29; // zf
  const char *v30; // eax
  const char *v31; // esi
  IMatSystemSurface_vtbl *v32; // ebx
  void (__thiscall *Think)(vgui::IClientPanel *); // eax
  int v34; // eax
  int v35; // eax
  int i; // eax
  int j; // esi
  IMatSystemSurface_vtbl *v38; // ebx
  int v39; // eax
  int v40; // ebx
  int v41; // esi
  int v42; // ebx
  IMatSystemSurface_vtbl *v43; // ebx
  int v44; // eax
  int v45; // eax
  int v46; // esi
  int v47; // ebx
  int v48; // esi
  IMatSystemSurface_vtbl *v49; // esi
  int v50; // eax
  BOOL v51; // [esp-4h] [ebp-19Ch]
  char chInfoText[256]; // [esp+8h] [ebp-190h] BYREF
  CAutoMatSysDebugMode auto_matsysdebugmode; // [esp+108h] [ebp-90h] BYREF
  int iTextLen[4]; // [esp+128h] [ebp-70h] BYREF
  int v55; // [esp+138h] [ebp-60h]
  char chSizeBuf[20]; // [esp+13Ch] [ebp-5Ch] BYREF
  int iTextMargins[4]; // [esp+150h] [ebp-48h] BYREF
  const char *szTextureFile; // [esp+160h] [ebp-38h]
  int y1; // [esp+164h] [ebp-34h]
  IMaterial *pMaterial; // [esp+168h] [ebp-30h] BYREF
  int iTxSize; // [esp+16Ch] [ebp-2Ch]
  int orgTxXA; // [esp+170h] [ebp-28h]
  ITexture *pMatTexture; // [esp+174h] [ebp-24h]
  int tileHeight; // [esp+178h] [ebp-20h] BYREF
  int iTxWidth; // [esp+17Ch] [ebp-1Ch]
  int iDrawWidth; // [esp+180h] [ebp-18h]
  int iDrawHeight; // [esp+184h] [ebp-14h]
  vgui::Panel *pPanel; // [esp+188h] [ebp-10h]
  int iTxHeight; // [esp+18Ch] [ebp-Ch]
  const char *szTxFormat; // [esp+190h] [ebp-8h]
  int extTxHeight; // [esp+194h] [ebp-4h]

  Flush = g_pMaterialSystem->Flush;
  pPanel = this;
  auto_matsysdebugmode.arrCleanupVars.m_LessFunc = (bool (__cdecl *)(IMaterialVar *const *, IMaterialVar *const *))CDmxSerializationDictionary::LessFunc;
  memset(&auto_matsysdebugmode.arrCleanupVars.m_Elements, 0, sizeof(auto_matsysdebugmode.arrCleanupVars.m_Elements));
  *(_DWORD *)&auto_matsysdebugmode.arrCleanupVars.m_Root = 0xFFFF;
  *(_DWORD *)&auto_matsysdebugmode.arrCleanupVars.m_FirstFree = -1;
  auto_matsysdebugmode.arrCleanupVars.m_pElements = nullptr;
  Flush(this: g_pMaterialSystem, a2: false);
  v7 = g_pMaterialSystemDebugTextureInfo->SetDebugTextureRendering(this: g_pMaterialSystemDebugTextureInfo, a2: true);
  m_pListPanel = this->m_pListPanel;
  GetItemIDFromRow = m_pListPanel->GetItemIDFromRow;
  auto_matsysdebugmode.bOldDebugMode = v7;
  v10 = GetItemIDFromRow(this: m_pListPanel, a2: (int)iTile);
  if ( v10 < 0
    || (v11 = this->m_pListPanel->GetItem(this: this->m_pListPanel, a2: v10),
        v12 = v11,
        iTile = (IMatSystemSurface_vtbl *)v11,
        v11 == nullptr) )
  {
    CAutoMatSysDebugMode::~CAutoMatSysDebugMode(this: &auto_matsysdebugmode);
    return;
  }
  v51 = a2;
  String = KeyValues::GetString(this: v11, keyName: "Name", defaultValue: defaultValue);
  szTextureFile = String;
  v14 = KeyValues::GetString(this: v12, keyName: "TexGroup", defaultValue: defaultValue);
  if ( *String == 0
    || (pMatTexture = materials->FindTexture(this: materials, a2: String, a3: v14, a4: 0, a5: 0)) == nullptr )
  {
    pMatTexture = materials->FindTexture(this: materials, a2: "debugempty", a3: defaultValue, a4: 0, a5: 0);
  }
  Int = KeyValues::GetInt(this: v12, keyName: "Width", defaultValue: 0);
  iTxWidth = Int;
  v16 = KeyValues::GetInt(this: v12, keyName: "Height", defaultValue: 0);
  iTxHeight = v16;
  iTxSize = KeyValues::GetInt(this: v12, keyName: "Size", defaultValue: 0);
  v17 = KeyValues::GetString(this: v12, keyName: "Format", defaultValue: defaultValue);
  szTxFormat = v17;
  v18 = strlen(v17);
  v19 = defaultValue;
  extTxHeight = v18;
  orgTxXA = (int)defaultValue;
  if ( v18 > 4 )
  {
    while ( v17[v18 - 1] != 54 )
    {
      if ( v17[v18 - 1] == 56 )
      {
        extTxHeight = v18;
        if ( v18 <= 4 )
          goto LABEL_22;
        do
        {
          if ( v17[v18 - 2] != 56 )
            break;
          --v18;
        }
        while ( v18 > 4 );
        goto LABEL_21;
      }
      if ( v17[v18 - 1] != 70 || *v19 != 0 )
        goto LABEL_21;
      v19 = "F";
      --v18;
      orgTxXA = (int)"F";
    }
    extTxHeight = v18;
    if ( v18 <= 4 )
      goto LABEL_22;
    do
    {
      if ( v17[v18 - 2] != 49 )
        break;
      if ( v17[v18 - 3] != 54 )
        break;
      v18 -= 2;
    }
    while ( v18 > 4 );
LABEL_21:
    extTxHeight = v18;
  }
LABEL_22:
  v20 = Int;
  if ( pMatTexture != nullptr
    && ((unsigned __int8 (__thiscall *)(ITexture *, BOOL))pMatTexture->IsCubeMap)(a1: pMatTexture, a2: v51) != 0 )
  {
    v20 = 1024;
    v16 = 1024;
  }
  else
  {
    if ( iTxHeight < Int )
    {
      if ( Int <= 256 )
      {
        if ( Int >= 64 )
          goto LABEL_35;
        v21 = 64.0;
        v20 = 64;
      }
      else
      {
        v21 = 256.0;
        v20 = 256;
      }
      v16 = (int)(float)((float)(v21 / (float)Int) * (float)iTxHeight);
      goto LABEL_35;
    }
    if ( iTxHeight <= 256 )
    {
      if ( iTxHeight < 64 )
      {
        v20 = (int)(float)((float)(64.0 / (float)iTxHeight) * (float)Int);
        v16 = 64;
      }
      goto LABEL_35;
    }
  }
  v20 = (int)(float)((float)(256.0 / (float)v16) * (float)v20);
  v16 = 256;
LABEL_35:
  iDrawHeight = (int)(float)((float)v16 * 0.75);
  iDrawWidth = (int)(float)((float)v20 * 0.75);
  if ( iDrawHeight <= 4 )
    iDrawHeight = 4;
  if ( (int)(float)((float)v20 * 0.75) <= 4 )
    iDrawWidth = 4;
  pPanel->__vftable[1].IsWithinTraverse(this: pPanel, a2: (int)&pMaterial, a3: (int)&tileHeight, a4: v51);
  g_pMatSystemSurface->DrawSetColor_2(this: g_pMatSystemSurface, a2: 255, a3: 255, a4: 255, a5: 255);
  v22 = y;
  v23 = x;
  g_pMatSystemSurface->DrawOutlinedRect(
    this: g_pMatSystemSurface,
    a2: x + 1,
    a3: y + 1,
    a4: (int)pMaterial + x - 2,
    a5: tileHeight + y - 2);
  v24 = v23 + 20;
  v25 = v22 + 10;
  y = v25;
  v26 = strlen(szTextureFile);
  tileHeight = (int)"...";
  if ( v26 > 22 )
  {
    pMaterial = (IMaterial *)&szTextureFile[v26 - 22];
  }
  else
  {
    tileHeight = (int)defaultValue;
    pMaterial = (IMaterial *)szTextureFile;
  }
  memset(chSizeBuf, 0, sizeof(chSizeBuf));
  if ( iTxSize < 0 )
    chSizeBuf[0] = 45;
  else
    FmtCommaNumber(pchBuffer: chSizeBuf, uiNumber: iTxSize);
  v27 = _S2_1;
  if ( (_S2_1 & 1) == 0 )
  {
    v27 = _S2_1 | 1;
    _S2_1 |= 1u;
    clrLblNormal = (Color)-15125991;
  }
  if ( (v27 & 2) == 0 )
  {
    v27 |= 2u;
    _S2_1 = v27;
    clrLblWarn = (Color)-16757941;
  }
  if ( (v27 & 4) == 0 )
  {
    _S2_1 = v27 | 4;
    clrLblError = (Color)-16777016;
  }
  if ( KeyValues::GetInt(this: (KeyValues *)iTile, keyName: "SpecialTx", defaultValue: 0) == 0
    && g_warn_enable
    && ShallWarnTx(kv: (KeyValues *)iTile, tx: pMatTexture) )
  {
    v28 = clrLblWarn;
    HIBYTE(iTile) = 1;
  }
  else
  {
    v28 = clrLblNormal;
    HIBYTE(iTile) = 0;
  }
  ((void (__thiscall *)(_DWORD, _DWORD))g_pMatSystemSurface->DrawSetColor)(a1: g_pMatSystemSurface, a2: v28);
  g_pMatSystemSurface->DrawFilledRect(this: g_pMatSystemSurface, a2: v24 - 10, a3: v25, a4: v24 + 202, a5: v25 + 35);
  memset(chInfoText, 0, sizeof(chInfoText));
  v29 = (pMatTexture->GetFlags(this: pMatTexture) & 0x1300) == 0;
  v30 = "***";
  if ( v29 )
    v30 = defaultValue;
  v31 = (const char *)orgTxXA;
  sprintf(
    string: chInfoText,
    format: "%s Kb  %dx%d  %.*s%s  %s",
    chSizeBuf,
    iTxWidth,
    iTxHeight,
    extTxHeight,
    szTxFormat,
    (const char *)orgTxXA,
    v30);
  v32 = g_pMatSystemSurface->__vftable;
  Think = pPanel->__vftable[1].Think;
  memset(iTextMargins, 0, sizeof(iTextMargins));
  v34 = ((int (__thiscall *)(vgui::Panel *))Think)(a1: pPanel);
  x = v32->GetFontTall(this: g_pMatSystemSurface, a2: v34);
  memset(&iTextLen[1], 0, 12);
  iTextLen[0] = strlen(chSizeBuf) + 5;
  strchr(string: chInfoText, chr: 0x78u);
  for ( i = 1 - (_DWORD)chInfoText + v35; chInfoText[i] != 32; ++i )
    ;
  iTextLen[1] = i + 1;
  iTextLen[2] = i + 1 + strlen(v31) + extTxHeight + 2;
  iTextLen[3] = strlen(chInfoText);
  for ( j = 0; j < 4; ++j )
  {
    v38 = g_pMatSystemSurface->__vftable;
    v39 = ((int (__thiscall *)(vgui::Panel *, const char *, int, char *))pPanel->__vftable[1].Think)(
            a1: pPanel,
            a2: "%.*s",
            a3: iTextLen[j],
            a4: chInfoText);
    iTextMargins[j] = ((int (__cdecl *)(IMatSystemSurface *, int))v38->DrawTextLen)(a1: g_pMatSystemSurface, a2: v39);
  }
  if ( HIBYTE(iTile) != 0 )
  {
    ((void (__thiscall *)(_DWORD, _DWORD))g_pMatSystemSurface->DrawSetColor)(a1: g_pMatSystemSurface, a2: clrLblError);
    v40 = iTextMargins[0];
    v41 = y;
    if ( iTxSize > g_warn_texkbytes )
      g_pMatSystemSurface->DrawFilledRect(
        this: g_pMatSystemSurface,
        a2: v24 - 2,
        a3: x + y + 1,
        a4: iTextMargins[0] + v24 - 5,
        a5: y + 35);
    if ( iTxWidth > g_warn_texdimensions || iTxHeight > g_warn_texdimensions )
      g_pMatSystemSurface->DrawFilledRect(
        this: g_pMatSystemSurface,
        a2: v40 + v24 - 2,
        a3: x + v41 + 1,
        a4: iTextMargins[1] + v24 - 1,
        a5: v41 + 35);
    v42 = iTextMargins[2];
    if ( strcmp(szTxFormat, "DXT1") != 0 && strcmp(szTxFormat, "DXT5") != 0 )
      g_pMatSystemSurface->DrawFilledRect(
        this: g_pMatSystemSurface,
        a2: iTextMargins[1] + v24 + 2,
        a3: x + v41 + 1,
        a4: iTextMargins[2] + v24 - 1,
        a5: v41 + 35);
    if ( (pMatTexture->GetFlags(this: pMatTexture) & 0x1300) != 0 )
      g_pMatSystemSurface->DrawFilledRect(
        this: g_pMatSystemSurface,
        a2: v42 + v24 + 3,
        a3: x + v41 + 1,
        a4: iTextMargins[3] + v24 + 2,
        a5: v41 + 35);
  }
  else
  {
    v41 = y;
  }
  v43 = g_pMatSystemSurface->__vftable;
  v44 = ((int (__thiscall *)(vgui::Panel *, int, int, int, int, int, int, int, int, const char *, int, IMaterial *, char *))pPanel->__vftable[1].Think)(
          a1: pPanel,
          a2: v24,
          a3: v41,
          a4: 192,
          a5: 35,
          a6: 255,
          a7: 255,
          a8: 255,
          a9: 255,
          a10: "%s%s\n%s",
          a11: tileHeight,
          a12: pMaterial,
          a13: chInfoText);
  ((void (__cdecl *)(IMatSystemSurface *, int))v43->DrawColoredTextRect)(a1: g_pMatSystemSurface, a2: v44);
  v29 = LOBYTE(pPanel[1].m_hKeyBindingsContext) == 0;
  y = v41 + 45;
  if ( v29 || (v45 = _V_stricmp(s1: szTxFormat, s2: "DXT1"), HIBYTE(iTile) = 1, v45 == 0) )
    HIBYTE(iTile) = 0;
  v46 = 0;
  x = 192;
  extTxHeight = 192;
  orgTxXA = 0;
  iTxSize = 0;
  if ( HIBYTE(iTile) != 0 )
  {
    if ( iTxWidth < 2 * iTxHeight )
    {
      v24 -= 6;
      if ( iTxHeight < 2 * iTxWidth )
      {
        extTxHeight = 96;
        iTxSize = 106;
        v46 = 48;
        x = 96;
        if ( iDrawWidth > 96 )
        {
          iDrawWidth /= 2;
          iDrawHeight /= 2;
        }
      }
      else
      {
        x = 96;
        orgTxXA = 106;
      }
    }
    else
    {
      extTxHeight = 96;
      iTxSize = 106;
    }
  }
  pMaterial = UseDebugMaterial(
                szMaterial: "debug/debugtexturecolor",
                a2: v24,
                a3: v46,
                pMatTexture,
                pRestoreVars: &auto_matsysdebugmode);
  if ( pMaterial != nullptr )
  {
    ((void (__thiscall *)(IMatSystemSurface *, int, int, int))g_pMatSystemSurface->DrawSetColor_2)(
      a1: g_pMatSystemSurface,
      a2: 255,
      a3: 255,
      a4: 255);
    y1 = (iDrawHeight + extTxHeight) / 2;
    tileHeight = y1 + y;
    v47 = (iDrawWidth + x) / 2;
    iTxHeight = v24 + v47 + v46;
    v55 = (extTxHeight - iDrawHeight) / 2;
    szTxFormat = (const char *)(y + v55);
    iTxWidth = (x - iDrawWidth) / 2;
    x = v24 + v46 + iTxWidth;
    g_pMatSystemSurface->DrawOutlinedRect(
      this: g_pMatSystemSurface,
      a2: x - 2,
      a3: y + v55 - 2,
      a4: iTxHeight + 2,
      a5: y1 + y + 2);
    RenderTexturedRect(pPanel, yoff: 1, pMaterial, x, y: (int)szTxFormat, x1: iTxHeight, y1: tileHeight, xoff: 2);
    if ( HIBYTE(iTile) != 0 )
    {
      v48 = orgTxXA + v46;
      tileHeight = (int)UseDebugMaterial(
                          szMaterial: "debug/debugtexturealpha",
                          a2: v24,
                          a3: v48,
                          pMatTexture,
                          pRestoreVars: &auto_matsysdebugmode);
      if ( tileHeight != 0 )
      {
        y1 += iTxSize + y;
        iTxHeight = v24 + v47 + v48;
        iTile = (IMatSystemSurface_vtbl *)(y + iTxSize + v55);
        x = v24 + v48 + iTxWidth;
        g_pMatSystemSurface->DrawOutlinedRect(
          this: g_pMatSystemSurface,
          a2: x - 2,
          a3: (int)&iTile[-1].DrawTexturedSubRectGradient + 2,
          a4: iTxHeight + 2,
          a5: y1 + 2);
        RenderTexturedRect(
          pPanel,
          yoff: 1,
          pMaterial: (IMaterial *)tileHeight,
          x,
          y: (int)iTile,
          x1: iTxHeight,
          y1,
          xoff: 2);
      }
      v46 = v48 - orgTxXA;
    }
  }
  else
  {
    ((void (__thiscall *)(IMatSystemSurface *, int, _DWORD, int))g_pMatSystemSurface->DrawSetColor_2)(
      a1: g_pMatSystemSurface,
      a2: 255,
      a3: 0,
      a4: 255);
    v47 = (x + iDrawWidth) / 2;
    iTxWidth = (x - iDrawWidth) / 2;
    iTile = g_pMatSystemSurface->__vftable;
    iTile->DrawFilledRect(
      this: g_pMatSystemSurface,
      a2: v24 + v46 + iTxWidth,
      a3: y + (x - iDrawHeight) / 2,
      a4: v24 + v47 + v46,
      a5: y + (x + iDrawHeight) / 2);
  }
  if ( mat_texture_list_exclude_editing.m_pParent != nullptr
    && mat_texture_list_exclude_editing.m_pParent->m_Value.m_nValue > 0
    && materials->FindTexture(this: materials, a2: szTextureFile, a3: defaultValue, a4: 0, a5: 0) != nullptr
    && materials->GetTextureInformation(this: materials, a2: szTextureFile, a3: (MaterialTextureInfo_t *)&iTile)
    && iTile == nullptr )
  {
    g_pMatSystemSurface->DrawSetColor_2(this: g_pMatSystemSurface, a2: 200, a3: 0, a4: 0, a5: 255);
    szTxFormat = (const char *)(y + (extTxHeight - iDrawHeight) / 2);
    x = v24 + v46 + iTxWidth;
    iTile = g_pMatSystemSurface->__vftable;
    iTile->DrawFilledRect(
      this: g_pMatSystemSurface,
      a2: x - 2,
      a3: (int)(szTxFormat - 2),
      a4: v46 + v47 + v24 + 2,
      a5: (extTxHeight + iDrawHeight) / 2 + y + 2);
    v49 = g_pMatSystemSurface->__vftable;
    v50 = ((int (__thiscall *)(vgui::Panel *, int, const char *, int, int, int, int, int, int, const char *))pPanel->__vftable[1].Think)(
            a1: pPanel,
            a2: x,
            a3: szTxFormat,
            a4: iDrawWidth,
            a5: iDrawHeight,
            a6: 255,
            a7: 255,
            a8: 255,
            a9: 255,
            a10: "-X-");
    ((void (__cdecl *)(IMatSystemSurface *, int))v49->DrawColoredTextRect)(a1: g_pMatSystemSurface, a2: v50);
  }
  CAutoMatSysDebugMode::~CAutoMatSysDebugMode(this: &auto_matsysdebugmode);
}

//------------------------------------------------------------------------------
// Address: 0x1009A9A0
// Name: public: virtual void CTextureListPanel::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTextureListPanel::Paint(CTextureListPanel *this@<ecx>, int a2@<edi>)
{
  CTextureListPanel *v2; // ebx
  KeyValues *m_p; // esi
  CRenderTextureEditor *m_pRenderTxEditor; // edi
  int m_iInfoHint; // esi
  KeyValues *m_pInfo; // edi
  const char *String; // esi
  KeyValues *FirstValue; // edi
  KeyValues *NextValue; // eax
  const char *v10; // esi
  bool v11; // al
  KeyValues *i; // esi
  int Int; // edi
  int v14; // eax
  const char *v15; // eax
  const char *v16; // eax
  int v17; // eax
  vgui::ListPanel *m_pListPanel; // ecx
  int (__thiscall *FirstItem)(vgui::ListPanel *); // eax
  int v20; // esi
  int v21; // edi
  vgui::ListPanel *v22; // ecx
  _DWORD dst[1024]; // [esp+4h] [ebp-1218h] BYREF
  char pDest[256]; // [esp+1004h] [ebp-218h] BYREF
  char szFilter[4]; // [esp+1104h] [ebp-118h] BYREF
  unsigned __int8 v27[256]; // [esp+1108h] [ebp-114h] BYREF
  CRenderTextureEditor *v28; // [esp+1208h] [ebp-14h] BYREF
  int iHint; // [esp+120Ch] [ebp-10h] BYREF
  KeyValues *kv; // [esp+1210h] [ebp-Ch] BYREF
  CSmartTextureKeyValues v31; // [esp+1214h] [ebp-8h] BYREF
  KeyValues *v32; // [esp+1218h] [ebp-4h]

  v2 = this;
  if ( this->m_hFont == 0 )
    return;
  if ( mat_texture_list.m_pParent == nullptr || mat_texture_list.m_pParent->m_Value.m_nValue == 0 )
    goto LABEL_6;
  if ( !g_pMaterialSystemDebugTextureInfo->IsDebugTextureListFresh(this: g_pMaterialSystemDebugTextureInfo, a2: 1) )
  {
    this = v2;
LABEL_6:
    CTextureListPanel::UpdateTotalUsageLabel(this);
    return;
  }
  CSmartTextureKeyValues::CSmartTextureKeyValues(this: &v31);
  m_p = v31.m_p;
  if ( v31.m_p == nullptr )
  {
    CTextureListPanel::UpdateTotalUsageLabel(this: v2);
    return;
  }
  m_pRenderTxEditor = v2->m_pViewPanel->m_pRenderTxEditor;
  v28 = m_pRenderTxEditor;
  if ( s_eTxListPanelRequest == TXR_RUNNING
    && ((unsigned __int8 (__thiscall *)(CRenderTextureEditor *, int))m_pRenderTxEditor->IsVisible)(
         a1: m_pRenderTxEditor,
         a2) != 0 )
  {
    m_iInfoHint = m_pRenderTxEditor->m_iInfoHint;
    m_pInfo = m_pRenderTxEditor->m_pInfo;
    iHint = m_iInfoHint;
    v32 = m_pInfo;
    if ( m_pInfo == nullptr )
      goto LABEL_24;
    if ( m_iInfoHint == 0 )
      goto LABEL_24;
    if ( !v2->m_pListPanel->IsValidItemID(this: v2->m_pListPanel, a2: m_iInfoHint) )
      goto LABEL_24;
    kv = v2->m_pListPanel->GetItem(this: v2->m_pListPanel, a2: m_iInfoHint);
    if ( kv == nullptr )
      goto LABEL_24;
    String = KeyValues::GetString(this: m_pInfo, keyName: "Name", defaultValue: defaultValue);
    if ( strcmp(KeyValues::GetString(this: kv, keyName: "Name", defaultValue: defaultValue), String) != 0 )
      goto LABEL_24;
    FirstValue = KeyValues::GetFirstValue(this: kv);
    NextValue = KeyValues::GetFirstValue(this: v32);
    v32 = NextValue;
    if ( FirstValue != nullptr )
    {
      while ( NextValue != nullptr )
      {
        v10 = KeyValues::GetString(this: NextValue, keyName: nullptr, defaultValue: defaultValue);
        if ( strcmp(KeyValues::GetString(this: FirstValue, keyName: nullptr, defaultValue: defaultValue), v10) != 0 )
          break;
        FirstValue = KeyValues::GetNextValue(this: FirstValue);
        NextValue = KeyValues::GetNextValue(this: v32);
        v32 = NextValue;
        if ( FirstValue == nullptr )
          goto LABEL_22;
      }
    }
    else
    {
LABEL_22:
      if ( NextValue == nullptr )
      {
LABEL_24:
        m_p = v31.m_p;
        goto LABEL_25;
      }
    }
    CRenderTextureEditor::SetDispInfo(this: v28, kv, iHint);
    goto LABEL_24;
  }
LABEL_25:
  if ( mat_texture_list_all.m_pParent != nullptr && mat_texture_list_all.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( s_eTxListPanelRequest == TXR_RUNNING )
    {
      if ( --s_nFramesForAllTextures <= 0 )
      {
        CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_texture_list.IConVar, value: 0);
        s_eTxListPanelRequest = TXR_SHOW;
      }
    }
    else
    {
      s_eTxListPanelRequest = TXR_RUNNING;
      if ( mat_texture_list_all_frames.m_pParent != nullptr )
        s_nFramesForAllTextures = mat_texture_list_all_frames.m_pParent->m_Value.m_nValue;
      else
        s_nFramesForAllTextures = 0;
    }
  }
  else if ( s_eTxListPanelRequest == TXR_SHOW )
  {
    v2->m_pListPanel->RemoveAll(this: v2->m_pListPanel);
    v2->m_pViewPanel->InvalidateLayout(this: v2->m_pViewPanel, a2: false, a3: false);
    s_eTxListPanelRequest = TXR_RUNNING;
    KeyValues::deleteThis(this: m_p);
    CTextureListPanel::UpdateTotalUsageLabel(this: v2);
    return;
  }
  memset((unsigned __int8 *)dst, value: 0, count: sizeof(dst));
  v11 = v2->m_pSpecialTexs->IsSelected(this: v2->m_pSpecialTexs);
  KeepSpecialKeys(textureList: m_p, bServiceKeys: v11);
  if ( v2->m_pFilteringChk->IsSelected(this: v2->m_pFilteringChk)
    && v2->m_pFilteringText->GetTextLength(this: v2->m_pFilteringText) != 0 )
  {
    v2->m_pFilteringText->GetText_2(this: v2->m_pFilteringText, a2: szFilter, a3: 259);
    v27[255] = 0;
    KeepKeysMatchingFilter(textureList: m_p, szFilter);
  }
  v32 = nullptr;
  for ( i = KeyValues::GetFirstSubKey(this: m_p); i != nullptr; i = KeyValues::GetNextKey(this: i) )
  {
    Int = KeyValues::GetInt(this: i, keyName: "Size", defaultValue: 0);
    v32 = (KeyValues *)((char *)v32 + Int);
    v14 = KeyValues::GetInt(this: i, keyName: "Count", defaultValue: 0);
    if ( v14 > 1 )
      Int *= v14;
    KeyValues::SetInt(this: i, keyName: "Size", value: (Int + 511) / 1024);
    if ( v2->m_pResolveTexturePath->IsSelected(this: v2->m_pResolveTexturePath) )
    {
      memset(v27, 0, sizeof(v27));
      memset(pDest, 0, sizeof(pDest));
      v15 = KeyValues::GetString(this: i, keyName: "Name", defaultValue: defaultValue);
      V_snprintf(pDest, maxLen: 255, pFormat: "materials/%s.vtf", v15);
      v16 = g_pFileSystem->RelativePathToFullPath(
              this: g_pFileSystem,
              a2: pDest,
              a3: "game",
              a4: v27,
              a5: 255,
              a6: 0,
              a7: 0);
      if ( v16 != nullptr )
        KeyValues::SetString(this: i, keyName: "Path", value: v16);
    }
    v17 = CTextureListPanel::AddListItem(this: v2, kv: i);
    if ( v17 < 0x8000 )
      dst[v17 >> 5] |= 1 << (v17 & 0x1F);
  }
  m_pListPanel = v2->m_pListPanel;
  v2->m_numDisplayedSizeKB = ((int)&v32[14].m_sValue + 3) / 1024;
  FirstItem = m_pListPanel->FirstItem;
  v32 = nullptr;
  v20 = FirstItem(this: m_pListPanel);
  if ( v20 != v2->m_pListPanel->InvalidItemID(this: v2->m_pListPanel) )
  {
    do
    {
      v21 = v2->m_pListPanel->NextItem(this: v2->m_pListPanel, a2: v20);
      if ( v20 >= 0x8000 || ((1 << (v20 & 0x1F)) & dst[(unsigned int)v20 >> 5]) == 0 )
      {
        v2->m_pListPanel->RemoveItem(this: v2->m_pListPanel, a2: v20);
        v32 = (KeyValues *)((char *)v32 + 1);
      }
      v20 = v21;
    }
    while ( v21 != v2->m_pListPanel->InvalidItemID(this: v2->m_pListPanel) );
  }
  vgui::ListPanel::GetSortColumnEx(
    this: v2->m_pListPanel,
    iPrimarySortColumn: (int *)&kv,
    iSecondarySortColumn: (int *)&v28,
    bSortAscending: (bool *)&iHint);
  v22 = v2->m_pListPanel;
  v28 = nullptr;
  v22->SetSortColumnEx(this: v22, a2: (int)kv, a3: 0, a4: iHint);
  v2->m_pListPanel->SortList(this: v2->m_pListPanel);
  if ( v32 != nullptr )
    v2->m_pViewPanel->InvalidateLayout(this: v2->m_pViewPanel, a2: false, a3: false);
  KeyValues::deleteThis(this: v31.m_p);
  CTextureListPanel::UpdateTotalUsageLabel(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1009AF40
// Name: public: virtual CRenderTextureEditor::~CRenderTextureEditor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRenderTextureEditor::~CRenderTextureEditor(CRenderTextureEditor *this)
{
  this->__vftable = (CRenderTextureEditor_vtbl *)&CRenderTextureEditor::`vftable';
  CRenderTextureEditor::SetDispInfo(this, kv: nullptr, iHint: 0);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_lstMaterials);
  if ( this->m_bufInfoText.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_bufInfoText.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_bufInfoText.m_Memory.m_pMemory);
      this->m_bufInfoText.m_Memory.m_pMemory = nullptr;
    }
    this->m_bufInfoText.m_Memory.m_nAllocationCount = 0;
  }
  vgui::Frame::~Frame(this);
}

//------------------------------------------------------------------------------
// Address: 0x1009B300
// Name: void MatViewOverride::DisplaySelectedTextures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MatViewOverride::DisplaySelectedTextures(void *ecx0)
{
  double v1; // st7
  ITexture *v2; // eax
  int m_Size; // esi
  unsigned __int16 v4; // si
  unsigned __int16 v5; // bx
  UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  int v7; // edi
  UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t,unsigned short> *v8; // eax
  const char *v9; // eax
  IMaterial *v10; // eax
  IMaterial *v11; // esi
  int v12; // eax
  IMaterial_vtbl *v13; // edx
  int v14; // edi
  int i; // ebx
  int v16; // ecx
  ITexture *v17; // esi
  const char *v18; // eax
  CUtlSymbol *v19; // eax
  int *v20; // ecx
  int v21; // edx
  const char *v22; // eax
  float v23; // eax
  int v24; // edx
  MatViewOverride::ViewParamsLast::VarMap *p_elem; // ebx
  int v26; // eax
  const char *v27; // eax
  IMaterial *v28; // eax
  IMaterial *v29; // esi
  int v30; // eax
  IMaterial_vtbl *v31; // edx
  int v32; // eax
  int v33; // esi
  int j; // edi
  const char *v35; // eax
  unsigned __int16 v36; // ax
  MatViewOverride::ViewParamsLast::TxInfo *v37; // eax
  ITexture *pTx; // eax
  int v39; // edi
  int v40; // ebx
  MatViewOverride::ViewParamsLast::VarMap *v41; // esi
  CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t search; // [esp+4h] [ebp-54h] BYREF
  CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t insert; // [esp+28h] [ebp-30h] BYREF
  MatViewOverride::ViewParamsLast::TxInfo txinfo; // [esp+34h] [ebp-24h]
  ITexture *txEmpty; // [esp+3Ch] [ebp-1Ch]
  int kEnd; // [esp+40h] [ebp-18h]
  MatViewOverride::ViewParamsLast::VarMap *vars; // [esp+44h] [ebp-14h]
  int idx; // [esp+48h] [ebp-10h]
  CUtlSymbol symVarName; // [esp+4Ch] [ebp-Ch] BYREF
  int numParams; // [esp+50h] [ebp-8h] BYREF
  int bRemovedSelection; // [esp+54h] [ebp-4h] BYREF

  if ( MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree.m_NumElements != 0 )
  {
    v1 = _Plat_FloatTime(a1: ecx0);
    *(float *)&idx = v1;
    if ( v1 >= MatViewOverride::s_viewParamsLast.flTime
      && MatViewOverride::s_viewParamsLast.flTime + 0.4 > v1
      && MatViewOverride::s_viewParamsReq.lstMaterials.m_Size != 0 )
    {
      return;
    }
    LODWORD(MatViewOverride::s_viewParamsLast.flTime) = idx;
    MatViewOverride::s_viewParamsLast.bHighlighted = !MatViewOverride::s_viewParamsLast.bHighlighted;
  }
  else
  {
    if ( MatViewOverride::s_viewParamsReq.lstMaterials.m_Size == 0 )
      return;
    MatViewOverride::s_viewParamsLast.flTime = _Plat_FloatTime(a1: ecx0);
    MatViewOverride::s_viewParamsLast.bHighlighted = false;
  }
  v2 = materials->FindTexture(this: materials, a2: "debugempty", a3: defaultValue, a4: 0, a5: 0);
  m_Size = MatViewOverride::s_viewParamsReq.lstMaterials.m_Size;
  txEmpty = v2;
  *(float *)&idx = 0.0;
  kEnd = MatViewOverride::s_viewParamsReq.lstMaterials.m_Size;
  if ( MatViewOverride::s_viewParamsReq.lstMaterials.m_Size > 0 )
  {
    do
    {
      v4 = MatViewOverride::s_viewParamsReq.lstMaterials.m_Memory.m_pMemory[idx];
      search.elem.m_Tree.m_LessFunc.m_LessFunc = CDefOps<unsigned short>::LessFunc;
      memset(&search.elem.m_Tree.m_Elements, 0, sizeof(search.elem.m_Tree.m_Elements));
      *(_DWORD *)&search.elem.m_Tree.m_Root = 0xFFFF;
      *(_DWORD *)&search.elem.m_Tree.m_FirstFree = -1;
      search.elem.m_Tree.m_pElements = nullptr;
      search.key = v4;
      v5 = CUtlRBTree<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
             this: &MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree,
             &search);
      CUtlRBTree<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &search.elem.m_Tree);
      m_pMemory = search.elem.m_Tree.m_Elements.m_pMemory;
      search.elem.m_Tree.m_FirstFree = -1;
      if ( search.elem.m_Tree.m_Elements.m_nGrowSize >= 0 )
      {
        if ( search.elem.m_Tree.m_Elements.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.elem.m_Tree.m_Elements.m_pMemory);
          m_pMemory = nullptr;
          search.elem.m_Tree.m_Elements.m_pMemory = nullptr;
        }
        search.elem.m_Tree.m_Elements.m_nAllocationCount = 0;
      }
      search.elem.m_Tree.m_LastAlloc.index = -1;
      if ( search.elem.m_Tree.m_Elements.m_nGrowSize >= 0 && m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      if ( v5 == 0xFFFF )
      {
        *(_DWORD *)&search.elem.m_Tree.m_Root = 0xFFFF;
        search.elem.m_Tree.m_LessFunc.m_LessFunc = CDefOps<unsigned short>::LessFunc;
        memset(&search.elem.m_Tree.m_Elements, 0, sizeof(search.elem.m_Tree.m_Elements));
        *(_DWORD *)&search.elem.m_Tree.m_FirstFree = -1;
        search.elem.m_Tree.m_pElements = nullptr;
        search.key = v4;
        v7 = CUtlRBTree<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
               this: &MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree,
               insert: &search);
        CUtlRBTree<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &search.elem.m_Tree);
        v8 = search.elem.m_Tree.m_Elements.m_pMemory;
        search.elem.m_Tree.m_FirstFree = -1;
        if ( search.elem.m_Tree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( search.elem.m_Tree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: search.elem.m_Tree.m_Elements.m_pMemory);
            v8 = nullptr;
            search.elem.m_Tree.m_Elements.m_pMemory = nullptr;
          }
          search.elem.m_Tree.m_Elements.m_nAllocationCount = 0;
        }
        search.elem.m_Tree.m_LastAlloc.index = -1;
        if ( search.elem.m_Tree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v8 != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
            search.elem.m_Tree.m_Elements.m_pMemory = nullptr;
          }
          search.elem.m_Tree.m_Elements.m_nAllocationCount = 0;
        }
        vars = &MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree.m_Elements.m_pMemory[v7].m_Data.elem;
        HIWORD(bRemovedSelection) = v4;
        v9 = CUtlSymbol::String(this: (CUtlSymbol *)&bRemovedSelection + 1);
        v10 = materials->FindMaterial(this: materials, a2: v9, a3: "Other textures", a4: 0, a5: 0);
        v11 = v10;
        if ( v10 != nullptr )
        {
          v12 = v10->ShaderParamCount(this: v10);
          v13 = v11->__vftable;
          bRemovedSelection = v12;
          v14 = 0;
          for ( i = (int)v13->GetShaderParams(this: v11); v14 < bRemovedSelection; ++v14 )
          {
            v16 = *(_DWORD *)(i + 4 * v14);
            if ( (*(_BYTE *)(v16 + 28) & 0xF) == 3 )
            {
              v17 = (ITexture *)(**(int (__thiscall ***)(int))v16)(a1: v16);
              if ( v17 != nullptr && !v17->IsError(this: v17) )
              {
                v18 = (const char *)v17->GetName(this: v17);
                v19 = CUtlSymbol::CUtlSymbol(this: &symVarName, pStr: v18);
                v20 = *(int **)(i + 4 * v14);
                v21 = *v20;
                txinfo.name = (CUtlSymbol)v19->m_Id;
                v22 = (const char *)(*(int (__thiscall **)(int *))(v21 + 8))(a1: v20);
                insert.key = CUtlSymbol::CUtlSymbol(this: (CUtlSymbol *)&numParams + 1, pStr: v22)->m_Id;
                insert.elem.pTx = v17;
                insert.elem.name.m_Id = txinfo.name.m_Id;
                CUtlRBTree<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
                  this: &vars->m_Tree,
                  &insert);
              }
            }
          }
        }
      }
      ++idx;
    }
    while ( idx < kEnd );
    m_Size = MatViewOverride::s_viewParamsReq.lstMaterials.m_Size;
  }
  LODWORD(v23) = (unsigned __int16)CUtlRBTree<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree);
  *(float *)&idx = v23;
  if ( LOWORD(v23) != 0xFFFF )
  {
    while ( 1 )
    {
      v24 = LOWORD(v23);
      p_elem = &MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree.m_Elements.m_pMemory[v24].m_Data.elem;
      v26 = 0;
      if ( m_Size <= 0 )
      {
LABEL_40:
        v26 = -1;
      }
      else
      {
        while ( MatViewOverride::s_viewParamsReq.lstMaterials.m_Memory.m_pMemory[v26] != MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree.m_Elements.m_pMemory[v24].m_Data.key )
        {
          if ( ++v26 >= m_Size )
            goto LABEL_40;
        }
      }
      HIWORD(numParams) = MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree.m_Elements.m_pMemory[v24].m_Data.key;
      HIBYTE(bRemovedSelection) = v26 < 0;
      v27 = CUtlSymbol::String(this: (CUtlSymbol *)&numParams + 1);
      v28 = materials->FindMaterial(this: materials, a2: v27, a3: "Other textures", a4: 0, a5: 0);
      v29 = v28;
      if ( v28 != nullptr )
      {
        v30 = v28->ShaderParamCount(this: v28);
        v31 = v29->__vftable;
        numParams = v30;
        v32 = (int)v31->GetShaderParams(this: v29);
        v33 = 0;
        for ( j = v32; v33 < numParams; ++v33 )
        {
          v35 = (const char *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)(j + 4 * v33) + 8))(a1: *(_DWORD *)(j + 4 * v33));
          CUtlSymbol::CUtlSymbol(this: &symVarName, pStr: v35);
          insert.elem.name.m_Id = -1;
          insert.key = symVarName.m_Id;
          v36 = CUtlRBTree<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                  this: &p_elem->m_Tree,
                  search: &insert);
          if ( v36 != 0xFFFF )
          {
            v37 = &p_elem->m_Tree.m_Elements.m_pMemory[v36].m_Data.elem;
            if ( !MatViewOverride::s_viewParamsLast.bHighlighted || HIBYTE(bRemovedSelection) != 0 )
              pTx = v37->pTx;
            else
              pTx = txEmpty;
            (*(void (__thiscall **)(_DWORD, ITexture *))(**(_DWORD **)(j + 4 * v33) + 60))(
              a1: *(_DWORD *)(j + 4 * v33),
              a2: pTx);
          }
        }
      }
      if ( HIBYTE(bRemovedSelection) != 0 )
      {
        v39 = (unsigned __int16)idx;
        idx = (unsigned __int16)CUtlRBTree<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                                  this: &MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree,
                                  i: idx);
        if ( (_WORD)v39 != 0xFFFF )
        {
          CUtlRBTree<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
            this: &MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree,
            elem: v39);
          v40 = v39;
          v41 = &MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree.m_Elements.m_pMemory[v39].m_Data.elem;
          CUtlRBTree<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::TxInfo,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &v41->m_Tree);
          v41->m_Tree.m_FirstFree = -1;
          if ( v41->m_Tree.m_Elements.m_nGrowSize >= 0 )
          {
            if ( v41->m_Tree.m_Elements.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41->m_Tree.m_Elements.m_pMemory);
              v41->m_Tree.m_Elements.m_pMemory = nullptr;
            }
            v41->m_Tree.m_Elements.m_nAllocationCount = 0;
          }
          v41->m_Tree.m_LastAlloc.index = -1;
          if ( v41->m_Tree.m_Elements.m_nGrowSize >= 0 )
          {
            if ( v41->m_Tree.m_Elements.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v41->m_Tree.m_Elements.m_pMemory);
              v41->m_Tree.m_Elements.m_pMemory = nullptr;
            }
            v41->m_Tree.m_Elements.m_nAllocationCount = 0;
          }
          MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree.m_Elements.m_pMemory[v40].m_Left = v39;
          MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree.m_Elements.m_pMemory[v40].m_Right = MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree.m_FirstFree;
          --MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree.m_NumElements;
          MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree.m_FirstFree = v39;
        }
      }
      else
      {
        idx = (unsigned __int16)CUtlRBTree<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                                  this: &MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree,
                                  i: idx);
      }
      if ( (_WORD)idx == 0xFFFF )
        break;
      m_Size = MatViewOverride::s_viewParamsReq.lstMaterials.m_Size;
      LOWORD(v23) = idx;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1009B830
// Name: void CL_TextureListPanel_ClearState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CL_TextureListPanel_ClearState(void *ecx0)
{
  MatViewOverride::s_viewParamsReq.lstMaterials.m_Size = 0;
  MatViewOverride::DisplaySelectedTextures(ecx0);
}

//------------------------------------------------------------------------------
// Address: 0x1009B840
// Name: void VGui_UpdateTextureListPanel(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall VGui_UpdateTextureListPanel(void *this)
{
  int v1; // eax
  int v2; // eax
  int m_nValue; // eax
  int v4; // eax
  bool v5; // bl
  bool (__thiscall *IsVisible)(vgui::Panel *); // edx
  con_nprint_s info; // [esp+0h] [ebp-44h] BYREF
  char kb1[20]; // [esp+18h] [ebp-2Ch] BYREF
  char kb2[20]; // [esp+2Ch] [ebp-18h] BYREF
  BOOL bShouldDrawTxListPanel; // [esp+40h] [ebp-4h]

  if ( mat_show_texture_memory_usage.m_pParent != nullptr
    && mat_show_texture_memory_usage.m_pParent->m_Value.m_nValue != 0 )
  {
    info.fixed_width_font = true;
    v1 = ((int (__thiscall *)(IDebugTextureInfo *, int, int, int, int, int, _DWORD, _DWORD))g_pMaterialSystemDebugTextureInfo->GetTextureMemoryUsed)(
           a1: g_pMaterialSystemDebugTextureInfo,
           a2: 1,
           a3: 4,
           a4: 1045220557,
           a5: 1065353216,
           a6: 1056964608,
           a7: 0,
           a8: *(_DWORD *)&info.fixed_width_font);
    FmtCommaNumber(pchBuffer: kb1, uiNumber: (v1 + 511) / 1024);
    v2 = g_pMaterialSystemDebugTextureInfo->GetTextureMemoryUsed(
           this: g_pMaterialSystemDebugTextureInfo,
           a2: MEMORY_TOTAL_LOADED);
    FmtCommaNumber(pchBuffer: kb2, uiNumber: (v2 + 511) / 1024);
    Con_NXPrintf(&info, fmt: "Texture Memory Usage: %s Kb / %s Kb", kb1, kb2);
  }
  MatViewOverride::DisplaySelectedTextures(ecx0: this);
  if ( mat_texture_list_all.m_pParent != nullptr )
    m_nValue = mat_texture_list_all.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  g_pMaterialSystemDebugTextureInfo->EnableGetAllTextures(this: g_pMaterialSystemDebugTextureInfo, a2: m_nValue != 0);
  if ( mat_texture_list.m_pParent != nullptr )
    v4 = mat_texture_list.m_pParent->m_Value.m_nValue;
  else
    v4 = 0;
  g_pMaterialSystemDebugTextureInfo->EnableDebugTextureList(this: g_pMaterialSystemDebugTextureInfo, a2: v4 > 0);
  v5 = g_pTextureListPanel->ShouldDraw(this: g_pTextureListPanel);
  IsVisible = g_pTextureListPanel->IsVisible;
  LOBYTE(bShouldDrawTxListPanel) = v5;
  if ( IsVisible(this: g_pTextureListPanel) != v5 )
  {
    g_pTextureListPanel->SetVisible(this: g_pTextureListPanel, a2: bShouldDrawTxListPanel);
    if ( v5 )
    {
      mat_texture_list_on_f();
    }
    else
    {
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&mat_texture_list.IConVar, value: 0);
      s_eTxListPanelRequest = TXR_HIDE;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100A1740
// Name: public: virtual void CRenderTextureEditor::Activate(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CRenderTextureEditor::Activate(CRenderTextureEditor *this)
{
  vgui::Frame::Activate(this);
}

//------------------------------------------------------------------------------
// Address: 0x101CECF0
// Name: public: static bool CDefOps<unsigned short>::LessFunc(unsigned short const __near &,unsigned short const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDefOps<unsigned short>::LessFunc(const unsigned __int16 *lhs, const unsigned __int16 *rhs)
{
  return *lhs < *rhs;
}

//------------------------------------------------------------------------------
// Address: 0x102ACDA0
// Name: public: virtual unsigned long vgui::TileViewPanelEx::GetFont(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall vgui::TileViewPanelEx::GetFont(vgui::Menu *this)
{
  return this->m_MenuItems.m_ElementCount;
}

//------------------------------------------------------------------------------
// Address: 0x102B2DA0
// Name: public: virtual unsigned long CRenderTextureEditor::GetFont(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PropertySheet *__thiscall CRenderTextureEditor::GetFont(vgui::PropertyDialog *this)
{
  return this->_propertySheet;
}

//------------------------------------------------------------------------------
// Address: 0x102CC4C0
// Name: public: virtual int vgui::TextEntry::GetTextCursorPos(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall vgui::TextEntry::GetTextCursorPos(vgui::TreeView *this)
{
  return this->m_Font;
}

//------------------------------------------------------------------------------
// Address: 0x10313F40
// Name: MatViewOverride::_dynamic_initializer_for__s_viewParamsReq__
// Source: json
//------------------------------------------------------------------------------
int MatViewOverride::_dynamic_initializer_for__s_viewParamsReq__()
{
  return atexit(func: MatViewOverride::_dynamic_atexit_destructor_for__s_viewParamsReq__);
}

//------------------------------------------------------------------------------
// Address: 0x10313F50
// Name: MatViewOverride::_dynamic_initializer_for__s_viewParamsLast__
// Source: json
//------------------------------------------------------------------------------
int MatViewOverride::_dynamic_initializer_for__s_viewParamsLast__()
{
  return atexit(func: MatViewOverride::_dynamic_atexit_destructor_for__s_viewParamsLast__);
}

//------------------------------------------------------------------------------
// Address: 0x10322BF0
// Name: MatViewOverride::_dynamic_atexit_destructor_for__s_viewParamsReq__
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatViewOverride::_dynamic_atexit_destructor_for__s_viewParamsReq__()
{
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&MatViewOverride::s_viewParamsReq);
}

//------------------------------------------------------------------------------
// Address: 0x10322C00
// Name: MatViewOverride::_dynamic_atexit_destructor_for__s_viewParamsLast__
// Source: json
//------------------------------------------------------------------------------
void __cdecl MatViewOverride::_dynamic_atexit_destructor_for__s_viewParamsLast__()
{
  CUtlRBTree<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned short,MatViewOverride::ViewParamsLast::VarMap,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &MatViewOverride::s_viewParamsLast.lstMaterials.m_Tree);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1031FCD0
// Name: _dynamic_initializer_for__texture_budget_panel_global__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__texture_budget_panel_global__()
{
  ConVar::ConVar(
    this: &texture_budget_panel_global,
    pName: "texture_budget_panel_global",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Show global times in the texture budget panel.");
  return atexit(func: dynamic_atexit_destructor_for__texture_budget_panel_global__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FE20
// Name: _dynamic_initializer_for__texture_budget_panel_x__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__texture_budget_panel_x__()
{
  ConVar::ConVar(
    this: &texture_budget_panel_x,
    pName: "texture_budget_panel_x",
    pDefaultValue: "0",
    flags: 128,
    pHelpString: "number of pixels from the left side of the game screen to draw the budget panel",
    callback: TextureCVarChangedCallBack);
  return atexit(func: dynamic_atexit_destructor_for__texture_budget_panel_x__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FE50
// Name: _dynamic_initializer_for__texture_budget_panel_y__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__texture_budget_panel_y__()
{
  ConVar::ConVar(
    this: &texture_budget_panel_y,
    pName: "texture_budget_panel_y",
    pDefaultValue: "450",
    flags: 128,
    pHelpString: "number of pixels from the top side of the game screen to draw the budget panel",
    callback: TextureCVarChangedCallBack);
  return atexit(func: dynamic_atexit_destructor_for__texture_budget_panel_y__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FE80
// Name: _dynamic_initializer_for__texture_budget_panel_width__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__texture_budget_panel_width__()
{
  ConVar::ConVar(
    this: &texture_budget_panel_width,
    pName: "texture_budget_panel_width",
    pDefaultValue: "512",
    flags: 128,
    pHelpString: "width in pixels of the budget panel",
    callback: TextureCVarChangedCallBack);
  return atexit(func: dynamic_atexit_destructor_for__texture_budget_panel_width__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FEB0
// Name: _dynamic_initializer_for__texture_budget_panel_height__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__texture_budget_panel_height__()
{
  ConVar::ConVar(
    this: &texture_budget_panel_height,
    pName: "texture_budget_panel_height",
    pDefaultValue: "284",
    flags: 128,
    pHelpString: "height in pixels of the budget panel",
    callback: TextureCVarChangedCallBack);
  return atexit(func: dynamic_atexit_destructor_for__texture_budget_panel_height__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FEE0
// Name: _dynamic_initializer_for__texture_budget_panel_bottom_of_history_fraction__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__texture_budget_panel_bottom_of_history_fraction__()
{
  ConVar::ConVar(
    this: &texture_budget_panel_bottom_of_history_fraction,
    pName: "texture_budget_panel_bottom_of_history_fraction",
    pDefaultValue: ".25",
    flags: 128,
    pHelpString: "number between 0 and 1",
    callback: TextureCVarChangedCallBack);
  return atexit(func: dynamic_atexit_destructor_for__texture_budget_panel_bottom_of_history_fraction__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FF10
// Name: _dynamic_initializer_for__texture_budget_background_alpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__texture_budget_background_alpha__()
{
  ConVar::ConVar(
    this: &texture_budget_background_alpha,
    pName: "texture_budget_background_alpha",
    pDefaultValue: "128",
    flags: 128,
    pHelpString: "how translucent the budget panel is");
  return atexit(func: dynamic_atexit_destructor_for__texture_budget_background_alpha__);
}

//------------------------------------------------------------------------------
// Address: 0x103205C0
// Name: _dynamic_initializer_for__panel_test_title_safe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__panel_test_title_safe__()
{
  ConVar::ConVar(
    this: &panel_test_title_safe,
    pName: "panel_test_title_safe",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Test vgui panel positioning with title safe indentation");
  return atexit(func: dynamic_atexit_destructor_for__panel_test_title_safe__);
}

//------------------------------------------------------------------------------
// Address: 0x10327700
// Name: _dynamic_atexit_destructor_for__texture_budget_panel_global__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__texture_budget_panel_global__()
{
  ConVar::~ConVar(this: &texture_budget_panel_global);
}

//------------------------------------------------------------------------------
// Address: 0x10327770
// Name: _dynamic_atexit_destructor_for__texture_budget_panel_x__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__texture_budget_panel_x__()
{
  ConVar::~ConVar(this: &texture_budget_panel_x);
}

//------------------------------------------------------------------------------
// Address: 0x10327780
// Name: _dynamic_atexit_destructor_for__texture_budget_panel_y__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__texture_budget_panel_y__()
{
  ConVar::~ConVar(this: &texture_budget_panel_y);
}

//------------------------------------------------------------------------------
// Address: 0x10327790
// Name: _dynamic_atexit_destructor_for__texture_budget_panel_width__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__texture_budget_panel_width__()
{
  ConVar::~ConVar(this: &texture_budget_panel_width);
}

//------------------------------------------------------------------------------
// Address: 0x103277A0
// Name: _dynamic_atexit_destructor_for__texture_budget_panel_height__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__texture_budget_panel_height__()
{
  ConVar::~ConVar(this: &texture_budget_panel_height);
}

//------------------------------------------------------------------------------
// Address: 0x103277B0
// Name: _dynamic_atexit_destructor_for__texture_budget_panel_bottom_of_history_fraction__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__texture_budget_panel_bottom_of_history_fraction__()
{
  ConVar::~ConVar(this: &texture_budget_panel_bottom_of_history_fraction);
}

//------------------------------------------------------------------------------
// Address: 0x103277C0
// Name: _dynamic_atexit_destructor_for__texture_budget_background_alpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__texture_budget_background_alpha__()
{
  ConVar::~ConVar(this: &texture_budget_background_alpha);
}

//------------------------------------------------------------------------------
// Address: 0x10327AF0
// Name: _dynamic_atexit_destructor_for__panel_test_title_safe__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__panel_test_title_safe__()
{
  ConVar::~ConVar(this: &panel_test_title_safe);
}

//------------------------------------------------------------------------------
// Address: 0x1031FD00
// Name: _dynamic_initializer_for__showbudget_texture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__showbudget_texture__()
{
  ConVar::ConVar(
    this: &showbudget_texture,
    pName: "showbudget_texture",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Enable the texture budget panel.");
  return atexit(func: dynamic_atexit_destructor_for__showbudget_texture__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FD30
// Name: _dynamic_initializer_for__showbudget_texture_global_sum__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__showbudget_texture_global_sum__()
{
  ConVar::ConVar(
    this: &showbudget_texture_global_sum,
    pName: "showbudget_texture_global_sum",
    pDefaultValue: "0.0f",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__showbudget_texture_global_sum__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FD60
// Name: _dynamic_initializer_for__showbudget_texture_on__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__showbudget_texture_on__()
{
  ConCommand::ConCommand(
    this: &showbudget_texture_on,
    pName: "+showbudget_texture",
    callback: showbudget_texture_on_f,
    pHelpString: defaultValue,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__showbudget_texture_on__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FD90
// Name: _dynamic_initializer_for__showbudget_texture_off__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__showbudget_texture_off__()
{
  ConCommand::ConCommand(
    this: &showbudget_texture_off,
    pName: "-showbudget_texture",
    callback: showbudget_texture_off_f,
    pHelpString: defaultValue,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__showbudget_texture_off__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FDC0
// Name: _dynamic_initializer_for__showbudget_texture_global_on__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__showbudget_texture_global_on__()
{
  ConCommand::ConCommand(
    this: &showbudget_texture_global_on,
    pName: "+showbudget_texture_global",
    callback: showbudget_texture_global_on_f,
    pHelpString: defaultValue,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__showbudget_texture_global_on__);
}

//------------------------------------------------------------------------------
// Address: 0x1031FDF0
// Name: _dynamic_initializer_for__showbudget_texture_global_off__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__showbudget_texture_global_off__()
{
  ConCommand::ConCommand(
    this: &showbudget_texture_global_off,
    pName: "-showbudget_texture_global",
    callback: showbudget_texture_off_f,
    pHelpString: defaultValue,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__showbudget_texture_global_off__);
}

//------------------------------------------------------------------------------
// Address: 0x10327710
// Name: _dynamic_atexit_destructor_for__showbudget_texture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__showbudget_texture__()
{
  ConVar::~ConVar(this: &showbudget_texture);
}

//------------------------------------------------------------------------------
// Address: 0x10327720
// Name: _dynamic_atexit_destructor_for__showbudget_texture_global_sum__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__showbudget_texture_global_sum__()
{
  ConVar::~ConVar(this: &showbudget_texture_global_sum);
}

//------------------------------------------------------------------------------
// Address: 0x10327730
// Name: _dynamic_atexit_destructor_for__showbudget_texture_on__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__showbudget_texture_on__()
{
  ConCommand::~ConCommand(this: &showbudget_texture_on);
}

//------------------------------------------------------------------------------
// Address: 0x10327740
// Name: _dynamic_atexit_destructor_for__showbudget_texture_off__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__showbudget_texture_off__()
{
  ConCommand::~ConCommand(this: &showbudget_texture_off);
}

//------------------------------------------------------------------------------
// Address: 0x10327750
// Name: _dynamic_atexit_destructor_for__showbudget_texture_global_on__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__showbudget_texture_global_on__()
{
  ConCommand::~ConCommand(this: &showbudget_texture_global_on);
}

//------------------------------------------------------------------------------
// Address: 0x10327760
// Name: _dynamic_atexit_destructor_for__showbudget_texture_global_off__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__showbudget_texture_global_off__()
{
  ConCommand::~ConCommand(this: &showbudget_texture_global_off);
}

} // namespace engine_xlsp
