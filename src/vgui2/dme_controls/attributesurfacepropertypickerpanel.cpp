// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/attributesurfacepropertypickerpanel.cpp
// Functions: 9
// ============================================================

#include "vgui2\dme_controls\attributesurfacepropertypickerpanel.h"

//------------------------------------------------------------------------------
// Address: 0x00470E70
// Name: private: virtual void CAttributeSurfacePropertyPickerPanel::OnPicked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSurfacePropertyPickerPanel::OnPicked(
        CAttributeSurfacePropertyPickerPanel *this,
        KeyValues *pKeyValues)
{
  const char *String; // eax

  String = KeyValues::GetString(this: pKeyValues, keyName: "choice", defaultValue: nullptr);
  if ( String != nullptr && *String != 0 )
  {
    this->m_pData->SetText(this: this->m_pData, a2: String);
    CBaseAttributePanel::SetDirty(this, dirty: true);
    if ( (this->m_nFlags & 0x10) != 0 )
      this->Apply(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471280
// Name: public: static char const __near * CAttributeSurfacePropertyPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeSurfacePropertyPickerPanel::GetPanelClassName()
{
  return "CAttributeSurfacePropertyPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004712A0
// Name: public: static void CAttributeSurfacePropertyPickerPanel::PanelMessageFunc_OnPicked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeSurfacePropertyPickerPanel::PanelMessageFunc_OnPicked::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeSurfacePropertyPickerPanel::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded )
  {
    `CAttributeSurfacePropertyPickerPanel::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeFilePickerPanel::`vcall'{884,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeSurfacePropertyPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "Picked";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00471330
// Name: private: void CAttributeSurfacePropertyPickerPanel::AddSurfacePropertiesToList(struct PickerList_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSurfacePropertyPickerPanel::AddSurfacePropertiesToList(
        CAttributeSurfacePropertyPickerPanel *this,
        PickerList_t *list)
{
  KeyValues *v2; // eax
  IBaseFileSystem *v3; // eax
  KeyValues *FirstSubKey; // edi
  const char *Name; // eax
  KeyValues *v6; // eax
  KeyValues *NextKey; // ebx
  IBaseFileSystem *v8; // esi
  const char *String; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  PickerInfo_t *m_pMemory; // ecx
  int v13; // eax
  PickerInfo_t *v14; // edi
  PickerInfo_t *v15; // edi
  const char *v16; // eax
  int v17; // [esp+0h] [ebp-10h]
  KeyValues *manifest; // [esp+4h] [ebp-Ch]
  KeyValues *sub; // [esp+8h] [ebp-8h]
  KeyValues *file; // [esp+Ch] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    manifest = KeyValues::KeyValues(this: v2, setName: SURFACEPROP_MANIFEST_FILE);
  else
    manifest = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v3 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v3 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: manifest,
         filesystem: v3,
         resourceName: SURFACEPROP_MANIFEST_FILE,
         pathID: "GAME",
         pfnEvaluateSymbolProc: nullptr) )
  {
    FirstSubKey = KeyValues::GetFirstSubKey(this: manifest);
    sub = FirstSubKey;
    if ( FirstSubKey != nullptr )
    {
      while ( 1 )
      {
        Name = KeyValues::GetName(this: FirstSubKey);
        if ( _V_stricmp(s1: Name, s2: "file") == 0 )
        {
          v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v6 != nullptr )
          {
            NextKey = KeyValues::KeyValues(this: v6, setName: SURFACEPROP_MANIFEST_FILE);
            file = NextKey;
          }
          else
          {
            file = nullptr;
            NextKey = nullptr;
          }
          if ( g_pFullFileSystem != nullptr )
            v8 = &g_pFullFileSystem->IBaseFileSystem;
          else
            v8 = nullptr;
          String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: defaultValue);
          if ( KeyValues::LoadFromFile(
                 this: NextKey,
                 filesystem: v8,
                 resourceName: String,
                 pathID: "GAME",
                 pfnEvaluateSymbolProc: nullptr) )
          {
            if ( NextKey != nullptr )
            {
              do
              {
                m_Size = list->m_Choices.m_Size;
                m_nAllocationCount = list->m_Choices.m_Memory.m_nAllocationCount;
                if ( m_Size + 1 > m_nAllocationCount )
                  CUtlMemory<MDLSquenceLayer_t,int>::Grow(
                    this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&list->m_Choices,
                    num: m_Size - m_nAllocationCount + 1);
                ++list->m_Choices.m_Size;
                m_pMemory = list->m_Choices.m_Memory.m_pMemory;
                v13 = list->m_Choices.m_Size - m_Size - 1;
                list->m_Choices.m_pElements = m_pMemory;
                if ( v13 > 0 )
                  _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v13);
                v17 = m_Size;
                v14 = &list->m_Choices.m_Memory.m_pMemory[m_Size];
                v14->m_pChoiceString = KeyValues::GetName(this: NextKey);
                v15 = &list->m_Choices.m_Memory.m_pMemory[v17];
                v15->m_pChoiceValue = KeyValues::GetName(this: NextKey);
                NextKey = KeyValues::GetNextKey(this: NextKey);
              }
              while ( NextKey != nullptr );
              FirstSubKey = sub;
              NextKey = file;
            }
          }
          else
          {
            v16 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: defaultValue);
            _Warning(a1: "Unable to load surface properties file '%s'\n", v16);
          }
          KeyValues::deleteThis(this: NextKey);
        }
        sub = KeyValues::GetNextKey(this: FirstSubKey);
        if ( sub == nullptr )
          break;
        FirstSubKey = sub;
      }
    }
  }
  else
  {
    _Warning(a1: "Unable to load manifest file '%s'\n", SURFACEPROP_MANIFEST_FILE);
  }
  KeyValues::deleteThis(this: manifest);
}

//------------------------------------------------------------------------------
// Address: 0x00471530
// Name: private: virtual void CAttributeSurfacePropertyPickerPanel::ShowPickerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSurfacePropertyPickerPanel::ShowPickerDialog(CAttributeSurfacePropertyPickerPanel *this)
{
  CPickerFrame *v2; // eax
  CPickerFrame *v3; // esi
  PickerList_t surfacePropList; // [esp+Ch] [ebp-18h] BYREF

  v2 = (CPickerFrame *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v2 != nullptr )
    v3 = CPickerFrame::CPickerFrame(
           this: v2,
           pParent: this,
           pTitle: "Select Surface Property",
           pPickerType: "Surface Property",
           pTextType: "surfacePropertyName");
  else
    v3 = nullptr;
  memset(&surfacePropList, 0, sizeof(surfacePropList));
  CAttributeSurfacePropertyPickerPanel::AddSurfacePropertiesToList(this, list: &surfacePropList);
  v3->AddActionSignalTarget_2(this: v3, a2: this);
  CPickerFrame::DoModal(this: v3, list: &surfacePropList, pContextKeyValues: nullptr);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&surfacePropList.m_Choices);
}

//------------------------------------------------------------------------------
// Address: 0x004715B0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeSurfacePropertyPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeSurfacePropertyPickerPanel::GetMessageMap(
        CAttributeSurfacePropertyPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeSurfacePropertyPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSurfacePropertyPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeSurfacePropertyPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeSurfacePropertyPickerPanel");
  `CAttributeSurfacePropertyPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004715E0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeSurfacePropertyPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeSurfacePropertyPickerPanel::GetAnimMap(
        CAttributeSurfacePropertyPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeSurfacePropertyPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x004715F0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeSurfacePropertyPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeSurfacePropertyPickerPanel::GetKBMap(
        CAttributeSurfacePropertyPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeSurfacePropertyPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSurfacePropertyPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeSurfacePropertyPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSurfacePropertyPickerPanel");
  `CAttributeSurfacePropertyPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00471620
// Name: public: CAttributeSurfacePropertyPickerPanel::CAttributeSurfacePropertyPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeSurfacePropertyPickerPanel *__thiscall CAttributeSurfacePropertyPickerPanel::CAttributeSurfacePropertyPickerPanel(
        CAttributeSurfacePropertyPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeBasePickerPanel::CAttributeBasePickerPanel(this, parent, info);
  this->__vftable = (CAttributeSurfacePropertyPickerPanel_vtbl *)&CAttributeSurfacePropertyPickerPanel::`vftable';
  if ( `CAttributeSurfacePropertyPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSurfacePropertyPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeSurfacePropertyPickerPanel");
    v4->pfnClassName = CAttributeSurfacePropertyPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeSurfacePropertyPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeSurfacePropertyPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeSurfacePropertyPickerPanel");
    v5->pfnClassName = CAttributeSurfacePropertyPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeSurfacePropertyPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSurfacePropertyPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSurfacePropertyPickerPanel");
    v6->pfnClassName = CAttributeSurfacePropertyPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
  }
  CAttributeSurfacePropertyPickerPanel::PanelMessageFunc_OnPicked::InitVar(a1: (int)&savedregs);
  return this;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10494350
// Name: private: virtual void CAttributeSurfacePropertyPickerPanel::OnPicked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSurfacePropertyPickerPanel::OnPicked(
        CAttributeSurfacePropertyPickerPanel *this,
        KeyValues *pKeyValues)
{
  char *String; // eax

  String = KeyValues::GetString(this: pKeyValues, keyName: "choice", defaultValue: nullptr);
  if ( String != nullptr && *String != 0 )
  {
    this->m_pData->SetText(this: this->m_pData, a2: String);
    CBaseAttributePanel::SetDirty(this, dirty: true);
    if ( (this->m_nFlags & 0x10) != 0 )
      this->Apply(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10494770
// Name: public: static char const __near * CAttributeSurfacePropertyPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeSurfacePropertyPickerPanel::GetPanelClassName()
{
  return "CAttributeSurfacePropertyPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10494780
// Name: public: static void CAttributeSurfacePropertyPickerPanel::PanelMessageFunc_OnPicked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeSurfacePropertyPickerPanel::PanelMessageFunc_OnPicked::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeSurfacePropertyPickerPanel::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded )
  {
    `CAttributeSurfacePropertyPickerPanel::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeFilePickerPanel::`vcall'{884,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeSurfacePropertyPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "Picked";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10494810
// Name: private: void CAttributeSurfacePropertyPickerPanel::AddSurfacePropertiesToList(struct PickerList_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSurfacePropertyPickerPanel::AddSurfacePropertiesToList(
        CAttributeSurfacePropertyPickerPanel *this,
        PickerList_t *list)
{
  KeyValues *v2; // eax
  IBaseFileSystem *v3; // eax
  KeyValues *FirstSubKey; // edi
  const char *Name; // eax
  KeyValues *v6; // eax
  KeyValues *NextKey; // ebx
  IBaseFileSystem *v8; // esi
  char *String; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  PickerInfo_t *m_pMemory; // ecx
  int v13; // eax
  PickerInfo_t *v14; // edi
  PickerInfo_t *v15; // edi
  char *v16; // eax
  int v17; // [esp+0h] [ebp-10h]
  KeyValues *manifest; // [esp+4h] [ebp-Ch]
  KeyValues *sub; // [esp+8h] [ebp-8h]
  KeyValues *file; // [esp+Ch] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    manifest = KeyValues::KeyValues(this: v2, setName: SURFACEPROP_MANIFEST_FILE);
  else
    manifest = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v3 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v3 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: manifest,
         filesystem: v3,
         resourceName: (char *)SURFACEPROP_MANIFEST_FILE,
         pathID: "GAME",
         pfnEvaluateSymbolProc: nullptr) )
  {
    FirstSubKey = KeyValues::GetFirstSubKey(this: manifest);
    sub = FirstSubKey;
    if ( FirstSubKey != nullptr )
    {
      while ( 1 )
      {
        Name = KeyValues::GetName(this: FirstSubKey);
        if ( _V_stricmp(s1: Name, s2: "file") == 0 )
        {
          v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v6 != nullptr )
          {
            NextKey = KeyValues::KeyValues(this: v6, setName: SURFACEPROP_MANIFEST_FILE);
            file = NextKey;
          }
          else
          {
            file = nullptr;
            NextKey = nullptr;
          }
          if ( g_pFullFileSystem != nullptr )
            v8 = &g_pFullFileSystem->IBaseFileSystem;
          else
            v8 = nullptr;
          String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: &var);
          if ( KeyValues::LoadFromFile(
                 this: NextKey,
                 filesystem: v8,
                 resourceName: String,
                 pathID: "GAME",
                 pfnEvaluateSymbolProc: nullptr) )
          {
            if ( NextKey != nullptr )
            {
              do
              {
                m_Size = list->m_Choices.m_Size;
                m_nAllocationCount = list->m_Choices.m_Memory.m_nAllocationCount;
                if ( m_Size + 1 > m_nAllocationCount )
                  CUtlMemory<CacheOptimizedKDNode,int>::Grow(
                    this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&list->m_Choices,
                    num: m_Size - m_nAllocationCount + 1);
                ++list->m_Choices.m_Size;
                m_pMemory = list->m_Choices.m_Memory.m_pMemory;
                v13 = list->m_Choices.m_Size - m_Size - 1;
                list->m_Choices.m_pElements = m_pMemory;
                if ( v13 > 0 )
                  _V_memmove(
                    dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
                    src: (unsigned __int8 *)&m_pMemory[m_Size],
                    count: 8 * v13);
                v17 = m_Size;
                v14 = &list->m_Choices.m_Memory.m_pMemory[m_Size];
                v14->m_pChoiceString = KeyValues::GetName(this: NextKey);
                v15 = &list->m_Choices.m_Memory.m_pMemory[v17];
                v15->m_pChoiceValue = KeyValues::GetName(this: NextKey);
                NextKey = KeyValues::GetNextKey(this: NextKey);
              }
              while ( NextKey != nullptr );
              FirstSubKey = sub;
              NextKey = file;
            }
          }
          else
          {
            v16 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: &var);
            _Warning(a1: "Unable to load surface properties file '%s'\n", v16);
          }
          KeyValues::deleteThis(this: NextKey);
        }
        sub = KeyValues::GetNextKey(this: FirstSubKey);
        if ( sub == nullptr )
          break;
        FirstSubKey = sub;
      }
    }
  }
  else
  {
    _Warning(a1: "Unable to load manifest file '%s'\n", SURFACEPROP_MANIFEST_FILE);
  }
  KeyValues::deleteThis(this: manifest);
}

//------------------------------------------------------------------------------
// Address: 0x10494A10
// Name: private: virtual void CAttributeSurfacePropertyPickerPanel::ShowPickerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSurfacePropertyPickerPanel::ShowPickerDialog(CAttributeSurfacePropertyPickerPanel *this)
{
  CPickerFrame *v2; // eax
  CPickerFrame *v3; // esi
  PickerList_t surfacePropList; // [esp+Ch] [ebp-18h] BYREF

  v2 = (CPickerFrame *)operator new(nSize: 0x224u);
  if ( v2 != nullptr )
    v3 = CPickerFrame::CPickerFrame(
           this: v2,
           pParent: this,
           pTitle: "Select Surface Property",
           pPickerType: "Surface Property",
           pTextType: "surfacePropertyName");
  else
    v3 = nullptr;
  memset(&surfacePropList, 0, sizeof(surfacePropList));
  CAttributeSurfacePropertyPickerPanel::AddSurfacePropertiesToList(this, list: &surfacePropList);
  v3->AddActionSignalTarget_2(this: v3, a2: this);
  CPickerFrame::DoModal(this: v3, list: &surfacePropList, pContextKeyValues: nullptr);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&surfacePropList.m_Choices);
}

//------------------------------------------------------------------------------
// Address: 0x10494A90
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeSurfacePropertyPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeSurfacePropertyPickerPanel::GetMessageMap(
        CAttributeSurfacePropertyPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeSurfacePropertyPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSurfacePropertyPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeSurfacePropertyPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeSurfacePropertyPickerPanel");
  `CAttributeSurfacePropertyPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10494AC0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeSurfacePropertyPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeSurfacePropertyPickerPanel::GetAnimMap(
        CAttributeSurfacePropertyPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeSurfacePropertyPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10494AD0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeSurfacePropertyPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeSurfacePropertyPickerPanel::GetKBMap(
        CAttributeSurfacePropertyPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeSurfacePropertyPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSurfacePropertyPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeSurfacePropertyPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSurfacePropertyPickerPanel");
  `CAttributeSurfacePropertyPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10494B00
// Name: public: CAttributeSurfacePropertyPickerPanel::CAttributeSurfacePropertyPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeSurfacePropertyPickerPanel *__thiscall CAttributeSurfacePropertyPickerPanel::CAttributeSurfacePropertyPickerPanel(
        CAttributeSurfacePropertyPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeBasePickerPanel::CAttributeBasePickerPanel(this, parent, info);
  this->__vftable = (CAttributeSurfacePropertyPickerPanel_vtbl *)&CAttributeSurfacePropertyPickerPanel::`vftable';
  if ( `CAttributeSurfacePropertyPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSurfacePropertyPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeSurfacePropertyPickerPanel");
    v4->pfnClassName = CAttributeSurfacePropertyPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeSurfacePropertyPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeSurfacePropertyPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeSurfacePropertyPickerPanel");
    v5->pfnClassName = CAttributeSurfacePropertyPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeSurfacePropertyPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSurfacePropertyPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSurfacePropertyPickerPanel");
    v6->pfnClassName = CAttributeSurfacePropertyPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
  }
  CAttributeSurfacePropertyPickerPanel::PanelMessageFunc_OnPicked::InitVar(a1: (int)&savedregs);
  return this;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0049AE20
// Name: public: static char const __near * CAttributeSurfacePropertyPickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeSurfacePropertyPickerPanel::GetPanelClassName()
{
  return "CAttributeSurfacePropertyPickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0049AE30
// Name: private: virtual void CAttributeSurfacePropertyPickerPanel::OnPicked(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSurfacePropertyPickerPanel::OnPicked(
        CAttributeSurfacePropertyPickerPanel *this,
        KeyValues *pKeyValues)
{
  const char *String; // eax

  String = KeyValues::GetString(this: pKeyValues, keyName: "choice", defaultValue: nullptr);
  if ( String != nullptr && *String != 0 )
  {
    this->m_pData->SetText(this: this->m_pData, a2: String);
    CBaseAttributePanel::SetDirty(this, dirty: true);
    if ( (this->m_nFlags & 0x10) != 0 )
      this->Apply(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049AE90
// Name: public: static void CAttributeSurfacePropertyPickerPanel::PanelMessageFunc_OnPicked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeSurfacePropertyPickerPanel::PanelMessageFunc_OnPicked::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeSurfacePropertyPickerPanel::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded )
  {
    `CAttributeSurfacePropertyPickerPanel::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeFilePickerPanel::`vcall'{884,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeSurfacePropertyPickerPanel");
    m_Size = v1->m_Size;
    v3 = _mm_load_si128(&v5);
    memset(&v4.m[2][3], 0, 20);
    LODWORD(v4.m[0][0]) = "Picked";
    *(__m128i *)&v4.m[1][0] = v3;
    LODWORD(v4.m[2][0]) = 1;
    *(_QWORD *)&v4.m[2][1] = 6;
    CUtlVector<vgui::MessageMapItem_t,CUtlMemory<vgui::MessageMapItem_t,int>>::InsertBefore(
      this: v1,
      elem: m_Size,
      src: &v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049AF20
// Name: private: void CAttributeSurfacePropertyPickerPanel::AddSurfacePropertiesToList(struct PickerList_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSurfacePropertyPickerPanel::AddSurfacePropertiesToList(
        CAttributeSurfacePropertyPickerPanel *this,
        PickerList_t *list)
{
  KeyValues *v2; // eax
  IBaseFileSystem *v3; // eax
  KeyValues *FirstSubKey; // edi
  const char *Name; // eax
  KeyValues *v6; // eax
  KeyValues *NextKey; // ebx
  IBaseFileSystem *v8; // esi
  const char *String; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  PickerInfo_t *m_pMemory; // ecx
  int v13; // eax
  PickerInfo_t *v14; // edi
  PickerInfo_t *v15; // edi
  const char *v16; // eax
  int v17; // [esp+0h] [ebp-10h]
  KeyValues *manifest; // [esp+4h] [ebp-Ch]
  KeyValues *sub; // [esp+8h] [ebp-8h]
  KeyValues *file; // [esp+Ch] [ebp-4h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    manifest = KeyValues::KeyValues(this: v2, setName: SURFACEPROP_MANIFEST_FILE);
  else
    manifest = nullptr;
  if ( g_pFullFileSystem != nullptr )
    v3 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v3 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: manifest,
         filesystem: v3,
         resourceName: SURFACEPROP_MANIFEST_FILE,
         pathID: "GAME",
         pfnEvaluateSymbolProc: nullptr) )
  {
    FirstSubKey = KeyValues::GetFirstSubKey(this: manifest);
    sub = FirstSubKey;
    if ( FirstSubKey != nullptr )
    {
      while ( 1 )
      {
        Name = KeyValues::GetName(this: FirstSubKey);
        if ( _V_stricmp(s1: Name, s2: "file") == 0 )
        {
          v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v6 != nullptr )
          {
            NextKey = KeyValues::KeyValues(this: v6, setName: SURFACEPROP_MANIFEST_FILE);
            file = NextKey;
          }
          else
          {
            file = nullptr;
            NextKey = nullptr;
          }
          if ( g_pFullFileSystem != nullptr )
            v8 = &g_pFullFileSystem->IBaseFileSystem;
          else
            v8 = nullptr;
          String = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: defaultValue);
          if ( KeyValues::LoadFromFile(
                 this: NextKey,
                 filesystem: v8,
                 resourceName: String,
                 pathID: "GAME",
                 pfnEvaluateSymbolProc: nullptr) )
          {
            if ( NextKey != nullptr )
            {
              do
              {
                m_Size = list->m_Choices.m_Size;
                m_nAllocationCount = list->m_Choices.m_Memory.m_nAllocationCount;
                if ( m_Size + 1 > m_nAllocationCount )
                  CUtlMemory<MDLSquenceLayer_t,int>::Grow(
                    this: (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&list->m_Choices,
                    num: m_Size - m_nAllocationCount + 1);
                ++list->m_Choices.m_Size;
                m_pMemory = list->m_Choices.m_Memory.m_pMemory;
                v13 = list->m_Choices.m_Size - m_Size - 1;
                list->m_Choices.m_pElements = m_pMemory;
                if ( v13 > 0 )
                  _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v13);
                v17 = m_Size;
                v14 = &list->m_Choices.m_Memory.m_pMemory[m_Size];
                v14->m_pChoiceString = KeyValues::GetName(this: NextKey);
                v15 = &list->m_Choices.m_Memory.m_pMemory[v17];
                v15->m_pChoiceValue = KeyValues::GetName(this: NextKey);
                NextKey = KeyValues::GetNextKey(this: NextKey);
              }
              while ( NextKey != nullptr );
              FirstSubKey = sub;
              NextKey = file;
            }
          }
          else
          {
            v16 = KeyValues::GetString(this: FirstSubKey, keyName: nullptr, defaultValue: defaultValue);
            _Warning(a1: "Unable to load surface properties file '%s'\n", v16);
          }
          KeyValues::deleteThis(this: NextKey);
        }
        sub = KeyValues::GetNextKey(this: FirstSubKey);
        if ( sub == nullptr )
          break;
        FirstSubKey = sub;
      }
    }
  }
  else
  {
    _Warning(a1: "Unable to load manifest file '%s'\n", SURFACEPROP_MANIFEST_FILE);
  }
  KeyValues::deleteThis(this: manifest);
}

//------------------------------------------------------------------------------
// Address: 0x0049B120
// Name: private: virtual void CAttributeSurfacePropertyPickerPanel::ShowPickerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeSurfacePropertyPickerPanel::ShowPickerDialog(CAttributeSurfacePropertyPickerPanel *this)
{
  CPickerFrame *v2; // eax
  CPickerFrame *v3; // esi
  PickerList_t surfacePropList; // [esp+Ch] [ebp-18h] BYREF

  v2 = (CPickerFrame *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v2 != nullptr )
    v3 = CPickerFrame::CPickerFrame(
           this: v2,
           pParent: this,
           pTitle: "Select Surface Property",
           pPickerType: "Surface Property",
           pTextType: "surfacePropertyName");
  else
    v3 = nullptr;
  memset(&surfacePropList, 0, sizeof(surfacePropList));
  CAttributeSurfacePropertyPickerPanel::AddSurfacePropertiesToList(this, list: &surfacePropList);
  v3->AddActionSignalTarget_2(this: v3, a2: this);
  CPickerFrame::DoModal(this: v3, list: &surfacePropList, pContextKeyValues: nullptr);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&surfacePropList.m_Choices);
}

//------------------------------------------------------------------------------
// Address: 0x0049B1A0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeSurfacePropertyPickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeSurfacePropertyPickerPanel::GetMessageMap(
        CAttributeSurfacePropertyPickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeSurfacePropertyPickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSurfacePropertyPickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeSurfacePropertyPickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeSurfacePropertyPickerPanel");
  `CAttributeSurfacePropertyPickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049B1D0
// Name: public: virtual struct PanelAnimationMap __near * CAttributeSurfacePropertyPickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeSurfacePropertyPickerPanel::GetAnimMap(
        CAttributeSurfacePropertyPickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeSurfacePropertyPickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0049B1E0
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeSurfacePropertyPickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeSurfacePropertyPickerPanel::GetKBMap(
        CAttributeSurfacePropertyPickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeSurfacePropertyPickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeSurfacePropertyPickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeSurfacePropertyPickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSurfacePropertyPickerPanel");
  `CAttributeSurfacePropertyPickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049B210
// Name: public: CAttributeSurfacePropertyPickerPanel::CAttributeSurfacePropertyPickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeSurfacePropertyPickerPanel *__thiscall CAttributeSurfacePropertyPickerPanel::CAttributeSurfacePropertyPickerPanel(
        CAttributeSurfacePropertyPickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeBasePickerPanel::CAttributeBasePickerPanel(this, parent, info);
  this->__vftable = (CAttributeSurfacePropertyPickerPanel_vtbl *)&CAttributeSurfacePropertyPickerPanel::`vftable';
  if ( `CAttributeSurfacePropertyPickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSurfacePropertyPickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeSurfacePropertyPickerPanel");
    v4->pfnClassName = CAttributeSurfacePropertyPickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeSurfacePropertyPickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeSurfacePropertyPickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeSurfacePropertyPickerPanel");
    v5->pfnClassName = CAttributeSurfacePropertyPickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeSurfacePropertyPickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeSurfacePropertyPickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeSurfacePropertyPickerPanel");
    v6->pfnClassName = CAttributeSurfacePropertyPickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
  }
  CAttributeSurfacePropertyPickerPanel::PanelMessageFunc_OnPicked::InitVar(a1: (int)&savedregs);
  return this;
}

} // namespace sceneviewer
