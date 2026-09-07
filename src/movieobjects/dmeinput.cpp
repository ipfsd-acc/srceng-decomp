// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmeinput.cpp
// Functions: 21
// ============================================================

#include "movieobjects\dmeinput.h"

//------------------------------------------------------------------------------
// Address: 0x0052C270
// Name: public: virtual void CDmAbstractElementFactory<class CDmeLogLayer>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeLogLayer>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge sym)
{
  CDmeLogLayer::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x0052C280
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLogLayer>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLogLayer>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeLogLayer::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0052C2A0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLogLayer>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLogLayer>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeLogLayer::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0052C760
// Name: public: virtual void CDmAbstractElementFactory<class CDmeCurveInfo>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeCurveInfo>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge sym)
{
  CDmeCurveInfo::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x0052C770
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeCurveInfo>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeCurveInfo>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeCurveInfo::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0052C790
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeCurveInfo>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeCurveInfo>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeCurveInfo::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0052CF40
// Name: public: virtual void CDmAbstractElementFactory<class CDmeLog>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeLog>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge sym)
{
  CDmeLog::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x0052CF50
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLog>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLog>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeLog::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0052CF70
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLog>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLog>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeLog::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00568900
// Name: public: virtual class CDmElement __near * CDmAbstractElementFactory<class CDmeOperator>::Create(enum DmElementHandle_t,char const __near *,char const __near *,enum DmFileId_t,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmAbstractElementFactory<CDmeOperator>::Create(
        CDmAbstractElementFactory<CDmeOperator> *this,
        DmElementHandle_t handle,
        const char *pElementType,
        const char *pElementName,
        const char *fileid,
        const UniqueId_t *id)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00568910
// Name: public: virtual void CDmAbstractElementFactory<class CDmeOperator>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeOperator>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge sym)
{
  CDmeOperator::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x00568920
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeOperator>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeOperator>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeOperator::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00568940
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeOperator>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeOperator>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00568E60
// Name: public: virtual void CDmAbstractElementFactory<class CDmeInput>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeInput>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge sym)
{
  CDmeInput::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x00568E70
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeInput>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeInput>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeInput::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00568E90
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeInput>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeInput>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmeOperator::m_classType.u.m_Id == CDmeInput::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmeOperator::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x005AEFE0
// Name: _dynamic_initializer_for__CDmeInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeInput::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005B0BF0
// Name: _dynamic_atexit_destructor_for__CDmeInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AF010
// Name: _dynamic_initializer_for__g_CDmeInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AF020
// Name: _dynamic_initializer_for__g_CDmeInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeInput_Helper,
           classname: "DmeInput",
           pFactory: &g_CDmeInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005B0C00
// Name: _dynamic_atexit_destructor_for__g_CDmeInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeInput_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeInput_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00582AA0
// Name: public: virtual void CDmAbstractElementFactory<class CDmeLogLayer>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeLogLayer>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge sym)
{
  CDmeLogLayer::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x00582AB0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLogLayer>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLogLayer>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeLogLayer::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00582AD0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLogLayer>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLogLayer>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeLogLayer::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00582F80
// Name: public: virtual void CDmAbstractElementFactory<class CDmeCurveInfo>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeCurveInfo>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge sym)
{
  CDmeCurveInfo::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x00582F90
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeCurveInfo>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeCurveInfo>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeCurveInfo::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00582FB0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeCurveInfo>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeCurveInfo>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeCurveInfo::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00583760
// Name: public: virtual void CDmAbstractElementFactory<class CDmeLog>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeLog>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge sym)
{
  CDmeLog::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x00583770
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLog>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLog>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeLog::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00583790
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLog>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLog>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeLog::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x005C76E0
// Name: public: virtual void CDmAbstractElementFactory<class CDmeOperator>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeOperator>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge sym)
{
  CDmeOperator::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x005C76F0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeOperator>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeOperator>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeOperator::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005C7710
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeOperator>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeOperator>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x005C7BC0
// Name: public: virtual class CDmElement __near * CDmAbstractElementFactory<class CDmeOperator>::Create(enum DmElementHandle_t,char const __near *,char const __near *,enum DmFileId_t,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmAbstractElementFactory<CDmeOperator>::Create(
        IParticleSystemQuery *this,
        CParticleCollection *pParticles,
        CParticleCollection *nControlPointNumber,
        int nBufSize,
        ModelHitBoxInfo_t *pHitBoxOutputBuffer,
        ModelHitBoxInfo_t *pszHitboxSetName)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005C7BD0
// Name: public: virtual void CDmAbstractElementFactory<class CDmeInput>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeInput>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge sym)
{
  CDmeInput::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x005C7BE0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeInput>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeInput>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeInput::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005C7C00
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeInput>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeInput>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmeOperator::m_classType.u.m_Id == CDmeInput::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmeOperator::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00680C10
// Name: _dynamic_initializer_for__CDmeInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeInput::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006832A0
// Name: _dynamic_atexit_destructor_for__CDmeInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00680C40
// Name: _dynamic_initializer_for__g_CDmeInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00680C50
// Name: _dynamic_initializer_for__g_CDmeInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeInput_Helper,
           classname: "DmeInput",
           pFactory: &g_CDmeInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006832B0
// Name: _dynamic_atexit_destructor_for__g_CDmeInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeInput_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeInput_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x105651B0
// Name: public: virtual void CDmAbstractElementFactory<class CDmeLogLayer>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeLogLayer>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge sym)
{
  CDmeLogLayer::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x105651C0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLogLayer>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLogLayer>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeLogLayer::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105651E0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLogLayer>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLogLayer>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeLogLayer::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10565690
// Name: public: virtual void CDmAbstractElementFactory<class CDmeCurveInfo>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeCurveInfo>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge sym)
{
  CDmeCurveInfo::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x105656A0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeCurveInfo>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeCurveInfo>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeCurveInfo::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x105656C0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeCurveInfo>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeCurveInfo>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeCurveInfo::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10565E70
// Name: public: virtual void CDmAbstractElementFactory<class CDmeLog>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeLog>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge sym)
{
  CDmeLog::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x10565E80
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLog>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLog>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeLog::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10565EA0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLog>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLog>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeLog::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10594720
// Name: public: virtual void CDmAbstractElementFactory<class CDmeOperator>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeOperator>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge sym)
{
  CDmeOperator::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x10594730
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeOperator>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeOperator>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeOperator::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10594750
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeOperator>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeOperator>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10595D80
// Name: public: virtual class CDmElement __near * CDmAbstractElementFactory<class CDmeOperator>::Create(enum DmElementHandle_t,char const __near *,char const __near *,enum DmFileId_t,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmAbstractElementFactory<CDmeOperator>::Create(
        IParticleSystemQuery *this,
        CParticleCollection *pParticles,
        CParticleCollection *nControlPointNumber,
        int nBufSize,
        ModelHitBoxInfo_t *pHitBoxOutputBuffer,
        ModelHitBoxInfo_t *pszHitboxSetName)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10595D90
// Name: public: virtual void CDmAbstractElementFactory<class CDmeInput>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeInput>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge sym)
{
  CDmeInput::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x10595DA0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeInput>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeInput>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeInput::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10595DC0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeInput>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeInput>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmeOperator::m_classType.u.m_Id == CDmeInput::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmeOperator::m_classType.u.m_Id;
  return v2;
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x00533BE0
// Name: public: virtual void CDmAbstractElementFactory<class CDmeLogLayer>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeLogLayer>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge sym)
{
  CDmeLogLayer::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x00533BF0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLogLayer>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLogLayer>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeLogLayer::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00533C10
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLogLayer>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLogLayer>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeLogLayer::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x005340C0
// Name: public: virtual void CDmAbstractElementFactory<class CDmeCurveInfo>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeCurveInfo>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge sym)
{
  CDmeCurveInfo::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x005340D0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeCurveInfo>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeCurveInfo>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeCurveInfo::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005340F0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeCurveInfo>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeCurveInfo>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeCurveInfo::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x005348A0
// Name: public: virtual class CDmElement __near * CDmAbstractElementFactory<class CDmeOperator>::Create(enum DmElementHandle_t,char const __near *,char const __near *,enum DmFileId_t,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmAbstractElementFactory<CDmeOperator>::Create(
        CDmAbstractElementFactory<CDmeOperator> *this,
        DmElementHandle_t handle,
        const char *pElementType,
        const char *pElementName,
        const char *fileid,
        const UniqueId_t *id)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005348B0
// Name: public: virtual void CDmAbstractElementFactory<class CDmeLog>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeLog>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge sym)
{
  CDmeLog::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x005348C0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLog>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLog>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeLog::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005348E0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLog>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLog>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeLog::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0055F310
// Name: public: virtual void CDmAbstractElementFactory<class CDmeOperator>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeOperator>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge sym)
{
  CDmeOperator::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x0055F320
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeOperator>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeOperator>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeOperator::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0055F340
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeOperator>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeOperator>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00566B50
// Name: public: virtual void CDmAbstractElementFactory<class CDmeInput>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeInput>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge sym)
{
  CDmeInput::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x00566B60
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeInput>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeInput>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeInput::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00566B80
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeInput>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeInput>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmeOperator::m_classType.u.m_Id == CDmeInput::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmeOperator::m_classType.u.m_Id;
  return v2;
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004F4580
// Name: public: virtual void CDmAbstractElementFactory<class CDmeOperator>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeOperator>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge sym)
{
  CDmeOperator::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x004F45A0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeOperator>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeOperator>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeOperator::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004F45C0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeOperator>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeOperator>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00581A60
// Name: public: virtual void CDmAbstractElementFactory<class CDmeLogLayer>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeLogLayer>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge sym)
{
  CDmeLogLayer::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x00581A70
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLogLayer>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLogLayer>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeLogLayer::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00581A90
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLogLayer>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLogLayer>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeLogLayer::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00581F40
// Name: public: virtual void CDmAbstractElementFactory<class CDmeCurveInfo>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeCurveInfo>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge sym)
{
  CDmeCurveInfo::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x00581F50
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeCurveInfo>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeCurveInfo>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeCurveInfo::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00581F70
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeCurveInfo>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeCurveInfo>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeCurveInfo::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00582720
// Name: public: virtual class CDmElement __near * CDmAbstractElementFactory<class CDmeOperator>::Create(enum DmElementHandle_t,char const __near *,char const __near *,enum DmFileId_t,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmAbstractElementFactory<CDmeOperator>::Create(
        CDmAbstractElementFactory<CDmeOperator> *this,
        DmElementHandle_t handle,
        const char *pElementType,
        const char *pElementName,
        const char *fileid,
        const UniqueId_t *id)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00582730
// Name: public: virtual void CDmAbstractElementFactory<class CDmeLog>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeLog>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge sym)
{
  CDmeLog::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x00582740
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLog>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLog>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeLog::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00582760
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLog>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLog>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeLog::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x005AFBD0
// Name: public: virtual void CDmAbstractElementFactory<class CDmeInput>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeInput>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge sym)
{
  CDmeInput::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x005AFBE0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeInput>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeInput>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeInput::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AFC00
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeInput>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeInput>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmeOperator::m_classType.u.m_Id == CDmeInput::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmeOperator::m_classType.u.m_Id;
  return v2;
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x004ED670
// Name: public: virtual void CDmAbstractElementFactory<class CDmeLogLayer>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeLogLayer>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge sym)
{
  CDmeLogLayer::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x004ED680
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLogLayer>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLogLayer>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeLogLayer::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004ED6A0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLogLayer>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLogLayer>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeLogLayer::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004EDB50
// Name: public: virtual class CDmElement __near * CDmAbstractElementFactory<class CDmeOperator>::Create(enum DmElementHandle_t,char const __near *,char const __near *,enum DmFileId_t,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmAbstractElementFactory<CDmeOperator>::Create(
        IParticleSystemQuery *this,
        CParticleCollection *pParticles,
        CParticleCollection *nControlPointNumber,
        int nBufSize,
        ModelHitBoxInfo_t *pHitBoxOutputBuffer,
        ModelHitBoxInfo_t *pszHitboxSetName)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004EDB60
// Name: public: virtual void CDmAbstractElementFactory<class CDmeCurveInfo>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeCurveInfo>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge sym)
{
  CDmeCurveInfo::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x004EDB70
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeCurveInfo>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeCurveInfo>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeCurveInfo::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004EDB90
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeCurveInfo>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeCurveInfo>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeCurveInfo::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004EE340
// Name: public: virtual void CDmAbstractElementFactory<class CDmeLog>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeLog>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge sym)
{
  CDmeLog::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x004EE360
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLog>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLog>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeLog::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004EE380
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLog>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLog>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeLog::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0052B950
// Name: public: virtual void CDmAbstractElementFactory<class CDmeOperator>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeOperator>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge sym)
{
  CDmeOperator::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x0052B960
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeOperator>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeOperator>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeOperator::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0052B980
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeOperator>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeOperator>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0052BE20
// Name: public: virtual void CDmAbstractElementFactory<class CDmeInput>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeInput>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge sym)
{
  CDmeInput::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x0052BE30
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeInput>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeInput>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeInput::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0052BE50
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeInput>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeInput>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmeOperator::m_classType.u.m_Id == CDmeInput::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmeOperator::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0056D580
// Name: _dynamic_initializer_for__CDmeInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeInput::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056F380
// Name: _dynamic_atexit_destructor_for__CDmeInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056D5B0
// Name: _dynamic_initializer_for__g_CDmeInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056D5C0
// Name: _dynamic_initializer_for__g_CDmeInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeInput_Helper,
           classname: "DmeInput",
           pFactory: &g_CDmeInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056F390
// Name: _dynamic_atexit_destructor_for__g_CDmeInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeInput_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeInput_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x004F2FE0
// Name: public: virtual void CDmAbstractElementFactory<class CDmeLogLayer>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeLogLayer>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge sym)
{
  CDmeLogLayer::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x004F2FF0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLogLayer>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLogLayer>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeLogLayer::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004F3010
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLogLayer>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLogLayer>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeLogLayer::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004F34C0
// Name: public: virtual void CDmAbstractElementFactory<class CDmeCurveInfo>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeCurveInfo>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge sym)
{
  CDmeCurveInfo::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x004F34D0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeCurveInfo>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeCurveInfo>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeCurveInfo::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004F34F0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeCurveInfo>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeCurveInfo>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeCurveInfo::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004F3CA0
// Name: public: virtual class CDmElement __near * CDmAbstractElementFactory<class CDmeOperator>::Create(enum DmElementHandle_t,char const __near *,char const __near *,enum DmFileId_t,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmAbstractElementFactory<CDmeOperator>::Create(
        CDmAbstractElementFactory<CDmeOperator> *this,
        DmElementHandle_t handle,
        const char *pElementType,
        const char *pElementName,
        const char *fileid,
        const UniqueId_t *id)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004F3CB0
// Name: public: virtual void CDmAbstractElementFactory<class CDmeLog>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeLog>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge sym)
{
  CDmeLog::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x004F3CC0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLog>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLog>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeLog::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004F3CE0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLog>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLog>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeLog::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00533DD0
// Name: public: virtual void CDmAbstractElementFactory<class CDmeOperator>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeOperator>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge sym)
{
  CDmeOperator::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x00533DE0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeOperator>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeOperator>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeOperator::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00533E00
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeOperator>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeOperator>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x005342E0
// Name: public: virtual void CDmAbstractElementFactory<class CDmeInput>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeInput>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge sym)
{
  CDmeInput::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x005342F0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeInput>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeInput>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeInput::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00534310
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeInput>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeInput>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmeOperator::m_classType.u.m_Id == CDmeInput::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmeOperator::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0057D6A0
// Name: _dynamic_initializer_for__CDmeInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeInput::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F4B0
// Name: _dynamic_atexit_destructor_for__CDmeInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057D6D0
// Name: _dynamic_initializer_for__g_CDmeInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D6E0
// Name: _dynamic_initializer_for__g_CDmeInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeInput_Helper,
           classname: "DmeInput",
           pFactory: &g_CDmeInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057F4C0
// Name: _dynamic_atexit_destructor_for__g_CDmeInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeInput_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeInput_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005A4A60
// Name: public: virtual void CDmAbstractElementFactory<class CDmeLogLayer>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeLogLayer>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge sym)
{
  CDmeLogLayer::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x005A4A70
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLogLayer>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLogLayer>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeLogLayer::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A4A90
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLogLayer>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLogLayer>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeLogLayer::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x005A4F40
// Name: public: virtual void CDmAbstractElementFactory<class CDmeCurveInfo>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeCurveInfo>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge sym)
{
  CDmeCurveInfo::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x005A4F50
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeCurveInfo>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeCurveInfo>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeCurveInfo::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A4F70
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeCurveInfo>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeCurveInfo>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeCurveInfo::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x005A5720
// Name: public: virtual class CDmElement __near * CDmAbstractElementFactory<class CDmeOperator>::Create(enum DmElementHandle_t,char const __near *,char const __near *,enum DmFileId_t,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmAbstractElementFactory<CDmeOperator>::Create(
        IParticleSystemQuery *this,
        CParticleCollection *pParticles,
        CParticleCollection *nControlPointNumber,
        int nBufSize,
        ModelHitBoxInfo_t *pHitBoxOutputBuffer,
        ModelHitBoxInfo_t *pszHitboxSetName)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005A5730
// Name: public: virtual void CDmAbstractElementFactory<class CDmeLog>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeLog>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge sym)
{
  CDmeLog::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x005A5740
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLog>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLog>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeLog::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A5760
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLog>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLog>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeLog::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x005F38C0
// Name: public: virtual void CDmAbstractElementFactory<class CDmeOperator>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeOperator>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge sym)
{
  CDmeOperator::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x005F38D0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeOperator>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeOperator>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeOperator::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005F38F0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeOperator>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeOperator>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x005F3D90
// Name: public: virtual void CDmAbstractElementFactory<class CDmeInput>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeInput>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge sym)
{
  CDmeInput::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x005F3DA0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeInput>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeInput>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeInput::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005F3DC0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeInput>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeInput>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmeOperator::m_classType.u.m_Id == CDmeInput::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmeOperator::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x006B29E0
// Name: _dynamic_initializer_for__CDmeInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeInput::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5D40
// Name: _dynamic_atexit_destructor_for__CDmeInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B2A10
// Name: _dynamic_initializer_for__g_CDmeInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B2A20
// Name: _dynamic_initializer_for__g_CDmeInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeInput_Helper,
           classname: "DmeInput",
           pFactory: &g_CDmeInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5D50
// Name: _dynamic_atexit_destructor_for__g_CDmeInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeInput_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeInput_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x004F40D0
// Name: public: virtual void CDmAbstractElementFactory<class CDmeLogLayer>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeLogLayer>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge sym)
{
  CDmeLogLayer::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x004F40E0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLogLayer>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLogLayer>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeLogLayer::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004F4100
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLogLayer>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLogLayer>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeLogLayer::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004F45B0
// Name: public: virtual class CDmElement __near * CDmAbstractElementFactory<class CDmeOperator>::Create(enum DmElementHandle_t,char const __near *,char const __near *,enum DmFileId_t,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmAbstractElementFactory<CDmeOperator>::Create(
        CDmAbstractElementFactory<CDmeOperator> *this,
        DmElementHandle_t handle,
        const char *pElementType,
        const char *pElementName,
        const char *fileid,
        const UniqueId_t *id)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004F45D0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeCurveInfo>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeCurveInfo>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeCurveInfo::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004F45F0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeCurveInfo>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeCurveInfo>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeCurveInfo::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004F4DA0
// Name: public: virtual void CDmAbstractElementFactory<class CDmeLog>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeLog>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge sym)
{
  CDmeLog::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x004F4DB0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLog>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLog>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeLog::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004F4DD0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLog>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLog>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeLog::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00535A10
// Name: public: virtual void CDmAbstractElementFactory<class CDmeOperator>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeOperator>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge sym)
{
  CDmeOperator::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x00535A30
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeOperator>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeOperator>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeOperator::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00535A50
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeOperator>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeOperator>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00535F20
// Name: public: virtual void CDmAbstractElementFactory<class CDmeInput>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeInput>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge sym)
{
  CDmeInput::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x00535F30
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeInput>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeInput>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeInput::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00535F50
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeInput>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeInput>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmeOperator::m_classType.u.m_Id == CDmeInput::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmeOperator::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0057F680
// Name: _dynamic_initializer_for__CDmeInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeInput::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00581490
// Name: _dynamic_atexit_destructor_for__CDmeInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057F6B0
// Name: _dynamic_initializer_for__g_CDmeInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F6C0
// Name: _dynamic_initializer_for__g_CDmeInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeInput_Helper,
           classname: "DmeInput",
           pFactory: &g_CDmeInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005814A0
// Name: _dynamic_atexit_destructor_for__g_CDmeInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeInput_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeInput_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004ED600
// Name: public: virtual void CDmAbstractElementFactory<class CDmeOperator>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeOperator>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge sym)
{
  CDmeOperator::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x004ED610
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeOperator>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeOperator>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeOperator::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004ED630
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeOperator>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeOperator>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0057A990
// Name: public: virtual void CDmAbstractElementFactory<class CDmeLogLayer>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeLogLayer>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge sym)
{
  CDmeLogLayer::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x0057A9B0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLogLayer>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLogLayer>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeLogLayer::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0057A9D0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLogLayer>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLogLayer>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeLogLayer::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0057AE80
// Name: public: virtual void CDmAbstractElementFactory<class CDmeCurveInfo>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeCurveInfo>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge sym)
{
  CDmeCurveInfo::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x0057AE90
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeCurveInfo>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeCurveInfo>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeCurveInfo::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0057AEB0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeCurveInfo>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeCurveInfo>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeCurveInfo::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0057B660
// Name: public: virtual class CDmElement __near * CDmAbstractElementFactory<class CDmeOperator>::Create(enum DmElementHandle_t,char const __near *,char const __near *,enum DmFileId_t,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmAbstractElementFactory<CDmeOperator>::Create(
        CDmAbstractElementFactory<CDmeOperator> *this,
        DmElementHandle_t handle,
        const char *pElementType,
        const char *pElementName,
        const char *fileid,
        const UniqueId_t *id)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0057B680
// Name: public: virtual void CDmAbstractElementFactory<class CDmeLog>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeLog>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge sym)
{
  CDmeLog::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x0057B690
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLog>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLog>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeLog::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0057B6B0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLog>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLog>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeLog::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x005A8B30
// Name: public: virtual void CDmAbstractElementFactory<class CDmeInput>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeInput>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge sym)
{
  CDmeInput::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x005A8B40
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeInput>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeInput>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeInput::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A8B60
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeInput>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeInput>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmeOperator::m_classType.u.m_Id == CDmeInput::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmeOperator::m_classType.u.m_Id;
  return v2;
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x004FC110
// Name: public: virtual void CDmAbstractElementFactory<class CDmeLogLayer>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeLogLayer>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge sym)
{
  CDmeLogLayer::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x004FC120
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLogLayer>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLogLayer>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeLogLayer::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004FC140
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLogLayer>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLogLayer>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeLogLayer::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004FC5F0
// Name: public: virtual void CDmAbstractElementFactory<class CDmeCurveInfo>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeCurveInfo>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge sym)
{
  CDmeCurveInfo::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x004FC600
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeCurveInfo>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeCurveInfo>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeCurveInfo::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004FC620
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeCurveInfo>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeCurveInfo>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeCurveInfo::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004FCDD0
// Name: public: virtual void CDmAbstractElementFactory<class CDmeLog>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeLog>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge sym)
{
  CDmeLog::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x004FCDE0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLog>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLog>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeLog::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004FCE00
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLog>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLog>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeLog::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0053A2C0
// Name: public: virtual class CDmElement __near * CDmAbstractElementFactory<class CDmeOperator>::Create(enum DmElementHandle_t,char const __near *,char const __near *,enum DmFileId_t,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmAbstractElementFactory<CDmeOperator>::Create(
        CDmAbstractElementFactory<CDmeOperator> *this,
        DmElementHandle_t handle,
        const char *pElementType,
        const char *pElementName,
        const char *fileid,
        const UniqueId_t *id)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0053A2D0
// Name: public: virtual void CDmAbstractElementFactory<class CDmeOperator>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeOperator>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge sym)
{
  CDmeOperator::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x0053A2E0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeOperator>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeOperator>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeOperator::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0053A300
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeOperator>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeOperator>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0053A7A0
// Name: public: virtual void CDmAbstractElementFactory<class CDmeInput>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeInput>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge sym)
{
  CDmeInput::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x0053A7B0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeInput>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeInput>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeInput::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0053A7D0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeInput>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeInput>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmeOperator::m_classType.u.m_Id == CDmeInput::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmeOperator::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0057CEC0
// Name: _dynamic_initializer_for__CDmeInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeInput::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EB80
// Name: _dynamic_atexit_destructor_for__CDmeInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057CEF0
// Name: _dynamic_initializer_for__g_CDmeInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057CF00
// Name: _dynamic_initializer_for__g_CDmeInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeInput_Helper,
           classname: "DmeInput",
           pFactory: &g_CDmeInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057EB90
// Name: _dynamic_atexit_destructor_for__g_CDmeInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeInput_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeInput_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x005FEF00
// Name: public: virtual void CDmAbstractElementFactory<class CDmeLogLayer>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeLogLayer>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge sym)
{
  CDmeLogLayer::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x005FEF10
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLogLayer>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLogLayer>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeLogLayer::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005FEF30
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLogLayer>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLogLayer>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLogLayer> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeLogLayer::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x005FF3F0
// Name: public: virtual void CDmAbstractElementFactory<class CDmeCurveInfo>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeCurveInfo>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge sym)
{
  CDmeCurveInfo::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x005FF410
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeCurveInfo>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeCurveInfo>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeCurveInfo::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005FF430
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeCurveInfo>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeCurveInfo>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeCurveInfo> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeCurveInfo::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x005FFBE0
// Name: public: virtual class CDmElement __near * CDmAbstractElementFactory<class CDmeOperator>::Create(enum DmElementHandle_t,char const __near *,char const __near *,enum DmFileId_t,struct UniqueId_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmAbstractElementFactory<CDmeOperator>::Create(
        CDmAbstractElementFactory<CDmeOperator> *this,
        DmElementHandle_t handle,
        const char *pElementType,
        const char *pElementName,
        const char *fileid,
        const UniqueId_t *id)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005FFBF0
// Name: public: virtual void CDmAbstractElementFactory<class CDmeLog>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeLog>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge sym)
{
  CDmeLog::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x005FFC00
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLog>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLog>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeLog::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005FFC20
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeLog>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeLog>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeLog> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeLog::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0063D370
// Name: public: virtual void CDmAbstractElementFactory<class CDmeOperator>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeOperator>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge sym)
{
  CDmeOperator::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x0063D380
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeOperator>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeOperator>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeOperator::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0063D3A0
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeOperator>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeOperator>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeOperator> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmElement::m_classType.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmElement::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0063D850
// Name: public: virtual void CDmAbstractElementFactory<class CDmeInput>::SetElementTypeSymbol(class CUtlSymbolLarge)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmAbstractElementFactory<CDmeInput>::SetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge sym)
{
  CDmeInput::m_classType.u.m_Id = sym.u.m_Id;
}

//------------------------------------------------------------------------------
// Address: 0x0063D860
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeInput>::GetElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeInput>::GetElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge *result)
{
  result->u.m_Id = CDmeInput::m_classType.u.m_Id;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0063D880
// Name: public: virtual class CUtlSymbolLarge CDmAbstractElementFactory<class CDmeInput>::GetParentElementTypeSymbol(void)const
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolLarge *__thiscall CDmAbstractElementFactory<CDmeInput>::GetParentElementTypeSymbol(
        CDmAbstractElementFactory<CDmeInput> *this,
        CUtlSymbolLarge *result)
{
  CUtlSymbolLarge *v2; // eax

  v2 = result;
  if ( CDmeOperator::m_classType.u.m_Id == CDmeInput::m_classType.u.m_Id )
    result->u.m_Id = -1;
  else
    result->u.m_Id = CDmeOperator::m_classType.u.m_Id;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x006BAE30
// Name: _dynamic_initializer_for__CDmeInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeInput::s_Allocator,
    blockSize: 0x4Cu,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BD9A0
// Name: _dynamic_atexit_destructor_for__CDmeInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BAE60
// Name: _dynamic_initializer_for__g_CDmeInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BAE70
// Name: _dynamic_initializer_for__g_CDmeInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeInput_Helper,
           classname: "DmeInput",
           pFactory: &g_CDmeInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BD9B0
// Name: _dynamic_atexit_destructor_for__g_CDmeInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeInput_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeInput_Factory.m_CallBackList);
}

} // namespace vmap
