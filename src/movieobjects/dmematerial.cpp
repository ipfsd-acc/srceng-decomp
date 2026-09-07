// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmematerial.cpp
// Functions: 12
// ============================================================

#include "movieobjects\dmematerial.h"

//------------------------------------------------------------------------------
// Address: 0x00557970
// Name: public: void CDmeMaterial::SetMaterial(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::SetMaterial(CDmeMaterial *this, const char *pMaterialName)
{
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pMaterialName, a3: pMaterialName);
  CDmAttribute::SetValue<CUtlSymbolLarge>(
    this: this->m_mtlName.m_pAttribute,
    value: (const CUtlSymbolLarge *)&pMaterialName);
}

//------------------------------------------------------------------------------
// Address: 0x005579A0
// Name: public: virtual void CDmeMaterial::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::Resolve(CDmeMaterial *this)
{
  if ( SLOBYTE(this->m_mtlName.m_pAttribute->m_nFlags) < 0 )
    CMaterialReference::Shutdown(this: &this->m_mtlRef, bDeleteIfUnreferenced: false);
}

//------------------------------------------------------------------------------
// Address: 0x005579C0
// Name: public: char const __near * CDmeMaterial::GetMaterialName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMaterial::GetMaterialName(CDmeMaterial *this)
{
  const char *result; // eax

  result = this->m_mtlName.m_Storage.u.m_pAsString;
  if ( result == (const char *)-1 )
    return var;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005579D0
// Name: public: class IMaterial __near * CDmeMaterial::GetCachedMTL(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CDmeMaterial::GetCachedMTL(CDmeMaterial *this)
{
  CMaterialReference *p_m_mtlRef; // esi
  IMaterial *result; // eax
  IMaterial *v3; // eax

  p_m_mtlRef = &this->m_mtlRef;
  if ( this->m_mtlRef.m_pMaterial != nullptr )
    return p_m_mtlRef->m_pMaterial;
  result = (IMaterial *)this->m_mtlName.m_Storage.u.m_Id;
  if ( result == (IMaterial *)-1 )
  {
    result = (IMaterial *)var;
LABEL_4:
    v3 = g_pMaterialSystem->FindMaterial(this: g_pMaterialSystem, a2: result, a3: 0, a4: 0, a5: 0);
    CMaterialReference::Init(this: p_m_mtlRef, pMaterial: v3);
    return p_m_mtlRef->m_pMaterial;
  }
  if ( result != nullptr )
    goto LABEL_4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00557AB0
// Name: public: virtual bool CDmeMaterial::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterial::IsA(CDmeMaterial *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterial::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00557AE0
// Name: public: virtual int CDmeMaterial::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterial::GetInheritanceDepth(CDmeMaterial *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterial::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00557B20
// Name: protected: virtual void CDmeMaterial::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::PerformConstruction(CDmeMaterial *this)
{
  CDmeFXClip::OnDestruction();
  this->m_mtlName.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "mtlName",
                                   type: AT_STRING,
                                   pMemory: &this->m_mtlName);
}

//------------------------------------------------------------------------------
// Address: 0x005AD890
// Name: _dynamic_initializer_for__CDmeMaterial::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterial::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterial::s_Allocator,
    blockSize: 80,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterial pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005B0430
// Name: _dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterial::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AD8C0
// Name: _dynamic_initializer_for__g_CDmeMaterial_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterial_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AD8D0
// Name: _dynamic_initializer_for__g_CDmeMaterial_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterial_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterial_Helper,
           classname: "DmeMaterial",
           pFactory: &g_CDmeMaterial_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005B0440
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMaterial_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005AEB10
// Name: public: virtual void CDmeMaterial::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::Resolve(CDmeMaterial *this)
{
  if ( SLOBYTE(this->m_mtlName.m_pAttribute->m_nFlags) < 0 )
    CMaterialReference::Shutdown(this: &this->m_mtlRef, bDeleteIfUnreferenced: false);
}

//------------------------------------------------------------------------------
// Address: 0x005AEB30
// Name: public: class IMaterial __near * CDmeMaterial::GetCachedMTL(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CDmeMaterial::GetCachedMTL(CDmeMaterial *this)
{
  CMaterialReference *p_m_mtlRef; // esi
  IMaterial *result; // eax
  IMaterial *v3; // eax

  p_m_mtlRef = &this->m_mtlRef;
  if ( this->m_mtlRef.m_pMaterial != nullptr )
    return p_m_mtlRef->m_pMaterial;
  result = (IMaterial *)this->m_mtlName.m_Storage.u.m_Id;
  if ( result == (IMaterial *)-1 )
  {
    result = (IMaterial *)defaultValue;
LABEL_4:
    v3 = g_pMaterialSystem->FindMaterial(this: g_pMaterialSystem, a2: result, a3: 0, a4: 0, a5: 0);
    CMaterialReference::Init(this: p_m_mtlRef, pMaterial: v3);
    return p_m_mtlRef->m_pMaterial;
  }
  if ( result != nullptr )
    goto LABEL_4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AEC10
// Name: public: virtual bool CDmeMaterial::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterial::IsA(CDmeMaterial *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterial::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AEC40
// Name: public: virtual int CDmeMaterial::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterial::GetInheritanceDepth(CDmeMaterial *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterial::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AEC80
// Name: protected: virtual void CDmeMaterial::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::PerformConstruction(CDmeMaterial *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_mtlName.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "mtlName",
                                   type: AT_STRING,
                                   pMemory: &this->m_mtlName);
}

//------------------------------------------------------------------------------
// Address: 0x0067F080
// Name: _dynamic_initializer_for__CDmeMaterial::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterial::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterial::s_Allocator,
    blockSize: 80,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterial pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00682940
// Name: _dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterial::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067F0B0
// Name: _dynamic_initializer_for__g_CDmeMaterial_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterial_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F0C0
// Name: _dynamic_initializer_for__g_CDmeMaterial_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterial_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterial_Helper,
           classname: "DmeMaterial",
           pFactory: &g_CDmeMaterial_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00682950
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMaterial_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10599EA0
// Name: public: virtual void CDmeMaterial::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::Resolve(CDmeMaterial *this)
{
  if ( SLOBYTE(this->m_mtlName.m_pAttribute->m_nFlags) < 0 )
    CMaterialReference::Shutdown(this: &this->m_mtlRef, bDeleteIfUnreferenced: false);
}

//------------------------------------------------------------------------------
// Address: 0x10599EC0
// Name: public: class IMaterial __near * CDmeMaterial::GetCachedMTL(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CDmeMaterial::GetCachedMTL(CDmeMaterial *this)
{
  CMaterialReference *p_m_mtlRef; // esi
  IMaterial *result; // eax
  IMaterial *v3; // eax

  p_m_mtlRef = &this->m_mtlRef;
  if ( this->m_mtlRef.m_pMaterial != nullptr )
    return p_m_mtlRef->m_pMaterial;
  result = (IMaterial *)this->m_mtlName.m_Storage.u.m_Id;
  if ( result == (IMaterial *)-1 )
  {
    result = (IMaterial *)&var;
LABEL_4:
    v3 = g_pMaterialSystem->FindMaterial(this: g_pMaterialSystem, a2: result, a3: 0, a4: 0, a5: 0);
    CMaterialReference::Init(this: p_m_mtlRef, pMaterial: v3);
    return p_m_mtlRef->m_pMaterial;
  }
  if ( result != nullptr )
    goto LABEL_4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10599FA0
// Name: public: virtual bool CDmeMaterial::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterial::IsA(CDmeMaterial *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterial::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10599FD0
// Name: public: virtual int CDmeMaterial::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterial::GetInheritanceDepth(CDmeMaterial *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterial::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1059A010
// Name: protected: virtual int CDmeMaterial::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterial::AllocatedSize(CDmeMaterial *this)
{
  return 80;
}

//------------------------------------------------------------------------------
// Address: 0x1059A020
// Name: protected: virtual void CDmeMaterial::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::PerformConstruction(CDmeMaterial *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  this->m_mtlName.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "mtlName",
                                   type: AT_STRING,
                                   pMemory: &this->m_mtlName);
}

//------------------------------------------------------------------------------
// Address: 0x105C9C60
// Name: _dynamic_initializer_for__CDmeMaterial::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterial::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterial::s_Allocator,
    blockSize: 0x50u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterial pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CDC70
// Name: _dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterial::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C9C90
// Name: _dynamic_initializer_for__g_CDmeMaterial_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterial_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9CA0
// Name: _dynamic_initializer_for__g_CDmeMaterial_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterial_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterial_Helper,
           classname: "DmeMaterial",
           pFactory: &g_CDmeMaterial_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CDC80
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeMaterial_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x00560100
// Name: public: virtual void CDmeMaterial::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::Resolve(CDmeMaterial *this)
{
  if ( SLOBYTE(this->m_mtlName.m_pAttribute->m_nFlags) < 0 )
    CMaterialReference::Shutdown(this: &this->m_mtlRef, bDeleteIfUnreferenced: false);
}

//------------------------------------------------------------------------------
// Address: 0x00560120
// Name: public: class IMaterial __near * CDmeMaterial::GetCachedMTL(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CDmeMaterial::GetCachedMTL(CDmeMaterial *this)
{
  CMaterialReference *p_m_mtlRef; // esi
  IMaterial *result; // eax
  IMaterial *v3; // eax

  p_m_mtlRef = &this->m_mtlRef;
  if ( this->m_mtlRef.m_pMaterial != nullptr )
    return p_m_mtlRef->m_pMaterial;
  result = (IMaterial *)this->m_mtlName.m_Storage.u.m_Id;
  if ( result == (IMaterial *)-1 )
  {
    result = (IMaterial *)WindowName;
LABEL_4:
    v3 = g_pMaterialSystem->FindMaterial(this: g_pMaterialSystem, a2: result, a3: 0, a4: 0, a5: 0);
    CMaterialReference::Init(this: p_m_mtlRef, pMaterial: v3);
    return p_m_mtlRef->m_pMaterial;
  }
  if ( result != nullptr )
    goto LABEL_4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00560200
// Name: public: virtual bool CDmeMaterial::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterial::IsA(CDmeMaterial *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterial::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00560230
// Name: public: virtual int CDmeMaterial::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterial::GetInheritanceDepth(CDmeMaterial *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterial::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00560270
// Name: protected: virtual void CDmeMaterial::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::PerformConstruction(CDmeMaterial *this)
{
  CDmeFXClip::OnDestruction();
  this->m_mtlName.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "mtlName",
                                   type: AT_STRING,
                                   pMemory: &this->m_mtlName);
}

//------------------------------------------------------------------------------
// Address: 0x0059CB70
// Name: _dynamic_initializer_for__CDmeMaterial::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterial::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterial::s_Allocator,
    blockSize: 80,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterial pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059F660
// Name: _dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterial::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059CBA0
// Name: _dynamic_initializer_for__g_CDmeMaterial_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterial_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059CBB0
// Name: _dynamic_initializer_for__g_CDmeMaterial_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterial_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterial_Helper,
           classname: "DmeMaterial",
           pFactory: &g_CDmeMaterial_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059F670
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMaterial_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x0050B960
// Name: public: virtual void CDmeMaterial::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::Resolve(CDmeMaterial *this)
{
  if ( SLOBYTE(this->m_mtlName.m_pAttribute->m_nFlags) < 0 )
    CMaterialReference::Shutdown(this: &this->m_mtlRef, bDeleteIfUnreferenced: false);
}

//------------------------------------------------------------------------------
// Address: 0x0050B980
// Name: public: char const __near * CDmeMaterial::GetMaterialName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMaterial::GetMaterialName(CDmeMaterial *this)
{
  const char *result; // eax

  result = this->m_mtlName.m_Storage.u.m_pAsString;
  if ( result == (const char *)-1 )
    return pDeltaStateName;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0050B990
// Name: public: class IMaterial __near * CDmeMaterial::GetCachedMTL(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CDmeMaterial::GetCachedMTL(CDmeMaterial *this)
{
  CMaterialReference *p_m_mtlRef; // esi
  IMaterial *result; // eax
  IMaterial *v3; // eax

  p_m_mtlRef = &this->m_mtlRef;
  if ( this->m_mtlRef.m_pMaterial != nullptr )
    return p_m_mtlRef->m_pMaterial;
  result = (IMaterial *)this->m_mtlName.m_Storage.u.m_Id;
  if ( result == (IMaterial *)-1 )
  {
    result = (IMaterial *)pDeltaStateName;
LABEL_4:
    v3 = g_pMaterialSystem->FindMaterial(this: g_pMaterialSystem, a2: result, a3: 0, a4: 0, a5: 0);
    CMaterialReference::Init(this: p_m_mtlRef, pMaterial: v3);
    return p_m_mtlRef->m_pMaterial;
  }
  if ( result != nullptr )
    goto LABEL_4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0050BA70
// Name: public: virtual bool CDmeMaterial::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterial::IsA(CDmeMaterial *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterial::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050BAA0
// Name: public: virtual int CDmeMaterial::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterial::GetInheritanceDepth(CDmeMaterial *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterial::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050BAF0
// Name: protected: virtual void CDmeMaterial::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::PerformConstruction(CDmeMaterial *this)
{
  CDmeFXClip::OnDestruction();
  this->m_mtlName.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "mtlName",
                                   type: AT_STRING,
                                   pMemory: &this->m_mtlName);
}

//------------------------------------------------------------------------------
// Address: 0x005F0150
// Name: _dynamic_initializer_for__CDmeMaterial::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterial::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterial::s_Allocator,
    blockSize: 80,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterial pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F41C0
// Name: _dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterial::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F0180
// Name: _dynamic_initializer_for__g_CDmeMaterial_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterial_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0190
// Name: _dynamic_initializer_for__g_CDmeMaterial_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterial_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterial_Helper,
           classname: "DmeMaterial",
           pFactory: &g_CDmeMaterial_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F41D0
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMaterial_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00519200
// Name: public: virtual void CDmeMaterial::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::Resolve(CDmeMaterial *this)
{
  if ( SLOBYTE(this->m_mtlName.m_pAttribute->m_nFlags) < 0 )
    CMaterialReference::Shutdown(this: &this->m_mtlRef, bDeleteIfUnreferenced: false);
}

//------------------------------------------------------------------------------
// Address: 0x00519220
// Name: public: class IMaterial __near * CDmeMaterial::GetCachedMTL(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CDmeMaterial::GetCachedMTL(CDmeMaterial *this)
{
  CMaterialReference *p_m_mtlRef; // esi
  IMaterial *result; // eax
  IMaterial *v3; // eax

  p_m_mtlRef = &this->m_mtlRef;
  if ( this->m_mtlRef.m_pMaterial != nullptr )
    return p_m_mtlRef->m_pMaterial;
  result = (IMaterial *)this->m_mtlName.m_Storage.u.m_Id;
  if ( result == (IMaterial *)-1 )
  {
    result = (IMaterial *)str;
LABEL_4:
    v3 = g_pMaterialSystem->FindMaterial(this: g_pMaterialSystem, a2: result, a3: 0, a4: 0, a5: 0);
    CMaterialReference::Init(this: p_m_mtlRef, pMaterial: v3);
    return p_m_mtlRef->m_pMaterial;
  }
  if ( result != nullptr )
    goto LABEL_4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00519300
// Name: public: virtual bool CDmeMaterial::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterial::IsA(CDmeMaterial *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterial::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00519330
// Name: public: virtual int CDmeMaterial::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterial::GetInheritanceDepth(CDmeMaterial *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterial::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00519370
// Name: protected: virtual void CDmeMaterial::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::PerformConstruction(CDmeMaterial *this)
{
  CDmeFXClip::OnDestruction();
  this->m_mtlName.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "mtlName",
                                   type: AT_STRING,
                                   pMemory: &this->m_mtlName);
}

//------------------------------------------------------------------------------
// Address: 0x0056BC60
// Name: _dynamic_initializer_for__CDmeMaterial::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterial::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterial::s_Allocator,
    blockSize: 80,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterial pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056EB20
// Name: _dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterial::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056BC90
// Name: _dynamic_initializer_for__g_CDmeMaterial_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterial_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056BCA0
// Name: _dynamic_initializer_for__g_CDmeMaterial_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterial_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterial_Helper,
           classname: "DmeMaterial",
           pFactory: &g_CDmeMaterial_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056EB30
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMaterial_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0051EBB0
// Name: public: virtual void CDmeMaterial::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::Resolve(CDmeMaterial *this)
{
  if ( SLOBYTE(this->m_mtlName.m_pAttribute->m_nFlags) < 0 )
    CMaterialReference::Shutdown(this: &this->m_mtlRef, bDeleteIfUnreferenced: false);
}

//------------------------------------------------------------------------------
// Address: 0x0051EBD0
// Name: public: class IMaterial __near * CDmeMaterial::GetCachedMTL(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CDmeMaterial::GetCachedMTL(CDmeMaterial *this)
{
  CMaterialReference *p_m_mtlRef; // esi
  IMaterial *result; // eax
  IMaterial *v3; // eax

  p_m_mtlRef = &this->m_mtlRef;
  if ( this->m_mtlRef.m_pMaterial != nullptr )
    return p_m_mtlRef->m_pMaterial;
  result = (IMaterial *)this->m_mtlName.m_Storage.u.m_Id;
  if ( result == (IMaterial *)-1 )
  {
    result = (IMaterial *)&pParentName;
LABEL_4:
    v3 = g_pMaterialSystem->FindMaterial(this: g_pMaterialSystem, a2: result, a3: 0, a4: 0, a5: 0);
    CMaterialReference::Init(this: p_m_mtlRef, pMaterial: v3);
    return p_m_mtlRef->m_pMaterial;
  }
  if ( result != nullptr )
    goto LABEL_4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0051ECB0
// Name: public: virtual bool CDmeMaterial::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterial::IsA(CDmeMaterial *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterial::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051ECE0
// Name: public: virtual int CDmeMaterial::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterial::GetInheritanceDepth(CDmeMaterial *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterial::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051ED20
// Name: protected: virtual void CDmeMaterial::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::PerformConstruction(CDmeMaterial *this)
{
  CDmeFXClip::OnDestruction();
  this->m_mtlName.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "mtlName",
                                   type: AT_STRING,
                                   pMemory: &this->m_mtlName);
}

//------------------------------------------------------------------------------
// Address: 0x0057BD70
// Name: _dynamic_initializer_for__CDmeMaterial::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterial::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterial::s_Allocator,
    blockSize: 80,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterial pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EC50
// Name: _dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterial::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057BDA0
// Name: _dynamic_initializer_for__g_CDmeMaterial_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterial_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BDB0
// Name: _dynamic_initializer_for__g_CDmeMaterial_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterial_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterial_Helper,
           classname: "DmeMaterial",
           pFactory: &g_CDmeMaterial_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057EC60
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMaterial_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00525530
// Name: public: void CDmeMaterial::SetMaterial(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::SetMaterial(CDmeMaterial *this, const char *pMaterialName)
{
  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, const char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 200))(
    a1: g_pDataModel.u,
    a2: &pMaterialName,
    a3: pMaterialName);
  CDmAttribute::SetValue<CUtlSymbolLarge>(
    this: this->m_mtlName.m_pAttribute,
    value: (const CUtlSymbolLarge *)&pMaterialName);
}

//------------------------------------------------------------------------------
// Address: 0x00525560
// Name: public: virtual void CDmeMaterial::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::Resolve(CDmeMaterial *this)
{
  if ( SLOBYTE(this->m_mtlName.m_pAttribute->m_nFlags) < 0 )
    CMaterialReference::Shutdown(this: &this->m_mtlRef, bDeleteIfUnreferenced: false);
}

//------------------------------------------------------------------------------
// Address: 0x00525580
// Name: public: char const __near * CDmeMaterial::GetMaterialName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMaterial::GetMaterialName(CDmeMaterial *this)
{
  const char *result; // eax

  result = this->m_mtlName.m_Storage.u.m_pAsString;
  if ( result == (const char *)-1 )
    return defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00525590
// Name: public: class IMaterial __near * CDmeMaterial::GetCachedMTL(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CDmeMaterial::GetCachedMTL(CDmeMaterial *this)
{
  CMaterialReference *p_m_mtlRef; // esi
  IMaterial *result; // eax
  IMaterial *v3; // eax

  p_m_mtlRef = &this->m_mtlRef;
  if ( this->m_mtlRef.m_pMaterial != nullptr )
    return p_m_mtlRef->m_pMaterial;
  result = (IMaterial *)this->m_mtlName.m_Storage.u.m_Id;
  if ( result == (IMaterial *)-1 )
  {
    result = (IMaterial *)defaultValue;
LABEL_4:
    v3 = g_pMaterialSystem->FindMaterial(this: g_pMaterialSystem, a2: result, a3: 0, a4: 0, a5: 0);
    CMaterialReference::Init(this: p_m_mtlRef, pMaterial: v3);
    return p_m_mtlRef->m_pMaterial;
  }
  if ( result != nullptr )
    goto LABEL_4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00525670
// Name: public: virtual bool CDmeMaterial::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterial::IsA(CDmeMaterial *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterial::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005256A0
// Name: public: virtual int CDmeMaterial::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterial::GetInheritanceDepth(CDmeMaterial *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterial::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005256E0
// Name: protected: virtual void CDmeMaterial::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::PerformConstruction(CDmeMaterial *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_mtlName.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "mtlName",
                                   type: AT_STRING,
                                   pMemory: &this->m_mtlName);
}

//------------------------------------------------------------------------------
// Address: 0x006AF030
// Name: _dynamic_initializer_for__CDmeMaterial::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterial::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterial::s_Allocator,
    blockSize: 80,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterial pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B4990
// Name: _dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterial::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AF060
// Name: _dynamic_initializer_for__g_CDmeMaterial_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterial_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AF070
// Name: _dynamic_initializer_for__g_CDmeMaterial_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterial_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterial_Helper,
           classname: "DmeMaterial",
           pFactory: &g_CDmeMaterial_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B49A0
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMaterial_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0051FCD0
// Name: public: virtual void CDmeMaterial::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::Resolve(CDmeMaterial *this)
{
  if ( SLOBYTE(this->m_mtlName.m_pAttribute->m_nFlags) < 0 )
    CMaterialReference::Shutdown(this: &this->m_mtlRef, bDeleteIfUnreferenced: false);
}

//------------------------------------------------------------------------------
// Address: 0x0051FCF0
// Name: public: class IMaterial __near * CDmeMaterial::GetCachedMTL(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CDmeMaterial::GetCachedMTL(CDmeMaterial *this)
{
  CMaterialReference *p_m_mtlRef; // esi
  IMaterial *result; // eax
  IMaterial *v3; // eax

  p_m_mtlRef = &this->m_mtlRef;
  if ( this->m_mtlRef.m_pMaterial != nullptr )
    return p_m_mtlRef->m_pMaterial;
  result = (IMaterial *)this->m_mtlName.m_Storage.u.m_Id;
  if ( result == (IMaterial *)-1 )
  {
    result = (IMaterial *)&pch;
LABEL_4:
    v3 = g_pMaterialSystem->FindMaterial(this: g_pMaterialSystem, a2: result, a3: 0, a4: 0, a5: 0);
    CMaterialReference::Init(this: p_m_mtlRef, pMaterial: v3);
    return p_m_mtlRef->m_pMaterial;
  }
  if ( result != nullptr )
    goto LABEL_4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0051FDD0
// Name: public: virtual bool CDmeMaterial::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterial::IsA(CDmeMaterial *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterial::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051FE00
// Name: public: virtual int CDmeMaterial::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterial::GetInheritanceDepth(CDmeMaterial *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterial::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051FE50
// Name: protected: virtual void CDmeMaterial::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::PerformConstruction(CDmeMaterial *this)
{
  CDmeFXClip::OnDestruction();
  this->m_mtlName.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "mtlName",
                                   type: AT_STRING,
                                   pMemory: &this->m_mtlName);
}

//------------------------------------------------------------------------------
// Address: 0x0057DD50
// Name: _dynamic_initializer_for__CDmeMaterial::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterial::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterial::s_Allocator,
    blockSize: 80,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterial pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00580C30
// Name: _dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterial::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057DD80
// Name: _dynamic_initializer_for__g_CDmeMaterial_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterial_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DD90
// Name: _dynamic_initializer_for__g_CDmeMaterial_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterial_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterial_Helper,
           classname: "DmeMaterial",
           pFactory: &g_CDmeMaterial_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00580C40
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMaterial_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005049C0
// Name: public: virtual void CDmeMaterial::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::Resolve(CDmeMaterial *this)
{
  if ( SLOBYTE(this->m_mtlName.m_pAttribute->m_nFlags) < 0 )
    CMaterialReference::Shutdown(this: &this->m_mtlRef, bDeleteIfUnreferenced: false);
}

//------------------------------------------------------------------------------
// Address: 0x005049E0
// Name: public: char const __near * CDmeMaterial::GetMaterialName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMaterial::GetMaterialName(CDmeMaterial *this)
{
  const char *result; // eax

  result = this->m_mtlName.m_Storage.u.m_pAsString;
  if ( result == (const char *)-1 )
    return pDeltaStateName;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005049F0
// Name: public: class IMaterial __near * CDmeMaterial::GetCachedMTL(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CDmeMaterial::GetCachedMTL(CDmeMaterial *this)
{
  CMaterialReference *p_m_mtlRef; // esi
  IMaterial *result; // eax
  IMaterial *v3; // eax

  p_m_mtlRef = &this->m_mtlRef;
  if ( this->m_mtlRef.m_pMaterial != nullptr )
    return p_m_mtlRef->m_pMaterial;
  result = (IMaterial *)this->m_mtlName.m_Storage.u.m_Id;
  if ( result == (IMaterial *)-1 )
  {
    result = (IMaterial *)pDeltaStateName;
LABEL_4:
    v3 = g_pMaterialSystem->FindMaterial(this: g_pMaterialSystem, a2: result, a3: 0, a4: 0, a5: 0);
    CMaterialReference::Init(this: p_m_mtlRef, pMaterial: v3);
    return p_m_mtlRef->m_pMaterial;
  }
  if ( result != nullptr )
    goto LABEL_4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00504AD0
// Name: public: virtual bool CDmeMaterial::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterial::IsA(CDmeMaterial *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterial::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00504B00
// Name: public: virtual int CDmeMaterial::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterial::GetInheritanceDepth(CDmeMaterial *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterial::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00504B40
// Name: protected: virtual void CDmeMaterial::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::PerformConstruction(CDmeMaterial *this)
{
  CDmeFXClip::OnDestruction();
  this->m_mtlName.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "mtlName",
                                   type: AT_STRING,
                                   pMemory: &this->m_mtlName);
}

//------------------------------------------------------------------------------
// Address: 0x005E8FF0
// Name: _dynamic_initializer_for__CDmeMaterial::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterial::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterial::s_Allocator,
    blockSize: 80,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterial pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED060
// Name: _dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterial::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E9020
// Name: _dynamic_initializer_for__g_CDmeMaterial_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterial_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E9030
// Name: _dynamic_initializer_for__g_CDmeMaterial_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterial_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterial_Helper,
           classname: "DmeMaterial",
           pFactory: &g_CDmeMaterial_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED070
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMaterial_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00475F30
// Name: public: void CDmeMaterial::SetMaterial(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::SetMaterial(CDmeMaterial *this, const char *pMaterialName)
{
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pMaterialName, a3: pMaterialName);
  CDmAttribute::SetValue<CUtlSymbolLarge>(
    this: this->m_mtlName.m_pAttribute,
    value: (const CUtlSymbolLarge *)&pMaterialName);
}

//------------------------------------------------------------------------------
// Address: 0x00475F60
// Name: public: virtual void CDmeMaterial::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::Resolve(CDmeMaterial *this)
{
  if ( SLOBYTE(this->m_mtlName.m_pAttribute->m_nFlags) < 0 )
    CMaterialReference::Shutdown(this: &this->m_mtlRef, bDeleteIfUnreferenced: false);
}

//------------------------------------------------------------------------------
// Address: 0x00475F80
// Name: public: class IMaterial __near * CDmeMaterial::GetCachedMTL(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CDmeMaterial::GetCachedMTL(CDmeMaterial *this)
{
  CMaterialReference *p_m_mtlRef; // esi
  IMaterial *result; // eax
  IMaterial *v3; // eax

  p_m_mtlRef = &this->m_mtlRef;
  if ( this->m_mtlRef.m_pMaterial != nullptr )
    return p_m_mtlRef->m_pMaterial;
  result = (IMaterial *)this->m_mtlName.m_Storage.u.m_Id;
  if ( result == (IMaterial *)-1 )
  {
    result = (IMaterial *)Ptr;
LABEL_4:
    v3 = g_pMaterialSystem->FindMaterial(this: g_pMaterialSystem, a2: result, a3: 0, a4: 0, a5: 0);
    CMaterialReference::Init(this: p_m_mtlRef, pMaterial: v3);
    return p_m_mtlRef->m_pMaterial;
  }
  if ( result != nullptr )
    goto LABEL_4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00476070
// Name: public: virtual bool CDmeMaterial::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterial::IsA(CDmeMaterial *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterial::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004760A0
// Name: public: virtual int CDmeMaterial::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterial::GetInheritanceDepth(CDmeMaterial *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterial::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004760E0
// Name: protected: virtual void CDmeMaterial::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::PerformConstruction(CDmeMaterial *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  this->m_mtlName.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "mtlName",
                                   type: AT_STRING,
                                   pMemory: &this->m_mtlName);
}

//------------------------------------------------------------------------------
// Address: 0x00579390
// Name: _dynamic_initializer_for__CDmeMaterial::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterial::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterial::s_Allocator,
    blockSize: 80,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterial pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D790
// Name: _dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterial::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005793C0
// Name: _dynamic_initializer_for__g_CDmeMaterial_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterial_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005793D0
// Name: _dynamic_initializer_for__g_CDmeMaterial_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterial_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterial_Helper,
           classname: "DmeMaterial",
           pFactory: &g_CDmeMaterial_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057D7A0
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMaterial_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0062AB20
// Name: public: void CDmeMaterial::SetMaterial(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::SetMaterial(CDmeMaterial *this, const char *pMaterialName)
{
  g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pMaterialName, a3: pMaterialName);
  CDmAttribute::SetValue<CUtlSymbolLarge>(
    this: this->m_mtlName.m_pAttribute,
    value: (const CUtlSymbolLarge *)&pMaterialName);
}

//------------------------------------------------------------------------------
// Address: 0x0062AB50
// Name: public: virtual void CDmeMaterial::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::Resolve(CDmeMaterial *this)
{
  if ( SLOBYTE(this->m_mtlName.m_pAttribute->m_nFlags) < 0 )
    CMaterialReference::Shutdown(this: &this->m_mtlRef, bDeleteIfUnreferenced: false);
}

//------------------------------------------------------------------------------
// Address: 0x0062AB70
// Name: public: class IMaterial __near * CDmeMaterial::GetCachedMTL(void)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__thiscall CDmeMaterial::GetCachedMTL(CDmeMaterial *this)
{
  CMaterialReference *p_m_mtlRef; // esi
  IMaterial *result; // eax
  IMaterial *v3; // eax

  p_m_mtlRef = &this->m_mtlRef;
  if ( this->m_mtlRef.m_pMaterial != nullptr )
    return p_m_mtlRef->m_pMaterial;
  result = (IMaterial *)this->m_mtlName.m_Storage.u.m_Id;
  if ( result == (IMaterial *)-1 )
  {
    result = (IMaterial *)var;
LABEL_4:
    v3 = g_pMaterialSystem->FindMaterial(this: g_pMaterialSystem, a2: result, a3: 0, a4: 0, a5: 0);
    CMaterialReference::Init(this: p_m_mtlRef, pMaterial: v3);
    return p_m_mtlRef->m_pMaterial;
  }
  if ( result != nullptr )
    goto LABEL_4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0062AC50
// Name: public: virtual bool CDmeMaterial::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMaterial::IsA(CDmeMaterial *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMaterial::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062AC80
// Name: public: virtual int CDmeMaterial::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMaterial::GetInheritanceDepth(CDmeMaterial *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMaterial::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062ACC0
// Name: protected: virtual void CDmeMaterial::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMaterial::PerformConstruction(CDmeMaterial *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  this->m_mtlName.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "mtlName",
                                   type: AT_STRING,
                                   pMemory: &this->m_mtlName);
}

//------------------------------------------------------------------------------
// Address: 0x006B9510
// Name: _dynamic_initializer_for__CDmeMaterial::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMaterial::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMaterial::s_Allocator,
    blockSize: 0x50u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMaterial pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BD140
// Name: _dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMaterial::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMaterial::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B9540
// Name: _dynamic_initializer_for__g_CDmeMaterial_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMaterial_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9550
// Name: _dynamic_initializer_for__g_CDmeMaterial_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMaterial_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMaterial_Helper,
           classname: "DmeMaterial",
           pFactory: &g_CDmeMaterial_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BD150
// Name: _dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMaterial_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeMaterial_Factory.m_CallBackList);
}

} // namespace vmap
