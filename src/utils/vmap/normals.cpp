// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmap/normals.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00428B10
// Name: void SaveVertexNormals(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SaveVertexNormals()
{
  int v0; // edx
  int v1; // edi
  __int16 *p_numedges; // esi
  int v3; // ebx
  int v4; // ecx
  dplane_t *v5; // eax
  Vector *v6; // ecx
  int i; // [esp+4h] [ebp-4h]

  v0 = 0;
  v1 = 0;
  g_numvertnormalindices = 0;
  g_numvertnormals = 0;
  i = 0;
  if ( numfaces > 0 )
  {
    p_numedges = &dfaces[0].numedges;
    do
    {
      v3 = 0;
      if ( *p_numedges > 0 )
      {
        do
        {
          if ( v1 == 256000 )
          {
            _Error(a1: "g_numvertnormalindices == MAX_MAP_VERTNORMALINDICES (%d)", 256000);
            v1 = g_numvertnormalindices;
            v0 = g_numvertnormals;
          }
          v4 = *p_numedges;
          g_vertnormalindices[v1++] = v0;
          ++v3;
          g_numvertnormalindices = v1;
        }
        while ( v3 < v4 );
      }
      if ( v0 == 256000 )
      {
        _Error(a1: "g_numvertnormals == MAX_MAP_VERTNORMALS (%d)", 256000);
        v1 = g_numvertnormalindices;
        v0 = g_numvertnormals;
      }
      v5 = &dplanes[(unsigned __int16)*(p_numedges - 4)];
      v6 = &g_vertnormals[v0++];
      p_numedges += 28;
      v6->x = v5->normal.x;
      g_numvertnormals = v0;
      v6->y = v5->normal.y;
      v6->z = v5->normal.z;
      ++i;
    }
    while ( i < numfaces );
  }
}
