// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mdlobjects/mpp_utils.cpp
// Functions: 8
// ============================================================

#include "mdlobjects\mpp_utils.h"

//------------------------------------------------------------------------------
// Address: 0x004AE350
// Name: public: class CDmeTransform __near * CDmeTransformList::GetTransform(int)
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeTransformList::GetTransform(CDmeTransformList *this, int nIndex)
{
  int v2; // eax
  int v3; // esi

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Transforms.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeTransform::m_classType.u) != 0 )
  {
    return (CDmeTransform *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004AE3A0
// Name: class CUtlString ComputeDmElementIdStr(class CDmElement const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__cdecl ComputeDmElementIdStr(CUtlString *result, const CDmElement *pDmElement)
{
  const char *m_pAsString; // eax
  const char *v4; // eax
  char pszBuf[64]; // [esp+4h] [ebp-50h] BYREF
  CUtlString sReturn; // [esp+44h] [ebp-10h] BYREF

  if ( pDmElement != nullptr )
  {
    CUtlString::CUtlString(this: &sReturn);
    m_pAsString = pDmElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = WindowName;
    CUtlString::operator=(this: &sReturn, src: m_pAsString);
    CUtlString::operator+=(this: &sReturn, rhs: "(");
    v4 = pDmElement->m_Name.m_Storage.u.m_pAsString;
    if ( v4 == (const char *)-1 )
      v4 = WindowName;
    CUtlString::operator=(this: &sReturn, src: v4);
    CUtlString::operator+=(this: &sReturn, rhs: "):\"");
    UniqueIdToString(id: &pDmElement->m_Id, pBuf: pszBuf, nMaxLen: 64);
    CUtlString::operator+=(this: &sReturn, rhs: pszBuf);
    CUtlString::operator+=(this: &sReturn, rhs: "\"");
    CUtlString::CUtlString(this: result, string: &sReturn);
    sReturn.m_Storage.m_nActualLength = 0;
    if ( sReturn.m_Storage.m_Memory.m_nGrowSize >= 0 && sReturn.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sReturn.m_Storage.m_Memory.m_pMemory);
    return result;
  }
  else
  {
    CUtlString::CUtlString(this: result, pString: "NULL(Unknown):\"Unknown\"");
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0059A820
// Name: _dynamic_initializer_for__CDmeTransformList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059EA60
// Name: _dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x004AE480
// Name: bool FindReferringElements<class CDmeChannel>(class CUtlVector<class CDmeChannel __near *,class CUtlMemory<class CDmeChannel __near *,int>> __near &,class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl FindReferringElements<CDmeChannel>(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *list,
        CDmElement *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // esi
  DmElementHandle_t Handle; // eax
  DmFileId_t m_fileId; // eax
  CDmeChannel *v8; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmeChannel **v11; // ecx
  int v12; // eax
  CDmeChannel **v13; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v5 = *(_DWORD *)g_pDataModel.u.m_Id;
    Handle = CDmElement::GetHandle(this: pElement);
    it.m_curr = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(v5 + 436))(
                  a1: g_pDataModel.u,
                  a2: Handle);
    m_fileId = pElement->m_fileId;
  }
  else
  {
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_fileId = DMFILEID_INVALID;
  }
  for ( it.m_fileid = m_fileId;
        it.m_curr != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
        it.m_curr = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id + 440))(
                      a1: g_pDataModel.u,
                      a2: it.m_curr) )
  {
    v8 = CAttributeReferenceIterator::FilterReference<CDmeChannel>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( v8 != nullptr )
    {
      m_pMemory = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v11 = (CDmeChannel **)list->m_pMemory;
      v12 = (int)list[1].m_pMemory - m_pMemory - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[m_pMemory + 1], src: &v11[m_pMemory], count: 4 * v12);
      v13 = (CDmeChannel **)&list->m_pMemory[m_pMemory];
      if ( v13 != nullptr )
        *v13 = v8;
    }
  }
  return (int)list[1].m_pMemory > 0;
}

//------------------------------------------------------------------------------
// Address: 0x0059A850
// Name: _dynamic_initializer_for__g_CDmeTransformList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059A860
// Name: _dynamic_initializer_for__g_CDmeTransformList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformList_Helper,
           classname: "DmeTransformList",
           pFactory: &g_CDmeTransformList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059EA70
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeTransformList_Factory.m_CallBackList);
}

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004F3770
// Name: class CUtlString ComputeDmElementIdStr(class CDmElement const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__cdecl ComputeDmElementIdStr(CUtlString *result, const CDmElement *pDmElement)
{
  const char *m_pAsString; // eax
  const char *v4; // eax
  char pszBuf[64]; // [esp+4h] [ebp-50h] BYREF
  CUtlString sReturn; // [esp+44h] [ebp-10h] BYREF

  if ( pDmElement != nullptr )
  {
    CUtlString::CUtlString(this: &sReturn);
    m_pAsString = pDmElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    CUtlString::operator=(this: &sReturn, src: m_pAsString);
    CUtlString::operator+=(this: &sReturn, rhs: "(");
    v4 = pDmElement->m_Name.m_Storage.u.m_pAsString;
    if ( v4 == (const char *)-1 )
      v4 = pDeltaStateName;
    CUtlString::operator=(this: &sReturn, src: v4);
    CUtlString::operator+=(this: &sReturn, rhs: "):\"");
    UniqueIdToString(id: &pDmElement->m_Id, pBuf: pszBuf, nMaxLen: 64);
    CUtlString::operator+=(this: &sReturn, rhs: pszBuf);
    CUtlString::operator+=(this: &sReturn, rhs: "\"");
    CUtlString::CUtlString(this: result, string: &sReturn);
    sReturn.m_Storage.m_nActualLength = 0;
    if ( sReturn.m_Storage.m_Memory.m_nGrowSize >= 0 && sReturn.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sReturn.m_Storage.m_Memory.m_pMemory);
    return result;
  }
  else
  {
    CUtlString::CUtlString(this: result, pString: "NULL(Unknown):\"Unknown\"");
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F3850
// Name: bool FindReferringElements<class CDmeChannel>(class CUtlVector<class CDmeChannel __near *,class CUtlMemory<class CDmeChannel __near *,int>> __near &,class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl FindReferringElements<CDmeChannel>(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *list,
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // esi
  int v6; // eax
  DmFileId_t m_pMemory; // eax
  CDmeChannel *v8; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmeChannel **v11; // ecx
  int v12; // eax
  CDmeChannel **v13; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v5 = *(_DWORD *)g_pDataModel.u.m_Id;
    v6 = CExpressionCalculator::VariableCount(this: pElement);
    it.m_curr = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v5 + 436))(a1: g_pDataModel.u, a2: v6);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
  }
  else
  {
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  for ( it.m_fileid = m_pMemory;
        it.m_curr != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
        it.m_curr = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id + 440))(
                      a1: g_pDataModel.u,
                      a2: it.m_curr) )
  {
    v8 = CAttributeReferenceIterator::FilterReference<CDmeChannel>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( v8 != nullptr )
    {
      v9 = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: v9 - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v11 = (CDmeChannel **)list->m_pMemory;
      v12 = (int)list[1].m_pMemory - v9 - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = (CDmeChannel **)&list->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = v8;
    }
  }
  return (int)list[1].m_pMemory > 0;
}

} // namespace mdlcompile

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x0051DE30
// Name: public: class CDmeTransform __near * CDmeTransformList::GetTransform(int)
// Source: json
//------------------------------------------------------------------------------
CDmeTransform *__thiscall CDmeTransformList::GetTransform(CDmeTransformList *this, int nIndex)
{
  int v2; // eax
  int v3; // esi

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Transforms.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeTransform::m_classType.u) != 0 )
  {
    return (CDmeTransform *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051DE80
// Name: class CUtlString ComputeDmElementIdStr(class CDmElement const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__cdecl ComputeDmElementIdStr(CUtlString *result, const CDmElement *pDmElement)
{
  const char *m_pAsString; // eax
  const char *v4; // eax
  char pszBuf[64]; // [esp+4h] [ebp-50h] BYREF
  CUtlString sReturn; // [esp+44h] [ebp-10h] BYREF

  if ( pDmElement != nullptr )
  {
    CUtlString::CUtlString(this: &sReturn);
    m_pAsString = pDmElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    CUtlString::operator=(this: &sReturn, src: m_pAsString);
    CUtlString::operator+=(this: &sReturn, rhs: "(");
    v4 = pDmElement->m_Name.m_Storage.u.m_pAsString;
    if ( v4 == (const char *)-1 )
      v4 = defaultValue;
    CUtlString::operator=(this: &sReturn, src: v4);
    CUtlString::operator+=(this: &sReturn, rhs: "):\"");
    UniqueIdToString(id: &pDmElement->m_Id, pBuf: pszBuf, nMaxLen: 64);
    CUtlString::operator+=(this: &sReturn, rhs: pszBuf);
    CUtlString::operator+=(this: &sReturn, rhs: "\"");
    CUtlString::CUtlString(this: result, string: &sReturn);
    sReturn.m_Storage.m_nActualLength = 0;
    if ( sReturn.m_Storage.m_Memory.m_nGrowSize >= 0 && sReturn.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sReturn.m_Storage.m_Memory.m_pMemory);
    return result;
  }
  else
  {
    CUtlString::CUtlString(this: result, pString: "NULL(Unknown):\"Unknown\"");
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x006B0410
// Name: _dynamic_initializer_for__CDmeTransformList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeTransformList::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeTransformList::s_Allocator,
    blockSize: 96,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeTransformList pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5090
// Name: _dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeTransformList::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeTransformList::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0051DF60
// Name: bool FindReferringElements<class CDmeChannel>(class CUtlVector<class CDmeChannel __near *,class CUtlMemory<class CDmeChannel __near *,int>> __near &,class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl FindReferringElements<CDmeChannel>(
        CUtlMemory<vgui::TreeNode *,int> *list,
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // esi
  int BufferType; // eax
  DmFileId_t m_pMemory; // eax
  CDmeChannel *v8; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmeChannel **v11; // ecx
  int v12; // eax
  CDmeChannel **v13; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v5 = *(_DWORD *)g_pDataModel.u.m_Id;
    BufferType = CCodecBuffer_Block::GetBufferType(this: pElement);
    it.m_curr = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v5 + 436))(
                  a1: g_pDataModel.u,
                  a2: BufferType);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
  }
  else
  {
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  for ( it.m_fileid = m_pMemory;
        it.m_curr != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
        it.m_curr = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id + 440))(
                      a1: g_pDataModel.u,
                      a2: it.m_curr) )
  {
    v8 = CAttributeReferenceIterator::FilterReference<CDmeChannel>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( v8 != nullptr )
    {
      v9 = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: v9 - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v11 = (CDmeChannel **)list->m_pMemory;
      v12 = (int)list[1].m_pMemory - v9 - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = (CDmeChannel **)&list->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = v8;
    }
  }
  return (int)list[1].m_pMemory > 0;
}

//------------------------------------------------------------------------------
// Address: 0x006B0440
// Name: _dynamic_initializer_for__g_CDmeTransformList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeTransformList_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0450
// Name: _dynamic_initializer_for__g_CDmeTransformList_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeTransformList_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeTransformList_Helper,
           classname: "DmeTransformList",
           pFactory: &g_CDmeTransformList_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B50A0
// Name: _dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeTransformList_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeTransformList_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004EC800
// Name: class CUtlString ComputeDmElementIdStr(class CDmElement const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__cdecl ComputeDmElementIdStr(CUtlString *result, const CDmElement *pDmElement)
{
  const char *m_pAsString; // eax
  const char *v4; // eax
  char pszBuf[64]; // [esp+4h] [ebp-50h] BYREF
  CUtlString sReturn; // [esp+44h] [ebp-10h] BYREF

  if ( pDmElement != nullptr )
  {
    CUtlString::CUtlString(this: &sReturn);
    m_pAsString = pDmElement->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = pDeltaStateName;
    CUtlString::operator=(this: &sReturn, src: m_pAsString);
    CUtlString::operator+=(this: &sReturn, rhs: "(");
    v4 = pDmElement->m_Name.m_Storage.u.m_pAsString;
    if ( v4 == (const char *)-1 )
      v4 = pDeltaStateName;
    CUtlString::operator=(this: &sReturn, src: v4);
    CUtlString::operator+=(this: &sReturn, rhs: "):\"");
    UniqueIdToString(id: &pDmElement->m_Id, pBuf: pszBuf, nMaxLen: 64);
    CUtlString::operator+=(this: &sReturn, rhs: pszBuf);
    CUtlString::operator+=(this: &sReturn, rhs: "\"");
    CUtlString::CUtlString(this: result, string: &sReturn);
    sReturn.m_Storage.m_nActualLength = 0;
    if ( sReturn.m_Storage.m_Memory.m_nGrowSize >= 0 && sReturn.m_Storage.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sReturn.m_Storage.m_Memory.m_pMemory);
    return result;
  }
  else
  {
    CUtlString::CUtlString(this: result, pString: "NULL(Unknown):\"Unknown\"");
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EC8E0
// Name: bool FindReferringElements<class CDmeChannel>(class CUtlVector<class CDmeChannel __near *,class CUtlMemory<class CDmeChannel __near *,int>> __near &,class CDmElement const __near *,class CUtlSymbolLarge,bool,enum TraversalDepth_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl FindReferringElements<CDmeChannel>(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *list,
        CExpressionCalculator *pElement,
        CUtlSymbolLarge symAttrName,
        bool bMustBeInSameFile,
        TraversalDepth_t depth)
{
  int v5; // esi
  int v6; // eax
  DmFileId_t m_pMemory; // eax
  CDmeChannel *v8; // ebx
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmeChannel **v11; // ecx
  int v12; // eax
  CDmeChannel **v13; // eax
  CAttributeReferenceIterator it; // [esp+Ch] [ebp-8h] BYREF

  if ( pElement != nullptr )
  {
    v5 = *(_DWORD *)g_pDataModel.u.m_Id;
    v6 = CExpressionCalculator::VariableCount(this: pElement);
    it.m_curr = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v5 + 436))(a1: g_pDataModel.u, a2: v6);
    m_pMemory = (DmFileId_t)pElement->m_stack.m_Memory.m_pMemory;
  }
  else
  {
    it.m_curr = DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
    m_pMemory = DMFILEID_INVALID;
  }
  for ( it.m_fileid = m_pMemory;
        it.m_curr != DMATTRIBUTE_REFERENCE_ITERATOR_INVALID;
        it.m_curr = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmAttributeReferenceIterator_t))(*(_DWORD *)g_pDataModel.u.m_Id + 440))(
                      a1: g_pDataModel.u,
                      a2: it.m_curr) )
  {
    v8 = CAttributeReferenceIterator::FilterReference<CDmeChannel>(this: &it, symAttrName, bMustBeInSameFile, depth);
    if ( v8 != nullptr )
    {
      v9 = (int)list[1].m_pMemory;
      m_nAllocationCount = list->m_nAllocationCount;
      if ( v9 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: list, num: v9 - m_nAllocationCount + 1);
      ++list[1].m_pMemory;
      v11 = (CDmeChannel **)list->m_pMemory;
      v12 = (int)list[1].m_pMemory - v9 - 1;
      list[1].m_nAllocationCount = (int)list->m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
      v13 = (CDmeChannel **)&list->m_pMemory[v9];
      if ( v13 != nullptr )
        *v13 = v8;
    }
  }
  return (int)list[1].m_pMemory > 0;
}

} // namespace studiomdl
