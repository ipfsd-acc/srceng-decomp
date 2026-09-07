// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/dmemotioncontrol.cpp
// Functions: 10
// ============================================================

#include "mdlobjects\dmemotioncontrol.h"

//------------------------------------------------------------------------------
// Address: 0x0049EAA0
// Name: protected: void CDmeMotionControl::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMotionControl::OnConstruction(CDmeMotionControl *this)
{
  this->m_bX.m_pAttribute = CDmElement::AddExternalAttribute(
                              this,
                              pAttributeName: "X",
                              type: AT_BOOL,
                              pMemory: &this->m_bX);
  this->m_bY.m_pAttribute = CDmElement::AddExternalAttribute(
                              this,
                              pAttributeName: "Y",
                              type: AT_BOOL,
                              pMemory: &this->m_bY);
  this->m_bZ.m_pAttribute = CDmElement::AddExternalAttribute(
                              this,
                              pAttributeName: "Z",
                              type: AT_BOOL,
                              pMemory: &this->m_bZ);
  this->m_bXR.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "XR",
                               type: AT_BOOL,
                               pMemory: &this->m_bXR);
  this->m_bYR.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "YR",
                               type: AT_BOOL,
                               pMemory: &this->m_bYR);
  this->m_bZR.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "ZR",
                               type: AT_BOOL,
                               pMemory: &this->m_bZR);
  this->m_bLX.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "LX",
                               type: AT_BOOL,
                               pMemory: &this->m_bLX);
  this->m_bLY.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "LY",
                               type: AT_BOOL,
                               pMemory: &this->m_bLY);
  this->m_bLZ.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "LZ",
                               type: AT_BOOL,
                               pMemory: &this->m_bLZ);
  this->m_bLXR.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "LXR",
                                type: AT_BOOL,
                                pMemory: &this->m_bLXR);
  this->m_bLYR.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "LYR",
                                type: AT_BOOL,
                                pMemory: &this->m_bLYR);
  this->m_bLZR.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "LZR",
                                type: AT_BOOL,
                                pMemory: &this->m_bLZR);
  this->m_bLM.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "LM",
                               type: AT_BOOL,
                               pMemory: &this->m_bLM);
}

//------------------------------------------------------------------------------
// Address: 0x0049EC30
// Name: protected: CDmeMotionControl::CDmeMotionControl(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMotionControl *__thiscall CDmeMotionControl::CDmeMotionControl(
        CDmeMotionControl *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeMotionControl_vtbl *)&CDmeMotionControl::`vftable';
  this->m_bX.m_pAttribute = nullptr;
  this->m_bX.m_Storage = false;
  this->m_bY.m_pAttribute = nullptr;
  this->m_bY.m_Storage = false;
  this->m_bZ.m_pAttribute = nullptr;
  this->m_bZ.m_Storage = false;
  this->m_bXR.m_pAttribute = nullptr;
  this->m_bXR.m_Storage = false;
  this->m_bYR.m_pAttribute = nullptr;
  this->m_bYR.m_Storage = false;
  this->m_bZR.m_pAttribute = nullptr;
  this->m_bZR.m_Storage = false;
  this->m_bLX.m_pAttribute = nullptr;
  this->m_bLX.m_Storage = false;
  this->m_bLY.m_pAttribute = nullptr;
  this->m_bLY.m_Storage = false;
  this->m_bLZ.m_pAttribute = nullptr;
  this->m_bLZ.m_Storage = false;
  this->m_bLXR.m_pAttribute = nullptr;
  this->m_bLXR.m_Storage = false;
  this->m_bLYR.m_pAttribute = nullptr;
  this->m_bLYR.m_Storage = false;
  this->m_bLZR.m_pAttribute = nullptr;
  this->m_bLZR.m_Storage = false;
  this->m_bLM.m_pAttribute = nullptr;
  this->m_bLM.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0049ED00
// Name: public: virtual bool CDmeMotionControl::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMotionControl::IsA(CDmeMotionControl *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMotionControl::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049ED30
// Name: public: virtual int CDmeMotionControl::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMotionControl::GetInheritanceDepth(CDmeMotionControl *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMotionControl::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0049EDC0
// Name: protected: virtual void CDmeMotionControl::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMotionControl::PerformConstruction(CDmeMotionControl *this)
{
  CDmeFXClip::OnDestruction();
  CDmeMotionControl::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00598D00
// Name: _dynamic_initializer_for__CDmeMotionControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMotionControl::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMotionControl::s_Allocator,
    blockSize: 172,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMotionControl pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMotionControl::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059E160
// Name: _dynamic_atexit_destructor_for__CDmeMotionControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMotionControl::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMotionControl::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00598D30
// Name: _dynamic_initializer_for__g_CDmeMotionControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMotionControl_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMotionControl_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00598D40
// Name: _dynamic_initializer_for__g_CDmeMotionControl_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMotionControl_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMotionControl_Helper,
           classname: "DmeMotionControl",
           pFactory: &g_CDmeMotionControl_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059E170
// Name: _dynamic_atexit_destructor_for__g_CDmeMotionControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMotionControl_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMotionControl_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004EBA40
// Name: protected: void CDmeMotionControl::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMotionControl::OnConstruction(CDmeMotionControl *this)
{
  this->m_bX.m_pAttribute = CDmElement::AddExternalAttribute(
                              this,
                              pAttributeName: "X",
                              type: AT_BOOL,
                              pMemory: &this->m_bX);
  this->m_bY.m_pAttribute = CDmElement::AddExternalAttribute(
                              this,
                              pAttributeName: "Y",
                              type: AT_BOOL,
                              pMemory: &this->m_bY);
  this->m_bZ.m_pAttribute = CDmElement::AddExternalAttribute(
                              this,
                              pAttributeName: "Z",
                              type: AT_BOOL,
                              pMemory: &this->m_bZ);
  this->m_bXR.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "XR",
                               type: AT_BOOL,
                               pMemory: &this->m_bXR);
  this->m_bYR.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "YR",
                               type: AT_BOOL,
                               pMemory: &this->m_bYR);
  this->m_bZR.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "ZR",
                               type: AT_BOOL,
                               pMemory: &this->m_bZR);
  this->m_bLX.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "LX",
                               type: AT_BOOL,
                               pMemory: &this->m_bLX);
  this->m_bLY.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "LY",
                               type: AT_BOOL,
                               pMemory: &this->m_bLY);
  this->m_bLZ.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "LZ",
                               type: AT_BOOL,
                               pMemory: &this->m_bLZ);
  this->m_bLXR.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "LXR",
                                type: AT_BOOL,
                                pMemory: &this->m_bLXR);
  this->m_bLYR.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "LYR",
                                type: AT_BOOL,
                                pMemory: &this->m_bLYR);
  this->m_bLZR.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "LZR",
                                type: AT_BOOL,
                                pMemory: &this->m_bLZR);
  this->m_bLM.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "LM",
                               type: AT_BOOL,
                               pMemory: &this->m_bLM);
}

//------------------------------------------------------------------------------
// Address: 0x004EBB70
// Name: public: int CDmeMotionControl::GetStudioMotionControl(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMotionControl::GetStudioMotionControl(CDmeMotionControl *this)
{
  return this->m_bX.m_Storage
       | (this->m_bY.m_Storage ? 2 : 0)
       | (this->m_bZ.m_Storage ? 4 : 0)
       | (this->m_bXR.m_Storage ? 8 : 0)
       | (this->m_bYR.m_Storage ? 0x10 : 0)
       | (this->m_bZR.m_Storage ? 0x20 : 0)
       | (this->m_bLX.m_Storage ? 0x40 : 0)
       | (this->m_bLY.m_Storage ? 0x80 : 0)
       | (this->m_bLZ.m_Storage ? 0x100 : 0)
       | (this->m_bLXR.m_Storage ? 0x200 : 0)
       | (this->m_bLYR.m_Storage ? 0x400 : 0)
       | (this->m_bLZR.m_Storage ? 0x800 : 0)
       | (this->m_bLM.m_Storage ? 0x1000 : 0);
}

//------------------------------------------------------------------------------
// Address: 0x004EBCA0
// Name: protected: CDmeMotionControl::CDmeMotionControl(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMotionControl *__thiscall CDmeMotionControl::CDmeMotionControl(
        CDmeMotionControl *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeMotionControl_vtbl *)&CDmeMotionControl::`vftable';
  this->m_bX.m_pAttribute = nullptr;
  this->m_bX.m_Storage = false;
  this->m_bY.m_pAttribute = nullptr;
  this->m_bY.m_Storage = false;
  this->m_bZ.m_pAttribute = nullptr;
  this->m_bZ.m_Storage = false;
  this->m_bXR.m_pAttribute = nullptr;
  this->m_bXR.m_Storage = false;
  this->m_bYR.m_pAttribute = nullptr;
  this->m_bYR.m_Storage = false;
  this->m_bZR.m_pAttribute = nullptr;
  this->m_bZR.m_Storage = false;
  this->m_bLX.m_pAttribute = nullptr;
  this->m_bLX.m_Storage = false;
  this->m_bLY.m_pAttribute = nullptr;
  this->m_bLY.m_Storage = false;
  this->m_bLZ.m_pAttribute = nullptr;
  this->m_bLZ.m_Storage = false;
  this->m_bLXR.m_pAttribute = nullptr;
  this->m_bLXR.m_Storage = false;
  this->m_bLYR.m_pAttribute = nullptr;
  this->m_bLYR.m_Storage = false;
  this->m_bLZR.m_pAttribute = nullptr;
  this->m_bLZR.m_Storage = false;
  this->m_bLM.m_pAttribute = nullptr;
  this->m_bLM.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004EBD70
// Name: public: virtual bool CDmeMotionControl::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMotionControl::IsA(CDmeMotionControl *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMotionControl::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EBDA0
// Name: public: virtual int CDmeMotionControl::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMotionControl::GetInheritanceDepth(CDmeMotionControl *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMotionControl::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EBE20
// Name: protected: virtual void CDmeMotionControl::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMotionControl::PerformConstruction(CDmeMotionControl *this)
{
  CDmeFXClip::OnDestruction();
  CDmeMotionControl::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005EEA20
// Name: _dynamic_initializer_for__CDmeMotionControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMotionControl::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMotionControl::s_Allocator,
    blockSize: 172,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMotionControl pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMotionControl::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F39F0
// Name: _dynamic_atexit_destructor_for__CDmeMotionControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMotionControl::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMotionControl::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EEA50
// Name: _dynamic_initializer_for__g_CDmeMotionControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMotionControl_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMotionControl_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EEA60
// Name: _dynamic_initializer_for__g_CDmeMotionControl_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMotionControl_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMotionControl_Helper,
           classname: "DmeMotionControl",
           pFactory: &g_CDmeMotionControl_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3A00
// Name: _dynamic_atexit_destructor_for__g_CDmeMotionControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMotionControl_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMotionControl_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0050E650
// Name: protected: void CDmeMotionControl::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMotionControl::OnConstruction(CDmeMotionControl *this)
{
  this->m_bX.m_pAttribute = CDmElement::AddExternalAttribute(
                              this,
                              pAttributeName: "X",
                              type: AT_BOOL,
                              pMemory: &this->m_bX);
  this->m_bY.m_pAttribute = CDmElement::AddExternalAttribute(
                              this,
                              pAttributeName: "Y",
                              type: AT_BOOL,
                              pMemory: &this->m_bY);
  this->m_bZ.m_pAttribute = CDmElement::AddExternalAttribute(
                              this,
                              pAttributeName: "Z",
                              type: AT_BOOL,
                              pMemory: &this->m_bZ);
  this->m_bXR.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "XR",
                               type: AT_BOOL,
                               pMemory: &this->m_bXR);
  this->m_bYR.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "YR",
                               type: AT_BOOL,
                               pMemory: &this->m_bYR);
  this->m_bZR.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "ZR",
                               type: AT_BOOL,
                               pMemory: &this->m_bZR);
  this->m_bLX.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "LX",
                               type: AT_BOOL,
                               pMemory: &this->m_bLX);
  this->m_bLY.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "LY",
                               type: AT_BOOL,
                               pMemory: &this->m_bLY);
  this->m_bLZ.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "LZ",
                               type: AT_BOOL,
                               pMemory: &this->m_bLZ);
  this->m_bLXR.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "LXR",
                                type: AT_BOOL,
                                pMemory: &this->m_bLXR);
  this->m_bLYR.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "LYR",
                                type: AT_BOOL,
                                pMemory: &this->m_bLYR);
  this->m_bLZR.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "LZR",
                                type: AT_BOOL,
                                pMemory: &this->m_bLZR);
  this->m_bLM.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "LM",
                               type: AT_BOOL,
                               pMemory: &this->m_bLM);
}

//------------------------------------------------------------------------------
// Address: 0x0050E7E0
// Name: protected: CDmeMotionControl::CDmeMotionControl(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMotionControl *__thiscall CDmeMotionControl::CDmeMotionControl(
        CDmeMotionControl *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeMotionControl_vtbl *)&CDmeMotionControl::`vftable';
  this->m_bX.m_pAttribute = nullptr;
  this->m_bX.m_Storage = false;
  this->m_bY.m_pAttribute = nullptr;
  this->m_bY.m_Storage = false;
  this->m_bZ.m_pAttribute = nullptr;
  this->m_bZ.m_Storage = false;
  this->m_bXR.m_pAttribute = nullptr;
  this->m_bXR.m_Storage = false;
  this->m_bYR.m_pAttribute = nullptr;
  this->m_bYR.m_Storage = false;
  this->m_bZR.m_pAttribute = nullptr;
  this->m_bZR.m_Storage = false;
  this->m_bLX.m_pAttribute = nullptr;
  this->m_bLX.m_Storage = false;
  this->m_bLY.m_pAttribute = nullptr;
  this->m_bLY.m_Storage = false;
  this->m_bLZ.m_pAttribute = nullptr;
  this->m_bLZ.m_Storage = false;
  this->m_bLXR.m_pAttribute = nullptr;
  this->m_bLXR.m_Storage = false;
  this->m_bLYR.m_pAttribute = nullptr;
  this->m_bLYR.m_Storage = false;
  this->m_bLZR.m_pAttribute = nullptr;
  this->m_bLZR.m_Storage = false;
  this->m_bLM.m_pAttribute = nullptr;
  this->m_bLM.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0050E8B0
// Name: public: virtual bool CDmeMotionControl::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMotionControl::IsA(CDmeMotionControl *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMotionControl::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050E8E0
// Name: public: virtual int CDmeMotionControl::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMotionControl::GetInheritanceDepth(CDmeMotionControl *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMotionControl::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050E960
// Name: protected: virtual void CDmeMotionControl::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMotionControl::PerformConstruction(CDmeMotionControl *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeMotionControl::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006AD100
// Name: _dynamic_initializer_for__CDmeMotionControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMotionControl::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMotionControl::s_Allocator,
    blockSize: 172,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMotionControl pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMotionControl::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B3F30
// Name: _dynamic_atexit_destructor_for__CDmeMotionControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMotionControl::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMotionControl::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AD130
// Name: _dynamic_initializer_for__g_CDmeMotionControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMotionControl_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMotionControl_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AD140
// Name: _dynamic_initializer_for__g_CDmeMotionControl_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMotionControl_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMotionControl_Helper,
           classname: "DmeMotionControl",
           pFactory: &g_CDmeMotionControl_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B3F40
// Name: _dynamic_atexit_destructor_for__g_CDmeMotionControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMotionControl_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMotionControl_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004DE0C0
// Name: protected: void CDmeMotionControl::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMotionControl::OnConstruction(CDmeMotionControl *this)
{
  this->m_bX.m_pAttribute = CDmElement::AddExternalAttribute(
                              this,
                              pAttributeName: "X",
                              type: AT_BOOL,
                              pMemory: &this->m_bX);
  this->m_bY.m_pAttribute = CDmElement::AddExternalAttribute(
                              this,
                              pAttributeName: "Y",
                              type: AT_BOOL,
                              pMemory: &this->m_bY);
  this->m_bZ.m_pAttribute = CDmElement::AddExternalAttribute(
                              this,
                              pAttributeName: "Z",
                              type: AT_BOOL,
                              pMemory: &this->m_bZ);
  this->m_bXR.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "XR",
                               type: AT_BOOL,
                               pMemory: &this->m_bXR);
  this->m_bYR.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "YR",
                               type: AT_BOOL,
                               pMemory: &this->m_bYR);
  this->m_bZR.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "ZR",
                               type: AT_BOOL,
                               pMemory: &this->m_bZR);
  this->m_bLX.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "LX",
                               type: AT_BOOL,
                               pMemory: &this->m_bLX);
  this->m_bLY.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "LY",
                               type: AT_BOOL,
                               pMemory: &this->m_bLY);
  this->m_bLZ.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "LZ",
                               type: AT_BOOL,
                               pMemory: &this->m_bLZ);
  this->m_bLXR.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "LXR",
                                type: AT_BOOL,
                                pMemory: &this->m_bLXR);
  this->m_bLYR.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "LYR",
                                type: AT_BOOL,
                                pMemory: &this->m_bLYR);
  this->m_bLZR.m_pAttribute = CDmElement::AddExternalAttribute(
                                this,
                                pAttributeName: "LZR",
                                type: AT_BOOL,
                                pMemory: &this->m_bLZR);
  this->m_bLM.m_pAttribute = CDmElement::AddExternalAttribute(
                               this,
                               pAttributeName: "LM",
                               type: AT_BOOL,
                               pMemory: &this->m_bLM);
}

//------------------------------------------------------------------------------
// Address: 0x004DE250
// Name: protected: CDmeMotionControl::CDmeMotionControl(enum DmElementHandle_t,char const __near *,struct UniqueId_t const __near &,char const __near *,enum DmFileId_t)
// Source: json
//------------------------------------------------------------------------------
CDmeMotionControl *__thiscall CDmeMotionControl::CDmeMotionControl(
        CDmeMotionControl *this,
        DmElementHandle_t handle,
        const char *pElementTypeName,
        const UniqueId_t *id,
        const char *pElementName,
        DmFileId_t fileid)
{
  CDmElement::CDmElement(this, handle, pElementType: pElementTypeName, id, pElementName, fileid);
  this->__vftable = (CDmeMotionControl_vtbl *)&CDmeMotionControl::`vftable';
  this->m_bX.m_pAttribute = nullptr;
  this->m_bX.m_Storage = false;
  this->m_bY.m_pAttribute = nullptr;
  this->m_bY.m_Storage = false;
  this->m_bZ.m_pAttribute = nullptr;
  this->m_bZ.m_Storage = false;
  this->m_bXR.m_pAttribute = nullptr;
  this->m_bXR.m_Storage = false;
  this->m_bYR.m_pAttribute = nullptr;
  this->m_bYR.m_Storage = false;
  this->m_bZR.m_pAttribute = nullptr;
  this->m_bZR.m_Storage = false;
  this->m_bLX.m_pAttribute = nullptr;
  this->m_bLX.m_Storage = false;
  this->m_bLY.m_pAttribute = nullptr;
  this->m_bLY.m_Storage = false;
  this->m_bLZ.m_pAttribute = nullptr;
  this->m_bLZ.m_Storage = false;
  this->m_bLXR.m_pAttribute = nullptr;
  this->m_bLXR.m_Storage = false;
  this->m_bLYR.m_pAttribute = nullptr;
  this->m_bLYR.m_Storage = false;
  this->m_bLZR.m_pAttribute = nullptr;
  this->m_bLZR.m_Storage = false;
  this->m_bLM.m_pAttribute = nullptr;
  this->m_bLM.m_Storage = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004DE320
// Name: public: virtual bool CDmeMotionControl::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMotionControl::IsA(CDmeMotionControl *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMotionControl::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DE350
// Name: public: virtual int CDmeMotionControl::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMotionControl::GetInheritanceDepth(CDmeMotionControl *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMotionControl::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004DE3D0
// Name: protected: virtual void CDmeMotionControl::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMotionControl::PerformConstruction(CDmeMotionControl *this)
{
  CDmeFXClip::OnDestruction();
  CDmeMotionControl::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005E67D0
// Name: _dynamic_initializer_for__CDmeMotionControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMotionControl::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMotionControl::s_Allocator,
    blockSize: 172,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMotionControl pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMotionControl::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EC2F0
// Name: _dynamic_atexit_destructor_for__CDmeMotionControl::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMotionControl::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMotionControl::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E6800
// Name: _dynamic_initializer_for__g_CDmeMotionControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMotionControl_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMotionControl_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E6810
// Name: _dynamic_initializer_for__g_CDmeMotionControl_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMotionControl_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMotionControl_Helper,
           classname: "DmeMotionControl",
           pFactory: &g_CDmeMotionControl_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EC300
// Name: _dynamic_atexit_destructor_for__g_CDmeMotionControl_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMotionControl_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMotionControl_Factory.m_CallBackList);
}

} // namespace studiomdl
