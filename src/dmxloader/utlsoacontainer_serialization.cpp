// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dmxloader/utlsoacontainer_serialization.cpp
// Functions: 9
// ============================================================

#include "dmxloader\utlsoacontainer_serialization.h"

//------------------------------------------------------------------------------
// Address: 0x00563110
// Name: public: bool CSOAContainer_Serializable::Serialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSOAContainer_Serializable::Serialize(CSOAContainer_Serializable *this, CDmxElement *pRootElement)
{
  int v3; // eax
  EAttributeDataType *m_nDataType; // ecx
  CDmxAttribute *v6; // esi
  _DWORD *m_pData; // esi
  CDmxAttribute *v8; // eax
  CDmxAttribute *v9; // esi
  _DWORD *v10; // eax
  CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *v11; // esi
  unsigned int v12; // eax
  CDmxAttribute *v13; // eax
  CDmxAttribute *v14; // ebx
  _DWORD *v15; // eax
  CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *v16; // ebx
  unsigned int v17; // eax
  int v18; // esi
  unsigned __int8 **m_pAttributePtrs; // ebx
  unsigned int v20; // eax
  unsigned int v21; // eax
  int v22; // [esp+8h] [ebp-Ch]
  __m128i *pBaseConstantPtr; // [esp+Ch] [ebp-8h]
  __m128i *pBaseDataPtr; // [esp+10h] [ebp-4h]

  CDmxElement::LockForChanges(this: pRootElement, bLock: true);
  if ( this->m_nColumns <= 0 || this->m_nRows <= 0 || this->m_nSlices <= 0 )
    goto LABEL_7;
  v3 = 0;
  m_nDataType = this->m_nDataType;
  while ( *m_nDataType == ATTRDATATYPE_NONE )
  {
    ++v3;
    ++m_nDataType;
    if ( v3 >= 32 )
      goto LABEL_7;
  }
  if ( this->m_pDataMemory != nullptr || this->m_pConstantDataMemory != nullptr )
  {
    CDmxElement::LockForChanges(this: pRootElement, bLock: true);
    v6 = CDmxElement::AddAttribute(this: pRootElement, pAttributeName: (CDmxAttribute *)"version");
    CDmxAttribute::AllocateDataMemory(this: v6, type: AT_INT);
    m_pData = v6->m_pData;
    if ( m_pData != nullptr )
      *m_pData = 1;
    if ( pRootElement != nullptr )
      CDmxElement::LockForChanges(this: pRootElement, bLock: false);
    CDmxElement::AddAttributesFromStructure(
      this: pRootElement,
      pData: (char *)this,
      pUnpack: (CDmxAttribute *)s_pSOAContainerUnpack);
    v8 = CDmxElement::AddAttribute(this: pRootElement, pAttributeName: (CDmxAttribute *)"memory_data");
    v9 = v8;
    if ( v8->m_Type != AT_FLOAT_ARRAY )
    {
      CDmxAttribute::AllocateDataMemory(this: v8, type: AT_FLOAT_ARRAY);
      v10 = v9->m_pData;
      if ( v10 != nullptr )
      {
        *v10 = 0;
        v10[1] = 0;
        v10[2] = 0;
        v10[3] = 0;
        v10[4] = 0;
      }
    }
    v11 = (CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *)v9->m_pData;
    v12 = CSOAContainer::DataMemorySize(this);
    v11->m_Size = 0;
    CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
      this: v11,
      elem: 0,
      num: v12 >> 2);
    v13 = CDmxElement::AddAttribute(this: pRootElement, pAttributeName: (CDmxAttribute *)"constant_data");
    v14 = v13;
    if ( v13->m_Type != AT_FLOAT_ARRAY )
    {
      CDmxAttribute::AllocateDataMemory(this: v13, type: AT_FLOAT_ARRAY);
      v15 = v14->m_pData;
      if ( v15 != nullptr )
      {
        *v15 = 0;
        v15[1] = 0;
        v15[2] = 0;
        v15[3] = 0;
        v15[4] = 0;
      }
    }
    v16 = (CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *)v14->m_pData;
    v17 = CSOAContainer::ConstantMemorySize(this);
    v16->m_Size = 0;
    CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
      this: v16,
      elem: 0,
      num: v17 >> 2);
    pBaseDataPtr = (__m128i *)v11->m_Memory.m_pMemory;
    pBaseConstantPtr = (__m128i *)v16->m_Memory.m_pMemory;
    v18 = 0;
    v22 = 1;
    m_pAttributePtrs = this->m_pAttributePtrs;
    do
    {
      if ( m_pAttributePtrs[32] != (unsigned __int8 *)-1 )
      {
        if ( (v22 & this->m_nFieldPresentMask) != 0 )
        {
          v20 = CSOAContainer::AttributeMemorySize(this, nAttrIndex: v18);
          memcpy(dst: pBaseDataPtr, src: (const __m128i *)*m_pAttributePtrs, count: v20);
          pBaseDataPtr = (__m128i *)((char *)pBaseDataPtr + CSOAContainer::AttributeMemorySize(this, nAttrIndex: v18));
        }
        else
        {
          v21 = CSOAContainer::AttributeMemorySize(this, nAttrIndex: v18);
          memcpy(dst: pBaseConstantPtr, src: (const __m128i *)*m_pAttributePtrs, count: v21);
          pBaseConstantPtr = (__m128i *)((char *)pBaseConstantPtr
                                       + CSOAContainer::AttributeMemorySize(this, nAttrIndex: v18));
        }
      }
      ++v18;
      ++m_pAttributePtrs;
      v22 = __ROL4__(v22, 1);
    }
    while ( v18 < 32 );
    if ( pRootElement != nullptr )
      CDmxElement::LockForChanges(this: pRootElement, bLock: false);
    return 1;
  }
  else
  {
LABEL_7:
    _Warning(a1: "ERROR: CSOAContainer_Serializable::Unserialize - no data to serialize!\n");
    if ( pRootElement != nullptr )
      CDmxElement::LockForChanges(this: pRootElement, bLock: false);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00563310
// Name: bool SerializeCSOAContainer(class CSOAContainer const __near *,class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SerializeCSOAContainer(CSOAContainer_Serializable *pContainer, CDmxElement *pRootElement)
{
  return CSOAContainer_Serializable::Serialize(this: pContainer, pRootElement);
}

//------------------------------------------------------------------------------
// Address: 0x0056DB00
// Name: CSOAContainer_Serializable_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *CSOAContainer_Serializable_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<CSOAContainer_Serializable>();
  s_pUnpack_2 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0056DB10
// Name: _dynamic_initializer_for__s_pSOAContainerUnpack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__s_pSOAContainerUnpack__()
{
  s_pSOAContainerUnpack = s_pUnpack_2;
  return s_pUnpack_2;
}

//------------------------------------------------------------------------------
// Address: 0x0056DB20
// Name: _dynamic_initializer_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__()
{
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTableLargeBaseTreeEntry_t *,int> *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 320);
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Root = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_NumElements = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_FirstFree = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_LastAlloc.index = -1;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_pElements = CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_Lookup.m_Elements.m_pMemory;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_pMemory = nullptr;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_nAllocationCount = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Memory.m_nGrowSize = 8;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_Size = 0;
  CDmxKeyValues2ErrorStack::m_ErrorSymbolTable.m_StringPools.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__CDmxKeyValues2ErrorStack::m_ErrorSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x0056DB90
// Name: _dynamic_initializer_for__g_KeyValues2ErrorStack___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KeyValues2ErrorStack___0()
{
  memset(&g_KeyValues2ErrorStack_0, 0xFFu, 0x100u);
  g_KeyValues2ErrorStack_0.m_pFilename = "NULL";
  g_KeyValues2ErrorStack_0.m_nFileLine = 1;
  g_KeyValues2ErrorStack_0.m_errorIndex = 0;
  g_KeyValues2ErrorStack_0.m_maxErrorIndex = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0056DBD0
// Name: _dynamic_atexit_destructor_for____s_SteamApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____s_SteamApplicationObject__()
{
  CUtlDict<int,unsigned short>::RemoveAll(this: &_s_SteamApplicationObject.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &_s_SteamApplicationObject.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&_s_SteamApplicationObject.m_NonAppSystemFactories);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&_s_SteamApplicationObject.m_Systems);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&_s_SteamApplicationObject.m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x0056DC10
// Name: _dynamic_atexit_destructor_for____s_ApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____s_ApplicationObject__()
{
  CUtlDict<int,unsigned short>::RemoveAll(this: &_s_ApplicationObject.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &_s_ApplicationObject.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&_s_ApplicationObject.m_NonAppSystemFactories);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&_s_ApplicationObject.m_Systems);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&_s_ApplicationObject.m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x0056DC50
// Name: _dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &DmAttributeList_t::s_Allocator);
}

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1040AF20
// Name: public: bool CSOAContainer_Serializable::Unserialize(class CDmxElement const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSOAContainer_Serializable::Unserialize(CSOAContainer_Serializable *this, CDmxElement *pRootElement)
{
  const CDmxAttribute *Attribute; // eax
  int *m_pData; // eax
  const CDmxAttribute *v7; // eax
  unsigned __int8 *m_nRows; // ebx
  int m_nSlices; // edx
  int v10; // eax
  EAttributeDataType *m_nDataType; // ecx
  SOAThreadMode_t m_eThreadMode; // edi
  const CUtlVector<float,CUtlMemory<float,int> > *v13; // edi
  unsigned int v14; // eax
  const CUtlVector<float,CUtlMemory<float,int> > *v15; // edi
  unsigned int v16; // eax
  CDmxAttribute *pConstantMemoryAttribute; // [esp+Ch] [ebp-Ch]
  CDmxAttribute *pDataMemoryAttribute; // [esp+10h] [ebp-8h]
  int nVersion; // [esp+14h] [ebp-4h] BYREF
  int nError; // [esp+20h] [ebp+8h]

  nVersion = -1;
  Attribute = CDmxElement::GetAttribute(this: pRootElement, pAttributeName: "version");
  if ( Attribute != nullptr )
  {
    if ( Attribute->m_Type == AT_INT )
    {
      m_pData = (int *)Attribute->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<int>'::`4'::defaultValue = 0;
      m_pData = &`CDmxAttribute::GetValue<int>'::`4'::defaultValue;
    }
  }
  else
  {
    m_pData = &nVersion;
  }
  nVersion = *m_pData;
  if ( nVersion == -1 )
  {
    _Warning(a1: "ERROR: CSOAContainer_Serializable::Unserialize - missing version field!\n");
    return 0;
  }
  CSOAContainer::Purge(this);
  CDmxElement::UnpackIntoStructure(this: pRootElement, pData: this, pUnpack: (CDmxAttribute *)s_pSOAContainerUnpack);
  nError = 0;
  pDataMemoryAttribute = (CDmxAttribute *)CDmxElement::GetAttribute(this: pRootElement, pAttributeName: "memory_data");
  v7 = CDmxElement::GetAttribute(this: pRootElement, pAttributeName: "constant_data");
  pConstantMemoryAttribute = (CDmxAttribute *)v7;
  if ( pDataMemoryAttribute == nullptr || v7 == nullptr )
    nError = 1;
  if ( this->m_nColumns <= 0
    || (int)(m_nRows = (unsigned __int8 *)this->m_nRows) <= 0
    || (m_nSlices = this->m_nSlices) <= 0 )
  {
LABEL_17:
    nError = 1;
  }
  else
  {
    v10 = 0;
    m_nDataType = this->m_nDataType;
    while ( *m_nDataType == ATTRDATATYPE_NONE )
    {
      ++v10;
      ++m_nDataType;
      if ( v10 >= 32 )
        goto LABEL_17;
    }
    if ( nError != 0 )
      goto LABEL_29;
    if ( nVersion == 1 )
    {
      m_eThreadMode = this->m_eThreadMode;
      CSOAContainer::AllocateData(
        this,
        nNCols: (unsigned __int8 *)this->m_nColumns,
        nNRows: m_nRows,
        nSlices: m_nSlices);
      CSOAContainer::SetThreadMode(this, eThreadMode: m_eThreadMode);
      if ( this->m_pDataMemory != nullptr )
      {
        v13 = CDmxAttribute::GetArray<float>(this: pDataMemoryAttribute);
        v14 = CSOAContainer::DataMemorySize(this);
        if ( v14 >> 2 == v13->m_Size )
          memcpy(dst: this->m_pDataMemory, src: (unsigned __int8 *)v13->m_Memory.m_pMemory, count: v14);
        else
          nError = 2;
      }
      if ( this->m_pConstantDataMemory != nullptr )
      {
        v15 = CDmxAttribute::GetArray<float>(this: pConstantMemoryAttribute);
        v16 = CSOAContainer::ConstantMemorySize(this);
        if ( v16 >> 2 != v15->m_Size )
        {
          nError = 3;
          goto LABEL_29;
        }
        memcpy(dst: this->m_pConstantDataMemory, src: (unsigned __int8 *)v15->m_Memory.m_pMemory, count: v16);
      }
      if ( nError == 0 )
        return 1;
    }
    else
    {
      nError = 1;
    }
  }
LABEL_29:
  if ( nError == 1 )
  {
    _Warning(a1: "ERROR: CSOAContainer_Serializable::Unserialize - DMX data does not represent a valid container!\n");
  }
  else if ( nError == 2 )
  {
    _Warning(a1: "ERROR: CSOAContainer_Serializable::Unserialize - found wrong amount of memory data!\n");
  }
  else
  {
    _Warning(a1: "ERROR: CSOAContainer_Serializable::Unserialize - found wrong amount of constant data!\n");
  }
  CSOAContainer::Purge(this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1040B100
// Name: bool UnserializeCSOAContainer(class CSOAContainer const __near *,class CDmxElement const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl UnserializeCSOAContainer(CSOAContainer_Serializable *pContainer, const CDmxElement *pRootElement)
{
  return CSOAContainer_Serializable::Unserialize(this: pContainer, pRootElement);
}

//------------------------------------------------------------------------------
// Address: 0x1042F5A0
// Name: CSOAContainer_Serializable_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *CSOAContainer_Serializable_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<CSOAContainer_Serializable>();
  s_pUnpack_175 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1042F5B0
// Name: _dynamic_initializer_for__s_pSOAContainerUnpack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__s_pSOAContainerUnpack__()
{
  s_pSOAContainerUnpack = s_pUnpack_175;
  return s_pUnpack_175;
}

} // namespace client
