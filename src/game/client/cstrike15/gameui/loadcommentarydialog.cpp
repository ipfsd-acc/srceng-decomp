// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/cstrike15/gameui/loadcommentarydialog.cpp
// Functions: 25
// ============================================================

#include "game\client\cstrike15\gameui\loadcommentarydialog.h"

//------------------------------------------------------------------------------
// Address: 0x101D1100
// Name: public: virtual void CCommentaryItemPanel::OnMousePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentaryItemPanel::OnMousePressed(CSaveGamePanel *this, ButtonCode_t code)
{
  vgui::PanelListPanel::SetSelectedPanel(this: this->m_pParent, panel: this);
}

//------------------------------------------------------------------------------
// Address: 0x101EFE00
// Name: public: static char const __near * CLoadCommentaryDialog::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CLoadCommentaryDialog::GetPanelClassName()
{
  return "CLoadCommentaryDialog";
}

//------------------------------------------------------------------------------
// Address: 0x101EFE10
// Name: public: static char const __near * CCommentaryItemPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CCommentaryItemPanel::GetPanelClassName()
{
  return "CCommentaryItemPanel";
}

//------------------------------------------------------------------------------
// Address: 0x101EFE20
// Name: public: void CCommentaryItemPanel::SetCommentaryInfo(struct CommentaryItem_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentaryItemPanel::SetCommentaryInfo(CCommentaryItemPanel *this, CommentaryItem_t *item)
{
  char *v3; // eax
  char tga[260]; // [esp+8h] [ebp-104h] BYREF

  V_strncpy(pDest: tga, pSrc: item->szMapFileName, maxLen: 260);
  strstr(str1: (unsigned __int8 *)tga, str2: ".txt");
  if ( v3 != nullptr )
    strcpy(v3, ".tga");
  CTGAImagePanel::SetTGAFilename(this: this->m_pCommentaryScreenshot, filename: tga);
  this->m_pMapNameLabel->SetText(this: this->m_pMapNameLabel, a2: item->szPrintName);
  this->m_pDescriptionLabel->SetText(this: this->m_pDescriptionLabel, a2: item->szDescription);
}

//------------------------------------------------------------------------------
// Address: 0x101EFEC0
// Name: protected: static int CLoadCommentaryDialog::SaveGameSortFunc(void const __near *,void const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CLoadCommentaryDialog::SaveGameSortFunc(const char *lhs, const char *rhs)
{
  return _V_stricmp(s1: lhs + 292, s2: rhs + 292);
}

//------------------------------------------------------------------------------
// Address: 0x101EFEE0
// Name: private: virtual void CLoadCommentaryDialog::OnPanelSelected(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoadCommentaryDialog::OnPanelSelected(CLoadCommentaryDialog *this)
{
  this->SetControlEnabled(this, a2: "loadcommentary", a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x101EFF00
// Name: protected: int CLoadCommentaryDialog::GetSelectedItemIndex(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLoadCommentaryDialog::GetSelectedItemIndex(CLoadCommentaryDialog *this)
{
  vgui::Panel *SelectedPanel; // eax
  _DWORD *v3; // edx
  int m_Size; // ecx
  int result; // eax
  int v6; // edx

  SelectedPanel = vgui::PanelListPanel::GetSelectedPanel(this: this->m_pGameList);
  v3 = __RTDynamicCast(
         inptr: SelectedPanel,
         VfDelta: 0,
         SrcType: &vgui::Panel `RTTI Type Descriptor',
         TargetType: &CCommentaryItemPanel `RTTI Type Descriptor',
         isReference: 0);
  if ( v3 == nullptr )
    return -1;
  m_Size = this->m_CommentaryItems.m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  v6 = v3[104];
  while ( result != v6 )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F0000
// Name: protected: virtual void CLoadCommentaryDialog::OnCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoadCommentaryDialog::OnCommand(CLoadCommentaryDialog *this, const char *command)
{
  int SelectedItemIndex; // eax
  char *szMapName; // eax
  char sz[256]; // [esp+8h] [ebp-100h] BYREF

  if ( _V_stricmp(s1: command, s2: "loadcommentary") != 0 )
  {
    vgui::Frame::OnCommand(this, command);
  }
  else
  {
    SelectedItemIndex = CLoadCommentaryDialog::GetSelectedItemIndex(this);
    if ( SelectedItemIndex >= 0 && SelectedItemIndex < this->m_CommentaryItems.m_Size )
    {
      szMapName = this->m_CommentaryItems.m_Memory.m_pMemory[SelectedItemIndex].szMapName;
      if ( szMapName != nullptr && *szMapName != 0 )
      {
        V_snprintf(pDest: sz, maxLen: 0x100u, pFormat: "progress_enable\ncommentary 1\nmap %s\n", szMapName);
        this->OnClose(this);
        engine->ClientCmd_Unrestricted(this: engine, a2: sz);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F0130
// Name: public: static void CLoadCommentaryDialog::PanelMessageFunc_OnPanelSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CLoadCommentaryDialog::PanelMessageFunc_OnPanelSelected::InitVar(int a1@<ebp>)
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
  if ( !`CLoadCommentaryDialog::PanelMessageFunc_OnPanelSelected::InitVar'::`2'::bAdded )
  {
    `CLoadCommentaryDialog::PanelMessageFunc_OnPanelSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CBonusMapsDialog::`vcall'{1116,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CLoadCommentaryDialog");
    v2 = _mm_load_si128(&v5);
    memset(v4.m[2], 0, 32);
    m_Size = v1->m_Size;
    LODWORD(v4.m[0][0]) = "PanelSelected";
    *(__m128i *)&v4.m[1][0] = v2;
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F01C0
// Name: public: static void CCommentaryItemPanel::PanelMessageFunc_OnPanelSelected::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CCommentaryItemPanel::PanelMessageFunc_OnPanelSelected::InitVar(int a1@<ebp>)
{
  CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *v1; // eax
  int m_Size; // edx
  __m128i v3; // xmm0
  VMatrix v4; // [esp-50h] [ebp-5Ch] BYREF
  __m128i v5; // [esp-10h] [ebp-1Ch] BYREF
  int v6; // [esp+0h] [ebp-Ch]
  void *v7; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v6 = a1;
  v7 = retaddr;
  if ( !`CCommentaryItemPanel::PanelMessageFunc_OnPanelSelected::InitVar'::`2'::bAdded )
  {
    `CCommentaryItemPanel::PanelMessageFunc_OnPanelSelected::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CSaveGamePanel::`vcall'{944,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CCommentaryItemPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "PanelSelected";
    *(__m128i *)&v4.m[1][0] = v3;
    *(_QWORD *)&v4.m[2][0] = 0x200000001LL;
    LODWORD(v4.m[2][2]) = "state";
    CUtlVector<randomsound_t,CUtlMemory<randomsound_t,int>>::InsertBefore(this: v1, elem: m_Size, src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F0260
// Name: protected: void CLoadCommentaryDialog::ParseCommentaryFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoadCommentaryDialog::ParseCommentaryFile(
        CLoadCommentaryDialog *this,
        char *pszFileName,
        const char *pszShortName)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IBaseFileSystem *v6; // eax
  KeyValues *Key; // eax
  KeyValues *i; // esi
  char *String; // eax
  char *v10; // eax
  char *v11; // eax
  _BYTE *v12; // eax
  CommentaryItem_t item; // [esp+8h] [ebp-448h] BYREF
  char mapname[260]; // [esp+34Ch] [ebp-104h] BYREF

  if ( pszFileName != nullptr && pszShortName != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "commentary_data");
    else
      v5 = nullptr;
    if ( g_pFullFileSystem != nullptr )
      v6 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v6 = nullptr;
    if ( KeyValues::LoadFromFile(
           this: v5,
           filesystem: v6,
           resourceName: pszFileName,
           pathID: "MOD",
           pfnEvaluateSymbolProc: nullptr) )
    {
      Key = KeyValues::FindKey(this: v5, keyName: "trackinfo", bCreate: false);
      if ( Key != nullptr )
      {
        for ( i = KeyValues::GetFirstSubKey(this: Key); i != nullptr; i = KeyValues::GetNextKey(this: i) )
        {
          V_strncpy(pDest: item.szMapFileName, pSrc: pszFileName, maxLen: 260);
          String = KeyValues::GetString(this: i, keyName: "map", defaultValue: prType);
          V_strncpy(pDest: item.szMapName, pSrc: String, maxLen: 32);
          v10 = KeyValues::GetString(this: i, keyName: "printname", defaultValue: prType);
          V_strncpy(pDest: item.szPrintName, pSrc: v10, maxLen: 32);
          v11 = KeyValues::GetString(this: i, keyName: "description", defaultValue: prType);
          V_strncpy(pDest: item.szDescription, pSrc: v11, maxLen: 512);
          CUtlVector<CommentaryItem_t,CUtlMemory<CommentaryItem_t,int>>::InsertBefore(
            this: &this->m_CommentaryItems,
            elem: this->m_CommentaryItems.m_Size,
            src: &item);
        }
      }
      else
      {
        V_strncpy(pDest: item.szMapFileName, pSrc: pszFileName, maxLen: 260);
        V_strncpy(pDest: mapname, pSrc: pszFileName, maxLen: 32);
        strstr(str1: (unsigned __int8 *)mapname, str2: "_commentary");
        *v12 = 0;
        V_FileBase(in: mapname, out: item.szMapName, maxlen: 32);
        V_strncpy(pDest: item.szPrintName, pSrc: "No trackinfo found.", maxLen: 32);
        V_strncpy(pDest: item.szDescription, pSrc: "No trackinfo found.", maxLen: 512);
        CUtlVector<CommentaryItem_t,CUtlMemory<CommentaryItem_t,int>>::InsertBefore(
          this: &this->m_CommentaryItems,
          elem: this->m_CommentaryItems.m_Size,
          src: &item);
      }
    }
    else
    {
      KeyValues::deleteThis(this: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F0450
// Name: public: CCommentaryItemPanel::CCommentaryItemPanel(class vgui::PanelListPanel __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CCommentaryItemPanel *__thiscall CCommentaryItemPanel::CCommentaryItemPanel(
        CCommentaryItemPanel *this,
        vgui::PanelListPanel *parent,
        const char *name,
        int iListItemID)
{
  vgui::PanelMessageMap *v5; // edi
  PanelAnimationMap *v6; // edi
  vgui::PanelKeyBindingMap *v7; // edi
  int v8; // edx
  vgui::PanelListPanel *v9; // eax
  CTGAImagePanel *v10; // eax
  CTGAImagePanel *v11; // eax
  vgui::ImagePanel *v12; // eax
  vgui::ImagePanel *v13; // eax
  vgui::Label *v14; // eax
  vgui::Label *v15; // eax
  vgui::Label *v16; // eax
  vgui::Label *v17; // eax
  CMouseMessageForwardingPanel *v18; // eax
  CMouseMessageForwardingPanel *v19; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::EditablePanel::EditablePanel(this, parent, panelName: name);
  this->__vftable = (CCommentaryItemPanel_vtbl *)&CCommentaryItemPanel::`vftable';
  if ( `CCommentaryItemPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CCommentaryItemPanel::ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelMessageMap(className: "CCommentaryItemPanel");
    v5->pfnClassName = CCommentaryItemPanel::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CCommentaryItemPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CCommentaryItemPanel::ChainToAnimationMap'::`2'::chained = 1;
    v6 = FindOrAddPanelAnimationMap(className: "CCommentaryItemPanel");
    v6->pfnClassName = CCommentaryItemPanel::GetPanelClassName;
    v6->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CCommentaryItemPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CCommentaryItemPanel::KB_ChainToMap'::`2'::chained = 1;
    v7 = vgui::FindOrAddPanelKeyBindingMap(className: "CCommentaryItemPanel");
    v7->pfnClassName = CCommentaryItemPanel::GetPanelClassName;
    v7->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  CCommentaryItemPanel::PanelMessageFunc_OnPanelSelected::InitVar(a1: (int)&savedregs);
  v8 = iListItemID;
  v9 = parent;
  this->m_TextColor = 0;
  this->m_FillColor = 0;
  this->m_SelectedColor = 0;
  this->m_iListItemID = v8;
  this->m_pParent = v9;
  v10 = (CTGAImagePanel *)MemAlloc_Alloc(nSize: 0x184u);
  if ( v10 != nullptr )
    v11 = CTGAImagePanel::CTGAImagePanel(this: v10, parent: this, name: "CommentaryMapScreenshot");
  else
    v11 = nullptr;
  this->m_pCommentaryScreenshot = v11;
  v12 = (vgui::ImagePanel *)MemAlloc_Alloc(nSize: 0x17Cu);
  if ( v12 != nullptr )
    v13 = vgui::ImagePanel::ImagePanel(this: v12, parent: this, name: "CommentaryScreenshotBackground");
  else
    v13 = nullptr;
  this->m_pCommentaryScreenshotBackground = v13;
  v14 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v14 != nullptr )
    v15 = vgui::Label::Label(this: v14, parent: this, panelName: "MapName", text: prType);
  else
    v15 = nullptr;
  this->m_pMapNameLabel = v15;
  v16 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
  if ( v16 != nullptr )
    v17 = vgui::Label::Label(this: v16, parent: this, panelName: "Description", text: prType);
  else
    v17 = nullptr;
  this->m_pDescriptionLabel = v17;
  v18 = (CMouseMessageForwardingPanel *)MemAlloc_Alloc(nSize: 0x150u);
  if ( v18 != nullptr )
    v19 = CMouseMessageForwardingPanel::CMouseMessageForwardingPanel(this: v18, parent: this, name: nullptr);
  else
    v19 = nullptr;
  vgui::Panel::SetZPos(this: v19, z: 2);
  vgui::Panel::SetSize(this, wide: 200, tall: 140);
  vgui::EditablePanel::LoadControlSettings(
    this,
    resourceName: "resource/CommentaryItem.res",
    pathID: nullptr,
    pKeyValues: nullptr,
    pConditions: nullptr);
  this->m_FillColor = *vgui::ImagePanel::GetFillColor(
                         this: this->m_pCommentaryScreenshotBackground,
                         result: (Color *)&parent);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F0640
// Name: public: virtual void CCommentaryItemPanel::OnPanelSelected(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentaryItemPanel::OnPanelSelected(CCommentaryItemPanel *this, int state)
{
  Color m_SelectedColor; // edx
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  CCommentaryItemPanel_vtbl *v6; // edi
  int v7; // eax

  if ( state != 0 )
  {
    vgui::ProgressBar::SetBarInset(
      this: (vgui::ProgressBar *)this->m_pCommentaryScreenshotBackground,
      pixels: *(_DWORD *)&this->m_SelectedColor);
    ((void (__thiscall *)(vgui::Label *, _DWORD))this->m_pMapNameLabel->SetFgColor)(
      a1: this->m_pMapNameLabel,
      a2: *(_DWORD *)&this->m_SelectedColor);
    m_SelectedColor = this->m_SelectedColor;
  }
  else
  {
    vgui::ProgressBar::SetBarInset(
      this: (vgui::ProgressBar *)this->m_pCommentaryScreenshotBackground,
      pixels: *(_DWORD *)&this->m_FillColor);
    ((void (__thiscall *)(vgui::Label *, _DWORD))this->m_pMapNameLabel->SetFgColor)(
      a1: this->m_pMapNameLabel,
      a2: *(_DWORD *)&this->m_TextColor);
    m_SelectedColor = this->m_TextColor;
  }
  ((void (__thiscall *)(_DWORD, _DWORD))this->m_pDescriptionLabel->SetFgColor)(
    a1: this->m_pDescriptionLabel,
    a2: m_SelectedColor);
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "PanelSelected");
  else
    v5 = nullptr;
  v6 = this->__vftable;
  v7 = ((int (__thiscall *)(vgui::PanelListPanel *, KeyValues *, _DWORD))this->m_pParent->GetVParent)(
         a1: this->m_pParent,
         a2: v5,
         a3: 0);
  ((void (__thiscall *)(CCommentaryItemPanel *, int))v6->PostMessage_2)(a1: this, a2: v7);
}

//------------------------------------------------------------------------------
// Address: 0x101F0710
// Name: public: virtual void CCommentaryItemPanel::OnMouseDoublePressed(enum ButtonCode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentaryItemPanel::OnMouseDoublePressed(CCommentaryItemPanel *this, ButtonCode_t code)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  CCommentaryItemPanel_vtbl *v5; // edi
  int v6; // eax

  this->OnMousePressed(this, a2: code);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "Command", firstKey: "command", firstValue: "loadcommentary");
  else
    v4 = nullptr;
  v5 = this->__vftable;
  v6 = ((int (__thiscall *)(vgui::PanelListPanel *, KeyValues *, _DWORD))this->m_pParent->GetParent)(
         a1: this->m_pParent,
         a2: v4,
         a3: 0);
  ((void (__thiscall *)(CCommentaryItemPanel *, int))v5->PostMessage)(a1: this, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x101F0780
// Name: public: virtual struct vgui::PanelMessageMap __near * CCommentaryItemPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CCommentaryItemPanel::GetMessageMap(CCommentaryItemPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CCommentaryItemPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CCommentaryItemPanel::GetMessageMap'::`2'::s_pMap;
  `CCommentaryItemPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CCommentaryItemPanel");
  `CCommentaryItemPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F07B0
// Name: public: virtual struct PanelAnimationMap __near * CCommentaryItemPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CCommentaryItemPanel::GetAnimMap(CCommentaryItemPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CCommentaryItemPanel");
}

//------------------------------------------------------------------------------
// Address: 0x101F07C0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CCommentaryItemPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CCommentaryItemPanel::GetKBMap(CCommentaryItemPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CCommentaryItemPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CCommentaryItemPanel::GetKBMap'::`2'::s_pMap;
  `CCommentaryItemPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CCommentaryItemPanel");
  `CCommentaryItemPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F07F0
// Name: public: virtual void CCommentaryItemPanel::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCommentaryItemPanel::ApplySchemeSettings(CCommentaryItemPanel *this, int pScheme)
{
  vgui::IScheme *v2; // esi
  Color v4; // ecx

  v2 = (vgui::IScheme *)pScheme;
  v4 = *(Color *)(*(int (__thiscall **)(int, int *, const char *, int))(*(_DWORD *)pScheme + 20))(
                   a1: pScheme,
                   a2: &pScheme,
                   a3: "NewGame.TextColor",
                   a4: -1);
  pScheme = -1;
  this->m_TextColor = v4;
  this->m_SelectedColor = *(Color *)((int (__thiscall *)(vgui::IScheme *, int *, const char *, int))v2->GetColor)(
                                      a1: v2,
                                      a2: &pScheme,
                                      a3: "NewGame.SelectionColor",
                                      a4: -1);
  vgui::Panel::ApplySchemeSettings(this, pScheme: (int)v2);
}

//------------------------------------------------------------------------------
// Address: 0x101F0860
// Name: protected: void CLoadCommentaryDialog::ScanCommentaryFiles(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CLoadCommentaryDialog::ScanCommentaryFiles(CLoadCommentaryDialog *this)
{
  int v2; // ebx
  const char *i; // edi
  CCommentaryItemPanel *v4; // eax
  CCommentaryItemPanel *v5; // edi
  vgui::Label *v6; // eax
  vgui::Label *v7; // edi
  char szDirectory[260]; // [esp+Ch] [ebp-210h] BYREF
  char szFileName[260]; // [esp+110h] [ebp-10Ch] BYREF
  int handle; // [esp+214h] [ebp-8h] BYREF
  int v11; // [esp+218h] [ebp-4h]

  V_snprintf(pDest: szDirectory, maxLen: 0x104u, pFormat: "maps/*commentary.txt");
  this->m_pGameList->DeleteAllItems(this: this->m_pGameList);
  v2 = 0;
  this->m_CommentaryItems.m_Size = 0;
  for ( i = g_pFullFileSystem->FindFirst(this: g_pFullFileSystem, a2: szDirectory, a3: &handle);
        i != nullptr;
        i = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: handle) )
  {
    V_snprintf(pDest: szFileName, maxLen: 0x104u, pFormat: "maps/%s", i);
    if ( g_pFullFileSystem->FileExists(this: &g_pFullFileSystem->IBaseFileSystem, a2: szFileName, a3: "MOD") )
      CLoadCommentaryDialog::ParseCommentaryFile(this, pszFileName: szFileName, pszShortName: i);
  }
  g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: handle);
  qsort(
    base: this->m_CommentaryItems.m_Memory.m_pMemory,
    num: this->m_CommentaryItems.m_Size,
    width: 0x344u,
    comp: (int (__cdecl *)(const void *, const void *))CLoadCommentaryDialog::SaveGameSortFunc);
  if ( this->m_CommentaryItems.m_Size > 0 )
  {
    v11 = 0;
    do
    {
      if ( v11 >= 26752 )
        break;
      v4 = (CCommentaryItemPanel *)MemAlloc_Alloc(nSize: 0x1A4u);
      v5 = v4 != nullptr
         ? CCommentaryItemPanel::CCommentaryItemPanel(
             this: v4,
             parent: this->m_pGameList,
             name: "CommentaryItemPanel",
             iListItemID: v2)
         : nullptr;
      CCommentaryItemPanel::SetCommentaryInfo(this: v5, item: &this->m_CommentaryItems.m_Memory.m_pMemory[v11 / 0x344u]);
      this->m_pGameList->AddItem(this: this->m_pGameList, a2: nullptr, a3: v5);
      v11 += 836;
      ++v2;
    }
    while ( v2 < this->m_CommentaryItems.m_Size );
  }
  if ( this->m_CommentaryItems.m_Size == 0 )
  {
    v6 = (vgui::Label *)MemAlloc_Alloc(nSize: 0x1A4u);
    if ( v6 != nullptr )
      v7 = vgui::Label::Label(
             this: v6,
             parent: this->m_pGameList,
             panelName: "NoCommentaryItemsLabel",
             text: "#GameUI_NoCommentaryItemsToDisplay");
    else
      v7 = nullptr;
    vgui::Panel::MakeReadyForUse(this: v7);
    v7->SetTextColorState(this: v7, a2: CS_DULL);
    this->m_pGameList->AddItem(this: this->m_pGameList, a2: nullptr, a3: v7);
  }
  this->SetControlEnabled(this, a2: "loadcommentary", a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x101F0A60
// Name: public: CLoadCommentaryDialog::CLoadCommentaryDialog(class vgui::Panel __near *)
// Source: json
//------------------------------------------------------------------------------
CLoadCommentaryDialog *__thiscall CLoadCommentaryDialog::CLoadCommentaryDialog(
        CLoadCommentaryDialog *this,
        vgui::Panel *parent)
{
  vgui::PanelMessageMap *v3; // edi
  PanelAnimationMap *v4; // edi
  vgui::PanelKeyBindingMap *v5; // edi
  vgui::Button *v6; // eax
  vgui::Button *v7; // eax
  vgui::PanelListPanel *v8; // eax
  vgui::PanelListPanel *v9; // eax
  vgui::Button *v10; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  vgui::Frame::Frame(this, parent, panelName: "LoadCommentaryDialog", showTaskbarIcon: 1, bPopup: true);
  this->__vftable = (CLoadCommentaryDialog_vtbl *)&CLoadCommentaryDialog::`vftable';
  if ( `CLoadCommentaryDialog::ChainToMap'::`2'::chained == 0 )
  {
    `CLoadCommentaryDialog::ChainToMap'::`2'::chained = 1;
    v3 = vgui::FindOrAddPanelMessageMap(className: "CLoadCommentaryDialog");
    v3->pfnClassName = CLoadCommentaryDialog::GetPanelClassName;
    v3->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::Frame");
  }
  if ( `CLoadCommentaryDialog::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CLoadCommentaryDialog::ChainToAnimationMap'::`2'::chained = 1;
    v4 = FindOrAddPanelAnimationMap(className: "CLoadCommentaryDialog");
    v4->pfnClassName = CLoadCommentaryDialog::GetPanelClassName;
    v4->baseMap = FindOrAddPanelAnimationMap(className: "vgui::Frame");
  }
  if ( `CLoadCommentaryDialog::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CLoadCommentaryDialog::KB_ChainToMap'::`2'::chained = 1;
    v5 = vgui::FindOrAddPanelKeyBindingMap(className: "CLoadCommentaryDialog");
    v5->pfnClassName = CLoadCommentaryDialog::GetPanelClassName;
    v5->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::Frame");
  }
  this->m_CommentaryItems.m_Memory.m_pMemory = nullptr;
  this->m_CommentaryItems.m_Memory.m_nAllocationCount = 0;
  this->m_CommentaryItems.m_Memory.m_nGrowSize = 0;
  this->m_CommentaryItems.m_Size = 0;
  this->m_CommentaryItems.m_pElements = nullptr;
  CLoadCommentaryDialog::PanelMessageFunc_OnPanelSelected::InitVar(a1: (int)&savedregs);
  vgui::Frame::SetDeleteSelfOnClose(this, state: true);
  vgui::Panel::SetBounds(this, x: 0, y: 0, wide: 512, tall: 384);
  vgui::Panel::SetMinimumSize(this, wide: 256, tall: 300);
  vgui::Frame::SetSizeable(this, state: true);
  vgui::Frame::SetTitle(this, title: "#GameUI_LoadCommentary", surfaceTitle: true);
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
  v8 = (vgui::PanelListPanel *)MemAlloc_Alloc(nSize: 0x1ACu);
  if ( v8 != nullptr )
    v9 = vgui::PanelListPanel::PanelListPanel(this: v8, parent: this, panelName: "listpanel_commentary");
  else
    v9 = nullptr;
  this->m_pGameList = v9;
  vgui::PanelListPanel::SetFirstColumnWidth(this: v9, width: 0);
  v10 = (vgui::Button *)MemAlloc_Alloc(nSize: 0x1F4u);
  if ( v10 != nullptr )
    vgui::Button::Button(
      this: v10,
      parent: this,
      panelName: "loadcommentary",
      text: prType,
      pActionSignalTarget: nullptr,
      pCmd: nullptr);
  vgui::EditablePanel::SetControlEnabled(this, controlName: "loadcommentary", enabled: false);
  vgui::Frame::LoadControlSettings(
    this,
    dialogResourceName: "resource/LoadCommentaryDialog.res",
    pathID: nullptr,
    pPreloadedKeyValues: nullptr,
    pConditions: nullptr);
  CLoadCommentaryDialog::ScanCommentaryFiles(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F0C40
// Name: public: virtual struct vgui::PanelMessageMap __near * CLoadCommentaryDialog::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CLoadCommentaryDialog::GetMessageMap(CLoadCommentaryDialog *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CLoadCommentaryDialog::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CLoadCommentaryDialog::GetMessageMap'::`2'::s_pMap;
  `CLoadCommentaryDialog::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CLoadCommentaryDialog");
  `CLoadCommentaryDialog::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F0C70
// Name: public: virtual struct PanelAnimationMap __near * CLoadCommentaryDialog::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CLoadCommentaryDialog::GetAnimMap(CLoadCommentaryDialog *this)
{
  return FindOrAddPanelAnimationMap(className: "CLoadCommentaryDialog");
}

//------------------------------------------------------------------------------
// Address: 0x101F0C80
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CLoadCommentaryDialog::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CLoadCommentaryDialog::GetKBMap(CLoadCommentaryDialog *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CLoadCommentaryDialog::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CLoadCommentaryDialog::GetKBMap'::`2'::s_pMap;
  `CLoadCommentaryDialog::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CLoadCommentaryDialog");
  `CLoadCommentaryDialog::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F0CB0
// Name: void OpenLoadCommentaryDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OpenLoadCommentaryDialog()
{
  CLoadCommentaryDialog *v0; // esi
  CCStrike15BasePanel *v1; // eax
  CLoadCommentaryDialog *v2; // eax
  CGameUI *v3; // eax
  vgui::Panel *v4; // eax
  vgui::DHANDLE<CLoadCommentaryDialog> hCommentaryDialog; // [esp+0h] [ebp-4h] BYREF

  hCommentaryDialog.m_iPanelID = -1;
  if ( vgui::PHandle::Get(this: &hCommentaryDialog) == nullptr )
  {
    v0 = (CLoadCommentaryDialog *)MemAlloc_Alloc(nSize: 0x230u);
    if ( v0 != nullptr )
    {
      v1 = BasePanel();
      v2 = CLoadCommentaryDialog::CLoadCommentaryDialog(this: v0, parent: v1);
    }
    else
    {
      v2 = nullptr;
    }
    vgui::DHANDLE<CDragDropHelperPanel>::operator=(this: &hCommentaryDialog, pPanel: v2);
  }
  v3 = GameUI();
  CGameUI::ActivateGameUI(this: v3);
  v4 = vgui::PHandle::Get(this: &hCommentaryDialog);
  v4->__vftable[1].OnTick(this: v4);
}

//------------------------------------------------------------------------------
// Address: 0x101F0D20
// Name: void CC_LoadCommentary_Test(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl CC_LoadCommentary_Test()
{
  OpenLoadCommentaryDialog();
}
