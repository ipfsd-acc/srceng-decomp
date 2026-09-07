// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmebodygroup.cpp
// Functions: 8
// ============================================================

#include "mdlobjects\dmebodygroup.h"

//------------------------------------------------------------------------------
// Address: 0x0049E1C0
// Name: public: virtual bool CDmeBodyGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBodyGroup::IsA(CDmeBodyGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBodyGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049E1F0
// Name: public: virtual int CDmeBodyGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBodyGroup::GetInheritanceDepth(CDmeBodyGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBodyGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049E230
// Name: protected: virtual void CDmeBodyGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBodyGroup::PerformConstruction(CDmeBodyGroup *this)
{
  CDmeFXClip::OnDestruction();
  this->m_BodyParts.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "bodyPartList",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_BodyParts);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BodyParts.m_pAttribute, typeSymbol: CDmeBodyPart::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00598B20
// Name: _dynamic_initializer_for__CDmeBodyGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBodyGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBodyGroup::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBodyGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBodyGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E0C0
// Name: _dynamic_atexit_destructor_for__CDmeBodyGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBodyGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBodyGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00598B50
// Name: _dynamic_initializer_for__g_CDmeBodyGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBodyGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBodyGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00598B60
// Name: _dynamic_initializer_for__g_CDmeBodyGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBodyGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBodyGroup_Helper,
           classname: "DmeBodyGroup",
           pFactory: &g_CDmeBodyGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E0D0
// Name: _dynamic_atexit_destructor_for__g_CDmeBodyGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBodyGroup_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBodyGroup_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E26D0
// Name: public: class CDmeLODList __near * CDmeBodyGroup::FindBodyPart(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeLODList *__thiscall CDmeBodyGroup::FindBodyPart(CDmeBodyGroup *this, const char *pName)
{
  int v3; // edi
  int v4; // eax
  _DWORD *v5; // esi
  const char *v6; // eax
  int nCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nCount = this->m_BodyParts.m_Storage.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_BodyParts.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = (_DWORD *)v4;
    if ( v4 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeBodyPart::m_classType.u) != 0
      && (*(unsigned __int8 (__thiscall **)(_DWORD *, CUtlSymbolLarge::<unnamed_type_u>))(*v5 + 16))(
           a1: v5,
           a2: CDmeLODList::m_classType.u) != 0 )
    {
      v6 = (const char *)v5[5];
      if ( v6 == (const char *)-1 )
        v6 = pDeltaStateName;
      if ( _V_stricmp(s1: pName, s2: v6) == 0 )
        break;
    }
    if ( ++v3 >= nCount )
      return nullptr;
  }
  return (CDmeLODList *)v5;
}

//------------------------------------------------------------------------------
// Address: 0x004E27E0
// Name: public: virtual bool CDmeBodyGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBodyGroup::IsA(CDmeBodyGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBodyGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E2810
// Name: public: virtual int CDmeBodyGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBodyGroup::GetInheritanceDepth(CDmeBodyGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBodyGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004E2850
// Name: protected: virtual void CDmeBodyGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBodyGroup::PerformConstruction(CDmeBodyGroup *this)
{
  CDmeFXClip::OnDestruction();
  this->m_BodyParts.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "bodyPartList",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_BodyParts);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BodyParts.m_pAttribute, typeSymbol: CDmeBodyPart::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005ED400
// Name: _dynamic_initializer_for__CDmeBodyGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBodyGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBodyGroup::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBodyGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBodyGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3290
// Name: _dynamic_atexit_destructor_for__CDmeBodyGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBodyGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBodyGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED430
// Name: _dynamic_initializer_for__g_CDmeBodyGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBodyGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBodyGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED440
// Name: _dynamic_initializer_for__g_CDmeBodyGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBodyGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBodyGroup_Helper,
           classname: "DmeBodyGroup",
           pFactory: &g_CDmeBodyGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F32A0
// Name: _dynamic_atexit_destructor_for__g_CDmeBodyGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBodyGroup_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBodyGroup_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0050DD70
// Name: public: virtual bool CDmeBodyGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBodyGroup::IsA(CDmeBodyGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBodyGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050DDA0
// Name: public: virtual int CDmeBodyGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBodyGroup::GetInheritanceDepth(CDmeBodyGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBodyGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050DDE0
// Name: protected: virtual void CDmeBodyGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBodyGroup::PerformConstruction(CDmeBodyGroup *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_BodyParts.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "bodyPartList",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_BodyParts);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BodyParts.m_pAttribute, typeSymbol: CDmeBodyPart::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x006ACF20
// Name: _dynamic_initializer_for__CDmeBodyGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBodyGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBodyGroup::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBodyGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBodyGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B3E90
// Name: _dynamic_atexit_destructor_for__CDmeBodyGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBodyGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBodyGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006ACF50
// Name: _dynamic_initializer_for__g_CDmeBodyGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBodyGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBodyGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006ACF60
// Name: _dynamic_initializer_for__g_CDmeBodyGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBodyGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBodyGroup_Helper,
           classname: "DmeBodyGroup",
           pFactory: &g_CDmeBodyGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B3EA0
// Name: _dynamic_atexit_destructor_for__g_CDmeBodyGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBodyGroup_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeBodyGroup_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004DD7E0
// Name: public: virtual bool CDmeBodyGroup::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeBodyGroup::IsA(CDmeBodyGroup *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeBodyGroup::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DD810
// Name: public: virtual int CDmeBodyGroup::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeBodyGroup::GetInheritanceDepth(CDmeBodyGroup *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeBodyGroup::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DD850
// Name: protected: virtual void CDmeBodyGroup::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeBodyGroup::PerformConstruction(CDmeBodyGroup *this)
{
  CDmeFXClip::OnDestruction();
  this->m_BodyParts.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "bodyPartList",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_BodyParts);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BodyParts.m_pAttribute, typeSymbol: CDmeBodyPart::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005E65F0
// Name: _dynamic_initializer_for__CDmeBodyGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeBodyGroup::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeBodyGroup::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeBodyGroup pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeBodyGroup::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC250
// Name: _dynamic_atexit_destructor_for__CDmeBodyGroup::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeBodyGroup::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeBodyGroup::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E6620
// Name: _dynamic_initializer_for__g_CDmeBodyGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeBodyGroup_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeBodyGroup_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6630
// Name: _dynamic_initializer_for__g_CDmeBodyGroup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeBodyGroup_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeBodyGroup_Helper,
           classname: "DmeBodyGroup",
           pFactory: &g_CDmeBodyGroup_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC260
// Name: _dynamic_atexit_destructor_for__g_CDmeBodyGroup_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeBodyGroup_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeBodyGroup_Factory.m_CallBackList);
}

} // namespace studiomdl
