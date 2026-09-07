// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/dme_controls/attributedetailtypepickerpanel.cpp
// Functions: 8
// ============================================================

#include "vgui2\dme_controls\attributedetailtypepickerpanel.h"

//------------------------------------------------------------------------------
// Address: 0x004720C0
// Name: public: static char const __near * CAttributeDetailTypePickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeDetailTypePickerPanel::GetPanelClassName()
{
  return "CAttributeDetailTypePickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x004720D0
// Name: public: static void CAttributeDetailTypePickerPanel::PanelMessageFunc_OnPicked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeDetailTypePickerPanel::PanelMessageFunc_OnPicked::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeDetailTypePickerPanel::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded )
  {
    `CAttributeDetailTypePickerPanel::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeFilePickerPanel::`vcall'{884,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeDetailTypePickerPanel");
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
// Address: 0x00472160
// Name: private: void CAttributeDetailTypePickerPanel::AddDetailTypesToList(struct PickerList_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeDetailTypePickerPanel::AddDetailTypesToList(
        CAttributeDetailTypePickerPanel *this,
        PickerList_t *list)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IBaseFileSystem *v4; // eax
  KeyValues *FirstTrueSubKey; // edi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  PickerInfo_t *m_pMemory; // ecx
  int v10; // eax
  PickerInfo_t *v11; // ebx
  PickerInfo_t *v12; // ebx
  KeyValues *pDetailTypes; // [esp+8h] [ebp-4h]
  PickerList_t *lista; // [esp+14h] [ebp+8h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: DETAILTYPE_FILE);
    pDetailTypes = v3;
  }
  else
  {
    pDetailTypes = nullptr;
    v3 = nullptr;
  }
  if ( g_pFullFileSystem != nullptr )
    v4 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v4 = nullptr;
  if ( !KeyValues::LoadFromFile(
          this: v3,
          filesystem: v4,
          resourceName: DETAILTYPE_FILE,
          pathID: "GAME",
          pfnEvaluateSymbolProc: nullptr) )
  {
    _Warning(a1: "Unable to load detail prop file '%s'\n", DETAILTYPE_FILE);
    goto LABEL_16;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: v3);
  if ( FirstTrueSubKey == nullptr )
  {
LABEL_16:
    KeyValues::deleteThis(this: v3);
    return;
  }
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
    v10 = list->m_Choices.m_Size - m_Size - 1;
    list->m_Choices.m_pElements = m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v10);
    lista = (PickerList_t *)(8 * m_Size);
    v11 = &list->m_Choices.m_Memory.m_pMemory[m_Size];
    v11->m_pChoiceString = KeyValues::GetName(this: FirstTrueSubKey);
    v12 = (PickerInfo_t *)((char *)lista + (unsigned int)list->m_Choices.m_Memory.m_pMemory);
    v12->m_pChoiceValue = KeyValues::GetName(this: FirstTrueSubKey);
    FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
  }
  while ( FirstTrueSubKey != nullptr );
  KeyValues::deleteThis(this: pDetailTypes);
}

//------------------------------------------------------------------------------
// Address: 0x00472290
// Name: private: virtual void CAttributeDetailTypePickerPanel::ShowPickerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeDetailTypePickerPanel::ShowPickerDialog(CAttributeDetailTypePickerPanel *this)
{
  CPickerFrame *v2; // eax
  CPickerFrame *v3; // esi
  PickerList_t detailTypeList; // [esp+Ch] [ebp-18h] BYREF

  v2 = (CPickerFrame *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v2 != nullptr )
    v3 = CPickerFrame::CPickerFrame(
           this: v2,
           pParent: this,
           pTitle: "Select Detail Type",
           pPickerType: "Detail Type",
           pTextType: "detailTypeName");
  else
    v3 = nullptr;
  memset(&detailTypeList, 0, sizeof(detailTypeList));
  CAttributeDetailTypePickerPanel::AddDetailTypesToList(this, list: &detailTypeList);
  v3->AddActionSignalTarget_2(this: v3, a2: this);
  CPickerFrame::DoModal(this: v3, list: &detailTypeList, pContextKeyValues: nullptr);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&detailTypeList.m_Choices);
}

//------------------------------------------------------------------------------
// Address: 0x00472310
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeDetailTypePickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeDetailTypePickerPanel::GetMessageMap(CAttributeDetailTypePickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeDetailTypePickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeDetailTypePickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeDetailTypePickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeDetailTypePickerPanel");
  `CAttributeDetailTypePickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00472340
// Name: public: virtual struct PanelAnimationMap __near * CAttributeDetailTypePickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeDetailTypePickerPanel::GetAnimMap(CAttributeDetailTypePickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeDetailTypePickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x00472350
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeDetailTypePickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeDetailTypePickerPanel::GetKBMap(CAttributeDetailTypePickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeDetailTypePickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeDetailTypePickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeDetailTypePickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeDetailTypePickerPanel");
  `CAttributeDetailTypePickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00472380
// Name: public: CAttributeDetailTypePickerPanel::CAttributeDetailTypePickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeDetailTypePickerPanel *__thiscall CAttributeDetailTypePickerPanel::CAttributeDetailTypePickerPanel(
        CAttributeDetailTypePickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeBasePickerPanel::CAttributeBasePickerPanel(this, parent, info);
  this->__vftable = (CAttributeDetailTypePickerPanel_vtbl *)&CAttributeDetailTypePickerPanel::`vftable';
  if ( `CAttributeDetailTypePickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeDetailTypePickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeDetailTypePickerPanel");
    v4->pfnClassName = CAttributeDetailTypePickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeDetailTypePickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeDetailTypePickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeDetailTypePickerPanel");
    v5->pfnClassName = CAttributeDetailTypePickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeDetailTypePickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeDetailTypePickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeDetailTypePickerPanel");
    v6->pfnClassName = CAttributeDetailTypePickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
  }
  CAttributeDetailTypePickerPanel::PanelMessageFunc_OnPicked::InitVar(a1: (int)&savedregs);
  return this;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104955F0
// Name: public: static char const __near * CAttributeDetailTypePickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeDetailTypePickerPanel::GetPanelClassName()
{
  return "CAttributeDetailTypePickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x10495600
// Name: public: static void CAttributeDetailTypePickerPanel::PanelMessageFunc_OnPicked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeDetailTypePickerPanel::PanelMessageFunc_OnPicked::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeDetailTypePickerPanel::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded )
  {
    `CAttributeDetailTypePickerPanel::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeFilePickerPanel::`vcall'{884,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeDetailTypePickerPanel");
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
// Address: 0x10495690
// Name: private: void CAttributeDetailTypePickerPanel::AddDetailTypesToList(struct PickerList_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeDetailTypePickerPanel::AddDetailTypesToList(
        CAttributeDetailTypePickerPanel *this,
        PickerList_t *list)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IBaseFileSystem *v4; // eax
  KeyValues *FirstTrueSubKey; // edi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  PickerInfo_t *m_pMemory; // ecx
  int v10; // eax
  PickerInfo_t *v11; // ebx
  PickerInfo_t *v12; // ebx
  KeyValues *pDetailTypes; // [esp+8h] [ebp-4h]
  PickerList_t *lista; // [esp+14h] [ebp+8h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: DETAILTYPE_FILE);
    pDetailTypes = v3;
  }
  else
  {
    pDetailTypes = nullptr;
    v3 = nullptr;
  }
  if ( g_pFullFileSystem != nullptr )
    v4 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v4 = nullptr;
  if ( !KeyValues::LoadFromFile(
          this: v3,
          filesystem: v4,
          resourceName: (char *)DETAILTYPE_FILE,
          pathID: "GAME",
          pfnEvaluateSymbolProc: nullptr) )
  {
    _Warning(a1: "Unable to load detail prop file '%s'\n", DETAILTYPE_FILE);
    goto LABEL_16;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: v3);
  if ( FirstTrueSubKey == nullptr )
  {
LABEL_16:
    KeyValues::deleteThis(this: v3);
    return;
  }
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
    v10 = list->m_Choices.m_Size - m_Size - 1;
    list->m_Choices.m_pElements = m_pMemory;
    if ( v10 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 8 * v10);
    lista = (PickerList_t *)(8 * m_Size);
    v11 = &list->m_Choices.m_Memory.m_pMemory[m_Size];
    v11->m_pChoiceString = KeyValues::GetName(this: FirstTrueSubKey);
    v12 = (PickerInfo_t *)((char *)lista + (unsigned int)list->m_Choices.m_Memory.m_pMemory);
    v12->m_pChoiceValue = KeyValues::GetName(this: FirstTrueSubKey);
    FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
  }
  while ( FirstTrueSubKey != nullptr );
  KeyValues::deleteThis(this: pDetailTypes);
}

//------------------------------------------------------------------------------
// Address: 0x104957C0
// Name: private: virtual void CAttributeDetailTypePickerPanel::ShowPickerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeDetailTypePickerPanel::ShowPickerDialog(CAttributeDetailTypePickerPanel *this)
{
  CPickerFrame *v2; // eax
  CPickerFrame *v3; // esi
  PickerList_t detailTypeList; // [esp+Ch] [ebp-18h] BYREF

  v2 = (CPickerFrame *)operator new(nSize: 0x224u);
  if ( v2 != nullptr )
    v3 = CPickerFrame::CPickerFrame(
           this: v2,
           pParent: this,
           pTitle: "Select Detail Type",
           pPickerType: "Detail Type",
           pTextType: "detailTypeName");
  else
    v3 = nullptr;
  memset(&detailTypeList, 0, sizeof(detailTypeList));
  CAttributeDetailTypePickerPanel::AddDetailTypesToList(this, list: &detailTypeList);
  v3->AddActionSignalTarget_2(this: v3, a2: this);
  CPickerFrame::DoModal(this: v3, list: &detailTypeList, pContextKeyValues: nullptr);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&detailTypeList.m_Choices);
}

//------------------------------------------------------------------------------
// Address: 0x10495840
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeDetailTypePickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeDetailTypePickerPanel::GetMessageMap(CAttributeDetailTypePickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeDetailTypePickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeDetailTypePickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeDetailTypePickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeDetailTypePickerPanel");
  `CAttributeDetailTypePickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10495870
// Name: public: virtual struct PanelAnimationMap __near * CAttributeDetailTypePickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeDetailTypePickerPanel::GetAnimMap(CAttributeDetailTypePickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeDetailTypePickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x10495880
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeDetailTypePickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeDetailTypePickerPanel::GetKBMap(CAttributeDetailTypePickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeDetailTypePickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeDetailTypePickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeDetailTypePickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeDetailTypePickerPanel");
  `CAttributeDetailTypePickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104958B0
// Name: public: CAttributeDetailTypePickerPanel::CAttributeDetailTypePickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeDetailTypePickerPanel *__thiscall CAttributeDetailTypePickerPanel::CAttributeDetailTypePickerPanel(
        CAttributeDetailTypePickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeBasePickerPanel::CAttributeBasePickerPanel(this, parent, info);
  this->__vftable = (CAttributeDetailTypePickerPanel_vtbl *)&CAttributeDetailTypePickerPanel::`vftable';
  if ( `CAttributeDetailTypePickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeDetailTypePickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeDetailTypePickerPanel");
    v4->pfnClassName = CAttributeDetailTypePickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeDetailTypePickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeDetailTypePickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeDetailTypePickerPanel");
    v5->pfnClassName = CAttributeDetailTypePickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeDetailTypePickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeDetailTypePickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeDetailTypePickerPanel");
    v6->pfnClassName = CAttributeDetailTypePickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
  }
  CAttributeDetailTypePickerPanel::PanelMessageFunc_OnPicked::InitVar(a1: (int)&savedregs);
  return this;
}

} // namespace hammer_dll

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0049BCA0
// Name: public: static char const __near * CAttributeDetailTypePickerPanel::GetPanelClassName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl CAttributeDetailTypePickerPanel::GetPanelClassName()
{
  return "CAttributeDetailTypePickerPanel";
}

//------------------------------------------------------------------------------
// Address: 0x0049BCB0
// Name: public: static void CAttributeDetailTypePickerPanel::PanelMessageFunc_OnPicked::InitVar(void)
// Source: json
//------------------------------------------------------------------------------
static void __usercall CAttributeDetailTypePickerPanel::PanelMessageFunc_OnPicked::InitVar(int a1@<ebp>)
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
  if ( !`CAttributeDetailTypePickerPanel::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded )
  {
    `CAttributeDetailTypePickerPanel::PanelMessageFunc_OnPicked::InitVar'::`2'::bAdded = true;
    v5.m128i_i32[0] = (int) __thiscall CAttributeFilePickerPanel::`vcall'{884,{flat}};
    memset((char *)v5.m128i_i64 + 4, 0, 12);
    v1 = (CUtlVector<VMatrix,CUtlMemory<VMatrix,int> > *)vgui::FindOrAddPanelMessageMap(className: "CAttributeDetailTypePickerPanel");
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
// Address: 0x0049BD40
// Name: private: void CAttributeDetailTypePickerPanel::AddDetailTypesToList(struct PickerList_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeDetailTypePickerPanel::AddDetailTypesToList(
        CAttributeDetailTypePickerPanel *this,
        PickerList_t *list)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  IBaseFileSystem *v4; // eax
  KeyValues *FirstTrueSubKey; // edi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  PickerInfo_t *m_pMemory; // ecx
  int v10; // eax
  PickerInfo_t *v11; // ebx
  PickerInfo_t *v12; // ebx
  KeyValues *pDetailTypes; // [esp+8h] [ebp-4h]
  PickerList_t *lista; // [esp+14h] [ebp+8h]

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = KeyValues::KeyValues(this: v2, setName: DETAILTYPE_FILE);
    pDetailTypes = v3;
  }
  else
  {
    pDetailTypes = nullptr;
    v3 = nullptr;
  }
  if ( g_pFullFileSystem != nullptr )
    v4 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v4 = nullptr;
  if ( !KeyValues::LoadFromFile(
          this: v3,
          filesystem: v4,
          resourceName: DETAILTYPE_FILE,
          pathID: "GAME",
          pfnEvaluateSymbolProc: nullptr) )
  {
    _Warning(a1: "Unable to load detail prop file '%s'\n", DETAILTYPE_FILE);
    goto LABEL_16;
  }
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: v3);
  if ( FirstTrueSubKey == nullptr )
  {
LABEL_16:
    KeyValues::deleteThis(this: v3);
    return;
  }
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
    v10 = list->m_Choices.m_Size - m_Size - 1;
    list->m_Choices.m_pElements = m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 8 * v10);
    lista = (PickerList_t *)(8 * m_Size);
    v11 = &list->m_Choices.m_Memory.m_pMemory[m_Size];
    v11->m_pChoiceString = KeyValues::GetName(this: FirstTrueSubKey);
    v12 = (PickerInfo_t *)((char *)lista + (unsigned int)list->m_Choices.m_Memory.m_pMemory);
    v12->m_pChoiceValue = KeyValues::GetName(this: FirstTrueSubKey);
    FirstTrueSubKey = KeyValues::GetNextTrueSubKey(this: FirstTrueSubKey);
  }
  while ( FirstTrueSubKey != nullptr );
  KeyValues::deleteThis(this: pDetailTypes);
}

//------------------------------------------------------------------------------
// Address: 0x0049BE70
// Name: private: virtual void CAttributeDetailTypePickerPanel::ShowPickerDialog(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAttributeDetailTypePickerPanel::ShowPickerDialog(CAttributeDetailTypePickerPanel *this)
{
  CPickerFrame *v2; // eax
  CPickerFrame *v3; // esi
  PickerList_t detailTypeList; // [esp+Ch] [ebp-18h] BYREF

  v2 = (CPickerFrame *)MemAlloc_Alloc(nSize: 0x224u);
  if ( v2 != nullptr )
    v3 = CPickerFrame::CPickerFrame(
           this: v2,
           pParent: this,
           pTitle: "Select Detail Type",
           pPickerType: "Detail Type",
           pTextType: "detailTypeName");
  else
    v3 = nullptr;
  memset(&detailTypeList, 0, sizeof(detailTypeList));
  CAttributeDetailTypePickerPanel::AddDetailTypesToList(this, list: &detailTypeList);
  v3->AddActionSignalTarget_2(this: v3, a2: this);
  CPickerFrame::DoModal(this: v3, list: &detailTypeList, pContextKeyValues: nullptr);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&detailTypeList.m_Choices);
}

//------------------------------------------------------------------------------
// Address: 0x0049BEF0
// Name: public: virtual struct vgui::PanelMessageMap __near * CAttributeDetailTypePickerPanel::GetMessageMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelMessageMap *__thiscall CAttributeDetailTypePickerPanel::GetMessageMap(CAttributeDetailTypePickerPanel *this)
{
  vgui::PanelMessageMap *result; // eax

  if ( (`CAttributeDetailTypePickerPanel::GetMessageMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeDetailTypePickerPanel::GetMessageMap'::`2'::s_pMap;
  `CAttributeDetailTypePickerPanel::GetMessageMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelMessageMap(className: "CAttributeDetailTypePickerPanel");
  `CAttributeDetailTypePickerPanel::GetMessageMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049BF20
// Name: public: virtual struct PanelAnimationMap __near * CAttributeDetailTypePickerPanel::GetAnimMap(void)
// Source: json
//------------------------------------------------------------------------------
PanelAnimationMap *__thiscall CAttributeDetailTypePickerPanel::GetAnimMap(CAttributeDetailTypePickerPanel *this)
{
  return FindOrAddPanelAnimationMap(className: "CAttributeDetailTypePickerPanel");
}

//------------------------------------------------------------------------------
// Address: 0x0049BF30
// Name: public: virtual struct vgui::PanelKeyBindingMap __near * CAttributeDetailTypePickerPanel::GetKBMap(void)
// Source: json
//------------------------------------------------------------------------------
vgui::PanelKeyBindingMap *__thiscall CAttributeDetailTypePickerPanel::GetKBMap(CAttributeDetailTypePickerPanel *this)
{
  vgui::PanelKeyBindingMap *result; // eax

  if ( (`CAttributeDetailTypePickerPanel::GetKBMap'::`2'::`local static guard' & 1) != 0 )
    return `CAttributeDetailTypePickerPanel::GetKBMap'::`2'::s_pMap;
  `CAttributeDetailTypePickerPanel::GetKBMap'::`2'::`local static guard' |= 1u;
  result = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeDetailTypePickerPanel");
  `CAttributeDetailTypePickerPanel::GetKBMap'::`2'::s_pMap = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049BF70
// Name: public: CAttributeDetailTypePickerPanel::CAttributeDetailTypePickerPanel(class vgui::Panel __near *,struct AttributeWidgetInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CAttributeDetailTypePickerPanel *__thiscall CAttributeDetailTypePickerPanel::CAttributeDetailTypePickerPanel(
        CAttributeDetailTypePickerPanel *this,
        vgui::Panel *parent,
        const AttributeWidgetInfo_t *info)
{
  vgui::PanelMessageMap *v4; // esi
  PanelAnimationMap *v5; // esi
  vgui::PanelKeyBindingMap *v6; // esi
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  CAttributeBasePickerPanel::CAttributeBasePickerPanel(this, parent, info);
  this->__vftable = (CAttributeDetailTypePickerPanel_vtbl *)&CAttributeDetailTypePickerPanel::`vftable';
  if ( `CAttributeDetailTypePickerPanel::ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeDetailTypePickerPanel::ChainToMap'::`2'::chained = 1;
    v4 = vgui::FindOrAddPanelMessageMap(className: "CAttributeDetailTypePickerPanel");
    v4->pfnClassName = CAttributeDetailTypePickerPanel::GetPanelClassName;
    v4->baseMap = vgui::FindOrAddPanelMessageMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeDetailTypePickerPanel::ChainToAnimationMap'::`2'::chained == 0 )
  {
    `CAttributeDetailTypePickerPanel::ChainToAnimationMap'::`2'::chained = 1;
    v5 = FindOrAddPanelAnimationMap(className: "CAttributeDetailTypePickerPanel");
    v5->pfnClassName = CAttributeDetailTypePickerPanel::GetPanelClassName;
    v5->baseMap = FindOrAddPanelAnimationMap(className: "CAttributeBasePickerPanel");
  }
  if ( `CAttributeDetailTypePickerPanel::KB_ChainToMap'::`2'::chained == 0 )
  {
    `CAttributeDetailTypePickerPanel::KB_ChainToMap'::`2'::chained = 1;
    v6 = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeDetailTypePickerPanel");
    v6->pfnClassName = CAttributeDetailTypePickerPanel::GetPanelClassName;
    v6->baseMap = vgui::FindOrAddPanelKeyBindingMap(className: "CAttributeBasePickerPanel");
  }
  CAttributeDetailTypePickerPanel::PanelMessageFunc_OnPicked::InitVar(a1: (int)&savedregs);
  return this;
}

} // namespace sceneviewer
