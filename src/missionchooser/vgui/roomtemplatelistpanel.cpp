// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: missionchooser/vgui/roomtemplatelistpanel.cpp
// Functions: 21
// ============================================================

#include "missionchooser\vgui\roomtemplatelistpanel.h"

//------------------------------------------------------------------------------
// Address: 0x10029940
// Name: public: static char const __near * CRoomTemplateListPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CRoomTemplateListPanel::GetPanelClassName()
{
  return "CRoomTemplateListPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10029950
// Name: private: static int CRoomTemplateListPanel::CompareFolders(struct CRoomTemplateListPanel::RoomTemplateFolder_t const __near *,struct CRoomTemplateListPanel::RoomTemplateFolder_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CRoomTemplateListPanel::CompareFolders(const char *s1, const char *s2)
{
  return _V_stricmp(s1, s2);
}

//------------------------------------------------------------------------------
// Address: 0x10029960
// Name: public: void CRoomTemplateListPanel::SetFilterText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplateListPanel::SetFilterText(CRoomTemplateListPanel *this, const char *pText)
{
  V_strncpy(pDest: this->m_FilterText, pSrc: pText, maxLen: 256);
}

//------------------------------------------------------------------------------
// Address: 0x10029990
// Name: public: void CUtlMemory<struct CRoomTemplateListPanel::RoomTemplateFolder_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CRoomTemplateListPanel::RoomTemplateFolder_t,int>::Grow(
        CUtlMemory<GDIVITEM,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  GDIVITEM *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

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
        m_nAllocationCount = 1;
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
    v7 = 268 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (GDIVITEM *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (GDIVITEM *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029A30
// Name: public: void CRoomTemplateListPanel::UpdatePanelsWithTemplate(class CRoomTemplate const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplateListPanel::UpdatePanelsWithTemplate(
        CRoomTemplateListPanel *this,
        const CRoomTemplate *pTemplate)
{
  int m_Size; // ebx
  int i; // esi
  CRoomTemplatePanel *v5; // ecx

  m_Size = this->m_Thumbnails.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v5 = this->m_Thumbnails.m_Memory.m_pMemory[i];
    if ( v5 != nullptr && v5->m_pRoomTemplate == pTemplate )
      CRoomTemplatePanel::UpdateImages(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029A70
// Name: public: virtual void CRoomTemplateListPanel::OnExpandAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplateListPanel::OnExpandAll(CRoomTemplateListPanel *this)
{
  int v1; // eax
  int v2; // edx

  v1 = 0;
  if ( this->m_RoomTemplateFolders.m_Size > 0 )
  {
    v2 = 0;
    do
    {
      this->m_RoomTemplateFolders.m_Memory.m_pMemory[v2].m_bExpanded = true;
      ++v1;
      ++v2;
    }
    while ( v1 < this->m_RoomTemplateFolders.m_Size );
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10029AB0
// Name: public: virtual void CRoomTemplateListPanel::OnCollapseAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplateListPanel::OnCollapseAll(CRoomTemplateListPanel *this)
{
  int v1; // eax
  int v2; // edx

  v1 = 0;
  if ( this->m_RoomTemplateFolders.m_Size > 0 )
  {
    v2 = 0;
    do
    {
      this->m_RoomTemplateFolders.m_Memory.m_pMemory[v2].m_bExpanded = false;
      ++v1;
      ++v2;
    }
    while ( v1 < this->m_RoomTemplateFolders.m_Size );
  }
  this->InvalidateLayout(this, a2: false, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x10029AF0
// Name: public: virtual void CRoomTemplateListPanel::OnToggleFolder(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplateListPanel::OnToggleFolder(CRoomTemplateListPanel *this, KeyValues *pKV)
{
  int v3; // edi
  int i; // ebx
  const char *pFolderName; // [esp+10h] [ebp+8h]

  v3 = 0;
  pFolderName = KeyValues::GetString(this: pKV, keyName: "folder", defaultValue: nullptr);
  if ( this->m_RoomTemplateFolders.m_Size > 0 )
  {
    for ( i = 0; _V_stricmp(s1: pFolderName, s2: this->m_RoomTemplateFolders.m_Memory.m_pMemory[i].m_FolderName) != 0; ++i )
    {
      if ( ++v3 >= this->m_RoomTemplateFolders.m_Size )
        return;
    }
    this->m_RoomTemplateFolders.m_Memory.m_pMemory[v3].m_bExpanded = !this->m_RoomTemplateFolders.m_Memory.m_pMemory[v3].m_bExpanded;
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10029B80
// Name: private: bool CRoomTemplateListPanel::FilterTemplate(class CRoomTemplate const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRoomTemplateListPanel::FilterTemplate(CRoomTemplateListPanel *this, const CRoomTemplate *pTemplate)
{
  char *m_FilterText; // edi
  int v5; // esi
  bool bInvert; // [esp+7h] [ebp-1h]
  int nNumTags; // [esp+10h] [ebp+8h]

  m_FilterText = this->m_FilterText;
  bInvert = false;
  if ( this->m_FilterText[0] == 33 )
  {
    bInvert = true;
    m_FilterText = &this->m_FilterText[1];
  }
  if ( *m_FilterText == 0 )
    return 1;
  if ( V_stristr(pStr: pTemplate->m_Description, pSearch: m_FilterText) != nullptr
    || V_stristr(pStr: pTemplate->m_FullName, pSearch: m_FilterText) != nullptr )
  {
    return !bInvert;
  }
  v5 = 0;
  nNumTags = pTemplate->m_Tags.m_Size;
  if ( nNumTags <= 0 )
    return bInvert;
  while ( V_stristr(pStr: pTemplate->m_Tags.m_Memory.m_pMemory[v5], pSearch: m_FilterText) == nullptr )
  {
    if ( ++v5 >= nNumTags )
      return bInvert;
  }
  return !bInvert;
}

//------------------------------------------------------------------------------
// Address: 0x10029CF0
// Name: public: virtual void CRoomTemplateListPanel::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplateListPanel::PerformLayout(CRoomTemplateListPanel *this)
{
  vgui::Panel *v2; // eax
  int Wide; // eax
  int v4; // eax
  vgui::Button *m_pRefreshList; // ecx
  int v6; // ebx
  int v7; // ebx
  int v8; // ebx
  CRoomTemplateListPanel::RoomTemplateFolder_t *v9; // edi
  const char *v10; // eax
  CRoomTemplateListPanel::RoomTemplateFolder_t *v11; // edi
  int v12; // eax
  int v13; // ebx
  bool v14; // cc
  int v15; // edi
  char pDest[268]; // [esp+Ch] [ebp-12Ch] BYREF
  int tt; // [esp+118h] [ebp-20h]
  int nPanelWidth; // [esp+11Ch] [ebp-1Ch]
  int i; // [esp+120h] [ebp-18h]
  int tw; // [esp+124h] [ebp-14h]
  int j; // [esp+128h] [ebp-10h]
  int tallest_on_this_row; // [esp+12Ch] [ebp-Ch]
  unsigned int v23; // [esp+130h] [ebp-8h]
  int cur_x; // [esp+134h] [ebp-4h]

  v2 = this->GetParent(this);
  Wide = vgui::Panel::GetWide(this: v2);
  vgui::Panel::SetWide(this, wide: Wide);
  cur_x = 8;
  v4 = vgui::Panel::GetWide(this);
  m_pRefreshList = this->m_pRefreshList;
  v6 = v4;
  nPanelWidth = v4;
  tallest_on_this_row = 0;
  vgui::Panel::SetBounds(this: m_pRefreshList, x: 8, y: 8, wide: v4 - 16, tall: 24);
  v7 = (v6 - 24) / 2;
  if ( v7 <= 40 )
    v7 = 40;
  vgui::Panel::SetBounds(this: this->m_pExpandAll, x: 8, y: 40, wide: v7, tall: 24);
  vgui::Panel::SetBounds(this: this->m_pCollapseAll, x: v7 + 16, y: 40, wide: v7, tall: 24);
  v8 = 72;
  i = 0;
  if ( this->m_RoomTemplateFolders.m_Size > 0 )
  {
    v23 = 0;
    do
    {
      v9 = &this->m_RoomTemplateFolders.m_Memory.m_pMemory[v23 / 0x10C];
      v10 = "-";
      if ( !v9->m_bExpanded )
        v10 = "+";
      V_snprintf(
        pDest,
        maxLen: 265,
        pFormat: "%s %s",
        v10,
        this->m_RoomTemplateFolders.m_Memory.m_pMemory[v23 / 0x10C].m_FolderName);
      v9->m_pFolderButton->SetText(this: v9->m_pFolderButton, a2: pDest);
      v11 = &this->m_RoomTemplateFolders.m_Memory.m_pMemory[v23 / 0x10C];
      v12 = vgui::Panel::GetWide(this);
      vgui::Panel::SetBounds(this: v11->m_pFolderButton, x: 8, y: v8, wide: v12 - 16, tall: 24);
      v13 = v8 + 24;
      v14 = this->m_Thumbnails.m_Size <= 0;
      j = 0;
      if ( !v14 )
      {
        do
        {
          v15 = j;
          if ( _V_stricmp(
                 s1: this->m_Thumbnails.m_Memory.m_pMemory[j]->m_pRoomTemplate->m_SubFolder,
                 s2: this->m_RoomTemplateFolders.m_Memory.m_pMemory[v23 / 0x10C].m_FolderName) == 0 )
          {
            if ( this->m_RoomTemplateFolders.m_Memory.m_pMemory[v23 / 0x10C].m_bExpanded
              && CRoomTemplateListPanel::FilterTemplate(
                   this,
                   pTemplate: this->m_Thumbnails.m_Memory.m_pMemory[v15]->m_pRoomTemplate) != 0 )
            {
              this->m_Thumbnails.m_Memory.m_pMemory[v15]->SetVisible(
                this: this->m_Thumbnails.m_Memory.m_pMemory[v15],
                a2: true);
              this->m_Thumbnails.m_Memory.m_pMemory[v15]->InvalidateLayout(
                this: this->m_Thumbnails.m_Memory.m_pMemory[v15],
                a2: true,
                a3: false);
              tw = vgui::Panel::GetWide(this: this->m_Thumbnails.m_Memory.m_pMemory[v15]);
              tt = vgui::Panel::GetTall(this: this->m_Thumbnails.m_Memory.m_pMemory[v15]);
              if ( cur_x + tw > nPanelWidth )
              {
                cur_x = 8;
                v13 += tallest_on_this_row + 8;
                tallest_on_this_row = 0;
              }
              vgui::Panel::SetPos(this: this->m_Thumbnails.m_Memory.m_pMemory[v15], x: cur_x, y: v13);
              if ( tt > tallest_on_this_row )
                tallest_on_this_row = tt;
              cur_x += tw + 8;
            }
            else
            {
              this->m_Thumbnails.m_Memory.m_pMemory[v15]->SetVisible(
                this: this->m_Thumbnails.m_Memory.m_pMemory[v15],
                a2: false);
            }
          }
          ++j;
        }
        while ( j < this->m_Thumbnails.m_Size );
      }
      v23 += 268;
      v8 = v13 + tallest_on_this_row + 8;
      tallest_on_this_row = 0;
      cur_x = 8;
      ++i;
    }
    while ( i < this->m_RoomTemplateFolders.m_Size );
  }
  vgui::Panel::SetTall(this, tall: v8);
}

//------------------------------------------------------------------------------
// Address: 0x10029FA0
// Name: public: virtual struct vgui::PanelMessageMap __near * CRoomTemplateListPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CRoomTemplateListPanel::GetMessageMap(CRoomTemplateListPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CRoomTemplateListPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CRoomTemplateListPanel::GetMessageMap'::`2'::s_pMap;
  `CRoomTemplateListPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CRoomTemplateListPanel");
  `CRoomTemplateListPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10029FD0
// Name: public: virtual struct PanelAnimationMap __near * CRoomTemplateListPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CRoomTemplateListPanel::GetAnimMap(CRoomTemplateListPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CRoomTemplateListPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10029FE0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CRoomTemplateListPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CRoomTemplateListPanel::GetKBMap(CRoomTemplateListPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CRoomTemplateListPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CRoomTemplateListPanel::GetKBMap'::`2'::s_pMap;
  `CRoomTemplateListPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CRoomTemplateListPanel");
  `CRoomTemplateListPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1002A010
// Name: public: static void CRoomTemplateListPanel::PanelMessageFunc_OnRefreshList::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CRoomTemplateListPanel::PanelMessageFunc_OnRefreshList::InitVar(int a1@<ebp>)
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
  if ( !`CRoomTemplateListPanel::PanelMessageFunc_OnRefreshList::InitVar'::`2'::bAdded )
  {
    `CRoomTemplateListPanel::PanelMessageFunc_OnRefreshList::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{844,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CRoomTemplateListPanel");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "RefreshList";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A0A0
// Name: public: static void CRoomTemplateListPanel::PanelMessageFunc_OnExpandAll::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CRoomTemplateListPanel::PanelMessageFunc_OnExpandAll::InitVar(int a1@<ebp>)
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
  if ( !`CRoomTemplateListPanel::PanelMessageFunc_OnExpandAll::InitVar'::`2'::bAdded )
  {
    `CRoomTemplateListPanel::PanelMessageFunc_OnExpandAll::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CRoomTemplateListPanel::`vcall'{848,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CRoomTemplateListPanel");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "ExpandAllFolders";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A130
// Name: public: static void CRoomTemplateListPanel::PanelMessageFunc_OnCollapseAll::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CRoomTemplateListPanel::PanelMessageFunc_OnCollapseAll::InitVar(int a1@<ebp>)
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
  if ( !`CRoomTemplateListPanel::PanelMessageFunc_OnCollapseAll::InitVar'::`2'::bAdded )
  {
    `CRoomTemplateListPanel::PanelMessageFunc_OnCollapseAll::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall vgui::ProgressBar::`vcall'{852,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CRoomTemplateListPanel");
    v2 = (__int128)_mm_load_si128(&v5);
    memset(&v4.numParams, 0, 32);
    m_Size = v1->entries.m_Size;
    v4.name = "CollapseAllFolders";
    v4.func = v2;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: &v1->entries,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A1C0
// Name: public: static void CRoomTemplateListPanel::PanelMessageFunc_OnToggleFolder::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CRoomTemplateListPanel::PanelMessageFunc_OnToggleFolder::InitVar(int a1@<ebp>)
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
  if ( !`CRoomTemplateListPanel::PanelMessageFunc_OnToggleFolder::InitVar'::`2'::bAdded )
  {
    `CRoomTemplateListPanel::PanelMessageFunc_OnToggleFolder::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CRoomTemplateListPanel::`vcall'{856,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = vgui::FindOrAddPanelMessageMap(className: "CRoomTemplateListPanel");
    m_Size = v1->entries.m_Size;
    v3 = (__int128)_mm_load_si128(&v5);
    memset(&v4.firstParamName, 0, 24);
    v4.name = "ToggleFolder";
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
// Address: 0x1002A250
// Name: public: CRoomTemplateListPanel::CRoomTemplateListPanel(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CRoomTemplateListPanel *__thiscall CRoomTemplateListPanel::CRoomTemplateListPanel(
        CRoomTemplateListPanel *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi
  CRoomTemplateListPanel::RoomTemplateFolder_t *v7; // eax
  vgui::Button *v8; // eax
  vgui::Button *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // eax
  vgui::Button *v16; // eax
  vgui::Button *v17; // eax
  KeyValues *v18; // eax
  KeyValues *v19; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  vgui::Panel::Panel(this, parent, panelName: name);
  this->__vftable = (CRoomTemplateListPanel_vtbl *)&CRoomTemplateListPanel::`vftable';
  if ( `CRoomTemplateListPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CRoomTemplateListPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CRoomTemplateListPanel");
    v4->pfnClassName = CRoomTemplateListPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Panel");
  }
  if ( `CRoomTemplateListPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CRoomTemplateListPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CRoomTemplateListPanel");
    v5->pfnClassName = CRoomTemplateListPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Panel");
  }
  if ( `CRoomTemplateListPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CRoomTemplateListPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CRoomTemplateListPanel");
    v6->pfnClassName = CRoomTemplateListPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Panel");
  }
  CRoomTemplateListPanel::PanelMessageFunc_OnRefreshList::InitVar(a1: (int)&savedregs);
  CRoomTemplateListPanel::PanelMessageFunc_OnExpandAll::InitVar(a1: (int)&savedregs);
  CRoomTemplateListPanel::PanelMessageFunc_OnCollapseAll::InitVar(a1: (int)&savedregs);
  CRoomTemplateListPanel::PanelMessageFunc_OnToggleFolder::InitVar(a1: (int)&savedregs);
  this->m_Thumbnails.m_Memory.m_pMemory = nullptr;
  this->m_Thumbnails.m_Memory.m_nAllocationCount = 0;
  this->m_Thumbnails.m_Memory.m_nGrowSize = 0;
  this->m_Thumbnails.m_Size = 0;
  this->m_Thumbnails.m_pElements = nullptr;
  this->m_RoomTemplateFolders.m_Memory.m_pMemory = nullptr;
  this->m_RoomTemplateFolders.m_Memory.m_nAllocationCount = 20;
  this->m_RoomTemplateFolders.m_Memory.m_nGrowSize = 0;
  v7 = (CRoomTemplateListPanel::RoomTemplateFolder_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 5360);
  this->m_RoomTemplateFolders.m_Memory.m_pMemory = v7;
  this->m_RoomTemplateFolders.m_Size = 0;
  this->m_RoomTemplateFolders.m_pElements = v7;
  this->m_FilterText[0] = 0;
  v8 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v8 != nullptr )
    v9 = vgui::Button::Button(
           this: v8,
           parent: this,
           panelName: "RefreshListButton",
           text: "Refresh List",
           pActionSignalTarget: this,
           pCmd: "RefreshList");
  else
    v9 = nullptr;
  this->m_pRefreshList = v9;
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 != nullptr )
    v11 = KeyValues::KeyValues(this: v10, setName: "RefreshList");
  else
    v11 = nullptr;
  this->m_pRefreshList->SetCommand(this: this->m_pRefreshList, a2: v11);
  v12 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v12 != nullptr )
    v13 = vgui::Button::Button(
            this: v12,
            parent: this,
            panelName: "ExpandAllButton",
            text: "Expand All",
            pActionSignalTarget: this,
            pCmd: "ExpandAllFolders");
  else
    v13 = nullptr;
  this->m_pExpandAll = v13;
  v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v14 != nullptr )
    v15 = KeyValues::KeyValues(this: v14, setName: "ExpandAllFolders");
  else
    v15 = nullptr;
  this->m_pExpandAll->SetCommand(this: this->m_pExpandAll, a2: v15);
  v16 = (vgui::Button *)operator new(nSize: 0x1F4u);
  if ( v16 != nullptr )
    v17 = vgui::Button::Button(
            this: v16,
            parent: this,
            panelName: "CollapseAllButton",
            text: "Collapse All",
            pActionSignalTarget: this,
            pCmd: "CollapseAllFolders");
  else
    v17 = nullptr;
  this->m_pCollapseAll = v17;
  v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v18 != nullptr )
    v19 = KeyValues::KeyValues(this: v18, setName: "CollapseAllFolders");
  else
    v19 = nullptr;
  this->m_pCollapseAll->SetCommand(this: this->m_pCollapseAll, a2: v19);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1002A4F0
// Name: private: void CRoomTemplateListPanel::AddFolder(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplateListPanel::AddFolder(CRoomTemplateListPanel *this, KeyValues *pFolderName)
{
  int v3; // esi
  int v4; // edi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlVector<CRoomTemplateListPanel::RoomTemplateFolder_t,CUtlMemory<CRoomTemplateListPanel::RoomTemplateFolder_t,int> > *p_m_RoomTemplateFolders; // esi
  CRoomTemplateListPanel::RoomTemplateFolder_t *m_pMemory; // ecx
  int v9; // eax
  int v10; // edi
  vgui::Button *v11; // eax
  vgui::Button *v12; // eax
  vgui::Button *m_pFolderButton; // ecx
  KeyValues *v14; // eax
  KeyValues *v15; // ebx
  KeyValues *v16; // eax
  int nNumFolders; // [esp+Ch] [ebp-4h]
  KeyValues *pMessageKV; // [esp+18h] [ebp+8h]

  v3 = 0;
  nNumFolders = this->m_RoomTemplateFolders.m_Size;
  if ( nNumFolders <= 0 )
  {
LABEL_5:
    m_Size = this->m_RoomTemplateFolders.m_Size;
    m_nAllocationCount = this->m_RoomTemplateFolders.m_Memory.m_nAllocationCount;
    p_m_RoomTemplateFolders = &this->m_RoomTemplateFolders;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CRoomTemplateListPanel::RoomTemplateFolder_t,int>::Grow(
        this: (CUtlMemory<GDIVITEM,int> *)&this->m_RoomTemplateFolders,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_RoomTemplateFolders.m_Size;
    m_pMemory = p_m_RoomTemplateFolders->m_Memory.m_pMemory;
    v9 = this->m_RoomTemplateFolders.m_Size - m_Size - 1;
    this->m_RoomTemplateFolders.m_pElements = this->m_RoomTemplateFolders.m_Memory.m_pMemory;
    if ( v9 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 268 * v9);
    v10 = nNumFolders;
    V_strncpy(
      pDest: p_m_RoomTemplateFolders->m_Memory.m_pMemory[nNumFolders].m_FolderName,
      pSrc: (const char *)pFolderName,
      maxLen: 260);
    p_m_RoomTemplateFolders->m_Memory.m_pMemory[nNumFolders].m_bExpanded = true;
    v11 = (vgui::Button *)operator new(nSize: 0x1F4u);
    if ( v11 != nullptr )
      v12 = vgui::Button::Button(
              this: v11,
              parent: this,
              panelName: "FolderButton",
              text: szDescription,
              pActionSignalTarget: this,
              pCmd: "ToggleFolder");
    else
      v12 = nullptr;
    p_m_RoomTemplateFolders->m_Memory.m_pMemory[v10].m_pFolderButton = v12;
    v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v15 = nullptr;
    if ( v14 != nullptr )
      pMessageKV = KeyValues::KeyValues(this: v14, setName: "ToggleFolder");
    else
      pMessageKV = nullptr;
    v16 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v16 != nullptr )
      v15 = KeyValues::KeyValues(this: v16, setName: "folder");
    KeyValues::SetString(
      this: v15,
      keyName: nullptr,
      value: p_m_RoomTemplateFolders->m_Memory.m_pMemory[v10].m_FolderName);
    KeyValues::AddSubKey(this: pMessageKV, pSubkey: v15);
    p_m_RoomTemplateFolders->m_Memory.m_pMemory[v10].m_pFolderButton->SetCommand(
      this: p_m_RoomTemplateFolders->m_Memory.m_pMemory[v10].m_pFolderButton,
      a2: pMessageKV);
  }
  else
  {
    v4 = 0;
    while ( _V_stricmp(
              s1: (const char *)pFolderName,
              s2: this->m_RoomTemplateFolders.m_Memory.m_pMemory[v4].m_FolderName) != 0 )
    {
      ++v3;
      ++v4;
      if ( v3 >= nNumFolders )
        goto LABEL_5;
    }
    m_pFolderButton = this->m_RoomTemplateFolders.m_Memory.m_pMemory[v3].m_pFolderButton;
    m_pFolderButton->SetVisible(this: m_pFolderButton, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A690
// Name: public: void CRoomTemplateListPanel::UpdateRoomList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplateListPanel::UpdateRoomList(CRoomTemplateListPanel *this)
{
  int j; // esi
  CRoomTemplatePanel *v3; // ecx
  int v4; // edi
  vgui::Button *v5; // ecx
  CLevelTheme *v6; // edi
  CRoomTemplatePanel *v7; // eax
  CRoomTemplatePanel *v8; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CRoomTemplatePanel **m_pMemory; // ecx
  int v12; // eax
  CRoomTemplatePanel **v13; // edi
  int v14; // esi
  int v15; // edi
  int v16; // ecx
  int v17; // ecx
  int v18; // eax
  CLevelTheme *pCurrentTheme; // [esp+Ch] [ebp-Ch]
  CLevelTheme *pCurrentThemea; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  int ia; // [esp+10h] [ebp-8h]
  CRoomTemplatePanel *pPanel; // [esp+14h] [ebp-4h]
  CRoomTemplatePanel *pPanela; // [esp+14h] [ebp-4h]

  for ( j = 0; j < this->m_Thumbnails.m_Size; ++j )
  {
    v3 = this->m_Thumbnails.m_Memory.m_pMemory[j];
    v3->MarkForDeletion(this: v3);
  }
  v4 = 0;
  this->m_Thumbnails.m_Size = 0;
  if ( this->m_RoomTemplateFolders.m_Size > 0 )
  {
    pPanel = nullptr;
    do
    {
      v5 = *(vgui::Button **)((char *)&this->m_RoomTemplateFolders.m_Memory.m_pMemory->m_pFolderButton
                            + (unsigned int)pPanel);
      v5->SetVisible(this: v5, a2: false);
      pPanel = (CRoomTemplatePanel *)((char *)pPanel + 268);
      ++v4;
    }
    while ( v4 < this->m_RoomTemplateFolders.m_Size );
  }
  v6 = CLevelTheme::s_pCurrentTheme;
  pCurrentTheme = CLevelTheme::s_pCurrentTheme;
  if ( CLevelTheme::s_pCurrentTheme != nullptr )
  {
    i = 0;
    if ( CLevelTheme::s_pCurrentTheme->m_RoomTemplates.m_Size > 0 )
    {
      while ( 1 )
      {
        v7 = (CRoomTemplatePanel *)operator new(nSize: 0x19Cu);
        if ( v7 != nullptr )
        {
          v8 = CRoomTemplatePanel::CRoomTemplatePanel(this: v7, parent: this, name: "RoomTemplatePanel");
          pPanela = v8;
        }
        else
        {
          pPanela = nullptr;
          v8 = nullptr;
        }
        v8->m_bRoomTemplateBrowserMode = true;
        CRoomTemplatePanel::SetRoomTemplate(this: v8, pTemplate: v6->m_RoomTemplates.m_Memory.m_pMemory[i]);
        m_Size = this->m_Thumbnails.m_Size;
        m_nAllocationCount = this->m_Thumbnails.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Thumbnails,
            num: m_Size - m_nAllocationCount + 1);
        ++this->m_Thumbnails.m_Size;
        m_pMemory = this->m_Thumbnails.m_Memory.m_pMemory;
        v12 = this->m_Thumbnails.m_Size - m_Size - 1;
        this->m_Thumbnails.m_pElements = m_pMemory;
        if ( v12 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
        v13 = &this->m_Thumbnails.m_Memory.m_pMemory[m_Size];
        if ( v13 != nullptr )
          *v13 = pPanela;
        CRoomTemplateListPanel::AddFolder(
          this,
          pFolderName: (KeyValues *)pCurrentTheme->m_RoomTemplates.m_Memory.m_pMemory[i++]->m_SubFolder);
        if ( i >= pCurrentTheme->m_RoomTemplates.m_Size )
          break;
        v6 = pCurrentTheme;
      }
    }
    v14 = 0;
    pCurrentThemea = nullptr;
    if ( this->m_RoomTemplateFolders.m_Size > 0 )
    {
      v15 = 0;
      ia = 0;
      do
      {
        v16 = *(int *)((char *)&this->m_RoomTemplateFolders.m_Memory.m_pMemory->m_pFolderButton + v15);
        if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v16 + 136))(a1: v16) == 0 )
        {
          v17 = *(int *)((char *)&this->m_RoomTemplateFolders.m_Memory.m_pMemory->m_pFolderButton + v15);
          (*(void (__thiscall **)(int))(*(_DWORD *)v17 + 320))(a1: v17);
          v18 = this->m_RoomTemplateFolders.m_Size;
          if ( v18 > 0 )
          {
            if ( v14 != v18 - 1 )
            {
              qmemcpy(
                &this->m_RoomTemplateFolders.m_Memory.m_pMemory->m_FolderName[v15],
                &this->m_RoomTemplateFolders.m_Memory.m_pMemory[v18 - 1],
                0x10Cu);
              v15 = ia;
              v14 = (int)pCurrentThemea;
            }
            --this->m_RoomTemplateFolders.m_Size;
          }
          --v14;
          v15 -= 268;
        }
        ++v14;
        v15 += 268;
        pCurrentThemea = (CLevelTheme *)v14;
        ia = v15;
      }
      while ( v14 < this->m_RoomTemplateFolders.m_Size );
    }
    CUtlVector<CRoomTemplateListPanel::RoomTemplateFolder_t,CUtlMemory<CRoomTemplateListPanel::RoomTemplateFolder_t,int>>::Sort(
      this: &this->m_RoomTemplateFolders,
      pfnCompare: (int (__cdecl *)(const CRoomTemplateListPanel::RoomTemplateFolder_t *, const CRoomTemplateListPanel::RoomTemplateFolder_t *))CRoomTemplateListPanel::CompareFolders);
    this->InvalidateLayout(this, a2: false, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002A8F0
// Name: public: virtual void CRoomTemplateListPanel::OnRefreshList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRoomTemplateListPanel::OnRefreshList(CRoomTemplateListPanel *this)
{
  CLevelTheme *v1; // esi

  v1 = CLevelTheme::s_pCurrentTheme;
  if ( CLevelTheme::s_pCurrentTheme != nullptr )
  {
    CMissionChooserTGAImagePanel::ClearImageCache();
    CLevelTheme::LoadRoomTemplates(this: v1);
    CRoomTemplateListPanel::UpdateRoomList(this);
  }
}
