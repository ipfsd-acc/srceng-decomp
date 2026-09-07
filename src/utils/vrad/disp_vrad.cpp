// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vrad/disp_vrad.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100049E0
// Name: void SmoothNeighboringDispSurfNormals(class CCoreDispInfo __near * __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SmoothNeighboringDispSurfNormals(CCoreDispInfo **ppListBase, int listSize)
{
  SmoothDispSurfNormals(ppListBase, nListSize: listSize);
}
