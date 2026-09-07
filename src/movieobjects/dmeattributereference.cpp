// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmeattributereference.cpp
// Functions: 40
// ============================================================

#include "movieobjects\dmeattributereference.h"

//------------------------------------------------------------------------------
// Address: 0x0056BE60
// Name: public: virtual void CDmeAttributeReference::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::OnAttributeChanged(CDmeAttributeReference *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_Element.m_pAttribute || pAttribute == this->m_AttributeName.m_pAttribute )
    this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x0056BE80
// Name: private: class CDmAttribute __near * CDmeAttributeReference::LookupAttributeHandle(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::LookupAttributeHandle(CDmeAttributeReference *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // edi

  m_Handle = this->m_Element.m_Storage.m_Handle;
  this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
  m_pAsString = this->m_AttributeName.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = var;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_AttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0056BEE0
// Name: public: class CDmAttribute __near * CDmeAttributeReference::GetReferencedAttribute(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::GetReferencedAttribute(CDmeAttributeReference *this)
{
  CDmAttribute *result; // eax

  result = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( result == nullptr )
    return CDmeAttributeReference::LookupAttributeHandle(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0056BF10
// Name: public: bool CDmeAttributeReference::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttributeReference::IsValid(CDmeAttributeReference *this)
{
  CDmAttribute *v2; // eax

  v2 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( v2 == nullptr )
    v2 = CDmeAttributeReference::LookupAttributeHandle(this);
  return v2 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0056BF40
// Name: protected: void CDmeAttributeReference::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::OnConstruction(CDmeAttributeReference *this)
{
  CDmaElement<CDmElement> *p_m_Element; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax

  p_m_Element = &this->m_Element;
  this->m_Element.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "element",
                                   type: AT_FIRST_VALUE_TYPE,
                                   pMemory: &this->m_Element);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Element->m_pAttribute, typeSymbol: CDmElement::m_classType);
  p_m_Element->m_pAttribute->m_nFlags |= 0x1100u;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "attribute",
         type: AT_STRING,
         pMemory: &this->m_AttributeName);
  this->m_AttributeName.m_pAttribute = v3;
  v3->m_nFlags |= 0x500u;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "index", type: AT_INT, pMemory: &this->m_AttributeIndex);
  this->m_AttributeIndex.m_pAttribute = v4;
  v4->m_nFlags |= 0x400u;
  this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x0056BFC0
// Name: public: void const __near * CDmeAttributeReference::GetAttributeValue(enum DmAttributeType_t __near &)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::GetAttributeValue(
        CDmeAttributeReference *this,
        DmAttributeType_t *type)
{
  CDmAttribute *result; // eax
  DmAttributeType_t v4; // ecx
  DmAttributeType_t *v5; // edi

  result = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( result != nullptr || (result = CDmeAttributeReference::LookupAttributeHandle(this)) != nullptr )
  {
    v4 = result->m_nFlags & 0x1F;
    v5 = type;
    *type = v4;
    if ( (unsigned int)(v4 - 15) > 0xD )
    {
      return (CDmAttribute *)result->m_pData;
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: (CDmrGenericArray *)&type, pAttribute: result);
      result = (CDmAttribute *)CDmrGenericArrayConst::GetUntyped(
                                 this: (CDmrGenericArrayConst *)&type,
                                 i: this->m_AttributeIndex.m_Storage);
      *v5 -= 14;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0056C030
// Name: public: void CDmeAttributeReference::SetAttributeValue(void const __near *,enum DmAttributeType_t)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::SetAttributeValue(
        CDmeAttributeReference *this,
        const void *pValue,
        DmAttributeType_t type)
{
  CDmAttribute *v4; // eax
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  v4 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( v4 != nullptr || (v4 = CDmeAttributeReference::LookupAttributeHandle(this)) != nullptr )
  {
    if ( (v4->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v4, valueType: type, pValue);
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v4);
      CDmrGenericArray::Set(this: &array, i: this->m_AttributeIndex.m_Storage, valueType: type, pValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0056C140
// Name: public: virtual bool CDmeAttributeReference::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttributeReference::IsA(CDmeAttributeReference *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAttributeReference::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0056C170
// Name: public: virtual int CDmeAttributeReference::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAttributeReference::GetInheritanceDepth(CDmeAttributeReference *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAttributeReference::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0056C220
// Name: protected: virtual void CDmeAttributeReference::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::PerformConstruction(CDmeAttributeReference *this)
{
  CDmeFXClip::OnDestruction();
  CDmeAttributeReference::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005AF1A0
// Name: _dynamic_initializer_for__CDmeAttributeReference::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAttributeReference::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAttributeReference::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAttributeReference pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005B0CB0
// Name: _dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAttributeReference::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AF1D0
// Name: _dynamic_initializer_for__g_CDmeAttributeReference_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAttributeReference_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AF1E0
// Name: _dynamic_initializer_for__g_CDmeAttributeReference_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAttributeReference_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAttributeReference_Helper,
           classname: "DmeAttributeReference",
           pFactory: &g_CDmeAttributeReference_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AF200
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x005AF210
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AF230
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x005AF240
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (unsigned __int8 *)s_StringCharConversion.m_pConversion,
    value: 0,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AF2A0
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AF2D0
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x005AF2F0
// Name: _dynamic_initializer_for__s_static_p4_factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_static_p4_factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_static_p4_factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AF300
// Name: _dynamic_initializer_for__g_QuaternionPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_QuaternionPool__()
{
  if ( ((unsigned __int8)&g_QuaternionPool & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  g_QuaternionPool = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_QuaternionPool__);
}

//------------------------------------------------------------------------------
// Address: 0x005AF330
// Name: _dynamic_initializer_for__g_VectorPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_VectorPool__()
{
  if ( ((unsigned __int8)&g_VectorPool & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  g_VectorPool = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_VectorPool__);
}

//------------------------------------------------------------------------------
// Address: 0x005AF360
// Name: _dynamic_initializer_for__g_MatrixPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_MatrixPool__()
{
  if ( ((unsigned __int8)&g_MatrixPool & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  g_MatrixPool = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_MatrixPool__);
}

//------------------------------------------------------------------------------
// Address: 0x005AF390
// Name: _dynamic_initializer_for__g_StudioBoneCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_StudioBoneCache__()
{
  CDataManagerBase::CDataManagerBase(this: &g_StudioBoneCache, maxSize: 0x20000u);
  g_StudioBoneCache.__vftable = (CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>_vtbl *)&CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>::`vftable';
  g_StudioBoneCache.m_mutex.m_ownerID = 0;
  g_StudioBoneCache.m_mutex.m_depth = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_StudioBoneCache__);
}

//------------------------------------------------------------------------------
// Address: 0x005AF3D0
// Name: _dynamic_initializer_for__cl_simdbones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_simdbones__()
{
  ConVar::ConVar(
    this: &cl_simdbones,
    pName: "cl_simdbones",
    pDefaultValue: "0",
    flags: 0x2000,
    pHelpString: "Use SIMD bone setup.");
  return atexit(func: dynamic_atexit_destructor_for__cl_simdbones__);
}

//------------------------------------------------------------------------------
// Address: 0x005AF400
// Name: _dynamic_initializer_for__cl_use_simd_bones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_use_simd_bones__()
{
  ConVar::ConVar(
    this: &cl_use_simd_bones,
    pName: "cl_use_simd_bones",
    pDefaultValue: "1",
    flags: 0x2000,
    pHelpString: "1 use SIMD bones 0 use scalar bones.");
  return atexit(func: dynamic_atexit_destructor_for__cl_use_simd_bones__);
}

//------------------------------------------------------------------------------
// Address: 0x005AF430
// Name: _dynamic_initializer_for__g_cv_BlendBonesMode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_cv_BlendBonesMode__()
{
  ConVar::ConVar(this: &g_cv_BlendBonesMode, pName: "BlendBonesMode", pDefaultValue: "2", flags: 0x2000);
  return atexit(func: dynamic_atexit_destructor_for__g_cv_BlendBonesMode__);
}

//------------------------------------------------------------------------------
// Address: 0x005B0CC0
// Name: _dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAttributeReference_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005B0CD0
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005B0D10
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x005B0D20
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x005B0D70
// Name: _dynamic_atexit_destructor_for__s_static_p4_factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_static_p4_factory__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x005B0D80
// Name: _dynamic_atexit_destructor_for__cl_simdbones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_simdbones__()
{
  ConVar::~ConVar(this: &cl_simdbones);
}

//------------------------------------------------------------------------------
// Address: 0x005B0D90
// Name: _dynamic_atexit_destructor_for__cl_use_simd_bones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_use_simd_bones__()
{
  ConVar::~ConVar(this: &cl_use_simd_bones);
}

//------------------------------------------------------------------------------
// Address: 0x005B0DA0
// Name: _dynamic_atexit_destructor_for__g_cv_BlendBonesMode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_cv_BlendBonesMode__()
{
  ConVar::~ConVar(this: &g_cv_BlendBonesMode);
}

//------------------------------------------------------------------------------
// Address: 0x005B0DB0
// Name: _dynamic_atexit_destructor_for__g_StudioBoneCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioBoneCache__()
{
  g_StudioBoneCache.__vftable = (CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>_vtbl *)&CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>::`vftable';
  if ( (*((_BYTE *)&g_StudioBoneCache.CDataManagerBase + 74) & 2) != 0 )
  {
    CDataManagerBase::FlushAll(this: &g_StudioBoneCache);
    *((_WORD *)&g_StudioBoneCache.CDataManagerBase + 37) |= 1u;
  }
  CDataManagerBase::~CDataManagerBase(this: &g_StudioBoneCache);
}

//------------------------------------------------------------------------------
// Address: 0x005B0DE0
// Name: _dynamic_atexit_destructor_for__g_QuaternionPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_QuaternionPool__()
{
  CTSListBase::Detach(this: &g_QuaternionPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x005B0DF0
// Name: _dynamic_atexit_destructor_for__g_VectorPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VectorPool__()
{
  CTSListBase::Detach(this: &g_VectorPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x005B0E00
// Name: _dynamic_atexit_destructor_for__g_MatrixPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatrixPool__()
{
  CTSListBase::Detach(this: &g_MatrixPool.m_FreeBlocks);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005C9040
// Name: public: virtual void CDmeAttributeReference::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::OnAttributeChanged(CDmeAttributeReference *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_Element.m_pAttribute || pAttribute == this->m_AttributeName.m_pAttribute )
    this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x005C9060
// Name: private: class CDmAttribute __near * CDmeAttributeReference::LookupAttributeHandle(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::LookupAttributeHandle(CDmeAttributeReference *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // edi

  m_Handle = this->m_Element.m_Storage.m_Handle;
  this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
  m_pAsString = this->m_AttributeName.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_AttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005C90C0
// Name: public: class CDmAttribute __near * CDmeAttributeReference::GetReferencedAttribute(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::GetReferencedAttribute(CDmeAttributeReference *this)
{
  CDmAttribute *result; // eax

  result = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( result == nullptr )
    return CDmeAttributeReference::LookupAttributeHandle(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005C90F0
// Name: public: bool CDmeAttributeReference::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttributeReference::IsValid(CDmeAttributeReference *this)
{
  CDmAttribute *v2; // eax

  v2 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( v2 == nullptr )
    v2 = CDmeAttributeReference::LookupAttributeHandle(this);
  return v2 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005C9120
// Name: protected: void CDmeAttributeReference::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::OnConstruction(CDmeAttributeReference *this)
{
  CDmaElement<CDmElement> *p_m_Element; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax

  p_m_Element = &this->m_Element;
  this->m_Element.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "element",
                                   type: AT_FIRST_VALUE_TYPE,
                                   pMemory: &this->m_Element);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Element->m_pAttribute, typeSymbol: CDmElement::m_classType);
  p_m_Element->m_pAttribute->m_nFlags |= 0x1100u;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "attribute",
         type: AT_STRING,
         pMemory: &this->m_AttributeName);
  this->m_AttributeName.m_pAttribute = v3;
  v3->m_nFlags |= 0x500u;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "index", type: AT_INT, pMemory: &this->m_AttributeIndex);
  this->m_AttributeIndex.m_pAttribute = v4;
  v4->m_nFlags |= 0x400u;
  this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x005C91A0
// Name: public: void const __near * CDmeAttributeReference::GetAttributeValue(enum DmAttributeType_t __near &)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::GetAttributeValue(
        CDmeAttributeReference *this,
        DmAttributeType_t *type)
{
  CDmAttribute *result; // eax
  DmAttributeType_t v4; // ecx
  DmAttributeType_t *v5; // edi

  result = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( result != nullptr || (result = CDmeAttributeReference::LookupAttributeHandle(this)) != nullptr )
  {
    v4 = result->m_nFlags & 0x1F;
    v5 = type;
    *type = v4;
    if ( (unsigned int)(v4 - 15) > 0xD )
    {
      return (CDmAttribute *)result->m_pData;
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: (CDmrGenericArray *)&type, pAttribute: result);
      result = (CDmAttribute *)CDmrGenericArrayConst::GetUntyped(
                                 this: (CDmrGenericArrayConst *)&type,
                                 i: this->m_AttributeIndex.m_Storage);
      *v5 -= 14;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005C9210
// Name: public: void CDmeAttributeReference::SetAttributeValue(void const __near *,enum DmAttributeType_t)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::SetAttributeValue(
        CDmeAttributeReference *this,
        const void *pValue,
        DmAttributeType_t type)
{
  CDmAttribute *v4; // eax
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  v4 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( v4 != nullptr || (v4 = CDmeAttributeReference::LookupAttributeHandle(this)) != nullptr )
  {
    if ( (v4->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v4, valueType: type, pValue);
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v4);
      CDmrGenericArray::Set(this: &array, i: this->m_AttributeIndex.m_Storage, valueType: type, pValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C9320
// Name: public: virtual bool CDmeAttributeReference::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttributeReference::IsA(CDmeAttributeReference *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAttributeReference::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C9350
// Name: public: virtual int CDmeAttributeReference::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAttributeReference::GetInheritanceDepth(CDmeAttributeReference *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAttributeReference::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005C9410
// Name: protected: virtual void CDmeAttributeReference::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::PerformConstruction(CDmeAttributeReference *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeAttributeReference::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00680CE0
// Name: _dynamic_initializer_for__CDmeAttributeReference::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAttributeReference::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAttributeReference::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAttributeReference pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006832E0
// Name: _dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAttributeReference::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00680D10
// Name: _dynamic_initializer_for__g_CDmeAttributeReference_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAttributeReference_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00680D20
// Name: _dynamic_initializer_for__g_CDmeAttributeReference_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAttributeReference_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAttributeReference_Helper,
           classname: "DmeAttributeReference",
           pFactory: &g_CDmeAttributeReference_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00680D40
// Name: _dynamic_initializer_for__s_ParticleSystemMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_ParticleSystemMgr__()
{
  CParticleSystemMgr::CParticleSystemMgr(this: &s_ParticleSystemMgr);
  return atexit(func: dynamic_atexit_destructor_for__s_ParticleSystemMgr__);
}

//------------------------------------------------------------------------------
// Address: 0x006832F0
// Name: _dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAttributeReference_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00683300
// Name: _dynamic_atexit_destructor_for__s_ParticleSystemMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ParticleSystemMgr__()
{
  CParticleSystemMgr::~CParticleSystemMgr(this: &s_ParticleSystemMgr);
}

//------------------------------------------------------------------------------
// Address: 0x00683310
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x00683320
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00683360
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x006833B0
// Name: _dynamic_atexit_destructor_for__g_OverridenColorSymbols__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_OverridenColorSymbols__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &g_OverridenColorSymbols);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1059B910
// Name: public: virtual void CDmeAttributeReference::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::OnAttributeChanged(CDmeAttributeReference *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_Element.m_pAttribute || pAttribute == this->m_AttributeName.m_pAttribute )
    this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x1059B930
// Name: protected: void CDmeAttributeReference::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::OnConstruction(CDmeAttributeReference *this)
{
  CDmaElement<CDmElement> *p_m_Element; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax

  p_m_Element = &this->m_Element;
  this->m_Element.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "element",
                                   type: AT_FIRST_VALUE_TYPE,
                                   pMemory: &this->m_Element);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Element->m_pAttribute, typeSymbol: CDmElement::m_classType);
  p_m_Element->m_pAttribute->m_nFlags |= 0x1100u;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "attribute",
         type: AT_STRING,
         pMemory: &this->m_AttributeName);
  this->m_AttributeName.m_pAttribute = v3;
  v3->m_nFlags |= 0x500u;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "index", type: AT_INT, pMemory: &this->m_AttributeIndex);
  this->m_AttributeIndex.m_pAttribute = v4;
  v4->m_nFlags |= 0x400u;
  this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x1059BA40
// Name: public: virtual bool CDmeAttributeReference::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttributeReference::IsA(CDmeAttributeReference *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAttributeReference::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x1059BA70
// Name: public: virtual int CDmeAttributeReference::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAttributeReference::GetInheritanceDepth(CDmeAttributeReference *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAttributeReference::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1059BB30
// Name: protected: virtual void CDmeAttributeReference::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::PerformConstruction(CDmeAttributeReference *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmeAttributeReference::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x105C9F60
// Name: _dynamic_initializer_for__CDmeAttributeReference::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAttributeReference::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAttributeReference::s_Allocator,
    blockSize: 0x64u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAttributeReference pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CDD70
// Name: _dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAttributeReference::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C9F90
// Name: _dynamic_initializer_for__g_CDmeAttributeReference_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAttributeReference_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9FA0
// Name: _dynamic_initializer_for__g_CDmeAttributeReference_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAttributeReference_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAttributeReference_Helper,
           classname: "DmeAttributeReference",
           pFactory: &g_CDmeAttributeReference_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C9FC0
// Name: _dynamic_initializer_for__g_Slider_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
vgui::CBuildFactoryHelper *dynamic_initializer_for__g_Slider_Helper__()
{
  return vgui::CBuildFactoryHelper::CBuildFactoryHelper(
           this: &g_Slider_Helper,
           className: "Slider",
           func: (vgui::Panel *(__cdecl *)())Create_Slider);
}

//------------------------------------------------------------------------------
// Address: 0x105CDD80
// Name: _dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeAttributeReference_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0055E740
// Name: public: virtual void CDmeAttributeReference::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::OnAttributeChanged(CDmeAttributeReference *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_Element.m_pAttribute || pAttribute == this->m_AttributeName.m_pAttribute )
    this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x0055E760
// Name: private: class CDmAttribute __near * CDmeAttributeReference::LookupAttributeHandle(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::LookupAttributeHandle(CDmeAttributeReference *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // edi

  m_Handle = this->m_Element.m_Storage.m_Handle;
  this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: m_Handle);
  m_pAsString = this->m_AttributeName.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = WindowName;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_AttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0055E7C0
// Name: public: class CDmAttribute __near * CDmeAttributeReference::GetReferencedAttribute(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::GetReferencedAttribute(CDmeAttributeReference *this)
{
  CDmAttribute *result; // eax

  result = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                             a1: g_pDataModel.u,
                             a2: this->m_AttributeHandle);
  if ( result == nullptr )
    return CDmeAttributeReference::LookupAttributeHandle(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0055E7F0
// Name: public: bool CDmeAttributeReference::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttributeReference::IsValid(CDmeAttributeReference *this)
{
  CDmAttribute *v2; // eax

  v2 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                         a1: g_pDataModel.u,
                         a2: this->m_AttributeHandle);
  if ( v2 == nullptr )
    v2 = CDmeAttributeReference::LookupAttributeHandle(this);
  return v2 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0055E820
// Name: protected: void CDmeAttributeReference::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::OnConstruction(CDmeAttributeReference *this)
{
  CDmaElement<CDmElement> *p_m_Element; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax

  p_m_Element = &this->m_Element;
  this->m_Element.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "element",
                                   type: AT_FIRST_VALUE_TYPE,
                                   pMemory: &this->m_Element);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Element->m_pAttribute, typeSymbol: CDmElement::m_classType);
  p_m_Element->m_pAttribute->m_nFlags |= 0x1100u;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "attribute",
         type: AT_STRING,
         pMemory: &this->m_AttributeName);
  this->m_AttributeName.m_pAttribute = v3;
  v3->m_nFlags |= 0x500u;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "index", type: AT_INT, pMemory: &this->m_AttributeIndex);
  this->m_AttributeIndex.m_pAttribute = v4;
  v4->m_nFlags |= 0x400u;
  this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x0055E8A0
// Name: public: void const __near * CDmeAttributeReference::GetAttributeValue(enum DmAttributeType_t __near &)const
// Source: json
//------------------------------------------------------------------------------
int *__thiscall CDmeAttributeReference::GetAttributeValue(CDmeAttributeReference *this, DmAttributeType_t *type)
{
  int *result; // eax
  DmAttributeType_t v4; // ecx
  DmAttributeType_t *v5; // edi

  result = (int *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 336))(
                    a1: g_pDataModel.u,
                    a2: this->m_AttributeHandle);
  if ( result != nullptr || (result = (int *)CDmeAttributeReference::LookupAttributeHandle(this)) != nullptr )
  {
    v4 = result[4] & 0x1F;
    v5 = type;
    *type = v4;
    if ( (unsigned int)(v4 - 15) > 0xD )
    {
      return (int *)result[1];
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: (CDmrGenericArray *)&type, pAttribute: (CDmAttribute *)result);
      result = CDmrGenericArrayConst::GetUntyped(
                 this: (CDmrGenericArrayConst *)&type,
                 i: this->m_AttributeIndex.m_Storage);
      *v5 -= 14;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0055E910
// Name: public: void CDmeAttributeReference::SetAttributeValue(void const __near *,enum DmAttributeType_t)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::SetAttributeValue(
        CDmeAttributeReference *this,
        const void *pValue,
        DmAttributeType_t type)
{
  CDmAttribute *v4; // eax
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  v4 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                         a1: g_pDataModel.u,
                         a2: this->m_AttributeHandle);
  if ( v4 != nullptr || (v4 = CDmeAttributeReference::LookupAttributeHandle(this)) != nullptr )
  {
    if ( (v4->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v4, valueType: type, pValue);
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v4);
      CDmrGenericArray::Set(this: &array, i: this->m_AttributeIndex.m_Storage, valueType: type, pValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055EA20
// Name: public: virtual bool CDmeAttributeReference::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttributeReference::IsA(CDmeAttributeReference *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAttributeReference::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055EA50
// Name: public: virtual int CDmeAttributeReference::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAttributeReference::GetInheritanceDepth(CDmeAttributeReference *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAttributeReference::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055EB00
// Name: protected: virtual void CDmeAttributeReference::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::PerformConstruction(CDmeAttributeReference *this)
{
  CDmeFXClip::OnDestruction();
  CDmeAttributeReference::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0059C9F0
// Name: _dynamic_initializer_for__CDmeAttributeReference::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAttributeReference::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAttributeReference::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAttributeReference pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059F5E0
// Name: _dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAttributeReference::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059CA20
// Name: _dynamic_initializer_for__g_CDmeAttributeReference_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAttributeReference_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059CA30
// Name: _dynamic_initializer_for__g_CDmeAttributeReference_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAttributeReference_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAttributeReference_Helper,
           classname: "DmeAttributeReference",
           pFactory: &g_CDmeAttributeReference_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059F5F0
// Name: _dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAttributeReference_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004F39B0
// Name: public: virtual void CDmeAttributeReference::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::OnAttributeChanged(CDmeAttributeReference *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_Element.m_pAttribute || pAttribute == this->m_AttributeName.m_pAttribute )
    this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x004F39D0
// Name: private: class CDmAttribute __near * CDmeAttributeReference::LookupAttributeHandle(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::LookupAttributeHandle(CDmeAttributeReference *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // edi

  m_Handle = this->m_Element.m_Storage.m_Handle;
  this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: m_Handle);
  m_pAsString = this->m_AttributeName.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = pDeltaStateName;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_AttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004F3A30
// Name: public: class CDmAttribute __near * CDmeAttributeReference::GetReferencedAttribute(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::GetReferencedAttribute(CDmeAttributeReference *this)
{
  CDmAttribute *result; // eax

  result = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                             a1: g_pDataModel.u,
                             a2: this->m_AttributeHandle);
  if ( result == nullptr )
    return CDmeAttributeReference::LookupAttributeHandle(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004F3A60
// Name: public: bool CDmeAttributeReference::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttributeReference::IsValid(CDmeAttributeReference *this)
{
  CDmAttribute *v2; // eax

  v2 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                         a1: g_pDataModel.u,
                         a2: this->m_AttributeHandle);
  if ( v2 == nullptr )
    v2 = CDmeAttributeReference::LookupAttributeHandle(this);
  return v2 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004F3A90
// Name: protected: void CDmeAttributeReference::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::OnConstruction(CDmeAttributeReference *this)
{
  CDmaElement<CDmElement> *p_m_Element; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax

  p_m_Element = &this->m_Element;
  this->m_Element.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "element",
                                   type: AT_FIRST_VALUE_TYPE,
                                   pMemory: &this->m_Element);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Element->m_pAttribute, typeSymbol: CDmElement::m_classType);
  p_m_Element->m_pAttribute->m_nFlags |= 0x1100u;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "attribute",
         type: AT_STRING,
         pMemory: &this->m_AttributeName);
  this->m_AttributeName.m_pAttribute = v3;
  v3->m_nFlags |= 0x500u;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "index", type: AT_INT, pMemory: &this->m_AttributeIndex);
  this->m_AttributeIndex.m_pAttribute = v4;
  v4->m_nFlags |= 0x400u;
  this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x004F3B10
// Name: public: void const __near * CDmeAttributeReference::GetAttributeValue(enum DmAttributeType_t __near &)const
// Source: json
//------------------------------------------------------------------------------
int *__thiscall CDmeAttributeReference::GetAttributeValue(CDmeAttributeReference *this, DmAttributeType_t *type)
{
  int *result; // eax
  DmAttributeType_t v4; // ecx
  DmAttributeType_t *v5; // edi

  result = (int *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 336))(
                    a1: g_pDataModel.u,
                    a2: this->m_AttributeHandle);
  if ( result != nullptr || (result = (int *)CDmeAttributeReference::LookupAttributeHandle(this)) != nullptr )
  {
    v4 = result[4] & 0x1F;
    v5 = type;
    *type = v4;
    if ( (unsigned int)(v4 - 15) > 0xD )
    {
      return (int *)result[1];
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: (CDmrGenericArray *)&type, pAttribute: (CDmAttribute *)result);
      result = CDmrGenericArrayConst::GetUntyped(
                 this: (CDmrGenericArrayConst *)&type,
                 i: this->m_AttributeIndex.m_Storage);
      *v5 -= 14;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004F3B80
// Name: public: void CDmeAttributeReference::SetAttributeValue(void const __near *,enum DmAttributeType_t)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::SetAttributeValue(
        CDmeAttributeReference *this,
        const void *pValue,
        DmAttributeType_t type)
{
  CDmAttribute *v4; // eax
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  v4 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                         a1: g_pDataModel.u,
                         a2: this->m_AttributeHandle);
  if ( v4 != nullptr || (v4 = CDmeAttributeReference::LookupAttributeHandle(this)) != nullptr )
  {
    if ( (v4->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v4, valueType: type, pValue);
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v4);
      CDmrGenericArray::Set(this: &array, i: this->m_AttributeIndex.m_Storage, valueType: type, pValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F3C90
// Name: public: virtual bool CDmeAttributeReference::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttributeReference::IsA(CDmeAttributeReference *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAttributeReference::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004F3CC0
// Name: public: virtual int CDmeAttributeReference::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAttributeReference::GetInheritanceDepth(CDmeAttributeReference *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAttributeReference::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004F3D70
// Name: protected: virtual void CDmeAttributeReference::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::PerformConstruction(CDmeAttributeReference *this)
{
  CDmeFXClip::OnDestruction();
  CDmeAttributeReference::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005EF280
// Name: _dynamic_initializer_for__CDmeAttributeReference::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAttributeReference::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAttributeReference::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAttributeReference pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3CB0
// Name: _dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAttributeReference::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EF2B0
// Name: _dynamic_initializer_for__g_CDmeAttributeReference_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAttributeReference_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EF2C0
// Name: _dynamic_initializer_for__g_CDmeAttributeReference_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAttributeReference_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAttributeReference_Helper,
           classname: "DmeAttributeReference",
           pFactory: &g_CDmeAttributeReference_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3CC0
// Name: _dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAttributeReference_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0052ECB0
// Name: public: virtual void CDmeAttributeReference::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::OnAttributeChanged(CDmeAttributeReference *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_Element.m_pAttribute || pAttribute == this->m_AttributeName.m_pAttribute )
    this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x0052ECD0
// Name: private: class CDmAttribute __near * CDmeAttributeReference::LookupAttributeHandle(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::LookupAttributeHandle(CDmeAttributeReference *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // edi

  m_Handle = this->m_Element.m_Storage.m_Handle;
  this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
  m_pAsString = this->m_AttributeName.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = str;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_AttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0052ED30
// Name: public: class CDmAttribute __near * CDmeAttributeReference::GetReferencedAttribute(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::GetReferencedAttribute(CDmeAttributeReference *this)
{
  CDmAttribute *result; // eax

  result = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( result == nullptr )
    return CDmeAttributeReference::LookupAttributeHandle(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0052ED60
// Name: public: bool CDmeAttributeReference::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttributeReference::IsValid(CDmeAttributeReference *this)
{
  CDmAttribute *v2; // eax

  v2 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( v2 == nullptr )
    v2 = CDmeAttributeReference::LookupAttributeHandle(this);
  return v2 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0052ED90
// Name: protected: void CDmeAttributeReference::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::OnConstruction(CDmeAttributeReference *this)
{
  CDmaElement<CDmElement> *p_m_Element; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax

  p_m_Element = &this->m_Element;
  this->m_Element.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "element",
                                   type: AT_FIRST_VALUE_TYPE,
                                   pMemory: &this->m_Element);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Element->m_pAttribute, typeSymbol: CDmElement::m_classType);
  p_m_Element->m_pAttribute->m_nFlags |= 0x1100u;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "attribute",
         type: AT_STRING,
         pMemory: &this->m_AttributeName);
  this->m_AttributeName.m_pAttribute = v3;
  v3->m_nFlags |= 0x500u;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "index", type: AT_INT, pMemory: &this->m_AttributeIndex);
  this->m_AttributeIndex.m_pAttribute = v4;
  v4->m_nFlags |= 0x400u;
  this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x0052EE10
// Name: public: void const __near * CDmeAttributeReference::GetAttributeValue(enum DmAttributeType_t __near &)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::GetAttributeValue(
        CDmeAttributeReference *this,
        DmAttributeType_t *type)
{
  CDmAttribute *result; // eax
  DmAttributeType_t v4; // ecx
  DmAttributeType_t *v5; // edi

  result = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( result != nullptr || (result = CDmeAttributeReference::LookupAttributeHandle(this)) != nullptr )
  {
    v4 = result->m_nFlags & 0x1F;
    v5 = type;
    *type = v4;
    if ( (unsigned int)(v4 - 15) > 0xD )
    {
      return (CDmAttribute *)result->m_pData;
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: (CDmrGenericArray *)&type, pAttribute: result);
      result = (CDmAttribute *)CDmrGenericArrayConst::GetUntyped(
                                 this: (CDmrGenericArrayConst *)&type,
                                 i: this->m_AttributeIndex.m_Storage);
      *v5 -= 14;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0052EE80
// Name: public: void CDmeAttributeReference::SetAttributeValue(void const __near *,enum DmAttributeType_t)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::SetAttributeValue(
        CDmeAttributeReference *this,
        const void *pValue,
        DmAttributeType_t type)
{
  CDmAttribute *v4; // eax
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  v4 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( v4 != nullptr || (v4 = CDmeAttributeReference::LookupAttributeHandle(this)) != nullptr )
  {
    if ( (v4->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v4, valueType: type, pValue);
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v4);
      CDmrGenericArray::Set(this: &array, i: this->m_AttributeIndex.m_Storage, valueType: type, pValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052EF90
// Name: public: virtual bool CDmeAttributeReference::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttributeReference::IsA(CDmeAttributeReference *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAttributeReference::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052EFC0
// Name: public: virtual int CDmeAttributeReference::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAttributeReference::GetInheritanceDepth(CDmeAttributeReference *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAttributeReference::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052F070
// Name: protected: virtual void CDmeAttributeReference::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::PerformConstruction(CDmeAttributeReference *this)
{
  CDmeFXClip::OnDestruction();
  CDmeAttributeReference::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0056D740
// Name: _dynamic_initializer_for__CDmeAttributeReference::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAttributeReference::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAttributeReference::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAttributeReference pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056F440
// Name: _dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAttributeReference::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056D770
// Name: _dynamic_initializer_for__g_CDmeAttributeReference_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAttributeReference_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056D780
// Name: _dynamic_initializer_for__g_CDmeAttributeReference_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAttributeReference_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAttributeReference_Helper,
           classname: "DmeAttributeReference",
           pFactory: &g_CDmeAttributeReference_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056F450
// Name: _dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAttributeReference_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056F470
// Name: _dynamic_atexit_destructor_for__s_ParticleSystemMgr__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_ParticleSystemMgr__()
{
  CParticleSystemMgr::~CParticleSystemMgr(this: &s_ParticleSystemMgr);
}

//------------------------------------------------------------------------------
// Address: 0x0056F480
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0056F4C0
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x0056F4D0
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x0056F520
// Name: _dynamic_atexit_destructor_for__cl_simdbones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_simdbones__()
{
  ConVar::~ConVar(this: &cl_simdbones);
}

//------------------------------------------------------------------------------
// Address: 0x0056F530
// Name: _dynamic_atexit_destructor_for__cl_use_simd_bones__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__cl_use_simd_bones__()
{
  ConVar::~ConVar(this: &cl_use_simd_bones);
}

//------------------------------------------------------------------------------
// Address: 0x0056F540
// Name: _dynamic_atexit_destructor_for__g_cv_BlendBonesMode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_cv_BlendBonesMode__()
{
  ConVar::~ConVar(this: &g_cv_BlendBonesMode);
}

//------------------------------------------------------------------------------
// Address: 0x0056F550
// Name: _dynamic_atexit_destructor_for__g_StudioBoneCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_StudioBoneCache__()
{
  g_StudioBoneCache.__vftable = (CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>_vtbl *)&CDataManager<CBoneCache,bonecacheparams_t,CBoneCache *,CThreadFastMutex>::`vftable';
  if ( (*((_BYTE *)&g_StudioBoneCache.CDataManagerBase + 74) & 2) != 0 )
  {
    CDataManagerBase::FlushAll(this: &g_StudioBoneCache);
    *((_WORD *)&g_StudioBoneCache.CDataManagerBase + 37) |= 1u;
  }
  CDataManagerBase::~CDataManagerBase(this: &g_StudioBoneCache);
}

//------------------------------------------------------------------------------
// Address: 0x0056F580
// Name: _dynamic_atexit_destructor_for__g_QuaternionPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_QuaternionPool__()
{
  CTSListBase::Detach(this: &g_QuaternionPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x0056F590
// Name: _dynamic_atexit_destructor_for__g_VectorPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_VectorPool__()
{
  CTSListBase::Detach(this: &g_VectorPool.m_FreeBlocks);
}

//------------------------------------------------------------------------------
// Address: 0x0056F5A0
// Name: _dynamic_atexit_destructor_for__g_MatrixPool__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_MatrixPool__()
{
  CTSListBase::Detach(this: &g_MatrixPool.m_FreeBlocks);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00537140
// Name: public: virtual void CDmeAttributeReference::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::OnAttributeChanged(CDmeAttributeReference *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_Element.m_pAttribute || pAttribute == this->m_AttributeName.m_pAttribute )
    this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x00537160
// Name: private: class CDmAttribute __near * CDmeAttributeReference::LookupAttributeHandle(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::LookupAttributeHandle(CDmeAttributeReference *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // edi

  m_Handle = this->m_Element.m_Storage.m_Handle;
  this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
  m_pAsString = this->m_AttributeName.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = &pParentName;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_AttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005371C0
// Name: public: class CDmAttribute __near * CDmeAttributeReference::GetReferencedAttribute(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::GetReferencedAttribute(CDmeAttributeReference *this)
{
  CDmAttribute *result; // eax

  result = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( result == nullptr )
    return CDmeAttributeReference::LookupAttributeHandle(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005371F0
// Name: public: bool CDmeAttributeReference::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttributeReference::IsValid(CDmeAttributeReference *this)
{
  CDmAttribute *v2; // eax

  v2 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( v2 == nullptr )
    v2 = CDmeAttributeReference::LookupAttributeHandle(this);
  return v2 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00537220
// Name: protected: void CDmeAttributeReference::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::OnConstruction(CDmeAttributeReference *this)
{
  CDmaElement<CDmElement> *p_m_Element; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax

  p_m_Element = &this->m_Element;
  this->m_Element.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "element",
                                   type: AT_FIRST_VALUE_TYPE,
                                   pMemory: &this->m_Element);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Element->m_pAttribute, typeSymbol: CDmElement::m_classType);
  p_m_Element->m_pAttribute->m_nFlags |= 0x1100u;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "attribute",
         type: AT_STRING,
         pMemory: &this->m_AttributeName);
  this->m_AttributeName.m_pAttribute = v3;
  v3->m_nFlags |= 0x500u;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "index", type: AT_INT, pMemory: &this->m_AttributeIndex);
  this->m_AttributeIndex.m_pAttribute = v4;
  v4->m_nFlags |= 0x400u;
  this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x005372A0
// Name: public: void const __near * CDmeAttributeReference::GetAttributeValue(enum DmAttributeType_t __near &)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::GetAttributeValue(
        CDmeAttributeReference *this,
        DmAttributeType_t *type)
{
  CDmAttribute *result; // eax
  DmAttributeType_t v4; // ecx
  DmAttributeType_t *v5; // edi

  result = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( result != nullptr || (result = CDmeAttributeReference::LookupAttributeHandle(this)) != nullptr )
  {
    v4 = result->m_nFlags & 0x1F;
    v5 = type;
    *type = v4;
    if ( (unsigned int)(v4 - 15) > 0xD )
    {
      return (CDmAttribute *)result->m_pData;
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: (CDmrGenericArray *)&type, pAttribute: result);
      result = (CDmAttribute *)CDmrGenericArrayConst::GetUntyped(
                                 this: (CDmrGenericArrayConst *)&type,
                                 i: this->m_AttributeIndex.m_Storage);
      *v5 -= 14;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00537310
// Name: public: void CDmeAttributeReference::SetAttributeValue(void const __near *,enum DmAttributeType_t)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::SetAttributeValue(
        CDmeAttributeReference *this,
        const void *pValue,
        DmAttributeType_t type)
{
  CDmAttribute *v4; // eax
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  v4 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( v4 != nullptr || (v4 = CDmeAttributeReference::LookupAttributeHandle(this)) != nullptr )
  {
    if ( (v4->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v4, valueType: type, pValue);
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v4);
      CDmrGenericArray::Set(this: &array, i: this->m_AttributeIndex.m_Storage, valueType: type, pValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00537420
// Name: public: virtual bool CDmeAttributeReference::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttributeReference::IsA(CDmeAttributeReference *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAttributeReference::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00537450
// Name: public: virtual int CDmeAttributeReference::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAttributeReference::GetInheritanceDepth(CDmeAttributeReference *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAttributeReference::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00537500
// Name: protected: virtual void CDmeAttributeReference::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::PerformConstruction(CDmeAttributeReference *this)
{
  CDmeFXClip::OnDestruction();
  CDmeAttributeReference::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057D860
// Name: _dynamic_initializer_for__CDmeAttributeReference::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAttributeReference::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAttributeReference::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAttributeReference pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F570
// Name: _dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAttributeReference::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057D890
// Name: _dynamic_initializer_for__g_CDmeAttributeReference_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAttributeReference_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D8A0
// Name: _dynamic_initializer_for__g_CDmeAttributeReference_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAttributeReference_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAttributeReference_Helper,
           classname: "DmeAttributeReference",
           pFactory: &g_CDmeAttributeReference_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057D8C0
// Name: _dynamic_initializer_for__s_GlobalFlexController__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_GlobalFlexController__()
{
  CUtlSymbolTable::CUtlSymbolTable(
    this: &s_GlobalFlexController.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__s_GlobalFlexController__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D8E0
// Name: _dynamic_initializer_for__g_ExtractorSingleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExtractorSingleton__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ExtractorSingleton__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D8F0
// Name: _dynamic_initializer_for__Context_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__Context_t::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &Context_t::s_Allocator,
    blockSize: 228,
    numElements: 128,
    growMode: 2,
    pszAllocOwner: "Context_t pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__Context_t::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D920
// Name: _dynamic_initializer_for__LogPreview_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LogPreview_t::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &LogPreview_t::s_Allocator,
    blockSize: 32,
    numElements: 256,
    growMode: 2,
    pszAllocOwner: "LogPreview_t pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__LogPreview_t::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F580
// Name: _dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAttributeReference_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057F590
// Name: _dynamic_atexit_destructor_for__s_GlobalFlexController__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_GlobalFlexController__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &s_GlobalFlexController.m_SymbolTable);
}

//------------------------------------------------------------------------------
// Address: 0x0057F5A0
// Name: _dynamic_atexit_destructor_for__g_ExtractorSingleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExtractorSingleton__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_ExtractorSingleton.m_Extractors);
  g_ExtractorSingleton.__vftable = (CSFMPhonemeExtractor_vtbl *)&ISFMPhonemeExtractor::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x0057F5C0
// Name: _dynamic_atexit_destructor_for__Context_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Context_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &Context_t::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057F5D0
// Name: _dynamic_atexit_destructor_for__LogPreview_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__LogPreview_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &LogPreview_t::s_Allocator);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005F2D00
// Name: public: virtual void CDmeAttributeReference::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::OnAttributeChanged(CDmeAttributeReference *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_Element.m_pAttribute || pAttribute == this->m_AttributeName.m_pAttribute )
    this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x005F2D20
// Name: private: class CDmAttribute __near * CDmeAttributeReference::LookupAttributeHandle(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::LookupAttributeHandle(CDmeAttributeReference *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // edi

  m_Handle = this->m_Element.m_Storage.m_Handle;
  this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: m_Handle);
  m_pAsString = this->m_AttributeName.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_AttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005F2D80
// Name: public: class CDmAttribute __near * CDmeAttributeReference::GetReferencedAttribute(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::GetReferencedAttribute(CDmeAttributeReference *this)
{
  CDmAttribute *result; // eax

  result = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                             a1: g_pDataModel.u,
                             a2: this->m_AttributeHandle);
  if ( result == nullptr )
    return CDmeAttributeReference::LookupAttributeHandle(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005F2DB0
// Name: public: bool CDmeAttributeReference::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttributeReference::IsValid(CDmeAttributeReference *this)
{
  CDmAttribute *v2; // eax

  v2 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                         a1: g_pDataModel.u,
                         a2: this->m_AttributeHandle);
  if ( v2 == nullptr )
    v2 = CDmeAttributeReference::LookupAttributeHandle(this);
  return v2 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005F2DE0
// Name: protected: void CDmeAttributeReference::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::OnConstruction(CDmeAttributeReference *this)
{
  CDmaElement<CDmElement> *p_m_Element; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax

  p_m_Element = &this->m_Element;
  this->m_Element.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "element",
                                   type: AT_FIRST_VALUE_TYPE,
                                   pMemory: &this->m_Element);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Element->m_pAttribute, typeSymbol: CDmElement::m_classType);
  p_m_Element->m_pAttribute->m_nFlags |= 0x1100u;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "attribute",
         type: AT_STRING,
         pMemory: &this->m_AttributeName);
  this->m_AttributeName.m_pAttribute = v3;
  v3->m_nFlags |= 0x500u;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "index", type: AT_INT, pMemory: &this->m_AttributeIndex);
  this->m_AttributeIndex.m_pAttribute = v4;
  v4->m_nFlags |= 0x400u;
  this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x005F2E60
// Name: public: void const __near * CDmeAttributeReference::GetAttributeValue(enum DmAttributeType_t __near &)const
// Source: json
//------------------------------------------------------------------------------
int *__thiscall CDmeAttributeReference::GetAttributeValue(CDmeAttributeReference *this, DmAttributeType_t *type)
{
  int *result; // eax
  DmAttributeType_t v4; // ecx
  DmAttributeType_t *v5; // edi

  result = (int *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 336))(
                    a1: g_pDataModel.u,
                    a2: this->m_AttributeHandle);
  if ( result != nullptr || (result = (int *)CDmeAttributeReference::LookupAttributeHandle(this)) != nullptr )
  {
    v4 = result[4] & 0x1F;
    v5 = type;
    *type = v4;
    if ( (unsigned int)(v4 - 15) > 0xD )
    {
      return (int *)result[1];
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: (CDmrGenericArray *)&type, pAttribute: (CDmAttribute *)result);
      result = CDmrGenericArrayConst::GetUntyped(
                 this: (CDmrGenericArrayConst *)&type,
                 i: this->m_AttributeIndex.m_Storage);
      *v5 -= 14;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005F2ED0
// Name: public: void CDmeAttributeReference::SetAttributeValue(void const __near *,enum DmAttributeType_t)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::SetAttributeValue(
        CDmeAttributeReference *this,
        const void *pValue,
        DmAttributeType_t type)
{
  CDmAttribute *v4; // eax
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  v4 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                         a1: g_pDataModel.u,
                         a2: this->m_AttributeHandle);
  if ( v4 != nullptr || (v4 = CDmeAttributeReference::LookupAttributeHandle(this)) != nullptr )
  {
    if ( (v4->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v4, valueType: type, pValue);
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v4);
      CDmrGenericArray::Set(this: &array, i: this->m_AttributeIndex.m_Storage, valueType: type, pValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005F2FE0
// Name: public: virtual bool CDmeAttributeReference::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttributeReference::IsA(CDmeAttributeReference *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAttributeReference::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F3010
// Name: public: virtual int CDmeAttributeReference::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAttributeReference::GetInheritanceDepth(CDmeAttributeReference *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAttributeReference::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005F30C0
// Name: protected: virtual void CDmeAttributeReference::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::PerformConstruction(CDmeAttributeReference *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeAttributeReference::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006B2860
// Name: _dynamic_initializer_for__CDmeAttributeReference::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAttributeReference::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAttributeReference::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAttributeReference pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5CC0
// Name: _dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAttributeReference::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B2890
// Name: _dynamic_initializer_for__g_CDmeAttributeReference_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAttributeReference_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B28A0
// Name: _dynamic_initializer_for__g_CDmeAttributeReference_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAttributeReference_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAttributeReference_Helper,
           classname: "DmeAttributeReference",
           pFactory: &g_CDmeAttributeReference_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5CD0
// Name: _dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeAttributeReference_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00538DE0
// Name: public: virtual void CDmeAttributeReference::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::OnAttributeChanged(CDmeAttributeReference *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_Element.m_pAttribute || pAttribute == this->m_AttributeName.m_pAttribute )
    this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x00538E00
// Name: private: class CDmAttribute __near * CDmeAttributeReference::LookupAttributeHandle(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::LookupAttributeHandle(CDmeAttributeReference *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // edi

  m_Handle = this->m_Element.m_Storage.m_Handle;
  this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
  m_pAsString = this->m_AttributeName.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = &pch;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_AttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00538E60
// Name: public: class CDmAttribute __near * CDmeAttributeReference::GetReferencedAttribute(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::GetReferencedAttribute(CDmeAttributeReference *this)
{
  CDmAttribute *result; // eax

  result = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( result == nullptr )
    return CDmeAttributeReference::LookupAttributeHandle(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00538E90
// Name: public: bool CDmeAttributeReference::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttributeReference::IsValid(CDmeAttributeReference *this)
{
  CDmAttribute *v2; // eax

  v2 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( v2 == nullptr )
    v2 = CDmeAttributeReference::LookupAttributeHandle(this);
  return v2 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00538EC0
// Name: protected: void CDmeAttributeReference::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::OnConstruction(CDmeAttributeReference *this)
{
  CDmaElement<CDmElement> *p_m_Element; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax

  p_m_Element = &this->m_Element;
  this->m_Element.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "element",
                                   type: AT_FIRST_VALUE_TYPE,
                                   pMemory: &this->m_Element);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Element->m_pAttribute, typeSymbol: CDmElement::m_classType);
  p_m_Element->m_pAttribute->m_nFlags |= 0x1100u;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "attribute",
         type: AT_STRING,
         pMemory: &this->m_AttributeName);
  this->m_AttributeName.m_pAttribute = v3;
  v3->m_nFlags |= 0x500u;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "index", type: AT_INT, pMemory: &this->m_AttributeIndex);
  this->m_AttributeIndex.m_pAttribute = v4;
  v4->m_nFlags |= 0x400u;
  this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x00538F40
// Name: public: void const __near * CDmeAttributeReference::GetAttributeValue(enum DmAttributeType_t __near &)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::GetAttributeValue(
        CDmeAttributeReference *this,
        DmAttributeType_t *type)
{
  CDmAttribute *result; // eax
  DmAttributeType_t v4; // ecx
  DmAttributeType_t *v5; // edi

  result = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( result != nullptr || (result = CDmeAttributeReference::LookupAttributeHandle(this)) != nullptr )
  {
    v4 = result->m_nFlags & 0x1F;
    v5 = type;
    *type = v4;
    if ( (unsigned int)(v4 - 15) > 0xD )
    {
      return (CDmAttribute *)result->m_pData;
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: (CDmrGenericArray *)&type, pAttribute: result);
      result = (CDmAttribute *)CDmrGenericArrayConst::GetUntyped(
                                 this: (CDmrGenericArrayConst *)&type,
                                 i: this->m_AttributeIndex.m_Storage);
      *v5 -= 14;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00538FB0
// Name: public: void CDmeAttributeReference::SetAttributeValue(void const __near *,enum DmAttributeType_t)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::SetAttributeValue(
        CDmeAttributeReference *this,
        const void *pValue,
        DmAttributeType_t type)
{
  CDmAttribute *v4; // eax
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  v4 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( v4 != nullptr || (v4 = CDmeAttributeReference::LookupAttributeHandle(this)) != nullptr )
  {
    if ( (v4->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v4, valueType: type, pValue);
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v4);
      CDmrGenericArray::Set(this: &array, i: this->m_AttributeIndex.m_Storage, valueType: type, pValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005390C0
// Name: public: virtual bool CDmeAttributeReference::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttributeReference::IsA(CDmeAttributeReference *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAttributeReference::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005390F0
// Name: public: virtual int CDmeAttributeReference::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAttributeReference::GetInheritanceDepth(CDmeAttributeReference *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAttributeReference::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005391A0
// Name: protected: virtual void CDmeAttributeReference::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::PerformConstruction(CDmeAttributeReference *this)
{
  CDmeFXClip::OnDestruction();
  CDmeAttributeReference::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057F840
// Name: _dynamic_initializer_for__CDmeAttributeReference::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAttributeReference::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAttributeReference::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAttributeReference pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00581550
// Name: _dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAttributeReference::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057F870
// Name: _dynamic_initializer_for__g_CDmeAttributeReference_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAttributeReference_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F880
// Name: _dynamic_initializer_for__g_CDmeAttributeReference_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAttributeReference_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAttributeReference_Helper,
           classname: "DmeAttributeReference",
           pFactory: &g_CDmeAttributeReference_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057F8A0
// Name: _dynamic_initializer_for__Context_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__Context_t::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &Context_t::s_Allocator,
    blockSize: 228,
    numElements: 128,
    growMode: 2,
    pszAllocOwner: "Context_t pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__Context_t::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F8D0
// Name: _dynamic_initializer_for__LogPreview_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__LogPreview_t::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &LogPreview_t::s_Allocator,
    blockSize: 32,
    numElements: 256,
    growMode: 2,
    pszAllocOwner: "LogPreview_t pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__LogPreview_t::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F900
// Name: _dynamic_initializer_for__s_GlobalFlexController__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_GlobalFlexController__()
{
  CUtlSymbolTable::CUtlSymbolTable(
    this: &s_GlobalFlexController.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__s_GlobalFlexController__);
}

//------------------------------------------------------------------------------
// Address: 0x0057F920
// Name: _dynamic_initializer_for__g_ExtractorSingleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExtractorSingleton__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ExtractorSingleton__);
}

//------------------------------------------------------------------------------
// Address: 0x00581560
// Name: _dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAttributeReference_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00581570
// Name: _dynamic_atexit_destructor_for__Context_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__Context_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &Context_t::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00581580
// Name: _dynamic_atexit_destructor_for__LogPreview_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__LogPreview_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &LogPreview_t::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00581590
// Name: _dynamic_atexit_destructor_for__s_GlobalFlexController__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_GlobalFlexController__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &s_GlobalFlexController.m_SymbolTable);
}

//------------------------------------------------------------------------------
// Address: 0x005815A0
// Name: _dynamic_atexit_destructor_for__g_ExtractorSingleton__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExtractorSingleton__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_ExtractorSingleton.m_Extractors);
  g_ExtractorSingleton.__vftable = (CSFMPhonemeExtractor_vtbl *)&ISFMPhonemeExtractor::`vftable';
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004ECA40
// Name: public: virtual void CDmeAttributeReference::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::OnAttributeChanged(CDmeAttributeReference *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_Element.m_pAttribute || pAttribute == this->m_AttributeName.m_pAttribute )
    this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x004ECA60
// Name: private: class CDmAttribute __near * CDmeAttributeReference::LookupAttributeHandle(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::LookupAttributeHandle(CDmeAttributeReference *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // edi

  m_Handle = this->m_Element.m_Storage.m_Handle;
  this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: m_Handle);
  m_pAsString = this->m_AttributeName.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = pDeltaStateName;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_AttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004ECAC0
// Name: public: class CDmAttribute __near * CDmeAttributeReference::GetReferencedAttribute(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::GetReferencedAttribute(CDmeAttributeReference *this)
{
  CDmAttribute *result; // eax

  result = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                             a1: g_pDataModel.u,
                             a2: this->m_AttributeHandle);
  if ( result == nullptr )
    return CDmeAttributeReference::LookupAttributeHandle(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004ECAF0
// Name: public: bool CDmeAttributeReference::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttributeReference::IsValid(CDmeAttributeReference *this)
{
  CDmAttribute *v2; // eax

  v2 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                         a1: g_pDataModel.u,
                         a2: this->m_AttributeHandle);
  if ( v2 == nullptr )
    v2 = CDmeAttributeReference::LookupAttributeHandle(this);
  return v2 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004ECB20
// Name: protected: void CDmeAttributeReference::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::OnConstruction(CDmeAttributeReference *this)
{
  CDmaElement<CDmElement> *p_m_Element; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax

  p_m_Element = &this->m_Element;
  this->m_Element.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "element",
                                   type: AT_FIRST_VALUE_TYPE,
                                   pMemory: &this->m_Element);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Element->m_pAttribute, typeSymbol: CDmElement::m_classType);
  p_m_Element->m_pAttribute->m_nFlags |= 0x1100u;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "attribute",
         type: AT_STRING,
         pMemory: &this->m_AttributeName);
  this->m_AttributeName.m_pAttribute = v3;
  v3->m_nFlags |= 0x500u;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "index", type: AT_INT, pMemory: &this->m_AttributeIndex);
  this->m_AttributeIndex.m_pAttribute = v4;
  v4->m_nFlags |= 0x400u;
  this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x004ECBA0
// Name: public: void const __near * CDmeAttributeReference::GetAttributeValue(enum DmAttributeType_t __near &)const
// Source: json
//------------------------------------------------------------------------------
int *__thiscall CDmeAttributeReference::GetAttributeValue(CDmeAttributeReference *this, DmAttributeType_t *type)
{
  int *result; // eax
  DmAttributeType_t v4; // ecx
  DmAttributeType_t *v5; // edi

  result = (int *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                + 336))(
                    a1: g_pDataModel.u,
                    a2: this->m_AttributeHandle);
  if ( result != nullptr || (result = (int *)CDmeAttributeReference::LookupAttributeHandle(this)) != nullptr )
  {
    v4 = result[4] & 0x1F;
    v5 = type;
    *type = v4;
    if ( (unsigned int)(v4 - 15) > 0xD )
    {
      return (int *)result[1];
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: (CDmrGenericArray *)&type, pAttribute: (CDmAttribute *)result);
      result = CDmrGenericArrayConst::GetUntyped(
                 this: (CDmrGenericArrayConst *)&type,
                 i: this->m_AttributeIndex.m_Storage);
      *v5 -= 14;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004ECC10
// Name: public: void CDmeAttributeReference::SetAttributeValue(void const __near *,enum DmAttributeType_t)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::SetAttributeValue(
        CDmeAttributeReference *this,
        const void *pValue,
        DmAttributeType_t type)
{
  CDmAttribute *v4; // eax
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  v4 = (CDmAttribute *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 336))(
                         a1: g_pDataModel.u,
                         a2: this->m_AttributeHandle);
  if ( v4 != nullptr || (v4 = CDmeAttributeReference::LookupAttributeHandle(this)) != nullptr )
  {
    if ( (v4->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v4, valueType: type, pValue);
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v4);
      CDmrGenericArray::Set(this: &array, i: this->m_AttributeIndex.m_Storage, valueType: type, pValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004ECD20
// Name: public: virtual bool CDmeAttributeReference::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttributeReference::IsA(CDmeAttributeReference *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAttributeReference::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ECD50
// Name: public: virtual int CDmeAttributeReference::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAttributeReference::GetInheritanceDepth(CDmeAttributeReference *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAttributeReference::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004ECE00
// Name: protected: virtual void CDmeAttributeReference::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::PerformConstruction(CDmeAttributeReference *this)
{
  CDmeFXClip::OnDestruction();
  CDmeAttributeReference::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005E8120
// Name: _dynamic_initializer_for__CDmeAttributeReference::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAttributeReference::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAttributeReference::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAttributeReference pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ECB50
// Name: _dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAttributeReference::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E8150
// Name: _dynamic_initializer_for__g_CDmeAttributeReference_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAttributeReference_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E8160
// Name: _dynamic_initializer_for__g_CDmeAttributeReference_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAttributeReference_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAttributeReference_Helper,
           classname: "DmeAttributeReference",
           pFactory: &g_CDmeAttributeReference_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ECB60
// Name: _dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAttributeReference_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0053D750
// Name: public: virtual void CDmeAttributeReference::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::OnAttributeChanged(CDmeAttributeReference *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_Element.m_pAttribute || pAttribute == this->m_AttributeName.m_pAttribute )
    this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x0053D770
// Name: private: class CDmAttribute __near * CDmeAttributeReference::LookupAttributeHandle(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::LookupAttributeHandle(CDmeAttributeReference *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // edi

  m_Handle = this->m_Element.m_Storage.m_Handle;
  this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
  m_pAsString = this->m_AttributeName.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = Ptr;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_AttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0053D7D0
// Name: public: class CDmAttribute __near * CDmeAttributeReference::GetReferencedAttribute(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::GetReferencedAttribute(CDmeAttributeReference *this)
{
  CDmAttribute *result; // eax

  result = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( result == nullptr )
    return CDmeAttributeReference::LookupAttributeHandle(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0053D800
// Name: public: bool CDmeAttributeReference::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttributeReference::IsValid(CDmeAttributeReference *this)
{
  CDmAttribute *v2; // eax

  v2 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( v2 == nullptr )
    v2 = CDmeAttributeReference::LookupAttributeHandle(this);
  return v2 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0053D830
// Name: protected: void CDmeAttributeReference::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::OnConstruction(CDmeAttributeReference *this)
{
  CDmaElement<CDmElement> *p_m_Element; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax

  p_m_Element = &this->m_Element;
  this->m_Element.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "element",
                                   type: AT_FIRST_VALUE_TYPE,
                                   pMemory: &this->m_Element);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Element->m_pAttribute, typeSymbol: CDmElement::m_classType);
  p_m_Element->m_pAttribute->m_nFlags |= 0x1100u;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "attribute",
         type: AT_STRING,
         pMemory: &this->m_AttributeName);
  this->m_AttributeName.m_pAttribute = v3;
  v3->m_nFlags |= 0x500u;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "index", type: AT_INT, pMemory: &this->m_AttributeIndex);
  this->m_AttributeIndex.m_pAttribute = v4;
  v4->m_nFlags |= 0x400u;
  this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x0053D8B0
// Name: public: void const __near * CDmeAttributeReference::GetAttributeValue(enum DmAttributeType_t __near &)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::GetAttributeValue(
        CDmeAttributeReference *this,
        DmAttributeType_t *type)
{
  CDmAttribute *result; // eax
  DmAttributeType_t v4; // ecx
  DmAttributeType_t *v5; // edi

  result = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( result != nullptr || (result = CDmeAttributeReference::LookupAttributeHandle(this)) != nullptr )
  {
    v4 = result->m_nFlags & 0x1F;
    v5 = type;
    *type = v4;
    if ( (unsigned int)(v4 - 15) > 0xD )
    {
      return (CDmAttribute *)result->m_pData;
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: (CDmrGenericArray *)&type, pAttribute: result);
      result = (CDmAttribute *)CDmrGenericArrayConst::GetUntyped(
                                 this: (CDmrGenericArrayConst *)&type,
                                 i: this->m_AttributeIndex.m_Storage);
      *v5 -= 14;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0053D920
// Name: public: void CDmeAttributeReference::SetAttributeValue(void const __near *,enum DmAttributeType_t)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::SetAttributeValue(
        CDmeAttributeReference *this,
        const void *pValue,
        DmAttributeType_t type)
{
  CDmAttribute *v4; // eax
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  v4 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( v4 != nullptr || (v4 = CDmeAttributeReference::LookupAttributeHandle(this)) != nullptr )
  {
    if ( (v4->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v4, valueType: type, pValue);
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v4);
      CDmrGenericArray::Set(this: &array, i: this->m_AttributeIndex.m_Storage, valueType: type, pValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053DA60
// Name: public: virtual bool CDmeAttributeReference::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttributeReference::IsA(CDmeAttributeReference *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAttributeReference::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0053DA90
// Name: public: virtual int CDmeAttributeReference::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAttributeReference::GetInheritanceDepth(CDmeAttributeReference *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAttributeReference::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0053DB40
// Name: protected: virtual void CDmeAttributeReference::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::PerformConstruction(CDmeAttributeReference *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeAttributeReference::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057D080
// Name: _dynamic_initializer_for__CDmeAttributeReference::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAttributeReference::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAttributeReference::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAttributeReference pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EC40
// Name: _dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAttributeReference::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057D0B0
// Name: _dynamic_initializer_for__g_CDmeAttributeReference_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAttributeReference_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D0C0
// Name: _dynamic_initializer_for__g_CDmeAttributeReference_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAttributeReference_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAttributeReference_Helper,
           classname: "DmeAttributeReference",
           pFactory: &g_CDmeAttributeReference_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057D0E0
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (int)s_StringCharConversion.m_pConversion,
    value: nullptr,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0057D140
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0057D170
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D180
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D1A0
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0057D1B0
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EC50
// Name: _dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeAttributeReference_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057EC60
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0057ECA0
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x0057ECB0
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00640720
// Name: public: virtual void CDmeAttributeReference::OnAttributeChanged(class CDmAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::OnAttributeChanged(CDmeAttributeReference *this, CDmAttribute *pAttribute)
{
  if ( pAttribute == this->m_Element.m_pAttribute || pAttribute == this->m_AttributeName.m_pAttribute )
    this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x00640740
// Name: private: class CDmAttribute __near * CDmeAttributeReference::LookupAttributeHandle(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::LookupAttributeHandle(CDmeAttributeReference *this)
{
  DmElementHandle_t m_Handle; // edx
  CDmElement *v3; // eax
  const char *m_pAsString; // edx
  CDmAttribute *result; // eax
  CDmAttribute *v6; // edi

  m_Handle = this->m_Element.m_Storage.m_Handle;
  this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
  v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
  m_pAsString = this->m_AttributeName.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = var;
  if ( v3 == nullptr || m_pAsString == nullptr || *m_pAsString == 0 )
    return nullptr;
  result = CDmElement::FindAttribute(this: v3, pAttributeName: m_pAsString);
  v6 = result;
  if ( result != nullptr )
  {
    this->m_AttributeHandle = CDmAttribute::GetHandle(this: result, bCreate: true);
    return v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006407A0
// Name: public: class CDmAttribute __near * CDmeAttributeReference::GetReferencedAttribute(void)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::GetReferencedAttribute(CDmeAttributeReference *this)
{
  CDmAttribute *result; // eax

  result = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( result == nullptr )
    return CDmeAttributeReference::LookupAttributeHandle(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006407D0
// Name: public: bool CDmeAttributeReference::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttributeReference::IsValid(CDmeAttributeReference *this)
{
  CDmAttribute *v2; // eax

  v2 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( v2 == nullptr )
    v2 = CDmeAttributeReference::LookupAttributeHandle(this);
  return v2 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00640800
// Name: protected: void CDmeAttributeReference::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::OnConstruction(CDmeAttributeReference *this)
{
  CDmaElement<CDmElement> *p_m_Element; // edi
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax

  p_m_Element = &this->m_Element;
  this->m_Element.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "element",
                                   type: AT_FIRST_VALUE_TYPE,
                                   pMemory: &this->m_Element);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Element->m_pAttribute, typeSymbol: CDmElement::m_classType);
  p_m_Element->m_pAttribute->m_nFlags |= 0x1100u;
  v3 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "attribute",
         type: AT_STRING,
         pMemory: &this->m_AttributeName);
  this->m_AttributeName.m_pAttribute = v3;
  v3->m_nFlags |= 0x500u;
  v4 = CDmElement::AddExternalAttribute(this, pAttributeName: "index", type: AT_INT, pMemory: &this->m_AttributeIndex);
  this->m_AttributeIndex.m_pAttribute = v4;
  v4->m_nFlags |= 0x400u;
  this->m_AttributeHandle = DMATTRIBUTE_HANDLE_INVALID;
}

//------------------------------------------------------------------------------
// Address: 0x00640880
// Name: public: void const __near * CDmeAttributeReference::GetAttributeValue(enum DmAttributeType_t __near &)const
// Source: json
//------------------------------------------------------------------------------
CDmAttribute *__thiscall CDmeAttributeReference::GetAttributeValue(
        CDmeAttributeReference *this,
        DmAttributeType_t *type)
{
  CDmAttribute *result; // eax
  DmAttributeType_t v4; // ecx
  DmAttributeType_t *v5; // edi

  result = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( result != nullptr || (result = CDmeAttributeReference::LookupAttributeHandle(this)) != nullptr )
  {
    v4 = result->m_nFlags & 0x1F;
    v5 = type;
    *type = v4;
    if ( (unsigned int)(v4 - 15) > 0xD )
    {
      return (CDmAttribute *)result->m_pData;
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: (CDmrGenericArray *)&type, pAttribute: result);
      result = (CDmAttribute *)CDmrGenericArrayConst::GetUntyped(
                                 this: (CDmrGenericArrayConst *)&type,
                                 i: this->m_AttributeIndex.m_Storage);
      *v5 -= 14;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006408F0
// Name: public: void CDmeAttributeReference::SetAttributeValue(void const __near *,enum DmAttributeType_t)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::SetAttributeValue(
        CDmeAttributeReference *this,
        const void *pValue,
        DmAttributeType_t type)
{
  CDmAttribute *v4; // eax
  CDmrGenericArray array; // [esp+4h] [ebp-4h] BYREF

  v4 = g_pDataModel->GetAttribute_2(this: g_pDataModel, a2: this->m_AttributeHandle);
  if ( v4 != nullptr || (v4 = CDmeAttributeReference::LookupAttributeHandle(this)) != nullptr )
  {
    if ( (v4->m_nFlags & 0x1Fu) - 15 > 0xD )
    {
      CDmAttribute::SetValue(this: v4, valueType: type, pValue);
    }
    else
    {
      CDmrGenericArray::CDmrGenericArray(this: &array, pAttribute: v4);
      CDmrGenericArray::Set(this: &array, i: this->m_AttributeIndex.m_Storage, valueType: type, pValue);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00640A00
// Name: public: virtual bool CDmeAttributeReference::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeAttributeReference::IsA(CDmeAttributeReference *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeAttributeReference::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00640A30
// Name: public: virtual int CDmeAttributeReference::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeAttributeReference::GetInheritanceDepth(CDmeAttributeReference *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeAttributeReference::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00640AF0
// Name: protected: virtual void CDmeAttributeReference::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeAttributeReference::PerformConstruction(CDmeAttributeReference *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeAttributeReference::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x006BAFF0
// Name: _dynamic_initializer_for__CDmeAttributeReference::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeAttributeReference::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeAttributeReference::s_Allocator,
    blockSize: 0x64u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeAttributeReference pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BDA60
// Name: _dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeAttributeReference::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeAttributeReference::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BB020
// Name: _dynamic_initializer_for__g_CDmeAttributeReference_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeAttributeReference_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006BB030
// Name: _dynamic_initializer_for__g_CDmeAttributeReference_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeAttributeReference_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeAttributeReference_Helper,
           classname: "DmeAttributeReference",
           pFactory: &g_CDmeAttributeReference_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BB050
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BB070
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x006BB080
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x006BB090
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (unsigned __int8 *)s_StringCharConversion.m_pConversion,
    value: 0,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006BB0F0
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x006BB120
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x006BDA70
// Name: _dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeAttributeReference_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeAttributeReference_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BDA80
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x006BDA90
// Name: _dynamic_atexit_destructor_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupSymbolTable__()
{
  CUtlSymbolTableMT *v0; // esi

  v0 = CUtlSymbol::s_pSymbolTable;
  if ( CUtlSymbol::s_pSymbolTable != nullptr )
  {
    CUtlSymbolTable::RemoveAll(this: CUtlSymbol::s_pSymbolTable);
    CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    free(pMem: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x006BDAD0
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x006BDB20
// Name: _DataMapInit_VTFFileBaseHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileBaseHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_73);
}

//------------------------------------------------------------------------------
// Address: 0x006BDB30
// Name: _DataMapInit_VTFFileHeaderV7_1_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderV7_1_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_74);
}

//------------------------------------------------------------------------------
// Address: 0x006BDB40
// Name: _DataMapInit_VTFFileHeaderV7_2_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderV7_2_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_75);
}

//------------------------------------------------------------------------------
// Address: 0x006BDB50
// Name: _DataMapInit_VTFFileHeaderV7_3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderV7_3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_76);
}

//------------------------------------------------------------------------------
// Address: 0x006BDB60
// Name: _DataMapInit_VTFFileHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeader_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_77);
}

//------------------------------------------------------------------------------
// Address: 0x006BDB70
// Name: _DataMapInit_VTFFileHeaderX360_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderX360_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_78);
}

//------------------------------------------------------------------------------
// Address: 0x006BDB80
// Name: _DataMapInit_VTFFileHeaderPS3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl DataMapInit_VTFFileHeaderPS3_t__::_2_::_dynamic_atexit_destructor_for__nameHolder__()
{
  CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(this: &nameHolder_79);
}

} // namespace vmap
