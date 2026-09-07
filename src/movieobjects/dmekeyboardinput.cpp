// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmekeyboardinput.cpp
// Functions: 14
// ============================================================

#include "movieobjects\dmekeyboardinput.h"

//------------------------------------------------------------------------------
// Address: 0x0055C0A0
// Name: protected: void CDmeKeyboardInput::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::OnConstruction(CDmeKeyboardInput *this)
{
  CDmaVar<bool> *v2; // esi
  CDmaVar<bool> *v3; // ecx
  int i; // edx
  unsigned int j; // edi
  CDmaVar<bool> *v6; // esi
  CDmAttribute *v7; // eax

  v2 = (CDmaVar<bool> *)operator new(nSize: 0x180u);
  if ( v2 != nullptr )
  {
    v3 = v2;
    for ( i = 47; i >= 0; --i )
    {
      v3->m_pAttribute = nullptr;
      v3->m_Storage = false;
      ++v3;
    }
  }
  else
  {
    v2 = nullptr;
  }
  this->m_keys = v2;
  for ( j = 0; j < 48; ++j )
  {
    v6 = &this->m_keys[j];
    v7 = CDmElement::AddExternalAttribute(
           this: &this->CDmElement,
           pAttributeName: g_keyInfo[j].str,
           type: AT_BOOL,
           pMemory: v6);
    v6->m_pAttribute = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055C100
// Name: public: virtual void CDmeKeyboardInput::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::Operate(CDmeKeyboardInput *this)
{
  unsigned int i; // esi
  bool v3; // al
  CDmaVar<bool> *m_keys; // edx
  bool value; // [esp+Bh] [ebp-1h] BYREF

  for ( i = 0; i < 48; ++i )
  {
    v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: g_keyInfo[i].code);
    m_keys = this->m_keys;
    value = v3;
    CDmAttribute::SetValue<bool>(this: m_keys[i].m_pAttribute, &value);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055C150
// Name: public: virtual bool CDmeKeyboardInput::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeKeyboardInput::IsDirty(CDmeKeyboardInput *this)
{
  int v2; // edi
  CDmaVar<bool> *m_keys; // esi

  v2 = 0;
  while ( 1 )
  {
    m_keys = this->m_keys;
    if ( m_keys[v2].m_Storage != g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: g_keyInfo[v2].code) )
      break;
    if ( (unsigned int)++v2 >= 48 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0055C1A0
// Name: public: virtual void CDmeKeyboardInput::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::GetOutputAttributes(
        CDmeKeyboardInput *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  unsigned int i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmAttribute *attrsa; // [esp+18h] [ebp+8h]

  for ( i = 0; i < 48; ++i )
  {
    m_Size = attrs->m_Size;
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    attrsa = this->m_keys[i].m_pAttribute;
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
      *v8 = attrsa;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055C2D0
// Name: public: virtual bool CDmeKeyboardInput::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeKeyboardInput::IsA(CDmeKeyboardInput *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeKeyboardInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055C310
// Name: public: virtual int CDmeKeyboardInput::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeKeyboardInput::GetInheritanceDepth(CDmeKeyboardInput *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeKeyboardInput::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeInput::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055C370
// Name: protected: virtual void CDmeKeyboardInput::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::PerformDestruction(CDmeKeyboardInput *this)
{
  free(pMem: (void *)this->m_nSortKey);
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x0055C3A0
// Name: protected: virtual int CDmeKeyboardInput::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeKeyboardInput::AllocatedSize(CDmeMaterial *this)
{
  return 80;
}

//------------------------------------------------------------------------------
// Address: 0x0055C410
// Name: protected: virtual void CDmeKeyboardInput::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::PerformConstruction(CDmeKeyboardInput *this)
{
  CDmeFXClip::OnDestruction();
  this = (CDmeKeyboardInput *)((char *)this - 4);
  CDmeOperator::OnConstruction(this);
  CDmeFXClip::OnDestruction();
  CDmeKeyboardInput::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x005ADEF0
// Name: _dynamic_initializer_for__CDmeKeyboardInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeKeyboardInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeKeyboardInput::s_Allocator,
    blockSize: 80,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeKeyboardInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeKeyboardInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005B0650
// Name: _dynamic_atexit_destructor_for__CDmeKeyboardInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeKeyboardInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeKeyboardInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ADF20
// Name: _dynamic_initializer_for__g_CDmeKeyboardInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeKeyboardInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeKeyboardInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ADF30
// Name: _dynamic_initializer_for__g_CDmeKeyboardInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeKeyboardInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeKeyboardInput_Helper,
           classname: "DmeKeyboardInput",
           pFactory: &g_CDmeKeyboardInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005B0660
// Name: _dynamic_atexit_destructor_for__g_CDmeKeyboardInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeKeyboardInput_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeKeyboardInput_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005B3190
// Name: protected: void CDmeKeyboardInput::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::OnConstruction(CDmeKeyboardInput *this)
{
  CDmaVar<bool> *v2; // esi
  CDmaVar<bool> *v3; // ecx
  int i; // edx
  unsigned int j; // edi
  CDmaVar<bool> *v6; // esi
  CDmAttribute *v7; // eax

  v2 = (CDmaVar<bool> *)MemAlloc_Alloc(nSize: 0x180u);
  if ( v2 != nullptr )
  {
    v3 = v2;
    for ( i = 47; i >= 0; --i )
    {
      v3->m_pAttribute = nullptr;
      v3->m_Storage = false;
      ++v3;
    }
  }
  else
  {
    v2 = nullptr;
  }
  this->m_keys = v2;
  for ( j = 0; j < 48; ++j )
  {
    v6 = &this->m_keys[j];
    v7 = CDmElement::AddExternalAttribute(
           this: &this->CDmElement,
           pAttributeName: g_keyInfo[j].str,
           type: AT_BOOL,
           pMemory: v6);
    v6->m_pAttribute = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B31F0
// Name: public: virtual void CDmeKeyboardInput::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::Operate(CDmeKeyboardInput *this)
{
  unsigned int i; // esi
  bool v3; // al
  CDmaVar<bool> *m_keys; // edx
  bool value; // [esp+Bh] [ebp-1h] BYREF

  for ( i = 0; i < 48; ++i )
  {
    v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: g_keyInfo[i].code);
    m_keys = this->m_keys;
    value = v3;
    CDmAttribute::SetValue<bool>(this: m_keys[i].m_pAttribute, &value);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B3240
// Name: public: virtual bool CDmeKeyboardInput::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeKeyboardInput::IsDirty(CDmeKeyboardInput *this)
{
  int v2; // edi
  CDmaVar<bool> *m_keys; // esi

  v2 = 0;
  while ( 1 )
  {
    m_keys = this->m_keys;
    if ( m_keys[v2].m_Storage != g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: g_keyInfo[v2].code) )
      break;
    if ( (unsigned int)++v2 >= 48 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005B3290
// Name: public: virtual void CDmeKeyboardInput::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::GetOutputAttributes(
        CDmeKeyboardInput *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  unsigned int i; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v6; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmAttribute *attrsa; // [esp+18h] [ebp+8h]

  for ( i = 0; i < 48; ++i )
  {
    m_pMemory = (int)attrs[1].m_pMemory;
    m_nAllocationCount = attrs->m_nAllocationCount;
    attrsa = this->m_keys[i].m_pAttribute;
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
      *v8 = attrsa;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B33C0
// Name: public: virtual bool CDmeKeyboardInput::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeKeyboardInput::IsA(CDmeKeyboardInput *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeKeyboardInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B3400
// Name: public: virtual int CDmeKeyboardInput::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeKeyboardInput::GetInheritanceDepth(CDmeKeyboardInput *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeKeyboardInput::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeInput::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B3460
// Name: protected: virtual void CDmeKeyboardInput::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::PerformDestruction(CDmeKeyboardInput *this)
{
  free(pMem: (void *)this->m_nSortKey);
  CDmeFXClip::OnDestruction(this: (vgui::PropertyPage *)((char *)this - 4));
  CDmeFXClip::OnDestruction(this: (vgui::PropertyPage *)((char *)this - 4));
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x005B3490
// Name: protected: virtual int CDmeKeyboardInput::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeKeyboardInput::AllocatedSize(CDmeMaterial *this)
{
  return 80;
}

//------------------------------------------------------------------------------
// Address: 0x005B3500
// Name: protected: virtual void CDmeKeyboardInput::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::PerformConstruction(CDmeKeyboardInput *this)
{
  CDmeKeyboardInput *v1; // esi

  v1 = this;
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  v1 = (CDmeKeyboardInput *)((char *)v1 - 4);
  CDmeOperator::OnConstruction(this: v1);
  CDmeFXClip::OnDestruction(this: (vgui::PropertyPage *)v1);
  CDmeKeyboardInput::OnConstruction(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x0067F6E0
// Name: _dynamic_initializer_for__CDmeKeyboardInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeKeyboardInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeKeyboardInput::s_Allocator,
    blockSize: 80,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeKeyboardInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeKeyboardInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00682B60
// Name: _dynamic_atexit_destructor_for__CDmeKeyboardInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeKeyboardInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeKeyboardInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067F710
// Name: _dynamic_initializer_for__g_CDmeKeyboardInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeKeyboardInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeKeyboardInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F720
// Name: _dynamic_initializer_for__g_CDmeKeyboardInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeKeyboardInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeKeyboardInput_Helper,
           classname: "DmeKeyboardInput",
           pFactory: &g_CDmeKeyboardInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00682B70
// Name: _dynamic_atexit_destructor_for__g_CDmeKeyboardInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeKeyboardInput_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeKeyboardInput_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0051D8F0
// Name: protected: void CDmeKeyboardInput::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::OnConstruction(CDmeKeyboardInput *this)
{
  CDmaVar<bool> *v2; // esi
  CDmaVar<bool> *v3; // ecx
  int i; // edx
  unsigned int j; // edi
  CDmaVar<bool> *v6; // esi
  CDmAttribute *v7; // eax

  v2 = (CDmaVar<bool> *)operator new(nSize: 0x180u);
  if ( v2 != nullptr )
  {
    v3 = v2;
    for ( i = 47; i >= 0; --i )
    {
      v3->m_pAttribute = nullptr;
      v3->m_Storage = false;
      ++v3;
    }
  }
  else
  {
    v2 = nullptr;
  }
  this->m_keys = v2;
  for ( j = 0; j < 48; ++j )
  {
    v6 = &this->m_keys[j];
    v7 = CDmElement::AddExternalAttribute(
           this: &this->CDmElement,
           pAttributeName: g_keyInfo[j].str,
           type: AT_BOOL,
           pMemory: v6);
    v6->m_pAttribute = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051D950
// Name: public: virtual void CDmeKeyboardInput::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::Operate(CDmeKeyboardInput *this)
{
  unsigned int i; // esi
  bool v3; // al
  CDmaVar<bool> *m_keys; // edx
  bool value; // [esp+Bh] [ebp-1h] BYREF

  for ( i = 0; i < 48; ++i )
  {
    v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: g_keyInfo[i].code);
    m_keys = this->m_keys;
    value = v3;
    CDmAttribute::SetValue<bool>(this: m_keys[i].m_pAttribute, &value);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051D9A0
// Name: public: virtual bool CDmeKeyboardInput::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeKeyboardInput::IsDirty(CDmeKeyboardInput *this)
{
  int v2; // edi
  CDmaVar<bool> *m_keys; // esi

  v2 = 0;
  while ( 1 )
  {
    m_keys = this->m_keys;
    if ( m_keys[v2].m_Storage != g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: g_keyInfo[v2].code) )
      break;
    if ( (unsigned int)++v2 >= 48 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0051D9F0
// Name: public: virtual void CDmeKeyboardInput::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::GetOutputAttributes(
        CDmeKeyboardInput *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  unsigned int i; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v6; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmAttribute *attrsa; // [esp+18h] [ebp+8h]

  for ( i = 0; i < 48; ++i )
  {
    m_pMemory = (int)attrs[1].m_pMemory;
    m_nAllocationCount = attrs->m_nAllocationCount;
    attrsa = this->m_keys[i].m_pAttribute;
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
      *v8 = attrsa;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051DB20
// Name: public: virtual bool CDmeKeyboardInput::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeKeyboardInput::IsA(CDmeKeyboardInput *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeKeyboardInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051DB60
// Name: public: virtual int CDmeKeyboardInput::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeKeyboardInput::GetInheritanceDepth(CDmeKeyboardInput *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeKeyboardInput::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeInput::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051DBC0
// Name: protected: virtual void CDmeKeyboardInput::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::PerformDestruction(CDmeKeyboardInput *this)
{
  free(pMem: (void *)this->m_nSortKey);
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x0051DBF0
// Name: protected: virtual int CDmeKeyboardInput::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeKeyboardInput::AllocatedSize(CDmeMaterial *this)
{
  return 80;
}

//------------------------------------------------------------------------------
// Address: 0x0051DC60
// Name: protected: virtual void CDmeKeyboardInput::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::PerformConstruction(CDmeKeyboardInput *this)
{
  CDmeFXClip::OnDestruction();
  this = (CDmeKeyboardInput *)((char *)this - 4);
  CDmeOperator::OnConstruction(this);
  CDmeFXClip::OnDestruction();
  CDmeKeyboardInput::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0056C2C0
// Name: _dynamic_initializer_for__CDmeKeyboardInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeKeyboardInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeKeyboardInput::s_Allocator,
    blockSize: 80,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeKeyboardInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeKeyboardInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056ED40
// Name: _dynamic_atexit_destructor_for__CDmeKeyboardInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeKeyboardInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeKeyboardInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056C2F0
// Name: _dynamic_initializer_for__g_CDmeKeyboardInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeKeyboardInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeKeyboardInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C300
// Name: _dynamic_initializer_for__g_CDmeKeyboardInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeKeyboardInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeKeyboardInput_Helper,
           classname: "DmeKeyboardInput",
           pFactory: &g_CDmeKeyboardInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056ED50
// Name: _dynamic_atexit_destructor_for__g_CDmeKeyboardInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeKeyboardInput_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeKeyboardInput_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x00523B50
// Name: protected: void CDmeKeyboardInput::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::OnConstruction(CDmeKeyboardInput *this)
{
  CDmaVar<bool> *v2; // esi
  CDmaVar<bool> *v3; // ecx
  int i; // edx
  unsigned int j; // edi
  CDmaVar<bool> *v6; // esi
  CDmAttribute *v7; // eax

  v2 = (CDmaVar<bool> *)operator new(nSize: 0x180u);
  if ( v2 != nullptr )
  {
    v3 = v2;
    for ( i = 47; i >= 0; --i )
    {
      v3->m_pAttribute = nullptr;
      v3->m_Storage = false;
      ++v3;
    }
  }
  else
  {
    v2 = nullptr;
  }
  this->m_keys = v2;
  for ( j = 0; j < 48; ++j )
  {
    v6 = &this->m_keys[j];
    v7 = CDmElement::AddExternalAttribute(
           this: &this->CDmElement,
           pAttributeName: g_keyInfo[j].str,
           type: AT_BOOL,
           pMemory: v6);
    v6->m_pAttribute = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00523BB0
// Name: public: virtual void CDmeKeyboardInput::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::Operate(CDmeKeyboardInput *this)
{
  unsigned int i; // esi
  bool v3; // al
  CDmaVar<bool> *m_keys; // edx
  bool value; // [esp+Bh] [ebp-1h] BYREF

  for ( i = 0; i < 48; ++i )
  {
    v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: g_keyInfo[i].code);
    m_keys = this->m_keys;
    value = v3;
    CDmAttribute::SetValue<bool>(this: m_keys[i].m_pAttribute, &value);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00523C00
// Name: public: virtual bool CDmeKeyboardInput::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeKeyboardInput::IsDirty(CDmeKeyboardInput *this)
{
  int v2; // edi
  CDmaVar<bool> *m_keys; // esi

  v2 = 0;
  while ( 1 )
  {
    m_keys = this->m_keys;
    if ( m_keys[v2].m_Storage != g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: g_keyInfo[v2].code) )
      break;
    if ( (unsigned int)++v2 >= 48 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00523C50
// Name: public: virtual void CDmeKeyboardInput::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::GetOutputAttributes(
        CDmeKeyboardInput *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  unsigned int i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmAttribute *attrsa; // [esp+18h] [ebp+8h]

  for ( i = 0; i < 48; ++i )
  {
    m_Size = attrs->m_Size;
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    attrsa = this->m_keys[i].m_pAttribute;
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
      *v8 = attrsa;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00523D80
// Name: public: virtual bool CDmeKeyboardInput::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeKeyboardInput::IsA(CDmeKeyboardInput *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeKeyboardInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00523DC0
// Name: public: virtual int CDmeKeyboardInput::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeKeyboardInput::GetInheritanceDepth(CDmeKeyboardInput *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeKeyboardInput::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeInput::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00523E20
// Name: protected: virtual void CDmeKeyboardInput::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::PerformDestruction(CDmeKeyboardInput *this)
{
  free(pMem: (void *)this->m_nSortKey);
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x00523E50
// Name: protected: virtual int CDmeKeyboardInput::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeKeyboardInput::AllocatedSize(CDmeMaterial *this)
{
  return 80;
}

//------------------------------------------------------------------------------
// Address: 0x00523EC0
// Name: protected: virtual void CDmeKeyboardInput::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::PerformConstruction(CDmeKeyboardInput *this)
{
  CDmeFXClip::OnDestruction();
  this = (CDmeKeyboardInput *)((char *)this - 4);
  CDmeOperator::OnConstruction(this);
  CDmeFXClip::OnDestruction();
  CDmeKeyboardInput::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057C3E0
// Name: _dynamic_initializer_for__CDmeKeyboardInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeKeyboardInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeKeyboardInput::s_Allocator,
    blockSize: 80,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeKeyboardInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeKeyboardInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EE70
// Name: _dynamic_atexit_destructor_for__CDmeKeyboardInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeKeyboardInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeKeyboardInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057C410
// Name: _dynamic_initializer_for__g_CDmeKeyboardInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeKeyboardInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeKeyboardInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C420
// Name: _dynamic_initializer_for__g_CDmeKeyboardInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeKeyboardInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeKeyboardInput_Helper,
           classname: "DmeKeyboardInput",
           pFactory: &g_CDmeKeyboardInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057EE80
// Name: _dynamic_atexit_destructor_for__g_CDmeKeyboardInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeKeyboardInput_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeKeyboardInput_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005E0A20
// Name: protected: void CDmeKeyboardInput::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::OnConstruction(CDmeKeyboardInput *this)
{
  CDmaVar<bool> *v2; // esi
  CDmaVar<bool> *v3; // ecx
  int i; // edx
  unsigned int j; // edi
  CDmaVar<bool> *v6; // esi
  CDmAttribute *v7; // eax

  v2 = (CDmaVar<bool> *)MemAlloc_Alloc(nSize: 0x180u);
  if ( v2 != nullptr )
  {
    v3 = v2;
    for ( i = 47; i >= 0; --i )
    {
      v3->m_pAttribute = nullptr;
      v3->m_Storage = false;
      ++v3;
    }
  }
  else
  {
    v2 = nullptr;
  }
  this->m_keys = v2;
  for ( j = 0; j < 48; ++j )
  {
    v6 = &this->m_keys[j];
    v7 = CDmElement::AddExternalAttribute(
           this: &this->CDmElement,
           pAttributeName: g_keyInfo[j].str,
           type: AT_BOOL,
           pMemory: v6);
    v6->m_pAttribute = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E0A80
// Name: public: virtual void CDmeKeyboardInput::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::Operate(CDmeKeyboardInput *this)
{
  unsigned int i; // esi
  bool v3; // al
  CDmaVar<bool> *m_keys; // edx
  bool value; // [esp+Bh] [ebp-1h] BYREF

  for ( i = 0; i < 48; ++i )
  {
    v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: g_keyInfo[i].code);
    m_keys = this->m_keys;
    value = v3;
    CDmAttribute::SetValue<bool>(this: m_keys[i].m_pAttribute, &value);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E0AD0
// Name: public: virtual bool CDmeKeyboardInput::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeKeyboardInput::IsDirty(CDmeKeyboardInput *this)
{
  int v2; // edi
  CDmaVar<bool> *m_keys; // esi

  v2 = 0;
  while ( 1 )
  {
    m_keys = this->m_keys;
    if ( m_keys[v2].m_Storage != g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: g_keyInfo[v2].code) )
      break;
    if ( (unsigned int)++v2 >= 48 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005E0B20
// Name: public: virtual void CDmeKeyboardInput::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::GetOutputAttributes(
        CDmeKeyboardInput *this,
        CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  unsigned int i; // ebx
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v6; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmAttribute *attrsa; // [esp+18h] [ebp+8h]

  for ( i = 0; i < 48; ++i )
  {
    m_pMemory = (int)attrs[1].m_pMemory;
    m_nAllocationCount = attrs->m_nAllocationCount;
    attrsa = this->m_keys[i].m_pAttribute;
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
      *v8 = attrsa;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E0C50
// Name: public: virtual bool CDmeKeyboardInput::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeKeyboardInput::IsA(CDmeKeyboardInput *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeKeyboardInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E0C90
// Name: public: virtual int CDmeKeyboardInput::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeKeyboardInput::GetInheritanceDepth(CDmeKeyboardInput *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeKeyboardInput::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeInput::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E0CF0
// Name: protected: virtual void CDmeKeyboardInput::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::PerformDestruction(CDmeKeyboardInput *this)
{
  free(pMem: (void *)this->m_nSortKey);
  CDmeFXClip::OnDestruction(this: (vgui::PropertyPage *)((char *)this - 4));
  CDmeFXClip::OnDestruction(this: (vgui::PropertyPage *)((char *)this - 4));
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x005E0D90
// Name: protected: virtual void CDmeKeyboardInput::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::PerformConstruction(CDmeKeyboardInput *this)
{
  CDmeKeyboardInput *v1; // esi

  v1 = this;
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  v1 = (CDmeKeyboardInput *)((char *)v1 - 4);
  CDmeOperator::OnConstruction(this: v1);
  CDmeFXClip::OnDestruction(this: (vgui::PropertyPage *)v1);
  CDmeKeyboardInput::OnConstruction(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x006B1530
// Name: _dynamic_initializer_for__CDmeKeyboardInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeKeyboardInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeKeyboardInput::s_Allocator,
    blockSize: 80,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeKeyboardInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeKeyboardInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5660
// Name: _dynamic_atexit_destructor_for__CDmeKeyboardInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeKeyboardInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeKeyboardInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B1560
// Name: _dynamic_initializer_for__g_CDmeKeyboardInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeKeyboardInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeKeyboardInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1570
// Name: _dynamic_initializer_for__g_CDmeKeyboardInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeKeyboardInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeKeyboardInput_Helper,
           classname: "DmeKeyboardInput",
           pFactory: &g_CDmeKeyboardInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5670
// Name: _dynamic_atexit_destructor_for__g_CDmeKeyboardInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeKeyboardInput_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeKeyboardInput_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0051FE40
// Name: protected: virtual int CDmeKeyboardInput::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeKeyboardInput::AllocatedSize(CDmeMaterial *this)
{
  return 80;
}

//------------------------------------------------------------------------------
// Address: 0x00524D10
// Name: protected: void CDmeKeyboardInput::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::OnConstruction(CDmeKeyboardInput *this)
{
  CDmaVar<bool> *v2; // esi
  CDmaVar<bool> *v3; // ecx
  int i; // edx
  unsigned int j; // edi
  CDmaVar<bool> *v6; // esi
  CDmAttribute *v7; // eax

  v2 = (CDmaVar<bool> *)operator new(nSize: 0x180u);
  if ( v2 != nullptr )
  {
    v3 = v2;
    for ( i = 47; i >= 0; --i )
    {
      v3->m_pAttribute = nullptr;
      v3->m_Storage = false;
      ++v3;
    }
  }
  else
  {
    v2 = nullptr;
  }
  this->m_keys = v2;
  for ( j = 0; j < 48; ++j )
  {
    v6 = &this->m_keys[j];
    v7 = CDmElement::AddExternalAttribute(
           this: &this->CDmElement,
           pAttributeName: g_keyInfo[j].str,
           type: AT_BOOL,
           pMemory: v6);
    v6->m_pAttribute = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00524D70
// Name: public: virtual void CDmeKeyboardInput::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::Operate(CDmeKeyboardInput *this)
{
  unsigned int i; // esi
  bool v3; // al
  CDmaVar<bool> *m_keys; // edx
  bool value; // [esp+Bh] [ebp-1h] BYREF

  for ( i = 0; i < 48; ++i )
  {
    v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: g_keyInfo[i].code);
    m_keys = this->m_keys;
    value = v3;
    CDmAttribute::SetValue<bool>(this: m_keys[i].m_pAttribute, &value);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00524DC0
// Name: public: virtual bool CDmeKeyboardInput::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeKeyboardInput::IsDirty(CDmeKeyboardInput *this)
{
  int v2; // edi
  CDmaVar<bool> *m_keys; // esi

  v2 = 0;
  while ( 1 )
  {
    m_keys = this->m_keys;
    if ( m_keys[v2].m_Storage != g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: g_keyInfo[v2].code) )
      break;
    if ( (unsigned int)++v2 >= 48 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00524E10
// Name: public: virtual void CDmeKeyboardInput::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::GetOutputAttributes(
        CDmeKeyboardInput *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  unsigned int i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmAttribute *attrsa; // [esp+18h] [ebp+8h]

  for ( i = 0; i < 48; ++i )
  {
    m_Size = attrs->m_Size;
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    attrsa = this->m_keys[i].m_pAttribute;
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
      *v8 = attrsa;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00524F40
// Name: public: virtual bool CDmeKeyboardInput::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeKeyboardInput::IsA(CDmeKeyboardInput *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeKeyboardInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00524F80
// Name: public: virtual int CDmeKeyboardInput::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeKeyboardInput::GetInheritanceDepth(CDmeKeyboardInput *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeKeyboardInput::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeInput::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00524FE0
// Name: protected: virtual void CDmeKeyboardInput::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::PerformDestruction(CDmeKeyboardInput *this)
{
  free(pMem: (void *)this->m_nSortKey);
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x00525070
// Name: protected: virtual void CDmeKeyboardInput::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::PerformConstruction(CDmeKeyboardInput *this)
{
  CDmeFXClip::OnDestruction();
  this = (CDmeKeyboardInput *)((char *)this - 4);
  CDmeOperator::OnConstruction(this);
  CDmeFXClip::OnDestruction();
  CDmeKeyboardInput::OnConstruction(this);
}

//------------------------------------------------------------------------------
// Address: 0x0057E3B0
// Name: _dynamic_initializer_for__CDmeKeyboardInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeKeyboardInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeKeyboardInput::s_Allocator,
    blockSize: 80,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeKeyboardInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeKeyboardInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00580E50
// Name: _dynamic_atexit_destructor_for__CDmeKeyboardInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeKeyboardInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeKeyboardInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E3E0
// Name: _dynamic_initializer_for__g_CDmeKeyboardInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeKeyboardInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeKeyboardInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E3F0
// Name: _dynamic_initializer_for__g_CDmeKeyboardInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeKeyboardInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeKeyboardInput_Helper,
           classname: "DmeKeyboardInput",
           pFactory: &g_CDmeKeyboardInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00580E60
// Name: _dynamic_atexit_destructor_for__g_CDmeKeyboardInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeKeyboardInput_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeKeyboardInput_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0052C240
// Name: protected: void CDmeKeyboardInput::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::OnConstruction(CDmeKeyboardInput *this)
{
  CDmaVar<bool> *v2; // esi
  CDmaVar<bool> *v3; // ecx
  int i; // edx
  unsigned int j; // edi
  CDmaVar<bool> *v6; // esi
  CDmAttribute *v7; // eax

  v2 = (CDmaVar<bool> *)operator new(nSize: 0x180u);
  if ( v2 != nullptr )
  {
    v3 = v2;
    for ( i = 47; i >= 0; --i )
    {
      v3->m_pAttribute = nullptr;
      v3->m_Storage = false;
      ++v3;
    }
  }
  else
  {
    v2 = nullptr;
  }
  this->m_keys = v2;
  for ( j = 0; j < 48; ++j )
  {
    v6 = &this->m_keys[j];
    v7 = CDmElement::AddExternalAttribute(
           this: &this->CDmElement,
           pAttributeName: g_keyInfo[j].str,
           type: AT_BOOL,
           pMemory: v6);
    v6->m_pAttribute = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052C2A0
// Name: public: virtual void CDmeKeyboardInput::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::Operate(CDmeKeyboardInput *this)
{
  unsigned int i; // esi
  bool v3; // al
  CDmaVar<bool> *m_keys; // edx
  bool value; // [esp+Bh] [ebp-1h] BYREF

  for ( i = 0; i < 48; ++i )
  {
    v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: g_keyInfo[i].code);
    m_keys = this->m_keys;
    value = v3;
    CDmAttribute::SetValue<bool>(this: m_keys[i].m_pAttribute, &value);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052C2F0
// Name: public: virtual bool CDmeKeyboardInput::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeKeyboardInput::IsDirty(CDmeKeyboardInput *this)
{
  int v2; // edi
  CDmaVar<bool> *m_keys; // esi

  v2 = 0;
  while ( 1 )
  {
    m_keys = this->m_keys;
    if ( m_keys[v2].m_Storage != g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: g_keyInfo[v2].code) )
      break;
    if ( (unsigned int)++v2 >= 48 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0052C340
// Name: public: virtual void CDmeKeyboardInput::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::GetOutputAttributes(
        CDmeKeyboardInput *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  unsigned int i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmAttribute *attrsa; // [esp+18h] [ebp+8h]

  for ( i = 0; i < 48; ++i )
  {
    m_Size = attrs->m_Size;
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    attrsa = this->m_keys[i].m_pAttribute;
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
      *v8 = attrsa;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052C470
// Name: public: virtual bool CDmeKeyboardInput::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeKeyboardInput::IsA(CDmeKeyboardInput *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeKeyboardInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052C4B0
// Name: public: virtual int CDmeKeyboardInput::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeKeyboardInput::GetInheritanceDepth(CDmeKeyboardInput *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeKeyboardInput::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeInput::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052C510
// Name: protected: virtual void CDmeKeyboardInput::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::PerformDestruction(CDmeKeyboardInput *this)
{
  free(pMem: (void *)this->m_nSortKey);
  CDmeFXClip::OnDestruction(this: (CDataManagerBase *)((char *)this - 4));
  CDmeFXClip::OnDestruction(this: (CDataManagerBase *)((char *)this - 4));
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0052C540
// Name: protected: virtual int CDmeKeyboardInput::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeKeyboardInput::AllocatedSize(CDmeMaterial *this)
{
  return 80;
}

//------------------------------------------------------------------------------
// Address: 0x0052C5B0
// Name: protected: virtual void CDmeKeyboardInput::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::PerformConstruction(CDmeKeyboardInput *this)
{
  CDmeKeyboardInput *v1; // esi

  v1 = this;
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  v1 = (CDmeKeyboardInput *)((char *)v1 - 4);
  CDmeOperator::OnConstruction(this: v1);
  CDmeFXClip::OnDestruction(this: (CDataManagerBase *)v1);
  CDmeKeyboardInput::OnConstruction(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x0057BC00
// Name: _dynamic_initializer_for__CDmeKeyboardInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeKeyboardInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeKeyboardInput::s_Allocator,
    blockSize: 80,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeKeyboardInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeKeyboardInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E540
// Name: _dynamic_atexit_destructor_for__CDmeKeyboardInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeKeyboardInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeKeyboardInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057BC30
// Name: _dynamic_initializer_for__g_CDmeKeyboardInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeKeyboardInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeKeyboardInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BC40
// Name: _dynamic_initializer_for__g_CDmeKeyboardInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeKeyboardInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeKeyboardInput_Helper,
           classname: "DmeKeyboardInput",
           pFactory: &g_CDmeKeyboardInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E550
// Name: _dynamic_atexit_destructor_for__g_CDmeKeyboardInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeKeyboardInput_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeKeyboardInput_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0062F240
// Name: protected: void CDmeKeyboardInput::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::OnConstruction(CDmeKeyboardInput *this)
{
  CDmaVar<bool> *v2; // esi
  CDmaVar<bool> *v3; // ecx
  int i; // edx
  unsigned int j; // edi
  CDmaVar<bool> *v6; // esi
  CDmAttribute *v7; // eax

  v2 = (CDmaVar<bool> *)MemAlloc_Alloc(nSize: 0x180u);
  if ( v2 != nullptr )
  {
    v3 = v2;
    for ( i = 47; i >= 0; --i )
    {
      v3->m_pAttribute = nullptr;
      v3->m_Storage = false;
      ++v3;
    }
  }
  else
  {
    v2 = nullptr;
  }
  this->m_keys = v2;
  for ( j = 0; j < 48; ++j )
  {
    v6 = &this->m_keys[j];
    v7 = CDmElement::AddExternalAttribute(
           this: &this->CDmElement,
           pAttributeName: g_keyInfo[j].str,
           type: AT_BOOL,
           pMemory: v6);
    v6->m_pAttribute = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062F2A0
// Name: public: virtual void CDmeKeyboardInput::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::Operate(CDmeKeyboardInput *this)
{
  unsigned int i; // esi
  bool v3; // al
  CDmaVar<bool> *m_keys; // edx
  bool value; // [esp+Bh] [ebp-1h] BYREF

  for ( i = 0; i < 48; ++i )
  {
    v3 = g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: g_keyInfo[i].code);
    m_keys = this->m_keys;
    value = v3;
    CDmAttribute::SetValue<bool>(this: m_keys[i].m_pAttribute, &value);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062F2F0
// Name: public: virtual bool CDmeKeyboardInput::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeKeyboardInput::IsDirty(CDmeKeyboardInput *this)
{
  int v2; // edi
  CDmaVar<bool> *m_keys; // esi

  v2 = 0;
  while ( 1 )
  {
    m_keys = this->m_keys;
    if ( m_keys[v2].m_Storage != g_pVGuiInput->IsKeyDown(this: g_pVGuiInput, a2: g_keyInfo[v2].code) )
      break;
    if ( (unsigned int)++v2 >= 48 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0062F340
// Name: public: virtual void CDmeKeyboardInput::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::GetOutputAttributes(
        CDmeKeyboardInput *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  unsigned int i; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmAttribute *attrsa; // [esp+18h] [ebp+8h]

  for ( i = 0; i < 48; ++i )
  {
    m_Size = attrs->m_Size;
    m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
    attrsa = this->m_keys[i].m_pAttribute;
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
      *v8 = attrsa;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062F470
// Name: public: virtual bool CDmeKeyboardInput::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeKeyboardInput::IsA(CDmeKeyboardInput *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeKeyboardInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062F4B0
// Name: public: virtual int CDmeKeyboardInput::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeKeyboardInput::GetInheritanceDepth(CDmeKeyboardInput *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeKeyboardInput::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeInput::m_classType.u.m_Id )
    return 1;
  if ( typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id )
    return 2;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 3;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062F510
// Name: protected: virtual void CDmeKeyboardInput::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::PerformDestruction(CDmeKeyboardInput *this)
{
  free(pMem: (void *)this->m_nSortKey);
  CDmeFXClip::OnDestruction(this: (CDataManagerBase *)((char *)this - 4));
  CDmeFXClip::OnDestruction(this: (CDataManagerBase *)((char *)this - 4));
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0062F540
// Name: protected: virtual int CDmeKeyboardInput::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeKeyboardInput::AllocatedSize(CDmeMaterial *this)
{
  return 80;
}

//------------------------------------------------------------------------------
// Address: 0x0062F5B0
// Name: protected: virtual void CDmeKeyboardInput::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeKeyboardInput::PerformConstruction(CDmeKeyboardInput *this)
{
  CDmeKeyboardInput *v1; // esi

  v1 = this;
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  v1 = (CDmeKeyboardInput *)((char *)v1 - 4);
  CDmeOperator::OnConstruction(this: v1);
  CDmeFXClip::OnDestruction(this: (CDataManagerBase *)v1);
  CDmeKeyboardInput::OnConstruction(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x006B9B70
// Name: _dynamic_initializer_for__CDmeKeyboardInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeKeyboardInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeKeyboardInput::s_Allocator,
    blockSize: 0x50u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeKeyboardInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeKeyboardInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BD360
// Name: _dynamic_atexit_destructor_for__CDmeKeyboardInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeKeyboardInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeKeyboardInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B9BA0
// Name: _dynamic_initializer_for__g_CDmeKeyboardInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeKeyboardInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeKeyboardInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9BB0
// Name: _dynamic_initializer_for__g_CDmeKeyboardInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeKeyboardInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeKeyboardInput_Helper,
           classname: "DmeKeyboardInput",
           pFactory: &g_CDmeKeyboardInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BD370
// Name: _dynamic_atexit_destructor_for__g_CDmeKeyboardInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeKeyboardInput_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeKeyboardInput_Factory.m_CallBackList);
}

} // namespace vmap
