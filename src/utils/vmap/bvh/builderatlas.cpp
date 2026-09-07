// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmap/bvh/builderatlas.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: void __near * MemAlloc_Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl MemAlloc_Alloc(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x00401090
// Name: int CalculateTotalAtlases(class CUtlVector<class CBuilderAtlas __near *,class CUtlMemory<class CBuilderAtlas __near *,int>> __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CalculateTotalAtlases(
        CUtlVector<CBuilderAtlas *,CUtlMemory<CBuilderAtlas *,int> > *pAtlasTable,
        int nAtlasTables)
{
  int v2; // edi
  int v3; // edx
  int v4; // esi
  int *p_m_Size; // eax
  unsigned int v6; // ecx
  int nAtlases; // [esp+Ch] [ebp-4h]

  v2 = 0;
  v3 = 0;
  v4 = 0;
  nAtlases = 0;
  if ( nAtlasTables >= 2 )
  {
    p_m_Size = &pAtlasTable[1].m_Size;
    v6 = ((unsigned int)(nAtlasTables - 2) >> 1) + 1;
    v2 = 2 * v6;
    do
    {
      v3 += *(p_m_Size - 5);
      v4 += *p_m_Size;
      p_m_Size += 10;
      --v6;
    }
    while ( v6 != 0 );
  }
  if ( v2 < nAtlasTables )
    nAtlases = pAtlasTable[v2].m_Size;
  return nAtlases + v4 + v3;
}

//------------------------------------------------------------------------------
// Address: 0x00401250
// Name: void DestroyAtlasTable(class CUtlVector<class CBuilderAtlas __near *,class CUtlMemory<class CBuilderAtlas __near *,int>> __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DestroyAtlasTable(
        CUtlVector<CBuilderAtlas *,CUtlMemory<CBuilderAtlas *,int> > *pAtlasTable,
        int nAtlasTables)
{
  CUtlVector<CBuilderAtlas *,CUtlMemory<CBuilderAtlas *,int> > *v2; // ecx
  CUtlVector<CBuilderAtlas *,CUtlMemory<CBuilderAtlas *,int> > *v3; // ebx
  int v4; // eax
  CBuilderAtlas *v5; // esi
  TextureData_t **m_pMemory; // eax
  int i; // [esp+4h] [ebp-8h]
  int a; // [esp+8h] [ebp-4h]

  v2 = pAtlasTable;
  if ( pAtlasTable != nullptr )
  {
    if ( nAtlasTables > 0 )
    {
      v3 = pAtlasTable;
      for ( i = nAtlasTables; i != 0; --i )
      {
        v4 = 0;
        for ( a = 0; v4 < v3->m_Size; a = v4 )
        {
          v5 = v3->m_Memory.m_pMemory[v4];
          if ( v5 != nullptr )
          {
            v5->m_ContributingTextures.m_Size = 0;
            if ( v5->m_ContributingTextures.m_Memory.m_nGrowSize >= 0 )
            {
              if ( v5->m_ContributingTextures.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_ContributingTextures.m_Memory.m_pMemory);
                v5->m_ContributingTextures.m_Memory.m_pMemory = nullptr;
              }
              v5->m_ContributingTextures.m_Memory.m_nAllocationCount = 0;
            }
            m_pMemory = v5->m_ContributingTextures.m_Memory.m_pMemory;
            v5->m_ContributingTextures.m_pElements = m_pMemory;
            if ( v5->m_ContributingTextures.m_Memory.m_nGrowSize >= 0 )
            {
              if ( m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
                v5->m_ContributingTextures.m_Memory.m_pMemory = nullptr;
              }
              v5->m_ContributingTextures.m_Memory.m_nAllocationCount = 0;
            }
            CTexturePacker::~CTexturePacker(this: &v5->m_Packer);
            free(pMem: v5);
            v4 = a;
          }
          ++v4;
        }
        v3->m_Size = 0;
        ++v3;
      }
      v2 = pAtlasTable;
    }
    CUtlVector<CBuilderAtlas *,CUtlMemory<CBuilderAtlas *,int>>::`vector deleting destructor'(this: v2, a2: 3u);
  }
}
