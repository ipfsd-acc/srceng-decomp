// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/shadersystem.cpp
// Functions: 78
// ============================================================

#include "materialsystem\shadersystem.h"

//------------------------------------------------------------------------------
// Address: 0x10012940
// Name: public: bool CUtlVector<class GFxMovieView __near *,class CUtlMemory<class GFxMovieView __near *,int>>::FindAndFastRemove(class GFxMovieView __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<GFxMovieView *,CUtlMemory<GFxMovieView *,int>>::FindAndFastRemove(
        CUtlVector<GFxMovieView *,CUtlMemory<GFxMovieView *,int> > *this,
        GFxMovieView **src)
{
  int m_Size; // esi
  int v3; // eax
  GFxMovieView **i; // edx

  m_Size = this->m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return 0;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++v3 >= m_Size )
      return 0;
  }
  if ( v3 == -1 )
    return 0;
  if ( v3 != m_Size - 1 )
    this->m_Memory.m_pMemory[v3] = this->m_Memory.m_pMemory[m_Size - 1];
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10013EB0
// Name: public: void CUtlVector<class GFxValue,class CUtlMemory<class GFxValue,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GFxValue,CUtlMemory<GFxValue,int>>::RemoveAll(
        CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  GFxValue *v3; // esi
  CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *v4; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v4 = this;
  if ( v1 >= 0 )
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      if ( (v3->Type & 0x40) != 0 )
      {
        GFxValue::ObjectInterface::ObjectRelease(this: (CStringPool *)v3->pObjectInterface, val: (StringPoolCase_t)v3);
        this = v4;
        v3->pObjectInterface = nullptr;
      }
      --v2;
      --v1;
    }
    while ( v1 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10013F00
// Name: public: int CUtlVector<class GFxValue,class CUtlMemory<class GFxValue,int>>::InsertBefore(int,class GFxValue const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<GFxValue,CUtlMemory<GFxValue,int>>::InsertBefore(
        CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *this,
        int elem,
        const GFxValue *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  GFxValue *m_pMemory; // ecx
  int v7; // eax
  GFxValue *v8; // eax
  CStringPool *pObjectInterface; // ecx

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CMatRenderContextBase::ScissorRectStackElement_t,int>::Grow(
      (CUtlMemory<CUtlString,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 16 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    v8->pObjectInterface = nullptr;
    v8->Type = src->Type;
    v8->Value.NValue = src->Value.NValue;
    if ( (src->Type & 0x40) != 0 )
    {
      pObjectInterface = (CStringPool *)src->pObjectInterface;
      v8->pObjectInterface = src->pObjectInterface;
      GFxValue::ObjectInterface::ObjectAddRef(this: pObjectInterface, val: (StringPoolCase_t)v8);
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10013FC0
// Name: public: CUtlVector<class GFxValue,class CUtlMemory<class GFxValue,int>>::~CUtlVector<class GFxValue,class CUtlMemory<class GFxValue,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GFxValue,CUtlMemory<GFxValue,int>>::~CUtlVector<GFxValue,CUtlMemory<GFxValue,int>>(
        CUtlVector<GFxValue,CUtlMemory<GFxValue,int> > *this)
{
  bool v2; // sf
  GFxValue *m_pMemory; // eax

  CUtlVector<GFxValue,CUtlMemory<GFxValue,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016400
// Name: public: void CUtlVector<class GFxValue __near *,class CUtlMemory<class GFxValue __near *,int>>::FastRemove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<GFxValue *,CUtlMemory<GFxValue *,int>>::FastRemove(
        CUtlVector<GFxValue *,CUtlMemory<GFxValue *,int> > *this,
        int elem)
{
  int m_Size; // edx

  m_Size = this->m_Size;
  if ( m_Size > 0 )
  {
    if ( elem != m_Size - 1 )
      this->m_Memory.m_pMemory[elem] = this->m_Memory.m_pMemory[m_Size - 1];
    --this->m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100186C0
// Name: public: void CUtlVector<struct ColorCorrectionLookup_t __near *,class CUtlMemory<struct ColorCorrectionLookup_t __near *,int>>::Sort(int (*)(struct ColorCorrectionLookup_t __near * const __near *,struct ColorCorrectionLookup_t __near * const __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int>>::Sort(
        CUtlVector<ColorCorrectionLookup_t *,CUtlMemory<ColorCorrectionLookup_t *,int> > *this,
        int (__cdecl *pfnCompare)(const void *, const void *))
{
  signed int m_Size; // ebx
  int i; // ebx
  int j; // esi
  ColorCorrectionLookup_t *v6; // ecx
  ColorCorrectionLookup_t **v7; // eax

  m_Size = this->m_Size;
  if ( m_Size > 1 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      qsort(base: this->m_Memory.m_pMemory, num: m_Size, width: 4u, comp: pfnCompare);
    }
    else
    {
      for ( i = m_Size - 1; i >= 0; --i )
      {
        for ( j = 1; j <= i; ++j )
        {
          if ( pfnCompare(a1: &this->m_Memory.m_pMemory[j - 1], a2: &this->m_Memory.m_pMemory[j]) < 0 )
          {
            v6 = this->m_Memory.m_pMemory[j - 1];
            v7 = &this->m_Memory.m_pMemory[j];
            *(v7 - 1) = *v7;
            *v7 = v6;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BA00
// Name: public: void CUtlVector<void __near *,class CUtlMemory<void __near *,int>>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<void *,CUtlMemory<void *,int>>::Purge(CUtlVector<void *,CUtlMemory<void *,int> > *this)
{
  bool v2; // sf
  void **m_pMemory; // ecx

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v2 )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = 0;
    this->m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027BF0
// Name: public: CUtlVector<struct CMatRenderContextBase::PlaneStackElement,class CUtlMemory<struct CMatRenderContextBase::PlaneStackElement,int>>::~CUtlVector<struct CMatRenderContextBase::PlaneStackElement,class CUtlMemory<struct CMatRenderContextBase::PlaneStackElement,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int>>::~CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int>>(
        CUtlVector<GFxValue *,CUtlMemory<GFxValue *,int> > *this)
{
  GFxValue **m_pMemory; // eax

  this->m_Size = 0;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10027DC0
// Name: public: int CUtlVector<class CMaterialSystem::COnLevelShutdownFunc,class CUtlMemory<class CMaterialSystem::COnLevelShutdownFunc,int>>::InsertBefore(int,class CMaterialSystem::COnLevelShutdownFunc const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CMaterialSystem::COnLevelShutdownFunc,CUtlMemory<CMaterialSystem::COnLevelShutdownFunc,int>>::InsertBefore(
        CUtlVector<CMaterialSystem::COnLevelShutdownFunc,CUtlMemory<CMaterialSystem::COnLevelShutdownFunc,int> > *this,
        int elem,
        const CMaterialSystem::COnLevelShutdownFunc *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CMaterialSystem::COnLevelShutdownFunc *m_pMemory; // ecx
  int v7; // eax
  CMaterialSystem::COnLevelShutdownFunc *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CMorph::MorphSegment_t,int>::Grow(
      (CUtlMemory<ResourceEntryInfo,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 8 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x100295E0
// Name: public: void CUtlVector<char,class CUtlMemory<char,int>>::SetCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char,CUtlMemory<char,int>>::SetCount(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        int count)
{
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v5; // eax

  this->m_Size = 0;
  if ( count != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( count > m_nAllocationCount )
      CUtlMemory<char,int>::Grow((CUtlMemory<unsigned char,int> *)this, num: count - m_nAllocationCount);
    this->m_Size += count;
    m_pMemory = this->m_Memory.m_pMemory;
    v5 = this->m_Size - count;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v5 > 0 && count > 0 )
      _V_memmove(dest: &m_pMemory[count], src: m_pMemory, count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10046520
// Name: public: void CUtlVector<struct CMatRenderContextBase::PlaneStackElement,class CUtlMemory<struct CMatRenderContextBase::PlaneStackElement,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int>>::Remove(
        CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int> > *this,
        int elem)
{
  int v3; // eax

  v3 = this->m_Size - elem - 1;
  if ( v3 > 0 )
    _V_memmove(dest: &this->m_Memory.m_pMemory[elem], src: &this->m_Memory.m_pMemory[elem + 1], count: 20 * v3);
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100471A0
// Name: public: int CUtlVector<struct CMatRenderContextBase::PlaneStackElement,class CUtlMemory<struct CMatRenderContextBase::PlaneStackElement,int>>::InsertBefore(int,struct CMatRenderContextBase::PlaneStackElement const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int>>::InsertBefore(
        CUtlVector<CMatRenderContextBase::PlaneStackElement,CUtlMemory<CMatRenderContextBase::PlaneStackElement,int> > *this,
        int elem,
        const CMatRenderContextBase::PlaneStackElement *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CMatRenderContextBase::PlaneStackElement *m_pMemory; // ecx
  int v7; // eax
  CMatRenderContextBase::PlaneStackElement *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CMatRenderContextBase::PlaneStackElement,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MissingMaterial_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 20 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1004C360
// Name: public: void CUtlVector<struct CTexture::DataChunk,class CUtlMemory<struct CTexture::DataChunk,int>>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CTexture::DataChunk,CUtlMemory<CTexture::DataChunk,int>>::EnsureCapacity(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this,
        int num)
{
  CVTFTexture::ResourceMemorySection *m_pMemory; // edx
  unsigned int v4; // eax
  CVTFTexture::ResourceMemorySection *v5; // eax

  if ( this->m_Memory.m_nAllocationCount >= num )
  {
    this->m_pElements = this->m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_Memory.m_nGrowSize < 0 )
    {
LABEL_5:
      this->m_pElements = this->m_Memory.m_pMemory;
      return;
    }
    m_pMemory = this->m_Memory.m_pMemory;
    this->m_Memory.m_nAllocationCount = num;
    v4 = 12 * num;
    if ( m_pMemory != nullptr )
    {
      this->m_Memory.m_pMemory = (CVTFTexture::ResourceMemorySection *)_g_pMemAlloc->Realloc_2(
                                                                         this: _g_pMemAlloc,
                                                                         a2: m_pMemory,
                                                                         a3: v4);
      goto LABEL_5;
    }
    v5 = (CVTFTexture::ResourceMemorySection *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v4);
    this->m_Memory.m_pMemory = v5;
    this->m_pElements = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004CDF0
// Name: public: int CUtlVector<struct TextureLodOverride::OverrideInfo,class CUtlMemory<struct TextureLodOverride::OverrideInfo,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int>>::InsertMultipleBefore(
        CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  TextureLodOverride::OverrideInfo *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  TextureLodOverride::OverrideInfo *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<TextureLodOverride::OverrideInfo,int>::Grow(
      this: &this->m_Memory,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 2 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      do
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          *v11 = 0;
        ++v10;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x1004DFB0
// Name: public: int CUtlVector<struct CTexture_MultipleRenderTarget::SubTarget_t,class CUtlMemory<struct CTexture_MultipleRenderTarget::SubTarget_t,int>>::InsertBefore(int,struct CTexture_MultipleRenderTarget::SubTarget_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CTexture_MultipleRenderTarget::SubTarget_t,CUtlMemory<CTexture_MultipleRenderTarget::SubTarget_t,int>>::InsertBefore(
        CUtlVector<CTexture_MultipleRenderTarget::SubTarget_t,CUtlMemory<CTexture_MultipleRenderTarget::SubTarget_t,int> > *this,
        int elem,
        const CTexture_MultipleRenderTarget::SubTarget_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CTexture_MultipleRenderTarget::SubTarget_t *m_pMemory; // ecx
  int v7; // eax
  CTexture_MultipleRenderTarget::SubTarget_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CMatRenderContextBase::PlaneStackElement,int>::Grow(
      (CUtlMemory<UtlRBTreeNode_t<CMaterialDict::MissingMaterial_t,int>,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 20 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10053A10
// Name: public: void CUtlVector<struct CVertexMorphDict::MorphVertexList_t,class CUtlMemory<struct CVertexMorphDict::MorphVertexList_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int>>::RemoveAll(
        CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *this)
{
  int v1; // ebx
  int v2; // edx
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+8h] [ebp-14h]
  CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *v6; // [esp+Ch] [ebp-10h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 32 * v1;
    v5 = 32 * v1;
    do
    {
      v3 = (char *)&this->m_Memory.m_pMemory->m_MorphInfo + v2;
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      v4 = *(void **)v3;
      *((_DWORD *)v3 + 4) = *(_DWORD *)v3;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      --v1;
      v2 = v5 - 32;
      v5 -= 32;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053AE0
// Name: public: void CUtlVector<class CUtlVector<struct CMorph::MorphSegment_t,class CUtlMemory<struct CMorph::MorphSegment_t,int>>,class CUtlMemory<class CUtlVector<struct CMorph::MorphSegment_t,class CUtlMemory<struct CMorph::MorphSegment_t,int>>,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int>>,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int>>,int>>::RemoveAll(
        CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+8h] [ebp-14h]
  CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,int> > *v6; // [esp+Ch] [ebp-10h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 20 * v1;
    v5 = 20 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 3) = 0;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( *(_DWORD *)v3 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v3);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      v4 = *(void **)v3;
      *((_DWORD *)v3 + 4) = *(_DWORD *)v3;
      if ( *((int *)v3 + 2) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *(_DWORD *)v3 = 0;
        }
        *((_DWORD *)v3 + 1) = 0;
      }
      --v1;
      v2 = v5 - 20;
      v5 -= 20;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053E80
// Name: public: CUtlVector<class CUtlVector<struct CMorph::MorphSegment_t,class CUtlMemory<struct CMorph::MorphSegment_t,int>>,class CUtlMemory<class CUtlVector<struct CMorph::MorphSegment_t,class CUtlMemory<struct CMorph::MorphSegment_t,int>>,int>>::~CUtlVector<class CUtlVector<struct CMorph::MorphSegment_t,class CUtlMemory<struct CMorph::MorphSegment_t,int>>,class CUtlMemory<class CUtlVector<struct CMorph::MorphSegment_t,class CUtlMemory<struct CMorph::MorphSegment_t,int>>,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int>>,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int>>,int>>::~CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int>>,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int>>,int>>(
        CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> >,int> > *this)
{
  bool v2; // sf
  CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> > *m_pMemory; // eax

  CUtlVector<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int>>,CUtlMemory<CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int>>,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10053FD0
// Name: public: CUtlVector<struct CVertexMorphDict::MorphVertexList_t,class CUtlMemory<struct CVertexMorphDict::MorphVertexList_t,int>>::~CUtlVector<struct CVertexMorphDict::MorphVertexList_t,class CUtlMemory<struct CVertexMorphDict::MorphVertexList_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int>>::~CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int>>(
        CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int> > *this)
{
  bool v2; // sf
  CVertexMorphDict::MorphVertexList_t *m_pMemory; // eax

  CUtlVector<CVertexMorphDict::MorphVertexList_t,CUtlMemory<CVertexMorphDict::MorphVertexList_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054DB0
// Name: char __near * MemAlloc_StrDup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl MemAlloc_StrDup(const char *pString)
{
  char *result; // eax

  if ( pString == nullptr )
    return nullptr;
  result = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(pString) + 1);
  if ( result == nullptr )
    return nullptr;
  strcpy(result, pString);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10054E00
// Name: bool CaselessStringLessThan(char const __near * const __near &,char const __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CaselessStringLessThan(const char **lhs, const char **rhs)
{
  if ( *lhs == nullptr )
    return false;
  if ( *rhs != nullptr )
    return _V_stricmp(s1: *lhs, s2: *rhs) < 0;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10054E40
// Name: private: void CShaderSystem::LoadModShaderDLLs(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderSystem::LoadModShaderDLLs(CShaderSystem *this, int dxSupportLevel)
{
  int v2; // ebx
  int i; // edi
  const char *j; // eax
  char buf[256]; // [esp+Ch] [ebp-100h] BYREF

  v2 = dxSupportLevel;
  for ( i = 6; i <= v2; ++i )
  {
    V_snprintf(pDest: buf, maxLen: 256, pFormat: "game_shader_dx%d", i);
    this->LoadShaderDLL_2(this, a2: buf, a3: "GAMEBIN", a4: true);
  }
  for ( j = g_pFullFileSystem->FindFirstEx(
              this: g_pFullFileSystem,
              a2: "game_shader_generic*",
              a3: "GAMEBIN",
              a4: &dxSupportLevel); j != nullptr; j = g_pFullFileSystem->FindNext(
                                                    this: g_pFullFileSystem,
                                                    a2: dxSupportLevel) )
  {
    V_snprintf(pDest: buf, maxLen: 256, pFormat: "%s", j);
    this->LoadShaderDLL_2(this, a2: buf, a3: "GAMEBIN", a4: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10054F10
// Name: public: virtual bool CShaderSystem::LoadShaderDLL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderSystem::LoadShaderDLL(CShaderSystem *this, const char *pFullPath)
{
  return this->LoadShaderDLL_2(this, a2: pFullPath, a3: nullptr, a4: false);
}

//------------------------------------------------------------------------------
// Address: 0x10054F30
// Name: private: void CShaderSystem::VerifyBaseShaderDLL(class CSysModule __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderSystem::VerifyBaseShaderDLL(CShaderSystem *this, struct CSysModule *pModule)
{
  unsigned __int8 *v2; // esi
  FARPROC _ftol3; // edi
  int v4; // eax
  unsigned int v5; // ecx
  unsigned __int8 *v6; // eax
  MD5Context_t md5Context; // [esp+Ch] [ebp-70h] BYREF
  unsigned __int8 digest[16]; // [esp+64h] [ebp-18h] BYREF
  IShaderDLLVerification *pVerify; // [esp+74h] [ebp-8h] BYREF
  unsigned int testCRC; // [esp+78h] [ebp-4h] BYREF

  v2 = (unsigned __int8 *)MemAlloc_Alloc(nSize: 0x1005u);
  _ftol3 = GetProcAddress(hModule: (HMODULE)pModule, lpProcName: "_ftol3");
  if ( _ftol3 == nullptr )
    _Error(a1: "Corrupt save data settings.");
  ((void (__cdecl *)(unsigned __int8 *))_ftol3)(a1: &md5Context.in[37]);
  CRC32_Init(pulCRC: &testCRC);
  CRC32_ProcessBuffer(pulCRC: &testCRC, pBuffer: v2, nBuffer: 4101);
  CRC32_ProcessBuffer(pulCRC: &testCRC, pBuffer: &pModule, nBuffer: 4);
  CRC32_ProcessBuffer(pulCRC: &testCRC, pBuffer: &pVerify, nBuffer: 4);
  CRC32_Final(pulCRC: &testCRC);
  v4 = pVerify->Function1(this: pVerify, a2: v2 - 43);
  if ( testCRC != v4 )
    _Error(a1: "Corrupt save data settings.");
  MD5Init(ctx: &md5Context);
  MD5Update(ctx: &md5Context, buf: v2 + 43, len: 0xFDAu);
  MD5Final(digest, ctx: &md5Context);
  pVerify->Function2(this: pVerify, a2: 2, a3: 3, a4: 3);
  v5 = 16;
  v6 = v2;
  while ( *(_DWORD *)&v6[digest - v2] == *(_DWORD *)v6 )
  {
    v5 -= 4;
    v6 += 4;
    if ( v5 < 4 )
      goto LABEL_10;
  }
  _Error(a1: "Corrupt save data settings.");
LABEL_10:
  pVerify->Function5(this: pVerify);
  free(pMem: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10055070
// Name: public: virtual char const __near * CShaderSystem::ShaderStateString(int)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CShaderSystem::ShaderStateString(CShaderSystem *this, int i)
{
  return s_pShaderStateString[i];
}

//------------------------------------------------------------------------------
// Address: 0x10055090
// Name: public: virtual int CShaderSystem::ShaderCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderSystem::ShaderCount(CShaderSystem *this)
{
  return this->GetShaders(this, a2: 0, a3: 0x10000, a4: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100550B0
// Name: public: virtual void CShaderSystem::CreateDebugMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderSystem::CreateDebugMaterials(CShaderSystem *this)
{
  IMaterialInternal **m_pDebugMaterials; // ebx
  int i; // esi
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  int v5; // esi
  _DWORD *v6; // edi
  IMaterial *v7; // eax
  char shaderName[64]; // [esp+4h] [ebp-68h] BYREF
  KeyValues *pVMTKeyValues[6]; // [esp+44h] [ebp-28h]
  KeyValues *v10; // [esp+5Ch] [ebp-10h]
  int v11; // [esp+68h] [ebp-4h]

  m_pDebugMaterials = this->m_pDebugMaterials;
  if ( this->m_pDebugMaterials[0] == nullptr )
  {
    for ( i = 0; i < 6; ++i )
    {
      v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      v10 = v3;
      v11 = 0;
      if ( v3 != nullptr )
        v4 = KeyValues::KeyValues(this: v3, setName: CShaderSystem::s_pDebugShaderName[i]);
      else
        v4 = nullptr;
      pVMTKeyValues[i] = v4;
      v11 = -1;
    }
    KeyValues::SetInt(this: pVMTKeyValues[4], keyName: "$decal", value: 1);
    v5 = 0;
    v6 = m_pDebugMaterials;
    do
    {
      V_snprintf(pDest: shaderName, maxLen: 64, pFormat: "___%s_%d.vmt", CShaderSystem::s_pDebugShaderName[v5], v5);
      v7 = g_pInternalMaterialSystem->CreateMaterial(
             this: g_pInternalMaterialSystem,
             a2: shaderName,
             a3: pVMTKeyValues[v5]);
      *v6 = v7;
      if ( v7 != nullptr )
        *v6 = ((int (__thiscall *)(IMaterial *))v7->__vftable[1].Refresh)(a1: v7);
      ++v5;
      ++v6;
    }
    while ( v5 < 6 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100551A0
// Name: public: virtual void CShaderSystem::CleanUpDebugMaterials(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CShaderSystem::CleanUpDebugMaterials(CShaderSystem *this@<ecx>, IMaterialInternal *a2@<edi>)
{
  IMaterialInternal **m_pDebugMaterials; // esi
  int i; // edi
  bool v4; // al

  m_pDebugMaterials = this->m_pDebugMaterials;
  if ( this->m_pDebugMaterials[0] != nullptr )
  {
    for ( i = 6; i != 0; --i )
    {
      ((void (__thiscall *)(IMaterialInternal *, IMaterialInternal *))(*m_pDebugMaterials)->DecrementReferenceCount)(
        a1: *m_pDebugMaterials,
        a2);
      v4 = (*m_pDebugMaterials)->InMaterialPage(this: *m_pDebugMaterials);
      a2 = *m_pDebugMaterials;
      if ( v4 )
        ((void (__thiscall *)(IMaterialSystemInternal *))g_pInternalMaterialSystem->RemoveMaterialSubRect)(a1: g_pInternalMaterialSystem);
      else
        ((void (__thiscall *)(IMaterialSystemInternal *))g_pInternalMaterialSystem->RemoveMaterial)(a1: g_pInternalMaterialSystem);
      *m_pDebugMaterials++ = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055200
// Name: public: virtual void CShaderSystem::InitShaderParameters(class IShader __near *,class IMaterialVar __near * __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderSystem::InitShaderParameters(
        CShaderSystem *this,
        IShader *pShader,
        IMaterialVar **params,
        const char *pMaterialName)
{
  int i; // esi
  VMatrix identity; // [esp+38h] [ebp-40h] BYREF

  _LoggingSystem_PushLoggingState(a1: 1, a2: 1);
  _LoggingSystem_RegisterLoggingListener(a1: &this->m_BufferedLoggingListener);
  _LoggingSystem_SetLoggingResponsePolicy(a1: &this->m_NonFatalLoggingResponsePolicy);
  this->m_pRenderState = nullptr;
  *(_WORD *)&this->m_nModulation = 0;
  pShader->InitShaderParams(this: pShader, a2: params, a3: pMaterialName);
  _LoggingSystem_PopLoggingState(a1: 1);
  CBufferedLoggingListener::EmitBufferedSpew(this: &this->m_BufferedLoggingListener);
  this->m_pRenderState = nullptr;
  if ( !params[4]->IsDefined(this: params[4]) )
    ((void (__thiscall *)(IMaterialVar *, int, int, int))params[4]->SetVecValue_2)(
      a1: params[4],
      a2: 1065353216,
      a3: 1065353216,
      a4: 1065353216);
  if ( !params[5]->IsDefined(this: params[5]) )
    ((void (__stdcall *)(int))params[5]->SetFloatValue)(a1: 1065353216);
  for ( i = pShader->GetParamCount(this: pShader) - 1; i >= 0; --i )
  {
    if ( !params[i]->IsDefined(this: params[i]) )
    {
      switch ( pShader->GetParamInfo(this: pShader, a2: i)->m_Type )
      {
        case SHADER_PARAM_TYPE_INTEGER:
        case SHADER_PARAM_TYPE_BOOL:
          ((void (__stdcall *)(_DWORD))params[i]->SetIntValue)(a1: 0);
          break;
        case SHADER_PARAM_TYPE_COLOR:
          ((void (__thiscall *)(IMaterialVar *, int, int, int))params[i]->SetVecValue_2)(
            a1: params[i],
            a2: 1065353216,
            a3: 1065353216,
            a4: 1065353216);
          break;
        case SHADER_PARAM_TYPE_VEC2:
          ((void (__thiscall *)(IMaterialVar *, _DWORD, _DWORD))params[i]->SetVecValue_3)(a1: params[i], a2: 0, a3: 0);
          break;
        case SHADER_PARAM_TYPE_VEC3:
          ((void (__thiscall *)(IMaterialVar *, _DWORD, _DWORD, _DWORD))params[i]->SetVecValue_2)(
            a1: params[i],
            a2: 0,
            a3: 0,
            a4: 0);
          break;
        case SHADER_PARAM_TYPE_VEC4:
          ((void (__thiscall *)(IMaterialVar *, _DWORD, _DWORD, _DWORD, _DWORD))params[i]->SetVecValue)(
            a1: params[i],
            a2: 0,
            a3: 0,
            a4: 0,
            a5: 0);
          break;
        case SHADER_PARAM_TYPE_FLOAT:
          ((void (__stdcall *)(_DWORD))params[i]->SetFloatValue)(a1: 0);
          break;
        case SHADER_PARAM_TYPE_FOURCC:
          params[i]->SetFourCCValue(this: params[i], a2: 0, a3: nullptr);
          break;
        case SHADER_PARAM_TYPE_MATRIX:
          MatrixSetIdentity(dst: &identity);
          ((void (__stdcall *)(VMatrix *))params[i]->SetMatrixValue)(a1: &identity);
          break;
        case SHADER_PARAM_TYPE_MATERIAL:
          ((void (__stdcall *)(_DWORD))params[i]->SetMaterialValue)(a1: 0);
          break;
        default:
          continue;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055440
// Name: public: virtual void CShaderSystem::InitShaderInstance(class IShader __near *,class IMaterialVar __near * __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderSystem::InitShaderInstance(
        CShaderSystem *this,
        IShader *pShader,
        IMaterialVar **params,
        const char *pMaterialName,
        const char *pTextureGroupName)
{
  _LoggingSystem_PushLoggingState(a1: 1, a2: 1);
  _LoggingSystem_RegisterLoggingListener(a1: &this->m_BufferedLoggingListener);
  _LoggingSystem_SetLoggingResponsePolicy(a1: &this->m_NonFatalLoggingResponsePolicy);
  this->m_pRenderState = nullptr;
  *(_WORD *)&this->m_nModulation = 0;
  pShader->InitShaderInstance(this: pShader, a2: params, a3: g_pShaderSystem, a4: pMaterialName, a5: pTextureGroupName);
  _LoggingSystem_PopLoggingState(a1: 1);
  CBufferedLoggingListener::EmitBufferedSpew(this: &this->m_BufferedLoggingListener);
  this->m_pRenderState = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100554B0
// Name: private: void CShaderSystem::InitStateSnapshots(class IShader __near *,class IMaterialVar __near * __near *,struct ShaderRenderState_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CShaderSystem::InitStateSnapshots(
        CShaderSystem *this@<ecx>,
        unsigned int a2@<edi>,
        IShader *pShader,
        IMaterialVar **params,
        ShaderRenderState_t *pRenderState)
{
  int m_intVal; // eax
  char v8; // al
  int m_nValue; // eax
  int v10; // eax
  int v11; // edi
  bool v12; // zf
  int v13; // eax
  unsigned int v14; // eax
  int v15; // eax
  unsigned int v16; // eax
  int v17; // eax
  unsigned int v18; // eax
  int v19; // eax
  unsigned int v20; // eax
  int v21; // eax
  unsigned int v22; // eax
  IMaterialVar *v23; // ecx
  int v24; // eax
  int v25; // eax
  unsigned int v26; // eax
  int v27; // eax
  unsigned int v28; // eax
  int v29; // eax
  unsigned int v30; // eax
  int v31; // eax
  IMaterialVar_vtbl *v32; // edx
  int v34; // [esp+8h] [ebp-18h]
  int v35; // [esp+Ch] [ebp-14h]
  int v36; // [esp+10h] [ebp-10h]
  int i; // [esp+14h] [ebp-Ch]
  bool bGBuffer1; // [esp+1Ah] [ebp-6h]
  bool bGBuffer0; // [esp+1Bh] [ebp-5h]
  bool bFlashlight; // [esp+1Ch] [ebp-4h]
  bool bEditor; // [esp+1Dh] [ebp-3h]
  bool bPaint; // [esp+1Eh] [ebp-2h]
  bool bCanSupportGBuffer; // [esp+1Fh] [ebp-1h]
  bool bModUsesFlashlight_3; // [esp+2Fh] [ebp+Fh]

  m_intVal = params[2]->m_intVal;
  bPaint = (m_intVal & 0x800) != 0;
  bFlashlight = (m_intVal & 0x400) != 0;
  bEditor = (m_intVal & 0x2000) != 0;
  bGBuffer1 = (m_intVal & 0x200000) != 0;
  bGBuffer0 = (m_intVal & 0x100000) != 0;
  v8 = g_pInternalMaterialSystem->GetConfigurationFlags(this: g_pInternalMaterialSystem);
  if ( (v8 & 2) != 0 )
    v35 = 64;
  else
    v35 = 8 * ((v8 & 1) != 0) + 8;
  if ( mat_supportflashlight.m_pParent != nullptr )
    m_nValue = mat_supportflashlight.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  bModUsesFlashlight_3 = m_nValue != 0;
  bCanSupportGBuffer = (g_pInternalMaterialSystem->GetConfigurationFlags(this: g_pInternalMaterialSystem) & 2) != 0;
  v10 = 0;
  i = 0;
  if ( v35 > 0 )
  {
    v36 = 0;
    do
    {
      v11 = v10 & 2;
      if ( (v10 & 2) != 0 && !bModUsesFlashlight_3
        || (v10 & 2) != 0 && (v10 & 0x30) != 0
        || (v34 = v10 & 8, (v10 & 8) != 0)
        && (v12 = !this->CanUseEditorMaterials(this: &this->IShaderSystem), v10 = i, v12)
        || (v10 & 0x30) != 0 && !bCanSupportGBuffer )
      {
        pRenderState->m_pSnapshots[v36].m_nPassCount = 0;
      }
      else
      {
        v13 = ((int (__thiscall *)(IMaterialVar *, unsigned int))params[2]->GetIntValueInternal)(a1: params[2], a2);
        if ( v11 != 0 )
          v14 = v13 | 0x400;
        else
          v14 = v13 & 0xFFFFFBFF;
        ((void (__stdcall *)(unsigned int))params[2]->SetIntValue)(a1: v14);
        v15 = params[2]->GetIntValueInternal(this: params[2]);
        if ( v34 != 0 )
          v16 = v15 | 0x2000;
        else
          v16 = v15 & 0xFFFFDFFF;
        ((void (__stdcall *)(unsigned int))params[2]->SetIntValue)(a1: v16);
        v17 = params[2]->GetIntValueInternal(this: params[2]);
        if ( (i & 4) != 0 )
          v18 = v17 | 0x800;
        else
          v18 = v17 & 0xFFFFF7FF;
        ((void (__stdcall *)(unsigned int))params[2]->SetIntValue)(a1: v18);
        v19 = params[2]->GetIntValueInternal(this: params[2]);
        if ( (i & 0x10) != 0 )
          v20 = v19 | 0x100000;
        else
          v20 = v19 & 0xFFEFFFFF;
        ((void (__stdcall *)(unsigned int))params[2]->SetIntValue)(a1: v20);
        v21 = params[2]->GetIntValueInternal(this: params[2]);
        if ( (i & 0x20) != 0 )
          v22 = v21 | 0x200000;
        else
          v22 = v21 & 0xFFDFFFFF;
        a2 = v22;
        ((void (*)(void))params[2]->SetIntValue)();
        _LoggingSystem_PushLoggingState(a1: 1, a2: 1);
        _LoggingSystem_RegisterLoggingListener(a1: &this->m_BufferedLoggingListener);
        _LoggingSystem_SetLoggingResponsePolicy(a1: &this->m_NonFatalLoggingResponsePolicy);
        this->m_pRenderState = pRenderState;
        this->m_nModulation = i;
        this->m_nRenderPass = 0;
        pRenderState->m_pSnapshots[v36].m_nPassCount = 0;
        pShader->DrawElements(
          this: pShader,
          a2: params,
          a3: i,
          a4: g_pShaderShadow,
          a5: nullptr,
          a6: VERTEX_COMPRESSION_NONE,
          a7: pRenderState->m_pSnapshots[v36].m_pContextData,
          a8: pRenderState->m_pSnapshots[v36].m_pInstanceData);
        _LoggingSystem_PopLoggingState(a1: 1);
        CBufferedLoggingListener::EmitBufferedSpew(this: &this->m_BufferedLoggingListener);
        v10 = i;
        this->m_pRenderState = nullptr;
      }
      ++v36;
      i = ++v10;
    }
    while ( v10 < v35 );
  }
  v23 = params[2];
  if ( bPaint )
    v24 = v23->GetIntValueInternal(this: v23) | 0x800;
  else
    v24 = v23->GetIntValueInternal(this: v23) & 0xFFFFF7FF;
  params[2]->SetIntValue(this: params[2], a2: v24);
  v25 = params[2]->GetIntValueInternal(this: params[2]);
  if ( bEditor )
    v26 = v25 | 0x2000;
  else
    v26 = v25 & 0xFFFFDFFF;
  ((void (__stdcall *)(unsigned int))params[2]->SetIntValue)(a1: v26);
  v27 = params[2]->GetIntValueInternal(this: params[2]);
  if ( bFlashlight )
    v28 = v27 | 0x400;
  else
    v28 = v27 & 0xFFFFFBFF;
  ((void (__stdcall *)(unsigned int))params[2]->SetIntValue)(a1: v28);
  v29 = params[2]->GetIntValueInternal(this: params[2]);
  if ( bGBuffer0 )
    v30 = v29 | 0x100000;
  else
    v30 = v29 & 0xFFEFFFFF;
  ((void (__stdcall *)(unsigned int))params[2]->SetIntValue)(a1: v30);
  v31 = params[2]->GetIntValueInternal(this: params[2]);
  v32 = params[2]->__vftable;
  if ( bGBuffer1 )
    ((void (__stdcall *)(int))v32->SetIntValue)(a1: v31 | 0x200000);
  else
    ((void (__stdcall *)(unsigned int))v32->SetIntValue)(a1: v31 & 0xFFDFFFFF);
}

//------------------------------------------------------------------------------
// Address: 0x100557F0
// Name: private: bool CShaderSystem::ComputeVertexFormatFromSnapshot(class IMaterialVar __near * __near *,struct ShaderRenderState_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderSystem::ComputeVertexFormatFromSnapshot(
        CShaderSystem *this,
        IMaterialVar **params,
        ShaderRenderState_t *pRenderState)
{
  char v4; // al
  int v5; // ecx
  RenderPassList_t *m_pSnapshots; // eax
  int m_nPassCount; // esi
  unsigned __int8 (*CanUseEditorMaterials)(void); // eax
  void *v10; // esp
  RenderPassList_t *v11; // eax
  int v12; // ecx
  int v13; // esi
  __int16 *m_Snapshot; // eax
  RenderPassList_t *v15; // eax
  int v16; // ecx
  __int16 *v17; // eax
  RenderPassList_t *v18; // eax
  int v19; // ecx
  __int16 *v20; // eax
  RenderPassList_t *v21; // ecx
  int v22; // edx
  _WORD *v23; // eax
  __int16 *v24; // ecx
  _WORD v26[6]; // [esp+0h] [ebp-14h] BYREF
  IShaderSystem *v27; // [esp+Ch] [ebp-8h]
  int v28; // [esp+10h] [ebp-4h]
  int numSnapshots; // [esp+20h] [ebp+Ch]

  v4 = g_pInternalMaterialSystem->GetConfigurationFlags(this: g_pInternalMaterialSystem);
  if ( (v4 & 2) != 0 )
  {
    v5 = 64;
    v28 = 64;
  }
  else
  {
    v28 = 8 * ((v4 & 1) != 0) + 8;
    v5 = v28;
  }
  m_pSnapshots = pRenderState->m_pSnapshots;
  m_nPassCount = m_pSnapshots->m_nPassCount;
  numSnapshots = m_pSnapshots->m_nPassCount;
  if ( v5 >= 2 )
  {
    m_nPassCount += m_pSnapshots[2].m_nPassCount;
    numSnapshots = m_nPassCount;
  }
  if ( v5 >= 4 )
  {
    m_nPassCount += m_pSnapshots[4].m_nPassCount;
    numSnapshots = m_nPassCount;
  }
  CanUseEditorMaterials = (unsigned __int8 (*)(void))this->CanUseEditorMaterials;
  v27 = &this->IShaderSystem;
  if ( CanUseEditorMaterials() != 0 )
  {
    m_nPassCount += pRenderState->m_pSnapshots[8].m_nPassCount;
    numSnapshots = m_nPassCount;
  }
  v10 = alloca(2 * m_nPassCount);
  v11 = pRenderState->m_pSnapshots;
  v12 = v11->m_nPassCount;
  v13 = 0;
  if ( v11->m_nPassCount > 0 )
  {
    m_Snapshot = v11->m_Snapshot;
    do
    {
      v26[v13++] = *m_Snapshot++;
      --v12;
    }
    while ( v12 != 0 );
  }
  if ( v28 >= 2 )
  {
    v15 = pRenderState->m_pSnapshots;
    v16 = v15[2].m_nPassCount;
    if ( v16 > 0 )
    {
      v17 = v15[2].m_Snapshot;
      do
      {
        v26[v13++] = *v17++;
        --v16;
      }
      while ( v16 != 0 );
    }
  }
  if ( v28 >= 4 )
  {
    v18 = pRenderState->m_pSnapshots;
    v19 = v18[4].m_nPassCount;
    if ( v19 > 0 )
    {
      v20 = v18[4].m_Snapshot;
      do
      {
        v26[v13++] = *v20++;
        --v19;
      }
      while ( v19 != 0 );
    }
  }
  if ( v27->CanUseEditorMaterials(this: v27) )
  {
    v21 = pRenderState->m_pSnapshots;
    v22 = v21[8].m_nPassCount;
    if ( v22 > 0 )
    {
      v23 = &v26[v13];
      v24 = v21[8].m_Snapshot;
      do
      {
        *v23++ = *v24++;
        --v22;
      }
      while ( v22 != 0 );
    }
  }
  pRenderState->m_VertexUsage = g_pShaderAPI->ComputeVertexUsage(this: g_pShaderAPI, a2: numSnapshots, a3: v26);
  pRenderState->m_VertexFormat = g_pShaderAPI->ComputeVertexFormat(this: g_pShaderAPI, a2: numSnapshots, a3: v26);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10055960
// Name: public: virtual bool CShaderSystem::InitRenderState(class IShader __near *,int,class IMaterialVar __near * __near *,struct ShaderRenderState_t __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderSystem::InitRenderState(
        CShaderSystem *this,
        IShader *pShader,
        int numParams,
        IMaterialVar **params,
        ShaderRenderState_t *pRenderState,
        const char *pMaterialName)
{
  RenderPassList_t *m_pSnapshots; // eax
  const char *v9; // eax
  const char *v11; // eax
  ShaderRenderState_t *pRenderStatea; // [esp+20h] [ebp+14h]

  pRenderState->m_Flags = 0;
  CShaderSystem::InitStateSnapshots(this, a2: (unsigned int)this, pShader, params, pRenderState);
  m_pSnapshots = pRenderState->m_pSnapshots;
  if ( m_pSnapshots->m_nPassCount != 0 )
  {
    pRenderStatea = (ShaderRenderState_t *)(unsigned __int16)m_pSnapshots->m_Snapshot[0];
    if ( g_pShaderAPI->IsTranslucent(this: g_pShaderAPI, a2: (__int16)pRenderStatea) )
    {
      pRenderState->m_Flags |= 0x40u;
    }
    else if ( g_pShaderAPI->IsAlphaTested(this: g_pShaderAPI, a2: (__int16)pRenderStatea) )
    {
      pRenderState->m_Flags |= 0x10u;
    }
    else
    {
      pRenderState->m_Flags |= 0x20u;
    }
    if ( CShaderSystem::ComputeVertexFormatFromSnapshot(this, params, pRenderState) != 0 )
    {
      return 1;
    }
    else
    {
      v11 = (const char *)pShader->GetName(this: pShader);
      _Warning(a1: "Material \"%s\":\n   Shader \"%s\" can't be used with models!\n", pMaterialName, v11);
      this->CleanupRenderState(this, a2: pRenderState);
      return 0;
    }
  }
  else
  {
    v9 = (const char *)pShader->GetName(this: pShader);
    _Warning(a1: "Material \"%s\":\n   No render states in shader \"%s\"\n", pMaterialName, v9);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055A40
// Name: public: virtual void CShaderSystem::CleanupRenderState(struct ShaderRenderState_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderSystem::CleanupRenderState(CShaderSystem *this, ShaderRenderState_t *pRenderState)
{
  ShaderRenderState_t *v2; // esi
  char v3; // al
  int v4; // eax
  int v5; // edi
  int v6; // ebx
  CBasePerInstanceContextData **m_pInstanceData; // esi
  void (__thiscall ***v8)(_DWORD, int); // ecx
  RenderPassList_t *pTemp; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v2 = pRenderState;
  if ( pRenderState != nullptr )
  {
    v3 = g_pInternalMaterialSystem->GetConfigurationFlags(this: g_pInternalMaterialSystem);
    v4 = (v3 & 2) != 0 ? 64 : 8 * ((v3 & 1) != 0) + 8;
    pTemp = pRenderState->m_pSnapshots;
    if ( v4 > 0 )
    {
      v5 = 0;
      for ( i = v4; i != 0; --i )
      {
        v6 = 0;
        if ( v2->m_pSnapshots[v5].m_nPassCount > 0 )
        {
          m_pInstanceData = pTemp[v5].m_pInstanceData;
          do
          {
            v8 = (void (__thiscall ***)(_DWORD, int))*(m_pInstanceData - 3);
            if ( v8 != nullptr )
            {
              (**v8)(a1: v8, a2: 1);
              *(m_pInstanceData - 3) = nullptr;
            }
            if ( *m_pInstanceData != nullptr )
            {
              ((void (__thiscall *)(CBasePerInstanceContextData *, int))(*m_pInstanceData)->dtr_CBasePerInstanceContextData)(
                a1: *m_pInstanceData,
                a2: 1);
              *m_pInstanceData = nullptr;
            }
            ++v6;
            ++m_pInstanceData;
          }
          while ( v6 < pRenderState->m_pSnapshots[v5].m_nPassCount );
          v2 = pRenderState;
        }
        v2->m_pSnapshots[v5++].m_nPassCount = 0;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055B00
// Name: public: virtual bool CShaderSystem::IsUsingGraphics(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CShaderSystem::IsUsingGraphics(CShaderSystem *this)
{
  return LOBYTE(this->m_pDebugMaterials[5]) != 0 || g_pShaderDevice->IsUsingGraphics(this: g_pShaderDevice);
}

//------------------------------------------------------------------------------
// Address: 0x10055B20
// Name: public: virtual bool CShaderSystem::CanUseEditorMaterials(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderSystem::CanUseEditorMaterials(CShaderSystem *this)
{
  return g_pInternalMaterialSystem->GetConfigurationFlags(this: g_pInternalMaterialSystem) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x10055B40
// Name: public: virtual void CShaderSystem::TakeSnapshot(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderSystem::TakeSnapshot(CShaderSystem *this)
{
  _DWORD *v2; // esi

  if ( g_pHardwareConfig->GetDXSupportLevel(this: g_pHardwareConfig) >= 92 )
  {
    g_pShaderShadow->EnableTexture(this: g_pShaderShadow, a2: SHADER_SAMPLER15, a3: true);
    g_pShaderShadow->EnableSRGBRead(this: g_pShaderShadow, a2: SHADER_SAMPLER15, a3: true);
  }
  v2 = (_DWORD *)((char *)this->m_NonFatalLoggingResponsePolicy.__vftable[6].OnLog + 36 * BYTE2(this->m_pRenderState));
  *((_WORD *)v2 + (*v2)++ + 2) = g_pShaderAPI->TakeSnapshot(this: g_pShaderAPI);
}

//------------------------------------------------------------------------------
// Address: 0x10055BB0
// Name: public: virtual void CShaderSystem::DrawSnapshot(unsigned char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderSystem::DrawSnapshot(
        CShaderSystem *this,
        const unsigned __int8 *pInstanceCommandBuffer,
        bool bMakeActualDrawCall)
{
  int v4; // edi

  v4 = *((_DWORD *)this->m_NonFatalLoggingResponsePolicy.__vftable[6].OnLog + 9 * BYTE2(this->m_pRenderState));
  if ( bMakeActualDrawCall )
    g_pShaderAPI->RenderPass(this: g_pShaderAPI, a2: pInstanceCommandBuffer, a3: HIBYTE(this->m_pRenderState), a4: v4);
  g_pShaderAPI->InvalidateDelayedShaderConstants(this: g_pShaderAPI);
  if ( (unsigned __int8)++HIBYTE(this->m_pRenderState) < v4 )
    ((void (__stdcall *)(_DWORD))g_pShaderAPI->BeginPass)(a1: *((unsigned __int16 *)this->m_NonFatalLoggingResponsePolicy.__vftable[6].OnLog
                                                              + 18 * BYTE2(this->m_pRenderState)
                                                              + HIBYTE(this->m_pRenderState)
                                                              + 2));
}

//------------------------------------------------------------------------------
// Address: 0x10055C40
// Name: private: void CShaderSystem::DrawUsingMaterial(class IMaterialInternal __near *,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderSystem::DrawUsingMaterial(
        CShaderSystem *this,
        IMaterialInternal *pMaterial,
        VertexCompressionType_t vertexCompression)
{
  IShader *v5; // ebx
  int v6; // eax
  int v7; // eax
  IShader_vtbl *v8; // [esp+Ch] [ebp-Ch]
  int nMod; // [esp+14h] [ebp-4h]
  int nModa; // [esp+14h] [ebp-4h]
  ShaderRenderState_t *pRenderState; // [esp+20h] [ebp+8h]

  pRenderState = pMaterial->GetRenderState(this: pMaterial);
  g_pShaderAPI->SetDefaultState(this: g_pShaderAPI);
  v5 = pMaterial->GetShader(this: pMaterial);
  nMod = (int)v5->__vftable;
  v6 = ((int (__thiscall *)(IMaterialInternal *, IShaderAPI *))pMaterial->GetShaderParams)(
         a1: pMaterial,
         a2: g_pShaderAPI);
  nModa = (*(int (__thiscall **)(IShader *, int))(nMod + 28))(a1: v5, a2: v6);
  pMaterial->GetShaderParams(this: pMaterial);
  _LoggingSystem_PushLoggingState(a1: 1, a2: 1);
  _LoggingSystem_RegisterLoggingListener(a1: &this->m_BufferedLoggingListener);
  _LoggingSystem_SetLoggingResponsePolicy(a1: &this->m_NonFatalLoggingResponsePolicy);
  this->m_nModulation = nModa;
  this->m_pRenderState = pRenderState;
  this->m_nRenderPass = 0;
  g_pShaderAPI->BeginPass(this: g_pShaderAPI, a2: pRenderState->m_pSnapshots[nModa].m_Snapshot[0]);
  v8 = v5->__vftable;
  v7 = ((int (__thiscall *)(IMaterialInternal *, int, _DWORD, IShaderAPI *, VertexCompressionType_t, CBasePerMaterialContextData **, CBasePerInstanceContextData **))pMaterial->GetShaderParams)(
         a1: pMaterial,
         a2: nModa,
         a3: 0,
         a4: g_pShaderAPI,
         a5: vertexCompression,
         a6: pRenderState->m_pSnapshots[nModa].m_pContextData,
         a7: pRenderState->m_pSnapshots[nModa].m_pInstanceData);
  ((void (__thiscall *)(IShader *, int))v8->DrawElements)(a1: v5, a2: v7);
  _LoggingSystem_PopLoggingState(a1: 1);
  CBufferedLoggingListener::EmitBufferedSpew(this: &this->m_BufferedLoggingListener);
  this->m_pRenderState = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10055D70
// Name: private: void CShaderSystem::CopyMaterialVarToDebugShader(class IMaterialInternal __near *,class IShader __near *,class IMaterialVar __near * __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderSystem::CopyMaterialVarToDebugShader(
        CShaderSystem *this,
        IMaterialInternal *pDebugMaterial,
        IShader *pShader,
        IMaterialVar **ppParams,
        const char *pSrcVarName,
        const char *pDstVarName)
{
  const char *v6; // eax
  IMaterialVar *v7; // ebx
  int v8; // esi
  const char *v9; // eax

  v6 = pDstVarName;
  if ( pDstVarName == nullptr )
    v6 = pSrcVarName;
  v7 = pDebugMaterial->FindVar(this: pDebugMaterial, a2: v6, a3: (char *)&pDstVarName + 3, a4: 1);
  v8 = pShader->GetParamCount(this: pShader) - 1;
  if ( v8 < 0 )
  {
LABEL_6:
    v7->SetUndefined(this: v7);
  }
  else
  {
    while ( 1 )
    {
      v9 = ppParams[v8]->GetName(this: ppParams[v8]);
      if ( _V_stricmp(s1: v9, s2: pSrcVarName) == 0 )
        break;
      if ( --v8 < 0 )
        goto LABEL_6;
    }
    v7->CopyFrom(this: v7, a2: ppParams[v8]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055DF0
// Name: private: void CShaderSystem::DrawMeasureFillRate(struct ShaderRenderState_t __near *,int,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderSystem::DrawMeasureFillRate(
        CShaderSystem *this,
        ShaderRenderState_t *pRenderState,
        int mod,
        VertexCompressionType_t vertexCompression)
{
  IMaterialInternal *v5; // esi
  int m_nPassCount; // ebx
  int v7; // eax

  v5 = this->m_pDebugMaterials[0];
  m_nPassCount = pRenderState->m_pSnapshots[mod].m_nPassCount;
  v7 = (int)v5->FindVar(this: v5, a2: "$passcount", a3: (bool *)&mod + 3, a4: true);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v7 + 20))(a1: v7, a2: m_nPassCount);
  CShaderSystem::DrawUsingMaterial(this, pMaterial: v5, vertexCompression);
}

//------------------------------------------------------------------------------
// Address: 0x10055E40
// Name: private: void CShaderSystem::DrawNormalMap(class IShader __near *,class IMaterialVar __near * __near *,enum VertexCompressionType_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderSystem::DrawNormalMap(
        CShaderSystem *this,
        IShader *pShader,
        IMaterialVar **ppParams,
        VertexCompressionType_t vertexCompression)
{
  IMaterialInternal *v5; // esi
  IMaterialVar **v6; // ebx
  int v7; // eax

  v5 = this->m_pDebugMaterials[1];
  if ( g_config.m_bFastNoBump )
  {
    v7 = (int)v5->FindVar(this: v5, a2: "$bumpmap", a3: (bool *)&pShader + 3, a4: true);
    (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 76))(a1: v7);
  }
  else
  {
    v6 = ppParams;
    CShaderSystem::CopyMaterialVarToDebugShader(
      this,
      pDebugMaterial: v5,
      pShader,
      ppParams,
      pSrcVarName: "$bumpmap",
      pDstVarName: nullptr);
    CShaderSystem::CopyMaterialVarToDebugShader(
      this,
      pDebugMaterial: v5,
      pShader,
      ppParams: v6,
      pSrcVarName: "$bumpframe",
      pDstVarName: nullptr);
    CShaderSystem::CopyMaterialVarToDebugShader(
      this,
      pDebugMaterial: v5,
      pShader,
      ppParams: v6,
      pSrcVarName: "$bumptransform",
      pDstVarName: nullptr);
  }
  CShaderSystem::DrawUsingMaterial(this, pMaterial: v5, vertexCompression);
}

//------------------------------------------------------------------------------
// Address: 0x10055EE0
// Name: public: virtual int CShaderSystem::GetShaderAPITextureBindHandle(class ITexture __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderSystem::GetShaderAPITextureBindHandle(
        CShaderSystem *this,
        ITexture *pTexture,
        int nFrame,
        int nTextureChannel)
{
  if ( pTexture != nullptr )
    return ((int (__thiscall *)(ITexture *, int, int))pTexture->__vftable[1].SetTextureRegenerator)(
             a1: pTexture,
             a2: nFrame,
             a3: nTextureChannel);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10055F10
// Name: public: virtual void CShaderSystem::BindTexture(enum Sampler_t,enum TextureBindFlags_t,class ITexture __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderSystem::BindTexture(
        CShaderSystem *this,
        Sampler_t sampler1,
        TextureBindFlags_t nBindFlags,
        ITexture *pTexture,
        int nFrame)
{
  if ( pTexture != nullptr )
    ((void (__thiscall *)(ITexture *, Sampler_t, TextureBindFlags_t, int, int))pTexture->__vftable[1].GetName)(
      a1: pTexture,
      a2: sampler1,
      a3: nBindFlags,
      a4: nFrame,
      a5: -1);
}

//------------------------------------------------------------------------------
// Address: 0x10055F40
// Name: public: virtual void CShaderSystem::BindTexture(enum Sampler_t,enum Sampler_t,enum TextureBindFlags_t,class ITexture __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderSystem::BindTexture(
        CShaderSystem *this,
        Sampler_t sampler1,
        Sampler_t sampler2,
        TextureBindFlags_t nBindFlags,
        ITexture *pTexture,
        int nFrame)
{
  if ( pTexture != nullptr )
  {
    if ( sampler2 == SHADER_SAMPLER_INVALID )
      ((void (__stdcall *)(Sampler_t, TextureBindFlags_t, int, int))pTexture->__vftable[1].GetName)(
        a1: sampler1,
        a2: nBindFlags,
        a3: nFrame,
        a4: -1);
    else
      ((void (__stdcall *)(Sampler_t, TextureBindFlags_t, int, Sampler_t))pTexture->__vftable[1].GetName)(
        a1: sampler1,
        a2: nBindFlags,
        a3: nFrame,
        a4: sampler2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10055F90
// Name: public: virtual void CShaderSystem::BindVertexTexture(enum VertexTextureSampler_t,class ITexture __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderSystem::BindVertexTexture(
        CShaderSystem *this,
        VertexTextureSampler_t vtSampler,
        ITexture *pTexture,
        int nFrame)
{
  if ( pTexture != nullptr )
    ((void (__thiscall *)(ITexture *, VertexTextureSampler_t, int))pTexture->__vftable[1].GetApproximateVidMemBytes)(
      a1: pTexture,
      a2: vtSampler,
      a3: nFrame);
}

//------------------------------------------------------------------------------
// Address: 0x10055FB0
// Name: public: virtual void CShaderSystem::LoadTexture(class IMaterialVar __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderSystem::LoadTexture(
        CShaderSystem *this,
        IMaterialVar *pTextureVar,
        const char *pTextureGroupName,
        int nAdditionalCreationFlags)
{
  char v4; // al
  IMaterialVar_vtbl *v6; // esi
  ITextureInternal *v7; // eax
  const char *v8; // eax
  const char *v9; // esi
  ITextureInternal *v10; // eax

  v4 = *((_BYTE *)pTextureVar + 28) & 0xF;
  if ( v4 == 1 )
  {
    v8 = pTextureVar->GetStringValue(this: pTextureVar);
    v9 = v8;
    if ( *v8 == 92 || v8[1] == 92 )
      v9 = v8 + 1;
    if ( !this->CanUseEditorMaterials(this: &this->IShaderSystem) || _V_stricmp(s1: v9, s2: "env_cubemap") != 0 )
    {
      v10 = g_pTextureManager->FindOrLoadTexture(
              this: g_pTextureManager,
              a2: v9,
              a3: pTextureGroupName,
              a4: nAdditionalCreationFlags);
      if ( v10 == nullptr )
      {
        if ( !g_pShaderDevice->IsUsingGraphics(this: g_pShaderDevice) && _V_stricmp(s1: v9, s2: "env_cubemap") != 0 )
          _Warning(a1: "Shader_t::LoadTexture: texture \"%s.vtf\" doesn't exist\n", v9);
        v10 = g_pTextureManager->ErrorTexture(this: g_pTextureManager);
      }
      pTextureVar->SetTextureValue(this: pTextureVar, a2: v10);
    }
    else
    {
      pTextureVar->SetTextureValue(this: pTextureVar, a2: (ITexture *)-1);
    }
  }
  else if ( v4 != 3 )
  {
    v6 = pTextureVar->__vftable;
    v7 = g_pTextureManager->ErrorTexture(this: g_pTextureManager);
    v6->SetTextureValue(this: pTextureVar, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100560A0
// Name: public: virtual void CShaderSystem::LoadBumpMap(class IMaterialVar __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderSystem::LoadBumpMap(
        CShaderSystem *this,
        IMaterialVar *pTextureVar,
        const char *pTextureGroupName,
        int nAdditionalCreationFlags)
{
  char v4; // al
  IMaterialVar_vtbl *v5; // edi
  ITextureInternal *v6; // eax
  ITextureManager *v7; // edi
  ITextureManager_vtbl *v8; // ebx
  int v9; // eax
  ITextureInternal *v10; // eax

  v4 = *((_BYTE *)pTextureVar + 28) & 0xF;
  if ( v4 == 1 )
  {
    v7 = g_pTextureManager;
    v8 = g_pTextureManager->__vftable;
    v9 = ((int (__thiscall *)(IMaterialVar *, const char *, int))pTextureVar->GetStringValue)(
           a1: pTextureVar,
           a2: pTextureGroupName,
           a3: nAdditionalCreationFlags);
    v10 = (ITextureInternal *)((int (__thiscall *)(ITextureManager *, int))v8->FindOrLoadTexture)(a1: v7, a2: v9);
    if ( v10 == nullptr )
      v10 = g_pTextureManager->ErrorTexture(this: g_pTextureManager);
    pTextureVar->SetTextureValue(this: pTextureVar, a2: v10);
  }
  else if ( v4 != 3 )
  {
    v5 = pTextureVar->__vftable;
    v6 = g_pTextureManager->ErrorTexture(this: g_pTextureManager);
    v5->SetTextureValue(this: pTextureVar, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10056120
// Name: public: virtual void CShaderSystem::LoadCubeMap(class IMaterialVar __near * __near *,class IMaterialVar __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderSystem::LoadCubeMap(
        CShaderSystem *this,
        IMaterialVar **ppParams,
        IMaterialVar *pTextureVar,
        int nAdditionalCreationFlags)
{
  char v4; // al
  IMaterialVar_vtbl *v5; // edi
  ITextureInternal *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  ITextureInternal *v9; // eax
  char textureName[260]; // [esp+4h] [ebp-104h] BYREF

  v4 = *((_BYTE *)pTextureVar + 28) & 0xF;
  if ( v4 == 1 )
  {
    v7 = pTextureVar->GetStringValue(this: pTextureVar);
    if ( _V_stricmp(s1: v7, s2: "env_cubemap") != 0 )
    {
      v8 = pTextureVar->GetStringValue(this: pTextureVar);
      V_strncpy(pDest: textureName, pSrc: v8, maxLen: 260);
      if ( g_pHWConfig->GetHDRType(this: g_pHWConfig) != HDR_TYPE_NONE )
        V_strncat(pDest: textureName, pSrc: ".hdr", destBufferSize: 0x104u, max_chars_to_copy: -1);
      v9 = g_pTextureManager->FindOrLoadTexture(
             this: g_pTextureManager,
             a2: textureName,
             a3: "CubeMap textures",
             a4: nAdditionalCreationFlags);
      if ( v9 == nullptr )
        v9 = g_pTextureManager->ErrorTexture(this: g_pTextureManager);
      pTextureVar->SetTextureValue(this: pTextureVar, a2: v9);
    }
    else
    {
      pTextureVar->SetTextureValue(this: pTextureVar, a2: (ITexture *)-1);
      ((void (__stdcall *)(int))ppParams[2]->SetIntValue)(a1: ppParams[2]->m_intVal | 0x20);
    }
  }
  else if ( v4 != 3 )
  {
    v5 = pTextureVar->__vftable;
    v6 = g_pTextureManager->ErrorTexture(this: g_pTextureManager);
    v5->SetTextureValue(this: pTextureVar, a2: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10056230
// Name: public: virtual void CShaderSystem::AddShaderComboInformation(struct ShaderComboSemantics_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderSystem::AddShaderComboInformation(CShaderSystem *this, const ShaderComboSemantics_t *pSemantics)
{
  g_pShaderAPI->AddShaderComboInformation(this: g_pShaderAPI, a2: pSemantics);
}

//------------------------------------------------------------------------------
// Address: 0x10056250
// Name: public: virtual enum LoggingResponse_t CNonFatalLoggingResponsePolicy::OnLog(struct LoggingContext_t const __near *)
// Source: json
//------------------------------------------------------------------------------
LoggingResponse_t __thiscall CNonFatalLoggingResponsePolicy::OnLog(
        CNonFatalLoggingResponsePolicy *this,
        const LoggingContext_t *pContext)
{
  int v2; // eax
  LoggingResponse_t result; // eax

  result = pContext->m_Severity == LS_ASSERT
        && (v2 = _CommandLine(a1: this),
            (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-noassert") == 0)
        || pContext->m_Severity == LS_ERROR;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10056290
// Name: public: virtual void CShaderSystem::ModInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderSystem::ModInit(CShaderSystem *this)
{
  int v2; // eax

  v2 = g_pHWConfig->GetMaxDXSupportLevel(this: g_pHWConfig);
  CShaderSystem::LoadModShaderDLLs(this, dxSupportLevel: v2 / 10);
}

//------------------------------------------------------------------------------
// Address: 0x100562C0
// Name: public: virtual void CShaderSystem::DrawElements(class IShader __near *,class IMaterialVar __near * __near *,struct ShaderRenderState_t __near *,enum VertexCompressionType_t,unsigned int,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderSystem::DrawElements(
        CShaderSystem *this,
        IShader *pShader,
        IMaterialVar **params,
        ShaderRenderState_t *pRenderState,
        VertexCompressionType_t vertexCompression,
        unsigned int nMaterialVarChangeTimeStamp,
        int nModulationFlags,
        bool bRenderingPreTessPatchMesh)
{
  unsigned int v9; // ebx
  __int16 v10; // ax
  IMaterialVar **v11; // ecx
  RenderPassList_t *m_pSnapshots; // edx
  CBasePerMaterialContextData *v13; // ecx
  CBasePerMaterialContextData **m_pContextData; // eax
  __int16 materialVarFlags; // [esp+28h] [ebp+1Ch]

  g_pShaderAPI->InvalidateDelayedShaderConstants(this: g_pShaderAPI);
  v9 = nModulationFlags | pShader->ComputeModulationFlags(this: pShader, a2: params, a3: g_pShaderAPI);
  if ( pRenderState->m_pSnapshots[v9].m_nPassCount != 0 )
  {
    v10 = (*params)->GetIntValueInternal(this: *params);
    materialVarFlags = v10;
    if ( (g_config.bMeasureFillRate || g_config.bVisualizeFillRate) && (v10 & 8) == 0 )
    {
      CShaderSystem::DrawMeasureFillRate(this, pRenderState, mod: v9, vertexCompression);
LABEL_11:
      g_pInternalMaterialSystem->ForceDepthFuncEquals(this: g_pInternalMaterialSystem, a2: false);
      return;
    }
    if ( g_config.bShowNormalMap || g_config.nShowMipLevels == 2 )
    {
      v11 = params;
      if ( (params[2]->m_intVal & 8) != 0 || (params[2]->m_intVal & 0x10) != 0 )
      {
        CShaderSystem::DrawNormalMap(this, pShader, ppParams: params, vertexCompression);
        goto LABEL_11;
      }
    }
    else
    {
      v11 = params;
    }
    if ( !bRenderingPreTessPatchMesh || (v11[2]->m_intVal & 0x800000) != 0 )
    {
      g_pShaderAPI->SetDefaultState(this: g_pShaderAPI);
      if ( (materialVarFlags & 0x1000) != 0 )
        g_pShaderAPI->ShadeMode(this: g_pShaderAPI, a2: SHADER_FLAT);
      _LoggingSystem_PushLoggingState(a1: 1, a2: 1);
      _LoggingSystem_RegisterLoggingListener(a1: &this->m_BufferedLoggingListener);
      _LoggingSystem_SetLoggingResponsePolicy(a1: &this->m_NonFatalLoggingResponsePolicy);
      this->m_pRenderState = pRenderState;
      this->m_nModulation = v9;
      this->m_nRenderPass = 0;
      ((void (__stdcall *)(_DWORD))g_pShaderAPI->BeginPass)(a1: (unsigned __int16)pRenderState->m_pSnapshots[(unsigned __int8)v9].m_Snapshot[0]);
      m_pSnapshots = this->m_pRenderState->m_pSnapshots;
      v13 = m_pSnapshots[this->m_nModulation].m_pContextData[0];
      m_pContextData = m_pSnapshots[this->m_nModulation].m_pContextData;
      if ( v13 != nullptr && v13->m_nVarChangeID != nMaterialVarChangeTimeStamp )
      {
        v13->m_bMaterialVarsChanged = true;
        (*m_pContextData)->m_nVarChangeID = nMaterialVarChangeTimeStamp;
      }
      pShader->DrawElements(
        this: pShader,
        a2: params,
        a3: v9,
        a4: nullptr,
        a5: g_pShaderAPI,
        a6: vertexCompression,
        a7: m_pContextData,
        a8: this->m_pRenderState->m_pSnapshots[this->m_nModulation].m_pInstanceData);
      _LoggingSystem_PopLoggingState(a1: 1);
      CBufferedLoggingListener::EmitBufferedSpew(this: &this->m_BufferedLoggingListener);
      this->m_pRenderState = nullptr;
    }
    else
    {
      _Warning(a1: "Warning error: CShaderSystem::DrawElements: Mesh supports tessellation, but material does not.\n");
      CShaderSystem::DrawUsingMaterial(this, pMaterial: g_pErrorMaterial, vertexCompression);
    }
    goto LABEL_11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100564C0
// Name: public: void CUtlMemory<struct CShaderSystem::ShaderDLLInfo_t,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int>::Grow(
        CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CShaderSystem::ShaderDLLInfo_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 1;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 48 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CShaderSystem::ShaderDLLInfo_t *)_g_pMemAlloc->Realloc_2(
                                                            this: _g_pMemAlloc,
                                                            a2: m_pMemory,
                                                            a3: v7);
    else
      this->m_pMemory = (CShaderSystem::ShaderDLLInfo_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10056560
// Name: private: int CShaderSystem::FindShaderDLL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderSystem::FindShaderDLL(CShaderSystem *this, const char *pFullPath)
{
  int v3; // esi
  int i; // edi

  v3 = this->m_ShaderDLLs.m_Size - 1;
  if ( v3 < 0 )
    return -1;
  for ( i = v3; _V_stricmp(s1: pFullPath, s2: this->m_ShaderDLLs.m_Memory.m_pMemory[i].m_pFileName) != 0; --i )
  {
    if ( --v3 < 0 )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100565B0
// Name: private: void CShaderSystem::UnloadShaderDLL(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderSystem::UnloadShaderDLL(CShaderSystem *this, int nShaderDLLIndex)
{
  int v3; // esi
  IShaderDLLInternal *m_pShaderDLL; // edi
  IShaderDLLInternal *ShaderDLLInternal; // eax
  struct CSysModule *m_hInstance; // esi
  int nShaderDLLIndexa; // [esp+Ch] [ebp+8h]

  if ( nShaderDLLIndex >= 0 )
  {
    v3 = nShaderDLLIndex;
    m_pShaderDLL = this->m_ShaderDLLs.m_Memory.m_pMemory[nShaderDLLIndex].m_pShaderDLL;
    nShaderDLLIndexa = (int)m_pShaderDLL->__vftable;
    ShaderDLLInternal = GetShaderDLLInternal();
    (*(void (__thiscall **)(IShaderDLLInternal *, bool))(nShaderDLLIndexa + 4))(
      a1: m_pShaderDLL,
      a2: m_pShaderDLL == ShaderDLLInternal);
    m_hInstance = this->m_ShaderDLLs.m_Memory.m_pMemory[v3].m_hInstance;
    if ( m_hInstance != nullptr )
      g_pFullFileSystem->UnloadModule(this: g_pFullFileSystem, a2: m_hInstance);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057590
// Name: public: virtual class IShader __near * CShaderSystem::FindShader(char const __near *)
// Source: json
//------------------------------------------------------------------------------
IShader *__thiscall CShaderSystem::FindShader(CShaderSystem *this, const char *pShaderName)
{
  int v2; // edi
  int i; // ebx
  CShaderSystem::ShaderDLLInfo_t *m_pMemory; // esi
  unsigned __int16 v5; // ax
  CUtlMap<char const *,IShader *,unsigned short>::Node_t search; // [esp+Ch] [ebp-Ch] BYREF
  CShaderSystem *v8; // [esp+14h] [ebp-4h]

  v2 = this->m_ShaderDLLs.m_Size - 1;
  v8 = this;
  if ( v2 < 0 )
    return nullptr;
  for ( i = v2; ; --i )
  {
    m_pMemory = this->m_ShaderDLLs.m_Memory.m_pMemory;
    if ( pShaderName != nullptr )
      break;
LABEL_6:
    if ( --v2 < 0 )
      return nullptr;
  }
  search.key = pShaderName;
  v5 = CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &m_pMemory[i].m_ShaderDict.m_Elements.m_Tree,
         &search);
  if ( v5 == 0xFFFF )
  {
    this = v8;
    goto LABEL_6;
  }
  return m_pMemory[i].m_ShaderDict.m_Elements.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x10057600
// Name: public: virtual int CShaderSystem::GetShaders(int,int,class IShader __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CShaderSystem::GetShaders(CShaderSystem *this, int nFirstShader, int nMaxCount, IShader **ppShaderList)
{
  CShaderSystem *v4; // ebx
  int v5; // esi
  int v6; // edi
  char *v7; // ebx
  int Inorder; // eax
  int v9; // esi
  const char *v10; // edi
  IShader *v11; // edx
  int v12; // esi
  int v13; // esi
  unsigned __int16 v14; // ax
  CUtlSymbolTable uniqueNames; // [esp+Ch] [ebp-60h] BYREF
  CShaderSystem *v17; // [esp+44h] [ebp-28h]
  int v18; // [esp+48h] [ebp-24h]
  int i; // [esp+4Ch] [ebp-20h]
  int nActualCount; // [esp+50h] [ebp-1Ch]
  int j; // [esp+54h] [ebp-18h]
  int nCount; // [esp+58h] [ebp-14h]
  CUtlSymbol v23; // [esp+5Ch] [ebp-10h] BYREF
  CUtlSymbol v24; // [esp+5Eh] [ebp-Eh] BYREF
  int v25; // [esp+68h] [ebp-4h]

  v4 = this;
  v17 = this;
  CUtlSymbolTable::CUtlSymbolTable(this: &uniqueNames, growSize: 0, initSize: 512, caseInsensitive: true);
  v25 = 0;
  nCount = 0;
  nActualCount = 0;
  v5 = v4->m_ShaderDLLs.m_Size - 1;
  i = v5;
  if ( v5 < 0 )
  {
LABEL_16:
    v25 = -1;
    CUtlSymbolTable::~CUtlSymbolTable(this: &uniqueNames);
    return nCount;
  }
  else
  {
    v6 = 48 * v5;
    v18 = 48 * v5;
    while ( 1 )
    {
      v7 = (char *)v4->m_ShaderDLLs.m_Memory.m_pMemory + v6;
      Inorder = (unsigned __int16)CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: (CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(v7 + 20));
      j = Inorder;
      if ( (_WORD)Inorder != 0xFFFF )
        break;
LABEL_15:
      --v5;
      v6 -= 48;
      i = v5;
      v18 = v6;
      if ( v5 < 0 )
        goto LABEL_16;
      v4 = v17;
    }
    while ( 1 )
    {
      v9 = 2 * (unsigned __int16)Inorder;
      v10 = *(const char **)(*((_DWORD *)v7 + 6) + 16 * (unsigned __int16)Inorder + 8);
      if ( CUtlSymbolTable::Find(this: &uniqueNames, result: &v24, pString: v10)->m_Id == 0xFFFF )
      {
        CUtlSymbolTable::AddString(this: &uniqueNames, result: &v23, pString: v10);
        if ( ++nActualCount > nFirstShader )
        {
          if ( ppShaderList != nullptr )
          {
            v11 = *(IShader **)(*((_DWORD *)v7 + 6) + 8 * v9 + 12);
            v12 = nCount;
            ppShaderList[nCount] = v11;
          }
          else
          {
            v12 = nCount;
          }
          v13 = v12 + 1;
          nCount = v13;
          if ( v13 >= nMaxCount )
            break;
        }
      }
      v14 = CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: (CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(v7 + 20),
              i: j);
      j = v14;
      if ( v14 == 0xFFFF )
      {
        v5 = i;
        v6 = v18;
        goto LABEL_15;
      }
      LOWORD(Inorder) = j;
    }
    v25 = -1;
    CUtlSymbolTable::~CUtlSymbolTable(this: &uniqueNames);
    return v13;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057780
// Name: struct CShaderSystem::ShaderDLLInfo_t __near * Construct<struct CShaderSystem::ShaderDLLInfo_t>(struct CShaderSystem::ShaderDLLInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
CShaderSystem::ShaderDLLInfo_t *__cdecl Construct<CShaderSystem::ShaderDLLInfo_t>(
        CShaderSystem::ShaderDLLInfo_t *pMemory)
{
  CShaderSystem::ShaderDLLInfo_t *result; // eax

  result = pMemory;
  if ( pMemory == nullptr )
    return nullptr;
  pMemory->m_ShaderDict.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  pMemory->m_ShaderDict.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  pMemory->m_ShaderDict.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  pMemory->m_ShaderDict.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  pMemory->m_ShaderDict.m_Elements.m_Tree.m_Root = -1;
  pMemory->m_ShaderDict.m_Elements.m_Tree.m_NumElements = 0;
  pMemory->m_ShaderDict.m_Elements.m_Tree.m_FirstFree = -1;
  pMemory->m_ShaderDict.m_Elements.m_Tree.m_LastAlloc.index = -1;
  pMemory->m_ShaderDict.m_Elements.m_Tree.m_pElements = pMemory->m_ShaderDict.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( pMemory->m_ShaderDict.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    pMemory->m_ShaderDict.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10057800
// Name: private: void CShaderSystem::SetupShaderDictionary(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderSystem::SetupShaderDictionary(CShaderSystem *this, int nShaderDLLIndex)
{
  CShaderSystem::ShaderDLLInfo_t *v2; // edi
  IShaderDLLInternal *m_pShaderDLL; // ecx
  int (__thiscall *ShaderComboSemanticsCount)(IShaderDLLInternal *); // edx
  int v5; // esi
  const ShaderComboSemantics_t *v6; // eax
  CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> > *p_m_Tree; // ebx
  IShader *v8; // eax
  IShader_vtbl *v9; // edx
  const char *v10; // esi
  CShaderSystem *v11; // eax
  char *v12; // eax
  char *v13; // eax
  unsigned __int16 v14; // ax
  unsigned __int16 v15; // dx
  unsigned __int16 v16; // cx
  int v17; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short> *v18; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  int v20; // edx
  UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short> *v21; // ecx
  CUtlMap<char const *,IShader *,unsigned short>::Node_t search; // [esp+8h] [ebp-28h] BYREF
  CUtlMap<char const *,IShader *,unsigned short>::Node_t insert; // [esp+10h] [ebp-20h] BYREF
  int nCount; // [esp+18h] [ebp-18h]
  IShader *pShader; // [esp+1Ch] [ebp-14h]
  CShaderSystem::ShaderDLLInfo_t *info; // [esp+20h] [ebp-10h]
  CShaderSystem *v27; // [esp+24h] [ebp-Ch]
  int iTestDLL; // [esp+28h] [ebp-8h] BYREF
  int i; // [esp+2Ch] [ebp-4h]

  v2 = &this->m_ShaderDLLs.m_Memory.m_pMemory[nShaderDLLIndex];
  v27 = this;
  m_pShaderDLL = v2->m_pShaderDLL;
  ShaderComboSemanticsCount = m_pShaderDLL->ShaderComboSemanticsCount;
  info = v2;
  v5 = 0;
  if ( ShaderComboSemanticsCount(this: m_pShaderDLL) > 0 )
  {
    do
    {
      v6 = v2->m_pShaderDLL->GetComboSemantics(this: v2->m_pShaderDLL, a2: v5);
      g_pShaderAPI->AddShaderComboInformation(this: g_pShaderAPI, a2: v6);
      ++v5;
    }
    while ( v5 < v2->m_pShaderDLL->ShaderComboSemanticsCount(this: v2->m_pShaderDLL) );
  }
  nCount = v2->m_pShaderDLL->ShaderCount(this: v2->m_pShaderDLL);
  i = 0;
  if ( nCount > 0 )
  {
    p_m_Tree = &v2->m_ShaderDict.m_Elements.m_Tree;
    while ( 1 )
    {
      v8 = v2->m_pShaderDLL->GetShader(this: v2->m_pShaderDLL, a2: i);
      v9 = v8->__vftable;
      pShader = v8;
      v10 = v9->GetName(this: v8);
      if ( v2->m_bModShaderDLL )
      {
        v11 = v27;
        iTestDLL = 0;
        if ( v27->m_ShaderDLLs.m_Size > 0 )
        {
          nShaderDLLIndex = 0;
          do
          {
            v12 = (char *)v11->m_ShaderDLLs.m_Memory.m_pMemory + nShaderDLLIndex;
            if ( v12[16] == 0 && v10 != nullptr )
            {
              search.key = v10;
              if ( CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                     this: (CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(v12 + 20),
                     &search) != 0xFFFF )
                _Error(a1: "Game shader '%s' trying to override a base shader '%s'.", v2->m_pFileName, v10);
            }
            v11 = v27;
            nShaderDLLIndex += 48;
            ++iTestDLL;
          }
          while ( iTestDLL < v27->m_ShaderDLLs.m_Size );
        }
      }
      if ( v10 != nullptr && (v13 = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: strlen(v10) + 1)) != nullptr )
        strcpy(v13, v10);
      else
        v13 = nullptr;
      insert.key = v13;
      insert.elem = pShader;
      iTestDLL = 0xFFFF;
      HIBYTE(nShaderDLLIndex) = 0;
      CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: p_m_Tree,
        &insert,
        parent: (unsigned __int16 *)&iTestDLL,
        leftchild: (bool *)&nShaderDLLIndex + 3);
      v14 = CUtlRBTree<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,ITextureInternal *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ITextureInternal *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: p_m_Tree);
      v15 = iTestDLL;
      v16 = v14;
      v17 = v14;
      v18 = &p_m_Tree->m_Elements.m_pMemory[v17];
      v18->m_Right = -1;
      v18->m_Left = -1;
      v18->m_Parent = v15;
      v18->m_Tag = 0;
      if ( v15 == 0xFFFF )
      {
        p_m_Tree->m_Root = v16;
      }
      else
      {
        m_pMemory = p_m_Tree->m_Elements.m_pMemory;
        v20 = v15;
        if ( HIBYTE(nShaderDLLIndex) != 0 )
          m_pMemory[v20].m_Left = v16;
        else
          m_pMemory[v20].m_Right = v16;
      }
      CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        this: p_m_Tree,
        elem: v16);
      v21 = p_m_Tree->m_Elements.m_pMemory;
      ++p_m_Tree->m_NumElements;
      if ( &v21[v17] != (UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short> *)-8 )
        v21[v17].m_Data = insert;
      if ( ++i >= nCount )
        break;
      v2 = info;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057A00
// Name: public: int CUtlVector<struct CShaderSystem::ShaderDLLInfo_t,class CUtlMemory<struct CShaderSystem::ShaderDLLInfo_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int>>::InsertBefore(
        CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CShaderSystem::ShaderDLLInfo_t *m_pMemory; // ecx
  int v6; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 48 * v6);
  Construct<CShaderSystem::ShaderDLLInfo_t>(pMemory: &this->m_Memory.m_pMemory[elem]);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10057A70
// Name: public: virtual bool CShaderSystem::LoadShaderDLL(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CShaderSystem::LoadShaderDLL(
        CShaderSystem *this,
        const char *pFullPath,
        const char *pPathID,
        bool bModShaderDLL)
{
  struct CSysModule *v6; // eax
  struct CSysModule *v7; // ebx
  void *(__cdecl *Factory)(const char *, int *); // eax
  const char **v9; // esi
  void *(__cdecl *FactoryThis)(const char *, int *); // eax
  int ShaderDLL; // eax
  int v12; // esi
  int v13; // ebx
  int v14; // eax
  IShaderDLLInternal *pShaderDLL; // [esp+4h] [ebp-Ch]
  struct CSysModule *bValidatedDllOnly; // [esp+Ch] [ebp-4h]
  const char *pPathIDa; // [esp+1Ch] [ebp+Ch]

  if ( pFullPath == nullptr && MEMORY[0] == 0 )
    return 1;
  v6 = g_pFullFileSystem->LoadModule(this: g_pFullFileSystem, a2: pFullPath, a3: pPathID, a4: !bModShaderDLL);
  v7 = v6;
  bValidatedDllOnly = v6;
  if ( v6 == nullptr )
    return 0;
  Factory = Sys_GetFactory(pModule: v6);
  if ( Factory != nullptr )
  {
    v9 = (const char **)Factory(a1: "ShaderDLL004", a2: nullptr);
    pShaderDLL = (IShaderDLLInternal *)v9;
    if ( v9 != nullptr )
    {
      if ( !bModShaderDLL )
        CShaderSystem::VerifyBaseShaderDLL(this, pModule: v7);
      pPathIDa = *v9;
      FactoryThis = Sys_GetFactoryThis();
      if ( (*(unsigned __int8 (__thiscall **)(const char **, void *(__cdecl *)(const char *, int *), _DWORD))pPathIDa)(
             a1: v9,
             a2: FactoryThis,
             a3: 0) != 0 )
      {
        ShaderDLL = CShaderSystem::FindShaderDLL(this, pFullPath);
        v12 = ShaderDLL;
        if ( ShaderDLL < 0 )
        {
          v12 = CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int>>::InsertBefore(
                  this: &this->m_ShaderDLLs,
                  elem: this->m_ShaderDLLs.m_Size);
          v13 = _V_strlen(str: pFullPath) + 1;
          this->m_ShaderDLLs.m_Memory.m_pMemory[v12].m_pFileName = (char *)MemAlloc_Alloc(nSize: v13);
          V_strncpy(pDest: this->m_ShaderDLLs.m_Memory.m_pMemory[v12].m_pFileName, pSrc: pFullPath, maxLen: v13);
          v7 = bValidatedDllOnly;
        }
        else
        {
          CShaderSystem::UnloadShaderDLL(this, nShaderDLLIndex: ShaderDLL);
        }
        v14 = v12;
        this->m_ShaderDLLs.m_Memory.m_pMemory[v14].m_hInstance = v7;
        this->m_ShaderDLLs.m_Memory.m_pMemory[v14].m_pShaderDLL = pShaderDLL;
        this->m_ShaderDLLs.m_Memory.m_pMemory[v14].m_bModShaderDLL = bModShaderDLL;
        CShaderSystem::SetupShaderDictionary(this, nShaderDLLIndex: v12);
        return 1;
      }
    }
  }
  g_pFullFileSystem->UnloadModule(this: g_pFullFileSystem, a2: v7);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10057BB0
// Name: public: void CUtlVector<struct CShaderSystem::ShaderDLLInfo_t,class CUtlMemory<struct CShaderSystem::ShaderDLLInfo_t,int>>::Remove(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int>>::Remove(
        CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *this,
        int elem)
{
  int v4; // edi
  CUtlDict<IShader *,unsigned short> *elema; // [esp+20h] [ebp+8h]

  v4 = elem;
  elema = &this->m_Memory.m_pMemory[elem].m_ShaderDict;
  CUtlDict<IShader *,unsigned short>::RemoveAll(this: elema);
  CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short>>::~CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short>>(this: &elema->m_Elements.m_Tree);
  if ( this->m_Size - elem - 1 > 0 )
    _V_memmove(
      dest: &this->m_Memory.m_pMemory[v4],
      src: &this->m_Memory.m_pMemory[v4 + 1],
      count: 48 * (this->m_Size - elem - 1));
  --this->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10057C40
// Name: public: void CUtlVector<struct CShaderSystem::ShaderDLLInfo_t,class CUtlMemory<struct CShaderSystem::ShaderDLLInfo_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int>>::RemoveAll(
        CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *this)
{
  int v1; // ebx
  int v2; // ebx
  CUtlDict<IShader *,unsigned short> *p_m_ShaderDict; // esi
  CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *v4; // [esp+8h] [ebp-14h]
  int i; // [esp+Ch] [ebp-10h]

  v1 = this->m_Size - 1;
  v4 = this;
  i = v1;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = v1;
    do
    {
      p_m_ShaderDict = &this->m_Memory.m_pMemory[v2].m_ShaderDict;
      CUtlDict<IShader *,unsigned short>::RemoveAll(this: p_m_ShaderDict);
      CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &p_m_ShaderDict->m_Elements.m_Tree);
      p_m_ShaderDict->m_Elements.m_Tree.m_FirstFree = -1;
      if ( p_m_ShaderDict->m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 )
      {
        if ( p_m_ShaderDict->m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_ShaderDict->m_Elements.m_Tree.m_Elements.m_pMemory);
          p_m_ShaderDict->m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
        }
        p_m_ShaderDict->m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
      }
      p_m_ShaderDict->m_Elements.m_Tree.m_LastAlloc.index = -1;
      if ( p_m_ShaderDict->m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 )
      {
        if ( p_m_ShaderDict->m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_ShaderDict->m_Elements.m_Tree.m_Elements.m_pMemory);
          p_m_ShaderDict->m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
        }
        p_m_ShaderDict->m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
      }
      this = v4;
      --v2;
      --i;
    }
    while ( i >= 0 );
    v4->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057D40
// Name: public: virtual void CShaderSystem::ModShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderSystem::ModShutdown(CShaderSystem *this)
{
  int v2; // ecx
  int v3; // edi
  CShaderSystem::ShaderDLLInfo_t *m_pMemory; // eax
  IShaderDLLInternal *v5; // esi
  IShaderDLLInternal_vtbl *v6; // edi
  IShaderDLLInternal *ShaderDLLInternal; // eax
  struct CSysModule *v8; // eax
  CUtlDict<IShader *,unsigned short> *v9; // esi
  int i; // [esp+4h] [ebp-14h]
  int v11; // [esp+8h] [ebp-10h]

  v2 = this->m_ShaderDLLs.m_Size - 1;
  i = v2;
  if ( v2 >= 0 )
  {
    v3 = 48 * v2;
    v11 = 48 * v2;
    do
    {
      m_pMemory = this->m_ShaderDLLs.m_Memory.m_pMemory;
      if ( *(&m_pMemory->m_bModShaderDLL + v3) )
      {
        v5 = *(IShaderDLLInternal **)((char *)&m_pMemory->m_pShaderDLL + v3);
        v6 = v5->__vftable;
        ShaderDLLInternal = GetShaderDLLInternal();
        v6->Disconnect(this: v5, a2: v5 == ShaderDLLInternal);
        v8 = *(struct CSysModule **)((char *)&this->m_ShaderDLLs.m_Memory.m_pMemory->m_hInstance + v11);
        if ( v8 != nullptr )
          g_pFullFileSystem->UnloadModule(this: g_pFullFileSystem, a2: v8);
        v3 = v11;
        free(pMem: *(void **)((char *)&this->m_ShaderDLLs.m_Memory.m_pMemory->m_pFileName + v11));
        v9 = (CUtlDict<IShader *,unsigned short> *)((char *)&this->m_ShaderDLLs.m_Memory.m_pMemory->m_ShaderDict + v11);
        CUtlDict<IShader *,unsigned short>::RemoveAll(this: v9);
        CUtlRBTree<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,IShader *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &v9->m_Elements.m_Tree);
        v9->m_Elements.m_Tree.m_FirstFree = -1;
        if ( v9->m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v9->m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9->m_Elements.m_Tree.m_Elements.m_pMemory);
            v9->m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
          }
          v9->m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
        }
        v9->m_Elements.m_Tree.m_LastAlloc.index = -1;
        if ( v9->m_Elements.m_Tree.m_Elements.m_nGrowSize >= 0 )
        {
          if ( v9->m_Elements.m_Tree.m_Elements.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9->m_Elements.m_Tree.m_Elements.m_pMemory);
            v9->m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
          }
          v9->m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
        }
        if ( this->m_ShaderDLLs.m_Size - i - 1 > 0 )
          _V_memmove(
            dest: (char *)this->m_ShaderDLLs.m_Memory.m_pMemory + v11,
            src: (char *)&this->m_ShaderDLLs.m_Memory.m_pMemory[1] + v11,
            count: 48 * (this->m_ShaderDLLs.m_Size - i - 1));
        --this->m_ShaderDLLs.m_Size;
        v2 = i;
      }
      --v2;
      v3 -= 48;
      i = v2;
      v11 = v3;
    }
    while ( v2 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057EC0
// Name: private: void CShaderSystem::UnloadAllShaderDLLs(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderSystem::UnloadAllShaderDLLs(CShaderSystem *this)
{
  CShaderSystem *v1; // edi
  int m_Size; // esi
  int v3; // esi
  int v4; // ebx
  IShaderDLLInternal *m_pShaderDLL; // esi
  IShaderDLLInternal_vtbl *v6; // edi
  IShaderDLLInternal *ShaderDLLInternal; // eax
  struct CSysModule *m_hInstance; // eax
  int i; // [esp+8h] [ebp-8h]

  v1 = this;
  m_Size = this->m_ShaderDLLs.m_Size;
  if ( m_Size != 0 )
  {
    v3 = m_Size - 1;
    i = v3;
    if ( v3 >= 0 )
    {
      v4 = v3;
      do
      {
        m_pShaderDLL = v1->m_ShaderDLLs.m_Memory.m_pMemory[v4].m_pShaderDLL;
        v6 = m_pShaderDLL->__vftable;
        ShaderDLLInternal = GetShaderDLLInternal();
        v6->Disconnect(this: m_pShaderDLL, a2: m_pShaderDLL == ShaderDLLInternal);
        m_hInstance = this->m_ShaderDLLs.m_Memory.m_pMemory[v4].m_hInstance;
        if ( m_hInstance != nullptr )
          g_pFullFileSystem->UnloadModule(this: g_pFullFileSystem, a2: m_hInstance);
        v1 = this;
        free(pMem: this->m_ShaderDLLs.m_Memory.m_pMemory[v4--].m_pFileName);
        --i;
      }
      while ( i >= 0 );
    }
    CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int>>::RemoveAll(this: &v1->m_ShaderDLLs);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057F60
// Name: public: virtual void CShaderSystem::UnloadShaderDLL(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CShaderSystem::UnloadShaderDLL(CShaderSystem *this, const char *pFullPath)
{
  int v2; // esi
  CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *p_m_ShaderDLLs; // ebx
  int i; // edi

  v2 = this->m_ShaderDLLs.m_Size - 1;
  if ( v2 >= 0 )
  {
    p_m_ShaderDLLs = &this->m_ShaderDLLs;
    for ( i = v2; _V_stricmp(s1: pFullPath, s2: p_m_ShaderDLLs->m_Memory.m_pMemory[i].m_pFileName) != 0; --i )
    {
      if ( --v2 < 0 )
        return;
    }
    CShaderSystem::UnloadShaderDLL(this, nShaderDLLIndex: v2);
    free(pMem: p_m_ShaderDLLs->m_Memory.m_pMemory[v2].m_pFileName);
    CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int>>::Remove(
      this: p_m_ShaderDLLs,
      elem: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10057FE0
// Name: public: CUtlVector<struct CShaderSystem::ShaderDLLInfo_t,class CUtlMemory<struct CShaderSystem::ShaderDLLInfo_t,int>>::~CUtlVector<struct CShaderSystem::ShaderDLLInfo_t,class CUtlMemory<struct CShaderSystem::ShaderDLLInfo_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int>>::~CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int>>(
        CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int> > *this)
{
  bool v2; // sf
  CShaderSystem::ShaderDLLInfo_t *m_pMemory; // eax

  CUtlVector<CShaderSystem::ShaderDLLInfo_t,CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int>>::RemoveAll(this);
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10058080
// Name: public: virtual void CShaderSystem::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CShaderSystem::Shutdown(CShaderSystem *this)
{
  CShaderSystem::UnloadAllShaderDLLs(this);
}

//------------------------------------------------------------------------------
// Address: 0x10058090
// Name: public: virtual void CShaderSystem::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CShaderSystem::Init(CShaderSystem *this@<ecx>, int a2@<ebx>)
{
  int v3; // eax
  int v4; // ecx
  int v5; // eax
  IShaderDLLInternal *ShaderDLLInternal; // eax
  IShaderDLLInternal_vtbl *v7; // edi
  void *(__cdecl *FactoryThis)(const char *, int *); // eax
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CShaderSystem::ShaderDLLInfo_t *m_pMemory; // eax
  int v12; // ecx
  CShaderSystem::ShaderDLLInfo_t *v13; // eax
  UtlRBTreeNode_t<CUtlMap<char const *,IShader *,unsigned short>::Node_t,unsigned short> *v14; // ecx
  int v15; // edi
  int i; // ebx
  const char *v17; // eax
  char pDest[32]; // [esp+10h] [ebp-30h] BYREF
  CShaderSystem::ShaderDLLInfo_t *v19; // [esp+30h] [ebp-10h]
  int v20; // [esp+3Ch] [ebp-4h]

  this->m_bForceUsingGraphicsReturnTrue = false;
  v3 = _CommandLine(a1: this);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-noshaderapi") != 0
    || (v5 = _CommandLine(a1: v4),
        (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-makereslists") != 0) )
  {
    this->m_bForceUsingGraphicsReturnTrue = true;
  }
  this->m_pDebugMaterials[0] = nullptr;
  this->m_pDebugMaterials[1] = nullptr;
  this->m_pDebugMaterials[2] = nullptr;
  this->m_pDebugMaterials[3] = nullptr;
  this->m_pDebugMaterials[4] = nullptr;
  this->m_pDebugMaterials[5] = nullptr;
  CShaderSystem::UnloadAllShaderDLLs(this);
  ShaderDLLInternal = GetShaderDLLInternal();
  v7 = ShaderDLLInternal->__vftable;
  v19 = (CShaderSystem::ShaderDLLInfo_t *)ShaderDLLInternal;
  FactoryThis = Sys_GetFactoryThis();
  ((void (__thiscall *)(CShaderSystem::ShaderDLLInfo_t *, void *(__cdecl *)(const char *, int *), int, int))v7->Connect)(
    a1: v19,
    a2: FactoryThis,
    a3: 1,
    a4: a2);
  m_Size = this->m_ShaderDLLs.m_Size;
  m_nAllocationCount = this->m_ShaderDLLs.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CShaderSystem::ShaderDLLInfo_t,int>::Grow(
      this: &this->m_ShaderDLLs.m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_ShaderDLLs.m_Size;
  m_pMemory = this->m_ShaderDLLs.m_Memory.m_pMemory;
  v12 = this->m_ShaderDLLs.m_Size - 1;
  this->m_ShaderDLLs.m_pElements = m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &m_pMemory[1], src: m_pMemory, count: 48 * v12);
  v13 = this->m_ShaderDLLs.m_Memory.m_pMemory;
  if ( v13 != nullptr )
  {
    v13->m_ShaderDict.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
    v13->m_ShaderDict.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
    v13->m_ShaderDict.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
    v13->m_ShaderDict.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
    v14 = v13->m_ShaderDict.m_Elements.m_Tree.m_Elements.m_pMemory;
    *(_DWORD *)&v13->m_ShaderDict.m_Elements.m_Tree.m_Root = 0xFFFF;
    *(_DWORD *)&v13->m_ShaderDict.m_Elements.m_Tree.m_FirstFree = -1;
    v13->m_ShaderDict.m_Elements.m_Tree.m_pElements = v14;
    if ( v13->m_ShaderDict.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
      v13->m_ShaderDict.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  }
  v20 = -1;
  this->m_ShaderDLLs.m_Memory.m_pMemory->m_pFileName = (char *)MemAlloc_Alloc(nSize: 1u);
  *this->m_ShaderDLLs.m_Memory.m_pMemory->m_pFileName = 0;
  this->m_ShaderDLLs.m_Memory.m_pMemory->m_hInstance = nullptr;
  v19 = this->m_ShaderDLLs.m_Memory.m_pMemory;
  v19->m_pShaderDLL = GetShaderDLLInternal();
  this->m_ShaderDLLs.m_Memory.m_pMemory->m_bModShaderDLL = false;
  CShaderSystem::SetupShaderDictionary(this, nShaderDLLIndex: 0);
  this->LoadShaderDLL(this, a2: "stdshader_dbg");
  v15 = g_pHWConfig->GetMaxDXSupportLevel(this: g_pHWConfig) / 10;
  for ( i = 9; i <= v15; ++i )
  {
    V_snprintf(pDest, maxLen: 32, pFormat: "stdshader_dx%d", i);
    this->LoadShaderDLL(this, a2: pDest);
  }
  v17 = g_pHWConfig->GetHWSpecificShaderDLLName(this: g_pHWConfig);
  if ( v17 != nullptr )
    this->LoadShaderDLL(this, a2: v17);
}

//------------------------------------------------------------------------------
// Address: 0x10256FE0
// Name: public: bool CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>::FindAndRemove(void (*const __near &)(class IConVar __near *,char const __near *,float))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::FindAndRemove(
        CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *this,
        void (__cdecl **src)(IConVar *, const char *, float))
{
  int m_Size; // edx
  int v4; // eax
  void (__cdecl **m_pMemory)(IConVar *, const char *, float); // ebx
  void (__cdecl **i)(IConVar *, const char *, float); // ecx
  int v8; // edx

  m_Size = this->m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return 0;
  m_pMemory = this->m_Memory.m_pMemory;
  for ( i = this->m_Memory.m_pMemory; *i != *src; ++i )
  {
    if ( ++v4 >= m_Size )
      return 0;
  }
  if ( v4 == -1 )
    return 0;
  v8 = m_Size - v4 - 1;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[v4], src: &m_pMemory[v4 + 1], count: 4 * v8);
  --this->m_Size;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10261120
// Name: public: int CUtlVector<struct ResourceEntryInfo,class CUtlMemory<struct ResourceEntryInfo,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ResourceEntryInfo,CUtlMemory<ResourceEntryInfo,int>>::InsertMultipleBefore(
        CUtlVector<ResourceEntryInfo,CUtlMemory<ResourceEntryInfo,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ResourceEntryInfo *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CMorph::MorphSegment_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 8 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10261190
// Name: public: int CUtlVector<struct CVTFTexture::ResourceMemorySection,class CUtlMemory<struct CVTFTexture::ResourceMemorySection,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int>>::InsertMultipleBefore(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this,
        int elem,
        int num)
{
  int v3; // edi
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CVTFTexture::ResourceMemorySection *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CVTFTexture::ResourceMemorySection *v11; // eax

  v3 = num;
  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CMorph::MorphQuad_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
  if ( num > 0 )
  {
    v10 = elem;
    do
    {
      v11 = &this->m_Memory.m_pMemory[v10];
      if ( v11 != nullptr )
      {
        *(_QWORD *)&v11->m_nDataAllocSize = 0;
        v11->m_pData = nullptr;
      }
      ++v10;
      --v3;
    }
    while ( v3 != 0 );
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10261230
// Name: public: int CUtlVector<class S3RGBA,class CUtlMemory<class S3RGBA,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int>>::InsertMultipleBefore(
        CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  S3RGBA *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<IMaterialVar *,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10261610
// Name: public: CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>::~CUtlVector<void (*)(class IConVar __near *,char const __near *,float),class CUtlMemory<void (*)(class IConVar __near *,char const __near *,float),int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this)
{
  bool v2; // sf
  CVTFTexture::ResourceMemorySection *m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10261680
// Name: public: int CUtlVector<struct CVTFTexture::ResourceMemorySection,class CUtlMemory<struct CVTFTexture::ResourceMemorySection,int>>::InsertBefore(int,struct CVTFTexture::ResourceMemorySection const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int>>::InsertBefore(
        CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *this,
        int elem,
        const CVTFTexture::ResourceMemorySection *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CVTFTexture::ResourceMemorySection *m_pMemory; // ecx
  int v7; // eax
  CVTFTexture::ResourceMemorySection *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CMorph::MorphQuad_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 12 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x10027C80
// Name: class CFunctor __near * CreateFunctor<class CMaterialSystem __near *,class CMaterialSystem,void,class CMatQueuedRenderContext __near *,class CMatQueuedRenderContext __near *>(class CMaterialSystem __near *,void (CMaterialSystem::*)(class CMatQueuedRenderContext __near *),class CMatQueuedRenderContext __near * const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFunctor *__cdecl CreateFunctor<CMaterialSystem *,CMaterialSystem,void,CMatQueuedRenderContext *,CMatQueuedRenderContext *>(
        CFunctor_vtbl *pObject,
        __int128 pfnProxied,
        CFunctor_vtbl **arg1)
{
  CFunctor *result; // eax
  CFunctor_vtbl **v4; // edx

  result = (CFunctor *)MemAlloc_Alloc(nSize: 0x30u);
  if ( result == nullptr )
    return nullptr;
  v4 = arg1;
  result[1].m_nUserID = 1;
  result->__vftable = (CFunctor_vtbl *)&CMemberFunctor1<CMaterialSystem *,void (__thiscall CMaterialSystem::*)(CMatQueuedRenderContext *),CMatQueuedRenderContext *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CFunctor'};
  result[1].__vftable = (CFunctor_vtbl *)&CMemberFunctor1<CMaterialSystem *,void (__thiscall CMaterialSystem::*)(CMatQueuedRenderContext *),CMatQueuedRenderContext *,CRefCounted1<CFunctor,CRefCountServiceBase<1,CRefMT>>,CFuncMemPolicyNone>::`vftable'{for `CRefCountServiceBase<1,CRefMT>'};
  *(_OWORD *)&result[2].__vftable = pfnProxied;
  result[4].__vftable = pObject;
  result[5].__vftable = *v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10054E30
// Name: __CreateCShaderSystemIShaderSystem_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
IShaderSystem *__cdecl _CreateCShaderSystemIShaderSystem_interface()
{
  return &s_ShaderSystem.IShaderSystem;
}
