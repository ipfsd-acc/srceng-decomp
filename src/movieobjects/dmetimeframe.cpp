// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmetimeframe.cpp
// Functions: 11
// ============================================================

#include "movieobjects\dmetimeframe.h"

//------------------------------------------------------------------------------
// Address: 0x004B8A40
// Name: public: virtual void CDmeTimeFrame::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeTimeFrame::OnAttributeChanged(
        CDmeTimeFrame *this@<ecx>,
        DmAttributeReferenceIterator_t a2@<edi>,
        CDmAttribute *pAttribute)
{
  DmElementHandle_t v3; // eax

  if ( pAttribute == this->m_Start.m_pAttribute || pAttribute == this->m_Duration.m_pAttribute )
  {
    v3 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
    InvokeOnAttributeChangedOnReferrers(a1: a2, hElement: v3, pChangedAttr: pAttribute);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B8A70
// Name: protected: void CDmeTimeFrame::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeFrame::OnConstruction(CDmeTimeFrame *this)
{
  CDmaTime *p_m_Start; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  DmeTime_t value; // [esp+8h] [ebp-4h] BYREF

  p_m_Start = &this->m_Start;
  value.m_tms = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "start", type: AT_TIME, pMemory: &this->m_Start);
  p_m_Start->m_pAttribute = v3;
  CDmAttribute::SetValue<DmeTime_t>(this: v3, &value);
  p_m_Start->m_pAttribute->m_nFlags |= 0x100u;
  value.m_tms = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "duration", type: AT_TIME, pMemory: &this->m_Duration);
  this->m_Duration.m_pAttribute = v4;
  CDmAttribute::SetValue<DmeTime_t>(this: v4, &value);
  this->m_Duration.m_pAttribute->m_nFlags |= 0x100u;
  value.m_tms = 0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "offset", type: AT_TIME, pMemory: &this->m_Offset);
  this->m_Offset.m_pAttribute = v5;
  CDmAttribute::SetValue<DmeTime_t>(this: v5, &value);
  value.m_tms = 1065353216;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_Scale);
  this->m_Scale.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (float *)&value.m_tms);
}

//------------------------------------------------------------------------------
// Address: 0x004B8BD0
// Name: public: virtual bool CDmeTimeFrame::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTimeFrame::IsA(CDmeTimeFrame *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTimeFrame::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B8C00
// Name: public: virtual int CDmeTimeFrame::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeFrame::GetInheritanceDepth(CDmeTimeFrame *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTimeFrame::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B8CB0
// Name: protected: virtual void CDmeTimeFrame::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeFrame::PerformConstruction(CDmeTimeFrame *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTimeFrame::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0055BFA0
// Name: protected: virtual int CDmeTimeFrame::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeFrame::AllocatedSize(CDmeTimeFrame *this)
{
  return 100;
}

//------------------------------------------------------------------------------
// Address: 0x005AC720
// Name: _dynamic_initializer_for__CDmeTimeFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTimeFrame::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTimeFrame::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTimeFrame pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AFE40
// Name: _dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTimeFrame::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AC750
// Name: _dynamic_initializer_for__g_CDmeTimeFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTimeFrame_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AC760
// Name: _dynamic_initializer_for__g_CDmeTimeFrame_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTimeFrame_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTimeFrame_Helper,
           classname: "DmeTimeFrame",
           pFactory: &g_CDmeTimeFrame_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AFE50
// Name: _dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTimeFrame_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x0050EEA0
// Name: public: virtual void CDmeTimeFrame::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeTimeFrame::OnAttributeChanged(
        CDmeTimeFrame *this@<ecx>,
        DmAttributeReferenceIterator_t a2@<edi>,
        CDmAttribute *pAttribute)
{
  DmElementHandle_t BufferType; // eax

  if ( pAttribute == this->m_Start.m_pAttribute || pAttribute == this->m_Duration.m_pAttribute )
  {
    BufferType = CCodecBuffer_Block::GetBufferType((CExpressionCalculator *)this);
    InvokeOnAttributeChangedOnReferrers(a1: a2, hElement: BufferType, pChangedAttr: pAttribute);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050EED0
// Name: protected: void CDmeTimeFrame::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeFrame::OnConstruction(CDmeTimeFrame *this)
{
  CDmaTime *p_m_Start; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  DmeTime_t value; // [esp+8h] [ebp-4h] BYREF

  p_m_Start = &this->m_Start;
  value.m_tms = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "start", type: AT_TIME, pMemory: &this->m_Start);
  p_m_Start->m_pAttribute = v3;
  CDmAttribute::SetValue<DmeTime_t>(this: v3, &value);
  p_m_Start->m_pAttribute->m_nFlags |= 0x100u;
  value.m_tms = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "duration", type: AT_TIME, pMemory: &this->m_Duration);
  this->m_Duration.m_pAttribute = v4;
  CDmAttribute::SetValue<DmeTime_t>(this: v4, &value);
  this->m_Duration.m_pAttribute->m_nFlags |= 0x100u;
  value.m_tms = 0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "offset", type: AT_TIME, pMemory: &this->m_Offset);
  this->m_Offset.m_pAttribute = v5;
  CDmAttribute::SetValue<DmeTime_t>(this: v5, &value);
  value.m_tms = 1065353216;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_Scale);
  this->m_Scale.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (const float *)&value.m_tms);
}

//------------------------------------------------------------------------------
// Address: 0x0050F030
// Name: public: virtual bool CDmeTimeFrame::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTimeFrame::IsA(CDmeTimeFrame *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTimeFrame::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050F060
// Name: public: virtual int CDmeTimeFrame::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeFrame::GetInheritanceDepth(CDmeTimeFrame *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTimeFrame::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050F110
// Name: protected: virtual void CDmeTimeFrame::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeFrame::PerformConstruction(CDmeTimeFrame *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeTimeFrame::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005C9390
// Name: protected: virtual int CDmeTimeFrame::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeFrame::AllocatedSize(CDmeTimeFrame *this)
{
  return 100;
}

//------------------------------------------------------------------------------
// Address: 0x0067DE50
// Name: _dynamic_initializer_for__CDmeTimeFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTimeFrame::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTimeFrame::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTimeFrame pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00682310
// Name: _dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTimeFrame::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067DE80
// Name: _dynamic_initializer_for__g_CDmeTimeFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTimeFrame_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067DE90
// Name: _dynamic_initializer_for__g_CDmeTimeFrame_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTimeFrame_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTimeFrame_Helper,
           classname: "DmeTimeFrame",
           pFactory: &g_CDmeTimeFrame_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00682320
// Name: _dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeTimeFrame_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10594940
// Name: public: virtual void CDmeTimeFrame::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeTimeFrame::OnAttributeChanged(
        CDmeTimeFrame *this@<ecx>,
        DmAttributeReferenceIterator_t a2@<edi>,
        CDmAttribute *pAttribute)
{
  DmElementHandle_t BufferType; // eax

  if ( pAttribute == this->m_Start.m_pAttribute || pAttribute == this->m_Duration.m_pAttribute )
  {
    BufferType = CCodecBuffer_Block::GetBufferType((CExpressionCalculator *)this);
    InvokeOnAttributeChangedOnReferrers(a1: a2, hElement: BufferType, pChangedAttr: pAttribute);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10594970
// Name: protected: void CDmeTimeFrame::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeFrame::OnConstruction(CDmeTimeFrame *this)
{
  CDmaTime *p_m_Start; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  DmeTime_t value; // [esp+8h] [ebp-4h] BYREF

  p_m_Start = &this->m_Start;
  value.m_tms = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "start", type: AT_TIME, pMemory: &this->m_Start);
  p_m_Start->m_pAttribute = v3;
  CDmAttribute::SetValue<DmeTime_t>(this: v3, &value);
  p_m_Start->m_pAttribute->m_nFlags |= 0x100u;
  value.m_tms = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "duration", type: AT_TIME, pMemory: &this->m_Duration);
  this->m_Duration.m_pAttribute = v4;
  CDmAttribute::SetValue<DmeTime_t>(this: v4, &value);
  this->m_Duration.m_pAttribute->m_nFlags |= 0x100u;
  value.m_tms = 0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "offset", type: AT_TIME, pMemory: &this->m_Offset);
  this->m_Offset.m_pAttribute = v5;
  CDmAttribute::SetValue<DmeTime_t>(this: v5, &value);
  value.m_tms = 1065353216;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_Scale);
  this->m_Scale.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (float *)&value.m_tms);
}

//------------------------------------------------------------------------------
// Address: 0x10594AD0
// Name: public: virtual bool CDmeTimeFrame::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTimeFrame::IsA(CDmeTimeFrame *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTimeFrame::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10594B00
// Name: public: virtual int CDmeTimeFrame::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeFrame::GetInheritanceDepth(CDmeTimeFrame *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTimeFrame::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10594BB0
// Name: protected: virtual void CDmeTimeFrame::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeFrame::PerformConstruction(CDmeTimeFrame *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeTimeFrame::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x1059BAB0
// Name: protected: virtual int CDmeTimeFrame::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeFrame::AllocatedSize(CDmeTimeFrame *this)
{
  return 100;
}

//------------------------------------------------------------------------------
// Address: 0x105C9650
// Name: _dynamic_initializer_for__CDmeTimeFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTimeFrame::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTimeFrame::s_Allocator,
    blockSize: 0x64u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTimeFrame pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CDA30
// Name: _dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTimeFrame::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C9680
// Name: _dynamic_initializer_for__g_CDmeTimeFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTimeFrame_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9690
// Name: _dynamic_initializer_for__g_CDmeTimeFrame_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTimeFrame_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTimeFrame_Helper,
           classname: "DmeTimeFrame",
           pFactory: &g_CDmeTimeFrame_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CDA40
// Name: _dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeTimeFrame_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x004C1180
// Name: public: virtual void CDmeTimeFrame::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeTimeFrame::OnAttributeChanged(CDmeTimeFrame *this@<ecx>, int a2@<edi>, CDmAttribute *pAttribute)
{
  DmElementHandle_t Handle; // eax

  if ( pAttribute == this->m_Start.m_pAttribute || pAttribute == this->m_Duration.m_pAttribute )
  {
    Handle = CDmElement::GetHandle(this);
    InvokeOnAttributeChangedOnReferrers(a1: a2, hElement: Handle, pChangedAttr: pAttribute);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004C11B0
// Name: protected: void CDmeTimeFrame::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeFrame::OnConstruction(CDmeTimeFrame *this)
{
  CDmaTime *p_m_Start; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  DmeTime_t value; // [esp+8h] [ebp-4h] BYREF

  p_m_Start = &this->m_Start;
  value.m_tms = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "start", type: AT_TIME, pMemory: &this->m_Start);
  p_m_Start->m_pAttribute = v3;
  CDmAttribute::SetValue<DmeTime_t>(this: v3, &value);
  p_m_Start->m_pAttribute->m_nFlags |= 0x100u;
  value.m_tms = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "duration", type: AT_TIME, pMemory: &this->m_Duration);
  this->m_Duration.m_pAttribute = v4;
  CDmAttribute::SetValue<DmeTime_t>(this: v4, &value);
  this->m_Duration.m_pAttribute->m_nFlags |= 0x100u;
  value.m_tms = 0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "offset", type: AT_TIME, pMemory: &this->m_Offset);
  this->m_Offset.m_pAttribute = v5;
  CDmAttribute::SetValue<DmeTime_t>(this: v5, &value);
  value.m_tms = 1065353216;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_Scale);
  this->m_Scale.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (float *)&value.m_tms);
}

//------------------------------------------------------------------------------
// Address: 0x004C1310
// Name: public: virtual bool CDmeTimeFrame::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTimeFrame::IsA(CDmeTimeFrame *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTimeFrame::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004C1340
// Name: public: virtual int CDmeTimeFrame::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeFrame::GetInheritanceDepth(CDmeTimeFrame *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTimeFrame::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004C1400
// Name: protected: virtual void CDmeTimeFrame::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeFrame::PerformConstruction(CDmeTimeFrame *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTimeFrame::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0059B880
// Name: _dynamic_initializer_for__CDmeTimeFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTimeFrame::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTimeFrame::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTimeFrame pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059EFF0
// Name: _dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTimeFrame::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059B8B0
// Name: _dynamic_initializer_for__g_CDmeTimeFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTimeFrame_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059B8C0
// Name: _dynamic_initializer_for__g_CDmeTimeFrame_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTimeFrame_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTimeFrame_Helper,
           classname: "DmeTimeFrame",
           pFactory: &g_CDmeTimeFrame_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059F000
// Name: _dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTimeFrame_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x0050EF60
// Name: public: virtual void CDmeTimeFrame::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeTimeFrame::OnAttributeChanged(CDmeTimeFrame *this@<ecx>, int a2@<edi>, CDmAttribute *pAttribute)
{
  DmElementHandle_t v3; // eax

  if ( pAttribute == this->m_Start.m_pAttribute || pAttribute == this->m_Duration.m_pAttribute )
  {
    v3 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
    InvokeOnAttributeChangedOnReferrers(a1: a2, hElement: v3, pChangedAttr: pAttribute);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050EF90
// Name: protected: void CDmeTimeFrame::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeFrame::OnConstruction(CDmeTimeFrame *this)
{
  CDmaTime *p_m_Start; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  DmeTime_t value; // [esp+8h] [ebp-4h] BYREF

  p_m_Start = &this->m_Start;
  value.m_tms = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "start", type: AT_TIME, pMemory: &this->m_Start);
  p_m_Start->m_pAttribute = v3;
  CDmAttribute::SetValue<DmeTime_t>(this: v3, &value);
  p_m_Start->m_pAttribute->m_nFlags |= 0x100u;
  value.m_tms = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "duration", type: AT_TIME, pMemory: &this->m_Duration);
  this->m_Duration.m_pAttribute = v4;
  CDmAttribute::SetValue<DmeTime_t>(this: v4, &value);
  this->m_Duration.m_pAttribute->m_nFlags |= 0x100u;
  value.m_tms = 0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "offset", type: AT_TIME, pMemory: &this->m_Offset);
  this->m_Offset.m_pAttribute = v5;
  CDmAttribute::SetValue<DmeTime_t>(this: v5, &value);
  value.m_tms = 1065353216;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_Scale);
  this->m_Scale.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (float *)&value.m_tms);
}

//------------------------------------------------------------------------------
// Address: 0x0050F0F0
// Name: public: virtual bool CDmeTimeFrame::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTimeFrame::IsA(CDmeTimeFrame *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTimeFrame::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050F120
// Name: public: virtual int CDmeTimeFrame::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeFrame::GetInheritanceDepth(CDmeTimeFrame *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTimeFrame::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050F1D0
// Name: protected: virtual void CDmeTimeFrame::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeFrame::PerformConstruction(CDmeTimeFrame *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTimeFrame::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005F08D0
// Name: _dynamic_initializer_for__CDmeTimeFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTimeFrame::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTimeFrame::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTimeFrame pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F4440
// Name: _dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTimeFrame::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F0900
// Name: _dynamic_initializer_for__g_CDmeTimeFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTimeFrame_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0910
// Name: _dynamic_initializer_for__g_CDmeTimeFrame_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTimeFrame_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTimeFrame_Helper,
           classname: "DmeTimeFrame",
           pFactory: &g_CDmeTimeFrame_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F4450
// Name: _dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTimeFrame_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00479DE0
// Name: public: virtual void CDmeTimeFrame::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeTimeFrame::OnAttributeChanged(
        CDmeTimeFrame *this@<ecx>,
        DmAttributeReferenceIterator_t a2@<edi>,
        CDmAttribute *pAttribute)
{
  DmElementHandle_t v3; // eax

  if ( pAttribute == this->m_Start.m_pAttribute || pAttribute == this->m_Duration.m_pAttribute )
  {
    v3 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
    InvokeOnAttributeChangedOnReferrers(a1: a2, hElement: v3, pChangedAttr: pAttribute);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00479E10
// Name: protected: void CDmeTimeFrame::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeFrame::OnConstruction(CDmeTimeFrame *this)
{
  CDmaTime *p_m_Start; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  DmeTime_t value; // [esp+8h] [ebp-4h] BYREF

  p_m_Start = &this->m_Start;
  value.m_tms = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "start", type: AT_TIME, pMemory: &this->m_Start);
  p_m_Start->m_pAttribute = v3;
  CDmAttribute::SetValue<DmeTime_t>(this: v3, &value);
  p_m_Start->m_pAttribute->m_nFlags |= 0x100u;
  value.m_tms = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "duration", type: AT_TIME, pMemory: &this->m_Duration);
  this->m_Duration.m_pAttribute = v4;
  CDmAttribute::SetValue<DmeTime_t>(this: v4, &value);
  this->m_Duration.m_pAttribute->m_nFlags |= 0x100u;
  value.m_tms = 0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "offset", type: AT_TIME, pMemory: &this->m_Offset);
  this->m_Offset.m_pAttribute = v5;
  CDmAttribute::SetValue<DmeTime_t>(this: v5, &value);
  value.m_tms = 1065353216;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_Scale);
  this->m_Scale.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (float *)&value.m_tms);
}

//------------------------------------------------------------------------------
// Address: 0x00479F70
// Name: public: virtual bool CDmeTimeFrame::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTimeFrame::IsA(CDmeTimeFrame *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTimeFrame::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00479FA0
// Name: public: virtual int CDmeTimeFrame::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeFrame::GetInheritanceDepth(CDmeTimeFrame *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTimeFrame::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047A050
// Name: protected: virtual void CDmeTimeFrame::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeFrame::PerformConstruction(CDmeTimeFrame *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTimeFrame::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0051D7F0
// Name: protected: virtual int CDmeTimeFrame::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeFrame::AllocatedSize(CDmeTimeFrame *this)
{
  return 100;
}

//------------------------------------------------------------------------------
// Address: 0x0056AA30
// Name: _dynamic_initializer_for__CDmeTimeFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTimeFrame::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTimeFrame::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTimeFrame pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056E4F0
// Name: _dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTimeFrame::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056AA60
// Name: _dynamic_initializer_for__g_CDmeTimeFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTimeFrame_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056AA70
// Name: _dynamic_initializer_for__g_CDmeTimeFrame_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTimeFrame_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTimeFrame_Helper,
           classname: "DmeTimeFrame",
           pFactory: &g_CDmeTimeFrame_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056E500
// Name: _dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTimeFrame_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0047EEF0
// Name: public: virtual void CDmeTimeFrame::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeTimeFrame::OnAttributeChanged(
        CDmeTimeFrame *this@<ecx>,
        DmAttributeReferenceIterator_t a2@<edi>,
        CDmAttribute *pAttribute)
{
  DmElementHandle_t v3; // eax

  if ( pAttribute == this->m_Start.m_pAttribute || pAttribute == this->m_Duration.m_pAttribute )
  {
    v3 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
    InvokeOnAttributeChangedOnReferrers(a1: a2, hElement: v3, pChangedAttr: pAttribute);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047EF20
// Name: protected: void CDmeTimeFrame::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeFrame::OnConstruction(CDmeTimeFrame *this)
{
  CDmaTime *p_m_Start; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  DmeTime_t value; // [esp+8h] [ebp-4h] BYREF

  p_m_Start = &this->m_Start;
  value.m_tms = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "start", type: AT_TIME, pMemory: &this->m_Start);
  p_m_Start->m_pAttribute = v3;
  CDmAttribute::SetValue<DmeTime_t>(this: v3, &value);
  p_m_Start->m_pAttribute->m_nFlags |= 0x100u;
  value.m_tms = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "duration", type: AT_TIME, pMemory: &this->m_Duration);
  this->m_Duration.m_pAttribute = v4;
  CDmAttribute::SetValue<DmeTime_t>(this: v4, &value);
  this->m_Duration.m_pAttribute->m_nFlags |= 0x100u;
  value.m_tms = 0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "offset", type: AT_TIME, pMemory: &this->m_Offset);
  this->m_Offset.m_pAttribute = v5;
  CDmAttribute::SetValue<DmeTime_t>(this: v5, &value);
  value.m_tms = 1065353216;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_Scale);
  this->m_Scale.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (const float *)&value.m_tms);
}

//------------------------------------------------------------------------------
// Address: 0x0047F080
// Name: public: virtual bool CDmeTimeFrame::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTimeFrame::IsA(CDmeTimeFrame *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTimeFrame::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047F0B0
// Name: public: virtual int CDmeTimeFrame::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeFrame::GetInheritanceDepth(CDmeTimeFrame *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTimeFrame::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047F160
// Name: protected: virtual void CDmeTimeFrame::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeFrame::PerformConstruction(CDmeTimeFrame *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTimeFrame::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00523A50
// Name: protected: virtual int CDmeTimeFrame::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeFrame::AllocatedSize(CDmeTimeFrame *this)
{
  return 100;
}

//------------------------------------------------------------------------------
// Address: 0x0057AB30
// Name: _dynamic_initializer_for__CDmeTimeFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTimeFrame::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTimeFrame::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTimeFrame pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E620
// Name: _dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTimeFrame::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057AB60
// Name: _dynamic_initializer_for__g_CDmeTimeFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTimeFrame_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057AB70
// Name: _dynamic_initializer_for__g_CDmeTimeFrame_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTimeFrame_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTimeFrame_Helper,
           classname: "DmeTimeFrame",
           pFactory: &g_CDmeTimeFrame_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E630
// Name: _dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTimeFrame_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005D84C0
// Name: public: virtual void CDmeTimeFrame::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeTimeFrame::OnAttributeChanged(CDmeTimeFrame *this@<ecx>, int a2@<edi>, CDmAttribute *pAttribute)
{
  DmElementHandle_t BufferType; // eax

  if ( pAttribute == this->m_Start.m_pAttribute || pAttribute == this->m_Duration.m_pAttribute )
  {
    BufferType = CCodecBuffer_Block::GetBufferType((CExpressionCalculator *)this);
    InvokeOnAttributeChangedOnReferrers(a1: a2, hElement: BufferType, pChangedAttr: pAttribute);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D84F0
// Name: protected: void CDmeTimeFrame::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeFrame::OnConstruction(CDmeTimeFrame *this)
{
  CDmaTime *p_m_Start; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  DmeTime_t value; // [esp+8h] [ebp-4h] BYREF

  p_m_Start = &this->m_Start;
  value.m_tms = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "start", type: AT_TIME, pMemory: &this->m_Start);
  p_m_Start->m_pAttribute = v3;
  CDmAttribute::SetValue<DmeTime_t>(this: v3, &value);
  p_m_Start->m_pAttribute->m_nFlags |= 0x100u;
  value.m_tms = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "duration", type: AT_TIME, pMemory: &this->m_Duration);
  this->m_Duration.m_pAttribute = v4;
  CDmAttribute::SetValue<DmeTime_t>(this: v4, &value);
  this->m_Duration.m_pAttribute->m_nFlags |= 0x100u;
  value.m_tms = 0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "offset", type: AT_TIME, pMemory: &this->m_Offset);
  this->m_Offset.m_pAttribute = v5;
  CDmAttribute::SetValue<DmeTime_t>(this: v5, &value);
  value.m_tms = 1065353216;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_Scale);
  this->m_Scale.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (const float *)&value.m_tms);
}

//------------------------------------------------------------------------------
// Address: 0x005D8650
// Name: public: virtual bool CDmeTimeFrame::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTimeFrame::IsA(CDmeTimeFrame *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTimeFrame::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D8680
// Name: public: virtual int CDmeTimeFrame::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeFrame::GetInheritanceDepth(CDmeTimeFrame *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTimeFrame::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D8730
// Name: protected: virtual void CDmeTimeFrame::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeFrame::PerformConstruction(CDmeTimeFrame *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeTimeFrame::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006B0B90
// Name: _dynamic_initializer_for__CDmeTimeFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTimeFrame::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTimeFrame::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTimeFrame pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5310
// Name: _dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTimeFrame::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B0BC0
// Name: _dynamic_initializer_for__g_CDmeTimeFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTimeFrame_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0BD0
// Name: _dynamic_initializer_for__g_CDmeTimeFrame_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTimeFrame_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTimeFrame_Helper,
           classname: "DmeTimeFrame",
           pFactory: &g_CDmeTimeFrame_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5320
// Name: _dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeTimeFrame_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0047FE90
// Name: public: virtual void CDmeTimeFrame::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeTimeFrame::OnAttributeChanged(
        CDmeTimeFrame *this@<ecx>,
        DmAttributeReferenceIterator_t a2@<edi>,
        CDmAttribute *pAttribute)
{
  DmElementHandle_t v3; // eax

  if ( pAttribute == this->m_Start.m_pAttribute || pAttribute == this->m_Duration.m_pAttribute )
  {
    v3 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
    InvokeOnAttributeChangedOnReferrers(a1: a2, hElement: v3, pChangedAttr: pAttribute);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047FEC0
// Name: protected: void CDmeTimeFrame::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeFrame::OnConstruction(CDmeTimeFrame *this)
{
  CDmaTime *p_m_Start; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  DmeTime_t value; // [esp+8h] [ebp-4h] BYREF

  p_m_Start = &this->m_Start;
  value.m_tms = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "start", type: AT_TIME, pMemory: &this->m_Start);
  p_m_Start->m_pAttribute = v3;
  CDmAttribute::SetValue<DmeTime_t>(this: v3, &value);
  p_m_Start->m_pAttribute->m_nFlags |= 0x100u;
  value.m_tms = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "duration", type: AT_TIME, pMemory: &this->m_Duration);
  this->m_Duration.m_pAttribute = v4;
  CDmAttribute::SetValue<DmeTime_t>(this: v4, &value);
  this->m_Duration.m_pAttribute->m_nFlags |= 0x100u;
  value.m_tms = 0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "offset", type: AT_TIME, pMemory: &this->m_Offset);
  this->m_Offset.m_pAttribute = v5;
  CDmAttribute::SetValue<DmeTime_t>(this: v5, &value);
  value.m_tms = 1065353216;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_Scale);
  this->m_Scale.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (const float *)&value.m_tms);
}

//------------------------------------------------------------------------------
// Address: 0x00480020
// Name: public: virtual bool CDmeTimeFrame::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTimeFrame::IsA(CDmeTimeFrame *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTimeFrame::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00480050
// Name: public: virtual int CDmeTimeFrame::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeFrame::GetInheritanceDepth(CDmeTimeFrame *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTimeFrame::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00480090
// Name: protected: virtual int CDmeTimeFrame::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeFrame::AllocatedSize(CDmeTimeFrame *this)
{
  return 100;
}

//------------------------------------------------------------------------------
// Address: 0x00480110
// Name: protected: virtual void CDmeTimeFrame::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeFrame::PerformConstruction(CDmeTimeFrame *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTimeFrame::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057CB20
// Name: _dynamic_initializer_for__CDmeTimeFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTimeFrame::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTimeFrame::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTimeFrame pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00580600
// Name: _dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTimeFrame::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057CB50
// Name: _dynamic_initializer_for__g_CDmeTimeFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTimeFrame_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CB60
// Name: _dynamic_initializer_for__g_CDmeTimeFrame_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTimeFrame_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTimeFrame_Helper,
           classname: "DmeTimeFrame",
           pFactory: &g_CDmeTimeFrame_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00580610
// Name: _dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTimeFrame_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x00507FA0
// Name: public: virtual void CDmeTimeFrame::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeTimeFrame::OnAttributeChanged(CDmeTimeFrame *this@<ecx>, int a2@<edi>, CDmAttribute *pAttribute)
{
  DmElementHandle_t v3; // eax

  if ( pAttribute == this->m_Start.m_pAttribute || pAttribute == this->m_Duration.m_pAttribute )
  {
    v3 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
    InvokeOnAttributeChangedOnReferrers(a1: a2, hElement: v3, pChangedAttr: pAttribute);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00507FD0
// Name: protected: void CDmeTimeFrame::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeFrame::OnConstruction(CDmeTimeFrame *this)
{
  CDmaTime *p_m_Start; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  DmeTime_t value; // [esp+8h] [ebp-4h] BYREF

  p_m_Start = &this->m_Start;
  value.m_tms = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "start", type: AT_TIME, pMemory: &this->m_Start);
  p_m_Start->m_pAttribute = v3;
  CDmAttribute::SetValue<DmeTime_t>(this: v3, &value);
  p_m_Start->m_pAttribute->m_nFlags |= 0x100u;
  value.m_tms = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "duration", type: AT_TIME, pMemory: &this->m_Duration);
  this->m_Duration.m_pAttribute = v4;
  CDmAttribute::SetValue<DmeTime_t>(this: v4, &value);
  this->m_Duration.m_pAttribute->m_nFlags |= 0x100u;
  value.m_tms = 0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "offset", type: AT_TIME, pMemory: &this->m_Offset);
  this->m_Offset.m_pAttribute = v5;
  CDmAttribute::SetValue<DmeTime_t>(this: v5, &value);
  value.m_tms = 1065353216;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_Scale);
  this->m_Scale.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (float *)&value.m_tms);
}

//------------------------------------------------------------------------------
// Address: 0x00508130
// Name: public: virtual bool CDmeTimeFrame::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTimeFrame::IsA(CDmeTimeFrame *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTimeFrame::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00508160
// Name: public: virtual int CDmeTimeFrame::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeFrame::GetInheritanceDepth(CDmeTimeFrame *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTimeFrame::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00508220
// Name: protected: virtual void CDmeTimeFrame::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeFrame::PerformConstruction(CDmeTimeFrame *this)
{
  CDmeFXClip::OnDestruction();
  CDmeTimeFrame::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005E9770
// Name: _dynamic_initializer_for__CDmeTimeFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTimeFrame::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTimeFrame::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTimeFrame pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED2E0
// Name: _dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTimeFrame::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E97A0
// Name: _dynamic_initializer_for__g_CDmeTimeFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTimeFrame_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E97B0
// Name: _dynamic_initializer_for__g_CDmeTimeFrame_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTimeFrame_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTimeFrame_Helper,
           classname: "DmeTimeFrame",
           pFactory: &g_CDmeTimeFrame_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED2F0
// Name: _dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTimeFrame_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x004889A0
// Name: public: virtual void CDmeTimeFrame::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeTimeFrame::OnAttributeChanged(
        CDmeTimeFrame *this@<ecx>,
        DmAttributeReferenceIterator_t a2@<edi>,
        CDmAttribute *pAttribute)
{
  DmElementHandle_t v3; // eax

  if ( pAttribute == this->m_Start.m_pAttribute || pAttribute == this->m_Duration.m_pAttribute )
  {
    v3 = CExpressionCalculator::VariableCount((CExpressionCalculator *)this);
    InvokeOnAttributeChangedOnReferrers(a1: a2, hElement: v3, pChangedAttr: pAttribute);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004889D0
// Name: protected: void CDmeTimeFrame::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeFrame::OnConstruction(CDmeTimeFrame *this)
{
  CDmaTime *p_m_Start; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  DmeTime_t value; // [esp+8h] [ebp-4h] BYREF

  p_m_Start = &this->m_Start;
  value.m_tms = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "start", type: AT_TIME, pMemory: &this->m_Start);
  p_m_Start->m_pAttribute = v3;
  CDmAttribute::SetValue<DmeTime_t>(this: v3, &value);
  p_m_Start->m_pAttribute->m_nFlags |= 0x100u;
  value.m_tms = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "duration", type: AT_TIME, pMemory: &this->m_Duration);
  this->m_Duration.m_pAttribute = v4;
  CDmAttribute::SetValue<DmeTime_t>(this: v4, &value);
  this->m_Duration.m_pAttribute->m_nFlags |= 0x100u;
  value.m_tms = 0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "offset", type: AT_TIME, pMemory: &this->m_Offset);
  this->m_Offset.m_pAttribute = v5;
  CDmAttribute::SetValue<DmeTime_t>(this: v5, &value);
  value.m_tms = 1065353216;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_Scale);
  this->m_Scale.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (const float *)&value.m_tms);
}

//------------------------------------------------------------------------------
// Address: 0x00488B30
// Name: public: virtual bool CDmeTimeFrame::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTimeFrame::IsA(CDmeTimeFrame *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTimeFrame::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00488B60
// Name: public: virtual int CDmeTimeFrame::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeFrame::GetInheritanceDepth(CDmeTimeFrame *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTimeFrame::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00488C10
// Name: protected: virtual void CDmeTimeFrame::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeFrame::PerformConstruction(CDmeTimeFrame *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeTimeFrame::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0052C140
// Name: protected: virtual int CDmeTimeFrame::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeFrame::AllocatedSize(CDmeTimeFrame *this)
{
  return 100;
}

//------------------------------------------------------------------------------
// Address: 0x0057A3D0
// Name: _dynamic_initializer_for__CDmeTimeFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTimeFrame::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTimeFrame::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTimeFrame pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DD10
// Name: _dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTimeFrame::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057A400
// Name: _dynamic_initializer_for__g_CDmeTimeFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTimeFrame_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A410
// Name: _dynamic_initializer_for__g_CDmeTimeFrame_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTimeFrame_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTimeFrame_Helper,
           classname: "DmeTimeFrame",
           pFactory: &g_CDmeTimeFrame_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057DD20
// Name: _dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTimeFrame_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0058B630
// Name: public: virtual void CDmeTimeFrame::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CDmeTimeFrame::OnAttributeChanged(
        CDmeTimeFrame *this@<ecx>,
        DmAttributeReferenceIterator_t a2@<edi>,
        CDmAttribute *pAttribute)
{
  DmElementHandle_t CenterVertIndex; // eax

  if ( pAttribute == this->m_Start.m_pAttribute || pAttribute == this->m_Duration.m_pAttribute )
  {
    CenterVertIndex = CCoreDispNode::GetCenterVertIndex((CVTFTexture *)this);
    InvokeOnAttributeChangedOnReferrers(a1: a2, hElement: CenterVertIndex, pChangedAttr: pAttribute);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0058B660
// Name: protected: void CDmeTimeFrame::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeFrame::OnConstruction(CDmeTimeFrame *this)
{
  CDmaTime *p_m_Start; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  CDmAttribute *v5; // eax
  CDmAttribute *v6; // eax
  DmeTime_t value; // [esp+8h] [ebp-4h] BYREF

  p_m_Start = &this->m_Start;
  value.m_tms = 0;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "start", type: AT_TIME, pMemory: &this->m_Start);
  p_m_Start->m_pAttribute = v3;
  CDmAttribute::SetValue<DmeTime_t>(this: v3, &value);
  p_m_Start->m_pAttribute->m_nFlags |= 0x100u;
  value.m_tms = 0;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "duration", type: AT_TIME, pMemory: &this->m_Duration);
  this->m_Duration.m_pAttribute = v4;
  CDmAttribute::SetValue<DmeTime_t>(this: v4, &value);
  this->m_Duration.m_pAttribute->m_nFlags |= 0x100u;
  value.m_tms = 0;
  v5 = CDmElement::AddExternalAttribute(this, pAttributeName: "offset", type: AT_TIME, pMemory: &this->m_Offset);
  this->m_Offset.m_pAttribute = v5;
  CDmAttribute::SetValue<DmeTime_t>(this: v5, &value);
  value.m_tms = 1065353216;
  v6 = CDmElement::AddExternalAttribute(this, pAttributeName: "scale", type: AT_FLOAT, pMemory: &this->m_Scale);
  this->m_Scale.m_pAttribute = v6;
  CDmAttribute::SetValue<float>(this: v6, value: (float *)&value.m_tms);
}

//------------------------------------------------------------------------------
// Address: 0x0058B7C0
// Name: public: virtual bool CDmeTimeFrame::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeTimeFrame::IsA(CDmeTimeFrame *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeTimeFrame::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0058B7F0
// Name: public: virtual int CDmeTimeFrame::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeTimeFrame::GetInheritanceDepth(CDmeTimeFrame *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeTimeFrame::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0058B8A0
// Name: protected: virtual void CDmeTimeFrame::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeTimeFrame::PerformConstruction(CDmeTimeFrame *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeTimeFrame::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006B82E0
// Name: _dynamic_initializer_for__CDmeTimeFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTimeFrame::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTimeFrame::s_Allocator,
    blockSize: 0x64u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTimeFrame pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BCB10
// Name: _dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTimeFrame::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTimeFrame::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B8310
// Name: _dynamic_initializer_for__g_CDmeTimeFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTimeFrame_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B8320
// Name: _dynamic_initializer_for__g_CDmeTimeFrame_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTimeFrame_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTimeFrame_Helper,
           classname: "DmeTimeFrame",
           pFactory: &g_CDmeTimeFrame_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BCB20
// Name: _dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTimeFrame_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeTimeFrame_Factory.m_CallBackList);
}

} // namespace vmap
