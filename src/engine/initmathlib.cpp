// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/initmathlib.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x101980E0
// Name: void InitMathlib(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitMathlib()
{
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: s_bAllow3DNow,
    bAllowSSE: true,
    bAllowSSE2: s_bAllowSSE2,
    bAllowMMX: true);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10198510
// Name: void InitMathlib(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitMathlib()
{
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: s_bAllow3DNow,
    bAllowSSE: true,
    bAllowSSE2: s_bAllowSSE2,
    bAllowMMX: true);
}

} // namespace engine_xlsp
