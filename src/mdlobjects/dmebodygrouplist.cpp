// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmebodygrouplist.cpp
// Functions: 8
// ============================================================

#include "mdlobjects\dmebodygrouplist.h"

//------------------------------------------------------------------------------
// Address: 0x0049E370
// Name: public: virtual bool CDmeBodyGroupList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBodyGroupList::IsA(CDmeBodyGroupList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBodyGroupList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049E3A0
// Name: public: virtual int CDmeBodyGroupList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBodyGroupList::GetInheritanceDepth(CDmeBodyGroupList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBodyGroupList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049E3E0
// Name: protected: virtual void CDmeBodyGroupList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBodyGroupList::PerformConstruction(CDmeBodyGroupList *this)
{
  CDmeFXClip::OnDestruction();
  this->m_BodyGroups.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "bodyGroupList",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_BodyGroups);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BodyGroups.m_pAttribute, typeSymbol: CDmeBodyGroup::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00598B80
// Name: _dynamic_initializer_for__CDmeBodyGroupList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBodyGroupList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBodyGroupList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBodyGroupList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBodyGroupList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E0E0
// Name: _dynamic_atexit_destructor_for__CDmeBodyGroupList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBodyGroupList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBodyGroupList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00598BB0
// Name: _dynamic_initializer_for__g_CDmeBodyGroupList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBodyGroupList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBodyGroupList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00598BC0
// Name: _dynamic_initializer_for__g_CDmeBodyGroupList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBodyGroupList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBodyGroupList_Helper,
           classname: "DmeBodyGroupList",
           pFactory: &g_CDmeBodyGroupList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E0F0
// Name: _dynamic_atexit_destructor_for__g_CDmeBodyGroupList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBodyGroupList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBodyGroupList_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E2930
// Name: public: class CDmeBodyGroup __near * CDmeBodyGroupList::FindBodyGroup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeBodyGroup *__thiscall CDmeBodyGroupList::FindBodyGroup(CDmeBodyGroupList *this, const char *pName)
{
  int v3; // edi
  int v4; // eax
  int v5; // esi
  const char *v6; // eax
  int v8; // eax
  int v9; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nCount = this->m_BodyGroups.m_Storage.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_BodyGroups.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeBodyGroup::m_classType.u) == 0 )
    {
      v5 = 0;
    }
    v6 = *(const char **)(v5 + 20);
    if ( v6 == (const char *)-1 )
      v6 = pDeltaStateName;
    if ( _V_stricmp(s1: pName, s2: v6) == 0 )
      break;
    if ( ++v3 >= nCount )
      return nullptr;
  }
  v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_BodyGroups.m_Storage.m_Memory.m_pMemory[v3]);
  v9 = v8;
  if ( v8 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
         a1: v8,
         a2: CDmeBodyGroup::m_classType.u) != 0 )
  {
    return (CDmeBodyGroup *)v9;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004E29F0
// Name: public: class CDmeLODList __near * CDmeBodyGroupList::GetMainBodyPart(void)
// Source: json
//------------------------------------------------------------------------------
CDmeLODList *__thiscall CDmeBodyGroupList::GetMainBodyPart(CDmeBodyGroupList *this)
{
  CDmeBodyGroup *BodyGroup; // ebx
  int v3; // eax
  CDmeBodyGroup *v4; // esi
  CDmeLODList *BodyPart; // eax
  int *v6; // esi
  int v8; // edi
  int v9; // eax
  int nBodypartCount; // [esp+Ch] [ebp-4h]

  if ( this->m_BodyGroups.m_Storage.m_Size != 0 )
  {
    BodyGroup = CDmeBodyGroupList::FindBodyGroup(this, pName: pszFlexControllerType);
    if ( BodyGroup == nullptr )
    {
      v3 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: *this->m_BodyGroups.m_Storage.m_Memory.m_pMemory);
      v4 = (CDmeBodyGroup *)v3;
      if ( v3 == 0
        || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v3 + 16))(
             a1: v3,
             a2: CDmeBodyGroup::m_classType.u) == 0 )
      {
        v4 = nullptr;
      }
      BodyGroup = v4;
    }
    BodyPart = CDmeBodyGroup::FindBodyPart(this: BodyGroup, pName: pszFlexControllerType);
    v6 = (int *)BodyPart;
    if ( BodyPart != nullptr && BodyPart->IsA(this: BodyPart, a2: CDmeLODList::m_classType) )
      return (CDmeLODList *)v6;
    v8 = 0;
    nBodypartCount = BodyGroup->m_BodyParts.m_Storage.m_Size;
    if ( nBodypartCount > 0 )
    {
      while ( 1 )
      {
        v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: BodyGroup->m_BodyParts.m_Storage.m_Memory.m_pMemory[v8]);
        v6 = (int *)v9;
        if ( v9 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v9 + 16))(
               a1: v9,
               a2: CDmeBodyPart::m_classType.u) != 0
          && (*(unsigned __int8 (__thiscall **)(int *, CUtlSymbolLarge::<unnamed_type_u>))(*v6 + 16))(
               a1: v6,
               a2: CDmeLODList::m_classType.u) != 0
          && v6[20] > 0 )
        {
          break;
        }
        if ( ++v8 >= nBodypartCount )
          return nullptr;
      }
      return (CDmeLODList *)v6;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004E2B50
// Name: public: virtual bool CDmeBodyGroupList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBodyGroupList::IsA(CDmeBodyGroupList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBodyGroupList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E2B80
// Name: public: virtual int CDmeBodyGroupList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBodyGroupList::GetInheritanceDepth(CDmeBodyGroupList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBodyGroupList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E2BC0
// Name: protected: virtual void CDmeBodyGroupList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBodyGroupList::PerformConstruction(CDmeBodyGroupList *this)
{
  CDmeFXClip::OnDestruction();
  this->m_BodyGroups.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "bodyGroupList",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_BodyGroups);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BodyGroups.m_pAttribute, typeSymbol: CDmeBodyGroup::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005ED460
// Name: _dynamic_initializer_for__CDmeBodyGroupList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBodyGroupList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBodyGroupList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBodyGroupList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBodyGroupList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F32B0
// Name: _dynamic_atexit_destructor_for__CDmeBodyGroupList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBodyGroupList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBodyGroupList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED490
// Name: _dynamic_initializer_for__g_CDmeBodyGroupList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBodyGroupList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBodyGroupList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED4A0
// Name: _dynamic_initializer_for__g_CDmeBodyGroupList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBodyGroupList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBodyGroupList_Helper,
           classname: "DmeBodyGroupList",
           pFactory: &g_CDmeBodyGroupList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F32C0
// Name: _dynamic_atexit_destructor_for__g_CDmeBodyGroupList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBodyGroupList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBodyGroupList_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0050DF20
// Name: public: virtual bool CDmeBodyGroupList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBodyGroupList::IsA(CDmeBodyGroupList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBodyGroupList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050DF50
// Name: public: virtual int CDmeBodyGroupList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBodyGroupList::GetInheritanceDepth(CDmeBodyGroupList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBodyGroupList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050DF90
// Name: protected: virtual void CDmeBodyGroupList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBodyGroupList::PerformConstruction(CDmeBodyGroupList *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_BodyGroups.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "bodyGroupList",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_BodyGroups);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BodyGroups.m_pAttribute, typeSymbol: CDmeBodyGroup::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x006ACF80
// Name: _dynamic_initializer_for__CDmeBodyGroupList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBodyGroupList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBodyGroupList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBodyGroupList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBodyGroupList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B3EB0
// Name: _dynamic_atexit_destructor_for__CDmeBodyGroupList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBodyGroupList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBodyGroupList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006ACFB0
// Name: _dynamic_initializer_for__g_CDmeBodyGroupList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBodyGroupList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBodyGroupList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ACFC0
// Name: _dynamic_initializer_for__g_CDmeBodyGroupList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBodyGroupList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBodyGroupList_Helper,
           classname: "DmeBodyGroupList",
           pFactory: &g_CDmeBodyGroupList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B3EC0
// Name: _dynamic_atexit_destructor_for__g_CDmeBodyGroupList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBodyGroupList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeBodyGroupList_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004DD990
// Name: public: virtual bool CDmeBodyGroupList::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBodyGroupList::IsA(CDmeBodyGroupList *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBodyGroupList::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DD9C0
// Name: public: virtual int CDmeBodyGroupList::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBodyGroupList::GetInheritanceDepth(CDmeBodyGroupList *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBodyGroupList::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DDA00
// Name: protected: virtual void CDmeBodyGroupList::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBodyGroupList::PerformConstruction(CDmeBodyGroupList *this)
{
  CDmeFXClip::OnDestruction();
  this->m_BodyGroups.m_pAttribute = CDmElement::AddExternalAttribute(
                                      this,
                                      pAttributeName: "bodyGroupList",
                                      type: AT_FIRST_ARRAY_TYPE,
                                      pMemory: &this->m_BodyGroups);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BodyGroups.m_pAttribute, typeSymbol: CDmeBodyGroup::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005E6650
// Name: _dynamic_initializer_for__CDmeBodyGroupList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBodyGroupList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBodyGroupList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBodyGroupList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBodyGroupList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC270
// Name: _dynamic_atexit_destructor_for__CDmeBodyGroupList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBodyGroupList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBodyGroupList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E6680
// Name: _dynamic_initializer_for__g_CDmeBodyGroupList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBodyGroupList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBodyGroupList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6690
// Name: _dynamic_initializer_for__g_CDmeBodyGroupList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBodyGroupList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBodyGroupList_Helper,
           classname: "DmeBodyGroupList",
           pFactory: &g_CDmeBodyGroupList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC280
// Name: _dynamic_atexit_destructor_for__g_CDmeBodyGroupList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBodyGroupList_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBodyGroupList_Factory.m_CallBackList);
}

} // namespace studiomdl
