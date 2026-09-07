// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/map_utils.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x102B7C70
// Name: void SetupLightNormalFromProps(class QAngle const __near &,float,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall SetupLightNormalFromProps(
        double a1@<esi:edi>,
        const QAngle *angles,
        float angle,
        float pitch,
        Vector *output)
{
  float y; // xmm0_4
  Vector *v6; // esi
  float v7; // xmm0_4
  float x; // xmm0_4
  float v9; // xmm0_4
  long double v10; // [esp-8h] [ebp-10h]
  long double v11; // [esp-8h] [ebp-10h]
  long double v12; // [esp-8h] [ebp-10h]

  y = angle;
  v10 = a1;
  if ( angle == -1.0 )
  {
    v6 = output;
    output->y = 0.0;
    output->x = 0.0;
    output->z = 1.0;
  }
  else if ( angle == -2.0 )
  {
    v6 = output;
    output->y = 0.0;
    output->x = 0.0;
    output->z = -1.0;
  }
  else
  {
    if ( angle == 0.0 )
      y = angles->y;
    v6 = output;
    output->z = 0.0;
    __libm_sse2_cos(x: v10);
    v7 = (float)(y * 0.0055555557) * 3.141592653589793;
    output->x = v7;
    __libm_sse2_sin(x: v11);
    output->y = v7;
  }
  x = pitch;
  if ( pitch == 0.0 )
    x = angles->x;
  __libm_sse2_sin(x: v10);
  v9 = (float)(x * 0.0055555557) * 3.141592653589793;
  v6->z = v9;
  __libm_sse2_cos(x: v12);
  v6->x = v9 * v6->x;
  v6->y = v6->y * v9;
}

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10082C40
// Name: void SetupLightNormalFromProps(class QAngle const __near &,float,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall SetupLightNormalFromProps(
        double a1@<esi:edi>,
        const QAngle *angles,
        float angle,
        float pitch,
        Vector *output)
{
  float y; // xmm0_4
  Vector *v6; // esi
  float v7; // xmm0_4
  float x; // xmm0_4
  float v9; // xmm0_4
  long double v10; // [esp-8h] [ebp-10h]
  long double v11; // [esp-8h] [ebp-10h]
  long double v12; // [esp-8h] [ebp-10h]

  y = angle;
  v10 = a1;
  if ( angle == -1.0 )
  {
    v6 = output;
    output->y = 0.0;
    output->x = 0.0;
    output->z = 1.0;
  }
  else if ( angle == -2.0 )
  {
    v6 = output;
    output->y = 0.0;
    output->x = 0.0;
    output->z = -1.0;
  }
  else
  {
    if ( angle == 0.0 )
      y = angles->y;
    v6 = output;
    output->z = 0.0;
    __libm_sse2_cos(x: v10);
    v7 = (float)(y * 0.0055555557) * 3.141592653589793;
    output->x = v7;
    __libm_sse2_sin(x: v11);
    output->y = v7;
  }
  x = pitch;
  if ( pitch == 0.0 )
    x = angles->x;
  __libm_sse2_sin(x: v10);
  v9 = (float)(x * 0.0055555557) * 3.141592653589793;
  v6->z = v9;
  __libm_sse2_cos(x: v12);
  v6->x = v9 * v6->x;
  v6->y = v6->y * v9;
}

} // namespace vrad_dll

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1016EDA0
// Name: void SetupLightNormalFromProps(class QAngle const __near &,float,float,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetupLightNormalFromProps(const QAngle *angles, unsigned int angle, unsigned int pitch, Vector *output)
{
  __m128 y_low; // xmm0
  Vector *v5; // esi
  __m128i v6; // xmm0
  double v7; // xmm0_8
  double v8; // xmm0_8
  __m128 x_low; // xmm0
  __m128i v10; // xmm0
  double v11; // xmm0_8
  double v12; // xmm0_8
  unsigned __int64 v13; // [esp+0h] [ebp-8h]
  unsigned __int64 v14; // [esp+0h] [ebp-8h]

  y_low = (__m128)angle;
  if ( *(float *)&angle == -1.0 )
  {
    v5 = output;
    output->y = 0.0;
    output->x = 0.0;
    output->z = 1.0;
  }
  else if ( *(float *)&angle == -2.0 )
  {
    v5 = output;
    output->y = 0.0;
    output->x = 0.0;
    output->z = -1.0;
  }
  else
  {
    if ( *(float *)&angle == 0.0 )
      y_low = (__m128)LODWORD(angles->y);
    y_low.m128_f32[0] = y_low.m128_f32[0] * 0.0055555557;
    v5 = output;
    v6 = (__m128i)_mm_cvtps_pd(y_low);
    *(double *)v6.m128i_i64 = *(double *)v6.m128i_i64 * 3.141592653589793;
    output->z = 0.0;
    v13 = v6.m128i_i64[0];
    __libm_sse2_cos(X: v6);
    *(float *)&v7 = v7;
    output->x = *(float *)&v7;
    __libm_sse2_sin(X: (__m128i)v13);
    *(float *)&v8 = v8;
    output->y = *(float *)&v8;
  }
  x_low = (__m128)pitch;
  if ( *(float *)&pitch == 0.0 )
    x_low = (__m128)LODWORD(angles->x);
  x_low.m128_f32[0] = x_low.m128_f32[0] * 0.0055555557;
  v10 = (__m128i)_mm_cvtps_pd(x_low);
  *(double *)v10.m128i_i64 = *(double *)v10.m128i_i64 * 3.141592653589793;
  v14 = v10.m128i_i64[0];
  __libm_sse2_sin(X: v10);
  *(float *)&v11 = v11;
  v5->z = *(float *)&v11;
  __libm_sse2_cos(X: (__m128i)v14);
  *(float *)&v12 = v12;
  v5->x = *(float *)&v12 * v5->x;
  v5->y = v5->y * *(float *)&v12;
}

} // namespace server
