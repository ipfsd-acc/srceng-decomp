// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vbsp2lib/serializesimplebspfile.cpp
// Functions: 53
// ============================================================

#include "vbsp2lib\serializesimplebspfile.h"

//------------------------------------------------------------------------------
// Address: 0x10067FC0
// Name: void Vector2DCopy(class Vector2D const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector2DCopy(const Vector2D *src, Vector2D *dst)
{
  *dst = *src;
}

//------------------------------------------------------------------------------
// Address: 0x10067FE0
// Name: public: class CCoreDispSurface __near * CCoreDispInfo::GetSurface(void)
// Source: json
//------------------------------------------------------------------------------
CCoreDispSurface *__thiscall CCoreDispInfo::GetSurface(CCoreDispInfo *this)
{
  return &this->m_Surf;
}

//------------------------------------------------------------------------------
// Address: 0x10067FF0
// Name: private: void CMemoryBSPFile::WriteLump(int,void const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump(
        CMemoryBSPFile *this,
        int nLump,
        unsigned __int8 *pData,
        int nByteLength,
        int nVersion)
{
  int v6; // ecx
  int v7; // eax
  int v8; // edx
  int v9; // ecx
  CUtlBuffer *m_pSerialBuffer; // ecx
  int m_Put; // edi
  int v12; // eax

  v6 = nLump;
  v7 = nLump;
  this->m_FileHeader.lumps[v7].fileofs = this->m_pSerialBuffer->m_Put;
  v8 = v6 + 259;
  v9 = nByteLength;
  *((_DWORD *)&this->m_pSerialBuffer + 4 * v8) = nByteLength;
  this->m_FileHeader.lumps[v7].version = nVersion;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: pData, size: v9);
  m_pSerialBuffer = this->m_pSerialBuffer;
  m_Put = this->m_pSerialBuffer->m_Put;
  v12 = 4 * ((m_Put + 3) / 4);
  if ( v12 > m_Put )
  {
    LOBYTE(nLump) = 0;
    *(_WORD *)((char *)&nLump + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&nLump, size: v12 - m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100686A0
// Name: private: struct MapBrushSide_t const __near * CMemoryBSPFile::FindClosestBrushSide(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
const MapBrushSide_t *__thiscall CMemoryBSPFile::FindClosestBrushSide(
        CMemoryBSPFile *this,
        const MapBrushSide_t *nBrushIndex,
        const Vector *vNormal)
{
  const CSimpleMapFile *m_pMapFile; // edx
  float v4; // xmm0_4
  int v6; // esi
  int v7; // eax
  int v8; // edi
  HashedPlane_t *m_pMemory; // ecx
  float y; // xmm2_4
  float x; // xmm3_4
  float z; // xmm4_4
  int v13; // edx
  const MapBrushSide_t *v14; // esi
  _DWORD *v15; // edi
  unsigned int v16; // edx
  int v17; // ecx
  int v18; // eax
  const CSimpleMapFile *v20; // [esp+0h] [ebp-10h]
  const MapBrush_t *pBrush; // [esp+8h] [ebp-8h]
  CMemoryBSPFile *v22; // [esp+Ch] [ebp-4h]
  const MapBrushSide_t *pBestSide; // [esp+18h] [ebp+8h]
  int i; // [esp+1Ch] [ebp+Ch]
  HashedPlane_t *ia; // [esp+1Ch] [ebp+Ch]

  m_pMapFile = this->m_pMapFile;
  v4 = -1.0;
  v6 = (int)&m_pMapFile->m_Brushes.m_Memory.m_pMemory[(_DWORD)nBrushIndex];
  v7 = *(_DWORD *)(v6 + 8);
  v8 = 0;
  v22 = this;
  v20 = m_pMapFile;
  pBrush = (const MapBrush_t *)v6;
  pBestSide = nullptr;
  if ( v7 >= 4 )
  {
    m_pMemory = this->m_PlaneHash.m_Planes.m_Memory.m_pMemory;
    y = vNormal->y;
    x = vNormal->x;
    z = vNormal->z;
    v13 = (int)&m_pMapFile->m_BrushSides.m_Memory.m_pMemory[*(_DWORD *)(v6 + 4)];
    v14 = (const MapBrushSide_t *)(v13 + 44);
    v15 = (_DWORD *)(v13 + 96);
    v16 = ((unsigned int)(v7 - 4) >> 2) + 1;
    i = 4 * v16;
    do
    {
      if ( (float)((float)((float)(m_pMemory[v14[-1].m_nPlaneIndex].m_vNormal.y * y)
                         + (float)(x * m_pMemory[v14[-1].m_nPlaneIndex].m_vNormal.x))
                 + (float)(m_pMemory[v14[-1].m_nPlaneIndex].m_vNormal.z * z)) > v4 )
      {
        v4 = (float)((float)(m_pMemory[v14[-1].m_nPlaneIndex].m_vNormal.y * y)
                   + (float)(x * m_pMemory[v14[-1].m_nPlaneIndex].m_vNormal.x))
           + (float)(m_pMemory[v14[-1].m_nPlaneIndex].m_vNormal.z * z);
        pBestSide = v14 - 1;
      }
      if ( (float)((float)((float)(m_pMemory[*(v15 - 11)].m_vNormal.y * y)
                         + (float)(x * m_pMemory[*(v15 - 11)].m_vNormal.x))
                 + (float)(m_pMemory[*(v15 - 11)].m_vNormal.z * z)) > v4 )
      {
        v4 = (float)((float)(m_pMemory[*(v15 - 11)].m_vNormal.y * y) + (float)(x * m_pMemory[*(v15 - 11)].m_vNormal.x))
           + (float)(m_pMemory[*(v15 - 11)].m_vNormal.z * z);
        pBestSide = v14;
      }
      if ( (float)((float)((float)(m_pMemory[*v15].m_vNormal.y * y) + (float)(x * m_pMemory[*v15].m_vNormal.x))
                 + (float)(m_pMemory[*v15].m_vNormal.z * z)) > v4 )
      {
        v4 = (float)((float)(m_pMemory[*v15].m_vNormal.y * y) + (float)(x * m_pMemory[*v15].m_vNormal.x))
           + (float)(m_pMemory[*v15].m_vNormal.z * z);
        pBestSide = v14 + 1;
      }
      if ( (float)((float)((float)(m_pMemory[v15[11]].m_vNormal.y * y) + (float)(x * m_pMemory[v15[11]].m_vNormal.x))
                 + (float)(m_pMemory[v15[11]].m_vNormal.z * z)) > v4 )
      {
        v4 = (float)((float)(m_pMemory[v15[11]].m_vNormal.y * y) + (float)(x * m_pMemory[v15[11]].m_vNormal.x))
           + (float)(m_pMemory[v15[11]].m_vNormal.z * z);
        pBestSide = v14 + 2;
      }
      v14 += 4;
      v15 += 44;
      --v16;
    }
    while ( v16 != 0 );
    this = v22;
    v6 = (int)pBrush;
    v8 = i;
    m_pMapFile = v20;
  }
  if ( v8 < v7 )
  {
    ia = this->m_PlaneHash.m_Planes.m_Memory.m_pMemory;
    v17 = (int)&m_pMapFile->m_BrushSides.m_Memory.m_pMemory[v8 + *(_DWORD *)(v6 + 4)];
    v18 = v7 - v8;
    do
    {
      if ( (float)((float)((float)(ia[*(_DWORD *)(v17 + 8)].m_vNormal.y * vNormal->y)
                         + (float)(vNormal->x * ia[*(_DWORD *)(v17 + 8)].m_vNormal.x))
                 + (float)(ia[*(_DWORD *)(v17 + 8)].m_vNormal.z * vNormal->z)) > v4 )
      {
        v4 = (float)((float)(ia[*(_DWORD *)(v17 + 8)].m_vNormal.y * vNormal->y)
                   + (float)(vNormal->x * ia[*(_DWORD *)(v17 + 8)].m_vNormal.x))
           + (float)(ia[*(_DWORD *)(v17 + 8)].m_vNormal.z * vNormal->z);
        pBestSide = (const MapBrushSide_t *)v17;
      }
      v17 += 44;
      --v18;
    }
    while ( v18 != 0 );
  }
  return pBestSide;
}

//------------------------------------------------------------------------------
// Address: 0x100688A0
// Name: private: void CMemoryBSPFile::WriteLump<struct texinfo_s>(int,class CUtlVector<struct texinfo_s,class CUtlMemory<struct texinfo_s,int>> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump<texinfo_s>(
        CMemoryBSPFile *this,
        int nLump,
        const CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int> > *data,
        int nVersion)
{
  const CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int> > *v4; // eax
  int m_Put; // ebx
  int v7; // ecx
  int v8; // edx
  CUtlBuffer *m_pSerialBuffer; // ecx
  int v10; // edi
  int v11; // eax

  v4 = data;
  m_Put = this->m_pSerialBuffer->m_Put;
  v7 = 72 * data->m_Size;
  v8 = nLump;
  this->m_FileHeader.lumps[v8].fileofs = m_Put;
  this->m_FileHeader.lumps[nLump].filelen = v7;
  this->m_FileHeader.lumps[v8].version = nVersion;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)v4->m_Memory.m_pMemory, size: 72 * v4->m_Size);
  m_pSerialBuffer = this->m_pSerialBuffer;
  v10 = this->m_pSerialBuffer->m_Put;
  v11 = 4 * ((v10 + 3) / 4);
  if ( v11 > v10 )
  {
    LOBYTE(data) = 0;
    *(_WORD *)((char *)&data + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&data, size: v11 - v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068930
// Name: private: void CMemoryBSPFile::WriteLump<char>(int,class CUtlVector<char,class CUtlMemory<char,int>> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump<char>(
        CMemoryBSPFile *this,
        int nLump,
        const CUtlVector<char,CUtlMemory<char,int> > *data,
        int nVersion)
{
  const CUtlVector<char,CUtlMemory<char,int> > *v4; // eax
  int m_Put; // ebx
  int v7; // ecx
  int v8; // edx
  CUtlBuffer *m_pSerialBuffer; // ecx
  int v10; // edi
  int v11; // eax

  v4 = data;
  m_Put = this->m_pSerialBuffer->m_Put;
  v7 = nLump;
  this->m_FileHeader.lumps[nLump].filelen = data->m_Size;
  v8 = nVersion;
  this->m_FileHeader.lumps[v7].fileofs = m_Put;
  this->m_FileHeader.lumps[v7].version = v8;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)v4->m_Memory.m_pMemory, size: v4->m_Size);
  m_pSerialBuffer = this->m_pSerialBuffer;
  v10 = this->m_pSerialBuffer->m_Put;
  v11 = 4 * ((v10 + 3) / 4);
  if ( v11 > v10 )
  {
    LOBYTE(data) = 0;
    *(_WORD *)((char *)&data + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&data, size: v11 - v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100689B0
// Name: private: void CMemoryBSPFile::WriteLump<struct dedge_t>(int,class CUtlVector<struct dedge_t,class CUtlMemory<struct dedge_t,int>> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump<dedge_t>(
        CMemoryBSPFile *this,
        int nLump,
        const CUtlVector<dedge_t,CUtlMemory<dedge_t,int> > *data,
        int nVersion)
{
  const CUtlVector<dedge_t,CUtlMemory<dedge_t,int> > *v4; // eax
  int m_Put; // ebx
  int v7; // ecx
  int v8; // edx
  CUtlBuffer *m_pSerialBuffer; // ecx
  int v10; // edi
  int v11; // eax

  v4 = data;
  m_Put = this->m_pSerialBuffer->m_Put;
  v7 = nLump;
  v8 = 4 * data->m_Size;
  this->m_FileHeader.lumps[v7].fileofs = m_Put;
  this->m_FileHeader.lumps[nLump].filelen = v8;
  this->m_FileHeader.lumps[v7].version = nVersion;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)v4->m_Memory.m_pMemory, size: 4 * v4->m_Size);
  m_pSerialBuffer = this->m_pSerialBuffer;
  v10 = this->m_pSerialBuffer->m_Put;
  v11 = 4 * ((v10 + 3) / 4);
  if ( v11 > v10 )
  {
    LOBYTE(data) = 0;
    *(_WORD *)((char *)&data + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&data, size: v11 - v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068A40
// Name: private: void CMemoryBSPFile::WriteLump<struct dface_t>(int,class CUtlVector<struct dface_t,class CUtlMemory<struct dface_t,int>> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump<dface_t>(
        CMemoryBSPFile *this,
        int nLump,
        const CUtlVector<dface_t,CUtlMemory<dface_t,int> > *data,
        int nVersion)
{
  const CUtlVector<dface_t,CUtlMemory<dface_t,int> > *v4; // eax
  int m_Size; // ecx
  int v7; // edx
  CUtlBuffer *m_pSerialBuffer; // ecx
  int m_Put; // edi
  int v10; // eax

  v4 = data;
  m_Size = data->m_Size;
  v7 = nLump;
  this->m_FileHeader.lumps[v7].fileofs = this->m_pSerialBuffer->m_Put;
  this->m_FileHeader.lumps[v7].version = nVersion;
  this->m_FileHeader.lumps[nLump].filelen = 56 * m_Size;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)v4->m_Memory.m_pMemory, size: 56 * v4->m_Size);
  m_pSerialBuffer = this->m_pSerialBuffer;
  m_Put = this->m_pSerialBuffer->m_Put;
  v10 = 4 * ((m_Put + 3) / 4);
  if ( v10 > m_Put )
  {
    LOBYTE(data) = 0;
    *(_WORD *)((char *)&data + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&data, size: v10 - m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068AE0
// Name: private: void CMemoryBSPFile::WriteLump<struct dleaf_t>(int,class CUtlVector<struct dleaf_t,class CUtlMemory<struct dleaf_t,int>> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump<dleaf_t>(
        CMemoryBSPFile *this,
        int nLump,
        const CUtlVector<dnode_t,CUtlMemory<dnode_t,int> > *data,
        int nVersion)
{
  const CUtlVector<dnode_t,CUtlMemory<dnode_t,int> > *v5; // ecx
  int m_Put; // ebx
  int v7; // edx
  int v8; // eax
  CUtlBuffer *m_pSerialBuffer; // ecx
  int v10; // edi
  int v11; // eax

  v5 = data;
  m_Put = this->m_pSerialBuffer->m_Put;
  v7 = nLump;
  this->m_FileHeader.lumps[nLump].filelen = 32 * data->m_Size;
  v8 = nVersion;
  this->m_FileHeader.lumps[v7].fileofs = m_Put;
  this->m_FileHeader.lumps[v7].version = v8;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)v5->m_Memory.m_pMemory, size: 32 * v5->m_Size);
  m_pSerialBuffer = this->m_pSerialBuffer;
  v10 = this->m_pSerialBuffer->m_Put;
  v11 = 4 * ((v10 + 3) / 4);
  if ( v11 > v10 )
  {
    LOBYTE(data) = 0;
    *(_WORD *)((char *)&data + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&data, size: v11 - v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068B60
// Name: private: void CMemoryBSPFile::WriteLump<class Vector>(int,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump<Vector>(
        CMemoryBSPFile *this,
        int nLump,
        const CUtlVector<dbrush_t,CUtlMemory<dbrush_t,int> > *data,
        int nVersion)
{
  const CUtlVector<dbrush_t,CUtlMemory<dbrush_t,int> > *v4; // eax
  int m_Put; // ebx
  int v7; // ecx
  int v8; // edx
  CUtlBuffer *m_pSerialBuffer; // ecx
  int v10; // edi
  int v11; // eax

  v4 = data;
  m_Put = this->m_pSerialBuffer->m_Put;
  v7 = 12 * data->m_Size;
  v8 = nLump;
  this->m_FileHeader.lumps[v8].fileofs = m_Put;
  this->m_FileHeader.lumps[nLump].filelen = v7;
  this->m_FileHeader.lumps[v8].version = nVersion;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)v4->m_Memory.m_pMemory, size: 12 * v4->m_Size);
  m_pSerialBuffer = this->m_pSerialBuffer;
  v10 = this->m_pSerialBuffer->m_Put;
  v11 = 4 * ((v10 + 3) / 4);
  if ( v11 > v10 )
  {
    LOBYTE(data) = 0;
    *(_WORD *)((char *)&data + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&data, size: v11 - v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068BF0
// Name: private: void CMemoryBSPFile::WriteLump<struct dbrushside_t>(int,class CUtlVector<struct dbrushside_t,class CUtlMemory<struct dbrushside_t,int>> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump<dbrushside_t>(
        CMemoryBSPFile *this,
        int nLump,
        const CUtlVector<dbrushside_t,CUtlMemory<dbrushside_t,int> > *data,
        int nVersion)
{
  const CUtlVector<dbrushside_t,CUtlMemory<dbrushside_t,int> > *v4; // eax
  int m_Put; // ebx
  int v7; // ecx
  int v8; // edx
  CUtlBuffer *m_pSerialBuffer; // ecx
  int v10; // edi
  int v11; // eax

  v4 = data;
  m_Put = this->m_pSerialBuffer->m_Put;
  v7 = nLump;
  v8 = 8 * data->m_Size;
  this->m_FileHeader.lumps[v7].fileofs = m_Put;
  this->m_FileHeader.lumps[nLump].filelen = v8;
  this->m_FileHeader.lumps[v7].version = nVersion;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)v4->m_Memory.m_pMemory, size: 8 * v4->m_Size);
  m_pSerialBuffer = this->m_pSerialBuffer;
  v10 = this->m_pSerialBuffer->m_Put;
  v11 = 4 * ((v10 + 3) / 4);
  if ( v11 > v10 )
  {
    LOBYTE(data) = 0;
    *(_WORD *)((char *)&data + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&data, size: v11 - v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068C80
// Name: private: void CMemoryBSPFile::WriteLump<struct dplane_t>(int,class CUtlVector<struct dplane_t,class CUtlMemory<struct dplane_t,int>> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump<dplane_t>(
        CMemoryBSPFile *this,
        int nLump,
        const CUtlVector<CDispVert,CUtlMemory<CDispVert,int> > *data,
        int nVersion)
{
  const CUtlVector<CDispVert,CUtlMemory<CDispVert,int> > *v4; // eax
  int m_Put; // ebx
  int v7; // ecx
  int v8; // edx
  CUtlBuffer *m_pSerialBuffer; // ecx
  int v10; // edi
  int v11; // eax

  v4 = data;
  m_Put = this->m_pSerialBuffer->m_Put;
  v7 = 20 * data->m_Size;
  v8 = nLump;
  this->m_FileHeader.lumps[v8].fileofs = m_Put;
  this->m_FileHeader.lumps[nLump].filelen = v7;
  this->m_FileHeader.lumps[v8].version = nVersion;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)v4->m_Memory.m_pMemory, size: 20 * v4->m_Size);
  m_pSerialBuffer = this->m_pSerialBuffer;
  v10 = this->m_pSerialBuffer->m_Put;
  v11 = 4 * ((v10 + 3) / 4);
  if ( v11 > v10 )
  {
    LOBYTE(data) = 0;
    *(_WORD *)((char *)&data + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&data, size: v11 - v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068D10
// Name: private: void CMemoryBSPFile::WriteLump<struct dmodel_t>(int,class CUtlVector<struct dmodel_t,class CUtlMemory<struct dmodel_t,int>> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump<dmodel_t>(
        CMemoryBSPFile *this,
        int nLump,
        const CUtlVector<dmodel_t,CUtlMemory<dmodel_t,int> > *data,
        int nVersion)
{
  const CUtlVector<dmodel_t,CUtlMemory<dmodel_t,int> > *v4; // eax
  int m_Put; // ebx
  int v7; // ecx
  int v8; // edx
  CUtlBuffer *m_pSerialBuffer; // ecx
  int v10; // edi
  int v11; // eax

  v4 = data;
  m_Put = this->m_pSerialBuffer->m_Put;
  v7 = 48 * data->m_Size;
  v8 = nLump;
  this->m_FileHeader.lumps[v8].fileofs = m_Put;
  this->m_FileHeader.lumps[nLump].filelen = v7;
  this->m_FileHeader.lumps[v8].version = nVersion;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)v4->m_Memory.m_pMemory, size: 48 * v4->m_Size);
  m_pSerialBuffer = this->m_pSerialBuffer;
  v10 = this->m_pSerialBuffer->m_Put;
  v11 = 4 * ((v10 + 3) / 4);
  if ( v11 > v10 )
  {
    LOBYTE(data) = 0;
    *(_WORD *)((char *)&data + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&data, size: v11 - v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068DA0
// Name: private: void CMemoryBSPFile::WriteLump<class ddispinfo_t>(int,class CUtlVector<class ddispinfo_t,class CUtlMemory<class ddispinfo_t,int>> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump<ddispinfo_t>(
        CMemoryBSPFile *this,
        int nLump,
        const CUtlVector<ddispinfo_t,CUtlMemory<ddispinfo_t,int> > *data,
        int nVersion)
{
  const CUtlVector<ddispinfo_t,CUtlMemory<ddispinfo_t,int> > *v5; // ecx
  int m_Put; // ebx
  int v7; // edx
  int v8; // eax
  CUtlBuffer *m_pSerialBuffer; // ecx
  int v10; // edi
  int v11; // eax

  v5 = data;
  m_Put = this->m_pSerialBuffer->m_Put;
  v7 = nLump;
  this->m_FileHeader.lumps[nLump].filelen = 176 * data->m_Size;
  v8 = nVersion;
  this->m_FileHeader.lumps[v7].fileofs = m_Put;
  this->m_FileHeader.lumps[v7].version = v8;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)v5->m_Memory.m_pMemory, size: 176 * v5->m_Size);
  m_pSerialBuffer = this->m_pSerialBuffer;
  v10 = this->m_pSerialBuffer->m_Put;
  v11 = 4 * ((v10 + 3) / 4);
  if ( v11 > v10 )
  {
    LOBYTE(data) = 0;
    *(_WORD *)((char *)&data + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&data, size: v11 - v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068E30
// Name: private: void CMemoryBSPFile::WriteLump<class CDispTri>(int,class CUtlVector<class CDispTri,class CUtlMemory<class CDispTri,int>> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump<CDispTri>(
        CMemoryBSPFile *this,
        int nLump,
        const CUtlVector<CDispTri,CUtlMemory<CDispTri,int> > *data,
        int nVersion)
{
  const CUtlVector<CDispTri,CUtlMemory<CDispTri,int> > *v4; // eax
  int m_Put; // ebx
  int v7; // ecx
  int v8; // edx
  CUtlBuffer *m_pSerialBuffer; // ecx
  int v10; // edi
  int v11; // eax

  v4 = data;
  m_Put = this->m_pSerialBuffer->m_Put;
  v7 = nLump;
  this->m_FileHeader.lumps[nLump].filelen = 2 * data->m_Size;
  v8 = nVersion;
  this->m_FileHeader.lumps[v7].fileofs = m_Put;
  this->m_FileHeader.lumps[v7].version = v8;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)v4->m_Memory.m_pMemory, size: 2 * v4->m_Size);
  m_pSerialBuffer = this->m_pSerialBuffer;
  v10 = this->m_pSerialBuffer->m_Put;
  v11 = 4 * ((v10 + 3) / 4);
  if ( v11 > v10 )
  {
    LOBYTE(data) = 0;
    *(_WORD *)((char *)&data + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&data, size: v11 - v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068EB0
// Name: private: void CMemoryBSPFile::WriteLump<class CDispMultiBlend>(int,class CUtlVector<class CDispMultiBlend,class CUtlMemory<class CDispMultiBlend,int>> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump<CDispMultiBlend>(
        CMemoryBSPFile *this,
        int nLump,
        const CUtlVector<CDispMultiBlend,CUtlMemory<CDispMultiBlend,int> > *data,
        int nVersion)
{
  const CUtlVector<CDispMultiBlend,CUtlMemory<CDispMultiBlend,int> > *v4; // eax
  int m_Put; // ebx
  int v7; // ecx
  int v8; // edx
  CUtlBuffer *m_pSerialBuffer; // ecx
  int v10; // edi
  int v11; // eax

  v4 = data;
  m_Put = this->m_pSerialBuffer->m_Put;
  v7 = 80 * data->m_Size;
  v8 = nLump;
  this->m_FileHeader.lumps[v8].fileofs = m_Put;
  this->m_FileHeader.lumps[nLump].filelen = v7;
  this->m_FileHeader.lumps[v8].version = nVersion;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)v4->m_Memory.m_pMemory, size: 80 * v4->m_Size);
  m_pSerialBuffer = this->m_pSerialBuffer;
  v10 = this->m_pSerialBuffer->m_Put;
  v11 = 4 * ((v10 + 3) / 4);
  if ( v11 > v10 )
  {
    LOBYTE(data) = 0;
    *(_WORD *)((char *)&data + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&data, size: v11 - v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10068F40
// Name: private: void CMemoryBSPFile::WriteLump<struct dworldlight_t>(int,class CUtlVector<struct dworldlight_t,class CUtlMemory<struct dworldlight_t,int>> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump<dworldlight_t>(
        CMemoryBSPFile *this,
        int nLump,
        const CUtlVector<dworldlight_t,CUtlMemory<dworldlight_t,int> > *data,
        int nVersion)
{
  const CUtlVector<dworldlight_t,CUtlMemory<dworldlight_t,int> > *v5; // ecx
  int m_Put; // ebx
  int v7; // edx
  int v8; // eax
  CUtlBuffer *m_pSerialBuffer; // ecx
  int v10; // edi
  int v11; // eax

  v5 = data;
  m_Put = this->m_pSerialBuffer->m_Put;
  v7 = nLump;
  this->m_FileHeader.lumps[nLump].filelen = 100 * data->m_Size;
  v8 = nVersion;
  this->m_FileHeader.lumps[v7].fileofs = m_Put;
  this->m_FileHeader.lumps[v7].version = v8;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)v5->m_Memory.m_pMemory, size: 100 * v5->m_Size);
  m_pSerialBuffer = this->m_pSerialBuffer;
  v10 = this->m_pSerialBuffer->m_Put;
  v11 = 4 * ((v10 + 3) / 4);
  if ( v11 > v10 )
  {
    LOBYTE(data) = 0;
    *(_WORD *)((char *)&data + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&data, size: v11 - v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069340
// Name: private: void CMemoryBSPFile::WriteTexData(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteTexData(CMemoryBSPFile *this, bool bPurgeWhenComplete)
{
  CUtlVector<dtexdata_t,CUtlMemory<dtexdata_t,int> > *p_m_TexDataList; // edi
  CUtlVector<char,CUtlMemory<char,int> > *p_m_TexStringData; // ebx
  CUtlVector<int,CUtlMemory<int,int> > *p_m_TexStringIndices; // [esp+Ch] [ebp-4h]

  p_m_TexDataList = &this->m_TexDataList;
  CMemoryBSPFile::WriteLump<dleaf_t>(
    this,
    nLump: 2,
    data: (const CUtlVector<dnode_t,CUtlMemory<dnode_t,int> > *)&this->m_TexDataList,
    nVersion: 0);
  p_m_TexStringData = &this->m_TexStringData;
  CMemoryBSPFile::WriteLump<char>(this, nLump: 43, data: &this->m_TexStringData, nVersion: 0);
  p_m_TexStringIndices = &this->m_TexStringIndices;
  CMemoryBSPFile::WriteLump<dedge_t>(
    this,
    nLump: 44,
    data: (const CUtlVector<dedge_t,CUtlMemory<dedge_t,int> > *)&this->m_TexStringIndices,
    nVersion: 0);
  if ( bPurgeWhenComplete )
  {
    p_m_TexDataList->m_Size = 0;
    if ( p_m_TexDataList->m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_TexDataList->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_TexDataList->m_Memory.m_pMemory);
        p_m_TexDataList->m_Memory.m_pMemory = nullptr;
      }
      p_m_TexDataList->m_Memory.m_nAllocationCount = 0;
    }
    p_m_TexDataList->m_pElements = p_m_TexDataList->m_Memory.m_pMemory;
    this->m_TexStringData.m_Size = 0;
    if ( this->m_TexStringData.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_TexStringData->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_TexStringData->m_Memory.m_pMemory);
        p_m_TexStringData->m_Memory.m_pMemory = nullptr;
      }
      this->m_TexStringData.m_Memory.m_nAllocationCount = 0;
    }
    this->m_TexStringData.m_pElements = this->m_TexStringData.m_Memory.m_pMemory;
    this->m_TexStringIndices.m_Size = 0;
    if ( this->m_TexStringIndices.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_TexStringIndices->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_TexStringIndices->m_Memory.m_pMemory);
        p_m_TexStringIndices->m_Memory.m_pMemory = nullptr;
      }
      this->m_TexStringIndices.m_Memory.m_nAllocationCount = 0;
    }
    this->m_TexStringIndices.m_pElements = this->m_TexStringIndices.m_Memory.m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069410
// Name: private: void CMemoryBSPFile::WriteBrushes(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteBrushes(CMemoryBSPFile *this, bool bPurgeWhenComplete)
{
  CUtlVector<dbrush_t,CUtlMemory<dbrush_t,int> > *p_m_BrushList; // esi
  CUtlVector<dbrushside_t,CUtlMemory<dbrushside_t,int> > *p_m_BrushSideList; // ebx

  p_m_BrushList = &this->m_BrushList;
  CMemoryBSPFile::WriteLump<Vector>(this, nLump: 18, data: &this->m_BrushList, nVersion: 0);
  p_m_BrushSideList = &this->m_BrushSideList;
  CMemoryBSPFile::WriteLump<dbrushside_t>(this, nLump: 19, data: &this->m_BrushSideList, nVersion: 0);
  if ( bPurgeWhenComplete )
  {
    p_m_BrushList->m_Size = 0;
    if ( p_m_BrushList->m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_BrushList->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_BrushList->m_Memory.m_pMemory);
        p_m_BrushList->m_Memory.m_pMemory = nullptr;
      }
      p_m_BrushList->m_Memory.m_nAllocationCount = 0;
    }
    p_m_BrushList->m_pElements = p_m_BrushList->m_Memory.m_pMemory;
    this->m_BrushSideList.m_Size = 0;
    if ( this->m_BrushSideList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_BrushSideList->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_BrushSideList->m_Memory.m_pMemory);
        p_m_BrushSideList->m_Memory.m_pMemory = nullptr;
      }
      this->m_BrushSideList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_BrushSideList.m_pElements = this->m_BrushSideList.m_Memory.m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100694A0
// Name: private: void CMemoryBSPFile::WriteDisplacements(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteDisplacements(CMemoryBSPFile *this, bool bPurgeWhenComplete)
{
  CUtlVector<ddispinfo_t,CUtlMemory<ddispinfo_t,int> > *p_m_DisplacementList; // edi
  CUtlVector<CDispVert,CUtlMemory<CDispVert,int> > *p_m_DisplacementVertexList; // ebx
  CUtlVector<CDispMultiBlend,CUtlMemory<CDispMultiBlend,int> > *p_m_DisplacementMultiBlendList; // [esp+Ch] [ebp-Ch]
  CUtlVector<CDispTri,CUtlMemory<CDispTri,int> > *p_m_DisplacementTriangleList; // [esp+10h] [ebp-8h]
  unsigned __int8 dummyLightmapSamplePositionData[4]; // [esp+14h] [ebp-4h] BYREF

  *(_DWORD *)dummyLightmapSamplePositionData = 0;
  CMemoryBSPFile::WriteLump(this, nLump: 34, pData: dummyLightmapSamplePositionData, nByteLength: 4, nVersion: 0);
  p_m_DisplacementList = &this->m_DisplacementList;
  CMemoryBSPFile::WriteLump<ddispinfo_t>(this, nLump: 26, data: &this->m_DisplacementList, nVersion: 0);
  p_m_DisplacementVertexList = &this->m_DisplacementVertexList;
  CMemoryBSPFile::WriteLump<dplane_t>(this, nLump: 33, data: &this->m_DisplacementVertexList, nVersion: 0);
  p_m_DisplacementTriangleList = &this->m_DisplacementTriangleList;
  CMemoryBSPFile::WriteLump<CDispTri>(this, nLump: 48, data: &this->m_DisplacementTriangleList, nVersion: 0);
  p_m_DisplacementMultiBlendList = &this->m_DisplacementMultiBlendList;
  CMemoryBSPFile::WriteLump<CDispMultiBlend>(this, nLump: 63, data: &this->m_DisplacementMultiBlendList, nVersion: 0);
  if ( bPurgeWhenComplete )
  {
    this->m_DisplacementList.m_Size = 0;
    if ( this->m_DisplacementList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_DisplacementList->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_DisplacementList->m_Memory.m_pMemory);
        p_m_DisplacementList->m_Memory.m_pMemory = nullptr;
      }
      this->m_DisplacementList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_DisplacementList.m_pElements = this->m_DisplacementList.m_Memory.m_pMemory;
    this->m_DisplacementVertexList.m_Size = 0;
    if ( this->m_DisplacementVertexList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_DisplacementVertexList->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_DisplacementVertexList->m_Memory.m_pMemory);
        p_m_DisplacementVertexList->m_Memory.m_pMemory = nullptr;
      }
      this->m_DisplacementVertexList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_DisplacementVertexList.m_pElements = this->m_DisplacementVertexList.m_Memory.m_pMemory;
    this->m_DisplacementTriangleList.m_Size = 0;
    if ( this->m_DisplacementTriangleList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_DisplacementTriangleList->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_DisplacementTriangleList->m_Memory.m_pMemory);
        p_m_DisplacementTriangleList->m_Memory.m_pMemory = nullptr;
      }
      this->m_DisplacementTriangleList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_DisplacementTriangleList.m_pElements = this->m_DisplacementTriangleList.m_Memory.m_pMemory;
    this->m_DisplacementMultiBlendList.m_Size = 0;
    if ( this->m_DisplacementMultiBlendList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_DisplacementMultiBlendList->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_DisplacementMultiBlendList->m_Memory.m_pMemory);
        p_m_DisplacementMultiBlendList->m_Memory.m_pMemory = nullptr;
      }
      this->m_DisplacementMultiBlendList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_DisplacementMultiBlendList.m_pElements = this->m_DisplacementMultiBlendList.m_Memory.m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069690
// Name: private: int CMemoryBSPFile::FindOrAddString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMemoryBSPFile::FindOrAddString(CMemoryBSPFile *this, const char *pString)
{
  int v3; // esi
  unsigned int v4; // eax
  int m_Size; // ebx
  int v6; // edx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v9; // eax
  int *v10; // ebx
  int v12; // [esp+8h] [ebp-8h]
  int nStrLen; // [esp+Ch] [ebp-4h]

  v3 = 0;
  if ( this->m_TexStringIndices.m_Size <= 0 )
  {
LABEL_4:
    v4 = _V_strlen(str: pString);
    m_Size = this->m_TexStringIndices.m_Size;
    v6 = v4 + 1;
    v12 = this->m_TexStringData.m_Size;
    m_nAllocationCount = this->m_TexStringIndices.m_Memory.m_nAllocationCount;
    nStrLen = v6;
    if ( m_Size + 1 > m_nAllocationCount )
    {
      CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_TexStringIndices,
        num: m_Size - m_nAllocationCount + 1);
      v6 = nStrLen;
    }
    ++this->m_TexStringIndices.m_Size;
    m_pMemory = this->m_TexStringIndices.m_Memory.m_pMemory;
    v9 = this->m_TexStringIndices.m_Size - m_Size - 1;
    this->m_TexStringIndices.m_pElements = m_pMemory;
    if ( v9 > 0 )
    {
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v9);
      v6 = nStrLen;
    }
    v10 = &this->m_TexStringIndices.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = v12;
    CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::InsertMultipleBefore(
      this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&this->m_TexStringData,
      elem: this->m_TexStringData.m_Size,
      num: v6,
      pToInsert: (const unsigned __int8 *)pString);
    return this->m_TexStringIndices.m_Size - 1;
  }
  else
  {
    while ( _V_stricmp(
              s1: &this->m_TexStringData.m_Memory.m_pMemory[this->m_TexStringIndices.m_Memory.m_pMemory[v3]],
              s2: pString) != 0 )
    {
      if ( ++v3 >= this->m_TexStringIndices.m_Size )
        goto LABEL_4;
    }
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069790
// Name: private: void CMemoryBSPFile::WriteModelData(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteModelData(CMemoryBSPFile *this, bool bPurgeWhenComplete)
{
  CUtlVector<dedge_t,CUtlMemory<dedge_t,int> > *p_m_EdgeList; // edi
  CUtlVector<int,CUtlMemory<int,int> > *p_m_SurfEdgeList; // ebx
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *p_m_VertexNormalIndexList; // [esp+Ch] [ebp-8h]
  CUtlVector<Vector,CUtlMemory<Vector,int> > *p_m_VertexNormalList; // [esp+10h] [ebp-4h]

  CMemoryBSPFile::WriteLump<Vector>(
    this,
    nLump: 3,
    data: (const CUtlVector<dbrush_t,CUtlMemory<dbrush_t,int> > *)&this->m_VertexHash.m_Vertices,
    nVersion: 0);
  p_m_EdgeList = &this->m_EdgeList;
  CMemoryBSPFile::WriteLump<dedge_t>(this, nLump: 12, data: &this->m_EdgeList, nVersion: 0);
  p_m_SurfEdgeList = &this->m_SurfEdgeList;
  CMemoryBSPFile::WriteLump<dedge_t>(
    this,
    nLump: 13,
    data: (const CUtlVector<dedge_t,CUtlMemory<dedge_t,int> > *)&this->m_SurfEdgeList,
    nVersion: 0);
  CMemoryBSPFile::WriteLump<dface_t>(this, nLump: 7, data: &this->m_FaceList, nVersion: 1);
  p_m_VertexNormalList = &this->m_VertexNormalList;
  CMemoryBSPFile::WriteLump<Vector>(
    this,
    nLump: 30,
    data: (const CUtlVector<dbrush_t,CUtlMemory<dbrush_t,int> > *)&this->m_VertexNormalList,
    nVersion: 0);
  p_m_VertexNormalIndexList = &this->m_VertexNormalIndexList;
  CMemoryBSPFile::WriteLump<CDispTri>(
    this,
    nLump: 31,
    data: (const CUtlVector<CDispTri,CUtlMemory<CDispTri,int> > *)&this->m_VertexNormalIndexList,
    nVersion: 0);
  if ( bPurgeWhenComplete )
  {
    CVertexHash::Purge(this: &this->m_VertexHash);
    this->m_EdgeList.m_Size = 0;
    if ( this->m_EdgeList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_EdgeList->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_EdgeList->m_Memory.m_pMemory);
        p_m_EdgeList->m_Memory.m_pMemory = nullptr;
      }
      this->m_EdgeList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_EdgeList.m_pElements = this->m_EdgeList.m_Memory.m_pMemory;
    this->m_SurfEdgeList.m_Size = 0;
    if ( this->m_SurfEdgeList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_SurfEdgeList->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_SurfEdgeList->m_Memory.m_pMemory);
        p_m_SurfEdgeList->m_Memory.m_pMemory = nullptr;
      }
      this->m_SurfEdgeList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_SurfEdgeList.m_pElements = this->m_SurfEdgeList.m_Memory.m_pMemory;
    this->m_VertexNormalList.m_Size = 0;
    if ( this->m_VertexNormalList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_VertexNormalList->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_VertexNormalList->m_Memory.m_pMemory);
        p_m_VertexNormalList->m_Memory.m_pMemory = nullptr;
      }
      this->m_VertexNormalList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_VertexNormalList.m_pElements = this->m_VertexNormalList.m_Memory.m_pMemory;
    this->m_VertexNormalIndexList.m_Size = 0;
    if ( this->m_VertexNormalIndexList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_VertexNormalIndexList->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_VertexNormalIndexList->m_Memory.m_pMemory);
        p_m_VertexNormalIndexList->m_Memory.m_pMemory = nullptr;
      }
      this->m_VertexNormalIndexList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_VertexNormalIndexList.m_pElements = this->m_VertexNormalIndexList.m_Memory.m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100698E0
// Name: private: void CMemoryBSPFile::EmitFace(class CBSPFace const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CMemoryBSPFile::EmitFace(CMemoryBSPFile *this, const CBSPFace *pBSPFace, bool bOnNode)
{
  bool v4; // zf
  CMemoryBSPFile *v5; // esi
  __int16 m_nPlaneIndex; // cx
  __int16 m_Size; // di
  char v8; // dl
  int v9; // ecx
  __int16 m_nTextureInfoIndex; // dx
  double v11; // st7
  __int16 m_nDisplacementIndex; // cx
  const CSimpleMapFile *m_pMapFile; // ecx
  const Vector *v14; // eax
  int VertexIndex; // eax
  bool v16; // cc
  CUtlMemory<vgui::TreeNode *,int> *p_m_EdgeList; // edi
  const Vector *v18; // eax
  vgui::TreeNode **m_pMemory; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v21; // ecx
  int v22; // eax
  vgui::TreeNode **v23; // esi
  const Vector *v24; // esi
  int v25; // ecx
  _DWORD *v26; // ecx
  int v27; // edx
  int v28; // eax
  int v29; // eax
  const Vector **v30; // esi
  const Vector *v31; // ecx
  int v32; // eax
  unsigned __int16 *v33; // edx
  int v34; // eax
  unsigned __int16 *v35; // ecx
  float v36; // xmm1_4
  float v37; // xmm2_4
  float v38; // xmm3_4
  float v39; // xmm0_4
  float v40; // xmm1_4
  int i; // edi
  __m128 v42; // xmm2
  __m128 v43; // xmm1
  __m128 v44; // xmm3
  __m128 v45; // xmm0
  __m128 v46; // xmm1
  int v47; // eax
  int v48; // ebx
  int v49; // edx
  int v50; // eax
  Vector *v51; // ecx
  int v52; // eax
  int v53; // eax
  int v54; // edi
  int v55; // eax
  dface_t *v56; // ecx
  int v57; // eax
  dface_t *v58; // edi
  _BYTE dst[68]; // [esp+8h] [ebp-64h] OVERLAPPED BYREF
  float flLightmapMax[2]; // [esp+4Ch] [ebp-20h]
  float flLightmapMin[2]; // [esp+54h] [ebp-18h]
  const MapTextureInfo_t *pMapTextureInfo; // [esp+5Ch] [ebp-10h]
  const Vector *vPoint; // [esp+60h] [ebp-Ch]
  const Vector *v64; // [esp+64h] [ebp-8h]
  int nVertex; // [esp+68h] [ebp-4h]
  vgui::TreeNode *v66; // [esp+74h] [ebp+8h]
  float v67; // [esp+74h] [ebp+8h]
  int v68; // [esp+78h] [ebp+Ch]
  float v69; // [esp+78h] [ebp+Ch]
  int v70; // [esp+78h] [ebp+Ch]

  v4 = pBSPFace->m_nSerializedFaceIndex == -1;
  v5 = this;
  nVertex = (int)this;
  if ( !v4 )
  {
    memset(dst, value: 0, count: 0x38u);
    m_nPlaneIndex = pBSPFace->m_nPlaneIndex;
    m_Size = pBSPFace->m_Polygon.m_Points.m_Size;
    v8 = m_nPlaneIndex & 1;
    dst[3] = bOnNode;
    *(_WORD *)dst = m_nPlaneIndex;
    v9 = v5->m_EdgeList.m_Size;
    dst[2] = v8;
    m_nTextureInfoIndex = pBSPFace->m_nTextureInfoIndex;
    *(_DWORD *)&dst[4] = v9;
    *(_WORD *)&dst[8] = m_Size;
    *(_WORD *)&dst[10] = m_nTextureInfoIndex;
    v11 = ComputePolygonArea(polygon: &pBSPFace->m_Polygon);
    m_nDisplacementIndex = pBSPFace->m_nDisplacementIndex;
    *(float *)&dst[24] = v11;
    *(_WORD *)&dst[12] = m_nDisplacementIndex;
    *(_WORD *)&dst[14] = -1;
    m_pMapFile = v5->m_pMapFile;
    *(_WORD *)&dst[48] = 0;
    v14 = &pBSPFace->m_Polygon.m_Points.m_Memory.m_pMemory[m_Size - 1];
    LODWORD(flLightmapMax[1]) = &m_pMapFile->m_TextureInfos.m_Memory.m_pMemory[pBSPFace->m_nTextureInfoIndex];
    flLightmapMax[0] = 3.4028235e38;
    *(_DWORD *)&dst[64] = 2139095039;
    *(_DWORD *)&dst[60] = -8388609;
    *(_DWORD *)&dst[56] = -8388609;
    VertexIndex = CVertexHash::FindVertexIndex(this: &v5->m_VertexHash, vertex: v14, bAlwaysAdd: false);
    v16 = pBSPFace->m_Polygon.m_Points.m_Size <= 0;
    v64 = (const Vector *)VertexIndex;
    pMapTextureInfo = nullptr;
    if ( !v16 )
    {
      p_m_EdgeList = (CUtlMemory<vgui::TreeNode *,int> *)&v5->m_EdgeList;
      v68 = 0;
      do
      {
        LODWORD(flLightmapMin[0]) = &pBSPFace->m_Polygon.m_Points.m_Memory.m_pMemory[v68];
        v18 = (const Vector *)CVertexHash::FindVertexIndex(
                                this: &v5->m_VertexHash,
                                vertex: (const Vector *)LODWORD(flLightmapMin[0]),
                                bAlwaysAdd: false);
        m_pMemory = p_m_EdgeList[1].m_pMemory;
        vPoint = v18;
        HIWORD(v66) = (_WORD)v18;
        m_nAllocationCount = p_m_EdgeList->m_nAllocationCount;
        LOWORD(v66) = (_WORD)v64;
        if ( (int)m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
            this: p_m_EdgeList,
            num: (int)m_pMemory - m_nAllocationCount + 1);
        ++p_m_EdgeList[1].m_pMemory;
        v21 = p_m_EdgeList->m_pMemory;
        v22 = (char *)p_m_EdgeList[1].m_pMemory - (char *)m_pMemory - 1;
        p_m_EdgeList[1].m_nAllocationCount = (int)p_m_EdgeList->m_pMemory;
        if ( v22 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&v21[(_DWORD)m_pMemory + 1],
            src: (unsigned __int8 *)&v21[(_DWORD)m_pMemory],
            count: 4 * v22);
        v23 = &p_m_EdgeList->m_pMemory[(_DWORD)m_pMemory];
        if ( v23 != nullptr )
          *v23 = v66;
        v24 = *(const Vector **)(nVertex + 70876);
        v64 = vPoint;
        vPoint = v24;
        v25 = *(_DWORD *)(nVertex + 70868);
        if ( (int)&v24->x + 1 > v25 )
          CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)(nVertex + 70864),
            num: (int)&v24->x - v25 + 1);
        v26 = (_DWORD *)nVertex;
        ++*(_DWORD *)(nVertex + 70876);
        v27 = v26[17716];
        v28 = v26[17719] - (_DWORD)v24 - 1;
        v26[17720] = v27;
        if ( v28 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)(v27 + 4 * (_DWORD)v24 + 4),
            src: (unsigned __int8 *)(v27 + 4 * (_DWORD)v24),
            count: 4 * v28);
        v29 = nVertex;
        v30 = (const Vector **)(*(_DWORD *)(nVertex + 70864) + 4 * (_DWORD)v24);
        if ( v30 != nullptr )
          *v30 = vPoint;
        v5 = (CMemoryBSPFile *)v29;
        v31 = *(const Vector **)(v29 + 70936);
        LODWORD(flLightmapMin[1]) = *(unsigned __int16 *)(v29 + 70916);
        v32 = *(_DWORD *)(v29 + 70928);
        vPoint = v31;
        if ( (int)&v31->x + 1 > v32 )
        {
          CUtlMemory<wchar_t,int>::Grow(
            this: (CUtlMemory<wchar_t,int> *)&v5->m_VertexNormalIndexList,
            num: (int)&v31->x - v32 + 1);
          v31 = vPoint;
        }
        ++v5->m_VertexNormalIndexList.m_Size;
        v33 = v5->m_VertexNormalIndexList.m_Memory.m_pMemory;
        v34 = v5->m_VertexNormalIndexList.m_Size - (_DWORD)v31 - 1;
        v5->m_VertexNormalIndexList.m_pElements = v33;
        if ( v34 > 0 )
        {
          _V_memmove(
            dest: (unsigned __int8 *)&v33[(_DWORD)v31 + 1],
            src: (unsigned __int8 *)&v33[(_DWORD)v31],
            count: 2 * v34);
          v31 = vPoint;
        }
        v35 = &v5->m_VertexNormalIndexList.m_Memory.m_pMemory[(_DWORD)v31];
        if ( v35 != nullptr )
          *v35 = LOWORD(flLightmapMin[1]);
        v36 = *(float *)(LODWORD(flLightmapMin[0]) + 4);
        v37 = *(float *)LODWORD(flLightmapMin[0]);
        v38 = *(float *)(LODWORD(flLightmapMin[0]) + 8);
        v39 = (float)((float)((float)(v36 * *(float *)(LODWORD(flLightmapMax[1]) + 36))
                            + (float)(*(float *)LODWORD(flLightmapMin[0]) * *(float *)(LODWORD(flLightmapMax[1]) + 32)))
                    + (float)(v38 * *(float *)(LODWORD(flLightmapMax[1]) + 40)))
            + *(float *)(LODWORD(flLightmapMax[1]) + 44);
        if ( *(float *)&dst[64] > v39 )
          *(float *)&dst[64] = (float)((float)((float)(*(float *)(LODWORD(flLightmapMin[0]) + 4)
                                                     * *(float *)(LODWORD(flLightmapMax[1]) + 36))
                                             + (float)(*(float *)LODWORD(flLightmapMin[0])
                                                     * *(float *)(LODWORD(flLightmapMax[1]) + 32)))
                                     + (float)(*(float *)(LODWORD(flLightmapMin[0]) + 8)
                                             * *(float *)(LODWORD(flLightmapMax[1]) + 40)))
                             + *(float *)(LODWORD(flLightmapMax[1]) + 44);
        if ( v39 > *(float *)&dst[56] )
          *(float *)&dst[56] = v39;
        v40 = (float)((float)((float)(v36 * *(float *)(LODWORD(flLightmapMax[1]) + 52))
                            + (float)(v37 * *(float *)(LODWORD(flLightmapMax[1]) + 48)))
                    + (float)(v38 * *(float *)(LODWORD(flLightmapMax[1]) + 56)))
            + *(float *)(LODWORD(flLightmapMax[1]) + 60);
        if ( flLightmapMax[0] > v40 )
          flLightmapMax[0] = v40;
        if ( v40 > *(float *)&dst[60] )
          *(float *)&dst[60] = v40;
        ++v68;
        pMapTextureInfo = (const MapTextureInfo_t *)((char *)pMapTextureInfo + 1);
      }
      while ( (int)pMapTextureInfo < pBSPFace->m_Polygon.m_Points.m_Size );
    }
    for ( i = 0; i < 8; i += 4 )
    {
      v42 = (__m128)*(unsigned int *)&dst[i + 64];
      v43.m128_i32[0] = 1258291200;
      v44 = _mm_and_ps((__m128)0x80000000, v42);
      v43.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v42, v44), v43).m128_f32[0]) & 0x4B000000
                      | v44.m128_i32[0];
      v45 = v42;
      v45.m128_f32[0] = (float)(v42.m128_f32[0] + v43.m128_f32[0]) - v43.m128_f32[0];
      v46 = v45;
      v46.m128_f32[0] = v45.m128_f32[0] - v42.m128_f32[0];
      v69 = v45.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v46, v44).m128_u32[0] & 0x3F800000);
      *(float *)&dst[i + 64] = v69;
      v67 = ceil(X: *(float *)&dst[i + 56]);
      *(float *)&dst[i + 56] = v67;
      *(_DWORD *)&dst[i + 28] = (int)v69;
      *(_DWORD *)&dst[i + 36] = (int)(float)(v67 - v69);
    }
    v47 = pBSPFace->m_nPlaneIndex;
    v48 = v5->m_VertexNormalList.m_Size;
    v49 = (int)&v5->m_PlaneHash.m_Planes.m_Memory.m_pMemory[v47];
    v50 = v5->m_VertexNormalList.m_Memory.m_nAllocationCount;
    v70 = v49;
    if ( v48 + 1 > v50 )
      CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
        this: (CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int> *)&v5->m_VertexNormalList,
        num: v48 - v50 + 1);
    ++v5->m_VertexNormalList.m_Size;
    v51 = v5->m_VertexNormalList.m_Memory.m_pMemory;
    v52 = v5->m_VertexNormalList.m_Size - v48 - 1;
    v5->m_VertexNormalList.m_pElements = v51;
    if ( v52 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v51[v48 + 1], src: (unsigned __int8 *)&v51[v48], count: 12 * v52);
    v53 = (int)&v5->m_VertexNormalList.m_Memory.m_pMemory[v48];
    if ( v53 != 0 )
    {
      *(_QWORD *)v53 = *(_QWORD *)v70;
      *(_DWORD *)(v53 + 8) = *(_DWORD *)(v70 + 8);
    }
    v54 = v5->m_FaceList.m_Size;
    v55 = v5->m_FaceList.m_Memory.m_nAllocationCount;
    if ( v54 + 1 > v55 )
      CUtlMemory<dface_t,int>::Grow(this: &v5->m_FaceList.m_Memory, num: v54 - v55 + 1);
    ++v5->m_FaceList.m_Size;
    v56 = v5->m_FaceList.m_Memory.m_pMemory;
    v57 = v5->m_FaceList.m_Size - v54 - 1;
    v5->m_FaceList.m_pElements = v56;
    if ( v57 > 0 )
      _V_memmove(dest: (unsigned __int8 *)&v56[v54 + 1], src: (unsigned __int8 *)&v56[v54], count: 56 * v57);
    v58 = &v5->m_FaceList.m_Memory.m_pMemory[v54];
    if ( v58 != nullptr )
      qmemcpy(v58, dst, sizeof(dface_t));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069DC0
// Name: private: void CMemoryBSPFile::WriteBSPTreeData(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteBSPTreeData(CMemoryBSPFile *this, bool bPurgeWhenComplete)
{
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *p_m_LeafFaceList; // edi
  bool v4; // sf

  CMemoryBSPFile::WriteLump<dleaf_t>(
    this,
    nLump: 10,
    data: (const CUtlVector<dnode_t,CUtlMemory<dnode_t,int> > *)&this->m_LeafList,
    nVersion: 1);
  CMemoryBSPFile::WriteLump<CDispTri>(
    this,
    nLump: 17,
    data: (const CUtlVector<CDispTri,CUtlMemory<CDispTri,int> > *)&this->m_LeafBrushList,
    nVersion: 0);
  p_m_LeafFaceList = &this->m_LeafFaceList;
  CMemoryBSPFile::WriteLump<CDispTri>(
    this,
    nLump: 16,
    data: (const CUtlVector<CDispTri,CUtlMemory<CDispTri,int> > *)&this->m_LeafFaceList,
    nVersion: 0);
  CMemoryBSPFile::WriteLump<dleaf_t>(this, nLump: 5, data: &this->m_NodeList, nVersion: 0);
  if ( bPurgeWhenComplete )
  {
    v4 = this->m_LeafFaceList.m_Memory.m_nGrowSize < 0;
    this->m_LeafFaceList.m_Size = 0;
    if ( !v4 )
    {
      if ( p_m_LeafFaceList->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_LeafFaceList->m_Memory.m_pMemory);
        p_m_LeafFaceList->m_Memory.m_pMemory = nullptr;
      }
      this->m_LeafFaceList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_LeafFaceList.m_pElements = this->m_LeafFaceList.m_Memory.m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10069E50
// Name: private: int CMemoryBSPFile::EmitLeaf(class CBSPNode const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMemoryBSPFile::EmitLeaf(CMemoryBSPFile *this, const CBSPNode *pNode)
{
  CMemoryBSPFile *v2; // edi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  dleaf_t *m_pMemory; // ecx
  int v6; // eax
  int v8; // ecx
  __int16 m_nClusterIndex; // ax
  CUtlMemory<wchar_t,int> *p_m_LeafBrushList; // esi
  int v11; // ecx
  wchar_t *v12; // edi
  int v13; // eax
  wchar_t *v14; // ecx
  int v15; // eax
  wchar_t *v16; // edi
  int v17; // edi
  CBSPPortal *v18; // eax
  int v19; // esi
  int v20; // edi
  int v21; // eax
  unsigned __int16 *v22; // ecx
  int v23; // eax
  unsigned __int16 *v24; // edi
  int v25; // edx
  CBSPFace *v26; // eax
  unsigned __int16 m_nSerializedFaceIndex; // dx
  int v28; // edi
  int v29; // eax
  unsigned __int16 *v30; // edx
  int v31; // eax
  unsigned __int16 *v32; // edi
  int nIndex; // [esp+Ch] [ebp-18h]
  int nSerializedFaceIndex; // [esp+10h] [ebp-14h]
  unsigned __int16 nSerializedFaceIndexa; // [esp+10h] [ebp-14h]
  CBSPPortal **v37; // [esp+14h] [ebp-10h]
  wchar_t v38; // [esp+18h] [ebp-Ch]
  int j; // [esp+18h] [ebp-Ch]
  dleaf_t *pNewLeaf; // [esp+20h] [ebp-4h]
  int i; // [esp+2Ch] [ebp+8h]
  int ia; // [esp+2Ch] [ebp+8h]
  int ib; // [esp+2Ch] [ebp+8h]

  v2 = this;
  m_Size = this->m_LeafList.m_Size;
  m_nAllocationCount = this->m_LeafList.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<vgui::RichText::TFormatStream,int>::Grow(
      this: (CUtlMemory<vgui::RichText::TFormatStream,int> *)&this->m_LeafList,
      num: m_Size - m_nAllocationCount + 1);
  ++v2->m_LeafList.m_Size;
  m_pMemory = v2->m_LeafList.m_Memory.m_pMemory;
  v6 = v2->m_LeafList.m_Size - m_Size - 1;
  v2->m_LeafList.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 32 * v6);
  nIndex = v2->m_LeafList.m_Size - 1;
  v8 = (int)&v2->m_LeafList.m_Memory.m_pMemory[nIndex];
  *(_QWORD *)v8 = 0;
  *(_QWORD *)(v8 + 8) = 0;
  *(_QWORD *)(v8 + 16) = 0;
  *(_QWORD *)(v8 + 24) = 0;
  *(_DWORD *)v8 = pNode->m_ContentsFlags;
  m_nClusterIndex = pNode->m_nClusterIndex;
  pNewLeaf = (dleaf_t *)v8;
  *(_WORD *)(v8 + 4) = m_nClusterIndex;
  if ( m_nClusterIndex == -1 )
    *(_WORD *)(v8 + 6) &= 0xFE00u;
  else
    *(_WORD *)(v8 + 6) = *(_WORD *)(v8 + 6) & 0xFE00 | 1;
  *(_WORD *)(v8 + 6) = *(_WORD *)(v8 + 6) & 0x1FF | 0x400;
  *(_WORD *)(v8 + 8) = (int)pNode->m_vMinBounds.x;
  *(_WORD *)(v8 + 10) = (int)pNode->m_vMinBounds.y;
  *(_WORD *)(v8 + 12) = (int)pNode->m_vMinBounds.z;
  *(_WORD *)(v8 + 14) = (int)pNode->m_vMaxBounds.x;
  *(_WORD *)(v8 + 16) = (int)pNode->m_vMaxBounds.y;
  *(_WORD *)(v8 + 18) = (int)pNode->m_vMaxBounds.z;
  *(_WORD *)(v8 + 20) = v2->m_LeafFaceList.m_Size;
  *(_WORD *)(v8 + 22) = 0;
  *(_WORD *)(v8 + 24) = v2->m_LeafBrushList.m_Size;
  *(_WORD *)(v8 + 26) = pNode->m_ClippedBrushes.m_Size;
  *(_WORD *)(v8 + 28) = -1;
  i = 0;
  if ( pNode->m_ClippedBrushes.m_Size > 0 )
  {
    p_m_LeafBrushList = (CUtlMemory<wchar_t,int> *)&v2->m_LeafBrushList;
    while ( 1 )
    {
      v11 = (char *)pNode->m_ClippedBrushes.m_Memory.m_pMemory[i]->m_pOriginalBrush
          - (char *)v2->m_pMapFile->m_Brushes.m_Memory.m_pMemory;
      v12 = p_m_LeafBrushList[1].m_pMemory;
      v13 = p_m_LeafBrushList->m_nAllocationCount;
      v38 = v11 / 36;
      if ( (int)v12 + 1 > v13 )
        CUtlMemory<wchar_t,int>::Grow(this: p_m_LeafBrushList, num: (int)v12 - v13 + 1);
      ++p_m_LeafBrushList[1].m_pMemory;
      v14 = p_m_LeafBrushList->m_pMemory;
      v15 = (char *)p_m_LeafBrushList[1].m_pMemory - (char *)v12 - 1;
      p_m_LeafBrushList[1].m_nAllocationCount = (int)p_m_LeafBrushList->m_pMemory;
      if ( v15 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&v14[(_DWORD)v12 + 1],
          src: (unsigned __int8 *)&v14[(_DWORD)v12],
          count: 2 * v15);
      v16 = &p_m_LeafBrushList->m_pMemory[(_DWORD)v12];
      if ( v16 != nullptr )
        *v16 = v38;
      if ( ++i >= pNode->m_ClippedBrushes.m_Size )
        break;
      v2 = this;
    }
    v8 = (int)pNewLeaf;
  }
  v17 = 0;
  for ( j = 0; v17 < pNode->m_Portals.m_Size; j = v17 )
  {
    v18 = pNode->m_Portals.m_Memory.m_pMemory[v17];
    v19 = 0;
    for ( ia = 0; v19 < v18->m_PortalFaces.m_Size; ia = v19 )
    {
      nSerializedFaceIndex = v18->m_PortalFaces.m_Memory.m_pMemory[v19]->m_nSerializedFaceIndex;
      if ( nSerializedFaceIndex != -1 )
      {
        v37 = &pNode->m_Portals.m_Memory.m_pMemory[v17];
        if ( pNode == (*v37)->m_pNodes[CBSPPortal::GetNodeIndexForFace(this: *v37)] )
        {
          v20 = this->m_LeafFaceList.m_Size;
          v21 = this->m_LeafFaceList.m_Memory.m_nAllocationCount;
          if ( v20 + 1 > v21 )
            CUtlMemory<wchar_t,int>::Grow(this: (CUtlMemory<wchar_t,int> *)&this->m_LeafFaceList, num: v20 - v21 + 1);
          ++this->m_LeafFaceList.m_Size;
          v22 = this->m_LeafFaceList.m_Memory.m_pMemory;
          v23 = this->m_LeafFaceList.m_Size - v20 - 1;
          this->m_LeafFaceList.m_pElements = v22;
          if ( v23 > 0 )
            _V_memmove(dest: (unsigned __int8 *)&v22[v20 + 1], src: (unsigned __int8 *)&v22[v20], count: 2 * v23);
          v24 = &this->m_LeafFaceList.m_Memory.m_pMemory[v20];
          if ( v24 != nullptr )
            *v24 = nSerializedFaceIndex;
          ++pNewLeaf->numleaffaces;
          v19 = ia;
          v17 = j;
          v8 = (int)pNewLeaf;
        }
        else
        {
          v8 = (int)pNewLeaf;
        }
      }
      v18 = pNode->m_Portals.m_Memory.m_pMemory[v17];
      ++v19;
    }
    ++v17;
  }
  v25 = 0;
  for ( ib = 0; v25 < pNode->m_Faces.m_Size; ib = v25 )
  {
    v26 = pNode->m_Faces.m_Memory.m_pMemory[v25];
    if ( v26->m_nSerializedFaceIndex != -1 )
    {
      m_nSerializedFaceIndex = v26->m_nSerializedFaceIndex;
      v28 = this->m_LeafFaceList.m_Size;
      v29 = this->m_LeafFaceList.m_Memory.m_nAllocationCount;
      nSerializedFaceIndexa = m_nSerializedFaceIndex;
      if ( v28 + 1 > v29 )
      {
        CUtlMemory<wchar_t,int>::Grow(this: (CUtlMemory<wchar_t,int> *)&this->m_LeafFaceList, num: v28 - v29 + 1);
        v8 = (int)pNewLeaf;
      }
      ++this->m_LeafFaceList.m_Size;
      v30 = this->m_LeafFaceList.m_Memory.m_pMemory;
      v31 = this->m_LeafFaceList.m_Size - v28 - 1;
      this->m_LeafFaceList.m_pElements = v30;
      if ( v31 > 0 )
      {
        _V_memmove(dest: (unsigned __int8 *)&v30[v28 + 1], src: (unsigned __int8 *)&v30[v28], count: 2 * v31);
        v8 = (int)pNewLeaf;
      }
      v32 = &this->m_LeafFaceList.m_Memory.m_pMemory[v28];
      if ( v32 != nullptr )
        *v32 = nSerializedFaceIndexa;
      ++*(_WORD *)(v8 + 22);
      v25 = ib;
    }
    ++v25;
  }
  if ( *(_WORD *)(v8 + 22) == 0 )
    *(_WORD *)(v8 + 20) = 0;
  return -1 - nIndex;
}

//------------------------------------------------------------------------------
// Address: 0x1006A200
// Name: private: int CMemoryBSPFile::EmitNode(class CBSPNode const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMemoryBSPFile::EmitNode(CMemoryBSPFile *this, const CBSPNode *pNode)
{
  int m_Size; // ebx
  dnode_t *v5; // eax
  unsigned __int16 v6; // dx
  int v7; // eax
  dnode_t *v8; // ecx
  int child0; // [esp+8h] [ebp-8h]

  if ( pNode->m_nSplitPlaneIndex == -1 )
    return CMemoryBSPFile::EmitLeaf(this, pNode);
  CUtlVector<dnode_t,CUtlMemory<dnode_t,int>>::AddToTail(this: &this->m_NodeList);
  m_Size = this->m_NodeList.m_Size;
  v5 = &this->m_NodeList.m_Memory.m_pMemory[m_Size - 1];
  *(_QWORD *)&v5->planenum = 0;
  *(_QWORD *)&v5->children[1] = 0;
  *(_QWORD *)&v5->mins[2] = 0;
  *(_QWORD *)&v5->firstface = 0;
  v5->planenum = pNode->m_nSplitPlaneIndex;
  v5->mins[0] = (int)pNode->m_vMinBounds.x;
  v5->mins[1] = (int)pNode->m_vMinBounds.y;
  v5->mins[2] = (int)pNode->m_vMinBounds.z;
  v5->maxs[0] = (int)pNode->m_vMaxBounds.x;
  v5->maxs[1] = (int)pNode->m_vMaxBounds.y;
  v5->maxs[2] = (int)pNode->m_vMaxBounds.z;
  if ( pNode->m_Faces.m_Size <= 0 )
    v5->firstface = 0;
  else
    v5->firstface = (*pNode->m_Faces.m_Memory.m_pMemory)->m_nSerializedFaceIndex;
  v6 = pNode->m_Faces.m_Size;
  v5->area = 0;
  v5->numfaces = v6;
  child0 = CMemoryBSPFile::EmitNode(this, pNode: pNode->m_pChildren[0]);
  v7 = CMemoryBSPFile::EmitNode(this, pNode: pNode->m_pChildren[1]);
  v8 = &this->m_NodeList.m_Memory.m_pMemory[m_Size - 1];
  v8->children[1] = v7;
  v8->children[0] = child0;
  return m_Size - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006A300
// Name: private: void CMemoryBSPFile::BuildEntityData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::BuildEntityData(CMemoryBSPFile *this)
{
  CMemoryBSPFile *v1; // ebx
  const CSimpleMapFile *m_pMapFile; // eax
  int v3; // edi
  int *v4; // esi
  int v5; // edi
  int v6; // edi
  int v7; // eax
  int v8; // ebx
  int p_m_pValue; // esi
  char *i; // eax
  char *j; // eax
  int v12; // eax
  int v13; // edi
  int v14; // esi
  char *k; // eax
  char *m; // eax
  bool v17; // zf
  int v18; // edi
  int m_nAllocationCount; // eax
  unsigned __int8 *v20; // ecx
  signed int v21; // eax
  char pString[2060]; // [esp+Ch] [ebp-1054h] BYREF
  char pDest[1024]; // [esp+818h] [ebp-848h] BYREF
  char v24[1024]; // [esp+C18h] [ebp-448h] BYREF
  CUtlBuffer v25; // [esp+1018h] [ebp-48h] BYREF
  CMemoryBSPFile *v26; // [esp+1048h] [ebp-18h]
  int v27; // [esp+104Ch] [ebp-14h]
  int v28; // [esp+1050h] [ebp-10h]
  int v29; // [esp+1054h] [ebp-Ch]
  MapEntityKeyValuePair_t *m_pMemory; // [esp+1058h] [ebp-8h]
  int v31; // [esp+105Ch] [ebp-4h]

  v1 = this;
  v26 = this;
  CUtlBuffer::CUtlBuffer(this: &v25, growSize: 0, initSize: 0, nFlags: 1u);
  CUtlBuffer::EnsureCapacity(this: &v25, num: 0x40000);
  m_pMapFile = v1->m_pMapFile;
  v3 = 0;
  m_pMemory = m_pMapFile->m_KeyValuePairs.m_Memory.m_pMemory;
  v29 = 1;
  v28 = 0;
  if ( m_pMapFile->m_Entities.m_Size > 0 )
  {
    while ( 1 )
    {
      v4 = (int *)&m_pMapFile->m_Entities.m_Memory.m_pMemory[v3];
      if ( v4[6] > 0 && ((1 << (v3 & 0x1F)) & v1->m_EntityExclusionFlags.m_Ints[v3 >> 5]) == 0 )
        break;
LABEL_33:
      m_pMapFile = v1->m_pMapFile;
      v28 = ++v3;
      if ( v3 >= m_pMapFile->m_Entities.m_Size )
        goto LABEL_34;
    }
    CUtlBuffer::PutString(this: &v25, pString: "{\n");
    if ( v3 != 0 )
    {
      if ( v3 < 1 || v4[4] <= 0 )
        goto LABEL_10;
      V_strncpy(pDest, pSrc: "model", maxLen: 1024);
      v5 = v29;
      V_snprintf(pDest: v24, maxLen: 0x400u, pFormat: "*%i", v29);
      v29 = v5 + 1;
      V_snprintf(pDest: pString, maxLen: 0x80Au, pFormat: "\"%s\" \"%s\"\n", pDest, v24);
    }
    else
    {
      V_strncpy(pDest, pSrc: "world_maxs", maxLen: 1024);
      V_snprintf(
        pDest: v24,
        maxLen: 0x400u,
        pFormat: "%d %d %d",
        (int)v1->m_ModelList.m_Memory.m_pMemory->maxs.x,
        (int)v1->m_ModelList.m_Memory.m_pMemory->maxs.y,
        (int)v1->m_ModelList.m_Memory.m_pMemory->maxs.z);
      V_snprintf(pDest: pString, maxLen: 0x80Au, pFormat: "\"%s\" \"%s\"\n", pDest, v24);
      CUtlBuffer::PutString(this: &v25, pString);
      V_strncpy(pDest, pSrc: "world_mins", maxLen: 1024);
      V_snprintf(
        pDest: v24,
        maxLen: 0x400u,
        pFormat: "%d %d %d",
        (int)v1->m_ModelList.m_Memory.m_pMemory->mins.x,
        (int)v1->m_ModelList.m_Memory.m_pMemory->mins.y,
        (int)v1->m_ModelList.m_Memory.m_pMemory->mins.z);
      V_snprintf(pDest: pString, maxLen: 0x80Au, pFormat: "\"%s\" \"%s\"\n", pDest, v24);
    }
    CUtlBuffer::PutString(this: &v25, pString);
LABEL_10:
    v6 = v4[5];
    v7 = v4[6];
    v8 = v7 + v6 - 1;
    if ( v8 >= v6 )
    {
      p_m_pValue = (int)&m_pMemory[v8].m_pValue;
      v27 = v7;
      v31 = v7;
      do
      {
        if ( *(_BYTE *)(p_m_pValue + 4) == 0 )
        {
          V_strncpy(pDest, pSrc: *(char **)(p_m_pValue - 4), maxLen: 1024);
          for ( i = &pDest[strlen(pDest)]; i >= pDest; *i-- = 0 )
          {
            if ( *i > 32 )
              break;
          }
          V_strncpy(pDest: v24, pSrc: *(char **)p_m_pValue, maxLen: 1024);
          for ( j = &v24[strlen(v24)]; j >= v24; *j-- = 0 )
          {
            if ( *j > 32 )
              break;
          }
          V_snprintf(pDest: pString, maxLen: 0x80Au, pFormat: "\"%s\" \"%s\"\n", pDest, v24);
          CUtlBuffer::PutString(this: &v25, pString);
        }
        p_m_pValue -= 12;
        --v31;
      }
      while ( v31 != 0 );
      if ( v6 <= v8 )
      {
        v12 = v6;
        v13 = v27;
        v14 = (int)&m_pMemory[v12].m_pValue;
        do
        {
          if ( *(_BYTE *)(v14 + 4) != 0 )
          {
            V_strncpy(pDest, pSrc: *(char **)(v14 - 4), maxLen: 1024);
            for ( k = &pDest[strlen(pDest)]; k >= pDest; *k-- = 0 )
            {
              if ( *k > 32 )
                break;
            }
            V_strncpy(pDest: v24, pSrc: *(char **)v14, maxLen: 1024);
            for ( m = &v24[strlen(v24)]; m >= v24; *m-- = 0 )
            {
              if ( *m > 32 )
                break;
            }
            V_snprintf(pDest: pString, maxLen: 0x80Au, pFormat: "\"%s\" \"%s\"\n", pDest, v24);
            CUtlBuffer::PutString(this: &v25, pString);
          }
          v14 += 12;
          --v13;
        }
        while ( v13 != 0 );
      }
    }
    CUtlBuffer::PutString(this: &v25, pString: "}\n");
    v3 = v28;
    v1 = v26;
    goto LABEL_33;
  }
LABEL_34:
  v18 = v25.m_Put + 1;
  v17 = v25.m_Put == -1;
  v1->m_EntityData.m_Size = 0;
  if ( !v17 )
  {
    m_nAllocationCount = v1->m_EntityData.m_Memory.m_nAllocationCount;
    if ( v18 > m_nAllocationCount )
      CUtlMemory<char,int>::Grow(this: &v1->m_EntityData.m_Memory, num: v18 - m_nAllocationCount);
    v1->m_EntityData.m_Size += v18;
    v20 = v1->m_EntityData.m_Memory.m_pMemory;
    v21 = v1->m_EntityData.m_Size - v18;
    v1->m_EntityData.m_pElements = v20;
    if ( v21 > 0 && v18 > 0 )
      _V_memmove(dest: &v20[v18], src: v20, count: v21);
  }
  memcpy(dst: v1->m_EntityData.m_Memory.m_pMemory, src: v25.m_Memory.m_pMemory, count: v25.m_Put);
  v1->m_EntityData.m_Memory.m_pMemory[v25.m_Put] = 0;
  if ( v25.m_Memory.m_nGrowSize >= 0 && v25.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v25.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1006A800
// Name: private: void CMemoryBSPFile::BuildVisibilityData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::BuildVisibilityData(CMemoryBSPFile *this)
{
  const CSimpleBSPFile *m_pSimpleBSPFile; // ecx
  int m_Size; // ebx
  const unsigned __int8 *m_pMemory; // eax
  int v5; // edi
  int m_nAllocationCount; // eax
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *p_m_VisibilityData; // esi
  unsigned __int8 *v8; // ecx
  signed int v9; // eax
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // edi
  int v12; // edi
  int v13; // ebx
  int v14; // eax
  unsigned __int8 *v15; // ecx
  signed int v16; // eax
  int v17; // eax
  int v18; // ecx
  CMemoryBSPFile *v19; // eax
  int v20; // ebx
  int v21; // edi
  int v22; // eax
  unsigned __int8 *v23; // ecx
  signed int v24; // eax
  const unsigned __int8 *v25; // ecx
  int v26; // ebx
  int v27; // edx
  const unsigned __int8 *v28; // ecx
  int v29; // edi
  int v30; // eax
  unsigned __int8 *v31; // ecx
  signed int v32; // eax
  unsigned __int8 *v33; // eax
  CUtlBuffer visDataLumpHeader; // [esp+Ch] [ebp-4Ch] BYREF
  int nHeaderOffset; // [esp+3Ch] [ebp-1Ch]
  CMemoryBSPFile *v36; // [esp+40h] [ebp-18h]
  int v37; // [esp+44h] [ebp-14h]
  const unsigned __int8 *pVisibilityData; // [esp+48h] [ebp-10h]
  int nRowLength; // [esp+4Ch] [ebp-Ch]
  int nNumClusters; // [esp+50h] [ebp-8h]
  int nRepetitions; // [esp+54h] [ebp-4h]

  m_pSimpleBSPFile = this->m_pSimpleBSPFile;
  m_Size = m_pSimpleBSPFile->m_Clusters.m_Size;
  nRowLength = (m_Size + 7) / 8;
  m_pMemory = m_pSimpleBSPFile->m_VisibilityData.m_Memory.m_pMemory;
  v36 = this;
  nNumClusters = m_Size;
  pVisibilityData = m_pMemory;
  CUtlBuffer::CUtlBuffer(this: &visDataLumpHeader, growSize: 0, initSize: 0, nFlags: 0);
  if ( (visDataLumpHeader.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &visDataLumpHeader, pFmt: "%d", m_Size);
  else
    CUtlBuffer::PutTypeBin<int>(this: &visDataLumpHeader, src: m_Size);
  v5 = this->m_VisibilityData.m_Size;
  m_nAllocationCount = this->m_VisibilityData.m_Memory.m_nAllocationCount;
  p_m_VisibilityData = &this->m_VisibilityData;
  if ( v5 + 4 > m_nAllocationCount )
    CUtlMemory<char,int>::Grow(this: &p_m_VisibilityData->m_Memory, num: v5 - m_nAllocationCount + 4);
  p_m_VisibilityData->m_Size += 4;
  v8 = p_m_VisibilityData->m_Memory.m_pMemory;
  v9 = p_m_VisibilityData->m_Size - v5 - 4;
  p_m_VisibilityData->m_pElements = p_m_VisibilityData->m_Memory.m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &v8[v5 + 4], src: &v8[v5], count: v9);
  v10 = &p_m_VisibilityData->m_Memory.m_pMemory[v5];
  if ( v10 != nullptr )
    *v10 = m_Size;
  if ( &p_m_VisibilityData->m_Memory.m_pMemory[v5] != (unsigned __int8 *)-1 )
    p_m_VisibilityData->m_Memory.m_pMemory[v5 + 1] = BYTE1(m_Size);
  if ( &p_m_VisibilityData->m_Memory.m_pMemory[v5] != (unsigned __int8 *)-2 )
    p_m_VisibilityData->m_Memory.m_pMemory[v5 + 2] = BYTE2(nNumClusters);
  v11 = &p_m_VisibilityData->m_Memory.m_pMemory[v5 + 3];
  if ( v11 != nullptr )
    *v11 = HIBYTE(nNumClusters);
  v12 = 8 * m_Size;
  v13 = p_m_VisibilityData->m_Size;
  if ( v12 != 0 )
  {
    v14 = p_m_VisibilityData->m_Memory.m_nAllocationCount;
    if ( v13 + v12 > v14 )
      CUtlMemory<char,int>::Grow(this: &p_m_VisibilityData->m_Memory, num: v12 + v13 - v14);
    p_m_VisibilityData->m_Size += v12;
    v15 = p_m_VisibilityData->m_Memory.m_pMemory;
    v16 = p_m_VisibilityData->m_Size - v13 - v12;
    p_m_VisibilityData->m_pElements = p_m_VisibilityData->m_Memory.m_pMemory;
    if ( v16 > 0 && v12 > 0 )
      _V_memmove(dest: &v15[v13 + v12], src: &v15[v13], count: v16);
  }
  v17 = nNumClusters;
  v18 = 4;
  if ( nNumClusters > 0 )
  {
    nNumClusters = 0;
    v37 = v17;
    do
    {
      v19 = v36;
      *(_DWORD *)&p_m_VisibilityData->m_Memory.m_pMemory[v18] = v36->m_VisibilityData.m_Size;
      *(_DWORD *)&p_m_VisibilityData->m_Memory.m_pMemory[v18 + 4] = v19->m_VisibilityData.m_Size;
      v18 += 8;
      v20 = 0;
      nHeaderOffset = v18;
      if ( nRowLength > 0 )
      {
        do
        {
          v21 = p_m_VisibilityData->m_Size;
          v22 = p_m_VisibilityData->m_Memory.m_nAllocationCount;
          if ( v21 + 1 > v22 )
            CUtlMemory<char,int>::Grow(this: &p_m_VisibilityData->m_Memory, num: v21 - v22 + 1);
          ++p_m_VisibilityData->m_Size;
          v23 = p_m_VisibilityData->m_Memory.m_pMemory;
          v24 = p_m_VisibilityData->m_Size - v21 - 1;
          p_m_VisibilityData->m_pElements = p_m_VisibilityData->m_Memory.m_pMemory;
          if ( v24 > 0 )
            _V_memmove(dest: &v23[v21 + 1], src: &v23[v21], count: v24);
          v25 = pVisibilityData;
          if ( &p_m_VisibilityData->m_Memory.m_pMemory[v21] != nullptr )
            p_m_VisibilityData->m_Memory.m_pMemory[v21] = pVisibilityData[v20 + nNumClusters];
          if ( v25[v20 + nNumClusters] == 0 )
          {
            v26 = v20 + 1;
            v27 = 1;
            nRepetitions = 1;
            if ( v26 < nRowLength )
            {
              v28 = &v25[nNumClusters];
              do
              {
                if ( v28[v26] != 0 )
                  break;
                if ( v27 == 255 )
                  break;
                ++v26;
                ++v27;
              }
              while ( v26 < nRowLength );
              nRepetitions = v27;
            }
            v29 = p_m_VisibilityData->m_Size;
            v30 = p_m_VisibilityData->m_Memory.m_nAllocationCount;
            if ( v29 + 1 > v30 )
            {
              CUtlMemory<char,int>::Grow(this: &p_m_VisibilityData->m_Memory, num: v29 - v30 + 1);
              LOBYTE(v27) = nRepetitions;
            }
            ++p_m_VisibilityData->m_Size;
            v31 = p_m_VisibilityData->m_Memory.m_pMemory;
            v32 = p_m_VisibilityData->m_Size - v29 - 1;
            p_m_VisibilityData->m_pElements = p_m_VisibilityData->m_Memory.m_pMemory;
            if ( v32 > 0 )
            {
              _V_memmove(dest: &v31[v29 + 1], src: &v31[v29], count: v32);
              LOBYTE(v27) = nRepetitions;
            }
            v33 = &p_m_VisibilityData->m_Memory.m_pMemory[v29];
            if ( v33 != nullptr )
              *v33 = v27;
            v20 = v26 - 1;
          }
          ++v20;
        }
        while ( v20 < nRowLength );
        v18 = nHeaderOffset;
      }
      nNumClusters += nRowLength;
      --v37;
    }
    while ( v37 != 0 );
  }
  if ( visDataLumpHeader.m_Memory.m_nGrowSize >= 0 && visDataLumpHeader.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: visDataLumpHeader.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1006AA80
// Name: private: int CMemoryBSPFile::RemapWorldMaterial(class CUtlVector<int,class CUtlMemory<int,int>> __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMemoryBSPFile::RemapWorldMaterial(
        CMemoryBSPFile *this,
        CUtlVector<int,CUtlMemory<int,int> > *pWorldPropertyRemapList,
        int nSurfacePropertyIndex)
{
  int m_Size; // edi
  int result; // eax
  int *v5; // ecx
  int m_nAllocationCount; // ecx
  int *m_pMemory; // ecx
  int v8; // eax
  int *v9; // eax

  m_Size = pWorldPropertyRemapList->m_Size;
  result = 0;
  if ( m_Size <= 0 )
  {
LABEL_5:
    m_nAllocationCount = pWorldPropertyRemapList->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)pWorldPropertyRemapList,
        num: m_Size - m_nAllocationCount + 1);
    ++pWorldPropertyRemapList->m_Size;
    m_pMemory = pWorldPropertyRemapList->m_Memory.m_pMemory;
    v8 = pWorldPropertyRemapList->m_Size - m_Size - 1;
    pWorldPropertyRemapList->m_pElements = pWorldPropertyRemapList->m_Memory.m_pMemory;
    if ( v8 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v8);
    v9 = &pWorldPropertyRemapList->m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = nSurfacePropertyIndex;
    return m_Size + 1;
  }
  else
  {
    v5 = pWorldPropertyRemapList->m_Memory.m_pMemory;
    while ( 1 )
    {
      ++result;
      if ( *v5 == nSurfacePropertyIndex )
        break;
      ++v5;
      if ( result >= m_Size )
        goto LABEL_5;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1006AB00
// Name: private: void CMemoryBSPFile::WritePhysicsCollisionData(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WritePhysicsCollisionData(CMemoryBSPFile *this, bool bPurgeWhenComplete)
{
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *p_m_PhysicsDisplacementData; // edi

  p_m_PhysicsDisplacementData = &this->m_PhysicsDisplacementData;
  CMemoryBSPFile::WriteLump<char>(
    this,
    nLump: 28,
    data: (const CUtlVector<char,CUtlMemory<char,int> > *)&this->m_PhysicsDisplacementData,
    nVersion: 0);
  CMemoryBSPFile::WriteLump<char>(
    this,
    nLump: 29,
    data: (const CUtlVector<char,CUtlMemory<char,int> > *)&this->m_PhysicsCollideData,
    nVersion: 0);
  if ( bPurgeWhenComplete )
  {
    p_m_PhysicsDisplacementData->m_Size = 0;
    if ( p_m_PhysicsDisplacementData->m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_PhysicsDisplacementData->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_PhysicsDisplacementData->m_Memory.m_pMemory);
        p_m_PhysicsDisplacementData->m_Memory.m_pMemory = nullptr;
      }
      p_m_PhysicsDisplacementData->m_Memory.m_nAllocationCount = 0;
    }
    p_m_PhysicsDisplacementData->m_pElements = p_m_PhysicsDisplacementData->m_Memory.m_pMemory;
    this->m_PhysicsCollideData.m_Size = 0;
    if ( this->m_PhysicsCollideData.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_PhysicsCollideData.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_PhysicsCollideData.m_Memory.m_pMemory);
        this->m_PhysicsCollideData.m_Memory.m_pMemory = nullptr;
      }
      this->m_PhysicsCollideData.m_Memory.m_nAllocationCount = 0;
    }
    this->m_PhysicsCollideData.m_pElements = this->m_PhysicsCollideData.m_Memory.m_pMemory;
    this->m_FaceList.m_Size = 0;
    if ( this->m_FaceList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_FaceList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FaceList.m_Memory.m_pMemory);
        this->m_FaceList.m_Memory.m_pMemory = nullptr;
      }
      this->m_FaceList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_FaceList.m_pElements = this->m_FaceList.m_Memory.m_pMemory;
    this->m_ModelList.m_Size = 0;
    if ( this->m_ModelList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_ModelList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ModelList.m_Memory.m_pMemory);
        this->m_ModelList.m_Memory.m_pMemory = nullptr;
      }
      this->m_ModelList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_ModelList.m_pElements = this->m_ModelList.m_Memory.m_pMemory;
    this->m_LeafList.m_Size = 0;
    if ( this->m_LeafList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_LeafList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_LeafList.m_Memory.m_pMemory);
        this->m_LeafList.m_Memory.m_pMemory = nullptr;
      }
      this->m_LeafList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_LeafList.m_pElements = this->m_LeafList.m_Memory.m_pMemory;
    this->m_LeafBrushList.m_Size = 0;
    if ( this->m_LeafBrushList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_LeafBrushList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_LeafBrushList.m_Memory.m_pMemory);
        this->m_LeafBrushList.m_Memory.m_pMemory = nullptr;
      }
      this->m_LeafBrushList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_LeafBrushList.m_pElements = this->m_LeafBrushList.m_Memory.m_pMemory;
    this->m_NodeList.m_Size = 0;
    if ( this->m_NodeList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_NodeList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_NodeList.m_Memory.m_pMemory);
        this->m_NodeList.m_Memory.m_pMemory = nullptr;
      }
      this->m_NodeList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_NodeList.m_pElements = this->m_NodeList.m_Memory.m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006ACF0
// Name: private: void CMemoryBSPFile::WriteLightingData(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLightingData(CMemoryBSPFile *this, bool bPurgeWhenComplete)
{
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *p_m_LightingData; // edi
  CUtlVector<dworldlight_t,CUtlMemory<dworldlight_t,int> > *p_m_WorldLightsLDR; // ebx
  CUtlVector<dworldlight_t,CUtlMemory<dworldlight_t,int> > *p_m_WorldLightsHDR; // [esp+Ch] [ebp-4h]

  p_m_LightingData = &this->m_LightingData;
  CMemoryBSPFile::WriteLump<char>(
    this,
    nLump: 8,
    data: (const CUtlVector<char,CUtlMemory<char,int> > *)&this->m_LightingData,
    nVersion: 1);
  p_m_WorldLightsLDR = &this->m_WorldLightsLDR;
  CMemoryBSPFile::WriteLump<dworldlight_t>(this, nLump: 15, data: &this->m_WorldLightsLDR, nVersion: 1);
  p_m_WorldLightsHDR = &this->m_WorldLightsHDR;
  CMemoryBSPFile::WriteLump<dworldlight_t>(this, nLump: 54, data: &this->m_WorldLightsHDR, nVersion: 1);
  if ( bPurgeWhenComplete )
  {
    p_m_LightingData->m_Size = 0;
    if ( p_m_LightingData->m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_LightingData->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_LightingData->m_Memory.m_pMemory);
        p_m_LightingData->m_Memory.m_pMemory = nullptr;
      }
      p_m_LightingData->m_Memory.m_nAllocationCount = 0;
    }
    p_m_LightingData->m_pElements = p_m_LightingData->m_Memory.m_pMemory;
    this->m_WorldLightsLDR.m_Size = 0;
    if ( this->m_WorldLightsLDR.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_WorldLightsLDR->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_WorldLightsLDR->m_Memory.m_pMemory);
        p_m_WorldLightsLDR->m_Memory.m_pMemory = nullptr;
      }
      this->m_WorldLightsLDR.m_Memory.m_nAllocationCount = 0;
    }
    this->m_WorldLightsLDR.m_pElements = this->m_WorldLightsLDR.m_Memory.m_pMemory;
    this->m_WorldLightsHDR.m_Size = 0;
    if ( this->m_WorldLightsHDR.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_WorldLightsHDR->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_WorldLightsHDR->m_Memory.m_pMemory);
        p_m_WorldLightsHDR->m_Memory.m_pMemory = nullptr;
      }
      this->m_WorldLightsHDR.m_Memory.m_nAllocationCount = 0;
    }
    this->m_WorldLightsHDR.m_pElements = this->m_WorldLightsHDR.m_Memory.m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006ADC0
// Name: private: void CMemoryBSPFile::BuildTexInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::BuildTexInfo(CMemoryBSPFile *this)
{
  const CSimpleMapFile *m_pMapFile; // eax
  int m_Size; // esi
  MapTextureInfo_t *m_pMemory; // edi
  CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int> > *p_m_TexInfoList; // ebx
  unsigned __int8 *p_m_SurfaceFlags; // edi
  int v6; // eax
  int v7; // esi
  int v8; // ecx
  bool v9; // zf
  int i; // [esp+Ch] [ebp-8h]
  const MapTextureInfo_t *pTextureInfos; // [esp+10h] [ebp-4h]
  const MapTextureInfo_t *pTextureInfosa; // [esp+10h] [ebp-4h]

  m_pMapFile = this->m_pMapFile;
  m_Size = m_pMapFile->m_TextureInfos.m_Size;
  m_pMemory = m_pMapFile->m_TextureInfos.m_Memory.m_pMemory;
  p_m_TexInfoList = &this->m_TexInfoList;
  pTextureInfos = m_pMemory;
  this->m_TexInfoList.m_Size = 0;
  CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int>>::InsertMultipleBefore(
    this: &this->m_TexInfoList,
    elem: 0,
    num: m_Size);
  if ( m_Size > 0 )
  {
    p_m_SurfaceFlags = (unsigned __int8 *)&m_pMemory->m_SurfaceFlags;
    v6 = -68 - (_DWORD)pTextureInfos;
    pTextureInfosa = (const MapTextureInfo_t *)m_Size;
    for ( i = v6; ; v6 = i )
    {
      v7 = (int)p_m_TexInfoList->m_Memory.m_pMemory + (unsigned int)&p_m_SurfaceFlags[v6];
      _V_memcpy(dest: (unsigned __int8 *)v7, src: p_m_SurfaceFlags - 68, count: 0x20u);
      _V_memcpy(dest: (unsigned __int8 *)(v7 + 32), src: p_m_SurfaceFlags - 36, count: 0x20u);
      *(_DWORD *)(v7 + 64) = *(__int16 *)p_m_SurfaceFlags;
      v8 = *((_DWORD *)p_m_SurfaceFlags - 1);
      p_m_SurfaceFlags += 72;
      v9 = pTextureInfosa == (const MapTextureInfo_t *)1;
      pTextureInfosa = (const MapTextureInfo_t *)((char *)pTextureInfosa - 1);
      *(_DWORD *)(v7 + 68) = v8;
      if ( v9 )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006AE60
// Name: private: void CMemoryBSPFile::BuildTexData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::BuildTexData(CMemoryBSPFile *this)
{
  CMemoryBSPFile *v1; // esi
  const CSimpleMapFile *m_pMapFile; // eax
  int m_Size; // ebx
  MapTextureData_t *m_pMemory; // edi
  CUtlVector<dtexdata_t,CUtlMemory<dtexdata_t,int> > *p_m_TexDataList; // ecx
  int v6; // ebx
  float *p_z; // edi
  dtexdata_t *v8; // esi
  dtexdata_t *v9; // esi
  int v10; // eax
  int v11; // eax
  bool v12; // zf
  int nTextureDataCount; // [esp+Ch] [ebp-8h]
  CMemoryBSPFile *v14; // [esp+10h] [ebp-4h]

  v1 = this;
  m_pMapFile = this->m_pMapFile;
  m_Size = m_pMapFile->m_TextureData.m_Size;
  m_pMemory = m_pMapFile->m_TextureData.m_Memory.m_pMemory;
  p_m_TexDataList = &this->m_TexDataList;
  v14 = v1;
  nTextureDataCount = m_Size;
  p_m_TexDataList->m_Size = 0;
  CUtlVector<dtexdata_t,CUtlMemory<dtexdata_t,int>>::InsertMultipleBefore(this: p_m_TexDataList, elem: 0, num: m_Size);
  if ( m_Size > 0 )
  {
    v6 = 0;
    p_z = &m_pMemory->m_vReflectivity.z;
    while ( 1 )
    {
      v8 = v1->m_TexDataList.m_Memory.m_pMemory;
      v8[v6].reflectivity.x = *(p_z - 2);
      v9 = &v8[v6];
      v9->reflectivity.y = *(p_z - 1);
      v9->reflectivity.z = *p_z;
      v9->nameStringTableID = CMemoryBSPFile::FindOrAddString(this: v14, pString: (const char *)p_z + 12);
      v10 = *((_DWORD *)p_z + 1);
      v9->view_width = v10;
      v9->width = v10;
      v11 = *((_DWORD *)p_z + 2);
      ++v6;
      p_z += 37;
      v12 = nTextureDataCount-- == 1;
      v9->view_height = v11;
      v9->height = v11;
      if ( v12 )
        break;
      v1 = v14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006AF10
// Name: private: void CMemoryBSPFile::WritePortalFaces(class CBSPNode const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WritePortalFaces(CMemoryBSPFile *this, const CBSPNode *pNode)
{
  const CBSPNode *i; // esi
  int j; // edi

  for ( i = pNode; i->m_nSplitPlaneIndex != -1; i = i->m_pChildren[1] )
  {
    for ( j = 0; j < i->m_Faces.m_Size; ++j )
      CMemoryBSPFile::EmitFace(this, pBSPFace: i->m_Faces.m_Memory.m_pMemory[j], bOnNode: true);
    CMemoryBSPFile::WritePortalFaces(this, pNode: i->m_pChildren[0]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006AF60
// Name: private: void CMemoryBSPFile::BuildBSPTreeData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::BuildBSPTreeData(CMemoryBSPFile *this)
{
  int m_Size; // edx
  int v3; // ebx
  const CSimpleBSPFile *m_pSimpleBSPFile; // eax
  dmodel_t *v5; // edi
  int v6; // eax
  dleaf_t sentinelLeaf; // [esp+8h] [ebp-24h] BYREF
  unsigned int v8; // [esp+28h] [ebp-4h]

  m_Size = this->m_LeafList.m_Size;
  v3 = 0;
  memset(&sentinelLeaf.cluster, 0, 28);
  sentinelLeaf.contents = 1;
  CUtlVector<dleaf_t,CUtlMemory<dleaf_t,int>>::InsertBefore(this: &this->m_LeafList, elem: m_Size, src: &sentinelLeaf);
  m_pSimpleBSPFile = this->m_pSimpleBSPFile;
  if ( m_pSimpleBSPFile->m_Models.m_Size > 0 )
  {
    v8 = 0;
    do
    {
      v5 = &this->m_ModelList.m_Memory.m_pMemory[v8 / 0x30];
      v6 = CMemoryBSPFile::EmitNode(this, pNode: m_pSimpleBSPFile->m_Models.m_Memory.m_pMemory[v3]->m_pTree->m_pRoot);
      v8 += 48;
      v5->headnode = v6;
      m_pSimpleBSPFile = this->m_pSimpleBSPFile;
      ++v3;
    }
    while ( v3 < m_pSimpleBSPFile->m_Models.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006AFF0
// Name: private: void CMemoryBSPFile::BuildBrushes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::BuildBrushes(CMemoryBSPFile *this)
{
  CMemoryBSPFile *v1; // edi
  dbrush_t *m_Size; // esi
  CUtlVector<Vector,CUtlMemory<Vector,int> > *p_m_BrushList; // ecx
  dbrush_t *v4; // eax
  MapBrush_t *v5; // edx
  int v6; // ebx
  CUtlMemory<vgui::PropertySheet::Page_t,int> *p_m_BrushSideList; // esi
  const CSimpleMapFile *m_pMapFile; // ecx
  vgui::PropertySheet::Page_t *m_pMemory; // edi
  int v10; // eax
  int m_nAllocationCount; // eax
  vgui::PropertySheet::Page_t *v12; // ecx
  int v13; // eax
  vgui::PropertySheet::Page_t *v14; // eax
  const MapBrush_t *p_m_vMaxBounds; // edx
  int v16; // ebx
  float v17; // xmm0_4
  int PlaneIndex; // eax
  int m_nNumSides; // edx
  int v20; // ecx
  int *p_m_nPlaneIndex; // esi
  CUtlMemory<vgui::PropertySheet::Page_t,int> *v22; // esi
  int v23; // edi
  int v24; // eax
  vgui::PropertySheet::Page_t *v25; // ecx
  int v26; // eax
  vgui::PropertySheet::Page_t *v27; // eax
  int v28; // ecx
  Vector vNormal; // [esp+Ch] [ebp-44h] BYREF
  vgui::Panel *v30; // [esp+18h] [ebp-38h]
  int v31; // [esp+1Ch] [ebp-34h]
  vgui::Panel *v32; // [esp+20h] [ebp-30h]
  dbrushside_t brushSide; // [esp+24h] [ebp-2Ch]
  dbrush_t *brush; // [esp+2Ch] [ebp-24h]
  int v35; // [esp+30h] [ebp-20h]
  int i; // [esp+34h] [ebp-1Ch]
  int nSide; // [esp+38h] [ebp-18h]
  unsigned int v38; // [esp+3Ch] [ebp-14h]
  Vector *p_vNormal; // [esp+40h] [ebp-10h]
  CMemoryBSPFile *v40; // [esp+44h] [ebp-Ch]
  MapBrush_t *v41; // [esp+48h] [ebp-8h]
  const MapBrush_t *pMapBrush; // [esp+4Ch] [ebp-4h]

  v1 = this;
  m_Size = (dbrush_t *)this->m_pMapFile->m_Brushes.m_Size;
  p_m_BrushList = (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_BrushList;
  v40 = v1;
  p_m_BrushList->m_Size = 0;
  CUtlVector<dbrush_t,CUtlMemory<dbrush_t,int>>::InsertMultipleBefore(this: p_m_BrushList, elem: 0, num: (int)m_Size);
  if ( (int)m_Size > 0 )
  {
    nSide = 0;
    v38 = 0;
    for ( brush = m_Size; brush != nullptr; brush = (dbrush_t *)((char *)brush - 1) )
    {
      v4 = &v1->m_BrushList.m_Memory.m_pMemory[nSide / 0xCu];
      v5 = &v1->m_pMapFile->m_Brushes.m_Memory.m_pMemory[v38 / 0x24];
      v4->firstside = v1->m_BrushSideList.m_Size;
      v4->numsides = v5->m_nNumSides;
      v6 = 0;
      v4->contents = v5->m_ContentsFlags;
      v41 = v5;
      *(_DWORD *)&brushSide.dispinfo = v4;
      if ( v5->m_nNumSides > 0 )
      {
        p_m_BrushSideList = (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&v1->m_BrushSideList;
        do
        {
          m_pMapFile = v1->m_pMapFile;
          m_pMemory = p_m_BrushSideList[1].m_pMemory;
          v10 = (int)&m_pMapFile->m_BrushSides.m_Memory.m_pMemory[v6 + v5->m_nFirstSideIndex];
          LOWORD(m_pMapFile) = *(_WORD *)(v10 + 8);
          LOWORD(v10) = *(_WORD *)(v10 + 12);
          LOWORD(v32) = (_WORD)m_pMapFile;
          HIWORD(v32) = v10;
          m_nAllocationCount = p_m_BrushSideList->m_nAllocationCount;
          brushSide.planenum = 0;
          LOBYTE(brushSide.texinfo) = 0;
          if ( (int)&m_pMemory->page + 1 > m_nAllocationCount )
          {
            CUtlMemory<EnumEntry_t,int>::Grow(
              this: p_m_BrushSideList,
              num: (int)&m_pMemory->page - m_nAllocationCount + 1);
            v5 = v41;
          }
          ++p_m_BrushSideList[1].m_pMemory;
          v12 = p_m_BrushSideList->m_pMemory;
          v13 = (char *)p_m_BrushSideList[1].m_pMemory - (char *)m_pMemory - 1;
          p_m_BrushSideList[1].m_nAllocationCount = (int)p_m_BrushSideList->m_pMemory;
          if ( v13 > 0 )
          {
            _V_memmove(
              dest: (unsigned __int8 *)&v12[(int)m_pMemory + 1],
              src: (unsigned __int8 *)&v12[(_DWORD)m_pMemory],
              count: 8 * v13);
            v5 = v41;
          }
          v14 = &p_m_BrushSideList->m_pMemory[(_DWORD)m_pMemory];
          if ( v14 != nullptr )
          {
            v14->page = v32;
            *(_DWORD *)&v14->contextMenu = *(_DWORD *)&brushSide.planenum;
          }
          v1 = v40;
          ++v6;
        }
        while ( v6 < v5->m_nNumSides );
      }
      p_m_vMaxBounds = (const MapBrush_t *)&v5->m_vMaxBounds;
      v16 = -1;
      p_vNormal = &vNormal;
      pMapBrush = p_m_vMaxBounds;
      v35 = 3;
      for ( i = -1; ; i = -1 )
      {
        while ( 1 )
        {
          vNormal = vec3_origin;
          p_vNormal->x = (float)v16;
          if ( v16 == -1 )
            LODWORD(v17) = LODWORD(p_m_vMaxBounds[-1].m_vMaxBounds.x) ^ _mask__NegFloat_;
          else
            v17 = *(float *)&p_m_vMaxBounds->m_ContentsFlags;
          PlaneIndex = CPlaneHash::FindPlaneIndex(this: &v1->m_PlaneHash, &vNormal, flDistance: v17);
          m_nNumSides = v41->m_nNumSides;
          v20 = 0;
          if ( m_nNumSides > 0 )
          {
            p_m_nPlaneIndex = &v1->m_pMapFile->m_BrushSides.m_Memory.m_pMemory[v41->m_nFirstSideIndex].m_nPlaneIndex;
            do
            {
              if ( *p_m_nPlaneIndex == PlaneIndex )
                break;
              ++v20;
              p_m_nPlaneIndex += 11;
            }
            while ( v20 < m_nNumSides );
            v16 = i;
          }
          if ( v20 == m_nNumSides )
          {
            v22 = (CUtlMemory<vgui::PropertySheet::Page_t,int> *)&v1->m_BrushSideList;
            v23 = v1->m_BrushSideList.m_Size;
            LOWORD(v30) = PlaneIndex;
            v24 = v22->m_nAllocationCount;
            HIWORD(v30) = HIWORD(v22->m_pMemory[v23 - 1].page);
            LOWORD(v31) = 0;
            BYTE2(v31) = 1;
            if ( v23 + 1 > v24 )
              CUtlMemory<EnumEntry_t,int>::Grow(this: v22, num: v23 - v24 + 1);
            ++v22[1].m_pMemory;
            v25 = v22->m_pMemory;
            v26 = (int)v22[1].m_pMemory - v23 - 1;
            v22[1].m_nAllocationCount = (int)v22->m_pMemory;
            if ( v26 > 0 )
              _V_memmove(dest: (unsigned __int8 *)&v25[v23 + 1], src: (unsigned __int8 *)&v25[v23], count: 8 * v26);
            v27 = &v22->m_pMemory[v23];
            if ( v27 != nullptr )
            {
              v28 = v31;
              v27->page = v30;
              *(_DWORD *)&v27->contextMenu = v28;
            }
            ++*(_DWORD *)(*(_DWORD *)&brushSide.dispinfo + 4);
            v1 = v40;
          }
          v16 += 2;
          i = v16;
          if ( v16 > 1 )
            break;
          p_m_vMaxBounds = pMapBrush;
        }
        p_vNormal = (Vector *)((char *)p_vNormal + 4);
        pMapBrush = (const MapBrush_t *)((char *)pMapBrush + 4);
        if ( --v35 == 0 )
          break;
        p_m_vMaxBounds = pMapBrush;
        v16 = -1;
      }
      v38 += 36;
      nSide += 12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006B280
// Name: private: void CMemoryBSPFile::BuildPlanes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::BuildPlanes(CMemoryBSPFile *this)
{
  int m_Size; // ebx
  int v3; // eax
  int v4; // ebx
  HashedPlane_t *m_pMemory; // edx
  dplane_t *v6; // ecx
  float *v7; // ecx
  HashedPlane_t *v8; // edx
  dplane_t *v9; // ecx
  int v10; // edx
  int v11; // ecx
  float *v12; // ecx
  HashedPlane_t *v13; // edx
  double v14; // st7
  int v15; // edx
  dplane_t *v16; // ecx
  bool v17; // zf
  HashedPlane_t *v18; // edx
  int v19; // edx
  int v20; // ebx
  HashedPlane_t *v21; // ecx
  dplane_t *v22; // eax
  dplane_t *v23; // eax
  int i; // [esp+Ch] [ebp-10h]
  unsigned int v25; // [esp+10h] [ebp-Ch]
  int v26; // [esp+10h] [ebp-Ch]
  int nPlaneCount; // [esp+14h] [ebp-8h]
  int v28; // [esp+18h] [ebp-4h]

  m_Size = this->m_PlaneHash.m_Planes.m_Size;
  nPlaneCount = m_Size;
  this->m_Planes.m_Size = 0;
  CUtlVector<dplane_t,CUtlMemory<dplane_t,int>>::InsertMultipleBefore(this: &this->m_Planes, elem: 0, num: m_Size);
  v3 = 0;
  if ( m_Size >= 4 )
  {
    v25 = ((unsigned int)(m_Size - 4) >> 2) + 1;
    v4 = 0;
    v28 = 0;
    i = 4 * v25;
    do
    {
      m_pMemory = this->m_PlaneHash.m_Planes.m_Memory.m_pMemory;
      v6 = this->m_Planes.m_Memory.m_pMemory;
      *(float *)((char *)&v6->normal.x + v4) = *(float *)((char *)&m_pMemory->m_vNormal.x + v3);
      v7 = (float *)((char *)&v6->normal.x + v4);
      v7[1] = *(float *)((char *)&m_pMemory->m_vNormal.y + v3);
      v7[2] = *(float *)((char *)&m_pMemory->m_vNormal.z + v3);
      v7[3] = *(float *)((char *)&this->m_PlaneHash.m_Planes.m_Memory.m_pMemory->m_flDistance + v3);
      v7[4] = *(float *)((char *)&this->m_PlaneHash.m_Planes.m_Memory.m_pMemory->m_Type + v3);
      v8 = this->m_PlaneHash.m_Planes.m_Memory.m_pMemory;
      v9 = this->m_Planes.m_Memory.m_pMemory;
      *(float *)((char *)&v9[1].normal.x + v4) = *(float *)((char *)&v8[1].m_vNormal.x + v3);
      v10 = (int)&v8[1] + v3;
      v11 = (int)&v9[1] + v4;
      *(float *)(v11 + 4) = *(float *)(v10 + 4);
      *(float *)(v11 + 8) = *(float *)(v10 + 8);
      *(float *)(v11 + 12) = *(float *)((char *)&this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[1].m_flDistance + v3);
      *(_DWORD *)(v11 + 16) = *(int *)((char *)&this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[1].m_Type + v3);
      v12 = (float *)((char *)&this->m_Planes.m_Memory.m_pMemory[2].normal.x + v4);
      v13 = this->m_PlaneHash.m_Planes.m_Memory.m_pMemory;
      v14 = *(float *)((char *)&v13[2].m_vNormal.x + v3);
      v15 = (int)&v13[2] + v3;
      *v12 = v14;
      v4 = v28 * 20 + 80;
      v12[1] = *(float *)(v15 + 4);
      v3 += 96;
      v12[2] = *(float *)(v15 + 8);
      v12[3] = *(float *)((char *)&this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[-1] + v3 - 12);
      v12[4] = *(float *)((char *)&this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[-1] + v3 - 8);
      v16 = &this->m_Planes.m_Memory.m_pMemory[v28 + 3];
      v17 = v25-- == 1;
      v18 = this->m_PlaneHash.m_Planes.m_Memory.m_pMemory;
      v28 += 4;
      v16->normal.x = *(float *)((char *)&v18[-1].m_vNormal.x + v3);
      v16->normal.y = *(float *)((char *)v18 + v3 - 20);
      v16->normal.z = *(float *)((char *)v18 + v3 - 16);
      v16->dist = *(float *)((char *)this->m_PlaneHash.m_Planes.m_Memory.m_pMemory + v3 - 12);
      v16->type = *(_DWORD *)((char *)this->m_PlaneHash.m_Planes.m_Memory.m_pMemory + v3 - 8);
    }
    while ( !v17 );
    v3 = i;
    m_Size = nPlaneCount;
  }
  if ( v3 < m_Size )
  {
    v19 = v3;
    v20 = v3;
    v26 = nPlaneCount - v3;
    do
    {
      v21 = this->m_PlaneHash.m_Planes.m_Memory.m_pMemory;
      v22 = this->m_Planes.m_Memory.m_pMemory;
      v22[v20].normal.x = v21[v19].m_vNormal.x;
      v23 = &v22[v20++];
      v23->normal.y = v21[v19++].m_vNormal.y;
      v17 = v26-- == 1;
      v23->normal.z = v21[v19 - 1].m_vNormal.z;
      v23->dist = this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[v19 - 1].m_flDistance;
      v23->type = this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[v19 - 1].m_Type;
    }
    while ( !v17 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006B430
// Name: private: int CMemoryBSPFile::AddStaticPropDictionaryEntry(char const __near *,class CUtlVector<struct StaticPropDictLump_t,class CUtlMemory<struct StaticPropDictLump_t,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMemoryBSPFile::AddStaticPropDictionaryEntry(
        CMemoryBSPFile *this,
        char *pModelName,
        CUtlVector<StaticPropDictLump_t,CUtlMemory<StaticPropDictLump_t,int> > *pStaticPropDictionaryLump)
{
  int v3; // edi
  int v4; // ebx
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  StaticPropDictLump_t *m_pMemory; // ecx
  int v8; // eax
  StaticPropDictLump_t *v9; // edi
  StaticPropDictLump_t dictionaryEntry; // [esp+Ch] [ebp-80h] BYREF

  memset(&dictionaryEntry, 0, sizeof(dictionaryEntry));
  V_strncpy(pDest: dictionaryEntry.m_Name, pSrc: pModelName, maxLen: 128);
  v3 = 0;
  if ( pStaticPropDictionaryLump->m_Size <= 0 )
  {
LABEL_5:
    m_Size = pStaticPropDictionaryLump->m_Size;
    m_nAllocationCount = pStaticPropDictionaryLump->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<StaticPropDictLump_t,int>::Grow(
        this: &pStaticPropDictionaryLump->m_Memory,
        num: m_Size - m_nAllocationCount + 1);
    ++pStaticPropDictionaryLump->m_Size;
    m_pMemory = pStaticPropDictionaryLump->m_Memory.m_pMemory;
    v8 = pStaticPropDictionaryLump->m_Size - m_Size - 1;
    pStaticPropDictionaryLump->m_pElements = pStaticPropDictionaryLump->m_Memory.m_pMemory;
    if ( v8 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: v8 << 7);
    v9 = &pStaticPropDictionaryLump->m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = dictionaryEntry;
    return m_Size;
  }
  else
  {
    v4 = 0;
    while ( _V_memcmp(m1: pStaticPropDictionaryLump->m_Memory.m_pMemory[v4].m_Name, m2: &dictionaryEntry, count: 0x80u) != 0 )
    {
      ++v3;
      ++v4;
      if ( v3 >= pStaticPropDictionaryLump->m_Size )
        goto LABEL_5;
    }
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006B500
// Name: private: int CMemoryBSPFile::AddStaticPropLeaves(class Vector const __near &,int,class CUtlVector<struct StaticPropLeafLump_t,class CUtlMemory<struct StaticPropLeafLump_t,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMemoryBSPFile::AddStaticPropLeaves(
        CMemoryBSPFile *this,
        const Vector *vOrigin,
        int nNodeIndex,
        CUtlVector<StaticPropLeafLump_t,CUtlMemory<StaticPropLeafLump_t,int> > *pStaticPropLeafLump)
{
  int v5; // ecx
  dnode_t *m_pMemory; // ebx
  int v7; // edx
  HashedPlane_t *v8; // eax
  float v9; // xmm0_4
  int m_Size; // edi
  int m_nAllocationCount; // eax
  unsigned __int16 v12; // bx
  StaticPropLeafLump_t *v13; // ecx
  int v14; // eax
  StaticPropLeafLump_t *v15; // edi
  int v17; // esi
  int v18; // ebx

  v5 = nNodeIndex;
  if ( nNodeIndex >= 0 )
  {
    m_pMemory = this->m_NodeList.m_Memory.m_pMemory;
    do
    {
      v7 = v5;
      v8 = &this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[m_pMemory[v5].planenum];
      v9 = (float)((float)((float)(v8->m_vNormal.y * vOrigin->y) + (float)(vOrigin->x * v8->m_vNormal.x))
                 + (float)(v8->m_vNormal.z * vOrigin->z))
         - v8->m_flDistance;
      if ( v9 >= -250.0 )
      {
        if ( v9 <= 250.0 )
        {
          v17 = v5;
          v18 = CMemoryBSPFile::AddStaticPropLeaves(
                  this,
                  vOrigin,
                  nNodeIndex: m_pMemory[v5].children[0],
                  pStaticPropLeafLump);
          return v18
               + CMemoryBSPFile::AddStaticPropLeaves(
                   this,
                   vOrigin,
                   nNodeIndex: this->m_NodeList.m_Memory.m_pMemory[v17].children[1],
                   pStaticPropLeafLump);
        }
        v5 = m_pMemory[v7].children[0];
      }
      else
      {
        v5 = m_pMemory[v7].children[1];
      }
    }
    while ( v5 >= 0 );
  }
  m_Size = pStaticPropLeafLump->m_Size;
  m_nAllocationCount = pStaticPropLeafLump->m_Memory.m_nAllocationCount;
  v12 = -1 - v5;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<wchar_t,int>::Grow(
      this: (CUtlMemory<wchar_t,int> *)pStaticPropLeafLump,
      num: m_Size - m_nAllocationCount + 1);
  ++pStaticPropLeafLump->m_Size;
  v13 = pStaticPropLeafLump->m_Memory.m_pMemory;
  v14 = pStaticPropLeafLump->m_Size - m_Size - 1;
  pStaticPropLeafLump->m_pElements = pStaticPropLeafLump->m_Memory.m_pMemory;
  if ( v14 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v13[m_Size + 1], src: (unsigned __int8 *)&v13[m_Size], count: 2 * v14);
  v15 = &pStaticPropLeafLump->m_Memory.m_pMemory[m_Size];
  if ( v15 != nullptr )
    v15->m_Leaf = v12;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1006B630
// Name: private: void CMemoryBSPFile::BuildDisplacements(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMemoryBSPFile::BuildDisplacements(CMemoryBSPFile *this@<ecx>, float a2@<ebp>)
{
  void *v2; // esp
  CMemoryBSPFile *v3; // edi
  const CSimpleMapFile *m_pMapFile; // eax
  int m_Size; // esi
  int v6; // edx
  int *p_m_Size; // eax
  bool v8; // zf
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  unsigned __int8 *v14; // ecx
  int v15; // esi
  int v16; // eax
  unsigned __int8 *v17; // ecx
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  unsigned __int8 *v21; // edx
  int v22; // eax
  int v23; // ecx
  int v24; // eax
  unsigned __int8 *v25; // edx
  int v26; // eax
  const CSimpleMapFile *v27; // ecx
  CDispVert *v28; // edx
  ddispinfo_t *v29; // eax
  CMapDisplacement *v30; // esi
  CDispVert *v31; // ecx
  CDispTri *v32; // edx
  double y; // st7
  int v34; // ecx
  double z; // st7
  int v36; // edx
  int v37; // edx
  char *v38; // edx
  float *p_z; // edi
  float *v40; // eax
  float v41; // xmm1_4
  __int128 v42; // xmm0
  CDispVert *v43; // eax
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm3_4
  int v47; // ecx
  float *v48; // edx
  CMapDisplacement::Vertex_t *v49; // eax
  double v50; // st7
  float *v51; // eax
  double v52; // st7
  CMemoryBSPFile *v53; // eax
  CMapDisplacement::Vertex_t *v54; // edx
  double v55; // st7
  float *v56; // edx
  CCoreDispInfo *v57; // ecx
  CDispMultiBlend *v58; // eax
  float *v59; // eax
  double v60; // st7
  int v61; // edx
  CMapDisplacement::Vertex_t *v62; // eax
  double v63; // st7
  CMapDisplacement::Vertex_t *v64; // eax
  double v65; // st7
  int v66; // eax
  int v67; // edx
  int v68; // edx
  CMapDisplacement::Vertex_t *v69; // eax
  int v70; // edx
  CMapDisplacement::Vertex_t *v71; // eax
  double v72; // st7
  int v73; // eax
  int v74; // edx
  int v75; // edx
  CMapDisplacement::Vertex_t *v76; // eax
  int v77; // edx
  CMapDisplacement::Vertex_t *v78; // eax
  double v79; // st7
  int v80; // eax
  int v81; // edx
  int v82; // edx
  double v83; // st7
  CMapDisplacement::Vertex_t *v84; // eax
  int v85; // edx
  CMapDisplacement::Vertex_t *v86; // eax
  double v87; // st7
  int v88; // eax
  int v89; // edx
  int v90; // edx
  double v91; // st7
  int j; // eax
  CCoreDispInfo *v93; // eax
  CCoreDispInfo *v94; // eax
  int v95; // edx
  CCoreDispInfo *v96; // ecx
  int m_ContentsFlags; // eax
  CCoreDispInfo *v98; // edi
  char *v99; // ecx
  float *v100; // eax
  float *v101; // eax
  float *v102; // eax
  float *v103; // eax
  int m_nFlags; // edx
  CCoreDispInfo *v105; // esi
  int k; // edi
  CCoreDispInfo *v107; // ecx
  char *v108; // esi
  int v109; // eax
  int v110; // ecx
  CMemoryBSPFile *v111; // eax
  CCoreDispInfo *v112; // ecx
  char *v113; // esi
  int v114; // eax
  int v115; // ecx
  __int64 v116; // xmm0_8
  int v117; // eax
  int v118; // ecx
  CCoreDispInfo **v119; // [esp+10h] [ebp-7184h]
  int v120; // [esp+14h] [ebp-7180h]
  CDispMultiBlend v121[289]; // [esp+28h] [ebp-716Ch] BYREF
  Vector v122[289]; // [esp+5A78h] [ebp-171Ch] BYREF
  float v123[290]; // [esp+6808h] [ebp-98Ch] BYREF
  float v124[290]; // [esp+6C90h] [ebp-504h] BYREF
  __int128 v125; // [esp+7118h] [ebp-7Ch]
  ddispinfo_t *v126; // [esp+7134h] [ebp-60h]
  CDispTri *v127; // [esp+7138h] [ebp-5Ch]
  int v128; // [esp+713Ch] [ebp-58h]
  Vector v129; // [esp+7140h] [ebp-54h] BYREF
  float *v130; // [esp+714Ch] [ebp-48h]
  int v131; // [esp+7150h] [ebp-44h]
  int v132; // [esp+7154h] [ebp-40h]
  unsigned int v133; // [esp+7158h] [ebp-3Ch]
  int v134; // [esp+715Ch] [ebp-38h]
  unsigned int v135; // [esp+7160h] [ebp-34h]
  CCoreDispInfo *v136; // [esp+7164h] [ebp-30h]
  CDispVert *v137; // [esp+7168h] [ebp-2Ch]
  int i; // [esp+716Ch] [ebp-28h]
  int v139; // [esp+7170h] [ebp-24h]
  CMemoryBSPFile *v140; // [esp+7174h] [ebp-20h]
  int v141; // [esp+7178h] [ebp-1Ch]
  int v142; // [esp+717Ch] [ebp-18h]
  int p_m_DisplacementMultiBlendList; // [esp+7180h] [ebp-14h]
  int v144; // [esp+7184h] [ebp-10h]
  float smoothingAngle; // [esp+7188h] [ebp-Ch]
  int v146; // [esp+718Ch] [ebp-8h]
  int vars0; // [esp+7194h] [ebp+0h]

  smoothingAngle = a2;
  v146 = vars0;
  v2 = alloca(29032);
  v3 = this;
  m_pMapFile = this->m_pMapFile;
  m_Size = m_pMapFile->m_Displacements.m_Size;
  v6 = 0;
  v140 = this;
  v144 = 0;
  v142 = 0;
  p_m_DisplacementMultiBlendList = 0;
  if ( m_Size > 0 )
  {
    p_m_Size = &m_pMapFile->m_Displacements.m_Memory.m_pMemory->m_Vertices.m_Size;
    for ( i = m_Size; i != 0; --i )
    {
      v6 += *p_m_Size;
      v142 += p_m_Size[5];
      v8 = (*(p_m_Size - 8) & 0x40000000) == 0;
      v144 = v6;
      if ( !v8 )
      {
        p_m_DisplacementMultiBlendList += *p_m_Size;
        v6 = v144;
      }
      p_m_Size += 17;
    }
  }
  this->m_DisplacementList.m_Size = 0;
  if ( m_Size != 0 )
  {
    m_nAllocationCount = this->m_DisplacementList.m_Memory.m_nAllocationCount;
    if ( m_Size > m_nAllocationCount )
    {
      CUtlMemory<MapBrushTexture_t,int>::Grow(
        this: (CUtlMemory<MapBrushTexture_t,int> *)&this->m_DisplacementList,
        num: m_Size - m_nAllocationCount);
      v6 = v144;
    }
    v3->m_DisplacementList.m_Size += m_Size;
    m_pMemory = (unsigned __int8 *)v3->m_DisplacementList.m_Memory.m_pMemory;
    v11 = v3->m_DisplacementList.m_Size - m_Size;
    v3->m_DisplacementList.m_pElements = (ddispinfo_t *)m_pMemory;
    if ( v11 > 0 && m_Size > 0 )
    {
      _V_memmove(dest: &m_pMemory[176 * m_Size], src: m_pMemory, count: 176 * v11);
      v6 = v144;
    }
  }
  v139 = v3->m_pMapFile->m_Displacements.m_Size;
  v12 = v139;
  v3->m_DisplacementHelperList.m_Size = 0;
  if ( v12 != 0 )
  {
    v13 = v3->m_DisplacementHelperList.m_Memory.m_nAllocationCount;
    if ( v12 > v13 )
    {
      CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&v3->m_DisplacementHelperList,
        num: v12 - v13);
      v6 = v144;
      v12 = v139;
    }
    v3->m_DisplacementHelperList.m_Size += v12;
    v14 = (unsigned __int8 *)v3->m_DisplacementHelperList.m_Memory.m_pMemory;
    v15 = v3->m_DisplacementHelperList.m_Size - v12;
    v3->m_DisplacementHelperList.m_pElements = (CCoreDispInfo **)v14;
    if ( v15 > 0 && v12 > 0 )
    {
      _V_memmove(dest: &v14[4 * v12], src: v14, count: 4 * v15);
      v6 = v144;
    }
  }
  v3->m_DisplacementVertexList.m_Size = 0;
  if ( v6 != 0 )
  {
    v16 = v3->m_DisplacementVertexList.m_Memory.m_nAllocationCount;
    if ( v6 > v16 )
    {
      CUtlMemory<CRoomCandidate,int>::Grow(
        this: (CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> *)&v3->m_DisplacementVertexList,
        num: v6 - v16);
      v6 = v144;
    }
    v3->m_DisplacementVertexList.m_Size += v6;
    v17 = (unsigned __int8 *)v3->m_DisplacementVertexList.m_Memory.m_pMemory;
    v18 = v3->m_DisplacementVertexList.m_Size - v6;
    v3->m_DisplacementVertexList.m_pElements = (CDispVert *)v17;
    if ( v18 > 0 && v6 > 0 )
      _V_memmove(dest: &v17[20 * v6], src: v17, count: 20 * v18);
  }
  v19 = v142;
  v3->m_DisplacementTriangleList.m_Size = 0;
  if ( v19 != 0 )
  {
    v20 = v3->m_DisplacementTriangleList.m_Memory.m_nAllocationCount;
    if ( v19 > v20 )
    {
      CUtlMemory<wchar_t,int>::Grow(this: (CUtlMemory<wchar_t,int> *)&v3->m_DisplacementTriangleList, num: v19 - v20);
      v19 = v142;
    }
    v3->m_DisplacementTriangleList.m_Size += v19;
    v21 = (unsigned __int8 *)v3->m_DisplacementTriangleList.m_Memory.m_pMemory;
    v22 = v3->m_DisplacementTriangleList.m_Size - v19;
    v3->m_DisplacementTriangleList.m_pElements = (CDispTri *)v21;
    if ( v22 > 0 && v19 > 0 )
      _V_memmove(dest: &v21[2 * v19], src: v21, count: 2 * v22);
  }
  v23 = p_m_DisplacementMultiBlendList;
  v3->m_DisplacementMultiBlendList.m_Size = 0;
  if ( v23 != 0 )
  {
    v24 = v3->m_DisplacementMultiBlendList.m_Memory.m_nAllocationCount;
    if ( v23 > v24 )
    {
      CUtlMemory<CDispMultiBlend,int>::Grow(this: &v3->m_DisplacementMultiBlendList.m_Memory, num: v23 - v24);
      v23 = p_m_DisplacementMultiBlendList;
    }
    v3->m_DisplacementMultiBlendList.m_Size += v23;
    v25 = (unsigned __int8 *)v3->m_DisplacementMultiBlendList.m_Memory.m_pMemory;
    v26 = v3->m_DisplacementMultiBlendList.m_Size - v23;
    v3->m_DisplacementMultiBlendList.m_pElements = (CDispMultiBlend *)v25;
    if ( v26 > 0 && v23 > 0 )
      _V_memmove(dest: &v25[80 * v23], src: v25, count: 80 * v26);
  }
  v27 = v3->m_pMapFile;
  v134 = 0;
  v128 = 0;
  v132 = 0;
  v131 = 0;
  if ( v27->m_Displacements.m_Size > 0 )
  {
    i = 0;
    v135 = 0;
    v133 = 0;
    do
    {
      v28 = v3->m_DisplacementVertexList.m_Memory.m_pMemory;
      v29 = &v3->m_DisplacementList.m_Memory.m_pMemory[v133 / 0xB0];
      v30 = &v27->m_Displacements.m_Memory.m_pMemory[v135 / 0x44];
      v139 = (int)v3->m_pSimpleBSPFile->m_DisplacementFaces.m_Memory.m_pMemory + i;
      v31 = &v28[v134];
      v32 = v3->m_DisplacementTriangleList.m_Memory.m_pMemory;
      v29->startPosition.x = v30->m_vStartPosition.x;
      y = v30->m_vStartPosition.y;
      v137 = v31;
      v34 = v128;
      v29->startPosition.y = y;
      z = v30->m_vStartPosition.z;
      v127 = &v32[v34];
      v29->startPosition.z = z;
      v36 = v134;
      v29->m_iDispVertStart = v134;
      v29->m_iDispTriStart = v34;
      v37 = v30->m_Vertices.m_Size + v36;
      v128 = v30->m_TriangleTags.m_Size + v34;
      v29->power = v30->m_nPower;
      v134 = v37;
      v29->minTess = v30->m_nFlags | 0x80000000;
      v38 = (char *)v139;
      v29->smoothingAngle = 0.0;
      v29->contents = v30->m_ContentsFlags;
      v29->m_iMapFace = *((_WORD *)v38 + 18);
      v29->m_iLightmapAlphaStart = 0;
      v29->m_iLightmapSamplePositionStart = 0;
      v126 = v29;
      v142 = 0;
      if ( v30->m_Vertices.m_Size > 0 )
      {
        v136 = (CCoreDispInfo *)(80 * v132);
        v141 = 0;
        v144 = 60;
        p_z = &v121[0].m_vMultiBlend.z;
        v130 = &v122[0].z;
        v137 = (CDispVert *)((char *)v137 + 8);
        do
        {
          v40 = (float *)((char *)&v30->m_Vertices.m_Memory.m_pMemory->m_flAlpha + v141);
          v41 = v40[1];
          v129.x = v40[2] * v41;
          v129.y = v40[3] * v41;
          v129.z = v40[4] * v41;
          v129.x = v129.x + v40[5];
          v129.y = v40[6] + v129.y;
          v129.z = v40[7] + v129.z;
          v42 = 0;
          *(float *)&v42 = fsqrt((float)((float)(v129.z * v129.z) + (float)(v129.y * v129.y)) + (float)(v129.x * v129.x));
          v125 = v42;
          VectorNormalize(vec: &v129);
          v43 = v137;
          *(float *)&v42 = v129.x;
          v44 = v129.y;
          v45 = v129.z;
          v46 = *(float *)&v125;
          v47 = v141;
          *(Vector *)&v137[-1].m_flDist = v129;
          v43->m_vVector.y = v46;
          v48 = v130;
          v43->m_vVector.z = *(float *)((char *)&v30->m_Vertices.m_Memory.m_pMemory->m_flAlpha + v47);
          *((_DWORD *)v48 - 2) = v42;
          *(v48 - 1) = v44;
          *v48 = v45;
          v124[v142] = v46;
          v123[v142] = *(float *)((char *)&v30->m_Vertices.m_Memory.m_pMemory->m_flAlpha + v47);
          if ( (v30->m_nFlags & 0x40000000) != 0 )
          {
            v49 = v30->m_Vertices.m_Memory.m_pMemory;
            v50 = *(float *)((char *)&v49->m_vMultiBlend.x + v47);
            v51 = (float *)((char *)&v49->m_vMultiBlend.x + v47);
            *(p_z - 2) = v50;
            *(p_z - 1) = v51[1];
            *p_z = v51[2];
            v52 = v51[3];
            v53 = v140;
            p_z[1] = v52;
            v54 = v30->m_Vertices.m_Memory.m_pMemory;
            v55 = *(float *)((char *)&v54->m_vMultiBlend.x + v47);
            v56 = (float *)((char *)&v54->m_vMultiBlend.x + v47);
            v57 = v136;
            p_m_DisplacementMultiBlendList = (int)&v53->m_DisplacementMultiBlendList;
            v58 = v53->m_DisplacementMultiBlendList.m_Memory.m_pMemory;
            *(float *)((char *)&v136->__vftable + (_DWORD)v58) = v55;
            v59 = (float *)((int)&v58->m_vMultiBlend.x + (_DWORD)v57);
            v59[1] = v56[1];
            v59[2] = v56[2];
            v60 = v56[3];
            v61 = v144;
            v59[3] = v60;
            v62 = v30->m_Vertices.m_Memory.m_pMemory;
            v63 = *(float *)((char *)v62 + v61 - 12);
            v61 -= 12;
            p_z[6] = v63;
            p_z[7] = *(float *)((char *)&v62->m_flDistance + v61);
            p_z[8] = *(float *)((char *)&v62->m_vNormal.x + v61);
            v64 = v30->m_Vertices.m_Memory.m_pMemory;
            v65 = *(float *)((char *)&v64->m_flAlpha + v61);
            v66 = (int)v64 + v61;
            v67 = *(_DWORD *)p_m_DisplacementMultiBlendList;
            *(float *)((char *)&v57->m_Surf.m_Points[0].z + v67) = v65;
            v68 = (int)&v57->m_Surf.m_Points[0].z + v67;
            *(float *)(v68 + 4) = *(float *)(v66 + 4);
            *(float *)(v68 + 8) = *(float *)(v66 + 8);
            v69 = v30->m_Vertices.m_Memory.m_pMemory;
            v70 = v144;
            p_z[9] = *(float *)((char *)&v69->m_flAlpha + v144);
            p_z[10] = *(float *)((char *)&v69->m_flDistance + v70);
            p_z[11] = *(float *)((char *)&v69->m_vNormal.x + v70);
            v71 = v30->m_Vertices.m_Memory.m_pMemory;
            v72 = *(float *)((char *)&v71->m_flAlpha + v70);
            v73 = (int)v71 + v70;
            v74 = *(_DWORD *)p_m_DisplacementMultiBlendList;
            *(float *)((char *)&v57->m_Surf.m_Points[1].z + v74) = v72;
            v75 = (int)&v57->m_Surf.m_Points[1].z + v74;
            *(float *)(v75 + 4) = *(float *)(v73 + 4);
            *(float *)(v75 + 8) = *(float *)(v73 + 8);
            v76 = v30->m_Vertices.m_Memory.m_pMemory;
            v77 = v144 + 12;
            p_z[12] = *(float *)((char *)&v76->m_vNormal.y + v144);
            p_z[13] = *(float *)((char *)&v76->m_flDistance + v77);
            p_z[14] = *(float *)((char *)&v76->m_vNormal.x + v77);
            v78 = v30->m_Vertices.m_Memory.m_pMemory;
            v79 = *(float *)((char *)&v78->m_flAlpha + v77);
            v80 = (int)v78 + v77;
            v81 = *(_DWORD *)p_m_DisplacementMultiBlendList;
            *(float *)((char *)&v57->m_Surf.m_Points[2].z + v81) = v79;
            v82 = (int)&v57->m_Surf.m_Points[2].z + v81;
            v83 = *(float *)(v80 + 4);
            ++v132;
            *(float *)(v82 + 4) = v83;
            *(float *)(v82 + 8) = *(float *)(v80 + 8);
            v84 = v30->m_Vertices.m_Memory.m_pMemory;
            v85 = v144 + 24;
            p_z[15] = *(float *)((char *)&v84->m_vOffset.y + v144);
            p_z[16] = *(float *)((char *)&v84->m_flDistance + v85);
            p_z[17] = *(float *)((char *)&v84->m_vNormal.x + v85);
            v86 = v30->m_Vertices.m_Memory.m_pMemory;
            v87 = *(float *)((char *)&v86->m_flAlpha + v85);
            v88 = (int)v86 + v85;
            v89 = *(_DWORD *)p_m_DisplacementMultiBlendList;
            *(float *)((char *)&v57->m_Surf.m_Points[3].z + v89) = v87;
            v90 = (int)&v57->m_Surf.m_Points[3].z + v89;
            *(float *)(v90 + 4) = *(float *)(v88 + 4);
            v91 = *(float *)(v88 + 8);
            v43 = v137;
            v136 = (CCoreDispInfo *)&v57->m_Surf.m_Normals[0].z;
            *(float *)(v90 + 8) = v91;
            v47 = v141;
          }
          v130 += 3;
          v144 += 96;
          p_z += 20;
          ++v142;
          v137 = v43 + 1;
          v141 = v47 + 96;
        }
        while ( v142 < v30->m_Vertices.m_Size );
        v3 = v140;
      }
      for ( j = 0; j < v30->m_TriangleTags.m_Size; ++j )
        v127[j] = (CDispTri)v30->m_TriangleTags.m_Memory.m_pMemory[j];
      v93 = (CCoreDispInfo *)operator new(nSize: 0x34Cu);
      if ( v93 != nullptr )
        v94 = CCoreDispInfo::CCoreDispInfo(this: v93);
      else
        v94 = nullptr;
      v95 = v131;
      v3->m_DisplacementHelperList.m_Memory.m_pMemory[v131] = v94;
      v96 = v3->m_DisplacementHelperList.m_Memory.m_pMemory[v95];
      v96->m_nListIndex = v95;
      v120 = v3->m_DisplacementHelperList.m_Size;
      v119 = v3->m_DisplacementHelperList.m_Memory.m_pMemory;
      v136 = v96;
      CCoreDispInfo::SetDispUtilsHelperInfo(this: v96, ppListBase: v119, listSize: v120);
      m_ContentsFlags = v30->m_ContentsFlags;
      v98 = v136;
      if ( (m_ContentsFlags & 0x300FF) == 0 )
        m_ContentsFlags |= 1u;
      v136->m_Surf.m_Contents = m_ContentsFlags;
      v98->m_Surf.m_PointCount = 4;
      v99 = (char *)v139;
      v100 = *(float **)(v139 + 12);
      v98->m_Surf.m_Points[0].x = *v100;
      v98->m_Surf.m_Points[0].y = v100[1];
      v98->m_Surf.m_Points[0].z = v100[2];
      v98->m_Surf.m_TexCoords[0].x = 0.0;
      v98->m_Surf.m_TexCoords[0].y = 0.0;
      v101 = *((float **)v99 + 3);
      v98->m_Surf.m_Points[1].x = v101[3];
      v98->m_Surf.m_Points[1].y = v101[4];
      v98->m_Surf.m_Points[1].z = v101[5];
      v98->m_Surf.m_TexCoords[1].x = 0.0;
      v98->m_Surf.m_TexCoords[1].y = 1.0;
      v102 = *((float **)v99 + 3);
      v98->m_Surf.m_Points[2].x = v102[6];
      v98->m_Surf.m_Points[2].y = v102[7];
      v98->m_Surf.m_Points[2].z = v102[8];
      v98->m_Surf.m_TexCoords[2].x = 1.0;
      v98->m_Surf.m_TexCoords[2].y = 0.0;
      v103 = *((float **)v99 + 3);
      v98->m_Surf.m_Points[3].x = v103[9];
      v98->m_Surf.m_Points[3].y = v103[10];
      v98->m_Surf.m_Points[3].z = v103[11];
      v98->m_Surf.m_TexCoords[3].x = 1.0;
      v98->m_Surf.m_TexCoords[3].y = 1.0;
      v98->m_Surf.m_PointStart.x = v30->m_vStartPosition.x;
      v98->m_Surf.m_PointStart.y = v30->m_vStartPosition.y;
      v98->m_Surf.m_PointStart.z = v30->m_vStartPosition.z;
      CCoreDispSurface::FindSurfPointStartIndex(this: &v98->m_Surf);
      CCoreDispSurface::AdjustSurfPointData(this: &v98->m_Surf);
      v98->m_Surf.m_nLuxelU = 0;
      v98->m_Surf.m_nLuxelV = 0;
      m_nFlags = v30->m_nFlags;
      v105 = v136;
      CCoreDispInfo::InitDispInfo(
        this: v136,
        power: v126->power,
        minTess: v126->minTess,
        smoothingAngle: v126->smoothingAngle,
        alphas: v123,
        dispVectorField: v122,
        dispDistances: v124,
        nFlags: m_nFlags,
        pvMultiBlends: v121);
      CCoreDispInfo::Create(this: v105);
      v133 += 176;
      ++v131;
      v27 = v140->m_pMapFile;
      v135 += 68;
      i += 40;
      v3 = v140;
    }
    while ( v131 < v27->m_Displacements.m_Size );
  }
  FindNeighboringDispSurfs(
    ppListBase: v3->m_DisplacementHelperList.m_Memory.m_pMemory,
    nListSize: v3->m_DisplacementHelperList.m_Size);
  p_m_DisplacementMultiBlendList = 0;
  if ( v3->m_DisplacementHelperList.m_Size > 0 )
  {
    v142 = 0;
    do
    {
      v141 = 0;
      v139 = 0;
      for ( k = 48; k < 96; k += 12 )
      {
        v107 = v140->m_DisplacementHelperList.m_Memory.m_pMemory[p_m_DisplacementMultiBlendList];
        v108 = (char *)v140->m_DisplacementList.m_Memory.m_pMemory + v142;
        v109 = (int)v107->GetEdgeNeighbor(this: v107, a2: v141);
        *(_QWORD *)&v108[k] = *(_QWORD *)v109;
        v110 = *(_DWORD *)(v109 + 8);
        v111 = v140;
        *(_DWORD *)&v108[k + 8] = v110;
        v112 = v111->m_DisplacementHelperList.m_Memory.m_pMemory[p_m_DisplacementMultiBlendList];
        v113 = (char *)v111->m_DisplacementList.m_Memory.m_pMemory + v142;
        v114 = (int)v112->GetCornerNeighbors(this: v112, a2: v141);
        v115 = v139;
        v116 = *(_QWORD *)v114;
        ++v141;
        *(_QWORD *)&v113[v139 + 96] = v116;
        *(_WORD *)&v113[v115 + 104] = *(_WORD *)(v114 + 8);
        v139 = v115 + 10;
      }
      v142 += 176;
      ++p_m_DisplacementMultiBlendList;
    }
    while ( p_m_DisplacementMultiBlendList < v140->m_DisplacementHelperList.m_Size );
    v3 = v140;
  }
  SetupAllowedVerts(
    ppListBase: v3->m_DisplacementHelperList.m_Memory.m_pMemory,
    nListSize: v3->m_DisplacementHelperList.m_Size);
  v117 = 0;
  if ( v3->m_DisplacementHelperList.m_Size > 0 )
  {
    v118 = 140;
    do
    {
      *(_DWORD *)((char *)v3->m_DisplacementList.m_Memory.m_pMemory + v118 - 4) = v3->m_DisplacementHelperList.m_Memory.m_pMemory[v117]->m_AllowedVerts.m_Ints[0];
      *(_DWORD *)((char *)&v3->m_DisplacementList.m_Memory.m_pMemory->startPosition.x + v118) = v3->m_DisplacementHelperList.m_Memory.m_pMemory[v117]->m_AllowedVerts.m_Ints[1];
      *(_DWORD *)((char *)&v3->m_DisplacementList.m_Memory.m_pMemory->startPosition.y + v118) = v3->m_DisplacementHelperList.m_Memory.m_pMemory[v117]->m_AllowedVerts.m_Ints[2];
      *(_DWORD *)((char *)&v3->m_DisplacementList.m_Memory.m_pMemory->startPosition.z + v118) = v3->m_DisplacementHelperList.m_Memory.m_pMemory[v117]->m_AllowedVerts.m_Ints[3];
      *(int *)((char *)&v3->m_DisplacementList.m_Memory.m_pMemory->m_iDispVertStart + v118) = v3->m_DisplacementHelperList.m_Memory.m_pMemory[v117]->m_AllowedVerts.m_Ints[4];
      *(int *)((char *)&v3->m_DisplacementList.m_Memory.m_pMemory->m_iDispTriStart + v118) = v3->m_DisplacementHelperList.m_Memory.m_pMemory[v117]->m_AllowedVerts.m_Ints[5];
      *(int *)((char *)&v3->m_DisplacementList.m_Memory.m_pMemory->power + v118) = v3->m_DisplacementHelperList.m_Memory.m_pMemory[v117]->m_AllowedVerts.m_Ints[6];
      *(int *)((char *)&v3->m_DisplacementList.m_Memory.m_pMemory->minTess + v118) = v3->m_DisplacementHelperList.m_Memory.m_pMemory[v117]->m_AllowedVerts.m_Ints[7];
      *(_DWORD *)((char *)&v3->m_DisplacementList.m_Memory.m_pMemory->smoothingAngle + v118) = v3->m_DisplacementHelperList.m_Memory.m_pMemory[v117]->m_AllowedVerts.m_Ints[8];
      *(int *)((char *)&v3->m_DisplacementList.m_Memory.m_pMemory->contents + v118) = v3->m_DisplacementHelperList.m_Memory.m_pMemory[v117++]->m_AllowedVerts.m_Ints[9];
      v118 += 176;
    }
    while ( v117 < v3->m_DisplacementHelperList.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006C020
// Name: private: class CPhysCollisionEntry __near * CMemoryBSPFile::CreatePhysicsModel(class IPhysicsCollision __near *,class IPhysicsSurfaceProps __near *,int const __near *,struct dmodel_t const __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
CPhysCollisionEntrySolid *__userpurge CMemoryBSPFile::CreatePhysicsModel@<eax>(
        CMemoryBSPFile *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        IPhysicsCollision *pPhysicsCollision,
        IPhysicsSurfaceProps *pPhysicsProperties,
        const int *pSurfacePropertyList,
        const dmodel_t *pModel)
{
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  bool v14; // cc
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  float v18; // eax
  int v20; // ecx
  MapTextureInfo_t *m_pMemory; // ebx
  dface_t *v22; // edx
  int numfaces; // edi
  int v24; // esi
  int v25; // eax
  double area; // st7
  float v27; // xmm0_4
  int v28; // esi
  int v29; // eax
  float v30; // xmm2_4
  int v31; // edx
  float v32; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm1_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm1_4
  float v40; // xmm1_4
  int v41; // edi
  const char *v42; // ebx
  int nProperty; // xmm0_4
  CPhysCollisionEntrySolid *v44; // esi
  CPhysCollisionEntrySolid *v45; // esi
  float flArea; // eax
  float v49; // [esp+18h] [ebp-C44h]
  int v50; // [esp+1Ch] [ebp-C40h]
  _DWORD v51[2]; // [esp+20h] [ebp-C3Ch]
  _DWORD v52[5]; // [esp+28h] [ebp-C34h]
  CMemoryBSPFile::CreatePhysicsModel::__l10::<unnamed_type_propertyList> propertyList[256]; // [esp+58h] [ebp-C04h] BYREF
  _BYTE physConvexBuilder_1004[24]; // [esp+C44h] [ebp-18h] OVERLAPPED BYREF
  float physConvexBuilder_1044; // [esp+C6Ch] [ebp+10h]
  float physConvexBuilder_1044a; // [esp+C6Ch] [ebp+10h]
  struct CPhysCollide *physConvexBuilder_1048; // [esp+C70h] [ebp+14h]

  CPhysConvexBuilder::CPhysConvexBuilder(
    this: (CPhysConvexBuilder *)&propertyList[248].flArea,
    flShrink: 0.5,
    contentsMask: 33767483,
    pMapFile: this->m_pMapFile,
    pPhysicsCollision);
  CPhysConvexBuilder::BuildConvexes(
    this: (CPhysConvexBuilder *)&propertyList[248].flArea,
    nNodeIndex: pModel->headnode,
    nodeList: &this->m_NodeList,
    leafList: &this->m_LeafList,
    leafBrushList: &this->m_LeafBrushList);
  v10 = pModel->maxs.y - pModel->mins.y;
  v11 = pModel->maxs.z - pModel->mins.z;
  v12 = pModel->maxs.x - pModel->mins.x;
  v13 = v10 * v11;
  v14 = (float)(v10 * v11) >= 0.0;
  *(_DWORD *)&physConvexBuilder_1004[6] = 0;
  *(_DWORD *)&physConvexBuilder_1004[16] = 0;
  physConvexBuilder_1004[4] = propertyList[250].nProperty > 1;
  physConvexBuilder_1004[5] = 1;
  v15 = v11 * v12;
  if ( !v14 || v13 > v15 )
    v13 = v15;
  v16 = v10 * v12;
  if ( v13 < 0.0 || v13 > v16 )
    v13 = v16;
  v17 = v13 * 0.0099999998;
  if ( v17 >= 1.0 )
  {
    if ( v17 <= 1024.0 )
      *(float *)&physConvexBuilder_1004[12] = v17;
    else
      *(_DWORD *)&physConvexBuilder_1004[12] = 1149239296;
  }
  else
  {
    *(_DWORD *)&physConvexBuilder_1004[12] = 1065353216;
  }
  physConvexBuilder_1048 = (struct CPhysCollide *)((int (__thiscall *)(IPhysicsCollision *, _DWORD, int, _BYTE *, int, int, int))pPhysicsCollision->ConvertConvexToCollideParams)(
                                                    a1: pPhysicsCollision,
                                                    a2: LODWORD(propertyList[248].flArea),
                                                    a3: propertyList[250].nProperty,
                                                    a4: &physConvexBuilder_1004[4],
                                                    a5: a3,
                                                    a6: a4,
                                                    a7: a2);
  if ( physConvexBuilder_1048 != nullptr )
  {
    v50 = 0;
    v51[0] = 1065353216;
    v20 = 1;
    if ( pModel->numfaces == 0 )
    {
      v51[1] = pSurfacePropertyList[this->m_pMapFile->m_TextureInfos.m_Memory.m_pMemory[this->m_pMapFile->m_BrushSides.m_Memory.m_pMemory[this->m_pMapFile->m_Brushes.m_Memory.m_pMemory[CPhysConvexBuilder::FindFirstReferencedBrush(this: (CPhysConvexBuilder *)&propertyList[248].flArea)].m_nFirstSideIndex].m_nTextureInfoIndex].m_nTextureDataIndex];
      v52[0] = 0x40000000;
      v20 = 2;
    }
    if ( pModel->numfaces > 0 )
    {
      m_pMemory = this->m_pMapFile->m_TextureInfos.m_Memory.m_pMemory;
      v22 = &this->m_FaceList.m_Memory.m_pMemory[pModel->firstface];
      numfaces = pModel->numfaces;
      do
      {
        v24 = pSurfacePropertyList[m_pMemory[v22->texinfo].m_nTextureDataIndex];
        v25 = 0;
        if ( v20 > 0 )
        {
          while ( v51[2 * v25 - 1] != v24 )
          {
            if ( ++v25 >= v20 )
              goto LABEL_30;
          }
          *(float *)&v51[2 * v25] = v22->area + *(float *)&v51[2 * v25];
        }
LABEL_30:
        if ( v25 == v20 && v20 < 256 )
        {
          area = v22->area;
          v51[2 * v20 - 1] = v24;
          *(float *)&v51[2 * v20++] = area;
        }
        ++v22;
        --numfaces;
      }
      while ( numfaces != 0 );
    }
    v27 = 0.0;
    v28 = 0;
    v29 = 0;
    v30 = 0.0;
    physConvexBuilder_1044 = 0.0;
    if ( v20 >= 4 )
    {
      v31 = 2;
      do
      {
        v32 = *(float *)&v51[2 * v29];
        if ( v32 > v27 )
        {
          v27 = *(float *)&v51[2 * v29];
          v28 = v29;
        }
        v33 = v30 + v32;
        v34 = *(float *)&v52[2 * v29];
        if ( v34 > v27 )
        {
          v27 = *(float *)&v52[2 * v29];
          v28 = v31 - 1;
        }
        v35 = v33 + v34;
        v36 = *(float *)&v52[2 * v29 + 2];
        if ( v36 > v27 )
        {
          v27 = *(float *)&v52[2 * v29 + 2];
          v28 = v31;
        }
        v37 = v36 + v35;
        v38 = *(float *)&v52[2 * v29 + 4];
        if ( v38 > v27 )
        {
          v27 = *(float *)&v52[2 * v29 + 4];
          v28 = v31 + 1;
        }
        v29 += 4;
        v31 += 4;
        v30 = v38 + v37;
      }
      while ( v29 < v20 - 3 );
      physConvexBuilder_1044 = v30;
    }
    if ( v29 < v20 )
    {
      do
      {
        v39 = *(float *)&v51[2 * v29];
        if ( v39 > v27 )
        {
          v27 = *(float *)&v51[2 * v29];
          v28 = v29;
        }
        ++v29;
        v40 = v39 + v30;
        v30 = v40;
      }
      while ( v29 < v20 );
      physConvexBuilder_1044 = v40;
    }
    v41 = v51[2 * v28 - 1];
    v42 = pPhysicsProperties->GetPropName(this: pPhysicsProperties, a2: v41);
    pPhysicsProperties->GetPhysicsProperties(
      this: pPhysicsProperties,
      a2: v41,
      a3: (float *)&physConvexBuilder_1004[20],
      a4: (float *)physConvexBuilder_1004,
      a5: nullptr,
      a6: nullptr);
    if ( *(float *)physConvexBuilder_1004 == 0.0 )
      nProperty = propertyList[252].nProperty;
    else
      *(float *)&nProperty = *(float *)physConvexBuilder_1004 * physConvexBuilder_1044;
    physConvexBuilder_1044a = (float)(*(float *)&nProperty * *(float *)&physConvexBuilder_1004[20]) * 0.000016387063;
    if ( physConvexBuilder_1044a > 50000.0 )
      physConvexBuilder_1044a = 50000.0;
    v44 = (CPhysCollisionEntrySolid *)operator new(nSize: 0x14u);
    if ( v44 != nullptr )
    {
      v49 = pPhysicsCollision->CollideVolume(this: pPhysicsCollision, a2: physConvexBuilder_1048);
      v45 = CPhysCollisionEntrySolid::CPhysCollisionEntrySolid(
              this: v44,
              pCollide: physConvexBuilder_1048,
              pMaterialName: v42,
              flMass: physConvexBuilder_1044a,
              flVolume: v49);
    }
    else
    {
      v45 = nullptr;
    }
    flArea = propertyList[248].flArea;
    propertyList[250].nProperty = 0;
    if ( propertyList[249].flArea >= 0.0 )
    {
      if ( LODWORD(propertyList[248].flArea) != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(propertyList[248].flArea));
        flArea = 0.0;
        propertyList[248].flArea = 0.0;
      }
      propertyList[249].nProperty = 0;
    }
    propertyList[250].flArea = flArea;
    if ( propertyList[249].flArea >= 0.0 && flArea != 0.0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(flArea));
    return v45;
  }
  else
  {
    v18 = propertyList[248].flArea;
    propertyList[250].nProperty = 0;
    if ( propertyList[249].flArea >= 0.0 )
    {
      if ( LODWORD(propertyList[248].flArea) != 0 )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(propertyList[248].flArea));
        v18 = 0.0;
        propertyList[248].flArea = 0.0;
      }
      propertyList[249].nProperty = 0;
    }
    propertyList[250].flArea = v18;
    if ( propertyList[249].flArea >= 0.0 && v18 != 0.0 )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)LODWORD(v18));
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006C470
// Name: void TesselateDisplacementNode<class CSimpleBSPTessellateHelper>(class CSimpleBSPTessellateHelper __near *,class CVertIndex const __near &,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TesselateDisplacementNode<CSimpleBSPTessellateHelper>(
        CSimpleBSPTessellateHelper *pHelper,
        const CVertIndex *nodeIndex,
        char iLevel,
        int *pActiveChildren)
{
  int v5; // eax
  __int16 v6; // dx
  __int16 v7; // di
  int m_iNode; // ecx
  CUtlMemory<wchar_t,int> *m_pIndices; // edi
  wchar_t *m_pMemory; // ebx
  int m_nAllocationCount; // eax
  wchar_t *v12; // ecx
  int v13; // eax
  wchar_t *v14; // ebx
  CUtlMemory<wchar_t,int> *v15; // edi
  wchar_t *v16; // ebx
  int v17; // eax
  wchar_t *v18; // ecx
  int v19; // eax
  wchar_t *v20; // eax
  CUtlMemory<wchar_t,int> *v21; // edi
  wchar_t *v22; // ebx
  int v23; // eax
  wchar_t *v24; // ecx
  int v25; // eax
  wchar_t *v26; // eax
  int iVert; // [esp+Ch] [ebp-8h]
  int vertInc; // [esp+10h] [ebp-4h]
  int iCurTriVert; // [esp+1Ch] [ebp+8h]
  int iLevela; // [esp+24h] [ebp+10h]

  vertInc = 1 << (pHelper->m_pPowerInfo->m_Power - iLevel - 1);
  v5 = 0;
  iCurTriVert = 0;
  iVert = 0;
  if ( g_TWinding.m_nVerts > 0 )
  {
    iLevela = 0;
    do
    {
      v6 = nodeIndex->x + vertInc * g_TWinding.m_Verts[iLevela].m_Index.x;
      v7 = nodeIndex->y + vertInc * g_TWinding.m_Verts[iLevela].m_Index.y;
      m_iNode = g_TWinding.m_Verts[iLevela].m_iNode;
      if ( m_iNode == -1 || pActiveChildren[m_iNode] == 0 )
      {
        if ( ((1 << ((v6 + LOBYTE(pHelper->m_pPowerInfo->m_SideLength) * v7) & 0x1F))
            & pHelper->m_pActiveVerts[(v6 + pHelper->m_pPowerInfo->m_SideLength * v7) >> 5]) != 0 )
        {
          pHelper->m_TempIndices[iCurTriVert] = v6 + v7 * LOWORD(pHelper->m_pPowerInfo->m_SideLength);
          v5 = iCurTriVert + 1;
          iCurTriVert = v5;
          if ( v5 == 2 )
          {
            pHelper->m_TempIndices[2] = nodeIndex->x + nodeIndex->y * LOWORD(pHelper->m_pPowerInfo->m_SideLength);
            CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertBefore(
              this: pHelper->m_pIndices,
              elem: pHelper->m_pIndices->m_Size,
              src: pHelper->m_TempIndices);
            CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertBefore(
              this: pHelper->m_pIndices,
              elem: pHelper->m_pIndices->m_Size,
              src: &pHelper->m_TempIndices[1]);
            CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertBefore(
              this: pHelper->m_pIndices,
              elem: pHelper->m_pIndices->m_Size,
              src: &pHelper->m_TempIndices[2]);
            pHelper->m_TempIndices[0] = pHelper->m_TempIndices[1];
            v5 = 1;
            iCurTriVert = 1;
          }
        }
        else
        {
          v5 = iCurTriVert;
        }
      }
      else
      {
        if ( v5 == 2 )
        {
          m_pIndices = (CUtlMemory<wchar_t,int> *)pHelper->m_pIndices;
          pHelper->m_TempIndices[2] = nodeIndex->x + nodeIndex->y * LOWORD(pHelper->m_pPowerInfo->m_SideLength);
          m_pMemory = m_pIndices[1].m_pMemory;
          m_nAllocationCount = m_pIndices->m_nAllocationCount;
          if ( (int)m_pMemory + 1 > m_nAllocationCount )
            CUtlMemory<wchar_t,int>::Grow(this: m_pIndices, num: (int)m_pMemory - m_nAllocationCount + 1);
          ++m_pIndices[1].m_pMemory;
          v12 = m_pIndices->m_pMemory;
          v13 = (char *)m_pIndices[1].m_pMemory - (char *)m_pMemory - 1;
          m_pIndices[1].m_nAllocationCount = (int)m_pIndices->m_pMemory;
          if ( v13 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&v12[(_DWORD)m_pMemory + 1],
              src: (unsigned __int8 *)&v12[(_DWORD)m_pMemory],
              count: 2 * v13);
          v14 = &m_pIndices->m_pMemory[(_DWORD)m_pMemory];
          if ( v14 != nullptr )
            *v14 = pHelper->m_TempIndices[0];
          v15 = (CUtlMemory<wchar_t,int> *)pHelper->m_pIndices;
          v16 = v15[1].m_pMemory;
          v17 = v15->m_nAllocationCount;
          if ( (int)v16 + 1 > v17 )
            CUtlMemory<wchar_t,int>::Grow(this: v15, num: (int)v16 - v17 + 1);
          ++v15[1].m_pMemory;
          v18 = v15->m_pMemory;
          v19 = (char *)v15[1].m_pMemory - (char *)v16 - 1;
          v15[1].m_nAllocationCount = (int)v15->m_pMemory;
          if ( v19 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&v18[(_DWORD)v16 + 1],
              src: (unsigned __int8 *)&v18[(_DWORD)v16],
              count: 2 * v19);
          v20 = &v15->m_pMemory[(_DWORD)v16];
          if ( v20 != nullptr )
            *v20 = pHelper->m_TempIndices[1];
          v21 = (CUtlMemory<wchar_t,int> *)pHelper->m_pIndices;
          v22 = v21[1].m_pMemory;
          v23 = v21->m_nAllocationCount;
          if ( (int)v22 + 1 > v23 )
            CUtlMemory<wchar_t,int>::Grow(this: v21, num: (int)v22 - v23 + 1);
          ++v21[1].m_pMemory;
          v24 = v21->m_pMemory;
          v25 = (char *)v21[1].m_pMemory - (char *)v22 - 1;
          v21[1].m_nAllocationCount = (int)v21->m_pMemory;
          if ( v25 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&v24[(_DWORD)v22 + 1],
              src: (unsigned __int8 *)&v24[(_DWORD)v22],
              count: 2 * v25);
          v26 = &v21->m_pMemory[(_DWORD)v22];
          if ( v26 != nullptr )
            *v26 = pHelper->m_TempIndices[2];
          pHelper->m_TempIndices[0] = pHelper->m_TempIndices[1];
        }
        v5 = 0;
        iCurTriVert = 0;
      }
      ++iLevela;
      ++iVert;
    }
    while ( iVert < g_TWinding.m_nVerts );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006C6F0
// Name: public: CMemoryBSPFile::CMemoryBSPFile(void)
// Source: json
//------------------------------------------------------------------------------
CMemoryBSPFile *__thiscall CMemoryBSPFile::CMemoryBSPFile(CMemoryBSPFile *this)
{
  this->m_pSerialBuffer = nullptr;
  this->m_pMapFile = nullptr;
  CPlaneHash::CPlaneHash(this: &this->m_PlaneHash);
  this->m_TexInfoList.m_Memory.m_pMemory = nullptr;
  this->m_TexInfoList.m_Memory.m_nAllocationCount = 0;
  this->m_TexInfoList.m_Memory.m_nGrowSize = 0;
  this->m_TexInfoList.m_Size = 0;
  this->m_TexInfoList.m_pElements = nullptr;
  this->m_TexDataList.m_Memory.m_pMemory = nullptr;
  this->m_TexDataList.m_Memory.m_nAllocationCount = 0;
  this->m_TexDataList.m_Memory.m_nGrowSize = 0;
  this->m_TexDataList.m_Size = 0;
  this->m_TexDataList.m_pElements = nullptr;
  this->m_TexStringData.m_Memory.m_pMemory = nullptr;
  this->m_TexStringData.m_Memory.m_nAllocationCount = 0;
  this->m_TexStringData.m_Memory.m_nGrowSize = 0;
  this->m_TexStringData.m_Size = 0;
  this->m_TexStringData.m_pElements = nullptr;
  this->m_TexStringIndices.m_Memory.m_pMemory = nullptr;
  this->m_TexStringIndices.m_Memory.m_nAllocationCount = 0;
  this->m_TexStringIndices.m_Memory.m_nGrowSize = 0;
  this->m_TexStringIndices.m_Size = 0;
  this->m_TexStringIndices.m_pElements = nullptr;
  this->m_ModelList.m_Memory.m_pMemory = nullptr;
  this->m_ModelList.m_Memory.m_nAllocationCount = 0;
  this->m_ModelList.m_Memory.m_nGrowSize = 0;
  this->m_ModelList.m_Size = 0;
  this->m_ModelList.m_pElements = nullptr;
  CVertexHash::CVertexHash(this: &this->m_VertexHash);
  this->m_EdgeList.m_Memory.m_pMemory = nullptr;
  this->m_EdgeList.m_Memory.m_nAllocationCount = 0;
  this->m_EdgeList.m_Memory.m_nGrowSize = 0;
  this->m_EdgeList.m_Size = 0;
  this->m_EdgeList.m_pElements = nullptr;
  this->m_SurfEdgeList.m_Memory.m_pMemory = nullptr;
  this->m_SurfEdgeList.m_Memory.m_nAllocationCount = 0;
  this->m_SurfEdgeList.m_Memory.m_nGrowSize = 0;
  this->m_SurfEdgeList.m_Size = 0;
  this->m_SurfEdgeList.m_pElements = nullptr;
  this->m_FaceList.m_Memory.m_pMemory = nullptr;
  this->m_FaceList.m_Memory.m_nAllocationCount = 0;
  this->m_FaceList.m_Memory.m_nGrowSize = 0;
  this->m_FaceList.m_Size = 0;
  this->m_FaceList.m_pElements = nullptr;
  this->m_VertexNormalList.m_Memory.m_pMemory = nullptr;
  this->m_VertexNormalList.m_Memory.m_nAllocationCount = 0;
  this->m_VertexNormalList.m_Memory.m_nGrowSize = 0;
  this->m_VertexNormalList.m_Size = 0;
  this->m_VertexNormalList.m_pElements = nullptr;
  this->m_VertexNormalIndexList.m_Memory.m_pMemory = nullptr;
  this->m_VertexNormalIndexList.m_Memory.m_nAllocationCount = 0;
  this->m_VertexNormalIndexList.m_Memory.m_nGrowSize = 0;
  this->m_VertexNormalIndexList.m_Size = 0;
  this->m_VertexNormalIndexList.m_pElements = nullptr;
  this->m_NodeList.m_Memory.m_pMemory = nullptr;
  this->m_NodeList.m_Memory.m_nAllocationCount = 0;
  this->m_NodeList.m_Memory.m_nGrowSize = 0;
  this->m_NodeList.m_Size = 0;
  this->m_NodeList.m_pElements = nullptr;
  this->m_LeafList.m_Memory.m_pMemory = nullptr;
  this->m_LeafList.m_Memory.m_nAllocationCount = 0;
  this->m_LeafList.m_Memory.m_nGrowSize = 0;
  this->m_LeafList.m_Size = 0;
  this->m_LeafList.m_pElements = nullptr;
  this->m_LeafBrushList.m_Memory.m_pMemory = nullptr;
  this->m_LeafBrushList.m_Memory.m_nAllocationCount = 0;
  this->m_LeafBrushList.m_Memory.m_nGrowSize = 0;
  this->m_LeafBrushList.m_Size = 0;
  this->m_LeafBrushList.m_pElements = nullptr;
  this->m_LeafFaceList.m_Memory.m_pMemory = nullptr;
  this->m_LeafFaceList.m_Memory.m_nAllocationCount = 0;
  this->m_LeafFaceList.m_Memory.m_nGrowSize = 0;
  this->m_LeafFaceList.m_Size = 0;
  this->m_LeafFaceList.m_pElements = nullptr;
  this->m_BrushList.m_Memory.m_pMemory = nullptr;
  this->m_BrushList.m_Memory.m_nAllocationCount = 0;
  this->m_BrushList.m_Memory.m_nGrowSize = 0;
  this->m_BrushList.m_Size = 0;
  this->m_BrushList.m_pElements = nullptr;
  this->m_BrushSideList.m_Memory.m_pMemory = nullptr;
  this->m_BrushSideList.m_Memory.m_nAllocationCount = 0;
  this->m_BrushSideList.m_Memory.m_nGrowSize = 0;
  this->m_BrushSideList.m_Size = 0;
  this->m_BrushSideList.m_pElements = nullptr;
  this->m_Planes.m_Memory.m_pMemory = nullptr;
  this->m_Planes.m_Memory.m_nAllocationCount = 0;
  this->m_Planes.m_Memory.m_nGrowSize = 0;
  this->m_Planes.m_Size = 0;
  this->m_Planes.m_pElements = nullptr;
  this->m_GameLumpData.m_Memory.m_pMemory = nullptr;
  this->m_GameLumpData.m_Memory.m_nAllocationCount = 0;
  this->m_GameLumpData.m_Memory.m_nGrowSize = 0;
  this->m_GameLumpData.m_Size = 0;
  this->m_GameLumpData.m_pElements = nullptr;
  this->m_EntityData.m_Memory.m_pMemory = nullptr;
  this->m_EntityData.m_Memory.m_nAllocationCount = 0;
  this->m_EntityData.m_Memory.m_nGrowSize = 0;
  this->m_EntityData.m_Size = 0;
  this->m_EntityData.m_pElements = nullptr;
  this->m_VisibilityData.m_Memory.m_pMemory = nullptr;
  this->m_VisibilityData.m_Memory.m_nAllocationCount = 0;
  this->m_VisibilityData.m_Memory.m_nGrowSize = 0;
  this->m_VisibilityData.m_Size = 0;
  this->m_VisibilityData.m_pElements = nullptr;
  this->m_DisplacementHelperList.m_Memory.m_pMemory = nullptr;
  this->m_DisplacementHelperList.m_Memory.m_nAllocationCount = 0;
  this->m_DisplacementHelperList.m_Memory.m_nGrowSize = 0;
  this->m_DisplacementHelperList.m_Size = 0;
  this->m_DisplacementHelperList.m_pElements = nullptr;
  this->m_DisplacementList.m_Memory.m_pMemory = nullptr;
  this->m_DisplacementList.m_Memory.m_nAllocationCount = 0;
  this->m_DisplacementList.m_Memory.m_nGrowSize = 0;
  this->m_DisplacementList.m_Size = 0;
  this->m_DisplacementList.m_pElements = nullptr;
  this->m_DisplacementVertexList.m_Memory.m_pMemory = nullptr;
  this->m_DisplacementVertexList.m_Memory.m_nAllocationCount = 0;
  this->m_DisplacementVertexList.m_Memory.m_nGrowSize = 0;
  this->m_DisplacementVertexList.m_Size = 0;
  this->m_DisplacementVertexList.m_pElements = nullptr;
  this->m_DisplacementTriangleList.m_Memory.m_pMemory = nullptr;
  this->m_DisplacementTriangleList.m_Memory.m_nAllocationCount = 0;
  this->m_DisplacementTriangleList.m_Memory.m_nGrowSize = 0;
  this->m_DisplacementTriangleList.m_Size = 0;
  this->m_DisplacementTriangleList.m_pElements = nullptr;
  this->m_DisplacementMultiBlendList.m_Memory.m_pMemory = nullptr;
  this->m_DisplacementMultiBlendList.m_Memory.m_nAllocationCount = 0;
  this->m_DisplacementMultiBlendList.m_Memory.m_nGrowSize = 0;
  this->m_DisplacementMultiBlendList.m_Size = 0;
  this->m_DisplacementMultiBlendList.m_pElements = nullptr;
  this->m_PhysicsDisplacementData.m_Memory.m_pMemory = nullptr;
  this->m_PhysicsDisplacementData.m_Memory.m_nAllocationCount = 0;
  this->m_PhysicsDisplacementData.m_Memory.m_nGrowSize = 0;
  this->m_PhysicsDisplacementData.m_Size = 0;
  this->m_PhysicsDisplacementData.m_pElements = nullptr;
  this->m_PhysicsCollideData.m_Memory.m_pMemory = nullptr;
  this->m_PhysicsCollideData.m_Memory.m_nAllocationCount = 0;
  this->m_PhysicsCollideData.m_Memory.m_nGrowSize = 0;
  this->m_PhysicsCollideData.m_Size = 0;
  this->m_PhysicsCollideData.m_pElements = nullptr;
  this->m_LightingData.m_Memory.m_pMemory = nullptr;
  this->m_LightingData.m_Memory.m_nAllocationCount = 0;
  this->m_LightingData.m_Memory.m_nGrowSize = 0;
  this->m_LightingData.m_Size = 0;
  this->m_LightingData.m_pElements = nullptr;
  this->m_WorldLightsLDR.m_Memory.m_pMemory = nullptr;
  this->m_WorldLightsLDR.m_Memory.m_nAllocationCount = 0;
  this->m_WorldLightsLDR.m_Memory.m_nGrowSize = 0;
  this->m_WorldLightsLDR.m_Size = 0;
  this->m_WorldLightsLDR.m_pElements = nullptr;
  this->m_WorldLightsHDR.m_Memory.m_pMemory = nullptr;
  this->m_WorldLightsHDR.m_Memory.m_nAllocationCount = 0;
  this->m_WorldLightsHDR.m_Memory.m_nGrowSize = 0;
  this->m_WorldLightsHDR.m_Size = 0;
  this->m_WorldLightsHDR.m_pElements = nullptr;
  if ( this != (CMemoryBSPFile *)-71344 )
    memset(dst: (unsigned __int8 *)&this->m_EntityExclusionFlags, value: 0, count: sizeof(this->m_EntityExclusionFlags));
  _V_memset(dest: (unsigned __int8 *)&this->m_FileHeader, fill: 0, count: 0x40Cu);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1006CAD0
// Name: private: void CMemoryBSPFile::BuildModelData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::BuildModelData(CMemoryBSPFile *this)
{
  int v2; // ebx
  CUtlVector<dmodel_t,CUtlMemory<dmodel_t,int> > *p_m_ModelList; // ecx
  dmodel_t *v4; // esi
  CBSPModel *v5; // ebx
  CBSPNode *m_pRoot; // eax
  bool v7; // cc
  int v8; // ebx
  const CSimpleBSPFile *m_pSimpleBSPFile; // eax
  int m_Size; // [esp-4h] [ebp-1Ch]
  int nFace; // [esp+Ch] [ebp-Ch]
  int nFacea; // [esp+Ch] [ebp-Ch]
  int nFaceb; // [esp+Ch] [ebp-Ch]
  int nModel; // [esp+10h] [ebp-8h]
  CBSPNode *v15; // [esp+14h] [ebp-4h]

  v2 = 0;
  m_Size = this->m_pSimpleBSPFile->m_Models.m_Size;
  p_m_ModelList = &this->m_ModelList;
  p_m_ModelList->m_Size = 0;
  CUtlVector<dmodel_t,CUtlMemory<dmodel_t,int>>::InsertMultipleBefore(this: p_m_ModelList, elem: 0, num: m_Size);
  nModel = 0;
  if ( this->m_pSimpleBSPFile->m_Models.m_Size > 0 )
  {
    while ( 1 )
    {
      v4 = &this->m_ModelList.m_Memory.m_pMemory[v2];
      memset(dst: (unsigned __int8 *)v4, value: 0, count: sizeof(dmodel_t));
      v5 = this->m_pSimpleBSPFile->m_Models.m_Memory.m_pMemory[v2];
      v4->firstface = this->m_FaceList.m_Size;
      v4->origin.x = 0.0;
      v4->origin.y = 0.0;
      v4->origin.z = 0.0;
      v4->mins.x = v5->m_vMinBounds.x;
      v4->mins.y = v5->m_vMinBounds.y;
      v4->mins.z = v5->m_vMinBounds.z;
      v4->maxs.x = v5->m_vMaxBounds.x;
      v4->maxs.y = v5->m_vMaxBounds.y;
      v4->maxs.z = v5->m_vMaxBounds.z;
      m_pRoot = v5->m_pTree->m_pRoot;
      v15 = m_pRoot;
      if ( m_pRoot->m_nSplitPlaneIndex != -1 )
      {
        nFace = 0;
        if ( m_pRoot->m_Faces.m_Size > 0 )
        {
          do
          {
            CMemoryBSPFile::EmitFace(this, pBSPFace: m_pRoot->m_Faces.m_Memory.m_pMemory[nFace], bOnNode: true);
            v7 = ++nFace < v15->m_Faces.m_Size;
            m_pRoot = v15;
          }
          while ( v7 );
        }
        CMemoryBSPFile::WritePortalFaces(this, pNode: m_pRoot->m_pChildren[0]);
        CMemoryBSPFile::WritePortalFaces(this, pNode: v15->m_pChildren[1]);
      }
      for ( nFacea = 0; nFacea < v5->m_DetailFaces.m_Size; ++nFacea )
        CMemoryBSPFile::EmitFace(this, pBSPFace: v5->m_DetailFaces.m_Memory.m_pMemory[nFacea], bOnNode: false);
      v8 = 0;
      if ( nModel == 0 )
      {
        m_pSimpleBSPFile = this->m_pSimpleBSPFile;
        if ( m_pSimpleBSPFile->m_DisplacementFaces.m_Size > 0 )
        {
          nFaceb = 0;
          do
          {
            CMemoryBSPFile::EmitFace(
              this,
              pBSPFace: &m_pSimpleBSPFile->m_DisplacementFaces.m_Memory.m_pMemory[nFaceb],
              bOnNode: false);
            m_pSimpleBSPFile = this->m_pSimpleBSPFile;
            ++nFaceb;
            ++v8;
          }
          while ( v8 < m_pSimpleBSPFile->m_DisplacementFaces.m_Size );
        }
      }
      v4->numfaces = this->m_FaceList.m_Size - v4->firstface;
      if ( ++nModel >= this->m_pSimpleBSPFile->m_Models.m_Size )
        break;
      v2 = nModel;
    }
  }
  if ( this->m_VertexHash.m_Vertices.m_Size > 0x10000
    && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_VBSP2, a2: 1, a3: "Vertex count (%d) exceeded MAX_MAP_VERTS (%d).\n");
  }
  if ( this->m_EdgeList.m_Size > 256000 && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
    _LoggingSystem_Log(a1: LOG_VBSP2, a2: 1, a3: "Edge count (%d) exceeded MAX_MAP_EDGES (%d).\n");
  if ( this->m_SurfEdgeList.m_Size > 512000
    && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_VBSP2, a2: 1, a3: "SurfEdge count (%d) exceeded MAX_MAP_SURFEDGES (%d).\n");
  }
  if ( this->m_FaceList.m_Size > 0x10000 && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
    _LoggingSystem_Log(a1: LOG_VBSP2, a2: 1, a3: "Face count (%d) exceeded MAX_MAP_FACES (%d).\n");
  if ( this->m_VertexNormalList.m_Size > 256000
    && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_VBSP2, a2: 1, a3: "Vertex normal count (%d) exceeded MAX_MAP_VERTNORMALS (%d).\n");
  }
  if ( this->m_VertexNormalIndexList.m_Size > 256000
    && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
  {
    _LoggingSystem_Log(a1: LOG_VBSP2, a2: 1, a3: "Vertex normal index count (%d) exceeded MAX_MAP_VERTNORMALS (%d).\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006CDE0
// Name: private: void CMemoryBSPFile::EmitStaticProp(struct MapEntity_t const __near *,class CUtlVector<struct StaticPropLump_t,class CUtlMemory<struct StaticPropLump_t,int>> __near *,class CUtlVector<struct StaticPropLeafLump_t,class CUtlMemory<struct StaticPropLeafLump_t,int>> __near *,class CUtlVector<struct StaticPropDictLump_t,class CUtlMemory<struct StaticPropDictLump_t,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::EmitStaticProp(
        CMemoryBSPFile *this,
        int pEntity,
        CUtlMemory<MapTextureInfo_t,int> *pStaticPropLump,
        CUtlVector<StaticPropLeafLump_t,CUtlMemory<StaticPropLeafLump_t,int> > *pStaticPropLeafLump,
        CUtlVector<StaticPropDictLump_t,CUtlMemory<StaticPropDictLump_t,int> > *pStaticPropDictionaryLump)
{
  CUtlMemory<MapTextureInfo_t,int> *v5; // esi
  const MapEntity_t *v6; // edi
  int v7; // ecx
  MapEntityKeyValuePair_t *v8; // ebx
  int m_nAllocationCount; // eax
  MapTextureInfo_t *m_pMemory; // edx
  int v11; // eax
  int v12; // esi
  const MapEntityKeyValuePair_t *Pair; // eax
  const char *PairValue; // eax
  const MapEntityKeyValuePair_t *v15; // eax
  char *v16; // eax
  const MapEntityKeyValuePair_t *v17; // eax
  const char *v18; // eax
  const MapEntityKeyValuePair_t *v19; // eax
  const char *v20; // eax
  const MapEntityKeyValuePair_t *v21; // eax
  const char *v22; // eax
  const MapEntityKeyValuePair_t *v23; // eax
  const char *v24; // eax
  const MapEntityKeyValuePair_t *v25; // eax
  const char *v26; // eax
  const MapEntityKeyValuePair_t *v27; // eax
  const char *v28; // eax
  const MapEntityKeyValuePair_t *v29; // eax
  const char *v30; // eax
  MapEntityKeyValuePair_t *v31; // eax
  MapEntityKeyValuePair_t *v32; // eax
  const char *m_pValue; // edi
  char *v34; // eax
  char v35; // dl
  CUtlVector<StaticPropLeafLump_t,CUtlMemory<StaticPropLeafLump_t,int> > *v36; // [esp-4h] [ebp-14h]

  v5 = pStaticPropLump;
  v6 = (const MapEntity_t *)pEntity;
  v8 = &this->m_pMapFile->m_KeyValuePairs.m_Memory.m_pMemory[*(_DWORD *)(pEntity + 20)];
  m_nAllocationCount = pStaticPropLump->m_nAllocationCount;
  pEntity = (int)pStaticPropLump[1].m_pMemory;
  v7 = pEntity;
  if ( pEntity + 1 > m_nAllocationCount )
  {
    CUtlMemory<StaticPropLump_t,int>::Grow(this: pStaticPropLump, num: pEntity - m_nAllocationCount + 1);
    v7 = pEntity;
  }
  ++v5[1].m_pMemory;
  m_pMemory = v5->m_pMemory;
  v11 = (int)v5[1].m_pMemory - v7 - 1;
  v5[1].m_nAllocationCount = (int)v5->m_pMemory;
  if ( v11 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&m_pMemory[v7 + 1], src: (unsigned __int8 *)&m_pMemory[v7], count: 72 * v11);
  v12 = (int)&v5->m_pMemory[(int)v5[1].m_pMemory - 1];
  *(float *)v12 = v6->m_vOrigin.x;
  *(float *)(v12 + 4) = v6->m_vOrigin.y;
  *(float *)(v12 + 8) = v6->m_vOrigin.z;
  *(_QWORD *)(v12 + 16) = 0;
  *(_DWORD *)(v12 + 12) = 0;
  Pair = FindPair(pKeyName: "angles", pPairs: v8, nNumPairs: v6->m_nNumKVPairs);
  PairValue = GetPairValue(pPair: Pair);
  sscanf(string: PairValue, format: "%f %f %f", v12 + 12, v12 + 16, v12 + 20);
  v15 = FindPair(pKeyName: "model", pPairs: v8, nNumPairs: v6->m_nNumKVPairs);
  v16 = (char *)GetPairValue(pPair: v15);
  *(_WORD *)(v12 + 24) = CMemoryBSPFile::AddStaticPropDictionaryEntry(this, pModelName: v16, pStaticPropDictionaryLump);
  v36 = pStaticPropLeafLump;
  *(_WORD *)(v12 + 26) = pStaticPropLeafLump->m_Size;
  *(_WORD *)(v12 + 28) = CMemoryBSPFile::AddStaticPropLeaves(
                           this,
                           vOrigin: (const Vector *)v12,
                           nNodeIndex: 0,
                           pStaticPropLeafLump: v36);
  v17 = FindPair(pKeyName: "solid", pPairs: v8, nNumPairs: v6->m_nNumKVPairs);
  v18 = GetPairValue(pPair: v17);
  *(_BYTE *)(v12 + 30) = atoi(nptr: v18);
  v19 = FindPair(pKeyName: "skin", pPairs: v8, nNumPairs: v6->m_nNumKVPairs);
  v20 = GetPairValue(pPair: v19);
  *(_DWORD *)(v12 + 32) = atoi(nptr: v20);
  *(_BYTE *)(v12 + 31) = 0;
  v21 = FindPair(pKeyName: "disablesahdows", pPairs: v8, nNumPairs: v6->m_nNumKVPairs);
  v22 = GetPairValue(pPair: v21);
  if ( atoi(nptr: v22) == 1 )
    *(_BYTE *)(v12 + 31) |= 0x10u;
  v23 = FindPair(pKeyName: "ignorenormals", pPairs: v8, nNumPairs: v6->m_nNumKVPairs);
  v24 = GetPairValue(pPair: v23);
  if ( atoi(nptr: v24) == 1 )
    *(_BYTE *)(v12 + 31) |= 8u;
  v25 = FindPair(pKeyName: "disableselfshadowing", pPairs: v8, nNumPairs: v6->m_nNumKVPairs);
  v26 = GetPairValue(pPair: v25);
  if ( atoi(nptr: v26) == 1 )
    *(_BYTE *)(v12 + 31) |= 0x80u;
  v27 = FindPair(pKeyName: "disablevertexlighting", pPairs: v8, nNumPairs: v6->m_nNumKVPairs);
  v28 = GetPairValue(pPair: v27);
  if ( atoi(nptr: v28) == 1 )
    *(_BYTE *)(v12 + 31) |= 0x40u;
  v29 = FindPair(pKeyName: "fademaxdist", pPairs: v8, nNumPairs: v6->m_nNumKVPairs);
  v30 = GetPairValue(pPair: v29);
  *(float *)(v12 + 40) = atof(nptr: v30);
  *(_DWORD *)(v12 + 36) = 0;
  *(Vector *)(v12 + 44) = vec3_origin;
  *(_QWORD *)(v12 + 56) = 1065353216;
  *(_BYTE *)(v12 + 68) = 0;
  v31 = FindPair(pKeyName: "rendercolor", pPairs: v8, nNumPairs: v6->m_nNumKVPairs);
  if ( v31 != nullptr )
    pEntity = (int)v31->m_pValue;
  else
    pEntity = 0;
  v32 = FindPair(pKeyName: "renderamt", pPairs: v8, nNumPairs: v6->m_nNumKVPairs);
  if ( v32 != nullptr )
    m_pValue = v32->m_pValue;
  else
    m_pValue = nullptr;
  v34 = (char *)pEntity;
  *(_DWORD *)(v12 + 64) = -1;
  if ( v34 != nullptr )
  {
    V_StringToColor32(color: (color32_s *)&pEntity, pString: v34);
    v35 = BYTE2(pEntity);
    *(_WORD *)(v12 + 64) = pEntity;
    *(_BYTE *)(v12 + 66) = v35;
  }
  if ( m_pValue != nullptr )
    *(_BYTE *)(v12 + 67) = atoi(nptr: m_pValue);
}

//------------------------------------------------------------------------------
// Address: 0x1006D0C0
// Name: private: class CPhysCollisionEntry __near * CMemoryBSPFile::CreateWorldPhysicsModels(class IPhysicsCollision __near *,class CUtlVector<int,class CUtlMemory<int,int>> __near *,int const __near *,struct dmodel_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CPhysCollisionEntryStaticSolid *__userpurge CMemoryBSPFile::CreateWorldPhysicsModels@<eax>(
        CMemoryBSPFile *this@<ecx>,
        int a2@<esi>,
        IPhysicsCollision *pPhysicsCollision,
        CUtlVector<int,CUtlMemory<int,int> > *pWorldPropertyRemapList,
        const int *pSurfacePropertyList,
        const dmodel_t *pModel,
        int contentsMask)
{
  IPhysicsCollision *v7; // ebx
  float v9; // eax
  IPhysicsCollision_vtbl *v10; // edx
  float *v11; // esi
  float z; // ebx
  int m_nTextureInfoIndex; // eax
  int v14; // eax
  CPhysCollisionEntryStaticSolid *v15; // eax
  CPhysCollisionEntryStaticSolid *v16; // edi
  vgui::CTreeViewListControl::CColumnInfo *m_pMemory; // eax
  int v19; // [esp+14h] [ebp-474h]
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > flShrink; // [esp+18h] [ebp-470h] BYREF
  CPhysConvexBuilder physConvexBuilder; // [esp+30h] [ebp-458h] BYREF
  Vector vPoints[3]; // [esp+458h] [ebp-30h] BYREF
  Vector vNormal; // [esp+47Ch] [ebp-Ch]
  int j; // [esp+49Ch] [ebp+14h]

  v7 = pPhysicsCollision;
  CPhysConvexBuilder::CPhysConvexBuilder(
    this: (CPhysConvexBuilder *)&flShrink,
    flShrink: 0.0,
    contentsMask,
    pMapFile: this->m_pMapFile,
    pPhysicsCollision);
  CPhysConvexBuilder::BuildConvexes(
    this: (CPhysConvexBuilder *)&flShrink,
    nNodeIndex: pModel->headnode,
    nodeList: &this->m_NodeList,
    leafList: &this->m_LeafList,
    leafBrushList: &this->m_LeafBrushList);
  if ( flShrink.m_Size <= 0 )
  {
    CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: &flShrink);
    return nullptr;
  }
  else
  {
    v9 = COERCE_FLOAT(
           ((int (__thiscall *)(IPhysicsCollision *, vgui::CTreeViewListControl::CColumnInfo *, int, int))pPhysicsCollision->ConvertConvexToCollide)(
             a1: pPhysicsCollision,
             a2: flShrink.m_Memory.m_pMemory,
             a3: flShrink.m_Size,
             a4: a2));
    v10 = pPhysicsCollision->__vftable;
    vPoints[2].z = v9;
    v11 = (float *)((int (__thiscall *)(IPhysicsCollision *, float))v10->CreateQueryModel)(
                     a1: pPhysicsCollision,
                     a2: COERCE_FLOAT(LODWORD(v9)));
    LODWORD(vNormal.x) = (*(int (__thiscall **)(float *))(*(_DWORD *)v11 + 4))(a1: v11);
    j = 0;
    if ( SLODWORD(vNormal.x) > 0 )
    {
      do
      {
        LODWORD(vNormal.y) = (*(int (__thiscall **)(float *, int))(*(_DWORD *)v11 + 8))(a1: v11, a2: j);
        z = 0.0;
        LODWORD(vPoints[2].y) = (*(int (__thiscall **)(float *, int))(*(_DWORD *)v11 + 12))(a1: v11, a2: j);
        vNormal.z = 0.0;
        if ( SLODWORD(vNormal.y) > 0 )
        {
          do
          {
            (*(void (__thiscall **)(float *, int, float, unsigned int *))(*(_DWORD *)v11 + 16))(
              a1: v11,
              a2: j,
              a3: COERCE_FLOAT(LODWORD(z)),
              a4: &physConvexBuilder.m_IsBrushReferenced.m_Ints[252]);
            TriangleNormal(
              result: &vPoints[1],
              v0: (const Vector *)&physConvexBuilder.m_IsBrushReferenced.m_Ints[252],
              v1: (const Vector *)&physConvexBuilder.m_IsBrushReferenced.m_Ints[255],
              v2: vPoints);
            m_nTextureInfoIndex = CMemoryBSPFile::FindClosestBrushSide(
                                    this,
                                    nBrushIndex: (const MapBrushSide_t *)LODWORD(vPoints[2].y),
                                    vNormal: &vPoints[1])->m_nTextureInfoIndex;
            if ( m_nTextureInfoIndex != -1 )
            {
              v19 = pSurfacePropertyList[this->m_pMapFile->m_TextureInfos.m_Memory.m_pMemory[m_nTextureInfoIndex].m_nTextureDataIndex];
              vPoints[2].x = *v11;
              v14 = CMemoryBSPFile::RemapWorldMaterial(this, pWorldPropertyRemapList, nSurfacePropertyIndex: v19);
              z = vNormal.z;
              (*(void (__thiscall **)(float *, int, _DWORD, int))(LODWORD(vPoints[2].x) + 28))(
                a1: v11,
                a2: j,
                a3: LODWORD(vNormal.z),
                a4: v14);
            }
            ++LODWORD(z);
            vNormal.z = z;
          }
          while ( SLODWORD(z) < SLODWORD(vNormal.y) );
        }
        ++j;
      }
      while ( j < SLODWORD(vNormal.x) );
      v7 = pPhysicsCollision;
    }
    v7->DestroyQueryModel(this: v7, a2: (ICollisionQuery *)v11);
    v15 = (CPhysCollisionEntryStaticSolid *)operator new(nSize: 0xCu);
    if ( v15 != nullptr )
      v16 = CPhysCollisionEntryStaticSolid::CPhysCollisionEntryStaticSolid(
              this: v15,
              pCollide: (struct CPhysCollide *)LODWORD(vPoints[2].z),
              contentsMask);
    else
      v16 = nullptr;
    m_pMemory = flShrink.m_Memory.m_pMemory;
    flShrink.m_Size = 0;
    if ( flShrink.m_Memory.m_nGrowSize >= 0 )
    {
      if ( flShrink.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: flShrink.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        flShrink.m_Memory.m_pMemory = nullptr;
      }
      flShrink.m_Memory.m_nAllocationCount = 0;
    }
    flShrink.m_pElements = m_pMemory;
    if ( flShrink.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return v16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006D2E0
// Name: void TesselateDisplacement_R<class CSimpleBSPTessellateHelper>(class CSimpleBSPTessellateHelper __near *,class CVertIndex const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TesselateDisplacement_R<CSimpleBSPTessellateHelper>(
        CSimpleBSPTessellateHelper *pHelper,
        const CVertIndex *nodeIndex,
        int iNodeBitIndex,
        int iLevel)
{
  const CPowerInfo *m_pPowerInfo; // ecx
  int v6; // edx
  int v7; // ebx
  const CPowerInfo *v8; // ecx
  const CVertIndex *v9; // esi
  unsigned int v10; // edx
  int bActiveChildren[4]; // [esp+0h] [ebp-18h] BYREF
  int oldIndexCount; // [esp+10h] [ebp-8h]
  int v13; // [esp+14h] [ebp-4h]
  int iChildNodeBit; // [esp+20h] [ebp+8h]

  if ( (`CSimpleBSPTessellateHelper::GetNodeInfo'::`2'::`local static guard' & 1) == 0 )
    `CSimpleBSPTessellateHelper::GetNodeInfo'::`2'::`local static guard' |= 1u;
  m_pPowerInfo = pHelper->m_pPowerInfo;
  v6 = m_pPowerInfo->m_Power - 1;
  oldIndexCount = pHelper->m_nIndices;
  if ( iLevel < v6 )
  {
    v7 = 0;
    iChildNodeBit = iNodeBitIndex + 1;
    v13 = 16 * (nodeIndex->x + m_pPowerInfo->m_SideLength * nodeIndex->y);
    do
    {
      v8 = pHelper->m_pPowerInfo;
      v9 = &v8->m_pChildVerts->m_Verts[v13 / 4u];
      v10 = pHelper->m_pActiveVerts[(v9->x + v8->m_SideLength * v9->y) >> 5]
          & (1 << ((v9->x + LOBYTE(v8->m_SideLength) * v9->y) & 0x1F));
      bActiveChildren[v7] = v10;
      if ( v10 != 0 )
      {
        TesselateDisplacement_R<CSimpleBSPTessellateHelper>(
          pHelper,
          nodeIndex: v9,
          iNodeBitIndex: iChildNodeBit,
          iLevel: iLevel + 1);
      }
      else
      {
        if ( (`CSimpleBSPTessellateHelper::GetNodeInfo'::`2'::`local static guard' & 1) == 0 )
          `CSimpleBSPTessellateHelper::GetNodeInfo'::`2'::`local static guard' |= 1u;
        word_101B74A6 = 0;
      }
      iChildNodeBit += pHelper->m_pPowerInfo->m_NodeIndexIncrements[iLevel];
      v13 += 4;
      ++v7;
    }
    while ( v7 < 4 );
  }
  else
  {
    memset(bActiveChildren, 0, sizeof(bActiveChildren));
  }
  if ( pHelper->m_nIndices == oldIndexCount )
  {
    HIBYTE(word_101B74A6) = 0;
  }
  else
  {
    HIBYTE(word_101B74A6) = 1;
    oldIndexCount = pHelper->m_nIndices;
  }
  TesselateDisplacementNode<CSimpleBSPTessellateHelper>(pHelper, nodeIndex, iLevel, pActiveChildren: bActiveChildren);
  LOBYTE(word_101B74A6) = LOBYTE(pHelper->m_nIndices) - oldIndexCount;
  `CSimpleBSPTessellateHelper::GetNodeInfo'::`2'::dummy = oldIndexCount;
}

//------------------------------------------------------------------------------
// Address: 0x1006D410
// Name: public: CMemoryBSPFile::~CMemoryBSPFile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::~CMemoryBSPFile(CMemoryBSPFile *this)
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_WorldLightsHDR);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_WorldLightsLDR);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LightingData);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_PhysicsCollideData);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_PhysicsDisplacementData);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_DisplacementMultiBlendList);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_DisplacementTriangleList);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_DisplacementVertexList);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_DisplacementList);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_DisplacementHelperList);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_VisibilityData);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_EntityData);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_GameLumpData);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_Planes);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_BrushSideList);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_BrushList);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LeafFaceList);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LeafBrushList);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_LeafList);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_NodeList);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_VertexNormalIndexList);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_VertexNormalList);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_FaceList);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_SurfEdgeList);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_EdgeList);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_VertexHash.m_Vertices);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_VertexHash.m_VertexHashChain);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_ModelList);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_TexStringIndices);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_TexStringData);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_TexDataList);
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_TexInfoList);
  this->m_PlaneHash.m_Planes.__vftable = (CCopyableUtlVector<HashedPlane_t>_vtbl *)&CCopyableUtlVector<HashedPlane_t>::`vftable';
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_PlaneHash.m_Planes.CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> >);
}

//------------------------------------------------------------------------------
// Address: 0x1006D590
// Name: private: void CMemoryBSPFile::BuildGameLumpData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::BuildGameLumpData(CMemoryBSPFile *this)
{
  int v1; // ebx
  const CSimpleMapFile *m_pMapFile; // eax
  int m_Size; // ecx
  const CSimpleMapFile *v5; // eax
  int v6; // esi
  MapEntityKeyValuePair_t *Pair; // eax
  const CSimpleMapFile *v8; // eax
  int v9; // ecx
  int v10; // eax
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *p_m_GameLumpData; // esi
  unsigned __int8 *m_pMemory; // edx
  unsigned __int8 *v13; // eax
  int v14; // ebx
  int m_nAllocationCount; // eax
  unsigned __int8 *v16; // ecx
  signed int v17; // eax
  unsigned __int8 *v18; // eax
  unsigned __int8 *v19; // ebx
  int m_Put; // eax
  int v21; // edi
  int v22; // ebx
  int v23; // eax
  unsigned __int8 *v24; // ecx
  signed int v25; // eax
  int i; // eax
  unsigned __int8 *v27; // ecx
  int v28; // edi
  int v29; // eax
  unsigned __int8 *v30; // ecx
  signed int v31; // eax
  int j; // eax
  unsigned __int8 *v33; // ecx
  int v34; // edi
  int v35; // eax
  unsigned __int8 *v36; // ecx
  signed int v37; // eax
  unsigned __int8 *v38; // eax
  int v39; // edi
  int v40; // eax
  __int16 v41; // bx
  unsigned __int8 *v42; // ecx
  signed int v43; // eax
  unsigned __int8 *v44; // eax
  unsigned __int8 *v45; // edi
  int v46; // edi
  int v47; // eax
  unsigned __int8 *v48; // ecx
  signed int v49; // eax
  unsigned __int8 *v50; // eax
  unsigned __int8 *v51; // edi
  int v52; // edi
  int v53; // eax
  unsigned __int8 *v54; // ecx
  signed int v55; // eax
  unsigned __int8 *v56; // eax
  unsigned __int8 *v57; // edi
  int v58; // edi
  int v59; // eax
  unsigned __int8 *v60; // ecx
  signed int v61; // eax
  unsigned __int8 *v62; // eax
  int v63; // edi
  int v64; // eax
  unsigned __int8 *v65; // ecx
  signed int v66; // eax
  unsigned __int8 *v67; // eax
  StaticPropLeafLump_t *v68; // eax
  CUtlVector<StaticPropDictLump_t,CUtlMemory<StaticPropDictLump_t,int> > staticPropDictionaryLump; // [esp+Ch] [ebp-5Ch] BYREF
  CUtlVector<StaticPropLump_t,CUtlMemory<StaticPropLump_t,int> > staticPropLump; // [esp+20h] [ebp-48h] BYREF
  CUtlVector<StaticPropLeafLump_t,CUtlMemory<StaticPropLeafLump_t,int> > staticPropLeafLump; // [esp+34h] [ebp-34h] BYREF
  dgamelump_t staticPropLumpHeader; // [esp+48h] [ebp-20h]
  int nPropSize; // [esp+58h] [ebp-10h]
  int nLeafSize; // [esp+5Ch] [ebp-Ch]
  int nDictionarySize; // [esp+60h] [ebp-8h]
  int nCount; // [esp+64h] [ebp-4h]

  v1 = 0;
  m_pMapFile = this->m_pMapFile;
  m_Size = 0;
  memset(&staticPropLeafLump, 0, sizeof(staticPropLeafLump));
  memset(&staticPropDictionaryLump, 0, sizeof(staticPropDictionaryLump));
  memset(&staticPropLump, 0, sizeof(staticPropLump));
  if ( m_pMapFile->m_Entities.m_Size > 0 )
  {
    nCount = 0;
    do
    {
      v5 = this->m_pMapFile;
      v6 = (int)v5->m_Entities.m_Memory.m_pMemory + nCount;
      Pair = FindPair(
               pKeyName: "classname",
               pPairs: &v5->m_KeyValuePairs.m_Memory.m_pMemory[*(_DWORD *)(v6 + 20)],
               nNumPairs: *(_DWORD *)(v6 + 24));
      if ( Pair != nullptr && _V_stricmp(s1: Pair->m_pValue, s2: "prop_static") == 0 )
      {
        CMemoryBSPFile::EmitStaticProp(
          this,
          pEntity: v6,
          pStaticPropLump: (CUtlMemory<MapTextureInfo_t,int> *)&staticPropLump,
          pStaticPropLeafLump: &staticPropLeafLump,
          pStaticPropDictionaryLump: &staticPropDictionaryLump);
        this->m_EntityExclusionFlags.m_Ints[v1 >> 5] |= 1 << (v1 & 0x1F);
      }
      v8 = this->m_pMapFile;
      nCount += 28;
      ++v1;
    }
    while ( v1 < v8->m_Entities.m_Size );
    m_Size = staticPropLump.m_Size;
  }
  nPropSize = 72 * m_Size;
  v9 = 2 * staticPropLeafLump.m_Size + 72 * m_Size;
  nDictionarySize = staticPropDictionaryLump.m_Size << 7;
  nCount = v9 + (staticPropDictionaryLump.m_Size << 7) + 12;
  v10 = v9 + (staticPropDictionaryLump.m_Size << 7) + 60;
  p_m_GameLumpData = &this->m_GameLumpData;
  nLeafSize = 2 * staticPropLeafLump.m_Size;
  if ( this->m_GameLumpData.m_Memory.m_nAllocationCount < v10 && this->m_GameLumpData.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = p_m_GameLumpData->m_Memory.m_pMemory;
    this->m_GameLumpData.m_Memory.m_nAllocationCount = v10;
    if ( m_pMemory != nullptr )
      v13 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v10);
    else
      v13 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v10);
    p_m_GameLumpData->m_Memory.m_pMemory = v13;
  }
  this->m_GameLumpData.m_pElements = this->m_GameLumpData.m_Memory.m_pMemory;
  v14 = this->m_GameLumpData.m_Size;
  m_nAllocationCount = this->m_GameLumpData.m_Memory.m_nAllocationCount;
  if ( v14 + 4 > m_nAllocationCount )
    CUtlMemory<char,int>::Grow(this: &this->m_GameLumpData.m_Memory, num: v14 - m_nAllocationCount + 4);
  this->m_GameLumpData.m_Size += 4;
  v16 = p_m_GameLumpData->m_Memory.m_pMemory;
  v17 = this->m_GameLumpData.m_Size - v14 - 4;
  this->m_GameLumpData.m_pElements = this->m_GameLumpData.m_Memory.m_pMemory;
  if ( v17 > 0 )
    _V_memmove(dest: &v16[v14 + 4], src: &v16[v14], count: v17);
  v18 = &p_m_GameLumpData->m_Memory.m_pMemory[v14];
  if ( v18 != nullptr )
    *v18 = 2;
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v14] != (unsigned __int8 *)-1 )
    p_m_GameLumpData->m_Memory.m_pMemory[v14 + 1] = 0;
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v14] != (unsigned __int8 *)-2 )
    p_m_GameLumpData->m_Memory.m_pMemory[v14 + 2] = 0;
  v19 = &p_m_GameLumpData->m_Memory.m_pMemory[v14 + 3];
  if ( v19 != nullptr )
    *v19 = 0;
  m_Put = this->m_pSerialBuffer->m_Put;
  v21 = this->m_GameLumpData.m_Size;
  v22 = v21 + m_Put + 32;
  v23 = p_m_GameLumpData->m_Memory.m_nAllocationCount;
  staticPropLumpHeader.id = 1936749168;
  *(_DWORD *)&staticPropLumpHeader.flags = 589824;
  staticPropLumpHeader.fileofs = v22;
  staticPropLumpHeader.filelen = nCount;
  if ( v21 + 16 > v23 )
    CUtlMemory<char,int>::Grow(this: &p_m_GameLumpData->m_Memory, num: v21 - v23 + 16);
  p_m_GameLumpData->m_Size += 16;
  v24 = p_m_GameLumpData->m_Memory.m_pMemory;
  v25 = p_m_GameLumpData->m_Size - v21 - 16;
  p_m_GameLumpData->m_pElements = p_m_GameLumpData->m_Memory.m_pMemory;
  if ( v25 > 0 )
    _V_memmove(dest: &v24[v21 + 16], src: &v24[v21], count: v25);
  for ( i = 0; i < 16; i += 4 )
  {
    v27 = &p_m_GameLumpData->m_Memory.m_pMemory[i + v21];
    if ( v27 != nullptr )
      *v27 = *((_BYTE *)&staticPropLumpHeader.id + i);
    if ( &p_m_GameLumpData->m_Memory.m_pMemory[i + v21] != (unsigned __int8 *)-1 )
      p_m_GameLumpData->m_Memory.m_pMemory[i + 1 + v21] = *((_BYTE *)&staticPropLumpHeader.id + i + 1);
    if ( &p_m_GameLumpData->m_Memory.m_pMemory[i + v21] != (unsigned __int8 *)-2 )
      p_m_GameLumpData->m_Memory.m_pMemory[i + 2 + v21] = *((_BYTE *)&staticPropLumpHeader.id + i + 2);
    if ( &p_m_GameLumpData->m_Memory.m_pMemory[i + v21] != (unsigned __int8 *)-3 )
      p_m_GameLumpData->m_Memory.m_pMemory[i + 3 + v21] = *((_BYTE *)&staticPropLumpHeader.id + i + 3);
  }
  v28 = p_m_GameLumpData->m_Size;
  v29 = p_m_GameLumpData->m_Memory.m_nAllocationCount;
  staticPropLumpHeader.id = 1685090928;
  *(_DWORD *)&staticPropLumpHeader.flags = 0x40000;
  staticPropLumpHeader.fileofs = nCount + v22;
  staticPropLumpHeader.filelen = 12;
  if ( v28 + 16 > v29 )
    CUtlMemory<char,int>::Grow(this: &p_m_GameLumpData->m_Memory, num: v28 - v29 + 16);
  p_m_GameLumpData->m_Size += 16;
  v30 = p_m_GameLumpData->m_Memory.m_pMemory;
  v31 = p_m_GameLumpData->m_Size - v28 - 16;
  p_m_GameLumpData->m_pElements = p_m_GameLumpData->m_Memory.m_pMemory;
  if ( v31 > 0 )
    _V_memmove(dest: &v30[v28 + 16], src: &v30[v28], count: v31);
  for ( j = 0; j < 16; j += 4 )
  {
    v33 = &p_m_GameLumpData->m_Memory.m_pMemory[j + v28];
    if ( v33 != nullptr )
      *v33 = *((_BYTE *)&staticPropLumpHeader.id + j);
    if ( &p_m_GameLumpData->m_Memory.m_pMemory[j + v28] != (unsigned __int8 *)-1 )
      p_m_GameLumpData->m_Memory.m_pMemory[j + 1 + v28] = *((_BYTE *)&staticPropLumpHeader.id + j + 1);
    if ( &p_m_GameLumpData->m_Memory.m_pMemory[j + v28] != (unsigned __int8 *)-2 )
      p_m_GameLumpData->m_Memory.m_pMemory[j + 2 + v28] = *((_BYTE *)&staticPropLumpHeader.id + j + 2);
    if ( &p_m_GameLumpData->m_Memory.m_pMemory[j + v28] != (unsigned __int8 *)-3 )
      p_m_GameLumpData->m_Memory.m_pMemory[j + 3 + v28] = *((_BYTE *)&staticPropLumpHeader.id + j + 3);
  }
  v34 = p_m_GameLumpData->m_Size;
  v35 = p_m_GameLumpData->m_Memory.m_nAllocationCount;
  if ( v34 + 4 > v35 )
    CUtlMemory<char,int>::Grow(this: &p_m_GameLumpData->m_Memory, num: v34 - v35 + 4);
  p_m_GameLumpData->m_Size += 4;
  v36 = p_m_GameLumpData->m_Memory.m_pMemory;
  v37 = p_m_GameLumpData->m_Size - v34 - 4;
  p_m_GameLumpData->m_pElements = p_m_GameLumpData->m_Memory.m_pMemory;
  if ( v37 > 0 )
    _V_memmove(dest: &v36[v34 + 4], src: &v36[v34], count: v37);
  v38 = &p_m_GameLumpData->m_Memory.m_pMemory[v34];
  if ( v38 != nullptr )
    *v38 = staticPropDictionaryLump.m_Size;
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v34] != (unsigned __int8 *)-1 )
    p_m_GameLumpData->m_Memory.m_pMemory[v34 + 1] = BYTE1(staticPropDictionaryLump.m_Size);
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v34] != (unsigned __int8 *)-2 )
    p_m_GameLumpData->m_Memory.m_pMemory[v34 + 2] = BYTE2(staticPropDictionaryLump.m_Size);
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v34] != (unsigned __int8 *)-3 )
    p_m_GameLumpData->m_Memory.m_pMemory[v34 + 3] = HIBYTE(staticPropDictionaryLump.m_Size);
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::InsertMultipleBefore(
    this: p_m_GameLumpData,
    elem: p_m_GameLumpData->m_Size,
    num: nDictionarySize,
    pToInsert: (const unsigned __int8 *)staticPropDictionaryLump.m_Memory.m_pMemory);
  v39 = p_m_GameLumpData->m_Size;
  v40 = p_m_GameLumpData->m_Memory.m_nAllocationCount;
  v41 = staticPropLeafLump.m_Size;
  nCount = staticPropLeafLump.m_Size;
  if ( v39 + 4 > v40 )
    CUtlMemory<char,int>::Grow(this: &p_m_GameLumpData->m_Memory, num: v39 - v40 + 4);
  p_m_GameLumpData->m_Size += 4;
  v42 = p_m_GameLumpData->m_Memory.m_pMemory;
  v43 = p_m_GameLumpData->m_Size - v39 - 4;
  p_m_GameLumpData->m_pElements = p_m_GameLumpData->m_Memory.m_pMemory;
  if ( v43 > 0 )
    _V_memmove(dest: &v42[v39 + 4], src: &v42[v39], count: v43);
  v44 = &p_m_GameLumpData->m_Memory.m_pMemory[v39];
  if ( v44 != nullptr )
    *v44 = v41;
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v39] != (unsigned __int8 *)-1 )
    p_m_GameLumpData->m_Memory.m_pMemory[v39 + 1] = HIBYTE(v41);
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v39] != (unsigned __int8 *)-2 )
    p_m_GameLumpData->m_Memory.m_pMemory[v39 + 2] = BYTE2(nCount);
  v45 = &p_m_GameLumpData->m_Memory.m_pMemory[v39 + 3];
  if ( v45 != nullptr )
    *v45 = HIBYTE(nCount);
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::InsertMultipleBefore(
    this: p_m_GameLumpData,
    elem: p_m_GameLumpData->m_Size,
    num: nLeafSize,
    pToInsert: (const unsigned __int8 *)staticPropLeafLump.m_Memory.m_pMemory);
  v46 = p_m_GameLumpData->m_Size;
  v47 = p_m_GameLumpData->m_Memory.m_nAllocationCount;
  if ( v46 + 4 > v47 )
    CUtlMemory<char,int>::Grow(this: &p_m_GameLumpData->m_Memory, num: v46 - v47 + 4);
  p_m_GameLumpData->m_Size += 4;
  v48 = p_m_GameLumpData->m_Memory.m_pMemory;
  v49 = p_m_GameLumpData->m_Size - v46 - 4;
  p_m_GameLumpData->m_pElements = p_m_GameLumpData->m_Memory.m_pMemory;
  if ( v49 > 0 )
    _V_memmove(dest: &v48[v46 + 4], src: &v48[v46], count: v49);
  v50 = &p_m_GameLumpData->m_Memory.m_pMemory[v46];
  if ( v50 != nullptr )
    *v50 = staticPropLump.m_Size;
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v46] != (unsigned __int8 *)-1 )
    p_m_GameLumpData->m_Memory.m_pMemory[v46 + 1] = BYTE1(staticPropLump.m_Size);
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v46] != (unsigned __int8 *)-2 )
    p_m_GameLumpData->m_Memory.m_pMemory[v46 + 2] = BYTE2(staticPropLump.m_Size);
  v51 = &p_m_GameLumpData->m_Memory.m_pMemory[v46 + 3];
  if ( v51 != nullptr )
    *v51 = HIBYTE(staticPropLump.m_Size);
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::InsertMultipleBefore(
    this: p_m_GameLumpData,
    elem: p_m_GameLumpData->m_Size,
    num: nPropSize,
    pToInsert: (const unsigned __int8 *)staticPropLump.m_Memory.m_pMemory);
  v52 = p_m_GameLumpData->m_Size;
  v53 = p_m_GameLumpData->m_Memory.m_nAllocationCount;
  if ( v52 + 4 > v53 )
    CUtlMemory<char,int>::Grow(this: &p_m_GameLumpData->m_Memory, num: v52 - v53 + 4);
  p_m_GameLumpData->m_Size += 4;
  v54 = p_m_GameLumpData->m_Memory.m_pMemory;
  v55 = p_m_GameLumpData->m_Size - v52 - 4;
  p_m_GameLumpData->m_pElements = p_m_GameLumpData->m_Memory.m_pMemory;
  if ( v55 > 0 )
    _V_memmove(dest: &v54[v52 + 4], src: &v54[v52], count: v55);
  v56 = &p_m_GameLumpData->m_Memory.m_pMemory[v52];
  if ( v56 != nullptr )
    *v56 = 0;
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v52] != (unsigned __int8 *)-1 )
    p_m_GameLumpData->m_Memory.m_pMemory[v52 + 1] = 0;
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v52] != (unsigned __int8 *)-2 )
    p_m_GameLumpData->m_Memory.m_pMemory[v52 + 2] = 0;
  v57 = &p_m_GameLumpData->m_Memory.m_pMemory[v52 + 3];
  if ( v57 != nullptr )
    *v57 = 0;
  v58 = p_m_GameLumpData->m_Size;
  v59 = p_m_GameLumpData->m_Memory.m_nAllocationCount;
  if ( v58 + 4 > v59 )
    CUtlMemory<char,int>::Grow(this: &p_m_GameLumpData->m_Memory, num: v58 - v59 + 4);
  p_m_GameLumpData->m_Size += 4;
  v60 = p_m_GameLumpData->m_Memory.m_pMemory;
  v61 = p_m_GameLumpData->m_Size - v58 - 4;
  p_m_GameLumpData->m_pElements = p_m_GameLumpData->m_Memory.m_pMemory;
  if ( v61 > 0 )
    _V_memmove(dest: &v60[v58 + 4], src: &v60[v58], count: v61);
  v62 = &p_m_GameLumpData->m_Memory.m_pMemory[v58];
  if ( v62 != nullptr )
    *v62 = 0;
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v58] != (unsigned __int8 *)-1 )
    p_m_GameLumpData->m_Memory.m_pMemory[v58 + 1] = 0;
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v58] != (unsigned __int8 *)-2 )
    p_m_GameLumpData->m_Memory.m_pMemory[v58 + 2] = 0;
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v58] != (unsigned __int8 *)-3 )
    p_m_GameLumpData->m_Memory.m_pMemory[v58 + 3] = 0;
  v63 = p_m_GameLumpData->m_Size;
  v64 = p_m_GameLumpData->m_Memory.m_nAllocationCount;
  if ( v63 + 4 > v64 )
    CUtlMemory<char,int>::Grow(this: &p_m_GameLumpData->m_Memory, num: v63 - v64 + 4);
  p_m_GameLumpData->m_Size += 4;
  v65 = p_m_GameLumpData->m_Memory.m_pMemory;
  v66 = p_m_GameLumpData->m_Size - v63 - 4;
  p_m_GameLumpData->m_pElements = p_m_GameLumpData->m_Memory.m_pMemory;
  if ( v66 > 0 )
    _V_memmove(dest: &v65[v63 + 4], src: &v65[v63], count: v66);
  v67 = &p_m_GameLumpData->m_Memory.m_pMemory[v63];
  if ( v67 != nullptr )
    *v67 = 0;
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v63] != (unsigned __int8 *)-1 )
    p_m_GameLumpData->m_Memory.m_pMemory[v63 + 1] = 0;
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v63] != (unsigned __int8 *)-2 )
    p_m_GameLumpData->m_Memory.m_pMemory[v63 + 2] = 0;
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v63] != (unsigned __int8 *)-3 )
    p_m_GameLumpData->m_Memory.m_pMemory[v63 + 3] = 0;
  if ( staticPropLump.m_Memory.m_nGrowSize >= 0 && staticPropLump.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: staticPropLump.m_Memory.m_pMemory);
  v68 = staticPropLeafLump.m_Memory.m_pMemory;
  staticPropLeafLump.m_Size = 0;
  if ( staticPropLeafLump.m_Memory.m_nGrowSize >= 0 )
  {
    if ( staticPropLeafLump.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: staticPropLeafLump.m_Memory.m_pMemory);
      v68 = nullptr;
      staticPropLeafLump.m_Memory.m_pMemory = nullptr;
    }
    staticPropLeafLump.m_Memory.m_nAllocationCount = 0;
  }
  staticPropLeafLump.m_pElements = v68;
  if ( staticPropLeafLump.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v68 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v68);
      staticPropLeafLump.m_Memory.m_pMemory = nullptr;
    }
    staticPropLeafLump.m_Memory.m_nAllocationCount = 0;
  }
  if ( staticPropDictionaryLump.m_Memory.m_nGrowSize >= 0 && staticPropDictionaryLump.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: staticPropDictionaryLump.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1006DC60
// Name: private: void CMemoryBSPFile::BuildDisplacementVirtualMesh(class IPhysicsCollision __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::BuildDisplacementVirtualMesh(
        CMemoryBSPFile *this,
        IPhysicsCollision *pPhysicsCollision)
{
  int v3; // ebx
  CCoreDispInfo *v4; // esi
  CCoreDispInfo_vtbl *v5; // eax
  struct CPhysCollide *(__thiscall *CreateVirtualMesh)(IPhysicsCollision *, const virtualmeshparams_t *); // edx
  struct CPhysCollide *v7; // eax
  Vector *m_pMemory; // eax
  unsigned __int16 *v9; // eax
  unsigned __int16 v10; // dx
  int m_nAllocationCount; // eax
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *p_m_PhysicsDisplacementData; // esi
  int v13; // edi
  unsigned __int8 *v14; // ecx
  signed int v15; // eax
  unsigned __int8 *v16; // eax
  unsigned __int8 *v17; // edi
  int v18; // ecx
  int v19; // eax
  bool v20; // zf
  int v21; // eax
  int v22; // edi
  int v23; // edx
  int v24; // ecx
  int v25; // edi
  int v26; // eax
  unsigned __int8 *v27; // ecx
  signed int v28; // eax
  unsigned __int8 *v29; // eax
  unsigned __int8 *v30; // edi
  int v31; // edi
  int v32; // eax
  int m_Size; // [esp-4h] [ebp-94h]
  CSimpleBSPTessellateHelper helper; // [esp+Ch] [ebp-84h] BYREF
  virtualmeshparams_t params; // [esp+28h] [ebp-68h] BYREF
  CSimpleBSPDisplacementMeshEvent meshHandler; // [esp+34h] [ebp-5Ch] BYREF
  int v37; // [esp+54h] [ebp-3Ch]
  int v38; // [esp+58h] [ebp-38h]
  CUtlVector<CPhysCollide *,CUtlMemory<CPhysCollide *,int> > virtualMeshes; // [esp+5Ch] [ebp-34h] BYREF
  int v40; // [esp+70h] [ebp-20h]
  int i; // [esp+74h] [ebp-1Ch]
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > indices; // [esp+78h] [ebp-18h] BYREF
  int nCollideSize; // [esp+8Ch] [ebp-4h]

  v3 = 0;
  m_Size = this->m_DisplacementHelperList.m_Size;
  memset(&virtualMeshes, 0, sizeof(virtualMeshes));
  CUtlVector<CPhysCollide *,CUtlMemory<CPhysCollide *,int>>::InsertMultipleBefore(
    this: &virtualMeshes,
    elem: 0,
    num: m_Size);
  if ( this->m_DisplacementHelperList.m_Size > 0 )
  {
    nCollideSize = 0;
    do
    {
      v4 = this->m_DisplacementHelperList.m_Memory.m_pMemory[v3];
      if ( (*((_BYTE *)&this->m_pMapFile->m_Displacements.m_Memory.m_pMemory->m_ContentsFlags + nCollideSize) & 1) != 0 )
      {
        memset(&indices, 0, sizeof(indices));
        v5 = v4->__vftable;
        helper.m_pIndices = &indices;
        helper.m_pActiveVerts = v4->m_AllowedVerts.m_Ints;
        helper.m_pPowerInfo = v5->GetPowerInfo(this: v4);
        helper.m_nIndices = 0;
        TesselateDisplacement_R<CSimpleBSPTessellateHelper>(
          pHelper: &helper,
          nodeIndex: &helper.m_pPowerInfo->m_RootNode,
          iNodeBitIndex: 0,
          iLevel: 0);
        CSimpleBSPDisplacementMeshEvent::CSimpleBSPDisplacementMeshEvent(
          this: &meshHandler,
          pIndices: indices.m_Memory.m_pMemory,
          nIndexCount: indices.m_Size,
          pDispInfo: v4);
        params.userData = &meshHandler;
        CreateVirtualMesh = pPhysicsCollision->CreateVirtualMesh;
        params.pMeshEventHandler = &meshHandler;
        params.buildOuterHull = true;
        v7 = CreateVirtualMesh(this: pPhysicsCollision, a2: &params);
        virtualMeshes.m_Memory.m_pMemory[v3] = v7;
        m_pMemory = meshHandler.m_Vertices.m_Memory.m_pMemory;
        meshHandler.m_Vertices.m_Size = 0;
        if ( meshHandler.m_Vertices.m_Memory.m_nGrowSize >= 0 )
        {
          if ( meshHandler.m_Vertices.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: meshHandler.m_Vertices.m_Memory.m_pMemory);
            m_pMemory = nullptr;
            meshHandler.m_Vertices.m_Memory.m_pMemory = nullptr;
          }
          meshHandler.m_Vertices.m_Memory.m_nAllocationCount = 0;
        }
        meshHandler.m_Vertices.m_pElements = m_pMemory;
        if ( meshHandler.m_Vertices.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            meshHandler.m_Vertices.m_Memory.m_pMemory = nullptr;
          }
          meshHandler.m_Vertices.m_Memory.m_nAllocationCount = 0;
        }
        v9 = indices.m_Memory.m_pMemory;
        indices.m_Size = 0;
        if ( indices.m_Memory.m_nGrowSize >= 0 )
        {
          if ( indices.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: indices.m_Memory.m_pMemory);
            v9 = nullptr;
            indices.m_Memory.m_pMemory = nullptr;
          }
          indices.m_Memory.m_nAllocationCount = 0;
        }
        indices.m_pElements = v9;
        if ( indices.m_Memory.m_nGrowSize >= 0 && v9 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
      }
      else
      {
        virtualMeshes.m_Memory.m_pMemory[v3] = nullptr;
      }
      nCollideSize += 68;
      ++v3;
    }
    while ( v3 < this->m_DisplacementHelperList.m_Size );
    v3 = 0;
  }
  v10 = this->m_DisplacementHelperList.m_Size;
  m_nAllocationCount = this->m_PhysicsDisplacementData.m_Memory.m_nAllocationCount;
  p_m_PhysicsDisplacementData = &this->m_PhysicsDisplacementData;
  v13 = this->m_PhysicsDisplacementData.m_Size;
  memset(&indices, 0, sizeof(indices));
  LOWORD(nCollideSize) = v10;
  if ( v13 + 2 > m_nAllocationCount )
  {
    CUtlMemory<char,int>::Grow(this: &p_m_PhysicsDisplacementData->m_Memory, num: v13 - m_nAllocationCount + 2);
    v10 = nCollideSize;
  }
  p_m_PhysicsDisplacementData->m_Size += 2;
  v14 = p_m_PhysicsDisplacementData->m_Memory.m_pMemory;
  v15 = p_m_PhysicsDisplacementData->m_Size - v13 - 2;
  p_m_PhysicsDisplacementData->m_pElements = p_m_PhysicsDisplacementData->m_Memory.m_pMemory;
  if ( v15 > 0 )
  {
    _V_memmove(dest: &v14[v13 + 2], src: &v14[v13], count: v15);
    v10 = nCollideSize;
  }
  v16 = &p_m_PhysicsDisplacementData->m_Memory.m_pMemory[v13];
  if ( v16 != nullptr )
    *v16 = v10;
  v17 = &p_m_PhysicsDisplacementData->m_Memory.m_pMemory[v13 + 1];
  if ( v17 != nullptr )
    *v17 = HIBYTE(v10);
  v18 = v10;
  v19 = 0;
  i = 0;
  v40 = v10;
  if ( v10 != 0 )
  {
    while ( 1 )
    {
      v20 = virtualMeshes.m_Memory.m_pMemory[v19] == nullptr;
      nCollideSize = -1;
      if ( !v20 )
      {
        v21 = pPhysicsCollision->CollideSize(this: pPhysicsCollision, a2: virtualMeshes.m_Memory.m_pMemory[v19]);
        nCollideSize = v21;
        if ( v3 < v21 )
        {
          v22 = v21 - v3;
          v23 = v3;
          v37 = v3;
          if ( v21 != v3 )
          {
            v24 = v21;
            v38 = v21;
            if ( v21 > indices.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<char,int>::Grow(
                this: (CUtlMemory<unsigned char,int> *)&indices,
                num: v21 - indices.m_Memory.m_nAllocationCount);
              v3 = indices.m_Size;
              v23 = v37;
              v24 = v38;
            }
            v3 += v22;
            indices.m_pElements = indices.m_Memory.m_pMemory;
            indices.m_Size = v3;
            if ( v3 - v23 - v22 > 0 && v22 > 0 )
              _V_memmove(
                dest: (unsigned __int8 *)indices.m_Memory.m_pMemory + v24,
                src: (unsigned __int8 *)indices.m_Memory.m_pMemory + v23,
                count: v3 - v23 - v22);
          }
        }
      }
      v25 = p_m_PhysicsDisplacementData->m_Size;
      v26 = p_m_PhysicsDisplacementData->m_Memory.m_nAllocationCount;
      if ( v25 + 2 > v26 )
        CUtlMemory<char,int>::Grow(this: &p_m_PhysicsDisplacementData->m_Memory, num: v25 - v26 + 2);
      p_m_PhysicsDisplacementData->m_Size += 2;
      v27 = p_m_PhysicsDisplacementData->m_Memory.m_pMemory;
      v28 = p_m_PhysicsDisplacementData->m_Size - v25 - 2;
      p_m_PhysicsDisplacementData->m_pElements = p_m_PhysicsDisplacementData->m_Memory.m_pMemory;
      if ( v28 > 0 )
        _V_memmove(dest: &v27[v25 + 2], src: &v27[v25], count: v28);
      v29 = &p_m_PhysicsDisplacementData->m_Memory.m_pMemory[v25];
      if ( v29 != nullptr )
        *v29 = nCollideSize;
      v30 = &p_m_PhysicsDisplacementData->m_Memory.m_pMemory[v25 + 1];
      if ( v30 != nullptr )
        *v30 = BYTE1(nCollideSize);
      v18 = v40;
      if ( ++i >= v40 )
        break;
      v19 = i;
    }
  }
  v31 = 0;
  if ( v18 > 0 )
  {
    do
    {
      if ( virtualMeshes.m_Memory.m_pMemory[v31] != nullptr )
      {
        v32 = pPhysicsCollision->CollideWrite(
                this: pPhysicsCollision,
                a2: (char *)indices.m_Memory.m_pMemory,
                a3: virtualMeshes.m_Memory.m_pMemory[v31],
                a4: false);
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::InsertMultipleBefore(
          this: p_m_PhysicsDisplacementData,
          elem: p_m_PhysicsDisplacementData->m_Size,
          num: v32,
          pToInsert: (const unsigned __int8 *)indices.m_Memory.m_pMemory);
      }
      ++v31;
    }
    while ( v31 < v40 );
  }
  if ( indices.m_Memory.m_nGrowSize >= 0 && indices.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: indices.m_Memory.m_pMemory);
  if ( virtualMeshes.m_Memory.m_nGrowSize >= 0 && virtualMeshes.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: virtualMeshes.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1006E000
// Name: private: void CMemoryBSPFile::BuildPhysicsCollisionData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::BuildPhysicsCollisionData(CMemoryBSPFile *this)
{
  void *(__cdecl *PhysicsFactory)(const char *, int *); // eax
  void *(__cdecl *v2)(const char *, int *); // edi
  IPhysicsSurfaceProps *v3; // eax
  IPhysicsSurfaceProps *v4; // edi
  IBaseFileSystem *v5; // eax
  CMemoryBSPFile *v6; // ebx
  int v7; // ecx
  int *p_m_nGrowSize; // eax
  int v9; // esi
  vgui::TreeNode **m_pMemory; // edi
  int v11; // ebx
  CTextBuffer **v12; // ebx
  int v13; // ebx
  CTextBuffer **v14; // ebx
  int v15; // ebx
  CTextBuffer **v16; // ebx
  int v17; // ebx
  CTextBuffer **v18; // ebx
  int v19; // ebx
  int v20; // eax
  vgui::TreeNode ***v21; // esi
  vgui::TreeNode **v22; // edi
  int v23; // eax
  CPhysCollisionEntrySolid **v24; // ebx
  int v25; // ecx
  CTextBuffer *v26; // eax
  int v27; // esi
  CPhysCollisionEntry **v28; // edi
  unsigned int CollisionBinarySize; // eax
  int *v30; // edi
  int v31; // esi
  CTextBuffer *v32; // esi
  int v33; // eax
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *p_m_PhysicsCollideData; // esi
  unsigned __int8 *v35; // edx
  unsigned __int8 *v36; // eax
  CMemoryBSPFile *v37; // edx
  int v38; // ebx
  int v39; // eax
  IPhysicsSurfaceProps *v40; // ebx
  CPhysCollisionEntry **v41; // edi
  unsigned int v42; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  unsigned __int8 *v45; // ecx
  signed int v46; // eax
  int i; // eax
  unsigned __int8 *v48; // ecx
  CPhysCollisionEntry **v49; // edi
  IPhysicsCollision *v50; // ebx
  unsigned int v51; // eax
  int v52; // edi
  int v53; // ebx
  int v54; // eax
  unsigned __int8 *v55; // ecx
  signed int v56; // eax
  unsigned __int8 *v57; // eax
  unsigned __int8 *v58; // edi
  int v59; // edi
  int v60; // ebx
  int v61; // edi
  CPhysCollisionEntry **v62; // edi
  bool v63; // zf
  CTextBuffer *v64; // edi
  bool v65; // sf
  unsigned __int8 *v66; // eax
  int v67; // edi
  int v68; // eax
  unsigned __int8 *v69; // ecx
  signed int v70; // eax
  int j; // eax
  unsigned __int8 *v72; // ecx
  char *v73; // esi
  int k; // edi
  void *v75; // eax
  const char *v76; // [esp-8h] [ebp-8074h]
  int dst[2048]; // [esp+Ch] [ebp-8060h] BYREF
  CTextBuffer *v78[1024]; // [esp+200Ch] [ebp-6060h] BYREF
  CUtlMemory<vgui::TreeNode *,int> v79; // [esp+300Ch] [ebp-5060h] BYREF
  int v80; // [esp+3018h] [ebp-5054h]
  vgui::TreeNode **v81; // [esp+301Ch] [ebp-5050h]
  char v82; // [esp+800Ch] [ebp-60h] BYREF
  CUtlVector<int,CUtlMemory<int,int> > pWorldPropertyRemapList; // [esp+8010h] [ebp-5Ch] BYREF
  int v84; // [esp+8024h] [ebp-48h]
  CUtlMemory<unsigned char,int> v85; // [esp+8028h] [ebp-44h] BYREF
  int v86; // [esp+8034h] [ebp-38h]
  unsigned __int8 *v87; // [esp+8038h] [ebp-34h]
  int v88; // [esp+803Ch] [ebp-30h]
  int v89; // [esp+8040h] [ebp-2Ch]
  int v90; // [esp+8044h] [ebp-28h]
  IPhysicsSurfaceProps *v91; // [esp+8048h] [ebp-24h]
  IPhysicsSurfaceProps *pPhysicsProperties; // [esp+804Ch] [ebp-20h]
  int num; // [esp+8050h] [ebp-1Ch]
  CPhysCollisionEntrySolid *PhysicsModel; // [esp+8054h] [ebp-18h]
  IPhysicsCollision *pPhysicsCollision; // [esp+8058h] [ebp-14h]
  CUtlMemory<vgui::TreeNode *,int> *v96; // [esp+805Ch] [ebp-10h]
  int v97; // [esp+8060h] [ebp-Ch]
  CMemoryBSPFile *v98; // [esp+8064h] [ebp-8h]
  CTextBuffer *v99; // [esp+8068h] [ebp-4h]

  v98 = this;
  PhysicsFactory = GetPhysicsFactory();
  v2 = PhysicsFactory;
  if ( PhysicsFactory != nullptr
    && (pPhysicsCollision = (IPhysicsCollision *)PhysicsFactory(a1: "VPhysicsCollision007", a2: nullptr),
        v3 = (IPhysicsSurfaceProps *)v2(a1: "VPhysicsSurfaceProps001", a2: nullptr),
        v4 = v3,
        pPhysicsProperties = v3,
        pPhysicsCollision != nullptr)
    && v3 != nullptr )
  {
    memset((unsigned __int8 *)dst, value: 0xFFu, count: sizeof(dst));
    if ( g_pFullFileSystem != nullptr )
      v5 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v5 = nullptr;
    v6 = v98;
    LoadSurfaceProperties(pFileSystem: v5, pPhysicsProperties: v4, pMapFile: v98->m_pMapFile, pSurfacePropertyList: dst);
    v7 = 1023;
    p_m_nGrowSize = &v79.m_nGrowSize;
    do
    {
      *(p_m_nGrowSize - 2) = 0;
      *(p_m_nGrowSize - 1) = 0;
      *p_m_nGrowSize = 0;
      p_m_nGrowSize[1] = 0;
      p_m_nGrowSize[2] = 0;
      p_m_nGrowSize += 5;
      --v7;
    }
    while ( v7 >= 0 );
    num = 0;
    v96 = nullptr;
    memset(&pWorldPropertyRemapList, 0, sizeof(pWorldPropertyRemapList));
    v97 = 0;
    if ( v6->m_ModelList.m_Size > 0 )
    {
      v9 = v80;
      m_pMemory = v79.m_pMemory;
      do
      {
        if ( v97 != 0 )
        {
          PhysicsModel = CMemoryBSPFile::CreatePhysicsModel(
                           this: v98,
                           a2: (int)v6,
                           a3: (int)m_pMemory,
                           a4: v9,
                           pPhysicsCollision,
                           pPhysicsProperties,
                           pSurfacePropertyList: dst,
                           pModel: &v98->m_ModelList.m_Memory.m_pMemory[v97]);
          if ( PhysicsModel != nullptr )
          {
            v19 = *(&v80 + 5 * v97);
            v20 = *(&v79.m_nAllocationCount + 5 * v97);
            v21 = &v79.m_pMemory + 5 * v97;
            if ( v19 + 1 > v20 )
              CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)((char *)&v79 + 20 * v97),
                num: v19 - v20 + 1);
            v21[3] = (vgui::TreeNode **)((char *)v21[3] + 1);
            v22 = *v21;
            v23 = (int)v21[3] - v19 - 1;
            v21[4] = *v21;
            if ( v23 > 0 )
              _V_memmove(dest: (unsigned __int8 *)&v22[v19 + 1], src: (unsigned __int8 *)&v22[v19], count: 4 * v23);
            v9 = v80;
            v24 = (CPhysCollisionEntrySolid **)&v22[v19];
            m_pMemory = v79.m_pMemory;
            if ( v24 != nullptr )
              *v24 = PhysicsModel;
          }
        }
        else
        {
          v99 = (CTextBuffer *)CMemoryBSPFile::CreateWorldPhysicsModels(
                                 this: v98,
                                 a2: v9,
                                 pPhysicsCollision,
                                 &pWorldPropertyRemapList,
                                 pSurfacePropertyList: dst,
                                 pModel: v98->m_ModelList.m_Memory.m_pMemory,
                                 contentsMask: 33570819);
          if ( v99 != nullptr )
          {
            v11 = v9;
            if ( v9 + 1 > v79.m_nAllocationCount )
            {
              CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
                this: &v79,
                num: v9 - v79.m_nAllocationCount + 1);
              v9 = v80;
              m_pMemory = v79.m_pMemory;
            }
            v80 = ++v9;
            v81 = m_pMemory;
            if ( v9 - v11 - 1 > 0 )
              _V_memmove(
                dest: (unsigned __int8 *)&m_pMemory[v11 + 1],
                src: (unsigned __int8 *)&m_pMemory[v11],
                count: 4 * (v9 - v11 - 1));
            v12 = (CTextBuffer **)&m_pMemory[v11];
            if ( v12 != nullptr )
              *v12 = v99;
          }
          v99 = (CTextBuffer *)CMemoryBSPFile::CreateWorldPhysicsModels(
                                 this: v98,
                                 a2: v9,
                                 pPhysicsCollision,
                                 &pWorldPropertyRemapList,
                                 pSurfacePropertyList: dst,
                                 pModel: v98->m_ModelList.m_Memory.m_pMemory,
                                 contentsMask: 8);
          if ( v99 != nullptr )
          {
            v13 = v9;
            if ( v9 + 1 > v79.m_nAllocationCount )
            {
              CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
                this: &v79,
                num: v9 - v79.m_nAllocationCount + 1);
              v9 = v80;
              m_pMemory = v79.m_pMemory;
            }
            v80 = ++v9;
            v81 = m_pMemory;
            if ( v9 - v13 - 1 > 0 )
              _V_memmove(
                dest: (unsigned __int8 *)&m_pMemory[v13 + 1],
                src: (unsigned __int8 *)&m_pMemory[v13],
                count: 4 * (v9 - v13 - 1));
            v14 = (CTextBuffer **)&m_pMemory[v13];
            if ( v14 != nullptr )
              *v14 = v99;
          }
          v99 = (CTextBuffer *)CMemoryBSPFile::CreateWorldPhysicsModels(
                                 this: v98,
                                 a2: v9,
                                 pPhysicsCollision,
                                 &pWorldPropertyRemapList,
                                 pSurfacePropertyList: dst,
                                 pModel: v98->m_ModelList.m_Memory.m_pMemory,
                                 contentsMask: 0x10000);
          if ( v99 != nullptr )
          {
            v15 = v9;
            if ( v9 + 1 > v79.m_nAllocationCount )
            {
              CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
                this: &v79,
                num: v9 - v79.m_nAllocationCount + 1);
              v9 = v80;
              m_pMemory = v79.m_pMemory;
            }
            v80 = ++v9;
            v81 = m_pMemory;
            if ( v9 - v15 - 1 > 0 )
              _V_memmove(
                dest: (unsigned __int8 *)&m_pMemory[v15 + 1],
                src: (unsigned __int8 *)&m_pMemory[v15],
                count: 4 * (v9 - v15 - 1));
            v16 = (CTextBuffer **)&m_pMemory[v15];
            if ( v16 != nullptr )
              *v16 = v99;
          }
          v99 = (CTextBuffer *)CMemoryBSPFile::CreateWorldPhysicsModels(
                                 this: v98,
                                 a2: v9,
                                 pPhysicsCollision,
                                 &pWorldPropertyRemapList,
                                 pSurfacePropertyList: dst,
                                 pModel: v98->m_ModelList.m_Memory.m_pMemory,
                                 contentsMask: 0x20000);
          if ( v99 != nullptr )
          {
            v17 = v9;
            if ( v9 + 1 > v79.m_nAllocationCount )
            {
              CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
                this: &v79,
                num: v9 - v79.m_nAllocationCount + 1);
              v9 = v80;
              m_pMemory = v79.m_pMemory;
            }
            v80 = ++v9;
            v81 = m_pMemory;
            if ( v9 - v17 - 1 > 0 )
              _V_memmove(
                dest: (unsigned __int8 *)&m_pMemory[v17 + 1],
                src: (unsigned __int8 *)&m_pMemory[v17],
                count: 4 * (v9 - v17 - 1));
            v18 = (CTextBuffer **)&m_pMemory[v17];
            if ( v18 != nullptr )
              *v18 = v99;
          }
          CMemoryBSPFile::BuildDisplacementVirtualMesh(this: v98, pPhysicsCollision);
        }
        v25 = v97;
        PhysicsModel = (CPhysCollisionEntrySolid *)&v78[v97];
        PhysicsModel->__vftable = nullptr;
        v6 = (CMemoryBSPFile *)*(&v80 + 5 * v25);
        v84 = 20 * v25;
        if ( v6 != nullptr )
        {
          v26 = (CTextBuffer *)operator new(nSize: 0x14u);
          v27 = 0;
          if ( v26 != nullptr )
          {
            v26->m_Buffer.m_Memory.m_pMemory = nullptr;
            v26->m_Buffer.m_Memory.m_nAllocationCount = 0;
            v26->m_Buffer.m_Memory.m_nGrowSize = 0;
            v26->m_Buffer.m_Size = 0;
            v26->m_Buffer.m_pElements = nullptr;
          }
          else
          {
            v26 = nullptr;
          }
          v99 = v26;
          PhysicsModel->__vftable = (CPhysCollisionEntrySolid_vtbl *)v26;
          if ( (int)v6 > 0 )
          {
            v28 = *(CPhysCollisionEntry ***)((char *)&v79.m_pMemory + v84);
            do
            {
              (*v28)->WriteToTextBuffer(this: *v28, a2: v99, a3: v27);
              CollisionBinarySize = CPhysCollisionEntry::GetCollisionBinarySize(this: *v28, pPhysicsCollision);
              ++v27;
              ++v28;
              v96 = (CUtlMemory<vgui::TreeNode *,int> *)((char *)v96 + CollisionBinarySize + 4);
            }
            while ( v27 < (int)v6 );
          }
          if ( v97 == 0 )
          {
            v6 = (CMemoryBSPFile *)v78[0];
            CTextBuffer::WriteText(this: v78[0], pText: "virtualterrain {}\n");
            if ( pWorldPropertyRemapList.m_Size > 0 )
            {
              CTextBuffer::WriteText(this: (CTextBuffer *)v6, pText: "materialtable {\n");
              v30 = pWorldPropertyRemapList.m_Memory.m_pMemory;
              v31 = 1;
              PhysicsModel = (CPhysCollisionEntrySolid *)pWorldPropertyRemapList.m_Size;
              do
              {
                if ( *v30 >= 0 )
                {
                  v76 = pPhysicsProperties->GetPropName(this: pPhysicsProperties, a2: *v30);
                  CTextBuffer::WriteIntKey(this: (CTextBuffer *)v6, pKeyName: v76, nOutputData: v31);
                }
                else
                {
                  CTextBuffer::WriteIntKey(this: (CTextBuffer *)v6, pKeyName: "default", nOutputData: v31);
                }
                ++v30;
                ++v31;
                PhysicsModel = (CPhysCollisionEntrySolid *)((char *)PhysicsModel - 1);
              }
              while ( PhysicsModel != nullptr );
              CTextBuffer::WriteText(this: (CTextBuffer *)v6, pText: "}\n");
            }
          }
          v32 = v99;
          CTextBuffer::Terminate(this: v99);
          v96 = (CUtlMemory<vgui::TreeNode *,int> *)((char *)v96 + v32->m_Buffer.m_Size);
          ++num;
          m_pMemory = v79.m_pMemory;
          v9 = v80;
          v25 = v97;
        }
        v97 = v25 + 1;
      }
      while ( v25 + 1 < v98->m_ModelList.m_Size );
    }
    v33 = (int)(&v96[1].m_nAllocationCount + 4 * num);
    p_m_PhysicsCollideData = &v98->m_PhysicsCollideData;
    memset(&v85, 0, sizeof(v85));
    v86 = 0;
    v87 = nullptr;
    if ( v98->m_PhysicsCollideData.m_Memory.m_nAllocationCount < v33
      && v98->m_PhysicsCollideData.m_Memory.m_nGrowSize >= 0 )
    {
      v35 = p_m_PhysicsCollideData->m_Memory.m_pMemory;
      v98->m_PhysicsCollideData.m_Memory.m_nAllocationCount = v33;
      if ( v35 != nullptr )
        v36 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v35, a3: v33);
      else
        v36 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v33);
      p_m_PhysicsCollideData->m_Memory.m_pMemory = v36;
    }
    v37 = v98;
    v38 = 0;
    p_m_PhysicsCollideData->m_pElements = p_m_PhysicsCollideData->m_Memory.m_pMemory;
    v97 = 0;
    if ( v37->m_ModelList.m_Size > 0 )
    {
      v96 = &v79;
      do
      {
        if ( v78[v38] != nullptr )
        {
          v39 = (int)v96[1].m_pMemory;
          v88 = v38;
          v91 = (IPhysicsSurfaceProps *)v39;
          v89 = 4 * v39;
          if ( v39 > 0 )
          {
            v40 = v91;
            v41 = (CPhysCollisionEntry **)v96->m_pMemory;
            do
            {
              v42 = CPhysCollisionEntry::GetCollisionBinarySize(this: *v41, pPhysicsCollision);
              v89 += v42;
              ++v41;
              v40 = (IPhysicsSurfaceProps *)((char *)v40 - 1);
            }
            while ( v40 != nullptr );
            v38 = v97;
          }
          m_Size = p_m_PhysicsCollideData->m_Size;
          m_nAllocationCount = p_m_PhysicsCollideData->m_Memory.m_nAllocationCount;
          v90 = v78[v38]->m_Buffer.m_Size;
          if ( m_Size + 16 > m_nAllocationCount )
            CUtlMemory<char,int>::Grow(this: &p_m_PhysicsCollideData->m_Memory, num: m_Size - m_nAllocationCount + 16);
          p_m_PhysicsCollideData->m_Size += 16;
          v45 = p_m_PhysicsCollideData->m_Memory.m_pMemory;
          v46 = p_m_PhysicsCollideData->m_Size - m_Size - 16;
          p_m_PhysicsCollideData->m_pElements = p_m_PhysicsCollideData->m_Memory.m_pMemory;
          if ( v46 > 0 )
            _V_memmove(dest: &v45[m_Size + 16], src: &v45[m_Size], count: v46);
          for ( i = 0; i < 16; i += 4 )
          {
            v48 = &p_m_PhysicsCollideData->m_Memory.m_pMemory[i + m_Size];
            if ( v48 != nullptr )
              *v48 = *((_BYTE *)&v88 + i);
            if ( &p_m_PhysicsCollideData->m_Memory.m_pMemory[i + m_Size] != (unsigned __int8 *)-1 )
              p_m_PhysicsCollideData->m_Memory.m_pMemory[i + 1 + m_Size] = *((_BYTE *)&v88 + i + 1);
            if ( &p_m_PhysicsCollideData->m_Memory.m_pMemory[i + m_Size] != (unsigned __int8 *)-2 )
              p_m_PhysicsCollideData->m_Memory.m_pMemory[i + 2 + m_Size] = *((_BYTE *)&v88 + i + 2);
            if ( &p_m_PhysicsCollideData->m_Memory.m_pMemory[i + m_Size] != (unsigned __int8 *)-3 )
              p_m_PhysicsCollideData->m_Memory.m_pMemory[i + 3 + m_Size] = *((_BYTE *)&v88 + i + 3);
          }
          if ( (int)v91 > 0 )
          {
            v49 = (CPhysCollisionEntry **)v96->m_pMemory;
            v50 = pPhysicsCollision;
            PhysicsModel = (CPhysCollisionEntrySolid *)v96->m_pMemory;
            pPhysicsProperties = v91;
            do
            {
              v51 = CPhysCollisionEntry::GetCollisionBinarySize(this: *v49, pPhysicsCollision: v50);
              v52 = p_m_PhysicsCollideData->m_Size;
              v53 = v51;
              v54 = p_m_PhysicsCollideData->m_Memory.m_nAllocationCount;
              num = v53;
              if ( v52 + 4 > v54 )
                CUtlMemory<char,int>::Grow(this: &p_m_PhysicsCollideData->m_Memory, num: v52 - v54 + 4);
              p_m_PhysicsCollideData->m_Size += 4;
              v55 = p_m_PhysicsCollideData->m_Memory.m_pMemory;
              v56 = p_m_PhysicsCollideData->m_Size - v52 - 4;
              p_m_PhysicsCollideData->m_pElements = p_m_PhysicsCollideData->m_Memory.m_pMemory;
              if ( v56 > 0 )
                _V_memmove(dest: &v55[v52 + 4], src: &v55[v52], count: v56);
              v57 = &p_m_PhysicsCollideData->m_Memory.m_pMemory[v52];
              if ( v57 != nullptr )
                *v57 = v53;
              if ( &p_m_PhysicsCollideData->m_Memory.m_pMemory[v52] != (unsigned __int8 *)-1 )
                p_m_PhysicsCollideData->m_Memory.m_pMemory[v52 + 1] = BYTE1(v53);
              if ( &p_m_PhysicsCollideData->m_Memory.m_pMemory[v52] != (unsigned __int8 *)-2 )
                p_m_PhysicsCollideData->m_Memory.m_pMemory[v52 + 2] = BYTE2(num);
              v58 = &p_m_PhysicsCollideData->m_Memory.m_pMemory[v52 + 3];
              if ( v58 != nullptr )
                *v58 = HIBYTE(num);
              if ( v86 < v53 )
              {
                v59 = v53;
                v60 = v86;
                v61 = v59 - v86;
                if ( v61 != 0 )
                {
                  v84 = v61 + v86;
                  if ( v61 + v86 > v85.m_nAllocationCount )
                    CUtlMemory<char,int>::Grow(this: &v85, num: v61 + v86 - v85.m_nAllocationCount);
                  v86 += v61;
                  v87 = v85.m_pMemory;
                  if ( v86 - v60 - v61 > 0 && v61 > 0 )
                    _V_memmove(dest: &v85.m_pMemory[v84], src: &v85.m_pMemory[v60], count: v86 - v60 - v61);
                }
              }
              v50 = pPhysicsCollision;
              v62 = (CPhysCollisionEntry **)PhysicsModel;
              CPhysCollisionEntry::WriteCollisionBinary(
                this: (CPhysCollisionEntry *)PhysicsModel->__vftable,
                pPhysicsCollision,
                pDest: v85.m_pMemory);
              CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::InsertMultipleBefore(
                this: p_m_PhysicsCollideData,
                elem: p_m_PhysicsCollideData->m_Size,
                num,
                pToInsert: v85.m_pMemory);
              CPhysCollisionEntry::Cleanup(this: *v62, pPhysicsCollision: v50);
              if ( *v62 != nullptr )
                ((void (__thiscall *)(CPhysCollisionEntry *, int))(*v62)->dtr_CPhysCollisionEntry)(a1: *v62, a2: 1);
              v49 = v62 + 1;
              v63 = pPhysicsProperties == (IPhysicsSurfaceProps *)1;
              pPhysicsProperties = (IPhysicsSurfaceProps *)((char *)pPhysicsProperties - 1);
              PhysicsModel = (CPhysCollisionEntrySolid *)v49;
            }
            while ( !v63 );
          }
          v64 = v78[v97];
          CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::InsertMultipleBefore(
            this: p_m_PhysicsCollideData,
            elem: p_m_PhysicsCollideData->m_Size,
            num: v64->m_Buffer.m_Size,
            pToInsert: (const unsigned __int8 *)v64->m_Buffer.m_Memory.m_pMemory);
          v38 = v97;
          if ( v64 != nullptr )
          {
            v65 = v64->m_Buffer.m_Memory.m_nGrowSize < 0;
            v64->m_Buffer.m_Size = 0;
            if ( !v65 )
            {
              if ( v64->m_Buffer.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v64->m_Buffer.m_Memory.m_pMemory);
                v64->m_Buffer.m_Memory.m_pMemory = nullptr;
              }
              v64->m_Buffer.m_Memory.m_nAllocationCount = 0;
            }
            v65 = v64->m_Buffer.m_Memory.m_nGrowSize < 0;
            v66 = (unsigned __int8 *)v64->m_Buffer.m_Memory.m_pMemory;
            v64->m_Buffer.m_pElements = v64->m_Buffer.m_Memory.m_pMemory;
            if ( !v65 )
            {
              if ( v66 != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v66);
                v64->m_Buffer.m_Memory.m_pMemory = nullptr;
              }
              v64->m_Buffer.m_Memory.m_nAllocationCount = 0;
            }
            free(pMem: v64);
          }
        }
        v96 = (CUtlMemory<vgui::TreeNode *,int> *)((char *)v96 + 20);
        v97 = ++v38;
      }
      while ( v38 < v98->m_ModelList.m_Size );
    }
    v67 = p_m_PhysicsCollideData->m_Size;
    v88 = -1;
    v89 = -1;
    v90 = 0;
    v91 = nullptr;
    v68 = p_m_PhysicsCollideData->m_Memory.m_nAllocationCount;
    if ( v67 + 16 > v68 )
      CUtlMemory<char,int>::Grow(this: &p_m_PhysicsCollideData->m_Memory, num: v67 - v68 + 16);
    p_m_PhysicsCollideData->m_Size += 16;
    v69 = p_m_PhysicsCollideData->m_Memory.m_pMemory;
    v70 = p_m_PhysicsCollideData->m_Size - v67 - 16;
    p_m_PhysicsCollideData->m_pElements = p_m_PhysicsCollideData->m_Memory.m_pMemory;
    if ( v70 > 0 )
      _V_memmove(dest: &v69[v67 + 16], src: &v69[v67], count: v70);
    for ( j = 0; j < 16; j += 4 )
    {
      v72 = &p_m_PhysicsCollideData->m_Memory.m_pMemory[j + v67];
      if ( v72 != nullptr )
        *v72 = *((_BYTE *)&v88 + j);
      if ( &p_m_PhysicsCollideData->m_Memory.m_pMemory[j + v67] != (unsigned __int8 *)-1 )
        p_m_PhysicsCollideData->m_Memory.m_pMemory[j + 1 + v67] = *((_BYTE *)&v88 + j + 1);
      if ( &p_m_PhysicsCollideData->m_Memory.m_pMemory[j + v67] != (unsigned __int8 *)-2 )
        p_m_PhysicsCollideData->m_Memory.m_pMemory[j + 2 + v67] = *((_BYTE *)&v88 + j + 2);
      if ( &p_m_PhysicsCollideData->m_Memory.m_pMemory[j + v67] != (unsigned __int8 *)-3 )
        p_m_PhysicsCollideData->m_Memory.m_pMemory[j + 3 + v67] = *((_BYTE *)&v88 + j + 3);
    }
    if ( v85.m_nGrowSize >= 0 && v85.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v85.m_pMemory);
    if ( pWorldPropertyRemapList.m_Memory.m_nGrowSize >= 0 && pWorldPropertyRemapList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pWorldPropertyRemapList.m_Memory.m_pMemory);
    v73 = &v82;
    for ( k = 1023; k >= 0; --k )
    {
      v73 -= 20;
      *((_DWORD *)v73 + 3) = 0;
      if ( *((int *)v73 + 2) >= 0 )
      {
        if ( *(_DWORD *)v73 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v73);
          *(_DWORD *)v73 = 0;
        }
        *((_DWORD *)v73 + 1) = 0;
      }
      v75 = *(void **)v73;
      *((_DWORD *)v73 + 4) = *(_DWORD *)v73;
      if ( *((int *)v73 + 2) >= 0 )
      {
        if ( v75 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v75);
          *(_DWORD *)v73 = 0;
        }
        *((_DWORD *)v73 + 1) = 0;
      }
    }
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
  {
    _LoggingSystem_Log(
      a1: LOG_VBSP2,
      a2: 3,
      a3: "Cannot instantiate necessary physics interfaces to build collision data.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1006E9D0
// Name: public: void CMemoryBSPFile::ProcessAndSerialize(class CUtlBuffer __near *,class CSimpleBSPFile const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::ProcessAndSerialize(
        CMemoryBSPFile *this,
        CUtlBuffer *pOutputBuffer,
        const CSimpleBSPFile *pSimpleBSPFile)
{
  CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *v4; // eax
  int *m_HashTable; // eax
  int i; // edx
  const CSimpleMapFile *m_pMapFile; // ecx
  int m_nMapRevision; // edx
  CUtlBuffer *m_pSerialBuffer; // ecx
  CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int> > *p_m_TexInfoList; // edi
  CUtlVector<dplane_t,CUtlMemory<dplane_t,int> > *p_m_Planes; // edi
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *p_m_GameLumpData; // edi
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *p_m_EntityData; // edi
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *p_m_VisibilityData; // edi
  int pData; // [esp+Ch] [ebp-1Ch] BYREF
  __int64 v16; // [esp+10h] [ebp-18h]
  int v17; // [esp+18h] [ebp-10h]
  __int16 v18; // [esp+1Ch] [ebp-Ch] BYREF
  __int64 v19; // [esp+1Eh] [ebp-Ah]
  __int16 v20; // [esp+26h] [ebp-2h]
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  this->m_pSerialBuffer = pOutputBuffer;
  CUtlBuffer::SeekPut(this: pOutputBuffer, type: SEEK_HEAD, offset: 0);
  this->m_pSimpleBSPFile = pSimpleBSPFile;
  this->m_pMapFile = pSimpleBSPFile->m_pMapFile;
  if ( pSimpleBSPFile == (const CSimpleBSPFile *)-4 )
    v4 = nullptr;
  else
    v4 = &pSimpleBSPFile->m_PlaneHash.m_Planes.CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> >;
  CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int>>::operator=(
    this: &this->m_PlaneHash.m_Planes.CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> >,
    other: v4);
  m_HashTable = this->m_PlaneHash.m_HashTable;
  for ( i = 1024; i != 0; --i )
  {
    *m_HashTable = *(int *)((char *)m_HashTable + (char *)&pSimpleBSPFile->m_PlaneHash - (char *)&this->m_PlaneHash);
    ++m_HashTable;
  }
  m_pMapFile = this->m_pMapFile;
  this->m_FileHeader.ident = 1347633750;
  this->m_FileHeader.m_nVersion = 21;
  m_nMapRevision = m_pMapFile->m_nMapRevision;
  m_pSerialBuffer = this->m_pSerialBuffer;
  this->m_FileHeader.mapRevision = m_nMapRevision;
  CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&this->m_FileHeader, size: 1036);
  CMemoryBSPFile::BuildTexInfo(this);
  p_m_TexInfoList = &this->m_TexInfoList;
  CMemoryBSPFile::WriteLump<texinfo_s>(this, nLump: 6, data: &this->m_TexInfoList, nVersion: 0);
  this->m_TexInfoList.m_Size = 0;
  if ( this->m_TexInfoList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_TexInfoList->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_TexInfoList->m_Memory.m_pMemory);
      p_m_TexInfoList->m_Memory.m_pMemory = nullptr;
    }
    this->m_TexInfoList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_TexInfoList.m_pElements = this->m_TexInfoList.m_Memory.m_pMemory;
  CMemoryBSPFile::BuildTexData(this);
  CMemoryBSPFile::WriteTexData(this, bPurgeWhenComplete: true);
  CMemoryBSPFile::BuildModelData(this);
  CMemoryBSPFile::WriteModelData(this, bPurgeWhenComplete: true);
  CMemoryBSPFile::BuildBSPTreeData(this);
  CMemoryBSPFile::WriteBSPTreeData(this, bPurgeWhenComplete: true);
  CMemoryBSPFile::BuildBrushes(this);
  CMemoryBSPFile::WriteBrushes(this, bPurgeWhenComplete: true);
  CMemoryBSPFile::BuildPlanes(this);
  p_m_Planes = &this->m_Planes;
  CMemoryBSPFile::WriteLump<dplane_t>(
    this,
    nLump: 1,
    data: (const CUtlVector<CDispVert,CUtlMemory<CDispVert,int> > *)&this->m_Planes,
    nVersion: 0);
  this->m_Planes.m_Size = 0;
  if ( this->m_Planes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Planes->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Planes->m_Memory.m_pMemory);
      p_m_Planes->m_Memory.m_pMemory = nullptr;
    }
    this->m_Planes.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Planes.m_pElements = p_m_Planes->m_Memory.m_pMemory;
  CMemoryBSPFile::WriteLump<dmodel_t>(this, nLump: 14, data: &this->m_ModelList, nVersion: 0);
  v19 = 0;
  v18 = 0;
  v20 = 0;
  pData = 0;
  v16 = 0;
  v17 = 1;
  CMemoryBSPFile::WriteLump(this, nLump: 20, (unsigned __int8 *)&pData, nByteLength: 16, nVersion: 0);
  CMemoryBSPFile::WriteLump(this, nLump: 21, pData: (unsigned __int8 *)&v18, nByteLength: 12, nVersion: 0);
  CMemoryBSPFile::BuildGameLumpData(this);
  p_m_GameLumpData = &this->m_GameLumpData;
  CMemoryBSPFile::WriteLump<char>(
    this,
    nLump: 35,
    data: (const CUtlVector<char,CUtlMemory<char,int> > *)&this->m_GameLumpData,
    nVersion: 0);
  this->m_GameLumpData.m_Size = 0;
  if ( this->m_GameLumpData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_GameLumpData->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_GameLumpData->m_Memory.m_pMemory);
      p_m_GameLumpData->m_Memory.m_pMemory = nullptr;
    }
    this->m_GameLumpData.m_Memory.m_nAllocationCount = 0;
  }
  this->m_GameLumpData.m_pElements = this->m_GameLumpData.m_Memory.m_pMemory;
  CMemoryBSPFile::BuildEntityData(this);
  p_m_EntityData = &this->m_EntityData;
  CMemoryBSPFile::WriteLump<char>(
    this,
    nLump: 0,
    data: (const CUtlVector<char,CUtlMemory<char,int> > *)&this->m_EntityData,
    nVersion: 0);
  this->m_EntityData.m_Size = 0;
  if ( this->m_EntityData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_EntityData->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_EntityData->m_Memory.m_pMemory);
      p_m_EntityData->m_Memory.m_pMemory = nullptr;
    }
    this->m_EntityData.m_Memory.m_nAllocationCount = 0;
  }
  this->m_EntityData.m_pElements = this->m_EntityData.m_Memory.m_pMemory;
  CMemoryBSPFile::BuildVisibilityData(this);
  p_m_VisibilityData = &this->m_VisibilityData;
  CMemoryBSPFile::WriteLump<char>(
    this,
    nLump: 4,
    data: (const CUtlVector<char,CUtlMemory<char,int> > *)&this->m_VisibilityData,
    nVersion: 0);
  this->m_VisibilityData.m_Size = 0;
  if ( this->m_VisibilityData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_VisibilityData->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_VisibilityData->m_Memory.m_pMemory);
      p_m_VisibilityData->m_Memory.m_pMemory = nullptr;
    }
    this->m_VisibilityData.m_Memory.m_nAllocationCount = 0;
  }
  this->m_VisibilityData.m_pElements = this->m_VisibilityData.m_Memory.m_pMemory;
  CMemoryBSPFile::BuildDisplacements(this, a2: COERCE_FLOAT(&savedregs));
  CMemoryBSPFile::WriteDisplacements(this, bPurgeWhenComplete: true);
  CMemoryBSPFile::BuildPhysicsCollisionData(this);
  CMemoryBSPFile::WritePhysicsCollisionData(this, bPurgeWhenComplete: true);
  CMemoryBSPFile::WriteLightingData(this, bPurgeWhenComplete: true);
  CUtlBuffer::SeekPut(this: this->m_pSerialBuffer, type: SEEK_HEAD, offset: 0);
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)&this->m_FileHeader, size: 1036);
}

//------------------------------------------------------------------------------
// Address: 0x1006EC90
// Name: void SaveToFile(class CUtlBuffer __near *,class CSimpleBSPFile const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SaveToFile(CUtlBuffer *pOutputBuffer, const CSimpleBSPFile *pBSPFile)
{
  CMemoryBSPFile v2; // [esp+0h] [ebp-11EB0h] BYREF

  CMemoryBSPFile::CMemoryBSPFile(this: &v2);
  CMemoryBSPFile::ProcessAndSerialize(this: &v2, pOutputBuffer, pSimpleBSPFile: pBSPFile);
  CMemoryBSPFile::~CMemoryBSPFile(this: &v2);
}

// ============================================================
// Overlay from vbsp2 (Missing functions)
// ============================================================
namespace vbsp2 {

//------------------------------------------------------------------------------
// Address: 0x00412AA0
// Name: void Vector2DCopy(class Vector2D const __near &,class Vector2D __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Vector2DCopy(const Vector2D *src, Vector2D *dst)
{
  *dst = *src;
}

//------------------------------------------------------------------------------
// Address: 0x00412AC0
// Name: public: class Vector4D __near & Vector4D::operator=(class Vector4D const __near &)
// Source: json
//------------------------------------------------------------------------------
Vector4D *__thiscall Vector4D::operator=(Vector4D *this, const Vector4D *vOther)
{
  *this = *vOther;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00412AF0
// Name: public: class CCoreDispSurface __near * CCoreDispInfo::GetSurface(void)
// Source: json
//------------------------------------------------------------------------------
CCoreDispSurface *__thiscall CCoreDispInfo::GetSurface(CCoreDispInfo *this)
{
  return &this->m_Surf;
}

//------------------------------------------------------------------------------
// Address: 0x00412B00
// Name: private: void CMemoryBSPFile::WriteLump(int,void const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump(
        CMemoryBSPFile *this,
        int nLump,
        unsigned __int8 *pData,
        int nByteLength,
        int nVersion)
{
  int v6; // ecx
  int v7; // eax
  int v8; // edx
  int v9; // ecx
  CUtlBuffer *m_pSerialBuffer; // ecx
  int m_Put; // edi
  int v12; // eax

  v6 = nLump;
  v7 = nLump;
  this->m_FileHeader.lumps[v7].fileofs = this->m_pSerialBuffer->m_Put;
  v8 = v6 + 259;
  v9 = nByteLength;
  *((_DWORD *)&this->m_pSerialBuffer + 4 * v8) = nByteLength;
  this->m_FileHeader.lumps[v7].version = nVersion;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: pData, size: v9);
  m_pSerialBuffer = this->m_pSerialBuffer;
  m_Put = this->m_pSerialBuffer->m_Put;
  v12 = 4 * ((m_Put + 3) / 4);
  if ( v12 > m_Put )
  {
    LOBYTE(nLump) = 0;
    *(_WORD *)((char *)&nLump + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&nLump, size: v12 - m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413280
// Name: public: bool CMemoryBSPFile::TryGetFaceVertex(int,int,class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CMemoryBSPFile::TryGetFaceVertex(CMemoryBSPFile *this, int nFace, int nVertexIndex, Vector *pPosition)
{
  dface_t *v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // edx
  int v8; // eax
  Vector *m_pMemory; // ecx
  int v10; // eax
  double x; // st7
  Vector *v12; // eax
  double z; // st7

  if ( nFace < 0 )
    return 0;
  if ( nFace >= this->m_FaceList.m_Size )
    return 0;
  v4 = &this->m_FaceList.m_Memory.m_pMemory[nFace];
  if ( nVertexIndex < 0 )
    return 0;
  if ( nVertexIndex >= v4->numedges )
    return 0;
  v5 = nVertexIndex + v4->firstedge;
  if ( v5 < 0 )
    return 0;
  if ( v5 >= this->m_SurfEdgeList.m_Size )
    return 0;
  v6 = this->m_SurfEdgeList.m_Memory.m_pMemory[v5];
  v7 = 0;
  if ( v6 < 0 )
  {
    v6 = -v6;
    v7 = 1;
    if ( v6 < 0 )
      return 0;
  }
  if ( v6 >= this->m_EdgeList.m_Size )
    return 0;
  v8 = this->m_EdgeList.m_Memory.m_pMemory[v6].v[v7];
  if ( v8 >= this->m_VertexHash.m_Vertices.m_Size )
    return 0;
  m_pMemory = this->m_VertexHash.m_Vertices.m_Memory.m_pMemory;
  v10 = v8;
  x = m_pMemory[v10].x;
  v12 = &m_pMemory[v10];
  pPosition->x = x;
  pPosition->y = v12->y;
  z = v12->z;
  pPosition->z = z;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00413340
// Name: public: int CMemoryBSPFile::GetLeafIndexFromPoint(int,class Vector const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMemoryBSPFile::GetLeafIndexFromPoint(CMemoryBSPFile *this, int nNodeIndex, const Vector *vPosition)
{
  int v4; // ecx
  dnode_t *v5; // esi
  dplane_t *m_pMemory; // ecx
  float v7; // xmm0_4
  int result; // eax

  v4 = nNodeIndex;
  while ( v4 >= 0 )
  {
    v5 = &this->m_NodeList.m_Memory.m_pMemory[v4];
    m_pMemory = this->m_Planes.m_Memory.m_pMemory;
    v7 = (float)((float)((float)(m_pMemory[v5->planenum].normal.y * vPosition->y)
                       + (float)(m_pMemory[v5->planenum].normal.x * vPosition->x))
               + (float)(m_pMemory[v5->planenum].normal.z * vPosition->z))
       - m_pMemory[v5->planenum].dist;
    if ( v7 <= 0.1 )
    {
      if ( v7 >= -0.1 )
      {
        result = CMemoryBSPFile::GetLeafIndexFromPoint(this, nNodeIndex: v5->children[0], vPosition);
        if ( this->m_LeafList.m_Memory.m_pMemory[result].cluster != -1 )
          return result;
      }
      v4 = v5->children[1];
    }
    else
    {
      v4 = v5->children[0];
    }
  }
  return -1 - v4;
}

//------------------------------------------------------------------------------
// Address: 0x00413400
// Name: private: struct MapBrushSide_t const __near * CMemoryBSPFile::FindClosestBrushSide(int,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
const MapBrushSide_t *__thiscall CMemoryBSPFile::FindClosestBrushSide(
        CMemoryBSPFile *this,
        const MapBrushSide_t *nBrushIndex,
        const Vector *vNormal)
{
  const CSimpleMapFile *m_pMapFile; // edx
  float v4; // xmm0_4
  int v6; // esi
  int v7; // eax
  int v8; // edi
  HashedPlane_t *m_pMemory; // ecx
  float y; // xmm2_4
  float x; // xmm3_4
  float z; // xmm4_4
  int v13; // edx
  const MapBrushSide_t *v14; // esi
  _DWORD *v15; // edi
  unsigned int v16; // edx
  int v17; // ecx
  int v18; // eax
  const CSimpleMapFile *v20; // [esp+0h] [ebp-10h]
  const MapBrush_t *pBrush; // [esp+8h] [ebp-8h]
  CMemoryBSPFile *v22; // [esp+Ch] [ebp-4h]
  const MapBrushSide_t *pBestSide; // [esp+18h] [ebp+8h]
  int i; // [esp+1Ch] [ebp+Ch]
  HashedPlane_t *ia; // [esp+1Ch] [ebp+Ch]

  m_pMapFile = this->m_pMapFile;
  v4 = -1.0;
  v6 = (int)&m_pMapFile->m_Brushes.m_Memory.m_pMemory[(_DWORD)nBrushIndex];
  v7 = *(_DWORD *)(v6 + 8);
  v8 = 0;
  v22 = this;
  v20 = m_pMapFile;
  pBrush = (const MapBrush_t *)v6;
  pBestSide = nullptr;
  if ( v7 >= 4 )
  {
    m_pMemory = this->m_PlaneHash.m_Planes.m_Memory.m_pMemory;
    y = vNormal->y;
    x = vNormal->x;
    z = vNormal->z;
    v13 = (int)&m_pMapFile->m_BrushSides.m_Memory.m_pMemory[*(_DWORD *)(v6 + 4)];
    v14 = (const MapBrushSide_t *)(v13 + 44);
    v15 = (_DWORD *)(v13 + 96);
    v16 = ((unsigned int)(v7 - 4) >> 2) + 1;
    i = 4 * v16;
    do
    {
      if ( (float)((float)((float)(m_pMemory[v14[-1].m_nPlaneIndex].m_vNormal.y * y)
                         + (float)(x * m_pMemory[v14[-1].m_nPlaneIndex].m_vNormal.x))
                 + (float)(m_pMemory[v14[-1].m_nPlaneIndex].m_vNormal.z * z)) > v4 )
      {
        v4 = (float)((float)(m_pMemory[v14[-1].m_nPlaneIndex].m_vNormal.y * y)
                   + (float)(x * m_pMemory[v14[-1].m_nPlaneIndex].m_vNormal.x))
           + (float)(m_pMemory[v14[-1].m_nPlaneIndex].m_vNormal.z * z);
        pBestSide = v14 - 1;
      }
      if ( (float)((float)((float)(m_pMemory[*(v15 - 11)].m_vNormal.y * y)
                         + (float)(x * m_pMemory[*(v15 - 11)].m_vNormal.x))
                 + (float)(m_pMemory[*(v15 - 11)].m_vNormal.z * z)) > v4 )
      {
        v4 = (float)((float)(m_pMemory[*(v15 - 11)].m_vNormal.y * y) + (float)(x * m_pMemory[*(v15 - 11)].m_vNormal.x))
           + (float)(m_pMemory[*(v15 - 11)].m_vNormal.z * z);
        pBestSide = v14;
      }
      if ( (float)((float)((float)(m_pMemory[*v15].m_vNormal.y * y) + (float)(x * m_pMemory[*v15].m_vNormal.x))
                 + (float)(m_pMemory[*v15].m_vNormal.z * z)) > v4 )
      {
        v4 = (float)((float)(m_pMemory[*v15].m_vNormal.y * y) + (float)(x * m_pMemory[*v15].m_vNormal.x))
           + (float)(m_pMemory[*v15].m_vNormal.z * z);
        pBestSide = v14 + 1;
      }
      if ( (float)((float)((float)(m_pMemory[v15[11]].m_vNormal.y * y) + (float)(x * m_pMemory[v15[11]].m_vNormal.x))
                 + (float)(m_pMemory[v15[11]].m_vNormal.z * z)) > v4 )
      {
        v4 = (float)((float)(m_pMemory[v15[11]].m_vNormal.y * y) + (float)(x * m_pMemory[v15[11]].m_vNormal.x))
           + (float)(m_pMemory[v15[11]].m_vNormal.z * z);
        pBestSide = v14 + 2;
      }
      v14 += 4;
      v15 += 44;
      --v16;
    }
    while ( v16 != 0 );
    this = v22;
    v6 = (int)pBrush;
    v8 = i;
    m_pMapFile = v20;
  }
  if ( v8 < v7 )
  {
    ia = this->m_PlaneHash.m_Planes.m_Memory.m_pMemory;
    v17 = (int)&m_pMapFile->m_BrushSides.m_Memory.m_pMemory[v8 + *(_DWORD *)(v6 + 4)];
    v18 = v7 - v8;
    do
    {
      if ( (float)((float)((float)(ia[*(_DWORD *)(v17 + 8)].m_vNormal.y * vNormal->y)
                         + (float)(vNormal->x * ia[*(_DWORD *)(v17 + 8)].m_vNormal.x))
                 + (float)(ia[*(_DWORD *)(v17 + 8)].m_vNormal.z * vNormal->z)) > v4 )
      {
        v4 = (float)((float)(ia[*(_DWORD *)(v17 + 8)].m_vNormal.y * vNormal->y)
                   + (float)(vNormal->x * ia[*(_DWORD *)(v17 + 8)].m_vNormal.x))
           + (float)(ia[*(_DWORD *)(v17 + 8)].m_vNormal.z * vNormal->z);
        pBestSide = (const MapBrushSide_t *)v17;
      }
      v17 += 44;
      --v18;
    }
    while ( v18 != 0 );
  }
  return pBestSide;
}

//------------------------------------------------------------------------------
// Address: 0x00413600
// Name: private: void CMemoryBSPFile::WriteLump<struct texinfo_s>(int,class CUtlVector<struct texinfo_s,class CUtlMemory<struct texinfo_s,int>> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump<texinfo_s>(
        CMemoryBSPFile *this,
        int nLump,
        const CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int> > *data,
        int nVersion)
{
  const CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int> > *v4; // eax
  int m_Put; // ebx
  int v7; // ecx
  int v8; // edx
  CUtlBuffer *m_pSerialBuffer; // ecx
  int v10; // edi
  int v11; // eax

  v4 = data;
  m_Put = this->m_pSerialBuffer->m_Put;
  v7 = 72 * data->m_Size;
  v8 = nLump;
  this->m_FileHeader.lumps[v8].fileofs = m_Put;
  this->m_FileHeader.lumps[nLump].filelen = v7;
  this->m_FileHeader.lumps[v8].version = nVersion;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)v4->m_Memory.m_pMemory, size: 72 * v4->m_Size);
  m_pSerialBuffer = this->m_pSerialBuffer;
  v10 = this->m_pSerialBuffer->m_Put;
  v11 = 4 * ((v10 + 3) / 4);
  if ( v11 > v10 )
  {
    LOBYTE(data) = 0;
    *(_WORD *)((char *)&data + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&data, size: v11 - v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413690
// Name: private: void CMemoryBSPFile::WriteLump<struct dleaf_t>(int,class CUtlVector<struct dleaf_t,class CUtlMemory<struct dleaf_t,int>> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump<dleaf_t>(
        CMemoryBSPFile *this,
        int nLump,
        const CUtlVector<dnode_t,CUtlMemory<dnode_t,int> > *data,
        int nVersion)
{
  const CUtlVector<dnode_t,CUtlMemory<dnode_t,int> > *v5; // ecx
  int m_Put; // ebx
  int v7; // edx
  int v8; // eax
  CUtlBuffer *m_pSerialBuffer; // ecx
  int v10; // edi
  int v11; // eax

  v5 = data;
  m_Put = this->m_pSerialBuffer->m_Put;
  v7 = nLump;
  this->m_FileHeader.lumps[nLump].filelen = 32 * data->m_Size;
  v8 = nVersion;
  this->m_FileHeader.lumps[v7].fileofs = m_Put;
  this->m_FileHeader.lumps[v7].version = v8;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)v5->m_Memory.m_pMemory, size: 32 * v5->m_Size);
  m_pSerialBuffer = this->m_pSerialBuffer;
  v10 = this->m_pSerialBuffer->m_Put;
  v11 = 4 * ((v10 + 3) / 4);
  if ( v11 > v10 )
  {
    LOBYTE(data) = 0;
    *(_WORD *)((char *)&data + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&data, size: v11 - v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413710
// Name: private: void CMemoryBSPFile::WriteLump<char>(int,class CUtlVector<char,class CUtlMemory<char,int>> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump<char>(
        CMemoryBSPFile *this,
        int nLump,
        const CUtlVector<char,CUtlMemory<char,int> > *data,
        int nVersion)
{
  const CUtlVector<char,CUtlMemory<char,int> > *v4; // eax
  int m_Put; // ebx
  int v7; // ecx
  int v8; // edx
  CUtlBuffer *m_pSerialBuffer; // ecx
  int v10; // edi
  int v11; // eax

  v4 = data;
  m_Put = this->m_pSerialBuffer->m_Put;
  v7 = nLump;
  this->m_FileHeader.lumps[nLump].filelen = data->m_Size;
  v8 = nVersion;
  this->m_FileHeader.lumps[v7].fileofs = m_Put;
  this->m_FileHeader.lumps[v7].version = v8;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)v4->m_Memory.m_pMemory, size: v4->m_Size);
  m_pSerialBuffer = this->m_pSerialBuffer;
  v10 = this->m_pSerialBuffer->m_Put;
  v11 = 4 * ((v10 + 3) / 4);
  if ( v11 > v10 )
  {
    LOBYTE(data) = 0;
    *(_WORD *)((char *)&data + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&data, size: v11 - v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413790
// Name: private: void CMemoryBSPFile::WriteLump<class Vector>(int,class CUtlVector<class Vector,class CUtlMemory<class Vector,int>> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump<Vector>(
        CMemoryBSPFile *this,
        int nLump,
        const CUtlVector<dbrush_t,CUtlMemory<dbrush_t,int> > *data,
        int nVersion)
{
  const CUtlVector<dbrush_t,CUtlMemory<dbrush_t,int> > *v4; // eax
  int m_Put; // ebx
  int v7; // ecx
  int v8; // edx
  CUtlBuffer *m_pSerialBuffer; // ecx
  int v10; // edi
  int v11; // eax

  v4 = data;
  m_Put = this->m_pSerialBuffer->m_Put;
  v7 = 12 * data->m_Size;
  v8 = nLump;
  this->m_FileHeader.lumps[v8].fileofs = m_Put;
  this->m_FileHeader.lumps[nLump].filelen = v7;
  this->m_FileHeader.lumps[v8].version = nVersion;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)v4->m_Memory.m_pMemory, size: 12 * v4->m_Size);
  m_pSerialBuffer = this->m_pSerialBuffer;
  v10 = this->m_pSerialBuffer->m_Put;
  v11 = 4 * ((v10 + 3) / 4);
  if ( v11 > v10 )
  {
    LOBYTE(data) = 0;
    *(_WORD *)((char *)&data + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&data, size: v11 - v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413820
// Name: private: void CMemoryBSPFile::WriteLump<struct dedge_t>(int,class CUtlVector<struct dedge_t,class CUtlMemory<struct dedge_t,int>> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump<dedge_t>(
        CMemoryBSPFile *this,
        int nLump,
        const CUtlVector<dedge_t,CUtlMemory<dedge_t,int> > *data,
        int nVersion)
{
  const CUtlVector<dedge_t,CUtlMemory<dedge_t,int> > *v4; // eax
  int m_Put; // ebx
  int v7; // ecx
  int v8; // edx
  CUtlBuffer *m_pSerialBuffer; // ecx
  int v10; // edi
  int v11; // eax

  v4 = data;
  m_Put = this->m_pSerialBuffer->m_Put;
  v7 = nLump;
  v8 = 4 * data->m_Size;
  this->m_FileHeader.lumps[v7].fileofs = m_Put;
  this->m_FileHeader.lumps[nLump].filelen = v8;
  this->m_FileHeader.lumps[v7].version = nVersion;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)v4->m_Memory.m_pMemory, size: 4 * v4->m_Size);
  m_pSerialBuffer = this->m_pSerialBuffer;
  v10 = this->m_pSerialBuffer->m_Put;
  v11 = 4 * ((v10 + 3) / 4);
  if ( v11 > v10 )
  {
    LOBYTE(data) = 0;
    *(_WORD *)((char *)&data + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&data, size: v11 - v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004138B0
// Name: private: void CMemoryBSPFile::WriteLump<struct dface_t>(int,class CUtlVector<struct dface_t,class CUtlMemory<struct dface_t,int>> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump<dface_t>(
        CMemoryBSPFile *this,
        int nLump,
        const CUtlVector<dface_t,CUtlMemory<dface_t,int> > *data,
        int nVersion)
{
  const CUtlVector<dface_t,CUtlMemory<dface_t,int> > *v4; // eax
  int m_Size; // ecx
  int v7; // edx
  CUtlBuffer *m_pSerialBuffer; // ecx
  int m_Put; // edi
  int v10; // eax

  v4 = data;
  m_Size = data->m_Size;
  v7 = nLump;
  this->m_FileHeader.lumps[v7].fileofs = this->m_pSerialBuffer->m_Put;
  this->m_FileHeader.lumps[v7].version = nVersion;
  this->m_FileHeader.lumps[nLump].filelen = 56 * m_Size;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)v4->m_Memory.m_pMemory, size: 56 * v4->m_Size);
  m_pSerialBuffer = this->m_pSerialBuffer;
  m_Put = this->m_pSerialBuffer->m_Put;
  v10 = 4 * ((m_Put + 3) / 4);
  if ( v10 > m_Put )
  {
    LOBYTE(data) = 0;
    *(_WORD *)((char *)&data + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&data, size: v10 - m_Put);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413950
// Name: private: void CMemoryBSPFile::WriteLump<struct dbrushside_t>(int,class CUtlVector<struct dbrushside_t,class CUtlMemory<struct dbrushside_t,int>> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump<dbrushside_t>(
        CMemoryBSPFile *this,
        int nLump,
        const CUtlVector<dbrushside_t,CUtlMemory<dbrushside_t,int> > *data,
        int nVersion)
{
  const CUtlVector<dbrushside_t,CUtlMemory<dbrushside_t,int> > *v4; // eax
  int m_Put; // ebx
  int v7; // ecx
  int v8; // edx
  CUtlBuffer *m_pSerialBuffer; // ecx
  int v10; // edi
  int v11; // eax

  v4 = data;
  m_Put = this->m_pSerialBuffer->m_Put;
  v7 = nLump;
  v8 = 8 * data->m_Size;
  this->m_FileHeader.lumps[v7].fileofs = m_Put;
  this->m_FileHeader.lumps[nLump].filelen = v8;
  this->m_FileHeader.lumps[v7].version = nVersion;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)v4->m_Memory.m_pMemory, size: 8 * v4->m_Size);
  m_pSerialBuffer = this->m_pSerialBuffer;
  v10 = this->m_pSerialBuffer->m_Put;
  v11 = 4 * ((v10 + 3) / 4);
  if ( v11 > v10 )
  {
    LOBYTE(data) = 0;
    *(_WORD *)((char *)&data + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&data, size: v11 - v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004139E0
// Name: private: void CMemoryBSPFile::WriteLump<struct dmodel_t>(int,class CUtlVector<struct dmodel_t,class CUtlMemory<struct dmodel_t,int>> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump<dmodel_t>(
        CMemoryBSPFile *this,
        int nLump,
        const CUtlVector<dmodel_t,CUtlMemory<dmodel_t,int> > *data,
        int nVersion)
{
  const CUtlVector<dmodel_t,CUtlMemory<dmodel_t,int> > *v4; // eax
  int m_Put; // ebx
  int v7; // ecx
  int v8; // edx
  CUtlBuffer *m_pSerialBuffer; // ecx
  int v10; // edi
  int v11; // eax

  v4 = data;
  m_Put = this->m_pSerialBuffer->m_Put;
  v7 = 48 * data->m_Size;
  v8 = nLump;
  this->m_FileHeader.lumps[v8].fileofs = m_Put;
  this->m_FileHeader.lumps[nLump].filelen = v7;
  this->m_FileHeader.lumps[v8].version = nVersion;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)v4->m_Memory.m_pMemory, size: 48 * v4->m_Size);
  m_pSerialBuffer = this->m_pSerialBuffer;
  v10 = this->m_pSerialBuffer->m_Put;
  v11 = 4 * ((v10 + 3) / 4);
  if ( v11 > v10 )
  {
    LOBYTE(data) = 0;
    *(_WORD *)((char *)&data + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&data, size: v11 - v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413A70
// Name: private: void CMemoryBSPFile::WriteLump<class ddispinfo_t>(int,class CUtlVector<class ddispinfo_t,class CUtlMemory<class ddispinfo_t,int>> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump<ddispinfo_t>(
        CMemoryBSPFile *this,
        int nLump,
        const CUtlVector<ddispinfo_t,CUtlMemory<ddispinfo_t,int> > *data,
        int nVersion)
{
  const CUtlVector<ddispinfo_t,CUtlMemory<ddispinfo_t,int> > *v5; // ecx
  int m_Put; // ebx
  int v7; // edx
  int v8; // eax
  CUtlBuffer *m_pSerialBuffer; // ecx
  int v10; // edi
  int v11; // eax

  v5 = data;
  m_Put = this->m_pSerialBuffer->m_Put;
  v7 = nLump;
  this->m_FileHeader.lumps[nLump].filelen = 176 * data->m_Size;
  v8 = nVersion;
  this->m_FileHeader.lumps[v7].fileofs = m_Put;
  this->m_FileHeader.lumps[v7].version = v8;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)v5->m_Memory.m_pMemory, size: 176 * v5->m_Size);
  m_pSerialBuffer = this->m_pSerialBuffer;
  v10 = this->m_pSerialBuffer->m_Put;
  v11 = 4 * ((v10 + 3) / 4);
  if ( v11 > v10 )
  {
    LOBYTE(data) = 0;
    *(_WORD *)((char *)&data + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&data, size: v11 - v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413B00
// Name: private: void CMemoryBSPFile::WriteLump<struct dplane_t>(int,class CUtlVector<struct dplane_t,class CUtlMemory<struct dplane_t,int>> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump<dplane_t>(
        CMemoryBSPFile *this,
        int nLump,
        const CUtlVector<CDispVert,CUtlMemory<CDispVert,int> > *data,
        int nVersion)
{
  const CUtlVector<CDispVert,CUtlMemory<CDispVert,int> > *v4; // eax
  int m_Put; // ebx
  int v7; // ecx
  int v8; // edx
  CUtlBuffer *m_pSerialBuffer; // ecx
  int v10; // edi
  int v11; // eax

  v4 = data;
  m_Put = this->m_pSerialBuffer->m_Put;
  v7 = 20 * data->m_Size;
  v8 = nLump;
  this->m_FileHeader.lumps[v8].fileofs = m_Put;
  this->m_FileHeader.lumps[nLump].filelen = v7;
  this->m_FileHeader.lumps[v8].version = nVersion;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)v4->m_Memory.m_pMemory, size: 20 * v4->m_Size);
  m_pSerialBuffer = this->m_pSerialBuffer;
  v10 = this->m_pSerialBuffer->m_Put;
  v11 = 4 * ((v10 + 3) / 4);
  if ( v11 > v10 )
  {
    LOBYTE(data) = 0;
    *(_WORD *)((char *)&data + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&data, size: v11 - v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413B90
// Name: private: void CMemoryBSPFile::WriteLump<class CDispTri>(int,class CUtlVector<class CDispTri,class CUtlMemory<class CDispTri,int>> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump<CDispTri>(
        CMemoryBSPFile *this,
        int nLump,
        const CUtlVector<CDispTri,CUtlMemory<CDispTri,int> > *data,
        int nVersion)
{
  const CUtlVector<CDispTri,CUtlMemory<CDispTri,int> > *v4; // eax
  int m_Put; // ebx
  int v7; // ecx
  int v8; // edx
  CUtlBuffer *m_pSerialBuffer; // ecx
  int v10; // edi
  int v11; // eax

  v4 = data;
  m_Put = this->m_pSerialBuffer->m_Put;
  v7 = nLump;
  this->m_FileHeader.lumps[nLump].filelen = 2 * data->m_Size;
  v8 = nVersion;
  this->m_FileHeader.lumps[v7].fileofs = m_Put;
  this->m_FileHeader.lumps[v7].version = v8;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)v4->m_Memory.m_pMemory, size: 2 * v4->m_Size);
  m_pSerialBuffer = this->m_pSerialBuffer;
  v10 = this->m_pSerialBuffer->m_Put;
  v11 = 4 * ((v10 + 3) / 4);
  if ( v11 > v10 )
  {
    LOBYTE(data) = 0;
    *(_WORD *)((char *)&data + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&data, size: v11 - v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413C10
// Name: private: void CMemoryBSPFile::WriteLump<class CDispMultiBlend>(int,class CUtlVector<class CDispMultiBlend,class CUtlMemory<class CDispMultiBlend,int>> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump<CDispMultiBlend>(
        CMemoryBSPFile *this,
        int nLump,
        const CUtlVector<CDispMultiBlend,CUtlMemory<CDispMultiBlend,int> > *data,
        int nVersion)
{
  const CUtlVector<CDispMultiBlend,CUtlMemory<CDispMultiBlend,int> > *v4; // eax
  int m_Put; // ebx
  int v7; // ecx
  int v8; // edx
  CUtlBuffer *m_pSerialBuffer; // ecx
  int v10; // edi
  int v11; // eax

  v4 = data;
  m_Put = this->m_pSerialBuffer->m_Put;
  v7 = 80 * data->m_Size;
  v8 = nLump;
  this->m_FileHeader.lumps[v8].fileofs = m_Put;
  this->m_FileHeader.lumps[nLump].filelen = v7;
  this->m_FileHeader.lumps[v8].version = nVersion;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)v4->m_Memory.m_pMemory, size: 80 * v4->m_Size);
  m_pSerialBuffer = this->m_pSerialBuffer;
  v10 = this->m_pSerialBuffer->m_Put;
  v11 = 4 * ((v10 + 3) / 4);
  if ( v11 > v10 )
  {
    LOBYTE(data) = 0;
    *(_WORD *)((char *)&data + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&data, size: v11 - v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413CA0
// Name: private: void CMemoryBSPFile::WriteLump<struct dworldlight_t>(int,class CUtlVector<struct dworldlight_t,class CUtlMemory<struct dworldlight_t,int>> const __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLump<dworldlight_t>(
        CMemoryBSPFile *this,
        int nLump,
        const CUtlVector<dworldlight_t,CUtlMemory<dworldlight_t,int> > *data,
        int nVersion)
{
  const CUtlVector<dworldlight_t,CUtlMemory<dworldlight_t,int> > *v5; // ecx
  int m_Put; // ebx
  int v7; // edx
  int v8; // eax
  CUtlBuffer *m_pSerialBuffer; // ecx
  int v10; // edi
  int v11; // eax

  v5 = data;
  m_Put = this->m_pSerialBuffer->m_Put;
  v7 = nLump;
  this->m_FileHeader.lumps[nLump].filelen = 100 * data->m_Size;
  v8 = nVersion;
  this->m_FileHeader.lumps[v7].fileofs = m_Put;
  this->m_FileHeader.lumps[v7].version = v8;
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)v5->m_Memory.m_pMemory, size: 100 * v5->m_Size);
  m_pSerialBuffer = this->m_pSerialBuffer;
  v10 = this->m_pSerialBuffer->m_Put;
  v11 = 4 * ((v10 + 3) / 4);
  if ( v11 > v10 )
  {
    LOBYTE(data) = 0;
    *(_WORD *)((char *)&data + 1) = 0;
    CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&data, size: v11 - v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414290
// Name: private: void CMemoryBSPFile::WriteTexData(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteTexData(CMemoryBSPFile *this, bool bPurgeWhenComplete)
{
  CUtlVector<dtexdata_t,CUtlMemory<dtexdata_t,int> > *p_m_TexDataList; // edi
  CUtlVector<char,CUtlMemory<char,int> > *p_m_TexStringData; // ebx
  CUtlVector<int,CUtlMemory<int,int> > *p_m_TexStringIndices; // [esp+Ch] [ebp-4h]

  p_m_TexDataList = &this->m_TexDataList;
  CMemoryBSPFile::WriteLump<dleaf_t>(
    this,
    nLump: 2,
    data: (const CUtlVector<dnode_t,CUtlMemory<dnode_t,int> > *)&this->m_TexDataList,
    nVersion: 0);
  p_m_TexStringData = &this->m_TexStringData;
  CMemoryBSPFile::WriteLump<char>(this, nLump: 43, data: &this->m_TexStringData, nVersion: 0);
  p_m_TexStringIndices = &this->m_TexStringIndices;
  CMemoryBSPFile::WriteLump<dedge_t>(
    this,
    nLump: 44,
    data: (const CUtlVector<dedge_t,CUtlMemory<dedge_t,int> > *)&this->m_TexStringIndices,
    nVersion: 0);
  if ( bPurgeWhenComplete )
  {
    p_m_TexDataList->m_Size = 0;
    if ( p_m_TexDataList->m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_TexDataList->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_TexDataList->m_Memory.m_pMemory);
        p_m_TexDataList->m_Memory.m_pMemory = nullptr;
      }
      p_m_TexDataList->m_Memory.m_nAllocationCount = 0;
    }
    p_m_TexDataList->m_pElements = p_m_TexDataList->m_Memory.m_pMemory;
    this->m_TexStringData.m_Size = 0;
    if ( this->m_TexStringData.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_TexStringData->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_TexStringData->m_Memory.m_pMemory);
        p_m_TexStringData->m_Memory.m_pMemory = nullptr;
      }
      this->m_TexStringData.m_Memory.m_nAllocationCount = 0;
    }
    this->m_TexStringData.m_pElements = this->m_TexStringData.m_Memory.m_pMemory;
    this->m_TexStringIndices.m_Size = 0;
    if ( this->m_TexStringIndices.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_TexStringIndices->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_TexStringIndices->m_Memory.m_pMemory);
        p_m_TexStringIndices->m_Memory.m_pMemory = nullptr;
      }
      this->m_TexStringIndices.m_Memory.m_nAllocationCount = 0;
    }
    this->m_TexStringIndices.m_pElements = this->m_TexStringIndices.m_Memory.m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414360
// Name: private: void CMemoryBSPFile::WriteBrushes(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteBrushes(CMemoryBSPFile *this, bool bPurgeWhenComplete)
{
  CUtlVector<dbrush_t,CUtlMemory<dbrush_t,int> > *p_m_BrushList; // esi
  CUtlVector<dbrushside_t,CUtlMemory<dbrushside_t,int> > *p_m_BrushSideList; // ebx

  p_m_BrushList = &this->m_BrushList;
  CMemoryBSPFile::WriteLump<Vector>(this, nLump: 18, data: &this->m_BrushList, nVersion: 0);
  p_m_BrushSideList = &this->m_BrushSideList;
  CMemoryBSPFile::WriteLump<dbrushside_t>(this, nLump: 19, data: &this->m_BrushSideList, nVersion: 0);
  if ( bPurgeWhenComplete )
  {
    p_m_BrushList->m_Size = 0;
    if ( p_m_BrushList->m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_BrushList->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_BrushList->m_Memory.m_pMemory);
        p_m_BrushList->m_Memory.m_pMemory = nullptr;
      }
      p_m_BrushList->m_Memory.m_nAllocationCount = 0;
    }
    p_m_BrushList->m_pElements = p_m_BrushList->m_Memory.m_pMemory;
    this->m_BrushSideList.m_Size = 0;
    if ( this->m_BrushSideList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_BrushSideList->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_BrushSideList->m_Memory.m_pMemory);
        p_m_BrushSideList->m_Memory.m_pMemory = nullptr;
      }
      this->m_BrushSideList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_BrushSideList.m_pElements = this->m_BrushSideList.m_Memory.m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004143F0
// Name: private: void CMemoryBSPFile::WriteDisplacements(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteDisplacements(CMemoryBSPFile *this, bool bPurgeWhenComplete)
{
  CUtlVector<ddispinfo_t,CUtlMemory<ddispinfo_t,int> > *p_m_DisplacementList; // edi
  CUtlVector<CDispVert,CUtlMemory<CDispVert,int> > *p_m_DisplacementVertexList; // ebx
  CUtlVector<CDispMultiBlend,CUtlMemory<CDispMultiBlend,int> > *p_m_DisplacementMultiBlendList; // [esp+Ch] [ebp-Ch]
  CUtlVector<CDispTri,CUtlMemory<CDispTri,int> > *p_m_DisplacementTriangleList; // [esp+10h] [ebp-8h]
  unsigned __int8 dummyLightmapSamplePositionData[4]; // [esp+14h] [ebp-4h] BYREF

  *(_DWORD *)dummyLightmapSamplePositionData = 0;
  CMemoryBSPFile::WriteLump(this, nLump: 34, pData: dummyLightmapSamplePositionData, nByteLength: 4, nVersion: 0);
  p_m_DisplacementList = &this->m_DisplacementList;
  CMemoryBSPFile::WriteLump<ddispinfo_t>(this, nLump: 26, data: &this->m_DisplacementList, nVersion: 0);
  p_m_DisplacementVertexList = &this->m_DisplacementVertexList;
  CMemoryBSPFile::WriteLump<dplane_t>(this, nLump: 33, data: &this->m_DisplacementVertexList, nVersion: 0);
  p_m_DisplacementTriangleList = &this->m_DisplacementTriangleList;
  CMemoryBSPFile::WriteLump<CDispTri>(this, nLump: 48, data: &this->m_DisplacementTriangleList, nVersion: 0);
  p_m_DisplacementMultiBlendList = &this->m_DisplacementMultiBlendList;
  CMemoryBSPFile::WriteLump<CDispMultiBlend>(this, nLump: 63, data: &this->m_DisplacementMultiBlendList, nVersion: 0);
  if ( bPurgeWhenComplete )
  {
    this->m_DisplacementList.m_Size = 0;
    if ( this->m_DisplacementList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_DisplacementList->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_DisplacementList->m_Memory.m_pMemory);
        p_m_DisplacementList->m_Memory.m_pMemory = nullptr;
      }
      this->m_DisplacementList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_DisplacementList.m_pElements = this->m_DisplacementList.m_Memory.m_pMemory;
    this->m_DisplacementVertexList.m_Size = 0;
    if ( this->m_DisplacementVertexList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_DisplacementVertexList->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_DisplacementVertexList->m_Memory.m_pMemory);
        p_m_DisplacementVertexList->m_Memory.m_pMemory = nullptr;
      }
      this->m_DisplacementVertexList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_DisplacementVertexList.m_pElements = this->m_DisplacementVertexList.m_Memory.m_pMemory;
    this->m_DisplacementTriangleList.m_Size = 0;
    if ( this->m_DisplacementTriangleList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_DisplacementTriangleList->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_DisplacementTriangleList->m_Memory.m_pMemory);
        p_m_DisplacementTriangleList->m_Memory.m_pMemory = nullptr;
      }
      this->m_DisplacementTriangleList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_DisplacementTriangleList.m_pElements = this->m_DisplacementTriangleList.m_Memory.m_pMemory;
    this->m_DisplacementMultiBlendList.m_Size = 0;
    if ( this->m_DisplacementMultiBlendList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_DisplacementMultiBlendList->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_DisplacementMultiBlendList->m_Memory.m_pMemory);
        p_m_DisplacementMultiBlendList->m_Memory.m_pMemory = nullptr;
      }
      this->m_DisplacementMultiBlendList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_DisplacementMultiBlendList.m_pElements = this->m_DisplacementMultiBlendList.m_Memory.m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414570
// Name: private: void CMemoryBSPFile::ReadLump<unsigned char>(int,class CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::ReadLump<unsigned char>(
        CMemoryBSPFile *this,
        int nLump,
        CUtlMemory<unsigned char,int> *pVector)
{
  int fileofs; // eax
  int filelen; // edi
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v8; // eax

  fileofs = this->m_FileHeader.lumps[nLump].fileofs;
  if ( fileofs > 0 )
    CUtlBuffer::SeekGet(this: this->m_pSerialBuffer, type: SEEK_HEAD, offset: fileofs);
  filelen = this->m_FileHeader.lumps[nLump].filelen;
  pVector[1].m_pMemory = nullptr;
  if ( filelen != 0 )
  {
    m_nAllocationCount = pVector->m_nAllocationCount;
    if ( filelen > m_nAllocationCount )
      CUtlMemory<char,int>::Grow(this: pVector, num: filelen - m_nAllocationCount);
    pVector[1].m_pMemory += filelen;
    m_pMemory = (char *)pVector->m_pMemory;
    v8 = (int)&pVector[1].m_pMemory[-filelen];
    pVector[1].m_nAllocationCount = (int)pVector->m_pMemory;
    if ( v8 > 0 )
    {
      if ( filelen <= 0 )
        return;
      _V_memmove(dest: &m_pMemory[filelen], src: m_pMemory, count: v8);
    }
    if ( filelen > 0 )
      CUtlBuffer::Get(this: this->m_pSerialBuffer, pMem: pVector->m_pMemory, size: (int)pVector[1].m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414600
// Name: private: int CMemoryBSPFile::FindOrAddString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMemoryBSPFile::FindOrAddString(CMemoryBSPFile *this, const char *pString)
{
  int v3; // esi
  unsigned int v4; // eax
  int m_Size; // ebx
  int v6; // edx
  int m_nAllocationCount; // eax
  int *m_pMemory; // ecx
  int v9; // eax
  int *v10; // ebx
  int v12; // [esp+8h] [ebp-8h]
  int nStrLen; // [esp+Ch] [ebp-4h]

  v3 = 0;
  if ( this->m_TexStringIndices.m_Size <= 0 )
  {
LABEL_4:
    v4 = _V_strlen(str: pString);
    m_Size = this->m_TexStringIndices.m_Size;
    v6 = v4 + 1;
    v12 = this->m_TexStringData.m_Size;
    m_nAllocationCount = this->m_TexStringIndices.m_Memory.m_nAllocationCount;
    nStrLen = v6;
    if ( m_Size + 1 > m_nAllocationCount )
    {
      CUtlMemory<ColorRGBExp32,int>::Grow(
        this: (CUtlMemory<BSPCluster_t,int> *)&this->m_TexStringIndices,
        num: m_Size - m_nAllocationCount + 1);
      v6 = nStrLen;
    }
    ++this->m_TexStringIndices.m_Size;
    m_pMemory = this->m_TexStringIndices.m_Memory.m_pMemory;
    v9 = this->m_TexStringIndices.m_Size - m_Size - 1;
    this->m_TexStringIndices.m_pElements = m_pMemory;
    if ( v9 > 0 )
    {
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
      v6 = nStrLen;
    }
    v10 = &this->m_TexStringIndices.m_Memory.m_pMemory[m_Size];
    if ( v10 != nullptr )
      *v10 = v12;
    CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::InsertMultipleBefore(
      this: (CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *)&this->m_TexStringData,
      elem: this->m_TexStringData.m_Size,
      num: v6,
      pToInsert: (const unsigned __int8 *)pString);
    return this->m_TexStringIndices.m_Size - 1;
  }
  else
  {
    while ( _V_stricmp(
              s1: &this->m_TexStringData.m_Memory.m_pMemory[this->m_TexStringIndices.m_Memory.m_pMemory[v3]],
              s2: pString) != 0 )
    {
      if ( ++v3 >= this->m_TexStringIndices.m_Size )
        goto LABEL_4;
    }
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414700
// Name: private: void CMemoryBSPFile::WriteModelData(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteModelData(CMemoryBSPFile *this, bool bPurgeWhenComplete)
{
  CUtlVector<dedge_t,CUtlMemory<dedge_t,int> > *p_m_EdgeList; // edi
  CUtlVector<int,CUtlMemory<int,int> > *p_m_SurfEdgeList; // ebx
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *p_m_VertexNormalIndexList; // [esp+Ch] [ebp-8h]
  CUtlVector<Vector,CUtlMemory<Vector,int> > *p_m_VertexNormalList; // [esp+10h] [ebp-4h]

  CMemoryBSPFile::WriteLump<Vector>(
    this,
    nLump: 3,
    data: (const CUtlVector<dbrush_t,CUtlMemory<dbrush_t,int> > *)&this->m_VertexHash.m_Vertices,
    nVersion: 0);
  p_m_EdgeList = &this->m_EdgeList;
  CMemoryBSPFile::WriteLump<dedge_t>(this, nLump: 12, data: &this->m_EdgeList, nVersion: 0);
  p_m_SurfEdgeList = &this->m_SurfEdgeList;
  CMemoryBSPFile::WriteLump<dedge_t>(
    this,
    nLump: 13,
    data: (const CUtlVector<dedge_t,CUtlMemory<dedge_t,int> > *)&this->m_SurfEdgeList,
    nVersion: 0);
  CMemoryBSPFile::WriteLump<dface_t>(this, nLump: 7, data: &this->m_FaceList, nVersion: 1);
  p_m_VertexNormalList = &this->m_VertexNormalList;
  CMemoryBSPFile::WriteLump<Vector>(
    this,
    nLump: 30,
    data: (const CUtlVector<dbrush_t,CUtlMemory<dbrush_t,int> > *)&this->m_VertexNormalList,
    nVersion: 0);
  p_m_VertexNormalIndexList = &this->m_VertexNormalIndexList;
  CMemoryBSPFile::WriteLump<CDispTri>(
    this,
    nLump: 31,
    data: (const CUtlVector<CDispTri,CUtlMemory<CDispTri,int> > *)&this->m_VertexNormalIndexList,
    nVersion: 0);
  if ( bPurgeWhenComplete )
  {
    CVertexHash::Purge(this: &this->m_VertexHash);
    this->m_EdgeList.m_Size = 0;
    if ( this->m_EdgeList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_EdgeList->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_EdgeList->m_Memory.m_pMemory);
        p_m_EdgeList->m_Memory.m_pMemory = nullptr;
      }
      this->m_EdgeList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_EdgeList.m_pElements = this->m_EdgeList.m_Memory.m_pMemory;
    this->m_SurfEdgeList.m_Size = 0;
    if ( this->m_SurfEdgeList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_SurfEdgeList->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_SurfEdgeList->m_Memory.m_pMemory);
        p_m_SurfEdgeList->m_Memory.m_pMemory = nullptr;
      }
      this->m_SurfEdgeList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_SurfEdgeList.m_pElements = this->m_SurfEdgeList.m_Memory.m_pMemory;
    this->m_VertexNormalList.m_Size = 0;
    if ( this->m_VertexNormalList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_VertexNormalList->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_VertexNormalList->m_Memory.m_pMemory);
        p_m_VertexNormalList->m_Memory.m_pMemory = nullptr;
      }
      this->m_VertexNormalList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_VertexNormalList.m_pElements = this->m_VertexNormalList.m_Memory.m_pMemory;
    this->m_VertexNormalIndexList.m_Size = 0;
    if ( this->m_VertexNormalIndexList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_VertexNormalIndexList->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_VertexNormalIndexList->m_Memory.m_pMemory);
        p_m_VertexNormalIndexList->m_Memory.m_pMemory = nullptr;
      }
      this->m_VertexNormalIndexList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_VertexNormalIndexList.m_pElements = this->m_VertexNormalIndexList.m_Memory.m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414850
// Name: private: void CMemoryBSPFile::EmitFace(class CBSPFace const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::EmitFace(CMemoryBSPFile *this, dedge_t pBSPFace, unsigned __int8 bOnNode)
{
  bool v4; // zf
  CMemoryBSPFile *v5; // esi
  unsigned __int16 v6; // cx
  __int16 v7; // di
  unsigned __int8 v8; // dl
  int m_Size; // ecx
  __int16 v10; // dx
  double v11; // st7
  __int16 v12; // cx
  const CSimpleMapFile *m_pMapFile; // ecx
  const Vector *v14; // eax
  int VertexIndex; // eax
  bool v16; // cc
  CUtlMemory<BSPCluster_t,int> *p_m_EdgeList; // edi
  int v18; // eax
  BSPCluster_t *m_pMemory; // esi
  int m_nAllocationCount; // eax
  BSPCluster_t *v21; // ecx
  int v22; // eax
  _DWORD *p_m_pLeafNode; // esi
  int v24; // esi
  int v25; // ecx
  CMemoryBSPFile *v26; // ecx
  int *v27; // edx
  int v28; // eax
  CMemoryBSPFile *v29; // eax
  int *v30; // esi
  int v31; // ecx
  int v32; // eax
  unsigned __int16 *v33; // edx
  int v34; // eax
  unsigned __int16 *v35; // ecx
  float y; // xmm1_4
  float x; // xmm2_4
  float z; // xmm3_4
  float v39; // xmm0_4
  float v40; // xmm1_4
  int i; // edi
  __m128 v42; // xmm2
  __m128 v43; // xmm1
  __m128 v44; // xmm3
  __m128 v45; // xmm0
  __m128 v46; // xmm1
  int v47; // eax
  int v48; // ebx
  int v49; // edx
  int v50; // eax
  Vector *v51; // ecx
  int v52; // eax
  int v53; // eax
  int v54; // edi
  int v55; // eax
  dface_t *v56; // ecx
  int v57; // eax
  dface_t *v58; // edi
  dface_t fileFace; // [esp+14h] [ebp-64h] BYREF
  float flLightmapMax[2]; // [esp+4Ch] [ebp-2Ch]
  float flLightmapMin[2]; // [esp+54h] [ebp-24h]
  const MapTextureInfo_t *pMapTextureInfo; // [esp+5Ch] [ebp-1Ch]
  const Vector *vPoint; // [esp+60h] [ebp-18h]
  int m_Size_low; // [esp+64h] [ebp-14h]
  int nVertex; // [esp+68h] [ebp-10h]
  int nCurrentVertexIndex; // [esp+6Ch] [ebp-Ch]
  int nPreviousVertexIndex; // [esp+70h] [ebp-8h]
  CMemoryBSPFile *v68; // [esp+74h] [ebp-4h]
  dedge_t newEdge; // [esp+80h] [ebp+8h]
  float newEdgea; // [esp+80h] [ebp+8h]
  int bOnNodea; // [esp+84h] [ebp+Ch]
  float bOnNodec; // [esp+84h] [ebp+Ch]
  int bOnNodeb; // [esp+84h] [ebp+Ch]

  v4 = *(_DWORD *)(*(_DWORD *)&pBSPFace + 36) == -1;
  v5 = this;
  v68 = this;
  if ( !v4 )
  {
    memset(dst: (unsigned __int8 *)&fileFace, value: 0, count: sizeof(fileFace));
    v6 = *(_WORD *)(*(_DWORD *)&pBSPFace + 4);
    v7 = *(_WORD *)(*(_DWORD *)&pBSPFace + 24);
    v8 = v6 & 1;
    fileFace.onNode = bOnNode;
    fileFace.planenum = v6;
    m_Size = v5->m_EdgeList.m_Size;
    fileFace.side = v8;
    v10 = *(_WORD *)pBSPFace.v[0];
    fileFace.firstedge = m_Size;
    fileFace.numedges = v7;
    fileFace.texinfo = v10;
    v11 = ComputePolygonArea(polygon: (const Polygon_t *)(*(_DWORD *)&pBSPFace + 8));
    v12 = *(_WORD *)(*(_DWORD *)&pBSPFace + 32);
    fileFace.area = v11;
    fileFace.dispinfo = v12;
    fileFace.surfaceFogVolumeID = -1;
    m_pMapFile = v5->m_pMapFile;
    fileFace.m_NumPrims = 0;
    v14 = (const Vector *)(*(_DWORD *)(*(_DWORD *)&pBSPFace + 12) + 12 * v7 - 12);
    pMapTextureInfo = &m_pMapFile->m_TextureInfos.m_Memory.m_pMemory[**(_DWORD **)&pBSPFace];
    flLightmapMin[1] = 3.4028235e38;
    flLightmapMin[0] = 3.4028235e38;
    flLightmapMax[1] = -3.4028235e38;
    flLightmapMax[0] = -3.4028235e38;
    VertexIndex = CVertexHash::FindVertexIndex(this: &v5->m_VertexHash, vertex: v14, bAlwaysAdd: false);
    v16 = *(_DWORD *)(*(_DWORD *)&pBSPFace + 24) <= 0;
    nPreviousVertexIndex = VertexIndex;
    nVertex = 0;
    if ( !v16 )
    {
      p_m_EdgeList = (CUtlMemory<BSPCluster_t,int> *)&v5->m_EdgeList;
      bOnNodea = 0;
      do
      {
        vPoint = (const Vector *)(bOnNodea + *(_DWORD *)(*(_DWORD *)&pBSPFace + 12));
        v18 = CVertexHash::FindVertexIndex(this: &v5->m_VertexHash, vertex: vPoint, bAlwaysAdd: false);
        m_pMemory = p_m_EdgeList[1].m_pMemory;
        nCurrentVertexIndex = v18;
        newEdge.v[1] = v18;
        m_nAllocationCount = p_m_EdgeList->m_nAllocationCount;
        newEdge.v[0] = nPreviousVertexIndex;
        if ( (int)&m_pMemory->m_pLeafNode + 1 > m_nAllocationCount )
          CUtlMemory<ColorRGBExp32,int>::Grow(
            this: p_m_EdgeList,
            num: (int)&m_pMemory->m_pLeafNode - m_nAllocationCount + 1);
        ++p_m_EdgeList[1].m_pMemory;
        v21 = p_m_EdgeList->m_pMemory;
        v22 = (char *)p_m_EdgeList[1].m_pMemory - (char *)m_pMemory - 1;
        p_m_EdgeList[1].m_nAllocationCount = (int)p_m_EdgeList->m_pMemory;
        if ( v22 > 0 )
          _V_memmove(dest: &v21[(_DWORD)m_pMemory + 1], src: &v21[(_DWORD)m_pMemory], count: 4 * v22);
        p_m_pLeafNode = &p_m_EdgeList->m_pMemory[(_DWORD)m_pMemory].m_pLeafNode;
        if ( p_m_pLeafNode != nullptr )
          *p_m_pLeafNode = newEdge;
        v24 = v68->m_SurfEdgeList.m_Size;
        nPreviousVertexIndex = nCurrentVertexIndex;
        nCurrentVertexIndex = v24;
        v25 = v68->m_SurfEdgeList.m_Memory.m_nAllocationCount;
        if ( v24 + 1 > v25 )
          CUtlMemory<ColorRGBExp32,int>::Grow(
            this: (CUtlMemory<BSPCluster_t,int> *)&v68->m_SurfEdgeList,
            num: v24 - v25 + 1);
        v26 = v68;
        ++v68->m_SurfEdgeList.m_Size;
        v27 = v26->m_SurfEdgeList.m_Memory.m_pMemory;
        v28 = v26->m_SurfEdgeList.m_Size - v24 - 1;
        v26->m_SurfEdgeList.m_pElements = v27;
        if ( v28 > 0 )
          _V_memmove(dest: &v27[v24 + 1], src: &v27[v24], count: 4 * v28);
        v29 = v68;
        v30 = &v68->m_SurfEdgeList.m_Memory.m_pMemory[v24];
        if ( v30 != nullptr )
          *v30 = nCurrentVertexIndex;
        v5 = v29;
        v31 = v29->m_VertexNormalIndexList.m_Size;
        m_Size_low = LOWORD(v29->m_VertexNormalList.m_Size);
        v32 = v29->m_VertexNormalIndexList.m_Memory.m_nAllocationCount;
        nCurrentVertexIndex = v31;
        if ( v31 + 1 > v32 )
        {
          CUtlMemory<unsigned short,int>::Grow(
            this: (CUtlMemory<StaticPropLeafLump_t,int> *)&v5->m_VertexNormalIndexList,
            num: v31 - v32 + 1);
          v31 = nCurrentVertexIndex;
        }
        ++v5->m_VertexNormalIndexList.m_Size;
        v33 = v5->m_VertexNormalIndexList.m_Memory.m_pMemory;
        v34 = v5->m_VertexNormalIndexList.m_Size - v31 - 1;
        v5->m_VertexNormalIndexList.m_pElements = v33;
        if ( v34 > 0 )
        {
          _V_memmove(dest: &v33[v31 + 1], src: &v33[v31], count: 2 * v34);
          v31 = nCurrentVertexIndex;
        }
        v35 = &v5->m_VertexNormalIndexList.m_Memory.m_pMemory[v31];
        if ( v35 != nullptr )
          *v35 = m_Size_low;
        y = vPoint->y;
        x = vPoint->x;
        z = vPoint->z;
        v39 = (float)((float)((float)(y * pMapTextureInfo->m_flLightmapVectors[0][1])
                            + (float)(vPoint->x * pMapTextureInfo->m_flLightmapVectors[0][0]))
                    + (float)(z * pMapTextureInfo->m_flLightmapVectors[0][2]))
            + pMapTextureInfo->m_flLightmapVectors[0][3];
        if ( flLightmapMin[0] > v39 )
          flLightmapMin[0] = (float)((float)((float)(vPoint->y * pMapTextureInfo->m_flLightmapVectors[0][1])
                                           + (float)(vPoint->x * pMapTextureInfo->m_flLightmapVectors[0][0]))
                                   + (float)(vPoint->z * pMapTextureInfo->m_flLightmapVectors[0][2]))
                           + pMapTextureInfo->m_flLightmapVectors[0][3];
        if ( v39 > flLightmapMax[0] )
          flLightmapMax[0] = v39;
        v40 = (float)((float)((float)(y * pMapTextureInfo->m_flLightmapVectors[1][1])
                            + (float)(x * pMapTextureInfo->m_flLightmapVectors[1][0]))
                    + (float)(z * pMapTextureInfo->m_flLightmapVectors[1][2]))
            + pMapTextureInfo->m_flLightmapVectors[1][3];
        if ( flLightmapMin[1] > v40 )
          flLightmapMin[1] = v40;
        if ( v40 > flLightmapMax[1] )
          flLightmapMax[1] = v40;
        bOnNodea += 12;
        ++nVertex;
      }
      while ( nVertex < *(_DWORD *)(*(_DWORD *)&pBSPFace + 24) );
    }
    for ( i = 0; i < 2; ++i )
    {
      v42 = (__m128)LODWORD(flLightmapMin[i]);
      v43.m128_i32[0] = 1258291200;
      v44 = _mm_and_ps((__m128)0x80000000, v42);
      v43.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v42, v44), v43).m128_f32[0]) & 0x4B000000
                      | v44.m128_i32[0];
      v45 = v42;
      v45.m128_f32[0] = (float)(v42.m128_f32[0] + v43.m128_f32[0]) - v43.m128_f32[0];
      v46 = v45;
      v46.m128_f32[0] = v45.m128_f32[0] - v42.m128_f32[0];
      bOnNodec = v45.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v46, v44).m128_u32[0] & 0x3F800000);
      flLightmapMin[i] = bOnNodec;
      newEdgea = ceil(X: flLightmapMax[i]);
      flLightmapMax[i] = newEdgea;
      fileFace.m_LightmapTextureMinsInLuxels[i] = (int)bOnNodec;
      fileFace.m_LightmapTextureSizeInLuxels[i] = (int)(float)(newEdgea - bOnNodec);
    }
    v47 = *(_DWORD *)(*(_DWORD *)&pBSPFace + 4);
    v48 = v5->m_VertexNormalList.m_Size;
    v49 = (int)&v5->m_PlaneHash.m_Planes.m_Memory.m_pMemory[v47];
    v50 = v5->m_VertexNormalList.m_Memory.m_nAllocationCount;
    bOnNodeb = v49;
    if ( v48 + 1 > v50 )
      CUtlMemory<Vector,int>::Grow(
        this: (CUtlMemory<MapEntityKeyValuePair_t,int> *)&v5->m_VertexNormalList,
        num: v48 - v50 + 1);
    ++v5->m_VertexNormalList.m_Size;
    v51 = v5->m_VertexNormalList.m_Memory.m_pMemory;
    v52 = v5->m_VertexNormalList.m_Size - v48 - 1;
    v5->m_VertexNormalList.m_pElements = v51;
    if ( v52 > 0 )
      _V_memmove(dest: &v51[v48 + 1], src: &v51[v48], count: 12 * v52);
    v53 = (int)&v5->m_VertexNormalList.m_Memory.m_pMemory[v48];
    if ( v53 != 0 )
    {
      *(_QWORD *)v53 = *(_QWORD *)bOnNodeb;
      *(_DWORD *)(v53 + 8) = *(_DWORD *)(bOnNodeb + 8);
    }
    v54 = v5->m_FaceList.m_Size;
    v55 = v5->m_FaceList.m_Memory.m_nAllocationCount;
    if ( v54 + 1 > v55 )
      CUtlMemory<dface_t,int>::Grow(this: &v5->m_FaceList.m_Memory, num: v54 - v55 + 1);
    ++v5->m_FaceList.m_Size;
    v56 = v5->m_FaceList.m_Memory.m_pMemory;
    v57 = v5->m_FaceList.m_Size - v54 - 1;
    v5->m_FaceList.m_pElements = v56;
    if ( v57 > 0 )
      _V_memmove(dest: &v56[v54 + 1], src: &v56[v54], count: 56 * v57);
    v58 = &v5->m_FaceList.m_Memory.m_pMemory[v54];
    if ( v58 != nullptr )
      *v58 = fileFace;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414D30
// Name: private: void CMemoryBSPFile::WriteBSPTreeData(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteBSPTreeData(CMemoryBSPFile *this, bool bPurgeWhenComplete)
{
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *p_m_LeafFaceList; // edi
  bool v4; // sf

  CMemoryBSPFile::WriteLump<dleaf_t>(
    this,
    nLump: 10,
    data: (const CUtlVector<dnode_t,CUtlMemory<dnode_t,int> > *)&this->m_LeafList,
    nVersion: 1);
  CMemoryBSPFile::WriteLump<CDispTri>(
    this,
    nLump: 17,
    data: (const CUtlVector<CDispTri,CUtlMemory<CDispTri,int> > *)&this->m_LeafBrushList,
    nVersion: 0);
  p_m_LeafFaceList = &this->m_LeafFaceList;
  CMemoryBSPFile::WriteLump<CDispTri>(
    this,
    nLump: 16,
    data: (const CUtlVector<CDispTri,CUtlMemory<CDispTri,int> > *)&this->m_LeafFaceList,
    nVersion: 0);
  CMemoryBSPFile::WriteLump<dleaf_t>(this, nLump: 5, data: &this->m_NodeList, nVersion: 0);
  if ( bPurgeWhenComplete )
  {
    v4 = this->m_LeafFaceList.m_Memory.m_nGrowSize < 0;
    this->m_LeafFaceList.m_Size = 0;
    if ( !v4 )
    {
      if ( p_m_LeafFaceList->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_LeafFaceList->m_Memory.m_pMemory);
        p_m_LeafFaceList->m_Memory.m_pMemory = nullptr;
      }
      this->m_LeafFaceList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_LeafFaceList.m_pElements = this->m_LeafFaceList.m_Memory.m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414DC0
// Name: private: int CMemoryBSPFile::EmitLeaf(class CBSPNode const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMemoryBSPFile::EmitLeaf(CMemoryBSPFile *this, const CBSPNode *pNode)
{
  CMemoryBSPFile *v2; // edi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  dleaf_t *m_pMemory; // ecx
  int v6; // eax
  int v8; // ecx
  __int16 m_nClusterIndex; // ax
  CUtlMemory<StaticPropLeafLump_t,int> *p_m_LeafBrushList; // esi
  int v11; // ecx
  StaticPropLeafLump_t *v12; // edi
  int v13; // eax
  StaticPropLeafLump_t *v14; // ecx
  int v15; // eax
  StaticPropLeafLump_t *v16; // edi
  int v17; // edi
  CBSPPortal *v18; // eax
  int v19; // esi
  int v20; // edi
  int v21; // eax
  unsigned __int16 *v22; // ecx
  int v23; // eax
  unsigned __int16 *v24; // edi
  int v25; // edx
  CBSPFace *v26; // eax
  unsigned __int16 m_nSerializedFaceIndex; // dx
  int v28; // edi
  int v29; // eax
  unsigned __int16 *v30; // edx
  int v31; // eax
  unsigned __int16 *v32; // edi
  int nIndex; // [esp+Ch] [ebp-18h]
  int nSerializedFaceIndex; // [esp+10h] [ebp-14h]
  unsigned __int16 nSerializedFaceIndexa; // [esp+10h] [ebp-14h]
  CBSPPortal **v37; // [esp+14h] [ebp-10h]
  unsigned __int16 v38; // [esp+18h] [ebp-Ch]
  int j; // [esp+18h] [ebp-Ch]
  dleaf_t *pNewLeaf; // [esp+20h] [ebp-4h]
  int i; // [esp+2Ch] [ebp+8h]
  int ia; // [esp+2Ch] [ebp+8h]
  int ib; // [esp+2Ch] [ebp+8h]

  v2 = this;
  m_Size = this->m_LeafList.m_Size;
  m_nAllocationCount = this->m_LeafList.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<dleaf_t,int>::Grow(
      this: (CUtlMemory<dtexdata_t,int> *)&this->m_LeafList,
      num: m_Size - m_nAllocationCount + 1);
  ++v2->m_LeafList.m_Size;
  m_pMemory = v2->m_LeafList.m_Memory.m_pMemory;
  v6 = v2->m_LeafList.m_Size - m_Size - 1;
  v2->m_LeafList.m_pElements = m_pMemory;
  if ( v6 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 32 * v6);
  nIndex = v2->m_LeafList.m_Size - 1;
  v8 = (int)&v2->m_LeafList.m_Memory.m_pMemory[nIndex];
  *(_QWORD *)v8 = 0;
  *(_QWORD *)(v8 + 8) = 0;
  *(_QWORD *)(v8 + 16) = 0;
  *(_QWORD *)(v8 + 24) = 0;
  *(_DWORD *)v8 = pNode->m_ContentsFlags;
  m_nClusterIndex = pNode->m_nClusterIndex;
  pNewLeaf = (dleaf_t *)v8;
  *(_WORD *)(v8 + 4) = m_nClusterIndex;
  if ( m_nClusterIndex == -1 )
    *(_WORD *)(v8 + 6) &= 0xFE00u;
  else
    *(_WORD *)(v8 + 6) = *(_WORD *)(v8 + 6) & 0xFE00 | 1;
  *(_WORD *)(v8 + 6) = *(_WORD *)(v8 + 6) & 0x1FF | 0x400;
  *(_WORD *)(v8 + 8) = (int)pNode->m_vMinBounds.x;
  *(_WORD *)(v8 + 10) = (int)pNode->m_vMinBounds.y;
  *(_WORD *)(v8 + 12) = (int)pNode->m_vMinBounds.z;
  *(_WORD *)(v8 + 14) = (int)pNode->m_vMaxBounds.x;
  *(_WORD *)(v8 + 16) = (int)pNode->m_vMaxBounds.y;
  *(_WORD *)(v8 + 18) = (int)pNode->m_vMaxBounds.z;
  *(_WORD *)(v8 + 20) = v2->m_LeafFaceList.m_Size;
  *(_WORD *)(v8 + 22) = 0;
  *(_WORD *)(v8 + 24) = v2->m_LeafBrushList.m_Size;
  *(_WORD *)(v8 + 26) = pNode->m_ClippedBrushes.m_Size;
  *(_WORD *)(v8 + 28) = -1;
  i = 0;
  if ( pNode->m_ClippedBrushes.m_Size > 0 )
  {
    p_m_LeafBrushList = (CUtlMemory<StaticPropLeafLump_t,int> *)&v2->m_LeafBrushList;
    while ( 1 )
    {
      v11 = (char *)pNode->m_ClippedBrushes.m_Memory.m_pMemory[i]->m_pOriginalBrush
          - (char *)v2->m_pMapFile->m_Brushes.m_Memory.m_pMemory;
      v12 = p_m_LeafBrushList[1].m_pMemory;
      v13 = p_m_LeafBrushList->m_nAllocationCount;
      v38 = v11 / 36;
      if ( (int)&v12->m_Leaf + 1 > v13 )
        CUtlMemory<unsigned short,int>::Grow(this: p_m_LeafBrushList, num: (int)&v12->m_Leaf - v13 + 1);
      ++p_m_LeafBrushList[1].m_pMemory;
      v14 = p_m_LeafBrushList->m_pMemory;
      v15 = (char *)p_m_LeafBrushList[1].m_pMemory - (char *)v12 - 1;
      p_m_LeafBrushList[1].m_nAllocationCount = (int)p_m_LeafBrushList->m_pMemory;
      if ( v15 > 0 )
        _V_memmove(dest: &v14[(_DWORD)v12 + 1], src: &v14[(_DWORD)v12], count: 2 * v15);
      v16 = &p_m_LeafBrushList->m_pMemory[(_DWORD)v12];
      if ( v16 != nullptr )
        v16->m_Leaf = v38;
      if ( ++i >= pNode->m_ClippedBrushes.m_Size )
        break;
      v2 = this;
    }
    v8 = (int)pNewLeaf;
  }
  v17 = 0;
  for ( j = 0; v17 < pNode->m_Portals.m_Size; j = v17 )
  {
    v18 = pNode->m_Portals.m_Memory.m_pMemory[v17];
    v19 = 0;
    for ( ia = 0; v19 < v18->m_PortalFaces.m_Size; ia = v19 )
    {
      nSerializedFaceIndex = v18->m_PortalFaces.m_Memory.m_pMemory[v19]->m_nSerializedFaceIndex;
      if ( nSerializedFaceIndex != -1 )
      {
        v37 = &pNode->m_Portals.m_Memory.m_pMemory[v17];
        if ( pNode == (*v37)->m_pNodes[CBSPPortal::GetNodeIndexForFace(this: *v37)] )
        {
          v20 = this->m_LeafFaceList.m_Size;
          v21 = this->m_LeafFaceList.m_Memory.m_nAllocationCount;
          if ( v20 + 1 > v21 )
            CUtlMemory<unsigned short,int>::Grow(
              this: (CUtlMemory<StaticPropLeafLump_t,int> *)&this->m_LeafFaceList,
              num: v20 - v21 + 1);
          ++this->m_LeafFaceList.m_Size;
          v22 = this->m_LeafFaceList.m_Memory.m_pMemory;
          v23 = this->m_LeafFaceList.m_Size - v20 - 1;
          this->m_LeafFaceList.m_pElements = v22;
          if ( v23 > 0 )
            _V_memmove(dest: &v22[v20 + 1], src: &v22[v20], count: 2 * v23);
          v24 = &this->m_LeafFaceList.m_Memory.m_pMemory[v20];
          if ( v24 != nullptr )
            *v24 = nSerializedFaceIndex;
          ++pNewLeaf->numleaffaces;
          v19 = ia;
          v17 = j;
          v8 = (int)pNewLeaf;
        }
        else
        {
          v8 = (int)pNewLeaf;
        }
      }
      v18 = pNode->m_Portals.m_Memory.m_pMemory[v17];
      ++v19;
    }
    ++v17;
  }
  v25 = 0;
  for ( ib = 0; v25 < pNode->m_Faces.m_Size; ib = v25 )
  {
    v26 = pNode->m_Faces.m_Memory.m_pMemory[v25];
    if ( v26->m_nSerializedFaceIndex != -1 )
    {
      m_nSerializedFaceIndex = v26->m_nSerializedFaceIndex;
      v28 = this->m_LeafFaceList.m_Size;
      v29 = this->m_LeafFaceList.m_Memory.m_nAllocationCount;
      nSerializedFaceIndexa = m_nSerializedFaceIndex;
      if ( v28 + 1 > v29 )
      {
        CUtlMemory<unsigned short,int>::Grow(
          this: (CUtlMemory<StaticPropLeafLump_t,int> *)&this->m_LeafFaceList,
          num: v28 - v29 + 1);
        v8 = (int)pNewLeaf;
      }
      ++this->m_LeafFaceList.m_Size;
      v30 = this->m_LeafFaceList.m_Memory.m_pMemory;
      v31 = this->m_LeafFaceList.m_Size - v28 - 1;
      this->m_LeafFaceList.m_pElements = v30;
      if ( v31 > 0 )
      {
        _V_memmove(dest: &v30[v28 + 1], src: &v30[v28], count: 2 * v31);
        v8 = (int)pNewLeaf;
      }
      v32 = &this->m_LeafFaceList.m_Memory.m_pMemory[v28];
      if ( v32 != nullptr )
        *v32 = nSerializedFaceIndexa;
      ++*(_WORD *)(v8 + 22);
      v25 = ib;
    }
    ++v25;
  }
  if ( *(_WORD *)(v8 + 22) == 0 )
    *(_WORD *)(v8 + 20) = 0;
  return -1 - nIndex;
}

//------------------------------------------------------------------------------
// Address: 0x00415170
// Name: private: int CMemoryBSPFile::EmitNode(class CBSPNode const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMemoryBSPFile::EmitNode(CMemoryBSPFile *this, const CBSPNode *pNode)
{
  int m_Size; // ebx
  dnode_t *v5; // eax
  unsigned __int16 v6; // dx
  int v7; // eax
  dnode_t *v8; // ecx
  int child0; // [esp+8h] [ebp-8h]

  if ( pNode->m_nSplitPlaneIndex == -1 )
    return CMemoryBSPFile::EmitLeaf(this, pNode);
  CUtlVector<dnode_t,CUtlMemory<dnode_t,int>>::AddToTail(this: &this->m_NodeList);
  m_Size = this->m_NodeList.m_Size;
  v5 = &this->m_NodeList.m_Memory.m_pMemory[m_Size - 1];
  *(_QWORD *)&v5->planenum = 0;
  *(_QWORD *)&v5->children[1] = 0;
  *(_QWORD *)&v5->mins[2] = 0;
  *(_QWORD *)&v5->firstface = 0;
  v5->planenum = pNode->m_nSplitPlaneIndex;
  v5->mins[0] = (int)pNode->m_vMinBounds.x;
  v5->mins[1] = (int)pNode->m_vMinBounds.y;
  v5->mins[2] = (int)pNode->m_vMinBounds.z;
  v5->maxs[0] = (int)pNode->m_vMaxBounds.x;
  v5->maxs[1] = (int)pNode->m_vMaxBounds.y;
  v5->maxs[2] = (int)pNode->m_vMaxBounds.z;
  if ( pNode->m_Faces.m_Size <= 0 )
    v5->firstface = 0;
  else
    v5->firstface = (*pNode->m_Faces.m_Memory.m_pMemory)->m_nSerializedFaceIndex;
  v6 = pNode->m_Faces.m_Size;
  v5->area = 0;
  v5->numfaces = v6;
  child0 = CMemoryBSPFile::EmitNode(this, pNode: pNode->m_pChildren[0]);
  v7 = CMemoryBSPFile::EmitNode(this, pNode: pNode->m_pChildren[1]);
  v8 = &this->m_NodeList.m_Memory.m_pMemory[m_Size - 1];
  v8->children[1] = v7;
  v8->children[0] = child0;
  return m_Size - 1;
}

//------------------------------------------------------------------------------
// Address: 0x00415270
// Name: private: void CMemoryBSPFile::BuildEntityData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::BuildEntityData(CMemoryBSPFile *this)
{
  CMemoryBSPFile *v1; // ebx
  const CSimpleMapFile *m_pMapFile; // eax
  int v3; // edi
  int *v4; // esi
  int v5; // edi
  int v6; // edi
  int v7; // eax
  int v8; // ebx
  int p_m_pValue; // esi
  char *i; // eax
  char *j; // eax
  int v12; // eax
  int v13; // edi
  int v14; // esi
  char *k; // eax
  char *m; // eax
  bool v17; // zf
  int v18; // edi
  int m_nAllocationCount; // eax
  unsigned __int8 *v20; // ecx
  int v21; // eax
  char pString[2060]; // [esp+Ch] [ebp-1054h] BYREF
  char pDest[1024]; // [esp+818h] [ebp-848h] BYREF
  char v24[1024]; // [esp+C18h] [ebp-448h] BYREF
  CUtlBuffer v25; // [esp+1018h] [ebp-48h] BYREF
  CMemoryBSPFile *v26; // [esp+1048h] [ebp-18h]
  int v27; // [esp+104Ch] [ebp-14h]
  int v28; // [esp+1050h] [ebp-10h]
  int v29; // [esp+1054h] [ebp-Ch]
  MapEntityKeyValuePair_t *m_pMemory; // [esp+1058h] [ebp-8h]
  int v31; // [esp+105Ch] [ebp-4h]

  v1 = this;
  v26 = this;
  CUtlBuffer::CUtlBuffer(this: &v25, growSize: 0, initSize: 0, nFlags: 1u);
  CUtlBuffer::EnsureCapacity(this: &v25, num: 0x40000);
  m_pMapFile = v1->m_pMapFile;
  v3 = 0;
  m_pMemory = m_pMapFile->m_KeyValuePairs.m_Memory.m_pMemory;
  v29 = 1;
  v28 = 0;
  if ( m_pMapFile->m_Entities.m_Size > 0 )
  {
    while ( 1 )
    {
      v4 = (int *)&m_pMapFile->m_Entities.m_Memory.m_pMemory[v3];
      if ( v4[6] > 0 && ((1 << (v3 & 0x1F)) & v1->m_EntityExclusionFlags.m_Ints[v3 >> 5]) == 0 )
        break;
LABEL_33:
      m_pMapFile = v1->m_pMapFile;
      v28 = ++v3;
      if ( v3 >= m_pMapFile->m_Entities.m_Size )
        goto LABEL_34;
    }
    CUtlBuffer::PutString(this: &v25, pString: "{\n");
    if ( v3 != 0 )
    {
      if ( v3 < 1 || v4[4] <= 0 )
        goto LABEL_10;
      V_strncpy(pDest, pSrc: "model", maxLen: 1024);
      v5 = v29;
      V_snprintf(pDest: v24, maxLen: 1024, pFormat: "*%i", v29);
      v29 = v5 + 1;
      V_snprintf(pDest: pString, maxLen: 2058, pFormat: "\"%s\" \"%s\"\n", pDest, v24);
    }
    else
    {
      V_strncpy(pDest, pSrc: "world_maxs", maxLen: 1024);
      V_snprintf(
        pDest: v24,
        maxLen: 1024,
        pFormat: "%d %d %d",
        (int)v1->m_ModelList.m_Memory.m_pMemory->maxs.x,
        (int)v1->m_ModelList.m_Memory.m_pMemory->maxs.y,
        (int)v1->m_ModelList.m_Memory.m_pMemory->maxs.z);
      V_snprintf(pDest: pString, maxLen: 2058, pFormat: "\"%s\" \"%s\"\n", pDest, v24);
      CUtlBuffer::PutString(this: &v25, pString);
      V_strncpy(pDest, pSrc: "world_mins", maxLen: 1024);
      V_snprintf(
        pDest: v24,
        maxLen: 1024,
        pFormat: "%d %d %d",
        (int)v1->m_ModelList.m_Memory.m_pMemory->mins.x,
        (int)v1->m_ModelList.m_Memory.m_pMemory->mins.y,
        (int)v1->m_ModelList.m_Memory.m_pMemory->mins.z);
      V_snprintf(pDest: pString, maxLen: 2058, pFormat: "\"%s\" \"%s\"\n", pDest, v24);
    }
    CUtlBuffer::PutString(this: &v25, pString);
LABEL_10:
    v6 = v4[5];
    v7 = v4[6];
    v8 = v7 + v6 - 1;
    if ( v8 >= v6 )
    {
      p_m_pValue = (int)&m_pMemory[v8].m_pValue;
      v27 = v7;
      v31 = v7;
      do
      {
        if ( *(_BYTE *)(p_m_pValue + 4) == 0 )
        {
          V_strncpy(pDest, pSrc: *(const char **)(p_m_pValue - 4), maxLen: 1024);
          for ( i = &pDest[strlen(pDest)]; i >= pDest; *i-- = 0 )
          {
            if ( *i > 32 )
              break;
          }
          V_strncpy(pDest: v24, pSrc: *(const char **)p_m_pValue, maxLen: 1024);
          for ( j = &v24[strlen(v24)]; j >= v24; *j-- = 0 )
          {
            if ( *j > 32 )
              break;
          }
          V_snprintf(pDest: pString, maxLen: 2058, pFormat: "\"%s\" \"%s\"\n", pDest, v24);
          CUtlBuffer::PutString(this: &v25, pString);
        }
        p_m_pValue -= 12;
        --v31;
      }
      while ( v31 != 0 );
      if ( v6 <= v8 )
      {
        v12 = v6;
        v13 = v27;
        v14 = (int)&m_pMemory[v12].m_pValue;
        do
        {
          if ( *(_BYTE *)(v14 + 4) != 0 )
          {
            V_strncpy(pDest, pSrc: *(const char **)(v14 - 4), maxLen: 1024);
            for ( k = &pDest[strlen(pDest)]; k >= pDest; *k-- = 0 )
            {
              if ( *k > 32 )
                break;
            }
            V_strncpy(pDest: v24, pSrc: *(const char **)v14, maxLen: 1024);
            for ( m = &v24[strlen(v24)]; m >= v24; *m-- = 0 )
            {
              if ( *m > 32 )
                break;
            }
            V_snprintf(pDest: pString, maxLen: 2058, pFormat: "\"%s\" \"%s\"\n", pDest, v24);
            CUtlBuffer::PutString(this: &v25, pString);
          }
          v14 += 12;
          --v13;
        }
        while ( v13 != 0 );
      }
    }
    CUtlBuffer::PutString(this: &v25, pString: "}\n");
    v3 = v28;
    v1 = v26;
    goto LABEL_33;
  }
LABEL_34:
  v18 = v25.m_Put + 1;
  v17 = v25.m_Put == -1;
  v1->m_EntityData.m_Size = 0;
  if ( !v17 )
  {
    m_nAllocationCount = v1->m_EntityData.m_Memory.m_nAllocationCount;
    if ( v18 > m_nAllocationCount )
      CUtlMemory<char,int>::Grow(this: &v1->m_EntityData.m_Memory, num: v18 - m_nAllocationCount);
    v1->m_EntityData.m_Size += v18;
    v20 = v1->m_EntityData.m_Memory.m_pMemory;
    v21 = v1->m_EntityData.m_Size - v18;
    v1->m_EntityData.m_pElements = v20;
    if ( v21 > 0 && v18 > 0 )
      _V_memmove(dest: &v20[v18], src: v20, count: v21);
  }
  memcpy(dst: v1->m_EntityData.m_Memory.m_pMemory, src: v25.m_Memory.m_pMemory, count: v25.m_Put);
  v1->m_EntityData.m_Memory.m_pMemory[v25.m_Put] = 0;
  if ( v25.m_Memory.m_nGrowSize >= 0 && v25.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v25.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00415770
// Name: private: void CMemoryBSPFile::BuildVisibilityData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::BuildVisibilityData(CMemoryBSPFile *this)
{
  const CSimpleBSPFile *m_pSimpleBSPFile; // ecx
  int m_Size; // ebx
  const unsigned __int8 *m_pMemory; // eax
  int v5; // edi
  int m_nAllocationCount; // eax
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *p_m_VisibilityData; // esi
  unsigned __int8 *v8; // ecx
  int v9; // eax
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // edi
  int v12; // edi
  int v13; // ebx
  int v14; // eax
  unsigned __int8 *v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // ecx
  CMemoryBSPFile *v19; // eax
  int v20; // ebx
  int v21; // edi
  int v22; // eax
  unsigned __int8 *v23; // ecx
  int v24; // eax
  const unsigned __int8 *v25; // ecx
  int v26; // ebx
  int v27; // edx
  const unsigned __int8 *v28; // ecx
  int v29; // edi
  int v30; // eax
  unsigned __int8 *v31; // ecx
  int v32; // eax
  unsigned __int8 *v33; // eax
  CUtlBuffer visDataLumpHeader; // [esp+Ch] [ebp-4Ch] BYREF
  int nHeaderOffset; // [esp+3Ch] [ebp-1Ch]
  CMemoryBSPFile *v36; // [esp+40h] [ebp-18h]
  int v37; // [esp+44h] [ebp-14h]
  const unsigned __int8 *pVisibilityData; // [esp+48h] [ebp-10h]
  int nRowLength; // [esp+4Ch] [ebp-Ch]
  int nNumClusters; // [esp+50h] [ebp-8h]
  int nRepetitions; // [esp+54h] [ebp-4h]

  m_pSimpleBSPFile = this->m_pSimpleBSPFile;
  m_Size = m_pSimpleBSPFile->m_Clusters.m_Size;
  nRowLength = (m_Size + 7) / 8;
  m_pMemory = m_pSimpleBSPFile->m_VisibilityData.m_Memory.m_pMemory;
  v36 = this;
  nNumClusters = m_Size;
  pVisibilityData = m_pMemory;
  CUtlBuffer::CUtlBuffer(this: &visDataLumpHeader, growSize: 0, initSize: 0, nFlags: 0);
  if ( (visDataLumpHeader.m_Flags & 1) != 0 )
    CUtlBuffer::Printf(this: &visDataLumpHeader, pFmt: "%d", m_Size);
  else
    CUtlBuffer::PutTypeBin<int>(this: &visDataLumpHeader, src: m_Size);
  v5 = this->m_VisibilityData.m_Size;
  m_nAllocationCount = this->m_VisibilityData.m_Memory.m_nAllocationCount;
  p_m_VisibilityData = &this->m_VisibilityData;
  if ( v5 + 4 > m_nAllocationCount )
    CUtlMemory<char,int>::Grow(this: &p_m_VisibilityData->m_Memory, num: v5 - m_nAllocationCount + 4);
  p_m_VisibilityData->m_Size += 4;
  v8 = p_m_VisibilityData->m_Memory.m_pMemory;
  v9 = p_m_VisibilityData->m_Size - v5 - 4;
  p_m_VisibilityData->m_pElements = p_m_VisibilityData->m_Memory.m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &v8[v5 + 4], src: &v8[v5], count: v9);
  v10 = &p_m_VisibilityData->m_Memory.m_pMemory[v5];
  if ( v10 != nullptr )
    *v10 = m_Size;
  if ( &p_m_VisibilityData->m_Memory.m_pMemory[v5] != (unsigned __int8 *)-1 )
    p_m_VisibilityData->m_Memory.m_pMemory[v5 + 1] = BYTE1(m_Size);
  if ( &p_m_VisibilityData->m_Memory.m_pMemory[v5] != (unsigned __int8 *)-2 )
    p_m_VisibilityData->m_Memory.m_pMemory[v5 + 2] = BYTE2(nNumClusters);
  v11 = &p_m_VisibilityData->m_Memory.m_pMemory[v5 + 3];
  if ( v11 != nullptr )
    *v11 = HIBYTE(nNumClusters);
  v12 = 8 * m_Size;
  v13 = p_m_VisibilityData->m_Size;
  if ( v12 != 0 )
  {
    v14 = p_m_VisibilityData->m_Memory.m_nAllocationCount;
    if ( v13 + v12 > v14 )
      CUtlMemory<char,int>::Grow(this: &p_m_VisibilityData->m_Memory, num: v12 + v13 - v14);
    p_m_VisibilityData->m_Size += v12;
    v15 = p_m_VisibilityData->m_Memory.m_pMemory;
    v16 = p_m_VisibilityData->m_Size - v13 - v12;
    p_m_VisibilityData->m_pElements = p_m_VisibilityData->m_Memory.m_pMemory;
    if ( v16 > 0 && v12 > 0 )
      _V_memmove(dest: &v15[v13 + v12], src: &v15[v13], count: v16);
  }
  v17 = nNumClusters;
  v18 = 4;
  if ( nNumClusters > 0 )
  {
    nNumClusters = 0;
    v37 = v17;
    do
    {
      v19 = v36;
      *(_DWORD *)&p_m_VisibilityData->m_Memory.m_pMemory[v18] = v36->m_VisibilityData.m_Size;
      *(_DWORD *)&p_m_VisibilityData->m_Memory.m_pMemory[v18 + 4] = v19->m_VisibilityData.m_Size;
      v18 += 8;
      v20 = 0;
      nHeaderOffset = v18;
      if ( nRowLength > 0 )
      {
        do
        {
          v21 = p_m_VisibilityData->m_Size;
          v22 = p_m_VisibilityData->m_Memory.m_nAllocationCount;
          if ( v21 + 1 > v22 )
            CUtlMemory<char,int>::Grow(this: &p_m_VisibilityData->m_Memory, num: v21 - v22 + 1);
          ++p_m_VisibilityData->m_Size;
          v23 = p_m_VisibilityData->m_Memory.m_pMemory;
          v24 = p_m_VisibilityData->m_Size - v21 - 1;
          p_m_VisibilityData->m_pElements = p_m_VisibilityData->m_Memory.m_pMemory;
          if ( v24 > 0 )
            _V_memmove(dest: &v23[v21 + 1], src: &v23[v21], count: v24);
          v25 = pVisibilityData;
          if ( &p_m_VisibilityData->m_Memory.m_pMemory[v21] != nullptr )
            p_m_VisibilityData->m_Memory.m_pMemory[v21] = pVisibilityData[v20 + nNumClusters];
          if ( v25[v20 + nNumClusters] == 0 )
          {
            v26 = v20 + 1;
            v27 = 1;
            nRepetitions = 1;
            if ( v26 < nRowLength )
            {
              v28 = &v25[nNumClusters];
              do
              {
                if ( v28[v26] != 0 )
                  break;
                if ( v27 == 255 )
                  break;
                ++v26;
                ++v27;
              }
              while ( v26 < nRowLength );
              nRepetitions = v27;
            }
            v29 = p_m_VisibilityData->m_Size;
            v30 = p_m_VisibilityData->m_Memory.m_nAllocationCount;
            if ( v29 + 1 > v30 )
            {
              CUtlMemory<char,int>::Grow(this: &p_m_VisibilityData->m_Memory, num: v29 - v30 + 1);
              LOBYTE(v27) = nRepetitions;
            }
            ++p_m_VisibilityData->m_Size;
            v31 = p_m_VisibilityData->m_Memory.m_pMemory;
            v32 = p_m_VisibilityData->m_Size - v29 - 1;
            p_m_VisibilityData->m_pElements = p_m_VisibilityData->m_Memory.m_pMemory;
            if ( v32 > 0 )
            {
              _V_memmove(dest: &v31[v29 + 1], src: &v31[v29], count: v32);
              LOBYTE(v27) = nRepetitions;
            }
            v33 = &p_m_VisibilityData->m_Memory.m_pMemory[v29];
            if ( v33 != nullptr )
              *v33 = v27;
            v20 = v26 - 1;
          }
          ++v20;
        }
        while ( v20 < nRowLength );
        v18 = nHeaderOffset;
      }
      nNumClusters += nRowLength;
      --v37;
    }
    while ( v37 != 0 );
  }
  if ( visDataLumpHeader.m_Memory.m_nGrowSize >= 0 && visDataLumpHeader.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: visDataLumpHeader.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004159F0
// Name: private: int CMemoryBSPFile::RemapWorldMaterial(class CUtlVector<int,class CUtlMemory<int,int>> __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMemoryBSPFile::RemapWorldMaterial(
        CMemoryBSPFile *this,
        CUtlVector<int,CUtlMemory<int,int> > *pWorldPropertyRemapList,
        int nSurfacePropertyIndex)
{
  int m_Size; // edi
  int result; // eax
  int *v5; // ecx
  int m_nAllocationCount; // ecx
  int *m_pMemory; // ecx
  int v8; // eax
  int *v9; // eax

  m_Size = pWorldPropertyRemapList->m_Size;
  result = 0;
  if ( m_Size <= 0 )
  {
LABEL_5:
    m_nAllocationCount = pWorldPropertyRemapList->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<ColorRGBExp32,int>::Grow(
        this: (CUtlMemory<BSPCluster_t,int> *)pWorldPropertyRemapList,
        num: m_Size - m_nAllocationCount + 1);
    ++pWorldPropertyRemapList->m_Size;
    m_pMemory = pWorldPropertyRemapList->m_Memory.m_pMemory;
    v8 = pWorldPropertyRemapList->m_Size - m_Size - 1;
    pWorldPropertyRemapList->m_pElements = pWorldPropertyRemapList->m_Memory.m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
    v9 = &pWorldPropertyRemapList->m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = nSurfacePropertyIndex;
    return m_Size + 1;
  }
  else
  {
    v5 = pWorldPropertyRemapList->m_Memory.m_pMemory;
    while ( 1 )
    {
      ++result;
      if ( *v5 == nSurfacePropertyIndex )
        break;
      ++v5;
      if ( result >= m_Size )
        goto LABEL_5;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00415A70
// Name: private: void CMemoryBSPFile::WritePhysicsCollisionData(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WritePhysicsCollisionData(CMemoryBSPFile *this, bool bPurgeWhenComplete)
{
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *p_m_PhysicsDisplacementData; // edi

  p_m_PhysicsDisplacementData = &this->m_PhysicsDisplacementData;
  CMemoryBSPFile::WriteLump<char>(
    this,
    nLump: 28,
    data: (const CUtlVector<char,CUtlMemory<char,int> > *)&this->m_PhysicsDisplacementData,
    nVersion: 0);
  CMemoryBSPFile::WriteLump<char>(
    this,
    nLump: 29,
    data: (const CUtlVector<char,CUtlMemory<char,int> > *)&this->m_PhysicsCollideData,
    nVersion: 0);
  if ( bPurgeWhenComplete )
  {
    p_m_PhysicsDisplacementData->m_Size = 0;
    if ( p_m_PhysicsDisplacementData->m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_PhysicsDisplacementData->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_PhysicsDisplacementData->m_Memory.m_pMemory);
        p_m_PhysicsDisplacementData->m_Memory.m_pMemory = nullptr;
      }
      p_m_PhysicsDisplacementData->m_Memory.m_nAllocationCount = 0;
    }
    p_m_PhysicsDisplacementData->m_pElements = p_m_PhysicsDisplacementData->m_Memory.m_pMemory;
    this->m_PhysicsCollideData.m_Size = 0;
    if ( this->m_PhysicsCollideData.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_PhysicsCollideData.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_PhysicsCollideData.m_Memory.m_pMemory);
        this->m_PhysicsCollideData.m_Memory.m_pMemory = nullptr;
      }
      this->m_PhysicsCollideData.m_Memory.m_nAllocationCount = 0;
    }
    this->m_PhysicsCollideData.m_pElements = this->m_PhysicsCollideData.m_Memory.m_pMemory;
    this->m_FaceList.m_Size = 0;
    if ( this->m_FaceList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_FaceList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FaceList.m_Memory.m_pMemory);
        this->m_FaceList.m_Memory.m_pMemory = nullptr;
      }
      this->m_FaceList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_FaceList.m_pElements = this->m_FaceList.m_Memory.m_pMemory;
    this->m_ModelList.m_Size = 0;
    if ( this->m_ModelList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_ModelList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ModelList.m_Memory.m_pMemory);
        this->m_ModelList.m_Memory.m_pMemory = nullptr;
      }
      this->m_ModelList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_ModelList.m_pElements = this->m_ModelList.m_Memory.m_pMemory;
    this->m_LeafList.m_Size = 0;
    if ( this->m_LeafList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_LeafList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_LeafList.m_Memory.m_pMemory);
        this->m_LeafList.m_Memory.m_pMemory = nullptr;
      }
      this->m_LeafList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_LeafList.m_pElements = this->m_LeafList.m_Memory.m_pMemory;
    this->m_LeafBrushList.m_Size = 0;
    if ( this->m_LeafBrushList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_LeafBrushList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_LeafBrushList.m_Memory.m_pMemory);
        this->m_LeafBrushList.m_Memory.m_pMemory = nullptr;
      }
      this->m_LeafBrushList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_LeafBrushList.m_pElements = this->m_LeafBrushList.m_Memory.m_pMemory;
    this->m_NodeList.m_Size = 0;
    if ( this->m_NodeList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( this->m_NodeList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_NodeList.m_Memory.m_pMemory);
        this->m_NodeList.m_Memory.m_pMemory = nullptr;
      }
      this->m_NodeList.m_Memory.m_nAllocationCount = 0;
    }
    this->m_NodeList.m_pElements = this->m_NodeList.m_Memory.m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415C60
// Name: private: void CMemoryBSPFile::WriteLightingData(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WriteLightingData(CMemoryBSPFile *this, bool bPurgeWhenComplete)
{
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *p_m_LightingData; // edi
  CUtlVector<dworldlight_t,CUtlMemory<dworldlight_t,int> > *p_m_WorldLightsLDR; // ebx
  CUtlVector<dworldlight_t,CUtlMemory<dworldlight_t,int> > *p_m_WorldLightsHDR; // [esp+Ch] [ebp-4h]

  p_m_LightingData = &this->m_LightingData;
  CMemoryBSPFile::WriteLump<char>(
    this,
    nLump: 8,
    data: (const CUtlVector<char,CUtlMemory<char,int> > *)&this->m_LightingData,
    nVersion: 1);
  p_m_WorldLightsLDR = &this->m_WorldLightsLDR;
  CMemoryBSPFile::WriteLump<dworldlight_t>(this, nLump: 15, data: &this->m_WorldLightsLDR, nVersion: 1);
  p_m_WorldLightsHDR = &this->m_WorldLightsHDR;
  CMemoryBSPFile::WriteLump<dworldlight_t>(this, nLump: 54, data: &this->m_WorldLightsHDR, nVersion: 1);
  if ( bPurgeWhenComplete )
  {
    p_m_LightingData->m_Size = 0;
    if ( p_m_LightingData->m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_LightingData->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_LightingData->m_Memory.m_pMemory);
        p_m_LightingData->m_Memory.m_pMemory = nullptr;
      }
      p_m_LightingData->m_Memory.m_nAllocationCount = 0;
    }
    p_m_LightingData->m_pElements = p_m_LightingData->m_Memory.m_pMemory;
    this->m_WorldLightsLDR.m_Size = 0;
    if ( this->m_WorldLightsLDR.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_WorldLightsLDR->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_WorldLightsLDR->m_Memory.m_pMemory);
        p_m_WorldLightsLDR->m_Memory.m_pMemory = nullptr;
      }
      this->m_WorldLightsLDR.m_Memory.m_nAllocationCount = 0;
    }
    this->m_WorldLightsLDR.m_pElements = this->m_WorldLightsLDR.m_Memory.m_pMemory;
    this->m_WorldLightsHDR.m_Size = 0;
    if ( this->m_WorldLightsHDR.m_Memory.m_nGrowSize >= 0 )
    {
      if ( p_m_WorldLightsHDR->m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_WorldLightsHDR->m_Memory.m_pMemory);
        p_m_WorldLightsHDR->m_Memory.m_pMemory = nullptr;
      }
      this->m_WorldLightsHDR.m_Memory.m_nAllocationCount = 0;
    }
    this->m_WorldLightsHDR.m_pElements = this->m_WorldLightsHDR.m_Memory.m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00415FE0
// Name: public: void CMemoryBSPFile::Serialize(class CUtlBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::Serialize(CMemoryBSPFile *this, CUtlBuffer *pOutputBuffer)
{
  CUtlBuffer *v3; // ecx
  int pData; // [esp+Ch] [ebp-1Ch] BYREF
  __int64 v5; // [esp+10h] [ebp-18h]
  int v6; // [esp+18h] [ebp-10h]
  __int16 v7; // [esp+1Ch] [ebp-Ch] BYREF
  __int64 v8; // [esp+1Eh] [ebp-Ah]
  __int16 v9; // [esp+26h] [ebp-2h]

  v3 = pOutputBuffer;
  this->m_pSerialBuffer = pOutputBuffer;
  CUtlBuffer::SeekPut(this: v3, type: SEEK_HEAD, offset: 0);
  memset(dst: (unsigned __int8 *)this->m_FileHeader.lumps, value: 0, count: sizeof(this->m_FileHeader.lumps));
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)&this->m_FileHeader, size: 1036);
  CMemoryBSPFile::WriteLump<texinfo_s>(this, nLump: 6, data: &this->m_TexInfoList, nVersion: 0);
  CMemoryBSPFile::WriteLump<dleaf_t>(
    this,
    nLump: 2,
    data: (const CUtlVector<dnode_t,CUtlMemory<dnode_t,int> > *)&this->m_TexDataList,
    nVersion: 0);
  CMemoryBSPFile::WriteLump<char>(this, nLump: 43, data: &this->m_TexStringData, nVersion: 0);
  CMemoryBSPFile::WriteLump<dedge_t>(
    this,
    nLump: 44,
    data: (const CUtlVector<dedge_t,CUtlMemory<dedge_t,int> > *)&this->m_TexStringIndices,
    nVersion: 0);
  CMemoryBSPFile::WriteLump<Vector>(
    this,
    nLump: 3,
    data: (const CUtlVector<dbrush_t,CUtlMemory<dbrush_t,int> > *)&this->m_VertexHash.m_Vertices,
    nVersion: 0);
  CMemoryBSPFile::WriteLump<dedge_t>(this, nLump: 12, data: &this->m_EdgeList, nVersion: 0);
  CMemoryBSPFile::WriteLump<dedge_t>(
    this,
    nLump: 13,
    data: (const CUtlVector<dedge_t,CUtlMemory<dedge_t,int> > *)&this->m_SurfEdgeList,
    nVersion: 0);
  CMemoryBSPFile::WriteLump<dface_t>(this, nLump: 7, data: &this->m_FaceList, nVersion: 1);
  CMemoryBSPFile::WriteLump<Vector>(
    this,
    nLump: 30,
    data: (const CUtlVector<dbrush_t,CUtlMemory<dbrush_t,int> > *)&this->m_VertexNormalList,
    nVersion: 0);
  CMemoryBSPFile::WriteLump<CDispTri>(
    this,
    nLump: 31,
    data: (const CUtlVector<CDispTri,CUtlMemory<CDispTri,int> > *)&this->m_VertexNormalIndexList,
    nVersion: 0);
  CMemoryBSPFile::WriteLump<dleaf_t>(
    this,
    nLump: 10,
    data: (const CUtlVector<dnode_t,CUtlMemory<dnode_t,int> > *)&this->m_LeafList,
    nVersion: 1);
  CMemoryBSPFile::WriteLump<CDispTri>(
    this,
    nLump: 17,
    data: (const CUtlVector<CDispTri,CUtlMemory<CDispTri,int> > *)&this->m_LeafBrushList,
    nVersion: 0);
  CMemoryBSPFile::WriteLump<CDispTri>(
    this,
    nLump: 16,
    data: (const CUtlVector<CDispTri,CUtlMemory<CDispTri,int> > *)&this->m_LeafFaceList,
    nVersion: 0);
  CMemoryBSPFile::WriteLump<dleaf_t>(this, nLump: 5, data: &this->m_NodeList, nVersion: 0);
  CMemoryBSPFile::WriteLump<Vector>(this, nLump: 18, data: &this->m_BrushList, nVersion: 0);
  CMemoryBSPFile::WriteLump<dbrushside_t>(this, nLump: 19, data: &this->m_BrushSideList, nVersion: 0);
  CMemoryBSPFile::WriteLump<dplane_t>(
    this,
    nLump: 1,
    data: (const CUtlVector<CDispVert,CUtlMemory<CDispVert,int> > *)&this->m_Planes,
    nVersion: 0);
  CMemoryBSPFile::WriteLump<dmodel_t>(this, nLump: 14, data: &this->m_ModelList, nVersion: 0);
  v7 = 0;
  v8 = 0;
  v9 = 0;
  pData = 0;
  v5 = 0;
  v6 = 1;
  CMemoryBSPFile::WriteLump(this, nLump: 20, (unsigned __int8 *)&pData, nByteLength: 16, nVersion: 0);
  CMemoryBSPFile::WriteLump(this, nLump: 21, pData: (unsigned __int8 *)&v7, nByteLength: 12, nVersion: 0);
  CMemoryBSPFile::WriteLump<char>(
    this,
    nLump: 35,
    data: (const CUtlVector<char,CUtlMemory<char,int> > *)&this->m_GameLumpData,
    nVersion: 0);
  CMemoryBSPFile::WriteLump<char>(
    this,
    nLump: 0,
    data: (const CUtlVector<char,CUtlMemory<char,int> > *)&this->m_EntityData,
    nVersion: 0);
  CMemoryBSPFile::WriteLump<char>(
    this,
    nLump: 4,
    data: (const CUtlVector<char,CUtlMemory<char,int> > *)&this->m_VisibilityData,
    nVersion: 0);
  pOutputBuffer = nullptr;
  CMemoryBSPFile::WriteLump(this, nLump: 34, pData: (unsigned __int8 *)&pOutputBuffer, nByteLength: 4, nVersion: 0);
  CMemoryBSPFile::WriteLump<ddispinfo_t>(this, nLump: 26, data: &this->m_DisplacementList, nVersion: 0);
  CMemoryBSPFile::WriteLump<dplane_t>(this, nLump: 33, data: &this->m_DisplacementVertexList, nVersion: 0);
  CMemoryBSPFile::WriteLump<CDispTri>(this, nLump: 48, data: &this->m_DisplacementTriangleList, nVersion: 0);
  CMemoryBSPFile::WriteLump<CDispMultiBlend>(this, nLump: 63, data: &this->m_DisplacementMultiBlendList, nVersion: 0);
  CMemoryBSPFile::WriteLump<char>(
    this,
    nLump: 28,
    data: (const CUtlVector<char,CUtlMemory<char,int> > *)&this->m_PhysicsDisplacementData,
    nVersion: 0);
  CMemoryBSPFile::WriteLump<char>(
    this,
    nLump: 29,
    data: (const CUtlVector<char,CUtlMemory<char,int> > *)&this->m_PhysicsCollideData,
    nVersion: 0);
  CMemoryBSPFile::WriteLump<char>(
    this,
    nLump: 8,
    data: (const CUtlVector<char,CUtlMemory<char,int> > *)&this->m_LightingData,
    nVersion: 1);
  CMemoryBSPFile::WriteLump<dworldlight_t>(this, nLump: 15, data: &this->m_WorldLightsLDR, nVersion: 1);
  CMemoryBSPFile::WriteLump<dworldlight_t>(this, nLump: 54, data: &this->m_WorldLightsHDR, nVersion: 1);
  CUtlBuffer::SeekPut(this: this->m_pSerialBuffer, type: SEEK_HEAD, offset: 0);
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)&this->m_FileHeader, size: 1036);
}

//------------------------------------------------------------------------------
// Address: 0x004162A0
// Name: private: void CMemoryBSPFile::BuildTexInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::BuildTexInfo(CMemoryBSPFile *this)
{
  const CSimpleMapFile *m_pMapFile; // eax
  int m_Size; // esi
  MapTextureInfo_t *m_pMemory; // edi
  CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int> > *p_m_TexInfoList; // ebx
  unsigned __int8 *p_m_SurfaceFlags; // edi
  int v6; // eax
  int v7; // esi
  int v8; // ecx
  bool v9; // zf
  int i; // [esp+Ch] [ebp-8h]
  const MapTextureInfo_t *pTextureInfos; // [esp+10h] [ebp-4h]
  const MapTextureInfo_t *pTextureInfosa; // [esp+10h] [ebp-4h]

  m_pMapFile = this->m_pMapFile;
  m_Size = m_pMapFile->m_TextureInfos.m_Size;
  m_pMemory = m_pMapFile->m_TextureInfos.m_Memory.m_pMemory;
  p_m_TexInfoList = &this->m_TexInfoList;
  pTextureInfos = m_pMemory;
  this->m_TexInfoList.m_Size = 0;
  CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int>>::InsertMultipleBefore(
    this: &this->m_TexInfoList,
    elem: 0,
    num: m_Size);
  if ( m_Size > 0 )
  {
    p_m_SurfaceFlags = (unsigned __int8 *)&m_pMemory->m_SurfaceFlags;
    v6 = -68 - (_DWORD)pTextureInfos;
    pTextureInfosa = (const MapTextureInfo_t *)m_Size;
    for ( i = v6; ; v6 = i )
    {
      v7 = (int)p_m_TexInfoList->m_Memory.m_pMemory + (unsigned int)&p_m_SurfaceFlags[v6];
      _V_memcpy(dest: (unsigned __int8 *)v7, src: p_m_SurfaceFlags - 68, count: 0x20u);
      _V_memcpy(dest: (unsigned __int8 *)(v7 + 32), src: p_m_SurfaceFlags - 36, count: 0x20u);
      *(_DWORD *)(v7 + 64) = *(__int16 *)p_m_SurfaceFlags;
      v8 = *((_DWORD *)p_m_SurfaceFlags - 1);
      p_m_SurfaceFlags += 72;
      v9 = pTextureInfosa == (const MapTextureInfo_t *)1;
      pTextureInfosa = (const MapTextureInfo_t *)((char *)pTextureInfosa - 1);
      *(_DWORD *)(v7 + 68) = v8;
      if ( v9 )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416340
// Name: private: void CMemoryBSPFile::BuildTexData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::BuildTexData(CMemoryBSPFile *this)
{
  CMemoryBSPFile *v1; // esi
  const CSimpleMapFile *m_pMapFile; // eax
  int m_Size; // ebx
  MapTextureData_t *m_pMemory; // edi
  CUtlVector<dtexdata_t,CUtlMemory<dtexdata_t,int> > *p_m_TexDataList; // ecx
  int v6; // ebx
  float *p_z; // edi
  dtexdata_t *v8; // esi
  dtexdata_t *v9; // esi
  int v10; // eax
  int v11; // eax
  bool v12; // zf
  int nTextureDataCount; // [esp+Ch] [ebp-8h]
  CMemoryBSPFile *v14; // [esp+10h] [ebp-4h]

  v1 = this;
  m_pMapFile = this->m_pMapFile;
  m_Size = m_pMapFile->m_TextureData.m_Size;
  m_pMemory = m_pMapFile->m_TextureData.m_Memory.m_pMemory;
  p_m_TexDataList = &this->m_TexDataList;
  v14 = v1;
  nTextureDataCount = m_Size;
  p_m_TexDataList->m_Size = 0;
  CUtlVector<dnode_t,CUtlMemory<dnode_t,int>>::InsertMultipleBefore(this: p_m_TexDataList, elem: 0, num: m_Size);
  if ( m_Size > 0 )
  {
    v6 = 0;
    p_z = &m_pMemory->m_vReflectivity.z;
    while ( 1 )
    {
      v8 = v1->m_TexDataList.m_Memory.m_pMemory;
      v8[v6].reflectivity.x = *(p_z - 2);
      v9 = &v8[v6];
      v9->reflectivity.y = *(p_z - 1);
      v9->reflectivity.z = *p_z;
      v9->nameStringTableID = CMemoryBSPFile::FindOrAddString(this: v14, pString: (const char *)p_z + 12);
      v10 = *((_DWORD *)p_z + 1);
      v9->view_width = v10;
      v9->width = v10;
      v11 = *((_DWORD *)p_z + 2);
      ++v6;
      p_z += 37;
      v12 = nTextureDataCount-- == 1;
      v9->view_height = v11;
      v9->height = v11;
      if ( v12 )
        break;
      v1 = v14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004163F0
// Name: private: void CMemoryBSPFile::WritePortalFaces(class CBSPNode const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::WritePortalFaces(CMemoryBSPFile *this, const CBSPNode *pNode)
{
  const CBSPNode *i; // esi
  int j; // edi

  for ( i = pNode; i->m_nSplitPlaneIndex != -1; i = i->m_pChildren[1] )
  {
    for ( j = 0; j < i->m_Faces.m_Size; ++j )
      CMemoryBSPFile::EmitFace(this, pBSPFace: (dedge_t)i->m_Faces.m_Memory.m_pMemory[j], bOnNode: 1u);
    CMemoryBSPFile::WritePortalFaces(this, pNode: i->m_pChildren[0]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416440
// Name: private: void CMemoryBSPFile::BuildBSPTreeData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::BuildBSPTreeData(CMemoryBSPFile *this)
{
  int m_Size; // edx
  int v3; // ebx
  const CSimpleBSPFile *m_pSimpleBSPFile; // eax
  dmodel_t *v5; // edi
  int v6; // eax
  dleaf_t sentinelLeaf; // [esp+8h] [ebp-24h] BYREF
  unsigned int v8; // [esp+28h] [ebp-4h]

  m_Size = this->m_LeafList.m_Size;
  v3 = 0;
  memset(&sentinelLeaf.cluster, 0, 28);
  sentinelLeaf.contents = 1;
  CUtlVector<dleaf_t,CUtlMemory<dleaf_t,int>>::InsertBefore(this: &this->m_LeafList, elem: m_Size, src: &sentinelLeaf);
  m_pSimpleBSPFile = this->m_pSimpleBSPFile;
  if ( m_pSimpleBSPFile->m_Models.m_Size > 0 )
  {
    v8 = 0;
    do
    {
      v5 = &this->m_ModelList.m_Memory.m_pMemory[v8 / 0x30];
      v6 = CMemoryBSPFile::EmitNode(this, pNode: m_pSimpleBSPFile->m_Models.m_Memory.m_pMemory[v3]->m_pTree->m_pRoot);
      v8 += 48;
      v5->headnode = v6;
      m_pSimpleBSPFile = this->m_pSimpleBSPFile;
      ++v3;
    }
    while ( v3 < m_pSimpleBSPFile->m_Models.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004164D0
// Name: private: void CMemoryBSPFile::BuildBrushes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::BuildBrushes(CMemoryBSPFile *this)
{
  CMemoryBSPFile *v1; // edi
  int m_Size; // esi
  CUtlVector<Vector,CUtlMemory<Vector,int> > *p_m_BrushList; // ecx
  dbrush_t *v4; // eax
  const MapBrush_t *v5; // edx
  int v6; // ebx
  CUtlMemory<dbrushside_t,int> *p_m_Memory; // esi
  const CSimpleMapFile *m_pMapFile; // ecx
  dbrushside_t *m_pMemory; // edi
  int v10; // eax
  int m_nAllocationCount; // eax
  dbrushside_t *v12; // ecx
  int v13; // eax
  dbrushside_t *v14; // eax
  float *p_x; // edx
  int v16; // ebx
  float flDistance; // xmm0_4
  int PlaneIndex; // eax
  int m_nNumSides; // edx
  int v20; // ecx
  int *p_m_nPlaneIndex; // esi
  CUtlMemory<dbrushside_t,int> *v22; // esi
  int v23; // edi
  int v24; // eax
  dbrushside_t *v25; // ecx
  int v26; // eax
  dbrushside_t *v27; // eax
  int v28; // ecx
  Vector vNormal; // [esp+10h] [ebp-44h] BYREF
  int v30; // [esp+1Ch] [ebp-38h]
  int v31; // [esp+20h] [ebp-34h]
  dbrushside_t brushSide; // [esp+24h] [ebp-30h]
  dbrush_t *brush; // [esp+2Ch] [ebp-28h]
  int i; // [esp+30h] [ebp-24h]
  int v35; // [esp+34h] [ebp-20h]
  int nSide; // [esp+38h] [ebp-1Ch]
  unsigned int v37; // [esp+3Ch] [ebp-18h]
  unsigned int v38; // [esp+40h] [ebp-14h]
  Vector *p_vNormal; // [esp+44h] [ebp-10h]
  CMemoryBSPFile *v40; // [esp+48h] [ebp-Ch]
  const MapBrush_t *pMapBrush; // [esp+4Ch] [ebp-8h]
  float *v42; // [esp+50h] [ebp-4h]

  v1 = this;
  m_Size = this->m_pMapFile->m_Brushes.m_Size;
  p_m_BrushList = (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_BrushList;
  v40 = v1;
  p_m_BrushList->m_Size = 0;
  CUtlVector<dbrush_t,CUtlMemory<dbrush_t,int>>::InsertMultipleBefore(this: p_m_BrushList, elem: 0, num: m_Size);
  if ( m_Size > 0 )
  {
    v37 = 0;
    v38 = 0;
    for ( i = m_Size; i != 0; --i )
    {
      v4 = &v1->m_BrushList.m_Memory.m_pMemory[v37 / 0xC];
      v5 = &v1->m_pMapFile->m_Brushes.m_Memory.m_pMemory[v38 / 0x24];
      v4->firstside = v1->m_BrushSideList.m_Size;
      v4->numsides = v5->m_nNumSides;
      v6 = 0;
      v4->contents = v5->m_ContentsFlags;
      pMapBrush = v5;
      brush = v4;
      if ( v5->m_nNumSides > 0 )
      {
        p_m_Memory = &v1->m_BrushSideList.m_Memory;
        do
        {
          m_pMapFile = v1->m_pMapFile;
          m_pMemory = p_m_Memory[1].m_pMemory;
          v10 = (int)&m_pMapFile->m_BrushSides.m_Memory.m_pMemory[v6 + v5->m_nFirstSideIndex];
          LOWORD(m_pMapFile) = *(_WORD *)(v10 + 8);
          LOWORD(v10) = *(_WORD *)(v10 + 12);
          brushSide.planenum = (unsigned __int16)m_pMapFile;
          brushSide.texinfo = v10;
          m_nAllocationCount = p_m_Memory->m_nAllocationCount;
          brushSide.dispinfo = 0;
          brushSide.bevel = 0;
          if ( (int)&m_pMemory->planenum + 1 > m_nAllocationCount )
          {
            CUtlMemory<dbrushside_t,int>::Grow(
              this: p_m_Memory,
              num: (int)&m_pMemory->planenum - m_nAllocationCount + 1);
            v5 = pMapBrush;
          }
          ++p_m_Memory[1].m_pMemory;
          v12 = p_m_Memory->m_pMemory;
          v13 = (char *)p_m_Memory[1].m_pMemory - (char *)m_pMemory - 1;
          p_m_Memory[1].m_nAllocationCount = (int)p_m_Memory->m_pMemory;
          if ( v13 > 0 )
          {
            _V_memmove(dest: &v12[(int)m_pMemory + 1], src: &v12[(_DWORD)m_pMemory], count: 8 * v13);
            v5 = pMapBrush;
          }
          v14 = &p_m_Memory->m_pMemory[(_DWORD)m_pMemory];
          if ( v14 != nullptr )
            *v14 = brushSide;
          v1 = v40;
          ++v6;
        }
        while ( v6 < v5->m_nNumSides );
      }
      p_x = &v5->m_vMaxBounds.x;
      v16 = -1;
      p_vNormal = &vNormal;
      v42 = p_x;
      v35 = 3;
      for ( nSide = -1; ; nSide = -1 )
      {
        while ( 1 )
        {
          vNormal = vec3_origin;
          p_vNormal->x = (float)v16;
          if ( v16 == -1 )
            LODWORD(flDistance) = *((_DWORD *)p_x - 3) ^ _mask__NegFloat_;
          else
            flDistance = *p_x;
          PlaneIndex = CPlaneHash::FindPlaneIndex(this: &v1->m_PlaneHash, &vNormal, flDistance);
          m_nNumSides = pMapBrush->m_nNumSides;
          v20 = 0;
          if ( m_nNumSides > 0 )
          {
            p_m_nPlaneIndex = &v1->m_pMapFile->m_BrushSides.m_Memory.m_pMemory[pMapBrush->m_nFirstSideIndex].m_nPlaneIndex;
            do
            {
              if ( *p_m_nPlaneIndex == PlaneIndex )
                break;
              ++v20;
              p_m_nPlaneIndex += 11;
            }
            while ( v20 < m_nNumSides );
            v16 = nSide;
          }
          if ( v20 == m_nNumSides )
          {
            v22 = &v1->m_BrushSideList.m_Memory;
            v23 = v1->m_BrushSideList.m_Size;
            LOWORD(v30) = PlaneIndex;
            v24 = v22->m_nAllocationCount;
            HIWORD(v30) = v22->m_pMemory[v23 - 1].texinfo;
            LOWORD(v31) = 0;
            BYTE2(v31) = 1;
            if ( v23 + 1 > v24 )
              CUtlMemory<dbrushside_t,int>::Grow(this: v22, num: v23 - v24 + 1);
            ++v22[1].m_pMemory;
            v25 = v22->m_pMemory;
            v26 = (int)v22[1].m_pMemory - v23 - 1;
            v22[1].m_nAllocationCount = (int)v22->m_pMemory;
            if ( v26 > 0 )
              _V_memmove(dest: &v25[v23 + 1], src: &v25[v23], count: 8 * v26);
            v27 = &v22->m_pMemory[v23];
            if ( v27 != nullptr )
            {
              v28 = v31;
              *(_DWORD *)&v27->planenum = v30;
              *(_DWORD *)&v27->dispinfo = v28;
            }
            ++brush->numsides;
            v1 = v40;
          }
          v16 += 2;
          nSide = v16;
          if ( v16 > 1 )
            break;
          p_x = v42;
        }
        p_vNormal = (Vector *)((char *)p_vNormal + 4);
        ++v42;
        if ( --v35 == 0 )
          break;
        p_x = v42;
        v16 = -1;
      }
      v38 += 36;
      v37 += 12;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416760
// Name: private: void CMemoryBSPFile::BuildPlanes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::BuildPlanes(CMemoryBSPFile *this)
{
  int m_Size; // ebx
  int v3; // eax
  int v4; // ebx
  HashedPlane_t *m_pMemory; // edx
  dplane_t *v6; // ecx
  float *v7; // ecx
  HashedPlane_t *v8; // edx
  dplane_t *v9; // ecx
  int v10; // edx
  int v11; // ecx
  float *v12; // ecx
  HashedPlane_t *v13; // edx
  double v14; // st7
  int v15; // edx
  dplane_t *v16; // ecx
  bool v17; // zf
  HashedPlane_t *v18; // edx
  int v19; // edx
  int v20; // ebx
  HashedPlane_t *v21; // ecx
  dplane_t *v22; // eax
  dplane_t *v23; // eax
  int i; // [esp+Ch] [ebp-10h]
  unsigned int v25; // [esp+10h] [ebp-Ch]
  int v26; // [esp+10h] [ebp-Ch]
  int nPlaneCount; // [esp+14h] [ebp-8h]
  int v28; // [esp+18h] [ebp-4h]

  m_Size = this->m_PlaneHash.m_Planes.m_Size;
  nPlaneCount = m_Size;
  this->m_Planes.m_Size = 0;
  CUtlVector<CDispVert,CUtlMemory<CDispVert,int>>::InsertMultipleBefore(
    this: (CUtlVector<CDispVert,CUtlMemory<CDispVert,int> > *)&this->m_Planes,
    elem: 0,
    num: m_Size);
  v3 = 0;
  if ( m_Size >= 4 )
  {
    v25 = ((unsigned int)(m_Size - 4) >> 2) + 1;
    v4 = 0;
    v28 = 0;
    i = 4 * v25;
    do
    {
      m_pMemory = this->m_PlaneHash.m_Planes.m_Memory.m_pMemory;
      v6 = this->m_Planes.m_Memory.m_pMemory;
      *(float *)((char *)&v6->normal.x + v4) = *(float *)((char *)&m_pMemory->m_vNormal.x + v3);
      v7 = (float *)((char *)&v6->normal.x + v4);
      v7[1] = *(float *)((char *)&m_pMemory->m_vNormal.y + v3);
      v7[2] = *(float *)((char *)&m_pMemory->m_vNormal.z + v3);
      v7[3] = *(float *)((char *)&this->m_PlaneHash.m_Planes.m_Memory.m_pMemory->m_flDistance + v3);
      v7[4] = *(float *)((char *)&this->m_PlaneHash.m_Planes.m_Memory.m_pMemory->m_Type + v3);
      v8 = this->m_PlaneHash.m_Planes.m_Memory.m_pMemory;
      v9 = this->m_Planes.m_Memory.m_pMemory;
      *(float *)((char *)&v9[1].normal.x + v4) = *(float *)((char *)&v8[1].m_vNormal.x + v3);
      v10 = (int)&v8[1] + v3;
      v11 = (int)&v9[1] + v4;
      *(float *)(v11 + 4) = *(float *)(v10 + 4);
      *(float *)(v11 + 8) = *(float *)(v10 + 8);
      *(float *)(v11 + 12) = *(float *)((char *)&this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[1].m_flDistance + v3);
      *(_DWORD *)(v11 + 16) = *(int *)((char *)&this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[1].m_Type + v3);
      v12 = (float *)((char *)&this->m_Planes.m_Memory.m_pMemory[2].normal.x + v4);
      v13 = this->m_PlaneHash.m_Planes.m_Memory.m_pMemory;
      v14 = *(float *)((char *)&v13[2].m_vNormal.x + v3);
      v15 = (int)&v13[2] + v3;
      *v12 = v14;
      v4 = v28 * 20 + 80;
      v12[1] = *(float *)(v15 + 4);
      v3 += 96;
      v12[2] = *(float *)(v15 + 8);
      v12[3] = *(float *)((char *)&this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[-1] + v3 - 12);
      v12[4] = *(float *)((char *)&this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[-1] + v3 - 8);
      v16 = &this->m_Planes.m_Memory.m_pMemory[v28 + 3];
      v17 = v25-- == 1;
      v18 = this->m_PlaneHash.m_Planes.m_Memory.m_pMemory;
      v28 += 4;
      v16->normal.x = *(float *)((char *)&v18[-1].m_vNormal.x + v3);
      v16->normal.y = *(float *)((char *)v18 + v3 - 20);
      v16->normal.z = *(float *)((char *)v18 + v3 - 16);
      v16->dist = *(float *)((char *)this->m_PlaneHash.m_Planes.m_Memory.m_pMemory + v3 - 12);
      v16->type = *(_DWORD *)((char *)this->m_PlaneHash.m_Planes.m_Memory.m_pMemory + v3 - 8);
    }
    while ( !v17 );
    v3 = i;
    m_Size = nPlaneCount;
  }
  if ( v3 < m_Size )
  {
    v19 = v3;
    v20 = v3;
    v26 = nPlaneCount - v3;
    do
    {
      v21 = this->m_PlaneHash.m_Planes.m_Memory.m_pMemory;
      v22 = this->m_Planes.m_Memory.m_pMemory;
      v22[v20].normal.x = v21[v19].m_vNormal.x;
      v23 = &v22[v20++];
      v23->normal.y = v21[v19++].m_vNormal.y;
      v17 = v26-- == 1;
      v23->normal.z = v21[v19 - 1].m_vNormal.z;
      v23->dist = this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[v19 - 1].m_flDistance;
      v23->type = this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[v19 - 1].m_Type;
    }
    while ( !v17 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416910
// Name: private: int CMemoryBSPFile::AddStaticPropDictionaryEntry(char const __near *,class CUtlVector<struct StaticPropDictLump_t,class CUtlMemory<struct StaticPropDictLump_t,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMemoryBSPFile::AddStaticPropDictionaryEntry(
        CMemoryBSPFile *this,
        const char *pModelName,
        CUtlVector<StaticPropDictLump_t,CUtlMemory<StaticPropDictLump_t,int> > *pStaticPropDictionaryLump)
{
  int v3; // edi
  int v4; // ebx
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  StaticPropDictLump_t *m_pMemory; // ecx
  int v8; // eax
  StaticPropDictLump_t *v9; // edi
  StaticPropDictLump_t dictionaryEntry; // [esp+Ch] [ebp-80h] BYREF

  memset(&dictionaryEntry, 0, sizeof(dictionaryEntry));
  V_strncpy(pDest: dictionaryEntry.m_Name, pSrc: pModelName, maxLen: 128);
  v3 = 0;
  if ( pStaticPropDictionaryLump->m_Size <= 0 )
  {
LABEL_5:
    m_Size = pStaticPropDictionaryLump->m_Size;
    m_nAllocationCount = pStaticPropDictionaryLump->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<StaticPropDictLump_t,int>::Grow(
        this: &pStaticPropDictionaryLump->m_Memory,
        num: m_Size - m_nAllocationCount + 1);
    ++pStaticPropDictionaryLump->m_Size;
    m_pMemory = pStaticPropDictionaryLump->m_Memory.m_pMemory;
    v8 = pStaticPropDictionaryLump->m_Size - m_Size - 1;
    pStaticPropDictionaryLump->m_pElements = pStaticPropDictionaryLump->m_Memory.m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: v8 << 7);
    v9 = &pStaticPropDictionaryLump->m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = dictionaryEntry;
    return m_Size;
  }
  else
  {
    v4 = 0;
    while ( _V_memcmp(m1: pStaticPropDictionaryLump->m_Memory.m_pMemory[v4].m_Name, m2: &dictionaryEntry, count: 0x80u) != 0 )
    {
      ++v3;
      ++v4;
      if ( v3 >= pStaticPropDictionaryLump->m_Size )
        goto LABEL_5;
    }
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004169E0
// Name: private: int CMemoryBSPFile::AddStaticPropLeaves(class Vector const __near &,int,class CUtlVector<struct StaticPropLeafLump_t,class CUtlMemory<struct StaticPropLeafLump_t,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CMemoryBSPFile::AddStaticPropLeaves(
        CMemoryBSPFile *this,
        const Vector *vOrigin,
        int nNodeIndex,
        CUtlVector<StaticPropLeafLump_t,CUtlMemory<StaticPropLeafLump_t,int> > *pStaticPropLeafLump)
{
  int v5; // ecx
  dnode_t *m_pMemory; // ebx
  int v7; // edx
  HashedPlane_t *v8; // eax
  float v9; // xmm0_4
  int m_Size; // edi
  int m_nAllocationCount; // eax
  unsigned __int16 v12; // bx
  StaticPropLeafLump_t *v13; // ecx
  int v14; // eax
  StaticPropLeafLump_t *v15; // edi
  int v17; // esi
  int v18; // ebx

  v5 = nNodeIndex;
  if ( nNodeIndex >= 0 )
  {
    m_pMemory = this->m_NodeList.m_Memory.m_pMemory;
    do
    {
      v7 = v5;
      v8 = &this->m_PlaneHash.m_Planes.m_Memory.m_pMemory[m_pMemory[v5].planenum];
      v9 = (float)((float)((float)(v8->m_vNormal.y * vOrigin->y) + (float)(vOrigin->x * v8->m_vNormal.x))
                 + (float)(v8->m_vNormal.z * vOrigin->z))
         - v8->m_flDistance;
      if ( v9 >= -250.0 )
      {
        if ( v9 <= 250.0 )
        {
          v17 = v5;
          v18 = CMemoryBSPFile::AddStaticPropLeaves(
                  this,
                  vOrigin,
                  nNodeIndex: m_pMemory[v5].children[0],
                  pStaticPropLeafLump);
          return v18
               + CMemoryBSPFile::AddStaticPropLeaves(
                   this,
                   vOrigin,
                   nNodeIndex: this->m_NodeList.m_Memory.m_pMemory[v17].children[1],
                   pStaticPropLeafLump);
        }
        v5 = m_pMemory[v7].children[0];
      }
      else
      {
        v5 = m_pMemory[v7].children[1];
      }
    }
    while ( v5 >= 0 );
  }
  m_Size = pStaticPropLeafLump->m_Size;
  m_nAllocationCount = pStaticPropLeafLump->m_Memory.m_nAllocationCount;
  v12 = -1 - v5;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<unsigned short,int>::Grow(this: &pStaticPropLeafLump->m_Memory, num: m_Size - m_nAllocationCount + 1);
  ++pStaticPropLeafLump->m_Size;
  v13 = pStaticPropLeafLump->m_Memory.m_pMemory;
  v14 = pStaticPropLeafLump->m_Size - m_Size - 1;
  pStaticPropLeafLump->m_pElements = pStaticPropLeafLump->m_Memory.m_pMemory;
  if ( v14 > 0 )
    _V_memmove(dest: &v13[m_Size + 1], src: &v13[m_Size], count: 2 * v14);
  v15 = &pStaticPropLeafLump->m_Memory.m_pMemory[m_Size];
  if ( v15 != nullptr )
    v15->m_Leaf = v12;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00416B10
// Name: private: void CMemoryBSPFile::BuildDisplacements(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CMemoryBSPFile::BuildDisplacements(CMemoryBSPFile *this@<ecx>, int a2@<ebp>)
{
  void *v2; // esp
  CMemoryBSPFile *v3; // edi
  const CSimpleMapFile *m_pMapFile; // eax
  int m_Size; // esi
  int v6; // edx
  int *p_m_Size; // eax
  bool v8; // zf
  int m_nAllocationCount; // eax
  ddispinfo_t *m_pMemory; // ecx
  int v11; // eax
  int v12; // eax
  int v13; // ecx
  CCoreDispInfo **v14; // ecx
  int v15; // esi
  int v16; // eax
  CDispVert *v17; // ecx
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  CDispTri *v21; // edx
  int v22; // eax
  int v23; // ecx
  int v24; // eax
  CDispMultiBlend *v25; // edx
  int v26; // eax
  const CSimpleMapFile *v27; // ecx
  CDispVert *v28; // edx
  ddispinfo_t *v29; // eax
  CMapDisplacement *v30; // esi
  CDispVert *v31; // ecx
  CDispTri *v32; // edx
  double y; // st7
  int v34; // ecx
  double z; // st7
  int v36; // edx
  int v37; // edx
  char *v38; // edx
  float *p_z; // edi
  float *v40; // eax
  float v41; // xmm1_4
  __int128 v42; // xmm0
  CDispVert *v43; // eax
  float v44; // xmm1_4
  float v45; // xmm2_4
  float v46; // xmm3_4
  int v47; // ecx
  float *v48; // edx
  CMapDisplacement::Vertex_t *v49; // eax
  double v50; // st7
  float *v51; // eax
  double v52; // st7
  CMemoryBSPFile *v53; // eax
  CMapDisplacement::Vertex_t *v54; // edx
  double v55; // st7
  float *v56; // edx
  CCoreDispInfo *v57; // ecx
  CDispMultiBlend *v58; // eax
  float *v59; // eax
  double v60; // st7
  int v61; // edx
  CMapDisplacement::Vertex_t *v62; // eax
  double v63; // st7
  CMapDisplacement::Vertex_t *v64; // eax
  double v65; // st7
  int v66; // eax
  int v67; // edx
  int v68; // edx
  CMapDisplacement::Vertex_t *v69; // eax
  int v70; // edx
  CMapDisplacement::Vertex_t *v71; // eax
  double v72; // st7
  int v73; // eax
  int v74; // edx
  int v75; // edx
  CMapDisplacement::Vertex_t *v76; // eax
  int v77; // edx
  CMapDisplacement::Vertex_t *v78; // eax
  double v79; // st7
  int v80; // eax
  int v81; // edx
  int v82; // edx
  double v83; // st7
  CMapDisplacement::Vertex_t *v84; // eax
  int v85; // edx
  CMapDisplacement::Vertex_t *v86; // eax
  double v87; // st7
  int v88; // eax
  int v89; // edx
  int v90; // edx
  double v91; // st7
  int j; // eax
  CCoreDispInfo *v93; // eax
  CCoreDispInfo *v94; // eax
  int v95; // edx
  CCoreDispInfo *v96; // ecx
  int m_ContentsFlags; // eax
  CCoreDispInfo *v98; // edi
  char *v99; // ecx
  float *v100; // eax
  float *v101; // eax
  float *v102; // eax
  float *v103; // eax
  int m_nFlags; // edx
  CCoreDispInfo *v105; // esi
  int k; // edi
  CCoreDispInfo *v107; // ecx
  char *v108; // esi
  int v109; // eax
  int v110; // ecx
  CMemoryBSPFile *v111; // eax
  CCoreDispInfo *v112; // ecx
  char *v113; // esi
  int v114; // eax
  int v115; // ecx
  __int64 v116; // xmm0_8
  int v117; // eax
  int v118; // ecx
  CCoreDispInfo **v119; // [esp+10h] [ebp-7184h]
  int v120; // [esp+14h] [ebp-7180h]
  CDispMultiBlend v121[289]; // [esp+28h] [ebp-716Ch] BYREF
  Vector v122[289]; // [esp+5A78h] [ebp-171Ch] BYREF
  float v123[290]; // [esp+6808h] [ebp-98Ch] BYREF
  float v124[290]; // [esp+6C90h] [ebp-504h] BYREF
  __int128 v125; // [esp+7118h] [ebp-7Ch]
  ddispinfo_t *v126; // [esp+7134h] [ebp-60h]
  CDispTri *v127; // [esp+7138h] [ebp-5Ch]
  int v128; // [esp+713Ch] [ebp-58h]
  Vector v129; // [esp+7140h] [ebp-54h] BYREF
  float *v130; // [esp+714Ch] [ebp-48h]
  int v131; // [esp+7150h] [ebp-44h]
  int v132; // [esp+7154h] [ebp-40h]
  unsigned int v133; // [esp+7158h] [ebp-3Ch]
  int v134; // [esp+715Ch] [ebp-38h]
  unsigned int v135; // [esp+7160h] [ebp-34h]
  CCoreDispInfo *v136; // [esp+7164h] [ebp-30h]
  CDispVert *v137; // [esp+7168h] [ebp-2Ch]
  int i; // [esp+716Ch] [ebp-28h]
  int v139; // [esp+7170h] [ebp-24h]
  CMemoryBSPFile *v140; // [esp+7174h] [ebp-20h]
  int v141; // [esp+7178h] [ebp-1Ch]
  int v142; // [esp+717Ch] [ebp-18h]
  int p_m_DisplacementMultiBlendList; // [esp+7180h] [ebp-14h]
  int v144; // [esp+7184h] [ebp-10h]
  int v145; // [esp+7188h] [ebp-Ch]
  void *v146; // [esp+718Ch] [ebp-8h]
  void *retaddr; // [esp+7194h] [ebp+0h]

  v145 = a2;
  v146 = retaddr;
  v2 = alloca(29032);
  v3 = this;
  m_pMapFile = this->m_pMapFile;
  m_Size = m_pMapFile->m_Displacements.m_Size;
  v6 = 0;
  v140 = this;
  v144 = 0;
  v142 = 0;
  p_m_DisplacementMultiBlendList = 0;
  if ( m_Size > 0 )
  {
    p_m_Size = &m_pMapFile->m_Displacements.m_Memory.m_pMemory->m_Vertices.m_Size;
    for ( i = m_Size; i != 0; --i )
    {
      v6 += *p_m_Size;
      v142 += p_m_Size[5];
      v8 = (*(p_m_Size - 8) & 0x40000000) == 0;
      v144 = v6;
      if ( !v8 )
      {
        p_m_DisplacementMultiBlendList += *p_m_Size;
        v6 = v144;
      }
      p_m_Size += 17;
    }
  }
  this->m_DisplacementList.m_Size = 0;
  if ( m_Size != 0 )
  {
    m_nAllocationCount = this->m_DisplacementList.m_Memory.m_nAllocationCount;
    if ( m_Size > m_nAllocationCount )
    {
      CUtlMemory<MapBrushTexture_t,int>::Grow(
        this: (CUtlMemory<MapBrushTexture_t,int> *)&this->m_DisplacementList,
        num: m_Size - m_nAllocationCount);
      v6 = v144;
    }
    v3->m_DisplacementList.m_Size += m_Size;
    m_pMemory = v3->m_DisplacementList.m_Memory.m_pMemory;
    v11 = v3->m_DisplacementList.m_Size - m_Size;
    v3->m_DisplacementList.m_pElements = m_pMemory;
    if ( v11 > 0 && m_Size > 0 )
    {
      _V_memmove(dest: &m_pMemory[m_Size], src: m_pMemory, count: 176 * v11);
      v6 = v144;
    }
  }
  v139 = v3->m_pMapFile->m_Displacements.m_Size;
  v12 = v139;
  v3->m_DisplacementHelperList.m_Size = 0;
  if ( v12 != 0 )
  {
    v13 = v3->m_DisplacementHelperList.m_Memory.m_nAllocationCount;
    if ( v12 > v13 )
    {
      CUtlMemory<ColorRGBExp32,int>::Grow(
        this: (CUtlMemory<BSPCluster_t,int> *)&v3->m_DisplacementHelperList,
        num: v12 - v13);
      v6 = v144;
      v12 = v139;
    }
    v3->m_DisplacementHelperList.m_Size += v12;
    v14 = v3->m_DisplacementHelperList.m_Memory.m_pMemory;
    v15 = v3->m_DisplacementHelperList.m_Size - v12;
    v3->m_DisplacementHelperList.m_pElements = v14;
    if ( v15 > 0 && v12 > 0 )
    {
      _V_memmove(dest: &v14[v12], src: v14, count: 4 * v15);
      v6 = v144;
    }
  }
  v3->m_DisplacementVertexList.m_Size = 0;
  if ( v6 != 0 )
  {
    v16 = v3->m_DisplacementVertexList.m_Memory.m_nAllocationCount;
    if ( v6 > v16 )
    {
      CUtlMemory<CDispVert,int>::Grow(this: &v3->m_DisplacementVertexList.m_Memory, num: v6 - v16);
      v6 = v144;
    }
    v3->m_DisplacementVertexList.m_Size += v6;
    v17 = v3->m_DisplacementVertexList.m_Memory.m_pMemory;
    v18 = v3->m_DisplacementVertexList.m_Size - v6;
    v3->m_DisplacementVertexList.m_pElements = v17;
    if ( v18 > 0 && v6 > 0 )
      _V_memmove(dest: &v17[v6], src: v17, count: 20 * v18);
  }
  v19 = v142;
  v3->m_DisplacementTriangleList.m_Size = 0;
  if ( v19 != 0 )
  {
    v20 = v3->m_DisplacementTriangleList.m_Memory.m_nAllocationCount;
    if ( v19 > v20 )
    {
      CUtlMemory<unsigned short,int>::Grow(
        this: (CUtlMemory<StaticPropLeafLump_t,int> *)&v3->m_DisplacementTriangleList,
        num: v19 - v20);
      v19 = v142;
    }
    v3->m_DisplacementTriangleList.m_Size += v19;
    v21 = v3->m_DisplacementTriangleList.m_Memory.m_pMemory;
    v22 = v3->m_DisplacementTriangleList.m_Size - v19;
    v3->m_DisplacementTriangleList.m_pElements = v21;
    if ( v22 > 0 && v19 > 0 )
      _V_memmove(dest: &v21[v19], src: v21, count: 2 * v22);
  }
  v23 = p_m_DisplacementMultiBlendList;
  v3->m_DisplacementMultiBlendList.m_Size = 0;
  if ( v23 != 0 )
  {
    v24 = v3->m_DisplacementMultiBlendList.m_Memory.m_nAllocationCount;
    if ( v23 > v24 )
    {
      CUtlMemory<CDispMultiBlend,int>::Grow(this: &v3->m_DisplacementMultiBlendList.m_Memory, num: v23 - v24);
      v23 = p_m_DisplacementMultiBlendList;
    }
    v3->m_DisplacementMultiBlendList.m_Size += v23;
    v25 = v3->m_DisplacementMultiBlendList.m_Memory.m_pMemory;
    v26 = v3->m_DisplacementMultiBlendList.m_Size - v23;
    v3->m_DisplacementMultiBlendList.m_pElements = v25;
    if ( v26 > 0 && v23 > 0 )
      _V_memmove(dest: &v25[v23], src: v25, count: 80 * v26);
  }
  v27 = v3->m_pMapFile;
  v134 = 0;
  v128 = 0;
  v132 = 0;
  v131 = 0;
  if ( v27->m_Displacements.m_Size > 0 )
  {
    i = 0;
    v135 = 0;
    v133 = 0;
    do
    {
      v28 = v3->m_DisplacementVertexList.m_Memory.m_pMemory;
      v29 = &v3->m_DisplacementList.m_Memory.m_pMemory[v133 / 0xB0];
      v30 = &v27->m_Displacements.m_Memory.m_pMemory[v135 / 0x44];
      v139 = (int)v3->m_pSimpleBSPFile->m_DisplacementFaces.m_Memory.m_pMemory + i;
      v31 = &v28[v134];
      v32 = v3->m_DisplacementTriangleList.m_Memory.m_pMemory;
      v29->startPosition.x = v30->m_vStartPosition.x;
      y = v30->m_vStartPosition.y;
      v137 = v31;
      v34 = v128;
      v29->startPosition.y = y;
      z = v30->m_vStartPosition.z;
      v127 = &v32[v34];
      v29->startPosition.z = z;
      v36 = v134;
      v29->m_iDispVertStart = v134;
      v29->m_iDispTriStart = v34;
      v37 = v30->m_Vertices.m_Size + v36;
      v128 = v30->m_TriangleTags.m_Size + v34;
      v29->power = v30->m_nPower;
      v134 = v37;
      v29->minTess = v30->m_nFlags | 0x80000000;
      v38 = (char *)v139;
      v29->smoothingAngle = 0.0;
      v29->contents = v30->m_ContentsFlags;
      v29->m_iMapFace = *((_WORD *)v38 + 18);
      v29->m_iLightmapAlphaStart = 0;
      v29->m_iLightmapSamplePositionStart = 0;
      v126 = v29;
      v142 = 0;
      if ( v30->m_Vertices.m_Size > 0 )
      {
        v136 = (CCoreDispInfo *)(80 * v132);
        v141 = 0;
        v144 = 60;
        p_z = &v121[0].m_vMultiBlend.z;
        v130 = &v122[0].z;
        v137 = (CDispVert *)((char *)v137 + 8);
        do
        {
          v40 = (float *)((char *)&v30->m_Vertices.m_Memory.m_pMemory->m_flAlpha + v141);
          v41 = v40[1];
          v129.x = v40[2] * v41;
          v129.y = v40[3] * v41;
          v129.z = v40[4] * v41;
          v129.x = v129.x + v40[5];
          v129.y = v40[6] + v129.y;
          v129.z = v40[7] + v129.z;
          v42 = 0;
          *(float *)&v42 = fsqrt((float)((float)(v129.z * v129.z) + (float)(v129.y * v129.y)) + (float)(v129.x * v129.x));
          v125 = v42;
          VectorNormalize(vec: &v129);
          v43 = v137;
          *(float *)&v42 = v129.x;
          v44 = v129.y;
          v45 = v129.z;
          v46 = *(float *)&v125;
          v47 = v141;
          *(Vector *)&v137[-1].m_flDist = v129;
          v43->m_vVector.y = v46;
          v48 = v130;
          v43->m_vVector.z = *(float *)((char *)&v30->m_Vertices.m_Memory.m_pMemory->m_flAlpha + v47);
          *((_DWORD *)v48 - 2) = v42;
          *(v48 - 1) = v44;
          *v48 = v45;
          v124[v142] = v46;
          v123[v142] = *(float *)((char *)&v30->m_Vertices.m_Memory.m_pMemory->m_flAlpha + v47);
          if ( (v30->m_nFlags & 0x40000000) != 0 )
          {
            v49 = v30->m_Vertices.m_Memory.m_pMemory;
            v50 = *(float *)((char *)&v49->m_vMultiBlend.x + v47);
            v51 = (float *)((char *)&v49->m_vMultiBlend.x + v47);
            *(p_z - 2) = v50;
            *(p_z - 1) = v51[1];
            *p_z = v51[2];
            v52 = v51[3];
            v53 = v140;
            p_z[1] = v52;
            v54 = v30->m_Vertices.m_Memory.m_pMemory;
            v55 = *(float *)((char *)&v54->m_vMultiBlend.x + v47);
            v56 = (float *)((char *)&v54->m_vMultiBlend.x + v47);
            v57 = v136;
            p_m_DisplacementMultiBlendList = (int)&v53->m_DisplacementMultiBlendList;
            v58 = v53->m_DisplacementMultiBlendList.m_Memory.m_pMemory;
            *(float *)((char *)&v136->__vftable + (_DWORD)v58) = v55;
            v59 = (float *)((int)&v58->m_vMultiBlend.x + (_DWORD)v57);
            v59[1] = v56[1];
            v59[2] = v56[2];
            v60 = v56[3];
            v61 = v144;
            v59[3] = v60;
            v62 = v30->m_Vertices.m_Memory.m_pMemory;
            v63 = *(float *)((char *)v62 + v61 - 12);
            v61 -= 12;
            p_z[6] = v63;
            p_z[7] = *(float *)((char *)&v62->m_flDistance + v61);
            p_z[8] = *(float *)((char *)&v62->m_vNormal.x + v61);
            v64 = v30->m_Vertices.m_Memory.m_pMemory;
            v65 = *(float *)((char *)&v64->m_flAlpha + v61);
            v66 = (int)v64 + v61;
            v67 = *(_DWORD *)p_m_DisplacementMultiBlendList;
            *(float *)((char *)&v57->m_Surf.m_Points[0].z + v67) = v65;
            v68 = (int)&v57->m_Surf.m_Points[0].z + v67;
            *(float *)(v68 + 4) = *(float *)(v66 + 4);
            *(float *)(v68 + 8) = *(float *)(v66 + 8);
            v69 = v30->m_Vertices.m_Memory.m_pMemory;
            v70 = v144;
            p_z[9] = *(float *)((char *)&v69->m_flAlpha + v144);
            p_z[10] = *(float *)((char *)&v69->m_flDistance + v70);
            p_z[11] = *(float *)((char *)&v69->m_vNormal.x + v70);
            v71 = v30->m_Vertices.m_Memory.m_pMemory;
            v72 = *(float *)((char *)&v71->m_flAlpha + v70);
            v73 = (int)v71 + v70;
            v74 = *(_DWORD *)p_m_DisplacementMultiBlendList;
            *(float *)((char *)&v57->m_Surf.m_Points[1].z + v74) = v72;
            v75 = (int)&v57->m_Surf.m_Points[1].z + v74;
            *(float *)(v75 + 4) = *(float *)(v73 + 4);
            *(float *)(v75 + 8) = *(float *)(v73 + 8);
            v76 = v30->m_Vertices.m_Memory.m_pMemory;
            v77 = v144 + 12;
            p_z[12] = *(float *)((char *)&v76->m_vNormal.y + v144);
            p_z[13] = *(float *)((char *)&v76->m_flDistance + v77);
            p_z[14] = *(float *)((char *)&v76->m_vNormal.x + v77);
            v78 = v30->m_Vertices.m_Memory.m_pMemory;
            v79 = *(float *)((char *)&v78->m_flAlpha + v77);
            v80 = (int)v78 + v77;
            v81 = *(_DWORD *)p_m_DisplacementMultiBlendList;
            *(float *)((char *)&v57->m_Surf.m_Points[2].z + v81) = v79;
            v82 = (int)&v57->m_Surf.m_Points[2].z + v81;
            v83 = *(float *)(v80 + 4);
            ++v132;
            *(float *)(v82 + 4) = v83;
            *(float *)(v82 + 8) = *(float *)(v80 + 8);
            v84 = v30->m_Vertices.m_Memory.m_pMemory;
            v85 = v144 + 24;
            p_z[15] = *(float *)((char *)&v84->m_vOffset.y + v144);
            p_z[16] = *(float *)((char *)&v84->m_flDistance + v85);
            p_z[17] = *(float *)((char *)&v84->m_vNormal.x + v85);
            v86 = v30->m_Vertices.m_Memory.m_pMemory;
            v87 = *(float *)((char *)&v86->m_flAlpha + v85);
            v88 = (int)v86 + v85;
            v89 = *(_DWORD *)p_m_DisplacementMultiBlendList;
            *(float *)((char *)&v57->m_Surf.m_Points[3].z + v89) = v87;
            v90 = (int)&v57->m_Surf.m_Points[3].z + v89;
            *(float *)(v90 + 4) = *(float *)(v88 + 4);
            v91 = *(float *)(v88 + 8);
            v43 = v137;
            v136 = (CCoreDispInfo *)&v57->m_Surf.m_Normals[0].z;
            *(float *)(v90 + 8) = v91;
            v47 = v141;
          }
          v130 += 3;
          v144 += 96;
          p_z += 20;
          ++v142;
          v137 = v43 + 1;
          v141 = v47 + 96;
        }
        while ( v142 < v30->m_Vertices.m_Size );
        v3 = v140;
      }
      for ( j = 0; j < v30->m_TriangleTags.m_Size; ++j )
        v127[j] = (CDispTri)v30->m_TriangleTags.m_Memory.m_pMemory[j];
      v93 = (CCoreDispInfo *)operator new(nSize: 0x34Cu);
      if ( v93 != nullptr )
        v94 = CCoreDispInfo::CCoreDispInfo(this: v93);
      else
        v94 = nullptr;
      v95 = v131;
      v3->m_DisplacementHelperList.m_Memory.m_pMemory[v131] = v94;
      v96 = v3->m_DisplacementHelperList.m_Memory.m_pMemory[v95];
      v96->m_nListIndex = v95;
      v120 = v3->m_DisplacementHelperList.m_Size;
      v119 = v3->m_DisplacementHelperList.m_Memory.m_pMemory;
      v136 = v96;
      CCoreDispInfo::SetDispUtilsHelperInfo(this: v96, ppListBase: v119, listSize: v120);
      m_ContentsFlags = v30->m_ContentsFlags;
      v98 = v136;
      if ( (m_ContentsFlags & 0x300FF) == 0 )
        m_ContentsFlags |= 1u;
      v136->m_Surf.m_Contents = m_ContentsFlags;
      v98->m_Surf.m_PointCount = 4;
      v99 = (char *)v139;
      v100 = *(float **)(v139 + 12);
      v98->m_Surf.m_Points[0].x = *v100;
      v98->m_Surf.m_Points[0].y = v100[1];
      v98->m_Surf.m_Points[0].z = v100[2];
      v98->m_Surf.m_TexCoords[0].x = 0.0;
      v98->m_Surf.m_TexCoords[0].y = 0.0;
      v101 = *((float **)v99 + 3);
      v98->m_Surf.m_Points[1].x = v101[3];
      v98->m_Surf.m_Points[1].y = v101[4];
      v98->m_Surf.m_Points[1].z = v101[5];
      v98->m_Surf.m_TexCoords[1].x = 0.0;
      v98->m_Surf.m_TexCoords[1].y = 1.0;
      v102 = *((float **)v99 + 3);
      v98->m_Surf.m_Points[2].x = v102[6];
      v98->m_Surf.m_Points[2].y = v102[7];
      v98->m_Surf.m_Points[2].z = v102[8];
      v98->m_Surf.m_TexCoords[2].x = 1.0;
      v98->m_Surf.m_TexCoords[2].y = 0.0;
      v103 = *((float **)v99 + 3);
      v98->m_Surf.m_Points[3].x = v103[9];
      v98->m_Surf.m_Points[3].y = v103[10];
      v98->m_Surf.m_Points[3].z = v103[11];
      v98->m_Surf.m_TexCoords[3].x = 1.0;
      v98->m_Surf.m_TexCoords[3].y = 1.0;
      v98->m_Surf.m_PointStart.x = v30->m_vStartPosition.x;
      v98->m_Surf.m_PointStart.y = v30->m_vStartPosition.y;
      v98->m_Surf.m_PointStart.z = v30->m_vStartPosition.z;
      CCoreDispSurface::FindSurfPointStartIndex(this: &v98->m_Surf);
      CCoreDispSurface::AdjustSurfPointData(this: &v98->m_Surf);
      v98->m_Surf.m_nLuxelU = 0;
      v98->m_Surf.m_nLuxelV = 0;
      m_nFlags = v30->m_nFlags;
      v105 = v136;
      CCoreDispInfo::InitDispInfo(
        this: v136,
        power: v126->power,
        minTess: v126->minTess,
        smoothingAngle: v126->smoothingAngle,
        alphas: v123,
        dispVectorField: v122,
        dispDistances: v124,
        nFlags: m_nFlags,
        pvMultiBlends: v121);
      CCoreDispInfo::Create(this: v105);
      v133 += 176;
      ++v131;
      v27 = v140->m_pMapFile;
      v135 += 68;
      i += 40;
      v3 = v140;
    }
    while ( v131 < v27->m_Displacements.m_Size );
  }
  FindNeighboringDispSurfs(
    ppListBase: v3->m_DisplacementHelperList.m_Memory.m_pMemory,
    nListSize: v3->m_DisplacementHelperList.m_Size);
  p_m_DisplacementMultiBlendList = 0;
  if ( v3->m_DisplacementHelperList.m_Size > 0 )
  {
    v142 = 0;
    do
    {
      v141 = 0;
      v139 = 0;
      for ( k = 48; k < 96; k += 12 )
      {
        v107 = v140->m_DisplacementHelperList.m_Memory.m_pMemory[p_m_DisplacementMultiBlendList];
        v108 = (char *)v140->m_DisplacementList.m_Memory.m_pMemory + v142;
        v109 = (int)v107->GetEdgeNeighbor(this: v107, a2: v141);
        *(_QWORD *)&v108[k] = *(_QWORD *)v109;
        v110 = *(_DWORD *)(v109 + 8);
        v111 = v140;
        *(_DWORD *)&v108[k + 8] = v110;
        v112 = v111->m_DisplacementHelperList.m_Memory.m_pMemory[p_m_DisplacementMultiBlendList];
        v113 = (char *)v111->m_DisplacementList.m_Memory.m_pMemory + v142;
        v114 = (int)v112->GetCornerNeighbors(this: v112, a2: v141);
        v115 = v139;
        v116 = *(_QWORD *)v114;
        ++v141;
        *(_QWORD *)&v113[v139 + 96] = v116;
        *(_WORD *)&v113[v115 + 104] = *(_WORD *)(v114 + 8);
        v139 = v115 + 10;
      }
      v142 += 176;
      ++p_m_DisplacementMultiBlendList;
    }
    while ( p_m_DisplacementMultiBlendList < v140->m_DisplacementHelperList.m_Size );
    v3 = v140;
  }
  SetupAllowedVerts(
    ppListBase: v3->m_DisplacementHelperList.m_Memory.m_pMemory,
    nListSize: v3->m_DisplacementHelperList.m_Size);
  v117 = 0;
  if ( v3->m_DisplacementHelperList.m_Size > 0 )
  {
    v118 = 140;
    do
    {
      *(_DWORD *)((char *)v3->m_DisplacementList.m_Memory.m_pMemory + v118 - 4) = v3->m_DisplacementHelperList.m_Memory.m_pMemory[v117]->m_AllowedVerts.m_Ints[0];
      *(_DWORD *)((char *)&v3->m_DisplacementList.m_Memory.m_pMemory->startPosition.x + v118) = v3->m_DisplacementHelperList.m_Memory.m_pMemory[v117]->m_AllowedVerts.m_Ints[1];
      *(_DWORD *)((char *)&v3->m_DisplacementList.m_Memory.m_pMemory->startPosition.y + v118) = v3->m_DisplacementHelperList.m_Memory.m_pMemory[v117]->m_AllowedVerts.m_Ints[2];
      *(_DWORD *)((char *)&v3->m_DisplacementList.m_Memory.m_pMemory->startPosition.z + v118) = v3->m_DisplacementHelperList.m_Memory.m_pMemory[v117]->m_AllowedVerts.m_Ints[3];
      *(int *)((char *)&v3->m_DisplacementList.m_Memory.m_pMemory->m_iDispVertStart + v118) = v3->m_DisplacementHelperList.m_Memory.m_pMemory[v117]->m_AllowedVerts.m_Ints[4];
      *(int *)((char *)&v3->m_DisplacementList.m_Memory.m_pMemory->m_iDispTriStart + v118) = v3->m_DisplacementHelperList.m_Memory.m_pMemory[v117]->m_AllowedVerts.m_Ints[5];
      *(int *)((char *)&v3->m_DisplacementList.m_Memory.m_pMemory->power + v118) = v3->m_DisplacementHelperList.m_Memory.m_pMemory[v117]->m_AllowedVerts.m_Ints[6];
      *(int *)((char *)&v3->m_DisplacementList.m_Memory.m_pMemory->minTess + v118) = v3->m_DisplacementHelperList.m_Memory.m_pMemory[v117]->m_AllowedVerts.m_Ints[7];
      *(_DWORD *)((char *)&v3->m_DisplacementList.m_Memory.m_pMemory->smoothingAngle + v118) = v3->m_DisplacementHelperList.m_Memory.m_pMemory[v117]->m_AllowedVerts.m_Ints[8];
      *(int *)((char *)&v3->m_DisplacementList.m_Memory.m_pMemory->contents + v118) = v3->m_DisplacementHelperList.m_Memory.m_pMemory[v117++]->m_AllowedVerts.m_Ints[9];
      v118 += 176;
    }
    while ( v117 < v3->m_DisplacementHelperList.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417500
// Name: private: class CPhysCollisionEntry __near * CMemoryBSPFile::CreatePhysicsModel(class IPhysicsCollision __near *,class IPhysicsSurfaceProps __near *,int const __near *,struct dmodel_t const __near *)
// Source: json
//------------------------------------------------------------------------------
CPhysCollisionEntrySolid *__userpurge CMemoryBSPFile::CreatePhysicsModel@<eax>(
        CMemoryBSPFile *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        IPhysicsCollision *pPhysicsCollision,
        IPhysicsSurfaceProps *pPhysicsProperties,
        const int *pSurfacePropertyList,
        const dmodel_t *pModel)
{
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm3_4
  float v13; // xmm0_4
  bool v14; // cc
  float v15; // xmm1_4
  float v16; // xmm2_4
  float v17; // xmm0_4
  struct CPhysConvex **v18; // eax
  int v20; // ecx
  MapTextureInfo_t *m_pMemory; // ebx
  dface_t *v22; // edx
  int numfaces; // edi
  int v24; // esi
  int v25; // eax
  double area; // st7
  float v27; // xmm0_4
  int v28; // esi
  int v29; // eax
  float v30; // xmm2_4
  int v31; // edx
  float flArea; // xmm1_4
  float v33; // xmm2_4
  float v34; // xmm1_4
  float v35; // xmm2_4
  float v36; // xmm1_4
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm1_4
  float v40; // xmm1_4
  int nProperty; // edi
  const char *v42; // ebx
  float m_flTotalVolume; // xmm0_4
  CPhysCollisionEntrySolid *v44; // esi
  CPhysCollisionEntrySolid *v45; // esi
  struct CPhysConvex **v46; // eax
  float flVolume; // [esp+38h] [ebp-C44h]
  CMemoryBSPFile::CreatePhysicsModel::__l10::<unnamed_type_propertyList> propertyList[256]; // [esp+3Ch] [ebp-C40h]
  CPhysConvexBuilder physConvexBuilder; // [esp+83Ch] [ebp-440h] BYREF
  float flThickness; // [esp+C64h] [ebp-18h] BYREF
  convertconvexparams_t params; // [esp+C68h] [ebp-14h] BYREF
  float flDensity; // [esp+C78h] [ebp-4h] BYREF
  float flTotalArea; // [esp+C8Ch] [ebp+10h]
  float flTotalAreaa; // [esp+C8Ch] [ebp+10h]
  struct CPhysCollide *pCollide; // [esp+C90h] [ebp+14h]

  CPhysConvexBuilder::CPhysConvexBuilder(
    this: &physConvexBuilder,
    flShrink: 0.5,
    contentsMask: 33767483,
    pMapFile: this->m_pMapFile,
    pPhysicsCollision);
  CPhysConvexBuilder::BuildConvexes(
    this: &physConvexBuilder,
    nNodeIndex: pModel->headnode,
    nodeList: &this->m_NodeList,
    leafList: &this->m_LeafList,
    leafBrushList: &this->m_LeafBrushList);
  v10 = pModel->maxs.y - pModel->mins.y;
  v11 = pModel->maxs.z - pModel->mins.z;
  v12 = pModel->maxs.x - pModel->mins.x;
  v13 = v10 * v11;
  v14 = (float)(v10 * v11) >= 0.0;
  *(_DWORD *)&params.buildOptimizedTraceTables = 0;
  params.pForcedOuterHull = nullptr;
  params.buildOuterConvexHull = physConvexBuilder.m_Convexes.m_Size > 1;
  params.buildDragAxisAreas = true;
  v15 = v11 * v12;
  if ( !v14 || v13 > v15 )
    v13 = v15;
  v16 = v10 * v12;
  if ( v13 < 0.0 || v13 > v16 )
    v13 = v16;
  v17 = v13 * 0.0099999998;
  if ( v17 >= 1.0 )
  {
    if ( v17 <= 1024.0 )
      params.dragAreaEpsilon = v17;
    else
      params.dragAreaEpsilon = 1024.0;
  }
  else
  {
    params.dragAreaEpsilon = 1.0;
  }
  pCollide = (struct CPhysCollide *)((int (__thiscall *)(IPhysicsCollision *, struct CPhysConvex **, int, convertconvexparams_t *, int, int, int))pPhysicsCollision->ConvertConvexToCollideParams)(
                                      a1: pPhysicsCollision,
                                      a2: physConvexBuilder.m_Convexes.m_Memory.m_pMemory,
                                      a3: physConvexBuilder.m_Convexes.m_Size,
                                      a4: &params,
                                      a5: a3,
                                      a6: a4,
                                      a7: a2);
  if ( pCollide != nullptr )
  {
    propertyList[0].nProperty = 0;
    propertyList[0].flArea = 1.0;
    v20 = 1;
    if ( pModel->numfaces == 0 )
    {
      propertyList[1].nProperty = pSurfacePropertyList[this->m_pMapFile->m_TextureInfos.m_Memory.m_pMemory[this->m_pMapFile->m_BrushSides.m_Memory.m_pMemory[this->m_pMapFile->m_Brushes.m_Memory.m_pMemory[CPhysConvexBuilder::FindFirstReferencedBrush(this: &physConvexBuilder)].m_nFirstSideIndex].m_nTextureInfoIndex].m_nTextureDataIndex];
      propertyList[1].flArea = 2.0;
      v20 = 2;
    }
    if ( pModel->numfaces > 0 )
    {
      m_pMemory = this->m_pMapFile->m_TextureInfos.m_Memory.m_pMemory;
      v22 = &this->m_FaceList.m_Memory.m_pMemory[pModel->firstface];
      numfaces = pModel->numfaces;
      do
      {
        v24 = pSurfacePropertyList[m_pMemory[v22->texinfo].m_nTextureDataIndex];
        v25 = 0;
        if ( v20 > 0 )
        {
          while ( propertyList[v25].nProperty != v24 )
          {
            if ( ++v25 >= v20 )
              goto LABEL_30;
          }
          propertyList[v25].flArea = v22->area + propertyList[v25].flArea;
        }
LABEL_30:
        if ( v25 == v20 && v20 < 256 )
        {
          area = v22->area;
          propertyList[v20].nProperty = v24;
          propertyList[v20++].flArea = area;
        }
        ++v22;
        --numfaces;
      }
      while ( numfaces != 0 );
    }
    v27 = 0.0;
    v28 = 0;
    v29 = 0;
    v30 = 0.0;
    flTotalArea = 0.0;
    if ( v20 >= 4 )
    {
      v31 = 2;
      do
      {
        flArea = propertyList[v29].flArea;
        if ( flArea > v27 )
        {
          v27 = propertyList[v29].flArea;
          v28 = v29;
        }
        v33 = v30 + flArea;
        v34 = propertyList[v29 + 1].flArea;
        if ( v34 > v27 )
        {
          v27 = propertyList[v29 + 1].flArea;
          v28 = v31 - 1;
        }
        v35 = v33 + v34;
        v36 = propertyList[v29 + 2].flArea;
        if ( v36 > v27 )
        {
          v27 = propertyList[v29 + 2].flArea;
          v28 = v31;
        }
        v37 = v36 + v35;
        v38 = propertyList[v29 + 3].flArea;
        if ( v38 > v27 )
        {
          v27 = propertyList[v29 + 3].flArea;
          v28 = v31 + 1;
        }
        v29 += 4;
        v31 += 4;
        v30 = v38 + v37;
      }
      while ( v29 < v20 - 3 );
      flTotalArea = v30;
    }
    if ( v29 < v20 )
    {
      do
      {
        v39 = propertyList[v29].flArea;
        if ( v39 > v27 )
        {
          v27 = propertyList[v29].flArea;
          v28 = v29;
        }
        ++v29;
        v40 = v39 + v30;
        v30 = v40;
      }
      while ( v29 < v20 );
      flTotalArea = v40;
    }
    nProperty = propertyList[v28].nProperty;
    v42 = pPhysicsProperties->GetPropName(this: pPhysicsProperties, a2: nProperty);
    pPhysicsProperties->GetPhysicsProperties(
      this: pPhysicsProperties,
      a2: nProperty,
      a3: &flDensity,
      a4: &flThickness,
      a5: nullptr,
      a6: nullptr);
    if ( flThickness == 0.0 )
      m_flTotalVolume = physConvexBuilder.m_flTotalVolume;
    else
      m_flTotalVolume = flThickness * flTotalArea;
    flTotalAreaa = (float)(m_flTotalVolume * flDensity) * 0.000016387063;
    if ( flTotalAreaa > 50000.0 )
      flTotalAreaa = 50000.0;
    v44 = (CPhysCollisionEntrySolid *)operator new(nSize: 0x14u);
    if ( v44 != nullptr )
    {
      flVolume = pPhysicsCollision->CollideVolume(this: pPhysicsCollision, a2: pCollide);
      v45 = CPhysCollisionEntrySolid::CPhysCollisionEntrySolid(
              this: v44,
              pCollide,
              pMaterialName: v42,
              flMass: flTotalAreaa,
              flVolume);
    }
    else
    {
      v45 = nullptr;
    }
    v46 = physConvexBuilder.m_Convexes.m_Memory.m_pMemory;
    physConvexBuilder.m_Convexes.m_Size = 0;
    if ( physConvexBuilder.m_Convexes.m_Memory.m_nGrowSize >= 0 )
    {
      if ( physConvexBuilder.m_Convexes.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: physConvexBuilder.m_Convexes.m_Memory.m_pMemory);
        v46 = nullptr;
        physConvexBuilder.m_Convexes.m_Memory.m_pMemory = nullptr;
      }
      physConvexBuilder.m_Convexes.m_Memory.m_nAllocationCount = 0;
    }
    physConvexBuilder.m_Convexes.m_pElements = v46;
    if ( physConvexBuilder.m_Convexes.m_Memory.m_nGrowSize >= 0 && v46 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v46);
    return v45;
  }
  else
  {
    v18 = physConvexBuilder.m_Convexes.m_Memory.m_pMemory;
    physConvexBuilder.m_Convexes.m_Size = 0;
    if ( physConvexBuilder.m_Convexes.m_Memory.m_nGrowSize >= 0 )
    {
      if ( physConvexBuilder.m_Convexes.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: physConvexBuilder.m_Convexes.m_Memory.m_pMemory);
        v18 = nullptr;
        physConvexBuilder.m_Convexes.m_Memory.m_pMemory = nullptr;
      }
      physConvexBuilder.m_Convexes.m_Memory.m_nAllocationCount = 0;
    }
    physConvexBuilder.m_Convexes.m_pElements = v18;
    if ( physConvexBuilder.m_Convexes.m_Memory.m_nGrowSize >= 0 && v18 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417950
// Name: void TesselateDisplacementNode<class CSimpleBSPTessellateHelper>(class CSimpleBSPTessellateHelper __near *,class CVertIndex const __near &,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TesselateDisplacementNode<CSimpleBSPTessellateHelper>(
        CSimpleBSPTessellateHelper *pHelper,
        const CVertIndex *nodeIndex,
        char iLevel,
        int *pActiveChildren)
{
  int v5; // eax
  __int16 v6; // dx
  __int16 v7; // di
  int m_iNode; // ecx
  CUtlMemory<StaticPropLeafLump_t,int> *m_pIndices; // edi
  StaticPropLeafLump_t *m_pMemory; // ebx
  int m_nAllocationCount; // eax
  StaticPropLeafLump_t *v12; // ecx
  int v13; // eax
  StaticPropLeafLump_t *v14; // ebx
  CUtlMemory<StaticPropLeafLump_t,int> *v15; // edi
  StaticPropLeafLump_t *v16; // ebx
  int v17; // eax
  StaticPropLeafLump_t *v18; // ecx
  int v19; // eax
  StaticPropLeafLump_t *v20; // eax
  CUtlMemory<StaticPropLeafLump_t,int> *v21; // edi
  StaticPropLeafLump_t *v22; // ebx
  int v23; // eax
  StaticPropLeafLump_t *v24; // ecx
  int v25; // eax
  StaticPropLeafLump_t *v26; // eax
  int iVert; // [esp+Ch] [ebp-8h]
  int vertInc; // [esp+10h] [ebp-4h]
  int iCurTriVert; // [esp+1Ch] [ebp+8h]
  int iLevela; // [esp+24h] [ebp+10h]

  vertInc = 1 << (pHelper->m_pPowerInfo->m_Power - iLevel - 1);
  v5 = 0;
  iCurTriVert = 0;
  iVert = 0;
  if ( g_TWinding.m_nVerts > 0 )
  {
    iLevela = 0;
    do
    {
      v6 = nodeIndex->x + vertInc * g_TWinding.m_Verts[iLevela].m_Index.x;
      v7 = nodeIndex->y + vertInc * g_TWinding.m_Verts[iLevela].m_Index.y;
      m_iNode = g_TWinding.m_Verts[iLevela].m_iNode;
      if ( m_iNode == -1 || pActiveChildren[m_iNode] == 0 )
      {
        if ( ((1 << ((v6 + LOBYTE(pHelper->m_pPowerInfo->m_SideLength) * v7) & 0x1F))
            & pHelper->m_pActiveVerts[(v6 + pHelper->m_pPowerInfo->m_SideLength * v7) >> 5]) != 0 )
        {
          pHelper->m_TempIndices[iCurTriVert] = v6 + v7 * LOWORD(pHelper->m_pPowerInfo->m_SideLength);
          v5 = iCurTriVert + 1;
          iCurTriVert = v5;
          if ( v5 == 2 )
          {
            pHelper->m_TempIndices[2] = nodeIndex->x + nodeIndex->y * LOWORD(pHelper->m_pPowerInfo->m_SideLength);
            CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertBefore(
              this: pHelper->m_pIndices,
              elem: pHelper->m_pIndices->m_Size,
              src: pHelper->m_TempIndices);
            CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertBefore(
              this: pHelper->m_pIndices,
              elem: pHelper->m_pIndices->m_Size,
              src: &pHelper->m_TempIndices[1]);
            CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertBefore(
              this: pHelper->m_pIndices,
              elem: pHelper->m_pIndices->m_Size,
              src: &pHelper->m_TempIndices[2]);
            pHelper->m_TempIndices[0] = pHelper->m_TempIndices[1];
            v5 = 1;
            iCurTriVert = 1;
          }
        }
        else
        {
          v5 = iCurTriVert;
        }
      }
      else
      {
        if ( v5 == 2 )
        {
          m_pIndices = (CUtlMemory<StaticPropLeafLump_t,int> *)pHelper->m_pIndices;
          pHelper->m_TempIndices[2] = nodeIndex->x + nodeIndex->y * LOWORD(pHelper->m_pPowerInfo->m_SideLength);
          m_pMemory = m_pIndices[1].m_pMemory;
          m_nAllocationCount = m_pIndices->m_nAllocationCount;
          if ( (int)&m_pMemory->m_Leaf + 1 > m_nAllocationCount )
            CUtlMemory<unsigned short,int>::Grow(
              this: m_pIndices,
              num: (int)&m_pMemory->m_Leaf - m_nAllocationCount + 1);
          ++m_pIndices[1].m_pMemory;
          v12 = m_pIndices->m_pMemory;
          v13 = (char *)m_pIndices[1].m_pMemory - (char *)m_pMemory - 1;
          m_pIndices[1].m_nAllocationCount = (int)m_pIndices->m_pMemory;
          if ( v13 > 0 )
            _V_memmove(dest: &v12[(_DWORD)m_pMemory + 1], src: &v12[(_DWORD)m_pMemory], count: 2 * v13);
          v14 = &m_pIndices->m_pMemory[(_DWORD)m_pMemory];
          if ( v14 != nullptr )
            v14->m_Leaf = pHelper->m_TempIndices[0];
          v15 = (CUtlMemory<StaticPropLeafLump_t,int> *)pHelper->m_pIndices;
          v16 = v15[1].m_pMemory;
          v17 = v15->m_nAllocationCount;
          if ( (int)&v16->m_Leaf + 1 > v17 )
            CUtlMemory<unsigned short,int>::Grow(this: v15, num: (int)&v16->m_Leaf - v17 + 1);
          ++v15[1].m_pMemory;
          v18 = v15->m_pMemory;
          v19 = (char *)v15[1].m_pMemory - (char *)v16 - 1;
          v15[1].m_nAllocationCount = (int)v15->m_pMemory;
          if ( v19 > 0 )
            _V_memmove(dest: &v18[(_DWORD)v16 + 1], src: &v18[(_DWORD)v16], count: 2 * v19);
          v20 = &v15->m_pMemory[(_DWORD)v16];
          if ( v20 != nullptr )
            v20->m_Leaf = pHelper->m_TempIndices[1];
          v21 = (CUtlMemory<StaticPropLeafLump_t,int> *)pHelper->m_pIndices;
          v22 = v21[1].m_pMemory;
          v23 = v21->m_nAllocationCount;
          if ( (int)&v22->m_Leaf + 1 > v23 )
            CUtlMemory<unsigned short,int>::Grow(this: v21, num: (int)&v22->m_Leaf - v23 + 1);
          ++v21[1].m_pMemory;
          v24 = v21->m_pMemory;
          v25 = (char *)v21[1].m_pMemory - (char *)v22 - 1;
          v21[1].m_nAllocationCount = (int)v21->m_pMemory;
          if ( v25 > 0 )
            _V_memmove(dest: &v24[(_DWORD)v22 + 1], src: &v24[(_DWORD)v22], count: 2 * v25);
          v26 = &v21->m_pMemory[(_DWORD)v22];
          if ( v26 != nullptr )
            v26->m_Leaf = pHelper->m_TempIndices[2];
          pHelper->m_TempIndices[0] = pHelper->m_TempIndices[1];
        }
        v5 = 0;
        iCurTriVert = 0;
      }
      ++iLevela;
      ++iVert;
    }
    while ( iVert < g_TWinding.m_nVerts );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417BD0
// Name: public: CMemoryBSPFile::CMemoryBSPFile(void)
// Source: json
//------------------------------------------------------------------------------
CMemoryBSPFile *__thiscall CMemoryBSPFile::CMemoryBSPFile(CMemoryBSPFile *this)
{
  this->m_pSerialBuffer = nullptr;
  this->m_pMapFile = nullptr;
  CPlaneHash::CPlaneHash(this: &this->m_PlaneHash);
  this->m_TexInfoList.m_Memory.m_pMemory = nullptr;
  this->m_TexInfoList.m_Memory.m_nAllocationCount = 0;
  this->m_TexInfoList.m_Memory.m_nGrowSize = 0;
  this->m_TexInfoList.m_Size = 0;
  this->m_TexInfoList.m_pElements = nullptr;
  this->m_TexDataList.m_Memory.m_pMemory = nullptr;
  this->m_TexDataList.m_Memory.m_nAllocationCount = 0;
  this->m_TexDataList.m_Memory.m_nGrowSize = 0;
  this->m_TexDataList.m_Size = 0;
  this->m_TexDataList.m_pElements = nullptr;
  this->m_TexStringData.m_Memory.m_pMemory = nullptr;
  this->m_TexStringData.m_Memory.m_nAllocationCount = 0;
  this->m_TexStringData.m_Memory.m_nGrowSize = 0;
  this->m_TexStringData.m_Size = 0;
  this->m_TexStringData.m_pElements = nullptr;
  this->m_TexStringIndices.m_Memory.m_pMemory = nullptr;
  this->m_TexStringIndices.m_Memory.m_nAllocationCount = 0;
  this->m_TexStringIndices.m_Memory.m_nGrowSize = 0;
  this->m_TexStringIndices.m_Size = 0;
  this->m_TexStringIndices.m_pElements = nullptr;
  this->m_ModelList.m_Memory.m_pMemory = nullptr;
  this->m_ModelList.m_Memory.m_nAllocationCount = 0;
  this->m_ModelList.m_Memory.m_nGrowSize = 0;
  this->m_ModelList.m_Size = 0;
  this->m_ModelList.m_pElements = nullptr;
  CVertexHash::CVertexHash(this: &this->m_VertexHash);
  this->m_EdgeList.m_Memory.m_pMemory = nullptr;
  this->m_EdgeList.m_Memory.m_nAllocationCount = 0;
  this->m_EdgeList.m_Memory.m_nGrowSize = 0;
  this->m_EdgeList.m_Size = 0;
  this->m_EdgeList.m_pElements = nullptr;
  this->m_SurfEdgeList.m_Memory.m_pMemory = nullptr;
  this->m_SurfEdgeList.m_Memory.m_nAllocationCount = 0;
  this->m_SurfEdgeList.m_Memory.m_nGrowSize = 0;
  this->m_SurfEdgeList.m_Size = 0;
  this->m_SurfEdgeList.m_pElements = nullptr;
  this->m_FaceList.m_Memory.m_pMemory = nullptr;
  this->m_FaceList.m_Memory.m_nAllocationCount = 0;
  this->m_FaceList.m_Memory.m_nGrowSize = 0;
  this->m_FaceList.m_Size = 0;
  this->m_FaceList.m_pElements = nullptr;
  this->m_VertexNormalList.m_Memory.m_pMemory = nullptr;
  this->m_VertexNormalList.m_Memory.m_nAllocationCount = 0;
  this->m_VertexNormalList.m_Memory.m_nGrowSize = 0;
  this->m_VertexNormalList.m_Size = 0;
  this->m_VertexNormalList.m_pElements = nullptr;
  this->m_VertexNormalIndexList.m_Memory.m_pMemory = nullptr;
  this->m_VertexNormalIndexList.m_Memory.m_nAllocationCount = 0;
  this->m_VertexNormalIndexList.m_Memory.m_nGrowSize = 0;
  this->m_VertexNormalIndexList.m_Size = 0;
  this->m_VertexNormalIndexList.m_pElements = nullptr;
  this->m_NodeList.m_Memory.m_pMemory = nullptr;
  this->m_NodeList.m_Memory.m_nAllocationCount = 0;
  this->m_NodeList.m_Memory.m_nGrowSize = 0;
  this->m_NodeList.m_Size = 0;
  this->m_NodeList.m_pElements = nullptr;
  this->m_LeafList.m_Memory.m_pMemory = nullptr;
  this->m_LeafList.m_Memory.m_nAllocationCount = 0;
  this->m_LeafList.m_Memory.m_nGrowSize = 0;
  this->m_LeafList.m_Size = 0;
  this->m_LeafList.m_pElements = nullptr;
  this->m_LeafBrushList.m_Memory.m_pMemory = nullptr;
  this->m_LeafBrushList.m_Memory.m_nAllocationCount = 0;
  this->m_LeafBrushList.m_Memory.m_nGrowSize = 0;
  this->m_LeafBrushList.m_Size = 0;
  this->m_LeafBrushList.m_pElements = nullptr;
  this->m_LeafFaceList.m_Memory.m_pMemory = nullptr;
  this->m_LeafFaceList.m_Memory.m_nAllocationCount = 0;
  this->m_LeafFaceList.m_Memory.m_nGrowSize = 0;
  this->m_LeafFaceList.m_Size = 0;
  this->m_LeafFaceList.m_pElements = nullptr;
  this->m_BrushList.m_Memory.m_pMemory = nullptr;
  this->m_BrushList.m_Memory.m_nAllocationCount = 0;
  this->m_BrushList.m_Memory.m_nGrowSize = 0;
  this->m_BrushList.m_Size = 0;
  this->m_BrushList.m_pElements = nullptr;
  this->m_BrushSideList.m_Memory.m_pMemory = nullptr;
  this->m_BrushSideList.m_Memory.m_nAllocationCount = 0;
  this->m_BrushSideList.m_Memory.m_nGrowSize = 0;
  this->m_BrushSideList.m_Size = 0;
  this->m_BrushSideList.m_pElements = nullptr;
  this->m_Planes.m_Memory.m_pMemory = nullptr;
  this->m_Planes.m_Memory.m_nAllocationCount = 0;
  this->m_Planes.m_Memory.m_nGrowSize = 0;
  this->m_Planes.m_Size = 0;
  this->m_Planes.m_pElements = nullptr;
  this->m_GameLumpData.m_Memory.m_pMemory = nullptr;
  this->m_GameLumpData.m_Memory.m_nAllocationCount = 0;
  this->m_GameLumpData.m_Memory.m_nGrowSize = 0;
  this->m_GameLumpData.m_Size = 0;
  this->m_GameLumpData.m_pElements = nullptr;
  this->m_EntityData.m_Memory.m_pMemory = nullptr;
  this->m_EntityData.m_Memory.m_nAllocationCount = 0;
  this->m_EntityData.m_Memory.m_nGrowSize = 0;
  this->m_EntityData.m_Size = 0;
  this->m_EntityData.m_pElements = nullptr;
  this->m_VisibilityData.m_Memory.m_pMemory = nullptr;
  this->m_VisibilityData.m_Memory.m_nAllocationCount = 0;
  this->m_VisibilityData.m_Memory.m_nGrowSize = 0;
  this->m_VisibilityData.m_Size = 0;
  this->m_VisibilityData.m_pElements = nullptr;
  this->m_DisplacementHelperList.m_Memory.m_pMemory = nullptr;
  this->m_DisplacementHelperList.m_Memory.m_nAllocationCount = 0;
  this->m_DisplacementHelperList.m_Memory.m_nGrowSize = 0;
  this->m_DisplacementHelperList.m_Size = 0;
  this->m_DisplacementHelperList.m_pElements = nullptr;
  this->m_DisplacementList.m_Memory.m_pMemory = nullptr;
  this->m_DisplacementList.m_Memory.m_nAllocationCount = 0;
  this->m_DisplacementList.m_Memory.m_nGrowSize = 0;
  this->m_DisplacementList.m_Size = 0;
  this->m_DisplacementList.m_pElements = nullptr;
  this->m_DisplacementVertexList.m_Memory.m_pMemory = nullptr;
  this->m_DisplacementVertexList.m_Memory.m_nAllocationCount = 0;
  this->m_DisplacementVertexList.m_Memory.m_nGrowSize = 0;
  this->m_DisplacementVertexList.m_Size = 0;
  this->m_DisplacementVertexList.m_pElements = nullptr;
  this->m_DisplacementTriangleList.m_Memory.m_pMemory = nullptr;
  this->m_DisplacementTriangleList.m_Memory.m_nAllocationCount = 0;
  this->m_DisplacementTriangleList.m_Memory.m_nGrowSize = 0;
  this->m_DisplacementTriangleList.m_Size = 0;
  this->m_DisplacementTriangleList.m_pElements = nullptr;
  this->m_DisplacementMultiBlendList.m_Memory.m_pMemory = nullptr;
  this->m_DisplacementMultiBlendList.m_Memory.m_nAllocationCount = 0;
  this->m_DisplacementMultiBlendList.m_Memory.m_nGrowSize = 0;
  this->m_DisplacementMultiBlendList.m_Size = 0;
  this->m_DisplacementMultiBlendList.m_pElements = nullptr;
  this->m_PhysicsDisplacementData.m_Memory.m_pMemory = nullptr;
  this->m_PhysicsDisplacementData.m_Memory.m_nAllocationCount = 0;
  this->m_PhysicsDisplacementData.m_Memory.m_nGrowSize = 0;
  this->m_PhysicsDisplacementData.m_Size = 0;
  this->m_PhysicsDisplacementData.m_pElements = nullptr;
  this->m_PhysicsCollideData.m_Memory.m_pMemory = nullptr;
  this->m_PhysicsCollideData.m_Memory.m_nAllocationCount = 0;
  this->m_PhysicsCollideData.m_Memory.m_nGrowSize = 0;
  this->m_PhysicsCollideData.m_Size = 0;
  this->m_PhysicsCollideData.m_pElements = nullptr;
  this->m_LightingData.m_Memory.m_pMemory = nullptr;
  this->m_LightingData.m_Memory.m_nAllocationCount = 0;
  this->m_LightingData.m_Memory.m_nGrowSize = 0;
  this->m_LightingData.m_Size = 0;
  this->m_LightingData.m_pElements = nullptr;
  this->m_WorldLightsLDR.m_Memory.m_pMemory = nullptr;
  this->m_WorldLightsLDR.m_Memory.m_nAllocationCount = 0;
  this->m_WorldLightsLDR.m_Memory.m_nGrowSize = 0;
  this->m_WorldLightsLDR.m_Size = 0;
  this->m_WorldLightsLDR.m_pElements = nullptr;
  this->m_WorldLightsHDR.m_Memory.m_pMemory = nullptr;
  this->m_WorldLightsHDR.m_Memory.m_nAllocationCount = 0;
  this->m_WorldLightsHDR.m_Memory.m_nGrowSize = 0;
  this->m_WorldLightsHDR.m_Size = 0;
  this->m_WorldLightsHDR.m_pElements = nullptr;
  if ( this != (CMemoryBSPFile *)-71344 )
    memset(dst: (unsigned __int8 *)&this->m_EntityExclusionFlags, value: 0, count: sizeof(this->m_EntityExclusionFlags));
  _V_memset(dest: (unsigned __int8 *)&this->m_FileHeader, fill: 0, count: 0x40Cu);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00417FB0
// Name: public: void CMemoryBSPFile::Deserialize(class CUtlBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::Deserialize(CMemoryBSPFile *this, CUtlBuffer *pInputBuffer)
{
  unsigned int filelen; // ecx
  unsigned int v4; // ecx
  unsigned int v5; // ecx
  int pInputBuffera; // [esp+14h] [ebp+8h]
  int pInputBufferb; // [esp+14h] [ebp+8h]
  int pInputBufferc; // [esp+14h] [ebp+8h]
  int pInputBufferd; // [esp+14h] [ebp+8h]
  int pInputBuffere; // [esp+14h] [ebp+8h]
  int pInputBufferf; // [esp+14h] [ebp+8h]
  int pInputBufferg; // [esp+14h] [ebp+8h]
  int pInputBufferh; // [esp+14h] [ebp+8h]
  int pInputBufferi; // [esp+14h] [ebp+8h]
  int pInputBufferj; // [esp+14h] [ebp+8h]
  CUtlBuffer *pInputBufferk; // [esp+14h] [ebp+8h]
  int pInputBufferl; // [esp+14h] [ebp+8h]
  CUtlBuffer *pInputBufferm; // [esp+14h] [ebp+8h]
  CUtlBuffer *pInputBuffern; // [esp+14h] [ebp+8h]

  this->m_pSerialBuffer = pInputBuffer;
  CUtlBuffer::SeekGet(this: pInputBuffer, type: SEEK_HEAD, offset: 0);
  CUtlBuffer::Get(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)&this->m_FileHeader, size: 1036);
  CMemoryBSPFile::ReadLump<texinfo_s>(this, nLump: 6, pVector: &this->m_TexInfoList);
  if ( this->m_FileHeader.lumps[2].fileofs > 0 )
    CUtlBuffer::SeekGet(this: this->m_pSerialBuffer, type: SEEK_HEAD, offset: this->m_FileHeader.lumps[2].fileofs);
  pInputBuffera = this->m_FileHeader.lumps[2].filelen;
  this->m_TexDataList.m_Size = 0;
  CUtlVector<dnode_t,CUtlMemory<dnode_t,int>>::InsertMultipleBefore(
    this: &this->m_TexDataList,
    elem: 0,
    num: (unsigned int)pInputBuffera >> 5);
  if ( pInputBuffera > 0 )
    CUtlBuffer::Get(
      this: this->m_pSerialBuffer,
      pMem: (unsigned __int8 *)this->m_TexDataList.m_Memory.m_pMemory,
      size: 32 * this->m_TexDataList.m_Size);
  CMemoryBSPFile::ReadLump<unsigned char>(
    this,
    nLump: 43,
    pVector: (CUtlMemory<unsigned char,int> *)&this->m_TexStringData);
  if ( this->m_FileHeader.lumps[44].fileofs > 0 )
    CUtlBuffer::SeekGet(this: this->m_pSerialBuffer, type: SEEK_HEAD, offset: this->m_FileHeader.lumps[44].fileofs);
  pInputBufferb = this->m_FileHeader.lumps[44].filelen;
  this->m_TexStringIndices.m_Size = 0;
  CUtlVector<dedge_t,CUtlMemory<dedge_t,int>>::InsertMultipleBefore(
    this: (CUtlVector<CPhysCollide *,CUtlMemory<CPhysCollide *,int> > *)&this->m_TexStringIndices,
    elem: 0,
    num: (unsigned int)pInputBufferb >> 2);
  if ( pInputBufferb > 0 )
    CUtlBuffer::Get(
      this: this->m_pSerialBuffer,
      pMem: (unsigned __int8 *)this->m_TexStringIndices.m_Memory.m_pMemory,
      size: 4 * this->m_TexStringIndices.m_Size);
  CMemoryBSPFile::ReadLump<Vector>(this, nLump: 3, pVector: &this->m_VertexHash.m_Vertices);
  if ( this->m_FileHeader.lumps[12].fileofs > 0 )
    CUtlBuffer::SeekGet(this: this->m_pSerialBuffer, type: SEEK_HEAD, offset: this->m_FileHeader.lumps[12].fileofs);
  pInputBufferc = this->m_FileHeader.lumps[12].filelen;
  this->m_EdgeList.m_Size = 0;
  CUtlVector<dedge_t,CUtlMemory<dedge_t,int>>::InsertMultipleBefore(
    this: (CUtlVector<CPhysCollide *,CUtlMemory<CPhysCollide *,int> > *)&this->m_EdgeList,
    elem: 0,
    num: (unsigned int)pInputBufferc >> 2);
  if ( pInputBufferc > 0 )
    CUtlBuffer::Get(
      this: this->m_pSerialBuffer,
      pMem: (unsigned __int8 *)this->m_EdgeList.m_Memory.m_pMemory,
      size: 4 * this->m_EdgeList.m_Size);
  if ( this->m_FileHeader.lumps[13].fileofs > 0 )
    CUtlBuffer::SeekGet(this: this->m_pSerialBuffer, type: SEEK_HEAD, offset: this->m_FileHeader.lumps[13].fileofs);
  pInputBufferd = this->m_FileHeader.lumps[13].filelen;
  this->m_SurfEdgeList.m_Size = 0;
  CUtlVector<dedge_t,CUtlMemory<dedge_t,int>>::InsertMultipleBefore(
    this: (CUtlVector<CPhysCollide *,CUtlMemory<CPhysCollide *,int> > *)&this->m_SurfEdgeList,
    elem: 0,
    num: (unsigned int)pInputBufferd >> 2);
  if ( pInputBufferd > 0 )
    CUtlBuffer::Get(
      this: this->m_pSerialBuffer,
      pMem: (unsigned __int8 *)this->m_SurfEdgeList.m_Memory.m_pMemory,
      size: 4 * this->m_SurfEdgeList.m_Size);
  CMemoryBSPFile::ReadLump<dface_t>(this, nLump: 7, pVector: &this->m_FaceList);
  CMemoryBSPFile::ReadLump<Vector>(this, nLump: 30, pVector: &this->m_VertexNormalList);
  if ( this->m_FileHeader.lumps[31].fileofs > 0 )
    CUtlBuffer::SeekGet(this: this->m_pSerialBuffer, type: SEEK_HEAD, offset: this->m_FileHeader.lumps[31].fileofs);
  pInputBuffere = this->m_FileHeader.lumps[31].filelen;
  this->m_VertexNormalIndexList.m_Size = 0;
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
    this: (CUtlVector<CDispTri,CUtlMemory<CDispTri,int> > *)&this->m_VertexNormalIndexList,
    elem: 0,
    num: (unsigned int)pInputBuffere >> 1);
  if ( pInputBuffere > 0 )
    CUtlBuffer::Get(
      this: this->m_pSerialBuffer,
      pMem: (unsigned __int8 *)this->m_VertexNormalIndexList.m_Memory.m_pMemory,
      size: 2 * this->m_VertexNormalIndexList.m_Size);
  if ( this->m_FileHeader.lumps[10].fileofs > 0 )
    CUtlBuffer::SeekGet(this: this->m_pSerialBuffer, type: SEEK_HEAD, offset: this->m_FileHeader.lumps[10].fileofs);
  pInputBufferf = this->m_FileHeader.lumps[10].filelen;
  this->m_LeafList.m_Size = 0;
  CUtlVector<dnode_t,CUtlMemory<dnode_t,int>>::InsertMultipleBefore(
    this: (CUtlVector<dtexdata_t,CUtlMemory<dtexdata_t,int> > *)&this->m_LeafList,
    elem: 0,
    num: (unsigned int)pInputBufferf >> 5);
  if ( pInputBufferf > 0 )
    CUtlBuffer::Get(
      this: this->m_pSerialBuffer,
      pMem: (unsigned __int8 *)this->m_LeafList.m_Memory.m_pMemory,
      size: 32 * this->m_LeafList.m_Size);
  if ( this->m_FileHeader.lumps[17].fileofs > 0 )
    CUtlBuffer::SeekGet(this: this->m_pSerialBuffer, type: SEEK_HEAD, offset: this->m_FileHeader.lumps[17].fileofs);
  pInputBufferg = this->m_FileHeader.lumps[17].filelen;
  this->m_LeafBrushList.m_Size = 0;
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
    this: (CUtlVector<CDispTri,CUtlMemory<CDispTri,int> > *)&this->m_LeafBrushList,
    elem: 0,
    num: (unsigned int)pInputBufferg >> 1);
  if ( pInputBufferg > 0 )
    CUtlBuffer::Get(
      this: this->m_pSerialBuffer,
      pMem: (unsigned __int8 *)this->m_LeafBrushList.m_Memory.m_pMemory,
      size: 2 * this->m_LeafBrushList.m_Size);
  if ( this->m_FileHeader.lumps[16].fileofs > 0 )
    CUtlBuffer::SeekGet(this: this->m_pSerialBuffer, type: SEEK_HEAD, offset: this->m_FileHeader.lumps[16].fileofs);
  pInputBufferh = this->m_FileHeader.lumps[16].filelen;
  this->m_LeafFaceList.m_Size = 0;
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
    this: (CUtlVector<CDispTri,CUtlMemory<CDispTri,int> > *)&this->m_LeafFaceList,
    elem: 0,
    num: (unsigned int)pInputBufferh >> 1);
  if ( pInputBufferh > 0 )
    CUtlBuffer::Get(
      this: this->m_pSerialBuffer,
      pMem: (unsigned __int8 *)this->m_LeafFaceList.m_Memory.m_pMemory,
      size: 2 * this->m_LeafFaceList.m_Size);
  if ( this->m_FileHeader.lumps[5].fileofs > 0 )
    CUtlBuffer::SeekGet(this: this->m_pSerialBuffer, type: SEEK_HEAD, offset: this->m_FileHeader.lumps[5].fileofs);
  pInputBufferi = this->m_FileHeader.lumps[5].filelen;
  this->m_NodeList.m_Size = 0;
  CUtlVector<dnode_t,CUtlMemory<dnode_t,int>>::InsertMultipleBefore(
    this: (CUtlVector<dtexdata_t,CUtlMemory<dtexdata_t,int> > *)&this->m_NodeList,
    elem: 0,
    num: (unsigned int)pInputBufferi >> 5);
  if ( pInputBufferi > 0 )
    CUtlBuffer::Get(
      this: this->m_pSerialBuffer,
      pMem: (unsigned __int8 *)this->m_NodeList.m_Memory.m_pMemory,
      size: 32 * this->m_NodeList.m_Size);
  CMemoryBSPFile::ReadLump<Vector>(
    this,
    nLump: 18,
    pVector: (CUtlVector<Vector,CUtlMemory<Vector,int> > *)&this->m_BrushList);
  if ( this->m_FileHeader.lumps[19].fileofs > 0 )
    CUtlBuffer::SeekGet(this: this->m_pSerialBuffer, type: SEEK_HEAD, offset: this->m_FileHeader.lumps[19].fileofs);
  pInputBufferj = this->m_FileHeader.lumps[19].filelen;
  this->m_BrushSideList.m_Size = 0;
  CUtlVector<dbrushside_t,CUtlMemory<dbrushside_t,int>>::InsertMultipleBefore(
    this: &this->m_BrushSideList,
    elem: 0,
    num: (unsigned int)pInputBufferj >> 3);
  if ( pInputBufferj > 0 )
    CUtlBuffer::Get(
      this: this->m_pSerialBuffer,
      pMem: (unsigned __int8 *)this->m_BrushSideList.m_Memory.m_pMemory,
      size: 8 * this->m_BrushSideList.m_Size);
  CMemoryBSPFile::ReadLump<CDispVert>(
    this,
    nLump: 1,
    pVector: (CUtlVector<CDispVert,CUtlMemory<CDispVert,int> > *)&this->m_Planes);
  CMemoryBSPFile::ReadLump<dmodel_t>(this, nLump: 14, pVector: &this->m_ModelList);
  CMemoryBSPFile::ReadLump<unsigned char>(this, nLump: 35, pVector: &this->m_GameLumpData.m_Memory);
  CMemoryBSPFile::ReadLump<unsigned char>(this, nLump: 0, pVector: &this->m_EntityData.m_Memory);
  CMemoryBSPFile::ReadLump<unsigned char>(this, nLump: 4, pVector: &this->m_VisibilityData.m_Memory);
  if ( this->m_FileHeader.lumps[26].fileofs > 0 )
    CUtlBuffer::SeekGet(this: this->m_pSerialBuffer, type: SEEK_HEAD, offset: this->m_FileHeader.lumps[26].fileofs);
  filelen = this->m_FileHeader.lumps[26].filelen;
  pInputBufferk = (CUtlBuffer *)filelen;
  this->m_DisplacementList.m_Size = 0;
  CUtlVector<ddispinfo_t,CUtlMemory<ddispinfo_t,int>>::InsertMultipleBefore(
    this: &this->m_DisplacementList,
    elem: 0,
    num: filelen / 0xB0);
  if ( (int)pInputBufferk > 0 )
    CUtlBuffer::Get(
      this: this->m_pSerialBuffer,
      pMem: (unsigned __int8 *)this->m_DisplacementList.m_Memory.m_pMemory,
      size: 176 * this->m_DisplacementList.m_Size);
  CMemoryBSPFile::ReadLump<CDispVert>(this, nLump: 33, pVector: &this->m_DisplacementVertexList);
  if ( this->m_FileHeader.lumps[48].fileofs > 0 )
    CUtlBuffer::SeekGet(this: this->m_pSerialBuffer, type: SEEK_HEAD, offset: this->m_FileHeader.lumps[48].fileofs);
  pInputBufferl = this->m_FileHeader.lumps[48].filelen;
  this->m_DisplacementTriangleList.m_Size = 0;
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int>>::InsertMultipleBefore(
    this: &this->m_DisplacementTriangleList,
    elem: 0,
    num: (unsigned int)pInputBufferl >> 1);
  if ( pInputBufferl > 0 )
    CUtlBuffer::Get(
      this: this->m_pSerialBuffer,
      pMem: (unsigned __int8 *)this->m_DisplacementTriangleList.m_Memory.m_pMemory,
      size: 2 * this->m_DisplacementTriangleList.m_Size);
  CMemoryBSPFile::ReadLump<CDispMultiBlend>(this, nLump: 63, pVector: &this->m_DisplacementMultiBlendList);
  CMemoryBSPFile::ReadLump<unsigned char>(this, nLump: 28, pVector: &this->m_PhysicsDisplacementData.m_Memory);
  CMemoryBSPFile::ReadLump<unsigned char>(this, nLump: 29, pVector: &this->m_PhysicsCollideData.m_Memory);
  CMemoryBSPFile::ReadLump<unsigned char>(this, nLump: 8, pVector: &this->m_LightingData.m_Memory);
  if ( this->m_FileHeader.lumps[15].fileofs > 0 )
    CUtlBuffer::SeekGet(this: this->m_pSerialBuffer, type: SEEK_HEAD, offset: this->m_FileHeader.lumps[15].fileofs);
  v4 = this->m_FileHeader.lumps[15].filelen;
  pInputBufferm = (CUtlBuffer *)v4;
  this->m_WorldLightsLDR.m_Size = 0;
  CUtlVector<dworldlight_t,CUtlMemory<dworldlight_t,int>>::InsertMultipleBefore(
    this: &this->m_WorldLightsLDR,
    elem: 0,
    num: v4 / 0x64);
  if ( (int)pInputBufferm > 0 )
    CUtlBuffer::Get(
      this: this->m_pSerialBuffer,
      pMem: (unsigned __int8 *)this->m_WorldLightsLDR.m_Memory.m_pMemory,
      size: 100 * this->m_WorldLightsLDR.m_Size);
  if ( this->m_FileHeader.lumps[54].fileofs > 0 )
    CUtlBuffer::SeekGet(this: this->m_pSerialBuffer, type: SEEK_HEAD, offset: this->m_FileHeader.lumps[54].fileofs);
  v5 = this->m_FileHeader.lumps[54].filelen;
  pInputBuffern = (CUtlBuffer *)v5;
  this->m_WorldLightsHDR.m_Size = 0;
  CUtlVector<dworldlight_t,CUtlMemory<dworldlight_t,int>>::InsertMultipleBefore(
    this: &this->m_WorldLightsHDR,
    elem: 0,
    num: v5 / 0x64);
  if ( (int)pInputBuffern > 0 )
    CUtlBuffer::Get(
      this: this->m_pSerialBuffer,
      pMem: (unsigned __int8 *)this->m_WorldLightsHDR.m_Memory.m_pMemory,
      size: 100 * this->m_WorldLightsHDR.m_Size);
}

//------------------------------------------------------------------------------
// Address: 0x00418550
// Name: private: void CMemoryBSPFile::BuildModelData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::BuildModelData(CMemoryBSPFile *this)
{
  int v2; // ebx
  CUtlVector<dmodel_t,CUtlMemory<dmodel_t,int> > *p_m_ModelList; // ecx
  dmodel_t *v4; // esi
  CBSPModel *v5; // ebx
  CBSPNode *m_pRoot; // eax
  bool v7; // cc
  int v8; // ebx
  const CSimpleBSPFile *m_pSimpleBSPFile; // eax
  int m_Size; // [esp-4h] [ebp-1Ch]
  int nFace; // [esp+Ch] [ebp-Ch]
  int nFacea; // [esp+Ch] [ebp-Ch]
  int nFaceb; // [esp+Ch] [ebp-Ch]
  int nModel; // [esp+10h] [ebp-8h]
  CBSPNode *v15; // [esp+14h] [ebp-4h]

  v2 = 0;
  m_Size = this->m_pSimpleBSPFile->m_Models.m_Size;
  p_m_ModelList = &this->m_ModelList;
  p_m_ModelList->m_Size = 0;
  CUtlVector<dmodel_t,CUtlMemory<dmodel_t,int>>::InsertMultipleBefore(this: p_m_ModelList, elem: 0, num: m_Size);
  nModel = 0;
  if ( this->m_pSimpleBSPFile->m_Models.m_Size > 0 )
  {
    while ( 1 )
    {
      v4 = &this->m_ModelList.m_Memory.m_pMemory[v2];
      memset(dst: (unsigned __int8 *)v4, value: 0, count: sizeof(dmodel_t));
      v5 = this->m_pSimpleBSPFile->m_Models.m_Memory.m_pMemory[v2];
      v4->firstface = this->m_FaceList.m_Size;
      v4->origin.x = 0.0;
      v4->origin.y = 0.0;
      v4->origin.z = 0.0;
      v4->mins.x = v5->m_vMinBounds.x;
      v4->mins.y = v5->m_vMinBounds.y;
      v4->mins.z = v5->m_vMinBounds.z;
      v4->maxs.x = v5->m_vMaxBounds.x;
      v4->maxs.y = v5->m_vMaxBounds.y;
      v4->maxs.z = v5->m_vMaxBounds.z;
      m_pRoot = v5->m_pTree->m_pRoot;
      v15 = m_pRoot;
      if ( m_pRoot->m_nSplitPlaneIndex != -1 )
      {
        nFace = 0;
        if ( m_pRoot->m_Faces.m_Size > 0 )
        {
          do
          {
            CMemoryBSPFile::EmitFace(this, pBSPFace: (dedge_t)m_pRoot->m_Faces.m_Memory.m_pMemory[nFace], bOnNode: 1u);
            v7 = ++nFace < v15->m_Faces.m_Size;
            m_pRoot = v15;
          }
          while ( v7 );
        }
        CMemoryBSPFile::WritePortalFaces(this, pNode: m_pRoot->m_pChildren[0]);
        CMemoryBSPFile::WritePortalFaces(this, pNode: v15->m_pChildren[1]);
      }
      for ( nFacea = 0; nFacea < v5->m_DetailFaces.m_Size; ++nFacea )
        CMemoryBSPFile::EmitFace(this, pBSPFace: (dedge_t)v5->m_DetailFaces.m_Memory.m_pMemory[nFacea], bOnNode: 0);
      v8 = 0;
      if ( nModel == 0 )
      {
        m_pSimpleBSPFile = this->m_pSimpleBSPFile;
        if ( m_pSimpleBSPFile->m_DisplacementFaces.m_Size > 0 )
        {
          nFaceb = 0;
          do
          {
            CMemoryBSPFile::EmitFace(
              this,
              pBSPFace: (dedge_t)&m_pSimpleBSPFile->m_DisplacementFaces.m_Memory.m_pMemory[nFaceb],
              bOnNode: 0);
            m_pSimpleBSPFile = this->m_pSimpleBSPFile;
            ++nFaceb;
            ++v8;
          }
          while ( v8 < m_pSimpleBSPFile->m_DisplacementFaces.m_Size );
        }
      }
      v4->numfaces = this->m_FaceList.m_Size - v4->firstface;
      if ( ++nModel >= this->m_pSimpleBSPFile->m_Models.m_Size )
        break;
      v2 = nModel;
    }
  }
  if ( this->m_VertexHash.m_Vertices.m_Size > 0x10000
    && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
  {
    _LoggingSystem_Log(
      a1: LOG_VBSP2,
      a2: 1,
      a3: "Vertex count (%d) exceeded MAX_MAP_VERTS (%d).\n",
      this->m_VertexHash.m_Vertices.m_Size,
      0x10000);
  }
  if ( this->m_EdgeList.m_Size > 256000 && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
    _LoggingSystem_Log(
      a1: LOG_VBSP2,
      a2: 1,
      a3: "Edge count (%d) exceeded MAX_MAP_EDGES (%d).\n",
      this->m_EdgeList.m_Size,
      256000);
  if ( this->m_SurfEdgeList.m_Size > 512000
    && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
  {
    _LoggingSystem_Log(
      a1: LOG_VBSP2,
      a2: 1,
      a3: "SurfEdge count (%d) exceeded MAX_MAP_SURFEDGES (%d).\n",
      this->m_SurfEdgeList.m_Size,
      512000);
  }
  if ( this->m_FaceList.m_Size > 0x10000 && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
    _LoggingSystem_Log(
      a1: LOG_VBSP2,
      a2: 1,
      a3: "Face count (%d) exceeded MAX_MAP_FACES (%d).\n",
      this->m_FaceList.m_Size,
      0x10000);
  if ( this->m_VertexNormalList.m_Size > 256000
    && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
  {
    _LoggingSystem_Log(
      a1: LOG_VBSP2,
      a2: 1,
      a3: "Vertex normal count (%d) exceeded MAX_MAP_VERTNORMALS (%d).\n",
      this->m_VertexNormalList.m_Size,
      256000);
  }
  if ( this->m_VertexNormalIndexList.m_Size > 256000
    && (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 1) != 0 )
  {
    _LoggingSystem_Log(
      a1: LOG_VBSP2,
      a2: 1,
      a3: "Vertex normal index count (%d) exceeded MAX_MAP_VERTNORMALS (%d).\n",
      this->m_VertexNormalIndexList.m_Size,
      256000);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418860
// Name: private: void CMemoryBSPFile::EmitStaticProp(struct MapEntity_t const __near *,class CUtlVector<struct StaticPropLump_t,class CUtlMemory<struct StaticPropLump_t,int>> __near *,class CUtlVector<struct StaticPropLeafLump_t,class CUtlMemory<struct StaticPropLeafLump_t,int>> __near *,class CUtlVector<struct StaticPropDictLump_t,class CUtlMemory<struct StaticPropDictLump_t,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::EmitStaticProp(
        CMemoryBSPFile *this,
        int pEntity,
        CUtlMemory<MapTextureInfo_t,int> *pStaticPropLump,
        CUtlVector<StaticPropLeafLump_t,CUtlMemory<StaticPropLeafLump_t,int> > *pStaticPropLeafLump,
        CUtlVector<StaticPropDictLump_t,CUtlMemory<StaticPropDictLump_t,int> > *pStaticPropDictionaryLump)
{
  CUtlMemory<MapTextureInfo_t,int> *v5; // esi
  const MapEntity_t *v6; // edi
  int v7; // ecx
  const MapEntityKeyValuePair_t *v8; // ebx
  int m_nAllocationCount; // eax
  MapTextureInfo_t *m_pMemory; // edx
  int v11; // eax
  int v12; // esi
  const MapEntityKeyValuePair_t *Pair; // eax
  const char *PairValue; // eax
  const MapEntityKeyValuePair_t *v15; // eax
  const char *v16; // eax
  const MapEntityKeyValuePair_t *v17; // eax
  const char *v18; // eax
  const MapEntityKeyValuePair_t *v19; // eax
  const char *v20; // eax
  const MapEntityKeyValuePair_t *v21; // eax
  const char *v22; // eax
  const MapEntityKeyValuePair_t *v23; // eax
  const char *v24; // eax
  const MapEntityKeyValuePair_t *v25; // eax
  const char *v26; // eax
  const MapEntityKeyValuePair_t *v27; // eax
  const char *v28; // eax
  const MapEntityKeyValuePair_t *v29; // eax
  const char *v30; // eax
  const MapEntityKeyValuePair_t *v31; // eax
  const MapEntityKeyValuePair_t *v32; // eax
  const char *m_pValue; // edi
  char *v34; // eax
  char v35; // dl
  CUtlVector<StaticPropLeafLump_t,CUtlMemory<StaticPropLeafLump_t,int> > *v36; // [esp-4h] [ebp-14h]

  v5 = pStaticPropLump;
  v6 = (const MapEntity_t *)pEntity;
  v8 = &this->m_pMapFile->m_KeyValuePairs.m_Memory.m_pMemory[*(_DWORD *)(pEntity + 20)];
  m_nAllocationCount = pStaticPropLump->m_nAllocationCount;
  pEntity = (int)pStaticPropLump[1].m_pMemory;
  v7 = pEntity;
  if ( pEntity + 1 > m_nAllocationCount )
  {
    CUtlMemory<StaticPropLump_t,int>::Grow(this: pStaticPropLump, num: pEntity - m_nAllocationCount + 1);
    v7 = pEntity;
  }
  ++v5[1].m_pMemory;
  m_pMemory = v5->m_pMemory;
  v11 = (int)v5[1].m_pMemory - v7 - 1;
  v5[1].m_nAllocationCount = (int)v5->m_pMemory;
  if ( v11 > 0 )
    _V_memmove(dest: &m_pMemory[v7 + 1], src: &m_pMemory[v7], count: 72 * v11);
  v12 = (int)&v5->m_pMemory[(int)v5[1].m_pMemory - 1];
  *(float *)v12 = v6->m_vOrigin.x;
  *(float *)(v12 + 4) = v6->m_vOrigin.y;
  *(float *)(v12 + 8) = v6->m_vOrigin.z;
  *(_QWORD *)(v12 + 16) = 0;
  *(_DWORD *)(v12 + 12) = 0;
  Pair = FindPair(pKeyName: "angles", pPairs: v8, nNumPairs: v6->m_nNumKVPairs);
  PairValue = GetPairValue(pPair: Pair);
  sscanf(string: PairValue, format: "%f %f %f", v12 + 12, v12 + 16, v12 + 20);
  v15 = FindPair(pKeyName: "model", pPairs: v8, nNumPairs: v6->m_nNumKVPairs);
  v16 = GetPairValue(pPair: v15);
  *(_WORD *)(v12 + 24) = CMemoryBSPFile::AddStaticPropDictionaryEntry(this, pModelName: v16, pStaticPropDictionaryLump);
  v36 = pStaticPropLeafLump;
  *(_WORD *)(v12 + 26) = pStaticPropLeafLump->m_Size;
  *(_WORD *)(v12 + 28) = CMemoryBSPFile::AddStaticPropLeaves(
                           this,
                           vOrigin: (const Vector *)v12,
                           nNodeIndex: 0,
                           pStaticPropLeafLump: v36);
  v17 = FindPair(pKeyName: "solid", pPairs: v8, nNumPairs: v6->m_nNumKVPairs);
  v18 = GetPairValue(pPair: v17);
  *(_BYTE *)(v12 + 30) = atoi(nptr: v18);
  v19 = FindPair(pKeyName: "skin", pPairs: v8, nNumPairs: v6->m_nNumKVPairs);
  v20 = GetPairValue(pPair: v19);
  *(_DWORD *)(v12 + 32) = atoi(nptr: v20);
  *(_BYTE *)(v12 + 31) = 0;
  v21 = FindPair(pKeyName: "disablesahdows", pPairs: v8, nNumPairs: v6->m_nNumKVPairs);
  v22 = GetPairValue(pPair: v21);
  if ( atoi(nptr: v22) == 1 )
    *(_BYTE *)(v12 + 31) |= 0x10u;
  v23 = FindPair(pKeyName: "ignorenormals", pPairs: v8, nNumPairs: v6->m_nNumKVPairs);
  v24 = GetPairValue(pPair: v23);
  if ( atoi(nptr: v24) == 1 )
    *(_BYTE *)(v12 + 31) |= 8u;
  v25 = FindPair(pKeyName: "disableselfshadowing", pPairs: v8, nNumPairs: v6->m_nNumKVPairs);
  v26 = GetPairValue(pPair: v25);
  if ( atoi(nptr: v26) == 1 )
    *(_BYTE *)(v12 + 31) |= 0x80u;
  v27 = FindPair(pKeyName: "disablevertexlighting", pPairs: v8, nNumPairs: v6->m_nNumKVPairs);
  v28 = GetPairValue(pPair: v27);
  if ( atoi(nptr: v28) == 1 )
    *(_BYTE *)(v12 + 31) |= 0x40u;
  v29 = FindPair(pKeyName: "fademaxdist", pPairs: v8, nNumPairs: v6->m_nNumKVPairs);
  v30 = GetPairValue(pPair: v29);
  *(float *)(v12 + 40) = atof(nptr: v30);
  *(_DWORD *)(v12 + 36) = 0;
  *(Vector *)(v12 + 44) = vec3_origin;
  *(_QWORD *)(v12 + 56) = 1065353216;
  *(_BYTE *)(v12 + 68) = 0;
  v31 = FindPair(pKeyName: "rendercolor", pPairs: v8, nNumPairs: v6->m_nNumKVPairs);
  if ( v31 != nullptr )
    pEntity = (int)v31->m_pValue;
  else
    pEntity = 0;
  v32 = FindPair(pKeyName: "renderamt", pPairs: v8, nNumPairs: v6->m_nNumKVPairs);
  if ( v32 != nullptr )
    m_pValue = v32->m_pValue;
  else
    m_pValue = nullptr;
  v34 = (char *)pEntity;
  *(_DWORD *)(v12 + 64) = -1;
  if ( v34 != nullptr )
  {
    V_StringToColor32(color: (color32_s *)&pEntity, pString: v34);
    v35 = BYTE2(pEntity);
    *(_WORD *)(v12 + 64) = pEntity;
    *(_BYTE *)(v12 + 66) = v35;
  }
  if ( m_pValue != nullptr )
    *(_BYTE *)(v12 + 67) = atoi(nptr: m_pValue);
}

//------------------------------------------------------------------------------
// Address: 0x00418B40
// Name: private: class CPhysCollisionEntry __near * CMemoryBSPFile::CreateWorldPhysicsModels(class IPhysicsCollision __near *,class CUtlVector<int,class CUtlMemory<int,int>> __near *,int const __near *,struct dmodel_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CPhysCollisionEntryStaticSolid *__userpurge CMemoryBSPFile::CreateWorldPhysicsModels@<eax>(
        CMemoryBSPFile *this@<ecx>,
        int a2@<esi>,
        IPhysicsCollision *pPhysicsCollision,
        CUtlVector<int,CUtlMemory<int,int> > *pWorldPropertyRemapList,
        const int *pSurfacePropertyList,
        const dmodel_t *pModel,
        int contentsMask)
{
  IPhysicsCollision *v7; // ebx
  struct CPhysCollide *v9; // eax
  IPhysicsCollision_vtbl *v10; // edx
  int v11; // esi
  int v12; // ebx
  int m_nTextureInfoIndex; // eax
  int v14; // eax
  CPhysCollisionEntryStaticSolid *v15; // eax
  CPhysCollisionEntryStaticSolid *v16; // edi
  struct CPhysConvex **m_pMemory; // eax
  int v19; // [esp+14h] [ebp-474h]
  CPhysConvexBuilder physConvexBuilder; // [esp+18h] [ebp-470h] BYREF
  Vector vPoints[3]; // [esp+440h] [ebp-48h] BYREF
  Vector vNormal; // [esp+464h] [ebp-24h] BYREF
  int v23; // [esp+470h] [ebp-18h]
  int nBrushIndex; // [esp+474h] [ebp-14h]
  struct CPhysCollide *pCollide; // [esp+478h] [ebp-10h]
  int nConvexCount; // [esp+47Ch] [ebp-Ch]
  int nTriCount; // [esp+480h] [ebp-8h]
  int j; // [esp+484h] [ebp-4h]
  int i; // [esp+49Ch] [ebp+14h]

  v7 = pPhysicsCollision;
  CPhysConvexBuilder::CPhysConvexBuilder(
    this: &physConvexBuilder,
    flShrink: 0.0,
    contentsMask,
    pMapFile: this->m_pMapFile,
    pPhysicsCollision);
  CPhysConvexBuilder::BuildConvexes(
    this: &physConvexBuilder,
    nNodeIndex: pModel->headnode,
    nodeList: &this->m_NodeList,
    leafList: &this->m_LeafList,
    leafBrushList: &this->m_LeafBrushList);
  if ( physConvexBuilder.m_Convexes.m_Size <= 0 )
  {
    CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>::~CUtlVector<MapEntityKeyValuePair_t,CUtlMemory<MapEntityKeyValuePair_t,int>>(this: (CUtlVector<CBSPBrush *,CUtlMemory<CBSPBrush *,int> > *)&physConvexBuilder);
    return nullptr;
  }
  else
  {
    v9 = (struct CPhysCollide *)((int (__thiscall *)(IPhysicsCollision *, struct CPhysConvex **, int, int))pPhysicsCollision->ConvertConvexToCollide)(
                                  a1: pPhysicsCollision,
                                  a2: physConvexBuilder.m_Convexes.m_Memory.m_pMemory,
                                  a3: physConvexBuilder.m_Convexes.m_Size,
                                  a4: a2);
    v10 = pPhysicsCollision->__vftable;
    pCollide = v9;
    v11 = (int)v10->CreateQueryModel(this: pPhysicsCollision, a2: v9);
    nConvexCount = (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 4))(a1: v11);
    i = 0;
    if ( nConvexCount > 0 )
    {
      do
      {
        nTriCount = (*(int (__thiscall **)(int, int))(*(_DWORD *)v11 + 8))(a1: v11, a2: i);
        v12 = 0;
        nBrushIndex = (*(int (__thiscall **)(int, int))(*(_DWORD *)v11 + 12))(a1: v11, a2: i);
        for ( j = 0; v12 < nTriCount; j = v12 )
        {
          (*(void (__thiscall **)(int, int, int, Vector *))(*(_DWORD *)v11 + 16))(a1: v11, a2: i, a3: v12, a4: vPoints);
          TriangleNormal(result: &vNormal, v0: vPoints, v1: &vPoints[1], v2: &vPoints[2]);
          m_nTextureInfoIndex = CMemoryBSPFile::FindClosestBrushSide(
                                  this,
                                  (const MapBrushSide_t *)nBrushIndex,
                                  &vNormal)->m_nTextureInfoIndex;
          if ( m_nTextureInfoIndex != -1 )
          {
            v19 = pSurfacePropertyList[this->m_pMapFile->m_TextureInfos.m_Memory.m_pMemory[m_nTextureInfoIndex].m_nTextureDataIndex];
            v23 = *(_DWORD *)v11;
            v14 = CMemoryBSPFile::RemapWorldMaterial(this, pWorldPropertyRemapList, nSurfacePropertyIndex: v19);
            v12 = j;
            (*(void (__thiscall **)(int, int, int, int))(v23 + 28))(a1: v11, a2: i, a3: j, a4: v14);
          }
          ++v12;
        }
        ++i;
      }
      while ( i < nConvexCount );
      v7 = pPhysicsCollision;
    }
    v7->DestroyQueryModel(this: v7, a2: (ICollisionQuery *)v11);
    v15 = (CPhysCollisionEntryStaticSolid *)operator new(nSize: 0xCu);
    if ( v15 != nullptr )
      v16 = CPhysCollisionEntryStaticSolid::CPhysCollisionEntryStaticSolid(this: v15, pCollide, contentsMask);
    else
      v16 = nullptr;
    m_pMemory = physConvexBuilder.m_Convexes.m_Memory.m_pMemory;
    physConvexBuilder.m_Convexes.m_Size = 0;
    if ( physConvexBuilder.m_Convexes.m_Memory.m_nGrowSize >= 0 )
    {
      if ( physConvexBuilder.m_Convexes.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: physConvexBuilder.m_Convexes.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        physConvexBuilder.m_Convexes.m_Memory.m_pMemory = nullptr;
      }
      physConvexBuilder.m_Convexes.m_Memory.m_nAllocationCount = 0;
    }
    physConvexBuilder.m_Convexes.m_pElements = m_pMemory;
    if ( physConvexBuilder.m_Convexes.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    return v16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418D60
// Name: void TesselateDisplacement_R<class CSimpleBSPTessellateHelper>(class CSimpleBSPTessellateHelper __near *,class CVertIndex const __near &,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TesselateDisplacement_R<CSimpleBSPTessellateHelper>(
        CSimpleBSPTessellateHelper *pHelper,
        const CVertIndex *nodeIndex,
        int iNodeBitIndex,
        int iLevel)
{
  const CPowerInfo *m_pPowerInfo; // ecx
  int v6; // edx
  int v7; // ebx
  const CPowerInfo *v8; // ecx
  const CVertIndex *v9; // esi
  unsigned int v10; // edx
  int bActiveChildren[4]; // [esp+0h] [ebp-18h] BYREF
  int oldIndexCount; // [esp+10h] [ebp-8h]
  int v13; // [esp+14h] [ebp-4h]
  int iChildNodeBit; // [esp+20h] [ebp+8h]

  if ( (`CSimpleBSPTessellateHelper::GetNodeInfo'::`2'::`local static guard' & 1) == 0 )
    `CSimpleBSPTessellateHelper::GetNodeInfo'::`2'::`local static guard' |= 1u;
  m_pPowerInfo = pHelper->m_pPowerInfo;
  v6 = m_pPowerInfo->m_Power - 1;
  oldIndexCount = pHelper->m_nIndices;
  if ( iLevel < v6 )
  {
    v7 = 0;
    iChildNodeBit = iNodeBitIndex + 1;
    v13 = 16 * (nodeIndex->x + m_pPowerInfo->m_SideLength * nodeIndex->y);
    do
    {
      v8 = pHelper->m_pPowerInfo;
      v9 = &v8->m_pChildVerts->m_Verts[v13 / 4u];
      v10 = pHelper->m_pActiveVerts[(v9->x + v8->m_SideLength * v9->y) >> 5]
          & (1 << ((v9->x + LOBYTE(v8->m_SideLength) * v9->y) & 0x1F));
      bActiveChildren[v7] = v10;
      if ( v10 != 0 )
      {
        TesselateDisplacement_R<CSimpleBSPTessellateHelper>(
          pHelper,
          nodeIndex: v9,
          iNodeBitIndex: iChildNodeBit,
          iLevel: iLevel + 1);
      }
      else
      {
        if ( (`CSimpleBSPTessellateHelper::GetNodeInfo'::`2'::`local static guard' & 1) == 0 )
          `CSimpleBSPTessellateHelper::GetNodeInfo'::`2'::`local static guard' |= 1u;
        word_47FB36 = 0;
      }
      iChildNodeBit += pHelper->m_pPowerInfo->m_NodeIndexIncrements[iLevel];
      v13 += 4;
      ++v7;
    }
    while ( v7 < 4 );
  }
  else
  {
    memset(bActiveChildren, 0, sizeof(bActiveChildren));
  }
  if ( pHelper->m_nIndices == oldIndexCount )
  {
    HIBYTE(word_47FB36) = 0;
  }
  else
  {
    HIBYTE(word_47FB36) = 1;
    oldIndexCount = pHelper->m_nIndices;
  }
  TesselateDisplacementNode<CSimpleBSPTessellateHelper>(pHelper, nodeIndex, iLevel, pActiveChildren: bActiveChildren);
  LOBYTE(word_47FB36) = LOBYTE(pHelper->m_nIndices) - oldIndexCount;
  `CSimpleBSPTessellateHelper::GetNodeInfo'::`2'::dummy = oldIndexCount;
}

//------------------------------------------------------------------------------
// Address: 0x00418E90
// Name: private: void CMemoryBSPFile::BuildGameLumpData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::BuildGameLumpData(CMemoryBSPFile *this)
{
  int v1; // ebx
  const CSimpleMapFile *m_pMapFile; // eax
  int m_Size; // ecx
  const CSimpleMapFile *v5; // eax
  int v6; // esi
  const MapEntityKeyValuePair_t *Pair; // eax
  const CSimpleMapFile *v8; // eax
  int v9; // ecx
  int v10; // eax
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *p_m_GameLumpData; // esi
  unsigned __int8 *m_pMemory; // edx
  unsigned __int8 *v13; // eax
  int v14; // ebx
  int m_nAllocationCount; // eax
  unsigned __int8 *v16; // ecx
  int v17; // eax
  unsigned __int8 *v18; // eax
  unsigned __int8 *v19; // ebx
  int m_Put; // eax
  int v21; // edi
  int v22; // ebx
  int v23; // eax
  unsigned __int8 *v24; // ecx
  int v25; // eax
  int i; // eax
  unsigned __int8 *v27; // ecx
  int v28; // edi
  int v29; // eax
  unsigned __int8 *v30; // ecx
  int v31; // eax
  int j; // eax
  unsigned __int8 *v33; // ecx
  int v34; // edi
  int v35; // eax
  unsigned __int8 *v36; // ecx
  int v37; // eax
  unsigned __int8 *v38; // eax
  int v39; // edi
  int v40; // eax
  __int16 v41; // bx
  unsigned __int8 *v42; // ecx
  int v43; // eax
  unsigned __int8 *v44; // eax
  unsigned __int8 *v45; // edi
  int v46; // edi
  int v47; // eax
  unsigned __int8 *v48; // ecx
  int v49; // eax
  unsigned __int8 *v50; // eax
  unsigned __int8 *v51; // edi
  int v52; // edi
  int v53; // eax
  unsigned __int8 *v54; // ecx
  int v55; // eax
  unsigned __int8 *v56; // eax
  unsigned __int8 *v57; // edi
  int v58; // edi
  int v59; // eax
  unsigned __int8 *v60; // ecx
  int v61; // eax
  unsigned __int8 *v62; // eax
  int v63; // edi
  int v64; // eax
  unsigned __int8 *v65; // ecx
  int v66; // eax
  unsigned __int8 *v67; // eax
  StaticPropLeafLump_t *v68; // eax
  CUtlVector<StaticPropDictLump_t,CUtlMemory<StaticPropDictLump_t,int> > staticPropDictionaryLump; // [esp+Ch] [ebp-5Ch] BYREF
  CUtlVector<StaticPropLump_t,CUtlMemory<StaticPropLump_t,int> > staticPropLump; // [esp+20h] [ebp-48h] BYREF
  CUtlVector<StaticPropLeafLump_t,CUtlMemory<StaticPropLeafLump_t,int> > staticPropLeafLump; // [esp+34h] [ebp-34h] BYREF
  dgamelump_t staticPropLumpHeader; // [esp+48h] [ebp-20h]
  int nPropSize; // [esp+58h] [ebp-10h]
  int nLeafSize; // [esp+5Ch] [ebp-Ch]
  int nDictionarySize; // [esp+60h] [ebp-8h]
  int nCount; // [esp+64h] [ebp-4h]

  v1 = 0;
  m_pMapFile = this->m_pMapFile;
  m_Size = 0;
  memset(&staticPropLeafLump, 0, sizeof(staticPropLeafLump));
  memset(&staticPropDictionaryLump, 0, sizeof(staticPropDictionaryLump));
  memset(&staticPropLump, 0, sizeof(staticPropLump));
  if ( m_pMapFile->m_Entities.m_Size > 0 )
  {
    nCount = 0;
    do
    {
      v5 = this->m_pMapFile;
      v6 = (int)v5->m_Entities.m_Memory.m_pMemory + nCount;
      Pair = FindPair(
               pKeyName: "classname",
               pPairs: &v5->m_KeyValuePairs.m_Memory.m_pMemory[*(_DWORD *)(v6 + 20)],
               nNumPairs: *(_DWORD *)(v6 + 24));
      if ( Pair != nullptr && _V_stricmp(s1: Pair->m_pValue, s2: "prop_static") == 0 )
      {
        CMemoryBSPFile::EmitStaticProp(
          this,
          pEntity: v6,
          pStaticPropLump: (CUtlMemory<MapTextureInfo_t,int> *)&staticPropLump,
          pStaticPropLeafLump: &staticPropLeafLump,
          pStaticPropDictionaryLump: &staticPropDictionaryLump);
        this->m_EntityExclusionFlags.m_Ints[v1 >> 5] |= 1 << (v1 & 0x1F);
      }
      v8 = this->m_pMapFile;
      nCount += 28;
      ++v1;
    }
    while ( v1 < v8->m_Entities.m_Size );
    m_Size = staticPropLump.m_Size;
  }
  nPropSize = 72 * m_Size;
  v9 = 2 * staticPropLeafLump.m_Size + 72 * m_Size;
  nDictionarySize = staticPropDictionaryLump.m_Size << 7;
  nCount = v9 + (staticPropDictionaryLump.m_Size << 7) + 12;
  v10 = v9 + (staticPropDictionaryLump.m_Size << 7) + 60;
  p_m_GameLumpData = &this->m_GameLumpData;
  nLeafSize = 2 * staticPropLeafLump.m_Size;
  if ( this->m_GameLumpData.m_Memory.m_nAllocationCount < v10 && this->m_GameLumpData.m_Memory.m_nGrowSize >= 0 )
  {
    m_pMemory = p_m_GameLumpData->m_Memory.m_pMemory;
    this->m_GameLumpData.m_Memory.m_nAllocationCount = v10;
    if ( m_pMemory != nullptr )
      v13 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v10);
    else
      v13 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v10);
    p_m_GameLumpData->m_Memory.m_pMemory = v13;
  }
  this->m_GameLumpData.m_pElements = this->m_GameLumpData.m_Memory.m_pMemory;
  v14 = this->m_GameLumpData.m_Size;
  m_nAllocationCount = this->m_GameLumpData.m_Memory.m_nAllocationCount;
  if ( v14 + 4 > m_nAllocationCount )
    CUtlMemory<char,int>::Grow(this: &this->m_GameLumpData.m_Memory, num: v14 - m_nAllocationCount + 4);
  this->m_GameLumpData.m_Size += 4;
  v16 = p_m_GameLumpData->m_Memory.m_pMemory;
  v17 = this->m_GameLumpData.m_Size - v14 - 4;
  this->m_GameLumpData.m_pElements = this->m_GameLumpData.m_Memory.m_pMemory;
  if ( v17 > 0 )
    _V_memmove(dest: &v16[v14 + 4], src: &v16[v14], count: v17);
  v18 = &p_m_GameLumpData->m_Memory.m_pMemory[v14];
  if ( v18 != nullptr )
    *v18 = 2;
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v14] != (unsigned __int8 *)-1 )
    p_m_GameLumpData->m_Memory.m_pMemory[v14 + 1] = 0;
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v14] != (unsigned __int8 *)-2 )
    p_m_GameLumpData->m_Memory.m_pMemory[v14 + 2] = 0;
  v19 = &p_m_GameLumpData->m_Memory.m_pMemory[v14 + 3];
  if ( v19 != nullptr )
    *v19 = 0;
  m_Put = this->m_pSerialBuffer->m_Put;
  v21 = this->m_GameLumpData.m_Size;
  v22 = v21 + m_Put + 32;
  v23 = p_m_GameLumpData->m_Memory.m_nAllocationCount;
  staticPropLumpHeader.id = 1936749168;
  *(_DWORD *)&staticPropLumpHeader.flags = 589824;
  staticPropLumpHeader.fileofs = v22;
  staticPropLumpHeader.filelen = nCount;
  if ( v21 + 16 > v23 )
    CUtlMemory<char,int>::Grow(this: &p_m_GameLumpData->m_Memory, num: v21 - v23 + 16);
  p_m_GameLumpData->m_Size += 16;
  v24 = p_m_GameLumpData->m_Memory.m_pMemory;
  v25 = p_m_GameLumpData->m_Size - v21 - 16;
  p_m_GameLumpData->m_pElements = p_m_GameLumpData->m_Memory.m_pMemory;
  if ( v25 > 0 )
    _V_memmove(dest: &v24[v21 + 16], src: &v24[v21], count: v25);
  for ( i = 0; i < 16; i += 4 )
  {
    v27 = &p_m_GameLumpData->m_Memory.m_pMemory[i + v21];
    if ( v27 != nullptr )
      *v27 = *((_BYTE *)&staticPropLumpHeader.id + i);
    if ( &p_m_GameLumpData->m_Memory.m_pMemory[i + v21] != (unsigned __int8 *)-1 )
      p_m_GameLumpData->m_Memory.m_pMemory[i + 1 + v21] = *((_BYTE *)&staticPropLumpHeader.id + i + 1);
    if ( &p_m_GameLumpData->m_Memory.m_pMemory[i + v21] != (unsigned __int8 *)-2 )
      p_m_GameLumpData->m_Memory.m_pMemory[i + 2 + v21] = *((_BYTE *)&staticPropLumpHeader.id + i + 2);
    if ( &p_m_GameLumpData->m_Memory.m_pMemory[i + v21] != (unsigned __int8 *)-3 )
      p_m_GameLumpData->m_Memory.m_pMemory[i + 3 + v21] = *((_BYTE *)&staticPropLumpHeader.id + i + 3);
  }
  v28 = p_m_GameLumpData->m_Size;
  v29 = p_m_GameLumpData->m_Memory.m_nAllocationCount;
  staticPropLumpHeader.id = 1685090928;
  *(_DWORD *)&staticPropLumpHeader.flags = 0x40000;
  staticPropLumpHeader.fileofs = nCount + v22;
  staticPropLumpHeader.filelen = 12;
  if ( v28 + 16 > v29 )
    CUtlMemory<char,int>::Grow(this: &p_m_GameLumpData->m_Memory, num: v28 - v29 + 16);
  p_m_GameLumpData->m_Size += 16;
  v30 = p_m_GameLumpData->m_Memory.m_pMemory;
  v31 = p_m_GameLumpData->m_Size - v28 - 16;
  p_m_GameLumpData->m_pElements = p_m_GameLumpData->m_Memory.m_pMemory;
  if ( v31 > 0 )
    _V_memmove(dest: &v30[v28 + 16], src: &v30[v28], count: v31);
  for ( j = 0; j < 16; j += 4 )
  {
    v33 = &p_m_GameLumpData->m_Memory.m_pMemory[j + v28];
    if ( v33 != nullptr )
      *v33 = *((_BYTE *)&staticPropLumpHeader.id + j);
    if ( &p_m_GameLumpData->m_Memory.m_pMemory[j + v28] != (unsigned __int8 *)-1 )
      p_m_GameLumpData->m_Memory.m_pMemory[j + 1 + v28] = *((_BYTE *)&staticPropLumpHeader.id + j + 1);
    if ( &p_m_GameLumpData->m_Memory.m_pMemory[j + v28] != (unsigned __int8 *)-2 )
      p_m_GameLumpData->m_Memory.m_pMemory[j + 2 + v28] = *((_BYTE *)&staticPropLumpHeader.id + j + 2);
    if ( &p_m_GameLumpData->m_Memory.m_pMemory[j + v28] != (unsigned __int8 *)-3 )
      p_m_GameLumpData->m_Memory.m_pMemory[j + 3 + v28] = *((_BYTE *)&staticPropLumpHeader.id + j + 3);
  }
  v34 = p_m_GameLumpData->m_Size;
  v35 = p_m_GameLumpData->m_Memory.m_nAllocationCount;
  if ( v34 + 4 > v35 )
    CUtlMemory<char,int>::Grow(this: &p_m_GameLumpData->m_Memory, num: v34 - v35 + 4);
  p_m_GameLumpData->m_Size += 4;
  v36 = p_m_GameLumpData->m_Memory.m_pMemory;
  v37 = p_m_GameLumpData->m_Size - v34 - 4;
  p_m_GameLumpData->m_pElements = p_m_GameLumpData->m_Memory.m_pMemory;
  if ( v37 > 0 )
    _V_memmove(dest: &v36[v34 + 4], src: &v36[v34], count: v37);
  v38 = &p_m_GameLumpData->m_Memory.m_pMemory[v34];
  if ( v38 != nullptr )
    *v38 = staticPropDictionaryLump.m_Size;
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v34] != (unsigned __int8 *)-1 )
    p_m_GameLumpData->m_Memory.m_pMemory[v34 + 1] = BYTE1(staticPropDictionaryLump.m_Size);
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v34] != (unsigned __int8 *)-2 )
    p_m_GameLumpData->m_Memory.m_pMemory[v34 + 2] = BYTE2(staticPropDictionaryLump.m_Size);
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v34] != (unsigned __int8 *)-3 )
    p_m_GameLumpData->m_Memory.m_pMemory[v34 + 3] = HIBYTE(staticPropDictionaryLump.m_Size);
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::InsertMultipleBefore(
    this: p_m_GameLumpData,
    elem: p_m_GameLumpData->m_Size,
    num: nDictionarySize,
    pToInsert: (const unsigned __int8 *)staticPropDictionaryLump.m_Memory.m_pMemory);
  v39 = p_m_GameLumpData->m_Size;
  v40 = p_m_GameLumpData->m_Memory.m_nAllocationCount;
  v41 = staticPropLeafLump.m_Size;
  nCount = staticPropLeafLump.m_Size;
  if ( v39 + 4 > v40 )
    CUtlMemory<char,int>::Grow(this: &p_m_GameLumpData->m_Memory, num: v39 - v40 + 4);
  p_m_GameLumpData->m_Size += 4;
  v42 = p_m_GameLumpData->m_Memory.m_pMemory;
  v43 = p_m_GameLumpData->m_Size - v39 - 4;
  p_m_GameLumpData->m_pElements = p_m_GameLumpData->m_Memory.m_pMemory;
  if ( v43 > 0 )
    _V_memmove(dest: &v42[v39 + 4], src: &v42[v39], count: v43);
  v44 = &p_m_GameLumpData->m_Memory.m_pMemory[v39];
  if ( v44 != nullptr )
    *v44 = v41;
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v39] != (unsigned __int8 *)-1 )
    p_m_GameLumpData->m_Memory.m_pMemory[v39 + 1] = HIBYTE(v41);
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v39] != (unsigned __int8 *)-2 )
    p_m_GameLumpData->m_Memory.m_pMemory[v39 + 2] = BYTE2(nCount);
  v45 = &p_m_GameLumpData->m_Memory.m_pMemory[v39 + 3];
  if ( v45 != nullptr )
    *v45 = HIBYTE(nCount);
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::InsertMultipleBefore(
    this: p_m_GameLumpData,
    elem: p_m_GameLumpData->m_Size,
    num: nLeafSize,
    pToInsert: (const unsigned __int8 *)staticPropLeafLump.m_Memory.m_pMemory);
  v46 = p_m_GameLumpData->m_Size;
  v47 = p_m_GameLumpData->m_Memory.m_nAllocationCount;
  if ( v46 + 4 > v47 )
    CUtlMemory<char,int>::Grow(this: &p_m_GameLumpData->m_Memory, num: v46 - v47 + 4);
  p_m_GameLumpData->m_Size += 4;
  v48 = p_m_GameLumpData->m_Memory.m_pMemory;
  v49 = p_m_GameLumpData->m_Size - v46 - 4;
  p_m_GameLumpData->m_pElements = p_m_GameLumpData->m_Memory.m_pMemory;
  if ( v49 > 0 )
    _V_memmove(dest: &v48[v46 + 4], src: &v48[v46], count: v49);
  v50 = &p_m_GameLumpData->m_Memory.m_pMemory[v46];
  if ( v50 != nullptr )
    *v50 = staticPropLump.m_Size;
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v46] != (unsigned __int8 *)-1 )
    p_m_GameLumpData->m_Memory.m_pMemory[v46 + 1] = BYTE1(staticPropLump.m_Size);
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v46] != (unsigned __int8 *)-2 )
    p_m_GameLumpData->m_Memory.m_pMemory[v46 + 2] = BYTE2(staticPropLump.m_Size);
  v51 = &p_m_GameLumpData->m_Memory.m_pMemory[v46 + 3];
  if ( v51 != nullptr )
    *v51 = HIBYTE(staticPropLump.m_Size);
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::InsertMultipleBefore(
    this: p_m_GameLumpData,
    elem: p_m_GameLumpData->m_Size,
    num: nPropSize,
    pToInsert: (const unsigned __int8 *)staticPropLump.m_Memory.m_pMemory);
  v52 = p_m_GameLumpData->m_Size;
  v53 = p_m_GameLumpData->m_Memory.m_nAllocationCount;
  if ( v52 + 4 > v53 )
    CUtlMemory<char,int>::Grow(this: &p_m_GameLumpData->m_Memory, num: v52 - v53 + 4);
  p_m_GameLumpData->m_Size += 4;
  v54 = p_m_GameLumpData->m_Memory.m_pMemory;
  v55 = p_m_GameLumpData->m_Size - v52 - 4;
  p_m_GameLumpData->m_pElements = p_m_GameLumpData->m_Memory.m_pMemory;
  if ( v55 > 0 )
    _V_memmove(dest: &v54[v52 + 4], src: &v54[v52], count: v55);
  v56 = &p_m_GameLumpData->m_Memory.m_pMemory[v52];
  if ( v56 != nullptr )
    *v56 = 0;
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v52] != (unsigned __int8 *)-1 )
    p_m_GameLumpData->m_Memory.m_pMemory[v52 + 1] = 0;
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v52] != (unsigned __int8 *)-2 )
    p_m_GameLumpData->m_Memory.m_pMemory[v52 + 2] = 0;
  v57 = &p_m_GameLumpData->m_Memory.m_pMemory[v52 + 3];
  if ( v57 != nullptr )
    *v57 = 0;
  v58 = p_m_GameLumpData->m_Size;
  v59 = p_m_GameLumpData->m_Memory.m_nAllocationCount;
  if ( v58 + 4 > v59 )
    CUtlMemory<char,int>::Grow(this: &p_m_GameLumpData->m_Memory, num: v58 - v59 + 4);
  p_m_GameLumpData->m_Size += 4;
  v60 = p_m_GameLumpData->m_Memory.m_pMemory;
  v61 = p_m_GameLumpData->m_Size - v58 - 4;
  p_m_GameLumpData->m_pElements = p_m_GameLumpData->m_Memory.m_pMemory;
  if ( v61 > 0 )
    _V_memmove(dest: &v60[v58 + 4], src: &v60[v58], count: v61);
  v62 = &p_m_GameLumpData->m_Memory.m_pMemory[v58];
  if ( v62 != nullptr )
    *v62 = 0;
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v58] != (unsigned __int8 *)-1 )
    p_m_GameLumpData->m_Memory.m_pMemory[v58 + 1] = 0;
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v58] != (unsigned __int8 *)-2 )
    p_m_GameLumpData->m_Memory.m_pMemory[v58 + 2] = 0;
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v58] != (unsigned __int8 *)-3 )
    p_m_GameLumpData->m_Memory.m_pMemory[v58 + 3] = 0;
  v63 = p_m_GameLumpData->m_Size;
  v64 = p_m_GameLumpData->m_Memory.m_nAllocationCount;
  if ( v63 + 4 > v64 )
    CUtlMemory<char,int>::Grow(this: &p_m_GameLumpData->m_Memory, num: v63 - v64 + 4);
  p_m_GameLumpData->m_Size += 4;
  v65 = p_m_GameLumpData->m_Memory.m_pMemory;
  v66 = p_m_GameLumpData->m_Size - v63 - 4;
  p_m_GameLumpData->m_pElements = p_m_GameLumpData->m_Memory.m_pMemory;
  if ( v66 > 0 )
    _V_memmove(dest: &v65[v63 + 4], src: &v65[v63], count: v66);
  v67 = &p_m_GameLumpData->m_Memory.m_pMemory[v63];
  if ( v67 != nullptr )
    *v67 = 0;
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v63] != (unsigned __int8 *)-1 )
    p_m_GameLumpData->m_Memory.m_pMemory[v63 + 1] = 0;
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v63] != (unsigned __int8 *)-2 )
    p_m_GameLumpData->m_Memory.m_pMemory[v63 + 2] = 0;
  if ( &p_m_GameLumpData->m_Memory.m_pMemory[v63] != (unsigned __int8 *)-3 )
    p_m_GameLumpData->m_Memory.m_pMemory[v63 + 3] = 0;
  if ( staticPropLump.m_Memory.m_nGrowSize >= 0 && staticPropLump.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: staticPropLump.m_Memory.m_pMemory);
  v68 = staticPropLeafLump.m_Memory.m_pMemory;
  staticPropLeafLump.m_Size = 0;
  if ( staticPropLeafLump.m_Memory.m_nGrowSize >= 0 )
  {
    if ( staticPropLeafLump.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: staticPropLeafLump.m_Memory.m_pMemory);
      v68 = nullptr;
      staticPropLeafLump.m_Memory.m_pMemory = nullptr;
    }
    staticPropLeafLump.m_Memory.m_nAllocationCount = 0;
  }
  staticPropLeafLump.m_pElements = v68;
  if ( staticPropLeafLump.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v68 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v68);
      staticPropLeafLump.m_Memory.m_pMemory = nullptr;
    }
    staticPropLeafLump.m_Memory.m_nAllocationCount = 0;
  }
  if ( staticPropDictionaryLump.m_Memory.m_nGrowSize >= 0 && staticPropDictionaryLump.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: staticPropDictionaryLump.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00419560
// Name: private: void CMemoryBSPFile::BuildDisplacementVirtualMesh(class IPhysicsCollision __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::BuildDisplacementVirtualMesh(
        CMemoryBSPFile *this,
        IPhysicsCollision *pPhysicsCollision)
{
  int v3; // ebx
  CCoreDispInfo *v4; // esi
  CCoreDispInfo_vtbl *v5; // eax
  struct CPhysCollide *(__thiscall *CreateVirtualMesh)(IPhysicsCollision *, const virtualmeshparams_t *); // edx
  struct CPhysCollide *v7; // eax
  Vector *m_pMemory; // eax
  unsigned __int16 *v9; // eax
  unsigned __int16 v10; // dx
  int m_nAllocationCount; // eax
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *p_m_PhysicsDisplacementData; // esi
  int v13; // edi
  unsigned __int8 *v14; // ecx
  int v15; // eax
  unsigned __int8 *v16; // eax
  unsigned __int8 *v17; // edi
  int v18; // ecx
  int v19; // eax
  bool v20; // zf
  int v21; // eax
  int v22; // edi
  int v23; // edx
  int v24; // ecx
  int v25; // edi
  int v26; // eax
  unsigned __int8 *v27; // ecx
  int v28; // eax
  unsigned __int8 *v29; // eax
  unsigned __int8 *v30; // edi
  int v31; // edi
  int v32; // eax
  int m_Size; // [esp-4h] [ebp-94h]
  CSimpleBSPTessellateHelper helper; // [esp+Ch] [ebp-84h] BYREF
  virtualmeshparams_t params; // [esp+28h] [ebp-68h] BYREF
  CSimpleBSPDisplacementMeshEvent meshHandler; // [esp+34h] [ebp-5Ch] BYREF
  int v37; // [esp+54h] [ebp-3Ch]
  int v38; // [esp+58h] [ebp-38h]
  CUtlVector<CPhysCollide *,CUtlMemory<CPhysCollide *,int> > virtualMeshes; // [esp+5Ch] [ebp-34h] BYREF
  int v40; // [esp+70h] [ebp-20h]
  int i; // [esp+74h] [ebp-1Ch]
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > indices; // [esp+78h] [ebp-18h] BYREF
  int nCollideSize; // [esp+8Ch] [ebp-4h]

  v3 = 0;
  m_Size = this->m_DisplacementHelperList.m_Size;
  memset(&virtualMeshes, 0, sizeof(virtualMeshes));
  CUtlVector<dedge_t,CUtlMemory<dedge_t,int>>::InsertMultipleBefore(this: &virtualMeshes, elem: 0, num: m_Size);
  if ( this->m_DisplacementHelperList.m_Size > 0 )
  {
    nCollideSize = 0;
    do
    {
      v4 = this->m_DisplacementHelperList.m_Memory.m_pMemory[v3];
      if ( (*((_BYTE *)&this->m_pMapFile->m_Displacements.m_Memory.m_pMemory->m_ContentsFlags + nCollideSize) & 1) != 0 )
      {
        memset(&indices, 0, sizeof(indices));
        v5 = v4->__vftable;
        helper.m_pIndices = &indices;
        helper.m_pActiveVerts = v4->m_AllowedVerts.m_Ints;
        helper.m_pPowerInfo = v5->GetPowerInfo(this: v4);
        helper.m_nIndices = 0;
        TesselateDisplacement_R<CSimpleBSPTessellateHelper>(
          pHelper: &helper,
          nodeIndex: &helper.m_pPowerInfo->m_RootNode,
          iNodeBitIndex: 0,
          iLevel: 0);
        CSimpleBSPDisplacementMeshEvent::CSimpleBSPDisplacementMeshEvent(
          this: &meshHandler,
          pIndices: indices.m_Memory.m_pMemory,
          nIndexCount: indices.m_Size,
          pDispInfo: v4);
        params.userData = &meshHandler;
        CreateVirtualMesh = pPhysicsCollision->CreateVirtualMesh;
        params.pMeshEventHandler = &meshHandler;
        params.buildOuterHull = true;
        v7 = CreateVirtualMesh(this: pPhysicsCollision, a2: &params);
        virtualMeshes.m_Memory.m_pMemory[v3] = v7;
        m_pMemory = meshHandler.m_Vertices.m_Memory.m_pMemory;
        meshHandler.m_Vertices.m_Size = 0;
        if ( meshHandler.m_Vertices.m_Memory.m_nGrowSize >= 0 )
        {
          if ( meshHandler.m_Vertices.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: meshHandler.m_Vertices.m_Memory.m_pMemory);
            m_pMemory = nullptr;
            meshHandler.m_Vertices.m_Memory.m_pMemory = nullptr;
          }
          meshHandler.m_Vertices.m_Memory.m_nAllocationCount = 0;
        }
        meshHandler.m_Vertices.m_pElements = m_pMemory;
        if ( meshHandler.m_Vertices.m_Memory.m_nGrowSize >= 0 )
        {
          if ( m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
            meshHandler.m_Vertices.m_Memory.m_pMemory = nullptr;
          }
          meshHandler.m_Vertices.m_Memory.m_nAllocationCount = 0;
        }
        v9 = indices.m_Memory.m_pMemory;
        indices.m_Size = 0;
        if ( indices.m_Memory.m_nGrowSize >= 0 )
        {
          if ( indices.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: indices.m_Memory.m_pMemory);
            v9 = nullptr;
            indices.m_Memory.m_pMemory = nullptr;
          }
          indices.m_Memory.m_nAllocationCount = 0;
        }
        indices.m_pElements = v9;
        if ( indices.m_Memory.m_nGrowSize >= 0 && v9 != nullptr )
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
      }
      else
      {
        virtualMeshes.m_Memory.m_pMemory[v3] = nullptr;
      }
      nCollideSize += 68;
      ++v3;
    }
    while ( v3 < this->m_DisplacementHelperList.m_Size );
    v3 = 0;
  }
  v10 = this->m_DisplacementHelperList.m_Size;
  m_nAllocationCount = this->m_PhysicsDisplacementData.m_Memory.m_nAllocationCount;
  p_m_PhysicsDisplacementData = &this->m_PhysicsDisplacementData;
  v13 = this->m_PhysicsDisplacementData.m_Size;
  memset(&indices, 0, sizeof(indices));
  LOWORD(nCollideSize) = v10;
  if ( v13 + 2 > m_nAllocationCount )
  {
    CUtlMemory<char,int>::Grow(this: &p_m_PhysicsDisplacementData->m_Memory, num: v13 - m_nAllocationCount + 2);
    v10 = nCollideSize;
  }
  p_m_PhysicsDisplacementData->m_Size += 2;
  v14 = p_m_PhysicsDisplacementData->m_Memory.m_pMemory;
  v15 = p_m_PhysicsDisplacementData->m_Size - v13 - 2;
  p_m_PhysicsDisplacementData->m_pElements = p_m_PhysicsDisplacementData->m_Memory.m_pMemory;
  if ( v15 > 0 )
  {
    _V_memmove(dest: &v14[v13 + 2], src: &v14[v13], count: v15);
    v10 = nCollideSize;
  }
  v16 = &p_m_PhysicsDisplacementData->m_Memory.m_pMemory[v13];
  if ( v16 != nullptr )
    *v16 = v10;
  v17 = &p_m_PhysicsDisplacementData->m_Memory.m_pMemory[v13 + 1];
  if ( v17 != nullptr )
    *v17 = HIBYTE(v10);
  v18 = v10;
  v19 = 0;
  i = 0;
  v40 = v10;
  if ( v10 != 0 )
  {
    while ( 1 )
    {
      v20 = virtualMeshes.m_Memory.m_pMemory[v19] == nullptr;
      nCollideSize = -1;
      if ( !v20 )
      {
        v21 = pPhysicsCollision->CollideSize(this: pPhysicsCollision, a2: virtualMeshes.m_Memory.m_pMemory[v19]);
        nCollideSize = v21;
        if ( v3 < v21 )
        {
          v22 = v21 - v3;
          v23 = v3;
          v37 = v3;
          if ( v21 != v3 )
          {
            v24 = v21;
            v38 = v21;
            if ( v21 > indices.m_Memory.m_nAllocationCount )
            {
              CUtlMemory<char,int>::Grow(
                this: (CUtlMemory<unsigned char,int> *)&indices,
                num: v21 - indices.m_Memory.m_nAllocationCount);
              v3 = indices.m_Size;
              v23 = v37;
              v24 = v38;
            }
            v3 += v22;
            indices.m_pElements = indices.m_Memory.m_pMemory;
            indices.m_Size = v3;
            if ( v3 - v23 - v22 > 0 && v22 > 0 )
              _V_memmove(
                dest: (char *)indices.m_Memory.m_pMemory + v24,
                src: (char *)indices.m_Memory.m_pMemory + v23,
                count: v3 - v23 - v22);
          }
        }
      }
      v25 = p_m_PhysicsDisplacementData->m_Size;
      v26 = p_m_PhysicsDisplacementData->m_Memory.m_nAllocationCount;
      if ( v25 + 2 > v26 )
        CUtlMemory<char,int>::Grow(this: &p_m_PhysicsDisplacementData->m_Memory, num: v25 - v26 + 2);
      p_m_PhysicsDisplacementData->m_Size += 2;
      v27 = p_m_PhysicsDisplacementData->m_Memory.m_pMemory;
      v28 = p_m_PhysicsDisplacementData->m_Size - v25 - 2;
      p_m_PhysicsDisplacementData->m_pElements = p_m_PhysicsDisplacementData->m_Memory.m_pMemory;
      if ( v28 > 0 )
        _V_memmove(dest: &v27[v25 + 2], src: &v27[v25], count: v28);
      v29 = &p_m_PhysicsDisplacementData->m_Memory.m_pMemory[v25];
      if ( v29 != nullptr )
        *v29 = nCollideSize;
      v30 = &p_m_PhysicsDisplacementData->m_Memory.m_pMemory[v25 + 1];
      if ( v30 != nullptr )
        *v30 = BYTE1(nCollideSize);
      v18 = v40;
      if ( ++i >= v40 )
        break;
      v19 = i;
    }
  }
  v31 = 0;
  if ( v18 > 0 )
  {
    do
    {
      if ( virtualMeshes.m_Memory.m_pMemory[v31] != nullptr )
      {
        v32 = pPhysicsCollision->CollideWrite(
                this: pPhysicsCollision,
                a2: (char *)indices.m_Memory.m_pMemory,
                a3: virtualMeshes.m_Memory.m_pMemory[v31],
                a4: false);
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::InsertMultipleBefore(
          this: p_m_PhysicsDisplacementData,
          elem: p_m_PhysicsDisplacementData->m_Size,
          num: v32,
          pToInsert: (const unsigned __int8 *)indices.m_Memory.m_pMemory);
      }
      ++v31;
    }
    while ( v31 < v40 );
  }
  if ( indices.m_Memory.m_nGrowSize >= 0 && indices.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: indices.m_Memory.m_pMemory);
  if ( virtualMeshes.m_Memory.m_nGrowSize >= 0 && virtualMeshes.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: virtualMeshes.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00419900
// Name: private: void CMemoryBSPFile::BuildPhysicsCollisionData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::BuildPhysicsCollisionData(CMemoryBSPFile *this)
{
  void *(__cdecl *PhysicsFactory)(const char *, int *); // eax
  void *(__cdecl *v2)(const char *, int *); // edi
  IPhysicsSurfaceProps *v3; // eax
  IPhysicsSurfaceProps *v4; // edi
  IBaseFileSystem *v5; // eax
  CMemoryBSPFile *v6; // ebx
  int v7; // ecx
  int *p_m_nGrowSize; // eax
  int v9; // esi
  BSPCluster_t *m_pMemory; // edi
  int v11; // ebx
  _DWORD *p_m_pLeafNode; // ebx
  int v13; // ebx
  _DWORD *v14; // ebx
  int v15; // ebx
  _DWORD *v16; // ebx
  int v17; // ebx
  _DWORD *v18; // ebx
  int v19; // ebx
  int v20; // eax
  BSPCluster_t **v21; // esi
  BSPCluster_t *v22; // edi
  int v23; // eax
  CPhysCollisionEntrySolid **v24; // ebx
  int v25; // ecx
  CTextBuffer *v26; // eax
  int v27; // esi
  CPhysCollisionEntry **v28; // edi
  unsigned int CollisionBinarySize; // eax
  int *v30; // edi
  int v31; // esi
  CTextBuffer *v32; // esi
  int v33; // eax
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *p_m_PhysicsCollideData; // esi
  unsigned __int8 *v35; // edx
  unsigned __int8 *v36; // eax
  CMemoryBSPFile *v37; // edx
  int v38; // ebx
  int v39; // eax
  IPhysicsSurfaceProps *v40; // ebx
  CPhysCollisionEntry **v41; // edi
  unsigned int v42; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  unsigned __int8 *v45; // ecx
  int v46; // eax
  int i; // eax
  unsigned __int8 *v48; // ecx
  CPhysCollisionEntry **v49; // edi
  IPhysicsCollision *v50; // ebx
  unsigned int v51; // eax
  int v52; // edi
  int v53; // ebx
  int v54; // eax
  unsigned __int8 *v55; // ecx
  int v56; // eax
  unsigned __int8 *v57; // eax
  unsigned __int8 *v58; // edi
  int v59; // edi
  int v60; // ebx
  int v61; // edi
  CPhysCollisionEntry **v62; // edi
  bool v63; // zf
  CTextBuffer *v64; // edi
  bool v65; // sf
  unsigned __int8 *v66; // eax
  int v67; // edi
  int v68; // eax
  unsigned __int8 *v69; // ecx
  int v70; // eax
  int j; // eax
  unsigned __int8 *v72; // ecx
  char *v73; // esi
  int k; // edi
  void *v75; // eax
  const char *v76; // [esp-8h] [ebp-8074h]
  int dst[2048]; // [esp+Ch] [ebp-8060h] BYREF
  CTextBuffer *v78[1024]; // [esp+200Ch] [ebp-6060h] BYREF
  CUtlMemory<BSPCluster_t,int> v79; // [esp+300Ch] [ebp-5060h] BYREF
  int v80; // [esp+3018h] [ebp-5054h]
  BSPCluster_t *v81; // [esp+301Ch] [ebp-5050h]
  char v82; // [esp+800Ch] [ebp-60h] BYREF
  CUtlVector<int,CUtlMemory<int,int> > pWorldPropertyRemapList; // [esp+8010h] [ebp-5Ch] BYREF
  int v84; // [esp+8024h] [ebp-48h]
  CUtlMemory<unsigned char,int> v85; // [esp+8028h] [ebp-44h] BYREF
  int v86; // [esp+8034h] [ebp-38h]
  unsigned __int8 *v87; // [esp+8038h] [ebp-34h]
  int v88; // [esp+803Ch] [ebp-30h]
  int v89; // [esp+8040h] [ebp-2Ch]
  int v90; // [esp+8044h] [ebp-28h]
  IPhysicsSurfaceProps *v91; // [esp+8048h] [ebp-24h]
  IPhysicsSurfaceProps *pPhysicsProperties; // [esp+804Ch] [ebp-20h]
  int num; // [esp+8050h] [ebp-1Ch]
  CPhysCollisionEntrySolid *PhysicsModel; // [esp+8054h] [ebp-18h]
  IPhysicsCollision *pPhysicsCollision; // [esp+8058h] [ebp-14h]
  CUtlMemory<BSPCluster_t,int> *v96; // [esp+805Ch] [ebp-10h]
  int v97; // [esp+8060h] [ebp-Ch]
  CMemoryBSPFile *v98; // [esp+8064h] [ebp-8h]
  CTextBuffer *v99; // [esp+8068h] [ebp-4h]

  v98 = this;
  PhysicsFactory = GetPhysicsFactory();
  v2 = PhysicsFactory;
  if ( PhysicsFactory != nullptr
    && (pPhysicsCollision = (IPhysicsCollision *)PhysicsFactory(a1: "VPhysicsCollision007", a2: nullptr),
        v3 = (IPhysicsSurfaceProps *)v2(a1: "VPhysicsSurfaceProps001", a2: nullptr),
        v4 = v3,
        pPhysicsProperties = v3,
        pPhysicsCollision != nullptr)
    && v3 != nullptr )
  {
    memset((unsigned __int8 *)dst, value: 0xFFu, count: sizeof(dst));
    if ( g_pFullFileSystem != nullptr )
      v5 = &g_pFullFileSystem->IBaseFileSystem;
    else
      v5 = nullptr;
    v6 = v98;
    LoadSurfaceProperties(pFileSystem: v5, pPhysicsProperties: v4, pMapFile: v98->m_pMapFile, pSurfacePropertyList: dst);
    v7 = 1023;
    p_m_nGrowSize = &v79.m_nGrowSize;
    do
    {
      *(p_m_nGrowSize - 2) = 0;
      *(p_m_nGrowSize - 1) = 0;
      *p_m_nGrowSize = 0;
      p_m_nGrowSize[1] = 0;
      p_m_nGrowSize[2] = 0;
      p_m_nGrowSize += 5;
      --v7;
    }
    while ( v7 >= 0 );
    num = 0;
    v96 = nullptr;
    memset(&pWorldPropertyRemapList, 0, sizeof(pWorldPropertyRemapList));
    v97 = 0;
    if ( v6->m_ModelList.m_Size > 0 )
    {
      v9 = v80;
      m_pMemory = v79.m_pMemory;
      do
      {
        if ( v97 != 0 )
        {
          PhysicsModel = CMemoryBSPFile::CreatePhysicsModel(
                           this: v98,
                           a2: (int)v6,
                           a3: (int)m_pMemory,
                           a4: v9,
                           pPhysicsCollision,
                           pPhysicsProperties,
                           pSurfacePropertyList: dst,
                           pModel: &v98->m_ModelList.m_Memory.m_pMemory[v97]);
          if ( PhysicsModel != nullptr )
          {
            v19 = *(&v80 + 5 * v97);
            v20 = *(&v79.m_nAllocationCount + 5 * v97);
            v21 = &(&v79.m_pMemory)[5 * v97];
            if ( v19 + 1 > v20 )
              CUtlMemory<ColorRGBExp32,int>::Grow(
                this: (CUtlMemory<BSPCluster_t,int> *)((char *)&v79 + 20 * v97),
                num: v19 - v20 + 1);
            v21[3] = (BSPCluster_t *)((char *)v21[3] + 1);
            v22 = *v21;
            v23 = (int)v21[3] - v19 - 1;
            v21[4] = *v21;
            if ( v23 > 0 )
              _V_memmove(dest: &v22[v19 + 1], src: &v22[v19], count: 4 * v23);
            v9 = v80;
            v24 = (CPhysCollisionEntrySolid **)&v22[v19];
            m_pMemory = v79.m_pMemory;
            if ( v24 != nullptr )
              *v24 = PhysicsModel;
          }
        }
        else
        {
          v99 = (CTextBuffer *)CMemoryBSPFile::CreateWorldPhysicsModels(
                                 this: v98,
                                 a2: v9,
                                 pPhysicsCollision,
                                 &pWorldPropertyRemapList,
                                 pSurfacePropertyList: dst,
                                 pModel: v98->m_ModelList.m_Memory.m_pMemory,
                                 contentsMask: 33570819);
          if ( v99 != nullptr )
          {
            v11 = v9;
            if ( v9 + 1 > v79.m_nAllocationCount )
            {
              CUtlMemory<ColorRGBExp32,int>::Grow(this: &v79, num: v9 - v79.m_nAllocationCount + 1);
              v9 = v80;
              m_pMemory = v79.m_pMemory;
            }
            v80 = ++v9;
            v81 = m_pMemory;
            if ( v9 - v11 - 1 > 0 )
              _V_memmove(dest: &m_pMemory[v11 + 1], src: &m_pMemory[v11], count: 4 * (v9 - v11 - 1));
            p_m_pLeafNode = &m_pMemory[v11].m_pLeafNode;
            if ( p_m_pLeafNode != nullptr )
              *p_m_pLeafNode = v99;
          }
          v99 = (CTextBuffer *)CMemoryBSPFile::CreateWorldPhysicsModels(
                                 this: v98,
                                 a2: v9,
                                 pPhysicsCollision,
                                 &pWorldPropertyRemapList,
                                 pSurfacePropertyList: dst,
                                 pModel: v98->m_ModelList.m_Memory.m_pMemory,
                                 contentsMask: 8);
          if ( v99 != nullptr )
          {
            v13 = v9;
            if ( v9 + 1 > v79.m_nAllocationCount )
            {
              CUtlMemory<ColorRGBExp32,int>::Grow(this: &v79, num: v9 - v79.m_nAllocationCount + 1);
              v9 = v80;
              m_pMemory = v79.m_pMemory;
            }
            v80 = ++v9;
            v81 = m_pMemory;
            if ( v9 - v13 - 1 > 0 )
              _V_memmove(dest: &m_pMemory[v13 + 1], src: &m_pMemory[v13], count: 4 * (v9 - v13 - 1));
            v14 = &m_pMemory[v13].m_pLeafNode;
            if ( v14 != nullptr )
              *v14 = v99;
          }
          v99 = (CTextBuffer *)CMemoryBSPFile::CreateWorldPhysicsModels(
                                 this: v98,
                                 a2: v9,
                                 pPhysicsCollision,
                                 &pWorldPropertyRemapList,
                                 pSurfacePropertyList: dst,
                                 pModel: v98->m_ModelList.m_Memory.m_pMemory,
                                 contentsMask: 0x10000);
          if ( v99 != nullptr )
          {
            v15 = v9;
            if ( v9 + 1 > v79.m_nAllocationCount )
            {
              CUtlMemory<ColorRGBExp32,int>::Grow(this: &v79, num: v9 - v79.m_nAllocationCount + 1);
              v9 = v80;
              m_pMemory = v79.m_pMemory;
            }
            v80 = ++v9;
            v81 = m_pMemory;
            if ( v9 - v15 - 1 > 0 )
              _V_memmove(dest: &m_pMemory[v15 + 1], src: &m_pMemory[v15], count: 4 * (v9 - v15 - 1));
            v16 = &m_pMemory[v15].m_pLeafNode;
            if ( v16 != nullptr )
              *v16 = v99;
          }
          v99 = (CTextBuffer *)CMemoryBSPFile::CreateWorldPhysicsModels(
                                 this: v98,
                                 a2: v9,
                                 pPhysicsCollision,
                                 &pWorldPropertyRemapList,
                                 pSurfacePropertyList: dst,
                                 pModel: v98->m_ModelList.m_Memory.m_pMemory,
                                 contentsMask: 0x20000);
          if ( v99 != nullptr )
          {
            v17 = v9;
            if ( v9 + 1 > v79.m_nAllocationCount )
            {
              CUtlMemory<ColorRGBExp32,int>::Grow(this: &v79, num: v9 - v79.m_nAllocationCount + 1);
              v9 = v80;
              m_pMemory = v79.m_pMemory;
            }
            v80 = ++v9;
            v81 = m_pMemory;
            if ( v9 - v17 - 1 > 0 )
              _V_memmove(dest: &m_pMemory[v17 + 1], src: &m_pMemory[v17], count: 4 * (v9 - v17 - 1));
            v18 = &m_pMemory[v17].m_pLeafNode;
            if ( v18 != nullptr )
              *v18 = v99;
          }
          CMemoryBSPFile::BuildDisplacementVirtualMesh(this: v98, pPhysicsCollision);
        }
        v25 = v97;
        PhysicsModel = (CPhysCollisionEntrySolid *)&v78[v97];
        PhysicsModel->__vftable = nullptr;
        v6 = (CMemoryBSPFile *)*(&v80 + 5 * v25);
        v84 = 20 * v25;
        if ( v6 != nullptr )
        {
          v26 = (CTextBuffer *)operator new(nSize: 0x14u);
          v27 = 0;
          if ( v26 != nullptr )
          {
            v26->m_Buffer.m_Memory.m_pMemory = nullptr;
            v26->m_Buffer.m_Memory.m_nAllocationCount = 0;
            v26->m_Buffer.m_Memory.m_nGrowSize = 0;
            v26->m_Buffer.m_Size = 0;
            v26->m_Buffer.m_pElements = nullptr;
          }
          else
          {
            v26 = nullptr;
          }
          v99 = v26;
          PhysicsModel->__vftable = (CPhysCollisionEntrySolid_vtbl *)v26;
          if ( (int)v6 > 0 )
          {
            v28 = *(CPhysCollisionEntry ***)((char *)&v79.m_pMemory + v84);
            do
            {
              (*v28)->WriteToTextBuffer(this: *v28, a2: v99, a3: v27);
              CollisionBinarySize = CPhysCollisionEntry::GetCollisionBinarySize(this: *v28, pPhysicsCollision);
              ++v27;
              ++v28;
              v96 = (CUtlMemory<BSPCluster_t,int> *)((char *)v96 + CollisionBinarySize + 4);
            }
            while ( v27 < (int)v6 );
          }
          if ( v97 == 0 )
          {
            v6 = (CMemoryBSPFile *)v78[0];
            CTextBuffer::WriteText(this: v78[0], pText: "virtualterrain {}\n");
            if ( pWorldPropertyRemapList.m_Size > 0 )
            {
              CTextBuffer::WriteText(this: (CTextBuffer *)v6, pText: "materialtable {\n");
              v30 = pWorldPropertyRemapList.m_Memory.m_pMemory;
              v31 = 1;
              PhysicsModel = (CPhysCollisionEntrySolid *)pWorldPropertyRemapList.m_Size;
              do
              {
                if ( *v30 >= 0 )
                {
                  v76 = pPhysicsProperties->GetPropName(this: pPhysicsProperties, a2: *v30);
                  CTextBuffer::WriteIntKey(this: (CTextBuffer *)v6, pKeyName: v76, nOutputData: v31);
                }
                else
                {
                  CTextBuffer::WriteIntKey(this: (CTextBuffer *)v6, pKeyName: "default", nOutputData: v31);
                }
                ++v30;
                ++v31;
                PhysicsModel = (CPhysCollisionEntrySolid *)((char *)PhysicsModel - 1);
              }
              while ( PhysicsModel != nullptr );
              CTextBuffer::WriteText(this: (CTextBuffer *)v6, pText: "}\n");
            }
          }
          v32 = v99;
          CTextBuffer::Terminate(this: v99);
          v96 = (CUtlMemory<BSPCluster_t,int> *)((char *)v96 + v32->m_Buffer.m_Size);
          ++num;
          m_pMemory = v79.m_pMemory;
          v9 = v80;
          v25 = v97;
        }
        v97 = v25 + 1;
      }
      while ( v25 + 1 < v98->m_ModelList.m_Size );
    }
    v33 = (int)(&v96[1].m_nAllocationCount + 4 * num);
    p_m_PhysicsCollideData = &v98->m_PhysicsCollideData;
    memset(&v85, 0, sizeof(v85));
    v86 = 0;
    v87 = nullptr;
    if ( v98->m_PhysicsCollideData.m_Memory.m_nAllocationCount < v33
      && v98->m_PhysicsCollideData.m_Memory.m_nGrowSize >= 0 )
    {
      v35 = p_m_PhysicsCollideData->m_Memory.m_pMemory;
      v98->m_PhysicsCollideData.m_Memory.m_nAllocationCount = v33;
      if ( v35 != nullptr )
        v36 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: v35, a3: v33);
      else
        v36 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v33);
      p_m_PhysicsCollideData->m_Memory.m_pMemory = v36;
    }
    v37 = v98;
    v38 = 0;
    p_m_PhysicsCollideData->m_pElements = p_m_PhysicsCollideData->m_Memory.m_pMemory;
    v97 = 0;
    if ( v37->m_ModelList.m_Size > 0 )
    {
      v96 = &v79;
      do
      {
        if ( v78[v38] != nullptr )
        {
          v39 = (int)v96[1].m_pMemory;
          v88 = v38;
          v91 = (IPhysicsSurfaceProps *)v39;
          v89 = 4 * v39;
          if ( v39 > 0 )
          {
            v40 = v91;
            v41 = (CPhysCollisionEntry **)v96->m_pMemory;
            do
            {
              v42 = CPhysCollisionEntry::GetCollisionBinarySize(this: *v41, pPhysicsCollision);
              v89 += v42;
              ++v41;
              v40 = (IPhysicsSurfaceProps *)((char *)v40 - 1);
            }
            while ( v40 != nullptr );
            v38 = v97;
          }
          m_Size = p_m_PhysicsCollideData->m_Size;
          m_nAllocationCount = p_m_PhysicsCollideData->m_Memory.m_nAllocationCount;
          v90 = v78[v38]->m_Buffer.m_Size;
          if ( m_Size + 16 > m_nAllocationCount )
            CUtlMemory<char,int>::Grow(this: &p_m_PhysicsCollideData->m_Memory, num: m_Size - m_nAllocationCount + 16);
          p_m_PhysicsCollideData->m_Size += 16;
          v45 = p_m_PhysicsCollideData->m_Memory.m_pMemory;
          v46 = p_m_PhysicsCollideData->m_Size - m_Size - 16;
          p_m_PhysicsCollideData->m_pElements = p_m_PhysicsCollideData->m_Memory.m_pMemory;
          if ( v46 > 0 )
            _V_memmove(dest: &v45[m_Size + 16], src: &v45[m_Size], count: v46);
          for ( i = 0; i < 16; i += 4 )
          {
            v48 = &p_m_PhysicsCollideData->m_Memory.m_pMemory[i + m_Size];
            if ( v48 != nullptr )
              *v48 = *((_BYTE *)&v88 + i);
            if ( &p_m_PhysicsCollideData->m_Memory.m_pMemory[i + m_Size] != (unsigned __int8 *)-1 )
              p_m_PhysicsCollideData->m_Memory.m_pMemory[i + 1 + m_Size] = *((_BYTE *)&v88 + i + 1);
            if ( &p_m_PhysicsCollideData->m_Memory.m_pMemory[i + m_Size] != (unsigned __int8 *)-2 )
              p_m_PhysicsCollideData->m_Memory.m_pMemory[i + 2 + m_Size] = *((_BYTE *)&v88 + i + 2);
            if ( &p_m_PhysicsCollideData->m_Memory.m_pMemory[i + m_Size] != (unsigned __int8 *)-3 )
              p_m_PhysicsCollideData->m_Memory.m_pMemory[i + 3 + m_Size] = *((_BYTE *)&v88 + i + 3);
          }
          if ( (int)v91 > 0 )
          {
            v49 = (CPhysCollisionEntry **)v96->m_pMemory;
            v50 = pPhysicsCollision;
            PhysicsModel = (CPhysCollisionEntrySolid *)v96->m_pMemory;
            pPhysicsProperties = v91;
            do
            {
              v51 = CPhysCollisionEntry::GetCollisionBinarySize(this: *v49, pPhysicsCollision: v50);
              v52 = p_m_PhysicsCollideData->m_Size;
              v53 = v51;
              v54 = p_m_PhysicsCollideData->m_Memory.m_nAllocationCount;
              num = v53;
              if ( v52 + 4 > v54 )
                CUtlMemory<char,int>::Grow(this: &p_m_PhysicsCollideData->m_Memory, num: v52 - v54 + 4);
              p_m_PhysicsCollideData->m_Size += 4;
              v55 = p_m_PhysicsCollideData->m_Memory.m_pMemory;
              v56 = p_m_PhysicsCollideData->m_Size - v52 - 4;
              p_m_PhysicsCollideData->m_pElements = p_m_PhysicsCollideData->m_Memory.m_pMemory;
              if ( v56 > 0 )
                _V_memmove(dest: &v55[v52 + 4], src: &v55[v52], count: v56);
              v57 = &p_m_PhysicsCollideData->m_Memory.m_pMemory[v52];
              if ( v57 != nullptr )
                *v57 = v53;
              if ( &p_m_PhysicsCollideData->m_Memory.m_pMemory[v52] != (unsigned __int8 *)-1 )
                p_m_PhysicsCollideData->m_Memory.m_pMemory[v52 + 1] = BYTE1(v53);
              if ( &p_m_PhysicsCollideData->m_Memory.m_pMemory[v52] != (unsigned __int8 *)-2 )
                p_m_PhysicsCollideData->m_Memory.m_pMemory[v52 + 2] = BYTE2(num);
              v58 = &p_m_PhysicsCollideData->m_Memory.m_pMemory[v52 + 3];
              if ( v58 != nullptr )
                *v58 = HIBYTE(num);
              if ( v86 < v53 )
              {
                v59 = v53;
                v60 = v86;
                v61 = v59 - v86;
                if ( v61 != 0 )
                {
                  v84 = v61 + v86;
                  if ( v61 + v86 > v85.m_nAllocationCount )
                    CUtlMemory<char,int>::Grow(this: &v85, num: v61 + v86 - v85.m_nAllocationCount);
                  v86 += v61;
                  v87 = v85.m_pMemory;
                  if ( v86 - v60 - v61 > 0 && v61 > 0 )
                    _V_memmove(dest: &v85.m_pMemory[v84], src: &v85.m_pMemory[v60], count: v86 - v60 - v61);
                }
              }
              v50 = pPhysicsCollision;
              v62 = (CPhysCollisionEntry **)PhysicsModel;
              CPhysCollisionEntry::WriteCollisionBinary(
                this: (CPhysCollisionEntry *)PhysicsModel->__vftable,
                pPhysicsCollision,
                pDest: v85.m_pMemory);
              CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::InsertMultipleBefore(
                this: p_m_PhysicsCollideData,
                elem: p_m_PhysicsCollideData->m_Size,
                num,
                pToInsert: v85.m_pMemory);
              CPhysCollisionEntry::Cleanup(this: *v62, pPhysicsCollision: v50);
              if ( *v62 != nullptr )
                ((void (__thiscall *)(CPhysCollisionEntry *, int))(*v62)->dtr_CPhysCollisionEntry)(a1: *v62, a2: 1);
              v49 = v62 + 1;
              v63 = pPhysicsProperties == (IPhysicsSurfaceProps *)1;
              pPhysicsProperties = (IPhysicsSurfaceProps *)((char *)pPhysicsProperties - 1);
              PhysicsModel = (CPhysCollisionEntrySolid *)v49;
            }
            while ( !v63 );
          }
          v64 = v78[v97];
          CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::InsertMultipleBefore(
            this: p_m_PhysicsCollideData,
            elem: p_m_PhysicsCollideData->m_Size,
            num: v64->m_Buffer.m_Size,
            pToInsert: (const unsigned __int8 *)v64->m_Buffer.m_Memory.m_pMemory);
          v38 = v97;
          if ( v64 != nullptr )
          {
            v65 = v64->m_Buffer.m_Memory.m_nGrowSize < 0;
            v64->m_Buffer.m_Size = 0;
            if ( !v65 )
            {
              if ( v64->m_Buffer.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v64->m_Buffer.m_Memory.m_pMemory);
                v64->m_Buffer.m_Memory.m_pMemory = nullptr;
              }
              v64->m_Buffer.m_Memory.m_nAllocationCount = 0;
            }
            v65 = v64->m_Buffer.m_Memory.m_nGrowSize < 0;
            v66 = (unsigned __int8 *)v64->m_Buffer.m_Memory.m_pMemory;
            v64->m_Buffer.m_pElements = v64->m_Buffer.m_Memory.m_pMemory;
            if ( !v65 )
            {
              if ( v66 != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v66);
                v64->m_Buffer.m_Memory.m_pMemory = nullptr;
              }
              v64->m_Buffer.m_Memory.m_nAllocationCount = 0;
            }
            free(pMem: v64);
          }
        }
        v96 = (CUtlMemory<BSPCluster_t,int> *)((char *)v96 + 20);
        v97 = ++v38;
      }
      while ( v38 < v98->m_ModelList.m_Size );
    }
    v67 = p_m_PhysicsCollideData->m_Size;
    v88 = -1;
    v89 = -1;
    v90 = 0;
    v91 = nullptr;
    v68 = p_m_PhysicsCollideData->m_Memory.m_nAllocationCount;
    if ( v67 + 16 > v68 )
      CUtlMemory<char,int>::Grow(this: &p_m_PhysicsCollideData->m_Memory, num: v67 - v68 + 16);
    p_m_PhysicsCollideData->m_Size += 16;
    v69 = p_m_PhysicsCollideData->m_Memory.m_pMemory;
    v70 = p_m_PhysicsCollideData->m_Size - v67 - 16;
    p_m_PhysicsCollideData->m_pElements = p_m_PhysicsCollideData->m_Memory.m_pMemory;
    if ( v70 > 0 )
      _V_memmove(dest: &v69[v67 + 16], src: &v69[v67], count: v70);
    for ( j = 0; j < 16; j += 4 )
    {
      v72 = &p_m_PhysicsCollideData->m_Memory.m_pMemory[j + v67];
      if ( v72 != nullptr )
        *v72 = *((_BYTE *)&v88 + j);
      if ( &p_m_PhysicsCollideData->m_Memory.m_pMemory[j + v67] != (unsigned __int8 *)-1 )
        p_m_PhysicsCollideData->m_Memory.m_pMemory[j + 1 + v67] = *((_BYTE *)&v88 + j + 1);
      if ( &p_m_PhysicsCollideData->m_Memory.m_pMemory[j + v67] != (unsigned __int8 *)-2 )
        p_m_PhysicsCollideData->m_Memory.m_pMemory[j + 2 + v67] = *((_BYTE *)&v88 + j + 2);
      if ( &p_m_PhysicsCollideData->m_Memory.m_pMemory[j + v67] != (unsigned __int8 *)-3 )
        p_m_PhysicsCollideData->m_Memory.m_pMemory[j + 3 + v67] = *((_BYTE *)&v88 + j + 3);
    }
    if ( v85.m_nGrowSize >= 0 && v85.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v85.m_pMemory);
    if ( pWorldPropertyRemapList.m_Memory.m_nGrowSize >= 0 && pWorldPropertyRemapList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pWorldPropertyRemapList.m_Memory.m_pMemory);
    v73 = &v82;
    for ( k = 1023; k >= 0; --k )
    {
      v73 -= 20;
      *((_DWORD *)v73 + 3) = 0;
      if ( *((int *)v73 + 2) >= 0 )
      {
        if ( *(_DWORD *)v73 != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)v73);
          *(_DWORD *)v73 = 0;
        }
        *((_DWORD *)v73 + 1) = 0;
      }
      v75 = *(void **)v73;
      *((_DWORD *)v73 + 4) = *(_DWORD *)v73;
      if ( *((int *)v73 + 2) >= 0 )
      {
        if ( v75 != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v75);
          *(_DWORD *)v73 = 0;
        }
        *((_DWORD *)v73 + 1) = 0;
      }
    }
  }
  else if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_VBSP2, a2: 3) != 0 )
  {
    _LoggingSystem_Log(
      a1: LOG_VBSP2,
      a2: 3,
      a3: "Cannot instantiate necessary physics interfaces to build collision data.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A2D0
// Name: public: void CMemoryBSPFile::ProcessAndSerialize(class CUtlBuffer __near *,class CSimpleBSPFile const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMemoryBSPFile::ProcessAndSerialize(
        CMemoryBSPFile *this,
        CUtlBuffer *pOutputBuffer,
        const CSimpleBSPFile *pSimpleBSPFile)
{
  CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> > *v4; // eax
  int *m_HashTable; // eax
  int i; // edx
  const CSimpleMapFile *m_pMapFile; // ecx
  int m_nMapRevision; // edx
  CUtlBuffer *m_pSerialBuffer; // ecx
  CUtlVector<texinfo_s,CUtlMemory<texinfo_s,int> > *p_m_TexInfoList; // edi
  CUtlVector<dplane_t,CUtlMemory<dplane_t,int> > *p_m_Planes; // edi
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *p_m_GameLumpData; // edi
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *p_m_EntityData; // edi
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *p_m_VisibilityData; // edi
  int pData; // [esp+Ch] [ebp-1Ch] BYREF
  __int64 v16; // [esp+10h] [ebp-18h]
  int v17; // [esp+18h] [ebp-10h]
  __int16 v18; // [esp+1Ch] [ebp-Ch] BYREF
  __int64 v19; // [esp+1Eh] [ebp-Ah]
  __int16 v20; // [esp+26h] [ebp-2h]
  int savedregs; // [esp+28h] [ebp+0h] BYREF

  this->m_pSerialBuffer = pOutputBuffer;
  CUtlBuffer::SeekPut(this: pOutputBuffer, type: SEEK_HEAD, offset: 0);
  this->m_pSimpleBSPFile = pSimpleBSPFile;
  this->m_pMapFile = pSimpleBSPFile->m_pMapFile;
  if ( pSimpleBSPFile == (const CSimpleBSPFile *)-4 )
    v4 = nullptr;
  else
    v4 = &pSimpleBSPFile->m_PlaneHash.m_Planes.CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> >;
  CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int>>::operator=(
    this: &this->m_PlaneHash.m_Planes.CUtlVector<HashedPlane_t,CUtlMemory<HashedPlane_t,int> >,
    other: v4);
  m_HashTable = this->m_PlaneHash.m_HashTable;
  for ( i = 1024; i != 0; --i )
  {
    *m_HashTable = *(int *)((char *)m_HashTable + (char *)&pSimpleBSPFile->m_PlaneHash - (char *)&this->m_PlaneHash);
    ++m_HashTable;
  }
  m_pMapFile = this->m_pMapFile;
  this->m_FileHeader.ident = 1347633750;
  this->m_FileHeader.m_nVersion = 21;
  m_nMapRevision = m_pMapFile->m_nMapRevision;
  m_pSerialBuffer = this->m_pSerialBuffer;
  this->m_FileHeader.mapRevision = m_nMapRevision;
  CUtlBuffer::Put(this: m_pSerialBuffer, pMem: (unsigned __int8 *)&this->m_FileHeader, size: 1036);
  CMemoryBSPFile::BuildTexInfo(this);
  p_m_TexInfoList = &this->m_TexInfoList;
  CMemoryBSPFile::WriteLump<texinfo_s>(this, nLump: 6, data: &this->m_TexInfoList, nVersion: 0);
  this->m_TexInfoList.m_Size = 0;
  if ( this->m_TexInfoList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_TexInfoList->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_TexInfoList->m_Memory.m_pMemory);
      p_m_TexInfoList->m_Memory.m_pMemory = nullptr;
    }
    this->m_TexInfoList.m_Memory.m_nAllocationCount = 0;
  }
  this->m_TexInfoList.m_pElements = this->m_TexInfoList.m_Memory.m_pMemory;
  CMemoryBSPFile::BuildTexData(this);
  CMemoryBSPFile::WriteTexData(this, bPurgeWhenComplete: true);
  CMemoryBSPFile::BuildModelData(this);
  CMemoryBSPFile::WriteModelData(this, bPurgeWhenComplete: true);
  CMemoryBSPFile::BuildBSPTreeData(this);
  CMemoryBSPFile::WriteBSPTreeData(this, bPurgeWhenComplete: true);
  CMemoryBSPFile::BuildBrushes(this);
  CMemoryBSPFile::WriteBrushes(this, bPurgeWhenComplete: true);
  CMemoryBSPFile::BuildPlanes(this);
  p_m_Planes = &this->m_Planes;
  CMemoryBSPFile::WriteLump<dplane_t>(
    this,
    nLump: 1,
    data: (const CUtlVector<CDispVert,CUtlMemory<CDispVert,int> > *)&this->m_Planes,
    nVersion: 0);
  this->m_Planes.m_Size = 0;
  if ( this->m_Planes.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_Planes->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_Planes->m_Memory.m_pMemory);
      p_m_Planes->m_Memory.m_pMemory = nullptr;
    }
    this->m_Planes.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Planes.m_pElements = p_m_Planes->m_Memory.m_pMemory;
  CMemoryBSPFile::WriteLump<dmodel_t>(this, nLump: 14, data: &this->m_ModelList, nVersion: 0);
  v19 = 0;
  v18 = 0;
  v20 = 0;
  pData = 0;
  v16 = 0;
  v17 = 1;
  CMemoryBSPFile::WriteLump(this, nLump: 20, (unsigned __int8 *)&pData, nByteLength: 16, nVersion: 0);
  CMemoryBSPFile::WriteLump(this, nLump: 21, pData: (unsigned __int8 *)&v18, nByteLength: 12, nVersion: 0);
  CMemoryBSPFile::BuildGameLumpData(this);
  p_m_GameLumpData = &this->m_GameLumpData;
  CMemoryBSPFile::WriteLump<char>(
    this,
    nLump: 35,
    data: (const CUtlVector<char,CUtlMemory<char,int> > *)&this->m_GameLumpData,
    nVersion: 0);
  this->m_GameLumpData.m_Size = 0;
  if ( this->m_GameLumpData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_GameLumpData->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_GameLumpData->m_Memory.m_pMemory);
      p_m_GameLumpData->m_Memory.m_pMemory = nullptr;
    }
    this->m_GameLumpData.m_Memory.m_nAllocationCount = 0;
  }
  this->m_GameLumpData.m_pElements = this->m_GameLumpData.m_Memory.m_pMemory;
  CMemoryBSPFile::BuildEntityData(this);
  p_m_EntityData = &this->m_EntityData;
  CMemoryBSPFile::WriteLump<char>(
    this,
    nLump: 0,
    data: (const CUtlVector<char,CUtlMemory<char,int> > *)&this->m_EntityData,
    nVersion: 0);
  this->m_EntityData.m_Size = 0;
  if ( this->m_EntityData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_EntityData->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_EntityData->m_Memory.m_pMemory);
      p_m_EntityData->m_Memory.m_pMemory = nullptr;
    }
    this->m_EntityData.m_Memory.m_nAllocationCount = 0;
  }
  this->m_EntityData.m_pElements = this->m_EntityData.m_Memory.m_pMemory;
  CMemoryBSPFile::BuildVisibilityData(this);
  p_m_VisibilityData = &this->m_VisibilityData;
  CMemoryBSPFile::WriteLump<char>(
    this,
    nLump: 4,
    data: (const CUtlVector<char,CUtlMemory<char,int> > *)&this->m_VisibilityData,
    nVersion: 0);
  this->m_VisibilityData.m_Size = 0;
  if ( this->m_VisibilityData.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_VisibilityData->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_VisibilityData->m_Memory.m_pMemory);
      p_m_VisibilityData->m_Memory.m_pMemory = nullptr;
    }
    this->m_VisibilityData.m_Memory.m_nAllocationCount = 0;
  }
  this->m_VisibilityData.m_pElements = this->m_VisibilityData.m_Memory.m_pMemory;
  CMemoryBSPFile::BuildDisplacements(this, a2: (int)&savedregs);
  CMemoryBSPFile::WriteDisplacements(this, bPurgeWhenComplete: true);
  CMemoryBSPFile::BuildPhysicsCollisionData(this);
  CMemoryBSPFile::WritePhysicsCollisionData(this, bPurgeWhenComplete: true);
  CMemoryBSPFile::WriteLightingData(this, bPurgeWhenComplete: true);
  CUtlBuffer::SeekPut(this: this->m_pSerialBuffer, type: SEEK_HEAD, offset: 0);
  CUtlBuffer::Put(this: this->m_pSerialBuffer, pMem: (unsigned __int8 *)&this->m_FileHeader, size: 1036);
}

//------------------------------------------------------------------------------
// Address: 0x0041A590
// Name: void SaveToFile(class CUtlBuffer __near *,class CSimpleBSPFile const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SaveToFile(CUtlBuffer *pOutputBuffer, const CSimpleBSPFile *pBSPFile)
{
  CMemoryBSPFile v2; // [esp+0h] [ebp-11EB0h] BYREF

  CMemoryBSPFile::CMemoryBSPFile(this: &v2);
  CMemoryBSPFile::ProcessAndSerialize(this: &v2, pOutputBuffer, pSimpleBSPFile: pBSPFile);
  CMemoryBSPFile::~CMemoryBSPFile(this: &v2);
}

} // namespace vbsp2
