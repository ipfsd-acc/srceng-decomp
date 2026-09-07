// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vrad/samplehash.cpp
// Functions: 8
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100189D0
// Name: bool SampleData_CompareFunc(struct SampleData_t const __near &,struct SampleData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl SampleData_CompareFunc(const PatchSampleData_t *src1, const PatchSampleData_t *src2)
{
  return src1->x == src2->x && src1->y == src2->y && src1->z == src2->z;
}

//------------------------------------------------------------------------------
// Address: 0x10018A00
// Name: unsigned int PatchSampleData_KeyFunc(struct PatchSampleData_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl PatchSampleData_KeyFunc(const PatchSampleData_t *src)
{
  return src->x + src->y + src->z;
}

//------------------------------------------------------------------------------
// Address: 0x10018AC0
// Name: unsigned short IncrementPatchIterationKey(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __cdecl IncrementPatchIterationKey()
{
  int v0; // ecx
  unsigned __int16 result; // ax
  int v2; // edx

  if ( g_PatchIterationKey == 0xFFFF )
  {
    v0 = 0;
    result = 1;
    g_PatchIterationKey = 1;
    if ( g_Patches.m_Size > 0 )
    {
      v2 = 0;
      do
      {
        g_Patches.m_Memory.m_pMemory[v2].m_IterationKey = 0;
        ++v0;
        ++v2;
      }
      while ( v0 < g_Patches.m_Size );
    }
  }
  else
  {
    return ++g_PatchIterationKey;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10018C70
// Name: void SampleData_Log(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SampleData_Log()
{
  if ( g_bLogHashData != 0 )
    CUtlHash<SampleData_t,bool (__cdecl *)(SampleData_t const &,SampleData_t const &),unsigned int (__cdecl *)(SampleData_t const &)>::Log(
      this: &g_SampleHashTable,
      filename: "samplehash.txt");
}

//------------------------------------------------------------------------------
// Address: 0x10018C90
// Name: unsigned int SampleData_Find(struct sample_t __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl SampleData_Find(sample_t *pSample)
{
  float y; // xmm1_4
  int v2; // eax
  float z; // xmm1_4
  unsigned int v4; // esi
  SampleData_t sampleData; // [esp+0h] [ebp-20h] BYREF
  unsigned int pBucket; // [esp+1Ch] [ebp-4h] BYREF

  y = pSample->pos.y;
  sampleData.x = 100 * (int)(float)(pSample->pos.x * 0.015625);
  v2 = (int)(float)(y * 0.015625);
  z = pSample->pos.z;
  memset(&sampleData.m_Samples, 0, sizeof(sampleData.m_Samples));
  pSample = nullptr;
  sampleData.y = 10 * v2;
  sampleData.z = (int)(float)(z * 0.015625);
  if ( CUtlHash<SampleData_t,bool (__cdecl *)(SampleData_t const &,SampleData_t const &),unsigned int (__cdecl *)(SampleData_t const &)>::DoFind(
         this: (CUtlHash<PatchSampleData_t,bool (__cdecl*)(PatchSampleData_t const &,PatchSampleData_t const &),unsigned int (__cdecl*)(PatchSampleData_t const &)> *)&g_SampleHashTable,
         src: (const PatchSampleData_t *)&sampleData,
         &pBucket,
         pIndex: (int *)&pSample) )
  {
    v4 = (unsigned int)pSample | (pBucket << 16);
    CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&sampleData.m_Samples);
    return v4;
  }
  else
  {
    CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&sampleData.m_Samples);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10018E80
// Name: unsigned int SampleData_InsertIntoHashTable(struct sample_t __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl SampleData_InsertIntoHashTable(sample_t *pSample, unsigned int sampleHandle)
{
  float y; // xmm1_4
  int v3; // eax
  float z; // xmm1_4
  unsigned int v5; // ebx
  unsigned int v6; // esi
  SampleData_t *v7; // eax
  CUtlMemory<S3RGBA,int> *p_m_Samples; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  S3RGBA *m_pMemory; // ecx
  int v12; // eax
  S3RGBA *v13; // edi
  SampleData_t sampleData; // [esp+0h] [ebp-20h] BYREF
  unsigned int pBucket; // [esp+1Ch] [ebp-4h] BYREF

  y = pSample->pos.y;
  sampleData.x = 100 * (int)(float)(pSample->pos.x * 0.015625);
  v3 = (int)(float)(y * 0.015625);
  z = pSample->pos.z;
  memset(&sampleData.m_Samples, 0, sizeof(sampleData.m_Samples));
  pSample = nullptr;
  sampleData.y = 10 * v3;
  sampleData.z = (int)(float)(z * 0.015625);
  if ( CUtlHash<SampleData_t,bool (__cdecl *)(SampleData_t const &,SampleData_t const &),unsigned int (__cdecl *)(SampleData_t const &)>::DoFind(
         this: (CUtlHash<PatchSampleData_t,bool (__cdecl*)(PatchSampleData_t const &,PatchSampleData_t const &),unsigned int (__cdecl*)(PatchSampleData_t const &)> *)&g_SampleHashTable,
         src: (const PatchSampleData_t *)&sampleData,
         &pBucket,
         pIndex: (int *)&pSample) )
  {
    v5 = (unsigned int)pSample | (pBucket << 16);
  }
  else
  {
    v6 = pBucket;
    v5 = (v6 << 16)
       | CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int>>::InsertBefore(
           this: (CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int> > *)&g_SampleHashTable.m_Buckets.m_Memory.m_pMemory[pBucket],
           elem: g_SampleHashTable.m_Buckets.m_Memory.m_pMemory[pBucket].m_Size);
  }
  v7 = &g_SampleHashTable.m_Buckets.m_Memory.m_pMemory[HIWORD(v5)].m_Memory.m_pMemory[(unsigned __int16)v5];
  v7->x = sampleData.x;
  v7->y = sampleData.y;
  p_m_Samples = (CUtlMemory<S3RGBA,int> *)&v7->m_Samples;
  v7->z = sampleData.z;
  m_Size = v7->m_Samples.m_Size;
  m_nAllocationCount = v7->m_Samples.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(this: p_m_Samples, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Samples[1].m_pMemory;
  m_pMemory = p_m_Samples->m_pMemory;
  v12 = (int)p_m_Samples[1].m_pMemory - m_Size - 1;
  p_m_Samples[1].m_nAllocationCount = (int)p_m_Samples->m_pMemory;
  if ( v12 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
  v13 = &p_m_Samples->m_pMemory[m_Size];
  if ( v13 != nullptr )
    *v13 = (S3RGBA)sampleHandle;
  ++samplesAdded;
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&sampleData.m_Samples);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x10018FE0
// Name: unsigned int SampleData_AddSample(struct sample_t __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl SampleData_AddSample(sample_t *pSample, unsigned int sampleHandle)
{
  unsigned int v2; // eax
  unsigned int v3; // ebx
  SampleData_t *m_pMemory; // ecx
  int m_nAllocationCount; // eax
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *p_m_Samples; // esi
  int m_Size; // edi
  unsigned int *v9; // ecx
  int v10; // eax
  unsigned int *v11; // edi

  v2 = SampleData_Find(pSample);
  v3 = v2;
  if ( v2 == -1 )
    return SampleData_InsertIntoHashTable(pSample, sampleHandle);
  m_pMemory = g_SampleHashTable.m_Buckets.m_Memory.m_pMemory[HIWORD(v2)].m_Memory.m_pMemory;
  m_nAllocationCount = m_pMemory[(unsigned __int16)v2].m_Samples.m_Memory.m_nAllocationCount;
  p_m_Samples = &m_pMemory[(unsigned __int16)v3].m_Samples;
  m_Size = m_pMemory[(unsigned __int16)v3].m_Samples.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&m_pMemory[(unsigned __int16)v3].m_Samples,
      num: m_Size - m_nAllocationCount + 1);
  ++p_m_Samples->m_Size;
  v9 = p_m_Samples->m_Memory.m_pMemory;
  v10 = p_m_Samples->m_Size - m_Size - 1;
  p_m_Samples->m_pElements = p_m_Samples->m_Memory.m_pMemory;
  if ( v10 > 0 )
    _V_memmove(dest: &v9[m_Size + 1], src: &v9[m_Size], count: 4 * v10);
  v11 = &p_m_Samples->m_Memory.m_pMemory[m_Size];
  if ( v11 != nullptr )
    *v11 = sampleHandle;
  ++samplesAdded;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10019090
// Name: void PatchSampleData_AddSample(struct CPatch __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PatchSampleData_AddSample(CPatch *pPatch, int ndxPatch)
{
  int v2; // edx
  float v3; // xmm1_4
  unsigned __int16 v4; // ax
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // esi
  PatchSampleData_t *v8; // eax
  CUtlMemory<S3RGBA,int> *v9; // esi
  int v10; // edi
  int v11; // eax
  S3RGBA *v12; // ecx
  int v13; // eax
  S3RGBA *v14; // eax
  PatchSampleData_t *m_pMemory; // ecx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_ndxPatches; // esi
  S3RGBA *v19; // ecx
  int v20; // eax
  S3RGBA *v21; // eax
  int *v22; // eax
  PatchSampleData_t iteratePatch; // [esp+0h] [ebp-44h] BYREF
  int patchSampleMins[3]; // [esp+1Ch] [ebp-28h]
  int iterateCoords[3]; // [esp+28h] [ebp-1Ch]
  unsigned int pBucket; // [esp+34h] [ebp-10h] BYREF
  int v27; // [esp+38h] [ebp-Ch]
  int i; // [esp+3Ch] [ebp-8h]
  unsigned int v29; // [esp+40h] [ebp-4h] BYREF

  v2 = (int)(float)(pPatch->origin.y * 0.015625);
  v3 = pPatch->origin.z * 0.015625;
  patchSampleMins[0] = (int)(float)(pPatch->origin.x * 0.015625);
  patchSampleMins[1] = v2;
  patchSampleMins[2] = (int)v3;
  iterateCoords[0] = patchSampleMins[0];
  do
  {
    iterateCoords[1] = patchSampleMins[1];
    v27 = 100 * iterateCoords[0];
    v4 = 10 * LOWORD(patchSampleMins[1]);
    iterateCoords[2] = patchSampleMins[2];
    for ( i = 10 * patchSampleMins[1]; ; i = 10 * iterateCoords[1] )
    {
      while ( 1 )
      {
        iteratePatch.y = v4;
        iteratePatch.x = v27;
        iteratePatch.z = iterateCoords[2];
        memset(&iteratePatch.m_ndxPatches, 0, sizeof(iteratePatch.m_ndxPatches));
        pPatch = nullptr;
        if ( CUtlHash<SampleData_t,bool (__cdecl *)(SampleData_t const &,SampleData_t const &),unsigned int (__cdecl *)(SampleData_t const &)>::DoFind(
               this: &g_PatchSampleHashTable,
               src: &iteratePatch,
               &pBucket,
               pIndex: (int *)&pPatch)
          && (v5 = (unsigned int)pPatch | (pBucket << 16)) != -1 )
        {
          m_pMemory = g_PatchSampleHashTable.m_Buckets.m_Memory.m_pMemory[HIWORD(v5)].m_Memory.m_pMemory;
          m_Size = m_pMemory[(unsigned __int16)pPatch].m_ndxPatches.m_Size;
          m_nAllocationCount = m_pMemory[(unsigned __int16)pPatch].m_ndxPatches.m_Memory.m_nAllocationCount;
          p_m_ndxPatches = (CUtlMemory<S3RGBA,int> *)&m_pMemory[(unsigned __int16)pPatch].m_ndxPatches;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<int,int>::Grow(this: p_m_ndxPatches, num: m_Size - m_nAllocationCount + 1);
          ++p_m_ndxPatches[1].m_pMemory;
          v19 = p_m_ndxPatches->m_pMemory;
          v20 = (int)p_m_ndxPatches[1].m_pMemory - m_Size - 1;
          p_m_ndxPatches[1].m_nAllocationCount = (int)p_m_ndxPatches->m_pMemory;
          if ( v20 > 0 )
            _V_memmove(dest: &v19[m_Size + 1], src: &v19[m_Size], count: 4 * v20);
          v21 = &p_m_ndxPatches->m_pMemory[m_Size];
          if ( v21 != nullptr )
            *v21 = (S3RGBA)ndxPatch;
        }
        else
        {
          pPatch = nullptr;
          if ( CUtlHash<SampleData_t,bool (__cdecl *)(SampleData_t const &,SampleData_t const &),unsigned int (__cdecl *)(SampleData_t const &)>::DoFind(
                 this: &g_PatchSampleHashTable,
                 src: &iteratePatch,
                 pBucket: &v29,
                 pIndex: (int *)&pPatch) )
          {
            v6 = (unsigned int)pPatch | (v29 << 16);
          }
          else
          {
            v7 = v29;
            v6 = (v7 << 16)
               | CUtlVector<PatchSampleData_t,CUtlMemory<PatchSampleData_t,int>>::InsertBefore(
                   this: &g_PatchSampleHashTable.m_Buckets.m_Memory.m_pMemory[v29],
                   elem: g_PatchSampleHashTable.m_Buckets.m_Memory.m_pMemory[v29].m_Size);
          }
          v8 = &g_PatchSampleHashTable.m_Buckets.m_Memory.m_pMemory[HIWORD(v6)].m_Memory.m_pMemory[(unsigned __int16)v6];
          v8->x = iteratePatch.x;
          v8->y = iteratePatch.y;
          v9 = (CUtlMemory<S3RGBA,int> *)&v8->m_ndxPatches;
          v8->z = iteratePatch.z;
          v10 = v8->m_ndxPatches.m_Size;
          v11 = v8->m_ndxPatches.m_Memory.m_nAllocationCount;
          if ( v10 + 1 > v11 )
            CUtlMemory<int,int>::Grow(this: v9, num: v10 - v11 + 1);
          ++v9[1].m_pMemory;
          v12 = v9->m_pMemory;
          v13 = (int)v9[1].m_pMemory - v10 - 1;
          v9[1].m_nAllocationCount = (int)v9->m_pMemory;
          if ( v13 > 0 )
            _V_memmove(dest: &v12[v10 + 1], src: &v12[v10], count: 4 * v13);
          v14 = &v9->m_pMemory[v10];
          if ( v14 != nullptr )
            *v14 = (S3RGBA)ndxPatch;
        }
        ++patchSamplesAdded;
        v22 = iteratePatch.m_ndxPatches.m_Memory.m_pMemory;
        iteratePatch.m_ndxPatches.m_Size = 0;
        if ( iteratePatch.m_ndxPatches.m_Memory.m_nGrowSize >= 0 )
        {
          if ( iteratePatch.m_ndxPatches.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: iteratePatch.m_ndxPatches.m_Memory.m_pMemory);
            v22 = nullptr;
            iteratePatch.m_ndxPatches.m_Memory.m_pMemory = nullptr;
          }
          iteratePatch.m_ndxPatches.m_Memory.m_nAllocationCount = 0;
        }
        iteratePatch.m_ndxPatches.m_pElements = v22;
        if ( iteratePatch.m_ndxPatches.m_Memory.m_nGrowSize >= 0 && v22 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v22);
        if ( ++iterateCoords[2] > patchSampleMins[2] )
          break;
        v4 = i;
      }
      if ( ++iterateCoords[1] > patchSampleMins[1] )
        break;
      v4 = 10 * LOWORD(iterateCoords[1]);
      iterateCoords[2] = patchSampleMins[2];
    }
    ++iterateCoords[0];
  }
  while ( iterateCoords[0] <= patchSampleMins[0] );
}
