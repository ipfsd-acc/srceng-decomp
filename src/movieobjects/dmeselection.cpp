// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmeselection.cpp
// Functions: 31
// ============================================================

#include "movieobjects\dmeselection.h"

//------------------------------------------------------------------------------
// Address: 0x004A66F0
// Name: public: virtual int CDmeSingleIndexedComponent::Count(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSingleIndexedComponent::Count(CDmeSingleIndexedComponent *this)
{
  if ( this->m_bComplete.m_Storage )
    return this->m_CompleteCount.m_Storage;
  else
    return this->m_Components.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x004A6700
// Name: public: bool CDmeSingleIndexedComponent::GetComponent(int,int __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSingleIndexedComponent::GetComponent(
        CDmeSingleIndexedComponent *this,
        int index,
        int *component,
        float *weight)
{
  if ( index >= this->Count(this) )
    return 0;
  if ( this->m_bComplete.m_Storage )
  {
    *component = index;
    *weight = 1.0;
  }
  else
  {
    *component = this->m_Components.m_Storage.m_Memory.m_pMemory[index];
    *weight = this->m_Weights.m_Storage.m_Memory.m_pMemory[index];
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004A6760
// Name: public: bool CDmeSingleIndexedComponent::HasComponent(int)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSingleIndexedComponent::HasComponent(CDmeSingleIndexedComponent *this, int component)
{
  int v3; // edi
  int v4; // edx
  int *m_pMemory; // ecx
  int v6; // eax
  int v7; // esi
  CDmeSingleIndexedComponent *v8; // [esp+0h] [ebp-4h]

  v8 = this;
  if ( this->m_bComplete.m_Storage )
    return 1;
  v3 = 0;
  v4 = this->m_Components.m_Storage.m_Size - 1;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Components.m_Storage.m_Memory.m_pMemory;
    while ( 1 )
    {
      v6 = (v4 + v3) >> 1;
      v7 = m_pMemory[v6];
      if ( component <= v7 )
      {
        if ( component >= v7 )
        {
          this = v8;
          return v6 < this->m_Components.m_Storage.m_Size
              && this->m_Components.m_Storage.m_Memory.m_pMemory[v6] == component;
        }
        v4 = v6 - 1;
      }
      else
      {
        v3 = v6 + 1;
      }
      if ( v3 > v4 )
      {
        this = v8;
        break;
      }
    }
  }
  v6 = v3;
  return v6 < this->m_Components.m_Storage.m_Size && this->m_Components.m_Storage.m_Memory.m_pMemory[v6] == component;
}

//------------------------------------------------------------------------------
// Address: 0x004A67D0
// Name: public: bool CDmeSingleIndexedComponent::GetWeight(int,float __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSingleIndexedComponent::GetWeight(CDmeSingleIndexedComponent *this, int component, float *weight)
{
  int v3; // edi
  int v4; // edx
  int *m_pMemory; // ecx
  int v6; // eax
  int v7; // esi
  CDmeSingleIndexedComponent *v9; // [esp+Ch] [ebp-4h]

  v3 = 0;
  v4 = this->m_Components.m_Storage.m_Size - 1;
  v9 = this;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Components.m_Storage.m_Memory.m_pMemory;
    while ( 1 )
    {
      v6 = (v4 + v3) >> 1;
      v7 = m_pMemory[v6];
      if ( component <= v7 )
      {
        if ( component >= v7 )
        {
          this = v9;
          goto LABEL_10;
        }
        v4 = v6 - 1;
      }
      else
      {
        v3 = v6 + 1;
      }
      if ( v3 > v4 )
      {
        this = v9;
        break;
      }
    }
  }
  v6 = v3;
LABEL_10:
  if ( v6 >= this->m_Components.m_Storage.m_Size || this->m_Components.m_Storage.m_Memory.m_pMemory[v6] != component )
    return 0;
  *weight = this->m_Weights.m_Storage.m_Memory.m_pMemory[v6];
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004A6840
// Name: public: void CDmeSingleIndexedComponent::AddComponent(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::AddComponent(CDmeSingleIndexedComponent *this, int component, float weight)
{
  CDmeSingleIndexedComponent *v3; // eax
  int v4; // esi
  int v5; // ecx
  int *m_pMemory; // ebx
  int v7; // eax
  int v8; // edx

  v3 = this;
  if ( this->m_bComplete.m_Storage )
    return;
  v4 = 0;
  v5 = this->m_Components.m_Storage.m_Size - 1;
  if ( v5 < 0 )
    goto LABEL_12;
  m_pMemory = v3->m_Components.m_Storage.m_Memory.m_pMemory;
  while ( 1 )
  {
    v7 = (v5 + v4) >> 1;
    v8 = m_pMemory[v7];
    if ( component <= v8 )
      break;
    v4 = v7 + 1;
LABEL_8:
    if ( v4 > v5 )
      goto LABEL_11;
  }
  if ( component < v8 )
  {
    v5 = v7 - 1;
    goto LABEL_8;
  }
  v4 = (v5 + v4) >> 1;
LABEL_11:
  v3 = this;
LABEL_12:
  if ( v4 == v3->m_Components.m_Storage.m_Size )
  {
    CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::AddToTail(
      this: &v3->m_Components,
      src: (const DmeTime_t *)&component);
    CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddToTail(
      this: &this->m_Weights,
      src: &weight);
  }
  else if ( component == v3->m_Components.m_Storage.m_Memory.m_pMemory[v4] )
  {
    CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::Set(
      this: &v3->m_Weights,
      i: v4,
      value: &weight);
  }
  else
  {
    CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::InsertBefore(
      this: &v3->m_Components,
      elem: (IUndoElement_vtbl *)v4,
      src: (const DmeTime_t *)&component);
    CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::InsertBefore(
      this: &this->m_Weights,
      elem: (CUndoAttributeArrayBase<float>_vtbl *)v4,
      src: &weight);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A6900
// Name: public: void CDmeSingleIndexedComponent::AddComponents(class CUtlVector<int,class CUtlMemory<int,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::AddComponents(
        CDmeSingleIndexedComponent *this,
        const CUtlVector<int,CUtlMemory<int,int> > *components)
{
  int v3; // eax
  bool v4; // zf
  int *m_pMemory; // edx
  int v6; // edi
  int v7; // esi
  int v8; // edx
  int v9; // eax
  int v10; // ecx
  CDmaArray<int> *p_m_Components; // ecx
  int nComponents; // [esp+4h] [ebp-10h]
  int i; // [esp+8h] [ebp-Ch]
  int src; // [esp+Ch] [ebp-8h] BYREF
  float value; // [esp+10h] [ebp-4h] BYREF

  v3 = 0;
  nComponents = components->m_Size;
  i = 0;
  if ( nComponents > 0 )
  {
    do
    {
      v4 = !this->m_bComplete.m_Storage;
      m_pMemory = components->m_Memory.m_pMemory;
      value = 1.0;
      v6 = m_pMemory[v3];
      src = v6;
      if ( v4 )
      {
        v7 = 0;
        v8 = this->m_Components.m_Storage.m_Size - 1;
        if ( v8 >= 0 )
        {
          do
          {
            v9 = (v8 + v7) >> 1;
            v10 = this->m_Components.m_Storage.m_Memory.m_pMemory[v9];
            if ( v6 <= v10 )
            {
              if ( v6 >= v10 )
              {
                v7 = (v8 + v7) >> 1;
                break;
              }
              v8 = v9 - 1;
            }
            else
            {
              v7 = v9 + 1;
            }
          }
          while ( v7 <= v8 );
        }
        p_m_Components = &this->m_Components;
        if ( v7 == this->m_Components.m_Storage.m_Size )
        {
          CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::AddToTail(
            this: p_m_Components,
            (const DmeTime_t *)&src);
          CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::AddToTail(
            this: &this->m_Weights,
            src: &value);
        }
        else if ( v6 == p_m_Components->m_Storage.m_Memory.m_pMemory[v7] )
        {
          CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::Set(
            this: &this->m_Weights,
            i: v7,
            &value);
        }
        else
        {
          CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::InsertBefore(
            this: p_m_Components,
            elem: (IUndoElement_vtbl *)v7,
            (const DmeTime_t *)&src);
          CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::InsertBefore(
            this: &this->m_Weights,
            elem: (CUndoAttributeArrayBase<float>_vtbl *)v7,
            src: &value);
        }
      }
      v3 = i + 1;
      i = v3;
    }
    while ( v3 < nComponents );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A69D0
// Name: public: void CDmeSingleIndexedComponent::RemoveComponent(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::RemoveComponent(CDmeSingleIndexedComponent *this, int component)
{
  CDmeSingleIndexedComponent *v2; // eax
  int v3; // esi
  int v4; // ecx
  int *m_pMemory; // ebx
  int v6; // eax
  int v7; // edx
  CDmeSingleIndexedComponent *v8; // [esp+Ch] [ebp-4h]

  v2 = this;
  v3 = 0;
  v4 = this->m_Components.m_Storage.m_Size - 1;
  v8 = v2;
  if ( v4 < 0 )
    goto LABEL_11;
  m_pMemory = v2->m_Components.m_Storage.m_Memory.m_pMemory;
  while ( 1 )
  {
    v6 = (v4 + v3) >> 1;
    v7 = m_pMemory[v6];
    if ( component <= v7 )
      break;
    v3 = v6 + 1;
LABEL_7:
    if ( v3 > v4 )
      goto LABEL_10;
  }
  if ( component < v7 )
  {
    v4 = v6 - 1;
    goto LABEL_7;
  }
  v3 = (v4 + v3) >> 1;
LABEL_10:
  v2 = v8;
LABEL_11:
  if ( v3 < v2->m_Components.m_Storage.m_Size && v2->m_Components.m_Storage.m_Memory.m_pMemory[v3] == component )
  {
    CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::Remove(this: &v2->m_Components, elem: v3);
    CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::Remove(
      this: &v8->m_Weights,
      elem: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A6A40
// Name: public: void CDmeSingleIndexedComponent::Subtract(class CDmeSingleIndexedComponent const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::Subtract(CDmeSingleIndexedComponent *this, CDmeSingleIndexedComponent *rhs)
{
  CDmeSingleIndexedComponent *v2; // edi
  int (__thiscall *Count)(struct CDmeSingleIndexedComponent *); // edx
  int v4; // esi
  int v5; // ebx
  int v6; // eax
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v8; // ecx
  int *v9; // edi
  int m_Size; // eax
  int v11; // esi
  int *m_pMemory; // ecx
  int v13; // eax
  int *v14; // esi
  float *v15; // edi
  int v16; // eax
  int v17; // esi
  float *v18; // ecx
  int v19; // eax
  float *v20; // esi
  CUtlVector<int,CUtlMemory<int,int> > newComponents; // [esp+Ch] [ebp-38h] BYREF
  CUtlVector<float,CUtlMemory<float,int> > newWeights; // [esp+20h] [ebp-24h] BYREF
  CDmeSingleIndexedComponent *v23; // [esp+34h] [ebp-10h]
  int r; // [esp+38h] [ebp-Ch]
  int nRhs; // [esp+3Ch] [ebp-8h]
  int nLhs; // [esp+40h] [ebp-4h]

  v2 = this;
  Count = this->Count;
  v23 = this;
  nLhs = ((int (__fastcall *)(CDmeSingleIndexedComponent *))Count)(a1: this);
  v4 = 0;
  v5 = 0;
  nRhs = rhs->Count(this: rhs);
  r = 0;
  if ( !v2->m_bComplete.m_Storage )
  {
    memset(&newComponents, 0, sizeof(newComponents));
    CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(
      this: (CUtlVector<CDmMeshComp::CVert *,CUtlMemory<CDmMeshComp::CVert *,int> > *)&newComponents,
      num: nLhs);
    memset(&newWeights, 0, sizeof(newWeights));
    CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(
      this: (CUtlVector<CDmMeshComp::CVert *,CUtlMemory<CDmMeshComp::CVert *,int> > *)&newWeights,
      num: nLhs);
    while ( v5 < nLhs )
    {
      do
      {
        if ( v4 < nRhs
          && v2->m_Components.m_Storage.m_Memory.m_pMemory[v5] >= rhs->m_Components.m_Storage.m_Memory.m_pMemory[v4] )
        {
          break;
        }
        v9 = &v2->m_Components.m_Storage.m_Memory.m_pMemory[v5];
        m_Size = newComponents.m_Size;
        v11 = newComponents.m_Size;
        if ( newComponents.m_Size + 1 > newComponents.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&newComponents,
            num: newComponents.m_Size - newComponents.m_Memory.m_nAllocationCount + 1);
          m_Size = newComponents.m_Size;
        }
        m_pMemory = newComponents.m_Memory.m_pMemory;
        newComponents.m_Size = m_Size + 1;
        v13 = m_Size - v11;
        newComponents.m_pElements = newComponents.m_Memory.m_pMemory;
        if ( v13 > 0 )
        {
          _V_memmove(
            dest: &newComponents.m_Memory.m_pMemory[v11 + 1],
            src: &newComponents.m_Memory.m_pMemory[v11],
            count: 4 * v13);
          m_pMemory = newComponents.m_Memory.m_pMemory;
        }
        v14 = &m_pMemory[v11];
        if ( v14 != nullptr )
          *v14 = *v9;
        v15 = &v23->m_Weights.m_Storage.m_Memory.m_pMemory[v5];
        v16 = newWeights.m_Size;
        v17 = newWeights.m_Size;
        if ( newWeights.m_Size + 1 > newWeights.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&newWeights,
            num: newWeights.m_Size - newWeights.m_Memory.m_nAllocationCount + 1);
          v16 = newWeights.m_Size;
        }
        v18 = newWeights.m_Memory.m_pMemory;
        newWeights.m_Size = v16 + 1;
        v19 = v16 - v17;
        newWeights.m_pElements = newWeights.m_Memory.m_pMemory;
        if ( v19 > 0 )
        {
          _V_memmove(
            dest: &newWeights.m_Memory.m_pMemory[v17 + 1],
            src: &newWeights.m_Memory.m_pMemory[v17],
            count: 4 * v19);
          v18 = newWeights.m_Memory.m_pMemory;
        }
        v20 = &v18[v17];
        if ( v20 != nullptr )
          *v20 = *v15;
        v2 = v23;
        v4 = r;
        ++v5;
      }
      while ( v5 < nLhs );
      if ( v4 < nRhs )
      {
        v6 = nRhs;
        do
        {
LABEL_24:
          if ( v5 < nLhs
            && v2->m_Components.m_Storage.m_Memory.m_pMemory[v5] <= rhs->m_Components.m_Storage.m_Memory.m_pMemory[v4] )
          {
            break;
          }
          ++v4;
        }
        while ( v4 < v6 );
        r = v4;
      }
      for ( ; v5 < nLhs; r = ++v4 )
      {
        if ( v4 >= nRhs )
          break;
        if ( v2->m_Components.m_Storage.m_Memory.m_pMemory[v5] != rhs->m_Components.m_Storage.m_Memory.m_pMemory[v4] )
          break;
        ++v5;
      }
    }
    v6 = nRhs;
    if ( v4 >= nRhs )
    {
      CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::CopyArray(
        this: &v2->m_Components,
        pArray: newComponents.m_Memory.m_pMemory,
        nCount: newComponents.m_Size);
      CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::CopyArray(
        this: &v2->m_Weights,
        pArray: newWeights.m_Memory.m_pMemory,
        nCount: newWeights.m_Size);
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&newWeights);
      CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&newComponents);
      goto LABEL_6;
    }
    goto LABEL_24;
  }
LABEL_6:
  m_pAttribute = v2->m_CompleteCount.m_pAttribute;
  rhs = nullptr;
  CDmAttribute::SetValue<int>(this: m_pAttribute, value: (int *)&rhs);
  v8 = v2->m_bComplete.m_pAttribute;
  HIBYTE(rhs) = 0;
  CDmAttribute::SetValue<bool>(this: v8, value: (const bool *)&rhs + 3);
}

//------------------------------------------------------------------------------
// Address: 0x004A6C70
// Name: public: void CDmeSingleIndexedComponent::Intersection(class CDmeSingleIndexedComponent const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::Intersection(
        CDmeSingleIndexedComponent *this,
        CDmeSingleIndexedComponent *rhs)
{
  CDmeSingleIndexedComponent *v2; // ebx
  int (__thiscall *Count)(struct CDmeSingleIndexedComponent *); // edx
  int v4; // eax
  int v5; // esi
  int v6; // edi
  bool v7; // zf
  int v8; // ecx
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v10; // ecx
  int *m_pMemory; // edx
  int v12; // ebx
  int m_Size; // eax
  int v14; // esi
  int *v15; // edi
  int v16; // eax
  int *v17; // eax
  int v18; // eax
  float *v19; // edi
  int v20; // esi
  float *v21; // ebx
  int v22; // eax
  float *v23; // eax
  CUtlVector<int,CUtlMemory<int,int> > newComponents; // [esp+Ch] [ebp-40h] BYREF
  CUtlVector<float,CUtlMemory<float,int> > newWeights; // [esp+20h] [ebp-2Ch] BYREF
  int *v26; // [esp+34h] [ebp-18h]
  int nRhs; // [esp+38h] [ebp-14h]
  CDmeSingleIndexedComponent *v28; // [esp+3Ch] [ebp-10h]
  int r; // [esp+40h] [ebp-Ch]
  int l; // [esp+44h] [ebp-8h]
  int nLhs; // [esp+48h] [ebp-4h]

  v2 = this;
  Count = this->Count;
  v28 = this;
  nLhs = ((int (__fastcall *)(CDmeSingleIndexedComponent *))Count)(a1: this);
  v4 = rhs->Count(this: rhs);
  v5 = 0;
  v6 = 0;
  v7 = !v2->m_bComplete.m_Storage;
  nRhs = v4;
  l = 0;
  r = 0;
  if ( v7 )
  {
    memset(&newComponents, 0, sizeof(newComponents));
    CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(
      this: (CUtlVector<CDmMeshComp::CVert *,CUtlMemory<CDmMeshComp::CVert *,int> > *)&newComponents,
      num: nLhs);
    memset(&newWeights, 0, sizeof(newWeights));
    CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(
      this: (CUtlVector<CDmMeshComp::CVert *,CUtlMemory<CDmMeshComp::CVert *,int> > *)&newWeights,
      num: nLhs);
    while ( 1 )
    {
LABEL_4:
      v8 = nLhs;
      if ( v6 < nLhs )
      {
        do
        {
          if ( v5 < nRhs )
          {
            v8 = nLhs;
            if ( v2->m_Components.m_Storage.m_Memory.m_pMemory[v6] >= rhs->m_Components.m_Storage.m_Memory.m_pMemory[v5] )
              break;
          }
          ++v6;
        }
        while ( v6 < v8 );
        l = v6;
        if ( v5 >= nRhs )
          goto LABEL_16;
      }
      else if ( v5 >= nRhs )
      {
        CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::CopyArray(
          this: &v2->m_Components,
          pArray: newComponents.m_Memory.m_pMemory,
          nCount: newComponents.m_Size);
        CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::CopyArray(
          this: &v2->m_Weights,
          pArray: newWeights.m_Memory.m_pMemory,
          nCount: newWeights.m_Size);
        CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&newWeights);
        CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&newComponents);
        break;
      }
      do
      {
        if ( v6 < v8
          && v2->m_Components.m_Storage.m_Memory.m_pMemory[v6] <= rhs->m_Components.m_Storage.m_Memory.m_pMemory[v5] )
        {
          break;
        }
        ++v5;
      }
      while ( v5 < nRhs );
      r = v5;
LABEL_16:
      if ( v6 < v8 )
      {
        while ( v5 < nRhs )
        {
          m_pMemory = rhs->m_Components.m_Storage.m_Memory.m_pMemory;
          v12 = v6;
          v26 = &v28->m_Components.m_Storage.m_Memory.m_pMemory[v6];
          if ( *v26 != m_pMemory[v5] )
          {
            v2 = v28;
            goto LABEL_4;
          }
          m_Size = newComponents.m_Size;
          v14 = newComponents.m_Size;
          if ( newComponents.m_Size + 1 > newComponents.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&newComponents,
              num: newComponents.m_Size - newComponents.m_Memory.m_nAllocationCount + 1);
            m_Size = newComponents.m_Size;
          }
          v15 = newComponents.m_Memory.m_pMemory;
          newComponents.m_Size = m_Size + 1;
          v16 = m_Size - v14;
          newComponents.m_pElements = newComponents.m_Memory.m_pMemory;
          if ( v16 > 0 )
            _V_memmove(
              dest: &newComponents.m_Memory.m_pMemory[v14 + 1],
              src: &newComponents.m_Memory.m_pMemory[v14],
              count: 4 * v16);
          v17 = &v15[v14];
          if ( v17 != nullptr )
            *v17 = *v26;
          v18 = newWeights.m_Size;
          v19 = &v28->m_Weights.m_Storage.m_Memory.m_pMemory[v12];
          v20 = newWeights.m_Size;
          if ( newWeights.m_Size + 1 > newWeights.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<IDmFormatUpdater *,int>::Grow(
              this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&newWeights,
              num: newWeights.m_Size - newWeights.m_Memory.m_nAllocationCount + 1);
            v18 = newWeights.m_Size;
          }
          v21 = newWeights.m_Memory.m_pMemory;
          newWeights.m_Size = v18 + 1;
          v22 = v18 - v20;
          newWeights.m_pElements = newWeights.m_Memory.m_pMemory;
          if ( v22 > 0 )
            _V_memmove(
              dest: &newWeights.m_Memory.m_pMemory[v20 + 1],
              src: &newWeights.m_Memory.m_pMemory[v20],
              count: 4 * v22);
          v23 = &v21[v20];
          if ( v23 != nullptr )
            *v23 = *v19;
          v5 = ++r;
          v2 = v28;
          v6 = ++l;
          if ( l >= nLhs )
            goto LABEL_4;
        }
      }
    }
  }
  m_pAttribute = v2->m_CompleteCount.m_pAttribute;
  rhs = nullptr;
  CDmAttribute::SetValue<int>(this: m_pAttribute, value: (int *)&rhs);
  v10 = v2->m_bComplete.m_pAttribute;
  HIBYTE(rhs) = 0;
  CDmAttribute::SetValue<bool>(this: v10, value: (const bool *)&rhs + 3);
}

//------------------------------------------------------------------------------
// Address: 0x004A6EA0
// Name: public: void CDmeSingleIndexedComponent::GetComponents(class CUtlVector<int,class CUtlMemory<int,int>> __near &,class CUtlVector<float,class CUtlMemory<float,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::GetComponents(
        CDmeSingleIndexedComponent *this,
        CUtlVector<int,CUtlMemory<int,int> > *components,
        CUtlVector<float,CUtlMemory<float,int> > *weights)
{
  int v4; // esi
  void *v5; // esp
  void *v6; // esp
  int v7; // edx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v10; // eax
  int i; // eax
  int m_Size; // ebx
  int j; // eax
  _BYTE v15[12]; // [esp+0h] [ebp-14h] BYREF
  float *pWeights; // [esp+Ch] [ebp-8h]
  int *pComponents; // [esp+10h] [ebp-4h]
  int *componentsa; // [esp+1Ch] [ebp+8h]

  if ( this->m_bComplete.m_Storage )
  {
    v4 = this->Count(this);
    v5 = alloca(4 * v4);
    pComponents = (int *)v15;
    v6 = alloca(4 * v4);
    v7 = 0;
    pWeights = (float *)v15;
    if ( v4 > 0 )
    {
      memset32(v15, 1065353216, v4);
      do
      {
        pComponents[v7] = v7;
        ++v7;
      }
      while ( v7 < v4 );
    }
    components->m_Size = 0;
    if ( v4 != 0 )
    {
      m_nAllocationCount = components->m_Memory.m_nAllocationCount;
      if ( v4 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)components,
          num: v4 - m_nAllocationCount);
      components->m_Size += v4;
      m_pMemory = components->m_Memory.m_pMemory;
      v10 = components->m_Size - v4;
      components->m_pElements = components->m_Memory.m_pMemory;
      if ( v10 > 0 && v4 > 0 )
        _V_memmove(dest: &m_pMemory[v4], src: m_pMemory, count: 4 * v10);
    }
    for ( i = 0; i < v4; ++i )
      components->m_Memory.m_pMemory[i] = pComponents[i];
    CUtlVector<float,CUtlMemory<float,int>>::CopyArray(this: weights, pArray: pWeights, size: v4);
  }
  else
  {
    components->m_Size = 0;
    m_Size = this->m_Components.m_Storage.m_Size;
    componentsa = this->m_Components.m_Storage.m_Memory.m_pMemory;
    components->m_Size = 0;
    CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
      this: (CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *)components,
      elem: 0,
      num: m_Size);
    for ( j = 0; j < m_Size; ++j )
      components->m_Memory.m_pMemory[j] = componentsa[j];
    weights->m_Size = 0;
    CUtlVector<float,CUtlMemory<float,int>>::CopyArray(
      this: weights,
      pArray: this->m_Weights.m_Storage.m_Memory.m_pMemory,
      size: this->m_Weights.m_Storage.m_Size);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A6FE0
// Name: public: void CDmeSingleIndexedComponent::GetComponents(class CUtlVector<int,class CUtlMemory<int,int>> __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::GetComponents(
        CDmeSingleIndexedComponent *this,
        CUtlVector<int,CUtlMemory<int,int> > *components)
{
  int v2; // esi
  void *v3; // esp
  int i; // eax
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v7; // eax
  int j; // eax
  int m_Size; // edi
  int *v10; // ebx
  int k; // eax
  _DWORD v12[3]; // [esp+0h] [ebp-Ch]

  if ( this->m_bComplete.m_Storage )
  {
    v2 = this->Count(this);
    v3 = alloca(4 * v2);
    for ( i = 0; i < v2; ++i )
      v12[i] = i;
    components->m_Size = 0;
    if ( v2 != 0 )
    {
      m_nAllocationCount = components->m_Memory.m_nAllocationCount;
      if ( v2 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)components,
          num: v2 - m_nAllocationCount);
      components->m_Size += v2;
      m_pMemory = components->m_Memory.m_pMemory;
      v7 = components->m_Size - v2;
      components->m_pElements = components->m_Memory.m_pMemory;
      if ( v7 > 0 && v2 > 0 )
        _V_memmove(dest: &m_pMemory[v2], src: m_pMemory, count: 4 * v7);
    }
    for ( j = 0; j < v2; ++j )
      components->m_Memory.m_pMemory[j] = v12[j];
  }
  else
  {
    components->m_Size = 0;
    m_Size = this->m_Components.m_Storage.m_Size;
    v10 = this->m_Components.m_Storage.m_Memory.m_pMemory;
    components->m_Size = 0;
    CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
      this: (CUtlVector<studiohdr_t const *,CUtlMemory<studiohdr_t const *,int> > *)components,
      elem: 0,
      num: m_Size);
    for ( k = 0; k < m_Size; ++k )
      components->m_Memory.m_pMemory[k] = v10[k];
  }
}

//------------------------------------------------------------------------------
// Address: 0x004A70C0
// Name: public: void CDmeSingleIndexedComponent::Add(class CDmeSingleIndexedComponent const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::Add(CDmeSingleIndexedComponent *this, CDmeSingleIndexedComponent *rhs)
{
  CDmeSingleIndexedComponent *v2; // ebx
  int (__thiscall *Count)(struct CDmeSingleIndexedComponent *); // edx
  int v4; // eax
  int v5; // edi
  int v6; // esi
  bool v7; // zf
  int *v8; // ecx
  int v9; // edi
  int *v10; // ebx
  int *v11; // ecx
  int *v12; // edi
  int v13; // eax
  int v14; // edi
  float *v15; // ebx
  int v16; // eax
  float *v17; // edi
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v19; // ecx
  int m_Size; // ebx
  CDmeSingleIndexedComponent *v21; // esi
  CDmAttribute *v22; // ecx
  CDmAttribute *v23; // ecx
  int *v24; // edi
  int v25; // eax
  int v26; // esi
  float *m_pMemory; // ecx
  int v28; // eax
  float *v29; // eax
  float *v30; // edi
  int v31; // esi
  int *v32; // ecx
  float *v33; // eax
  int v34; // eax
  int *v35; // edi
  int v36; // esi
  float *v37; // ecx
  int v38; // eax
  int *v39; // eax
  float *v40; // edi
  int v41; // esi
  int *v42; // ecx
  float *v43; // eax
  int *v44; // ecx
  int v45; // edx
  int v46; // eax
  int v47; // esi
  float *v48; // edi
  int v49; // eax
  float *v50; // eax
  float *v51; // edi
  int v52; // esi
  int *v53; // ecx
  float *v54; // eax
  CUtlVector<int,CUtlMemory<int,int> > newComponents; // [esp+Ch] [ebp-44h] BYREF
  CUtlVector<float,CUtlMemory<float,int> > newWeights; // [esp+20h] [ebp-30h] BYREF
  double v57; // [esp+34h] [ebp-1Ch]
  CDmeSingleIndexedComponent *v58; // [esp+3Ch] [ebp-14h]
  int nLhs; // [esp+40h] [ebp-10h]
  int nRhs; // [esp+44h] [ebp-Ch] BYREF
  int r; // [esp+48h] [ebp-8h]
  int l; // [esp+4Ch] [ebp-4h]

  v2 = this;
  Count = this->Count;
  v58 = this;
  nLhs = ((int (__fastcall *)(CDmeSingleIndexedComponent *))Count)(a1: this);
  v4 = rhs->Count(this: rhs);
  v5 = 0;
  v6 = 0;
  v7 = !v2->m_bComplete.m_Storage;
  nRhs = v4;
  l = 0;
  r = 0;
  if ( v7 )
  {
    memset(&newWeights, 0, sizeof(newWeights));
    v57 = (double)nLhs;
    CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(
      this: (CUtlVector<CDmMeshComp::CVert *,CUtlMemory<CDmMeshComp::CVert *,int> > *)&newWeights,
      num: (int)((double)v4 * 0.5 + (double)nLhs));
    memset(&newComponents, 0, sizeof(newComponents));
    CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(
      this: (CUtlVector<CDmMeshComp::CVert *,CUtlMemory<CDmMeshComp::CVert *,int> > *)&newComponents,
      num: (int)((double)nRhs * 0.5 + v57));
    m_Size = newComponents.m_Size;
    while ( v5 < nLhs )
    {
      do
      {
        if ( v6 < nRhs
          && v58->m_Components.m_Storage.m_Memory.m_pMemory[v5] >= rhs->m_Components.m_Storage.m_Memory.m_pMemory[v6] )
        {
          break;
        }
        v24 = &v58->m_Components.m_Storage.m_Memory.m_pMemory[v5];
        v25 = newWeights.m_Size;
        v26 = newWeights.m_Size;
        if ( newWeights.m_Size + 1 > newWeights.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&newWeights,
            num: newWeights.m_Size - newWeights.m_Memory.m_nAllocationCount + 1);
          v25 = newWeights.m_Size;
        }
        m_pMemory = newWeights.m_Memory.m_pMemory;
        newWeights.m_Size = v25 + 1;
        v28 = v25 - v26;
        newWeights.m_pElements = newWeights.m_Memory.m_pMemory;
        if ( v28 > 0 )
        {
          _V_memmove(
            dest: &newWeights.m_Memory.m_pMemory[v26 + 1],
            src: &newWeights.m_Memory.m_pMemory[v26],
            count: 4 * v28);
          m_pMemory = newWeights.m_Memory.m_pMemory;
        }
        v29 = &m_pMemory[v26];
        if ( v29 != nullptr )
          *(_DWORD *)v29 = *v24;
        v30 = &v58->m_Weights.m_Storage.m_Memory.m_pMemory[l];
        v31 = m_Size;
        if ( m_Size + 1 > newComponents.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&newComponents,
            num: m_Size - newComponents.m_Memory.m_nAllocationCount + 1);
          m_Size = newComponents.m_Size;
        }
        v32 = newComponents.m_Memory.m_pMemory;
        newComponents.m_Size = ++m_Size;
        newComponents.m_pElements = newComponents.m_Memory.m_pMemory;
        if ( m_Size - v31 - 1 > 0 )
        {
          _V_memmove(
            dest: &newComponents.m_Memory.m_pMemory[v31 + 1],
            src: &newComponents.m_Memory.m_pMemory[v31],
            count: 4 * (m_Size - v31 - 1));
          v32 = newComponents.m_Memory.m_pMemory;
        }
        v33 = (float *)&v32[v31];
        if ( v33 != nullptr )
          *v33 = *v30;
        v6 = r;
        v5 = ++l;
      }
      while ( l < nLhs );
      if ( v6 < nRhs )
        goto LABEL_47;
LABEL_62:
      if ( v5 >= nLhs )
        break;
      do
      {
        if ( v6 >= nRhs )
          break;
        v44 = rhs->m_Components.m_Storage.m_Memory.m_pMemory;
        v45 = v58->m_Components.m_Storage.m_Memory.m_pMemory[v5];
        HIDWORD(v57) = &v58->m_Components.m_Storage.m_Memory.m_pMemory[v5];
        if ( v45 != v44[v6] )
          break;
        v46 = newWeights.m_Size;
        v47 = newWeights.m_Size;
        if ( newWeights.m_Size + 1 > newWeights.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&newWeights,
            num: newWeights.m_Size - newWeights.m_Memory.m_nAllocationCount + 1);
          v46 = newWeights.m_Size;
        }
        v48 = newWeights.m_Memory.m_pMemory;
        newWeights.m_Size = v46 + 1;
        v49 = v46 - v47;
        newWeights.m_pElements = newWeights.m_Memory.m_pMemory;
        if ( v49 > 0 )
          _V_memmove(
            dest: &newWeights.m_Memory.m_pMemory[v47 + 1],
            src: &newWeights.m_Memory.m_pMemory[v47],
            count: 4 * v49);
        v50 = &v48[v47];
        if ( v50 != nullptr )
          *v50 = *(float *)HIDWORD(v57);
        v51 = &v58->m_Weights.m_Storage.m_Memory.m_pMemory[l];
        v52 = m_Size;
        if ( m_Size + 1 > newComponents.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&newComponents,
            num: m_Size - newComponents.m_Memory.m_nAllocationCount + 1);
          m_Size = newComponents.m_Size;
        }
        v53 = newComponents.m_Memory.m_pMemory;
        newComponents.m_Size = ++m_Size;
        newComponents.m_pElements = newComponents.m_Memory.m_pMemory;
        if ( m_Size - v52 - 1 > 0 )
        {
          _V_memmove(
            dest: &newComponents.m_Memory.m_pMemory[v52 + 1],
            src: &newComponents.m_Memory.m_pMemory[v52],
            count: 4 * (m_Size - v52 - 1));
          v53 = newComponents.m_Memory.m_pMemory;
        }
        v54 = (float *)&v53[v52];
        if ( v54 != nullptr )
          *v54 = *v51;
        v6 = ++r;
        v5 = ++l;
      }
      while ( l < nLhs );
    }
    if ( v6 >= nRhs )
    {
      v21 = v58;
      CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::CopyArray(
        this: &v58->m_Components,
        pArray: (int *)newWeights.m_Memory.m_pMemory,
        nCount: newWeights.m_Size);
      CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::CopyArray(
        this: &v21->m_Weights,
        pArray: (float *)newComponents.m_Memory.m_pMemory,
        nCount: m_Size);
      CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&newComponents);
      CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&newWeights);
      v2 = v21;
      goto LABEL_30;
    }
    do
    {
LABEL_47:
      if ( v5 < nLhs
        && v58->m_Components.m_Storage.m_Memory.m_pMemory[v5] <= rhs->m_Components.m_Storage.m_Memory.m_pMemory[v6] )
      {
        break;
      }
      v34 = newWeights.m_Size;
      v35 = &rhs->m_Components.m_Storage.m_Memory.m_pMemory[v6];
      v36 = newWeights.m_Size;
      if ( newWeights.m_Size + 1 > newWeights.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&newWeights,
          num: newWeights.m_Size - newWeights.m_Memory.m_nAllocationCount + 1);
        v34 = newWeights.m_Size;
      }
      v37 = newWeights.m_Memory.m_pMemory;
      newWeights.m_Size = v34 + 1;
      v38 = v34 - v36;
      newWeights.m_pElements = newWeights.m_Memory.m_pMemory;
      if ( v38 > 0 )
      {
        _V_memmove(
          dest: &newWeights.m_Memory.m_pMemory[v36 + 1],
          src: &newWeights.m_Memory.m_pMemory[v36],
          count: 4 * v38);
        v37 = newWeights.m_Memory.m_pMemory;
      }
      v39 = (int *)&v37[v36];
      if ( v39 != nullptr )
        *v39 = *v35;
      v40 = &rhs->m_Weights.m_Storage.m_Memory.m_pMemory[r];
      v41 = m_Size;
      if ( m_Size + 1 > newComponents.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<IDmFormatUpdater *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&newComponents,
          num: m_Size - newComponents.m_Memory.m_nAllocationCount + 1);
        m_Size = newComponents.m_Size;
      }
      v42 = newComponents.m_Memory.m_pMemory;
      newComponents.m_Size = ++m_Size;
      newComponents.m_pElements = newComponents.m_Memory.m_pMemory;
      if ( m_Size - v41 - 1 > 0 )
      {
        _V_memmove(
          dest: &newComponents.m_Memory.m_pMemory[v41 + 1],
          src: &newComponents.m_Memory.m_pMemory[v41],
          count: 4 * (m_Size - v41 - 1));
        v42 = newComponents.m_Memory.m_pMemory;
      }
      v43 = (float *)&v42[v41];
      if ( v43 != nullptr )
        *v43 = *v40;
      v5 = l;
      v6 = ++r;
    }
    while ( r < nRhs );
    goto LABEL_62;
  }
  if ( rhs->m_bComplete.m_Storage && v4 > nLhs )
  {
    CDmAttribute::SetValue<int>(this: v2->m_CompleteCount.m_pAttribute, value: &nRhs);
  }
  else if ( v4 > 0 )
  {
    v8 = rhs->m_Components.m_Storage.m_Memory.m_pMemory;
    while ( *v8 < nLhs )
    {
      ++v6;
      ++v8;
      if ( v6 >= v4 )
        goto LABEL_30;
    }
    memset(&newComponents, 0, sizeof(newComponents));
    CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(
      this: (CUtlVector<CDmMeshComp::CVert *,CUtlMemory<CDmMeshComp::CVert *,int> > *)&newComponents,
      num: nLhs + v4 - v6);
    memset(&newWeights, 0, sizeof(newWeights));
    CUtlVector<float,CUtlMemory<float,int>>::EnsureCapacity(
      this: (CUtlVector<CDmMeshComp::CVert *,CUtlMemory<CDmMeshComp::CVert *,int> > *)&newWeights,
      num: nLhs + nRhs - v6);
    CDmeSingleIndexedComponent::GetComponents(this: v2, components: &newComponents, weights: &newWeights);
    if ( v6 < nRhs )
    {
      do
      {
        v9 = newComponents.m_Size;
        v10 = &rhs->m_Components.m_Storage.m_Memory.m_pMemory[v6];
        if ( newComponents.m_Size + 1 > newComponents.m_Memory.m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&newComponents,
            num: newComponents.m_Size - newComponents.m_Memory.m_nAllocationCount + 1);
        v11 = newComponents.m_Memory.m_pMemory;
        ++newComponents.m_Size;
        newComponents.m_pElements = newComponents.m_Memory.m_pMemory;
        if ( newComponents.m_Size - v9 - 1 > 0 )
        {
          _V_memmove(
            dest: &newComponents.m_Memory.m_pMemory[v9 + 1],
            src: &newComponents.m_Memory.m_pMemory[v9],
            count: 4 * (newComponents.m_Size - v9 - 1));
          v11 = newComponents.m_Memory.m_pMemory;
        }
        v12 = &v11[v9];
        if ( v12 != nullptr )
          *v12 = *v10;
        nLhs = (int)&rhs->m_Weights.m_Storage.m_Memory.m_pMemory[v6];
        v13 = newWeights.m_Size;
        v14 = newWeights.m_Size;
        if ( newWeights.m_Size + 1 > newWeights.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<IDmFormatUpdater *,int>::Grow(
            this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&newWeights,
            num: newWeights.m_Size - newWeights.m_Memory.m_nAllocationCount + 1);
          v13 = newWeights.m_Size;
        }
        v15 = newWeights.m_Memory.m_pMemory;
        newWeights.m_Size = v13 + 1;
        v16 = v13 - v14;
        newWeights.m_pElements = newWeights.m_Memory.m_pMemory;
        if ( v16 > 0 )
          _V_memmove(
            dest: &newWeights.m_Memory.m_pMemory[v14 + 1],
            src: &newWeights.m_Memory.m_pMemory[v14],
            count: 4 * v16);
        v17 = &v15[v14];
        if ( v17 != nullptr )
          *v17 = *(float *)nLhs;
        ++v6;
      }
      while ( v6 < nRhs );
      v2 = v58;
    }
    CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::CopyArray(
      this: &v2->m_Components,
      pArray: newComponents.m_Memory.m_pMemory,
      nCount: newComponents.m_Size);
    CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::CopyArray(
      this: &v2->m_Weights,
      pArray: newWeights.m_Memory.m_pMemory,
      nCount: newWeights.m_Size);
    m_pAttribute = v2->m_CompleteCount.m_pAttribute;
    rhs = nullptr;
    CDmAttribute::SetValue<int>(this: m_pAttribute, value: (int *)&rhs);
    v19 = v2->m_bComplete.m_pAttribute;
    HIBYTE(rhs) = 0;
    CDmAttribute::SetValue<bool>(this: v19, value: (const bool *)&rhs + 3);
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&newWeights);
    CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>::~CUtlVector<LuaFunc_s *,CUtlMemory<LuaFunc_s *,int>>(this: (CUtlVector<char const *,CUtlMemory<char const *,int> > *)&newComponents);
  }
LABEL_30:
  v22 = v2->m_CompleteCount.m_pAttribute;
  rhs = nullptr;
  CDmAttribute::SetValue<int>(this: v22, value: (int *)&rhs);
  v23 = v2->m_bComplete.m_pAttribute;
  HIBYTE(rhs) = 0;
  CDmAttribute::SetValue<bool>(this: v23, value: (const bool *)&rhs + 3);
}

//------------------------------------------------------------------------------
// Address: 0x004A7730
// Name: public: virtual bool CDmeComponent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeComponent::IsA(CDmeComponent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A7760
// Name: public: virtual int CDmeComponent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeComponent::GetInheritanceDepth(CDmeComponent *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A77A0
// Name: public: virtual void CDmeComponent::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeComponent::Clear(CDmeComponent *this)
{
  CDmAttribute *m_pAttribute; // ecx
  bool value; // [esp+1h] [ebp-1h] BYREF

  value = HIBYTE(this);
  m_pAttribute = this->m_bComplete.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x004A7820
// Name: protected: virtual void CDmeComponent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeComponent::PerformConstruction(CDmeComponent *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-8h] BYREF
  bool v5; // [esp+Fh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction();
  value = -1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "componentType", type: AT_INT, pMemory: &this->m_Type);
  this->m_Type.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  v5 = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "complete", type: AT_BOOL, pMemory: &this->m_bComplete);
  this->m_bComplete.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, value: &v5);
}

//------------------------------------------------------------------------------
// Address: 0x004A7880
// Name: public: virtual bool CDmeComponent::IsEqual(class CDmeComponent const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeComponent::IsEqual(CDmeComponent *this, CDmeComponent *pRhs)
{
  unsigned int m_Storage; // eax
  unsigned int v4; // ecx
  int v5; // ebx
  BOOL result; // eax

  m_Storage = this->m_Type.m_Storage;
  if ( m_Storage > 1 )
    m_Storage = -1;
  v4 = pRhs->m_Type.m_Storage;
  if ( v4 > 1 )
    v4 = -1;
  result = false;
  if ( m_Storage == v4 )
  {
    v5 = pRhs->Count(this: pRhs);
    if ( this->Count(this) == v5 && this->m_bComplete.m_Storage == pRhs->m_bComplete.m_Storage )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004A7940
// Name: public: virtual bool CDmeSingleIndexedComponent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSingleIndexedComponent::IsA(CDmeSingleIndexedComponent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSingleIndexedComponent::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A7970
// Name: public: virtual int CDmeSingleIndexedComponent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSingleIndexedComponent::GetInheritanceDepth(
        CDmeSingleIndexedComponent *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSingleIndexedComponent::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004A79C0
// Name: public: virtual void CDmeSingleIndexedComponent::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::Clear(CDmeSingleIndexedComponent *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  int v4; // [esp+4h] [ebp-8h] BYREF
  bool value; // [esp+Bh] [ebp-1h] BYREF

  m_pAttribute = this->m_bComplete.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
  v3 = this->m_CompleteCount.m_pAttribute;
  v4 = 0;
  CDmAttribute::SetValue<int>(this: v3, value: &v4);
  CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::RemoveAll(this: &this->m_Components);
  CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::RemoveAll(this: &this->m_Weights);
}

//------------------------------------------------------------------------------
// Address: 0x004A7A10
// Name: protected: virtual void CDmeSingleIndexedComponent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::PerformConstruction(CDmeSingleIndexedComponent *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  int value; // [esp+8h] [ebp-8h] BYREF
  bool v6; // [esp+Fh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction();
  value = -1;
  v2 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "componentType",
         type: AT_INT,
         pMemory: &this->CDmeComponent::m_Type);
  this->CDmeComponent::m_Type.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  v6 = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "complete", type: AT_BOOL, pMemory: &this->m_bComplete);
  this->m_bComplete.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, value: &v6);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "completeCount",
         type: AT_INT,
         pMemory: &this->m_CompleteCount);
  this->m_CompleteCount.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, &value);
  CDmaDecorator<int,CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &this->m_Components,
    pOwner: this,
    pAttributeName: "components",
    nFlags: 0);
  CDmaDecorator<float,CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &this->m_Weights,
    pOwner: this,
    pAttributeName: "weights",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x005AB840
// Name: _dynamic_initializer_for__CDmeComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeComponent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeComponent::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeComponent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AB8A0
// Name: _dynamic_initializer_for__CDmeSingleIndexedComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSingleIndexedComponent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSingleIndexedComponent::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSingleIndexedComponent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005AF980
// Name: _dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeComponent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AF990
// Name: _dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSingleIndexedComponent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005AB870
// Name: _dynamic_initializer_for__g_CDmeComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeComponent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeComponent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AB880
// Name: _dynamic_initializer_for__g_CDmeComponent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeComponent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeComponent_Helper,
           classname: "DmeComponent",
           pFactory: &g_CDmeComponent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AB8D0
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSingleIndexedComponent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005AB8E0
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSingleIndexedComponent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSingleIndexedComponent_Helper,
           classname: "DmeSingleIndexedComponent",
           pFactory: &g_CDmeSingleIndexedComponent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005AF9A0
// Name: _dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSingleIndexedComponent_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005AF9B0
// Name: _dynamic_atexit_destructor_for__g_CDmeComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeComponent_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeComponent_Factory.m_CallBackList);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005ABEC0
// Name: public: virtual int CDmeSingleIndexedComponent::Count(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSingleIndexedComponent::Count(CDmeSingleIndexedComponent *this)
{
  if ( this->m_bComplete.m_Storage )
    return this->m_CompleteCount.m_Storage;
  else
    return this->m_Components.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x005ABED0
// Name: public: bool CDmeSingleIndexedComponent::GetComponent(int,int __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSingleIndexedComponent::GetComponent(
        CDmeSingleIndexedComponent *this,
        int index,
        int *component,
        float *weight)
{
  if ( index >= this->Count(this) )
    return 0;
  if ( this->m_bComplete.m_Storage )
  {
    *component = index;
    *weight = 1.0;
  }
  else
  {
    *component = this->m_Components.m_Storage.m_Memory.m_pMemory[index];
    *weight = this->m_Weights.m_Storage.m_Memory.m_pMemory[index];
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005ABFC0
// Name: public: virtual bool CDmeComponent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeComponent::IsA(CDmeComponent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005ABFF0
// Name: public: virtual int CDmeComponent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeComponent::GetInheritanceDepth(CDmeComponent *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AC030
// Name: public: virtual void CDmeComponent::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeComponent::Clear(CDmeComponent *this)
{
  CDmAttribute *m_pAttribute; // ecx
  bool value; // [esp+1h] [ebp-1h] BYREF

  value = HIBYTE(this);
  m_pAttribute = this->m_bComplete.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005AC0B0
// Name: protected: virtual void CDmeComponent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeComponent::PerformConstruction(CDmeComponent *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-8h] BYREF
  bool v5; // [esp+Fh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  value = -1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "componentType", type: AT_INT, pMemory: &this->m_Type);
  this->m_Type.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  v5 = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "complete", type: AT_BOOL, pMemory: &this->m_bComplete);
  this->m_bComplete.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, value: &v5);
}

//------------------------------------------------------------------------------
// Address: 0x005AC110
// Name: public: virtual bool CDmeComponent::IsEqual(class CDmeComponent const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeComponent::IsEqual(CDmeComponent *this, CDmeComponent *pRhs)
{
  unsigned int m_Storage; // eax
  unsigned int v4; // ecx
  int v5; // ebx
  BOOL result; // eax

  m_Storage = this->m_Type.m_Storage;
  if ( m_Storage > 1 )
    m_Storage = -1;
  v4 = pRhs->m_Type.m_Storage;
  if ( v4 > 1 )
    v4 = -1;
  result = false;
  if ( m_Storage == v4 )
  {
    v5 = pRhs->Count(this: pRhs);
    if ( this->Count(this) == v5 && this->m_bComplete.m_Storage == pRhs->m_bComplete.m_Storage )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AC1D0
// Name: public: virtual bool CDmeSingleIndexedComponent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSingleIndexedComponent::IsA(CDmeSingleIndexedComponent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSingleIndexedComponent::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AC200
// Name: public: virtual int CDmeSingleIndexedComponent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSingleIndexedComponent::GetInheritanceDepth(
        CDmeSingleIndexedComponent *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSingleIndexedComponent::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AC260
// Name: public: virtual void CDmeSingleIndexedComponent::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::Clear(CDmeSingleIndexedComponent *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  int v4; // [esp+4h] [ebp-8h] BYREF
  bool value; // [esp+Bh] [ebp-1h] BYREF

  m_pAttribute = this->m_bComplete.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
  v3 = this->m_CompleteCount.m_pAttribute;
  v4 = 0;
  CDmAttribute::SetValue<int>(this: v3, value: &v4);
  CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::RemoveAll(this: &this->m_Components);
  CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::RemoveAll(this: &this->m_Weights);
}

//------------------------------------------------------------------------------
// Address: 0x005AC2B0
// Name: protected: virtual void CDmeSingleIndexedComponent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::PerformConstruction(CDmeSingleIndexedComponent *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  int value; // [esp+8h] [ebp-8h] BYREF
  bool v6; // [esp+Fh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  value = -1;
  v2 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "componentType",
         type: AT_INT,
         pMemory: &this->CDmeComponent::m_Type);
  this->CDmeComponent::m_Type.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  v6 = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "complete", type: AT_BOOL, pMemory: &this->m_bComplete);
  this->m_bComplete.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, value: &v6);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "completeCount",
         type: AT_INT,
         pMemory: &this->m_CompleteCount);
  this->m_CompleteCount.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, &value);
  CDmaDecorator<int,CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &this->m_Components,
    pOwner: this,
    pAttributeName: "components",
    nFlags: 0);
  CDmaDecorator<float,CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &this->m_Weights,
    pOwner: this,
    pAttributeName: "weights",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0067EE10
// Name: _dynamic_initializer_for__CDmeComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeComponent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeComponent::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeComponent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067EE70
// Name: _dynamic_initializer_for__CDmeSingleIndexedComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSingleIndexedComponent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSingleIndexedComponent::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSingleIndexedComponent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00682850
// Name: _dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeComponent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00682860
// Name: _dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSingleIndexedComponent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067EE40
// Name: _dynamic_initializer_for__g_CDmeComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeComponent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeComponent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067EE50
// Name: _dynamic_initializer_for__g_CDmeComponent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeComponent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeComponent_Helper,
           classname: "DmeComponent",
           pFactory: &g_CDmeComponent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067EEA0
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSingleIndexedComponent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067EEB0
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSingleIndexedComponent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSingleIndexedComponent_Helper,
           classname: "DmeSingleIndexedComponent",
           pFactory: &g_CDmeSingleIndexedComponent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00682870
// Name: _dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSingleIndexedComponent_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00682880
// Name: _dynamic_atexit_destructor_for__g_CDmeComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeComponent_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeComponent_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x1059A0C0
// Name: public: virtual int CDmeSingleIndexedComponent::Count(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSingleIndexedComponent::Count(CDmeSingleIndexedComponent *this)
{
  if ( this->m_bComplete.m_Storage )
    return this->m_CompleteCount.m_Storage;
  else
    return this->m_Components.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x1059A0D0
// Name: public: bool CDmeSingleIndexedComponent::GetComponent(int,int __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSingleIndexedComponent::GetComponent(
        CDmeSingleIndexedComponent *this,
        int index,
        int *component,
        float *weight)
{
  if ( index >= this->Count(this) )
    return 0;
  if ( this->m_bComplete.m_Storage )
  {
    *component = index;
    *weight = 1.0;
  }
  else
  {
    *component = this->m_Components.m_Storage.m_Memory.m_pMemory[index];
    *weight = this->m_Weights.m_Storage.m_Memory.m_pMemory[index];
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1059A1C0
// Name: public: virtual bool CDmeComponent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeComponent::IsA(CDmeComponent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x1059A1F0
// Name: public: virtual int CDmeComponent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeComponent::GetInheritanceDepth(CDmeComponent *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1059A230
// Name: public: virtual void CDmeComponent::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeComponent::Clear(CDmeComponent *this)
{
  CDmAttribute *m_pAttribute; // ecx
  bool v2; // [esp+1h] [ebp-1h] BYREF

  v2 = HIBYTE(this);
  m_pAttribute = this->m_bComplete.m_pAttribute;
  v2 = false;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, value: &v2);
}

//------------------------------------------------------------------------------
// Address: 0x1059A2B0
// Name: protected: virtual void CDmeComponent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeComponent::PerformConstruction(CDmeComponent *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-8h] BYREF
  bool v5; // [esp+Fh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  value = -1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "componentType", type: AT_INT, pMemory: &this->m_Type);
  this->m_Type.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  v5 = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "complete", type: AT_BOOL, pMemory: &this->m_bComplete);
  this->m_bComplete.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, value: &v5);
}

//------------------------------------------------------------------------------
// Address: 0x1059A310
// Name: public: virtual bool CDmeComponent::IsEqual(class CDmeComponent const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeComponent::IsEqual(CDmeComponent *this, CDmeComponent *pRhs)
{
  unsigned int m_Storage; // eax
  unsigned int v4; // ecx
  int v5; // ebx
  BOOL result; // eax

  m_Storage = this->m_Type.m_Storage;
  if ( m_Storage > 1 )
    m_Storage = -1;
  v4 = pRhs->m_Type.m_Storage;
  if ( v4 > 1 )
    v4 = -1;
  result = false;
  if ( m_Storage == v4 )
  {
    v5 = pRhs->Count(this: pRhs);
    if ( this->Count(this) == v5 && this->m_bComplete.m_Storage == pRhs->m_bComplete.m_Storage )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1059A3D0
// Name: public: virtual bool CDmeSingleIndexedComponent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSingleIndexedComponent::IsA(CDmeSingleIndexedComponent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSingleIndexedComponent::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x1059A400
// Name: public: virtual int CDmeSingleIndexedComponent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSingleIndexedComponent::GetInheritanceDepth(
        CDmeSingleIndexedComponent *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSingleIndexedComponent::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1059A460
// Name: public: virtual void CDmeSingleIndexedComponent::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::Clear(CDmeSingleIndexedComponent *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  int v4; // [esp+4h] [ebp-8h] BYREF
  bool value; // [esp+Bh] [ebp-1h] BYREF

  m_pAttribute = this->m_bComplete.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
  v3 = this->m_CompleteCount.m_pAttribute;
  v4 = 0;
  CDmAttribute::SetValue<int>(this: v3, value: &v4);
  CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::RemoveAll(this: &this->m_Components);
  CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::RemoveAll(this: &this->m_Weights);
}

//------------------------------------------------------------------------------
// Address: 0x1059A4B0
// Name: protected: virtual void CDmeSingleIndexedComponent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::PerformConstruction(CDmeSingleIndexedComponent *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  int value; // [esp+8h] [ebp-8h] BYREF
  bool v6; // [esp+Fh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction((vgui::ToolWindow *)this);
  value = -1;
  v2 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "componentType",
         type: AT_INT,
         pMemory: &this->CDmeComponent::m_Type);
  this->CDmeComponent::m_Type.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  v6 = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "complete", type: AT_BOOL, pMemory: &this->m_bComplete);
  this->m_bComplete.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, value: &v6);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "completeCount",
         type: AT_INT,
         pMemory: &this->m_CompleteCount);
  this->m_CompleteCount.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, &value);
  CDmaDecorator<int,CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &this->m_Components,
    pOwner: this,
    pAttributeName: "components",
    nFlags: 0);
  CDmaDecorator<float,CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &this->m_Weights,
    pOwner: this,
    pAttributeName: "weights",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x105C9CC0
// Name: _dynamic_initializer_for__CDmeComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeComponent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeComponent::s_Allocator,
    blockSize: 0x54u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeComponent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9D20
// Name: _dynamic_initializer_for__CDmeSingleIndexedComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSingleIndexedComponent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSingleIndexedComponent::s_Allocator,
    blockSize: 0x8Cu,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSingleIndexedComponent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CDC90
// Name: _dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeComponent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CDCA0
// Name: _dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSingleIndexedComponent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C9CF0
// Name: _dynamic_initializer_for__g_CDmeComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeComponent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeComponent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9D00
// Name: _dynamic_initializer_for__g_CDmeComponent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeComponent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeComponent_Helper,
           classname: "DmeComponent",
           pFactory: &g_CDmeComponent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C9D50
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSingleIndexedComponent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C9D60
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSingleIndexedComponent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSingleIndexedComponent_Helper,
           classname: "DmeSingleIndexedComponent",
           pFactory: &g_CDmeSingleIndexedComponent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CDCB0
// Name: _dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeSingleIndexedComponent_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CDCC0
// Name: _dynamic_atexit_destructor_for__g_CDmeComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeComponent_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeComponent_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0055CF90
// Name: public: virtual int CDmeSingleIndexedComponent::Count(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSingleIndexedComponent::Count(CDmeSingleIndexedComponent *this)
{
  if ( this->m_bComplete.m_Storage )
    return this->m_CompleteCount.m_Storage;
  else
    return this->m_Components.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0055CFA0
// Name: public: bool CDmeSingleIndexedComponent::GetComponent(int,int __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSingleIndexedComponent::GetComponent(
        CDmeSingleIndexedComponent *this,
        int index,
        int *component,
        float *weight)
{
  if ( index >= this->Count(this) )
    return 0;
  if ( this->m_bComplete.m_Storage )
  {
    *component = index;
    *weight = 1.0;
  }
  else
  {
    *component = this->m_Components.m_Storage.m_Memory.m_pMemory[index];
    *weight = this->m_Weights.m_Storage.m_Memory.m_pMemory[index];
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0055D090
// Name: public: virtual bool CDmeComponent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeComponent::IsA(CDmeComponent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055D0C0
// Name: public: virtual int CDmeComponent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeComponent::GetInheritanceDepth(CDmeComponent *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055D100
// Name: public: virtual void CDmeComponent::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeComponent::Clear(CDmeComponent *this)
{
  CDmAttribute *m_pAttribute; // ecx
  bool value; // [esp+1h] [ebp-1h] BYREF

  value = HIBYTE(this);
  m_pAttribute = this->m_bComplete.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0055D180
// Name: protected: virtual void CDmeComponent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeComponent::PerformConstruction(CDmeComponent *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-8h] BYREF
  bool v5; // [esp+Fh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction();
  value = -1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "componentType", type: AT_INT, pMemory: &this->m_Type);
  this->m_Type.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  v5 = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "complete", type: AT_BOOL, pMemory: &this->m_bComplete);
  this->m_bComplete.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, value: &v5);
}

//------------------------------------------------------------------------------
// Address: 0x0055D1E0
// Name: public: virtual bool CDmeComponent::IsEqual(class CDmeComponent const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeComponent::IsEqual(CDmeComponent *this, CDmeComponent *pRhs)
{
  unsigned int m_Storage; // eax
  unsigned int v4; // ecx
  int v5; // ebx
  BOOL result; // eax

  m_Storage = this->m_Type.m_Storage;
  if ( m_Storage > 1 )
    m_Storage = -1;
  v4 = pRhs->m_Type.m_Storage;
  if ( v4 > 1 )
    v4 = -1;
  result = false;
  if ( m_Storage == v4 )
  {
    v5 = pRhs->Count(this: pRhs);
    if ( this->Count(this) == v5 && this->m_bComplete.m_Storage == pRhs->m_bComplete.m_Storage )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0055D2A0
// Name: public: virtual bool CDmeSingleIndexedComponent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSingleIndexedComponent::IsA(CDmeSingleIndexedComponent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSingleIndexedComponent::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055D2D0
// Name: public: virtual int CDmeSingleIndexedComponent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSingleIndexedComponent::GetInheritanceDepth(
        CDmeSingleIndexedComponent *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSingleIndexedComponent::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0055D320
// Name: public: virtual void CDmeSingleIndexedComponent::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::Clear(CDmeSingleIndexedComponent *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  int v4; // [esp+4h] [ebp-8h] BYREF
  bool value; // [esp+Bh] [ebp-1h] BYREF

  m_pAttribute = this->m_bComplete.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
  v3 = this->m_CompleteCount.m_pAttribute;
  v4 = 0;
  CDmAttribute::SetValue<int>(this: v3, value: &v4);
  CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::RemoveAll(this: &this->m_Components);
  CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::RemoveAll(this: &this->m_Weights);
}

//------------------------------------------------------------------------------
// Address: 0x0055D370
// Name: protected: virtual void CDmeSingleIndexedComponent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::PerformConstruction(CDmeSingleIndexedComponent *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  int value; // [esp+8h] [ebp-8h] BYREF
  bool v6; // [esp+Fh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction();
  value = -1;
  v2 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "componentType",
         type: AT_INT,
         pMemory: &this->CDmeComponent::m_Type);
  this->CDmeComponent::m_Type.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  v6 = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "complete", type: AT_BOOL, pMemory: &this->m_bComplete);
  this->m_bComplete.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, value: &v6);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "completeCount",
         type: AT_INT,
         pMemory: &this->m_CompleteCount);
  this->m_CompleteCount.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, &value);
  CDmaDecorator<int,CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &this->m_Components,
    pOwner: this,
    pAttributeName: "components",
    nFlags: 0);
  CDmaDecorator<float,CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &this->m_Weights,
    pOwner: this,
    pAttributeName: "weights",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0059C840
// Name: _dynamic_initializer_for__CDmeComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeComponent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeComponent::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeComponent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059C8A0
// Name: _dynamic_initializer_for__CDmeSingleIndexedComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSingleIndexedComponent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSingleIndexedComponent::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSingleIndexedComponent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059F530
// Name: _dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeComponent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059F540
// Name: _dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSingleIndexedComponent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059C870
// Name: _dynamic_initializer_for__g_CDmeComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeComponent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeComponent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059C880
// Name: _dynamic_initializer_for__g_CDmeComponent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeComponent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeComponent_Helper,
           classname: "DmeComponent",
           pFactory: &g_CDmeComponent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059C8D0
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSingleIndexedComponent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059C8E0
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSingleIndexedComponent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSingleIndexedComponent_Helper,
           classname: "DmeSingleIndexedComponent",
           pFactory: &g_CDmeSingleIndexedComponent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059F550
// Name: _dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSingleIndexedComponent_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059F560
// Name: _dynamic_atexit_destructor_for__g_CDmeComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeComponent_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeComponent_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005AAE10
// Name: public: virtual int CDmeSingleIndexedComponent::Count(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSingleIndexedComponent::Count(CDmeSingleIndexedComponent *this)
{
  if ( this->m_bComplete.m_Storage )
    return this->m_CompleteCount.m_Storage;
  else
    return this->m_Components.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x005AAE20
// Name: public: bool CDmeSingleIndexedComponent::GetComponent(int,int __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSingleIndexedComponent::GetComponent(
        CDmeSingleIndexedComponent *this,
        int index,
        int *component,
        float *weight)
{
  if ( index >= this->Count(this) )
    return 0;
  if ( this->m_bComplete.m_Storage )
  {
    *component = index;
    *weight = 1.0;
  }
  else
  {
    *component = this->m_Components.m_Storage.m_Memory.m_pMemory[index];
    *weight = this->m_Weights.m_Storage.m_Memory.m_pMemory[index];
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005AAF10
// Name: public: virtual bool CDmeComponent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeComponent::IsA(CDmeComponent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AAF40
// Name: public: virtual int CDmeComponent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeComponent::GetInheritanceDepth(CDmeComponent *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AAF80
// Name: public: virtual void CDmeComponent::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeComponent::Clear(CDmeComponent *this)
{
  CDmAttribute *m_pAttribute; // ecx
  bool value; // [esp+1h] [ebp-1h] BYREF

  value = HIBYTE(this);
  m_pAttribute = this->m_bComplete.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005AB000
// Name: protected: virtual void CDmeComponent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeComponent::PerformConstruction(CDmeComponent *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-8h] BYREF
  bool v5; // [esp+Fh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction();
  value = -1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "componentType", type: AT_INT, pMemory: &this->m_Type);
  this->m_Type.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  v5 = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "complete", type: AT_BOOL, pMemory: &this->m_bComplete);
  this->m_bComplete.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, value: &v5);
}

//------------------------------------------------------------------------------
// Address: 0x005AB060
// Name: public: virtual bool CDmeComponent::IsEqual(class CDmeComponent const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeComponent::IsEqual(CDmeComponent *this, CDmeComponent *pRhs)
{
  unsigned int m_Storage; // eax
  unsigned int v4; // ecx
  int v5; // ebx
  BOOL result; // eax

  m_Storage = this->m_Type.m_Storage;
  if ( m_Storage > 1 )
    m_Storage = -1;
  v4 = pRhs->m_Type.m_Storage;
  if ( v4 > 1 )
    v4 = -1;
  result = false;
  if ( m_Storage == v4 )
  {
    v5 = pRhs->Count(this: pRhs);
    if ( this->Count(this) == v5 && this->m_bComplete.m_Storage == pRhs->m_bComplete.m_Storage )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AB120
// Name: public: virtual bool CDmeSingleIndexedComponent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSingleIndexedComponent::IsA(CDmeSingleIndexedComponent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSingleIndexedComponent::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AB150
// Name: public: virtual int CDmeSingleIndexedComponent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSingleIndexedComponent::GetInheritanceDepth(
        CDmeSingleIndexedComponent *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSingleIndexedComponent::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005AB1B0
// Name: public: virtual void CDmeSingleIndexedComponent::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::Clear(CDmeSingleIndexedComponent *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  int v4; // [esp+4h] [ebp-8h] BYREF
  bool value; // [esp+Bh] [ebp-1h] BYREF

  m_pAttribute = this->m_bComplete.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
  v3 = this->m_CompleteCount.m_pAttribute;
  v4 = 0;
  CDmAttribute::SetValue<int>(this: v3, value: &v4);
  CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::RemoveAll(this: &this->m_Components);
  CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::RemoveAll(this: &this->m_Weights);
}

//------------------------------------------------------------------------------
// Address: 0x005AB200
// Name: protected: virtual void CDmeSingleIndexedComponent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::PerformConstruction(CDmeSingleIndexedComponent *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  int value; // [esp+8h] [ebp-8h] BYREF
  bool v6; // [esp+Fh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction();
  value = -1;
  v2 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "componentType",
         type: AT_INT,
         pMemory: &this->CDmeComponent::m_Type);
  this->CDmeComponent::m_Type.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  v6 = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "complete", type: AT_BOOL, pMemory: &this->m_bComplete);
  this->m_bComplete.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, value: &v6);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "completeCount",
         type: AT_INT,
         pMemory: &this->m_CompleteCount);
  this->m_CompleteCount.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, &value);
  CDmaDecorator<int,CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &this->m_Components,
    pOwner: this,
    pAttributeName: "components",
    nFlags: 0);
  CDmaDecorator<float,CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &this->m_Weights,
    pOwner: this,
    pAttributeName: "weights",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x005F1890
// Name: _dynamic_initializer_for__CDmeComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeComponent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeComponent::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeComponent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F18F0
// Name: _dynamic_initializer_for__CDmeSingleIndexedComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSingleIndexedComponent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSingleIndexedComponent::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSingleIndexedComponent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F4980
// Name: _dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeComponent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F4990
// Name: _dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSingleIndexedComponent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F18C0
// Name: _dynamic_initializer_for__g_CDmeComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeComponent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeComponent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F18D0
// Name: _dynamic_initializer_for__g_CDmeComponent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeComponent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeComponent_Helper,
           classname: "DmeComponent",
           pFactory: &g_CDmeComponent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F1920
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSingleIndexedComponent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F1930
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSingleIndexedComponent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSingleIndexedComponent_Helper,
           classname: "DmeSingleIndexedComponent",
           pFactory: &g_CDmeSingleIndexedComponent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F49A0
// Name: _dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSingleIndexedComponent_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F49B0
// Name: _dynamic_atexit_destructor_for__g_CDmeComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeComponent_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeComponent_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00516A90
// Name: public: virtual int CDmeSingleIndexedComponent::Count(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSingleIndexedComponent::Count(CDmeSingleIndexedComponent *this)
{
  if ( this->m_bComplete.m_Storage )
    return this->m_CompleteCount.m_Storage;
  else
    return this->m_Components.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00516AA0
// Name: public: bool CDmeSingleIndexedComponent::GetComponent(int,int __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSingleIndexedComponent::GetComponent(
        CDmeSingleIndexedComponent *this,
        int index,
        int *component,
        float *weight)
{
  if ( index >= this->Count(this) )
    return 0;
  if ( this->m_bComplete.m_Storage )
  {
    *component = index;
    *weight = 1.0;
  }
  else
  {
    *component = this->m_Components.m_Storage.m_Memory.m_pMemory[index];
    *weight = this->m_Weights.m_Storage.m_Memory.m_pMemory[index];
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00516B90
// Name: public: virtual bool CDmeComponent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeComponent::IsA(CDmeComponent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00516BC0
// Name: public: virtual int CDmeComponent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeComponent::GetInheritanceDepth(CDmeComponent *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00516C00
// Name: public: virtual void CDmeComponent::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeComponent::Clear(CDmeComponent *this)
{
  CDmAttribute *m_pAttribute; // ecx
  bool value; // [esp+1h] [ebp-1h] BYREF

  value = HIBYTE(this);
  m_pAttribute = this->m_bComplete.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00516C80
// Name: protected: virtual void CDmeComponent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeComponent::PerformConstruction(CDmeComponent *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-8h] BYREF
  bool v5; // [esp+Fh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction();
  value = -1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "componentType", type: AT_INT, pMemory: &this->m_Type);
  this->m_Type.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  v5 = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "complete", type: AT_BOOL, pMemory: &this->m_bComplete);
  this->m_bComplete.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, value: &v5);
}

//------------------------------------------------------------------------------
// Address: 0x00516CE0
// Name: public: virtual bool CDmeComponent::IsEqual(class CDmeComponent const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeComponent::IsEqual(CDmeComponent *this, CDmeComponent *pRhs)
{
  unsigned int m_Storage; // eax
  unsigned int v4; // ecx
  int v5; // ebx
  BOOL result; // eax

  m_Storage = this->m_Type.m_Storage;
  if ( m_Storage > 1 )
    m_Storage = -1;
  v4 = pRhs->m_Type.m_Storage;
  if ( v4 > 1 )
    v4 = -1;
  result = false;
  if ( m_Storage == v4 )
  {
    v5 = pRhs->Count(this: pRhs);
    if ( this->Count(this) == v5 && this->m_bComplete.m_Storage == pRhs->m_bComplete.m_Storage )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00516DA0
// Name: public: virtual bool CDmeSingleIndexedComponent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSingleIndexedComponent::IsA(CDmeSingleIndexedComponent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSingleIndexedComponent::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00516DD0
// Name: public: virtual int CDmeSingleIndexedComponent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSingleIndexedComponent::GetInheritanceDepth(
        CDmeSingleIndexedComponent *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSingleIndexedComponent::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00516E30
// Name: public: virtual void CDmeSingleIndexedComponent::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::Clear(CDmeSingleIndexedComponent *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  int v4; // [esp+4h] [ebp-8h] BYREF
  bool value; // [esp+Bh] [ebp-1h] BYREF

  m_pAttribute = this->m_bComplete.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
  v3 = this->m_CompleteCount.m_pAttribute;
  v4 = 0;
  CDmAttribute::SetValue<int>(this: v3, value: &v4);
  CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::RemoveAll(this: &this->m_Components);
  CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::RemoveAll(this: &this->m_Weights);
}

//------------------------------------------------------------------------------
// Address: 0x00516E80
// Name: protected: virtual void CDmeSingleIndexedComponent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::PerformConstruction(CDmeSingleIndexedComponent *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  int value; // [esp+8h] [ebp-8h] BYREF
  bool v6; // [esp+Fh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction();
  value = -1;
  v2 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "componentType",
         type: AT_INT,
         pMemory: &this->CDmeComponent::m_Type);
  this->CDmeComponent::m_Type.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  v6 = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "complete", type: AT_BOOL, pMemory: &this->m_bComplete);
  this->m_bComplete.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, value: &v6);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "completeCount",
         type: AT_INT,
         pMemory: &this->m_CompleteCount);
  this->m_CompleteCount.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, &value);
  CDmaDecorator<int,CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &this->m_Components,
    pOwner: this,
    pAttributeName: "components",
    nFlags: 0);
  CDmaDecorator<float,CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &this->m_Weights,
    pOwner: this,
    pAttributeName: "weights",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0056B9F0
// Name: _dynamic_initializer_for__CDmeComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeComponent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeComponent::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeComponent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056BA50
// Name: _dynamic_initializer_for__CDmeSingleIndexedComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSingleIndexedComponent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSingleIndexedComponent::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSingleIndexedComponent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056EA30
// Name: _dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeComponent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056EA40
// Name: _dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSingleIndexedComponent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056BA20
// Name: _dynamic_initializer_for__g_CDmeComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeComponent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeComponent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056BA30
// Name: _dynamic_initializer_for__g_CDmeComponent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeComponent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeComponent_Helper,
           classname: "DmeComponent",
           pFactory: &g_CDmeComponent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056BA80
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSingleIndexedComponent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0056BA90
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSingleIndexedComponent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSingleIndexedComponent_Helper,
           classname: "DmeSingleIndexedComponent",
           pFactory: &g_CDmeSingleIndexedComponent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056EA50
// Name: _dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSingleIndexedComponent_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056EA60
// Name: _dynamic_atexit_destructor_for__g_CDmeComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeComponent_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeComponent_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0051C3F0
// Name: public: virtual int CDmeSingleIndexedComponent::Count(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSingleIndexedComponent::Count(CDmeSingleIndexedComponent *this)
{
  if ( this->m_bComplete.m_Storage )
    return this->m_CompleteCount.m_Storage;
  else
    return this->m_Components.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0051C400
// Name: public: bool CDmeSingleIndexedComponent::GetComponent(int,int __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSingleIndexedComponent::GetComponent(
        CDmeSingleIndexedComponent *this,
        int index,
        int *component,
        float *weight)
{
  if ( index >= this->Count(this) )
    return 0;
  if ( this->m_bComplete.m_Storage )
  {
    *component = index;
    *weight = 1.0;
  }
  else
  {
    *component = this->m_Components.m_Storage.m_Memory.m_pMemory[index];
    *weight = this->m_Weights.m_Storage.m_Memory.m_pMemory[index];
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0051C4F0
// Name: public: virtual bool CDmeComponent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeComponent::IsA(CDmeComponent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051C520
// Name: public: virtual int CDmeComponent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeComponent::GetInheritanceDepth(CDmeComponent *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051C560
// Name: public: virtual void CDmeComponent::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeComponent::Clear(CDmeComponent *this)
{
  CDmAttribute *m_pAttribute; // ecx
  bool value; // [esp+1h] [ebp-1h] BYREF

  value = HIBYTE(this);
  m_pAttribute = this->m_bComplete.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0051C5E0
// Name: protected: virtual void CDmeComponent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeComponent::PerformConstruction(CDmeComponent *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-8h] BYREF
  bool v5; // [esp+Fh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction();
  value = -1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "componentType", type: AT_INT, pMemory: &this->m_Type);
  this->m_Type.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  v5 = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "complete", type: AT_BOOL, pMemory: &this->m_bComplete);
  this->m_bComplete.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, value: &v5);
}

//------------------------------------------------------------------------------
// Address: 0x0051C640
// Name: public: virtual bool CDmeComponent::IsEqual(class CDmeComponent const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeComponent::IsEqual(CDmeComponent *this, CDmeComponent *pRhs)
{
  unsigned int m_Storage; // eax
  unsigned int v4; // ecx
  int v5; // ebx
  BOOL result; // eax

  m_Storage = this->m_Type.m_Storage;
  if ( m_Storage > 1 )
    m_Storage = -1;
  v4 = pRhs->m_Type.m_Storage;
  if ( v4 > 1 )
    v4 = -1;
  result = false;
  if ( m_Storage == v4 )
  {
    v5 = pRhs->Count(this: pRhs);
    if ( this->Count(this) == v5 && this->m_bComplete.m_Storage == pRhs->m_bComplete.m_Storage )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0051C700
// Name: public: virtual bool CDmeSingleIndexedComponent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSingleIndexedComponent::IsA(CDmeSingleIndexedComponent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSingleIndexedComponent::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051C730
// Name: public: virtual int CDmeSingleIndexedComponent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSingleIndexedComponent::GetInheritanceDepth(
        CDmeSingleIndexedComponent *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSingleIndexedComponent::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051C780
// Name: public: virtual void CDmeSingleIndexedComponent::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::Clear(CDmeSingleIndexedComponent *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  int v4; // [esp+4h] [ebp-8h] BYREF
  bool value; // [esp+Bh] [ebp-1h] BYREF

  m_pAttribute = this->m_bComplete.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
  v3 = this->m_CompleteCount.m_pAttribute;
  v4 = 0;
  CDmAttribute::SetValue<int>(this: v3, value: &v4);
  CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::RemoveAll(this: &this->m_Components);
  CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::RemoveAll(this: &this->m_Weights);
}

//------------------------------------------------------------------------------
// Address: 0x0051C7D0
// Name: protected: virtual void CDmeSingleIndexedComponent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::PerformConstruction(CDmeSingleIndexedComponent *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  int value; // [esp+8h] [ebp-8h] BYREF
  bool v6; // [esp+Fh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction();
  value = -1;
  v2 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "componentType",
         type: AT_INT,
         pMemory: &this->CDmeComponent::m_Type);
  this->CDmeComponent::m_Type.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  v6 = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "complete", type: AT_BOOL, pMemory: &this->m_bComplete);
  this->m_bComplete.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, value: &v6);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "completeCount",
         type: AT_INT,
         pMemory: &this->m_CompleteCount);
  this->m_CompleteCount.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, &value);
  CDmaDecorator<int,CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &this->m_Components,
    pOwner: this,
    pAttributeName: "components",
    nFlags: 0);
  CDmaDecorator<float,CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &this->m_Weights,
    pOwner: this,
    pAttributeName: "weights",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0057BB00
// Name: _dynamic_initializer_for__CDmeComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeComponent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeComponent::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeComponent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BB60
// Name: _dynamic_initializer_for__CDmeSingleIndexedComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSingleIndexedComponent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSingleIndexedComponent::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSingleIndexedComponent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057EB60
// Name: _dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeComponent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057EB70
// Name: _dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSingleIndexedComponent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057BB30
// Name: _dynamic_initializer_for__g_CDmeComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeComponent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeComponent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BB40
// Name: _dynamic_initializer_for__g_CDmeComponent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeComponent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeComponent_Helper,
           classname: "DmeComponent",
           pFactory: &g_CDmeComponent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057BB90
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSingleIndexedComponent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057BBA0
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSingleIndexedComponent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSingleIndexedComponent_Helper,
           classname: "DmeSingleIndexedComponent",
           pFactory: &g_CDmeSingleIndexedComponent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057EB80
// Name: _dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSingleIndexedComponent_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057EB90
// Name: _dynamic_atexit_destructor_for__g_CDmeComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeComponent_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeComponent_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005D98C0
// Name: public: virtual int CDmeSingleIndexedComponent::Count(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSingleIndexedComponent::Count(CDmeSingleIndexedComponent *this)
{
  if ( this->m_bComplete.m_Storage )
    return this->m_CompleteCount.m_Storage;
  else
    return this->m_Components.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x005D98D0
// Name: public: bool CDmeSingleIndexedComponent::GetComponent(int,int __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSingleIndexedComponent::GetComponent(
        CDmeSingleIndexedComponent *this,
        int index,
        int *component,
        float *weight)
{
  if ( index >= this->Count(this) )
    return 0;
  if ( this->m_bComplete.m_Storage )
  {
    *component = index;
    *weight = 1.0;
  }
  else
  {
    *component = this->m_Components.m_Storage.m_Memory.m_pMemory[index];
    *weight = this->m_Weights.m_Storage.m_Memory.m_pMemory[index];
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005D9930
// Name: public: bool CDmeSingleIndexedComponent::GetWeight(int,float __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSingleIndexedComponent::GetWeight(CDmeSingleIndexedComponent *this, int component, float *weight)
{
  int v3; // edi
  int v4; // edx
  int *m_pMemory; // ecx
  int v6; // eax
  int v7; // esi
  CDmeSingleIndexedComponent *v9; // [esp+Ch] [ebp-4h]

  v3 = 0;
  v4 = this->m_Components.m_Storage.m_Size - 1;
  v9 = this;
  if ( v4 >= 0 )
  {
    m_pMemory = this->m_Components.m_Storage.m_Memory.m_pMemory;
    while ( 1 )
    {
      v6 = (v4 + v3) >> 1;
      v7 = m_pMemory[v6];
      if ( component <= v7 )
      {
        if ( component >= v7 )
        {
          this = v9;
          goto LABEL_10;
        }
        v4 = v6 - 1;
      }
      else
      {
        v3 = v6 + 1;
      }
      if ( v3 > v4 )
      {
        this = v9;
        break;
      }
    }
  }
  v6 = v3;
LABEL_10:
  if ( v6 >= this->m_Components.m_Storage.m_Size || this->m_Components.m_Storage.m_Memory.m_pMemory[v6] != component )
    return 0;
  *weight = this->m_Weights.m_Storage.m_Memory.m_pMemory[v6];
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005D9A30
// Name: public: virtual bool CDmeComponent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeComponent::IsA(CDmeComponent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D9A60
// Name: public: virtual int CDmeComponent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeComponent::GetInheritanceDepth(CDmeComponent *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D9AA0
// Name: public: virtual void CDmeComponent::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeComponent::Clear(CDmeComponent *this)
{
  CDmAttribute *m_pAttribute; // ecx
  bool value; // [esp+1h] [ebp-1h] BYREF

  value = HIBYTE(this);
  m_pAttribute = this->m_bComplete.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005D9B20
// Name: protected: virtual void CDmeComponent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeComponent::PerformConstruction(CDmeComponent *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-8h] BYREF
  bool v5; // [esp+Fh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  value = -1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "componentType", type: AT_INT, pMemory: &this->m_Type);
  this->m_Type.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  v5 = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "complete", type: AT_BOOL, pMemory: &this->m_bComplete);
  this->m_bComplete.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, value: &v5);
}

//------------------------------------------------------------------------------
// Address: 0x005D9B80
// Name: public: virtual bool CDmeComponent::IsEqual(class CDmeComponent const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeComponent::IsEqual(CDmeComponent *this, CDmeComponent *pRhs)
{
  unsigned int m_Storage; // eax
  unsigned int v4; // ecx
  int v5; // ebx
  BOOL result; // eax

  m_Storage = this->m_Type.m_Storage;
  if ( m_Storage > 1 )
    m_Storage = -1;
  v4 = pRhs->m_Type.m_Storage;
  if ( v4 > 1 )
    v4 = -1;
  result = false;
  if ( m_Storage == v4 )
  {
    v5 = pRhs->Count(this: pRhs);
    if ( this->Count(this) == v5 && this->m_bComplete.m_Storage == pRhs->m_bComplete.m_Storage )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005D9C40
// Name: public: virtual bool CDmeSingleIndexedComponent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSingleIndexedComponent::IsA(CDmeSingleIndexedComponent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSingleIndexedComponent::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D9C70
// Name: public: virtual int CDmeSingleIndexedComponent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSingleIndexedComponent::GetInheritanceDepth(
        CDmeSingleIndexedComponent *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSingleIndexedComponent::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D9CC0
// Name: public: virtual void CDmeSingleIndexedComponent::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::Clear(CDmeSingleIndexedComponent *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  int v4; // [esp+4h] [ebp-8h] BYREF
  bool value; // [esp+Bh] [ebp-1h] BYREF

  m_pAttribute = this->m_bComplete.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
  v3 = this->m_CompleteCount.m_pAttribute;
  v4 = 0;
  CDmAttribute::SetValue<int>(this: v3, value: &v4);
  CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::RemoveAll(this: &this->m_Components);
  CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::RemoveAll(this: &this->m_Weights);
}

//------------------------------------------------------------------------------
// Address: 0x005D9D10
// Name: protected: virtual void CDmeSingleIndexedComponent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::PerformConstruction(CDmeSingleIndexedComponent *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  int value; // [esp+8h] [ebp-8h] BYREF
  bool v6; // [esp+Fh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  value = -1;
  v2 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "componentType",
         type: AT_INT,
         pMemory: &this->CDmeComponent::m_Type);
  this->CDmeComponent::m_Type.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  v6 = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "complete", type: AT_BOOL, pMemory: &this->m_bComplete);
  this->m_bComplete.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, value: &v6);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "completeCount",
         type: AT_INT,
         pMemory: &this->m_CompleteCount);
  this->m_CompleteCount.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, &value);
  CDmaDecorator<int,CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &this->m_Components,
    pOwner: this,
    pAttributeName: "components",
    nFlags: 0);
  CDmaDecorator<float,CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &this->m_Weights,
    pOwner: this,
    pAttributeName: "weights",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x006B0CB0
// Name: _dynamic_initializer_for__CDmeComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeComponent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeComponent::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeComponent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0D10
// Name: _dynamic_initializer_for__CDmeSingleIndexedComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSingleIndexedComponent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSingleIndexedComponent::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSingleIndexedComponent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5370
// Name: _dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeComponent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5380
// Name: _dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSingleIndexedComponent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B0CE0
// Name: _dynamic_initializer_for__g_CDmeComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeComponent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeComponent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0CF0
// Name: _dynamic_initializer_for__g_CDmeComponent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeComponent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeComponent_Helper,
           classname: "DmeComponent",
           pFactory: &g_CDmeComponent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B0D40
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSingleIndexedComponent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0D50
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSingleIndexedComponent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSingleIndexedComponent_Helper,
           classname: "DmeSingleIndexedComponent",
           pFactory: &g_CDmeSingleIndexedComponent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5390
// Name: _dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSingleIndexedComponent_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B53A0
// Name: _dynamic_atexit_destructor_for__g_CDmeComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeComponent_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeComponent_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x0051D4F0
// Name: public: virtual int CDmeSingleIndexedComponent::Count(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSingleIndexedComponent::Count(CDmeSingleIndexedComponent *this)
{
  if ( this->m_bComplete.m_Storage )
    return this->m_CompleteCount.m_Storage;
  else
    return this->m_Components.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0051D500
// Name: public: bool CDmeSingleIndexedComponent::GetComponent(int,int __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSingleIndexedComponent::GetComponent(
        CDmeSingleIndexedComponent *this,
        int index,
        int *component,
        float *weight)
{
  if ( index >= this->Count(this) )
    return 0;
  if ( this->m_bComplete.m_Storage )
  {
    *component = index;
    *weight = 1.0;
  }
  else
  {
    *component = this->m_Components.m_Storage.m_Memory.m_pMemory[index];
    *weight = this->m_Weights.m_Storage.m_Memory.m_pMemory[index];
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0051D5F0
// Name: public: virtual bool CDmeComponent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeComponent::IsA(CDmeComponent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051D620
// Name: public: virtual int CDmeComponent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeComponent::GetInheritanceDepth(CDmeComponent *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051D660
// Name: public: virtual void CDmeComponent::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeComponent::Clear(CDmeComponent *this)
{
  CDmAttribute *m_pAttribute; // ecx
  bool value; // [esp+1h] [ebp-1h] BYREF

  value = HIBYTE(this);
  m_pAttribute = this->m_bComplete.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x0051D6E0
// Name: protected: virtual void CDmeComponent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeComponent::PerformConstruction(CDmeComponent *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-8h] BYREF
  bool v5; // [esp+Fh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction();
  value = -1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "componentType", type: AT_INT, pMemory: &this->m_Type);
  this->m_Type.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  v5 = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "complete", type: AT_BOOL, pMemory: &this->m_bComplete);
  this->m_bComplete.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, value: &v5);
}

//------------------------------------------------------------------------------
// Address: 0x0051D740
// Name: public: virtual bool CDmeComponent::IsEqual(class CDmeComponent const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeComponent::IsEqual(CDmeComponent *this, CDmeComponent *pRhs)
{
  unsigned int m_Storage; // eax
  unsigned int v4; // ecx
  int v5; // ebx
  BOOL result; // eax

  m_Storage = this->m_Type.m_Storage;
  if ( m_Storage > 1 )
    m_Storage = -1;
  v4 = pRhs->m_Type.m_Storage;
  if ( v4 > 1 )
    v4 = -1;
  result = false;
  if ( m_Storage == v4 )
  {
    v5 = pRhs->Count(this: pRhs);
    if ( this->Count(this) == v5 && this->m_bComplete.m_Storage == pRhs->m_bComplete.m_Storage )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0051D800
// Name: public: virtual bool CDmeSingleIndexedComponent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSingleIndexedComponent::IsA(CDmeSingleIndexedComponent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSingleIndexedComponent::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051D830
// Name: public: virtual int CDmeSingleIndexedComponent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSingleIndexedComponent::GetInheritanceDepth(
        CDmeSingleIndexedComponent *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSingleIndexedComponent::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0051D880
// Name: public: virtual void CDmeSingleIndexedComponent::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::Clear(CDmeSingleIndexedComponent *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  int v4; // [esp+4h] [ebp-8h] BYREF
  bool value; // [esp+Bh] [ebp-1h] BYREF

  m_pAttribute = this->m_bComplete.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
  v3 = this->m_CompleteCount.m_pAttribute;
  v4 = 0;
  CDmAttribute::SetValue<int>(this: v3, value: &v4);
  CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::RemoveAll(this: &this->m_Components);
  CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::RemoveAll(this: &this->m_Weights);
}

//------------------------------------------------------------------------------
// Address: 0x0051D8D0
// Name: protected: virtual void CDmeSingleIndexedComponent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::PerformConstruction(CDmeSingleIndexedComponent *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  int value; // [esp+8h] [ebp-8h] BYREF
  bool v6; // [esp+Fh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction();
  value = -1;
  v2 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "componentType",
         type: AT_INT,
         pMemory: &this->CDmeComponent::m_Type);
  this->CDmeComponent::m_Type.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  v6 = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "complete", type: AT_BOOL, pMemory: &this->m_bComplete);
  this->m_bComplete.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, value: &v6);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "completeCount",
         type: AT_INT,
         pMemory: &this->m_CompleteCount);
  this->m_CompleteCount.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, &value);
  CDmaDecorator<int,CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &this->m_Components,
    pOwner: this,
    pAttributeName: "components",
    nFlags: 0);
  CDmaDecorator<float,CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &this->m_Weights,
    pOwner: this,
    pAttributeName: "weights",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0057DAE0
// Name: _dynamic_initializer_for__CDmeComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeComponent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeComponent::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeComponent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DB40
// Name: _dynamic_initializer_for__CDmeSingleIndexedComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSingleIndexedComponent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSingleIndexedComponent::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSingleIndexedComponent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00580B40
// Name: _dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeComponent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580B50
// Name: _dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSingleIndexedComponent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057DB10
// Name: _dynamic_initializer_for__g_CDmeComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeComponent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeComponent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DB20
// Name: _dynamic_initializer_for__g_CDmeComponent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeComponent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeComponent_Helper,
           classname: "DmeComponent",
           pFactory: &g_CDmeComponent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057DB70
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSingleIndexedComponent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057DB80
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSingleIndexedComponent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSingleIndexedComponent_Helper,
           classname: "DmeSingleIndexedComponent",
           pFactory: &g_CDmeSingleIndexedComponent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00580B60
// Name: _dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSingleIndexedComponent_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00580B70
// Name: _dynamic_atexit_destructor_for__g_CDmeComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeComponent_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeComponent_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005A3D50
// Name: public: virtual int CDmeSingleIndexedComponent::Count(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSingleIndexedComponent::Count(CDmeSingleIndexedComponent *this)
{
  if ( this->m_bComplete.m_Storage )
    return this->m_CompleteCount.m_Storage;
  else
    return this->m_Components.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x005A3D60
// Name: public: bool CDmeSingleIndexedComponent::GetComponent(int,int __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSingleIndexedComponent::GetComponent(
        CDmeSingleIndexedComponent *this,
        int index,
        int *component,
        float *weight)
{
  if ( index >= this->Count(this) )
    return 0;
  if ( this->m_bComplete.m_Storage )
  {
    *component = index;
    *weight = 1.0;
  }
  else
  {
    *component = this->m_Components.m_Storage.m_Memory.m_pMemory[index];
    *weight = this->m_Weights.m_Storage.m_Memory.m_pMemory[index];
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005A3E50
// Name: public: virtual bool CDmeComponent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeComponent::IsA(CDmeComponent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A3E80
// Name: public: virtual int CDmeComponent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeComponent::GetInheritanceDepth(CDmeComponent *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A3EC0
// Name: public: virtual void CDmeComponent::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeComponent::Clear(CDmeComponent *this)
{
  CDmAttribute *m_pAttribute; // ecx
  bool value; // [esp+1h] [ebp-1h] BYREF

  value = HIBYTE(this);
  m_pAttribute = this->m_bComplete.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x005A3F40
// Name: protected: virtual void CDmeComponent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeComponent::PerformConstruction(CDmeComponent *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-8h] BYREF
  bool v5; // [esp+Fh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction();
  value = -1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "componentType", type: AT_INT, pMemory: &this->m_Type);
  this->m_Type.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  v5 = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "complete", type: AT_BOOL, pMemory: &this->m_bComplete);
  this->m_bComplete.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, value: &v5);
}

//------------------------------------------------------------------------------
// Address: 0x005A3FA0
// Name: public: virtual bool CDmeComponent::IsEqual(class CDmeComponent const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeComponent::IsEqual(CDmeComponent *this, CDmeComponent *pRhs)
{
  unsigned int m_Storage; // eax
  unsigned int v4; // ecx
  int v5; // ebx
  BOOL result; // eax

  m_Storage = this->m_Type.m_Storage;
  if ( m_Storage > 1 )
    m_Storage = -1;
  v4 = pRhs->m_Type.m_Storage;
  if ( v4 > 1 )
    v4 = -1;
  result = false;
  if ( m_Storage == v4 )
  {
    v5 = pRhs->Count(this: pRhs);
    if ( this->Count(this) == v5 && this->m_bComplete.m_Storage == pRhs->m_bComplete.m_Storage )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A4060
// Name: public: virtual bool CDmeSingleIndexedComponent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSingleIndexedComponent::IsA(CDmeSingleIndexedComponent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSingleIndexedComponent::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A4090
// Name: public: virtual int CDmeSingleIndexedComponent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSingleIndexedComponent::GetInheritanceDepth(
        CDmeSingleIndexedComponent *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSingleIndexedComponent::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005A40E0
// Name: public: virtual void CDmeSingleIndexedComponent::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::Clear(CDmeSingleIndexedComponent *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  int v4; // [esp+4h] [ebp-8h] BYREF
  bool value; // [esp+Bh] [ebp-1h] BYREF

  m_pAttribute = this->m_bComplete.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
  v3 = this->m_CompleteCount.m_pAttribute;
  v4 = 0;
  CDmAttribute::SetValue<int>(this: v3, value: &v4);
  CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::RemoveAll(this: &this->m_Components);
  CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::RemoveAll(this: &this->m_Weights);
}

//------------------------------------------------------------------------------
// Address: 0x005A4130
// Name: protected: virtual void CDmeSingleIndexedComponent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::PerformConstruction(CDmeSingleIndexedComponent *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  int value; // [esp+8h] [ebp-8h] BYREF
  bool v6; // [esp+Fh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction();
  value = -1;
  v2 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "componentType",
         type: AT_INT,
         pMemory: &this->CDmeComponent::m_Type);
  this->CDmeComponent::m_Type.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  v6 = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "complete", type: AT_BOOL, pMemory: &this->m_bComplete);
  this->m_bComplete.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, value: &v6);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "completeCount",
         type: AT_INT,
         pMemory: &this->m_CompleteCount);
  this->m_CompleteCount.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, &value);
  CDmaDecorator<int,CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &this->m_Components,
    pOwner: this,
    pAttributeName: "components",
    nFlags: 0);
  CDmaDecorator<float,CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &this->m_Weights,
    pOwner: this,
    pAttributeName: "weights",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x005EA740
// Name: _dynamic_initializer_for__CDmeComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeComponent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeComponent::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeComponent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005EA7A0
// Name: _dynamic_initializer_for__CDmeSingleIndexedComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSingleIndexedComponent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSingleIndexedComponent::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSingleIndexedComponent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED820
// Name: _dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeComponent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED830
// Name: _dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSingleIndexedComponent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005EA770
// Name: _dynamic_initializer_for__g_CDmeComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeComponent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeComponent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EA780
// Name: _dynamic_initializer_for__g_CDmeComponent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeComponent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeComponent_Helper,
           classname: "DmeComponent",
           pFactory: &g_CDmeComponent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005EA7D0
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSingleIndexedComponent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005EA7E0
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSingleIndexedComponent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSingleIndexedComponent_Helper,
           classname: "DmeSingleIndexedComponent",
           pFactory: &g_CDmeSingleIndexedComponent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED840
// Name: _dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSingleIndexedComponent_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ED850
// Name: _dynamic_atexit_destructor_for__g_CDmeComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeComponent_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeComponent_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00525530
// Name: public: virtual int CDmeSingleIndexedComponent::Count(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSingleIndexedComponent::Count(CDmeSingleIndexedComponent *this)
{
  if ( this->m_bComplete.m_Storage )
    return this->m_CompleteCount.m_Storage;
  else
    return this->m_Components.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00525540
// Name: public: bool CDmeSingleIndexedComponent::GetComponent(int,int __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSingleIndexedComponent::GetComponent(
        CDmeSingleIndexedComponent *this,
        int index,
        int *component,
        float *weight)
{
  if ( index >= this->Count(this) )
    return 0;
  if ( this->m_bComplete.m_Storage )
  {
    *component = index;
    *weight = 1.0;
  }
  else
  {
    *component = this->m_Components.m_Storage.m_Memory.m_pMemory[index];
    *weight = this->m_Weights.m_Storage.m_Memory.m_pMemory[index];
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00525630
// Name: public: virtual bool CDmeComponent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeComponent::IsA(CDmeComponent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00525660
// Name: public: virtual int CDmeComponent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeComponent::GetInheritanceDepth(CDmeComponent *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005256A0
// Name: public: virtual void CDmeComponent::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeComponent::Clear(CDmeComponent *this)
{
  CDmAttribute *m_pAttribute; // ecx
  bool value; // [esp+1h] [ebp-1h] BYREF

  value = HIBYTE(this);
  m_pAttribute = this->m_bComplete.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00525720
// Name: protected: virtual void CDmeComponent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeComponent::PerformConstruction(CDmeComponent *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-8h] BYREF
  bool v5; // [esp+Fh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  value = -1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "componentType", type: AT_INT, pMemory: &this->m_Type);
  this->m_Type.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  v5 = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "complete", type: AT_BOOL, pMemory: &this->m_bComplete);
  this->m_bComplete.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, value: &v5);
}

//------------------------------------------------------------------------------
// Address: 0x00525780
// Name: public: virtual bool CDmeComponent::IsEqual(class CDmeComponent const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeComponent::IsEqual(CDmeComponent *this, CDmeComponent *pRhs)
{
  unsigned int m_Storage; // eax
  unsigned int v4; // ecx
  int v5; // ebx
  BOOL result; // eax

  m_Storage = this->m_Type.m_Storage;
  if ( m_Storage > 1 )
    m_Storage = -1;
  v4 = pRhs->m_Type.m_Storage;
  if ( v4 > 1 )
    v4 = -1;
  result = false;
  if ( m_Storage == v4 )
  {
    v5 = pRhs->Count(this: pRhs);
    if ( this->Count(this) == v5 && this->m_bComplete.m_Storage == pRhs->m_bComplete.m_Storage )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00525840
// Name: public: virtual bool CDmeSingleIndexedComponent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSingleIndexedComponent::IsA(CDmeSingleIndexedComponent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSingleIndexedComponent::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00525870
// Name: public: virtual int CDmeSingleIndexedComponent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSingleIndexedComponent::GetInheritanceDepth(
        CDmeSingleIndexedComponent *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSingleIndexedComponent::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005258C0
// Name: public: virtual void CDmeSingleIndexedComponent::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::Clear(CDmeSingleIndexedComponent *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  int v4; // [esp+4h] [ebp-8h] BYREF
  bool value; // [esp+Bh] [ebp-1h] BYREF

  m_pAttribute = this->m_bComplete.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
  v3 = this->m_CompleteCount.m_pAttribute;
  v4 = 0;
  CDmAttribute::SetValue<int>(this: v3, value: &v4);
  CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::RemoveAll(this: &this->m_Components);
  CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::RemoveAll(this: &this->m_Weights);
}

//------------------------------------------------------------------------------
// Address: 0x00525910
// Name: protected: virtual void CDmeSingleIndexedComponent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::PerformConstruction(CDmeSingleIndexedComponent *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  int value; // [esp+8h] [ebp-8h] BYREF
  bool v6; // [esp+Fh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  value = -1;
  v2 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "componentType",
         type: AT_INT,
         pMemory: &this->CDmeComponent::m_Type);
  this->CDmeComponent::m_Type.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  v6 = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "complete", type: AT_BOOL, pMemory: &this->m_bComplete);
  this->m_bComplete.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, value: &v6);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "completeCount",
         type: AT_INT,
         pMemory: &this->m_CompleteCount);
  this->m_CompleteCount.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, &value);
  CDmaDecorator<int,CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &this->m_Components,
    pOwner: this,
    pAttributeName: "components",
    nFlags: 0);
  CDmaDecorator<float,CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &this->m_Weights,
    pOwner: this,
    pAttributeName: "weights",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0057B390
// Name: _dynamic_initializer_for__CDmeComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeComponent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeComponent::s_Allocator,
    blockSize: 84,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeComponent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B3F0
// Name: _dynamic_initializer_for__CDmeSingleIndexedComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSingleIndexedComponent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSingleIndexedComponent::s_Allocator,
    blockSize: 140,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSingleIndexedComponent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E250
// Name: _dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeComponent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E260
// Name: _dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSingleIndexedComponent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057B3C0
// Name: _dynamic_initializer_for__g_CDmeComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeComponent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeComponent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B3D0
// Name: _dynamic_initializer_for__g_CDmeComponent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeComponent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeComponent_Helper,
           classname: "DmeComponent",
           pFactory: &g_CDmeComponent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057B420
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSingleIndexedComponent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057B430
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSingleIndexedComponent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSingleIndexedComponent_Helper,
           classname: "DmeSingleIndexedComponent",
           pFactory: &g_CDmeSingleIndexedComponent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E270
// Name: _dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSingleIndexedComponent_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E280
// Name: _dynamic_atexit_destructor_for__g_CDmeComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeComponent_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeComponent_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0049A2FF
// Name: public: virtual int D3DXShader::CNode::IsEqual(class D3DXShader::CNode __near *)
// Source: json
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CNode::IsEqual(D3DXShader::CNode *this, struct D3DXShader::CNode *a2)
{
  struct D3DXShader::CNode *result; // eax

  result = a2;
  if ( a2 != nullptr )
    return (struct D3DXShader::CNode *)(*((_DWORD *)this + 1) == *((_DWORD *)a2 + 1));
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049A31A
// Name: public: static int D3DXShader::CNode::IsEqual(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: json
//------------------------------------------------------------------------------
static int __stdcall D3DXShader::CNode::IsEqual(struct D3DXShader::CNode *a1, struct D3DXShader::CNode *a2)
{
  if ( a1 != nullptr )
    return (**(int (__thiscall ***)(struct D3DXShader::CNode *, struct D3DXShader::CNode *))a1)(a1, a2);
  else
    return a2 == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0049A3BF
// Name: public: virtual int D3DXShader::CNodeList::IsEqual(class D3DXShader::CNode __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CNodeList::IsEqual(D3DXShader::CNodeList *this, struct D3DXShader::CNode *a2)
{
  struct D3DXShader::CNode *v2; // esi
  int result; // eax
  int v4; // ecx
  int v5; // edi

  v2 = a2;
  result = (int)D3DXShader::CNode::IsEqual(this, a2);
  if ( result != 0 )
  {
    v5 = v4;
    if ( v4 != 0 )
    {
      while ( *(_DWORD *)(v5 + 4) == 1 )
      {
        if ( v2 == nullptr
          || *((_DWORD *)v2 + 1) != 1
          || D3DXShader::CNode::IsEqual(
               a1: *(struct D3DXShader::CNode **)(v5 + 8),
               a2: *((struct D3DXShader::CNode **)v2 + 2)) == 0 )
        {
          return 0;
        }
        v5 = *(_DWORD *)(v5 + 12);
        v2 = *((struct D3DXShader::CNode **)v2 + 3);
        if ( v5 == 0 )
          return 1;
      }
      if ( D3DXShader::CNode::IsEqual(a1: (struct D3DXShader::CNode *)v5, a2: v2) == 0 )
        return 0;
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049A468
// Name: public: virtual int D3DXShader::CNodeTree::IsEqual(class D3DXShader::CNode __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeTree::IsEqual(struct D3DXShader::CNode **this, struct D3DXShader::CNode **a2)
{
  return D3DXShader::CNode::IsEqual((D3DXShader::CNode *)this, (struct D3DXShader::CNode *)a2) != nullptr
      && *(this + 4) == a2[4]
      && *(this + 5) == a2[5]
      && D3DXShader::CNode::IsEqual(a1: *(this + 2), a2: a2[2]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 3), a2: a2[3]) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0049A5C3
// Name: public: virtual int D3DXShader::CNodeToken::IsEqual(class D3DXShader::CNode __near *)
// Source: json
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CNodeToken::IsEqual(
        D3DXShader::CNodeToken *this,
        struct D3DXShader::CNode *a2)
{
  struct D3DXShader::CNode *result; // eax
  int v3; // ecx

  result = D3DXShader::CNode::IsEqual(this, a2);
  if ( result != nullptr )
    return (struct D3DXShader::CNode *)(sub_49A4B8(a1: v3 + 16) != 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049A63C
// Name: public: virtual int D3DXShader::CNodeProgram::IsEqual(class D3DXShader::CNode __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeProgram::IsEqual(D3DXShader::CNodeProgram *this, struct D3DXShader::CNode *a2)
{
  int v2; // edx
  int v3; // ecx

  return D3DXShader::CNode::IsEqual(this, a2) != nullptr
      && *(_DWORD *)(v3 + 16) == *(_DWORD *)(v2 + 16)
      && *(_DWORD *)(v3 + 20) == *(_DWORD *)(v2 + 20)
      && *(_DWORD *)(v3 + 24) == *(_DWORD *)(v2 + 24)
      && D3DXShader::CNode::IsEqual(
           a1: *(struct D3DXShader::CNode **)(v3 + 28),
           a2: *(struct D3DXShader::CNode **)(v2 + 28)) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0049A6DA
// Name: public: virtual int D3DXShader::CNodeScope::IsEqual(class D3DXShader::CNode __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeScope::IsEqual(struct D3DXShader::CNode **this, struct D3DXShader::CNode **a2)
{
  return D3DXShader::CNode::IsEqual((D3DXShader::CNode *)this, (struct D3DXShader::CNode *)a2) != nullptr
      && *(this + 4) == a2[4]
      && *(this + 5) == a2[5]
      && D3DXShader::CNode::IsEqual(a1: *(this + 6), a2: a2[6]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 7), a2: a2[7]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 8), a2: a2[8]) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0049A7A8
// Name: public: virtual int D3DXShader::CNodeDecl::IsEqual(class D3DXShader::CNode __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeDecl::IsEqual(struct D3DXShader::CNode **this, struct D3DXShader::CNode **a2)
{
  return D3DXShader::CNode::IsEqual((D3DXShader::CNode *)this, (struct D3DXShader::CNode *)a2) != nullptr
      && *(this + 4) == a2[4]
      && *(this + 8) == a2[8]
      && *(this + 9) == a2[9]
      && *(this + 10) == a2[10]
      && *(this + 11) == a2[11]
      && D3DXShader::CNode::IsEqual(a1: *(this + 5), a2: a2[5]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 6), a2: a2[6]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 7), a2: a2[7]) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0049A869
// Name: public: virtual int D3DXShader::CNodeUsage::IsEqual(class D3DXShader::CNode __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeUsage::IsEqual(struct D3DXShader::CNode **this, struct D3DXShader::CNode **a2)
{
  return D3DXShader::CNode::IsEqual((D3DXShader::CNode *)this, (struct D3DXShader::CNode *)a2) != nullptr
      && *(this + 4) == a2[4]
      && D3DXShader::CNode::IsEqual(a1: *(this + 5), a2: a2[5]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 6), a2: a2[6]) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0049A8F2
// Name: public: virtual int D3DXShader::CNodeArray::IsEqual(class D3DXShader::CNode __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeArray::IsEqual(D3DXShader::CNodeArray *this, struct D3DXShader::CNode *a2)
{
  int v2; // edx
  int v3; // ecx

  return D3DXShader::CNode::IsEqual(this, a2) != nullptr
      && *(_DWORD *)(v3 + 20) == *(_DWORD *)(v2 + 20)
      && D3DXShader::CNode::IsEqual(
           a1: *(struct D3DXShader::CNode **)(v3 + 16),
           a2: *(struct D3DXShader::CNode **)(v2 + 16)) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0049A984
// Name: public: virtual int D3DXShader::CNodeType::IsEqual(class D3DXShader::CNode __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeType::IsEqual(D3DXShader::CNodeType *this, struct D3DXShader::CNode *a2)
{
  _DWORD *v2; // edx
  _DWORD *v3; // ecx

  return D3DXShader::CNode::IsEqual(this, a2) != nullptr
      && v3[4] == v2[4]
      && v3[5] == v2[5]
      && v3[6] == v2[6]
      && v3[7] == v2[7]
      && v3[8] == v2[8];
}

//------------------------------------------------------------------------------
// Address: 0x0049AA01
// Name: public: virtual int D3DXShader::CNodeFunction::IsEqual(class D3DXShader::CNode __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeFunction::IsEqual(struct D3DXShader::CNode **this, struct D3DXShader::CNode **a2)
{
  return D3DXShader::CNode::IsEqual((D3DXShader::CNode *)this, (struct D3DXShader::CNode *)a2) != nullptr
      && *(this + 4) == a2[4]
      && *(this + 5) == a2[5]
      && *(this + 6) == a2[6]
      && *(this + 14) == a2[14]
      && *(this + 15) == a2[15]
      && D3DXShader::CNode::IsEqual(a1: *(this + 7), a2: a2[7]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 8), a2: a2[8]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 9), a2: a2[9]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 10), a2: a2[10]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 11), a2: a2[11]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 12), a2: a2[12]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 13), a2: a2[13]) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0049AAF9
// Name: public: virtual int D3DXShader::CNodeVariable::IsEqual(class D3DXShader::CNode __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeVariable::IsEqual(D3DXShader::CNodeVariable *this, struct D3DXShader::CNode *a2)
{
  int v3; // eax
  BOOL result; // eax

  result = false;
  if ( D3DXShader::CNode::IsEqual(this, a2) != nullptr
    && *((_DWORD *)this + 4) == *((_DWORD *)a2 + 4)
    && *((_DWORD *)this + 5) == *((_DWORD *)a2 + 5)
    && *((_DWORD *)this + 6) == *((_DWORD *)a2 + 6)
    && *((_DWORD *)this + 7) == *((_DWORD *)a2 + 7)
    && *((_DWORD *)this + 13) == *((_DWORD *)a2 + 13)
    && D3DXShader::CNode::IsEqual(
         a1: *((struct D3DXShader::CNode **)this + 8),
         a2: *((struct D3DXShader::CNode **)a2 + 8)) != 0
    && D3DXShader::CNode::IsEqual(
         a1: *((struct D3DXShader::CNode **)this + 9),
         a2: *((struct D3DXShader::CNode **)a2 + 9)) != 0
    && D3DXShader::CNode::IsEqual(
         a1: *((struct D3DXShader::CNode **)this + 10),
         a2: *((struct D3DXShader::CNode **)a2 + 10)) != 0
    && D3DXShader::CNode::IsEqual(
         a1: *((struct D3DXShader::CNode **)this + 11),
         a2: *((struct D3DXShader::CNode **)a2 + 11)) != 0
    && D3DXShader::CNode::IsEqual(
         a1: *((struct D3DXShader::CNode **)this + 12),
         a2: *((struct D3DXShader::CNode **)a2 + 12)) != 0 )
  {
    v3 = *((_DWORD *)this + 13);
    if ( v3 == 0 || memcmp(*((const void **)this + 14), *((const void **)a2 + 14), 4 * v3) == 0 )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049ABD6
// Name: public: virtual int D3DXShader::CNodeStatement::IsEqual(class D3DXShader::CNode __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeStatement::IsEqual(struct D3DXShader::CNode **this, struct D3DXShader::CNode **a2)
{
  return D3DXShader::CNode::IsEqual((D3DXShader::CNode *)this, (struct D3DXShader::CNode *)a2) != nullptr
      && *(this + 4) == a2[4]
      && D3DXShader::CNode::IsEqual(a1: *(this + 5), a2: a2[5]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 6), a2: a2[6]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 7), a2: a2[7]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 8), a2: a2[8]) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0049ACC5
// Name: public: virtual int D3DXShader::CNodeExpression::IsEqual(class D3DXShader::CNode __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeExpression::IsEqual(struct D3DXShader::CNode **this, struct D3DXShader::CNode **a2)
{
  return D3DXShader::CNode::IsEqual((D3DXShader::CNode *)this, (struct D3DXShader::CNode *)a2) != nullptr
      && *(this + 5) == a2[5]
      && *(this + 6) == a2[6]
      && *(this + 7) == a2[7]
      && *(this + 10) == a2[10]
      && sub_49A4B8(a1: this + 12) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 4), a2: a2[4]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 8), a2: a2[8]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 9), a2: a2[9]) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0049AE68
// Name: public: virtual int D3DXShader::CNodeValue::IsEqual(class D3DXShader::CNode __near *)
// Source: json
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CNodeValue::IsEqual(
        D3DXShader::CNodeValue *this,
        struct D3DXShader::CNode **a2)
{
  struct D3DXShader::CNode *result; // eax
  int v3; // edx
  struct D3DXShader::CNode *v4; // eax

  result = D3DXShader::CNode::IsEqual(this, (struct D3DXShader::CNode *)a2);
  if ( result != nullptr )
  {
    v4 = *(struct D3DXShader::CNode **)(v3 + 16);
    return (struct D3DXShader::CNode *)(v4 == a2[4]
                                     && (memcmp((const void *)(v3 + 16), a2 + 4, 0x10u) == 0
                                      || v4 == (struct D3DXShader::CNode *)4
                                      && D3DXShader::CNode::IsEqual(
                                           a1: *(struct D3DXShader::CNode **)(v3 + 24),
                                           a2: a2[6]) != 0));
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049AF02
// Name: public: virtual int D3DXShader::CNodeState::IsEqual(class D3DXShader::CNode __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeState::IsEqual(struct D3DXShader::CNode **this, struct D3DXShader::CNode **a2)
{
  return D3DXShader::CNode::IsEqual((D3DXShader::CNode *)this, (struct D3DXShader::CNode *)a2) != nullptr
      && D3DXShader::CNode::IsEqual(a1: *(this + 4), a2: a2[4]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 5), a2: a2[5]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 6), a2: a2[6]) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x0049AFA1
// Name: public: virtual int D3DXShader::CNodeBuffer::IsEqual(class D3DXShader::CNode __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeBuffer::IsEqual(D3DXShader::CNodeBuffer *this, struct D3DXShader::CNode *a2)
{
  return D3DXShader::CNode::IsEqual(this, a2) != nullptr
      && sub_49A4B8(a1: (char *)this + 16) != 0
      && *((_DWORD *)a2 + 12) == *((_DWORD *)this + 12)
      && *((_DWORD *)this + 13) == *((_DWORD *)a2 + 13);
}

//------------------------------------------------------------------------------
// Address: 0x0049B023
// Name: public: virtual int D3DXShader::CNodeRegister::IsEqual(class D3DXShader::CNode __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall D3DXShader::CNodeRegister::IsEqual(struct D3DXShader::CNode **this, struct D3DXShader::CNode **a2)
{
  return D3DXShader::CNode::IsEqual((D3DXShader::CNode *)this, (struct D3DXShader::CNode *)a2) != nullptr
      && D3DXShader::CNode::IsEqual(a1: *(this + 4), a2: a2[4]) != 0
      && D3DXShader::CNode::IsEqual(a1: *(this + 5), a2: a2[5]) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x00628340
// Name: public: virtual int CDmeSingleIndexedComponent::Count(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSingleIndexedComponent::Count(CDmeSingleIndexedComponent *this)
{
  if ( this->m_bComplete.m_Storage )
    return this->m_CompleteCount.m_Storage;
  else
    return this->m_Components.m_Storage.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00628350
// Name: public: bool CDmeSingleIndexedComponent::GetComponent(int,int __near &,float __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeSingleIndexedComponent::GetComponent(
        CDmeSingleIndexedComponent *this,
        int index,
        int *component,
        float *weight)
{
  if ( index >= this->Count(this) )
    return 0;
  if ( this->m_bComplete.m_Storage )
  {
    *component = index;
    *weight = 1.0;
  }
  else
  {
    *component = this->m_Components.m_Storage.m_Memory.m_pMemory[index];
    *weight = this->m_Weights.m_Storage.m_Memory.m_pMemory[index];
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00628440
// Name: public: virtual bool CDmeComponent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeComponent::IsA(CDmeComponent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00628470
// Name: public: virtual int CDmeComponent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeComponent::GetInheritanceDepth(CDmeComponent *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x006284C0
// Name: public: virtual void CDmeComponent::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeComponent::Clear(CDmeComponent *this)
{
  CDmAttribute *m_pAttribute; // ecx
  bool value; // [esp+1h] [ebp-1h] BYREF

  value = HIBYTE(this);
  m_pAttribute = this->m_bComplete.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
}

//------------------------------------------------------------------------------
// Address: 0x00628540
// Name: protected: virtual void CDmeComponent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeComponent::PerformConstruction(CDmeComponent *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  int value; // [esp+8h] [ebp-8h] BYREF
  bool v5; // [esp+Fh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  value = -1;
  v2 = CDmElement::AddExternalAttribute(this, pAttributeName: "componentType", type: AT_INT, pMemory: &this->m_Type);
  this->m_Type.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  v5 = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "complete", type: AT_BOOL, pMemory: &this->m_bComplete);
  this->m_bComplete.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, value: &v5);
}

//------------------------------------------------------------------------------
// Address: 0x006285A0
// Name: public: virtual bool CDmeComponent::IsEqual(class CDmeComponent const __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CDmeComponent::IsEqual(CDmeComponent *this, CDmeComponent *pRhs)
{
  unsigned int m_Storage; // eax
  unsigned int v4; // ecx
  int v5; // ebx
  BOOL result; // eax

  m_Storage = this->m_Type.m_Storage;
  if ( m_Storage > 1 )
    m_Storage = -1;
  v4 = pRhs->m_Type.m_Storage;
  if ( v4 > 1 )
    v4 = -1;
  result = false;
  if ( m_Storage == v4 )
  {
    v5 = pRhs->Count(this: pRhs);
    if ( this->Count(this) == v5 && this->m_bComplete.m_Storage == pRhs->m_bComplete.m_Storage )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00628660
// Name: public: virtual bool CDmeSingleIndexedComponent::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSingleIndexedComponent::IsA(CDmeSingleIndexedComponent *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSingleIndexedComponent::m_classType.u.m_Id
      || typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00628690
// Name: public: virtual int CDmeSingleIndexedComponent::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSingleIndexedComponent::GetInheritanceDepth(
        CDmeSingleIndexedComponent *this,
        CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSingleIndexedComponent::m_classType.u.m_Id )
    return 0;
  if ( typeSymbol.u.m_Id == CDmeComponent::m_classType.u.m_Id )
    return 1;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 2;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x006286E0
// Name: public: virtual void CDmeSingleIndexedComponent::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::Clear(CDmeSingleIndexedComponent *this)
{
  CDmAttribute *m_pAttribute; // ecx
  CDmAttribute *v3; // ecx
  int v4; // [esp+4h] [ebp-8h] BYREF
  bool value; // [esp+Bh] [ebp-1h] BYREF

  m_pAttribute = this->m_bComplete.m_pAttribute;
  value = false;
  CDmAttribute::SetValue<bool>(this: m_pAttribute, &value);
  v3 = this->m_CompleteCount.m_pAttribute;
  v4 = 0;
  CDmAttribute::SetValue<int>(this: v3, value: &v4);
  CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>::RemoveAll(this: &this->m_Components);
  CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>::RemoveAll(this: &this->m_Weights);
}

//------------------------------------------------------------------------------
// Address: 0x00628730
// Name: protected: virtual void CDmeSingleIndexedComponent::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSingleIndexedComponent::PerformConstruction(CDmeSingleIndexedComponent *this)
{
  CDmAttribute *v2; // eax
  CDmAttribute *v3; // eax
  CDmAttribute *v4; // eax
  int value; // [esp+8h] [ebp-8h] BYREF
  bool v6; // [esp+Fh] [ebp-1h] BYREF

  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  value = -1;
  v2 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "componentType",
         type: AT_INT,
         pMemory: &this->CDmeComponent::m_Type);
  this->CDmeComponent::m_Type.m_pAttribute = v2;
  CDmAttribute::SetValue<int>(this: v2, &value);
  v6 = false;
  v3 = CDmElement::AddExternalAttribute(this, pAttributeName: "complete", type: AT_BOOL, pMemory: &this->m_bComplete);
  this->m_bComplete.m_pAttribute = v3;
  CDmAttribute::SetValue<bool>(this: v3, value: &v6);
  value = 0;
  v4 = CDmElement::AddExternalAttribute(
         this,
         pAttributeName: "completeCount",
         type: AT_INT,
         pMemory: &this->m_CompleteCount);
  this->m_CompleteCount.m_pAttribute = v4;
  CDmAttribute::SetValue<int>(this: v4, &value);
  CDmaDecorator<int,CDmaArrayBase<int,CDmaDataInternal<CUtlVector<int,CUtlMemory<int,int>>>>>::Init(
    this: &this->m_Components,
    pOwner: this,
    pAttributeName: "components",
    nFlags: 0);
  CDmaDecorator<float,CDmaArrayBase<float,CDmaDataInternal<CUtlVector<float,CUtlMemory<float,int>>>>>::Init(
    this: &this->m_Weights,
    pOwner: this,
    pAttributeName: "weights",
    nFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x006B92A0
// Name: _dynamic_initializer_for__CDmeComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeComponent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeComponent::s_Allocator,
    blockSize: 0x54u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeComponent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9300
// Name: _dynamic_initializer_for__CDmeSingleIndexedComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSingleIndexedComponent::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSingleIndexedComponent::s_Allocator,
    blockSize: 0x8Cu,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSingleIndexedComponent pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BD050
// Name: _dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeComponent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeComponent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BD060
// Name: _dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSingleIndexedComponent::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSingleIndexedComponent::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0049A33B
// Name: public: static class D3DXShader::CNode __near * D3DXShader::CNode::Copy(class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static struct D3DXShader::CNode *__stdcall D3DXShader::CNode::Copy(struct D3DXShader::CNode *a1)
{
  if ( a1 != nullptr )
    return (*(struct D3DXShader::CNode *(__thiscall **)(struct D3DXShader::CNode *))(*(_DWORD *)a1 + 4))(a1);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0049A354
// Name: public: static class D3DXShader::CNode __near * D3DXShader::CNode::Append(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
static struct D3DXShader::CNode *__stdcall D3DXShader::CNode::Append(
        struct D3DXShader::CNode *a1,
        struct D3DXShader::CNode *a2)
{
  struct D3DXShader::CNode **v3; // eax

  if ( a1 == nullptr )
    return a2;
  v3 = &a1;
  do
    v3 = (struct D3DXShader::CNode **)((char *)*v3 + 12);
  while ( *v3 != nullptr );
  *v3 = a2;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x0049A37D
// Name: public: D3DXShader::CNodeList::CNodeList(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeList::CNodeList(D3DXShader::CNodeList *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 1);
  v1[4] = 0;
  *v1 = &D3DXShader::CNodeList::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0049A393
// Name: public: D3DXShader::CNodeList::CNodeList(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeList::CNodeList(
        D3DXShader::CNodeList *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3,
        const char *a4)
{
  _DWORD *v4; // edx

  D3DXShader::CNode::CNode(this, a2: 1);
  v4[2] = a2;
  v4[3] = a3;
  v4[4] = a4;
  *v4 = &D3DXShader::CNodeList::`vftable';
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0049A41C
// Name: public: D3DXShader::CNodeTree::CNodeTree(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeTree::CNodeTree(D3DXShader::CNodeTree *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 2);
  v1[4] = 0;
  v1[5] = 0;
  *v1 = &D3DXShader::CNodeTree::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0049A436
// Name: public: D3DXShader::CNodeTree::CNodeTree(char const __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeTree::CNodeTree(
        D3DXShader::CNodeTree *this,
        const char *a2,
        struct D3DXShader::CNode *a3,
        struct D3DXShader::CNode *a4,
        struct D3DXShader::CNode *a5)
{
  _DWORD *v5; // edx

  D3DXShader::CNode::CNode(this, a2: 2);
  v5[4] = a2;
  v5[2] = a3;
  v5[3] = a4;
  v5[5] = a5;
  *v5 = &D3DXShader::CNodeTree::`vftable';
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0049A4B8
// Name: sub_49A4B8
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_49A4B8@<eax>(_DWORD *a1@<eax>, _DWORD *a2@<ecx>)
{
  int v2; // edx
  _BYTE *v5; // esi
  _BYTE *v6; // eax
  bool v7; // cf
  unsigned __int8 v8; // dl
  int v9; // eax
  int v10; // edx
  _BYTE *v11; // esi
  _BYTE *v12; // ecx
  unsigned __int8 v13; // dl
  _BYTE *v14; // esi
  _BYTE *v15; // ecx
  unsigned __int8 v16; // dl

  v2 = *a2;
  if ( *a2 != *a1 )
    return 0;
  if ( v2 > 8 )
  {
    v10 = v2 - 9;
    if ( v10 != 0 )
    {
      if ( v10 != 1 )
        return 1;
      v11 = (_BYTE *)a1[2];
      v12 = (_BYTE *)a2[2];
      while ( 1 )
      {
        v7 = *v12 < *v11;
        if ( *v12 != *v11 )
          break;
        if ( *v12 == 0 )
          goto LABEL_16;
        v13 = v12[1];
        v7 = v13 < v11[1];
        if ( v13 != v11[1] )
          break;
        v12 += 2;
        v11 += 2;
        if ( v13 == 0 )
          goto LABEL_16;
      }
    }
    else
    {
      v14 = (_BYTE *)a1[2];
      v15 = (_BYTE *)a2[2];
      while ( 1 )
      {
        v7 = *v15 < *v14;
        if ( *v15 != *v14 )
          break;
        if ( *v15 != 0 )
        {
          v16 = v15[1];
          v7 = v16 < v14[1];
          if ( v16 != v14[1] )
            break;
          v15 += 2;
          v14 += 2;
          if ( v16 != 0 )
            continue;
        }
LABEL_16:
        v9 = 0;
        return v9 == 0;
      }
    }
  }
  else
  {
    if ( v2 >= 5 )
      return *((double *)a2 + 1) == *((double *)a1 + 1);
    if ( v2 == 0 )
      return a2[2] == a1[2];
    if ( v2 != 1 )
    {
      if ( v2 <= 1 )
        return 1;
      return a2[2] == a1[2];
    }
    v5 = a1 + 2;
    v6 = a2 + 2;
    while ( 1 )
    {
      v7 = *v6 < *v5;
      if ( *v6 != *v5 )
        break;
      if ( *v6 == 0 )
        goto LABEL_16;
      v8 = v6[1];
      v7 = v8 < v5[1];
      if ( v8 != v5[1] )
        break;
      v6 += 2;
      v5 += 2;
      if ( v8 == 0 )
        goto LABEL_16;
    }
  }
  v9 = -v7 - (v7 - 1);
  return v9 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0049A588
// Name: public: D3DXShader::CNodeToken::CNodeToken(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeToken::CNodeToken(D3DXShader::CNodeToken *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 3);
  *v1 = &D3DXShader::CNodeToken::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0049A59A
// Name: public: D3DXShader::CNodeToken::CNodeToken(struct D3DXShader::D3DXTOKEN const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeToken::CNodeToken(
        D3DXShader::CNodeToken *this,
        const struct D3DXShader::D3DXTOKEN *a2)
{
  _DWORD *v2; // edx

  D3DXShader::CNode::CNode(this, a2: 3);
  *v2 = &D3DXShader::CNodeToken::`vftable';
  qmemcpy(v2 + 4, a2, 0x20u);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0049A5EA
// Name: public: D3DXShader::CNodeProgram::CNodeProgram(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeProgram::CNodeProgram(D3DXShader::CNodeProgram *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 4);
  v1[4] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[7] = 0;
  *v1 = &D3DXShader::CNodeProgram::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0049A60A
// Name: public: D3DXShader::CNodeProgram::CNodeProgram(unsigned int,unsigned int,unsigned int,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeProgram::CNodeProgram(
        D3DXShader::CNodeProgram *this,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        struct D3DXShader::CNode *a5)
{
  _DWORD *v5; // edx

  D3DXShader::CNode::CNode(this, a2: 4);
  v5[4] = a2;
  v5[5] = a3;
  v5[6] = a4;
  v5[7] = a5;
  *v5 = &D3DXShader::CNodeProgram::`vftable';
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0049A67F
// Name: public: D3DXShader::CNodeScope::CNodeScope(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeScope::CNodeScope(D3DXShader::CNodeScope *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 5);
  v1[4] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[7] = 0;
  v1[8] = 0;
  *v1 = &D3DXShader::CNodeScope::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0049A6A2
// Name: public: D3DXShader::CNodeScope::CNodeScope(enum D3DXShader::_D3DXSCOPE_TYPE,char const __near *,class D3DXShader::CNode __near *,class D3DXShader::CNodeTree __near *,class D3DXShader::CNodeScope __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeScope::CNodeScope(_DWORD *this, int a2, int a3, int a4, int a5, int a6)
{
  _DWORD *v6; // edx

  D3DXShader::CNode::CNode(this, a2: 5);
  v6[4] = a2;
  v6[5] = a3;
  v6[6] = a4;
  v6[7] = a5;
  v6[8] = a6;
  *v6 = &D3DXShader::CNodeScope::`vftable';
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x0049A73A
// Name: public: D3DXShader::CNodeDecl::CNodeDecl(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeDecl::CNodeDecl(D3DXShader::CNodeDecl *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 6);
  v1[9] = -1;
  v1[4] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[7] = 0;
  v1[8] = 0;
  v1[10] = 0;
  v1[11] = 0;
  *v1 = &D3DXShader::CNodeDecl::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0049A767
// Name: public: D3DXShader::CNodeDecl::CNodeDecl(enum D3DXShader::_D3DXDECL_TYPE,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeDecl::CNodeDecl(_DWORD *this, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // edx

  D3DXShader::CNode::CNode(this, a2: 6);
  v5[4] = a2;
  v5[5] = a3;
  v5[6] = a4;
  v5[7] = a5;
  v5[9] = -1;
  v5[8] = 0;
  v5[10] = 0;
  v5[11] = 0;
  *v5 = &D3DXShader::CNodeDecl::`vftable';
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0049A820
// Name: public: D3DXShader::CNodeUsage::CNodeUsage(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeUsage::CNodeUsage(D3DXShader::CNodeUsage *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 7);
  v1[4] = 0;
  v1[5] = 0;
  v1[6] = 0;
  *v1 = &D3DXShader::CNodeUsage::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0049A83D
// Name: public: D3DXShader::CNodeUsage::CNodeUsage(unsigned long,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeUsage::CNodeUsage(
        D3DXShader::CNodeUsage *this,
        unsigned int a2,
        struct D3DXShader::CNode *a3,
        struct D3DXShader::CNode *a4)
{
  _DWORD *v4; // edx

  D3DXShader::CNode::CNode(this, a2: 7);
  v4[4] = a2;
  v4[5] = a3;
  v4[6] = a4;
  *v4 = &D3DXShader::CNodeUsage::`vftable';
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0049A8B2
// Name: public: D3DXShader::CNodeArray::CNodeArray(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeArray::CNodeArray(D3DXShader::CNodeArray *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 8);
  v1[4] = 0;
  v1[5] = 0;
  *v1 = &D3DXShader::CNodeArray::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0049A8CC
// Name: public: D3DXShader::CNodeArray::CNodeArray(class D3DXShader::CNode __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeArray::CNodeArray(
        D3DXShader::CNodeArray *this,
        struct D3DXShader::CNode *a2,
        unsigned int a3)
{
  _DWORD *v3; // edx

  D3DXShader::CNode::CNode(this, a2: 8);
  v3[4] = a2;
  v3[5] = a3;
  *v3 = &D3DXShader::CNodeArray::`vftable';
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0049A925
// Name: public: D3DXShader::CNodeType::CNodeType(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeType::CNodeType(D3DXShader::CNodeType *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 9);
  v1[4] = 0;
  v1[6] = 0;
  v1[7] = 0;
  v1[8] = 0;
  *v1 = &D3DXShader::CNodeType::`vftable';
  v1[5] = 9;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0049A94C
// Name: public: D3DXShader::CNodeType::CNodeType(enum D3DXShader::_D3DXTYPE_TEMPLATE,enum D3DXShader::_D3DXCOMPONENT_TYPE,unsigned int,unsigned int,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeType::CNodeType(_DWORD *this, int a2, int a3, int a4, int a5, int a6)
{
  _DWORD *v6; // edx

  D3DXShader::CNode::CNode(this, a2: 9);
  v6[4] = a2;
  v6[5] = a3;
  v6[6] = a4;
  v6[7] = a5;
  v6[8] = a6;
  *v6 = &D3DXShader::CNodeType::`vftable';
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x0049A9C9
// Name: public: D3DXShader::CNodeFunction::CNodeFunction(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeFunction::CNodeFunction(D3DXShader::CNodeFunction *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 10);
  v1[4] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[7] = 0;
  v1[8] = 0;
  v1[9] = 0;
  v1[10] = 0;
  v1[11] = 0;
  v1[12] = 0;
  v1[13] = 0;
  v1[14] = 0;
  v1[15] = 0;
  *v1 = &D3DXShader::CNodeFunction::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0049AAC1
// Name: public: D3DXShader::CNodeVariable::CNodeVariable(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeVariable::CNodeVariable(D3DXShader::CNodeVariable *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 11);
  v1[4] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[7] = 0;
  v1[8] = 0;
  v1[9] = 0;
  v1[10] = 0;
  v1[11] = 0;
  v1[12] = 0;
  v1[13] = 0;
  v1[14] = 0;
  v1[15] = 0;
  *v1 = &D3DXShader::CNodeVariable::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0049ABB3
// Name: public: D3DXShader::CNodeStatement::CNodeStatement(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeStatement::CNodeStatement(D3DXShader::CNodeStatement *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 12);
  v1[4] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[7] = 0;
  v1[8] = 0;
  *v1 = &D3DXShader::CNodeStatement::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0049AC3D
// Name: public: D3DXShader::CNodeExpression::CNodeExpression(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeExpression::CNodeExpression(D3DXShader::CNodeExpression *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 13);
  v1[4] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[7] = 0;
  v1[8] = 0;
  v1[9] = 0;
  *v1 = &D3DXShader::CNodeExpression::`vftable';
  v1[10] = 1;
  memset(v1 + 12, 0, 0x20u);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0049AC76
// Name: public: D3DXShader::CNodeExpression::CNodeExpression(class D3DXShader::CNode __near *,enum D3DXShader::_D3DXEXPR_OP,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,int,struct D3DXShader::D3DXTOKEN const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeExpression::CNodeExpression(
        _DWORD *this,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        const void *a7)
{
  _DWORD *v7; // edx

  D3DXShader::CNode::CNode(this, a2: 13);
  v7[5] = 0;
  v7[6] = 0;
  v7[4] = a2;
  v7[7] = a3;
  v7[8] = a4;
  v7[9] = a5;
  v7[10] = a6;
  *v7 = &D3DXShader::CNodeExpression::`vftable';
  qmemcpy(v7 + 12, a7, 0x20u);
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x0049AD44
// Name: public: D3DXShader::CNodeValue::CNodeValue(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeValue::CNodeValue(D3DXShader::CNodeValue *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 14);
  *v1 = &D3DXShader::CNodeValue::`vftable';
  v1[4] = 0;
  v1[5] = 0;
  v1[6] = 0;
  v1[7] = 0;
  memset(v1 + 8, 0, 0x20u);
  v1[4] = 3;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0049AD77
// Name: public: D3DXShader::CNodeValue::CNodeValue(struct D3DXShader::_D3DXVALUE const __near *,struct D3DXShader::D3DXTOKEN const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CNodeValue *__thiscall D3DXShader::CNodeValue::CNodeValue(
        D3DXShader::CNodeValue *this,
        const struct D3DXShader::_D3DXVALUE *a2,
        const struct D3DXShader::D3DXTOKEN *a3)
{
  bool v4; // zf

  D3DXShader::CNode::CNode(this, a2: 14);
  *(_DWORD *)this = &D3DXShader::CNodeValue::`vftable';
  *((_DWORD *)this + 4) = *(_DWORD *)a2;
  *((_DWORD *)this + 5) = *((_DWORD *)a2 + 1);
  *((_DWORD *)this + 6) = *((_DWORD *)a2 + 2);
  *((_DWORD *)this + 7) = *((_DWORD *)a2 + 3);
  v4 = *((_DWORD *)this + 4) == 4;
  qmemcpy((char *)this + 32, a3, 0x20u);
  if ( v4 && *((_DWORD *)this + 6) != 0 )
    *((_DWORD *)this + 6) = D3DXShader::CNode::Copy(a1: *((struct D3DXShader::CNode **)this + 6));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0049ADC3
// Name: public: D3DXShader::CNodeValue::CNodeValue(enum D3DXShader::_D3DXVALUE_TYPE,class D3DXShader::CNode __near *,struct D3DXShader::D3DXTOKEN const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeValue::CNodeValue(_DWORD *this, int a2, int a3, const void *a4)
{
  _DWORD *v4; // edx

  D3DXShader::CNode::CNode(this, a2: 14);
  v4[4] = a2;
  v4[6] = a3;
  *v4 = &D3DXShader::CNodeValue::`vftable';
  qmemcpy(v4 + 8, a4, 0x20u);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0049ADF8
// Name: public: D3DXShader::CNodeValue::CNodeValue(enum D3DXShader::_D3DXVALUE_TYPE,double,struct D3DXShader::D3DXTOKEN const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall D3DXShader::CNodeValue::CNodeValue(_DWORD *this, int a2, double a3, const void *a4)
{
  int v4; // edx

  D3DXShader::CNode::CNode(this, a2: 14);
  *(double *)(v4 + 24) = a3;
  *(_DWORD *)(v4 + 16) = a2;
  *(_DWORD *)v4 = &D3DXShader::CNodeValue::`vftable';
  qmemcpy((void *)(v4 + 32), a4, 0x20u);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0049AE2D
// Name: public: D3DXShader::CNodeValue::CNodeValue(enum D3DXShader::_D3DXVALUE_TYPE,unsigned int,unsigned int,struct D3DXShader::D3DXTOKEN const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeValue::CNodeValue(_DWORD *this, int a2, int a3, int a4, const void *a5)
{
  _DWORD *v5; // edx

  D3DXShader::CNode::CNode(this, a2: 14);
  v5[4] = a2;
  v5[6] = a3;
  v5[7] = a4;
  *v5 = &D3DXShader::CNodeValue::`vftable';
  qmemcpy(v5 + 8, a5, 0x20u);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0049AEB9
// Name: public: D3DXShader::CNodeState::CNodeState(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeState::CNodeState(D3DXShader::CNodeState *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 16);
  v1[4] = 0;
  v1[5] = 0;
  v1[6] = 0;
  *v1 = &D3DXShader::CNodeState::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0049AED6
// Name: public: D3DXShader::CNodeState::CNodeState(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeState::CNodeState(
        D3DXShader::CNodeState *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3,
        struct D3DXShader::CNode *a4)
{
  _DWORD *v4; // edx

  D3DXShader::CNode::CNode(this, a2: 16);
  v4[4] = a2;
  v4[5] = a3;
  v4[6] = a4;
  *v4 = &D3DXShader::CNodeState::`vftable';
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0049AF52
// Name: public: D3DXShader::CNodeBuffer::CNodeBuffer(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeBuffer::CNodeBuffer(D3DXShader::CNodeBuffer *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 15);
  v1[12] = 0;
  v1[13] = 0;
  *v1 = &D3DXShader::CNodeBuffer::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0049AF6C
// Name: public: D3DXShader::CNodeBuffer::CNodeBuffer(struct D3DXShader::D3DXTOKEN const __near *,unsigned char __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeBuffer::CNodeBuffer(
        D3DXShader::CNodeBuffer *this,
        const struct D3DXShader::D3DXTOKEN *a2,
        unsigned __int8 *a3,
        unsigned int a4)
{
  _DWORD *v4; // edx

  D3DXShader::CNode::CNode(this, a2: 15);
  *v4 = &D3DXShader::CNodeBuffer::`vftable';
  qmemcpy(v4 + 4, a2, 0x20u);
  v4[12] = a3;
  v4[13] = a4;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0049AFE3
// Name: public: D3DXShader::CNodeRegister::CNodeRegister(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeRegister::CNodeRegister(D3DXShader::CNodeRegister *this)
{
  _DWORD *v1; // edx

  D3DXShader::CNode::CNode(this, a2: 17);
  v1[4] = 0;
  v1[5] = 0;
  *v1 = &D3DXShader::CNodeRegister::`vftable';
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0049AFFD
// Name: public: D3DXShader::CNodeRegister::CNodeRegister(class D3DXShader::CNode __near *,class D3DXShader::CNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall D3DXShader::CNodeRegister::CNodeRegister(
        D3DXShader::CNodeRegister *this,
        struct D3DXShader::CNode *a2,
        struct D3DXShader::CNode *a3)
{
  _DWORD *v3; // edx

  D3DXShader::CNode::CNode(this, a2: 17);
  v3[4] = a2;
  v3[5] = a3;
  *v3 = &D3DXShader::CNodeRegister::`vftable';
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0049B064
// Name: public: virtual class D3DXShader::CNode __near * D3DXShader::CNode::Copy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNode *__thiscall D3DXShader::CNode::Copy(D3DXShader::CNode *this)
{
  _DWORD *v2; // eax

  v2 = D3DXShader::CNode::operator new(a1: 0x10u);
  if ( v2 != nullptr )
    return (struct D3DXShader::CNode *)D3DXShader::CNode::CNode(this: v2, a2: *((_DWORD *)this + 1));
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0049B084
// Name: public: virtual class D3DXShader::CNodeList __near * D3DXShader::CNodeList::Copy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNodeList *__thiscall D3DXShader::CNodeList::Copy(D3DXShader::CNodeList *this)
{
  int *v2; // edi
  D3DXShader::CNodeList *v3; // eax
  _DWORD *v4; // eax
  int v6; // [esp+8h] [ebp-4h] BYREF

  v6 = 0;
  v2 = &v6;
  while ( this != nullptr )
  {
    if ( *((_DWORD *)this + 1) != 1 )
    {
      *v2 = (*(int (__thiscall **)(D3DXShader::CNodeList *))(*(_DWORD *)this + 4))(a1: this);
      return (struct D3DXShader::CNodeList *)v6;
    }
    v3 = (D3DXShader::CNodeList *)D3DXShader::CNode::operator new(a1: 0x14u);
    if ( v3 != nullptr )
      v4 = D3DXShader::CNodeList::CNodeList(this: v3);
    else
      v4 = nullptr;
    *v2 = (int)v4;
    if ( v4 == nullptr )
      return (struct D3DXShader::CNodeList *)v6;
    v4[4] = *((_DWORD *)this + 4);
    if ( *((_DWORD *)this + 2) != 0 )
    {
      *(_DWORD *)(*v2 + 8) = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 2) + 4))(a1: *((_DWORD *)this + 2));
      if ( *(_DWORD *)(*v2 + 8) == 0 )
      {
        *v2 = 0;
        return (struct D3DXShader::CNodeList *)v6;
      }
    }
    this = *((D3DXShader::CNodeList **)this + 3);
    v2 = (int *)(*v2 + 12);
  }
  return (struct D3DXShader::CNodeList *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x0049B0FD
// Name: public: virtual class D3DXShader::CNodeTree __near * D3DXShader::CNodeTree::Copy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNodeTree *__thiscall D3DXShader::CNodeTree::Copy(D3DXShader::CNodeTree *this)
{
  D3DXShader::CNodeTree *v2; // eax
  _DWORD *v3; // edi
  int v4; // eax
  int v5; // eax

  v2 = (D3DXShader::CNodeTree *)D3DXShader::CNode::operator new(a1: 0x18u);
  if ( v2 != nullptr )
    v3 = D3DXShader::CNodeTree::CNodeTree(this: v2);
  else
    v3 = nullptr;
  if ( v3 != nullptr
    && ((v3[5] = *((_DWORD *)this + 5), *((_DWORD *)this + 2) == 0)
     || (v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 2) + 4))(a1: *((_DWORD *)this + 2)),
         v3[2] = v4,
         v4 != 0))
    && (*((_DWORD *)this + 3) == 0
     || (v5 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 3) + 4))(a1: *((_DWORD *)this + 3)),
         v3[3] = v5,
         v5 != 0)) )
  {
    return (struct D3DXShader::CNodeTree *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049B158
// Name: public: virtual class D3DXShader::CNodeToken __near * D3DXShader::CNodeToken::Copy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNodeToken *__thiscall D3DXShader::CNodeToken::Copy(D3DXShader::CNodeToken *this)
{
  D3DXShader::CNodeToken *v2; // eax
  struct D3DXShader::CNodeToken *result; // eax

  v2 = (D3DXShader::CNodeToken *)D3DXShader::CNode::operator new(a1: 0x30u);
  if ( v2 != nullptr )
    result = (struct D3DXShader::CNodeToken *)D3DXShader::CNodeToken::CNodeToken(this: v2);
  else
    result = nullptr;
  if ( result != nullptr )
    qmemcpy((char *)result + 16, (char *)this + 16, 0x20u);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049B188
// Name: public: virtual class D3DXShader::CNodeProgram __near * D3DXShader::CNodeProgram::Copy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNodeProgram *__thiscall D3DXShader::CNodeProgram::Copy(D3DXShader::CNodeProgram *this)
{
  D3DXShader::CNodeProgram *v2; // eax
  _DWORD *v3; // esi
  int v4; // eax

  v2 = (D3DXShader::CNodeProgram *)D3DXShader::CNode::operator new(a1: 0x20u);
  if ( v2 != nullptr )
    v3 = D3DXShader::CNodeProgram::CNodeProgram(this: v2);
  else
    v3 = nullptr;
  if ( v3 != nullptr
    && ((v3[4] = *((_DWORD *)this + 4),
         v3[5] = *((_DWORD *)this + 5),
         v3[6] = *((_DWORD *)this + 6),
         *((_DWORD *)this + 7) == 0)
     || (v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 7) + 4))(a1: *((_DWORD *)this + 7)),
         v3[7] = v4,
         v4 != 0)) )
  {
    return (struct D3DXShader::CNodeProgram *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049B1DA
// Name: public: virtual class D3DXShader::CNodeScope __near * D3DXShader::CNodeScope::Copy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNodeScope *__thiscall D3DXShader::CNodeScope::Copy(D3DXShader::CNodeScope *this)
{
  D3DXShader::CNodeScope *v2; // eax
  _DWORD *v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // eax

  v2 = (D3DXShader::CNodeScope *)D3DXShader::CNode::operator new(a1: 0x24u);
  if ( v2 != nullptr )
    v3 = D3DXShader::CNodeScope::CNodeScope(this: v2);
  else
    v3 = nullptr;
  if ( v3 == nullptr )
    return nullptr;
  v3[4] = *((_DWORD *)this + 4);
  v3[5] = *((_DWORD *)this + 5);
  if ( *((_DWORD *)this + 6) != 0 )
  {
    v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 6) + 4))(a1: *((_DWORD *)this + 6));
    v3[6] = v4;
    if ( v4 == 0 )
      return nullptr;
  }
  if ( (*((_DWORD *)this + 7) == 0
     || (v5 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 7) + 4))(a1: *((_DWORD *)this + 7)),
         v3[7] = v5,
         v5 != 0))
    && (*((_DWORD *)this + 8) == 0
     || (v6 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 8) + 4))(a1: *((_DWORD *)this + 8)),
         v3[8] = v6,
         v6 != 0)) )
  {
    return (struct D3DXShader::CNodeScope *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049B250
// Name: public: virtual class D3DXShader::CNodeDecl __near * D3DXShader::CNodeDecl::Copy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNodeDecl *__thiscall D3DXShader::CNodeDecl::Copy(D3DXShader::CNodeDecl *this)
{
  D3DXShader::CNodeDecl *v2; // eax
  _DWORD *v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // eax

  v2 = (D3DXShader::CNodeDecl *)D3DXShader::CNode::operator new(a1: 0x30u);
  if ( v2 != nullptr )
    v3 = D3DXShader::CNodeDecl::CNodeDecl(this: v2);
  else
    v3 = nullptr;
  if ( v3 == nullptr )
    return nullptr;
  v3[4] = *((_DWORD *)this + 4);
  v3[8] = *((_DWORD *)this + 8);
  v3[9] = *((_DWORD *)this + 9);
  v3[10] = *((_DWORD *)this + 10);
  v3[11] = *((_DWORD *)this + 11);
  if ( *((_DWORD *)this + 5) != 0 )
  {
    v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 5) + 4))(a1: *((_DWORD *)this + 5));
    v3[5] = v4;
    if ( v4 == 0 )
      return nullptr;
  }
  if ( (*((_DWORD *)this + 6) == 0
     || (v5 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 6) + 4))(a1: *((_DWORD *)this + 6)),
         v3[6] = v5,
         v5 != 0))
    && (*((_DWORD *)this + 7) == 0
     || (v6 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 7) + 4))(a1: *((_DWORD *)this + 7)),
         v3[7] = v6,
         v6 != 0)) )
  {
    return (struct D3DXShader::CNodeDecl *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049B2D8
// Name: public: virtual class D3DXShader::CNodeUsage __near * D3DXShader::CNodeUsage::Copy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNodeUsage *__thiscall D3DXShader::CNodeUsage::Copy(D3DXShader::CNodeUsage *this)
{
  D3DXShader::CNodeUsage *v2; // eax
  _DWORD *v3; // edi
  int v4; // eax
  int v5; // eax

  v2 = (D3DXShader::CNodeUsage *)D3DXShader::CNode::operator new(a1: 0x1Cu);
  if ( v2 != nullptr )
    v3 = D3DXShader::CNodeUsage::CNodeUsage(this: v2);
  else
    v3 = nullptr;
  if ( v3 != nullptr
    && ((v3[4] = *((_DWORD *)this + 4), *((_DWORD *)this + 5) == 0)
     || (v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 5) + 4))(a1: *((_DWORD *)this + 5)),
         v3[5] = v4,
         v4 != 0))
    && (*((_DWORD *)this + 6) == 0
     || (v5 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 6) + 4))(a1: *((_DWORD *)this + 6)),
         v3[6] = v5,
         v5 != 0)) )
  {
    return (struct D3DXShader::CNodeUsage *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049B333
// Name: public: virtual class D3DXShader::CNodeArray __near * D3DXShader::CNodeArray::Copy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNodeArray *__thiscall D3DXShader::CNodeArray::Copy(D3DXShader::CNodeArray *this)
{
  D3DXShader::CNodeArray *v2; // eax
  _DWORD *v3; // esi
  int v4; // eax

  v2 = (D3DXShader::CNodeArray *)D3DXShader::CNode::operator new(a1: 0x18u);
  if ( v2 != nullptr )
    v3 = D3DXShader::CNodeArray::CNodeArray(this: v2);
  else
    v3 = nullptr;
  if ( v3 != nullptr
    && ((v3[5] = *((_DWORD *)this + 5), *((_DWORD *)this + 4) == 0)
     || (v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 4) + 4))(a1: *((_DWORD *)this + 4)),
         v3[4] = v4,
         v4 != 0)) )
  {
    return (struct D3DXShader::CNodeArray *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049B379
// Name: public: virtual class D3DXShader::CNodeType __near * D3DXShader::CNodeType::Copy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNodeType *__thiscall D3DXShader::CNodeType::Copy(D3DXShader::CNodeType *this)
{
  D3DXShader::CNodeType *v2; // eax
  struct D3DXShader::CNodeType *result; // eax

  v2 = (D3DXShader::CNodeType *)D3DXShader::CNode::operator new(a1: 0x24u);
  if ( v2 != nullptr )
    result = (struct D3DXShader::CNodeType *)D3DXShader::CNodeType::CNodeType(this: v2);
  else
    result = nullptr;
  if ( result != nullptr )
  {
    *((_DWORD *)result + 4) = *((_DWORD *)this + 4);
    *((_DWORD *)result + 5) = *((_DWORD *)this + 5);
    *((_DWORD *)result + 6) = *((_DWORD *)this + 6);
    *((_DWORD *)result + 7) = *((_DWORD *)this + 7);
    *((_DWORD *)result + 8) = *((_DWORD *)this + 8);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049B3BA
// Name: public: virtual class D3DXShader::CNodeFunction __near * D3DXShader::CNodeFunction::Copy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNodeFunction *__thiscall D3DXShader::CNodeFunction::Copy(D3DXShader::CNodeFunction *this)
{
  D3DXShader::CNodeFunction *v2; // eax
  _DWORD *v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax

  v2 = (D3DXShader::CNodeFunction *)D3DXShader::CNode::operator new(a1: 0x40u);
  if ( v2 != nullptr )
    v3 = D3DXShader::CNodeFunction::CNodeFunction(this: v2);
  else
    v3 = nullptr;
  if ( v3 == nullptr )
    return nullptr;
  v3[4] = *((_DWORD *)this + 4);
  v3[5] = *((_DWORD *)this + 5);
  v3[6] = *((_DWORD *)this + 6);
  v3[14] = *((_DWORD *)this + 14);
  v3[15] = *((_DWORD *)this + 15);
  if ( *((_DWORD *)this + 7) != 0 )
  {
    v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 7) + 4))(a1: *((_DWORD *)this + 7));
    v3[7] = v4;
    if ( v4 == 0 )
      return nullptr;
  }
  if ( *((_DWORD *)this + 8) != 0 )
  {
    v5 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 8) + 4))(a1: *((_DWORD *)this + 8));
    v3[8] = v5;
    if ( v5 == 0 )
      return nullptr;
  }
  if ( *((_DWORD *)this + 9) != 0 )
  {
    v6 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 9) + 4))(a1: *((_DWORD *)this + 9));
    v3[9] = v6;
    if ( v6 == 0 )
      return nullptr;
  }
  if ( *((_DWORD *)this + 10) != 0 )
  {
    v7 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 10) + 4))(a1: *((_DWORD *)this + 10));
    v3[10] = v7;
    if ( v7 == 0 )
      return nullptr;
  }
  if ( (*((_DWORD *)this + 11) == 0
     || (v8 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 11) + 4))(a1: *((_DWORD *)this + 11)),
         v3[11] = v8,
         v8 != 0))
    && (*((_DWORD *)this + 12) == 0
     || (v9 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 12) + 4))(a1: *((_DWORD *)this + 12)),
         v3[12] = v9,
         v9 != 0))
    && (*((_DWORD *)this + 13) == 0
     || (v10 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 13) + 4))(a1: *((_DWORD *)this + 13)),
         v3[13] = v10,
         v10 != 0)) )
  {
    return (struct D3DXShader::CNodeFunction *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049B497
// Name: public: virtual class D3DXShader::CNodeVariable __near * D3DXShader::CNodeVariable::Copy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNodeVariable *__thiscall D3DXShader::CNodeVariable::Copy(D3DXShader::CNodeVariable *this)
{
  D3DXShader::CNodeVariable *v2; // eax
  _DWORD *v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // eax
  _DWORD *v13; // [esp+Ch] [ebp-4h]

  v2 = (D3DXShader::CNodeVariable *)D3DXShader::CNode::operator new(a1: 0x40u);
  if ( v2 != nullptr )
  {
    v3 = D3DXShader::CNodeVariable::CNodeVariable(this: v2);
    v13 = v3;
  }
  else
  {
    v13 = nullptr;
    v3 = nullptr;
  }
  if ( v3 != nullptr )
  {
    v3[4] = *((_DWORD *)this + 4);
    v3[5] = *((_DWORD *)this + 5);
    v3[6] = *((_DWORD *)this + 6);
    v3[7] = *((_DWORD *)this + 7);
    v3[13] = *((_DWORD *)this + 13);
    if ( *((_DWORD *)this + 8) == 0
      || (v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 8) + 4))(a1: *((_DWORD *)this + 8)),
          v3[8] = v4,
          v4 != 0) )
    {
      if ( *((_DWORD *)this + 9) == 0
        || (v5 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 9) + 4))(a1: *((_DWORD *)this + 9)),
            v3[9] = v5,
            v5 != 0) )
      {
        if ( *((_DWORD *)this + 10) == 0
          || (v6 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 10) + 4))(a1: *((_DWORD *)this + 10)),
              v3[10] = v6,
              v6 != 0) )
        {
          if ( *((_DWORD *)this + 11) == 0
            || (v7 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 11) + 4))(a1: *((_DWORD *)this + 11)),
                v3[11] = v7,
                v7 != 0) )
          {
            if ( *((_DWORD *)this + 12) == 0
              || (v8 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 12) + 4))(a1: *((_DWORD *)this + 12)),
                  v3[12] = v8,
                  v8 != 0) )
            {
              v9 = *((_DWORD *)this + 13);
              if ( v9 == 0 )
                return (struct D3DXShader::CNodeVariable *)v3;
              v10 = D3DXCore::CAlloc::Alloc(this: D3DXShader::CNode::s_pAlloc, a2: 4 * v9, dwSize: 0x10u);
              v3[14] = v10;
              if ( v10 != nullptr )
              {
                v11 = D3DXCore::CAlloc::Alloc(
                        this: D3DXShader::CNode::s_pAlloc,
                        a2: 4 * *((_DWORD *)this + 5),
                        dwSize: 0x10u);
                v3[15] = v11;
                if ( v11 != nullptr )
                {
                  qmemcpy((void *)v3[14], *((const void **)this + 14), 4 * *((_DWORD *)this + 13));
                  qmemcpy((void *)v13[15], *((const void **)this + 15), 4 * *((_DWORD *)this + 5));
                  return (struct D3DXShader::CNodeVariable *)v13;
                }
              }
            }
          }
        }
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0049B5DB
// Name: public: virtual class D3DXShader::CNodeStatement __near * D3DXShader::CNodeStatement::Copy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNodeStatement *__thiscall D3DXShader::CNodeStatement::Copy(D3DXShader::CNodeStatement *this)
{
  D3DXShader::CNodeStatement *v2; // eax
  _DWORD *v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax

  v2 = (D3DXShader::CNodeStatement *)D3DXShader::CNode::operator new(a1: 0x24u);
  if ( v2 != nullptr )
    v3 = D3DXShader::CNodeStatement::CNodeStatement(this: v2);
  else
    v3 = nullptr;
  if ( v3 == nullptr )
    return nullptr;
  v3[4] = *((_DWORD *)this + 4);
  if ( *((_DWORD *)this + 5) != 0 )
  {
    v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 5) + 4))(a1: *((_DWORD *)this + 5));
    v3[5] = v4;
    if ( v4 == 0 )
      return nullptr;
  }
  if ( (*((_DWORD *)this + 6) == 0
     || (v5 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 6) + 4))(a1: *((_DWORD *)this + 6)),
         v3[6] = v5,
         v5 != 0))
    && (*((_DWORD *)this + 7) == 0
     || (v6 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 7) + 4))(a1: *((_DWORD *)this + 7)),
         v3[7] = v6,
         v6 != 0))
    && (*((_DWORD *)this + 8) == 0
     || (v7 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 8) + 4))(a1: *((_DWORD *)this + 8)),
         v3[8] = v7,
         v7 != 0)) )
  {
    return (struct D3DXShader::CNodeStatement *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049B660
// Name: public: virtual class D3DXShader::CNodeExpression __near * D3DXShader::CNodeExpression::Copy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNodeExpression *__thiscall D3DXShader::CNodeExpression::Copy(D3DXShader::CNodeExpression *this)
{
  D3DXShader::CNodeExpression *v2; // eax
  struct D3DXShader::CNodeExpression *result; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  struct D3DXShader::CNodeExpression *v7; // [esp+4h] [ebp-4h]

  v2 = (D3DXShader::CNodeExpression *)D3DXShader::CNode::operator new(a1: 0x50u);
  if ( v2 != nullptr )
  {
    result = (struct D3DXShader::CNodeExpression *)D3DXShader::CNodeExpression::CNodeExpression(this: v2);
    v7 = result;
  }
  else
  {
    v7 = nullptr;
    result = nullptr;
  }
  if ( result == nullptr )
    return result;
  *((_DWORD *)result + 5) = *((_DWORD *)this + 5);
  *((_DWORD *)result + 6) = *((_DWORD *)this + 6);
  *((_DWORD *)result + 7) = *((_DWORD *)this + 7);
  *((_DWORD *)result + 10) = *((_DWORD *)this + 10);
  qmemcpy((char *)result + 48, (char *)this + 48, 0x20u);
  if ( *((_DWORD *)this + 4) != 0 )
  {
    v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 4) + 4))(a1: *((_DWORD *)this + 4));
    *((_DWORD *)v7 + 4) = v4;
    if ( v4 == 0 )
      return nullptr;
    result = v7;
  }
  if ( *((_DWORD *)this + 8) != 0 )
  {
    v5 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 8) + 4))(a1: *((_DWORD *)this + 8));
    *((_DWORD *)v7 + 8) = v5;
    if ( v5 != 0 )
    {
      result = v7;
      goto LABEL_11;
    }
    return nullptr;
  }
LABEL_11:
  if ( *((_DWORD *)this + 9) == 0 )
    return result;
  v6 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 9) + 4))(a1: *((_DWORD *)this + 9));
  *((_DWORD *)v7 + 9) = v6;
  if ( v6 == 0 )
    return nullptr;
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x0049B709
// Name: public: virtual class D3DXShader::CNodeValue __near * D3DXShader::CNodeValue::Copy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNodeValue *__thiscall D3DXShader::CNodeValue::Copy(D3DXShader::CNodeValue *this)
{
  D3DXShader::CNodeValue *v2; // eax
  struct D3DXShader::CNode *v3; // eax
  _DWORD *v5; // [esp+4h] [ebp-4h]

  v2 = (D3DXShader::CNodeValue *)D3DXShader::CNode::operator new(a1: 0x40u);
  if ( v2 != nullptr )
    v5 = D3DXShader::CNodeValue::CNodeValue(this: v2);
  else
    v5 = nullptr;
  if ( v5 != nullptr
    && ((v5[4] = *((_DWORD *)this + 4),
         v5[5] = *((_DWORD *)this + 5),
         v5[6] = *((_DWORD *)this + 6),
         v5[7] = *((_DWORD *)this + 7),
         qmemcpy(v5 + 8, (char *)this + 32, 0x20u),
         *((_DWORD *)this + 4) != 4)
     || *((_DWORD *)this + 6) == 0
     || (v3 = D3DXShader::CNode::Copy(a1: *((struct D3DXShader::CNode **)this + 6)),
         *((_DWORD *)this + 6) = v3,
         v3 != nullptr)) )
  {
    return (struct D3DXShader::CNodeValue *)v5;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049B772
// Name: public: virtual class D3DXShader::CNodeState __near * D3DXShader::CNodeState::Copy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNodeState *__thiscall D3DXShader::CNodeState::Copy(D3DXShader::CNodeState *this)
{
  D3DXShader::CNodeState *v2; // eax
  _DWORD *v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // eax

  v2 = (D3DXShader::CNodeState *)D3DXShader::CNode::operator new(a1: 0x1Cu);
  if ( v2 != nullptr )
    v3 = D3DXShader::CNodeState::CNodeState(this: v2);
  else
    v3 = nullptr;
  if ( v3 != nullptr
    && (*((_DWORD *)this + 4) == 0
     || (v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 4) + 4))(a1: *((_DWORD *)this + 4)),
         v3[4] = v4,
         v4 != 0))
    && (*((_DWORD *)this + 5) == 0
     || (v5 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 5) + 4))(a1: *((_DWORD *)this + 5)),
         v3[5] = v5,
         v5 != 0))
    && (*((_DWORD *)this + 6) == 0
     || (v6 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 6) + 4))(a1: *((_DWORD *)this + 6)),
         v3[6] = v6,
         v6 != 0)) )
  {
    return (struct D3DXShader::CNodeState *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049B7DC
// Name: public: virtual class D3DXShader::CNodeBuffer __near * D3DXShader::CNodeBuffer::Copy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNodeBuffer *__thiscall D3DXShader::CNodeBuffer::Copy(D3DXShader::CNodeBuffer *this)
{
  D3DXShader::CNodeBuffer *v2; // eax
  struct D3DXShader::CNodeBuffer *result; // eax

  v2 = (D3DXShader::CNodeBuffer *)D3DXShader::CNode::operator new(a1: 0x38u);
  if ( v2 != nullptr )
    result = (struct D3DXShader::CNodeBuffer *)D3DXShader::CNodeBuffer::CNodeBuffer(this: v2);
  else
    result = nullptr;
  if ( result != nullptr )
    qmemcpy((char *)result + 16, (char *)this + 16, 0x28u);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0049B81A
// Name: public: virtual class D3DXShader::CNodeRegister __near * D3DXShader::CNodeRegister::Copy(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct D3DXShader::CNodeRegister *__thiscall D3DXShader::CNodeRegister::Copy(D3DXShader::CNodeRegister *this)
{
  D3DXShader::CNodeRegister *v2; // eax
  _DWORD *v3; // edi
  int v4; // eax
  int v5; // eax

  v2 = (D3DXShader::CNodeRegister *)D3DXShader::CNode::operator new(a1: 0x18u);
  if ( v2 != nullptr )
    v3 = D3DXShader::CNodeRegister::CNodeRegister(this: v2);
  else
    v3 = nullptr;
  if ( v3 != nullptr
    && (*((_DWORD *)this + 4) == 0
     || (v4 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 4) + 4))(a1: *((_DWORD *)this + 4)),
         v3[4] = v4,
         v4 != 0))
    && (*((_DWORD *)this + 5) == 0
     || (v5 = (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 5) + 4))(a1: *((_DWORD *)this + 5)),
         v3[5] = v5,
         v5 != 0)) )
  {
    return (struct D3DXShader::CNodeRegister *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0049B86F
// Name: public: D3DXShader::CCommentBlock::CCommentBlock(unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
D3DXShader::CCommentBlock *__thiscall D3DXShader::CCommentBlock::CCommentBlock(
        D3DXShader::CCommentBlock *this,
        unsigned int a2)
{
  *((_DWORD *)this + 1) = 0;
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = (char *)this + 8;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0049B88C
// Name: public: D3DXShader::CCommentBlock::~CCommentBlock(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall D3DXShader::CCommentBlock::~CCommentBlock(D3DXShader::CCommentBlock *this)
{
  int v2; // edi
  int v3; // eax

  while ( *((_DWORD *)this + 2) != 0 )
  {
    v2 = *((_DWORD *)this + 2);
    *((_DWORD *)this + 2) = *(_DWORD *)(v2 + 16);
    v3 = *(_DWORD *)(v2 + 8);
    if ( (v3 & 8) != 0 || (v3 & 1) == 0 )
      free(pMem: *(void **)v2);
    free(pMem: (void *)v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x006B92D0
// Name: _dynamic_initializer_for__g_CDmeComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeComponent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeComponent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B92E0
// Name: _dynamic_initializer_for__g_CDmeComponent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeComponent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeComponent_Helper,
           classname: "DmeComponent",
           pFactory: &g_CDmeComponent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B9330
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSingleIndexedComponent_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B9340
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponent_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSingleIndexedComponent_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSingleIndexedComponent_Helper,
           classname: "DmeSingleIndexedComponent",
           pFactory: &g_CDmeSingleIndexedComponent_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BD070
// Name: _dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSingleIndexedComponent_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeSingleIndexedComponent_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BD080
// Name: _dynamic_atexit_destructor_for__g_CDmeComponent_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeComponent_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeComponent_Factory.m_CallBackList);
}

} // namespace vmap
