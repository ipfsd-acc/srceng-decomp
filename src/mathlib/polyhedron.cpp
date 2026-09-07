// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mathlib/polyhedron.cpp
// Functions: 3
// ============================================================

#include "mathlib\polyhedron.h"

//------------------------------------------------------------------------------
// Address: 0x100AB430
// Name: public: virtual void CPolyhedron_AllocByNew::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CPolyhedron_AllocByNew::Release(CPolyhedron_AllocByNew *this)
{
  if ( this != nullptr )
    ((void (__thiscall *)(CPolyhedron_AllocByNew *, int))this->dtr_CPolyhedron)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x100AB470
// Name: public: static class CPolyhedron_AllocByNew __near * CPolyhedron_AllocByNew::Allocate(unsigned short,unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
CPolyhedron_AllocByNew *__cdecl CPolyhedron_AllocByNew::Allocate(
        unsigned __int16 iVertices,
        unsigned __int16 iLines,
        unsigned __int16 iIndices,
        unsigned __int16 iPolygons)
{
  CPolyhedron_AllocByNew *result; // eax
  Polyhedron_IndexedLine_t *v5; // ecx
  Polyhedron_IndexedLineReference_t *v6; // ecx

  result = (CPolyhedron_AllocByNew *)p_malloc(size: 4 * (iLines + iVertices + iIndices + 2 * iVertices + 4 * iPolygons) + 28);
  if ( result != nullptr )
    result->__vftable = (CPolyhedron_AllocByNew_vtbl *)&CPolyhedron_AllocByNew::`vftable';
  else
    result = nullptr;
  result->iLineCount = iLines;
  result->iVertexCount = iVertices;
  result->iPolygonCount = iPolygons;
  result->iIndexCount = iIndices;
  result->pVertices = (Vector *)&result[1];
  v5 = (Polyhedron_IndexedLine_t *)((char *)&result[1] + 12 * iVertices);
  result->pLines = v5;
  v6 = (Polyhedron_IndexedLineReference_t *)&v5[iLines];
  result->pIndices = v6;
  result->pPolygons = (Polyhedron_IndexedPolygon_t *)&v6[iIndices];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100AB4F0
// Name: class CPolyhedron __near * GetTempPolyhedron(unsigned short,unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
CPolyhedron_TempMemory *__cdecl GetTempPolyhedron(
        unsigned __int16 iVertices,
        unsigned __int16 iLines,
        unsigned __int16 iIndices,
        unsigned __int16 iPolygons)
{
  int m_Size; // ecx
  int v5; // esi
  unsigned __int8 *m_pMemory; // eax

  m_Size = 0;
  v5 = 4 * (iLines + iVertices + iIndices + 2 * iVertices + 4 * iPolygons);
  s_TempMemoryPolyhedron_Buffer.m_Size = 0;
  if ( v5 == 0 )
    goto LABEL_7;
  if ( v5 > s_TempMemoryPolyhedron_Buffer.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<char,int>::Grow(
      this: &s_TempMemoryPolyhedron_Buffer.m_Memory,
      num: v5 - s_TempMemoryPolyhedron_Buffer.m_Memory.m_nAllocationCount);
    m_Size = s_TempMemoryPolyhedron_Buffer.m_Size;
  }
  m_pMemory = s_TempMemoryPolyhedron_Buffer.m_Memory.m_pMemory;
  s_TempMemoryPolyhedron_Buffer.m_Size = v5 + m_Size;
  s_TempMemoryPolyhedron_Buffer.m_pElements = s_TempMemoryPolyhedron_Buffer.m_Memory.m_pMemory;
  if ( m_Size > 0 && 4 * (iLines + iVertices + iIndices + 2 * iVertices + 4 * iPolygons) != 0 )
  {
    _V_memmove(
      dest: &s_TempMemoryPolyhedron_Buffer.m_Memory.m_pMemory[v5],
      src: s_TempMemoryPolyhedron_Buffer.m_Memory.m_pMemory,
      count: m_Size);
LABEL_7:
    m_pMemory = s_TempMemoryPolyhedron_Buffer.m_Memory.m_pMemory;
  }
  s_TempMemoryPolyhedron.iVertexCount = iVertices;
  s_TempMemoryPolyhedron.iIndexCount = iIndices;
  s_TempMemoryPolyhedron.pVertices = (Vector *)m_pMemory;
  s_TempMemoryPolyhedron.iLineCount = iLines;
  s_TempMemoryPolyhedron.pLines = (Polyhedron_IndexedLine_t *)&m_pMemory[12 * iVertices];
  s_TempMemoryPolyhedron.iPolygonCount = iPolygons;
  s_TempMemoryPolyhedron.pIndices = (Polyhedron_IndexedLineReference_t *)&s_TempMemoryPolyhedron.pLines[iLines];
  s_TempMemoryPolyhedron.pPolygons = (Polyhedron_IndexedPolygon_t *)&s_TempMemoryPolyhedron.pIndices[iIndices];
  return &s_TempMemoryPolyhedron;
}
