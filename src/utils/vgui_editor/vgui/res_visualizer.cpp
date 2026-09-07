// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vgui_editor/vgui/res_visualizer.cpp
// Functions: 50
// ============================================================

#include "utils\vgui_editor\vgui\res_visualizer.h"

//------------------------------------------------------------------------------
// Address: 0x00404E50
// Name: public: void CUtlVector<struct visualized_panel_t __near *,class CUtlMemory<struct visualized_panel_t __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<visualized_panel_t *,CUtlMemory<visualized_panel_t *,int>>::PurgeAndDeleteElements(
        CUtlVector<CManaged_Panel_Child *,CUtlMemory<CManaged_Panel_Child *,int> > *this)
{
  int i; // edi
  bool v3; // sf
  CManaged_Panel_Child **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
    free(pMem: this->m_Memory.m_pMemory[i]);
  v3 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v3 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406260
// Name: public: void CUtlVector<class CManaged_Panel_Data __near *,class CUtlMemory<class CManaged_Panel_Data __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CManaged_Panel_Data *,CUtlMemory<CManaged_Panel_Data *,int>>::PurgeAndDeleteElements(
        CUtlVector<CManaged_Panel_Data *,CUtlMemory<CManaged_Panel_Data *,int> > *this)
{
  int i; // edi
  CManaged_Panel_Data *v3; // ebx
  bool v4; // sf
  CManaged_Panel_Data **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
  {
    v3 = this->m_Memory.m_pMemory[i];
    if ( v3 != nullptr )
    {
      CManaged_Panel_Data::~CManaged_Panel_Data(this: this->m_Memory.m_pMemory[i]);
      free(pMem: v3);
    }
  }
  v4 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v4 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406B50
// Name: public: int CUtlVector<struct vgui::MessageMapItem_t,class CUtlMemory<struct vgui::MessageMapItem_t,int>>::InsertBefore(int,struct vgui::MessageMapItem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
        CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int> > *this,
        int elem,
        const vgui::MessageMapItem_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::MessageMapItem_t *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::MessageMapItem_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: v7 << 6);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004083D0
// Name: public: int CUtlVector<struct PanelAnimationMapEntry,class CUtlMemory<struct PanelAnimationMapEntry,int>>::InsertBefore(int,struct PanelAnimationMapEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int>>::InsertBefore(
        CUtlVector<PanelAnimationMapEntry,CUtlMemory<PanelAnimationMapEntry,int> > *this,
        int elem,
        const PanelAnimationMapEntry *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  PanelAnimationMapEntry *m_pMemory; // ecx
  int v7; // eax
  PanelAnimationMapEntry *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,vgui::IPanelAnimationPropertyConverter *,int>::Node_t,int>,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelKeyBindingMapDictionary::PanelKeyBindingMapDictionaryEntry,int>::Node_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 24 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0040B870
// Name: public: static char const __near * CRes_Visualizer::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CRes_Visualizer::GetPanelClassName()
{
  return "CRes_Visualizer";
}

//------------------------------------------------------------------------------
// Address: 0x0040B880
// Name: public: virtual bool CKeyValuesDumpViaLoggingSystem::KvWriteText(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CKeyValuesDumpViaLoggingSystem::KvWriteText(CKeyValuesDumpViaLoggingSystem *this, const char *szText)
{
  int Channel; // eax
  int v3; // eax

  Channel = _LoggingSystem_FindChannel(a1: "Console");
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: Channel) != 0 )
  {
    v3 = _LoggingSystem_FindChannel(a1: "Console");
    _LoggingSystem_Log(a1: v3);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0040B8D0
// Name: public: virtual void CRes_Visualizer::ApplySchemeSettings(class vgui::IScheme __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRes_Visualizer::ApplySchemeSettings(CRes_Visualizer *this, vgui::IScheme *pScheme)
{
  vgui::Panel::ApplySchemeSettings(this, pScheme);
  this->m_hDefaultFont = pScheme->GetFont(this: pScheme, a2: "DefaultVerySmall", a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0040B900
// Name: public: virtual void CRes_Visualizer::PerformLayout(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRes_Visualizer::PerformLayout(CRes_Visualizer *this)
{
  RV_Aspect_Ratio_t m_AspectRatio; // eax

  vgui::EditablePanel::PerformLayout(this);
  m_AspectRatio = this->m_AspectRatio;
  this->m_nHeight = 480;
  switch ( m_AspectRatio )
  {
    case AR_5_4:
      this->m_nWidth = 600;
      break;
    case AR_4_3:
      this->m_nWidth = 640;
      break;
    case AR_16_10:
      this->m_nWidth = 768;
      break;
    case AR_16_9:
      this->m_nWidth = 852;
      break;
    default:
      break;
  }
  vgui::Panel::SetSize(
    this,
    wide: (int)(float)((float)this->m_nWidth * this->m_flScale),
    tall: (int)(float)(this->m_flScale * 480.0));
}

//------------------------------------------------------------------------------
// Address: 0x0040B9A0
// Name: protected: void CRes_Visualizer::DrawKeys(class KeyValues __near *,bool,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRes_Visualizer::DrawKeys(
        CRes_Visualizer *this,
        KeyValues *pKeys,
        bool bRecurse,
        int offset_x,
        int offset_y,
        int max_w,
        int max_h)
{
  KeyValues *i; // esi

  if ( pKeys != nullptr )
  {
    for ( i = KeyValues::GetFirstSubKey(this: pKeys); i != nullptr; i = KeyValues::GetNextKey(this: i) )
      CRes_Visualizer::DrawPanel(this, pPanelKeys: i, bRecurse, offset_x, offset_y, max_w, max_h);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B9F0
// Name: protected: void CRes_Visualizer::RecursivelyLoadResFiles(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRes_Visualizer::RecursivelyLoadResFiles(CRes_Visualizer *this, KeyValues *pParentKeys)
{
  const char *String; // ebx
  KeyValues *v3; // eax
  KeyValues *v4; // edi
  IBaseFileSystem *v5; // eax
  KeyValues *v6; // eax
  KeyValues *i; // esi
  const char *v8; // eax
  KeyValues *Copy; // eax
  char childResFilename[260]; // [esp+Ch] [ebp-10Ch] BYREF
  CRes_Visualizer *v11; // [esp+110h] [ebp-8h]
  KeyValues *pChildKeys; // [esp+114h] [ebp-4h]

  v11 = this;
  String = KeyValues::GetString(this: pParentKeys, keyName: "ControlName", defaultValue: &defaultValue);
  V_snprintf(pDest: childResFilename, maxLen: 260, pFormat: "resource/UI/%s.res", String);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  v4 = nullptr;
  if ( v3 != nullptr )
    pChildKeys = KeyValues::KeyValues(this: v3, setName: childResFilename);
  else
    pChildKeys = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v5 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v5 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: pChildKeys,
         filesystem: v5,
         resourceName: childResFilename,
         pathID: "GAME",
         pfnEvaluateSymbolProc: nullptr) )
  {
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
      v4 = KeyValues::KeyValues(this: v6, setName: "CHILDREN");
    KeyValues::AddSubKey(this: pParentKeys, pSubkey: v4);
    for ( i = KeyValues::GetFirstSubKey(this: pChildKeys); i != nullptr; i = KeyValues::GetNextKey(this: i) )
    {
      v8 = KeyValues::GetString(this: i, keyName: "ControlName", defaultValue: &defaultValue);
      if ( _V_stricmp(s1: v8, s2: String) != 0 )
      {
        CRes_Visualizer::RecursivelyLoadResFiles(this: v11, pParentKeys: i);
        Copy = KeyValues::MakeCopy(this: i);
        KeyValues::AddSubKey(this: v4, pSubkey: Copy);
      }
      else
      {
        KeyValues::MergeFrom(this: pParentKeys, kvMerge: i, eOp: MERGE_KV_UPDATE);
      }
    }
  }
  KeyValues::deleteThis(this: pChildKeys);
}

//------------------------------------------------------------------------------
// Address: 0x0040BB20
// Name: public: void CRes_Visualizer::SetKeys(class KeyValues __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRes_Visualizer::SetKeys(CRes_Visualizer *this, KeyValues *pKeys, bool bRecurse)
{
  KeyValues *m_pKeys; // ecx
  KeyValues *Copy; // eax
  KeyValues *i; // edi
  KeyValues *v7; // eax
  IBaseFileSystem *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // ebx
  KeyValues *j; // esi
  const char *String; // eax
  KeyValues *v13; // eax
  char pDest[260]; // [esp+4h] [ebp-108h] BYREF
  CRes_Visualizer *v15; // [esp+108h] [ebp-4h]
  const char *pKeysa; // [esp+114h] [ebp+8h]
  KeyValues *bRecursea; // [esp+118h] [ebp+Ch]

  m_pKeys = this->m_pKeys;
  v15 = this;
  if ( m_pKeys != nullptr )
    KeyValues::deleteThis(this: m_pKeys);
  Copy = KeyValues::MakeCopy(this: pKeys);
  this->m_pKeys = Copy;
  if ( bRecurse )
  {
    for ( i = KeyValues::GetFirstSubKey(this: Copy); i != nullptr; i = KeyValues::GetNextKey(this: i) )
    {
      pKeysa = KeyValues::GetString(this: i, keyName: "ControlName", defaultValue: &defaultValue);
      V_snprintf(pDest, maxLen: 260, pFormat: "resource/UI/%s.res", pKeysa);
      v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v7 != nullptr )
        bRecursea = KeyValues::KeyValues(this: v7, setName: pDest);
      else
        bRecursea = nullptr;
      if ( g_pFullFileSystem != nullptr )
        v8 = &g_pFullFileSystem->IBaseFileSystem;
      else
        v8 = nullptr;
      if ( KeyValues::LoadFromFile(
             this: bRecursea,
             filesystem: v8,
             resourceName: pDest,
             pathID: "GAME",
             pfnEvaluateSymbolProc: nullptr) )
      {
        v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        v10 = v9 != nullptr ? KeyValues::KeyValues(this: v9, setName: "CHILDREN") : nullptr;
        KeyValues::AddSubKey(this: i, pSubkey: v10);
        for ( j = KeyValues::GetFirstSubKey(this: bRecursea); j != nullptr; j = KeyValues::GetNextKey(this: j) )
        {
          String = KeyValues::GetString(this: j, keyName: "ControlName", defaultValue: &defaultValue);
          if ( _V_stricmp(s1: String, s2: pKeysa) != 0 )
          {
            CRes_Visualizer::RecursivelyLoadResFiles(this: v15, pParentKeys: j);
            v13 = KeyValues::MakeCopy(this: j);
            KeyValues::AddSubKey(this: v10, pSubkey: v13);
          }
          else
          {
            KeyValues::MergeFrom(this: i, kvMerge: j, eOp: MERGE_KV_UPDATE);
          }
        }
      }
      KeyValues::deleteThis(this: bRecursea);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040BCB0
// Name: public: CRes_Visualizer::CRes_Visualizer(class vgui::Panel __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CRes_Visualizer *__thiscall CRes_Visualizer::CRes_Visualizer(
        CRes_Visualizer *this,
        vgui::Panel *parent,
        const char *name)
{
  vgui::PanelMessageMap *v4; // edi
  PanelAnimationMap *v5; // edi
  vgui::PanelKeyBindingMap *v6; // edi

  vgui::EditablePanel::EditablePanel(this, parent, panelName: name);
  this->__vftable = (CRes_Visualizer_vtbl *)&CRes_Visualizer::`vftable';
  if ( `CRes_Visualizer::ChainToMap'::`2'::chained == 0 )
  {
    `CRes_Visualizer::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CRes_Visualizer");
    v4->pfnClassName = CRes_Visualizer::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "vgui::EditablePanel");
  }
  if ( `CRes_Visualizer::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CRes_Visualizer::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CRes_Visualizer");
    v5->pfnClassName = CRes_Visualizer::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "vgui::EditablePanel");
  }
  if ( `CRes_Visualizer::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CRes_Visualizer::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CRes_Visualizer");
    v6->pfnClassName = CRes_Visualizer::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "vgui::EditablePanel");
  }
  this->m_nTextureIDs.m_Memory.m_pMemory = nullptr;
  this->m_nTextureIDs.m_Memory.m_nAllocationCount = 0;
  this->m_nTextureIDs.m_Memory.m_nGrowSize = 0;
  this->m_nTextureIDs.m_Size = 0;
  this->m_nTextureIDs.m_pElements = nullptr;
  this->m_VisualizedPanels.m_Memory.m_pMemory = nullptr;
  this->m_VisualizedPanels.m_Memory.m_nAllocationCount = 0;
  this->m_VisualizedPanels.m_Memory.m_nGrowSize = 0;
  this->m_VisualizedPanels.m_Size = 0;
  this->m_VisualizedPanels.m_pElements = nullptr;
  this->m_pKeys = nullptr;
  this->m_AspectRatio = AR_4_3;
  this->m_flScale = 1.0;
  this->m_nWidth = 640;
  this->m_nHeight = 480;
  *(_WORD *)&this->m_bClipContents = 257;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040BDF0
// Name: public: virtual struct vgui::PanelMessageMap __near * CRes_Visualizer::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CRes_Visualizer::GetMessageMap(CRes_Visualizer *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CRes_Visualizer::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CRes_Visualizer::GetMessageMap'::`2'::s_pMap;
  `CRes_Visualizer::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CRes_Visualizer");
  `CRes_Visualizer::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040BE20
// Name: public: virtual struct PanelAnimationMap __near * CRes_Visualizer::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CRes_Visualizer::GetAnimMap(CRes_Visualizer *this)
{
  return FindOrAddPanelAnimationMap(className: "CRes_Visualizer");
}

//------------------------------------------------------------------------------
// Address: 0x0040BE30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CRes_Visualizer::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CRes_Visualizer::GetKBMap(CRes_Visualizer *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CRes_Visualizer::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CRes_Visualizer::GetKBMap'::`2'::s_pMap;
  `CRes_Visualizer::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CRes_Visualizer");
  `CRes_Visualizer::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040BE60
// Name: public: virtual void CRes_Visualizer::Paint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CRes_Visualizer::Paint(CRes_Visualizer *this)
{
  int m_nWidth; // [esp-8h] [ebp-Ch]
  int m_nHeight; // [esp-4h] [ebp-8h]

  CSteamApplication::PostShutdown(this);
  CUtlVector<visualized_panel_t *,CUtlMemory<visualized_panel_t *,int>>::PurgeAndDeleteElements(this: (CUtlVector<CManaged_Panel_Child *,CUtlMemory<CManaged_Panel_Child *,int> > *)&this->m_VisualizedPanels);
  m_nHeight = this->m_nHeight;
  m_nWidth = this->m_nWidth;
  this->m_nRecurseLevel = 0;
  this->m_nCurrentTextureID = 0;
  CRes_Visualizer::DrawKeys(
    this,
    pKeys: this->m_pKeys,
    bRecurse: true,
    offset_x: 0,
    offset_y: 0,
    max_w: m_nWidth,
    max_h: m_nHeight);
  ConVar::SetValue(this: (ConVar *)&res_vis_debug.IConVar, value: "0");
}

//------------------------------------------------------------------------------
// Address: 0x0040BF00
// Name: protected: void CRes_Visualizer::DrawPanel(class KeyValues __near *,bool,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CRes_Visualizer::DrawPanel(
        CRes_Visualizer *this@<ecx>,
        int a2@<ebx>,
        KeyValues *pPanelKeys,
        bool bRecurse,
        int offset_x,
        float offset_y,
        int max_w,
        int max_h)
{
  KeyValues *v8; // esi
  const char *String; // ebx
  const char *v11; // edi
  char v12; // al
  char v13; // al
  int v14; // eax
  int v15; // edi
  const char *v16; // eax
  bool v17; // bl
  const char *v18; // eax
  bool v19; // bl
  int v20; // ebx
  int Int; // edi
  visualized_panel_t *v22; // ebx
  int v23; // edx
  int v24; // ecx
  int v25; // ecx
  int v26; // edx
  const char **v27; // ebx
  const char *v28; // eax
  int v29; // ecx
  int v30; // edx
  CRes_Visualizer *v31; // edi
  int v32; // eax
  int m_nAllocationCount; // eax
  visualized_panel_t **m_pMemory; // ecx
  int v35; // eax
  visualized_panel_t **v36; // eax
  CRes_Visualizer *v37; // eax
  bool v38; // cc
  float m_flScale; // xmm0_4
  int v40; // edi
  int v41; // ebx
  void (__thiscall *DrawSetColor)(vgui::ISurface *, Color); // edx
  void (__thiscall *v43)(vgui::ISurface *, Color); // eax
  KeyValues *v44; // eax
  int v45; // eax
  CRes_Visualizer *v46; // edx
  int *v47; // ecx
  int v48; // eax
  int *v49; // eax
  void (__thiscall *v50)(vgui::ISurface *, Color); // eax
  int Channel; // eax
  int v52; // eax
  KeyValues *FirstSubKey; // esi
  int v54; // eax
  int v55; // eax
  const char *Name; // eax
  int v57; // eax
  int v58; // eax
  KeyValues *i; // esi
  wchar_t szconverted[1024]; // [esp+8h] [ebp-940h] BYREF
  char buffer[260]; // [esp+808h] [ebp-140h] BYREF
  int cy2; // [esp+90Ch] [ebp-3Ch] BYREF
  const char *szW; // [esp+910h] [ebp-38h]
  int cx2; // [esp+914h] [ebp-34h] BYREF
  const char *szH; // [esp+918h] [ebp-30h]
  int v66; // [esp+91Ch] [ebp-2Ch] BYREF
  const char *szPanelClass; // [esp+920h] [ebp-28h]
  int cy; // [esp+924h] [ebp-24h] BYREF
  const char *szPanelName; // [esp+928h] [ebp-20h]
  bool bFullH; // [esp+92Eh] [ebp-1Ah]
  bool bFullW; // [esp+92Fh] [ebp-19h]
  int y; // [esp+930h] [ebp-18h]
  bool bRightY; // [esp+937h] [ebp-11h]
  int h; // [esp+938h] [ebp-10h]
  int w; // [esp+93Ch] [ebp-Ch]
  int x; // [esp+940h] [ebp-8h]
  CRes_Visualizer *v77; // [esp+944h] [ebp-4h]

  v8 = pPanelKeys;
  v77 = this;
  if ( pPanelKeys == nullptr )
    return;
  ((void (__thiscall *)(vgui::ISurface *, int *, int *, int *, int *, int))g_pVGuiSurface->GetClipRect)(
    a1: g_pVGuiSurface,
    a2: &v66,
    a3: &cy,
    a4: &cx2,
    a5: &cy2,
    a6: a2);
  if ( this->m_bClipContents )
    g_pVGuiSurface->SetClipRect(
      this: g_pVGuiSurface,
      a2: offset_x + v66,
      a3: cy + LODWORD(offset_y),
      a4: offset_x + v66 + max_w,
      a5: cy + LODWORD(offset_y) + max_h);
  szPanelClass = KeyValues::GetString(this: v8, keyName: "ControlName", defaultValue: &defaultValue);
  szPanelName = KeyValues::GetString(this: v8, keyName: "fieldName", defaultValue: &defaultValue);
  h = 0;
  w = 0;
  y = 0;
  x = 0;
  String = KeyValues::GetString(this: v8, keyName: "xpos", defaultValue: &defaultValue);
  v11 = KeyValues::GetString(this: v8, keyName: "ypos", defaultValue: &defaultValue);
  szW = KeyValues::GetString(this: v8, keyName: "wide", defaultValue: &defaultValue);
  szH = KeyValues::GetString(this: v8, keyName: "tall", defaultValue: &defaultValue);
  HIBYTE(pPanelKeys) = 0;
  HIBYTE(max_h) = 0;
  HIBYTE(max_w) = 0;
  bRightY = false;
  bFullW = false;
  bFullH = false;
  if ( String != nullptr )
  {
    v12 = *String;
    if ( *String == 99 || v12 == 67 )
    {
      HIBYTE(pPanelKeys) = 1;
    }
    else
    {
      if ( v12 != 114 && v12 != 82 )
      {
LABEL_12:
        x = atoi(nptr: String);
        if ( HIBYTE(pPanelKeys) != 0 )
        {
          x = (int)(float)((float)((float)v77->m_nWidth * 0.5) + (float)x);
        }
        else if ( HIBYTE(max_h) != 0 )
        {
          x = v77->m_nWidth - x;
        }
        goto LABEL_16;
      }
      HIBYTE(max_h) = 1;
    }
    ++String;
    goto LABEL_12;
  }
LABEL_16:
  if ( v11 != nullptr )
  {
    v13 = *v11;
    if ( *v11 == 99 || v13 == 67 )
    {
      HIBYTE(max_w) = 1;
    }
    else
    {
      if ( v13 != 114 && v13 != 82 )
      {
LABEL_24:
        v14 = atoi(nptr: v11);
        v15 = v14;
        if ( HIBYTE(max_w) != 0 )
        {
          v15 = (int)(float)((float)((float)v77->m_nHeight * 0.5) + (float)v14);
        }
        else if ( bRightY )
        {
          v15 = v77->m_nHeight - v14;
        }
        goto LABEL_29;
      }
      bRightY = true;
    }
    ++v11;
    goto LABEL_24;
  }
  v15 = y;
LABEL_29:
  v16 = szW;
  if ( szW != nullptr )
  {
    if ( *szW == 102 )
    {
      v17 = true;
      v16 = szW + 1;
    }
    else
    {
      v17 = bFullW;
    }
    w = atoi(nptr: v16);
    if ( v17 )
      w = v77->m_nWidth;
  }
  v18 = szH;
  if ( szH != nullptr )
  {
    if ( *szH == 102 )
    {
      v19 = true;
      v18 = szH + 1;
    }
    else
    {
      v19 = bFullH;
    }
    h = atoi(nptr: v18);
    if ( v19 )
      h = v77->m_nHeight;
  }
  x += offset_x;
  y = LODWORD(offset_y) + v15;
  if ( KeyValues::FindKey(this: v8, keyName: "pin_to_sibling", bCreate: false) == nullptr )
    goto LABEL_78;
  offset_x = (int)KeyValues::GetString(this: v8, keyName: "pin_to_sibling", defaultValue: &defaultValue);
  offset_y = COERCE_FLOAT(KeyValues::GetInt(this: v8, keyName: "pin_corner_to_sibling", defaultValue: 0));
  v20 = 0;
  Int = KeyValues::GetInt(this: v8, keyName: "pin_to_sibling_corner", defaultValue: 0);
  if ( v77->m_VisualizedPanels.m_Size <= 0 )
    goto LABEL_78;
  while ( _V_stricmp(s1: (const char *)offset_x, s2: v77->m_VisualizedPanels.m_Memory.m_pMemory[v20]->pszPanelName) != 0 )
  {
    if ( ++v20 >= v77->m_VisualizedPanels.m_Size )
      goto LABEL_78;
  }
  v22 = v77->m_VisualizedPanels.m_Memory.m_pMemory[v20];
  if ( v22 == nullptr )
    goto LABEL_78;
  v23 = v22->x + x;
  v24 = v22->y + y;
  x = v23;
  y = v24;
  if ( Int == 2 || Int == 3 || Int == 7 )
  {
    v24 += v22->h;
    y = v24;
  }
  else if ( Int == 6 || Int == 8 )
  {
    v24 = (int)(float)((float)((float)v22->h * 0.5) + (float)v24);
    y = v24;
  }
  if ( Int == 1 || Int == 3 || Int == 6 )
  {
    v23 += v22->w;
    goto LABEL_61;
  }
  if ( Int == 5 || Int == 7 )
  {
    v23 = (int)(float)((float)((float)v22->w * 0.5) + (float)v23);
LABEL_61:
    x = v23;
  }
  if ( LODWORD(offset_y) == 2 || LODWORD(offset_y) == 3 || LODWORD(offset_y) == 7 )
  {
    v25 = v24 - h;
    goto LABEL_69;
  }
  if ( LODWORD(offset_y) == 6 || LODWORD(offset_y) == 8 )
  {
    v25 = (int)(float)((float)v24 - (float)((float)h * 0.5));
LABEL_69:
    y = v25;
  }
  if ( LODWORD(offset_y) == 1 || LODWORD(offset_y) == 3 || LODWORD(offset_y) == 6 )
  {
    v26 = v23 - w;
  }
  else
  {
    if ( LODWORD(offset_y) != 5 && LODWORD(offset_y) != 7 )
      goto LABEL_78;
    v26 = (int)(float)((float)((float)w * 0.5) + (float)v23);
  }
  x = v26;
LABEL_78:
  v27 = (const char **)operator new(nSize: 0x14u);
  v28 = KeyValues::GetString(this: v8, keyName: "fieldName", defaultValue: &defaultValue);
  v29 = y;
  v30 = w;
  v31 = v77;
  *v27 = v28;
  v27[1] = (const char *)x;
  v32 = h;
  v27[2] = (const char *)v29;
  v27[3] = (const char *)v30;
  v27[4] = (const char *)v32;
  m_nAllocationCount = v31->m_VisualizedPanels.m_Memory.m_nAllocationCount;
  offset_x = v31->m_VisualizedPanels.m_Size;
  if ( offset_x + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&v31->m_VisualizedPanels,
      num: offset_x - m_nAllocationCount + 1);
  ++v31->m_VisualizedPanels.m_Size;
  m_pMemory = v31->m_VisualizedPanels.m_Memory.m_pMemory;
  v35 = v31->m_VisualizedPanels.m_Size - offset_x - 1;
  v31->m_VisualizedPanels.m_pElements = m_pMemory;
  if ( v35 > 0 )
    _V_memmove(dest: &m_pMemory[offset_x + 1], src: &m_pMemory[offset_x], count: 4 * v35);
  v36 = &v31->m_VisualizedPanels.m_Memory.m_pMemory[offset_x];
  if ( v36 != nullptr )
    *v36 = (visualized_panel_t *)v27;
  v37 = v31;
  v38 = v31->m_nRecurseLevel <= 0;
  m_flScale = v31->m_flScale;
  v40 = (int)(float)((float)x * m_flScale);
  v41 = (int)(float)((float)y * m_flScale);
  w = (int)(float)((float)w * m_flScale);
  h = (int)(float)((float)h * m_flScale);
  offset_y = 1.0;
  if ( !v38 )
    offset_y = 0.050000001;
  if ( v37->m_bShowContents )
  {
    if ( KeyValues::FindKey(this: v8, keyName: "bgcolor_override", bCreate: false) != nullptr
      && KeyValues::GetInt(this: v8, keyName: "PaintBackgroundEnabled", defaultValue: -1) != 0 )
    {
      offset_x = 0;
      KeyValues::GetColor(
        this: v8,
        result: (Color *)&pPanelKeys,
        keyName: "bgcolor_override",
        defaultColor: (const Color *)&offset_x);
      ((void (__thiscall *)(vgui::ISurface *, KeyValues *))g_pVGuiSurface->DrawSetColor)(
        a1: g_pVGuiSurface,
        a2: pPanelKeys);
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v40, a3: v41, a4: v40 + w, a5: v41 + h);
    }
    if ( _V_stricmp(s1: szPanelClass, s2: "StatsBar") != 0 )
    {
      if ( _V_stricmp(s1: szPanelClass, s2: "ImagePanel") == 0 )
      {
        v44 = (KeyValues *)KeyValues::GetString(this: v8, keyName: "image", defaultValue: &defaultValue);
        pPanelKeys = v44;
        if ( v44 != nullptr && *(_BYTE *)v44 != 0 )
        {
          if ( v77->m_nCurrentTextureID >= v77->m_nTextureIDs.m_Size )
          {
            max_h = g_pVGuiSurface->CreateNewTextureID(this: g_pVGuiSurface, a2: false);
            v45 = v77->m_nTextureIDs.m_Memory.m_nAllocationCount;
            offset_x = v77->m_nTextureIDs.m_Size;
            if ( offset_x + 1 > v45 )
              CUtlMemory<unsigned long,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&v77->m_nTextureIDs,
                num: offset_x - v45 + 1);
            v46 = v77;
            ++v77->m_nTextureIDs.m_Size;
            v47 = v46->m_nTextureIDs.m_Memory.m_pMemory;
            v48 = v46->m_nTextureIDs.m_Size - offset_x - 1;
            v46->m_nTextureIDs.m_pElements = v47;
            if ( v48 > 0 )
              _V_memmove(dest: &v47[offset_x + 1], src: &v47[offset_x], count: 4 * v48);
            v49 = &v77->m_nTextureIDs.m_Memory.m_pMemory[offset_x];
            if ( v49 != nullptr )
              *v49 = max_h;
          }
          V_snprintf(pDest: buffer, maxLen: 260, pFormat: "vgui/%s", (const char *)pPanelKeys);
          g_pVGuiSurface->DrawSetTextureFile(
            this: g_pVGuiSurface,
            a2: v77->m_nTextureIDs.m_Memory.m_pMemory[v77->m_nCurrentTextureID],
            a3: buffer,
            a4: 1,
            a5: false);
          g_pVGuiSurface->DrawSetTexture(
            this: g_pVGuiSurface,
            a2: v77->m_nTextureIDs.m_Memory.m_pMemory[v77->m_nCurrentTextureID]);
          g_pVGuiSurface->DrawSetColor_2(this: g_pVGuiSurface, a2: 255, a3: 255, a4: 255, a5: 255);
          g_pVGuiSurface->DrawTexturedRect(this: g_pVGuiSurface, a2: v40, a3: v41, a4: v40 + w, a5: v41 + h);
          ++v77->m_nCurrentTextureID;
        }
      }
    }
    else
    {
      DrawSetColor = g_pVGuiSurface->DrawSetColor;
      offset_x = -10466751;
      ((void (__thiscall *)(vgui::ISurface *, int))DrawSetColor)(a1: g_pVGuiSurface, a2: -10466751);
      offset_x = v40 + w;
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v40, a3: v41, a4: v40 + w, a5: v41 + h);
      v43 = g_pVGuiSurface->DrawSetColor;
      offset_x = -4157886;
      ((void (__thiscall *)(vgui::ISurface *, int))v43)(a1: g_pVGuiSurface, a2: -4157886);
      g_pVGuiSurface->DrawFilledRect(this: g_pVGuiSurface, a2: v40 + 1, a3: v41 + 1, a4: v40 + w - 2, a5: v41 + h - 2);
    }
  }
  BYTE2(offset_x) = 0x80;
  v50 = g_pVGuiSurface->DrawSetColor;
  HIBYTE(offset_x) = (int)(float)(offset_y * 128.0);
  LOWORD(offset_x) = -32640;
  ((void (__thiscall *)(vgui::ISurface *, int))v50)(a1: g_pVGuiSurface, a2: offset_x);
  g_pVGuiSurface->DrawOutlinedRect(this: g_pVGuiSurface, a2: v40, a3: v41, a4: v40 + w, a5: v41 + h);
  g_pVGuiSurface->DrawSetTextFont(this: g_pVGuiSurface, a2: v77->m_hDefaultFont);
  g_pVGuiSurface->DrawSetTextColor_2(
    this: g_pVGuiSurface,
    a2: 255,
    a3: 255,
    a4: 255,
    a5: (int)(float)(offset_y * 220.0));
  g_pVGuiSurface->DrawSetTextPos(this: g_pVGuiSurface, a2: v40, a3: v41);
  g_pVGuiLocalize->ConvertANSIToUnicode(this: g_pVGuiLocalize, a2: szPanelName, a3: szconverted, a4: 2048);
  g_pVGuiSurface->DrawPrintText(this: g_pVGuiSurface, a2: szconverted, a3: wcslen(szconverted), a4: FONT_DRAW_DEFAULT);
  if ( bRecurse )
  {
    if ( res_vis_debug.m_pParent->m_Value.m_nValue == 1 )
    {
      Channel = _LoggingSystem_FindChannel(a1: "Console");
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: Channel) != 0 )
      {
        v52 = _LoggingSystem_FindChannel(a1: "Console");
        _LoggingSystem_Log(a1: v52);
      }
    }
    FirstSubKey = KeyValues::GetFirstSubKey(this: v8);
    for ( offset_x = (int)FirstSubKey; FirstSubKey != nullptr; offset_x = (int)FirstSubKey )
    {
      if ( res_vis_debug.m_pParent->m_Value.m_nValue == 1 )
      {
        v54 = _LoggingSystem_FindChannel(a1: "Console");
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: v54) != 0 )
        {
          KeyValues::GetName(this: FirstSubKey);
          v55 = _LoggingSystem_FindChannel(a1: "Console");
          _LoggingSystem_Log(a1: v55);
        }
      }
      Name = KeyValues::GetName(this: FirstSubKey);
      if ( _V_stricmp(s1: Name, s2: "CHILDREN") == 0 )
      {
        if ( res_vis_debug.m_pParent->m_Value.m_nValue == 2 )
        {
          v57 = _LoggingSystem_FindChannel(a1: "Console");
          if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: v57) != 0 )
          {
            KeyValues::GetName(this: FirstSubKey);
            v58 = _LoggingSystem_FindChannel(a1: "Console");
            _LoggingSystem_Log(a1: v58);
          }
          offset_y = COERCE_FLOAT(&CKeyValuesDumpViaLoggingSystem::`vftable');
          KeyValues::Dump(this: FirstSubKey, pDump: (IKeyValuesDumpContext *)&offset_y, nIndentLevel: 1);
        }
        ++v77->m_nRecurseLevel;
        for ( i = KeyValues::GetFirstSubKey(this: (KeyValues *)offset_x); i != nullptr; i = KeyValues::GetNextKey(this: i) )
          CRes_Visualizer::DrawPanel(
            this: v77,
            pPanelKeys: i,
            bRecurse,
            offset_x: v40,
            offset_y: v41,
            max_w: w,
            max_h: h);
        --v77->m_nRecurseLevel;
        FirstSubKey = (KeyValues *)offset_x;
      }
      FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
    }
  }
  ((void (__thiscall *)(vgui::ISurface *, int, int, int))g_pVGuiSurface->SetClipRect)(
    a1: g_pVGuiSurface,
    a2: v66,
    a3: cy,
    a4: cx2);
}

//------------------------------------------------------------------------------
// Address: 0x0040DAF0
// Name: public: void CUtlMemory<class CUtlSymbolTable,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CUtlSymbolTable,int>::Grow(CUtlMemory<CUtlSymbolTable,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CUtlSymbolTable *m_pMemory; // edx

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
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CUtlSymbolTable *)_g_pMemAlloc->Realloc_2(
                                             this: _g_pMemAlloc,
                                             a2: m_pMemory,
                                             a3: 56 * m_nAllocationCount);
    else
      this->m_pMemory = (CUtlSymbolTable *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 56 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E220
// Name: public: void CUtlVector<class CUtlSymbolTable,class CUtlMemory<class CUtlSymbolTable,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::Purge(
        CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int> > *this)
{
  int v2; // esi
  int v3; // ebx
  CUtlSymbolTable *m_pMemory; // ecx

  v2 = this->m_Size - 1;
  if ( v2 >= 0 )
  {
    v3 = v2;
    do
    {
      CUtlSymbolTable::~CUtlSymbolTable(this: &this->m_Memory.m_pMemory[v3--]);
      --v2;
    }
    while ( v2 >= 0 );
  }
  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize < 0 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E390
// Name: public: int CUtlVector<class CUtlSymbolTable,class CUtlMemory<class CUtlSymbolTable,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int>>::InsertMultipleBefore(
        CUtlVector<CUtlSymbolTable,CUtlMemory<CUtlSymbolTable,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  int v8; // edx
  CUtlSymbolTable *m_pMemory; // ecx
  int v10; // eax
  int v11; // ebx
  CUtlSymbolTable *v12; // ecx

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CUtlSymbolTable,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  v8 = elem;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[num + elem], src: &m_pMemory[elem], count: 56 * v10);
    v8 = elem;
LABEL_8:
    if ( num > 0 )
    {
      v11 = v8;
      do
      {
        v12 = &this->m_Memory.m_pMemory[v11];
        if ( v12 != nullptr )
        {
          CUtlSymbolTable::CUtlSymbolTable(this: v12, growSize: 0, initSize: 16, caseInsensitive: false);
          v8 = elem;
        }
        ++v11;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x0040EA40
// Name: public: int CUtlVector<struct CAppSystemGroup::Module_t,class CUtlMemory<struct CAppSystemGroup::Module_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int>>::AddToTail(
        CUtlVector<CAppSystemGroup::Module_t,CUtlMemory<CAppSystemGroup::Module_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CAppSystemGroup::Module_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 12 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00423280
// Name: public: int CUtlVector<struct vgui::BoundKey_t,class CUtlMemory<struct vgui::BoundKey_t,int>>::InsertBefore(int,struct vgui::BoundKey_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int>>::InsertBefore(
        CUtlVector<vgui::BoundKey_t,CUtlMemory<vgui::BoundKey_t,int> > *this,
        int elem,
        const vgui::BoundKey_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::BoundKey_t *m_pMemory; // ecx
  int v7; // eax
  vgui::BoundKey_t *v8; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    vgui::BoundKey_t::BoundKey_t(this: v8, src);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004232F0
// Name: public: int CUtlVector<struct vgui::OverridableColorEntry,class CUtlMemory<struct vgui::OverridableColorEntry,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int>>::InsertBefore(
        CUtlVector<vgui::OverridableColorEntry,CUtlMemory<vgui::OverridableColorEntry,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::OverridableColorEntry *m_pMemory; // ecx
  int v6; // eax
  vgui::OverridableColorEntry *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
      (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    v7->m_colFromScript = 0;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0042D670
// Name: public: CUtlVector<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,int>>::~CUtlVector<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,class CUtlMemory<struct CUtlSymbolTableLargeBase<class CThreadsafeTree<0>,0>::StringPool_t __near *,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(
        CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *this)
{
  bool v2; // sf
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042D6E0
// Name: public: int CUtlVector<struct vgui::AnimationController::ActiveAnimation_t,class CUtlMemory<struct vgui::AnimationController::ActiveAnimation_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::AnimationController::ActiveAnimation_t,CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int>>::InsertBefore(
        CUtlVector<vgui::AnimationController::ActiveAnimation_t,CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::AnimationController::ActiveAnimation_t *m_pMemory; // ecx
  int v6; // eax
  vgui::AnimationController::ActiveAnimation_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::AnimationController::ActiveAnimation_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 68 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
    v7->panel.m_iPanelID = -1;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0042D760
// Name: public: int CUtlVector<struct vgui::AnimationController::RanEvent_t,class CUtlMemory<struct vgui::AnimationController::RanEvent_t,int>>::InsertBefore(int,struct vgui::AnimationController::RanEvent_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int>>::InsertBefore(
        CUtlVector<vgui::AnimationController::RanEvent_t,CUtlMemory<vgui::AnimationController::RanEvent_t,int> > *this,
        int elem,
        const vgui::AnimationController::RanEvent_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::AnimationController::RanEvent_t *m_pMemory; // ecx
  int v7; // eax
  vgui::AnimationController::RanEvent_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::AnimationController::RanEvent_t,int>::Grow(
      (CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0042E9E0
// Name: public: int CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::InsertBefore(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::AnimationController::AnimSequence_t *m_pMemory; // ecx
  int v6; // eax
  vgui::AnimationController::AnimSequence_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::AnimationController::AnimSequence_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->cmdList.m_Memory.m_pMemory = nullptr;
    v7->cmdList.m_Memory.m_nAllocationCount = 0;
    v7->cmdList.m_Memory.m_nGrowSize = 0;
    v7->cmdList.m_Size = 0;
    v7->cmdList.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0042EA70
// Name: public: void CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::Remove(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this,
        int elem)
{
  int v3; // eax

  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Memory.m_pMemory[elem].cmdList);
  v3 = this->m_Size - elem - 1;
  if ( v3 > 0 )
    _V_memmove(dest: &this->m_Memory.m_pMemory[elem], src: &this->m_Memory.m_pMemory[elem + 1], count: 28 * v3);
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0042EAD0
// Name: public: void CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this)
{
  int v1; // ebx
  int v2; // edx
  char *v3; // esi
  void *v4; // eax
  CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *v5; // [esp+4h] [ebp-8h]
  int v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 28 * v1;
    v6 = 28 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 5) = 0;
      if ( *((int *)v3 + 4) >= 0 )
      {
        if ( *((_DWORD *)v3 + 2) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 2));
          v2 = v6;
          this = v5;
          *((_DWORD *)v3 + 2) = 0;
        }
        *((_DWORD *)v3 + 3) = 0;
      }
      v4 = *((void **)v3 + 2);
      *((_DWORD *)v3 + 6) = v4;
      if ( *((int *)v3 + 4) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          v2 = v6;
          this = v5;
          *((_DWORD *)v3 + 2) = 0;
        }
        *((_DWORD *)v3 + 3) = 0;
      }
      --v1;
      v2 -= 28;
      v6 = v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042F9B0
// Name: public: CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>::~CUtlVector<struct vgui::AnimationController::AnimSequence_t,class CUtlMemory<struct vgui::AnimationController::AnimSequence_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::~CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>(
        CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int> > *this)
{
  bool v2; // sf
  vgui::AnimationController::AnimSequence_t *m_pMemory; // eax

  CUtlVector<vgui::AnimationController::AnimSequence_t,CUtlMemory<vgui::AnimationController::AnimSequence_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043D450
// Name: public: int CUtlVector<int,class CUtlMemory<int,int>>::Find(int const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemory<int,int>>::Find(CUtlVector<int,CUtlMemory<int,int> > *this, const int *src)
{
  int m_Size; // edx
  int result; // eax
  int *i; // ecx

  m_Size = this->m_Size;
  result = 0;
  if ( m_Size <= 0 )
    return -1;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++result >= m_Size )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043FFA0
// Name: public: int CUtlVector<int,class CUtlMemory<int,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<int,CUtlMemory<int,int>>::AddToTail(CUtlVector<int,CUtlMemory<int,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  int *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow((CUtlMemory<vgui::TreeNode *,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0044E0C0
// Name: public: void CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::RemoveMultiple(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::RemoveMultiple(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int elem,
        int num)
{
  if ( this->m_Size - elem - num > 0 && num > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + num],
      count: 2 * (this->m_Size - elem - num));
  this->m_Size -= num;
}

//------------------------------------------------------------------------------
// Address: 0x0044EC30
// Name: public: void CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::EnsureCapacity(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int num)
{
  wchar_t *m_pMemory; // edx
  unsigned int v4; // eax
  wchar_t *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 2 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (wchar_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v4);
      goto LABEL_5;
    }
    v5 = (wchar_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044EF10
// Name: public: int CUtlVector<struct vgui::RichText::TFormatStream,class CUtlMemory<struct vgui::RichText::TFormatStream,int>>::InsertBefore(int,struct vgui::RichText::TFormatStream const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::RichText::TFormatStream,CUtlMemory<vgui::RichText::TFormatStream,int>>::InsertBefore(
        CUtlVector<vgui::RichText::TFormatStream,CUtlMemory<vgui::RichText::TFormatStream,int> > *this,
        int elem,
        const vgui::RichText::TFormatStream *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::RichText::TFormatStream *m_pMemory; // ecx
  int v7; // eax
  vgui::RichText::TFormatStream *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::RichText::TFormatStream,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 32 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00457660
// Name: public: int CUtlVector<wchar_t,class CUtlMemory<wchar_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<wchar_t,CUtlMemory<wchar_t,int>>::InsertMultipleBefore(
        CUtlVector<wchar_t,CUtlMemory<wchar_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  wchar_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<wchar_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 2 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0045D1F0
// Name: public: int CUtlVector<class vgui::TreeNode __near *,class CUtlMemory<class vgui::TreeNode __near *,int>>::AddToHead(class vgui::TreeNode __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int>>::AddToHead(
        CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *this,
        vgui::TreeNode **src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::TreeNode **m_pMemory; // eax
  int v6; // ecx
  vgui::TreeNode **v7; // esi

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: m_pMemory + 1, src: m_pMemory, count: 4 * v6);
  v7 = this->m_Memory.m_pMemory;
  if ( v7 != nullptr )
    *v7 = *src;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0045F7D0
// Name: public: int CUtlVector<class vgui::CTreeViewListControl::CColumnInfo,class CUtlMemory<class vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int>>::InsertMultipleBefore(
        CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  vgui::CTreeViewListControl::CColumnInfo *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_Title.m_Id = -1;
          v11->m_ciFlags = 0;
          v11->m_Right = 0;
          v11->m_Left = 0;
          v11->m_Width = 0;
        }
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00464E70
// Name: public: void CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  CUtlString *v3; // esi
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      v3->m_Storage.m_nActualLength = 0;
      if ( v3->m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Storage.m_Memory.m_pMemory);
          this = v4;
          v3->m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Storage.m_Memory.m_nAllocationCount = 0;
      }
      --v1;
      --v2;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00465000
// Name: public: CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>::~CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  bool v2; // sf
  CUtlString *m_pMemory; // eax

  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00466C60
// Name: public: void CUtlVector<class vgui::CHistoryItem,class CUtlMemory<class vgui::CHistoryItem,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::RemoveAll(
        CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  vgui::CHistoryItem *m_pMemory; // esi
  CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      free(pMem: this->m_Memory.m_pMemory[v2].m_text);
      free(pMem: m_pMemory[v2].m_extraText);
      m_pMemory[v2--].m_text = nullptr;
      if ( --v1 < 0 )
        break;
      this = v4;
    }
    v4->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00467140
// Name: public: void CUtlVector<class vgui::CConsolePanel::CompletionItem __near *,class CUtlMemory<class vgui::CConsolePanel::CompletionItem __near *,int>>::Sort(int (*)(class vgui::CConsolePanel::CompletionItem __near * const __near *,class vgui::CConsolePanel::CompletionItem __near * const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::CConsolePanel::CompletionItem *,CUtlMemory<vgui::CConsolePanel::CompletionItem *,int>>::Sort(
        CUtlVector<vgui::CConsolePanel::CompletionItem *,CUtlMemory<vgui::CConsolePanel::CompletionItem *,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  signed int m_Size; // ebx
  int i; // ebx
  int j; // esi
  vgui::CConsolePanel::CompletionItem *v6; // ecx
  vgui::CConsolePanel::CompletionItem **v7; // eax

  m_Size = this->m_Size;
  if ( m_Size > 1 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      qsort(base: this->m_Memory.m_pMemory, num: m_Size, width: 4u, comp: pfnCompare);
    }
    else
    {
      for ( i = m_Size - 1; i >= 0; --i )
      {
        for ( j = 1; j <= i; ++j )
        {
          if ( pfnCompare(a1: &this->m_Memory.m_pMemory[j - 1], a2: &this->m_Memory.m_pMemory[j]) < 0 )
          {
            v6 = this->m_Memory.m_pMemory[j - 1];
            v7 = &this->m_Memory.m_pMemory[j];
            *(v7 - 1) = *v7;
            *v7 = v6;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004671C0
// Name: public: void CUtlVector<class vgui::CHistoryItem,class CUtlMemory<class vgui::CHistoryItem,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::Remove(
        CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int> > *this,
        int elem)
{
  vgui::CHistoryItem *m_pMemory; // esi

  m_pMemory = this->m_Memory.m_pMemory;
  free(pMem: this->m_Memory.m_pMemory[elem].m_text);
  free(pMem: m_pMemory[elem].m_extraText);
  m_pMemory[elem].m_text = nullptr;
  if ( this->m_Size - elem - 1 > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[elem],
      src: &this->m_Memory.m_pMemory[elem + 1],
      count: 12 * (this->m_Size - elem - 1));
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004672F0
// Name: public: CUtlVector<class vgui::CHistoryItem,class CUtlMemory<class vgui::CHistoryItem,int>>::~CUtlVector<class vgui::CHistoryItem,class CUtlMemory<class vgui::CHistoryItem,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::~CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>(
        CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int> > *this)
{
  bool v2; // sf
  vgui::CHistoryItem *m_pMemory; // eax

  CUtlVector<vgui::CHistoryItem,CUtlMemory<vgui::CHistoryItem,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00469190
// Name: public: virtual class CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>> __near * vgui::BuildGroup::GetControlGroup(void)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *__thiscall vgui::BuildGroup::GetControlGroup(
        vgui::BuildGroup *this)
{
  return &this->_controlGroup;
}

//------------------------------------------------------------------------------
// Address: 0x0046A760
// Name: public: int CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int>>::InsertMultipleBefore(
        CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  vgui::PHandle *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  vgui::PHandle *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<unsigned long,int>::Grow(
      (CUtlMemory<vgui::TreeNode *,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          v11->m_iPanelID = -1;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0046AD40
// Name: public: int CUtlVector<struct CUtlHandleTable<class vgui::BuildGroup,20>::EntryType_t,class CUtlMemory<struct CUtlHandleTable<class vgui::BuildGroup,20>::EntryType_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int>>::InsertBefore(
        CUtlVector<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *m_pMemory; // ecx
  int v6; // eax
  CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::AnimationController::RanEvent_t,int>::Grow(
      this: &this->m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    *(_DWORD *)v7 = 0;
    v7->m_pData = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0046CFF0
// Name: public: void CUtlMemory<struct PanelItem_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<PanelItem_t,int>::Grow(CUtlMemory<PanelItem_t,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  PanelItem_t *m_pMemory; // edx
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
    v7 = 84 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (PanelItem_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v7);
    else
      this->m_pMemory = (PanelItem_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046D080
// Name: public: void CUtlMemory<struct UtlRBTreeNode_t<char const __near *,int>,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<UtlRBTreeNode_t<char const *,int>,int>::Grow(
        CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // edx
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
        m_nAllocationCount = 2;
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
    v7 = 20 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (vgui::CTreeViewListControl::CColumnInfo *)_g_pMemAlloc->Realloc_2(
                                                                     this: _g_pMemAlloc,
                                                                     a2: m_pMemory,
                                                                     a3: v7);
    else
      this->m_pMemory = (vgui::CTreeViewListControl::CColumnInfo *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0046DCC0
// Name: public: bool CUtlVector<class vgui::PHandle,class CUtlMemory<class vgui::PHandle,int>>::FindAndRemove(class vgui::PHandle const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int>>::FindAndRemove(
        CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *this,
        vgui::TreeNode **src)
{
  int m_Size; // edx
  int v4; // eax
  vgui::TreeNode **m_pMemory; // ebx
  vgui::TreeNode **i; // ecx
  int v8; // edx

  m_Size = this->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  v8 = m_Size - v4 - 1;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 4 * v8);
  --this->m_Size;
  return 1;
}
