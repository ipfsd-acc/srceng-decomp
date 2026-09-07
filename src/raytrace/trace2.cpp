// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: raytrace/trace2.cpp
// Functions: 3
// ============================================================

#include "raytrace\trace2.h"

//------------------------------------------------------------------------------
// Address: 0x0042E0E0
// Name: public: void RayTracingEnvironment::FlushStreamEntry(class RayStream __near &,int,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge RayTracingEnvironment::FlushStreamEntry(
        RayTracingEnvironment *this@<ecx>,
        int a2@<ebp>,
        RayStream *s,
        int msk,
        RTECullMode_t cullMode)
{
  char *v5; // eax
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm2
  __m128 v9; // xmm0
  RayTracingSingleResult *v10; // eax
  RayTracingSingleResult *v11; // eax
  RayTracingSingleResult *v12; // eax
  RayTracingSingleResult *v13; // eax
  _DWORD v14[3]; // [esp-Ch] [ebp-6Ch] BYREF
  _BYTE tmpresult[92]; // [esp+0h] [ebp-60h] OVERLAPPED
  _UNKNOWN *retaddr; // [esp+60h] [ebp+0h]

  *(_DWORD *)&tmpresult[84] = a2;
  *(_DWORD *)&tmpresult[88] = retaddr;
  v5 = (char *)s + 96 * msk;
  v6 = _mm_sqrt_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(*((__m128 *)v5 + 13), *((__m128 *)v5 + 13)),
             _mm_mul_ps(*((__m128 *)v5 + 14), *((__m128 *)v5 + 14))),
           _mm_mul_ps(*((__m128 *)v5 + 15), *((__m128 *)v5 + 15))));
  v7 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(Four_Zeros, v6), Four_Epsilons), v6);
  v8 = _mm_rcp_ps(v7);
  v9 = _mm_sub_ps(_mm_add_ps(v8, v8), _mm_mul_ps(_mm_mul_ps(v8, v8), v7));
  *((__m128 *)v5 + 13) = _mm_mul_ps(*((__m128 *)v5 + 13), v9);
  *((__m128 *)v5 + 14) = _mm_mul_ps(*((__m128 *)v5 + 14), v9);
  *((__m128 *)v5 + 15) = _mm_mul_ps(*((__m128 *)v5 + 15), v9);
  *(__m128 *)&tmpresult[68] = v6;
  RayTracingEnvironment::Trace4Rays(
    this,
    rays: (const FourRays *)(v5 + 160),
    TMin: Four_Zeros,
    TMax: v6,
    DirectionSignMask: msk,
    rslt_out: (RayTracingResult *)v14,
    skip_id: -1,
    pCallback: nullptr,
    cullMode);
  v10 = s->PendingStreamOutputs[msk][0];
  v10->ray_length = *(float *)&tmpresult[68];
  LODWORD(v10->surface_normal.x) = v14[0];
  v10->surface_normal.y = *(float *)&tmpresult[4];
  v10->surface_normal.z = *(float *)&tmpresult[20];
  v10->HitID = *(_DWORD *)&tmpresult[36];
  v10->HitDistance = *(float *)&tmpresult[52];
  v11 = s->PendingStreamOutputs[msk][1];
  v11->ray_length = *(float *)&tmpresult[72];
  LODWORD(v11->surface_normal.x) = v14[1];
  v11->surface_normal.y = *(float *)&tmpresult[8];
  v11->surface_normal.z = *(float *)&tmpresult[24];
  v11->HitID = *(_DWORD *)&tmpresult[40];
  v11->HitDistance = *(float *)&tmpresult[56];
  v12 = s->PendingStreamOutputs[msk][2];
  v12->ray_length = *(float *)&tmpresult[76];
  LODWORD(v12->surface_normal.x) = v14[2];
  v12->surface_normal.y = *(float *)&tmpresult[12];
  v12->surface_normal.z = *(float *)&tmpresult[28];
  v12->HitID = *(_DWORD *)&tmpresult[44];
  v12->HitDistance = *(float *)&tmpresult[60];
  v13 = s->PendingStreamOutputs[msk][3];
  v13->ray_length = *(float *)&tmpresult[80];
  v13->surface_normal.x = *(float *)tmpresult;
  v13->surface_normal.y = *(float *)&tmpresult[16];
  v13->surface_normal.z = *(float *)&tmpresult[32];
  v13->HitID = *(_DWORD *)&tmpresult[48];
  v13->HitDistance = *(float *)&tmpresult[64];
  s->n_in_stream[msk] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042E2C0
// Name: public: void RayTracingEnvironment::AddToRayStream(class RayStream __near &,class Vector const __near &,class Vector const __near &,struct RayTracingSingleResult __near *,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::AddToRayStream(
        RayTracingEnvironment *this,
        RayStream *s,
        const Vector *start,
        const Vector *end,
        RayTracingSingleResult *rslt_out,
        RTECullMode_t cullMode)
{
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  int v9; // edx
  int v10; // edi
  int v11; // esi
  double z; // st7
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  v6 = end->y - start->y;
  v7 = end->z - start->z;
  v8 = end->x - start->x;
  v9 = v8 < 0.0;
  if ( v6 < 0.0 )
    v9 += 2;
  if ( v7 < 0.0 )
    v9 += 4;
  v10 = s->n_in_stream[v9];
  v11 = v10 + 24 * v9;
  s->PendingRays[0].origin.x.m128_i32[v11] = LODWORD(start->x);
  s->PendingRays[0].origin.y.m128_f32[v11] = start->y;
  z = start->z;
  s->PendingRays[0].direction.x.m128_f32[v11] = v8;
  s->PendingRays[v9].origin.z.m128_f32[v10] = z;
  s->PendingRays[0].direction.y.m128_f32[v11] = v6;
  s->PendingRays[0].direction.z.m128_f32[v11] = v7;
  s->PendingStreamOutputs[v9][v10] = rslt_out;
  if ( v10 == 3 )
    RayTracingEnvironment::FlushStreamEntry(this, a2: (int)&savedregs, s, msk: v9, cullMode);
  else
    ++s->n_in_stream[v9];
}

//------------------------------------------------------------------------------
// Address: 0x0042E3A0
// Name: public: void RayTracingEnvironment::FinishRayStream(class RayStream __near &,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::FinishRayStream(
        RayTracingEnvironment *this,
        RayStream *s,
        RTECullMode_t cullMode)
{
  RayStream *v3; // eax
  int v4; // ecx
  RayStream *v5; // edi
  __m128 *p_y; // esi
  int v7; // ebx
  RayTracingSingleResult **v8; // ecx
  float *v9; // eax
  unsigned int v10; // edx
  RayTracingSingleResult **v11; // edx
  float *v12; // eax
  int v13; // ecx
  int c; // [esp+10h] [ebp-Ch]
  int v16; // [esp+14h] [ebp-8h]
  int msk; // [esp+18h] [ebp-4h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  v3 = s;
  v4 = 0;
  msk = 0;
  v16 = 0;
  v5 = s;
  p_y = &s->PendingRays[0].origin.y;
  do
  {
    v7 = v3->n_in_stream[v4];
    if ( v7 != 0 )
    {
      c = v3->n_in_stream[v4];
      if ( v7 < 4 )
      {
        if ( 4 - v7 >= 4 )
        {
          v8 = &v3->PendingStreamOutputs[v4][v7];
          v9 = &v3->PendingRays[0].origin.y.m128_f32[v7 + v16];
          v10 = ((unsigned int)-v7 >> 2) + 1;
          c = v7 + 4 * v10;
          do
          {
            v9 += 4;
            *(v9 - 8) = p_y[-1].m128_f32[0];
            v8 += 4;
            --v10;
            *(v9 - 4) = p_y->m128_f32[0];
            *v9 = p_y[1].m128_f32[0];
            v9[4] = p_y[2].m128_f32[0];
            v9[8] = p_y[3].m128_f32[0];
            v9[12] = p_y[4].m128_f32[0];
            *(v8 - 4) = v5->PendingStreamOutputs[0][0];
            *(v9 - 7) = p_y[-1].m128_f32[0];
            *(v9 - 3) = p_y->m128_f32[0];
            v9[1] = p_y[1].m128_f32[0];
            v9[5] = p_y[2].m128_f32[0];
            v9[9] = p_y[3].m128_f32[0];
            v9[13] = p_y[4].m128_f32[0];
            *(v8 - 3) = v5->PendingStreamOutputs[0][0];
            *(v9 - 6) = p_y[-1].m128_f32[0];
            *(v9 - 2) = p_y->m128_f32[0];
            v9[2] = p_y[1].m128_f32[0];
            v9[6] = p_y[2].m128_f32[0];
            v9[10] = p_y[3].m128_f32[0];
            v9[14] = p_y[4].m128_f32[0];
            *(v8 - 2) = v5->PendingStreamOutputs[0][0];
            *(v9 - 5) = p_y[-1].m128_f32[0];
            *(v9 - 1) = p_y->m128_f32[0];
            v9[3] = p_y[1].m128_f32[0];
            v9[7] = p_y[2].m128_f32[0];
            v9[11] = p_y[3].m128_f32[0];
            v9[15] = p_y[4].m128_f32[0];
            *(v8 - 1) = v5->PendingStreamOutputs[0][0];
          }
          while ( v10 != 0 );
          v3 = s;
          v4 = msk;
        }
        if ( c < 4 )
        {
          v11 = &v3->PendingStreamOutputs[v4][c];
          v12 = &v3->PendingRays[0].origin.y.m128_f32[c + v16];
          v13 = 4 - c;
          do
          {
            *(++v12 - 5) = p_y[-1].m128_f32[0];
            ++v11;
            --v13;
            *(v12 - 1) = p_y->m128_f32[0];
            v12[3] = p_y[1].m128_f32[0];
            v12[7] = p_y[2].m128_f32[0];
            v12[11] = p_y[3].m128_f32[0];
            v12[15] = p_y[4].m128_f32[0];
            *(v11 - 1) = v5->PendingStreamOutputs[0][0];
          }
          while ( v13 != 0 );
          v4 = msk;
          v3 = s;
        }
      }
      RayTracingEnvironment::FlushStreamEntry(this, a2: (int)&savedregs, s: v3, msk: v4, cullMode);
      v3 = s;
      v4 = msk;
    }
    v16 += 24;
    ++v4;
    p_y += 6;
    v5 = (RayStream *)((char *)v5 + 16);
    msk = v4;
  }
  while ( v4 < 8 );
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102A7920
// Name: public: void RayTracingEnvironment::FlushStreamEntry(class RayStream __near &,int,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge RayTracingEnvironment::FlushStreamEntry(
        RayTracingEnvironment *this@<ecx>,
        int a2@<ebp>,
        RayStream *s,
        int msk,
        RTECullMode_t cullMode)
{
  char *v5; // eax
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm2
  __m128 v9; // xmm0
  RayTracingSingleResult *v10; // eax
  RayTracingSingleResult *v11; // eax
  RayTracingSingleResult *v12; // eax
  RayTracingSingleResult *v13; // eax
  _DWORD v14[3]; // [esp-Ch] [ebp-6Ch] BYREF
  _BYTE tmpresult[92]; // [esp+0h] [ebp-60h] OVERLAPPED
  _UNKNOWN *retaddr; // [esp+60h] [ebp+0h]

  *(_DWORD *)&tmpresult[84] = a2;
  *(_DWORD *)&tmpresult[88] = retaddr;
  v5 = (char *)s + 96 * msk;
  v6 = _mm_sqrt_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(*((__m128 *)v5 + 13), *((__m128 *)v5 + 13)),
             _mm_mul_ps(*((__m128 *)v5 + 14), *((__m128 *)v5 + 14))),
           _mm_mul_ps(*((__m128 *)v5 + 15), *((__m128 *)v5 + 15))));
  v7 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(Four_Zeros, v6), Four_Epsilons), v6);
  v8 = _mm_rcp_ps(v7);
  v9 = _mm_sub_ps(_mm_add_ps(v8, v8), _mm_mul_ps(_mm_mul_ps(v8, v8), v7));
  *((__m128 *)v5 + 13) = _mm_mul_ps(*((__m128 *)v5 + 13), v9);
  *((__m128 *)v5 + 14) = _mm_mul_ps(*((__m128 *)v5 + 14), v9);
  *((__m128 *)v5 + 15) = _mm_mul_ps(*((__m128 *)v5 + 15), v9);
  *(__m128 *)&tmpresult[68] = v6;
  RayTracingEnvironment::Trace4Rays(
    this,
    TMin: Four_Zeros,
    TMax: v6,
    rays: (const FourRays *)(v5 + 160),
    DirectionSignMask: msk,
    rslt_out: (RayTracingResult *)v14,
    skip_id: -1,
    pCallback: nullptr,
    cullMode);
  v10 = s->PendingStreamOutputs[msk][0];
  v10->ray_length = *(float *)&tmpresult[68];
  LODWORD(v10->surface_normal.x) = v14[0];
  v10->surface_normal.y = *(float *)&tmpresult[4];
  v10->surface_normal.z = *(float *)&tmpresult[20];
  v10->HitID = *(_DWORD *)&tmpresult[36];
  v10->HitDistance = *(float *)&tmpresult[52];
  v11 = s->PendingStreamOutputs[msk][1];
  v11->ray_length = *(float *)&tmpresult[72];
  LODWORD(v11->surface_normal.x) = v14[1];
  v11->surface_normal.y = *(float *)&tmpresult[8];
  v11->surface_normal.z = *(float *)&tmpresult[24];
  v11->HitID = *(_DWORD *)&tmpresult[40];
  v11->HitDistance = *(float *)&tmpresult[56];
  v12 = s->PendingStreamOutputs[msk][2];
  v12->ray_length = *(float *)&tmpresult[76];
  LODWORD(v12->surface_normal.x) = v14[2];
  v12->surface_normal.y = *(float *)&tmpresult[12];
  v12->surface_normal.z = *(float *)&tmpresult[28];
  v12->HitID = *(_DWORD *)&tmpresult[44];
  v12->HitDistance = *(float *)&tmpresult[60];
  v13 = s->PendingStreamOutputs[msk][3];
  v13->ray_length = *(float *)&tmpresult[80];
  v13->surface_normal.x = *(float *)tmpresult;
  v13->surface_normal.y = *(float *)&tmpresult[16];
  v13->surface_normal.z = *(float *)&tmpresult[32];
  v13->HitID = *(_DWORD *)&tmpresult[48];
  v13->HitDistance = *(float *)&tmpresult[64];
  s->n_in_stream[msk] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x102A7B00
// Name: public: void RayTracingEnvironment::AddToRayStream(class RayStream __near &,class Vector const __near &,class Vector const __near &,struct RayTracingSingleResult __near *,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::AddToRayStream(
        RayTracingEnvironment *this,
        RayStream *s,
        const Vector *start,
        const Vector *end,
        RayTracingSingleResult *rslt_out,
        RTECullMode_t cullMode)
{
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  int v9; // edx
  int v10; // edi
  int v11; // esi
  double z; // st7
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  v6 = end->y - start->y;
  v7 = end->z - start->z;
  v8 = end->x - start->x;
  v9 = v8 < 0.0;
  if ( v6 < 0.0 )
    v9 += 2;
  if ( v7 < 0.0 )
    v9 += 4;
  v10 = s->n_in_stream[v9];
  v11 = v10 + 24 * v9;
  s->PendingRays[0].origin.x.m128_i32[v11] = LODWORD(start->x);
  s->PendingRays[0].origin.y.m128_f32[v11] = start->y;
  z = start->z;
  s->PendingRays[0].direction.x.m128_f32[v11] = v8;
  s->PendingRays[v9].origin.z.m128_f32[v10] = z;
  s->PendingRays[0].direction.y.m128_f32[v11] = v6;
  s->PendingRays[0].direction.z.m128_f32[v11] = v7;
  s->PendingStreamOutputs[v9][v10] = rslt_out;
  if ( v10 == 3 )
    RayTracingEnvironment::FlushStreamEntry(this, a2: (int)&savedregs, s, msk: v9, cullMode);
  else
    ++s->n_in_stream[v9];
}

//------------------------------------------------------------------------------
// Address: 0x102A7BE0
// Name: public: void RayTracingEnvironment::FinishRayStream(class RayStream __near &,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::FinishRayStream(
        RayTracingEnvironment *this,
        RayStream *s,
        RTECullMode_t cullMode)
{
  RayStream *v3; // eax
  int v4; // ecx
  RayStream *v5; // edi
  __m128 *p_y; // esi
  int v7; // ebx
  RayTracingSingleResult **v8; // ecx
  float *v9; // eax
  unsigned int v10; // edx
  RayTracingSingleResult **v11; // edx
  float *v12; // eax
  int v13; // ecx
  int c; // [esp+10h] [ebp-Ch]
  int v16; // [esp+14h] [ebp-8h]
  int msk; // [esp+18h] [ebp-4h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  v3 = s;
  v4 = 0;
  msk = 0;
  v16 = 0;
  v5 = s;
  p_y = &s->PendingRays[0].origin.y;
  do
  {
    v7 = v3->n_in_stream[v4];
    if ( v7 != 0 )
    {
      c = v3->n_in_stream[v4];
      if ( v7 < 4 )
      {
        if ( 4 - v7 >= 4 )
        {
          v8 = &v3->PendingStreamOutputs[v4][v7];
          v9 = &v3->PendingRays[0].origin.y.m128_f32[v7 + v16];
          v10 = ((unsigned int)-v7 >> 2) + 1;
          c = v7 + 4 * v10;
          do
          {
            v9 += 4;
            *(v9 - 8) = p_y[-1].m128_f32[0];
            v8 += 4;
            --v10;
            *(v9 - 4) = p_y->m128_f32[0];
            *v9 = p_y[1].m128_f32[0];
            v9[4] = p_y[2].m128_f32[0];
            v9[8] = p_y[3].m128_f32[0];
            v9[12] = p_y[4].m128_f32[0];
            *(v8 - 4) = v5->PendingStreamOutputs[0][0];
            *(v9 - 7) = p_y[-1].m128_f32[0];
            *(v9 - 3) = p_y->m128_f32[0];
            v9[1] = p_y[1].m128_f32[0];
            v9[5] = p_y[2].m128_f32[0];
            v9[9] = p_y[3].m128_f32[0];
            v9[13] = p_y[4].m128_f32[0];
            *(v8 - 3) = v5->PendingStreamOutputs[0][0];
            *(v9 - 6) = p_y[-1].m128_f32[0];
            *(v9 - 2) = p_y->m128_f32[0];
            v9[2] = p_y[1].m128_f32[0];
            v9[6] = p_y[2].m128_f32[0];
            v9[10] = p_y[3].m128_f32[0];
            v9[14] = p_y[4].m128_f32[0];
            *(v8 - 2) = v5->PendingStreamOutputs[0][0];
            *(v9 - 5) = p_y[-1].m128_f32[0];
            *(v9 - 1) = p_y->m128_f32[0];
            v9[3] = p_y[1].m128_f32[0];
            v9[7] = p_y[2].m128_f32[0];
            v9[11] = p_y[3].m128_f32[0];
            v9[15] = p_y[4].m128_f32[0];
            *(v8 - 1) = v5->PendingStreamOutputs[0][0];
          }
          while ( v10 != 0 );
          v3 = s;
          v4 = msk;
        }
        if ( c < 4 )
        {
          v11 = &v3->PendingStreamOutputs[v4][c];
          v12 = &v3->PendingRays[0].origin.y.m128_f32[c + v16];
          v13 = 4 - c;
          do
          {
            *(++v12 - 5) = p_y[-1].m128_f32[0];
            ++v11;
            --v13;
            *(v12 - 1) = p_y->m128_f32[0];
            v12[3] = p_y[1].m128_f32[0];
            v12[7] = p_y[2].m128_f32[0];
            v12[11] = p_y[3].m128_f32[0];
            v12[15] = p_y[4].m128_f32[0];
            *(v11 - 1) = v5->PendingStreamOutputs[0][0];
          }
          while ( v13 != 0 );
          v4 = msk;
          v3 = s;
        }
      }
      RayTracingEnvironment::FlushStreamEntry(this, a2: (int)&savedregs, s: v3, msk: v4, cullMode);
      v3 = s;
      v4 = msk;
    }
    v16 += 24;
    ++v4;
    p_y += 6;
    v5 = (RayStream *)((char *)v5 + 16);
    msk = v4;
  }
  while ( v4 < 8 );
}

} // namespace hammer_dll

// ============================================================
// Overlay from lightworld (Missing functions)
// ============================================================
namespace lightworld {

//------------------------------------------------------------------------------
// Address: 0x0040B600
// Name: public: void RayTracingEnvironment::FlushStreamEntry(class RayStream __near &,int,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge RayTracingEnvironment::FlushStreamEntry(
        RayTracingEnvironment *this@<ecx>,
        int a2@<ebp>,
        RayStream *s,
        int msk,
        RTECullMode_t cullMode)
{
  char *v5; // eax
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm2
  __m128 v9; // xmm0
  RayTracingSingleResult *v10; // eax
  RayTracingSingleResult *v11; // eax
  RayTracingSingleResult *v12; // eax
  RayTracingSingleResult *v13; // eax
  _DWORD v14[3]; // [esp-Ch] [ebp-6Ch] BYREF
  _BYTE tmpresult[92]; // [esp+0h] [ebp-60h] OVERLAPPED
  _UNKNOWN *retaddr; // [esp+60h] [ebp+0h]

  *(_DWORD *)&tmpresult[84] = a2;
  *(_DWORD *)&tmpresult[88] = retaddr;
  v5 = (char *)s + 96 * msk;
  v6 = _mm_sqrt_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(*((__m128 *)v5 + 13), *((__m128 *)v5 + 13)),
             _mm_mul_ps(*((__m128 *)v5 + 14), *((__m128 *)v5 + 14))),
           _mm_mul_ps(*((__m128 *)v5 + 15), *((__m128 *)v5 + 15))));
  v7 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(Four_Zeros, v6), Four_Epsilons), v6);
  v8 = _mm_rcp_ps(v7);
  v9 = _mm_sub_ps(_mm_add_ps(v8, v8), _mm_mul_ps(_mm_mul_ps(v8, v8), v7));
  *((__m128 *)v5 + 13) = _mm_mul_ps(*((__m128 *)v5 + 13), v9);
  *((__m128 *)v5 + 14) = _mm_mul_ps(*((__m128 *)v5 + 14), v9);
  *((__m128 *)v5 + 15) = _mm_mul_ps(*((__m128 *)v5 + 15), v9);
  *(__m128 *)&tmpresult[68] = v6;
  RayTracingEnvironment::Trace4Rays(
    this,
    rays: (const FourRays *)(v5 + 160),
    TMin: Four_Zeros,
    TMax: v6,
    DirectionSignMask: msk,
    rslt_out: (RayTracingResult *)v14,
    skip_id: -1,
    pCallback: nullptr,
    cullMode);
  v10 = s->PendingStreamOutputs[msk][0];
  v10->ray_length = *(float *)&tmpresult[68];
  LODWORD(v10->surface_normal.x) = v14[0];
  v10->surface_normal.y = *(float *)&tmpresult[4];
  v10->surface_normal.z = *(float *)&tmpresult[20];
  v10->HitID = *(_DWORD *)&tmpresult[36];
  v10->HitDistance = *(float *)&tmpresult[52];
  v11 = s->PendingStreamOutputs[msk][1];
  v11->ray_length = *(float *)&tmpresult[72];
  LODWORD(v11->surface_normal.x) = v14[1];
  v11->surface_normal.y = *(float *)&tmpresult[8];
  v11->surface_normal.z = *(float *)&tmpresult[24];
  v11->HitID = *(_DWORD *)&tmpresult[40];
  v11->HitDistance = *(float *)&tmpresult[56];
  v12 = s->PendingStreamOutputs[msk][2];
  v12->ray_length = *(float *)&tmpresult[76];
  LODWORD(v12->surface_normal.x) = v14[2];
  v12->surface_normal.y = *(float *)&tmpresult[12];
  v12->surface_normal.z = *(float *)&tmpresult[28];
  v12->HitID = *(_DWORD *)&tmpresult[44];
  v12->HitDistance = *(float *)&tmpresult[60];
  v13 = s->PendingStreamOutputs[msk][3];
  v13->ray_length = *(float *)&tmpresult[80];
  v13->surface_normal.x = *(float *)tmpresult;
  v13->surface_normal.y = *(float *)&tmpresult[16];
  v13->surface_normal.z = *(float *)&tmpresult[32];
  v13->HitID = *(_DWORD *)&tmpresult[48];
  v13->HitDistance = *(float *)&tmpresult[64];
  s->n_in_stream[msk] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040B7E0
// Name: public: void RayTracingEnvironment::AddToRayStream(class RayStream __near &,class Vector const __near &,class Vector const __near &,struct RayTracingSingleResult __near *,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::AddToRayStream(
        RayTracingEnvironment *this,
        RayStream *s,
        const Vector *start,
        const Vector *end,
        RayTracingSingleResult *rslt_out,
        RTECullMode_t cullMode)
{
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  int v9; // edx
  int v10; // edi
  int v11; // esi
  double z; // st7
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  v6 = end->y - start->y;
  v7 = end->z - start->z;
  v8 = end->x - start->x;
  v9 = v8 < 0.0;
  if ( v6 < 0.0 )
    v9 += 2;
  if ( v7 < 0.0 )
    v9 += 4;
  v10 = s->n_in_stream[v9];
  v11 = v10 + 24 * v9;
  s->PendingRays[0].origin.x.m128_i32[v11] = LODWORD(start->x);
  s->PendingRays[0].origin.y.m128_f32[v11] = start->y;
  z = start->z;
  s->PendingRays[0].direction.x.m128_f32[v11] = v8;
  s->PendingRays[v9].origin.z.m128_f32[v10] = z;
  s->PendingRays[0].direction.y.m128_f32[v11] = v6;
  s->PendingRays[0].direction.z.m128_f32[v11] = v7;
  s->PendingStreamOutputs[v9][v10] = rslt_out;
  if ( v10 == 3 )
    RayTracingEnvironment::FlushStreamEntry(this, a2: (int)&savedregs, s, msk: v9, cullMode);
  else
    ++s->n_in_stream[v9];
}

//------------------------------------------------------------------------------
// Address: 0x0040B8C0
// Name: public: void RayTracingEnvironment::FinishRayStream(class RayStream __near &,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::FinishRayStream(
        RayTracingEnvironment *this,
        RayStream *s,
        RTECullMode_t cullMode)
{
  RayStream *v3; // eax
  int v4; // ecx
  RayStream *v5; // edi
  __m128 *p_y; // esi
  int v7; // ebx
  RayTracingSingleResult **v8; // ecx
  float *v9; // eax
  unsigned int v10; // edx
  RayTracingSingleResult **v11; // edx
  float *v12; // eax
  int v13; // ecx
  int c; // [esp+10h] [ebp-Ch]
  int v16; // [esp+14h] [ebp-8h]
  int msk; // [esp+18h] [ebp-4h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  v3 = s;
  v4 = 0;
  msk = 0;
  v16 = 0;
  v5 = s;
  p_y = &s->PendingRays[0].origin.y;
  do
  {
    v7 = v3->n_in_stream[v4];
    if ( v7 != 0 )
    {
      c = v3->n_in_stream[v4];
      if ( v7 < 4 )
      {
        if ( 4 - v7 >= 4 )
        {
          v8 = &v3->PendingStreamOutputs[v4][v7];
          v9 = &v3->PendingRays[0].origin.y.m128_f32[v7 + v16];
          v10 = ((unsigned int)-v7 >> 2) + 1;
          c = v7 + 4 * v10;
          do
          {
            v9 += 4;
            *(v9 - 8) = p_y[-1].m128_f32[0];
            v8 += 4;
            --v10;
            *(v9 - 4) = p_y->m128_f32[0];
            *v9 = p_y[1].m128_f32[0];
            v9[4] = p_y[2].m128_f32[0];
            v9[8] = p_y[3].m128_f32[0];
            v9[12] = p_y[4].m128_f32[0];
            *(v8 - 4) = v5->PendingStreamOutputs[0][0];
            *(v9 - 7) = p_y[-1].m128_f32[0];
            *(v9 - 3) = p_y->m128_f32[0];
            v9[1] = p_y[1].m128_f32[0];
            v9[5] = p_y[2].m128_f32[0];
            v9[9] = p_y[3].m128_f32[0];
            v9[13] = p_y[4].m128_f32[0];
            *(v8 - 3) = v5->PendingStreamOutputs[0][0];
            *(v9 - 6) = p_y[-1].m128_f32[0];
            *(v9 - 2) = p_y->m128_f32[0];
            v9[2] = p_y[1].m128_f32[0];
            v9[6] = p_y[2].m128_f32[0];
            v9[10] = p_y[3].m128_f32[0];
            v9[14] = p_y[4].m128_f32[0];
            *(v8 - 2) = v5->PendingStreamOutputs[0][0];
            *(v9 - 5) = p_y[-1].m128_f32[0];
            *(v9 - 1) = p_y->m128_f32[0];
            v9[3] = p_y[1].m128_f32[0];
            v9[7] = p_y[2].m128_f32[0];
            v9[11] = p_y[3].m128_f32[0];
            v9[15] = p_y[4].m128_f32[0];
            *(v8 - 1) = v5->PendingStreamOutputs[0][0];
          }
          while ( v10 != 0 );
          v3 = s;
          v4 = msk;
        }
        if ( c < 4 )
        {
          v11 = &v3->PendingStreamOutputs[v4][c];
          v12 = &v3->PendingRays[0].origin.y.m128_f32[c + v16];
          v13 = 4 - c;
          do
          {
            *(++v12 - 5) = p_y[-1].m128_f32[0];
            ++v11;
            --v13;
            *(v12 - 1) = p_y->m128_f32[0];
            v12[3] = p_y[1].m128_f32[0];
            v12[7] = p_y[2].m128_f32[0];
            v12[11] = p_y[3].m128_f32[0];
            v12[15] = p_y[4].m128_f32[0];
            *(v11 - 1) = v5->PendingStreamOutputs[0][0];
          }
          while ( v13 != 0 );
          v4 = msk;
          v3 = s;
        }
      }
      RayTracingEnvironment::FlushStreamEntry(this, a2: (int)&savedregs, s: v3, msk: v4, cullMode);
      v3 = s;
      v4 = msk;
    }
    v16 += 24;
    ++v4;
    p_y += 6;
    v5 = (RayStream *)((char *)v5 + 16);
    msk = v4;
  }
  while ( v4 < 8 );
}

} // namespace lightworld

// ============================================================
// Overlay from subdbaker (Missing functions)
// ============================================================
namespace subdbaker {

//------------------------------------------------------------------------------
// Address: 0x004C2680
// Name: public: void RayTracingEnvironment::FlushStreamEntry(class RayStream __near &,int,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge RayTracingEnvironment::FlushStreamEntry(
        RayTracingEnvironment *this@<ecx>,
        int a2@<ebp>,
        RayStream *s,
        int msk,
        RTECullMode_t cullMode)
{
  char *v5; // eax
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm2
  __m128 v9; // xmm0
  RayTracingSingleResult *v10; // eax
  RayTracingSingleResult *v11; // eax
  RayTracingSingleResult *v12; // eax
  RayTracingSingleResult *v13; // eax
  _DWORD v14[3]; // [esp-Ch] [ebp-6Ch] BYREF
  _BYTE tmpresult[92]; // [esp+0h] [ebp-60h] OVERLAPPED
  _UNKNOWN *retaddr; // [esp+60h] [ebp+0h]

  *(_DWORD *)&tmpresult[84] = a2;
  *(_DWORD *)&tmpresult[88] = retaddr;
  v5 = (char *)s + 96 * msk;
  v6 = _mm_sqrt_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(*((__m128 *)v5 + 13), *((__m128 *)v5 + 13)),
             _mm_mul_ps(*((__m128 *)v5 + 14), *((__m128 *)v5 + 14))),
           _mm_mul_ps(*((__m128 *)v5 + 15), *((__m128 *)v5 + 15))));
  v7 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(Four_Zeros, v6), Four_Epsilons), v6);
  v8 = _mm_rcp_ps(v7);
  v9 = _mm_sub_ps(_mm_add_ps(v8, v8), _mm_mul_ps(_mm_mul_ps(v8, v8), v7));
  *((__m128 *)v5 + 13) = _mm_mul_ps(*((__m128 *)v5 + 13), v9);
  *((__m128 *)v5 + 14) = _mm_mul_ps(*((__m128 *)v5 + 14), v9);
  *((__m128 *)v5 + 15) = _mm_mul_ps(*((__m128 *)v5 + 15), v9);
  *(__m128 *)&tmpresult[68] = v6;
  RayTracingEnvironment::Trace4Rays(
    this,
    rays: (const FourRays *)(v5 + 160),
    TMin: Four_Zeros,
    TMax: v6,
    DirectionSignMask: msk,
    rslt_out: (RayTracingResult *)v14,
    skip_id: -1,
    pCallback: nullptr,
    cullMode);
  v10 = s->PendingStreamOutputs[msk][0];
  v10->ray_length = *(float *)&tmpresult[68];
  LODWORD(v10->surface_normal.x) = v14[0];
  v10->surface_normal.y = *(float *)&tmpresult[4];
  v10->surface_normal.z = *(float *)&tmpresult[20];
  v10->HitID = *(_DWORD *)&tmpresult[36];
  v10->HitDistance = *(float *)&tmpresult[52];
  v11 = s->PendingStreamOutputs[msk][1];
  v11->ray_length = *(float *)&tmpresult[72];
  LODWORD(v11->surface_normal.x) = v14[1];
  v11->surface_normal.y = *(float *)&tmpresult[8];
  v11->surface_normal.z = *(float *)&tmpresult[24];
  v11->HitID = *(_DWORD *)&tmpresult[40];
  v11->HitDistance = *(float *)&tmpresult[56];
  v12 = s->PendingStreamOutputs[msk][2];
  v12->ray_length = *(float *)&tmpresult[76];
  LODWORD(v12->surface_normal.x) = v14[2];
  v12->surface_normal.y = *(float *)&tmpresult[12];
  v12->surface_normal.z = *(float *)&tmpresult[28];
  v12->HitID = *(_DWORD *)&tmpresult[44];
  v12->HitDistance = *(float *)&tmpresult[60];
  v13 = s->PendingStreamOutputs[msk][3];
  v13->ray_length = *(float *)&tmpresult[80];
  v13->surface_normal.x = *(float *)tmpresult;
  v13->surface_normal.y = *(float *)&tmpresult[16];
  v13->surface_normal.z = *(float *)&tmpresult[32];
  v13->HitID = *(_DWORD *)&tmpresult[48];
  v13->HitDistance = *(float *)&tmpresult[64];
  s->n_in_stream[msk] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004C2860
// Name: public: void RayTracingEnvironment::AddToRayStream(class RayStream __near &,class Vector const __near &,class Vector const __near &,struct RayTracingSingleResult __near *,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::AddToRayStream(
        RayTracingEnvironment *this,
        RayStream *s,
        const Vector *start,
        const Vector *end,
        RayTracingSingleResult *rslt_out,
        RTECullMode_t cullMode)
{
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  int v9; // edx
  int v10; // edi
  int v11; // esi
  double z; // st7
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  v6 = end->y - start->y;
  v7 = end->z - start->z;
  v8 = end->x - start->x;
  v9 = v8 < 0.0;
  if ( v6 < 0.0 )
    v9 += 2;
  if ( v7 < 0.0 )
    v9 += 4;
  v10 = s->n_in_stream[v9];
  v11 = v10 + 24 * v9;
  s->PendingRays[0].origin.x.m128_i32[v11] = LODWORD(start->x);
  s->PendingRays[0].origin.y.m128_f32[v11] = start->y;
  z = start->z;
  s->PendingRays[0].direction.x.m128_f32[v11] = v8;
  s->PendingRays[v9].origin.z.m128_f32[v10] = z;
  s->PendingRays[0].direction.y.m128_f32[v11] = v6;
  s->PendingRays[0].direction.z.m128_f32[v11] = v7;
  s->PendingStreamOutputs[v9][v10] = rslt_out;
  if ( v10 == 3 )
    RayTracingEnvironment::FlushStreamEntry(this, a2: (int)&savedregs, s, msk: v9, cullMode);
  else
    ++s->n_in_stream[v9];
}

//------------------------------------------------------------------------------
// Address: 0x004C2940
// Name: public: void RayTracingEnvironment::FinishRayStream(class RayStream __near &,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::FinishRayStream(
        RayTracingEnvironment *this,
        RayStream *s,
        RTECullMode_t cullMode)
{
  RayStream *v3; // eax
  int v4; // ecx
  RayStream *v5; // edi
  __m128 *p_y; // esi
  int v7; // ebx
  RayTracingSingleResult **v8; // ecx
  float *v9; // eax
  unsigned int v10; // edx
  RayTracingSingleResult **v11; // edx
  float *v12; // eax
  int v13; // ecx
  int c; // [esp+10h] [ebp-Ch]
  int v16; // [esp+14h] [ebp-8h]
  int msk; // [esp+18h] [ebp-4h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  v3 = s;
  v4 = 0;
  msk = 0;
  v16 = 0;
  v5 = s;
  p_y = &s->PendingRays[0].origin.y;
  do
  {
    v7 = v3->n_in_stream[v4];
    if ( v7 != 0 )
    {
      c = v3->n_in_stream[v4];
      if ( v7 < 4 )
      {
        if ( 4 - v7 >= 4 )
        {
          v8 = &v3->PendingStreamOutputs[v4][v7];
          v9 = &v3->PendingRays[0].origin.y.m128_f32[v7 + v16];
          v10 = ((unsigned int)-v7 >> 2) + 1;
          c = v7 + 4 * v10;
          do
          {
            v9 += 4;
            *(v9 - 8) = p_y[-1].m128_f32[0];
            v8 += 4;
            --v10;
            *(v9 - 4) = p_y->m128_f32[0];
            *v9 = p_y[1].m128_f32[0];
            v9[4] = p_y[2].m128_f32[0];
            v9[8] = p_y[3].m128_f32[0];
            v9[12] = p_y[4].m128_f32[0];
            *(v8 - 4) = v5->PendingStreamOutputs[0][0];
            *(v9 - 7) = p_y[-1].m128_f32[0];
            *(v9 - 3) = p_y->m128_f32[0];
            v9[1] = p_y[1].m128_f32[0];
            v9[5] = p_y[2].m128_f32[0];
            v9[9] = p_y[3].m128_f32[0];
            v9[13] = p_y[4].m128_f32[0];
            *(v8 - 3) = v5->PendingStreamOutputs[0][0];
            *(v9 - 6) = p_y[-1].m128_f32[0];
            *(v9 - 2) = p_y->m128_f32[0];
            v9[2] = p_y[1].m128_f32[0];
            v9[6] = p_y[2].m128_f32[0];
            v9[10] = p_y[3].m128_f32[0];
            v9[14] = p_y[4].m128_f32[0];
            *(v8 - 2) = v5->PendingStreamOutputs[0][0];
            *(v9 - 5) = p_y[-1].m128_f32[0];
            *(v9 - 1) = p_y->m128_f32[0];
            v9[3] = p_y[1].m128_f32[0];
            v9[7] = p_y[2].m128_f32[0];
            v9[11] = p_y[3].m128_f32[0];
            v9[15] = p_y[4].m128_f32[0];
            *(v8 - 1) = v5->PendingStreamOutputs[0][0];
          }
          while ( v10 != 0 );
          v3 = s;
          v4 = msk;
        }
        if ( c < 4 )
        {
          v11 = &v3->PendingStreamOutputs[v4][c];
          v12 = &v3->PendingRays[0].origin.y.m128_f32[c + v16];
          v13 = 4 - c;
          do
          {
            *(++v12 - 5) = p_y[-1].m128_f32[0];
            ++v11;
            --v13;
            *(v12 - 1) = p_y->m128_f32[0];
            v12[3] = p_y[1].m128_f32[0];
            v12[7] = p_y[2].m128_f32[0];
            v12[11] = p_y[3].m128_f32[0];
            v12[15] = p_y[4].m128_f32[0];
            *(v11 - 1) = v5->PendingStreamOutputs[0][0];
          }
          while ( v13 != 0 );
          v4 = msk;
          v3 = s;
        }
      }
      RayTracingEnvironment::FlushStreamEntry(this, a2: (int)&savedregs, s: v3, msk: v4, cullMode);
      v3 = s;
      v4 = msk;
    }
    v16 += 24;
    ++v4;
    p_y += 6;
    v5 = (RayStream *)((char *)v5 + 16);
    msk = v4;
  }
  while ( v4 < 8 );
}

} // namespace subdbaker

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00643D50
// Name: public: void RayTracingEnvironment::FlushStreamEntry(class RayStream __near &,int,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge RayTracingEnvironment::FlushStreamEntry(
        RayTracingEnvironment *this@<ecx>,
        int a2@<ebp>,
        RayStream *s,
        int msk,
        RTECullMode_t cullMode)
{
  char *v5; // eax
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm2
  __m128 v9; // xmm0
  RayTracingSingleResult *v10; // eax
  RayTracingSingleResult *v11; // eax
  RayTracingSingleResult *v12; // eax
  RayTracingSingleResult *v13; // eax
  _DWORD v14[3]; // [esp-Ch] [ebp-6Ch] BYREF
  _BYTE tmpresult[92]; // [esp+0h] [ebp-60h] OVERLAPPED
  _UNKNOWN *retaddr; // [esp+60h] [ebp+0h]

  *(_DWORD *)&tmpresult[84] = a2;
  *(_DWORD *)&tmpresult[88] = retaddr;
  v5 = (char *)s + 96 * msk;
  v6 = _mm_sqrt_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(*((__m128 *)v5 + 13), *((__m128 *)v5 + 13)),
             _mm_mul_ps(*((__m128 *)v5 + 14), *((__m128 *)v5 + 14))),
           _mm_mul_ps(*((__m128 *)v5 + 15), *((__m128 *)v5 + 15))));
  v7 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(Four_Zeros, v6), Four_Epsilons), v6);
  v8 = _mm_rcp_ps(v7);
  v9 = _mm_sub_ps(_mm_add_ps(v8, v8), _mm_mul_ps(_mm_mul_ps(v8, v8), v7));
  *((__m128 *)v5 + 13) = _mm_mul_ps(*((__m128 *)v5 + 13), v9);
  *((__m128 *)v5 + 14) = _mm_mul_ps(*((__m128 *)v5 + 14), v9);
  *((__m128 *)v5 + 15) = _mm_mul_ps(*((__m128 *)v5 + 15), v9);
  *(__m128 *)&tmpresult[68] = v6;
  RayTracingEnvironment::Trace4Rays(
    this,
    TMin: Four_Zeros,
    TMax: v6,
    rays: (const FourRays *)(v5 + 160),
    DirectionSignMask: msk,
    rslt_out: (RayTracingResult *)v14,
    skip_id: -1,
    pCallback: nullptr,
    cullMode);
  v10 = s->PendingStreamOutputs[msk][0];
  v10->ray_length = *(float *)&tmpresult[68];
  LODWORD(v10->surface_normal.x) = v14[0];
  v10->surface_normal.y = *(float *)&tmpresult[4];
  v10->surface_normal.z = *(float *)&tmpresult[20];
  v10->HitID = *(_DWORD *)&tmpresult[36];
  v10->HitDistance = *(float *)&tmpresult[52];
  v11 = s->PendingStreamOutputs[msk][1];
  v11->ray_length = *(float *)&tmpresult[72];
  LODWORD(v11->surface_normal.x) = v14[1];
  v11->surface_normal.y = *(float *)&tmpresult[8];
  v11->surface_normal.z = *(float *)&tmpresult[24];
  v11->HitID = *(_DWORD *)&tmpresult[40];
  v11->HitDistance = *(float *)&tmpresult[56];
  v12 = s->PendingStreamOutputs[msk][2];
  v12->ray_length = *(float *)&tmpresult[76];
  LODWORD(v12->surface_normal.x) = v14[2];
  v12->surface_normal.y = *(float *)&tmpresult[12];
  v12->surface_normal.z = *(float *)&tmpresult[28];
  v12->HitID = *(_DWORD *)&tmpresult[44];
  v12->HitDistance = *(float *)&tmpresult[60];
  v13 = s->PendingStreamOutputs[msk][3];
  v13->ray_length = *(float *)&tmpresult[80];
  v13->surface_normal.x = *(float *)tmpresult;
  v13->surface_normal.y = *(float *)&tmpresult[16];
  v13->surface_normal.z = *(float *)&tmpresult[32];
  v13->HitID = *(_DWORD *)&tmpresult[48];
  v13->HitDistance = *(float *)&tmpresult[64];
  s->n_in_stream[msk] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00643F30
// Name: public: void RayTracingEnvironment::AddToRayStream(class RayStream __near &,class Vector const __near &,class Vector const __near &,struct RayTracingSingleResult __near *,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::AddToRayStream(
        RayTracingEnvironment *this,
        RayStream *s,
        const Vector *start,
        const Vector *end,
        RayTracingSingleResult *rslt_out,
        RTECullMode_t cullMode)
{
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  int v9; // edx
  int v10; // edi
  int v11; // esi
  double z; // st7
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  v6 = end->y - start->y;
  v7 = end->z - start->z;
  v8 = end->x - start->x;
  v9 = v8 < 0.0;
  if ( v6 < 0.0 )
    v9 += 2;
  if ( v7 < 0.0 )
    v9 += 4;
  v10 = s->n_in_stream[v9];
  v11 = v10 + 24 * v9;
  s->PendingRays[0].origin.x.m128_i32[v11] = LODWORD(start->x);
  s->PendingRays[0].origin.y.m128_f32[v11] = start->y;
  z = start->z;
  s->PendingRays[0].direction.x.m128_f32[v11] = v8;
  s->PendingRays[v9].origin.z.m128_f32[v10] = z;
  s->PendingRays[0].direction.y.m128_f32[v11] = v6;
  s->PendingRays[0].direction.z.m128_f32[v11] = v7;
  s->PendingStreamOutputs[v9][v10] = rslt_out;
  if ( v10 == 3 )
    RayTracingEnvironment::FlushStreamEntry(this, a2: (int)&savedregs, s, msk: v9, cullMode);
  else
    ++s->n_in_stream[v9];
}

//------------------------------------------------------------------------------
// Address: 0x00644010
// Name: public: void RayTracingEnvironment::FinishRayStream(class RayStream __near &,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::FinishRayStream(
        RayTracingEnvironment *this,
        RayStream *s,
        RTECullMode_t cullMode)
{
  RayStream *v3; // eax
  int v4; // ecx
  RayStream *v5; // edi
  __m128 *p_y; // esi
  int v7; // ebx
  RayTracingSingleResult **v8; // ecx
  float *v9; // eax
  unsigned int v10; // edx
  RayTracingSingleResult **v11; // edx
  float *v12; // eax
  int v13; // ecx
  int c; // [esp+10h] [ebp-Ch]
  int v16; // [esp+14h] [ebp-8h]
  int msk; // [esp+18h] [ebp-4h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  v3 = s;
  v4 = 0;
  msk = 0;
  v16 = 0;
  v5 = s;
  p_y = &s->PendingRays[0].origin.y;
  do
  {
    v7 = v3->n_in_stream[v4];
    if ( v7 != 0 )
    {
      c = v3->n_in_stream[v4];
      if ( v7 < 4 )
      {
        if ( 4 - v7 >= 4 )
        {
          v8 = &v3->PendingStreamOutputs[v4][v7];
          v9 = &v3->PendingRays[0].origin.y.m128_f32[v7 + v16];
          v10 = ((unsigned int)-v7 >> 2) + 1;
          c = v7 + 4 * v10;
          do
          {
            v9 += 4;
            *(v9 - 8) = p_y[-1].m128_f32[0];
            v8 += 4;
            --v10;
            *(v9 - 4) = p_y->m128_f32[0];
            *v9 = p_y[1].m128_f32[0];
            v9[4] = p_y[2].m128_f32[0];
            v9[8] = p_y[3].m128_f32[0];
            v9[12] = p_y[4].m128_f32[0];
            *(v8 - 4) = v5->PendingStreamOutputs[0][0];
            *(v9 - 7) = p_y[-1].m128_f32[0];
            *(v9 - 3) = p_y->m128_f32[0];
            v9[1] = p_y[1].m128_f32[0];
            v9[5] = p_y[2].m128_f32[0];
            v9[9] = p_y[3].m128_f32[0];
            v9[13] = p_y[4].m128_f32[0];
            *(v8 - 3) = v5->PendingStreamOutputs[0][0];
            *(v9 - 6) = p_y[-1].m128_f32[0];
            *(v9 - 2) = p_y->m128_f32[0];
            v9[2] = p_y[1].m128_f32[0];
            v9[6] = p_y[2].m128_f32[0];
            v9[10] = p_y[3].m128_f32[0];
            v9[14] = p_y[4].m128_f32[0];
            *(v8 - 2) = v5->PendingStreamOutputs[0][0];
            *(v9 - 5) = p_y[-1].m128_f32[0];
            *(v9 - 1) = p_y->m128_f32[0];
            v9[3] = p_y[1].m128_f32[0];
            v9[7] = p_y[2].m128_f32[0];
            v9[11] = p_y[3].m128_f32[0];
            v9[15] = p_y[4].m128_f32[0];
            *(v8 - 1) = v5->PendingStreamOutputs[0][0];
          }
          while ( v10 != 0 );
          v3 = s;
          v4 = msk;
        }
        if ( c < 4 )
        {
          v11 = &v3->PendingStreamOutputs[v4][c];
          v12 = &v3->PendingRays[0].origin.y.m128_f32[c + v16];
          v13 = 4 - c;
          do
          {
            *(++v12 - 5) = p_y[-1].m128_f32[0];
            ++v11;
            --v13;
            *(v12 - 1) = p_y->m128_f32[0];
            v12[3] = p_y[1].m128_f32[0];
            v12[7] = p_y[2].m128_f32[0];
            v12[11] = p_y[3].m128_f32[0];
            v12[15] = p_y[4].m128_f32[0];
            *(v11 - 1) = v5->PendingStreamOutputs[0][0];
          }
          while ( v13 != 0 );
          v4 = msk;
          v3 = s;
        }
      }
      RayTracingEnvironment::FlushStreamEntry(this, a2: (int)&savedregs, s: v3, msk: v4, cullMode);
      v3 = s;
      v4 = msk;
    }
    v16 += 24;
    ++v4;
    p_y += 6;
    v5 = (RayStream *)((char *)v5 + 16);
    msk = v4;
  }
  while ( v4 < 8 );
}

} // namespace vmap

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x1007AD80
// Name: public: void RayTracingEnvironment::FlushStreamEntry(class RayStream __near &,int,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __userpurge RayTracingEnvironment::FlushStreamEntry(
        RayTracingEnvironment *this@<ecx>,
        int a2@<ebp>,
        RayStream *s,
        int msk,
        RTECullMode_t cullMode)
{
  char *v5; // eax
  __m128 v6; // xmm1
  __m128 v7; // xmm0
  __m128 v8; // xmm2
  __m128 v9; // xmm0
  RayTracingSingleResult *v10; // eax
  RayTracingSingleResult *v11; // eax
  RayTracingSingleResult *v12; // eax
  RayTracingSingleResult *v13; // eax
  _DWORD v14[3]; // [esp-Ch] [ebp-6Ch] BYREF
  _BYTE tmpresult[92]; // [esp+0h] [ebp-60h] OVERLAPPED
  _UNKNOWN *retaddr; // [esp+60h] [ebp+0h]

  *(_DWORD *)&tmpresult[84] = a2;
  *(_DWORD *)&tmpresult[88] = retaddr;
  v5 = (char *)s + 96 * msk;
  v6 = _mm_sqrt_ps(
         _mm_add_ps(
           _mm_add_ps(
             _mm_mul_ps(*((__m128 *)v5 + 13), *((__m128 *)v5 + 13)),
             _mm_mul_ps(*((__m128 *)v5 + 14), *((__m128 *)v5 + 14))),
           _mm_mul_ps(*((__m128 *)v5 + 15), *((__m128 *)v5 + 15))));
  v7 = _mm_or_ps(_mm_and_ps(_mm_cmpeq_ps(Four_Zeros, v6), Four_Epsilons), v6);
  v8 = _mm_rcp_ps(v7);
  v9 = _mm_sub_ps(_mm_add_ps(v8, v8), _mm_mul_ps(_mm_mul_ps(v8, v8), v7));
  *((__m128 *)v5 + 13) = _mm_mul_ps(*((__m128 *)v5 + 13), v9);
  *((__m128 *)v5 + 14) = _mm_mul_ps(*((__m128 *)v5 + 14), v9);
  *((__m128 *)v5 + 15) = _mm_mul_ps(*((__m128 *)v5 + 15), v9);
  *(__m128 *)&tmpresult[68] = v6;
  RayTracingEnvironment::Trace4Rays(
    this,
    TMin: Four_Zeros,
    TMax: v6,
    rays: (const FourRays *)(v5 + 160),
    DirectionSignMask: msk,
    rslt_out: (RayTracingResult *)v14,
    skip_id: -1,
    pCallback: nullptr,
    cullMode);
  v10 = s->PendingStreamOutputs[msk][0];
  v10->ray_length = *(float *)&tmpresult[68];
  LODWORD(v10->surface_normal.x) = v14[0];
  v10->surface_normal.y = *(float *)&tmpresult[4];
  v10->surface_normal.z = *(float *)&tmpresult[20];
  v10->HitID = *(_DWORD *)&tmpresult[36];
  v10->HitDistance = *(float *)&tmpresult[52];
  v11 = s->PendingStreamOutputs[msk][1];
  v11->ray_length = *(float *)&tmpresult[72];
  LODWORD(v11->surface_normal.x) = v14[1];
  v11->surface_normal.y = *(float *)&tmpresult[8];
  v11->surface_normal.z = *(float *)&tmpresult[24];
  v11->HitID = *(_DWORD *)&tmpresult[40];
  v11->HitDistance = *(float *)&tmpresult[56];
  v12 = s->PendingStreamOutputs[msk][2];
  v12->ray_length = *(float *)&tmpresult[76];
  LODWORD(v12->surface_normal.x) = v14[2];
  v12->surface_normal.y = *(float *)&tmpresult[12];
  v12->surface_normal.z = *(float *)&tmpresult[28];
  v12->HitID = *(_DWORD *)&tmpresult[44];
  v12->HitDistance = *(float *)&tmpresult[60];
  v13 = s->PendingStreamOutputs[msk][3];
  v13->ray_length = *(float *)&tmpresult[80];
  v13->surface_normal.x = *(float *)tmpresult;
  v13->surface_normal.y = *(float *)&tmpresult[16];
  v13->surface_normal.z = *(float *)&tmpresult[32];
  v13->HitID = *(_DWORD *)&tmpresult[48];
  v13->HitDistance = *(float *)&tmpresult[64];
  s->n_in_stream[msk] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1007AF60
// Name: public: void RayTracingEnvironment::AddToRayStream(class RayStream __near &,class Vector const __near &,class Vector const __near &,struct RayTracingSingleResult __near *,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::AddToRayStream(
        RayTracingEnvironment *this,
        RayStream *s,
        const Vector *start,
        const Vector *end,
        RayTracingSingleResult *rslt_out,
        RTECullMode_t cullMode)
{
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm0_4
  int v9; // edx
  int v10; // edi
  int v11; // esi
  double z; // st7
  int savedregs; // [esp+10h] [ebp+0h] BYREF

  v6 = end->y - start->y;
  v7 = end->z - start->z;
  v8 = end->x - start->x;
  v9 = v8 < 0.0;
  if ( v6 < 0.0 )
    v9 += 2;
  if ( v7 < 0.0 )
    v9 += 4;
  v10 = s->n_in_stream[v9];
  v11 = v10 + 24 * v9;
  s->PendingRays[0].origin.x.m128_i32[v11] = LODWORD(start->x);
  s->PendingRays[0].origin.y.m128_f32[v11] = start->y;
  z = start->z;
  s->PendingRays[0].direction.x.m128_f32[v11] = v8;
  s->PendingRays[v9].origin.z.m128_f32[v10] = z;
  s->PendingRays[0].direction.y.m128_f32[v11] = v6;
  s->PendingRays[0].direction.z.m128_f32[v11] = v7;
  s->PendingStreamOutputs[v9][v10] = rslt_out;
  if ( v10 == 3 )
    RayTracingEnvironment::FlushStreamEntry(this, a2: (int)&savedregs, s, msk: v9, cullMode);
  else
    ++s->n_in_stream[v9];
}

//------------------------------------------------------------------------------
// Address: 0x1007B040
// Name: public: void RayTracingEnvironment::FinishRayStream(class RayStream __near &,enum RTECullMode_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall RayTracingEnvironment::FinishRayStream(
        RayTracingEnvironment *this,
        RayStream *s,
        RTECullMode_t cullMode)
{
  RayStream *v3; // eax
  int v4; // ecx
  RayStream *v5; // edi
  __m128 *p_y; // esi
  int v7; // ebx
  RayTracingSingleResult **v8; // ecx
  float *v9; // eax
  unsigned int v10; // edx
  RayTracingSingleResult **v11; // edx
  float *v12; // eax
  int v13; // ecx
  int c; // [esp+10h] [ebp-Ch]
  int v16; // [esp+14h] [ebp-8h]
  int msk; // [esp+18h] [ebp-4h]
  int savedregs; // [esp+1Ch] [ebp+0h] BYREF

  v3 = s;
  v4 = 0;
  msk = 0;
  v16 = 0;
  v5 = s;
  p_y = &s->PendingRays[0].origin.y;
  do
  {
    v7 = v3->n_in_stream[v4];
    if ( v7 != 0 )
    {
      c = v3->n_in_stream[v4];
      if ( v7 < 4 )
      {
        if ( 4 - v7 >= 4 )
        {
          v8 = &v3->PendingStreamOutputs[v4][v7];
          v9 = &v3->PendingRays[0].origin.y.m128_f32[v7 + v16];
          v10 = ((unsigned int)-v7 >> 2) + 1;
          c = v7 + 4 * v10;
          do
          {
            v9 += 4;
            *(v9 - 8) = p_y[-1].m128_f32[0];
            v8 += 4;
            --v10;
            *(v9 - 4) = p_y->m128_f32[0];
            *v9 = p_y[1].m128_f32[0];
            v9[4] = p_y[2].m128_f32[0];
            v9[8] = p_y[3].m128_f32[0];
            v9[12] = p_y[4].m128_f32[0];
            *(v8 - 4) = v5->PendingStreamOutputs[0][0];
            *(v9 - 7) = p_y[-1].m128_f32[0];
            *(v9 - 3) = p_y->m128_f32[0];
            v9[1] = p_y[1].m128_f32[0];
            v9[5] = p_y[2].m128_f32[0];
            v9[9] = p_y[3].m128_f32[0];
            v9[13] = p_y[4].m128_f32[0];
            *(v8 - 3) = v5->PendingStreamOutputs[0][0];
            *(v9 - 6) = p_y[-1].m128_f32[0];
            *(v9 - 2) = p_y->m128_f32[0];
            v9[2] = p_y[1].m128_f32[0];
            v9[6] = p_y[2].m128_f32[0];
            v9[10] = p_y[3].m128_f32[0];
            v9[14] = p_y[4].m128_f32[0];
            *(v8 - 2) = v5->PendingStreamOutputs[0][0];
            *(v9 - 5) = p_y[-1].m128_f32[0];
            *(v9 - 1) = p_y->m128_f32[0];
            v9[3] = p_y[1].m128_f32[0];
            v9[7] = p_y[2].m128_f32[0];
            v9[11] = p_y[3].m128_f32[0];
            v9[15] = p_y[4].m128_f32[0];
            *(v8 - 1) = v5->PendingStreamOutputs[0][0];
          }
          while ( v10 != 0 );
          v3 = s;
          v4 = msk;
        }
        if ( c < 4 )
        {
          v11 = &v3->PendingStreamOutputs[v4][c];
          v12 = &v3->PendingRays[0].origin.y.m128_f32[c + v16];
          v13 = 4 - c;
          do
          {
            *(++v12 - 5) = p_y[-1].m128_f32[0];
            ++v11;
            --v13;
            *(v12 - 1) = p_y->m128_f32[0];
            v12[3] = p_y[1].m128_f32[0];
            v12[7] = p_y[2].m128_f32[0];
            v12[11] = p_y[3].m128_f32[0];
            v12[15] = p_y[4].m128_f32[0];
            *(v11 - 1) = v5->PendingStreamOutputs[0][0];
          }
          while ( v13 != 0 );
          v4 = msk;
          v3 = s;
        }
      }
      RayTracingEnvironment::FlushStreamEntry(this, a2: (int)&savedregs, s: v3, msk: v4, cullMode);
      v3 = s;
      v4 = msk;
    }
    v16 += 24;
    ++v4;
    p_y += 6;
    v5 = (RayStream *)((char *)v5 + 16);
    msk = v4;
  }
  while ( v4 < 8 );
}

} // namespace vrad_dll
