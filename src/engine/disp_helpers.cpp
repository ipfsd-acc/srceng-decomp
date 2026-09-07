// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/disp_helpers.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1015E410
// Name: void CalcMaxNumVertsAndIndices(int,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalcMaxNumVertsAndIndices(char power, int *nVerts, int *nIndices)
{
  *nVerts = ((1 << power) + 1) * ((1 << power) + 1);
  *nIndices = (1 << power) * (6 * ((1 << power) + 1) - 6);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1015E6B0
// Name: void CalcMaxNumVertsAndIndices(int,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CalcMaxNumVertsAndIndices(char power, int *nVerts, int *nIndices)
{
  *nVerts = ((1 << power) + 1) * ((1 << power) + 1);
  *nIndices = (1 << power) * (6 * ((1 << power) + 1) - 6);
}

} // namespace engine_xlsp
