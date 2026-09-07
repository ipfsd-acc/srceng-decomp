// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxstyles.cpp
// Functions: 35
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxstyles.h"

//------------------------------------------------------------------------------
// Address: 0x1013AF80
// Name: public: void GFxGradientRecord::Read(class GFxLoadProcess __near *,enum GFxTagType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGradientRecord::Read(
        CMemberFuncProxyBase<CMatQueuedMesh *,void (__thiscall CMatQueuedMesh::*)(CMatQueuedMesh::MST_MeshInfo_t const &),CFuncMemPolicyNone> *this,
        _DWORD *p,
        unsigned __int8 *a3)
{
  _DWORD *v3; // esi
  int v5; // eax
  int v6; // eax
  char v7; // cl

  v3 = (_DWORD *)p[201];
  if ( v3 == nullptr )
    v3 = p + 10;
  v5 = v3[12] - v3[11];
  *((_BYTE *)v3 + 21) = 0;
  if ( v5 < 1 )
    GFxStream::PopulateBuffer1(this: v3);
  v6 = v3[11];
  v7 = *(_BYTE *)(v6 + v3[15]);
  v3[11] = v6 + 1;
  LOBYTE(this->m_pfnProxied) = v7;
  GFxLoadProcess::ReadRgbaTag(this: p, pc: (struct GColor *)&this->m_pfnProxied + 1, (int)a3);
}

//------------------------------------------------------------------------------
// Address: 0x1013AFE0
// Name: private: void GFocalRadialGradient::updateValues(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFocalRadialGradient::updateValues(GFocalRadialGradient *this)
{
  double v1; // st7
  double v2; // st6
  double v3; // st6
  double v4; // st5
  double v5; // st4
  double v6; // st4
  double v7; // rtt
  double v8; // st5
  double v9; // st6
  double v10; // st6
  double v11; // st6
  float v12; // [esp+0h] [ebp-4h]
  float v13; // [esp+0h] [ebp-4h]
  float v14; // [esp+0h] [ebp-4h]
  float v15; // [esp+0h] [ebp-4h]
  float v16; // [esp+0h] [ebp-4h]
  float v17; // [esp+0h] [ebp-4h]
  float v18; // [esp+0h] [ebp-4h]

  v12 = *(float *)this * *(float *)this;
  v1 = v12;
  *((float *)this + 3) = v12;
  v13 = *((float *)this + 1) * *((float *)this + 1);
  v2 = v13;
  v14 = *((float *)this + 2) * *((float *)this + 2);
  v15 = v1 - (v2 + v14);
  v3 = 0.0;
  if ( 0.0 == v15 )
  {
    v4 = 1.0;
    if ( 0.0 != *((float *)this + 1) )
    {
      v5 = *((float *)this + 1);
      if ( v5 >= 0.0 )
        v6 = v5 - 1.0;
      else
        v6 = v5 + 1.0;
      *((float *)this + 1) = v6;
      v4 = 1.0;
      v3 = 0.0;
    }
    if ( v3 != *((float *)this + 2) )
    {
      v7 = v4;
      v8 = v3;
      v9 = v7;
      if ( v8 <= *((float *)this + 2) )
        v10 = *((float *)this + 2) - v9;
      else
        v10 = v9 + *((float *)this + 2);
      *((float *)this + 2) = v10;
    }
    v16 = *((float *)this + 1) * *((float *)this + 1);
    v11 = v16;
    v17 = *((float *)this + 2) * *((float *)this + 2);
    v18 = v1 - (v11 + v17);
    *((float *)this + 4) = *(float *)this / v18;
  }
  else
  {
    *((float *)this + 4) = *(float *)this / v15;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013B0C0
// Name: public: unsigned int GFxGradientData::ComputeRadialGradientImageSize(class GFxGradientParams __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxGradientData::ComputeRadialGradientImageSize(
        GFxGradientData *this,
        struct GFxGradientParams *a2)
{
  GFxGradientData *v2; // edx
  unsigned int result; // eax
  unsigned int v4; // ecx
  unsigned int v5; // eax
  int v6; // eax
  unsigned int v7; // ebx
  unsigned __int8 *v8; // edi
  unsigned __int8 *v9; // esi
  double v10; // st6
  double v11; // st5
  __int64 v12; // rax
  __int64 v13; // rax
  __int64 v14; // rax
  __int64 v15; // rax
  double v16; // st4
  double v17; // st5
  double v18; // st6
  double v19; // st5
  __int64 v20; // rax
  __int64 v21; // rax
  __int64 v22; // rax
  __int64 v23; // rax
  double v24; // st4
  double v25; // st5
  __int64 v26; // rax
  __int64 v27; // rax
  __int64 v28; // rax
  __int64 v29; // rax
  double v30; // st6
  __int64 v31; // rax
  __int64 v32; // rax
  __int64 v33; // rax
  __int64 v34; // rax
  unsigned __int8 *v35; // edi
  unsigned __int8 *v36; // esi
  unsigned int v37; // ebx
  double v38; // st6
  __int64 v39; // rax
  __int64 v40; // rax
  __int64 v41; // rax
  unsigned int v42; // eax
  int v43; // [esp+4h] [ebp-Ch]
  float v44; // [esp+4h] [ebp-Ch]
  float v46; // [esp+Ch] [ebp-4h]
  float v47; // [esp+Ch] [ebp-4h]
  float v48; // [esp+Ch] [ebp-4h]
  float v49; // [esp+Ch] [ebp-4h]
  float v50; // [esp+Ch] [ebp-4h]
  float v51; // [esp+Ch] [ebp-4h]
  float v52; // [esp+Ch] [ebp-4h]
  float v53; // [esp+Ch] [ebp-4h]
  float v54; // [esp+Ch] [ebp-4h]
  float v55; // [esp+Ch] [ebp-4h]
  float v56; // [esp+Ch] [ebp-4h]
  float v57; // [esp+Ch] [ebp-4h]
  float v58; // [esp+Ch] [ebp-4h]
  float v59; // [esp+Ch] [ebp-4h]
  float v60; // [esp+Ch] [ebp-4h]
  float v61; // [esp+Ch] [ebp-4h]
  float v62; // [esp+Ch] [ebp-4h]
  float v63; // [esp+Ch] [ebp-4h]
  float v64; // [esp+Ch] [ebp-4h]
  float v65; // [esp+Ch] [ebp-4h]
  float v66; // [esp+Ch] [ebp-4h]
  float v67; // [esp+Ch] [ebp-4h]
  float v68; // [esp+Ch] [ebp-4h]
  float v69; // [esp+Ch] [ebp-4h]
  float v70; // [esp+Ch] [ebp-4h]
  float v71; // [esp+18h] [ebp+8h]
  float v72; // [esp+18h] [ebp+8h]
  float v73; // [esp+18h] [ebp+8h]

  v2 = this;
  if ( a2 == nullptr || a2->AdaptiveGradients )
  {
    v4 = *((unsigned __int16 *)this + 5);
    v5 = 1;
    v71 = 0.0;
    if ( v4 <= 1 )
      return 64;
    if ( (int)(v4 - 1) >= 4 )
    {
      v6 = *((_DWORD *)v2 + 3);
      v7 = ((v4 - 5) >> 2) + 1;
      v8 = (unsigned __int8 *)(v6 + 14);
      v9 = (unsigned __int8 *)(v6 + 5);
      v43 = 4 * v7 + 1;
      do
      {
        v10 = (double)*(v8 - 6);
        v46 = v10 - (double)*(v8 - 14);
        v11 = v46;
        if ( v46 > 0.0 )
        {
          v12 = v9[1] - *v8;
          v47 = (double)(int)((HIDWORD(v12) ^ v12) - HIDWORD(v12)) / v11;
          if ( v71 < (double)v47 )
            v71 = (double)(int)((HIDWORD(v12) ^ v12) - HIDWORD(v12)) / v11;
          v13 = *v9 - *(v8 - 1);
          v48 = (double)(int)((HIDWORD(v13) ^ v13) - HIDWORD(v13)) / v11;
          if ( v71 < (double)v48 )
            v71 = (double)(int)((HIDWORD(v13) ^ v13) - HIDWORD(v13)) / v11;
          v14 = *(v9 - 1) - *(v8 - 2);
          v49 = (double)(int)((HIDWORD(v14) ^ v14) - HIDWORD(v14)) / v11;
          if ( v71 < (double)v49 )
            v71 = (double)(int)((HIDWORD(v14) ^ v14) - HIDWORD(v14)) / v11;
          v15 = v9[2] - v8[1];
          v50 = (double)(int)((HIDWORD(v15) ^ v15) - HIDWORD(v15)) / v11;
          if ( v71 < (double)v50 )
            v71 = (double)(int)((HIDWORD(v15) ^ v15) - HIDWORD(v15)) / v11;
        }
        v16 = (double)v8[2];
        v17 = v16 - v10;
        v18 = v16;
        v51 = v17;
        v19 = v51;
        if ( v51 > 0.0 )
        {
          v20 = *v8 - v9[17];
          v52 = (double)(int)((HIDWORD(v20) ^ v20) - HIDWORD(v20)) / v19;
          if ( v71 < (double)v52 )
            v71 = (double)(int)((HIDWORD(v20) ^ v20) - HIDWORD(v20)) / v19;
          v21 = *(v8 - 1) - v9[16];
          v53 = (double)(int)((HIDWORD(v21) ^ v21) - HIDWORD(v21)) / v19;
          if ( v71 < (double)v53 )
            v71 = (double)(int)((HIDWORD(v21) ^ v21) - HIDWORD(v21)) / v19;
          v22 = *(v8 - 2) - v9[15];
          v54 = (double)(int)((HIDWORD(v22) ^ v22) - HIDWORD(v22)) / v19;
          if ( v71 < (double)v54 )
            v71 = (double)(int)((HIDWORD(v22) ^ v22) - HIDWORD(v22)) / v19;
          v23 = v8[1] - v9[18];
          v55 = (double)(int)((HIDWORD(v23) ^ v23) - HIDWORD(v23)) / v19;
          if ( v71 < (double)v55 )
            v71 = (double)(int)((HIDWORD(v23) ^ v23) - HIDWORD(v23)) / v19;
        }
        v24 = (double)v8[10];
        v56 = v24 - v18;
        v25 = v56;
        if ( v56 > 0.0 )
        {
          v26 = v9[17] - v9[25];
          v57 = (double)(int)((HIDWORD(v26) ^ v26) - HIDWORD(v26)) / v25;
          if ( v71 < (double)v57 )
            v71 = (double)(int)((HIDWORD(v26) ^ v26) - HIDWORD(v26)) / v25;
          v27 = v9[16] - v9[24];
          v58 = (double)(int)((HIDWORD(v27) ^ v27) - HIDWORD(v27)) / v25;
          if ( v71 < (double)v58 )
            v71 = (double)(int)((HIDWORD(v27) ^ v27) - HIDWORD(v27)) / v25;
          v28 = v9[15] - v9[23];
          v59 = (double)(int)((HIDWORD(v28) ^ v28) - HIDWORD(v28)) / v25;
          if ( v71 < (double)v59 )
            v71 = (double)(int)((HIDWORD(v28) ^ v28) - HIDWORD(v28)) / v25;
          v29 = v9[18] - v9[26];
          v60 = (double)(int)((HIDWORD(v29) ^ v29) - HIDWORD(v29)) / v25;
          if ( v71 < (double)v60 )
            v71 = (double)(int)((HIDWORD(v29) ^ v29) - HIDWORD(v29)) / v25;
        }
        v61 = (double)v8[18] - v24;
        v30 = v61;
        if ( v61 > 0.0 )
        {
          v31 = v9[25] - v9[33];
          v62 = (double)(int)((HIDWORD(v31) ^ v31) - HIDWORD(v31)) / v30;
          if ( v71 < (double)v62 )
            v71 = (double)(int)((HIDWORD(v31) ^ v31) - HIDWORD(v31)) / v30;
          v32 = v9[24] - v9[32];
          v63 = (double)(int)((HIDWORD(v32) ^ v32) - HIDWORD(v32)) / v30;
          if ( v71 < (double)v63 )
            v71 = (double)(int)((HIDWORD(v32) ^ v32) - HIDWORD(v32)) / v30;
          v33 = v9[23] - v9[31];
          v64 = (double)(int)((HIDWORD(v33) ^ v33) - HIDWORD(v33)) / v30;
          if ( v71 < (double)v64 )
            v71 = (double)(int)((HIDWORD(v33) ^ v33) - HIDWORD(v33)) / v30;
          v34 = v9[26] - v9[34];
          v65 = (double)(int)((HIDWORD(v34) ^ v34) - HIDWORD(v34)) / v30;
          if ( v71 < (double)v65 )
            v71 = (double)(int)((HIDWORD(v34) ^ v34) - HIDWORD(v34)) / v30;
        }
        v9 += 32;
        v8 += 32;
        --v7;
      }
      while ( v7 != 0 );
      v5 = v43;
      v2 = this;
    }
    if ( v5 < v4 )
    {
      v35 = (unsigned __int8 *)(*((_DWORD *)v2 + 3) + 8 * v5);
      v36 = v35 - 3;
      v37 = v4 - v5;
      do
      {
        v66 = (double)*v35 - (double)*(v36 - 5);
        v38 = v66;
        if ( v66 > 0.0 )
        {
          v39 = v36[1] - v36[9];
          v67 = (double)(int)((HIDWORD(v39) ^ v39) - HIDWORD(v39)) / v38;
          if ( v71 < (double)v67 )
            v71 = (double)(int)((HIDWORD(v39) ^ v39) - HIDWORD(v39)) / v38;
          v68 = (double)(int)abs32(*v36 - v36[8]) / v38;
          if ( v71 < (double)v68 )
            v71 = v68;
          v40 = *(v36 - 1) - v36[7];
          v69 = (double)(int)((HIDWORD(v40) ^ v40) - HIDWORD(v40)) / v38;
          if ( v71 < (double)v69 )
            v71 = (double)(int)((HIDWORD(v40) ^ v40) - HIDWORD(v40)) / v38;
          v41 = v36[2] - v36[10];
          v70 = (double)(int)((HIDWORD(v41) ^ v41) - HIDWORD(v41)) / v38;
          if ( v71 < (double)v70 )
            v71 = (double)(int)((HIDWORD(v41) ^ v41) - HIDWORD(v41)) / v38;
        }
        v35 += 8;
        v36 += 8;
        --v37;
      }
      while ( v37 != 0 );
      v2 = this;
    }
    if ( 0.0 == v71 )
    {
      return 64;
    }
    else
    {
      if ( *((_BYTE *)v2 + 8) != 0 )
        v71 = v71 * 1.5;
      if ( *((_BYTE *)v2 + 9) == 19 )
      {
        v44 = fabs(*((float *)v2 + 4));
        if ( v44 > 0.5 )
          v71 = v71 / (1.009999990463257 - v44);
      }
      if ( v71 < 0.0 )
        v71 = 0.0;
      v72 = (v71 + 0.1800000071525574) * 5.0;
      v73 = sqrt(v72);
      v42 = (__int64)v73;
      if ( v42 >= 0x12 )
        v42 = 17;
      return GFxGradientData_RadialGradientSizeTable[v42];
    }
  }
  else
  {
    result = a2->RadialGradientImageSize;
    if ( result == 0 )
      return 64;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013B6B0
// Name: public: GFxFillStyle::~GFxFillStyle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFillStyle::~GFxFillStyle(void *this)
{
  IShaderAPI *v2; // ecx
  IShaderDevice *v3; // ecx

  if ( (*(_BYTE *)this & 0x10) != 0 )
  {
    v2 = *((IShaderAPI **)this + 1);
    if ( v2 != nullptr )
      GRefCountImpl::Release(this: v2);
  }
  if ( *((_DWORD *)this + 2) == 0 )
  {
    v3 = *((IShaderDevice **)this + 3);
    if ( v3 != nullptr )
      GFxResource::Release(this: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013B6E0
// Name: public: void GFxFillStyle::SetFillType(enum GFxFillType)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxFillStyle::SetFillType(void *this, char a2)
{
  IShaderAPI *v3; // ecx
  char result; // al

  if ( (*(_BYTE *)this & 0x10) != 0 )
  {
    v3 = *((IShaderAPI **)this + 1);
    if ( v3 != nullptr )
    {
      GRefCountImpl::Release(this: v3);
      result = a2;
    }
    *(_BYTE *)this = a2;
  }
  else
  {
    *(_BYTE *)this = a2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013B720
// Name: public: GFxLineStyle::GFxLineStyle(void)
// Source: json
//------------------------------------------------------------------------------
CMemberFuncProxyBase<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(IMesh *,int),CFuncMemPolicyNone> *__thiscall GFxLineStyle::GFxLineStyle(
        float *this)
{
  *(this + 5) = 1.0;
  *(_DWORD *)this = &GFxLineStyle::`vftable';
  *((_WORD *)this + 2) = 0;
  *(this + 3) = 0.0;
  *((_WORD *)this + 8) = 0;
  return (CMemberFuncProxyBase<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(IMesh *,int),CFuncMemPolicyNone> *)this;
}

//------------------------------------------------------------------------------
// Address: 0x1013B740
// Name: public: bool GFxGradientData::SetRecordCount(unsigned short)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxGradientData::SetRecordCount(int this, const MeshInstanceData_t *result)
{
  __int16 v2; // si
  _BYTE *v5; // edi
  unsigned __int16 v6; // ax
  unsigned int v7; // esi
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  unsigned int copyCount; // [esp+8h] [ebp-8h]
  int v12; // [esp+Ch] [ebp-4h] BYREF

  v2 = (__int16)result;
  if ( (_WORD)result == *(_WORD *)(this + 10) )
    return 1;
  v5 = nullptr;
  if ( (_WORD)result != 0 )
  {
    v12 = 258;
    v5 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 8 * (unsigned __int16)result, a3: &v12);
    if ( v5 == nullptr )
      return 0;
  }
  if ( *(_DWORD *)(this + 12) != 0 )
  {
    v6 = *(_WORD *)(this + 10);
    if ( (unsigned __int16)result < v6 )
      v6 = (unsigned __int16)result;
    v7 = 0;
    for ( copyCount = v6; v7 < copyCount; *(_DWORD *)&v5[v9 + 4] = v10 )
    {
      v8 = *(_DWORD *)(this + 12);
      v9 = 8 * v7;
      v5[v9] = *(_BYTE *)(v8 + 8 * v7);
      v10 = *(_DWORD *)(v8 + 8 * v7++ + 4);
    }
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)(this + 12));
    v2 = (__int16)result;
  }
  *(_DWORD *)(this + 12) = v5;
  *(_WORD *)(this + 10) = v2;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1013B810
// Name: public: bool GFxGradientData::operator==(class GFxGradientData const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxGradientData::operator==(
        int this,
        const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),CFuncMemPolicyNone> *result)
{
  unsigned int v2; // edi
  unsigned int v3; // esi
  int m_pfnProxied_high; // edx
  int v5; // eax
  _DWORD *v6; // ecx
  int v7; // edx

  v2 = *(unsigned __int16 *)(this + 10);
  if ( (_WORD)v2 != WORD5(result->m_pfnProxied)
    || *(_BYTE *)(this + 9) != BYTE9(result->m_pfnProxied)
    || *(float *)&result->m_pObject != *(float *)(this + 16)
    || *(_BYTE *)(this + 8) != BYTE8(result->m_pfnProxied) )
  {
    return 0;
  }
  v3 = 0;
  if ( *(_WORD *)(this + 10) == 0 )
    return 1;
  m_pfnProxied_high = HIDWORD(result->m_pfnProxied);
  v5 = *(_DWORD *)(this + 12);
  v6 = (_DWORD *)(m_pfnProxied_high + 4);
  v7 = m_pfnProxied_high - v5;
  while ( *(_BYTE *)v5 == *(_BYTE *)(v7 + v5) && *(_DWORD *)(v5 + 4) == *v6 )
  {
    ++v3;
    v6 += 2;
    v5 += 8;
    if ( v3 >= v2 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013B8A0
// Name: public: virtual unsigned int GFxGradientImageResourceKey::GetHashCode(void __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxGradientImageResourceKey::GetHashCode(GFxGradientImageResourceKey *this, _DWORD *a2)
{
  unsigned int result; // eax
  int v3; // esi
  unsigned __int8 *v4; // ecx

  result = *((unsigned __int8 *)a2 + 9);
  v3 = *((unsigned __int16 *)a2 + 5);
  if ( *((_WORD *)a2 + 5) != 0 )
  {
    v4 = (unsigned __int8 *)a2[3];
    do
    {
      result ^= *((_DWORD *)v4 + 1) ^ *v4 ^ HIWORD(*((_DWORD *)v4 + 1));
      v4 += 8;
      --v3;
    }
    while ( v3 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1013B8E0
// Name: public: virtual bool GFxGradientImageResourceKey::KeyEquals(void __near *,class GFxResourceKey const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxGradientImageResourceKey::KeyEquals(
        GFxGradientImageResourceKey *this,
        void *a2,
        const struct GFxResourceKey *a3)
{
  if ( this == (GFxGradientImageResourceKey *)a3->pKeyInterface )
    return GFxGradientData::operator==(
             this: (int)a2,
             result: (const CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),CFuncMemPolicyNone> *)a3->hKeyData);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013B900
// Name: public: GFxFillStyle::GFxFillStyle(void)
// Source: json
//------------------------------------------------------------------------------
CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *__thiscall GFxFillStyle::GFxFillStyle(
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *this)
{
  *((_QWORD *)&this->m_pfnProxied + 1) = 0;
  GMatrix2D::SetIdentity(this: (float *)&this->m_pObject);
  LOWORD(this->m_pfnProxied) = 512;
  DWORD1(this->m_pfnProxied) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013B930
// Name: public: class GFxFillStyle __near & GFxFillStyle::operator=(class GFxFillStyle const __near &)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall GFxFillStyle::operator=(void *this, int a2)
{
  IShaderDevice *v3; // ecx
  IShaderAPI *v4; // ecx
  IShaderDevice *v5; // ecx
  IShaderDevice *v6; // ecx

  if ( (*(_BYTE *)a2 & 0x10) != 0 )
  {
    v3 = *(IShaderDevice **)(a2 + 4);
    if ( v3 != nullptr )
      GRefCountImpl::AddRef(this: v3);
  }
  if ( (*(_BYTE *)this & 0x10) != 0 )
  {
    v4 = *((IShaderAPI **)this + 1);
    if ( v4 != nullptr )
      GRefCountImpl::Release(this: v4);
  }
  *(_BYTE *)this = *(_BYTE *)a2;
  *((_BYTE *)this + 1) = *(_BYTE *)(a2 + 1);
  *((_DWORD *)this + 1) = *(_DWORD *)(a2 + 4);
  if ( *(_DWORD *)(a2 + 8) == 0 )
  {
    v5 = *(IShaderDevice **)(a2 + 12);
    if ( v5 != nullptr )
      GRefCountImpl::AddRef(this: v5);
  }
  if ( *((_DWORD *)this + 2) == 0 )
  {
    v6 = *((IShaderDevice **)this + 3);
    if ( v6 != nullptr )
      GFxResource::Release(this: v6);
  }
  *((_DWORD *)this + 2) = *(_DWORD *)(a2 + 8);
  *((_DWORD *)this + 3) = *(_DWORD *)(a2 + 12);
  *((float *)this + 4) = *(float *)(a2 + 16);
  *((float *)this + 5) = *(float *)(a2 + 20);
  *((float *)this + 6) = *(float *)(a2 + 24);
  *((float *)this + 7) = *(float *)(a2 + 28);
  *((float *)this + 8) = *(float *)(a2 + 32);
  *((float *)this + 9) = *(float *)(a2 + 36);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013B9D0
// Name: public: void GFxFillStyle::SetImageFill(enum GFxFillType,class GFxImageResource __near *,class GMatrix2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFillStyle::SetImageFill(
        void *this,
        CMemberFuncProxy3<CMatQueuedRenderContext *,void (__thiscall CMatQueuedRenderContext::*)(IMesh *,CPrimList *,int),IMesh *,CPrimList *,int,CFuncMemPolicyNone> *result,
        IShaderDevice *pimage,
        float *pimage_4)
{
  IShaderAPI *v5; // ecx
  IShaderDevice *v6; // ecx

  if ( (*(_BYTE *)this & 0x10) != 0 )
  {
    v5 = *((IShaderAPI **)this + 1);
    if ( v5 != nullptr )
      GRefCountImpl::Release(this: v5);
  }
  *(_BYTE *)this = (_BYTE)result;
  *((_BYTE *)this + 1) = 2;
  *((float *)this + 4) = *pimage_4;
  *((float *)this + 5) = pimage_4[1];
  *((float *)this + 6) = pimage_4[2];
  *((float *)this + 7) = pimage_4[3];
  *((float *)this + 8) = pimage_4[4];
  *((float *)this + 9) = pimage_4[5];
  *((float *)this + 4) = *((float *)this + 4) * 20.0;
  *((float *)this + 5) = *((float *)this + 5) * 20.0;
  *((float *)this + 6) = *((float *)this + 6) * 20.0;
  *((float *)this + 7) = *((float *)this + 7) * 20.0;
  *((float *)this + 8) = *((float *)this + 8) * 20.0;
  *((float *)this + 9) = 20.0 * *((float *)this + 9);
  if ( pimage != nullptr )
    GRefCountImpl::AddRef(this: pimage);
  if ( *((_DWORD *)this + 2) == 0 )
  {
    v6 = *((IShaderDevice **)this + 3);
    if ( v6 != nullptr )
      GFxResource::Release(this: v6);
  }
  *((_DWORD *)this + 3) = pimage;
  *((_DWORD *)this + 2) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013BA80
// Name: public: void GFxFillStyle::SetGradientFill(enum GFxFillType,class GFxGradientData __near *,class GMatrix2D const __near &)
// Source: json
//------------------------------------------------------------------------------
float *__thiscall GFxFillStyle::SetGradientFill(void *this, char a2, IShaderDevice *a3, float *a4)
{
  IShaderAPI *v5; // ecx

  if ( (*(_BYTE *)this & 0x10) == 0 || a3 != *((IShaderDevice **)this + 1) )
  {
    if ( (*(_BYTE *)this & 0x10) != 0 )
    {
      v5 = *((IShaderAPI **)this + 1);
      if ( v5 != nullptr )
        GRefCountImpl::Release(this: v5);
    }
    *(_BYTE *)this = a2;
    *((_DWORD *)this + 1) = a3;
    if ( a3 != nullptr )
      GRefCountImpl::AddRef(this: a3);
  }
  *((float *)this + 4) = *a4;
  *((float *)this + 5) = a4[1];
  *((float *)this + 6) = a4[2];
  *((float *)this + 7) = a4[3];
  *((float *)this + 8) = a4[4];
  *((float *)this + 9) = a4[5];
  *((float *)this + 6) = *((float *)this + 6) * 20.0;
  *((float *)this + 9) = 20.0 * *((float *)this + 9);
  return a4;
}

//------------------------------------------------------------------------------
// Address: 0x1013BB00
// Name: public: class GFxFillStyle __near * GFxLineStyle::CreateComplexFill(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLineStyle::CreateComplexFill(
        CMemberFunctor2<IMesh *,void (__thiscall IMesh::*)(int,int),int,int,CRefCounted1<CFunctor,CRefCountServiceDestruct<CRefST> >,CFuncMemPolicyNone> *this)
{
  void *v2; // eax
  int v3; // esi
  int v4; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_iRefs == 0 )
  {
    v4 = 258;
    v2 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 40, a3: &v4);
    v3 = (int)v2;
    if ( v2 != nullptr )
    {
      *((_DWORD *)v2 + 2) = 0;
      *((_DWORD *)v2 + 3) = 0;
      GMatrix2D::SetIdentity(this: (float *)v2 + 4);
      *(_WORD *)v3 = 512;
      *(_DWORD *)(v3 + 4) = 0;
      this->m_iRefs = v3;
    }
    else
    {
      this->m_iRefs = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013BB70
// Name: public: virtual void GFxLineStyle::Apply(class GRenderer __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLineStyle::Apply(GFxLineStyle *this, struct GRenderer *a2)
{
  ((void (__thiscall *)(struct GRenderer *, _DWORD))a2->LineStyleColor)(a1: a2, a2: *((_DWORD *)this + 2));
}

//------------------------------------------------------------------------------
// Address: 0x1013BCE0
// Name: public: void GFxGradientRamp::Init(class GFxGradientRecord const __near *,unsigned int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGradientRamp::Init(
        GFxGradientRamp *this,
        const struct GFxGradientRecord *a2,
        unsigned int a3,
        float a4)
{
  const struct GFxGradientRecord *v4; // ebx
  unsigned int i; // eax
  unsigned int j; // eax
  unsigned int k; // esi
  unsigned int v9; // esi
  int v10; // eax
  unsigned __int8 *v11; // ecx
  unsigned __int16 v12; // bx
  unsigned __int16 v13; // dx
  __int16 v14; // ax
  unsigned __int16 v15; // di
  int v16; // edx
  unsigned __int16 v17; // dx
  signed int v18; // edi
  int v19; // ecx
  int v20; // edi
  int v21; // ebx
  int v22; // edi
  char v23; // al
  char v24; // al
  char v25; // al
  bool v26; // zf
  int v27; // [esp+14h] [ebp-258h]
  int v28; // [esp+18h] [ebp-254h]
  int v29; // [esp+18h] [ebp-254h]
  int v30; // [esp+1Ch] [ebp-250h]
  int v31; // [esp+20h] [ebp-24Ch]
  int v32; // [esp+20h] [ebp-24Ch]
  int v33; // [esp+24h] [ebp-248h]
  int v35; // [esp+2Ch] [ebp-240h]
  int v36; // [esp+30h] [ebp-23Ch]
  int v37; // [esp+34h] [ebp-238h]
  int v38; // [esp+34h] [ebp-238h]
  float v39; // [esp+38h] [ebp-234h]
  unsigned __int8 *v40; // [esp+3Ch] [ebp-230h]
  int v41; // [esp+40h] [ebp-22Ch]
  int v42; // [esp+40h] [ebp-22Ch]
  unsigned __int16 v43; // [esp+44h] [ebp-228h] BYREF
  unsigned __int16 v44; // [esp+46h] [ebp-226h]
  int v45; // [esp+48h] [ebp-224h]
  int v46; // [esp+4Ch] [ebp-220h]
  unsigned __int16 v47; // [esp+50h] [ebp-21Ch]
  unsigned __int16 v48; // [esp+52h] [ebp-21Ah]
  unsigned __int16 v49; // [esp+54h] [ebp-218h]
  unsigned __int16 v50; // [esp+56h] [ebp-216h]
  unsigned int v51; // [esp+58h] [ebp-214h]
  float v52; // [esp+5Ch] [ebp-210h]
  int v53; // [esp+60h] [ebp-20Ch]
  int v54[129]; // [esp+64h] [ebp-208h]

  v4 = a2;
  if ( a3 == 0 || a2 == nullptr )
  {
    LOBYTE(v43) = 0;
    v45 = -16777216;
    v4 = (const struct GFxGradientRecord *)&v43;
    goto LABEL_4;
  }
  if ( a3 <= 1 )
  {
LABEL_4:
    for ( i = 0; i < 0x100; ++i )
      *((_DWORD *)this + i) = *((_DWORD *)v4 + 1);
    return;
  }
  v39 = 1.0;
  if ( a4 == 1.0 )
  {
    for ( j = 0; j < 0x100; ++j )
      *((_WORD *)&v54[1] + j) = j | ((_WORD)j << 8);
  }
  else
  {
    for ( k = 0; k < 0x100; *((_WORD *)v54 + k + 1) = LOWORD(v52) )
    {
      v52 = (double)k / 255.0;
      v52 = pow(v52, a4);
      v52 = v52 * 65535.0 + 0.5;
      ++k;
      LODWORD(v52) = (int)floor(X: v52);
    }
    v39 = 1.0 / a4;
  }
  v9 = *(unsigned __int8 *)a2;
  v10 = *((_DWORD *)a2 + 1);
  v54[0] = v10;
  if ( v9 != 0 )
    memset32(this, v10, v9);
  v11 = (unsigned __int8 *)a2 + 6;
  v40 = (unsigned __int8 *)a2 + 6;
  LODWORD(v52) = a3 - 1;
  while ( 1 )
  {
    v51 = v11[2];
    if ( v51 < v9 )
      v51 = v9;
    v12 = *((_WORD *)&v54[1] + *(v11 - 2));
    v13 = *((_WORD *)&v54[1] + *v11);
    v14 = v11[9];
    v50 = v11[1] | (v11[1] << 8);
    v15 = *((_WORD *)&v54[1] + v11[8]);
    v47 = v13;
    v16 = *(v11 - 1);
    v43 = v15;
    v17 = *((_WORD *)&v54[1] + v16);
    v44 = *((_WORD *)&v54[1] + v11[7]);
    LOWORD(v45) = *((_WORD *)&v54[1] + v11[6]);
    HIWORD(v45) = v14 | (v14 << 8);
    v18 = v51 - v9;
    v48 = v17;
    v49 = v12;
    if ( 1.0 == a4 )
    {
      if ( v9 >= v51 )
        goto LABEL_30;
      v19 = v18 | (v18 << 8);
      v20 = (unsigned __int16)v45 - v12;
      v41 = v44 - v17;
      v21 = v41;
      v28 = v20;
      v53 = v20;
      v37 = HIWORD(v45) - v50;
      v31 = v43 - v47;
      v46 = v37;
      v22 = v31;
      do
      {
        v23 = v22 / v19;
        v22 += v31;
        ++v9;
        BYTE2(v35) = v47 + v23;
        v24 = v21 / v19;
        v21 += v41;
        BYTE1(v35) = v48 + v24;
        LOBYTE(v35) = v49 + v53 / v19;
        HIBYTE(v35) = v50 + v46 / v19;
        *((_DWORD *)this + v9 - 1) = v35;
        v46 += v37;
        v54[0] = v35;
        v53 += v28;
      }
      while ( v9 < v51 );
    }
    else
    {
      if ( v9 >= v51 )
        goto LABEL_30;
      v38 = HIWORD(v45) - v50;
      v42 = v44 - v17;
      v29 = (unsigned __int16)v45 - v49;
      v33 = v29;
      v32 = v43 - v47;
      v27 = v38;
      v30 = v42;
      v46 = v32;
      do
      {
        *(float *)v54 = (double)(unsigned __int16)(v47 + v46 / v18) / 65535.0;
        *(float *)v54 = pow(*(float *)v54, v39);
        *(float *)v54 = *(float *)v54 * 255.0 + 0.5;
        BYTE2(v36) = (int)floor(X: *(float *)v54);
        v54[0] = (unsigned __int16)(v48 + v30 / v18);
        *(float *)v54 = (double)v54[0] / 65535.0;
        *(float *)v54 = pow(*(float *)v54, v39);
        *(float *)v54 = *(float *)v54 * 255.0 + 0.5;
        BYTE1(v36) = (int)floor(X: *(float *)v54);
        *(float *)v54 = (double)(unsigned __int16)(v49 + v33 / v18) / 65535.0;
        *(float *)v54 = pow(*(float *)v54, v39);
        *(float *)v54 = *(float *)v54 * 255.0 + 0.5;
        ++v9;
        LOBYTE(v36) = (int)floor(X: *(float *)v54);
        v25 = v27 / (v18 | (v18 << 8));
        v27 += v38;
        HIBYTE(v36) = v50 + v25;
        *((_DWORD *)this + v9 - 1) = v36;
        v30 += v42;
        v54[0] = v36;
        v46 += v32;
        v33 += v29;
      }
      while ( v9 < v51 );
    }
    v11 = v40;
LABEL_30:
    v26 = LODWORD(v52)-- == 1;
    v40 = v11 + 8;
    if ( v26 )
      break;
    v11 += 8;
  }
  if ( v51 < 0x100 )
    memset32((char *)this + 4 * v51, v54[0], 256 - v51);
}

//------------------------------------------------------------------------------
// Address: 0x1013C3A0
// Name: public: GFxFillStyle::GFxFillStyle(class GFxFillStyle const __near &)
// Source: json
//------------------------------------------------------------------------------
GFxFillStyle *__thiscall GFxFillStyle::GFxFillStyle(GFxFillStyle *this, const struct GFxFillStyle *a2)
{
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  GMatrix2D::SetIdentity(this: (float *)this + 4);
  *(_BYTE *)this = 0;
  GFxFillStyle::operator=(this, (int)a2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013C3E0
// Name: public: virtual GFxLineStyle::~GFxLineStyle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLineStyle::~GFxLineStyle(
        CMemberFuncProxyBase<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(IMesh *,int),CFuncMemPolicyNone> *this)
{
  void *m_pfnProxied_high; // esi
  IShaderAPI *v2; // ecx
  IShaderDevice *v3; // ecx

  m_pfnProxied_high = (void *)HIDWORD(this->m_pfnProxied);
  LODWORD(this->m_pfnProxied) = &GFxLineStyle::`vftable';
  if ( m_pfnProxied_high != nullptr )
  {
    if ( (*(_BYTE *)m_pfnProxied_high & 0x10) != 0 )
    {
      v2 = *((IShaderAPI **)m_pfnProxied_high + 1);
      if ( v2 != nullptr )
        GRefCountImpl::Release(this: v2);
    }
    if ( *((_DWORD *)m_pfnProxied_high + 2) == 0 )
    {
      v3 = *((IShaderDevice **)m_pfnProxied_high + 3);
      if ( v3 != nullptr )
        GFxResource::Release(this: v3);
    }
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: m_pfnProxied_high);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013C430
// Name: public: class GFxLineStyle __near & GFxLineStyle::operator=(class GFxLineStyle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxLineStyle::operator=(
        CMemberFuncProxyBase<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(IMesh *,int),CFuncMemPolicyNone> *this@<ecx>,
        CLateBoundPtr<IMesh> src,
        __int128 a3)
{
  IMesh **m_ppObject; // ebx
  void *m_pfnProxied_high; // esi
  IShaderAPI *v6; // ecx
  IShaderDevice *v7; // ecx
  void *v8; // esi
  int v9; // ebx

  m_ppObject = src.m_ppObject;
  WORD2(this->m_pfnProxied) = *((_WORD *)src.m_ppObject + 2);
  DWORD2(this->m_pfnProxied) = m_ppObject[2];
  m_pfnProxied_high = (void *)HIDWORD(this->m_pfnProxied);
  LOWORD(this->m_pObject.m_ppObject) = *((_WORD *)m_ppObject + 8);
  *((float *)&this->m_pObject + 1) = *((float *)m_ppObject + 5);
  if ( m_pfnProxied_high != nullptr )
  {
    if ( (*(_BYTE *)m_pfnProxied_high & 0x10) != 0 )
    {
      v6 = *((IShaderAPI **)m_pfnProxied_high + 1);
      if ( v6 != nullptr )
        GRefCountImpl::Release(this: v6);
    }
    if ( *((_DWORD *)m_pfnProxied_high + 2) == 0 )
    {
      v7 = *((IShaderDevice **)m_pfnProxied_high + 3);
      if ( v7 != nullptr )
        GFxResource::Release(this: v7);
    }
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: m_pfnProxied_high);
    HIDWORD(this->m_pfnProxied) = 0;
  }
  if ( m_ppObject[3] != nullptr )
  {
    src.m_ppObject = (IMesh **)258;
    v8 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 40, a3: &src);
    if ( v8 != nullptr )
    {
      v9 = (int)m_ppObject[3];
      *((_DWORD *)v8 + 2) = 0;
      *((_DWORD *)v8 + 3) = 0;
      GMatrix2D::SetIdentity(this: (float *)v8 + 4);
      *(_BYTE *)v8 = 0;
      GFxFillStyle::operator=(this: v8, a2: v9);
      HIDWORD(this->m_pfnProxied) = v8;
    }
    else
    {
      HIDWORD(this->m_pfnProxied) = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013C500
// Name: public: void GFxLineStyle::SetComplexFill(class GFxFillStyle const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLineStyle::SetComplexFill(GFxLineStyle *this, const struct GFxFillStyle *a2)
{
  void *v3; // esi
  IShaderAPI *v4; // ecx
  IShaderDevice *v5; // ecx
  void *v6; // eax
  _BYTE *v7; // esi
  int v8; // [esp+8h] [ebp-4h] BYREF

  v3 = *((void **)this + 3);
  if ( v3 != nullptr )
  {
    if ( (*(_BYTE *)v3 & 0x10) != 0 )
    {
      v4 = *((IShaderAPI **)v3 + 1);
      if ( v4 != nullptr )
        GRefCountImpl::Release(this: v4);
    }
    if ( *((_DWORD *)v3 + 2) == 0 )
    {
      v5 = *((IShaderDevice **)v3 + 3);
      if ( v5 != nullptr )
        GFxResource::Release(this: v5);
    }
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v3);
  }
  v8 = 258;
  v6 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 40, a3: &v8);
  v7 = v6;
  if ( v6 != nullptr )
  {
    *((_DWORD *)v6 + 2) = 0;
    *((_DWORD *)v6 + 3) = 0;
    GMatrix2D::SetIdentity(this: (float *)v6 + 4);
    *v7 = 0;
    GFxFillStyle::operator=(this: v7, (int)a2);
    *((_DWORD *)this + 3) = v7;
  }
  else
  {
    *((_DWORD *)this + 3) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013C6F0
// Name: public: GFxGradientData::GFxGradientData(enum GFxFillType,unsigned short,bool)
// Source: json
//------------------------------------------------------------------------------
_WORD *__thiscall GFxGradientData::GFxGradientData(
        _WORD *this,
        char a2,
        const MeshInstanceData_t *recordCount,
        bool linearRgb)
{
  *(_DWORD *)this = &GRefCountImplCore::`vftable';
  *(this + 5) = 0;
  *((_DWORD *)this + 1) = 1;
  *(_DWORD *)this = &GFxGradientData::`vftable';
  *((_BYTE *)this + 9) = a2;
  *((_DWORD *)this + 3) = 0;
  GFxGradientData::SetRecordCount((int)this, result: recordCount);
  *((float *)this + 4) = 0.0;
  *((_BYTE *)this + 8) = linearRgb;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1013C740
// Name: public: class GImage __near * GFxGradientData::CreateGradientImage(class GFxGradientParams __near *,class GMemoryHeap __near *)const
// Source: json
//------------------------------------------------------------------------------
CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),CFuncMemPolicyNone> *__thiscall GFxGradientData::CreateGradientImage(
        int this,
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),CFuncMemPolicyNone> *result,
        int pparams_4)
{
  bool v4; // zf
  double v5; // st7
  const struct GFxGradientRecord *v6; // ecx
  unsigned int v7; // ebx
  GImage *v8; // eax
  unsigned int v9; // ebx
  CBaseShader *v10; // edx
  unsigned int v11; // edi
  double v12; // st7
  unsigned int v13; // esi
  unsigned int v14; // eax
  unsigned int v15; // edi
  unsigned int v16; // esi
  CBaseShader *v17; // ebx
  unsigned int v18; // esi
  GImage *v19; // eax
  unsigned int v20; // ebx
  unsigned int v21; // edi
  unsigned int v22; // esi
  unsigned int v23; // eax
  unsigned int v24; // edi
  unsigned int v25; // esi
  CBaseShader *v26; // ebx
  GImage *Image; // eax
  IMaterialVar **v28; // esi
  CBaseShader *v29; // edi
  int v30; // eax
  double v32; // [esp+14h] [ebp-450h]
  double v33; // [esp+1Ch] [ebp-448h]
  double v34; // [esp+24h] [ebp-440h]
  double v35; // [esp+24h] [ebp-440h]
  float v36; // [esp+2Ch] [ebp-438h] BYREF
  float v37; // [esp+30h] [ebp-434h]
  float v38; // [esp+34h] [ebp-430h]
  float v39; // [esp+38h] [ebp-42Ch]
  float v40; // [esp+3Ch] [ebp-428h]
  unsigned int *p_Height; // [esp+40h] [ebp-424h]
  float radius; // [esp+44h] [ebp-420h]
  unsigned int imgSize; // [esp+48h] [ebp-41Ch]
  CBaseShader *v44; // [esp+4Ch] [ebp-418h]
  float center; // [esp+50h] [ebp-414h]
  float v46; // [esp+54h] [ebp-410h]
  CBaseShader *v47; // [esp+58h] [ebp-40Ch]
  unsigned int y; // [esp+5Ch] [ebp-408h]
  _DWORD v49[255]; // [esp+60h] [ebp-404h] BYREF
  unsigned int v50; // [esp+45Ch] [ebp-8h]

  v4 = *(_BYTE *)(this + 8) == 0;
  v47 = nullptr;
  if ( v4 )
    v5 = 1.0;
  else
    v5 = 2.1700001;
  v6 = *(const struct GFxGradientRecord **)(this + 12);
  *(float *)&v44 = v5;
  GFxGradientRamp::Init(this: (GFxGradientRamp *)v49, a2: v6, a3: *(unsigned __int16 *)(this + 10), a4: *(float *)&v44);
  switch ( *(_BYTE *)(this + 9) )
  {
    case 0x10:
      Image = GImage::CreateImage(result: (ICachedPerFrameMeshData *)1, width: 0x100u, height: 1u, a4: pparams_4);
      v47 = (CBaseShader *)Image;
      if ( Image != nullptr )
      {
        v28 = nullptr;
        if ( Image->Width != 0 )
        {
          v29 = (CBaseShader *)Image;
          do
          {
            v30 = (int)v28;
            if ( (unsigned int)v28 >= 0x100 )
              v30 = 255;
            GImageBase::SetPixelRGBA(
              this: v29 + 2,
              x: v28,
              y: 0,
              color: (unsigned __int8)BYTE2(v49[v30])
            | (((unsigned __int8)BYTE1(v49[v30]) | (((unsigned __int8)v49[v30] | (HIBYTE(v49[v30]) << 8)) << 8)) << 8));
            v28 = (IMaterialVar **)((char *)v28 + 1);
          }
          while ( (CBaseShader_vtbl *)v28 < v29[3].__vftable );
        }
      }
      break;
    case 0x12:
      v18 = GFxGradientData::ComputeRadialGradientImageSize(
              (GFxGradientData *)this,
              a2: (struct GFxGradientParams *)result);
      imgSize = v18;
      v19 = GImage::CreateImage(result: (ICachedPerFrameMeshData *)1, width: v18, height: v18, a4: pparams_4);
      v47 = (CBaseShader *)v19;
      if ( v19 != nullptr )
      {
        v20 = v18 - 1;
        v21 = 1;
        center = (double)v19->Height * 0.5;
        radius = center - 1.0;
        if ( v18 - 1 > 1 )
        {
          v44 = (CBaseShader *)&v19->GImageBase;
          do
          {
            v22 = 1;
            *(float *)&y = (double)v21 - center + 0.5;
            v35 = *(float *)&y * *(float *)&y;
            do
            {
              *(float *)&y = (double)v22 - center + 0.5;
              *(float *)&y = *(float *)&y * *(float *)&y + v35;
              *(float *)&y = sqrt(*(float *)&y);
              *(float *)&y = *(float *)&y * 256.0 / radius + 0.5;
              *(float *)&y = floor(X: *(float *)&y);
              v23 = (int)*(float *)&y;
              if ( v23 >= 0x100 )
                v23 = 255;
              GImageBase::SetPixelRGBA(
                this: v44,
                x: (IMaterialVar **)v22++,
                y: v21,
                color: (unsigned __int8)BYTE2(v49[v23])
              | (((unsigned __int8)BYTE1(v49[v23]) | (((unsigned __int8)v49[v23] | (HIBYTE(v49[v23]) << 8)) << 8)) << 8));
            }
            while ( v22 < v20 );
            ++v21;
          }
          while ( v21 < v20 );
          v18 = imgSize;
        }
        v24 = 1;
        if ( v18 > 1 )
        {
          v25 = BYTE2(v50) | ((BYTE1(v50) | (((unsigned __int8)v50 | (HIBYTE(v50) << 8)) << 8)) << 8);
          v26 = v47 + 2;
          do
          {
            GImageBase::SetPixelRGBA(this: v26, x: (IMaterialVar **)v24, y: 0, color: v25);
            GImageBase::SetPixelRGBA(
              this: v26,
              x: (IMaterialVar **)((char *)&v47[3].__vftable[-1].OnDrawElements + 3),
              y: v24,
              color: v25);
            GImageBase::SetPixelRGBA(
              this: v26,
              x: (IMaterialVar **)((char *)v47[3].__vftable - v24 - 1),
              y: (unsigned int)&v47[4].__vftable[-1].OnDrawElements + 3,
              color: v25);
            GImageBase::SetPixelRGBA(this: v26, x: nullptr, y: (unsigned int)v47[4].__vftable - v24++ - 1, color: v25);
          }
          while ( v24 < imgSize );
        }
      }
      break;
    case 0x13:
      v7 = GFxGradientData::ComputeRadialGradientImageSize(
             (GFxGradientData *)this,
             a2: (struct GFxGradientParams *)result);
      imgSize = v7;
      v8 = GImage::CreateImage(result: (ICachedPerFrameMeshData *)1, width: v7, height: v7, a4: pparams_4);
      v47 = (CBaseShader *)v8;
      if ( v8 != nullptr )
      {
        p_Height = &v8->Height;
        y = v8->Height;
        v9 = v7 - 1;
        center = (double)y * 0.5;
        radius = center - 1.0;
        v36 = radius;
        v37 = radius * *(float *)(this + 16);
        v38 = 0.0;
        GFocalRadialGradient::updateValues(this: (GFocalRadialGradient *)&v36);
        v11 = 1;
        if ( v9 > 1 )
        {
          v44 = v10 + 2;
          do
          {
            v12 = v38;
            y = v11;
            v13 = 1;
            v46 = (double)v11 - center + 0.5;
            v46 = v46 - v38;
            v32 = v37 * v46;
            v33 = v46 * v46;
            v34 = v46 * v38;
            while ( 1 )
            {
              v46 = (double)v13 - center + 0.5;
              v46 = v46 - v37;
              *(float *)&y = v12 * v46 - v32;
              *(float *)&y = (v46 * v46 + v33) * v39 - *(float *)&y * *(float *)&y;
              *(float *)&y = fabs(*(float *)&y);
              *(float *)&y = sqrt(*(float *)&y);
              *(float *)&y = (*(float *)&y + v37 * v46 + v34) * v40;
              *(float *)&y = *(float *)&y * 256.0 / radius + 0.5;
              *(float *)&y = floor(X: *(float *)&y);
              v14 = (int)*(float *)&y;
              if ( v14 >= 0x100 )
                v14 = 255;
              GImageBase::SetPixelRGBA(
                this: v44,
                x: (IMaterialVar **)v13++,
                y: v11,
                color: (unsigned __int8)BYTE2(v49[v14])
              | (((unsigned __int8)BYTE1(v49[v14]) | (((unsigned __int8)v49[v14] | (HIBYTE(v49[v14]) << 8)) << 8)) << 8));
              if ( v13 >= v9 )
                break;
              v12 = v38;
            }
            ++v11;
          }
          while ( v11 < v9 );
        }
        v15 = 1;
        if ( imgSize > 1 )
        {
          v16 = BYTE2(v50) | ((BYTE1(v50) | (((unsigned __int8)v50 | (HIBYTE(v50) << 8)) << 8)) << 8);
          v17 = v47 + 2;
          do
          {
            GImageBase::SetPixelRGBA(this: v17, x: (IMaterialVar **)v15, y: 0, color: v16);
            GImageBase::SetPixelRGBA(
              this: v17,
              x: (IMaterialVar **)((char *)&v47[3].__vftable[-1].OnDrawElements + 3),
              y: v15,
              color: v16);
            GImageBase::SetPixelRGBA(
              this: v17,
              x: (IMaterialVar **)((char *)v47[3].__vftable - v15 - 1),
              y: *p_Height - 1,
              color: v16);
            GImageBase::SetPixelRGBA(this: v17, x: nullptr, y: *p_Height - v15++ - 1, color: v16);
          }
          while ( v15 < imgSize );
        }
      }
      break;
    default:
      break;
  }
  return (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),CFuncMemPolicyNone> *)v47;
}

//------------------------------------------------------------------------------
// Address: 0x1013CDC0
// Name: private: bool GFxFillStyle::GetImageFillTexture(struct GRenderer::FillTexture __near *,class GFxDisplayContext const __near &,float,class GMatrix2D const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxFillStyle::GetImageFillTexture(
        VertexShaderHandle_t__ *this,
        struct GRenderer::FillTexture *scaleMultiplier,
        const struct GFxDisplayContext *a3,
        float a4,
        const struct GMatrix2D *a5)
{
  GFxAmpViewStats *v5; // ebx
  int v7; // eax
  void *v8; // ecx
  int v9; // edx
  int v10; // edx
  char *v11; // ecx
  unsigned int Resource; // eax
  int v13; // edi
  int v14; // eax
  int v15; // ebx
  float *v16; // esi
  float *v17; // ecx
  int (__thiscall *v18)(int); // edx
  int (__thiscall *v19)(int); // edx
  double v20; // st7
  void *v21; // ecx
  float *v22; // eax
  double v23; // st7
  double v24; // st7
  int v25; // esi
  __int64 v26; // rax
  __int64 v28; // rax
  const CMaterialDict::MaterialLookup_t *v29; // [esp+0h] [ebp-78h]
  _DWORD v30[4]; // [esp+Ch] [ebp-6Ch] BYREF
  __int64 v31; // [esp+1Ch] [ebp-5Ch]
  GFxAmpViewStats *v32; // [esp+24h] [ebp-54h]
  float *v33; // [esp+34h] [ebp-44h]
  const struct GMatrix2D *v34; // [esp+38h] [ebp-40h]
  float v35; // [esp+3Ch] [ebp-3Ch]
  int li; // [esp+40h] [ebp-38h]
  struct GMatrix2D v37; // [esp+44h] [ebp-34h] BYREF
  GMatrix2D m; // [esp+5Ch] [ebp-1Ch] BYREF

  v5 = *((GFxAmpViewStats **)a3 + 36);
  v33 = (float *)scaleMultiplier;
  v7 = 0;
  v34 = a5;
  v32 = v5;
  if ( v5 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v5, swdHandle: 1u, swfOffset: 0x20u);
    GTimer::GetRawTicks(li: v8);
    HIDWORD(v31) = v9;
  }
  else
  {
    HIDWORD(v31) = 0;
  }
  v10 = *((_DWORD *)a3 + 18);
  LODWORD(v31) = v7;
  li = *(_DWORD *)(v10 + 12);
  GMatrix2D::SetIdentity(this: (float *)&m);
  v11 = (char *)(this + 2);
  if ( (*((_DWORD *)this + 2) == 0 && (Resource = *((_DWORD *)this + 3)) != 0
     || (Resource = GFxResourceHandle::GetResource(
                      this: (GFxResourceHandle *)v11,
                      a2: this,
                      pbinding: *((struct GFxResourceBinding **)a3 + 28))) != 0)
    && (v13 = *(_DWORD *)(Resource + 12)) != 0
    && (v35 = COERCE_FLOAT((*(int (__thiscall **)(int, int))(*(_DWORD *)v13 + 20))(a1: v13, a2: li))) != 0.0 )
  {
    v14 = *(_BYTE *)this - 64;
    v15 = 0;
    li = 1;
    switch ( v14 )
    {
      case 0:
        v15 = 0;
        li = 1;
        break;
      case 1:
        li = 1;
        goto LABEL_14;
      case 2:
        v15 = 0;
        li = 0;
        break;
      case 3:
        li = 0;
LABEL_14:
        v15 = 1;
        break;
      default:
        break;
    }
    m.M_[0][0] = *((float *)this + 4);
    m.M_[0][1] = *((float *)this + 5);
    m.M_[0][2] = *((float *)this + 6);
    m.M_[1][0] = *((float *)this + 7);
    m.M_[1][1] = *((float *)this + 8);
    m.M_[1][2] = *((float *)this + 9);
    if ( *(float *)&v34 != 0.0 )
      GMatrix2D::Append(this: &m, a2: v34);
    (*(void (__thiscall **)(int, _DWORD *))(*(_DWORD *)v13 + 28))(a1: v13, a2: v30);
    v16 = v33;
    v17 = v33 + 1;
    *v33 = v35;
    GMatrix2D::SetInverse(a1: v17, (const CMaterialDict::MaterialLookup_t *)&m, a3: v29);
    v37.M_[0][0] = a4;
    v37.M_[0][1] = 0.0;
    v37.M_[0][2] = 0.0;
    v37.M_[1][0] = 0.0;
    v37.M_[1][2] = 0.0;
    v37.M_[1][1] = a4;
    GMatrix2D::Prepend(this: (GMatrix2D *)(v16 + 1), a2: &v37);
    v18 = *(int (__thiscall **)(int))(*(_DWORD *)v13 + 4);
    v16[3] = (double)v30[0] + v16[3];
    v16[6] = (double)v30[1] + v16[6];
    v35 = COERCE_FLOAT(v18(a1: v13));
    v19 = *(int (__thiscall **)(int))(*(_DWORD *)v13 + 8);
    v35 = 1.0 / (double)LODWORD(v35);
    v20 = (double)(unsigned int)v19(a1: v13);
    v21 = (void *)li;
    v22 = v16;
    *(float *)&v34 = 1.0 / v20;
    v23 = v35;
    v16[1] = v35 * v16[1];
    v16[2] = v23 * v16[2];
    v16[3] = v23 * v16[3];
    v24 = *(float *)&v34;
    v16[4] = v16[4] * *(float *)&v34;
    v16[5] = v16[5] * v24;
    v16[6] = v24 * v16[6];
    v25 = (int)v32;
    *((_DWORD *)v22 + 7) = v15;
    *((_DWORD *)v22 + 8) = v21;
    if ( v25 != 0 )
    {
      GTimer::GetRawTicks(li: v21);
      GFxAmpViewStats::PopCallstack(this: v25, result: (GImageInfo *)1, swfOffset: 0x20u, funcTime: v26 - v31);
    }
    return 1;
  }
  else
  {
    if ( v5 != nullptr )
    {
      GTimer::GetRawTicks(li: v11);
      GFxAmpViewStats::PopCallstack(this: (int)v5, result: (GImageInfo *)1, swfOffset: 0x20u, funcTime: v28 - v31);
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013D020
// Name: public: class GImageInfoBase __near * GFxFillStyle::GetImageInfo(class GFxDisplayContext const __near &)const
// Source: json
//------------------------------------------------------------------------------
struct GImageInfoBase *__userpurge GFxFillStyle::GetImageInfo@<eax>(
        GFxResourceHandle *this@<ecx>,
        VertexShaderHandle_t__ *a2@<esi>,
        struct GFxResourceBinding **a3)
{
  unsigned int Resource; // eax

  if ( (*(_BYTE *)this & 0x50) != 0
    && (Resource = GFxResourceHandle::GetResource(this: this + 2, a2, pbinding: a3[28])) != 0 )
  {
    return *(struct GImageInfoBase **)(Resource + 12);
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013D050
// Name: public: void GFxFillStyle::SetLerp(class GFxFillStyle const __near &,class GFxFillStyle const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxFillStyle::SetLerp(
        GFxFillStyle *this@<ecx>,
        const struct GFxFillStyle *a2,
        const struct GFxFillStyle *a3,
        CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::Iterator_t result)
{
  const struct GFxFillStyle *v4; // esi
  char v5; // al
  int v7; // edx
  IShaderAPI *v8; // ecx
  int v9; // ebx
  _WORD *v10; // eax
  char v11; // dl
  _WORD *v12; // eax
  unsigned int v13; // ebx
  int v14; // edx
  double m_nIndex; // st7
  double v16; // st7
  double v17; // st6
  int v18; // eax
  IShaderDevice *v19; // ecx
  float v20; // [esp+8h] [ebp-24h]
  const CMorph::MorphSegment_t *v21; // [esp+Ch] [ebp-20h]
  CUtlFixedMemory<UtlLinkedListElem_t<COcclusionQueryMgr::OcclusionQueryObject_t,int> >::Iterator_t v22; // [esp+18h] [ebp-14h] BYREF
  int v23; // [esp+20h] [ebp-Ch]
  int v24; // [esp+24h] [ebp-8h]
  int v25; // [esp+28h] [ebp-4h] BYREF
  float v26; // [esp+34h] [ebp+8h]

  v4 = a2;
  v5 = *(_BYTE *)a2;
  *(_BYTE *)this = *(_BYTE *)a2;
  if ( v5 != 0 )
  {
    if ( (v5 & 0x10) != 0 )
    {
      v7 = *((_DWORD *)a3 + 1);
      v8 = *((IShaderAPI **)this + 1);
      v9 = *((_DWORD *)a2 + 1);
      v23 = v9;
      v24 = v7;
      if ( v8 != nullptr )
        GRefCountImpl::Release(this: v8);
      v25 = 258;
      v10 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 20, a3: &v25);
      if ( v10 != nullptr )
      {
        v11 = *(_BYTE *)a2;
        LOBYTE(v22.m_nIndex) = *((_BYTE *)a2 + 1) & 1;
        v12 = GFxGradientData::GFxGradientData(
                this: v10,
                a2: v11,
                recordCount: (const MeshInstanceData_t *)*(unsigned __int16 *)(v9 + 10),
                linearRgb: v22.m_nIndex);
      }
      else
      {
        v12 = nullptr;
      }
      *((_DWORD *)this + 1) = v12;
      if ( v12 != nullptr )
      {
        v13 = 0;
        if ( v12[5] != 0 )
        {
          do
          {
            v14 = v23;
            v22.m_nIndex = *(unsigned __int8 *)(*(_DWORD *)(v23 + 12) + 8 * v13);
            m_nIndex = (double)v22.m_nIndex;
            v22.m_nIndex = *(unsigned __int8 *)(*(_DWORD *)(v24 + 12) + 8 * v13);
            *(float *)&v25 = m_nIndex;
            v16 = *(float *)&result.m_pBlockHeader;
            *(float *)&v22.m_nIndex = *(float *)&v25
                                    + ((double)v22.m_nIndex - *(float *)&v25) * *(float *)&result.m_pBlockHeader;
            v17 = *(float *)&v22.m_nIndex;
            v22.m_nIndex = HIWORD(v25) | 0xC00;
            v18 = *(_DWORD *)(*((_DWORD *)this + 1) + 12);
            v22.m_nIndex = (int)(v17 + 0.5);
            *(_BYTE *)(8 * v13 + v18) = v22.m_nIndex;
            v20 = v16;
            *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 1) + 12) + 8 * v13 + 4) = GColor::Blend(
                                                                                   result: &v22,
                                                                                   a2: *(_DWORD *)(*(_DWORD *)(v14 + 12)
                                                                                             + 8 * v13
                                                                                             + 4),
                                                                                   a3: *(_DWORD *)(*(_DWORD *)(v24 + 12)
                                                                                             + 8 * v13
                                                                                             + 4),
                                                                                   f: v20)->m_pBlockHeader;
            ++v13;
          }
          while ( v13 < *(unsigned __int16 *)(*((_DWORD *)this + 1) + 10) );
          v4 = a2;
        }
      }
      v26 = (*(float *)(v24 + 16) - *(float *)(v23 + 16)) * *(float *)&result.m_pBlockHeader + *(float *)(v23 + 16);
      *(float *)(*((_DWORD *)this + 1) + 16) = v26;
      if ( *((_DWORD *)this + 2) == 0 )
      {
        v19 = *((IShaderDevice **)this + 3);
        if ( v19 != nullptr )
          GFxResource::Release(this: v19);
      }
      *((_DWORD *)this + 2) = 0;
      *((_DWORD *)this + 3) = 0;
    }
    else if ( (v5 & 0x40) != 0 )
    {
      GFxResourcePtr<GFxImageResource>::operator=(
        this: (CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> > *)((char *)this + 8),
        other: (int)a2 + 8,
        a3: v21);
    }
    GMatrix2D::SetLerp(
      this: (GMatrix2D *)((char *)this + 16),
      a2: (const struct GMatrix2D *)((char *)v4 + 16),
      a3: (const struct GMatrix2D *)((char *)a3 + 16),
      t: *(float *)&result.m_pBlockHeader);
  }
  else
  {
    *((_DWORD *)this + 1) = GColor::Blend(
                              &result,
                              a2: *((_DWORD *)a2 + 1),
                              a3: *((_DWORD *)a3 + 1),
                              f: *(float *)&result.m_pBlockHeader)->m_pBlockHeader;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013D2B0
// Name: public: GFxLineStyle::GFxLineStyle(class GFxLineStyle const __near &)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x1013D2E0
// Name: public: void GHashSet<unsigned int,class GFixedSizeHash<unsigned int>,class GFixedSizeHash<unsigned int>,struct GAllocatorLH<unsigned int,2>,class GHashsetCachedEntry<unsigned int,class GFixedSizeHash<unsigned int>>>::Add<unsigned int>(unsigned int const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GHashSet<unsigned int,GFixedSizeHash<unsigned int>,GFixedSizeHash<unsigned int>,GAllocatorLH<unsigned int,2>,GHashsetCachedEntry<unsigned int,GFixedSizeHash<unsigned int>>>::Add<unsigned int>(
        int *this,
        _DWORD *a2)
{
  int v2; // eax
  int v3; // edx
  int v4; // edi

  v2 = 4;
  v3 = 5381;
  do
  {
    v4 = *((unsigned __int8 *)a2 + --v2);
    v3 = v4 + 65599 * v3;
  }
  while ( v2 != 0 );
  return GHashSetBase<unsigned int,GFixedSizeHash<unsigned int>,GFixedSizeHash<unsigned int>,GAllocatorLH<unsigned int,2>,GHashsetCachedEntry<unsigned int,GFixedSizeHash<unsigned int>>>::add<unsigned int>(
           this,
           a2: (int)this,
           a3: a2,
           a4: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1013D320
// Name: public: class GFxImageResource __near * GFxGradientData::CreateImageResource(class GFxResourceWeakLib __near *,class GFxGradientParams __near *,class GFxImageCreator __near *,class GFxRenderConfig __near *,class GFxLog __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGradientData::CreateImageResource(
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),CFuncMemPolicyNone> *this,
        int pimage,
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),CFuncMemPolicyNone> *threadedLoading,
        int a4,
        int a5,
        int a6,
        int a7)
{
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),CFuncMemPolicyNone> *GradientImage; // eax
  int v10; // esi
  struct GImageInfoBase *v11; // edi
  int v12; // eax
  int (__thiscall *v13)(int, int, int *); // edx
  GFxImageResource *v14; // eax
  struct GFxResource *v15; // eax
  struct GFxResource *v16; // esi
  tagCBT_CREATEWNDW *ico; // [esp+Ch] [ebp-44h] BYREF
  int v18; // [esp+10h] [ebp-40h]
  int v19; // [esp+14h] [ebp-3Ch]
  int v20; // [esp+18h] [ebp-38h]
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),CFuncMemPolicyNone> *v21; // [esp+1Ch] [ebp-34h]
  int v22; // [esp+20h] [ebp-30h]
  int v23; // [esp+24h] [ebp-2Ch]
  int v24; // [esp+28h] [ebp-28h]
  int v25; // [esp+2Ch] [ebp-24h]
  int v26; // [esp+30h] [ebp-20h]
  int v27; // [esp+34h] [ebp-1Ch]
  char v28; // [esp+38h] [ebp-18h]
  GFxResourceKey src; // [esp+3Ch] [ebp-14h] BYREF
  GFxResourceLib::BindHandle v30; // [esp+44h] [ebp-Ch] BYREF
  GRefCountNTSImpl *pimagea; // [esp+58h] [ebp+8h]

  GFxResourceKey::GFxResourceKey(
    this: &src,
    a2: (struct GFxResourceKey::KeyInterface *)&GFxRectangle_DefaultParams.UseLocks,
    a3: this);
  v30.State = RS_Unbound;
  v30.pResource = nullptr;
  if ( GFxResourceWeakLib::BindResourceKey(this: pimage, result: (ShaderDeviceInfo_t *)&v30, a3: (int)&src) == 3 )
  {
    GradientImage = GFxGradientData::CreateGradientImage(
                      (int)this,
                      result: threadedLoading,
                      pparams_4: *(_DWORD *)(pimage + 40));
    pimagea = (GRefCountNTSImpl *)GradientImage;
    if ( GradientImage == nullptr )
      goto LABEL_13;
    v10 = *(_DWORD *)(pimage + 40);
    ico = (tagCBT_CREATEWNDW *)1;
    v20 = 1;
    v24 = a6;
    v21 = GradientImage;
    v11 = nullptr;
    v19 = 0;
    v18 = 2;
    v22 = 0;
    v23 = a5;
    v25 = 0;
    v26 = 0;
    v28 = a7;
    v27 = v10;
    if ( a4 != 0 )
    {
      v12 = (*(int (__thiscall **)(int, tagCBT_CREATEWNDW **))(*(_DWORD *)a4 + 4))(a1: a4, a2: &ico);
      v10 = v27;
      v11 = (struct GImageInfoBase *)v12;
    }
    v13 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v10 + 40);
    a7 = 2;
    v14 = (GFxImageResource *)v13(a1: v10, a2: 28, a3: &a7);
    if ( v14 != nullptr )
    {
      v15 = (struct GFxResource *)GFxImageResource::GFxImageResource(
                                    this: v14,
                                    a2: v11,
                                    (IShaderDevice *)&src,
                                    a4: Use_Gradient);
      v16 = v15;
      if ( v15 != nullptr )
        GFxResourceLib::ResourceSlot::Resolve(this: v30.pSlot, a2: v15);
    }
    else
    {
      v16 = nullptr;
    }
    if ( v11 != nullptr )
      GRefCountNTSImpl::Release(this: v11);
    if ( v16 == nullptr )
LABEL_13:
      GFxResourceLib::ResourceSlot::CancelResolve(this: v30.pSlot, a2: "Failed to create gradient");
    if ( pimagea != nullptr )
      GRefCountNTSImpl::Release(this: pimagea);
  }
  else
  {
    GFxResourceLib::BindHandle::WaitForResolve(this: &v30);
  }
  if ( v30.State == RS_Available )
  {
    GFxResource::Release(this: (IShaderDevice *)v30.pResource);
  }
  else if ( v30.State >= RS_WaitingResolve )
  {
    GRefCountImpl::Release(this: (IShaderAPI *)v30.pResource);
  }
  if ( src.pKeyInterface != nullptr )
    src.pKeyInterface->Release(this: src.pKeyInterface, a2: src.hKeyData);
}

//------------------------------------------------------------------------------
// Address: 0x1013D480
// Name: private: virtual bool GFxGradientImageResourceCreator::CreateResource(void __near *,struct GFxResourceBindData __near *,class GFxLoadStates __near *,class GMemoryHeap __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GFxGradientImageResourceCreator::CreateResource(
        GFxGradientImageResourceCreator *this,
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),CFuncMemPolicyNone> *a2,
        IShaderDevice **a3,
        struct GFxLoadStates *a4,
        struct GMemoryHeap *a5)
{
  BOOL v5; // ebx
  IShaderDevice *v6; // eax
  IShaderDevice *v7; // esi

  v5 = *((_BYTE *)a4 + 68) != 0 || *((_DWORD *)a4 + 6) != 0;
  GFxGradientData::CreateImageResource(
    this: a2,
    pimage: *((_DWORD *)a4 + 14),
    threadedLoading: *(CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),CFuncMemPolicyNone> **)(*((_DWORD *)a4 + 2) + 24),
    a4: *(_DWORD *)(*((_DWORD *)a4 + 2) + 16),
    a5: *((_DWORD *)a4 + 8),
    a6: *((_DWORD *)a4 + 3),
    a7: v5);
  v7 = v6;
  if ( *a3 != nullptr )
    GFxResource::Release(this: *a3);
  *a3 = v7;
  return v7 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1013D4E0
// Name: public: void GFxFillStyle::Read(class GFxLoadProcess __near *,enum GFxTagType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFillStyle::Read(
        CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *this,
        int i,
        struct GColor pc)
{
  int v3; // esi
  int v4; // ebx
  int v6; // eax
  int v7; // eax
  GArrayLH<GString,2,GArrayDefaultPolicy> *v8; // ecx
  char m_pfnProxied; // al
  GArrayLH<GString,2,GArrayDefaultPolicy> *v10; // ecx
  GFxStream *v11; // eax
  GFxStream *v12; // ecx
  int v13; // ebx
  int v14; // eax
  int v15; // eax
  char v16; // cl
  const MeshInstanceData_t *v17; // ebx
  _WORD *v18; // eax
  IShaderAPI *v19; // eax
  GArrayLH<GString,2,GArrayDefaultPolicy> *v20; // ecx
  char v21; // al
  int v22; // ebx
  IShaderDevice *v23; // eax
  int v24; // ecx
  int v25; // ecx
  char v26; // dl
  unsigned int Raw; // ecx
  int U16; // edx
  int v29; // eax
  int v30; // eax
  unsigned int v31; // ebx
  unsigned __int16 v32; // ax
  unsigned int v33; // ebx
  GArrayLH<GString,2,GArrayDefaultPolicy> *v34; // ecx
  int *v35; // ecx
  GFxStream *v36; // ecx
  tagBITMAPINFOHEADER *v37; // eax
  int v38; // [esp+0h] [ebp-1Ch]
  _TRIVERTEX *rh; // [esp+Ch] [ebp-10h] BYREF
  IShaderDevice *v40; // [esp+10h] [ebp-Ch]
  _IMAGE_CE_RUNTIME_FUNCTION_ENTRY resData; // [esp+14h] [ebp-8h] BYREF

  v3 = i;
  v4 = *(_DWORD *)(i + 804);
  if ( v4 == 0 )
    v4 = i + 40;
  v6 = *(_DWORD *)(v4 + 48) - *(_DWORD *)(v4 + 44);
  *(_BYTE *)(v4 + 21) = 0;
  if ( v6 < 1 )
    GFxStream::PopulateBuffer1(this: (void *)v4);
  v7 = *(_DWORD *)(v4 + 44);
  v8 = *(GArrayLH<GString,2,GArrayDefaultPolicy> **)(v4 + 60);
  LOBYTE(v8) = *((_BYTE *)&v8->Data.Data + v7);
  *(_DWORD *)(v4 + 44) = v7 + 1;
  LOBYTE(this->m_pfnProxied) = (_BYTE)v8;
  BYTE1(this->m_pfnProxied) = 0;
  GFxLogBase<GFxLoadProcess>::LogParse(this: v8, pfmt: v3 + 20, a3: (int)"  FillStyle read type = 0x%X\n", a4: (char)v8);
  m_pfnProxied = this->m_pfnProxied;
  if ( LOBYTE(this->m_pfnProxied) == 0 )
  {
    GFxLoadProcess::ReadRgbaTag(this: (_DWORD *)v3, &pc, a3: pc.Raw);
    GFxLogBase<GFxLoadProcess>::LogParse(this: v10, pfmt: v3 + 20, a3: (int)"  color: ", a4: v38);
    v11 = *(GFxStream **)(v3 + 804);
    if ( v11 == nullptr )
      v11 = (GFxStream *)(v3 + 40);
    GFxStream::LogParseClass(this: v11, a2: pc);
    if ( pc.Channels.Alpha != 0xFF )
      BYTE1(this->m_pfnProxied) |= 2u;
    *((float *)&this->m_pfnProxied + 1) = *(float *)&pc.Raw;
    return;
  }
  if ( (m_pfnProxied & 0x10) != 0 )
  {
    v12 = *(GFxStream **)(v3 + 804);
    if ( v12 == nullptr )
      v12 = (GFxStream *)(v3 + 40);
    GFxStream::ReadMatrix(this: v12, a2: (struct GMatrix2D *)&this->m_pObject);
    v13 = *(_DWORD *)(v3 + 804);
    if ( v13 == 0 )
      v13 = v3 + 40;
    v14 = *(_DWORD *)(v13 + 48) - *(_DWORD *)(v13 + 44);
    *(_BYTE *)(v13 + 21) = 0;
    if ( v14 < 1 )
      GFxStream::PopulateBuffer1(this: (void *)v13);
    v15 = *(_DWORD *)(v13 + 44);
    v16 = *(_BYTE *)(v15 + *(_DWORD *)(v13 + 60));
    *(_DWORD *)(v13 + 44) = v15 + 1;
    if ( (v16 & 0x10) != 0 )
      BYTE1(this->m_pfnProxied) |= 1u;
    i = 258;
    v17 = (const MeshInstanceData_t *)(v16 & 0xF);
    v18 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 20, a3: &i);
    if ( v18 != nullptr )
    {
      *((_BYTE *)&resData + 4) = BYTE1(this->m_pfnProxied) & 1;
      v19 = (IShaderAPI *)GFxGradientData::GFxGradientData(
                            this: v18,
                            a2: this->m_pfnProxied,
                            recordCount: v17,
                            linearRgb: *((bool *)&resData + 4));
    }
    else
    {
      v19 = nullptr;
    }
    DWORD1(this->m_pfnProxied) = v19;
    if ( v19 != nullptr )
    {
      v20 = (GArrayLH<GString,2,GArrayDefaultPolicy> *)HIWORD(v19[2].__vftable);
      if ( (_WORD)v20 == (_WORD)v17 )
      {
        v21 = (char)v17;
        i = 0;
        *((_DWORD *)&resData + 1) = v17;
        if ( (int)v17 > 0 )
        {
          do
          {
            v22 = *(_DWORD *)(v3 + 804);
            v23 = (IShaderDevice *)(8 * i + *(_DWORD *)(DWORD1(this->m_pfnProxied) + 12));
            v40 = v23;
            if ( v22 == 0 )
              v22 = v3 + 40;
            v24 = *(_DWORD *)(v22 + 48) - *(_DWORD *)(v22 + 44);
            *(_BYTE *)(v22 + 21) = 0;
            if ( v24 < 1 )
            {
              GFxStream::PopulateBuffer1(this: (void *)v22);
              v23 = v40;
            }
            v25 = *(_DWORD *)(v22 + 44);
            v26 = *(_BYTE *)(v25 + *(_DWORD *)(v22 + 60));
            *(_DWORD *)(v22 + 44) = v25 + 1;
            Raw = pc.Raw;
            LOBYTE(v23->__vftable) = v26;
            GFxLoadProcess::ReadRgbaTag(this: (_DWORD *)v3, pc: (struct GColor *)&v23[1], a3: Raw);
            v20 = *(GArrayLH<GString,2,GArrayDefaultPolicy> **)(DWORD1(this->m_pfnProxied) + 12);
            if ( *((_BYTE *)&v20->Data.Size + 8 * i + 3) != 0xFF )
              BYTE1(this->m_pfnProxied) |= 2u;
            ++i;
          }
          while ( i < *((int *)&resData + 1) );
          v21 = *((_BYTE *)&resData + 4);
        }
        GFxLogBase<GFxLoadProcess>::LogParse(
          this: v20,
          pfmt: v3 + 20,
          a3: (int)"  gradients: numGradients = %d\n",
          a4: v21);
        if ( LOBYTE(this->m_pfnProxied) == 19 )
        {
          U16 = (__int16)GFxLoadProcess::ReadU16(this: (GFxAmpMsgHandler *)v3);
          v29 = DWORD1(this->m_pfnProxied);
          *(float *)&pc.Raw = (double)U16 * 0.00390625;
          *(float *)(v29 + 16) = *(float *)&pc.Raw;
        }
        v30 = *(_DWORD *)(v3 + 32);
        v31 = *(_DWORD *)(v30 + 276);
        *(_DWORD *)(v30 + 276) = v31 + 1;
        if ( (*(_DWORD *)(*(_DWORD *)(v3 + 32) + 76) != 0 ? *(_DWORD *)(v3 + 32) + 76 : 0) != 0
          && (*(_BYTE *)(*(_DWORD *)(*(_DWORD *)(v3 + 32) + 76) != 0 ? *(_DWORD *)(v3 + 32) + 76 + 0x10 : 16) & 2) != 0 )
        {
          rh = nullptr;
          v40 = nullptr;
          if ( GFxMovieDataDef::LoadTaskData::GetResourceHandle(
                 this: *(CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)(v3 + 32),
                 phandle: &rh,
                 rid: v31) != 0 )
            GFxResourcePtr<GFxImageResource>::SetFromHandle(
              this: (CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> > *)((char *)&this->m_pfnProxied
                                                                                           + 8),
              src: (const GenericThreadLocals::CThreadLocal<int> *)&rh,
              a3: v38);
          if ( rh == nullptr && v40 != nullptr )
            GFxResource::Release(this: v40);
        }
        else
        {
          pc = *(struct GColor *)((char *)&this->m_pfnProxied + 4);
          (*(void (__thiscall **)(unsigned int *, struct GColor))(GFxRectangle_DefaultParams.HeapLock.cs.SpinCount + 4))(
            a1: &GFxRectangle_DefaultParams.HeapLock.cs.SpinCount,
            a2: pc);
          *((struct GColor *)&resData + 1) = pc;
          resData.FuncStart = (unsigned int)&GFxRectangle_DefaultParams.HeapLock.cs.SpinCount;
          GFxLoadProcess::AddDataResource(this: (int *)v3, a2: &rh, a3: v31, (void (__thiscall **)(CP4File *))&resData);
          if ( rh != nullptr || v40 != nullptr )
          {
            GFxResourcePtr<GFxImageResource>::SetFromHandle(
              this: (CUtlVector<CMorph::MorphSegment_t,CUtlMemory<CMorph::MorphSegment_t,int> > *)((char *)&this->m_pfnProxied
                                                                                           + 8),
              src: (const GenericThreadLocals::CThreadLocal<int> *)&rh,
              a3: v38);
            if ( rh == nullptr && v40 != nullptr )
              GFxResource::Release(this: v40);
          }
          if ( resData.FuncStart != 0 )
            (*(void (__thiscall **)(unsigned int, _DWORD))(*(_DWORD *)resData.FuncStart + 8))(
              a1: resData.FuncStart,
              a2: *((_DWORD *)&resData + 1));
        }
        return;
      }
      GRefCountImpl::Release(this: v19);
    }
    DWORD1(this->m_pfnProxied) = 0;
    LOBYTE(this->m_pfnProxied) = 0;
    return;
  }
  if ( (m_pfnProxied & 0x40) != 0 )
  {
    v32 = (unsigned __int16)GFxLoadProcess::ReadU16(this: (GFxAmpMsgHandler *)v3);
    v33 = v32;
    GFxLogBase<GFxLoadProcess>::LogParse(this: v34, pfmt: v3 + 20, a3: (int)"  BitmapChar = %d\n", a4: v32);
    if ( GFxMovieDataDef::LoadTaskData::GetResourceHandle(
           this: *(CUtlVector<TextureLodOverride::OverrideInfo,CUtlMemory<TextureLodOverride::OverrideInfo,int> > **)(v3 + 32),
           phandle: (_DWORD *)&this->m_pfnProxied + 2,
           rid: v33) != 0 )
    {
      v35 = *(int **)(v3 + 720);
      if ( v35 != nullptr && (LOBYTE(this->m_pfnProxied) == 66 || LOBYTE(this->m_pfnProxied) == 64) )
      {
        pc = *(struct GColor *)((char *)&this->m_pfnProxied + 12);
        GHashSet<unsigned int,GFixedSizeHash<unsigned int>,GFixedSizeHash<unsigned int>,GAllocatorLH<unsigned int,2>,GHashsetCachedEntry<unsigned int,GFixedSizeHash<unsigned int>>>::Add<unsigned int>(
          this: v35,
          a2: &pc);
      }
    }
    v36 = *(GFxStream **)(v3 + 804);
    if ( v36 == nullptr )
      v36 = (GFxStream *)(v3 + 40);
    GFxStream::ReadMatrix(this: v36, a2: (struct GMatrix2D *)&this->m_pObject);
    BYTE1(this->m_pfnProxied) |= 2u;
    v37 = *(tagBITMAPINFOHEADER **)(v3 + 804);
    if ( v37 == nullptr )
      v37 = (tagBITMAPINFOHEADER *)(v3 + 40);
    GFxStream::LogParseClass(
      this: v37,
      result: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)&this->m_pObject);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013D8C0
// Name: private: bool GFxFillStyle::GetGradientFillTexture(struct GRenderer::FillTexture __near *,class GFxDisplayContext const __near &,float,class GMatrix2D const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxFillStyle::GetGradientFillTexture(
        GFxFillStyle *this,
        struct GRenderer::FillTexture *scaleMultiplier,
        const struct GFxDisplayContext *a3,
        float a4,
        const struct GMatrix2D *a5)
{
  GFxAmpViewStats *v6; // ecx
  int v7; // eax
  void *v8; // ecx
  int v9; // edx
  void *v10; // ecx
  IShaderDevice *Resource; // edi
  IShaderDevice *v12; // eax
  IShaderDevice *v13; // ecx
  IShaderDevice_vtbl *v14; // edi
  GMatrix2D *p_TextureMatrix; // esi
  bool v16; // zf
  double v17; // st7
  void *v18; // ecx
  __int64 v19; // rax
  __int64 v21; // rax
  const CMaterialDict::MaterialLookup_t *v22; // [esp+0h] [ebp-64h]
  int v23; // [esp+10h] [ebp-54h]
  __int64 v24; // [esp+18h] [ebp-4Ch]
  int v25; // [esp+20h] [ebp-44h]
  GMatrix2D m; // [esp+30h] [ebp-34h] BYREF
  struct GMatrix2D v27; // [esp+48h] [ebp-1Ch] BYREF

  v6 = *((GFxAmpViewStats **)a3 + 36);
  v7 = 0;
  v25 = (int)v6;
  if ( v6 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v6, swdHandle: 1u, swfOffset: 0x1Fu);
    GTimer::GetRawTicks(li: v8);
    HIDWORD(v24) = v9;
  }
  else
  {
    HIDWORD(v24) = 0;
  }
  LODWORD(v24) = v7;
  v23 = *(_DWORD *)(*((_DWORD *)a3 + 18) + 12);
  GMatrix2D::SetIdentity(this: (float *)&m);
  Resource = (IShaderDevice *)GFxResourceHandle::GetResource(
                                this: (GFxResourceHandle *)this + 2,
                                a2: (VertexShaderHandle_t__ *)a3,
                                pbinding: *((struct GFxResourceBinding **)a3 + 28));
  if ( Resource == nullptr )
  {
    if ( *((_DWORD *)this + 2) == 1 )
      goto LABEL_20;
    GFxGradientData::CreateImageResource(
      this: *((CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),CFuncMemPolicyNone> **)this
      + 1),
      pimage: *((_DWORD *)a3 + 27),
      threadedLoading: *((CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),CFuncMemPolicyNone> **)a3
      + 22),
      a4: *((_DWORD *)a3 + 23),
      a5: *((_DWORD *)a3 + 18),
      a6: *((_DWORD *)a3 + 25),
      a7: 0);
    Resource = v12;
    if ( v12 == nullptr )
      goto LABEL_20;
    GRefCountImpl::AddRef(this: v12);
    if ( *((_DWORD *)this + 2) == 0 )
    {
      v13 = *((IShaderDevice **)this + 3);
      if ( v13 != nullptr )
        GFxResource::Release(this: v13);
    }
    *((_DWORD *)this + 2) = 0;
    *((_DWORD *)this + 3) = Resource;
    GFxResource::Release(this: Resource);
  }
  v14 = Resource[3].__vftable;
  if ( v14 != nullptr )
  {
    scaleMultiplier->pTexture = (GTexture *)(*((int (__thiscall **)(IShaderDevice_vtbl *, int))v14->ReleaseResources + 5))(
                                              a1: v14,
                                              a2: v23);
    scaleMultiplier->WrapMode = Wrap_Clamp;
    scaleMultiplier->SampleMode = Sample_Linear;
    p_TextureMatrix = &scaleMultiplier->TextureMatrix;
    GMatrix2D::SetIdentity(this: (float *)&scaleMultiplier->TextureMatrix);
    v16 = *(_BYTE *)this == 16;
    scaleMultiplier->TextureMatrix.M_[0][0] = scaleMultiplier->TextureMatrix.M_[0][0] * 0.000030517578125;
    scaleMultiplier->TextureMatrix.M_[0][1] = scaleMultiplier->TextureMatrix.M_[0][1] * 0.000030517578125;
    scaleMultiplier->TextureMatrix.M_[0][2] = scaleMultiplier->TextureMatrix.M_[0][2] * 0.000030517578125;
    scaleMultiplier->TextureMatrix.M_[1][0] = scaleMultiplier->TextureMatrix.M_[1][0] * 0.000030517578125;
    scaleMultiplier->TextureMatrix.M_[1][1] = scaleMultiplier->TextureMatrix.M_[1][1] * 0.000030517578125;
    scaleMultiplier->TextureMatrix.M_[1][2] = 0.000030517578125 * scaleMultiplier->TextureMatrix.M_[1][2];
    scaleMultiplier->TextureMatrix.M_[0][2] = scaleMultiplier->TextureMatrix.M_[0][2] + 0.5;
    if ( v16 )
      v17 = scaleMultiplier->TextureMatrix.M_[1][2] + 0.0;
    else
      v17 = scaleMultiplier->TextureMatrix.M_[1][2] + 0.5;
    scaleMultiplier->TextureMatrix.M_[1][2] = v17;
    m.M_[0][0] = *((float *)this + 4);
    m.M_[0][1] = *((float *)this + 5);
    m.M_[0][2] = *((float *)this + 6);
    m.M_[1][0] = *((float *)this + 7);
    m.M_[1][1] = *((float *)this + 8);
    m.M_[1][2] = *((float *)this + 9);
    if ( a5 != nullptr )
      GMatrix2D::Append(this: &m, a2: a5);
    GMatrix2D::SetIdentity(this: (float *)&v27);
    GMatrix2D::SetInverse(a1: (float *)&v27, (const CMaterialDict::MaterialLookup_t *)&m, a3: v22);
    GMatrix2D::Prepend(this: p_TextureMatrix, a2: &v27);
    v27.M_[0][0] = a4;
    v27.M_[0][1] = 0.0;
    v27.M_[0][2] = 0.0;
    v27.M_[1][0] = 0.0;
    v27.M_[1][2] = 0.0;
    v27.M_[1][1] = a4;
    GMatrix2D::Prepend(this: p_TextureMatrix, a2: &v27);
    if ( v25 != 0 )
    {
      GTimer::GetRawTicks(li: v18);
      GFxAmpViewStats::PopCallstack(this: v25, result: (GImageInfo *)1, swfOffset: 0x1Fu, funcTime: v19 - v24);
    }
    return 1;
  }
LABEL_20:
  if ( v25 != 0 )
  {
    GTimer::GetRawTicks(li: v10);
    GFxAmpViewStats::PopCallstack(this: v25, result: (GImageInfo *)1, swfOffset: 0x1Fu, funcTime: v21 - v24);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013DB00
// Name: public: void GFxLineStyle::Read(class GFxLoadProcess __near *,enum GFxTagType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxLineStyle::Read(
        CMemberFuncProxyBase<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(IMesh *,int),CFuncMemPolicyNone> *this,
        GFxAmpMsgHandler *p,
        unsigned __int8 *a3)
{
  int RefCount; // esi
  int v5; // eax
  int v6; // eax
  __int16 v7; // dx
  char v8; // bl
  int v9; // esi
  int v10; // edx
  int v11; // ecx
  __int16 v12; // dx
  CMemberFuncProxyBase<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(IMesh *,int),CFuncMemPolicyNone> *v13; // esi
  unsigned int RecvAddress; // edx
  int v15; // ecx
  int (__thiscall *v16)(int, int, int *); // eax
  int v17; // eax
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *v18; // esi
  int v19; // eax
  int v20; // esi
  int U16; // [esp+Ch] [ebp-34h] BYREF
  CMemberFuncProxyBase<CLateBoundPtr<IMesh>,void (__thiscall IMesh::*)(IMesh *,int),CFuncMemPolicyNone> *v22; // [esp+10h] [ebp-30h]
  __int16 v23; // [esp+14h] [ebp-2Ch] BYREF
  IShaderAPI *v24; // [esp+18h] [ebp-28h]
  int v25; // [esp+1Ch] [ebp-24h]
  IShaderDevice *v26; // [esp+20h] [ebp-20h]
  float v27[6]; // [esp+24h] [ebp-1Ch] BYREF

  RefCount = p[40].RefCount;
  v22 = this;
  if ( RefCount == 0 )
    RefCount = (int)&p[2];
  v5 = *(_DWORD *)(RefCount + 48) - *(_DWORD *)(RefCount + 44);
  *(_BYTE *)(RefCount + 21) = 0;
  if ( v5 < 2 )
    GFxStream::PopulateBuffer(this: RefCount, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
  v6 = *(_DWORD *)(RefCount + 44);
  v7 = *(_WORD *)(*(_DWORD *)(RefCount + 60) + v6);
  *(_DWORD *)(RefCount + 44) = v6 + 2;
  WORD2(this->m_pfnProxied) = v7;
  v8 = 0;
  if ( a3 == (unsigned __int8 *)83 )
  {
    v9 = p[40].RefCount;
    if ( v9 == 0 )
      v9 = (int)&p[2];
    v10 = *(_DWORD *)(v9 + 48) - *(_DWORD *)(v9 + 44);
    *(_BYTE *)(v9 + 21) = 0;
    if ( v10 < 2 )
      GFxStream::PopulateBuffer(this: v9, result: (_JOBOBJECT_BASIC_ACCOUNTING_INFORMATION *)2);
    v11 = *(_DWORD *)(v9 + 44);
    v12 = *(_WORD *)(*(_DWORD *)(v9 + 60) + v11);
    *(_DWORD *)(v9 + 44) = v11 + 2;
    v13 = v22;
    v8 = v12;
    LOWORD(v22->m_pObject.m_ppObject) = v12;
    if ( (v12 & 0x20) != 0 )
    {
      U16 = (unsigned __int16)GFxLoadProcess::ReadU16(this: p);
      *((float *)&v13->m_pObject + 1) = (double)U16 * 0.00390625;
    }
  }
  else
  {
    v13 = v22;
  }
  if ( (v8 & 8) == 0 )
  {
    GFxLoadProcess::ReadRgbaTag(this: p, pc: (struct GColor *)&v13->m_pfnProxied + 2, (int)a3);
    return;
  }
  v25 = 0;
  v26 = nullptr;
  GMatrix2D::SetIdentity(this: v27);
  RecvAddress = p[1].RecvAddress;
  v23 = 512;
  v24 = nullptr;
  v15 = *(_DWORD *)(RecvAddress + 28);
  v16 = *(int (__thiscall **)(int, int, int *))(*(_DWORD *)v15 + 40);
  U16 = 258;
  v17 = v16(a1: v15, a2: 40, a3: &U16);
  v18 = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *)v17;
  if ( v17 != 0 )
  {
    *(_DWORD *)(v17 + 8) = 0;
    *(_DWORD *)(v17 + 12) = 0;
    GMatrix2D::SetIdentity(this: (float *)(v17 + 16));
    LOWORD(v18->m_pfnProxied) = 512;
    DWORD1(v18->m_pfnProxied) = 0;
  }
  else
  {
    v18 = nullptr;
  }
  HIDWORD(v22->m_pfnProxied) = v18;
  if ( v18 == nullptr )
    v18 = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *)&v23;
  GFxFillStyle::Read(this: v18, i: (int)p, pc: (struct GColor)a3);
  if ( LOBYTE(v18->m_pfnProxied) != 0 )
  {
    if ( (v18->m_pfnProxied & 0x10) == 0 )
      goto LABEL_26;
    v20 = DWORD1(v18->m_pfnProxied);
    if ( v20 == 0 || *(_WORD *)(v20 + 10) == 0 )
      goto LABEL_26;
    v19 = *(_DWORD *)(*(_DWORD *)(v20 + 12) + 4);
  }
  else
  {
    v19 = DWORD1(v18->m_pfnProxied);
  }
  DWORD2(v22->m_pfnProxied) = v19;
LABEL_26:
  if ( (v23 & 0x10) != 0 && v24 != nullptr )
    GRefCountImpl::Release(this: v24);
  if ( v25 == 0 && v26 != nullptr )
    GFxResource::Release(this: v26);
}

//------------------------------------------------------------------------------
// Address: 0x1013DCD0
// Name: public: bool GFxFillStyle::GetFillTexture(struct GRenderer::FillTexture __near *,class GFxDisplayContext const __near &,float,class GMatrix2D const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall GFxFillStyle::GetFillTexture(
        GFxFillStyle *this,
        struct GRenderer::FillTexture *scaleMultiplier,
        const struct GFxDisplayContext *a3,
        float a4,
        const struct GMatrix2D *a5)
{
  if ( (*(_BYTE *)this & 0x10) != 0 )
    return GFxFillStyle::GetGradientFillTexture(this, scaleMultiplier, a3, a4, a5);
  if ( (*(_BYTE *)this & 0x40) != 0 )
    return GFxFillStyle::GetImageFillTexture((VertexShaderHandle_t__ *)this, scaleMultiplier, a3, a4, a5);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1013DD20
// Name: public: void GFxFillStyle::Apply(class GFxDisplayContext const __near &,float,class GMatrix2D const __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxFillStyle::Apply(
        VertexShaderHandle_t__ *this,
        const struct GFxDisplayContext *a2,
        float scaleMultiplier,
        const struct GMatrix2D *a4)
{
  char v5; // al
  int v6; // [esp+14h] [ebp-2Ch]
  struct GRenderer::FillTexture v7; // [esp+18h] [ebp-28h] BYREF

  v6 = *(_DWORD *)(*((_DWORD *)a2 + 18) + 12);
  if ( *(_BYTE *)this == 0 )
  {
    (*(void (__stdcall **)(_DWORD))(**(_DWORD **)(*((_DWORD *)a2 + 18) + 12) + 136))(a1: *((_DWORD *)this + 1));
    return;
  }
  GMatrix2D::SetIdentity(this: (float *)&v7.TextureMatrix);
  v5 = *(_BYTE *)this;
  v7.pTexture = nullptr;
  if ( (v5 & 0x10) != 0 )
  {
    GFxFillStyle::GetGradientFillTexture(
      (GFxFillStyle *)this,
      scaleMultiplier: &v7,
      a3: a2,
      a4: scaleMultiplier,
      a5: a4);
  }
  else
  {
    if ( (v5 & 0x40) == 0 )
      return;
    GFxFillStyle::GetImageFillTexture(this, scaleMultiplier: &v7, a3: a2, a4: scaleMultiplier, a5: a4);
  }
  if ( v7.pTexture != nullptr )
    (*(void (__stdcall **)(struct GRenderer::FillTexture *))(*(_DWORD *)v6 + 140))(a1: &v7);
}
