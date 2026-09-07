// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmeconnectionoperator.cpp
// Functions: 14
// ============================================================

#include "movieobjects\dmeconnectionoperator.h"

//------------------------------------------------------------------------------
// Address: 0x0055B4D0
// Name: public: virtual bool CDmeConnectionOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeConnectionOperator::IsDirty(CDmeConnectionOperator *this)
{
  CDmeAttributeReference *v1; // eax
  CDmAttribute *ReferencedAttribute; // eax

  v1 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v1);
  return ReferencedAttribute != nullptr && (ReferencedAttribute->m_nFlags & 0x80) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0055B5A0
// Name: protected: void CDmeConnectionOperator::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::OnDestruction(CDmeConnectionOperator *this)
{
  int m_Size; // esi
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  CExpressionCalculator *v7; // ecx
  IDataModel_vtbl *v8; // esi
  int v9; // eax
  int nOutputs; // [esp+Ch] [ebp-4h]

  g_pDataModel->DestroyElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  m_Size = this->m_Outputs.m_Storage.m_Size;
  v3 = 0;
  for ( nOutputs = m_Size; v3 < m_Size; ++v3 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v3]);
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeAttributeReference::m_classType) )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v3]);
      v6 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeAttributeReference::m_classType) )
        v7 = (CExpressionCalculator *)v6;
      else
        v7 = nullptr;
      v8 = g_pDataModel->__vftable;
      v9 = CExpressionCalculator::VariableCount(this: v7);
      v8->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v9);
      m_Size = nOutputs;
    }
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &this->m_Outputs);
}

//------------------------------------------------------------------------------
// Address: 0x0055B670
// Name: public: virtual void CDmeConnectionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::Operate(CDmeConnectionOperator *this)
{
  CDmeAttributeReference *v2; // eax
  int m_Size; // esi
  int v4; // edi
  DmElementHandle_t m_Handle; // eax
  CDmeAttributeReference *v6; // eax
  CDmElement *v7; // eax
  CDmeAttributeReference *v8; // esi
  CDmeAttributeReference *v9; // ecx
  int nOutputs; // [esp+Ch] [ebp-Ch]
  const void *pValue; // [esp+10h] [ebp-8h]
  DmAttributeType_t inputType; // [esp+14h] [ebp-4h] BYREF

  v2 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  if ( CDmeAttributeReference::IsValid(this: v2) )
  {
    m_Size = this->m_Outputs.m_Storage.m_Size;
    v4 = 0;
    nOutputs = m_Size;
    if ( m_Size != 0 )
    {
      m_Handle = this->m_Input.m_Storage.m_Handle;
      inputType = AT_UNKNOWN;
      v6 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
      pValue = CDmeAttributeReference::GetAttributeValue(this: v6, type: &inputType);
      if ( m_Size > 0 )
      {
        do
        {
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v4]);
          v8 = (CDmeAttributeReference *)v7;
          if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeAttributeReference::m_classType) )
            v9 = v8;
          else
            v9 = nullptr;
          CDmeAttributeReference::SetAttributeValue(this: v9, pValue, type: inputType);
          ++v4;
        }
        while ( v4 < nOutputs );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055B730
// Name: public: virtual void CDmeConnectionOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::GetInputAttributes(
        CDmeConnectionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmeAttributeReference *v2; // eax
  CDmAttribute *ReferencedAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax

  v2 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v2);
  if ( ReferencedAttribute != nullptr )
  {
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    m_Size = attrs->m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: m_Size - m_nAllocationCount + 1);
    ++attrs->m_Size;
    m_pMemory = attrs->m_Memory.m_pMemory;
    v7 = attrs->m_Size - m_Size - 1;
    attrs->m_pElements = attrs->m_Memory.m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
    v8 = &attrs->m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      *v8 = ReferencedAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055B7B0
// Name: public: virtual void CDmeConnectionOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::GetOutputAttributes(
        CDmeConnectionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // eax
  CDmeAttributeReference *v3; // edi
  CDmeAttributeReference *v4; // ecx
  CDmAttribute *ReferencedAttribute; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v9; // eax
  CDmAttribute **v10; // eax
  int nOutputs; // [esp+Ch] [ebp-Ch]
  CDmeConnectionOperator *v12; // [esp+10h] [ebp-8h]
  int iOutput; // [esp+14h] [ebp-4h]

  v12 = this;
  nOutputs = this->m_Outputs.m_Storage.m_Size;
  iOutput = 0;
  if ( nOutputs > 0 )
  {
    while ( 1 )
    {
      v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[iOutput]);
      v3 = (CDmeAttributeReference *)v2;
      if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeAttributeReference::m_classType) )
        v4 = v3;
      else
        v4 = nullptr;
      ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v4);
      if ( ReferencedAttribute != nullptr )
      {
        m_Size = attrs->m_Size;
        m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
            num: m_Size - m_nAllocationCount + 1);
        ++attrs->m_Size;
        m_pMemory = attrs->m_Memory.m_pMemory;
        v9 = attrs->m_Size - m_Size - 1;
        attrs->m_pElements = attrs->m_Memory.m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
        v10 = &attrs->m_Memory.m_pMemory[m_Size];
        if ( v10 != nullptr )
          *v10 = ReferencedAttribute;
      }
      if ( ++iOutput >= nOutputs )
        break;
      this = v12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055B930
// Name: public: virtual bool CDmeConnectionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeConnectionOperator::IsA(CDmeConnectionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeConnectionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055B960
// Name: public: virtual int CDmeConnectionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeConnectionOperator::GetInheritanceDepth(CDmeConnectionOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeConnectionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055B9B0
// Name: protected: virtual void CDmeConnectionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::PerformConstruction(CDmeConnectionOperator *this)
{
  char *v2; // esi
  CDmElement *v3; // eax
  CDmElement *v4; // ecx
  CDmAttribute **v5; // esi

  CDmeFXClip::OnDestruction();
  v2 = (char *)this - 4;
  CDmeOperator::OnConstruction(this: (CDmeOperator *)v2);
  if ( v2 != nullptr )
    v3 = (CDmElement *)(v2 + 4);
  else
    v3 = nullptr;
  CDmaElement<CDmeAttributeReference>::InitAndCreate(
    this: (CDmaElement<CDmeAttributeReference> *)(v2 + 76),
    pOwner: v3,
    pAttributeName: (DmElementHandle_t)"input",
    pElementName: nullptr,
    flags: 0);
  if ( v2 != nullptr )
    v4 = (CDmElement *)(v2 + 4);
  else
    v4 = nullptr;
  v5 = (CDmAttribute **)(v2 + 88);
  v5[6] = CDmElement::AddExternalAttribute(this: v4, pAttributeName: "outputs", type: AT_FIRST_ARRAY_TYPE, pMemory: v5);
  CDmAttribute::SetElementTypeSymbol(this: v5[6], typeSymbol: CDmeAttributeReference::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0055BA20
// Name: protected: virtual void CDmeConnectionOperator::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::PerformDestruction(CDmeConnectionOperator *this)
{
  CDmeConnectionOperator::OnDestruction(this: (CDmeConnectionOperator *)((char *)this - 4));
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x005ADE30
// Name: _dynamic_initializer_for__CDmeConnectionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeConnectionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeConnectionOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeConnectionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005B0610
// Name: _dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeConnectionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ADE60
// Name: _dynamic_initializer_for__g_CDmeConnectionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeConnectionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ADE70
// Name: _dynamic_initializer_for__g_CDmeConnectionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeConnectionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeConnectionOperator_Helper,
           classname: "DmeConnectionOperator",
           pFactory: &g_CDmeConnectionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005B0620
// Name: _dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeConnectionOperator_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005B2600
// Name: public: virtual bool CDmeConnectionOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeConnectionOperator::IsDirty(CDmeConnectionOperator *this)
{
  CDmeAttributeReference *v1; // eax
  CDmAttribute *ReferencedAttribute; // eax

  v1 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v1);
  return ReferencedAttribute != nullptr && (ReferencedAttribute->m_nFlags & 0x80) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x005B26D0
// Name: protected: void CDmeConnectionOperator::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::OnDestruction(CDmeConnectionOperator *this)
{
  int m_Size; // esi
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  CExpressionCalculator *v7; // ecx
  IDataModel_vtbl *v8; // esi
  int BufferType; // eax
  int nOutputs; // [esp+Ch] [ebp-4h]

  g_pDataModel->DestroyElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  m_Size = this->m_Outputs.m_Storage.m_Size;
  v3 = 0;
  for ( nOutputs = m_Size; v3 < m_Size; ++v3 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v3]);
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeAttributeReference::m_classType) )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v3]);
      v6 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeAttributeReference::m_classType) )
        v7 = (CExpressionCalculator *)v6;
      else
        v7 = nullptr;
      v8 = g_pDataModel->__vftable;
      BufferType = CCodecBuffer_Block::GetBufferType(this: v7);
      v8->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
      m_Size = nOutputs;
    }
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &this->m_Outputs);
}

//------------------------------------------------------------------------------
// Address: 0x005B27A0
// Name: public: virtual void CDmeConnectionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::Operate(CDmeConnectionOperator *this)
{
  CDmeAttributeReference *v2; // eax
  int m_Size; // esi
  int v4; // edi
  DmElementHandle_t m_Handle; // eax
  CDmeAttributeReference *v6; // eax
  CDmElement *v7; // eax
  CDmeAttributeReference *v8; // esi
  CDmeAttributeReference *v9; // ecx
  int nOutputs; // [esp+Ch] [ebp-Ch]
  const void *pValue; // [esp+10h] [ebp-8h]
  DmAttributeType_t inputType; // [esp+14h] [ebp-4h] BYREF

  v2 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  if ( CDmeAttributeReference::IsValid(this: v2) )
  {
    m_Size = this->m_Outputs.m_Storage.m_Size;
    v4 = 0;
    nOutputs = m_Size;
    if ( m_Size != 0 )
    {
      m_Handle = this->m_Input.m_Storage.m_Handle;
      inputType = AT_UNKNOWN;
      v6 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
      pValue = CDmeAttributeReference::GetAttributeValue(this: v6, type: &inputType);
      if ( m_Size > 0 )
      {
        do
        {
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v4]);
          v8 = (CDmeAttributeReference *)v7;
          if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeAttributeReference::m_classType) )
            v9 = v8;
          else
            v9 = nullptr;
          CDmeAttributeReference::SetAttributeValue(this: v9, pValue, type: inputType);
          ++v4;
        }
        while ( v4 < nOutputs );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B2860
// Name: public: virtual void CDmeConnectionOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::GetInputAttributes(
        CDmeConnectionOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmeAttributeReference *v2; // eax
  CDmAttribute *ReferencedAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v6; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax

  v2 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v2);
  if ( ReferencedAttribute != nullptr )
  {
    m_nAllocationCount = attrs->m_nAllocationCount;
    m_pMemory = (int)attrs[1].m_pMemory;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v6 = (CDmAttribute **)attrs->m_pMemory;
    v7 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &v6[m_pMemory + 1], src: &v6[m_pMemory], count: 4 * v7);
    v8 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v8 != nullptr )
      *v8 = ReferencedAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B28E0
// Name: public: virtual void CDmeConnectionOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::GetOutputAttributes(
        CDmeConnectionOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmElement *v2; // eax
  CDmeAttributeReference *v3; // edi
  CDmeAttributeReference *v4; // ecx
  CDmAttribute *ReferencedAttribute; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v8; // ecx
  int v9; // eax
  CDmAttribute **v10; // eax
  int nOutputs; // [esp+Ch] [ebp-Ch]
  CDmeConnectionOperator *v12; // [esp+10h] [ebp-8h]
  int iOutput; // [esp+14h] [ebp-4h]

  v12 = this;
  nOutputs = this->m_Outputs.m_Storage.m_Size;
  iOutput = 0;
  if ( nOutputs > 0 )
  {
    while ( 1 )
    {
      v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[iOutput]);
      v3 = (CDmeAttributeReference *)v2;
      if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeAttributeReference::m_classType) )
        v4 = v3;
      else
        v4 = nullptr;
      ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v4);
      if ( ReferencedAttribute != nullptr )
      {
        m_pMemory = (int)attrs[1].m_pMemory;
        m_nAllocationCount = attrs->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
        ++attrs[1].m_pMemory;
        v8 = (CDmAttribute **)attrs->m_pMemory;
        v9 = (int)attrs[1].m_pMemory - m_pMemory - 1;
        attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: &v8[m_pMemory + 1], src: &v8[m_pMemory], count: 4 * v9);
        v10 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
        if ( v10 != nullptr )
          *v10 = ReferencedAttribute;
      }
      if ( ++iOutput >= nOutputs )
        break;
      this = v12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B2A30
// Name: public: virtual bool CDmeConnectionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeConnectionOperator::IsA(CDmeConnectionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeConnectionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B2A60
// Name: public: virtual int CDmeConnectionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeConnectionOperator::GetInheritanceDepth(CDmeConnectionOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeConnectionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B2AB0
// Name: protected: virtual void CDmeConnectionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::PerformConstruction(CDmeConnectionOperator *this)
{
  char *v2; // esi
  CDmElement *v3; // eax
  CDmElement *v4; // ecx
  CDmAttribute **v5; // esi

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  v2 = (char *)this - 4;
  CDmeOperator::OnConstruction(this: (CDmeOperator *)v2);
  if ( v2 != nullptr )
    v3 = (CDmElement *)(v2 + 4);
  else
    v3 = nullptr;
  CDmaElement<CDmeAttributeReference>::InitAndCreate(
    this: (CDmaElement<CDmeAttributeReference> *)(v2 + 76),
    pOwner: v3,
    pAttributeName: (DmElementHandle_t)"input",
    pElementName: nullptr,
    flags: 0);
  if ( v2 != nullptr )
    v4 = (CDmElement *)(v2 + 4);
  else
    v4 = nullptr;
  v5 = (CDmAttribute **)(v2 + 88);
  v5[6] = CDmElement::AddExternalAttribute(this: v4, pAttributeName: "outputs", type: AT_FIRST_ARRAY_TYPE, pMemory: v5);
  CDmAttribute::SetElementTypeSymbol(this: v5[6], typeSymbol: CDmeAttributeReference::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005B2B20
// Name: protected: virtual void CDmeConnectionOperator::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::PerformDestruction(CDmeConnectionOperator *this)
{
  CDmeConnectionOperator::OnDestruction(this: (CDmeConnectionOperator *)((char *)this - 4));
  CDmeFXClip::OnDestruction(this: (vgui::PropertyPage *)((char *)this - 4));
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0067F620
// Name: _dynamic_initializer_for__CDmeConnectionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeConnectionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeConnectionOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeConnectionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00682B20
// Name: _dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeConnectionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067F650
// Name: _dynamic_initializer_for__g_CDmeConnectionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeConnectionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F660
// Name: _dynamic_initializer_for__g_CDmeConnectionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeConnectionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeConnectionOperator_Helper,
           classname: "DmeConnectionOperator",
           pFactory: &g_CDmeConnectionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00682B30
// Name: _dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeConnectionOperator_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0055F370
// Name: public: virtual bool CDmeConnectionOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeConnectionOperator::IsDirty(CDmeConnectionOperator *this)
{
  CDmeAttributeReference *v1; // eax
  CDmAttribute *ReferencedAttribute; // eax

  v1 = (CDmeAttributeReference *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                   a1: g_pDataModel.u,
                                   a2: this->m_Input.m_Storage.m_Handle);
  ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v1);
  return ReferencedAttribute != nullptr && (ReferencedAttribute->m_nFlags & 0x80) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0055F440
// Name: protected: void CDmeConnectionOperator::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::OnDestruction(CDmeConnectionOperator *this)
{
  int m_Size; // esi
  int v3; // edi
  int v4; // eax
  int v5; // eax
  CDmElement *v6; // esi
  CDmElement *v7; // ecx
  int v8; // esi
  DmElementHandle_t Handle; // eax
  int nOutputs; // [esp+Ch] [ebp-4h]

  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 68))(
    a1: g_pDataModel.u,
    a2: this->m_Input.m_Storage.m_Handle);
  m_Size = this->m_Outputs.m_Storage.m_Size;
  v3 = 0;
  for ( nOutputs = m_Size; v3 < m_Size; ++v3 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v3]);
    if ( v4 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeAttributeReference::m_classType.u) != 0 )
    {
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v3]);
      v6 = (CDmElement *)v5;
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
             a1: v5,
             a2: CDmeAttributeReference::m_classType.u) != 0 )
      {
        v7 = v6;
      }
      else
      {
        v7 = nullptr;
      }
      v8 = *(_DWORD *)g_pDataModel.u.m_Id;
      Handle = CDmElement::GetHandle(this: v7);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(v8 + 68))(
        a1: g_pDataModel.u,
        a2: Handle);
      m_Size = nOutputs;
    }
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &this->m_Outputs);
}

//------------------------------------------------------------------------------
// Address: 0x0055F510
// Name: public: virtual void CDmeConnectionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::Operate(CDmeConnectionOperator *this)
{
  CDmeAttributeReference *v2; // eax
  int m_Size; // esi
  int v4; // edi
  DmElementHandle_t m_Handle; // eax
  CDmeAttributeReference *v6; // eax
  int v7; // eax
  CDmeAttributeReference *v8; // esi
  CDmeAttributeReference *v9; // ecx
  int nOutputs; // [esp+Ch] [ebp-Ch]
  int *pValue; // [esp+10h] [ebp-8h]
  DmAttributeType_t inputType; // [esp+14h] [ebp-4h] BYREF

  v2 = (CDmeAttributeReference *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                   a1: g_pDataModel.u,
                                   a2: this->m_Input.m_Storage.m_Handle);
  if ( CDmeAttributeReference::IsValid(this: v2) )
  {
    m_Size = this->m_Outputs.m_Storage.m_Size;
    v4 = 0;
    nOutputs = m_Size;
    if ( m_Size != 0 )
    {
      m_Handle = this->m_Input.m_Storage.m_Handle;
      inputType = AT_UNKNOWN;
      v6 = (CDmeAttributeReference *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                       a1: g_pDataModel.u,
                                       a2: m_Handle);
      pValue = CDmeAttributeReference::GetAttributeValue(this: v6, type: &inputType);
      if ( m_Size > 0 )
      {
        do
        {
          v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v4]);
          v8 = (CDmeAttributeReference *)v7;
          if ( v7 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                 a1: v7,
                 a2: CDmeAttributeReference::m_classType.u) != 0 )
          {
            v9 = v8;
          }
          else
          {
            v9 = nullptr;
          }
          CDmeAttributeReference::SetAttributeValue(this: v9, pValue, type: inputType);
          ++v4;
        }
        while ( v4 < nOutputs );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055F5D0
// Name: public: virtual void CDmeConnectionOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::GetInputAttributes(
        CDmeConnectionOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  CDmeAttributeReference *v2; // eax
  CDmAttribute *ReferencedAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v6; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax

  v2 = (CDmeAttributeReference *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                   a1: g_pDataModel.u,
                                   a2: this->m_Input.m_Storage.m_Handle);
  ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v2);
  if ( ReferencedAttribute != nullptr )
  {
    m_nAllocationCount = attrs->m_nAllocationCount;
    m_pMemory = (int)attrs[1].m_pMemory;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v6 = (CDmAttribute **)attrs->m_pMemory;
    v7 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &v6[m_pMemory + 1], src: &v6[m_pMemory], count: 4 * v7);
    v8 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v8 != nullptr )
      *v8 = ReferencedAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055F650
// Name: public: virtual void CDmeConnectionOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::GetOutputAttributes(
        CDmeConnectionOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  int v2; // eax
  CDmeAttributeReference *v3; // edi
  CDmeAttributeReference *v4; // ecx
  CDmAttribute *ReferencedAttribute; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v8; // ecx
  int v9; // eax
  CDmAttribute **v10; // eax
  int nOutputs; // [esp+Ch] [ebp-Ch]
  CDmeConnectionOperator *v12; // [esp+10h] [ebp-8h]
  int iOutput; // [esp+14h] [ebp-4h]

  v12 = this;
  nOutputs = this->m_Outputs.m_Storage.m_Size;
  iOutput = 0;
  if ( nOutputs > 0 )
  {
    while ( 1 )
    {
      v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[iOutput]);
      v3 = (CDmeAttributeReference *)v2;
      if ( v2 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
             a1: v2,
             a2: CDmeAttributeReference::m_classType.u) != 0 )
      {
        v4 = v3;
      }
      else
      {
        v4 = nullptr;
      }
      ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v4);
      if ( ReferencedAttribute != nullptr )
      {
        m_pMemory = (int)attrs[1].m_pMemory;
        m_nAllocationCount = attrs->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
        ++attrs[1].m_pMemory;
        v8 = (CDmAttribute **)attrs->m_pMemory;
        v9 = (int)attrs[1].m_pMemory - m_pMemory - 1;
        attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: &v8[m_pMemory + 1], src: &v8[m_pMemory], count: 4 * v9);
        v10 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
        if ( v10 != nullptr )
          *v10 = ReferencedAttribute;
      }
      if ( ++iOutput >= nOutputs )
        break;
      this = v12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055F7A0
// Name: public: virtual bool CDmeConnectionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeConnectionOperator::IsA(CDmeConnectionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeConnectionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055F7D0
// Name: public: virtual int CDmeConnectionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeConnectionOperator::GetInheritanceDepth(CDmeConnectionOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeConnectionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055F820
// Name: protected: virtual void CDmeConnectionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::PerformConstruction(CDmeConnectionOperator *this)
{
  char *v2; // esi
  CDmElement *v3; // eax
  CDmElement *v4; // ecx
  CDmAttribute **v5; // esi

  CDmeFXClip::OnDestruction();
  v2 = (char *)this - 4;
  CDmeOperator::OnConstruction(this: (CDmeOperator *)v2);
  if ( v2 != nullptr )
    v3 = (CDmElement *)(v2 + 4);
  else
    v3 = nullptr;
  CDmaElement<CDmeAttributeReference>::InitAndCreate(
    this: (CDmaElement<CDmeAttributeReference> *)(v2 + 76),
    pOwner: v3,
    pAttributeName: (DmElementHandle_t)"input",
    pElementName: nullptr,
    flags: 0);
  if ( v2 != nullptr )
    v4 = (CDmElement *)(v2 + 4);
  else
    v4 = nullptr;
  v5 = (CDmAttribute **)(v2 + 88);
  v5[6] = CDmElement::AddExternalAttribute(this: v4, pAttributeName: "outputs", type: AT_FIRST_ARRAY_TYPE, pMemory: v5);
  CDmAttribute::SetElementTypeSymbol(this: v5[6], typeSymbol: CDmeAttributeReference::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0055F890
// Name: protected: virtual void CDmeConnectionOperator::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::PerformDestruction(CDmeConnectionOperator *this)
{
  CDmeConnectionOperator::OnDestruction(this: (CDmeConnectionOperator *)((char *)this - 4));
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x0059CAB0
// Name: _dynamic_initializer_for__CDmeConnectionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeConnectionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeConnectionOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeConnectionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059F620
// Name: _dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeConnectionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059CAE0
// Name: _dynamic_initializer_for__g_CDmeConnectionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeConnectionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059CAF0
// Name: _dynamic_initializer_for__g_CDmeConnectionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeConnectionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeConnectionOperator_Helper,
           classname: "DmeConnectionOperator",
           pFactory: &g_CDmeConnectionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059F630
// Name: _dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeConnectionOperator_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004F2940
// Name: protected: virtual int CDmeOperator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeOperator::AllocatedSize(CDmeOperator *this)
{
  return 76;
}

//------------------------------------------------------------------------------
// Address: 0x004F45F0
// Name: public: virtual bool CDmeConnectionOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeConnectionOperator::IsDirty(CDmeConnectionOperator *this)
{
  CDmeAttributeReference *v1; // eax
  CDmAttribute *ReferencedAttribute; // eax

  v1 = (CDmeAttributeReference *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                   a1: g_pDataModel.u,
                                   a2: this->m_Input.m_Storage.m_Handle);
  ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v1);
  return ReferencedAttribute != nullptr && (ReferencedAttribute->m_nFlags & 0x80) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004F46C0
// Name: protected: void CDmeConnectionOperator::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::OnDestruction(CDmeConnectionOperator *this)
{
  int m_Size; // esi
  int v3; // edi
  int v4; // eax
  int v5; // eax
  CExpressionCalculator *v6; // esi
  CExpressionCalculator *v7; // ecx
  int v8; // esi
  int v9; // eax
  int nOutputs; // [esp+Ch] [ebp-4h]

  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 68))(
    a1: g_pDataModel.u,
    a2: this->m_Input.m_Storage.m_Handle);
  m_Size = this->m_Outputs.m_Storage.m_Size;
  v3 = 0;
  for ( nOutputs = m_Size; v3 < m_Size; ++v3 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v3]);
    if ( v4 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeAttributeReference::m_classType.u) != 0 )
    {
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v3]);
      v6 = (CExpressionCalculator *)v5;
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
             a1: v5,
             a2: CDmeAttributeReference::m_classType.u) != 0 )
      {
        v7 = v6;
      }
      else
      {
        v7 = nullptr;
      }
      v8 = *(_DWORD *)g_pDataModel.u.m_Id;
      v9 = CExpressionCalculator::VariableCount(this: v7);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v8 + 68))(a1: g_pDataModel.u, a2: v9);
      m_Size = nOutputs;
    }
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &this->m_Outputs);
}

//------------------------------------------------------------------------------
// Address: 0x004F4790
// Name: public: virtual void CDmeConnectionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::Operate(CDmeConnectionOperator *this)
{
  CDmeAttributeReference *v2; // eax
  int m_Size; // esi
  int v4; // edi
  DmElementHandle_t m_Handle; // eax
  CDmeAttributeReference *v6; // eax
  int v7; // eax
  CDmeAttributeReference *v8; // esi
  CDmeAttributeReference *v9; // ecx
  int nOutputs; // [esp+Ch] [ebp-Ch]
  const void *pValue; // [esp+10h] [ebp-8h]
  DmAttributeType_t inputType; // [esp+14h] [ebp-4h] BYREF

  v2 = (CDmeAttributeReference *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                   a1: g_pDataModel.u,
                                   a2: this->m_Input.m_Storage.m_Handle);
  if ( CDmeAttributeReference::IsValid(this: v2) )
  {
    m_Size = this->m_Outputs.m_Storage.m_Size;
    v4 = 0;
    nOutputs = m_Size;
    if ( m_Size != 0 )
    {
      m_Handle = this->m_Input.m_Storage.m_Handle;
      inputType = AT_UNKNOWN;
      v6 = (CDmeAttributeReference *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                       a1: g_pDataModel.u,
                                       a2: m_Handle);
      pValue = CDmeAttributeReference::GetAttributeValue(this: v6, type: &inputType);
      if ( m_Size > 0 )
      {
        do
        {
          v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v4]);
          v8 = (CDmeAttributeReference *)v7;
          if ( v7 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                 a1: v7,
                 a2: CDmeAttributeReference::m_classType.u) != 0 )
          {
            v9 = v8;
          }
          else
          {
            v9 = nullptr;
          }
          CDmeAttributeReference::SetAttributeValue(this: v9, pValue, type: inputType);
          ++v4;
        }
        while ( v4 < nOutputs );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F4850
// Name: public: virtual void CDmeConnectionOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::GetInputAttributes(
        CDmeConnectionOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  CDmeAttributeReference *v2; // eax
  CDmAttribute *ReferencedAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v6; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax

  v2 = (CDmeAttributeReference *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                   a1: g_pDataModel.u,
                                   a2: this->m_Input.m_Storage.m_Handle);
  ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v2);
  if ( ReferencedAttribute != nullptr )
  {
    m_nAllocationCount = attrs->m_nAllocationCount;
    m_pMemory = (int)attrs[1].m_pMemory;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v6 = (CDmAttribute **)attrs->m_pMemory;
    v7 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &v6[m_pMemory + 1], src: &v6[m_pMemory], count: 4 * v7);
    v8 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v8 != nullptr )
      *v8 = ReferencedAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F48D0
// Name: public: virtual void CDmeConnectionOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::GetOutputAttributes(
        CDmeConnectionOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  int v2; // eax
  CDmeAttributeReference *v3; // edi
  CDmeAttributeReference *v4; // ecx
  CDmAttribute *ReferencedAttribute; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v8; // ecx
  int v9; // eax
  CDmAttribute **v10; // eax
  int nOutputs; // [esp+Ch] [ebp-Ch]
  CDmeConnectionOperator *v12; // [esp+10h] [ebp-8h]
  int iOutput; // [esp+14h] [ebp-4h]

  v12 = this;
  nOutputs = this->m_Outputs.m_Storage.m_Size;
  iOutput = 0;
  if ( nOutputs > 0 )
  {
    while ( 1 )
    {
      v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[iOutput]);
      v3 = (CDmeAttributeReference *)v2;
      if ( v2 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
             a1: v2,
             a2: CDmeAttributeReference::m_classType.u) != 0 )
      {
        v4 = v3;
      }
      else
      {
        v4 = nullptr;
      }
      ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v4);
      if ( ReferencedAttribute != nullptr )
      {
        m_pMemory = (int)attrs[1].m_pMemory;
        m_nAllocationCount = attrs->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
        ++attrs[1].m_pMemory;
        v8 = (CDmAttribute **)attrs->m_pMemory;
        v9 = (int)attrs[1].m_pMemory - m_pMemory - 1;
        attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: &v8[m_pMemory + 1], src: &v8[m_pMemory], count: 4 * v9);
        v10 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
        if ( v10 != nullptr )
          *v10 = ReferencedAttribute;
      }
      if ( ++iOutput >= nOutputs )
        break;
      this = v12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004F49B0
// Name: protected: virtual void CDmeOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::PerformConstruction(CDmeOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x004F49D0
// Name: public: virtual char const __near * IDmeOperator::GetOperatorName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall IDmeOperator::GetOperatorName(IDmeOperator *this)
{
  return "Unknown";
}

//------------------------------------------------------------------------------
// Address: 0x004F4A90
// Name: public: virtual bool CDmeOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeOperator::IsA(CDmeOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004F4AC0
// Name: public: virtual int CDmeOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeOperator::GetInheritanceDepth(CDmeOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004F4B00
// Name: public: virtual char const __near * CDmeOperator::GetOperatorName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeOperator::GetOperatorName(CDmeOperator *this)
{
  const char *result; // eax

  result = this->m_Name.m_Storage.u.m_pAsString;
  if ( result == (const char *)-1 )
    return pDeltaStateName;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004F4B20
// Name: public: virtual bool CDmeConnectionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeConnectionOperator::IsA(CDmeConnectionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeConnectionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004F4B50
// Name: public: virtual int CDmeConnectionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeConnectionOperator::GetInheritanceDepth(CDmeConnectionOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeConnectionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004F4BA0
// Name: protected: virtual void CDmeConnectionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::PerformConstruction(CDmeConnectionOperator *this)
{
  char *v2; // esi
  CDmElement *v3; // eax
  CDmElement *v4; // ecx
  CDmAttribute **v5; // esi

  CDmeFXClip::OnDestruction();
  v2 = (char *)this - 4;
  CDmeOperator::OnConstruction(this: (CDmeOperator *)v2);
  if ( v2 != nullptr )
    v3 = (CDmElement *)(v2 + 4);
  else
    v3 = nullptr;
  CDmaElement<CDmeAttributeReference>::InitAndCreate(
    this: (CDmaElement<CDmeAttributeReference> *)(v2 + 76),
    pOwner: v3,
    pAttributeName: (DmElementHandle_t)"input",
    pElementName: nullptr,
    flags: 0);
  if ( v2 != nullptr )
    v4 = (CDmElement *)(v2 + 4);
  else
    v4 = nullptr;
  v5 = (CDmAttribute **)(v2 + 88);
  v5[6] = CDmElement::AddExternalAttribute(this: v4, pAttributeName: "outputs", type: AT_FIRST_ARRAY_TYPE, pMemory: v5);
  CDmAttribute::SetElementTypeSymbol(this: v5[6], typeSymbol: CDmeAttributeReference::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004F4C10
// Name: protected: virtual void CDmeConnectionOperator::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::PerformDestruction(CDmeConnectionOperator *this)
{
  CDmeConnectionOperator::OnDestruction(this: (CDmeConnectionOperator *)((char *)this - 4));
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x005AD030
// Name: protected: virtual void CDmeOperator::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::PerformDestruction(CDmeGlobalFlexControllerOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x005EF2E0
// Name: _dynamic_initializer_for__CDmeOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeOperator::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EF340
// Name: _dynamic_initializer_for__CDmeConnectionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeConnectionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeConnectionOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeConnectionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F3CD0
// Name: _dynamic_atexit_destructor_for__CDmeOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F3CF0
// Name: _dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeConnectionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EF310
// Name: _dynamic_initializer_for__g_CDmeOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EF320
// Name: _dynamic_initializer_for__g_CDmeOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeOperator_Helper,
           classname: "DmeOperator",
           pFactory: &g_CDmeOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EF370
// Name: _dynamic_initializer_for__g_CDmeConnectionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeConnectionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EF380
// Name: _dynamic_initializer_for__g_CDmeConnectionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeConnectionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeConnectionOperator_Helper,
           classname: "DmeConnectionOperator",
           pFactory: &g_CDmeConnectionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F3CE0
// Name: _dynamic_atexit_destructor_for__g_CDmeOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeOperator_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F3D00
// Name: _dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeConnectionOperator_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0051CD50
// Name: public: virtual bool CDmeConnectionOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeConnectionOperator::IsDirty(CDmeConnectionOperator *this)
{
  CDmeAttributeReference *v1; // eax
  CDmAttribute *ReferencedAttribute; // eax

  v1 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v1);
  return ReferencedAttribute != nullptr && (ReferencedAttribute->m_nFlags & 0x80) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0051CE20
// Name: protected: void CDmeConnectionOperator::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::OnDestruction(CDmeConnectionOperator *this)
{
  int m_Size; // esi
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  CExpressionCalculator *v7; // ecx
  IDataModel_vtbl *v8; // esi
  int v9; // eax
  int nOutputs; // [esp+Ch] [ebp-4h]

  g_pDataModel->DestroyElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  m_Size = this->m_Outputs.m_Storage.m_Size;
  v3 = 0;
  for ( nOutputs = m_Size; v3 < m_Size; ++v3 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v3]);
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeAttributeReference::m_classType) )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v3]);
      v6 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeAttributeReference::m_classType) )
        v7 = (CExpressionCalculator *)v6;
      else
        v7 = nullptr;
      v8 = g_pDataModel->__vftable;
      v9 = CExpressionCalculator::VariableCount(this: v7);
      v8->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v9);
      m_Size = nOutputs;
    }
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &this->m_Outputs);
}

//------------------------------------------------------------------------------
// Address: 0x0051CEF0
// Name: public: virtual void CDmeConnectionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::Operate(CDmeConnectionOperator *this)
{
  CDmeAttributeReference *v2; // eax
  int m_Size; // esi
  int v4; // edi
  DmElementHandle_t m_Handle; // eax
  CDmeAttributeReference *v6; // eax
  CDmElement *v7; // eax
  CDmeAttributeReference *v8; // esi
  CDmeAttributeReference *v9; // ecx
  int nOutputs; // [esp+Ch] [ebp-Ch]
  const void *pValue; // [esp+10h] [ebp-8h]
  DmAttributeType_t inputType; // [esp+14h] [ebp-4h] BYREF

  v2 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  if ( CDmeAttributeReference::IsValid(this: v2) )
  {
    m_Size = this->m_Outputs.m_Storage.m_Size;
    v4 = 0;
    nOutputs = m_Size;
    if ( m_Size != 0 )
    {
      m_Handle = this->m_Input.m_Storage.m_Handle;
      inputType = AT_UNKNOWN;
      v6 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
      pValue = CDmeAttributeReference::GetAttributeValue(this: v6, type: &inputType);
      if ( m_Size > 0 )
      {
        do
        {
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v4]);
          v8 = (CDmeAttributeReference *)v7;
          if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeAttributeReference::m_classType) )
            v9 = v8;
          else
            v9 = nullptr;
          CDmeAttributeReference::SetAttributeValue(this: v9, pValue, type: inputType);
          ++v4;
        }
        while ( v4 < nOutputs );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051CFB0
// Name: public: virtual void CDmeConnectionOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::GetInputAttributes(
        CDmeConnectionOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  CDmeAttributeReference *v2; // eax
  CDmAttribute *ReferencedAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v6; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax

  v2 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v2);
  if ( ReferencedAttribute != nullptr )
  {
    m_nAllocationCount = attrs->m_nAllocationCount;
    m_pMemory = (int)attrs[1].m_pMemory;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v6 = (CDmAttribute **)attrs->m_pMemory;
    v7 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &v6[m_pMemory + 1], src: &v6[m_pMemory], count: 4 * v7);
    v8 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v8 != nullptr )
      *v8 = ReferencedAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051D030
// Name: public: virtual void CDmeConnectionOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::GetOutputAttributes(
        CDmeConnectionOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  CDmElement *v2; // eax
  CDmeAttributeReference *v3; // edi
  CDmeAttributeReference *v4; // ecx
  CDmAttribute *ReferencedAttribute; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v8; // ecx
  int v9; // eax
  CDmAttribute **v10; // eax
  int nOutputs; // [esp+Ch] [ebp-Ch]
  CDmeConnectionOperator *v12; // [esp+10h] [ebp-8h]
  int iOutput; // [esp+14h] [ebp-4h]

  v12 = this;
  nOutputs = this->m_Outputs.m_Storage.m_Size;
  iOutput = 0;
  if ( nOutputs > 0 )
  {
    while ( 1 )
    {
      v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[iOutput]);
      v3 = (CDmeAttributeReference *)v2;
      if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeAttributeReference::m_classType) )
        v4 = v3;
      else
        v4 = nullptr;
      ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v4);
      if ( ReferencedAttribute != nullptr )
      {
        m_pMemory = (int)attrs[1].m_pMemory;
        m_nAllocationCount = attrs->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
        ++attrs[1].m_pMemory;
        v8 = (CDmAttribute **)attrs->m_pMemory;
        v9 = (int)attrs[1].m_pMemory - m_pMemory - 1;
        attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: &v8[m_pMemory + 1], src: &v8[m_pMemory], count: 4 * v9);
        v10 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
        if ( v10 != nullptr )
          *v10 = ReferencedAttribute;
      }
      if ( ++iOutput >= nOutputs )
        break;
      this = v12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051D180
// Name: public: virtual bool CDmeConnectionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeConnectionOperator::IsA(CDmeConnectionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeConnectionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051D1B0
// Name: public: virtual int CDmeConnectionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeConnectionOperator::GetInheritanceDepth(CDmeConnectionOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeConnectionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051D200
// Name: protected: virtual void CDmeConnectionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::PerformConstruction(CDmeConnectionOperator *this)
{
  char *v2; // esi
  CDmElement *v3; // eax
  CDmElement *v4; // ecx
  CDmAttribute **v5; // esi

  CDmeFXClip::OnDestruction();
  v2 = (char *)this - 4;
  CDmeOperator::OnConstruction(this: (CDmeOperator *)v2);
  if ( v2 != nullptr )
    v3 = (CDmElement *)(v2 + 4);
  else
    v3 = nullptr;
  CDmaElement<CDmeAttributeReference>::InitAndCreate(
    this: (CDmaElement<CDmeAttributeReference> *)(v2 + 76),
    pOwner: v3,
    pAttributeName: (DmElementHandle_t)"input",
    pElementName: nullptr,
    flags: 0);
  if ( v2 != nullptr )
    v4 = (CDmElement *)(v2 + 4);
  else
    v4 = nullptr;
  v5 = (CDmAttribute **)(v2 + 88);
  v5[6] = CDmElement::AddExternalAttribute(this: v4, pAttributeName: "outputs", type: AT_FIRST_ARRAY_TYPE, pMemory: v5);
  CDmAttribute::SetElementTypeSymbol(this: v5[6], typeSymbol: CDmeAttributeReference::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0051D270
// Name: protected: virtual void CDmeConnectionOperator::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::PerformDestruction(CDmeConnectionOperator *this)
{
  CDmeConnectionOperator::OnDestruction(this: (CDmeConnectionOperator *)((char *)this - 4));
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x0056C200
// Name: _dynamic_initializer_for__CDmeConnectionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeConnectionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeConnectionOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeConnectionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056ED00
// Name: _dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeConnectionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056C230
// Name: _dynamic_initializer_for__g_CDmeConnectionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeConnectionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C240
// Name: _dynamic_initializer_for__g_CDmeConnectionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeConnectionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeConnectionOperator_Helper,
           classname: "DmeConnectionOperator",
           pFactory: &g_CDmeConnectionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056ED10
// Name: _dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeConnectionOperator_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00522F80
// Name: public: virtual bool CDmeConnectionOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeConnectionOperator::IsDirty(CDmeConnectionOperator *this)
{
  CDmeAttributeReference *v1; // eax
  CDmAttribute *ReferencedAttribute; // eax

  v1 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v1);
  return ReferencedAttribute != nullptr && (ReferencedAttribute->m_nFlags & 0x80) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00523050
// Name: protected: void CDmeConnectionOperator::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::OnDestruction(CDmeConnectionOperator *this)
{
  int m_Size; // esi
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  CExpressionCalculator *v7; // ecx
  IDataModel_vtbl *v8; // esi
  int v9; // eax
  int nOutputs; // [esp+Ch] [ebp-4h]

  g_pDataModel->DestroyElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  m_Size = this->m_Outputs.m_Storage.m_Size;
  v3 = 0;
  for ( nOutputs = m_Size; v3 < m_Size; ++v3 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v3]);
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeAttributeReference::m_classType) )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v3]);
      v6 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeAttributeReference::m_classType) )
        v7 = (CExpressionCalculator *)v6;
      else
        v7 = nullptr;
      v8 = g_pDataModel->__vftable;
      v9 = CExpressionCalculator::VariableCount(this: v7);
      v8->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v9);
      m_Size = nOutputs;
    }
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &this->m_Outputs);
}

//------------------------------------------------------------------------------
// Address: 0x00523120
// Name: public: virtual void CDmeConnectionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::Operate(CDmeConnectionOperator *this)
{
  CDmeAttributeReference *v2; // eax
  int m_Size; // esi
  int v4; // edi
  DmElementHandle_t m_Handle; // eax
  CDmeAttributeReference *v6; // eax
  CDmElement *v7; // eax
  CDmeAttributeReference *v8; // esi
  CDmeAttributeReference *v9; // ecx
  int nOutputs; // [esp+Ch] [ebp-Ch]
  const void *pValue; // [esp+10h] [ebp-8h]
  DmAttributeType_t inputType; // [esp+14h] [ebp-4h] BYREF

  v2 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  if ( CDmeAttributeReference::IsValid(this: v2) )
  {
    m_Size = this->m_Outputs.m_Storage.m_Size;
    v4 = 0;
    nOutputs = m_Size;
    if ( m_Size != 0 )
    {
      m_Handle = this->m_Input.m_Storage.m_Handle;
      inputType = AT_UNKNOWN;
      v6 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
      pValue = CDmeAttributeReference::GetAttributeValue(this: v6, type: &inputType);
      if ( m_Size > 0 )
      {
        do
        {
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v4]);
          v8 = (CDmeAttributeReference *)v7;
          if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeAttributeReference::m_classType) )
            v9 = v8;
          else
            v9 = nullptr;
          CDmeAttributeReference::SetAttributeValue(this: v9, pValue, type: inputType);
          ++v4;
        }
        while ( v4 < nOutputs );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005231E0
// Name: public: virtual void CDmeConnectionOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::GetInputAttributes(
        CDmeConnectionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmeAttributeReference *v2; // eax
  CDmAttribute *ReferencedAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax

  v2 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v2);
  if ( ReferencedAttribute != nullptr )
  {
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    m_Size = attrs->m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: m_Size - m_nAllocationCount + 1);
    ++attrs->m_Size;
    m_pMemory = attrs->m_Memory.m_pMemory;
    v7 = attrs->m_Size - m_Size - 1;
    attrs->m_pElements = attrs->m_Memory.m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
    v8 = &attrs->m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      *v8 = ReferencedAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00523260
// Name: public: virtual void CDmeConnectionOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::GetOutputAttributes(
        CDmeConnectionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // eax
  CDmeAttributeReference *v3; // edi
  CDmeAttributeReference *v4; // ecx
  CDmAttribute *ReferencedAttribute; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v9; // eax
  CDmAttribute **v10; // eax
  int nOutputs; // [esp+Ch] [ebp-Ch]
  CDmeConnectionOperator *v12; // [esp+10h] [ebp-8h]
  int iOutput; // [esp+14h] [ebp-4h]

  v12 = this;
  nOutputs = this->m_Outputs.m_Storage.m_Size;
  iOutput = 0;
  if ( nOutputs > 0 )
  {
    while ( 1 )
    {
      v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[iOutput]);
      v3 = (CDmeAttributeReference *)v2;
      if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeAttributeReference::m_classType) )
        v4 = v3;
      else
        v4 = nullptr;
      ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v4);
      if ( ReferencedAttribute != nullptr )
      {
        m_Size = attrs->m_Size;
        m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
            num: m_Size - m_nAllocationCount + 1);
        ++attrs->m_Size;
        m_pMemory = attrs->m_Memory.m_pMemory;
        v9 = attrs->m_Size - m_Size - 1;
        attrs->m_pElements = attrs->m_Memory.m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
        v10 = &attrs->m_Memory.m_pMemory[m_Size];
        if ( v10 != nullptr )
          *v10 = ReferencedAttribute;
      }
      if ( ++iOutput >= nOutputs )
        break;
      this = v12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005233E0
// Name: public: virtual bool CDmeConnectionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeConnectionOperator::IsA(CDmeConnectionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeConnectionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00523410
// Name: public: virtual int CDmeConnectionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeConnectionOperator::GetInheritanceDepth(CDmeConnectionOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeConnectionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00523460
// Name: protected: virtual void CDmeConnectionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::PerformConstruction(CDmeConnectionOperator *this)
{
  char *v2; // esi
  CDmElement *v3; // eax
  CDmElement *v4; // ecx
  CDmAttribute **v5; // esi

  CDmeFXClip::OnDestruction();
  v2 = (char *)this - 4;
  CDmeOperator::OnConstruction(this: (CDmeOperator *)v2);
  if ( v2 != nullptr )
    v3 = (CDmElement *)(v2 + 4);
  else
    v3 = nullptr;
  CDmaElement<CDmeAttributeReference>::InitAndCreate(
    this: (CDmaElement<CDmeAttributeReference> *)(v2 + 76),
    pOwner: v3,
    pAttributeName: (DmElementHandle_t)"input",
    pElementName: nullptr,
    flags: 0);
  if ( v2 != nullptr )
    v4 = (CDmElement *)(v2 + 4);
  else
    v4 = nullptr;
  v5 = (CDmAttribute **)(v2 + 88);
  v5[6] = CDmElement::AddExternalAttribute(this: v4, pAttributeName: "outputs", type: AT_FIRST_ARRAY_TYPE, pMemory: v5);
  CDmAttribute::SetElementTypeSymbol(this: v5[6], typeSymbol: CDmeAttributeReference::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005234D0
// Name: protected: virtual void CDmeConnectionOperator::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::PerformDestruction(CDmeConnectionOperator *this)
{
  CDmeConnectionOperator::OnDestruction(this: (CDmeConnectionOperator *)((char *)this - 4));
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x0057C320
// Name: _dynamic_initializer_for__CDmeConnectionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeConnectionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeConnectionOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeConnectionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EE30
// Name: _dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeConnectionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057C350
// Name: _dynamic_initializer_for__g_CDmeConnectionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeConnectionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C360
// Name: _dynamic_initializer_for__g_CDmeConnectionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeConnectionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeConnectionOperator_Helper,
           classname: "DmeConnectionOperator",
           pFactory: &g_CDmeConnectionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057EE40
// Name: _dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeConnectionOperator_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005DFE90
// Name: public: virtual bool CDmeConnectionOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeConnectionOperator::IsDirty(CDmeConnectionOperator *this)
{
  CDmeAttributeReference *v1; // eax
  CDmAttribute *ReferencedAttribute; // eax

  v1 = (CDmeAttributeReference *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                   a1: g_pDataModel.u,
                                   a2: this->m_Input.m_Storage.m_Handle);
  ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v1);
  return ReferencedAttribute != nullptr && (ReferencedAttribute->m_nFlags & 0x80) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x005DFF60
// Name: protected: void CDmeConnectionOperator::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::OnDestruction(CDmeConnectionOperator *this)
{
  int m_Size; // esi
  int v3; // edi
  int v4; // eax
  int v5; // eax
  CExpressionCalculator *v6; // esi
  CExpressionCalculator *v7; // ecx
  int v8; // esi
  int BufferType; // eax
  int nOutputs; // [esp+Ch] [ebp-4h]

  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 68))(
    a1: g_pDataModel.u,
    a2: this->m_Input.m_Storage.m_Handle);
  m_Size = this->m_Outputs.m_Storage.m_Size;
  v3 = 0;
  for ( nOutputs = m_Size; v3 < m_Size; ++v3 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v3]);
    if ( v4 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeAttributeReference::m_classType.u) != 0 )
    {
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v3]);
      v6 = (CExpressionCalculator *)v5;
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
             a1: v5,
             a2: CDmeAttributeReference::m_classType.u) != 0 )
      {
        v7 = v6;
      }
      else
      {
        v7 = nullptr;
      }
      v8 = *(_DWORD *)g_pDataModel.u.m_Id;
      BufferType = CCodecBuffer_Block::GetBufferType(this: v7);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v8 + 68))(a1: g_pDataModel.u, a2: BufferType);
      m_Size = nOutputs;
    }
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &this->m_Outputs);
}

//------------------------------------------------------------------------------
// Address: 0x005E0030
// Name: public: virtual void CDmeConnectionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::Operate(CDmeConnectionOperator *this)
{
  CDmeAttributeReference *v2; // eax
  int m_Size; // esi
  int v4; // edi
  DmElementHandle_t m_Handle; // eax
  CDmeAttributeReference *v6; // eax
  int v7; // eax
  CDmeAttributeReference *v8; // esi
  CDmeAttributeReference *v9; // ecx
  int nOutputs; // [esp+Ch] [ebp-Ch]
  const void *pValue; // [esp+10h] [ebp-8h]
  DmAttributeType_t inputType; // [esp+14h] [ebp-4h] BYREF

  v2 = (CDmeAttributeReference *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                   a1: g_pDataModel.u,
                                   a2: this->m_Input.m_Storage.m_Handle);
  if ( CDmeAttributeReference::IsValid(this: v2) )
  {
    m_Size = this->m_Outputs.m_Storage.m_Size;
    v4 = 0;
    nOutputs = m_Size;
    if ( m_Size != 0 )
    {
      m_Handle = this->m_Input.m_Storage.m_Handle;
      inputType = AT_UNKNOWN;
      v6 = (CDmeAttributeReference *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                       a1: g_pDataModel.u,
                                       a2: m_Handle);
      pValue = CDmeAttributeReference::GetAttributeValue(this: v6, type: &inputType);
      if ( m_Size > 0 )
      {
        do
        {
          v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v4]);
          v8 = (CDmeAttributeReference *)v7;
          if ( v7 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                 a1: v7,
                 a2: CDmeAttributeReference::m_classType.u) != 0 )
          {
            v9 = v8;
          }
          else
          {
            v9 = nullptr;
          }
          CDmeAttributeReference::SetAttributeValue(this: v9, pValue, type: inputType);
          ++v4;
        }
        while ( v4 < nOutputs );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E00F0
// Name: public: virtual void CDmeConnectionOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::GetInputAttributes(
        CDmeConnectionOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmeAttributeReference *v2; // eax
  CDmAttribute *ReferencedAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v6; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax

  v2 = (CDmeAttributeReference *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                   a1: g_pDataModel.u,
                                   a2: this->m_Input.m_Storage.m_Handle);
  ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v2);
  if ( ReferencedAttribute != nullptr )
  {
    m_nAllocationCount = attrs->m_nAllocationCount;
    m_pMemory = (int)attrs[1].m_pMemory;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v6 = (CDmAttribute **)attrs->m_pMemory;
    v7 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &v6[m_pMemory + 1], src: &v6[m_pMemory], count: 4 * v7);
    v8 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v8 != nullptr )
      *v8 = ReferencedAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E0170
// Name: public: virtual void CDmeConnectionOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::GetOutputAttributes(
        CDmeConnectionOperator *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  int v2; // eax
  CDmeAttributeReference *v3; // edi
  CDmeAttributeReference *v4; // ecx
  CDmAttribute *ReferencedAttribute; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v8; // ecx
  int v9; // eax
  CDmAttribute **v10; // eax
  int nOutputs; // [esp+Ch] [ebp-Ch]
  CDmeConnectionOperator *v12; // [esp+10h] [ebp-8h]
  int iOutput; // [esp+14h] [ebp-4h]

  v12 = this;
  nOutputs = this->m_Outputs.m_Storage.m_Size;
  iOutput = 0;
  if ( nOutputs > 0 )
  {
    while ( 1 )
    {
      v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[iOutput]);
      v3 = (CDmeAttributeReference *)v2;
      if ( v2 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
             a1: v2,
             a2: CDmeAttributeReference::m_classType.u) != 0 )
      {
        v4 = v3;
      }
      else
      {
        v4 = nullptr;
      }
      ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v4);
      if ( ReferencedAttribute != nullptr )
      {
        m_pMemory = (int)attrs[1].m_pMemory;
        m_nAllocationCount = attrs->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
        ++attrs[1].m_pMemory;
        v8 = (CDmAttribute **)attrs->m_pMemory;
        v9 = (int)attrs[1].m_pMemory - m_pMemory - 1;
        attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: &v8[m_pMemory + 1], src: &v8[m_pMemory], count: 4 * v9);
        v10 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
        if ( v10 != nullptr )
          *v10 = ReferencedAttribute;
      }
      if ( ++iOutput >= nOutputs )
        break;
      this = v12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E02C0
// Name: public: virtual bool CDmeConnectionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeConnectionOperator::IsA(CDmeConnectionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeConnectionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E02F0
// Name: public: virtual int CDmeConnectionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeConnectionOperator::GetInheritanceDepth(CDmeConnectionOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeConnectionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E0340
// Name: protected: virtual void CDmeConnectionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::PerformConstruction(CDmeConnectionOperator *this)
{
  char *v2; // esi
  CDmElement *v3; // eax
  CDmElement *v4; // ecx
  CDmAttribute **v5; // esi

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  v2 = (char *)this - 4;
  CDmeOperator::OnConstruction(this: (CDmeOperator *)v2);
  if ( v2 != nullptr )
    v3 = (CDmElement *)(v2 + 4);
  else
    v3 = nullptr;
  CDmaElement<CDmeAttributeReference>::InitAndCreate(
    this: (CDmaElement<CDmeAttributeReference> *)(v2 + 76),
    pOwner: v3,
    pAttributeName: (DmElementHandle_t)"input",
    pElementName: nullptr,
    flags: 0);
  if ( v2 != nullptr )
    v4 = (CDmElement *)(v2 + 4);
  else
    v4 = nullptr;
  v5 = (CDmAttribute **)(v2 + 88);
  v5[6] = CDmElement::AddExternalAttribute(this: v4, pAttributeName: "outputs", type: AT_FIRST_ARRAY_TYPE, pMemory: v5);
  CDmAttribute::SetElementTypeSymbol(this: v5[6], typeSymbol: CDmeAttributeReference::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005E03B0
// Name: protected: virtual void CDmeConnectionOperator::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::PerformDestruction(CDmeConnectionOperator *this)
{
  CDmeConnectionOperator::OnDestruction(this: (CDmeConnectionOperator *)((char *)this - 4));
  CDmeFXClip::OnDestruction(this: (vgui::PropertyPage *)((char *)this - 4));
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x006B1470
// Name: _dynamic_initializer_for__CDmeConnectionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeConnectionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeConnectionOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeConnectionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5620
// Name: _dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeConnectionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B14A0
// Name: _dynamic_initializer_for__g_CDmeConnectionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeConnectionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B14B0
// Name: _dynamic_initializer_for__g_CDmeConnectionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeConnectionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeConnectionOperator_Helper,
           classname: "DmeConnectionOperator",
           pFactory: &g_CDmeConnectionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5630
// Name: _dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeConnectionOperator_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00524180
// Name: public: virtual bool CDmeConnectionOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeConnectionOperator::IsDirty(CDmeConnectionOperator *this)
{
  CDmeAttributeReference *v1; // eax
  CDmAttribute *ReferencedAttribute; // eax

  v1 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v1);
  return ReferencedAttribute != nullptr && (ReferencedAttribute->m_nFlags & 0x80) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00524250
// Name: protected: void CDmeConnectionOperator::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::OnDestruction(CDmeConnectionOperator *this)
{
  int m_Size; // esi
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  CExpressionCalculator *v7; // ecx
  IDataModel_vtbl *v8; // esi
  int v9; // eax
  int nOutputs; // [esp+Ch] [ebp-4h]

  g_pDataModel->DestroyElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  m_Size = this->m_Outputs.m_Storage.m_Size;
  v3 = 0;
  for ( nOutputs = m_Size; v3 < m_Size; ++v3 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v3]);
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeAttributeReference::m_classType) )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v3]);
      v6 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeAttributeReference::m_classType) )
        v7 = (CExpressionCalculator *)v6;
      else
        v7 = nullptr;
      v8 = g_pDataModel->__vftable;
      v9 = CExpressionCalculator::VariableCount(this: v7);
      v8->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v9);
      m_Size = nOutputs;
    }
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &this->m_Outputs);
}

//------------------------------------------------------------------------------
// Address: 0x00524320
// Name: public: virtual void CDmeConnectionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::Operate(CDmeConnectionOperator *this)
{
  CDmeAttributeReference *v2; // eax
  int m_Size; // esi
  int v4; // edi
  DmElementHandle_t m_Handle; // eax
  CDmeAttributeReference *v6; // eax
  CDmElement *v7; // eax
  CDmeAttributeReference *v8; // esi
  CDmeAttributeReference *v9; // ecx
  int nOutputs; // [esp+Ch] [ebp-Ch]
  const void *pValue; // [esp+10h] [ebp-8h]
  DmAttributeType_t inputType; // [esp+14h] [ebp-4h] BYREF

  v2 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  if ( CDmeAttributeReference::IsValid(this: v2) )
  {
    m_Size = this->m_Outputs.m_Storage.m_Size;
    v4 = 0;
    nOutputs = m_Size;
    if ( m_Size != 0 )
    {
      m_Handle = this->m_Input.m_Storage.m_Handle;
      inputType = AT_UNKNOWN;
      v6 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
      pValue = CDmeAttributeReference::GetAttributeValue(this: v6, type: &inputType);
      if ( m_Size > 0 )
      {
        do
        {
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v4]);
          v8 = (CDmeAttributeReference *)v7;
          if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeAttributeReference::m_classType) )
            v9 = v8;
          else
            v9 = nullptr;
          CDmeAttributeReference::SetAttributeValue(this: v9, pValue, type: inputType);
          ++v4;
        }
        while ( v4 < nOutputs );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005243E0
// Name: public: virtual void CDmeConnectionOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::GetInputAttributes(
        CDmeConnectionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmeAttributeReference *v2; // eax
  CDmAttribute *ReferencedAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax

  v2 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v2);
  if ( ReferencedAttribute != nullptr )
  {
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    m_Size = attrs->m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: m_Size - m_nAllocationCount + 1);
    ++attrs->m_Size;
    m_pMemory = attrs->m_Memory.m_pMemory;
    v7 = attrs->m_Size - m_Size - 1;
    attrs->m_pElements = attrs->m_Memory.m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
    v8 = &attrs->m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      *v8 = ReferencedAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00524460
// Name: public: virtual void CDmeConnectionOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::GetOutputAttributes(
        CDmeConnectionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // eax
  CDmeAttributeReference *v3; // edi
  CDmeAttributeReference *v4; // ecx
  CDmAttribute *ReferencedAttribute; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v9; // eax
  CDmAttribute **v10; // eax
  int nOutputs; // [esp+Ch] [ebp-Ch]
  CDmeConnectionOperator *v12; // [esp+10h] [ebp-8h]
  int iOutput; // [esp+14h] [ebp-4h]

  v12 = this;
  nOutputs = this->m_Outputs.m_Storage.m_Size;
  iOutput = 0;
  if ( nOutputs > 0 )
  {
    while ( 1 )
    {
      v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[iOutput]);
      v3 = (CDmeAttributeReference *)v2;
      if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeAttributeReference::m_classType) )
        v4 = v3;
      else
        v4 = nullptr;
      ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v4);
      if ( ReferencedAttribute != nullptr )
      {
        m_Size = attrs->m_Size;
        m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
            num: m_Size - m_nAllocationCount + 1);
        ++attrs->m_Size;
        m_pMemory = attrs->m_Memory.m_pMemory;
        v9 = attrs->m_Size - m_Size - 1;
        attrs->m_pElements = attrs->m_Memory.m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
        v10 = &attrs->m_Memory.m_pMemory[m_Size];
        if ( v10 != nullptr )
          *v10 = ReferencedAttribute;
      }
      if ( ++iOutput >= nOutputs )
        break;
      this = v12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005245B0
// Name: public: virtual bool CDmeConnectionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeConnectionOperator::IsA(CDmeConnectionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeConnectionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005245E0
// Name: public: virtual int CDmeConnectionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeConnectionOperator::GetInheritanceDepth(CDmeConnectionOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeConnectionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00524630
// Name: protected: virtual void CDmeConnectionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::PerformConstruction(CDmeConnectionOperator *this)
{
  char *v2; // esi
  CDmElement *v3; // eax
  CDmElement *v4; // ecx
  CDmAttribute **v5; // esi

  CDmeFXClip::OnDestruction();
  v2 = (char *)this - 4;
  CDmeOperator::OnConstruction(this: (CDmeOperator *)v2);
  if ( v2 != nullptr )
    v3 = (CDmElement *)(v2 + 4);
  else
    v3 = nullptr;
  CDmaElement<CDmeAttributeReference>::InitAndCreate(
    this: (CDmaElement<CDmeAttributeReference> *)(v2 + 76),
    pOwner: v3,
    pAttributeName: (DmElementHandle_t)"input",
    pElementName: nullptr,
    flags: 0);
  if ( v2 != nullptr )
    v4 = (CDmElement *)(v2 + 4);
  else
    v4 = nullptr;
  v5 = (CDmAttribute **)(v2 + 88);
  v5[6] = CDmElement::AddExternalAttribute(this: v4, pAttributeName: "outputs", type: AT_FIRST_ARRAY_TYPE, pMemory: v5);
  CDmAttribute::SetElementTypeSymbol(this: v5[6], typeSymbol: CDmeAttributeReference::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x005246A0
// Name: protected: virtual void CDmeConnectionOperator::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::PerformDestruction(CDmeConnectionOperator *this)
{
  CDmeConnectionOperator::OnDestruction(this: (CDmeConnectionOperator *)((char *)this - 4));
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x0057E2F0
// Name: _dynamic_initializer_for__CDmeConnectionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeConnectionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeConnectionOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeConnectionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00580E10
// Name: _dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeConnectionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E320
// Name: _dynamic_initializer_for__g_CDmeConnectionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeConnectionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E330
// Name: _dynamic_initializer_for__g_CDmeConnectionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeConnectionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeConnectionOperator_Helper,
           classname: "DmeConnectionOperator",
           pFactory: &g_CDmeConnectionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00580E20
// Name: _dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeConnectionOperator_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004E07C0
// Name: protected: virtual int CDmeOperator::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeOperator::AllocatedSize(CDmeOperator *this)
{
  return 76;
}

//------------------------------------------------------------------------------
// Address: 0x004ED660
// Name: public: virtual bool CDmeConnectionOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeConnectionOperator::IsDirty(CDmeConnectionOperator *this)
{
  CDmeAttributeReference *v1; // eax
  CDmAttribute *ReferencedAttribute; // eax

  v1 = (CDmeAttributeReference *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                   a1: g_pDataModel.u,
                                   a2: this->m_Input.m_Storage.m_Handle);
  ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v1);
  return ReferencedAttribute != nullptr && (ReferencedAttribute->m_nFlags & 0x80) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004ED730
// Name: protected: void CDmeConnectionOperator::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::OnDestruction(CDmeConnectionOperator *this)
{
  int m_Size; // esi
  int v3; // edi
  int v4; // eax
  int v5; // eax
  CExpressionCalculator *v6; // esi
  CExpressionCalculator *v7; // ecx
  int v8; // esi
  int v9; // eax
  int nOutputs; // [esp+Ch] [ebp-4h]

  (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 68))(
    a1: g_pDataModel.u,
    a2: this->m_Input.m_Storage.m_Handle);
  m_Size = this->m_Outputs.m_Storage.m_Size;
  v3 = 0;
  for ( nOutputs = m_Size; v3 < m_Size; ++v3 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v3]);
    if ( v4 != 0
      && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeAttributeReference::m_classType.u) != 0 )
    {
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v3]);
      v6 = (CExpressionCalculator *)v5;
      if ( v5 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
             a1: v5,
             a2: CDmeAttributeReference::m_classType.u) != 0 )
      {
        v7 = v6;
      }
      else
      {
        v7 = nullptr;
      }
      v8 = *(_DWORD *)g_pDataModel.u.m_Id;
      v9 = CExpressionCalculator::VariableCount(this: v7);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v8 + 68))(a1: g_pDataModel.u, a2: v9);
      m_Size = nOutputs;
    }
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &this->m_Outputs);
}

//------------------------------------------------------------------------------
// Address: 0x004ED800
// Name: public: virtual void CDmeConnectionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::Operate(CDmeConnectionOperator *this)
{
  CDmeAttributeReference *v2; // eax
  int m_Size; // esi
  int v4; // edi
  DmElementHandle_t m_Handle; // eax
  CDmeAttributeReference *v6; // eax
  int v7; // eax
  CDmeAttributeReference *v8; // esi
  CDmeAttributeReference *v9; // ecx
  int nOutputs; // [esp+Ch] [ebp-Ch]
  const void *pValue; // [esp+10h] [ebp-8h]
  DmAttributeType_t inputType; // [esp+14h] [ebp-4h] BYREF

  v2 = (CDmeAttributeReference *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                   a1: g_pDataModel.u,
                                   a2: this->m_Input.m_Storage.m_Handle);
  if ( CDmeAttributeReference::IsValid(this: v2) )
  {
    m_Size = this->m_Outputs.m_Storage.m_Size;
    v4 = 0;
    nOutputs = m_Size;
    if ( m_Size != 0 )
    {
      m_Handle = this->m_Input.m_Storage.m_Handle;
      inputType = AT_UNKNOWN;
      v6 = (CDmeAttributeReference *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                       a1: g_pDataModel.u,
                                       a2: m_Handle);
      pValue = CDmeAttributeReference::GetAttributeValue(this: v6, type: &inputType);
      if ( m_Size > 0 )
      {
        do
        {
          v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                           + 72))(
                 a1: g_pDataModel.u,
                 a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v4]);
          v8 = (CDmeAttributeReference *)v7;
          if ( v7 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
                 a1: v7,
                 a2: CDmeAttributeReference::m_classType.u) != 0 )
          {
            v9 = v8;
          }
          else
          {
            v9 = nullptr;
          }
          CDmeAttributeReference::SetAttributeValue(this: v9, pValue, type: inputType);
          ++v4;
        }
        while ( v4 < nOutputs );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004ED8C0
// Name: public: virtual void CDmeConnectionOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::GetInputAttributes(
        CDmeConnectionOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  CDmeAttributeReference *v2; // eax
  CDmAttribute *ReferencedAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_pMemory; // edi
  CDmAttribute **v6; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax

  v2 = (CDmeAttributeReference *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                   a1: g_pDataModel.u,
                                   a2: this->m_Input.m_Storage.m_Handle);
  ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v2);
  if ( ReferencedAttribute != nullptr )
  {
    m_nAllocationCount = attrs->m_nAllocationCount;
    m_pMemory = (int)attrs[1].m_pMemory;
    if ( m_pMemory + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
    ++attrs[1].m_pMemory;
    v6 = (CDmAttribute **)attrs->m_pMemory;
    v7 = (int)attrs[1].m_pMemory - m_pMemory - 1;
    attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &v6[m_pMemory + 1], src: &v6[m_pMemory], count: 4 * v7);
    v8 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
    if ( v8 != nullptr )
      *v8 = ReferencedAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004ED940
// Name: public: virtual void CDmeConnectionOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::GetOutputAttributes(
        CDmeConnectionOperator *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  int v2; // eax
  CDmeAttributeReference *v3; // edi
  CDmeAttributeReference *v4; // ecx
  CDmAttribute *ReferencedAttribute; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v8; // ecx
  int v9; // eax
  CDmAttribute **v10; // eax
  int nOutputs; // [esp+Ch] [ebp-Ch]
  CDmeConnectionOperator *v12; // [esp+10h] [ebp-8h]
  int iOutput; // [esp+14h] [ebp-4h]

  v12 = this;
  nOutputs = this->m_Outputs.m_Storage.m_Size;
  iOutput = 0;
  if ( nOutputs > 0 )
  {
    while ( 1 )
    {
      v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[iOutput]);
      v3 = (CDmeAttributeReference *)v2;
      if ( v2 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
             a1: v2,
             a2: CDmeAttributeReference::m_classType.u) != 0 )
      {
        v4 = v3;
      }
      else
      {
        v4 = nullptr;
      }
      ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v4);
      if ( ReferencedAttribute != nullptr )
      {
        m_pMemory = (int)attrs[1].m_pMemory;
        m_nAllocationCount = attrs->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: m_pMemory - m_nAllocationCount + 1);
        ++attrs[1].m_pMemory;
        v8 = (CDmAttribute **)attrs->m_pMemory;
        v9 = (int)attrs[1].m_pMemory - m_pMemory - 1;
        attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: &v8[m_pMemory + 1], src: &v8[m_pMemory], count: 4 * v9);
        v10 = (CDmAttribute **)&attrs->m_pMemory[m_pMemory];
        if ( v10 != nullptr )
          *v10 = ReferencedAttribute;
      }
      if ( ++iOutput >= nOutputs )
        break;
      this = v12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004EDA20
// Name: protected: virtual void CDmeOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::PerformConstruction(CDmeOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeOperator::OnConstruction(this: (CDmeOperator *)((char *)this - 4));
}

//------------------------------------------------------------------------------
// Address: 0x004EDA40
// Name: public: virtual char const __near * IDmeOperator::GetOperatorName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall IDmeOperator::GetOperatorName(IDmeOperator *this)
{
  return "Unknown";
}

//------------------------------------------------------------------------------
// Address: 0x004EDB00
// Name: public: virtual bool CDmeOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeOperator::IsA(CDmeOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EDB30
// Name: public: virtual int CDmeOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeOperator::GetInheritanceDepth(CDmeOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EDB70
// Name: public: virtual char const __near * CDmeOperator::GetOperatorName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeOperator::GetOperatorName(CDmeOperator *this)
{
  const char *result; // eax

  result = this->m_Name.m_Storage.u.m_pAsString;
  if ( result == (const char *)-1 )
    return pDeltaStateName;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004EDB90
// Name: public: virtual bool CDmeConnectionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeConnectionOperator::IsA(CDmeConnectionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeConnectionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EDBC0
// Name: public: virtual int CDmeConnectionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeConnectionOperator::GetInheritanceDepth(CDmeConnectionOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeConnectionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004EDC20
// Name: protected: virtual void CDmeConnectionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::PerformConstruction(CDmeConnectionOperator *this)
{
  char *v2; // esi
  CDmElement *v3; // eax
  CDmElement *v4; // ecx
  CDmAttribute **v5; // esi

  CDmeFXClip::OnDestruction();
  v2 = (char *)this - 4;
  CDmeOperator::OnConstruction(this: (CDmeOperator *)v2);
  if ( v2 != nullptr )
    v3 = (CDmElement *)(v2 + 4);
  else
    v3 = nullptr;
  CDmaElement<CDmeAttributeReference>::InitAndCreate(
    this: (CDmaElement<CDmeAttributeReference> *)(v2 + 76),
    pOwner: v3,
    pAttributeName: (DmElementHandle_t)"input",
    pElementName: nullptr,
    flags: 0);
  if ( v2 != nullptr )
    v4 = (CDmElement *)(v2 + 4);
  else
    v4 = nullptr;
  v5 = (CDmAttribute **)(v2 + 88);
  v5[6] = CDmElement::AddExternalAttribute(this: v4, pAttributeName: "outputs", type: AT_FIRST_ARRAY_TYPE, pMemory: v5);
  CDmAttribute::SetElementTypeSymbol(this: v5[6], typeSymbol: CDmeAttributeReference::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x004EDC90
// Name: protected: virtual void CDmeConnectionOperator::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::PerformDestruction(CDmeConnectionOperator *this)
{
  CDmeConnectionOperator::OnDestruction(this: (CDmeConnectionOperator *)((char *)this - 4));
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x005A65E0
// Name: protected: virtual void CDmeOperator::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeOperator::PerformDestruction(CDmeGlobalFlexControllerOperator *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x005E8180
// Name: _dynamic_initializer_for__CDmeOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeOperator::s_Allocator,
    blockSize: 76,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E81E0
// Name: _dynamic_initializer_for__CDmeConnectionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeConnectionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeConnectionOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeConnectionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ECB70
// Name: _dynamic_atexit_destructor_for__CDmeOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ECB90
// Name: _dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeConnectionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E81B0
// Name: _dynamic_initializer_for__g_CDmeOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E81C0
// Name: _dynamic_initializer_for__g_CDmeOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeOperator_Helper,
           classname: "DmeOperator",
           pFactory: &g_CDmeOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E8210
// Name: _dynamic_initializer_for__g_CDmeConnectionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeConnectionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E8220
// Name: _dynamic_initializer_for__g_CDmeConnectionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeConnectionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeConnectionOperator_Helper,
           classname: "DmeConnectionOperator",
           pFactory: &g_CDmeConnectionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ECB80
// Name: _dynamic_atexit_destructor_for__g_CDmeOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeOperator_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeOperator_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ECBA0
// Name: _dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeConnectionOperator_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0052B680
// Name: public: virtual bool CDmeConnectionOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeConnectionOperator::IsDirty(CDmeConnectionOperator *this)
{
  CDmeAttributeReference *v1; // eax
  CDmAttribute *ReferencedAttribute; // eax

  v1 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v1);
  return ReferencedAttribute != nullptr && (ReferencedAttribute->m_nFlags & 0x80) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0052B750
// Name: protected: void CDmeConnectionOperator::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::OnDestruction(CDmeConnectionOperator *this)
{
  int m_Size; // esi
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  CExpressionCalculator *v7; // ecx
  IDataModel_vtbl *v8; // esi
  int v9; // eax
  int nOutputs; // [esp+Ch] [ebp-4h]

  g_pDataModel->DestroyElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  m_Size = this->m_Outputs.m_Storage.m_Size;
  v3 = 0;
  for ( nOutputs = m_Size; v3 < m_Size; ++v3 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v3]);
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeAttributeReference::m_classType) )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v3]);
      v6 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeAttributeReference::m_classType) )
        v7 = (CExpressionCalculator *)v6;
      else
        v7 = nullptr;
      v8 = g_pDataModel->__vftable;
      v9 = CExpressionCalculator::VariableCount(this: v7);
      v8->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)v9);
      m_Size = nOutputs;
    }
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &this->m_Outputs);
}

//------------------------------------------------------------------------------
// Address: 0x0052B820
// Name: public: virtual void CDmeConnectionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::Operate(CDmeConnectionOperator *this)
{
  CDmeAttributeReference *v2; // eax
  int m_Size; // esi
  int v4; // edi
  DmElementHandle_t m_Handle; // eax
  CDmeAttributeReference *v6; // eax
  CDmElement *v7; // eax
  CDmeAttributeReference *v8; // esi
  CDmeAttributeReference *v9; // ecx
  int nOutputs; // [esp+Ch] [ebp-Ch]
  const void *pValue; // [esp+10h] [ebp-8h]
  DmAttributeType_t inputType; // [esp+14h] [ebp-4h] BYREF

  v2 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  if ( CDmeAttributeReference::IsValid(this: v2) )
  {
    m_Size = this->m_Outputs.m_Storage.m_Size;
    v4 = 0;
    nOutputs = m_Size;
    if ( m_Size != 0 )
    {
      m_Handle = this->m_Input.m_Storage.m_Handle;
      inputType = AT_UNKNOWN;
      v6 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
      pValue = CDmeAttributeReference::GetAttributeValue(this: v6, type: &inputType);
      if ( m_Size > 0 )
      {
        do
        {
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v4]);
          v8 = (CDmeAttributeReference *)v7;
          if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeAttributeReference::m_classType) )
            v9 = v8;
          else
            v9 = nullptr;
          CDmeAttributeReference::SetAttributeValue(this: v9, pValue, type: inputType);
          ++v4;
        }
        while ( v4 < nOutputs );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052B8E0
// Name: public: virtual void CDmeConnectionOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::GetInputAttributes(
        CDmeConnectionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmeAttributeReference *v2; // eax
  CDmAttribute *ReferencedAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax

  v2 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v2);
  if ( ReferencedAttribute != nullptr )
  {
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    m_Size = attrs->m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(
        this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
        num: m_Size - m_nAllocationCount + 1);
    ++attrs->m_Size;
    m_pMemory = attrs->m_Memory.m_pMemory;
    v7 = attrs->m_Size - m_Size - 1;
    attrs->m_pElements = attrs->m_Memory.m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
    v8 = &attrs->m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      *v8 = ReferencedAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052B960
// Name: public: virtual void CDmeConnectionOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::GetOutputAttributes(
        CDmeConnectionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // eax
  CDmeAttributeReference *v3; // edi
  CDmeAttributeReference *v4; // ecx
  CDmAttribute *ReferencedAttribute; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v9; // eax
  CDmAttribute **v10; // eax
  int nOutputs; // [esp+Ch] [ebp-Ch]
  CDmeConnectionOperator *v12; // [esp+10h] [ebp-8h]
  int iOutput; // [esp+14h] [ebp-4h]

  v12 = this;
  nOutputs = this->m_Outputs.m_Storage.m_Size;
  iOutput = 0;
  if ( nOutputs > 0 )
  {
    while ( 1 )
    {
      v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[iOutput]);
      v3 = (CDmeAttributeReference *)v2;
      if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeAttributeReference::m_classType) )
        v4 = v3;
      else
        v4 = nullptr;
      ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v4);
      if ( ReferencedAttribute != nullptr )
      {
        m_Size = attrs->m_Size;
        m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
            num: m_Size - m_nAllocationCount + 1);
        ++attrs->m_Size;
        m_pMemory = attrs->m_Memory.m_pMemory;
        v9 = attrs->m_Size - m_Size - 1;
        attrs->m_pElements = attrs->m_Memory.m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
        v10 = &attrs->m_Memory.m_pMemory[m_Size];
        if ( v10 != nullptr )
          *v10 = ReferencedAttribute;
      }
      if ( ++iOutput >= nOutputs )
        break;
      this = v12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052BAB0
// Name: public: virtual bool CDmeConnectionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeConnectionOperator::IsA(CDmeConnectionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeConnectionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052BAE0
// Name: public: virtual int CDmeConnectionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeConnectionOperator::GetInheritanceDepth(CDmeConnectionOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeConnectionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052BB40
// Name: protected: virtual void CDmeConnectionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::PerformConstruction(CDmeConnectionOperator *this)
{
  char *v2; // esi
  CDmElement *v3; // eax
  CDmElement *v4; // ecx
  CDmAttribute **v5; // esi

  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  v2 = (char *)this - 4;
  CDmeOperator::OnConstruction(this: (CDmeOperator *)v2);
  if ( v2 != nullptr )
    v3 = (CDmElement *)(v2 + 4);
  else
    v3 = nullptr;
  CDmaElement<CDmeAttributeReference>::InitAndCreate(
    this: (CDmaElement<CDmeAttributeReference> *)(v2 + 76),
    pOwner: v3,
    pAttributeName: (DmElementHandle_t)"input",
    pElementName: nullptr,
    flags: 0);
  if ( v2 != nullptr )
    v4 = (CDmElement *)(v2 + 4);
  else
    v4 = nullptr;
  v5 = (CDmAttribute **)(v2 + 88);
  v5[6] = CDmElement::AddExternalAttribute(this: v4, pAttributeName: "outputs", type: AT_FIRST_ARRAY_TYPE, pMemory: v5);
  CDmAttribute::SetElementTypeSymbol(this: v5[6], typeSymbol: CDmeAttributeReference::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0052BBB0
// Name: protected: virtual void CDmeConnectionOperator::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::PerformDestruction(CDmeConnectionOperator *this)
{
  CDmeConnectionOperator::OnDestruction(this: (CDmeConnectionOperator *)((char *)this - 4));
  CDmeFXClip::OnDestruction(this: (CDataManagerBase *)((char *)this - 4));
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0057BB40
// Name: _dynamic_initializer_for__CDmeConnectionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeConnectionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeConnectionOperator::s_Allocator,
    blockSize: 116,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeConnectionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E500
// Name: _dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeConnectionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057BB70
// Name: _dynamic_initializer_for__g_CDmeConnectionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeConnectionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BB80
// Name: _dynamic_initializer_for__g_CDmeConnectionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeConnectionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeConnectionOperator_Helper,
           classname: "DmeConnectionOperator",
           pFactory: &g_CDmeConnectionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E510
// Name: _dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeConnectionOperator_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0062E6A0
// Name: public: virtual bool CDmeConnectionOperator::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeConnectionOperator::IsDirty(CDmeConnectionOperator *this)
{
  CDmeAttributeReference *v1; // eax
  CDmAttribute *ReferencedAttribute; // eax

  v1 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v1);
  return ReferencedAttribute != nullptr && (ReferencedAttribute->m_nFlags & 0x80) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0062E770
// Name: protected: void CDmeConnectionOperator::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::OnDestruction(CDmeConnectionOperator *this)
{
  int m_Size; // esi
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  CVTFTexture *v7; // ecx
  IDataModel_vtbl *v8; // esi
  int CenterVertIndex; // eax
  int nOutputs; // [esp+Ch] [ebp-4h]

  g_pDataModel->DestroyElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  m_Size = this->m_Outputs.m_Storage.m_Size;
  v3 = 0;
  for ( nOutputs = m_Size; v3 < m_Size; ++v3 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v3]);
    if ( v4 != nullptr && v4->IsA(this: v4, a2: CDmeAttributeReference::m_classType) )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v3]);
      v6 = v5;
      if ( v5 != nullptr && v5->IsA(this: v5, a2: CDmeAttributeReference::m_classType) )
        v7 = (CVTFTexture *)v6;
      else
        v7 = nullptr;
      v8 = g_pDataModel->__vftable;
      CenterVertIndex = CCoreDispNode::GetCenterVertIndex(this: v7);
      v8->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)CenterVertIndex);
      m_Size = nOutputs;
    }
  }
  CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::RemoveAll(this: &this->m_Outputs);
}

//------------------------------------------------------------------------------
// Address: 0x0062E840
// Name: public: virtual void CDmeConnectionOperator::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::Operate(CDmeConnectionOperator *this)
{
  CDmeAttributeReference *v2; // eax
  int m_Size; // esi
  int v4; // edi
  DmElementHandle_t m_Handle; // eax
  CDmeAttributeReference *v6; // eax
  CDmElement *v7; // eax
  CDmeAttributeReference *v8; // esi
  CDmeAttributeReference *v9; // ecx
  int nOutputs; // [esp+Ch] [ebp-Ch]
  const void *pValue; // [esp+10h] [ebp-8h]
  DmAttributeType_t inputType; // [esp+14h] [ebp-4h] BYREF

  v2 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  if ( CDmeAttributeReference::IsValid(this: v2) )
  {
    m_Size = this->m_Outputs.m_Storage.m_Size;
    v4 = 0;
    nOutputs = m_Size;
    if ( m_Size != 0 )
    {
      m_Handle = this->m_Input.m_Storage.m_Handle;
      inputType = AT_UNKNOWN;
      v6 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: m_Handle);
      pValue = CDmeAttributeReference::GetAttributeValue(this: v6, type: &inputType);
      if ( m_Size > 0 )
      {
        do
        {
          v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[v4]);
          v8 = (CDmeAttributeReference *)v7;
          if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeAttributeReference::m_classType) )
            v9 = v8;
          else
            v9 = nullptr;
          CDmeAttributeReference::SetAttributeValue(this: v9, pValue, type: inputType);
          ++v4;
        }
        while ( v4 < nOutputs );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062E900
// Name: public: virtual void CDmeConnectionOperator::GetInputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::GetInputAttributes(
        CDmeConnectionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmeAttributeReference *v2; // eax
  CDmAttribute *ReferencedAttribute; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax

  v2 = (CDmeAttributeReference *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Input.m_Storage.m_Handle);
  ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v2);
  if ( ReferencedAttribute != nullptr )
  {
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    m_Size = attrs->m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<HemiLightData_t *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)attrs,
        num: m_Size - m_nAllocationCount + 1);
    ++attrs->m_Size;
    m_pMemory = attrs->m_Memory.m_pMemory;
    v7 = attrs->m_Size - m_Size - 1;
    attrs->m_pElements = attrs->m_Memory.m_pMemory;
    if ( v7 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
    v8 = &attrs->m_Memory.m_pMemory[m_Size];
    if ( v8 != nullptr )
      *v8 = ReferencedAttribute;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062E980
// Name: public: virtual void CDmeConnectionOperator::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::GetOutputAttributes(
        CDmeConnectionOperator *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // eax
  CDmeAttributeReference *v3; // edi
  CDmeAttributeReference *v4; // ecx
  CDmAttribute *ReferencedAttribute; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v9; // eax
  CDmAttribute **v10; // eax
  int nOutputs; // [esp+Ch] [ebp-Ch]
  CDmeConnectionOperator *v12; // [esp+10h] [ebp-8h]
  int iOutput; // [esp+14h] [ebp-4h]

  v12 = this;
  nOutputs = this->m_Outputs.m_Storage.m_Size;
  iOutput = 0;
  if ( nOutputs > 0 )
  {
    while ( 1 )
    {
      v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Outputs.m_Storage.m_Memory.m_pMemory[iOutput]);
      v3 = (CDmeAttributeReference *)v2;
      if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeAttributeReference::m_classType) )
        v4 = v3;
      else
        v4 = nullptr;
      ReferencedAttribute = CDmeAttributeReference::GetReferencedAttribute(this: v4);
      if ( ReferencedAttribute != nullptr )
      {
        m_Size = attrs->m_Size;
        m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<HemiLightData_t *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)attrs,
            num: m_Size - m_nAllocationCount + 1);
        ++attrs->m_Size;
        m_pMemory = attrs->m_Memory.m_pMemory;
        v9 = attrs->m_Size - m_Size - 1;
        attrs->m_pElements = attrs->m_Memory.m_pMemory;
        if ( v9 > 0 )
          _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
        v10 = &attrs->m_Memory.m_pMemory[m_Size];
        if ( v10 != nullptr )
          *v10 = ReferencedAttribute;
      }
      if ( ++iOutput >= nOutputs )
        break;
      this = v12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062EAD0
// Name: public: virtual bool CDmeConnectionOperator::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeConnectionOperator::IsA(CDmeConnectionOperator *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeConnectionOperator::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062EB00
// Name: public: virtual int CDmeConnectionOperator::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeConnectionOperator::GetInheritanceDepth(CDmeConnectionOperator *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeConnectionOperator::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062EB60
// Name: protected: virtual void CDmeConnectionOperator::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::PerformConstruction(CDmeConnectionOperator *this)
{
  char *v2; // esi
  CDmElement *v3; // eax
  CDmElement *v4; // ecx
  CDmAttribute **v5; // esi

  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  v2 = (char *)this - 4;
  CDmeOperator::OnConstruction(this: (CDmeOperator *)v2);
  if ( v2 != nullptr )
    v3 = (CDmElement *)(v2 + 4);
  else
    v3 = nullptr;
  CDmaElement<CDmeAttributeReference>::InitAndCreate(
    this: (CDmaElement<CDmeAttributeReference> *)(v2 + 76),
    pOwner: v3,
    pAttributeName: (DmElementHandle_t)"input",
    pElementName: nullptr,
    flags: 0);
  if ( v2 != nullptr )
    v4 = (CDmElement *)(v2 + 4);
  else
    v4 = nullptr;
  v5 = (CDmAttribute **)(v2 + 88);
  v5[6] = CDmElement::AddExternalAttribute(this: v4, pAttributeName: "outputs", type: AT_FIRST_ARRAY_TYPE, pMemory: v5);
  CDmAttribute::SetElementTypeSymbol(this: v5[6], typeSymbol: CDmeAttributeReference::m_classType);
}

//------------------------------------------------------------------------------
// Address: 0x0062EBD0
// Name: protected: virtual void CDmeConnectionOperator::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeConnectionOperator::PerformDestruction(CDmeConnectionOperator *this)
{
  CDmeConnectionOperator::OnDestruction(this: (CDmeConnectionOperator *)((char *)this - 4));
  CDmeFXClip::OnDestruction(this: (CDataManagerBase *)((char *)this - 4));
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x006B9AB0
// Name: _dynamic_initializer_for__CDmeConnectionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeConnectionOperator::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeConnectionOperator::s_Allocator,
    blockSize: 0x74u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeConnectionOperator pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BD320
// Name: _dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeConnectionOperator::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeConnectionOperator::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B9AE0
// Name: _dynamic_initializer_for__g_CDmeConnectionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeConnectionOperator_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9AF0
// Name: _dynamic_initializer_for__g_CDmeConnectionOperator_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeConnectionOperator_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeConnectionOperator_Helper,
           classname: "DmeConnectionOperator",
           pFactory: &g_CDmeConnectionOperator_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BD330
// Name: _dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeConnectionOperator_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeConnectionOperator_Factory.m_CallBackList);
}

} // namespace vmap
