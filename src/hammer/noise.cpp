// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/noise.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10088260
// Name: float SmoothNoise2D(int,int)
// Source: json
//------------------------------------------------------------------------------
double __cdecl SmoothNoise2D(int x, int y)
{
  int v2; // eax
  int v3; // ecx
  int v4; // edx
  int v5; // esi
  int v6; // edi
  int v8; // [esp+Ch] [ebp-Ch]
  int v9; // [esp+10h] [ebp-8h]
  int v10; // [esp+14h] [ebp-4h]
  int xa; // [esp+20h] [ebp+8h]

  v2 = x + 57 * y;
  v3 = ((v2 - 58) << 13) ^ (v2 - 58);
  v4 = ((v2 - 56) << 13) ^ (v2 - 56);
  v5 = ((v2 + 56) << 13) ^ (v2 + 56);
  xa = ((v2 + 58) << 13) ^ (v2 + 58);
  v9 = ((v2 - 1) << 13) ^ (v2 - 1);
  v10 = ((v2 + 1) << 13) ^ (v2 + 1);
  v8 = ((v2 - 57) << 13) ^ (v2 - 57);
  v6 = ((v2 + 57) << 13) ^ (v2 + 57);
  return (1.0
        - (double)((v4 * (15731 * v4 * v4 + 789221) - 771171059) & 0x7FFFFFFF) * 9.3132257e-10
        + 1.0
        - (double)((v3 * (15731 * v3 * v3 + 789221) - 771171059) & 0x7FFFFFFF) * 9.3132257e-10
        + 1.0
        - (double)((v5 * (15731 * v5 * v5 + 789221) - 771171059) & 0x7FFFFFFF) * 9.3132257e-10
        + 1.0
        - (double)((xa * (15731 * xa * xa + 789221) - 771171059) & 0x7FFFFFFF) * 9.3132257e-10)
       * 0.0625
       + (1.0
        - (double)((v10 * (15731 * v10 * v10 + 789221) - 771171059) & 0x7FFFFFFF) * 9.3132257e-10
        + 1.0
        - (double)((v9 * (15731 * v9 * v9 + 789221) - 771171059) & 0x7FFFFFFF) * 9.3132257e-10
        + 1.0
        - (double)((v8 * (15731 * v8 * v8 + 789221) - 771171059) & 0x7FFFFFFF) * 9.3132257e-10
        + 1.0
        - (double)((v6 * (15731 * v6 * v6 + 789221) - 771171059) & 0x7FFFFFFF) * 9.3132257e-10)
       * 0.125
       + (1.0
        - 9.3132257e-10
        * (double)((((v2 << 13) ^ v2) * (15731 * ((v2 << 13) ^ v2) * ((v2 << 13) ^ v2) + 789221) - 771171059)
                 & 0x7FFFFFFF))
       * 0.25;
}

//------------------------------------------------------------------------------
// Address: 0x100884A0
// Name: float PerlinNoise2D(float,float,float)
// Source: json
//------------------------------------------------------------------------------
double __cdecl PerlinNoise2D(float x, float y, float rockiness)
{
  float v3; // xmm6_4
  int i; // ebx
  float v5; // xmm1_4
  unsigned int v6; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm2_4
  unsigned int v10; // eax
  float v11; // xmm0_4
  float v12; // xmm5_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  int v15; // edi
  float v16; // xmm2_4
  float v18; // [esp+0h] [ebp-14h]
  float v19; // [esp+4h] [ebp-10h]
  float v20; // [esp+8h] [ebp-Ch]
  float v21; // [esp+Ch] [ebp-8h]

  v3 = 0.0;
  for ( i = 0; i < 3; ++i )
  {
    v5 = 2.0;
    v6 = i;
    if ( i < 0 )
      v6 = -i;
    v7 = 1.0;
    while ( 1 )
    {
      if ( (v6 & 1) != 0 )
        v7 = v7 * v5;
      v6 >>= 1;
      if ( v6 == 0 )
        break;
      v5 = v5 * v5;
    }
    if ( i >= 0 )
      v8 = v7;
    else
      v8 = 1.0 / v7;
    v9 = rockiness;
    v10 = i;
    if ( i < 0 )
      v10 = -i;
    v11 = 1.0;
    while ( 1 )
    {
      if ( (v10 & 1) != 0 )
        v11 = v11 * v9;
      v10 >>= 1;
      if ( v10 == 0 )
        break;
      v9 = v9 * v9;
    }
    if ( i >= 0 )
      v12 = v11;
    else
      v12 = 1.0 / v11;
    v13 = v8 * x;
    v14 = v8 * y;
    v18 = SmoothNoise2D(x: (int)v13, y: (int)v14);
    v19 = SmoothNoise2D(x: (int)v13 + 1, y: (int)v14);
    v15 = (int)v14 + 1;
    v20 = SmoothNoise2D(x: (int)v13, y: v15);
    v21 = SmoothNoise2D(x: (int)v13 + 1, y: v15);
    v16 = (float)((float)((float)((float)(1.0 - (float)(v14 - (float)(int)v14))
                                * (float)((float)((float)(1.0 - (float)(v13 - (float)(int)v13)) * v18)
                                        + (float)(v19 * (float)(v13 - (float)(int)v13))))
                        + (float)((float)((float)((float)(1.0 - (float)(v13 - (float)(int)v13)) * v20)
                                        + (float)(v21 * (float)(v13 - (float)(int)v13)))
                                * (float)(v14 - (float)(int)v14)))
                * v12)
        + v3;
    v3 = v16;
  }
  return v16;
}
