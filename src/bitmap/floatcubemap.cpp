// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: bitmap/floatcubemap.cpp
// Functions: 1
// ============================================================

#include "bitmap\floatcubemap.h"

//------------------------------------------------------------------------------
// Address: 0x10213DB0
// Name: public: void FloatCubeMap_t::WritePFMs(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatCubeMap_t::WritePFMs(FloatCubeMap_t *this, const char *basename)
{
  const char **v3; // esi
  char fnamebuf[512]; // [esp+Ch] [ebp-200h] BYREF

  v3 = namepts;
  do
  {
    sprintf(string: fnamebuf, format: *v3, basename);
    FloatBitMap_t::WritePFM(this: this->face_maps, fname: fnamebuf);
    ++v3;
    this = (FloatCubeMap_t *)((char *)this + 804);
  }
  while ( (int)v3 < (int)&vec2_invalid_158 );
}

// ============================================================
// Overlay from cubelight (Missing functions)
// ============================================================
namespace cubelight {

//------------------------------------------------------------------------------
// Address: 0x00404780
// Name: public: void FloatCubeMap_t::WritePFMs(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatCubeMap_t::WritePFMs(FloatCubeMap_t *this, const char *basename)
{
  const char **v3; // esi
  char fnamebuf[512]; // [esp+Ch] [ebp-200h] BYREF

  v3 = namepts;
  do
  {
    sprintf(string: fnamebuf, format: *v3, basename);
    FloatBitMap_t::WritePFM(this: this->face_maps, fname: fnamebuf);
    ++v3;
    this = (FloatCubeMap_t *)((char *)this + 804);
  }
  while ( (int)v3 < (int)&vec2_invalid_1 );
}

//------------------------------------------------------------------------------
// Address: 0x004047E0
// Name: public: class Vector FloatCubeMap_t::PixelDirection(int,int,int)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall FloatCubeMap_t::PixelDirection(FloatCubeMap_t *this, Vector *result, int face, int x, int y)
{
  FloatBitMap_t *v5; // edx
  float v6; // xmm0_4
  float v7; // xmm0_4
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  float v11; // xmm2_4
  float v12; // xmm0_4
  float v13; // xmm0_4
  float v14; // xmm3_4

  v5 = &this->face_maps[face];
  v6 = (double)y / (double)(v5->m_nRows - 1);
  v7 = v6 * 2.0;
  v8 = face_yvector[face].x * v7;
  v9 = face_yvector[face].y * v7;
  v10 = face_yvector[face].z * v7;
  v11 = face_xvector[face].y;
  v12 = (double)x / (double)(v5->m_nColumns - 1);
  v13 = v12 * 2.0;
  v14 = face_xvector[face].z * v13;
  result->x = face_zvector[face].x + (float)((float)(face_xvector[face].x * v13) + v8);
  result->y = face_zvector[face].y + (float)((float)(v11 * v13) + v9);
  result->z = face_zvector[face].z + (float)(v14 + v10);
  VectorNormalize(vec: result);
  return result;
}

} // namespace cubelight

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10213F80
// Name: public: void FloatCubeMap_t::WritePFMs(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FloatCubeMap_t::WritePFMs(FloatCubeMap_t *this, const char *basename)
{
  const char **v3; // esi
  char fnamebuf[512]; // [esp+Ch] [ebp-200h] BYREF

  v3 = namepts;
  do
  {
    sprintf(string: fnamebuf, format: *v3, basename);
    FloatBitMap_t::WritePFM(this: this->face_maps, fname: fnamebuf);
    ++v3;
    this = (FloatCubeMap_t *)((char *)this + 804);
  }
  while ( (int)v3 < (int)&vec2_invalid_158 );
}

} // namespace engine_xlsp
