// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mathlib/color_conversion.cpp
// Functions: 23
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1025EAC0
// Name: float TextureToLinear(int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl TextureToLinear(int c)
{
  if ( c < 0 )
    return 0.0;
  if ( c <= 255 )
    return texturetolinear[c];
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1025EAF0
// Name: int LinearToTexture(float)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LinearToTexture(float f)
{
  int v1; // eax

  v1 = (int)(float)(f * 1023.0);
  if ( v1 < 0 )
    return lineartotexture[0];
  if ( v1 > 1023 )
    v1 = 1023;
  return lineartotexture[v1];
}

//------------------------------------------------------------------------------
// Address: 0x1025EB30
// Name: int LinearToScreenGamma(float)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LinearToScreenGamma(float f)
{
  int v1; // eax

  v1 = (int)(float)(f * 1023.0);
  if ( v1 < 0 )
    return lineartoscreen[0];
  if ( v1 > 1023 )
    v1 = 1023;
  return lineartoscreen[v1];
}

//------------------------------------------------------------------------------
// Address: 0x1025EB70
// Name: void ColorRGBExp32ToVector(struct ColorRGBExp32 const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ColorRGBExp32ToVector(const ColorRGBExp32 *in, Vector *out)
{
  out->x = (float)((float)in->r * dword_10425B80[in->exponent]) * 255.0;
  out->y = (float)((float)in->g * dword_10425B80[in->exponent]) * 255.0;
  out->z = (float)((float)in->b * dword_10425B80[in->exponent]) * 255.0;
}

//------------------------------------------------------------------------------
// Address: 0x1025EBF0
// Name: void VectorToColorRGBExp32(class Vector const __near &,struct ColorRGBExp32 __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VectorToColorRGBExp32(const Vector *vin, ColorRGBExp32 *c)
{
  float x; // xmm1_4
  float y; // xmm2_4
  const Vector *p_y; // ecx
  float z; // xmm0_4
  int v6; // eax
  int blue; // [esp+8h] [ebp+8h]

  x = vin->x;
  y = vin->y;
  p_y = (const Vector *)&vin->y;
  if ( vin->x <= y )
  {
    z = vin->z;
    if ( y <= z )
      p_y = (const Vector *)&vin->z;
  }
  else
  {
    z = vin->z;
    p_y = (const Vector *)&vin->z;
    if ( x > z )
      p_y = vin;
  }
  if ( p_y->x == 0.0 )
    v6 = 0;
  else
    v6 = (unsigned __int8)(LODWORD(p_y->x) >> 23) - 134;
  blue = (127 - v6) << 23;
  c->g = (int)(float)(y * *(float *)&blue);
  c->r = (int)(float)(x * *(float *)&blue);
  c->b = (int)(float)(z * *(float *)&blue);
  c->exponent = v6;
}

//------------------------------------------------------------------------------
// Address: 0x1025EC90
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double v22; // [esp+4h] [ebp-Ch]
  long double v23; // [esp+4h] [ebp-Ch]
  float g1; // [esp+Ch] [ebp-4h]
  float gammaa; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g1 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g1 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g1 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g1 < v9 )
      v10 = (float)((float)(v9 - g1) / (float)(1.0 - g1)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g1) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: v22);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: v23);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  gammaa = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    gammaa = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * gammaa;
    if ( (float)(v17 * gammaa) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * gammaa);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

//------------------------------------------------------------------------------
// Address: 0x1025F000
// Name: float SrgbGammaToLinear(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl SrgbGammaToLinear(float flSrgbGammaValue)
{
  float v1; // xmm0_4

  v1 = 0.0;
  if ( flSrgbGammaValue < 0.0 )
    return (float)(v1 * 0.077399381);
  v1 = 1.0;
  if ( flSrgbGammaValue <= 1.0 )
  {
    v1 = flSrgbGammaValue;
    if ( flSrgbGammaValue <= 0.040449999 )
      return (float)(v1 * 0.077399381);
  }
  __libm_sse2_pow();
  return (float)((float)(v1 + 0.055) * 0.94786733);
}

//------------------------------------------------------------------------------
// Address: 0x1025F070
// Name: float SrgbLinearToGamma(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl SrgbLinearToGamma(float flLinearValue)
{
  float v1; // xmm0_4

  v1 = 0.0;
  if ( flLinearValue < 0.0 )
    return (float)(v1 * 12.92);
  v1 = 1.0;
  if ( flLinearValue <= 1.0 )
  {
    v1 = flLinearValue;
    if ( flLinearValue <= 0.0031308001 )
      return (float)(v1 * 12.92);
  }
  __libm_sse2_pow();
  return (float)((float)(v1 * 1.0549999) - 0.055);
}

//------------------------------------------------------------------------------
// Address: 0x1025F0E0
// Name: float X360GammaToLinear(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl X360GammaToLinear(float fl360GammaValue)
{
  __m128 v1; // xmm0
  float v2; // xmm2_4
  __m128 v3; // xmm2
  float v4; // xmm4_4
  __m128 v5; // xmm3
  __m128 v6; // xmm1
  __m128 v7; // xmm2
  float v8; // xmm2_4
  __m128 v10; // xmm1
  __m128 v11; // xmm3
  __m128 v12; // xmm4
  __m128 v13; // xmm2
  __m128 v14; // xmm3

  v1 = (__m128)LODWORD(fl360GammaValue);
  if ( fl360GammaValue < 0.0 )
  {
    v2 = 0.0 * 255.0;
    goto LABEL_6;
  }
  if ( fl360GammaValue > 1.0 )
  {
    v1 = (__m128)0x3F800000u;
LABEL_5:
    v3.m128_i32[0] = 1258291200;
    v4 = (float)(v1.m128_f32[0] * 2040.0) - 1024.0;
    v1.m128_f32[0] = v4 * 0.0078125;
    v5 = _mm_and_ps((__m128)0x80000000, v1);
    v3.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v1, v5), v3).m128_f32[0]) & 0x4B000000 | v5.m128_i32[0];
    v6 = v1;
    v6.m128_f32[0] = (float)((float)(v4 * 0.0078125) + v3.m128_f32[0]) - v3.m128_f32[0];
    v7 = v6;
    v7.m128_f32[0] = v6.m128_f32[0] - (float)(v4 * 0.0078125);
    v2 = (float)(v6.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v7, v5).m128_f32[0]) & 0x3F800000)) + v4;
    goto LABEL_6;
  }
  if ( fl360GammaValue >= 0.3764706 )
  {
    if ( fl360GammaValue >= 0.75294119 )
      goto LABEL_5;
    v1.m128_f32[0] = (float)(fl360GammaValue * 1020.0) - 256.0;
    v10 = v1;
    v10.m128_f32[0] = v1.m128_f32[0] * 0.00390625;
  }
  else
  {
    if ( fl360GammaValue < 0.25098041 )
    {
      v2 = fl360GammaValue * 255.0;
      goto LABEL_6;
    }
    v1.m128_f32[0] = (float)(fl360GammaValue * 510.0) - 64.0;
    v10 = v1;
    v10.m128_f32[0] = v1.m128_f32[0] * 0.001953125;
  }
  v11.m128_i32[0] = 1258291200;
  v12 = _mm_and_ps((__m128)0x80000000, v10);
  v11.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v10, v12), v11).m128_f32[0]) & 0x4B000000
                  | v12.m128_i32[0];
  v13 = v10;
  v13.m128_f32[0] = (float)(v10.m128_f32[0] + v11.m128_f32[0]) - v11.m128_f32[0];
  v14 = v13;
  v14.m128_f32[0] = v13.m128_f32[0] - v10.m128_f32[0];
  v2 = (float)(v13.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v14, v12).m128_u32[0] & 0x3F800000)) + v1.m128_f32[0];
LABEL_6:
  v8 = v2 * 0.00097751711;
  if ( v8 < 0.0 )
    return 0.0;
  if ( v8 <= 1.0 )
    return v8;
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1025F270
// Name: float X360LinearToGamma(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl X360LinearToGamma(float flLinearValue)
{
  float v1; // xmm0_4
  float v2; // xmm0_4

  v1 = flLinearValue;
  if ( flLinearValue < 0.0 )
  {
    v1 = 0.0;
LABEL_10:
    v2 = v1 * 4.0117645;
    goto LABEL_11;
  }
  if ( flLinearValue > 1.0 )
  {
    v1 = 1.0;
LABEL_5:
    v2 = (float)(v1 * 0.50147057) + 0.50196081;
    if ( v2 > 1.0 )
      return 1.0;
    goto LABEL_11;
  }
  if ( flLinearValue >= 0.12512219 )
  {
    if ( flLinearValue < 0.50048876 )
    {
      v2 = (float)(flLinearValue * 1.0029411) + 0.25098041;
      goto LABEL_11;
    }
    goto LABEL_5;
  }
  if ( flLinearValue < 0.062561095 )
    goto LABEL_10;
  v2 = (float)(flLinearValue * 2.0058823) + 0.1254902;
LABEL_11:
  if ( v2 < 0.0 )
    return 0.0;
  if ( v2 <= 1.0 )
    return v2;
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1025F330
// Name: float SrgbGammaTo360Gamma(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl SrgbGammaTo360Gamma(float flSrgbGammaValue)
{
  float v1; // xmm0_4

  v1 = 0.0;
  if ( flSrgbGammaValue < 0.0 )
    return X360LinearToGamma(flLinearValue: v1 * 0.077399381);
  v1 = 1.0;
  if ( flSrgbGammaValue <= 1.0 )
  {
    v1 = flSrgbGammaValue;
    if ( flSrgbGammaValue <= 0.040449999 )
      return X360LinearToGamma(flLinearValue: v1 * 0.077399381);
  }
  __libm_sse2_pow();
  return X360LinearToGamma(flLinearValue: (float)(v1 + 0.055) * 0.94786733);
}

//------------------------------------------------------------------------------
// Address: 0x1031B0F0
// Name: _dynamic_initializer_for__version_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__version_command__()
{
  ConCommand::ConCommand(
    this: &version_command,
    pName: "version",
    callback: version,
    pHelpString: "Print version info string.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__version_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10325870
// Name: _dynamic_atexit_destructor_for__version_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__version_command__()
{
  ConCommand::~ConCommand(this: &version_command);
}

//------------------------------------------------------------------------------
// Address: 0x1031B120
// Name: _dynamic_initializer_for__pause_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__pause_command__()
{
  ConCommand::ConCommand(
    this: &pause_command,
    pName: "pause",
    callback: (void (__cdecl *)())pause,
    pHelpString: "Toggle the server pause state.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__pause_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B150
// Name: _dynamic_initializer_for__setpause_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__setpause_command__()
{
  ConCommand::ConCommand(
    this: &setpause_command,
    pName: "setpause",
    callback: (void (__cdecl *)())setpause,
    pHelpString: "Set the pause state of the server.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__setpause_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B180
// Name: _dynamic_initializer_for__unpause_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__unpause_command__()
{
  ConCommand::ConCommand(
    this: &unpause_command,
    pName: "unpause",
    callback: (void (__cdecl *)())unpause,
    pHelpString: "Unpause the game.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__unpause_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B1B0
// Name: _dynamic_initializer_for__kickid_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__kickid_command__()
{
  ConCommand::ConCommand(
    this: &kickid_command,
    pName: "kickid",
    callback: (void (__cdecl *)())kickid,
    pHelpString: "Kick a player by userid or uniqueid, with a message.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__kickid_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B1E0
// Name: _dynamic_initializer_for__kick_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__kick_command__()
{
  ConCommand::ConCommand(
    this: &kick_command,
    pName: "kick",
    callback: (void (__cdecl *)())kick,
    pHelpString: "Kick a player by name.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__kick_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10325880
// Name: _dynamic_atexit_destructor_for__pause_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__pause_command__()
{
  ConCommand::~ConCommand(this: &pause_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325890
// Name: _dynamic_atexit_destructor_for__setpause_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__setpause_command__()
{
  ConCommand::~ConCommand(this: &setpause_command);
}

//------------------------------------------------------------------------------
// Address: 0x103258A0
// Name: _dynamic_atexit_destructor_for__unpause_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__unpause_command__()
{
  ConCommand::~ConCommand(this: &unpause_command);
}

//------------------------------------------------------------------------------
// Address: 0x103258B0
// Name: _dynamic_atexit_destructor_for__kickid_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__kickid_command__()
{
  ConCommand::~ConCommand(this: &kickid_command);
}

//------------------------------------------------------------------------------
// Address: 0x103258C0
// Name: _dynamic_atexit_destructor_for__kick_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__kick_command__()
{
  ConCommand::~ConCommand(this: &kick_command);
}

// ============================================================
// Overlay from MaterialSystem (Missing functions)
// ============================================================
namespace MaterialSystem {

//------------------------------------------------------------------------------
// Address: 0x10251980
// Name: float GammaToLinear(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl GammaToLinear(float gamma)
{
  if ( gamma < 0.0 )
    return 0.0;
  if ( gamma < 0.94999999 )
    return g_Mathlib_GammaToLinear[(float)(gamma * 255.0)];
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x102519D0
// Name: float TextureToLinear(int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl TextureToLinear(int c)
{
  if ( c < 0 )
    return 0.0;
  if ( c <= 255 )
    return texturetolinear[c];
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10251A00
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

//------------------------------------------------------------------------------
// Address: 0x10251D70
// Name: float X360LinearToGamma(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl X360LinearToGamma(float flLinearValue)
{
  float v1; // xmm0_4
  float v2; // xmm0_4

  v1 = flLinearValue;
  if ( flLinearValue < 0.0 )
  {
    v1 = 0.0;
LABEL_10:
    v2 = v1 * 4.0117645;
    goto LABEL_11;
  }
  if ( flLinearValue > 1.0 )
  {
    v1 = 1.0;
LABEL_5:
    v2 = (float)(v1 * 0.50147057) + 0.50196081;
    if ( v2 > 1.0 )
      return 1.0;
    goto LABEL_11;
  }
  if ( flLinearValue >= 0.12512219 )
  {
    if ( flLinearValue < 0.50048876 )
    {
      v2 = (float)(flLinearValue * 1.0029411) + 0.25098041;
      goto LABEL_11;
    }
    goto LABEL_5;
  }
  if ( flLinearValue < 0.062561095 )
    goto LABEL_10;
  v2 = (float)(flLinearValue * 2.0058823) + 0.1254902;
LABEL_11:
  if ( v2 < 0.0 )
    return 0.0;
  if ( v2 <= 1.0 )
    return v2;
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10251E30
// Name: float SrgbGammaTo360Gamma(float)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

} // namespace MaterialSystem

// ============================================================
// Overlay from StudioRender (Missing functions)
// ============================================================
namespace StudioRender {

//------------------------------------------------------------------------------
// Address: 0x10057140
// Name: float TextureToLinear(int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl TextureToLinear(int c)
{
  if ( c < 0 )
    return 0.0;
  if ( c <= 255 )
    return texturetolinear[c];
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10057170
// Name: int LinearToTexture(float)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LinearToTexture(float f)
{
  int v1; // eax

  v1 = (int)(float)(f * 1023.0);
  if ( v1 < 0 )
    return lineartotexture[0];
  if ( v1 > 1023 )
    v1 = 1023;
  return lineartotexture[v1];
}

//------------------------------------------------------------------------------
// Address: 0x100571B0
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace StudioRender

// ============================================================
// Overlay from shaderapidx9 (Missing functions)
// ============================================================
namespace shaderapidx9 {

//------------------------------------------------------------------------------
// Address: 0x100D0EB0
// Name: float GammaToLinearFullRange(float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl GammaToLinearFullRange(float gamma)
{
  return pow(gamma, 2.200000047683716);
}

//------------------------------------------------------------------------------
// Address: 0x100D0ED0
// Name: float LinearToGammaFullRange(float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl LinearToGammaFullRange(float linear)
{
  return pow(linear, 0.4545454382896423);
}

//------------------------------------------------------------------------------
// Address: 0x100D0EF0
// Name: float GammaToLinear(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl GammaToLinear(float gamma)
{
  if ( gamma < 0.0 )
    return 0.0;
  if ( gamma < 0.94999999 )
    return g_Mathlib_GammaToLinear[(float)(gamma * 255.0)];
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x100D0F40
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

//------------------------------------------------------------------------------
// Address: 0x100D12B0
// Name: float SrgbGammaToLinear(float)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100D1320
// Name: float SrgbLinearToGamma(float)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

} // namespace shaderapidx9

// ============================================================
// Overlay from bsppack (Missing functions)
// ============================================================
namespace bsppack {

//------------------------------------------------------------------------------
// Address: 0x1001E4B0
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace bsppack

// ============================================================
// Overlay from bspzip (Missing functions)
// ============================================================
namespace bspzip {

//------------------------------------------------------------------------------
// Address: 0x00413480
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildGammaTable(float gamma, float texGamma, float brightness, int overbright)
{
  int v4; // esi
  int v5; // eax
  int i; // esi
  float v7; // xmm0_4
  float v8; // xmm0_4
  int v9; // eax
  int j; // esi
  float v11; // xmm0_4
  int k; // esi
  int v13; // xmm0_4
  int m; // esi
  float v15; // xmm1_4
  int v16; // eax
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  if ( brightness > 0.0 )
  {
    if ( brightness <= 1.0 )
    {
      v4 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v4 = 0;
    }
  }
  else
  {
    g3 = 0.125;
    v4 = 0;
  }
  do
  {
    __libm_sse2_pow();
    v5 = (int)(float)((float)((float)v4 * 0.0039215689) * 255.0);
    if ( v5 >= 0 )
    {
      if ( v5 > 255 )
        LOBYTE(v5) = -1;
    }
    else
    {
      LOBYTE(v5) = 0;
    }
    texgammatable[v4++] = v5;
  }
  while ( v4 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v7 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v7 = v7 * brightness;
    if ( g3 < v7 )
      v8 = (float)((float)(v7 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v8 = (float)(v7 / g3) * 0.125;
    __libm_sse2_pow();
    v9 = (int)(float)(v8 * 255.0);
    if ( v9 >= 0 )
    {
      if ( v9 > 255 )
        v9 = 255;
    }
    else
    {
      v9 = 0;
    }
    lineartoscreen[i] = v9;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow();
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow();
    v11 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v11;
    __libm_sse2_pow();
    g_Mathlib_GammaToLinear[j] = v11;
  }
  for ( k = 0; k < 1024; ++k )
  {
    __libm_sse2_pow();
    lineartotexture[k] = 255 * (int)((double)k * 0.0009775171065493646);
  }
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v13 = 1056964608;
LABEL_30:
    overbrightFactor = *(float *)&v13;
    goto LABEL_31;
  }
  if ( overbright == 4 )
  {
    v13 = 1048576000;
    goto LABEL_30;
  }
LABEL_31:
  for ( m = 0; m < 4096; ++m )
  {
    __libm_sse2_pow();
    v15 = (double)m * 0.0009765625;
    lineartovertex[m] = v15 * overbrightFactor;
    if ( (float)(v15 * overbrightFactor) > 1.0 )
      lineartovertex[m] = 1.0;
    v16 = (int)(float)((float)(v15 * 255.0) * overbrightFactor);
    if ( v16 >= 0 )
    {
      if ( v16 > 255 )
        LOBYTE(v16) = -1;
    }
    else
    {
      LOBYTE(v16) = 0;
    }
    lineartolightmap[m] = v16;
  }
}

} // namespace bspzip

// ============================================================
// Overlay from choreogen (Missing functions)
// ============================================================
namespace choreogen {

//------------------------------------------------------------------------------
// Address: 0x00412120
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildGammaTable(float gamma, float texGamma, float brightness, int overbright)
{
  double v4; // st7
  double v5; // st6
  double v6; // st6
  double v7; // st7
  int v8; // esi
  int v9; // eax
  int v10; // esi
  double v11; // st7
  double v12; // st5
  long double v13; // st7
  int v14; // eax
  int v15; // esi
  long double v16; // st7
  int v17; // esi
  double v18; // st6
  int v19; // esi
  long double v20; // st7
  int v21; // ecx
  unsigned __int8 v22; // al
  int g3; // [esp+4h] [ebp-10h]
  int g3a; // [esp+4h] [ebp-10h]
  int g3b; // [esp+4h] [ebp-10h]
  int g3c; // [esp+4h] [ebp-10h]
  int g3d; // [esp+4h] [ebp-10h]
  float g1; // [esp+8h] [ebp-Ch]
  float g; // [esp+Ch] [ebp-8h]
  float v30; // [esp+10h] [ebp-4h]
  float gammaa; // [esp+18h] [ebp+4h]
  float overbrightFactor; // [esp+1Ch] [ebp+8h]
  float overbrightFactora; // [esp+1Ch] [ebp+8h]
  float brightnessa; // [esp+20h] [ebp+Ch]
  float overbrighta; // [esp+24h] [ebp+10h]

  v4 = 3.0;
  if ( gamma <= 3.0 )
    v4 = gamma;
  v5 = 1.0 / v4;
  v30 = v5;
  g = v5 * texGamma;
  v6 = brightness;
  if ( brightness > 0.0 )
  {
    if ( v6 <= 1.0 )
      v7 = 0.125 - v6 * v6 * 0.075;
    else
      v7 = 0.050000001;
  }
  else
  {
    v7 = 0.125;
  }
  g1 = v7;
  v8 = 0;
  g3 = 0;
  do
  {
    v9 = (int)(pow((double)g3 * 0.0039215689, g) * 255.0);
    if ( v9 >= 0 )
    {
      if ( v9 > 255 )
        LOBYTE(v9) = -1;
    }
    else
    {
      LOBYTE(v9) = 0;
    }
    texgammatable[v8++] = v9;
    g3 = v8;
  }
  while ( v8 < 256 );
  v10 = 0;
  g3a = 0;
  do
  {
    v11 = (double)g3a * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v11 = v11 * brightness;
    v12 = g1;
    if ( g1 < v11 )
      v13 = (v11 - v12) / (1.0 - v12) * 0.875 + 0.125;
    else
      v13 = v11 / v12 * 0.125;
    v14 = (int)(pow(v13, v30) * 255.0);
    if ( v14 >= 0 )
    {
      if ( v14 > 255 )
        v14 = 255;
    }
    else
    {
      v14 = 0;
    }
    lineartoscreen[v10++] = v14;
    g3a = v10;
  }
  while ( v10 < 1024 );
  v15 = 0;
  g3b = 0;
  do
  {
    v16 = (double)g3b * 0.0039215689;
    brightnessa = v16;
    texturetolinear[v15] = pow(v16, texGamma);
    g_Mathlib_LinearToGamma[v15] = pow(brightnessa, 0.4545454382896423);
    g_Mathlib_GammaToLinear[v15++] = pow(brightnessa, 2.200000047683716);
    g3b = v15;
  }
  while ( v15 < 256 );
  v17 = 0;
  g3c = 0;
  overbrightFactor = 1.0 / texGamma;
  do
  {
    lineartotexture[v17++] = (int)(pow((double)g3c * 0.0009775171065493646, overbrightFactor) * 255.0);
    g3c = v17;
  }
  while ( v17 < 1024 );
  overbrightFactora = 1.0;
  if ( overbright == 2 )
  {
    v18 = 0.5;
LABEL_33:
    overbrightFactora = v18;
    goto LABEL_34;
  }
  if ( overbright == 4 )
  {
    v18 = 0.25;
    goto LABEL_33;
  }
LABEL_34:
  v19 = 0;
  g3d = 0;
  gammaa = 1.0 / gamma;
  do
  {
    v20 = pow((double)g3d * 0.0009765625, gammaa) * overbrightFactora;
    lineartovertex[v19] = v20;
    if ( v20 > 1.0 )
      lineartovertex[v19] = 1.0;
    overbrighta = v20 * 255.0;
    v21 = (int)overbrighta;
    if ( v21 <= 255 )
      v22 = v21 < 0 ? 0 : v21;
    else
      v22 = -1;
    lineartolightmap[v19++] = v22;
    g3d = v19;
  }
  while ( v19 < 4096 );
}

} // namespace choreogen

// ============================================================
// Overlay from concatworlds (Missing functions)
// ============================================================
namespace concatworlds {

//------------------------------------------------------------------------------
// Address: 0x00406F60
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace concatworlds

// ============================================================
// Overlay from cubelight (Missing functions)
// ============================================================
namespace cubelight {

//------------------------------------------------------------------------------
// Address: 0x0041F0E0
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace cubelight

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x1002C200
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace dedicated

// ============================================================
// Overlay from Dist2alpha (Missing functions)
// ============================================================
namespace Dist2alpha {

//------------------------------------------------------------------------------
// Address: 0x0042C550
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace Dist2alpha

// ============================================================
// Overlay from dumpworld (Missing functions)
// ============================================================
namespace dumpworld {

//------------------------------------------------------------------------------
// Address: 0x00406FF0
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace dumpworld

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x00490B50
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace dmxedit

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1025EB20
// Name: int LinearToTexture(float)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LinearToTexture(float f)
{
  int v1; // eax

  v1 = (int)(float)(f * 1023.0);
  if ( v1 < 0 )
    return lineartotexture[0];
  if ( v1 > 1023 )
    v1 = 1023;
  return lineartotexture[v1];
}

//------------------------------------------------------------------------------
// Address: 0x1025EB60
// Name: int LinearToScreenGamma(float)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LinearToScreenGamma(float f)
{
  int v1; // eax

  v1 = (int)(float)(f * 1023.0);
  if ( v1 < 0 )
    return lineartoscreen[0];
  if ( v1 > 1023 )
    v1 = 1023;
  return lineartoscreen[v1];
}

//------------------------------------------------------------------------------
// Address: 0x1025EBA0
// Name: void ColorRGBExp32ToVector(struct ColorRGBExp32 const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ColorRGBExp32ToVector(const ColorRGBExp32 *in, Vector *out)
{
  out->x = (float)((float)in->r * dword_10425B80[in->exponent]) * 255.0;
  out->y = (float)((float)in->g * dword_10425B80[in->exponent]) * 255.0;
  out->z = (float)((float)in->b * dword_10425B80[in->exponent]) * 255.0;
}

//------------------------------------------------------------------------------
// Address: 0x1025EC20
// Name: void VectorToColorRGBExp32(class Vector const __near &,struct ColorRGBExp32 __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VectorToColorRGBExp32(const Vector *vin, ColorRGBExp32 *c)
{
  float x; // xmm1_4
  float y; // xmm2_4
  const Vector *p_y; // ecx
  float z; // xmm0_4
  int v6; // eax
  int blue; // [esp+8h] [ebp+8h]

  x = vin->x;
  y = vin->y;
  p_y = (const Vector *)&vin->y;
  if ( vin->x <= y )
  {
    z = vin->z;
    if ( y <= z )
      p_y = (const Vector *)&vin->z;
  }
  else
  {
    z = vin->z;
    p_y = (const Vector *)&vin->z;
    if ( x > z )
      p_y = vin;
  }
  if ( p_y->x == 0.0 )
    v6 = 0;
  else
    v6 = (unsigned __int8)(LODWORD(p_y->x) >> 23) - 134;
  blue = (127 - v6) << 23;
  c->g = (int)(float)(y * *(float *)&blue);
  c->r = (int)(float)(x * *(float *)&blue);
  c->b = (int)(float)(z * *(float *)&blue);
  c->exponent = v6;
}

//------------------------------------------------------------------------------
// Address: 0x1025ECC0
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildGammaTable(float gamma, float texGamma, float brightness, int overbright)
{
  int v4; // esi
  int v5; // eax
  int i; // esi
  float v7; // xmm0_4
  float v8; // xmm0_4
  int v9; // eax
  int j; // esi
  float v11; // xmm0_4
  int k; // esi
  int v13; // xmm0_4
  int m; // esi
  float v15; // xmm1_4
  int v16; // eax
  float g1; // [esp+Ch] [ebp-4h]
  float gammaa; // [esp+1Ch] [ebp+Ch]

  if ( brightness > 0.0 )
  {
    if ( brightness <= 1.0 )
    {
      v4 = 0;
      g1 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g1 = 0.050000001;
      v4 = 0;
    }
  }
  else
  {
    g1 = 0.125;
    v4 = 0;
  }
  do
  {
    __libm_sse2_pow();
    v5 = (int)(float)((float)((float)v4 * 0.0039215689) * 255.0);
    if ( v5 >= 0 )
    {
      if ( v5 > 255 )
        LOBYTE(v5) = -1;
    }
    else
    {
      LOBYTE(v5) = 0;
    }
    texgammatable[v4++] = v5;
  }
  while ( v4 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v7 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v7 = v7 * brightness;
    if ( g1 < v7 )
      v8 = (float)((float)(v7 - g1) / (float)(1.0 - g1)) * 0.875 + 0.125;
    else
      v8 = (float)(v7 / g1) * 0.125;
    __libm_sse2_pow();
    v9 = (int)(float)(v8 * 255.0);
    if ( v9 >= 0 )
    {
      if ( v9 > 255 )
        v9 = 255;
    }
    else
    {
      v9 = 0;
    }
    lineartoscreen[i] = v9;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow();
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow();
    v11 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v11;
    __libm_sse2_pow();
    g_Mathlib_GammaToLinear[j] = v11;
  }
  for ( k = 0; k < 1024; ++k )
  {
    __libm_sse2_pow();
    lineartotexture[k] = 255 * (int)((double)k * 0.0009775171065493646);
  }
  gammaa = 1.0;
  if ( overbright == 2 )
  {
    v13 = 1056964608;
LABEL_30:
    gammaa = *(float *)&v13;
    goto LABEL_31;
  }
  if ( overbright == 4 )
  {
    v13 = 1048576000;
    goto LABEL_30;
  }
LABEL_31:
  for ( m = 0; m < 4096; ++m )
  {
    __libm_sse2_pow();
    v15 = (double)m * 0.0009765625;
    lineartovertex[m] = v15 * gammaa;
    if ( (float)(v15 * gammaa) > 1.0 )
      lineartovertex[m] = 1.0;
    v16 = (int)(float)((float)(v15 * 255.0) * gammaa);
    if ( v16 >= 0 )
    {
      if ( v16 > 255 )
        LOBYTE(v16) = -1;
    }
    else
    {
      LOBYTE(v16) = 0;
    }
    lineartolightmap[m] = v16;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1025F030
// Name: float SrgbGammaToLinear(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl SrgbGammaToLinear(float flSrgbGammaValue)
{
  float v1; // xmm0_4

  v1 = 0.0;
  if ( flSrgbGammaValue < 0.0 )
    return (float)(v1 * 0.077399381);
  v1 = 1.0;
  if ( flSrgbGammaValue <= 1.0 )
  {
    v1 = flSrgbGammaValue;
    if ( flSrgbGammaValue <= 0.040449999 )
      return (float)(v1 * 0.077399381);
  }
  __libm_sse2_pow();
  return (float)((float)(v1 + 0.055) * 0.94786733);
}

//------------------------------------------------------------------------------
// Address: 0x1025F0A0
// Name: float SrgbLinearToGamma(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl SrgbLinearToGamma(float flLinearValue)
{
  float v1; // xmm0_4

  v1 = 0.0;
  if ( flLinearValue < 0.0 )
    return (float)(v1 * 12.92);
  v1 = 1.0;
  if ( flLinearValue <= 1.0 )
  {
    v1 = flLinearValue;
    if ( flLinearValue <= 0.0031308001 )
      return (float)(v1 * 12.92);
  }
  __libm_sse2_pow();
  return (float)((float)(v1 * 1.0549999) - 0.055);
}

//------------------------------------------------------------------------------
// Address: 0x1025F110
// Name: float X360GammaToLinear(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl X360GammaToLinear(float fl360GammaValue)
{
  __m128 v1; // xmm0
  float v2; // xmm2_4
  __m128 v3; // xmm2
  float v4; // xmm4_4
  __m128 v5; // xmm3
  __m128 v6; // xmm1
  __m128 v7; // xmm2
  float v8; // xmm2_4
  __m128 v10; // xmm1
  __m128 v11; // xmm3
  __m128 v12; // xmm4
  __m128 v13; // xmm2
  __m128 v14; // xmm3

  v1 = (__m128)LODWORD(fl360GammaValue);
  if ( fl360GammaValue < 0.0 )
  {
    v2 = 0.0 * 255.0;
    goto LABEL_6;
  }
  if ( fl360GammaValue > 1.0 )
  {
    v1 = (__m128)0x3F800000u;
LABEL_5:
    v3.m128_i32[0] = 1258291200;
    v4 = (float)(v1.m128_f32[0] * 2040.0) - 1024.0;
    v1.m128_f32[0] = v4 * 0.0078125;
    v5 = _mm_and_ps((__m128)0x80000000, v1);
    v3.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v1, v5), v3).m128_f32[0]) & 0x4B000000 | v5.m128_i32[0];
    v6 = v1;
    v6.m128_f32[0] = (float)((float)(v4 * 0.0078125) + v3.m128_f32[0]) - v3.m128_f32[0];
    v7 = v6;
    v7.m128_f32[0] = v6.m128_f32[0] - (float)(v4 * 0.0078125);
    v2 = (float)(v6.m128_f32[0] - COERCE_FLOAT(COERCE_UNSIGNED_INT(_mm_cmpgt_ss(v7, v5).m128_f32[0]) & 0x3F800000)) + v4;
    goto LABEL_6;
  }
  if ( fl360GammaValue >= 0.3764706 )
  {
    if ( fl360GammaValue >= 0.75294119 )
      goto LABEL_5;
    v1.m128_f32[0] = (float)(fl360GammaValue * 1020.0) - 256.0;
    v10 = v1;
    v10.m128_f32[0] = v1.m128_f32[0] * 0.00390625;
  }
  else
  {
    if ( fl360GammaValue < 0.25098041 )
    {
      v2 = fl360GammaValue * 255.0;
      goto LABEL_6;
    }
    v1.m128_f32[0] = (float)(fl360GammaValue * 510.0) - 64.0;
    v10 = v1;
    v10.m128_f32[0] = v1.m128_f32[0] * 0.001953125;
  }
  v11.m128_i32[0] = 1258291200;
  v12 = _mm_and_ps((__m128)0x80000000, v10);
  v11.m128_i32[0] = COERCE_UNSIGNED_INT(_mm_cmplt_ss(_mm_xor_ps(v10, v12), v11).m128_f32[0]) & 0x4B000000
                  | v12.m128_i32[0];
  v13 = v10;
  v13.m128_f32[0] = (float)(v10.m128_f32[0] + v11.m128_f32[0]) - v11.m128_f32[0];
  v14 = v13;
  v14.m128_f32[0] = v13.m128_f32[0] - v10.m128_f32[0];
  v2 = (float)(v13.m128_f32[0] - COERCE_FLOAT(_mm_cmpgt_ss(v14, v12).m128_u32[0] & 0x3F800000)) + v1.m128_f32[0];
LABEL_6:
  v8 = v2 * 0.00097751711;
  if ( v8 < 0.0 )
    return 0.0;
  if ( v8 <= 1.0 )
    return v8;
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1025F2A0
// Name: float X360LinearToGamma(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl X360LinearToGamma(float flLinearValue)
{
  float v1; // xmm0_4
  float v2; // xmm0_4

  v1 = flLinearValue;
  if ( flLinearValue < 0.0 )
  {
    v1 = 0.0;
LABEL_10:
    v2 = v1 * 4.0117645;
    goto LABEL_11;
  }
  if ( flLinearValue > 1.0 )
  {
    v1 = 1.0;
LABEL_5:
    v2 = (float)(v1 * 0.50147057) + 0.50196081;
    if ( v2 > 1.0 )
      return 1.0;
    goto LABEL_11;
  }
  if ( flLinearValue >= 0.12512219 )
  {
    if ( flLinearValue < 0.50048876 )
    {
      v2 = (float)(flLinearValue * 1.0029411) + 0.25098041;
      goto LABEL_11;
    }
    goto LABEL_5;
  }
  if ( flLinearValue < 0.062561095 )
    goto LABEL_10;
  v2 = (float)(flLinearValue * 2.0058823) + 0.1254902;
LABEL_11:
  if ( v2 < 0.0 )
    return 0.0;
  if ( v2 <= 1.0 )
    return v2;
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1025F360
// Name: float SrgbGammaTo360Gamma(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl SrgbGammaTo360Gamma(float flSrgbGammaValue)
{
  float v1; // xmm0_4

  v1 = 0.0;
  if ( flSrgbGammaValue < 0.0 )
    return X360LinearToGamma(flLinearValue: v1 * 0.077399381);
  v1 = 1.0;
  if ( flSrgbGammaValue <= 1.0 )
  {
    v1 = flSrgbGammaValue;
    if ( flSrgbGammaValue <= 0.040449999 )
      return X360LinearToGamma(flLinearValue: v1 * 0.077399381);
  }
  __libm_sse2_pow();
  return X360LinearToGamma(flLinearValue: (float)(v1 + 0.055) * 0.94786733);
}

//------------------------------------------------------------------------------
// Address: 0x1031B2E0
// Name: _dynamic_initializer_for__version_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__version_command__()
{
  ConCommand::ConCommand(
    this: &version_command,
    pName: "version",
    callback: (void (__cdecl *)(const CCommand *))version,
    pHelpString: "Print version info string.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__version_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10325A60
// Name: _dynamic_atexit_destructor_for__version_command__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__version_command__()
{
  ConCommand::~ConCommand(this: &version_command);
}

//------------------------------------------------------------------------------
// Address: 0x1031B310
// Name: _dynamic_initializer_for__pause_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__pause_command__()
{
  ConCommand::ConCommand(
    this: &pause_command,
    pName: "pause",
    callback: pause,
    pHelpString: "Toggle the server pause state.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__pause_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B340
// Name: _dynamic_initializer_for__setpause_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__setpause_command__()
{
  ConCommand::ConCommand(
    this: &setpause_command,
    pName: "setpause",
    callback: setpause,
    pHelpString: "Set the pause state of the server.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__setpause_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B370
// Name: _dynamic_initializer_for__unpause_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__unpause_command__()
{
  ConCommand::ConCommand(
    this: &unpause_command,
    pName: "unpause",
    callback: unpause,
    pHelpString: "Unpause the game.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__unpause_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B3A0
// Name: _dynamic_initializer_for__kickid_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__kickid_command__()
{
  ConCommand::ConCommand(
    this: &kickid_command,
    pName: "kickid",
    callback: kickid,
    pHelpString: "Kick a player by userid or uniqueid, with a message.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__kickid_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1031B3D0
// Name: _dynamic_initializer_for__kick_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__kick_command__()
{
  ConCommand::ConCommand(
    this: &kick_command,
    pName: "kick",
    callback: kick,
    pHelpString: "Kick a player by name.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__kick_command__);
}

//------------------------------------------------------------------------------
// Address: 0x10325A70
// Name: _dynamic_atexit_destructor_for__pause_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__pause_command__()
{
  ConCommand::~ConCommand(this: &pause_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325A80
// Name: _dynamic_atexit_destructor_for__setpause_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__setpause_command__()
{
  ConCommand::~ConCommand(this: &setpause_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325A90
// Name: _dynamic_atexit_destructor_for__unpause_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__unpause_command__()
{
  ConCommand::~ConCommand(this: &unpause_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325AA0
// Name: _dynamic_atexit_destructor_for__kickid_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__kickid_command__()
{
  ConCommand::~ConCommand(this: &kickid_command);
}

//------------------------------------------------------------------------------
// Address: 0x10325AB0
// Name: _dynamic_atexit_destructor_for__kick_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__kick_command__()
{
  ConCommand::~ConCommand(this: &kick_command);
}

} // namespace engine_xlsp

// ============================================================
// Overlay from glview (Missing functions)
// ============================================================
namespace glview {

//------------------------------------------------------------------------------
// Address: 0x00406090
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace glview

// ============================================================
// Overlay from height2normal (Missing functions)
// ============================================================
namespace height2normal {

//------------------------------------------------------------------------------
// Address: 0x0042B2B0
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace height2normal

// ============================================================
// Overlay from height2ssbump (Missing functions)
// ============================================================
namespace height2ssbump {

//------------------------------------------------------------------------------
// Address: 0x0042DD70
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace height2ssbump

// ============================================================
// Overlay from hlfaceposer (Missing functions)
// ============================================================
namespace hlfaceposer {

//------------------------------------------------------------------------------
// Address: 0x004C0F60
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace hlfaceposer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10203090
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double v22; // [esp+4h] [ebp-Ch]
  long double v23; // [esp+4h] [ebp-Ch]
  float g1; // [esp+Ch] [ebp-4h]
  float gammaa; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g1 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g1 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g1 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g1 < v9 )
      v10 = (float)((float)(v9 - g1) / (float)(1.0 - g1)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g1) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: v22);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: v23);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  gammaa = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    gammaa = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * gammaa;
    if ( (float)(v17 * gammaa) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * gammaa);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0049B940
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace hlmv

// ============================================================
// Overlay from lightworld (Missing functions)
// ============================================================
namespace lightworld {

//------------------------------------------------------------------------------
// Address: 0x0040B290
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace lightworld

// ============================================================
// Overlay from matchmaking_ds (Missing functions)
// ============================================================
namespace matchmaking_ds {

//------------------------------------------------------------------------------
// Address: 0x10004EE0
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(unsigned int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm1_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  int k; // esi
  int v14; // xmm0_4
  int m; // esi
  float v16; // xmm0_4
  float v17; // xmm0_4
  int v18; // ecx
  unsigned __int8 v19; // al
  __int64 g3; // [esp+0h] [ebp-10h]
  long double g3a; // [esp+0h] [ebp-10h]
  long double g3b; // [esp+0h] [ebp-10h]
  long double g; // [esp+8h] [ebp-8h]
  long double ga; // [esp+8h] [ebp-8h]
  long double gb; // [esp+8h] [ebp-8h]
  float overbrightFactor; // [esp+18h] [ebp+8h]
  float brightnessa; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&g + 1) = 1.0 / v5;
  *(float *)&g = (float)(1.0 / v5) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(g3) = a1;
    if ( brightness <= 1.0 )
      *((float *)&g3 + 1) = 0.125 - (float)(brightness * brightness) * 0.075;
    else
      HIDWORD(g3) = 1028443341;
    v6 = 0;
  }
  else
  {
    g3 = a1 | 0x3E00000000000000LL;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&g3, y: g);
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( *((float *)&g3 + 1) < v9 )
      v10 = (float)((float)(v9 - *((float *)&g3 + 1)) / (float)(1.0 - *((float *)&g3 + 1))) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / *((float *)&g3 + 1)) * 0.125;
    __libm_sse2_pow(x: *(long double *)&g3, y: g);
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    brightnessa = (float)j * 0.0039215689;
    __libm_sse2_pow(x: *(long double *)&g3, y: g);
    texturetolinear[j] = brightnessa;
    __libm_sse2_pow(x: g3a, y: ga);
    g_Mathlib_LinearToGamma[j] = brightnessa;
    __libm_sse2_pow(x: g3b, y: gb);
    g_Mathlib_GammaToLinear[j] = brightnessa;
  }
  for ( k = 0; k < 1024; ++k )
  {
    __libm_sse2_pow(x: *(long double *)&g3, y: g);
    lineartotexture[k] = (int)((double)k * 0.0009775171065493646 * 255.0);
  }
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    *(float *)&v14 = 0.5;
LABEL_33:
    overbrightFactor = *(float *)&v14;
    goto LABEL_34;
  }
  if ( overbright == 4 )
  {
    *(float *)&v14 = 0.25;
    goto LABEL_33;
  }
LABEL_34:
  for ( m = 0; m < 4096; ++m )
  {
    __libm_sse2_pow(x: *(long double *)&g3, y: g);
    v16 = (double)m * 0.0009765625;
    v17 = v16 * overbrightFactor;
    lineartovertex[m] = v17;
    if ( v17 > 1.0 )
      lineartovertex[m] = 1.0;
    v18 = (int)(float)(v17 * 255.0);
    if ( v18 <= 255 )
      v19 = v18 < 0 ? 0 : v18;
    else
      v19 = -1;
    lineartolightmap[m] = v19;
  }
}

} // namespace matchmaking_ds

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x00527CF0
// Name: float TextureToLinear(int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl TextureToLinear(int c)
{
  if ( c < 0 )
    return 0.0;
  if ( c <= 255 )
    return texturetolinear[c];
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x00527D20
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

//------------------------------------------------------------------------------
// Address: 0x00528090
// Name: float SrgbGammaToLinear(float)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00528100
// Name: float SrgbLinearToGamma(float)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00528170
// Name: float X360LinearToGamma(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl X360LinearToGamma(float flLinearValue)
{
  float v1; // xmm0_4
  float v2; // xmm0_4

  v1 = flLinearValue;
  if ( flLinearValue < 0.0 )
  {
    v1 = 0.0;
LABEL_10:
    v2 = v1 * 4.0117645;
    goto LABEL_11;
  }
  if ( flLinearValue > 1.0 )
  {
    v1 = 1.0;
LABEL_5:
    v2 = (float)(v1 * 0.50147057) + 0.50196081;
    if ( v2 > 1.0 )
      return 1.0;
    goto LABEL_11;
  }
  if ( flLinearValue >= 0.12512219 )
  {
    if ( flLinearValue < 0.50048876 )
    {
      v2 = (float)(flLinearValue * 1.0029411) + 0.25098041;
      goto LABEL_11;
    }
    goto LABEL_5;
  }
  if ( flLinearValue < 0.062561095 )
    goto LABEL_10;
  v2 = (float)(flLinearValue * 2.0058823) + 0.1254902;
LABEL_11:
  if ( v2 < 0.0 )
    return 0.0;
  if ( v2 <= 1.0 )
    return v2;
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x00528230
// Name: float SrgbGammaTo360Gamma(float)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

} // namespace makegamedata

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E07F0
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace mdlcompile

// ============================================================
// Overlay from meshutilstest (Missing functions)
// ============================================================
namespace meshutilstest {

//------------------------------------------------------------------------------
// Address: 0x00406A80
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildGammaTable(float gamma, float texGamma, float brightness, int overbright)
{
  double v4; // st7
  double v5; // st6
  double v6; // st6
  double v7; // st7
  int v8; // esi
  int v9; // eax
  int v10; // esi
  double v11; // st7
  double v12; // st5
  long double v13; // st7
  int v14; // eax
  int v15; // esi
  long double v16; // st7
  int v17; // esi
  double v18; // st6
  int v19; // esi
  long double v20; // st7
  int v21; // ecx
  unsigned __int8 v22; // al
  int g3; // [esp+4h] [ebp-10h]
  int g3a; // [esp+4h] [ebp-10h]
  int g3b; // [esp+4h] [ebp-10h]
  int g3c; // [esp+4h] [ebp-10h]
  int g3d; // [esp+4h] [ebp-10h]
  float g1; // [esp+8h] [ebp-Ch]
  float g; // [esp+Ch] [ebp-8h]
  float v30; // [esp+10h] [ebp-4h]
  float gammaa; // [esp+18h] [ebp+4h]
  float overbrightFactor; // [esp+1Ch] [ebp+8h]
  float overbrightFactora; // [esp+1Ch] [ebp+8h]
  float brightnessa; // [esp+20h] [ebp+Ch]
  float overbrighta; // [esp+24h] [ebp+10h]

  v4 = 3.0;
  if ( gamma <= 3.0 )
    v4 = gamma;
  v5 = 1.0 / v4;
  v30 = v5;
  g = v5 * texGamma;
  v6 = brightness;
  if ( brightness > 0.0 )
  {
    if ( v6 <= 1.0 )
      v7 = 0.125 - v6 * v6 * 0.075;
    else
      v7 = 0.050000001;
  }
  else
  {
    v7 = 0.125;
  }
  g1 = v7;
  v8 = 0;
  g3 = 0;
  do
  {
    v9 = (int)(pow((double)g3 * 0.0039215689, g) * 255.0);
    if ( v9 >= 0 )
    {
      if ( v9 > 255 )
        LOBYTE(v9) = -1;
    }
    else
    {
      LOBYTE(v9) = 0;
    }
    texgammatable[v8++] = v9;
    g3 = v8;
  }
  while ( v8 < 256 );
  v10 = 0;
  g3a = 0;
  do
  {
    v11 = (double)g3a * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v11 = v11 * brightness;
    v12 = g1;
    if ( g1 < v11 )
      v13 = (v11 - v12) / (1.0 - v12) * 0.875 + 0.125;
    else
      v13 = v11 / v12 * 0.125;
    v14 = (int)(pow(v13, v30) * 255.0);
    if ( v14 >= 0 )
    {
      if ( v14 > 255 )
        v14 = 255;
    }
    else
    {
      v14 = 0;
    }
    lineartoscreen[v10++] = v14;
    g3a = v10;
  }
  while ( v10 < 1024 );
  v15 = 0;
  g3b = 0;
  do
  {
    v16 = (double)g3b * 0.0039215689;
    brightnessa = v16;
    texturetolinear[v15] = pow(v16, texGamma);
    g_Mathlib_LinearToGamma[v15] = pow(brightnessa, 0.4545454382896423);
    g_Mathlib_GammaToLinear[v15++] = pow(brightnessa, 2.200000047683716);
    g3b = v15;
  }
  while ( v15 < 256 );
  v17 = 0;
  g3c = 0;
  overbrightFactor = 1.0 / texGamma;
  do
  {
    lineartotexture[v17++] = (int)(pow((double)g3c * 0.0009775171065493646, overbrightFactor) * 255.0);
    g3c = v17;
  }
  while ( v17 < 1024 );
  overbrightFactora = 1.0;
  if ( overbright == 2 )
  {
    v18 = 0.5;
LABEL_33:
    overbrightFactora = v18;
    goto LABEL_34;
  }
  if ( overbright == 4 )
  {
    v18 = 0.25;
    goto LABEL_33;
  }
LABEL_34:
  v19 = 0;
  g3d = 0;
  gammaa = 1.0 / gamma;
  do
  {
    v20 = pow((double)g3d * 0.0009765625, gammaa) * overbrightFactora;
    lineartovertex[v19] = v20;
    if ( v20 > 1.0 )
      lineartovertex[v19] = 1.0;
    overbrighta = v20 * 255.0;
    v21 = (int)overbrighta;
    if ( v21 <= 255 )
      v22 = v21 < 0 ? 0 : v21;
    else
      v22 = -1;
    lineartolightmap[v19++] = v22;
    g3d = v19;
  }
  while ( v19 < 4096 );
}

} // namespace meshutilstest

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x00463F50
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace mksheet

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x0040B5B0
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace modelbrowser

// ============================================================
// Overlay from motionmapper (Missing functions)
// ============================================================
namespace motionmapper {

//------------------------------------------------------------------------------
// Address: 0x0040CAB0
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace motionmapper

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00465EE0
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildGammaTable(float gamma, float texGamma, float brightness, int overbright)
{
  int v4; // esi
  int v5; // eax
  int i; // esi
  float v7; // xmm0_4
  float v8; // xmm0_4
  int v9; // eax
  int j; // esi
  float v11; // xmm0_4
  int k; // esi
  int v13; // xmm0_4
  int m; // esi
  float v15; // xmm1_4
  int v16; // eax
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  if ( brightness > 0.0 )
  {
    if ( brightness <= 1.0 )
    {
      v4 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v4 = 0;
    }
  }
  else
  {
    g3 = 0.125;
    v4 = 0;
  }
  do
  {
    __libm_sse2_pow();
    v5 = (int)(float)((float)((float)v4 * 0.0039215689) * 255.0);
    if ( v5 >= 0 )
    {
      if ( v5 > 255 )
        LOBYTE(v5) = -1;
    }
    else
    {
      LOBYTE(v5) = 0;
    }
    texgammatable[v4++] = v5;
  }
  while ( v4 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v7 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v7 = v7 * brightness;
    if ( g3 < v7 )
      v8 = (float)((float)(v7 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v8 = (float)(v7 / g3) * 0.125;
    __libm_sse2_pow();
    v9 = (int)(float)(v8 * 255.0);
    if ( v9 >= 0 )
    {
      if ( v9 > 255 )
        v9 = 255;
    }
    else
    {
      v9 = 0;
    }
    lineartoscreen[i] = v9;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow();
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow();
    v11 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v11;
    __libm_sse2_pow();
    g_Mathlib_GammaToLinear[j] = v11;
  }
  for ( k = 0; k < 1024; ++k )
  {
    __libm_sse2_pow();
    lineartotexture[k] = 255 * (int)((double)k * 0.0009775171065493646);
  }
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v13 = 1056964608;
LABEL_30:
    overbrightFactor = *(float *)&v13;
    goto LABEL_31;
  }
  if ( overbright == 4 )
  {
    v13 = 1048576000;
    goto LABEL_30;
  }
LABEL_31:
  for ( m = 0; m < 4096; ++m )
  {
    __libm_sse2_pow();
    v15 = (double)m * 0.0009765625;
    lineartovertex[m] = v15 * overbrightFactor;
    if ( (float)(v15 * overbrightFactor) > 1.0 )
      lineartovertex[m] = 1.0;
    v16 = (int)(float)((float)(v15 * 255.0) * overbrightFactor);
    if ( v16 >= 0 )
    {
      if ( v16 > 255 )
        LOBYTE(v16) = -1;
    }
    else
    {
      LOBYTE(v16) = 0;
    }
    lineartolightmap[m] = v16;
  }
}

} // namespace particle_import

// ============================================================
// Overlay from pcffix (Missing functions)
// ============================================================
namespace pcffix {

//------------------------------------------------------------------------------
// Address: 0x00442320
// Name: void BuildExponentTable(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildExponentTable()
{
  int v0; // ecx
  float *v1; // edx
  int i; // esi
  double v3; // st4
  unsigned int v4; // eax
  double v5; // st3
  double v6; // st4

  v0 = -128;
  v1 = power2_n;
  for ( i = 256; i != 0; --i )
  {
    v3 = 2.0;
    v4 = v0;
    if ( v0 < 0 )
      v4 = -v0;
    v5 = 1.0;
    while ( 1 )
    {
      if ( (v4 & 1) != 0 )
        v5 = v5 * v3;
      v4 >>= 1;
      if ( v4 == 0 )
        break;
      v3 = v3 * v3;
    }
    v6 = v5;
    if ( v0 < 0 )
      v6 = 1.0 / v5;
    ++v0;
    *v1++ = v6 * 0.0039215689;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00442380
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildGammaTable(float gamma, float texGamma, float brightness, int overbright)
{
  double v4; // st7
  double v5; // st6
  double v6; // st6
  double v7; // st7
  int v8; // esi
  int v9; // eax
  int v10; // esi
  double v11; // st7
  double v12; // st5
  long double v13; // st7
  int v14; // eax
  int v15; // esi
  long double v16; // st7
  int v17; // esi
  double v18; // st6
  int v19; // esi
  long double v20; // st7
  int v21; // ecx
  unsigned __int8 v22; // al
  int g3; // [esp+4h] [ebp-10h]
  int g3a; // [esp+4h] [ebp-10h]
  int g3b; // [esp+4h] [ebp-10h]
  int g3c; // [esp+4h] [ebp-10h]
  int g3d; // [esp+4h] [ebp-10h]
  float g1; // [esp+8h] [ebp-Ch]
  float g; // [esp+Ch] [ebp-8h]
  float v30; // [esp+10h] [ebp-4h]
  float gammaa; // [esp+18h] [ebp+4h]
  float overbrightFactor; // [esp+1Ch] [ebp+8h]
  float overbrightFactora; // [esp+1Ch] [ebp+8h]
  float brightnessa; // [esp+20h] [ebp+Ch]
  float overbrighta; // [esp+24h] [ebp+10h]

  v4 = 3.0;
  if ( gamma <= 3.0 )
    v4 = gamma;
  v5 = 1.0 / v4;
  v30 = v5;
  g = v5 * texGamma;
  v6 = brightness;
  if ( brightness > 0.0 )
  {
    if ( v6 <= 1.0 )
      v7 = 0.125 - v6 * v6 * 0.075;
    else
      v7 = 0.050000001;
  }
  else
  {
    v7 = 0.125;
  }
  g1 = v7;
  v8 = 0;
  g3 = 0;
  do
  {
    v9 = (int)(pow((double)g3 * 0.0039215689, g) * 255.0);
    if ( v9 >= 0 )
    {
      if ( v9 > 255 )
        LOBYTE(v9) = -1;
    }
    else
    {
      LOBYTE(v9) = 0;
    }
    texgammatable[v8++] = v9;
    g3 = v8;
  }
  while ( v8 < 256 );
  v10 = 0;
  g3a = 0;
  do
  {
    v11 = (double)g3a * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v11 = v11 * brightness;
    v12 = g1;
    if ( g1 < v11 )
      v13 = (v11 - v12) / (1.0 - v12) * 0.875 + 0.125;
    else
      v13 = v11 / v12 * 0.125;
    v14 = (int)(pow(v13, v30) * 255.0);
    if ( v14 >= 0 )
    {
      if ( v14 > 255 )
        v14 = 255;
    }
    else
    {
      v14 = 0;
    }
    lineartoscreen[v10++] = v14;
    g3a = v10;
  }
  while ( v10 < 1024 );
  v15 = 0;
  g3b = 0;
  do
  {
    v16 = (double)g3b * 0.0039215689;
    brightnessa = v16;
    texturetolinear[v15] = pow(v16, texGamma);
    g_Mathlib_LinearToGamma[v15] = pow(brightnessa, 0.4545454382896423);
    g_Mathlib_GammaToLinear[v15++] = pow(brightnessa, 2.200000047683716);
    g3b = v15;
  }
  while ( v15 < 256 );
  v17 = 0;
  g3c = 0;
  overbrightFactor = 1.0 / texGamma;
  do
  {
    lineartotexture[v17++] = (int)(pow((double)g3c * 0.0009775171065493646, overbrightFactor) * 255.0);
    g3c = v17;
  }
  while ( v17 < 1024 );
  BuildExponentTable();
  overbrightFactora = 1.0;
  if ( overbright == 2 )
  {
    v18 = 0.5;
LABEL_33:
    overbrightFactora = v18;
    goto LABEL_34;
  }
  if ( overbright == 4 )
  {
    v18 = 0.25;
    goto LABEL_33;
  }
LABEL_34:
  v19 = 0;
  g3d = 0;
  gammaa = 1.0 / gamma;
  do
  {
    v20 = pow((double)g3d * 0.0009765625, gammaa) * overbrightFactora;
    lineartovertex[v19] = v20;
    if ( v20 > 1.0 )
      lineartovertex[v19] = 1.0;
    overbrighta = v20 * 255.0;
    v21 = (int)overbrighta;
    if ( v21 <= 255 )
      v22 = v21 < 0 ? 0 : v21;
    else
      v22 = -1;
    lineartolightmap[v19++] = v22;
    g3d = v19;
  }
  while ( v19 < 4096 );
}

} // namespace pcffix

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x00460840
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x004692E0
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace phogen

// ============================================================
// Overlay from ps3shaderoptimizer (Missing functions)
// ============================================================
namespace ps3shaderoptimizer {

//------------------------------------------------------------------------------
// Address: 0x00417640
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace ps3shaderoptimizer

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x004287C0
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace scenemanager

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004C5140
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace sceneviewer

// ============================================================
// Overlay from ScratchPad3DViewer (Missing functions)
// ============================================================
namespace ScratchPad3DViewer {

//------------------------------------------------------------------------------
// Address: 0x00409450
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace ScratchPad3DViewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00469EB0
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace sfmgen

// ============================================================
// Overlay from shaderapidx10 (Missing functions)
// ============================================================
namespace shaderapidx10 {

//------------------------------------------------------------------------------
// Address: 0x10041220
// Name: float GammaToLinearFullRange(float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl GammaToLinearFullRange(float gamma)
{
  return pow(gamma, 2.200000047683716);
}

//------------------------------------------------------------------------------
// Address: 0x10041230
// Name: float LinearToGammaFullRange(float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl LinearToGammaFullRange(float linear)
{
  return pow(linear, 0.4545454382896423);
}

//------------------------------------------------------------------------------
// Address: 0x10041240
// Name: float GammaToLinear(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl GammaToLinear(float gamma)
{
  if ( gamma < 0.0 )
    return 0.0;
  if ( gamma < 0.94999999 )
    return g_Mathlib_GammaToLinear[(float)(gamma * 255.0)];
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10041290
// Name: float SrgbGammaToLinear(float)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10041300
// Name: float SrgbLinearToGamma(float)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10041370
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(unsigned int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm1_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  int k; // esi
  int v14; // xmm0_4
  int m; // esi
  float v16; // xmm0_4
  float v17; // xmm0_4
  int v18; // ecx
  unsigned __int8 v19; // al
  __int64 g3; // [esp+0h] [ebp-10h]
  long double g3a; // [esp+0h] [ebp-10h]
  long double g3b; // [esp+0h] [ebp-10h]
  long double g; // [esp+8h] [ebp-8h]
  long double ga; // [esp+8h] [ebp-8h]
  long double gb; // [esp+8h] [ebp-8h]
  float overbrightFactor; // [esp+18h] [ebp+8h]
  float brightnessa; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&g + 1) = 1.0 / v5;
  *(float *)&g = (float)(1.0 / v5) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(g3) = a1;
    if ( brightness <= 1.0 )
      *((float *)&g3 + 1) = 0.125 - (float)(brightness * brightness) * 0.075;
    else
      HIDWORD(g3) = 1028443341;
    v6 = 0;
  }
  else
  {
    g3 = a1 | 0x3E00000000000000LL;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&g3, y: g);
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( *((float *)&g3 + 1) < v9 )
      v10 = (float)((float)(v9 - *((float *)&g3 + 1)) / (float)(1.0 - *((float *)&g3 + 1))) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / *((float *)&g3 + 1)) * 0.125;
    __libm_sse2_pow(x: *(long double *)&g3, y: g);
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    brightnessa = (float)j * 0.0039215689;
    __libm_sse2_pow(x: *(long double *)&g3, y: g);
    texturetolinear[j] = brightnessa;
    __libm_sse2_pow(x: g3a, y: ga);
    g_Mathlib_LinearToGamma[j] = brightnessa;
    __libm_sse2_pow(x: g3b, y: gb);
    g_Mathlib_GammaToLinear[j] = brightnessa;
  }
  for ( k = 0; k < 1024; ++k )
  {
    __libm_sse2_pow(x: *(long double *)&g3, y: g);
    lineartotexture[k] = (int)((double)k * 0.0009775171065493646 * 255.0);
  }
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    *(float *)&v14 = 0.5;
LABEL_33:
    overbrightFactor = *(float *)&v14;
    goto LABEL_34;
  }
  if ( overbright == 4 )
  {
    *(float *)&v14 = 0.25;
    goto LABEL_33;
  }
LABEL_34:
  for ( m = 0; m < 4096; ++m )
  {
    __libm_sse2_pow(x: *(long double *)&g3, y: g);
    v16 = (double)m * 0.0009765625;
    v17 = v16 * overbrightFactor;
    lineartovertex[m] = v17;
    if ( v17 > 1.0 )
      lineartovertex[m] = 1.0;
    v18 = (int)(float)(v17 * 255.0);
    if ( v18 <= 255 )
      v19 = v18 < 0 ? 0 : v18;
    else
      v19 = -1;
    lineartolightmap[m] = v19;
  }
}

} // namespace shaderapidx10

// ============================================================
// Overlay from simdtest (Missing functions)
// ============================================================
namespace simdtest {

//------------------------------------------------------------------------------
// Address: 0x004018E0
// Name: float GammaToLinear(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl GammaToLinear(float gamma)
{
  if ( gamma < 0.0 )
    return 0.0;
  if ( gamma < 0.94999999 )
    return g_Mathlib_GammaToLinear[(float)(gamma * 255.0)];
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x00401930
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace simdtest

// ============================================================
// Overlay from stdshader_dbg (Missing functions)
// ============================================================
namespace stdshader_dbg {

//------------------------------------------------------------------------------
// Address: 0x10002800
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace stdshader_dbg

// ============================================================
// Overlay from stdshader_dx9 (Missing functions)
// ============================================================
namespace stdshader_dx9 {

//------------------------------------------------------------------------------
// Address: 0x10048EE0
// Name: float GammaToLinear(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl GammaToLinear(float gamma)
{
  if ( gamma < 0.0 )
    return 0.0;
  if ( gamma < 0.94999999 )
    return g_Mathlib_GammaToLinear[(float)(gamma * 255.0)];
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10048F30
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

//------------------------------------------------------------------------------
// Address: 0x100492A0
// Name: float SrgbGammaToLinear(float)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

} // namespace stdshader_dx9

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004D9BB0
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace studiomdl

// ============================================================
// Overlay from tgadiff (Missing functions)
// ============================================================
namespace tgadiff {

//------------------------------------------------------------------------------
// Address: 0x0042AD20
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace tgadiff

// ============================================================
// Overlay from tgamse (Missing functions)
// ============================================================
namespace tgamse {

//------------------------------------------------------------------------------
// Address: 0x0042A970
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace tgamse

// ============================================================
// Overlay from vbsp (Missing functions)
// ============================================================
namespace vbsp {

//------------------------------------------------------------------------------
// Address: 0x00455960
// Name: float TextureToLinear(int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl TextureToLinear(int c)
{
  if ( c < 0 )
    return 0.0;
  if ( c <= 255 )
    return texturetolinear[c];
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x00455990
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

//------------------------------------------------------------------------------
// Address: 0x00455D00
// Name: float X360LinearToGamma(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl X360LinearToGamma(float flLinearValue)
{
  float v1; // xmm0_4
  float v2; // xmm0_4

  v1 = flLinearValue;
  if ( flLinearValue < 0.0 )
  {
    v1 = 0.0;
LABEL_10:
    v2 = v1 * 4.0117645;
    goto LABEL_11;
  }
  if ( flLinearValue > 1.0 )
  {
    v1 = 1.0;
LABEL_5:
    v2 = (float)(v1 * 0.50147057) + 0.50196081;
    if ( v2 > 1.0 )
      return 1.0;
    goto LABEL_11;
  }
  if ( flLinearValue >= 0.12512219 )
  {
    if ( flLinearValue < 0.50048876 )
    {
      v2 = (float)(flLinearValue * 1.0029411) + 0.25098041;
      goto LABEL_11;
    }
    goto LABEL_5;
  }
  if ( flLinearValue < 0.062561095 )
    goto LABEL_10;
  v2 = (float)(flLinearValue * 2.0058823) + 0.1254902;
LABEL_11:
  if ( v2 < 0.0 )
    return 0.0;
  if ( v2 <= 1.0 )
    return v2;
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x00455DC0
// Name: float SrgbGammaTo360Gamma(float)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

} // namespace vbsp

// ============================================================
// Overlay from vbsp2 (Missing functions)
// ============================================================
namespace vbsp2 {

//------------------------------------------------------------------------------
// Address: 0x00405980
// Name: void ColorRGBExp32ToVector(struct ColorRGBExp32 const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ColorRGBExp32ToVector(const ColorRGBExp32 *in, Vector *out)
{
  out->x = (float)((float)in->r * dword_468600[in->exponent]) * 255.0;
  out->y = (float)((float)in->g * dword_468600[in->exponent]) * 255.0;
  out->z = (float)((float)in->b * dword_468600[in->exponent]) * 255.0;
}

//------------------------------------------------------------------------------
// Address: 0x00405A00
// Name: void VectorToColorRGBExp32(class Vector const __near &,struct ColorRGBExp32 __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VectorToColorRGBExp32(const Vector *vin, ColorRGBExp32 *c)
{
  float x; // xmm1_4
  float y; // xmm2_4
  const Vector *p_y; // ecx
  float z; // xmm0_4
  int v6; // eax
  int blue; // [esp+8h] [ebp+8h]

  x = vin->x;
  y = vin->y;
  p_y = (const Vector *)&vin->y;
  if ( vin->x <= y )
  {
    z = vin->z;
    if ( y <= z )
      p_y = (const Vector *)&vin->z;
  }
  else
  {
    z = vin->z;
    p_y = (const Vector *)&vin->z;
    if ( x > z )
      p_y = vin;
  }
  if ( p_y->x == 0.0 )
    v6 = 0;
  else
    v6 = (unsigned __int8)(LODWORD(p_y->x) >> 23) - 134;
  blue = (127 - v6) << 23;
  c->g = (int)(float)(y * *(float *)&blue);
  c->r = (int)(float)(x * *(float *)&blue);
  c->b = (int)(float)(z * *(float *)&blue);
  c->exponent = v6;
}

//------------------------------------------------------------------------------
// Address: 0x00405AA0
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace vbsp2

// ============================================================
// Overlay from vbspinfo (Missing functions)
// ============================================================
namespace vbspinfo {

//------------------------------------------------------------------------------
// Address: 0x004141B0
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace vbspinfo

// ============================================================
// Overlay from vcdupdate (Missing functions)
// ============================================================
namespace vcdupdate {

//------------------------------------------------------------------------------
// Address: 0x00411710
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace vcdupdate

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10041C90
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildGammaTable(float gamma, float texGamma, float brightness, int overbright)
{
  int v4; // esi
  int v5; // eax
  int i; // esi
  float v7; // xmm0_4
  float v8; // xmm0_4
  int v9; // eax
  int j; // esi
  float v11; // xmm0_4
  int k; // esi
  int v13; // xmm0_4
  int m; // esi
  float v15; // xmm1_4
  int v16; // eax
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  if ( brightness > 0.0 )
  {
    if ( brightness <= 1.0 )
    {
      v4 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v4 = 0;
    }
  }
  else
  {
    g3 = 0.125;
    v4 = 0;
  }
  do
  {
    __libm_sse2_pow();
    v5 = (int)(float)((float)((float)v4 * 0.0039215689) * 255.0);
    if ( v5 >= 0 )
    {
      if ( v5 > 255 )
        LOBYTE(v5) = -1;
    }
    else
    {
      LOBYTE(v5) = 0;
    }
    texgammatable[v4++] = v5;
  }
  while ( v4 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v7 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v7 = v7 * brightness;
    if ( g3 < v7 )
      v8 = (float)((float)(v7 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v8 = (float)(v7 / g3) * 0.125;
    __libm_sse2_pow();
    v9 = (int)(float)(v8 * 255.0);
    if ( v9 >= 0 )
    {
      if ( v9 > 255 )
        v9 = 255;
    }
    else
    {
      v9 = 0;
    }
    lineartoscreen[i] = v9;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow();
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow();
    v11 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v11;
    __libm_sse2_pow();
    g_Mathlib_GammaToLinear[j] = v11;
  }
  for ( k = 0; k < 1024; ++k )
  {
    __libm_sse2_pow();
    lineartotexture[k] = 255 * (int)((double)k * 0.0009775171065493646);
  }
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v13 = 1056964608;
LABEL_30:
    overbrightFactor = *(float *)&v13;
    goto LABEL_31;
  }
  if ( overbright == 4 )
  {
    v13 = 1048576000;
    goto LABEL_30;
  }
LABEL_31:
  for ( m = 0; m < 4096; ++m )
  {
    __libm_sse2_pow();
    v15 = (double)m * 0.0009765625;
    lineartovertex[m] = v15 * overbrightFactor;
    if ( (float)(v15 * overbrightFactor) > 1.0 )
      lineartovertex[m] = 1.0;
    v16 = (int)(float)((float)(v15 * 255.0) * overbrightFactor);
    if ( v16 >= 0 )
    {
      if ( v16 > 255 )
        LOBYTE(v16) = -1;
    }
    else
    {
      LOBYTE(v16) = 0;
    }
    lineartolightmap[m] = v16;
  }
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x004103C0
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00430D50
// Name: float X360LinearToGamma(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl X360LinearToGamma(float flLinearValue)
{
  float v1; // xmm0_4
  float v2; // xmm0_4
  float fl360GammaValue; // [esp+4h] [ebp+4h]

  v1 = flLinearValue;
  if ( flLinearValue > 1.0 )
  {
    v1 = 1.0;
LABEL_3:
    v2 = (float)(v1 * 0.50147057) + 0.50196081;
    goto LABEL_4;
  }
  if ( flLinearValue >= 0.0 )
  {
    if ( flLinearValue >= 0.12512219 )
    {
      if ( flLinearValue >= 0.50048876 )
        goto LABEL_3;
      v2 = (float)(flLinearValue * 1.0029411) + 0.25098041;
    }
    else if ( flLinearValue >= 0.062561095 )
    {
      v2 = (float)(flLinearValue * 2.0058823) + 0.1254902;
    }
    else
    {
      v2 = flLinearValue * 4.0117645;
    }
  }
  else
  {
    v2 = 0.0 * 4.0117645;
  }
LABEL_4:
  fl360GammaValue = v2;
  if ( v2 > 1.0 )
    return 1.0;
  if ( v2 < 0.0 )
    return 0.0;
  return fl360GammaValue;
}

//------------------------------------------------------------------------------
// Address: 0x00430E10
// Name: float SrgbGammaTo360Gamma(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl SrgbGammaTo360Gamma(float flSrgbGammaValue)
{
  float v1; // xmm0_4
  float v2; // xmm0_4

  v1 = 1.0;
  if ( flSrgbGammaValue > 1.0
    || (v1 = 0.0, flSrgbGammaValue >= 0.0) && (v1 = flSrgbGammaValue, flSrgbGammaValue > 0.040449999) )
  {
    __libm_sse2_pow();
    v2 = (float)(v1 + 0.055) * 0.94786733;
  }
  else
  {
    v2 = v1 * 0.077399381;
  }
  return X360LinearToGamma(flLinearValue: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00430E80
// Name: float TextureToLinear(int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl TextureToLinear(int c)
{
  if ( c < 0 )
    return 0.0;
  if ( c <= 255 )
    return texturetolinear[c];
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x00430EA0
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildGammaTable(float gamma, float texGamma, float brightness, int overbright)
{
  int v4; // esi
  int v5; // eax
  int i; // esi
  float v7; // xmm0_4
  float v8; // xmm0_4
  int v9; // eax
  int j; // esi
  int k; // esi
  int v12; // xmm0_4
  int m; // esi
  float v14; // xmm0_4
  float v15; // xmm0_4
  int v16; // ecx
  unsigned __int8 v17; // al
  float g1; // [esp+4h] [ebp-Ch]
  float overbrightFactor; // [esp+18h] [ebp+8h]
  float brightnessa; // [esp+1Ch] [ebp+Ch]

  if ( brightness > 0.0 )
  {
    if ( brightness <= 1.0 )
      g1 = 0.125 - (float)(brightness * brightness) * 0.075;
    else
      g1 = 0.050000001;
    v4 = 0;
  }
  else
  {
    g1 = 0.125;
    v4 = 0;
  }
  do
  {
    __libm_sse2_pow();
    v5 = (int)(float)((float)((float)v4 * 0.0039215689) * 255.0);
    if ( v5 >= 0 )
    {
      if ( v5 > 255 )
        LOBYTE(v5) = -1;
    }
    else
    {
      LOBYTE(v5) = 0;
    }
    texgammatable[v4++] = v5;
  }
  while ( v4 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v7 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v7 = v7 * brightness;
    if ( g1 < v7 )
      v8 = (float)((float)(v7 - g1) / (float)(1.0 - g1)) * 0.875 + 0.125;
    else
      v8 = (float)(v7 / g1) * 0.125;
    __libm_sse2_pow();
    v9 = (int)(float)(v8 * 255.0);
    if ( v9 >= 0 )
    {
      if ( v9 > 255 )
        v9 = 255;
    }
    else
    {
      v9 = 0;
    }
    lineartoscreen[i] = v9;
  }
  for ( j = 0; j < 256; ++j )
  {
    brightnessa = (float)j * 0.0039215689;
    __libm_sse2_pow();
    texturetolinear[j] = brightnessa;
    __libm_sse2_pow();
    g_Mathlib_LinearToGamma[j] = brightnessa;
    __libm_sse2_pow();
    g_Mathlib_GammaToLinear[j] = brightnessa;
  }
  for ( k = 0; k < 1024; ++k )
  {
    __libm_sse2_pow();
    lineartotexture[k] = 255 * (int)((double)k * 0.0009775171065493646);
  }
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v12 = 1056964608;
LABEL_31:
    overbrightFactor = *(float *)&v12;
    goto LABEL_32;
  }
  if ( overbright == 4 )
  {
    v12 = 1048576000;
    goto LABEL_31;
  }
LABEL_32:
  for ( m = 0; m < 4096; ++m )
  {
    __libm_sse2_pow();
    v14 = (double)m * 0.0009765625;
    v15 = v14 * overbrightFactor;
    lineartovertex[m] = v15;
    if ( v15 > 1.0 )
      lineartovertex[m] = 1.0;
    v16 = (int)(float)(v15 * 255.0);
    if ( v16 <= 255 )
      v17 = v16 < 0 ? 0 : v16;
    else
      v17 = -1;
    lineartolightmap[m] = v17;
  }
}

} // namespace vgui_perftest

// ============================================================
// Overlay from videocache (Missing functions)
// ============================================================
namespace videocache {

//------------------------------------------------------------------------------
// Address: 0x00414860
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace videocache

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0056FFA0
// Name: float TextureToLinear(int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl TextureToLinear(int c)
{
  if ( c < 0 )
    return 0.0;
  if ( c <= 255 )
    return texturetolinear[c];
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x0056FFD0
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

//------------------------------------------------------------------------------
// Address: 0x00570340
// Name: float X360LinearToGamma(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl X360LinearToGamma(float flLinearValue)
{
  float v1; // xmm0_4
  float v2; // xmm0_4

  v1 = flLinearValue;
  if ( flLinearValue < 0.0 )
  {
    v1 = 0.0;
LABEL_10:
    v2 = v1 * 4.0117645;
    goto LABEL_11;
  }
  if ( flLinearValue > 1.0 )
  {
    v1 = 1.0;
LABEL_5:
    v2 = (float)(v1 * 0.50147057) + 0.50196081;
    if ( v2 > 1.0 )
      return 1.0;
    goto LABEL_11;
  }
  if ( flLinearValue >= 0.12512219 )
  {
    if ( flLinearValue < 0.50048876 )
    {
      v2 = (float)(flLinearValue * 1.0029411) + 0.25098041;
      goto LABEL_11;
    }
    goto LABEL_5;
  }
  if ( flLinearValue < 0.062561095 )
    goto LABEL_10;
  v2 = (float)(flLinearValue * 2.0058823) + 0.1254902;
LABEL_11:
  if ( v2 < 0.0 )
    return 0.0;
  if ( v2 <= 1.0 )
    return v2;
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x00570400
// Name: float SrgbGammaTo360Gamma(float)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

} // namespace vmap

// ============================================================
// Overlay from vphysics (Missing functions)
// ============================================================
namespace vphysics {

//------------------------------------------------------------------------------
// Address: 0x100AB6D0
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace vphysics

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10077980
// Name: float TextureToLinear(int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl TextureToLinear(int c)
{
  if ( c < 0 )
    return 0.0;
  if ( c <= 255 )
    return texturetolinear[c];
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x100779B0
// Name: int LinearToScreenGamma(float)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LinearToScreenGamma(float f)
{
  int v1; // eax

  v1 = (int)(float)(f * 1023.0);
  if ( v1 < 0 )
    return lineartoscreen[0];
  if ( v1 > 1023 )
    v1 = 1023;
  return lineartoscreen[v1];
}

//------------------------------------------------------------------------------
// Address: 0x100779F0
// Name: void ColorRGBExp32ToVector(struct ColorRGBExp32 const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ColorRGBExp32ToVector(const ColorRGBExp32 *in, Vector *out)
{
  out->x = (float)((float)in->r * dword_10135B00[in->exponent]) * 255.0;
  out->y = (float)((float)in->g * dword_10135B00[in->exponent]) * 255.0;
  out->z = (float)((float)in->b * dword_10135B00[in->exponent]) * 255.0;
}

//------------------------------------------------------------------------------
// Address: 0x10077A70
// Name: void VectorToColorRGBExp32(class Vector const __near &,struct ColorRGBExp32 __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl VectorToColorRGBExp32(const Vector *vin, ColorRGBExp32 *c)
{
  float x; // xmm1_4
  float y; // xmm2_4
  const Vector *p_y; // ecx
  float z; // xmm0_4
  int v6; // eax
  int blue; // [esp+8h] [ebp+8h]

  x = vin->x;
  y = vin->y;
  p_y = (const Vector *)&vin->y;
  if ( vin->x <= y )
  {
    z = vin->z;
    if ( y <= z )
      p_y = (const Vector *)&vin->z;
  }
  else
  {
    z = vin->z;
    p_y = (const Vector *)&vin->z;
    if ( x > z )
      p_y = vin;
  }
  if ( p_y->x == 0.0 )
    v6 = 0;
  else
    v6 = (unsigned __int8)(LODWORD(p_y->x) >> 23) - 134;
  blue = (127 - v6) << 23;
  c->g = (int)(float)(y * *(float *)&blue);
  c->r = (int)(float)(x * *(float *)&blue);
  c->b = (int)(float)(z * *(float *)&blue);
  c->exponent = v6;
}

//------------------------------------------------------------------------------
// Address: 0x10077B10
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

//------------------------------------------------------------------------------
// Address: 0x10077E80
// Name: float X360LinearToGamma(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl X360LinearToGamma(float flLinearValue)
{
  float v1; // xmm0_4
  float v2; // xmm0_4

  v1 = flLinearValue;
  if ( flLinearValue < 0.0 )
  {
    v1 = 0.0;
LABEL_10:
    v2 = v1 * 4.0117645;
    goto LABEL_11;
  }
  if ( flLinearValue > 1.0 )
  {
    v1 = 1.0;
LABEL_5:
    v2 = (float)(v1 * 0.50147057) + 0.50196081;
    if ( v2 > 1.0 )
      return 1.0;
    goto LABEL_11;
  }
  if ( flLinearValue >= 0.12512219 )
  {
    if ( flLinearValue < 0.50048876 )
    {
      v2 = (float)(flLinearValue * 1.0029411) + 0.25098041;
      goto LABEL_11;
    }
    goto LABEL_5;
  }
  if ( flLinearValue < 0.062561095 )
    goto LABEL_10;
  v2 = (float)(flLinearValue * 2.0058823) + 0.1254902;
LABEL_11:
  if ( v2 < 0.0 )
    return 0.0;
  if ( v2 <= 1.0 )
    return v2;
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10077F40
// Name: float SrgbGammaTo360Gamma(float)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

} // namespace vrad_dll

// ============================================================
// Overlay from vscript_python (Missing functions)
// ============================================================
namespace vscript_python {

//------------------------------------------------------------------------------
// Address: 0x10009600
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(unsigned int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm1_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  int k; // esi
  int v14; // xmm0_4
  int m; // esi
  float v16; // xmm0_4
  float v17; // xmm0_4
  int v18; // ecx
  unsigned __int8 v19; // al
  __int64 g3; // [esp+0h] [ebp-10h]
  long double g3a; // [esp+0h] [ebp-10h]
  long double g3b; // [esp+0h] [ebp-10h]
  long double g; // [esp+8h] [ebp-8h]
  long double ga; // [esp+8h] [ebp-8h]
  long double gb; // [esp+8h] [ebp-8h]
  float overbrightFactor; // [esp+18h] [ebp+8h]
  float brightnessa; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&g + 1) = 1.0 / v5;
  *(float *)&g = (float)(1.0 / v5) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(g3) = a1;
    if ( brightness <= 1.0 )
      *((float *)&g3 + 1) = 0.125 - (float)(brightness * brightness) * 0.075;
    else
      HIDWORD(g3) = 1028443341;
    v6 = 0;
  }
  else
  {
    g3 = a1 | 0x3E00000000000000LL;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&g3, y: g);
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( *((float *)&g3 + 1) < v9 )
      v10 = (float)((float)(v9 - *((float *)&g3 + 1)) / (float)(1.0 - *((float *)&g3 + 1))) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / *((float *)&g3 + 1)) * 0.125;
    __libm_sse2_pow(x: *(long double *)&g3, y: g);
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    brightnessa = (float)j * 0.0039215689;
    __libm_sse2_pow(x: *(long double *)&g3, y: g);
    texturetolinear[j] = brightnessa;
    __libm_sse2_pow(x: g3a, y: ga);
    g_Mathlib_LinearToGamma[j] = brightnessa;
    __libm_sse2_pow(x: g3b, y: gb);
    g_Mathlib_GammaToLinear[j] = brightnessa;
  }
  for ( k = 0; k < 1024; ++k )
  {
    __libm_sse2_pow(x: *(long double *)&g3, y: g);
    lineartotexture[k] = (int)((double)k * 0.0009775171065493646 * 255.0);
  }
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    *(float *)&v14 = 0.5;
LABEL_33:
    overbrightFactor = *(float *)&v14;
    goto LABEL_34;
  }
  if ( overbright == 4 )
  {
    *(float *)&v14 = 0.25;
    goto LABEL_33;
  }
LABEL_34:
  for ( m = 0; m < 4096; ++m )
  {
    __libm_sse2_pow(x: *(long double *)&g3, y: g);
    v16 = (double)m * 0.0009765625;
    v17 = v16 * overbrightFactor;
    lineartovertex[m] = v17;
    if ( v17 > 1.0 )
      lineartovertex[m] = 1.0;
    v18 = (int)(float)(v17 * 255.0);
    if ( v18 <= 255 )
      v19 = v18 < 0 ? 0 : v18;
    else
      v19 = -1;
    lineartolightmap[m] = v19;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009960
// Name: _memset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memset(int dst, unsigned __int8 *value, unsigned int count)
{
  unsigned int v3; // edx
  int v4; // eax
  unsigned __int8 *v5; // edi
  int v6; // ecx
  unsigned int v7; // ecx
  unsigned int v8; // ecx

  v3 = count;
  if ( count != 0 )
  {
    LOBYTE(v4) = (_BYTE)value;
    if ( (_BYTE)value != 0 || count < 0x100 || __sse2_available == 0 )
    {
      v5 = (unsigned __int8 *)dst;
      if ( count < 4 )
        goto LABEL_15;
      v6 = -dst & 3;
      if ( v6 != 0 )
      {
        v3 = count - v6;
        do
        {
          *v5++ = (unsigned __int8)value;
          --v6;
        }
        while ( v6 != 0 );
      }
      v4 = 16843009 * (unsigned __int8)value;
      v7 = v3;
      v3 &= 3u;
      v8 = v7 >> 2;
      if ( v8 == 0 || (memset32(v5, v4, v8), v5 += 4 * v8, v3 != 0) )
      {
LABEL_15:
        do
        {
          *v5++ = v4;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else
    {
      _VEC_memzero((void *)dst, val: (int)value, len: count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100099DA
// Name: __vsnprintf_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf_l(char *string, unsigned int count, const char *format, localeinfo_struct *plocinfo, char *ap)
{
  int result; // eax
  int v6; // edi
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  if ( format != nullptr )
  {
    if ( count == 0 || string != nullptr )
    {
      str._cnt = 0x7FFFFFFF;
      if ( count <= 0x7FFFFFFF )
        str._cnt = count;
      str._flag = 66;
      str._base = string;
      str._ptr = string;
      result = _output_l(stream: &str, format, plocinfo, argptr: ap);
      v6 = result;
      if ( string != nullptr )
      {
        if ( --str._cnt < 0 )
          _flsbuf(ch: 0, &str);
        else
          *str._ptr = 0;
        return v6;
      }
    }
    else
    {
      *_errno() = 22;
      _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      return -1;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10009A8B
// Name: __vsnprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf(char *string, unsigned int count, const char *format, char *ap)
{
  return _vsnprintf_l(string, count, format, plocinfo: nullptr, ap);
}

//------------------------------------------------------------------------------
// Address: 0x10009AB0
// Name: _memcpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memcpy(unsigned __int8 *dst, unsigned __int8 *src, unsigned int count)
{
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // edi
  unsigned int v8; // ecx

  v3 = src;
  v4 = dst;
  if ( dst > src && dst < &src[count] )
  {
    v6 = &src[count - 4];
    v7 = &dst[count - 4];
    if ( ((unsigned __int8)v7 & 3) != 0 )
    {
      switch ( count )
      {
        case 0u:
          return;
        case 1u:
TrailDown1:
          v7[3] = v6[3];
          break;
        case 2u:
TrailDown2:
          v7[3] = v6[3];
          v7[2] = v6[2];
          break;
        case 3u:
TrailDown3:
          v7[3] = v6[3];
          v7[2] = v6[2];
          v7[1] = v6[1];
          break;
        default:
          __asm { jmp     dword ptr ds:(ByteCopyDown+4)[eax*4] }
          return;
      }
    }
    else
    {
      v8 = count >> 2;
      if ( count >> 2 < 8 )
      {
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1;
          case 2u:
            goto TrailDown2;
          case 3u:
            goto TrailDown3;
        }
      }
      else
      {
        while ( v8 != 0 )
        {
          *(_DWORD *)v7 = *(_DWORD *)v6;
          v6 -= 4;
          v7 -= 4;
          --v8;
        }
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1;
          case 2u:
            goto TrailDown2;
          case 3u:
            goto TrailDown3;
        }
      }
    }
  }
  else if ( count >= 0x100
         && __sse2_available != 0
         && (v3 = src, v4 = dst, ((unsigned __int8)dst & 0xF) == ((unsigned __int8)src & 0xF)) )
  {
    _VEC_memcpy(dst, src, len: count);
  }
  else
  {
    if ( ((unsigned __int8)v4 & 3) != 0 )
    {
      if ( count >= 4 )
        __asm { jmp     dword ptr ds:(CopyUnwindUp+4)[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0[ecx*4]; jumptable 10009B0C case 0 }
    }
    v5 = count >> 2;
    switch ( v5 )
    {
      case 0u:
        goto UnwindUp0;
      case 1u:
        goto UnwindUp1;
      case 2u:
        goto UnwindUp2;
      case 3u:
        goto UnwindUp3;
      case 4u:
        goto UnwindUp4;
      case 5u:
        goto UnwindUp5;
      case 6u:
        goto UnwindUp6;
      case 7u:
        *(_DWORD *)&v4[4 * v5 - 28] = *(_DWORD *)&v3[4 * v5 - 28];
UnwindUp6:
        *(_DWORD *)&v4[4 * v5 - 24] = *(_DWORD *)&v3[4 * v5 - 24];
UnwindUp5:
        *(_DWORD *)&v4[4 * v5 - 20] = *(_DWORD *)&v3[4 * v5 - 20];
UnwindUp4:
        *(_DWORD *)&v4[4 * v5 - 16] = *(_DWORD *)&v3[4 * v5 - 16];
UnwindUp3:
        *(_DWORD *)&v4[4 * v5 - 12] = *(_DWORD *)&v3[4 * v5 - 12];
UnwindUp2:
        *(_DWORD *)&v4[4 * v5 - 8] = *(_DWORD *)&v3[4 * v5 - 8];
UnwindUp1:
        *(_DWORD *)&v4[4 * v5 - 4] = *(_DWORD *)&v3[4 * v5 - 4];
        v3 += 4 * v5;
        v4 += 4 * v5;
UnwindUp0:
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailUp1;
          case 2u:
            goto TrailUp2;
          case 3u:
            goto TrailUp3;
        }
      default:
        qmemcpy(v4, v3, 4 * v5);
        v3 += 4 * v5;
        v4 += 4 * v5;
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
TrailUp1:
            *v4 = *v3;
            break;
          case 2u:
TrailUp2:
            *v4 = *v3;
            v4[1] = v3[1];
            break;
          case 3u:
TrailUp3:
            *v4 = *v3;
            v4[1] = v3[1];
            v4[2] = v3[2];
            break;
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009E30
// Name: _strchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strchr(char *string, unsigned __int8 chr)
{
  char *v2; // edx
  char v3; // cl
  int v4; // ecx
  int v5; // esi
  int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax

  v2 = string;
  if ( ((unsigned __int8)string & 3) != 0 )
  {
    while ( 1 )
    {
      v3 = *v2++;
      if ( v3 == chr || v3 == 0 )
        break;
      if ( ((unsigned __int8)v2 & 3) == 0 )
        goto main_loop;
    }
  }
  else
  {
    do
    {
main_loop:
      while ( 1 )
      {
        v4 = ((chr << 8) | chr | (((chr << 8) | chr) << 16)) ^ *(_DWORD *)v2;
        v5 = *(_DWORD *)v2 + 2130640639;
        v6 = v5 ^ ~*(_DWORD *)v2;
        v2 += 4;
        if ( (((v4 + 2130640639) ^ ~v4) & 0x81010100) != 0 )
          break;
        v7 = v6 & 0x81010100;
        if ( v7 != 0 && ((v7 & 0x1010100) != 0 || (v5 & 0x80000000) == 0) )
          return;
      }
      v8 = *((_DWORD *)v2 - 1);
      if ( (_BYTE)v8 == chr )
        break;
      if ( (_BYTE)v8 == 0 )
        break;
      if ( BYTE1(v8) == chr )
        break;
      if ( BYTE1(v8) == 0 )
        break;
      v9 = HIWORD(v8);
      if ( (_BYTE)v9 == chr )
        break;
    }
    while ( (_BYTE)v9 != 0 && BYTE1(v9) != chr && BYTE1(v9) != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009F96
// Name: _CRT_INIT(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _CRT_INIT(void *hDllHandle, unsigned int dwReason, unsigned int lpreserved)
{
  HANDLE ProcessHeap; // eax
  _OSVERSIONINFOA *v4; // eax
  _OSVERSIONINFOA *v5; // esi
  HANDLE v7; // eax
  int v8; // edi
  HANDLE v9; // eax
  _tiddata *v10; // eax
  _tiddata *v11; // esi
  int (__stdcall *v12)(unsigned int, _tiddata *); // eax
  DWORD CurrentThreadId; // eax
  unsigned int v14; // [esp-8h] [ebp-18h]
  _tiddata *v15; // [esp-4h] [ebp-14h]
  unsigned int winminor; // [esp+Ch] [ebp-4h]
  unsigned int osplatform; // [esp+1Ch] [ebp+Ch]
  unsigned int winmajor; // [esp+20h] [ebp+10h]

  if ( dwReason == 1 )
  {
    ProcessHeap = GetProcessHeap();
    v4 = (_OSVERSIONINFOA *)HeapAlloc(hHeap: ProcessHeap, dwFlags: 0, dwBytes: 0x94u);
    v5 = v4;
    if ( v4 == nullptr )
      return 0;
    v4->dwOSVersionInfoSize = 148;
    if ( !GetVersionExA(lpVersionInformation: v4) )
    {
      v7 = GetProcessHeap();
      HeapFree(hHeap: v7, dwFlags: 0, lpMem: v5);
      return 0;
    }
    osplatform = v5->dwPlatformId;
    winmajor = v5->dwMajorVersion;
    winminor = v5->dwMinorVersion;
    v8 = v5->dwBuildNumber & 0x7FFF;
    v9 = GetProcessHeap();
    HeapFree(hHeap: v9, dwFlags: 0, lpMem: v5);
    if ( osplatform != 2 )
      v8 |= 0x8000u;
    _osplatform = osplatform;
    _winver = winminor + (winmajor << 8);
    _winmajor = winmajor;
    _winminor = winminor;
    _osver = v8;
    if ( _heap_init() == 0 )
      return 0;
    if ( _mtinit() == 0 )
    {
LABEL_10:
      CPythonVM::DisconnectDebugger();
      return 0;
    }
    _RTC_Initialize();
    _acmdln = GetCommandLineA();
    _aenvptr = (char *)__crtGetEnvironmentStringsA();
    if ( _ioinit() < 0 )
    {
LABEL_12:
      _mtterm();
      goto LABEL_10;
    }
    if ( _setargv() < 0 || _setenvp() < 0 || _cinit(initFloatingPrecision: 0) != 0 )
    {
      _ioterm();
      goto LABEL_12;
    }
    ++_proc_attached;
  }
  else if ( dwReason != 0 )
  {
    if ( dwReason == 2 )
    {
      __set_flsgetvalue();
      v10 = (_tiddata *)calloc(count: 1u, size: 0x214u);
      v11 = v10;
      if ( v10 == nullptr )
        return 0;
      v15 = v10;
      v14 = __flsindex;
      v12 = (int (__stdcall *)(unsigned int, _tiddata *))_decode_pointer(codedptr: gpFlsSetValue);
      if ( v12(a1: v14, a2: v15) == 0 )
      {
        free(pMem: v11);
        return 0;
      }
      _initptd(ptd: v11, ptloci: nullptr);
      CurrentThreadId = GetCurrentThreadId();
      v11->_thandle = -1;
      v11->_tid = CurrentThreadId;
    }
    else if ( dwReason == 3 )
    {
      _freeptd(ptd: nullptr);
    }
  }
  else
  {
    if ( _proc_attached <= 0 )
      return 0;
    --_proc_attached;
    if ( _C_Termination_Done == 0 )
      _cexit();
    if ( lpreserved == 0 )
    {
      _ioterm();
      _mtterm();
      CPythonVM::DisconnectDebugger();
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000A16F
// Name: __DllMainCRTStartup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _DllMainCRTStartup(void *lpreserved, unsigned int dwReason, HINSTANCE hDllHandle)
{
  BOOL v5; // eax
  int retcode; // [esp+10h] [ebp-1Ch]

  if ( dwReason == 0 && _proc_attached == 0
    || (dwReason == 1 || dwReason == 2) && _CRT_INIT(hDllHandle, dwReason, (unsigned int)lpreserved) == 0 )
  {
    return 0;
  }
  v5 = DllMain(hinstDLL: hDllHandle, fdwReason: dwReason, lpvReserved: lpreserved);
  retcode = v5;
  if ( dwReason == 1 && !v5 )
  {
    DllMain(hinstDLL: hDllHandle, fdwReason: 0, lpvReserved: lpreserved);
    _CRT_INIT(hDllHandle, dwReason: 0, (unsigned int)lpreserved);
  }
  if ( (dwReason == 0 || dwReason == 3) && _CRT_INIT(hDllHandle, dwReason, (unsigned int)lpreserved) == 0 )
    return 0;
  return retcode;
}

//------------------------------------------------------------------------------
// Address: 0x1000A265
// Name: _DllMainCRTStartup(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall _DllMainCRTStartup(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
  if ( fdwReason == 1 )
    __security_init_cookie();
  return _DllMainCRTStartup(lpreserved: lpReserved, dwReason: fdwReason, hDllHandle: hinstDLL);
}

//------------------------------------------------------------------------------
// Address: 0x1000A290
// Name: _strstr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strstr(unsigned __int8 *str1, unsigned __int8 *str2)
{
  unsigned __int8 v2; // dl
  unsigned __int8 v4; // dh
  unsigned __int8 *v5; // ecx
  unsigned __int8 *v6; // esi
  char v7; // al
  unsigned __int8 v8; // ah
  unsigned __int8 v9; // al
  unsigned __int8 v10; // al

  v2 = *str2;
  if ( *str2 != 0 )
  {
    v4 = str2[1];
    if ( v4 == 0 )
      JUMPOUT(0x10009E36);
findnext:
    v5 = str2;
    v6 = str1 + 1;
    if ( *str1 == v2 )
      goto first_char_found;
    if ( *str1 != 0 )
    {
      while ( 2 )
      {
        v7 = *v6++;
        while ( v7 == v2 )
        {
first_char_found:
          v7 = *v6++;
          if ( v7 == v4 )
          {
            str1 = v6 - 1;
            while ( 1 )
            {
              v8 = v5[2];
              if ( v8 == 0 )
                break;
              v9 = *v6;
              v6 += 2;
              if ( v9 != v8 )
                goto findnext;
              v10 = v5[3];
              if ( v10 == 0 )
                break;
              v5 += 2;
              if ( v10 != *(v6 - 1) )
                goto findnext;
            }
            return;
          }
        }
        if ( v7 != 0 )
          continue;
        break;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A316
// Name: __freea
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _freea(_DWORD *_Memory)
{
  if ( _Memory != nullptr && *(_Memory - 2) == 56797 )
    free(pMem: _Memory - 2);
}

//------------------------------------------------------------------------------
// Address: 0x1000A331
// Name: public: _LocaleUpdate::_LocaleUpdate(struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_LocaleUpdate *__thiscall _LocaleUpdate::_LocaleUpdate(_LocaleUpdate *this, localeinfo_struct *plocinfo)
{
  _tiddata *v3; // eax
  _tiddata *ptd; // eax

  this->updated = false;
  if ( plocinfo != nullptr )
  {
    this->localeinfo = *plocinfo;
  }
  else
  {
    v3 = _getptd();
    this->ptd = v3;
    this->localeinfo.locinfo = v3->ptlocinfo;
    this->localeinfo.mbcinfo = v3->ptmbcinfo;
    if ( this->localeinfo.locinfo != __ptlocinfo && (__globallocalestatus & v3->_ownlocale) == 0 )
      this->localeinfo.locinfo = __updatetlocinfo();
    if ( this->localeinfo.mbcinfo != __ptmbcinfo && (__globallocalestatus & this->ptd->_ownlocale) == 0 )
      this->localeinfo.mbcinfo = __updatetmbcinfo();
    ptd = this->ptd;
    if ( (ptd->_ownlocale & 2) == 0 )
    {
      ptd->_ownlocale |= 2u;
      this->updated = true;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000A3B3
// Name: __tolower_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _tolower_l(unsigned int c, localeinfo_struct *plocinfo)
{
  threadlocaleinfostruct *locinfo; // ecx
  int v4; // eax
  unsigned int result; // eax
  int v6; // ecx
  int v7; // eax
  unsigned __int16 v8; // ax
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-18h] BYREF
  char outbuffer[4]; // [esp+18h] [ebp-8h] BYREF
  char inbuffer[4]; // [esp+1Ch] [ebp-4h] BYREF
  int ca; // [esp+28h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( c >= 0x100 )
  {
    if ( _loc_update.localeinfo.locinfo->mb_cur_max > 1
      && (ca = (int)c >> 8, _isleadbyte_l(c: BYTE1(c), plocinfo: &_loc_update.localeinfo) != 0) )
    {
      inbuffer[0] = ca;
      inbuffer[1] = c;
      inbuffer[2] = 0;
      v6 = 2;
    }
    else
    {
      *_errno() = 42;
      inbuffer[0] = c;
      inbuffer[1] = 0;
      v6 = 1;
    }
    v7 = __crtLCMapStringA(
           plocinfo: &_loc_update.localeinfo,
           Locale: _loc_update.localeinfo.locinfo->lc_handle[2],
           dwMapFlags: 0x100u,
           lpSrcStr: inbuffer,
           cchSrc: v6,
           lpDestStr: outbuffer,
           cchDest: 3,
           code_page: _loc_update.localeinfo.locinfo->lc_codepage,
           bError: 1);
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        result = (unsigned __int8)outbuffer[0];
      }
      else
      {
        LOBYTE(v8) = 0;
        HIBYTE(v8) = outbuffer[0];
        result = (unsigned __int8)outbuffer[1] | v8;
      }
      goto LABEL_18;
    }
  }
  else
  {
    locinfo = _loc_update.localeinfo.locinfo;
    if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->pctype[c] & 1;
    }
    else
    {
      v4 = _isctype_l(c, mask: 1, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v4 != 0 )
    {
      result = locinfo->pclmap[c];
LABEL_18:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x1000A4CA
// Name: _tolower
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl tolower(unsigned int c)
{
  unsigned int result; // eax

  if ( __locale_changed != 0 )
    return _tolower_l(c, plocinfo: nullptr);
  result = c;
  if ( c - 65 <= 0x19 )
    return c + 32;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000A500
// Name: __allmul
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __stdcall _allmul(__int64 a1, __int64 a2)
{
  if ( (HIDWORD(a1) | HIDWORD(a2)) != 0 )
    return a1 * a2;
  else
    return (unsigned int)a2 * (unsigned __int64)(unsigned int)a1;
}

//------------------------------------------------------------------------------
// Address: 0x1000A540
// Name: _strncat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strncat(char *Destination, const char *Source, size_t Count)
{
  size_t v3; // ecx
  char *v4; // edi
  char v5; // al
  int v6; // eax
  int v7; // eax
  char *v8; // edi
  const char *v9; // esi
  char v10; // bl
  size_t v11; // ecx
  int v12; // edx
  char v13; // dl
  int v15; // eax

  v3 = Count;
  if ( Count == 0 )
    return Destination;
  v4 = Destination;
  if ( ((unsigned __int8)Destination & 3) == 0 )
    goto find_end_of_front_string_loop;
  do
  {
    v5 = *v4++;
    if ( v5 == 0 )
    {
start_byte_3:
      v8 = v4 - 1;
      goto copy_start;
    }
  }
  while ( ((unsigned __int8)v4 & 3) != 0 );
  while ( 1 )
  {
    do
    {
find_end_of_front_string_loop:
      v6 = (*(_DWORD *)v4 + 2130640639) ^ ~*(_DWORD *)v4;
      v4 += 4;
    }
    while ( (v6 & 0x81010100) == 0 );
    v7 = *((_DWORD *)v4 - 1);
    if ( (_BYTE)v7 == 0 )
      break;
    if ( BYTE1(v7) == 0 )
    {
      v8 = v4 - 3;
      goto copy_start;
    }
    if ( (v7 & 0xFF0000) == 0 )
    {
      v8 = v4 - 2;
      goto copy_start;
    }
    if ( (v7 & 0xFF000000) == 0 )
      goto start_byte_3;
  }
  v8 = v4 - 4;
copy_start:
  v9 = Source;
  if ( ((unsigned __int8)Source & 3) == 0 )
  {
    v10 = Count;
    v11 = Count >> 2;
    if ( Count >> 2 != 0 )
      goto main_loop_entrance;
tail_loop_start:
    v3 = v10 & 3;
    if ( (v10 & 3) != 0 )
    {
      while ( 1 )
      {
        v13 = *v9++;
        *v8++ = v13;
        if ( v13 == 0 )
          break;
        if ( --v3 == 0 )
          goto empty_counter;
      }
    }
    else
    {
empty_counter:
      *v8 = v3;
    }
    return Destination;
  }
  do
  {
    LOBYTE(v12) = *v9++;
    if ( (_BYTE)v12 == 0 )
    {
LABEL_26:
      *v8 = v12;
      return Destination;
    }
    *v8++ = v12;
    if ( --v3 == 0 )
      goto empty_counter;
  }
  while ( ((unsigned __int8)v9 & 3) != 0 );
  v10 = v3;
  v11 = v3 >> 2;
  if ( v11 == 0 )
    goto tail_loop_start;
  while ( 1 )
  {
main_loop_entrance:
    v15 = (*(_DWORD *)v9 + 2130640639) ^ ~*(_DWORD *)v9;
    v12 = *(_DWORD *)v9;
    v9 += 4;
    if ( (v15 & 0x81010100) != 0 )
    {
      if ( (_BYTE)v12 == 0 )
        goto LABEL_26;
      if ( BYTE1(v12) == 0 )
        break;
      if ( (v12 & 0xFF0000) == 0 )
      {
        *(_WORD *)v8 = v12;
        v8[2] = 0;
        return Destination;
      }
      if ( (v12 & 0xFF000000) == 0 )
      {
        *(_DWORD *)v8 = v12;
        return Destination;
      }
    }
    *(_DWORD *)v8 = v12;
    v8 += 4;
    if ( --v11 == 0 )
      goto tail_loop_start;
  }
  *(_WORD *)v8 = (unsigned __int8)v12;
  return Destination;
}

//------------------------------------------------------------------------------
// Address: 0x1000A680
// Name: _memmove
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memmove(unsigned __int8 *dst, unsigned __int8 *src, unsigned int count)
{
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // edi
  unsigned int v8; // ecx

  v3 = src;
  v4 = dst;
  if ( dst > src && dst < &src[count] )
  {
    v6 = &src[count - 4];
    v7 = &dst[count - 4];
    if ( ((unsigned __int8)v7 & 3) != 0 )
    {
      switch ( count )
      {
        case 0u:
          return;
        case 1u:
TrailDown1_0:
          v7[3] = v6[3];
          break;
        case 2u:
TrailDown2_0:
          v7[3] = v6[3];
          v7[2] = v6[2];
          break;
        case 3u:
TrailDown3_0:
          v7[3] = v6[3];
          v7[2] = v6[2];
          v7[1] = v6[1];
          break;
        default:
          __asm { jmp     dword ptr ds:(ByteCopyDown_0+4)[eax*4] }
          return;
      }
    }
    else
    {
      v8 = count >> 2;
      if ( count >> 2 < 8 )
      {
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1_0;
          case 2u:
            goto TrailDown2_0;
          case 3u:
            goto TrailDown3_0;
        }
      }
      else
      {
        while ( v8 != 0 )
        {
          *(_DWORD *)v7 = *(_DWORD *)v6;
          v6 -= 4;
          v7 -= 4;
          --v8;
        }
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1_0;
          case 2u:
            goto TrailDown2_0;
          case 3u:
            goto TrailDown3_0;
        }
      }
    }
  }
  else if ( count >= 0x100
         && __sse2_available != 0
         && (v3 = src, v4 = dst, ((unsigned __int8)dst & 0xF) == ((unsigned __int8)src & 0xF)) )
  {
    _VEC_memcpy(dst, src, len: count);
  }
  else
  {
    if ( ((unsigned __int8)v4 & 3) != 0 )
    {
      if ( count >= 4 )
        __asm { jmp     dword ptr ds:(CopyUnwindUp_0+4)[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0_0[ecx*4]; jumptable 1000A6DC case 0 }
    }
    v5 = count >> 2;
    switch ( v5 )
    {
      case 0u:
        goto UnwindUp0_0;
      case 1u:
        goto UnwindUp1_0;
      case 2u:
        goto UnwindUp2_0;
      case 3u:
        goto UnwindUp3_0;
      case 4u:
        goto UnwindUp4_0;
      case 5u:
        goto UnwindUp5_0;
      case 6u:
        goto UnwindUp6_0;
      case 7u:
        *(_DWORD *)&v4[4 * v5 - 28] = *(_DWORD *)&v3[4 * v5 - 28];
UnwindUp6_0:
        *(_DWORD *)&v4[4 * v5 - 24] = *(_DWORD *)&v3[4 * v5 - 24];
UnwindUp5_0:
        *(_DWORD *)&v4[4 * v5 - 20] = *(_DWORD *)&v3[4 * v5 - 20];
UnwindUp4_0:
        *(_DWORD *)&v4[4 * v5 - 16] = *(_DWORD *)&v3[4 * v5 - 16];
UnwindUp3_0:
        *(_DWORD *)&v4[4 * v5 - 12] = *(_DWORD *)&v3[4 * v5 - 12];
UnwindUp2_0:
        *(_DWORD *)&v4[4 * v5 - 8] = *(_DWORD *)&v3[4 * v5 - 8];
UnwindUp1_0:
        *(_DWORD *)&v4[4 * v5 - 4] = *(_DWORD *)&v3[4 * v5 - 4];
        v3 += 4 * v5;
        v4 += 4 * v5;
UnwindUp0_0:
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailUp1_0;
          case 2u:
            goto TrailUp2_0;
          case 3u:
            goto TrailUp3_0;
        }
      default:
        qmemcpy(v4, v3, 4 * v5);
        v3 += 4 * v5;
        v4 += 4 * v5;
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
TrailUp1_0:
            *v4 = *v3;
            break;
          case 2u:
TrailUp2_0:
            *v4 = *v3;
            v4[1] = v3[1];
            break;
          case 3u:
TrailUp3_0:
            *v4 = *v3;
            v4[1] = v3[1];
            v4[2] = v3[2];
            break;
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A9E5
// Name: __validdrive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _validdrive(unsigned int drive)
{
  BOOL result; // eax

  result = true;
  if ( drive != 0 )
  {
    LOBYTE(drive) = drive + 64;
    strcpy((char *)&drive + 1, ":\\");
    if ( GetDriveTypeA(lpRootPathName: (LPCSTR)&drive) <= 1 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000AA1C
// Name: __getdcwd_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _getdcwd_nolock(unsigned int drive, char *pnbuf, int maxlen)
{
  int v4; // eax
  char *v5; // edi
  signed int FullPathNameA; // eax
  char *v7; // eax
  signed int v8; // eax
  DWORD LastError; // eax
  char *pname; // [esp+4h] [ebp-8h] BYREF
  char drvstr[4]; // [esp+8h] [ebp-4h] BYREF
  signed int count; // [esp+14h] [ebp+8h]

  if ( drive != 0 )
  {
    if ( !_validdrive(drive) )
    {
      *__doserrno() = 15;
      *_errno() = 13;
      _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      return nullptr;
    }
    v4 = drive;
  }
  else
  {
    v4 = _getdrive();
  }
  v5 = pnbuf;
  if ( pnbuf != nullptr )
  {
    if ( maxlen <= 0 )
    {
      *_errno() = 22;
      _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
      return nullptr;
    }
    count = maxlen;
    *pnbuf = 0;
  }
  else
  {
    count = 0;
  }
  if ( v4 != 0 )
  {
    drvstr[0] = v4 + 64;
    strcpy(&drvstr[1], ":.");
  }
  else
  {
    strcpy(drvstr, ".");
  }
  FullPathNameA = GetFullPathNameA(lpFileName: drvstr, nBufferLength: count, lpBuffer: pnbuf, lpFilePart: &pname);
  if ( FullPathNameA == 0 )
    goto LABEL_25;
  if ( pnbuf == nullptr )
  {
    if ( FullPathNameA > maxlen )
      maxlen = FullPathNameA;
    v7 = (char *)calloc(count: maxlen, size: 1u);
    v5 = v7;
    if ( v7 == nullptr )
    {
      *_errno() = 12;
      *__doserrno() = 8;
      return nullptr;
    }
    v8 = GetFullPathNameA(lpFileName: drvstr, nBufferLength: maxlen, lpBuffer: v7, lpFilePart: &pname);
    if ( v8 != 0 && v8 < maxlen )
      return v5;
LABEL_25:
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    return nullptr;
  }
  if ( FullPathNameA < count )
    return v5;
  *_errno() = 34;
  *pnbuf = 0;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000AB51
// Name: __getcwd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _getcwd(char *pnbuf, int maxlen)
{
  char *retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 7);
  retval = _getdcwd_nolock(drive: 0, pnbuf, maxlen);
  _unlock(locknum: 7);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1000ABA0
// Name: _strncpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strncpy(unsigned __int8 *dest, unsigned __int8 *source, unsigned int count)
{
  unsigned int v3; // ecx
  unsigned int v4; // ebx
  unsigned __int8 *v5; // esi
  unsigned int v7; // ecx
  unsigned __int8 v8; // al
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // edx

  v3 = count;
  if ( count == 0 )
    return;
  v4 = count;
  v5 = source;
  if ( ((unsigned __int8)source & 3) == 0 )
  {
    v7 = count >> 2;
    if ( count >> 2 != 0 )
      goto main_loop_entrance_0;
copy_tail_loop:
    while ( 1 )
    {
      v8 = *v5++;
      *dest++ = v8;
      if ( v8 == 0 )
        break;
      if ( --v4 == 0 )
        return;
    }
    while ( --v4 != 0 )
finish_loop:
      *dest++ = v8;
    return;
  }
  do
  {
    v8 = *v5++;
    *dest++ = v8;
    if ( --v3 == 0 )
      return;
    if ( v8 == 0 )
    {
      while ( ((unsigned __int8)dest & 3) != 0 )
      {
        *dest++ = 0;
        if ( --v3 == 0 )
          return;
      }
      v4 = v3;
      v9 = v3 >> 2;
      if ( v9 == 0 )
        goto finish_loop;
      goto fill_dwords_with_EOS;
    }
  }
  while ( ((unsigned __int8)v5 & 3) != 0 );
  LOBYTE(v4) = v3;
  v7 = v3 >> 2;
  if ( v7 == 0 )
  {
tail_loop_start_0:
    v4 &= 3u;
    if ( v4 != 0 )
      goto copy_tail_loop;
    return;
  }
  while ( 1 )
  {
main_loop_entrance_0:
    v10 = (*(_DWORD *)v5 + 2130640639) ^ ~*(_DWORD *)v5;
    v11 = *(_DWORD *)v5;
    v5 += 4;
    if ( (v10 & 0x81010100) != 0 )
    {
      if ( (_BYTE)v11 == 0 )
        break;
      if ( BYTE1(v11) == 0 )
      {
        *(_DWORD *)dest = (unsigned __int8)v11;
        goto fill_with_EOS_dwords;
      }
      if ( (v11 & 0xFF0000) == 0 )
      {
        *(_DWORD *)dest = (unsigned __int16)v11;
        goto fill_with_EOS_dwords;
      }
      if ( (v11 & 0xFF000000) == 0 )
      {
        *(_DWORD *)dest = v11;
        goto fill_with_EOS_dwords;
      }
    }
    *(_DWORD *)dest = v11;
    dest += 4;
    if ( --v7 == 0 )
      goto tail_loop_start_0;
  }
  *(_DWORD *)dest = 0;
fill_with_EOS_dwords:
  dest += 4;
  v8 = 0;
  v9 = v7 - 1;
  if ( v9 != 0 )
  {
fill_dwords_with_EOS:
    v8 = 0;
    do
    {
      *(_DWORD *)dest = 0;
      dest += 4;
      --v9;
    }
    while ( v9 != 0 );
  }
  v4 &= 3u;
  if ( v4 != 0 )
    goto finish_loop;
}

//------------------------------------------------------------------------------
// Address: 0x1000ACD0
// Name: __allrem
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __stdcall _allrem(unsigned __int64 a1, __int64 a2)
{
  int v2; // edi
  int v3; // eax
  unsigned __int64 v4; // rtt
  unsigned __int64 result; // rax
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rax
  unsigned int v8; // eax
  int v9; // ecx
  bool v10; // cf
  unsigned __int64 v11; // rax

  v2 = 0;
  if ( (a1 & 0x8000000000000000uLL) != 0LL )
  {
    v2 = 1;
    HIDWORD(a1) = -HIDWORD(a1) - ((_DWORD)a1 != 0);
    LODWORD(a1) = -(int)a1;
  }
  v3 = HIDWORD(a2);
  if ( a2 < 0 )
  {
    v3 = -HIDWORD(a2) - ((_DWORD)a2 != 0);
    HIDWORD(a2) = v3;
    LODWORD(a2) = -(int)a2;
  }
  if ( v3 == 0 )
  {
    LODWORD(v4) = a1;
    HIDWORD(v4) = HIDWORD(a1) % (unsigned int)a2;
    result = v4 % (unsigned int)a2;
    if ( v2 - 1 < 0 )
      return result;
    return -(__int64)result;
  }
  v6 = __PAIR64__(v3, a2);
  v7 = a1;
  do
  {
    v6 >>= 1;
    v7 >>= 1;
  }
  while ( HIDWORD(v6) != 0 );
  v8 = v7 / (unsigned int)v6;
  v9 = HIDWORD(a2) * v8;
  v11 = (unsigned int)a2 * (unsigned __int64)v8;
  v10 = __CFADD__(v9, HIDWORD(v11));
  HIDWORD(v11) += v9;
  if ( v10 || v11 > a1 )
    v11 -= a2;
  result = v11 - a1;
  if ( v2 - 1 < 0 )
    return -(__int64)result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000AD90
// Name: __alldiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _alldiv(unsigned __int64 a1, __int64 a2)
{
  int v2; // edi
  int v3; // eax
  unsigned __int64 v4; // rtt
  __int64 v5; // rax
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rax
  unsigned int v8; // esi
  unsigned __int64 v9; // rax

  v2 = 0;
  if ( (a1 & 0x8000000000000000uLL) != 0LL )
  {
    v2 = 1;
    HIDWORD(a1) = -HIDWORD(a1) - ((_DWORD)a1 != 0);
    LODWORD(a1) = -(int)a1;
  }
  v3 = HIDWORD(a2);
  if ( a2 < 0 )
  {
    ++v2;
    v3 = -HIDWORD(a2) - ((_DWORD)a2 != 0);
    HIDWORD(a2) = v3;
    LODWORD(a2) = -(int)a2;
  }
  if ( v3 != 0 )
  {
    v6 = __PAIR64__(v3, a2);
    v7 = a1;
    do
    {
      v6 >>= 1;
      v7 >>= 1;
    }
    while ( HIDWORD(v6) != 0 );
    v8 = v7 / (unsigned int)v6;
    v9 = v8 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v8, HIDWORD(v9)) || (HIDWORD(v9) = (a2 * (unsigned __int64)v8) >> 32, v9 > a1) )
      --v8;
    v5 = v8;
  }
  else
  {
    LODWORD(v4) = a1;
    HIDWORD(v4) = HIDWORD(a1) % (unsigned int)a2;
    LODWORD(v5) = v4 / (unsigned int)a2;
    HIDWORD(v5) = HIDWORD(a1) / (unsigned int)a2;
  }
  if ( v2 == 1 )
    return -v5;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1000AE3A
// Name: _atol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atol(const char *nptr)
{
  return strtol(nptr, endptr: nullptr, ibase: 10);
}

//------------------------------------------------------------------------------
// Address: 0x1000AE4B
// Name: vscan_fn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall vscan_fn@<eax>(
        char *string@<esi>,
        int (__cdecl *inputfn)(_iobuf *, const unsigned __int8 *, localeinfo_struct *, char *),
        const char *format,
        localeinfo_struct *plocinfo,
        char *arglist)
{
  unsigned int v5; // eax
  unsigned __int8 *v7; // [esp+0h] [ebp-28h]
  _iobuf str; // [esp+8h] [ebp-20h] BYREF

  strlen(buf: v7);
  if ( string != nullptr && format != nullptr )
  {
    str._flag = 73;
    str._base = string;
    str._ptr = string;
    str._cnt = 0x7FFFFFFF;
    if ( v5 <= 0x7FFFFFFF )
      str._cnt = v5;
    return inputfn(a1: &str, a2: (const unsigned __int8 *)format, a3: plocinfo, a4: arglist);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AEB3
// Name: _sscanf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sscanf(char *string, const char *format, ...)
{
  va_list arglist; // [esp+10h] [ebp+Ch] BYREF

  va_start(arglist, format);
  return vscan_fn(string, inputfn: _input_l, format, plocinfo: nullptr, arglist);
}

//------------------------------------------------------------------------------
// Address: 0x1000AED2
// Name: __atof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _atof_l(char *nptr, localeinfo_struct *plocinfo)
{
  unsigned __int8 *v2; // esi
  long double result; // st7
  int v4; // eax
  int v5; // eax
  _flt fltstruct; // [esp+8h] [ebp-28h] BYREF
  _LocaleUpdate _loc_update; // [esp+20h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v2 = (unsigned __int8 *)nptr;
  if ( nptr != nullptr )
  {
    while ( 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->mb_cur_max <= 1
         ? _loc_update.localeinfo.locinfo->pctype[*v2] & 8
         : _isctype_l(c: *v2, mask: 8, plocinfo: &_loc_update.localeinfo);
      if ( v4 == 0 )
        break;
      ++v2;
    }
    strlen(buf: v2);
    result = _fltin2(
               flt: &fltstruct,
               str: (const char *)v2,
               len_ignore: v5,
               scale_ignore: 0,
               radix_ignore: 0,
               _Locale: &_loc_update.localeinfo)->dval;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000AF7B
// Name: _atof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl atof(char *nptr)
{
  return _atof_l(nptr, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1000AF90
// Name: __chkstk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__usercall _chkstk@<eax>(unsigned int a1@<eax>, int a2@<ecx>)
{
  unsigned int v2; // ecx
  unsigned int i; // eax
  int v5; // [esp-4h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF

  v5 = a2;
  v2 = ~((unsigned int)((unsigned int)&retaddr - (unsigned __int64)a1) >> 32) & ((unsigned int)&retaddr - a1);
  for ( i = (unsigned int)&v5 & 0xFFFFF000; v2 < i; i -= 4096 )
    ;
  return retaddr;
}

//------------------------------------------------------------------------------
// Address: 0x1000AFC0
// Name: __alloca_probe_16
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__usercall _alloca_probe_16@<eax>(int a1@<eax>, int a2@<ecx>)
{
  char v2; // sp
  int v3; // ecx

  v3 = (v2 + 8 - (_BYTE)a1) & 0xF;
  return _chkstk(a1: __CFADD__(v3, a1) ? -1 : v3 + a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x1000B110
// Name: _atexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atexit(void (__cdecl *func)())
{
  return (_onexit((int (__cdecl *)())func) != nullptr) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1000B122
// Name: strtoxl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtoxl(
        localeinfo_struct *plocinfo,
        const char *nptr,
        const char **endptr,
        unsigned int ibase,
        int flags)
{
  threadlocaleinfostruct *locinfo; // ecx
  char v7; // bl
  const char *i; // edi
  int v9; // eax
  _BYTE *v10; // edi
  const unsigned __int16 *pctype; // esi
  unsigned int v12; // eax
  unsigned __int16 v13; // cx
  unsigned int v14; // ecx
  int v15; // ecx
  const char *v16; // edi
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-14h] BYREF
  unsigned int number; // [esp+18h] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr || ibase != 0 && ((int)ibase < 2 || (int)ibase > 36) )
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  locinfo = _loc_update.localeinfo.locinfo;
  v7 = *nptr;
  number = 0;
  for ( i = nptr + 1; ; ++i )
  {
    if ( locinfo->mb_cur_max <= 1 )
    {
      v9 = locinfo->pctype[(unsigned __int8)v7] & 8;
    }
    else
    {
      v9 = _isctype_l(c: (unsigned __int8)v7, mask: 8, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v9 == 0 )
      break;
    v7 = *i;
  }
  if ( v7 == 45 )
  {
    flags |= 2u;
  }
  else if ( v7 != 43 )
  {
    goto LABEL_20;
  }
  v7 = *i++;
LABEL_20:
  if ( ibase != 0 )
  {
    if ( ibase != 16 || v7 != 48 )
      goto LABEL_32;
  }
  else
  {
    if ( v7 != 48 )
    {
      ibase = 10;
      goto LABEL_32;
    }
    if ( *i != 120 && *i != 88 )
    {
      ibase = 8;
      goto LABEL_32;
    }
    ibase = 16;
  }
  if ( *i == 120 || *i == 88 )
  {
    v10 = i + 1;
    v7 = *v10;
    i = v10 + 1;
  }
LABEL_32:
  pctype = locinfo->pctype;
  v12 = 0xFFFFFFFF / ibase;
  while ( 1 )
  {
    v13 = pctype[(unsigned __int8)v7];
    if ( (v13 & 4) != 0 )
    {
      v14 = v7 - 48;
    }
    else
    {
      if ( (v13 & 0x103) == 0 )
        break;
      v15 = v7;
      if ( (unsigned __int8)(v7 - 97) <= 0x19u )
        v15 = v7 - 32;
      v14 = v15 - 55;
    }
    if ( v14 >= ibase )
      break;
    flags |= 8u;
    if ( number < v12 || number == v12 && v14 <= 0xFFFFFFFF % ibase )
    {
      number = v14 + ibase * number;
    }
    else
    {
      flags |= 4u;
      if ( endptr == nullptr )
        break;
    }
    v7 = *i++;
  }
  v16 = i - 1;
  if ( (flags & 8) != 0 )
  {
    if ( (flags & 4) != 0
      || (flags & 1) == 0 && ((flags & 2) != 0 && number > 0x80000000 || (flags & 2) == 0 && number > 0x7FFFFFFF) )
    {
      *_errno() = 34;
      if ( (flags & 1) != 0 )
        number = -1;
      else
        number = ((flags & 2) != 0) + 0x7FFFFFFF;
    }
  }
  else
  {
    if ( endptr != nullptr )
      v16 = nptr;
    number = 0;
  }
  if ( endptr != nullptr )
    *endptr = v16;
  if ( (flags & 2) != 0 )
    number = -number;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return number;
}

//------------------------------------------------------------------------------
// Address: 0x1000B34D
// Name: _strtol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtol(const char *nptr, char **endptr, unsigned int ibase)
{
  if ( __locale_changed != 0 )
    return strtoxl(plocinfo: nullptr, nptr, (const char **)endptr, ibase, flags: 0);
  else
    return strtoxl(plocinfo: &__initiallocalestructinfo, nptr, (const char **)endptr, ibase, flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000B380
// Name: _acos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl acos(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v1 = _mm_getcsr() & 0x1F80;
    v2 = v1 == 8064;
    if ( v1 == 8064 )
      v2 = (v4 & 0x7F) == 127;
    if ( v2 )
      JUMPOUT(0x10012548);
  }
  JUMPOUT(0x1000B40F);
}

//------------------------------------------------------------------------------
// Address: 0x1000B3C0
// Name: __CIacos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CIacos(__int64 a1)
{
  int v2; // eax
  bool v3; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CIacos;
  v2 = _mm_getcsr() & 0x1F80;
  v3 = v2 == 8064;
  if ( v2 == 8064 )
    v3 = (v4 & 0x7F) == 127;
  if ( v3 )
    _CIacos_pentium4(a1);
  else
__CIacos:
    _CIacos_default(a1, a2: HIDWORD(a1));
}

//------------------------------------------------------------------------------
// Address: 0x1000B3FB
// Name: __CIacos_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1000B4D0
// Name: _asin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl asin(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v1 = _mm_getcsr() & 0x1F80;
    v2 = v1 == 8064;
    if ( v1 == 8064 )
      v2 = (v4 & 0x7F) == 127;
    if ( v2 )
      JUMPOUT(0x10012E68);
  }
  JUMPOUT(0x1000B55F);
}

//------------------------------------------------------------------------------
// Address: 0x1000B510
// Name: __CIasin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CIasin(__int64 a1)
{
  int v2; // eax
  bool v3; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CIasin;
  v2 = _mm_getcsr() & 0x1F80;
  v3 = v2 == 8064;
  if ( v2 == 8064 )
    v3 = (v4 & 0x7F) == 127;
  if ( v3 )
    _CIasin_pentium4(a1);
  else
__CIasin:
    _CIasin_default(a1, a2: HIDWORD(a1));
}

//------------------------------------------------------------------------------
// Address: 0x1000B54B
// Name: __CIasin_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1000B620
// Name: _fmod
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl fmod(double X, double Y)
{
  double result; // st7

  _ctrandisp2(parm1: *(unsigned __int64 *)&X, parm2: *(unsigned __int64 *)&Y);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000B62A
// Name: __CIfmod
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __thiscall _CIfmod(int this)
{
  return _cintrindisp2(a1: this, a2: &_OP_FMODjmptab);
}

//------------------------------------------------------------------------------
// Address: 0x1000B634
// Name: fFMOD
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall fFMOD@<st0>(long double a1@<st1>, long double a2@<st0>)
{
  long double v4; // st7
  char v6; // c2

  v4 = a1;
  do
  {
    if ( _adjust_fdiv == 1 )
      _adj_fprem();
    else
      a2 = __FPREM__(a2, v4);
  }
  while ( v6 != 0 );
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x1000B660
// Name: _pow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl pow(double X, double Y)
{
  int v2; // eax
  bool v3; // zf
  char v5; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v2 = _mm_getcsr() & 0x1F80;
    v3 = v2 == 8064;
    if ( v2 == 8064 )
      v3 = (v5 & 0x7F) == 127;
    if ( v3 )
      JUMPOUT(0x100143F9);
  }
  JUMPOUT(0x1000B6F4);
}

//------------------------------------------------------------------------------
// Address: 0x1000B6A0
// Name: __CIpow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CIpow(__int64 a1, __int64 a2)
{
  int v4; // eax
  bool v5; // zf
  char v6; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CIpow;
  v4 = _mm_getcsr() & 0x1F80;
  v5 = v4 == 8064;
  if ( v4 == 8064 )
    v5 = (v6 & 0x7F) == 127;
  if ( v5 )
    _CIpow_pentium4(a1, a2);
  else
__CIpow:
    _CIpow_default(a1, a2: HIDWORD(a1), a3: a2, a4: HIDWORD(a2));
}

//------------------------------------------------------------------------------
// Address: 0x1000B6DB
// Name: __CIpow_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _CIpow_default()
{
  JUMPOUT(0x1000B6FD);
}

//------------------------------------------------------------------------------
// Address: 0x1000B8EA
// Name: ___libm_sse2_sin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall __libm_sse2_sin@<st0>(__m128i X@<xmm0>)
{
  double result; // st7

  if ( (__int16)((_mm_extract_epi16(X, 3) & 0x7FFF) - 12336) > 4293 && (_mm_extract_epi16(X, 3) & 0x7FF0) != 0x7FF0 )
    return sin(X: *(double *)X.m128i_i64);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000BAA2
// Name: ___libm_sse2_atan2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_sse2_atan2()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000BFB8
// Name: ___libm_sse2_pow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_sse2_pow()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000CA30
// Name: _floor
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl floor(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    return _floor_default(x: X);
  v1 = _mm_getcsr() & 0x1F80;
  v2 = v1 == 8064;
  if ( v1 == 8064 )
    v2 = (v4 & 0x7F) == 127;
  if ( v2 )
    return _floor_pentium4(X);
  else
    return _floor_default(x: X);
}

//------------------------------------------------------------------------------
// Address: 0x1000CA70
// Name: __floor_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _floor_pentium4(const __m128i a1)
{
  __m128i v1; // xmm7
  __m128d v2; // xmm0
  int v3; // eax
  __m128i v4; // xmm2
  __m128i v5; // xmm1
  __int64 v6; // xmm1_8
  __m128d v8; // xmm1
  __m128d v9; // xmm3
  double v10; // xmm0_8

  v1 = _mm_loadl_epi64(&a1);
  v2 = (__m128d)_mm_srli_epi64(v1, 0x34u);
  v3 = _mm_cvtsi128_si32((__m128i)v2);
  v4 = _mm_sub_epi32(*(__m128i *)&Bns, (__m128i)_mm_and_pd(v2, *(__m128d *)&S));
  v5 = _mm_srl_epi64(v1, v4);
  if ( (v3 & 0x800) != 0 )
  {
    v8 = (__m128d)_mm_sll_epi64(v5, v4);
    v9 = (__m128d)_mm_loadl_epi64(&a1);
    v10 = _mm_cmplt_pd(v9, v8).m128d_f64[0];
    if ( v3 < 3071 )
    {
      a1.m128i_i64[0] = (*(_QWORD *)&_mm_cmplt_pd(v9, *(__m128d *)&NegZero).m128d_f64[0] | NegZero) & NegOne;
      return *(double *)a1.m128i_i64;
    }
    else
    {
      if ( v3 > 3122 )
        return *(double *)a1.m128i_i64;
      *(double *)a1.m128i_i64 = v8.m128d_f64[0] - COERCE_DOUBLE(*(_QWORD *)&v10 & One);
      return *(double *)a1.m128i_i64;
    }
  }
  else
  {
    if ( v3 >= 1023 )
    {
      v6 = v5.m128i_i64[0] << v4.m128i_i8[0];
      if ( v3 <= 1074 )
      {
        a1.m128i_i64[0] = v6;
        return *(double *)&v6;
      }
      return *(double *)a1.m128i_i64;
    }
    return 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CB51
// Name: fastzero_I
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl fastzero_I(_OWORD *dst, unsigned int len)
{
  unsigned int v3; // ecx

  v3 = len >> 7;
  do
  {
    *dst = 0;
    dst[1] = 0;
    dst[2] = 0;
    dst[3] = 0;
    dst[4] = 0;
    dst[5] = 0;
    dst[6] = 0;
    dst[7] = 0;
    dst += 8;
    --v3;
  }
  while ( v3 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x1000CBA8
// Name: __VEC_memzero
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _VEC_memzero(int dst, int val, int len)
{
  char *result; // eax
  int v4; // edi
  int v5; // edx
  unsigned int v6; // [esp+4h] [ebp-Ch]

  result = (char *)dst;
  v4 = dst % 16;
  if ( dst % 16 != 0 )
  {
    memset((void *)dst, 0, 16 - v4);
    _VEC_memzero(dst: (void *)(16 - v4 + dst), val: 0, len: len - (16 - v4));
    return (char *)dst;
  }
  else
  {
    v5 = len & 0x7F;
    v6 = v5;
    if ( len != v5 )
    {
      fastzero_I((_OWORD *)dst, len: len - v5);
      result = (char *)dst;
      v5 = v6;
    }
    if ( v5 != 0 )
    {
      memset(&result[len - v5], 0, v6);
      return (char *)dst;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000CC37
// Name: __sse2_mathfcns_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _sse2_mathfcns_init()
{
  __use_sse2_mathfcns = 0;
  __use_sse2_mathfcns = _get_sse2_info();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000CC4B
// Name: __flsbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flsbuf(unsigned __int8 ch, int str)
{
  _iobuf *v2; // esi
  int flag; // eax
  bool v5; // zf
  char *base; // eax
  char *ptr; // edi
  signed int v8; // edi
  ioinfo *v9; // eax
  __int64 v10; // rax
  int written; // [esp+4h] [ebp-4h]

  v2 = (_iobuf *)str;
  str = _fileno(stream: (_iobuf *)str);
  flag = v2->_flag;
  if ( (flag & 0x82) == 0 )
  {
    *_errno() = 9;
LABEL_3:
    v2->_flag |= 0x20u;
    return -1;
  }
  if ( (flag & 0x40) != 0 )
  {
    *_errno() = 34;
    goto LABEL_3;
  }
  if ( (flag & 1) != 0 )
  {
    v2->_cnt = 0;
    if ( (flag & 0x10) == 0 )
    {
      v2->_flag = flag | 0x20;
      return -1;
    }
    v2->_ptr = v2->_base;
    v2->_flag = flag & 0xFFFFFFFE;
  }
  v5 = (v2->_flag & 0x10C) == 0;
  v2->_flag = v2->_flag & 0xFFFFFFED | 2;
  v2->_cnt = 0;
  written = 0;
  if ( v5 && (v2 != &__iob_func()[1] && v2 != &__iob_func()[2] || _isatty(fh: str) == 0) )
    _getbuf(str: v2);
  if ( (v2->_flag & 0x108) != 0 )
  {
    base = v2->_base;
    ptr = v2->_ptr;
    v2->_ptr = base + 1;
    v8 = ptr - base;
    v2->_cnt = v2->_bufsiz - 1;
    if ( v8 <= 0 )
    {
      if ( str == -1 || str == -2 )
        v9 = &__badioinfo;
      else
        v9 = &__pioinfo[str >> 5][str & 0x1F];
      if ( (v9->osfile & 0x20) != 0 )
      {
        v10 = _lseeki64(fh: str, pos: 0, mthd: 2);
        if ( (HIDWORD(v10) & (unsigned int)v10) == 0xFFFFFFFF )
          goto LABEL_27;
      }
    }
    else
    {
      written = _write(fh: str, buf: base, cnt: v8);
    }
    *v2->_base = ch;
  }
  else
  {
    v8 = 1;
    written = _write(fh: str, buf: &ch, cnt: 1u);
  }
  if ( written != v8 )
  {
LABEL_27:
    v2->_flag |= 0x20u;
    return -1;
  }
  return ch;
}

//------------------------------------------------------------------------------
// Address: 0x1000CDAB
// Name: write_char
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_char(int ch@<eax>, _iobuf *f@<ecx>, int *pnumwritten@<esi>)
{
  bool v3; // sf

  if ( ((f->_flag & 0x40) == 0 || f->_base != nullptr)
    && ((v3 = f->_cnt - 1 < 0, --f->_cnt, v3)
      ? (ch = _flsbuf(ch, str: (int)f))
      : (*f->_ptr = ch, ++f->_ptr, ch = (unsigned __int8)ch),
        ch == -1) )
  {
    *pnumwritten = -1;
  }
  else
  {
    ++*pnumwritten;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CDDE
// Name: write_multi_char
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_multi_char(int *pnumwritten@<eax>, char ch, int num, _iobuf *f)
{
  int *v4; // esi

  v4 = pnumwritten;
  do
  {
    if ( num <= 0 )
      break;
    LOBYTE(pnumwritten) = ch;
    --num;
    write_char(ch: (int)pnumwritten, f, pnumwritten: v4);
  }
  while ( *v4 != -1 );
}

//------------------------------------------------------------------------------
// Address: 0x1000CE02
// Name: write_string
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_string(char *string@<ecx>, _iobuf *f@<edi>, int *pnumwritten@<eax>, int len)
{
  int *v4; // esi
  int *v6; // eax

  v4 = pnumwritten;
  if ( (f->_flag & 0x40) == 0 || f->_base != nullptr )
  {
    while ( len > 0 )
    {
      LOBYTE(pnumwritten) = *string;
      --len;
      write_char(ch: (int)pnumwritten, f, pnumwritten: v4);
      ++string;
      if ( *v4 == -1 )
      {
        v6 = _errno();
        if ( *v6 != 42 )
          return;
        LOBYTE(v6) = 63;
        write_char(ch: (int)v6, f, pnumwritten: v4);
      }
    }
  }
  else
  {
    *pnumwritten += len;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CE4C
// Name: __output_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _output_l(_iobuf *stream, const char *format, localeinfo_struct *plocinfo, char *argptr)
{
  const char *v4; // ebx
  int *v5; // edi
  ioinfo **v7; // esi
  ioinfo *v8; // eax
  ioinfo **v9; // esi
  ioinfo *v10; // eax
  char v11; // dl
  STATE v12; // ecx
  bool v13; // zf
  char *v14; // ebx
  int v15; // eax
  char v16; // al
  int v17; // eax
  _output_l::__l2::<unnamed_tag> *p_buffer; // ebx
  int v19; // ecx
  char *v20; // edi
  char *v21; // eax
  char *v22; // edi
  __int16 *v23; // eax
  char *v24; // ecx
  int v25; // eax
  _WORD *v26; // esi
  __int64 v27; // rax
  int *v28; // edi
  int v29; // esi
  char *v30; // eax
  int v31; // eax
  char *v32; // edi
  void (__cdecl *v33)(_CRT_DOUBLE *, _output_l::__l2::<unnamed_tag> *, int, int, int, int, _LocaleUpdate *); // eax
  int v34; // edi
  void (__cdecl *v35)(_output_l::__l2::<unnamed_tag> *, _LocaleUpdate *); // eax
  void (__cdecl *v36)(_output_l::__l2::<unnamed_tag> *, _LocaleUpdate *); // eax
  unsigned int v37; // ebx
  unsigned int v38; // edi
  char *j; // esi
  int v40; // eax
  unsigned __int64 v41; // rcx
  int v42; // ecx
  char *v43; // eax
  char *v44; // esi
  char *i; // eax
  int v46; // ebx
  _iobuf *v47; // edi
  char *v48; // esi
  wchar_t v49; // ax
  char v50; // al
  int v51; // [esp-14h] [ebp-A0h]
  int v52; // [esp-10h] [ebp-9Ch]
  unsigned __int64 v53; // [esp-10h] [ebp-9Ch]
  int v54; // [esp-Ch] [ebp-98h]
  int v55; // [esp-8h] [ebp-94h]
  _CRT_DOUBLE tmp; // [esp+Ch] [ebp-80h] BYREF
  int capexp; // [esp+14h] [ebp-78h]
  STATE state; // [esp+18h] [ebp-74h]
  int retval; // [esp+1Ch] [ebp-70h] BYREF
  int count; // [esp+24h] [ebp-68h]
  _LocaleUpdate _loc_update; // [esp+28h] [ebp-64h] BYREF
  char *heapbuf; // [esp+38h] [ebp-54h]
  int no_output; // [esp+3Ch] [ebp-50h]
  int hexadd; // [esp+40h] [ebp-4Ch]
  char *v65; // [esp+44h] [ebp-48h]
  int bufferiswide; // [esp+48h] [ebp-44h]
  int fldwidth; // [esp+4Ch] [ebp-40h]
  int prefixlen; // [esp+50h] [ebp-3Ch]
  char prefix[4]; // [esp+54h] [ebp-38h] BYREF
  int charsout; // [esp+58h] [ebp-34h] BYREF
  _iobuf *f; // [esp+5Ch] [ebp-30h]
  char *v72; // [esp+60h] [ebp-2Ch]
  int radix; // [esp+64h] [ebp-28h] BYREF
  char *string; // [esp+68h] [ebp-24h]
  int precision; // [esp+6Ch] [ebp-20h]
  char v76; // [esp+73h] [ebp-19h]
  int flags; // [esp+74h] [ebp-18h]
  _output_l::__l2::<unnamed_tag> buffer; // [esp+78h] [ebp-14h] BYREF
  char L_buffer[8]; // [esp+278h] [ebp+1ECh] BYREF

  v4 = format;
  v5 = (int *)argptr;
  f = stream;
  v72 = argptr;
  hexadd = 0;
  flags = 0;
  fldwidth = 0;
  precision = 0;
  prefixlen = 0;
  no_output = 0;
  bufferiswide = 0;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( f == nullptr
    || (f->_flag & 0x40) == 0
    && (_fileno(stream: f) == -1 || _fileno(stream: f) == -2
      ? (v8 = &__badioinfo)
      : (v7 = &__pioinfo[_fileno(stream: f) >> 5], v8 = &(*v7)[_fileno(stream: f) & 0x1F]),
        (*((_BYTE *)v8 + 36) & 0x7F) != 0
     || (_fileno(stream: f) == -1 || _fileno(stream: f) == -2
       ? (v10 = &__badioinfo)
       : (v9 = &__pioinfo[_fileno(stream: f) >> 5], v10 = &(*v9)[_fileno(stream: f) & 0x1F]),
         *((char *)v10 + 36) < 0))
    || format == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
    goto LABEL_3;
  }
  v11 = *format;
  v12 = ST_NORMAL;
  v13 = *format == 0;
  charsout = 0;
  radix = 0;
  heapbuf = nullptr;
  v76 = v11;
  if ( v13 )
  {
LABEL_222:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return charsout;
  }
  while ( 1 )
  {
    v14 = (char *)(v4 + 1);
    v65 = v14;
    if ( charsout < 0 )
      goto LABEL_222;
    if ( (unsigned __int8)(v11 - 32) > 0x58u )
      v15 = 0;
    else
      v15 = *((_BYTE *)&S + v11 + 8) & 0xF;
    state = __lookuptable[8 * v15 + v12] >> 4;
    switch ( state )
    {
      case ST_NORMAL:
        goto NORMAL_STATE;
      case ST_PERCENT:
        precision = -1;
        capexp = 0;
        no_output = 0;
        fldwidth = 0;
        prefixlen = 0;
        flags = 0;
        bufferiswide = 0;
        goto LABEL_219;
      case ST_FLAG:
        switch ( v11 )
        {
          case ' ':
            flags |= 2u;
            break;
          case '#':
            flags |= 0x80u;
            break;
          case '+':
            flags |= 1u;
            break;
          case '-':
            flags |= 4u;
            break;
          case '0':
            flags |= 8u;
            break;
          default:
            break;
        }
        goto LABEL_219;
      case ST_WIDTH:
        if ( v11 == 42 )
        {
          v72 = (char *)(v5 + 1);
          fldwidth = *v5;
          if ( fldwidth < 0 )
          {
            flags |= 4u;
            fldwidth = -fldwidth;
          }
        }
        else
        {
          fldwidth = 10 * fldwidth + v11 - 48;
        }
        goto LABEL_219;
      case ST_DOT:
        precision = 0;
        goto LABEL_219;
      case ST_PRECIS:
        if ( v11 == 42 )
        {
          v72 = (char *)(v5 + 1);
          precision = *v5;
          if ( precision < 0 )
            precision = -1;
        }
        else
        {
          precision = 10 * precision + v11 - 48;
        }
        goto LABEL_219;
      case ST_SIZE:
        if ( v11 != 73 )
        {
          switch ( v11 )
          {
            case 'h':
              flags |= 0x20u;
              break;
            case 'l':
              if ( *v14 == 108 )
              {
                flags |= 0x1000u;
                v65 = v14 + 1;
              }
              else
              {
                flags |= 0x10u;
              }
              break;
            case 'w':
              flags |= 0x800u;
              break;
            default:
              break;
          }
          goto LABEL_219;
        }
        v16 = *v14;
        if ( *v14 == 54 && v14[1] == 52 )
        {
          flags |= 0x8000u;
          v65 = v14 + 2;
          goto LABEL_219;
        }
        if ( v16 == 51 && v14[1] == 50 )
        {
          flags &= ~0x8000u;
          v65 = v14 + 2;
          goto LABEL_219;
        }
        if ( v16 == 100 || v16 == 105 || v16 == 111 || v16 == 117 || v16 == 120 || v16 == 88 )
          goto LABEL_219;
        state = ST_NORMAL;
NORMAL_STATE:
        bufferiswide = 0;
        v17 = _isleadbyte_l(c: (unsigned __int8)v11, plocinfo: &_loc_update.localeinfo);
        v13 = v17 == 0;
        LOBYTE(v17) = v76;
        if ( v13 || (write_char(ch: v17, f, pnumwritten: &charsout), LOBYTE(v17) = *v14, v65 = v14 + 1, (_BYTE)v17 != 0) )
        {
          write_char(ch: v17, f, pnumwritten: &charsout);
          goto LABEL_219;
        }
LABEL_221:
        *_errno() = 22;
        _invalid_parameter(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
LABEL_3:
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
        return -1;
      case ST_TYPE:
        if ( v11 <= 100 )
        {
          if ( v11 == 100 )
          {
LABEL_119:
            flags |= 0x40u;
            goto LABEL_120;
          }
          if ( v11 > 83 )
          {
            if ( v11 == 88 )
              goto LABEL_141;
            if ( v11 == 90 )
            {
              v23 = (__int16 *)*v5;
              v72 = (char *)(v5 + 1);
              if ( v23 != nullptr && (v24 = *((char **)v23 + 1)) != nullptr )
              {
                v25 = *v23;
                string = v24;
                if ( (flags & 0x800) != 0 )
                {
                  v25 /= 2;
                  bufferiswide = 1;
                }
                else
                {
                  bufferiswide = 0;
                }
              }
              else
              {
                string = __nullstring;
                strlen(buf: (unsigned __int8 *)__nullstring);
              }
              goto LABEL_190;
            }
            if ( v11 != 97 )
            {
              if ( v11 != 99 )
                goto LABEL_191;
              goto LABEL_94;
            }
          }
          else
          {
            if ( v11 == 83 )
            {
              if ( (flags & 0x830) == 0 )
                flags |= 0x800u;
              goto LABEL_84;
            }
            if ( v11 != 65 )
            {
              if ( v11 != 67 )
              {
                if ( v11 != 69 && v11 != 71 )
                  goto LABEL_191;
                goto LABEL_77;
              }
              if ( (flags & 0x830) == 0 )
                flags |= 0x800u;
LABEL_94:
              v22 = (char *)(v5 + 1);
              v72 = v22;
              if ( (flags & 0x810) != 0 )
              {
                if ( wctomb_s(pRetValue: &radix, dst: buffer.sz, sizeInBytes: 0x200u, wchar: *((_WORD *)v22 - 2)) != 0 )
                  no_output = 1;
              }
              else
              {
                buffer.sz[0] = *(v22 - 4);
                radix = 1;
              }
              string = (char *)&buffer;
              goto LABEL_191;
            }
LABEL_77:
            v11 += 32;
            capexp = 1;
            v76 = v11;
          }
LABEL_78:
          flags |= 0x40u;
          p_buffer = &buffer;
          string = (char *)&buffer;
          count = 512;
          if ( precision >= 0 )
          {
            if ( precision != 0 )
            {
              if ( precision > 512 )
                precision = 512;
              if ( precision > 163 )
              {
                v29 = precision + 349;
                v30 = (char *)operator new(nSize: precision + 349);
                v11 = v76;
                heapbuf = v30;
                if ( v30 != nullptr )
                {
                  string = v30;
                  count = v29;
                  p_buffer = (_output_l::__l2::<unnamed_tag> *)v30;
                }
                else
                {
                  precision = 163;
                }
              }
            }
            else
            {
              precision = v11 == 103;
            }
          }
          else
          {
            precision = 6;
          }
          v31 = *v5;
          v32 = (char *)(v5 + 2);
          LODWORD(tmp.x) = v31;
          HIDWORD(tmp.x) = *((_DWORD *)v32 - 1);
          v55 = capexp;
          v54 = precision;
          v72 = v32;
          v52 = v11;
          v51 = count;
          v33 = (void (__cdecl *)(_CRT_DOUBLE *, _output_l::__l2::<unnamed_tag> *, int, int, int, int, _LocaleUpdate *))_decode_pointer(codedptr: codedptr);
          v33(a1: &tmp, a2: p_buffer, a3: v51, a4: v52, a5: v54, a6: v55, a7: &_loc_update);
          v34 = flags & 0x80;
          if ( (flags & 0x80) != 0 && precision == 0 )
          {
            v35 = (void (__cdecl *)(_output_l::__l2::<unnamed_tag> *, _LocaleUpdate *))_decode_pointer(codedptr: off_10037F9C);
            v35(a1: p_buffer, a2: &_loc_update);
          }
          if ( v76 == 103 && v34 == 0 )
          {
            v36 = (void (__cdecl *)(_output_l::__l2::<unnamed_tag> *, _LocaleUpdate *))_decode_pointer(codedptr: off_10037F98);
            v36(a1: p_buffer, a2: &_loc_update);
          }
          if ( p_buffer->sz[0] == 45 )
          {
            flags |= 0x100u;
            p_buffer = (_output_l::__l2::<unnamed_tag> *)((char *)p_buffer + 1);
            string = (char *)p_buffer;
          }
          strlen(buf: (unsigned __int8 *)p_buffer);
          goto LABEL_190;
        }
        if ( v11 > 112 )
        {
          if ( v11 != 115 )
          {
            if ( v11 != 117 )
            {
              if ( v11 != 120 )
                goto LABEL_191;
              hexadd = 39;
              goto COMMON_HEX;
            }
LABEL_120:
            radix = 10;
            goto COMMON_INT;
          }
LABEL_84:
          v19 = precision;
          if ( precision == -1 )
            v19 = 0x7FFFFFFF;
          v72 = (char *)(v5 + 1);
          v20 = (char *)*v5;
          string = v20;
          if ( (flags & 0x810) != 0 )
          {
            if ( v20 == nullptr )
              string = (char *)__wnullstring;
            v21 = string;
            bufferiswide = 1;
            while ( v19 != 0 )
            {
              --v19;
              if ( *(_WORD *)v21 == 0 )
                break;
              v21 += 2;
            }
            v25 = (v21 - string) >> 1;
          }
          else
          {
            if ( v20 == nullptr )
              string = __nullstring;
            for ( i = string; v19 != 0; ++i )
            {
              --v19;
              if ( *i == 0 )
                break;
            }
            v25 = i - string;
          }
LABEL_190:
          radix = v25;
          goto LABEL_191;
        }
        if ( v11 == 112 )
        {
          precision = 8;
LABEL_141:
          hexadd = 7;
COMMON_HEX:
          radix = 16;
          if ( (flags & 0x80u) != 0 )
          {
            prefix[0] = 48;
            prefix[1] = hexadd + 81;
            prefixlen = 2;
          }
          goto COMMON_INT;
        }
        if ( v11 < 101 )
          goto LABEL_191;
        if ( v11 <= 103 )
          goto LABEL_78;
        if ( v11 == 105 )
          goto LABEL_119;
        if ( v11 != 110 )
        {
          if ( v11 != 111 )
            goto LABEL_191;
          radix = 8;
          if ( (flags & 0x80u) != 0 )
            flags |= 0x200u;
COMMON_INT:
          if ( (flags & 0x8000u) != 0 || (flags & 0x1000) != 0 )
          {
            v27 = *(_QWORD *)v5;
            v28 = v5 + 2;
          }
          else
          {
            v28 = v5 + 1;
            if ( (flags & 0x20) != 0 )
            {
              v72 = (char *)v28;
              if ( (flags & 0x40) != 0 )
                LODWORD(v27) = *((__int16 *)v28 - 2);
              else
                LODWORD(v27) = *((unsigned __int16 *)v28 - 2);
              v27 = (int)v27;
LABEL_158:
              if ( (flags & 0x40) != 0 && v27 < 0 )
              {
                v27 = -v27;
                flags |= 0x100u;
              }
              v37 = HIDWORD(v27);
              v38 = v27;
              if ( (flags & 0x9000) == 0 )
                v37 = 0;
              if ( precision >= 0 )
              {
                flags &= ~8u;
                if ( precision > 512 )
                  precision = 512;
              }
              else
              {
                precision = 1;
              }
              if ( (v37 | (unsigned int)v27) == 0 )
                prefixlen = 0;
              for ( j = &buffer.sz[511]; ; --j )
              {
                v40 = precision--;
                if ( v40 <= 0 && (v37 | v38) == 0 )
                  break;
                v53 = __PAIR64__(v37, v38);
                v41 = __PAIR64__(v37, v38) % radix;
                v42 = v41 + 48;
                count = HIDWORD(v41);
                v37 = (v53 / radix) >> 32;
                v38 = v53 / radix;
                if ( v42 > 57 )
                  LOBYTE(v42) = hexadd + v42;
                *j = v42;
              }
              v43 = (char *)(&buffer.sz[511] - j);
              v44 = j + 1;
              radix = (int)v43;
              string = v44;
              if ( (flags & 0x200) != 0 && (v43 == nullptr || *v44 != 48) )
              {
                *--string = 48;
                v25 = (int)(v43 + 1);
                goto LABEL_190;
              }
LABEL_191:
              if ( no_output != 0 )
                goto LABEL_217;
              if ( (flags & 0x40) != 0 )
              {
                if ( (flags & 0x100) != 0 )
                {
                  prefix[0] = 45;
                  goto LABEL_199;
                }
                if ( (flags & 1) != 0 )
                {
                  prefix[0] = 43;
                  goto LABEL_199;
                }
                if ( (flags & 2) != 0 )
                {
                  prefix[0] = 32;
LABEL_199:
                  prefixlen = 1;
                }
              }
              v46 = fldwidth - radix - prefixlen;
              if ( (flags & 0xC) == 0 )
                write_multi_char(pnumwritten: &charsout, ch: 32, num: fldwidth - radix - prefixlen, f);
              v47 = f;
              write_string(string: prefix, f, pnumwritten: &charsout, len: prefixlen);
              if ( (flags & 8) != 0 && (flags & 4) == 0 )
                write_multi_char(pnumwritten: &charsout, ch: 48, num: v46, f: v47);
              if ( bufferiswide != 0 && radix > 0 )
              {
                v48 = string;
                count = radix;
                while ( 1 )
                {
                  v49 = *(_WORD *)v48;
                  --count;
                  v48 += 2;
                  if ( wctomb_s(pRetValue: &retval, dst: L_buffer, sizeInBytes: 6u, wchar: v49) != 0 || retval == 0 )
                    break;
                  write_string(string: L_buffer, f: v47, pnumwritten: &charsout, len: retval);
                  if ( count == 0 )
                    goto LABEL_214;
                }
                charsout = -1;
              }
              else
              {
                write_string(string, f: v47, pnumwritten: &charsout, len: radix);
              }
LABEL_214:
              if ( charsout >= 0 && (flags & 4) != 0 )
                write_multi_char(pnumwritten: &charsout, ch: 32, num: v46, f: v47);
              goto LABEL_217;
            }
            LODWORD(v27) = *(v28 - 1);
            if ( (flags & 0x40) != 0 )
              v27 = (int)v27;
            else
              HIDWORD(v27) = 0;
          }
          v72 = (char *)v28;
          goto LABEL_158;
        }
        v26 = (_WORD *)*v5;
        v72 = (char *)(v5 + 1);
        if ( _get_printf_count_output() == 0 )
          goto LABEL_221;
        if ( (flags & 0x20) != 0 )
          *v26 = charsout;
        else
          *(_DWORD *)v26 = charsout;
        no_output = 1;
LABEL_217:
        if ( heapbuf != nullptr )
        {
          free(pMem: heapbuf);
          heapbuf = nullptr;
        }
LABEL_219:
        v4 = v65;
        v50 = *v65;
        v76 = *v65;
        if ( v76 == 0 )
          goto LABEL_222;
        v12 = state;
        v5 = (int *)v72;
        v11 = v50;
        break;
      default:
        goto LABEL_219;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D7E0
// Name: __initp_misc_invarg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_invarg(
        void (__cdecl *enull)(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, unsigned int))
{
  __pInvalidArgHandler = enull;
}

//------------------------------------------------------------------------------
// Address: 0x1000D7EA
// Name: __invoke_watson
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __noreturn _invoke_watson(
        unsigned int a1@<eax>,
        unsigned int a2@<edx>,
        unsigned int a3@<ecx>,
        unsigned int a4@<ebx>,
        unsigned int a5@<edi>,
        unsigned int a6@<esi>)
{
  unsigned int v6; // kr00_4
  BOOL v7; // esi
  HANDLE CurrentProcess; // eax
  _EXCEPTION_RECORD ExceptionRecord; // [esp+4h] [ebp-80h] BYREF
  _EXCEPTION_POINTERS ExceptionPointers; // [esp+54h] [ebp-30h] BYREF
  _CONTEXT ContextRecord; // [esp+5Ch] [ebp-28h] BYREF
  unsigned int savedregs; // [esp+32Ch] [ebp+2A8h]
  void *retaddr; // [esp+330h] [ebp+2ACh] BYREF

  ContextRecord.Eax = a1;
  ContextRecord.Ecx = a3;
  ContextRecord.Edx = a2;
  ContextRecord.Ebx = a4;
  ContextRecord.Esi = a6;
  ContextRecord.Edi = a5;
  LOWORD(ContextRecord.SegSs) = __SS__;
  LOWORD(ContextRecord.SegCs) = __CS__;
  LOWORD(ContextRecord.SegDs) = __DS__;
  LOWORD(ContextRecord.SegEs) = __ES__;
  LOWORD(ContextRecord.SegFs) = __FS__;
  LOWORD(ContextRecord.SegGs) = __GS__;
  v6 = __readeflags();
  ContextRecord.EFlags = v6;
  ContextRecord.Esp = (unsigned int)&retaddr;
  ContextRecord.ContextFlags = 65537;
  ContextRecord.Eip = (unsigned int)retaddr;
  ContextRecord.Ebp = savedregs;
  memset(dst: (int)&ExceptionRecord, value: nullptr, count: sizeof(ExceptionRecord));
  ExceptionPointers.ExceptionRecord = &ExceptionRecord;
  ExceptionRecord.ExceptionCode = -1073741811;
  ExceptionRecord.ExceptionAddress = retaddr;
  ExceptionPointers.ContextRecord = &ContextRecord;
  v7 = IsDebuggerPresent();
  SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: nullptr);
  if ( UnhandledExceptionFilter(ExceptionInfo: &ExceptionPointers) == 0 && !v7 )
    _crt_debugger_hook(_Reserved: 2);
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 0xC000000D);
}

//------------------------------------------------------------------------------
// Address: 0x1000D8E6
// Name: __invalid_parameter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _invalid_parameter(unsigned int a1@<ebx>, unsigned int a2@<edi>, unsigned int a3@<esi>)
{
  void (*v3)(void); // eax
  unsigned int v4; // eax
  unsigned int v5; // edx
  unsigned int v6; // [esp-4h] [ebp-4h]

  v3 = (void (*)(void))_decode_pointer(codedptr: __pInvalidArgHandler);
  if ( v3 == nullptr )
  {
    _crt_debugger_hook(_Reserved: 2);
    _invoke_watson(a1: v4, a2: v5, a3: v6, a4: a1, a5: a2, a6: a3);
  }
  v3();
}

//------------------------------------------------------------------------------
// Address: 0x1000D90A
// Name: __get_errno_from_oserr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_errno_from_oserr(unsigned int oserrno)
{
  unsigned int i; // ecx

  for ( i = 0; i < 0x2D; ++i )
  {
    if ( oserrno == errtable[i].oscode )
      return errtable[i].errnocode;
  }
  if ( oserrno - 19 > 0x11 )
    return oserrno - 188 > 0xE ? 22 : 8;
  else
    return 13;
}

//------------------------------------------------------------------------------
// Address: 0x1000D945
// Name: __errno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl _errno()
{
  _tiddata *v0; // eax

  v0 = _getptd_noexit();
  if ( v0 != nullptr )
    return &v0->_terrno;
  else
    return &ErrnoNoMem;
}

//------------------------------------------------------------------------------
// Address: 0x1000D958
// Name: ___doserrno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int *__cdecl __doserrno()
{
  _tiddata *v0; // eax

  v0 = _getptd_noexit();
  if ( v0 != nullptr )
    return &v0->_tdoserrno;
  else
    return &DoserrorNoMem;
}

//------------------------------------------------------------------------------
// Address: 0x1000D96B
// Name: __dosmaperr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _dosmaperr(unsigned int oserrno)
{
  int errno_from_oserr; // esi

  *__doserrno() = oserrno;
  errno_from_oserr = _get_errno_from_oserr(oserrno);
  *_errno() = errno_from_oserr;
}

//------------------------------------------------------------------------------
// Address: 0x1000D989
// Name: fastcopy_I
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl fastcopy_I(__m128i *dst, const __m128i *src, unsigned int len)
{
  unsigned int v5; // ecx
  __m128i si128; // xmm1
  __m128i v7; // xmm2
  __m128i v8; // xmm3
  __m128i v9; // xmm5
  __m128i v10; // xmm6
  __m128i v11; // xmm7

  v5 = len >> 7;
  do
  {
    si128 = _mm_load_si128(src + 1);
    v7 = _mm_load_si128(src + 2);
    v8 = _mm_load_si128(src + 3);
    *dst = _mm_load_si128(src);
    dst[1] = si128;
    dst[2] = v7;
    dst[3] = v8;
    v9 = _mm_load_si128(src + 5);
    v10 = _mm_load_si128(src + 6);
    v11 = _mm_load_si128(src + 7);
    dst[4] = _mm_load_si128(src + 4);
    dst[5] = v9;
    dst[6] = v10;
    dst[7] = v11;
    src += 8;
    dst += 8;
    --v5;
  }
  while ( v5 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x1000DA10
// Name: __VEC_memcpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__m128i *__cdecl _VEC_memcpy(__m128i *dst, const __m128i *src, unsigned int len)
{
  int v3; // ecx
  __m128i *result; // eax
  int v5; // ecx
  unsigned int v6; // [esp+4h] [ebp-18h]

  v3 = (int)src % 16;
  result = dst;
  if ( (((int)dst % 16) | ((int)src % 16)) != 0 )
  {
    if ( v3 == (int)dst % 16 )
    {
      qmemcpy(dst, src, 16 - v3);
      _VEC_memcpy(dst: &dst->m128i_i8[16 - v3], src: &src->m128i_i8[16 - v3], len: len - (16 - v3));
    }
    else
    {
      qmemcpy(dst, src, len);
    }
    return dst;
  }
  else
  {
    v5 = len & 0x7F;
    v6 = v5;
    if ( len != v5 )
    {
      fastcopy_I(dst, src, len: len - v5);
      result = dst;
      v5 = v6;
    }
    if ( v5 != 0 )
    {
      qmemcpy(&result->m128i_i8[len - v5], &src->m128i_i8[len - v5], v6);
      return dst;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000DAF3
// Name: __forcdecpt_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _forcdecpt_l(char *buffer, localeinfo_struct *_Locale)
{
  char *v2; // esi
  bool i; // zf
  char v4; // al
  char *v5; // esi
  char v6; // cl
  char v7; // cl
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo: _Locale);
  v2 = buffer;
  for ( i = tolower(c: *buffer) == 101; !i; i = isdigit(c: (unsigned __int8)*v2) == 0 )
    ++v2;
  if ( tolower(c: *v2) == 120 )
    v2 += 2;
  v4 = *v2;
  *v2 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
  v5 = v2 + 1;
  do
  {
    v6 = *v5;
    *v5 = v4;
    v4 = v6;
    v7 = *v5++;
  }
  while ( v7 != 0 );
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x1000DB64
// Name: __cropzeros_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cropzeros_l(char *buf, localeinfo_struct *_Locale)
{
  char *v2; // eax
  char i; // cl
  char v4; // cl
  char *v5; // eax
  char v6; // cl
  char *v7; // edx
  char v8; // cl
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo: _Locale);
  v2 = buf;
  for ( i = *buf; *v2 != 0; i = *++v2 )
  {
    if ( i == *_loc_update.localeinfo.locinfo->lconv->decimal_point )
      break;
  }
  v4 = *v2;
  v5 = v2 + 1;
  if ( v4 != 0 )
  {
    while ( 1 )
    {
      v6 = *v5;
      if ( *v5 == 0 || v6 == 101 || v6 == 69 )
        break;
      ++v5;
    }
    v7 = v5;
    do
      --v5;
    while ( *v5 == 48 );
    if ( *v5 == *_loc_update.localeinfo.locinfo->lconv->decimal_point )
      --v5;
    do
    {
      v8 = *v7;
      ++v5;
      ++v7;
      *v5 = v8;
    }
    while ( v8 != 0 );
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x1000DBE4
// Name: __positive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _positive(long double *arg)
{
  return *arg >= 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1000DBFA
// Name: __fassign_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _fassign_l(_CRT_FLOAT flag, char *argument, char *number, localeinfo_struct *plocinfo)
{
  _CRT_DOUBLE doubletemp; // [esp+0h] [ebp-8h] BYREF

  if ( LODWORD(flag.f) != 0 )
  {
    _atodbl_l(d: &doubletemp, str: number, plocinfo);
    *(_CRT_DOUBLE *)argument = doubletemp;
  }
  else
  {
    _atoflt_l(d: &flag, str: number, plocinfo);
    *(_CRT_FLOAT *)argument = flag;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DC3A
// Name: __fassign
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _fassign(int flag, char *argument, char *number)
{
  _fassign_l((_CRT_FLOAT)flag, argument, number, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1000DC51
// Name: _shift
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall shift(char *s@<eax>, int dist@<edi>)
{
  int v3; // eax

  if ( dist != 0 )
  {
    strlen(buf: (unsigned __int8 *)s);
    memmove(dst: (unsigned __int8 *)&s[dist], src: (unsigned __int8 *)s, count: v3 + 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DC6E
// Name: __forcdecpt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _forcdecpt(char *buffer)
{
  _forcdecpt_l(buffer, _Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1000DC7C
// Name: __cropzeros
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cropzeros(char *buf)
{
  _cropzeros_l(buf, _Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1000DC8A
// Name: _cftoe2_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall cftoe2_l@<eax>(
        char *buf@<eax>,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        _strflt *pflt,
        char g_fmt,
        localeinfo_struct *plocinfo)
{
  int *v8; // eax
  int v10; // eax
  char *v11; // esi
  char *v12; // esi
  unsigned int v13; // ebx
  unsigned int v14; // eax
  unsigned int v15; // edx
  unsigned int v16; // ecx
  unsigned __int8 *v17; // ecx
  _BYTE *v18; // esi
  int v19; // eax
  _BYTE *v20; // esi
  _BYTE *v21; // esi
  unsigned int v22; // [esp-4h] [ebp-20h]
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( buf == nullptr || sizeInBytes == 0 )
  {
    v8 = _errno();
    v22 = 22;
LABEL_3:
    *v8 = v22;
    _invalid_parameter(a1: (unsigned int)buf, a2: v22, a3: 0);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return v22;
  }
  if ( ndec <= 0 )
    v10 = 0;
  else
    v10 = ndec;
  if ( sizeInBytes <= v10 + 9 )
  {
    v8 = _errno();
    v22 = 34;
    goto LABEL_3;
  }
  if ( g_fmt != 0 )
    shift(s: &buf[pflt->sign == 45], dist: ndec > 0);
  v11 = buf;
  if ( pflt->sign == 45 )
  {
    *buf = 45;
    v11 = buf + 1;
  }
  if ( ndec > 0 )
  {
    *v11 = v11[1];
    *++v11 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
  }
  v12 = &v11[ndec + (g_fmt == 0)];
  if ( sizeInBytes == -1 )
    v13 = -1;
  else
    v13 = sizeInBytes + buf - v12;
  v14 = strcpy_s(_Dst: v12, _SizeInBytes: v13, _Src: "e+000");
  if ( v14 != 0 )
    _invoke_watson(a1: v14, a2: v15, a3: v16, a4: 0, a5: (unsigned int)pflt, a6: (unsigned int)v12);
  v17 = (unsigned __int8 *)(v12 + 2);
  if ( caps != 0 )
    *v12 = 69;
  v18 = v12 + 1;
  if ( *pflt->mantissa != 48 )
  {
    v19 = pflt->decpt - 1;
    if ( v19 < 0 )
    {
      v19 = 1 - pflt->decpt;
      *v18 = 45;
    }
    v20 = v18 + 1;
    if ( v19 >= 100 )
    {
      *v20 += v19 / 100;
      v19 %= 100;
    }
    v21 = v20 + 1;
    if ( v19 >= 10 )
    {
      *v21 += v19 / 10;
      LOBYTE(v19) = v19 % 10;
    }
    v21[1] += v19;
  }
  if ( (_outputformat & 1) != 0 && *v17 == 48 )
    memmove(dst: v17, src: v17 + 1, count: 3u);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000DDF7
// Name: __cftoe_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _cftoe_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  unsigned int result; // eax
  unsigned int v7; // eax
  _strflt retstrflt; // [esp+Ch] [ebp-2Ch] BYREF
  char resstr[24]; // [esp+1Ch] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && sizeInBytes != 0 )
  {
    if ( sizeInBytes == -1 )
      v7 = -1;
    else
      v7 = sizeInBytes - (retstrflt.sign == 45) - (ndec > 0);
    result = _fptostr(
               buf: &buf[(retstrflt.sign == 45) + (ndec > 0)],
               sizeInBytes: v7,
               digits: ndec + 1,
               pflt: &retstrflt);
    if ( result != 0 )
      *buf = 0;
    else
      return cftoe2_l(buf, sizeInBytes, ndec, caps, pflt: &retstrflt, g_fmt: 0, plocinfo);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: (unsigned int)buf, a3: 0x16u);
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000DEC5
// Name: __cftoe
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _cftoe(_CRT_DOUBLE *pvalue, char *buf, unsigned int sizeInBytes, int ndec, int caps)
{
  return _cftoe_l(pvalue, buf, sizeInBytes, ndec, caps, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1000DEE3
// Name: __cftoa_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _cftoa_l@<eax>(
        unsigned int a1@<ebx>,
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  char *v7; // esi
  int *v8; // eax
  unsigned int result; // eax
  unsigned int v10; // eax
  bool v11; // zf
  _BYTE *v12; // esi
  _BYTE *v13; // eax
  _BYTE *v14; // esi
  _BYTE *v15; // esi
  char *v16; // esi
  char *v17; // eax
  char *v18; // esi
  int x_low; // eax
  unsigned __int16 v20; // ax
  unsigned int v21; // ecx
  char *i; // eax
  _BYTE *v23; // esi
  __int64 v24; // rax
  __int64 v25; // rcx
  _BYTE *v26; // esi
  _BYTE *v27; // edi
  __int64 v28; // rax
  __int64 v29; // rcx
  __int64 v30; // rax
  __int64 v31; // rcx
  __int64 v32; // rcx
  __int64 v33; // [esp-Ch] [ebp-38h]
  unsigned int v34; // [esp-4h] [ebp-30h]
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-24h] BYREF
  __int64 exponent; // [esp+18h] [ebp-14h]
  unsigned __int64 mask; // [esp+20h] [ebp-Ch]
  int maskpos; // [esp+28h] [ebp-4h]
  char *pos; // [esp+38h] [ebp+Ch]

  LODWORD(exponent) = 1023;
  maskpos = 48;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( ndec < 0 )
    ndec = 0;
  v7 = buf;
  if ( buf == nullptr || sizeInBytes == 0 )
  {
    v8 = _errno();
    v34 = 22;
LABEL_5:
    *v8 = v34;
    _invalid_parameter(a1, a2: 0, a3: v34);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return v34;
  }
  *buf = 0;
  if ( sizeInBytes <= ndec + 11 )
  {
    v8 = _errno();
    v34 = 34;
    goto LABEL_5;
  }
  LODWORD(mask) = LODWORD(pvalue->x);
  if ( ((HIDWORD(pvalue->x) >> 20) & 0x7FF) == 0x7FF )
  {
    v10 = sizeInBytes;
    if ( sizeInBytes != -1 )
      v10 = sizeInBytes - 2;
    result = _cftoe(pvalue, buf: buf + 2, sizeInBytes: v10, ndec, caps: 0);
    if ( result != 0 )
    {
      v11 = !_loc_update.updated;
      *buf = 0;
      if ( !v11 )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
    if ( buf[2] == 45 )
    {
      *buf = 45;
      v7 = buf + 1;
    }
    *v7 = 48;
    v12 = v7 + 1;
    *v12 = caps == 0 ? 120 : 88;
    strrchr(string: v12 + 1, chr: 0x65u);
    if ( v13 != nullptr )
    {
      *v13 = caps == 0 ? 112 : 80;
      v13[3] = 0;
    }
  }
  else
  {
    if ( (HIDWORD(pvalue->x) & 0x80000000) != 0 )
    {
      *buf = 45;
      v7 = buf + 1;
    }
    *v7 = 48;
    v14 = v7 + 1;
    *v14 = caps == 0 ? 120 : 88;
    v15 = v14 + 1;
    if ( (HIDWORD(pvalue->x) & 0x7FF00000) != 0 )
    {
      *v15 = 49;
      v16 = v15 + 1;
    }
    else
    {
      *v15 = 48;
      v16 = v15 + 1;
      if ( (HIDWORD(pvalue->x) & 0xFFFFF | LODWORD(pvalue->x)) != 0 )
        LODWORD(exponent) = 1022;
      else
        LODWORD(exponent) = 0;
    }
    v17 = v16;
    v18 = v16 + 1;
    pos = v17;
    if ( ndec != 0 )
      *v17 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
    else
      *v17 = 0;
    x_low = LODWORD(pvalue->x);
    HIDWORD(mask) = HIDWORD(pvalue->x) & 0xFFFFF;
    if ( HIDWORD(mask) != 0 || x_low != 0 )
    {
      mask = 0xF000000000000LL;
      do
      {
        if ( ndec <= 0 )
          break;
        v20 = ((mask & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> maskpos) + 48;
        if ( v20 > 0x39u )
          LOBYTE(v20) = (caps != 0 ? 7 : 39) + v20;
        v21 = HIDWORD(mask);
        maskpos -= 4;
        *v18++ = v20;
        --ndec;
        mask = __PAIR64__(v21, mask) >> 4;
      }
      while ( (maskpos & 0x8000u) == 0 );
      if ( (maskpos & 0x8000u) == 0
        && (unsigned __int16)((mask & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> maskpos) > 8u )
      {
        for ( i = v18 - 1; *i == 102 || *i == 70; --i )
          *i = 48;
        if ( i == pos )
        {
          ++*(i - 1);
        }
        else if ( *i == 57 )
        {
          *i = caps != 0 ? 65 : 97;
        }
        else
        {
          ++*i;
        }
      }
    }
    if ( ndec > 0 )
    {
      memset(dst: (int)v18, value: (unsigned __int8 *)0x30, count: ndec);
      v18 += ndec;
    }
    if ( *pos == 0 )
      v18 = pos;
    *v18 = caps == 0 ? 112 : 80;
    v23 = v18 + 1;
    HIDWORD(v25) = 0;
    v24 = ((*(_QWORD *)&pvalue->x >> 52) & 0x7FFLL) - (unsigned int)exponent;
    if ( v24 < 0 )
    {
      *v23 = 45;
      v26 = v23 + 1;
      v24 = -v24;
    }
    else
    {
      *v23 = 43;
      v26 = v23 + 1;
    }
    v27 = v26;
    *v26 = 48;
    if ( v24 >= 0 )
    {
      LODWORD(v25) = 1000;
      if ( v24 >= 1000 )
      {
        v33 = v25;
        v29 = v24 % v25;
        v28 = v24 / v33;
        *v26++ = v28 + 48;
        HIDWORD(exponent) = HIDWORD(v28);
        v24 = v29;
        if ( v26 != v27 )
          goto LABEL_60;
      }
    }
    if ( v24 >= 100 )
    {
LABEL_60:
      v31 = v24 % 100;
      v30 = v24 / 100;
      *v26 = v30 + 48;
      HIDWORD(exponent) = HIDWORD(v30);
      ++v26;
      v24 = v31;
    }
    if ( v26 != v27 || v24 >= 10 )
    {
      v32 = v24 % 10;
      *v26++ = v24 / 10 + 48;
      LOBYTE(v24) = v24 % 10;
      HIDWORD(exponent) = HIDWORD(v32);
    }
    *v26 = v24 + 48;
    v26[1] = 0;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000E254
// Name: _cftof2_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall cftof2_l@<eax>(
        char *buf@<ecx>,
        _strflt *pflt@<eax>,
        unsigned int sizeInBytes,
        int ndec,
        char g_fmt,
        localeinfo_struct *plocinfo)
{
  int v8; // esi
  char *v10; // eax
  char *v11; // esi
  int decpt; // eax
  char *v13; // esi
  int v14; // ebx
  char *v15; // esi
  int v16; // ebx
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  v8 = pflt->decpt - 1;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( buf != nullptr && sizeInBytes != 0 )
  {
    if ( g_fmt != 0 && v8 == ndec )
    {
      v10 = &buf[v8 + (pflt->sign == 45)];
      *v10 = 48;
      v10[1] = 0;
    }
    v11 = buf;
    if ( pflt->sign == 45 )
    {
      *buf = 45;
      v11 = buf + 1;
    }
    decpt = pflt->decpt;
    if ( decpt > 0 )
    {
      v13 = &v11[decpt];
    }
    else
    {
      shift(s: v11, dist: 1);
      *v11 = 48;
      v13 = v11 + 1;
    }
    if ( ndec > 0 )
    {
      shift(s: v13, dist: 1);
      *v13 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
      v14 = pflt->decpt;
      v15 = v13 + 1;
      if ( v14 < 0 )
      {
        v16 = -v14;
        if ( g_fmt != 0 || ndec >= v16 )
          ndec = v16;
        shift(s: v15, dist: ndec);
        memset(dst: (int)v15, value: (unsigned __int8 *)0x30, count: ndec);
      }
    }
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1: (unsigned int)pflt, a2: (unsigned int)buf, a3: 0x16u);
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E349
// Name: __cftof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftof_l(_CRT_DOUBLE *pvalue, char *buf, unsigned int sizeInBytes, int ndec, localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v6; // eax
  _strflt retstrflt; // [esp+Ch] [ebp-2Ch] BYREF
  char resstr[24]; // [esp+1Ch] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && (v6 = sizeInBytes, sizeInBytes != 0) )
  {
    if ( sizeInBytes != -1 )
      v6 = sizeInBytes - (retstrflt.sign == 45);
    result = _fptostr(
               buf: &buf[retstrflt.sign == 45],
               sizeInBytes: v6,
               digits: ndec + retstrflt.decpt,
               pflt: &retstrflt);
    if ( result != 0 )
      *buf = 0;
    else
      return cftof2_l(buf, pflt: &retstrflt, sizeInBytes, ndec, g_fmt: 0, plocinfo);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: (unsigned int)buf, a3: 0x16u);
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000E402
// Name: __cftog_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _cftog_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  unsigned int result; // eax
  unsigned int v7; // ecx
  BOOL v8; // eax
  char *v9; // edi
  _strflt retstrflt; // [esp+Ch] [ebp-30h] BYREF
  int g_magnitude; // [esp+1Ch] [ebp-20h]
  char resstr[24]; // [esp+20h] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && (v7 = sizeInBytes, sizeInBytes != 0) )
  {
    g_magnitude = retstrflt.decpt - 1;
    v8 = retstrflt.sign == 45;
    v9 = &buf[v8];
    if ( sizeInBytes != -1 )
      v7 = sizeInBytes - v8;
    result = _fptostr(buf: v9, sizeInBytes: v7, digits: ndec, pflt: &retstrflt);
    if ( result != 0 )
    {
      *buf = 0;
    }
    else if ( retstrflt.decpt - 1 < -4 || retstrflt.decpt - 1 >= ndec )
    {
      return cftoe2_l(buf, sizeInBytes, ndec, caps, pflt: &retstrflt, g_fmt: 1, plocinfo);
    }
    else
    {
      if ( g_magnitude < retstrflt.decpt - 1 )
        v9[strlen(v9) - 1] = 0;
      return cftof2_l(buf, pflt: &retstrflt, sizeInBytes, ndec, g_fmt: 1, plocinfo);
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: 0x16u, a3: (unsigned int)buf);
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000E5C0
// Name: __setdefaultprecision
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _setdefaultprecision@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>)
{
  unsigned int result; // eax
  unsigned int v3; // edx
  unsigned int v4; // ecx

  result = _controlfp_s(_CurrentState: nullptr, newctrl: 0x10000u, mask: 0x30000u);
  if ( result != 0 )
    _invoke_watson(a1: result, a2: v3, a3: v4, a4: a1, a5: a2, a6: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000E5E9
// Name: __ms_p5_test_fdiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _ms_p5_test_fdiv()
{
  return 4195835.0 - 4195835.0 / 3145727.0 * 3145727.0 > 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x1000E625
// Name: __ms_p5_mp_test_fdiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ms_p5_mp_test_fdiv()
{
  HMODULE ModuleHandleA; // eax
  BOOL (__stdcall *IsProcessorFeaturePresent)(DWORD); // eax

  ModuleHandleA = GetModuleHandleA(lpModuleName: "KERNEL32");
  if ( ModuleHandleA != nullptr
    && (IsProcessorFeaturePresent = (BOOL (__stdcall *)(DWORD))GetProcAddress(
                                                                 hModule: ModuleHandleA,
                                                                 lpProcName: "IsProcessorFeaturePresent")) != nullptr )
  {
    return IsProcessorFeaturePresent(ProcessorFeature: 0);
  }
  else
  {
    return _ms_p5_test_fdiv();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E6C0
// Name: _strcmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strcmp(unsigned __int8 *str1, unsigned __int8 *str2)
{
  unsigned __int8 *v2; // edx
  unsigned __int8 *v3; // ecx
  unsigned int v4; // eax
  unsigned int v5; // eax
  __int16 v6; // ax

  v2 = str1;
  v3 = str2;
  if ( ((unsigned __int8)str1 & 3) != 0 )
  {
    if ( ((unsigned __int8)str1 & 1) == 0 )
      goto doword;
    v2 = str1 + 1;
    if ( *str1 != *str2 )
      return;
    v3 = str2 + 1;
    if ( *str1 == 0 )
      return;
    if ( ((unsigned __int8)v2 & 2) != 0 )
    {
doword:
      v6 = *(_WORD *)v2;
      v2 += 2;
      if ( (_BYTE)v6 != *v3 || (_BYTE)v6 == 0 || HIBYTE(v6) != v3[1] || HIBYTE(v6) == 0 )
        return;
      v3 += 2;
    }
  }
  do
  {
    v4 = *(_DWORD *)v2;
    if ( (unsigned __int8)*(_DWORD *)v2 != *v3 )
      break;
    if ( (_BYTE)v4 == 0 )
      break;
    if ( BYTE1(v4) != v3[1] )
      break;
    if ( BYTE1(v4) == 0 )
      break;
    v5 = HIWORD(v4);
    if ( (_BYTE)v5 != v3[2] )
      break;
    if ( (_BYTE)v5 == 0 )
      break;
    if ( BYTE1(v5) != v3[3] )
      break;
    v3 += 4;
    v2 += 4;
  }
  while ( BYTE1(v5) != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x1000E748
// Name: _abort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn abort()
{
  unsigned int v0; // esi
  void (__cdecl *sigabrt)(int); // eax
  unsigned int v2; // edx
  unsigned int v3; // ecx
  unsigned int v4; // kr00_4
  unsigned int v5; // [esp-4h] [ebp-88h]
  _EXCEPTION_RECORD ExceptionRecord; // [esp+4h] [ebp-80h] BYREF
  _EXCEPTION_POINTERS ExceptionPointers; // [esp+54h] [ebp-30h] BYREF
  _CONTEXT ContextRecord; // [esp+5Ch] [ebp-28h] BYREF
  unsigned int savedregs; // [esp+32Ch] [ebp+2A8h]
  void *retaddr; // [esp+330h] [ebp+2ACh] BYREF

  if ( (__abort_behavior & 1) != 0 )
    _NMSG_WRITE(rterrnum: 10);
  sigabrt = __get_sigabrt();
  if ( sigabrt != nullptr )
  {
    sigabrt = (void (__cdecl *)(int))raise(signum: 22);
    v3 = v5;
  }
  if ( (__abort_behavior & 2) != 0 )
  {
    ContextRecord.Eax = (unsigned int)sigabrt;
    ContextRecord.Ecx = v3;
    ContextRecord.Edx = v2;
    ContextRecord.Esi = v0;
    LOWORD(ContextRecord.SegSs) = __SS__;
    LOWORD(ContextRecord.SegCs) = __CS__;
    LOWORD(ContextRecord.SegDs) = __DS__;
    LOWORD(ContextRecord.SegEs) = __ES__;
    LOWORD(ContextRecord.SegFs) = __FS__;
    LOWORD(ContextRecord.SegGs) = __GS__;
    v4 = __readeflags();
    ContextRecord.EFlags = v4;
    ContextRecord.Esp = (unsigned int)&retaddr;
    ContextRecord.ContextFlags = 65537;
    ContextRecord.Eip = (unsigned int)retaddr;
    ContextRecord.Ebp = savedregs;
    memset(dst: (int)&ExceptionRecord, value: nullptr, count: sizeof(ExceptionRecord));
    ExceptionPointers.ExceptionRecord = &ExceptionRecord;
    ExceptionRecord.ExceptionCode = 1073741845;
    ExceptionRecord.ExceptionAddress = retaddr;
    ExceptionPointers.ContextRecord = &ContextRecord;
    SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: nullptr);
    UnhandledExceptionFilter(ExceptionInfo: &ExceptionPointers);
  }
  _exit(code: 3);
}

//------------------------------------------------------------------------------
// Address: 0x1000E83B
// Name: __NMSG_WRITE
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _NMSG_WRITE(int rterrnum)
{
  unsigned int i; // edi
  unsigned int v2; // eax
  unsigned int v3; // edx
  unsigned int v4; // ecx
  unsigned int v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  int v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // edx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // ecx
  unsigned int v15; // eax
  unsigned int v16; // edx
  unsigned int v17; // ecx
  HANDLE StdHandle; // eax
  void *v19; // ebp
  unsigned __int8 **p_rterrtxt; // esi
  DWORD v21; // eax
  unsigned int NumberOfBytesWritten; // [esp+Ch] [ebp-4h] BYREF

  for ( i = 0; i < 0x17; ++i )
  {
    if ( rterrnum == rterrs[i].rterrno )
      break;
  }
  if ( i < 0x17 )
  {
    if ( _set_error_mode(em: 3) == 1 || _set_error_mode(em: 3) == 0 && __app_type == 1 )
    {
      StdHandle = GetStdHandle(nStdHandle: 0xFFFFFFF4);
      v19 = StdHandle;
      if ( StdHandle != nullptr && StdHandle != (HANDLE)-1 )
      {
        p_rterrtxt = (unsigned __int8 **)&rterrs[i].rterrtxt;
        strlen(buf: *p_rterrtxt);
        WriteFile(
          hFile: v19,
          lpBuffer: *p_rterrtxt,
          nNumberOfBytesToWrite: v21,
          lpNumberOfBytesWritten: &NumberOfBytesWritten,
          lpOverlapped: nullptr);
      }
    }
    else if ( rterrnum != 252 )
    {
      v2 = strcpy_s(_Dst: outmsg, _SizeInBytes: 0x314u, _Src: "Runtime Error!\n\nProgram: ");
      if ( v2 != 0 )
        _invoke_watson(a1: v2, a2: v3, a3: v4, a4: 0x314u, a5: i, a6: 0);
      outmsg[285] = 0;
      if ( GetModuleFileNameA(hModule: nullptr, lpFilename: &outmsg[25], nSize: 0x104u) == 0
        && strcpy_s(_Dst: &outmsg[25], _SizeInBytes: 0x2FBu, _Src: "<program name unknown>") != 0 )
      {
        _invoke_watson(a1: 0, a2: v5, a3: v6, a4: 0x314u, a5: i, a6: (unsigned int)&outmsg[25]);
      }
      strlen(buf: (unsigned __int8 *)&outmsg[25]);
      if ( (unsigned int)(v7 + 1) > 0x3C )
      {
        strlen(buf: (unsigned __int8 *)&outmsg[25]);
        v9 = strncpy_s(
               _Dst: &outmsg[v8 - 34],
               _SizeInBytes: (char *)&gpFlsAlloc - &outmsg[v8 - 34],
               _Src: "...",
               _Count: 3u);
        if ( v9 != 0 )
          _invoke_watson(a1: v9, a2: v10, a3: v11, a4: 0x314u, a5: i, a6: 0);
      }
      v12 = strcat_s(_Dst: outmsg, _SizeInBytes: 0x314u, _Src: "\n\n");
      if ( v12 != 0 )
        _invoke_watson(a1: v12, a2: v13, a3: v14, a4: 0x314u, a5: i, a6: 0);
      v15 = strcat_s(_Dst: outmsg, _SizeInBytes: 0x314u, _Src: rterrs[i].rterrtxt);
      if ( v15 != 0 )
        _invoke_watson(a1: v15, a2: v16, a3: v17, a4: 0x314u, a5: i, a6: 0);
      __crtMessageBoxA(lpText: outmsg, lpCaption: "Microsoft Visual C++ Runtime Library", uType: 0x12010u);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E9DB
// Name: __FF_MSGBANNER
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _FF_MSGBANNER()
{
  if ( _set_error_mode(em: 3) == 1 || _set_error_mode(em: 3) == 0 && __app_type == 1 )
  {
    _NMSG_WRITE(rterrnum: 252);
    _NMSG_WRITE(rterrnum: 255);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EA14
// Name: _use_encode_pointer
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl use_encode_pointer()
{
  unsigned int v0; // ebx
  HMODULE ModuleHandleA; // eax
  char *v3; // esi
  unsigned __int8 *v4; // edi
  int v5; // eax
  int bEncode; // [esp+8h] [ebp-8h]
  int winmajor; // [esp+Ch] [ebp-4h] BYREF

  v0 = 0;
  bEncode = 1;
  winmajor = 0;
  _get_winmajor(pValue: (unsigned int *)&winmajor);
  if ( winmajor > 5 )
    return 1;
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  v3 = (char *)ModuleHandleA + *((_DWORD *)ModuleHandleA + 15);
  v4 = (unsigned __int8 *)&v3[*((unsigned __int16 *)v3 + 10) + 24];
  if ( *((_WORD *)v3 + 3) != 0 )
  {
    while ( 1 )
    {
      strcmp(str1: ".mixcrt", str2: v4);
      if ( v5 == 0 )
        break;
      ++v0;
      v4 += 40;
      if ( v0 >= *((unsigned __int16 *)v3 + 3) )
        return bEncode;
    }
    return 0;
  }
  return bEncode;
}

//------------------------------------------------------------------------------
// Address: 0x1000EA80
// Name: __encode_pointer
// Source: linker_block_proximity
//------------------------------------------------------------------------------
PVOID __cdecl _encode_pointer(void *ptr)
{
  int (__stdcall *Value)(unsigned int); // eax
  int v2; // eax
  PVOID (__stdcall *EncodePointer)(PVOID); // eax
  HMODULE ModuleHandleA; // esi
  unsigned int v6; // [esp-4h] [ebp-8h]

  if ( TlsGetValue(dwTlsIndex: __getvalueindex) != nullptr
    && __flsindex != -1
    && (v6 = __flsindex,
        Value = (int (__stdcall *)(unsigned int))TlsGetValue(dwTlsIndex: __getvalueindex),
        (v2 = Value(a1: v6)) != 0) )
  {
    EncodePointer = *(PVOID (__stdcall **)(PVOID))(v2 + 504);
  }
  else
  {
    ModuleHandleA = GetModuleHandleA(lpModuleName: "KERNEL32.DLL");
    if ( ModuleHandleA == nullptr || use_encode_pointer() == 0 )
      return ptr;
    EncodePointer = (PVOID (__stdcall *)(PVOID))GetProcAddress(hModule: ModuleHandleA, lpProcName: "EncodePointer");
  }
  if ( EncodePointer != nullptr )
    return EncodePointer(Ptr: ptr);
  return ptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000EAEE
// Name: __encoded_null
// Source: linker_block_proximity
//------------------------------------------------------------------------------
PVOID __cdecl _encoded_null()
{
  return _encode_pointer(ptr: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1000EAF7
// Name: __decode_pointer
// Source: linker_block_proximity
//------------------------------------------------------------------------------
PVOID __cdecl _decode_pointer(void *codedptr)
{
  int (__stdcall *Value)(unsigned int); // eax
  int v2; // eax
  PVOID (__stdcall *DecodePointer)(PVOID); // eax
  HMODULE ModuleHandleA; // esi
  unsigned int v6; // [esp-4h] [ebp-8h]

  if ( TlsGetValue(dwTlsIndex: __getvalueindex) != nullptr
    && __flsindex != -1
    && (v6 = __flsindex,
        Value = (int (__stdcall *)(unsigned int))TlsGetValue(dwTlsIndex: __getvalueindex),
        (v2 = Value(a1: v6)) != 0) )
  {
    DecodePointer = *(PVOID (__stdcall **)(PVOID))(v2 + 508);
  }
  else
  {
    ModuleHandleA = GetModuleHandleA(lpModuleName: "KERNEL32.DLL");
    if ( ModuleHandleA == nullptr || use_encode_pointer() == 0 )
      return codedptr;
    DecodePointer = (PVOID (__stdcall *)(PVOID))GetProcAddress(hModule: ModuleHandleA, lpProcName: "DecodePointer");
  }
  if ( DecodePointer != nullptr )
    return DecodePointer(Ptr: codedptr);
  return codedptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000EB65
// Name: __crtTlsAlloc(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
DWORD __stdcall __crtTlsAlloc(void (__stdcall *lpCallBack)(void *))
{
  return TlsAlloc();
}

//------------------------------------------------------------------------------
// Address: 0x1000EB6E
// Name: ___set_flsgetvalue
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *(__stdcall *__cdecl __set_flsgetvalue())(unsigned int)
{
  void *Value; // esi

  Value = TlsGetValue(dwTlsIndex: __getvalueindex);
  if ( Value == nullptr )
  {
    Value = _decode_pointer(codedptr: gpFlsGetValue);
    TlsSetValue(dwTlsIndex: __getvalueindex, lpTlsValue: Value);
  }
  return (void *(__stdcall *)(unsigned int))Value;
}

//------------------------------------------------------------------------------
// Address: 0x1000EBA0
// Name: __mtterm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _mtterm()
{
  void (__stdcall *v0)(unsigned int); // eax
  unsigned int v2; // [esp-4h] [ebp-4h]

  if ( __flsindex != -1 )
  {
    v2 = __flsindex;
    v0 = (void (__stdcall *)(unsigned int))_decode_pointer(codedptr: gpFlsFree);
    v0(a1: v2);
    __flsindex = -1;
  }
  if ( __getvalueindex != -1 )
  {
    TlsFree(dwTlsIndex: __getvalueindex);
    __getvalueindex = -1;
  }
  return _mtdeletelocks();
}

//------------------------------------------------------------------------------
// Address: 0x1000EBDD
// Name: __initptd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initptd(_tiddata *ptd, threadlocaleinfostruct *ptloci)
{
  HINSTANCE__ *hKernel32; // [esp+10h] [ebp-1Ch]

  hKernel32 = GetModuleHandleA(lpModuleName: "KERNEL32.DLL");
  ptd->_pxcptacttab = _XcptActTab;
  ptd->_holdrand = 1;
  if ( hKernel32 != nullptr && use_encode_pointer() != 0 )
  {
    ptd->_encode_ptr = GetProcAddress(hModule: hKernel32, lpProcName: "EncodePointer");
    ptd->_decode_ptr = GetProcAddress(hModule: hKernel32, lpProcName: "DecodePointer");
  }
  ptd->_ownlocale = 1;
  ptd->_setloc_data._cachein[0] = 67;
  ptd->_setloc_data._cacheout[0] = 67;
  ptd->ptmbcinfo = &__initialmbcinfo;
  InterlockedIncrement(lpAddend: &__initialmbcinfo.refcount);
  _lock(locknum: 12);
  ptd->ptlocinfo = ptloci;
  if ( ptloci == nullptr )
    ptd->ptlocinfo = __ptlocinfo;
  __addlocaleref(ptloci: ptd->ptlocinfo);
  _unlock(locknum: 12);
}

//------------------------------------------------------------------------------
// Address: 0x1000EC9C
// Name: __getptd_noexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_tiddata *__cdecl _getptd_noexit()
{
  DWORD LastError; // eax
  DWORD v1; // edi
  void *(__stdcall *v2)(unsigned int); // eax
  _tiddata *v3; // esi
  _tiddata *v4; // eax
  int (__stdcall *v5)(unsigned int, _tiddata *); // eax
  DWORD CurrentThreadId; // eax
  unsigned int v8; // [esp-8h] [ebp-10h]
  unsigned int v9; // [esp-4h] [ebp-Ch]
  _tiddata *v10; // [esp-4h] [ebp-Ch]

  LastError = GetLastError();
  v9 = __flsindex;
  v1 = LastError;
  v2 = __set_flsgetvalue();
  v3 = (_tiddata *)v2(a1: v9);
  if ( v3 == nullptr )
  {
    v4 = (_tiddata *)calloc(count: 1u, size: 0x214u);
    v3 = v4;
    if ( v4 != nullptr )
    {
      v10 = v4;
      v8 = __flsindex;
      v5 = (int (__stdcall *)(unsigned int, _tiddata *))_decode_pointer(codedptr: gpFlsSetValue);
      if ( v5(a1: v8, a2: v10) != 0 )
      {
        _initptd(ptd: v3, ptloci: nullptr);
        CurrentThreadId = GetCurrentThreadId();
        v3->_thandle = -1;
        v3->_tid = CurrentThreadId;
      }
      else
      {
        free(pMem: v3);
        v3 = nullptr;
      }
    }
  }
  SetLastError(dwErrCode: v1);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1000ED13
// Name: __getptd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_tiddata *__cdecl _getptd()
{
  _tiddata *v0; // esi

  v0 = _getptd_noexit();
  if ( v0 == nullptr )
    _amsg_exit(rterrnum: 16);
  return v0;
}

//------------------------------------------------------------------------------
// Address: 0x1000ED2B
// Name: _freefls(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _freefls(void *data)
{
  threadmbcinfostruct *v1; // edi
  threadlocaleinfostruct *v2; // edi
  int savedregs; // [esp+28h] [ebp+0h]

  if ( data != nullptr )
  {
    if ( *((_DWORD *)data + 9) != 0 )
      free(pMem: *((void **)data + 9));
    if ( *((_DWORD *)data + 11) != 0 )
      free(pMem: *((void **)data + 11));
    if ( *((_DWORD *)data + 13) != 0 )
      free(pMem: *((void **)data + 13));
    if ( *((_DWORD *)data + 15) != 0 )
      free(pMem: *((void **)data + 15));
    if ( *((_DWORD *)data + 17) != 0 )
      free(pMem: *((void **)data + 17));
    if ( *((_DWORD *)data + 18) != 0 )
      free(pMem: *((void **)data + 18));
    if ( *((_XCPT_ACTION **)data + 23) != _XcptActTab )
      free(pMem: *((void **)data + 23));
    _lock(locknum: 13);
    v1 = *((threadmbcinfostruct **)data + 26);
    if ( v1 != nullptr && InterlockedDecrement(lpAddend: *((volatile LONG **)data + 26)) == 0 && v1 != &__initialmbcinfo )
      free(pMem: v1);
    _unlock(locknum: 13);
    _lock(locknum: 12);
    v2 = *((threadlocaleinfostruct **)data + 27);
    if ( v2 != nullptr )
    {
      __removelocaleref(ptloci: *((threadlocaleinfostruct **)data + 27));
      if ( v2 != __ptlocinfo && v2 != &__initiallocinfo && v2->refcount == 0 )
        __freetlocinfo(ptloci: v2);
    }
    savedregs = 268496421;
    _unlock(locknum: 12);
    free(pMem: data);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000EE4C
// Name: __freeptd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _freeptd(_tiddata *ptd)
{
  _tiddata *v1; // edi
  int (__stdcall *Value)(unsigned int); // eax
  void (__stdcall *v3)(unsigned int, _DWORD); // eax
  unsigned int v4; // [esp-Ch] [ebp-Ch]
  unsigned int v5; // [esp-Ch] [ebp-Ch]

  if ( __flsindex != -1 )
  {
    v1 = ptd;
    if ( ptd == nullptr && TlsGetValue(dwTlsIndex: __getvalueindex) != nullptr )
    {
      v4 = __flsindex;
      Value = (int (__stdcall *)(unsigned int))TlsGetValue(dwTlsIndex: __getvalueindex);
      v1 = (_tiddata *)Value(a1: v4);
    }
    v5 = __flsindex;
    v3 = (void (__stdcall *)(unsigned int, _DWORD))_decode_pointer(codedptr: gpFlsSetValue);
    v3(a1: v5, a2: 0);
    _freefls(data: v1);
  }
  if ( __getvalueindex != -1 )
    TlsSetValue(dwTlsIndex: __getvalueindex, lpTlsValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1000EEB5
// Name: __mtinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mtinit()
{
  HMODULE ModuleHandleA; // eax
  HMODULE v1; // edi
  BOOL (__stdcall *FlsFree)(DWORD); // eax
  DWORD v4; // eax
  int (__stdcall *v5)(_DWORD); // eax
  _tiddata *v6; // eax
  _tiddata *v7; // esi
  int (__stdcall *v8)(unsigned int, _tiddata *); // eax
  DWORD CurrentThreadId; // eax
  unsigned int v10; // [esp-Ch] [ebp-10h]
  _tiddata *v11; // [esp-8h] [ebp-Ch]

  ModuleHandleA = GetModuleHandleA(lpModuleName: "KERNEL32.DLL");
  v1 = ModuleHandleA;
  if ( ModuleHandleA == nullptr )
  {
    _mtterm();
    return 0;
  }
  gpFlsAlloc = (unsigned int (__stdcall *)(void (__stdcall *)(void *)))GetProcAddress(
                                                                         hModule: ModuleHandleA,
                                                                         lpProcName: "FlsAlloc");
  gpFlsGetValue = (void *(__stdcall *)(unsigned int))GetProcAddress(hModule: v1, lpProcName: "FlsGetValue");
  gpFlsSetValue = (int (__stdcall *)(unsigned int, void *))GetProcAddress(hModule: v1, lpProcName: "FlsSetValue");
  FlsFree = (BOOL (__stdcall *)(DWORD))GetProcAddress(hModule: v1, lpProcName: "FlsFree");
  gpFlsFree = FlsFree;
  if ( gpFlsAlloc == nullptr || gpFlsGetValue == nullptr || gpFlsSetValue == nullptr || FlsFree == nullptr )
  {
    gpFlsGetValue = TlsGetValue;
    gpFlsAlloc = __crtTlsAlloc;
    gpFlsSetValue = TlsSetValue;
    gpFlsFree = TlsFree;
  }
  v4 = TlsAlloc();
  __getvalueindex = v4;
  if ( v4 != -1 && TlsSetValue(dwTlsIndex: v4, lpTlsValue: gpFlsGetValue) )
  {
    _init_pointers();
    gpFlsAlloc = (unsigned int (__stdcall *)(void (__stdcall *)(void *)))_encode_pointer(ptr: gpFlsAlloc);
    gpFlsGetValue = (void *(__stdcall *)(unsigned int))_encode_pointer(ptr: gpFlsGetValue);
    gpFlsSetValue = (int (__stdcall *)(unsigned int, void *))_encode_pointer(ptr: gpFlsSetValue);
    gpFlsFree = (int (__stdcall *)(unsigned int))_encode_pointer(ptr: gpFlsFree);
    if ( _mtinitlocks() != 0 )
    {
      v5 = (int (__stdcall *)(_DWORD))_decode_pointer(codedptr: gpFlsAlloc);
      __flsindex = v5(a1: _freefls);
      if ( __flsindex != -1 )
      {
        v6 = (_tiddata *)calloc(count: 1u, size: 0x214u);
        v7 = v6;
        if ( v6 != nullptr )
        {
          v11 = v6;
          v10 = __flsindex;
          v8 = (int (__stdcall *)(unsigned int, _tiddata *))_decode_pointer(codedptr: gpFlsSetValue);
          if ( v8(a1: v10, a2: v11) != 0 )
          {
            _initptd(ptd: v7, ptloci: nullptr);
            CurrentThreadId = GetCurrentThreadId();
            v7->_thandle = -1;
            v7->_tid = CurrentThreadId;
            return 1;
          }
        }
      }
    }
    _mtterm();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000F039
// Name: __initp_misc_purevirt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_purevirt(void (__cdecl *enull)())
{
  __pPurecall = enull;
}

//------------------------------------------------------------------------------
// Address: 0x1000F043
// Name: __amsg_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _amsg_exit(int rterrnum)
{
  void (__cdecl *v1)(int); // eax

  _FF_MSGBANNER();
  _NMSG_WRITE(rterrnum);
  v1 = (void (__cdecl *)(int))_decode_pointer(codedptr: _aexit_rtn);
  v1(a1: 255);
}

//------------------------------------------------------------------------------
// Address: 0x1000F067
// Name: ___crtCorExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __crtCorExitProcess(int status)
{
  HMODULE ModuleHandleA; // eax
  FARPROC CorExitProcess; // eax

  ModuleHandleA = GetModuleHandleA(lpModuleName: "mscoree.dll");
  if ( ModuleHandleA != nullptr )
  {
    CorExitProcess = GetProcAddress(hModule: ModuleHandleA, lpProcName: "CorExitProcess");
    if ( CorExitProcess != nullptr )
      ((void (__stdcall *)(int))CorExitProcess)(a1: status);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F08D
// Name: ___crtExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn __crtExitProcess(int status)
{
  __crtCorExitProcess(status);
  ExitProcess(uExitCode: status);
}

//------------------------------------------------------------------------------
// Address: 0x1000F0A2
// Name: __lockexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _lockexit()
{
  _lock(locknum: 8);
}

//------------------------------------------------------------------------------
// Address: 0x1000F0AB
// Name: __unlockexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _unlockexit()
{
  _unlock(locknum: 8);
}

//------------------------------------------------------------------------------
// Address: 0x1000F0B4
// Name: _initterm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall initterm(void (__cdecl **pfbegin)()@<eax>, void (__cdecl **pfend)())
{
  while ( pfbegin < pfend )
  {
    if ( *pfbegin != nullptr )
      (*pfbegin)();
    ++pfbegin;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F0CC
// Name: __initterm_e
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _initterm_e(int (__cdecl **pfbegin)(), int (__cdecl **pfend)())
{
  int result; // eax

  result = 0;
  while ( pfbegin < pfend && result == 0 )
  {
    if ( *pfbegin != nullptr )
      result = (*pfbegin)();
    ++pfbegin;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000F0EC
// Name: __get_osplatform
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _get_osplatform@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, unsigned int *pValue)
{
  if ( pValue != nullptr && _osplatform != 0 )
  {
    *pValue = _osplatform;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2, a3: 0);
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F123
// Name: __get_winmajor
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _get_winmajor@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, unsigned int *pValue)
{
  if ( pValue != nullptr && _osplatform != 0 )
  {
    *pValue = _winmajor;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2, a3: 0);
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F15F
// Name: __cinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cinit(int initFloatingPrecision)
{
  int result; // eax
  void (**i)(void); // esi

  if ( _fpmath != nullptr && _IsNonwritableInCurrentImage(pTarget: (unsigned __int8 *)&_FPinit) != 0 )
    _fpmath(initPrecision: initFloatingPrecision);
  _initp_misc_cfltcvt_tab();
  result = _initterm_e(pfbegin: __xi_a, pfend: __xi_z);
  if ( result == 0 )
  {
    atexit(func: _RTC_Terminate);
    for ( i = __xc_a; i < __xc_z; ++i )
    {
      if ( *i != nullptr )
        (*i)();
    }
    if ( __dyn_tls_init_callback != nullptr
      && _IsNonwritableInCurrentImage(pTarget: (unsigned __int8 *)&__dyn_tls_init_callback) != 0 )
    {
      __dyn_tls_init_callback(a1: nullptr, a2: 2u, a3: nullptr);
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000F1F1
// Name: doexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl doexit(int code, int quick, int retcaller)
{
  void **v3; // esi
  PVOID v4; // edi
  void (*v5)(void); // eax
  void (__cdecl **onexitbegin)(); // [esp+14h] [ebp-1Ch]

  _lock(locknum: 8);
  if ( _C_Exit_Done != 1 )
  {
    _C_Termination_Done = 1;
    _exitflag = retcaller;
    if ( quick == 0 )
    {
      onexitbegin = (void (__cdecl **)())_decode_pointer(codedptr: __onexitbegin);
      v3 = (void **)_decode_pointer(codedptr: __onexitend);
      if ( onexitbegin != nullptr )
      {
        while ( --v3 >= (void **)onexitbegin )
        {
          if ( *v3 != nullptr )
          {
            v4 = *v3;
            if ( v4 != _encoded_null() )
            {
              v5 = (void (*)(void))_decode_pointer(codedptr: v4);
              v5();
            }
          }
        }
      }
      initterm(pfbegin: __xp_a, pfend: __xp_z);
    }
    initterm(pfbegin: __xt_a, pfend: __xt_z);
  }
  if ( retcaller != 0 )
    _unlock(locknum: 8);
  if ( retcaller == 0 )
  {
    _C_Exit_Done = 1;
    _unlock(locknum: 8);
    __crtExitProcess(status: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000F2D3
// Name: __exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _exit(int code)
{
  doexit(code, quick: 1, retcaller: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000F2E4
// Name: __cexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cexit()
{
  doexit(code: 0, quick: 0, retcaller: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1000F2F3
// Name: __init_pointers
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void (__cdecl *_init_pointers())(int)
{
  PVOID v0; // esi
  void (__cdecl *result)(int); // eax

  v0 = _encoded_null();
  _initp_heap_handler(enull: v0);
  _initp_misc_initcrit(enull: v0);
  _initp_misc_invarg(enull: (void (__cdecl *)(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, unsigned int))v0);
  _initp_misc_purevirt(enull: (void (__cdecl *)())v0);
  _initp_misc_rand_s(enull: v0);
  _initp_misc_winsig(enull: v0);
  _initp_misc_winxfltr(enull: v0);
  _initp_eh_hooks(enull: v0);
  result = (void (__cdecl *)(int))_encode_pointer(ptr: _exit);
  _aexit_rtn = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000F33F
// Name: __ioinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ioinit()
{
  ioinfo *v0; // eax
  ioinfo *j; // ecx
  int v2; // edi
  unsigned __int8 *v3; // ebx
  ioinfo *v4; // eax
  ioinfo **v5; // ecx
  unsigned int k; // edx
  ioinfo *v7; // esi
  int m; // ebx
  ioinfo *v9; // esi
  DWORD v10; // eax
  HANDLE StdHandle; // eax
  int v12; // edi
  DWORD FileType; // eax
  _STARTUPINFOA StartupInfo; // [esp+10h] [ebp-64h] BYREF
  int i; // [esp+54h] [ebp-20h]
  int *posfhnd; // [esp+58h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+5Ch] [ebp-18h]

  ms_exc.registration.TryLevel = 0;
  GetStartupInfoA(lpStartupInfo: &StartupInfo);
  ms_exc.registration.TryLevel = -2;
  v0 = (ioinfo *)calloc(count: 0x20u, size: 0x40u);
  if ( v0 == nullptr )
    return -1;
  __pioinfo[0] = v0;
  _nhandle = 32;
  for ( j = v0 + 32; v0 < j; j = __pioinfo[0] + 32 )
  {
    v0->osfile = 0;
    v0->osfhnd = -1;
    v0->pipech = 10;
    v0->lockinitflag = 0;
    *((_BYTE *)v0 + 36) = 0;
    v0->pipech2[0] = 10;
    v0->pipech2[1] = 10;
    v0->dbcsBufferUsed = 0;
    v0->dbcsBuffer = 0;
    ++v0;
  }
  if ( StartupInfo.cbReserved2 != 0 && StartupInfo.lpReserved2 != nullptr )
  {
    v2 = *(_DWORD *)StartupInfo.lpReserved2;
    v3 = StartupInfo.lpReserved2 + 4;
    posfhnd = (int *)&StartupInfo.lpReserved2[*(_DWORD *)StartupInfo.lpReserved2 + 4];
    if ( v2 >= 2048 )
      v2 = 2048;
    i = 1;
    while ( (int)_nhandle < v2 )
    {
      v4 = (ioinfo *)calloc(count: 0x20u, size: 0x40u);
      if ( v4 == nullptr )
      {
        v2 = _nhandle;
        break;
      }
      v5 = &__pioinfo[i];
      *v5 = v4;
      _nhandle += 32;
      for ( k = (unsigned int)&v4[32]; (unsigned int)v4 < k; k = (unsigned int)&(*v5)[32] )
      {
        v4->osfile = 0;
        v4->osfhnd = -1;
        v4->pipech = 10;
        v4->lockinitflag = 0;
        *((_BYTE *)v4 + 36) &= 0x80u;
        v4->pipech2[0] = 10;
        v4->pipech2[1] = 10;
        v4->dbcsBufferUsed = 0;
        v4->dbcsBuffer = 0;
        ++v4;
      }
      ++i;
    }
    for ( i = 0; i < v2; ++posfhnd )
    {
      if ( *posfhnd != -1
        && *posfhnd != -2
        && (*v3 & 1) != 0
        && ((*v3 & 8) != 0 || GetFileType(hFile: (HANDLE)*posfhnd) != 0) )
      {
        v7 = &__pioinfo[i >> 5][i & 0x1F];
        v7->osfhnd = *posfhnd;
        v7->osfile = *v3;
        if ( __crtInitCritSecAndSpinCount(lpCriticalSection: &v7->lock, dwSpinCount: 0xFA0u) == 0 )
          return -1;
        ++v7->lockinitflag;
      }
      ++i;
      ++v3;
    }
  }
  for ( m = 0; m < 3; ++m )
  {
    v9 = &__pioinfo[0][m];
    if ( v9->osfhnd == -1 || v9->osfhnd == -2 )
    {
      v9->osfile = -127;
      if ( m != 0 )
        v10 = -(m != 1) - 11;
      else
        v10 = -10;
      StdHandle = GetStdHandle(nStdHandle: v10);
      v12 = (int)StdHandle;
      if ( StdHandle != (HANDLE)-1 && StdHandle != nullptr && (FileType = GetFileType(hFile: StdHandle)) != 0 )
      {
        v9->osfhnd = v12;
        if ( (unsigned __int8)FileType == 2 )
        {
          v9->osfile |= 0x40u;
        }
        else if ( (unsigned __int8)FileType == 3 )
        {
          v9->osfile |= 8u;
        }
        if ( __crtInitCritSecAndSpinCount(lpCriticalSection: &v9->lock, dwSpinCount: 0xFA0u) == 0 )
          return -1;
        ++v9->lockinitflag;
      }
      else
      {
        v9->osfile |= 0x40u;
        v9->osfhnd = -2;
      }
    }
    else
    {
      v9->osfile |= 0x80u;
    }
  }
  SetHandleCount(uNumber: _nhandle);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000F593
// Name: __ioterm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _ioterm()
{
  void **v0; // esi
  char *v1; // edi
  unsigned int i; // eax

  v0 = (void **)__pioinfo;
  do
  {
    v1 = (char *)*v0;
    if ( *v0 != nullptr )
    {
      for ( i = (unsigned int)(v1 + 2048); (unsigned int)v1 < i; i = (unsigned int)*v0 + 2048 )
      {
        if ( *((_DWORD *)v1 + 2) != 0 )
          DeleteCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(v1 + 12));
        v1 += 64;
      }
      free(pMem: *v0);
      *v0 = nullptr;
    }
    ++v0;
  }
  while ( (int)v0 < (int)&__env_initialized );
}

//------------------------------------------------------------------------------
// Address: 0x1000F5DF
// Name: __setenvp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setenvp()
{
  unsigned __int8 *v0; // esi
  int v1; // edi
  int v3; // eax
  char **v4; // edi
  unsigned __int8 *i; // esi
  int v6; // eax
  unsigned int v7; // ebp
  char *v8; // eax
  unsigned int v9; // eax
  unsigned int v10; // edx
  unsigned int v11; // ecx

  if ( __mbctype_initialized == 0 )
    __initmbctable();
  v0 = (unsigned __int8 *)_aenvptr;
  v1 = 0;
  if ( _aenvptr != nullptr )
  {
    while ( *v0 != 0 )
    {
      if ( *v0 != 61 )
        ++v1;
      strlen(buf: v0);
      v0 += v3 + 1;
    }
    v4 = (char **)calloc(count: v1 + 1, size: 4u);
    _environ = v4;
    if ( v4 != nullptr )
    {
      for ( i = (unsigned __int8 *)_aenvptr; ; i += v7 )
      {
        if ( *i == 0 )
        {
          free(pMem: _aenvptr);
          _aenvptr = nullptr;
          *v4 = nullptr;
          __env_initialized = 1;
          return 0;
        }
        strlen(buf: i);
        v7 = v6 + 1;
        if ( *i != 61 )
          break;
LABEL_16:
        ;
      }
      v8 = (char *)calloc(count: v6 + 1, size: 1u);
      *v4 = v8;
      if ( v8 != nullptr )
      {
        v9 = strcpy_s(_Dst: v8, _SizeInBytes: v7, _Src: (const char *)i);
        if ( v9 != 0 )
          _invoke_watson(a1: v9, a2: v10, a3: v11, a4: 0, a5: (unsigned int)v4, a6: (unsigned int)i);
        ++v4;
        goto LABEL_16;
      }
      free(pMem: _environ);
      _environ = nullptr;
      return -1;
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1000F6BA
// Name: parse_cmdline
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall parse_cmdline(char *cmdstart@<edx>, int *numchars@<edi>, char **argv, char *args, int *numargs)
{
  int *v5; // ecx
  char *v7; // edx
  char **v8; // ebx
  char v9; // bl
  char *v10; // ecx
  char **v11; // eax
  int v12; // ebx
  unsigned int v13; // ecx
  char v14; // al
  char *v15; // ecx
  char *v16; // ecx
  unsigned int v17; // [esp-4h] [ebp-10h]
  BOOL inquote; // [esp+8h] [ebp-4h]
  BOOL inquotea; // [esp+8h] [ebp-4h]

  v5 = numargs;
  *numchars = 0;
  v7 = args;
  *numargs = 1;
  if ( argv != nullptr )
  {
    v8 = argv++;
    *v8 = args;
  }
  inquote = false;
  do
  {
    if ( *cmdstart == 34 )
    {
      v9 = 34;
      ++cmdstart;
      inquote = !inquote;
    }
    else
    {
      ++*numchars;
      if ( v7 != nullptr )
      {
        *v7 = *cmdstart;
        args = v7 + 1;
      }
      v9 = *cmdstart;
      v17 = (unsigned __int8)*cmdstart++;
      if ( _ismbblead(tst: v17) != 0 )
      {
        ++*numchars;
        if ( args != nullptr )
        {
          v10 = args++;
          *v10 = *cmdstart;
        }
        ++cmdstart;
      }
      v7 = args;
      v5 = numargs;
      if ( v9 == 0 )
      {
        --cmdstart;
        goto LABEL_18;
      }
    }
  }
  while ( inquote || v9 != 32 && v9 != 9 );
  if ( v7 != nullptr )
    *(v7 - 1) = 0;
LABEL_18:
  inquotea = false;
  while ( *cmdstart != 0 )
  {
    while ( *cmdstart == 32 || *cmdstart == 9 )
      ++cmdstart;
    if ( *cmdstart == 0 )
      break;
    if ( argv != nullptr )
    {
      v11 = argv++;
      *v11 = v7;
    }
    ++*v5;
    while ( 1 )
    {
      v12 = 1;
      v13 = 0;
      while ( *cmdstart == 92 )
      {
        ++cmdstart;
        ++v13;
      }
      if ( *cmdstart == 34 )
      {
        if ( (v13 & 1) == 0 )
        {
          if ( inquotea && cmdstart[1] == 34 )
          {
            ++cmdstart;
          }
          else
          {
            v12 = 0;
            inquotea = !inquotea;
          }
        }
        v13 >>= 1;
      }
      if ( v13 != 0 )
      {
        do
        {
          --v13;
          if ( v7 != nullptr )
            *v7++ = 92;
          ++*numchars;
        }
        while ( v13 != 0 );
        args = v7;
      }
      v14 = *cmdstart;
      if ( *cmdstart == 0 || !inquotea && (v14 == 32 || v14 == 9) )
        break;
      if ( v12 != 0 )
      {
        if ( v7 != nullptr )
        {
          if ( _ismbblead(tst: v14) != 0 )
          {
            v15 = args++;
            *v15 = *cmdstart++;
            ++*numchars;
          }
          v16 = args++;
          *v16 = *cmdstart;
        }
        else if ( _ismbblead(tst: v14) != 0 )
        {
          ++cmdstart;
          ++*numchars;
        }
        ++*numchars;
        v7 = args;
      }
      ++cmdstart;
    }
    if ( v7 != nullptr )
    {
      *v7++ = 0;
      args = v7;
    }
    ++*numchars;
    v5 = numargs;
  }
  if ( argv != nullptr )
    *argv = nullptr;
  ++*v5;
}

//------------------------------------------------------------------------------
// Address: 0x1000F852
// Name: __setargv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setargv()
{
  bool v0; // zf
  int v1; // edi
  unsigned int v2; // eax
  char **v3; // esi
  int numchars; // [esp+Ch] [ebp-Ch] BYREF
  int numargs; // [esp+10h] [ebp-8h] BYREF
  char *cmdstart; // [esp+14h] [ebp-4h]

  if ( __mbctype_initialized == 0 )
    __initmbctable();
  pgmname[260] = 0;
  GetModuleFileNameA(hModule: nullptr, lpFilename: pgmname, nSize: 0x104u);
  _pgmptr = pgmname;
  if ( _acmdln == nullptr || (v0 = *_acmdln == 0, cmdstart = _acmdln, v0) )
    cmdstart = pgmname;
  parse_cmdline(cmdstart, &numchars, argv: nullptr, args: nullptr, &numargs);
  if ( (unsigned int)numargs >= 0x3FFFFFFF )
    return -1;
  if ( numchars == -1 )
    return -1;
  v1 = numargs;
  v2 = 4 * numargs + numchars;
  if ( v2 < numchars )
    return -1;
  v3 = (char **)operator new(nSize: v2);
  if ( v3 == nullptr )
    return -1;
  parse_cmdline(cmdstart, &numchars, argv: v3, args: (char *)&v3[v1], &numargs);
  __argc = numargs - 1;
  __argv = v3;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000F90B
// Name: ___crtGetEnvironmentStringsA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl __crtGetEnvironmentStringsA()
{
  int v0; // eax
  char *v1; // ebx
  WCHAR *EnvironmentStringsW; // esi
  WCHAR *i; // eax
  unsigned int v5; // eax
  int v6; // ebp
  char *v7; // eax
  LPCH EnvironmentStrings; // eax
  char *v9; // esi
  unsigned int v10; // ebp
  unsigned __int8 *v11; // eax
  unsigned __int8 *v12; // edi
  char *nSizeW; // [esp+10h] [ebp-8h]
  int cchWideChar; // [esp+14h] [ebp-4h]

  v0 = f_use;
  v1 = nullptr;
  EnvironmentStringsW = nullptr;
  if ( f_use == 0 )
  {
    EnvironmentStringsW = GetEnvironmentStringsW();
    if ( EnvironmentStringsW != nullptr )
    {
      f_use = 1;
      goto LABEL_8;
    }
    if ( GetLastError() == 120 )
    {
      v0 = 2;
      f_use = 2;
    }
    else
    {
      v0 = f_use;
    }
  }
  if ( v0 == 1 )
  {
LABEL_8:
    if ( EnvironmentStringsW == nullptr )
    {
      EnvironmentStringsW = GetEnvironmentStringsW();
      if ( EnvironmentStringsW == nullptr )
        return nullptr;
    }
    for ( i = EnvironmentStringsW; *i != 0; ++i )
    {
      do
        ++i;
      while ( *i != 0 );
    }
    cchWideChar = i - EnvironmentStringsW + 1;
    v5 = WideCharToMultiByte(
           CodePage: 0,
           dwFlags: 0,
           lpWideCharStr: EnvironmentStringsW,
           cchWideChar,
           lpMultiByteStr: nullptr,
           cbMultiByte: 0,
           lpDefaultChar: nullptr,
           lpUsedDefaultChar: nullptr);
    v6 = v5;
    if ( v5 != 0 )
    {
      v7 = (char *)operator new(nSize: v5);
      nSizeW = v7;
      if ( v7 != nullptr )
      {
        if ( WideCharToMultiByte(
               CodePage: 0,
               dwFlags: 0,
               lpWideCharStr: EnvironmentStringsW,
               cchWideChar,
               lpMultiByteStr: v7,
               cbMultiByte: v6,
               lpDefaultChar: nullptr,
               lpUsedDefaultChar: nullptr) == 0 )
        {
          free(pMem: nSizeW);
          nSizeW = nullptr;
        }
        v1 = nSizeW;
      }
    }
    FreeEnvironmentStringsW(penv: EnvironmentStringsW);
    return (unsigned __int8 *)v1;
  }
  if ( v0 != 2 && v0 != 0 )
    return nullptr;
  EnvironmentStrings = GetEnvironmentStrings();
  v9 = EnvironmentStrings;
  if ( EnvironmentStrings == nullptr )
    return nullptr;
  for ( ; *EnvironmentStrings != 0; ++EnvironmentStrings )
  {
    do
      ++EnvironmentStrings;
    while ( *EnvironmentStrings != 0 );
  }
  v10 = EnvironmentStrings - v9 + 1;
  v11 = (unsigned __int8 *)operator new(nSize: v10);
  v12 = v11;
  if ( v11 == nullptr )
  {
    FreeEnvironmentStringsA(penv: v9);
    return nullptr;
  }
  memcpy(dst: v11, src: (unsigned __int8 *)v9, count: v10);
  FreeEnvironmentStringsA(penv: v9);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x1000FA40
// Name: __RTC_Initialize
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _RTC_Initialize()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000FA64
// Name: __RTC_Terminate
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _RTC_Terminate()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000FA88
// Name: __initp_misc_winxfltr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_winxfltr()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1000FA89
// Name: __XcptFilter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _XcptFilter(unsigned int xcptnum, _EXCEPTION_POINTERS *pxcptinfoptrs)
{
  int result; // eax
  _DWORD *v3; // esi
  int *v4; // edx
  int *v5; // ecx
  int *v6; // eax
  void (__cdecl *v7)(int); // ebx
  int v8; // ecx
  int v9; // edx
  int v10; // ecx
  int v11; // eax
  int v12; // edi
  void *oldpxcptinfoptrs; // [esp+4h] [ebp-8h]

  result = (int)_getptd_noexit();
  v3 = (_DWORD *)result;
  if ( result != 0 )
  {
    v4 = *(int **)(result + 92);
    v5 = v4;
    do
    {
      if ( *v5 == xcptnum )
        break;
      v5 += 3;
    }
    while ( v5 < &v4[3 * _XcptActTabCount] );
    if ( v5 < &v4[3 * _XcptActTabCount] && *v5 == xcptnum )
      v6 = v5;
    else
      v6 = nullptr;
    if ( v6 != nullptr && (v7 = (void (__cdecl *)(int))v6[2]) != nullptr )
    {
      if ( v7 == (void (__cdecl *)(int))5 )
      {
        v6[2] = 0;
        return 1;
      }
      else
      {
        if ( v7 != (void (__cdecl *)(int))1 )
        {
          oldpxcptinfoptrs = (void *)v3[24];
          v3[24] = pxcptinfoptrs;
          v8 = v6[1];
          if ( v8 == 8 )
          {
            v9 = _First_FPE_Indx;
            if ( _First_FPE_Indx < _First_FPE_Indx + _Num_FPE )
            {
              v10 = 12 * _First_FPE_Indx;
              do
              {
                *(_DWORD *)(v10 + v3[23] + 8) = 0;
                ++v9;
                v10 += 12;
              }
              while ( v9 < _First_FPE_Indx + _Num_FPE );
            }
            v11 = *v6;
            v12 = v3[25];
            switch ( v11 )
            {
              case -1073741682:
                v3[25] = 131;
                break;
              case -1073741680:
                v3[25] = 129;
                break;
              case -1073741679:
                v3[25] = 132;
                break;
              case -1073741677:
                v3[25] = 133;
                break;
              case -1073741683:
                v3[25] = 130;
                break;
              case -1073741681:
                v3[25] = 134;
                break;
              case -1073741678:
                v3[25] = 138;
                break;
              default:
                break;
            }
            v7(a1: 8);
            v3[25] = v12;
          }
          else
          {
            v6[2] = 0;
            v7(a1: v8);
          }
          v3[24] = oldpxcptinfoptrs;
        }
        return -1;
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000FBE7
// Name: ___CppXcptFilter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __CppXcptFilter(unsigned int xcptnum, _EXCEPTION_POINTERS *pxcptinfoptrs)
{
  if ( xcptnum == -529697949 )
    return _XcptFilter(xcptnum: 0xE06D7363, pxcptinfoptrs);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000FC02
// Name: DllMain(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x1000FC4D
// Name: __SEH_epilog4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void _SEH_epilog4()
{
  __asm { retn }
}

//------------------------------------------------------------------------------
// Address: 0x1000FE06
// Name: ___security_init_cookie
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __security_init_cookie()
{
  unsigned int v0; // esi
  DWORD v1; // esi
  DWORD v2; // esi
  DWORD v3; // esi
  uintptr_t v4; // esi
  _LARGE_INTEGER perfctr; // [esp+8h] [ebp-10h] BYREF
  FT systime; // [esp+10h] [ebp-8h] BYREF

  systime.ft_scalar = 0;
  if ( __security_cookie == -1153374642 || (__security_cookie & 0xFFFF0000) == 0 )
  {
    GetSystemTimeAsFileTime(lpSystemTimeAsFileTime: (LPFILETIME)&systime);
    v0 = systime.ft_struct.dwLowDateTime ^ systime.ft_struct.dwHighDateTime;
    v1 = GetCurrentProcessId() ^ v0;
    v2 = GetCurrentThreadId() ^ v1;
    v3 = GetTickCount() ^ v2;
    QueryPerformanceCounter(lpPerformanceCount: &perfctr);
    v4 = perfctr.LowPart ^ perfctr.HighPart ^ v3;
    if ( v4 == -1153374642 )
    {
      v4 = -1153374641;
    }
    else if ( (v4 & 0xFFFF0000) == 0 )
    {
      v4 |= v4 << 16;
    }
    __security_cookie = v4;
    __security_cookie_complement = ~v4;
  }
  else
  {
    __security_cookie_complement = ~__security_cookie;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FE9A
// Name: CPtoLCID
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall CPtoLCID@<eax>(int codepage@<eax>)
{
  int v1; // eax
  int v2; // eax
  int v3; // eax

  v1 = codepage - 932;
  if ( v1 == 0 )
    return 1041;
  v2 = v1 - 4;
  if ( v2 == 0 )
    return 2052;
  v3 = v2 - 13;
  if ( v3 == 0 )
    return 1042;
  if ( v3 == 1 )
    return 1028;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000FEC9
// Name: setSBCS
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall setSBCS(threadmbcinfostruct *ptmbci@<eax>)
{
  int v1; // ebp
  unsigned __int8 *mbctype; // ebx
  int v4; // eax
  unsigned __int8 *mbcasemap; // ecx
  int i; // esi

  v1 = 257;
  mbctype = ptmbci->mbctype;
  memset(dst: (int)ptmbci->mbctype, value: nullptr, count: sizeof(ptmbci->mbctype));
  ptmbci->mbcodepage = 0;
  ptmbci->ismbcodepage = 0;
  ptmbci->mblcid = 0;
  *(_DWORD *)ptmbci->mbulinfo = 0;
  *(_DWORD *)&ptmbci->mbulinfo[2] = 0;
  *(_DWORD *)&ptmbci->mbulinfo[4] = 0;
  v4 = (char *)&__initialmbcinfo - (char *)ptmbci;
  do
  {
    *mbctype = mbctype[v4];
    ++mbctype;
    --v1;
  }
  while ( v1 != 0 );
  mbcasemap = ptmbci->mbcasemap;
  for ( i = 256; i != 0; --i )
  {
    *mbcasemap = mbcasemap[v4];
    ++mbcasemap;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000FF1E
// Name: setSBUpLow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall setSBUpLow(threadmbcinfostruct *ptmbci@<esi>)
{
  unsigned int i; // eax
  unsigned __int8 v2; // al
  unsigned __int8 *v3; // ebx
  unsigned int v4; // ecx
  unsigned int v5; // eax
  unsigned __int8 *v6; // ebx
  int v7; // eax
  unsigned __int16 v8; // cx
  unsigned __int8 v9; // cl
  unsigned int v10; // ecx
  unsigned __int8 *v11; // eax
  unsigned __int8 v12; // dl
  int v13; // [esp+8h] [ebp-80h]
  _cpinfo cpinfo; // [esp+Ch] [ebp-7Ch] BYREF
  unsigned __int16 wVector[256]; // [esp+20h] [ebp-68h] BYREF
  unsigned __int8 upVector[256]; // [esp+220h] [ebp+198h] BYREF
  unsigned __int8 lowVector[256]; // [esp+320h] [ebp+298h] BYREF
  unsigned __int8 sbVector[256]; // [esp+420h] [ebp+398h] BYREF

  if ( GetCPInfo(CodePage: ptmbci->mbcodepage, lpCPInfo: &cpinfo) )
  {
    for ( i = 0; i < 0x100; ++i )
      sbVector[i] = i;
    v2 = cpinfo.LeadByte[0];
    sbVector[0] = 32;
    if ( cpinfo.LeadByte[0] != 0 )
    {
      v3 = &cpinfo.LeadByte[1];
      do
      {
        v4 = v2;
        v5 = *v3;
        if ( v4 <= v5 )
          memset(dst: (int)&sbVector[v4], value: (unsigned __int8 *)0x20, count: v5 - v4 + 1);
        v6 = v3 + 1;
        v2 = *v6;
        v3 = v6 + 1;
      }
      while ( v2 != 0 );
    }
    __crtGetStringTypeA(
      plocinfo: nullptr,
      dwInfoType: 1u,
      lpSrcStr: (const char *)sbVector,
      cchSrc: 256,
      lpCharType: wVector,
      code_page: ptmbci->mbcodepage,
      lcid: ptmbci->mblcid,
      bError: 0);
    __crtLCMapStringA(
      plocinfo: nullptr,
      Locale: ptmbci->mblcid,
      dwMapFlags: 0x100u,
      lpSrcStr: (const char *)sbVector,
      cchSrc: 256,
      lpDestStr: (char *)lowVector,
      cchDest: 256,
      code_page: ptmbci->mbcodepage,
      bError: 0);
    __crtLCMapStringA(
      plocinfo: nullptr,
      Locale: ptmbci->mblcid,
      dwMapFlags: 0x200u,
      lpSrcStr: (const char *)sbVector,
      cchSrc: 256,
      lpDestStr: (char *)upVector,
      cchDest: 256,
      code_page: ptmbci->mbcodepage,
      bError: 0);
    v7 = 0;
    while ( 1 )
    {
      v8 = wVector[v7];
      if ( (v8 & 1) != 0 )
      {
        ptmbci->mbctype[v7 + 1] |= 0x10u;
        v9 = lowVector[v7];
      }
      else
      {
        if ( (v8 & 2) == 0 )
        {
          ptmbci->mbcasemap[v7] = 0;
          goto LABEL_16;
        }
        ptmbci->mbctype[v7 + 1] |= 0x20u;
        v9 = upVector[v7];
      }
      ptmbci->mbcasemap[v7] = v9;
LABEL_16:
      if ( (unsigned int)++v7 >= 0x100 )
        return;
    }
  }
  v10 = 0;
  v13 = -97 - (_DWORD)ptmbci->mbcasemap;
  do
  {
    v11 = &ptmbci->mbcasemap[v10];
    if ( (unsigned int)&v11[v13 + 32] <= 0x19 )
    {
      ptmbci->mbctype[v10 + 1] |= 0x10u;
      v12 = v10 + 32;
LABEL_23:
      *v11 = v12;
      goto LABEL_25;
    }
    if ( (unsigned int)&v11[v13] <= 0x19 )
    {
      ptmbci->mbctype[v10 + 1] |= 0x20u;
      v12 = v10 - 32;
      goto LABEL_23;
    }
    *v11 = 0;
LABEL_25:
    ++v10;
  }
  while ( v10 < 0x100 );
}

//------------------------------------------------------------------------------
// Address: 0x100100A8
// Name: ___updatetmbcinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadmbcinfostruct *__cdecl __updatetmbcinfo()
{
  _tiddata *v0; // edi
  threadmbcinfostruct *ptmbcinfo; // esi

  v0 = _getptd();
  if ( (__globallocalestatus & v0->_ownlocale) != 0 && v0->ptlocinfo != nullptr )
  {
    ptmbcinfo = v0->ptmbcinfo;
  }
  else
  {
    _lock(locknum: 13);
    ptmbcinfo = v0->ptmbcinfo;
    if ( ptmbcinfo != __ptmbcinfo )
    {
      if ( ptmbcinfo != nullptr
        && InterlockedDecrement(lpAddend: &ptmbcinfo->refcount) == 0
        && ptmbcinfo != &__initialmbcinfo )
      {
        free(pMem: ptmbcinfo);
      }
      v0->ptmbcinfo = __ptmbcinfo;
      ptmbcinfo = __ptmbcinfo;
      InterlockedIncrement(lpAddend: &__ptmbcinfo->refcount);
    }
    _unlock(locknum: 13);
  }
  if ( ptmbcinfo == nullptr )
    _amsg_exit(rterrnum: 32);
  return ptmbcinfo;
}

//------------------------------------------------------------------------------
// Address: 0x1001014C
// Name: getSystemCP
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UINT __usercall getSystemCP@<eax>(int codepage@<esi>)
{
  UINT result; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo: nullptr);
  fSystemSet = 0;
  switch ( codepage )
  {
    case -2:
      fSystemSet = 1;
      result = GetOEMCP();
      goto LABEL_3;
    case -3:
      fSystemSet = 1;
      result = GetACP();
      goto LABEL_3;
    case -4:
      result = _loc_update.localeinfo.locinfo->lc_codepage;
      fSystemSet = 1;
LABEL_3:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    default:
      break;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return codepage;
}

//------------------------------------------------------------------------------
// Address: 0x100101C6
// Name: __setmbcp_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setmbcp_nolock(int codepage, threadmbcinfostruct *ptmbci)
{
  UINT SystemCP; // edi
  unsigned int i; // eax
  bool v5; // cc
  unsigned __int8 *v6; // esi
  unsigned __int8 v7; // cl
  unsigned int k; // eax
  unsigned __int8 *v9; // esi
  unsigned int v10; // eax
  unsigned int v11; // edi
  unsigned __int16 *mbulinfo; // eax
  int v13; // ecx
  unsigned __int16 *v14; // ecx
  int j; // edx
  unsigned __int8 *v16; // eax
  int m; // ecx
  int v18; // edx
  unsigned int irg; // [esp+Ch] [ebp-20h]
  unsigned int icp; // [esp+10h] [ebp-1Ch]
  unsigned int icpa; // [esp+10h] [ebp-1Ch]
  _cpinfo cpinfo; // [esp+14h] [ebp-18h] BYREF
  int codepagea; // [esp+34h] [ebp+8h]

  SystemCP = getSystemCP(codepage);
  codepagea = SystemCP;
  if ( SystemCP != 0 )
  {
    icp = 0;
    for ( i = 0; i < 5; ++i )
    {
      if ( _rgcode_page_info[i].code_page == SystemCP )
      {
        memset(dst: (int)ptmbci->mbctype, value: nullptr, count: sizeof(ptmbci->mbctype));
        irg = 0;
        v9 = _rgcode_page_info[icp].rgrange[0];
        icpa = (unsigned int)v9;
        do
        {
          while ( *v9 != 0 )
          {
            LOBYTE(v10) = v9[1];
            if ( (_BYTE)v10 == 0 )
              break;
            v11 = *v9;
            v10 = (unsigned __int8)v10;
            while ( v11 <= v10 )
            {
              ptmbci->mbctype[v11 + 1] |= _rgctypeflag[irg];
              v10 = v9[1];
              ++v11;
            }
            SystemCP = codepagea;
            v9 += 2;
          }
          ++irg;
          v9 = (unsigned __int8 *)(icpa + 8);
          icpa += 8;
        }
        while ( irg < 4 );
        ptmbci->mbcodepage = SystemCP;
        ptmbci->ismbcodepage = 1;
        ptmbci->mblcid = CPtoLCID(codepage: SystemCP);
        mbulinfo = ptmbci->mbulinfo;
        v14 = (unsigned __int16 *)((char *)_rgcode_page_info[0].mbulinfo + v13);
        for ( j = 6; j != 0; --j )
          *mbulinfo++ = *v14++;
LABEL_26:
        setSBUpLow(ptmbci);
        return 0;
      }
      ++icp;
    }
    if ( SystemCP == 65000 || SystemCP == 65001 || !IsValidCodePage(CodePage: (unsigned __int16)SystemCP) )
      return -1;
    if ( GetCPInfo(CodePage: SystemCP, lpCPInfo: &cpinfo) )
    {
      memset(dst: (int)ptmbci->mbctype, value: nullptr, count: sizeof(ptmbci->mbctype));
      v5 = cpinfo.MaxCharSize <= 1;
      ptmbci->mbcodepage = SystemCP;
      ptmbci->mblcid = 0;
      if ( v5 )
      {
        ptmbci->ismbcodepage = 0;
      }
      else
      {
        if ( cpinfo.LeadByte[0] != 0 )
        {
          v6 = &cpinfo.LeadByte[1];
          do
          {
            v7 = *v6;
            if ( *v6 == 0 )
              break;
            for ( k = *(v6 - 1); k <= v7; ++k )
              ptmbci->mbctype[k + 1] |= 4u;
            v6 += 2;
          }
          while ( *(v6 - 1) != 0 );
        }
        v16 = &ptmbci->mbctype[2];
        for ( m = 254; m != 0; --m )
          *v16++ |= 8u;
        ptmbci->mblcid = CPtoLCID(codepage: ptmbci->mbcodepage);
        ptmbci->ismbcodepage = v18;
      }
      *(_DWORD *)ptmbci->mbulinfo = 0;
      *(_DWORD *)&ptmbci->mbulinfo[2] = 0;
      *(_DWORD *)&ptmbci->mbulinfo[4] = 0;
      goto LABEL_26;
    }
    if ( fSystemSet == 0 )
      return -1;
  }
  setSBCS(ptmbci);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001039F
// Name: __setmbcp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setmbcp(int codepage)
{
  _tiddata *v1; // edi
  threadmbcinfostruct *ptmbcinfo; // ebx
  threadmbcinfostruct *v3; // eax
  threadmbcinfostruct *v4; // ebx
  int v5; // eax
  int i; // eax
  int j; // eax
  int k; // eax
  int retcode; // [esp+14h] [ebp-20h]
  UINT codepagea; // [esp+3Ch] [ebp+8h]

  retcode = -1;
  v1 = _getptd();
  __updatetmbcinfo();
  ptmbcinfo = v1->ptmbcinfo;
  codepagea = getSystemCP(codepage);
  if ( codepagea == ptmbcinfo->mbcodepage )
    return 0;
  v3 = (threadmbcinfostruct *)operator new(nSize: 0x220u);
  v4 = v3;
  if ( v3 != nullptr )
  {
    qmemcpy(v3, v1->ptmbcinfo, sizeof(threadmbcinfostruct));
    v3->refcount = 0;
    v5 = _setmbcp_nolock(codepage: codepagea, ptmbci: v3);
    retcode = v5;
    if ( v5 != 0 )
    {
      if ( v5 == -1 )
      {
        if ( v4 != &__initialmbcinfo )
          free(pMem: v4);
        *_errno() = 22;
      }
    }
    else
    {
      if ( InterlockedDecrement(lpAddend: &v1->ptmbcinfo->refcount) == 0 && v1->ptmbcinfo != &__initialmbcinfo )
        free(pMem: v1->ptmbcinfo);
      v1->ptmbcinfo = v4;
      InterlockedIncrement(lpAddend: &v4->refcount);
      if ( (v1->_ownlocale & 2) == 0 && (__globallocalestatus & 1) == 0 )
      {
        _lock(locknum: 13);
        __mbcodepage = v4->mbcodepage;
        __ismbcodepage = v4->ismbcodepage;
        __mblcid = v4->mblcid;
        for ( i = 0; i < 5; ++i )
          __mbulinfo[i] = v4->mbulinfo[i];
        for ( j = 0; j < 257; ++j )
          _mbctype[j] = v4->mbctype[j];
        for ( k = 0; k < 256; ++k )
          _mbcasemap[k] = v4->mbcasemap[k];
        if ( InterlockedDecrement(lpAddend: &__ptmbcinfo->refcount) == 0 && __ptmbcinfo != &__initialmbcinfo )
          free(pMem: __ptmbcinfo);
        __ptmbcinfo = v4;
        InterlockedIncrement(lpAddend: &v4->refcount);
        _unlock(locknum: 13);
      }
    }
  }
  return retcode;
}

//------------------------------------------------------------------------------
// Address: 0x10010539
// Name: ___initmbctable
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __initmbctable()
{
  if ( __mbctype_initialized == 0 )
  {
    _setmbcp(codepage: -3);
    __mbctype_initialized = 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10010557
// Name: ___freetlocinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __freetlocinfo(threadlocaleinfostruct *ptloci)
{
  lconv *lconv; // eax
  int *lconv_intl_refcount; // eax
  int *lconv_mon_refcount; // eax
  int *lconv_num_refcount; // eax
  int *ctype1_refcount; // eax
  __lc_time_data *lc_time_curr; // eax
  void **p_refcount; // edi
  int i; // ebx
  _DWORD *v9; // eax

  lconv = ptloci->lconv;
  if ( lconv != nullptr && lconv != &__lconv_c )
  {
    lconv_intl_refcount = ptloci->lconv_intl_refcount;
    if ( lconv_intl_refcount != nullptr && *lconv_intl_refcount == 0 )
    {
      lconv_mon_refcount = ptloci->lconv_mon_refcount;
      if ( lconv_mon_refcount != nullptr && *lconv_mon_refcount == 0 )
      {
        free(pMem: ptloci->lconv_mon_refcount);
        __free_lconv_mon(l: ptloci->lconv);
      }
      lconv_num_refcount = ptloci->lconv_num_refcount;
      if ( lconv_num_refcount != nullptr && *lconv_num_refcount == 0 )
      {
        free(pMem: ptloci->lconv_num_refcount);
        __free_lconv_num(l: ptloci->lconv);
      }
      free(pMem: ptloci->lconv_intl_refcount);
      free(pMem: ptloci->lconv);
    }
  }
  ctype1_refcount = ptloci->ctype1_refcount;
  if ( ctype1_refcount != nullptr && *ctype1_refcount == 0 )
  {
    free(pMem: ptloci->ctype1 - 127);
    free(pMem: (void *)(ptloci->pclmap - 128));
    free(pMem: (void *)(ptloci->pcumap - 128));
    free(pMem: ptloci->ctype1_refcount);
  }
  lc_time_curr = ptloci->lc_time_curr;
  if ( lc_time_curr != &__lc_time_c && lc_time_curr->refcount == 0 )
  {
    __free_lc_time(lc_time: ptloci->lc_time_curr);
    free(pMem: ptloci->lc_time_curr);
  }
  p_refcount = (void **)&ptloci->lc_category[0].refcount;
  for ( i = 6; i != 0; --i )
  {
    if ( *(p_refcount - 2) != __clocalestr && *p_refcount != nullptr && *(_DWORD *)*p_refcount == 0 )
      free(pMem: *p_refcount);
    if ( *(p_refcount - 1) != nullptr )
    {
      v9 = p_refcount[1];
      if ( v9 != nullptr && *v9 == 0 )
        free(pMem: p_refcount[1]);
    }
    p_refcount += 4;
  }
  free(pMem: ptloci);
}

//------------------------------------------------------------------------------
// Address: 0x10010697
// Name: ___addlocaleref
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __addlocaleref(threadlocaleinfostruct *ptloci)
{
  volatile LONG **p_refcount; // ebx
  int i; // ebp

  InterlockedIncrement(lpAddend: &ptloci->refcount);
  if ( ptloci->lconv_intl_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->lconv_intl_refcount);
  if ( ptloci->lconv_mon_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->lconv_mon_refcount);
  if ( ptloci->lconv_num_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->lconv_num_refcount);
  if ( ptloci->ctype1_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->ctype1_refcount);
  p_refcount = (volatile LONG **)&ptloci->lc_category[0].refcount;
  for ( i = 6; i != 0; --i )
  {
    if ( *(p_refcount - 2) != (volatile LONG *)__clocalestr && *p_refcount != nullptr )
      InterlockedIncrement(lpAddend: *p_refcount);
    if ( *(p_refcount - 1) != nullptr && p_refcount[1] != nullptr )
      InterlockedIncrement(lpAddend: p_refcount[1]);
    p_refcount += 4;
  }
  InterlockedIncrement(lpAddend: &ptloci->lc_time_curr->refcount);
}

//------------------------------------------------------------------------------
// Address: 0x1001071D
// Name: ___removelocaleref
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadlocaleinfostruct *__cdecl __removelocaleref(threadlocaleinfostruct *ptloci)
{
  volatile LONG **p_refcount; // ebx
  int i; // ebp

  if ( ptloci != nullptr )
  {
    InterlockedDecrement(lpAddend: &ptloci->refcount);
    if ( ptloci->lconv_intl_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->lconv_intl_refcount);
    if ( ptloci->lconv_mon_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->lconv_mon_refcount);
    if ( ptloci->lconv_num_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->lconv_num_refcount);
    if ( ptloci->ctype1_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->ctype1_refcount);
    p_refcount = (volatile LONG **)&ptloci->lc_category[0].refcount;
    for ( i = 6; i != 0; --i )
    {
      if ( *(p_refcount - 2) != (volatile LONG *)__clocalestr && *p_refcount != nullptr )
        InterlockedDecrement(lpAddend: *p_refcount);
      if ( *(p_refcount - 1) != nullptr && p_refcount[1] != nullptr )
        InterlockedDecrement(lpAddend: p_refcount[1]);
      p_refcount += 4;
    }
    InterlockedDecrement(lpAddend: &ptloci->lc_time_curr->refcount);
  }
  return ptloci;
}

//------------------------------------------------------------------------------
// Address: 0x100107A9
// Name: _updatetlocinfoEx_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadlocaleinfostruct *__usercall updatetlocinfoEx_nolock@<eax>(
        threadlocaleinfostruct **pptlocid@<eax>,
        threadlocaleinfostruct *ptlocis@<edi>)
{
  threadlocaleinfostruct *v2; // esi

  if ( ptlocis == nullptr || pptlocid == nullptr )
    return nullptr;
  v2 = *pptlocid;
  if ( *pptlocid != ptlocis )
  {
    *pptlocid = ptlocis;
    __addlocaleref(ptloci: ptlocis);
    if ( v2 != nullptr )
    {
      __removelocaleref(ptloci: v2);
      if ( v2->refcount == 0 && v2 != &__initiallocinfo )
        __freetlocinfo(ptloci: v2);
    }
  }
  return ptlocis;
}

//------------------------------------------------------------------------------
// Address: 0x100107E7
// Name: ___updatetlocinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadlocaleinfostruct *__cdecl __updatetlocinfo()
{
  _tiddata *v0; // esi
  threadlocaleinfostruct *ptlocinfo; // esi
  threadlocaleinfostruct *ptloci; // [esp+10h] [ebp-1Ch]

  v0 = _getptd();
  if ( (__globallocalestatus & v0->_ownlocale) != 0 && v0->ptlocinfo != nullptr )
  {
    ptlocinfo = _getptd()->ptlocinfo;
  }
  else
  {
    _lock(locknum: 12);
    ptloci = updatetlocinfoEx_nolock(pptlocid: &v0->ptlocinfo, ptlocis: __ptlocinfo);
    _unlock(locknum: 12);
    ptlocinfo = ptloci;
  }
  if ( ptlocinfo == nullptr )
    _amsg_exit(rterrnum: 32);
  return ptlocinfo;
}

//------------------------------------------------------------------------------
// Address: 0x1001085D
// Name: __security_check_cookie(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall __security_check_cookie(uintptr_t StackCookie)
{
  if ( StackCookie != __security_cookie )
    __report_gsfailure();
}

//------------------------------------------------------------------------------
// Address: 0x1001086C
// Name: __crtLCMapStringA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _crtLCMapStringA_stat(
        unsigned int Locale,
        DWORD dwMapFlags,
        const char *lpSrcStr,
        int cchSrc,
        char *lpDestStr,
        int cchDest,
        unsigned int code_page,
        int bError)
{
  localeinfo_struct *plocinfo; // ecx
  localeinfo_struct *v9; // esi
  int v10; // ecx
  const char *v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // edi
  unsigned int v15; // eax
  void *v16; // esp
  wchar_t *v17; // eax
  int v18; // eax
  int v19; // ecx
  unsigned int v20; // eax
  void *v21; // esp
  WCHAR *v22; // esi
  WCHAR *v23; // eax
  int v24; // eax
  int v26; // eax
  wchar_t *v27; // eax
  int v28; // eax
  int v29; // esi
  unsigned int v30; // eax
  void *v31; // esp
  char *v32; // edi
  char *v33; // eax
  _DWORD v34[2]; // [esp+0h] [ebp-20h] BYREF
  int v35; // [esp+8h] [ebp-18h] BYREF
  int AnsiCP; // [esp+Ch] [ebp-14h]
  char *cbuffer2; // [esp+10h] [ebp-10h]
  wchar_t *inwbuffer; // [esp+14h] [ebp-Ch]
  int retval; // [esp+18h] [ebp-8h] BYREF

  v9 = plocinfo;
  if ( f_use_0 == 0 )
  {
    if ( LCMapStringW(Locale: 0, dwMapFlags: 0x100u, lpSrcStr: &SrcStr, cchSrc: 1, lpDestStr: nullptr, cchDest: 0) != 0 )
    {
      f_use_0 = 1;
    }
    else if ( GetLastError() == 120 )
    {
      f_use_0 = 2;
    }
  }
  if ( cchSrc > 0 )
  {
    v10 = cchSrc;
    v11 = lpSrcStr;
    while ( 1 )
    {
      --v10;
      if ( *v11 == 0 )
        break;
      ++v11;
      if ( v10 == 0 )
      {
        v10 = -1;
        break;
      }
    }
    v12 = cchSrc - v10 - 1;
    if ( v12 < cchSrc )
      v12 = cchSrc - v10;
    cchSrc = v12;
  }
  if ( f_use_0 != 2 && f_use_0 != 0 )
  {
    if ( f_use_0 == 1 )
    {
      retval = 0;
      if ( code_page == 0 )
        code_page = v9->locinfo->lc_codepage;
      v13 = MultiByteToWideChar(
              CodePage: code_page,
              dwFlags: 8 * (bError != 0) + 1,
              lpMultiByteStr: lpSrcStr,
              cbMultiByte: cchSrc,
              lpWideCharStr: nullptr,
              cchWideChar: 0);
      v14 = v13;
      if ( v13 != 0 )
      {
        if ( v13 <= 0 || 0xFFFFFFE0 / v13 < 2 )
        {
          inwbuffer = nullptr;
LABEL_30:
          if ( inwbuffer != nullptr )
          {
            if ( MultiByteToWideChar(
                   CodePage: code_page,
                   dwFlags: 1u,
                   lpMultiByteStr: lpSrcStr,
                   cbMultiByte: cchSrc,
                   lpWideCharStr: inwbuffer,
                   cchWideChar: v14) != 0 )
            {
              v18 = LCMapStringW(Locale, dwMapFlags, lpSrcStr: inwbuffer, cchSrc: v14, lpDestStr: nullptr, cchDest: 0);
              v19 = v18;
              retval = v18;
              if ( v18 != 0 )
              {
                if ( (dwMapFlags & 0x400) != 0 )
                {
                  if ( cchDest != 0 && v18 <= cchDest )
                    LCMapStringW(Locale, dwMapFlags, lpSrcStr: inwbuffer, cchSrc: v14, (LPWSTR)lpDestStr, cchDest);
                  goto LABEL_53;
                }
                if ( v18 <= 0 || 0xFFFFFFE0 / v18 < 2 )
                {
                  v22 = nullptr;
LABEL_46:
                  if ( v22 != nullptr )
                  {
                    if ( LCMapStringW(
                           Locale,
                           dwMapFlags,
                           lpSrcStr: inwbuffer,
                           cchSrc: v14,
                           lpDestStr: v22,
                           cchDest: retval) != 0 )
                    {
                      if ( cchDest != 0 )
                        v24 = WideCharToMultiByte(
                                CodePage: code_page,
                                dwFlags: 0,
                                lpWideCharStr: v22,
                                cchWideChar: retval,
                                lpMultiByteStr: lpDestStr,
                                cbMultiByte: cchDest,
                                lpDefaultChar: nullptr,
                                lpUsedDefaultChar: nullptr);
                      else
                        v24 = WideCharToMultiByte(
                                CodePage: code_page,
                                dwFlags: 0,
                                lpWideCharStr: v22,
                                cchWideChar: retval,
                                lpMultiByteStr: nullptr,
                                cbMultiByte: 0,
                                lpDefaultChar: nullptr,
                                lpUsedDefaultChar: nullptr);
                      retval = v24;
                    }
                    _freea(_Memory: v22);
                  }
                  goto LABEL_53;
                }
                v20 = 2 * v18 + 8;
                if ( v20 > 0x400 )
                {
                  v23 = (WCHAR *)operator new(nSize: 2 * v19 + 8);
                  if ( v23 != nullptr )
                  {
                    *(_DWORD *)v23 = 56797;
                    v23 += 4;
                  }
                  v22 = v23;
                  goto LABEL_46;
                }
                v21 = alloca(v20);
                if ( v34 != nullptr )
                {
                  v34[0] = 52428;
                  v22 = (WCHAR *)&v35;
                  goto LABEL_46;
                }
              }
            }
LABEL_53:
            _freea(_Memory: inwbuffer);
            return retval;
          }
          return 0;
        }
        v15 = 2 * v13 + 8;
        if ( v15 > 0x400 )
        {
          v17 = (wchar_t *)operator new(nSize: 2 * v14 + 8);
          if ( v17 != nullptr )
          {
            *(_DWORD *)v17 = 56797;
            goto LABEL_27;
          }
        }
        else
        {
          v16 = alloca(v15);
          v17 = (wchar_t *)v34;
          if ( v34 != nullptr )
          {
            v34[0] = 52428;
LABEL_27:
            v17 += 4;
          }
        }
        inwbuffer = v17;
        goto LABEL_30;
      }
    }
    return 0;
  }
  inwbuffer = nullptr;
  cbuffer2 = nullptr;
  if ( Locale == 0 )
    Locale = v9->locinfo->lc_handle[2];
  if ( code_page == 0 )
    code_page = v9->locinfo->lc_codepage;
  v26 = __ansicp(lcid: Locale);
  AnsiCP = v26;
  if ( v26 == -1 )
    return 0;
  if ( v26 == code_page )
  {
    v29 = LCMapStringA(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest);
    goto LABEL_78;
  }
  v27 = (wchar_t *)__convertcp(fromCP: code_page, toCP: v26, lpSrcStr, pcchSrc: &cchSrc, lpDestStr: nullptr, cchDest: 0);
  inwbuffer = v27;
  if ( v27 == nullptr )
    return 0;
  v28 = LCMapStringA(Locale, dwMapFlags, lpSrcStr: (LPCSTR)v27, cchSrc, lpDestStr: nullptr, cchDest: 0);
  retval = v28;
  if ( v28 != 0 )
  {
    if ( v28 <= 0 )
    {
      v32 = nullptr;
    }
    else
    {
      v30 = v28 + 8;
      if ( v30 > 0x400 )
      {
        v33 = (char *)operator new(nSize: v30);
        if ( v33 != nullptr )
        {
          *(_DWORD *)v33 = 56797;
          v33 += 8;
        }
        v32 = v33;
      }
      else
      {
        v31 = alloca(v30);
        if ( v34 == nullptr )
          goto LABEL_63;
        v34[0] = 52428;
        v32 = (char *)&v35;
      }
    }
    if ( v32 != nullptr )
    {
      memset(dst: (int)v32, value: nullptr, count: retval);
      retval = LCMapStringA(Locale, dwMapFlags, lpSrcStr: (LPCSTR)inwbuffer, cchSrc, lpDestStr: v32, cchDest: retval);
      if ( retval != 0 )
      {
        cbuffer2 = __convertcp(fromCP: AnsiCP, toCP: code_page, lpSrcStr: v32, pcchSrc: &retval, lpDestStr, cchDest);
        v29 = cbuffer2 != nullptr ? retval : 0;
      }
      else
      {
        v29 = 0;
      }
      _freea(_Memory: v32);
      goto LABEL_78;
    }
  }
LABEL_63:
  v29 = 0;
LABEL_78:
  if ( inwbuffer != nullptr )
    free(pMem: inwbuffer);
  if ( cbuffer2 != nullptr && lpDestStr != cbuffer2 )
    free(pMem: cbuffer2);
  return v29;
}

//------------------------------------------------------------------------------
// Address: 0x10010C0E
// Name: ___crtLCMapStringA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtLCMapStringA(
        localeinfo_struct *plocinfo,
        unsigned int Locale,
        DWORD dwMapFlags,
        const char *lpSrcStr,
        int cchSrc,
        char *lpDestStr,
        int cchDest,
        unsigned int code_page,
        int bError)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtLCMapStringA_stat(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest, code_page, bError);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10010C51
// Name: __isleadbyte_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isleadbyte_l(unsigned __int8 c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _loc_update.localeinfo.locinfo->pctype[c] & 0x8000;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10010C87
// Name: _isleadbyte
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isleadbyte(unsigned __int8 c)
{
  return _isleadbyte_l(c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10010C95
// Name: __isctype_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isctype_l(int c, int mask, localeinfo_struct *plocinfo)
{
  __int16 v3; // bx
  int v4; // eax
  int v5; // ecx
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  char buffer[4]; // [esp+14h] [ebp-8h] BYREF
  unsigned __int16 chartype; // [esp+18h] [ebp-4h] BYREF
  int ca; // [esp+24h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v3 = c;
  if ( (unsigned int)(c + 1) <= 0x100 )
  {
    v4 = _loc_update.localeinfo.locinfo->pctype[c];
    goto LABEL_11;
  }
  ca = c >> 8;
  if ( _isleadbyte_l(c: HIBYTE(v3), plocinfo: &_loc_update.localeinfo) != 0 )
  {
    buffer[0] = ca;
    buffer[1] = v3;
    buffer[2] = 0;
    v5 = 2;
  }
  else
  {
    buffer[0] = v3;
    buffer[1] = 0;
    v5 = 1;
  }
  if ( __crtGetStringTypeA(
         plocinfo: &_loc_update.localeinfo,
         dwInfoType: 1u,
         lpSrcStr: buffer,
         cchSrc: v5,
         lpCharType: &chartype,
         code_page: _loc_update.localeinfo.locinfo->lc_codepage,
         lcid: _loc_update.localeinfo.locinfo->lc_handle[2],
         bError: 1) != 0 )
  {
    v4 = chartype;
LABEL_11:
    result = mask & v4;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10010D4B
// Name: __getdrive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _getdrive()
{
  unsigned __int8 *v0; // ebx
  signed int CurrentDirectoryA; // esi
  char *v2; // eax
  int v3; // edi
  int memfree; // [esp+10h] [ebp-7Ch]
  char curdirstr[264]; // [esp+14h] [ebp-78h] BYREF

  memfree = 0;
  v0 = (unsigned __int8 *)curdirstr;
  CurrentDirectoryA = GetCurrentDirectoryA(nBufferLength: 0x105u, lpBuffer: curdirstr);
  if ( CurrentDirectoryA > 260 )
  {
    v2 = (char *)calloc(count: CurrentDirectoryA + 1, size: 1u);
    v0 = (unsigned __int8 *)v2;
    if ( v2 != nullptr )
    {
      memfree = 1;
      CurrentDirectoryA = GetCurrentDirectoryA(nBufferLength: CurrentDirectoryA + 1, lpBuffer: v2);
    }
    else
    {
      *_errno() = 12;
      CurrentDirectoryA = 0;
    }
  }
  v3 = 0;
  if ( CurrentDirectoryA != 0 )
  {
    if ( v0[1] == 58 )
      v3 = toupper(c: *v0) - 64;
  }
  else
  {
    *_errno() = 12;
  }
  if ( memfree != 0 )
    free(pMem: v0);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10010E11
// Name: __mtinitlocks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mtinitlocks()
{
  int v0; // esi
  _RTL_CRITICAL_SECTION *v1; // edi
  LPCRITICAL_SECTION *v2; // eax

  v0 = 0;
  v1 = lclcritsects;
  while ( 1 )
  {
    if ( *(&locktable + 2 * v0 + 1) == (LPCRITICAL_SECTION)1 )
    {
      v2 = &locktable + 2 * v0;
      *v2 = v1++;
      if ( __crtInitCritSecAndSpinCount(lpCriticalSection: *v2, dwSpinCount: 0xFA0u) == 0 )
        break;
    }
    if ( ++v0 >= 36 )
      return 1;
  }
  *(&locktable + 2 * v0) = nullptr;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10010E5A
// Name: __mtdeletelocks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _mtdeletelocks()
{
  LPCRITICAL_SECTION *v0; // esi
  LPCRITICAL_SECTION v1; // edi
  LPCRITICAL_SECTION *v2; // esi

  v0 = &locktable;
  do
  {
    v1 = *v0;
    if ( *v0 != nullptr && v0[1] != (LPCRITICAL_SECTION)1 )
    {
      DeleteCriticalSection(lpCriticalSection: *v0);
      free(pMem: v1);
      *v0 = nullptr;
    }
    v0 += 2;
  }
  while ( (int)v0 < (int)dword_10038888 );
  v2 = &locktable;
  do
  {
    if ( *v2 != nullptr && v2[1] == (LPCRITICAL_SECTION)1 )
      DeleteCriticalSection(lpCriticalSection: *v2);
    v2 += 2;
  }
  while ( (int)v2 < (int)dword_10038888 );
}

//------------------------------------------------------------------------------
// Address: 0x10010EAF
// Name: __unlock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock(int locknum)
{
  LeaveCriticalSection(lpCriticalSection: *(&locktable + 2 * locknum));
}

//------------------------------------------------------------------------------
// Address: 0x10010EC4
// Name: __mtinitlocknum
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mtinitlocknum(int locknum)
{
  LPCRITICAL_SECTION *v1; // esi
  _RTL_CRITICAL_SECTION *v3; // edi
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 1;
  if ( _crtheap == nullptr )
  {
    _FF_MSGBANNER();
    _NMSG_WRITE(rterrnum: 30);
    __crtExitProcess(status: 255);
  }
  v1 = &locktable + 2 * locknum;
  if ( *v1 != nullptr )
    return 1;
  v3 = (_RTL_CRITICAL_SECTION *)operator new(nSize: 0x18u);
  if ( v3 != nullptr )
  {
    _lock(locknum: 10);
    if ( *v1 != nullptr )
    {
      free(pMem: v3);
    }
    else if ( __crtInitCritSecAndSpinCount(lpCriticalSection: v3, dwSpinCount: 0xFA0u) != 0 )
    {
      *v1 = v3;
    }
    else
    {
      free(pMem: v3);
      *_errno() = 12;
      retval = 0;
    }
    _unlock(locknum: 10);
    return retval;
  }
  else
  {
    *_errno() = 12;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010F87
// Name: __lock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock(int locknum)
{
  LPCRITICAL_SECTION *v1; // esi

  v1 = &locktable + 2 * locknum;
  if ( *v1 == nullptr && _mtinitlocknum(locknum) == 0 )
    _amsg_exit(rterrnum: 17);
  EnterCriticalSection(lpCriticalSection: *v1);
}

//------------------------------------------------------------------------------
// Address: 0x10010FC0
// Name: _strlen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strlen(char *buf)
{
  char *v1; // ecx
  char v2; // al
  int v3; // eax
  int v4; // eax

  v1 = buf;
  if ( ((unsigned __int8)buf & 3) != 0 )
  {
    while ( 1 )
    {
      v2 = *v1++;
      if ( v2 == 0 )
        break;
      if ( ((unsigned __int8)v1 & 3) == 0 )
        goto main_loop_2;
    }
  }
  else
  {
    do
    {
      do
      {
main_loop_2:
        v3 = (*(_DWORD *)v1 + 2130640639) ^ ~*(_DWORD *)v1;
        v1 += 4;
      }
      while ( (v3 & 0x81010100) == 0 );
      v4 = *((_DWORD *)v1 - 1);
    }
    while ( (_BYTE)v4 != 0 && BYTE1(v4) != 0 && (v4 & 0xFF0000) != 0 && (v4 & 0xFF000000) != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001104B
// Name: __check_float_string
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _check_float_string@<eax>(
        unsigned int *pnFloatStrSz@<esi>,
        char **pFloatStr@<edi>,
        unsigned int nFloatStrUsed,
        char *floatstring,
        int *pmalloc_FloatStrFlag)
{
  unsigned int v5; // eax
  char *v6; // eax
  char *v8; // eax

  v5 = *pnFloatStrSz;
  if ( nFloatStrUsed == *pnFloatStrSz )
  {
    if ( *pFloatStr == floatstring )
    {
      v6 = (char *)calloc(count: v5, size: 2u);
      *pFloatStr = v6;
      if ( v6 == nullptr )
        return 0;
      *pmalloc_FloatStrFlag = 1;
      memcpy(dst: (unsigned __int8 *)*pFloatStr, src: (unsigned __int8 *)floatstring, count: *pnFloatStrSz);
    }
    else
    {
      v8 = (char *)_recalloc_crt(ptr: *pFloatStr, count: v5, size: 2u);
      if ( v8 == nullptr )
        return 0;
      *pFloatStr = v8;
    }
    *pnFloatStrSz *= 2;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001109F
// Name: _inc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall inc(int a1, _iobuf *fileptr)
{
  if ( --fileptr->_cnt < 0 )
    return _filbuf(str: fileptr);
  return *(unsigned __int8 *)fileptr->_ptr++;
}

//------------------------------------------------------------------------------
// Address: 0x100110B5
// Name: _whiteout
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall whiteout@<eax>(int *counter@<esi>, int a2@<ecx>, _iobuf *fileptr)
{
  int v3; // ebx
  int v4; // eax
  int v6; // [esp-4h] [ebp-8h]

  do
  {
    ++*counter;
    v3 = inc(a1: a2, fileptr);
    if ( v3 == -1 )
      break;
    v4 = isspace(c: (unsigned __int8)v3);
    a2 = v6;
  }
  while ( v4 != 0 );
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100110DA
// Name: __input_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _input_l(_iobuf *stream, ioinfo **format, localeinfo_struct *plocinfo, char *arglist)
{
  ioinfo **v4; // edi
  int result; // eax
  ioinfo *v6; // eax
  ioinfo *v7; // eax
  unsigned __int8 v8; // al
  const unsigned __int8 *v9; // edi
  int v10; // eax
  _WORD *v11; // esi
  int v12; // ebx
  int v13; // eax
  int v14; // ecx
  unsigned __int8 *v15; // eax
  unsigned __int8 v16; // al
  int v17; // ebx
  int v18; // eax
  int v19; // ecx
  int v20; // edi
  signed int v21; // ebx
  int v22; // ebx
  int i; // eax
  int v24; // eax
  int v25; // ecx
  int v26; // eax
  int j; // eax
  int v28; // eax
  int v29; // ecx
  int v30; // eax
  int v31; // ecx
  int v32; // ecx
  int v33; // eax
  int k; // eax
  int v35; // eax
  int v36; // ecx
  void (__cdecl *v37)(int, void *, char *, _LocaleUpdate *); // eax
  _WORD *v38; // edi
  int v39; // eax
  int v40; // eax
  const unsigned __int8 *v41; // edi
  const unsigned __int8 *v42; // esi
  unsigned __int8 v43; // dl
  unsigned __int8 v44; // al
  unsigned int v45; // edi
  int v46; // edx
  unsigned __int8 v47; // al
  int v48; // eax
  int v49; // ecx
  int v50; // eax
  int v51; // ecx
  unsigned int v52; // esi
  int v53; // eax
  int v54; // eax
  int v55; // ecx
  int v56; // edi
  int v57; // eax
  int v58; // ebx
  int v59; // eax
  int v60; // eax
  int v61; // ecx
  bool v62; // zf
  int v63; // [esp-10h] [ebp-8Ch]
  void *v64; // [esp-Ch] [ebp-88h]
  char *v65; // [esp-8h] [ebp-84h]
  int v66; // [esp-4h] [ebp-80h]
  int v67; // [esp-4h] [ebp-80h]
  int v68; // [esp-4h] [ebp-80h]
  int v69; // [esp-4h] [ebp-80h]
  int v70; // [esp-4h] [ebp-80h]
  int v71; // [esp-4h] [ebp-80h]
  int v72; // [esp-4h] [ebp-80h]
  int v73; // [esp-4h] [ebp-80h]
  int v74; // [esp-4h] [ebp-80h]
  int v75; // [esp-4h] [ebp-80h]
  char *arglistsave; // [esp+Ch] [ebp-70h]
  _LocaleUpdate _loc_update; // [esp+10h] [ebp-6Ch] BYREF
  int wctemp; // [esp+20h] [ebp-5Ch] BYREF
  char *v79; // [esp+24h] [ebp-58h]
  unsigned int number; // [esp+28h] [ebp-54h]
  char temp[4]; // [esp+2Ch] [ebp-50h] BYREF
  unsigned int nFloatStrSz; // [esp+30h] [ebp-4Ch] BYREF
  int integer64; // [esp+34h] [ebp-48h]
  int malloc_FloatStrFlag; // [esp+38h] [ebp-44h] BYREF
  unsigned __int8 prevchar; // [esp+3Fh] [ebp-3Dh]
  int count; // [esp+40h] [ebp-3Ch]
  void *pointer; // [esp+44h] [ebp-38h]
  unsigned __int64 num64; // [esp+48h] [ebp-34h]
  int widthset; // [esp+50h] [ebp-2Ch]
  const unsigned __int8 *v90; // [esp+54h] [ebp-28h]
  char *pFloatStr; // [esp+58h] [ebp-24h] BYREF
  int comchr; // [esp+5Ch] [ebp-20h]
  int started; // [esp+60h] [ebp-1Ch]
  char decimal; // [esp+64h] [ebp-18h]
  char negative; // [esp+65h] [ebp-17h]
  char fl_wchar_arg; // [esp+66h] [ebp-16h]
  char match; // [esp+67h] [ebp-15h]
  _iobuf *fileptr; // [esp+68h] [ebp-14h]
  char longone; // [esp+6Eh] [ebp-Eh]
  char suppress; // [esp+6Fh] [ebp-Dh]
  int width; // [esp+70h] [ebp-Ch]
  char widechar; // [esp+77h] [ebp-5h]
  int v103; // [esp+78h] [ebp-4h]
  char done_flag; // [esp+7Fh] [ebp+3h]
  int charcount; // [esp+80h] [ebp+4h] BYREF
  char floatstring[352]; // [esp+84h] [ebp+8h] BYREF
  char AsciiTable[32]; // [esp+1E4h] [ebp+168h] BYREF

  v4 = format;
  v79 = arglist;
  fileptr = stream;
  v90 = (const unsigned __int8 *)format;
  pFloatStr = floatstring;
  nFloatStrSz = 350;
  malloc_FloatStrFlag = 0;
  wctemp = 0;
  v103 = 0;
  if ( format != nullptr && stream != nullptr )
  {
    if ( (stream->_flag & 0x40) != 0 )
      goto LABEL_16;
    if ( _fileno(stream) == -1 || _fileno(stream) == -2 )
    {
      v6 = &__badioinfo;
    }
    else
    {
      v4 = &__pioinfo[_fileno(stream) >> 5];
      v6 = &(*v4)[_fileno(stream) & 0x1F];
    }
    if ( (*((_BYTE *)v6 + 36) & 0x7F) == 0 )
    {
      if ( _fileno(stream) == -1 || _fileno(stream) == -2 )
      {
        v7 = &__badioinfo;
      }
      else
      {
        v4 = &__pioinfo[_fileno(stream) >> 5];
        v7 = &(*v4)[_fileno(stream) & 0x1F];
      }
      if ( *((char *)v7 + 36) >= 0 )
      {
        v4 = (ioinfo **)v90;
LABEL_16:
        _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
        v8 = *(_BYTE *)v4;
        v62 = *(_BYTE *)v4 == 0;
        match = 0;
        charcount = 0;
        count = 0;
        if ( v62 )
          goto LABEL_289;
        v9 = v90;
        while ( 2 )
        {
          if ( isspace(c: v8) != 0 )
          {
            --charcount;
            v10 = whiteout(counter: &charcount, a2: v66, fileptr);
            if ( v10 != -1 )
              _ungetc_nolock(ch: v10, str: fileptr);
            do
              ++v9;
            while ( isspace(c: *v9) != 0 );
            goto LABEL_273;
          }
          if ( *v9 != 37 )
          {
            ++charcount;
            v58 = inc(a1: v66, fileptr);
            v59 = *v9++;
            v103 = v58;
            v90 = v9;
            if ( v59 == v58 )
            {
              if ( isleadbyte(c: v58) == 0 )
                goto LABEL_269;
              ++charcount;
              v60 = inc(a1: v75, fileptr);
              v61 = *v9++;
              v90 = v9;
              if ( v61 == v60 )
              {
                --charcount;
                goto LABEL_269;
              }
              if ( v60 != -1 )
                _ungetc_nolock(ch: v60, str: fileptr);
            }
            v62 = v58 == -1;
            goto LABEL_279;
          }
          number = 0;
          prevchar = 0;
          started = 0;
          widthset = 0;
          width = 0;
          decimal = 0;
          negative = 0;
          suppress = 0;
          done_flag = 0;
          fl_wchar_arg = 0;
          widechar = 0;
          longone = 1;
          integer64 = 0;
          v11 = nullptr;
          do
          {
            v12 = *++v9;
            v13 = isdigit(c: (unsigned __int8)v12);
            v14 = v67;
            if ( v13 != 0 )
            {
              ++widthset;
              width = 10 * width + v12 - 48;
              continue;
            }
            if ( v12 > 78 )
            {
              if ( v12 == 104 )
              {
                --longone;
                --widechar;
              }
              else
              {
                if ( v12 == 108 )
                {
                  v15 = (unsigned __int8 *)(v9 + 1);
                  if ( v9[1] == 108 )
                    goto LABEL_36;
                  ++longone;
                }
                else if ( v12 != 119 )
                {
                  goto DEFAULT_LABEL;
                }
                ++widechar;
              }
            }
            else
            {
              switch ( v12 )
              {
                case 'N':
                  continue;
                case '*':
                  ++suppress;
                  continue;
                case 'F':
                  continue;
                default:
                  break;
              }
              if ( v12 != 73 )
              {
                if ( v12 == 76 )
                {
                  ++longone;
                  continue;
                }
DEFAULT_LABEL:
                ++done_flag;
                continue;
              }
              LOBYTE(v14) = v9[1];
              if ( (_BYTE)v14 == 54 )
              {
                v15 = (unsigned __int8 *)(v9 + 2);
                if ( v9[2] == 52 )
                {
LABEL_36:
                  ++integer64;
                  v9 = v15;
                  num64 = 0;
                  continue;
                }
              }
              if ( (_BYTE)v14 == 51 && v9[2] == 50 )
              {
                v9 += 2;
                continue;
              }
              if ( (_BYTE)v14 != 100 && (_BYTE)v14 != 105 && (_BYTE)v14 != 111 && (_BYTE)v14 != 120 && (_BYTE)v14 != 88 )
                goto DEFAULT_LABEL;
            }
          }
          while ( done_flag == 0 );
          v90 = v9;
          if ( suppress == 0 )
          {
            v11 = *(_WORD **)v79;
            arglistsave = v79;
            v79 += 4;
          }
          pointer = v11;
          done_flag = 0;
          if ( widechar == 0 )
          {
            v16 = *v9;
            if ( *v9 == 83 || (widechar = -1, v16 == 67) )
              widechar = 1;
          }
          comchr = *v9 | 0x20;
          v17 = comchr;
          if ( comchr != 110 )
          {
            if ( comchr == 99 || comchr == 123 )
            {
              ++charcount;
              v18 = inc(a1: v14, fileptr);
            }
            else
            {
              v18 = whiteout(counter: &charcount, a2: v14, fileptr);
            }
            v103 = v18;
            if ( v18 == -1 )
              goto error_return;
            v11 = pointer;
            v9 = v90;
          }
          v19 = widthset;
          if ( widthset != 0 && width == 0 )
            goto LABEL_275;
          if ( v17 > 111 )
          {
            switch ( v17 )
            {
              case 'p':
                longone = 1;
                break;
              case 's':
LABEL_127:
                if ( widechar > 0 )
                  fl_wchar_arg = 1;
                goto scanit;
              case 'u':
                break;
              case 'x':
                goto LABEL_82;
              case '{':
                if ( widechar > 0 )
                  fl_wchar_arg = 1;
                v41 = v9 + 1;
                v42 = v41;
                if ( *v41 == 94 )
                {
                  v42 = v41 + 1;
                  decimal = -1;
                }
                memset(dst: (int)AsciiTable, value: nullptr, count: sizeof(AsciiTable));
                if ( *v42 == 93 )
                {
                  v43 = 93;
                  ++v42;
                  AsciiTable[11] = 32;
                }
                else
                {
                  v43 = prevchar;
                }
                while ( 1 )
                {
                  v47 = *v42;
                  if ( *v42 == 93 )
                    break;
                  ++v42;
                  if ( v47 == 45 && v43 != 0 && (LOBYTE(v19) = *v42, *v42 != 93) )
                  {
                    ++v42;
                    if ( v43 >= (unsigned __int8)v19 )
                    {
                      v44 = v43;
                      v43 = v19;
                    }
                    else
                    {
                      v44 = v19;
                    }
                    if ( v43 <= v44 )
                    {
                      v45 = v43;
                      v46 = (unsigned __int8)(v44 - v43 + 1);
                      do
                      {
                        v19 = v45 & 7;
                        AsciiTable[v45++ >> 3] |= 1 << v19;
                        --v46;
                      }
                      while ( v46 != 0 );
                      v17 = comchr;
                    }
                    v43 = 0;
                  }
                  else
                  {
                    v43 = v47;
                    v19 = v47 & 7;
                    AsciiTable[v47 >> 3] |= 1 << (v47 & 7);
                    v17 = comchr;
                  }
                }
                v90 = v42;
                v11 = pointer;
scanit:
                --charcount;
                v38 = v11;
                if ( v103 != -1 )
                {
                  _ungetc_nolock(ch: v103, str: fileptr);
                  v19 = v69;
                }
                while ( 1 )
                {
                  if ( widthset != 0 )
                  {
                    v39 = width--;
                    if ( v39 == 0 )
                      goto LABEL_200;
                  }
                  ++charcount;
                  v40 = inc(a1: v19, fileptr);
                  v103 = v40;
                  if ( v40 == -1 )
                    goto LABEL_198;
                  if ( v17 != 99 )
                  {
                    if ( v17 != 115 )
                      goto LABEL_294;
                    if ( v40 >= 9 && v40 <= 13 )
                    {
LABEL_198:
                      --charcount;
                      if ( v40 != -1 )
                        _ungetc_nolock(ch: v40, str: fileptr);
LABEL_200:
                      if ( v38 != v11 )
                      {
                        if ( suppress == 0 )
                        {
                          ++count;
                          if ( v17 != 99 )
                          {
                            if ( fl_wchar_arg != 0 )
                              *(_WORD *)pointer = 0;
                            else
                              *(_BYTE *)pointer = 0;
                          }
                        }
                        goto LABEL_264;
                      }
                      goto error_return;
                    }
                    if ( v40 == 32 )
                    {
LABEL_294:
                      if ( v17 != 123 )
                        goto LABEL_198;
                      v19 = decimal ^ AsciiTable[v40 >> 3];
                      v17 = comchr;
                      if ( ((1 << (v40 & 7)) & v19) == 0 )
                        goto LABEL_198;
                    }
                  }
                  if ( suppress != 0 )
                  {
                    v38 = (_WORD *)((char *)v38 + 1);
                  }
                  else
                  {
                    if ( fl_wchar_arg != 0 )
                    {
                      temp[0] = v40;
                      if ( isleadbyte(c: v40) != 0 )
                      {
                        ++charcount;
                        temp[1] = inc(a1: v70, fileptr);
                      }
                      wctemp = 63;
                      _mbtowc_l(
                        pwc: (wchar_t *)&wctemp,
                        s: temp,
                        n: _loc_update.localeinfo.locinfo->mb_cur_max,
                        plocinfo: &_loc_update.localeinfo);
                      *v11++ = wctemp;
                    }
                    else
                    {
                      *(_BYTE *)v11 = v40;
                      v11 = (_WORD *)((char *)v11 + 1);
                    }
                    pointer = v11;
                  }
                }
              default:
                goto LABEL_151;
            }
LABEL_207:
            v21 = v103;
            if ( v103 == 45 )
            {
              negative = 1;
            }
            else if ( v103 != 43 )
            {
              goto getnum;
            }
            if ( --width == 0 && widthset != 0 )
            {
              done_flag = 1;
              goto getnum;
            }
            ++charcount;
            v21 = inc(a1: widthset, fileptr);
            goto LABEL_214;
          }
          switch ( v17 )
          {
            case 'o':
              goto LABEL_207;
            case 'c':
              if ( widthset == 0 )
              {
                ++width;
                widthset = 1;
              }
              goto LABEL_127;
            case 'd':
              goto LABEL_207;
            default:
              break;
          }
          if ( v17 <= 100 )
            goto LABEL_151;
          if ( v17 <= 103 )
          {
            v22 = 0;
            if ( v103 == 45 )
            {
              *pFloatStr = 45;
              v22 = 1;
              goto f_incwidth;
            }
            if ( v103 == 43 )
            {
f_incwidth:
              --width;
              ++charcount;
              v103 = inc(a1: v19, fileptr);
            }
            if ( widthset == 0 )
              width = -1;
            for ( i = (unsigned __int8)v103; isdigit(c: i) != 0; i = (unsigned __int8)v103 )
            {
              v24 = width--;
              if ( v24 == 0 )
                break;
              ++started;
              pFloatStr[v22] = v103;
              if ( _check_float_string(
                     pnFloatStrSz: &nFloatStrSz,
                     &pFloatStr,
                     nFloatStrUsed: ++v22,
                     floatstring,
                     pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                goto error_return;
              ++charcount;
              v103 = inc(a1: v25, fileptr);
            }
            decimal = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
            if ( decimal == (_BYTE)v103 )
            {
              v26 = width--;
              if ( v26 != 0 )
              {
                ++charcount;
                v103 = inc(a1: v68, fileptr);
                pFloatStr[v22] = decimal;
                if ( _check_float_string(
                       pnFloatStrSz: &nFloatStrSz,
                       &pFloatStr,
                       nFloatStrUsed: ++v22,
                       floatstring,
                       pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                  goto error_return;
                for ( j = (unsigned __int8)v103; isdigit(c: j) != 0; j = (unsigned __int8)v103 )
                {
                  v28 = width--;
                  if ( v28 == 0 )
                    break;
                  ++started;
                  pFloatStr[v22] = v103;
                  if ( _check_float_string(
                         pnFloatStrSz: &nFloatStrSz,
                         &pFloatStr,
                         nFloatStrUsed: ++v22,
                         floatstring,
                         pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                    goto error_return;
                  ++charcount;
                  v103 = inc(a1: v29, fileptr);
                }
              }
            }
            if ( started != 0 && (v103 == 101 || v103 == 69) )
            {
              v30 = width--;
              if ( v30 != 0 )
              {
                pFloatStr[v22] = 101;
                if ( _check_float_string(
                       pnFloatStrSz: &nFloatStrSz,
                       &pFloatStr,
                       nFloatStrUsed: ++v22,
                       floatstring,
                       pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                  goto error_return;
                ++charcount;
                v103 = inc(a1: v31, fileptr);
                if ( v103 == 45 )
                {
                  pFloatStr[v22] = 45;
                  if ( _check_float_string(
                         pnFloatStrSz: &nFloatStrSz,
                         &pFloatStr,
                         nFloatStrUsed: ++v22,
                         floatstring,
                         pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                    goto error_return;
f_incwidth2:
                  v33 = width--;
                  if ( v33 != 0 )
                  {
                    ++charcount;
                    v103 = inc(a1: v32, fileptr);
                  }
                  else
                  {
                    width = 0;
                  }
                }
                else if ( v103 == 43 )
                {
                  goto f_incwidth2;
                }
                for ( k = (unsigned __int8)v103; isdigit(c: k) != 0; k = (unsigned __int8)v103 )
                {
                  v35 = width--;
                  if ( v35 == 0 )
                    break;
                  ++started;
                  pFloatStr[v22] = v103;
                  if ( _check_float_string(
                         pnFloatStrSz: &nFloatStrSz,
                         &pFloatStr,
                         nFloatStrUsed: ++v22,
                         floatstring,
                         pmalloc_FloatStrFlag: &malloc_FloatStrFlag) == 0 )
                    goto error_return;
                  ++charcount;
                  v103 = inc(a1: v36, fileptr);
                }
              }
            }
            --charcount;
            if ( v103 != -1 )
              _ungetc_nolock(ch: v103, str: fileptr);
            if ( started != 0 )
            {
              if ( suppress == 0 )
              {
                ++count;
                v65 = pFloatStr;
                v64 = pointer;
                pFloatStr[v22] = 0;
                v63 = longone - 1;
                v37 = (void (__cdecl *)(int, void *, char *, _LocaleUpdate *))_decode_pointer(codedptr: off_10037F94);
                v37(a1: v63, a2: v64, a3: v65, a4: &_loc_update);
              }
              goto LABEL_264;
            }
            goto error_return;
          }
          if ( v17 != 105 )
          {
            if ( v17 == 110 )
            {
              v20 = charcount;
              if ( suppress == 0 )
              {
assign_num:
                if ( integer64 != 0 )
                {
                  *(_QWORD *)v11 = num64;
                }
                else if ( longone != 0 )
                {
                  *(_DWORD *)v11 = v20;
                }
                else
                {
                  *v11 = v20;
                }
              }
              goto LABEL_264;
            }
LABEL_151:
            if ( *v9 == v103 )
            {
              --match;
              if ( suppress == 0 )
                v79 = arglistsave;
              goto LABEL_264;
            }
LABEL_275:
            v62 = v103 == -1;
LABEL_279:
            if ( !v62 )
              _ungetc_nolock(ch: v103, str: fileptr);
            goto error_return;
          }
          comchr = 100;
LABEL_82:
          v21 = v103;
          if ( v103 == 45 )
          {
            negative = 1;
            goto x_incwidth;
          }
          if ( v103 == 43 )
          {
x_incwidth:
            if ( --width != 0 || widthset == 0 )
            {
              ++charcount;
              v21 = inc(a1: widthset, fileptr);
              v103 = v21;
            }
            else
            {
              done_flag = 1;
            }
          }
          if ( v21 == 48 )
          {
            ++charcount;
            v48 = inc(a1: v19, fileptr);
            v21 = v48;
            v103 = v48;
            if ( (_BYTE)v48 != 120 && (_BYTE)v48 != 88 )
            {
              started = 1;
              if ( comchr != 120 )
              {
                if ( widthset != 0 && --width == 0 )
                  ++done_flag;
                comchr = 111;
                goto getnum;
              }
              --charcount;
              if ( v48 != -1 )
                _ungetc_nolock(ch: v48, str: fileptr);
              v21 = 48;
LABEL_214:
              v103 = v21;
              goto getnum;
            }
            ++charcount;
            v21 = inc(a1: v49, fileptr);
            v103 = v21;
            if ( widthset != 0 )
            {
              width -= 2;
              if ( width < 1 )
                ++done_flag;
            }
            comchr = 120;
          }
getnum:
          if ( integer64 == 0 )
          {
            v20 = number;
            if ( done_flag == 0 )
            {
              while ( 1 )
              {
                if ( comchr == 120 || comchr == 112 )
                {
                  if ( isxdigit(c: (unsigned __int8)v21) == 0 )
                  {
LABEL_250:
                    --charcount;
                    if ( v21 != -1 )
                      _ungetc_nolock(ch: v21, str: fileptr);
                    break;
                  }
                  v56 = 16 * v20;
                  v57 = isdigit(c: (unsigned __int8)v21);
                  v55 = v74;
                  v21 = (char)v21;
                  if ( v57 == 0 )
                    v21 = ((char)v21 & 0xFFFFFFDF) - 7;
                  v103 = v21;
                }
                else
                {
                  v54 = isdigit(c: (unsigned __int8)v21);
                  v55 = v73;
                  if ( v54 == 0 )
                    goto LABEL_250;
                  if ( comchr == 111 )
                  {
                    if ( v21 >= 56 )
                      goto LABEL_250;
                    v56 = 8 * v20;
                  }
                  else
                  {
                    v56 = 10 * v20;
                  }
                }
                ++started;
                v20 = v56 + v21 - 48;
                if ( widthset != 0 && --width == 0 )
                  break;
                ++charcount;
                v21 = inc(a1: v55, fileptr);
                v103 = v21;
              }
            }
            if ( negative != 0 )
              v20 = -v20;
            goto LABEL_254;
          }
          if ( done_flag != 0 )
            goto LABEL_233;
          while ( 2 )
          {
            if ( comchr != 120 && comchr != 112 )
            {
              v50 = isdigit(c: (unsigned __int8)v21);
              v51 = v71;
              if ( v50 == 0 )
                break;
              if ( comchr == 111 )
              {
                if ( v21 >= 56 )
                  break;
                v52 = 8 * num64;
                HIDWORD(num64) = num64 >> 29;
              }
              else
              {
                HIDWORD(num64) = (10 * num64) >> 32;
                v52 = 10 * num64;
              }
              goto LABEL_228;
            }
            if ( isxdigit(c: (unsigned __int8)v21) != 0 )
            {
              v52 = 16 * num64;
              HIDWORD(num64) = num64 >> 28;
              v53 = isdigit(c: (unsigned __int8)v21);
              v51 = v72;
              v21 = (char)v21;
              if ( v53 == 0 )
                v21 = ((char)v21 & 0xFFFFFFDF) - 7;
              v103 = v21;
LABEL_228:
              ++started;
              num64 = v21 - 48 + __PAIR64__(HIDWORD(num64), v52);
              if ( widthset != 0 && --width == 0 )
                goto LABEL_233;
              ++charcount;
              v21 = inc(a1: v51, fileptr);
              v103 = v21;
              continue;
            }
            break;
          }
          --charcount;
          if ( v21 != -1 )
            _ungetc_nolock(ch: v21, str: fileptr);
LABEL_233:
          v20 = number;
          if ( negative != 0 )
            num64 = -(__int64)num64;
LABEL_254:
          if ( comchr == 70 )
            started = 0;
          if ( started == 0 )
            goto error_return;
          if ( suppress == 0 )
          {
            ++count;
            v11 = pointer;
            goto assign_num;
          }
LABEL_264:
          ++match;
          v9 = ++v90;
LABEL_269:
          if ( v103 != -1 )
          {
LABEL_273:
            v8 = *v9;
            if ( *v9 == 0 )
              goto error_return;
            continue;
          }
          break;
        }
        if ( *v9 == 37 && v90[1] == 110 )
        {
          v9 = v90;
          goto LABEL_273;
        }
error_return:
        if ( malloc_FloatStrFlag == 1 )
          free(pMem: pFloatStr);
        if ( v103 == -1 )
        {
          result = count;
          if ( count == 0 && match == 0 )
            result = -1;
          if ( _loc_update.updated )
            _loc_update.ptd->_ownlocale &= ~2u;
          return result;
        }
LABEL_289:
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
        return count;
      }
    }
  }
  *_errno() = 22;
  _invalid_parameter(a1: 0, a2: (unsigned int)v4, a3: (unsigned int)stream);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10011D27
// Name: __fltin2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_flt *__cdecl _fltin2(
        _flt *flt,
        const char *str,
        int len_ignore,
        int scale_ignore,
        int radix_ignore,
        localeinfo_struct *_Locale)
{
  int v6; // ebx
  INTRNCVT_STATUS v7; // eax
  const char *EndPtr; // [esp+Ch] [ebp-24h] BYREF
  const char *v10; // [esp+10h] [ebp-20h]
  _CRT_DOUBLE x; // [esp+14h] [ebp-1Ch] BYREF
  unsigned int flags; // [esp+1Ch] [ebp-14h]
  _LDBL12 ld12; // [esp+20h] [ebp-10h] BYREF

  v10 = str;
  v6 = 0;
  flags = __strgtold12_l(pld12: &ld12, p_end_ptr: &EndPtr, str, mult12: 0, scale: 0, decpt: 0, implicit_E: 0, _Locale);
  if ( (flags & 4) != 0 )
  {
    v6 = 512;
    *(_CRT_DOUBLE *)&x.x = 0;
  }
  else
  {
    v7 = _ld12tod(pld12: &ld12, d: &x);
    if ( (flags & 2) != 0 || v7 == INTRNCVT_OVERFLOW )
      v6 = 128;
    if ( (flags & 1) != 0 || v7 == INTRNCVT_UNDERFLOW )
      v6 |= 0x100u;
  }
  flt->nbytes = EndPtr - v10;
  flt->dval = x.x;
  flt->flags = v6;
  return flt;
}

//------------------------------------------------------------------------------
// Address: 0x10011DCC
// Name: ___strgtold12_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl __strgtold12_l(
        _LDBL12 *pld12,
        const char **p_end_ptr,
        const char *str,
        int mult12,
        int scale,
        int decpt,
        int implicit_E,
        localeinfo_struct *_Locale)
{
  int v8; // ecx
  char *v9; // edi
  const char *v11; // edx
  char v12; // al
  char v13; // al
  int v14; // eax
  int v15; // eax
  const char *v16; // edx
  int v17; // eax
  int v18; // eax
  bool v19; // zf
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // eax
  _LDBL12 *v24; // esi
  char v25; // al
  int v26; // eax
  _LDBL12 *v27; // eax
  _LDBL12 *v28; // ebx
  __int16 v29; // dx
  __int16 v30; // ax
  unsigned __int16 v31; // dx
  __int16 v32; // ax
  unsigned __int16 v33; // di
  int v34; // eax
  _WORD *v35; // esi
  unsigned int v36; // ecx
  unsigned int v37; // edx
  unsigned int v38; // ebx
  __int16 v39; // di
  unsigned int v40; // ecx
  int v41; // esi
  int v42; // ecx
  int v43; // esi
  unsigned int v44; // ecx
  int v45; // ebx
  int v46; // ecx
  __int16 v47; // cx
  int v48; // esi
  unsigned int v49; // edx
  __int16 v50; // ax
  int v51; // [esp-4h] [ebp-8Ch]
  int v52; // [esp-4h] [ebp-8Ch]
  int v53; // [esp+10h] [ebp-78h]
  __int16 man_sign; // [esp+14h] [ebp-74h]
  _LDBL12 *v55; // [esp+18h] [ebp-70h]
  unsigned int result_flags; // [esp+1Ch] [ebp-6Ch]
  int exp_sign; // [esp+20h] [ebp-68h]
  int exp_signa; // [esp+20h] [ebp-68h]
  int pow; // [esp+24h] [ebp-64h]
  int powa; // [esp+24h] [ebp-64h]
  int found_exponent; // [esp+28h] [ebp-60h]
  unsigned __int8 *found_exponenta; // [esp+28h] [ebp-60h]
  int found_decpoint; // [esp+2Ch] [ebp-5Ch]
  unsigned __int8 *found_decpointa; // [esp+2Ch] [ebp-5Ch]
  int found_digit; // [esp+30h] [ebp-58h]
  int found_digita; // [esp+30h] [ebp-58h]
  const char *savedp; // [esp+34h] [ebp-54h]
  int savedpa; // [esp+34h] [ebp-54h]
  int exp_adj; // [esp+38h] [ebp-50h]
  int exp_adja; // [esp+38h] [ebp-50h]
  unsigned int manlen; // [esp+3Ch] [ebp-4Ch]
  unsigned int manlena; // [esp+3Ch] [ebp-4Ch]
  __int64 v73; // [esp+40h] [ebp-48h] BYREF
  int v74; // [esp+48h] [ebp-40h]
  _LDBL12 tmpld12; // [esp+4Ch] [ebp-3Ch] BYREF
  _BYTE v76[12]; // [esp+5Ch] [ebp-2Ch] BYREF
  char buf[28]; // [esp+68h] [ebp-20h] BYREF

  v8 = 0;
  v9 = buf;
  man_sign = 0;
  exp_sign = 1;
  manlen = 0;
  found_digit = 0;
  found_decpoint = 0;
  found_exponent = 0;
  pow = 0;
  exp_adj = 0;
  result_flags = 0;
  if ( _Locale == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: (unsigned int)buf, a3: 1u);
    return 0;
  }
  v11 = str;
  savedp = str;
  while ( 1 )
  {
    v12 = *v11;
    if ( *v11 != 32 && v12 != 9 && v12 != 10 && v12 != 13 )
      break;
    ++v11;
  }
  while ( 2 )
  {
    v13 = *v11++;
    switch ( v8 )
    {
      case 0:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_11;
        if ( v13 == *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_14;
        v14 = v13 - 43;
        if ( v14 == 0 )
        {
          man_sign = 0;
          v8 = 2;
          continue;
        }
        v15 = v14 - 2;
        if ( v15 == 0 )
        {
          v8 = 2;
          man_sign = 0x8000;
          continue;
        }
        if ( v15 != 3 )
          goto LABEL_75;
        goto LABEL_19;
      case 1:
        found_digit = 1;
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_11;
        if ( v13 == *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_24;
        if ( v13 == 43 || v13 == 45 )
          goto LABEL_33;
        if ( v13 == 48 )
          goto LABEL_19;
LABEL_28:
        if ( v13 <= 67 || v13 > 69 && (v13 <= 99 || v13 > 101) )
          goto LABEL_75;
        v52 = 6;
        goto LABEL_15;
      case 2:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
        {
LABEL_11:
          v51 = 3;
LABEL_12:
          v8 = v51;
          --v11;
        }
        else
        {
          if ( v13 == *_Locale->locinfo->lconv->decimal_point )
          {
LABEL_14:
            v52 = 5;
            goto LABEL_15;
          }
          if ( v13 != 48 )
          {
LABEL_37:
            v16 = savedp;
            goto LABEL_82;
          }
LABEL_19:
          v8 = 1;
        }
        continue;
      case 3:
        found_digit = 1;
        while ( v13 >= 48 && v13 <= 57 )
        {
          if ( manlen >= 0x19 )
          {
            ++exp_adj;
          }
          else
          {
            ++manlen;
            *v9++ = v13 - 48;
          }
          v13 = *v11++;
        }
        if ( v13 != *_Locale->locinfo->lconv->decimal_point )
          goto LABEL_46;
LABEL_24:
        v52 = 4;
        goto LABEL_15;
      case 4:
        found_digit = 1;
        found_decpoint = 1;
        if ( manlen == 0 )
        {
          while ( v13 == 48 )
          {
            --exp_adj;
            v13 = *v11++;
          }
        }
        while ( v13 >= 48 && v13 <= 57 )
        {
          if ( manlen < 0x19 )
          {
            ++manlen;
            *v9++ = v13 - 48;
            --exp_adj;
          }
          v13 = *v11++;
        }
LABEL_46:
        if ( v13 != 43 && v13 != 45 )
          goto LABEL_28;
LABEL_33:
        --v11;
        v52 = 11;
        goto LABEL_15;
      case 5:
        found_decpoint = 1;
        if ( (unsigned __int8)(v13 - 48) > 9u )
          goto LABEL_37;
        v51 = 4;
        goto LABEL_12;
      case 6:
        savedp = v11 - 2;
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_63;
        v17 = v13 - 43;
        if ( v17 == 0 )
          goto LABEL_70;
        v18 = v17 - 2;
        if ( v18 == 0 )
          goto LABEL_69;
        v19 = v18 == 3;
LABEL_67:
        if ( !v19 )
          goto LABEL_37;
        v52 = 8;
        goto LABEL_15;
      case 7:
        if ( (unsigned __int8)(v13 - 49) <= 8u )
          goto LABEL_63;
        v19 = v13 == 48;
        goto LABEL_67;
      case 8:
        found_exponent = 1;
        while ( v13 == 48 )
          v13 = *v11++;
        if ( (unsigned __int8)(v13 - 49) > 8u )
          goto LABEL_75;
LABEL_63:
        v51 = 9;
        goto LABEL_12;
      case 9:
        found_exponent = 1;
        v21 = 0;
        while ( 2 )
        {
          if ( v13 >= 48 && v13 <= 57 )
          {
            v21 = 10 * v21 + v13 - 48;
            if ( v21 <= 5200 )
            {
              v13 = *v11++;
              continue;
            }
            v21 = 5201;
          }
          break;
        }
        pow = v21;
        while ( v13 >= 48 && v13 <= 57 )
          v13 = *v11++;
LABEL_75:
        v16 = v11 - 1;
        goto LABEL_82;
      case 11:
        if ( implicit_E != 0 )
        {
          v20 = v13 - 43;
          savedp = v11 - 1;
          if ( v20 != 0 )
          {
            if ( v20 != 2 )
            {
              v16 = v11 - 1;
              goto LABEL_82;
            }
LABEL_69:
            exp_sign = -1;
            v8 = 7;
          }
          else
          {
LABEL_70:
            v52 = 7;
LABEL_15:
            v8 = v52;
          }
          continue;
        }
        v16 = v11 - 1;
LABEL_82:
        *p_end_ptr = v16;
        if ( found_digit == 0 )
        {
          result_flags = 4;
LABEL_174:
          v47 = 0;
          v50 = 0;
          v49 = 0;
          v48 = 0;
          goto LABEL_175;
        }
        if ( manlen > 0x18 )
        {
          if ( buf[23] >= 5 )
            ++buf[23];
          --v9;
          ++exp_adj;
          manlen = 24;
        }
        if ( manlen == 0 )
          goto LABEL_174;
        while ( *--v9 == 0 )
        {
          --manlen;
          ++exp_adj;
        }
        __mtold12(manptr: buf, manlen, ld12: &tmpld12);
        v22 = pow;
        if ( exp_sign < 0 )
          v22 = -pow;
        v23 = exp_adj + v22;
        if ( found_exponent == 0 )
          v23 += scale;
        if ( found_decpoint == 0 )
          v23 -= decpt;
        if ( v23 > 5200 )
        {
          v48 = 0;
          v50 = 0x7FFF;
          v49 = 0x80000000;
          v47 = 0;
          result_flags = 2;
          goto LABEL_175;
        }
        if ( v23 < -5200 )
        {
          result_flags = 1;
          goto LABEL_174;
        }
        v24 = &_pow10pos[-8];
        savedpa = v23;
        if ( v23 != 0 )
        {
          if ( v23 < 0 )
          {
            savedpa = -v23;
            v24 = &_pow10neg[-8];
          }
          if ( mult12 == 0 )
            *(_WORD *)tmpld12.ld12 = 0;
          while ( savedpa != 0 )
          {
            v25 = savedpa;
            savedpa >>= 3;
            v24 += 7;
            v26 = v25 & 7;
            manlena = (unsigned int)v24;
            if ( v26 != 0 )
            {
              v27 = &v24[v26];
              v28 = v27;
              v55 = v27;
              if ( *(_WORD *)v27->ld12 >= 0x8000u )
              {
                v73 = *(_QWORD *)v27->ld12;
                v74 = *(_DWORD *)&v27->ld12[8];
                --*(_DWORD *)((char *)&v73 + 2);
                v28 = (_LDBL12 *)&v73;
                v55 = (_LDBL12 *)&v73;
              }
              v29 = *(_WORD *)&v28->ld12[10];
              exp_adja = 0;
              memset(v76, 0, sizeof(v76));
              v30 = *(_WORD *)&tmpld12.ld12[10] ^ v29;
              v31 = v29 & 0x7FFF;
              v32 = v30 & 0x8000;
              v33 = v31 + (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF);
              if ( (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF) == 0x7FFF || v31 >= 0x7FFFu || v33 > 0xBFFDu )
              {
LABEL_167:
                *(_DWORD *)&tmpld12.ld12[4] = 0;
                v34 = v32 != 0 ? -32768 : 2147450880;
                *(_DWORD *)tmpld12.ld12 = 0;
                goto LABEL_168;
              }
              if ( v33 <= 0x3FBFu )
              {
                v34 = 0;
                *(_DWORD *)&tmpld12.ld12[4] = 0;
                *(_DWORD *)tmpld12.ld12 = 0;
LABEL_168:
                *(_DWORD *)&tmpld12.ld12[8] = v34;
                continue;
              }
              if ( (*(_WORD *)&tmpld12.ld12[10] & 0x7FFF) != 0
                || (++v33, (*(_DWORD *)&tmpld12.ld12[8] & 0x7FFFFFFF) != 0)
                || *(_DWORD *)&tmpld12.ld12[4] != 0
                || *(_DWORD *)tmpld12.ld12 != 0 )
              {
                if ( v31 != 0
                  || (++v33, (*(_DWORD *)&v28->ld12[8] & 0x7FFFFFFF) != 0)
                  || *(_DWORD *)&v28->ld12[4] != 0
                  || *(_DWORD *)v28->ld12 != 0 )
                {
                  exp_signa = 0;
                  v35 = &v76[4];
                  for ( found_digita = 5; found_digita > 0; --found_digita )
                  {
                    powa = found_digita;
                    found_decpointa = &tmpld12.ld12[2 * exp_signa];
                    found_exponenta = &v28->ld12[8];
                    do
                    {
                      v53 = 0;
                      v36 = *(unsigned __int16 *)found_decpointa * *(unsigned __int16 *)found_exponenta;
                      v37 = *((_DWORD *)v35 - 1);
                      v38 = v37 + v36;
                      if ( v37 + v36 < v37 || v38 < v36 )
                        v53 = 1;
                      *((_DWORD *)v35 - 1) = v38;
                      if ( v53 != 0 )
                        ++*v35;
                      found_decpointa += 2;
                      found_exponenta -= 2;
                      --powa;
                    }
                    while ( powa > 0 );
                    v28 = v55;
                    ++v35;
                    ++exp_signa;
                  }
                  v39 = v33 - 16382;
                  if ( v39 <= 0 )
                    goto LABEL_178;
                  do
                  {
                    if ( *(int *)&v76[8] < 0 )
                      break;
                    v40 = *(_DWORD *)v76;
                    *(_DWORD *)v76 *= 2;
                    v41 = (v40 >> 31) | (2 * *(_DWORD *)&v76[4]);
                    v42 = *(__int64 *)&v76[4] >> 31;
                    --v39;
                    *(_DWORD *)&v76[4] = v41;
                    *(_DWORD *)&v76[8] = v42;
                  }
                  while ( v39 > 0 );
                  if ( v39 <= 0 )
                  {
LABEL_178:
                    if ( --v39 < 0 )
                    {
                      v43 = (unsigned __int16)-v39;
                      v39 = 0;
                      do
                      {
                        if ( (v76[0] & 1) != 0 )
                          ++exp_adja;
                        v44 = *(_DWORD *)&v76[8];
                        *(_DWORD *)&v76[8] >>= 1;
                        v45 = __SPAIR64__(v44, *(unsigned int *)&v76[4]) >> 1;
                        v46 = *(__int64 *)v76 >> 1;
                        --v43;
                        *(_DWORD *)&v76[4] = v45;
                        *(_DWORD *)v76 = v46;
                      }
                      while ( v43 != 0 );
                      if ( exp_adja != 0 )
                        *(_WORD *)v76 |= 1u;
                    }
                  }
                  if ( *(_WORD *)v76 > 0x8000u || (*(_DWORD *)v76 & 0x1FFFF) == 0x18000 )
                  {
                    if ( *(_DWORD *)&v76[2] == -1 )
                    {
                      *(_DWORD *)&v76[2] = 0;
                      if ( *(_DWORD *)&v76[6] == -1 )
                      {
                        *(_DWORD *)&v76[6] = 0;
                        if ( *(_WORD *)&v76[10] == 0xFFFF )
                        {
                          *(_WORD *)&v76[10] = 0x8000;
                          ++v39;
                        }
                        else
                        {
                          ++*(_WORD *)&v76[10];
                        }
                      }
                      else
                      {
                        ++*(_DWORD *)&v76[6];
                      }
                    }
                    else
                    {
                      ++*(_DWORD *)&v76[2];
                    }
                  }
                  v24 = (_LDBL12 *)manlena;
                  if ( (unsigned __int16)v39 >= 0x7FFFu )
                    goto LABEL_167;
                  *(_WORD *)tmpld12.ld12 = *(_WORD *)&v76[2];
                  *(_QWORD *)&tmpld12.ld12[2] = *(_QWORD *)&v76[4];
                  *(_WORD *)&tmpld12.ld12[10] = v32 | v39;
                }
                else
                {
                  memset(&tmpld12, 0, sizeof(tmpld12));
                }
              }
              else
              {
                *(_WORD *)&tmpld12.ld12[10] = 0;
              }
            }
          }
        }
        v47 = *(_WORD *)tmpld12.ld12;
        v48 = *(_DWORD *)&tmpld12.ld12[2];
        v49 = *(_DWORD *)&tmpld12.ld12[6];
        v50 = *(_WORD *)&tmpld12.ld12[10];
LABEL_175:
        *(_WORD *)pld12->ld12 = v47;
        *(_WORD *)&pld12->ld12[10] = man_sign | v50;
        *(_DWORD *)&pld12->ld12[2] = v48;
        *(_DWORD *)&pld12->ld12[6] = v49;
        return result_flags;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10012490
// Name: __aulldvrm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall _aulldvrm(unsigned __int64 a1, __int64 a2)
{
  unsigned __int64 v2; // rtt
  unsigned int v3; // esi
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  unsigned __int64 v6; // rax
  char v7; // cf
  unsigned __int64 v8; // rax

  if ( HIDWORD(a2) != 0 )
  {
    v4 = HIDWORD(a2);
    v5 = a2;
    v6 = a1;
    do
    {
      v7 = v4 & 1;
      v4 >>= 1;
      v5 = (v5 >> 1) | (v7 << 31);
      v6 >>= 1;
    }
    while ( v4 != 0 );
    v3 = v6 / v5;
    v8 = v3 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v3, HIDWORD(v8)) || (HIDWORD(v8) = (a2 * (unsigned __int64)v3) >> 32, v8 > a1) )
      --v3;
  }
  else
  {
    LODWORD(v2) = a1;
    HIDWORD(v2) = HIDWORD(a1) % (unsigned int)a2;
    return v2 / (unsigned int)a2;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10012530
// Name: __CIacos_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _CIacos_pentium4()
{
  JUMPOUT(0x1001254E);
}

//------------------------------------------------------------------------------
// Address: 0x10012A90
// Name: __trandisp1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _trandisp1@<eax>(int a1@<edx>, __int16 a2@<cx>, int a3@<ebp>, __int16 a4@<fpstat>, double _ST7@<st0>)
{
  __int16 v5; // bx

  if ( *(_BYTE *)(a1 + 14) == 5 )
  {
    HIBYTE(v5) = HIBYTE(*(_WORD *)(a3 - 164)) & 0xFC | 2;
    LOBYTE(v5) = 63;
  }
  else
  {
    v5 = 4927;
  }
  *(_WORD *)(a3 - 162) = v5;
  _EBX = &XAMtoTagTab;
  __asm { fxam }
  *(_DWORD *)(a3 - 148) = a1;
  *(_WORD *)(a3 - 160) = a4;
  *(_BYTE *)(a3 - 144) = 0;
  LOBYTE(a2) = __ROL1__((char)(2 * *(_BYTE *)(a3 - 159)) >> 1, 1);
  _AL = a2 & 0xF;
  __asm { xlat }
  return (*(int (__thiscall **)(int))(_AL + a1 + 16))(a1: a2 & 0x404);
}

//------------------------------------------------------------------------------
// Address: 0x10012AF7
// Name: __trandisp2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _trandisp2@<eax>(int a1@<edx>, int a2@<ebp>, __int16 a3@<fpstat>, double _ST6@<st1>, double a5@<st0>)
{
  __int16 v5; // bx
  __int16 v7; // fps
  char v9; // cl
  __int16 v10; // cx
  char v13; // ah

  if ( *(_BYTE *)(a1 + 14) == 5 )
  {
    HIBYTE(v5) = HIBYTE(*(_WORD *)(a2 - 164)) & 0xFC | 2;
    LOBYTE(v5) = 63;
  }
  else
  {
    v5 = 4927;
  }
  *(_WORD *)(a2 - 162) = v5;
  _EBX = &XAMtoTagTab;
  __asm { fxam }
  *(_DWORD *)(a2 - 148) = a1;
  *(_WORD *)(a2 - 160) = a3;
  *(_BYTE *)(a2 - 144) = 0;
  _ST6 = a5;
  v9 = *(_BYTE *)(a2 - 159);
  __asm { fxam }
  *(_WORD *)(a2 - 160) = v7;
  HIBYTE(v10) = __ROL1__((char)(2 * *(_BYTE *)(a2 - 159)) >> 1, 1);
  _AL = HIBYTE(v10) & 0xF;
  __asm { xlat }
  v13 = _AL;
  LOBYTE(v10) = __ROL1__((char)(2 * v9) >> 1, 1);
  _AL = v10 & 0xF;
  __asm { xlat }
  return (*(int (__thiscall **)(int))((char)((4 * v13) | _AL) + a1 + 16))(a1: v10 & 0x404);
}

//------------------------------------------------------------------------------
// Address: 0x10012B83
// Name: __rttospopde
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int _rttospopde()
{
  _rttosnpopde();
  return _rttospop();
}

//------------------------------------------------------------------------------
// Address: 0x10012B88
// Name: __rttospop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _rttospop()
{
  return _rtnospop();
}

//------------------------------------------------------------------------------
// Address: 0x10012B8A
// Name: __rtnospop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _rtnospop()
{
  JUMPOUT(0x10012B8C);
}

//------------------------------------------------------------------------------
// Address: 0x10012B8D
// Name: __rtnospopde
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _rtnospopde()
{
  _rttosnpopde();
  _rtnospop();
}

//------------------------------------------------------------------------------
// Address: 0x10012B94
// Name: __rtzeropop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _rtzeropop@<eax>(double a1@<st0>)
{
  return _rtzeronpop(a1);
}

//------------------------------------------------------------------------------
// Address: 0x10012B96
// Name: __rtzeronpop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double _rtzeronpop()
{
  return 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10012B9B
// Name: __rtonepop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _rtonepop@<eax>(double a1@<st0>)
{
  return _rtonenpop(a1);
}

//------------------------------------------------------------------------------
// Address: 0x10012B9D
// Name: __rtonenpop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double _rtonenpop()
{
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10012BA2
// Name: __tosnan1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _tosnan1@<st0>(int a1@<ebp>, double a2@<st0>)
{
  double result; // st7

  *(double *)(a1 - 158) = a2;
  result = *(double *)(a1 - 158);
  if ( (*(_BYTE *)(a1 - 151) & 0x40) != 0 )
  {
    *(_BYTE *)(a1 - 144) = 7;
  }
  else
  {
    *(_BYTE *)(a1 - 144) = 1;
    return result + *(double *)&One_1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012BCD
// Name: __nosnan2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _nosnan2()
{
  return _tosnan2();
}

//------------------------------------------------------------------------------
// Address: 0x10012BCF
// Name: __tosnan2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _tosnan2@<st0>(int a1@<ebp>, double a2@<st1>, double a3@<st0>)
{
  double v3; // st6

  *(double *)(a1 - 158) = a2;
  v3 = *(double *)(a1 - 158);
  if ( (*(_BYTE *)(a1 - 151) & 0x40) != 0 )
    *(_BYTE *)(a1 - 144) = 7;
  else
    *(_BYTE *)(a1 - 144) = 1;
  return a3 + v3;
}

//------------------------------------------------------------------------------
// Address: 0x10012BF7
// Name: __nan2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _nan2@<st0>(int a1@<ebp>, double a2@<st1>, double a3@<st0>)
{
  double v3; // st6
  double v4; // rt0
  double v5; // st6

  *(double *)(a1 - 158) = a2;
  v3 = *(double *)(a1 - 158);
  if ( (*(_BYTE *)(a1 - 151) & 0x40) != 0
    && (v4 = v3,
        v5 = a3,
        a3 = v4,
        *(double *)(a1 - 158) = v5,
        v3 = *(double *)(a1 - 158),
        (*(_BYTE *)(a1 - 151) & 0x40) != 0) )
  {
    *(_BYTE *)(a1 - 144) = 7;
  }
  else
  {
    *(_BYTE *)(a1 - 144) = 1;
  }
  return a3 + v3;
}

//------------------------------------------------------------------------------
// Address: 0x10012C36
// Name: __rtindfpop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _rtindfpop@<eax>(double a1@<st0>)
{
  return _rtindfnpop(a1);
}

//------------------------------------------------------------------------------
// Address: 0x10012C38
// Name: __rtindfnpop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _rtindfnpop@<eax>(int a1@<ebp>)
{
  if ( *(char *)(a1 - 144) > 0 )
    JUMPOUT(0x10012C50);
  return _rttosnpopde();
}

//------------------------------------------------------------------------------
// Address: 0x10012C49
// Name: __rttosnpopde
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _rttosnpopde(int a1@<ebp>)
{
  *(_BYTE *)(a1 - 144) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x10012C53
// Name: __rtchsifneg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _rtchsifneg@<st0>(char a1@<cl>, double result@<st0>)
{
  if ( a1 != 0 )
    return -result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012C60
// Name: __startTwoArgErrorHandling
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _startTwoArgErrorHandling()
{
  JUMPOUT(0x10012C80);
}

//------------------------------------------------------------------------------
// Address: 0x10012C77
// Name: __startOneArgErrorHandling
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _startOneArgErrorHandling(
        int a1@<eax>,
        int a2@<edx>,
        char *a3@<ecx>,
        __int16 savCW,
        unsigned int ret_addr,
        unsigned __int64 param1)
{
  _exception exc; // [esp+0h] [ebp-20h] BYREF

  exc.type = a1;
  __asm { fstp    [ebp+exc.retval] }
  exc.name = a3;
  *(_QWORD *)&exc.arg1 = param1;
  _87except(opcode: a2, &exc, pcw16: (unsigned __int16 *)&savCW);
  __asm { fld     [ebp+exc.retval] }
  if ( savCW != 639 )
    __asm { fldcw   word ptr [ebp+savCW] }
}

//------------------------------------------------------------------------------
// Address: 0x10012CC0
// Name: __twoToTOS
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall _twoToTOS@<st0>(long double a1@<st0>)
{
  long double v1; // rt0

  v1 = rint(a1);
  return __FSCALE__(__F2XM1__(-(v1 - a1)) + 1.0, v1);
}

//------------------------------------------------------------------------------
// Address: 0x10012CD5
// Name: __load_CW
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _load_CW()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10012CEC
// Name: __convertTOStoQNaN
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _convertTOStoQNaN@<st0>(int a1@<eax>, double result@<st0>)
{
  if ( (a1 & 0x80000) == 0 )
    return result + 1.0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012D05
// Name: __fload_withFB
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __fastcall _fload_withFB(int a1, _DWORD *a2)
{
  double result; // st7

  if ( (a2[1] & 0x7FF00000) != 0x7FF00000 )
    return *(double *)a2;
  *(_QWORD *)&result = *(_QWORD *)a2 << 11;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012D48
// Name: __checkTOS_withFB
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _checkTOS_withFB(int a1, int a2)
{
  int result; // eax

  result = a2 & 0x7FF00000;
  if ( (a2 & 0x7FF00000) == 0x7FF00000 )
    return a2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10012D5E
// Name: __fast_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void _fast_exit()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10012D6B
// Name: __math_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10012D95
// Name: __check_overflow_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _check_overflow_exit()
{
  JUMPOUT(0x10012DBD);
}

//------------------------------------------------------------------------------
// Address: 0x10012DA9
// Name: __check_range_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10012E50
// Name: __CIasin_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _CIasin_pentium4()
{
  JUMPOUT(0x10012E6E);
}

//------------------------------------------------------------------------------
// Address: 0x100133D0
// Name: __cintrindisp2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _cintrindisp2@<eax>(int a1@<edx>, __int16 a2@<fpstat>, double a3@<st1>, double a4@<st0>)
{
  int savedregs; // [esp+2D4h] [ebp+0h] BYREF

  _trandisp2(a1, a2: (int)&savedregs, a3: a2, _ST6: a3, a5: a4);
  return cintrinexit();
}

//------------------------------------------------------------------------------
// Address: 0x1001340E
// Name: __cintrindisp1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _cintrindisp1@<eax>(int a1@<edx>, __int16 a2@<cx>, __int16 a3@<fpstat>, double a4@<st0>)
{
  int savedregs; // [esp+2D4h] [ebp+0h] BYREF

  _trandisp1(a1, a2, a3: (int)&savedregs, a4: a3, _ST7: a4);
  return cintrinexit();
}

//------------------------------------------------------------------------------
// Address: 0x1001344B
// Name: __ctrandisp2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _ctrandisp2(double a1@<st1>, double a2@<st0>, unsigned __int64 parm1, unsigned __int64 parm2)
{
  int v4; // edx
  __int16 v5; // fps
  int savedregs; // [esp+2D4h] [ebp+0h] BYREF

  _fload(parm: parm1);
  _fload(parm: parm2);
  _trandisp2(a1: v4, a2: (int)&savedregs, a3: v5, _ST6: a1, a5: a2);
  ctranexit();
}

//------------------------------------------------------------------------------
// Address: 0x10013493
// Name: ctranexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall ctranexit@<eax>(int a1@<ebp>)
{
  *(_BYTE *)(a1 - 712) &= ~1u;
  return cintrinexit();
}

//------------------------------------------------------------------------------
// Address: 0x1001349A
// Name: cintrinexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall cintrinexit@<st0>(long double *a1@<ebp>, long double result@<st0>)
{
  char v2; // fps
  char v3; // al
  __int16 v4; // ax
  int v5; // ebx

  if ( __fastflag != 0 )
    return result;
  *(a1 - 90) = result;
  v3 = *((_BYTE *)a1 - 144);
  switch ( v3 )
  {
    case 0:
      goto checkinexact;
    case -1:
      if ( (*((_WORD *)a1 - 357) & 0x7FF0) != 0x7FF0 )
        goto checkinexact;
      goto haveoverflow_0;
    case -2:
      v4 = *((_WORD *)a1 - 357) & 0x7FF0;
      if ( v4 == 0 )
      {
        *(_DWORD *)((char *)a1 - 142) = 4;
        result = __FSCALE__(result, 1536.0);
        if ( fabs(result) < 2.225073858507201e-308 )
          result = result * 0.0;
        goto haveerror;
      }
      if ( v4 != 32752 )
      {
checkinexact:
        if ( (*((_WORD *)a1 - 82) & 0x20) != 0 || (v2 & 0x20) == 0 )
          return result;
        *(_DWORD *)((char *)a1 - 142) = 8;
        goto haveerror;
      }
haveoverflow_0:
      *(_DWORD *)((char *)a1 - 142) = 3;
      result = __FSCALE__(result, -1536.0);
      if ( fabs(result) > 1.797693134862316e308 )
        result = result * INFINITY;
      goto haveerror;
    default:
      break;
  }
  *(_DWORD *)((char *)a1 - 142) = v3;
haveerror:
  v5 = *((_DWORD *)a1 - 37) + 1;
  *(_DWORD *)((char *)a1 - 138) = v5;
  if ( (*(_BYTE *)(a1 - 89) & 1) == 0 )
  {
    *(_DWORD *)((char *)a1 - 134) = *((_DWORD *)a1 + 2);
    *(_DWORD *)((char *)a1 - 130) = *((_DWORD *)a1 + 3);
    if ( *(_BYTE *)(v5 + 12) != 1 )
    {
      *(_DWORD *)((char *)a1 - 126) = *((_DWORD *)a1 + 4);
      *(_DWORD *)((char *)a1 - 122) = *((_DWORD *)a1 + 5);
    }
  }
  *(long double *)((char *)a1 - 118) = result;
  _87except(
    opcode: *(char *)(*((_DWORD *)a1 - 37) + 14),
    exc: (_exception *)((char *)a1 - 142),
    pcw16: (unsigned __int16 *)a1 - 82);
  return *(long double *)((char *)a1 - 118);
}

//------------------------------------------------------------------------------
// Address: 0x100135E1
// Name: __ctrandisp1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _ctrandisp1(double a1@<st0>, unsigned __int64 parm1)
{
  int v2; // edx
  __int16 v3; // cx
  __int16 v4; // fps
  int savedregs; // [esp+2D4h] [ebp+0h] BYREF

  _fload(parm: parm1);
  _trandisp1(a1: v2, a2: v3, a3: (int)&savedregs, a4: v4, _ST7: a1);
  ctranexit(a1: (int)&savedregs);
}

//------------------------------------------------------------------------------
// Address: 0x10013614
// Name: __fload
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _fload(double parm)
{
  double tmp; // [esp+6h] [ebp-Ah]

  if ( (HIWORD(parm) & 0x7FF0) != 0x7FF0 )
    return parm;
  HIDWORD(tmp) = *(_QWORD *)&parm >> 21;
  LODWORD(tmp) = LODWORD(parm);
  return tmp;
}

//------------------------------------------------------------------------------
// Address: 0x10013650
// Name: _fdiv_main_routine
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl fdiv_main_routine(_TBYTE a1, _TBYTE a2)
{
  double v2; // st7
  double v3; // st6
  unsigned int v4; // eax

  v2 = *(double *)&a2;
  v3 = *(double *)&a1;
  while ( !__CFADD__(DWORD1(a1), DWORD1(a1)) )
  {
    if ( *(_QWORD *)&a1 == 0 || (HIWORD(a1) & 0x7FFF) != 0 )
      return v2 / v3;
    if ( (HIWORD(a2) & 0x7FFF) != 0 )
    {
      if ( (HIWORD(a2) & 0x7FFF) == 0x7FFF || !__CFADD__(DWORD1(a2), DWORD1(a2)) )
        return v2 / v3;
    }
    else if ( __CFADD__(DWORD1(a2), DWORD1(a2)) )
    {
      return v2 / v3;
    }
    *(double *)&a1 = v3 * *(float *)&one_shl_63;
    v2 = *(double *)&a2;
  }
  v4 = (2 * DWORD1(a1)) ^ 0xE000000;
  if ( (v4 & 0xE000000) != 0 )
    return v2 / v3;
  if ( fdiv_risc_table[v4 >> 28] == 0 )
    return v2 / v3;
  if ( (HIWORD(a1) & 0x7FFF) == 0 || (HIWORD(a1) & 0x7FFF) == 0x7FFF )
    return v2 / v3;
  if ( (HIWORD(a2) & 0x7FFF) == 1 )
    return v2 * *(float *)&fdiv_scale_2 / (v3 * *(float *)&fdiv_scale_2);
  else
    return v2 * *(float *)&fdiv_scale_1 / (v3 * *(float *)&fdiv_scale_1);
}

//------------------------------------------------------------------------------
// Address: 0x10013767
// Name: __adj_fdiv_r
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _adj_fdiv_r(char a1@<al>)
{
  _TBYTE v1; // [esp-2Ch] [ebp-58h]
  _TBYTE v2; // [esp-20h] [ebp-4Ch]
  _TBYTE v17; // [esp+0h] [ebp-2Ch]
  _TBYTE v18; // [esp+Ch] [ebp-20h]

  switch ( a1 & 0x3F )
  {
    case 0:
      __asm { fdiv    st, st; jumptable 1001376D case 0 }
      return;
    case 1:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label2;
    case 2:
label2:
      __asm { fdivr   st, st; jumptable 1001376D case 2 }
      return;
    case 3:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label4;
    case 4:
label4:
      __asm { fdiv    st, st; jumptable 1001376D case 4 }
      return;
    case 5:
      __asm { fdivp   st, st; jumptable 1001376D case 5 }
      return;
    case 6:
      __asm { fdivr   st, st; jumptable 1001376D case 6 }
      return;
    case 7:
      __asm { fdivrp  st, st; jumptable 1001376D case 7 }
      return;
    case 8:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 1001376D case 8
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fld     [esp+2Ch+var_C]
        fxch    st(1)
      }
      return;
    case 9:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label10;
    case 0xA:
label10:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 1001376D case 10
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fld     [esp+arg_8]
        fxch    st(1)
      }
      return;
    case 0xB:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label12;
    case 0xC:
label12:
      __asm
      {
        fxch    st(1); jumptable 1001376D case 12
        fstp    [esp+arg_8]; _TBYTE
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm { fld     [esp+arg_1C] }
      return;
    case 0xD:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 1001376D case 13
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      return;
    case 0xE:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 1001376D case 14
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fld     [esp+2Ch+var_20] }
      return;
    case 0xF:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 1001376D case 15
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      return;
    case 0x10:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 1001376D case 16
        fxch    st(1)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(1)
        fld     [esp+2Ch+var_C]
        fxch    st(2)
      }
      return;
    case 0x11:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label18;
    case 0x12:
label18:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 1001376D case 18
        fxch    st(1)
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(1)
        fld     [esp+arg_8]
        fxch    st(2)
      }
      return;
    case 0x13:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label20;
    case 0x14:
label20:
      __asm
      {
        fxch    st(2); jumptable 1001376D case 20
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(1)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(1)
        fld     [esp+arg_1C]
      }
      return;
    case 0x15:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 1001376D case 21
        fxch    st(1)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(1) }
      return;
    case 0x16:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 1001376D case 22
        fxch    st(1)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(1)
        fld     [esp+2Ch+var_20]
      }
      return;
    case 0x17:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 1001376D case 23
        fxch    st(1)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(1) }
      return;
    case 0x18:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 1001376D case 24
        fxch    st(2)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(2)
        fld     [esp+2Ch+var_C]
        fxch    st(3)
      }
      return;
    case 0x19:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label26;
    case 0x1A:
label26:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 1001376D case 26
        fxch    st(2)
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(2)
        fld     [esp+arg_8]
        fxch    st(3)
      }
      return;
    case 0x1B:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label28;
    case 0x1C:
label28:
      __asm
      {
        fxch    st(3); jumptable 1001376D case 28
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(2)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(2)
        fld     [esp+arg_1C]
      }
      return;
    case 0x1D:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 1001376D case 29
        fxch    st(2)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(2) }
      return;
    case 0x1E:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 1001376D case 30
        fxch    st(2)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(2)
        fld     [esp+2Ch+var_20]
      }
      return;
    case 0x1F:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 1001376D case 31
        fxch    st(2)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(2) }
      return;
    case 0x20:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 1001376D case 32
        fxch    st(3)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(3)
        fld     [esp+2Ch+var_C]
        fxch    st(4)
      }
      return;
    case 0x21:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label34;
    case 0x22:
label34:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 1001376D case 34
        fxch    st(3)
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(3)
        fld     [esp+arg_8]
        fxch    st(4)
      }
      return;
    case 0x23:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label36;
    case 0x24:
label36:
      __asm
      {
        fxch    st(4); jumptable 1001376D case 36
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(3)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(3)
        fld     [esp+arg_1C]
      }
      return;
    case 0x25:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 1001376D case 37
        fxch    st(3)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(3) }
      return;
    case 0x26:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 1001376D case 38
        fxch    st(3)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(3)
        fld     [esp+2Ch+var_20]
      }
      return;
    case 0x27:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 1001376D case 39
        fxch    st(3)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(3) }
      return;
    case 0x28:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 1001376D case 40
        fxch    st(4)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(4)
        fld     [esp+2Ch+var_C]
        fxch    st(5)
      }
      return;
    case 0x29:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label42;
    case 0x2A:
label42:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 1001376D case 42
        fxch    st(4)
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(4)
        fld     [esp+arg_8]
        fxch    st(5)
      }
      return;
    case 0x2B:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label44;
    case 0x2C:
label44:
      __asm
      {
        fxch    st(5); jumptable 1001376D case 44
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(4)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(4)
        fld     [esp+arg_1C]
      }
      return;
    case 0x2D:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 1001376D case 45
        fxch    st(4)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(4) }
      return;
    case 0x2E:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 1001376D case 46
        fxch    st(4)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(4)
        fld     [esp+2Ch+var_20]
      }
      return;
    case 0x2F:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 1001376D case 47
        fxch    st(4)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(4) }
      return;
    case 0x30:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 1001376D case 48
        fxch    st(5)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(5)
        fld     [esp+2Ch+var_C]
        fxch    st(6)
      }
      return;
    case 0x31:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label50;
    case 0x32:
label50:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 1001376D case 50
        fxch    st(5)
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(5)
        fld     [esp+arg_8]
        fxch    st(6)
      }
      return;
    case 0x33:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label52;
    case 0x34:
label52:
      __asm
      {
        fxch    st(6); jumptable 1001376D case 52
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(5)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(5)
        fld     [esp+arg_1C]
      }
      return;
    case 0x35:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 1001376D case 53
        fxch    st(5)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(5) }
      return;
    case 0x36:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 1001376D case 54
        fxch    st(5)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(5)
        fld     [esp+2Ch+var_20]
      }
      return;
    case 0x37:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 1001376D case 55
        fxch    st(5)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(5) }
      return;
    case 0x38:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 1001376D case 56
        fxch    st(6)
        fld     st
        fstp    [esp+2Ch+var_2C]; _TBYTE
        fstp    [esp+2Ch+var_C]
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(6)
        fld     [esp+2Ch+var_C]
        fxch    st(7)
      }
      return;
    case 0x39:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label58;
    case 0x3A:
label58:
      __asm
      {
        fstp    tbyte ptr [esp+0]; jumptable 1001376D case 58
        fxch    st(6)
        fstp    [esp+arg_8]; _TBYTE
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(6)
        fld     [esp+arg_8]
        fxch    st(7)
      }
      return;
    case 0x3B:
      __asm { int     6;  - internal hardware - UNDEFINED OPCODE (80286+) }
      goto label60;
    case 0x3C:
label60:
      __asm
      {
        fxch    st(7); jumptable 1001376D case 60
        fstp    [esp+arg_8]; _TBYTE
        fxch    st(6)
        fld     st
        fstp    tbyte ptr [esp+0]; _TBYTE
        fstp    [esp+arg_1C]
      }
      fdiv_main_routine(a1: v17, a2: v18);
      __asm
      {
        fxch    st(6)
        fld     [esp+arg_1C]
      }
      break;
    case 0x3D:
      __asm
      {
        fstp    [esp+2Ch+var_2C]; jumptable 1001376D case 61
        fxch    st(6)
        fstp    [esp+2Ch+var_20]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(6) }
      break;
    case 0x3E:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 1001376D case 62
        fxch    st(6)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm
      {
        fxch    st(6)
        fld     [esp+2Ch+var_20]
      }
      break;
    case 0x3F:
      __asm
      {
        fstp    [esp+2Ch+var_20]; jumptable 1001376D case 63
        fxch    st(6)
        fstp    [esp+2Ch+var_2C]; _TBYTE
      }
      fdiv_main_routine(a1: v1, a2: v2);
      __asm { fxch    st(6) }
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013C06
// Name: __fdivp_sti_st
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _fdivp_sti_st(double a1@<st1>, double a2@<st0>)
{
  _TBYTE v2; // [esp+0h] [ebp-2Ch]
  _TBYTE v3; // [esp+Ch] [ebp-20h]

  *(double *)&v2 = a1;
  *(double *)&v3 = a2;
  fdiv_main_routine(a1: v2, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10013C19
// Name: __fdivrp_sti_st
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _fdivrp_sti_st(double a1@<st1>, double a2@<st0>)
{
  _TBYTE v2; // [esp+0h] [ebp-2Ch]
  _TBYTE v3; // [esp+Ch] [ebp-20h]

  *(double *)&v3 = a1;
  *(double *)&v2 = a2;
  fdiv_main_routine(a1: v2, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10013C2C
// Name: __adj_fdiv_m32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __spoils<edx,ecx,st0> _adj_fdiv_m32(__int16 a1@<fpstat>, double a2@<st1>, double a3@<st0>, float a4)
{
  if ( (LODWORD(a4) & 0x7F800000) != 0x7F800000 )
  {
    if ( (a1 & 0x3800) != 0 )
      _fdivp_sti_st(a1: a2, a2: a3);
    else
      _fdivp_sti_st(a1: a4, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013C78
// Name: __adj_fdiv_m64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __spoils<edx,ecx,st0> _adj_fdiv_m64(__int16 a1@<fpstat>, double a2@<st1>, double a3@<st0>, double a4)
{
  if ( (HIDWORD(a4) & 0x7FF00000) != 0x7FF00000 )
  {
    if ( (a1 & 0x3800) != 0 )
      _fdivp_sti_st(a1: a2, a2: a3);
    else
      _fdivp_sti_st(a1: a4, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013CC4
// Name: __adj_fdiv_m16i
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __spoils<edx,ecx,st0> _adj_fdiv_m16i(
        __int16 a1@<fpstat>,
        double a2@<st1>,
        double a3@<st0>,
        __int16 a4)
{
  if ( (a1 & 0x3800) != 0 )
    _fdivp_sti_st(a1: a2, a2: a3);
  else
    _fdivp_sti_st(a1: (double)a4, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10013CF8
// Name: __adj_fdiv_m32i
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __spoils<edx,ecx,st0> _adj_fdiv_m32i(__int16 a1@<fpstat>, double a2@<st1>, double a3@<st0>, int a4)
{
  if ( (a1 & 0x3800) != 0 )
    _fdivp_sti_st(a1: a2, a2: a3);
  else
    _fdivp_sti_st(a1: (double)a4, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10013D2C
// Name: __adj_fdivr_m32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __spoils<edx,ecx,st0> _adj_fdivr_m32(__int16 a1@<fpstat>, double a2@<st1>, double a3@<st0>, float a4)
{
  if ( (LODWORD(a4) & 0x7F800000) != 0x7F800000 )
  {
    if ( (a1 & 0x3800) != 0 )
      _fdivrp_sti_st(a1: a2, a2: a3);
    else
      _fdivrp_sti_st(a1: a4, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013D78
// Name: __adj_fdivr_m64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __spoils<edx,ecx,st0> _adj_fdivr_m64(__int16 a1@<fpstat>, double a2@<st1>, double a3@<st0>, double a4)
{
  if ( (HIDWORD(a4) & 0x7FF00000) != 0x7FF00000 )
  {
    if ( (a1 & 0x3800) != 0 )
      _fdivrp_sti_st(a1: a2, a2: a3);
    else
      _fdivrp_sti_st(a1: a4, a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10013DC4
// Name: __adj_fdivr_m16i
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __spoils<edx,ecx,st0> _adj_fdivr_m16i(
        __int16 a1@<fpstat>,
        double a2@<st1>,
        double a3@<st0>,
        __int16 a4)
{
  if ( (a1 & 0x3800) != 0 )
    _fdivrp_sti_st(a1: a2, a2: a3);
  else
    _fdivrp_sti_st(a1: (double)a4, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10013DF8
// Name: __adj_fdivr_m32i
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge __spoils<edx,ecx,st0> _adj_fdivr_m32i(__int16 a1@<fpstat>, double a2@<st1>, double a3@<st0>, int a4)
{
  if ( (a1 & 0x3800) != 0 )
    _fdivrp_sti_st(a1: a2, a2: a3);
  else
    _fdivrp_sti_st(a1: (double)a4, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10013E2C
// Name: __safe_fdiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __spoils<edx,ecx,st0> _safe_fdiv(double a1@<st1>, double a2@<st0>)
{
  _TBYTE v2; // [esp+0h] [ebp-30h]
  _TBYTE v3; // [esp+Ch] [ebp-24h]

  *(double *)&v2 = a1;
  *(double *)&v3 = a2;
  fdiv_main_routine(a1: v2, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10013E41
// Name: __safe_fdivr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __spoils<edx,ecx,st0> _safe_fdivr(double a1@<st1>, double a2@<st0>)
{
  _TBYTE v2; // [esp+0h] [ebp-30h]
  _TBYTE v3; // [esp+Ch] [ebp-24h]

  *(double *)&v3 = a1;
  *(double *)&v2 = a2;
  fdiv_main_routine(a1: v2, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10013E56
// Name: __fprem_common
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _fprem_common@<eax>(char a1@<dl>, __int128 a2, int a3, int a4, __int128 a5)
{
  unsigned int result; // eax
  int v6; // ecx
  double v7; // st7
  __int16 v8; // fps
  double v9; // st6
  bool v10; // c0
  char v11; // c2
  bool v12; // c3
  __int16 v13; // fps

  result = *(_DWORD *)((char *)&a2 + 6) ^ 0x700;
  if ( ((*(_DWORD *)((char *)&a2 + 6) ^ 0x700) & 0x700) == 0 )
  {
    result = (result >> 11) & 0xF;
    if ( fprem_risc_table[result] != 0 )
    {
      result = *(_DWORD *)((_BYTE *)&a2 + 6) & 0x7FFF0000;
      if ( (*(_DWORD *)((_BYTE *)&a2 + 6) & 0x7FFF0000) != 0x7FFF0000 )
      {
        result = *(_DWORD *)((_BYTE *)&a5 + 6) & 0x7FFF0000;
        if ( (*(_DWORD *)((_BYTE *)&a5 + 6) & 0x7FFF0000) != 0 && result != 2147418112 )
        {
          result = 2 * DWORD1(a5);
          if ( 2 * DWORD1(a5) == 0 )
          {
            result = 2 * DWORD1(a2);
            if ( 2 * DWORD1(a2) == 0 )
            {
              if ( (WORD4(a5) & 0x7FFFu) > (WORD4(a2) & 0x7FFFu) + 63 )
              {
                v6 = ((BYTE8(a5) - BYTE8(a2)) & 0x3F | 0x20) + 1;
                v7 = fabs(*(long double *)&a2);
                v9 = fabs(*(long double *)&a5);
                do
                {
                  v10 = v9 < v7;
                  v11 = 0;
                  v12 = v9 == v7;
                  result = v8 & 0x100;
                  if ( (v8 & 0x100) == 0 )
                    v9 = v9 - v7;
                  v7 = v7 * *(double *)&half;
                  --v6;
                }
                while ( v6 != 0 );
              }
              else
              {
                while ( 1 )
                {
                  result = (WORD4(a2) & 0x7FFF) + 10;
                  if ( (int)((WORD4(a5) & 0x7FFF) - result) < 0 )
                    break;
                  *(double *)&a5 = __FPREM__(*(long double *)&a5, *(long double *)&a2);
                }
              }
            }
          }
        }
      }
    }
  }
  if ( (a1 & 3) != 0 )
  {
    __asm { fnstenv [esp+28h+var_28] }
    __asm { fldenv  [esp+28h+var_28] }
    return v13 & 0x4300;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001405C
// Name: __adj_fprem
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall __spoils<ecx,st0> _adj_fprem@<eax>(double a1@<st1>, double a2@<st0>)
{
  int result; // eax
  char v3; // dl
  _BYTE v4[20]; // [esp+0h] [ebp-34h]
  int v5; // [esp+14h] [ebp-20h]
  __int128 v6; // [esp+18h] [ebp-1Ch]

  *(double *)&v6 = a1;
  *(double *)v4 = a2;
  if ( (*(_DWORD *)&v4[6] & 0x7FFF0000) != 0 )
    return _fprem_common(a1: 0, a2: *(__int128 *)v4, a3: *(int *)&v4[16], a4: v5, a5: v6);
  result = *(_DWORD *)&v4[4] | *(_DWORD *)v4;
  if ( a2 != 0.0 )
  {
    *(double *)&v4[12] = a2;
    v3 = 2;
    if ( (WORD4(v6) & 0x7FFFu) <= 0x7FBE )
    {
      v3 = 3;
      *(double *)&v6 = a1 * *(double *)&one_shl_64;
    }
    *(double *)v4 = a2 * *(double *)&one_shl_64;
    return _fprem_common(a1: v3, a2: *(__int128 *)v4, a3: HIDWORD(*(unsigned __int64 *)&a2), a4: v5, a5: v6);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001410E
// Name: __fprem1_common
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _fprem1_common@<eax>(char a1@<dl>, __int128 a2, int a3, int a4, __int128 a5)
{
  unsigned int result; // eax
  int v6; // ecx
  double v7; // st7
  __int16 v8; // fps
  double v9; // st6
  bool v10; // c0
  char v11; // c2
  bool v12; // c3
  __int16 v13; // fps

  result = *(_DWORD *)((char *)&a2 + 6) ^ 0x700;
  if ( ((*(_DWORD *)((char *)&a2 + 6) ^ 0x700) & 0x700) == 0 )
  {
    result = (result >> 11) & 0xF;
    if ( fprem_risc_table[result] != 0 )
    {
      result = *(_DWORD *)((_BYTE *)&a2 + 6) & 0x7FFF0000;
      if ( (*(_DWORD *)((_BYTE *)&a2 + 6) & 0x7FFF0000) != 0x7FFF0000 )
      {
        result = *(_DWORD *)((_BYTE *)&a5 + 6) & 0x7FFF0000;
        if ( (*(_DWORD *)((_BYTE *)&a5 + 6) & 0x7FFF0000) != 0 && result != 2147418112 )
        {
          result = 2 * DWORD1(a5);
          if ( 2 * DWORD1(a5) == 0 )
          {
            result = 2 * DWORD1(a2);
            if ( 2 * DWORD1(a2) == 0 )
            {
              if ( (WORD4(a5) & 0x7FFFu) > (WORD4(a2) & 0x7FFFu) + 63 )
              {
                v6 = ((BYTE8(a5) - BYTE8(a2)) & 0x3F | 0x20) + 1;
                v7 = fabs(*(long double *)&a2);
                v9 = fabs(*(long double *)&a5);
                do
                {
                  v10 = v9 < v7;
                  v11 = 0;
                  v12 = v9 == v7;
                  result = v8 & 0x100;
                  if ( (v8 & 0x100) == 0 )
                    v9 = v9 - v7;
                  v7 = v7 * *(double *)&half;
                  --v6;
                }
                while ( v6 != 0 );
              }
              else
              {
                while ( 1 )
                {
                  result = (WORD4(a2) & 0x7FFF) + 10;
                  if ( (int)((WORD4(a5) & 0x7FFF) - result) < 0 )
                    break;
                  *(double *)&a5 = __FPREM__(*(long double *)&a5, *(long double *)&a2);
                }
              }
            }
          }
        }
      }
    }
  }
  if ( (a1 & 3) != 0 )
  {
    __asm { fnstenv [esp+28h+var_28] }
    __asm { fldenv  [esp+28h+var_28] }
    return v13 & 0x4300;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014314
// Name: __adj_fprem1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall __spoils<ecx,st0> _adj_fprem1@<eax>(double a1@<st1>, double a2@<st0>)
{
  int result; // eax
  char v3; // dl
  _BYTE v4[20]; // [esp+0h] [ebp-34h]
  int v5; // [esp+14h] [ebp-20h]
  __int128 v6; // [esp+18h] [ebp-1Ch]

  *(double *)&v6 = a1;
  *(double *)v4 = a2;
  if ( (*(_DWORD *)&v4[6] & 0x7FFF0000) != 0 )
    return _fprem1_common(a1: 0, a2: *(__int128 *)v4, a3: *(int *)&v4[16], a4: v5, a5: v6);
  result = *(_DWORD *)&v4[4] | *(_DWORD *)v4;
  if ( a2 != 0.0 )
  {
    *(double *)&v4[12] = a2;
    v3 = 2;
    if ( (WORD4(v6) & 0x7FFFu) <= 0x7FBE )
    {
      v3 = 3;
      *(double *)&v6 = a1 * *(double *)&one_shl_64;
    }
    *(double *)v4 = a2 * *(double *)&one_shl_64;
    return _fprem1_common(a1: v3, a2: *(__int128 *)v4, a3: HIDWORD(*(unsigned __int64 *)&a2), a4: v5, a5: v6);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100143C9
// Name: __safe_fprem
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __usercall _safe_fprem@<eax>(double a1@<st1>, double a2@<st0>)
{
  return _adj_fprem(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x100143CF
// Name: __safe_fprem1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __usercall _safe_fprem1@<eax>(double a1@<st1>, double a2@<st0>)
{
  return _adj_fprem1(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x100143D5
// Name: __adj_fpatan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall _adj_fpatan@<st0>(long double a1@<st1>, long double a2@<st0>)
{
  return atan2(a2, a1);
}

//------------------------------------------------------------------------------
// Address: 0x100143D8
// Name: __adj_fptan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _adj_fptan()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100143E0
// Name: __CIpow_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _CIpow_pentium4()
{
  JUMPOUT(0x100143F9);
}

//------------------------------------------------------------------------------
// Address: 0x10014F51
// Name: __fFEXP
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _fFEXP@<eax>(__int16 a1@<cx>, int a2@<ebp>, double a3@<st0>)
{
  double v3; // st7

  *(_BYTE *)(a2 - 144) = -2;
  HIBYTE(a1) = 0;
  v3 = a3 * 1.442695040888963407;
  _ffexpm1(a1);
  if ( (*(_BYTE *)(a2 - 159) & 1) != 0 && _adjust_fdiv == 1 )
    _safe_fdivr(a1: 1.442695040888963407 + 1.0, a2: v3);
  return _rttospop();
}

//------------------------------------------------------------------------------
// Address: 0x10014FB8
// Name: __rtinfpopse
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _rtinfpopse@<eax>(double a1@<st0>)
{
  return _rtinfnpopse(a1);
}

//------------------------------------------------------------------------------
// Address: 0x10014FBA
// Name: __rtinfnpopse
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _rtinfnpopse@<st0>(int a1@<ebp>)
{
  double result; // st7

  result = *(double *)&_infinity;
  *(_BYTE *)(a1 - 144) = 2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10014FCA
// Name: __fFLN
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall _fFLN@<st0>(int a1@<ebp>, long double a2@<st0>)
{
  __int16 v2; // fps
  bool v3; // c0
  char v4; // c2
  bool v5; // c3
  long double result; // st7

  v3 = a2 < 0.0;
  v4 = 0;
  v5 = a2 == 0.0;
  *(_WORD *)(a1 - 160) = v2;
  if ( (*(_BYTE *)(a1 - 159) & 0x41) == 0 )
    return __FYL2X__(a2, 0.6931471805599453094);
  _rtindfpop(a1: 0.6931471805599453094);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10015027
// Name: zerotoxdone
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void zerotoxdone()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1001507F
// Name: __rtinfpop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _rtinfpop@<eax>(double a1@<st0>)
{
  return _rtinfnpop(a1);
}

//------------------------------------------------------------------------------
// Address: 0x10015081
// Name: __rtinfnpop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __usercall _rtinfnpop@<st0>(int a1@<ebp>)
{
  double result; // st7

  result = *(double *)&_infinity;
  *(_BYTE *)(a1 - 144) = 3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10015091
// Name: _rtforexpinf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __fastcall rtforexpinf(char a1)
{
  double result; // st7

  if ( a1 == 0 )
    return *(double *)&_infinity;
  _rtzeronpop();
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001509E
// Name: __ffexpm1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
double __usercall _ffexpm1@<st0>(char a1@<ch>, int _EBP@<ebp>)
{
  double result; // st7

  __asm
  {
    fld     st
    fabs
    fld     _log2max
    fcompp
    fstsw   word ptr [ebp-0A0h]
  }
  if ( (*(_BYTE *)(_EBP - 159) & 0x41) != 0 )
  {
    __asm
    {
      ftst
      fstsw   word ptr [ebp-0A0h]
    }
    if ( (*(_BYTE *)(_EBP - 159) & 1) != 0 )
    {
      *(_BYTE *)(_EBP - 144) = 4;
      return _rtzeronpop();
    }
    else
    {
      __asm
      {
        fstp    st
        fld     __infinity
      }
      if ( a1 != 0 )
        __asm { fchs }
    }
  }
  else
  {
    __asm
    {
      fld     st
      frndint
      ftst
      fstsw   word ptr [ebp-0A0h]
    }
    __asm
    {
      fxch    st(1)
      fsub    st, st(1)
      ftst
      fstsw   word ptr [ebp-0A0h]
      fabs
      f2xm1
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100150E1
// Name: _isintTOS
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall isintTOS@<eax>(long double a1@<st0>)
{
  if ( rint(a1) != a1 )
    return notanint();
  if ( rint(a1 * *(double *)&half) == a1 * *(double *)&half )
    return evenint();
  return isintTOSret();
}

//------------------------------------------------------------------------------
// Address: 0x10015106
// Name: _isintTOSret
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void isintTOSret()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10015107
// Name: notanint
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void notanint()
{
  isintTOSret();
}

//------------------------------------------------------------------------------
// Address: 0x1001510E
// Name: evenint
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void evenint()
{
  isintTOSret();
}

//------------------------------------------------------------------------------
// Address: 0x10015115
// Name: _usepowhlp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __usercall usepowhlp@<st0>(int a1@<ebp>, long double y@<st1>, long double x@<st0>)
{
  int v4; // eax
  long double result; // st7
  long double *v6; // [esp+10h] [ebp-7Ch]
  long double v7[15]; // [esp+14h] [ebp-78h] BYREF

  _ESI = v7;
  v6 = v7;
  __asm { fsave   byte ptr [esi+8] }
  v4 = _powhlp(x, y, result: v7);
  __asm { frstor  byte ptr [esi+8] }
  result = v7[0];
  if ( v4 != 0 )
    _rttosnpopde(a1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10015147
// Name: __d_inttype
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _d_inttype(long double y)
{
  if ( (_fpclass(x: y) & 0x90) != 0 || _frnd(x: y) != y )
    return 0;
  if ( _frnd(x: y * 0.5) == y * 0.5 )
    return 2;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100151AB
// Name: __powhlp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _powhlp(double x, long double y, long double *result)
{
  long double dbl; // st7
  int v4; // esi
  long double v5; // st6
  double *v6; // eax
  int v7; // eax

  dbl = 0.0;
  v4 = 0;
  v5 = x;
  if ( x < 0.0 )
    v5 = -x;
  if ( HIDWORD(y) == 2146435072 )
  {
    if ( LODWORD(y) == 0 )
    {
      if ( v5 <= 1.0 )
      {
        v6 = result;
        if ( v5 >= 1.0 )
          dbl = 1.0;
        goto LABEL_28;
      }
      goto LABEL_6;
    }
  }
  else if ( y == -INFINITY )
  {
    if ( v5 > 1.0 )
      goto LABEL_27;
    v6 = result;
    if ( v5 < 1.0 )
    {
      dbl = _d_inf.dbl;
LABEL_28:
      *v6 = dbl;
      return v4;
    }
    *result = _d_ind.dbl;
    return 1;
  }
  if ( HIDWORD(x) == 2146435072 )
  {
    if ( LODWORD(x) == 0 )
    {
      if ( y <= 0.0 )
      {
        v6 = result;
        if ( y >= 0.0 )
          dbl = 1.0;
        goto LABEL_28;
      }
LABEL_6:
      dbl = _d_inf.dbl;
LABEL_27:
      v6 = result;
      goto LABEL_28;
    }
  }
  else if ( x == -INFINITY )
  {
    v7 = _d_inttype(y);
    dbl = 0.0;
    if ( y <= 0.0 )
    {
      if ( y >= 0.0 )
      {
        dbl = 1.0;
      }
      else if ( v7 == 1 )
      {
        dbl = _d_mzero.dbl;
      }
    }
    else
    {
      dbl = _d_inf.dbl;
      if ( v7 == 1 )
        dbl = -_d_inf.dbl;
    }
    goto LABEL_27;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100152F0
// Name: _sin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl sin(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v1 = _mm_getcsr() & 0x1F80;
    v2 = v1 == 8064;
    if ( v1 == 8064 )
      v2 = (v4 & 0x7F) == 127;
    if ( v2 )
      JUMPOUT(0x10019368);
  }
  JUMPOUT(0x1001537F);
}

//------------------------------------------------------------------------------
// Address: 0x10015330
// Name: __CIsin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CIsin(__int64 a1)
{
  int v2; // eax
  bool v3; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CIsin;
  v2 = _mm_getcsr() & 0x1F80;
  v3 = v2 == 8064;
  if ( v2 == 8064 )
    v3 = (v4 & 0x7F) == 127;
  if ( v3 )
    _CIsin_pentium4(a1);
  else
__CIsin:
    _CIsin_default(a1);
}

//------------------------------------------------------------------------------
// Address: 0x1001536B
// Name: __CIsin_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10015420
// Name: _cos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl cos(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v1 = _mm_getcsr() & 0x1F80;
    v2 = v1 == 8064;
    if ( v1 == 8064 )
      v2 = (v4 & 0x7F) == 127;
    if ( v2 )
      JUMPOUT(0x10019538);
  }
  JUMPOUT(0x100154AF);
}

//------------------------------------------------------------------------------
// Address: 0x10015460
// Name: __CIcos
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CIcos(__int64 a1)
{
  int v2; // eax
  bool v3; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CIcos;
  v2 = _mm_getcsr() & 0x1F80;
  v3 = v2 == 8064;
  if ( v2 == 8064 )
    v3 = (v4 & 0x7F) == 127;
  if ( v3 )
    _CIcos_pentium4(a1);
  else
__CIcos:
    _CIcos_default(a1);
}

//------------------------------------------------------------------------------
// Address: 0x1001549B
// Name: __CIcos_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10015550
// Name: _tan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl tan(double X)
{
  int v1; // eax
  bool v2; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns != 0 )
  {
    v1 = _mm_getcsr() & 0x1F80;
    v2 = v1 == 8064;
    if ( v1 == 8064 )
      v2 = (v4 & 0x7F) == 127;
    if ( v2 )
      JUMPOUT(0x100196E8);
  }
  JUMPOUT(0x100155DF);
}

//------------------------------------------------------------------------------
// Address: 0x10015590
// Name: __CItan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CItan(__int64 a1)
{
  int v2; // eax
  bool v3; // zf
  char v4; // [esp+0h] [ebp-8h]

  if ( __use_sse2_mathfcns == 0 )
    goto __CItan;
  v2 = _mm_getcsr() & 0x1F80;
  v3 = v2 == 8064;
  if ( v2 == 8064 )
    v3 = (v4 & 0x7F) == 127;
  if ( v3 )
    _CItan_pentium4(a1);
  else
__CItan:
    _CItan_default(a1);
}

//------------------------------------------------------------------------------
// Address: 0x100155CB
// Name: __CItan_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1001567D
// Name: ___libm_error_support
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __libm_error_support(long double *arg1, long double *arg2, long double *retval, error_types input_tag)
{
  int (__cdecl *v4)(_exception *); // eax
  long double v5; // st7
  long double v6; // st7
  long double v7; // st7
  _exception exc; // [esp+Ch] [ebp-28h] BYREF
  char double_zero[8]; // [esp+2Ch] [ebp-8h]

  double_zero[0] = 0;
  double_zero[1] = 0;
  double_zero[2] = 0;
  double_zero[3] = 0;
  double_zero[4] = 0;
  double_zero[5] = 0;
  double_zero[6] = 0;
  double_zero[7] = 0;
  if ( pmatherr_set != 0 )
    v4 = (int (__cdecl *)(_exception *))_decode_pointer(codedptr: _pmatherr);
  else
    v4 = _matherr;
  if ( input_tag > exp10_overflow )
  {
    switch ( input_tag )
    {
      case log_nan:
        exc.name = "log";
        goto LABEL_37;
      case log10_nan:
        exc.name = "log10";
        goto LABEL_37;
      case exp_nan:
        exc.name = "exp";
        goto LABEL_37;
      case atan_nan:
        exc.name = "atan";
        goto LABEL_37;
      case ceil_nan:
        exc.name = "ceil";
        goto LABEL_37;
      case floor_nan:
        exc.name = "floor";
        goto LABEL_37;
      case pow_nan:
        goto $LN36_0;
      case modf_nan:
        exc.name = "modf";
        goto LABEL_37;
      case acos_nan:
        goto $LN30_0;
      case asin_nan:
        goto $LN8_3;
      case sin_naninf:
        exc.name = "sin";
        goto LABEL_53;
      case cos_naninf:
        exc.name = "cos";
        goto LABEL_53;
      case tan_naninf:
        exc.name = "tan";
LABEL_53:
        v6 = *arg1 * *(double *)double_zero;
        *retval = v6;
        exc.arg1 = *arg1;
        exc.arg2 = *arg2;
        goto LABEL_54;
      default:
        return;
    }
  }
  if ( input_tag == exp10_overflow )
  {
    exc.type = 3;
    exc.name = "exp10";
    goto LABEL_17;
  }
  if ( input_tag <= pow_underflow )
  {
    switch ( input_tag )
    {
      case pow_underflow:
        exc.name = "pow";
        goto LABEL_20;
      case log_zero:
        exc.type = 2;
        exc.name = "log";
        goto LABEL_17;
      case log_negative:
        exc.name = "log";
        break;
      case log10_zero:
        exc.type = 2;
        exc.name = "log10";
        goto LABEL_17;
      case log10_negative:
        exc.name = "log10";
        break;
      case exp_overflow:
        exc.type = 3;
        exc.name = "exp";
LABEL_17:
        exc.arg1 = *arg1;
        exc.arg2 = *arg2;
        exc.retval = *retval;
        if ( v4(pexcept: &exc) == 0 )
          *_errno() = 34;
        goto LABEL_56;
      case exp_underflow:
        exc.name = "exp";
LABEL_20:
        exc.arg1 = *arg1;
        v5 = *arg2;
        exc.type = 4;
        exc.arg2 = v5;
        exc.retval = *retval;
        v4(pexcept: &exc);
LABEL_56:
        v7 = exc.retval;
        goto LABEL_57;
      case pow_overflow:
        exc.type = 3;
        goto LABEL_16;
      default:
        return;
    }
LABEL_23:
    exc.arg1 = *arg1;
    exc.arg2 = *arg2;
    v6 = *retval;
LABEL_54:
    exc.retval = v6;
    exc.type = 1;
    if ( v4(pexcept: &exc) == 0 )
      *_errno() = 33;
    goto LABEL_56;
  }
  if ( input_tag != pow_zero_to_zero )
  {
    switch ( input_tag )
    {
      case pow_zero_to_negative:
        exc.type = 2;
LABEL_16:
        exc.name = "pow";
        goto LABEL_17;
      case pow_neg_to_non_integer:
$LN36_0:
        exc.name = "pow";
        break;
      case pow_nan_to_zero:
        exc.name = "pow";
LABEL_37:
        *retval = *arg1;
        break;
      case acos_gt_one:
$LN30_0:
        exc.name = "acos";
        break;
      case asin_gt_one:
$LN8_3:
        exc.name = "asin";
        break;
      default:
        return;
    }
    goto LABEL_23;
  }
  v7 = 1.0;
LABEL_57:
  *retval = v7;
}

//------------------------------------------------------------------------------
// Address: 0x1001592D
// Name: __floor_default
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _floor_default(long double x)
{
  unsigned int v1; // ebx
  int v2; // eax
  long double v4; // [esp+1Ch] [ebp-8h]

  v1 = _ctrlfp(newctrl: newcw, _mask: 0xFFFFu);
  if ( (HIWORD(x) & 0x7FF0) == 0x7FF0 )
  {
    v2 = _sptype(x);
    if ( v2 > 0 )
    {
      if ( v2 <= 2 )
      {
        _ctrlfp(newctrl: v1, _mask: 0xFFFFu);
        return x;
      }
      if ( v2 == 3 )
        return _handle_qnan1(opcode: 0xBu, x, savedcw: v1);
    }
    return _except1(flags: 8, opcode: 11, arg: x, result: x + 1.0, cw: v1);
  }
  else
  {
    v4 = _frnd(x);
    if ( x == v4 || (v1 & 0x20) != 0 )
    {
      _ctrlfp(newctrl: v1, _mask: 0xFFFFu);
      return v4;
    }
    else
    {
      return _except1(flags: 16, opcode: 11, arg: x, result: v4, cw: v1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100159FE
// Name: has_osfxsr_set
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl has_osfxsr_set()
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10015A4E
// Name: __get_sse2_info
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _get_sse2_info()
{
  unsigned int v0; // kr00_4
  unsigned int v1; // kr04_4
  int cpu_feature; // [esp+18h] [ebp-4h]

  cpu_feature = 0;
  v0 = __readeflags();
  __writeeflags(v0 ^ 0x200000);
  v1 = __readeflags();
  if ( v1 != v0 )
  {
    __writeeflags(v0);
    _EAX = 0;
    __asm { cpuid }
    _EAX = 1;
    __asm { cpuid }
    cpu_feature = _EDX;
  }
  return (cpu_feature & 0x4000000) != 0 && has_osfxsr_set() != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10015AAE
// Name: ___sse2_available_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __sse2_available_init()
{
  __sse2_available = _get_sse2_info();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10015ABB
// Name: __lseeki64_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
doubleint __cdecl _lseeki64_nolock(int fh, __int64 pos, DWORD mthd)
{
  void *osfhandle; // eax
  DWORD LastError; // eax
  char *p_osfile; // eax
  doubleint newpos; // [esp+8h] [ebp-8h] BYREF

  newpos.bigint = pos;
  osfhandle = (void *)_get_osfhandle(fh);
  if ( osfhandle == (void *)-1 )
  {
    *_errno() = 9;
    return (doubleint)-1LL;
  }
  newpos.twoints.lowerhalf = SetFilePointer(
                               hFile: osfhandle,
                               lDistanceToMove: newpos.twoints.lowerhalf,
                               lpDistanceToMoveHigh: &newpos.twoints.upperhalf,
                               dwMoveMethod: mthd);
  if ( newpos.twoints.lowerhalf == -1 )
  {
    LastError = GetLastError();
    if ( LastError != 0 )
    {
      _dosmaperr(oserrno: LastError);
      return (doubleint)-1LL;
    }
  }
  p_osfile = &__pioinfo[fh >> 5][fh & 0x1F].osfile;
  *p_osfile &= ~2u;
  return newpos;
}

//------------------------------------------------------------------------------
// Address: 0x10015B3E
// Name: __lseeki64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _lseeki64@<eax>(unsigned int a1@<ebx>, int fh, __int64 pos, DWORD mthd)
{
  ioinfo **v5; // ebx
  unsigned int v6; // esi
  unsigned int r; // [esp+10h] [ebp-24h]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter(a1, a2: 0, a3: 0xFFFFFFFF);
    return -1;
  }
  v5 = &__pioinfo[fh >> 5];
  v6 = (fh & 0x1F) << 6;
  if ( (*(&(*v5)->osfile + v6) & 1) != 0 )
  {
    __lock_fhandle(fh);
    if ( (*(&(*v5)->osfile + v6) & 1) != 0 )
    {
      r = _lseeki64_nolock(fh, pos, mthd).twoints.lowerhalf;
    }
    else
    {
      *_errno() = 9;
      *__doserrno() = 0;
      r = -1;
    }
    _unlock_fhandle(fh);
    return r;
  }
  else
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter(a1: (unsigned int)v5, a2: 0, a3: v6);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10015C57
// Name: __write_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _write_nolock@<eax>(char a1@<bl>, unsigned int a2@<edi>, int fh, char *buf, DWORD cnt)
{
  ioinfo **v6; // esi
  unsigned int v7; // edi
  char *v8; // eax
  char v9; // bl
  _tiddata *v10; // eax
  UINT v11; // eax
  char *v12; // ebx
  unsigned __int8 v13; // cl
  ioinfo **v14; // esi
  unsigned int v15; // eax
  int v16; // eax
  DWORD v17; // eax
  int v18; // esi
  ioinfo *v19; // eax
  DWORD v20; // esi
  ioinfo *v21; // ecx
  char v22; // dl
  HANDLE *v23; // eax
  unsigned int v24; // ecx
  char *v25; // eax
  char *v26; // edx
  char v27; // dl
  int v28; // ebx
  unsigned int v29; // ecx
  char *v30; // eax
  unsigned __int16 *v31; // edx
  unsigned __int16 v32; // dx
  int v33; // ebx
  unsigned int v34; // ecx
  wchar_t *v35; // eax
  wchar_t v36; // dx
  int v37; // esi
  int v38; // ebx
  void *v39; // [esp-10h] [ebp-90h]
  unsigned int consoleCP; // [esp+4h] [ebp-7Ch] BYREF
  int bCR; // [esp+8h] [ebp-78h]
  char tmode; // [esp+Fh] [ebp-71h]
  ioinfo **v43; // [esp+10h] [ebp-70h]
  int written; // [esp+14h] [ebp-6Ch] BYREF
  int lfcount; // [esp+18h] [ebp-68h]
  char *s; // [esp+1Ch] [ebp-64h]
  int charcount; // [esp+20h] [ebp-60h]
  char *p; // [esp+24h] [ebp-5Ch] BYREF
  DWORD tmpchar; // [esp+28h] [ebp-58h] BYREF
  unsigned __int16 *pu; // [esp+2Ch] [ebp-54h]
  char utf8_buf[1028]; // [esp+30h] [ebp-50h] BYREF
  wchar_t utf16_buf[170]; // [esp+434h] [ebp+3B4h] BYREF
  char mboutbuf[8]; // [esp+588h] [ebp+508h] BYREF

  s = buf;
  charcount = 0;
  lfcount = 0;
  if ( cnt == 0 )
    return 0;
  if ( buf == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter(a1, a2, a3: 0);
    return -1;
  }
  v6 = &__pioinfo[fh >> 5];
  v7 = (fh & 0x1F) << 6;
  v8 = (char *)*v6 + v7;
  v9 = (char)(2 * v8[36]) >> 1;
  v43 = v6;
  tmode = v9;
  if ( (v9 == 2 || v9 == 1) && (cnt & 1) != 0 )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter(a1: v9, a2: v7, a3: 0);
    return -1;
  }
  if ( (v8[4] & 0x20) != 0 )
    _lseeki64_nolock(fh, pos: 0, mthd: 2u);
  if ( _isatty(fh) != 0 && *(&(*v6)->osfile + v7) < 0 )
  {
    v10 = _getptd();
    v39 = *(void **)((char *)&(*v6)->osfhnd + v7);
    bCR = v10->ptlocinfo->lc_handle[2] == 0;
    if ( GetConsoleMode(hConsoleHandle: v39, lpMode: &consoleCP) && (bCR == 0 || v9 != 0) )
    {
      v11 = GetConsoleCP();
      v12 = s;
      consoleCP = v11;
      p = nullptr;
      pu = nullptr;
      while ( 1 )
      {
        if ( tmode != 0 )
        {
          if ( tmode == 1 || tmode == 2 )
          {
            v20 = *(unsigned __int16 *)v12;
            v12 += 2;
            ++pu;
            tmpchar = v20;
            bCR = (_WORD)v20 == 10;
          }
          if ( tmode == 1 || tmode == 2 )
          {
            if ( _putwch_nolock(ch: tmpchar) != (_WORD)tmpchar )
              goto LABEL_85;
            ++charcount;
            if ( bCR != 0 )
            {
              tmpchar = 13;
              if ( _putwch_nolock(ch: 0xDu) != 13 )
                goto LABEL_85;
              ++charcount;
              ++lfcount;
            }
          }
          goto LABEL_42;
        }
        v13 = *v12;
        v14 = v43;
        bCR = *v12 == 10;
        v15 = (unsigned int)*v43 + v7;
        if ( *(_DWORD *)(v15 + 56) != 0 )
        {
          mboutbuf[0] = *(_BYTE *)(v15 + 52);
          mboutbuf[1] = v13;
          *(_DWORD *)(v15 + 56) = 0;
          v16 = mbtowc(pwc: (wchar_t *)&tmpchar, s: mboutbuf, n: 2u);
        }
        else
        {
          if ( isleadbyte(c: v13) != 0 )
          {
            if ( cnt + s - v12 <= 1 )
            {
              v21 = *v14;
              v22 = *v12;
              ++charcount;
              *(&v21->dbcsBuffer + v7) = v22;
              *(int *)((char *)&(*v14)->dbcsBufferUsed + v7) = 1;
              goto LABEL_86;
            }
            if ( mbtowc(pwc: (wchar_t *)&tmpchar, s: v12, n: 2u) == -1 )
              goto LABEL_86;
            ++v12;
            pu = (unsigned __int16 *)((char *)pu + 1);
            goto LABEL_26;
          }
          v16 = mbtowc(pwc: (wchar_t *)&tmpchar, s: v12, n: 1u);
        }
        if ( v16 == -1 )
          goto LABEL_86;
LABEL_26:
        ++v12;
        pu = (unsigned __int16 *)((char *)pu + 1);
        v17 = WideCharToMultiByte(
                CodePage: consoleCP,
                dwFlags: 0,
                lpWideCharStr: (LPCWCH)&tmpchar,
                cchWideChar: 1,
                lpMultiByteStr: mboutbuf,
                cbMultiByte: 5,
                lpDefaultChar: nullptr,
                lpUsedDefaultChar: nullptr);
        v18 = v17;
        if ( v17 == 0 )
          goto LABEL_86;
        if ( !WriteFile(
                hFile: *(HANDLE *)((char *)&(*v43)->osfhnd + v7),
                lpBuffer: mboutbuf,
                nNumberOfBytesToWrite: v17,
                lpNumberOfBytesWritten: (LPDWORD)&p,
                lpOverlapped: nullptr) )
          goto LABEL_85;
        charcount = (int)pu + lfcount;
        if ( (int)p < v18 )
          goto LABEL_86;
        if ( bCR != 0 )
        {
          v19 = *v43;
          mboutbuf[0] = 13;
          if ( !WriteFile(
                  hFile: *(HANDLE *)((char *)&v19->osfhnd + v7),
                  lpBuffer: mboutbuf,
                  nNumberOfBytesToWrite: 1u,
                  lpNumberOfBytesWritten: (LPDWORD)&p,
                  lpOverlapped: nullptr) )
            goto LABEL_85;
          if ( (int)p < 1 )
            goto LABEL_86;
          ++lfcount;
          ++charcount;
        }
LABEL_42:
        if ( (unsigned int)pu >= cnt )
          goto LABEL_86;
      }
    }
  }
  v23 = (HANDLE *)((char *)*v6 + v7);
  if ( *((char *)v23 + 4) >= 0 )
  {
    if ( WriteFile(
           hFile: *v23,
           lpBuffer: s,
           nNumberOfBytesToWrite: cnt,
           lpNumberOfBytesWritten: (LPDWORD)&written,
           lpOverlapped: nullptr) )
    {
      tmpchar = 0;
      charcount = written;
      goto LABEL_86;
    }
  }
  else
  {
    tmpchar = 0;
    if ( v9 != 0 )
    {
      pu = (unsigned __int16 *)s;
      if ( v9 == 2 )
      {
        while ( 1 )
        {
          p = nullptr;
          v29 = (char *)pu - s;
          v30 = utf8_buf;
          do
          {
            if ( v29 >= cnt )
              break;
            v31 = pu++;
            v32 = *v31;
            v29 += 2;
            if ( v32 == 10 )
            {
              lfcount += 2;
              *(_WORD *)v30 = 13;
              v30 += 2;
              p += 2;
            }
            p += 2;
            *(_WORD *)v30 = v32;
            v30 += 2;
          }
          while ( (unsigned int)p < 0x3FF );
          v33 = v30 - utf8_buf;
          if ( !WriteFile(
                  hFile: *(HANDLE *)((char *)&(*v6)->osfhnd + v7),
                  lpBuffer: utf8_buf,
                  nNumberOfBytesToWrite: v30 - utf8_buf,
                  lpNumberOfBytesWritten: (LPDWORD)&written,
                  lpOverlapped: nullptr) )
            break;
          charcount += written;
          if ( written < v33 || (char *)pu - s >= cnt )
            goto LABEL_86;
          v6 = v43;
        }
      }
      else
      {
        while ( 1 )
        {
          p = nullptr;
          v34 = (char *)pu - s;
          v35 = utf16_buf;
          do
          {
            if ( v34 >= cnt )
              break;
            v36 = *pu++;
            v34 += 2;
            if ( v36 == 10 )
            {
              *v35++ = 13;
              p += 2;
            }
            p += 2;
            *v35++ = v36;
          }
          while ( (unsigned int)p < 0x152 );
          v37 = 0;
          v38 = WideCharToMultiByte(
                  CodePage: 0xFDE9u,
                  dwFlags: 0,
                  lpWideCharStr: utf16_buf,
                  cchWideChar: v35 - utf16_buf,
                  lpMultiByteStr: &utf8_buf[340],
                  cbMultiByte: 683,
                  lpDefaultChar: nullptr,
                  lpUsedDefaultChar: nullptr);
          if ( v38 == 0 )
            break;
          while ( WriteFile(
                    hFile: *(HANDLE *)((char *)&(*v43)->osfhnd + v7),
                    lpBuffer: &utf8_buf[v37 + 340],
                    nNumberOfBytesToWrite: v38 - v37,
                    lpNumberOfBytesWritten: (LPDWORD)&written,
                    lpOverlapped: nullptr) )
          {
            v37 += written;
            if ( v38 <= v37 )
              goto LABEL_80;
          }
          tmpchar = GetLastError();
LABEL_80:
          if ( v38 <= v37 )
          {
            charcount = (char *)pu - s;
            if ( (char *)pu - s < cnt )
              continue;
          }
          goto LABEL_86;
        }
      }
    }
    else
    {
      p = s;
      while ( 1 )
      {
        pu = nullptr;
        v24 = p - s;
        v25 = utf8_buf;
        do
        {
          if ( v24 >= cnt )
            break;
          v26 = p++;
          v27 = *v26;
          ++v24;
          if ( v27 == 10 )
          {
            ++lfcount;
            *v25++ = 13;
            pu = (unsigned __int16 *)((char *)pu + 1);
          }
          *v25++ = v27;
          pu = (unsigned __int16 *)((char *)pu + 1);
        }
        while ( (unsigned int)pu < 0x400 );
        v28 = v25 - utf8_buf;
        if ( !WriteFile(
                hFile: *(HANDLE *)((char *)&(*v6)->osfhnd + v7),
                lpBuffer: utf8_buf,
                nNumberOfBytesToWrite: v25 - utf8_buf,
                lpNumberOfBytesWritten: (LPDWORD)&written,
                lpOverlapped: nullptr) )
          break;
        charcount += written;
        if ( written < v28 || p - s >= cnt )
          goto LABEL_86;
        v6 = v43;
      }
    }
  }
LABEL_85:
  tmpchar = GetLastError();
LABEL_86:
  if ( charcount == 0 )
  {
    if ( tmpchar != 0 )
    {
      if ( tmpchar == 5 )
      {
        *_errno() = 9;
        *__doserrno() = 5;
      }
      else
      {
        _dosmaperr(oserrno: tmpchar);
      }
    }
    else
    {
      if ( (*(&(*v43)->osfile + v7) & 0x40) != 0 && *s == 26 )
        return 0;
      *_errno() = 28;
      *__doserrno() = 0;
    }
    return -1;
  }
  return charcount - lfcount;
}

//------------------------------------------------------------------------------
// Address: 0x10016279
// Name: __write
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _write@<eax>(ioinfo **a1@<ebx>, unsigned int a2@<esi>, int fh, char *buf, DWORD cnt)
{
  int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle || (a1 = &__pioinfo[fh >> 5], a2 = (fh & 0x1F) << 6, (*(&(*a1)->osfile + a2) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter((unsigned int)a1, a2: 0, a3: a2);
    return -1;
  }
  __lock_fhandle(fh);
  if ( (*(&(*a1)->osfile + a2) & 1) != 0 )
  {
    r = _write_nolock((char)a1, a2: 0, fh, buf, cnt);
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x10016355
// Name: __getbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _getbuf(_iobuf *str)
{
  char *v1; // eax
  char *base; // eax

  ++_cflush;
  v1 = (char *)operator new(nSize: 0x1000u);
  str->_base = v1;
  if ( v1 != nullptr )
  {
    str->_flag |= 8u;
    str->_bufsiz = 4096;
  }
  else
  {
    str->_flag |= 4u;
    str->_base = (char *)&str->_charbuf;
    str->_bufsiz = 2;
  }
  base = str->_base;
  str->_cnt = 0;
  str->_ptr = base;
}

//------------------------------------------------------------------------------
// Address: 0x10016399
// Name: __isatty
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _isatty@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, int fh)
{
  if ( fh == -2 )
  {
    *_errno() = 9;
    return 0;
  }
  else if ( fh >= 0 && fh < _nhandle )
  {
    return __pioinfo[fh >> 5][fh & 0x1F].osfile & 0x40;
  }
  else
  {
    *_errno() = 9;
    _invalid_parameter(a1, a2, a3: 0);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100163F7
// Name: ___iob_func
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl __iob_func()
{
  return _iob;
}

//------------------------------------------------------------------------------
// Address: 0x100163FD
// Name: ___initstdio
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __initstdio()
{
  unsigned int v0; // eax
  void **v1; // eax
  int v3; // edx
  _iobuf *v4; // ecx
  int v5; // edx
  _DWORD *v6; // ecx
  int osfhnd; // eax

  v0 = _nstream;
  if ( _nstream == 0 )
  {
    v0 = 512;
LABEL_5:
    _nstream = v0;
    goto LABEL_6;
  }
  if ( (int)_nstream < 20 )
  {
    v0 = 20;
    goto LABEL_5;
  }
LABEL_6:
  v1 = (void **)calloc(count: v0, size: 4u);
  __piob = v1;
  if ( v1 == nullptr )
  {
    _nstream = 20;
    v1 = (void **)calloc(count: 0x14u, size: 4u);
    __piob = v1;
    if ( v1 == nullptr )
      return 26;
  }
  v3 = 0;
  v4 = _iob;
  while ( 1 )
  {
    v1[v3++] = v4++;
    if ( (int)v4 >= (int)&_pctype )
      break;
    v1 = __piob;
  }
  v5 = 0;
  v6 = &unk_10038AE0;
  do
  {
    osfhnd = __pioinfo[v5 >> 5][v5 & 0x1F].osfhnd;
    if ( osfhnd == -1 || osfhnd == -2 || osfhnd == 0 )
      *v6 = -2;
    v6 += 8;
    ++v5;
  }
  while ( (int)v6 < (int)dword_10038B40 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100164AE
// Name: ___endstdio
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __endstdio()
{
  _flushall();
  if ( _exitflag != 0 )
    _fcloseall();
  free(pMem: __piob);
}

//------------------------------------------------------------------------------
// Address: 0x100164CE
// Name: __lock_file
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock_file(_iobuf *pf)
{
  if ( pf < _iob || pf > &stru_10038D30 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&pf[1]);
  }
  else
  {
    _lock(locknum: pf - _iob + 16);
    pf->_flag |= 0x8000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001650A
// Name: __lock_file2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock_file2(int i, char *s)
{
  if ( i >= 20 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(s + 32));
  }
  else
  {
    _lock(locknum: i + 16);
    *((_DWORD *)s + 3) |= 0x8000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016538
// Name: __unlock_file
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_file(_iobuf *pf)
{
  if ( pf < _iob || pf > &stru_10038D30 )
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&pf[1]);
  }
  else
  {
    pf->_flag &= ~0x8000u;
    _unlock(locknum: pf - _iob + 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001656E
// Name: __unlock_file2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_file2(int i, char *s)
{
  if ( i >= 20 )
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(s + 32));
  }
  else
  {
    *((_DWORD *)s + 3) &= ~0x8000u;
    _unlock(locknum: i + 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016598
// Name: __fileno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _fileno@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, _iobuf *stream)
{
  if ( stream != nullptr )
    return stream->_file;
  *_errno() = 22;
  _invalid_parameter(a1, a2, a3: 0);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100165C5
// Name: __get_printf_count_output
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _get_printf_count_output()
{
  return _enable_percent_n == (__security_cookie | 1);
}

//------------------------------------------------------------------------------
// Address: 0x100165DB
// Name: __wctomb_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wctomb_s_l(
        int *pRetValue,
        char *dst,
        unsigned int sizeInBytes,
        wchar_t wchar,
        localeinfo_struct *plocinfo)
{
  char *v5; // esi
  unsigned int v6; // edi
  int result; // eax
  int v8; // esi
  int v9; // eax
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  v5 = dst;
  v6 = sizeInBytes;
  if ( dst == nullptr && sizeInBytes != 0 )
  {
    if ( pRetValue != nullptr )
      *pRetValue = 0;
    return 0;
  }
  if ( pRetValue != nullptr )
    *pRetValue = -1;
  if ( v6 > 0x7FFFFFFF )
  {
    v8 = 22;
    *_errno() = 22;
    _invalid_parameter(a1: 0, a2: v6, a3: 0x16u);
    return v8;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->lc_handle[2] == 0 )
  {
    if ( wchar > 0xFFu )
    {
      if ( v5 != nullptr && v6 != 0 )
        memset(dst: (int)v5, value: nullptr, count: v6);
      goto LABEL_16;
    }
    if ( v5 != nullptr )
    {
      if ( v6 == 0 )
      {
LABEL_21:
        v8 = 34;
        *_errno() = 34;
        _invalid_parameter(a1: 0, a2: v6, a3: 0x22u);
        if ( _loc_update.updated )
          _loc_update.ptd->_ownlocale &= ~2u;
        return v8;
      }
      *v5 = wchar;
    }
    if ( pRetValue != nullptr )
      *pRetValue = 1;
LABEL_26:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  dst = nullptr;
  v9 = WideCharToMultiByte(
         CodePage: _loc_update.localeinfo.locinfo->lc_codepage,
         dwFlags: 0,
         lpWideCharStr: &wchar,
         cchWideChar: 1,
         lpMultiByteStr: v5,
         cbMultiByte: v6,
         lpDefaultChar: nullptr,
         lpUsedDefaultChar: (LPBOOL)&dst);
  if ( v9 != 0 )
  {
    if ( dst == nullptr )
    {
      if ( pRetValue != nullptr )
        *pRetValue = v9;
      goto LABEL_26;
    }
  }
  else if ( GetLastError() == 122 )
  {
    if ( v5 != nullptr && v6 != 0 )
      memset(dst: (int)v5, value: nullptr, count: v6);
    goto LABEL_21;
  }
LABEL_16:
  *_errno() = 42;
  result = *_errno();
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001673A
// Name: _wctomb_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wctomb_s(int *pRetValue, char *dst, unsigned int sizeInBytes, wchar_t wchar)
{
  return _wctomb_s_l(pRetValue, dst, sizeInBytes, wchar, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10016755
// Name: __crt_debugger_hook
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _crt_debugger_hook()
{
  _debugger_hook_dummy = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10016760
// Name: _strrchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strrchr(unsigned __int8 *string, unsigned __int8 chr)
{
  unsigned int v2; // ecx
  unsigned __int8 *v3; // edi
  bool v4; // zf

  v2 = strlen((const char *)string) + 1;
  v3 = &string[v2 - 1];
  do
  {
    if ( v2 == 0 )
      break;
    v4 = *v3-- == chr;
    --v2;
  }
  while ( !v4 );
}

//------------------------------------------------------------------------------
// Address: 0x1001678D
// Name: __isdigit_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isdigit_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 4;
  else
    result = _isctype_l(c, mask: 4, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100167DC
// Name: _isdigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isdigit(int c)
{
  if ( __locale_changed != 0 )
    return _isdigit_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 4;
}

//------------------------------------------------------------------------------
// Address: 0x10016805
// Name: __isxdigit_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isxdigit_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 0x80;
  else
    result = _isctype_l(c, mask: 128, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016859
// Name: _isxdigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isxdigit(int c)
{
  if ( __locale_changed != 0 )
    return _isxdigit_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 0x80;
}

//------------------------------------------------------------------------------
// Address: 0x10016884
// Name: __isspace_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isspace_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 8;
  else
    result = _isctype_l(c, mask: 8, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100168D3
// Name: _isspace
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isspace(int c)
{
  if ( __locale_changed != 0 )
    return _isspace_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 8;
}

//------------------------------------------------------------------------------
// Address: 0x100168FC
// Name: __atodbl_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _atodbl_l(_CRT_DOUBLE *d, char *str, localeinfo_struct *plocinfo)
{
  INTRNCVT_STATUS v3; // eax
  const char *EndPtr; // [esp+Ch] [ebp-28h] BYREF
  _LocaleUpdate _loc_update; // [esp+10h] [ebp-24h] BYREF
  unsigned int retval1; // [esp+20h] [ebp-14h]
  _LDBL12 ld12; // [esp+24h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  retval1 = __strgtold12_l(
              pld12: &ld12,
              p_end_ptr: &EndPtr,
              str,
              mult12: 0,
              scale: 0,
              decpt: 0,
              implicit_E: 0,
              _Locale: &_loc_update.localeinfo);
  v3 = _ld12tod(pld12: &ld12, d);
  if ( (retval1 & 3) != 0 )
  {
    if ( (retval1 & 1) != 0 )
      goto LABEL_8;
    if ( (retval1 & 2) != 0 )
      goto LABEL_3;
  }
  else
  {
    if ( v3 == INTRNCVT_OVERFLOW )
    {
LABEL_3:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 3;
    }
    if ( v3 == INTRNCVT_UNDERFLOW )
    {
LABEL_8:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 4;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100169A2
// Name: __atoflt_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _atoflt_l(_CRT_FLOAT *d, char *str, localeinfo_struct *plocinfo)
{
  INTRNCVT_STATUS v3; // eax
  const char *EndPtr; // [esp+Ch] [ebp-28h] BYREF
  _LocaleUpdate _loc_update; // [esp+10h] [ebp-24h] BYREF
  unsigned int retval1; // [esp+20h] [ebp-14h]
  _LDBL12 ld12; // [esp+24h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  retval1 = __strgtold12_l(
              pld12: &ld12,
              p_end_ptr: &EndPtr,
              str,
              mult12: 0,
              scale: 0,
              decpt: 0,
              implicit_E: 0,
              _Locale: &_loc_update.localeinfo);
  v3 = _ld12tof(pld12: &ld12, f: d);
  if ( (retval1 & 3) != 0 )
  {
    if ( (retval1 & 1) != 0 )
      goto LABEL_8;
    if ( (retval1 & 2) != 0 )
      goto LABEL_3;
  }
  else
  {
    if ( v3 == INTRNCVT_OVERFLOW )
    {
LABEL_3:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 3;
    }
    if ( v3 == INTRNCVT_UNDERFLOW )
    {
LABEL_8:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return 4;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10016A48
// Name: _strcpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall strcpy_s@<eax>(unsigned int a1@<edi>, char *_Dst, unsigned int _SizeInBytes, const char *_Src)
{
  unsigned int v4; // esi
  const char *v6; // esi
  char *v7; // edx
  char v8; // al

  if ( _Dst == nullptr )
    goto LABEL_3;
  a1 = _SizeInBytes;
  if ( _SizeInBytes == 0 )
    goto LABEL_3;
  v6 = _Src;
  if ( _Src == nullptr )
  {
    *_Dst = 0;
LABEL_3:
    v4 = 22;
    *_errno() = 22;
LABEL_4:
    _invalid_parameter(a1: 0, a2: a1, a3: v4);
    return v4;
  }
  v7 = _Dst;
  do
  {
    v8 = *v6;
    *v7++ = *v6++;
    if ( v8 == 0 )
      break;
    --a1;
  }
  while ( a1 != 0 );
  if ( a1 == 0 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v4 = 34;
    goto LABEL_4;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10016AAD
// Name: __fptostr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _fptostr(char *buf, unsigned int sizeInBytes, int digits, _strflt *pflt)
{
  _strflt *v4; // ecx
  char *mantissa; // edi
  unsigned int v6; // esi
  int v8; // edx
  int v9; // eax
  char *v10; // eax
  char v11; // cl
  int v12; // eax

  v4 = pflt;
  mantissa = pflt->mantissa;
  if ( buf == nullptr || sizeInBytes == 0 )
  {
    v6 = 22;
    *_errno() = 22;
LABEL_3:
    _invalid_parameter(a1: 0, a2: (unsigned int)mantissa, a3: v6);
    return v6;
  }
  v8 = digits;
  *buf = 0;
  if ( digits <= 0 )
    v9 = 0;
  else
    v9 = digits;
  if ( sizeInBytes <= v9 + 1 )
  {
    *_errno() = 34;
    v6 = 34;
    goto LABEL_3;
  }
  *buf = 48;
  v10 = buf + 1;
  if ( digits > 0 )
  {
    do
    {
      v11 = *mantissa;
      if ( *mantissa != 0 )
        ++mantissa;
      else
        v11 = 48;
      *v10++ = v11;
      --v8;
    }
    while ( v8 > 0 );
    v4 = pflt;
  }
  *v10 = 0;
  if ( v8 >= 0 && *mantissa >= 53 )
  {
    while ( *--v10 == 57 )
      *v10 = 48;
    ++*v10;
  }
  if ( *buf == 49 )
  {
    ++v4->decpt;
  }
  else
  {
    strlen(buf: buf + 1);
    memmove(dst: (unsigned __int8 *)buf, src: (unsigned __int8 *)buf + 1, count: v12 + 1);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10016B6A
// Name: ___dtold
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __dtold(_LDOUBLE *pld, long double *px)
{
  int v3; // ecx
  int v4; // eax
  unsigned int v5; // edx
  int v6; // eax
  __int16 v7; // cx
  __int16 v8; // di
  _LDOUBLE *v9; // eax
  __int16 v10; // cx
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  unsigned int msb; // [esp+Ch] [ebp-4h]
  __int16 sign; // [esp+1Ch] [ebp+Ch]

  v3 = (*((unsigned __int16 *)px + 3) >> 4) & 0x7FF;
  sign = *((_WORD *)px + 3) & 0x8000;
  v4 = *((_DWORD *)px + 1);
  v5 = *(_DWORD *)px;
  v6 = v4 & 0xFFFFF;
  msb = 0x80000000;
  if ( (_WORD)v3 == 0 )
  {
    if ( v6 == 0 && v5 == 0 )
    {
      v9 = pld;
      v10 = sign;
      *(_DWORD *)&pld->ld[4] = 0;
      *(_DWORD *)pld->ld = 0;
      goto LABEL_13;
    }
    v7 = 15361;
    msb = 0;
    goto LABEL_9;
  }
  if ( (unsigned __int16)v3 != 2047 )
  {
    v7 = v3 + 15360;
LABEL_9:
    v8 = v7;
    goto LABEL_10;
  }
  v8 = 0x7FFF;
LABEL_10:
  v11 = msb | (v6 << 11) | (v5 >> 21);
  v9 = pld;
  *(_DWORD *)&pld->ld[4] = v11;
  *(_DWORD *)pld->ld = v5 << 11;
  if ( (v11 & 0x80000000) == 0 )
  {
    do
    {
      v12 = *(__int64 *)pld->ld >> 31;
      v13 = 2 * *(_DWORD *)pld->ld;
      --v8;
      *(_DWORD *)&pld->ld[4] = v12;
      *(_DWORD *)pld->ld = v13;
    }
    while ( (v12 & 0x80000000) == 0 );
  }
  v10 = v8 | sign;
LABEL_13:
  *(_WORD *)&v9->ld[8] = v10;
}

//------------------------------------------------------------------------------
// Address: 0x10016C25
// Name: __fltout2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_strflt *__cdecl _fltout2(_CRT_DOUBLE x, _strflt *flt, char *resultstr, unsigned int resultsize)
{
  _strflt *v4; // ebx
  int v5; // eax
  char *v6; // esi
  unsigned int v7; // edx
  unsigned int v8; // ecx
  _BYTE v10[26]; // [esp-Eh] [ebp-4Ah] BYREF
  char *_Dst; // [esp+Ch] [ebp-30h]
  _FloatOutStruct autofos; // [esp+10h] [ebp-2Ch] BYREF
  _LDOUBLE ld; // [esp+2Ch] [ebp-10h] BYREF

  v4 = flt;
  _Dst = resultstr;
  __dtold(pld: &ld, px: &x.x);
  v5 = _I10_OUTPUT(ld, ndigits: 17, output_flags: 0, fos: &autofos);
  v6 = _Dst;
  v4->flag = v5;
  v4->sign = autofos.sign;
  v4->decpt = autofos.exp;
  if ( strcpy_s(a1: (unsigned int)v10, _Dst: v6, _SizeInBytes: resultsize, _Src: autofos.man) != 0 )
  {
    memset(v10, 0, 14);
    _invoke_watson(a1: 0, a2: v7, a3: v8, a4: (unsigned int)v4, a5: (unsigned int)v10, a6: (unsigned int)v6);
  }
  v4->mantissa = v6;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10016CC0
// Name: __alldvrm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _alldvrm(unsigned __int64 a1, __int64 a2)
{
  int v2; // edi
  int v3; // eax
  unsigned __int64 v4; // rtt
  int v5; // esi
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rax
  int result; // eax

  v2 = 0;
  if ( (a1 & 0x8000000000000000uLL) != 0LL )
  {
    v2 = 1;
    HIDWORD(a1) = -HIDWORD(a1) - ((_DWORD)a1 != 0);
    LODWORD(a1) = -(int)a1;
  }
  v3 = HIDWORD(a2);
  if ( a2 < 0 )
  {
    ++v2;
    v3 = -HIDWORD(a2) - ((_DWORD)a2 != 0);
    HIDWORD(a2) = v3;
    LODWORD(a2) = -(int)a2;
  }
  if ( v3 != 0 )
  {
    v6 = __PAIR64__(v3, a2);
    v7 = a1;
    do
    {
      v6 >>= 1;
      v7 >>= 1;
    }
    while ( HIDWORD(v6) != 0 );
    v5 = v7 / (unsigned int)v6;
    v8 = (unsigned int)v5 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v5, HIDWORD(v8))
      || (HIDWORD(v8) = (a2 * (unsigned __int64)(unsigned int)v5) >> 32, v8 > a1) )
    {
      --v5;
    }
  }
  else
  {
    LODWORD(v4) = a1;
    HIDWORD(v4) = HIDWORD(a1) % (unsigned int)a2;
    v5 = v4 / (unsigned int)a2;
  }
  result = v5;
  if ( v2 == 1 )
    return -v5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016DA0
// Name: __aullshr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __usercall _aullshr@<edx:eax>(unsigned __int64 a1@<edx:eax>, unsigned __int8 a2@<cl>)
{
  if ( a2 >= 0x40u )
    return 0;
  else
    return a1 >> a2;
}

//------------------------------------------------------------------------------
// Address: 0x10016DBF
// Name: __fptrap
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _fptrap()
{
  _amsg_exit(rterrnum: 2);
}

//------------------------------------------------------------------------------
// Address: 0x10016DC8
// Name: __controlfp_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _controlfp_s@<eax>(
        unsigned int a1@<ebx>,
        unsigned int *_CurrentState,
        unsigned int newctrl,
        unsigned int mask)
{
  unsigned int v5; // [esp-4h] [ebp-8h]

  if ( (mask & 0xFFF7FFFF & newctrl & 0xFCF0FCE0) != 0 )
  {
    if ( _CurrentState != nullptr )
      *_CurrentState = _control87(newctrl: 0, mask: 0);
    *_errno() = 22;
    _invalid_parameter(a1, a2: 0x16u, a3: 0);
    return 22;
  }
  else
  {
    v5 = mask & 0xFFF7FFFF;
    if ( _CurrentState != nullptr )
      *_CurrentState = _control87(newctrl, mask: v5);
    else
      _control87(newctrl, mask: v5);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10016E32
// Name: __initp_misc_winsig
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_winsig(void (__cdecl *enull)(int))
{
  ctrlc_action = enull;
  ctrlbreak_action = enull;
  abort_action = enull;
  term_action = enull;
}

//------------------------------------------------------------------------------
// Address: 0x10016E4B
// Name: siglookup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_XCPT_ACTION *__usercall siglookup@<eax>(int signum@<edx>, _XCPT_ACTION *pxcptacttab)
{
  _XCPT_ACTION *result; // eax

  result = pxcptacttab;
  do
  {
    if ( result->SigNum == signum )
      break;
    ++result;
  }
  while ( result < &pxcptacttab[_XcptActTabCount] );
  if ( result >= &pxcptacttab[_XcptActTabCount] || result->SigNum != signum )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10016E7F
// Name: ___get_sigabrt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void (__cdecl *__cdecl __get_sigabrt())(int)
{
  return (void (__cdecl *)(int))_decode_pointer(codedptr: abort_action);
}

//------------------------------------------------------------------------------
// Address: 0x10016E8C
// Name: _raise
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall raise@<eax>(unsigned int a1@<esi>, int signum)
{
  _tiddata *v2; // edi
  _tiddata *v3; // eax
  int result; // eax
  void (__cdecl **p_XcptAction)(int); // esi
  void (__cdecl *v6)(int); // eax
  void (__cdecl *v7)(int); // eax
  int oldfpecode; // [esp+10h] [ebp-30h]
  _EXCEPTION_POINTERS *oldpxcptinfoptrs; // [esp+14h] [ebp-2Ch]
  int indx; // [esp+1Ch] [ebp-24h]
  void (__cdecl *sigact)(int); // [esp+20h] [ebp-20h]
  int siglock; // [esp+24h] [ebp-1Ch]

  v2 = nullptr;
  siglock = 0;
  if ( signum > 11 )
  {
    if ( signum == 15 )
    {
      p_XcptAction = &term_action;
      v6 = term_action;
      goto LABEL_18;
    }
    if ( signum == 21 )
    {
      p_XcptAction = &ctrlbreak_action;
      v6 = ctrlbreak_action;
      goto LABEL_18;
    }
    if ( signum != 22 )
      goto LABEL_14;
    goto LABEL_15;
  }
  if ( signum != 11 )
  {
    if ( signum == 2 )
    {
      p_XcptAction = &ctrlc_action;
      v6 = ctrlc_action;
LABEL_18:
      siglock = 1;
      v7 = (void (__cdecl *)(int))_decode_pointer(codedptr: v6);
      goto LABEL_19;
    }
    if ( signum != 4 )
    {
      if ( signum != 6 )
      {
        if ( signum == 8 )
          goto LABEL_7;
LABEL_14:
        *_errno() = 22;
        _invalid_parameter(a1: signum, a2: 0, a3: a1);
        return -1;
      }
LABEL_15:
      p_XcptAction = &abort_action;
      v6 = abort_action;
      goto LABEL_18;
    }
  }
LABEL_7:
  v3 = _getptd_noexit();
  v2 = v3;
  if ( v3 == nullptr )
    return -1;
  p_XcptAction = &siglookup(signum, pxcptacttab: (_XCPT_ACTION *)v3->_pxcptacttab)->XcptAction;
  v7 = *p_XcptAction;
LABEL_19:
  sigact = v7;
  result = 0;
  if ( sigact == (void (__cdecl *)(int))1 )
    return result;
  if ( sigact == nullptr )
    _exit(code: 3);
  if ( siglock != 0 )
    _lock(locknum: 0);
  if ( signum == 8 || signum == 11 || signum == 4 )
  {
    oldpxcptinfoptrs = (_EXCEPTION_POINTERS *)v2->_tpxcptinfoptrs;
    v2->_tpxcptinfoptrs = nullptr;
    if ( signum != 8 )
      goto LABEL_33;
    oldfpecode = v2->_tfpecode;
    v2->_tfpecode = 140;
  }
  if ( signum == 8 )
  {
    for ( indx = _First_FPE_Indx; indx < _First_FPE_Indx + _Num_FPE; ++indx )
      *((_DWORD *)v2->_pxcptacttab + 3 * indx + 2) = 0;
    goto $LN37;
  }
LABEL_33:
  *p_XcptAction = (void (__cdecl *)(int))_encoded_null();
$LN37:
  if ( siglock != 0 )
    _unlock(locknum: 0);
  if ( signum == 8 )
    ((void (__cdecl *)(int, int))sigact)(a1: 8, a2: v2->_tfpecode);
  else
    sigact(a1: signum);
  if ( signum == 8 || signum == 11 || signum == 4 )
  {
    v2->_tpxcptinfoptrs = oldpxcptinfoptrs;
    if ( signum == 8 )
      v2->_tfpecode = oldfpecode;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001703C
// Name: ___crtMessageBoxA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtMessageBoxA(const char *lpText, const char *lpCaption, unsigned int uType)
{
  HMODULE LibraryA; // eax
  HMODULE v4; // edi
  int (__stdcall *MessageBoxA)(HWND, LPCSTR, LPCSTR, UINT); // eax
  HWND (__stdcall *GetActiveWindow)(); // eax
  HWND (__stdcall *GetLastActivePopup)(HWND); // eax
  unsigned int v8; // eax
  unsigned int v9; // edx
  BOOL (__stdcall *GetUserObjectInformationA)(HANDLE, int, PVOID, DWORD, LPDWORD); // eax
  HWINSTA (__stdcall *GetProcessWindowStation)(); // eax
  int (*v12)(void); // esi
  int (__stdcall *v13)(int, int, tagUSEROBJECTFLAGS *, int, unsigned int *); // eax
  int (__stdcall *v14)(int, int, tagUSEROBJECTFLAGS *, int, unsigned int *); // edi
  int v15; // eax
  unsigned int v16; // eax
  unsigned int v17; // edx
  int (*v18)(void); // eax
  int (__stdcall *v19)(HWND__ *); // eax
  int (__stdcall *v20)(HWND__ *, const char *, const char *, unsigned int); // eax
  LPCSTR lpProcName; // [esp+0h] [ebp-30h]
  LPCSTR lpProcNamea; // [esp+0h] [ebp-30h]
  tagUSEROBJECTFLAGS uof; // [esp+10h] [ebp-20h] BYREF
  unsigned int nDummy; // [esp+1Ch] [ebp-14h] BYREF
  unsigned int winmajor; // [esp+20h] [ebp-10h] BYREF
  unsigned int osplatform; // [esp+24h] [ebp-Ch] BYREF
  void *enull; // [esp+28h] [ebp-8h]
  HWND__ *hWndParent; // [esp+2Ch] [ebp-4h]

  enull = _encoded_null();
  hWndParent = nullptr;
  osplatform = 0;
  winmajor = 0;
  if ( pfnMessageBox == nullptr )
  {
    LibraryA = LoadLibraryA(lpLibFileName: "USER32.DLL");
    v4 = LibraryA;
    if ( LibraryA == nullptr )
      return 0;
    MessageBoxA = (int (__stdcall *)(HWND, LPCSTR, LPCSTR, UINT))GetProcAddress(
                                                                   hModule: LibraryA,
                                                                   lpProcName: "MessageBoxA");
    if ( MessageBoxA == nullptr )
      return 0;
    pfnMessageBox = (int (__stdcall *)(HWND__ *, const char *, const char *, unsigned int))_encode_pointer(ptr: MessageBoxA);
    GetActiveWindow = (HWND (__stdcall *)())GetProcAddress(hModule: v4, lpProcName: "GetActiveWindow");
    pfnGetActiveWindow = (HWND__ *(__stdcall *)())_encode_pointer(ptr: GetActiveWindow);
    GetLastActivePopup = (HWND (__stdcall *)(HWND))GetProcAddress(hModule: v4, lpProcName: "GetLastActivePopup");
    pfnGetLastActivePopup = (HWND__ *(__stdcall *)(HWND__ *))_encode_pointer(ptr: GetLastActivePopup);
    v8 = _get_osplatform(a1: 0, a2: (unsigned int)v4, pValue: &osplatform);
    if ( v8 != 0 )
      _invoke_watson(
        a1: v8,
        a2: v9,
        a3: (unsigned int)lpProcName,
        a4: 0,
        a5: (unsigned int)v4,
        a6: (unsigned int)GetProcAddress);
    if ( osplatform == 2 )
    {
      GetUserObjectInformationA = (BOOL (__stdcall *)(HANDLE, int, PVOID, DWORD, LPDWORD))GetProcAddress(
                                                                                            hModule: v4,
                                                                                            lpProcName: "GetUserObjectInformationA");
      pfnGetUserObjectInformation = (int (__stdcall *)(void *, int, void *, unsigned int, unsigned int *))_encode_pointer(ptr: GetUserObjectInformationA);
      if ( pfnGetUserObjectInformation != nullptr )
      {
        GetProcessWindowStation = (HWINSTA (__stdcall *)())GetProcAddress(
                                                             hModule: v4,
                                                             lpProcName: "GetProcessWindowStation");
        pfnGetProcessWindowStation = (HWINSTA__ *(__stdcall *)())_encode_pointer(ptr: GetProcessWindowStation);
      }
    }
  }
  if ( pfnGetProcessWindowStation == enull
    || pfnGetUserObjectInformation == enull
    || (v12 = (int (*)(void))_decode_pointer(codedptr: pfnGetProcessWindowStation),
        v13 = (int (__stdcall *)(int, int, tagUSEROBJECTFLAGS *, int, unsigned int *))_decode_pointer(codedptr: pfnGetUserObjectInformation),
        v14 = v13,
        v12 == nullptr)
    || v13 == nullptr
    || (v15 = v12()) != 0 && v14(a1: v15, a2: 1, a3: &uof, a4: 12, a5: &nDummy) != 0 && (uof.dwFlags & 1) != 0 )
  {
    if ( pfnGetActiveWindow != enull )
    {
      v18 = (int (*)(void))_decode_pointer(codedptr: pfnGetActiveWindow);
      if ( v18 != nullptr )
      {
        hWndParent = (HWND__ *)v18();
        if ( hWndParent != nullptr && pfnGetLastActivePopup != enull )
        {
          v19 = (int (__stdcall *)(HWND__ *))_decode_pointer(codedptr: pfnGetLastActivePopup);
          if ( v19 != nullptr )
            hWndParent = (HWND__ *)v19(a1: hWndParent);
        }
      }
    }
  }
  else
  {
    v16 = _get_winmajor(a1: 0, a2: (unsigned int)v14, pValue: &winmajor);
    if ( v16 != 0 )
      _invoke_watson(
        a1: v16,
        a2: v17,
        a3: (unsigned int)lpProcNamea,
        a4: 0,
        a5: (unsigned int)v14,
        a6: (unsigned int)v12);
    if ( winmajor < 4 )
      uType |= 0x40000u;
    else
      uType |= 0x200000u;
  }
  v20 = (int (__stdcall *)(HWND__ *, const char *, const char *, unsigned int))_decode_pointer(codedptr: pfnMessageBox);
  if ( v20 != nullptr )
    return v20(a1: hWndParent, a2: lpText, a3: lpCaption, a4: uType);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100171F9
// Name: _strcat_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall strcat_s@<eax>(unsigned int a1@<edi>, char *_Dst, unsigned int _SizeInBytes, const char *_Src)
{
  unsigned int v4; // esi
  const char *v6; // esi
  char *v7; // edx
  char v8; // cl

  if ( _Dst == nullptr )
    goto LABEL_3;
  a1 = _SizeInBytes;
  if ( _SizeInBytes == 0 )
    goto LABEL_3;
  v6 = _Src;
  if ( _Src != nullptr )
  {
    v7 = _Dst;
    do
    {
      if ( *v7 == 0 )
        break;
      ++v7;
      --a1;
    }
    while ( a1 != 0 );
    if ( a1 != 0 )
    {
      do
      {
        v8 = *v6;
        *v7++ = *v6++;
        if ( v8 == 0 )
          break;
        --a1;
      }
      while ( a1 != 0 );
      if ( a1 == 0 )
      {
        *_Dst = 0;
        *_errno() = 34;
        v4 = 34;
        goto LABEL_4;
      }
      return 0;
    }
  }
  *_Dst = 0;
LABEL_3:
  v4 = 22;
  *_errno() = 22;
LABEL_4:
  _invalid_parameter(a1: 0, a2: a1, a3: v4);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1001726A
// Name: _strncpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall strncpy_s@<eax>(
        unsigned int a1@<edi>,
        char *_Dst,
        unsigned int _SizeInBytes,
        const char *_Src,
        unsigned int _Count)
{
  unsigned int v6; // esi
  const char *v7; // edx
  char *v8; // eax
  char v9; // cl
  char v10; // cl

  if ( _Count != 0 )
  {
    if ( _Dst == nullptr )
    {
LABEL_7:
      v6 = 22;
      *_errno() = 22;
LABEL_8:
      _invalid_parameter(a1: 0, a2: a1, a3: v6);
      return v6;
    }
  }
  else if ( _Dst == nullptr )
  {
    if ( _SizeInBytes == 0 )
      return 0;
    goto LABEL_7;
  }
  a1 = _SizeInBytes;
  if ( _SizeInBytes == 0 )
    goto LABEL_7;
  if ( _Count == 0 )
  {
    *_Dst = 0;
    return 0;
  }
  v7 = _Src;
  if ( _Src == nullptr )
  {
    *_Dst = 0;
    goto LABEL_7;
  }
  v8 = _Dst;
  if ( _Count == -1 )
  {
    do
    {
      v9 = *v7;
      *v8++ = *v7++;
      if ( v9 == 0 )
        break;
      --a1;
    }
    while ( a1 != 0 );
  }
  else
  {
    do
    {
      v10 = *v7;
      *v8++ = *v7++;
      if ( v10 == 0 )
        break;
      if ( --a1 == 0 )
        break;
      --_Count;
    }
    while ( _Count != 0 );
    if ( _Count == 0 )
      *v8 = 0;
  }
  if ( a1 != 0 )
    return 0;
  if ( _Count != -1 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v6 = 34;
    goto LABEL_8;
  }
  _Dst[_SizeInBytes - 1] = 0;
  return 80;
}

//------------------------------------------------------------------------------
// Address: 0x1001731D
// Name: __set_error_mode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _set_error_mode@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, int em)
{
  int result; // eax

  if ( em >= 0 )
  {
    if ( em <= 2 )
    {
      result = __error_mode;
      __error_mode = em;
      return result;
    }
    if ( em == 3 )
      return __error_mode;
  }
  *_errno() = 22;
  _invalid_parameter(a1, a2, a3: 0);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10017370
// Name: __ValidateImageBase
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _ValidateImageBase(unsigned __int8 *pImageBase)
{
  unsigned __int8 *v2; // eax

  return *(_WORD *)pImageBase == 23117
      && *(_DWORD *)(v2 = &pImageBase[*((_DWORD *)pImageBase + 15)]) == 17744
      && *((_WORD *)v2 + 12) == 267;
}

//------------------------------------------------------------------------------
// Address: 0x100173A0
// Name: __FindPESection
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_IMAGE_SECTION_HEADER *__cdecl _FindPESection(unsigned __int8 *pImageBase, unsigned int rva)
{
  unsigned __int8 *v2; // ecx
  unsigned int v3; // esi
  unsigned int v4; // edx
  _IMAGE_SECTION_HEADER *result; // eax
  unsigned int VirtualAddress; // ecx

  v2 = &pImageBase[*((_DWORD *)pImageBase + 15)];
  v3 = *((unsigned __int16 *)v2 + 3);
  v4 = 0;
  result = (_IMAGE_SECTION_HEADER *)&v2[*((unsigned __int16 *)v2 + 10) + 24];
  if ( *((_WORD *)v2 + 3) == 0 )
    return nullptr;
  while ( 1 )
  {
    VirtualAddress = result->VirtualAddress;
    if ( rva >= VirtualAddress && rva < VirtualAddress + result->Misc.PhysicalAddress )
      break;
    ++v4;
    ++result;
    if ( v4 >= v3 )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100173F0
// Name: __IsNonwritableInCurrentImage
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _IsNonwritableInCurrentImage(unsigned __int8 *pTarget)
{
  _IMAGE_SECTION_HEADER *PESection; // eax

  return _ValidateImageBase(pImageBase: (unsigned __int8 *)0x10000000)
      && (PESection = _FindPESection(
                        pImageBase: (unsigned __int8 *)0x10000000,
                        rva: (unsigned int)(pTarget - 0x10000000))) != nullptr
      && (PESection->Characteristics & 0x80000000) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100174AB
// Name: void terminate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn terminate()
{
  void (*v0)(void); // eax

  v0 = (void (*)(void))_getptd()->_terminate;
  if ( v0 != nullptr )
    v0();
  abort();
}

//------------------------------------------------------------------------------
// Address: 0x100174E4
// Name: __initp_eh_hooks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_eh_hooks()
{
  __pInconsistency = (void (__cdecl *)())_encode_pointer(ptr: terminate);
}

//------------------------------------------------------------------------------
// Address: 0x100174F5
// Name: __initp_misc_rand_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_rand_s(int (__stdcall *enull)(void *, unsigned int))
{
  g_pfnRtlGenRandom = enull;
}

//------------------------------------------------------------------------------
// Address: 0x100174FF
// Name: __initp_misc_initcrit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_initcrit(int (__stdcall *enull)(_RTL_CRITICAL_SECTION *, unsigned int))
{
  _pfnInitCritSecAndSpinCount = enull;
}

//------------------------------------------------------------------------------
// Address: 0x10017509
// Name: __crtInitCritSecNoSpinCount
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _crtInitCritSecNoSpinCount(_RTL_CRITICAL_SECTION *lpCriticalSection, unsigned int dwSpinCount)
{
  InitializeCriticalSection(lpCriticalSection);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10017519
// Name: ___crtInitCritSecAndSpinCount
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __usercall __crtInitCritSecAndSpinCount@<eax>(
        unsigned int a1@<ebx>,
        _RTL_CRITICAL_SECTION *lpCriticalSection,
        DWORD dwSpinCount)
{
  BOOL (__stdcall *InitializeCriticalSectionAndSpinCount)(LPCRITICAL_SECTION, DWORD); // esi
  unsigned int v4; // eax
  unsigned int v5; // edx
  HMODULE ModuleHandleA; // eax
  unsigned int v8; // [esp-4h] [ebp-38h]
  unsigned int osplatform; // [esp+18h] [ebp-1Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+1Ch] [ebp-18h]

  osplatform = 0;
  InitializeCriticalSectionAndSpinCount = (BOOL (__stdcall *)(LPCRITICAL_SECTION, DWORD))_decode_pointer(codedptr: _pfnInitCritSecAndSpinCount);
  if ( InitializeCriticalSectionAndSpinCount == nullptr )
  {
    v4 = _get_osplatform(a1, a2: 0, pValue: &osplatform);
    if ( v4 != 0 )
      _invoke_watson(a1: v4, a2: v5, a3: v8, a4: a1, a5: 0, a6: 0);
    if ( osplatform == 1
      || (ModuleHandleA = GetModuleHandleA(lpModuleName: "kernel32.dll")) == nullptr
      || (InitializeCriticalSectionAndSpinCount = (BOOL (__stdcall *)(LPCRITICAL_SECTION, DWORD))GetProcAddress(
                                                                                                   hModule: ModuleHandleA,
                                                                                                   lpProcName: "InitializeCriticalSec"
                                                                                                   "tionAndSpinCount")) == nullptr )
    {
      InitializeCriticalSectionAndSpinCount = _crtInitCritSecNoSpinCount;
    }
    _pfnInitCritSecAndSpinCount = (int (__stdcall *)(_RTL_CRITICAL_SECTION *, unsigned int))_encode_pointer(ptr: InitializeCriticalSectionAndSpinCount);
  }
  ms_exc.registration.TryLevel = 0;
  return InitializeCriticalSectionAndSpinCount(lpCriticalSection, dwSpinCount);
}

//------------------------------------------------------------------------------
// Address: 0x100175DE
// Name: __initp_heap_handler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_heap_handler(int (__cdecl *enull)(unsigned int))
{
  _pnhHeap = enull;
}

//------------------------------------------------------------------------------
// Address: 0x100175E8
// Name: x_ismbbtype_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl x_ismbbtype_l(localeinfo_struct *plocinfo, unsigned __int8 tst, int cmask, unsigned __int8 kmask)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( (kmask & _loc_update.localeinfo.mbcinfo->mbctype[tst + 1]) != 0
    || (cmask == 0 ? (result = 0) : (result = (unsigned __int16)(cmask & _loc_update.localeinfo.locinfo->pctype[tst])),
        result != 0) )
  {
    result = 1;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017639
// Name: __ismbblead
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ismbblead(unsigned __int8 tst)
{
  return x_ismbbtype_l(plocinfo: nullptr, tst, cmask: 0, kmask: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x1001764C
// Name: __local_unwind4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _local_unwind4(_DWORD *a1, int a2, unsigned int a3)
{
  int result; // eax
  unsigned int v4; // esi
  int v5; // esi
  int v6; // ebx
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp-8h] [ebp-28h]
  int (__cdecl *v8)(int, int, int, int); // [esp-4h] [ebp-24h]

  v8 = unwind_handler4;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  while ( 1 )
  {
    result = a2;
    v4 = *(_DWORD *)(a2 + 12);
    if ( v4 == -2 || a3 != -2 && v4 <= a3 )
      break;
    v5 = 3 * v4;
    v6 = (*a1 ^ *(_DWORD *)(a2 + 8)) + 4 * v5 + 16;
    *(_DWORD *)(a2 + 12) = *(_DWORD *)((*a1 ^ *(_DWORD *)(a2 + 8)) + 4 * v5 + 0x10);
    if ( *(_DWORD *)(v6 + 4) == 0 )
    {
      _NLG_Notify(a1: 257);
      _NLG_Call(a1: 1, a2: ExceptionList, a3: v8);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100176DC
// Name: _unwind_handler4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl unwind_handler4(int a1, int a2, int a3, _DWORD *a4)
{
  int result; // eax

  result = 1;
  if ( (*(_DWORD *)(a1 + 4) & 6) != 0 )
  {
    _local_unwind4(a1: *(_DWORD **)(a2 + 20), a2: *(_DWORD *)(a2 + 16), a3: *(_DWORD *)(a2 + 12));
    *a4 = a2;
    return 3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017722
// Name: _seh_longjmp_unwind4(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _seh_longjmp_unwind4(unsigned int Dummy)
{
  _local_unwind4(a1: *(_DWORD **)(Dummy + 40), a2: *(_DWORD *)(Dummy + 24), a3: *(_DWORD *)(Dummy + 28));
}

//------------------------------------------------------------------------------
// Address: 0x1001773E
// Name: _EH4_CallFilterFunc(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall _EH4_CallFilterFunc(int (*this)(void))
{
  return this();
}

//------------------------------------------------------------------------------
// Address: 0x10017755
// Name: _EH4_TransferToHandler(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall _EH4_TransferToHandler(int (__fastcall *this)(_DWORD, _DWORD))
{
  _NLG_Notify(a1: 1);
  return this(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1001776E
// Name: _EH4_GlobalUnwind(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall _EH4_GlobalUnwind(PVOID TargetFrame)
{
  RtlUnwind(TargetFrame, TargetIp: &ReturnPoint, ExceptionRecord: nullptr, ReturnValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10017788
// Name: _EH4_LocalUnwind(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _EH4_LocalUnwind(int a1, unsigned int a2, int a3, _DWORD *a4)
{
  return _local_unwind4(a1: a4, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x1001779F
// Name: __crtGetStringTypeA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _crtGetStringTypeA_stat(
        DWORD dwInfoType,
        const char *lpSrcStr,
        int cchSrc,
        unsigned __int16 *lpCharType,
        unsigned int code_page,
        int lcid,
        int bError)
{
  localeinfo_struct *plocinfo; // ecx
  int v8; // eax
  wchar_t *v9; // ebx
  localeinfo_struct *v10; // edi
  int v11; // eax
  int v12; // edi
  unsigned int v13; // eax
  void *v14; // esp
  wchar_t *v15; // eax
  int v16; // eax
  char *v18; // esi
  int v19; // eax
  const char *v20; // eax
  BOOL StringTypeA; // edi
  _DWORD v22[3]; // [esp+0h] [ebp-14h] BYREF
  int retval2; // [esp+Ch] [ebp-8h] BYREF

  v8 = f_use_1;
  v9 = nullptr;
  v10 = plocinfo;
  if ( f_use_1 == 0 )
  {
    if ( GetStringTypeW(dwInfoType: 1u, lpSrcStr: &SrcStr, cchSrc: 1, lpCharType: (LPWORD)&retval2) )
    {
      f_use_1 = 1;
      goto LABEL_10;
    }
    if ( GetLastError() == 120 )
    {
      v8 = 2;
      f_use_1 = 2;
    }
    else
    {
      v8 = f_use_1;
    }
  }
  if ( v8 != 2 && v8 != 0 )
  {
    if ( v8 != 1 )
      return 0;
LABEL_10:
    retval2 = 0;
    if ( code_page == 0 )
      code_page = v10->locinfo->lc_codepage;
    v11 = MultiByteToWideChar(
            CodePage: code_page,
            dwFlags: 8 * (bError != 0) + 1,
            lpMultiByteStr: lpSrcStr,
            cbMultiByte: cchSrc,
            lpWideCharStr: nullptr,
            cchWideChar: 0);
    v12 = v11;
    if ( v11 == 0 )
      return 0;
    if ( v11 > 0 && (unsigned int)v11 <= 0x7FFFFFF0 )
    {
      v13 = 2 * v11 + 8;
      if ( v13 > 0x400 )
      {
        v15 = (wchar_t *)operator new(nSize: 2 * v12 + 8);
        if ( v15 != nullptr )
        {
          *(_DWORD *)v15 = 56797;
          goto LABEL_20;
        }
      }
      else
      {
        v14 = alloca(v13);
        v15 = (wchar_t *)v22;
        if ( v22 != nullptr )
        {
          v22[0] = 52428;
LABEL_20:
          v15 += 4;
        }
      }
      v9 = v15;
    }
    if ( v9 != nullptr )
    {
      memset(dst: (int)v9, value: nullptr, count: 2 * v12);
      v16 = MultiByteToWideChar(
              CodePage: code_page,
              dwFlags: 1u,
              lpMultiByteStr: lpSrcStr,
              cbMultiByte: cchSrc,
              lpWideCharStr: v9,
              cchWideChar: v12);
      if ( v16 != 0 )
        retval2 = GetStringTypeW(dwInfoType, lpSrcStr: v9, cchSrc: v16, lpCharType);
      _freea(_Memory: v9);
      return retval2;
    }
    return 0;
  }
  v18 = nullptr;
  if ( lcid == 0 )
    lcid = v10->locinfo->lc_handle[2];
  if ( code_page == 0 )
    code_page = v10->locinfo->lc_codepage;
  v19 = __ansicp(lcid);
  if ( v19 == -1 )
    return 0;
  if ( v19 != code_page )
  {
    v20 = __convertcp(fromCP: code_page, toCP: v19, lpSrcStr, pcchSrc: &cchSrc, lpDestStr: nullptr, cchDest: 0);
    v18 = (char *)v20;
    if ( v20 == nullptr )
      return 0;
    lpSrcStr = v20;
  }
  StringTypeA = GetStringTypeA(Locale: lcid, dwInfoType, lpSrcStr, cchSrc, lpCharType);
  if ( v18 != nullptr )
    free(pMem: v18);
  return StringTypeA;
}

//------------------------------------------------------------------------------
// Address: 0x10017957
// Name: ___crtGetStringTypeA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtGetStringTypeA(
        localeinfo_struct *plocinfo,
        DWORD dwInfoType,
        const char *lpSrcStr,
        int cchSrc,
        unsigned __int16 *lpCharType,
        unsigned int code_page,
        int lcid,
        int bError)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _crtGetStringTypeA_stat(dwInfoType, lpSrcStr, cchSrc, lpCharType, code_page, lcid, bError);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10017997
// Name: ___free_lc_time
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __free_lc_time(__lc_time_data *lc_time)
{
  if ( lc_time != nullptr )
  {
    free(pMem: lc_time->wday_abbr[1]);
    free(pMem: lc_time->wday_abbr[2]);
    free(pMem: lc_time->wday_abbr[3]);
    free(pMem: lc_time->wday_abbr[4]);
    free(pMem: lc_time->wday_abbr[5]);
    free(pMem: lc_time->wday_abbr[6]);
    free(pMem: lc_time->wday_abbr[0]);
    free(pMem: lc_time->wday[1]);
    free(pMem: lc_time->wday[2]);
    free(pMem: lc_time->wday[3]);
    free(pMem: lc_time->wday[4]);
    free(pMem: lc_time->wday[5]);
    free(pMem: lc_time->wday[6]);
    free(pMem: lc_time->wday[0]);
    free(pMem: lc_time->month_abbr[0]);
    free(pMem: lc_time->month_abbr[1]);
    free(pMem: lc_time->month_abbr[2]);
    free(pMem: lc_time->month_abbr[3]);
    free(pMem: lc_time->month_abbr[4]);
    free(pMem: lc_time->month_abbr[5]);
    free(pMem: lc_time->month_abbr[6]);
    free(pMem: lc_time->month_abbr[7]);
    free(pMem: lc_time->month_abbr[8]);
    free(pMem: lc_time->month_abbr[9]);
    free(pMem: lc_time->month_abbr[10]);
    free(pMem: lc_time->month_abbr[11]);
    free(pMem: lc_time->month[0]);
    free(pMem: lc_time->month[1]);
    free(pMem: lc_time->month[2]);
    free(pMem: lc_time->month[3]);
    free(pMem: lc_time->month[4]);
    free(pMem: lc_time->month[5]);
    free(pMem: lc_time->month[6]);
    free(pMem: lc_time->month[7]);
    free(pMem: lc_time->month[8]);
    free(pMem: lc_time->month[9]);
    free(pMem: lc_time->month[10]);
    free(pMem: lc_time->month[11]);
    free(pMem: lc_time->ampm[0]);
    free(pMem: lc_time->ampm[1]);
    free(pMem: lc_time->ww_sdatefmt);
    free(pMem: lc_time->ww_ldatefmt);
    free(pMem: lc_time->ww_timefmt);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017B27
// Name: ___free_lconv_num
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __free_lconv_num(lconv *l)
{
  char *grouping; // esi

  if ( l != nullptr )
  {
    if ( l->decimal_point != __lconv_c.decimal_point )
      free(pMem: l->decimal_point);
    if ( l->thousands_sep != __lconv_c.thousands_sep )
      free(pMem: l->thousands_sep);
    grouping = l->grouping;
    if ( grouping != __lconv_c.grouping )
      free(pMem: grouping);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017B67
// Name: ___free_lconv_mon
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __free_lconv_mon(lconv *l)
{
  char *negative_sign; // esi

  if ( l != nullptr )
  {
    if ( l->int_curr_symbol != __lconv_c.int_curr_symbol )
      free(pMem: l->int_curr_symbol);
    if ( l->currency_symbol != __lconv_c.currency_symbol )
      free(pMem: l->currency_symbol);
    if ( l->mon_decimal_point != __lconv_c.mon_decimal_point )
      free(pMem: l->mon_decimal_point);
    if ( l->mon_thousands_sep != __lconv_c.mon_thousands_sep )
      free(pMem: l->mon_thousands_sep);
    if ( l->mon_grouping != __lconv_c.mon_grouping )
      free(pMem: l->mon_grouping);
    if ( l->positive_sign != __lconv_c.positive_sign )
      free(pMem: l->positive_sign);
    negative_sign = l->negative_sign;
    if ( negative_sign != __lconv_c.negative_sign )
      free(pMem: negative_sign);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10017BF0
// Name: _strcspn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strcspn(unsigned __int8 *string, unsigned __int8 *control)
{
  unsigned int v2; // eax
  int v5; // ecx
  signed __int32 v6[9]; // [esp+0h] [ebp-24h] BYREF

  v2 = 0;
  memset(v6, 0, 32);
  while ( 1 )
  {
    LOBYTE(v2) = *control;
    if ( *control == 0 )
      break;
    ++control;
    _bittestandset(v6, v2);
  }
  v5 = -1;
  do
  {
    ++v5;
    LOBYTE(v2) = *string;
    if ( *string == 0 )
      break;
    ++string;
  }
  while ( !_bittest(v6, v2) );
}

//------------------------------------------------------------------------------
// Address: 0x10017C40
// Name: _strpbrk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strpbrk(unsigned __int8 *string, unsigned __int8 *control)
{
  unsigned int v2; // eax
  signed __int32 v5[9]; // [esp+0h] [ebp-24h] BYREF

  v2 = 0;
  memset(v5, 0, 32);
  while ( 1 )
  {
    LOBYTE(v2) = *control;
    if ( *control == 0 )
      break;
    ++control;
    _bittestandset(v5, v2);
  }
  do
  {
    LOBYTE(v2) = *string;
    if ( *string == 0 )
      break;
    ++string;
  }
  while ( !_bittest(v5, v2) );
}

//------------------------------------------------------------------------------
// Address: 0x10017C80
// Name: ___ansicp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __ansicp(LCID lcid)
{
  char LCData[8]; // [esp+0h] [ebp-Ch] BYREF

  LCData[6] = 0;
  if ( GetLocaleInfoA(Locale: lcid, LCType: 0x1004u, lpLCData: LCData, cchData: 6) != 0 )
    return atol(nptr: LCData);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10017CC7
// Name: ___convertcp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl __convertcp(UINT fromCP, UINT toCP, char *lpSrcStr, int *pcchSrc, char *lpDestStr, int cchDest)
{
  int v6; // esi
  int v7; // eax
  bool v8; // cc
  unsigned int v9; // eax
  void *v10; // esp
  unsigned __int16 *v11; // eax
  char *v13; // ebx
  char *v14; // eax
  int v15; // eax
  _DWORD v16[3]; // [esp+0h] [ebp-40h] BYREF
  LPSTR lpMultiByteStr; // [esp+Ch] [ebp-34h]
  int *v18; // [esp+10h] [ebp-30h]
  int sb; // [esp+14h] [ebp-2Ch]
  unsigned __int8 *buf; // [esp+18h] [ebp-28h]
  int cchSrc; // [esp+1Ch] [ebp-24h]
  char *cbuffer; // [esp+20h] [ebp-20h]
  unsigned __int16 *wbuffer; // [esp+24h] [ebp-1Ch]
  _cpinfo cpi; // [esp+28h] [ebp-18h] BYREF

  buf = (unsigned __int8 *)lpSrcStr;
  v18 = pcchSrc;
  cchSrc = *pcchSrc;
  lpMultiByteStr = lpDestStr;
  cbuffer = nullptr;
  sb = 0;
  if ( fromCP != toCP )
  {
    if ( GetCPInfo(CodePage: fromCP, lpCPInfo: &cpi)
      && cpi.MaxCharSize == 1
      && GetCPInfo(CodePage: toCP, lpCPInfo: &cpi)
      && cpi.MaxCharSize == 1 )
    {
      v6 = cchSrc;
      sb = 1;
      if ( cchSrc == -1 )
      {
        strlen((char *)buf);
        v6 = v7 + 1;
      }
      v8 = v6 <= 0;
    }
    else
    {
      v6 = MultiByteToWideChar(
             CodePage: fromCP,
             dwFlags: 1u,
             lpMultiByteStr: (LPCCH)buf,
             cbMultiByte: cchSrc,
             lpWideCharStr: nullptr,
             cchWideChar: 0);
      v8 = v6 <= 0;
      if ( v6 == 0 )
        return nullptr;
    }
    if ( v8 || (unsigned int)v6 > 0x7FFFFFF0 )
    {
      wbuffer = nullptr;
LABEL_21:
      if ( wbuffer != nullptr )
      {
        memset(dst: (int)wbuffer, value: nullptr, count: 2 * v6);
        if ( MultiByteToWideChar(
               CodePage: fromCP,
               dwFlags: 1u,
               lpMultiByteStr: (LPCCH)buf,
               cbMultiByte: cchSrc,
               lpWideCharStr: wbuffer,
               cchWideChar: v6) != 0 )
        {
          v13 = lpMultiByteStr;
          if ( lpMultiByteStr != nullptr )
          {
            if ( WideCharToMultiByte(
                   CodePage: toCP,
                   dwFlags: 0,
                   lpWideCharStr: wbuffer,
                   cchWideChar: v6,
                   lpMultiByteStr,
                   cbMultiByte: cchDest,
                   lpDefaultChar: nullptr,
                   lpUsedDefaultChar: nullptr) != 0 )
              cbuffer = v13;
          }
          else if ( sb != 0
                 || (v6 = WideCharToMultiByte(
                            CodePage: toCP,
                            dwFlags: 0,
                            lpWideCharStr: wbuffer,
                            cchWideChar: v6,
                            lpMultiByteStr: nullptr,
                            cbMultiByte: 0,
                            lpDefaultChar: nullptr,
                            lpUsedDefaultChar: nullptr)) != 0 )
          {
            v14 = (char *)calloc(count: 1u, size: v6);
            cbuffer = v14;
            if ( v14 != nullptr )
            {
              v15 = WideCharToMultiByte(
                      CodePage: toCP,
                      dwFlags: 0,
                      lpWideCharStr: wbuffer,
                      cchWideChar: v6,
                      lpMultiByteStr: v14,
                      cbMultiByte: v6,
                      lpDefaultChar: nullptr,
                      lpUsedDefaultChar: nullptr);
              if ( v15 != 0 )
              {
                if ( cchSrc != -1 )
                  *v18 = v15;
              }
              else
              {
                free(pMem: cbuffer);
                cbuffer = nullptr;
              }
            }
          }
        }
        _freea(_Memory: wbuffer);
        return cbuffer;
      }
      return nullptr;
    }
    v9 = 2 * v6 + 8;
    if ( v9 > 0x400 )
    {
      v11 = (unsigned __int16 *)operator new(nSize: 2 * v6 + 8);
      if ( v11 != nullptr )
      {
        *(_DWORD *)v11 = 56797;
        goto LABEL_18;
      }
    }
    else
    {
      v10 = alloca(v9);
      v11 = (unsigned __int16 *)v16;
      if ( v16 != nullptr )
      {
        v16[0] = 52428;
LABEL_18:
        v11 += 4;
      }
    }
    wbuffer = v11;
    goto LABEL_21;
  }
  return cbuffer;
}

//------------------------------------------------------------------------------
// Address: 0x10017E79
// Name: ___report_gsfailure
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn __report_gsfailure()
{
  unsigned int v0; // eax
  unsigned int v1; // edx
  unsigned int v2; // ecx
  unsigned int v3; // ebx
  unsigned int v4; // edi
  unsigned int v5; // esi
  unsigned int v6; // kr00_4
  HANDLE CurrentProcess; // eax
  unsigned int vars0; // [esp+328h] [ebp+0h]
  void *retaddr; // [esp+32Ch] [ebp+4h]
  char v10; // [esp+330h] [ebp+8h] BYREF

  GS_ContextRecord.Eax = v0;
  GS_ContextRecord.Ecx = v2;
  GS_ContextRecord.Edx = v1;
  GS_ContextRecord.Ebx = v3;
  GS_ContextRecord.Esi = v5;
  GS_ContextRecord.Edi = v4;
  LOWORD(GS_ContextRecord.SegSs) = __SS__;
  LOWORD(GS_ContextRecord.SegCs) = __CS__;
  LOWORD(GS_ContextRecord.SegDs) = __DS__;
  LOWORD(GS_ContextRecord.SegEs) = __ES__;
  LOWORD(GS_ContextRecord.SegFs) = __FS__;
  LOWORD(GS_ContextRecord.SegGs) = __GS__;
  v6 = __readeflags();
  GS_ContextRecord.EFlags = v6;
  GS_ContextRecord.Ebp = vars0;
  GS_ContextRecord.Eip = (unsigned int)retaddr;
  GS_ContextRecord.Esp = (unsigned int)&v10;
  GS_ContextRecord.ContextFlags = 65537;
  GS_ExceptionRecord.ExceptionAddress = retaddr;
  GS_ExceptionRecord.ExceptionCode = -1073740791;
  GS_ExceptionRecord.ExceptionFlags = 1;
  DebuggerWasPresent = IsDebuggerPresent();
  _crt_debugger_hook();
  SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: nullptr);
  UnhandledExceptionFilter(ExceptionInfo: &GS_ExceptionPointers);
  if ( DebuggerWasPresent == 0 )
    _crt_debugger_hook();
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 0xC0000409);
}

//------------------------------------------------------------------------------
// Address: 0x10017F7D
// Name: __toupper_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _toupper_l(unsigned int c, localeinfo_struct *plocinfo)
{
  threadlocaleinfostruct *locinfo; // ecx
  int v4; // eax
  unsigned int result; // eax
  int v6; // ecx
  int v7; // eax
  unsigned __int16 v8; // ax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  char outbuffer[4]; // [esp+14h] [ebp-8h] BYREF
  char inbuffer[4]; // [esp+18h] [ebp-4h] BYREF
  int ca; // [esp+24h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( c >= 0x100 )
  {
    if ( _loc_update.localeinfo.locinfo->mb_cur_max > 1
      && (ca = (int)c >> 8, _isleadbyte_l(c: BYTE1(c), plocinfo: &_loc_update.localeinfo) != 0) )
    {
      inbuffer[0] = ca;
      inbuffer[1] = c;
      inbuffer[2] = 0;
      v6 = 2;
    }
    else
    {
      *_errno() = 42;
      inbuffer[0] = c;
      inbuffer[1] = 0;
      v6 = 1;
    }
    v7 = __crtLCMapStringA(
           plocinfo: &_loc_update.localeinfo,
           Locale: _loc_update.localeinfo.locinfo->lc_handle[2],
           dwMapFlags: 0x200u,
           lpSrcStr: inbuffer,
           cchSrc: v6,
           lpDestStr: outbuffer,
           cchDest: 3,
           code_page: _loc_update.localeinfo.locinfo->lc_codepage,
           bError: 1);
    if ( v7 != 0 )
    {
      if ( v7 == 1 )
      {
        result = (unsigned __int8)outbuffer[0];
      }
      else
      {
        LOBYTE(v8) = 0;
        HIBYTE(v8) = outbuffer[0];
        result = (unsigned __int8)outbuffer[1] | v8;
      }
      goto LABEL_18;
    }
  }
  else
  {
    locinfo = _loc_update.localeinfo.locinfo;
    if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->pctype[c] & 2;
    }
    else
    {
      v4 = _isctype_l(c, mask: 2, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v4 != 0 )
    {
      result = locinfo->pcumap[c];
LABEL_18:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x10018095
// Name: _toupper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl toupper(unsigned int c)
{
  unsigned int result; // eax

  if ( __locale_changed != 0 )
    return _toupper_l(c, plocinfo: nullptr);
  result = c;
  if ( c - 97 <= 0x19 )
    return c - 32;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100180BC
// Name: __mbtowc_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbtowc_l(wchar_t *pwc, const char *s, signed int n, localeinfo_struct *plocinfo)
{
  int result; // eax
  threadlocaleinfostruct *locinfo; // eax
  int mb_cur_max; // ecx
  bool v7; // zf
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  if ( s == nullptr || n == 0 )
    return 0;
  if ( *s == 0 )
  {
    if ( pwc != nullptr )
      *pwc = 0;
    return 0;
  }
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->lc_handle[2] == 0 )
  {
    if ( pwc != nullptr )
      *pwc = *(unsigned __int8 *)s;
    goto LABEL_11;
  }
  if ( _isleadbyte_l(c: *s, plocinfo: &_loc_update.localeinfo) != 0 )
  {
    locinfo = _loc_update.localeinfo.locinfo;
    mb_cur_max = _loc_update.localeinfo.locinfo->mb_cur_max;
    if ( mb_cur_max > 1
      && n >= mb_cur_max
      && (v7 = MultiByteToWideChar(
                 CodePage: _loc_update.localeinfo.locinfo->lc_codepage,
                 dwFlags: 9u,
                 lpMultiByteStr: s,
                 cbMultiByte: mb_cur_max,
                 lpWideCharStr: pwc,
                 cchWideChar: pwc != nullptr) == 0,
          locinfo = _loc_update.localeinfo.locinfo,
          !v7)
      || (unsigned int)n >= locinfo->mb_cur_max && s[1] != 0 )
    {
      result = locinfo->mb_cur_max;
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  else if ( MultiByteToWideChar(
              CodePage: _loc_update.localeinfo.locinfo->lc_codepage,
              dwFlags: 9u,
              lpMultiByteStr: s,
              cbMultiByte: 1,
              lpWideCharStr: pwc,
              cchWideChar: pwc != nullptr) != 0 )
  {
LABEL_11:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 1;
  }
  *_errno() = 42;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100181CF
// Name: _mbtowc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl mbtowc(wchar_t *pwc, const char *s, unsigned int n)
{
  return _mbtowc_l(pwc, s, n, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100181E6
// Name: __filbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _filbuf@<eax>(unsigned int a1@<ebx>, _iobuf *str)
{
  int flag; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  ioinfo **v6; // edi
  ioinfo *v7; // eax
  int v8; // eax
  char *ptr; // ecx
  int result; // eax
  char *base; // [esp-8h] [ebp-10h]
  unsigned int bufsiz; // [esp-4h] [ebp-Ch]

  if ( str == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2: 0, a3: 0);
    return -1;
  }
  flag = str->_flag;
  if ( (flag & 0x83) == 0 || (flag & 0x40) != 0 )
    return -1;
  if ( (flag & 2) != 0 )
  {
    str->_flag = flag | 0x20;
    return -1;
  }
  v3 = flag | 1;
  str->_flag = v3;
  if ( (v3 & 0x10C) != 0 )
    str->_ptr = str->_base;
  else
    _getbuf(str);
  bufsiz = str->_bufsiz;
  base = str->_base;
  v4 = _fileno(a1, a2: 0, stream: str);
  v5 = _read(fh: v4, buf: base, cnt: bufsiz);
  str->_cnt = v5;
  if ( v5 == 0 || v5 == -1 )
  {
    str->_flag |= v5 != 0 ? 32 : 16;
    str->_cnt = 0;
    return -1;
  }
  if ( (str->_flag & 0x82) == 0 )
  {
    if ( _fileno(a1, a2: 0, stream: str) == -1 || _fileno(a1, a2: 0, stream: str) == -2 )
    {
      v7 = &__badioinfo;
    }
    else
    {
      v6 = &__pioinfo[_fileno(a1, a2: 0, stream: str) >> 5];
      v7 = &(*v6)[_fileno(a1, a2: (unsigned int)v6, stream: str) & 0x1F];
    }
    if ( (v7->osfile & 0x82) == 0x82 )
      str->_flag |= 0x2000u;
  }
  if ( str->_bufsiz == 512 )
  {
    v8 = str->_flag;
    if ( (v8 & 8) != 0 && (v8 & 0x400) == 0 )
      str->_bufsiz = 4096;
  }
  ptr = str->_ptr;
  --str->_cnt;
  result = (unsigned __int8)*ptr;
  str->_ptr = ptr + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10018306
// Name: __ungetc_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ungetc_nolock@<eax>(unsigned int a1@<ebx>, ioinfo **a2@<edi>, int ch, _iobuf *str)
{
  ioinfo *v4; // eax
  ioinfo **v5; // edi
  ioinfo *v6; // eax
  int flag; // eax
  char *v9; // eax
  int v10; // eax

  if ( (str->_flag & 0x40) == 0 )
  {
    if ( _fileno(a1, (unsigned int)a2, stream: str) == -1
      || _fileno(a1: (unsigned int)&__badioinfo, (unsigned int)a2, stream: str) == -2 )
    {
      v4 = &__badioinfo;
    }
    else
    {
      a2 = &__pioinfo[_fileno(a1: (unsigned int)&__badioinfo, (unsigned int)a2, stream: str) >> 5];
      v4 = &(*a2)[_fileno(a1: (unsigned int)&__badioinfo, (unsigned int)a2, stream: str) & 0x1F];
    }
    if ( (*((_BYTE *)v4 + 36) & 0x7F) != 0
      || (_fileno(a1: (unsigned int)&__badioinfo, (unsigned int)a2, stream: str) == -1
       || _fileno(a1: (unsigned int)&__badioinfo, (unsigned int)a2, stream: str) == -2
        ? (v6 = &__badioinfo)
        : (v5 = &__pioinfo[_fileno(a1: (unsigned int)&__badioinfo, (unsigned int)a2, stream: str) >> 5],
           v6 = &(*v5)[_fileno(a1: (unsigned int)&__badioinfo, a2: (unsigned int)v5, stream: str) & 0x1F]),
          *((char *)v6 + 36) < 0) )
    {
      *_errno() = 22;
      _invalid_parameter(a1: (unsigned int)&__badioinfo, a2: 0, a3: (unsigned int)str);
      return -1;
    }
  }
  if ( ch == -1 )
    return -1;
  flag = str->_flag;
  if ( (flag & 1) == 0 && ((flag & 0x80u) == 0 || (flag & 2) != 0) )
    return -1;
  if ( str->_base == nullptr )
    _getbuf(str);
  if ( str->_ptr == str->_base )
  {
    if ( str->_cnt != 0 )
      return -1;
    ++str->_ptr;
  }
  v9 = --str->_ptr;
  if ( (str->_flag & 0x40) != 0 )
  {
    if ( *v9 != (_BYTE)ch )
    {
      str->_ptr = v9 + 1;
      return -1;
    }
  }
  else
  {
    *v9 = ch;
  }
  v10 = str->_flag;
  ++str->_cnt;
  str->_flag = v10 & 0xFFFFFFEE | 1;
  return (unsigned __int8)ch;
}

//------------------------------------------------------------------------------
// Address: 0x10018424
// Name: __ld12tod
// Source: linker_block_proximity
//------------------------------------------------------------------------------
INTRNCVT_STATUS __cdecl _ld12tod(_LDBL12 *pld12, _CRT_DOUBLE *d)
{
  __int16 v2; // bx
  int v3; // ebx
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  INTRNCVT_STATUS result; // eax
  int v8; // esi
  unsigned int *v9; // edi
  int v10; // eax
  bool i; // zf
  int v12; // eax
  unsigned int v13; // edx
  unsigned int *v14; // ecx
  bool v15; // cf
  unsigned int v16; // esi
  int v17; // eax
  int v18; // edx
  int *v19; // ebx
  unsigned int v20; // esi
  char v21; // cl
  int v22; // edx
  unsigned int *v23; // ecx
  int v24; // esi
  int v25; // eax
  unsigned int *v26; // ebx
  bool j; // zf
  int v28; // eax
  unsigned int v29; // edx
  unsigned int *v30; // ecx
  unsigned int v31; // edi
  int k; // ecx
  unsigned int *v33; // ecx
  unsigned int v34; // esi
  int v35; // edi
  int v36; // eax
  int v37; // edx
  int *v38; // ebx
  unsigned int v39; // esi
  char v40; // cl
  int v41; // edx
  unsigned int *v42; // ecx
  int v43; // eax
  int v44; // edx
  int *v45; // ebx
  unsigned int v46; // esi
  char v47; // cl
  int v48; // edx
  unsigned int *v49; // ecx
  int v50; // eax
  int v51; // edx
  unsigned int v52; // edi
  int v53; // edx
  unsigned int *v54; // ecx
  unsigned int v55; // ebx
  int v56; // edx
  unsigned int v57; // [esp+8h] [ebp-2Ch]
  int v58; // [esp+Ch] [ebp-28h]
  int v59; // [esp+10h] [ebp-24h]
  unsigned int v60; // [esp+14h] [ebp-20h] BYREF
  int v61; // [esp+18h] [ebp-1Ch]
  int v62; // [esp+1Ch] [ebp-18h] BYREF
  int v63; // [esp+20h] [ebp-14h]
  int v64; // [esp+24h] [ebp-10h]
  int v65; // [esp+28h] [ebp-Ch]
  int v66; // [esp+2Ch] [ebp-8h]
  int v67; // [esp+30h] [ebp-4h]
  _LDBL12 *pld12a; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12b; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12c; // [esp+3Ch] [ebp+8h]
  int pld12d; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12e; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12f; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12g; // [esp+3Ch] [ebp+8h]

  v2 = *(_WORD *)&pld12->ld12[10];
  v63 = v2 & 0x8000;
  v60 = *(_DWORD *)&pld12->ld12[6];
  v3 = (v2 & 0x7FFF) - 0x3FFF;
  v4 = *(unsigned __int16 *)pld12->ld12 << 16;
  v61 = *(_DWORD *)&pld12->ld12[2];
  v62 = v4;
  if ( v3 != -16383 )
  {
    pld12a = nullptr;
    v57 = v60;
    v58 = v61;
    v59 = v62;
    v8 = DoubleFormat.precision - 1;
    v64 = v3;
    v65 = DoubleFormat.precision / 32;
    v9 = &v60 + DoubleFormat.precision / 32;
    v66 = 31 - DoubleFormat.precision % 32;
    if ( ((1 << (31 - DoubleFormat.precision % 32)) & *v9) != 0 )
    {
      v10 = v65;
      for ( i = (~(-1 << (31 - DoubleFormat.precision % 32)) & *(&v60 + v65)) == 0; i; i = *(&v60 + v10) == 0 )
      {
        if ( ++v10 >= 3 )
          goto LABEL_22;
      }
      v12 = v8 / 32;
      v67 = 0;
      v13 = 1 << (31 - v8 % 32);
      v14 = &v60 + v8 / 32;
      pld12b = (_LDBL12 *)(v13 + *v14);
      if ( (unsigned int)pld12b >= *v14 )
      {
        v15 = (unsigned int)pld12b < v13;
        goto LABEL_18;
      }
LABEL_19:
      v67 = 1;
      while ( 1 )
      {
        --v12;
        *v14 = (unsigned int)pld12b;
        if ( v12 < 0 || v67 == 0 )
          break;
        v67 = 0;
        v14 = &v60 + v12;
        v16 = *v14 + 1;
        pld12b = (_LDBL12 *)v16;
        if ( v16 >= *v14 )
        {
          v15 = v16 == 0;
LABEL_18:
          if ( !v15 )
            continue;
        }
        goto LABEL_19;
      }
      pld12a = (_LDBL12 *)v67;
    }
LABEL_22:
    *v9 &= -1 << v66;
    if ( v65 + 1 < 3 )
      memset(&v60 + v65 + 1, 0, 4 * (3 - (v65 + 1)));
    if ( pld12a != nullptr )
      ++v3;
    if ( v3 >= DoubleFormat.min_exp - DoubleFormat.precision )
    {
      if ( v3 > DoubleFormat.min_exp )
      {
        if ( v3 < DoubleFormat.max_exp )
        {
          v60 &= ~0x80000000;
          v5 = DoubleFormat.bias + v3;
          v50 = DoubleFormat.exp_width / 32;
          v51 = DoubleFormat.exp_width % 32;
          v65 = 0;
          pld12g = nullptr;
          v67 = 32 - DoubleFormat.exp_width % 32;
          do
          {
            v52 = *(&v60 + (_DWORD)pld12g);
            v64 = ~(-1 << v51) & v52;
            *(&v60 + (_DWORD)pld12g) = v65 | (v52 >> v51);
            pld12g = (_LDBL12 *)((char *)pld12g + 1);
            v65 = v64 << v67;
          }
          while ( (int)pld12g < 3 );
          v53 = 2;
          v54 = (unsigned int *)(&v62 - v50);
          do
          {
            if ( v53 < v50 )
              *(&v60 + v53) = 0;
            else
              *(&v60 + v53) = *v54;
            --v53;
            --v54;
          }
          while ( v53 >= 0 );
          result = INTRNCVT_OK;
        }
        else
        {
          v61 = 0;
          v62 = 0;
          v60 = 0x80000000;
          v43 = DoubleFormat.exp_width / 32;
          v44 = DoubleFormat.exp_width % 32;
          v65 = 0;
          pld12f = nullptr;
          v67 = 32 - DoubleFormat.exp_width % 32;
          do
          {
            v45 = (int *)(&v60 + (_DWORD)pld12f);
            v46 = *v45;
            v64 = ~(-1 << v44) & *v45;
            v47 = v67;
            *v45 = v65 | (v46 >> v44);
            pld12f = (_LDBL12 *)((char *)pld12f + 1);
            v65 = v64 << v47;
          }
          while ( (int)pld12f < 3 );
          v48 = 2;
          v49 = (unsigned int *)(&v62 - v43);
          do
          {
            if ( v48 < v43 )
              *(&v60 + v48) = 0;
            else
              *(&v60 + v48) = *v49;
            --v48;
            --v49;
          }
          while ( v48 >= 0 );
          v5 = DoubleFormat.bias + DoubleFormat.max_exp;
          result = INTRNCVT_OVERFLOW;
        }
        goto LABEL_79;
      }
      v60 = v57;
      v61 = v58;
      v17 = (DoubleFormat.min_exp - v64) / 32;
      v62 = v59;
      v18 = (DoubleFormat.min_exp - v64) % 32;
      v65 = 0;
      pld12c = nullptr;
      v67 = 32 - v18;
      do
      {
        v19 = (int *)(&v60 + (_DWORD)pld12c);
        v20 = *v19;
        v64 = ~(-1 << v18) & *v19;
        v21 = v67;
        *v19 = v65 | (v20 >> v18);
        pld12c = (_LDBL12 *)((char *)pld12c + 1);
        v65 = v64 << v21;
      }
      while ( (int)pld12c < 3 );
      v22 = 2;
      v23 = (unsigned int *)(&v62 - v17);
      do
      {
        if ( v22 < v17 )
          *(&v60 + v22) = 0;
        else
          *(&v60 + v22) = *v23;
        --v22;
        --v23;
      }
      while ( v22 >= 0 );
      v24 = DoubleFormat.precision - 1;
      v25 = DoubleFormat.precision / 32;
      v65 = DoubleFormat.precision / 32;
      v26 = &v60 + DoubleFormat.precision / 32;
      v64 = 31 - DoubleFormat.precision % 32;
      if ( ((1 << (31 - DoubleFormat.precision % 32)) & *v26) != 0 )
      {
        for ( j = (~(-1 << (31 - DoubleFormat.precision % 32)) & *(&v60 + v25)) == 0; j; j = *(&v60 + v25) == 0 )
        {
          if ( ++v25 >= 3 )
            goto LABEL_52;
        }
        v28 = v24 / 32;
        pld12d = 0;
        v29 = 1 << (31 - v24 % 32);
        v30 = &v60 + v24 / 32;
        v31 = *v30 + v29;
        if ( v31 < *v30 || v31 < v29 )
          pld12d = 1;
        *v30 = v31;
        for ( k = pld12d; --v28 >= 0 && k != 0; k = v35 )
        {
          v33 = &v60 + v28;
          v34 = *v33 + 1;
          v35 = 0;
          if ( v34 < *v33 || *v33 == -1 )
            v35 = 1;
          *v33 = v34;
        }
      }
LABEL_52:
      *v26 &= -1 << v64;
      if ( v65 + 1 < 3 )
        memset(&v60 + v65 + 1, 0, 4 * (3 - (v65 + 1)));
      v36 = (DoubleFormat.exp_width + 1) / 32;
      v37 = (DoubleFormat.exp_width + 1) % 32;
      v65 = 0;
      pld12e = nullptr;
      v67 = 32 - v37;
      do
      {
        v38 = (int *)(&v60 + (_DWORD)pld12e);
        v39 = *v38;
        v64 = ~(-1 << v37) & *v38;
        v40 = v67;
        *v38 = v65 | (v39 >> v37);
        pld12e = (_LDBL12 *)((char *)pld12e + 1);
        v65 = v64 << v40;
      }
      while ( (int)pld12e < 3 );
      v41 = 2;
      v42 = (unsigned int *)(&v62 - v36);
      do
      {
        if ( v41 < v36 )
          *(&v60 + v41) = 0;
        else
          *(&v60 + v41) = *v42;
        --v41;
        --v42;
      }
      while ( v41 >= 0 );
    }
    else
    {
      v60 = 0;
      v61 = 0;
      v62 = 0;
    }
    v5 = 0;
    result = INTRNCVT_UNDERFLOW;
    goto LABEL_79;
  }
  v5 = 0;
  v6 = 0;
  while ( *(&v60 + v6) == 0 )
  {
    if ( ++v6 >= 3 )
    {
      result = INTRNCVT_OK;
      goto LABEL_79;
    }
  }
  v60 = 0;
  v61 = 0;
  v62 = 0;
  result = INTRNCVT_UNDERFLOW;
LABEL_79:
  v55 = v60 | (v63 != 0 ? 0x80000000 : 0) | (v5 << (31 - LOBYTE(DoubleFormat.exp_width)));
  if ( DoubleFormat.format_width == 64 )
  {
    v56 = v61;
    HIDWORD(d->x) = v55;
    LODWORD(d->x) = v56;
  }
  else if ( DoubleFormat.format_width == 32 )
  {
    LODWORD(d->x) = v55;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10018966
// Name: __ld12tof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
INTRNCVT_STATUS __cdecl _ld12tof(_LDBL12 *pld12, _CRT_FLOAT *f)
{
  __int16 v2; // bx
  int v3; // ebx
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  INTRNCVT_STATUS result; // eax
  int v8; // esi
  unsigned int *v9; // edi
  int v10; // eax
  bool i; // zf
  int v12; // eax
  unsigned int v13; // edx
  unsigned int *v14; // ecx
  bool v15; // cf
  unsigned int v16; // esi
  int v17; // eax
  int v18; // edx
  int *v19; // ebx
  unsigned int v20; // esi
  char v21; // cl
  int v22; // edx
  unsigned int *v23; // ecx
  int v24; // esi
  int v25; // eax
  unsigned int *v26; // ebx
  bool j; // zf
  int v28; // eax
  unsigned int v29; // edx
  unsigned int *v30; // ecx
  unsigned int v31; // edi
  int k; // ecx
  unsigned int *v33; // ecx
  unsigned int v34; // esi
  int v35; // edi
  int v36; // eax
  int v37; // edx
  int *v38; // ebx
  unsigned int v39; // esi
  char v40; // cl
  int v41; // edx
  unsigned int *v42; // ecx
  int v43; // eax
  int v44; // edx
  int *v45; // ebx
  unsigned int v46; // esi
  char v47; // cl
  int v48; // edx
  unsigned int *v49; // ecx
  int v50; // eax
  int v51; // edx
  unsigned int v52; // edi
  int v53; // edx
  unsigned int *v54; // ecx
  float v55; // ebx
  float v56; // edx
  unsigned int v57; // [esp+8h] [ebp-2Ch]
  float v58; // [esp+Ch] [ebp-28h]
  int v59; // [esp+10h] [ebp-24h]
  unsigned int v60; // [esp+14h] [ebp-20h] BYREF
  float v61; // [esp+18h] [ebp-1Ch]
  int v62; // [esp+1Ch] [ebp-18h] BYREF
  int v63; // [esp+20h] [ebp-14h]
  int v64; // [esp+24h] [ebp-10h]
  int v65; // [esp+28h] [ebp-Ch]
  int v66; // [esp+2Ch] [ebp-8h]
  int v67; // [esp+30h] [ebp-4h]
  _LDBL12 *pld12a; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12b; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12c; // [esp+3Ch] [ebp+8h]
  int pld12d; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12e; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12f; // [esp+3Ch] [ebp+8h]
  _LDBL12 *pld12g; // [esp+3Ch] [ebp+8h]

  v2 = *(_WORD *)&pld12->ld12[10];
  v63 = v2 & 0x8000;
  v60 = *(_DWORD *)&pld12->ld12[6];
  v3 = (v2 & 0x7FFF) - 0x3FFF;
  v4 = *(unsigned __int16 *)pld12->ld12 << 16;
  v61 = *(float *)&pld12->ld12[2];
  v62 = v4;
  if ( v3 != -16383 )
  {
    pld12a = nullptr;
    v57 = v60;
    v58 = v61;
    v59 = v62;
    v8 = FloatFormat.precision - 1;
    v64 = v3;
    v65 = FloatFormat.precision / 32;
    v9 = &v60 + FloatFormat.precision / 32;
    v66 = 31 - FloatFormat.precision % 32;
    if ( ((1 << (31 - FloatFormat.precision % 32)) & *v9) != 0 )
    {
      v10 = v65;
      for ( i = (~(-1 << (31 - FloatFormat.precision % 32)) & *(&v60 + v65)) == 0; i; i = *(&v60 + v10) == 0 )
      {
        if ( ++v10 >= 3 )
          goto LABEL_22;
      }
      v12 = v8 / 32;
      v67 = 0;
      v13 = 1 << (31 - v8 % 32);
      v14 = &v60 + v8 / 32;
      pld12b = (_LDBL12 *)(v13 + *v14);
      if ( (unsigned int)pld12b >= *v14 )
      {
        v15 = (unsigned int)pld12b < v13;
        goto LABEL_18;
      }
LABEL_19:
      v67 = 1;
      while ( 1 )
      {
        --v12;
        *v14 = (unsigned int)pld12b;
        if ( v12 < 0 || v67 == 0 )
          break;
        v67 = 0;
        v14 = &v60 + v12;
        v16 = *v14 + 1;
        pld12b = (_LDBL12 *)v16;
        if ( v16 >= *v14 )
        {
          v15 = v16 == 0;
LABEL_18:
          if ( !v15 )
            continue;
        }
        goto LABEL_19;
      }
      pld12a = (_LDBL12 *)v67;
    }
LABEL_22:
    *v9 &= -1 << v66;
    if ( v65 + 1 < 3 )
      memset(&v60 + v65 + 1, 0, 4 * (3 - (v65 + 1)));
    if ( pld12a != nullptr )
      ++v3;
    if ( v3 >= FloatFormat.min_exp - FloatFormat.precision )
    {
      if ( v3 > FloatFormat.min_exp )
      {
        if ( v3 < FloatFormat.max_exp )
        {
          v60 &= ~0x80000000;
          v5 = FloatFormat.bias + v3;
          v50 = FloatFormat.exp_width / 32;
          v51 = FloatFormat.exp_width % 32;
          v65 = 0;
          pld12g = nullptr;
          v67 = 32 - FloatFormat.exp_width % 32;
          do
          {
            v52 = *(&v60 + (_DWORD)pld12g);
            v64 = ~(-1 << v51) & v52;
            *(&v60 + (_DWORD)pld12g) = v65 | (v52 >> v51);
            pld12g = (_LDBL12 *)((char *)pld12g + 1);
            v65 = v64 << v67;
          }
          while ( (int)pld12g < 3 );
          v53 = 2;
          v54 = (unsigned int *)(&v62 - v50);
          do
          {
            if ( v53 < v50 )
              *(&v60 + v53) = 0;
            else
              *(&v60 + v53) = *v54;
            --v53;
            --v54;
          }
          while ( v53 >= 0 );
          result = INTRNCVT_OK;
        }
        else
        {
          v61 = 0.0;
          v62 = 0;
          v60 = 0x80000000;
          v43 = FloatFormat.exp_width / 32;
          v44 = FloatFormat.exp_width % 32;
          v65 = 0;
          pld12f = nullptr;
          v67 = 32 - FloatFormat.exp_width % 32;
          do
          {
            v45 = (int *)(&v60 + (_DWORD)pld12f);
            v46 = *v45;
            v64 = ~(-1 << v44) & *v45;
            v47 = v67;
            *v45 = v65 | (v46 >> v44);
            pld12f = (_LDBL12 *)((char *)pld12f + 1);
            v65 = v64 << v47;
          }
          while ( (int)pld12f < 3 );
          v48 = 2;
          v49 = (unsigned int *)(&v62 - v43);
          do
          {
            if ( v48 < v43 )
              *(&v60 + v48) = 0;
            else
              *(&v60 + v48) = *v49;
            --v48;
            --v49;
          }
          while ( v48 >= 0 );
          v5 = FloatFormat.bias + FloatFormat.max_exp;
          result = INTRNCVT_OVERFLOW;
        }
        goto LABEL_79;
      }
      v60 = v57;
      v61 = v58;
      v17 = (FloatFormat.min_exp - v64) / 32;
      v62 = v59;
      v18 = (FloatFormat.min_exp - v64) % 32;
      v65 = 0;
      pld12c = nullptr;
      v67 = 32 - v18;
      do
      {
        v19 = (int *)(&v60 + (_DWORD)pld12c);
        v20 = *v19;
        v64 = ~(-1 << v18) & *v19;
        v21 = v67;
        *v19 = v65 | (v20 >> v18);
        pld12c = (_LDBL12 *)((char *)pld12c + 1);
        v65 = v64 << v21;
      }
      while ( (int)pld12c < 3 );
      v22 = 2;
      v23 = (unsigned int *)(&v62 - v17);
      do
      {
        if ( v22 < v17 )
          *(&v60 + v22) = 0;
        else
          *(&v60 + v22) = *v23;
        --v22;
        --v23;
      }
      while ( v22 >= 0 );
      v24 = FloatFormat.precision - 1;
      v25 = FloatFormat.precision / 32;
      v65 = FloatFormat.precision / 32;
      v26 = &v60 + FloatFormat.precision / 32;
      v64 = 31 - FloatFormat.precision % 32;
      if ( ((1 << (31 - FloatFormat.precision % 32)) & *v26) != 0 )
      {
        for ( j = (~(-1 << (31 - FloatFormat.precision % 32)) & *(&v60 + v25)) == 0; j; j = *(&v60 + v25) == 0 )
        {
          if ( ++v25 >= 3 )
            goto LABEL_52;
        }
        v28 = v24 / 32;
        pld12d = 0;
        v29 = 1 << (31 - v24 % 32);
        v30 = &v60 + v24 / 32;
        v31 = *v30 + v29;
        if ( v31 < *v30 || v31 < v29 )
          pld12d = 1;
        *v30 = v31;
        for ( k = pld12d; --v28 >= 0 && k != 0; k = v35 )
        {
          v33 = &v60 + v28;
          v34 = *v33 + 1;
          v35 = 0;
          if ( v34 < *v33 || *v33 == -1 )
            v35 = 1;
          *v33 = v34;
        }
      }
LABEL_52:
      *v26 &= -1 << v64;
      if ( v65 + 1 < 3 )
        memset(&v60 + v65 + 1, 0, 4 * (3 - (v65 + 1)));
      v36 = (FloatFormat.exp_width + 1) / 32;
      v37 = (FloatFormat.exp_width + 1) % 32;
      v65 = 0;
      pld12e = nullptr;
      v67 = 32 - v37;
      do
      {
        v38 = (int *)(&v60 + (_DWORD)pld12e);
        v39 = *v38;
        v64 = ~(-1 << v37) & *v38;
        v40 = v67;
        *v38 = v65 | (v39 >> v37);
        pld12e = (_LDBL12 *)((char *)pld12e + 1);
        v65 = v64 << v40;
      }
      while ( (int)pld12e < 3 );
      v41 = 2;
      v42 = (unsigned int *)(&v62 - v36);
      do
      {
        if ( v41 < v36 )
          *(&v60 + v41) = 0;
        else
          *(&v60 + v41) = *v42;
        --v41;
        --v42;
      }
      while ( v41 >= 0 );
    }
    else
    {
      v60 = 0;
      v61 = 0.0;
      v62 = 0;
    }
    v5 = 0;
    result = INTRNCVT_UNDERFLOW;
    goto LABEL_79;
  }
  v5 = 0;
  v6 = 0;
  while ( *(&v60 + v6) == 0 )
  {
    if ( ++v6 >= 3 )
    {
      result = INTRNCVT_OK;
      goto LABEL_79;
    }
  }
  v60 = 0;
  v61 = 0.0;
  v62 = 0;
  result = INTRNCVT_UNDERFLOW;
LABEL_79:
  LODWORD(v55) = v60 | (v63 != 0 ? 0x80000000 : 0) | (v5 << (31 - LOBYTE(FloatFormat.exp_width)));
  if ( FloatFormat.format_width == 64 )
  {
    v56 = v61;
    f[1].f = v55;
    f->f = v56;
  }
  else if ( FloatFormat.format_width == 32 )
  {
    f->f = v55;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10018EA8
// Name: ___mtold12
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __mtold12(char *manptr, unsigned int manlen, _LDBL12 *ld12)
{
  int v3; // ecx
  unsigned int v4; // ebx
  unsigned int v5; // edx
  unsigned int v6; // edi
  int v7; // ebx
  unsigned int v8; // ecx
  unsigned int v9; // ebx
  int v10; // esi
  unsigned int v11; // ecx
  unsigned int v12; // edi
  int v13; // ebx
  unsigned int v14; // edx
  unsigned int v15; // esi
  int v16; // edx
  unsigned int v17; // ecx
  unsigned int v18; // esi
  unsigned int v19; // edi
  int v20; // ecx
  __int16 expn; // [esp+Ch] [ebp-18h]
  int v22; // [esp+10h] [ebp-14h]
  int v23; // [esp+10h] [ebp-14h]
  unsigned int tmp_4; // [esp+18h] [ebp-Ch]
  int tmp_8; // [esp+1Ch] [ebp-8h]

  expn = 16462;
  *(_DWORD *)ld12->ld12 = 0;
  *(_DWORD *)&ld12->ld12[4] = 0;
  for ( *(_DWORD *)&ld12->ld12[8] = 0; manlen != 0; ++manptr )
  {
    tmp_4 = *(_DWORD *)&ld12->ld12[4];
    tmp_8 = *(_DWORD *)&ld12->ld12[8];
    v22 = 0;
    v3 = __SPAIR64__(*(_QWORD *)&ld12->ld12[4] >> 31, *(__int64 *)ld12->ld12 >> 31) >> 31;
    v4 = *(_DWORD *)ld12->ld12;
    v5 = (2LL * *(_QWORD *)ld12->ld12) >> 31;
    v6 = 5 * *(_DWORD *)ld12->ld12;
    *(_DWORD *)ld12->ld12 *= 4;
    *(_DWORD *)&ld12->ld12[4] = v5;
    *(_DWORD *)&ld12->ld12[8] = v3;
    if ( 5 * v4 < 4 * v4 || v6 < v4 )
      v22 = 1;
    v7 = 0;
    *(_DWORD *)ld12->ld12 = v6;
    if ( v22 != 0 )
    {
      if ( v5 + 1 < v5 || v5 == -1 )
        v7 = 1;
      *(_DWORD *)&ld12->ld12[4] = v5 + 1;
      if ( v7 != 0 )
        *(_DWORD *)&ld12->ld12[8] = v3 + 1;
    }
    v8 = *(_DWORD *)&ld12->ld12[4];
    v9 = v8 + tmp_4;
    v10 = 0;
    if ( v8 + tmp_4 < v8 || v9 < tmp_4 )
      v10 = 1;
    *(_DWORD *)&ld12->ld12[4] = v9;
    if ( v10 != 0 )
      ++*(_DWORD *)&ld12->ld12[8];
    *(_DWORD *)&ld12->ld12[8] += tmp_8;
    v23 = 0;
    v11 = 2 * v6;
    v12 = (v6 >> 31) | (2 * v9);
    v13 = (v9 >> 31) | (2 * *(_DWORD *)&ld12->ld12[8]);
    *(_DWORD *)ld12->ld12 = v11;
    *(_DWORD *)&ld12->ld12[4] = v12;
    *(_DWORD *)&ld12->ld12[8] = v13;
    v14 = *manptr;
    v15 = v11 + v14;
    if ( v11 + v14 < v11 || v15 < v14 )
      v23 = 1;
    *(_DWORD *)ld12->ld12 = v15;
    if ( v23 != 0 )
    {
      v16 = 0;
      if ( v12 + 1 < v12 || v12 == -1 )
        v16 = 1;
      *(_DWORD *)&ld12->ld12[4] = v12 + 1;
      if ( v16 != 0 )
        *(_DWORD *)&ld12->ld12[8] = v13 + 1;
    }
    --manlen;
  }
  while ( *(_DWORD *)&ld12->ld12[8] == 0 )
  {
    v17 = *(_DWORD *)&ld12->ld12[4];
    *(_DWORD *)&ld12->ld12[8] = HIWORD(v17);
    expn -= 16;
    *(_QWORD *)ld12->ld12 = __PAIR64__(v17, *(_DWORD *)ld12->ld12) << 16;
  }
  if ( (*(_DWORD *)&ld12->ld12[8] & 0x8000) == 0 )
  {
    do
    {
      v18 = *(_DWORD *)ld12->ld12;
      v19 = *(_DWORD *)&ld12->ld12[4];
      --expn;
      *(_DWORD *)ld12->ld12 *= 2;
      v20 = (v19 >> 31) | (2 * *(_DWORD *)&ld12->ld12[8]);
      *(_DWORD *)&ld12->ld12[4] = (v18 >> 31) | (2 * v19);
      *(_DWORD *)&ld12->ld12[8] = v20;
    }
    while ( (v20 & 0x8000) == 0 );
  }
  *(_WORD *)&ld12->ld12[10] = expn;
}

//------------------------------------------------------------------------------
// Address: 0x10019074
// Name: __87except
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _87except(int opcode, _exception *exc, unsigned __int16 *pcw16)
{
  unsigned int v3; // ecx
  bool v4; // zf
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // ebx
  unsigned int v12; // [esp+100h] [ebp-94h]
  unsigned int pcw; // [esp+110h] [ebp-84h] BYREF
  _FPIEEE_RECORD prec; // [esp+114h] [ebp-80h] BYREF

  v3 = *pcw16;
  v5 = exc->type - 1;
  v4 = exc->type == 1;
  pcw = v3;
  if ( v4 )
    goto LABEL_13;
  v6 = v5 - 1;
  if ( v6 == 0 )
  {
    v12 = 4;
    goto LABEL_14;
  }
  v7 = v6 - 1;
  if ( v7 == 0 )
  {
    v12 = 17;
    goto LABEL_14;
  }
  v8 = v7 - 1;
  if ( v8 == 0 )
  {
    v12 = 18;
    goto LABEL_14;
  }
  v9 = v8 - 1;
  if ( v9 == 0 )
  {
LABEL_13:
    v12 = 8;
LABEL_14:
    v11 = v12;
    if ( _handle_exc(flags: v12, presult: &exc->retval, cw: v3) == 0 )
    {
      if ( opcode == 16 || opcode == 22 || opcode == 29 )
      {
        prec.Operand2.Value.Fp64Value = exc->arg2;
        *((_DWORD *)&prec.Operand2 + 4) = *((_DWORD *)&prec.Operand2 + 4) & 0xFFFFFFE0 | 3;
      }
      else
      {
        *((_DWORD *)&prec.Operand2 + 4) &= ~1u;
      }
      _raise_exc(&prec, &pcw, flags: v11, opcode, parg1: &exc->arg1, presult: &exc->retval);
    }
    goto LABEL_21;
  }
  v10 = v9 - 2;
  if ( v10 == 0 )
  {
    exc->type = 1;
    goto LABEL_21;
  }
  if ( v10 == 1 )
  {
    v12 = 16;
    goto LABEL_14;
  }
LABEL_21:
  _ctrlfp(newctrl: pcw, _mask: 0xFFFFu);
  if ( exc->type == 8 || _matherr_flag != 0 || _matherr(pexcept: exc) == 0 )
    _set_errno_from_matherr(matherrtype: exc->type);
}

//------------------------------------------------------------------------------
// Address: 0x10019170
// Name: __frnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _frnd(long double x)
{
  return rint(x);
}

//------------------------------------------------------------------------------
// Address: 0x10019181
// Name: __fpclass
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fpclass(long double x)
{
  int v1; // eax
  int v2; // eax
  int v4; // ecx

  if ( (HIWORD(x) & 0x7FF0) == 0x7FF0 )
  {
    v1 = _sptype(x) - 1;
    if ( v1 != 0 )
    {
      v2 = v1 - 1;
      if ( v2 == 0 )
        return 4;
      if ( v2 != 1 )
        return 1;
      return 2;
    }
    else
    {
      return 512;
    }
  }
  else
  {
    v4 = HIWORD(x) & 0x8000;
    if ( (HIWORD(x) & 0x7FF0) == 0 && ((HIDWORD(x) & 0xFFFFF) != 0 || LODWORD(x) != 0) )
    {
      return (HIWORD(x) & 0x8000) != 0 ? 16 : 128;
    }
    else if ( 0.0 == x )
    {
      return v4 != 0 ? 32 : 64;
    }
    else
    {
      return v4 != 0 ? 8 : 256;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019215
// Name: __set_exp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _set_exp(long double x, __int16 exp)
{
  long double retval; // [esp+0h] [ebp-8h]

  retval = x;
  HIWORD(retval) = HIWORD(x) & 0x800F | (16 * (exp + 1022));
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1001923F
// Name: __sptype
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _sptype(long double x)
{
  if ( HIDWORD(x) == 2146435072 )
  {
    if ( LODWORD(x) == 0 )
      return 1;
  }
  else if ( x == -INFINITY )
  {
    return 2;
  }
  if ( (HIWORD(x) & 0x7FF8) == 0x7FF8 )
    return 3;
  if ( (HIWORD(x) & 0x7FF8) == 0x7FF0 && ((HIDWORD(x) & 0x7FFFF) != 0 || LODWORD(x) != 0) )
    return 4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1001929A
// Name: __decomp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
long double __cdecl _decomp(long double x, int *pexp)
{
  long double result; // st7
  int v3; // edx
  int v4; // edx
  BOOL v5; // eax

  result = 0.0;
  if ( 0.0 == x )
  {
    v3 = 0;
  }
  else if ( (HIWORD(x) & 0x7FF0) == 0 && ((HIDWORD(x) & 0xFFFFF) != 0 || LODWORD(x) != 0) )
  {
    v4 = -1021;
    v5 = x < 0.0;
    while ( (BYTE6(x) & 0x10) == 0 )
    {
      HIDWORD(x) *= 2;
      if ( SLODWORD(x) < 0 )
        HIDWORD(x) |= 1u;
      LODWORD(x) *= 2;
      --v4;
    }
    HIWORD(x) &= ~0x10u;
    if ( v5 )
      HIWORD(x) |= 0x8000u;
    result = _set_exp(x, exp: 0);
  }
  else
  {
    result = _set_exp(x, exp: 0);
    v3 = ((*(_DWORD *)((char *)&x + 6) >> 4) & 0x7FF) - 1022;
  }
  *pexp = v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10019350
// Name: __CIsin_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10019520
// Name: __CIcos_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100196D0
// Name: __CItan_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10019930
// Name: __matherr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _matherr()
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10019933
// Name: __raise_exc_ex
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _raise_exc_ex(
        _FPIEEE_RECORD *prec,
        unsigned int *pcw,
        DWORD flags,
        int opcode,
        float *parg1,
        float *presult,
        int isfloat)
{
  char v7; // cl
  unsigned int *v8; // esi
  char v9; // al
  int v10; // eax
  _FPIEEE_RECORD *v11; // eax
  unsigned int v12; // ecx
  int v13; // eax
  _FPIEEE_RECORD *v14; // eax
  unsigned int v15; // ecx
  float *v16; // edi
  _FPIEEE_RECORD *v17; // ecx
  int v18; // eax
  int v19; // eax
  int v20; // eax
  unsigned int v21; // eax
  int v22; // eax
  int v23; // eax
  unsigned int v24; // eax

  v7 = flags;
  prec->Cause = 0;
  prec->Enable = 0;
  prec->Status = 0;
  if ( (v7 & 0x10) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 1u;
    flags = -1073741681;
  }
  if ( (v7 & 2) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 2u;
    flags = -1073741677;
  }
  if ( (v7 & 1) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 4u;
    flags = -1073741679;
  }
  if ( (v7 & 4) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 8u;
    flags = -1073741682;
  }
  if ( (v7 & 8) != 0 )
  {
    *(_DWORD *)&prec->Cause |= 0x10u;
    flags = -1073741680;
  }
  v8 = pcw;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(16 * *pcw)) & 0x10;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(2 * *v8)) & 8;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(*v8 >> 1)) & 4;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(*v8 >> 3)) & 2;
  *(_DWORD *)&prec->Enable ^= (*(_DWORD *)&prec->Enable ^ ~(*v8 >> 5)) & 1;
  v9 = _statfp();
  if ( (v9 & 1) != 0 )
    *(_DWORD *)&prec->Status |= 0x10u;
  if ( (v9 & 4) != 0 )
    *(_DWORD *)&prec->Status |= 8u;
  if ( (v9 & 8) != 0 )
    *(_DWORD *)&prec->Status |= 4u;
  if ( (v9 & 0x10) != 0 )
    *(_DWORD *)&prec->Status |= 2u;
  if ( (v9 & 0x20) != 0 )
    *(_DWORD *)&prec->Status |= 1u;
  v10 = *v8 & 0xC00;
  switch ( v10 )
  {
    case 0:
      *(_DWORD *)prec &= 0xFFFFFFFC;
      break;
    case 1024:
      v11 = prec;
      v12 = *(_DWORD *)prec & 0xFFFFFFFC | 1;
      goto LABEL_27;
    case 2048:
      v11 = prec;
      v12 = *(_DWORD *)prec & 0xFFFFFFFC | 2;
LABEL_27:
      *(_DWORD *)v11 = v12;
      break;
    case 3072:
      *(_DWORD *)prec |= 3u;
      break;
    default:
      break;
  }
  v13 = *v8 & 0x300;
  switch ( v13 )
  {
    case 0:
      v14 = prec;
      v15 = *(_DWORD *)prec & 0xFFFFFFE3 | 8;
      goto LABEL_36;
    case 512:
      v14 = prec;
      v15 = *(_DWORD *)prec & 0xFFFFFFE3 | 4;
LABEL_36:
      *(_DWORD *)v14 = v15;
      break;
    case 768:
      *(_DWORD *)prec &= 0xFFFFFFE3;
      break;
    default:
      break;
  }
  *(_DWORD *)prec ^= (*(_DWORD *)prec ^ (32 * opcode)) & 0x1FFE0;
  *((_DWORD *)&prec->Operand1 + 4) |= 1u;
  v16 = presult;
  if ( isfloat != 0 )
  {
    *((_DWORD *)&prec->Operand1 + 4) &= 0xFFFFFFE1;
    prec->Operand1.Value.Fp32Value = *parg1;
    *((_DWORD *)&prec->Result + 4) |= 1u;
    *((_DWORD *)&prec->Result + 4) &= 0xFFFFFFE1;
    prec->Result.Value.Fp32Value = *v16;
  }
  else
  {
    *((_DWORD *)&prec->Operand1 + 4) = *((_DWORD *)&prec->Operand1 + 4) & 0xFFFFFFE1 | 2;
    prec->Operand1.Value.Fp64Value = *(double *)parg1;
    *((_DWORD *)&prec->Result + 4) |= 1u;
    *((_DWORD *)&prec->Result + 4) = *((_DWORD *)&prec->Result + 4) & 0xFFFFFFE1 | 2;
    prec->Result.Value.Fp64Value = *(double *)v16;
  }
  _clrfp();
  RaiseException(
    dwExceptionCode: flags,
    dwExceptionFlags: 0,
    nNumberOfArguments: 1u,
    lpArguments: (const ULONG_PTR *)&prec);
  v17 = prec;
  if ( (*(_BYTE *)&prec->Enable & 0x10) != 0 )
    *v8 &= ~1u;
  if ( (*(_BYTE *)&v17->Enable & 8) != 0 )
    *v8 &= ~4u;
  if ( (*(_BYTE *)&v17->Enable & 4) != 0 )
    *v8 &= ~8u;
  if ( (*(_BYTE *)&v17->Enable & 2) != 0 )
    *v8 &= ~0x10u;
  if ( (*(_BYTE *)&v17->Enable & 1) != 0 )
    *v8 &= ~0x20u;
  v18 = *(_DWORD *)v17 & 3;
  if ( v18 == 0 )
  {
    *v8 &= 0xFFFFF3FF;
    goto LABEL_59;
  }
  v19 = v18 - 1;
  if ( v19 == 0 )
  {
    v21 = *v8 & 0xFFFFF3FF | 0x400;
    goto LABEL_56;
  }
  v20 = v19 - 1;
  if ( v20 == 0 )
  {
    v21 = *v8 & 0xFFFFF3FF | 0x800;
LABEL_56:
    *v8 = v21;
    goto LABEL_59;
  }
  if ( v20 == 1 )
    *v8 |= 0xC00u;
LABEL_59:
  v22 = (*(_DWORD *)v17 >> 2) & 7;
  if ( v22 == 0 )
  {
    v24 = *v8 & 0xFFFFF0FF | 0x300;
    goto LABEL_65;
  }
  v23 = v22 - 1;
  if ( v23 == 0 )
  {
    v24 = *v8 & 0xFFFFF1FF | 0x200;
LABEL_65:
    *v8 = v24;
    goto LABEL_66;
  }
  if ( v23 == 1 )
    *v8 &= 0xFFFFF3FF;
LABEL_66:
  if ( isfloat != 0 )
    *v16 = v17->Result.Value.Fp32Value;
  else
    *(double *)v16 = v17->Result.Value.Fp64Value;
}

//------------------------------------------------------------------------------
// Address: 0x10019C0D
// Name: __raise_exc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _raise_exc(
        _FPIEEE_RECORD *prec,
        unsigned int *pcw,
        DWORD flags,
        int opcode,
        long double *parg1,
        long double *presult)
{
  _raise_exc_ex(prec, pcw, flags, opcode, (float *)parg1, (float *)presult, isfloat: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10019C2E
// Name: __handle_exc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _handle_exc(char flags, long double *presult, __int16 cw)
{
  int v3; // esi
  int v4; // eax
  double *v5; // ecx
  long double dbl; // st7
  BOOL v7; // esi
  int v8; // ecx
  double v9; // st7
  BOOL v10; // edx
  int v11; // eax
  double v13; // [esp+18h] [ebp-10h]
  int expn; // [esp+20h] [ebp-8h] BYREF
  int flags_p; // [esp+24h] [ebp-4h]

  v3 = flags & 0x1F;
  flags_p = v3;
  if ( (flags & 8) != 0 && (cw & 1) != 0 )
  {
    _set_statfp(sw: 1u);
    v3 = flags & 0x17;
    goto LABEL_46;
  }
  if ( (flags & 4) != 0 && (cw & 4) != 0 )
  {
    _set_statfp(sw: 4u);
    v3 = flags & 0x1B;
    goto LABEL_46;
  }
  if ( (flags & 1) != 0 && (cw & 8) != 0 )
  {
    _set_statfp(sw: 8u);
    v4 = cw & 0xC00;
    if ( (cw & 0xC00) != 0 )
    {
      if ( v4 != 1024 )
      {
        if ( v4 != 2048 )
        {
          if ( v4 != 3072 )
          {
LABEL_24:
            v3 = flags & 0x1E;
            goto LABEL_46;
          }
          v5 = presult;
          dbl = _d_max.dbl;
          if ( *presult <= 0.0 )
            goto LABEL_22;
LABEL_23:
          *v5 = dbl;
          goto LABEL_24;
        }
        v5 = presult;
        if ( *presult <= 0.0 )
        {
          dbl = _d_max.dbl;
LABEL_22:
          dbl = -dbl;
          goto LABEL_23;
        }
LABEL_20:
        dbl = _d_inf.dbl;
        goto LABEL_23;
      }
      v5 = presult;
      if ( *presult > 0.0 )
      {
        dbl = _d_max.dbl;
        goto LABEL_23;
      }
    }
    else
    {
      v5 = presult;
      if ( *presult > 0.0 )
        goto LABEL_20;
    }
    dbl = _d_inf.dbl;
    goto LABEL_22;
  }
  if ( (flags & 2) != 0 && (cw & 0x10) != 0 )
  {
    v7 = (flags & 0x10) != 0;
    if ( 0.0 == *presult )
    {
      v7 = true;
      goto LABEL_43;
    }
    v13 = _decomp(x: *presult, pexp: &expn);
    v8 = expn - 1536;
    if ( expn - 1536 >= -1074 )
    {
      v10 = v13 < 0.0;
      HIWORD(v13) = BYTE6(v13) & 0xF | 0x10;
      if ( v8 < -1021 )
      {
        v11 = -1021 - v8;
        do
        {
          if ( (LOBYTE(v13) & 1) != 0 && !v7 )
            v7 = true;
          LODWORD(v13) >>= 1;
          if ( (BYTE4(v13) & 1) != 0 )
            LODWORD(v13) |= 0x80000000;
          HIDWORD(v13) >>= 1;
          --v11;
        }
        while ( v11 != 0 );
      }
      if ( !v10 )
        goto LABEL_41;
      v9 = -v13;
    }
    else
    {
      v7 = true;
      v9 = v13 * 0.0;
    }
    v13 = v9;
LABEL_41:
    *presult = v13;
LABEL_43:
    if ( v7 )
      _set_statfp(sw: 0x10u);
    flags_p &= ~2u;
    v3 = flags_p;
  }
LABEL_46:
  if ( (flags & 0x10) != 0 && (cw & 0x20) != 0 )
  {
    _set_statfp(sw: 0x20u);
    v3 &= ~0x10u;
  }
  return v3 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10019E0F
// Name: __set_errno_from_matherr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _set_errno_from_matherr(int matherrtype)
{
  if ( matherrtype == 1 )
  {
    *_errno() = 33;
  }
  else if ( matherrtype > 1 && matherrtype <= 3 )
  {
    *_errno() = 34;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019E37
// Name: __errcode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _errcode(char flags)
{
  if ( (flags & 0x20) != 0 )
    return 5;
  if ( (flags & 8) != 0 )
    return 1;
  if ( (flags & 4) != 0 )
    return 2;
  if ( (flags & 1) != 0 )
    return 3;
  return 2 * (flags & 2);
}

//------------------------------------------------------------------------------
// Address: 0x10019E64
// Name: __umatherr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _umatherr(
        int type,
        unsigned int opcode,
        long double arg1,
        long double arg2,
        long double retval,
        unsigned int cw)
{
  int v6; // eax
  char *v7; // eax

  v6 = 0;
  while ( dword_10039188[2 * v6] != opcode )
  {
    if ( ++v6 >= 29 )
    {
      v7 = nullptr;
      goto LABEL_5;
    }
  }
  v7 = (&off_1003918C)[2 * v6];
LABEL_5:
  if ( v7 != nullptr )
  {
    _ctrlfp(newctrl: cw, _mask: 0xFFFFu);
    if ( _matherr() == 0 )
      _set_errno_from_matherr(matherrtype: type);
    return retval;
  }
  else
  {
    _ctrlfp(newctrl: cw, _mask: 0xFFFFu);
    _set_errno_from_matherr(matherrtype: type);
    return retval;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10019F02
// Name: __handle_qnan1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _handle_qnan1(unsigned int opcode, long double x, unsigned int savedcw)
{
  if ( _matherr_flag == 0 )
    return _umatherr(type: 1, opcode, arg1: x, arg2: 0.0, retval: x, cw: savedcw);
  *_errno() = 33;
  _ctrlfp(newctrl: savedcw, _mask: 0xFFFFu);
  return x;
}

//------------------------------------------------------------------------------
// Address: 0x10019F55
// Name: __except1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _except1(int flags, int opcode, long double arg, long double result, unsigned int cw)
{
  int v5; // eax
  _FPIEEE_RECORD prec; // [esp+80h] [ebp-80h] BYREF

  if ( !_handle_exc(flags, presult: &result, cw) )
  {
    *((_DWORD *)&prec.Operand2 + 4) &= ~1u;
    _raise_exc_ex(&prec, pcw: &cw, flags, opcode, parg1: (float *)&arg, presult: (float *)&result, isfloat: 0);
  }
  v5 = _errcode(flags);
  if ( _matherr_flag == 0 && v5 != 0 )
    return _umatherr(type: v5, opcode, arg1: arg, arg2: 0.0, retval: result, cw);
  _set_errno_from_matherr(matherrtype: v5);
  _ctrlfp(newctrl: cw, _mask: 0xFFFFu);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001A00F
// Name: __statfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _statfp@<eax>(__int16 a1@<fpstat>)
{
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x1001A01A
// Name: __clrfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _clrfp@<eax>(__int16 a1@<fpstat>)
{
  __asm { fnclex }
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x1001A026
// Name: __ctrlfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _ctrlfp()
{
  __int16 oldCw; // [esp+0h] [ebp-4h]

  return oldCw;
}

//------------------------------------------------------------------------------
// Address: 0x1001A04D
// Name: __set_statfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _set_statfp()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x1001A0A3
// Name: ___set_fpsr_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __set_fpsr_sse2(unsigned int newMXCSR)
{
  if ( __sse2_available != 0 )
  {
    if ( (newMXCSR & 0x40) != 0 && _DAZ_ENABLED != 0 )
      _mm_setcsr(newMXCSR);
    else
      _mm_setcsr(newMXCSR & 0xFFFFFFBF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A115
// Name: __free_osfhnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _free_osfhnd(int fh)
{
  ioinfo **v1; // edi
  int v2; // esi
  _DWORD *v3; // eax

  if ( fh < 0
    || fh >= _nhandle
    || (v1 = &__pioinfo[fh >> 5], v2 = (fh & 0x1F) << 6, ((v3 = (int *)((char *)&(*v1)->osfhnd + v2))[1] & 1) == 0)
    || *v3 == -1 )
  {
    *_errno() = 9;
    *__doserrno() = 0;
    return -1;
  }
  else
  {
    if ( __app_type == 1 )
    {
      if ( fh != 0 )
      {
        if ( fh == 1 )
        {
          SetStdHandle(nStdHandle: 0xFFFFFFF5, hHandle: nullptr);
        }
        else if ( fh == 2 )
        {
          SetStdHandle(nStdHandle: 0xFFFFFFF4, hHandle: nullptr);
        }
      }
      else
      {
        SetStdHandle(nStdHandle: 0xFFFFFFF6, hHandle: nullptr);
      }
    }
    *(int *)((char *)&(*v1)->osfhnd + v2) = -1;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A196
// Name: __get_osfhandle
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _get_osfhandle@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, int fh)
{
  ioinfo *v4; // eax

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  else if ( fh >= 0 && fh < _nhandle && ((v4 = &__pioinfo[fh >> 5][fh & 0x1F])->osfile & 1) != 0 )
  {
    return v4->osfhnd;
  }
  else
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter(a1, a2, a3: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001A207
// Name: ___lock_fhandle
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl __lock_fhandle(int fh)
{
  ioinfo *v1; // esi
  BOOL retval; // [esp+10h] [ebp-1Ch]

  v1 = &__pioinfo[fh >> 5][fh & 0x1F];
  retval = true;
  if ( v1->lockinitflag == 0 )
  {
    _lock(locknum: 10);
    if ( v1->lockinitflag == 0 )
    {
      retval = __crtInitCritSecAndSpinCount(a1: 0, lpCriticalSection: &v1->lock, dwSpinCount: 0xFA0u);
      ++v1->lockinitflag;
    }
    _unlock(locknum: 10);
  }
  if ( retval )
    EnterCriticalSection(lpCriticalSection: &__pioinfo[fh >> 5][fh & 0x1F].lock);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1001A2A7
// Name: __unlock_fhandle
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_fhandle(int fh)
{
  LeaveCriticalSection(lpCriticalSection: &__pioinfo[fh >> 5][fh & 0x1F].lock);
}

//------------------------------------------------------------------------------
// Address: 0x1001A2C9
// Name: __putwch_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
wchar_t __cdecl _putwch_nolock(wchar_t ch)
{
  UINT ConsoleOutputCP; // eax
  DWORD v3; // eax
  int num_written; // [esp+4h] [ebp-10h] BYREF
  char mbc[8]; // [esp+8h] [ebp-Ch] BYREF

  if ( use_w == 0 )
    goto LABEL_10;
  if ( _confh == (HANDLE)-2 )
    __initconout();
  if ( _confh == (HANDLE)-1 )
    return -1;
  if ( !WriteConsoleW(
          hConsoleOutput: _confh,
          lpBuffer: &ch,
          nNumberOfCharsToWrite: 1u,
          lpNumberOfCharsWritten: (LPDWORD)&num_written,
          lpReserved: nullptr) )
  {
    if ( use_w != 2 || GetLastError() != 120 )
      return -1;
    use_w = 0;
LABEL_10:
    ConsoleOutputCP = GetConsoleOutputCP();
    v3 = WideCharToMultiByte(
           CodePage: ConsoleOutputCP,
           dwFlags: 0,
           lpWideCharStr: &ch,
           cchWideChar: 1,
           lpMultiByteStr: mbc,
           cbMultiByte: 5,
           lpDefaultChar: nullptr,
           lpUsedDefaultChar: nullptr);
    if ( _confh != (HANDLE)-1
      && WriteConsoleA(
           hConsoleOutput: _confh,
           lpBuffer: mbc,
           nNumberOfCharsToWrite: v3,
           lpNumberOfCharsWritten: (LPDWORD)&num_written,
           lpReserved: nullptr) )
    {
      return ch;
    }
    return -1;
  }
  use_w = 1;
  return ch;
}

//------------------------------------------------------------------------------
// Address: 0x1001A38B
// Name: __fcloseall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fcloseall()
{
  int i; // edi
  int v1; // esi
  void **v2; // eax
  _iobuf *v3; // eax
  int count; // [esp+14h] [ebp-1Ch]

  count = 0;
  _lock(locknum: 1);
  for ( i = 3; i < (int)_nstream; ++i )
  {
    v1 = i;
    v2 = &__piob[i];
    if ( *v2 != nullptr )
    {
      v3 = (_iobuf *)*v2;
      if ( (v3->_flag & 0x83) != 0 && fclose(stream: v3) != -1 )
        ++count;
      if ( i >= 20 )
      {
        DeleteCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)__piob[v1] + 32));
        free(pMem: __piob[v1]);
        __piob[v1] = nullptr;
      }
    }
  }
  _unlock(locknum: 1);
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x1001A42A
// Name: __flush
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flush(_iobuf *str)
{
  int flag; // eax
  int v2; // ebx
  char *base; // eax
  char *v4; // edi
  int v5; // eax
  int v6; // eax
  char *v7; // eax
  char *v9; // [esp-Ch] [ebp-14h]
  char *v10; // [esp-8h] [ebp-10h]

  flag = str->_flag;
  v2 = 0;
  if ( (flag & 3) == 2 && (flag & 0x108) != 0 )
  {
    base = str->_base;
    v4 = (char *)(str->_ptr - base);
    if ( (int)v4 > 0 )
    {
      v10 = (char *)(str->_ptr - base);
      v9 = str->_base;
      v5 = _fileno(a1: 0, a2: (unsigned int)v4, stream: str);
      if ( (char *)_write(a1: nullptr, a2: (unsigned int)str, fh: v5, buf: v9, cnt: (DWORD)v10) == v4 )
      {
        v6 = str->_flag;
        if ( (v6 & 0x80u) != 0 )
          str->_flag = v6 & 0xFFFFFFFD;
      }
      else
      {
        str->_flag |= 0x20u;
        v2 = -1;
      }
    }
  }
  v7 = str->_base;
  str->_cnt = 0;
  str->_ptr = v7;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1001A48C
// Name: __fflush_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _fflush_nolock@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>, _iobuf *str)
{
  int v4; // eax

  if ( str == nullptr )
    return flsall(flushflag: 0);
  if ( _flush(str) != 0 )
    return -1;
  if ( (str->_flag & 0x4000) == 0 )
    return 0;
  v4 = _fileno(a1, a2, stream: str);
  return -(_commit(filedes: v4) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x1001A4CE
// Name: flsall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall flsall@<eax>(unsigned int a1@<ebx>, int flushflag)
{
  int i; // esi
  char **v3; // eax
  char *v4; // eax
  int v5; // ecx
  int result; // eax
  int err; // [esp+10h] [ebp-24h]
  int count; // [esp+18h] [ebp-1Ch]

  count = 0;
  err = 0;
  _lock(locknum: 1);
  for ( i = 0; i < (int)_nstream; ++i )
  {
    v3 = (char **)&__piob[i];
    if ( *v3 != nullptr )
    {
      v4 = *v3;
      if ( (v4[12] & 0x83) != 0 )
      {
        _lock_file2(i, s: v4);
        v5 = *((_DWORD *)__piob[i] + 3);
        if ( (v5 & 0x83) != 0 )
        {
          if ( flushflag == 1 )
          {
            if ( _fflush_nolock(a1, a2: 0, str: (_iobuf *)__piob[i]) != -1 )
              ++count;
          }
          else if ( flushflag == 0 && (v5 & 2) != 0 && _fflush_nolock(a1, a2: 0, str: (_iobuf *)__piob[i]) == -1 )
          {
            err = -1;
          }
        }
        _unlock_file2(i, s: (char *)__piob[i]);
      }
    }
  }
  _unlock(locknum: 1);
  result = count;
  if ( flushflag != 1 )
    return err;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001A5A8
// Name: __flushall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _flushall@<eax>(unsigned int a1@<ebx>)
{
  return flsall(a1, flushflag: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1001A5B1
// Name: _$I10_OUTPUT
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _I10_OUTPUT(_LDOUBLE ld, int ndigits, char output_flags, _FloatOutStruct *fos)
{
  __int16 v4; // cx
  unsigned __int16 v5; // dx
  int v6; // esi
  unsigned int v7; // edi
  unsigned int v9; // eax
  unsigned int v10; // edx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // ecx
  int v15; // ebx
  int v16; // ecx
  _LDBL12 *v17; // ecx
  __int16 v18; // di
  __int16 v19; // cx
  unsigned __int16 v20; // di
  __int16 v21; // cx
  unsigned __int16 v22; // ax
  _BYTE *v23; // edi
  unsigned int v24; // edi
  unsigned int v25; // edx
  unsigned int v26; // esi
  __int16 v27; // ax
  unsigned int v28; // edx
  int v29; // edi
  int v30; // edx
  int v31; // edx
  int v32; // edi
  int v33; // edx
  bool v34; // zf
  __int16 v35; // cx
  unsigned __int16 v36; // di
  _WORD *v37; // eax
  unsigned int v38; // edx
  unsigned int v39; // esi
  unsigned int v40; // ebx
  __int16 v41; // di
  unsigned int v42; // edx
  int v43; // ebx
  int v44; // edx
  int v45; // eax
  int v46; // edx
  int v47; // ebx
  int v48; // edx
  int v49; // esi
  int k; // ebx
  unsigned int v51; // eax
  int v52; // edi
  int v53; // eax
  int v54; // esi
  int v55; // eax
  int v56; // edi
  int v57; // eax
  char *man; // ebx
  unsigned int v59; // edx
  unsigned int v60; // edi
  unsigned int v61; // ecx
  int v62; // esi
  int v63; // ecx
  unsigned int v64; // esi
  unsigned int v65; // edi
  int v66; // edx
  unsigned int v67; // edx
  char *v68; // ebx
  char v69; // al
  char *v70; // ebx
  _FloatOutStruct *v71; // eax
  char v72; // bl
  int v73; // [esp+10h] [ebp-70h]
  __int16 sign; // [esp+14h] [ebp-6Ch]
  _LDBL12 *v75; // [esp+18h] [ebp-68h]
  _LDBL12 *p_tmp12; // [esp+1Ch] [ebp-64h]
  int v77; // [esp+24h] [ebp-5Ch]
  unsigned __int8 *v78; // [esp+24h] [ebp-5Ch]
  unsigned __int8 *v79; // [esp+28h] [ebp-58h]
  int v80; // [esp+28h] [ebp-58h]
  unsigned __int8 *v81; // [esp+2Ch] [ebp-54h]
  int v82; // [esp+2Ch] [ebp-54h]
  int v83; // [esp+30h] [ebp-50h]
  int v84; // [esp+30h] [ebp-50h]
  __int16 digcount; // [esp+34h] [ebp-4Ch]
  int digcounta; // [esp+34h] [ebp-4Ch]
  int v87; // [esp+38h] [ebp-48h]
  unsigned __int8 *v88; // [esp+38h] [ebp-48h]
  _WORD *v89; // [esp+3Ch] [ebp-44h]
  int v90; // [esp+3Ch] [ebp-44h]
  int v91; // [esp+3Ch] [ebp-44h]
  unsigned int v92; // [esp+3Ch] [ebp-44h]
  int i; // [esp+40h] [ebp-40h]
  int j; // [esp+40h] [ebp-40h]
  char *v95; // [esp+40h] [ebp-40h]
  _LDBL12 tmp12; // [esp+44h] [ebp-3Ch] BYREF
  _LDBL12 ld12_one_tenth; // [esp+50h] [ebp-30h] BYREF
  _LDBL12 ld12; // [esp+60h] [ebp-20h] BYREF
  _BYTE v99[12]; // [esp+70h] [ebp-10h] BYREF

  *(_LDOUBLE *)v99 = ld;
  v4 = *(_WORD *)&ld.ld[8] & 0x8000;
  v5 = *(_WORD *)&ld.ld[8] & 0x7FFF;
  memset(&ld12_one_tenth, 204, 10);
  ld12_one_tenth.ld12[10] = -5;
  ld12_one_tenth.ld12[11] = 63;
  sign = *(_WORD *)&ld.ld[8] & 0x8000;
  if ( *(__int16 *)&ld.ld[8] >= 0 )
    fos->sign = 32;
  else
    fos->sign = 45;
  v6 = *(_DWORD *)&v99[4];
  v7 = *(_DWORD *)v99;
  if ( v5 == 0 && *(_DWORD *)&v99[4] == 0 && *(_DWORD *)v99 == 0 )
  {
    fos->exp = 0;
    fos->sign = v4 != -32768 ? 32 : 45;
    fos->ManLen = 1;
    fos->man[0] = 48;
    fos->man[1] = 0;
    return 1;
  }
  if ( v5 == 0x7FFF )
  {
    fos->exp = 1;
    if ( (v6 != 0x80000000 || v7 != 0) && (v6 & 0x40000000) == 0 )
    {
      v9 = strcpy_s(a1: v7, _Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#SNAN");
LABEL_25:
      if ( v9 != 0 )
        _invoke_watson(a1: v9, a2: v10, a3: v11, a4: (unsigned int)fos, a5: v7, a6: 0);
      fos->ManLen = 6;
      return 0;
    }
    if ( v4 != 0 && v6 == -1073741824 )
    {
      if ( v7 == 0 )
      {
        v12 = strcpy_s(a1: 0, _Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#IND");
LABEL_21:
        if ( v12 != 0 )
          _invoke_watson(a1: v12, a2: v13, a3: v14, a4: (unsigned int)fos, a5: 0, a6: 0);
        fos->ManLen = 5;
        return 0;
      }
    }
    else if ( v6 == 0x80000000 && v7 == 0 )
    {
      v12 = strcpy_s(a1: 0, _Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#INF");
      goto LABEL_21;
    }
    v9 = strcpy_s(a1: v7, _Dst: fos->man, _SizeInBytes: 0x16u, _Src: "1#QNAN");
    goto LABEL_25;
  }
  digcount = (77 * (HIBYTE(v5) + 2 * HIBYTE(*(_DWORD *)&v99[4])) + 19728 * (unsigned int)v5 - 323162868) >> 16;
  v15 = -digcount;
  *(_WORD *)&ld12.ld12[10] = *(_WORD *)&ld.ld[8] & 0x7FFF;
  *(_DWORD *)&ld12.ld12[6] = *(_DWORD *)&v99[4];
  *(_DWORD *)&ld12.ld12[2] = *(_DWORD *)v99;
  *(_WORD *)ld12.ld12 = 0;
  v75 = &_pow10pos[-8];
  if ( digcount != 0 )
  {
    if ( (__int16)((77 * (HIBYTE(v5) + 2 * HIBYTE(*(_DWORD *)&v99[4])) + 19728 * (unsigned int)v5 - 323162868) >> 16) > 0 )
    {
      v15 = (__int16)((77 * (HIBYTE(v5) + 2 * HIBYTE(*(_DWORD *)&v99[4])) + 19728 * (unsigned int)v5 - 323162868) >> 16);
      v75 = &_pow10neg[-8];
    }
    while ( v15 != 0 )
    {
      v75 += 7;
      v16 = v15 & 7;
      v15 >>= 3;
      if ( v16 != 0 )
      {
        v17 = &v75[v16];
        p_tmp12 = v17;
        if ( *(_WORD *)v17->ld12 >= 0x8000u )
        {
          tmp12 = *v17;
          --*(_DWORD *)&tmp12.ld12[2];
          p_tmp12 = &tmp12;
          v17 = &tmp12;
        }
        v18 = *(_WORD *)&v17->ld12[10];
        v19 = *(_WORD *)&ld12.ld12[10] ^ v18;
        v20 = v18 & 0x7FFF;
        v87 = 0;
        memset(v99, 0, sizeof(v99));
        v21 = v19 & 0x8000;
        v22 = v20 + (*(_WORD *)&ld12.ld12[10] & 0x7FFF);
        if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0x7FFF || v20 >= 0x7FFFu || v22 > 0xBFFDu )
        {
LABEL_81:
          *(_DWORD *)&ld12.ld12[4] = 0;
          *(_DWORD *)ld12.ld12 = 0;
          *(_DWORD *)&ld12.ld12[8] = v21 != 0 ? -32768 : 2147450880;
          continue;
        }
        if ( v22 <= 0x3FBFu )
          goto LABEL_40;
        if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0 )
        {
          ++v22;
          if ( (*(_DWORD *)&ld12.ld12[8] & 0x7FFFFFFF) == 0
            && *(_DWORD *)&ld12.ld12[4] == 0
            && *(_DWORD *)ld12.ld12 == 0 )
          {
            *(_WORD *)&ld12.ld12[10] = 0;
            continue;
          }
        }
        if ( v20 != 0
          || (++v22, (*(_DWORD *)&p_tmp12->ld12[8] & 0x7FFFFFFF) != 0)
          || *(_DWORD *)&p_tmp12->ld12[4] != 0
          || *(_DWORD *)p_tmp12->ld12 != 0 )
        {
          v23 = &v99[4];
          v77 = 0;
          v89 = &v99[4];
          for ( i = 5; i > 0; --i )
          {
            v83 = i;
            v79 = &ld12.ld12[2 * v77];
            v81 = &p_tmp12->ld12[8];
            do
            {
              v24 = *((_DWORD *)v23 - 1);
              v25 = *(unsigned __int16 *)v81 * *(unsigned __int16 *)v79;
              v73 = 0;
              v26 = v24 + v25;
              if ( v24 + v25 < v24 || v26 < v25 )
                v73 = 1;
              v23 = v89;
              *((_DWORD *)v89 - 1) = v26;
              if ( v73 != 0 )
                ++*v89;
              v79 += 2;
              v81 -= 2;
              --v83;
            }
            while ( v83 > 0 );
            v23 = v89 + 1;
            ++v77;
            ++v89;
          }
          v27 = v22 - 16382;
          if ( v27 <= 0 )
            goto LABEL_170;
          do
          {
            if ( *(int *)&v99[8] < 0 )
              break;
            v28 = *(_DWORD *)v99;
            *(_DWORD *)v99 *= 2;
            v29 = (v28 >> 31) | (2 * *(_DWORD *)&v99[4]);
            v30 = *(__int64 *)&v99[4] >> 31;
            --v27;
            *(_DWORD *)&v99[4] = v29;
            *(_DWORD *)&v99[8] = v30;
          }
          while ( v27 > 0 );
          if ( v27 <= 0 )
          {
LABEL_170:
            if ( --v27 < 0 )
            {
              v90 = (unsigned __int16)-v27;
              v27 = 0;
              do
              {
                if ( (v99[0] & 1) != 0 )
                  ++v87;
                v31 = *(_DWORD *)&v99[8];
                *(_DWORD *)&v99[8] >>= 1;
                v32 = (v31 << 31) | (*(_DWORD *)&v99[4] >> 1);
                v33 = *(__int64 *)v99 >> 1;
                v34 = v90-- == 1;
                *(_DWORD *)&v99[4] = v32;
                *(_DWORD *)v99 = v33;
              }
              while ( !v34 );
              if ( v87 != 0 )
                *(_WORD *)v99 |= 1u;
            }
          }
          if ( *(_WORD *)v99 > 0x8000u || (*(_DWORD *)v99 & 0x1FFFF) == 0x18000 )
          {
            if ( *(_DWORD *)&v99[2] == -1 )
            {
              *(_DWORD *)&v99[2] = 0;
              if ( *(_DWORD *)&v99[6] == -1 )
              {
                *(_DWORD *)&v99[6] = 0;
                if ( *(_WORD *)&v99[10] == 0xFFFF )
                {
                  *(_WORD *)&v99[10] = 0x8000;
                  ++v27;
                }
                else
                {
                  ++*(_WORD *)&v99[10];
                }
              }
              else
              {
                ++*(_DWORD *)&v99[6];
              }
            }
            else
            {
              ++*(_DWORD *)&v99[2];
            }
          }
          if ( (unsigned __int16)v27 >= 0x7FFFu )
            goto LABEL_81;
          *(_WORD *)ld12.ld12 = *(_WORD *)&v99[2];
          *(_QWORD *)&ld12.ld12[2] = *(_QWORD *)&v99[4];
          *(_WORD *)&ld12.ld12[10] = v21 | v27;
        }
        else
        {
LABEL_40:
          memset(&ld12, 0, sizeof(ld12));
        }
      }
    }
  }
  if ( *(_WORD *)&ld12.ld12[10] >= 0x3FFFu )
  {
    ++digcount;
    v35 = (*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&ld12_one_tenth.ld12[10]) & 0x8000;
    v80 = 0;
    memset(v99, 0, sizeof(v99));
    v36 = (*(_WORD *)&ld12_one_tenth.ld12[10] & 0x7FFF) + (*(_WORD *)&ld12.ld12[10] & 0x7FFF);
    if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0x7FFF
      || (*(_WORD *)&ld12_one_tenth.ld12[10] & 0x7FFF) == 0x7FFF
      || v36 > 0xBFFDu )
    {
      *(_DWORD *)&ld12.ld12[8] = ((*(_WORD *)&ld12.ld12[10] ^ *(_WORD *)&ld12_one_tenth.ld12[10]) & 0x8000u) != 0
                               ? -32768
                               : 2147450880;
    }
    else
    {
      if ( v36 > 0x3FBFu )
      {
        if ( (*(_WORD *)&ld12.ld12[10] & 0x7FFF) == 0 )
        {
          ++v36;
          if ( (*(_DWORD *)&ld12.ld12[8] & 0x7FFFFFFF) == 0
            && *(_DWORD *)&ld12.ld12[4] == 0
            && *(_DWORD *)ld12.ld12 == 0 )
          {
            *(_WORD *)&ld12.ld12[10] = 0;
            goto LABEL_132;
          }
        }
        if ( (*(_WORD *)&ld12_one_tenth.ld12[10] & 0x7FFF) != 0
          || (++v36, (*(_DWORD *)&ld12_one_tenth.ld12[8] & 0x7FFFFFFF) != 0)
          || *(_DWORD *)&ld12_one_tenth.ld12[4] != 0
          || *(_DWORD *)ld12_one_tenth.ld12 != 0 )
        {
          v82 = 0;
          v37 = &v99[4];
          for ( j = 5; j > 0; --j )
          {
            v84 = j;
            v78 = &ld12_one_tenth.ld12[8];
            v88 = &ld12.ld12[2 * v82];
            do
            {
              v91 = 0;
              v38 = *(unsigned __int16 *)v88 * *(unsigned __int16 *)v78;
              v39 = *((_DWORD *)v37 - 1);
              v40 = v39 + v38;
              if ( v39 + v38 < v39 || v40 < v38 )
                v91 = 1;
              *((_DWORD *)v37 - 1) = v40;
              if ( v91 != 0 )
                ++*v37;
              v88 += 2;
              v78 -= 2;
              --v84;
            }
            while ( v84 > 0 );
            ++v37;
            ++v82;
          }
          v41 = v36 - 16382;
          if ( v41 <= 0 )
            goto LABEL_171;
          do
          {
            if ( *(int *)&v99[8] < 0 )
              break;
            v42 = *(_DWORD *)v99;
            *(_DWORD *)v99 *= 2;
            v43 = (v42 >> 31) | (2 * *(_DWORD *)&v99[4]);
            v44 = *(__int64 *)&v99[4] >> 31;
            --v41;
            *(_DWORD *)&v99[4] = v43;
            *(_DWORD *)&v99[8] = v44;
          }
          while ( v41 > 0 );
          if ( v41 <= 0 )
          {
LABEL_171:
            if ( --v41 < 0 )
            {
              v45 = (unsigned __int16)-v41;
              v41 = 0;
              do
              {
                if ( (v99[0] & 1) != 0 )
                  ++v80;
                v46 = *(_DWORD *)&v99[8];
                *(_DWORD *)&v99[8] >>= 1;
                v47 = (v46 << 31) | (*(_DWORD *)&v99[4] >> 1);
                v48 = *(__int64 *)v99 >> 1;
                --v45;
                *(_DWORD *)&v99[4] = v47;
                *(_DWORD *)v99 = v48;
              }
              while ( v45 != 0 );
              if ( v80 != 0 )
                *(_WORD *)v99 |= 1u;
            }
          }
          if ( *(_WORD *)v99 > 0x8000u || (*(_DWORD *)v99 & 0x1FFFF) == 0x18000 )
          {
            if ( *(_DWORD *)&v99[2] == -1 )
            {
              *(_DWORD *)&v99[2] = 0;
              if ( *(_DWORD *)&v99[6] == -1 )
              {
                *(_DWORD *)&v99[6] = 0;
                if ( *(_WORD *)&v99[10] == 0xFFFF )
                {
                  *(_WORD *)&v99[10] = 0x8000;
                  ++v41;
                }
                else
                {
                  ++*(_WORD *)&v99[10];
                }
              }
              else
              {
                ++*(_DWORD *)&v99[6];
              }
            }
            else
            {
              ++*(_DWORD *)&v99[2];
            }
          }
          if ( (unsigned __int16)v41 < 0x7FFFu )
          {
            *(_WORD *)ld12.ld12 = *(_WORD *)&v99[2];
            *(_QWORD *)&ld12.ld12[2] = *(_QWORD *)&v99[4];
            *(_WORD *)&ld12.ld12[10] = v35 | v41;
          }
          else
          {
            *(_DWORD *)&ld12.ld12[4] = 0;
            *(_DWORD *)ld12.ld12 = 0;
            *(_DWORD *)&ld12.ld12[8] = v35 != 0 ? -32768 : 2147450880;
          }
          goto LABEL_132;
        }
      }
      *(_DWORD *)&ld12.ld12[8] = 0;
    }
    *(_DWORD *)&ld12.ld12[4] = 0;
    *(_DWORD *)ld12.ld12 = 0;
  }
LABEL_132:
  fos->exp = digcount;
  if ( (output_flags & 1) != 0 )
  {
    ndigits += digcount;
    if ( ndigits <= 0 )
    {
      fos->exp = 0;
      fos->ManLen = 1;
      fos->sign = sign != (__int16)0x8000 ? 32 : 45;
      fos->man[0] = 48;
      fos->man[1] = 0;
      return 1;
    }
  }
  if ( ndigits > 21 )
    ndigits = 21;
  v49 = *(unsigned __int16 *)&ld12.ld12[10] - 16382;
  *(_WORD *)&ld12.ld12[10] = 0;
  for ( k = 8; k != 0; --k )
  {
    v51 = *(_DWORD *)ld12.ld12;
    *(_DWORD *)ld12.ld12 *= 2;
    v52 = (v51 >> 31) | (2 * *(_DWORD *)&ld12.ld12[4]);
    v53 = *(__int64 *)&ld12.ld12[4] >> 31;
    *(_DWORD *)&ld12.ld12[4] = v52;
    *(_DWORD *)&ld12.ld12[8] = v53;
  }
  if ( v49 < 0 )
  {
    v54 = (unsigned __int8)-(char)v49;
    if ( v54 != 0 )
    {
      do
      {
        v55 = *(_DWORD *)&ld12.ld12[8];
        *(_DWORD *)&ld12.ld12[8] >>= 1;
        v56 = (v55 << 31) | (*(_DWORD *)&ld12.ld12[4] >> 1);
        v57 = *(__int64 *)ld12.ld12 >> 1;
        --v54;
        *(_DWORD *)&ld12.ld12[4] = v56;
        *(_DWORD *)ld12.ld12 = v57;
      }
      while ( v54 > 0 );
    }
  }
  man = fos->man;
  v95 = fos->man;
  for ( digcounta = ndigits + 1; digcounta > 0; ld12.ld12[11] = 0 )
  {
    v59 = *(_DWORD *)ld12.ld12;
    tmp12 = ld12;
    *(_DWORD *)ld12.ld12 *= 2;
    v60 = *(_DWORD *)ld12.ld12;
    *(_DWORD *)ld12.ld12 *= 2;
    v61 = (v59 >> 31) | (2 * *(_DWORD *)&ld12.ld12[4]);
    v62 = 2 * v61;
    v63 = (v61 >> 31) | (2 * (*(__int64 *)&ld12.ld12[4] >> 31));
    v64 = (v60 >> 31) | v62;
    v65 = *(_DWORD *)tmp12.ld12 + *(_DWORD *)ld12.ld12;
    if ( (unsigned int)(*(_DWORD *)tmp12.ld12 + *(_DWORD *)ld12.ld12) < *(_DWORD *)ld12.ld12
      || v65 < *(_DWORD *)tmp12.ld12 )
    {
      v66 = 0;
      if ( v64 + 1 < v64 || v64 == -1 )
        v66 = 1;
      ++v64;
      if ( v66 != 0 )
        ++v63;
    }
    v67 = *(_DWORD *)&tmp12.ld12[4] + v64;
    v92 = *(_DWORD *)&tmp12.ld12[4] + v64;
    if ( *(_DWORD *)&tmp12.ld12[4] + v64 < v64 || v67 < *(_DWORD *)&tmp12.ld12[4] )
      ++v63;
    *(_DWORD *)ld12.ld12 = 2 * v65;
    *(_DWORD *)&ld12.ld12[8] = (v67 >> 31) | (2 * (*(_DWORD *)&tmp12.ld12[8] + v63));
    *man++ = ld12.ld12[11] + 48;
    --digcounta;
    *(_DWORD *)&ld12.ld12[4] = (v65 >> 31) | (2 * v92);
  }
  v68 = man - 1;
  v69 = *v68;
  v70 = v68 - 1;
  if ( v69 >= 53 )
  {
    while ( v70 >= v95 && *v70 == 57 )
      *v70-- = 48;
    v71 = fos;
    if ( v70 < v95 )
    {
      ++v70;
      ++fos->exp;
    }
    ++*v70;
  }
  else
  {
    while ( v70 >= v95 && *v70 == 48 )
      --v70;
    v71 = fos;
    if ( v70 < v95 )
    {
      fos->exp = 0;
      fos->ManLen = 1;
      fos->sign = sign != (__int16)0x8000 ? 32 : 45;
      *v95 = 48;
      fos->man[1] = 0;
      return 1;
    }
  }
  v72 = (_BYTE)v70 - (_BYTE)v71 - 3;
  v71->ManLen = v72;
  v71->man[v72] = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001AE77
// Name: _hw_cw
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall hw_cw@<eax>(unsigned int abstr@<ebx>)
{
  int result; // eax
  unsigned int v2; // ecx

  result = (abstr & 0x10) != 0;
  if ( (abstr & 8) != 0 )
    result |= 4u;
  if ( (abstr & 4) != 0 )
    result |= 8u;
  if ( (abstr & 2) != 0 )
    result |= 0x10u;
  if ( (abstr & 1) != 0 )
    result |= 0x20u;
  if ( (abstr & 0x80000) != 0 )
    result |= 2u;
  v2 = abstr & 0x300;
  if ( (abstr & 0x300) != 0 )
  {
    switch ( v2 )
    {
      case 0x100u:
        result |= 0x400u;
        break;
      case 0x200u:
        result |= 0x800u;
        break;
      case 0x300u:
        result |= 0xC00u;
        break;
      default:
        break;
    }
  }
  if ( (abstr & 0x30000) != 0 )
  {
    if ( (abstr & 0x30000) == 0x10000 )
      result |= 0x200u;
  }
  else
  {
    result |= 0x300u;
  }
  if ( (abstr & 0x40000) != 0 )
    return result | 0x1000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001AF05
// Name: __hw_cw_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __fastcall _hw_cw_sse2(int a1, unsigned int abstr)
{
  unsigned int result; // eax
  unsigned int v3; // ecx
  unsigned int v4; // edx

  result = 0;
  if ( (abstr & 0x10) != 0 )
    result = 128;
  if ( (abstr & 8) != 0 )
    result |= 0x200u;
  if ( (abstr & 4) != 0 )
    result |= 0x400u;
  if ( (abstr & 2) != 0 )
    result |= 0x800u;
  if ( (abstr & 1) != 0 )
    result |= 0x1000u;
  if ( (abstr & 0x80000) != 0 )
    result |= 0x100u;
  v3 = abstr & 0x300;
  if ( (abstr & 0x300) != 0 )
  {
    switch ( v3 )
    {
      case 0x100u:
        result |= 0x2000u;
        break;
      case 0x200u:
        result |= 0x4000u;
        break;
      case 0x300u:
        result |= 0x6000u;
        break;
      default:
        break;
    }
  }
  v4 = abstr & 0x3000000;
  switch ( v4 )
  {
    case 0x1000000u:
      result |= 0x8040u;
      break;
    case 0x2000000u:
      result |= 0x40u;
      break;
    case 0x3000000u:
      result |= 0x8000u;
      break;
    default:
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001AFA5
// Name: __control87
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _control87(unsigned int newctrl, unsigned int mask)
{
  int v2; // edx
  int v3; // eax
  unsigned int result; // eax
  __int16 v5; // ax
  __int16 v6; // bx
  unsigned int v7; // edx
  int v8; // eax
  __int16 v9; // ax
  int v10; // esi
  int v11; // ecx
  int v12; // eax
  int v13; // eax
  unsigned int v14; // edx
  int v15; // eax
  __int16 v16; // ax
  int v17; // edx
  int v18; // ecx
  int v19; // eax
  int v20; // eax
  int v21; // edx
  __int16 v22; // [esp+14h] [ebp-Ch]
  unsigned int v23; // [esp+1Ch] [ebp-4h]
  unsigned int maska; // [esp+28h] [ebp+8h]

  v2 = 0;
  if ( (v22 & 1) != 0 )
    v2 = 16;
  if ( (v22 & 4) != 0 )
    v2 |= 8u;
  if ( (v22 & 8) != 0 )
    v2 |= 4u;
  if ( (v22 & 0x10) != 0 )
    v2 |= 2u;
  if ( (v22 & 0x20) != 0 )
    v2 |= 1u;
  if ( (v22 & 2) != 0 )
    v2 |= 0x80000u;
  v3 = v22 & 0xC00;
  if ( v3 != 0 )
  {
    switch ( v3 )
    {
      case 1024:
        v2 |= 0x100u;
        break;
      case 2048:
        v2 |= 0x200u;
        break;
      case 3072:
        v2 |= 0x300u;
        break;
      default:
        break;
    }
  }
  if ( (v22 & 0x300) != 0 )
  {
    if ( (v22 & 0x300) == 0x200 )
      v2 |= 0x10000u;
  }
  else
  {
    v2 |= 0x20000u;
  }
  if ( (v22 & 0x1000) != 0 )
    v2 |= 0x40000u;
  result = mask & newctrl | v2 & ~mask;
  v23 = result;
  if ( result != v2 )
  {
    v5 = hw_cw(abstr: mask & newctrl | v2 & ~mask);
    v6 = v5;
    v7 = 0;
    if ( (v5 & 1) != 0 )
      v7 = 16;
    if ( (v5 & 4) != 0 )
      v7 |= 8u;
    if ( (v5 & 8) != 0 )
      v7 |= 4u;
    if ( (v5 & 0x10) != 0 )
      v7 |= 2u;
    if ( (v5 & 0x20) != 0 )
      v7 |= 1u;
    if ( (v5 & 2) != 0 )
      v7 |= 0x80000u;
    v8 = v5 & 0xC00;
    if ( (v6 & 0xC00) != 0 )
    {
      switch ( v8 )
      {
        case 1024:
          v7 |= 0x100u;
          break;
        case 2048:
          v7 |= 0x200u;
          break;
        case 3072:
          v7 |= 0x300u;
          break;
        default:
          break;
      }
    }
    if ( (v6 & 0x300) != 0 )
    {
      if ( (v6 & 0x300) == 0x200 )
        v7 |= 0x10000u;
    }
    else
    {
      v7 |= 0x20000u;
    }
    if ( (v6 & 0x1000) != 0 )
      v7 |= 0x40000u;
    result = v7;
    v23 = v7;
  }
  if ( __sse2_available != 0 )
  {
    v9 = _mm_getcsr();
    v10 = 0;
    if ( (v9 & 0x80u) != 0 )
      v10 = 16;
    if ( (v9 & 0x200) != 0 )
      v10 |= 8u;
    if ( (v9 & 0x400) != 0 )
      v10 |= 4u;
    if ( (v9 & 0x800) != 0 )
      v10 |= 2u;
    if ( (v9 & 0x1000) != 0 )
      v10 |= 1u;
    if ( (v9 & 0x100) != 0 )
      v10 |= 0x80000u;
    v11 = v9 & 0x6000;
    if ( (v9 & 0x6000) != 0 )
    {
      switch ( v11 )
      {
        case 8192:
          v10 |= 0x100u;
          break;
        case 16384:
          v10 |= 0x200u;
          break;
        case 24576:
          v10 |= 0x300u;
          break;
        default:
          break;
      }
    }
    v12 = (v9 & 0x8040) - 64;
    if ( v12 != 0 )
    {
      v13 = v12 - 32704;
      if ( v13 != 0 )
      {
        if ( v13 == 64 )
          v10 |= 0x1000000u;
      }
      else
      {
        v10 |= 0x3000000u;
      }
    }
    else
    {
      v10 |= 0x2000000u;
    }
    v14 = newctrl & mask & 0x308031F | v10 & ~(mask & 0x308031F);
    if ( v14 == v10 )
    {
      v15 = v10;
    }
    else
    {
      maska = _hw_cw_sse2(a1: v11, abstr: v14);
      __set_fpsr_sse2(newMXCSR: maska);
      v16 = _mm_getcsr();
      v17 = 0;
      if ( (v16 & 0x80u) != 0 )
        v17 = 16;
      if ( (v16 & 0x200) != 0 )
        v17 |= 8u;
      if ( (v16 & 0x400) != 0 )
        v17 |= 4u;
      if ( (v16 & 0x800) != 0 )
        v17 |= 2u;
      if ( (v16 & 0x1000) != 0 )
        v17 |= 1u;
      if ( (v16 & 0x100) != 0 )
        v17 |= 0x80000u;
      v18 = v16 & 0x6000;
      if ( (v16 & 0x6000) != 0 )
      {
        switch ( v18 )
        {
          case 8192:
            v17 |= 0x100u;
            break;
          case 16384:
            v17 |= 0x200u;
            break;
          case 24576:
            v17 |= 0x300u;
            break;
          default:
            break;
        }
      }
      v19 = (v16 & 0x8040) - 64;
      if ( v19 != 0 )
      {
        v20 = v19 - 32704;
        if ( v20 != 0 )
        {
          if ( v20 == 64 )
            v17 |= 0x1000000u;
        }
        else
        {
          v17 |= 0x3000000u;
        }
      }
      else
      {
        v17 |= 0x2000000u;
      }
      v15 = v17;
    }
    v21 = v23 ^ v15;
    result = v23 | v15;
    if ( (v21 & 0x8031F) != 0 )
      result |= 0x80000000;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001B2A8
// Name: __global_unwind2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _global_unwind2(PVOID TargetFrame)
{
  RtlUnwind(TargetFrame, TargetIp: &gu_return, ExceptionRecord: nullptr, ReturnValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1001B2C8
// Name: __unwind_handler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _unwind_handler(int a1, int a2, int a3, _DWORD *a4, int a5)
{
  int result; // eax

  result = 1;
  if ( (*(_DWORD *)(a1 + 4) & 6) != 0 )
  {
    _local_unwind2(a1: *(_DWORD *)(a5 + 36), a2: *(_DWORD *)(a5 + 40));
    *a4 = a2;
    return 3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001B30D
// Name: __local_unwind2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _local_unwind2(int a1, unsigned int a2)
{
  int result; // eax
  int v3; // ebx
  unsigned int v4; // esi
  int v5; // esi
  int v6; // ecx
  int v7; // [esp-4h] [ebp-24h]
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp+0h] [ebp-20h]

  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  while ( 1 )
  {
    result = a1;
    v3 = *(_DWORD *)(a1 + 8);
    v4 = *(_DWORD *)(a1 + 12);
    if ( v4 == -1 || a2 != -1 && v4 <= a2 )
      break;
    v5 = 3 * v4;
    *(_DWORD *)(a1 + 12) = *(_DWORD *)(v3 + 4 * v5);
    if ( *(_DWORD *)(v3 + 4 * v5 + 4) == 0 )
    {
      _NLG_Notify(a1: 257);
      _NLG_Call(a1: v6, a2: v7, a3: ExceptionList);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001B391
// Name: __abnormal_termination
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _abnormal_termination()
{
  int result; // eax
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // ecx

  result = 0;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  if ( (int (__cdecl *)(int, int, int, _DWORD *, int))ExceptionList->Handler == _unwind_handler )
    return ExceptionList[1].Next == *((_EXCEPTION_REGISTRATION_RECORD **)ExceptionList[1].Handler + 3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001B3B4
// Name: __NLG_Notify1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _NLG_Notify1(int a1)
{
  JUMPOUT(0x1001B3C8);
}

//------------------------------------------------------------------------------
// Address: 0x1001B3BD
// Name: __NLG_Notify
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __userpurge _NLG_Notify@<eax>(unsigned int result@<eax>, unsigned int a2@<ebp>, unsigned int a3)
{
  _NLG_Destination.dwCode = a3;
  _NLG_Destination.uoffDestination = result;
  _NLG_Destination.uoffFramePointer = a2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001B3DC
// Name: __NLG_Call
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _NLG_Call@<eax>(int (*a1)(void)@<eax>)
{
  return a1();
}

//------------------------------------------------------------------------------
// Address: 0x1001B3DF
// Name: __read_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _read_nolock@<eax>(unsigned int a1@<edi>, int fh, _BYTE *inputbuf, unsigned int cnt)
{
  unsigned int v4; // edx
  int result; // eax
  ioinfo **v6; // edi
  unsigned int v7; // esi
  char *v8; // eax
  char v9; // cl
  _BYTE *v10; // eax
  doubleint v11; // rax
  ioinfo *v12; // ecx
  char *v13; // ecx
  char v14; // cl
  ioinfo *v15; // ecx
  bool v16; // zf
  char v17; // cl
  ioinfo *v18; // ecx
  char v19; // cl
  ioinfo *v20; // ecx
  ioinfo *v21; // eax
  char *v22; // eax
  char *v23; // ebx
  bool v24; // cf
  char v25; // al
  char *v26; // eax
  char *v27; // ebx
  int v28; // ecx
  int v29; // eax
  char v30; // dl
  char *v31; // ecx
  char *v32; // ebx
  int v33; // ebx
  DWORD LastError; // eax
  ioinfo *v35; // edx
  BOOL v36; // ecx
  char *v37; // ebx
  __int16 v38; // cx
  char *v39; // esi
  unsigned int inputsize; // [esp+4h] [ebp-1Ch]
  int os_read; // [esp+8h] [ebp-18h] BYREF
  int retval; // [esp+Ch] [ebp-14h]
  int bytes_read; // [esp+10h] [ebp-10h]
  void *buf; // [esp+14h] [ebp-Ch]
  wchar_t wpeekchr; // [esp+18h] [ebp-8h] BYREF
  char tmode; // [esp+1Eh] [ebp-2h]
  char peekchr; // [esp+1Fh] [ebp-1h] BYREF
  char *p; // [esp+30h] [ebp+10h]
  char *pa; // [esp+30h] [ebp+10h]

  v4 = cnt;
  retval = -2;
  inputsize = cnt;
  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter(a1: 0, a2: a1, a3: fh);
    return -1;
  }
  v6 = &__pioinfo[fh >> 5];
  v7 = (fh & 0x1F) << 6;
  v8 = (char *)*v6 + v7;
  v9 = v8[4];
  if ( (v9 & 1) == 0 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
LABEL_19:
    _invalid_parameter(a1: 0, a2: (unsigned int)v6, a3: v7);
    return -1;
  }
  if ( cnt > 0x7FFFFFFF )
    goto LABEL_18;
  bytes_read = 0;
  if ( cnt == 0 || (v9 & 2) != 0 )
    return 0;
  if ( inputbuf == nullptr )
    goto LABEL_18;
  tmode = (char)(2 * v8[36]) >> 1;
  if ( tmode != 1 )
  {
    if ( tmode != 2 )
    {
LABEL_16:
      v10 = inputbuf;
      buf = inputbuf;
      goto LABEL_26;
    }
    if ( (cnt & 1) == 0 )
    {
      cnt &= ~1u;
      goto LABEL_16;
    }
LABEL_18:
    *__doserrno() = 0;
    *_errno() = 22;
    goto LABEL_19;
  }
  if ( (cnt & 1) != 0 )
    goto LABEL_18;
  cnt = 4;
  if ( v4 >> 1 >= 4 )
    cnt = v4 >> 1;
  buf = operator new(nSize: cnt);
  if ( buf == nullptr )
  {
    *_errno() = 12;
    *__doserrno() = 8;
    return -1;
  }
  v11.bigint = _lseeki64_nolock(fh, pos: 0, mthd: 1u).bigint;
  v12 = *v6;
  *(_DWORD *)&v12->pipech2[v7 + 3] = v11.twoints.lowerhalf;
  v10 = buf;
  *(_DWORD *)&v12->pipech2[v7 + 7] = v11.twoints.upperhalf;
LABEL_26:
  v13 = (char *)*v6 + v7;
  if ( (v13[4] & 0x48) != 0 )
  {
    v14 = v13[5];
    if ( v14 != 10 && cnt != 0 )
    {
      *v10 = v14;
      v15 = *v6;
      ++v10;
      --cnt;
      v16 = tmode == 0;
      bytes_read = 1;
      *(&v15->pipech + v7) = 10;
      if ( !v16 )
      {
        v17 = (*v6)->pipech2[v7];
        if ( v17 != 10 && cnt != 0 )
        {
          *v10 = v17;
          v18 = *v6;
          ++v10;
          --cnt;
          v16 = tmode == 1;
          bytes_read = 2;
          v18->pipech2[v7] = 10;
          if ( v16 )
          {
            v19 = (*v6)->pipech2[v7 + 1];
            if ( v19 != 10 && cnt != 0 )
            {
              *v10 = v19;
              v20 = *v6;
              ++v10;
              --cnt;
              bytes_read = 3;
              v20->pipech2[v7 + 1] = 10;
            }
          }
        }
      }
    }
  }
  if ( !ReadFile(
          hFile: *(HANDLE *)((char *)&(*v6)->osfhnd + v7),
          lpBuffer: v10,
          nNumberOfBytesToRead: cnt,
          lpNumberOfBytesRead: (LPDWORD)&os_read,
          lpOverlapped: nullptr)
    || os_read < 0
    || os_read > cnt )
  {
    LastError = GetLastError();
    if ( LastError == 5 )
    {
      *_errno() = 9;
      *__doserrno() = 5;
      goto LABEL_93;
    }
    if ( LastError == 109 )
    {
      retval = 0;
      goto error_return_0;
    }
    goto LABEL_92;
  }
  v21 = *v6;
  bytes_read += os_read;
  v22 = &v21->osfile + v7;
  if ( *v22 < 0 )
  {
    if ( tmode != 2 )
    {
      if ( os_read != 0 && *(_BYTE *)buf == 10 )
        *v22 |= 4u;
      else
        *v22 &= ~4u;
      v23 = (char *)buf;
      v24 = buf < (char *)buf + bytes_read;
      p = (char *)buf;
      bytes_read += (int)buf;
      if ( v24 )
      {
        do
        {
          v25 = *p;
          if ( *p == 26 )
          {
            v26 = &(*v6)->osfile + v7;
            if ( (*v26 & 0x40) != 0 )
              *v23++ = *p;
            else
              *v26 |= 2u;
            break;
          }
          if ( v25 == 13 )
          {
            if ( (unsigned int)p < bytes_read - 1 )
            {
              if ( p[1] == 10 )
              {
                p += 2;
                goto LABEL_52;
              }
              ++p;
LABEL_63:
              *v23 = 13;
LABEL_64:
              ++v23;
              continue;
            }
            ++p;
            if ( !ReadFile(
                    hFile: *(HANDLE *)((char *)&(*v6)->osfhnd + v7),
                    lpBuffer: &peekchr,
                    nNumberOfBytesToRead: 1u,
                    lpNumberOfBytesRead: (LPDWORD)&os_read,
                    lpOverlapped: nullptr)
              && GetLastError() != 0
              || os_read == 0 )
            {
              goto LABEL_63;
            }
            if ( (*(&(*v6)->osfile + v7) & 0x48) != 0 )
            {
              if ( peekchr != 10 )
              {
                *v23 = 13;
                *(&(*v6)->pipech + v7) = peekchr;
                goto LABEL_64;
              }
LABEL_52:
              *v23 = 10;
              goto LABEL_64;
            }
            if ( v23 == buf && peekchr == 10 )
              goto LABEL_52;
            _lseeki64_nolock(fh, pos: -1, mthd: 1u);
            if ( peekchr != 10 )
              goto LABEL_63;
          }
          else
          {
            *v23++ = v25;
            ++p;
          }
        }
        while ( (unsigned int)p < bytes_read );
      }
      bytes_read = v23 - (_BYTE *)buf;
      if ( tmode != 1 || v23 == buf )
        goto error_return_0;
      v27 = v23 - 1;
      LOBYTE(v28) = *v27;
      if ( *v27 < 0 )
      {
        v29 = 1;
        v28 = (unsigned __int8)v28;
        while ( _lookuptrailbytes[v28] == 0 && v29 <= 4 && v27 >= buf )
        {
          v28 = (unsigned __int8)*--v27;
          ++v29;
        }
        v30 = *v27;
        if ( _lookuptrailbytes[(unsigned __int8)*v27] == 0 )
        {
          *_errno() = 42;
LABEL_93:
          retval = -1;
          goto error_return_0;
        }
        if ( _lookuptrailbytes[(unsigned __int8)*v27] + 1 == v29 )
        {
          v27 += v29;
        }
        else
        {
          v31 = (char *)*v6 + v7;
          if ( (v31[4] & 0x48) != 0 )
          {
            v32 = v27 + 1;
            v31[5] = v30;
            if ( v29 >= 2 )
              (*v6)->pipech2[v7] = *v32++;
            if ( v29 == 3 )
              (*v6)->pipech2[v7 + 1] = *v32++;
            v27 = &v32[-v29];
          }
          else
          {
            _lseeki64_nolock(fh, pos: -v29, mthd: 1u);
          }
        }
      }
      else
      {
        ++v27;
      }
      v33 = v27 - (_BYTE *)buf;
      bytes_read = MultiByteToWideChar(
                     CodePage: 0xFDE9u,
                     dwFlags: 0,
                     lpMultiByteStr: (LPCCH)buf,
                     cbMultiByte: v33,
                     lpWideCharStr: (LPWSTR)inputbuf,
                     cchWideChar: inputsize >> 1);
      if ( bytes_read != 0 )
      {
        v35 = *v6;
        v36 = bytes_read != v33;
        bytes_read *= 2;
        *(int *)((char *)&v35->utf8translations + v7) = v36;
        goto error_return_0;
      }
      LastError = GetLastError();
LABEL_92:
      _dosmaperr(oserrno: LastError);
      goto LABEL_93;
    }
    if ( os_read != 0 && *(_WORD *)buf == 10 )
      *v22 |= 4u;
    else
      *v22 &= ~4u;
    v37 = (char *)buf;
    v24 = buf < (char *)buf + bytes_read;
    pa = (char *)buf;
    bytes_read += (int)buf;
    if ( !v24 )
    {
LABEL_128:
      bytes_read = v37 - (_BYTE *)buf;
      goto error_return_0;
    }
    while ( 1 )
    {
      v38 = *(_WORD *)pa;
      if ( *(_WORD *)pa == 26 )
      {
        v39 = &(*v6)->osfile + v7;
        if ( (*v39 & 0x40) != 0 )
        {
          *(_WORD *)v37 = *(_WORD *)pa;
          v37 += 2;
        }
        else
        {
          *v39 |= 2u;
        }
        goto LABEL_128;
      }
      if ( v38 == 13 )
      {
        if ( (unsigned int)pa < bytes_read - 2 )
        {
          if ( *((_WORD *)pa + 1) == 10 )
          {
            pa += 4;
            goto LABEL_110;
          }
          pa += 2;
LABEL_121:
          *(_WORD *)v37 = 13;
LABEL_122:
          v37 += 2;
          goto LABEL_123;
        }
        pa += 2;
        if ( !ReadFile(
                hFile: *(HANDLE *)((char *)&(*v6)->osfhnd + v7),
                lpBuffer: &wpeekchr,
                nNumberOfBytesToRead: 2u,
                lpNumberOfBytesRead: (LPDWORD)&os_read,
                lpOverlapped: nullptr)
          && GetLastError() != 0
          || os_read == 0 )
        {
          goto LABEL_121;
        }
        if ( (*(&(*v6)->osfile + v7) & 0x48) != 0 )
        {
          if ( wpeekchr != 10 )
          {
            *(_WORD *)v37 = 13;
            *(&(*v6)->pipech + v7) = wpeekchr;
            (*v6)->pipech2[v7] = HIBYTE(wpeekchr);
            (*v6)->pipech2[v7 + 1] = 10;
            goto LABEL_122;
          }
LABEL_110:
          *(_WORD *)v37 = 10;
          goto LABEL_122;
        }
        if ( v37 == buf && wpeekchr == 10 )
          goto LABEL_110;
        _lseeki64_nolock(fh, pos: -2, mthd: 1u);
        if ( wpeekchr != 10 )
          goto LABEL_121;
      }
      else
      {
        *(_WORD *)v37 = v38;
        v37 += 2;
        pa += 2;
      }
LABEL_123:
      if ( (unsigned int)pa >= bytes_read )
        goto LABEL_128;
    }
  }
error_return_0:
  if ( buf != inputbuf )
    free(pMem: buf);
  result = retval;
  if ( retval == -2 )
    return bytes_read;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001B9A0
// Name: __read
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _read@<eax>(ioinfo **a1@<ebx>, unsigned int a2@<edi>, int fh, _BYTE *buf, unsigned int cnt)
{
  int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle || (a1 = &__pioinfo[fh >> 5], a2 = (fh & 0x1F) << 6, (*(&(*a1)->osfile + a2) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
LABEL_7:
    _invalid_parameter((unsigned int)a1, a2, a3: 0);
    return -1;
  }
  if ( cnt > 0x7FFFFFFF )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    goto LABEL_7;
  }
  __lock_fhandle(fh);
  if ( (*(&(*a1)->osfile + a2) & 1) != 0 )
  {
    r = _read_nolock(a1: a2, fh, inputbuf: buf, cnt);
  }
  else
  {
    *_errno() = 9;
    *__doserrno() = 0;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x1001BA9D
// Name: ___initconout
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __initconout()
{
  HANDLE result; // eax

  result = CreateFileA(
             lpFileName: "CONOUT$",
             dwDesiredAccess: 0x40000000u,
             dwShareMode: 3u,
             lpSecurityAttributes: nullptr,
             dwCreationDisposition: 3u,
             dwFlagsAndAttributes: 0,
             hTemplateFile: nullptr);
  _confh = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001BABC
// Name: ___termcon
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HANDLE __termcon()
{
  HANDLE result; // eax

  if ( _confh != (HANDLE)-1 && _confh != (HANDLE)-2 )
    CloseHandle(hObject: _confh);
  result = _coninpfh;
  if ( _coninpfh != (HANDLE)-1 && _coninpfh != (HANDLE)-2 )
    return (HANDLE)CloseHandle(hObject: _coninpfh);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001BAE9
// Name: __fclose_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _fclose_nolock(_iobuf *str)
{
  unsigned int v1; // ebx
  int v3; // eax

  v1 = -1;
  if ( str != nullptr )
  {
    if ( (str->_flag & 0x83) != 0 )
    {
      v1 = _flush(str);
      _freebuf(stream: str);
      v3 = _fileno(a1: v1, a2: 0, stream: str);
      if ( _close(fh: v3) >= 0 )
      {
        if ( str->_tmpfname != nullptr )
        {
          free(pMem: str->_tmpfname);
          str->_tmpfname = nullptr;
        }
      }
      else
      {
        v1 = -1;
      }
    }
    str->_flag = 0;
    return v1;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1: 0xFFFFFFFF, a2: 0, a3: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BB5B
// Name: _fclose
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall fclose@<eax>(unsigned int a1@<ebx>, _iobuf *stream)
{
  unsigned int v3; // [esp+10h] [ebp-1Ch]

  v3 = -1;
  if ( stream != nullptr )
  {
    if ( (stream->_flag & 0x40) != 0 )
    {
      stream->_flag = 0;
    }
    else
    {
      _lock_file(pf: stream);
      v3 = _fclose_nolock(str: stream);
      _unlock_file(pf: stream);
    }
    return v3;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2: 0, a3: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BBD7
// Name: __commit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD __usercall _commit@<eax>(ioinfo **a1@<edi>, unsigned int a2@<esi>, int filedes)
{
  void *osfhandle; // eax
  DWORD retval; // [esp+14h] [ebp-1Ch]

  if ( filedes == -2 )
  {
    *_errno() = 9;
    return -1;
  }
  if ( filedes < 0
    || filedes >= _nhandle
    || (a1 = &__pioinfo[filedes >> 5], (*(&(*a1)->osfile + (a2 = (filedes & 0x1F) << 6)) & 1) == 0) )
  {
    *_errno() = 9;
    _invalid_parameter(a1: 0, a2: (unsigned int)a1, a3: a2);
    return -1;
  }
  __lock_fhandle(fh: filedes);
  if ( (*(&(*a1)->osfile + a2) & 1) != 0 )
  {
    osfhandle = (void *)_get_osfhandle(a1: 0, a2: (unsigned int)a1, fh: filedes);
    if ( FlushFileBuffers(hFile: osfhandle) )
      retval = 0;
    else
      retval = GetLastError();
    if ( retval == 0 )
      goto good;
    *__doserrno() = retval;
  }
  *_errno() = 9;
  retval = -1;
good:
  _unlock_fhandle(fh: filedes);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1001BCC0
// Name: ___ascii_strnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __ascii_strnicmp(unsigned __int8 *first, unsigned __int8 *last, unsigned int count)
{
  unsigned int i; // ecx
  unsigned __int8 v6; // ah
  unsigned __int8 v7; // al

  for ( i = count; i != 0; --i )
  {
    v6 = *first;
    v7 = *last;
    if ( *first == 0 || v7 == 0 )
      break;
    ++first;
    ++last;
    if ( v6 >= 0x41u && v6 <= 0x5Au )
      v6 += 32;
    if ( v7 >= 0x41u && v7 <= 0x5Au )
      v7 += 32;
    if ( v6 != v7 )
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BD21
// Name: __close_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _close_nolock@<eax>(unsigned int a1@<ebx>, unsigned int osfhandle@<edi>, int fh)
{
  void *v3; // eax
  DWORD LastError; // edi

  if ( _get_osfhandle(a1, a2: osfhandle, fh) == -1
    || (fh == 1 && (__pioinfo[0][2].osfile & 1) != 0 || fh == 2 && (__pioinfo[0][1].osfile & 1) != 0)
    && (osfhandle = _get_osfhandle(a1, a2: osfhandle, fh: 2), _get_osfhandle(a1, a2: osfhandle, fh: 1) == osfhandle)
    || (v3 = (void *)_get_osfhandle(a1, a2: osfhandle, fh), CloseHandle(hObject: v3)) )
  {
    LastError = 0;
  }
  else
  {
    LastError = GetLastError();
  }
  _free_osfhnd(fh);
  __pioinfo[fh >> 5][fh & 0x1F].osfile = 0;
  if ( LastError == 0 )
    return 0;
  _dosmaperr(oserrno: LastError);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1001BDB8
// Name: __close
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _close@<eax>(ioinfo **a1@<ebx>, unsigned int a2@<esi>, int fh)
{
  int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle || (a1 = &__pioinfo[fh >> 5], a2 = (fh & 0x1F) << 6, (*(&(*a1)->osfile + a2) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter((unsigned int)a1, a2: 0, a3: a2);
    return -1;
  }
  __lock_fhandle(fh);
  if ( (*(&(*a1)->osfile + a2) & 1) != 0 )
  {
    r = _close_nolock((unsigned int)a1, osfhandle: 0, fh);
  }
  else
  {
    *_errno() = 9;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x1001BE85
// Name: __freebuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _freebuf(_iobuf *stream)
{
  int flag; // eax

  flag = stream->_flag;
  if ( (flag & 0x83) != 0 && (flag & 8) != 0 )
  {
    free(pMem: stream->_base);
    stream->_flag &= 0xFFFFFBF7;
    stream->_ptr = nullptr;
    stream->_base = nullptr;
    stream->_cnt = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001BEB2
// Name: RtlUnwind(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __stdcall RtlUnwind(PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_RECORD ExceptionRecord, PVOID ReturnValue)
{
  __imp__RtlUnwind@16(TargetFrame, TargetIp, ExceptionRecord, ReturnValue);
}

//------------------------------------------------------------------------------
// Address: 0x1001BEC0
// Name: _dynamic_initializer_for__PyTypeVector__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__PyTypeVector__()
{
  PyTypeVector.tp_alloc = (_object *(__cdecl *)(_typeobject *, int))_PyType_GenericAlloc;
  PyTypeVector.tp_new = (_object *(__cdecl *)(_typeobject *, _object *, _object *))_PyType_GenericNew;
  PyTypeVector.tp_free = (void (__cdecl *)(void *))_PyObject_Free;
  *(_QWORD *)&PyTypeVector.tp_is_gc = 0;
  *(_QWORD *)&PyTypeVector.tp_mro = 0;
  *(_QWORD *)&PyTypeVector.tp_subclasses = 0;
  PyTypeVector.tp_del = nullptr;
  return _PyType_GenericAlloc;
}

//------------------------------------------------------------------------------
// Address: 0x1001BF10
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  s_EmptyConVar.m_Value.m_StringLength = strlen("0") + 1;
  s_EmptyConVar.m_Value.m_pszString = (char *)operator new(nSize: s_EmptyConVar.m_Value.m_StringLength);
  memcpy(
    dst: (unsigned __int8 *)s_EmptyConVar.m_Value.m_pszString,
    src: (unsigned __int8 *)s_EmptyConVar.m_pszDefaultValue,
    count: s_EmptyConVar.m_Value.m_StringLength);
  if ( ConVar::InternalSetColorFromString(this: &s_EmptyConVar, value: s_EmptyConVar.m_Value.m_pszString) == 0 )
  {
    s_EmptyConVar.m_Value.m_fValue = atof(nptr: s_EmptyConVar.m_Value.m_pszString);
    if ( (LODWORD(s_EmptyConVar.m_Value.m_fValue) & 0x7F800000) == 0x7F800000 )
    {
      _Warning(
        a1: "ConVar(%s) defined with infinite float value (%s)\n",
        byte_1001DB62,
        s_EmptyConVar.m_Value.m_pszString);
      s_EmptyConVar.m_Value.m_fValue = 3.4028235e38;
    }
    s_EmptyConVar.m_Value.m_nValue = (int)s_EmptyConVar.m_Value.m_fValue;
  }
  s_EmptyConVar.m_bRegistered = false;
  s_EmptyConVar.m_pszName = byte_1001DB62;
  s_EmptyConVar.m_pszHelpString = empty_string;
  s_EmptyConVar.m_nFlags = 0;
  s_EmptyConVar.m_pNext = ConCommandBase::s_pConCommandBases;
  ConCommandBase::s_pConCommandBases = &s_EmptyConVar;
  if ( ConCommandBase::s_pAccessor != nullptr )
    s_EmptyConVar.Init(this: &s_EmptyConVar);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&CEmptyConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&CEmptyConVar::`vftable'{for `IConVar'};
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x1001C040
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **dynamic_initializer_for__s_StringCharConversion__()
{
  char **result; // eax
  int v1; // edx
  char v2; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(
    dst: (int)s_StringCharConversion.m_pConversion,
    value: nullptr,
    count: sizeof(s_StringCharConversion.m_pConversion));
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v1 = **result;
    v2 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v1] = v2;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001C0A0
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001C0D0
// Name: _dynamic_atexit_destructor_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__s_EmptyConVar__()
{
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConVar::`vftable'{for `ConCommandBase'};
  s_EmptyConVar.ConVar::IConVar::__vftable = (IConVar_vtbl *)&ConVar::`vftable'{for `IConVar'};
  if ( s_EmptyConVar.m_Value.m_pszString != nullptr )
  {
    free(pMem: s_EmptyConVar.m_Value.m_pszString);
    s_EmptyConVar.m_Value.m_pszString = nullptr;
  }
  CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>::~CUtlVector<void (__cdecl *)(IConVar *,char const *,float),CUtlMemory<void (__cdecl *)(IConVar *,char const *,float),int>>(this: &s_EmptyConVar.m_fnChangeCallbacks);
  s_EmptyConVar.ConVar::ConCommandBase::__vftable = (CEmptyConVar_vtbl *)&ConCommandBase::`vftable';
}

} // namespace vscript_python

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x10096B50
// Name: float TextureToLinear(int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl TextureToLinear(int c)
{
  if ( c < 0 )
    return 0.0;
  if ( c <= 255 )
    return texturetolinear[c];
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10096B80
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

//------------------------------------------------------------------------------
// Address: 0x10096EF0
// Name: float X360LinearToGamma(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl X360LinearToGamma(float flLinearValue)
{
  float v1; // xmm0_4
  float v2; // xmm0_4

  v1 = flLinearValue;
  if ( flLinearValue < 0.0 )
  {
    v1 = 0.0;
LABEL_10:
    v2 = v1 * 4.0117645;
    goto LABEL_11;
  }
  if ( flLinearValue > 1.0 )
  {
    v1 = 1.0;
LABEL_5:
    v2 = (float)(v1 * 0.50147057) + 0.50196081;
    if ( v2 > 1.0 )
      return 1.0;
    goto LABEL_11;
  }
  if ( flLinearValue >= 0.12512219 )
  {
    if ( flLinearValue < 0.50048876 )
    {
      v2 = (float)(flLinearValue * 1.0029411) + 0.25098041;
      goto LABEL_11;
    }
    goto LABEL_5;
  }
  if ( flLinearValue < 0.062561095 )
    goto LABEL_10;
  v2 = (float)(flLinearValue * 2.0058823) + 0.1254902;
LABEL_11:
  if ( v2 < 0.0 )
    return 0.0;
  if ( v2 <= 1.0 )
    return v2;
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10096FB0
// Name: float SrgbGammaTo360Gamma(float)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

} // namespace vtex_dll

// ============================================================
// Overlay from vtf2tga (Missing functions)
// ============================================================
namespace vtf2tga {

//------------------------------------------------------------------------------
// Address: 0x0042B1C0
// Name: float TextureToLinear(int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl TextureToLinear(int c)
{
  if ( c < 0 )
    return 0.0;
  if ( c <= 255 )
    return texturetolinear[c];
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x0042B1F0
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

//------------------------------------------------------------------------------
// Address: 0x0042B560
// Name: float X360LinearToGamma(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl X360LinearToGamma(float flLinearValue)
{
  float v1; // xmm0_4
  float v2; // xmm0_4

  v1 = flLinearValue;
  if ( flLinearValue < 0.0 )
  {
    v1 = 0.0;
LABEL_10:
    v2 = v1 * 4.0117645;
    goto LABEL_11;
  }
  if ( flLinearValue > 1.0 )
  {
    v1 = 1.0;
LABEL_5:
    v2 = (float)(v1 * 0.50147057) + 0.50196081;
    if ( v2 > 1.0 )
      return 1.0;
    goto LABEL_11;
  }
  if ( flLinearValue >= 0.12512219 )
  {
    if ( flLinearValue < 0.50048876 )
    {
      v2 = (float)(flLinearValue * 1.0029411) + 0.25098041;
      goto LABEL_11;
    }
    goto LABEL_5;
  }
  if ( flLinearValue < 0.062561095 )
    goto LABEL_10;
  v2 = (float)(flLinearValue * 2.0058823) + 0.1254902;
LABEL_11:
  if ( v2 < 0.0 )
    return 0.0;
  if ( v2 <= 1.0 )
    return v2;
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x0042B620
// Name: float SrgbGammaTo360Gamma(float)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

} // namespace vtf2tga

// ============================================================
// Overlay from vtfdiff (Missing functions)
// ============================================================
namespace vtfdiff {

//------------------------------------------------------------------------------
// Address: 0x00442090
// Name: float TextureToLinear(int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl TextureToLinear(int c)
{
  if ( c < 0 )
    return 0.0;
  if ( c <= 255 )
    return texturetolinear[c];
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x004420C0
// Name: float X360LinearToGamma(float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl X360LinearToGamma(float flLinearValue)
{
  float v1; // xmm0_4
  float v2; // xmm0_4

  v1 = flLinearValue;
  if ( flLinearValue < 0.0 )
  {
    v1 = 0.0;
LABEL_10:
    v2 = v1 * 4.0117645;
    goto LABEL_11;
  }
  if ( flLinearValue > 1.0 )
  {
    v1 = 1.0;
LABEL_5:
    v2 = (float)(v1 * 0.50147057) + 0.50196081;
    if ( v2 > 1.0 )
      return 1.0;
    goto LABEL_11;
  }
  if ( flLinearValue >= 0.12512219 )
  {
    if ( flLinearValue < 0.50048876 )
    {
      v2 = (float)(flLinearValue * 1.0029411) + 0.25098041;
      goto LABEL_11;
    }
    goto LABEL_5;
  }
  if ( flLinearValue < 0.062561095 )
    goto LABEL_10;
  v2 = (float)(flLinearValue * 2.0058823) + 0.1254902;
LABEL_11:
  if ( v2 < 0.0 )
    return 0.0;
  if ( v2 <= 1.0 )
    return v2;
  return 1.0;
}

//------------------------------------------------------------------------------
// Address: 0x00442180
// Name: float SrgbGammaTo360Gamma(float)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

} // namespace vtfdiff

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x1001B410
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace vvis_dll

// ============================================================
// Overlay from worldrenderertest (Missing functions)
// ============================================================
namespace worldrenderertest {

//------------------------------------------------------------------------------
// Address: 0x0040ED20
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildGammaTable(float gamma, float texGamma, float brightness, int overbright)
{
  double v4; // st7
  double v5; // st6
  double v6; // st6
  double v7; // st7
  int v8; // esi
  int v9; // eax
  int v10; // esi
  double v11; // st7
  double v12; // st5
  long double v13; // st7
  int v14; // eax
  int v15; // esi
  long double v16; // st7
  int v17; // esi
  double v18; // st6
  int v19; // esi
  long double v20; // st7
  int v21; // ecx
  unsigned __int8 v22; // al
  int g3; // [esp+4h] [ebp-10h]
  int g3a; // [esp+4h] [ebp-10h]
  int g3b; // [esp+4h] [ebp-10h]
  int g3c; // [esp+4h] [ebp-10h]
  int g3d; // [esp+4h] [ebp-10h]
  float g1; // [esp+8h] [ebp-Ch]
  float g; // [esp+Ch] [ebp-8h]
  float v30; // [esp+10h] [ebp-4h]
  float gammaa; // [esp+18h] [ebp+4h]
  float overbrightFactor; // [esp+1Ch] [ebp+8h]
  float overbrightFactora; // [esp+1Ch] [ebp+8h]
  float brightnessa; // [esp+20h] [ebp+Ch]
  float overbrighta; // [esp+24h] [ebp+10h]

  v4 = 3.0;
  if ( gamma <= 3.0 )
    v4 = gamma;
  v5 = 1.0 / v4;
  v30 = v5;
  g = v5 * texGamma;
  v6 = brightness;
  if ( brightness > 0.0 )
  {
    if ( v6 <= 1.0 )
      v7 = 0.125 - v6 * v6 * 0.075;
    else
      v7 = 0.050000001;
  }
  else
  {
    v7 = 0.125;
  }
  g1 = v7;
  v8 = 0;
  g3 = 0;
  do
  {
    v9 = (int)(pow((double)g3 * 0.0039215689, g) * 255.0);
    if ( v9 >= 0 )
    {
      if ( v9 > 255 )
        LOBYTE(v9) = -1;
    }
    else
    {
      LOBYTE(v9) = 0;
    }
    texgammatable[v8++] = v9;
    g3 = v8;
  }
  while ( v8 < 256 );
  v10 = 0;
  g3a = 0;
  do
  {
    v11 = (double)g3a * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v11 = v11 * brightness;
    v12 = g1;
    if ( g1 < v11 )
      v13 = (v11 - v12) / (1.0 - v12) * 0.875 + 0.125;
    else
      v13 = v11 / v12 * 0.125;
    v14 = (int)(pow(v13, v30) * 255.0);
    if ( v14 >= 0 )
    {
      if ( v14 > 255 )
        v14 = 255;
    }
    else
    {
      v14 = 0;
    }
    lineartoscreen[v10++] = v14;
    g3a = v10;
  }
  while ( v10 < 1024 );
  v15 = 0;
  g3b = 0;
  do
  {
    v16 = (double)g3b * 0.0039215689;
    brightnessa = v16;
    texturetolinear[v15] = pow(v16, texGamma);
    g_Mathlib_LinearToGamma[v15] = pow(brightnessa, 0.4545454382896423);
    g_Mathlib_GammaToLinear[v15++] = pow(brightnessa, 2.200000047683716);
    g3b = v15;
  }
  while ( v15 < 256 );
  v17 = 0;
  g3c = 0;
  overbrightFactor = 1.0 / texGamma;
  do
  {
    lineartotexture[v17++] = (int)(pow((double)g3c * 0.0009775171065493646, overbrightFactor) * 255.0);
    g3c = v17;
  }
  while ( v17 < 1024 );
  overbrightFactora = 1.0;
  if ( overbright == 2 )
  {
    v18 = 0.5;
LABEL_33:
    overbrightFactora = v18;
    goto LABEL_34;
  }
  if ( overbright == 4 )
  {
    v18 = 0.25;
    goto LABEL_33;
  }
LABEL_34:
  v19 = 0;
  g3d = 0;
  gammaa = 1.0 / gamma;
  do
  {
    v20 = pow((double)g3d * 0.0009765625, gammaa) * overbrightFactora;
    lineartovertex[v19] = v20;
    if ( v20 > 1.0 )
      lineartovertex[v19] = 1.0;
    overbrighta = v20 * 255.0;
    v21 = (int)overbrighta;
    if ( v21 <= 255 )
      v22 = v21 < 0 ? 0 : v21;
    else
      v22 = -1;
    lineartolightmap[v19++] = v22;
    g3d = v19;
  }
  while ( v19 < 4096 );
}

} // namespace worldrenderertest

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x102CA1F0
// Name: float LinearToGammaFullRange(float)
// Source: json
//------------------------------------------------------------------------------
long double __cdecl LinearToGammaFullRange(float linear)
{
  return pow(linear, 0.4545454382896423);
}

//------------------------------------------------------------------------------
// Address: 0x102CA210
// Name: int LinearToTexture(float)
// Source: json
//------------------------------------------------------------------------------
int __cdecl LinearToTexture(float f)
{
  int v1; // eax

  v1 = (int)(float)(f * 1023.0);
  if ( v1 < 0 )
    return lineartotexture[0];
  if ( v1 > 1023 )
    v1 = 1023;
  return lineartotexture[v1];
}

//------------------------------------------------------------------------------
// Address: 0x102CA250
// Name: void ColorRGBExp32ToVector(struct ColorRGBExp32 const __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ColorRGBExp32ToVector(const ColorRGBExp32 *in, Vector *out)
{
  out->x = (float)((float)in->r * dword_105BA000[in->exponent]) * 255.0;
  out->y = (float)((float)in->g * dword_105BA000[in->exponent]) * 255.0;
  out->z = (float)((float)in->b * dword_105BA000[in->exponent]) * 255.0;
}

//------------------------------------------------------------------------------
// Address: 0x102CA2D0
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildGammaTable(float gamma, float texGamma, float brightness, int overbright)
{
  int v4; // esi
  int v5; // eax
  int i; // esi
  float v7; // xmm0_4
  float v8; // xmm0_4
  int v9; // eax
  int j; // esi
  float v11; // xmm0_4
  int k; // esi
  int v13; // xmm0_4
  int m; // esi
  float v15; // xmm1_4
  int v16; // eax
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  if ( brightness > 0.0 )
  {
    if ( brightness <= 1.0 )
    {
      v4 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v4 = 0;
    }
  }
  else
  {
    g3 = 0.125;
    v4 = 0;
  }
  do
  {
    __libm_sse2_pow();
    v5 = (int)(float)((float)((float)v4 * 0.0039215689) * 255.0);
    if ( v5 >= 0 )
    {
      if ( v5 > 255 )
        LOBYTE(v5) = -1;
    }
    else
    {
      LOBYTE(v5) = 0;
    }
    texgammatable[v4++] = v5;
  }
  while ( v4 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v7 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v7 = v7 * brightness;
    if ( g3 < v7 )
      v8 = (float)((float)(v7 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v8 = (float)(v7 / g3) * 0.125;
    __libm_sse2_pow();
    v9 = (int)(float)(v8 * 255.0);
    if ( v9 >= 0 )
    {
      if ( v9 > 255 )
        v9 = 255;
    }
    else
    {
      v9 = 0;
    }
    lineartoscreen[i] = v9;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow();
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow();
    v11 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v11;
    __libm_sse2_pow();
    g_Mathlib_GammaToLinear[j] = v11;
  }
  for ( k = 0; k < 1024; ++k )
  {
    __libm_sse2_pow();
    lineartotexture[k] = 255 * (int)((double)k * 0.0009775171065493646);
  }
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v13 = 1056964608;
LABEL_30:
    overbrightFactor = *(float *)&v13;
    goto LABEL_31;
  }
  if ( overbright == 4 )
  {
    v13 = 1048576000;
    goto LABEL_30;
  }
LABEL_31:
  for ( m = 0; m < 4096; ++m )
  {
    __libm_sse2_pow();
    v15 = (double)m * 0.0009765625;
    lineartovertex[m] = v15 * overbrightFactor;
    if ( (float)(v15 * overbrightFactor) > 1.0 )
      lineartovertex[m] = 1.0;
    v16 = (int)(float)((float)(v15 * 255.0) * overbrightFactor);
    if ( v16 >= 0 )
    {
      if ( v16 > 255 )
        LOBYTE(v16) = -1;
    }
    else
    {
      LOBYTE(v16) = 0;
    }
    lineartolightmap[m] = v16;
  }
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1035A980
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace server

// ============================================================
// Overlay from matchmaking (Missing functions)
// ============================================================
namespace matchmaking {

//------------------------------------------------------------------------------
// Address: 0x100334D0
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace matchmaking

// ============================================================
// Overlay from matchmaking_ds (Missing functions)
// ============================================================
namespace matchmaking_ds {

//------------------------------------------------------------------------------
// Address: 0x10008D70
// Name: void BuildGammaTable(float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildGammaTable(int a1@<esi>, float gamma, float texGamma, float brightness, int overbright)
{
  float v5; // xmm0_4
  int v6; // esi
  int v7; // eax
  int i; // esi
  float v9; // xmm0_4
  float v10; // xmm0_4
  int v11; // eax
  int j; // esi
  float v13; // xmm0_4
  int v14; // esi
  int v15; // xmm0_4
  int v16; // esi
  float v17; // xmm1_4
  int v18; // eax
  __int128 v19; // [esp-4h] [ebp-14h]
  long double v20; // [esp-4h] [ebp-14h]
  long double v21; // [esp-4h] [ebp-14h]
  long double g; // [esp+4h] [ebp-Ch]
  long double ga; // [esp+4h] [ebp-Ch]
  float g3; // [esp+Ch] [ebp-4h]
  float overbrightFactor; // [esp+1Ch] [ebp+Ch]

  v5 = gamma;
  if ( gamma > 3.0 )
    v5 = 3.0;
  *((float *)&v19 + 2) = 1.0 / v5;
  *((float *)&v19 + 3) = *((float *)&v19 + 2) * texGamma;
  if ( brightness > 0.0 )
  {
    LODWORD(v19) = a1;
    if ( brightness <= 1.0 )
    {
      v6 = 0;
      g3 = 0.125 - (float)(brightness * brightness) * 0.075;
    }
    else
    {
      g3 = 0.050000001;
      v6 = 0;
    }
  }
  else
  {
    LODWORD(v19) = a1;
    g3 = 0.125;
    v6 = 0;
  }
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v7 = (int)(float)((float)((float)v6 * 0.0039215689) * 255.0);
    if ( v7 >= 0 )
    {
      if ( v7 > 255 )
        LOBYTE(v7) = -1;
    }
    else
    {
      LOBYTE(v7) = 0;
    }
    texgammatable[v6++] = v7;
  }
  while ( v6 < 256 );
  for ( i = 0; i < 1024; ++i )
  {
    v9 = (double)i * 0.0009775171065493646;
    if ( brightness > 1.0 )
      v9 = v9 * brightness;
    if ( g3 < v9 )
      v10 = (float)((float)(v9 - g3) / (float)(1.0 - g3)) * 0.875 + 0.125;
    else
      v10 = (float)(v9 / g3) * 0.125;
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v11 = (int)(float)(v10 * 255.0);
    if ( v11 >= 0 )
    {
      if ( v11 > 255 )
        v11 = 255;
    }
    else
    {
      v11 = 0;
    }
    lineartoscreen[i] = v11;
  }
  for ( j = 0; j < 256; ++j )
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    texturetolinear[j] = (float)j * 0.0039215689;
    __libm_sse2_pow(x: v20, y: g);
    v13 = (float)j * 0.0039215689;
    g_Mathlib_LinearToGamma[j] = v13;
    __libm_sse2_pow(x: v21, y: ga);
    g_Mathlib_GammaToLinear[j] = v13;
  }
  v14 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / texGamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    lineartotexture[v14] = 255 * (int)((double)v14 * 0.0009775171065493646);
    ++v14;
  }
  while ( v14 < 1024 );
  overbrightFactor = 1.0;
  if ( overbright == 2 )
  {
    v15 = 1056964608;
LABEL_32:
    overbrightFactor = *(float *)&v15;
    goto LABEL_33;
  }
  if ( overbright == 4 )
  {
    v15 = 1048576000;
    goto LABEL_32;
  }
LABEL_33:
  v16 = 0;
  *(double *)((char *)&v19 + 4) = 1.0 / gamma;
  do
  {
    __libm_sse2_pow(x: *(long double *)&v19, y: *((long double *)&v19 + 1));
    v17 = (double)v16 * 0.0009765625;
    lineartovertex[v16] = v17 * overbrightFactor;
    if ( (float)(v17 * overbrightFactor) > 1.0 )
      lineartovertex[v16] = 1.0;
    v18 = (int)(float)((float)(v17 * 255.0) * overbrightFactor);
    if ( v18 >= 0 )
    {
      if ( v18 > 255 )
        LOBYTE(v18) = -1;
    }
    else
    {
      LOBYTE(v18) = 0;
    }
    lineartolightmap[v16++] = v18;
  }
  while ( v16 < 4096 );
}

} // namespace matchmaking_ds
