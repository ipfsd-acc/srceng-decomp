// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: resourcesystem/resourceintrospectiondictionary.cpp
// Functions: 19
// ============================================================

#include "resourcesystem\resourceintrospectiondictionary.h"

//------------------------------------------------------------------------------
// Address: 0x100012B0
// Name: protected: virtual bool CRefCountServiceBase<1,class CRefMT>::OnFinalRelease(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRefCountServiceBase<1,CRefMT>::OnFinalRelease(ConCommandBase *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001300
// Name: public: virtual void CMemberFunctor1<class CResourceIntrospectionDictionary __near *,void (CResourceIntrospectionDictionary::*)(class IAsyncFileRequest __near *),class IAsyncFileRequest __near *,class CRefCounted1<class CFunctor,class CRefCountServiceBase<1,class CRefMT>>,class CFuncMemPolicyNone>::operator()(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemberFunctor1<CResourceIntrospectionDictionary *,void (__thiscall CResourceIntrospectionDictionary::*)(IAsyncFileRequest *),IAsyncFileRequest *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::operator()(
        CMemberFunctor1<CResourceIntrospectionDictionary *,void (__thiscall CResourceIntrospectionDictionary::*)(IAsyncFileRequest *),IAsyncFileRequest *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT> >,CFuncMemPolicyNone> *this)
{
  this->m_Proxy.m_pfnProxied(this: this->m_Proxy.m_pObject, a2: this->m_arg1);
}

//------------------------------------------------------------------------------
// Address: 0x10003550
// Name: public: void CResourceIntrospectionDictionary::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceIntrospectionDictionary::Shutdown(CResourceIntrospectionDictionary *this)
{
  int i; // edi
  bool v3; // sf
  void **m_pMemory; // ecx

  for ( i = 0; i < this->m_pIntrospectionBuffers.m_Size; ++i )
  {
    if ( this->m_pIntrospectionBuffers.m_Memory.m_pMemory[i] != nullptr )
      g_pAsyncFileSystem->ReleaseBuffer(
        this: g_pAsyncFileSystem,
        a2: this->m_pIntrospectionBuffers.m_Memory.m_pMemory[i]);
  }
  v3 = this->m_pIntrospectionBuffers.m_Memory.m_nGrowSize < 0;
  this->m_pIntrospectionBuffers.m_Size = 0;
  if ( v3 )
  {
    this->m_pIntrospectionBuffers.m_pElements = this->m_pIntrospectionBuffers.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_pIntrospectionBuffers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pIntrospectionBuffers.m_Memory.m_pMemory);
      this->m_pIntrospectionBuffers.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_pIntrospectionBuffers.m_Memory.m_pMemory;
    this->m_pIntrospectionBuffers.m_Memory.m_nAllocationCount = 0;
    this->m_pIntrospectionBuffers.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100035D0
// Name: public: class CResourceStructIntrospection const __near * CResourceIntrospectionDictionary::FindStructIntrospection(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
const CResourceStructIntrospection *__thiscall CResourceIntrospectionDictionary::FindStructIntrospection(
        CResourceIntrospectionDictionary *this,
        unsigned int id)
{
  unsigned __int16 v3; // ax
  CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  search.key = id;
  v3 = CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_StructMap.m_Tree,
         &search);
  if ( v3 == 0xFFFF )
    return nullptr;
  else
    return this->m_StructMap.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x10003620
// Name: public: class CResourceStructIntrospection const __near * CResourceIntrospectionDictionary::FindStructIntrospection(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CResourceStructIntrospection *__thiscall CResourceIntrospectionDictionary::FindStructIntrospection(
        CResourceIntrospectionDictionary *this,
        const char *pStructName)
{
  unsigned __int16 v3; // ax
  CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  search.key = ComputeStructureNameHash(pStructName);
  v3 = CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_StructMap.m_Tree,
         &search);
  if ( v3 == 0xFFFF )
    return nullptr;
  else
    return this->m_StructMap.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x10003670
// Name: public: class CResourceStructIntrospection const __near * CResourceIntrospectionDictionary::FindStructIntrospectionByDmElement(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CResourceStructIntrospection *__thiscall CResourceIntrospectionDictionary::FindStructIntrospectionByDmElement(
        CResourceIntrospectionDictionary *this,
        const char *pDmeElement)
{
  CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short> *p_m_StructMap; // ebp
  unsigned __int16 Inorder; // si
  const CResourceStructIntrospection *elem; // eax

  p_m_StructMap = &this->m_StructMap;
  Inorder = CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_StructMap.m_Tree);
  if ( Inorder == 0xFFFF )
    return nullptr;
  while ( 1 )
  {
    elem = this->m_StructMap.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
    if ( _V_stricmp(s1: (const char *)&elem->m_pDmeElementType + elem->m_pDmeElementType.m_nOffset, s2: pDmeElement) == 0 )
      break;
    Inorder = CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                this: &p_m_StructMap->m_Tree,
                i: Inorder);
    if ( Inorder == 0xFFFF )
      return nullptr;
  }
  return this->m_StructMap.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x100036F0
// Name: public: class CResourceStructIntrospection const __near * CResourceIntrospectionDictionary::FindStructIntrospectionByBlockType(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
const CResourceStructIntrospection *__thiscall CResourceIntrospectionDictionary::FindStructIntrospectionByBlockType(
        CResourceIntrospectionDictionary *this,
        unsigned int nBlockType)
{
  CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short> *p_m_StructMap; // edi
  unsigned __int16 Inorder; // ax

  p_m_StructMap = &this->m_StructMap;
  Inorder = CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_StructMap.m_Tree);
  if ( Inorder == 0xFFFF )
    return nullptr;
  while ( *(_DWORD *)this->m_StructMap.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem->m_ResourceBlockType != nBlockType )
  {
    Inorder = CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                this: &p_m_StructMap->m_Tree,
                i: Inorder);
    if ( Inorder == 0xFFFF )
      return nullptr;
  }
  return this->m_StructMap.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x10003750
// Name: public: class CResourceEnumIntrospection const __near * CResourceIntrospectionDictionary::FindEnumIntrospection(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
const CResourceEnumIntrospection *__thiscall CResourceIntrospectionDictionary::FindEnumIntrospection(
        CResourceIntrospectionDictionary *this,
        unsigned int id)
{
  unsigned __int16 v3; // ax
  CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  search.key = id;
  v3 = CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_EnumMap.m_Tree,
         &search);
  if ( v3 == 0xFFFF )
    return nullptr;
  else
    return this->m_EnumMap.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x100037A0
// Name: public: class CResourceEnumIntrospection const __near * CResourceIntrospectionDictionary::FindEnumIntrospection(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CResourceEnumIntrospection *__thiscall CResourceIntrospectionDictionary::FindEnumIntrospection(
        CResourceIntrospectionDictionary *this,
        const char *pEnumName)
{
  unsigned __int16 v3; // ax
  CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  search.key = ComputeStructureNameHash(pStructName: pEnumName);
  v3 = CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_EnumMap.m_Tree,
         &search);
  if ( v3 == 0xFFFF )
    return nullptr;
  else
    return this->m_EnumMap.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x100037F0
// Name: public: class CResourceTypedefIntrospection const __near * CResourceIntrospectionDictionary::FindTypedefIntrospection(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
const CResourceTypedefIntrospection *__thiscall CResourceIntrospectionDictionary::FindTypedefIntrospection(
        CResourceIntrospectionDictionary *this,
        unsigned int id)
{
  unsigned __int16 v3; // ax
  CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  search.key = id;
  v3 = CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_TypedefMap.m_Tree,
         &search);
  if ( v3 == 0xFFFF )
    return nullptr;
  else
    return this->m_TypedefMap.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x10003840
// Name: public: class CResourceTypedefIntrospection const __near * CResourceIntrospectionDictionary::FindTypedefIntrospection(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const CResourceTypedefIntrospection *__thiscall CResourceIntrospectionDictionary::FindTypedefIntrospection(
        CResourceIntrospectionDictionary *this,
        const char *pTypedefName)
{
  unsigned __int16 v3; // ax
  CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  search.key = ComputeStructureNameHash(pStructName: pTypedefName);
  v3 = CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_TypedefMap.m_Tree,
         &search);
  if ( v3 == 0xFFFF )
    return nullptr;
  else
    return this->m_TypedefMap.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x10003890
// Name: public: bool CResourceIntrospectionDictionary::FindEnumeratedValue(void __near *,char const __near *,char const __near *,int)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CResourceIntrospectionDictionary::FindEnumeratedValue(
        CResourceIntrospectionDictionary *this,
        _DWORD *pValue,
        const char *pEnumName,
        const char *pEnumValueName,
        int nDefaultValue)
{
  unsigned __int16 v6; // ax
  CResourceEnumIntrospection *elem; // edi
  int v8; // esi
  CResourceEnumValueIntrospection *EnumValue; // ebx
  const char *Name; // eax
  CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t search; // [esp+10h] [ebp-8h] BYREF

  search.key = ComputeStructureNameHash(pStructName: pEnumName);
  v6 = CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_EnumMap.m_Tree,
         &search);
  if ( v6 == 0xFFFF )
    elem = nullptr;
  else
    elem = this->m_EnumMap.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem;
  v8 = 0;
  if ( CResourceIntrospection::GetEnumCount(this: elem) <= 0 )
  {
LABEL_7:
    *pValue = nDefaultValue;
    return 0;
  }
  else
  {
    while ( 1 )
    {
      EnumValue = (CResourceEnumValueIntrospection *)CResourceEnumIntrospection::GetEnumValue(this: elem, nIndex: v8);
      Name = CResourceEnumValueIntrospection::GetName(this: EnumValue);
      if ( _V_strcmp(s1: pEnumValueName, s2: Name) == 0 )
        break;
      if ( ++v8 >= CResourceIntrospection::GetEnumCount(this: elem) )
        goto LABEL_7;
    }
    *pValue = CResourceTypeManagerBase::GetResourceType(this: EnumValue);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003940
// Name: public: char const __near * CResourceIntrospectionDictionary::FindEnumerationName(char const __near *,int,char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CResourceIntrospectionDictionary::FindEnumerationName(
        CResourceIntrospectionDictionary *this,
        const char *pEnumName,
        int nValue,
        const char *pDefaultName)
{
  unsigned __int16 v5; // ax
  CResourceEnumIntrospection *elem; // edi
  int v7; // esi
  CResourceEnumValueIntrospection *EnumValue; // ebx
  CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t search; // [esp+10h] [ebp-8h] BYREF

  search.key = ComputeStructureNameHash(pStructName: pEnumName);
  v5 = CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_EnumMap.m_Tree,
         &search);
  if ( v5 == 0xFFFF )
    elem = nullptr;
  else
    elem = this->m_EnumMap.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
  v7 = 0;
  if ( CResourceIntrospection::GetEnumCount(this: elem) <= 0 )
    return pDefaultName;
  while ( 1 )
  {
    EnumValue = (CResourceEnumValueIntrospection *)CResourceEnumIntrospection::GetEnumValue(this: elem, nIndex: v7);
    if ( CResourceTypeManagerBase::GetResourceType(this: EnumValue) == nValue )
      break;
    if ( ++v7 >= CResourceIntrospection::GetEnumCount(this: elem) )
      return pDefaultName;
  }
  return CResourceEnumValueIntrospection::GetName(this: EnumValue);
}

//------------------------------------------------------------------------------
// Address: 0x10003B00
// Name: public: CResourceIntrospectionDictionary::~CResourceIntrospectionDictionary(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CResourceIntrospectionDictionary::~CResourceIntrospectionDictionary(
        CResourceIntrospectionDictionary *this)
{
  CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_TypedefMap.m_Tree);
  CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_EnumMap.m_Tree);
  CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &this->m_StructMap.m_Tree);
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>((CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)this);
}

//------------------------------------------------------------------------------
// Address: 0x10003B30
// Name: public: class CResourceStructIntrospection const __near * CResourceIntrospectionDictionary::FindStructIntrospectionForResourceType(int)const
// Source: json
//------------------------------------------------------------------------------
const CResourceStructIntrospection *__thiscall CResourceIntrospectionDictionary::FindStructIntrospectionForResourceType(
        CResourceIntrospectionDictionary *this,
        int nType)
{
  unsigned __int16 v3; // ax
  CResourceEnumIntrospection *elem; // ecx
  const char *EnumString; // ebx
  unsigned __int16 Inorder; // si
  const CResourceStructIntrospection *v7; // eax
  CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t search; // [esp+10h] [ebp-8h] BYREF

  search.key = ComputeStructureNameHash(pStructName: "ResourceTypeEngine_t");
  v3 = CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_EnumMap.m_Tree,
         &search);
  if ( v3 == 0xFFFF )
    elem = nullptr;
  else
    elem = this->m_EnumMap.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
  EnumString = CResourceEnumIntrospection::FindEnumString(this: elem, nValue: nType);
  Inorder = CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_StructMap.m_Tree);
  if ( Inorder == 0xFFFF )
    return nullptr;
  while ( 1 )
  {
    v7 = this->m_StructMap.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
    if ( _V_stricmp(s1: (const char *)&v7->m_pResourceType + v7->m_pResourceType.m_nOffset, s2: EnumString) == 0 )
      break;
    Inorder = CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                this: &this->m_StructMap.m_Tree,
                i: Inorder);
    if ( Inorder == 0xFFFF )
      return nullptr;
  }
  return this->m_StructMap.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x10003BF0
// Name: public: class CResourceStructIntrospection const __near * CResourceIntrospectionDictionary::FindPermanentStructIntrospectionForResourceType(int)const
// Source: json
//------------------------------------------------------------------------------
const CResourceStructIntrospection *__thiscall CResourceIntrospectionDictionary::FindPermanentStructIntrospectionForResourceType(
        CResourceIntrospectionDictionary *this,
        int nType)
{
  unsigned __int16 v3; // ax
  CResourceEnumIntrospection *elem; // ecx
  const char *EnumString; // ebp
  unsigned __int16 Inorder; // si
  const CResourceStructIntrospection *v7; // eax
  unsigned __int16 v9; // ax
  CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t search; // [esp+10h] [ebp-8h] BYREF

  search.key = ComputeStructureNameHash(pStructName: "ResourceTypeEngine_t");
  v3 = CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_EnumMap.m_Tree,
         &search);
  if ( v3 == 0xFFFF )
    elem = nullptr;
  else
    elem = this->m_EnumMap.m_Tree.m_Elements.m_pMemory[v3].m_Data.elem;
  EnumString = CResourceEnumIntrospection::FindEnumString(this: elem, nValue: nType);
  Inorder = CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_StructMap.m_Tree);
  if ( Inorder == 0xFFFF )
    return nullptr;
  while ( 1 )
  {
    v7 = this->m_StructMap.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
    if ( _V_stricmp(s1: (const char *)&v7->m_pResourceType + v7->m_pResourceType.m_nOffset, s2: EnumString) == 0 )
      break;
    Inorder = CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                this: &this->m_StructMap.m_Tree,
                i: Inorder);
    if ( Inorder == 0xFFFF )
      return nullptr;
  }
  search.key = this->m_StructMap.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem->m_nUncacheableStructId;
  v9 = CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_StructMap.m_Tree,
         (const CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t *)&search);
  if ( v9 == 0xFFFF )
    return nullptr;
  else
    return this->m_StructMap.m_Tree.m_Elements.m_pMemory[v9].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x10003CE0
// Name: public: CResourceIntrospectionDictionary::CResourceIntrospectionDictionary(void)
// Source: json
//------------------------------------------------------------------------------
CResourceIntrospectionDictionary *__thiscall CResourceIntrospectionDictionary::CResourceIntrospectionDictionary(
        CResourceIntrospectionDictionary *this)
{
  this->m_pIntrospectionBuffers.m_Memory.m_pMemory = nullptr;
  this->m_pIntrospectionBuffers.m_Memory.m_nAllocationCount = 0;
  this->m_pIntrospectionBuffers.m_Memory.m_nGrowSize = 0;
  this->m_pIntrospectionBuffers.m_Size = 0;
  this->m_pIntrospectionBuffers.m_pElements = nullptr;
  this->m_StructMap.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_StructMap.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_StructMap.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_StructMap.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_StructMap.m_Tree.m_NumElements = 0;
  this->m_StructMap.m_Tree.m_Root = -1;
  this->m_StructMap.m_Tree.m_FirstFree = -1;
  this->m_StructMap.m_Tree.m_LastAlloc.index = -1;
  this->m_StructMap.m_Tree.m_pElements = this->m_StructMap.m_Tree.m_Elements.m_pMemory;
  this->m_EnumMap.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_EnumMap.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_EnumMap.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_EnumMap.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_EnumMap.m_Tree.m_Root = -1;
  this->m_EnumMap.m_Tree.m_NumElements = 0;
  this->m_EnumMap.m_Tree.m_FirstFree = -1;
  this->m_EnumMap.m_Tree.m_LastAlloc.index = -1;
  this->m_EnumMap.m_Tree.m_pElements = this->m_EnumMap.m_Tree.m_Elements.m_pMemory;
  this->m_TypedefMap.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_TypedefMap.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_TypedefMap.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_TypedefMap.m_Tree.m_Elements.m_nGrowSize = 0;
  *(_DWORD *)&this->m_TypedefMap.m_Tree.m_Root = 0xFFFF;
  this->m_TypedefMap.m_Tree.m_FirstFree = -1;
  this->m_TypedefMap.m_Tree.m_LastAlloc.index = -1;
  this->m_TypedefMap.m_Tree.m_pElements = this->m_TypedefMap.m_Tree.m_Elements.m_pMemory;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10003D60
// Name: private: void CResourceIntrospectionDictionary::OnIntrospectionDictLoaded(class IAsyncFileRequest __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CResourceIntrospectionDictionary::OnIntrospectionDictLoaded(
        CResourceIntrospectionDictionary *this@<ecx>,
        int a2@<ebp>,
        IAsyncFileRequest *pRequest,
        const IAsyncRequestBase *a4)
{
  AsyncRequestStatus_t (__thiscall *GetRequestStatus)(struct IAsyncFileRequest *); // edx
  CUtlMemory<KeyValues *,int> *v5; // edi
  const char *v6; // eax
  CResourceIntrospection *v7; // ebx
  unsigned int Version; // eax
  IAsyncFileRequest_vtbl *v9; // edx
  const char *v10; // eax
  int v11; // ebp
  CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *p_m_nGrowSize; // esi
  unsigned __int16 v13; // ax
  unsigned __int16 v14; // dx
  unsigned __int16 v15; // cx
  int v16; // edi
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *v17; // eax
  bool v18; // zf
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  int v20; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *v21; // ecx
  int v22; // ebp
  CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *v23; // esi
  unsigned __int16 v24; // ax
  unsigned __int16 v25; // dx
  unsigned __int16 v26; // cx
  int v27; // edi
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *v28; // eax
  int v29; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *v30; // edx
  int v31; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short> *v32; // eax
  CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t *p_m_Data; // eax
  int v34; // ebp
  CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *p_m_nAllocationCount; // esi
  unsigned __int16 v36; // ax
  unsigned __int16 v37; // dx
  unsigned __int16 v38; // cx
  int v39; // edi
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *v40; // eax
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *v41; // eax
  int v42; // edx
  UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *v43; // ecx
  KeyValues **v44; // esi
  int m_nAllocationCount; // eax
  KeyValues **v46; // ecx
  int v47; // eax
  KeyValues **v48; // esi
  int nCount; // [esp+Ch] [ebp-18h] BYREF
  unsigned __int16 parent[2]; // [esp+10h] [ebp-14h] BYREF
  void *pResultBuffer; // [esp+14h] [ebp-10h]
  const ResourceFileHeader_t *v52; // [esp+18h] [ebp-Ch]
  KeyValues *v53; // [esp+1Ch] [ebp-8h]
  unsigned int m_nId; // [esp+20h] [ebp-4h] BYREF
  const CResourceStructIntrospection *StructIntrospection; // [esp+24h] [ebp+0h]

  GetRequestStatus = pRequest->GetRequestStatus;
  v5 = (CUtlMemory<KeyValues *,int> *)this;
  pResultBuffer = this;
  if ( GetRequestStatus(this: pRequest) != ASYNC_REQUEST_OK )
  {
    v6 = pRequest->GetFileName(this: pRequest);
    _Error(a1: "Error loading introspection dictionary %s", v6);
    _InterlockedExchangeAdd((volatile signed __int32 *)(v5[8].m_nGrowSize + 6436), 0xFFFFFFFF);
  }
  else
  {
    v52 = (const ResourceFileHeader_t *)pRequest->GetResultBuffer(this: pRequest);
    v7 = CResourceIntrospection::FindInFile(pHeader: v52);
    Version = CResourceIntrospection::GetVersion(this: v7);
    v9 = pRequest->__vftable;
    if ( Version == 2 )
    {
      ((void (__thiscall *)(IAsyncFileRequest *, int))v9->KeepResultBuffer)(a1: pRequest, a2);
      v11 = 0;
      pResultBuffer = (void *)CResourceIntrospection::GetStructCount(this: v7);
      if ( (int)pResultBuffer > 0 )
      {
        p_m_nGrowSize = (CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&v5[1].m_nGrowSize;
        do
        {
          StructIntrospection = CResourceIntrospection::GetStructIntrospection(this: v7, nIndex: v11);
          m_nId = StructIntrospection->m_nId;
          CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
            this: p_m_nGrowSize,
            insert: (const CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t *)&m_nId,
            parent,
            leftchild: (bool *)&nCount + 3);
          v13 = CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)p_m_nGrowSize);
          v14 = parent[0];
          v15 = v13;
          v16 = v13;
          v17 = &p_m_nGrowSize->m_Elements.m_pMemory[v16];
          v18 = parent[0] == 0xFFFF;
          v17->m_Parent = parent[0];
          v17->m_Right = -1;
          v17->m_Left = -1;
          v17->m_Tag = 0;
          if ( v18 )
          {
            p_m_nGrowSize->m_Root = v15;
          }
          else
          {
            m_pMemory = p_m_nGrowSize->m_Elements.m_pMemory;
            v20 = v14;
            if ( HIBYTE(nCount) != 0 )
              m_pMemory[v20].m_Left = v15;
            else
              m_pMemory[v20].m_Right = v15;
          }
          CUtlRBTree<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
            this: p_m_nGrowSize,
            elem: v15);
          v21 = p_m_nGrowSize->m_Elements.m_pMemory;
          ++p_m_nGrowSize->m_NumElements;
          if ( &v21[v16] != (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceStructIntrospection const *,unsigned short>::Node_t,unsigned short> *)-8 )
          {
            v21[v16].m_Data.key = m_nId;
            v21[v16].m_Data.elem = StructIntrospection;
          }
          ++v11;
        }
        while ( v11 < (int)pResultBuffer );
        v5 = (CUtlMemory<KeyValues *,int> *)v52;
      }
      v22 = 0;
      pResultBuffer = (void *)CResourceIntrospection::GetEnumCount(this: (CResourceEnumIntrospection *)v7);
      if ( (int)pResultBuffer > 0 )
      {
        v23 = (CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&v5[4];
        do
        {
          StructIntrospection = (const CResourceStructIntrospection *)CResourceIntrospection::GetEnumIntrospection(
                                                                        this: v7,
                                                                        nIndex: v22);
          m_nId = StructIntrospection->m_nId;
          CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
            this: v23,
            insert: (const CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t *)&m_nId,
            parent,
            leftchild: (bool *)&nCount + 3);
          v24 = CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)v23);
          v25 = parent[0];
          v26 = v24;
          v27 = v24;
          v28 = &v23->m_Elements.m_pMemory[v27];
          v18 = parent[0] == 0xFFFF;
          v28->m_Parent = parent[0];
          v28->m_Right = -1;
          v28->m_Left = -1;
          v28->m_Tag = 0;
          if ( v18 )
          {
            v23->m_Root = v26;
          }
          else
          {
            v29 = v25;
            v30 = v23->m_Elements.m_pMemory;
            v31 = v29;
            if ( HIBYTE(nCount) != 0 )
              v30[v31].m_Left = v26;
            else
              v30[v31].m_Right = v26;
          }
          CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
            this: v23,
            elem: v26);
          v32 = v23->m_Elements.m_pMemory;
          ++v23->m_NumElements;
          p_m_Data = &v32[v27].m_Data;
          if ( p_m_Data != nullptr )
          {
            p_m_Data->key = m_nId;
            p_m_Data->elem = (const CResourceEnumIntrospection *)StructIntrospection;
          }
          ++v22;
        }
        while ( v22 < (int)pResultBuffer );
        v5 = (CUtlMemory<KeyValues *,int> *)v52;
      }
      v34 = 0;
      pResultBuffer = (void *)CResourceIntrospection::GetTypedefCount(this: v7);
      if ( (int)pResultBuffer > 0 )
      {
        p_m_nAllocationCount = (CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)&v5[6].m_nAllocationCount;
        do
        {
          StructIntrospection = (const CResourceStructIntrospection *)CResourceIntrospection::GetTypedefIntrospection(
                                                                        this: v7,
                                                                        nIndex: v34);
          m_nId = StructIntrospection->m_nId;
          CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
            this: p_m_nAllocationCount,
            insert: (const CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t *)&m_nId,
            parent,
            leftchild: (bool *)&nCount + 3);
          v36 = CUtlRBTree<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceEnumIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: p_m_nAllocationCount);
          v37 = parent[0];
          v38 = v36;
          v39 = v36;
          v40 = &p_m_nAllocationCount->m_Elements.m_pMemory[v39];
          v18 = parent[0] == 0xFFFF;
          v40->m_Parent = parent[0];
          v40->m_Right = -1;
          v40->m_Left = -1;
          v40->m_Tag = 0;
          if ( v18 )
          {
            p_m_nAllocationCount->m_Root = v38;
          }
          else
          {
            v41 = p_m_nAllocationCount->m_Elements.m_pMemory;
            v42 = v37;
            if ( HIBYTE(nCount) != 0 )
              v41[v42].m_Left = v38;
            else
              v41[v42].m_Right = v38;
          }
          CUtlRBTree<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short,CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
            this: p_m_nAllocationCount,
            elem: v38);
          v43 = p_m_nAllocationCount->m_Elements.m_pMemory;
          ++p_m_nAllocationCount->m_NumElements;
          if ( &v43[v39] != (UtlRBTreeNode_t<CUtlMap<unsigned int,CResourceTypedefIntrospection const *,unsigned short>::Node_t,unsigned short> *)-8 )
          {
            v43[v39].m_Data.key = m_nId;
            v43[v39].m_Data.elem = (const CResourceTypedefIntrospection *)StructIntrospection;
          }
          ++v34;
        }
        while ( v34 < (int)pResultBuffer );
        v5 = (CUtlMemory<KeyValues *,int> *)v52;
      }
      v44 = v5[1].m_pMemory;
      m_nAllocationCount = v5->m_nAllocationCount;
      if ( (int)v44 + 1 > m_nAllocationCount )
        CUtlMemory<unsigned int,int>::Grow(this: v5, num: (int)v44 - m_nAllocationCount + 1);
      ++v5[1].m_pMemory;
      v46 = v5->m_pMemory;
      v47 = (char *)v5[1].m_pMemory - (char *)v44 - 1;
      v18 = (char *)v5[1].m_pMemory - (char *)v44 == 1;
      v5[1].m_nAllocationCount = (int)v5->m_pMemory;
      if ( v47 >= 0 && !v18 )
        _V_memmove(dest: &v46[(_DWORD)v44 + 1], src: &v46[(_DWORD)v44], count: 4 * v47);
      v48 = &v5->m_pMemory[(_DWORD)v44];
      if ( v48 != nullptr )
        *v48 = v53;
      g_pAsyncFileSystem->ReleaseAsyncRequest(this: g_pAsyncFileSystem, a2: a4);
      _InterlockedExchangeAdd((volatile signed __int32 *)(v5[8].m_nGrowSize + 6436), 0xFFFFFFFF);
    }
    else
    {
      v10 = v9->GetFileName(this: pRequest);
      _Msg(a1: "Ignoring out-of-date introspection dictionary: '%s'\n", v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100040F0
// Name: public: void CResourceIntrospectionDictionary::Init(class CResourceSystem __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CResourceIntrospectionDictionary::Init(
        CResourceIntrospectionDictionary *this@<ecx>,
        _DWORD *a2@<esi>,
        CResourceSystem *pOwner)
{
  IAsyncSearchRequest *v4; // edi
  int i; // ebx
  IAsyncFileRequest *v6; // esi
  _DWORD *v7; // eax
  int v9; // [esp+18h] [ebp+8h]

  this->m_pOwner = pOwner;
  if ( this->m_StructMap.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_StructMap.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const unsigned int *, const unsigned int *))CDefOps<void const *>::LessFunc;
  if ( this->m_EnumMap.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_EnumMap.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const unsigned int *, const unsigned int *))CDefOps<void const *>::LessFunc;
  if ( this->m_TypedefMap.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_TypedefMap.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const unsigned int *, const unsigned int *))CDefOps<void const *>::LessFunc;
  v4 = g_pAsyncFileSystem->CreateNewSearchRequest(this: g_pAsyncFileSystem);
  v4->SetSearchPathAndFileSpec_2(this: v4, a2: "GAME", a3: "../bin/schema/*.vtd");
  v4->SetSubdirectoryScan(this: v4, a2: false);
  g_pAsyncFileSystem->SubmitSyncFileRequest(this: g_pAsyncFileSystem, a2: v4);
  for ( i = 0; i < v4->GetResultCount(this: v4); ++i )
  {
    v9 = ((int (__thiscall *)(IAsyncSearchRequest *, int, _DWORD *))v4->GetMatchedFile)(a1: v4, a2: i, a3: a2);
    v6 = g_pAsyncFileSystem->CreateNewFileRequest(this: g_pAsyncFileSystem);
    v6->LoadFile(this: v6, a2: (const char *)v9);
    v6->ProvideDataBuffer(this: v6);
    v7 = operator new(nSize: 0x1Cu);
    if ( v7 != nullptr )
    {
      v7[3] = 1;
      *v7 = &CMemberFunctor1<CResourceIntrospectionDictionary *,void (__thiscall CResourceIntrospectionDictionary::*)(IAsyncFileRequest *),IAsyncFileRequest *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
      v7[2] = &CMemberFunctor1<CResourceIntrospectionDictionary *,void (__thiscall CResourceIntrospectionDictionary::*)(IAsyncFileRequest *),IAsyncFileRequest *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
      v7[4] = CResourceIntrospectionDictionary::OnIntrospectionDictLoaded;
      v7[5] = this;
      v7[6] = v6;
    }
    else
    {
      v7 = nullptr;
    }
    a2 = v7;
    ((void (__thiscall *)(IAsyncFileRequest *))v6->AssignCallback)(a1: v6);
    _InterlockedExchangeAdd(&this->m_pOwner->m_nPendingVTDRequests.m_value, 1u);
    g_pAsyncFileSystem->SubmitAsyncFileRequest(this: g_pAsyncFileSystem, a2: v6);
  }
  g_pAsyncFileSystem->ReleaseAsyncRequest(this: g_pAsyncFileSystem, a2: v4);
}
