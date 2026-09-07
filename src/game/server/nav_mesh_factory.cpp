// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/nav_mesh_factory.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10323390
// Name: class CNavMesh __near * NavMeshFactory(void)
// Source: json
//------------------------------------------------------------------------------
CSNavMesh *__cdecl NavMeshFactory()
{
  CSNavMesh *v0; // eax

  v0 = (CSNavMesh *)operator new(nSize: 0x5D0u);
  if ( v0 != nullptr )
    return CSNavMesh::CSNavMesh(this: v0);
  else
    return nullptr;
}
