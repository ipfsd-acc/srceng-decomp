// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmemouseinput.cpp
// Functions: 13
// ============================================================

#include "movieobjects\dmemouseinput.h"

//------------------------------------------------------------------------------
// Address: 0x0055BB10
// Name: protected: void CDmeMouseInput::GetNormalizedCursorPos(float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::GetNormalizedCursorPos(CDmeMouseInput *this, float *flX, float *flY)
{
  unsigned int v3; // esi
  int v4; // edx
  __m128i v5; // xmm1
  int h; // [esp+4h] [ebp-18h] BYREF
  int y0; // [esp+8h] [ebp-14h] BYREF
  int y; // [esp+Ch] [ebp-10h] BYREF
  int w; // [esp+10h] [ebp-Ch] BYREF
  int x0; // [esp+14h] [ebp-8h] BYREF
  int x; // [esp+18h] [ebp-4h] BYREF

  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  v3 = g_pVGuiInput->GetFocus(this: g_pVGuiInput);
  if ( v3 != 0 )
  {
    g_pVGuiPanel->GetPos(this: g_pVGuiPanel, a2: v3, a3: &x0, a4: &y0);
    g_pVGuiPanel->GetSize(this: g_pVGuiPanel, a2: v3, a3: &w, a4: &h);
    v4 = y - y0;
    v5 = _mm_cvtsi32_si128(h);
    *flX = (float)(x - x0) / (float)w;
    *flY = (float)v4 / _mm_cvtepi32_ps(v5).m128_f32[0];
  }
  else
  {
    *flY = 0.0;
    *flX = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055BBD0
// Name: public: virtual void CDmeMouseInput::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::Operate(CDmeMouseInput *this)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v3; // eax
  float flY; // [esp+8h] [ebp-8h] BYREF
  float flX; // [esp+Ch] [ebp-4h] BYREF

  CDmeMouseInput::GetNormalizedCursorPos(this, &flX, &flY);
  flX = flX - this->m_xOrigin;
  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "x");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: &this->CDmElement, pAttributeName: "x", type: AT_FLOAT)) != nullptr )
  {
    CDmAttribute::SetValue<float>(this: Attribute, value: &flX);
  }
  flY = flY - this->m_yOrigin;
  v3 = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "y");
  if ( v3 != nullptr
    || (v3 = CDmElement::CreateAttribute(this: &this->CDmElement, pAttributeName: "y", type: AT_FLOAT)) != nullptr )
  {
    CDmAttribute::SetValue<float>(this: v3, value: &flY);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0055BC70
// Name: public: virtual bool CDmeMouseInput::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeMouseInput::IsDirty(CDmeMouseInput *this)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<float> *v3; // eax
  CDmAttribute *v4; // eax
  CDmaVar<float> *v5; // eax
  float flY; // [esp+8h] [ebp-8h] BYREF
  float flX; // [esp+Ch] [ebp-4h] BYREF

  CDmeMouseInput::GetNormalizedCursorPos(this, &flX, &flY);
  flX = flX - this->m_xOrigin;
  flY = flY - this->m_yOrigin;
  if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
  }
  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "x");
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<float>(this: Attribute);
  else
    v3 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
  if ( flX != v3->m_Storage )
    return true;
  if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
  }
  v4 = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "y");
  v5 = v4 != nullptr ? CDmAttribute::GetValue<float>(this: v4) : &`CDmElement::GetValue<float>'::`2'::defaultVal;
  return flY != v5->m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0055BD60
// Name: public: virtual void CDmeMouseInput::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::GetOutputAttributes(
        CDmeMouseInput *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // ebx
  CDmAttribute *Attribute; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmAttribute *v9; // eax
  int v10; // edi
  CDmAttribute *v11; // ebx
  int v12; // eax
  CDmAttribute **v13; // ecx
  int v14; // eax
  CDmAttribute **v15; // eax
  CDmAttribute *v16; // [esp+Ch] [ebp-4h]

  v2 = &this->CDmElement;
  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "x");
  m_Size = attrs->m_Size;
  v16 = Attribute;
  m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
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
    *v8 = v16;
  v9 = CDmElement::FindAttribute(this: v2, pAttributeName: "y");
  v10 = attrs->m_Size;
  v11 = v9;
  v12 = attrs->m_Memory.m_nAllocationCount;
  if ( v10 + 1 > v12 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v10 - v12 + 1);
  ++attrs->m_Size;
  v13 = attrs->m_Memory.m_pMemory;
  v14 = attrs->m_Size - v10 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v14 > 0 )
    _V_memmove(dest: &v13[v10 + 1], src: &v13[v10], count: 4 * v14);
  v15 = &attrs->m_Memory.m_pMemory[v10];
  if ( v15 != nullptr )
    *v15 = v11;
}

//------------------------------------------------------------------------------
// Address: 0x0055BEE0
// Name: public: virtual bool CDmeMouseInput::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMouseInput::IsA(CDmeMouseInput *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMouseInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055BF20
// Name: public: virtual int CDmeMouseInput::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMouseInput::GetInheritanceDepth(CDmeMouseInput *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMouseInput::m_classType.u.m_Id )
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
// Address: 0x0055BF80
// Name: protected: virtual void CDmeMouseInput::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::PerformDestruction(CDmeMouseInput *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x0055C030
// Name: protected: virtual void CDmeMouseInput::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::PerformConstruction(CDmeMouseInput *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  CDmeFXClip::OnDestruction();
  v2 = (CDmeMouseInput *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  CDmeFXClip::OnDestruction();
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  *(_DWORD *)&v2[1].m_Id.m_Value[4] = CDmElement::AddExternalAttribute(
                                        this: v3,
                                        pAttributeName: "x",
                                        type: AT_FLOAT,
                                        pMemory: &v2[1].m_Id);
  if ( v2 != nullptr )
    v4 = &v2->CDmElement;
  else
    v4 = nullptr;
  *(_DWORD *)&v2[1].m_Id.m_Value[12] = CDmElement::AddExternalAttribute(
                                         this: v4,
                                         pAttributeName: "y",
                                         type: AT_FLOAT,
                                         pMemory: &v2[1].m_Id.m_Value[8]);
  v2[1].IDmeOperator::__vftable = nullptr;
  v2[1].CDmElement::__vftable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005ADE90
// Name: _dynamic_initializer_for__CDmeMouseInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMouseInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMouseInput::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMouseInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMouseInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005B0630
// Name: _dynamic_atexit_destructor_for__CDmeMouseInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMouseInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMouseInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ADEC0
// Name: _dynamic_initializer_for__g_CDmeMouseInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMouseInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMouseInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005ADED0
// Name: _dynamic_initializer_for__g_CDmeMouseInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMouseInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMouseInput_Helper,
           classname: "DmeMouseInput",
           pFactory: &g_CDmeMouseInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005B0640
// Name: _dynamic_atexit_destructor_for__g_CDmeMouseInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMouseInput_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMouseInput_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005B2C10
// Name: protected: void CDmeMouseInput::GetNormalizedCursorPos(float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::GetNormalizedCursorPos(CDmeMouseInput *this, float *flX, float *flY)
{
  unsigned int v3; // esi
  int v4; // edx
  __m128i v5; // xmm1
  int h; // [esp+4h] [ebp-18h] BYREF
  int y0; // [esp+8h] [ebp-14h] BYREF
  int y; // [esp+Ch] [ebp-10h] BYREF
  int w; // [esp+10h] [ebp-Ch] BYREF
  int x0; // [esp+14h] [ebp-8h] BYREF
  int x; // [esp+18h] [ebp-4h] BYREF

  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  v3 = g_pVGuiInput->GetFocus(this: g_pVGuiInput);
  if ( v3 != 0 )
  {
    g_pVGuiPanel->GetPos(this: g_pVGuiPanel, a2: v3, a3: &x0, a4: &y0);
    g_pVGuiPanel->GetSize(this: g_pVGuiPanel, a2: v3, a3: &w, a4: &h);
    v4 = y - y0;
    v5 = _mm_cvtsi32_si128(h);
    *flX = (float)(x - x0) / (float)w;
    *flY = (float)v4 / _mm_cvtepi32_ps(v5).m128_f32[0];
  }
  else
  {
    *flY = 0.0;
    *flX = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B2CD0
// Name: public: virtual void CDmeMouseInput::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::Operate(CDmeMouseInput *this)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v3; // eax
  float flY; // [esp+8h] [ebp-8h] BYREF
  float flX; // [esp+Ch] [ebp-4h] BYREF

  CDmeMouseInput::GetNormalizedCursorPos(this, &flX, &flY);
  flX = flX - this->m_xOrigin;
  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "x");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: &this->CDmElement, pAttributeName: "x", type: AT_FLOAT)) != nullptr )
  {
    CDmAttribute::SetValue<float>(this: Attribute, value: &flX);
  }
  flY = flY - this->m_yOrigin;
  v3 = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "y");
  if ( v3 != nullptr
    || (v3 = CDmElement::CreateAttribute(this: &this->CDmElement, pAttributeName: "y", type: AT_FLOAT)) != nullptr )
  {
    CDmAttribute::SetValue<float>(this: v3, value: &flY);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005B2D70
// Name: public: virtual bool CDmeMouseInput::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeMouseInput::IsDirty(CDmeMouseInput *this)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<float> *v3; // eax
  CDmAttribute *v4; // eax
  CDmaVar<float> *v5; // eax
  float flY; // [esp+8h] [ebp-8h] BYREF
  float flX; // [esp+Ch] [ebp-4h] BYREF

  CDmeMouseInput::GetNormalizedCursorPos(this, &flX, &flY);
  flX = flX - this->m_xOrigin;
  flY = flY - this->m_yOrigin;
  if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
  }
  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "x");
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<float>(this: Attribute);
  else
    v3 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
  if ( flX != v3->m_Storage )
    return true;
  if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
  }
  v4 = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "y");
  v5 = v4 != nullptr ? CDmAttribute::GetValue<float>(this: v4) : &`CDmElement::GetValue<float>'::`2'::defaultVal;
  return flY != v5->m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x005B2E60
// Name: public: virtual void CDmeMouseInput::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::GetOutputAttributes(CDmeMouseInput *this, CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmElement *v2; // ebx
  CDmAttribute *Attribute; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v6; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmAttribute *v9; // eax
  int v10; // edi
  CDmAttribute *v11; // ebx
  int v12; // eax
  CDmAttribute **v13; // ecx
  int v14; // eax
  CDmAttribute **v15; // eax
  CDmAttribute *v16; // [esp+Ch] [ebp-4h]

  v2 = &this->CDmElement;
  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "x");
  m_pMemory = (int)attrs[1].m_pMemory;
  v16 = Attribute;
  m_nAllocationCount = attrs->m_nAllocationCount;
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
    *v8 = v16;
  v9 = CDmElement::FindAttribute(this: v2, pAttributeName: "y");
  v10 = (int)attrs[1].m_pMemory;
  v11 = v9;
  v12 = attrs->m_nAllocationCount;
  if ( v10 + 1 > v12 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v10 - v12 + 1);
  ++attrs[1].m_pMemory;
  v13 = (CDmAttribute **)attrs->m_pMemory;
  v14 = (int)attrs[1].m_pMemory - v10 - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v14 > 0 )
    _V_memmove(dest: &v13[v10 + 1], src: &v13[v10], count: 4 * v14);
  v15 = (CDmAttribute **)&attrs->m_pMemory[v10];
  if ( v15 != nullptr )
    *v15 = v11;
}

//------------------------------------------------------------------------------
// Address: 0x005B2FE0
// Name: public: virtual bool CDmeMouseInput::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMouseInput::IsA(CDmeMouseInput *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMouseInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005B3020
// Name: public: virtual int CDmeMouseInput::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMouseInput::GetInheritanceDepth(CDmeMouseInput *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMouseInput::m_classType.u.m_Id )
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
// Address: 0x005B3080
// Name: protected: virtual void CDmeMouseInput::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::PerformDestruction(CDmeMouseInput *this)
{
  CDmeFXClip::OnDestruction(this: (vgui::PropertyPage *)((char *)this - 4));
  CDmeFXClip::OnDestruction(this: (vgui::PropertyPage *)((char *)this - 4));
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x005B3120
// Name: protected: virtual void CDmeMouseInput::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::PerformConstruction(CDmeMouseInput *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  v2 = (CDmeMouseInput *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  CDmeFXClip::OnDestruction(this: (vgui::PropertyPage *)v2);
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  *(_DWORD *)&v2[1].m_Id.m_Value[4] = CDmElement::AddExternalAttribute(
                                        this: v3,
                                        pAttributeName: "x",
                                        type: AT_FLOAT,
                                        pMemory: &v2[1].m_Id);
  if ( v2 != nullptr )
    v4 = &v2->CDmElement;
  else
    v4 = nullptr;
  *(_DWORD *)&v2[1].m_Id.m_Value[12] = CDmElement::AddExternalAttribute(
                                         this: v4,
                                         pAttributeName: "y",
                                         type: AT_FLOAT,
                                         pMemory: &v2[1].m_Id.m_Value[8]);
  v2[1].IDmeOperator::__vftable = nullptr;
  v2[1].CDmElement::__vftable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0067F680
// Name: _dynamic_initializer_for__CDmeMouseInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMouseInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMouseInput::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMouseInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMouseInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00682B40
// Name: _dynamic_atexit_destructor_for__CDmeMouseInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMouseInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMouseInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067F6B0
// Name: _dynamic_initializer_for__g_CDmeMouseInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMouseInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMouseInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067F6C0
// Name: _dynamic_initializer_for__g_CDmeMouseInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMouseInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMouseInput_Helper,
           classname: "DmeMouseInput",
           pFactory: &g_CDmeMouseInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00682B50
// Name: _dynamic_atexit_destructor_for__g_CDmeMouseInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMouseInput_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMouseInput_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0051D360
// Name: protected: void CDmeMouseInput::GetNormalizedCursorPos(float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::GetNormalizedCursorPos(CDmeMouseInput *this, float *flX, float *flY)
{
  unsigned int v3; // esi
  int v4; // edx
  __m128i v5; // xmm1
  int h; // [esp+4h] [ebp-18h] BYREF
  int y0; // [esp+8h] [ebp-14h] BYREF
  int y; // [esp+Ch] [ebp-10h] BYREF
  int w; // [esp+10h] [ebp-Ch] BYREF
  int x0; // [esp+14h] [ebp-8h] BYREF
  int x; // [esp+18h] [ebp-4h] BYREF

  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  v3 = g_pVGuiInput->GetFocus(this: g_pVGuiInput);
  if ( v3 != 0 )
  {
    g_pVGuiPanel->GetPos(this: g_pVGuiPanel, a2: v3, a3: &x0, a4: &y0);
    g_pVGuiPanel->GetSize(this: g_pVGuiPanel, a2: v3, a3: &w, a4: &h);
    v4 = y - y0;
    v5 = _mm_cvtsi32_si128(h);
    *flX = (float)(x - x0) / (float)w;
    *flY = (float)v4 / _mm_cvtepi32_ps(v5).m128_f32[0];
  }
  else
  {
    *flY = 0.0;
    *flX = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051D420
// Name: public: virtual void CDmeMouseInput::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::Operate(CDmeMouseInput *this)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v3; // eax
  float flY; // [esp+8h] [ebp-8h] BYREF
  float flX; // [esp+Ch] [ebp-4h] BYREF

  CDmeMouseInput::GetNormalizedCursorPos(this, &flX, &flY);
  flX = flX - this->m_xOrigin;
  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "x");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: &this->CDmElement, pAttributeName: "x", type: AT_FLOAT)) != nullptr )
  {
    CDmAttribute::SetValue<float>(this: Attribute, value: &flX);
  }
  flY = flY - this->m_yOrigin;
  v3 = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "y");
  if ( v3 != nullptr
    || (v3 = CDmElement::CreateAttribute(this: &this->CDmElement, pAttributeName: "y", type: AT_FLOAT)) != nullptr )
  {
    CDmAttribute::SetValue<float>(this: v3, value: &flY);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0051D4C0
// Name: public: virtual bool CDmeMouseInput::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeMouseInput::IsDirty(CDmeMouseInput *this)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<float> *v3; // eax
  CDmAttribute *v4; // eax
  float *v5; // eax
  float flY; // [esp+8h] [ebp-8h] BYREF
  float flX; // [esp+Ch] [ebp-4h] BYREF

  CDmeMouseInput::GetNormalizedCursorPos(this, &flX, &flY);
  flX = flX - this->m_xOrigin;
  flY = flY - this->m_yOrigin;
  if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
  }
  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "x");
  if ( Attribute != nullptr )
    v3 = (CDmaVar<float> *)CDmAttribute::GetValue<float>(this: Attribute);
  else
    v3 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
  if ( flX != v3->m_Storage )
    return true;
  if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
  }
  v4 = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "y");
  v5 = v4 != nullptr
     ? (float *)CDmAttribute::GetValue<float>(this: v4)
     : (float *)&`CDmElement::GetValue<float>'::`2'::defaultVal;
  return flY != *v5;
}

//------------------------------------------------------------------------------
// Address: 0x0051D5B0
// Name: public: virtual void CDmeMouseInput::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::GetOutputAttributes(
        CDmeMouseInput *this,
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *attrs)
{
  CDmElement *v2; // ebx
  CDmAttribute *Attribute; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v6; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmAttribute *v9; // eax
  int v10; // edi
  CDmAttribute *v11; // ebx
  int v12; // eax
  CDmAttribute **v13; // ecx
  int v14; // eax
  CDmAttribute **v15; // eax
  CDmAttribute *v16; // [esp+Ch] [ebp-4h]

  v2 = &this->CDmElement;
  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "x");
  m_pMemory = (int)attrs[1].m_pMemory;
  v16 = Attribute;
  m_nAllocationCount = attrs->m_nAllocationCount;
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
    *v8 = v16;
  v9 = CDmElement::FindAttribute(this: v2, pAttributeName: "y");
  v10 = (int)attrs[1].m_pMemory;
  v11 = v9;
  v12 = attrs->m_nAllocationCount;
  if ( v10 + 1 > v12 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v10 - v12 + 1);
  ++attrs[1].m_pMemory;
  v13 = (CDmAttribute **)attrs->m_pMemory;
  v14 = (int)attrs[1].m_pMemory - v10 - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v14 > 0 )
    _V_memmove(dest: &v13[v10 + 1], src: &v13[v10], count: 4 * v14);
  v15 = (CDmAttribute **)&attrs->m_pMemory[v10];
  if ( v15 != nullptr )
    *v15 = v11;
}

//------------------------------------------------------------------------------
// Address: 0x0051D730
// Name: public: virtual bool CDmeMouseInput::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMouseInput::IsA(CDmeMouseInput *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMouseInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051D770
// Name: public: virtual int CDmeMouseInput::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMouseInput::GetInheritanceDepth(CDmeMouseInput *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMouseInput::m_classType.u.m_Id )
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
// Address: 0x0051D7D0
// Name: protected: virtual void CDmeMouseInput::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::PerformDestruction(CDmeMouseInput *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x0051D880
// Name: protected: virtual void CDmeMouseInput::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::PerformConstruction(CDmeMouseInput *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  CDmeFXClip::OnDestruction();
  v2 = (CDmeMouseInput *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  CDmeFXClip::OnDestruction();
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  *(_DWORD *)&v2[1].m_Id.m_Value[4] = CDmElement::AddExternalAttribute(
                                        this: v3,
                                        pAttributeName: "x",
                                        type: AT_FLOAT,
                                        pMemory: &v2[1].m_Id);
  if ( v2 != nullptr )
    v4 = &v2->CDmElement;
  else
    v4 = nullptr;
  *(_DWORD *)&v2[1].m_Id.m_Value[12] = CDmElement::AddExternalAttribute(
                                         this: v4,
                                         pAttributeName: "y",
                                         type: AT_FLOAT,
                                         pMemory: &v2[1].m_Id.m_Value[8]);
  v2[1].IDmeOperator::__vftable = nullptr;
  v2[1].CDmElement::__vftable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0056C260
// Name: _dynamic_initializer_for__CDmeMouseInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMouseInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMouseInput::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMouseInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMouseInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056ED20
// Name: _dynamic_atexit_destructor_for__CDmeMouseInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMouseInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMouseInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056C290
// Name: _dynamic_initializer_for__g_CDmeMouseInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMouseInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMouseInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056C2A0
// Name: _dynamic_initializer_for__g_CDmeMouseInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMouseInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMouseInput_Helper,
           classname: "DmeMouseInput",
           pFactory: &g_CDmeMouseInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056ED30
// Name: _dynamic_atexit_destructor_for__g_CDmeMouseInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMouseInput_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMouseInput_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x005235C0
// Name: protected: void CDmeMouseInput::GetNormalizedCursorPos(float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::GetNormalizedCursorPos(CDmeMouseInput *this, float *flX, float *flY)
{
  unsigned int v3; // esi
  int v4; // edx
  __m128i v5; // xmm1
  int h; // [esp+4h] [ebp-18h] BYREF
  int y0; // [esp+8h] [ebp-14h] BYREF
  int y; // [esp+Ch] [ebp-10h] BYREF
  int w; // [esp+10h] [ebp-Ch] BYREF
  int x0; // [esp+14h] [ebp-8h] BYREF
  int x; // [esp+18h] [ebp-4h] BYREF

  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  v3 = g_pVGuiInput->GetFocus(this: g_pVGuiInput);
  if ( v3 != 0 )
  {
    g_pVGuiPanel->GetPos(this: g_pVGuiPanel, a2: v3, a3: &x0, a4: &y0);
    g_pVGuiPanel->GetSize(this: g_pVGuiPanel, a2: v3, a3: &w, a4: &h);
    v4 = y - y0;
    v5 = _mm_cvtsi32_si128(h);
    *flX = (float)(x - x0) / (float)w;
    *flY = (float)v4 / _mm_cvtepi32_ps(v5).m128_f32[0];
  }
  else
  {
    *flY = 0.0;
    *flX = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00523680
// Name: public: virtual void CDmeMouseInput::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::Operate(CDmeMouseInput *this)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v3; // eax
  float flY; // [esp+8h] [ebp-8h] BYREF
  float flX; // [esp+Ch] [ebp-4h] BYREF

  CDmeMouseInput::GetNormalizedCursorPos(this, &flX, &flY);
  flX = flX - this->m_xOrigin;
  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "x");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: &this->CDmElement, pAttributeName: "x", type: AT_FLOAT)) != nullptr )
  {
    CDmAttribute::SetValue<float>(this: Attribute, value: &flX);
  }
  flY = flY - this->m_yOrigin;
  v3 = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "y");
  if ( v3 != nullptr
    || (v3 = CDmElement::CreateAttribute(this: &this->CDmElement, pAttributeName: "y", type: AT_FLOAT)) != nullptr )
  {
    CDmAttribute::SetValue<float>(this: v3, value: &flY);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00523720
// Name: public: virtual bool CDmeMouseInput::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeMouseInput::IsDirty(CDmeMouseInput *this)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<float> *v3; // eax
  CDmAttribute *v4; // eax
  CDmaVar<float> *v5; // eax
  float flY; // [esp+8h] [ebp-8h] BYREF
  float flX; // [esp+Ch] [ebp-4h] BYREF

  CDmeMouseInput::GetNormalizedCursorPos(this, &flX, &flY);
  flX = flX - this->m_xOrigin;
  flY = flY - this->m_yOrigin;
  if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
  }
  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "x");
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<float>(this: Attribute);
  else
    v3 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
  if ( flX != v3->m_Storage )
    return true;
  if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
  }
  v4 = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "y");
  v5 = v4 != nullptr ? CDmAttribute::GetValue<float>(this: v4) : &`CDmElement::GetValue<float>'::`2'::defaultVal;
  return flY != v5->m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x00523810
// Name: public: virtual void CDmeMouseInput::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::GetOutputAttributes(
        CDmeMouseInput *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // ebx
  CDmAttribute *Attribute; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmAttribute *v9; // eax
  int v10; // edi
  CDmAttribute *v11; // ebx
  int v12; // eax
  CDmAttribute **v13; // ecx
  int v14; // eax
  CDmAttribute **v15; // eax
  CDmAttribute *v16; // [esp+Ch] [ebp-4h]

  v2 = &this->CDmElement;
  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "x");
  m_Size = attrs->m_Size;
  v16 = Attribute;
  m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
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
    *v8 = v16;
  v9 = CDmElement::FindAttribute(this: v2, pAttributeName: "y");
  v10 = attrs->m_Size;
  v11 = v9;
  v12 = attrs->m_Memory.m_nAllocationCount;
  if ( v10 + 1 > v12 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v10 - v12 + 1);
  ++attrs->m_Size;
  v13 = attrs->m_Memory.m_pMemory;
  v14 = attrs->m_Size - v10 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v14 > 0 )
    _V_memmove(dest: &v13[v10 + 1], src: &v13[v10], count: 4 * v14);
  v15 = &attrs->m_Memory.m_pMemory[v10];
  if ( v15 != nullptr )
    *v15 = v11;
}

//------------------------------------------------------------------------------
// Address: 0x00523990
// Name: public: virtual bool CDmeMouseInput::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMouseInput::IsA(CDmeMouseInput *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMouseInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005239D0
// Name: public: virtual int CDmeMouseInput::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMouseInput::GetInheritanceDepth(CDmeMouseInput *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMouseInput::m_classType.u.m_Id )
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
// Address: 0x00523A30
// Name: protected: virtual void CDmeMouseInput::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::PerformDestruction(CDmeMouseInput *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x00523AE0
// Name: protected: virtual void CDmeMouseInput::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::PerformConstruction(CDmeMouseInput *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  CDmeFXClip::OnDestruction();
  v2 = (CDmeMouseInput *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  CDmeFXClip::OnDestruction();
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  *(_DWORD *)&v2[1].m_Id.m_Value[4] = CDmElement::AddExternalAttribute(
                                        this: v3,
                                        pAttributeName: "x",
                                        type: AT_FLOAT,
                                        pMemory: &v2[1].m_Id);
  if ( v2 != nullptr )
    v4 = &v2->CDmElement;
  else
    v4 = nullptr;
  *(_DWORD *)&v2[1].m_Id.m_Value[12] = CDmElement::AddExternalAttribute(
                                         this: v4,
                                         pAttributeName: "y",
                                         type: AT_FLOAT,
                                         pMemory: &v2[1].m_Id.m_Value[8]);
  v2[1].IDmeOperator::__vftable = nullptr;
  v2[1].CDmElement::__vftable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0057C380
// Name: _dynamic_initializer_for__CDmeMouseInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMouseInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMouseInput::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMouseInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMouseInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EE50
// Name: _dynamic_atexit_destructor_for__CDmeMouseInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMouseInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMouseInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057C3B0
// Name: _dynamic_initializer_for__g_CDmeMouseInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMouseInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMouseInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C3C0
// Name: _dynamic_initializer_for__g_CDmeMouseInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMouseInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMouseInput_Helper,
           classname: "DmeMouseInput",
           pFactory: &g_CDmeMouseInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057EE60
// Name: _dynamic_atexit_destructor_for__g_CDmeMouseInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMouseInput_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMouseInput_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005E04A0
// Name: protected: void CDmeMouseInput::GetNormalizedCursorPos(float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::GetNormalizedCursorPos(CDmeMouseInput *this, float *flX, float *flY)
{
  unsigned int v3; // esi
  int v4; // edx
  __m128i v5; // xmm1
  int h; // [esp+4h] [ebp-18h] BYREF
  int y0; // [esp+8h] [ebp-14h] BYREF
  int y; // [esp+Ch] [ebp-10h] BYREF
  int w; // [esp+10h] [ebp-Ch] BYREF
  int x0; // [esp+14h] [ebp-8h] BYREF
  int x; // [esp+18h] [ebp-4h] BYREF

  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  v3 = g_pVGuiInput->GetFocus(this: g_pVGuiInput);
  if ( v3 != 0 )
  {
    g_pVGuiPanel->GetPos(this: g_pVGuiPanel, a2: v3, a3: &x0, a4: &y0);
    g_pVGuiPanel->GetSize(this: g_pVGuiPanel, a2: v3, a3: &w, a4: &h);
    v4 = y - y0;
    v5 = _mm_cvtsi32_si128(h);
    *flX = (float)(x - x0) / (float)w;
    *flY = (float)v4 / _mm_cvtepi32_ps(v5).m128_f32[0];
  }
  else
  {
    *flY = 0.0;
    *flX = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E0560
// Name: public: virtual void CDmeMouseInput::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::Operate(CDmeMouseInput *this)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v3; // eax
  float flY; // [esp+8h] [ebp-8h] BYREF
  float flX; // [esp+Ch] [ebp-4h] BYREF

  CDmeMouseInput::GetNormalizedCursorPos(this, &flX, &flY);
  flX = flX - this->m_xOrigin;
  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "x");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: &this->CDmElement, pAttributeName: "x", type: AT_FLOAT)) != nullptr )
  {
    CDmAttribute::SetValue<float>(this: Attribute, value: &flX);
  }
  flY = flY - this->m_yOrigin;
  v3 = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "y");
  if ( v3 != nullptr
    || (v3 = CDmElement::CreateAttribute(this: &this->CDmElement, pAttributeName: "y", type: AT_FLOAT)) != nullptr )
  {
    CDmAttribute::SetValue<float>(this: v3, value: &flY);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005E0600
// Name: public: virtual bool CDmeMouseInput::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeMouseInput::IsDirty(CDmeMouseInput *this)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<float> *v3; // eax
  CDmAttribute *v4; // eax
  float *v5; // eax
  float flY; // [esp+8h] [ebp-8h] BYREF
  float flX; // [esp+Ch] [ebp-4h] BYREF

  CDmeMouseInput::GetNormalizedCursorPos(this, &flX, &flY);
  flX = flX - this->m_xOrigin;
  flY = flY - this->m_yOrigin;
  if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
  }
  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "x");
  if ( Attribute != nullptr )
    v3 = (CDmaVar<float> *)CDmAttribute::GetValue<float>(this: Attribute);
  else
    v3 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
  if ( flX != v3->m_Storage )
    return true;
  if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
  }
  v4 = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "y");
  v5 = v4 != nullptr
     ? (float *)CDmAttribute::GetValue<float>(this: v4)
     : (float *)&`CDmElement::GetValue<float>'::`2'::defaultVal;
  return flY != *v5;
}

//------------------------------------------------------------------------------
// Address: 0x005E06F0
// Name: public: virtual void CDmeMouseInput::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::GetOutputAttributes(CDmeMouseInput *this, CUtlMemory<vgui::TreeNode *,int> *attrs)
{
  CDmElement *v2; // ebx
  CDmAttribute *Attribute; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **v6; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmAttribute *v9; // eax
  int v10; // edi
  CDmAttribute *v11; // ebx
  int v12; // eax
  CDmAttribute **v13; // ecx
  int v14; // eax
  CDmAttribute **v15; // eax
  CDmAttribute *v16; // [esp+Ch] [ebp-4h]

  v2 = &this->CDmElement;
  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "x");
  m_pMemory = (int)attrs[1].m_pMemory;
  v16 = Attribute;
  m_nAllocationCount = attrs->m_nAllocationCount;
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
    *v8 = v16;
  v9 = CDmElement::FindAttribute(this: v2, pAttributeName: "y");
  v10 = (int)attrs[1].m_pMemory;
  v11 = v9;
  v12 = attrs->m_nAllocationCount;
  if ( v10 + 1 > v12 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(this: attrs, num: v10 - v12 + 1);
  ++attrs[1].m_pMemory;
  v13 = (CDmAttribute **)attrs->m_pMemory;
  v14 = (int)attrs[1].m_pMemory - v10 - 1;
  attrs[1].m_nAllocationCount = (int)attrs->m_pMemory;
  if ( v14 > 0 )
    _V_memmove(dest: &v13[v10 + 1], src: &v13[v10], count: 4 * v14);
  v15 = (CDmAttribute **)&attrs->m_pMemory[v10];
  if ( v15 != nullptr )
    *v15 = v11;
}

//------------------------------------------------------------------------------
// Address: 0x005E0870
// Name: public: virtual bool CDmeMouseInput::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMouseInput::IsA(CDmeMouseInput *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMouseInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005E08B0
// Name: public: virtual int CDmeMouseInput::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMouseInput::GetInheritanceDepth(CDmeMouseInput *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMouseInput::m_classType.u.m_Id )
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
// Address: 0x005E0910
// Name: protected: virtual void CDmeMouseInput::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::PerformDestruction(CDmeMouseInput *this)
{
  CDmeFXClip::OnDestruction(this: (vgui::PropertyPage *)((char *)this - 4));
  CDmeFXClip::OnDestruction(this: (vgui::PropertyPage *)((char *)this - 4));
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x005E09B0
// Name: protected: virtual void CDmeMouseInput::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::PerformConstruction(CDmeMouseInput *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  v2 = (CDmeMouseInput *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  CDmeFXClip::OnDestruction(this: (vgui::PropertyPage *)v2);
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  *(_DWORD *)&v2[1].m_Id.m_Value[4] = CDmElement::AddExternalAttribute(
                                        this: v3,
                                        pAttributeName: "x",
                                        type: AT_FLOAT,
                                        pMemory: &v2[1].m_Id);
  if ( v2 != nullptr )
    v4 = &v2->CDmElement;
  else
    v4 = nullptr;
  *(_DWORD *)&v2[1].m_Id.m_Value[12] = CDmElement::AddExternalAttribute(
                                         this: v4,
                                         pAttributeName: "y",
                                         type: AT_FLOAT,
                                         pMemory: &v2[1].m_Id.m_Value[8]);
  v2[1].IDmeOperator::__vftable = nullptr;
  v2[1].CDmElement::__vftable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x006B14D0
// Name: _dynamic_initializer_for__CDmeMouseInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMouseInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMouseInput::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMouseInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMouseInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5640
// Name: _dynamic_atexit_destructor_for__CDmeMouseInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMouseInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMouseInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B1500
// Name: _dynamic_initializer_for__g_CDmeMouseInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMouseInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMouseInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B1510
// Name: _dynamic_initializer_for__g_CDmeMouseInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMouseInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMouseInput_Helper,
           classname: "DmeMouseInput",
           pFactory: &g_CDmeMouseInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5650
// Name: _dynamic_atexit_destructor_for__g_CDmeMouseInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMouseInput_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMouseInput_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00524790
// Name: protected: void CDmeMouseInput::GetNormalizedCursorPos(float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::GetNormalizedCursorPos(CDmeMouseInput *this, float *flX, float *flY)
{
  unsigned int v3; // esi
  int v4; // edx
  __m128i v5; // xmm1
  int h; // [esp+4h] [ebp-18h] BYREF
  int y0; // [esp+8h] [ebp-14h] BYREF
  int y; // [esp+Ch] [ebp-10h] BYREF
  int w; // [esp+10h] [ebp-Ch] BYREF
  int x0; // [esp+14h] [ebp-8h] BYREF
  int x; // [esp+18h] [ebp-4h] BYREF

  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  v3 = g_pVGuiInput->GetFocus(this: g_pVGuiInput);
  if ( v3 != 0 )
  {
    g_pVGuiPanel->GetPos(this: g_pVGuiPanel, a2: v3, a3: &x0, a4: &y0);
    g_pVGuiPanel->GetSize(this: g_pVGuiPanel, a2: v3, a3: &w, a4: &h);
    v4 = y - y0;
    v5 = _mm_cvtsi32_si128(h);
    *flX = (float)(x - x0) / (float)w;
    *flY = (float)v4 / _mm_cvtepi32_ps(v5).m128_f32[0];
  }
  else
  {
    *flY = 0.0;
    *flX = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00524850
// Name: public: virtual void CDmeMouseInput::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::Operate(CDmeMouseInput *this)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v3; // eax
  float flY; // [esp+8h] [ebp-8h] BYREF
  float flX; // [esp+Ch] [ebp-4h] BYREF

  CDmeMouseInput::GetNormalizedCursorPos(this, &flX, &flY);
  flX = flX - this->m_xOrigin;
  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "x");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: &this->CDmElement, pAttributeName: "x", type: AT_FLOAT)) != nullptr )
  {
    CDmAttribute::SetValue<float>(this: Attribute, value: &flX);
  }
  flY = flY - this->m_yOrigin;
  v3 = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "y");
  if ( v3 != nullptr
    || (v3 = CDmElement::CreateAttribute(this: &this->CDmElement, pAttributeName: "y", type: AT_FLOAT)) != nullptr )
  {
    CDmAttribute::SetValue<float>(this: v3, value: &flY);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005248F0
// Name: public: virtual bool CDmeMouseInput::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeMouseInput::IsDirty(CDmeMouseInput *this)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<float> *v3; // eax
  CDmAttribute *v4; // eax
  float *v5; // eax
  float flY; // [esp+8h] [ebp-8h] BYREF
  float flX; // [esp+Ch] [ebp-4h] BYREF

  CDmeMouseInput::GetNormalizedCursorPos(this, &flX, &flY);
  flX = flX - this->m_xOrigin;
  flY = flY - this->m_yOrigin;
  if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
  }
  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "x");
  if ( Attribute != nullptr )
    v3 = (CDmaVar<float> *)CDmAttribute::GetValue<float>(this: Attribute);
  else
    v3 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
  if ( flX != v3->m_Storage )
    return true;
  if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
  }
  v4 = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "y");
  v5 = v4 != nullptr
     ? (float *)CDmAttribute::GetValue<float>(this: v4)
     : (float *)&`CDmElement::GetValue<float>'::`2'::defaultVal;
  return flY != *v5;
}

//------------------------------------------------------------------------------
// Address: 0x005249E0
// Name: public: virtual void CDmeMouseInput::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::GetOutputAttributes(
        CDmeMouseInput *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // ebx
  CDmAttribute *Attribute; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmAttribute *v9; // eax
  int v10; // edi
  CDmAttribute *v11; // ebx
  int v12; // eax
  CDmAttribute **v13; // ecx
  int v14; // eax
  CDmAttribute **v15; // eax
  CDmAttribute *v16; // [esp+Ch] [ebp-4h]

  v2 = &this->CDmElement;
  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "x");
  m_Size = attrs->m_Size;
  v16 = Attribute;
  m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
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
    *v8 = v16;
  v9 = CDmElement::FindAttribute(this: v2, pAttributeName: "y");
  v10 = attrs->m_Size;
  v11 = v9;
  v12 = attrs->m_Memory.m_nAllocationCount;
  if ( v10 + 1 > v12 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v10 - v12 + 1);
  ++attrs->m_Size;
  v13 = attrs->m_Memory.m_pMemory;
  v14 = attrs->m_Size - v10 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v14 > 0 )
    _V_memmove(dest: &v13[v10 + 1], src: &v13[v10], count: 4 * v14);
  v15 = &attrs->m_Memory.m_pMemory[v10];
  if ( v15 != nullptr )
    *v15 = v11;
}

//------------------------------------------------------------------------------
// Address: 0x00524B60
// Name: public: virtual bool CDmeMouseInput::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMouseInput::IsA(CDmeMouseInput *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMouseInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00524BA0
// Name: public: virtual int CDmeMouseInput::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMouseInput::GetInheritanceDepth(CDmeMouseInput *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMouseInput::m_classType.u.m_Id )
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
// Address: 0x00524C00
// Name: protected: virtual void CDmeMouseInput::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::PerformDestruction(CDmeMouseInput *this)
{
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x00524CA0
// Name: protected: virtual void CDmeMouseInput::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::PerformConstruction(CDmeMouseInput *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  CDmeFXClip::OnDestruction();
  v2 = (CDmeMouseInput *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  CDmeFXClip::OnDestruction();
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  *(_DWORD *)&v2[1].m_Id.m_Value[4] = CDmElement::AddExternalAttribute(
                                        this: v3,
                                        pAttributeName: "x",
                                        type: AT_FLOAT,
                                        pMemory: &v2[1].m_Id);
  if ( v2 != nullptr )
    v4 = &v2->CDmElement;
  else
    v4 = nullptr;
  *(_DWORD *)&v2[1].m_Id.m_Value[12] = CDmElement::AddExternalAttribute(
                                         this: v4,
                                         pAttributeName: "y",
                                         type: AT_FLOAT,
                                         pMemory: &v2[1].m_Id.m_Value[8]);
  v2[1].IDmeOperator::__vftable = nullptr;
  v2[1].CDmElement::__vftable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0057E350
// Name: _dynamic_initializer_for__CDmeMouseInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMouseInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMouseInput::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMouseInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMouseInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00580E30
// Name: _dynamic_atexit_destructor_for__CDmeMouseInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMouseInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMouseInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E380
// Name: _dynamic_initializer_for__g_CDmeMouseInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMouseInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMouseInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E390
// Name: _dynamic_initializer_for__g_CDmeMouseInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMouseInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMouseInput_Helper,
           classname: "DmeMouseInput",
           pFactory: &g_CDmeMouseInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00580E40
// Name: _dynamic_atexit_destructor_for__g_CDmeMouseInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMouseInput_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMouseInput_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0052BCA0
// Name: protected: void CDmeMouseInput::GetNormalizedCursorPos(float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::GetNormalizedCursorPos(CDmeMouseInput *this, float *flX, float *flY)
{
  unsigned int v3; // esi
  int v4; // edx
  __m128i v5; // xmm1
  int h; // [esp+4h] [ebp-18h] BYREF
  int y0; // [esp+8h] [ebp-14h] BYREF
  int y; // [esp+Ch] [ebp-10h] BYREF
  int w; // [esp+10h] [ebp-Ch] BYREF
  int x0; // [esp+14h] [ebp-8h] BYREF
  int x; // [esp+18h] [ebp-4h] BYREF

  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  v3 = g_pVGuiInput->GetFocus(this: g_pVGuiInput);
  if ( v3 != 0 )
  {
    g_pVGuiPanel->GetPos(this: g_pVGuiPanel, a2: v3, a3: &x0, a4: &y0);
    g_pVGuiPanel->GetSize(this: g_pVGuiPanel, a2: v3, a3: &w, a4: &h);
    v4 = y - y0;
    v5 = _mm_cvtsi32_si128(h);
    *flX = (float)(x - x0) / (float)w;
    *flY = (float)v4 / _mm_cvtepi32_ps(v5).m128_f32[0];
  }
  else
  {
    *flY = 0.0;
    *flX = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052BD60
// Name: public: virtual void CDmeMouseInput::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::Operate(CDmeMouseInput *this)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v3; // eax
  float flY; // [esp+8h] [ebp-8h] BYREF
  float flX; // [esp+Ch] [ebp-4h] BYREF

  CDmeMouseInput::GetNormalizedCursorPos(this, &flX, &flY);
  flX = flX - this->m_xOrigin;
  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "x");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: &this->CDmElement, pAttributeName: "x", type: AT_FLOAT)) != nullptr )
  {
    CDmAttribute::SetValue<float>(this: Attribute, value: &flX);
  }
  flY = flY - this->m_yOrigin;
  v3 = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "y");
  if ( v3 != nullptr
    || (v3 = CDmElement::CreateAttribute(this: &this->CDmElement, pAttributeName: "y", type: AT_FLOAT)) != nullptr )
  {
    CDmAttribute::SetValue<float>(this: v3, value: &flY);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0052BE00
// Name: public: virtual bool CDmeMouseInput::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeMouseInput::IsDirty(CDmeMouseInput *this)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<float> *v3; // eax
  CDmAttribute *v4; // eax
  float *v5; // eax
  float flY; // [esp+8h] [ebp-8h] BYREF
  float flX; // [esp+Ch] [ebp-4h] BYREF

  CDmeMouseInput::GetNormalizedCursorPos(this, &flX, &flY);
  flX = flX - this->m_xOrigin;
  flY = flY - this->m_yOrigin;
  if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
  }
  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "x");
  if ( Attribute != nullptr )
    v3 = (CDmaVar<float> *)CDmAttribute::GetValue<float>(this: Attribute);
  else
    v3 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
  if ( flX != v3->m_Storage )
    return true;
  if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
  }
  v4 = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "y");
  v5 = v4 != nullptr
     ? (float *)CDmAttribute::GetValue<float>(this: v4)
     : (float *)&`CDmElement::GetValue<float>'::`2'::defaultVal;
  return flY != *v5;
}

//------------------------------------------------------------------------------
// Address: 0x0052BEF0
// Name: public: virtual void CDmeMouseInput::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::GetOutputAttributes(
        CDmeMouseInput *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // ebx
  CDmAttribute *Attribute; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmAttribute *v9; // eax
  int v10; // edi
  CDmAttribute *v11; // ebx
  int v12; // eax
  CDmAttribute **v13; // ecx
  int v14; // eax
  CDmAttribute **v15; // eax
  CDmAttribute *v16; // [esp+Ch] [ebp-4h]

  v2 = &this->CDmElement;
  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "x");
  m_Size = attrs->m_Size;
  v16 = Attribute;
  m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
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
    *v8 = v16;
  v9 = CDmElement::FindAttribute(this: v2, pAttributeName: "y");
  v10 = attrs->m_Size;
  v11 = v9;
  v12 = attrs->m_Memory.m_nAllocationCount;
  if ( v10 + 1 > v12 )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)attrs,
      num: v10 - v12 + 1);
  ++attrs->m_Size;
  v13 = attrs->m_Memory.m_pMemory;
  v14 = attrs->m_Size - v10 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v14 > 0 )
    _V_memmove(dest: &v13[v10 + 1], src: &v13[v10], count: 4 * v14);
  v15 = &attrs->m_Memory.m_pMemory[v10];
  if ( v15 != nullptr )
    *v15 = v11;
}

//------------------------------------------------------------------------------
// Address: 0x0052C080
// Name: public: virtual bool CDmeMouseInput::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMouseInput::IsA(CDmeMouseInput *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMouseInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0052C0C0
// Name: public: virtual int CDmeMouseInput::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMouseInput::GetInheritanceDepth(CDmeMouseInput *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMouseInput::m_classType.u.m_Id )
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
// Address: 0x0052C120
// Name: protected: virtual void CDmeMouseInput::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::PerformDestruction(CDmeMouseInput *this)
{
  CDmeFXClip::OnDestruction(this: (CDataManagerBase *)((char *)this - 4));
  CDmeFXClip::OnDestruction(this: (CDataManagerBase *)((char *)this - 4));
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0052C1D0
// Name: protected: virtual void CDmeMouseInput::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::PerformConstruction(CDmeMouseInput *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  v2 = (CDmeMouseInput *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  CDmeFXClip::OnDestruction(this: (CDataManagerBase *)v2);
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  *(_DWORD *)&v2[1].m_Id.m_Value[4] = CDmElement::AddExternalAttribute(
                                        this: v3,
                                        pAttributeName: "x",
                                        type: AT_FLOAT,
                                        pMemory: &v2[1].m_Id);
  if ( v2 != nullptr )
    v4 = &v2->CDmElement;
  else
    v4 = nullptr;
  *(_DWORD *)&v2[1].m_Id.m_Value[12] = CDmElement::AddExternalAttribute(
                                         this: v4,
                                         pAttributeName: "y",
                                         type: AT_FLOAT,
                                         pMemory: &v2[1].m_Id.m_Value[8]);
  v2[1].IDmeOperator::__vftable = nullptr;
  v2[1].CDmElement::__vftable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0057BBA0
// Name: _dynamic_initializer_for__CDmeMouseInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMouseInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMouseInput::s_Allocator,
    blockSize: 100,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMouseInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMouseInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E520
// Name: _dynamic_atexit_destructor_for__CDmeMouseInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMouseInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMouseInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057BBD0
// Name: _dynamic_initializer_for__g_CDmeMouseInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMouseInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMouseInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BBE0
// Name: _dynamic_initializer_for__g_CDmeMouseInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMouseInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMouseInput_Helper,
           classname: "DmeMouseInput",
           pFactory: &g_CDmeMouseInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E530
// Name: _dynamic_atexit_destructor_for__g_CDmeMouseInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMouseInput_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMouseInput_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0062ECC0
// Name: protected: void CDmeMouseInput::GetNormalizedCursorPos(float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::GetNormalizedCursorPos(CDmeMouseInput *this, float *flX, float *flY)
{
  unsigned int v3; // esi
  int v4; // edx
  __m128i v5; // xmm1
  int h; // [esp+4h] [ebp-18h] BYREF
  int y0; // [esp+8h] [ebp-14h] BYREF
  int y; // [esp+Ch] [ebp-10h] BYREF
  int w; // [esp+10h] [ebp-Ch] BYREF
  int x0; // [esp+14h] [ebp-8h] BYREF
  int x; // [esp+18h] [ebp-4h] BYREF

  g_pVGuiInput->GetCursorPos(this: g_pVGuiInput, a2: &x, a3: &y);
  v3 = g_pVGuiInput->GetFocus(this: g_pVGuiInput);
  if ( v3 != 0 )
  {
    g_pVGuiPanel->GetPos(this: g_pVGuiPanel, a2: v3, a3: &x0, a4: &y0);
    g_pVGuiPanel->GetSize(this: g_pVGuiPanel, a2: v3, a3: &w, a4: &h);
    v4 = y - y0;
    v5 = _mm_cvtsi32_si128(h);
    *flX = (float)(x - x0) / (float)w;
    *flY = (float)v4 / _mm_cvtepi32_ps(v5).m128_f32[0];
  }
  else
  {
    *flY = 0.0;
    *flX = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062ED80
// Name: public: virtual void CDmeMouseInput::Operate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::Operate(CDmeMouseInput *this)
{
  CDmAttribute *Attribute; // eax
  CDmAttribute *v3; // eax
  float flY; // [esp+8h] [ebp-8h] BYREF
  float flX; // [esp+Ch] [ebp-4h] BYREF

  CDmeMouseInput::GetNormalizedCursorPos(this, &flX, &flY);
  flX = flX - this->m_xOrigin;
  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "x");
  if ( Attribute != nullptr
    || (Attribute = CDmElement::CreateAttribute(this: &this->CDmElement, pAttributeName: "x", type: AT_FLOAT)) != nullptr )
  {
    CDmAttribute::SetValue<float>(this: Attribute, value: &flX);
  }
  flY = flY - this->m_yOrigin;
  v3 = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "y");
  if ( v3 != nullptr
    || (v3 = CDmElement::CreateAttribute(this: &this->CDmElement, pAttributeName: "y", type: AT_FLOAT)) != nullptr )
  {
    CDmAttribute::SetValue<float>(this: v3, value: &flY);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0062EE20
// Name: public: virtual bool CDmeMouseInput::IsDirty(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeMouseInput::IsDirty(CDmeMouseInput *this)
{
  CDmAttribute *Attribute; // eax
  CDmaVar<float> *v3; // eax
  CDmAttribute *v4; // eax
  CDmaVar<float> *v5; // eax
  float flY; // [esp+8h] [ebp-8h] BYREF
  float flX; // [esp+Ch] [ebp-4h] BYREF

  CDmeMouseInput::GetNormalizedCursorPos(this, &flX, &flY);
  flX = flX - this->m_xOrigin;
  flY = flY - this->m_yOrigin;
  if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
  }
  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "x");
  if ( Attribute != nullptr )
    v3 = CDmAttribute::GetValue<float>(this: Attribute);
  else
    v3 = &`CDmElement::GetValue<float>'::`2'::defaultVal;
  if ( flX != v3->m_Storage )
    return true;
  if ( (`CDmElement::GetValue<float>'::`2'::`local static guard' & 1) == 0 )
  {
    `CDmElement::GetValue<float>'::`2'::`local static guard' |= 1u;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_pAttribute = nullptr;
    `CDmElement::GetValue<float>'::`2'::defaultVal.m_Storage = 0.0;
  }
  v4 = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "y");
  v5 = v4 != nullptr ? CDmAttribute::GetValue<float>(this: v4) : &`CDmElement::GetValue<float>'::`2'::defaultVal;
  return flY != v5->m_Storage;
}

//------------------------------------------------------------------------------
// Address: 0x0062EF10
// Name: public: virtual void CDmeMouseInput::GetOutputAttributes(class CUtlVector<class CDmAttribute __near *,class CUtlMemory<class CDmAttribute __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::GetOutputAttributes(
        CDmeMouseInput *this,
        CUtlVector<CDmAttribute *,CUtlMemory<CDmAttribute *,int> > *attrs)
{
  CDmElement *v2; // ebx
  CDmAttribute *Attribute; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CDmAttribute **m_pMemory; // ecx
  int v7; // eax
  CDmAttribute **v8; // eax
  CDmAttribute *v9; // eax
  int v10; // edi
  CDmAttribute *v11; // ebx
  int v12; // eax
  CDmAttribute **v13; // ecx
  int v14; // eax
  CDmAttribute **v15; // eax
  CDmAttribute *v16; // [esp+Ch] [ebp-4h]

  v2 = &this->CDmElement;
  Attribute = CDmElement::FindAttribute(this: &this->CDmElement, pAttributeName: "x");
  m_Size = attrs->m_Size;
  v16 = Attribute;
  m_nAllocationCount = attrs->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)attrs, num: m_Size - m_nAllocationCount + 1);
  ++attrs->m_Size;
  m_pMemory = attrs->m_Memory.m_pMemory;
  v7 = attrs->m_Size - m_Size - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &attrs->m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = v16;
  v9 = CDmElement::FindAttribute(this: v2, pAttributeName: "y");
  v10 = attrs->m_Size;
  v11 = v9;
  v12 = attrs->m_Memory.m_nAllocationCount;
  if ( v10 + 1 > v12 )
    CUtlMemory<HemiLightData_t *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)attrs, num: v10 - v12 + 1);
  ++attrs->m_Size;
  v13 = attrs->m_Memory.m_pMemory;
  v14 = attrs->m_Size - v10 - 1;
  attrs->m_pElements = attrs->m_Memory.m_pMemory;
  if ( v14 > 0 )
    _V_memmove(dest: &v13[v10 + 1], src: &v13[v10], count: 4 * v14);
  v15 = &attrs->m_Memory.m_pMemory[v10];
  if ( v15 != nullptr )
    *v15 = v11;
}

//------------------------------------------------------------------------------
// Address: 0x0062F090
// Name: public: virtual bool CDmeMouseInput::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMouseInput::IsA(CDmeMouseInput *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMouseInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeInput::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeOperator::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0062F0D0
// Name: public: virtual int CDmeMouseInput::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMouseInput::GetInheritanceDepth(CDmeMouseInput *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMouseInput::m_classType.u.m_Id )
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
// Address: 0x0062F130
// Name: protected: virtual void CDmeMouseInput::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::PerformDestruction(CDmeMouseInput *this)
{
  CDmeFXClip::OnDestruction(this: (CDataManagerBase *)((char *)this - 4));
  CDmeFXClip::OnDestruction(this: (CDataManagerBase *)((char *)this - 4));
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0062F1D0
// Name: protected: virtual void CDmeMouseInput::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMouseInput::PerformConstruction(CDmeMouseInput *this)
{
  CDmeOperator *v2; // esi
  CDmElement *v3; // ecx
  CDmElement *v4; // ecx

  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  v2 = (CDmeMouseInput *)((char *)this - 4);
  CDmeOperator::OnConstruction(this: v2);
  CDmeFXClip::OnDestruction(this: (CDataManagerBase *)v2);
  if ( v2 != nullptr )
    v3 = &v2->CDmElement;
  else
    v3 = nullptr;
  *(_DWORD *)&v2[1].m_Id.m_Value[4] = CDmElement::AddExternalAttribute(
                                        this: v3,
                                        pAttributeName: "x",
                                        type: AT_FLOAT,
                                        pMemory: &v2[1].m_Id);
  if ( v2 != nullptr )
    v4 = &v2->CDmElement;
  else
    v4 = nullptr;
  *(_DWORD *)&v2[1].m_Id.m_Value[12] = CDmElement::AddExternalAttribute(
                                         this: v4,
                                         pAttributeName: "y",
                                         type: AT_FLOAT,
                                         pMemory: &v2[1].m_Id.m_Value[8]);
  v2[1].IDmeOperator::__vftable = nullptr;
  v2[1].CDmElement::__vftable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x006B9B10
// Name: _dynamic_initializer_for__CDmeMouseInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMouseInput::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMouseInput::s_Allocator,
    blockSize: 0x64u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMouseInput pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMouseInput::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BD340
// Name: _dynamic_atexit_destructor_for__CDmeMouseInput::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMouseInput::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMouseInput::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B9B40
// Name: _dynamic_initializer_for__g_CDmeMouseInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMouseInput_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMouseInput_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9B50
// Name: _dynamic_initializer_for__g_CDmeMouseInput_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMouseInput_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMouseInput_Helper,
           classname: "DmeMouseInput",
           pFactory: &g_CDmeMouseInput_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BD350
// Name: _dynamic_atexit_destructor_for__g_CDmeMouseInput_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMouseInput_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeMouseInput_Factory.m_CallBackList);
}

} // namespace vmap
