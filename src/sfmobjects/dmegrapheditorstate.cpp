// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: sfmobjects/dmegrapheditorstate.cpp
// Functions: 9
// ============================================================

#include "sfmobjects\dmegrapheditorstate.h"

//------------------------------------------------------------------------------
// Address: 0x00543F70
// Name: protected: void CDmeGraphEditorState::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGraphEditorState::OnConstruction(CDmeGraphEditorState *this)
{
  CDmaElementArray<CDmeGraphEditorCurve> *p_m_CurveList; // edi
  CDmAttribute *v3; // eax
  bool value; // [esp+Fh] [ebp-1h] BYREF

  p_m_CurveList = &this->m_CurveList;
  this->m_CurveList.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "curveList",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_CurveList);
  CDmAttribute::SetElementTypeSymbol(this: p_m_CurveList->m_pAttribute, typeSymbol: CDmeGraphEditorCurve::m_classType);
  p_m_CurveList->m_pAttribute->m_nFlags |= 0x40u;
  this->m_ActiveCurveList.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "activeCurveList",
                                           type: AT_FIRST_ARRAY_TYPE,
                                           pMemory: &this->m_ActiveCurveList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ActiveCurveList.m_pAttribute,
    typeSymbol: CDmeGraphEditorCurve::m_classType);
  this->m_ActiveCurveList.m_pAttribute->m_nFlags |= 0x40u;
  this->m_SelectedKeys.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "selectedKeys",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_SelectedKeys);
  CDmAttribute::SetElementTypeSymbol(this: this->m_SelectedKeys.m_pAttribute, typeSymbol: CDmeCurveKey::m_classType);
  this->m_SelectedKeys.m_pAttribute->m_nFlags |= 0x40u;
  this->m_BookmarkSet.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "bookmarkSet",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_BookmarkSet);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BookmarkSet.m_pAttribute, typeSymbol: CDmeBookmark::m_classType);
  this->m_BookmarkSet.m_pAttribute->m_nFlags |= 0x40u;
  value = true;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "displayGrid",
         type: AT_BOOL,
         pMemory: &this->m_bDisplayGrid);
  this->m_bDisplayGrid.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005440D0
// Name: public: virtual bool CDmeGraphEditorState::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGraphEditorState::IsA(CDmeGraphEditorState *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGraphEditorState::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00544100
// Name: public: virtual int CDmeGraphEditorState::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGraphEditorState::GetInheritanceDepth(CDmeGraphEditorState *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGraphEditorState::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00544140
// Name: protected: virtual void CDmeGraphEditorState::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGraphEditorState::PerformConstruction(CDmeGraphEditorState *this)
{
  CDmeFXClip::OnDestruction();
  CDmeGraphEditorState::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057D950
// Name: _dynamic_initializer_for__CDmeGraphEditorState::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGraphEditorState::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGraphEditorState::s_Allocator,
    blockSize: 188,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGraphEditorState pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGraphEditorState::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F5E0
// Name: _dynamic_atexit_destructor_for__CDmeGraphEditorState::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGraphEditorState::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGraphEditorState::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057D980
// Name: _dynamic_initializer_for__g_CDmeGraphEditorState_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGraphEditorState_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGraphEditorState_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D990
// Name: _dynamic_initializer_for__g_CDmeGraphEditorState_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGraphEditorState_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGraphEditorState_Helper,
           classname: "DmeGraphEditorState",
           pFactory: &g_CDmeGraphEditorState_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x0057F5F0
// Name: _dynamic_atexit_destructor_for__g_CDmeGraphEditorState_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGraphEditorState_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGraphEditorState_Factory.m_CallBackList);
}

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00545D10
// Name: protected: void CDmeGraphEditorState::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGraphEditorState::OnConstruction(CDmeGraphEditorState *this)
{
  CDmaElementArray<CDmeGraphEditorCurve> *p_m_CurveList; // edi
  CDmAttribute *v3; // eax
  bool value; // [esp+Fh] [ebp-1h] BYREF

  p_m_CurveList = &this->m_CurveList;
  this->m_CurveList.m_pAttribute = CDmElement::AddExternalAttribute(
                                     this,
                                     pAttributeName: "curveList",
                                     type: AT_FIRST_ARRAY_TYPE,
                                     pMemory: &this->m_CurveList);
  CDmAttribute::SetElementTypeSymbol(this: p_m_CurveList->m_pAttribute, typeSymbol: CDmeGraphEditorCurve::m_classType);
  p_m_CurveList->m_pAttribute->m_nFlags |= 0x40u;
  this->m_ActiveCurveList.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "activeCurveList",
                                           type: AT_FIRST_ARRAY_TYPE,
                                           pMemory: &this->m_ActiveCurveList);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_ActiveCurveList.m_pAttribute,
    typeSymbol: CDmeGraphEditorCurve::m_classType);
  this->m_ActiveCurveList.m_pAttribute->m_nFlags |= 0x40u;
  this->m_SelectedKeys.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "selectedKeys",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_SelectedKeys);
  CDmAttribute::SetElementTypeSymbol(this: this->m_SelectedKeys.m_pAttribute, typeSymbol: CDmeCurveKey::m_classType);
  this->m_SelectedKeys.m_pAttribute->m_nFlags |= 0x40u;
  this->m_BookmarkSet.m_pAttribute = CDmElement::AddExternalAttribute(
                                       this,
                                       pAttributeName: "bookmarkSet",
                                       type: AT_FIRST_ARRAY_TYPE,
                                       pMemory: &this->m_BookmarkSet);
  CDmAttribute::SetElementTypeSymbol(this: this->m_BookmarkSet.m_pAttribute, typeSymbol: CDmeBookmark::m_classType);
  this->m_BookmarkSet.m_pAttribute->m_nFlags |= 0x40u;
  value = true;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "displayGrid",
         type: AT_BOOL,
         pMemory: &this->m_bDisplayGrid);
  this->m_bDisplayGrid.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00545E70
// Name: public: virtual bool CDmeGraphEditorState::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeGraphEditorState::IsA(CDmeGraphEditorState *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeGraphEditorState::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00545EA0
// Name: public: virtual int CDmeGraphEditorState::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeGraphEditorState::GetInheritanceDepth(CDmeGraphEditorState *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeGraphEditorState::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00545EE0
// Name: protected: virtual void CDmeGraphEditorState::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeGraphEditorState::PerformConstruction(CDmeGraphEditorState *this)
{
  CDmeFXClip::OnDestruction();
  CDmeGraphEditorState::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057F930
// Name: _dynamic_initializer_for__CDmeGraphEditorState::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeGraphEditorState::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeGraphEditorState::s_Allocator,
    blockSize: 188,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeGraphEditorState pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeGraphEditorState::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005815C0
// Name: _dynamic_atexit_destructor_for__CDmeGraphEditorState::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeGraphEditorState::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeGraphEditorState::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057F960
// Name: _dynamic_initializer_for__g_CDmeGraphEditorState_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeGraphEditorState_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeGraphEditorState_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F970
// Name: _dynamic_initializer_for__g_CDmeGraphEditorState_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeGraphEditorState_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeGraphEditorState_Helper,
           classname: "DmeGraphEditorState",
           pFactory: &g_CDmeGraphEditorState_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x005815D0
// Name: _dynamic_atexit_destructor_for__g_CDmeGraphEditorState_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeGraphEditorState_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeGraphEditorState_Factory.m_CallBackList);
}

} // namespace sfmgen
