// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier2/meshutils.cpp
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1027AA30
// Name: void GenerateSequentialIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateSequentialIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  int i; // eax

  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount; ++i )
      pIndices[i] = nFirstVertex + i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027AA60
// Name: void GenerateQuadIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateQuadIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // esi
  unsigned __int16 *v4; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int16 *v7; // eax

  if ( pIndices != nullptr )
  {
    v3 = nIndexCount / 6;
    if ( ((unsigned __int8)pIndices & 3) != 0 )
    {
      if ( v3 > 0 )
      {
        v6 = (unsigned __int16)(nFirstVertex + 2);
        v7 = pIndices + 2;
        do
        {
          *(v7 - 2) = v6 - 2;
          v7[1] = v6 - 2;
          *v7 = v6;
          v7[2] = v6;
          *(v7 - 1) = v6 - 1;
          v7[3] = v6 + 1;
          v6 += 4;
          v7 += 6;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else if ( v3 > 0 )
    {
      v4 = pIndices + 4;
      v5 = (nFirstVertex | (nFirstVertex << 16)) + 2;
      do
      {
        *((_DWORD *)v4 - 2) = v5 + 65534;
        *((_DWORD *)v4 - 1) = v5;
        *(_DWORD *)v4 = v5 + 196608;
        v4 += 6;
        v5 += 262148;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027AB10
// Name: void GeneratePolygonIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GeneratePolygonIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // ecx
  unsigned __int16 *v4; // eax

  if ( pIndices != nullptr )
  {
    v3 = 0;
    if ( nIndexCount / 3 > 0 )
    {
      v4 = pIndices + 2;
      do
      {
        *(v4 - 2) = nFirstVertex;
        *(v4 - 1) = v3 + nFirstVertex + 1;
        *v4 = v3++ + nFirstVertex + 2;
        v4 += 3;
      }
      while ( v3 < nIndexCount / 3 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027AB70
// Name: void GenerateLineStripIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineStripIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  unsigned __int16 *v3; // esi
  int i; // ecx

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount / 2; v3 += 2 )
    {
      *v3 = i + nFirstVertex;
      v3[1] = i++ + nFirstVertex + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027ABB0
// Name: void GenerateLineLoopIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineLoopIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // edx
  unsigned __int16 *i; // ecx

  if ( pIndices != nullptr )
  {
    *pIndices = nIndexCount / 2 + nFirstVertex - 1;
    pIndices[1] = nFirstVertex;
    v3 = 1;
    for ( i = pIndices + 2; v3 < nIndexCount / 2; i += 2 )
    {
      *i = v3 + nFirstVertex - 1;
      i[1] = v3++ + nFirstVertex;
    }
  }
}

// ============================================================
// Overlay from MaterialSystem (Missing functions)
// ============================================================
namespace MaterialSystem {

//------------------------------------------------------------------------------
// Address: 0x1025D370
// Name: void GenerateSequentialIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateSequentialIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  int i; // eax

  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount; ++i )
      pIndices[i] = nFirstVertex + i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025D3A0
// Name: void GenerateQuadIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateQuadIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // esi
  unsigned __int16 *v4; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int16 *v7; // eax

  if ( pIndices != nullptr )
  {
    v3 = nIndexCount / 6;
    if ( ((unsigned __int8)pIndices & 3) != 0 )
    {
      if ( v3 > 0 )
      {
        v6 = (unsigned __int16)(nFirstVertex + 2);
        v7 = pIndices + 2;
        do
        {
          *(v7 - 2) = v6 - 2;
          v7[1] = v6 - 2;
          *v7 = v6;
          v7[2] = v6;
          *(v7 - 1) = v6 - 1;
          v7[3] = v6 + 1;
          v6 += 4;
          v7 += 6;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else if ( v3 > 0 )
    {
      v4 = pIndices + 4;
      v5 = (nFirstVertex | (nFirstVertex << 16)) + 2;
      do
      {
        *((_DWORD *)v4 - 2) = v5 + 65534;
        *((_DWORD *)v4 - 1) = v5;
        *(_DWORD *)v4 = v5 + 196608;
        v4 += 6;
        v5 += 262148;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025D450
// Name: void GeneratePolygonIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GeneratePolygonIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // ecx
  unsigned __int16 *v4; // eax

  if ( pIndices != nullptr )
  {
    v3 = 0;
    if ( nIndexCount / 3 > 0 )
    {
      v4 = pIndices + 2;
      do
      {
        *(v4 - 2) = nFirstVertex;
        *(v4 - 1) = v3 + nFirstVertex + 1;
        *v4 = v3++ + nFirstVertex + 2;
        v4 += 3;
      }
      while ( v3 < nIndexCount / 3 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025D4B0
// Name: void GenerateLineStripIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineStripIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  unsigned __int16 *v3; // esi
  int i; // ecx

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount / 2; v3 += 2 )
    {
      *v3 = i + nFirstVertex;
      v3[1] = i++ + nFirstVertex + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025D4F0
// Name: void GenerateLineLoopIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineLoopIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // edx
  unsigned __int16 *i; // ecx

  if ( pIndices != nullptr )
  {
    *pIndices = nIndexCount / 2 + nFirstVertex - 1;
    pIndices[1] = nFirstVertex;
    v3 = 1;
    for ( i = pIndices + 2; v3 < nIndexCount / 2; i += 2 )
    {
      *i = v3 + nFirstVertex - 1;
      i[1] = v3++ + nFirstVertex;
    }
  }
}

} // namespace MaterialSystem

// ============================================================
// Overlay from StudioRender (Missing functions)
// ============================================================
namespace StudioRender {

//------------------------------------------------------------------------------
// Address: 0x10059620
// Name: void GenerateSequentialIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateSequentialIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  int i; // eax

  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount; ++i )
      pIndices[i] = nFirstVertex + i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10059650
// Name: void GenerateQuadIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateQuadIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // esi
  unsigned __int16 *v4; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int16 *v7; // eax

  if ( pIndices != nullptr )
  {
    v3 = nIndexCount / 6;
    if ( ((unsigned __int8)pIndices & 3) != 0 )
    {
      if ( v3 > 0 )
      {
        v6 = (unsigned __int16)(nFirstVertex + 2);
        v7 = pIndices + 2;
        do
        {
          *(v7 - 2) = v6 - 2;
          v7[1] = v6 - 2;
          *v7 = v6;
          v7[2] = v6;
          *(v7 - 1) = v6 - 1;
          v7[3] = v6 + 1;
          v6 += 4;
          v7 += 6;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else if ( v3 > 0 )
    {
      v4 = pIndices + 4;
      v5 = (nFirstVertex | (nFirstVertex << 16)) + 2;
      do
      {
        *((_DWORD *)v4 - 2) = v5 + 65534;
        *((_DWORD *)v4 - 1) = v5;
        *(_DWORD *)v4 = v5 + 196608;
        v4 += 6;
        v5 += 262148;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10059700
// Name: void GeneratePolygonIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GeneratePolygonIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // ecx
  unsigned __int16 *v4; // eax

  if ( pIndices != nullptr )
  {
    v3 = 0;
    if ( nIndexCount / 3 > 0 )
    {
      v4 = pIndices + 2;
      do
      {
        *(v4 - 2) = nFirstVertex;
        *(v4 - 1) = v3 + nFirstVertex + 1;
        *v4 = v3++ + nFirstVertex + 2;
        v4 += 3;
      }
      while ( v3 < nIndexCount / 3 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10059760
// Name: void GenerateLineStripIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineStripIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  unsigned __int16 *v3; // esi
  int i; // ecx

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount / 2; v3 += 2 )
    {
      *v3 = i + nFirstVertex;
      v3[1] = i++ + nFirstVertex + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100597A0
// Name: void GenerateLineLoopIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineLoopIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // edx
  unsigned __int16 *i; // ecx

  if ( pIndices != nullptr )
  {
    *pIndices = nIndexCount / 2 + nFirstVertex - 1;
    pIndices[1] = nFirstVertex;
    v3 = 1;
    for ( i = pIndices + 2; v3 < nIndexCount / 2; i += 2 )
    {
      *i = v3 + nFirstVertex - 1;
      i[1] = v3++ + nFirstVertex;
    }
  }
}

} // namespace StudioRender

// ============================================================
// Overlay from shaderapidx9 (Missing functions)
// ============================================================
namespace shaderapidx9 {

//------------------------------------------------------------------------------
// Address: 0x100D9D10
// Name: void GenerateSequentialIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateSequentialIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  int i; // eax

  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount; ++i )
      pIndices[i] = nFirstVertex + i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D9D40
// Name: void GenerateQuadIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateQuadIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // esi
  unsigned __int16 *v4; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int16 *v7; // eax

  if ( pIndices != nullptr )
  {
    v3 = nIndexCount / 6;
    if ( ((unsigned __int8)pIndices & 3) != 0 )
    {
      if ( v3 > 0 )
      {
        v6 = (unsigned __int16)(nFirstVertex + 2);
        v7 = pIndices + 2;
        do
        {
          *(v7 - 2) = v6 - 2;
          v7[1] = v6 - 2;
          *v7 = v6;
          v7[2] = v6;
          *(v7 - 1) = v6 - 1;
          v7[3] = v6 + 1;
          v6 += 4;
          v7 += 6;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else if ( v3 > 0 )
    {
      v4 = pIndices + 4;
      v5 = (nFirstVertex | (nFirstVertex << 16)) + 2;
      do
      {
        *((_DWORD *)v4 - 2) = v5 + 65534;
        *((_DWORD *)v4 - 1) = v5;
        *(_DWORD *)v4 = v5 + 196608;
        v4 += 6;
        v5 += 262148;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D9DF0
// Name: void GeneratePolygonIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GeneratePolygonIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // ecx
  unsigned __int16 *v4; // eax

  if ( pIndices != nullptr )
  {
    v3 = 0;
    if ( nIndexCount / 3 > 0 )
    {
      v4 = pIndices + 2;
      do
      {
        *(v4 - 2) = nFirstVertex;
        *(v4 - 1) = v3 + nFirstVertex + 1;
        *v4 = v3++ + nFirstVertex + 2;
        v4 += 3;
      }
      while ( v3 < nIndexCount / 3 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D9E50
// Name: void GenerateLineStripIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineStripIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  unsigned __int16 *v3; // esi
  int i; // ecx

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount / 2; v3 += 2 )
    {
      *v3 = i + nFirstVertex;
      v3[1] = i++ + nFirstVertex + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D9E90
// Name: void GenerateLineLoopIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineLoopIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // edx
  unsigned __int16 *i; // ecx

  if ( pIndices != nullptr )
  {
    *pIndices = nIndexCount / 2 + nFirstVertex - 1;
    pIndices[1] = nFirstVertex;
    v3 = 1;
    for ( i = pIndices + 2; v3 < nIndexCount / 2; i += 2 )
    {
      *i = v3 + nFirstVertex - 1;
      i[1] = v3++ + nFirstVertex;
    }
  }
}

} // namespace shaderapidx9

// ============================================================
// Overlay from avitest (Missing functions)
// ============================================================
namespace avitest {

//------------------------------------------------------------------------------
// Address: 0x0040E730
// Name: void GenerateSequentialIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateSequentialIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  int i; // eax

  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount; ++i )
      pIndices[i] = nFirstVertex + i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E760
// Name: void GenerateQuadIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateQuadIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // esi
  unsigned __int16 *v4; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int16 *v7; // eax

  if ( pIndices != nullptr )
  {
    v3 = nIndexCount / 6;
    if ( ((unsigned __int8)pIndices & 3) != 0 )
    {
      if ( v3 > 0 )
      {
        v6 = (unsigned __int16)(nFirstVertex + 2);
        v7 = pIndices + 2;
        do
        {
          *(v7 - 2) = v6 - 2;
          v7[1] = v6 - 2;
          *v7 = v6;
          v7[2] = v6;
          *(v7 - 1) = v6 - 1;
          v7[3] = v6 + 1;
          v6 += 4;
          v7 += 6;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else if ( v3 > 0 )
    {
      v4 = pIndices + 4;
      v5 = (nFirstVertex | (nFirstVertex << 16)) + 2;
      do
      {
        *((_DWORD *)v4 - 2) = v5 + 65534;
        *((_DWORD *)v4 - 1) = v5;
        *(_DWORD *)v4 = v5 + 196608;
        v4 += 6;
        v5 += 262148;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E810
// Name: void GeneratePolygonIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GeneratePolygonIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // ecx
  unsigned __int16 *v4; // eax

  if ( pIndices != nullptr )
  {
    v3 = 0;
    if ( nIndexCount / 3 > 0 )
    {
      v4 = pIndices + 2;
      do
      {
        *(v4 - 2) = nFirstVertex;
        *(v4 - 1) = v3 + nFirstVertex + 1;
        *v4 = v3++ + nFirstVertex + 2;
        v4 += 3;
      }
      while ( v3 < nIndexCount / 3 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E870
// Name: void GenerateLineStripIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineStripIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  unsigned __int16 *v3; // esi
  int i; // ecx

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount / 2; v3 += 2 )
    {
      *v3 = i + nFirstVertex;
      v3[1] = i++ + nFirstVertex + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040E8B0
// Name: void GenerateLineLoopIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineLoopIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // edx
  unsigned __int16 *i; // ecx

  if ( pIndices != nullptr )
  {
    *pIndices = nIndexCount / 2 + nFirstVertex - 1;
    pIndices[1] = nFirstVertex;
    v3 = 1;
    for ( i = pIndices + 2; v3 < nIndexCount / 2; i += 2 )
    {
      *i = v3 + nFirstVertex - 1;
      i[1] = v3++ + nFirstVertex;
    }
  }
}

} // namespace avitest

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x00576B40
// Name: void GenerateSequentialIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateSequentialIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  int i; // eax

  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount; ++i )
      pIndices[i] = nFirstVertex + i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00576B70
// Name: void GenerateQuadIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateQuadIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // esi
  unsigned __int16 *v4; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int16 *v7; // eax

  if ( pIndices != nullptr )
  {
    v3 = nIndexCount / 6;
    if ( ((unsigned __int8)pIndices & 3) != 0 )
    {
      if ( v3 > 0 )
      {
        v6 = (unsigned __int16)(nFirstVertex + 2);
        v7 = pIndices + 2;
        do
        {
          *(v7 - 2) = v6 - 2;
          v7[1] = v6 - 2;
          *v7 = v6;
          v7[2] = v6;
          *(v7 - 1) = v6 - 1;
          v7[3] = v6 + 1;
          v6 += 4;
          v7 += 6;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else if ( v3 > 0 )
    {
      v4 = pIndices + 4;
      v5 = (nFirstVertex | (nFirstVertex << 16)) + 2;
      do
      {
        *((_DWORD *)v4 - 2) = v5 + 65534;
        *((_DWORD *)v4 - 1) = v5;
        *(_DWORD *)v4 = v5 + 196608;
        v4 += 6;
        v5 += 262148;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00576C20
// Name: void GeneratePolygonIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GeneratePolygonIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // ecx
  unsigned __int16 *v4; // eax

  if ( pIndices != nullptr )
  {
    v3 = 0;
    if ( nIndexCount / 3 > 0 )
    {
      v4 = pIndices + 2;
      do
      {
        *(v4 - 2) = nFirstVertex;
        *(v4 - 1) = v3 + nFirstVertex + 1;
        *v4 = v3++ + nFirstVertex + 2;
        v4 += 3;
      }
      while ( v3 < nIndexCount / 3 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00576C80
// Name: void GenerateLineStripIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineStripIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  unsigned __int16 *v3; // esi
  int i; // ecx

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount / 2; v3 += 2 )
    {
      *v3 = i + nFirstVertex;
      v3[1] = i++ + nFirstVertex + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00576CC0
// Name: void GenerateLineLoopIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineLoopIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // edx
  unsigned __int16 *i; // ecx

  if ( pIndices != nullptr )
  {
    *pIndices = nIndexCount / 2 + nFirstVertex - 1;
    pIndices[1] = nFirstVertex;
    v3 = 1;
    for ( i = pIndices + 2; v3 < nIndexCount / 2; i += 2 )
    {
      *i = v3 + nFirstVertex - 1;
      i[1] = v3++ + nFirstVertex;
    }
  }
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x005DA290
// Name: void GenerateSequentialIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateSequentialIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  int i; // eax

  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount; ++i )
      pIndices[i] = nFirstVertex + i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005DA2C0
// Name: void GenerateQuadIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateQuadIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // esi
  unsigned __int16 *v4; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int16 *v7; // eax

  if ( pIndices != nullptr )
  {
    v3 = nIndexCount / 6;
    if ( ((unsigned __int8)pIndices & 3) != 0 )
    {
      if ( v3 > 0 )
      {
        v6 = (unsigned __int16)(nFirstVertex + 2);
        v7 = pIndices + 2;
        do
        {
          *(v7 - 2) = v6 - 2;
          v7[1] = v6 - 2;
          *v7 = v6;
          v7[2] = v6;
          *(v7 - 1) = v6 - 1;
          v7[3] = v6 + 1;
          v6 += 4;
          v7 += 6;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else if ( v3 > 0 )
    {
      v4 = pIndices + 4;
      v5 = (nFirstVertex | (nFirstVertex << 16)) + 2;
      do
      {
        *((_DWORD *)v4 - 2) = v5 + 65534;
        *((_DWORD *)v4 - 1) = v5;
        *(_DWORD *)v4 = v5 + 196608;
        v4 += 6;
        v5 += 262148;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005DA370
// Name: void GeneratePolygonIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GeneratePolygonIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // ecx
  unsigned __int16 *v4; // eax

  if ( pIndices != nullptr )
  {
    v3 = 0;
    if ( nIndexCount / 3 > 0 )
    {
      v4 = pIndices + 2;
      do
      {
        *(v4 - 2) = nFirstVertex;
        *(v4 - 1) = v3 + nFirstVertex + 1;
        *v4 = v3++ + nFirstVertex + 2;
        v4 += 3;
      }
      while ( v3 < nIndexCount / 3 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005DA3D0
// Name: void GenerateLineStripIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineStripIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  unsigned __int16 *v3; // esi
  int i; // ecx

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount / 2; v3 += 2 )
    {
      *v3 = i + nFirstVertex;
      v3[1] = i++ + nFirstVertex + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005DA410
// Name: void GenerateLineLoopIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineLoopIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // edx
  unsigned __int16 *i; // ecx

  if ( pIndices != nullptr )
  {
    *pIndices = nIndexCount / 2 + nFirstVertex - 1;
    pIndices[1] = nFirstVertex;
    v3 = 1;
    for ( i = pIndices + 2; v3 < nIndexCount / 2; i += 2 )
    {
      *i = v3 + nFirstVertex - 1;
      i[1] = v3++ + nFirstVertex;
    }
  }
}

} // namespace elementviewer

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1027ABA0
// Name: void GenerateQuadIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateQuadIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // esi
  unsigned __int16 *v4; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int16 *v7; // eax

  if ( pIndices != nullptr )
  {
    v3 = nIndexCount / 6;
    if ( ((unsigned __int8)pIndices & 3) != 0 )
    {
      if ( v3 > 0 )
      {
        v6 = (unsigned __int16)(nFirstVertex + 2);
        v7 = pIndices + 2;
        do
        {
          *(v7 - 2) = v6 - 2;
          v7[1] = v6 - 2;
          *v7 = v6;
          v7[2] = v6;
          *(v7 - 1) = v6 - 1;
          v7[3] = v6 + 1;
          v6 += 4;
          v7 += 6;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else if ( v3 > 0 )
    {
      v4 = pIndices + 4;
      v5 = (nFirstVertex | (nFirstVertex << 16)) + 2;
      do
      {
        *((_DWORD *)v4 - 2) = v5 + 65534;
        *((_DWORD *)v4 - 1) = v5;
        *(_DWORD *)v4 = v5 + 196608;
        v4 += 6;
        v5 += 262148;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027AC50
// Name: void GeneratePolygonIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GeneratePolygonIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // ecx
  unsigned __int16 *v4; // eax

  if ( pIndices != nullptr )
  {
    v3 = 0;
    if ( nIndexCount / 3 > 0 )
    {
      v4 = pIndices + 2;
      do
      {
        *(v4 - 2) = nFirstVertex;
        *(v4 - 1) = v3 + nFirstVertex + 1;
        *v4 = v3++ + nFirstVertex + 2;
        v4 += 3;
      }
      while ( v3 < nIndexCount / 3 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027ACB0
// Name: void GenerateLineStripIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineStripIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  unsigned __int16 *v3; // esi
  int i; // ecx

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount / 2; v3 += 2 )
    {
      *v3 = i + nFirstVertex;
      v3[1] = i++ + nFirstVertex + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1027ACF0
// Name: void GenerateLineLoopIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineLoopIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // edx
  unsigned __int16 *i; // ecx

  if ( pIndices != nullptr )
  {
    *pIndices = nIndexCount / 2 + nFirstVertex - 1;
    pIndices[1] = nFirstVertex;
    v3 = 1;
    for ( i = pIndices + 2; v3 < nIndexCount / 2; i += 2 )
    {
      *i = v3 + nFirstVertex - 1;
      i[1] = v3++ + nFirstVertex;
    }
  }
}

} // namespace engine_xlsp

// ============================================================
// Overlay from hlfaceposer (Missing functions)
// ============================================================
namespace hlfaceposer {

//------------------------------------------------------------------------------
// Address: 0x004CD810
// Name: void GenerateSequentialIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateSequentialIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  int i; // eax

  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount; ++i )
      pIndices[i] = nFirstVertex + i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CD840
// Name: void GenerateQuadIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateQuadIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // esi
  unsigned __int16 *v4; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int16 *v7; // eax

  if ( pIndices != nullptr )
  {
    v3 = nIndexCount / 6;
    if ( ((unsigned __int8)pIndices & 3) != 0 )
    {
      if ( v3 > 0 )
      {
        v6 = (unsigned __int16)(nFirstVertex + 2);
        v7 = pIndices + 2;
        do
        {
          *(v7 - 2) = v6 - 2;
          v7[1] = v6 - 2;
          *v7 = v6;
          v7[2] = v6;
          *(v7 - 1) = v6 - 1;
          v7[3] = v6 + 1;
          v6 += 4;
          v7 += 6;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else if ( v3 > 0 )
    {
      v4 = pIndices + 4;
      v5 = (nFirstVertex | (nFirstVertex << 16)) + 2;
      do
      {
        *((_DWORD *)v4 - 2) = v5 + 65534;
        *((_DWORD *)v4 - 1) = v5;
        *(_DWORD *)v4 = v5 + 196608;
        v4 += 6;
        v5 += 262148;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CD8F0
// Name: void GeneratePolygonIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GeneratePolygonIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // ecx
  unsigned __int16 *v4; // eax

  if ( pIndices != nullptr )
  {
    v3 = 0;
    if ( nIndexCount / 3 > 0 )
    {
      v4 = pIndices + 2;
      do
      {
        *(v4 - 2) = nFirstVertex;
        *(v4 - 1) = v3 + nFirstVertex + 1;
        *v4 = v3++ + nFirstVertex + 2;
        v4 += 3;
      }
      while ( v3 < nIndexCount / 3 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CD950
// Name: void GenerateLineStripIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineStripIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  unsigned __int16 *v3; // esi
  int i; // ecx

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount / 2; v3 += 2 )
    {
      *v3 = i + nFirstVertex;
      v3[1] = i++ + nFirstVertex + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004CD990
// Name: void GenerateLineLoopIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineLoopIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // edx
  unsigned __int16 *i; // ecx

  if ( pIndices != nullptr )
  {
    *pIndices = nIndexCount / 2 + nFirstVertex - 1;
    pIndices[1] = nFirstVertex;
    v3 = 1;
    for ( i = pIndices + 2; v3 < nIndexCount / 2; i += 2 )
    {
      *i = v3 + nFirstVertex - 1;
      i[1] = v3++ + nFirstVertex;
    }
  }
}

} // namespace hlfaceposer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102B6CD0
// Name: void GenerateSequentialIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateSequentialIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  int i; // eax

  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount; ++i )
      pIndices[i] = nFirstVertex + i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B6D00
// Name: void GenerateQuadIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateQuadIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // esi
  unsigned __int16 *v4; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int16 *v7; // eax

  if ( pIndices != nullptr )
  {
    v3 = nIndexCount / 6;
    if ( ((unsigned __int8)pIndices & 3) != 0 )
    {
      if ( v3 > 0 )
      {
        v6 = (unsigned __int16)(nFirstVertex + 2);
        v7 = pIndices + 2;
        do
        {
          *(v7 - 2) = v6 - 2;
          v7[1] = v6 - 2;
          *v7 = v6;
          v7[2] = v6;
          *(v7 - 1) = v6 - 1;
          v7[3] = v6 + 1;
          v6 += 4;
          v7 += 6;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else if ( v3 > 0 )
    {
      v4 = pIndices + 4;
      v5 = (nFirstVertex | (nFirstVertex << 16)) + 2;
      do
      {
        *((_DWORD *)v4 - 2) = v5 + 65534;
        *((_DWORD *)v4 - 1) = v5;
        *(_DWORD *)v4 = v5 + 196608;
        v4 += 6;
        v5 += 262148;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B6DB0
// Name: void GeneratePolygonIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GeneratePolygonIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // ecx
  unsigned __int16 *v4; // eax

  if ( pIndices != nullptr )
  {
    v3 = 0;
    if ( nIndexCount / 3 > 0 )
    {
      v4 = pIndices + 2;
      do
      {
        *(v4 - 2) = nFirstVertex;
        *(v4 - 1) = v3 + nFirstVertex + 1;
        *v4 = v3++ + nFirstVertex + 2;
        v4 += 3;
      }
      while ( v3 < nIndexCount / 3 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B6E10
// Name: void GenerateLineStripIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineStripIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  unsigned __int16 *v3; // esi
  int i; // ecx

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount / 2; v3 += 2 )
    {
      *v3 = i + nFirstVertex;
      v3[1] = i++ + nFirstVertex + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102B6E50
// Name: void GenerateLineLoopIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineLoopIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // edx
  unsigned __int16 *i; // ecx

  if ( pIndices != nullptr )
  {
    *pIndices = nIndexCount / 2 + nFirstVertex - 1;
    pIndices[1] = nFirstVertex;
    v3 = 1;
    for ( i = pIndices + 2; v3 < nIndexCount / 2; i += 2 )
    {
      *i = v3 + nFirstVertex - 1;
      i[1] = v3++ + nFirstVertex;
    }
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0057AB00
// Name: void GenerateSequentialIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateSequentialIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  int i; // eax

  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount; ++i )
      pIndices[i] = nFirstVertex + i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0057AB30
// Name: void GenerateQuadIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateQuadIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // esi
  unsigned __int16 *v4; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int16 *v7; // eax

  if ( pIndices != nullptr )
  {
    v3 = nIndexCount / 6;
    if ( ((unsigned __int8)pIndices & 3) != 0 )
    {
      if ( v3 > 0 )
      {
        v6 = (unsigned __int16)(nFirstVertex + 2);
        v7 = pIndices + 2;
        do
        {
          *(v7 - 2) = v6 - 2;
          v7[1] = v6 - 2;
          *v7 = v6;
          v7[2] = v6;
          *(v7 - 1) = v6 - 1;
          v7[3] = v6 + 1;
          v6 += 4;
          v7 += 6;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else if ( v3 > 0 )
    {
      v4 = pIndices + 4;
      v5 = (nFirstVertex | (nFirstVertex << 16)) + 2;
      do
      {
        *((_DWORD *)v4 - 2) = v5 + 65534;
        *((_DWORD *)v4 - 1) = v5;
        *(_DWORD *)v4 = v5 + 196608;
        v4 += 6;
        v5 += 262148;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0057ABE0
// Name: void GeneratePolygonIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GeneratePolygonIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // ecx
  unsigned __int16 *v4; // eax

  if ( pIndices != nullptr )
  {
    v3 = 0;
    if ( nIndexCount / 3 > 0 )
    {
      v4 = pIndices + 2;
      do
      {
        *(v4 - 2) = nFirstVertex;
        *(v4 - 1) = v3 + nFirstVertex + 1;
        *v4 = v3++ + nFirstVertex + 2;
        v4 += 3;
      }
      while ( v3 < nIndexCount / 3 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0057AC40
// Name: void GenerateLineStripIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineStripIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  unsigned __int16 *v3; // esi
  int i; // ecx

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount / 2; v3 += 2 )
    {
      *v3 = i + nFirstVertex;
      v3[1] = i++ + nFirstVertex + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0057AC80
// Name: void GenerateLineLoopIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineLoopIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // edx
  unsigned __int16 *i; // ecx

  if ( pIndices != nullptr )
  {
    *pIndices = nIndexCount / 2 + nFirstVertex - 1;
    pIndices[1] = nFirstVertex;
    v3 = 1;
    for ( i = pIndices + 2; v3 < nIndexCount / 2; i += 2 )
    {
      *i = v3 + nFirstVertex - 1;
      i[1] = v3++ + nFirstVertex;
    }
  }
}

} // namespace hlmv

// ============================================================
// Overlay from materialsystemtest (Missing functions)
// ============================================================
namespace materialsystemtest {

//------------------------------------------------------------------------------
// Address: 0x0040CAF0
// Name: void GenerateSequentialIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateSequentialIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  int i; // eax

  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount; ++i )
      pIndices[i] = nFirstVertex + i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CB20
// Name: void GenerateQuadIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateQuadIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // esi
  unsigned __int16 *v4; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int16 *v7; // eax

  if ( pIndices != nullptr )
  {
    v3 = nIndexCount / 6;
    if ( ((unsigned __int8)pIndices & 3) != 0 )
    {
      if ( v3 > 0 )
      {
        v6 = (unsigned __int16)(nFirstVertex + 2);
        v7 = pIndices + 2;
        do
        {
          *(v7 - 2) = v6 - 2;
          v7[1] = v6 - 2;
          *v7 = v6;
          v7[2] = v6;
          *(v7 - 1) = v6 - 1;
          v7[3] = v6 + 1;
          v6 += 4;
          v7 += 6;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else if ( v3 > 0 )
    {
      v4 = pIndices + 4;
      v5 = (nFirstVertex | (nFirstVertex << 16)) + 2;
      do
      {
        *((_DWORD *)v4 - 2) = v5 + 65534;
        *((_DWORD *)v4 - 1) = v5;
        *(_DWORD *)v4 = v5 + 196608;
        v4 += 6;
        v5 += 262148;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CBD0
// Name: void GeneratePolygonIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GeneratePolygonIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // ecx
  unsigned __int16 *v4; // eax

  if ( pIndices != nullptr )
  {
    v3 = 0;
    if ( nIndexCount / 3 > 0 )
    {
      v4 = pIndices + 2;
      do
      {
        *(v4 - 2) = nFirstVertex;
        *(v4 - 1) = v3 + nFirstVertex + 1;
        *v4 = v3++ + nFirstVertex + 2;
        v4 += 3;
      }
      while ( v3 < nIndexCount / 3 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CC30
// Name: void GenerateLineStripIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineStripIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  unsigned __int16 *v3; // esi
  int i; // ecx

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount / 2; v3 += 2 )
    {
      *v3 = i + nFirstVertex;
      v3[1] = i++ + nFirstVertex + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CC70
// Name: void GenerateLineLoopIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineLoopIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // edx
  unsigned __int16 *i; // ecx

  if ( pIndices != nullptr )
  {
    *pIndices = nIndexCount / 2 + nFirstVertex - 1;
    pIndices[1] = nFirstVertex;
    v3 = 1;
    for ( i = pIndices + 2; v3 < nIndexCount / 2; i += 2 )
    {
      *i = v3 + nFirstVertex - 1;
      i[1] = v3++ + nFirstVertex;
    }
  }
}

} // namespace materialsystemtest

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x005C8C50
// Name: void GenerateSequentialIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateSequentialIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  int i; // eax

  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount; ++i )
      pIndices[i] = nFirstVertex + i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C8C80
// Name: void GenerateQuadIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateQuadIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // esi
  unsigned __int16 *v4; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int16 *v7; // eax

  if ( pIndices != nullptr )
  {
    v3 = nIndexCount / 6;
    if ( ((unsigned __int8)pIndices & 3) != 0 )
    {
      if ( v3 > 0 )
      {
        v6 = (unsigned __int16)(nFirstVertex + 2);
        v7 = pIndices + 2;
        do
        {
          *(v7 - 2) = v6 - 2;
          v7[1] = v6 - 2;
          *v7 = v6;
          v7[2] = v6;
          *(v7 - 1) = v6 - 1;
          v7[3] = v6 + 1;
          v6 += 4;
          v7 += 6;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else if ( v3 > 0 )
    {
      v4 = pIndices + 4;
      v5 = (nFirstVertex | (nFirstVertex << 16)) + 2;
      do
      {
        *((_DWORD *)v4 - 2) = v5 + 65534;
        *((_DWORD *)v4 - 1) = v5;
        *(_DWORD *)v4 = v5 + 196608;
        v4 += 6;
        v5 += 262148;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C8D30
// Name: void GeneratePolygonIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GeneratePolygonIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // ecx
  unsigned __int16 *v4; // eax

  if ( pIndices != nullptr )
  {
    v3 = 0;
    if ( nIndexCount / 3 > 0 )
    {
      v4 = pIndices + 2;
      do
      {
        *(v4 - 2) = nFirstVertex;
        *(v4 - 1) = v3 + nFirstVertex + 1;
        *v4 = v3++ + nFirstVertex + 2;
        v4 += 3;
      }
      while ( v3 < nIndexCount / 3 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C8D90
// Name: void GenerateLineStripIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineStripIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  unsigned __int16 *v3; // esi
  int i; // ecx

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount / 2; v3 += 2 )
    {
      *v3 = i + nFirstVertex;
      v3[1] = i++ + nFirstVertex + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C8DD0
// Name: void GenerateLineLoopIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineLoopIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // edx
  unsigned __int16 *i; // ecx

  if ( pIndices != nullptr )
  {
    *pIndices = nIndexCount / 2 + nFirstVertex - 1;
    pIndices[1] = nFirstVertex;
    v3 = 1;
    for ( i = pIndices + 2; v3 < nIndexCount / 2; i += 2 )
    {
      *i = v3 + nFirstVertex - 1;
      i[1] = v3++ + nFirstVertex;
    }
  }
}

} // namespace mdlcompile

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x00420BB0
// Name: void GenerateSequentialIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateSequentialIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  int i; // eax

  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount; ++i )
      pIndices[i] = nFirstVertex + i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420BE0
// Name: void GenerateQuadIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateQuadIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // esi
  unsigned __int16 *v4; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int16 *v7; // eax

  if ( pIndices != nullptr )
  {
    v3 = nIndexCount / 6;
    if ( ((unsigned __int8)pIndices & 3) != 0 )
    {
      if ( v3 > 0 )
      {
        v6 = (unsigned __int16)(nFirstVertex + 2);
        v7 = pIndices + 2;
        do
        {
          *(v7 - 2) = v6 - 2;
          v7[1] = v6 - 2;
          *v7 = v6;
          v7[2] = v6;
          *(v7 - 1) = v6 - 1;
          v7[3] = v6 + 1;
          v6 += 4;
          v7 += 6;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else if ( v3 > 0 )
    {
      v4 = pIndices + 4;
      v5 = (nFirstVertex | (nFirstVertex << 16)) + 2;
      do
      {
        *((_DWORD *)v4 - 2) = v5 + 65534;
        *((_DWORD *)v4 - 1) = v5;
        *(_DWORD *)v4 = v5 + 196608;
        v4 += 6;
        v5 += 262148;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420C90
// Name: void GeneratePolygonIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GeneratePolygonIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // ecx
  unsigned __int16 *v4; // eax

  if ( pIndices != nullptr )
  {
    v3 = 0;
    if ( nIndexCount / 3 > 0 )
    {
      v4 = pIndices + 2;
      do
      {
        *(v4 - 2) = nFirstVertex;
        *(v4 - 1) = v3 + nFirstVertex + 1;
        *v4 = v3++ + nFirstVertex + 2;
        v4 += 3;
      }
      while ( v3 < nIndexCount / 3 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420CF0
// Name: void GenerateLineStripIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineStripIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  unsigned __int16 *v3; // esi
  int i; // ecx

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount / 2; v3 += 2 )
    {
      *v3 = i + nFirstVertex;
      v3[1] = i++ + nFirstVertex + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00420D30
// Name: void GenerateLineLoopIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineLoopIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // edx
  unsigned __int16 *i; // ecx

  if ( pIndices != nullptr )
  {
    *pIndices = nIndexCount / 2 + nFirstVertex - 1;
    pIndices[1] = nFirstVertex;
    v3 = 1;
    for ( i = pIndices + 2; v3 < nIndexCount / 2; i += 2 )
    {
      *i = v3 + nFirstVertex - 1;
      i[1] = v3++ + nFirstVertex;
    }
  }
}

} // namespace modelbrowser

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x0053B990
// Name: void GenerateSequentialIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateSequentialIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  int i; // eax

  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount; ++i )
      pIndices[i] = nFirstVertex + i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053B9C0
// Name: void GenerateQuadIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateQuadIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // esi
  unsigned __int16 *v4; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int16 *v7; // eax

  if ( pIndices != nullptr )
  {
    v3 = nIndexCount / 6;
    if ( ((unsigned __int8)pIndices & 3) != 0 )
    {
      if ( v3 > 0 )
      {
        v6 = (unsigned __int16)(nFirstVertex + 2);
        v7 = pIndices + 2;
        do
        {
          *(v7 - 2) = v6 - 2;
          v7[1] = v6 - 2;
          *v7 = v6;
          v7[2] = v6;
          *(v7 - 1) = v6 - 1;
          v7[3] = v6 + 1;
          v6 += 4;
          v7 += 6;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else if ( v3 > 0 )
    {
      v4 = pIndices + 4;
      v5 = (nFirstVertex | (nFirstVertex << 16)) + 2;
      do
      {
        *((_DWORD *)v4 - 2) = v5 + 65534;
        *((_DWORD *)v4 - 1) = v5;
        *(_DWORD *)v4 = v5 + 196608;
        v4 += 6;
        v5 += 262148;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053BA70
// Name: void GeneratePolygonIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GeneratePolygonIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // ecx
  unsigned __int16 *v4; // eax

  if ( pIndices != nullptr )
  {
    v3 = 0;
    if ( nIndexCount / 3 > 0 )
    {
      v4 = pIndices + 2;
      do
      {
        *(v4 - 2) = nFirstVertex;
        *(v4 - 1) = v3 + nFirstVertex + 1;
        *v4 = v3++ + nFirstVertex + 2;
        v4 += 3;
      }
      while ( v3 < nIndexCount / 3 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053BAD0
// Name: void GenerateLineStripIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineStripIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  unsigned __int16 *v3; // esi
  int i; // ecx

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount / 2; v3 += 2 )
    {
      *v3 = i + nFirstVertex;
      v3[1] = i++ + nFirstVertex + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0053BB10
// Name: void GenerateLineLoopIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineLoopIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // edx
  unsigned __int16 *i; // ecx

  if ( pIndices != nullptr )
  {
    *pIndices = nIndexCount / 2 + nFirstVertex - 1;
    pIndices[1] = nFirstVertex;
    v3 = 1;
    for ( i = pIndices + 2; v3 < nIndexCount / 2; i += 2 )
    {
      *i = v3 + nFirstVertex - 1;
      i[1] = v3++ + nFirstVertex;
    }
  }
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x0054F440
// Name: void GenerateSequentialIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateSequentialIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  int i; // eax

  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount; ++i )
      pIndices[i] = nFirstVertex + i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0054F470
// Name: void GenerateQuadIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateQuadIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // esi
  unsigned __int16 *v4; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int16 *v7; // eax

  if ( pIndices != nullptr )
  {
    v3 = nIndexCount / 6;
    if ( ((unsigned __int8)pIndices & 3) != 0 )
    {
      if ( v3 > 0 )
      {
        v6 = (unsigned __int16)(nFirstVertex + 2);
        v7 = pIndices + 2;
        do
        {
          *(v7 - 2) = v6 - 2;
          v7[1] = v6 - 2;
          *v7 = v6;
          v7[2] = v6;
          *(v7 - 1) = v6 - 1;
          v7[3] = v6 + 1;
          v6 += 4;
          v7 += 6;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else if ( v3 > 0 )
    {
      v4 = pIndices + 4;
      v5 = (nFirstVertex | (nFirstVertex << 16)) + 2;
      do
      {
        *((_DWORD *)v4 - 2) = v5 + 65534;
        *((_DWORD *)v4 - 1) = v5;
        *(_DWORD *)v4 = v5 + 196608;
        v4 += 6;
        v5 += 262148;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0054F520
// Name: void GeneratePolygonIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GeneratePolygonIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // ecx
  unsigned __int16 *v4; // eax

  if ( pIndices != nullptr )
  {
    v3 = 0;
    if ( nIndexCount / 3 > 0 )
    {
      v4 = pIndices + 2;
      do
      {
        *(v4 - 2) = nFirstVertex;
        *(v4 - 1) = v3 + nFirstVertex + 1;
        *v4 = v3++ + nFirstVertex + 2;
        v4 += 3;
      }
      while ( v3 < nIndexCount / 3 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0054F580
// Name: void GenerateLineStripIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineStripIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  unsigned __int16 *v3; // esi
  int i; // ecx

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount / 2; v3 += 2 )
    {
      *v3 = i + nFirstVertex;
      v3[1] = i++ + nFirstVertex + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0054F5C0
// Name: void GenerateLineLoopIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineLoopIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // edx
  unsigned __int16 *i; // ecx

  if ( pIndices != nullptr )
  {
    *pIndices = nIndexCount / 2 + nFirstVertex - 1;
    pIndices[1] = nFirstVertex;
    v3 = 1;
    for ( i = pIndices + 2; v3 < nIndexCount / 2; i += 2 )
    {
      *i = v3 + nFirstVertex - 1;
      i[1] = v3++ + nFirstVertex;
    }
  }
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x006065D0
// Name: void GenerateSequentialIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateSequentialIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  int i; // eax

  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount; ++i )
      pIndices[i] = nFirstVertex + i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00606600
// Name: void GenerateQuadIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateQuadIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // esi
  unsigned __int16 *v4; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int16 *v7; // eax

  if ( pIndices != nullptr )
  {
    v3 = nIndexCount / 6;
    if ( ((unsigned __int8)pIndices & 3) != 0 )
    {
      if ( v3 > 0 )
      {
        v6 = (unsigned __int16)(nFirstVertex + 2);
        v7 = pIndices + 2;
        do
        {
          *(v7 - 2) = v6 - 2;
          v7[1] = v6 - 2;
          *v7 = v6;
          v7[2] = v6;
          *(v7 - 1) = v6 - 1;
          v7[3] = v6 + 1;
          v6 += 4;
          v7 += 6;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else if ( v3 > 0 )
    {
      v4 = pIndices + 4;
      v5 = (nFirstVertex | (nFirstVertex << 16)) + 2;
      do
      {
        *((_DWORD *)v4 - 2) = v5 + 65534;
        *((_DWORD *)v4 - 1) = v5;
        *(_DWORD *)v4 = v5 + 196608;
        v4 += 6;
        v5 += 262148;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006066B0
// Name: void GeneratePolygonIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GeneratePolygonIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // ecx
  unsigned __int16 *v4; // eax

  if ( pIndices != nullptr )
  {
    v3 = 0;
    if ( nIndexCount / 3 > 0 )
    {
      v4 = pIndices + 2;
      do
      {
        *(v4 - 2) = nFirstVertex;
        *(v4 - 1) = v3 + nFirstVertex + 1;
        *v4 = v3++ + nFirstVertex + 2;
        v4 += 3;
      }
      while ( v3 < nIndexCount / 3 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00606710
// Name: void GenerateLineStripIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineStripIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  unsigned __int16 *v3; // esi
  int i; // ecx

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount / 2; v3 += 2 )
    {
      *v3 = i + nFirstVertex;
      v3[1] = i++ + nFirstVertex + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00606750
// Name: void GenerateLineLoopIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineLoopIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // edx
  unsigned __int16 *i; // ecx

  if ( pIndices != nullptr )
  {
    *pIndices = nIndexCount / 2 + nFirstVertex - 1;
    pIndices[1] = nFirstVertex;
    v3 = 1;
    for ( i = pIndices + 2; v3 < nIndexCount / 2; i += 2 )
    {
      *i = v3 + nFirstVertex - 1;
      i[1] = v3++ + nFirstVertex;
    }
  }
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x005511E0
// Name: void GenerateSequentialIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateSequentialIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  int i; // eax

  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount; ++i )
      pIndices[i] = nFirstVertex + i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00551210
// Name: void GenerateQuadIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateQuadIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // esi
  unsigned __int16 *v4; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int16 *v7; // eax

  if ( pIndices != nullptr )
  {
    v3 = nIndexCount / 6;
    if ( ((unsigned __int8)pIndices & 3) != 0 )
    {
      if ( v3 > 0 )
      {
        v6 = (unsigned __int16)(nFirstVertex + 2);
        v7 = pIndices + 2;
        do
        {
          *(v7 - 2) = v6 - 2;
          v7[1] = v6 - 2;
          *v7 = v6;
          v7[2] = v6;
          *(v7 - 1) = v6 - 1;
          v7[3] = v6 + 1;
          v6 += 4;
          v7 += 6;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else if ( v3 > 0 )
    {
      v4 = pIndices + 4;
      v5 = (nFirstVertex | (nFirstVertex << 16)) + 2;
      do
      {
        *((_DWORD *)v4 - 2) = v5 + 65534;
        *((_DWORD *)v4 - 1) = v5;
        *(_DWORD *)v4 = v5 + 196608;
        v4 += 6;
        v5 += 262148;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005512C0
// Name: void GeneratePolygonIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GeneratePolygonIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // ecx
  unsigned __int16 *v4; // eax

  if ( pIndices != nullptr )
  {
    v3 = 0;
    if ( nIndexCount / 3 > 0 )
    {
      v4 = pIndices + 2;
      do
      {
        *(v4 - 2) = nFirstVertex;
        *(v4 - 1) = v3 + nFirstVertex + 1;
        *v4 = v3++ + nFirstVertex + 2;
        v4 += 3;
      }
      while ( v3 < nIndexCount / 3 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00551320
// Name: void GenerateLineStripIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineStripIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  unsigned __int16 *v3; // esi
  int i; // ecx

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount / 2; v3 += 2 )
    {
      *v3 = i + nFirstVertex;
      v3[1] = i++ + nFirstVertex + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00551360
// Name: void GenerateLineLoopIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineLoopIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // edx
  unsigned __int16 *i; // ecx

  if ( pIndices != nullptr )
  {
    *pIndices = nIndexCount / 2 + nFirstVertex - 1;
    pIndices[1] = nFirstVertex;
    v3 = 1;
    for ( i = pIndices + 2; v3 < nIndexCount / 2; i += 2 )
    {
      *i = v3 + nFirstVertex - 1;
      i[1] = v3++ + nFirstVertex;
    }
  }
}

} // namespace sfmgen

// ============================================================
// Overlay from shaderapidx10 (Missing functions)
// ============================================================
namespace shaderapidx10 {

//------------------------------------------------------------------------------
// Address: 0x10039610
// Name: void GenerateSequentialIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateSequentialIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  int i; // eax

  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount; ++i )
      pIndices[i] = nFirstVertex + i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039650
// Name: void GenerateQuadIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateQuadIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  unsigned __int16 *v3; // ecx
  int v4; // esi
  unsigned __int16 *v5; // eax
  int v6; // ecx
  int v7; // eax

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    v4 = nIndexCount / 6;
    if ( ((unsigned __int8)pIndices & 3) != 0 )
    {
      if ( v4 > 0 )
      {
        v7 = (unsigned __int16)(nFirstVertex + 2);
        do
        {
          *v3 = v7 - 2;
          v3[3] = v7 - 2;
          v3[2] = v7;
          v3[4] = v7;
          v3[1] = v7 - 1;
          v3[5] = v7 + 1;
          v7 += 4;
          v3 += 6;
          --v4;
        }
        while ( v4 != 0 );
      }
    }
    else if ( v4 > 0 )
    {
      v5 = pIndices + 4;
      v6 = (nFirstVertex | (nFirstVertex << 16)) + 2;
      do
      {
        *((_DWORD *)v5 - 2) = v6 + 65534;
        *((_DWORD *)v5 - 1) = v6;
        *(_DWORD *)v5 = v6 + 196608;
        v5 += 6;
        v6 += 262148;
        --v4;
      }
      while ( v4 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039700
// Name: void GeneratePolygonIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GeneratePolygonIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  unsigned __int16 *v3; // ecx
  int i; // eax

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount / 3; v3 += 3 )
    {
      *v3 = nFirstVertex;
      v3[1] = i + nFirstVertex + 1;
      v3[2] = i++ + nFirstVertex + 2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039760
// Name: void GenerateLineStripIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineStripIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  unsigned __int16 *v3; // esi
  int i; // ecx

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount / 2; v3 += 2 )
    {
      *v3 = i + nFirstVertex;
      v3[1] = i++ + nFirstVertex + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100397A0
// Name: void GenerateLineLoopIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineLoopIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // edx
  unsigned __int16 *i; // ecx

  if ( pIndices != nullptr )
  {
    *pIndices = nIndexCount / 2 + nFirstVertex - 1;
    pIndices[1] = nFirstVertex;
    v3 = 1;
    for ( i = pIndices + 2; v3 < nIndexCount / 2; i += 2 )
    {
      *i = v3 + nFirstVertex - 1;
      i[1] = v3++ + nFirstVertex;
    }
  }
}

} // namespace shaderapidx10

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x005C1A70
// Name: void GenerateSequentialIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateSequentialIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  int i; // eax

  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount; ++i )
      pIndices[i] = nFirstVertex + i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C1AA0
// Name: void GenerateQuadIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateQuadIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // esi
  unsigned __int16 *v4; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int16 *v7; // eax

  if ( pIndices != nullptr )
  {
    v3 = nIndexCount / 6;
    if ( ((unsigned __int8)pIndices & 3) != 0 )
    {
      if ( v3 > 0 )
      {
        v6 = (unsigned __int16)(nFirstVertex + 2);
        v7 = pIndices + 2;
        do
        {
          *(v7 - 2) = v6 - 2;
          v7[1] = v6 - 2;
          *v7 = v6;
          v7[2] = v6;
          *(v7 - 1) = v6 - 1;
          v7[3] = v6 + 1;
          v6 += 4;
          v7 += 6;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else if ( v3 > 0 )
    {
      v4 = pIndices + 4;
      v5 = (nFirstVertex | (nFirstVertex << 16)) + 2;
      do
      {
        *((_DWORD *)v4 - 2) = v5 + 65534;
        *((_DWORD *)v4 - 1) = v5;
        *(_DWORD *)v4 = v5 + 196608;
        v4 += 6;
        v5 += 262148;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C1B50
// Name: void GeneratePolygonIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GeneratePolygonIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // ecx
  unsigned __int16 *v4; // eax

  if ( pIndices != nullptr )
  {
    v3 = 0;
    if ( nIndexCount / 3 > 0 )
    {
      v4 = pIndices + 2;
      do
      {
        *(v4 - 2) = nFirstVertex;
        *(v4 - 1) = v3 + nFirstVertex + 1;
        *v4 = v3++ + nFirstVertex + 2;
        v4 += 3;
      }
      while ( v3 < nIndexCount / 3 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C1BB0
// Name: void GenerateLineStripIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineStripIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  unsigned __int16 *v3; // esi
  int i; // ecx

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount / 2; v3 += 2 )
    {
      *v3 = i + nFirstVertex;
      v3[1] = i++ + nFirstVertex + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005C1BF0
// Name: void GenerateLineLoopIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineLoopIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // edx
  unsigned __int16 *i; // ecx

  if ( pIndices != nullptr )
  {
    *pIndices = nIndexCount / 2 + nFirstVertex - 1;
    pIndices[1] = nFirstVertex;
    v3 = 1;
    for ( i = pIndices + 2; v3 < nIndexCount / 2; i += 2 )
    {
      *i = v3 + nFirstVertex - 1;
      i[1] = v3++ + nFirstVertex;
    }
  }
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00548130
// Name: void GenerateSequentialIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateSequentialIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  int i; // eax

  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount; ++i )
      pIndices[i] = nFirstVertex + i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00548160
// Name: void GenerateQuadIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateQuadIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // esi
  unsigned __int16 *v4; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int16 *v7; // eax

  if ( pIndices != nullptr )
  {
    v3 = nIndexCount / 6;
    if ( ((unsigned __int8)pIndices & 3) != 0 )
    {
      if ( v3 > 0 )
      {
        v6 = (unsigned __int16)(nFirstVertex + 2);
        v7 = pIndices + 2;
        do
        {
          *(v7 - 2) = v6 - 2;
          v7[1] = v6 - 2;
          *v7 = v6;
          v7[2] = v6;
          *(v7 - 1) = v6 - 1;
          v7[3] = v6 + 1;
          v6 += 4;
          v7 += 6;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else if ( v3 > 0 )
    {
      v4 = pIndices + 4;
      v5 = (nFirstVertex | (nFirstVertex << 16)) + 2;
      do
      {
        *((_DWORD *)v4 - 2) = v5 + 65534;
        *((_DWORD *)v4 - 1) = v5;
        *(_DWORD *)v4 = v5 + 196608;
        v4 += 6;
        v5 += 262148;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00548210
// Name: void GeneratePolygonIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GeneratePolygonIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // ecx
  unsigned __int16 *v4; // eax

  if ( pIndices != nullptr )
  {
    v3 = 0;
    if ( nIndexCount / 3 > 0 )
    {
      v4 = pIndices + 2;
      do
      {
        *(v4 - 2) = nFirstVertex;
        *(v4 - 1) = v3 + nFirstVertex + 1;
        *v4 = v3++ + nFirstVertex + 2;
        v4 += 3;
      }
      while ( v3 < nIndexCount / 3 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00548270
// Name: void GenerateLineStripIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineStripIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  unsigned __int16 *v3; // esi
  int i; // ecx

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount / 2; v3 += 2 )
    {
      *v3 = i + nFirstVertex;
      v3[1] = i++ + nFirstVertex + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005482B0
// Name: void GenerateLineLoopIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineLoopIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // edx
  unsigned __int16 *i; // ecx

  if ( pIndices != nullptr )
  {
    *pIndices = nIndexCount / 2 + nFirstVertex - 1;
    pIndices[1] = nFirstVertex;
    v3 = 1;
    for ( i = pIndices + 2; v3 < nIndexCount / 2; i += 2 )
    {
      *i = v3 + nFirstVertex - 1;
      i[1] = v3++ + nFirstVertex;
    }
  }
}

} // namespace uvlightmap

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x1004A220
// Name: void GenerateSequentialIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateSequentialIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  int i; // eax

  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount; ++i )
      pIndices[i] = nFirstVertex + i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A250
// Name: void GenerateQuadIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateQuadIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // esi
  unsigned __int16 *v4; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int16 *v7; // eax

  if ( pIndices != nullptr )
  {
    v3 = nIndexCount / 6;
    if ( ((unsigned __int8)pIndices & 3) != 0 )
    {
      if ( v3 > 0 )
      {
        v6 = (unsigned __int16)(nFirstVertex + 2);
        v7 = pIndices + 2;
        do
        {
          *(v7 - 2) = v6 - 2;
          v7[1] = v6 - 2;
          *v7 = v6;
          v7[2] = v6;
          *(v7 - 1) = v6 - 1;
          v7[3] = v6 + 1;
          v6 += 4;
          v7 += 6;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else if ( v3 > 0 )
    {
      v4 = pIndices + 4;
      v5 = (nFirstVertex | (nFirstVertex << 16)) + 2;
      do
      {
        *((_DWORD *)v4 - 2) = v5 + 65534;
        *((_DWORD *)v4 - 1) = v5;
        *(_DWORD *)v4 = v5 + 196608;
        v4 += 6;
        v5 += 262148;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A300
// Name: void GeneratePolygonIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GeneratePolygonIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // ecx
  unsigned __int16 *v4; // eax

  if ( pIndices != nullptr )
  {
    v3 = 0;
    if ( nIndexCount / 3 > 0 )
    {
      v4 = pIndices + 2;
      do
      {
        *(v4 - 2) = nFirstVertex;
        *(v4 - 1) = v3 + nFirstVertex + 1;
        *v4 = v3++ + nFirstVertex + 2;
        v4 += 3;
      }
      while ( v3 < nIndexCount / 3 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A360
// Name: void GenerateLineStripIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineStripIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  unsigned __int16 *v3; // esi
  int i; // ecx

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount / 2; v3 += 2 )
    {
      *v3 = i + nFirstVertex;
      v3[1] = i++ + nFirstVertex + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1004A3A0
// Name: void GenerateLineLoopIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineLoopIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // edx
  unsigned __int16 *i; // ecx

  if ( pIndices != nullptr )
  {
    *pIndices = nIndexCount / 2 + nFirstVertex - 1;
    pIndices[1] = nFirstVertex;
    v3 = 1;
    for ( i = pIndices + 2; v3 < nIndexCount / 2; i += 2 )
    {
      *i = v3 + nFirstVertex - 1;
      i[1] = v3++ + nFirstVertex;
    }
  }
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00468CE0
// Name: void GenerateSequentialIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateSequentialIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  int i; // eax

  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount; ++i )
      pIndices[i] = nFirstVertex + i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468D20
// Name: void GenerateQuadIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateQuadIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  unsigned __int16 *v3; // ecx
  int v4; // esi
  unsigned __int16 *v5; // eax
  int v6; // ecx
  int v7; // eax

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    v4 = nIndexCount / 6;
    if ( ((unsigned __int8)pIndices & 3) != 0 )
    {
      if ( v4 > 0 )
      {
        v7 = (unsigned __int16)(nFirstVertex + 2);
        do
        {
          *v3 = v7 - 2;
          v3[3] = v7 - 2;
          v3[2] = v7;
          v3[4] = v7;
          v3[1] = v7 - 1;
          v3[5] = v7 + 1;
          v7 += 4;
          v3 += 6;
          --v4;
        }
        while ( v4 != 0 );
      }
    }
    else if ( v4 > 0 )
    {
      v5 = pIndices + 4;
      v6 = (nFirstVertex | (nFirstVertex << 16)) + 2;
      do
      {
        *((_DWORD *)v5 - 2) = v6 + 65534;
        *((_DWORD *)v5 - 1) = v6;
        *(_DWORD *)v5 = v6 + 196608;
        v5 += 6;
        v6 += 262148;
        --v4;
      }
      while ( v4 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468DD0
// Name: void GeneratePolygonIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GeneratePolygonIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  unsigned __int16 *v3; // ecx
  int i; // eax

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount / 3; v3 += 3 )
    {
      *v3 = nFirstVertex;
      v3[1] = i + nFirstVertex + 1;
      v3[2] = i++ + nFirstVertex + 2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468E30
// Name: void GenerateLineStripIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineStripIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  unsigned __int16 *v3; // esi
  int i; // ecx

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount / 2; v3 += 2 )
    {
      *v3 = i + nFirstVertex;
      v3[1] = i++ + nFirstVertex + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00468E70
// Name: void GenerateLineLoopIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineLoopIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // edx
  unsigned __int16 *i; // ecx

  if ( pIndices != nullptr )
  {
    *pIndices = nIndexCount / 2 + nFirstVertex - 1;
    pIndices[1] = nFirstVertex;
    v3 = 1;
    for ( i = pIndices + 2; v3 < nIndexCount / 2; i += 2 )
    {
      *i = v3 + nFirstVertex - 1;
      i[1] = v3++ + nFirstVertex;
    }
  }
}

} // namespace vgui_perftest

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00650FA0
// Name: void GenerateSequentialIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateSequentialIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  int i; // eax

  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount; ++i )
      pIndices[i] = nFirstVertex + i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00650FD0
// Name: void GenerateQuadIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateQuadIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // esi
  unsigned __int16 *v4; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int16 *v7; // eax

  if ( pIndices != nullptr )
  {
    v3 = nIndexCount / 6;
    if ( ((unsigned __int8)pIndices & 3) != 0 )
    {
      if ( v3 > 0 )
      {
        v6 = (unsigned __int16)(nFirstVertex + 2);
        v7 = pIndices + 2;
        do
        {
          *(v7 - 2) = v6 - 2;
          v7[1] = v6 - 2;
          *v7 = v6;
          v7[2] = v6;
          *(v7 - 1) = v6 - 1;
          v7[3] = v6 + 1;
          v6 += 4;
          v7 += 6;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else if ( v3 > 0 )
    {
      v4 = pIndices + 4;
      v5 = (nFirstVertex | (nFirstVertex << 16)) + 2;
      do
      {
        *((_DWORD *)v4 - 2) = v5 + 65534;
        *((_DWORD *)v4 - 1) = v5;
        *(_DWORD *)v4 = v5 + 196608;
        v4 += 6;
        v5 += 262148;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00651080
// Name: void GeneratePolygonIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GeneratePolygonIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // ecx
  unsigned __int16 *v4; // eax

  if ( pIndices != nullptr )
  {
    v3 = 0;
    if ( nIndexCount / 3 > 0 )
    {
      v4 = pIndices + 2;
      do
      {
        *(v4 - 2) = nFirstVertex;
        *(v4 - 1) = v3 + nFirstVertex + 1;
        *v4 = v3++ + nFirstVertex + 2;
        v4 += 3;
      }
      while ( v3 < nIndexCount / 3 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x006510E0
// Name: void GenerateLineStripIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineStripIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  unsigned __int16 *v3; // esi
  int i; // ecx

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount / 2; v3 += 2 )
    {
      *v3 = i + nFirstVertex;
      v3[1] = i++ + nFirstVertex + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00651120
// Name: void GenerateLineLoopIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineLoopIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // edx
  unsigned __int16 *i; // ecx

  if ( pIndices != nullptr )
  {
    *pIndices = nIndexCount / 2 + nFirstVertex - 1;
    pIndices[1] = nFirstVertex;
    v3 = 1;
    for ( i = pIndices + 2; v3 < nIndexCount / 2; i += 2 )
    {
      *i = v3 + nFirstVertex - 1;
      i[1] = v3++ + nFirstVertex;
    }
  }
}

} // namespace vmap

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x1036F730
// Name: void GenerateSequentialIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateSequentialIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  int i; // eax

  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount; ++i )
      pIndices[i] = nFirstVertex + i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036F760
// Name: void GenerateQuadIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateQuadIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // esi
  unsigned __int16 *v4; // eax
  int v5; // ecx
  int v6; // ecx
  unsigned __int16 *v7; // eax

  if ( pIndices != nullptr )
  {
    v3 = nIndexCount / 6;
    if ( ((unsigned __int8)pIndices & 3) != 0 )
    {
      if ( v3 > 0 )
      {
        v6 = (unsigned __int16)(nFirstVertex + 2);
        v7 = pIndices + 2;
        do
        {
          *(v7 - 2) = v6 - 2;
          v7[1] = v6 - 2;
          *v7 = v6;
          v7[2] = v6;
          *(v7 - 1) = v6 - 1;
          v7[3] = v6 + 1;
          v6 += 4;
          v7 += 6;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else if ( v3 > 0 )
    {
      v4 = pIndices + 4;
      v5 = (nFirstVertex | (nFirstVertex << 16)) + 2;
      do
      {
        *((_DWORD *)v4 - 2) = v5 + 65534;
        *((_DWORD *)v4 - 1) = v5;
        *(_DWORD *)v4 = v5 + 196608;
        v4 += 6;
        v5 += 262148;
        --v3;
      }
      while ( v3 != 0 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036F810
// Name: void GeneratePolygonIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GeneratePolygonIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // ecx
  unsigned __int16 *v4; // eax

  if ( pIndices != nullptr )
  {
    v3 = 0;
    if ( nIndexCount / 3 > 0 )
    {
      v4 = pIndices + 2;
      do
      {
        *(v4 - 2) = nFirstVertex;
        *(v4 - 1) = v3 + nFirstVertex + 1;
        *v4 = v3++ + nFirstVertex + 2;
        v4 += 3;
      }
      while ( v3 < nIndexCount / 3 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036F870
// Name: void GenerateLineStripIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineStripIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, __int16 nFirstVertex)
{
  unsigned __int16 *v3; // esi
  int i; // ecx

  v3 = pIndices;
  if ( pIndices != nullptr )
  {
    for ( i = 0; i < nIndexCount / 2; v3 += 2 )
    {
      *v3 = i + nFirstVertex;
      v3[1] = i++ + nFirstVertex + 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1036F8B0
// Name: void GenerateLineLoopIndexBuffer(unsigned short __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateLineLoopIndexBuffer(unsigned __int16 *pIndices, int nIndexCount, unsigned __int16 nFirstVertex)
{
  int v3; // edx
  unsigned __int16 *i; // ecx

  if ( pIndices != nullptr )
  {
    *pIndices = nIndexCount / 2 + nFirstVertex - 1;
    pIndices[1] = nFirstVertex;
    v3 = 1;
    for ( i = pIndices + 2; v3 < nIndexCount / 2; i += 2 )
    {
      *i = v3 + nFirstVertex - 1;
      i[1] = v3++ + nFirstVertex;
    }
  }
}

} // namespace client
