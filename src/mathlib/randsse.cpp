// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mathlib/randsse.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10263370
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&output[6][8] );
}

// ============================================================
// Overlay from MaterialSystem (Missing functions)
// ============================================================
namespace MaterialSystem {

//------------------------------------------------------------------------------
// Address: 0x10252220
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&s_pTokenBuf[648] );
}

} // namespace MaterialSystem

// ============================================================
// Overlay from StudioRender (Missing functions)
// ============================================================
namespace StudioRender {

//------------------------------------------------------------------------------
// Address: 0x10057520
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&s_pTokenBuf[352] );
}

} // namespace StudioRender

// ============================================================
// Overlay from shaderapidx9 (Missing functions)
// ============================================================
namespace shaderapidx9 {

//------------------------------------------------------------------------------
// Address: 0x100D1E40
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&s_StringCharConversion.m_pReplacements[51] );
}

//------------------------------------------------------------------------------
// Address: 0x100D1F40
// Name: _NvAPI_Initialize
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl NvAPI_Initialize()
{
  HMODULE LibraryA; // eax
  void *(__cdecl *nvapi_QueryInterface)(unsigned int); // eax
  int (*v3)(void); // eax

  LibraryA = g_nvapi_hModule;
  if ( g_nvapi_hModule == nullptr )
  {
    LibraryA = LoadLibraryA(lpLibFileName: "nvapi.dll");
    g_nvapi_hModule = LibraryA;
    if ( LibraryA == nullptr )
      return -2;
  }
  nvapi_QueryInterface = (void *(__cdecl *)(unsigned int))GetProcAddress(
                                                            hModule: LibraryA,
                                                            lpProcName: "nvapi_QueryInterface");
  g_nvapi_lpNvAPI_QueryInterface = nvapi_QueryInterface;
  if ( nvapi_QueryInterface != nullptr )
  {
    v3 = (int (*)(void))nvapi_QueryInterface(a1: 22079528u);
    if ( v3 == nullptr || v3() != 0 )
    {
      g_nvapi_lpNvAPI_QueryInterface = nullptr;
      FreeLibrary(hLibModule: g_nvapi_hModule);
      g_nvapi_hModule = nullptr;
      return -1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    FreeLibrary(hLibModule: g_nvapi_hModule);
    g_nvapi_hModule = nullptr;
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100D1FF0
// Name: _NvAPI_Stereo_CreateConfigurationProfileRegistryKey
// Source: linker_block_proximity
//------------------------------------------------------------------------------
NvAPI_Status __cdecl NvAPI_Stereo_CreateConfigurationProfileRegistryKey()
{
  NvAPI_Status (*fp)(void); // eax

  fp = (NvAPI_Status (*)(void))nvapi_vTable[78].fp;
  if ( g_nvapi_lpNvAPI_QueryInterface != nullptr )
  {
    if ( nvapi_vTable[78].fp != nullptr )
      return fp();
    if ( nvapi_vTable[78].loaded != 0 )
      return NVAPI_NO_IMPLEMENTATION;
    fp = (NvAPI_Status (*)(void))g_nvapi_lpNvAPI_QueryInterface(a1: 0xBE7692EC);
    nvapi_vTable[78].fp = (int (__stdcall *)())fp;
    nvapi_vTable[78].loaded = 1;
  }
  if ( fp == nullptr )
    return NVAPI_NO_IMPLEMENTATION;
  return fp();
}

//------------------------------------------------------------------------------
// Address: 0x100D2030
// Name: _NvAPI_Stereo_IsEnabled
// Source: linker_block_proximity
//------------------------------------------------------------------------------
NvAPI_Status __cdecl NvAPI_Stereo_IsEnabled()
{
  NvAPI_Status (*fp)(void); // eax

  fp = (NvAPI_Status (*)(void))nvapi_vTable[84].fp;
  if ( g_nvapi_lpNvAPI_QueryInterface != nullptr )
  {
    if ( nvapi_vTable[84].fp != nullptr )
      return fp();
    if ( nvapi_vTable[84].loaded != 0 )
      return NVAPI_NO_IMPLEMENTATION;
    fp = (NvAPI_Status (*)(void))g_nvapi_lpNvAPI_QueryInterface(a1: 0x348FF8E1u);
    nvapi_vTable[84].fp = (int (__stdcall *)())fp;
    nvapi_vTable[84].loaded = 1;
  }
  if ( fp == nullptr )
    return NVAPI_NO_IMPLEMENTATION;
  return fp();
}

//------------------------------------------------------------------------------
// Address: 0x100D2070
// Name: _NvAPI_Stereo_CreateHandleFromIUnknown
// Source: linker_block_proximity
//------------------------------------------------------------------------------
NvAPI_Status __cdecl NvAPI_Stereo_CreateHandleFromIUnknown()
{
  NvAPI_Status (*fp)(void); // eax

  fp = (NvAPI_Status (*)(void))nvapi_vTable[85].fp;
  if ( g_nvapi_lpNvAPI_QueryInterface != nullptr )
  {
    if ( nvapi_vTable[85].fp != nullptr )
      return fp();
    if ( nvapi_vTable[85].loaded != 0 )
      return NVAPI_NO_IMPLEMENTATION;
    fp = (NvAPI_Status (*)(void))g_nvapi_lpNvAPI_QueryInterface(a1: 0xAC7E37F4);
    nvapi_vTable[85].fp = (int (__stdcall *)())fp;
    nvapi_vTable[85].loaded = 1;
  }
  if ( fp == nullptr )
    return NVAPI_NO_IMPLEMENTATION;
  return fp();
}

//------------------------------------------------------------------------------
// Address: 0x100D20B0
// Name: _NvAPI_Stereo_DestroyHandle
// Source: linker_block_proximity
//------------------------------------------------------------------------------
NvAPI_Status __cdecl NvAPI_Stereo_DestroyHandle()
{
  NvAPI_Status (*fp)(void); // eax

  fp = (NvAPI_Status (*)(void))nvapi_vTable[86].fp;
  if ( g_nvapi_lpNvAPI_QueryInterface != nullptr )
  {
    if ( nvapi_vTable[86].fp != nullptr )
      return fp();
    if ( nvapi_vTable[86].loaded != 0 )
      return NVAPI_NO_IMPLEMENTATION;
    fp = (NvAPI_Status (*)(void))g_nvapi_lpNvAPI_QueryInterface(a1: 0x3A153134u);
    nvapi_vTable[86].fp = (int (__stdcall *)())fp;
    nvapi_vTable[86].loaded = 1;
  }
  if ( fp == nullptr )
    return NVAPI_NO_IMPLEMENTATION;
  return fp();
}

//------------------------------------------------------------------------------
// Address: 0x100D20F0
// Name: _NvAPI_Stereo_IsActivated
// Source: linker_block_proximity
//------------------------------------------------------------------------------
NvAPI_Status __cdecl NvAPI_Stereo_IsActivated()
{
  NvAPI_Status (*fp)(void); // eax

  fp = (NvAPI_Status (*)(void))nvapi_vTable[89].fp;
  if ( g_nvapi_lpNvAPI_QueryInterface != nullptr )
  {
    if ( nvapi_vTable[89].fp != nullptr )
      return fp();
    if ( nvapi_vTable[89].loaded != 0 )
      return NVAPI_NO_IMPLEMENTATION;
    fp = (NvAPI_Status (*)(void))g_nvapi_lpNvAPI_QueryInterface(a1: 0x1FB0BC30u);
    nvapi_vTable[89].fp = (int (__stdcall *)())fp;
    nvapi_vTable[89].loaded = 1;
  }
  if ( fp == nullptr )
    return NVAPI_NO_IMPLEMENTATION;
  return fp();
}

//------------------------------------------------------------------------------
// Address: 0x100D2130
// Name: _NvAPI_Stereo_GetSeparation
// Source: linker_block_proximity
//------------------------------------------------------------------------------
NvAPI_Status __cdecl NvAPI_Stereo_GetSeparation()
{
  NvAPI_Status (*fp)(void); // eax

  fp = (NvAPI_Status (*)(void))nvapi_vTable[90].fp;
  if ( g_nvapi_lpNvAPI_QueryInterface != nullptr )
  {
    if ( nvapi_vTable[90].fp != nullptr )
      return fp();
    if ( nvapi_vTable[90].loaded != 0 )
      return NVAPI_NO_IMPLEMENTATION;
    fp = (NvAPI_Status (*)(void))g_nvapi_lpNvAPI_QueryInterface(a1: 0x451F2134u);
    nvapi_vTable[90].fp = (int (__stdcall *)())fp;
    nvapi_vTable[90].loaded = 1;
  }
  if ( fp == nullptr )
    return NVAPI_NO_IMPLEMENTATION;
  return fp();
}

//------------------------------------------------------------------------------
// Address: 0x100D2170
// Name: _NvAPI_Stereo_GetConvergence
// Source: linker_block_proximity
//------------------------------------------------------------------------------
NvAPI_Status __cdecl NvAPI_Stereo_GetConvergence()
{
  NvAPI_Status (*fp)(void); // eax

  fp = (NvAPI_Status (*)(void))nvapi_vTable[94].fp;
  if ( g_nvapi_lpNvAPI_QueryInterface != nullptr )
  {
    if ( nvapi_vTable[94].fp != nullptr )
      return fp();
    if ( nvapi_vTable[94].loaded != 0 )
      return NVAPI_NO_IMPLEMENTATION;
    fp = (NvAPI_Status (*)(void))g_nvapi_lpNvAPI_QueryInterface(a1: 0x4AB00934u);
    nvapi_vTable[94].fp = (int (__stdcall *)())fp;
    nvapi_vTable[94].loaded = 1;
  }
  if ( fp == nullptr )
    return NVAPI_NO_IMPLEMENTATION;
  return fp();
}

//------------------------------------------------------------------------------
// Address: 0x100D21B0
// Name: _NvAPI_Stereo_GetEyeSeparation
// Source: linker_block_proximity
//------------------------------------------------------------------------------
NvAPI_Status __cdecl NvAPI_Stereo_GetEyeSeparation()
{
  NvAPI_Status (*fp)(void); // eax

  fp = (NvAPI_Status (*)(void))nvapi_vTable[104].fp;
  if ( g_nvapi_lpNvAPI_QueryInterface != nullptr )
  {
    if ( nvapi_vTable[104].fp != nullptr )
      return fp();
    if ( nvapi_vTable[104].loaded != 0 )
      return NVAPI_NO_IMPLEMENTATION;
    fp = (NvAPI_Status (*)(void))g_nvapi_lpNvAPI_QueryInterface(a1: 0xCE653127);
    nvapi_vTable[104].fp = (int (__stdcall *)())fp;
    nvapi_vTable[104].loaded = 1;
  }
  if ( fp == nullptr )
    return NVAPI_NO_IMPLEMENTATION;
  return fp();
}

} // namespace shaderapidx9

// ============================================================
// Overlay from bsppack (Missing functions)
// ============================================================
namespace bsppack {

//------------------------------------------------------------------------------
// Address: 0x1001E3B0
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace bsppack

// ============================================================
// Overlay from bspzip (Missing functions)
// ============================================================
namespace bspzip {

//------------------------------------------------------------------------------
// Address: 0x00413380
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace bspzip

// ============================================================
// Overlay from choreogen (Missing functions)
// ============================================================
namespace choreogen {

//------------------------------------------------------------------------------
// Address: 0x00412000
// Name: public: void SIMDRandStreamContext::Seed(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SIMDRandStreamContext::Seed(SIMDRandStreamContext *this, unsigned int seed)
{
  float *v3; // edx
  int i; // esi
  unsigned int v5; // eax
  unsigned int v6; // eax

  this->m_pRand_J = &this->m_RandY[23];
  this->m_pRand_K = &this->m_RandY[54];
  v3 = &this->m_RandY[0].m128_f32[2];
  for ( i = 55; i != 0; --i )
  {
    *(v3 - 2) = (double)HIWORD(seed) * 0.0000152587890625;
    v5 = -1153374675 - 1153374675 * seed;
    *(v3 - 1) = (double)HIWORD(v5) * 0.0000152587890625;
    *v3 = (double)((-1153374675 - 1153374675 * v5) >> 16) * 0.0000152587890625;
    v6 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v5);
    v3[1] = (double)HIWORD(v6) * 0.0000152587890625;
    v3 += 4;
    seed = -1153374675 - 1153374675 * v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004120F0
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // edi
  SIMDRandStreamContext *v2; // esi

  v1 = 0;
  v2 = s_SIMDRandContexts;
  do
  {
    SIMDRandStreamContext::Seed(this: v2++, seed: v1 + seed);
    ++v1;
  }
  while ( (int)v2 < (int)s_nRandContextsInUse );
}

} // namespace choreogen

// ============================================================
// Overlay from concatworlds (Missing functions)
// ============================================================
namespace concatworlds {

//------------------------------------------------------------------------------
// Address: 0x00406E60
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace concatworlds

// ============================================================
// Overlay from cubelight (Missing functions)
// ============================================================
namespace cubelight {

//------------------------------------------------------------------------------
// Address: 0x0041EFE0
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace cubelight

// ============================================================
// Overlay from dedicated (Missing functions)
// ============================================================
namespace dedicated {

//------------------------------------------------------------------------------
// Address: 0x1002C100
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace dedicated

// ============================================================
// Overlay from Dist2alpha (Missing functions)
// ============================================================
namespace Dist2alpha {

//------------------------------------------------------------------------------
// Address: 0x0042C450
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace Dist2alpha

// ============================================================
// Overlay from dumpworld (Missing functions)
// ============================================================
namespace dumpworld {

//------------------------------------------------------------------------------
// Address: 0x00406EF0
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace dumpworld

// ============================================================
// Overlay from dmxedit (Missing functions)
// ============================================================
namespace dmxedit {

//------------------------------------------------------------------------------
// Address: 0x00490A50
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace dmxedit

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102633A0
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&output[6][8] );
}

} // namespace engine_xlsp

// ============================================================
// Overlay from glview (Missing functions)
// ============================================================
namespace glview {

//------------------------------------------------------------------------------
// Address: 0x00405F90
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace glview

// ============================================================
// Overlay from height2normal (Missing functions)
// ============================================================
namespace height2normal {

//------------------------------------------------------------------------------
// Address: 0x0042B1B0
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace height2normal

// ============================================================
// Overlay from height2ssbump (Missing functions)
// ============================================================
namespace height2ssbump {

//------------------------------------------------------------------------------
// Address: 0x0042DC70
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace height2ssbump

// ============================================================
// Overlay from hlfaceposer (Missing functions)
// ============================================================
namespace hlfaceposer {

//------------------------------------------------------------------------------
// Address: 0x004C0E60
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace hlfaceposer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x102050B0
// Name: public: union __m128 SIMDRandStreamContext::RandSIMD(void)
// Source: json
//------------------------------------------------------------------------------
__m128 *__thiscall SIMDRandStreamContext::RandSIMD(SIMDRandStreamContext *this, __m128 *result)
{
  __m128 *m_pRand_K; // eax
  __m128 v3; // xmm0
  __m128 v4; // xmm0

  m_pRand_K = this->m_pRand_K;
  v3 = _mm_add_ps(*this->m_pRand_J, *m_pRand_K);
  v4 = _mm_sub_ps(v3, _mm_and_ps(_mm_cmple_ps(Four_Ones, v3), Four_Ones));
  *m_pRand_K = v4;
  if ( --this->m_pRand_J < (__m128 *)this )
    this->m_pRand_J = &this->m_RandY[54];
  if ( --this->m_pRand_K < (__m128 *)this )
    this->m_pRand_K = &this->m_RandY[54];
  *result = v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10205120
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&r_eyes.m_pszDefaultValue );
}

//------------------------------------------------------------------------------
// Address: 0x10205220
// Name: union __m128 RandSIMD(int)
// Source: json
//------------------------------------------------------------------------------
__m128 *__usercall RandSIMD@<eax>(int a1@<ebp>, __m128 *result)
{
  __m128 v3; // [esp-10h] [ebp-1Ch] BYREF
  int v4; // [esp+0h] [ebp-Ch]
  void *v5; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v4 = a1;
  v5 = retaddr;
  return SIMDRandStreamContext::RandSIMD(this: &s_SIMDRandContexts[(_DWORD)result], result: &v3);
}

//------------------------------------------------------------------------------
// Address: 0x10205260
// Name: int GetSIMDRandContext(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl GetSIMDRandContext()
{
  unsigned int v0; // ecx
  volatile int *v1; // edx

LABEL_1:
  v0 = 0;
  v1 = s_nRandContextsInUse;
  while ( *v1 != 0 || _InterlockedCompareExchange(v1, 1, 0) != 0 )
  {
    ++v0;
    ++v1;
    if ( v0 >= 0x20 )
    {
      _ThreadSleep(a1: 0);
      goto LABEL_1;
    }
  }
  return v0;
}

//------------------------------------------------------------------------------
// Address: 0x102052B0
// Name: void ReleaseSIMDRandContext(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReleaseSIMDRandContext(int nContext)
{
  s_nRandContextsInUse[nContext] = 0;
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x0049B840
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace hlmv

// ============================================================
// Overlay from lightworld (Missing functions)
// ============================================================
namespace lightworld {

//------------------------------------------------------------------------------
// Address: 0x0040B190
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace lightworld

// ============================================================
// Overlay from matchmaking_ds (Missing functions)
// ============================================================
namespace matchmaking_ds {

//------------------------------------------------------------------------------
// Address: 0x10004DC0
// Name: public: void SIMDRandStreamContext::Seed(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SIMDRandStreamContext::Seed(SIMDRandStreamContext *this, unsigned int seed)
{
  float *v3; // edx
  int i; // esi
  unsigned int v5; // eax
  unsigned int v6; // eax

  this->m_pRand_J = &this->m_RandY[23];
  this->m_pRand_K = &this->m_RandY[54];
  v3 = &this->m_RandY[0].m128_f32[2];
  for ( i = 55; i != 0; --i )
  {
    *(v3 - 2) = (double)HIWORD(seed) * 0.0000152587890625;
    v5 = -1153374675 - 1153374675 * seed;
    *(v3 - 1) = (double)HIWORD(v5) * 0.0000152587890625;
    *v3 = (double)((-1153374675 - 1153374675 * v5) >> 16) * 0.0000152587890625;
    v6 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v5);
    v3[1] = (double)HIWORD(v6) * 0.0000152587890625;
    v3 += 4;
    seed = -1153374675 - 1153374675 * v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004EB0
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // edi
  SIMDRandStreamContext *v2; // esi

  v1 = 0;
  v2 = s_SIMDRandContexts;
  do
  {
    SIMDRandStreamContext::Seed(this: v2++, seed: v1 + seed);
    ++v1;
  }
  while ( (int)v2 < (int)s_nRandContextsInUse );
}

} // namespace matchmaking_ds

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x00527BF0
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace makegamedata

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x004E06F0
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace mdlcompile

// ============================================================
// Overlay from meshutilstest (Missing functions)
// ============================================================
namespace meshutilstest {

//------------------------------------------------------------------------------
// Address: 0x00406960
// Name: public: void SIMDRandStreamContext::Seed(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SIMDRandStreamContext::Seed(SIMDRandStreamContext *this, unsigned int seed)
{
  float *v3; // edx
  int i; // esi
  unsigned int v5; // eax
  unsigned int v6; // eax

  this->m_pRand_J = &this->m_RandY[23];
  this->m_pRand_K = &this->m_RandY[54];
  v3 = &this->m_RandY[0].m128_f32[2];
  for ( i = 55; i != 0; --i )
  {
    *(v3 - 2) = (double)HIWORD(seed) * 0.0000152587890625;
    v5 = -1153374675 - 1153374675 * seed;
    *(v3 - 1) = (double)HIWORD(v5) * 0.0000152587890625;
    *v3 = (double)((-1153374675 - 1153374675 * v5) >> 16) * 0.0000152587890625;
    v6 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v5);
    v3[1] = (double)HIWORD(v6) * 0.0000152587890625;
    v3 += 4;
    seed = -1153374675 - 1153374675 * v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406A50
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // edi
  SIMDRandStreamContext *v2; // esi

  v1 = 0;
  v2 = s_SIMDRandContexts;
  do
  {
    SIMDRandStreamContext::Seed(this: v2++, seed: v1 + seed);
    ++v1;
  }
  while ( (int)v2 < (int)s_nRandContextsInUse );
}

} // namespace meshutilstest

// ============================================================
// Overlay from mksheet (Missing functions)
// ============================================================
namespace mksheet {

//------------------------------------------------------------------------------
// Address: 0x00463E50
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace mksheet

// ============================================================
// Overlay from modelbrowser (Missing functions)
// ============================================================
namespace modelbrowser {

//------------------------------------------------------------------------------
// Address: 0x0040B4B0
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace modelbrowser

// ============================================================
// Overlay from motionmapper (Missing functions)
// ============================================================
namespace motionmapper {

//------------------------------------------------------------------------------
// Address: 0x0040C9B0
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace motionmapper

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00465DE0
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace particle_import

// ============================================================
// Overlay from pcfmanager (Missing functions)
// ============================================================
namespace pcfmanager {

//------------------------------------------------------------------------------
// Address: 0x00460740
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace pcfmanager

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x004691E0
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace phogen

// ============================================================
// Overlay from ps3shaderoptimizer (Missing functions)
// ============================================================
namespace ps3shaderoptimizer {

//------------------------------------------------------------------------------
// Address: 0x00417540
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace ps3shaderoptimizer

// ============================================================
// Overlay from scenemanager (Missing functions)
// ============================================================
namespace scenemanager {

//------------------------------------------------------------------------------
// Address: 0x004286C0
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace scenemanager

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x004C5040
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace sceneviewer

// ============================================================
// Overlay from ScratchPad3DViewer (Missing functions)
// ============================================================
namespace ScratchPad3DViewer {

//------------------------------------------------------------------------------
// Address: 0x00409350
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace ScratchPad3DViewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00469DB0
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace sfmgen

// ============================================================
// Overlay from shaderapidx10 (Missing functions)
// ============================================================
namespace shaderapidx10 {

//------------------------------------------------------------------------------
// Address: 0x100422C0
// Name: public: void SIMDRandStreamContext::Seed(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SIMDRandStreamContext::Seed(SIMDRandStreamContext *this, unsigned int seed)
{
  float *v3; // edx
  int i; // esi
  unsigned int v5; // eax
  unsigned int v6; // eax

  this->m_pRand_J = &this->m_RandY[23];
  this->m_pRand_K = &this->m_RandY[54];
  v3 = &this->m_RandY[0].m128_f32[2];
  for ( i = 55; i != 0; --i )
  {
    *(v3 - 2) = (double)HIWORD(seed) * 0.0000152587890625;
    v5 = -1153374675 - 1153374675 * seed;
    *(v3 - 1) = (double)HIWORD(v5) * 0.0000152587890625;
    *v3 = (double)((-1153374675 - 1153374675 * v5) >> 16) * 0.0000152587890625;
    v6 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v5);
    v3[1] = (double)HIWORD(v6) * 0.0000152587890625;
    v3 += 4;
    seed = -1153374675 - 1153374675 * v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100423B0
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // edi
  SIMDRandStreamContext *v2; // esi

  v1 = 0;
  v2 = s_SIMDRandContexts;
  do
  {
    SIMDRandStreamContext::Seed(this: v2++, seed: v1 + seed);
    ++v1;
  }
  while ( (int)v2 < (int)s_nRandContextsInUse );
}

} // namespace shaderapidx10

// ============================================================
// Overlay from simdtest (Missing functions)
// ============================================================
namespace simdtest {

//------------------------------------------------------------------------------
// Address: 0x00401CA0
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&LastJobName[736] );
}

} // namespace simdtest

// ============================================================
// Overlay from stdshader_dbg (Missing functions)
// ============================================================
namespace stdshader_dbg {

//------------------------------------------------------------------------------
// Address: 0x10002B70
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&s_StringCharConversion.m_pList[136] );
}

} // namespace stdshader_dbg

// ============================================================
// Overlay from stdshader_dx9 (Missing functions)
// ============================================================
namespace stdshader_dx9 {

//------------------------------------------------------------------------------
// Address: 0x10049310
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&s_StringCharConversion.m_pList[136] );
}

} // namespace stdshader_dx9

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x004D9AB0
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace studiomdl

// ============================================================
// Overlay from tgadiff (Missing functions)
// ============================================================
namespace tgadiff {

//------------------------------------------------------------------------------
// Address: 0x0042AC20
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace tgadiff

// ============================================================
// Overlay from tgamse (Missing functions)
// ============================================================
namespace tgamse {

//------------------------------------------------------------------------------
// Address: 0x0042A870
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace tgamse

// ============================================================
// Overlay from vbsp (Missing functions)
// ============================================================
namespace vbsp {

//------------------------------------------------------------------------------
// Address: 0x00455860
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace vbsp

// ============================================================
// Overlay from vbsp2 (Missing functions)
// ============================================================
namespace vbsp2 {

//------------------------------------------------------------------------------
// Address: 0x00405880
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace vbsp2

// ============================================================
// Overlay from vbspinfo (Missing functions)
// ============================================================
namespace vbspinfo {

//------------------------------------------------------------------------------
// Address: 0x004140B0
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace vbspinfo

// ============================================================
// Overlay from vcdupdate (Missing functions)
// ============================================================
namespace vcdupdate {

//------------------------------------------------------------------------------
// Address: 0x00411610
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace vcdupdate

// ============================================================
// Overlay from vguimatsurface (Missing functions)
// ============================================================
namespace vguimatsurface {

//------------------------------------------------------------------------------
// Address: 0x10041B90
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace vguimatsurface

// ============================================================
// Overlay from vgui_editor (Missing functions)
// ============================================================
namespace vgui_editor {

//------------------------------------------------------------------------------
// Address: 0x004102C0
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace vgui_editor

// ============================================================
// Overlay from vgui_perftest (Missing functions)
// ============================================================
namespace vgui_perftest {

//------------------------------------------------------------------------------
// Address: 0x00430C30
// Name: public: void SIMDRandStreamContext::Seed(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SIMDRandStreamContext::Seed(SIMDRandStreamContext *this, unsigned int seed)
{
  float *v3; // edx
  int i; // esi
  unsigned int v5; // eax
  unsigned int v6; // eax

  this->m_pRand_J = &this->m_RandY[23];
  this->m_pRand_K = &this->m_RandY[54];
  v3 = &this->m_RandY[0].m128_f32[2];
  for ( i = 55; i != 0; --i )
  {
    *(v3 - 2) = (double)HIWORD(seed) * 0.0000152587890625;
    v5 = -1153374675 - 1153374675 * seed;
    *(v3 - 1) = (double)HIWORD(v5) * 0.0000152587890625;
    *v3 = (double)((-1153374675 - 1153374675 * v5) >> 16) * 0.0000152587890625;
    v6 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v5);
    v3[1] = (double)HIWORD(v6) * 0.0000152587890625;
    v3 += 4;
    seed = -1153374675 - 1153374675 * v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00430D20
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // edi
  SIMDRandStreamContext *v2; // esi

  v1 = 0;
  v2 = s_SIMDRandContexts;
  do
  {
    SIMDRandStreamContext::Seed(this: v2++, seed: v1 + seed);
    ++v1;
  }
  while ( (int)v2 < (int)s_nRandContextsInUse );
}

} // namespace vgui_perftest

// ============================================================
// Overlay from videocache (Missing functions)
// ============================================================
namespace videocache {

//------------------------------------------------------------------------------
// Address: 0x00414760
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace videocache

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x0056FEA0
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace vmap

// ============================================================
// Overlay from vphysics (Missing functions)
// ============================================================
namespace vphysics {

//------------------------------------------------------------------------------
// Address: 0x100AB5D0
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace vphysics

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10078410
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&s_StringCharConversion.m_pReplacements[45] );
}

} // namespace vrad_dll

// ============================================================
// Overlay from vscript_python (Missing functions)
// ============================================================
namespace vscript_python {

//------------------------------------------------------------------------------
// Address: 0x100094E0
// Name: public: void SIMDRandStreamContext::Seed(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SIMDRandStreamContext::Seed(SIMDRandStreamContext *this, unsigned int seed)
{
  float *v3; // edx
  int i; // esi
  unsigned int v5; // eax
  unsigned int v6; // eax

  this->m_pRand_J = &this->m_RandY[23];
  this->m_pRand_K = &this->m_RandY[54];
  v3 = &this->m_RandY[0].m128_f32[2];
  for ( i = 55; i != 0; --i )
  {
    *(v3 - 2) = (double)HIWORD(seed) * 0.0000152587890625;
    v5 = -1153374675 - 1153374675 * seed;
    *(v3 - 1) = (double)HIWORD(v5) * 0.0000152587890625;
    *v3 = (double)((-1153374675 - 1153374675 * v5) >> 16) * 0.0000152587890625;
    v6 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v5);
    v3[1] = (double)HIWORD(v6) * 0.0000152587890625;
    v3 += 4;
    seed = -1153374675 - 1153374675 * v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100095D0
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // edi
  SIMDRandStreamContext *v2; // esi

  v1 = 0;
  v2 = s_SIMDRandContexts;
  do
  {
    SIMDRandStreamContext::Seed(this: v2++, seed: v1 + seed);
    ++v1;
  }
  while ( (int)v2 < (int)s_nRandContextsInUse );
}

} // namespace vscript_python

// ============================================================
// Overlay from vtex_dll (Missing functions)
// ============================================================
namespace vtex_dll {

//------------------------------------------------------------------------------
// Address: 0x10096A50
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace vtex_dll

// ============================================================
// Overlay from vtf2tga (Missing functions)
// ============================================================
namespace vtf2tga {

//------------------------------------------------------------------------------
// Address: 0x0042B0C0
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace vtf2tga

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x1001B310
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace vvis_dll

// ============================================================
// Overlay from worldrenderertest (Missing functions)
// ============================================================
namespace worldrenderertest {

//------------------------------------------------------------------------------
// Address: 0x0040EC00
// Name: public: void SIMDRandStreamContext::Seed(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall SIMDRandStreamContext::Seed(SIMDRandStreamContext *this, unsigned int seed)
{
  float *v3; // edx
  int i; // esi
  unsigned int v5; // eax
  unsigned int v6; // eax

  this->m_pRand_J = &this->m_RandY[23];
  this->m_pRand_K = &this->m_RandY[54];
  v3 = &this->m_RandY[0].m128_f32[2];
  for ( i = 55; i != 0; --i )
  {
    *(v3 - 2) = (double)HIWORD(seed) * 0.0000152587890625;
    v5 = -1153374675 - 1153374675 * seed;
    *(v3 - 1) = (double)HIWORD(v5) * 0.0000152587890625;
    *v3 = (double)((-1153374675 - 1153374675 * v5) >> 16) * 0.0000152587890625;
    v6 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v5);
    v3[1] = (double)HIWORD(v6) * 0.0000152587890625;
    v3 += 4;
    seed = -1153374675 - 1153374675 * v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040ECF0
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // edi
  SIMDRandStreamContext *v2; // esi

  v1 = 0;
  v2 = s_SIMDRandContexts;
  do
  {
    SIMDRandStreamContext::Seed(this: v2++, seed: v1 + seed);
    ++v1;
  }
  while ( (int)v2 < (int)s_nRandContextsInUse );
}

} // namespace worldrenderertest

// ============================================================
// Overlay from client (Missing functions)
// ============================================================
namespace client {

//------------------------------------------------------------------------------
// Address: 0x102CB020
// Name: public: union __m128 SIMDRandStreamContext::RandSIMD(void)
// Source: json
//------------------------------------------------------------------------------
__m128 *__thiscall SIMDRandStreamContext::RandSIMD(SIMDRandStreamContext *this, __m128 *result)
{
  __m128 *m_pRand_K; // eax
  __m128 v3; // xmm0
  __m128 v4; // xmm0

  m_pRand_K = this->m_pRand_K;
  v3 = _mm_add_ps(*this->m_pRand_J, *m_pRand_K);
  v4 = _mm_sub_ps(v3, _mm_and_ps(_mm_cmple_ps(Four_Ones, v3), Four_Ones));
  *m_pRand_K = v4;
  if ( --this->m_pRand_J < (__m128 *)this )
    this->m_pRand_J = &this->m_RandY[54];
  if ( --this->m_pRand_K < (__m128 *)this )
    this->m_pRand_K = &this->m_RandY[54];
  *result = v4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CB090
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&r_showenvcubemap.m_fnChangeCallbacks.m_Memory.m_nAllocationCount );
}

//------------------------------------------------------------------------------
// Address: 0x102CB190
// Name: union __m128 RandSIMD(int)
// Source: json
//------------------------------------------------------------------------------
__m128 *__usercall RandSIMD@<eax>(int a1@<ebp>, __m128 *result)
{
  __m128 v3; // [esp-10h] [ebp-1Ch] BYREF
  int v4; // [esp+0h] [ebp-Ch]
  void *v5; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v4 = a1;
  v5 = retaddr;
  return SIMDRandStreamContext::RandSIMD(this: &s_SIMDRandContexts[(_DWORD)result], result: &v3);
}

//------------------------------------------------------------------------------
// Address: 0x102CB1D0
// Name: int GetSIMDRandContext(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl GetSIMDRandContext()
{
  unsigned int v0; // ecx
  volatile int *v1; // edx

LABEL_1:
  v0 = 0;
  v1 = s_nRandContextsInUse;
  while ( *v1 != 0 || _InterlockedCompareExchange(v1, 1, 0) != 0 )
  {
    ++v0;
    ++v1;
    if ( v0 >= 0x20 )
    {
      _ThreadSleep(a1: 0);
      goto LABEL_1;
    }
  }
  return v0;
}

//------------------------------------------------------------------------------
// Address: 0x102CB220
// Name: void ReleaseSIMDRandContext(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReleaseSIMDRandContext(int nContext)
{
  s_nRandContextsInUse[nContext] = 0;
}

} // namespace client

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x1035A880
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace server

// ============================================================
// Overlay from matchmaking (Missing functions)
// ============================================================
namespace matchmaking {

//------------------------------------------------------------------------------
// Address: 0x100333D0
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace matchmaking

// ============================================================
// Overlay from matchmaking_ds (Missing functions)
// ============================================================
namespace matchmaking_ds {

//------------------------------------------------------------------------------
// Address: 0x10008C70
// Name: void SeedRandSIMD(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SeedRandSIMD(unsigned int seed)
{
  int v1; // ebx
  __m128 **p_m_pRand_J; // esi
  unsigned int v3; // eax
  float *v4; // edx
  int i; // edi
  unsigned int v6; // eax
  unsigned int v7; // eax

  v1 = 0;
  p_m_pRand_J = &s_SIMDRandContexts[0].m_pRand_J;
  do
  {
    p_m_pRand_J[1] = (__m128 *)(p_m_pRand_J - 4);
    v3 = v1 + seed;
    *p_m_pRand_J = (__m128 *)(p_m_pRand_J - 128);
    v4 = (float *)(p_m_pRand_J - 218);
    for ( i = 55; i != 0; --i )
    {
      *(v4 - 2) = (double)HIWORD(v3) * 0.0000152587890625;
      v6 = -1153374675 - 1153374675 * v3;
      *(v4 - 1) = (double)HIWORD(v6) * 0.0000152587890625;
      *v4 = (double)((-1153374675 - 1153374675 * v6) >> 16) * 0.0000152587890625;
      v7 = -1153374675 - 1153374675 * (-1153374675 - 1153374675 * v6);
      v4[1] = (double)HIWORD(v7) * 0.0000152587890625;
      v4 += 4;
      v3 = -1153374675 - 1153374675 * v7;
    }
    p_m_pRand_J += 224;
    ++v1;
  }
  while ( (int)p_m_pRand_J < (int)&texturetolinear[184] );
}

} // namespace matchmaking_ds
