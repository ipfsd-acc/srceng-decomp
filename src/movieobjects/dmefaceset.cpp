// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmefaceset.cpp
// Functions: 17
// ============================================================

#include "movieobjects\dmefaceset.h"

//------------------------------------------------------------------------------
// Address: 0x004B2750
// Name: public: void CDmeFaceSet::SetIndices(int,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFaceSet::SetIndices(CDmeFaceSet *this, int nFirstIndex, int nCount, int *pIndices)
{
  CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::SetMultiple(
    this: &this->m_indices,
    i: nFirstIndex,
    nCount,
    pValue: pIndices);
}

//------------------------------------------------------------------------------
// Address: 0x004B2760
// Name: public: void CDmeFaceSet::SetIndex(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFaceSet::SetIndex(CDmeFaceSet *this, int i, int nValue)
{
  CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
    this: &this->m_indices,
    i,
    value: &nValue);
}

//------------------------------------------------------------------------------
// Address: 0x004B2780
// Name: public: void CDmeFaceSet::RemoveMultiple(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFaceSet::RemoveMultiple(CDmeFaceSet *this, int elem, int num)
{
  CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::RemoveMultiple(
    this: &this->m_indices,
    elem,
    num);
}

//------------------------------------------------------------------------------
// Address: 0x004B2790
// Name: public: class CDmeMaterial __near * CDmeFaceSet::GetMaterial(void)
// Source: json
//------------------------------------------------------------------------------
CDmeMaterial *__thiscall CDmeFaceSet::GetMaterial(CDmeFaceSet *this)
{
  return (CDmeMaterial *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_material.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x004B27B0
// Name: public: void CDmeFaceSet::SetMaterial(class CDmeMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFaceSet::SetMaterial(CDmeFaceSet *this, int pMaterial)
{
  CDmeMaterial *v3; // eax
  CDmAttribute *m_pAttribute; // ecx

  if ( pMaterial != 0 )
  {
    v3 = (CDmeMaterial *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pMaterial);
    m_pAttribute = this->m_material.m_pAttribute;
    pMaterial = (int)v3;
  }
  else
  {
    m_pAttribute = this->m_material.m_pAttribute;
    pMaterial = -1;
  }
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: m_pAttribute, value: (DmElementHandle_t *)&pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x004B27F0
// Name: public: int CDmeFaceSet::AddIndices(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::AddIndices(CDmeFaceSet *this, int nCount)
{
  int m_Size; // esi

  m_Size = this->m_indices.m_Storage.m_Size;
  CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::EnsureCount(
    this: &this->m_indices,
    num: m_Size + nCount);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004B2810
// Name: public: int CDmeFaceSet::GetNextPolygonVertexCount(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetNextPolygonVertexCount(CDmeFaceSet *this, int nFirstIndex)
{
  int m_Size; // edx
  int v3; // eax
  int *v4; // ecx

  m_Size = this->m_indices.m_Storage.m_Size;
  v3 = nFirstIndex;
  if ( nFirstIndex < m_Size )
  {
    v4 = &this->m_indices.m_Storage.m_Memory.m_pMemory[nFirstIndex];
    do
    {
      if ( *v4 == -1 )
        break;
      ++v3;
      ++v4;
    }
    while ( v3 < m_Size );
  }
  return v3 - nFirstIndex;
}

//------------------------------------------------------------------------------
// Address: 0x004B2840
// Name: public: int CDmeFaceSet::GetTriangulatedIndexCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetTriangulatedIndexCount(CDmeFaceSet *this)
{
  int m_Size; // esi
  int result; // eax
  int v3; // edx
  int *m_pMemory; // ecx

  m_Size = this->m_indices.m_Storage.m_Size;
  result = 0;
  v3 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_indices.m_Storage.m_Memory.m_pMemory;
    do
    {
      if ( *m_pMemory == -1 )
      {
        if ( v3 >= 3 )
          result = v3 + result - 2 + 2 * v3 - 4;
        v3 = 0;
      }
      else
      {
        ++v3;
      }
      ++m_pMemory;
      --m_Size;
    }
    while ( m_Size != 0 );
    if ( v3 >= 3 )
      return v3 + result - 2 + 2 * v3 - 4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B2880
// Name: public: int CDmeFaceSet::GetIndexCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetIndexCount(CDmeFaceSet *this)
{
  int m_Size; // edx
  int v2; // esi
  int v3; // eax
  int *m_pMemory; // ecx

  m_Size = this->m_indices.m_Storage.m_Size;
  v2 = 0;
  v3 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_indices.m_Storage.m_Memory.m_pMemory;
    do
    {
      if ( *m_pMemory == -1 )
      {
        v2 += v3;
        v3 = 0;
      }
      else
      {
        ++v3;
      }
      ++m_pMemory;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  return v2 + v3;
}

//------------------------------------------------------------------------------
// Address: 0x004B2910
// Name: public: virtual bool CDmeFaceSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFaceSet::IsA(CDmeFaceSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFaceSet::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B2940
// Name: public: virtual int CDmeFaceSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetInheritanceDepth(CDmeFaceSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFaceSet::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B2990
// Name: protected: virtual void CDmeFaceSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFaceSet::PerformConstruction(CDmeFaceSet *this)
{
  CDmeFXClip::OnDestruction();
  CDmaDecorator<int,CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &this->m_indices,
    pOwner: this,
    pAttributeName: "faces",
    nFlags: 0);
  this->m_material.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "material",
                                    type: AT_FIRST_VALUE_TYPE,
                                    pMemory: &this->m_material);
  CDmAttribute::SetElementTypeSymbol(this: this->m_material.m_pAttribute, typeSymbol: CDmeMaterial::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005ABFE0
// Name: _dynamic_initializer_for__CDmeFaceSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFaceSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFaceSet::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFaceSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AFC20
// Name: _dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFaceSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AC010
// Name: _dynamic_initializer_for__g_CDmeFaceSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFaceSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AC020
// Name: _dynamic_initializer_for__g_CDmeFaceSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFaceSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFaceSet_Helper,
           classname: "DmeFaceSet",
           pFactory: &g_CDmeFaceSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AFC30
// Name: _dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFaceSet_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00503230
// Name: public: class CDmeMaterial __near * CDmeFaceSet::GetMaterial(void)
// Source: json
//------------------------------------------------------------------------------
CDmeMaterial *__thiscall CDmeFaceSet::GetMaterial(CDmeFaceSet *this)
{
  return (CDmeMaterial *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_material.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00503250
// Name: public: int CDmeFaceSet::GetNextPolygonVertexCount(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetNextPolygonVertexCount(CDmeFaceSet *this, int nFirstIndex)
{
  int m_Size; // edx
  int v3; // eax
  int *v4; // ecx

  m_Size = this->m_indices.m_Storage.m_Size;
  v3 = nFirstIndex;
  if ( nFirstIndex < m_Size )
  {
    v4 = &this->m_indices.m_Storage.m_Memory.m_pMemory[nFirstIndex];
    do
    {
      if ( *v4 == -1 )
        break;
      ++v3;
      ++v4;
    }
    while ( v3 < m_Size );
  }
  return v3 - nFirstIndex;
}

//------------------------------------------------------------------------------
// Address: 0x00503280
// Name: public: int CDmeFaceSet::GetTriangulatedIndexCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetTriangulatedIndexCount(CDmeFaceSet *this)
{
  int m_Size; // esi
  int result; // eax
  int v3; // edx
  int *m_pMemory; // ecx

  m_Size = this->m_indices.m_Storage.m_Size;
  result = 0;
  v3 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_indices.m_Storage.m_Memory.m_pMemory;
    do
    {
      if ( *m_pMemory == -1 )
      {
        if ( v3 >= 3 )
          result = v3 + result - 2 + 2 * v3 - 4;
        v3 = 0;
      }
      else
      {
        ++v3;
      }
      ++m_pMemory;
      --m_Size;
    }
    while ( m_Size != 0 );
    if ( v3 >= 3 )
      return v3 + result - 2 + 2 * v3 - 4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00503320
// Name: public: virtual bool CDmeFaceSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFaceSet::IsA(CDmeFaceSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFaceSet::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00503350
// Name: public: virtual int CDmeFaceSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetInheritanceDepth(CDmeFaceSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFaceSet::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00503390
// Name: protected: virtual void CDmeFaceSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFaceSet::PerformConstruction(CDmeFaceSet *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmaDecorator<int,CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &this->m_indices,
    pOwner: this,
    pAttributeName: "faces",
    nFlags: 0);
  this->m_material.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "material",
                                    type: AT_FIRST_VALUE_TYPE,
                                    pMemory: &this->m_material);
  CDmAttribute::SetElementTypeSymbol(this: this->m_material.m_pAttribute, typeSymbol: CDmeMaterial::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0067D150
// Name: _dynamic_initializer_for__CDmeFaceSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFaceSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFaceSet::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFaceSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00681EF0
// Name: _dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFaceSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067D180
// Name: _dynamic_initializer_for__g_CDmeFaceSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFaceSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D190
// Name: _dynamic_initializer_for__g_CDmeFaceSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFaceSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFaceSet_Helper,
           classname: "DmeFaceSet",
           pFactory: &g_CDmeFaceSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00681F00
// Name: _dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeFaceSet_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10599C40
// Name: public: class CDmeMaterial __near * CDmeFaceSet::GetMaterial(void)
// Source: json
//------------------------------------------------------------------------------
CDmeMaterial *__thiscall CDmeFaceSet::GetMaterial(CDmeFaceSet *this)
{
  return (CDmeMaterial *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_material.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x10599C60
// Name: public: int CDmeFaceSet::GetNextPolygonVertexCount(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetNextPolygonVertexCount(CDmeFaceSet *this, int nFirstIndex)
{
  int m_Size; // edx
  int v3; // eax
  int *v4; // ecx

  m_Size = this->m_indices.m_Storage.m_Size;
  v3 = nFirstIndex;
  if ( nFirstIndex < m_Size )
  {
    v4 = &this->m_indices.m_Storage.m_Memory.m_pMemory[nFirstIndex];
    do
    {
      if ( *v4 == -1 )
        break;
      ++v3;
      ++v4;
    }
    while ( v3 < m_Size );
  }
  return v3 - nFirstIndex;
}

//------------------------------------------------------------------------------
// Address: 0x10599C90
// Name: public: int CDmeFaceSet::GetTriangulatedIndexCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetTriangulatedIndexCount(CDmeFaceSet *this)
{
  int m_Size; // esi
  int result; // eax
  int v3; // edx
  int *m_pMemory; // ecx

  m_Size = this->m_indices.m_Storage.m_Size;
  result = 0;
  v3 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_indices.m_Storage.m_Memory.m_pMemory;
    do
    {
      if ( *m_pMemory == -1 )
      {
        if ( v3 >= 3 )
          result = v3 + result - 2 + 2 * v3 - 4;
        v3 = 0;
      }
      else
      {
        ++v3;
      }
      ++m_pMemory;
      --m_Size;
    }
    while ( m_Size != 0 );
    if ( v3 >= 3 )
      return v3 + result - 2 + 2 * v3 - 4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10599D30
// Name: public: virtual bool CDmeFaceSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFaceSet::IsA(CDmeFaceSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFaceSet::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x10599D60
// Name: public: virtual int CDmeFaceSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetInheritanceDepth(CDmeFaceSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFaceSet::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10599DA0
// Name: protected: virtual void CDmeFaceSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFaceSet::PerformConstruction(CDmeFaceSet *this)
{
  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  CDmaDecorator<int,CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &this->m_indices,
    pOwner: this,
    pAttributeName: "faces",
    nFlags: 0);
  this->m_material.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "material",
                                    type: AT_FIRST_VALUE_TYPE,
                                    pMemory: &this->m_material);
  CDmAttribute::SetElementTypeSymbol(this: this->m_material.m_pAttribute, typeSymbol: CDmeMaterial::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x105C9C00
// Name: _dynamic_initializer_for__CDmeFaceSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFaceSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFaceSet::s_Allocator,
    blockSize: 0x68u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFaceSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CDC50
// Name: _dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFaceSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C9C30
// Name: _dynamic_initializer_for__g_CDmeFaceSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFaceSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9C40
// Name: _dynamic_initializer_for__g_CDmeFaceSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFaceSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFaceSet_Helper,
           classname: "DmeFaceSet",
           pFactory: &g_CDmeFaceSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CDC60
// Name: _dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeFaceSet_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x004B6710
// Name: public: class CDmeMaterial __near * CDmeFaceSet::GetMaterial(void)
// Source: json
//------------------------------------------------------------------------------
CDmeMaterial *__thiscall CDmeFaceSet::GetMaterial(CDmeFaceSet *this)
{
  return (*(CDmeMaterial *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 72))(
           a1: g_pDataModel.u,
           a2: this->m_material.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x004B6730
// Name: public: int CDmeFaceSet::GetNextPolygonVertexCount(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetNextPolygonVertexCount(CDmeFaceSet *this, int nFirstIndex)
{
  int m_Size; // edx
  int v3; // eax
  int *v4; // ecx

  m_Size = this->m_indices.m_Storage.m_Size;
  v3 = nFirstIndex;
  if ( nFirstIndex < m_Size )
  {
    v4 = &this->m_indices.m_Storage.m_Memory.m_pMemory[nFirstIndex];
    do
    {
      if ( *v4 == -1 )
        break;
      ++v3;
      ++v4;
    }
    while ( v3 < m_Size );
  }
  return v3 - nFirstIndex;
}

//------------------------------------------------------------------------------
// Address: 0x004B6760
// Name: public: int CDmeFaceSet::GetTriangulatedIndexCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetTriangulatedIndexCount(CDmeFaceSet *this)
{
  int m_Size; // esi
  int result; // eax
  int v3; // edx
  int *m_pMemory; // ecx

  m_Size = this->m_indices.m_Storage.m_Size;
  result = 0;
  v3 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_indices.m_Storage.m_Memory.m_pMemory;
    do
    {
      if ( *m_pMemory == -1 )
      {
        if ( v3 >= 3 )
          result = v3 + result - 2 + 2 * v3 - 4;
        v3 = 0;
      }
      else
      {
        ++v3;
      }
      ++m_pMemory;
      --m_Size;
    }
    while ( m_Size != 0 );
    if ( v3 >= 3 )
      return v3 + result - 2 + 2 * v3 - 4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004B6800
// Name: public: virtual bool CDmeFaceSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFaceSet::IsA(CDmeFaceSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFaceSet::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B6830
// Name: public: virtual int CDmeFaceSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetInheritanceDepth(CDmeFaceSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFaceSet::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B6870
// Name: protected: virtual void CDmeFaceSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFaceSet::PerformConstruction(CDmeFaceSet *this)
{
  CDmeFXClip::OnDestruction();
  CDmaDecorator<int,CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &this->m_indices,
    pOwner: this,
    pAttributeName: "faces",
    nFlags: 0);
  this->m_material.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "material",
                                    type: AT_FIRST_VALUE_TYPE,
                                    pMemory: &this->m_material);
  CDmAttribute::SetElementTypeSymbol(this: this->m_material.m_pAttribute, typeSymbol: CDmeMaterial::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0059AB70
// Name: _dynamic_initializer_for__CDmeFaceSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFaceSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFaceSet::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFaceSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059EBD0
// Name: _dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFaceSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059ABA0
// Name: _dynamic_initializer_for__g_CDmeFaceSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFaceSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059ABB0
// Name: _dynamic_initializer_for__g_CDmeFaceSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFaceSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFaceSet_Helper,
           classname: "DmeFaceSet",
           pFactory: &g_CDmeFaceSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059EBE0
// Name: _dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFaceSet_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x0050B700
// Name: public: class CDmeMaterial __near * CDmeFaceSet::GetMaterial(void)
// Source: json
//------------------------------------------------------------------------------
CDmeMaterial *__thiscall CDmeFaceSet::GetMaterial(CDmeFaceSet *this)
{
  return (*(CDmeMaterial *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 72))(
           a1: g_pDataModel.u,
           a2: this->m_material.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x0050B720
// Name: public: int CDmeFaceSet::GetNextPolygonVertexCount(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetNextPolygonVertexCount(CDmeFaceSet *this, int nFirstIndex)
{
  int m_Size; // edx
  int v3; // eax
  int *v4; // ecx

  m_Size = this->m_indices.m_Storage.m_Size;
  v3 = nFirstIndex;
  if ( nFirstIndex < m_Size )
  {
    v4 = &this->m_indices.m_Storage.m_Memory.m_pMemory[nFirstIndex];
    do
    {
      if ( *v4 == -1 )
        break;
      ++v3;
      ++v4;
    }
    while ( v3 < m_Size );
  }
  return v3 - nFirstIndex;
}

//------------------------------------------------------------------------------
// Address: 0x0050B750
// Name: public: int CDmeFaceSet::GetTriangulatedIndexCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetTriangulatedIndexCount(CDmeFaceSet *this)
{
  int m_Size; // esi
  int result; // eax
  int v3; // edx
  int *m_pMemory; // ecx

  m_Size = this->m_indices.m_Storage.m_Size;
  result = 0;
  v3 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_indices.m_Storage.m_Memory.m_pMemory;
    do
    {
      if ( *m_pMemory == -1 )
      {
        if ( v3 >= 3 )
          result = v3 + result - 2 + 2 * v3 - 4;
        v3 = 0;
      }
      else
      {
        ++v3;
      }
      ++m_pMemory;
      --m_Size;
    }
    while ( m_Size != 0 );
    if ( v3 >= 3 )
      return v3 + result - 2 + 2 * v3 - 4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0050B7F0
// Name: public: virtual bool CDmeFaceSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFaceSet::IsA(CDmeFaceSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFaceSet::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050B820
// Name: public: virtual int CDmeFaceSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetInheritanceDepth(CDmeFaceSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFaceSet::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050B860
// Name: protected: virtual void CDmeFaceSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFaceSet::PerformConstruction(CDmeFaceSet *this)
{
  CDmeFXClip::OnDestruction();
  CDmaDecorator<int,CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &this->m_indices,
    pOwner: this,
    pAttributeName: "faces",
    nFlags: 0);
  this->m_material.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "material",
                                    type: AT_FIRST_VALUE_TYPE,
                                    pMemory: &this->m_material);
  CDmAttribute::SetElementTypeSymbol(this: this->m_material.m_pAttribute, typeSymbol: CDmeMaterial::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005F00F0
// Name: _dynamic_initializer_for__CDmeFaceSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFaceSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFaceSet::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFaceSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F41A0
// Name: _dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFaceSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F0120
// Name: _dynamic_initializer_for__g_CDmeFaceSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFaceSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0130
// Name: _dynamic_initializer_for__g_CDmeFaceSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFaceSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFaceSet_Helper,
           classname: "DmeFaceSet",
           pFactory: &g_CDmeFaceSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F41B0
// Name: _dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFaceSet_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0046F1E0
// Name: public: class CDmeMaterial __near * CDmeFaceSet::GetMaterial(void)
// Source: json
//------------------------------------------------------------------------------
CDmeMaterial *__thiscall CDmeFaceSet::GetMaterial(CDmeFaceSet *this)
{
  return (CDmeMaterial *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_material.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x0046F200
// Name: public: int CDmeFaceSet::GetNextPolygonVertexCount(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetNextPolygonVertexCount(CDmeFaceSet *this, int nFirstIndex)
{
  int m_Size; // edx
  int v3; // eax
  int *v4; // ecx

  m_Size = this->m_indices.m_Storage.m_Size;
  v3 = nFirstIndex;
  if ( nFirstIndex < m_Size )
  {
    v4 = &this->m_indices.m_Storage.m_Memory.m_pMemory[nFirstIndex];
    do
    {
      if ( *v4 == -1 )
        break;
      ++v3;
      ++v4;
    }
    while ( v3 < m_Size );
  }
  return v3 - nFirstIndex;
}

//------------------------------------------------------------------------------
// Address: 0x0046F230
// Name: public: int CDmeFaceSet::GetTriangulatedIndexCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetTriangulatedIndexCount(CDmeFaceSet *this)
{
  int m_Size; // esi
  int result; // eax
  int v3; // edx
  int *m_pMemory; // ecx

  m_Size = this->m_indices.m_Storage.m_Size;
  result = 0;
  v3 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_indices.m_Storage.m_Memory.m_pMemory;
    do
    {
      if ( *m_pMemory == -1 )
      {
        if ( v3 >= 3 )
          result = v3 + result - 2 + 2 * v3 - 4;
        v3 = 0;
      }
      else
      {
        ++v3;
      }
      ++m_pMemory;
      --m_Size;
    }
    while ( m_Size != 0 );
    if ( v3 >= 3 )
      return v3 + result - 2 + 2 * v3 - 4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0046F2D0
// Name: public: virtual bool CDmeFaceSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFaceSet::IsA(CDmeFaceSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFaceSet::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046F300
// Name: public: virtual int CDmeFaceSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetInheritanceDepth(CDmeFaceSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFaceSet::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0046F340
// Name: protected: virtual void CDmeFaceSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFaceSet::PerformConstruction(CDmeFaceSet *this)
{
  CDmeFXClip::OnDestruction();
  CDmaDecorator<int,CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &this->m_indices,
    pOwner: this,
    pAttributeName: "faces",
    nFlags: 0);
  this->m_material.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "material",
                                    type: AT_FIRST_VALUE_TYPE,
                                    pMemory: &this->m_material);
  CDmAttribute::SetElementTypeSymbol(this: this->m_material.m_pAttribute, typeSymbol: CDmeMaterial::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00569D30
// Name: _dynamic_initializer_for__CDmeFaceSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFaceSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFaceSet::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFaceSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056E0D0
// Name: _dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFaceSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00569D60
// Name: _dynamic_initializer_for__g_CDmeFaceSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFaceSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00569D70
// Name: _dynamic_initializer_for__g_CDmeFaceSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFaceSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFaceSet_Helper,
           classname: "DmeFaceSet",
           pFactory: &g_CDmeFaceSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056E0E0
// Name: _dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFaceSet_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00472E80
// Name: public: class CDmeMaterial __near * CDmeFaceSet::GetMaterial(void)
// Source: json
//------------------------------------------------------------------------------
CDmeMaterial *__thiscall CDmeFaceSet::GetMaterial(CDmeFaceSet *this)
{
  return (CDmeMaterial *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_material.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00472EA0
// Name: public: int CDmeFaceSet::GetNextPolygonVertexCount(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetNextPolygonVertexCount(CDmeFaceSet *this, int nFirstIndex)
{
  int m_Size; // edx
  int v3; // eax
  int *v4; // ecx

  m_Size = this->m_indices.m_Storage.m_Size;
  v3 = nFirstIndex;
  if ( nFirstIndex < m_Size )
  {
    v4 = &this->m_indices.m_Storage.m_Memory.m_pMemory[nFirstIndex];
    do
    {
      if ( *v4 == -1 )
        break;
      ++v3;
      ++v4;
    }
    while ( v3 < m_Size );
  }
  return v3 - nFirstIndex;
}

//------------------------------------------------------------------------------
// Address: 0x00472ED0
// Name: public: int CDmeFaceSet::GetTriangulatedIndexCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetTriangulatedIndexCount(CDmeFaceSet *this)
{
  int m_Size; // esi
  int result; // eax
  int v3; // edx
  int *m_pMemory; // ecx

  m_Size = this->m_indices.m_Storage.m_Size;
  result = 0;
  v3 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_indices.m_Storage.m_Memory.m_pMemory;
    do
    {
      if ( *m_pMemory == -1 )
      {
        if ( v3 >= 3 )
          result = v3 + result - 2 + 2 * v3 - 4;
        v3 = 0;
      }
      else
      {
        ++v3;
      }
      ++m_pMemory;
      --m_Size;
    }
    while ( m_Size != 0 );
    if ( v3 >= 3 )
      return v3 + result - 2 + 2 * v3 - 4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00472F70
// Name: public: virtual bool CDmeFaceSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFaceSet::IsA(CDmeFaceSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFaceSet::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00472FA0
// Name: public: virtual int CDmeFaceSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetInheritanceDepth(CDmeFaceSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFaceSet::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00472FF0
// Name: protected: virtual void CDmeFaceSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFaceSet::PerformConstruction(CDmeFaceSet *this)
{
  CDmeFXClip::OnDestruction();
  CDmaDecorator<int,CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &this->m_indices,
    pOwner: this,
    pAttributeName: "faces",
    nFlags: 0);
  this->m_material.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "material",
                                    type: AT_FIRST_VALUE_TYPE,
                                    pMemory: &this->m_material);
  CDmAttribute::SetElementTypeSymbol(this: this->m_material.m_pAttribute, typeSymbol: CDmeMaterial::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00579E30
// Name: _dynamic_initializer_for__CDmeFaceSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFaceSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFaceSet::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFaceSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E200
// Name: _dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFaceSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00579E60
// Name: _dynamic_initializer_for__g_CDmeFaceSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFaceSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579E70
// Name: _dynamic_initializer_for__g_CDmeFaceSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFaceSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFaceSet_Helper,
           classname: "DmeFaceSet",
           pFactory: &g_CDmeFaceSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E210
// Name: _dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFaceSet_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00525260
// Name: public: void CDmeFaceSet::SetIndices(int,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFaceSet::SetIndices(CDmeFaceSet *this, int nFirstIndex, int nCount, int *pIndices)
{
  CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::SetMultiple(
    this: &this->m_indices,
    i: nFirstIndex,
    nCount,
    pValue: pIndices);
}

//------------------------------------------------------------------------------
// Address: 0x00525270
// Name: public: class CDmeMaterial __near * CDmeFaceSet::GetMaterial(void)
// Source: json
//------------------------------------------------------------------------------
CDmeMaterial *__thiscall CDmeFaceSet::GetMaterial(CDmeFaceSet *this)
{
  return (*(CDmeMaterial *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 72))(
           a1: g_pDataModel.u,
           a2: this->m_material.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00525290
// Name: public: void CDmeFaceSet::SetMaterial(class CDmeMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFaceSet::SetMaterial(CDmeFaceSet *this, int pMaterial)
{
  CDmeMaterial *BufferType; // eax
  CDmAttribute *m_pAttribute; // ecx

  if ( pMaterial != 0 )
  {
    BufferType = (CDmeMaterial *)CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pMaterial);
    m_pAttribute = this->m_material.m_pAttribute;
    pMaterial = (int)BufferType;
  }
  else
  {
    m_pAttribute = this->m_material.m_pAttribute;
    pMaterial = -1;
  }
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: m_pAttribute, value: (const DmElementHandle_t *)&pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x005252D0
// Name: public: int CDmeFaceSet::AddIndices(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::AddIndices(CDmeFaceSet *this, int nCount)
{
  int m_Size; // esi

  m_Size = this->m_indices.m_Storage.m_Size;
  CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::EnsureCount(
    this: &this->m_indices,
    num: m_Size + nCount);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x005252F0
// Name: public: int CDmeFaceSet::GetNextPolygonVertexCount(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetNextPolygonVertexCount(CDmeFaceSet *this, int nFirstIndex)
{
  int m_Size; // edx
  int v3; // eax
  int *v4; // ecx

  m_Size = this->m_indices.m_Storage.m_Size;
  v3 = nFirstIndex;
  if ( nFirstIndex < m_Size )
  {
    v4 = &this->m_indices.m_Storage.m_Memory.m_pMemory[nFirstIndex];
    do
    {
      if ( *v4 == -1 )
        break;
      ++v3;
      ++v4;
    }
    while ( v3 < m_Size );
  }
  return v3 - nFirstIndex;
}

//------------------------------------------------------------------------------
// Address: 0x00525320
// Name: public: int CDmeFaceSet::GetTriangulatedIndexCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetTriangulatedIndexCount(CDmeFaceSet *this)
{
  int m_Size; // esi
  int result; // eax
  int v3; // edx
  int *m_pMemory; // ecx

  m_Size = this->m_indices.m_Storage.m_Size;
  result = 0;
  v3 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_indices.m_Storage.m_Memory.m_pMemory;
    do
    {
      if ( *m_pMemory == -1 )
      {
        if ( v3 >= 3 )
          result = v3 + result - 2 + 2 * v3 - 4;
        v3 = 0;
      }
      else
      {
        ++v3;
      }
      ++m_pMemory;
      --m_Size;
    }
    while ( m_Size != 0 );
    if ( v3 >= 3 )
      return v3 + result - 2 + 2 * v3 - 4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005253C0
// Name: public: virtual bool CDmeFaceSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFaceSet::IsA(CDmeFaceSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFaceSet::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005253F0
// Name: public: virtual int CDmeFaceSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetInheritanceDepth(CDmeFaceSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFaceSet::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00525430
// Name: protected: virtual void CDmeFaceSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFaceSet::PerformConstruction(CDmeFaceSet *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmaDecorator<int,CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &this->m_indices,
    pOwner: this,
    pAttributeName: "faces",
    nFlags: 0);
  this->m_material.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "material",
                                    type: AT_FIRST_VALUE_TYPE,
                                    pMemory: &this->m_material);
  CDmAttribute::SetElementTypeSymbol(this: this->m_material.m_pAttribute, typeSymbol: CDmeMaterial::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x006AEFD0
// Name: _dynamic_initializer_for__CDmeFaceSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFaceSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFaceSet::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFaceSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B4970
// Name: _dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFaceSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006AF000
// Name: _dynamic_initializer_for__g_CDmeFaceSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFaceSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006AF010
// Name: _dynamic_initializer_for__g_CDmeFaceSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFaceSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFaceSet_Helper,
           classname: "DmeFaceSet",
           pFactory: &g_CDmeFaceSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B4980
// Name: _dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeFaceSet_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00473C10
// Name: public: class CDmeMaterial __near * CDmeFaceSet::GetMaterial(void)
// Source: json
//------------------------------------------------------------------------------
CDmeMaterial *__thiscall CDmeFaceSet::GetMaterial(CDmeFaceSet *this)
{
  return (CDmeMaterial *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_material.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00473C30
// Name: public: int CDmeFaceSet::GetNextPolygonVertexCount(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetNextPolygonVertexCount(CDmeFaceSet *this, int nFirstIndex)
{
  int m_Size; // edx
  int v3; // eax
  int *v4; // ecx

  m_Size = this->m_indices.m_Storage.m_Size;
  v3 = nFirstIndex;
  if ( nFirstIndex < m_Size )
  {
    v4 = &this->m_indices.m_Storage.m_Memory.m_pMemory[nFirstIndex];
    do
    {
      if ( *v4 == -1 )
        break;
      ++v3;
      ++v4;
    }
    while ( v3 < m_Size );
  }
  return v3 - nFirstIndex;
}

//------------------------------------------------------------------------------
// Address: 0x00473C60
// Name: public: int CDmeFaceSet::GetTriangulatedIndexCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetTriangulatedIndexCount(CDmeFaceSet *this)
{
  int m_Size; // esi
  int result; // eax
  int v3; // edx
  int *m_pMemory; // ecx

  m_Size = this->m_indices.m_Storage.m_Size;
  result = 0;
  v3 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_indices.m_Storage.m_Memory.m_pMemory;
    do
    {
      if ( *m_pMemory == -1 )
      {
        if ( v3 >= 3 )
          result = v3 + result - 2 + 2 * v3 - 4;
        v3 = 0;
      }
      else
      {
        ++v3;
      }
      ++m_pMemory;
      --m_Size;
    }
    while ( m_Size != 0 );
    if ( v3 >= 3 )
      return v3 + result - 2 + 2 * v3 - 4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00473D00
// Name: public: virtual bool CDmeFaceSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFaceSet::IsA(CDmeFaceSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFaceSet::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00473D30
// Name: public: virtual int CDmeFaceSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetInheritanceDepth(CDmeFaceSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFaceSet::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00473D70
// Name: protected: virtual void CDmeFaceSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFaceSet::PerformConstruction(CDmeFaceSet *this)
{
  CDmeFXClip::OnDestruction();
  CDmaDecorator<int,CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &this->m_indices,
    pOwner: this,
    pAttributeName: "faces",
    nFlags: 0);
  this->m_material.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "material",
                                    type: AT_FIRST_VALUE_TYPE,
                                    pMemory: &this->m_material);
  CDmAttribute::SetElementTypeSymbol(this: this->m_material.m_pAttribute, typeSymbol: CDmeMaterial::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0057BE20
// Name: _dynamic_initializer_for__CDmeFaceSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFaceSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFaceSet::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFaceSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005801E0
// Name: _dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFaceSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057BE50
// Name: _dynamic_initializer_for__g_CDmeFaceSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFaceSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BE60
// Name: _dynamic_initializer_for__g_CDmeFaceSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFaceSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFaceSet_Helper,
           classname: "DmeFaceSet",
           pFactory: &g_CDmeFaceSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005801F0
// Name: _dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFaceSet_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x00504750
// Name: public: class CDmeMaterial __near * CDmeFaceSet::GetMaterial(void)
// Source: json
//------------------------------------------------------------------------------
CDmeMaterial *__thiscall CDmeFaceSet::GetMaterial(CDmeFaceSet *this)
{
  return (*(CDmeMaterial *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 72))(
           a1: g_pDataModel.u,
           a2: this->m_material.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00504770
// Name: public: int CDmeFaceSet::GetNextPolygonVertexCount(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetNextPolygonVertexCount(CDmeFaceSet *this, int nFirstIndex)
{
  int m_Size; // edx
  int v3; // eax
  int *v4; // ecx

  m_Size = this->m_indices.m_Storage.m_Size;
  v3 = nFirstIndex;
  if ( nFirstIndex < m_Size )
  {
    v4 = &this->m_indices.m_Storage.m_Memory.m_pMemory[nFirstIndex];
    do
    {
      if ( *v4 == -1 )
        break;
      ++v3;
      ++v4;
    }
    while ( v3 < m_Size );
  }
  return v3 - nFirstIndex;
}

//------------------------------------------------------------------------------
// Address: 0x005047A0
// Name: public: int CDmeFaceSet::GetTriangulatedIndexCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetTriangulatedIndexCount(CDmeFaceSet *this)
{
  int m_Size; // esi
  int result; // eax
  int v3; // edx
  int *m_pMemory; // ecx

  m_Size = this->m_indices.m_Storage.m_Size;
  result = 0;
  v3 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_indices.m_Storage.m_Memory.m_pMemory;
    do
    {
      if ( *m_pMemory == -1 )
      {
        if ( v3 >= 3 )
          result = v3 + result - 2 + 2 * v3 - 4;
        v3 = 0;
      }
      else
      {
        ++v3;
      }
      ++m_pMemory;
      --m_Size;
    }
    while ( m_Size != 0 );
    if ( v3 >= 3 )
      return v3 + result - 2 + 2 * v3 - 4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00504840
// Name: public: virtual bool CDmeFaceSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFaceSet::IsA(CDmeFaceSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFaceSet::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00504870
// Name: public: virtual int CDmeFaceSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetInheritanceDepth(CDmeFaceSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFaceSet::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005048C0
// Name: protected: virtual void CDmeFaceSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFaceSet::PerformConstruction(CDmeFaceSet *this)
{
  CDmeFXClip::OnDestruction();
  CDmaDecorator<int,CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &this->m_indices,
    pOwner: this,
    pAttributeName: "faces",
    nFlags: 0);
  this->m_material.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "material",
                                    type: AT_FIRST_VALUE_TYPE,
                                    pMemory: &this->m_material);
  CDmAttribute::SetElementTypeSymbol(this: this->m_material.m_pAttribute, typeSymbol: CDmeMaterial::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005E8F90
// Name: _dynamic_initializer_for__CDmeFaceSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFaceSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFaceSet::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFaceSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED040
// Name: _dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFaceSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E8FC0
// Name: _dynamic_initializer_for__g_CDmeFaceSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFaceSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E8FD0
// Name: _dynamic_initializer_for__g_CDmeFaceSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFaceSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFaceSet_Helper,
           classname: "DmeFaceSet",
           pFactory: &g_CDmeFaceSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED050
// Name: _dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFaceSet_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00475C60
// Name: public: void CDmeFaceSet::SetIndices(int,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFaceSet::SetIndices(CDmeFaceSet *this, int nFirstIndex, int nCount, int *pIndices)
{
  CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::SetMultiple(
    this: &this->m_indices,
    i: nFirstIndex,
    nCount,
    pValue: pIndices);
}

//------------------------------------------------------------------------------
// Address: 0x00475C70
// Name: public: class CDmeMaterial __near * CDmeFaceSet::GetMaterial(void)
// Source: json
//------------------------------------------------------------------------------
CDmeMaterial *__thiscall CDmeFaceSet::GetMaterial(CDmeFaceSet *this)
{
  return (CDmeMaterial *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_material.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00475C90
// Name: public: void CDmeFaceSet::SetMaterial(class CDmeMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFaceSet::SetMaterial(CDmeFaceSet *this, int pMaterial)
{
  CDmeMaterial *v3; // eax
  CDmAttribute *m_pAttribute; // ecx

  if ( pMaterial != 0 )
  {
    v3 = (CDmeMaterial *)CExpressionCalculator::VariableCount(this: (CExpressionCalculator *)pMaterial);
    m_pAttribute = this->m_material.m_pAttribute;
    pMaterial = (int)v3;
  }
  else
  {
    m_pAttribute = this->m_material.m_pAttribute;
    pMaterial = -1;
  }
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: m_pAttribute, value: (const DmElementHandle_t *)&pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x00475CD0
// Name: public: int CDmeFaceSet::AddIndices(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::AddIndices(CDmeFaceSet *this, int nCount)
{
  int m_Size; // esi

  m_Size = this->m_indices.m_Storage.m_Size;
  CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::EnsureCount(
    this: &this->m_indices,
    num: m_Size + nCount);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00475CF0
// Name: public: int CDmeFaceSet::GetNextPolygonVertexCount(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetNextPolygonVertexCount(CDmeFaceSet *this, int nFirstIndex)
{
  int m_Size; // edx
  int v3; // eax
  int *v4; // ecx

  m_Size = this->m_indices.m_Storage.m_Size;
  v3 = nFirstIndex;
  if ( nFirstIndex < m_Size )
  {
    v4 = &this->m_indices.m_Storage.m_Memory.m_pMemory[nFirstIndex];
    do
    {
      if ( *v4 == -1 )
        break;
      ++v3;
      ++v4;
    }
    while ( v3 < m_Size );
  }
  return v3 - nFirstIndex;
}

//------------------------------------------------------------------------------
// Address: 0x00475D20
// Name: public: int CDmeFaceSet::GetTriangulatedIndexCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetTriangulatedIndexCount(CDmeFaceSet *this)
{
  int m_Size; // esi
  int result; // eax
  int v3; // edx
  int *m_pMemory; // ecx

  m_Size = this->m_indices.m_Storage.m_Size;
  result = 0;
  v3 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_indices.m_Storage.m_Memory.m_pMemory;
    do
    {
      if ( *m_pMemory == -1 )
      {
        if ( v3 >= 3 )
          result = v3 + result - 2 + 2 * v3 - 4;
        v3 = 0;
      }
      else
      {
        ++v3;
      }
      ++m_pMemory;
      --m_Size;
    }
    while ( m_Size != 0 );
    if ( v3 >= 3 )
      return v3 + result - 2 + 2 * v3 - 4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00475DC0
// Name: public: virtual bool CDmeFaceSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFaceSet::IsA(CDmeFaceSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFaceSet::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00475DF0
// Name: public: virtual int CDmeFaceSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetInheritanceDepth(CDmeFaceSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFaceSet::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00475E30
// Name: protected: virtual void CDmeFaceSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFaceSet::PerformConstruction(CDmeFaceSet *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmaDecorator<int,CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &this->m_indices,
    pOwner: this,
    pAttributeName: "faces",
    nFlags: 0);
  this->m_material.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "material",
                                    type: AT_FIRST_VALUE_TYPE,
                                    pMemory: &this->m_material);
  CDmAttribute::SetElementTypeSymbol(this: this->m_material.m_pAttribute, typeSymbol: CDmeMaterial::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x00579330
// Name: _dynamic_initializer_for__CDmeFaceSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFaceSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFaceSet::s_Allocator,
    blockSize: 104,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFaceSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D770
// Name: _dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFaceSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00579360
// Name: _dynamic_initializer_for__g_CDmeFaceSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFaceSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579370
// Name: _dynamic_initializer_for__g_CDmeFaceSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFaceSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFaceSet_Helper,
           classname: "DmeFaceSet",
           pFactory: &g_CDmeFaceSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057D780
// Name: _dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeFaceSet_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x005808F0
// Name: public: void CDmeFaceSet::SetIndex(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFaceSet::SetIndex(CDmeFaceSet *this, int i, int nValue)
{
  CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::Set(
    this: &this->m_indices,
    i,
    value: &nValue);
}

//------------------------------------------------------------------------------
// Address: 0x00580910
// Name: public: class CDmeMaterial __near * CDmeFaceSet::GetMaterial(void)
// Source: json
//------------------------------------------------------------------------------
CDmeMaterial *__thiscall CDmeFaceSet::GetMaterial(CDmeFaceSet *this)
{
  return (CDmeMaterial *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_material.m_Storage.m_Handle);
}

//------------------------------------------------------------------------------
// Address: 0x00580930
// Name: public: void CDmeFaceSet::SetMaterial(class CDmeMaterial __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFaceSet::SetMaterial(CDmeFaceSet *this, int pMaterial)
{
  CDmeMaterial *CenterVertIndex; // eax
  CDmAttribute *m_pAttribute; // ecx

  if ( pMaterial != 0 )
  {
    CenterVertIndex = (CDmeMaterial *)CCoreDispNode::GetCenterVertIndex(this: (CVTFTexture *)pMaterial);
    m_pAttribute = this->m_material.m_pAttribute;
    pMaterial = (int)CenterVertIndex;
  }
  else
  {
    m_pAttribute = this->m_material.m_pAttribute;
    pMaterial = -1;
  }
  CDmAttribute::SetValue<enum DmElementHandle_t>(this: m_pAttribute, value: (DmElementHandle_t *)&pMaterial);
}

//------------------------------------------------------------------------------
// Address: 0x00580970
// Name: public: int CDmeFaceSet::AddIndices(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::AddIndices(CDmeFaceSet *this, int nCount)
{
  int m_Size; // esi

  m_Size = this->m_indices.m_Storage.m_Size;
  CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::EnsureCount(
    this: &this->m_indices,
    num: m_Size + nCount);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00580990
// Name: public: int CDmeFaceSet::GetNextPolygonVertexCount(int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetNextPolygonVertexCount(CDmeFaceSet *this, int nFirstIndex)
{
  int m_Size; // edx
  int v3; // eax
  int *v4; // ecx

  m_Size = this->m_indices.m_Storage.m_Size;
  v3 = nFirstIndex;
  if ( nFirstIndex < m_Size )
  {
    v4 = &this->m_indices.m_Storage.m_Memory.m_pMemory[nFirstIndex];
    do
    {
      if ( *v4 == -1 )
        break;
      ++v3;
      ++v4;
    }
    while ( v3 < m_Size );
  }
  return v3 - nFirstIndex;
}

//------------------------------------------------------------------------------
// Address: 0x005809C0
// Name: public: int CDmeFaceSet::GetTriangulatedIndexCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetTriangulatedIndexCount(CDmeFaceSet *this)
{
  int m_Size; // esi
  int result; // eax
  int v3; // edx
  int *m_pMemory; // ecx

  m_Size = this->m_indices.m_Storage.m_Size;
  result = 0;
  v3 = 0;
  if ( m_Size > 0 )
  {
    m_pMemory = this->m_indices.m_Storage.m_Memory.m_pMemory;
    do
    {
      if ( *m_pMemory == -1 )
      {
        if ( v3 >= 3 )
          result = v3 + result - 2 + 2 * v3 - 4;
        v3 = 0;
      }
      else
      {
        ++v3;
      }
      ++m_pMemory;
      --m_Size;
    }
    while ( m_Size != 0 );
    if ( v3 >= 3 )
      return v3 + result - 2 + 2 * v3 - 4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00580A60
// Name: public: virtual bool CDmeFaceSet::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeFaceSet::IsA(CDmeFaceSet *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeFaceSet::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00580A90
// Name: public: virtual int CDmeFaceSet::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeFaceSet::GetInheritanceDepth(CDmeFaceSet *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeFaceSet::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00580AD0
// Name: protected: virtual void CDmeFaceSet::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeFaceSet::PerformConstruction(CDmeFaceSet *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmaDecorator<int,CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &this->m_indices,
    pOwner: this,
    pAttributeName: "faces",
    nFlags: 0);
  this->m_material.m_pAttribute = CDmElement::AddExternalAttribute(
                                    this,
                                    pAttributeName: "material",
                                    type: AT_FIRST_VALUE_TYPE,
                                    pMemory: &this->m_material);
  CDmAttribute::SetElementTypeSymbol(this: this->m_material.m_pAttribute, typeSymbol: CDmeMaterial::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x006B75E0
// Name: _dynamic_initializer_for__CDmeFaceSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeFaceSet::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeFaceSet::s_Allocator,
    blockSize: 0x68u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeFaceSet pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BC6F0
// Name: _dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeFaceSet::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeFaceSet::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B7610
// Name: _dynamic_initializer_for__g_CDmeFaceSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeFaceSet_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7620
// Name: _dynamic_initializer_for__g_CDmeFaceSet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeFaceSet_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeFaceSet_Helper,
           classname: "DmeFaceSet",
           pFactory: &g_CDmeFaceSet_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BC700
// Name: _dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeFaceSet_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeFaceSet_Factory.m_CallBackList);
}

} // namespace vmap
