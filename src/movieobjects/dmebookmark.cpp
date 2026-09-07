// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmebookmark.cpp
// Functions: 19
// ============================================================

#include "movieobjects\dmebookmark.h"

//------------------------------------------------------------------------------
// Address: 0x004BD2B0
// Name: protected: virtual int CDmeBookmark::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmark::AllocatedSize(CDmeCurveInfo *this)
{
  return 92;
}

//------------------------------------------------------------------------------
// Address: 0x005689F0
// Name: protected: void CDmeBookmark::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmark::OnConstruction(CDmeBookmark *this)
{
  CDmaTime *p_m_Time; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  DmeTime_t value; // [esp+8h] [ebp-4h] BYREF

  p_m_Time = &this->m_Time;
  value.m_tms = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "time", type: AT_TIME, pMemory: &this->m_Time);
  p_m_Time->m_pAttribute = v3;
  CDmAttribute::SetValue<DmeTime_t>(this: v3, &value);
  value.m_tms = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "duration", type: AT_TIME, pMemory: &this->m_Duration);
  this->m_Duration.m_pAttribute = v4;
  CDmAttribute::SetValue<DmeTime_t>(this: v4, &value);
  this->m_Note.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "note",
                                type: AT_STRING,
                                pMemory: &this->m_Note);
}

//------------------------------------------------------------------------------
// Address: 0x00568A60
// Name: public: void CDmeBookmarkSet::ScaleBookmarkTimes(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmarkSet::ScaleBookmarkTimes(CDmeBookmarkSet *this, float scale)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // ecx
  DmeTime_t v7; // [esp+18h] [ebp-14h] BYREF
  DmeTime_t result; // [esp+1Ch] [ebp-10h] BYREF
  int nBookmarks; // [esp+20h] [ebp-Ch]
  DmeTime_t value; // [esp+24h] [ebp-8h] BYREF
  DmeTime_t v11; // [esp+28h] [ebp-4h] BYREF

  v3 = 0;
  nBookmarks = this->m_Bookmarks.m_Storage.m_Size;
  if ( nBookmarks > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Bookmarks.m_Storage.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeBookmark::m_classType) )
      {
        v11.m_tms = *(_DWORD *)&v5[1].m_Id.m_Value[4];
        DmeTime_t::operator*=(this: &v11, &result, f: scale);
        v6 = *(CDmAttribute **)&v5[1].m_Id.m_Value[8];
        value.m_tms = v11.m_tms;
        CDmAttribute::SetValue<DmeTime_t>(this: v6, &value);
        v11.m_tms = *(_DWORD *)&v5[1].m_Id.m_Value[12];
        DmeTime_t::operator*=(this: &v11, result: &v7, f: scale);
        value.m_tms = v11.m_tms;
        CDmAttribute::SetValue<DmeTime_t>(this: (CDmAttribute *)v5[1].m_Name.m_Storage.u.m_Id, &value);
      }
      ++v3;
    }
    while ( v3 < nBookmarks );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00568BC0
// Name: public: virtual bool CDmeBookmark::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBookmark::IsA(CDmeBookmark *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBookmark::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00568BF0
// Name: public: virtual int CDmeBookmark::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmark::GetInheritanceDepth(CDmeBookmark *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBookmark::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00568CA0
// Name: protected: virtual void CDmeBookmark::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmark::PerformConstruction(CDmeBookmark *this)
{
  CDmeFXClip::OnDestruction();
  CDmeBookmark::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00568D10
// Name: public: virtual bool CDmeBookmarkSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBookmarkSet::IsA(CDmeBookmarkSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBookmarkSet::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00568D40
// Name: public: virtual int CDmeBookmarkSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmarkSet::GetInheritanceDepth(CDmeBookmarkSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBookmarkSet::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00568D80
// Name: protected: virtual void CDmeBookmarkSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmarkSet::PerformConstruction(CDmeBookmarkSet *this)
{
  CDmeFXClip::OnDestruction();
  this->m_Bookmarks.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "bookmarks",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_Bookmarks);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Bookmarks.m_pAttribute, typeSymbol: CDmeBookmark::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005AEF20
// Name: _dynamic_initializer_for__CDmeBookmark::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBookmark::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBookmark::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBookmark pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AEF80
// Name: _dynamic_initializer_for__CDmeBookmarkSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBookmarkSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBookmarkSet::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBookmarkSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005B0BB0
// Name: _dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBookmark::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0BC0
// Name: _dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBookmarkSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AEF50
// Name: _dynamic_initializer_for__g_CDmeBookmark_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBookmark_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AEF60
// Name: _dynamic_initializer_for__g_CDmeBookmark_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBookmark_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBookmark_Helper,
           classname: "DmeBookmark",
           pFactory: &g_CDmeBookmark_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AEFB0
// Name: _dynamic_initializer_for__g_CDmeBookmarkSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBookmarkSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AEFC0
// Name: _dynamic_initializer_for__g_CDmeBookmarkSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBookmarkSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBookmarkSet_Helper,
           classname: "DmeBookmarkSet",
           pFactory: &g_CDmeBookmarkSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005B0BD0
// Name: _dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBookmarkSet_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B0BE0
// Name: _dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBookmark_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005C7740
// Name: protected: void CDmeBookmark::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmark::OnConstruction(CDmeBookmark *this)
{
  CDmaTime *p_m_Time; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  DmeTime_t value; // [esp+8h] [ebp-4h] BYREF

  p_m_Time = &this->m_Time;
  value.m_tms = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "time", type: AT_TIME, pMemory: &this->m_Time);
  p_m_Time->m_pAttribute = v3;
  CDmAttribute::SetValue<DmeTime_t>(this: v3, &value);
  value.m_tms = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "duration", type: AT_TIME, pMemory: &this->m_Duration);
  this->m_Duration.m_pAttribute = v4;
  CDmAttribute::SetValue<DmeTime_t>(this: v4, &value);
  this->m_Note.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "note",
                                type: AT_STRING,
                                pMemory: &this->m_Note);
}

//------------------------------------------------------------------------------
// Address: 0x005C77B0
// Name: public: void CDmeBookmarkSet::ScaleBookmarkTimes(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmarkSet::ScaleBookmarkTimes(CDmeBookmarkSet *this, float scale)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // ecx
  DmeTime_t v7; // [esp+18h] [ebp-14h] BYREF
  DmeTime_t result; // [esp+1Ch] [ebp-10h] BYREF
  int nBookmarks; // [esp+20h] [ebp-Ch]
  DmeTime_t value; // [esp+24h] [ebp-8h] BYREF
  DmeTime_t v11; // [esp+28h] [ebp-4h] BYREF

  v3 = 0;
  nBookmarks = this->m_Bookmarks.m_Storage.m_Size;
  if ( nBookmarks > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Bookmarks.m_Storage.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeBookmark::m_classType) )
      {
        v11.m_tms = *(_DWORD *)&v5[1].m_Id.m_Value[4];
        DmeTime_t::operator*=(this: &v11, &result, f: scale);
        v6 = *(CDmAttribute **)&v5[1].m_Id.m_Value[8];
        value.m_tms = v11.m_tms;
        CDmAttribute::SetValue<DmeTime_t>(this: v6, &value);
        v11.m_tms = *(_DWORD *)&v5[1].m_Id.m_Value[12];
        DmeTime_t::operator*=(this: &v11, result: &v7, f: scale);
        value.m_tms = v11.m_tms;
        CDmAttribute::SetValue<DmeTime_t>(this: (CDmAttribute *)v5[1].m_Name.m_Storage.u.m_Id, &value);
      }
      ++v3;
    }
    while ( v3 < nBookmarks );
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C7910
// Name: public: virtual bool CDmeBookmark::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBookmark::IsA(CDmeBookmark *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBookmark::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C7940
// Name: public: virtual int CDmeBookmark::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmark::GetInheritanceDepth(CDmeBookmark *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBookmark::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C79F0
// Name: protected: virtual void CDmeBookmark::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmark::PerformConstruction(CDmeBookmark *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeBookmark::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005C7A60
// Name: public: virtual bool CDmeBookmarkSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBookmarkSet::IsA(CDmeBookmarkSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBookmarkSet::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C7A90
// Name: public: virtual int CDmeBookmarkSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmarkSet::GetInheritanceDepth(CDmeBookmarkSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBookmarkSet::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C7AE0
// Name: protected: virtual void CDmeBookmarkSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmarkSet::PerformConstruction(CDmeBookmarkSet *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_Bookmarks.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "bookmarks",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_Bookmarks);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Bookmarks.m_pAttribute, typeSymbol: CDmeBookmark::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00680B50
// Name: _dynamic_initializer_for__CDmeBookmark::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBookmark::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBookmark::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBookmark pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00680BB0
// Name: _dynamic_initializer_for__CDmeBookmarkSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBookmarkSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBookmarkSet::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBookmarkSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00683260
// Name: _dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBookmark::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00683270
// Name: _dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBookmarkSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00680B80
// Name: _dynamic_initializer_for__g_CDmeBookmark_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBookmark_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00680B90
// Name: _dynamic_initializer_for__g_CDmeBookmark_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBookmark_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBookmark_Helper,
           classname: "DmeBookmark",
           pFactory: &g_CDmeBookmark_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00680BE0
// Name: _dynamic_initializer_for__g_CDmeBookmarkSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBookmarkSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00680BF0
// Name: _dynamic_initializer_for__g_CDmeBookmarkSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBookmarkSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBookmarkSet_Helper,
           classname: "DmeBookmarkSet",
           pFactory: &g_CDmeBookmarkSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00683280
// Name: _dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeBookmarkSet_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00683290
// Name: _dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeBookmark_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10594BC0
// Name: protected: void CDmeBookmark::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmark::OnConstruction(CDmeBookmark *this)
{
  CDmaTime *p_m_Time; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  DmeTime_t value; // [esp+8h] [ebp-4h] BYREF

  p_m_Time = &this->m_Time;
  value.m_tms = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "time", type: AT_TIME, pMemory: &this->m_Time);
  p_m_Time->m_pAttribute = v3;
  CDmAttribute::SetValue<DmeTime_t>(this: v3, &value);
  value.m_tms = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "duration", type: AT_TIME, pMemory: &this->m_Duration);
  this->m_Duration.m_pAttribute = v4;
  CDmAttribute::SetValue<DmeTime_t>(this: v4, &value);
  this->m_Note.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "note",
                                type: AT_STRING,
                                pMemory: &this->m_Note);
}

//------------------------------------------------------------------------------
// Address: 0x10594C30
// Name: public: void CDmeBookmarkSet::ScaleBookmarkTimes(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmarkSet::ScaleBookmarkTimes(CDmeBookmarkSet *this, float scale)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // ecx
  DmeTime_t v7; // [esp+10h] [ebp-14h] BYREF
  DmeTime_t v8; // [esp+14h] [ebp-10h] BYREF
  int m_Size; // [esp+18h] [ebp-Ch]
  DmeTime_t v10; // [esp+1Ch] [ebp-8h] BYREF
  DmeTime_t result; // [esp+20h] [ebp-4h] BYREF

  v3 = 0;
  m_Size = this->m_Bookmarks.m_Storage.m_Size;
  if ( m_Size > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Bookmarks.m_Storage.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeBookmark::m_classType) )
      {
        result.m_tms = *(_DWORD *)&v5[1].m_Id.m_Value[4];
        DmeTime_t::operator*=(this: &result, result: &v8, f: scale);
        v6 = *(CDmAttribute **)&v5[1].m_Id.m_Value[8];
        v10.m_tms = result.m_tms;
        CDmAttribute::SetValue<DmeTime_t>(this: v6, value: &v10);
        result.m_tms = *(_DWORD *)&v5[1].m_Id.m_Value[12];
        DmeTime_t::operator*=(this: &result, result: &v7, f: scale);
        v10.m_tms = result.m_tms;
        CDmAttribute::SetValue<DmeTime_t>(this: (CDmAttribute *)v5[1].m_Name.m_Storage.u.m_Id, value: &v10);
      }
      ++v3;
    }
    while ( v3 < m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10594D90
// Name: public: virtual bool CDmeBookmark::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBookmark::IsA(CDmeBookmark *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBookmark::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10594DC0
// Name: public: virtual int CDmeBookmark::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmark::GetInheritanceDepth(CDmeBookmark *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBookmark::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10594E70
// Name: protected: virtual void CDmeBookmark::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmark::PerformConstruction(CDmeBookmark *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeBookmark::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x10594EE0
// Name: public: virtual bool CDmeBookmarkSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBookmarkSet::IsA(CDmeBookmarkSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBookmarkSet::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10594F10
// Name: public: virtual int CDmeBookmarkSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmarkSet::GetInheritanceDepth(CDmeBookmarkSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBookmarkSet::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10594F50
// Name: protected: virtual void CDmeBookmarkSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmarkSet::PerformConstruction(CDmeBookmarkSet *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  this->m_Bookmarks.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "bookmarks",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_Bookmarks);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Bookmarks.m_pAttribute, typeSymbol: CDmeBookmark::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x105C96B0
// Name: _dynamic_initializer_for__CDmeBookmark::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBookmark::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBookmark::s_Allocator,
    blockSize: 0x5Cu,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBookmark pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9710
// Name: _dynamic_initializer_for__CDmeBookmarkSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBookmarkSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBookmarkSet::s_Allocator,
    blockSize: 0x60u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBookmarkSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CDA50
// Name: _dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBookmark::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CDA60
// Name: _dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBookmarkSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C96E0
// Name: _dynamic_initializer_for__g_CDmeBookmark_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBookmark_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C96F0
// Name: _dynamic_initializer_for__g_CDmeBookmark_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBookmark_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBookmark_Helper,
           classname: "DmeBookmark",
           pFactory: &g_CDmeBookmark_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C9740
// Name: _dynamic_initializer_for__g_CDmeBookmarkSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBookmarkSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9750
// Name: _dynamic_initializer_for__g_CDmeBookmarkSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBookmarkSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBookmarkSet_Helper,
           classname: "DmeBookmarkSet",
           pFactory: &g_CDmeBookmarkSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CDA70
// Name: _dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeBookmarkSet_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CDA80
// Name: _dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeBookmark_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x00565960
// Name: protected: void CDmeBookmark::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmark::OnConstruction(CDmeBookmark *this)
{
  CDmaTime *p_m_Time; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  DmeTime_t value; // [esp+8h] [ebp-4h] BYREF

  p_m_Time = &this->m_Time;
  value.m_tms = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "time", type: AT_TIME, pMemory: &this->m_Time);
  p_m_Time->m_pAttribute = v3;
  CDmAttribute::SetValue<DmeTime_t>(this: v3, &value);
  value.m_tms = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "duration", type: AT_TIME, pMemory: &this->m_Duration);
  this->m_Duration.m_pAttribute = v4;
  CDmAttribute::SetValue<DmeTime_t>(this: v4, &value);
  this->m_Note.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "note",
                                type: AT_STRING,
                                pMemory: &this->m_Note);
}

//------------------------------------------------------------------------------
// Address: 0x005659D0
// Name: public: void CDmeBookmarkSet::ScaleBookmarkTimes(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmarkSet::ScaleBookmarkTimes(CDmeBookmarkSet *this, float scale)
{
  int v3; // edi
  int v4; // eax
  int v5; // esi
  CDmAttribute *v6; // ecx
  DmeTime_t v7; // [esp+18h] [ebp-14h] BYREF
  DmeTime_t result; // [esp+1Ch] [ebp-10h] BYREF
  int nBookmarks; // [esp+20h] [ebp-Ch]
  DmeTime_t value; // [esp+24h] [ebp-8h] BYREF
  DmeTime_t v11; // [esp+28h] [ebp-4h] BYREF

  v3 = 0;
  nBookmarks = this->m_Bookmarks.m_Storage.m_Size;
  if ( nBookmarks > 0 )
  {
    do
    {
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_Bookmarks.m_Storage.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
             a1: v4,
             a2: CDmeBookmark::m_classType.u) != 0 )
      {
        v11.m_tms = *(_DWORD *)(v5 + 76);
        DmeTime_t::operator*=(this: &v11, &result, f: scale);
        v6 = *(CDmAttribute **)(v5 + 80);
        value.m_tms = v11.m_tms;
        CDmAttribute::SetValue<DmeTime_t>(this: v6, &value);
        v11.m_tms = *(_DWORD *)(v5 + 84);
        DmeTime_t::operator*=(this: &v11, result: &v7, f: scale);
        value.m_tms = v11.m_tms;
        CDmAttribute::SetValue<DmeTime_t>(this: *(CDmAttribute **)(v5 + 88), &value);
      }
      ++v3;
    }
    while ( v3 < nBookmarks );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00565B30
// Name: public: virtual bool CDmeBookmark::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBookmark::IsA(CDmeBookmark *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBookmark::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00565B60
// Name: public: virtual int CDmeBookmark::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmark::GetInheritanceDepth(CDmeBookmark *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBookmark::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00565C10
// Name: protected: virtual void CDmeBookmark::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmark::PerformConstruction(CDmeBookmark *this)
{
  CDmeFXClip::OnDestruction();
  CDmeBookmark::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00565C80
// Name: public: virtual bool CDmeBookmarkSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBookmarkSet::IsA(CDmeBookmarkSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBookmarkSet::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00565CB0
// Name: public: virtual int CDmeBookmarkSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmarkSet::GetInheritanceDepth(CDmeBookmarkSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBookmarkSet::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00565CF0
// Name: protected: virtual void CDmeBookmarkSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmarkSet::PerformConstruction(CDmeBookmarkSet *this)
{
  CDmeFXClip::OnDestruction();
  this->m_Bookmarks.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "bookmarks",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_Bookmarks);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Bookmarks.m_pAttribute, typeSymbol: CDmeBookmark::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0059D110
// Name: _dynamic_initializer_for__CDmeBookmark::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBookmark::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBookmark::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBookmark pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D170
// Name: _dynamic_initializer_for__CDmeBookmarkSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBookmarkSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBookmarkSet::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBookmarkSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059F840
// Name: _dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBookmark::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059F850
// Name: _dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBookmarkSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059D140
// Name: _dynamic_initializer_for__g_CDmeBookmark_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBookmark_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D150
// Name: _dynamic_initializer_for__g_CDmeBookmark_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBookmark_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBookmark_Helper,
           classname: "DmeBookmark",
           pFactory: &g_CDmeBookmark_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059D1A0
// Name: _dynamic_initializer_for__g_CDmeBookmarkSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBookmarkSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059D1B0
// Name: _dynamic_initializer_for__g_CDmeBookmarkSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBookmarkSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBookmarkSet_Helper,
           classname: "DmeBookmarkSet",
           pFactory: &g_CDmeBookmarkSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059F860
// Name: _dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBookmarkSet_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059F870
// Name: _dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBookmark_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005AEA10
// Name: protected: void CDmeBookmark::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmark::OnConstruction(CDmeBookmark *this)
{
  CDmaTime *p_m_Time; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  DmeTime_t value; // [esp+8h] [ebp-4h] BYREF

  p_m_Time = &this->m_Time;
  value.m_tms = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "time", type: AT_TIME, pMemory: &this->m_Time);
  p_m_Time->m_pAttribute = v3;
  CDmAttribute::SetValue<DmeTime_t>(this: v3, &value);
  value.m_tms = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "duration", type: AT_TIME, pMemory: &this->m_Duration);
  this->m_Duration.m_pAttribute = v4;
  CDmAttribute::SetValue<DmeTime_t>(this: v4, &value);
  this->m_Note.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "note",
                                type: AT_STRING,
                                pMemory: &this->m_Note);
}

//------------------------------------------------------------------------------
// Address: 0x005AEA80
// Name: public: void CDmeBookmarkSet::ScaleBookmarkTimes(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmarkSet::ScaleBookmarkTimes(CDmeBookmarkSet *this, float scale)
{
  int v3; // edi
  int v4; // eax
  int v5; // esi
  CDmAttribute *v6; // ecx
  DmeTime_t v7; // [esp+18h] [ebp-14h] BYREF
  DmeTime_t result; // [esp+1Ch] [ebp-10h] BYREF
  int nBookmarks; // [esp+20h] [ebp-Ch]
  DmeTime_t value; // [esp+24h] [ebp-8h] BYREF
  DmeTime_t v11; // [esp+28h] [ebp-4h] BYREF

  v3 = 0;
  nBookmarks = this->m_Bookmarks.m_Storage.m_Size;
  if ( nBookmarks > 0 )
  {
    do
    {
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_Bookmarks.m_Storage.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
             a1: v4,
             a2: CDmeBookmark::m_classType.u) != 0 )
      {
        v11.m_tms = *(_DWORD *)(v5 + 76);
        DmeTime_t::operator*=(this: &v11, &result, f: scale);
        v6 = *(CDmAttribute **)(v5 + 80);
        value.m_tms = v11.m_tms;
        CDmAttribute::SetValue<DmeTime_t>(this: v6, &value);
        v11.m_tms = *(_DWORD *)(v5 + 84);
        DmeTime_t::operator*=(this: &v11, result: &v7, f: scale);
        value.m_tms = v11.m_tms;
        CDmAttribute::SetValue<DmeTime_t>(this: *(CDmAttribute **)(v5 + 88), &value);
      }
      ++v3;
    }
    while ( v3 < nBookmarks );
  }
}

//------------------------------------------------------------------------------
// Address: 0x005AEBE0
// Name: public: virtual bool CDmeBookmark::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBookmark::IsA(CDmeBookmark *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBookmark::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AEC10
// Name: public: virtual int CDmeBookmark::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmark::GetInheritanceDepth(CDmeBookmark *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBookmark::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AECC0
// Name: protected: virtual void CDmeBookmark::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmark::PerformConstruction(CDmeBookmark *this)
{
  CDmeFXClip::OnDestruction();
  CDmeBookmark::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005AED30
// Name: public: virtual bool CDmeBookmarkSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBookmarkSet::IsA(CDmeBookmarkSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBookmarkSet::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AED60
// Name: public: virtual int CDmeBookmarkSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmarkSet::GetInheritanceDepth(CDmeBookmarkSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBookmarkSet::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AEDA0
// Name: protected: virtual void CDmeBookmarkSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmarkSet::PerformConstruction(CDmeBookmarkSet *this)
{
  CDmeFXClip::OnDestruction();
  this->m_Bookmarks.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "bookmarks",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_Bookmarks);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Bookmarks.m_pAttribute, typeSymbol: CDmeBookmark::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005F1DA0
// Name: _dynamic_initializer_for__CDmeBookmark::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBookmark::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBookmark::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBookmark pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F1E00
// Name: _dynamic_initializer_for__CDmeBookmarkSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBookmarkSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBookmarkSet::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBookmarkSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F4B50
// Name: _dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBookmark::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F4B60
// Name: _dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBookmarkSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F1DD0
// Name: _dynamic_initializer_for__g_CDmeBookmark_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBookmark_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F1DE0
// Name: _dynamic_initializer_for__g_CDmeBookmark_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBookmark_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBookmark_Helper,
           classname: "DmeBookmark",
           pFactory: &g_CDmeBookmark_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F1E30
// Name: _dynamic_initializer_for__g_CDmeBookmarkSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBookmarkSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F1E40
// Name: _dynamic_initializer_for__g_CDmeBookmarkSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBookmarkSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBookmarkSet_Helper,
           classname: "DmeBookmarkSet",
           pFactory: &g_CDmeBookmarkSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F4B70
// Name: _dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBookmarkSet_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F4B80
// Name: _dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBookmark_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0047E6F0
// Name: protected: virtual int CDmeBookmark::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmark::AllocatedSize(CDmeCurveInfo *this)
{
  return 92;
}

//------------------------------------------------------------------------------
// Address: 0x0052B9B0
// Name: protected: void CDmeBookmark::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmark::OnConstruction(CDmeBookmark *this)
{
  CDmaTime *p_m_Time; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  DmeTime_t value; // [esp+8h] [ebp-4h] BYREF

  p_m_Time = &this->m_Time;
  value.m_tms = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "time", type: AT_TIME, pMemory: &this->m_Time);
  p_m_Time->m_pAttribute = v3;
  CDmAttribute::SetValue<DmeTime_t>(this: v3, &value);
  value.m_tms = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "duration", type: AT_TIME, pMemory: &this->m_Duration);
  this->m_Duration.m_pAttribute = v4;
  CDmAttribute::SetValue<DmeTime_t>(this: v4, &value);
  this->m_Note.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "note",
                                type: AT_STRING,
                                pMemory: &this->m_Note);
}

//------------------------------------------------------------------------------
// Address: 0x0052BA20
// Name: public: void CDmeBookmarkSet::ScaleBookmarkTimes(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmarkSet::ScaleBookmarkTimes(CDmeBookmarkSet *this, float scale)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // ecx
  DmeTime_t v7; // [esp+18h] [ebp-14h] BYREF
  DmeTime_t result; // [esp+1Ch] [ebp-10h] BYREF
  int nBookmarks; // [esp+20h] [ebp-Ch]
  DmeTime_t value; // [esp+24h] [ebp-8h] BYREF
  DmeTime_t v11; // [esp+28h] [ebp-4h] BYREF

  v3 = 0;
  nBookmarks = this->m_Bookmarks.m_Storage.m_Size;
  if ( nBookmarks > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Bookmarks.m_Storage.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeBookmark::m_classType) )
      {
        v11.m_tms = *(_DWORD *)&v5[1].m_Id.m_Value[4];
        DmeTime_t::operator*=(this: &v11, &result, f: scale);
        v6 = *(CDmAttribute **)&v5[1].m_Id.m_Value[8];
        value.m_tms = v11.m_tms;
        CDmAttribute::SetValue<DmeTime_t>(this: v6, &value);
        v11.m_tms = *(_DWORD *)&v5[1].m_Id.m_Value[12];
        DmeTime_t::operator*=(this: &v11, result: &v7, f: scale);
        value.m_tms = v11.m_tms;
        CDmAttribute::SetValue<DmeTime_t>(this: (CDmAttribute *)v5[1].m_Name.m_Storage.u.m_Id, &value);
      }
      ++v3;
    }
    while ( v3 < nBookmarks );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052BB80
// Name: public: virtual bool CDmeBookmark::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBookmark::IsA(CDmeBookmark *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBookmark::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052BBB0
// Name: public: virtual int CDmeBookmark::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmark::GetInheritanceDepth(CDmeBookmark *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBookmark::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052BC60
// Name: protected: virtual void CDmeBookmark::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmark::PerformConstruction(CDmeBookmark *this)
{
  CDmeFXClip::OnDestruction();
  CDmeBookmark::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0052BCD0
// Name: public: virtual bool CDmeBookmarkSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBookmarkSet::IsA(CDmeBookmarkSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBookmarkSet::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052BD00
// Name: public: virtual int CDmeBookmarkSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmarkSet::GetInheritanceDepth(CDmeBookmarkSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBookmarkSet::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052BD40
// Name: protected: virtual void CDmeBookmarkSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmarkSet::PerformConstruction(CDmeBookmarkSet *this)
{
  CDmeFXClip::OnDestruction();
  this->m_Bookmarks.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "bookmarks",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_Bookmarks);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Bookmarks.m_pAttribute, typeSymbol: CDmeBookmark::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0056D4C0
// Name: _dynamic_initializer_for__CDmeBookmark::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBookmark::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBookmark::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBookmark pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056D520
// Name: _dynamic_initializer_for__CDmeBookmarkSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBookmarkSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBookmarkSet::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBookmarkSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056F340
// Name: _dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBookmark::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056F350
// Name: _dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBookmarkSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056D4F0
// Name: _dynamic_initializer_for__g_CDmeBookmark_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBookmark_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056D500
// Name: _dynamic_initializer_for__g_CDmeBookmark_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBookmark_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBookmark_Helper,
           classname: "DmeBookmark",
           pFactory: &g_CDmeBookmark_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056D550
// Name: _dynamic_initializer_for__g_CDmeBookmarkSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBookmarkSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056D560
// Name: _dynamic_initializer_for__g_CDmeBookmarkSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBookmarkSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBookmarkSet_Helper,
           classname: "DmeBookmarkSet",
           pFactory: &g_CDmeBookmarkSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056F360
// Name: _dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBookmarkSet_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056F370
// Name: _dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBookmark_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00469770
// Name: public: class CDmaElementArray<class CDmeBookmark> __near & CDmeBookmarkSet::GetBookmarks(void)
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmeBookmarkSet::GetBookmarks(CDmeTransform *this)
{
  return &this->m_Position;
}

//------------------------------------------------------------------------------
// Address: 0x00533E30
// Name: protected: void CDmeBookmark::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmark::OnConstruction(CDmeBookmark *this)
{
  CDmaTime *p_m_Time; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  DmeTime_t value; // [esp+8h] [ebp-4h] BYREF

  p_m_Time = &this->m_Time;
  value.m_tms = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "time", type: AT_TIME, pMemory: &this->m_Time);
  p_m_Time->m_pAttribute = v3;
  CDmAttribute::SetValue<DmeTime_t>(this: v3, &value);
  value.m_tms = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "duration", type: AT_TIME, pMemory: &this->m_Duration);
  this->m_Duration.m_pAttribute = v4;
  CDmAttribute::SetValue<DmeTime_t>(this: v4, &value);
  this->m_Note.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "note",
                                type: AT_STRING,
                                pMemory: &this->m_Note);
}

//------------------------------------------------------------------------------
// Address: 0x00533EA0
// Name: public: void CDmeBookmarkSet::ScaleBookmarkTimes(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmarkSet::ScaleBookmarkTimes(CDmeBookmarkSet *this, float scale)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // ecx
  DmeTime_t v7; // [esp+18h] [ebp-14h] BYREF
  DmeTime_t result; // [esp+1Ch] [ebp-10h] BYREF
  int nBookmarks; // [esp+20h] [ebp-Ch]
  DmeTime_t value; // [esp+24h] [ebp-8h] BYREF
  DmeTime_t v11; // [esp+28h] [ebp-4h] BYREF

  v3 = 0;
  nBookmarks = this->m_Bookmarks.m_Storage.m_Size;
  if ( nBookmarks > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Bookmarks.m_Storage.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeBookmark::m_classType) )
      {
        v11.m_tms = *(_DWORD *)&v5[1].m_Id.m_Value[4];
        DmeTime_t::operator*=(this: &v11, &result, f: scale);
        v6 = *(CDmAttribute **)&v5[1].m_Id.m_Value[8];
        value.m_tms = v11.m_tms;
        CDmAttribute::SetValue<DmeTime_t>(this: v6, &value);
        v11.m_tms = *(_DWORD *)&v5[1].m_Id.m_Value[12];
        DmeTime_t::operator*=(this: &v11, result: &v7, f: scale);
        value.m_tms = v11.m_tms;
        CDmAttribute::SetValue<DmeTime_t>(this: (CDmAttribute *)v5[1].m_Name.m_Storage.u.m_Id, &value);
      }
      ++v3;
    }
    while ( v3 < nBookmarks );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00534000
// Name: public: virtual bool CDmeBookmark::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBookmark::IsA(CDmeBookmark *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBookmark::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00534030
// Name: public: virtual int CDmeBookmark::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmark::GetInheritanceDepth(CDmeBookmark *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBookmark::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00534070
// Name: protected: virtual int CDmeBookmark::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmark::AllocatedSize(CDmeCurveInfo *this)
{
  return 92;
}

//------------------------------------------------------------------------------
// Address: 0x005340F0
// Name: protected: virtual void CDmeBookmark::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmark::PerformConstruction(CDmeBookmark *this)
{
  CDmeFXClip::OnDestruction();
  CDmeBookmark::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00534190
// Name: public: virtual bool CDmeBookmarkSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBookmarkSet::IsA(CDmeBookmarkSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBookmarkSet::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005341C0
// Name: public: virtual int CDmeBookmarkSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmarkSet::GetInheritanceDepth(CDmeBookmarkSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBookmarkSet::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00534200
// Name: protected: virtual void CDmeBookmarkSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmarkSet::PerformConstruction(CDmeBookmarkSet *this)
{
  CDmeFXClip::OnDestruction();
  this->m_Bookmarks.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "bookmarks",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_Bookmarks);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Bookmarks.m_pAttribute, typeSymbol: CDmeBookmark::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0057D5E0
// Name: _dynamic_initializer_for__CDmeBookmark::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBookmark::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBookmark::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBookmark pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D640
// Name: _dynamic_initializer_for__CDmeBookmarkSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBookmarkSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBookmarkSet::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBookmarkSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F470
// Name: _dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBookmark::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057F480
// Name: _dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBookmarkSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057D610
// Name: _dynamic_initializer_for__g_CDmeBookmark_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBookmark_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D620
// Name: _dynamic_initializer_for__g_CDmeBookmark_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBookmark_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBookmark_Helper,
           classname: "DmeBookmark",
           pFactory: &g_CDmeBookmark_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057D670
// Name: _dynamic_initializer_for__g_CDmeBookmarkSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBookmarkSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D680
// Name: _dynamic_initializer_for__g_CDmeBookmarkSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBookmarkSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBookmarkSet_Helper,
           classname: "DmeBookmarkSet",
           pFactory: &g_CDmeBookmarkSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057F490
// Name: _dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBookmarkSet_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057F4A0
// Name: _dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBookmark_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005F3920
// Name: protected: void CDmeBookmark::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmark::OnConstruction(CDmeBookmark *this)
{
  CDmaTime *p_m_Time; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  DmeTime_t value; // [esp+8h] [ebp-4h] BYREF

  p_m_Time = &this->m_Time;
  value.m_tms = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "time", type: AT_TIME, pMemory: &this->m_Time);
  p_m_Time->m_pAttribute = v3;
  CDmAttribute::SetValue<DmeTime_t>(this: v3, &value);
  value.m_tms = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "duration", type: AT_TIME, pMemory: &this->m_Duration);
  this->m_Duration.m_pAttribute = v4;
  CDmAttribute::SetValue<DmeTime_t>(this: v4, &value);
  this->m_Note.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "note",
                                type: AT_STRING,
                                pMemory: &this->m_Note);
}

//------------------------------------------------------------------------------
// Address: 0x005F3990
// Name: public: void CDmeBookmarkSet::ScaleBookmarkTimes(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmarkSet::ScaleBookmarkTimes(CDmeBookmarkSet *this, float scale)
{
  int v3; // edi
  int v4; // eax
  int v5; // esi
  CDmAttribute *v6; // ecx
  DmeTime_t v7; // [esp+18h] [ebp-14h] BYREF
  DmeTime_t result; // [esp+1Ch] [ebp-10h] BYREF
  int nBookmarks; // [esp+20h] [ebp-Ch]
  DmeTime_t value; // [esp+24h] [ebp-8h] BYREF
  DmeTime_t v11; // [esp+28h] [ebp-4h] BYREF

  v3 = 0;
  nBookmarks = this->m_Bookmarks.m_Storage.m_Size;
  if ( nBookmarks > 0 )
  {
    do
    {
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_Bookmarks.m_Storage.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
             a1: v4,
             a2: CDmeBookmark::m_classType.u) != 0 )
      {
        v11.m_tms = *(_DWORD *)(v5 + 76);
        DmeTime_t::operator*=(this: &v11, &result, f: scale);
        v6 = *(CDmAttribute **)(v5 + 80);
        value.m_tms = v11.m_tms;
        CDmAttribute::SetValue<DmeTime_t>(this: v6, &value);
        v11.m_tms = *(_DWORD *)(v5 + 84);
        DmeTime_t::operator*=(this: &v11, result: &v7, f: scale);
        value.m_tms = v11.m_tms;
        CDmAttribute::SetValue<DmeTime_t>(this: *(CDmAttribute **)(v5 + 88), &value);
      }
      ++v3;
    }
    while ( v3 < nBookmarks );
  }
}

//------------------------------------------------------------------------------
// Address: 0x005F3AF0
// Name: public: virtual bool CDmeBookmark::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBookmark::IsA(CDmeBookmark *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBookmark::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F3B20
// Name: public: virtual int CDmeBookmark::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmark::GetInheritanceDepth(CDmeBookmark *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBookmark::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F3BD0
// Name: protected: virtual void CDmeBookmark::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmark::PerformConstruction(CDmeBookmark *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeBookmark::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005F3C40
// Name: public: virtual bool CDmeBookmarkSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBookmarkSet::IsA(CDmeBookmarkSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBookmarkSet::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F3C70
// Name: public: virtual int CDmeBookmarkSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmarkSet::GetInheritanceDepth(CDmeBookmarkSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBookmarkSet::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F3CB0
// Name: protected: virtual void CDmeBookmarkSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmarkSet::PerformConstruction(CDmeBookmarkSet *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_Bookmarks.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "bookmarks",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_Bookmarks);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Bookmarks.m_pAttribute, typeSymbol: CDmeBookmark::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x006B2920
// Name: _dynamic_initializer_for__CDmeBookmark::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBookmark::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBookmark::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBookmark pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B2980
// Name: _dynamic_initializer_for__CDmeBookmarkSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBookmarkSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBookmarkSet::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBookmarkSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5D00
// Name: _dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBookmark::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5D10
// Name: _dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBookmarkSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B2950
// Name: _dynamic_initializer_for__g_CDmeBookmark_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBookmark_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B2960
// Name: _dynamic_initializer_for__g_CDmeBookmark_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBookmark_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBookmark_Helper,
           classname: "DmeBookmark",
           pFactory: &g_CDmeBookmark_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B29B0
// Name: _dynamic_initializer_for__g_CDmeBookmarkSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBookmarkSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B29C0
// Name: _dynamic_initializer_for__g_CDmeBookmarkSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBookmarkSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBookmarkSet_Helper,
           classname: "DmeBookmarkSet",
           pFactory: &g_CDmeBookmarkSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5D20
// Name: _dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeBookmarkSet_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B5D30
// Name: _dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeBookmark_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00535A80
// Name: public: class CDmaElementArray<class CDmeBookmark> __near & CDmeBookmarkSet::GetBookmarks(void)
// Source: json
//------------------------------------------------------------------------------
CDmaVar<Vector> *__thiscall CDmeBookmarkSet::GetBookmarks(CDmeTransform *this)
{
  return &this->m_Position;
}

//------------------------------------------------------------------------------
// Address: 0x00535A90
// Name: protected: void CDmeBookmark::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmark::OnConstruction(CDmeBookmark *this)
{
  CDmaTime *p_m_Time; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  DmeTime_t value; // [esp+8h] [ebp-4h] BYREF

  p_m_Time = &this->m_Time;
  value.m_tms = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "time", type: AT_TIME, pMemory: &this->m_Time);
  p_m_Time->m_pAttribute = v3;
  CDmAttribute::SetValue<DmeTime_t>(this: v3, &value);
  value.m_tms = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "duration", type: AT_TIME, pMemory: &this->m_Duration);
  this->m_Duration.m_pAttribute = v4;
  CDmAttribute::SetValue<DmeTime_t>(this: v4, &value);
  this->m_Note.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "note",
                                type: AT_STRING,
                                pMemory: &this->m_Note);
}

//------------------------------------------------------------------------------
// Address: 0x00535B00
// Name: public: void CDmeBookmarkSet::ScaleBookmarkTimes(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmarkSet::ScaleBookmarkTimes(CDmeBookmarkSet *this, float scale)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // ecx
  DmeTime_t v7; // [esp+18h] [ebp-14h] BYREF
  DmeTime_t result; // [esp+1Ch] [ebp-10h] BYREF
  int nBookmarks; // [esp+20h] [ebp-Ch]
  DmeTime_t value; // [esp+24h] [ebp-8h] BYREF
  DmeTime_t v11; // [esp+28h] [ebp-4h] BYREF

  v3 = 0;
  nBookmarks = this->m_Bookmarks.m_Storage.m_Size;
  if ( nBookmarks > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Bookmarks.m_Storage.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeBookmark::m_classType) )
      {
        v11.m_tms = *(_DWORD *)&v5[1].m_Id.m_Value[4];
        DmeTime_t::operator*=(this: &v11, &result, f: scale);
        v6 = *(CDmAttribute **)&v5[1].m_Id.m_Value[8];
        value.m_tms = v11.m_tms;
        CDmAttribute::SetValue<DmeTime_t>(this: v6, &value);
        v11.m_tms = *(_DWORD *)&v5[1].m_Id.m_Value[12];
        DmeTime_t::operator*=(this: &v11, result: &v7, f: scale);
        value.m_tms = v11.m_tms;
        CDmAttribute::SetValue<DmeTime_t>(this: (CDmAttribute *)v5[1].m_Name.m_Storage.u.m_Id, &value);
      }
      ++v3;
    }
    while ( v3 < nBookmarks );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00535C60
// Name: public: virtual bool CDmeBookmark::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBookmark::IsA(CDmeBookmark *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBookmark::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00535C90
// Name: public: virtual int CDmeBookmark::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmark::GetInheritanceDepth(CDmeBookmark *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBookmark::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00535CD0
// Name: protected: virtual int CDmeBookmark::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmark::AllocatedSize(CDmeCurveInfo *this)
{
  return 92;
}

//------------------------------------------------------------------------------
// Address: 0x00535D50
// Name: protected: virtual void CDmeBookmark::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmark::PerformConstruction(CDmeBookmark *this)
{
  CDmeFXClip::OnDestruction();
  CDmeBookmark::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00535DC0
// Name: public: virtual bool CDmeBookmarkSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBookmarkSet::IsA(CDmeBookmarkSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBookmarkSet::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00535DF0
// Name: public: virtual int CDmeBookmarkSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmarkSet::GetInheritanceDepth(CDmeBookmarkSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBookmarkSet::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00535E30
// Name: protected: virtual void CDmeBookmarkSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmarkSet::PerformConstruction(CDmeBookmarkSet *this)
{
  CDmeFXClip::OnDestruction();
  this->m_Bookmarks.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "bookmarks",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_Bookmarks);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Bookmarks.m_pAttribute, typeSymbol: CDmeBookmark::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0057F5C0
// Name: _dynamic_initializer_for__CDmeBookmark::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBookmark::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBookmark::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBookmark pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F620
// Name: _dynamic_initializer_for__CDmeBookmarkSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBookmarkSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBookmarkSet::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBookmarkSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00581450
// Name: _dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBookmark::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00581460
// Name: _dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBookmarkSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057F5F0
// Name: _dynamic_initializer_for__g_CDmeBookmark_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBookmark_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F600
// Name: _dynamic_initializer_for__g_CDmeBookmark_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBookmark_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBookmark_Helper,
           classname: "DmeBookmark",
           pFactory: &g_CDmeBookmark_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057F650
// Name: _dynamic_initializer_for__g_CDmeBookmarkSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBookmarkSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F660
// Name: _dynamic_initializer_for__g_CDmeBookmarkSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBookmarkSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBookmarkSet_Helper,
           classname: "DmeBookmarkSet",
           pFactory: &g_CDmeBookmarkSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00581470
// Name: _dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBookmarkSet_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00581480
// Name: _dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBookmark_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005A7970
// Name: protected: void CDmeBookmark::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmark::OnConstruction(CDmeBookmark *this)
{
  CDmaTime *p_m_Time; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  DmeTime_t value; // [esp+8h] [ebp-4h] BYREF

  p_m_Time = &this->m_Time;
  value.m_tms = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "time", type: AT_TIME, pMemory: &this->m_Time);
  p_m_Time->m_pAttribute = v3;
  CDmAttribute::SetValue<DmeTime_t>(this: v3, &value);
  value.m_tms = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "duration", type: AT_TIME, pMemory: &this->m_Duration);
  this->m_Duration.m_pAttribute = v4;
  CDmAttribute::SetValue<DmeTime_t>(this: v4, &value);
  this->m_Note.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "note",
                                type: AT_STRING,
                                pMemory: &this->m_Note);
}

//------------------------------------------------------------------------------
// Address: 0x005A79E0
// Name: public: void CDmeBookmarkSet::ScaleBookmarkTimes(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmarkSet::ScaleBookmarkTimes(CDmeBookmarkSet *this, float scale)
{
  int v3; // edi
  int v4; // eax
  int v5; // esi
  CDmAttribute *v6; // ecx
  DmeTime_t v7; // [esp+18h] [ebp-14h] BYREF
  DmeTime_t result; // [esp+1Ch] [ebp-10h] BYREF
  int nBookmarks; // [esp+20h] [ebp-Ch]
  DmeTime_t value; // [esp+24h] [ebp-8h] BYREF
  DmeTime_t v11; // [esp+28h] [ebp-4h] BYREF

  v3 = 0;
  nBookmarks = this->m_Bookmarks.m_Storage.m_Size;
  if ( nBookmarks > 0 )
  {
    do
    {
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_Bookmarks.m_Storage.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
             a1: v4,
             a2: CDmeBookmark::m_classType.u) != 0 )
      {
        v11.m_tms = *(_DWORD *)(v5 + 76);
        DmeTime_t::operator*=(this: &v11, &result, f: scale);
        v6 = *(CDmAttribute **)(v5 + 80);
        value.m_tms = v11.m_tms;
        CDmAttribute::SetValue<DmeTime_t>(this: v6, &value);
        v11.m_tms = *(_DWORD *)(v5 + 84);
        DmeTime_t::operator*=(this: &v11, result: &v7, f: scale);
        value.m_tms = v11.m_tms;
        CDmAttribute::SetValue<DmeTime_t>(this: *(CDmAttribute **)(v5 + 88), &value);
      }
      ++v3;
    }
    while ( v3 < nBookmarks );
  }
}

//------------------------------------------------------------------------------
// Address: 0x005A7B40
// Name: public: virtual bool CDmeBookmark::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBookmark::IsA(CDmeBookmark *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBookmark::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A7B70
// Name: public: virtual int CDmeBookmark::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmark::GetInheritanceDepth(CDmeBookmark *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBookmark::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A7C20
// Name: protected: virtual void CDmeBookmark::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmark::PerformConstruction(CDmeBookmark *this)
{
  CDmeFXClip::OnDestruction();
  CDmeBookmark::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005A7C90
// Name: public: virtual bool CDmeBookmarkSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBookmarkSet::IsA(CDmeBookmarkSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBookmarkSet::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A7CC0
// Name: public: virtual int CDmeBookmarkSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmarkSet::GetInheritanceDepth(CDmeBookmarkSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBookmarkSet::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A7D00
// Name: protected: virtual void CDmeBookmarkSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmarkSet::PerformConstruction(CDmeBookmarkSet *this)
{
  CDmeFXClip::OnDestruction();
  this->m_Bookmarks.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "bookmarks",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_Bookmarks);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Bookmarks.m_pAttribute, typeSymbol: CDmeBookmark::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005EAC50
// Name: _dynamic_initializer_for__CDmeBookmark::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBookmark::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBookmark::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBookmark pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EACB0
// Name: _dynamic_initializer_for__CDmeBookmarkSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBookmarkSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBookmarkSet::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBookmarkSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED9F0
// Name: _dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBookmark::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EDA00
// Name: _dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBookmarkSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EAC80
// Name: _dynamic_initializer_for__g_CDmeBookmark_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBookmark_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EAC90
// Name: _dynamic_initializer_for__g_CDmeBookmark_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBookmark_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBookmark_Helper,
           classname: "DmeBookmark",
           pFactory: &g_CDmeBookmark_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EACE0
// Name: _dynamic_initializer_for__g_CDmeBookmarkSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBookmarkSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EACF0
// Name: _dynamic_initializer_for__g_CDmeBookmarkSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBookmarkSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBookmarkSet_Helper,
           classname: "DmeBookmarkSet",
           pFactory: &g_CDmeBookmarkSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EDA10
// Name: _dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBookmarkSet_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005EDA20
// Name: _dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBookmark_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0048D200
// Name: protected: virtual int CDmeBookmark::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmark::AllocatedSize(CDmeCurveInfo *this)
{
  return 92;
}

//------------------------------------------------------------------------------
// Address: 0x0053A330
// Name: protected: void CDmeBookmark::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmark::OnConstruction(CDmeBookmark *this)
{
  CDmaTime *p_m_Time; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  DmeTime_t value; // [esp+8h] [ebp-4h] BYREF

  p_m_Time = &this->m_Time;
  value.m_tms = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "time", type: AT_TIME, pMemory: &this->m_Time);
  p_m_Time->m_pAttribute = v3;
  CDmAttribute::SetValue<DmeTime_t>(this: v3, &value);
  value.m_tms = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "duration", type: AT_TIME, pMemory: &this->m_Duration);
  this->m_Duration.m_pAttribute = v4;
  CDmAttribute::SetValue<DmeTime_t>(this: v4, &value);
  this->m_Note.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "note",
                                type: AT_STRING,
                                pMemory: &this->m_Note);
}

//------------------------------------------------------------------------------
// Address: 0x0053A3A0
// Name: public: void CDmeBookmarkSet::ScaleBookmarkTimes(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmarkSet::ScaleBookmarkTimes(CDmeBookmarkSet *this, float scale)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // ecx
  DmeTime_t v7; // [esp+18h] [ebp-14h] BYREF
  DmeTime_t result; // [esp+1Ch] [ebp-10h] BYREF
  int nBookmarks; // [esp+20h] [ebp-Ch]
  DmeTime_t value; // [esp+24h] [ebp-8h] BYREF
  DmeTime_t v11; // [esp+28h] [ebp-4h] BYREF

  v3 = 0;
  nBookmarks = this->m_Bookmarks.m_Storage.m_Size;
  if ( nBookmarks > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Bookmarks.m_Storage.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeBookmark::m_classType) )
      {
        v11.m_tms = *(_DWORD *)&v5[1].m_Id.m_Value[4];
        DmeTime_t::operator*=(this: &v11, &result, f: scale);
        v6 = *(CDmAttribute **)&v5[1].m_Id.m_Value[8];
        value.m_tms = v11.m_tms;
        CDmAttribute::SetValue<DmeTime_t>(this: v6, &value);
        v11.m_tms = *(_DWORD *)&v5[1].m_Id.m_Value[12];
        DmeTime_t::operator*=(this: &v11, result: &v7, f: scale);
        value.m_tms = v11.m_tms;
        CDmAttribute::SetValue<DmeTime_t>(this: (CDmAttribute *)v5[1].m_Name.m_Storage.u.m_Id, &value);
      }
      ++v3;
    }
    while ( v3 < nBookmarks );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053A500
// Name: public: virtual bool CDmeBookmark::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBookmark::IsA(CDmeBookmark *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBookmark::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0053A530
// Name: public: virtual int CDmeBookmark::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmark::GetInheritanceDepth(CDmeBookmark *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBookmark::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0053A5E0
// Name: protected: virtual void CDmeBookmark::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmark::PerformConstruction(CDmeBookmark *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeBookmark::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0053A650
// Name: public: virtual bool CDmeBookmarkSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBookmarkSet::IsA(CDmeBookmarkSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBookmarkSet::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0053A680
// Name: public: virtual int CDmeBookmarkSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmarkSet::GetInheritanceDepth(CDmeBookmarkSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBookmarkSet::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0053A6C0
// Name: protected: virtual void CDmeBookmarkSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmarkSet::PerformConstruction(CDmeBookmarkSet *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  this->m_Bookmarks.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "bookmarks",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_Bookmarks);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Bookmarks.m_pAttribute, typeSymbol: CDmeBookmark::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0057CE00
// Name: _dynamic_initializer_for__CDmeBookmark::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBookmark::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBookmark::s_Allocator,
    blockSize: 92,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBookmark pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CE60
// Name: _dynamic_initializer_for__CDmeBookmarkSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBookmarkSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBookmarkSet::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBookmarkSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EB40
// Name: _dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBookmark::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057EB50
// Name: _dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBookmarkSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057CE30
// Name: _dynamic_initializer_for__g_CDmeBookmark_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBookmark_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CE40
// Name: _dynamic_initializer_for__g_CDmeBookmark_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBookmark_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBookmark_Helper,
           classname: "DmeBookmark",
           pFactory: &g_CDmeBookmark_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057CE90
// Name: _dynamic_initializer_for__g_CDmeBookmarkSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBookmarkSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CEA0
// Name: _dynamic_initializer_for__g_CDmeBookmarkSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBookmarkSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBookmarkSet_Helper,
           classname: "DmeBookmarkSet",
           pFactory: &g_CDmeBookmarkSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057EB60
// Name: _dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBookmarkSet_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057EB70
// Name: _dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBookmark_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0063D3D0
// Name: protected: void CDmeBookmark::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmark::OnConstruction(CDmeBookmark *this)
{
  CDmaTime *p_m_Time; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  DmeTime_t value; // [esp+8h] [ebp-4h] BYREF

  p_m_Time = &this->m_Time;
  value.m_tms = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "time", type: AT_TIME, pMemory: &this->m_Time);
  p_m_Time->m_pAttribute = v3;
  CDmAttribute::SetValue<DmeTime_t>(this: v3, &value);
  value.m_tms = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "duration", type: AT_TIME, pMemory: &this->m_Duration);
  this->m_Duration.m_pAttribute = v4;
  CDmAttribute::SetValue<DmeTime_t>(this: v4, &value);
  this->m_Note.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "note",
                                type: AT_STRING,
                                pMemory: &this->m_Note);
}

//------------------------------------------------------------------------------
// Address: 0x0063D440
// Name: public: void CDmeBookmarkSet::ScaleBookmarkTimes(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmarkSet::ScaleBookmarkTimes(CDmeBookmarkSet *this, float scale)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmAttribute *v6; // ecx
  DmeTime_t v7; // [esp+18h] [ebp-14h] BYREF
  DmeTime_t result; // [esp+1Ch] [ebp-10h] BYREF
  int nBookmarks; // [esp+20h] [ebp-Ch]
  DmeTime_t value; // [esp+24h] [ebp-8h] BYREF
  DmeTime_t v11; // [esp+28h] [ebp-4h] BYREF

  v3 = 0;
  nBookmarks = this->m_Bookmarks.m_Storage.m_Size;
  if ( nBookmarks > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Bookmarks.m_Storage.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeBookmark::m_classType) )
      {
        v11.m_tms = *(_DWORD *)&v5[1].m_Id.m_Value[4];
        DmeTime_t::operator*=(this: &v11, &result, f: scale);
        v6 = *(CDmAttribute **)&v5[1].m_Id.m_Value[8];
        value.m_tms = v11.m_tms;
        CDmAttribute::SetValue<DmeTime_t>(this: v6, &value);
        v11.m_tms = *(_DWORD *)&v5[1].m_Id.m_Value[12];
        DmeTime_t::operator*=(this: &v11, result: &v7, f: scale);
        value.m_tms = v11.m_tms;
        CDmAttribute::SetValue<DmeTime_t>(this: (CDmAttribute *)v5[1].m_Name.m_Storage.u.m_Id, &value);
      }
      ++v3;
    }
    while ( v3 < nBookmarks );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0063D5A0
// Name: public: virtual bool CDmeBookmark::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBookmark::IsA(CDmeBookmark *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBookmark::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0063D5D0
// Name: public: virtual int CDmeBookmark::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmark::GetInheritanceDepth(CDmeBookmark *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBookmark::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0063D610
// Name: protected: virtual int CDmeBookmark::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmark::AllocatedSize(CDmeCurveInfo *this)
{
  return 92;
}

//------------------------------------------------------------------------------
// Address: 0x0063D690
// Name: protected: virtual void CDmeBookmark::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmark::PerformConstruction(CDmeBookmark *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeBookmark::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0063D700
// Name: public: virtual bool CDmeBookmarkSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBookmarkSet::IsA(CDmeBookmarkSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBookmarkSet::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0063D730
// Name: public: virtual int CDmeBookmarkSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBookmarkSet::GetInheritanceDepth(CDmeBookmarkSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBookmarkSet::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0063D770
// Name: protected: virtual void CDmeBookmarkSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBookmarkSet::PerformConstruction(CDmeBookmarkSet *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  this->m_Bookmarks.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "bookmarks",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_Bookmarks);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Bookmarks.m_pAttribute, typeSymbol: CDmeBookmark::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x006BAD70
// Name: _dynamic_initializer_for__CDmeBookmark::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBookmark::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBookmark::s_Allocator,
    blockSize: 0x5Cu,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBookmark pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BADD0
// Name: _dynamic_initializer_for__CDmeBookmarkSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBookmarkSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBookmarkSet::s_Allocator,
    blockSize: 0x60u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBookmarkSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BD960
// Name: _dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBookmark::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBookmark::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD970
// Name: _dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBookmarkSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBookmarkSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BADA0
// Name: _dynamic_initializer_for__g_CDmeBookmark_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBookmark_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BADB0
// Name: _dynamic_initializer_for__g_CDmeBookmark_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBookmark_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBookmark_Helper,
           classname: "DmeBookmark",
           pFactory: &g_CDmeBookmark_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BAE00
// Name: _dynamic_initializer_for__g_CDmeBookmarkSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBookmarkSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BAE10
// Name: _dynamic_initializer_for__g_CDmeBookmarkSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBookmarkSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBookmarkSet_Helper,
           classname: "DmeBookmarkSet",
           pFactory: &g_CDmeBookmarkSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BD980
// Name: _dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBookmarkSet_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeBookmarkSet_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD990
// Name: _dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBookmark_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeBookmark_Factory.m_CallBackList);
}

} // namespace vmap
