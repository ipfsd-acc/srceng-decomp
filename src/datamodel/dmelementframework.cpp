// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: datamodel/dmelementframework.cpp
// Functions: 11
// ============================================================

#include "datamodel\dmelementframework.h"

//------------------------------------------------------------------------------
// Address: 0x00443E50
// Name: public: virtual bool CDmElementFramework::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmElementFramework::Connect(CDmElementFramework *this, void *(__cdecl *factory)(const char *, int *))
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00443E60
// Name: public: virtual void __near * CDmElementFramework::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElementFramework *__thiscall CDmElementFramework::QueryInterface(
        CDmElementFramework *this,
        const char *pInterfaceName)
{
  return _V_strcmp(s1: pInterfaceName, s2: "VDmElementFrameworkVersion001") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00443E90
// Name: public: virtual void CDmElementFramework::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Shutdown(CDmElementFramework *this)
{
  CDependencyGraph::Cleanup(this: &this->m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x00443EA0
// Name: public: virtual enum DmPhase_t CDmElementFramework::GetPhase(void)
// Source: json
//------------------------------------------------------------------------------
DmPhase_t __thiscall CDmElementFramework::GetPhase(CDmElementFramework *this)
{
  return this->m_phase;
}

//------------------------------------------------------------------------------
// Address: 0x00443EB0
// Name: public: virtual void CDmElementFramework::SetOperators(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::SetOperators(
        CDmElementFramework *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  CDependencyGraph::Reset(this: &this->m_dependencyGraph, operators);
}

//------------------------------------------------------------------------------
// Address: 0x00443ED0
// Name: private: void CDmElementFramework::Resolve(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this, bool clearDirtyFlags)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  int nCount; // [esp+8h] [ebp-4h]

  v3 = 0;
  nCount = this->m_dirtyElements.m_Size;
  if ( nCount > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != nullptr )
      {
        v4->Resolve(this: v4);
        if ( clearDirtyFlags )
        {
          CDmElement::MarkDirty(this: v5, bDirty: false);
          CDmElement::MarkAttributesClean(this: v5);
        }
      }
      ++v3;
    }
    while ( v3 < nCount );
  }
  if ( clearDirtyFlags )
    this->m_dirtyElements.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00443F50
// Name: public: virtual void CDmElementFramework::BeginEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::BeginEdit(CDmElementFramework *this)
{
  int v2; // edi
  int m_Size; // ebx
  CDmElement *v4; // eax

  v2 = 0;
  if ( this->m_phase != PH_EDIT )
  {
    this->m_phase = PH_EDIT;
  }
  else
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    this->m_phase = PH_EDIT_RESOLVE;
    if ( m_Size <= 0 )
    {
      this->m_phase = PH_EDIT;
    }
    else
    {
      do
      {
        v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v2]);
        if ( v4 != nullptr )
          v4->Resolve(this: v4);
        ++v2;
      }
      while ( v2 < m_Size );
      this->m_phase = PH_EDIT;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443FC0
// Name: public: virtual void CDmElementFramework::Operate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Operate(CDmElementFramework *this, bool bResolve)
{
  int m_Size; // ebx
  int v4; // edi
  CDmElement *v5; // eax
  unsigned int v6; // ebx
  unsigned int i; // edi
  IDmeOperator *v8; // ecx
  int v9; // eax
  int v10; // ebx
  CDmElement *v11; // eax
  CDmElement *v12; // edi
  int bResolvea; // [esp+14h] [ebp+8h]

  if ( this->m_phase == PH_EDIT )
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    v4 = 0;
    for ( this->m_phase = PH_EDIT_RESOLVE; v4 < m_Size; ++v4 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v4]);
      if ( v5 != nullptr )
        v5->Resolve(this: v5);
    }
  }
  this->m_phase = PH_DEPENDENCY;
  if ( CDependencyGraph::CullAndSortOperators(this: &this->m_dependencyGraph) )
    _Warning(a1: "Operator cycle found during dependency graph traversal!\n");
  this->m_phase = PH_OPERATE;
  v6 = this->m_dependencyGraph.m_operators.m_Size;
  for ( i = 0; i < v6; ++i )
  {
    v8 = this->m_dependencyGraph.m_operators.m_Memory.m_pMemory[i];
    v8->Operate(this: v8);
  }
  if ( bResolve )
  {
    v9 = this->m_dirtyElements.m_Size;
    v10 = 0;
    this->m_phase = PH_OPERATE_RESOLVE;
    for ( bResolvea = v9; v10 < bResolvea; ++v10 )
    {
      v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v10]);
      v12 = v11;
      if ( v11 != nullptr )
      {
        v11->Resolve(this: v11);
        CDmElement::MarkDirty(this: v12, bDirty: false);
        CDmElement::MarkAttributesClean(this: v12);
      }
    }
    this->m_dirtyElements.m_Size = 0;
    this->m_phase = PH_OUTPUT;
  }
  CDataModel::CommitSymbols(this: g_pDataModelImp);
}

//------------------------------------------------------------------------------
// Address: 0x004440E0
// Name: public: virtual void CDmElementFramework::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this)
{
  this->m_phase = PH_OPERATE_RESOLVE;
  CDmElementFramework::Resolve(this, clearDirtyFlags: true);
  this->m_phase = PH_OUTPUT;
}

//------------------------------------------------------------------------------
// Address: 0x00444100
// Name: public: void CDmElementFramework::RemoveCleanElementsFromDirtyList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::RemoveCleanElementsFromDirtyList(CDmElementFramework *this)
{
  int i; // edi
  CDmElement *v3; // eax
  int m_Size; // ecx

  for ( i = this->m_dirtyElements.m_Size - 1; i >= 0; --i )
  {
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[i]);
    if ( v3 != nullptr && !CDmElement::IsDirty(this: v3) )
    {
      m_Size = this->m_dirtyElements.m_Size;
      if ( m_Size > 0 )
      {
        if ( i != m_Size - 1 )
          this->m_dirtyElements.m_Memory.m_pMemory[i] = this->m_dirtyElements.m_Memory.m_pMemory[m_Size - 1];
        --this->m_dirtyElements.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00444160
// Name: public: void CDmElementFramework::AddElementToDirtyList(enum DmElementHandle_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::AddElementToDirtyList(
        CDmElementFramework *this,
        CUtlSymbolTable::StringPool_t *hElement)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_dirtyElements; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  m_nAllocationCount = this->m_dirtyElements.m_Memory.m_nAllocationCount;
  p_m_dirtyElements = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_dirtyElements;
  m_Size = this->m_dirtyElements.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_dirtyElements, num: m_Size - m_nAllocationCount + 1);
  ++p_m_dirtyElements[1].m_pMemory;
  m_pMemory = p_m_dirtyElements->m_pMemory;
  v6 = (int)p_m_dirtyElements[1].m_pMemory - m_Size - 1;
  p_m_dirtyElements[1].m_nAllocationCount = (int)p_m_dirtyElements->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_dirtyElements->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = hElement;
}

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x004526E0
// Name: public: virtual bool CDmElementFramework::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmElementFramework::Connect(CDmElementFramework *this, void *(__cdecl *factory)(const char *, int *))
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004526F0
// Name: public: virtual void __near * CDmElementFramework::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElementFramework *__thiscall CDmElementFramework::QueryInterface(
        CDmElementFramework *this,
        const char *pInterfaceName)
{
  return _V_strcmp(s1: pInterfaceName, s2: "VDmElementFrameworkVersion001") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00452720
// Name: public: virtual void CDmElementFramework::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Shutdown(CDmElementFramework *this)
{
  CDependencyGraph::Cleanup(this: &this->m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x00452730
// Name: public: virtual void CDmElementFramework::SetOperators(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::SetOperators(
        CDmElementFramework *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  CDependencyGraph::Reset(this: &this->m_dependencyGraph, operators);
}

//------------------------------------------------------------------------------
// Address: 0x00452750
// Name: private: void CDmElementFramework::Resolve(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this, bool clearDirtyFlags)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  int nCount; // [esp+8h] [ebp-4h]

  v3 = 0;
  nCount = this->m_dirtyElements.m_Size;
  if ( nCount > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != nullptr )
      {
        v4->Resolve(this: v4);
        if ( clearDirtyFlags )
        {
          CDmElement::MarkDirty(this: v5, bDirty: false);
          CDmElement::MarkAttributesClean(this: v5);
        }
      }
      ++v3;
    }
    while ( v3 < nCount );
  }
  if ( clearDirtyFlags )
    this->m_dirtyElements.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004527D0
// Name: public: virtual void CDmElementFramework::BeginEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::BeginEdit(CDmElementFramework *this)
{
  int v2; // edi
  int m_Size; // ebx
  CDmElement *v4; // eax

  v2 = 0;
  if ( this->m_phase != PH_EDIT )
  {
    this->m_phase = PH_EDIT;
  }
  else
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    this->m_phase = PH_EDIT_RESOLVE;
    if ( m_Size <= 0 )
    {
      this->m_phase = PH_EDIT;
    }
    else
    {
      do
      {
        v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v2]);
        if ( v4 != nullptr )
          v4->Resolve(this: v4);
        ++v2;
      }
      while ( v2 < m_Size );
      this->m_phase = PH_EDIT;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00452840
// Name: public: virtual void CDmElementFramework::Operate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Operate(CDmElementFramework *this, bool bResolve)
{
  int m_Size; // ebx
  int v4; // edi
  CDmElement *v5; // eax
  unsigned int v6; // ebx
  unsigned int i; // edi
  IDmeOperator *v8; // ecx
  int v9; // eax
  int v10; // ebx
  CDmElement *v11; // eax
  CDmElement *v12; // edi
  int bResolvea; // [esp+14h] [ebp+8h]

  if ( this->m_phase == PH_EDIT )
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    v4 = 0;
    for ( this->m_phase = PH_EDIT_RESOLVE; v4 < m_Size; ++v4 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v4]);
      if ( v5 != nullptr )
        v5->Resolve(this: v5);
    }
  }
  this->m_phase = PH_DEPENDENCY;
  if ( CDependencyGraph::CullAndSortOperators(this: &this->m_dependencyGraph) )
    _Warning(a1: "Operator cycle found during dependency graph traversal!\n");
  this->m_phase = PH_OPERATE;
  v6 = this->m_dependencyGraph.m_operators.m_Size;
  for ( i = 0; i < v6; ++i )
  {
    v8 = this->m_dependencyGraph.m_operators.m_Memory.m_pMemory[i];
    v8->Operate(this: v8);
  }
  if ( bResolve )
  {
    v9 = this->m_dirtyElements.m_Size;
    v10 = 0;
    this->m_phase = PH_OPERATE_RESOLVE;
    for ( bResolvea = v9; v10 < bResolvea; ++v10 )
    {
      v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v10]);
      v12 = v11;
      if ( v11 != nullptr )
      {
        v11->Resolve(this: v11);
        CDmElement::MarkDirty(this: v12, bDirty: false);
        CDmElement::MarkAttributesClean(this: v12);
      }
    }
    this->m_dirtyElements.m_Size = 0;
    this->m_phase = PH_OUTPUT;
  }
  CDataModel::CommitSymbols(this: g_pDataModelImp);
}

//------------------------------------------------------------------------------
// Address: 0x00452960
// Name: public: virtual void CDmElementFramework::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this)
{
  this->m_phase = PH_OPERATE_RESOLVE;
  CDmElementFramework::Resolve(this, clearDirtyFlags: true);
  this->m_phase = PH_OUTPUT;
}

//------------------------------------------------------------------------------
// Address: 0x00452980
// Name: public: void CDmElementFramework::RemoveCleanElementsFromDirtyList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::RemoveCleanElementsFromDirtyList(CDmElementFramework *this)
{
  int i; // edi
  CDmElement *v3; // eax
  int m_Size; // ecx

  for ( i = this->m_dirtyElements.m_Size - 1; i >= 0; --i )
  {
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[i]);
    if ( v3 != nullptr && !CDmElement::IsDirty(this: v3) )
    {
      m_Size = this->m_dirtyElements.m_Size;
      if ( m_Size > 0 )
      {
        if ( i != m_Size - 1 )
          this->m_dirtyElements.m_Memory.m_pMemory[i] = this->m_dirtyElements.m_Memory.m_pMemory[m_Size - 1];
        --this->m_dirtyElements.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004529E0
// Name: public: void CDmElementFramework::AddElementToDirtyList(enum DmElementHandle_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::AddElementToDirtyList(
        CDmElementFramework *this,
        CUtlSymbolTable::StringPool_t *hElement)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_dirtyElements; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  m_nAllocationCount = this->m_dirtyElements.m_Memory.m_nAllocationCount;
  p_m_dirtyElements = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_dirtyElements;
  m_Size = this->m_dirtyElements.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_dirtyElements, num: m_Size - m_nAllocationCount + 1);
  ++p_m_dirtyElements[1].m_pMemory;
  m_pMemory = p_m_dirtyElements->m_pMemory;
  v6 = (int)p_m_dirtyElements[1].m_pMemory - m_Size - 1;
  p_m_dirtyElements[1].m_nAllocationCount = (int)p_m_dirtyElements->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_dirtyElements->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = hElement;
}

//------------------------------------------------------------------------------
// Address: 0x00495DA0
// Name: public: virtual enum DmPhase_t CDmElementFramework::GetPhase(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmElementFramework::GetPhase(CDmeDag *this)
{
  return this->m_Children.m_Storage.m_Size;
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00408100
// Name: public: virtual void __near * CDmElementFramework::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElementFramework *__thiscall CDmElementFramework::QueryInterface(
        CDmElementFramework *this,
        const char *pInterfaceName)
{
  return _V_strcmp(s1: pInterfaceName, s2: "VDmElementFrameworkVersion001") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00408130
// Name: public: virtual void CDmElementFramework::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Shutdown(CDmElementFramework *this)
{
  CDependencyGraph::Cleanup(this: &this->m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x00408140
// Name: public: virtual void CDmElementFramework::SetOperators(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::SetOperators(
        CDmElementFramework *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  CDependencyGraph::Reset(this: &this->m_dependencyGraph, operators);
}

//------------------------------------------------------------------------------
// Address: 0x00408160
// Name: private: void CDmElementFramework::Resolve(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this, bool clearDirtyFlags)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  int nCount; // [esp+8h] [ebp-4h]

  v3 = 0;
  nCount = this->m_dirtyElements.m_Size;
  if ( nCount > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != nullptr )
      {
        v4->Resolve(this: v4);
        if ( clearDirtyFlags )
        {
          CDmElement::MarkDirty(this: v5, bDirty: false);
          CDmElement::MarkAttributesClean(this: v5);
        }
      }
      ++v3;
    }
    while ( v3 < nCount );
  }
  if ( clearDirtyFlags )
    this->m_dirtyElements.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004081E0
// Name: public: virtual void CDmElementFramework::BeginEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::BeginEdit(CDmElementFramework *this)
{
  int v2; // edi
  int m_Size; // ebx
  CDmElement *v4; // eax

  v2 = 0;
  if ( this->m_phase != PH_EDIT )
  {
    this->m_phase = PH_EDIT;
  }
  else
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    this->m_phase = PH_EDIT_RESOLVE;
    if ( m_Size <= 0 )
    {
      this->m_phase = PH_EDIT;
    }
    else
    {
      do
      {
        v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v2]);
        if ( v4 != nullptr )
          v4->Resolve(this: v4);
        ++v2;
      }
      while ( v2 < m_Size );
      this->m_phase = PH_EDIT;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408250
// Name: public: virtual void CDmElementFramework::Operate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Operate(CDmElementFramework *this, bool bResolve)
{
  int m_Size; // ebx
  int v4; // edi
  CDmElement *v5; // eax
  unsigned int v6; // ebx
  unsigned int i; // edi
  IDmeOperator *v8; // ecx
  int v9; // eax
  int v10; // ebx
  CDmElement *v11; // eax
  CDmElement *v12; // edi
  int bResolvea; // [esp+14h] [ebp+8h]

  if ( this->m_phase == PH_EDIT )
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    v4 = 0;
    for ( this->m_phase = PH_EDIT_RESOLVE; v4 < m_Size; ++v4 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v4]);
      if ( v5 != nullptr )
        v5->Resolve(this: v5);
    }
  }
  this->m_phase = PH_DEPENDENCY;
  if ( CDependencyGraph::CullAndSortOperators(this: &this->m_dependencyGraph) )
    _Warning(a1: "Operator cycle found during dependency graph traversal!\n");
  this->m_phase = PH_OPERATE;
  v6 = this->m_dependencyGraph.m_operators.m_Size;
  for ( i = 0; i < v6; ++i )
  {
    v8 = this->m_dependencyGraph.m_operators.m_Memory.m_pMemory[i];
    v8->Operate(this: v8);
  }
  if ( bResolve )
  {
    v9 = this->m_dirtyElements.m_Size;
    v10 = 0;
    this->m_phase = PH_OPERATE_RESOLVE;
    for ( bResolvea = v9; v10 < bResolvea; ++v10 )
    {
      v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v10]);
      v12 = v11;
      if ( v11 != nullptr )
      {
        v11->Resolve(this: v11);
        CDmElement::MarkDirty(this: v12, bDirty: false);
        CDmElement::MarkAttributesClean(this: v12);
      }
    }
    this->m_dirtyElements.m_Size = 0;
    this->m_phase = PH_OUTPUT;
  }
  CDataModel::CommitSymbols(this: g_pDataModelImp);
}

//------------------------------------------------------------------------------
// Address: 0x00408370
// Name: public: virtual void CDmElementFramework::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this)
{
  this->m_phase = PH_OPERATE_RESOLVE;
  CDmElementFramework::Resolve(this, clearDirtyFlags: true);
  this->m_phase = PH_OUTPUT;
}

//------------------------------------------------------------------------------
// Address: 0x00408390
// Name: public: void CDmElementFramework::RemoveCleanElementsFromDirtyList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::RemoveCleanElementsFromDirtyList(CDmElementFramework *this)
{
  int i; // edi
  CDmElement *v3; // eax
  int m_Size; // ecx

  for ( i = this->m_dirtyElements.m_Size - 1; i >= 0; --i )
  {
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[i]);
    if ( v3 != nullptr && !CDmElement::IsDirty(this: v3) )
    {
      m_Size = this->m_dirtyElements.m_Size;
      if ( m_Size > 0 )
      {
        if ( i != m_Size - 1 )
          this->m_dirtyElements.m_Memory.m_pMemory[i] = this->m_dirtyElements.m_Memory.m_pMemory[m_Size - 1];
        --this->m_dirtyElements.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004083F0
// Name: public: void CDmElementFramework::AddElementToDirtyList(enum DmElementHandle_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::AddElementToDirtyList(CDmElementFramework *this, vgui::TreeNode *hElement)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_dirtyElements; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax

  m_nAllocationCount = this->m_dirtyElements.m_Memory.m_nAllocationCount;
  p_m_dirtyElements = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_dirtyElements;
  m_Size = this->m_dirtyElements.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_dirtyElements, num: m_Size - m_nAllocationCount + 1);
  ++p_m_dirtyElements[1].m_pMemory;
  m_pMemory = p_m_dirtyElements->m_pMemory;
  v6 = (int)p_m_dirtyElements[1].m_pMemory - m_Size - 1;
  p_m_dirtyElements[1].m_nAllocationCount = (int)p_m_dirtyElements->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_dirtyElements->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = hElement;
}

//------------------------------------------------------------------------------
// Address: 0x00501E20
// Name: public: virtual enum DmPhase_t CDmElementFramework::GetPhase(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmElementFramework::GetPhase(CDmeDag *this)
{
  return this->m_Children.m_Storage.m_Size;
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x101EBCE0
// Name: public: virtual void __near * CDmElementFramework::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElementFramework *__thiscall CDmElementFramework::QueryInterface(
        CDmElementFramework *this,
        const char *pInterfaceName)
{
  return _V_strcmp(s1: pInterfaceName, s2: "VDmElementFrameworkVersion001") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101EBD10
// Name: public: virtual void CDmElementFramework::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Shutdown(CDmElementFramework *this)
{
  CDependencyGraph::Cleanup(this: &this->m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x101EBD20
// Name: public: virtual void CDmElementFramework::SetOperators(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::SetOperators(
        CDmElementFramework *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  CDependencyGraph::Reset(this: &this->m_dependencyGraph, operators);
}

//------------------------------------------------------------------------------
// Address: 0x101EBD40
// Name: private: void CDmElementFramework::Resolve(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this, bool clearDirtyFlags)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  int nCount; // [esp+8h] [ebp-4h]

  v3 = 0;
  nCount = this->m_dirtyElements.m_Size;
  if ( nCount > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != nullptr )
      {
        v4->Resolve(this: v4);
        if ( clearDirtyFlags )
        {
          CDmElement::MarkDirty(this: v5, bDirty: false);
          CDmElement::MarkAttributesClean(this: v5);
        }
      }
      ++v3;
    }
    while ( v3 < nCount );
  }
  if ( clearDirtyFlags )
    this->m_dirtyElements.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101EBDC0
// Name: public: virtual void CDmElementFramework::BeginEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::BeginEdit(CDmElementFramework *this)
{
  int v2; // edi
  int m_Size; // ebx
  CDmElement *v4; // eax

  v2 = 0;
  if ( this->m_phase != PH_EDIT )
  {
    this->m_phase = PH_EDIT;
  }
  else
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    this->m_phase = PH_EDIT_RESOLVE;
    if ( m_Size <= 0 )
    {
      this->m_phase = PH_EDIT;
    }
    else
    {
      do
      {
        v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v2]);
        if ( v4 != nullptr )
          v4->Resolve(this: v4);
        ++v2;
      }
      while ( v2 < m_Size );
      this->m_phase = PH_EDIT;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EBE30
// Name: public: virtual void CDmElementFramework::Operate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Operate(CDmElementFramework *this, bool bResolve)
{
  int m_Size; // ebx
  int v4; // edi
  CDmElement *v5; // eax
  unsigned int v6; // ebx
  unsigned int i; // edi
  IDmeOperator *v8; // ecx
  int v9; // eax
  int v10; // ebx
  CDmElement *v11; // eax
  CDmElement *v12; // edi
  int bResolvea; // [esp+14h] [ebp+8h]

  if ( this->m_phase == PH_EDIT )
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    v4 = 0;
    for ( this->m_phase = PH_EDIT_RESOLVE; v4 < m_Size; ++v4 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v4]);
      if ( v5 != nullptr )
        v5->Resolve(this: v5);
    }
  }
  this->m_phase = PH_DEPENDENCY;
  if ( CDependencyGraph::CullAndSortOperators(this: &this->m_dependencyGraph) )
    _Warning(a1: "Operator cycle found during dependency graph traversal!\n");
  this->m_phase = PH_OPERATE;
  v6 = this->m_dependencyGraph.m_operators.m_Size;
  for ( i = 0; i < v6; ++i )
  {
    v8 = this->m_dependencyGraph.m_operators.m_Memory.m_pMemory[i];
    v8->Operate(this: v8);
  }
  if ( bResolve )
  {
    v9 = this->m_dirtyElements.m_Size;
    v10 = 0;
    this->m_phase = PH_OPERATE_RESOLVE;
    for ( bResolvea = v9; v10 < bResolvea; ++v10 )
    {
      v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v10]);
      v12 = v11;
      if ( v11 != nullptr )
      {
        v11->Resolve(this: v11);
        CDmElement::MarkDirty(this: v12, bDirty: false);
        CDmElement::MarkAttributesClean(this: v12);
      }
    }
    this->m_dirtyElements.m_Size = 0;
    this->m_phase = PH_OUTPUT;
  }
  CDataModel::CommitSymbols(this: g_pDataModelImp);
}

//------------------------------------------------------------------------------
// Address: 0x101EBF50
// Name: public: virtual void CDmElementFramework::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this)
{
  this->m_phase = PH_OPERATE_RESOLVE;
  CDmElementFramework::Resolve(this, clearDirtyFlags: true);
  this->m_phase = PH_OUTPUT;
}

//------------------------------------------------------------------------------
// Address: 0x101EBF70
// Name: public: void CDmElementFramework::RemoveCleanElementsFromDirtyList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::RemoveCleanElementsFromDirtyList(CDmElementFramework *this)
{
  int i; // edi
  CDmElement *v3; // eax
  int m_Size; // ecx

  for ( i = this->m_dirtyElements.m_Size - 1; i >= 0; --i )
  {
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[i]);
    if ( v3 != nullptr && !CDmElement::IsDirty(this: v3) )
    {
      m_Size = this->m_dirtyElements.m_Size;
      if ( m_Size > 0 )
      {
        if ( i != m_Size - 1 )
          this->m_dirtyElements.m_Memory.m_pMemory[i] = this->m_dirtyElements.m_Memory.m_pMemory[m_Size - 1];
        --this->m_dirtyElements.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101EBFD0
// Name: public: void CDmElementFramework::AddElementToDirtyList(enum DmElementHandle_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::AddElementToDirtyList(CDmElementFramework *this, vgui::TreeNode *hElement)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_dirtyElements; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax

  m_nAllocationCount = this->m_dirtyElements.m_Memory.m_nAllocationCount;
  p_m_dirtyElements = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_dirtyElements;
  m_Size = this->m_dirtyElements.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_dirtyElements, num: m_Size - m_nAllocationCount + 1);
  ++p_m_dirtyElements[1].m_pMemory;
  m_pMemory = p_m_dirtyElements->m_pMemory;
  v6 = (int)p_m_dirtyElements[1].m_pMemory - m_Size - 1;
  p_m_dirtyElements[1].m_nAllocationCount = (int)p_m_dirtyElements->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_dirtyElements->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = hElement;
}

//------------------------------------------------------------------------------
// Address: 0x104D9310
// Name: public: virtual enum DmPhase_t CDmElementFramework::GetPhase(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmElementFramework::GetPhase(CDmeDag *this)
{
  return this->m_Children.m_Storage.m_Size;
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x00474480
// Name: public: virtual bool CDmElementFramework::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmElementFramework::Connect(CDmElementFramework *this, void *(__cdecl *factory)(const char *, int *))
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00474490
// Name: public: virtual void __near * CDmElementFramework::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElementFramework *__thiscall CDmElementFramework::QueryInterface(
        CDmElementFramework *this,
        const char *pInterfaceName)
{
  return _V_strcmp(s1: pInterfaceName, s2: "VDmElementFrameworkVersion001") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004744C0
// Name: public: virtual void CDmElementFramework::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Shutdown(CDmElementFramework *this)
{
  CDependencyGraph::Cleanup(this: &this->m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x004744D0
// Name: public: virtual void CDmElementFramework::SetOperators(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::SetOperators(
        CDmElementFramework *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  CDependencyGraph::Reset(this: &this->m_dependencyGraph, operators);
}

//------------------------------------------------------------------------------
// Address: 0x00474510
// Name: private: void CDmElementFramework::Resolve(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this, bool clearDirtyFlags)
{
  int v3; // edi
  int v4; // eax
  CDmElement *v5; // esi
  int nCount; // [esp+8h] [ebp-4h]

  v3 = 0;
  nCount = this->m_dirtyElements.m_Size;
  if ( nCount > 0 )
  {
    do
    {
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_dirtyElements.m_Memory.m_pMemory[v3]);
      v5 = (CDmElement *)v4;
      if ( v4 != 0 )
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
        if ( clearDirtyFlags )
        {
          CDmElement::MarkDirty(this: v5, bDirty: false);
          CDmElement::MarkAttributesClean(this: v5);
        }
      }
      ++v3;
    }
    while ( v3 < nCount );
  }
  if ( clearDirtyFlags )
    this->m_dirtyElements.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00474590
// Name: public: virtual void CDmElementFramework::BeginEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::BeginEdit(CDmElementFramework *this)
{
  int v2; // edi
  int m_Size; // ebx
  int v4; // eax

  v2 = 0;
  if ( this->m_phase != PH_EDIT )
  {
    this->m_phase = PH_EDIT;
  }
  else
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    this->m_phase = PH_EDIT_RESOLVE;
    if ( m_Size <= 0 )
    {
      this->m_phase = PH_EDIT;
    }
    else
    {
      do
      {
        v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_dirtyElements.m_Memory.m_pMemory[v2]);
        if ( v4 != 0 )
          (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
        ++v2;
      }
      while ( v2 < m_Size );
      this->m_phase = PH_EDIT;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474600
// Name: public: virtual void CDmElementFramework::Operate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Operate(CDmElementFramework *this, bool bResolve)
{
  int m_Size; // ebx
  int v4; // edi
  int v5; // eax
  unsigned int v6; // ebx
  unsigned int i; // edi
  IDmeOperator *v8; // ecx
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  CDmElement *v12; // edi
  int bResolvea; // [esp+14h] [ebp+8h]

  if ( this->m_phase == PH_EDIT )
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    v4 = 0;
    for ( this->m_phase = PH_EDIT_RESOLVE; v4 < m_Size; ++v4 )
    {
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_dirtyElements.m_Memory.m_pMemory[v4]);
      if ( v5 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
    }
  }
  this->m_phase = PH_DEPENDENCY;
  if ( CDependencyGraph::CullAndSortOperators(this: &this->m_dependencyGraph) )
    _Warning(a1: "Operator cycle found during dependency graph traversal!\n");
  this->m_phase = PH_OPERATE;
  v6 = this->m_dependencyGraph.m_operators.m_Size;
  for ( i = 0; i < v6; ++i )
  {
    v8 = this->m_dependencyGraph.m_operators.m_Memory.m_pMemory[i];
    v8->Operate(this: v8);
  }
  if ( bResolve )
  {
    v9 = this->m_dirtyElements.m_Size;
    v10 = 0;
    this->m_phase = PH_OPERATE_RESOLVE;
    for ( bResolvea = v9; v10 < bResolvea; ++v10 )
    {
      v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
              a1: g_pDataModel.u,
              a2: this->m_dirtyElements.m_Memory.m_pMemory[v10]);
      v12 = (CDmElement *)v11;
      if ( v11 != 0 )
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 12))(a1: v11);
        CDmElement::MarkDirty(this: v12, bDirty: false);
        CDmElement::MarkAttributesClean(this: v12);
      }
    }
    this->m_dirtyElements.m_Size = 0;
    this->m_phase = PH_OUTPUT;
  }
  CDataModel::CommitSymbols(this: g_pDataModelImp);
}

//------------------------------------------------------------------------------
// Address: 0x00474720
// Name: public: virtual void CDmElementFramework::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this)
{
  this->m_phase = PH_OPERATE_RESOLVE;
  CDmElementFramework::Resolve(this, clearDirtyFlags: true);
  this->m_phase = PH_OUTPUT;
}

//------------------------------------------------------------------------------
// Address: 0x00474740
// Name: public: void CDmElementFramework::RemoveCleanElementsFromDirtyList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::RemoveCleanElementsFromDirtyList(CDmElementFramework *this)
{
  int i; // edi
  CDmElement *v3; // eax
  int m_Size; // ecx

  for ( i = this->m_dirtyElements.m_Size - 1; i >= 0; --i )
  {
    v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_dirtyElements.m_Memory.m_pMemory[i]);
    if ( v3 != nullptr && !CDmElement::IsDirty(this: v3) )
    {
      m_Size = this->m_dirtyElements.m_Size;
      if ( m_Size > 0 )
      {
        if ( i != m_Size - 1 )
          this->m_dirtyElements.m_Memory.m_pMemory[i] = this->m_dirtyElements.m_Memory.m_pMemory[m_Size - 1];
        --this->m_dirtyElements.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004747A0
// Name: public: void CDmElementFramework::AddElementToDirtyList(enum DmElementHandle_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::AddElementToDirtyList(
        CDmElementFramework *this,
        CUtlSymbolTable::StringPool_t *hElement)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_dirtyElements; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  m_nAllocationCount = this->m_dirtyElements.m_Memory.m_nAllocationCount;
  p_m_dirtyElements = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_dirtyElements;
  m_Size = this->m_dirtyElements.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_dirtyElements, num: m_Size - m_nAllocationCount + 1);
  ++p_m_dirtyElements[1].m_pMemory;
  m_pMemory = p_m_dirtyElements->m_pMemory;
  v6 = (int)p_m_dirtyElements[1].m_pMemory - m_Size - 1;
  p_m_dirtyElements[1].m_nAllocationCount = (int)p_m_dirtyElements->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_dirtyElements->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = hElement;
}

//------------------------------------------------------------------------------
// Address: 0x004B5A60
// Name: public: virtual enum DmPhase_t CDmElementFramework::GetPhase(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmElementFramework::GetPhase(CDmeDag *this)
{
  return this->m_Children.m_Storage.m_Size;
}

} // namespace hlmv

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x00500640
// Name: public: virtual bool CDmElementFramework::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmElementFramework::Connect(CDmElementFramework *this, void *(__cdecl *factory)(const char *, int *))
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00500650
// Name: public: virtual void __near * CDmElementFramework::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElementFramework *__thiscall CDmElementFramework::QueryInterface(
        CDmElementFramework *this,
        const char *pInterfaceName)
{
  return _V_strcmp(s1: pInterfaceName, s2: "VDmElementFrameworkVersion001") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00500680
// Name: public: virtual void CDmElementFramework::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Shutdown(CDmElementFramework *this)
{
  CDependencyGraph::Cleanup(this: &this->m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x00500690
// Name: public: virtual enum DmPhase_t CDmElementFramework::GetPhase(void)
// Source: json
//------------------------------------------------------------------------------
DmPhase_t __thiscall CDmElementFramework::GetPhase(CDmElementFramework *this)
{
  return this->m_phase;
}

//------------------------------------------------------------------------------
// Address: 0x005006A0
// Name: public: virtual void CDmElementFramework::SetOperators(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::SetOperators(
        CDmElementFramework *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  CDependencyGraph::Reset(this: &this->m_dependencyGraph, operators);
}

//------------------------------------------------------------------------------
// Address: 0x005006C0
// Name: private: void CDmElementFramework::Resolve(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this, bool clearDirtyFlags)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  int nCount; // [esp+8h] [ebp-4h]

  v3 = 0;
  nCount = this->m_dirtyElements.m_Size;
  if ( nCount > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != nullptr )
      {
        v4->Resolve(this: v4);
        if ( clearDirtyFlags )
        {
          CDmElement::MarkDirty(this: v5, bDirty: false);
          CDmElement::MarkAttributesClean(this: v5);
        }
      }
      ++v3;
    }
    while ( v3 < nCount );
  }
  if ( clearDirtyFlags )
    this->m_dirtyElements.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00500740
// Name: public: virtual void CDmElementFramework::BeginEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::BeginEdit(CDmElementFramework *this)
{
  int v2; // edi
  int m_Size; // ebx
  CDmElement *v4; // eax

  v2 = 0;
  if ( this->m_phase != PH_EDIT )
  {
    this->m_phase = PH_EDIT;
  }
  else
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    this->m_phase = PH_EDIT_RESOLVE;
    if ( m_Size <= 0 )
    {
      this->m_phase = PH_EDIT;
    }
    else
    {
      do
      {
        v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v2]);
        if ( v4 != nullptr )
          v4->Resolve(this: v4);
        ++v2;
      }
      while ( v2 < m_Size );
      this->m_phase = PH_EDIT;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005007B0
// Name: public: virtual void CDmElementFramework::Operate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Operate(CDmElementFramework *this, bool bResolve)
{
  int m_Size; // ebx
  int v4; // edi
  CDmElement *v5; // eax
  unsigned int v6; // ebx
  unsigned int i; // edi
  IDmeOperator *v8; // ecx
  int v9; // eax
  int v10; // ebx
  CDmElement *v11; // eax
  CDmElement *v12; // edi
  int bResolvea; // [esp+14h] [ebp+8h]

  if ( this->m_phase == PH_EDIT )
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    v4 = 0;
    for ( this->m_phase = PH_EDIT_RESOLVE; v4 < m_Size; ++v4 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v4]);
      if ( v5 != nullptr )
        v5->Resolve(this: v5);
    }
  }
  this->m_phase = PH_DEPENDENCY;
  if ( CDependencyGraph::CullAndSortOperators(this: &this->m_dependencyGraph) )
    _Warning(a1: "Operator cycle found during dependency graph traversal!\n");
  this->m_phase = PH_OPERATE;
  v6 = this->m_dependencyGraph.m_operators.m_Size;
  for ( i = 0; i < v6; ++i )
  {
    v8 = this->m_dependencyGraph.m_operators.m_Memory.m_pMemory[i];
    v8->Operate(this: v8);
  }
  if ( bResolve )
  {
    v9 = this->m_dirtyElements.m_Size;
    v10 = 0;
    this->m_phase = PH_OPERATE_RESOLVE;
    for ( bResolvea = v9; v10 < bResolvea; ++v10 )
    {
      v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v10]);
      v12 = v11;
      if ( v11 != nullptr )
      {
        v11->Resolve(this: v11);
        CDmElement::MarkDirty(this: v12, bDirty: false);
        CDmElement::MarkAttributesClean(this: v12);
      }
    }
    this->m_dirtyElements.m_Size = 0;
    this->m_phase = PH_OUTPUT;
  }
  CDataModel::CommitSymbols(this: g_pDataModelImp);
}

//------------------------------------------------------------------------------
// Address: 0x005008D0
// Name: public: virtual void CDmElementFramework::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this)
{
  this->m_phase = PH_OPERATE_RESOLVE;
  CDmElementFramework::Resolve(this, clearDirtyFlags: true);
  this->m_phase = PH_OUTPUT;
}

//------------------------------------------------------------------------------
// Address: 0x005008F0
// Name: public: void CDmElementFramework::RemoveCleanElementsFromDirtyList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::RemoveCleanElementsFromDirtyList(CDmElementFramework *this)
{
  int i; // edi
  CDmElement *v3; // eax
  int m_Size; // ecx

  for ( i = this->m_dirtyElements.m_Size - 1; i >= 0; --i )
  {
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[i]);
    if ( v3 != nullptr && !CDmElement::IsDirty(this: v3) )
    {
      m_Size = this->m_dirtyElements.m_Size;
      if ( m_Size > 0 )
      {
        if ( i != m_Size - 1 )
          this->m_dirtyElements.m_Memory.m_pMemory[i] = this->m_dirtyElements.m_Memory.m_pMemory[m_Size - 1];
        --this->m_dirtyElements.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00500950
// Name: public: void CDmElementFramework::AddElementToDirtyList(enum DmElementHandle_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::AddElementToDirtyList(CDmElementFramework *this, DmElementHandle_t hElement)
{
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_dirtyElements; // esi
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v6; // eax
  S3RGBA *v7; // eax

  m_nAllocationCount = this->m_dirtyElements.m_Memory.m_nAllocationCount;
  p_m_dirtyElements = (CUtlMemory<S3RGBA,int> *)&this->m_dirtyElements;
  m_Size = this->m_dirtyElements.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_dirtyElements, num: m_Size - m_nAllocationCount + 1);
  ++p_m_dirtyElements[1].m_pMemory;
  m_pMemory = p_m_dirtyElements->m_pMemory;
  v6 = (int)p_m_dirtyElements[1].m_pMemory - m_Size - 1;
  p_m_dirtyElements[1].m_nAllocationCount = (int)p_m_dirtyElements->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_dirtyElements->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (S3RGBA)hElement;
}

} // namespace makegamedata

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004B8AA0
// Name: public: virtual void __near * CDmElementFramework::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElementFramework *__thiscall CDmElementFramework::QueryInterface(
        CDmElementFramework *this,
        const char *pInterfaceName)
{
  return _V_strcmp(s1: pInterfaceName, s2: "VDmElementFrameworkVersion001") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004B8AD0
// Name: public: virtual void CDmElementFramework::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Shutdown(CDmElementFramework *this)
{
  CDependencyGraph::Cleanup(this: &this->m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x004B8AE0
// Name: public: virtual void CDmElementFramework::SetOperators(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::SetOperators(
        CDmElementFramework *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  CDependencyGraph::Reset(this: &this->m_dependencyGraph, operators);
}

//------------------------------------------------------------------------------
// Address: 0x004B8B00
// Name: private: void CDmElementFramework::Resolve(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this, bool clearDirtyFlags)
{
  int v3; // edi
  int v4; // eax
  CDmElement *v5; // esi
  int nCount; // [esp+8h] [ebp-4h]

  v3 = 0;
  nCount = this->m_dirtyElements.m_Size;
  if ( nCount > 0 )
  {
    do
    {
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_dirtyElements.m_Memory.m_pMemory[v3]);
      v5 = (CDmElement *)v4;
      if ( v4 != 0 )
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
        if ( clearDirtyFlags )
        {
          CDmElement::MarkDirty(this: v5, bDirty: false);
          CDmElement::MarkAttributesClean(this: v5);
        }
      }
      ++v3;
    }
    while ( v3 < nCount );
  }
  if ( clearDirtyFlags )
    this->m_dirtyElements.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B8B80
// Name: public: virtual void CDmElementFramework::BeginEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::BeginEdit(CDmElementFramework *this)
{
  int v2; // edi
  int m_Size; // ebx
  int v4; // eax

  v2 = 0;
  if ( this->m_phase != PH_EDIT )
  {
    this->m_phase = PH_EDIT;
  }
  else
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    this->m_phase = PH_EDIT_RESOLVE;
    if ( m_Size <= 0 )
    {
      this->m_phase = PH_EDIT;
    }
    else
    {
      do
      {
        v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_dirtyElements.m_Memory.m_pMemory[v2]);
        if ( v4 != 0 )
          (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
        ++v2;
      }
      while ( v2 < m_Size );
      this->m_phase = PH_EDIT;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B8BF0
// Name: public: virtual void CDmElementFramework::Operate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Operate(CDmElementFramework *this, bool bResolve)
{
  int m_Size; // ebx
  int v4; // edi
  int v5; // eax
  unsigned int v6; // ebx
  unsigned int i; // edi
  IDmeOperator *v8; // ecx
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  CDmElement *v12; // edi
  int bResolvea; // [esp+14h] [ebp+8h]

  if ( this->m_phase == PH_EDIT )
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    v4 = 0;
    for ( this->m_phase = PH_EDIT_RESOLVE; v4 < m_Size; ++v4 )
    {
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_dirtyElements.m_Memory.m_pMemory[v4]);
      if ( v5 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
    }
  }
  this->m_phase = PH_DEPENDENCY;
  if ( CDependencyGraph::CullAndSortOperators(this: &this->m_dependencyGraph) )
    _Warning(a1: "Operator cycle found during dependency graph traversal!\n");
  this->m_phase = PH_OPERATE;
  v6 = this->m_dependencyGraph.m_operators.m_Size;
  for ( i = 0; i < v6; ++i )
  {
    v8 = this->m_dependencyGraph.m_operators.m_Memory.m_pMemory[i];
    v8->Operate(this: v8);
  }
  if ( bResolve )
  {
    v9 = this->m_dirtyElements.m_Size;
    v10 = 0;
    this->m_phase = PH_OPERATE_RESOLVE;
    for ( bResolvea = v9; v10 < bResolvea; ++v10 )
    {
      v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
              a1: g_pDataModel.u,
              a2: this->m_dirtyElements.m_Memory.m_pMemory[v10]);
      v12 = (CDmElement *)v11;
      if ( v11 != 0 )
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 12))(a1: v11);
        CDmElement::MarkDirty(this: v12, bDirty: false);
        CDmElement::MarkAttributesClean(this: v12);
      }
    }
    this->m_dirtyElements.m_Size = 0;
    this->m_phase = PH_OUTPUT;
  }
  CDataModel::CommitSymbols(this: g_pDataModelImp);
}

//------------------------------------------------------------------------------
// Address: 0x004B8D10
// Name: public: virtual void CDmElementFramework::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this)
{
  this->m_phase = PH_OPERATE_RESOLVE;
  CDmElementFramework::Resolve(this, clearDirtyFlags: true);
  this->m_phase = PH_OUTPUT;
}

//------------------------------------------------------------------------------
// Address: 0x004B8D30
// Name: public: void CDmElementFramework::RemoveCleanElementsFromDirtyList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::RemoveCleanElementsFromDirtyList(CDmElementFramework *this)
{
  int i; // edi
  CDmElement *v3; // eax
  int m_Size; // ecx

  for ( i = this->m_dirtyElements.m_Size - 1; i >= 0; --i )
  {
    v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_dirtyElements.m_Memory.m_pMemory[i]);
    if ( v3 != nullptr && !CDmElement::IsDirty(this: v3) )
    {
      m_Size = this->m_dirtyElements.m_Size;
      if ( m_Size > 0 )
      {
        if ( i != m_Size - 1 )
          this->m_dirtyElements.m_Memory.m_pMemory[i] = this->m_dirtyElements.m_Memory.m_pMemory[m_Size - 1];
        --this->m_dirtyElements.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B8D90
// Name: public: void CDmElementFramework::AddElementToDirtyList(enum DmElementHandle_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::AddElementToDirtyList(
        CDmElementFramework *this,
        CUtlSymbolTable::StringPool_t *hElement)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_dirtyElements; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  m_nAllocationCount = this->m_dirtyElements.m_Memory.m_nAllocationCount;
  p_m_dirtyElements = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_dirtyElements;
  m_Size = this->m_dirtyElements.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_dirtyElements, num: m_Size - m_nAllocationCount + 1);
  ++p_m_dirtyElements[1].m_pMemory;
  m_pMemory = p_m_dirtyElements->m_pMemory;
  v6 = (int)p_m_dirtyElements[1].m_pMemory - m_Size - 1;
  p_m_dirtyElements[1].m_nAllocationCount = (int)p_m_dirtyElements->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_dirtyElements->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = hElement;
}

//------------------------------------------------------------------------------
// Address: 0x004F55A0
// Name: public: virtual enum DmPhase_t CDmElementFramework::GetPhase(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmElementFramework::GetPhase(CDmeDag *this)
{
  return this->m_Children.m_Storage.m_Size;
}

} // namespace mdlcompile

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x00445C90
// Name: public: virtual bool CDmElementFramework::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmElementFramework::Connect(CDmElementFramework *this, void *(__cdecl *factory)(const char *, int *))
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00445CA0
// Name: public: virtual void __near * CDmElementFramework::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElementFramework *__thiscall CDmElementFramework::QueryInterface(
        CDmElementFramework *this,
        const char *pInterfaceName)
{
  return _V_strcmp(s1: pInterfaceName, s2: "VDmElementFrameworkVersion001") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00445CD0
// Name: public: virtual void CDmElementFramework::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Shutdown(CDmElementFramework *this)
{
  CDependencyGraph::Cleanup(this: &this->m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x00445CE0
// Name: public: virtual enum DmPhase_t CDmElementFramework::GetPhase(void)
// Source: json
//------------------------------------------------------------------------------
DmPhase_t __thiscall CDmElementFramework::GetPhase(CDmElementFramework *this)
{
  return this->m_phase;
}

//------------------------------------------------------------------------------
// Address: 0x00445CF0
// Name: public: virtual void CDmElementFramework::SetOperators(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::SetOperators(
        CDmElementFramework *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  CDependencyGraph::Reset(this: &this->m_dependencyGraph, operators);
}

//------------------------------------------------------------------------------
// Address: 0x00445D10
// Name: private: void CDmElementFramework::Resolve(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this, bool clearDirtyFlags)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  int nCount; // [esp+8h] [ebp-4h]

  v3 = 0;
  nCount = this->m_dirtyElements.m_Size;
  if ( nCount > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != nullptr )
      {
        v4->Resolve(this: v4);
        if ( clearDirtyFlags )
        {
          CDmElement::MarkDirty(this: v5, bDirty: false);
          CDmElement::MarkAttributesClean(this: v5);
        }
      }
      ++v3;
    }
    while ( v3 < nCount );
  }
  if ( clearDirtyFlags )
    this->m_dirtyElements.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00445D90
// Name: public: virtual void CDmElementFramework::BeginEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::BeginEdit(CDmElementFramework *this)
{
  int v2; // edi
  int m_Size; // ebx
  CDmElement *v4; // eax

  v2 = 0;
  if ( this->m_phase != PH_EDIT )
  {
    this->m_phase = PH_EDIT;
  }
  else
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    this->m_phase = PH_EDIT_RESOLVE;
    if ( m_Size <= 0 )
    {
      this->m_phase = PH_EDIT;
    }
    else
    {
      do
      {
        v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v2]);
        if ( v4 != nullptr )
          v4->Resolve(this: v4);
        ++v2;
      }
      while ( v2 < m_Size );
      this->m_phase = PH_EDIT;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00445E00
// Name: public: virtual void CDmElementFramework::Operate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Operate(CDmElementFramework *this, bool bResolve)
{
  int m_Size; // ebx
  int v4; // edi
  CDmElement *v5; // eax
  unsigned int v6; // ebx
  unsigned int i; // edi
  IDmeOperator *v8; // ecx
  int v9; // eax
  int v10; // ebx
  CDmElement *v11; // eax
  CDmElement *v12; // edi
  int bResolvea; // [esp+14h] [ebp+8h]

  if ( this->m_phase == PH_EDIT )
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    v4 = 0;
    for ( this->m_phase = PH_EDIT_RESOLVE; v4 < m_Size; ++v4 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v4]);
      if ( v5 != nullptr )
        v5->Resolve(this: v5);
    }
  }
  this->m_phase = PH_DEPENDENCY;
  if ( CDependencyGraph::CullAndSortOperators(this: &this->m_dependencyGraph) )
    _Warning(a1: "Operator cycle found during dependency graph traversal!\n");
  this->m_phase = PH_OPERATE;
  v6 = this->m_dependencyGraph.m_operators.m_Size;
  for ( i = 0; i < v6; ++i )
  {
    v8 = this->m_dependencyGraph.m_operators.m_Memory.m_pMemory[i];
    v8->Operate(this: v8);
  }
  if ( bResolve )
  {
    v9 = this->m_dirtyElements.m_Size;
    v10 = 0;
    this->m_phase = PH_OPERATE_RESOLVE;
    for ( bResolvea = v9; v10 < bResolvea; ++v10 )
    {
      v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v10]);
      v12 = v11;
      if ( v11 != nullptr )
      {
        v11->Resolve(this: v11);
        CDmElement::MarkDirty(this: v12, bDirty: false);
        CDmElement::MarkAttributesClean(this: v12);
      }
    }
    this->m_dirtyElements.m_Size = 0;
    this->m_phase = PH_OUTPUT;
  }
  CDataModel::CommitSymbols(this: g_pDataModelImp);
}

//------------------------------------------------------------------------------
// Address: 0x00445F20
// Name: public: virtual void CDmElementFramework::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this)
{
  this->m_phase = PH_OPERATE_RESOLVE;
  CDmElementFramework::Resolve(this, clearDirtyFlags: true);
  this->m_phase = PH_OUTPUT;
}

//------------------------------------------------------------------------------
// Address: 0x00445F40
// Name: public: void CDmElementFramework::RemoveCleanElementsFromDirtyList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::RemoveCleanElementsFromDirtyList(CDmElementFramework *this)
{
  int i; // edi
  CDmElement *v3; // eax
  int m_Size; // ecx

  for ( i = this->m_dirtyElements.m_Size - 1; i >= 0; --i )
  {
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[i]);
    if ( v3 != nullptr && !CDmElement::IsDirty(this: v3) )
    {
      m_Size = this->m_dirtyElements.m_Size;
      if ( m_Size > 0 )
      {
        if ( i != m_Size - 1 )
          this->m_dirtyElements.m_Memory.m_pMemory[i] = this->m_dirtyElements.m_Memory.m_pMemory[m_Size - 1];
        --this->m_dirtyElements.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00445FA0
// Name: public: void CDmElementFramework::AddElementToDirtyList(enum DmElementHandle_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::AddElementToDirtyList(
        CDmElementFramework *this,
        CUtlSymbolTable::StringPool_t *hElement)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_dirtyElements; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  m_nAllocationCount = this->m_dirtyElements.m_Memory.m_nAllocationCount;
  p_m_dirtyElements = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_dirtyElements;
  m_Size = this->m_dirtyElements.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_dirtyElements, num: m_Size - m_nAllocationCount + 1);
  ++p_m_dirtyElements[1].m_pMemory;
  m_pMemory = p_m_dirtyElements->m_pMemory;
  v6 = (int)p_m_dirtyElements[1].m_pMemory - m_Size - 1;
  p_m_dirtyElements[1].m_nAllocationCount = (int)p_m_dirtyElements->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_dirtyElements->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = hElement;
}

} // namespace mksheet

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0043F000
// Name: public: virtual void __near * CDmElementFramework::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElementFramework *__thiscall CDmElementFramework::QueryInterface(
        CDmElementFramework *this,
        const char *pInterfaceName)
{
  return _V_strcmp(s1: pInterfaceName, s2: "VDmElementFrameworkVersion001") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0043F030
// Name: public: virtual void CDmElementFramework::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Shutdown(CDmElementFramework *this)
{
  CDependencyGraph::Cleanup(this: &this->m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x0043F040
// Name: public: virtual enum DmPhase_t CDmElementFramework::GetPhase(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmElementFramework::GetPhase(CDmeDag *this)
{
  return this->m_Children.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0043F050
// Name: public: virtual void CDmElementFramework::SetOperators(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::SetOperators(
        CDmElementFramework *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  CDependencyGraph::Reset(this: &this->m_dependencyGraph, operators);
}

//------------------------------------------------------------------------------
// Address: 0x0043F070
// Name: private: void CDmElementFramework::Resolve(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this, bool clearDirtyFlags)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  int nCount; // [esp+8h] [ebp-4h]

  v3 = 0;
  nCount = this->m_dirtyElements.m_Size;
  if ( nCount > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != nullptr )
      {
        v4->Resolve(this: v4);
        if ( clearDirtyFlags )
        {
          CDmElement::MarkDirty(this: v5, bDirty: false);
          CDmElement::MarkAttributesClean(this: v5);
        }
      }
      ++v3;
    }
    while ( v3 < nCount );
  }
  if ( clearDirtyFlags )
    this->m_dirtyElements.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043F0F0
// Name: public: virtual void CDmElementFramework::BeginEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::BeginEdit(CDmElementFramework *this)
{
  int v2; // edi
  int m_Size; // ebx
  CDmElement *v4; // eax

  v2 = 0;
  if ( this->m_phase != PH_EDIT )
  {
    this->m_phase = PH_EDIT;
  }
  else
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    this->m_phase = PH_EDIT_RESOLVE;
    if ( m_Size <= 0 )
    {
      this->m_phase = PH_EDIT;
    }
    else
    {
      do
      {
        v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v2]);
        if ( v4 != nullptr )
          v4->Resolve(this: v4);
        ++v2;
      }
      while ( v2 < m_Size );
      this->m_phase = PH_EDIT;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043F160
// Name: public: virtual void CDmElementFramework::Operate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Operate(CDmElementFramework *this, bool bResolve)
{
  int m_Size; // ebx
  int v4; // edi
  CDmElement *v5; // eax
  unsigned int v6; // ebx
  unsigned int i; // edi
  IDmeOperator *v8; // ecx
  int v9; // eax
  int v10; // ebx
  CDmElement *v11; // eax
  CDmElement *v12; // edi
  int bResolvea; // [esp+14h] [ebp+8h]

  if ( this->m_phase == PH_EDIT )
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    v4 = 0;
    for ( this->m_phase = PH_EDIT_RESOLVE; v4 < m_Size; ++v4 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v4]);
      if ( v5 != nullptr )
        v5->Resolve(this: v5);
    }
  }
  this->m_phase = PH_DEPENDENCY;
  if ( CDependencyGraph::CullAndSortOperators(this: &this->m_dependencyGraph) )
    _Warning(a1: "Operator cycle found during dependency graph traversal!\n");
  this->m_phase = PH_OPERATE;
  v6 = this->m_dependencyGraph.m_operators.m_Size;
  for ( i = 0; i < v6; ++i )
  {
    v8 = this->m_dependencyGraph.m_operators.m_Memory.m_pMemory[i];
    v8->Operate(this: v8);
  }
  if ( bResolve )
  {
    v9 = this->m_dirtyElements.m_Size;
    v10 = 0;
    this->m_phase = PH_OPERATE_RESOLVE;
    for ( bResolvea = v9; v10 < bResolvea; ++v10 )
    {
      v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v10]);
      v12 = v11;
      if ( v11 != nullptr )
      {
        v11->Resolve(this: v11);
        CDmElement::MarkDirty(this: v12, bDirty: false);
        CDmElement::MarkAttributesClean(this: v12);
      }
    }
    this->m_dirtyElements.m_Size = 0;
    this->m_phase = PH_OUTPUT;
  }
  CDataModel::CommitSymbols(this: g_pDataModelImp);
}

//------------------------------------------------------------------------------
// Address: 0x0043F280
// Name: public: virtual void CDmElementFramework::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this)
{
  this->m_phase = PH_OPERATE_RESOLVE;
  CDmElementFramework::Resolve(this, clearDirtyFlags: true);
  this->m_phase = PH_OUTPUT;
}

//------------------------------------------------------------------------------
// Address: 0x0043F2A0
// Name: public: void CDmElementFramework::RemoveCleanElementsFromDirtyList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::RemoveCleanElementsFromDirtyList(CDmElementFramework *this)
{
  int i; // edi
  CDmElement *v3; // eax
  int m_Size; // ecx

  for ( i = this->m_dirtyElements.m_Size - 1; i >= 0; --i )
  {
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[i]);
    if ( v3 != nullptr && !CDmElement::IsDirty(this: v3) )
    {
      m_Size = this->m_dirtyElements.m_Size;
      if ( m_Size > 0 )
      {
        if ( i != m_Size - 1 )
          this->m_dirtyElements.m_Memory.m_pMemory[i] = this->m_dirtyElements.m_Memory.m_pMemory[m_Size - 1];
        --this->m_dirtyElements.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043F300
// Name: public: void CDmElementFramework::AddElementToDirtyList(enum DmElementHandle_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::AddElementToDirtyList(
        CDmElementFramework *this,
        CUtlSymbolTable::StringPool_t *hElement)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_dirtyElements; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  m_nAllocationCount = this->m_dirtyElements.m_Memory.m_nAllocationCount;
  p_m_dirtyElements = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_dirtyElements;
  m_Size = this->m_dirtyElements.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_dirtyElements, num: m_Size - m_nAllocationCount + 1);
  ++p_m_dirtyElements[1].m_pMemory;
  m_pMemory = p_m_dirtyElements->m_pMemory;
  v6 = (int)p_m_dirtyElements[1].m_pMemory - m_Size - 1;
  p_m_dirtyElements[1].m_nAllocationCount = (int)p_m_dirtyElements->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_dirtyElements->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = hElement;
}

} // namespace particle_import

// ============================================================
// Overlay from pcffix (Missing functions)
// ============================================================
namespace pcffix {

//------------------------------------------------------------------------------
// Address: 0x0040F520
// Name: public: virtual enum InitReturnVal_t CDmElementFramework::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmElementFramework::Init(CDmFormatUpdater_dmx *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0043CD20
// Name: public: virtual bool CDmElementFramework::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmElementFramework::Connect(CDmElementFramework *this, void *(__cdecl *factory)(const char *, int *))
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0043CD30
// Name: public: virtual void __near * CDmElementFramework::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElementFramework *__thiscall CDmElementFramework::QueryInterface(
        CDmElementFramework *this,
        const char *pInterfaceName)
{
  return strcmp(pInterfaceName, "VDmElementFrameworkVersion001") != 0 ? nullptr : this;
}

//------------------------------------------------------------------------------
// Address: 0x0043CD60
// Name: public: virtual void CDmElementFramework::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Shutdown(CDmElementFramework *this)
{
  CDependencyGraph::Cleanup(this: &this->m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x0043CD70
// Name: public: virtual enum DmPhase_t CDmElementFramework::GetPhase(void)
// Source: json
//------------------------------------------------------------------------------
DmPhase_t __thiscall CDmElementFramework::GetPhase(CDmElementFramework *this)
{
  return this->m_phase;
}

//------------------------------------------------------------------------------
// Address: 0x0043CD80
// Name: public: virtual void CDmElementFramework::SetOperators(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::SetOperators(
        CDmElementFramework *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  CDependencyGraph::Reset(this: &this->m_dependencyGraph, operators);
}

//------------------------------------------------------------------------------
// Address: 0x0043CD90
// Name: private: void CDmElementFramework::Resolve(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this, bool clearDirtyFlags)
{
  int m_Size; // ebx
  int i; // edi
  CDmElement *v5; // eax
  CDmElement *v6; // esi

  m_Size = this->m_dirtyElements.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[i]);
    v6 = v5;
    if ( v5 != nullptr )
    {
      v5->Resolve(this: v5);
      if ( clearDirtyFlags )
      {
        CDmElement::MarkDirty(this: v6, bDirty: false);
        CDmElement::MarkAttributesClean(this: v6);
      }
    }
  }
  if ( clearDirtyFlags )
    this->m_dirtyElements.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043CE00
// Name: public: virtual void CDmElementFramework::BeginEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::BeginEdit(CDmElementFramework *this)
{
  int m_Size; // ebx
  int v3; // edi
  CDmElement *v4; // eax

  if ( this->m_phase != PH_EDIT )
  {
    this->m_phase = PH_EDIT;
  }
  else
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    v3 = 0;
    this->m_phase = PH_EDIT_RESOLVE;
    if ( m_Size <= 0 )
    {
      this->m_phase = PH_EDIT;
    }
    else
    {
      do
      {
        v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v3]);
        if ( v4 != nullptr )
          v4->Resolve(this: v4);
        ++v3;
      }
      while ( v3 < m_Size );
      this->m_phase = PH_EDIT;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043CE80
// Name: public: virtual void CDmElementFramework::Operate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Operate(CDmElementFramework *this, bool bResolve)
{
  unsigned int m_Size; // ebx
  unsigned int i; // edi
  IDmeOperator *v5; // ecx
  int v6; // ebp
  int v7; // ebx
  CDmElement *v8; // eax
  CDmElement *v9; // edi

  if ( this->m_phase == PH_EDIT )
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    this->m_phase = PH_EDIT_RESOLVE;
    CDmElementFramework::Resolve(this, clearDirtyFlags: true);
  }
  this->m_phase = PH_DEPENDENCY;
  if ( CDependencyGraph::CullAndSortOperators(this: &this->m_dependencyGraph) )
    _Warning(a1: "Operator cycle found during dependency graph traversal!\n");
  this->m_phase = PH_OPERATE;
  m_Size = this->m_dependencyGraph.m_operators.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v5 = this->m_dependencyGraph.m_operators.m_Memory.m_pMemory[i];
    v5->Operate(this: v5);
  }
  if ( bResolve )
  {
    v6 = this->m_dirtyElements.m_Size;
    v7 = 0;
    for ( this->m_phase = PH_OPERATE_RESOLVE; v7 < v6; ++v7 )
    {
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v7]);
      v9 = v8;
      if ( v8 != nullptr )
      {
        v8->Resolve(this: v8);
        CDmElement::MarkDirty(this: v9, bDirty: false);
        CDmElement::MarkAttributesClean(this: v9);
      }
    }
    this->m_dirtyElements.m_Size = 0;
    this->m_phase = PH_OUTPUT;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043CF60
// Name: public: virtual void CDmElementFramework::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this)
{
  this->m_phase = PH_OPERATE_RESOLVE;
  CDmElementFramework::Resolve(this, clearDirtyFlags: true);
  this->m_phase = PH_OUTPUT;
}

//------------------------------------------------------------------------------
// Address: 0x0043CF80
// Name: public: void CDmElementFramework::RemoveCleanElementsFromDirtyList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::RemoveCleanElementsFromDirtyList(CDmElementFramework *this)
{
  int i; // edi
  CDmElement *v3; // eax
  int m_Size; // ecx

  for ( i = this->m_dirtyElements.m_Size - 1; i >= 0; --i )
  {
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[i]);
    if ( v3 != nullptr && !CDmElement::IsDirty(this: v3) )
    {
      m_Size = this->m_dirtyElements.m_Size;
      if ( m_Size > 0 )
      {
        this->m_dirtyElements.m_Memory.m_pMemory[i] = this->m_dirtyElements.m_Memory.m_pMemory[m_Size - 1];
        --this->m_dirtyElements.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043CFD0
// Name: public: void CDmElementFramework::AddElementToDirtyList(enum DmElementHandle_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::AddElementToDirtyList(CDmElementFramework *this, DmElementHandle_t hElement)
{
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertBefore(
    this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_dirtyElements,
    elem: this->m_dirtyElements.m_Size,
    src: (CUtlSymbolTable::StringPool_t **)&hElement);
}

} // namespace pcffix

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x0043D400
// Name: public: virtual bool CDmElementFramework::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmElementFramework::Connect(CDmElementFramework *this, void *(__cdecl *factory)(const char *, int *))
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0043D410
// Name: public: virtual void __near * CDmElementFramework::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElementFramework *__thiscall CDmElementFramework::QueryInterface(
        CDmElementFramework *this,
        const char *pInterfaceName)
{
  return _V_strcmp(s1: pInterfaceName, s2: "VDmElementFrameworkVersion001") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0043D440
// Name: public: virtual void CDmElementFramework::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Shutdown(CDmElementFramework *this)
{
  CDependencyGraph::Cleanup(this: &this->m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x0043D450
// Name: public: virtual enum DmPhase_t CDmElementFramework::GetPhase(void)
// Source: json
//------------------------------------------------------------------------------
DmPhase_t __thiscall CDmElementFramework::GetPhase(CDmElementFramework *this)
{
  return this->m_phase;
}

//------------------------------------------------------------------------------
// Address: 0x0043D460
// Name: public: virtual void CDmElementFramework::SetOperators(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::SetOperators(
        CDmElementFramework *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  CDependencyGraph::Reset(this: &this->m_dependencyGraph, operators);
}

//------------------------------------------------------------------------------
// Address: 0x0043D480
// Name: private: void CDmElementFramework::Resolve(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this, bool clearDirtyFlags)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  int nCount; // [esp+8h] [ebp-4h]

  v3 = 0;
  nCount = this->m_dirtyElements.m_Size;
  if ( nCount > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != nullptr )
      {
        v4->Resolve(this: v4);
        if ( clearDirtyFlags )
        {
          CDmElement::MarkDirty(this: v5, bDirty: false);
          CDmElement::MarkAttributesClean(this: v5);
        }
      }
      ++v3;
    }
    while ( v3 < nCount );
  }
  if ( clearDirtyFlags )
    this->m_dirtyElements.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043D500
// Name: public: virtual void CDmElementFramework::BeginEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::BeginEdit(CDmElementFramework *this)
{
  int v2; // edi
  int m_Size; // ebx
  CDmElement *v4; // eax

  v2 = 0;
  if ( this->m_phase != PH_EDIT )
  {
    this->m_phase = PH_EDIT;
  }
  else
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    this->m_phase = PH_EDIT_RESOLVE;
    if ( m_Size <= 0 )
    {
      this->m_phase = PH_EDIT;
    }
    else
    {
      do
      {
        v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v2]);
        if ( v4 != nullptr )
          v4->Resolve(this: v4);
        ++v2;
      }
      while ( v2 < m_Size );
      this->m_phase = PH_EDIT;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043D570
// Name: public: virtual void CDmElementFramework::Operate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Operate(CDmElementFramework *this, bool bResolve)
{
  int m_Size; // ebx
  int v4; // edi
  CDmElement *v5; // eax
  unsigned int v6; // ebx
  unsigned int i; // edi
  IDmeOperator *v8; // ecx
  int v9; // eax
  int v10; // ebx
  CDmElement *v11; // eax
  CDmElement *v12; // edi
  int bResolvea; // [esp+14h] [ebp+8h]

  if ( this->m_phase == PH_EDIT )
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    v4 = 0;
    for ( this->m_phase = PH_EDIT_RESOLVE; v4 < m_Size; ++v4 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v4]);
      if ( v5 != nullptr )
        v5->Resolve(this: v5);
    }
  }
  this->m_phase = PH_DEPENDENCY;
  if ( CDependencyGraph::CullAndSortOperators(this: &this->m_dependencyGraph) )
    _Warning(a1: "Operator cycle found during dependency graph traversal!\n");
  this->m_phase = PH_OPERATE;
  v6 = this->m_dependencyGraph.m_operators.m_Size;
  for ( i = 0; i < v6; ++i )
  {
    v8 = this->m_dependencyGraph.m_operators.m_Memory.m_pMemory[i];
    v8->Operate(this: v8);
  }
  if ( bResolve )
  {
    v9 = this->m_dirtyElements.m_Size;
    v10 = 0;
    this->m_phase = PH_OPERATE_RESOLVE;
    for ( bResolvea = v9; v10 < bResolvea; ++v10 )
    {
      v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v10]);
      v12 = v11;
      if ( v11 != nullptr )
      {
        v11->Resolve(this: v11);
        CDmElement::MarkDirty(this: v12, bDirty: false);
        CDmElement::MarkAttributesClean(this: v12);
      }
    }
    this->m_dirtyElements.m_Size = 0;
    this->m_phase = PH_OUTPUT;
  }
  CDataModel::CommitSymbols(this: g_pDataModelImp);
}

//------------------------------------------------------------------------------
// Address: 0x0043D690
// Name: public: virtual void CDmElementFramework::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this)
{
  this->m_phase = PH_OPERATE_RESOLVE;
  CDmElementFramework::Resolve(this, clearDirtyFlags: true);
  this->m_phase = PH_OUTPUT;
}

//------------------------------------------------------------------------------
// Address: 0x0043D6B0
// Name: public: void CDmElementFramework::RemoveCleanElementsFromDirtyList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::RemoveCleanElementsFromDirtyList(CDmElementFramework *this)
{
  int i; // edi
  CDmElement *v3; // eax
  int m_Size; // ecx

  for ( i = this->m_dirtyElements.m_Size - 1; i >= 0; --i )
  {
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[i]);
    if ( v3 != nullptr && !CDmElement::IsDirty(this: v3) )
    {
      m_Size = this->m_dirtyElements.m_Size;
      if ( m_Size > 0 )
      {
        if ( i != m_Size - 1 )
          this->m_dirtyElements.m_Memory.m_pMemory[i] = this->m_dirtyElements.m_Memory.m_pMemory[m_Size - 1];
        --this->m_dirtyElements.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043D710
// Name: public: void CDmElementFramework::AddElementToDirtyList(enum DmElementHandle_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::AddElementToDirtyList(
        CDmElementFramework *this,
        CUtlSymbolTable::StringPool_t *hElement)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_dirtyElements; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  m_nAllocationCount = this->m_dirtyElements.m_Memory.m_nAllocationCount;
  p_m_dirtyElements = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_dirtyElements;
  m_Size = this->m_dirtyElements.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_dirtyElements, num: m_Size - m_nAllocationCount + 1);
  ++p_m_dirtyElements[1].m_pMemory;
  m_pMemory = p_m_dirtyElements->m_pMemory;
  v6 = (int)p_m_dirtyElements[1].m_pMemory - m_Size - 1;
  p_m_dirtyElements[1].m_nAllocationCount = (int)p_m_dirtyElements->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_dirtyElements->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = hElement;
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x004427A0
// Name: public: virtual bool CDmElementFramework::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmElementFramework::Connect(CDmElementFramework *this, void *(__cdecl *factory)(const char *, int *))
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004427B0
// Name: public: virtual void __near * CDmElementFramework::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElementFramework *__thiscall CDmElementFramework::QueryInterface(
        CDmElementFramework *this,
        const char *pInterfaceName)
{
  return _V_strcmp(s1: pInterfaceName, s2: "VDmElementFrameworkVersion001") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004427E0
// Name: public: virtual void CDmElementFramework::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Shutdown(CDmElementFramework *this)
{
  CDependencyGraph::Cleanup(this: &this->m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x004427F0
// Name: public: virtual enum DmPhase_t CDmElementFramework::GetPhase(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmElementFramework::GetPhase(CDmeDag *this)
{
  return this->m_Children.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00442800
// Name: public: virtual void CDmElementFramework::SetOperators(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::SetOperators(
        CDmElementFramework *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  CDependencyGraph::Reset(this: &this->m_dependencyGraph, operators);
}

//------------------------------------------------------------------------------
// Address: 0x00442820
// Name: private: void CDmElementFramework::Resolve(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this, bool clearDirtyFlags)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  int nCount; // [esp+8h] [ebp-4h]

  v3 = 0;
  nCount = this->m_dirtyElements.m_Size;
  if ( nCount > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != nullptr )
      {
        v4->Resolve(this: v4);
        if ( clearDirtyFlags )
        {
          CDmElement::MarkDirty(this: v5, bDirty: false);
          CDmElement::MarkAttributesClean(this: v5);
        }
      }
      ++v3;
    }
    while ( v3 < nCount );
  }
  if ( clearDirtyFlags )
    this->m_dirtyElements.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004428A0
// Name: public: virtual void CDmElementFramework::BeginEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::BeginEdit(CDmElementFramework *this)
{
  int v2; // edi
  int m_Size; // ebx
  CDmElement *v4; // eax

  v2 = 0;
  if ( this->m_phase != PH_EDIT )
  {
    this->m_phase = PH_EDIT;
  }
  else
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    this->m_phase = PH_EDIT_RESOLVE;
    if ( m_Size <= 0 )
    {
      this->m_phase = PH_EDIT;
    }
    else
    {
      do
      {
        v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v2]);
        if ( v4 != nullptr )
          v4->Resolve(this: v4);
        ++v2;
      }
      while ( v2 < m_Size );
      this->m_phase = PH_EDIT;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00442910
// Name: public: virtual void CDmElementFramework::Operate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Operate(CDmElementFramework *this, bool bResolve)
{
  int m_Size; // ebx
  int v4; // edi
  CDmElement *v5; // eax
  unsigned int v6; // ebx
  unsigned int i; // edi
  IDmeOperator *v8; // ecx
  int v9; // eax
  int v10; // ebx
  CDmElement *v11; // eax
  CDmElement *v12; // edi
  int bResolvea; // [esp+14h] [ebp+8h]

  if ( this->m_phase == PH_EDIT )
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    v4 = 0;
    for ( this->m_phase = PH_EDIT_RESOLVE; v4 < m_Size; ++v4 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v4]);
      if ( v5 != nullptr )
        v5->Resolve(this: v5);
    }
  }
  this->m_phase = PH_DEPENDENCY;
  if ( CDependencyGraph::CullAndSortOperators(this: &this->m_dependencyGraph) )
    _Warning(a1: "Operator cycle found during dependency graph traversal!\n");
  this->m_phase = PH_OPERATE;
  v6 = this->m_dependencyGraph.m_operators.m_Size;
  for ( i = 0; i < v6; ++i )
  {
    v8 = this->m_dependencyGraph.m_operators.m_Memory.m_pMemory[i];
    v8->Operate(this: v8);
  }
  if ( bResolve )
  {
    v9 = this->m_dirtyElements.m_Size;
    v10 = 0;
    this->m_phase = PH_OPERATE_RESOLVE;
    for ( bResolvea = v9; v10 < bResolvea; ++v10 )
    {
      v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v10]);
      v12 = v11;
      if ( v11 != nullptr )
      {
        v11->Resolve(this: v11);
        CDmElement::MarkDirty(this: v12, bDirty: false);
        CDmElement::MarkAttributesClean(this: v12);
      }
    }
    this->m_dirtyElements.m_Size = 0;
    this->m_phase = PH_OUTPUT;
  }
  CDataModel::CommitSymbols(this: g_pDataModelImp);
}

//------------------------------------------------------------------------------
// Address: 0x00442A30
// Name: public: virtual void CDmElementFramework::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this)
{
  this->m_phase = PH_OPERATE_RESOLVE;
  CDmElementFramework::Resolve(this, clearDirtyFlags: true);
  this->m_phase = PH_OUTPUT;
}

//------------------------------------------------------------------------------
// Address: 0x00442A50
// Name: public: void CDmElementFramework::RemoveCleanElementsFromDirtyList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::RemoveCleanElementsFromDirtyList(CDmElementFramework *this)
{
  int i; // edi
  CDmElement *v3; // eax
  int m_Size; // ecx

  for ( i = this->m_dirtyElements.m_Size - 1; i >= 0; --i )
  {
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[i]);
    if ( v3 != nullptr && !CDmElement::IsDirty(this: v3) )
    {
      m_Size = this->m_dirtyElements.m_Size;
      if ( m_Size > 0 )
      {
        if ( i != m_Size - 1 )
          this->m_dirtyElements.m_Memory.m_pMemory[i] = this->m_dirtyElements.m_Memory.m_pMemory[m_Size - 1];
        --this->m_dirtyElements.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00442AB0
// Name: public: void CDmElementFramework::AddElementToDirtyList(enum DmElementHandle_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::AddElementToDirtyList(
        CDmElementFramework *this,
        CUtlSymbolTable::StringPool_t *hElement)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_dirtyElements; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  m_nAllocationCount = this->m_dirtyElements.m_Memory.m_nAllocationCount;
  p_m_dirtyElements = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_dirtyElements;
  m_Size = this->m_dirtyElements.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_dirtyElements, num: m_Size - m_nAllocationCount + 1);
  ++p_m_dirtyElements[1].m_pMemory;
  m_pMemory = p_m_dirtyElements->m_pMemory;
  v6 = (int)p_m_dirtyElements[1].m_pMemory - m_Size - 1;
  p_m_dirtyElements[1].m_nAllocationCount = (int)p_m_dirtyElements->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_dirtyElements->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = hElement;
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00447770
// Name: public: virtual void __near * CDmElementFramework::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElementFramework *__thiscall CDmElementFramework::QueryInterface(
        CDmElementFramework *this,
        const char *pInterfaceName)
{
  return _V_strcmp(s1: pInterfaceName, s2: "VDmElementFrameworkVersion001") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004477A0
// Name: public: virtual void CDmElementFramework::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Shutdown(CDmElementFramework *this)
{
  CDependencyGraph::Cleanup(this: &this->m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x004477B0
// Name: public: virtual void CDmElementFramework::SetOperators(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::SetOperators(
        CDmElementFramework *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  CDependencyGraph::Reset(this: &this->m_dependencyGraph, operators);
}

//------------------------------------------------------------------------------
// Address: 0x004477D0
// Name: private: void CDmElementFramework::Resolve(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this, bool clearDirtyFlags)
{
  int v3; // edi
  int v4; // eax
  CDmElement *v5; // esi
  int nCount; // [esp+8h] [ebp-4h]

  v3 = 0;
  nCount = this->m_dirtyElements.m_Size;
  if ( nCount > 0 )
  {
    do
    {
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_dirtyElements.m_Memory.m_pMemory[v3]);
      v5 = (CDmElement *)v4;
      if ( v4 != 0 )
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
        if ( clearDirtyFlags )
        {
          CDmElement::MarkDirty(this: v5, bDirty: false);
          CDmElement::MarkAttributesClean(this: v5);
        }
      }
      ++v3;
    }
    while ( v3 < nCount );
  }
  if ( clearDirtyFlags )
    this->m_dirtyElements.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00447850
// Name: public: virtual void CDmElementFramework::BeginEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::BeginEdit(CDmElementFramework *this)
{
  int v2; // edi
  int m_Size; // ebx
  int v4; // eax

  v2 = 0;
  if ( this->m_phase != PH_EDIT )
  {
    this->m_phase = PH_EDIT;
  }
  else
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    this->m_phase = PH_EDIT_RESOLVE;
    if ( m_Size <= 0 )
    {
      this->m_phase = PH_EDIT;
    }
    else
    {
      do
      {
        v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_dirtyElements.m_Memory.m_pMemory[v2]);
        if ( v4 != 0 )
          (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
        ++v2;
      }
      while ( v2 < m_Size );
      this->m_phase = PH_EDIT;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004478C0
// Name: public: virtual void CDmElementFramework::Operate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Operate(CDmElementFramework *this, bool bResolve)
{
  int m_Size; // ebx
  int v4; // edi
  int v5; // eax
  unsigned int v6; // ebx
  unsigned int i; // edi
  IDmeOperator *v8; // ecx
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  CDmElement *v12; // edi
  int bResolvea; // [esp+14h] [ebp+8h]

  if ( this->m_phase == PH_EDIT )
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    v4 = 0;
    for ( this->m_phase = PH_EDIT_RESOLVE; v4 < m_Size; ++v4 )
    {
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_dirtyElements.m_Memory.m_pMemory[v4]);
      if ( v5 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
    }
  }
  this->m_phase = PH_DEPENDENCY;
  if ( CDependencyGraph::CullAndSortOperators(this: &this->m_dependencyGraph) )
    _Warning(a1: "Operator cycle found during dependency graph traversal!\n");
  this->m_phase = PH_OPERATE;
  v6 = this->m_dependencyGraph.m_operators.m_Size;
  for ( i = 0; i < v6; ++i )
  {
    v8 = this->m_dependencyGraph.m_operators.m_Memory.m_pMemory[i];
    v8->Operate(this: v8);
  }
  if ( bResolve )
  {
    v9 = this->m_dirtyElements.m_Size;
    v10 = 0;
    this->m_phase = PH_OPERATE_RESOLVE;
    for ( bResolvea = v9; v10 < bResolvea; ++v10 )
    {
      v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
              a1: g_pDataModel.u,
              a2: this->m_dirtyElements.m_Memory.m_pMemory[v10]);
      v12 = (CDmElement *)v11;
      if ( v11 != 0 )
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 12))(a1: v11);
        CDmElement::MarkDirty(this: v12, bDirty: false);
        CDmElement::MarkAttributesClean(this: v12);
      }
    }
    this->m_dirtyElements.m_Size = 0;
    this->m_phase = PH_OUTPUT;
  }
  CDataModel::CommitSymbols(this: g_pDataModelImp);
}

//------------------------------------------------------------------------------
// Address: 0x004479E0
// Name: public: virtual void CDmElementFramework::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this)
{
  this->m_phase = PH_OPERATE_RESOLVE;
  CDmElementFramework::Resolve(this, clearDirtyFlags: true);
  this->m_phase = PH_OUTPUT;
}

//------------------------------------------------------------------------------
// Address: 0x00447A00
// Name: public: void CDmElementFramework::RemoveCleanElementsFromDirtyList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::RemoveCleanElementsFromDirtyList(CDmElementFramework *this)
{
  int i; // edi
  CDmElement *v3; // eax
  int m_Size; // ecx

  for ( i = this->m_dirtyElements.m_Size - 1; i >= 0; --i )
  {
    v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_dirtyElements.m_Memory.m_pMemory[i]);
    if ( v3 != nullptr && !CDmElement::IsDirty(this: v3) )
    {
      m_Size = this->m_dirtyElements.m_Size;
      if ( m_Size > 0 )
      {
        if ( i != m_Size - 1 )
          this->m_dirtyElements.m_Memory.m_pMemory[i] = this->m_dirtyElements.m_Memory.m_pMemory[m_Size - 1];
        --this->m_dirtyElements.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00447A60
// Name: public: void CDmElementFramework::AddElementToDirtyList(enum DmElementHandle_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::AddElementToDirtyList(CDmElementFramework *this, vgui::TreeNode *hElement)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_dirtyElements; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax

  m_nAllocationCount = this->m_dirtyElements.m_Memory.m_nAllocationCount;
  p_m_dirtyElements = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_dirtyElements;
  m_Size = this->m_dirtyElements.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_dirtyElements, num: m_Size - m_nAllocationCount + 1);
  ++p_m_dirtyElements[1].m_pMemory;
  m_pMemory = p_m_dirtyElements->m_pMemory;
  v6 = (int)p_m_dirtyElements[1].m_pMemory - m_Size - 1;
  p_m_dirtyElements[1].m_nAllocationCount = (int)p_m_dirtyElements->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_dirtyElements->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = hElement;
}

//------------------------------------------------------------------------------
// Address: 0x0051E890
// Name: public: virtual enum DmPhase_t CDmElementFramework::GetPhase(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmElementFramework::GetPhase(CDmeDag *this)
{
  return this->m_Children.m_Storage.m_Size;
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00443310
// Name: public: virtual bool CDmElementFramework::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmElementFramework::Connect(CDmElementFramework *this, void *(__cdecl *factory)(const char *, int *))
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00443320
// Name: public: virtual void __near * CDmElementFramework::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElementFramework *__thiscall CDmElementFramework::QueryInterface(
        CDmElementFramework *this,
        const char *pInterfaceName)
{
  return _V_strcmp(s1: pInterfaceName, s2: "VDmElementFrameworkVersion001") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00443350
// Name: public: virtual void CDmElementFramework::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Shutdown(CDmElementFramework *this)
{
  CDependencyGraph::Cleanup(this: &this->m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x00443360
// Name: public: virtual enum DmPhase_t CDmElementFramework::GetPhase(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmElementFramework::GetPhase(CDmeDag *this)
{
  return this->m_Children.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00443370
// Name: public: virtual void CDmElementFramework::SetOperators(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::SetOperators(
        CDmElementFramework *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  CDependencyGraph::Reset(this: &this->m_dependencyGraph, operators);
}

//------------------------------------------------------------------------------
// Address: 0x00443390
// Name: private: void CDmElementFramework::Resolve(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this, bool clearDirtyFlags)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  int nCount; // [esp+8h] [ebp-4h]

  v3 = 0;
  nCount = this->m_dirtyElements.m_Size;
  if ( nCount > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != nullptr )
      {
        v4->Resolve(this: v4);
        if ( clearDirtyFlags )
        {
          CDmElement::MarkDirty(this: v5, bDirty: false);
          CDmElement::MarkAttributesClean(this: v5);
        }
      }
      ++v3;
    }
    while ( v3 < nCount );
  }
  if ( clearDirtyFlags )
    this->m_dirtyElements.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00443410
// Name: public: virtual void CDmElementFramework::BeginEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::BeginEdit(CDmElementFramework *this)
{
  int v2; // edi
  int m_Size; // ebx
  CDmElement *v4; // eax

  v2 = 0;
  if ( this->m_phase != PH_EDIT )
  {
    this->m_phase = PH_EDIT;
  }
  else
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    this->m_phase = PH_EDIT_RESOLVE;
    if ( m_Size <= 0 )
    {
      this->m_phase = PH_EDIT;
    }
    else
    {
      do
      {
        v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v2]);
        if ( v4 != nullptr )
          v4->Resolve(this: v4);
        ++v2;
      }
      while ( v2 < m_Size );
      this->m_phase = PH_EDIT;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443480
// Name: public: virtual void CDmElementFramework::Operate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Operate(CDmElementFramework *this, bool bResolve)
{
  int m_Size; // ebx
  int v4; // edi
  CDmElement *v5; // eax
  unsigned int v6; // ebx
  unsigned int i; // edi
  IDmeOperator *v8; // ecx
  int v9; // eax
  int v10; // ebx
  CDmElement *v11; // eax
  CDmElement *v12; // edi
  int bResolvea; // [esp+14h] [ebp+8h]

  if ( this->m_phase == PH_EDIT )
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    v4 = 0;
    for ( this->m_phase = PH_EDIT_RESOLVE; v4 < m_Size; ++v4 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v4]);
      if ( v5 != nullptr )
        v5->Resolve(this: v5);
    }
  }
  this->m_phase = PH_DEPENDENCY;
  if ( CDependencyGraph::CullAndSortOperators(this: &this->m_dependencyGraph) )
    _Warning(a1: "Operator cycle found during dependency graph traversal!\n");
  this->m_phase = PH_OPERATE;
  v6 = this->m_dependencyGraph.m_operators.m_Size;
  for ( i = 0; i < v6; ++i )
  {
    v8 = this->m_dependencyGraph.m_operators.m_Memory.m_pMemory[i];
    v8->Operate(this: v8);
  }
  if ( bResolve )
  {
    v9 = this->m_dirtyElements.m_Size;
    v10 = 0;
    this->m_phase = PH_OPERATE_RESOLVE;
    for ( bResolvea = v9; v10 < bResolvea; ++v10 )
    {
      v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v10]);
      v12 = v11;
      if ( v11 != nullptr )
      {
        v11->Resolve(this: v11);
        CDmElement::MarkDirty(this: v12, bDirty: false);
        CDmElement::MarkAttributesClean(this: v12);
      }
    }
    this->m_dirtyElements.m_Size = 0;
    this->m_phase = PH_OUTPUT;
  }
  CDataModel::CommitSymbols(this: g_pDataModelImp);
}

//------------------------------------------------------------------------------
// Address: 0x004435A0
// Name: public: virtual void CDmElementFramework::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this)
{
  this->m_phase = PH_OPERATE_RESOLVE;
  CDmElementFramework::Resolve(this, clearDirtyFlags: true);
  this->m_phase = PH_OUTPUT;
}

//------------------------------------------------------------------------------
// Address: 0x004435C0
// Name: public: void CDmElementFramework::RemoveCleanElementsFromDirtyList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::RemoveCleanElementsFromDirtyList(CDmElementFramework *this)
{
  int i; // edi
  CDmElement *v3; // eax
  int m_Size; // ecx

  for ( i = this->m_dirtyElements.m_Size - 1; i >= 0; --i )
  {
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[i]);
    if ( v3 != nullptr && !CDmElement::IsDirty(this: v3) )
    {
      m_Size = this->m_dirtyElements.m_Size;
      if ( m_Size > 0 )
      {
        if ( i != m_Size - 1 )
          this->m_dirtyElements.m_Memory.m_pMemory[i] = this->m_dirtyElements.m_Memory.m_pMemory[m_Size - 1];
        --this->m_dirtyElements.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00443620
// Name: public: void CDmElementFramework::AddElementToDirtyList(enum DmElementHandle_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::AddElementToDirtyList(
        CDmElementFramework *this,
        CUtlSymbolTable::StringPool_t *hElement)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_dirtyElements; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  m_nAllocationCount = this->m_dirtyElements.m_Memory.m_nAllocationCount;
  p_m_dirtyElements = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_dirtyElements;
  m_Size = this->m_dirtyElements.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_dirtyElements, num: m_Size - m_nAllocationCount + 1);
  ++p_m_dirtyElements[1].m_pMemory;
  m_pMemory = p_m_dirtyElements->m_pMemory;
  v6 = (int)p_m_dirtyElements[1].m_pMemory - m_Size - 1;
  p_m_dirtyElements[1].m_nAllocationCount = (int)p_m_dirtyElements->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_dirtyElements->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = hElement;
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004B1EF0
// Name: public: virtual void __near * CDmElementFramework::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElementFramework *__thiscall CDmElementFramework::QueryInterface(
        CDmElementFramework *this,
        const char *pInterfaceName)
{
  return _V_strcmp(s1: pInterfaceName, s2: "VDmElementFrameworkVersion001") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004B1F20
// Name: public: virtual void CDmElementFramework::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Shutdown(CDmElementFramework *this)
{
  CDependencyGraph::Cleanup(this: &this->m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x004B1F30
// Name: public: virtual void CDmElementFramework::SetOperators(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::SetOperators(
        CDmElementFramework *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  CDependencyGraph::Reset(this: &this->m_dependencyGraph, operators);
}

//------------------------------------------------------------------------------
// Address: 0x004B1F50
// Name: private: void CDmElementFramework::Resolve(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this, bool clearDirtyFlags)
{
  int v3; // edi
  int v4; // eax
  CDmElement *v5; // esi
  int nCount; // [esp+8h] [ebp-4h]

  v3 = 0;
  nCount = this->m_dirtyElements.m_Size;
  if ( nCount > 0 )
  {
    do
    {
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_dirtyElements.m_Memory.m_pMemory[v3]);
      v5 = (CDmElement *)v4;
      if ( v4 != 0 )
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
        if ( clearDirtyFlags )
        {
          CDmElement::MarkDirty(this: v5, bDirty: false);
          CDmElement::MarkAttributesClean(this: v5);
        }
      }
      ++v3;
    }
    while ( v3 < nCount );
  }
  if ( clearDirtyFlags )
    this->m_dirtyElements.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004B1FD0
// Name: public: virtual void CDmElementFramework::BeginEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::BeginEdit(CDmElementFramework *this)
{
  int v2; // edi
  int m_Size; // ebx
  int v4; // eax

  v2 = 0;
  if ( this->m_phase != PH_EDIT )
  {
    this->m_phase = PH_EDIT;
  }
  else
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    this->m_phase = PH_EDIT_RESOLVE;
    if ( m_Size <= 0 )
    {
      this->m_phase = PH_EDIT;
    }
    else
    {
      do
      {
        v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_dirtyElements.m_Memory.m_pMemory[v2]);
        if ( v4 != 0 )
          (*(void (__thiscall **)(int))(*(_DWORD *)v4 + 12))(a1: v4);
        ++v2;
      }
      while ( v2 < m_Size );
      this->m_phase = PH_EDIT;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B2040
// Name: public: virtual void CDmElementFramework::Operate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Operate(CDmElementFramework *this, bool bResolve)
{
  int m_Size; // ebx
  int v4; // edi
  int v5; // eax
  unsigned int v6; // ebx
  unsigned int i; // edi
  IDmeOperator *v8; // ecx
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  CDmElement *v12; // edi
  int bResolvea; // [esp+14h] [ebp+8h]

  if ( this->m_phase == PH_EDIT )
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    v4 = 0;
    for ( this->m_phase = PH_EDIT_RESOLVE; v4 < m_Size; ++v4 )
    {
      v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_dirtyElements.m_Memory.m_pMemory[v4]);
      if ( v5 != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 12))(a1: v5);
    }
  }
  this->m_phase = PH_DEPENDENCY;
  if ( CDependencyGraph::CullAndSortOperators(this: &this->m_dependencyGraph) )
    _Warning(a1: "Operator cycle found during dependency graph traversal!\n");
  this->m_phase = PH_OPERATE;
  v6 = this->m_dependencyGraph.m_operators.m_Size;
  for ( i = 0; i < v6; ++i )
  {
    v8 = this->m_dependencyGraph.m_operators.m_Memory.m_pMemory[i];
    v8->Operate(this: v8);
  }
  if ( bResolve )
  {
    v9 = this->m_dirtyElements.m_Size;
    v10 = 0;
    this->m_phase = PH_OPERATE_RESOLVE;
    for ( bResolvea = v9; v10 < bResolvea; ++v10 )
    {
      v11 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
              a1: g_pDataModel.u,
              a2: this->m_dirtyElements.m_Memory.m_pMemory[v10]);
      v12 = (CDmElement *)v11;
      if ( v11 != 0 )
      {
        (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 12))(a1: v11);
        CDmElement::MarkDirty(this: v12, bDirty: false);
        CDmElement::MarkAttributesClean(this: v12);
      }
    }
    this->m_dirtyElements.m_Size = 0;
    this->m_phase = PH_OUTPUT;
  }
  CDataModel::CommitSymbols(this: g_pDataModelImp);
}

//------------------------------------------------------------------------------
// Address: 0x004B2160
// Name: public: virtual void CDmElementFramework::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this)
{
  this->m_phase = PH_OPERATE_RESOLVE;
  CDmElementFramework::Resolve(this, clearDirtyFlags: true);
  this->m_phase = PH_OUTPUT;
}

//------------------------------------------------------------------------------
// Address: 0x004B2180
// Name: public: void CDmElementFramework::RemoveCleanElementsFromDirtyList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::RemoveCleanElementsFromDirtyList(CDmElementFramework *this)
{
  int i; // edi
  CDmElement *v3; // eax
  int m_Size; // ecx

  for ( i = this->m_dirtyElements.m_Size - 1; i >= 0; --i )
  {
    v3 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                         a1: g_pDataModel.u,
                         a2: this->m_dirtyElements.m_Memory.m_pMemory[i]);
    if ( v3 != nullptr && !CDmElement::IsDirty(this: v3) )
    {
      m_Size = this->m_dirtyElements.m_Size;
      if ( m_Size > 0 )
      {
        if ( i != m_Size - 1 )
          this->m_dirtyElements.m_Memory.m_pMemory[i] = this->m_dirtyElements.m_Memory.m_pMemory[m_Size - 1];
        --this->m_dirtyElements.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B21E0
// Name: public: void CDmElementFramework::AddElementToDirtyList(enum DmElementHandle_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::AddElementToDirtyList(
        CDmElementFramework *this,
        CUtlSymbolTable::StringPool_t *hElement)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_dirtyElements; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  m_nAllocationCount = this->m_dirtyElements.m_Memory.m_nAllocationCount;
  p_m_dirtyElements = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_dirtyElements;
  m_Size = this->m_dirtyElements.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_dirtyElements, num: m_Size - m_nAllocationCount + 1);
  ++p_m_dirtyElements[1].m_pMemory;
  m_pMemory = p_m_dirtyElements->m_pMemory;
  v6 = (int)p_m_dirtyElements[1].m_pMemory - m_Size - 1;
  p_m_dirtyElements[1].m_nAllocationCount = (int)p_m_dirtyElements->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_dirtyElements->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = hElement;
}

//------------------------------------------------------------------------------
// Address: 0x004EE580
// Name: public: virtual enum DmPhase_t CDmElementFramework::GetPhase(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmElementFramework::GetPhase(CDmeDag *this)
{
  return this->m_Children.m_Storage.m_Size;
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0044DE50
// Name: public: virtual bool CDmElementFramework::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmElementFramework::Connect(CDmElementFramework *this, void *(__cdecl *factory)(const char *, int *))
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0044DE60
// Name: public: virtual void __near * CDmElementFramework::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElementFramework *__thiscall CDmElementFramework::QueryInterface(
        CDmElementFramework *this,
        const char *pInterfaceName)
{
  return _V_strcmp(s1: pInterfaceName, s2: "VDmElementFrameworkVersion001") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0044DE90
// Name: public: virtual void CDmElementFramework::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Shutdown(CDmElementFramework *this)
{
  CDependencyGraph::Cleanup(this: &this->m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x0044DEA0
// Name: public: virtual enum DmPhase_t CDmElementFramework::GetPhase(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmElementFramework::GetPhase(CDmeDag *this)
{
  return this->m_Children.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0044DEB0
// Name: public: virtual void CDmElementFramework::SetOperators(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::SetOperators(
        CDmElementFramework *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  CDependencyGraph::Reset(this: &this->m_dependencyGraph, operators);
}

//------------------------------------------------------------------------------
// Address: 0x0044DED0
// Name: private: void CDmElementFramework::Resolve(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this, bool clearDirtyFlags)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  int nCount; // [esp+8h] [ebp-4h]

  v3 = 0;
  nCount = this->m_dirtyElements.m_Size;
  if ( nCount > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != nullptr )
      {
        v4->Resolve(this: v4);
        if ( clearDirtyFlags )
        {
          CDmElement::MarkDirty(this: v5, bDirty: false);
          CDmElement::MarkAttributesClean(this: v5);
        }
      }
      ++v3;
    }
    while ( v3 < nCount );
  }
  if ( clearDirtyFlags )
    this->m_dirtyElements.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044DF50
// Name: public: virtual void CDmElementFramework::BeginEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::BeginEdit(CDmElementFramework *this)
{
  int v2; // edi
  int m_Size; // ebx
  CDmElement *v4; // eax

  v2 = 0;
  if ( this->m_phase != PH_EDIT )
  {
    this->m_phase = PH_EDIT;
  }
  else
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    this->m_phase = PH_EDIT_RESOLVE;
    if ( m_Size <= 0 )
    {
      this->m_phase = PH_EDIT;
    }
    else
    {
      do
      {
        v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v2]);
        if ( v4 != nullptr )
          v4->Resolve(this: v4);
        ++v2;
      }
      while ( v2 < m_Size );
      this->m_phase = PH_EDIT;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044DFC0
// Name: public: virtual void CDmElementFramework::Operate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Operate(CDmElementFramework *this, bool bResolve)
{
  int m_Size; // ebx
  int v4; // edi
  CDmElement *v5; // eax
  unsigned int v6; // ebx
  unsigned int i; // edi
  IDmeOperator *v8; // ecx
  int v9; // eax
  int v10; // ebx
  CDmElement *v11; // eax
  CDmElement *v12; // edi
  int bResolvea; // [esp+14h] [ebp+8h]

  if ( this->m_phase == PH_EDIT )
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    v4 = 0;
    for ( this->m_phase = PH_EDIT_RESOLVE; v4 < m_Size; ++v4 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v4]);
      if ( v5 != nullptr )
        v5->Resolve(this: v5);
    }
  }
  this->m_phase = PH_DEPENDENCY;
  if ( CDependencyGraph::CullAndSortOperators(this: &this->m_dependencyGraph) )
    _Warning(a1: "Operator cycle found during dependency graph traversal!\n");
  this->m_phase = PH_OPERATE;
  v6 = this->m_dependencyGraph.m_operators.m_Size;
  for ( i = 0; i < v6; ++i )
  {
    v8 = this->m_dependencyGraph.m_operators.m_Memory.m_pMemory[i];
    v8->Operate(this: v8);
  }
  if ( bResolve )
  {
    v9 = this->m_dirtyElements.m_Size;
    v10 = 0;
    this->m_phase = PH_OPERATE_RESOLVE;
    for ( bResolvea = v9; v10 < bResolvea; ++v10 )
    {
      v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v10]);
      v12 = v11;
      if ( v11 != nullptr )
      {
        v11->Resolve(this: v11);
        CDmElement::MarkDirty(this: v12, bDirty: false);
        CDmElement::MarkAttributesClean(this: v12);
      }
    }
    this->m_dirtyElements.m_Size = 0;
    this->m_phase = PH_OUTPUT;
  }
  CDataModel::CommitSymbols(this: g_pDataModelImp);
}

//------------------------------------------------------------------------------
// Address: 0x0044E0E0
// Name: public: virtual void CDmElementFramework::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this)
{
  this->m_phase = PH_OPERATE_RESOLVE;
  CDmElementFramework::Resolve(this, clearDirtyFlags: true);
  this->m_phase = PH_OUTPUT;
}

//------------------------------------------------------------------------------
// Address: 0x0044E100
// Name: public: void CDmElementFramework::RemoveCleanElementsFromDirtyList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::RemoveCleanElementsFromDirtyList(CDmElementFramework *this)
{
  int i; // edi
  CDmElement *v3; // eax
  int m_Size; // ecx

  for ( i = this->m_dirtyElements.m_Size - 1; i >= 0; --i )
  {
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[i]);
    if ( v3 != nullptr && !CDmElement::IsDirty(this: v3) )
    {
      m_Size = this->m_dirtyElements.m_Size;
      if ( m_Size > 0 )
      {
        if ( i != m_Size - 1 )
          this->m_dirtyElements.m_Memory.m_pMemory[i] = this->m_dirtyElements.m_Memory.m_pMemory[m_Size - 1];
        --this->m_dirtyElements.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044E160
// Name: public: void CDmElementFramework::AddElementToDirtyList(enum DmElementHandle_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::AddElementToDirtyList(
        CDmElementFramework *this,
        CUtlSymbolTable::StringPool_t *hElement)
{
  int m_nAllocationCount; // eax
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_dirtyElements; // esi
  int m_Size; // edi
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v6; // eax
  CUtlSymbolTable::StringPool_t **v7; // eax

  m_nAllocationCount = this->m_dirtyElements.m_Memory.m_nAllocationCount;
  p_m_dirtyElements = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_dirtyElements;
  m_Size = this->m_dirtyElements.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_dirtyElements, num: m_Size - m_nAllocationCount + 1);
  ++p_m_dirtyElements[1].m_pMemory;
  m_pMemory = p_m_dirtyElements->m_pMemory;
  v6 = (int)p_m_dirtyElements[1].m_pMemory - m_Size - 1;
  p_m_dirtyElements[1].m_nAllocationCount = (int)p_m_dirtyElements->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_dirtyElements->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = hElement;
}

} // namespace uvlightmap

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x004FABA0
// Name: public: virtual enum InitReturnVal_t CDmElementFramework::Init(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmElementFramework::Init(CDmSerializerKeyValues2 *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00527240
// Name: public: virtual bool CDmElementFramework::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmElementFramework::Connect(CDmElementFramework *this, void *(__cdecl *factory)(const char *, int *))
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00527250
// Name: public: virtual void __near * CDmElementFramework::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElementFramework *__thiscall CDmElementFramework::QueryInterface(
        CDmElementFramework *this,
        const char *pInterfaceName)
{
  return _V_strcmp(s1: pInterfaceName, s2: "VDmElementFrameworkVersion001") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00527280
// Name: public: virtual void CDmElementFramework::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Shutdown(CDmElementFramework *this)
{
  CDependencyGraph::Cleanup(this: &this->m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x00527290
// Name: public: virtual enum DmPhase_t CDmElementFramework::GetPhase(void)
// Source: json
//------------------------------------------------------------------------------
DmPhase_t __thiscall CDmElementFramework::GetPhase(CDmElementFramework *this)
{
  return this->m_phase;
}

//------------------------------------------------------------------------------
// Address: 0x005272A0
// Name: public: virtual void CDmElementFramework::SetOperators(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::SetOperators(
        CDmElementFramework *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  CDependencyGraph::Reset(this: &this->m_dependencyGraph, operators);
}

//------------------------------------------------------------------------------
// Address: 0x005272C0
// Name: private: void CDmElementFramework::Resolve(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this, bool clearDirtyFlags)
{
  int m_Size; // ebx
  int i; // edi
  CDmElement *v5; // eax
  CDmElement *v6; // esi

  m_Size = this->m_dirtyElements.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[i]);
    v6 = v5;
    if ( v5 != nullptr )
    {
      v5->Resolve(this: v5);
      if ( clearDirtyFlags )
      {
        CDmElement::MarkDirty(this: v6, bDirty: false);
        CDmElement::MarkAttributesClean(this: v6);
      }
    }
  }
  if ( clearDirtyFlags )
    this->m_dirtyElements.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00527330
// Name: public: virtual void CDmElementFramework::BeginEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::BeginEdit(CDmElementFramework *this)
{
  int m_Size; // ebx
  int v3; // edi
  CDmElement *v4; // eax

  if ( this->m_phase != PH_EDIT )
  {
    this->m_phase = PH_EDIT;
  }
  else
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    v3 = 0;
    this->m_phase = PH_EDIT_RESOLVE;
    if ( m_Size <= 0 )
    {
      this->m_phase = PH_EDIT;
    }
    else
    {
      do
      {
        v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v3]);
        if ( v4 != nullptr )
          v4->Resolve(this: v4);
        ++v3;
      }
      while ( v3 < m_Size );
      this->m_phase = PH_EDIT;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005273B0
// Name: public: virtual void CDmElementFramework::Operate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Operate(CDmElementFramework *this, bool bResolve)
{
  int m_Size; // ebx
  int v4; // edi
  CDmElement *v5; // eax
  unsigned int v6; // ebx
  unsigned int i; // edi
  IDmeOperator *v8; // ecx
  int v9; // ebp
  int v10; // ebx
  CDmElement *v11; // eax
  CDmElement *v12; // edi

  if ( this->m_phase == PH_EDIT )
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    v4 = 0;
    for ( this->m_phase = PH_EDIT_RESOLVE; v4 < m_Size; ++v4 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v4]);
      if ( v5 != nullptr )
        v5->Resolve(this: v5);
    }
  }
  this->m_phase = PH_DEPENDENCY;
  if ( CDependencyGraph::CullAndSortOperators(this: &this->m_dependencyGraph) )
    _Warning(a1: "Operator cycle found during dependency graph traversal!\n");
  this->m_phase = PH_OPERATE;
  v6 = this->m_dependencyGraph.m_operators.m_Size;
  for ( i = 0; i < v6; ++i )
  {
    v8 = this->m_dependencyGraph.m_operators.m_Memory.m_pMemory[i];
    v8->Operate(this: v8);
  }
  if ( bResolve )
  {
    v9 = this->m_dirtyElements.m_Size;
    v10 = 0;
    for ( this->m_phase = PH_OPERATE_RESOLVE; v10 < v9; ++v10 )
    {
      v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v10]);
      v12 = v11;
      if ( v11 != nullptr )
      {
        v11->Resolve(this: v11);
        CDmElement::MarkDirty(this: v12, bDirty: false);
        CDmElement::MarkAttributesClean(this: v12);
      }
    }
    this->m_dirtyElements.m_Size = 0;
    this->m_phase = PH_OUTPUT;
  }
  CDataModel::CommitSymbols(this: g_pDataModelImp);
}

//------------------------------------------------------------------------------
// Address: 0x005274D0
// Name: public: virtual void CDmElementFramework::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this)
{
  this->m_phase = PH_OPERATE_RESOLVE;
  CDmElementFramework::Resolve(this, clearDirtyFlags: true);
  this->m_phase = PH_OUTPUT;
}

//------------------------------------------------------------------------------
// Address: 0x005274F0
// Name: public: void CDmElementFramework::RemoveCleanElementsFromDirtyList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::RemoveCleanElementsFromDirtyList(CDmElementFramework *this)
{
  int i; // edi
  CDmElement *v3; // eax
  int m_Size; // ecx

  for ( i = this->m_dirtyElements.m_Size - 1; i >= 0; --i )
  {
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[i]);
    if ( v3 != nullptr && !CDmElement::IsDirty(this: v3) )
    {
      m_Size = this->m_dirtyElements.m_Size;
      if ( m_Size > 0 )
      {
        if ( i != m_Size - 1 )
          this->m_dirtyElements.m_Memory.m_pMemory[i] = this->m_dirtyElements.m_Memory.m_pMemory[m_Size - 1];
        --this->m_dirtyElements.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00527550
// Name: public: void CDmElementFramework::AddElementToDirtyList(enum DmElementHandle_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::AddElementToDirtyList(CDmElementFramework *this, DmElementHandle_t hElement)
{
  CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
    this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_dirtyElements,
    elem: this->m_dirtyElements.m_Size,
    src: (vgui::TreeNode **)&hElement);
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00545C90
// Name: public: virtual bool CDmElementFramework::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmElementFramework::Connect(CDmElementFramework *this, void *(__cdecl *factory)(const char *, int *))
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00545CA0
// Name: public: virtual void __near * CDmElementFramework::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElementFramework *__thiscall CDmElementFramework::QueryInterface(
        CDmElementFramework *this,
        const char *pInterfaceName)
{
  return _V_strcmp(s1: pInterfaceName, s2: "VDmElementFrameworkVersion001") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00545CD0
// Name: public: virtual void CDmElementFramework::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Shutdown(CDmElementFramework *this)
{
  CDependencyGraph::Cleanup(this: &this->m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x00545CE0
// Name: public: virtual enum DmPhase_t CDmElementFramework::GetPhase(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmElementFramework::GetPhase(CDmeDag *this)
{
  return this->m_Children.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00545CF0
// Name: public: virtual void CDmElementFramework::SetOperators(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::SetOperators(
        CDmElementFramework *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  CDependencyGraph::Reset(this: &this->m_dependencyGraph, operators);
}

//------------------------------------------------------------------------------
// Address: 0x00545D10
// Name: private: void CDmElementFramework::Resolve(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this, bool clearDirtyFlags)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  int nCount; // [esp+8h] [ebp-4h]

  v3 = 0;
  nCount = this->m_dirtyElements.m_Size;
  if ( nCount > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != nullptr )
      {
        v4->Resolve(this: v4);
        if ( clearDirtyFlags )
        {
          CDmElement::MarkDirty(this: v5, bDirty: false);
          CDmElement::MarkAttributesClean(this: v5);
        }
      }
      ++v3;
    }
    while ( v3 < nCount );
  }
  if ( clearDirtyFlags )
    this->m_dirtyElements.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00545D90
// Name: public: virtual void CDmElementFramework::BeginEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::BeginEdit(CDmElementFramework *this)
{
  int v2; // edi
  int m_Size; // ebx
  CDmElement *v4; // eax

  v2 = 0;
  if ( this->m_phase != PH_EDIT )
  {
    this->m_phase = PH_EDIT;
  }
  else
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    this->m_phase = PH_EDIT_RESOLVE;
    if ( m_Size <= 0 )
    {
      this->m_phase = PH_EDIT;
    }
    else
    {
      do
      {
        v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v2]);
        if ( v4 != nullptr )
          v4->Resolve(this: v4);
        ++v2;
      }
      while ( v2 < m_Size );
      this->m_phase = PH_EDIT;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00545E00
// Name: public: virtual void CDmElementFramework::Operate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Operate(CDmElementFramework *this, bool bResolve)
{
  int m_Size; // ebx
  int v4; // edi
  CDmElement *v5; // eax
  unsigned int v6; // ebx
  unsigned int i; // edi
  IDmeOperator *v8; // ecx
  int v9; // eax
  int v10; // ebx
  CDmElement *v11; // eax
  CDmElement *v12; // edi
  int bResolvea; // [esp+14h] [ebp+8h]

  if ( this->m_phase == PH_EDIT )
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    v4 = 0;
    for ( this->m_phase = PH_EDIT_RESOLVE; v4 < m_Size; ++v4 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v4]);
      if ( v5 != nullptr )
        v5->Resolve(this: v5);
    }
  }
  this->m_phase = PH_DEPENDENCY;
  if ( CDependencyGraph::CullAndSortOperators(this: &this->m_dependencyGraph) )
    _Warning(a1: "Operator cycle found during dependency graph traversal!\n");
  this->m_phase = PH_OPERATE;
  v6 = this->m_dependencyGraph.m_operators.m_Size;
  for ( i = 0; i < v6; ++i )
  {
    v8 = this->m_dependencyGraph.m_operators.m_Memory.m_pMemory[i];
    v8->Operate(this: v8);
  }
  if ( bResolve )
  {
    v9 = this->m_dirtyElements.m_Size;
    v10 = 0;
    this->m_phase = PH_OPERATE_RESOLVE;
    for ( bResolvea = v9; v10 < bResolvea; ++v10 )
    {
      v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v10]);
      v12 = v11;
      if ( v11 != nullptr )
      {
        v11->Resolve(this: v11);
        CDmElement::MarkDirty(this: v12, bDirty: false);
        CDmElement::MarkAttributesClean(this: v12);
      }
    }
    this->m_dirtyElements.m_Size = 0;
    this->m_phase = PH_OUTPUT;
  }
  CDataModel::CommitSymbols(this: g_pDataModelImp);
}

//------------------------------------------------------------------------------
// Address: 0x00545F20
// Name: public: virtual void CDmElementFramework::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this)
{
  this->m_phase = PH_OPERATE_RESOLVE;
  CDmElementFramework::Resolve(this, clearDirtyFlags: true);
  this->m_phase = PH_OUTPUT;
}

//------------------------------------------------------------------------------
// Address: 0x00545F40
// Name: public: void CDmElementFramework::RemoveCleanElementsFromDirtyList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::RemoveCleanElementsFromDirtyList(CDmElementFramework *this)
{
  int i; // edi
  CDmElement *v3; // eax
  int m_Size; // ecx

  for ( i = this->m_dirtyElements.m_Size - 1; i >= 0; --i )
  {
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[i]);
    if ( v3 != nullptr && !CDmElement::IsDirty(this: v3) )
    {
      m_Size = this->m_dirtyElements.m_Size;
      if ( m_Size > 0 )
      {
        if ( i != m_Size - 1 )
          this->m_dirtyElements.m_Memory.m_pMemory[i] = this->m_dirtyElements.m_Memory.m_pMemory[m_Size - 1];
        --this->m_dirtyElements.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00545FA0
// Name: public: void CDmElementFramework::AddElementToDirtyList(enum DmElementHandle_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::AddElementToDirtyList(CDmElementFramework *this, DmElementHandle_t hElement)
{
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_dirtyElements; // esi
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v6; // eax
  S3RGBA *v7; // eax

  m_nAllocationCount = this->m_dirtyElements.m_Memory.m_nAllocationCount;
  p_m_dirtyElements = (CUtlMemory<S3RGBA,int> *)&this->m_dirtyElements;
  m_Size = this->m_dirtyElements.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<HemiLightData_t *,int>::Grow(this: p_m_dirtyElements, num: m_Size - m_nAllocationCount + 1);
  ++p_m_dirtyElements[1].m_pMemory;
  m_pMemory = p_m_dirtyElements->m_pMemory;
  v6 = (int)p_m_dirtyElements[1].m_pMemory - m_Size - 1;
  p_m_dirtyElements[1].m_nAllocationCount = (int)p_m_dirtyElements->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_dirtyElements->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (S3RGBA)hElement;
}

} // namespace vmap

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x10038AB0
// Name: public: virtual void CDmElementFramework::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Disconnect(CDmeTexture *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10070110
// Name: public: virtual bool CDmElementFramework::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmElementFramework::Connect(CDmElementFramework *this, void *(__cdecl *factory)(const char *, int *))
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10070120
// Name: public: virtual void __near * CDmElementFramework::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmElementFramework *__thiscall CDmElementFramework::QueryInterface(
        CDmElementFramework *this,
        const char *pInterfaceName)
{
  return _V_strcmp(s1: pInterfaceName, s2: "VDmElementFrameworkVersion001") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10070150
// Name: public: virtual void CDmElementFramework::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Shutdown(CDmElementFramework *this)
{
  CDependencyGraph::Cleanup(this: &this->m_dependencyGraph);
}

//------------------------------------------------------------------------------
// Address: 0x10070160
// Name: public: virtual enum DmPhase_t CDmElementFramework::GetPhase(void)
// Source: json
//------------------------------------------------------------------------------
DmPhase_t __thiscall CDmElementFramework::GetPhase(CDmElementFramework *this)
{
  return this->m_phase;
}

//------------------------------------------------------------------------------
// Address: 0x10070170
// Name: public: virtual void CDmElementFramework::SetOperators(class CUtlVector<class IDmeOperator __near *,class CUtlMemory<class IDmeOperator __near *,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::SetOperators(
        CDmElementFramework *this,
        const CUtlVector<IDmeOperator *,CUtlMemory<IDmeOperator *,int> > *operators)
{
  CDependencyGraph::Reset(this: &this->m_dependencyGraph, operators);
}

//------------------------------------------------------------------------------
// Address: 0x10070190
// Name: private: void CDmElementFramework::Resolve(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this, bool clearDirtyFlags)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  int nCount; // [esp+8h] [ebp-4h]

  v3 = 0;
  nCount = this->m_dirtyElements.m_Size;
  if ( nCount > 0 )
  {
    do
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v3]);
      v5 = v4;
      if ( v4 != nullptr )
      {
        v4->Resolve(this: v4);
        if ( clearDirtyFlags )
        {
          CDmElement::MarkDirty(this: v5, bDirty: false);
          CDmElement::MarkAttributesClean(this: v5);
        }
      }
      ++v3;
    }
    while ( v3 < nCount );
  }
  if ( clearDirtyFlags )
    this->m_dirtyElements.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10070210
// Name: public: virtual void CDmElementFramework::BeginEdit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::BeginEdit(CDmElementFramework *this)
{
  int v2; // edi
  int m_Size; // ebx
  CDmElement *v4; // eax

  v2 = 0;
  if ( this->m_phase != PH_EDIT )
  {
    this->m_phase = PH_EDIT;
  }
  else
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    this->m_phase = PH_EDIT_RESOLVE;
    if ( m_Size <= 0 )
    {
      this->m_phase = PH_EDIT;
    }
    else
    {
      do
      {
        v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v2]);
        if ( v4 != nullptr )
          v4->Resolve(this: v4);
        ++v2;
      }
      while ( v2 < m_Size );
      this->m_phase = PH_EDIT;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10070280
// Name: public: virtual void CDmElementFramework::Operate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Operate(CDmElementFramework *this, bool bResolve)
{
  int m_Size; // ebx
  int v4; // edi
  CDmElement *v5; // eax
  unsigned int v6; // ebx
  unsigned int i; // edi
  IDmeOperator *v8; // ecx
  int v9; // eax
  int v10; // ebx
  CDmElement *v11; // eax
  CDmElement *v12; // edi
  int bResolvea; // [esp+14h] [ebp+8h]

  if ( this->m_phase == PH_EDIT )
  {
    this->m_phase = PH_EDIT_APPLY;
    CDataModel::RemoveUnreferencedElements(this: g_pDataModelImp);
    m_Size = this->m_dirtyElements.m_Size;
    v4 = 0;
    for ( this->m_phase = PH_EDIT_RESOLVE; v4 < m_Size; ++v4 )
    {
      v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v4]);
      if ( v5 != nullptr )
        v5->Resolve(this: v5);
    }
  }
  this->m_phase = PH_DEPENDENCY;
  if ( CDependencyGraph::CullAndSortOperators(this: &this->m_dependencyGraph) )
    _Warning(a1: "Operator cycle found during dependency graph traversal!\n");
  this->m_phase = PH_OPERATE;
  v6 = this->m_dependencyGraph.m_operators.m_Size;
  for ( i = 0; i < v6; ++i )
  {
    v8 = this->m_dependencyGraph.m_operators.m_Memory.m_pMemory[i];
    v8->Operate(this: v8);
  }
  if ( bResolve )
  {
    v9 = this->m_dirtyElements.m_Size;
    v10 = 0;
    this->m_phase = PH_OPERATE_RESOLVE;
    for ( bResolvea = v9; v10 < bResolvea; ++v10 )
    {
      v11 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[v10]);
      v12 = v11;
      if ( v11 != nullptr )
      {
        v11->Resolve(this: v11);
        CDmElement::MarkDirty(this: v12, bDirty: false);
        CDmElement::MarkAttributesClean(this: v12);
      }
    }
    this->m_dirtyElements.m_Size = 0;
    this->m_phase = PH_OUTPUT;
  }
  CDataModel::CommitSymbols(this: g_pDataModelImp);
}

//------------------------------------------------------------------------------
// Address: 0x100703A0
// Name: public: virtual void CDmElementFramework::Resolve(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::Resolve(CDmElementFramework *this)
{
  this->m_phase = PH_OPERATE_RESOLVE;
  CDmElementFramework::Resolve(this, clearDirtyFlags: true);
  this->m_phase = PH_OUTPUT;
}

//------------------------------------------------------------------------------
// Address: 0x100703C0
// Name: public: void CDmElementFramework::RemoveCleanElementsFromDirtyList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::RemoveCleanElementsFromDirtyList(CDmElementFramework *this)
{
  int i; // edi
  CDmElement *v3; // eax
  int m_Size; // ecx

  for ( i = this->m_dirtyElements.m_Size - 1; i >= 0; --i )
  {
    v3 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_dirtyElements.m_Memory.m_pMemory[i]);
    if ( v3 != nullptr && !CDmElement::IsDirty(this: v3) )
    {
      m_Size = this->m_dirtyElements.m_Size;
      if ( m_Size > 0 )
      {
        if ( i != m_Size - 1 )
          this->m_dirtyElements.m_Memory.m_pMemory[i] = this->m_dirtyElements.m_Memory.m_pMemory[m_Size - 1];
        --this->m_dirtyElements.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10070420
// Name: public: void CDmElementFramework::AddElementToDirtyList(enum DmElementHandle_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmElementFramework::AddElementToDirtyList(CDmElementFramework *this, DmElementHandle_t hElement)
{
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_dirtyElements; // esi
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v6; // eax
  S3RGBA *v7; // eax

  m_nAllocationCount = this->m_dirtyElements.m_Memory.m_nAllocationCount;
  p_m_dirtyElements = (CUtlMemory<S3RGBA,int> *)&this->m_dirtyElements;
  m_Size = this->m_dirtyElements.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_dirtyElements, num: m_Size - m_nAllocationCount + 1);
  ++p_m_dirtyElements[1].m_pMemory;
  m_pMemory = p_m_dirtyElements->m_pMemory;
  v6 = (int)p_m_dirtyElements[1].m_pMemory - m_Size - 1;
  p_m_dirtyElements[1].m_nAllocationCount = (int)p_m_dirtyElements->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
  v7 = &p_m_dirtyElements->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (S3RGBA)hElement;
}

} // namespace vtex_dll
