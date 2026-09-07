// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialobjects/dmesheetsequence.cpp
// Functions: 46
// ============================================================

#include "materialobjects\dmesheetsequence.h"

//------------------------------------------------------------------------------
// Address: 0x00462540
// Name: protected: void CDmeSheetSequence::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSheetSequence::OnConstruction(CDmeSheetSequence *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  int v4; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  this->m_nSequenceNumber.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "sequencenumber",
                                           type: AT_INT,
                                           pMemory: &this->m_nSequenceNumber);
  this->m_Clamp.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "clamp",
                                 type: AT_BOOL,
                                 pMemory: &this->m_Clamp);
  this->m_eMode.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "mode",
                                 type: AT_INT,
                                 pMemory: &this->m_eMode);
  this->m_Frames.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "frames",
                                  type: AT_FIRST_ARRAY_TYPE,
                                  pMemory: &this->m_Frames);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Frames.m_pAttribute, typeSymbol: CDmeSheetSequenceFrame::m_classType);
  m_pAttribute = this->m_Clamp.m_pAttribute;
  value = true;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
  v3 = this->m_eMode.m_pAttribute;
  v4 = 0;
  CDmAttribute::SetValue<int>(this: v3, value: &v4);
}

//------------------------------------------------------------------------------
// Address: 0x004625E0
// Name: public: class CDmeSheetSequence __near * CDmeSheetImage::FindSequence(int)
// Source: json
//------------------------------------------------------------------------------
CDmeSheetSequence *__thiscall CDmeSheetImage::FindSequence(CDmeSheetImage *this, int index)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  if ( index < this->m_mapSequences.m_Storage.m_Size
    && (v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_mapSequences.m_Storage.m_Memory.m_pMemory[index]),
        v3 = v2,
        v2 != nullptr)
    && v2->IsA(this: v2, a2: CDmeSheetSequence::m_classType) )
  {
    return (CDmeSheetSequence *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00462750
// Name: public: virtual bool CDmeSheetSequenceFrame::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSheetSequenceFrame::IsA(CDmeSheetSequenceFrame *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSheetSequenceFrame::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00462780
// Name: public: virtual int CDmeSheetSequenceFrame::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSheetSequenceFrame::GetInheritanceDepth(CDmeSheetSequenceFrame *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSheetSequenceFrame::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004627D0
// Name: protected: virtual int CDmeSheetSequenceFrame::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSheetSequenceFrame::AllocatedSize(CDmeSheetSequenceFrame *this)
{
  return 104;
}

//------------------------------------------------------------------------------
// Address: 0x004627E0
// Name: protected: virtual void CDmeSheetSequenceFrame::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSheetSequenceFrame::PerformConstruction(CDmeSheetSequenceFrame *this)
{
  CSteamApplication::PostShutdown();
  this->m_pSheetImages.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "sheetimages",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_pSheetImages);
  CDmAttribute::SetElementTypeSymbol(this: this->m_pSheetImages.m_pAttribute, typeSymbol: CDmeSheetImage::m_classType);
  this->m_fDisplayTime.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "displaytime",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_fDisplayTime);
}

//------------------------------------------------------------------------------
// Address: 0x00462880
// Name: public: virtual bool CDmeSheetSequence::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSheetSequence::IsA(CDmeSheetSequence *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSheetSequence::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004628B0
// Name: public: virtual int CDmeSheetSequence::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSheetSequence::GetInheritanceDepth(CDmeSheetSequence *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSheetSequence::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004628F0
// Name: protected: virtual int CDmeSheetSequence::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSheetSequence::AllocatedSize(CDmeSheetSequence *this)
{
  return 120;
}

//------------------------------------------------------------------------------
// Address: 0x00462900
// Name: protected: virtual void CDmeSheetSequence::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSheetSequence::PerformConstruction(CDmeSheetSequence *this)
{
  CSteamApplication::PostShutdown();
  CDmeSheetSequence::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00462A30
// Name: public: virtual bool CDmeSheetImage::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSheetImage::IsA(CDmeSheetImage *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSheetImage::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00462A60
// Name: public: virtual int CDmeSheetImage::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSheetImage::GetInheritanceDepth(CDmeSheetImage *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSheetImage::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00462AA0
// Name: protected: virtual int CDmeSheetImage::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSheetImage::AllocatedSize(CDmeSheetImage *this)
{
  return 116;
}

//------------------------------------------------------------------------------
// Address: 0x00462AB0
// Name: protected: virtual void CDmeSheetImage::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSheetImage::PerformConstruction(CDmeSheetImage *this)
{
  CSteamApplication::PostShutdown();
  this->m_XCoord.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "xcoord",
                                  type: AT_INT,
                                  pMemory: &this->m_XCoord);
  this->m_YCoord.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "ycoord",
                                  type: AT_INT,
                                  pMemory: &this->m_YCoord);
  this->m_mapSequences.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "mapsequences",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_mapSequences);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_mapSequences.m_pAttribute,
    typeSymbol: CDmeSheetSequence::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004B7420
// Name: _dynamic_initializer_for__CDmeSheetImage::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSheetImage::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSheetImage::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSheetImage pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSheetImage::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x004B7480
// Name: _dynamic_initializer_for__CDmeSheetSequenceFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSheetSequenceFrame::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSheetSequenceFrame::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSheetSequenceFrame pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSheetSequenceFrame::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x004B74E0
// Name: _dynamic_initializer_for__CDmeSheetSequence::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSheetSequence::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSheetSequence::s_Allocator,
    blockSize: 120,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSheetSequence pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSheetSequence::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x004B7A30
// Name: _dynamic_atexit_destructor_for__CDmeSheetImage::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSheetImage::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSheetImage::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x004B7A40
// Name: _dynamic_atexit_destructor_for__CDmeSheetSequenceFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSheetSequenceFrame::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSheetSequenceFrame::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x004B7A50
// Name: _dynamic_atexit_destructor_for__CDmeSheetSequence::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSheetSequence::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSheetSequence::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x004B7450
// Name: _dynamic_initializer_for__g_CDmeSheetImage_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSheetImage_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSheetImage_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x004B7460
// Name: _dynamic_initializer_for__g_CDmeSheetImage_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSheetImage_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSheetImage_Helper,
           classname: "DmeSheetImage",
           pFactory: &g_CDmeSheetImage_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x004B74B0
// Name: _dynamic_initializer_for__g_CDmeSheetSequenceFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSheetSequenceFrame_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSheetSequenceFrame_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x004B74C0
// Name: _dynamic_initializer_for__g_CDmeSheetSequenceFrame_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSheetSequenceFrame_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSheetSequenceFrame_Helper,
           classname: "DmeSheetSequenceFrame",
           pFactory: &g_CDmeSheetSequenceFrame_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x004B7510
// Name: _dynamic_initializer_for__g_CDmeSheetSequence_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSheetSequence_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSheetSequence_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x004B7520
// Name: _dynamic_initializer_for__g_CDmeSheetSequence_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSheetSequence_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSheetSequence_Helper,
           classname: "DmeSheetSequence",
           pFactory: &g_CDmeSheetSequence_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x004B7540
// Name: sub_4B7540
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_4B7540()
{
  struct _SYSTEM_INFO SystemInfo; // [esp+0h] [ebp-24h] BYREF

  GetSystemInfo(lpSystemInfo: &SystemInfo);
  dword_543D4C = SystemInfo.dwNumberOfProcessors;
}

//------------------------------------------------------------------------------
// Address: 0x004B7560
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x004B7580
// Name: _dynamic_initializer_for__g_CleanupSymbolTable__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupSymbolTable__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupSymbolTable__);
}

//------------------------------------------------------------------------------
// Address: 0x004B7590
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x004B75B0
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
// Address: 0x004B75C0
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
// Address: 0x004B7620
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
// Address: 0x004B7650
// Name: _dynamic_initializer_for__s_static_p4_factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_static_p4_factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__s_static_p4_factory__);
}

//------------------------------------------------------------------------------
// Address: 0x004B7660
// Name: _dynamic_atexit_destructor_for____s_SteamApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____s_SteamApplicationObject__()
{
  CUtlDict<int,unsigned short>::RemoveAll(this: &_s_SteamApplicationObject.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &_s_SteamApplicationObject.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&_s_SteamApplicationObject.m_NonAppSystemFactories);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&_s_SteamApplicationObject.m_Systems);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&_s_SteamApplicationObject.m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x004B76A0
// Name: _dynamic_atexit_destructor_for____s_ApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for____s_ApplicationObject__()
{
  CUtlDict<int,unsigned short>::RemoveAll(this: &_s_ApplicationObject.m_SystemDict);
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &_s_ApplicationObject.m_SystemDict.m_Elements.m_Tree);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&_s_ApplicationObject.m_NonAppSystemFactories);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&_s_ApplicationObject.m_Systems);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&_s_ApplicationObject.m_Modules);
}

//------------------------------------------------------------------------------
// Address: 0x004B76E0
// Name: _dynamic_atexit_destructor_for__g_DataModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_DataModel__()
{
  CDataModel::~CDataModel(this: &g_DataModel);
}

//------------------------------------------------------------------------------
// Address: 0x004B76F0
// Name: _dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &DmAttributeList_t::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x004B7A60
// Name: _dynamic_atexit_destructor_for__g_CDmeSheetSequenceFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSheetSequenceFrame_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_CDmeSheetSequenceFrame_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x004B7A70
// Name: _dynamic_atexit_destructor_for__g_CDmeSheetSequence_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSheetSequence_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_CDmeSheetSequence_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x004B7A80
// Name: _dynamic_atexit_destructor_for__g_CDmeSheetImage_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSheetImage_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&g_CDmeSheetImage_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x004B7A90
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    operator delete(p: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x004B7AE0
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
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: &v0->m_StringPools);
    CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short>>(this: &v0->m_Lookup);
    operator delete(p: v0);
  }
  CUtlSymbol::s_pSymbolTable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004B7B20
// Name: _dynamic_atexit_destructor_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::~CExpressionEvaluator(this: &g_ExpressionEvaluator);
}

//------------------------------------------------------------------------------
// Address: 0x004B7B30
// Name: _dynamic_atexit_destructor_for__s_static_p4_factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_static_p4_factory__()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004B7B31
// Name: _operator_new_::_6_::_dynamic_atexit_destructor_for__nomem__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl operator_new_::_6_::_dynamic_atexit_destructor_for__nomem__()
{
  nomem.__vftable = (std::bad_alloc_vtbl *)&std::bad_alloc::`vftable';
  std::exception::~exception(this: &nomem);
}

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004BA8F0
// Name: protected: void CDmeSheetSequence::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSheetSequence::OnConstruction(CDmeSheetSequence *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  int v4; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  this->m_nSequenceNumber.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "sequencenumber",
                                           type: AT_INT,
                                           pMemory: &this->m_nSequenceNumber);
  this->m_Clamp.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "clamp",
                                 type: AT_BOOL,
                                 pMemory: &this->m_Clamp);
  this->m_eMode.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "mode",
                                 type: AT_INT,
                                 pMemory: &this->m_eMode);
  this->m_Frames.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "frames",
                                  type: AT_FIRST_ARRAY_TYPE,
                                  pMemory: &this->m_Frames);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Frames.m_pAttribute, typeSymbol: CDmeSheetSequenceFrame::m_classType);
  m_pAttribute = this->m_Clamp.m_pAttribute;
  value = true;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
  v3 = this->m_eMode.m_pAttribute;
  v4 = 0;
  CDmAttribute::SetValue<int>(this: v3, value: &v4);
}

//------------------------------------------------------------------------------
// Address: 0x004BAAB0
// Name: public: virtual bool CDmeSheetSequenceFrame::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSheetSequenceFrame::IsA(CDmeSheetSequenceFrame *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSheetSequenceFrame::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BAAE0
// Name: public: virtual int CDmeSheetSequenceFrame::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSheetSequenceFrame::GetInheritanceDepth(CDmeSheetSequenceFrame *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSheetSequenceFrame::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BAB20
// Name: protected: virtual void CDmeSheetSequenceFrame::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSheetSequenceFrame::PerformConstruction(CDmeSheetSequenceFrame *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_pSheetImages.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "sheetimages",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_pSheetImages);
  CDmAttribute::SetElementTypeSymbol(this: this->m_pSheetImages.m_pAttribute, typeSymbol: CDmeSheetImage::m_classType);
  this->m_fDisplayTime.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "displaytime",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_fDisplayTime);
}

//------------------------------------------------------------------------------
// Address: 0x004BABB0
// Name: public: virtual bool CDmeSheetSequence::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSheetSequence::IsA(CDmeSheetSequence *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSheetSequence::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BABE0
// Name: public: virtual int CDmeSheetSequence::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSheetSequence::GetInheritanceDepth(CDmeSheetSequence *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSheetSequence::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BAC20
// Name: protected: virtual int CDmeSheetSequence::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSheetSequence::AllocatedSize(CDmeSheetSequence *this)
{
  return 120;
}

//------------------------------------------------------------------------------
// Address: 0x004BAC30
// Name: protected: virtual void CDmeSheetSequence::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSheetSequence::PerformConstruction(CDmeSheetSequence *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeSheetSequence::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x004BAD60
// Name: public: virtual bool CDmeSheetImage::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSheetImage::IsA(CDmeSheetImage *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSheetImage::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BAD90
// Name: public: virtual int CDmeSheetImage::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSheetImage::GetInheritanceDepth(CDmeSheetImage *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSheetImage::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004BADD0
// Name: protected: virtual void CDmeSheetImage::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSheetImage::PerformConstruction(CDmeSheetImage *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_XCoord.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "xcoord",
                                  type: AT_INT,
                                  pMemory: &this->m_XCoord);
  this->m_YCoord.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "ycoord",
                                  type: AT_INT,
                                  pMemory: &this->m_YCoord);
  this->m_mapSequences.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "mapsequences",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_mapSequences);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_mapSequences.m_pAttribute,
    typeSymbol: CDmeSheetSequence::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x006AC070
// Name: _dynamic_initializer_for__CDmeSheetImage::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSheetImage::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSheetImage::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSheetImage pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSheetImage::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC0D0
// Name: _dynamic_initializer_for__CDmeSheetSequenceFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSheetSequenceFrame::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSheetSequenceFrame::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSheetSequenceFrame pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSheetSequenceFrame::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC130
// Name: _dynamic_initializer_for__CDmeSheetSequence::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSheetSequence::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSheetSequence::s_Allocator,
    blockSize: 120,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSheetSequence pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSheetSequence::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B3920
// Name: _dynamic_atexit_destructor_for__CDmeSheetImage::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSheetImage::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSheetImage::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B3930
// Name: _dynamic_atexit_destructor_for__CDmeSheetSequenceFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSheetSequenceFrame::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSheetSequenceFrame::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B3940
// Name: _dynamic_atexit_destructor_for__CDmeSheetSequence::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSheetSequence::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSheetSequence::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AC0A0
// Name: _dynamic_initializer_for__g_CDmeSheetImage_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSheetImage_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSheetImage_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC0B0
// Name: _dynamic_initializer_for__g_CDmeSheetImage_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSheetImage_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSheetImage_Helper,
           classname: "DmeSheetImage",
           pFactory: &g_CDmeSheetImage_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006AC100
// Name: _dynamic_initializer_for__g_CDmeSheetSequenceFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSheetSequenceFrame_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSheetSequenceFrame_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC110
// Name: _dynamic_initializer_for__g_CDmeSheetSequenceFrame_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSheetSequenceFrame_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSheetSequenceFrame_Helper,
           classname: "DmeSheetSequenceFrame",
           pFactory: &g_CDmeSheetSequenceFrame_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006AC160
// Name: _dynamic_initializer_for__g_CDmeSheetSequence_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSheetSequence_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSheetSequence_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AC170
// Name: _dynamic_initializer_for__g_CDmeSheetSequence_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSheetSequence_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSheetSequence_Helper,
           classname: "DmeSheetSequence",
           pFactory: &g_CDmeSheetSequence_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006B3950
// Name: _dynamic_atexit_destructor_for__g_CDmeSheetSequenceFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSheetSequenceFrame_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSheetSequenceFrame_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B3960
// Name: _dynamic_atexit_destructor_for__g_CDmeSheetSequence_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSheetSequence_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSheetSequence_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B3970
// Name: _dynamic_atexit_destructor_for__g_CDmeSheetImage_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSheetImage_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSheetImage_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x0042D460
// Name: protected: void CDmeSheetImage::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSheetImage::OnConstruction(CDmeSheetImage *this)
{
  this->m_XCoord.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "xcoord",
                                  type: AT_INT,
                                  pMemory: &this->m_XCoord);
  this->m_YCoord.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "ycoord",
                                  type: AT_INT,
                                  pMemory: &this->m_YCoord);
  this->m_mapSequences.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "mapsequences",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_mapSequences);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_mapSequences.m_pAttribute,
    typeSymbol: CDmeSheetSequence::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0042D4C0
// Name: protected: void CDmeSheetSequence::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSheetSequence::OnConstruction(CDmeSheetSequence *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  bool value; // [esp+Bh] [ebp-5h] BYREF
  int v5; // [esp+Ch] [ebp-4h] BYREF

  this->m_nSequenceNumber.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "sequencenumber",
                                           type: AT_INT,
                                           pMemory: &this->m_nSequenceNumber);
  this->m_Clamp.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "clamp",
                                 type: AT_BOOL,
                                 pMemory: &this->m_Clamp);
  this->m_eMode.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "mode",
                                 type: AT_INT,
                                 pMemory: &this->m_eMode);
  this->m_Frames.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "frames",
                                  type: AT_FIRST_ARRAY_TYPE,
                                  pMemory: &this->m_Frames);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Frames.m_pAttribute, typeSymbol: CDmeSheetSequenceFrame::m_classType);
  m_pAttribute = this->m_Clamp.m_pAttribute;
  value = true;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
  v3 = this->m_eMode.m_pAttribute;
  v5 = 0;
  CDmAttribute::SetValue<int>(this: v3, value: &v5);
}

//------------------------------------------------------------------------------
// Address: 0x0042D620
// Name: public: virtual bool CDmeSheetSequenceFrame::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSheetSequenceFrame::IsA(CDmeSheetSequenceFrame *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSheetSequenceFrame::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042D650
// Name: public: virtual int CDmeSheetSequenceFrame::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSheetSequenceFrame::GetInheritanceDepth(CDmeSheetSequenceFrame *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSheetSequenceFrame::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042D680
// Name: protected: virtual int CDmeSheetSequenceFrame::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSheetSequenceFrame::AllocatedSize(CDmeSheetSequenceFrame *this)
{
  return 104;
}

//------------------------------------------------------------------------------
// Address: 0x0042D690
// Name: protected: virtual void CDmeSheetSequenceFrame::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSheetSequenceFrame::PerformConstruction(CDmeSheetSequenceFrame *this)
{
  CSteamApplication::PostShutdown((CFontManager *)this);
  this->m_pSheetImages.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "sheetimages",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_pSheetImages);
  CDmAttribute::SetElementTypeSymbol(this: this->m_pSheetImages.m_pAttribute, typeSymbol: CDmeSheetImage::m_classType);
  this->m_fDisplayTime.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "displaytime",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_fDisplayTime);
}

//------------------------------------------------------------------------------
// Address: 0x0042D720
// Name: public: virtual bool CDmeSheetSequence::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSheetSequence::IsA(CDmeSheetSequence *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSheetSequence::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042D750
// Name: public: virtual int CDmeSheetSequence::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSheetSequence::GetInheritanceDepth(CDmeSheetSequence *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSheetSequence::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042D780
// Name: protected: virtual int CDmeSheetSequence::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSheetSequence::AllocatedSize(CDmeSheetSequence *this)
{
  return 120;
}

//------------------------------------------------------------------------------
// Address: 0x0042D790
// Name: protected: virtual void CDmeSheetSequence::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSheetSequence::PerformConstruction(CDmeSheetSequence *this)
{
  CSteamApplication::PostShutdown((CFontManager *)this);
  CDmeSheetSequence::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0042D8A0
// Name: public: virtual bool CDmeSheetImage::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSheetImage::IsA(CDmeSheetImage *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSheetImage::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042D8D0
// Name: public: virtual int CDmeSheetImage::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSheetImage::GetInheritanceDepth(CDmeSheetImage *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSheetImage::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0042D900
// Name: protected: virtual int CDmeSheetImage::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSheetImage::AllocatedSize(CDmeSheetImage *this)
{
  return 116;
}

//------------------------------------------------------------------------------
// Address: 0x0042D910
// Name: protected: virtual void CDmeSheetImage::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSheetImage::PerformConstruction(CDmeSheetImage *this)
{
  CSteamApplication::PostShutdown((CFontManager *)this);
  CDmeSheetImage::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005337C0
// Name: _dynamic_initializer_for__CDmeSheetImage::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSheetImage::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSheetImage::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSheetImage pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSheetImage::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00533820
// Name: _dynamic_initializer_for__CDmeSheetSequenceFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSheetSequenceFrame::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSheetSequenceFrame::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSheetSequenceFrame pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSheetSequenceFrame::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00533880
// Name: _dynamic_initializer_for__CDmeSheetSequence::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSheetSequence::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSheetSequence::s_Allocator,
    blockSize: 120,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSheetSequence pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSheetSequence::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00535190
// Name: _dynamic_atexit_destructor_for__CDmeSheetImage::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSheetImage::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSheetImage::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005351A0
// Name: _dynamic_atexit_destructor_for__CDmeSheetSequenceFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSheetSequenceFrame::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSheetSequenceFrame::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005351B0
// Name: _dynamic_atexit_destructor_for__CDmeSheetSequence::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSheetSequence::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSheetSequence::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005337F0
// Name: _dynamic_initializer_for__g_CDmeSheetImage_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSheetImage_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSheetImage_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00533800
// Name: _dynamic_initializer_for__g_CDmeSheetImage_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSheetImage_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSheetImage_Helper,
           classname: "DmeSheetImage",
           pFactory: &g_CDmeSheetImage_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x00533850
// Name: _dynamic_initializer_for__g_CDmeSheetSequenceFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSheetSequenceFrame_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSheetSequenceFrame_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00533860
// Name: _dynamic_initializer_for__g_CDmeSheetSequenceFrame_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSheetSequenceFrame_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSheetSequenceFrame_Helper,
           classname: "DmeSheetSequenceFrame",
           pFactory: &g_CDmeSheetSequenceFrame_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x005338B0
// Name: _dynamic_initializer_for__g_CDmeSheetSequence_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSheetSequence_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSheetSequence_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005338C0
// Name: _dynamic_initializer_for__g_CDmeSheetSequence_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSheetSequence_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSheetSequence_Helper,
           classname: "DmeSheetSequence",
           pFactory: &g_CDmeSheetSequence_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x005351C0
// Name: _dynamic_atexit_destructor_for__g_CDmeSheetSequenceFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSheetSequenceFrame_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeSheetSequenceFrame_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005351D0
// Name: _dynamic_atexit_destructor_for__g_CDmeSheetSequence_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSheetSequence_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeSheetSequence_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005351E0
// Name: _dynamic_atexit_destructor_for__g_CDmeSheetImage_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSheetImage_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeSheetImage_Factory.m_CallBackList);
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00567310
// Name: protected: void CDmeSheetSequence::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSheetSequence::OnConstruction(CDmeSheetSequence *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  int v4; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  this->m_nSequenceNumber.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "sequencenumber",
                                           type: AT_INT,
                                           pMemory: &this->m_nSequenceNumber);
  this->m_Clamp.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "clamp",
                                 type: AT_BOOL,
                                 pMemory: &this->m_Clamp);
  this->m_eMode.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "mode",
                                 type: AT_INT,
                                 pMemory: &this->m_eMode);
  this->m_Frames.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "frames",
                                  type: AT_FIRST_ARRAY_TYPE,
                                  pMemory: &this->m_Frames);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Frames.m_pAttribute, typeSymbol: CDmeSheetSequenceFrame::m_classType);
  m_pAttribute = this->m_Clamp.m_pAttribute;
  value = true;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
  v3 = this->m_eMode.m_pAttribute;
  v4 = 0;
  CDmAttribute::SetValue<int>(this: v3, value: &v4);
}

//------------------------------------------------------------------------------
// Address: 0x005674D0
// Name: public: virtual bool CDmeSheetSequenceFrame::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSheetSequenceFrame::IsA(CDmeSheetSequenceFrame *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSheetSequenceFrame::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00567500
// Name: public: virtual int CDmeSheetSequenceFrame::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSheetSequenceFrame::GetInheritanceDepth(CDmeSheetSequenceFrame *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSheetSequenceFrame::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00567540
// Name: protected: virtual void CDmeSheetSequenceFrame::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSheetSequenceFrame::PerformConstruction(CDmeSheetSequenceFrame *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  this->m_pSheetImages.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "sheetimages",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_pSheetImages);
  CDmAttribute::SetElementTypeSymbol(this: this->m_pSheetImages.m_pAttribute, typeSymbol: CDmeSheetImage::m_classType);
  this->m_fDisplayTime.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "displaytime",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_fDisplayTime);
}

//------------------------------------------------------------------------------
// Address: 0x005675D0
// Name: public: virtual bool CDmeSheetSequence::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSheetSequence::IsA(CDmeSheetSequence *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSheetSequence::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00567600
// Name: public: virtual int CDmeSheetSequence::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSheetSequence::GetInheritanceDepth(CDmeSheetSequence *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSheetSequence::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00567640
// Name: protected: virtual int CDmeSheetSequence::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSheetSequence::AllocatedSize(CDmeSheetSequence *this)
{
  return 120;
}

//------------------------------------------------------------------------------
// Address: 0x00567650
// Name: protected: virtual void CDmeSheetSequence::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSheetSequence::PerformConstruction(CDmeSheetSequence *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeSheetSequence::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x00567780
// Name: public: virtual bool CDmeSheetImage::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSheetImage::IsA(CDmeSheetImage *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSheetImage::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005677B0
// Name: public: virtual int CDmeSheetImage::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSheetImage::GetInheritanceDepth(CDmeSheetImage *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSheetImage::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005677F0
// Name: protected: virtual void CDmeSheetImage::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSheetImage::PerformConstruction(CDmeSheetImage *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  this->m_XCoord.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "xcoord",
                                  type: AT_INT,
                                  pMemory: &this->m_XCoord);
  this->m_YCoord.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "ycoord",
                                  type: AT_INT,
                                  pMemory: &this->m_YCoord);
  this->m_mapSequences.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "mapsequences",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_mapSequences);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_mapSequences.m_pAttribute,
    typeSymbol: CDmeSheetSequence::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x006B6E40
// Name: _dynamic_initializer_for__CDmeSheetImage::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSheetImage::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSheetImage::s_Allocator,
    blockSize: 0x74u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSheetImage pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSheetImage::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B6EA0
// Name: _dynamic_initializer_for__CDmeSheetSequenceFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSheetSequenceFrame::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSheetSequenceFrame::s_Allocator,
    blockSize: 0x68u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSheetSequenceFrame pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSheetSequenceFrame::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B6F00
// Name: _dynamic_initializer_for__CDmeSheetSequence::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSheetSequence::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSheetSequence::s_Allocator,
    blockSize: 0x78u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSheetSequence pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSheetSequence::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BC410
// Name: _dynamic_atexit_destructor_for__CDmeSheetImage::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSheetImage::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSheetImage::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BC420
// Name: _dynamic_atexit_destructor_for__CDmeSheetSequenceFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSheetSequenceFrame::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSheetSequenceFrame::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BC430
// Name: _dynamic_atexit_destructor_for__CDmeSheetSequence::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSheetSequence::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSheetSequence::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B6E70
// Name: _dynamic_initializer_for__g_CDmeSheetImage_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSheetImage_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSheetImage_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B6E80
// Name: _dynamic_initializer_for__g_CDmeSheetImage_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSheetImage_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSheetImage_Helper,
           classname: "DmeSheetImage",
           pFactory: &g_CDmeSheetImage_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006B6ED0
// Name: _dynamic_initializer_for__g_CDmeSheetSequenceFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSheetSequenceFrame_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSheetSequenceFrame_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B6EE0
// Name: _dynamic_initializer_for__g_CDmeSheetSequenceFrame_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSheetSequenceFrame_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSheetSequenceFrame_Helper,
           classname: "DmeSheetSequenceFrame",
           pFactory: &g_CDmeSheetSequenceFrame_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006B6F30
// Name: _dynamic_initializer_for__g_CDmeSheetSequence_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSheetSequence_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSheetSequence_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B6F40
// Name: _dynamic_initializer_for__g_CDmeSheetSequence_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSheetSequence_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSheetSequence_Helper,
           classname: "DmeSheetSequence",
           pFactory: &g_CDmeSheetSequence_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x006BC440
// Name: _dynamic_atexit_destructor_for__g_CDmeSheetSequenceFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSheetSequenceFrame_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeSheetSequenceFrame_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BC450
// Name: _dynamic_atexit_destructor_for__g_CDmeSheetSequence_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSheetSequence_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeSheetSequence_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BC460
// Name: _dynamic_atexit_destructor_for__g_CDmeSheetImage_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSheetImage_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeSheetImage_Factory.m_CallBackList);
}

} // namespace vmap

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x10092250
// Name: protected: void CDmeSheetSequence::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSheetSequence::OnConstruction(CDmeSheetSequence *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  int v4; // [esp+8h] [ebp-8h] BYREF
  bool value; // [esp+Fh] [ebp-1h] BYREF

  this->m_nSequenceNumber.m_pAttribute = CDmElement::AddExternalAttribute(
                                           this,
                                           pAttributeName: "sequencenumber",
                                           type: AT_INT,
                                           pMemory: &this->m_nSequenceNumber);
  this->m_Clamp.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "clamp",
                                 type: AT_BOOL,
                                 pMemory: &this->m_Clamp);
  this->m_eMode.m_pAttribute = CDmElement::AddExternalAttribute(
                                 this,
                                 pAttributeName: "mode",
                                 type: AT_INT,
                                 pMemory: &this->m_eMode);
  this->m_Frames.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "frames",
                                  type: AT_FIRST_ARRAY_TYPE,
                                  pMemory: &this->m_Frames);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Frames.m_pAttribute, typeSymbol: CDmeSheetSequenceFrame::m_classType);
  m_pAttribute = this->m_Clamp.m_pAttribute;
  value = true;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
  v3 = this->m_eMode.m_pAttribute;
  v4 = 0;
  CDmAttribute::SetValue<int>(this: v3, value: &v4);
}

//------------------------------------------------------------------------------
// Address: 0x10092410
// Name: public: virtual bool CDmeSheetSequenceFrame::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSheetSequenceFrame::IsA(CDmeSheetSequenceFrame *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSheetSequenceFrame::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10092440
// Name: public: virtual int CDmeSheetSequenceFrame::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSheetSequenceFrame::GetInheritanceDepth(CDmeSheetSequenceFrame *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSheetSequenceFrame::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10092480
// Name: protected: virtual int CDmeSheetSequenceFrame::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSheetSequenceFrame::AllocatedSize(CDmeSheetSequenceFrame *this)
{
  return 104;
}

//------------------------------------------------------------------------------
// Address: 0x10092490
// Name: protected: virtual void CDmeSheetSequenceFrame::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSheetSequenceFrame::PerformConstruction(CDmeSheetSequenceFrame *this)
{
  CDmElementFramework::Disconnect((CDmeTexture *)this);
  this->m_pSheetImages.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "sheetimages",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_pSheetImages);
  CDmAttribute::SetElementTypeSymbol(this: this->m_pSheetImages.m_pAttribute, typeSymbol: CDmeSheetImage::m_classType);
  this->m_fDisplayTime.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "displaytime",
                                        type: AT_FLOAT,
                                        pMemory: &this->m_fDisplayTime);
}

//------------------------------------------------------------------------------
// Address: 0x10092530
// Name: public: virtual bool CDmeSheetSequence::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSheetSequence::IsA(CDmeSheetSequence *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSheetSequence::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10092560
// Name: public: virtual int CDmeSheetSequence::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSheetSequence::GetInheritanceDepth(CDmeSheetSequence *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSheetSequence::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100925B0
// Name: protected: virtual int CDmeSheetSequence::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSheetSequence::AllocatedSize(CDmeSheetSequence *this)
{
  return 120;
}

//------------------------------------------------------------------------------
// Address: 0x100925C0
// Name: protected: virtual void CDmeSheetSequence::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSheetSequence::PerformConstruction(CDmeSheetSequence *this)
{
  CDmElementFramework::Disconnect((CDmeTexture *)this);
  CDmeSheetSequence::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x100926F0
// Name: public: virtual bool CDmeSheetImage::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSheetImage::IsA(CDmeSheetImage *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSheetImage::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10092720
// Name: public: virtual int CDmeSheetImage::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSheetImage::GetInheritanceDepth(CDmeSheetImage *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSheetImage::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10092760
// Name: protected: virtual int CDmeSheetImage::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSheetImage::AllocatedSize(CDmeSheetImage *this)
{
  return 116;
}

//------------------------------------------------------------------------------
// Address: 0x10092770
// Name: protected: virtual void CDmeSheetImage::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSheetImage::PerformConstruction(CDmeSheetImage *this)
{
  CDmElementFramework::Disconnect((CDmeTexture *)this);
  this->m_XCoord.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "xcoord",
                                  type: AT_INT,
                                  pMemory: &this->m_XCoord);
  this->m_YCoord.m_pAttribute = CDmElement::AddExternalAttribute(
                                  this,
                                  pAttributeName: "ycoord",
                                  type: AT_INT,
                                  pMemory: &this->m_YCoord);
  this->m_mapSequences.m_pAttribute = CDmElement::AddExternalAttribute(
                                        this,
                                        pAttributeName: "mapsequences",
                                        type: AT_FIRST_ARRAY_TYPE,
                                        pMemory: &this->m_mapSequences);
  CDmAttribute::SetElementTypeSymbol(
    this: this->m_mapSequences.m_pAttribute,
    typeSymbol: CDmeSheetSequence::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x100C4980
// Name: _dynamic_initializer_for__CDmeSheetImage::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSheetImage::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSheetImage::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSheetImage pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSheetImage::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x100C49E0
// Name: _dynamic_initializer_for__CDmeSheetSequenceFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSheetSequenceFrame::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSheetSequenceFrame::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSheetSequenceFrame pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSheetSequenceFrame::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4A40
// Name: _dynamic_initializer_for__CDmeSheetSequence::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSheetSequence::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSheetSequence::s_Allocator,
    blockSize: 120,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSheetSequence pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSheetSequence::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x100C5290
// Name: _dynamic_atexit_destructor_for__CDmeSheetImage::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSheetImage::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSheetImage::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x100C52A0
// Name: _dynamic_atexit_destructor_for__CDmeSheetSequenceFrame::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSheetSequenceFrame::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSheetSequenceFrame::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x100C52B0
// Name: _dynamic_atexit_destructor_for__CDmeSheetSequence::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSheetSequence::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSheetSequence::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x100C49B0
// Name: _dynamic_initializer_for__g_CDmeSheetImage_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSheetImage_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSheetImage_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x100C49C0
// Name: _dynamic_initializer_for__g_CDmeSheetImage_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSheetImage_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSheetImage_Helper,
           classname: "DmeSheetImage",
           pFactory: &g_CDmeSheetImage_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x100C4A10
// Name: _dynamic_initializer_for__g_CDmeSheetSequenceFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSheetSequenceFrame_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSheetSequenceFrame_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4A20
// Name: _dynamic_initializer_for__g_CDmeSheetSequenceFrame_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSheetSequenceFrame_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSheetSequenceFrame_Helper,
           classname: "DmeSheetSequenceFrame",
           pFactory: &g_CDmeSheetSequenceFrame_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x100C4A70
// Name: _dynamic_initializer_for__g_CDmeSheetSequence_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSheetSequence_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSheetSequence_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x100C4A80
// Name: _dynamic_initializer_for__g_CDmeSheetSequence_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSheetSequence_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSheetSequence_Helper,
           classname: "DmeSheetSequence",
           pFactory: &g_CDmeSheetSequence_Factory,
           bIsStandardFactory: false);
}

//------------------------------------------------------------------------------
// Address: 0x100C52C0
// Name: _dynamic_atexit_destructor_for__g_CDmeSheetSequenceFrame_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSheetSequenceFrame_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeSheetSequenceFrame_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x100C52D0
// Name: _dynamic_atexit_destructor_for__g_CDmeSheetSequence_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSheetSequence_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeSheetSequence_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x100C52E0
// Name: _dynamic_atexit_destructor_for__g_CDmeSheetImage_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSheetImage_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeSheetImage_Factory.m_CallBackList);
}

} // namespace vtex_dll
