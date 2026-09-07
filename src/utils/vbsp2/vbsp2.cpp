// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vbsp2/vbsp2.cpp
// Functions: 61
// ============================================================

#include "utils\vbsp2\vbsp2.h"

//------------------------------------------------------------------------------
// Address: 0x00401220
// Name: public: CUtlVector<struct MapEntityKeyValuePair_t,class CUtlMemory<struct MapEntityKeyValuePair_t,int>>::~CUtlVector<struct MapEntityKeyValuePair_t,class CUtlMemory<struct MapEntityKeyValuePair_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(
        CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *this)
{
  bool v2; // sf
  CBSPBrush **m_pMemory; // eax

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
// Address: 0x00401290
// Name: public: int CUtlVector<struct LightmapSourceFile_t,class CUtlMemory<struct LightmapSourceFile_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<LightmapSourceFile_t,CUtlMemory<LightmapSourceFile_t,int>>::AddToTail(
        CUtlVector<LightmapSourceFile_t,CUtlMemory<LightmapSourceFile_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  LightmapSourceFile_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<LightmapSourceFile_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 272 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00401350
// Name: public: CMemoryBSPFile::~CMemoryBSPFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::~CMemoryBSPFile(CMemoryBSPFile *this)
{
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_WorldLightsHDR);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_WorldLightsLDR);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_LightingData);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_PhysicsCollideData);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_PhysicsDisplacementData);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_DisplacementMultiBlendList);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_DisplacementTriangleList);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_DisplacementVertexList);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_DisplacementList);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_DisplacementHelperList);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_VisibilityData);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_EntityData);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_GameLumpData);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_Planes);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_BrushSideList);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_BrushList);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_LeafFaceList);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_LeafBrushList);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_LeafList);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_NodeList);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_VertexNormalIndexList);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_VertexNormalList);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_FaceList);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_SurfEdgeList);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_EdgeList);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_VertexHash.m_Vertices);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_VertexHash.m_VertexHashChain);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_ModelList);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_TexStringIndices);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_TexStringData);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_TexDataList);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_TexInfoList);
  this->m_PlaneHash.m_Planes.__vftable = (CCopyableUtlVector<HashedPlane_t>_vtbl *)&CCopyableUtlVector<HashedPlane_t>::`vftable';
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_PlaneHash.m_Planes.CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> >);
}

//------------------------------------------------------------------------------
// Address: 0x004014D0
// Name: TransferLighting
// Source: json
//------------------------------------------------------------------------------
void __cdecl TransferLighting(char *pBSPFilename)
{
  int v1; // edi
  int v2; // esi
  int *m_pMemory; // eax
  dworldlight_t *v4; // eax
  dworldlight_t *v5; // eax
  CLuxelHash::LuxelHashEntry_t *v6; // eax
  ColorRGBExp32 *v7; // eax
  CMemoryBSPFile pSourceBSPFile; // [esp+24h] [ebp-23E04h] BYREF
  CMemoryBSPFile pTargetBSPFile; // [esp+11ED4h] [ebp-11F54h] BYREF
  CUtlStreamBuffer v10; // [esp+23D84h] [ebp-A4h] BYREF
  CLuxelHash v11; // [esp+23DC4h] [ebp-64h] BYREF

  CMemoryBSPFile::CMemoryBSPFile(this: &pTargetBSPFile);
  CLuxelHash::CLuxelHash(this: &v11, nHashBucketCount: 196613);
  v1 = 0;
  if ( s_LightmapSourceFiles.m_Size > 0 )
  {
    v2 = 0;
    do
    {
      if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 0) != 0 )
        _LoggingSystem_Log(
          a1: LOG_VBSP2,
          a2: 0,
          a3: "Loading lightmap source file %s at offset (%f, %f, %f)...\n",
          s_LightmapSourceFiles.m_Memory.m_pMemory[v2].m_Filename,
          s_LightmapSourceFiles.m_Memory.m_pMemory[v2].m_vOffset.x,
          s_LightmapSourceFiles.m_Memory.m_pMemory[v2].m_vOffset.y,
          s_LightmapSourceFiles.m_Memory.m_pMemory[v2].m_vOffset.z);
      CMemoryBSPFile::CMemoryBSPFile(this: &pSourceBSPFile);
      CUtlStreamBuffer::CUtlStreamBuffer(
        this: &v10,
        pFileName: s_LightmapSourceFiles.m_Memory.m_pMemory[v2].m_Filename,
        pPath: nullptr,
        nFlags: 8,
        bDelayOpen: false,
        nOpenFileFlags: 0);
      CMemoryBSPFile::Deserialize(this: &pSourceBSPFile, pInputBuffer: &v10);
      CLuxelHash::AddSourceBSPFile(
        this: &v11,
        &pSourceBSPFile,
        vOffset: &s_LightmapSourceFiles.m_Memory.m_pMemory[v2].m_vOffset);
      CUtlStreamBuffer::~CUtlStreamBuffer(this: &v10);
      CMemoryBSPFile::~CMemoryBSPFile(this: &pSourceBSPFile);
      ++v1;
      ++v2;
    }
    while ( v1 < s_LightmapSourceFiles.m_Size );
  }
  CUtlStreamBuffer::CUtlStreamBuffer(
    this: &v10,
    pFileName: pBSPFilename,
    pPath: nullptr,
    nFlags: 8,
    bDelayOpen: false,
    nOpenFileFlags: 0);
  CMemoryBSPFile::Deserialize(this: &pTargetBSPFile, pInputBuffer: &v10);
  CUtlStreamBuffer::~CUtlStreamBuffer(this: &v10);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 0) != 0 )
    _LoggingSystem_Log(a1: LOG_VBSP2, a2: 0, a3: "Copying lightmap data from sources files...\n");
  CLuxelHash::CopyLighting(this: &v11, &pTargetBSPFile);
  CUtlStreamBuffer::CUtlStreamBuffer(
    this: &v10,
    pFileName: pBSPFilename,
    pPath: nullptr,
    nFlags: 0,
    bDelayOpen: false,
    nOpenFileFlags: 0);
  CMemoryBSPFile::Serialize(this: &pTargetBSPFile, pOutputBuffer: &v10);
  CUtlStreamBuffer::~CUtlStreamBuffer(this: &v10);
  if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 0) != 0 )
    _LoggingSystem_Log(a1: LOG_VBSP2, a2: 0, a3: "Done copying lightmap data to target file.\n");
  m_pMemory = v11.m_UniformGrid.m_Memory.m_pMemory;
  v11.m_UniformGrid.m_Size = 0;
  if ( v11.m_UniformGrid.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v11.m_UniformGrid.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11.m_UniformGrid.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      v11.m_UniformGrid.m_Memory.m_pMemory = nullptr;
    }
    v11.m_UniformGrid.m_Memory.m_nAllocationCount = 0;
  }
  v11.m_UniformGrid.m_pElements = m_pMemory;
  if ( v11.m_UniformGrid.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      v11.m_UniformGrid.m_Memory.m_pMemory = nullptr;
    }
    v11.m_UniformGrid.m_Memory.m_nAllocationCount = 0;
  }
  v4 = v11.m_WorldLightsHDR.m_Memory.m_pMemory;
  v11.m_WorldLightsHDR.m_Size = 0;
  if ( v11.m_WorldLightsHDR.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v11.m_WorldLightsHDR.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11.m_WorldLightsHDR.m_Memory.m_pMemory);
      v4 = nullptr;
      v11.m_WorldLightsHDR.m_Memory.m_pMemory = nullptr;
    }
    v11.m_WorldLightsHDR.m_Memory.m_nAllocationCount = 0;
  }
  v11.m_WorldLightsHDR.m_pElements = v4;
  if ( v11.m_WorldLightsHDR.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v4 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
      v11.m_WorldLightsHDR.m_Memory.m_pMemory = nullptr;
    }
    v11.m_WorldLightsHDR.m_Memory.m_nAllocationCount = 0;
  }
  v5 = v11.m_WorldLightsLDR.m_Memory.m_pMemory;
  v11.m_WorldLightsLDR.m_Size = 0;
  if ( v11.m_WorldLightsLDR.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v11.m_WorldLightsLDR.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11.m_WorldLightsLDR.m_Memory.m_pMemory);
      v5 = nullptr;
      v11.m_WorldLightsLDR.m_Memory.m_pMemory = nullptr;
    }
    v11.m_WorldLightsLDR.m_Memory.m_nAllocationCount = 0;
  }
  v11.m_WorldLightsLDR.m_pElements = v5;
  if ( v11.m_WorldLightsLDR.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
      v11.m_WorldLightsLDR.m_Memory.m_pMemory = nullptr;
    }
    v11.m_WorldLightsLDR.m_Memory.m_nAllocationCount = 0;
  }
  v6 = v11.m_HashEntries.m_Memory.m_pMemory;
  v11.m_HashEntries.m_Size = 0;
  if ( v11.m_HashEntries.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v11.m_HashEntries.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11.m_HashEntries.m_Memory.m_pMemory);
      v6 = nullptr;
      v11.m_HashEntries.m_Memory.m_pMemory = nullptr;
    }
    v11.m_HashEntries.m_Memory.m_nAllocationCount = 0;
  }
  v11.m_HashEntries.m_pElements = v6;
  if ( v11.m_HashEntries.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v6 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
      v11.m_HashEntries.m_Memory.m_pMemory = nullptr;
    }
    v11.m_HashEntries.m_Memory.m_nAllocationCount = 0;
  }
  v7 = v11.m_LuxelData.m_Memory.m_pMemory;
  v11.m_LuxelData.m_Size = 0;
  if ( v11.m_LuxelData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v11.m_LuxelData.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v11.m_LuxelData.m_Memory.m_pMemory);
      v7 = nullptr;
      v11.m_LuxelData.m_Memory.m_pMemory = nullptr;
    }
    v11.m_LuxelData.m_Memory.m_nAllocationCount = 0;
  }
  v11.m_LuxelData.m_pElements = v7;
  if ( v11.m_LuxelData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v7 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
      v11.m_LuxelData.m_Memory.m_pMemory = nullptr;
    }
    v11.m_LuxelData.m_Memory.m_nAllocationCount = 0;
  }
  CMemoryBSPFile::~CMemoryBSPFile(this: &pTargetBSPFile);
}

//------------------------------------------------------------------------------
// Address: 0x00401840
// Name: ProcessBSP
// Source: json
//------------------------------------------------------------------------------
int __usercall ProcessBSP@<eax>(char *pBSPFilename@<eax>)
{
  void *v2; // edi
  unsigned int v3; // esi
  void *v4; // ebx
  void *v5; // edi
  void *v6; // edi
  char lumpFilename[260]; // [esp+4h] [ebp-208h] BYREF
  char stripFilename[260]; // [esp+108h] [ebp-104h] BYREF

  V_StripExtension(in: pBSPFilename, out: stripFilename, outSize: 260);
  if ( s_LightmapSourceFiles.m_Size > 0 )
    TransferLighting(pBSPFilename);
  if ( s_bDumpGL || s_bDumpInfo || s_nDumpLump >= 0 )
  {
    v2 = SafeOpenRead(filename: pBSPFilename);
    v3 = g_pFileSystem->Size_2(this: g_pFileSystem, a2: v2);
    v4 = operator new(nSize: v3);
    SafeRead(f: v2, buffer: v4, count: v3);
    g_pFileSystem->Close(this: g_pFileSystem, a2: v2);
    if ( s_bDumpInfo )
      DumpBSPInfo(pPrefixName: stripFilename, pBSPData: (unsigned __int8 *)v4, nBSPDataSize: v3);
    if ( s_bDumpGL )
    {
      sprintf(string: lumpFilename, format: "%s.gl", stripFilename);
      v5 = SafeOpenWrite(filename: lumpFilename);
      WriteGLBSPFile(fileHandle: v5, pBSPData: (unsigned __int8 *)v4, nBSPDataSize: v3);
      g_pFileSystem->Close(this: g_pFileSystem, a2: v5);
    }
    if ( s_nDumpLump >= 0 )
    {
      sprintf(string: lumpFilename, format: "%s_%d.bin", stripFilename, s_nDumpLump);
      v6 = SafeOpenWrite(filename: lumpFilename);
      DumpLump(fileHandle: v6, pBSPData: (unsigned __int8 *)v4, nBSPDataSize: v3, nLumpIndex: s_nDumpLump);
      g_pFileSystem->Close(this: g_pFileSystem, a2: v6);
    }
    free(pMem: v4);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004019A0
// Name: public: void CUtlVector<class CMapDisplacement,class CUtlMemory<class CMapDisplacement,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int>>::RemoveAll(
        CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  void *v5; // eax
  CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int> > *v6; // [esp+4h] [ebp-8h]
  int v7; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 68 * v1;
    v7 = 68 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 15) = 0;
      if ( *((int *)v3 + 14) >= 0 )
      {
        if ( *((_DWORD *)v3 + 12) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 12));
          *((_DWORD *)v3 + 12) = 0;
        }
        *((_DWORD *)v3 + 13) = 0;
      }
      v4 = *((void **)v3 + 12);
      *((_DWORD *)v3 + 16) = v4;
      if ( *((int *)v3 + 14) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          *((_DWORD *)v3 + 12) = 0;
        }
        *((_DWORD *)v3 + 13) = 0;
      }
      *((_DWORD *)v3 + 10) = 0;
      if ( *((int *)v3 + 9) >= 0 )
      {
        if ( *((_DWORD *)v3 + 7) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 7));
          *((_DWORD *)v3 + 7) = 0;
        }
        *((_DWORD *)v3 + 8) = 0;
      }
      v5 = *((void **)v3 + 7);
      *((_DWORD *)v3 + 11) = v5;
      if ( *((int *)v3 + 9) >= 0 )
      {
        if ( v5 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
          *((_DWORD *)v3 + 7) = 0;
        }
        *((_DWORD *)v3 + 8) = 0;
      }
      this = v6;
      --v1;
      v2 = v7 - 68;
      v7 -= 68;
    }
    while ( v1 >= 0 );
    v6->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401A90
// Name: public: void CUtlVector<struct MapBrushSide_t,class CUtlMemory<struct MapBrushSide_t,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<MapBrushSide_t,CUtlMemory<MapBrushSide_t,int>>::RemoveAll(
        CUtlVector<MapBrushSide_t,CUtlMemory<MapBrushSide_t,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<MapBrushSide_t,CUtlMemory<MapBrushSide_t,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 44 * v1;
    v5 = 44 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 4) = &CCopyableUtlVector<Vector>::`vftable';
      *((_DWORD *)v3 + 8) = 0;
      if ( *((int *)v3 + 7) >= 0 )
      {
        if ( *((_DWORD *)v3 + 5) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 5));
          this = v6;
          *((_DWORD *)v3 + 5) = 0;
        }
        *((_DWORD *)v3 + 6) = 0;
      }
      v4 = *((void **)v3 + 5);
      *((_DWORD *)v3 + 9) = v4;
      if ( *((int *)v3 + 7) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *((_DWORD *)v3 + 5) = 0;
        }
        *((_DWORD *)v3 + 6) = 0;
      }
      --v1;
      v2 = v5 - 44;
      v5 -= 44;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401B30
// Name: public: CUtlVector<class CMapDisplacement,class CUtlMemory<class CMapDisplacement,int>>::~CUtlVector<class CMapDisplacement,class CUtlMemory<class CMapDisplacement,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int>>::~CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int>>(
        CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int> > *this)
{
  bool v2; // sf
  CMapDisplacement *m_pMemory; // eax

  CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int>>::RemoveAll(this);
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
// Address: 0x00401B90
// Name: public: CUtlVector<struct MapBrushSide_t,class CUtlMemory<struct MapBrushSide_t,int>>::~CUtlVector<struct MapBrushSide_t,class CUtlMemory<struct MapBrushSide_t,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<MapBrushSide_t,CUtlMemory<MapBrushSide_t,int>>::~CUtlVector<MapBrushSide_t,CUtlMemory<MapBrushSide_t,int>>(
        CUtlVector<MapBrushSide_t,CUtlMemory<MapBrushSide_t,int> > *this)
{
  bool v2; // sf
  MapBrushSide_t *m_pMemory; // eax

  CUtlVector<MapBrushSide_t,CUtlMemory<MapBrushSide_t,int>>::RemoveAll(this);
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
// Address: 0x00401BF0
// Name: public: CSimpleMapFile::~CSimpleMapFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSimpleMapFile::~CSimpleMapFile(CSimpleMapFile *this)
{
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_MaterialInfos);
  CStringPool::~CStringPool(this: &this->m_KeyValueStringPool);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_KeyValuePairs);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_TextureData);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_TextureInfos);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_BrushTextures);
  CUtlVector<MapBrushSide_t,CUtlMemory<MapBrushSide_t,int>>::~CUtlVector<MapBrushSide_t,CUtlMemory<MapBrushSide_t,int>>(this: &this->m_BrushSides);
  CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int>>::~CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int>>(this: &this->m_Displacements);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_Brushes);
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_Entities);
  this->m_PlaneHash.m_Planes.__vftable = (CCopyableUtlVector<HashedPlane_t>_vtbl *)&CCopyableUtlVector<HashedPlane_t>::`vftable';
  CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&this->m_PlaneHash.m_Planes.CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> >);
}

//------------------------------------------------------------------------------
// Address: 0x00401C80
// Name: ProcessMap
// Source: json
//------------------------------------------------------------------------------
int __usercall ProcessMap@<eax>(const char *pVMFFilename@<eax>)
{
  CSimpleBSPFile *v2; // eax
  CSimpleBSPFile *v3; // esi
  CSimpleMapFile *v4; // esi
  char stripFilename[260]; // [esp+4h] [ebp-24Ch] BYREF
  char bspFilename[260]; // [esp+108h] [ebp-148h] BYREF
  CUtlStreamBuffer outputBSPFile; // [esp+20Ch] [ebp-44h] BYREF
  CSimpleMapFile *pMapFile; // [esp+24Ch] [ebp-4h] BYREF

  V_StripExtension(in: pVMFFilename, out: stripFilename, outSize: 260);
  sprintf(string: bspFilename, format: "%s.bsp", stripFilename);
  pMapFile = nullptr;
  CSimpleMapFile::LoadFromFile(
    pFileSystem: g_pFullFileSystem,
    pVMFFilename,
    ppNewMapFile: &pMapFile,
    instanceFlags: NO_FLAGS);
  CSimpleMapFile::ResolveInstances(
    this: pMapFile,
    instanceFlags: NO_FLAGS,
    pPostLoadInstanceHandler: nullptr,
    pHandlerContext: nullptr);
  v2 = (CSimpleBSPFile *)operator new(nSize: 0x1074u);
  if ( v2 != nullptr )
    v3 = CSimpleBSPFile::CSimpleBSPFile(this: v2);
  else
    v3 = nullptr;
  CSimpleBSPFile::CreateFromMapFile(this: v3, pMapFile);
  CUtlStreamBuffer::CUtlStreamBuffer(
    this: &outputBSPFile,
    pFileName: bspFilename,
    pPath: nullptr,
    nFlags: 0,
    bDelayOpen: false,
    nOpenFileFlags: 0);
  SaveToFile(pOutputBuffer: &outputBSPFile, pBSPFile: v3);
  CUtlStreamBuffer::Close(this: &outputBSPFile);
  ProcessBSP(pBSPFilename: bspFilename);
  if ( v3 != nullptr )
  {
    CSimpleBSPFile::~CSimpleBSPFile(this: v3);
    free(pMem: v3);
  }
  v4 = pMapFile;
  if ( pMapFile != nullptr )
  {
    CSimpleMapFile::~CSimpleMapFile(this: pMapFile);
    free(pMem: v4);
  }
  CUtlStreamBuffer::~CUtlStreamBuffer(this: &outputBSPFile);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00401D80
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  void (__thiscall ***v3)(_DWORD, int, const char **); // eax
  void *(__cdecl *FileSystemFactory)(const char *, int *); // eax
  void (*v6)(const char *, ...); // ebx
  const char *v7; // esi
  int v8; // esi
  int v9; // ebx
  int v10; // esi
  LightmapSourceFile_t *v11; // ebx
  const char *v12; // eax
  LightmapSourceFile_t *v13; // ebx
  LightmapSourceFile_t *v14; // ebx
  LightmapSourceFile_t *v15; // esi
  const char *v16; // eax
  const char *FileExtension; // esi
  char materialPath[260]; // [esp+34h] [ebp-220h] BYREF
  char filename[260]; // [esp+138h] [ebp-11Ch] BYREF
  int v21; // [esp+23Ch] [ebp-18h]
  int returnValue; // [esp+240h] [ebp-14h]
  int i; // [esp+244h] [ebp-10h]
  int v24; // [esp+248h] [ebp-Ch]
  const char **v25; // [esp+24Ch] [ebp-8h]
  const char **v26; // [esp+250h] [ebp-4h]
  const char **argva; // [esp+260h] [ebp+Ch]

  returnValue = 1;
  SetupDefaultToolsMinidumpHandler();
  v3 = (void (__thiscall ***)(_DWORD, int, const char **))_CommandLine();
  (**v3)(a1: v3, a2: argc, a3: argv);
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: false,
    bAllowSSE: false,
    bAllowSSE2: false,
    bAllowMMX: false);
  InstallSpewFunction();
  _LoggingSystem_SetChannelSpewLevelByTag(a1: "Developer", a2: 0);
  CmdLib_InitFileSystem(pFilename: argv[argc - 1], maxMemoryUsage: 0);
  sprintf(string: materialPath, format: "%smaterials", gamedir);
  FileSystemFactory = CmdLib_GetFileSystemFactory();
  InitMaterialSystem(materialBaseDirPath: materialPath, fileSystemFactory: FileSystemFactory);
  v6 = (void (*)(const char *, ...))_Msg;
  _Msg(a1: "materialPath: %s\n", materialPath);
  if ( argc >= 2 )
  {
    v8 = 1;
    i = 1;
    v9 = 6;
    v24 = 3;
    v21 = 6;
    v26 = argv + 5;
    v25 = argv + 4;
    argva = argv + 3;
    do
    {
      if ( _V_stricmp(s1: argv[v8], s2: "-gl") != 0 )
      {
        if ( _V_stricmp(s1: argv[v8], s2: "-info") != 0 )
        {
          if ( _V_stricmp(s1: argv[v8], s2: "-lump") != 0 )
          {
            if ( _V_stricmp(s1: argv[v8], s2: "-lightmap") == 0 && argc > v9 )
            {
              v10 = CUtlVector<LightmapSourceFile_t,CUtlMemory<LightmapSourceFile_t,int>>::AddToTail(this: &s_LightmapSourceFiles);
              v11 = &s_LightmapSourceFiles.m_Memory.m_pMemory[v10];
              v12 = ExpandArg(path: (char *)argv[i + 1]);
              V_strncpy(pDest: v11->m_Filename, pSrc: v12, maxLen: 260);
              v13 = &s_LightmapSourceFiles.m_Memory.m_pMemory[v10];
              v13->m_vOffset.x = atof(nptr: *argva);
              v14 = &s_LightmapSourceFiles.m_Memory.m_pMemory[v10];
              v14->m_vOffset.y = atof(nptr: *v25);
              v15 = &s_LightmapSourceFiles.m_Memory.m_pMemory[v10];
              v15->m_vOffset.z = atof(nptr: *v26);
              v8 = i;
              v9 = v21;
            }
          }
          else
          {
            if ( argc <= v24 )
            {
              v6 = (void (*)(const char *, ...))_Msg;
              v7 = "The -lump argument must be followed by an integer lump index.\n";
              _Msg(a1: "\n");
              goto LABEL_29;
            }
            s_nDumpLump = atoi(nptr: argv[v8 + 1]);
            ++argva;
            ++v25;
            ++v26;
            ++v8;
            ++v9;
            ++v24;
          }
        }
        else
        {
          s_bDumpInfo = true;
        }
      }
      else
      {
        s_bDumpGL = true;
      }
      ++argva;
      ++v25;
      ++v26;
      ++v24;
      ++v8;
      ++v9;
      i = v8;
      v21 = v9;
    }
    while ( v8 < argc );
    v6 = (void (*)(const char *, ...))_Msg;
    v16 = ExpandArg(path: (char *)argv[argc - 1]);
    V_strncpy(pDest: filename, pSrc: v16, maxLen: 260);
    V_DefaultExtension(path: filename, extension: ".vmf", pathStringLength: 260);
    FileExtension = V_GetFileExtension(path: filename);
    if ( _V_stricmp(s1: FileExtension, s2: "bsp") == 0 )
    {
      s_bNoVMF = true;
      if ( !s_bDumpGL && !s_bDumpInfo && s_nDumpLump < 0 && s_LightmapSourceFiles.m_Size <= 0 )
      {
        v7 = "When specifying a BSP file, you must specify -info, -gl, and/or -lump.";
        goto usage;
      }
      returnValue = ProcessBSP(pBSPFilename: filename);
      goto cleanup;
    }
    if ( _V_stricmp(s1: FileExtension, s2: "vmf") == 0 )
    {
      returnValue = ProcessMap(pVMFFilename: filename);
      goto cleanup;
    }
    v7 = "vbsp2.exe only reads VMF or BSP files.\n";
  }
  else
  {
    v7 = "vbsp2.exe requires at least 1 argument.\n";
  }
usage:
  v6(a1: "\n");
LABEL_29:
  v6(a1: "**USAGE**\n");
  v6(a1: "\n");
  v6(a1: "vbsp2.exe [-info] [-gl] filename.vmf\n");
  v6(a1: "vbsp2.exe [-info] [-gl] filename.bsp\n");
  v6(a1: "\n");
  v6(a1: "If a .VMF file is specified, VBSP2 will load the level and process it\n");
  v6(a1: "into a .BSP file with the same name.\n");
  v6(a1: "If no extension is specified, the file is assumed to be a .VMF.\n");
  v6(a1: "\n");
  v6(a1: "-info: Dumps information about the BSP file to a series of files named filename_*.csv/txt.\n");
  v6(a1: "-gl: Emits a glview file (.gl) with the same name.\n");
  v6(a1: "-lump <index>: Emits the given lump to a file named filename_<index>.bin.\n");
  v6(a1: "\n");
  v6(a1: "If a .BSP file is specified, -info and/or -gl must be specified.\n");
  v6(a1: "VBSP2 will then load the existing BSP file and perform the -info or -gl processing.\n");
  v6(a1: "\n");
  if ( v7 != nullptr )
    _Error(a1: v7);
cleanup:
  DeleteCmdLine(argc, (char **)argv);
  CmdLib_Cleanup();
  return returnValue;
}

//------------------------------------------------------------------------------
// Address: 0x00409670
// Name: public: int CUtlVector<struct dedge_t,class CUtlMemory<struct dedge_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dedge_t,CUtlMemory<dedge_t,int>>::InsertMultipleBefore(
        CUtlVector<CPhysCollide *,CUtlMemory<CPhysCollide *,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  struct CPhysCollide **m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ColorRGBExp32,int>::Grow((CUtlMemory<BSPCluster_t,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem] + num, src: &m_pMemory[elem], count: 4 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0040D420
// Name: public: int CUtlVector<struct ColorRGBExp32,class CUtlMemory<struct ColorRGBExp32,int>>::InsertMultipleBefore(int,int,struct ColorRGBExp32 const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ColorRGBExp32,CUtlMemory<ColorRGBExp32,int>>::InsertMultipleBefore(
        CUtlVector<CBSPFace *,CUtlMemory<CBSPFace *,int> > *this,
        int elem,
        int num,
        CBSPFace *const *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CBSPFace **m_pMemory; // ecx
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  int v12; // edx
  CBSPFace **v13; // ecx

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<ColorRGBExp32,int>::Grow((CUtlMemory<BSPCluster_t,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = elem;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem] + num, src: &m_pMemory[elem], count: 4 * v10);
  if ( pToInsert != nullptr )
  {
    v11 = 0;
    if ( num > 0 )
    {
      v12 = elem;
      do
      {
        v13 = &this->m_Memory.m_pMemory[v12];
        if ( v13 != nullptr )
        {
          *v13 = pToInsert[v11];
          v9 = elem;
        }
        ++v11;
        ++v12;
      }
      while ( v11 < num );
    }
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x0040D4C0
// Name: public: int CUtlVector<struct dbrush_t,class CUtlMemory<struct dbrush_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dbrush_t,CUtlMemory<dbrush_t,int>>::InsertMultipleBefore(
        CUtlVector<Vector,CUtlMemory<Vector,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<Vector,int>::Grow(
      (CUtlMemory<MapEntityKeyValuePair_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 12 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0040D540
// Name: public: int CUtlVector<struct HashedPlane_t,class CUtlMemory<struct HashedPlane_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int>>::InsertMultipleBefore(
        CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  HashedPlane_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<HashedPlane_t,int>::Grow((CUtlMemory<CDispBox,int> *)this, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 24 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0040DBB0
// Name: public: int CUtlVector<struct BSPCluster_t,class CUtlMemory<struct BSPCluster_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<BSPCluster_t,CUtlMemory<BSPCluster_t,int>>::AddToTail(
        CUtlVector<BSPCluster_t,CUtlMemory<BSPCluster_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  BSPCluster_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ColorRGBExp32,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x0040E590
// Name: public: int CUtlVector<class CBSPBrushSide,class CUtlMemory<class CBSPBrushSide,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::InsertMultipleBefore(
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CBSPBrushSide *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CBSPBrushSide *v11; // eax
  int elema; // [esp+10h] [ebp+8h]

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CLuxelHash::LuxelHashEntry_t,int>::Grow(
      (CUtlMemory<MapBrush_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 36 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      for ( elema = num; elema != 0; --elema )
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_nPlaneIndex = -1;
          v11->m_nTextureInfoIndex = 0;
          v11->m_SurfaceFlags = 0;
          v11->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
          v11->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
          v11->m_Polygon.m_Points.m_Memory.m_nGrowSize = 0;
          v11->m_Polygon.m_Points.m_Size = 0;
          v11->m_Polygon.m_Points.m_pElements = nullptr;
          v11->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
        }
        ++v10;
      }
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0040E920
// Name: public: int CUtlVector<class CBSPBrushSide,class CUtlMemory<class CBSPBrushSide,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::InsertBefore(
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CBSPBrushSide *m_pMemory; // ecx
  int v6; // eax
  CBSPBrushSide *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CLuxelHash::LuxelHashEntry_t,int>::Grow(
      (CUtlMemory<MapBrush_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 36 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_nPlaneIndex = -1;
    v7->m_nTextureInfoIndex = 0;
    v7->m_SurfaceFlags = 0;
    v7->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
    v7->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
    v7->m_Polygon.m_Points.m_Memory.m_nGrowSize = 0;
    v7->m_Polygon.m_Points.m_Size = 0;
    v7->m_Polygon.m_Points.m_pElements = nullptr;
    v7->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0040E9B0
// Name: public: int CUtlVector<class CBSPFace,class CUtlMemory<class CBSPFace,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CBSPFace,CUtlMemory<CBSPFace,int>>::InsertMultipleBefore(
        CUtlVector<CBSPFace,CUtlMemory<CBSPFace,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CBSPFace *m_pMemory; // ecx
  int v9; // eax
  int v10; // ecx
  CBSPFace *v11; // eax
  int elema; // [esp+10h] [ebp+8h]

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CBSPFace,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 <= 0 )
    goto LABEL_8;
  if ( num > 0 )
  {
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 40 * v9);
LABEL_8:
    if ( num > 0 )
    {
      v10 = elem;
      for ( elema = num; elema != 0; --elema )
      {
        v11 = &this->m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
        {
          v11->m_nTextureInfoIndex = -1;
          v11->m_nPlaneIndex = -1;
          v11->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
          v11->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
          v11->m_Polygon.m_Points.m_Memory.m_nGrowSize = 0;
          v11->m_Polygon.m_Points.m_Size = 0;
          v11->m_Polygon.m_Points.m_pElements = nullptr;
          v11->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
          v11->m_nDisplacementIndex = -1;
          v11->m_nSerializedFaceIndex = -1;
        }
        ++v10;
      }
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0040F1A0
// Name: public: class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near & CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::operator=(class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<Vector,CUtlMemory<Vector,int> > *__thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(
        CUtlVector<Vector,CUtlMemory<Vector,int> > *this,
        const CUtlVector<Vector,CUtlMemory<Vector,int> > *other)
{
  int m_Size; // ebx
  signed int v5; // eax
  Vector *m_pMemory; // ecx
  Vector *v7; // edx
  float *v8; // ecx
  Vector *v9; // edx
  int v10; // edx
  bool v11; // zf
  Vector *v12; // ecx
  Vector *v13; // edx
  Vector *v14; // ecx
  Vector *v15; // edx
  unsigned int v16; // edx
  int v17; // ebx
  Vector *v18; // eax
  Vector *v19; // ecx
  int i; // [esp+Ch] [ebp-8h]
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *othera; // [esp+1Ch] [ebp+8h]

  m_Size = other->m_Size;
  this->m_Size = 0;
  CUtlVector<dbrush_t,CUtlMemory<dbrush_t,int>>::InsertMultipleBefore(this, elem: 0, num: m_Size);
  v5 = 0;
  if ( m_Size >= 4 )
  {
    othera = (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)(((unsigned int)(m_Size - 4) >> 2) + 1);
    i = 4 * (_DWORD)othera;
    do
    {
      m_pMemory = other->m_Memory.m_pMemory;
      v7 = this->m_Memory.m_pMemory;
      *(float *)((char *)&v7->x + v5) = *(float *)((char *)&other->m_Memory.m_pMemory->x + v5);
      *(float *)((char *)&v7->y + v5) = *(float *)((char *)&m_pMemory->y + v5);
      *(float *)((char *)&v7->z + v5) = *(float *)((char *)&m_pMemory->z + v5);
      v8 = (float *)((char *)&other->m_Memory.m_pMemory[1].x + v5);
      v9 = this->m_Memory.m_pMemory;
      *(float *)((char *)&v9[1].x + v5) = *v8;
      v10 = (int)&v9[1] + v5;
      *(float *)(v10 + 4) = v8[1];
      v5 += 48;
      v11 = othera == (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)1;
      othera = (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)((char *)othera - 1);
      *(float *)(v10 + 8) = v8[2];
      v12 = other->m_Memory.m_pMemory;
      v13 = this->m_Memory.m_pMemory;
      *(float *)((char *)&v13[-2].x + v5) = *(float *)((char *)&other->m_Memory.m_pMemory[-2].x + v5);
      *(float *)((char *)&v13[-1] + v5 - 8) = *(float *)((char *)&v12[-1] + v5 - 8);
      *(float *)((char *)&v13[-1] + v5 - 4) = *(float *)((char *)&v12[-1] + v5 - 4);
      v14 = other->m_Memory.m_pMemory;
      v15 = this->m_Memory.m_pMemory;
      *(float *)((char *)&v15[-1].x + v5) = *(float *)((char *)&other->m_Memory.m_pMemory[-1].x + v5);
      *(float *)((char *)v15 + v5 - 8) = *(float *)((char *)v14 + v5 - 8);
      *(float *)((char *)v15 + v5 - 4) = *(float *)((char *)v14 + v5 - 4);
    }
    while ( !v11 );
    v5 = i;
  }
  if ( v5 < m_Size )
  {
    v16 = v5;
    v17 = m_Size - v5;
    do
    {
      v18 = other->m_Memory.m_pMemory;
      v19 = this->m_Memory.m_pMemory;
      v19[v16].x = other->m_Memory.m_pMemory[v16].x;
      ++v16;
      --v17;
      v19[v16 - 1].y = v18[v16 - 1].y;
      v19[v16 - 1].z = v18[v16 - 1].z;
    }
    while ( v17 != 0 );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040F2A0
// Name: public: void CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::CopyArray(class Vector const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::CopyArray(
        CUtlVector<Vector,CUtlMemory<Vector,int> > *this,
        const Vector *pArray,
        int size)
{
  int v3; // edi
  int v5; // eax
  int v6; // edx
  unsigned int v7; // edi
  float *p_z; // eax
  Vector *m_pMemory; // ecx
  char *v10; // edx
  float *v11; // ecx
  float *v12; // ecx
  double v13; // st7
  float *v14; // ecx
  float *v15; // ecx
  int v16; // edi
  double v17; // st7
  float *v18; // eax
  int i; // [esp+Ch] [ebp-Ch]

  v3 = size;
  this->m_Size = 0;
  CUtlVector<dbrush_t,CUtlMemory<dbrush_t,int>>::InsertMultipleBefore(this, elem: 0, num: size);
  v5 = 0;
  if ( size >= 4 )
  {
    v6 = -20 - (_DWORD)pArray;
    v7 = ((unsigned int)(size - 4) >> 2) + 1;
    p_z = &pArray[1].z;
    i = 4 * v7;
    while ( 1 )
    {
      m_pMemory = this->m_Memory.m_pMemory;
      v10 = (char *)p_z + v6;
      *(float *)&v10[(_DWORD)m_pMemory] = *(p_z - 5);
      *(float *)&v10[(_DWORD)m_pMemory + 4] = *(p_z - 4);
      *(float *)&v10[(_DWORD)m_pMemory + 8] = *(p_z - 3);
      v11 = (float *)&v10[(unsigned int)this->m_Memory.m_pMemory + 12];
      *v11 = *(p_z - 2);
      v11[1] = *(p_z - 1);
      v11[2] = *p_z;
      v12 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 4 - (_DWORD)pArray);
      *v12 = p_z[1];
      v12[1] = p_z[2];
      v12[2] = p_z[3];
      v13 = p_z[4];
      v14 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)p_z + 16 - (_DWORD)pArray);
      p_z += 12;
      --v7;
      *v14 = v13;
      v14[1] = *(p_z - 7);
      v14[2] = *(p_z - 6);
      if ( v7 == 0 )
        break;
      v6 = -20 - (_DWORD)pArray;
    }
    v5 = i;
    v3 = size;
  }
  if ( v5 < v3 )
  {
    v15 = &pArray[v5].z;
    v16 = v3 - v5;
    do
    {
      v17 = *(v15 - 2);
      v18 = (float *)((char *)&this->m_Memory.m_pMemory->x + (unsigned int)v15 - 8 - (_DWORD)pArray);
      v15 += 3;
      --v16;
      *v18 = v17;
      v18[1] = *(v15 - 4);
      v18[2] = *(v15 - 3);
    }
    while ( v16 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F3B0
// Name: public: class CUtlVector<struct HashedPlane_t,class CUtlMemory<struct HashedPlane_t,int>> __near & CUtlVector<struct HashedPlane_t,class CUtlMemory<struct HashedPlane_t,int>>::operator=(class CUtlVector<struct HashedPlane_t,class CUtlMemory<struct HashedPlane_t,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *__thiscall CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int>>::operator=(
        CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *this,
        const CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *other)
{
  int m_Size; // ebx
  int v5; // eax
  int v6; // edx
  HashedPlane_t *m_pMemory; // eax
  HashedPlane_t *v8; // ecx
  HashedPlane_t *v9; // eax
  HashedPlane_t *v10; // ecx
  HashedPlane_t *v11; // eax
  HashedPlane_t *v12; // ecx
  int v13; // ecx
  HashedPlane_t *v14; // ecx
  HashedPlane_t *v15; // eax
  HashedPlane_t *v16; // ecx
  HashedPlane_t *v17; // ecx
  HashedPlane_t *v18; // eax
  HashedPlane_t *v19; // ecx
  bool v20; // zf
  int v21; // edx
  HashedPlane_t *v22; // ecx
  HashedPlane_t *v23; // eax
  HashedPlane_t *v24; // ecx
  int i; // [esp+Ch] [ebp-8h]
  const CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *othera; // [esp+1Ch] [ebp+8h]
  const CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *otherb; // [esp+1Ch] [ebp+8h]

  m_Size = other->m_Size;
  this->m_Size = 0;
  CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int>>::InsertMultipleBefore(this, elem: 0, num: m_Size);
  v5 = 0;
  if ( m_Size >= 4 )
  {
    v6 = 0;
    othera = (const CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *)(((unsigned int)(m_Size - 4) >> 2) + 1);
    i = 4 * (_DWORD)othera;
    do
    {
      m_pMemory = other->m_Memory.m_pMemory;
      v8 = this->m_Memory.m_pMemory;
      v8[v6].m_vNormal.x = other->m_Memory.m_pMemory[v6].m_vNormal.x;
      v9 = &m_pMemory[v6];
      v10 = &v8[v6];
      v10->m_vNormal.y = v9->m_vNormal.y;
      v10->m_vNormal.z = v9->m_vNormal.z;
      v10->m_flDistance = v9->m_flDistance;
      v10->m_Type = v9->m_Type;
      v10->m_nNextPlaneIndex = v9->m_nNextPlaneIndex;
      v11 = &other->m_Memory.m_pMemory[v6 + 1];
      v12 = this->m_Memory.m_pMemory;
      v12[v6 + 1].m_vNormal.x = v11->m_vNormal.x;
      v13 = (int)&v12[v6 + 1];
      *(float *)(v13 + 4) = v11->m_vNormal.y;
      *(float *)(v13 + 8) = v11->m_vNormal.z;
      *(float *)(v13 + 12) = v11->m_flDistance;
      *(_DWORD *)(v13 + 16) = v11->m_Type;
      *(_DWORD *)(v13 + 20) = v11->m_nNextPlaneIndex;
      v14 = this->m_Memory.m_pMemory;
      v15 = &other->m_Memory.m_pMemory[v6 + 2];
      v14[v6 + 2].m_vNormal.x = v15->m_vNormal.x;
      v16 = &v14[v6 + 2];
      v16->m_vNormal.y = v15->m_vNormal.y;
      v16->m_vNormal.z = v15->m_vNormal.z;
      v16->m_flDistance = v15->m_flDistance;
      v16->m_Type = v15->m_Type;
      v16->m_nNextPlaneIndex = v15->m_nNextPlaneIndex;
      v17 = this->m_Memory.m_pMemory;
      v18 = &other->m_Memory.m_pMemory[v6 + 3];
      v17[v6 + 3].m_vNormal.x = v18->m_vNormal.x;
      v19 = &v17[v6 + 3];
      v6 += 4;
      v20 = othera == (const CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *)1;
      othera = (const CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *)((char *)othera - 1);
      v19->m_vNormal.y = v18->m_vNormal.y;
      v19->m_vNormal.z = v18->m_vNormal.z;
      v19->m_flDistance = v18->m_flDistance;
      v19->m_Type = v18->m_Type;
      v19->m_nNextPlaneIndex = v18->m_nNextPlaneIndex;
    }
    while ( !v20 );
    v5 = i;
  }
  if ( v5 < m_Size )
  {
    v21 = v5;
    otherb = (const CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *)(m_Size - v5);
    do
    {
      v22 = this->m_Memory.m_pMemory;
      v23 = &other->m_Memory.m_pMemory[v21];
      v22[v21].m_vNormal.x = v23->m_vNormal.x;
      v24 = &v22[v21];
      v24->m_vNormal.y = v23->m_vNormal.y;
      ++v21;
      v20 = otherb == (const CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *)1;
      otherb = (const CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *)((char *)otherb - 1);
      v24->m_vNormal.z = v23->m_vNormal.z;
      v24->m_flDistance = v23->m_flDistance;
      v24->m_Type = v23->m_Type;
      v24->m_nNextPlaneIndex = v23->m_nNextPlaneIndex;
    }
    while ( !v20 );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040F520
// Name: public: void CUtlVector<class CBSPFace,class CUtlMemory<class CBSPFace,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CBSPFace,CUtlMemory<CBSPFace,int>>::RemoveAll(
        CUtlVector<CBSPFace,CUtlMemory<CBSPFace,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<CBSPFace,CUtlMemory<CBSPFace,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 40 * v1;
    v5 = 40 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 2) = &CCopyableUtlVector<Vector>::`vftable';
      *((_DWORD *)v3 + 6) = 0;
      if ( *((int *)v3 + 5) >= 0 )
      {
        if ( *((_DWORD *)v3 + 3) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 3));
          this = v6;
          *((_DWORD *)v3 + 3) = 0;
        }
        *((_DWORD *)v3 + 4) = 0;
      }
      v4 = *((void **)v3 + 3);
      *((_DWORD *)v3 + 7) = v4;
      if ( *((int *)v3 + 5) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *((_DWORD *)v3 + 3) = 0;
        }
        *((_DWORD *)v3 + 4) = 0;
      }
      --v1;
      v2 = v5 - 40;
      v5 -= 40;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F5D0
// Name: public: void CUtlVector<class CBSPBrushSide,class CUtlMemory<class CBSPBrushSide,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::RemoveAll(
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *this)
{
  int v1; // ebx
  int v2; // eax
  char *v3; // esi
  void *v4; // eax
  int v5; // [esp+4h] [ebp-8h]
  CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *v6; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 36 * v1;
    v5 = 36 * v1;
    do
    {
      v3 = (char *)this->m_Memory.m_pMemory + v2;
      *((_DWORD *)v3 + 3) = &CCopyableUtlVector<Vector>::`vftable';
      *((_DWORD *)v3 + 7) = 0;
      if ( *((int *)v3 + 6) >= 0 )
      {
        if ( *((_DWORD *)v3 + 4) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *((void **)v3 + 4));
          this = v6;
          *((_DWORD *)v3 + 4) = 0;
        }
        *((_DWORD *)v3 + 5) = 0;
      }
      v4 = *((void **)v3 + 4);
      *((_DWORD *)v3 + 8) = v4;
      if ( *((int *)v3 + 6) >= 0 )
      {
        if ( v4 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
          this = v6;
          *((_DWORD *)v3 + 4) = 0;
        }
        *((_DWORD *)v3 + 5) = 0;
      }
      --v1;
      v2 = v5 - 36;
      v5 -= 36;
    }
    while ( v1 >= 0 );
    this->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040FEB0
// Name: public: CUtlVector<class CBSPBrushSide,class CUtlMemory<class CBSPBrushSide,int>>::~CUtlVector<class CBSPBrushSide,class CUtlMemory<class CBSPBrushSide,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::~CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>(
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *this)
{
  bool v2; // sf
  CBSPBrushSide *m_pMemory; // eax

  CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::RemoveAll(this);
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
// Address: 0x0040FF40
// Name: public: void CUtlVector<class CBSPBrushSide,class CUtlMemory<class CBSPBrushSide,int>>::CopyArray(class CBSPBrushSide const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::CopyArray(
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *this,
        const CBSPBrushSide *pArray,
        int size)
{
  int v4; // edi
  int *p_m_nTextureInfoIndex; // esi
  char *v6; // eax
  const CUtlVector<Vector,CUtlMemory<Vector,int> > *v7; // ecx

  CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::RemoveAll(this);
  v4 = size;
  CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::InsertMultipleBefore(this, elem: this->m_Size, num: size);
  if ( size > 0 )
  {
    p_m_nTextureInfoIndex = &pArray->m_nTextureInfoIndex;
    do
    {
      v6 = (char *)this->m_Memory.m_pMemory + (unsigned int)p_m_nTextureInfoIndex - 4 - (_DWORD)pArray;
      *(_DWORD *)v6 = *(p_m_nTextureInfoIndex - 1);
      *((_DWORD *)v6 + 1) = *p_m_nTextureInfoIndex;
      *((_WORD *)v6 + 4) = *((_WORD *)p_m_nTextureInfoIndex + 2);
      if ( p_m_nTextureInfoIndex == (int *)-8 )
        v7 = nullptr;
      else
        v7 = (const CUtlVector<Vector,CUtlMemory<Vector,int> > *)(p_m_nTextureInfoIndex + 3);
      CUtlVector<Vector,CUtlMemory<Vector,int>>::operator=(
        this: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)(v6 + 16),
        other: v7);
      p_m_nTextureInfoIndex += 9;
      --v4;
    }
    while ( v4 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040FFC0
// Name: public: int CUtlVector<class CBSPBrushSide,class CUtlMemory<class CBSPBrushSide,int>>::InsertBefore(int,class CBSPBrushSide const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int>>::InsertBefore(
        CUtlVector<CBSPBrushSide,CUtlMemory<CBSPBrushSide,int> > *this,
        int elem,
        const CBSPBrushSide *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CBSPBrushSide *m_pMemory; // ecx
  int v7; // eax
  CBSPBrushSide *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CLuxelHash::LuxelHashEntry_t,int>::Grow(
      (CUtlMemory<MapBrush_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 36 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
  {
    v8->m_nPlaneIndex = src->m_nPlaneIndex;
    v8->m_nTextureInfoIndex = src->m_nTextureInfoIndex;
    v8->m_SurfaceFlags = src->m_SurfaceFlags;
    v8->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
    v8->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
    v8->m_Polygon.m_Points.m_Memory.m_nGrowSize = 0;
    v8->m_Polygon.m_Points.m_Size = 0;
    v8->m_Polygon.m_Points.m_pElements = nullptr;
    v8->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
    CUtlVector<Vector,CUtlMemory<Vector,int>>::CopyArray(
      this: &v8->m_Polygon.m_Points.CUtlVector<Vector,CUtlMemory<Vector,int> >,
      pArray: src->m_Polygon.m_Points.m_Memory.m_pMemory,
      size: src->m_Polygon.m_Points.m_Size);
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00413080
// Name: public: int CUtlVector<struct dface_t,class CUtlMemory<struct dface_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dface_t,CUtlMemory<dface_t,int>>::InsertMultipleBefore(
        CUtlVector<dface_t,CUtlMemory<dface_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  dface_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<dface_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 56 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00413110
// Name: public: int CUtlVector<struct dnode_t,class CUtlMemory<struct dnode_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dnode_t,CUtlMemory<dnode_t,int>>::InsertMultipleBefore(
        CUtlVector<dtexdata_t,CUtlMemory<dtexdata_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  dtexdata_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<dleaf_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 32 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00413180
// Name: public: int CUtlVector<struct dbrushside_t,class CUtlMemory<struct dbrushside_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dbrushside_t,CUtlMemory<dbrushside_t,int>>::InsertMultipleBefore(
        CUtlVector<dbrushside_t,CUtlMemory<dbrushside_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  dbrushside_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<dbrushside_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
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
// Address: 0x00413D20
// Name: public: int CUtlVector<class Vector,class CUtlMemory<class Vector,int>>::InsertBefore(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<Vector,CUtlMemory<Vector,int>>::InsertBefore(
        CUtlVector<Vector,CUtlMemory<Vector,int> > *this,
        int elem,
        const Vector *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  Vector *m_pMemory; // ecx
  int v7; // eax
  Vector *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<Vector,int>::Grow((CUtlMemory<MapEntityKeyValuePair_t,int> *)this, num: m_Size - m_nAllocationCount + 1);
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
// Address: 0x00413DA0
// Name: public: int CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>>::InsertBefore(int,unsigned short const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertBefore(
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *this,
        int elem,
        unsigned __int16 *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned __int16 *m_pMemory; // ecx
  int v7; // eax
  unsigned __int16 *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned short,int>::Grow(
      (CUtlMemory<StaticPropLeafLump_t,int> *)this,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 2 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00413E10
// Name: public: int CUtlVector<struct dleaf_t,class CUtlMemory<struct dleaf_t,int>>::InsertBefore(int,struct dleaf_t const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dleaf_t,CUtlMemory<dleaf_t,int>>::InsertBefore(
        CUtlVector<dleaf_t,CUtlMemory<dleaf_t,int> > *this,
        int elem,
        const dleaf_t *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  dleaf_t *m_pMemory; // ecx
  int v7; // eax
  dleaf_t *v8; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<dleaf_t,int>::Grow((CUtlMemory<dtexdata_t,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 32 * v7);
  v8 = &this->m_Memory.m_pMemory[elem];
  if ( v8 != nullptr )
    *v8 = *src;
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00413EA0
// Name: public: int CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>>::InsertMultipleBefore(int,int,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::InsertMultipleBefore(
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *this,
        int elem,
        int num,
        const unsigned __int8 *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  unsigned __int8 *m_pMemory; // ecx
  int v9; // eax
  int i; // ecx
  unsigned __int8 *v11; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<char,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: v9);
  if ( pToInsert != nullptr )
  {
    for ( i = 0; i < num; ++i )
    {
      v11 = &this->m_Memory.m_pMemory[i + elem];
      if ( v11 != nullptr )
        *v11 = pToInsert[i];
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00413F30
// Name: public: int CUtlVector<struct texinfo_s,class CUtlMemory<struct texinfo_s,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int>>::InsertMultipleBefore(
        CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  texinfo_s *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<StaticPropLump_t,int>::Grow(
      (CUtlMemory<MapTextureInfo_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 72 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00413FB0
// Name: public: int CUtlVector<struct dmodel_t,class CUtlMemory<struct dmodel_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dmodel_t,CUtlMemory<dmodel_t,int>>::InsertMultipleBefore(
        CUtlVector<dmodel_t,CUtlMemory<dmodel_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  dmodel_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<dmodel_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 48 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00414030
// Name: public: int CUtlVector<class ddispinfo_t,class CUtlMemory<class ddispinfo_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<ddispinfo_t,CUtlMemory<ddispinfo_t,int>>::InsertMultipleBefore(
        CUtlVector<ddispinfo_t,CUtlMemory<ddispinfo_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  ddispinfo_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<MapBrushTexture_t,int>::Grow(
      (CUtlMemory<MapBrushTexture_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 176 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004140B0
// Name: public: int CUtlVector<class CDispVert,class CUtlMemory<class CDispVert,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDispVert,CUtlMemory<CDispVert,int>>::InsertMultipleBefore(
        CUtlVector<CDispVert,CUtlMemory<CDispVert,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDispVert *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CDispVert,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 20 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00414130
// Name: public: int CUtlVector<unsigned short,class CUtlMemory<unsigned short,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
        CUtlVector<CDispTri,CUtlMemory<CDispTri,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDispTri *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<unsigned short,int>::Grow(
      (CUtlMemory<StaticPropLeafLump_t,int> *)this,
      num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 2 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x004141A0
// Name: public: int CUtlVector<class CDispMultiBlend,class CUtlMemory<class CDispMultiBlend,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CDispMultiBlend,CUtlMemory<CDispMultiBlend,int>>::InsertMultipleBefore(
        CUtlVector<CDispMultiBlend,CUtlMemory<CDispMultiBlend,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CDispMultiBlend *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CDispMultiBlend,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 80 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00414220
// Name: public: int CUtlVector<struct dworldlight_t,class CUtlMemory<struct dworldlight_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dworldlight_t,CUtlMemory<dworldlight_t,int>>::InsertMultipleBefore(
        CUtlVector<dworldlight_t,CUtlMemory<dworldlight_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  dworldlight_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<dworldlight_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 100 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00414520
// Name: public: int CUtlVector<struct dnode_t,class CUtlMemory<struct dnode_t,int>>::AddToTail(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dnode_t,CUtlMemory<dnode_t,int>>::AddToTail(
        CUtlVector<dnode_t,CUtlMemory<dnode_t,int> > *this)
{
  int m_nAllocationCount; // eax
  int m_Size; // edi
  dnode_t *m_pMemory; // ecx
  int v5; // eax

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  m_Size = this->m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<dleaf_t,int>::Grow((CUtlMemory<dtexdata_t,int> *)this, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = this->m_Size - m_Size - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v5 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 32 * v5);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00415D30
// Name: private: void CMemoryBSPFile::ReadLump<struct texinfo_s>(int,class CUtlVector<struct texinfo_s,class CUtlMemory<struct texinfo_s,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::ReadLump<texinfo_s>(
        CMemoryBSPFile *this,
        int nLump,
        CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int> > *pVector)
{
  int fileofs; // eax
  int filelen; // ebx

  fileofs = this->m_FileHeader.lumps[nLump].fileofs;
  if ( fileofs > 0 )
    CUtlBuffer::SeekGet(this: this->m_pSerialBuffer, type: SEEK_HEAD, offset: fileofs);
  filelen = this->m_FileHeader.lumps[nLump].filelen;
  pVector->m_Size = 0;
  CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int>>::InsertMultipleBefore(this: pVector, elem: 0, num: filelen / 0x48u);
  if ( filelen > 0 )
    CUtlBuffer::Get(this: this->m_pSerialBuffer, pMem: pVector->m_Memory.m_pMemory, size: 72 * pVector->m_Size);
}

//------------------------------------------------------------------------------
// Address: 0x00415DA0
// Name: private: void CMemoryBSPFile::ReadLump<class Vector>(int,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::ReadLump<Vector>(
        CMemoryBSPFile *this,
        int nLump,
        CUtlVector<Vector,CUtlMemory<Vector,int> > *pVector)
{
  int fileofs; // eax
  int filelen; // ebx

  fileofs = this->m_FileHeader.lumps[nLump].fileofs;
  if ( fileofs > 0 )
    CUtlBuffer::SeekGet(this: this->m_pSerialBuffer, type: SEEK_HEAD, offset: fileofs);
  filelen = this->m_FileHeader.lumps[nLump].filelen;
  pVector->m_Size = 0;
  CUtlVector<dbrush_t,CUtlMemory<dbrush_t,int>>::InsertMultipleBefore(this: pVector, elem: 0, num: filelen / 0xCu);
  if ( filelen > 0 )
    CUtlBuffer::Get(this: this->m_pSerialBuffer, pMem: pVector->m_Memory.m_pMemory, size: 12 * pVector->m_Size);
}

//------------------------------------------------------------------------------
// Address: 0x00415E10
// Name: private: void CMemoryBSPFile::ReadLump<struct dface_t>(int,class CUtlVector<struct dface_t,class CUtlMemory<struct dface_t,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::ReadLump<dface_t>(
        CMemoryBSPFile *this,
        int nLump,
        CUtlVector<dface_t,CUtlMemory<dface_t,int> > *pVector)
{
  int fileofs; // eax
  int filelen; // esi

  fileofs = this->m_FileHeader.lumps[nLump].fileofs;
  if ( fileofs > 0 )
    CUtlBuffer::SeekGet(this: this->m_pSerialBuffer, type: SEEK_HEAD, offset: fileofs);
  filelen = this->m_FileHeader.lumps[nLump].filelen;
  pVector->m_Size = 0;
  CUtlVector<dface_t,CUtlMemory<dface_t,int>>::InsertMultipleBefore(this: pVector, elem: 0, num: filelen / 0x38u);
  if ( filelen > 0 )
    CUtlBuffer::Get(this: this->m_pSerialBuffer, pMem: pVector->m_Memory.m_pMemory, size: 56 * pVector->m_Size);
}

//------------------------------------------------------------------------------
// Address: 0x00415E90
// Name: private: void CMemoryBSPFile::ReadLump<struct dmodel_t>(int,class CUtlVector<struct dmodel_t,class CUtlMemory<struct dmodel_t,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::ReadLump<dmodel_t>(
        CMemoryBSPFile *this,
        int nLump,
        CUtlVector<dmodel_t,CUtlMemory<dmodel_t,int> > *pVector)
{
  int fileofs; // eax
  int filelen; // ebx

  fileofs = this->m_FileHeader.lumps[nLump].fileofs;
  if ( fileofs > 0 )
    CUtlBuffer::SeekGet(this: this->m_pSerialBuffer, type: SEEK_HEAD, offset: fileofs);
  filelen = this->m_FileHeader.lumps[nLump].filelen;
  pVector->m_Size = 0;
  CUtlVector<dmodel_t,CUtlMemory<dmodel_t,int>>::InsertMultipleBefore(this: pVector, elem: 0, num: filelen / 0x30u);
  if ( filelen > 0 )
    CUtlBuffer::Get(this: this->m_pSerialBuffer, pMem: pVector->m_Memory.m_pMemory, size: 48 * pVector->m_Size);
}

//------------------------------------------------------------------------------
// Address: 0x00415F00
// Name: private: void CMemoryBSPFile::ReadLump<class CDispVert>(int,class CUtlVector<class CDispVert,class CUtlMemory<class CDispVert,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::ReadLump<CDispVert>(
        CMemoryBSPFile *this,
        int nLump,
        CUtlVector<CDispVert,CUtlMemory<CDispVert,int> > *pVector)
{
  int fileofs; // eax
  int filelen; // ebx

  fileofs = this->m_FileHeader.lumps[nLump].fileofs;
  if ( fileofs > 0 )
    CUtlBuffer::SeekGet(this: this->m_pSerialBuffer, type: SEEK_HEAD, offset: fileofs);
  filelen = this->m_FileHeader.lumps[nLump].filelen;
  pVector->m_Size = 0;
  CUtlVector<CDispVert,CUtlMemory<CDispVert,int>>::InsertMultipleBefore(this: pVector, elem: 0, num: filelen / 0x14u);
  if ( filelen > 0 )
    CUtlBuffer::Get(this: this->m_pSerialBuffer, pMem: pVector->m_Memory.m_pMemory, size: 20 * pVector->m_Size);
}

//------------------------------------------------------------------------------
// Address: 0x00415F70
// Name: private: void CMemoryBSPFile::ReadLump<class CDispMultiBlend>(int,class CUtlVector<class CDispMultiBlend,class CUtlMemory<class CDispMultiBlend,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::ReadLump<CDispMultiBlend>(
        CMemoryBSPFile *this,
        int nLump,
        CUtlVector<CDispMultiBlend,CUtlMemory<CDispMultiBlend,int> > *pVector)
{
  int fileofs; // eax
  int filelen; // ebx

  fileofs = this->m_FileHeader.lumps[nLump].fileofs;
  if ( fileofs > 0 )
    CUtlBuffer::SeekGet(this: this->m_pSerialBuffer, type: SEEK_HEAD, offset: fileofs);
  filelen = this->m_FileHeader.lumps[nLump].filelen;
  pVector->m_Size = 0;
  CUtlVector<CDispMultiBlend,CUtlMemory<CDispMultiBlend,int>>::InsertMultipleBefore(
    this: pVector,
    elem: 0,
    num: filelen / 0x50u);
  if ( filelen > 0 )
    CUtlBuffer::Get(this: this->m_pSerialBuffer, pMem: pVector->m_Memory.m_pMemory, size: 80 * pVector->m_Size);
}

//------------------------------------------------------------------------------
// Address: 0x0041AB50
// Name: public: int CUtlVector<struct dworldlight_t,class CUtlMemory<struct dworldlight_t,int>>::InsertMultipleBefore(int,int,struct dworldlight_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<dworldlight_t,CUtlMemory<dworldlight_t,int>>::InsertMultipleBefore(
        CUtlVector<dworldlight_t,CUtlMemory<dworldlight_t,int> > *this,
        int elem,
        int num,
        const dworldlight_t *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  dworldlight_t *m_pMemory; // ecx
  int v9; // edi
  int v10; // eax
  const dworldlight_t *v11; // edx
  int v12; // eax
  dworldlight_t *v13; // edi

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<dworldlight_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = elem;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 100 * v10);
  v11 = pToInsert;
  if ( pToInsert != nullptr && num > 0 )
  {
    v12 = elem;
    do
    {
      v13 = &this->m_Memory.m_pMemory[v12];
      if ( v13 != nullptr )
        qmemcpy(v13, v11, sizeof(dworldlight_t));
      ++v12;
      ++v11;
      --num;
    }
    while ( num != 0 );
    return elem;
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x0041CEE0
// Name: public: int CUtlVector<struct MapEntity_t,class CUtlMemory<struct MapEntity_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<MapEntity_t,CUtlMemory<MapEntity_t,int>>::InsertBefore(
        CUtlVector<MapEntity_t,CUtlMemory<MapEntity_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  MapEntity_t *m_pMemory; // ecx
  int v6; // eax
  int v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<MapEntity_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v7 = v6 - elem - 1;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 28 * v7);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041CF50
// Name: public: int CUtlVector<struct MapBrush_t,class CUtlMemory<struct MapBrush_t,int>>::InsertMultipleBefore(int,int,struct MapBrush_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<MapBrush_t,CUtlMemory<MapBrush_t,int>>::InsertMultipleBefore(
        CUtlVector<MapBrush_t,CUtlMemory<MapBrush_t,int> > *this,
        int elem,
        int num,
        const MapBrush_t *pToInsert)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  MapBrush_t *m_pMemory; // ecx
  int v10; // eax
  const MapBrush_t *v11; // ecx
  int v12; // edx
  MapBrush_t *v13; // eax
  int elema; // [esp+10h] [ebp+8h]

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CLuxelHash::LuxelHashEntry_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v10 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v10 > 0 && num > 0 )
    _V_memmove(dest: (void *)&m_pMemory[elem + num], src: &m_pMemory[elem], count: 36 * v10);
  v11 = pToInsert;
  if ( pToInsert != nullptr && num > 0 )
  {
    v12 = elem;
    for ( elema = num; elema != 0; --elema )
    {
      v13 = &this->m_Memory.m_pMemory[v12];
      if ( v13 != nullptr )
      {
        *(_QWORD *)&v13->m_ContentsFlags = *(_QWORD *)&v11->m_ContentsFlags;
        *(_QWORD *)&v13->m_nNumSides = *(_QWORD *)&v11->m_nNumSides;
        *(_QWORD *)&v13->m_vMinBounds.y = *(_QWORD *)&v11->m_vMinBounds.y;
        *(_QWORD *)&v13->m_vMaxBounds.x = *(_QWORD *)&v11->m_vMaxBounds.x;
        v13->m_vMaxBounds.z = v11->m_vMaxBounds.z;
      }
      ++v12;
      ++v11;
    }
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041D020
// Name: public: int CUtlVector<struct CMapDisplacement::Vertex_t,class CUtlMemory<struct CMapDisplacement::Vertex_t,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CMapDisplacement::Vertex_t,CUtlMemory<CMapDisplacement::Vertex_t,int>>::InsertMultipleBefore(
        CUtlVector<CMapDisplacement::Vertex_t,CUtlMemory<CMapDisplacement::Vertex_t,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CMapDisplacement::Vertex_t *m_pMemory; // ecx
  int v8; // eax
  int v9; // eax

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CMapDisplacement::Vertex_t,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v8 = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v9 = v8 - elem - num;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: &m_pMemory[elem + num], src: &m_pMemory[elem], count: 96 * v9);
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041EF20
// Name: public: int CUtlVector<class CMapDisplacement,class CUtlMemory<class CMapDisplacement,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int>>::InsertBefore(
        CUtlVector<CMapDisplacement,CUtlMemory<CMapDisplacement,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CMapDisplacement *m_pMemory; // ecx
  int v6; // eax
  CMapDisplacement *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CMapDisplacement,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 68 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_nPower = 0;
    v7->m_nOriginalBrushSide = -1;
    v7->m_nFlags = 0;
    v7->m_ContentsFlags = 0;
    v7->m_vStartPosition.x = 0.0;
    v7->m_vStartPosition.y = 0.0;
    v7->m_vStartPosition.z = 0.0;
    v7->m_Vertices.m_Memory.m_pMemory = nullptr;
    v7->m_Vertices.m_Memory.m_nAllocationCount = 0;
    v7->m_Vertices.m_Memory.m_nGrowSize = 0;
    v7->m_Vertices.m_Size = 0;
    v7->m_Vertices.m_pElements = nullptr;
    v7->m_TriangleTags.m_Memory.m_pMemory = nullptr;
    v7->m_TriangleTags.m_Memory.m_nAllocationCount = 0;
    v7->m_TriangleTags.m_Memory.m_nGrowSize = 0;
    v7->m_TriangleTags.m_Size = 0;
    v7->m_TriangleTags.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x0041F7C0
// Name: public: int CUtlVector<struct MapBrushSide_t,class CUtlMemory<struct MapBrushSide_t,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<MapBrushSide_t,CUtlMemory<MapBrushSide_t,int>>::InsertBefore(
        CUtlVector<MapBrushSide_t,CUtlMemory<MapBrushSide_t,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  MapBrushSide_t *m_pMemory; // ecx
  int v6; // eax
  MapBrushSide_t *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<MapBrushSide_t,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 44 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_Polygon.m_Points.m_Memory.m_pMemory = nullptr;
    v7->m_Polygon.m_Points.m_Memory.m_nAllocationCount = 0;
    v7->m_Polygon.m_Points.m_Memory.m_nGrowSize = 0;
    v7->m_Polygon.m_Points.m_Size = 0;
    v7->m_Polygon.m_Points.m_pElements = nullptr;
    v7->m_Polygon.m_Points.__vftable = (CCopyableUtlVector<Vector>_vtbl *)&CCopyableUtlVector<Vector>::`vftable';
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00444620
// Name: public: void CUtlVector<char __near *,class CUtlMemory<char __near *,int>>::PurgeAndDeleteElements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(
        CUtlVector<char *,CUtlMemory<char *,int> > *this)
{
  int i; // edi
  bool v3; // sf
  char **m_pMemory; // ecx

  for ( i = 0; i < this->m_Size; ++i )
    free(pMem: this->m_Memory.m_pMemory[i]);
  v3 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( v3 )
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
// Address: 0x00445DD0
// Name: public: void CUtlVector<struct FGDVisGroupsBaseClass_s,class CUtlMemory<struct FGDVisGroupsBaseClass_s,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int>>::RemoveAll(
        CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int> > *this)
{
  int v1; // ebx
  int v2; // edx
  CUtlVector<char *,CUtlMemory<char *,int> > *v3; // esi
  char **m_pMemory; // eax
  CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int> > *v5; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]

  v1 = this->m_Size - 1;
  v5 = this;
  if ( v1 < 0 )
  {
    this->m_Size = 0;
  }
  else
  {
    v2 = 280 * v1;
    for ( i = 280 * v1; ; v2 = i )
    {
      v3 = (CUtlVector<char *,CUtlMemory<char *,int> > *)&this->m_Memory.m_pMemory->szClass[v2];
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: v3 + 13);
      v3[13].m_Size = 0;
      if ( v3[13].m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3[13].m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3[13].m_Memory.m_pMemory);
          v3[13].m_Memory.m_pMemory = nullptr;
        }
        v3[13].m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = v3[13].m_Memory.m_pMemory;
      v3[13].m_pElements = m_pMemory;
      if ( v3[13].m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3[13].m_Memory.m_pMemory = nullptr;
        }
        v3[13].m_Memory.m_nAllocationCount = 0;
      }
      i -= 280;
      this = v5;
      if ( --v1 < 0 )
        break;
    }
    v5->m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00446B10
// Name: public: int CUtlVector<struct FGDVisGroupsBaseClass_s,class CUtlMemory<struct FGDVisGroupsBaseClass_s,int>>::InsertBefore(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int>>::InsertBefore(
        CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int> > *this,
        int elem)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  FGDAutoVisGroups_s *m_pMemory; // ecx
  int v6; // eax
  FGDAutoVisGroups_s *v7; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<FGDAutoVisGroups_s,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v6 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 280 * v6);
  v7 = &this->m_Memory.m_pMemory[elem];
  if ( v7 != nullptr )
  {
    v7->m_Classes.m_Memory.m_pMemory = nullptr;
    v7->m_Classes.m_Memory.m_nAllocationCount = 0;
    v7->m_Classes.m_Memory.m_nGrowSize = 0;
    v7->m_Classes.m_Size = 0;
    v7->m_Classes.m_pElements = nullptr;
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00446BA0
// Name: public: void CUtlVector<struct FGDAutoVisGroups_s,class CUtlMemory<struct FGDAutoVisGroups_s,int>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int>>::RemoveAll(
        CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int> > *this)
{
  int v1; // edi
  int v2; // ebx
  FGDAutoVisGroups_s *v3; // esi
  bool v4; // sf
  FGDVisGroupsBaseClass_s *m_pMemory; // eax
  CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int> > *v6; // [esp+4h] [ebp-4h]

  v1 = this->m_Size - 1;
  v6 = this;
  if ( v1 >= 0 )
  {
    v2 = v1;
    do
    {
      v3 = &this->m_Memory.m_pMemory[v2];
      CUtlVector<FGDVisGroupsBaseClass_s,CUtlMemory<FGDVisGroupsBaseClass_s,int>>::RemoveAll(this: &v3->m_Classes);
      if ( v3->m_Classes.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v3->m_Classes.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3->m_Classes.m_Memory.m_pMemory);
          v3->m_Classes.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Classes.m_Memory.m_nAllocationCount = 0;
      }
      v4 = v3->m_Classes.m_Memory.m_nGrowSize < 0;
      m_pMemory = v3->m_Classes.m_Memory.m_pMemory;
      v3->m_Classes.m_pElements = m_pMemory;
      if ( !v4 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          v3->m_Classes.m_Memory.m_pMemory = nullptr;
        }
        v3->m_Classes.m_Memory.m_nAllocationCount = 0;
      }
      this = v6;
      --v2;
      --v1;
    }
    while ( v1 >= 0 );
  }
  this->m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004470D0
// Name: public: CUtlVector<struct FGDAutoVisGroups_s,class CUtlMemory<struct FGDAutoVisGroups_s,int>>::~CUtlVector<struct FGDAutoVisGroups_s,class CUtlMemory<struct FGDAutoVisGroups_s,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int>>::~CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int>>(
        CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int> > *this)
{
  bool v2; // sf
  FGDAutoVisGroups_s *m_pMemory; // eax

  CUtlVector<FGDAutoVisGroups_s,CUtlMemory<FGDAutoVisGroups_s,int>>::RemoveAll(this);
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
// Address: 0x004492B0
// Name: public: int CUtlVector<struct GDIVITEM,class CUtlMemory<struct GDIVITEM,int>>::InsertBefore(int,struct GDIVITEM const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<GDIVITEM,CUtlMemory<GDIVITEM,int>>::InsertBefore(
        CUtlVector<GDIVITEM,CUtlMemory<GDIVITEM,int> > *this,
        int elem,
        const GDIVITEM *src)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  GDIVITEM *m_pMemory; // ecx
  int v7; // eax
  int result; // eax

  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<GDIVITEM,int>::Grow(this: &this->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  v7 = this->m_Size - elem - 1;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[elem + 1], src: &m_pMemory[elem], count: 268 * v7);
  result = elem;
  if ( &this->m_Memory.m_pMemory[elem] != nullptr )
    qmemcpy(&this->m_Memory.m_pMemory[elem], src, sizeof(this->m_Memory.m_pMemory[elem]));
  return result;
}
