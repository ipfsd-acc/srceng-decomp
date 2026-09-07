// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/interpolatortypes.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00403A80
// Name: int Interpolator_InterpolatorForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Interpolator_InterpolatorForName(const char *name)
{
  InterpolatorNameMap_t *v1; // esi

  v1 = g_InterpolatorNameMap;
  while ( _stricmp(dst: name, src: v1->name) != 0 )
  {
    if ( (int)++v1 >= (int)g_CurveNameMap )
      return 0;
  }
  return v1->type;
}

//------------------------------------------------------------------------------
// Address: 0x00403AC0
// Name: int Interpolator_CurveTypeForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Interpolator_CurveTypeForName(const char *name)
{
  char v1; // bl
  char *v2; // esi
  char v3; // bl
  char sz[132]; // [esp+4h] [ebp-84h] BYREF

  V_strncpy(pDest: &sz[4], pSrc: name, maxLen: 128);
  v1 = 0;
  if ( V_strnicmp(s1: &sz[4], s2: "curve_", n: 6) == 0 )
  {
    v2 = V_stristr(pStr: &sz[10], pSearch: "_to_curve_");
    v3 = *v2;
    *v2 = 0;
    Interpolator_InterpolatorForName(name: &sz[10]);
    *v2 = v3;
    return Interpolator_InterpolatorForName(name: v2 + 10);
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x00403B50
// Name: char const __near * Interpolator_NameForCurveType(int,bool)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Interpolator_NameForCurveType(__int16 type, bool printname)
{
  const char *name; // edx
  const char *v3; // edx
  const char *v4; // eax

  if ( printname )
  {
    if ( (unsigned __int8)type >= 0x10u )
      v3 = g_InterpolatorNameMap[0].printname;
    else
      v3 = g_InterpolatorNameMap[(unsigned __int8)type].printname;
    if ( HIBYTE(type) >= 0x10u )
      v4 = g_InterpolatorNameMap[0].printname;
    else
      v4 = g_InterpolatorNameMap[HIBYTE(type)].printname;
    V_snprintf(pDest: outname, maxLen: 256, pFormat: "%s <-> %s", v4, v3);
  }
  else
  {
    if ( (unsigned __int8)type >= 0x10u )
      name = g_InterpolatorNameMap[0].name;
    else
      name = g_InterpolatorNameMap[(unsigned __int8)type].name;
    if ( HIBYTE(type) >= 0x10u )
      V_snprintf(pDest: outname, maxLen: 256, pFormat: "curve_%s_to_curve_%s", g_InterpolatorNameMap[0].name, name);
    else
      V_snprintf(
        pDest: outname,
        maxLen: 256,
        pFormat: "curve_%s_to_curve_%s",
        g_InterpolatorNameMap[HIBYTE(type)].name,
        name);
  }
  return outname;
}

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x0040C290
// Name: float ExponentialDecay(float,float,float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl ExponentialDecay(float decayTo, float decayTime, float dt)
{
  long double v3; // st7
  long double v4; // rt1

  v3 = __FYL2X__(decayTo, 0.6931471805599453094) / decayTime * dt * 1.442695040888963407;
  v4 = rint(v3);
  return __FSCALE__(__F2XM1__(v3 - v4) + 1.0, v4);
}

//------------------------------------------------------------------------------
// Address: 0x0040C2C0
// Name: char const __near * Interpolator_NameForCurveType(int,bool)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Interpolator_NameForCurveType(__int16 type, bool printname)
{
  const char *name; // ecx
  const char *v3; // ecx
  const char *v4; // eax

  if ( printname )
  {
    if ( (unsigned __int8)type >= 0x10u )
      v3 = g_InterpolatorNameMap[0].printname;
    else
      v3 = g_InterpolatorNameMap[(unsigned __int8)type].printname;
    if ( HIBYTE(type) >= 0x10u )
      v4 = g_InterpolatorNameMap[0].printname;
    else
      v4 = g_InterpolatorNameMap[HIBYTE(type)].printname;
    V_snprintf(pDest: outname, maxLen: 256, pFormat: "%s <-> %s", v4, v3);
  }
  else
  {
    if ( (unsigned __int8)type >= 0x10u )
      name = g_InterpolatorNameMap[0].name;
    else
      name = g_InterpolatorNameMap[(unsigned __int8)type].name;
    if ( HIBYTE(type) >= 0x10u )
      V_snprintf(pDest: outname, maxLen: 256, pFormat: "curve_%s_to_curve_%s", g_InterpolatorNameMap[0].name, name);
    else
      V_snprintf(
        pDest: outname,
        maxLen: 256,
        pFormat: "curve_%s_to_curve_%s",
        g_InterpolatorNameMap[HIBYTE(type)].name,
        name);
  }
  return outname;
}

//------------------------------------------------------------------------------
// Address: 0x0040C380
// Name: void Interpolator_CurveInterpolatorsForType(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_CurveInterpolatorsForType(__int16 type, int *inbound, int *outbound)
{
  *inbound = HIBYTE(type);
  *outbound = (unsigned __int8)type;
}

//------------------------------------------------------------------------------
// Address: 0x0040C3B0
// Name: void Interpolator_GetKochanekBartelsParams(int,float __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_GetKochanekBartelsParams(
        int interpolationType,
        float *tension,
        float *bias,
        float *continuity)
{
  float *v4; // ecx
  float *v5; // edx
  float *v6; // eax
  int v7; // xmm1_4

  if ( interpolationType == 7 )
  {
    v7 = 0;
    goto LABEL_8;
  }
  if ( interpolationType == 8 )
  {
    v7 = -1082130432;
LABEL_8:
    v5 = continuity;
    v4 = bias;
    v6 = tension;
    goto LABEL_9;
  }
  v4 = bias;
  v5 = continuity;
  v6 = tension;
  if ( interpolationType != 9 )
  {
    *tension = 0.0;
    *bias = 0.0;
    *continuity = 0.0;
    return;
  }
  v7 = 1065353216;
LABEL_9:
  *v6 = 0.76999998;
  *(_DWORD *)v4 = v7;
  *v5 = 0.76999998;
}

//------------------------------------------------------------------------------
// Address: 0x0040C420
// Name: void Interpolator_CurveInterpolate(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl Interpolator_CurveInterpolate(
        float interpolationType,
        const Vector *vPre,
        const Vector *vStart,
        const Vector *vEnd,
        const Vector *vNext,
        float f,
        float vOut)
{
  int v7; // eax
  Vector *v8; // esi
  double v9; // xmm0_8
  float v10; // xmm0_4
  const Vector *v11; // eax
  const Vector *v12; // ecx
  double v13; // xmm0_8
  float v14; // xmm1_4
  const Vector *v15; // eax
  const Vector *v16; // ecx
  long double y; // st7
  const Vector *v18; // edi
  float decayTime; // xmm0_4
  long double v20; // st7
  long double tension; // [esp+24h] [ebp-8h] OVERLAPPED BYREF

  v7 = LODWORD(interpolationType);
  v8 = (Vector *)LODWORD(vOut);
  *(_DWORD *)LODWORD(vOut) = 0;
  v8->y = 0.0;
  v8->z = 0.0;
  switch ( v7 )
  {
    case 0:
    case 1:
      goto $LN15;
    case 2:
      v9 = f * 3.141592653589793 * 0.5;
      __libm_sse2_sin(x: tension);
      v10 = v9;
      goto LABEL_6;
    case 3:
      v13 = f * 3.141592653589793 * 0.5 + 1.570796326794897;
      __libm_sse2_sin(x: tension);
      v10 = 1.0 - v13;
LABEL_6:
      v11 = vStart;
      v12 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v10) + vStart->x;
      v8->y = (float)((float)(v12->y - v11->y) * v10) + v11->y;
      v8->z = (float)((float)(v12->z - v11->z) * v10) + v11->z;
      return;
    case 4:
      v14 = (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f);
      goto LABEL_9;
    case 5:
      BSpline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      return;
    case 6:
      v14 = f;
LABEL_9:
      v15 = vStart;
      v16 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v14) + vStart->x;
      v8->y = (float)((float)(v16->y - v15->y) * v14) + v15->y;
      v8->z = (float)((float)(v16->z - v15->z) * v14) + v15->z;
      break;
    case 7:
    case 8:
    case 9:
      HIDWORD(tension) = 0;
      interpolationType = 0.0;
      vOut = 0.0;
      Interpolator_GetKochanekBartelsParams(
        interpolationType: v7,
        tension: (float *)&tension + 1,
        bias: &interpolationType,
        continuity: &vOut);
      Kochanek_Bartels_Spline_NormalizeX(
        tension: *((float *)&tension + 1),
        bias: interpolationType,
        continuity: vOut,
        p1: vPre,
        p2: vStart,
        p3: vEnd,
        p4: vNext,
        t: f,
        output: v8);
      break;
    case 10:
      Cubic_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 11:
      Catmull_Rom_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 12:
      Catmull_Rom_Spline_Normalize(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 13:
      Catmull_Rom_Spline_Tangent(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 14:
      y = vStart->y;
      v18 = vEnd;
      decayTime = vEnd->x - vStart->x;
      if ( decayTime > 0.0 )
      {
        vOut = vStart->y;
        v20 = ExponentialDecay(decayTo: 0.001, decayTime, dt: decayTime * f);
        y = vOut + (v18->y - vOut) * (1.0 - v20);
      }
      v8->y = y;
      break;
    case 15:
      v8->y = vStart->y;
      break;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", v7);
$LN15:
      Catmull_Rom_Spline_NormalizeX(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C7A0
// Name: void Interpolator_CurveInterpolate_NonNormalized(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl Interpolator_CurveInterpolate_NonNormalized(
        float interpolationType,
        const Vector *vPre,
        const Vector *vStart,
        const Vector *vEnd,
        const Vector *vNext,
        float f,
        float vOut)
{
  int v7; // eax
  Vector *v8; // esi
  double v9; // xmm0_8
  float v10; // xmm0_4
  const Vector *v11; // eax
  const Vector *v12; // ecx
  double v13; // xmm0_8
  float v14; // xmm1_4
  const Vector *v15; // eax
  const Vector *v16; // ecx
  long double y; // st7
  const Vector *v18; // edi
  float decayTime; // xmm0_4
  long double v20; // st7
  long double tension; // [esp+24h] [ebp-8h] OVERLAPPED BYREF

  v7 = LODWORD(interpolationType);
  v8 = (Vector *)LODWORD(vOut);
  *(_DWORD *)LODWORD(vOut) = 0;
  v8->y = 0.0;
  v8->z = 0.0;
  switch ( v7 )
  {
    case 0:
    case 1:
    case 11:
    case 12:
    case 13:
      goto $LN12_1;
    case 2:
      v9 = f * 3.141592653589793 * 0.5;
      __libm_sse2_sin(x: tension);
      v10 = v9;
      goto LABEL_3;
    case 3:
      v13 = f * 3.141592653589793 * 0.5 + 1.570796326794897;
      __libm_sse2_sin(x: tension);
      v10 = 1.0 - v13;
LABEL_3:
      v11 = vStart;
      v12 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v10) + vStart->x;
      v8->y = (float)((float)(v12->y - v11->y) * v10) + v11->y;
      v8->z = (float)((float)(v12->z - v11->z) * v10) + v11->z;
      return;
    case 4:
      v14 = (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f);
      goto LABEL_6;
    case 5:
      BSpline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      return;
    case 6:
      v14 = f;
LABEL_6:
      v15 = vStart;
      v16 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v14) + vStart->x;
      v8->y = (float)((float)(v16->y - v15->y) * v14) + v15->y;
      v8->z = (float)((float)(v16->z - v15->z) * v14) + v15->z;
      break;
    case 7:
    case 8:
    case 9:
      HIDWORD(tension) = 0;
      interpolationType = 0.0;
      vOut = 0.0;
      Interpolator_GetKochanekBartelsParams(
        interpolationType: v7,
        tension: (float *)&tension + 1,
        bias: &interpolationType,
        continuity: &vOut);
      Kochanek_Bartels_Spline(
        tension: *((float *)&tension + 1),
        bias: interpolationType,
        continuity: vOut,
        p1: vPre,
        p2: vStart,
        p3: vEnd,
        p4: vNext,
        t: f,
        output: v8);
      break;
    case 10:
      Cubic_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 14:
      y = vStart->y;
      v18 = vEnd;
      decayTime = vEnd->x - vStart->x;
      if ( decayTime > 0.0 )
      {
        vOut = vStart->y;
        v20 = ExponentialDecay(decayTo: 0.001, decayTime, dt: decayTime * f);
        y = vOut + (v18->y - vOut) * (1.0 - v20);
      }
      v8->y = y;
      break;
    case 15:
      v8->y = vStart->y;
      break;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", v7);
$LN12_1:
      Catmull_Rom_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040CAA0
// Name: void Interpolator_CurveInterpolate_NonNormalized(int,class Quaternion const __near &,class Quaternion const __near &,class Quaternion const __near &,class Quaternion const __near &,float,class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall Interpolator_CurveInterpolate_NonNormalized(
        int a1@<esi>,
        int interpolationType,
        const Quaternion *vPre,
        const Quaternion *vStart,
        const Quaternion *vEnd,
        const Quaternion *vNext,
        float f,
        Quaternion *vOut)
{
  float t; // xmm0_4
  float v9; // xmm0_4
  long double v10; // [esp+4h] [ebp-8h]
  Quaternion *v11; // [esp+4h] [ebp-8h]
  Quaternion *v12; // [esp+4h] [ebp-8h]

  HIDWORD(v10) = a1;
  vOut->x = 0.0;
  vOut->y = 0.0;
  vOut->z = 0.0;
  vOut->w = 0.0;
  switch ( interpolationType )
  {
    case 0:
    case 1:
    case 5:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
      goto $LN7_4;
    case 2:
      LODWORD(v10) = vOut;
      __libm_sse2_sin(x: v10);
      t = f * 3.141592653589793 * 0.5;
      QuaternionSlerp(p: vStart, q: vEnd, t, qt: v11);
      return;
    case 3:
      LODWORD(v10) = vOut;
      __libm_sse2_sin(x: v10);
      v9 = 1.0 - (f * 3.141592653589793 * 0.5 + 1.570796326794897);
      goto LABEL_10;
    case 4:
      QuaternionSlerp(
        p: vStart,
        q: vEnd,
        t: (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f),
        qt: vOut);
      return;
    case 6:
      QuaternionSlerp(p: vStart, q: vEnd, t: f, qt: vOut);
      return;
    case 14:
      vOut->x = 0.0;
      vOut->y = 0.0;
      vOut->z = 0.0;
      vOut->w = 0.0;
      return;
    case 15:
      *vOut = *vStart;
      return;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", interpolationType);
$LN7_4:
      v9 = f;
      v12 = vOut;
LABEL_10:
      QuaternionSlerp(p: vStart, q: vEnd, t: v9, qt: v12);
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005A9DB0
// Name: _dynamic_initializer_for__Interp_LuaFunc_s__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__Interp_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  Interp_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &Interp_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9DD0
// Name: _dynamic_initializer_for__Save_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__Save_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  Save_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &Save_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9DF0
// Name: _dynamic_initializer_for__Merge_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__Merge_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  Merge_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &Merge_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9E10
// Name: _dynamic_initializer_for__SaveDelta_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__SaveDelta_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  SaveDelta_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &SaveDelta_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9E30
// Name: _dynamic_initializer_for__DeleteDelta_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__DeleteDelta_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  DeleteDelta_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &DeleteDelta_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9E50
// Name: _dynamic_initializer_for__RemapMaterial_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__RemapMaterial_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  RemapMaterial_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &RemapMaterial_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9E70
// Name: _dynamic_initializer_for__RemoveFacesWithMaterial_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__RemoveFacesWithMaterial_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  RemoveFacesWithMaterial_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &RemoveFacesWithMaterial_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9E90
// Name: _dynamic_initializer_for__RemoveFacesWithMoreThanNVerts_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__RemoveFacesWithMoreThanNVerts_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  RemoveFacesWithMoreThanNVerts_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &RemoveFacesWithMoreThanNVerts_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9EB0
// Name: _dynamic_initializer_for__Mirror_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__Mirror_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  Mirror_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &Mirror_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9ED0
// Name: _dynamic_initializer_for__ComputeNormals_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__ComputeNormals_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  ComputeNormals_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &ComputeNormals_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9EF0
// Name: _dynamic_initializer_for__ComputeWrinkles_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__ComputeWrinkles_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  ComputeWrinkles_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &ComputeWrinkles_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9F10
// Name: _dynamic_initializer_for__ComputeWrinkle_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__ComputeWrinkle_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  ComputeWrinkle_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &ComputeWrinkle_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9F30
// Name: _dynamic_initializer_for__CreateDeltasFromPresets_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__CreateDeltasFromPresets_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  CreateDeltasFromPresets_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &CreateDeltasFromPresets_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9F50
// Name: _dynamic_initializer_for__CachePreset_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__CachePreset_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  CachePreset_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &CachePreset_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9F70
// Name: _dynamic_initializer_for__ClearPresetCache_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__ClearPresetCache_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  ClearPresetCache_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &ClearPresetCache_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9F90
// Name: _dynamic_initializer_for__CreateDeltasFromCachedPresets_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__CreateDeltasFromCachedPresets_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  CreateDeltasFromCachedPresets_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &CreateDeltasFromCachedPresets_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9FB0
// Name: _dynamic_initializer_for__CreateExpressionFileFromPresets_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__CreateExpressionFileFromPresets_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  CreateExpressionFileFromPresets_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &CreateExpressionFileFromPresets_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9FD0
// Name: _dynamic_initializer_for__CreateExpressionFilesFromCachedPresets_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__CreateExpressionFilesFromCachedPresets_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  CreateExpressionFilesFromCachedPresets_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &CreateExpressionFilesFromCachedPresets_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005A9FF0
// Name: _dynamic_initializer_for__Scale_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__Scale_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  Scale_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &Scale_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AA010
// Name: _dynamic_initializer_for__SetDistanceType_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__SetDistanceType_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  SetDistanceType_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &SetDistanceType_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AA030
// Name: _dynamic_initializer_for__Translate_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__Translate_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  Translate_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &Translate_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AA050
// Name: _dynamic_initializer_for__Rotate_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__Rotate_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  Rotate_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &Rotate_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AA070
// Name: _dynamic_initializer_for__FileExists_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__FileExists_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  FileExists_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &FileExists_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AA090
// Name: _dynamic_initializer_for__GroupControls_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__GroupControls_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  GroupControls_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &GroupControls_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AA0B0
// Name: _dynamic_initializer_for__ReorderControls_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__ReorderControls_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  ReorderControls_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &ReorderControls_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AA0D0
// Name: _dynamic_initializer_for__AddDominationRule_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__AddDominationRule_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  AddDominationRule_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &AddDominationRule_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AA0F0
// Name: _dynamic_initializer_for__SetStereoControl_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__SetStereoControl_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  SetStereoControl_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &SetStereoControl_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AA110
// Name: _dynamic_initializer_for__SetEyelidControl_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__SetEyelidControl_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  SetEyelidControl_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &SetEyelidControl_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AA130
// Name: _dynamic_initializer_for__MaxDeltaDistance_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__MaxDeltaDistance_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  MaxDeltaDistance_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &MaxDeltaDistance_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AA150
// Name: _dynamic_initializer_for__DeltaRadius_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__DeltaRadius_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  DeltaRadius_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &DeltaRadius_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AA170
// Name: _dynamic_initializer_for__SelectionRadius_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__SelectionRadius_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  SelectionRadius_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &SelectionRadius_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AA190
// Name: _dynamic_initializer_for__SetWrinkleScale_LuaFunc_s__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LuaFunc_s *dynamic_initializer_for__SetWrinkleScale_LuaFunc_s__()
{
  LuaFunc_s *result; // eax

  result = LuaFunc_s::s_pFirstFunc;
  SetWrinkleScale_LuaFunc_s.m_pNextFunc = LuaFunc_s::s_pFirstFunc;
  LuaFunc_s::s_pFirstFunc = &SetWrinkleScale_LuaFunc_s;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x005AA1B0
// Name: _dynamic_initializer_for____s_ApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____s_ApplicationObject__()
{
  CSteamAppSystemGroup::CSteamAppSystemGroup(
    this: &_s_ApplicationObject,
    pFileSystem: nullptr,
    pAppSystemParent: nullptr);
  _s_ApplicationObject.__vftable = (CDmxEditApp_vtbl *)&CDmxEditApp::`vftable';
  return atexit(func: dynamic_atexit_destructor_for____s_ApplicationObject__);
}

//------------------------------------------------------------------------------
// Address: 0x005AA1E0
// Name: _dynamic_initializer_for____s_SteamApplicationObject__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for____s_SteamApplicationObject__()
{
  CSteamApplication::CSteamApplication(this: &_s_SteamApplicationObject, pAppSystemGroup: &_s_ApplicationObject);
  return atexit(func: dynamic_atexit_destructor_for____s_SteamApplicationObject__);
}

//------------------------------------------------------------------------------
// Address: 0x005AA200
// Name: _dynamic_initializer_for__g_CDmElementPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElement *dynamic_initializer_for__g_CDmElementPullInModule__()
{
  g_CDmElementPullInModule = g_CDmElementLinkerHack;
  return g_CDmElementLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA210
// Name: _dynamic_initializer_for__g_CDmeTransformPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTransform *dynamic_initializer_for__g_CDmeTransformPullInModule__()
{
  g_CDmeTransformPullInModule = g_CDmeTransformLinkerHack;
  return g_CDmeTransformLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA220
// Name: _dynamic_initializer_for__g_CDmeTransformListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTransformList *dynamic_initializer_for__g_CDmeTransformListPullInModule__()
{
  g_CDmeTransformListPullInModule = g_CDmeTransformListLinkerHack;
  return g_CDmeTransformListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA230
// Name: _dynamic_initializer_for__g_CDmeVertexDataBasePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeVertexDataBase *dynamic_initializer_for__g_CDmeVertexDataBasePullInModule__()
{
  g_CDmeVertexDataBasePullInModule = g_CDmeVertexDataBaseLinkerHack;
  return g_CDmeVertexDataBaseLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA240
// Name: _dynamic_initializer_for__g_CDmeVertexDataPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeVertexData *dynamic_initializer_for__g_CDmeVertexDataPullInModule__()
{
  g_CDmeVertexDataPullInModule = g_CDmeVertexDataLinkerHack;
  return g_CDmeVertexDataLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA250
// Name: _dynamic_initializer_for__g_CDmeVertexDeltaDataPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeVertexDeltaData *dynamic_initializer_for__g_CDmeVertexDeltaDataPullInModule__()
{
  g_CDmeVertexDeltaDataPullInModule = g_CDmeVertexDeltaDataLinkerHack;
  return g_CDmeVertexDeltaDataLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA260
// Name: _dynamic_initializer_for__g_CDmeShapePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeShape *dynamic_initializer_for__g_CDmeShapePullInModule__()
{
  g_CDmeShapePullInModule = g_CDmeShapeLinkerHack;
  return g_CDmeShapeLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA270
// Name: _dynamic_initializer_for__g_CDmeMeshPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMesh *dynamic_initializer_for__g_CDmeMeshPullInModule__()
{
  g_CDmeMeshPullInModule = g_CDmeMeshLinkerHack;
  return g_CDmeMeshLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA280
// Name: _dynamic_initializer_for__g_CDmeDagPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDag *dynamic_initializer_for__g_CDmeDagPullInModule__()
{
  g_CDmeDagPullInModule = g_CDmeDagLinkerHack;
  return g_CDmeDagLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA290
// Name: _dynamic_initializer_for__g_CDmeFaceSetPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFaceSet *dynamic_initializer_for__g_CDmeFaceSetPullInModule__()
{
  g_CDmeFaceSetPullInModule = g_CDmeFaceSetLinkerHack;
  return g_CDmeFaceSetLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA2A0
// Name: _dynamic_initializer_for__g_CDmeModelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeModel *dynamic_initializer_for__g_CDmeModelPullInModule__()
{
  g_CDmeModelPullInModule = g_CDmeModelLinkerHack;
  return g_CDmeModelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA2B0
// Name: _dynamic_initializer_for__g_CDmeJointPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeJoint *dynamic_initializer_for__g_CDmeJointPullInModule__()
{
  g_CDmeJointPullInModule = g_CDmeJointLinkerHack;
  return g_CDmeJointLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA2C0
// Name: _dynamic_initializer_for__g_CDmeAttachmentPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAttachment *dynamic_initializer_for__g_CDmeAttachmentPullInModule__()
{
  g_CDmeAttachmentPullInModule = g_CDmeAttachmentLinkerHack;
  return g_CDmeAttachmentLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA2D0
// Name: _dynamic_initializer_for__g_CDmeMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMakefile *dynamic_initializer_for__g_CDmeMakefilePullInModule__()
{
  g_CDmeMakefilePullInModule = g_CDmeMakefileLinkerHack;
  return g_CDmeMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA2E0
// Name: _dynamic_initializer_for__g_CDmeMDLMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMDLMakefile *dynamic_initializer_for__g_CDmeMDLMakefilePullInModule__()
{
  g_CDmeMDLMakefilePullInModule = g_CDmeMDLMakefileLinkerHack;
  return g_CDmeMDLMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA2F0
// Name: _dynamic_initializer_for__g_CDmeDCCMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDCCMakefile *dynamic_initializer_for__g_CDmeDCCMakefilePullInModule__()
{
  g_CDmeDCCMakefilePullInModule = g_CDmeDCCMakefileLinkerHack;
  return g_CDmeDCCMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA300
// Name: _dynamic_initializer_for__g_CDmeMayaAnimationMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMayaAnimationMakefile *dynamic_initializer_for__g_CDmeMayaAnimationMakefilePullInModule__()
{
  g_CDmeMayaAnimationMakefilePullInModule = g_CDmeMayaAnimationMakefileLinkerHack;
  return g_CDmeMayaAnimationMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA310
// Name: _dynamic_initializer_for__g_CDmeMayaCombinationOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMayaCombinationOperator *dynamic_initializer_for__g_CDmeMayaCombinationOperatorPullInModule__()
{
  g_CDmeMayaCombinationOperatorPullInModule = g_CDmeMayaCombinationOperatorLinkerHack;
  return g_CDmeMayaCombinationOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA320
// Name: _dynamic_initializer_for__g_CDmeMayaMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMayaMakefile *dynamic_initializer_for__g_CDmeMayaMakefilePullInModule__()
{
  g_CDmeMayaMakefilePullInModule = g_CDmeMayaMakefileLinkerHack;
  return g_CDmeMayaMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA330
// Name: _dynamic_initializer_for__g_CDmeMayaModelMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMayaModelMakefile *dynamic_initializer_for__g_CDmeMayaModelMakefilePullInModule__()
{
  g_CDmeMayaModelMakefilePullInModule = g_CDmeMayaModelMakefileLinkerHack;
  return g_CDmeMayaModelMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA340
// Name: _dynamic_initializer_for__g_CDmeXSIMakefilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeXSIMakefile *dynamic_initializer_for__g_CDmeXSIMakefilePullInModule__()
{
  g_CDmeXSIMakefilePullInModule = g_CDmeXSIMakefileLinkerHack;
  return g_CDmeXSIMakefileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA350
// Name: _dynamic_initializer_for__g_CDmeSourcePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSource *dynamic_initializer_for__g_CDmeSourcePullInModule__()
{
  g_CDmeSourcePullInModule = g_CDmeSourceLinkerHack;
  return g_CDmeSourceLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA360
// Name: _dynamic_initializer_for__g_CDmeSourceDCCFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceDCCFile *dynamic_initializer_for__g_CDmeSourceDCCFilePullInModule__()
{
  g_CDmeSourceDCCFilePullInModule = g_CDmeSourceDCCFileLinkerHack;
  return g_CDmeSourceDCCFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA370
// Name: _dynamic_initializer_for__g_CDmeSourceMayaFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceMayaFile *dynamic_initializer_for__g_CDmeSourceMayaFilePullInModule__()
{
  g_CDmeSourceMayaFilePullInModule = g_CDmeSourceMayaFileLinkerHack;
  return g_CDmeSourceMayaFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA380
// Name: _dynamic_initializer_for__g_CDmeSourceMayaModelFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceMayaModelFile *dynamic_initializer_for__g_CDmeSourceMayaModelFilePullInModule__()
{
  g_CDmeSourceMayaModelFilePullInModule = g_CDmeSourceMayaModelFileLinkerHack;
  return g_CDmeSourceMayaModelFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA390
// Name: _dynamic_initializer_for__g_CDmeSourceMayaAnimationFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceMayaAnimationFile *dynamic_initializer_for__g_CDmeSourceMayaAnimationFilePullInModule__()
{
  g_CDmeSourceMayaAnimationFilePullInModule = g_CDmeSourceMayaAnimationFileLinkerHack;
  return g_CDmeSourceMayaAnimationFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA3A0
// Name: _dynamic_initializer_for__g_CDmeSourceXSIFilePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSourceXSIFile *dynamic_initializer_for__g_CDmeSourceXSIFilePullInModule__()
{
  g_CDmeSourceXSIFilePullInModule = g_CDmeSourceXSIFileLinkerHack;
  return g_CDmeSourceXSIFileLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA3B0
// Name: _dynamic_initializer_for__g_CDmeAnimationListPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimationList *dynamic_initializer_for__g_CDmeAnimationListPullInModule__()
{
  g_CDmeAnimationListPullInModule = g_CDmeAnimationListLinkerHack;
  return g_CDmeAnimationListLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA3C0
// Name: _dynamic_initializer_for__g_CDmeClipPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeClip *dynamic_initializer_for__g_CDmeClipPullInModule__()
{
  g_CDmeClipPullInModule = g_CDmeClipLinkerHack;
  return g_CDmeClipLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA3D0
// Name: _dynamic_initializer_for__g_CDmeChannelsClipPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeChannelsClip *dynamic_initializer_for__g_CDmeChannelsClipPullInModule__()
{
  g_CDmeChannelsClipPullInModule = g_CDmeChannelsClipLinkerHack;
  return g_CDmeChannelsClipLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA3E0
// Name: _dynamic_initializer_for__g_CDmeChannelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeChannel *dynamic_initializer_for__g_CDmeChannelPullInModule__()
{
  g_CDmeChannelPullInModule = g_CDmeChannelLinkerHack;
  return g_CDmeChannelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA3F0
// Name: _dynamic_initializer_for__g_CDmeTimeFramePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTimeFrame *dynamic_initializer_for__g_CDmeTimeFramePullInModule__()
{
  g_CDmeTimeFramePullInModule = g_CDmeTimeFrameLinkerHack;
  return g_CDmeTimeFrameLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA400
// Name: _dynamic_initializer_for__g_CDmeTrackGroupPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTrackGroup *dynamic_initializer_for__g_CDmeTrackGroupPullInModule__()
{
  g_CDmeTrackGroupPullInModule = g_CDmeTrackGroupLinkerHack;
  return g_CDmeTrackGroupLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA410
// Name: _dynamic_initializer_for__g_CDmeTrackPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTrack *dynamic_initializer_for__g_CDmeTrackPullInModule__()
{
  g_CDmeTrackPullInModule = g_CDmeTrackLinkerHack;
  return g_CDmeTrackLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA420
// Name: _dynamic_initializer_for__g_CDmeCombinationDominationRulePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCombinationDominationRule *dynamic_initializer_for__g_CDmeCombinationDominationRulePullInModule__()
{
  g_CDmeCombinationDominationRulePullInModule = g_CDmeCombinationDominationRuleLinkerHack;
  return g_CDmeCombinationDominationRuleLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA430
// Name: _dynamic_initializer_for__g_CDmeCombinationInputControlPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCombinationInputControl *dynamic_initializer_for__g_CDmeCombinationInputControlPullInModule__()
{
  g_CDmeCombinationInputControlPullInModule = g_CDmeCombinationInputControlLinkerHack;
  return g_CDmeCombinationInputControlLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA440
// Name: _dynamic_initializer_for__g_CDmeCombinationOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCombinationOperator *dynamic_initializer_for__g_CDmeCombinationOperatorPullInModule__()
{
  g_CDmeCombinationOperatorPullInModule = g_CDmeCombinationOperatorLinkerHack;
  return g_CDmeCombinationOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA450
// Name: _dynamic_initializer_for__g_CDmeIntLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<int> *dynamic_initializer_for__g_CDmeIntLogPullInModule__()
{
  g_CDmeIntLogPullInModule = g_CDmeIntLogLinkerHack;
  return g_CDmeIntLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA460
// Name: _dynamic_initializer_for__g_CDmeFloatLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<float> *dynamic_initializer_for__g_CDmeFloatLogPullInModule__()
{
  g_CDmeFloatLogPullInModule = g_CDmeFloatLogLinkerHack;
  return g_CDmeFloatLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA470
// Name: _dynamic_initializer_for__g_CDmeBoolLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<bool> *dynamic_initializer_for__g_CDmeBoolLogPullInModule__()
{
  g_CDmeBoolLogPullInModule = g_CDmeBoolLogLinkerHack;
  return g_CDmeBoolLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA480
// Name: _dynamic_initializer_for__g_CDmeColorLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Color> *dynamic_initializer_for__g_CDmeColorLogPullInModule__()
{
  g_CDmeColorLogPullInModule = g_CDmeColorLogLinkerHack;
  return g_CDmeColorLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA490
// Name: _dynamic_initializer_for__g_CDmeVector2LogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Vector2D> *dynamic_initializer_for__g_CDmeVector2LogPullInModule__()
{
  g_CDmeVector2LogPullInModule = g_CDmeVector2LogLinkerHack;
  return g_CDmeVector2LogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA4A0
// Name: _dynamic_initializer_for__g_CDmeVector3LogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Vector> *dynamic_initializer_for__g_CDmeVector3LogPullInModule__()
{
  g_CDmeVector3LogPullInModule = g_CDmeVector3LogLinkerHack;
  return g_CDmeVector3LogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA4B0
// Name: _dynamic_initializer_for__g_CDmeVector4LogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Vector4D> *dynamic_initializer_for__g_CDmeVector4LogPullInModule__()
{
  g_CDmeVector4LogPullInModule = g_CDmeVector4LogLinkerHack;
  return g_CDmeVector4LogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA4C0
// Name: _dynamic_initializer_for__g_CDmeQAngleLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<QAngle> *dynamic_initializer_for__g_CDmeQAngleLogPullInModule__()
{
  g_CDmeQAngleLogPullInModule = g_CDmeQAngleLogLinkerHack;
  return g_CDmeQAngleLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA4D0
// Name: _dynamic_initializer_for__g_CDmeQuaternionLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<Quaternion> *dynamic_initializer_for__g_CDmeQuaternionLogPullInModule__()
{
  g_CDmeQuaternionLogPullInModule = g_CDmeQuaternionLogLinkerHack;
  return g_CDmeQuaternionLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA4E0
// Name: _dynamic_initializer_for__g_CDmeVMatrixLogPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLog<VMatrix> *dynamic_initializer_for__g_CDmeVMatrixLogPullInModule__()
{
  g_CDmeVMatrixLogPullInModule = g_CDmeVMatrixLogLinkerHack;
  return g_CDmeVMatrixLogLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA4F0
// Name: _dynamic_initializer_for__g_CDmeIntLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<int> *dynamic_initializer_for__g_CDmeIntLogLayerPullInModule__()
{
  g_CDmeIntLogLayerPullInModule = g_CDmeIntLogLayerLinkerHack;
  return g_CDmeIntLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA500
// Name: _dynamic_initializer_for__g_CDmeFloatLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<float> *dynamic_initializer_for__g_CDmeFloatLogLayerPullInModule__()
{
  g_CDmeFloatLogLayerPullInModule = g_CDmeFloatLogLayerLinkerHack;
  return g_CDmeFloatLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA510
// Name: _dynamic_initializer_for__g_CDmeBoolLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<bool> *dynamic_initializer_for__g_CDmeBoolLogLayerPullInModule__()
{
  g_CDmeBoolLogLayerPullInModule = g_CDmeBoolLogLayerLinkerHack;
  return g_CDmeBoolLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA520
// Name: _dynamic_initializer_for__g_CDmeColorLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Color> *dynamic_initializer_for__g_CDmeColorLogLayerPullInModule__()
{
  g_CDmeColorLogLayerPullInModule = g_CDmeColorLogLayerLinkerHack;
  return g_CDmeColorLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA530
// Name: _dynamic_initializer_for__g_CDmeVector2LogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Vector2D> *dynamic_initializer_for__g_CDmeVector2LogLayerPullInModule__()
{
  g_CDmeVector2LogLayerPullInModule = g_CDmeVector2LogLayerLinkerHack;
  return g_CDmeVector2LogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA540
// Name: _dynamic_initializer_for__g_CDmeVector3LogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Vector> *dynamic_initializer_for__g_CDmeVector3LogLayerPullInModule__()
{
  g_CDmeVector3LogLayerPullInModule = g_CDmeVector3LogLayerLinkerHack;
  return g_CDmeVector3LogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA550
// Name: _dynamic_initializer_for__g_CDmeVector4LogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Vector4D> *dynamic_initializer_for__g_CDmeVector4LogLayerPullInModule__()
{
  g_CDmeVector4LogLayerPullInModule = g_CDmeVector4LogLayerLinkerHack;
  return g_CDmeVector4LogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA560
// Name: _dynamic_initializer_for__g_CDmeQAngleLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<QAngle> *dynamic_initializer_for__g_CDmeQAngleLogLayerPullInModule__()
{
  g_CDmeQAngleLogLayerPullInModule = g_CDmeQAngleLogLayerLinkerHack;
  return g_CDmeQAngleLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA570
// Name: _dynamic_initializer_for__g_CDmeQuaternionLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<Quaternion> *dynamic_initializer_for__g_CDmeQuaternionLogLayerPullInModule__()
{
  g_CDmeQuaternionLogLayerPullInModule = g_CDmeQuaternionLogLayerLinkerHack;
  return g_CDmeQuaternionLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA580
// Name: _dynamic_initializer_for__g_CDmeVMatrixLogLayerPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedLogLayer<VMatrix> *dynamic_initializer_for__g_CDmeVMatrixLogLayerPullInModule__()
{
  g_CDmeVMatrixLogLayerPullInModule = g_CDmeVMatrixLogLayerLinkerHack;
  return g_CDmeVMatrixLogLayerLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA590
// Name: _dynamic_initializer_for__g_CDmeIntCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<int> *dynamic_initializer_for__g_CDmeIntCurveInfoPullInModule__()
{
  g_CDmeIntCurveInfoPullInModule = g_CDmeIntCurveInfoLinkerHack;
  return g_CDmeIntCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA5A0
// Name: _dynamic_initializer_for__g_CDmeFloatCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<float> *dynamic_initializer_for__g_CDmeFloatCurveInfoPullInModule__()
{
  g_CDmeFloatCurveInfoPullInModule = g_CDmeFloatCurveInfoLinkerHack;
  return g_CDmeFloatCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA5B0
// Name: _dynamic_initializer_for__g_CDmeBoolCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<bool> *dynamic_initializer_for__g_CDmeBoolCurveInfoPullInModule__()
{
  g_CDmeBoolCurveInfoPullInModule = g_CDmeBoolCurveInfoLinkerHack;
  return g_CDmeBoolCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA5C0
// Name: _dynamic_initializer_for__g_CDmeColorCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Color> *dynamic_initializer_for__g_CDmeColorCurveInfoPullInModule__()
{
  g_CDmeColorCurveInfoPullInModule = g_CDmeColorCurveInfoLinkerHack;
  return g_CDmeColorCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA5D0
// Name: _dynamic_initializer_for__g_CDmeVector2CurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Vector2D> *dynamic_initializer_for__g_CDmeVector2CurveInfoPullInModule__()
{
  g_CDmeVector2CurveInfoPullInModule = g_CDmeVector2CurveInfoLinkerHack;
  return g_CDmeVector2CurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA5E0
// Name: _dynamic_initializer_for__g_CDmeVector3CurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Vector> *dynamic_initializer_for__g_CDmeVector3CurveInfoPullInModule__()
{
  g_CDmeVector3CurveInfoPullInModule = g_CDmeVector3CurveInfoLinkerHack;
  return g_CDmeVector3CurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA5F0
// Name: _dynamic_initializer_for__g_CDmeVector4CurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Vector4D> *dynamic_initializer_for__g_CDmeVector4CurveInfoPullInModule__()
{
  g_CDmeVector4CurveInfoPullInModule = g_CDmeVector4CurveInfoLinkerHack;
  return g_CDmeVector4CurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA600
// Name: _dynamic_initializer_for__g_CDmeQAngleCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<QAngle> *dynamic_initializer_for__g_CDmeQAngleCurveInfoPullInModule__()
{
  g_CDmeQAngleCurveInfoPullInModule = g_CDmeQAngleCurveInfoLinkerHack;
  return g_CDmeQAngleCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA610
// Name: _dynamic_initializer_for__g_CDmeQuaternionCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<Quaternion> *dynamic_initializer_for__g_CDmeQuaternionCurveInfoPullInModule__()
{
  g_CDmeQuaternionCurveInfoPullInModule = g_CDmeQuaternionCurveInfoLinkerHack;
  return g_CDmeQuaternionCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA620
// Name: _dynamic_initializer_for__g_CDmeVMatrixCurveInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTypedCurveInfo<VMatrix> *dynamic_initializer_for__g_CDmeVMatrixCurveInfoPullInModule__()
{
  g_CDmeVMatrixCurveInfoPullInModule = g_CDmeVMatrixCurveInfoLinkerHack;
  return g_CDmeVMatrixCurveInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA630
// Name: _dynamic_initializer_for__g_CDmeComponentPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeComponent *dynamic_initializer_for__g_CDmeComponentPullInModule__()
{
  g_CDmeComponentPullInModule = g_CDmeComponentLinkerHack;
  return g_CDmeComponentLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA640
// Name: _dynamic_initializer_for__g_CDmeSingleIndexedComponentPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSingleIndexedComponent *dynamic_initializer_for__g_CDmeSingleIndexedComponentPullInModule__()
{
  g_CDmeSingleIndexedComponentPullInModule = g_CDmeSingleIndexedComponentLinkerHack;
  return g_CDmeSingleIndexedComponentLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA650
// Name: _dynamic_initializer_for__g_CDmeDrawSettingsPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeDrawSettings *dynamic_initializer_for__g_CDmeDrawSettingsPullInModule__()
{
  g_CDmeDrawSettingsPullInModule = g_CDmeDrawSettingsLinkerHack;
  return g_CDmeDrawSettingsLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA660
// Name: _dynamic_initializer_for__g_CDmeCameraPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeCamera *dynamic_initializer_for__g_CDmeCameraPullInModule__()
{
  g_CDmeCameraPullInModule = g_CDmeCameraLinkerHack;
  return g_CDmeCameraLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA670
// Name: _dynamic_initializer_for__g_CDmeSoundClipPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSoundClip *dynamic_initializer_for__g_CDmeSoundClipPullInModule__()
{
  g_CDmeSoundClipPullInModule = g_CDmeSoundClipLinkerHack;
  return g_CDmeSoundClipLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA680
// Name: _dynamic_initializer_for__g_CDmeFilmClipPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFilmClip *dynamic_initializer_for__g_CDmeFilmClipPullInModule__()
{
  g_CDmeFilmClipPullInModule = g_CDmeFilmClipLinkerHack;
  return g_CDmeFilmClipLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA690
// Name: _dynamic_initializer_for__g_CDmeMDLPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMDL *dynamic_initializer_for__g_CDmeMDLPullInModule__()
{
  g_CDmeMDLPullInModule = g_CDmeMDLLinkerHack;
  return g_CDmeMDLLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA6A0
// Name: _dynamic_initializer_for__g_CDmeMaterialPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMaterial *dynamic_initializer_for__g_CDmeMaterialPullInModule__()
{
  g_CDmeMaterialPullInModule = g_CDmeMaterialLinkerHack;
  return g_CDmeMaterialLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA6B0
// Name: _dynamic_initializer_for__g_CDmeLightPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeLight *dynamic_initializer_for__g_CDmeLightPullInModule__()
{
  g_CDmeLightPullInModule = g_CDmeLightLinkerHack;
  return g_CDmeLightLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA6C0
// Name: _dynamic_initializer_for__g_CDmeGameModelPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeGameModel *dynamic_initializer_for__g_CDmeGameModelPullInModule__()
{
  g_CDmeGameModelPullInModule = g_CDmeGameModelLinkerHack;
  return g_CDmeGameModelLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA6D0
// Name: _dynamic_initializer_for__g_CDmeSoundPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeSound *dynamic_initializer_for__g_CDmeSoundPullInModule__()
{
  g_CDmeSoundPullInModule = g_CDmeSoundLinkerHack;
  return g_CDmeSoundLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA6E0
// Name: _dynamic_initializer_for__g_CDmeGameSoundPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeGameSound *dynamic_initializer_for__g_CDmeGameSoundPullInModule__()
{
  g_CDmeGameSoundPullInModule = g_CDmeGameSoundLinkerHack;
  return g_CDmeGameSoundLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA6F0
// Name: _dynamic_initializer_for__g_CDmeMorphOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMorphOperator *dynamic_initializer_for__g_CDmeMorphOperatorPullInModule__()
{
  g_CDmeMorphOperatorPullInModule = g_CDmeMorphOperatorLinkerHack;
  return g_CDmeMorphOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA700
// Name: _dynamic_initializer_for__g_CDmeTransformOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTransformOperator *dynamic_initializer_for__g_CDmeTransformOperatorPullInModule__()
{
  g_CDmeTransformOperatorPullInModule = g_CDmeTransformOperatorLinkerHack;
  return g_CDmeTransformOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA710
// Name: _dynamic_initializer_for__g_CDmeExpressionOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeExpressionOperator *dynamic_initializer_for__g_CDmeExpressionOperatorPullInModule__()
{
  g_CDmeExpressionOperatorPullInModule = g_CDmeExpressionOperatorLinkerHack;
  return g_CDmeExpressionOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA720
// Name: _dynamic_initializer_for__g_CDmeConnectionOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeConnectionOperator *dynamic_initializer_for__g_CDmeConnectionOperatorPullInModule__()
{
  g_CDmeConnectionOperatorPullInModule = g_CDmeConnectionOperatorLinkerHack;
  return g_CDmeConnectionOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA730
// Name: _dynamic_initializer_for__g_CDmeGamePortalPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeGamePortal *dynamic_initializer_for__g_CDmeGamePortalPullInModule__()
{
  g_CDmeGamePortalPullInModule = g_CDmeGamePortalLinkerHack;
  return g_CDmeGamePortalLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA740
// Name: _dynamic_initializer_for__g_CDmeMouseInputPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeMouseInput *dynamic_initializer_for__g_CDmeMouseInputPullInModule__()
{
  g_CDmeMouseInputPullInModule = g_CDmeMouseInputLinkerHack;
  return g_CDmeMouseInputLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA750
// Name: _dynamic_initializer_for__g_CDmeKeyboardInputPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeKeyboardInput *dynamic_initializer_for__g_CDmeKeyboardInputPullInModule__()
{
  g_CDmeKeyboardInputPullInModule = g_CDmeKeyboardInputLinkerHack;
  return g_CDmeKeyboardInputLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA760
// Name: _dynamic_initializer_for__g_CDmeEditorAttributeInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorAttributeInfo *dynamic_initializer_for__g_CDmeEditorAttributeInfoPullInModule__()
{
  g_CDmeEditorAttributeInfoPullInModule = g_CDmeEditorAttributeInfoLinkerHack;
  return g_CDmeEditorAttributeInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA770
// Name: _dynamic_initializer_for__g_CDmeEditorChoicesInfoPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorChoicesInfo *dynamic_initializer_for__g_CDmeEditorChoicesInfoPullInModule__()
{
  g_CDmeEditorChoicesInfoPullInModule = g_CDmeEditorChoicesInfoLinkerHack;
  return g_CDmeEditorChoicesInfoLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA780
// Name: _dynamic_initializer_for__g_CDmeEditorTypePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorType *dynamic_initializer_for__g_CDmeEditorTypePullInModule__()
{
  g_CDmeEditorTypePullInModule = g_CDmeEditorTypeLinkerHack;
  return g_CDmeEditorTypeLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA790
// Name: _dynamic_initializer_for__g_CDmeEditorTypeDictionaryPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeEditorTypeDictionary *dynamic_initializer_for__g_CDmeEditorTypeDictionaryPullInModule__()
{
  g_CDmeEditorTypeDictionaryPullInModule = g_CDmeEditorTypeDictionaryLinkerHack;
  return g_CDmeEditorTypeDictionaryLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA7A0
// Name: _dynamic_initializer_for__g_CDmePackColorOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePackColorOperator *dynamic_initializer_for__g_CDmePackColorOperatorPullInModule__()
{
  g_CDmePackColorOperatorPullInModule = g_CDmePackColorOperatorLinkerHack;
  return g_CDmePackColorOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA7B0
// Name: _dynamic_initializer_for__g_CDmePackVector2OperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePackVector2Operator *dynamic_initializer_for__g_CDmePackVector2OperatorPullInModule__()
{
  g_CDmePackVector2OperatorPullInModule = g_CDmePackVector2OperatorLinkerHack;
  return g_CDmePackVector2OperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA7C0
// Name: _dynamic_initializer_for__g_CDmePackVector3OperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePackVector3Operator *dynamic_initializer_for__g_CDmePackVector3OperatorPullInModule__()
{
  g_CDmePackVector3OperatorPullInModule = g_CDmePackVector3OperatorLinkerHack;
  return g_CDmePackVector3OperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA7D0
// Name: _dynamic_initializer_for__g_CDmePackVector4OperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePackVector4Operator *dynamic_initializer_for__g_CDmePackVector4OperatorPullInModule__()
{
  g_CDmePackVector4OperatorPullInModule = g_CDmePackVector4OperatorLinkerHack;
  return g_CDmePackVector4OperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA7E0
// Name: _dynamic_initializer_for__g_CDmePackQAngleOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePackQAngleOperator *dynamic_initializer_for__g_CDmePackQAngleOperatorPullInModule__()
{
  g_CDmePackQAngleOperatorPullInModule = g_CDmePackQAngleOperatorLinkerHack;
  return g_CDmePackQAngleOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA7F0
// Name: _dynamic_initializer_for__g_CDmePackQuaternionOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePackQuaternionOperator *dynamic_initializer_for__g_CDmePackQuaternionOperatorPullInModule__()
{
  g_CDmePackQuaternionOperatorPullInModule = g_CDmePackQuaternionOperatorLinkerHack;
  return g_CDmePackQuaternionOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA800
// Name: _dynamic_initializer_for__g_CDmePackVMatrixOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePackVMatrixOperator *dynamic_initializer_for__g_CDmePackVMatrixOperatorPullInModule__()
{
  g_CDmePackVMatrixOperatorPullInModule = g_CDmePackVMatrixOperatorLinkerHack;
  return g_CDmePackVMatrixOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA810
// Name: _dynamic_initializer_for__g_CDmeUnpackColorOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackColorOperator *dynamic_initializer_for__g_CDmeUnpackColorOperatorPullInModule__()
{
  g_CDmeUnpackColorOperatorPullInModule = g_CDmeUnpackColorOperatorLinkerHack;
  return g_CDmeUnpackColorOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA820
// Name: _dynamic_initializer_for__g_CDmeUnpackVector2OperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackVector2Operator *dynamic_initializer_for__g_CDmeUnpackVector2OperatorPullInModule__()
{
  g_CDmeUnpackVector2OperatorPullInModule = g_CDmeUnpackVector2OperatorLinkerHack;
  return g_CDmeUnpackVector2OperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA830
// Name: _dynamic_initializer_for__g_CDmeUnpackVector3OperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackVector3Operator *dynamic_initializer_for__g_CDmeUnpackVector3OperatorPullInModule__()
{
  g_CDmeUnpackVector3OperatorPullInModule = g_CDmeUnpackVector3OperatorLinkerHack;
  return g_CDmeUnpackVector3OperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA840
// Name: _dynamic_initializer_for__g_CDmeUnpackVector4OperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackVector4Operator *dynamic_initializer_for__g_CDmeUnpackVector4OperatorPullInModule__()
{
  g_CDmeUnpackVector4OperatorPullInModule = g_CDmeUnpackVector4OperatorLinkerHack;
  return g_CDmeUnpackVector4OperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA850
// Name: _dynamic_initializer_for__g_CDmeUnpackQAngleOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackQAngleOperator *dynamic_initializer_for__g_CDmeUnpackQAngleOperatorPullInModule__()
{
  g_CDmeUnpackQAngleOperatorPullInModule = g_CDmeUnpackQAngleOperatorLinkerHack;
  return g_CDmeUnpackQAngleOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA860
// Name: _dynamic_initializer_for__g_CDmeUnpackQuaternionOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackQuaternionOperator *dynamic_initializer_for__g_CDmeUnpackQuaternionOperatorPullInModule__()
{
  g_CDmeUnpackQuaternionOperatorPullInModule = g_CDmeUnpackQuaternionOperatorLinkerHack;
  return g_CDmeUnpackQuaternionOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA870
// Name: _dynamic_initializer_for__g_CDmeUnpackVMatrixOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeUnpackVMatrixOperator *dynamic_initializer_for__g_CDmeUnpackVMatrixOperatorPullInModule__()
{
  g_CDmeUnpackVMatrixOperatorPullInModule = g_CDmeUnpackVMatrixOperatorLinkerHack;
  return g_CDmeUnpackVMatrixOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA880
// Name: _dynamic_initializer_for__g_CDmeAnimationSetPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeAnimationSet *dynamic_initializer_for__g_CDmeAnimationSetPullInModule__()
{
  g_CDmeAnimationSetPullInModule = g_CDmeAnimationSetLinkerHack;
  return g_CDmeAnimationSetLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA890
// Name: _dynamic_initializer_for__g_CDmePhonemeMappingPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmePhonemeMapping *dynamic_initializer_for__g_CDmePhonemeMappingPullInModule__()
{
  g_CDmePhonemeMappingPullInModule = g_CDmePhonemeMappingLinkerHack;
  return g_CDmePhonemeMappingLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA8A0
// Name: _dynamic_initializer_for__g_CDmeGlobalFlexControllerOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeGlobalFlexControllerOperator *dynamic_initializer_for__g_CDmeGlobalFlexControllerOperatorPullInModule__()
{
  g_CDmeGlobalFlexControllerOperatorPullInModule = g_CDmeGlobalFlexControllerOperatorLinkerHack;
  return g_CDmeGlobalFlexControllerOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA8B0
// Name: _dynamic_initializer_for__g_CDmeTransformControlPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTransformControl *dynamic_initializer_for__g_CDmeTransformControlPullInModule__()
{
  g_CDmeTransformControlPullInModule = g_CDmeTransformControlLinkerHack;
  return g_CDmeTransformControlLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA8C0
// Name: _dynamic_initializer_for__g_CDmeControlGroupPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeControlGroup *dynamic_initializer_for__g_CDmeControlGroupPullInModule__()
{
  g_CDmeControlGroupPullInModule = g_CDmeControlGroupLinkerHack;
  return g_CDmeControlGroupLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA8D0
// Name: _dynamic_initializer_for__g_CDmeTimeSelectionPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeTimeSelection *dynamic_initializer_for__g_CDmeTimeSelectionPullInModule__()
{
  g_CDmeTimeSelectionPullInModule = g_CDmeTimeSelectionLinkerHack;
  return g_CDmeTimeSelectionLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA8E0
// Name: _dynamic_initializer_for__g_CDmeConstraintTargetPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeConstraintTarget *dynamic_initializer_for__g_CDmeConstraintTargetPullInModule__()
{
  g_CDmeConstraintTargetPullInModule = g_CDmeConstraintTargetLinkerHack;
  return g_CDmeConstraintTargetLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA8F0
// Name: _dynamic_initializer_for__g_CDmeConstraintSlavePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeConstraintSlave *dynamic_initializer_for__g_CDmeConstraintSlavePullInModule__()
{
  g_CDmeConstraintSlavePullInModule = g_CDmeConstraintSlaveLinkerHack;
  return g_CDmeConstraintSlaveLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA900
// Name: _dynamic_initializer_for__g_CDmeRigPointConstraintOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigPointConstraintOperator *dynamic_initializer_for__g_CDmeRigPointConstraintOperatorPullInModule__()
{
  g_CDmeRigPointConstraintOperatorPullInModule = g_CDmeRigPointConstraintOperatorLinkerHack;
  return g_CDmeRigPointConstraintOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA910
// Name: _dynamic_initializer_for__g_CDmeRigOrientConstraintOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigOrientConstraintOperator *dynamic_initializer_for__g_CDmeRigOrientConstraintOperatorPullInModule__()
{
  g_CDmeRigOrientConstraintOperatorPullInModule = g_CDmeRigOrientConstraintOperatorLinkerHack;
  return g_CDmeRigOrientConstraintOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA920
// Name: _dynamic_initializer_for__g_CDmeRigAimConstraintOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigAimConstraintOperator *dynamic_initializer_for__g_CDmeRigAimConstraintOperatorPullInModule__()
{
  g_CDmeRigAimConstraintOperatorPullInModule = g_CDmeRigAimConstraintOperatorLinkerHack;
  return g_CDmeRigAimConstraintOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA930
// Name: _dynamic_initializer_for__g_CDmeRigIKConstraintOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigIKConstraintOperator *dynamic_initializer_for__g_CDmeRigIKConstraintOperatorPullInModule__()
{
  g_CDmeRigIKConstraintOperatorPullInModule = g_CDmeRigIKConstraintOperatorLinkerHack;
  return g_CDmeRigIKConstraintOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA940
// Name: _dynamic_initializer_for__g_CDmeRigRotationConstraintOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigRotationConstraintOperator *dynamic_initializer_for__g_CDmeRigRotationConstraintOperatorPullInModule__()
{
  g_CDmeRigRotationConstraintOperatorPullInModule = g_CDmeRigRotationConstraintOperatorLinkerHack;
  return g_CDmeRigRotationConstraintOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA950
// Name: _dynamic_initializer_for__g_CDmeRigHandlePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigHandle *dynamic_initializer_for__g_CDmeRigHandlePullInModule__()
{
  g_CDmeRigHandlePullInModule = g_CDmeRigHandleLinkerHack;
  return g_CDmeRigHandleLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA960
// Name: _dynamic_initializer_for__g_CDmeRigPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRig *dynamic_initializer_for__g_CDmeRigPullInModule__()
{
  g_CDmeRigPullInModule = g_CDmeRigLinkerHack;
  return g_CDmeRigLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA970
// Name: _dynamic_initializer_for__g_CDmeRigAnimSetElementsPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigAnimSetElements *dynamic_initializer_for__g_CDmeRigAnimSetElementsPullInModule__()
{
  g_CDmeRigAnimSetElementsPullInModule = g_CDmeRigAnimSetElementsLinkerHack;
  return g_CDmeRigAnimSetElementsLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA980
// Name: _dynamic_initializer_for__g_CDmeRigTwistSlavePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigTwistSlave *dynamic_initializer_for__g_CDmeRigTwistSlavePullInModule__()
{
  g_CDmeRigTwistSlavePullInModule = g_CDmeRigTwistSlaveLinkerHack;
  return g_CDmeRigTwistSlaveLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA990
// Name: _dynamic_initializer_for__g_CDmeRigTwistConstraintOperatorPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeRigTwistConstraintOperator *dynamic_initializer_for__g_CDmeRigTwistConstraintOperatorPullInModule__()
{
  g_CDmeRigTwistConstraintOperatorPullInModule = g_CDmeRigTwistConstraintOperatorLinkerHack;
  return g_CDmeRigTwistConstraintOperatorLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA9A0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleBasePullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFlexRuleBase *dynamic_initializer_for__g_CDmeFlexRuleBasePullInModule__()
{
  g_CDmeFlexRuleBasePullInModule = g_CDmeFlexRuleBaseLinkerHack;
  return g_CDmeFlexRuleBaseLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA9B0
// Name: _dynamic_initializer_for__g_CDmeFlexRulePassThroughPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFlexRulePassThrough *dynamic_initializer_for__g_CDmeFlexRulePassThroughPullInModule__()
{
  g_CDmeFlexRulePassThroughPullInModule = g_CDmeFlexRulePassThroughLinkerHack;
  return g_CDmeFlexRulePassThroughLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA9C0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleExpressionPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFlexRuleExpression *dynamic_initializer_for__g_CDmeFlexRuleExpressionPullInModule__()
{
  g_CDmeFlexRuleExpressionPullInModule = g_CDmeFlexRuleExpressionLinkerHack;
  return g_CDmeFlexRuleExpressionLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA9D0
// Name: _dynamic_initializer_for__g_CDmeFlexRuleLocalVarPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFlexRuleLocalVar *dynamic_initializer_for__g_CDmeFlexRuleLocalVarPullInModule__()
{
  g_CDmeFlexRuleLocalVarPullInModule = g_CDmeFlexRuleLocalVarLinkerHack;
  return g_CDmeFlexRuleLocalVarLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA9E0
// Name: _dynamic_initializer_for__g_CDmeFlexRulesPullInModule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmeFlexRules *dynamic_initializer_for__g_CDmeFlexRulesPullInModule__()
{
  g_CDmeFlexRulesPullInModule = g_CDmeFlexRulesLinkerHack;
  return g_CDmeFlexRulesLinkerHack;
}

//------------------------------------------------------------------------------
// Address: 0x005AA9F0
// Name: _dynamic_initializer_for__g_DataModel__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_DataModel__()
{
  CDataModel::CDataModel(this: &g_DataModel);
  return atexit(func: dynamic_atexit_destructor_for__g_DataModel__);
}

//------------------------------------------------------------------------------
// Address: 0x005AAA10
// Name: _dynamic_initializer_for__DmAttributeList_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__DmAttributeList_t::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &DmAttributeList_t::s_Allocator,
    blockSize: 8,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "DmAttributeList_t pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__DmAttributeList_t::s_Allocator__);
}

} // namespace dmxedit

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00402D20
// Name: float ExponentialDecay(float,float,float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl ExponentialDecay(float decayTo, float decayTime, float dt)
{
  long double v3; // st7
  long double v4; // rt1

  v3 = __FYL2X__(decayTo, 0.6931471805599453094) / decayTime * dt * 1.442695040888963407;
  v4 = rint(v3);
  return __FSCALE__(__F2XM1__(v3 - v4) + 1.0, v4);
}

//------------------------------------------------------------------------------
// Address: 0x00402D50
// Name: char const __near * Interpolator_NameForInterpolator(int,bool)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Interpolator_NameForInterpolator(unsigned int type, bool printname)
{
  const char *result; // eax

  if ( type >= 0x10 )
  {
    result = g_InterpolatorNameMap[0].printname;
    if ( !printname )
      return g_InterpolatorNameMap[0].name;
  }
  else if ( printname )
  {
    return g_InterpolatorNameMap[type].printname;
  }
  else
  {
    return g_InterpolatorNameMap[type].name;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402D90
// Name: char const __near * Interpolator_NameForCurveType(int,bool)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Interpolator_NameForCurveType(__int16 type, bool printname)
{
  const char *name; // ecx
  const char *v3; // ecx
  const char *v4; // eax

  if ( printname )
  {
    if ( (unsigned __int8)type >= 0x10u )
      v3 = g_InterpolatorNameMap[0].printname;
    else
      v3 = g_InterpolatorNameMap[(unsigned __int8)type].printname;
    if ( HIBYTE(type) >= 0x10u )
      v4 = g_InterpolatorNameMap[0].printname;
    else
      v4 = g_InterpolatorNameMap[HIBYTE(type)].printname;
    V_snprintf(pDest: outname, maxLen: 256, pFormat: "%s <-> %s", v4, v3);
  }
  else
  {
    if ( (unsigned __int8)type >= 0x10u )
      name = g_InterpolatorNameMap[0].name;
    else
      name = g_InterpolatorNameMap[(unsigned __int8)type].name;
    if ( HIBYTE(type) >= 0x10u )
      V_snprintf(pDest: outname, maxLen: 256, pFormat: "curve_%s_to_curve_%s", g_InterpolatorNameMap[0].name, name);
    else
      V_snprintf(
        pDest: outname,
        maxLen: 256,
        pFormat: "curve_%s_to_curve_%s",
        g_InterpolatorNameMap[HIBYTE(type)].name,
        name);
  }
  return outname;
}

//------------------------------------------------------------------------------
// Address: 0x00402E50
// Name: void Interpolator_CurveInterpolatorsForType(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_CurveInterpolatorsForType(__int16 type, int *inbound, int *outbound)
{
  *inbound = HIBYTE(type);
  *outbound = (unsigned __int8)type;
}

//------------------------------------------------------------------------------
// Address: 0x00402E80
// Name: void Interpolator_GetKochanekBartelsParams(int,float __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_GetKochanekBartelsParams(
        int interpolationType,
        float *tension,
        float *bias,
        float *continuity)
{
  float *v4; // ecx
  float *v5; // edx
  float *v6; // eax
  int v7; // xmm1_4

  if ( interpolationType == 7 )
  {
    v7 = 0;
    goto LABEL_8;
  }
  if ( interpolationType == 8 )
  {
    v7 = -1082130432;
LABEL_8:
    v5 = continuity;
    v4 = bias;
    v6 = tension;
    goto LABEL_9;
  }
  v4 = bias;
  v5 = continuity;
  v6 = tension;
  if ( interpolationType != 9 )
  {
    *tension = 0.0;
    *bias = 0.0;
    *continuity = 0.0;
    return;
  }
  v7 = 1065353216;
LABEL_9:
  *v6 = 0.76999998;
  *(_DWORD *)v4 = v7;
  *v5 = 0.76999998;
}

//------------------------------------------------------------------------------
// Address: 0x00402EF0
// Name: void Interpolator_CurveInterpolate(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl Interpolator_CurveInterpolate(
        float interpolationType,
        const Vector *vPre,
        const Vector *vStart,
        const Vector *vEnd,
        const Vector *vNext,
        float f,
        float vOut)
{
  int v7; // eax
  Vector *v8; // esi
  double v9; // xmm0_8
  float v10; // xmm0_4
  const Vector *v11; // eax
  const Vector *v12; // ecx
  double v13; // xmm0_8
  float v14; // xmm1_4
  const Vector *v15; // eax
  const Vector *v16; // ecx
  long double y; // st7
  const Vector *v18; // edi
  float decayTime; // xmm0_4
  long double v20; // st7
  long double tension; // [esp+24h] [ebp-8h] OVERLAPPED BYREF

  v7 = LODWORD(interpolationType);
  v8 = (Vector *)LODWORD(vOut);
  *(_DWORD *)LODWORD(vOut) = 0;
  v8->y = 0.0;
  v8->z = 0.0;
  switch ( v7 )
  {
    case 0:
    case 1:
      goto $LN15;
    case 2:
      v9 = f * 3.141592653589793 * 0.5;
      __libm_sse2_sin(x: tension);
      v10 = v9;
      goto LABEL_6;
    case 3:
      v13 = f * 3.141592653589793 * 0.5 + 1.570796326794897;
      __libm_sse2_sin(x: tension);
      v10 = 1.0 - v13;
LABEL_6:
      v11 = vStart;
      v12 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v10) + vStart->x;
      v8->y = (float)((float)(v12->y - v11->y) * v10) + v11->y;
      v8->z = (float)((float)(v12->z - v11->z) * v10) + v11->z;
      return;
    case 4:
      v14 = (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f);
      goto LABEL_9;
    case 5:
      BSpline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      return;
    case 6:
      v14 = f;
LABEL_9:
      v15 = vStart;
      v16 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v14) + vStart->x;
      v8->y = (float)((float)(v16->y - v15->y) * v14) + v15->y;
      v8->z = (float)((float)(v16->z - v15->z) * v14) + v15->z;
      break;
    case 7:
    case 8:
    case 9:
      HIDWORD(tension) = 0;
      interpolationType = 0.0;
      vOut = 0.0;
      Interpolator_GetKochanekBartelsParams(
        interpolationType: v7,
        tension: (float *)&tension + 1,
        bias: &interpolationType,
        continuity: &vOut);
      Kochanek_Bartels_Spline_NormalizeX(
        tension: *((float *)&tension + 1),
        bias: interpolationType,
        continuity: vOut,
        p1: vPre,
        p2: vStart,
        p3: vEnd,
        p4: vNext,
        t: f,
        output: v8);
      break;
    case 10:
      Cubic_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 11:
      Catmull_Rom_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 12:
      Catmull_Rom_Spline_Normalize(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 13:
      Catmull_Rom_Spline_Tangent(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 14:
      y = vStart->y;
      v18 = vEnd;
      decayTime = vEnd->x - vStart->x;
      if ( decayTime > 0.0 )
      {
        vOut = vStart->y;
        v20 = ExponentialDecay(decayTo: 0.001, decayTime, dt: decayTime * f);
        y = vOut + (v18->y - vOut) * (1.0 - v20);
      }
      v8->y = y;
      break;
    case 15:
      v8->y = vStart->y;
      break;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", v7);
$LN15:
      Catmull_Rom_Spline_NormalizeX(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403270
// Name: void Interpolator_CurveInterpolate_NonNormalized(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl Interpolator_CurveInterpolate_NonNormalized(
        float interpolationType,
        const Vector *vPre,
        const Vector *vStart,
        const Vector *vEnd,
        const Vector *vNext,
        float f,
        float vOut)
{
  int v7; // eax
  Vector *v8; // esi
  double v9; // xmm0_8
  float v10; // xmm0_4
  const Vector *v11; // eax
  const Vector *v12; // ecx
  double v13; // xmm0_8
  float v14; // xmm1_4
  const Vector *v15; // eax
  const Vector *v16; // ecx
  long double y; // st7
  const Vector *v18; // edi
  float decayTime; // xmm0_4
  long double v20; // st7
  long double tension; // [esp+24h] [ebp-8h] OVERLAPPED BYREF

  v7 = LODWORD(interpolationType);
  v8 = (Vector *)LODWORD(vOut);
  *(_DWORD *)LODWORD(vOut) = 0;
  v8->y = 0.0;
  v8->z = 0.0;
  switch ( v7 )
  {
    case 0:
    case 1:
    case 11:
    case 12:
    case 13:
      goto $LN12_0;
    case 2:
      v9 = f * 3.141592653589793 * 0.5;
      __libm_sse2_sin(x: tension);
      v10 = v9;
      goto LABEL_3;
    case 3:
      v13 = f * 3.141592653589793 * 0.5 + 1.570796326794897;
      __libm_sse2_sin(x: tension);
      v10 = 1.0 - v13;
LABEL_3:
      v11 = vStart;
      v12 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v10) + vStart->x;
      v8->y = (float)((float)(v12->y - v11->y) * v10) + v11->y;
      v8->z = (float)((float)(v12->z - v11->z) * v10) + v11->z;
      return;
    case 4:
      v14 = (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f);
      goto LABEL_6;
    case 5:
      BSpline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      return;
    case 6:
      v14 = f;
LABEL_6:
      v15 = vStart;
      v16 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v14) + vStart->x;
      v8->y = (float)((float)(v16->y - v15->y) * v14) + v15->y;
      v8->z = (float)((float)(v16->z - v15->z) * v14) + v15->z;
      break;
    case 7:
    case 8:
    case 9:
      HIDWORD(tension) = 0;
      interpolationType = 0.0;
      vOut = 0.0;
      Interpolator_GetKochanekBartelsParams(
        interpolationType: v7,
        tension: (float *)&tension + 1,
        bias: &interpolationType,
        continuity: &vOut);
      Kochanek_Bartels_Spline(
        tension: *((float *)&tension + 1),
        bias: interpolationType,
        continuity: vOut,
        p1: vPre,
        p2: vStart,
        p3: vEnd,
        p4: vNext,
        t: f,
        output: v8);
      break;
    case 10:
      Cubic_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 14:
      y = vStart->y;
      v18 = vEnd;
      decayTime = vEnd->x - vStart->x;
      if ( decayTime > 0.0 )
      {
        vOut = vStart->y;
        v20 = ExponentialDecay(decayTo: 0.001, decayTime, dt: decayTime * f);
        y = vOut + (v18->y - vOut) * (1.0 - v20);
      }
      v8->y = y;
      break;
    case 15:
      v8->y = vStart->y;
      break;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", v7);
$LN12_0:
      Catmull_Rom_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403570
// Name: void Interpolator_CurveInterpolate_NonNormalized(int,class Quaternion const __near &,class Quaternion const __near &,class Quaternion const __near &,class Quaternion const __near &,float,class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall Interpolator_CurveInterpolate_NonNormalized(
        int a1@<esi>,
        int interpolationType,
        const Quaternion *vPre,
        const Quaternion *vStart,
        const Quaternion *vEnd,
        const Quaternion *vNext,
        float f,
        Quaternion *vOut)
{
  float t; // xmm0_4
  float v9; // xmm0_4
  long double v10; // [esp+4h] [ebp-8h]
  Quaternion *v11; // [esp+4h] [ebp-8h]
  Quaternion *v12; // [esp+4h] [ebp-8h]

  HIDWORD(v10) = a1;
  vOut->x = 0.0;
  vOut->y = 0.0;
  vOut->z = 0.0;
  vOut->w = 0.0;
  switch ( interpolationType )
  {
    case 0:
    case 1:
    case 5:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
      goto $LN7_1;
    case 2:
      LODWORD(v10) = vOut;
      __libm_sse2_sin(x: v10);
      t = f * 3.141592653589793 * 0.5;
      QuaternionSlerp(p: vStart, q: vEnd, t, qt: v11);
      return;
    case 3:
      LODWORD(v10) = vOut;
      __libm_sse2_sin(x: v10);
      v9 = 1.0 - (f * 3.141592653589793 * 0.5 + 1.570796326794897);
      goto LABEL_10;
    case 4:
      QuaternionSlerp(
        p: vStart,
        q: vEnd,
        t: (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f),
        qt: vOut);
      return;
    case 6:
      QuaternionSlerp(p: vStart, q: vEnd, t: f, qt: vOut);
      return;
    case 14:
      vOut->x = 0.0;
      vOut->y = 0.0;
      vOut->z = 0.0;
      vOut->w = 0.0;
      return;
    case 15:
      *vOut = *vStart;
      return;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", interpolationType);
$LN7_1:
      v9 = f;
      v12 = vOut;
LABEL_10:
      QuaternionSlerp(p: vStart, q: vEnd, t: v9, qt: v12);
      return;
  }
}

} // namespace elementviewer

// ============================================================
// Overlay from hlfaceposer (Missing functions)
// ============================================================
namespace hlfaceposer {

//------------------------------------------------------------------------------
// Address: 0x00409930
// Name: float ExponentialDecay(float,float,float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl ExponentialDecay(float decayTo, float decayTime, float dt)
{
  long double v3; // st7
  long double v4; // rt1

  v3 = __FYL2X__(decayTo, 0.6931471805599453094) / decayTime * dt * 1.442695040888963407;
  v4 = rint(v3);
  return __FSCALE__(__F2XM1__(v3 - v4) + 1.0, v4);
}

//------------------------------------------------------------------------------
// Address: 0x00409960
// Name: int Interpolator_InterpolatorForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Interpolator_InterpolatorForName(const char *name)
{
  InterpolatorNameMap_t *v1; // esi

  v1 = g_InterpolatorNameMap;
  while ( _V_stricmp(s1: name, s2: v1->name) != 0 )
  {
    if ( (int)++v1 >= (int)g_CurveNameMap )
      return 0;
  }
  return v1->type;
}

//------------------------------------------------------------------------------
// Address: 0x004099A0
// Name: char const __near * Interpolator_NameForInterpolator(int,bool)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Interpolator_NameForInterpolator(unsigned int type, bool printname)
{
  const char *result; // eax

  if ( type >= 0x10 )
  {
    result = g_InterpolatorNameMap[0].printname;
    if ( !printname )
      return g_InterpolatorNameMap[0].name;
  }
  else if ( printname )
  {
    return g_InterpolatorNameMap[type].printname;
  }
  else
  {
    return g_InterpolatorNameMap[type].name;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004099E0
// Name: int Interpolator_CurveTypeForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Interpolator_CurveTypeForName(const char *name)
{
  unsigned __int8 v1; // bl
  unsigned __int8 v2; // si
  int v3; // edi
  char *v4; // edi
  char *v5; // esi
  char v6; // bl
  int v7; // eax
  unsigned __int8 v8; // al
  char sz[128]; // [esp+Ch] [ebp-84h] BYREF
  int leftcurve; // [esp+8Ch] [ebp-4h]

  V_strncpy(pDest: sz, pSrc: name, maxLen: 128);
  v1 = 0;
  v2 = 0;
  v3 = _V_strlen(str: "curve_");
  if ( V_strnicmp(s1: sz, s2: "curve_", n: v3) == 0 )
  {
    v4 = &sz[v3];
    v5 = V_stristr(pStr: v4, pSearch: "_to_curve_");
    v6 = *v5;
    *v5 = 0;
    leftcurve = Interpolator_InterpolatorForName(name: v4);
    *v5 = v6;
    v7 = _V_strlen(str: "_to_curve_");
    v8 = Interpolator_InterpolatorForName(name: &v5[v7]);
    v1 = leftcurve;
    v2 = v8;
  }
  return v2 | (v1 << 8);
}

//------------------------------------------------------------------------------
// Address: 0x00409A90
// Name: char const __near * Interpolator_NameForCurveType(int,bool)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Interpolator_NameForCurveType(__int16 type, bool printname)
{
  const char *name; // ecx
  const char *v3; // ecx
  const char *v4; // eax

  if ( printname )
  {
    if ( (unsigned __int8)type >= 0x10u )
      v3 = g_InterpolatorNameMap[0].printname;
    else
      v3 = g_InterpolatorNameMap[(unsigned __int8)type].printname;
    if ( HIBYTE(type) >= 0x10u )
      v4 = g_InterpolatorNameMap[0].printname;
    else
      v4 = g_InterpolatorNameMap[HIBYTE(type)].printname;
    V_snprintf(pDest: outname, maxLen: 256, pFormat: "%s <-> %s", v4, v3);
  }
  else
  {
    if ( (unsigned __int8)type >= 0x10u )
      name = g_InterpolatorNameMap[0].name;
    else
      name = g_InterpolatorNameMap[(unsigned __int8)type].name;
    if ( HIBYTE(type) >= 0x10u )
      V_snprintf(pDest: outname, maxLen: 256, pFormat: "curve_%s_to_curve_%s", g_InterpolatorNameMap[0].name, name);
    else
      V_snprintf(
        pDest: outname,
        maxLen: 256,
        pFormat: "curve_%s_to_curve_%s",
        g_InterpolatorNameMap[HIBYTE(type)].name,
        name);
  }
  return outname;
}

//------------------------------------------------------------------------------
// Address: 0x00409B50
// Name: void Interpolator_CurveInterpolatorsForType(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_CurveInterpolatorsForType(__int16 type, int *inbound, int *outbound)
{
  *inbound = HIBYTE(type);
  *outbound = (unsigned __int8)type;
}

//------------------------------------------------------------------------------
// Address: 0x00409B80
// Name: int Interpolator_CurveTypeForHotkey(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Interpolator_CurveTypeForHotkey(int key)
{
  CurveNameMap_t *v1; // eax

  v1 = g_CurveNameMap;
  while ( v1->hotkey != key )
  {
    if ( (int)++v1 >= (int)&vec2_invalid_8 )
      return -1;
  }
  return v1->type;
}

//------------------------------------------------------------------------------
// Address: 0x00409BB0
// Name: void Interpolator_GetKochanekBartelsParams(int,float __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_GetKochanekBartelsParams(
        int interpolationType,
        float *tension,
        float *bias,
        float *continuity)
{
  float *v4; // ecx
  float *v5; // edx
  float *v6; // eax
  int v7; // xmm1_4

  if ( interpolationType == 7 )
  {
    v7 = 0;
    goto LABEL_8;
  }
  if ( interpolationType == 8 )
  {
    v7 = -1082130432;
LABEL_8:
    v5 = continuity;
    v4 = bias;
    v6 = tension;
    goto LABEL_9;
  }
  v4 = bias;
  v5 = continuity;
  v6 = tension;
  if ( interpolationType != 9 )
  {
    *tension = 0.0;
    *bias = 0.0;
    *continuity = 0.0;
    return;
  }
  v7 = 1065353216;
LABEL_9:
  *v6 = 0.76999998;
  *(_DWORD *)v4 = v7;
  *v5 = 0.76999998;
}

//------------------------------------------------------------------------------
// Address: 0x00409C20
// Name: void Interpolator_CurveInterpolate(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl Interpolator_CurveInterpolate(
        float interpolationType,
        const Vector *vPre,
        const Vector *vStart,
        const Vector *vEnd,
        const Vector *vNext,
        float f,
        float vOut)
{
  int v7; // eax
  Vector *v8; // esi
  double v9; // xmm0_8
  float v10; // xmm0_4
  const Vector *v11; // eax
  const Vector *v12; // ecx
  double v13; // xmm0_8
  float v14; // xmm1_4
  const Vector *v15; // eax
  const Vector *v16; // ecx
  long double y; // st7
  const Vector *v18; // edi
  float decayTime; // xmm0_4
  long double v20; // st7
  long double tension; // [esp+24h] [ebp-8h] OVERLAPPED BYREF

  v7 = LODWORD(interpolationType);
  v8 = (Vector *)LODWORD(vOut);
  *(_DWORD *)LODWORD(vOut) = 0;
  v8->y = 0.0;
  v8->z = 0.0;
  switch ( v7 )
  {
    case 0:
    case 1:
      goto $LN15;
    case 2:
      v9 = f * 3.141592653589793 * 0.5;
      __libm_sse2_sin(x: tension);
      v10 = v9;
      goto LABEL_6;
    case 3:
      v13 = f * 3.141592653589793 * 0.5 + 1.570796326794897;
      __libm_sse2_sin(x: tension);
      v10 = 1.0 - v13;
LABEL_6:
      v11 = vStart;
      v12 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v10) + vStart->x;
      v8->y = (float)((float)(v12->y - v11->y) * v10) + v11->y;
      v8->z = (float)((float)(v12->z - v11->z) * v10) + v11->z;
      return;
    case 4:
      v14 = (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f);
      goto LABEL_9;
    case 5:
      BSpline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      return;
    case 6:
      v14 = f;
LABEL_9:
      v15 = vStart;
      v16 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v14) + vStart->x;
      v8->y = (float)((float)(v16->y - v15->y) * v14) + v15->y;
      v8->z = (float)((float)(v16->z - v15->z) * v14) + v15->z;
      break;
    case 7:
    case 8:
    case 9:
      HIDWORD(tension) = 0;
      interpolationType = 0.0;
      vOut = 0.0;
      Interpolator_GetKochanekBartelsParams(
        interpolationType: v7,
        tension: (float *)&tension + 1,
        bias: &interpolationType,
        continuity: &vOut);
      Kochanek_Bartels_Spline_NormalizeX(
        tension: *((float *)&tension + 1),
        bias: interpolationType,
        continuity: vOut,
        p1: vPre,
        p2: vStart,
        p3: vEnd,
        p4: vNext,
        t: f,
        output: v8);
      break;
    case 10:
      Cubic_Spline_NormalizeX(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 11:
      Catmull_Rom_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 12:
      Catmull_Rom_Spline_Normalize(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 13:
      Catmull_Rom_Spline_Tangent(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 14:
      y = vStart->y;
      v18 = vEnd;
      decayTime = vEnd->x - vStart->x;
      if ( decayTime > 0.0 )
      {
        vOut = vStart->y;
        v20 = ExponentialDecay(decayTo: 0.001, decayTime, dt: decayTime * f);
        y = vOut + (v18->y - vOut) * (1.0 - v20);
      }
      v8->y = y;
      break;
    case 15:
      v8->y = vStart->y;
      break;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", v7);
$LN15:
      Catmull_Rom_Spline_NormalizeX(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
  }
}

} // namespace hlfaceposer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x100479A0
// Name: float ExponentialDecay(float,float,float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl ExponentialDecay(float decayTo, float decayTime, float dt)
{
  long double v3; // st7
  long double v4; // rt1

  v3 = __FYL2X__(decayTo, 0.6931471805599453094) / decayTime * dt * 1.442695040888963407;
  v4 = rint(v3);
  return __FSCALE__(__F2XM1__(v3 - v4) + 1.0, v4);
}

//------------------------------------------------------------------------------
// Address: 0x100479D0
// Name: int Interpolator_InterpolatorForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Interpolator_InterpolatorForName(const char *name)
{
  InterpolatorNameMap_t *v1; // esi

  v1 = g_InterpolatorNameMap;
  while ( _V_stricmp(s1: name, s2: v1->name) != 0 )
  {
    if ( (int)++v1 >= (int)g_CurveNameMap )
      return 0;
  }
  return v1->type;
}

//------------------------------------------------------------------------------
// Address: 0x10047A10
// Name: char const __near * Interpolator_NameForInterpolator(int,bool)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Interpolator_NameForInterpolator(unsigned int type, bool printname)
{
  const char *result; // eax

  if ( type >= 0x10 )
  {
    result = g_InterpolatorNameMap[0].printname;
    if ( !printname )
      return g_InterpolatorNameMap[0].name;
  }
  else if ( printname )
  {
    return g_InterpolatorNameMap[type].printname;
  }
  else
  {
    return g_InterpolatorNameMap[type].name;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10047A50
// Name: int Interpolator_CurveTypeForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Interpolator_CurveTypeForName(const char *name)
{
  unsigned __int8 v1; // bl
  unsigned __int8 v2; // si
  unsigned int v3; // edi
  char *v4; // edi
  char *v5; // esi
  char v6; // bl
  unsigned int v7; // eax
  unsigned __int8 v8; // al
  char sz[128]; // [esp+Ch] [ebp-84h] BYREF
  int leftcurve; // [esp+8Ch] [ebp-4h]

  V_strncpy(pDest: sz, pSrc: name, maxLen: 128);
  v1 = 0;
  v2 = 0;
  v3 = std::char_traits<char>::length(str: "curve_");
  if ( V_strnicmp(s1: sz, s2: "curve_", n: v3) == 0 )
  {
    v4 = &sz[v3];
    v5 = V_stristr(pStr: v4, pSearch: "_to_curve_");
    v6 = *v5;
    *v5 = 0;
    leftcurve = Interpolator_InterpolatorForName(name: v4);
    *v5 = v6;
    v7 = std::char_traits<char>::length(str: "_to_curve_");
    v8 = Interpolator_InterpolatorForName(name: &v5[v7]);
    v1 = leftcurve;
    v2 = v8;
  }
  return v2 | (v1 << 8);
}

//------------------------------------------------------------------------------
// Address: 0x10047B00
// Name: char const __near * Interpolator_NameForCurveType(int,bool)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Interpolator_NameForCurveType(__int16 type, bool printname)
{
  const char *name; // ecx
  const char *v3; // ecx
  const char *v4; // eax

  if ( printname )
  {
    if ( (unsigned __int8)type >= 0x10u )
      v3 = g_InterpolatorNameMap[0].printname;
    else
      v3 = g_InterpolatorNameMap[(unsigned __int8)type].printname;
    if ( HIBYTE(type) >= 0x10u )
      v4 = g_InterpolatorNameMap[0].printname;
    else
      v4 = g_InterpolatorNameMap[HIBYTE(type)].printname;
    V_snprintf(pDest: outname, maxLen: 256, pFormat: "%s <-> %s", v4, v3);
  }
  else
  {
    if ( (unsigned __int8)type >= 0x10u )
      name = g_InterpolatorNameMap[0].name;
    else
      name = g_InterpolatorNameMap[(unsigned __int8)type].name;
    if ( HIBYTE(type) >= 0x10u )
      V_snprintf(pDest: outname, maxLen: 256, pFormat: "curve_%s_to_curve_%s", g_InterpolatorNameMap[0].name, name);
    else
      V_snprintf(
        pDest: outname,
        maxLen: 256,
        pFormat: "curve_%s_to_curve_%s",
        g_InterpolatorNameMap[HIBYTE(type)].name,
        name);
  }
  return outname;
}

//------------------------------------------------------------------------------
// Address: 0x10047BC0
// Name: void Interpolator_CurveInterpolatorsForType(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_CurveInterpolatorsForType(__int16 type, int *inbound, int *outbound)
{
  *inbound = HIBYTE(type);
  *outbound = (unsigned __int8)type;
}

//------------------------------------------------------------------------------
// Address: 0x10047BF0
// Name: void Interpolator_GetKochanekBartelsParams(int,float __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_GetKochanekBartelsParams(
        int interpolationType,
        float *tension,
        float *bias,
        float *continuity)
{
  float *v4; // ecx
  float *v5; // edx
  float *v6; // eax
  int v7; // xmm1_4

  if ( interpolationType == 7 )
  {
    v7 = 0;
    goto LABEL_8;
  }
  if ( interpolationType == 8 )
  {
    v7 = -1082130432;
LABEL_8:
    v5 = continuity;
    v4 = bias;
    v6 = tension;
    goto LABEL_9;
  }
  v4 = bias;
  v5 = continuity;
  v6 = tension;
  if ( interpolationType != 9 )
  {
    *tension = 0.0;
    *bias = 0.0;
    *continuity = 0.0;
    return;
  }
  v7 = 1065353216;
LABEL_9:
  *v6 = 0.76999998;
  *(_DWORD *)v4 = v7;
  *v5 = 0.76999998;
}

//------------------------------------------------------------------------------
// Address: 0x10047C60
// Name: void Interpolator_CurveInterpolate(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_CurveInterpolate(
        float interpolationType,
        const Vector *vPre,
        const Vector *vStart,
        const Vector *vEnd,
        const Vector *vNext,
        float f,
        float vOut)
{
  int v7; // eax
  Vector *v8; // esi
  double v9; // xmm0_8
  float v10; // xmm0_4
  const Vector *v11; // eax
  const Vector *v12; // ecx
  double v13; // xmm0_8
  float v14; // xmm1_4
  const Vector *v15; // eax
  const Vector *v16; // ecx
  long double y; // st7
  const Vector *v18; // edi
  float v19; // xmm0_4
  long double v20; // st7
  long double v21; // [esp-4h] [ebp-8h] BYREF

  v7 = LODWORD(interpolationType);
  v8 = (Vector *)LODWORD(vOut);
  *(_DWORD *)LODWORD(vOut) = 0;
  v8->y = 0.0;
  v8->z = 0.0;
  switch ( v7 )
  {
    case 0:
    case 1:
      goto $LN15_1;
    case 2:
      v9 = f * 3.141592653589793 * 0.5;
      __libm_sse2_sin(x: v21);
      v10 = v9;
      goto LABEL_6;
    case 3:
      v13 = f * 3.141592653589793 * 0.5 + 1.570796326794897;
      __libm_sse2_sin(x: v21);
      v10 = 1.0 - v13;
LABEL_6:
      v11 = vStart;
      v12 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v10) + vStart->x;
      v8->y = (float)((float)(v12->y - v11->y) * v10) + v11->y;
      v8->z = (float)((float)(v12->z - v11->z) * v10) + v11->z;
      return;
    case 4:
      v14 = (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f);
      goto LABEL_9;
    case 5:
      BSpline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      return;
    case 6:
      v14 = f;
LABEL_9:
      v15 = vStart;
      v16 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v14) + vStart->x;
      v8->y = (float)((float)(v16->y - v15->y) * v14) + v15->y;
      v8->z = (float)((float)(v16->z - v15->z) * v14) + v15->z;
      break;
    case 7:
    case 8:
    case 9:
      HIDWORD(v21) = 0;
      interpolationType = 0.0;
      vOut = 0.0;
      Interpolator_GetKochanekBartelsParams(
        interpolationType: v7,
        tension: (float *)&v21 + 1,
        bias: &interpolationType,
        continuity: &vOut);
      Kochanek_Bartels_Spline_NormalizeX(
        tension: *((float *)&v21 + 1),
        bias: interpolationType,
        continuity: vOut,
        p1: vPre,
        p2: vStart,
        p3: vEnd,
        p4: vNext,
        t: f,
        output: v8);
      break;
    case 10:
      Cubic_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 11:
      Catmull_Rom_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 12:
      Catmull_Rom_Spline_Normalize(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 13:
      Catmull_Rom_Spline_Tangent(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 14:
      y = vStart->y;
      v18 = vEnd;
      v19 = vEnd->x - vStart->x;
      if ( v19 > 0.0 )
      {
        vOut = vStart->y;
        v20 = ExponentialDecay(decayTo: 0.001, decayTime: v19, dt: v19 * f);
        y = vOut + (v18->y - vOut) * (1.0 - v20);
      }
      v8->y = y;
      break;
    case 15:
      v8->y = vStart->y;
      break;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", v7);
$LN15_1:
      Catmull_Rom_Spline_NormalizeX(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047FE0
// Name: void Interpolator_CurveInterpolate_NonNormalized(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_CurveInterpolate_NonNormalized(
        float interpolationType,
        const Vector *vPre,
        const Vector *vStart,
        const Vector *vEnd,
        const Vector *vNext,
        float f,
        float vOut)
{
  int v7; // eax
  Vector *v8; // esi
  double v9; // xmm0_8
  float v10; // xmm0_4
  const Vector *v11; // eax
  const Vector *v12; // ecx
  double v13; // xmm0_8
  float v14; // xmm1_4
  const Vector *v15; // eax
  const Vector *v16; // ecx
  long double y; // st7
  const Vector *v18; // edi
  float v19; // xmm0_4
  long double v20; // st7
  long double v21; // [esp-4h] [ebp-8h] BYREF

  v7 = LODWORD(interpolationType);
  v8 = (Vector *)LODWORD(vOut);
  *(_DWORD *)LODWORD(vOut) = 0;
  v8->y = 0.0;
  v8->z = 0.0;
  switch ( v7 )
  {
    case 0:
    case 1:
    case 11:
    case 12:
    case 13:
      goto $LN12_12;
    case 2:
      v9 = f * 3.141592653589793 * 0.5;
      __libm_sse2_sin(x: v21);
      v10 = v9;
      goto LABEL_3;
    case 3:
      v13 = f * 3.141592653589793 * 0.5 + 1.570796326794897;
      __libm_sse2_sin(x: v21);
      v10 = 1.0 - v13;
LABEL_3:
      v11 = vStart;
      v12 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v10) + vStart->x;
      v8->y = (float)((float)(v12->y - v11->y) * v10) + v11->y;
      v8->z = (float)((float)(v12->z - v11->z) * v10) + v11->z;
      return;
    case 4:
      v14 = (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f);
      goto LABEL_6;
    case 5:
      BSpline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      return;
    case 6:
      v14 = f;
LABEL_6:
      v15 = vStart;
      v16 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v14) + vStart->x;
      v8->y = (float)((float)(v16->y - v15->y) * v14) + v15->y;
      v8->z = (float)((float)(v16->z - v15->z) * v14) + v15->z;
      break;
    case 7:
    case 8:
    case 9:
      HIDWORD(v21) = 0;
      interpolationType = 0.0;
      vOut = 0.0;
      Interpolator_GetKochanekBartelsParams(
        interpolationType: v7,
        tension: (float *)&v21 + 1,
        bias: &interpolationType,
        continuity: &vOut);
      Kochanek_Bartels_Spline(
        tension: *((float *)&v21 + 1),
        bias: interpolationType,
        continuity: vOut,
        p1: vPre,
        p2: vStart,
        p3: vEnd,
        p4: vNext,
        t: f,
        output: v8);
      break;
    case 10:
      Cubic_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 14:
      y = vStart->y;
      v18 = vEnd;
      v19 = vEnd->x - vStart->x;
      if ( v19 > 0.0 )
      {
        vOut = vStart->y;
        v20 = ExponentialDecay(decayTo: 0.001, decayTime: v19, dt: v19 * f);
        y = vOut + (v18->y - vOut) * (1.0 - v20);
      }
      v8->y = y;
      break;
    case 15:
      v8->y = vStart->y;
      break;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", v7);
$LN12_12:
      Catmull_Rom_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100482E0
// Name: void Interpolator_CurveInterpolate_NonNormalized(int,class Quaternion const __near &,class Quaternion const __near &,class Quaternion const __near &,class Quaternion const __near &,float,class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall Interpolator_CurveInterpolate_NonNormalized(
        int a1@<esi>,
        int interpolationType,
        const Quaternion *vPre,
        const Quaternion *vStart,
        const Quaternion *vEnd,
        const Quaternion *vNext,
        float f,
        Quaternion *vOut)
{
  float v8; // xmm0_4
  float v9; // xmm0_4
  long double v10; // [esp-8h] [ebp-8h]
  Quaternion *v11; // [esp-8h] [ebp-8h]
  Quaternion *v12; // [esp-8h] [ebp-8h]

  HIDWORD(v10) = a1;
  vOut->x = 0.0;
  vOut->y = 0.0;
  vOut->z = 0.0;
  vOut->w = 0.0;
  switch ( interpolationType )
  {
    case 0:
    case 1:
    case 5:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
      goto $LN7_24;
    case 2:
      LODWORD(v10) = vOut;
      __libm_sse2_sin(x: v10);
      v8 = f * 3.141592653589793 * 0.5;
      QuaternionSlerp(p: vStart, q: vEnd, t: v8, qt: v11);
      return;
    case 3:
      LODWORD(v10) = vOut;
      __libm_sse2_sin(x: v10);
      v9 = 1.0 - (f * 3.141592653589793 * 0.5 + 1.570796326794897);
      goto LABEL_10;
    case 4:
      QuaternionSlerp(
        p: vStart,
        q: vEnd,
        t: (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f),
        qt: vOut);
      return;
    case 6:
      QuaternionSlerp(p: vStart, q: vEnd, t: f, qt: vOut);
      return;
    case 14:
      vOut->x = 0.0;
      vOut->y = 0.0;
      vOut->z = 0.0;
      vOut->w = 0.0;
      return;
    case 15:
      *vOut = *vStart;
      return;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", interpolationType);
$LN7_24:
      v9 = f;
      v12 = vOut;
LABEL_10:
      QuaternionSlerp(p: vStart, q: vEnd, t: v9, qt: v12);
      return;
  }
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x00412AD0
// Name: float ExponentialDecay(float,float,float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl ExponentialDecay(float decayTo, float decayTime, float dt)
{
  long double v3; // st7
  long double v4; // rt1

  v3 = __FYL2X__(decayTo, 0.6931471805599453094) / decayTime * dt * 1.442695040888963407;
  v4 = rint(v3);
  return __FSCALE__(__F2XM1__(v3 - v4) + 1.0, v4);
}

//------------------------------------------------------------------------------
// Address: 0x00412B00
// Name: char const __near * Interpolator_NameForCurveType(int,bool)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Interpolator_NameForCurveType(__int16 type, bool printname)
{
  const char *name; // ecx
  const char *v3; // ecx
  const char *v4; // eax

  if ( printname )
  {
    if ( (unsigned __int8)type >= 0x10u )
      v3 = g_InterpolatorNameMap[0].printname;
    else
      v3 = g_InterpolatorNameMap[(unsigned __int8)type].printname;
    if ( HIBYTE(type) >= 0x10u )
      v4 = g_InterpolatorNameMap[0].printname;
    else
      v4 = g_InterpolatorNameMap[HIBYTE(type)].printname;
    V_snprintf(pDest: outname, maxLen: 256, pFormat: "%s <-> %s", v4, v3);
  }
  else
  {
    if ( (unsigned __int8)type >= 0x10u )
      name = g_InterpolatorNameMap[0].name;
    else
      name = g_InterpolatorNameMap[(unsigned __int8)type].name;
    if ( HIBYTE(type) >= 0x10u )
      V_snprintf(pDest: outname, maxLen: 256, pFormat: "curve_%s_to_curve_%s", g_InterpolatorNameMap[0].name, name);
    else
      V_snprintf(
        pDest: outname,
        maxLen: 256,
        pFormat: "curve_%s_to_curve_%s",
        g_InterpolatorNameMap[HIBYTE(type)].name,
        name);
  }
  return outname;
}

//------------------------------------------------------------------------------
// Address: 0x00412BC0
// Name: void Interpolator_CurveInterpolatorsForType(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_CurveInterpolatorsForType(__int16 type, int *inbound, int *outbound)
{
  *inbound = HIBYTE(type);
  *outbound = (unsigned __int8)type;
}

//------------------------------------------------------------------------------
// Address: 0x00412BF0
// Name: void Interpolator_GetKochanekBartelsParams(int,float __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_GetKochanekBartelsParams(
        int interpolationType,
        float *tension,
        float *bias,
        float *continuity)
{
  float *v4; // ecx
  float *v5; // edx
  float *v6; // eax
  int v7; // xmm1_4

  if ( interpolationType == 7 )
  {
    v7 = 0;
    goto LABEL_8;
  }
  if ( interpolationType == 8 )
  {
    v7 = -1082130432;
LABEL_8:
    v5 = continuity;
    v4 = bias;
    v6 = tension;
    goto LABEL_9;
  }
  v4 = bias;
  v5 = continuity;
  v6 = tension;
  if ( interpolationType != 9 )
  {
    *tension = 0.0;
    *bias = 0.0;
    *continuity = 0.0;
    return;
  }
  v7 = 1065353216;
LABEL_9:
  *v6 = 0.76999998;
  *(_DWORD *)v4 = v7;
  *v5 = 0.76999998;
}

//------------------------------------------------------------------------------
// Address: 0x00412C60
// Name: void Interpolator_CurveInterpolate(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl Interpolator_CurveInterpolate(
        float interpolationType,
        const Vector *vPre,
        const Vector *vStart,
        const Vector *vEnd,
        const Vector *vNext,
        float f,
        float vOut)
{
  int v7; // eax
  Vector *v8; // esi
  double v9; // xmm0_8
  float v10; // xmm0_4
  const Vector *v11; // eax
  const Vector *v12; // ecx
  double v13; // xmm0_8
  float v14; // xmm1_4
  const Vector *v15; // eax
  const Vector *v16; // ecx
  long double y; // st7
  const Vector *v18; // edi
  float decayTime; // xmm0_4
  long double v20; // st7
  long double tension; // [esp+24h] [ebp-8h] OVERLAPPED BYREF

  v7 = LODWORD(interpolationType);
  v8 = (Vector *)LODWORD(vOut);
  *(_DWORD *)LODWORD(vOut) = 0;
  v8->y = 0.0;
  v8->z = 0.0;
  switch ( v7 )
  {
    case 0:
    case 1:
      goto $LN15_0;
    case 2:
      v9 = f * 3.141592653589793 * 0.5;
      __libm_sse2_sin(x: tension);
      v10 = v9;
      goto LABEL_6;
    case 3:
      v13 = f * 3.141592653589793 * 0.5 + 1.570796326794897;
      __libm_sse2_sin(x: tension);
      v10 = 1.0 - v13;
LABEL_6:
      v11 = vStart;
      v12 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v10) + vStart->x;
      v8->y = (float)((float)(v12->y - v11->y) * v10) + v11->y;
      v8->z = (float)((float)(v12->z - v11->z) * v10) + v11->z;
      return;
    case 4:
      v14 = (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f);
      goto LABEL_9;
    case 5:
      BSpline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      return;
    case 6:
      v14 = f;
LABEL_9:
      v15 = vStart;
      v16 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v14) + vStart->x;
      v8->y = (float)((float)(v16->y - v15->y) * v14) + v15->y;
      v8->z = (float)((float)(v16->z - v15->z) * v14) + v15->z;
      break;
    case 7:
    case 8:
    case 9:
      HIDWORD(tension) = 0;
      interpolationType = 0.0;
      vOut = 0.0;
      Interpolator_GetKochanekBartelsParams(
        interpolationType: v7,
        tension: (float *)&tension + 1,
        bias: &interpolationType,
        continuity: &vOut);
      Kochanek_Bartels_Spline_NormalizeX(
        tension: *((float *)&tension + 1),
        bias: interpolationType,
        continuity: vOut,
        p1: vPre,
        p2: vStart,
        p3: vEnd,
        p4: vNext,
        t: f,
        output: v8);
      break;
    case 10:
      Cubic_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 11:
      Catmull_Rom_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 12:
      Catmull_Rom_Spline_Normalize(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 13:
      Catmull_Rom_Spline_Tangent(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 14:
      y = vStart->y;
      v18 = vEnd;
      decayTime = vEnd->x - vStart->x;
      if ( decayTime > 0.0 )
      {
        vOut = vStart->y;
        v20 = ExponentialDecay(decayTo: 0.001, decayTime, dt: decayTime * f);
        y = vOut + (v18->y - vOut) * (1.0 - v20);
      }
      v8->y = y;
      break;
    case 15:
      v8->y = vStart->y;
      break;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", v7);
$LN15_0:
      Catmull_Rom_Spline_NormalizeX(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412FE0
// Name: void Interpolator_CurveInterpolate_NonNormalized(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl Interpolator_CurveInterpolate_NonNormalized(
        float interpolationType,
        const Vector *vPre,
        const Vector *vStart,
        const Vector *vEnd,
        const Vector *vNext,
        float f,
        float vOut)
{
  int v7; // eax
  Vector *v8; // esi
  double v9; // xmm0_8
  float v10; // xmm0_4
  const Vector *v11; // eax
  const Vector *v12; // ecx
  double v13; // xmm0_8
  float v14; // xmm1_4
  const Vector *v15; // eax
  const Vector *v16; // ecx
  long double y; // st7
  const Vector *v18; // edi
  float decayTime; // xmm0_4
  long double v20; // st7
  long double tension; // [esp+24h] [ebp-8h] OVERLAPPED BYREF

  v7 = LODWORD(interpolationType);
  v8 = (Vector *)LODWORD(vOut);
  *(_DWORD *)LODWORD(vOut) = 0;
  v8->y = 0.0;
  v8->z = 0.0;
  switch ( v7 )
  {
    case 0:
    case 1:
    case 11:
    case 12:
    case 13:
      goto $LN12_1;
    case 2:
      v9 = f * 3.141592653589793 * 0.5;
      __libm_sse2_sin(x: tension);
      v10 = v9;
      goto LABEL_3;
    case 3:
      v13 = f * 3.141592653589793 * 0.5 + 1.570796326794897;
      __libm_sse2_sin(x: tension);
      v10 = 1.0 - v13;
LABEL_3:
      v11 = vStart;
      v12 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v10) + vStart->x;
      v8->y = (float)((float)(v12->y - v11->y) * v10) + v11->y;
      v8->z = (float)((float)(v12->z - v11->z) * v10) + v11->z;
      return;
    case 4:
      v14 = (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f);
      goto LABEL_6;
    case 5:
      BSpline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      return;
    case 6:
      v14 = f;
LABEL_6:
      v15 = vStart;
      v16 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v14) + vStart->x;
      v8->y = (float)((float)(v16->y - v15->y) * v14) + v15->y;
      v8->z = (float)((float)(v16->z - v15->z) * v14) + v15->z;
      break;
    case 7:
    case 8:
    case 9:
      HIDWORD(tension) = 0;
      interpolationType = 0.0;
      vOut = 0.0;
      Interpolator_GetKochanekBartelsParams(
        interpolationType: v7,
        tension: (float *)&tension + 1,
        bias: &interpolationType,
        continuity: &vOut);
      Kochanek_Bartels_Spline(
        tension: *((float *)&tension + 1),
        bias: interpolationType,
        continuity: vOut,
        p1: vPre,
        p2: vStart,
        p3: vEnd,
        p4: vNext,
        t: f,
        output: v8);
      break;
    case 10:
      Cubic_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 14:
      y = vStart->y;
      v18 = vEnd;
      decayTime = vEnd->x - vStart->x;
      if ( decayTime > 0.0 )
      {
        vOut = vStart->y;
        v20 = ExponentialDecay(decayTo: 0.001, decayTime, dt: decayTime * f);
        y = vOut + (v18->y - vOut) * (1.0 - v20);
      }
      v8->y = y;
      break;
    case 15:
      v8->y = vStart->y;
      break;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", v7);
$LN12_1:
      Catmull_Rom_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004132E0
// Name: void Interpolator_CurveInterpolate_NonNormalized(int,class Quaternion const __near &,class Quaternion const __near &,class Quaternion const __near &,class Quaternion const __near &,float,class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall Interpolator_CurveInterpolate_NonNormalized(
        int a1@<esi>,
        int interpolationType,
        const Quaternion *vPre,
        const Quaternion *vStart,
        const Quaternion *vEnd,
        const Quaternion *vNext,
        float f,
        Quaternion *vOut)
{
  float t; // xmm0_4
  float v9; // xmm0_4
  long double v10; // [esp+4h] [ebp-8h]
  Quaternion *v11; // [esp+4h] [ebp-8h]
  Quaternion *v12; // [esp+4h] [ebp-8h]

  HIDWORD(v10) = a1;
  vOut->x = 0.0;
  vOut->y = 0.0;
  vOut->z = 0.0;
  vOut->w = 0.0;
  switch ( interpolationType )
  {
    case 0:
    case 1:
    case 5:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
      goto $LN7_8;
    case 2:
      LODWORD(v10) = vOut;
      __libm_sse2_sin(x: v10);
      t = f * 3.141592653589793 * 0.5;
      QuaternionSlerp(p: vStart, q: vEnd, t, qt: v11);
      return;
    case 3:
      LODWORD(v10) = vOut;
      __libm_sse2_sin(x: v10);
      v9 = 1.0 - (f * 3.141592653589793 * 0.5 + 1.570796326794897);
      goto LABEL_10;
    case 4:
      QuaternionSlerp(
        p: vStart,
        q: vEnd,
        t: (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f),
        qt: vOut);
      return;
    case 6:
      QuaternionSlerp(p: vStart, q: vEnd, t: f, qt: vOut);
      return;
    case 14:
      vOut->x = 0.0;
      vOut->y = 0.0;
      vOut->z = 0.0;
      vOut->w = 0.0;
      return;
    case 15:
      *vOut = *vStart;
      return;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", interpolationType);
$LN7_8:
      v9 = f;
      v12 = vOut;
LABEL_10:
      QuaternionSlerp(p: vStart, q: vEnd, t: v9, qt: v12);
      return;
  }
}

} // namespace hlmv

// ============================================================
// Overlay from localization_check (Missing functions)
// ============================================================
namespace localization_check {

//------------------------------------------------------------------------------
// Address: 0x00405A20
// Name: int Interpolator_InterpolatorForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Interpolator_InterpolatorForName(const char *name)
{
  InterpolatorNameMap_t *v1; // esi

  v1 = g_InterpolatorNameMap;
  while ( _V_stricmp(s1: name, s2: v1->name) != 0 )
  {
    if ( (int)++v1 >= (int)g_CurveNameMap )
      return 0;
  }
  return v1->type;
}

//------------------------------------------------------------------------------
// Address: 0x00405A60
// Name: int Interpolator_CurveTypeForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Interpolator_CurveTypeForName(const char *name)
{
  unsigned __int8 v1; // bl
  unsigned __int8 v2; // si
  int v3; // edi
  char *v4; // edi
  char *v5; // esi
  char v6; // bl
  int v7; // eax
  unsigned __int8 v8; // al
  char sz[128]; // [esp+Ch] [ebp-84h] BYREF
  int leftcurve; // [esp+8Ch] [ebp-4h]

  V_strncpy(pDest: sz, pSrc: name, maxLen: 128);
  v1 = 0;
  v2 = 0;
  v3 = _V_strlen(str: "curve_");
  if ( V_strnicmp(s1: sz, s2: "curve_", n: v3) == 0 )
  {
    v4 = &sz[v3];
    v5 = V_stristr(pStr: v4, pSearch: "_to_curve_");
    v6 = *v5;
    *v5 = 0;
    leftcurve = Interpolator_InterpolatorForName(name: v4);
    *v5 = v6;
    v7 = _V_strlen(str: "_to_curve_");
    v8 = Interpolator_InterpolatorForName(name: &v5[v7]);
    v1 = leftcurve;
    v2 = v8;
  }
  return v2 | (v1 << 8);
}

} // namespace localization_check

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x0041E630
// Name: int Interpolator_InterpolatorForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Interpolator_InterpolatorForName(const char *name)
{
  InterpolatorNameMap_t *v1; // esi

  v1 = g_InterpolatorNameMap;
  while ( _V_stricmp(s1: name, s2: v1->name) != 0 )
  {
    if ( (int)++v1 >= (int)g_CurveNameMap )
      return 0;
  }
  return v1->type;
}

//------------------------------------------------------------------------------
// Address: 0x0041E670
// Name: int Interpolator_CurveTypeForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Interpolator_CurveTypeForName(const char *name)
{
  unsigned __int8 v1; // bl
  unsigned __int8 v2; // si
  int v3; // edi
  char *v4; // edi
  char *v5; // esi
  char v6; // bl
  int v7; // eax
  unsigned __int8 v8; // al
  char sz[128]; // [esp+Ch] [ebp-84h] BYREF
  int leftcurve; // [esp+8Ch] [ebp-4h]

  V_strncpy(pDest: sz, pSrc: name, maxLen: 128);
  v1 = 0;
  v2 = 0;
  v3 = _V_strlen(str: "curve_");
  if ( V_strnicmp(s1: sz, s2: "curve_", n: v3) == 0 )
  {
    v4 = &sz[v3];
    v5 = V_stristr(pStr: v4, pSearch: "_to_curve_");
    v6 = *v5;
    *v5 = 0;
    leftcurve = Interpolator_InterpolatorForName(name: v4);
    *v5 = v6;
    v7 = _V_strlen(str: "_to_curve_");
    v8 = Interpolator_InterpolatorForName(name: &v5[v7]);
    v1 = leftcurve;
    v2 = v8;
  }
  return v2 | (v1 << 8);
}

} // namespace makegamedata

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x00416440
// Name: float ExponentialDecay(float,float,float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl ExponentialDecay(float decayTo, float decayTime, float dt)
{
  long double v3; // st7
  long double v4; // rt1

  v3 = __FYL2X__(decayTo, 0.6931471805599453094) / decayTime * dt * 1.442695040888963407;
  v4 = rint(v3);
  return __FSCALE__(__F2XM1__(v3 - v4) + 1.0, v4);
}

//------------------------------------------------------------------------------
// Address: 0x00416470
// Name: char const __near * Interpolator_NameForCurveType(int,bool)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Interpolator_NameForCurveType(__int16 type, bool printname)
{
  const char *name; // ecx
  const char *v3; // ecx
  const char *v4; // eax

  if ( printname )
  {
    if ( (unsigned __int8)type >= 0x10u )
      v3 = g_InterpolatorNameMap[0].printname;
    else
      v3 = g_InterpolatorNameMap[(unsigned __int8)type].printname;
    if ( HIBYTE(type) >= 0x10u )
      v4 = g_InterpolatorNameMap[0].printname;
    else
      v4 = g_InterpolatorNameMap[HIBYTE(type)].printname;
    V_snprintf(pDest: outname, maxLen: 256, pFormat: "%s <-> %s", v4, v3);
  }
  else
  {
    if ( (unsigned __int8)type >= 0x10u )
      name = g_InterpolatorNameMap[0].name;
    else
      name = g_InterpolatorNameMap[(unsigned __int8)type].name;
    if ( HIBYTE(type) >= 0x10u )
      V_snprintf(pDest: outname, maxLen: 256, pFormat: "curve_%s_to_curve_%s", g_InterpolatorNameMap[0].name, name);
    else
      V_snprintf(
        pDest: outname,
        maxLen: 256,
        pFormat: "curve_%s_to_curve_%s",
        g_InterpolatorNameMap[HIBYTE(type)].name,
        name);
  }
  return outname;
}

//------------------------------------------------------------------------------
// Address: 0x00416530
// Name: void Interpolator_CurveInterpolatorsForType(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_CurveInterpolatorsForType(__int16 type, int *inbound, int *outbound)
{
  *inbound = HIBYTE(type);
  *outbound = (unsigned __int8)type;
}

//------------------------------------------------------------------------------
// Address: 0x00416560
// Name: void Interpolator_GetKochanekBartelsParams(int,float __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_GetKochanekBartelsParams(
        int interpolationType,
        float *tension,
        float *bias,
        float *continuity)
{
  float *v4; // ecx
  float *v5; // edx
  float *v6; // eax
  int v7; // xmm1_4

  if ( interpolationType == 7 )
  {
    v7 = 0;
    goto LABEL_8;
  }
  if ( interpolationType == 8 )
  {
    v7 = -1082130432;
LABEL_8:
    v5 = continuity;
    v4 = bias;
    v6 = tension;
    goto LABEL_9;
  }
  v4 = bias;
  v5 = continuity;
  v6 = tension;
  if ( interpolationType != 9 )
  {
    *tension = 0.0;
    *bias = 0.0;
    *continuity = 0.0;
    return;
  }
  v7 = 1065353216;
LABEL_9:
  *v6 = 0.76999998;
  *(_DWORD *)v4 = v7;
  *v5 = 0.76999998;
}

//------------------------------------------------------------------------------
// Address: 0x004165D0
// Name: void Interpolator_CurveInterpolate(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl Interpolator_CurveInterpolate(
        float interpolationType,
        const Vector *vPre,
        const Vector *vStart,
        const Vector *vEnd,
        const Vector *vNext,
        float f,
        float vOut)
{
  int v7; // eax
  Vector *v8; // esi
  double v9; // xmm0_8
  float v10; // xmm0_4
  const Vector *v11; // eax
  const Vector *v12; // ecx
  double v13; // xmm0_8
  float v14; // xmm1_4
  const Vector *v15; // eax
  const Vector *v16; // ecx
  long double y; // st7
  const Vector *v18; // edi
  float decayTime; // xmm0_4
  long double v20; // st7
  long double tension; // [esp+24h] [ebp-8h] OVERLAPPED BYREF

  v7 = LODWORD(interpolationType);
  v8 = (Vector *)LODWORD(vOut);
  *(_DWORD *)LODWORD(vOut) = 0;
  v8->y = 0.0;
  v8->z = 0.0;
  switch ( v7 )
  {
    case 0:
    case 1:
      goto $LN15;
    case 2:
      v9 = f * 3.141592653589793 * 0.5;
      __libm_sse2_sin(x: tension);
      v10 = v9;
      goto LABEL_6;
    case 3:
      v13 = f * 3.141592653589793 * 0.5 + 1.570796326794897;
      __libm_sse2_sin(x: tension);
      v10 = 1.0 - v13;
LABEL_6:
      v11 = vStart;
      v12 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v10) + vStart->x;
      v8->y = (float)((float)(v12->y - v11->y) * v10) + v11->y;
      v8->z = (float)((float)(v12->z - v11->z) * v10) + v11->z;
      return;
    case 4:
      v14 = (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f);
      goto LABEL_9;
    case 5:
      BSpline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      return;
    case 6:
      v14 = f;
LABEL_9:
      v15 = vStart;
      v16 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v14) + vStart->x;
      v8->y = (float)((float)(v16->y - v15->y) * v14) + v15->y;
      v8->z = (float)((float)(v16->z - v15->z) * v14) + v15->z;
      break;
    case 7:
    case 8:
    case 9:
      HIDWORD(tension) = 0;
      interpolationType = 0.0;
      vOut = 0.0;
      Interpolator_GetKochanekBartelsParams(
        interpolationType: v7,
        tension: (float *)&tension + 1,
        bias: &interpolationType,
        continuity: &vOut);
      Kochanek_Bartels_Spline_NormalizeX(
        tension: *((float *)&tension + 1),
        bias: interpolationType,
        continuity: vOut,
        p1: vPre,
        p2: vStart,
        p3: vEnd,
        p4: vNext,
        t: f,
        output: v8);
      break;
    case 10:
      Cubic_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 11:
      Catmull_Rom_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 12:
      Catmull_Rom_Spline_Normalize(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 13:
      Catmull_Rom_Spline_Tangent(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 14:
      y = vStart->y;
      v18 = vEnd;
      decayTime = vEnd->x - vStart->x;
      if ( decayTime > 0.0 )
      {
        vOut = vStart->y;
        v20 = ExponentialDecay(decayTo: 0.001, decayTime, dt: decayTime * f);
        y = vOut + (v18->y - vOut) * (1.0 - v20);
      }
      v8->y = y;
      break;
    case 15:
      v8->y = vStart->y;
      break;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", v7);
$LN15:
      Catmull_Rom_Spline_NormalizeX(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416950
// Name: void Interpolator_CurveInterpolate_NonNormalized(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl Interpolator_CurveInterpolate_NonNormalized(
        float interpolationType,
        const Vector *vPre,
        const Vector *vStart,
        const Vector *vEnd,
        const Vector *vNext,
        float f,
        float vOut)
{
  int v7; // eax
  Vector *v8; // esi
  double v9; // xmm0_8
  float v10; // xmm0_4
  const Vector *v11; // eax
  const Vector *v12; // ecx
  double v13; // xmm0_8
  float v14; // xmm1_4
  const Vector *v15; // eax
  const Vector *v16; // ecx
  long double y; // st7
  const Vector *v18; // edi
  float decayTime; // xmm0_4
  long double v20; // st7
  long double tension; // [esp+24h] [ebp-8h] OVERLAPPED BYREF

  v7 = LODWORD(interpolationType);
  v8 = (Vector *)LODWORD(vOut);
  *(_DWORD *)LODWORD(vOut) = 0;
  v8->y = 0.0;
  v8->z = 0.0;
  switch ( v7 )
  {
    case 0:
    case 1:
    case 11:
    case 12:
    case 13:
      goto $LN12_1;
    case 2:
      v9 = f * 3.141592653589793 * 0.5;
      __libm_sse2_sin(x: tension);
      v10 = v9;
      goto LABEL_3;
    case 3:
      v13 = f * 3.141592653589793 * 0.5 + 1.570796326794897;
      __libm_sse2_sin(x: tension);
      v10 = 1.0 - v13;
LABEL_3:
      v11 = vStart;
      v12 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v10) + vStart->x;
      v8->y = (float)((float)(v12->y - v11->y) * v10) + v11->y;
      v8->z = (float)((float)(v12->z - v11->z) * v10) + v11->z;
      return;
    case 4:
      v14 = (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f);
      goto LABEL_6;
    case 5:
      BSpline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      return;
    case 6:
      v14 = f;
LABEL_6:
      v15 = vStart;
      v16 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v14) + vStart->x;
      v8->y = (float)((float)(v16->y - v15->y) * v14) + v15->y;
      v8->z = (float)((float)(v16->z - v15->z) * v14) + v15->z;
      break;
    case 7:
    case 8:
    case 9:
      HIDWORD(tension) = 0;
      interpolationType = 0.0;
      vOut = 0.0;
      Interpolator_GetKochanekBartelsParams(
        interpolationType: v7,
        tension: (float *)&tension + 1,
        bias: &interpolationType,
        continuity: &vOut);
      Kochanek_Bartels_Spline(
        tension: *((float *)&tension + 1),
        bias: interpolationType,
        continuity: vOut,
        p1: vPre,
        p2: vStart,
        p3: vEnd,
        p4: vNext,
        t: f,
        output: v8);
      break;
    case 10:
      Cubic_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 14:
      y = vStart->y;
      v18 = vEnd;
      decayTime = vEnd->x - vStart->x;
      if ( decayTime > 0.0 )
      {
        vOut = vStart->y;
        v20 = ExponentialDecay(decayTo: 0.001, decayTime, dt: decayTime * f);
        y = vOut + (v18->y - vOut) * (1.0 - v20);
      }
      v8->y = y;
      break;
    case 15:
      v8->y = vStart->y;
      break;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", v7);
$LN12_1:
      Catmull_Rom_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416C50
// Name: void Interpolator_CurveInterpolate_NonNormalized(int,class Quaternion const __near &,class Quaternion const __near &,class Quaternion const __near &,class Quaternion const __near &,float,class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall Interpolator_CurveInterpolate_NonNormalized(
        int a1@<esi>,
        int interpolationType,
        const Quaternion *vPre,
        const Quaternion *vStart,
        const Quaternion *vEnd,
        const Quaternion *vNext,
        float f,
        Quaternion *vOut)
{
  float t; // xmm0_4
  float v9; // xmm0_4
  long double v10; // [esp+4h] [ebp-8h]
  Quaternion *v11; // [esp+4h] [ebp-8h]
  Quaternion *v12; // [esp+4h] [ebp-8h]

  HIDWORD(v10) = a1;
  vOut->x = 0.0;
  vOut->y = 0.0;
  vOut->z = 0.0;
  vOut->w = 0.0;
  switch ( interpolationType )
  {
    case 0:
    case 1:
    case 5:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
      goto $LN7_2;
    case 2:
      LODWORD(v10) = vOut;
      __libm_sse2_sin(x: v10);
      t = f * 3.141592653589793 * 0.5;
      QuaternionSlerp(p: vStart, q: vEnd, t, qt: v11);
      return;
    case 3:
      LODWORD(v10) = vOut;
      __libm_sse2_sin(x: v10);
      v9 = 1.0 - (f * 3.141592653589793 * 0.5 + 1.570796326794897);
      goto LABEL_10;
    case 4:
      QuaternionSlerp(
        p: vStart,
        q: vEnd,
        t: (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f),
        qt: vOut);
      return;
    case 6:
      QuaternionSlerp(p: vStart, q: vEnd, t: f, qt: vOut);
      return;
    case 14:
      vOut->x = 0.0;
      vOut->y = 0.0;
      vOut->z = 0.0;
      vOut->w = 0.0;
      return;
    case 15:
      *vOut = *vStart;
      return;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", interpolationType);
$LN7_2:
      v9 = f;
      v12 = vOut;
LABEL_10:
      QuaternionSlerp(p: vStart, q: vEnd, t: v9, qt: v12);
      return;
  }
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: float ExponentialDecay(float,float,float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl ExponentialDecay(float decayTo, float decayTime, float dt)
{
  long double v3; // st7
  long double v4; // rt1

  v3 = __FYL2X__(decayTo, 0.6931471805599453094) / decayTime * dt * 1.442695040888963407;
  v4 = rint(v3);
  return __FSCALE__(__F2XM1__(v3 - v4) + 1.0, v4);
}

//------------------------------------------------------------------------------
// Address: 0x00401030
// Name: char const __near * Interpolator_NameForCurveType(int,bool)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Interpolator_NameForCurveType(__int16 type, bool printname)
{
  const char *name; // ecx
  const char *v3; // ecx
  const char *v4; // eax

  if ( printname )
  {
    if ( (unsigned __int8)type >= 0x10u )
      v3 = g_InterpolatorNameMap[0].printname;
    else
      v3 = g_InterpolatorNameMap[(unsigned __int8)type].printname;
    if ( HIBYTE(type) >= 0x10u )
      v4 = g_InterpolatorNameMap[0].printname;
    else
      v4 = g_InterpolatorNameMap[HIBYTE(type)].printname;
    V_snprintf(pDest: outname, maxLen: 256, pFormat: "%s <-> %s", v4, v3);
  }
  else
  {
    if ( (unsigned __int8)type >= 0x10u )
      name = g_InterpolatorNameMap[0].name;
    else
      name = g_InterpolatorNameMap[(unsigned __int8)type].name;
    if ( HIBYTE(type) >= 0x10u )
      V_snprintf(pDest: outname, maxLen: 256, pFormat: "curve_%s_to_curve_%s", g_InterpolatorNameMap[0].name, name);
    else
      V_snprintf(
        pDest: outname,
        maxLen: 256,
        pFormat: "curve_%s_to_curve_%s",
        g_InterpolatorNameMap[HIBYTE(type)].name,
        name);
  }
  return outname;
}

//------------------------------------------------------------------------------
// Address: 0x004010F0
// Name: void Interpolator_CurveInterpolatorsForType(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_CurveInterpolatorsForType(__int16 type, int *inbound, int *outbound)
{
  *inbound = HIBYTE(type);
  *outbound = (unsigned __int8)type;
}

//------------------------------------------------------------------------------
// Address: 0x00401120
// Name: void Interpolator_GetKochanekBartelsParams(int,float __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_GetKochanekBartelsParams(
        int interpolationType,
        float *tension,
        float *bias,
        float *continuity)
{
  float *v4; // ecx
  float *v5; // edx
  float *v6; // eax
  int v7; // xmm1_4

  if ( interpolationType == 7 )
  {
    v7 = 0;
    goto LABEL_8;
  }
  if ( interpolationType == 8 )
  {
    v7 = -1082130432;
LABEL_8:
    v5 = continuity;
    v4 = bias;
    v6 = tension;
    goto LABEL_9;
  }
  v4 = bias;
  v5 = continuity;
  v6 = tension;
  if ( interpolationType != 9 )
  {
    *tension = 0.0;
    *bias = 0.0;
    *continuity = 0.0;
    return;
  }
  v7 = 1065353216;
LABEL_9:
  *v6 = 0.76999998;
  *(_DWORD *)v4 = v7;
  *v5 = 0.76999998;
}

//------------------------------------------------------------------------------
// Address: 0x00401190
// Name: void Interpolator_CurveInterpolate(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl Interpolator_CurveInterpolate(
        float interpolationType,
        const Vector *vPre,
        const Vector *vStart,
        const Vector *vEnd,
        const Vector *vNext,
        float f,
        float vOut)
{
  int v7; // eax
  Vector *v8; // esi
  double v9; // xmm0_8
  float v10; // xmm0_4
  const Vector *v11; // eax
  const Vector *v12; // ecx
  double v13; // xmm0_8
  float v14; // xmm1_4
  const Vector *v15; // eax
  const Vector *v16; // ecx
  long double y; // st7
  const Vector *v18; // edi
  float decayTime; // xmm0_4
  long double v20; // st7
  long double tension; // [esp+24h] [ebp-8h] OVERLAPPED BYREF

  v7 = LODWORD(interpolationType);
  v8 = (Vector *)LODWORD(vOut);
  *(_DWORD *)LODWORD(vOut) = 0;
  v8->y = 0.0;
  v8->z = 0.0;
  switch ( v7 )
  {
    case 0:
    case 1:
      goto $LN15;
    case 2:
      v9 = f * 3.141592653589793 * 0.5;
      __libm_sse2_sin(x: tension);
      v10 = v9;
      goto LABEL_6;
    case 3:
      v13 = f * 3.141592653589793 * 0.5 + 1.570796326794897;
      __libm_sse2_sin(x: tension);
      v10 = 1.0 - v13;
LABEL_6:
      v11 = vStart;
      v12 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v10) + vStart->x;
      v8->y = (float)((float)(v12->y - v11->y) * v10) + v11->y;
      v8->z = (float)((float)(v12->z - v11->z) * v10) + v11->z;
      return;
    case 4:
      v14 = (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f);
      goto LABEL_9;
    case 5:
      BSpline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      return;
    case 6:
      v14 = f;
LABEL_9:
      v15 = vStart;
      v16 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v14) + vStart->x;
      v8->y = (float)((float)(v16->y - v15->y) * v14) + v15->y;
      v8->z = (float)((float)(v16->z - v15->z) * v14) + v15->z;
      break;
    case 7:
    case 8:
    case 9:
      HIDWORD(tension) = 0;
      interpolationType = 0.0;
      vOut = 0.0;
      Interpolator_GetKochanekBartelsParams(
        interpolationType: v7,
        tension: (float *)&tension + 1,
        bias: &interpolationType,
        continuity: &vOut);
      Kochanek_Bartels_Spline_NormalizeX(
        tension: *((float *)&tension + 1),
        bias: interpolationType,
        continuity: vOut,
        p1: vPre,
        p2: vStart,
        p3: vEnd,
        p4: vNext,
        t: f,
        output: v8);
      break;
    case 10:
      Cubic_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 11:
      Catmull_Rom_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 12:
      Catmull_Rom_Spline_Normalize(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 13:
      Catmull_Rom_Spline_Tangent(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 14:
      y = vStart->y;
      v18 = vEnd;
      decayTime = vEnd->x - vStart->x;
      if ( decayTime > 0.0 )
      {
        vOut = vStart->y;
        v20 = ExponentialDecay(decayTo: 0.001, decayTime, dt: decayTime * f);
        y = vOut + (v18->y - vOut) * (1.0 - v20);
      }
      v8->y = y;
      break;
    case 15:
      v8->y = vStart->y;
      break;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", v7);
$LN15:
      Catmull_Rom_Spline_NormalizeX(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401510
// Name: void Interpolator_CurveInterpolate_NonNormalized(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl Interpolator_CurveInterpolate_NonNormalized(
        float interpolationType,
        const Vector *vPre,
        const Vector *vStart,
        const Vector *vEnd,
        const Vector *vNext,
        float f,
        float vOut)
{
  int v7; // eax
  Vector *v8; // esi
  double v9; // xmm0_8
  float v10; // xmm0_4
  const Vector *v11; // eax
  const Vector *v12; // ecx
  double v13; // xmm0_8
  float v14; // xmm1_4
  const Vector *v15; // eax
  const Vector *v16; // ecx
  long double y; // st7
  const Vector *v18; // edi
  float decayTime; // xmm0_4
  long double v20; // st7
  long double tension; // [esp+24h] [ebp-8h] OVERLAPPED BYREF

  v7 = LODWORD(interpolationType);
  v8 = (Vector *)LODWORD(vOut);
  *(_DWORD *)LODWORD(vOut) = 0;
  v8->y = 0.0;
  v8->z = 0.0;
  switch ( v7 )
  {
    case 0:
    case 1:
    case 11:
    case 12:
    case 13:
      goto $LN12_0;
    case 2:
      v9 = f * 3.141592653589793 * 0.5;
      __libm_sse2_sin(x: tension);
      v10 = v9;
      goto LABEL_3;
    case 3:
      v13 = f * 3.141592653589793 * 0.5 + 1.570796326794897;
      __libm_sse2_sin(x: tension);
      v10 = 1.0 - v13;
LABEL_3:
      v11 = vStart;
      v12 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v10) + vStart->x;
      v8->y = (float)((float)(v12->y - v11->y) * v10) + v11->y;
      v8->z = (float)((float)(v12->z - v11->z) * v10) + v11->z;
      return;
    case 4:
      v14 = (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f);
      goto LABEL_6;
    case 5:
      BSpline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      return;
    case 6:
      v14 = f;
LABEL_6:
      v15 = vStart;
      v16 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v14) + vStart->x;
      v8->y = (float)((float)(v16->y - v15->y) * v14) + v15->y;
      v8->z = (float)((float)(v16->z - v15->z) * v14) + v15->z;
      break;
    case 7:
    case 8:
    case 9:
      HIDWORD(tension) = 0;
      interpolationType = 0.0;
      vOut = 0.0;
      Interpolator_GetKochanekBartelsParams(
        interpolationType: v7,
        tension: (float *)&tension + 1,
        bias: &interpolationType,
        continuity: &vOut);
      Kochanek_Bartels_Spline(
        tension: *((float *)&tension + 1),
        bias: interpolationType,
        continuity: vOut,
        p1: vPre,
        p2: vStart,
        p3: vEnd,
        p4: vNext,
        t: f,
        output: v8);
      break;
    case 10:
      Cubic_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 14:
      y = vStart->y;
      v18 = vEnd;
      decayTime = vEnd->x - vStart->x;
      if ( decayTime > 0.0 )
      {
        vOut = vStart->y;
        v20 = ExponentialDecay(decayTo: 0.001, decayTime, dt: decayTime * f);
        y = vOut + (v18->y - vOut) * (1.0 - v20);
      }
      v8->y = y;
      break;
    case 15:
      v8->y = vStart->y;
      break;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", v7);
$LN12_0:
      Catmull_Rom_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401810
// Name: void Interpolator_CurveInterpolate_NonNormalized(int,class Quaternion const __near &,class Quaternion const __near &,class Quaternion const __near &,class Quaternion const __near &,float,class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall Interpolator_CurveInterpolate_NonNormalized(
        int a1@<esi>,
        int interpolationType,
        const Quaternion *vPre,
        const Quaternion *vStart,
        const Quaternion *vEnd,
        const Quaternion *vNext,
        float f,
        Quaternion *vOut)
{
  float t; // xmm0_4
  float v9; // xmm0_4
  long double v10; // [esp+4h] [ebp-8h]
  Quaternion *v11; // [esp+4h] [ebp-8h]
  Quaternion *v12; // [esp+4h] [ebp-8h]

  HIDWORD(v10) = a1;
  vOut->x = 0.0;
  vOut->y = 0.0;
  vOut->z = 0.0;
  vOut->w = 0.0;
  switch ( interpolationType )
  {
    case 0:
    case 1:
    case 5:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
      goto $LN7_1;
    case 2:
      LODWORD(v10) = vOut;
      __libm_sse2_sin(x: v10);
      t = f * 3.141592653589793 * 0.5;
      QuaternionSlerp(p: vStart, q: vEnd, t, qt: v11);
      return;
    case 3:
      LODWORD(v10) = vOut;
      __libm_sse2_sin(x: v10);
      v9 = 1.0 - (f * 3.141592653589793 * 0.5 + 1.570796326794897);
      goto LABEL_10;
    case 4:
      QuaternionSlerp(
        p: vStart,
        q: vEnd,
        t: (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f),
        qt: vOut);
      return;
    case 6:
      QuaternionSlerp(p: vStart, q: vEnd, t: f, qt: vOut);
      return;
    case 14:
      vOut->x = 0.0;
      vOut->y = 0.0;
      vOut->z = 0.0;
      vOut->w = 0.0;
      return;
    case 15:
      *vOut = *vStart;
      return;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", interpolationType);
$LN7_1:
      v9 = f;
      v12 = vOut;
LABEL_10:
      QuaternionSlerp(p: vStart, q: vEnd, t: v9, qt: v12);
      return;
  }
}

} // namespace particle_import

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x00408340
// Name: int Interpolator_InterpolatorForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Interpolator_InterpolatorForName(const char *name)
{
  InterpolatorNameMap_t *v1; // esi

  v1 = g_InterpolatorNameMap;
  while ( _V_stricmp(s1: name, s2: v1->name) != 0 )
  {
    if ( (int)++v1 >= (int)g_CurveNameMap )
      return 0;
  }
  return v1->type;
}

//------------------------------------------------------------------------------
// Address: 0x00408380
// Name: int Interpolator_CurveTypeForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Interpolator_CurveTypeForName(const char *name)
{
  unsigned __int8 v1; // bl
  unsigned __int8 v2; // si
  int v3; // edi
  char *v4; // edi
  char *v5; // esi
  char v6; // bl
  int v7; // eax
  unsigned __int8 v8; // al
  char sz[128]; // [esp+Ch] [ebp-84h] BYREF
  int leftcurve; // [esp+8Ch] [ebp-4h]

  V_strncpy(pDest: sz, pSrc: name, maxLen: 128);
  v1 = 0;
  v2 = 0;
  v3 = _V_strlen(str: "curve_");
  if ( V_strnicmp(s1: sz, s2: "curve_", n: v3) == 0 )
  {
    v4 = &sz[v3];
    v5 = V_stristr(pStr: v4, pSearch: "_to_curve_");
    v6 = *v5;
    *v5 = 0;
    leftcurve = Interpolator_InterpolatorForName(name: v4);
    *v5 = v6;
    v7 = _V_strlen(str: "_to_curve_");
    v8 = Interpolator_InterpolatorForName(name: &v5[v7]);
    v1 = leftcurve;
    v2 = v8;
  }
  return v2 | (v1 << 8);
}

} // namespace scenemanager

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x00407A40
// Name: float ExponentialDecay(float,float,float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl ExponentialDecay(float decayTo, float decayTime, float dt)
{
  long double v3; // st7
  long double v4; // rt1

  v3 = __FYL2X__(decayTo, 0.6931471805599453094) / decayTime * dt * 1.442695040888963407;
  v4 = rint(v3);
  return __FSCALE__(__F2XM1__(v3 - v4) + 1.0, v4);
}

//------------------------------------------------------------------------------
// Address: 0x00407A70
// Name: char const __near * Interpolator_NameForInterpolator(int,bool)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Interpolator_NameForInterpolator(unsigned int type, bool printname)
{
  const char *result; // eax

  if ( type >= 0x10 )
  {
    result = g_InterpolatorNameMap[0].printname;
    if ( !printname )
      return g_InterpolatorNameMap[0].name;
  }
  else if ( printname )
  {
    return g_InterpolatorNameMap[type].printname;
  }
  else
  {
    return g_InterpolatorNameMap[type].name;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00407AB0
// Name: char const __near * Interpolator_NameForCurveType(int,bool)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Interpolator_NameForCurveType(__int16 type, bool printname)
{
  const char *name; // ecx
  const char *v3; // ecx
  const char *v4; // eax

  if ( printname )
  {
    if ( (unsigned __int8)type >= 0x10u )
      v3 = g_InterpolatorNameMap[0].printname;
    else
      v3 = g_InterpolatorNameMap[(unsigned __int8)type].printname;
    if ( HIBYTE(type) >= 0x10u )
      v4 = g_InterpolatorNameMap[0].printname;
    else
      v4 = g_InterpolatorNameMap[HIBYTE(type)].printname;
    V_snprintf(pDest: outname, maxLen: 256, pFormat: "%s <-> %s", v4, v3);
  }
  else
  {
    if ( (unsigned __int8)type >= 0x10u )
      name = g_InterpolatorNameMap[0].name;
    else
      name = g_InterpolatorNameMap[(unsigned __int8)type].name;
    if ( HIBYTE(type) >= 0x10u )
      V_snprintf(pDest: outname, maxLen: 256, pFormat: "curve_%s_to_curve_%s", g_InterpolatorNameMap[0].name, name);
    else
      V_snprintf(
        pDest: outname,
        maxLen: 256,
        pFormat: "curve_%s_to_curve_%s",
        g_InterpolatorNameMap[HIBYTE(type)].name,
        name);
  }
  return outname;
}

//------------------------------------------------------------------------------
// Address: 0x00407B70
// Name: void Interpolator_CurveInterpolatorsForType(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_CurveInterpolatorsForType(__int16 type, int *inbound, int *outbound)
{
  *inbound = HIBYTE(type);
  *outbound = (unsigned __int8)type;
}

//------------------------------------------------------------------------------
// Address: 0x00407BA0
// Name: void Interpolator_GetKochanekBartelsParams(int,float __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_GetKochanekBartelsParams(
        int interpolationType,
        float *tension,
        float *bias,
        float *continuity)
{
  float *v4; // ecx
  float *v5; // edx
  float *v6; // eax
  int v7; // xmm1_4

  if ( interpolationType == 7 )
  {
    v7 = 0;
    goto LABEL_8;
  }
  if ( interpolationType == 8 )
  {
    v7 = -1082130432;
LABEL_8:
    v5 = continuity;
    v4 = bias;
    v6 = tension;
    goto LABEL_9;
  }
  v4 = bias;
  v5 = continuity;
  v6 = tension;
  if ( interpolationType != 9 )
  {
    *tension = 0.0;
    *bias = 0.0;
    *continuity = 0.0;
    return;
  }
  v7 = 1065353216;
LABEL_9:
  *v6 = 0.76999998;
  *(_DWORD *)v4 = v7;
  *v5 = 0.76999998;
}

//------------------------------------------------------------------------------
// Address: 0x00407C10
// Name: void Interpolator_CurveInterpolate(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl Interpolator_CurveInterpolate(
        float interpolationType,
        const Vector *vPre,
        const Vector *vStart,
        const Vector *vEnd,
        const Vector *vNext,
        float f,
        float vOut)
{
  int v7; // eax
  Vector *v8; // esi
  double v9; // xmm0_8
  float v10; // xmm0_4
  const Vector *v11; // eax
  const Vector *v12; // ecx
  double v13; // xmm0_8
  float v14; // xmm1_4
  const Vector *v15; // eax
  const Vector *v16; // ecx
  long double y; // st7
  const Vector *v18; // edi
  float decayTime; // xmm0_4
  long double v20; // st7
  long double tension; // [esp+24h] [ebp-8h] OVERLAPPED BYREF

  v7 = LODWORD(interpolationType);
  v8 = (Vector *)LODWORD(vOut);
  *(_DWORD *)LODWORD(vOut) = 0;
  v8->y = 0.0;
  v8->z = 0.0;
  switch ( v7 )
  {
    case 0:
    case 1:
      goto $LN15;
    case 2:
      v9 = f * 3.141592653589793 * 0.5;
      __libm_sse2_sin(x: tension);
      v10 = v9;
      goto LABEL_6;
    case 3:
      v13 = f * 3.141592653589793 * 0.5 + 1.570796326794897;
      __libm_sse2_sin(x: tension);
      v10 = 1.0 - v13;
LABEL_6:
      v11 = vStart;
      v12 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v10) + vStart->x;
      v8->y = (float)((float)(v12->y - v11->y) * v10) + v11->y;
      v8->z = (float)((float)(v12->z - v11->z) * v10) + v11->z;
      return;
    case 4:
      v14 = (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f);
      goto LABEL_9;
    case 5:
      BSpline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      return;
    case 6:
      v14 = f;
LABEL_9:
      v15 = vStart;
      v16 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v14) + vStart->x;
      v8->y = (float)((float)(v16->y - v15->y) * v14) + v15->y;
      v8->z = (float)((float)(v16->z - v15->z) * v14) + v15->z;
      break;
    case 7:
    case 8:
    case 9:
      HIDWORD(tension) = 0;
      interpolationType = 0.0;
      vOut = 0.0;
      Interpolator_GetKochanekBartelsParams(
        interpolationType: v7,
        tension: (float *)&tension + 1,
        bias: &interpolationType,
        continuity: &vOut);
      Kochanek_Bartels_Spline_NormalizeX(
        tension: *((float *)&tension + 1),
        bias: interpolationType,
        continuity: vOut,
        p1: vPre,
        p2: vStart,
        p3: vEnd,
        p4: vNext,
        t: f,
        output: v8);
      break;
    case 10:
      Cubic_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 11:
      Catmull_Rom_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 12:
      Catmull_Rom_Spline_Normalize(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 13:
      Catmull_Rom_Spline_Tangent(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 14:
      y = vStart->y;
      v18 = vEnd;
      decayTime = vEnd->x - vStart->x;
      if ( decayTime > 0.0 )
      {
        vOut = vStart->y;
        v20 = ExponentialDecay(decayTo: 0.001, decayTime, dt: decayTime * f);
        y = vOut + (v18->y - vOut) * (1.0 - v20);
      }
      v8->y = y;
      break;
    case 15:
      v8->y = vStart->y;
      break;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", v7);
$LN15:
      Catmull_Rom_Spline_NormalizeX(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407F90
// Name: void Interpolator_CurveInterpolate_NonNormalized(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl Interpolator_CurveInterpolate_NonNormalized(
        float interpolationType,
        const Vector *vPre,
        const Vector *vStart,
        const Vector *vEnd,
        const Vector *vNext,
        float f,
        float vOut)
{
  int v7; // eax
  Vector *v8; // esi
  double v9; // xmm0_8
  float v10; // xmm0_4
  const Vector *v11; // eax
  const Vector *v12; // ecx
  double v13; // xmm0_8
  float v14; // xmm1_4
  const Vector *v15; // eax
  const Vector *v16; // ecx
  long double y; // st7
  const Vector *v18; // edi
  float decayTime; // xmm0_4
  long double v20; // st7
  long double tension; // [esp+24h] [ebp-8h] OVERLAPPED BYREF

  v7 = LODWORD(interpolationType);
  v8 = (Vector *)LODWORD(vOut);
  *(_DWORD *)LODWORD(vOut) = 0;
  v8->y = 0.0;
  v8->z = 0.0;
  switch ( v7 )
  {
    case 0:
    case 1:
    case 11:
    case 12:
    case 13:
      goto $LN12_0;
    case 2:
      v9 = f * 3.141592653589793 * 0.5;
      __libm_sse2_sin(x: tension);
      v10 = v9;
      goto LABEL_3;
    case 3:
      v13 = f * 3.141592653589793 * 0.5 + 1.570796326794897;
      __libm_sse2_sin(x: tension);
      v10 = 1.0 - v13;
LABEL_3:
      v11 = vStart;
      v12 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v10) + vStart->x;
      v8->y = (float)((float)(v12->y - v11->y) * v10) + v11->y;
      v8->z = (float)((float)(v12->z - v11->z) * v10) + v11->z;
      return;
    case 4:
      v14 = (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f);
      goto LABEL_6;
    case 5:
      BSpline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      return;
    case 6:
      v14 = f;
LABEL_6:
      v15 = vStart;
      v16 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v14) + vStart->x;
      v8->y = (float)((float)(v16->y - v15->y) * v14) + v15->y;
      v8->z = (float)((float)(v16->z - v15->z) * v14) + v15->z;
      break;
    case 7:
    case 8:
    case 9:
      HIDWORD(tension) = 0;
      interpolationType = 0.0;
      vOut = 0.0;
      Interpolator_GetKochanekBartelsParams(
        interpolationType: v7,
        tension: (float *)&tension + 1,
        bias: &interpolationType,
        continuity: &vOut);
      Kochanek_Bartels_Spline(
        tension: *((float *)&tension + 1),
        bias: interpolationType,
        continuity: vOut,
        p1: vPre,
        p2: vStart,
        p3: vEnd,
        p4: vNext,
        t: f,
        output: v8);
      break;
    case 10:
      Cubic_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 14:
      y = vStart->y;
      v18 = vEnd;
      decayTime = vEnd->x - vStart->x;
      if ( decayTime > 0.0 )
      {
        vOut = vStart->y;
        v20 = ExponentialDecay(decayTo: 0.001, decayTime, dt: decayTime * f);
        y = vOut + (v18->y - vOut) * (1.0 - v20);
      }
      v8->y = y;
      break;
    case 15:
      v8->y = vStart->y;
      break;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", v7);
$LN12_0:
      Catmull_Rom_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00408290
// Name: void Interpolator_CurveInterpolate_NonNormalized(int,class Quaternion const __near &,class Quaternion const __near &,class Quaternion const __near &,class Quaternion const __near &,float,class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall Interpolator_CurveInterpolate_NonNormalized(
        int a1@<esi>,
        int interpolationType,
        const Quaternion *vPre,
        const Quaternion *vStart,
        const Quaternion *vEnd,
        const Quaternion *vNext,
        float f,
        Quaternion *vOut)
{
  float t; // xmm0_4
  float v9; // xmm0_4
  long double v10; // [esp+4h] [ebp-8h]
  Quaternion *v11; // [esp+4h] [ebp-8h]
  Quaternion *v12; // [esp+4h] [ebp-8h]

  HIDWORD(v10) = a1;
  vOut->x = 0.0;
  vOut->y = 0.0;
  vOut->z = 0.0;
  vOut->w = 0.0;
  switch ( interpolationType )
  {
    case 0:
    case 1:
    case 5:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
      goto $LN7_1;
    case 2:
      LODWORD(v10) = vOut;
      __libm_sse2_sin(x: v10);
      t = f * 3.141592653589793 * 0.5;
      QuaternionSlerp(p: vStart, q: vEnd, t, qt: v11);
      return;
    case 3:
      LODWORD(v10) = vOut;
      __libm_sse2_sin(x: v10);
      v9 = 1.0 - (f * 3.141592653589793 * 0.5 + 1.570796326794897);
      goto LABEL_10;
    case 4:
      QuaternionSlerp(
        p: vStart,
        q: vEnd,
        t: (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f),
        qt: vOut);
      return;
    case 6:
      QuaternionSlerp(p: vStart, q: vEnd, t: f, qt: vOut);
      return;
    case 14:
      vOut->x = 0.0;
      vOut->y = 0.0;
      vOut->z = 0.0;
      vOut->w = 0.0;
      return;
    case 15:
      *vOut = *vStart;
      return;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", interpolationType);
$LN7_1:
      v9 = f;
      v12 = vOut;
LABEL_10:
      QuaternionSlerp(p: vStart, q: vEnd, t: v9, qt: v12);
      return;
  }
}

} // namespace sceneviewer

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x0040F0C0
// Name: float ExponentialDecay(float,float,float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl ExponentialDecay(float decayTo, float decayTime, float dt)
{
  long double v3; // st7
  long double v4; // rt1

  v3 = __FYL2X__(decayTo, 0.6931471805599453094) / decayTime * dt * 1.442695040888963407;
  v4 = rint(v3);
  return __FSCALE__(__F2XM1__(v3 - v4) + 1.0, v4);
}

//------------------------------------------------------------------------------
// Address: 0x0040F0F0
// Name: char const __near * Interpolator_NameForCurveType(int,bool)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Interpolator_NameForCurveType(__int16 type, bool printname)
{
  const char *name; // ecx
  const char *v3; // ecx
  const char *v4; // eax

  if ( printname )
  {
    if ( (unsigned __int8)type >= 0x10u )
      v3 = g_InterpolatorNameMap[0].printname;
    else
      v3 = g_InterpolatorNameMap[(unsigned __int8)type].printname;
    if ( HIBYTE(type) >= 0x10u )
      v4 = g_InterpolatorNameMap[0].printname;
    else
      v4 = g_InterpolatorNameMap[HIBYTE(type)].printname;
    V_snprintf(pDest: outname, maxLen: 256, pFormat: "%s <-> %s", v4, v3);
  }
  else
  {
    if ( (unsigned __int8)type >= 0x10u )
      name = g_InterpolatorNameMap[0].name;
    else
      name = g_InterpolatorNameMap[(unsigned __int8)type].name;
    if ( HIBYTE(type) >= 0x10u )
      V_snprintf(pDest: outname, maxLen: 256, pFormat: "curve_%s_to_curve_%s", g_InterpolatorNameMap[0].name, name);
    else
      V_snprintf(
        pDest: outname,
        maxLen: 256,
        pFormat: "curve_%s_to_curve_%s",
        g_InterpolatorNameMap[HIBYTE(type)].name,
        name);
  }
  return outname;
}

//------------------------------------------------------------------------------
// Address: 0x0040F1B0
// Name: void Interpolator_CurveInterpolatorsForType(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_CurveInterpolatorsForType(__int16 type, int *inbound, int *outbound)
{
  *inbound = HIBYTE(type);
  *outbound = (unsigned __int8)type;
}

//------------------------------------------------------------------------------
// Address: 0x0040F1E0
// Name: void Interpolator_GetKochanekBartelsParams(int,float __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_GetKochanekBartelsParams(
        int interpolationType,
        float *tension,
        float *bias,
        float *continuity)
{
  float *v4; // ecx
  float *v5; // edx
  float *v6; // eax
  int v7; // xmm1_4

  if ( interpolationType == 7 )
  {
    v7 = 0;
    goto LABEL_8;
  }
  if ( interpolationType == 8 )
  {
    v7 = -1082130432;
LABEL_8:
    v5 = continuity;
    v4 = bias;
    v6 = tension;
    goto LABEL_9;
  }
  v4 = bias;
  v5 = continuity;
  v6 = tension;
  if ( interpolationType != 9 )
  {
    *tension = 0.0;
    *bias = 0.0;
    *continuity = 0.0;
    return;
  }
  v7 = 1065353216;
LABEL_9:
  *v6 = 0.76999998;
  *(_DWORD *)v4 = v7;
  *v5 = 0.76999998;
}

//------------------------------------------------------------------------------
// Address: 0x0040F250
// Name: void Interpolator_CurveInterpolate(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl Interpolator_CurveInterpolate(
        float interpolationType,
        const Vector *vPre,
        const Vector *vStart,
        const Vector *vEnd,
        const Vector *vNext,
        float f,
        float vOut)
{
  int v7; // eax
  Vector *v8; // esi
  double v9; // xmm0_8
  float v10; // xmm0_4
  const Vector *v11; // eax
  const Vector *v12; // ecx
  double v13; // xmm0_8
  float v14; // xmm1_4
  const Vector *v15; // eax
  const Vector *v16; // ecx
  long double y; // st7
  const Vector *v18; // edi
  float decayTime; // xmm0_4
  long double v20; // st7
  long double tension; // [esp+24h] [ebp-8h] OVERLAPPED BYREF

  v7 = LODWORD(interpolationType);
  v8 = (Vector *)LODWORD(vOut);
  *(_DWORD *)LODWORD(vOut) = 0;
  v8->y = 0.0;
  v8->z = 0.0;
  switch ( v7 )
  {
    case 0:
    case 1:
      goto $LN15;
    case 2:
      v9 = f * 3.141592653589793 * 0.5;
      __libm_sse2_sin(x: tension);
      v10 = v9;
      goto LABEL_6;
    case 3:
      v13 = f * 3.141592653589793 * 0.5 + 1.570796326794897;
      __libm_sse2_sin(x: tension);
      v10 = 1.0 - v13;
LABEL_6:
      v11 = vStart;
      v12 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v10) + vStart->x;
      v8->y = (float)((float)(v12->y - v11->y) * v10) + v11->y;
      v8->z = (float)((float)(v12->z - v11->z) * v10) + v11->z;
      return;
    case 4:
      v14 = (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f);
      goto LABEL_9;
    case 5:
      BSpline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      return;
    case 6:
      v14 = f;
LABEL_9:
      v15 = vStart;
      v16 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v14) + vStart->x;
      v8->y = (float)((float)(v16->y - v15->y) * v14) + v15->y;
      v8->z = (float)((float)(v16->z - v15->z) * v14) + v15->z;
      break;
    case 7:
    case 8:
    case 9:
      HIDWORD(tension) = 0;
      interpolationType = 0.0;
      vOut = 0.0;
      Interpolator_GetKochanekBartelsParams(
        interpolationType: v7,
        tension: (float *)&tension + 1,
        bias: &interpolationType,
        continuity: &vOut);
      Kochanek_Bartels_Spline_NormalizeX(
        tension: *((float *)&tension + 1),
        bias: interpolationType,
        continuity: vOut,
        p1: vPre,
        p2: vStart,
        p3: vEnd,
        p4: vNext,
        t: f,
        output: v8);
      break;
    case 10:
      Cubic_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 11:
      Catmull_Rom_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 12:
      Catmull_Rom_Spline_Normalize(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 13:
      Catmull_Rom_Spline_Tangent(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 14:
      y = vStart->y;
      v18 = vEnd;
      decayTime = vEnd->x - vStart->x;
      if ( decayTime > 0.0 )
      {
        vOut = vStart->y;
        v20 = ExponentialDecay(decayTo: 0.001, decayTime, dt: decayTime * f);
        y = vOut + (v18->y - vOut) * (1.0 - v20);
      }
      v8->y = y;
      break;
    case 15:
      v8->y = vStart->y;
      break;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", v7);
$LN15:
      Catmull_Rom_Spline_NormalizeX(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F5D0
// Name: void Interpolator_CurveInterpolate_NonNormalized(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl Interpolator_CurveInterpolate_NonNormalized(
        float interpolationType,
        const Vector *vPre,
        const Vector *vStart,
        const Vector *vEnd,
        const Vector *vNext,
        float f,
        float vOut)
{
  int v7; // eax
  Vector *v8; // esi
  double v9; // xmm0_8
  float v10; // xmm0_4
  const Vector *v11; // eax
  const Vector *v12; // ecx
  double v13; // xmm0_8
  float v14; // xmm1_4
  const Vector *v15; // eax
  const Vector *v16; // ecx
  long double y; // st7
  const Vector *v18; // edi
  float decayTime; // xmm0_4
  long double v20; // st7
  long double tension; // [esp+24h] [ebp-8h] OVERLAPPED BYREF

  v7 = LODWORD(interpolationType);
  v8 = (Vector *)LODWORD(vOut);
  *(_DWORD *)LODWORD(vOut) = 0;
  v8->y = 0.0;
  v8->z = 0.0;
  switch ( v7 )
  {
    case 0:
    case 1:
    case 11:
    case 12:
    case 13:
      goto $LN12_1;
    case 2:
      v9 = f * 3.141592653589793 * 0.5;
      __libm_sse2_sin(x: tension);
      v10 = v9;
      goto LABEL_3;
    case 3:
      v13 = f * 3.141592653589793 * 0.5 + 1.570796326794897;
      __libm_sse2_sin(x: tension);
      v10 = 1.0 - v13;
LABEL_3:
      v11 = vStart;
      v12 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v10) + vStart->x;
      v8->y = (float)((float)(v12->y - v11->y) * v10) + v11->y;
      v8->z = (float)((float)(v12->z - v11->z) * v10) + v11->z;
      return;
    case 4:
      v14 = (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f);
      goto LABEL_6;
    case 5:
      BSpline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      return;
    case 6:
      v14 = f;
LABEL_6:
      v15 = vStart;
      v16 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v14) + vStart->x;
      v8->y = (float)((float)(v16->y - v15->y) * v14) + v15->y;
      v8->z = (float)((float)(v16->z - v15->z) * v14) + v15->z;
      break;
    case 7:
    case 8:
    case 9:
      HIDWORD(tension) = 0;
      interpolationType = 0.0;
      vOut = 0.0;
      Interpolator_GetKochanekBartelsParams(
        interpolationType: v7,
        tension: (float *)&tension + 1,
        bias: &interpolationType,
        continuity: &vOut);
      Kochanek_Bartels_Spline(
        tension: *((float *)&tension + 1),
        bias: interpolationType,
        continuity: vOut,
        p1: vPre,
        p2: vStart,
        p3: vEnd,
        p4: vNext,
        t: f,
        output: v8);
      break;
    case 10:
      Cubic_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 14:
      y = vStart->y;
      v18 = vEnd;
      decayTime = vEnd->x - vStart->x;
      if ( decayTime > 0.0 )
      {
        vOut = vStart->y;
        v20 = ExponentialDecay(decayTo: 0.001, decayTime, dt: decayTime * f);
        y = vOut + (v18->y - vOut) * (1.0 - v20);
      }
      v8->y = y;
      break;
    case 15:
      v8->y = vStart->y;
      break;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", v7);
$LN12_1:
      Catmull_Rom_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040F8D0
// Name: void Interpolator_CurveInterpolate_NonNormalized(int,class Quaternion const __near &,class Quaternion const __near &,class Quaternion const __near &,class Quaternion const __near &,float,class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall Interpolator_CurveInterpolate_NonNormalized(
        int a1@<esi>,
        int interpolationType,
        const Quaternion *vPre,
        const Quaternion *vStart,
        const Quaternion *vEnd,
        const Quaternion *vNext,
        float f,
        Quaternion *vOut)
{
  float t; // xmm0_4
  float v9; // xmm0_4
  long double v10; // [esp+4h] [ebp-8h]
  Quaternion *v11; // [esp+4h] [ebp-8h]
  Quaternion *v12; // [esp+4h] [ebp-8h]

  HIDWORD(v10) = a1;
  vOut->x = 0.0;
  vOut->y = 0.0;
  vOut->z = 0.0;
  vOut->w = 0.0;
  switch ( interpolationType )
  {
    case 0:
    case 1:
    case 5:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
      goto $LN7_2;
    case 2:
      LODWORD(v10) = vOut;
      __libm_sse2_sin(x: v10);
      t = f * 3.141592653589793 * 0.5;
      QuaternionSlerp(p: vStart, q: vEnd, t, qt: v11);
      return;
    case 3:
      LODWORD(v10) = vOut;
      __libm_sse2_sin(x: v10);
      v9 = 1.0 - (f * 3.141592653589793 * 0.5 + 1.570796326794897);
      goto LABEL_10;
    case 4:
      QuaternionSlerp(
        p: vStart,
        q: vEnd,
        t: (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f),
        qt: vOut);
      return;
    case 6:
      QuaternionSlerp(p: vStart, q: vEnd, t: f, qt: vOut);
      return;
    case 14:
      vOut->x = 0.0;
      vOut->y = 0.0;
      vOut->z = 0.0;
      vOut->w = 0.0;
      return;
    case 15:
      *vOut = *vStart;
      return;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", interpolationType);
$LN7_2:
      v9 = f;
      v12 = vOut;
LABEL_10:
      QuaternionSlerp(p: vStart, q: vEnd, t: v9, qt: v12);
      return;
  }
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x00411730
// Name: float ExponentialDecay(float,float,float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl ExponentialDecay(float decayTo, float decayTime, float dt)
{
  long double v3; // st7
  long double v4; // rt1

  v3 = __FYL2X__(decayTo, 0.6931471805599453094) / decayTime * dt * 1.442695040888963407;
  v4 = rint(v3);
  return __FSCALE__(__F2XM1__(v3 - v4) + 1.0, v4);
}

//------------------------------------------------------------------------------
// Address: 0x00411760
// Name: char const __near * Interpolator_NameForCurveType(int,bool)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Interpolator_NameForCurveType(__int16 type, bool printname)
{
  const char *name; // ecx
  const char *v3; // ecx
  const char *v4; // eax

  if ( printname )
  {
    if ( (unsigned __int8)type >= 0x10u )
      v3 = g_InterpolatorNameMap[0].printname;
    else
      v3 = g_InterpolatorNameMap[(unsigned __int8)type].printname;
    if ( HIBYTE(type) >= 0x10u )
      v4 = g_InterpolatorNameMap[0].printname;
    else
      v4 = g_InterpolatorNameMap[HIBYTE(type)].printname;
    V_snprintf(pDest: outname, maxLen: 256, pFormat: "%s <-> %s", v4, v3);
  }
  else
  {
    if ( (unsigned __int8)type >= 0x10u )
      name = g_InterpolatorNameMap[0].name;
    else
      name = g_InterpolatorNameMap[(unsigned __int8)type].name;
    if ( HIBYTE(type) >= 0x10u )
      V_snprintf(pDest: outname, maxLen: 256, pFormat: "curve_%s_to_curve_%s", g_InterpolatorNameMap[0].name, name);
    else
      V_snprintf(
        pDest: outname,
        maxLen: 256,
        pFormat: "curve_%s_to_curve_%s",
        g_InterpolatorNameMap[HIBYTE(type)].name,
        name);
  }
  return outname;
}

//------------------------------------------------------------------------------
// Address: 0x00411820
// Name: void Interpolator_CurveInterpolatorsForType(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_CurveInterpolatorsForType(__int16 type, int *inbound, int *outbound)
{
  *inbound = HIBYTE(type);
  *outbound = (unsigned __int8)type;
}

//------------------------------------------------------------------------------
// Address: 0x00411850
// Name: void Interpolator_GetKochanekBartelsParams(int,float __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_GetKochanekBartelsParams(
        int interpolationType,
        float *tension,
        float *bias,
        float *continuity)
{
  float *v4; // ecx
  float *v5; // edx
  float *v6; // eax
  int v7; // xmm1_4

  if ( interpolationType == 7 )
  {
    v7 = 0;
    goto LABEL_8;
  }
  if ( interpolationType == 8 )
  {
    v7 = -1082130432;
LABEL_8:
    v5 = continuity;
    v4 = bias;
    v6 = tension;
    goto LABEL_9;
  }
  v4 = bias;
  v5 = continuity;
  v6 = tension;
  if ( interpolationType != 9 )
  {
    *tension = 0.0;
    *bias = 0.0;
    *continuity = 0.0;
    return;
  }
  v7 = 1065353216;
LABEL_9:
  *v6 = 0.76999998;
  *(_DWORD *)v4 = v7;
  *v5 = 0.76999998;
}

//------------------------------------------------------------------------------
// Address: 0x004118C0
// Name: void Interpolator_CurveInterpolate(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_CurveInterpolate(
        float interpolationType,
        const Vector *vPre,
        const Vector *vStart,
        const Vector *vEnd,
        const Vector *vNext,
        float f,
        float vOut)
{
  int v7; // eax
  Vector *v8; // esi
  __m128i v9; // xmm0
  double v10; // xmm0_8
  float v11; // xmm0_4
  const Vector *v12; // eax
  const Vector *v13; // ecx
  __m128i v14; // xmm0
  double v15; // xmm0_8
  float v16; // xmm1_4
  const Vector *v17; // eax
  const Vector *v18; // ecx
  long double y; // st7
  const Vector *v20; // edi
  float decayTime; // xmm0_4
  long double v22; // st7
  float t; // [esp+28h] [ebp-4h] BYREF

  v7 = LODWORD(interpolationType);
  v8 = (Vector *)LODWORD(vOut);
  *(_DWORD *)LODWORD(vOut) = 0;
  v8->y = 0.0;
  v8->z = 0.0;
  switch ( v7 )
  {
    case 0:
    case 1:
      goto $LN15_1;
    case 2:
      v9 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(f));
      *(double *)v9.m128i_i64 = *(double *)v9.m128i_i64 * 3.141592653589793 * 0.5;
      __libm_sse2_sin(X: v9);
      v11 = v10;
      goto LABEL_6;
    case 3:
      v14 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(f));
      *(double *)v14.m128i_i64 = *(double *)v14.m128i_i64 * 3.141592653589793 * 0.5 + 1.570796326794897;
      __libm_sse2_sin(X: v14);
      v11 = 1.0 - v15;
LABEL_6:
      v12 = vStart;
      v13 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v11) + vStart->x;
      v8->y = (float)((float)(v13->y - v12->y) * v11) + v12->y;
      v8->z = (float)((float)(v13->z - v12->z) * v11) + v12->z;
      return;
    case 4:
      v16 = (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f);
      goto LABEL_9;
    case 5:
      BSpline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      return;
    case 6:
      v16 = f;
LABEL_9:
      v17 = vStart;
      v18 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v16) + vStart->x;
      v8->y = (float)((float)(v18->y - v17->y) * v16) + v17->y;
      v8->z = (float)((float)(v18->z - v17->z) * v16) + v17->z;
      break;
    case 7:
    case 8:
    case 9:
      t = 0.0;
      interpolationType = 0.0;
      vOut = 0.0;
      Interpolator_GetKochanekBartelsParams(
        interpolationType: v7,
        tension: &t,
        bias: &interpolationType,
        continuity: &vOut);
      Kochanek_Bartels_Spline_NormalizeX(
        tension: t,
        bias: interpolationType,
        continuity: vOut,
        p1: vPre,
        p2: vStart,
        p3: vEnd,
        p4: vNext,
        t: f,
        output: v8);
      break;
    case 10:
      Cubic_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 11:
      Catmull_Rom_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 12:
      Catmull_Rom_Spline_Normalize(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 13:
      Catmull_Rom_Spline_Tangent(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 14:
      y = vStart->y;
      v20 = vEnd;
      decayTime = vEnd->x - vStart->x;
      if ( decayTime > 0.0 )
      {
        vOut = vStart->y;
        v22 = ExponentialDecay(decayTo: 0.001, decayTime, dt: decayTime * f);
        y = vOut + (v20->y - vOut) * (1.0 - v22);
      }
      v8->y = y;
      break;
    case 15:
      v8->y = vStart->y;
      break;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", v7);
$LN15_1:
      Catmull_Rom_Spline_NormalizeX(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411C40
// Name: void Interpolator_CurveInterpolate_NonNormalized(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_CurveInterpolate_NonNormalized(
        float interpolationType,
        const Vector *vPre,
        const Vector *vStart,
        const Vector *vEnd,
        const Vector *vNext,
        float f,
        float vOut)
{
  int v7; // eax
  Vector *v8; // esi
  __m128i v9; // xmm0
  double v10; // xmm0_8
  float v11; // xmm0_4
  const Vector *v12; // eax
  const Vector *v13; // ecx
  __m128i v14; // xmm0
  double v15; // xmm0_8
  float v16; // xmm1_4
  const Vector *v17; // eax
  const Vector *v18; // ecx
  long double y; // st7
  const Vector *v20; // edi
  float decayTime; // xmm0_4
  long double v22; // st7
  float t; // [esp+28h] [ebp-4h] BYREF

  v7 = LODWORD(interpolationType);
  v8 = (Vector *)LODWORD(vOut);
  *(_DWORD *)LODWORD(vOut) = 0;
  v8->y = 0.0;
  v8->z = 0.0;
  switch ( v7 )
  {
    case 0:
    case 1:
    case 11:
    case 12:
    case 13:
      goto $LN12_1;
    case 2:
      v9 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(f));
      *(double *)v9.m128i_i64 = *(double *)v9.m128i_i64 * 3.141592653589793 * 0.5;
      __libm_sse2_sin(X: v9);
      v11 = v10;
      goto LABEL_3;
    case 3:
      v14 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(f));
      *(double *)v14.m128i_i64 = *(double *)v14.m128i_i64 * 3.141592653589793 * 0.5 + 1.570796326794897;
      __libm_sse2_sin(X: v14);
      v11 = 1.0 - v15;
LABEL_3:
      v12 = vStart;
      v13 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v11) + vStart->x;
      v8->y = (float)((float)(v13->y - v12->y) * v11) + v12->y;
      v8->z = (float)((float)(v13->z - v12->z) * v11) + v12->z;
      return;
    case 4:
      v16 = (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f);
      goto LABEL_6;
    case 5:
      BSpline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      return;
    case 6:
      v16 = f;
LABEL_6:
      v17 = vStart;
      v18 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v16) + vStart->x;
      v8->y = (float)((float)(v18->y - v17->y) * v16) + v17->y;
      v8->z = (float)((float)(v18->z - v17->z) * v16) + v17->z;
      break;
    case 7:
    case 8:
    case 9:
      t = 0.0;
      interpolationType = 0.0;
      vOut = 0.0;
      Interpolator_GetKochanekBartelsParams(
        interpolationType: v7,
        tension: &t,
        bias: &interpolationType,
        continuity: &vOut);
      Kochanek_Bartels_Spline(
        tension: t,
        bias: interpolationType,
        continuity: vOut,
        p1: vPre,
        p2: vStart,
        p3: vEnd,
        p4: vNext,
        t: f,
        output: v8);
      break;
    case 10:
      Cubic_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 14:
      y = vStart->y;
      v20 = vEnd;
      decayTime = vEnd->x - vStart->x;
      if ( decayTime > 0.0 )
      {
        vOut = vStart->y;
        v22 = ExponentialDecay(decayTo: 0.001, decayTime, dt: decayTime * f);
        y = vOut + (v20->y - vOut) * (1.0 - v22);
      }
      v8->y = y;
      break;
    case 15:
      v8->y = vStart->y;
      break;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", v7);
$LN12_1:
      Catmull_Rom_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00411F40
// Name: void Interpolator_CurveInterpolate_NonNormalized(int,class Quaternion const __near &,class Quaternion const __near &,class Quaternion const __near &,class Quaternion const __near &,float,class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_CurveInterpolate_NonNormalized(
        int interpolationType,
        const Quaternion *vPre,
        const Quaternion *vStart,
        const Quaternion *vEnd,
        const Quaternion *vNext,
        float f,
        Quaternion *vOut)
{
  __m128i v7; // xmm0
  double t; // xmm0_8
  __m128i v9; // xmm0
  double v10; // xmm0_8

  vOut->x = 0.0;
  vOut->y = 0.0;
  vOut->z = 0.0;
  vOut->w = 0.0;
  switch ( interpolationType )
  {
    case 0:
    case 1:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
      goto LABEL_8;
    case 2:
      v7 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(f));
      *(double *)v7.m128i_i64 = *(double *)v7.m128i_i64 * 3.141592653589793 * 0.5;
      __libm_sse2_sin(X: v7);
      *(float *)&t = t;
      QuaternionSlerp(p: vStart, q: vEnd, t: *(float *)&t, qt: vOut);
      break;
    case 3:
      v9 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(f));
      *(double *)v9.m128i_i64 = *(double *)v9.m128i_i64 * 3.141592653589793 * 0.5 + 1.570796326794897;
      __libm_sse2_sin(X: v9);
      QuaternionSlerp(p: vStart, q: vEnd, t: 1.0 - v10, qt: vOut);
      break;
    case 4:
      QuaternionSlerp(
        p: vStart,
        q: vEnd,
        t: (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f),
        qt: vOut);
      break;
    case 14:
      vOut->x = 0.0;
      vOut->y = 0.0;
      vOut->z = 0.0;
      vOut->w = 0.0;
      break;
    case 15:
      *vOut = *vStart;
      break;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", interpolationType);
LABEL_8:
      QuaternionSlerp(p: vStart, q: vEnd, t: f, qt: vOut);
      break;
  }
}

} // namespace uvlightmap

// ============================================================
// Overlay from vcdupdate (Missing functions)
// ============================================================
namespace vcdupdate {

//------------------------------------------------------------------------------
// Address: 0x00401040
// Name: int Interpolator_CurveTypeForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Interpolator_CurveTypeForName(const char *name)
{
  unsigned __int8 v1; // bl
  unsigned __int8 v2; // si
  int v3; // edi
  char *v4; // edi
  char *v5; // esi
  char v6; // bl
  int v7; // eax
  unsigned __int8 v8; // al
  char sz[128]; // [esp+Ch] [ebp-84h] BYREF
  int leftcurve; // [esp+8Ch] [ebp-4h]

  V_strncpy(pDest: sz, pSrc: name, maxLen: 128);
  v1 = 0;
  v2 = 0;
  v3 = _V_strlen(str: "curve_");
  if ( V_strnicmp(s1: sz, s2: "curve_", n: v3) == 0 )
  {
    v4 = &sz[v3];
    v5 = V_stristr(pStr: v4, pSearch: "_to_curve_");
    v6 = *v5;
    *v5 = 0;
    leftcurve = Interpolator_InterpolatorForName(name: v4);
    *v5 = v6;
    v7 = _V_strlen(str: "_to_curve_");
    v8 = Interpolator_InterpolatorForName(name: &v5[v7]);
    v1 = leftcurve;
    v2 = v8;
  }
  return v2 | (v1 << 8);
}

} // namespace vcdupdate

// ============================================================
// Overlay from vcd_sound_check (Missing functions)
// ============================================================
namespace vcd_sound_check {

//------------------------------------------------------------------------------
// Address: 0x004038A0
// Name: int Interpolator_InterpolatorForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Interpolator_InterpolatorForName(const char *name)
{
  InterpolatorNameMap_t *v1; // esi

  v1 = g_InterpolatorNameMap;
  while ( _V_stricmp(s1: name, s2: v1->name) != 0 )
  {
    if ( (int)++v1 >= (int)g_CurveNameMap )
      return 0;
  }
  return v1->type;
}

//------------------------------------------------------------------------------
// Address: 0x004038E0
// Name: int Interpolator_CurveTypeForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Interpolator_CurveTypeForName(const char *name)
{
  unsigned __int8 v1; // bl
  unsigned __int8 v2; // si
  int v3; // edi
  char *v4; // edi
  char *v5; // esi
  char v6; // bl
  int v7; // eax
  unsigned __int8 v8; // al
  char sz[128]; // [esp+Ch] [ebp-84h] BYREF
  int leftcurve; // [esp+8Ch] [ebp-4h]

  V_strncpy(pDest: sz, pSrc: name, maxLen: 128);
  v1 = 0;
  v2 = 0;
  v3 = _V_strlen(str: "curve_");
  if ( V_strnicmp(s1: sz, s2: "curve_", n: v3) == 0 )
  {
    v4 = &sz[v3];
    v5 = V_stristr(pStr: v4, pSearch: "_to_curve_");
    v6 = *v5;
    *v5 = 0;
    leftcurve = Interpolator_InterpolatorForName(name: v4);
    *v5 = v6;
    v7 = _V_strlen(str: "_to_curve_");
    v8 = Interpolator_InterpolatorForName(name: &v5[v7]);
    v1 = leftcurve;
    v2 = v8;
  }
  return v2 | (v1 << 8);
}

} // namespace vcd_sound_check

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x004551A0
// Name: float ExponentialDecay(float,float,float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl ExponentialDecay(float decayTo, float decayTime, float dt)
{
  long double v3; // st7
  long double v4; // rt1

  v3 = __FYL2X__(decayTo, 0.6931471805599453094) / decayTime * dt * 1.442695040888963407;
  v4 = rint(v3);
  return __FSCALE__(__F2XM1__(v3 - v4) + 1.0, v4);
}

//------------------------------------------------------------------------------
// Address: 0x004551D0
// Name: char const __near * Interpolator_NameForCurveType(int,bool)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Interpolator_NameForCurveType(__int16 type, bool printname)
{
  const char *name; // ecx
  const char *v3; // ecx
  const char *v4; // eax

  if ( printname )
  {
    if ( (unsigned __int8)type >= 0x10u )
      v3 = g_InterpolatorNameMap[0].printname;
    else
      v3 = g_InterpolatorNameMap[(unsigned __int8)type].printname;
    if ( HIBYTE(type) >= 0x10u )
      v4 = g_InterpolatorNameMap[0].printname;
    else
      v4 = g_InterpolatorNameMap[HIBYTE(type)].printname;
    V_snprintf(pDest: outname, maxLen: 256, pFormat: "%s <-> %s", v4, v3);
  }
  else
  {
    if ( (unsigned __int8)type >= 0x10u )
      name = g_InterpolatorNameMap[0].name;
    else
      name = g_InterpolatorNameMap[(unsigned __int8)type].name;
    if ( HIBYTE(type) >= 0x10u )
      V_snprintf(pDest: outname, maxLen: 256, pFormat: "curve_%s_to_curve_%s", g_InterpolatorNameMap[0].name, name);
    else
      V_snprintf(
        pDest: outname,
        maxLen: 256,
        pFormat: "curve_%s_to_curve_%s",
        g_InterpolatorNameMap[HIBYTE(type)].name,
        name);
  }
  return outname;
}

//------------------------------------------------------------------------------
// Address: 0x00455290
// Name: void Interpolator_CurveInterpolatorsForType(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_CurveInterpolatorsForType(__int16 type, int *inbound, int *outbound)
{
  *inbound = HIBYTE(type);
  *outbound = (unsigned __int8)type;
}

//------------------------------------------------------------------------------
// Address: 0x004552C0
// Name: void Interpolator_GetKochanekBartelsParams(int,float __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_GetKochanekBartelsParams(
        int interpolationType,
        float *tension,
        float *bias,
        float *continuity)
{
  float *v4; // ecx
  float *v5; // edx
  float *v6; // eax
  int v7; // xmm1_4

  if ( interpolationType == 7 )
  {
    v7 = 0;
    goto LABEL_8;
  }
  if ( interpolationType == 8 )
  {
    v7 = -1082130432;
LABEL_8:
    v5 = continuity;
    v4 = bias;
    v6 = tension;
    goto LABEL_9;
  }
  v4 = bias;
  v5 = continuity;
  v6 = tension;
  if ( interpolationType != 9 )
  {
    *tension = 0.0;
    *bias = 0.0;
    *continuity = 0.0;
    return;
  }
  v7 = 1065353216;
LABEL_9:
  *v6 = 0.76999998;
  *(_DWORD *)v4 = v7;
  *v5 = 0.76999998;
}

//------------------------------------------------------------------------------
// Address: 0x00455330
// Name: void Interpolator_CurveInterpolate(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl Interpolator_CurveInterpolate(
        float interpolationType,
        const Vector *vPre,
        const Vector *vStart,
        const Vector *vEnd,
        const Vector *vNext,
        float f,
        float vOut)
{
  int v7; // eax
  Vector *v8; // esi
  double v9; // xmm0_8
  float v10; // xmm0_4
  const Vector *v11; // eax
  const Vector *v12; // ecx
  double v13; // xmm0_8
  float v14; // xmm1_4
  const Vector *v15; // eax
  const Vector *v16; // ecx
  long double y; // st7
  const Vector *v18; // edi
  float decayTime; // xmm0_4
  long double v20; // st7
  long double tension; // [esp+24h] [ebp-8h] OVERLAPPED BYREF

  v7 = LODWORD(interpolationType);
  v8 = (Vector *)LODWORD(vOut);
  *(_DWORD *)LODWORD(vOut) = 0;
  v8->y = 0.0;
  v8->z = 0.0;
  switch ( v7 )
  {
    case 0:
    case 1:
      goto $LN15;
    case 2:
      v9 = f * 3.141592653589793 * 0.5;
      __libm_sse2_sin(x: tension);
      v10 = v9;
      goto LABEL_6;
    case 3:
      v13 = f * 3.141592653589793 * 0.5 + 1.570796326794897;
      __libm_sse2_sin(x: tension);
      v10 = 1.0 - v13;
LABEL_6:
      v11 = vStart;
      v12 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v10) + vStart->x;
      v8->y = (float)((float)(v12->y - v11->y) * v10) + v11->y;
      v8->z = (float)((float)(v12->z - v11->z) * v10) + v11->z;
      return;
    case 4:
      v14 = (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f);
      goto LABEL_9;
    case 5:
      BSpline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      return;
    case 6:
      v14 = f;
LABEL_9:
      v15 = vStart;
      v16 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v14) + vStart->x;
      v8->y = (float)((float)(v16->y - v15->y) * v14) + v15->y;
      v8->z = (float)((float)(v16->z - v15->z) * v14) + v15->z;
      break;
    case 7:
    case 8:
    case 9:
      HIDWORD(tension) = 0;
      interpolationType = 0.0;
      vOut = 0.0;
      Interpolator_GetKochanekBartelsParams(
        interpolationType: v7,
        tension: (float *)&tension + 1,
        bias: &interpolationType,
        continuity: &vOut);
      Kochanek_Bartels_Spline_NormalizeX(
        tension: *((float *)&tension + 1),
        bias: interpolationType,
        continuity: vOut,
        p1: vPre,
        p2: vStart,
        p3: vEnd,
        p4: vNext,
        t: f,
        output: v8);
      break;
    case 10:
      Cubic_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 11:
      Catmull_Rom_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 12:
      Catmull_Rom_Spline_Normalize(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 13:
      Catmull_Rom_Spline_Tangent(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 14:
      y = vStart->y;
      v18 = vEnd;
      decayTime = vEnd->x - vStart->x;
      if ( decayTime > 0.0 )
      {
        vOut = vStart->y;
        v20 = ExponentialDecay(decayTo: 0.001, decayTime, dt: decayTime * f);
        y = vOut + (v18->y - vOut) * (1.0 - v20);
      }
      v8->y = y;
      break;
    case 15:
      v8->y = vStart->y;
      break;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", v7);
$LN15:
      Catmull_Rom_Spline_NormalizeX(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004556B0
// Name: void Interpolator_CurveInterpolate_NonNormalized(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl Interpolator_CurveInterpolate_NonNormalized(
        float interpolationType,
        const Vector *vPre,
        const Vector *vStart,
        const Vector *vEnd,
        const Vector *vNext,
        float f,
        float vOut)
{
  int v7; // eax
  Vector *v8; // esi
  double v9; // xmm0_8
  float v10; // xmm0_4
  const Vector *v11; // eax
  const Vector *v12; // ecx
  double v13; // xmm0_8
  float v14; // xmm1_4
  const Vector *v15; // eax
  const Vector *v16; // ecx
  long double y; // st7
  const Vector *v18; // edi
  float decayTime; // xmm0_4
  long double v20; // st7
  long double tension; // [esp+24h] [ebp-8h] OVERLAPPED BYREF

  v7 = LODWORD(interpolationType);
  v8 = (Vector *)LODWORD(vOut);
  *(_DWORD *)LODWORD(vOut) = 0;
  v8->y = 0.0;
  v8->z = 0.0;
  switch ( v7 )
  {
    case 0:
    case 1:
    case 11:
    case 12:
    case 13:
      goto $LN12_1;
    case 2:
      v9 = f * 3.141592653589793 * 0.5;
      __libm_sse2_sin(x: tension);
      v10 = v9;
      goto LABEL_3;
    case 3:
      v13 = f * 3.141592653589793 * 0.5 + 1.570796326794897;
      __libm_sse2_sin(x: tension);
      v10 = 1.0 - v13;
LABEL_3:
      v11 = vStart;
      v12 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v10) + vStart->x;
      v8->y = (float)((float)(v12->y - v11->y) * v10) + v11->y;
      v8->z = (float)((float)(v12->z - v11->z) * v10) + v11->z;
      return;
    case 4:
      v14 = (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f);
      goto LABEL_6;
    case 5:
      BSpline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      return;
    case 6:
      v14 = f;
LABEL_6:
      v15 = vStart;
      v16 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v14) + vStart->x;
      v8->y = (float)((float)(v16->y - v15->y) * v14) + v15->y;
      v8->z = (float)((float)(v16->z - v15->z) * v14) + v15->z;
      break;
    case 7:
    case 8:
    case 9:
      HIDWORD(tension) = 0;
      interpolationType = 0.0;
      vOut = 0.0;
      Interpolator_GetKochanekBartelsParams(
        interpolationType: v7,
        tension: (float *)&tension + 1,
        bias: &interpolationType,
        continuity: &vOut);
      Kochanek_Bartels_Spline(
        tension: *((float *)&tension + 1),
        bias: interpolationType,
        continuity: vOut,
        p1: vPre,
        p2: vStart,
        p3: vEnd,
        p4: vNext,
        t: f,
        output: v8);
      break;
    case 10:
      Cubic_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 14:
      y = vStart->y;
      v18 = vEnd;
      decayTime = vEnd->x - vStart->x;
      if ( decayTime > 0.0 )
      {
        vOut = vStart->y;
        v20 = ExponentialDecay(decayTo: 0.001, decayTime, dt: decayTime * f);
        y = vOut + (v18->y - vOut) * (1.0 - v20);
      }
      v8->y = y;
      break;
    case 15:
      v8->y = vStart->y;
      break;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", v7);
$LN12_1:
      Catmull_Rom_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004559B0
// Name: void Interpolator_CurveInterpolate_NonNormalized(int,class Quaternion const __near &,class Quaternion const __near &,class Quaternion const __near &,class Quaternion const __near &,float,class Quaternion __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall Interpolator_CurveInterpolate_NonNormalized(
        int a1@<esi>,
        int interpolationType,
        const Quaternion *vPre,
        const Quaternion *vStart,
        const Quaternion *vEnd,
        const Quaternion *vNext,
        float f,
        Quaternion *vOut)
{
  float t; // xmm0_4
  float v9; // xmm0_4
  long double v10; // [esp+4h] [ebp-8h]
  Quaternion *v11; // [esp+4h] [ebp-8h]
  Quaternion *v12; // [esp+4h] [ebp-8h]

  HIDWORD(v10) = a1;
  vOut->x = 0.0;
  vOut->y = 0.0;
  vOut->z = 0.0;
  vOut->w = 0.0;
  switch ( interpolationType )
  {
    case 0:
    case 1:
    case 5:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
      goto $LN7_4;
    case 2:
      LODWORD(v10) = vOut;
      __libm_sse2_sin(x: v10);
      t = f * 3.141592653589793 * 0.5;
      QuaternionSlerp(p: vStart, q: vEnd, t, qt: v11);
      return;
    case 3:
      LODWORD(v10) = vOut;
      __libm_sse2_sin(x: v10);
      v9 = 1.0 - (f * 3.141592653589793 * 0.5 + 1.570796326794897);
      goto LABEL_10;
    case 4:
      QuaternionSlerp(
        p: vStart,
        q: vEnd,
        t: (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f),
        qt: vOut);
      return;
    case 6:
      QuaternionSlerp(p: vStart, q: vEnd, t: f, qt: vOut);
      return;
    case 14:
      vOut->x = 0.0;
      vOut->y = 0.0;
      vOut->z = 0.0;
      vOut->w = 0.0;
      return;
    case 15:
      *vOut = *vStart;
      return;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", interpolationType);
$LN7_4:
      v9 = f;
      v12 = vOut;
LABEL_10:
      QuaternionSlerp(p: vStart, q: vEnd, t: v9, qt: v12);
      return;
  }
}

} // namespace vmap

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x101190D0
// Name: int Interpolator_InterpolatorForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Interpolator_InterpolatorForName(const char *name)
{
  InterpolatorNameMap_t *v1; // esi

  v1 = g_InterpolatorNameMap;
  while ( _V_stricmp(s1: name, s2: v1->name) != 0 )
  {
    if ( (int)++v1 >= (int)g_CurveNameMap )
      return 0;
  }
  return v1->type;
}

//------------------------------------------------------------------------------
// Address: 0x10119110
// Name: int Interpolator_CurveTypeForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Interpolator_CurveTypeForName(const char *name)
{
  unsigned __int8 v1; // bl
  unsigned __int8 v2; // si
  int v3; // edi
  char *v4; // edi
  char *v5; // esi
  char v6; // bl
  int v7; // eax
  unsigned __int8 v8; // al
  char sz[128]; // [esp+Ch] [ebp-84h] BYREF
  int leftcurve; // [esp+8Ch] [ebp-4h]

  V_strncpy(pDest: sz, pSrc: name, maxLen: 128);
  v1 = 0;
  v2 = 0;
  v3 = _V_strlen(str: "curve_");
  if ( V_strnicmp(s1: sz, s2: "curve_", n: v3) == 0 )
  {
    v4 = &sz[v3];
    v5 = V_stristr(pStr: v4, pSearch: "_to_curve_");
    v6 = *v5;
    *v5 = 0;
    leftcurve = Interpolator_InterpolatorForName(name: v4);
    *v5 = v6;
    v7 = _V_strlen(str: "_to_curve_");
    v8 = Interpolator_InterpolatorForName(name: &v5[v7]);
    v1 = leftcurve;
    v2 = v8;
  }
  return v2 | (v1 << 8);
}

//------------------------------------------------------------------------------
// Address: 0x101191C0
// Name: void Interpolator_CurveInterpolatorsForType(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_CurveInterpolatorsForType(__int16 type, int *inbound, int *outbound)
{
  *inbound = HIBYTE(type);
  *outbound = (unsigned __int8)type;
}

//------------------------------------------------------------------------------
// Address: 0x101191F0
// Name: void Interpolator_GetKochanekBartelsParams(int,float __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_GetKochanekBartelsParams(
        int interpolationType,
        float *tension,
        float *bias,
        float *continuity)
{
  float *v4; // ecx
  float *v5; // edx
  float *v6; // eax
  int v7; // xmm1_4

  if ( interpolationType == 7 )
  {
    v7 = 0;
    goto LABEL_8;
  }
  if ( interpolationType == 8 )
  {
    v7 = -1082130432;
LABEL_8:
    v5 = continuity;
    v4 = bias;
    v6 = tension;
    goto LABEL_9;
  }
  v4 = bias;
  v5 = continuity;
  v6 = tension;
  if ( interpolationType != 9 )
  {
    *tension = 0.0;
    *bias = 0.0;
    *continuity = 0.0;
    return;
  }
  v7 = 1065353216;
LABEL_9:
  *v6 = 0.76999998;
  *(_DWORD *)v4 = v7;
  *v5 = 0.76999998;
}

//------------------------------------------------------------------------------
// Address: 0x10119260
// Name: void Interpolator_CurveInterpolate(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_CurveInterpolate(
        float interpolationType,
        const Vector *vPre,
        const Vector *vStart,
        const Vector *vEnd,
        const Vector *vNext,
        float f,
        float vOut)
{
  int v7; // eax
  Vector *v8; // esi
  __m128i v9; // xmm0
  double v10; // xmm0_8
  float v11; // xmm0_4
  const Vector *v12; // eax
  const Vector *v13; // ecx
  __m128i v14; // xmm0
  double v15; // xmm0_8
  float v16; // xmm1_4
  const Vector *v17; // eax
  const Vector *v18; // ecx
  long double y; // st7
  const Vector *v20; // edi
  float decayTime; // xmm0_4
  long double v22; // st7
  float t; // [esp+28h] [ebp-4h] BYREF
  int savedregs; // [esp+2Ch] [ebp+0h] BYREF

  v7 = LODWORD(interpolationType);
  v8 = (Vector *)LODWORD(vOut);
  *(_DWORD *)LODWORD(vOut) = 0;
  v8->y = 0.0;
  v8->z = 0.0;
  switch ( v7 )
  {
    case 0:
    case 1:
      goto $LN15_5;
    case 2:
      v9 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(f));
      *(double *)v9.m128i_i64 = *(double *)v9.m128i_i64 * 3.141592653589793 * 0.5;
      __libm_sse2_sin(X: v9);
      v11 = v10;
      goto LABEL_6;
    case 3:
      v14 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(f));
      *(double *)v14.m128i_i64 = *(double *)v14.m128i_i64 * 3.141592653589793 * 0.5 + 1.570796326794897;
      __libm_sse2_sin(X: v14);
      v11 = 1.0 - v15;
LABEL_6:
      v12 = vStart;
      v13 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v11) + vStart->x;
      v8->y = (float)((float)(v13->y - v12->y) * v11) + v12->y;
      v8->z = (float)((float)(v13->z - v12->z) * v11) + v12->z;
      return;
    case 4:
      v16 = (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f);
      goto LABEL_9;
    case 5:
      BSpline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      return;
    case 6:
      v16 = f;
LABEL_9:
      v17 = vStart;
      v18 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v16) + vStart->x;
      v8->y = (float)((float)(v18->y - v17->y) * v16) + v17->y;
      v8->z = (float)((float)(v18->z - v17->z) * v16) + v17->z;
      break;
    case 7:
    case 8:
    case 9:
      t = 0.0;
      interpolationType = 0.0;
      vOut = 0.0;
      Interpolator_GetKochanekBartelsParams(
        interpolationType: v7,
        tension: &t,
        bias: &interpolationType,
        continuity: &vOut);
      Kochanek_Bartels_Spline_NormalizeX(
        tension: t,
        bias: interpolationType,
        continuity: vOut,
        p1: vPre,
        p2: vStart,
        p3: vEnd,
        p4: vNext,
        t: f,
        output: v8);
      break;
    case 10:
      Cubic_Spline_NormalizeX(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 11:
      Catmull_Rom_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 12:
      Catmull_Rom_Spline_Normalize(
        a1: COERCE_FLOAT(&savedregs),
        p1: vPre,
        p2: vStart,
        p3: vEnd,
        p4: vNext,
        t: __SPAIR64__((unsigned int)v8, LODWORD(f)));
      break;
    case 13:
      Catmull_Rom_Spline_Tangent(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 14:
      y = vStart->y;
      v20 = vEnd;
      decayTime = vEnd->x - vStart->x;
      if ( decayTime > 0.0 )
      {
        vOut = vStart->y;
        v22 = ExponentialDecay(decayTo: 0.001, decayTime, dt: decayTime * f);
        y = vOut + (v20->y - vOut) * (1.0 - v22);
      }
      v8->y = y;
      break;
    case 15:
      v8->y = vStart->y;
      break;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", v7);
$LN15_5:
      Catmull_Rom_Spline_NormalizeX(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
  }
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10162BC0
// Name: int Interpolator_InterpolatorForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Interpolator_InterpolatorForName(const char *name)
{
  InterpolatorNameMap_t *v1; // esi

  v1 = g_InterpolatorNameMap;
  while ( _V_stricmp(s1: name, s2: v1->name) != 0 )
  {
    if ( (int)++v1 >= (int)g_CurveNameMap )
      return 0;
  }
  return v1->type;
}

//------------------------------------------------------------------------------
// Address: 0x10162C00
// Name: int Interpolator_CurveTypeForName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Interpolator_CurveTypeForName(const char *name)
{
  unsigned __int8 v1; // bl
  unsigned __int8 v2; // si
  int v3; // edi
  char *v4; // edi
  char *v5; // esi
  char v6; // bl
  int v7; // eax
  unsigned __int8 v8; // al
  char sz[128]; // [esp+Ch] [ebp-84h] BYREF
  int leftcurve; // [esp+8Ch] [ebp-4h]

  V_strncpy(pDest: sz, pSrc: name, maxLen: 128);
  v1 = 0;
  v2 = 0;
  v3 = _V_strlen(str: "curve_");
  if ( V_strnicmp(s1: sz, s2: "curve_", n: v3) == 0 )
  {
    v4 = &sz[v3];
    v5 = V_stristr(pStr: v4, pSearch: "_to_curve_");
    v6 = *v5;
    *v5 = 0;
    leftcurve = Interpolator_InterpolatorForName(name: v4);
    *v5 = v6;
    v7 = _V_strlen(str: "_to_curve_");
    v8 = Interpolator_InterpolatorForName(name: &v5[v7]);
    v1 = leftcurve;
    v2 = v8;
  }
  return v2 | (v1 << 8);
}

//------------------------------------------------------------------------------
// Address: 0x10162CB0
// Name: void Interpolator_CurveInterpolatorsForType(int,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_CurveInterpolatorsForType(__int16 type, int *inbound, int *outbound)
{
  *inbound = HIBYTE(type);
  *outbound = (unsigned __int8)type;
}

//------------------------------------------------------------------------------
// Address: 0x10162CE0
// Name: void Interpolator_GetKochanekBartelsParams(int,float __near &,float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_GetKochanekBartelsParams(
        int interpolationType,
        float *tension,
        float *bias,
        float *continuity)
{
  float *v4; // ecx
  float *v5; // edx
  float *v6; // eax
  int v7; // xmm1_4

  if ( interpolationType == 7 )
  {
    v7 = 0;
    goto LABEL_8;
  }
  if ( interpolationType == 8 )
  {
    v7 = -1082130432;
LABEL_8:
    v5 = continuity;
    v4 = bias;
    v6 = tension;
    goto LABEL_9;
  }
  v4 = bias;
  v5 = continuity;
  v6 = tension;
  if ( interpolationType != 9 )
  {
    *tension = 0.0;
    *bias = 0.0;
    *continuity = 0.0;
    return;
  }
  v7 = 1065353216;
LABEL_9:
  *v6 = 0.76999998;
  *(_DWORD *)v4 = v7;
  *v5 = 0.76999998;
}

//------------------------------------------------------------------------------
// Address: 0x10162D50
// Name: void Interpolator_CurveInterpolate(int,class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Interpolator_CurveInterpolate(
        float interpolationType,
        const Vector *vPre,
        const Vector *vStart,
        const Vector *vEnd,
        const Vector *vNext,
        float f,
        float vOut)
{
  int v7; // eax
  Vector *v8; // esi
  __m128i v9; // xmm0
  double v10; // xmm0_8
  float v11; // xmm0_4
  const Vector *v12; // eax
  const Vector *v13; // ecx
  __m128i v14; // xmm0
  double v15; // xmm0_8
  float v16; // xmm1_4
  const Vector *v17; // eax
  const Vector *v18; // ecx
  long double y; // st7
  const Vector *v20; // edi
  float decayTime; // xmm0_4
  long double v22; // st7
  float t; // [esp+28h] [ebp-4h] BYREF

  v7 = LODWORD(interpolationType);
  v8 = (Vector *)LODWORD(vOut);
  *(_DWORD *)LODWORD(vOut) = 0;
  v8->y = 0.0;
  v8->z = 0.0;
  switch ( v7 )
  {
    case 0:
    case 1:
      goto $LN15_7;
    case 2:
      v9 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(f));
      *(double *)v9.m128i_i64 = *(double *)v9.m128i_i64 * 3.141592653589793 * 0.5;
      __libm_sse2_sin(X: v9);
      v11 = v10;
      goto LABEL_6;
    case 3:
      v14 = (__m128i)_mm_cvtps_pd((__m128)LODWORD(f));
      *(double *)v14.m128i_i64 = *(double *)v14.m128i_i64 * 3.141592653589793 * 0.5 + 1.570796326794897;
      __libm_sse2_sin(X: v14);
      v11 = 1.0 - v15;
LABEL_6:
      v12 = vStart;
      v13 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v11) + vStart->x;
      v8->y = (float)((float)(v13->y - v12->y) * v11) + v12->y;
      v8->z = (float)((float)(v13->z - v12->z) * v11) + v12->z;
      return;
    case 4:
      v16 = (float)((float)(f * f) * 3.0) - (float)((float)((float)(f * f) * 2.0) * f);
      goto LABEL_9;
    case 5:
      BSpline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      return;
    case 6:
      v16 = f;
LABEL_9:
      v17 = vStart;
      v18 = vEnd;
      v8->x = (float)((float)(vEnd->x - vStart->x) * v16) + vStart->x;
      v8->y = (float)((float)(v18->y - v17->y) * v16) + v17->y;
      v8->z = (float)((float)(v18->z - v17->z) * v16) + v17->z;
      break;
    case 7:
    case 8:
    case 9:
      t = 0.0;
      interpolationType = 0.0;
      vOut = 0.0;
      Interpolator_GetKochanekBartelsParams(
        interpolationType: v7,
        tension: &t,
        bias: &interpolationType,
        continuity: &vOut);
      Kochanek_Bartels_Spline_NormalizeX(
        tension: t,
        bias: interpolationType,
        continuity: vOut,
        p1: vPre,
        p2: vStart,
        p3: vEnd,
        p4: vNext,
        t: f,
        output: v8);
      break;
    case 10:
      Cubic_Spline_NormalizeX(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 11:
      Catmull_Rom_Spline(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 12:
      Catmull_Rom_Spline_Normalize(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 13:
      Catmull_Rom_Spline_Tangent(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
    case 14:
      y = vStart->y;
      v20 = vEnd;
      decayTime = vEnd->x - vStart->x;
      if ( decayTime > 0.0 )
      {
        vOut = vStart->y;
        v22 = ExponentialDecay(decayTo: 0.001, decayTime, dt: decayTime * f);
        y = vOut + (v20->y - vOut) * (1.0 - v22);
      }
      v8->y = y;
      break;
    case 15:
      v8->y = vStart->y;
      break;
    default:
      _Warning(a1: "Unknown interpolation type %d\n", v7);
$LN15_7:
      Catmull_Rom_Spline_NormalizeX(p1: vPre, p2: vStart, p3: vEnd, p4: vNext, t: f, output: v8);
      break;
  }
}

} // namespace server
