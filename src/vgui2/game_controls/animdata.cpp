// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vgui2/game_controls/animdata.cpp
// Functions: 19
// ============================================================

#include "vgui2\game_controls\animdata.h"

//------------------------------------------------------------------------------
// Address: 0x00426660
// Name: public: bool CAnimData::Unserialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAnimData::Unserialize(CAnimData *this, CDmxElement *pElement)
{
  const CDmxAttribute *Attribute; // eax
  CDmxElement **m_pData; // eax
  const CDmxAttribute *v6; // eax
  CDmxElement **v7; // eax
  const CDmxAttribute *v8; // eax
  CDmxElement **v9; // eax
  const CDmxAttribute *v10; // eax
  CDmxElement **v11; // eax
  const CDmxAttribute *v12; // eax
  CDmxElement **v13; // eax

  CDmxElement::UnpackIntoStructure(this: pElement, pData: this, pUnpack: s_AnimDataUnpack);
  Attribute = CDmxElement::GetAttribute(this: pElement, pAttributeName: "colorlog");
  if ( Attribute != nullptr )
  {
    if ( Attribute->m_Type == AT_FIRST_VALUE_TYPE )
    {
      m_pData = (CDmxElement **)Attribute->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<CDmxElement *>'::`4'::defaultValue = 0;
      m_pData = (CDmxElement **)&`CDmxAttribute::GetValue<CDmxElement *>'::`4'::defaultValue;
    }
    if ( !CTypedLog<color32_s>::Unserialize(this: &this->m_ColorAnim, pElement: *m_pData) )
      return 0;
  }
  v6 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "centerlog");
  if ( v6 != nullptr )
  {
    if ( v6->m_Type == AT_FIRST_VALUE_TYPE )
    {
      v7 = (CDmxElement **)v6->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<CDmxElement *>'::`4'::defaultValue = 0;
      v7 = (CDmxElement **)&`CDmxAttribute::GetValue<CDmxElement *>'::`4'::defaultValue;
    }
    if ( !CTypedLog<Vector2D>::Unserialize(this: &this->m_CenterPosAnim, pElement: *v7) )
      return 0;
  }
  v8 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "scalelog");
  if ( v8 != nullptr )
  {
    if ( v8->m_Type == AT_FIRST_VALUE_TYPE )
    {
      v9 = (CDmxElement **)v8->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<CDmxElement *>'::`4'::defaultValue = 0;
      v9 = (CDmxElement **)&`CDmxAttribute::GetValue<CDmxElement *>'::`4'::defaultValue;
    }
    if ( !CTypedLog<Vector2D>::Unserialize(this: &this->m_ScaleAnim, pElement: *v9) )
      return 0;
  }
  v10 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "rotationlog");
  if ( v10 != nullptr )
  {
    if ( v10->m_Type == AT_FIRST_VALUE_TYPE )
    {
      v11 = (CDmxElement **)v10->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<CDmxElement *>'::`4'::defaultValue = 0;
      v11 = (CDmxElement **)&`CDmxAttribute::GetValue<CDmxElement *>'::`4'::defaultValue;
    }
    if ( !CTypedLog<float>::Unserialize(this: &this->m_RotationAnim, pElement: *v11) )
      return 0;
  }
  v12 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "fontlog");
  if ( v12 != nullptr
    && (v12->m_Type != AT_FIRST_VALUE_TYPE
      ? (`CDmxAttribute::GetValue<CDmxElement *>'::`4'::defaultValue = 0,
         v13 = (CDmxElement **)&`CDmxAttribute::GetValue<CDmxElement *>'::`4'::defaultValue)
      : (v13 = (CDmxElement **)v12->m_pData),
        !CTypedLog<CUtlString>::Unserialize(this: &this->m_FontAnim, pElement: *v13)) )
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004267A0
// Name: public: bool CTypedLog<class CUtlString>::IsDone(class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CTypedLog<CUtlString>::IsDone(CTypedLog<CUtlString> *this, DmeTime_t time)
{
  int m_Size; // eax

  m_Size = this->m_values.m_Size;
  return m_Size == 0 || time.m_tms >= this->m_times.m_Memory.m_pMemory[m_Size - 1].m_tms;
}

//------------------------------------------------------------------------------
// Address: 0x004267C0
// Name: public: bool CAnimData::IsDone(class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAnimData::IsDone(CAnimData *this, DmeTime_t time)
{
  int m_Size; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  bool result; // al

  m_Size = this->m_ColorAnim.m_values.m_Size;
  result = false;
  if ( m_Size == 0 || time.m_tms >= this->m_ColorAnim.m_times.m_Memory.m_pMemory[m_Size - 1].m_tms )
  {
    v3 = this->m_CenterPosAnim.m_values.m_Size;
    if ( v3 == 0 || time.m_tms >= this->m_CenterPosAnim.m_times.m_Memory.m_pMemory[v3 - 1].m_tms )
    {
      v4 = this->m_ScaleAnim.m_values.m_Size;
      if ( v4 == 0 || time.m_tms >= this->m_ScaleAnim.m_times.m_Memory.m_pMemory[v4 - 1].m_tms )
      {
        v5 = this->m_RotationAnim.m_values.m_Size;
        if ( (v5 == 0 || time.m_tms >= this->m_RotationAnim.m_times.m_Memory.m_pMemory[v5 - 1].m_tms)
          && CTypedLog<CUtlString>::IsDone(this: &this->m_FontAnim, time) )
        {
          return true;
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00426830
// Name: public: CAnimData::~CAnimData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAnimData::~CAnimData(CAnimData *this)
{
  CTypedLog<CUtlString> *p_m_FontAnim; // edi
  bool v3; // sf

  p_m_FontAnim = &this->m_FontAnim;
  v3 = this->m_FontAnim.m_DefaultValue.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_FontAnim.m_DefaultValue.m_Storage.m_nActualLength = 0;
  if ( !v3 )
  {
    if ( this->m_FontAnim.m_DefaultValue.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FontAnim.m_DefaultValue.m_Storage.m_Memory.m_pMemory);
      p_m_FontAnim->m_DefaultValue.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    p_m_FontAnim->m_DefaultValue.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&p_m_FontAnim->m_times);
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::~CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)p_m_FontAnim);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_RotationAnim.m_times);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_RotationAnim);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ScaleAnim.m_times);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ScaleAnim);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_CenterPosAnim.m_times);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_CenterPosAnim);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ColorAnim.m_times);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ColorAnim);
  v3 = this->m_pAnimAlias.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_pAnimAlias.m_Storage.m_nActualLength = 0;
  if ( !v3 )
  {
    if ( this->m_pAnimAlias.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pAnimAlias.m_Storage.m_Memory.m_pMemory);
      this->m_pAnimAlias.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_pAnimAlias.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  v3 = this->m_pStateName.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_pStateName.m_Storage.m_nActualLength = 0;
  if ( !v3 )
  {
    if ( this->m_pStateName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pStateName.m_Storage.m_Memory.m_pMemory);
      this->m_pStateName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_pStateName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426910
// Name: public: CAnimData::CAnimData(void)
// Source: json
//------------------------------------------------------------------------------
CAnimData *__thiscall CAnimData::CAnimData(CAnimData *this)
{
  CUtlString::CUtlString(this: &this->m_pStateName);
  CUtlString::CUtlString(this: &this->m_pAnimAlias);
  this->m_ColorAnim.m_values.m_Memory.m_pMemory = nullptr;
  this->m_ColorAnim.m_values.m_Memory.m_nAllocationCount = 0;
  this->m_ColorAnim.m_values.m_Memory.m_nGrowSize = 0;
  this->m_ColorAnim.m_values.m_Size = 0;
  this->m_ColorAnim.m_values.m_pElements = nullptr;
  this->m_ColorAnim.m_times.m_Memory.m_pMemory = nullptr;
  this->m_ColorAnim.m_times.m_Memory.m_nAllocationCount = 0;
  this->m_ColorAnim.m_times.m_Memory.m_nGrowSize = 0;
  this->m_ColorAnim.m_times.m_Size = 0;
  this->m_ColorAnim.m_times.m_pElements = nullptr;
  this->m_ColorAnim.m_UseDefaultValue = false;
  this->m_ColorAnim.m_bLoop = false;
  this->m_ColorAnim.m_fAnimationRateMultiplier = 1.0;
  this->m_CenterPosAnim.m_values.m_Memory.m_pMemory = nullptr;
  this->m_CenterPosAnim.m_values.m_Memory.m_nAllocationCount = 0;
  this->m_CenterPosAnim.m_values.m_Memory.m_nGrowSize = 0;
  this->m_CenterPosAnim.m_values.m_Size = 0;
  this->m_CenterPosAnim.m_values.m_pElements = nullptr;
  this->m_CenterPosAnim.m_times.m_Memory.m_pMemory = nullptr;
  this->m_CenterPosAnim.m_times.m_Memory.m_nAllocationCount = 0;
  this->m_CenterPosAnim.m_times.m_Memory.m_nGrowSize = 0;
  this->m_CenterPosAnim.m_times.m_Size = 0;
  this->m_CenterPosAnim.m_times.m_pElements = nullptr;
  this->m_CenterPosAnim.m_UseDefaultValue = false;
  this->m_CenterPosAnim.m_bLoop = false;
  this->m_CenterPosAnim.m_fAnimationRateMultiplier = 1.0;
  this->m_ScaleAnim.m_values.m_Memory.m_pMemory = nullptr;
  this->m_ScaleAnim.m_values.m_Memory.m_nAllocationCount = 0;
  this->m_ScaleAnim.m_values.m_Memory.m_nGrowSize = 0;
  this->m_ScaleAnim.m_values.m_Size = 0;
  this->m_ScaleAnim.m_values.m_pElements = nullptr;
  this->m_ScaleAnim.m_times.m_Memory.m_pMemory = nullptr;
  this->m_ScaleAnim.m_times.m_Memory.m_nAllocationCount = 0;
  this->m_ScaleAnim.m_times.m_Memory.m_nGrowSize = 0;
  this->m_ScaleAnim.m_times.m_Size = 0;
  this->m_ScaleAnim.m_times.m_pElements = nullptr;
  this->m_ScaleAnim.m_UseDefaultValue = false;
  this->m_ScaleAnim.m_bLoop = false;
  this->m_ScaleAnim.m_fAnimationRateMultiplier = 1.0;
  this->m_RotationAnim.m_values.m_Memory.m_pMemory = nullptr;
  this->m_RotationAnim.m_values.m_Memory.m_nAllocationCount = 0;
  this->m_RotationAnim.m_values.m_Memory.m_nGrowSize = 0;
  this->m_RotationAnim.m_values.m_Size = 0;
  this->m_RotationAnim.m_values.m_pElements = nullptr;
  this->m_RotationAnim.m_times.m_Memory.m_pMemory = nullptr;
  this->m_RotationAnim.m_times.m_Memory.m_nAllocationCount = 0;
  this->m_RotationAnim.m_times.m_Memory.m_nGrowSize = 0;
  this->m_RotationAnim.m_times.m_Size = 0;
  this->m_RotationAnim.m_times.m_pElements = nullptr;
  this->m_RotationAnim.m_UseDefaultValue = false;
  this->m_RotationAnim.m_bLoop = false;
  this->m_RotationAnim.m_fAnimationRateMultiplier = 1.0;
  this->m_FontAnim.m_values.m_Memory.m_pMemory = nullptr;
  this->m_FontAnim.m_values.m_Memory.m_nAllocationCount = 0;
  this->m_FontAnim.m_values.m_Memory.m_nGrowSize = 0;
  this->m_FontAnim.m_values.m_Size = 0;
  this->m_FontAnim.m_values.m_pElements = nullptr;
  this->m_FontAnim.m_times.m_Memory.m_pMemory = nullptr;
  this->m_FontAnim.m_times.m_Memory.m_nAllocationCount = 0;
  this->m_FontAnim.m_times.m_Memory.m_nGrowSize = 0;
  this->m_FontAnim.m_times.m_Size = 0;
  this->m_FontAnim.m_times.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_FontAnim.m_DefaultValue);
  this->m_FontAnim.m_UseDefaultValue = false;
  this->m_FontAnim.m_bLoop = false;
  this->m_FontAnim.m_fAnimationRateMultiplier = 1.0;
  CUtlString::operator=(this: &this->m_pStateName, src: defaultValue);
  CUtlString::operator=(this: &this->m_pAnimAlias, src: defaultValue);
  this->m_TextureAnimSheetSeqNumber = 0;
  this->m_AnimationRate = 1.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00426AC0
// Name: private: int CTypedLog<class CUtlString>::GetValueForTime(class DmeTime_t)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTypedLog<CUtlString>::GetValueForTime(CTypedLog<CUtlString> *this, DmeTime_t time)
{
  int m_Size; // edx
  int result; // eax
  DmeTime_t *i; // ecx

  m_Size = this->m_values.m_Size;
  if ( m_Size == 1 || time.m_tms == 0 )
    return 0;
  result = 0;
  if ( m_Size <= 0 )
    return m_Size - 1;
  for ( i = this->m_times.m_Memory.m_pMemory; time.m_tms > i->m_tms; ++i )
  {
    if ( ++result >= m_Size )
      return m_Size - 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00426C10
// Name: private: void CTypedLog<struct color32_s>::AdjustTimeByLogAttributes(class DmeTime_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTypedLog<color32_s>::AdjustTimeByLogAttributes(CTypedLog<CUtlString> *this, DmeTime_t *time)
{
  DmeTime_t *v2; // edi
  int m_tms; // ecx

  v2 = time;
  DmeTime_t::operator*=(this: time, result: (DmeTime_t *)&time, f: this->m_fAnimationRateMultiplier);
  m_tms = this->m_times.m_Memory.m_pMemory[this->m_values.m_Size - 1].m_tms;
  if ( this->m_bLoop )
    v2->m_tms %= m_tms;
  if ( v2->m_tms > m_tms )
    v2->m_tms = m_tms;
}

//------------------------------------------------------------------------------
// Address: 0x00426C50
// Name: public: void CTypedLog<struct color32_s>::GetValue(class DmeTime_t,struct color32_s __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTypedLog<color32_s>::GetValue(CTypedLog<color32_s> *this, DmeTime_t time, color32_s *pOutValue)
{
  int m_tms; // edi
  int ValueForTime; // eax
  DmeTime_t *m_pMemory; // ecx
  int v7; // edx
  int v8; // edi
  double v9; // xmm1_8
  color32_s *v10; // ecx
  int r; // edx
  float v12; // xmm3_4
  color32_s *v13; // ecx

  if ( this->m_UseDefaultValue )
  {
    *pOutValue = this->m_DefaultValue;
  }
  else if ( this->m_values.m_Size != 0 )
  {
    CTypedLog<color32_s>::AdjustTimeByLogAttributes((CTypedLog<CUtlString> *)this, &time);
    m_tms = time.m_tms;
    ValueForTime = CTypedLog<CUtlString>::GetValueForTime((CTypedLog<CUtlString> *)this, time);
    if ( ValueForTime != 0 )
    {
      m_pMemory = this->m_times.m_Memory.m_pMemory;
      v7 = m_pMemory[ValueForTime - 1].m_tms;
      v8 = m_tms - v7;
      v9 = (double)(m_pMemory[ValueForTime].m_tms - v7);
      v10 = &this->m_values.m_Memory.m_pMemory[ValueForTime];
      r = v10[-1].r;
      *(float *)&v9 = (double)v8 / v9;
      v12 = (float)v10->r;
      v13 = pOutValue;
      pOutValue->r = (int)(float)((float)((float)r * (float)(1.0 - *(float *)&v9)) + (float)(v12 * *(float *)&v9));
      v13->g = (int)(float)((float)((float)this->m_values.m_Memory.m_pMemory[ValueForTime - 1].g
                                  * (float)(1.0 - *(float *)&v9))
                          + (float)((float)this->m_values.m_Memory.m_pMemory[ValueForTime].g * *(float *)&v9));
      v13->b = (int)(float)((float)((float)this->m_values.m_Memory.m_pMemory[ValueForTime - 1].b
                                  * (float)(1.0 - *(float *)&v9))
                          + (float)((float)this->m_values.m_Memory.m_pMemory[ValueForTime].b * *(float *)&v9));
      v13->a = (int)(float)((float)((float)this->m_values.m_Memory.m_pMemory[ValueForTime - 1].a
                                  * (float)(1.0 - *(float *)&v9))
                          + (float)((float)this->m_values.m_Memory.m_pMemory[ValueForTime].a * *(float *)&v9));
    }
    else
    {
      *pOutValue = *this->m_values.m_Memory.m_pMemory;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426E00
// Name: public: void CTypedLog<class Vector2D>::GetValue(class DmeTime_t,class Vector2D __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTypedLog<Vector2D>::GetValue(CTypedLog<Vector2D> *this, DmeTime_t time, Vector2D *pOutValue)
{
  int m_tms; // edi
  int ValueForTime; // eax
  float v6; // xmm1_4
  float v7; // xmm2_4
  Vector2D *v8; // ecx

  if ( this->m_UseDefaultValue )
  {
    *pOutValue = this->m_DefaultValue;
  }
  else if ( this->m_values.m_Size != 0 )
  {
    CTypedLog<color32_s>::AdjustTimeByLogAttributes((CTypedLog<CUtlString> *)this, &time);
    m_tms = time.m_tms;
    ValueForTime = CTypedLog<CUtlString>::GetValueForTime((CTypedLog<CUtlString> *)this, time);
    if ( ValueForTime != 0 )
    {
      v6 = this->m_values.m_Memory.m_pMemory[ValueForTime].y - this->m_values.m_Memory.m_pMemory[ValueForTime - 1].y;
      v7 = (double)(m_tms - this->m_times.m_Memory.m_pMemory[ValueForTime - 1].m_tms)
         / (double)(this->m_times.m_Memory.m_pMemory[ValueForTime].m_tms
                  - this->m_times.m_Memory.m_pMemory[ValueForTime - 1].m_tms);
      v8 = pOutValue;
      pOutValue->x = (float)((float)(this->m_values.m_Memory.m_pMemory[ValueForTime].x
                                   - this->m_values.m_Memory.m_pMemory[ValueForTime - 1].x)
                           * v7)
                   + this->m_values.m_Memory.m_pMemory[ValueForTime - 1].x;
      v8->y = (float)(v6 * v7) + this->m_values.m_Memory.m_pMemory[ValueForTime - 1].y;
    }
    else
    {
      *pOutValue = *this->m_values.m_Memory.m_pMemory;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426EC0
// Name: public: void CTypedLog<class CUtlString>::GetValue(class DmeTime_t,class CUtlString __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTypedLog<CUtlString>::GetValue(CTypedLog<CUtlString> *this, DmeTime_t time, CUtlString *pOutValue)
{
  int ValueForTime; // eax
  DmeTime_t result; // [esp+8h] [ebp-4h] BYREF

  if ( this->m_UseDefaultValue )
  {
    CUtlString::operator=(this: pOutValue, src: &this->m_DefaultValue);
  }
  else if ( this->m_values.m_Size != 0 )
  {
    DmeTime_t::operator*=(this: &time, &result, f: this->m_fAnimationRateMultiplier);
    CTypedLog<color32_s>::AdjustTimeByLogAttributes(this, &time);
    ValueForTime = CTypedLog<CUtlString>::GetValueForTime(this, time);
    CUtlString::operator=(this: pOutValue, src: &this->m_values.m_Memory.m_pMemory[ValueForTime]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427140
// Name: public: bool CTypedLog<struct color32_s>::Unserialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTypedLog<color32_s>::Unserialize(CTypedLog<color32_s> *this, CDmxElement *pElement)
{
  CDmxElement *v2; // edi
  const CDmxAttribute *Attribute; // eax
  int *m_pData; // eax
  const CDmxAttribute *v6; // eax
  char *v7; // eax
  const CDmxAttribute *v8; // eax
  char *v9; // eax
  const Color *v10; // eax
  unsigned __int8 v11; // cl
  unsigned __int8 v12; // dl
  const CDmxAttribute *v13; // eax
  CDmxAttribute *v14; // esi
  const CDmxAttribute *v15; // eax
  CDmxAttribute *v16; // edi
  int v18; // esi
  char v19; // dl
  DmeTime_t *v20; // eax
  char v21; // cl
  char m_tms_high; // dl
  int v23; // [esp-8h] [ebp-24h]
  const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *logtimes; // [esp+10h] [ebp-Ch]
  const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *nCount; // [esp+14h] [ebp-8h]
  int m_Size; // [esp+18h] [ebp-4h]

  v2 = pElement;
  Attribute = CDmxElement::GetAttribute(this: pElement, pAttributeName: "animationrate");
  if ( Attribute != nullptr )
  {
    if ( Attribute->m_Type == AT_FLOAT )
    {
      m_pData = (int *)Attribute->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
      m_pData = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
    m_pData = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
  }
  this->m_fAnimationRateMultiplier = *(float *)m_pData;
  v6 = CDmxElement::GetAttribute(this: v2, pAttributeName: "loop");
  if ( v6 != nullptr )
  {
    if ( v6->m_Type == AT_BOOL )
    {
      v7 = (char *)v6->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<bool>'::`4'::defaultValue = 0;
      v7 = &`CDmxAttribute::GetValue<bool>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<bool>'::`4'::defaultValue = 0;
    v7 = &`CDmxElement::GetValue<bool>'::`4'::defaultValue;
  }
  this->m_bLoop = *v7;
  v8 = CDmxElement::GetAttribute(this: v2, pAttributeName: "usedefault");
  if ( v8 != nullptr )
  {
    if ( v8->m_Type == AT_BOOL )
    {
      v9 = (char *)v8->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<bool>'::`4'::defaultValue = 0;
      v9 = &`CDmxAttribute::GetValue<bool>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<bool>'::`4'::defaultValue = 0;
    v9 = &`CDmxElement::GetValue<bool>'::`4'::defaultValue;
  }
  this->m_UseDefaultValue = *v9;
  v10 = CDmxElement::GetValue<Color>(this: v2, pAttributeName: "defaultvalue");
  v11 = v10->_color[1];
  LOBYTE(pElement) = v10->_color[0];
  v12 = v10->_color[2];
  LOBYTE(v10) = v10->_color[3];
  BYTE1(pElement) = v11;
  BYTE2(pElement) = v12;
  HIBYTE(pElement) = (_BYTE)v10;
  this->m_DefaultValue = (color32_s)pElement;
  v13 = CDmxElement::GetAttribute(this: v2, pAttributeName: "logvalues");
  v14 = (CDmxAttribute *)v13;
  if ( v13 != nullptr && v13->m_Type == AT_COLOR_ARRAY )
  {
    v15 = CDmxElement::GetAttribute(this: v2, pAttributeName: "logtimes");
    v16 = (CDmxAttribute *)v15;
    if ( v15 == nullptr || v15->m_Type != AT_TIME_ARRAY )
      return 0;
    if ( this->m_UseDefaultValue )
      _Warning(a1: "Warning: Possible unintended behavior: CTypedLog is set to use a default value when there are log entries.\n");
    logtimes = (const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)CDmxAttribute::GetArray<Color>(this: v14);
    nCount = CDmxAttribute::GetArray<DmeTime_t>(this: v16);
    v18 = 0;
    m_Size = logtimes->m_Size;
    if ( m_Size > 0 )
    {
      do
      {
        v19 = BYTE1(logtimes->m_Memory.m_pMemory[v18].m_tms);
        v20 = &logtimes->m_Memory.m_pMemory[v18];
        LOBYTE(pElement) = v20->m_tms;
        v21 = BYTE2(v20->m_tms);
        BYTE1(pElement) = v19;
        m_tms_high = HIBYTE(v20->m_tms);
        BYTE2(pElement) = v21;
        v23 = this->m_values.m_Size;
        HIBYTE(pElement) = m_tms_high;
        CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
          (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)this,
          elem: v23,
          src: (vgui::TreeNode **)&pElement);
        CUtlVector<vgui::ClickPanel *,CUtlMemory<vgui::ClickPanel *,int>>::InsertBefore(
          this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_times,
          elem: this->m_times.m_Size,
          src: (vgui::TreeNode **)&nCount->m_Memory.m_pMemory[v18++]);
      }
      while ( v18 < m_Size );
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004274E0
// Name: private: bool CTypedLog<class Vector2D>::UnSerializeValues(class CDmxAttribute __near *,class CDmxAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTypedLog<Vector2D>::UnSerializeValues(
        CTypedLog<Vector2D> *this,
        const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *pLogValues,
        const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *pLogTimes)
{
  int v3; // ebp
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *p_m_times; // esi
  int v6; // edi
  int m_nAllocationCount; // eax
  DmeTime_t *m_pMemory; // ecx
  int v9; // eax
  bool v10; // zf
  DmeTime_t *v11; // eax
  DmeTime_t *nCount; // [esp+8h] [ebp-8h]
  int m_Size; // [esp+Ch] [ebp-4h]
  const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *logvalues; // [esp+14h] [ebp+4h]
  const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *logtimes; // [esp+18h] [ebp+8h]

  v3 = 0;
  if ( pLogValues->m_Memory.m_pMemory == (Vector2D *)23 )
  {
    logvalues = (const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)pLogValues->m_Memory.m_nGrowSize;
  }
  else
  {
    if ( (`CDmxAttribute::GetArray<Vector2D>'::`4'::`local static guard' & 1) == 0 )
    {
      `CDmxAttribute::GetArray<Vector2D>'::`4'::`local static guard' |= 1u;
      `CDmxAttribute::GetArray<Vector2D>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
      `CDmxAttribute::GetArray<Vector2D>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
      `CDmxAttribute::GetArray<Vector2D>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
      `CDmxAttribute::GetArray<Vector2D>'::`4'::defaultArray.m_Size = 0;
      `CDmxAttribute::GetArray<Vector2D>'::`4'::defaultArray.m_pElements = nullptr;
      atexit(func: `CDmxAttribute::GetArray<Vector2D>'::`4'::`dynamic atexit destructor for 'defaultArray'');
    }
    logvalues = &`CDmxAttribute::GetArray<Vector2D>'::`4'::defaultArray;
  }
  if ( pLogTimes->m_Memory.m_pMemory == (DmeTime_t *)21 )
  {
    logtimes = (const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)pLogTimes->m_Memory.m_nGrowSize;
  }
  else
  {
    if ( (`CDmxAttribute::GetArray<DmeTime_t>'::`4'::`local static guard' & 1) == 0 )
    {
      `CDmxAttribute::GetArray<DmeTime_t>'::`4'::`local static guard' |= 1u;
      `CDmxAttribute::GetArray<DmeTime_t>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
      `CDmxAttribute::GetArray<DmeTime_t>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
      `CDmxAttribute::GetArray<DmeTime_t>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
      `CDmxAttribute::GetArray<DmeTime_t>'::`4'::defaultArray.m_Size = 0;
      `CDmxAttribute::GetArray<DmeTime_t>'::`4'::defaultArray.m_pElements = nullptr;
      atexit(func: `CDmxAttribute::GetArray<DmeTime_t>'::`4'::`dynamic atexit destructor for 'defaultArray'');
    }
    logtimes = &`CDmxAttribute::GetArray<DmeTime_t>'::`4'::defaultArray;
  }
  m_Size = logvalues->m_Size;
  if ( m_Size > 0 )
  {
    p_m_times = &this->m_times;
    do
    {
      CUtlVector<Vector2D,CUtlMemory<Vector2D,int>>::InsertBefore(
        this: &this->m_values,
        elem: this->m_values.m_Size,
        src: &logvalues->m_Memory.m_pMemory[v3]);
      v6 = this->m_times.m_Size;
      nCount = &logtimes->m_Memory.m_pMemory[v3];
      m_nAllocationCount = this->m_times.m_Memory.m_nAllocationCount;
      if ( v6 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&this->m_times,
          num: v6 - m_nAllocationCount + 1);
      ++this->m_times.m_Size;
      m_pMemory = p_m_times->m_Memory.m_pMemory;
      v9 = this->m_times.m_Size - v6 - 1;
      v10 = this->m_times.m_Size - v6 == 1;
      this->m_times.m_pElements = this->m_times.m_Memory.m_pMemory;
      if ( v9 >= 0 && !v10 )
        _V_memmove(dest: &m_pMemory[v6 + 1], src: &m_pMemory[v6], count: 4 * v9);
      v11 = &p_m_times->m_Memory.m_pMemory[v6];
      if ( v11 != nullptr )
        v11->m_tms = nCount->m_tms;
      ++v3;
    }
    while ( v3 < m_Size );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004277B0
// Name: public: bool CTypedLog<class Vector2D>::Unserialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTypedLog<Vector2D>::Unserialize(CTypedLog<Vector2D> *this, CDmxElement *pElement)
{
  const CDmxAttribute *Attribute; // eax
  int *m_pData; // eax
  const CDmxAttribute *v5; // eax
  char *v6; // eax
  const CDmxAttribute *v7; // eax
  char *v8; // eax
  const CDmxAttribute *v9; // eax
  const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *v10; // ebp
  const CDmxAttribute *v12; // eax
  const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *v13; // edi

  Attribute = CDmxElement::GetAttribute(this: pElement, pAttributeName: "animationrate");
  if ( Attribute != nullptr )
  {
    if ( Attribute->m_Type == AT_FLOAT )
    {
      m_pData = (int *)Attribute->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
      m_pData = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
    m_pData = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
  }
  this->m_fAnimationRateMultiplier = *(float *)m_pData;
  v5 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "loop");
  if ( v5 != nullptr )
  {
    if ( v5->m_Type == AT_BOOL )
    {
      v6 = (char *)v5->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<bool>'::`4'::defaultValue = 0;
      v6 = &`CDmxAttribute::GetValue<bool>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<bool>'::`4'::defaultValue = 0;
    v6 = &`CDmxElement::GetValue<bool>'::`4'::defaultValue;
  }
  this->m_bLoop = *v6;
  v7 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "usedefault");
  if ( v7 != nullptr )
  {
    if ( v7->m_Type == AT_BOOL )
    {
      v8 = (char *)v7->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<bool>'::`4'::defaultValue = 0;
      v8 = &`CDmxAttribute::GetValue<bool>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<bool>'::`4'::defaultValue = 0;
    v8 = &`CDmxElement::GetValue<bool>'::`4'::defaultValue;
  }
  this->m_UseDefaultValue = *v8;
  this->m_DefaultValue = *CDmxElement::GetValue<Vector2D>(this: pElement, pAttributeName: "defaultvalue");
  v9 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "logvalues");
  v10 = (const CUtlVector<Vector2D,CUtlMemory<Vector2D,int> > *)v9;
  if ( v9 == nullptr || v9->m_Type != AT_VECTOR2_ARRAY )
    return 1;
  v12 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "logtimes");
  v13 = (const CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)v12;
  if ( v12 == nullptr || v12->m_Type != AT_TIME_ARRAY )
    return 0;
  if ( this->m_UseDefaultValue )
    _Warning(a1: "Warning: Possible unintended behavior: CTypedLog is set to use a default value when there are log entries.\n");
  return CTypedLog<Vector2D>::UnSerializeValues(this, pLogValues: v10, pLogTimes: v13);
}

//------------------------------------------------------------------------------
// Address: 0x004278F0
// Name: private: bool CTypedLog<class CUtlString>::UnSerializeValues(class CDmxAttribute __near *,class CDmxAttribute __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTypedLog<CUtlString>::UnSerializeValues(
        CTypedLog<CUtlString> *this,
        const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *pLogValues,
        CDmxAttribute *pLogTimes)
{
  int v3; // esi
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *p_m_times; // edi
  int m_nAllocationCount; // eax
  const CUtlString *v7; // ebx
  int v8; // esi
  CUtlString *m_pMemory; // ecx
  int v10; // eax
  bool v11; // zf
  CUtlString *v12; // esi
  int v13; // esi
  int v14; // eax
  DmeTime_t *v15; // ebx
  DmeTime_t *v16; // ecx
  int v17; // eax
  DmeTime_t *v18; // esi
  bool v19; // cc
  CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *m_pData; // [esp+8h] [ebp-Ch]
  int nCount; // [esp+Ch] [ebp-8h]
  int m_Size; // [esp+10h] [ebp-4h]
  const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *logvalues; // [esp+18h] [ebp+4h]
  int i; // [esp+1Ch] [ebp+8h]

  v3 = 0;
  if ( pLogValues->m_Memory.m_pMemory == (CUtlString *)19 )
  {
    logvalues = (const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)pLogValues->m_Memory.m_nGrowSize;
  }
  else
  {
    if ( (`CDmxAttribute::GetArray<CUtlString>'::`4'::`local static guard' & 1) == 0 )
    {
      `CDmxAttribute::GetArray<CUtlString>'::`4'::`local static guard' |= 1u;
      `CDmxAttribute::GetArray<CUtlString>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
      `CDmxAttribute::GetArray<CUtlString>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
      `CDmxAttribute::GetArray<CUtlString>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
      `CDmxAttribute::GetArray<CUtlString>'::`4'::defaultArray.m_Size = 0;
      `CDmxAttribute::GetArray<CUtlString>'::`4'::defaultArray.m_pElements = nullptr;
      atexit(func: `CDmxAttribute::GetArray<CUtlString>'::`4'::`dynamic atexit destructor for 'defaultArray'');
    }
    logvalues = &`CDmxAttribute::GetArray<CUtlString>'::`4'::defaultArray;
  }
  if ( pLogTimes->m_Type == AT_TIME_ARRAY )
  {
    m_pData = (CUtlVector<DmeTime_t,CUtlMemory<DmeTime_t,int> > *)pLogTimes->m_pData;
  }
  else
  {
    if ( (`CDmxAttribute::GetArray<DmeTime_t>'::`4'::`local static guard' & 1) == 0 )
    {
      `CDmxAttribute::GetArray<DmeTime_t>'::`4'::`local static guard' |= 1u;
      `CDmxAttribute::GetArray<DmeTime_t>'::`4'::defaultArray.m_Memory.m_pMemory = nullptr;
      `CDmxAttribute::GetArray<DmeTime_t>'::`4'::defaultArray.m_Memory.m_nAllocationCount = 0;
      `CDmxAttribute::GetArray<DmeTime_t>'::`4'::defaultArray.m_Memory.m_nGrowSize = 0;
      `CDmxAttribute::GetArray<DmeTime_t>'::`4'::defaultArray.m_Size = 0;
      `CDmxAttribute::GetArray<DmeTime_t>'::`4'::defaultArray.m_pElements = nullptr;
      atexit(func: `CDmxAttribute::GetArray<DmeTime_t>'::`4'::`dynamic atexit destructor for 'defaultArray'');
    }
    m_pData = &`CDmxAttribute::GetArray<DmeTime_t>'::`4'::defaultArray;
  }
  m_Size = logvalues->m_Size;
  i = 0;
  if ( m_Size > 0 )
  {
    p_m_times = &this->m_times;
    nCount = 0;
    do
    {
      m_nAllocationCount = this->m_values.m_Memory.m_nAllocationCount;
      v7 = (CUtlString *)((char *)logvalues->m_Memory.m_pMemory + v3);
      v8 = this->m_values.m_Size;
      if ( v8 + 1 > m_nAllocationCount )
        CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int>::Grow(
          (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)this,
          num: v8 - m_nAllocationCount + 1);
      ++this->m_values.m_Size;
      m_pMemory = this->m_values.m_Memory.m_pMemory;
      v10 = this->m_values.m_Size - v8 - 1;
      v11 = this->m_values.m_Size - v8 == 1;
      this->m_values.m_pElements = this->m_values.m_Memory.m_pMemory;
      if ( v10 >= 0 && !v11 )
        _V_memmove(dest: &m_pMemory[v8 + 1], src: &m_pMemory[v8], count: 16 * v10);
      v12 = &this->m_values.m_Memory.m_pMemory[v8];
      if ( v12 != nullptr )
        CUtlString::CUtlString(this: v12, string: v7);
      v13 = this->m_times.m_Size;
      v14 = this->m_times.m_Memory.m_nAllocationCount;
      v15 = &m_pData->m_Memory.m_pMemory[i];
      if ( v13 + 1 > v14 )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_times, num: v13 - v14 + 1);
      ++this->m_times.m_Size;
      v16 = p_m_times->m_Memory.m_pMemory;
      v17 = this->m_times.m_Size - v13 - 1;
      v11 = this->m_times.m_Size - v13 == 1;
      this->m_times.m_pElements = this->m_times.m_Memory.m_pMemory;
      if ( v17 >= 0 && !v11 )
        _V_memmove(dest: &v16[v13 + 1], src: &v16[v13], count: 4 * v17);
      v18 = &p_m_times->m_Memory.m_pMemory[v13];
      if ( v18 != nullptr )
        v18->m_tms = v15->m_tms;
      v3 = nCount + 16;
      v19 = ++i < m_Size;
      nCount += 16;
    }
    while ( v19 );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00427AC0
// Name: public: bool CTypedLog<class CUtlString>::Unserialize(class CDmxElement __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CTypedLog<CUtlString>::Unserialize(CTypedLog<CUtlString> *this, CDmxElement *pElement)
{
  const CDmxAttribute *Attribute; // eax
  int *m_pData; // eax
  const CDmxAttribute *v5; // eax
  char *v6; // eax
  const CDmxAttribute *v7; // eax
  char *v8; // eax
  const CUtlString *v9; // eax
  const CDmxAttribute *v10; // eax
  const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v11; // ebp
  const CDmxAttribute *v13; // eax
  CDmxAttribute *v14; // edi

  Attribute = CDmxElement::GetAttribute(this: pElement, pAttributeName: "animationrate");
  if ( Attribute != nullptr )
  {
    if ( Attribute->m_Type == AT_FLOAT )
    {
      m_pData = (int *)Attribute->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<float>'::`4'::defaultValue = 0;
      m_pData = &`CDmxAttribute::GetValue<float>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<float>'::`4'::defaultValue = 0;
    m_pData = &`CDmxElement::GetValue<float>'::`4'::defaultValue;
  }
  this->m_fAnimationRateMultiplier = *(float *)m_pData;
  v5 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "loop");
  if ( v5 != nullptr )
  {
    if ( v5->m_Type == AT_BOOL )
    {
      v6 = (char *)v5->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<bool>'::`4'::defaultValue = 0;
      v6 = &`CDmxAttribute::GetValue<bool>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<bool>'::`4'::defaultValue = 0;
    v6 = &`CDmxElement::GetValue<bool>'::`4'::defaultValue;
  }
  this->m_bLoop = *v6;
  v7 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "usedefault");
  if ( v7 != nullptr )
  {
    if ( v7->m_Type == AT_BOOL )
    {
      v8 = (char *)v7->m_pData;
    }
    else
    {
      `CDmxAttribute::GetValue<bool>'::`4'::defaultValue = 0;
      v8 = &`CDmxAttribute::GetValue<bool>'::`4'::defaultValue;
    }
  }
  else
  {
    `CDmxElement::GetValue<bool>'::`4'::defaultValue = 0;
    v8 = &`CDmxElement::GetValue<bool>'::`4'::defaultValue;
  }
  this->m_UseDefaultValue = *v8;
  v9 = CDmxElement::GetValue<CUtlString>(this: pElement, pAttributeName: "defaultvalue");
  CUtlString::operator=(this: &this->m_DefaultValue, src: v9);
  v10 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "logvalues");
  v11 = (const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)v10;
  if ( v10 == nullptr || v10->m_Type != AT_STRING_ARRAY )
    return 1;
  v13 = CDmxElement::GetAttribute(this: pElement, pAttributeName: "logtimes");
  v14 = (CDmxAttribute *)v13;
  if ( v13 == nullptr || v13->m_Type != AT_TIME_ARRAY )
    return 0;
  if ( this->m_UseDefaultValue )
    _Warning(a1: "Warning: Possible unintended behavior: CTypedLog is set to use a default value when there are log entries.\n");
  return CTypedLog<CUtlString>::UnSerializeValues(this, pLogValues: v11, pLogTimes: v14);
}

//------------------------------------------------------------------------------
// Address: 0x005336A0
// Name: CAnimData_UnpackInit::_dynamic_initializer_for__s_pUnpack__
// Source: json
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *CAnimData_UnpackInit::_dynamic_initializer_for__s_pUnpack__()
{
  DmxElementUnpackStructure_t *result; // eax

  result = DmxElementUnpackInit<CAnimData>();
  s_pUnpack_6 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005336B0
// Name: _dynamic_initializer_for__s_AnimDataUnpack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__s_AnimDataUnpack__()
{
  s_AnimDataUnpack = s_pUnpack_6;
  return s_pUnpack_6;
}

//------------------------------------------------------------------------------
// Address: 0x005336C0
// Name: _dynamic_initializer_for__g_CDynamicRectClassFactory___0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDynamicRectClassFactory___0()
{
  return ((int (__thiscall *)(CGameUISystemMgr *, const char *, CDynamicRectClassFactory *))g_pGameUISystemMgrImpl->RegisterGraphicClassFactory)(
           a1: g_pGameUISystemMgrImpl,
           a2: "rect",
           a3: &g_CDynamicRectClassFactory_0);
}

//------------------------------------------------------------------------------
// Address: 0x005336E0
// Name: _dynamic_initializer_for__s_GameDynamicRectUnpack__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DmxElementUnpackStructure_t *dynamic_initializer_for__s_GameDynamicRectUnpack__()
{
  s_GameDynamicRectUnpack = s_pUnpack_1;
  return s_pUnpack_1;
}
