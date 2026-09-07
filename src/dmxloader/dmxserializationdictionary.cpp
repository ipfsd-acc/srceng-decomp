// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dmxloader/dmxserializationdictionary.cpp
// Functions: 15
// ============================================================

#include "dmxloader\dmxserializationdictionary.h"

//------------------------------------------------------------------------------
// Address: 0x1000DC40
// Name: private: static bool CDmxSerializationDictionary::LessFunc(struct CDmxSerializationDictionary::DmxElementInfo_t const __near &,struct CDmxSerializationDictionary::DmxElementInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDmxSerializationDictionary::LessFunc(
        const CDmxSerializationDictionary::DmxElementInfo_t *lhs,
        const CDmxSerializationDictionary::DmxElementInfo_t *rhs)
{
  return lhs->m_pElement < rhs->m_pElement;
}

//------------------------------------------------------------------------------
// Address: 0x1024D660
// Name: public: int CDmxSerializationDictionary::FirstRootElement(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxSerializationDictionary::FirstRootElement(CDmxSerializationDictionary *this)
{
  int m_NumElements; // edx
  int result; // eax
  bool *i; // ecx

  m_NumElements = this->m_Dict.m_NumElements;
  result = 0;
  if ( m_NumElements <= 0 )
    return -1;
  for ( i = &this->m_Dict.m_Elements.m_pMemory->m_Data.m_bRoot; !*i; i += 24 )
  {
    if ( ++result >= m_NumElements )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1024D690
// Name: public: int CDmxSerializationDictionary::NextRootElement(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxSerializationDictionary::NextRootElement(CDmxSerializationDictionary *this, int h)
{
  int m_NumElements; // edx
  int result; // eax
  bool *i; // ecx

  m_NumElements = this->m_Dict.m_NumElements;
  result = h + 1;
  if ( h + 1 >= m_NumElements )
    return -1;
  for ( i = &this->m_Dict.m_Elements.m_pMemory[result].m_Data.m_bRoot; !*i; i += 24 )
  {
    if ( ++result >= m_NumElements )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1024D6D0
// Name: public: class CDmxElement __near * CDmxSerializationDictionary::GetRootElement(int)
// Source: json
//------------------------------------------------------------------------------
CDmxElement *__thiscall CDmxSerializationDictionary::GetRootElement(CDmxSerializationDictionary *this, int h)
{
  return this->m_Dict.m_Elements.m_pMemory[h].m_Data.m_pElement;
}

//------------------------------------------------------------------------------
// Address: 0x1024DE50
// Name: public: int CDmxSerializationDictionary::Find(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxSerializationDictionary::Find(CDmxSerializationDictionary *this, CDmxElement *pElement)
{
  CDmxSerializationDictionary::DmxElementInfo_t find; // [esp+0h] [ebp-8h] BYREF

  find.m_pElement = pElement;
  return CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::Find(
           this: &this->m_Dict,
           search: &find);
}

//------------------------------------------------------------------------------
// Address: 0x1024DE70
// Name: public: bool CDmxSerializationDictionary::ShouldInlineElement(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxSerializationDictionary::ShouldInlineElement(
        CDmxSerializationDictionary *this,
        CDmxElement *pElement)
{
  int v3; // eax
  CDmxSerializationDictionary::DmxElementInfo_t search; // [esp+4h] [ebp-8h] BYREF

  search.m_pElement = pElement;
  v3 = CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::Find(
         this: &this->m_Dict,
         &search);
  return v3 != -1 && !this->m_Dict.m_Elements.m_pMemory[v3].m_Data.m_bRoot;
}

//------------------------------------------------------------------------------
// Address: 0x1024DEB0
// Name: public: int CDmxSerializationDictionary::RootElementCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxSerializationDictionary::RootElementCount(CDmxSerializationDictionary *this)
{
  int v2; // edi
  int i; // eax

  v2 = 0;
  for ( i = CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::FirstInorder(this: &this->m_Dict);
        i != -1;
        i = CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::NextInorder(
              this: &this->m_Dict,
              i) )
  {
    if ( this->m_Dict.m_Elements.m_pMemory[i].m_Data.m_bRoot )
      ++v2;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1024DF50
// Name: public: CDmxSerializationDictionary::CDmxSerializationDictionary(int)
// Source: json
//------------------------------------------------------------------------------
CDmxSerializationDictionary *__thiscall CDmxSerializationDictionary::CDmxSerializationDictionary(
        CDmxSerializationDictionary *this,
        int nElementsHint)
{
  this->m_Dict.m_LessFunc = (bool (__cdecl *)(const CDmxSerializationDictionary::DmxElementInfo_t *, const CDmxSerializationDictionary::DmxElementInfo_t *))CDmxSerializationDictionary::LessFunc;
  this->m_Dict.m_Elements.m_pMemory = nullptr;
  this->m_Dict.m_Elements.m_nAllocationCount = nElementsHint;
  this->m_Dict.m_Elements.m_nGrowSize = 0;
  if ( nElementsHint != 0 )
    this->m_Dict.m_Elements.m_pMemory = (UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24 * nElementsHint);
  this->m_Dict.m_Root = -1;
  this->m_Dict.m_FirstFree = -1;
  this->m_Dict.m_NumElements = 0;
  this->m_Dict.m_LastAlloc.index = -1;
  this->m_Dict.m_pElements = this->m_Dict.m_Elements.m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1024E020
// Name: private: void CDmxSerializationDictionary::BuildElementList_R(class CDmxElement __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxSerializationDictionary::BuildElementList_R(
        CDmxSerializationDictionary *this,
        CDmxElement *pElement,
        bool bFlatMode,
        bool bIsRoot)
{
  vgui::ImageList *v4; // esi
  CDmxSerializationDictionary *v5; // edi
  int v6; // eax
  int Wide; // eax
  int v8; // ecx
  vgui::IImage *Image; // eax
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *v10; // ebx
  int m_Size; // edi
  int j; // esi
  CDmxElement *v13; // eax
  CDmxElement *Paint; // eax
  CDmxSerializationDictionary::DmxElementInfo_t info; // [esp+8h] [ebp-14h] BYREF
  CDmxSerializationDictionary::DmxElementInfo_t search; // [esp+10h] [ebp-Ch] BYREF
  CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl*)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int> > *p_m_Dict; // [esp+18h] [ebp-4h]
  int i; // [esp+2Ch] [ebp+10h]

  v4 = (vgui::ImageList *)pElement;
  v5 = this;
  p_m_Dict = &this->m_Dict;
  if ( pElement != nullptr )
  {
    search.m_pElement = pElement;
    v6 = CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::Find(
           this: &this->m_Dict,
           &search);
    if ( v6 == -1 )
    {
      if ( bFlatMode || (info.m_bRoot = false, bIsRoot) )
        info.m_bRoot = true;
      info.m_pElement = pElement;
      CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::Insert(
        this: &v5->m_Dict,
        insert: &info);
      Wide = vgui::Image::GetWide(this: (CVTFTexture *)pElement);
      v8 = 0;
      *(_DWORD *)&search.m_bRoot = Wide;
      i = 0;
      if ( Wide > 0 )
      {
        do
        {
          Image = vgui::ImageList::GetImage(this: v4, imageIndex: v8);
          if ( Image->__vftable == (vgui::IImage_vtbl *)1 )
          {
            Paint = (CDmxElement *)Image[2].Paint;
            if ( Paint != nullptr )
              CDmxSerializationDictionary::BuildElementList_R(this: v5, pElement: Paint, bFlatMode, bIsRoot: false);
          }
          else if ( Image->__vftable == (vgui::IImage_vtbl *)15 )
          {
            v10 = CDmxAttribute::GetArray<CDmxElement *>(this: (CDmxAttribute *)Image);
            m_Size = v10->m_Size;
            for ( j = 0; j < m_Size; ++j )
            {
              v13 = v10->m_Memory.m_pMemory[j];
              if ( v13 == nullptr )
                break;
              CDmxSerializationDictionary::BuildElementList_R(
                this: (CDmxSerializationDictionary *)p_m_Dict,
                pElement: v13,
                bFlatMode,
                bIsRoot: false);
            }
            v4 = (vgui::ImageList *)pElement;
            v5 = (CDmxSerializationDictionary *)p_m_Dict;
          }
          v8 = i + 1;
          i = v8;
        }
        while ( v8 < *(int *)&search.m_bRoot );
      }
    }
    else
    {
      v5->m_Dict.m_Elements.m_pMemory[v6].m_Data.m_bRoot = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024E110
// Name: public: void CDmxSerializationDictionary::BuildElementList(class CDmxElement __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxSerializationDictionary::BuildElementList(
        CDmxSerializationDictionary *this,
        CDmxElement *pElement,
        bool bFlatMode)
{
  CDmxSerializationDictionary::BuildElementList_R(this, pElement, bFlatMode, bIsRoot: true);
}

//------------------------------------------------------------------------------
// Address: 0x10327950
// Name: _GetPanelMessageMapDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl GetPanelMessageMapDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &dictionary_0.m_PanelMessageMapPool);
  CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::RemoveAll(this: &dictionary_0.m_MessageMaps);
  CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>(this: &dictionary_0.m_MessageMaps.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10327990
// Name: _GetPanelAnimationDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl GetPanelAnimationDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__()
{
  CClassMemoryPool<PanelAnimationMap>::Clear(this: &dictionary_1.m_PanelAnimationMapPool);
  CUtlDict<CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::RemoveAll(this: &dictionary_1.m_AnimationMaps);
  CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>(this: &dictionary_1.m_AnimationMaps.m_Elements.m_Tree);
  CUtlMemoryPool::~CUtlMemoryPool(this: &dictionary_1.m_PanelAnimationMapPool);
}

//------------------------------------------------------------------------------
// Address: 0x10327970
// Name: _dynamic_atexit_destructor_for__g_KBMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_KBMgr__()
{
  CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::~CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>(this: &g_KBMgr.m_Bindings);
}

//------------------------------------------------------------------------------
// Address: 0x10327980
// Name: _dynamic_atexit_destructor_for__g_ScriptSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ScriptSymbols__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ScriptSymbols);
}

//------------------------------------------------------------------------------
// Address: 0x103279C0
// Name: _dynamic_atexit_destructor_for__g_ButtonSoundNames__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ButtonSoundNames__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ButtonSoundNames);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10004300
// Name: private: static bool CDmxSerializationDictionary::LessFunc(struct CDmxSerializationDictionary::DmxElementInfo_t const __near &,struct CDmxSerializationDictionary::DmxElementInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDmxSerializationDictionary::LessFunc(
        const CDmxSerializationDictionary::DmxElementInfo_t *lhs,
        const CDmxSerializationDictionary::DmxElementInfo_t *rhs)
{
  return lhs->m_pElement < rhs->m_pElement;
}

//------------------------------------------------------------------------------
// Address: 0x1024D6C0
// Name: public: int CDmxSerializationDictionary::NextRootElement(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxSerializationDictionary::NextRootElement(CDmxSerializationDictionary *this, int h)
{
  int m_NumElements; // edx
  int result; // eax
  bool *i; // ecx

  m_NumElements = this->m_Dict.m_NumElements;
  result = h + 1;
  if ( h + 1 >= m_NumElements )
    return -1;
  for ( i = &this->m_Dict.m_Elements.m_pMemory[result].m_Data.m_bRoot; !*i; i += 24 )
  {
    if ( ++result >= m_NumElements )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1024D700
// Name: public: class CDmxElement __near * CDmxSerializationDictionary::GetRootElement(int)
// Source: json
//------------------------------------------------------------------------------
CDmxElement *__thiscall CDmxSerializationDictionary::GetRootElement(CDmxSerializationDictionary *this, int h)
{
  return this->m_Dict.m_Elements.m_pMemory[h].m_Data.m_pElement;
}

//------------------------------------------------------------------------------
// Address: 0x1024DE80
// Name: public: int CDmxSerializationDictionary::Find(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxSerializationDictionary::Find(CDmxSerializationDictionary *this, CDmxElement *pElement)
{
  CDmxSerializationDictionary::DmxElementInfo_t find; // [esp+0h] [ebp-8h] BYREF

  find.m_pElement = pElement;
  return CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::Find(
           this: &this->m_Dict,
           search: &find);
}

//------------------------------------------------------------------------------
// Address: 0x1024DEA0
// Name: public: bool CDmxSerializationDictionary::ShouldInlineElement(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxSerializationDictionary::ShouldInlineElement(
        CDmxSerializationDictionary *this,
        CDmxElement *pElement)
{
  int v3; // eax
  CDmxSerializationDictionary::DmxElementInfo_t search; // [esp+4h] [ebp-8h] BYREF

  search.m_pElement = pElement;
  v3 = CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::Find(
         this: &this->m_Dict,
         &search);
  return v3 != -1 && !this->m_Dict.m_Elements.m_pMemory[v3].m_Data.m_bRoot;
}

//------------------------------------------------------------------------------
// Address: 0x1024DEE0
// Name: public: int CDmxSerializationDictionary::RootElementCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxSerializationDictionary::RootElementCount(CDmxSerializationDictionary *this)
{
  int v2; // edi
  int i; // eax

  v2 = 0;
  for ( i = CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::FirstInorder(this: &this->m_Dict);
        i != -1;
        i = CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::NextInorder(
              this: &this->m_Dict,
              i) )
  {
    if ( this->m_Dict.m_Elements.m_pMemory[i].m_Data.m_bRoot )
      ++v2;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1024DF80
// Name: public: CDmxSerializationDictionary::CDmxSerializationDictionary(int)
// Source: json
//------------------------------------------------------------------------------
CDmxSerializationDictionary *__thiscall CDmxSerializationDictionary::CDmxSerializationDictionary(
        CDmxSerializationDictionary *this,
        int nElementsHint)
{
  this->m_Dict.m_LessFunc = (bool (__cdecl *)(const CDmxSerializationDictionary::DmxElementInfo_t *, const CDmxSerializationDictionary::DmxElementInfo_t *))CDmxSerializationDictionary::LessFunc;
  this->m_Dict.m_Elements.m_pMemory = nullptr;
  this->m_Dict.m_Elements.m_nAllocationCount = nElementsHint;
  this->m_Dict.m_Elements.m_nGrowSize = 0;
  if ( nElementsHint != 0 )
    this->m_Dict.m_Elements.m_pMemory = (UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24 * nElementsHint);
  this->m_Dict.m_Root = -1;
  this->m_Dict.m_FirstFree = -1;
  this->m_Dict.m_NumElements = 0;
  this->m_Dict.m_LastAlloc.index = -1;
  this->m_Dict.m_pElements = this->m_Dict.m_Elements.m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1024E050
// Name: private: void CDmxSerializationDictionary::BuildElementList_R(class CDmxElement __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxSerializationDictionary::BuildElementList_R(
        CDmxSerializationDictionary *this,
        CDmxElement *pElement,
        bool bFlatMode,
        bool bIsRoot)
{
  vgui::ImageList *v4; // esi
  CDmxSerializationDictionary *v5; // edi
  int v6; // eax
  int Wide; // eax
  int v8; // ecx
  vgui::IImage *Image; // eax
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *v10; // ebx
  int m_Size; // edi
  int j; // esi
  CDmxElement *v13; // eax
  CDmxElement *Paint; // eax
  CDmxSerializationDictionary::DmxElementInfo_t info; // [esp+8h] [ebp-14h] BYREF
  CDmxSerializationDictionary::DmxElementInfo_t search; // [esp+10h] [ebp-Ch] BYREF
  CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl*)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int> > *p_m_Dict; // [esp+18h] [ebp-4h]
  int i; // [esp+2Ch] [ebp+10h]

  v4 = (vgui::ImageList *)pElement;
  v5 = this;
  p_m_Dict = &this->m_Dict;
  if ( pElement != nullptr )
  {
    search.m_pElement = pElement;
    v6 = CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::Find(
           this: &this->m_Dict,
           &search);
    if ( v6 == -1 )
    {
      if ( bFlatMode || (info.m_bRoot = false, bIsRoot) )
        info.m_bRoot = true;
      info.m_pElement = pElement;
      CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::Insert(
        this: &v5->m_Dict,
        insert: &info);
      Wide = vgui::Image::GetWide(this: (CVTFTexture *)pElement);
      v8 = 0;
      *(_DWORD *)&search.m_bRoot = Wide;
      i = 0;
      if ( Wide > 0 )
      {
        do
        {
          Image = vgui::ImageList::GetImage(this: v4, imageIndex: v8);
          if ( Image->__vftable == (vgui::IImage_vtbl *)1 )
          {
            Paint = (CDmxElement *)Image[2].Paint;
            if ( Paint != nullptr )
              CDmxSerializationDictionary::BuildElementList_R(this: v5, pElement: Paint, bFlatMode, bIsRoot: false);
          }
          else if ( Image->__vftable == (vgui::IImage_vtbl *)15 )
          {
            v10 = CDmxAttribute::GetArray<CDmxElement *>(this: (CDmxAttribute *)Image);
            m_Size = v10->m_Size;
            for ( j = 0; j < m_Size; ++j )
            {
              v13 = v10->m_Memory.m_pMemory[j];
              if ( v13 == nullptr )
                break;
              CDmxSerializationDictionary::BuildElementList_R(
                this: (CDmxSerializationDictionary *)p_m_Dict,
                pElement: v13,
                bFlatMode,
                bIsRoot: false);
            }
            v4 = (vgui::ImageList *)pElement;
            v5 = (CDmxSerializationDictionary *)p_m_Dict;
          }
          v8 = i + 1;
          i = v8;
        }
        while ( v8 < *(int *)&search.m_bRoot );
      }
    }
    else
    {
      v5->m_Dict.m_Elements.m_pMemory[v6].m_Data.m_bRoot = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1024E140
// Name: public: void CDmxSerializationDictionary::BuildElementList(class CDmxElement __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxSerializationDictionary::BuildElementList(
        CDmxSerializationDictionary *this,
        CDmxElement *pElement,
        bool bFlatMode)
{
  CDmxSerializationDictionary::BuildElementList_R(this, pElement, bFlatMode, bIsRoot: true);
}

//------------------------------------------------------------------------------
// Address: 0x10327B40
// Name: _GetPanelMessageMapDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl GetPanelMessageMapDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &dictionary_0.m_PanelMessageMapPool);
  CUtlDict<CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::RemoveAll(this: &dictionary_0.m_MessageMaps);
  CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelMessageMapDictionary::PanelMessageMapDictionaryEntry,int>::Node_t,int>,int>>(this: &dictionary_0.m_MessageMaps.m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10327B80
// Name: _GetPanelAnimationDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl GetPanelAnimationDictionary_::_2_::_dynamic_atexit_destructor_for__dictionary__()
{
  CClassMemoryPool<PanelAnimationMap>::Clear(this: &dictionary_1.m_PanelAnimationMapPool);
  CUtlDict<CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::RemoveAll(this: &dictionary_1.m_AnimationMaps);
  CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int,CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,CPanelAnimationDictionary::PanelAnimationMapDictionaryEntry,int>::Node_t,int>,int>>(this: &dictionary_1.m_AnimationMaps.m_Elements.m_Tree);
  CUtlMemoryPool::~CUtlMemoryPool(this: &dictionary_1.m_PanelAnimationMapPool);
}

//------------------------------------------------------------------------------
// Address: 0x10327B60
// Name: _dynamic_atexit_destructor_for__g_KBMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_KBMgr__()
{
  CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>::~CUtlRBTree<CKeyBindingsMgr::KBContext_t,int,bool (__cdecl *)(CKeyBindingsMgr::KBContext_t const &,CKeyBindingsMgr::KBContext_t const &),CUtlMemory<UtlRBTreeNode_t<CKeyBindingsMgr::KBContext_t,int>,int>>(this: &g_KBMgr.m_Bindings);
}

//------------------------------------------------------------------------------
// Address: 0x10327B70
// Name: _dynamic_atexit_destructor_for__g_ScriptSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ScriptSymbols__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ScriptSymbols);
}

//------------------------------------------------------------------------------
// Address: 0x10327BB0
// Name: _dynamic_atexit_destructor_for__g_ButtonSoundNames__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ButtonSoundNames__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_ButtonSoundNames);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00447F40
// Name: private: static bool CDmxSerializationDictionary::LessFunc(struct CDmxSerializationDictionary::DmxElementInfo_t const __near &,struct CDmxSerializationDictionary::DmxElementInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl CDmxSerializationDictionary::LessFunc(const studiohdr_t *const *lhs, const studiohdr_t *const *rhs)
{
  return *lhs < *rhs;
}

//------------------------------------------------------------------------------
// Address: 0x00563A00
// Name: public: int CDmxSerializationDictionary::FirstRootElement(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxSerializationDictionary::FirstRootElement(CDmxSerializationDictionary *this)
{
  int m_NumElements; // edx
  int result; // eax
  bool *i; // ecx

  m_NumElements = this->m_Dict.m_NumElements;
  result = 0;
  if ( m_NumElements <= 0 )
    return -1;
  for ( i = &this->m_Dict.m_Elements.m_pMemory->m_Data.m_bRoot; !*i; i += 24 )
  {
    if ( ++result >= m_NumElements )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00563A30
// Name: public: int CDmxSerializationDictionary::NextRootElement(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxSerializationDictionary::NextRootElement(CDmxSerializationDictionary *this, int h)
{
  int m_NumElements; // edx
  int result; // eax
  bool *i; // ecx

  m_NumElements = this->m_Dict.m_NumElements;
  result = h + 1;
  if ( h + 1 >= m_NumElements )
    return -1;
  for ( i = &this->m_Dict.m_Elements.m_pMemory[result].m_Data.m_bRoot; !*i; i += 24 )
  {
    if ( ++result >= m_NumElements )
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00563A70
// Name: public: class CDmxElement __near * CDmxSerializationDictionary::GetRootElement(int)
// Source: json
//------------------------------------------------------------------------------
CDmxElement *__thiscall CDmxSerializationDictionary::GetRootElement(CDmxSerializationDictionary *this, int h)
{
  return this->m_Dict.m_Elements.m_pMemory[h].m_Data.m_pElement;
}

//------------------------------------------------------------------------------
// Address: 0x005641F0
// Name: public: int CDmxSerializationDictionary::Find(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxSerializationDictionary::Find(CDmxSerializationDictionary *this, CDmxElement *pElement)
{
  CDmxSerializationDictionary::DmxElementInfo_t find; // [esp+0h] [ebp-8h] BYREF

  find.m_pElement = pElement;
  return CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::Find(
           this: &this->m_Dict,
           search: &find);
}

//------------------------------------------------------------------------------
// Address: 0x00564210
// Name: public: bool CDmxSerializationDictionary::ShouldInlineElement(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmxSerializationDictionary::ShouldInlineElement(
        CDmxSerializationDictionary *this,
        CDmxElement *pElement)
{
  int v3; // eax
  CDmxSerializationDictionary::DmxElementInfo_t search; // [esp+4h] [ebp-8h] BYREF

  search.m_pElement = pElement;
  v3 = CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::Find(
         this: &this->m_Dict,
         &search);
  return v3 != -1 && !this->m_Dict.m_Elements.m_pMemory[v3].m_Data.m_bRoot;
}

//------------------------------------------------------------------------------
// Address: 0x00564250
// Name: public: int CDmxSerializationDictionary::RootElementCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmxSerializationDictionary::RootElementCount(CDmxSerializationDictionary *this)
{
  int v2; // edi
  int i; // eax

  v2 = 0;
  for ( i = CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::FirstInorder(this: &this->m_Dict);
        i != -1;
        i = CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::NextInorder(
              this: &this->m_Dict,
              i) )
  {
    if ( this->m_Dict.m_Elements.m_pMemory[i].m_Data.m_bRoot )
      ++v2;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x005642F0
// Name: public: CDmxSerializationDictionary::CDmxSerializationDictionary(int)
// Source: json
//------------------------------------------------------------------------------
CDmxSerializationDictionary *__thiscall CDmxSerializationDictionary::CDmxSerializationDictionary(
        CDmxSerializationDictionary *this,
        int nElementsHint)
{
  this->m_Dict.m_LessFunc = (bool (__cdecl *)(const CDmxSerializationDictionary::DmxElementInfo_t *, const CDmxSerializationDictionary::DmxElementInfo_t *))CDmxSerializationDictionary::LessFunc;
  this->m_Dict.m_Elements.m_pMemory = nullptr;
  this->m_Dict.m_Elements.m_nAllocationCount = nElementsHint;
  this->m_Dict.m_Elements.m_nGrowSize = 0;
  if ( nElementsHint != 0 )
    this->m_Dict.m_Elements.m_pMemory = (UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 24 * nElementsHint);
  this->m_Dict.m_Root = -1;
  this->m_Dict.m_FirstFree = -1;
  this->m_Dict.m_NumElements = 0;
  this->m_Dict.m_LastAlloc.index = -1;
  this->m_Dict.m_pElements = this->m_Dict.m_Elements.m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x005643C0
// Name: private: void CDmxSerializationDictionary::BuildElementList_R(class CDmxElement __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxSerializationDictionary::BuildElementList_R(
        CDmxSerializationDictionary *this,
        CDmxElement *pElement,
        bool bFlatMode,
        bool bIsRoot)
{
  CDmxElement *v4; // esi
  CDmxSerializationDictionary *v5; // edi
  int v6; // eax
  const char *Name; // eax
  int v8; // ecx
  CDmxAttribute *Attribute; // eax
  const CUtlVector<CDmxElement *,CUtlMemory<CDmxElement *,int> > *v10; // ebx
  int m_Size; // edi
  int j; // esi
  CDmxElement *v13; // eax
  CDmxElement *v14; // eax
  CDmxSerializationDictionary::DmxElementInfo_t info; // [esp+8h] [ebp-14h] BYREF
  CDmxSerializationDictionary::DmxElementInfo_t search; // [esp+10h] [ebp-Ch] BYREF
  CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl*)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int> > *p_m_Dict; // [esp+18h] [ebp-4h]
  int i; // [esp+2Ch] [ebp+10h]

  v4 = pElement;
  v5 = this;
  p_m_Dict = &this->m_Dict;
  if ( pElement != nullptr )
  {
    search.m_pElement = pElement;
    v6 = CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::Find(
           this: &this->m_Dict,
           &search);
    if ( v6 == -1 )
    {
      if ( bFlatMode || (info.m_bRoot = false, bIsRoot) )
        info.m_bRoot = true;
      info.m_pElement = pElement;
      CUtlRBTree<CDmxSerializationDictionary::DmxElementInfo_t,int,bool (__cdecl *)(CDmxSerializationDictionary::DmxElementInfo_t const &,CDmxSerializationDictionary::DmxElementInfo_t const &),CUtlMemory<UtlRBTreeNode_t<CDmxSerializationDictionary::DmxElementInfo_t,int>,int>>::Insert(
        this: &v5->m_Dict,
        insert: &info);
      Name = ConCommandBase::GetName(this: (ConCommandBase *)pElement);
      v8 = 0;
      *(_DWORD *)&search.m_bRoot = Name;
      i = 0;
      if ( (int)Name > 0 )
      {
        do
        {
          Attribute = CDmxElement::GetAttribute(this: v4, nIndex: v8);
          if ( Attribute->m_Type == AT_FIRST_VALUE_TYPE )
          {
            v14 = *(CDmxElement **)Attribute->m_pData;
            if ( v14 != nullptr )
              CDmxSerializationDictionary::BuildElementList_R(this: v5, pElement: v14, bFlatMode, bIsRoot: false);
          }
          else if ( Attribute->m_Type == AT_FIRST_ARRAY_TYPE )
          {
            v10 = CDmxAttribute::GetArray<CDmxElement *>(this: Attribute);
            m_Size = v10->m_Size;
            for ( j = 0; j < m_Size; ++j )
            {
              v13 = v10->m_Memory.m_pMemory[j];
              if ( v13 == nullptr )
                break;
              CDmxSerializationDictionary::BuildElementList_R(
                this: (CDmxSerializationDictionary *)p_m_Dict,
                pElement: v13,
                bFlatMode,
                bIsRoot: false);
            }
            v4 = pElement;
            v5 = (CDmxSerializationDictionary *)p_m_Dict;
          }
          v8 = i + 1;
          i = v8;
        }
        while ( v8 < *(int *)&search.m_bRoot );
      }
    }
    else
    {
      v5->m_Dict.m_Elements.m_pMemory[v6].m_Data.m_bRoot = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005644B0
// Name: public: void CDmxSerializationDictionary::BuildElementList(class CDmxElement __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmxSerializationDictionary::BuildElementList(
        CDmxSerializationDictionary *this,
        CDmxElement *pElement,
        bool bFlatMode)
{
  CDmxSerializationDictionary::BuildElementList_R(this, pElement, bFlatMode, bIsRoot: true);
}

} // namespace particle_import
