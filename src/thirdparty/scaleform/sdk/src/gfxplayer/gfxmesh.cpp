// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxmesh.cpp
// Functions: 21
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxmesh.h"

//------------------------------------------------------------------------------
// Address: 0x10149850
// Name: public: GFxTexture9Grid::GFxTexture9Grid(void)
// Source: json
//------------------------------------------------------------------------------
GFxTexture9Grid *__thiscall GFxTexture9Grid::GFxTexture9Grid(GFxTexture9Grid *this)
{
  *((float *)this + 1) = 0.0;
  *((float *)this + 2) = 0.0;
  *((float *)this + 3) = 0.0;
  *((float *)this + 4) = 0.0;
  *((float *)this + 5) = 0.0;
  *((float *)this + 6) = 0.0;
  *((float *)this + 7) = 0.0;
  *((float *)this + 8) = 0.0;
  *((float *)this + 10) = 0.0;
  *((float *)this + 11) = 0.0;
  *((float *)this + 12) = 0.0;
  *((float *)this + 13) = 0.0;
  *((float *)this + 14) = 0.0;
  *((float *)this + 15) = 0.0;
  *((float *)this + 16) = 0.0;
  *((float *)this + 17) = 0.0;
  *((float *)this + 19) = 0.0;
  *((float *)this + 20) = 0.0;
  *((float *)this + 21) = 0.0;
  *((float *)this + 22) = 0.0;
  *((float *)this + 23) = 0.0;
  *((float *)this + 24) = 0.0;
  *((float *)this + 25) = 0.0;
  *((float *)this + 26) = 0.0;
  *((float *)this + 28) = 0.0;
  *((float *)this + 29) = 0.0;
  *((float *)this + 30) = 0.0;
  *((float *)this + 31) = 0.0;
  *((float *)this + 32) = 0.0;
  *((float *)this + 33) = 0.0;
  *((float *)this + 34) = 0.0;
  *((float *)this + 35) = 0.0;
  *((float *)this + 37) = 0.0;
  *((float *)this + 38) = 0.0;
  *((float *)this + 39) = 0.0;
  *((float *)this + 40) = 0.0;
  *((float *)this + 41) = 0.0;
  *((float *)this + 42) = 0.0;
  *((float *)this + 43) = 0.0;
  *((float *)this + 44) = 0.0;
  *((float *)this + 46) = 0.0;
  *((float *)this + 47) = 0.0;
  *((float *)this + 48) = 0.0;
  *((float *)this + 49) = 0.0;
  *((float *)this + 50) = 0.0;
  *((float *)this + 51) = 0.0;
  *((float *)this + 52) = 0.0;
  *((float *)this + 53) = 0.0;
  *((float *)this + 55) = 0.0;
  *((float *)this + 56) = 0.0;
  *((float *)this + 57) = 0.0;
  *((float *)this + 58) = 0.0;
  *((float *)this + 59) = 0.0;
  *((float *)this + 60) = 0.0;
  *((float *)this + 61) = 0.0;
  *((float *)this + 62) = 0.0;
  *((float *)this + 64) = 0.0;
  *((float *)this + 65) = 0.0;
  *((float *)this + 66) = 0.0;
  *((float *)this + 67) = 0.0;
  *((float *)this + 68) = 0.0;
  *((float *)this + 69) = 0.0;
  *((float *)this + 70) = 0.0;
  *((float *)this + 71) = 0.0;
  *((float *)this + 73) = 0.0;
  *((float *)this + 74) = 0.0;
  *((float *)this + 75) = 0.0;
  *((float *)this + 76) = 0.0;
  *((float *)this + 77) = 0.0;
  *((float *)this + 78) = 0.0;
  *((float *)this + 79) = 0.0;
  *((float *)this + 80) = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1015A8B0
// Name: public: void GFxMesh::SetEdgeAAStyles(unsigned int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMesh::SetEdgeAAStyles(
        GFxMesh *this,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5)
{
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = a3;
  *((_DWORD *)this + 2) = a4;
  *((_DWORD *)this + 3) = a5;
}

//------------------------------------------------------------------------------
// Address: 0x1015A8D0
// Name: private: void GFxCachedStroke::BoundCheckPoint(class GPoint<float> __near *,float,float)
// Source: json
//------------------------------------------------------------------------------
void __stdcall GFxCachedStroke::BoundCheckPoint(float *a1, int a2, int a3)
{
  double v4; // st6
  double v5; // st5
  double v6; // st5
  double v7; // st6
  double v8; // rt2
  float v9; // [esp+8h] [ebp+8h]
  float v10; // [esp+8h] [ebp+8h]
  float v11; // [esp+8h] [ebp+8h]
  float v12; // [esp+8h] [ebp+8h]

  v9 = fabs(*a1);
  v4 = 32767.0;
  v5 = -32768.0;
  if ( v9 > 32767.0 )
  {
    if ( *a1 <= 32767.0 )
    {
      v10 = -32768.0;
      v6 = 32767.0;
      v7 = -32768.0;
    }
    else
    {
      v6 = 32767.0;
      v7 = -32768.0;
      v10 = 32767.0;
    }
    *a1 = v10;
    v8 = v6;
    v5 = v7;
    v4 = v8;
  }
  v11 = fabs(a1[1]);
  if ( v11 > 32767.0 )
  {
    if ( a1[1] <= 32767.0 )
      v12 = v5;
    else
      v12 = v4;
    a1[1] = v12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015A970
// Name: public: bool GFxMeshSet::MeshKeyFits(enum GFxMeshSet::KeyCategoryType,void const __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GFxMeshSet::MeshKeyFits(int this, int a2, unsigned __int8 *a3, unsigned int a4)
{
  unsigned int v4; // esi
  unsigned __int8 *v5; // edx
  unsigned __int8 *v6; // ecx

  if ( a2 == *(unsigned __int8 *)(this + 92) && a4 == *(unsigned __int8 *)(this + 93) )
  {
    v4 = a4;
    if ( a4 > 6 )
    {
      v5 = *(unsigned __int8 **)(this + 96);
      v6 = a3;
      while ( *(_DWORD *)v5 == *(_DWORD *)v6 )
      {
        v4 -= 4;
        v6 += 4;
        v5 += 4;
        if ( v4 < 4 )
          goto LABEL_11;
      }
    }
    else
    {
      v5 = a3;
      v6 = (unsigned __int8 *)(this + 94);
      if ( a4 < 4 )
      {
LABEL_11:
        if ( v4 == 0 )
          return true;
      }
      else
      {
        while ( *(_DWORD *)v5 == *(_DWORD *)v6 )
        {
          v4 -= 4;
          v6 += 4;
          v5 += 4;
          if ( v4 < 4 )
            goto LABEL_11;
        }
      }
    }
    return *v5 == *v6 && (v4 <= 1 || v5[1] == v6[1] && (v4 <= 2 || v5[2] == v6[2] && v4 <= 3));
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x1015AA40
// Name: public: unsigned long GFxMeshSet::GetNumStrokes(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxMeshSet::GetNumStrokes(GFxMeshSet *this)
{
  return *((_DWORD *)this + 28);
}

//------------------------------------------------------------------------------
// Address: 0x1015AA50
// Name: public: void GFxMesh::Display(class GFxDisplayContext const __near &,class GFxFillStyle const __near *,unsigned int,unsigned int,unsigned int,float,class GMatrix2D const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMesh::Display(
        GFxMesh *this,
        const struct GFxDisplayContext *a2,
        const struct GFxFillStyle *a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        float a7,
        const struct GMatrix2D *a8,
        bool a9)
{
  GFxAmpViewStats *v10; // ecx
  int v11; // eax
  void *v12; // ecx
  int v13; // edx
  bool v14; // zf
  int v15; // ebx
  GMatrix2D *p_TextureMatrix; // edi
  struct GRenderer::FillTexture *p_scaleMultiplier; // edi
  _DWORD *v18; // ebx
  const struct GMatrix2D *v19; // ecx
  const struct GMatrix2D *v20; // eax
  int v21; // ecx
  void (__thiscall *v22)(int, int, int, int, char **); // edx
  __int64 v23; // rax
  int v24; // [esp-8h] [ebp-CCh]
  __int64 v25; // [esp+14h] [ebp-B0h]
  int v26; // [esp+1Ch] [ebp-A8h]
  char *v27; // [esp+2Ch] [ebp-98h] BYREF
  char v28; // [esp+30h] [ebp-94h]
  struct GFxDisplayContext *v29; // [esp+34h] [ebp-90h]
  int v30; // [esp+38h] [ebp-8Ch]
  int v31; // [esp+3Ch] [ebp-88h]
  int v32; // [esp+40h] [ebp-84h]
  int v33; // [esp+44h] [ebp-80h]
  const struct GMatrix2D *v34; // [esp+48h] [ebp-7Ch]
  const struct GFxFillStyle *v35; // [esp+4Ch] [ebp-78h]
  int v36; // [esp+50h] [ebp-74h]
  struct GRenderer::FillTexture scaleMultiplier; // [esp+54h] [ebp-70h] BYREF

  v35 = a3;
  v34 = a8;
  v10 = *((GFxAmpViewStats **)a2 + 36);
  v11 = 0;
  v29 = a2;
  v26 = (int)v10;
  if ( v10 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v10, swdHandle: 1u, swfOffset: 7u);
    GTimer::GetRawTicks(li: v12);
    HIDWORD(v25) = v13;
  }
  else
  {
    HIDWORD(v25) = 0;
  }
  v14 = *((_DWORD *)this + 6) == 0;
  v15 = *(_DWORD *)(*((_DWORD *)a2 + 18) + 12);
  LODWORD(v25) = v11;
  v30 = v15;
  if ( !v14 )
  {
    if ( a9 )
    {
      v36 = 2;
      p_TextureMatrix = &scaleMultiplier.TextureMatrix;
      do
      {
        GMatrix2D::SetIdentity(this: (float *)p_TextureMatrix);
        p_TextureMatrix = (GMatrix2D *)((char *)p_TextureMatrix + 36);
        --v36;
      }
      while ( v36 >= 0 );
      v31 = 0;
      v32 = 0;
      v33 = 0;
      if ( a4 != 0 )
      {
        v36 = 0;
        if ( *(_DWORD *)this != 0 )
        {
          p_scaleMultiplier = &scaleMultiplier;
          v18 = (_DWORD *)((char *)this + 4);
          do
          {
            if ( v34 != nullptr )
              v19 = &v34[*v18];
            else
              v19 = nullptr;
            if ( *v18 != -1
              && GFxFillStyle::GetFillTexture(
                   this: (GFxFillStyle *)((char *)v35 + 40 * *v18),
                   scaleMultiplier: p_scaleMultiplier,
                   a3: v29,
                   a4: a7,
                   a5: v19) != 0 )
            {
              *(&v31 + v36) = (int)p_scaleMultiplier;
            }
            ++p_scaleMultiplier;
            ++v18;
            ++v36;
          }
          while ( (unsigned int)v36 < *(_DWORD *)this );
          v15 = v30;
        }
      }
      (*(void (__thiscall **)(int, _DWORD, int, int, int))(*(_DWORD *)v15 + 144))(
        a1: v15,
        a2: *((_DWORD *)this + 4),
        a3: v31,
        a4: v32,
        a5: v33);
    }
    else if ( a4 != 0 )
    {
      if ( v34 != nullptr )
        v20 = &v34[*((_DWORD *)this + 1)];
      else
        v20 = nullptr;
      GFxFillStyle::Apply(
        this: (VertexShaderHandle_t__ *)v35 + 10 * *((_DWORD *)this + 1),
        a2,
        scaleMultiplier: a7,
        a4: v20);
    }
    v21 = *((_DWORD *)this + 6);
    v22 = *(void (__thiscall **)(int, int, int, int, char **))(*(_DWORD *)v15 + 108);
    v27 = (char *)this + 32;
    v24 = *((_DWORD *)this + 5);
    v28 = 0;
    v22(a1: v15, a2: v24, a3: v21, a4: 1, a5: &v27);
    (*(void (__thiscall **)(int, unsigned int, _DWORD, unsigned int, _DWORD, unsigned int))(*(_DWORD *)v15 + 116))(
      a1: v15,
      a2: a5,
      a3: 0,
      a4: a6,
      a5: 0,
      a6: *((_DWORD *)this + 6) / 3u);
  }
  if ( v26 != 0 )
  {
    GTimer::GetRawTicks(li: v10);
    GFxAmpViewStats::PopCallstack(this: v26, result: (GImageInfo *)1, swfOffset: 7u, funcTime: v23 - v25);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015AC50
// Name: public: void GFxMeshSet::SetShapeBounds(class GRect<float> const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMeshSet::SetShapeBounds(float *this, float *a2, float a3)
{
  double v4; // st6
  double v5; // st6
  double v6; // st6
  double v7; // st6
  double v8; // st7
  double v9; // st7
  double v10; // st7
  double v11; // st7
  double v12; // st6
  float v13; // [esp+0h] [ebp-8h]
  float v14; // [esp+4h] [ebp-4h]
  float v15; // [esp+4h] [ebp-4h]
  int v16; // [esp+10h] [ebp+8h]
  int v17; // [esp+10h] [ebp+8h]
  int v18; // [esp+10h] [ebp+8h]
  float v19; // [esp+10h] [ebp+8h]
  float v20; // [esp+10h] [ebp+8h]
  float v21; // [esp+10h] [ebp+8h]
  float v22; // [esp+10h] [ebp+8h]

  v4 = a2[3];
  if ( v4 < 0.0 )
    v4 = -v4;
  *(float *)&v16 = v4;
  v5 = a2[1];
  if ( v5 < 0.0 )
    v5 = -v5;
  v14 = v5;
  v6 = *(float *)&v16;
  if ( v14 > (double)*(float *)&v16 )
    v6 = v14;
  v13 = v6;
  v7 = a2[2];
  if ( v7 < 0.0 )
    v7 = -v7;
  *(float *)&v17 = v7;
  v8 = *a2;
  if ( v8 < 0.0 )
    v8 = -v8;
  v15 = v8;
  v9 = *(float *)&v17;
  if ( v15 > (double)*(float *)&v17 )
    v9 = v15;
  *(float *)&v18 = v9;
  v10 = v13;
  if ( *(float *)&v18 > (double)v13 )
    v10 = *(float *)&v18;
  v19 = v10;
  v11 = v19;
  if ( v19 >= 0.0099999998 )
  {
    v20 = a3 + a3 + 50.0 + 20.0;
    v12 = v20;
    if ( v20 < 2000.0 )
      v12 = 2000.0;
    v21 = v12;
    v22 = v11 + v21;
    *(this + 3) = 32766.0 / v22;
    *(this + 4) = 1.0 / *(this + 3);
  }
  else
  {
    *(this + 3) = 1.0;
    *(this + 4) = 1.0 / *(this + 3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015AD80
// Name: public: void GFxMeshSet::SetMeshKey(enum GFxMeshSet::KeyCategoryType,void const __near *,unsigned int,class GFxCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMeshSet::SetMeshKey(int this, int a2, unsigned __int8 *src, unsigned int count, int a5)
{
  unsigned int v5; // ebx
  int v7; // ecx
  unsigned __int8 v8; // al

  v5 = count;
  v7 = a5;
  *(_BYTE *)(this + 92) = a2;
  v8 = *(_BYTE *)(this + 93);
  *(_DWORD *)(this + 100) = v7;
  if ( v5 != v8 )
  {
    if ( v8 > 6u )
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)(this + 96));
    if ( v5 > 6 )
    {
      a2 = 2;
      *(_DWORD *)(this + 96) = GMemory::pGlobalHeap->AllocAutoHeap_2(
                                 this: GMemory::pGlobalHeap,
                                 a2: this,
                                 a3: v5,
                                 a4: &a2);
    }
    *(_BYTE *)(this + 93) = v5;
  }
  if ( v5 > 6 )
    memcpy(dst: *(unsigned __int8 **)(this + 96), src, count: v5);
  else
    memcpy(dst: (unsigned __int8 *)(this + 94), src, count: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1015AF30
// Name: public: GFxTexture9Grid::GFxTexture9Grid(struct GFxTexture9Grid const __near &)
// Source: json
//------------------------------------------------------------------------------
GFxTexture9Grid *__thiscall GFxTexture9Grid::GFxTexture9Grid(GFxTexture9Grid *this, const struct GFxTexture9Grid *a2)
{
  GFxTexture9Grid *result; // eax
  float v4; // [esp+0h] [ebp-8h]
  float v5; // [esp+0h] [ebp-8h]
  float v6; // [esp+0h] [ebp-8h]
  float v7; // [esp+0h] [ebp-8h]
  float v8; // [esp+0h] [ebp-8h]
  float v9; // [esp+0h] [ebp-8h]
  float v10; // [esp+0h] [ebp-8h]
  float v11; // [esp+0h] [ebp-8h]
  float v12; // [esp+0h] [ebp-8h]
  float v13; // [esp+0h] [ebp-8h]
  float v14; // [esp+0h] [ebp-8h]
  float v15; // [esp+0h] [ebp-8h]
  float v16; // [esp+0h] [ebp-8h]
  float v17; // [esp+0h] [ebp-8h]
  float v18; // [esp+0h] [ebp-8h]
  float v19; // [esp+0h] [ebp-8h]
  float v20; // [esp+0h] [ebp-8h]
  float v21; // [esp+0h] [ebp-8h]
  float v22; // [esp+4h] [ebp-4h]
  float v23; // [esp+4h] [ebp-4h]
  float v24; // [esp+4h] [ebp-4h]
  float v25; // [esp+4h] [ebp-4h]
  float v26; // [esp+4h] [ebp-4h]
  float v27; // [esp+4h] [ebp-4h]
  float v28; // [esp+4h] [ebp-4h]
  float v29; // [esp+4h] [ebp-4h]
  float v30; // [esp+4h] [ebp-4h]
  float v31; // [esp+4h] [ebp-4h]
  float v32; // [esp+4h] [ebp-4h]
  float v33; // [esp+4h] [ebp-4h]
  float v34; // [esp+4h] [ebp-4h]
  float v35; // [esp+4h] [ebp-4h]
  float v36; // [esp+4h] [ebp-4h]
  float v37; // [esp+4h] [ebp-4h]
  float v38; // [esp+4h] [ebp-4h]
  float v39; // [esp+4h] [ebp-4h]
  float v40; // [esp+10h] [ebp+8h]
  float v41; // [esp+10h] [ebp+8h]
  float v42; // [esp+10h] [ebp+8h]
  float v43; // [esp+10h] [ebp+8h]
  float v44; // [esp+10h] [ebp+8h]
  float v45; // [esp+10h] [ebp+8h]
  float v46; // [esp+10h] [ebp+8h]
  float v47; // [esp+10h] [ebp+8h]
  float v48; // [esp+10h] [ebp+8h]
  float v49; // [esp+10h] [ebp+8h]
  float v50; // [esp+10h] [ebp+8h]
  float v51; // [esp+10h] [ebp+8h]
  float v52; // [esp+10h] [ebp+8h]
  float v53; // [esp+10h] [ebp+8h]
  float v54; // [esp+10h] [ebp+8h]
  float v55; // [esp+10h] [ebp+8h]
  float v56; // [esp+10h] [ebp+8h]
  float v57; // [esp+10h] [ebp+8h]

  result = this;
  *(float *)result = *(float *)a2;
  v40 = *((float *)a2 + 2);
  v22 = *((float *)a2 + 3);
  v4 = *((float *)a2 + 4);
  *((float *)result + 1) = *((float *)a2 + 1);
  *((float *)result + 2) = v40;
  *((float *)result + 3) = v22;
  *((float *)result + 4) = v4;
  v41 = *((float *)a2 + 6);
  v5 = *((float *)a2 + 7);
  v23 = *((float *)a2 + 8);
  *((float *)result + 5) = *((float *)a2 + 5);
  *((float *)result + 6) = v41;
  *((float *)result + 7) = v5;
  *((float *)result + 8) = v23;
  *((_DWORD *)result + 9) = *((_DWORD *)a2 + 9);
  v42 = *((float *)a2 + 11);
  v24 = *((float *)a2 + 12);
  v6 = *((float *)a2 + 13);
  *((float *)result + 10) = *((float *)a2 + 10);
  *((float *)result + 11) = v42;
  *((float *)result + 12) = v24;
  *((float *)result + 13) = v6;
  v43 = *((float *)a2 + 15);
  v7 = *((float *)a2 + 16);
  v25 = *((float *)a2 + 17);
  *((float *)result + 14) = *((float *)a2 + 14);
  *((float *)result + 15) = v43;
  *((float *)result + 16) = v7;
  *((float *)result + 17) = v25;
  *((_DWORD *)result + 18) = *((_DWORD *)a2 + 18);
  v44 = *((float *)a2 + 20);
  v26 = *((float *)a2 + 21);
  v8 = *((float *)a2 + 22);
  *((float *)result + 19) = *((float *)a2 + 19);
  *((float *)result + 20) = v44;
  *((float *)result + 21) = v26;
  *((float *)result + 22) = v8;
  v45 = *((float *)a2 + 24);
  v9 = *((float *)a2 + 25);
  v27 = *((float *)a2 + 26);
  *((float *)result + 23) = *((float *)a2 + 23);
  *((float *)result + 24) = v45;
  *((float *)result + 25) = v9;
  *((float *)result + 26) = v27;
  *((_DWORD *)result + 27) = *((_DWORD *)a2 + 27);
  v46 = *((float *)a2 + 29);
  v28 = *((float *)a2 + 30);
  v10 = *((float *)a2 + 31);
  *((float *)result + 28) = *((float *)a2 + 28);
  *((float *)result + 29) = v46;
  *((float *)result + 30) = v28;
  *((float *)result + 31) = v10;
  v47 = *((float *)a2 + 33);
  v11 = *((float *)a2 + 34);
  v29 = *((float *)a2 + 35);
  *((float *)result + 32) = *((float *)a2 + 32);
  *((float *)result + 33) = v47;
  *((float *)result + 34) = v11;
  *((float *)result + 35) = v29;
  *((_DWORD *)result + 36) = *((_DWORD *)a2 + 36);
  v48 = *((float *)a2 + 38);
  v30 = *((float *)a2 + 39);
  v12 = *((float *)a2 + 40);
  *((float *)result + 37) = *((float *)a2 + 37);
  *((float *)result + 38) = v48;
  *((float *)result + 39) = v30;
  *((float *)result + 40) = v12;
  v49 = *((float *)a2 + 42);
  v13 = *((float *)a2 + 43);
  v31 = *((float *)a2 + 44);
  *((float *)result + 41) = *((float *)a2 + 41);
  *((float *)result + 42) = v49;
  *((float *)result + 43) = v13;
  *((float *)result + 44) = v31;
  *((_DWORD *)result + 45) = *((_DWORD *)a2 + 45);
  v50 = *((float *)a2 + 47);
  v32 = *((float *)a2 + 48);
  v14 = *((float *)a2 + 49);
  *((float *)result + 46) = *((float *)a2 + 46);
  *((float *)result + 47) = v50;
  *((float *)result + 48) = v32;
  *((float *)result + 49) = v14;
  v51 = *((float *)a2 + 51);
  v15 = *((float *)a2 + 52);
  v33 = *((float *)a2 + 53);
  *((float *)result + 50) = *((float *)a2 + 50);
  *((float *)result + 51) = v51;
  *((float *)result + 52) = v15;
  *((float *)result + 53) = v33;
  *((_DWORD *)result + 54) = *((_DWORD *)a2 + 54);
  v52 = *((float *)a2 + 56);
  v34 = *((float *)a2 + 57);
  v16 = *((float *)a2 + 58);
  *((float *)result + 55) = *((float *)a2 + 55);
  *((float *)result + 56) = v52;
  *((float *)result + 57) = v34;
  *((float *)result + 58) = v16;
  v53 = *((float *)a2 + 60);
  v17 = *((float *)a2 + 61);
  v35 = *((float *)a2 + 62);
  *((float *)result + 59) = *((float *)a2 + 59);
  *((float *)result + 60) = v53;
  *((float *)result + 61) = v17;
  *((float *)result + 62) = v35;
  *((_DWORD *)result + 63) = *((_DWORD *)a2 + 63);
  v54 = *((float *)a2 + 65);
  v36 = *((float *)a2 + 66);
  v18 = *((float *)a2 + 67);
  *((float *)result + 64) = *((float *)a2 + 64);
  *((float *)result + 65) = v54;
  *((float *)result + 66) = v36;
  *((float *)result + 67) = v18;
  v55 = *((float *)a2 + 69);
  v19 = *((float *)a2 + 70);
  v37 = *((float *)a2 + 71);
  *((float *)result + 68) = *((float *)a2 + 68);
  *((float *)result + 69) = v55;
  *((float *)result + 70) = v19;
  *((float *)result + 71) = v37;
  *((_DWORD *)result + 72) = *((_DWORD *)a2 + 72);
  v56 = *((float *)a2 + 74);
  v38 = *((float *)a2 + 75);
  v20 = *((float *)a2 + 76);
  *((float *)result + 73) = *((float *)a2 + 73);
  *((float *)result + 74) = v56;
  *((float *)result + 75) = v38;
  *((float *)result + 76) = v20;
  v57 = *((float *)a2 + 78);
  v21 = *((float *)a2 + 79);
  v39 = *((float *)a2 + 80);
  *((float *)result + 77) = *((float *)a2 + 77);
  *((float *)result + 78) = v57;
  *((float *)result + 79) = v21;
  *((float *)result + 80) = v39;
  *((_DWORD *)result + 81) = *((_DWORD *)a2 + 81);
  *((_DWORD *)result + 82) = *((_DWORD *)a2 + 82);
  *((_DWORD *)result + 83) = *((_DWORD *)a2 + 83);
  *((_DWORD *)result + 84) = *((_DWORD *)a2 + 84);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015B600
// Name: public: void GFxMesh::AddTriangle(unsigned short,unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMesh::AddTriangle(GFxMesh *this, unsigned __int16 a2, unsigned __int16 a3, unsigned __int16 a4)
{
  unsigned int v4; // eax
  char *v5; // esi
  unsigned int v6; // edi
  _WORD *v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // edi
  _WORD *v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // edi
  _WORD *v13; // edx

  v4 = *((_DWORD *)this + 6);
  v5 = (char *)this + 20;
  v6 = v4 + 1;
  if ( v4 + 1 >= v4 )
  {
    if ( v6 >= *((_DWORD *)this + 7) )
      GArrayDataBase<unsigned short,GAllocatorLH<unsigned short,2>,GArrayDefaultPolicy>::Reserve(
        this: (void **)v5,
        a2: v5,
        a3: v6 + (v6 >> 2));
  }
  else if ( v6 < *((_DWORD *)this + 7) >> 1 )
  {
    GArrayDataBase<unsigned short,GAllocatorLH<unsigned short,2>,GArrayDefaultPolicy>::Reserve(
      this: (void **)v5,
      a2: v5,
      a3: v6);
  }
  v7 = (_WORD *)(*(_DWORD *)v5 + 2 * v6 - 2);
  *((_DWORD *)v5 + 1) = v6;
  if ( v7 != nullptr )
    *v7 = a2;
  v8 = *((_DWORD *)v5 + 1);
  v9 = v8 + 1;
  if ( v8 + 1 >= v8 )
  {
    if ( v9 >= *((_DWORD *)v5 + 2) )
      GArrayDataBase<unsigned short,GAllocatorLH<unsigned short,2>,GArrayDefaultPolicy>::Reserve(
        this: (void **)v5,
        a2: v5,
        a3: v9 + (v9 >> 2));
  }
  else if ( v9 < *((_DWORD *)v5 + 2) >> 1 )
  {
    GArrayDataBase<unsigned short,GAllocatorLH<unsigned short,2>,GArrayDefaultPolicy>::Reserve(
      this: (void **)v5,
      a2: v5,
      a3: v8 + 1);
  }
  v10 = (_WORD *)(*(_DWORD *)v5 + 2 * v9 - 2);
  *((_DWORD *)v5 + 1) = v9;
  if ( v10 != nullptr )
    *v10 = a3;
  v11 = *((_DWORD *)v5 + 1);
  v12 = v11 + 1;
  if ( v11 + 1 >= v11 )
  {
    if ( v12 >= *((_DWORD *)v5 + 2) )
      GArrayDataBase<unsigned short,GAllocatorLH<unsigned short,2>,GArrayDefaultPolicy>::Reserve(
        this: (void **)v5,
        a2: v5,
        a3: v12 + (v12 >> 2));
  }
  else if ( v12 < *((_DWORD *)v5 + 2) >> 1 )
  {
    GArrayDataBase<unsigned short,GAllocatorLH<unsigned short,2>,GArrayDefaultPolicy>::Reserve(
      this: (void **)v5,
      a2: v5,
      a3: v12);
  }
  v13 = *(_WORD **)v5;
  *((_DWORD *)v5 + 1) = v12;
  if ( &v13[v12] != (_WORD *)2 )
    v13[v12 - 1] = a4;
}

//------------------------------------------------------------------------------
// Address: 0x1015B6D0
// Name: public: void GFxMesh::AddTriangles(unsigned int,class GTessellator const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMesh::AddTriangles(GFxMesh *this, unsigned int a2, const struct GTessellator *a3)
{
  int v3; // eax
  unsigned int v4; // ebx
  unsigned int v5; // edi
  void **v6; // esi
  unsigned int v7; // edx
  int v8; // eax
  _WORD *v9; // ecx
  int v10; // [esp+0h] [ebp-4h]

  v3 = *((_DWORD *)this + 6);
  v10 = v3;
  if ( v3 == 0 )
  {
    *((_DWORD *)this + 1) = a2;
    *(_DWORD *)this = 1;
  }
  v4 = *((_DWORD *)a3 + 97);
  v5 = v4 + v3 + 2 * v4;
  v6 = (void **)((char *)this + 20);
  if ( v5 >= *((_DWORD *)this + 6) )
  {
    if ( v5 < *((_DWORD *)this + 7) )
      goto LABEL_9;
    GArrayDataBase<unsigned short,GAllocatorLH<unsigned short,2>,GArrayDefaultPolicy>::Reserve(
      this: v6,
      a2: v6,
      a3: v5 + (v5 >> 2));
  }
  else
  {
    if ( v5 >= *((_DWORD *)this + 7) >> 1 )
      goto LABEL_9;
    GArrayDataBase<unsigned short,GAllocatorLH<unsigned short,2>,GArrayDefaultPolicy>::Reserve(
      this: v6,
      a2: v6,
      a3: v4 + v3 + 2 * v4);
  }
  v3 = v10;
LABEL_9:
  v7 = 0;
  v6[1] = (void *)v5;
  if ( v4 != 0 )
  {
    v8 = 2 * v3;
    do
    {
      v9 = (_WORD *)(*(_DWORD *)(*((_DWORD *)a3 + 100) + 4 * (v7 >> 10)) + 12 * (v7 & 0x3FF));
      *(_WORD *)((char *)*v6 + v8) = *v9;
      *(_WORD *)((char *)*v6 + v8 + 2) = v9[2];
      *(_WORD *)((char *)*v6 + v8 + 4) = v9[4];
      ++v7;
      v8 += 6;
    }
    while ( v7 < v4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015B790
// Name: public: void GFxMesh::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMesh::Clear(GFxMesh *this)
{
  int v2; // ecx
  void **v3; // esi

  v2 = *((_DWORD *)this + 8);
  if ( v2 != 0 )
    (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)v2 + 112))(a1: v2, a2: (char *)this + 32, a3: 2);
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  v3 = (void **)((char *)this + 20);
  if ( *((_DWORD *)this + 6) != 0 )
  {
    if ( (*((_DWORD *)this + 7) & 0xFFFFFFFE) != 0 )
    {
      if ( *v3 != nullptr )
      {
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v3);
        *v3 = nullptr;
      }
      *((_DWORD *)this + 7) = 0;
    }
  }
  else if ( *((_DWORD *)this + 7) == 0 )
  {
    GArrayDataBase<unsigned short,GAllocatorLH<unsigned short,2>,GArrayDefaultPolicy>::Reserve(
      this: (void **)this + 5,
      a2: (char *)this + 20,
      a3: 0);
  }
  *((_DWORD *)this + 6) = 0;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 1) = -1;
  *((_DWORD *)this + 2) = -1;
  *((_DWORD *)this + 3) = -1;
}

//------------------------------------------------------------------------------
// Address: 0x1015B810
// Name: public: void GFxCachedStroke::AddShapePathVertices(class GCompoundShape const __near &,unsigned int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCachedStroke::AddShapePathVertices(
        GFxCachedStroke *this,
        const struct GCompoundShape *a2,
        unsigned int a3,
        float a4)
{
  _DWORD *v4; // esi
  unsigned int v5; // eax
  unsigned int v6; // edi
  void **v7; // ebx
  unsigned int v8; // edi
  double v9; // st7
  GRenderer::CachedData *v10; // edi
  unsigned int v11; // esi
  GRenderer *pRenderer; // edx
  int v13; // [esp+8h] [ebp-8h]
  const struct GCompoundShape *v15; // [esp+18h] [ebp+8h]
  unsigned int v16; // [esp+1Ch] [ebp+Ch]
  unsigned int v17; // [esp+1Ch] [ebp+Ch]

  v4 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)a2 + 9) + 4 * (a3 >> 6)) + 24 * (a3 & 0x3F));
  v5 = *((_DWORD *)this + 2);
  v16 = v5;
  if ( v5 == 0 )
    *(_DWORD *)this = v4[5];
  v13 = 2 * v4[1];
  v6 = v5 + v13;
  v7 = (void **)((char *)this + 4);
  v15 = (const struct GCompoundShape *)v4[1];
  if ( v5 + v13 >= *((_DWORD *)this + 2) )
  {
    if ( v6 >= *((_DWORD *)this + 3) )
      GArrayDataBase<unsigned short,GAllocatorLH<unsigned short,2>,GArrayDefaultPolicy>::Reserve(
        this: v7,
        a2: v7,
        a3: v6 + (v6 >> 2));
  }
  else if ( v6 < *((_DWORD *)this + 3) >> 1 )
  {
    GArrayDataBase<unsigned short,GAllocatorLH<unsigned short,2>,GArrayDefaultPolicy>::Reserve(this: v7, a2: v7, a3: v6);
  }
  v7[1] = (void *)v6;
  v8 = 0;
  if ( v15 != nullptr )
  {
    v9 = a4;
    v17 = 2 * v16;
    do
    {
      *(_WORD *)((char *)*v7 + v17) = (int)(*(float *)(*(_DWORD *)(*(_DWORD *)(*v4 + 20) + 4 * ((v8 + v4[2]) >> 8))
                                                     + 8 * (unsigned __int8)(v8 + *((_BYTE *)v4 + 8)))
                                          * v9);
      *(_WORD *)((char *)*v7 + v17 + 2) = (int)(*(float *)(*(_DWORD *)(*(_DWORD *)(*v4 + 20) + 4 * ((v8 + v4[2]) >> 8))
                                                         + 8 * (unsigned __int8)(v8 + *((_BYTE *)v4 + 8))
                                                         + 4)
                                              * v9);
      ++v8;
      v17 += 4;
    }
    while ( v8 < (unsigned int)v15 );
  }
  v10 = (GRenderer::CachedData *)((char *)this + 24);
  v11 = *((_DWORD *)this + 7) + 1;
  if ( v11 >= *((_DWORD *)this + 7) )
  {
    if ( v11 >= *((_DWORD *)this + 8) )
      GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
        this: v10,
        pheapAddr: v10,
        newCapacity: v11 + (v11 >> 2));
  }
  else if ( v11 < *((_DWORD *)this + 8) >> 1 )
  {
    GArrayDataBase<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,GAllocatorLH<GPtr<GFxAmpMovieInstructionStats::ScriptBufferStats>,2>,GArrayDefaultPolicy>::Reserve(
      this: v10,
      pheapAddr: v10,
      newCapacity: *((_DWORD *)this + 7) + 1);
  }
  pRenderer = v10->pRenderer;
  *((_DWORD *)this + 7) = v11;
  if ( (GRenderer *)((char *)pRenderer + 4 * v11) != (GRenderer *)4 )
    *((_DWORD *)pRenderer + v11 - 1) = v13;
}

//------------------------------------------------------------------------------
// Address: 0x1015BA00
// Name: public: GFxCachedStroke::~GFxCachedStroke(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxCachedStroke::~GFxCachedStroke(GFxCachedStroke *this)
{
  int v2; // ecx
  int v3; // ecx
  int v4; // esi
  int v5; // ecx

  v2 = *((_DWORD *)this + 20);
  if ( v2 != 0 )
    (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)v2 + 112))(a1: v2, a2: (char *)this + 80, a3: 1);
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 21) = 0;
  v3 = *((_DWORD *)this + 4);
  if ( v3 != 0 )
    (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)v3 + 112))(a1: v3, a2: (char *)this + 16, a3: 1);
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  v4 = *((_DWORD *)this + 9);
  if ( v4 != 0 )
  {
    v5 = *(_DWORD *)(v4 + 32);
    if ( v5 != 0 )
      (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v5 + 112))(a1: v5, a2: v4 + 32, a3: 2);
    *(_DWORD *)(v4 + 32) = 0;
    *(_DWORD *)(v4 + 36) = 0;
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)(v4 + 20));
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: (void *)v4);
  }
  GFxVertexArray::~GFxVertexArray(this: (GFxCachedStroke *)((char *)this + 60));
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 6));
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 1));
}

//------------------------------------------------------------------------------
// Address: 0x1015BAB0
// Name: public: bool GFxCachedStroke::Display(class GFxDisplayContext __near &,class GFxLineStyle const __near &,class GMatrix2D const __near &,float,float,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __userpurge GFxCachedStroke::Display@<al>(
        GFxCachedStroke *this@<ecx>,
        const CMaterialDict::MaterialLookup_t *a2@<edi>,
        struct GFxDisplayContext *a3,
        const struct GFxLineStyle *a4,
        const struct GMatrix2D *a5,
        float a6,
        float a7,
        bool a8,
        bool a9,
        bool a10)
{
  double v10; // st7
  int v11; // edx
  const struct GFxLineStyle *v13; // edi
  float v14; // ecx
  int v15; // esi
  int v16; // eax
  bool v17; // cl
  int v18; // ecx
  bool v19; // zf
  double v20; // st6
  double v21; // st5
  double v22; // st7
  double v23; // st7
  double v24; // st7
  double v25; // st7
  double v26; // st7
  char v27; // al
  double v28; // st7
  double v29; // st6
  int v30; // ecx
  _DWORD *v31; // eax
  GMatrix2D *v32; // edi
  int v33; // edx
  int v34; // ecx
  unsigned int v35; // eax
  float v36; // eax
  int v37; // eax
  int v38; // ecx
  int v39; // eax
  int v40; // edx
  float v41; // ecx
  int v42; // ecx
  int v43; // eax
  const struct GFxLineStyle *v44; // edi
  GStrokerAA *v45; // ecx
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  double v50; // st7
  double v51; // st6
  double v52; // st7
  double v53; // st7
  char v54; // al
  int v55; // edx
  GFxVertexArray *v56; // edi
  _DWORD *v57; // eax
  int v58; // eax
  double v59; // st7
  int v60; // ecx
  float v61; // edx
  int v62; // eax
  float v63; // edx
  int v64; // edx
  int v65; // ecx
  float v66; // eax
  float v67; // ecx
  int v68; // eax
  _DWORD *v69; // eax
  int v70; // ecx
  int v71; // ecx
  int v72; // edx
  double v73; // st7
  int v74; // eax
  unsigned int j; // edi
  int v76; // ecx
  int v77; // ecx
  double v78; // st7
  const struct GFxLineStyle *v79; // ecx
  int v80; // eax
  int v81; // eax
  int v82; // eax
  int v83; // eax
  double v84; // st6
  double v85; // st6
  int v86; // edx
  bool v87; // al
  int v88; // ecx
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *v89; // edi
  const struct GFxFillStyle *v90; // eax
  bool SolidMesh; // al
  const struct GFxLineStyle *v92; // eax
  _DWORD *v93; // eax
  unsigned int v94; // edi
  int v95; // eax
  int v96; // edx
  int v97; // ecx
  int v98; // eax
  double v99; // st7
  float *v100; // ecx
  int v101; // eax
  unsigned int i; // edi
  char v103; // al
  char v104; // cl
  double v105; // st7
  struct GRenderer *v106; // edx
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *v107; // edx
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *v108; // eax
  unsigned int v109; // ecx
  unsigned int v111; // eax
  unsigned int v112; // esi
  unsigned int v113; // edi
  int v114; // eax
  float v115; // [esp+18h] [ebp-D8h]
  float v116; // [esp+18h] [ebp-D8h]
  char *t; // [esp+1Ch] [ebp-D4h]
  const CMaterialDict::MaterialLookup_t *v118; // [esp+20h] [ebp-D0h]
  int v119; // [esp+20h] [ebp-D0h]
  char *v120; // [esp+2Ch] [ebp-C4h] BYREF
  char v121; // [esp+30h] [ebp-C0h]
  float v122; // [esp+34h] [ebp-BCh]
  float v123; // [esp+38h] [ebp-B8h]
  CCountedStringPoolBase<unsigned int>::hash_item_t v124; // [esp+3Ch] [ebp-B4h] BYREF
  char *pString; // [esp+48h] [ebp-A8h]
  float v126; // [esp+4Ch] [ebp-A4h]
  int v127; // [esp+50h] [ebp-A0h] BYREF
  struct GRenderer::CacheProvider p; // [esp+54h] [ebp-9Ch] BYREF
  float XScale; // [esp+5Ch] [ebp-94h]
  float v130; // [esp+60h] [ebp-90h]
  int v131; // [esp+64h] [ebp-8Ch]
  float v132; // [esp+68h] [ebp-88h]
  int v133; // [esp+6Ch] [ebp-84h]
  const struct GFxLineStyle *v134; // [esp+70h] [ebp-80h]
  float v135; // [esp+74h] [ebp-7Ch]
  float v136; // [esp+78h] [ebp-78h]
  float Rotation; // [esp+7Ch] [ebp-74h]
  char v138; // [esp+83h] [ebp-6Dh]
  GMatrix2D *v139; // [esp+84h] [ebp-6Ch]
  float v140; // [esp+88h] [ebp-68h]
  char v141; // [esp+8Eh] [ebp-62h]
  char v142; // [esp+8Fh] [ebp-61h]
  float v143; // [esp+90h] [ebp-60h] BYREF
  CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> v144; // [esp+94h] [ebp-5Ch] BYREF
  struct GMatrix2D v145; // [esp+BCh] [ebp-34h] BYREF
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > m; // [esp+D4h] [ebp-1Ch] BYREF

  v10 = 1.0;
  v11 = *((_DWORD *)a3 + 18);
  v140 = 1.0;
  Rotation = 1.0;
  v118 = a2;
  v13 = a4;
  v139 = a5;
  LODWORD(v14) = *((unsigned __int16 *)a4 + 2);
  *(_DWORD *)&v124.nReferenceCount = a3;
  v15 = *(_DWORD *)(*((_DWORD *)a3 + 26) + 16);
  v16 = *((_DWORD *)a4 + 3);
  v143 = v14;
  v138 = !a9;
  v134 = a4;
  v133 = v11;
  v142 = 1;
  v130 = (float)SLODWORD(v14);
  if ( v16 != 0 )
    v17 = (*(_BYTE *)(v16 + 1) & 2) != 0;
  else
    v17 = *((_BYTE *)a4 + 11) != 0xFF;
  if ( v17 )
    v138 = 0;
  v18 = *(_DWORD *)(v11 + 20);
  if ( (v18 & 0x10) == 0 || (v19 = (*(_DWORD *)(v11 + 28) & 0x100) == 0, v141 = 1, v19) )
    v141 = 0;
  if ( v16 != 0 && (*(_DWORD *)(v133 + 28) & 0x200) == 0 )
    v141 = 0;
  if ( (v18 & 3) == 2 || *((_WORD *)a4 + 2) == 0 )
  {
    (*(void (__thiscall **)(const struct GFxLineStyle *, _DWORD))(*(_DWORD *)a4 + 4))(
      a1: a4,
      a2: *(_DWORD *)(v133 + 12));
    v120 = (char *)this + 16;
    v111 = *((_DWORD *)this + 2);
    v121 = 0;
    (*(void (__thiscall **)(_DWORD, _DWORD, unsigned int, int, char **))(**(_DWORD **)(v133 + 12) + 104))(
      a1: *(_DWORD *)(v133 + 12),
      a2: *((_DWORD *)this + 1),
      a3: v111 >> 1,
      a4: 1,
      a5: &v120);
    v112 = 0;
    v113 = 0;
    if ( *((_DWORD *)this + 7) != 0 )
    {
      v114 = *((_DWORD *)this + 6);
      do
      {
        (*(void (__thiscall **)(_DWORD, unsigned int, int))(**(_DWORD **)(v133 + 12) + 120))(
          a1: *(_DWORD *)(v133 + 12),
          a2: v113 >> 1,
          a3: (*(_DWORD *)(v114 + 4 * v112) >> 1) - 1);
        v114 = *((_DWORD *)this + 6);
        v113 += *(_DWORD *)(v114 + 4 * v112++);
      }
      while ( v112 < *((_DWORD *)this + 7) );
    }
    return 0;
  }
  if ( a10 )
  {
    XScale = 1.0;
    *(float *)&v131 = 1.0;
  }
  else
  {
    XScale = GMatrix2D::GetXScale(this: v139);
    *(float *)&v131 = GMatrix2D::GetYScale(this: v139);
    v10 = 1.0;
  }
  v20 = XScale;
  v21 = *(float *)&v131;
  switch ( *((_WORD *)a4 + 8) & 6 )
  {
    case 0:
      v143 = v21 * v21 + v20 * v20;
      v143 = sqrt(v143);
      v19 = (*(_BYTE *)(v133 + 20) & 3) == 0;
      Rotation = v143 * 0.7071067690849304;
      if ( v19 || a10 )
      {
        v140 = Rotation;
      }
      else
      {
        v142 = 0;
        v140 = 1.0;
      }
      break;
    case 2:
      Rotation = GMatrix2D::GetRotation(this: v139);
      v143 = Rotation + 0.7853981852531433;
      v143 = cos(v143);
      v24 = v143;
      if ( v143 <= 0.0 )
        v24 = 0.0;
      v136 = v24;
      v143 = cos(Rotation);
      v132 = v143 * XScale;
      v143 = sin(Rotation);
      v143 = v143 * *(float *)&v131;
      v143 = v143 * v143 + v132 * v132;
      v143 = sqrt(v143);
      v25 = v143;
      v143 = v136 * 1.414213538169861;
      v140 = v25 * v143;
      Rotation = v140;
      break;
    case 4:
      Rotation = GMatrix2D::GetRotation(this: v139);
      v143 = Rotation - 0.7853981852531433;
      v143 = cos(v143);
      v22 = v143;
      if ( v143 <= 0.0 )
        v22 = 0.0;
      v136 = v22;
      v143 = sin(Rotation);
      v132 = v143 * XScale;
      v143 = cos(Rotation);
      v143 = v143 * *(float *)&v131;
      v143 = v143 * v143 + v132 * v132;
      v143 = sqrt(v143);
      v23 = v143;
      v143 = v136 * 1.414213538169861;
      v140 = v23 * v143;
      Rotation = v140;
      break;
    case 6:
      v140 = v10;
      v143 = v21 * v21 + v20 * v20;
      v143 = sqrt(v143);
      Rotation = v143 * 0.7071067690849304;
      break;
    default:
      break;
  }
  v143 = v130 * Rotation * *(float *)(*(_DWORD *)&v124.nReferenceCount + 116);
  if ( *(float *)(v133 + 24) * 20.0 >= v143 )
    v138 = 1;
  if ( v142 == 0 && v143 < 20.0 )
    v130 = 20.0 / (Rotation * *(float *)(*(_DWORD *)&v124.nReferenceCount + 116));
  v19 = *((_DWORD *)this + 9) == 0;
  v130 = v130 * v140;
  v26 = v130;
  if ( v19 )
  {
    LODWORD(v143) = 2;
    v31 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 40, a4: &v143);
    if ( v31 != nullptr )
    {
      v31[5] = 0;
      v31[6] = 0;
      v31[7] = 0;
      v31[8] = 0;
      v31[9] = 0;
      *v31 = 0;
      v31[1] = -1;
      v31[2] = -1;
      v31[3] = -1;
      v31[4] = 0;
    }
    else
    {
      v31 = nullptr;
    }
    *((_DWORD *)this + 9) = v31;
    if ( v31 == nullptr )
      return 0;
LABEL_57:
    GMatrix2D::SetIdentity(this: (float *)&m);
    GMatrix2D::SetIdentity(this: (float *)&v145);
    if ( (*(_BYTE *)(v133 + 20) & 0x10) == 0
      || (*(_DWORD *)(v133 + 28) & 0x100) == 0
      || (v19 = *((_BYTE *)this + 44) == 0, v141 = 1, !v19) )
    {
      v141 = 0;
    }
    if ( *((_DWORD *)a4 + 3) != 0 && (*(_DWORD *)(v133 + 28) & 0x200) == 0 )
      v141 = 0;
    if ( a8 && (*(_DWORD *)(v133 + 32) & 0x10) == 0 )
    {
      if ( (*(_DWORD *)(v133 + 28) & 0x1000) != 0 )
        v141 = 0;
      else
        a8 = false;
    }
    if ( v142 != 0 )
    {
      *(float *)&m.m_Memory.m_pMemory = v139->M_[0][0];
      *(float *)&m.m_Size = v139->M_[1][0];
      *(float *)&m.m_Memory.m_nAllocationCount = v139->M_[0][1];
      *(float *)&m.m_pElements = v139->M_[1][1];
      GMatrix2D::SetInverse(a1: (float *)&v145, (const CMaterialDict::MaterialLookup_t *)&m, a3: v118);
    }
    GCompoundShape::Clear(this: (GCompoundShape *)(v15 + 8));
    v140 = 0.0;
    *(float *)&v139 = 0.0;
    if ( *((_DWORD *)this + 7) != 0 )
    {
      do
      {
        v32 = *(GMatrix2D **)(*((_DWORD *)this + 6) + 4 * LODWORD(v140));
        t = *(char **)this;
        v136 = *(float *)&v32;
        GCompoundShape::BeginPath(this: (GCompoundShape *)(v15 + 8), lStyle: -1, rStyle: -1, a4: t);
        if ( v142 != 0 )
        {
          if ( *(float *)&v32 != 0.0 )
          {
            LODWORD(v135) = (((unsigned int)&v32[-1].M_[1][2] + 3) >> 1) + 1;
            do
            {
              v33 = *((_DWORD *)this + 1);
              v34 = *(__int16 *)(v33 + 2 * (_DWORD)v139 + 2);
              LODWORD(v143) = *(__int16 *)(v33 + 2 * (_DWORD)v139);
              v132 = (float)v34;
              *(float *)&p.pData = (float)SLODWORD(v143);
              *(float *)&p.DiscardSharedData = v132;
              GMatrix2D::Transform(this: &m, result: &v124, (float *)&p, p_4: (int)v118);
              v35 = *(_DWORD *)(v15 + 16);
              pString = v124.pString;
              LODWORD(v36) = v35 >> 8;
              v136 = v36;
              v126 = *(float *)&v124.nNextElement;
              if ( LODWORD(v36) >= *(_DWORD *)(v15 + 20) )
                GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(
                  this: (unsigned int *)(v15 + 16),
                  a2: LODWORD(v36));
              v37 = *(_DWORD *)(v15 + 16);
              v38 = *(_DWORD *)(*(_DWORD *)(v15 + 28) + 4 * LODWORD(v136));
              v139 = (GMatrix2D *)((char *)v139 + 2);
              *(float *)(v38 + 8 * (unsigned __int8)v37) = *(float *)&pString;
              *(float *)(v38 + 8 * (unsigned __int8)v37 + 4) = v126;
              ++*(_DWORD *)(v15 + 16);
              ++*(_DWORD *)(*(_DWORD *)(v15 + 48) + 4);
              --LODWORD(v135);
            }
            while ( v135 != 0.0 );
          }
        }
        else if ( *(float *)&v32 != 0.0 )
        {
          LODWORD(v135) = ((unsigned int)(LODWORD(v136) - 1) >> 1) + 1;
          do
          {
            v39 = *((_DWORD *)this + 1);
            v40 = *(__int16 *)(v39 + 2 * (_DWORD)v139);
            LODWORD(v41) = *(_DWORD *)(v15 + 16) >> 8;
            LODWORD(v143) = *(__int16 *)(v39 + 2 * (_DWORD)v139 + 2);
            v136 = v41;
            v122 = (float)v40;
            v123 = (float)SLODWORD(v143);
            if ( LODWORD(v41) >= *(_DWORD *)(v15 + 20) )
            {
              GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(
                this: (unsigned int *)(v15 + 16),
                a2: LODWORD(v41));
              v41 = v136;
            }
            v42 = *(_DWORD *)(*(_DWORD *)(v15 + 28) + 4 * LODWORD(v41));
            v43 = *(_DWORD *)(v15 + 16);
            v139 = (GMatrix2D *)((char *)v139 + 2);
            *(float *)(v42 + 8 * (unsigned __int8)v43) = v122;
            *(float *)(v42 + 8 * (unsigned __int8)v43 + 4) = v123;
            ++*(_DWORD *)(v15 + 16);
            ++*(_DWORD *)(*(_DWORD *)(v15 + 48) + 4);
            --LODWORD(v135);
          }
          while ( v135 != 0.0 );
        }
        ++LODWORD(v140);
      }
      while ( LODWORD(v140) < *((_DWORD *)this + 7) );
    }
    if ( v138 == 0 )
    {
      GTessellator::Clear(this: (GTessellator *)(v15 + 196));
      *(_DWORD *)(v15 + 176) = 0;
      *(_BYTE *)(v15 + 192) = 0;
      GCompoundShape::Clear(this: (GCompoundShape *)(v15 + 80));
      v78 = a6;
      v135 = -10.0 * a6 / *(float *)(*(_DWORD *)&v124.nReferenceCount + 116);
      if ( v142 == 0 )
        v135 = v135 / Rotation;
      *(float *)&v139 = v130 * v78;
      if ( v141 != 0 )
      {
        *(float *)&v139 = v135 + v135 + *(float *)&v139;
        if ( *(float *)&v139 < 1.0 )
          *(float *)&v139 = 1.0;
      }
      v79 = v134;
      v80 = *((_WORD *)v134 + 8) & 0x30;
      if ( v80 == 16 )
        v81 = 4;
      else
        v81 = v80 != 32 ? 3 : 0;
      *(_DWORD *)(v15 + 160) = v81;
      if ( (*((_WORD *)v79 + 8) & 0xC0) == 0x40 )
      {
        v82 = 0;
      }
      else if ( (*((_WORD *)v79 + 8) & 0xC0) == 0x80 )
      {
        v82 = 1;
      }
      else
      {
        v82 = 2;
      }
      *(_DWORD *)(v15 + 164) = v82;
      if ( ((*((unsigned __int16 *)v79 + 8) >> 2) & 0xC0) == 0x40 )
      {
        v83 = 0;
      }
      else if ( ((*((unsigned __int16 *)v79 + 8) >> 2) & 0xC0) == 0x80 )
      {
        v83 = 1;
      }
      else
      {
        v83 = 2;
      }
      v84 = *(float *)&v139;
      *(_DWORD *)(v15 + 168) = v83;
      v143 = v84 * 0.5;
      v85 = v143;
      *(float *)(v15 + 152) = v143;
      if ( v85 < 0.0 )
        v85 = -v85;
      v143 = v85;
      *(float *)(v15 + 156) = v143;
      if ( (*((_BYTE *)v79 + 16) & 0x30) == 0x20 )
        *(float *)(v15 + 172) = *((float *)v79 + 5);
      v143 = v78 * a7;
      GCompoundShape::SetCurveTolerance(this: (long double *)(v15 + 80), t: (char *)LODWORD(v143));
      GStroker::generateEquidistant(
        this: (_FPIEEE_RECORD *)(v15 + 152),
        srcShape: (unsigned int *)(v15 + 8),
        srcStyle: *(_DWORD *)this,
        dstShape: v15 + 80,
        bothSides: (long double *)1,
        j: (long double *)v118);
      v86 = v133;
      *(_DWORD *)(v15 + 196) = 0;
      v87 = (*(_DWORD *)(v86 + 20) & 0x20) != 0;
      *(_BYTE *)(v15 + 201) = v87;
      *(_BYTE *)(v15 + 202) = v87;
      *(_BYTE *)(v15 + 203) = v87;
      *(_BYTE *)(v15 + 200) = 1;
      GTessellator::Monotonize(
        this: (GTessellator *)(v15 + 196),
        a2: (const struct GCompoundShape *)(v15 + 80),
        addStyle: 1);
      ++*(_DWORD *)(v15 + 940);
      if ( *(_DWORD *)(v15 + 456) == 0 )
        goto LABEL_197;
      v88 = *((_DWORD *)this + 20);
      v89 = (CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> *)((char *)this + 80);
      if ( v88 != 0 )
        (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)v88 + 112))(a1: v88, a2: (char *)this + 80, a3: 1);
      v19 = v141 == 0;
      LODWORD(v89->m_pfnProxied) = 0;
      *((_DWORD *)this + 21) = 0;
      *((_BYTE *)this + 45) = 0;
      if ( !v19 )
      {
        v90 = *((const struct GFxFillStyle **)v134 + 3);
        v127 = 0;
        p.pData = nullptr;
        *(_DWORD *)&p.DiscardSharedData = 0;
        if ( v90 != nullptr )
        {
          GArrayBase<GArrayData<GFxFillStyle,GAllocatorGH<GFxFillStyle,259>,GArrayDefaultPolicy>>::PushBack(
            this: &v127,
            a2: v90);
        }
        else
        {
          GFxFillStyle::GFxFillStyle(this: &v144);
          DWORD1(v144.m_pfnProxied) = *((_DWORD *)v134 + 2);
          GArrayBase<GArrayData<GFxFillStyle,GAllocatorGH<GFxFillStyle,259>,GArrayDefaultPolicy>>::PushBack(
            this: &v127,
            a2: (const struct GFxFillStyle *)&v144);
          GFxFillStyle::~GFxFillStyle(this: &v144);
        }
        GFxEdgeAAGenerator::ProcessAndSortEdges(
          a1: v15 + 776,
          a2: v15 + 196,
          a3: v127,
          a4: p.pData,
          a5: LODWORD(v135),
          a6: 0,
          a7: *((_DWORD *)v134 + 3) != 0 ? 0xFFFFFF : 0);
        if ( GFxEdgeAAGenerator::GetVertexCount(this: (GFxEdgeAAGenerator *)(v15 + 776)) <= 0xFFFE )
        {
          *((_BYTE *)this + 46) = a8;
          if ( a8 || *((_DWORD *)v134 + 3) != 0 )
            GFxVertexArray::SetFormat(this: (GFxCachedStroke *)((char *)this + 60), a2: Vertex_XY16iCF32);
          else
            GFxVertexArray::SetFormat(this: (GFxCachedStroke *)((char *)this + 60), a2: Vertex_XY16iC32);
          if ( v142 != 0 )
            SolidMesh = GFxEdgeAAGenerator::GenerateSolidMesh(
                          this: (GFxEdgeAAGenerator *)(v15 + 776),
                          a2: (GFxCachedStroke *)((char *)this + 60),
                          a3: *((struct GFxMesh **)this + 9),
                          a4: &v145);
          else
            SolidMesh = GFxEdgeAAGenerator::GenerateSolidMesh(
                          this: (GFxEdgeAAGenerator *)(v15 + 776),
                          a2: (GFxCachedStroke *)((char *)this + 60),
                          a3: *((struct GFxMesh **)this + 9),
                          a4: 1.0);
          v89 = *(CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> **)(*(_DWORD *)&v124.nReferenceCount + 76);
          if ( v89 != nullptr )
            HIDWORD(v89->m_pfnProxied) += *(_DWORD *)(*((_DWORD *)this + 9) + 24) / 3u;
          if ( SolidMesh )
          {
            v92 = v134;
            *((_BYTE *)this + 45) = 1;
            if ( *((_DWORD *)v92 + 3) != 0 )
            {
              v93 = *((_DWORD **)this + 9);
              *v93 = 1;
              v93[1] = 0;
              v93[2] = -1;
              v93[3] = -1;
              *(_DWORD *)(*((_DWORD *)this + 9) + 16) = 1;
            }
          }
        }
        GArray<GFxFillStyle,259,GArrayDefaultPolicy>::~GArray<GFxFillStyle,259,GArrayDefaultPolicy>(a1: &v127, a2: v89);
      }
      if ( *((_BYTE *)this + 45) != 0 )
        goto LABEL_197;
      GFxVertexArray::SetFormat(this: (GFxCachedStroke *)((char *)this + 60), a2: Vertex_XY16i);
      GFxVertexArray::Resize(this: (GFxCachedStroke *)((char *)this + 60), a2: *(_DWORD *)(v15 + 456));
      v94 = 0;
      if ( v142 != 0 )
      {
        if ( *(_DWORD *)(v15 + 456) != 0 )
        {
          do
          {
            v95 = *(_DWORD *)(*(_DWORD *)(v15 + 468) + 4 * (v94 >> 10));
            v96 = v94 & 0x3FF;
            p.pData = *(GRenderer::CachedData **)(v95 + 8 * v96);
            *(float *)&p.DiscardSharedData = *(float *)(v95 + 8 * v96 + 4);
            GMatrix2D::Transform(
              this: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)&v145,
              result: &v124,
              (float *)&p,
              p_4: v119);
            GFxCachedStroke::BoundCheckPoint(a1: (float *)&v124, a2: SLODWORD(XScale), a3: v131);
            (*(void (__thiscall **)(_DWORD, unsigned int, char *, unsigned int, _DWORD))(**(_DWORD **)(*((_DWORD *)this + 18) + 8)
                                                                                       + 4))(
              a1: *(_DWORD *)(*((_DWORD *)this + 18) + 8),
              a2: *((_DWORD *)this + 17) + v94 * *(_DWORD *)(*((_DWORD *)this + 18) + 4),
              a3: v124.pString,
              a4: v124.nNextElement,
              a5: 0);
            ++v94;
          }
          while ( v94 < *(_DWORD *)(v15 + 456) );
        }
      }
      else if ( *(_DWORD *)(v15 + 456) != 0 )
      {
        do
        {
          v97 = *(_DWORD *)(*(_DWORD *)(v15 + 468) + 4 * (v94 >> 10));
          v98 = v94 & 0x3FF;
          v99 = *(float *)(v97 + 8 * v98 + 4);
          v100 = (float *)(v97 + 8 * v98);
          v101 = *((_DWORD *)this + 17) + v94 * *(_DWORD *)(*((_DWORD *)this + 18) + 4);
          *(_DWORD *)&p.DiscardSharedData = *(_DWORD *)(*((_DWORD *)this + 18) + 8);
          v116 = v99;
          (*(void (__thiscall **)(_DWORD, int, float, _DWORD, _DWORD))(**(_DWORD **)&p.DiscardSharedData + 4))(
            a1: *(_DWORD *)&p.DiscardSharedData,
            a2: v101,
            a3: *v100,
            a4: LODWORD(v116),
            a5: 0);
          ++v94;
        }
        while ( v94 < *(_DWORD *)(v15 + 456) );
      }
      for ( i = 0; i < *(_DWORD *)(v15 + 536); ++i )
      {
        GTessellator::TriangulateMonotone(this: (GTessellator *)(v15 + 196), idx: i);
        GFxMesh::AddTriangles(this: *((GFxMesh **)this + 9), a2: 0, a3: (const struct GTessellator *)(v15 + 196));
      }
      v77 = *(_DWORD *)(*(_DWORD *)&v124.nReferenceCount + 76);
LABEL_195:
      if ( v77 != 0 )
        *(_DWORD *)(v77 + 12) += *(_DWORD *)(*((_DWORD *)this + 9) + 24) / 3u;
LABEL_197:
      v103 = v138;
      v104 = v142;
      *((float *)this + 10) = v130;
      v13 = v134;
      *((float *)this + 13) = XScale;
      v105 = *(float *)&v131;
      *((_BYTE *)this + 47) = v103;
      *((float *)this + 14) = v105;
      *((_BYTE *)this + 48) = v104;
      *((_BYTE *)this + 46) = a8;
      goto LABEL_198;
    }
    v44 = v134;
    v45 = (GStrokerAA *)(v15 + 664);
    *(_DWORD *)(v15 + 708) = 0;
    *(_BYTE *)(v15 + 724) = 0;
    *(_DWORD *)(v15 + 728) = 0;
    *(_DWORD *)(v15 + 744) = 0;
    if ( (*((_WORD *)v44 + 8) & 0xC0) == 0x40 )
    {
      v46 = 0;
    }
    else if ( (*((_WORD *)v44 + 8) & 0xC0) == 0x80 )
    {
      v46 = 1;
    }
    else
    {
      v46 = 2;
    }
    *(_DWORD *)(v15 + 668) = v46;
    if ( ((*((unsigned __int16 *)v44 + 8) >> 2) & 0xC0) == 0x40 )
    {
      v47 = 0;
    }
    else if ( ((*((unsigned __int16 *)v44 + 8) >> 2) & 0xC0) == 0x80 )
    {
      v47 = 1;
    }
    else
    {
      v47 = 2;
    }
    *(_DWORD *)(v15 + 672) = v47;
    v48 = *((_WORD *)v44 + 8) & 0x30;
    if ( v48 == 16 )
      v49 = 4;
    else
      v49 = v48 != 32 ? 3 : 0;
    v45->pNext = (EHRegistrationNode *)v49;
    if ( (*((_BYTE *)v44 + 16) & 0x30) == 0x20 )
      *(float *)(v15 + 676) = *((float *)v44 + 5);
    v50 = a6;
    *(float *)(v15 + 704) = a6 * a7;
    if ( v141 != 0 )
    {
      v135 = 20.0 * v50 / *(float *)(*(_DWORD *)&v124.nReferenceCount + 116);
      if ( v142 == 0 )
        v135 = v135 / Rotation;
      v51 = v135;
      *(float *)(v15 + 700) = v135;
      *(float *)(v15 + 696) = v51;
      v143 = v50 * v130 - v51;
      v52 = 0.0;
      if ( v143 >= 0.0 )
        v52 = v143;
      v136 = v52;
      v143 = v136 * 0.5;
      v53 = v143;
    }
    else
    {
      *(float *)(v15 + 700) = 0.0;
      *(float *)(v15 + 696) = 0.0;
      v143 = v50 * v130;
      v143 = v143 * 0.5;
      v53 = v143;
    }
    *(float *)(v15 + 692) = v53;
    *(float *)(v15 + 688) = v53;
    GStrokerAA::Tessellate(this: v45, a2: (const struct GCompoundShape *)(v15 + 8), a3: *(_DWORD *)this);
    ++*(_DWORD *)(v15 + 940);
    if ( v141 == 0 )
    {
      v56 = (GFxCachedStroke *)((char *)this + 60);
      GFxVertexArray::SetFormat(this: (GFxCachedStroke *)((char *)this + 60), a2: Vertex_XY16i);
      GFxVertexArray::Resize(this: (GFxCachedStroke *)((char *)this + 60), a2: *(_DWORD *)(v15 + 728));
      v19 = v142 == 0;
      v69 = *((_DWORD **)this + 9);
      v69[1] = 0;
      *v69 = 1;
      v140 = 0.0;
      if ( v19 )
      {
        if ( *(_DWORD *)(v15 + 728) != 0 )
        {
          do
          {
            v71 = *(_DWORD *)(*(_DWORD *)(v15 + 740) + 4 * (LODWORD(v140) >> 8));
            v72 = *((_DWORD *)this + 18);
            v73 = *(float *)(v71 + 12 * LOBYTE(v140) + 4);
            v74 = *((_DWORD *)this + 17) + LODWORD(v140) * *(_DWORD *)(v72 + 4);
            *(_DWORD *)&p.DiscardSharedData = *(_DWORD *)(v72 + 8);
            v115 = v73;
            (*(void (__thiscall **)(_DWORD, int, _DWORD, _DWORD, _DWORD))(**(_DWORD **)&p.DiscardSharedData + 4))(
              a1: *(_DWORD *)&p.DiscardSharedData,
              a2: v74,
              a3: *(float *)(v71 + 12 * LOBYTE(v140)),
              a4: LODWORD(v115),
              a5: 0);
            ++LODWORD(v140);
          }
          while ( LODWORD(v140) < *(_DWORD *)(v15 + 728) );
        }
      }
      else if ( *(_DWORD *)(v15 + 728) != 0 )
      {
        do
        {
          v70 = *(_DWORD *)(*(_DWORD *)(v15 + 740) + 4 * (LODWORD(v140) >> 8));
          p.pData = *(GRenderer::CachedData **)(v70 + 12 * LOBYTE(v140));
          *(float *)&p.DiscardSharedData = *(float *)(v70 + 12 * LOBYTE(v140) + 4);
          GMatrix2D::Transform(
            this: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)&v145,
            result: &v124,
            (float *)&p,
            p_4: (int)v118);
          GFxCachedStroke::BoundCheckPoint(a1: (float *)&v124, a2: SLODWORD(XScale), a3: v131);
          (*(void (__thiscall **)(_DWORD, int, char *, unsigned int, _DWORD))(**(_DWORD **)(*((_DWORD *)this + 18) + 8)
                                                                            + 4))(
            a1: *(_DWORD *)(*((_DWORD *)this + 18) + 8),
            a2: *((_DWORD *)this + 17) + LODWORD(v140) * *(_DWORD *)(*((_DWORD *)this + 18) + 4),
            a3: v124.pString,
            a4: v124.nNextElement,
            a5: 0);
          ++LODWORD(v140);
        }
        while ( LODWORD(v140) < *(_DWORD *)(v15 + 728) );
      }
      goto LABEL_138;
    }
    v135 = 0.0;
    Rotation = 0.0;
    *((_BYTE *)this + 46) = a8;
    v55 = HIWORD(*((_DWORD *)v44 + 2));
    v139 = *((GMatrix2D **)v44 + 2);
    v54 = (char)v139;
    LOBYTE(v139) = v55;
    BYTE2(v139) = v54;
    if ( a8 || *((_DWORD *)v44 + 3) != 0 )
    {
      v56 = (GFxCachedStroke *)((char *)this + 60);
      GFxVertexArray::SetFormat(this: (GFxCachedStroke *)((char *)this + 60), a2: Vertex_XY16iCF32);
      if ( *((_DWORD *)v134 + 3) != 0 )
      {
        v135 = NAN;
        Rotation = 2.3509886e-38;
      }
      else
      {
        v135 = -1.7014118e38;
        Rotation = 0.0;
      }
      v136 = *(float *)&v139;
    }
    else
    {
      v56 = (GFxCachedStroke *)((char *)this + 60);
      GFxVertexArray::SetFormat(this: (GFxCachedStroke *)((char *)this + 60), a2: Vertex_XY16iC32);
      LODWORD(v136) = (unsigned int)v139 & 0xFFFFFF;
    }
    v57 = *((_DWORD **)this + 9);
    *v57 = 1;
    v57[1] = 0;
    v57[2] = -1;
    v57[3] = -1;
    *(_DWORD *)(*((_DWORD *)this + 9) + 16) = *((_DWORD *)v134 + 3) != 0;
    if ( *(_DWORD *)(v15 + 728) <= 0xFFFEu )
    {
      GFxVertexArray::Resize(this: v56, a2: *(_DWORD *)(v15 + 728));
      v140 = 0.0;
      if ( v142 != 0 )
      {
        if ( *(_DWORD *)(v15 + 728) != 0 )
        {
          do
          {
            v58 = *(_DWORD *)(*(_DWORD *)(v15 + 740) + 4 * (LODWORD(v140) >> 8)) + 12 * LOBYTE(v140);
            p.pData = *(GRenderer::CachedData **)v58;
            v59 = *(float *)(v58 + 4);
            v143 = *(float *)&v58;
            *(float *)&p.DiscardSharedData = v59;
            GMatrix2D::Transform(
              this: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)&v145,
              result: &v124,
              (float *)&p,
              p_4: (int)v118);
            GFxCachedStroke::BoundCheckPoint(a1: (float *)&v124, a2: SLODWORD(XScale), a3: v131);
            v60 = *((_DWORD *)v56 + 3);
            v61 = *(float *)(v60 + 8);
            pString = (char *)(*((_DWORD *)v56 + 2) + LODWORD(v140) * *(_DWORD *)(v60 + 4));
            v62 = *(_DWORD *)(LODWORD(v143) + 8);
            v126 = v61;
            v63 = v136;
            if ( v62 == -1 )
            {
              v132 = Rotation;
            }
            else
            {
              v63 = *(float *)&v139;
              v132 = v135;
            }
            (*(void (__thiscall **)(float, char *, char *, unsigned int, float))(*(_DWORD *)LODWORD(v126) + 4))(
              a1: COERCE_FLOAT(LODWORD(v126)),
              a2: pString,
              a3: v124.pString,
              a4: v124.nNextElement,
              a5: COERCE_FLOAT(LODWORD(v63)));
            (*(void (__thiscall **)(float, char *, float))(*(_DWORD *)LODWORD(v126) + 20))(
              a1: COERCE_FLOAT(LODWORD(v126)),
              a2: pString,
              a3: COERCE_FLOAT(LODWORD(v132)));
            ++LODWORD(v140);
          }
          while ( LODWORD(v140) < *(_DWORD *)(v15 + 728) );
          *((_BYTE *)this + 45) = 1;
          goto LABEL_138;
        }
      }
      else if ( *(_DWORD *)(v15 + 728) != 0 )
      {
        do
        {
          v64 = *(_DWORD *)(*(_DWORD *)(v15 + 740) + 4 * (LODWORD(v140) >> 8)) + 12 * LOBYTE(v140);
          v65 = *((_DWORD *)v56 + 3);
          pString = (char *)(*((_DWORD *)v56 + 2) + LODWORD(v140) * *(_DWORD *)(v65 + 4));
          v66 = *(float *)(v65 + 8);
          v67 = v136;
          v126 = v66;
          v68 = *(_DWORD *)(v64 + 8);
          if ( v68 != -1 )
            v67 = *(float *)&v139;
          v132 = v67;
          if ( v68 == -1 )
            v143 = Rotation;
          else
            v143 = v135;
          (*(void (__stdcall **)(char *, _DWORD, _DWORD, float))(*(_DWORD *)LODWORD(v126) + 4))(
            a1: pString,
            a2: *(float *)v64,
            a3: *(float *)(v64 + 4),
            a4: COERCE_FLOAT(LODWORD(v132)));
          (*(void (__thiscall **)(float, char *, float))(*(_DWORD *)LODWORD(v126) + 20))(
            a1: COERCE_FLOAT(LODWORD(v126)),
            a2: pString,
            a3: COERCE_FLOAT(LODWORD(v143)));
          ++LODWORD(v140);
        }
        while ( LODWORD(v140) < *(_DWORD *)(v15 + 728) );
      }
      *((_BYTE *)this + 45) = 1;
    }
LABEL_138:
    if ( *(_DWORD *)v56 != 0 )
    {
      for ( j = 0; j < *(_DWORD *)(v15 + 744); ++j )
      {
        v76 = *(_DWORD *)(*(_DWORD *)(v15 + 756) + 4 * (j >> 8));
        GFxMesh::AddTriangle(
          this: *((GFxMesh **)this + 9),
          a2: *(_WORD *)(v76 + 12 * (unsigned __int8)j),
          a3: *(_WORD *)(v76 + 12 * (unsigned __int8)j + 4),
          a4: *(_WORD *)(v76 + 12 * (unsigned __int8)j + 8));
      }
    }
    v77 = *(_DWORD *)(*(_DWORD *)&v124.nReferenceCount + 76);
    goto LABEL_195;
  }
  if ( v142 != *((_BYTE *)this + 48)
    || (v27 = *((_BYTE *)this + 47)) != 0 && v138 != v27
    || v141 != *((_BYTE *)this + 45)
    || a8 && *((_BYTE *)this + 46) == 0
    || *((float *)this + 10) - 2.0 >= v26
    || *((float *)this + 10) + 2.0 <= v26
    || v142 != 0
    && ((v143 = a6 * 0.000007812500371073838, *((float *)this + 14) - v143 > *(float *)&v131)
     || (v28 = v143, v143 + *((float *)this + 14) < *(float *)&v131)
     || ((v29 = XScale, *((float *)this + 13) - v28 > XScale) || *((float *)this + 13) + v28 < v29)
     && (-*((float *)this + 13) - v28 > v29 || v29 > v28 - *((float *)this + 13))) )
  {
    v30 = *((_DWORD *)this + 20);
    if ( v30 != 0 )
      (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)v30 + 112))(a1: v30, a2: (char *)this + 80, a3: 1);
    *((_DWORD *)this + 20) = 0;
    *((_DWORD *)this + 21) = 0;
    GFxMesh::Clear(this: *((GFxMesh **)this + 9));
    GFxVertexArray::Clear(this: (GFxCachedStroke *)((char *)this + 60));
    goto LABEL_57;
  }
LABEL_198:
  if ( *((_DWORD *)this + 15) != 0 )
  {
    v106 = *(struct GRenderer **)(v133 + 12);
    p.pData = (GRenderer::CachedData *)((char *)this + 80);
    p.DiscardSharedData = false;
    GFxVertexArray::ApplyToRenderer(this: (GFxCachedStroke *)((char *)this + 60), a2: v106, a3: &p);
    GFxFillStyle::GFxFillStyle(this: &v144);
    v107 = *((CMemberFuncProxyBase<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,matrix3x4_t const &),CFuncMemPolicyNone> **)v13
           + 3);
    v143 = 1.0;
    v108 = nullptr;
    v109 = 0;
    if ( v107 != nullptr )
    {
      v108 = v107;
      v143 = 1.0 / a6;
    }
    else
    {
      if ( *((_BYTE *)this + 45) != 0 )
      {
LABEL_204:
        GFxMesh::Display(
          this: *((GFxMesh **)this + 9),
          a2: *(const struct GFxDisplayContext **)&v124.nReferenceCount,
          a3: (const struct GFxFillStyle *)v108,
          a4: v109,
          a5: 0,
          a6: *((_DWORD *)this + 15),
          a7: v143,
          a8: nullptr,
          a9: *((_BYTE *)this + 45));
        GFxFillStyle::~GFxFillStyle(this: &v144);
        return 1;
      }
      v108 = &v144;
      DWORD1(v144.m_pfnProxied) = *((_DWORD *)v13 + 2);
    }
    v109 = 1;
    goto LABEL_204;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1015CE40
// Name: public: void GFxMeshSet::Display(struct GFxDisplayParams __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMeshSet::Display(GFxMeshSet *this, struct GFxDisplayParams *a2, bool a3)
{
  GFxAmpViewStats *v4; // ecx
  void *v5; // ecx
  __int64 v6; // rax
  struct GRenderer *v7; // ebx
  bool v8; // cc
  double v9; // st7
  int v10; // eax
  GFxTexture9Grid *v11; // eax
  bool v12; // zf
  const struct GMatrix2D **v13; // eax
  int v14; // edx
  int v15; // ebx
  const struct GFxFillStyle *v16; // ecx
  int v17; // edx
  GRenderer_vtbl *v18; // edx
  void (__thiscall *SetMatrix)(GRenderer *, const GMatrix2D *); // edx
  int v20; // ebx
  double v21; // st7
  int v22; // ecx
  int v23; // eax
  int v24; // ecx
  void *v25; // ecx
  __int64 v26; // rax
  float v27; // [esp+20h] [ebp-9Ch]
  __int64 v28; // [esp+3Ch] [ebp-80h]
  int v29; // [esp+44h] [ebp-78h]
  struct GRenderer::CacheProvider v30; // [esp+54h] [ebp-68h] BYREF
  bool v31[4]; // [esp+5Ch] [ebp-60h]
  float v32; // [esp+60h] [ebp-5Ch]
  const struct GMatrix2D *v33; // [esp+64h] [ebp-58h]
  bool v34[4]; // [esp+68h] [ebp-54h]
  struct GRenderer *v35; // [esp+6Ch] [ebp-50h]
  float v36; // [esp+70h] [ebp-4Ch]
  unsigned int v37; // [esp+74h] [ebp-48h]
  unsigned int v38; // [esp+78h] [ebp-44h]
  unsigned int v39; // [esp+7Ch] [ebp-40h]
  int v40; // [esp+80h] [ebp-3Ch]
  char v41; // [esp+87h] [ebp-35h]
  struct GMatrix2D v42; // [esp+88h] [ebp-34h] BYREF
  GMatrix2D v43; // [esp+A0h] [ebp-1Ch] BYREF

  v4 = *(GFxAmpViewStats **)(*(_DWORD *)a2 + 144);
  v29 = (int)v4;
  if ( v4 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v4, swdHandle: 1u, swfOffset: 5u);
    GTimer::GetRawTicks(li: v5);
    v28 = v6;
  }
  else
  {
    v28 = 0;
  }
  *((_DWORD *)this + 28) = 0;
  v7 = *(struct GRenderer **)(*(_DWORD *)(*(_DWORD *)a2 + 72) + 12);
  v43.M_[0][0] = *((float *)a2 + 3);
  v43.M_[0][1] = *((float *)a2 + 4);
  v43.M_[0][2] = *((float *)a2 + 5);
  v35 = v7;
  v43.M_[1][0] = *((float *)a2 + 6);
  v43.M_[1][1] = *((float *)a2 + 7);
  v43.M_[1][2] = *((float *)a2 + 8);
  v36 = *((float *)this + 4);
  v42.M_[0][0] = v36;
  v42.M_[0][1] = 0.0;
  v42.M_[0][2] = 0.0;
  v42.M_[1][0] = 0.0;
  v42.M_[1][2] = 0.0;
  v42.M_[1][1] = v36;
  GMatrix2D::Prepend(this: &v43, a2: &v42);
  v7->SetCxform(this: v7, a2: (const GRenderer::Cxform *)((char *)a2 + 36));
  v8 = *((_DWORD *)a2 + 17) <= 2;
  v34[0] = false;
  if ( !v8 || *((float *)a2 + 15) < 0.996999979019165 )
    v34[0] = true;
  v9 = 5.0 / *(float *)(*(_DWORD *)a2 + 116);
  v41 = 1;
  v36 = 0.0;
  v37 = 0;
  v38 = 0;
  v32 = v9;
  if ( *((_DWORD *)this + 21) != 0 )
  {
    v40 = 0;
    do
    {
      v10 = *(_DWORD *)(v40 + *((_DWORD *)this + 20) + 16);
      if ( v10 == -1 )
      {
        if ( v41 != 0 )
        {
          v12 = *((_DWORD *)this + 13) == 0;
          v30.pData = (GRenderer::CachedData *)((char *)this + 72);
          v30.DiscardSharedData = false;
          if ( v12 )
          {
            if ( v7 == *((struct GRenderer **)this + 18) )
              v7->SetVertexData(this: v7, a2: nullptr, a3: 0, a4: Vertex_None, a5: &v30);
          }
          else
          {
            GFxVertexArray::ApplyToRenderer(this: (GFxMeshSet *)((char *)this + 52), a2: v7, a3: &v30);
          }
          v7->SetMatrix(this: v7, a2: &v43);
          v41 = 0;
        }
        v13 = *((const struct GMatrix2D ***)this + 27);
        v33 = nullptr;
        if ( v13 != nullptr )
          v33 = *v13;
        v14 = *((_DWORD *)this + 20);
        v39 = 0;
        if ( *(_DWORD *)(v40 + v14) != 0 )
        {
          v15 = 40 * v37;
          do
          {
            if ( v37 >= *((_DWORD *)this + 8) )
              break;
            v16 = *((_DWORD *)a2 + 18) != 0 ? *((const struct GFxFillStyle **)a2 + 1) : nullptr;
            GFxMesh::Display(
              this: (GFxMesh *)(v15 + *((_DWORD *)this + 7)),
              a2: *(const struct GFxDisplayContext **)a2,
              a3: v16,
              a4: *((_DWORD *)a2 + 18),
              a5: *(_DWORD *)(*((_DWORD *)this + 20) + v40 + 8),
              a6: *(_DWORD *)(*((_DWORD *)this + 20) + v40 + 12),
              a7: *((float *)this + 4),
              a8: v33,
              a9: *((_BYTE *)this + 21));
            v17 = *((_DWORD *)this + 20);
            ++v37;
            v15 += 40;
            ++v39;
          }
          while ( v39 < *(_DWORD *)(v40 + v17) );
          v7 = v35;
        }
        if ( *(_DWORD *)(v40 + *((_DWORD *)this + 20) + 4) == 0 )
          goto LABEL_36;
        v18 = v7->__vftable;
        v42.M_[0][0] = v43.M_[0][0];
        SetMatrix = v18->SetMatrix;
        v42.M_[0][1] = v43.M_[0][1];
        v42.M_[1][0] = v43.M_[1][0];
        v42.M_[1][1] = v43.M_[1][1];
        v42.M_[0][2] = v43.M_[0][2] + v32;
        v42.M_[1][2] = v32 + v43.M_[1][2];
        SetMatrix(this: v7, a2: &v42);
        v12 = *(_DWORD *)(v40 + *((_DWORD *)this + 20) + 4) == 0;
        v39 = 0;
        if ( !v12 )
        {
          v20 = 88 * v38;
          do
          {
            if ( v38 >= *((_DWORD *)this + 11) )
              break;
            v21 = *((float *)this + 2);
            v22 = *((_DWORD *)this + 10);
            v23 = *(_DWORD *)(v22 + v20);
            v31[0] = *((_BYTE *)this + 23);
            v27 = v21;
            if ( GFxCachedStroke::Display(
                   this: (GFxCachedStroke *)(v20 + v22),
                   (const CMaterialDict::MaterialLookup_t *)a2,
                   a3: *(struct GFxDisplayContext **)a2,
                   a4: (const struct GFxLineStyle *)(*((_DWORD *)a2 + 2) + 24 * v23),
                   a5: (const struct GMatrix2D *)((char *)a2 + 12),
                   a6: *((float *)this + 3),
                   a7: v27,
                   a8: v31[0],
                   a9: v34[0],
                   a10: a3) != 0 )
              ++*((_DWORD *)this + 28);
            v24 = *((_DWORD *)this + 20);
            ++v38;
            v20 += 88;
            ++v39;
          }
          while ( v39 < *(_DWORD *)(v40 + v24 + 4) );
          v7 = v35;
        }
      }
      else
      {
        v11 = (GFxTexture9Grid *)(**((_DWORD **)this + 26) + 340 * v10);
        GFxTexture9Grid::Display(
          this: v11,
          a2: *(struct GFxDisplayContext **)a2,
          a3: (GFxFillStyle *)(*((_DWORD *)a2 + 1) + 40 * *((_DWORD *)v11 + 83)),
          a4: &v43);
      }
      v41 = 1;
LABEL_36:
      v40 += 20;
      ++LODWORD(v36);
    }
    while ( LODWORD(v36) < *((_DWORD *)this + 21) );
  }
  v7->SetVertexData(this: v7, a2: nullptr, a3: 0, a4: Vertex_None, a5: nullptr);
  v7->SetIndexData(this: v7, a2: nullptr, a3: 0, a4: Index_None, a5: nullptr);
  if ( v29 != 0 )
  {
    GTimer::GetRawTicks(li: v25);
    GFxAmpViewStats::PopCallstack(this: v29, result: (GImageInfo *)1, swfOffset: 5u, funcTime: v26 - v28);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1015D1A0
// Name: public: void GFxMeshSet::SetImgAdjustMatrices(class GArray<struct GFxScale9GridInfo::ImgAdjust,2,struct GArrayDefaultPolicy> const __near &)
// Source: json
//------------------------------------------------------------------------------
float *__thiscall GFxMeshSet::SetImgAdjustMatrices(const CMaterialDict::MissingMaterial_t ***this, _DWORD *a2)
{
  unsigned int v3; // ebx
  const CMaterialDict::MissingMaterial_t **v4; // eax
  float *result; // eax
  int v6; // edi
  int v7; // edx
  float *v8; // ecx
  int v9; // eax
  int v11; // [esp+10h] [ebp-4h] BYREF

  v3 = 0;
  if ( *(this + 27) == nullptr )
  {
    v11 = 2;
    v4 = (const CMaterialDict::MissingMaterial_t **)GMemory::pGlobalHeap->AllocAutoHeap_2(
                                                      this: GMemory::pGlobalHeap,
                                                      a2: this,
                                                      a3: 12,
                                                      a4: &v11);
    if ( v4 != nullptr )
    {
      *v4 = nullptr;
      v4[1] = nullptr;
      v4[2] = nullptr;
    }
    else
    {
      v4 = nullptr;
    }
    *(this + 27) = v4;
  }
  result = (float *)GArrayData<GMatrix2D,GAllocatorLH<GMatrix2D,2>,GArrayDefaultPolicy>::Resize(
                      this: *(this + 27),
                      a2: a2[1]);
  if ( a2[1] != 0 )
  {
    v6 = 0;
    v7 = 0;
    do
    {
      v8 = (float *)(v7 + *a2 + 16);
      v9 = (int)**(this + 27);
      *(float *)(v9 + v6) = *v8;
      result = (float *)(v6 + v9);
      ++v3;
      result[1] = v8[1];
      v7 += 40;
      v6 += 24;
      result[2] = v8[2];
      result[3] = v8[3];
      result[4] = v8[4];
      result[5] = v8[5];
    }
    while ( v3 < a2[1] );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1015D2D0
// Name: public: void GFxMeshSet::AddTexture9Grid(struct GFxTexture9Grid const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMeshSet::AddTexture9Grid(GFxMeshSet *this, const struct GFxTexture9Grid *a2)
{
  _DWORD *v3; // eax
  void **v4; // edi
  unsigned int v5; // ecx
  unsigned int v6; // esi
  char *v7; // ecx
  GFxTexture9Grid *v8; // ecx
  _DWORD v9[5]; // [esp+8h] [ebp-18h] BYREF
  int v10; // [esp+1Ch] [ebp-4h] BYREF

  if ( *((_DWORD *)this + 26) == 0 )
  {
    v10 = 2;
    v3 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this, a3: 12, a4: &v10);
    if ( v3 != nullptr )
    {
      *v3 = 0;
      v3[1] = 0;
      v3[2] = 0;
    }
    else
    {
      v3 = nullptr;
    }
    *((_DWORD *)this + 26) = v3;
  }
  v4 = *((void ***)this + 26);
  v5 = (unsigned int)v4[1];
  memset(v9, 0, 16);
  v6 = v5 + 1;
  v9[4] = v5;
  if ( v5 + 1 >= v5 )
  {
    if ( v6 >= (unsigned int)v4[2] )
      GArrayDataBase<GFxTexture9Grid,GAllocatorLH<GFxTexture9Grid,2>,GArrayDefaultPolicy>::Reserve(
        this: v4,
        a2: v4,
        a3: v6 + (v6 >> 2));
  }
  else if ( v6 < (unsigned int)v4[2] >> 1 )
  {
    GArrayDataBase<GFxTexture9Grid,GAllocatorLH<GFxTexture9Grid,2>,GArrayDefaultPolicy>::Reserve(
      this: v4,
      a2: v4,
      a3: v5 + 1);
  }
  v7 = (char *)*v4;
  v4[1] = (void *)v6;
  v8 = (GFxTexture9Grid *)&v7[340 * v6 - 340];
  if ( v8 != nullptr )
    GFxTexture9Grid::GFxTexture9Grid(this: v8, a2);
  GArrayData<GFxMeshSet::MeshSubShape,GAllocatorLH<GFxMeshSet::MeshSubShape,2>,GArrayDefaultPolicy>::PushBack(
    this: (int *)this + 20,
    a2: v9);
  *((_BYTE *)this + 21) = *((_BYTE *)this + 20) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1015D530
// Name: public: virtual GFxMeshSet::~GFxMeshSet(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMeshSet::~GFxMeshSet(GFxMeshSet *this)
{
  _DWORD *v2; // edi
  int v3; // ecx
  void **v4; // edi
  void **v5; // edi
  GFxCachedStroke *v6; // edi
  int v7; // ebx

  v2 = (_DWORD *)((char *)this + 72);
  *(_DWORD *)this = &GFxMeshSet::`vftable';
  v3 = *((_DWORD *)this + 18);
  if ( v3 != 0 )
    (*(void (__thiscall **)(int, _DWORD *, int))(*(_DWORD *)v3 + 112))(a1: v3, a2: v2, a3: 1);
  *v2 = 0;
  v2[1] = 0;
  if ( *((_BYTE *)this + 93) > 6u )
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 24));
  v4 = *((void ***)this + 26);
  if ( v4 != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v4);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v4);
  }
  v5 = *((void ***)this + 27);
  if ( v5 != nullptr )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v5);
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v5);
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 20));
  GFxVertexArray::~GFxVertexArray(this: (GFxMeshSet *)((char *)this + 52));
  v6 = (GFxCachedStroke *)(88 * *((_DWORD *)this + 11) + *((_DWORD *)this + 10) - 88);
  if ( *((_DWORD *)this + 11) != 0 )
  {
    v7 = *((_DWORD *)this + 11);
    do
    {
      GFxCachedStroke::~GFxCachedStroke(this: v6);
      v6 = (GFxCachedStroke *)((char *)v6 - 88);
      --v7;
    }
    while ( v7 != 0 );
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 10));
  GConstructorMov<GFxMesh>::DestructArray(a1: *((_DWORD *)this + 7), a2: *((_DWORD *)this + 8));
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 7));
}

//------------------------------------------------------------------------------
// Address: 0x1015D640
// Name: public: GFxMeshSet::GFxMeshSet(float,float,bool,bool)
// Source: json
//------------------------------------------------------------------------------
GFxMeshSet *__thiscall GFxMeshSet::GFxMeshSet(GFxMeshSet *this, float a2, float a3, bool a4, bool a5)
{
  *(_DWORD *)this = &GFxMeshSet::`vftable';
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  GFxVertexArray::GFxVertexArray(this: (GFxMeshSet *)((char *)this + 52), a2: nullptr, a3: Vertex_None, a4: 0);
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 22) = 0;
  *((float *)this + 1) = a2;
  *((_BYTE *)this + 20) = a4;
  *((float *)this + 2) = a3;
  *(_WORD *)((char *)this + 21) = 0;
  *((_BYTE *)this + 23) = 0;
  *((float *)this + 3) = 1.0;
  *((_BYTE *)this + 25) = 0;
  *((float *)this + 4) = 1.0;
  *((_BYTE *)this + 24) = a5;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 24) = 0;
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 27) = 0;
  *((_DWORD *)this + 28) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1015D700
// Name: public: void GFxMeshSet::AddTessellatedShape(class GCompoundShape const __near &,class GFxFillStyle const __near *,unsigned int,class GFxDisplayContext __near *,class GFxRenderConfig const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxMeshSet::AddTessellatedShape(
        GFxMeshSet *this,
        const struct GCompoundShape *a2,
        const struct GFxFillStyle *a3,
        unsigned int idx,
        struct GFxDisplayContext *a5,
        const struct GFxRenderConfig *a6)
{
  GRefCountNTSImpl *v7; // edi
  GFxRenderGen *v8; // eax
  GRefCountNTSImpl *v9; // eax
  bool v11; // cl
  bool v12; // zf
  unsigned int RendererCapBits; // eax
  unsigned int v14; // eax
  const struct GFxFillStyle *v15; // ecx
  unsigned int VertexCount; // eax
  enum GRenderer::VertexFormat v17; // esi
  unsigned int v18; // eax
  const struct GFxFillStyle *v19; // ecx
  unsigned int *v20; // esi
  struct GFxDisplayContext *v21; // edx
  const struct GFxFillStyle *v22; // ecx
  unsigned int v23; // edi
  unsigned int v24; // esi
  float *v25; // edx
  _DWORD *v26; // edi
  unsigned int v27; // esi
  unsigned int v28; // eax
  unsigned int v29; // esi
  int v30; // eax
  unsigned int v31; // edx
  _BYTE *v32; // eax
  unsigned int j; // ecx
  int v34; // ecx
  bool v35; // sf
  struct GFxVertexArray *v36; // eax
  _DWORD *v37; // esi
  unsigned int v38; // edi
  unsigned int v39; // edi
  const struct GCompoundShape *v40; // eax
  int v41; // eax
  void **v42; // edi
  unsigned int v43; // esi
  unsigned int *v44; // eax
  float v45; // [esp+1Ch] [ebp-40h]
  unsigned int v46; // [esp+30h] [ebp-2Ch]
  unsigned int v47; // [esp+34h] [ebp-28h]
  unsigned int v48; // [esp+38h] [ebp-24h]
  GRefCountNTSImpl_vtbl *v49; // [esp+3Ch] [ebp-20h]
  _BYTE *v50; // [esp+44h] [ebp-18h]
  int v51; // [esp+50h] [ebp-Ch] BYREF
  struct GFxVertexArray *v52; // [esp+54h] [ebp-8h] BYREF
  GRefCountNTSImpl *v53; // [esp+58h] [ebp-4h]
  const struct GFxFillStyle *i; // [esp+68h] [ebp+Ch]
  unsigned int v55; // [esp+68h] [ebp+Ch]
  const struct GFxFillStyle *v56; // [esp+68h] [ebp+Ch]
  unsigned int idxa; // [esp+6Ch] [ebp+10h]
  float idxd; // [esp+6Ch] [ebp+10h]
  float idxe; // [esp+6Ch] [ebp+10h]
  unsigned int idxb; // [esp+6Ch] [ebp+10h]
  unsigned int idxc; // [esp+6Ch] [ebp+10h]
  GFxCachedStroke *v62; // [esp+70h] [ebp+14h]
  const struct GFxRenderConfig *v63; // [esp+74h] [ebp+18h]
  int k; // [esp+74h] [ebp+18h]
  bool v65; // [esp+77h] [ebp+1Bh]

  v49 = nullptr;
  v48 = 0;
  v47 = 0;
  v46 = 0;
  if ( a5 != nullptr )
  {
    v7 = *(GRefCountNTSImpl **)(*((_DWORD *)a5 + 26) + 16);
    if ( v7 != nullptr )
      ++v7->RefCount;
    v53 = v7;
  }
  else
  {
    v51 = 2;
    v8 = (GFxRenderGen *)GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 948, a3: &v51);
    if ( v8 != nullptr )
      v9 = (GRefCountNTSImpl *)GFxRenderGen::GFxRenderGen(this: v8, a2: GMemory::pGlobalHeap);
    else
      v9 = nullptr;
    v7 = v9;
    v53 = v9;
  }
  GTessellator::Clear(this: (GTessellator *)&v7[24].RefCount);
  v7[24].RefCount = *((_BYTE *)a2 + 68) == 0;
  LOBYTE(v7[25].__vftable) = 1;
  BYTE1(v7[25].__vftable) = *((_BYTE *)this + 24);
  BYTE2(v7[25].__vftable) = *((_BYTE *)this + 24);
  HIBYTE(v7[25].__vftable) = *((_BYTE *)this + 24);
  GTessellator::Monotonize(this: (GTessellator *)&v7[24].RefCount, a2, addStyle: 1);
  ++v7[117].RefCount;
  if ( v7[57].__vftable > (GRefCountNTSImpl_vtbl *)0xFFFE )
  {
    GRefCountNTSImpl::Release(this: v7);
    return;
  }
  GTessellator::SortMonotonesByStyle(this: (GTessellator *)&v7[24].RefCount);
  v11 = (a6->RendererVtxFmts & 0x10) != 0;
  v12 = (a6->RenderFlags & 0x10) == 0;
  v65 = v11;
  if ( !v12 )
  {
    RendererCapBits = a6->RendererCapBits;
    if ( (RendererCapBits & 0x100) != 0
      && *((_BYTE *)this + 20) == 0
      && (*((_BYTE *)this + 23) == 0 || (RendererCapBits & 0x1000) == 0 || v11) )
    {
      if ( (RendererCapBits & 0x200) == 0 )
      {
        v14 = 0;
        if ( idx != 0 )
        {
          v15 = a3;
          while ( *(_BYTE *)v15 == 0 )
          {
            ++v14;
            v15 = (const struct GFxFillStyle *)((char *)v15 + 40);
            if ( v14 >= idx )
              goto LABEL_22;
          }
          goto LABEL_48;
        }
      }
LABEL_22:
      v52 = (struct GFxVertexArray *)&v7[115];
      GFxVertexArray::Clear(this: (GFxVertexArray *)&v7[115]);
      *(float *)&v51 = *((float *)this + 1) * -0.5;
      GFxEdgeAAGenerator::ProcessAndSortEdges(a1: &v7[97], a2: &v7[24].RefCount, a3, a4: idx, a5: v51, a6: 1, a7: 0);
      v51 = *((int *)this + 13);
      VertexCount = GFxEdgeAAGenerator::GetVertexCount(this: (GFxEdgeAAGenerator *)&v7[97]);
      if ( v51 + VertexCount > 0xFFFE )
      {
        *((_BYTE *)this + 22) = 1;
        goto LABEL_48;
      }
      if ( **((_DWORD **)this + 16) != 0 )
      {
        GFxVertexArray::SetFormat(this: v52, a2: **((enum GRenderer::VertexFormat **)this + 16));
        goto LABEL_34;
      }
      v17 = Vertex_XY16iC32;
      if ( v65 )
      {
        if ( *((_BYTE *)this + 23) != 0 )
        {
LABEL_32:
          v17 = Vertex_XY16iCF32;
          *((_BYTE *)this + 23) = 1;
          goto LABEL_33;
        }
        v18 = 0;
        if ( idx != 0 )
        {
          v19 = a3;
          while ( *(_BYTE *)v19 == 0 )
          {
            ++v18;
            v19 = (const struct GFxFillStyle *)((char *)v19 + 40);
            if ( v18 >= idx )
              goto LABEL_33;
          }
          goto LABEL_32;
        }
      }
LABEL_33:
      GFxVertexArray::SetFormat(this: v52, a2: v17);
LABEL_34:
      if ( LOBYTE(v7[114].__vftable) == 0 || *(_DWORD *)v7[116].RefCount == 3 )
      {
        v20 = (unsigned int *)((char *)this + 28);
        GArrayData<GFxMesh,GAllocatorLH<GFxMesh,131>,GArrayDefaultPolicy>::Resize(
          this: (unsigned int *)this + 7,
          a2: *((_DWORD *)this + 8) + 1);
        idxa = 1;
        GFxEdgeAAGenerator::GenerateSolidMesh(
          this: (GFxEdgeAAGenerator *)&v7[97],
          a2: v52,
          a3: (struct GFxMesh *)(*((_DWORD *)this + 7) + 40 * *((_DWORD *)this + 8) - 40),
          a4: *((float *)this + 3));
      }
      else
      {
        v20 = (unsigned int *)((char *)this + 28);
        idxa = GFxEdgeAAGenerator::GenerateTexturedMeshes(a1: v52, a2: (int)this + 28, a3: *((float *)this + 3));
      }
      v21 = a5;
      if ( a5 != nullptr )
      {
        v22 = nullptr;
        for ( i = nullptr; (unsigned int)v22 < idxa; i = v22 )
        {
          if ( *((_DWORD *)v21 + 19) != 0 )
          {
            v21 = a5;
            *(_DWORD *)(*((_DWORD *)a5 + 19) + 12) += *(_DWORD *)(*v20 + 40 * (*((_DWORD *)this + 8) - (_DWORD)v22) - 16)
                                                    / 3u;
            v22 = i;
          }
          v22 = (const struct GFxFillStyle *)((char *)v22 + 1);
        }
      }
      if ( (unsigned int)(*(_DWORD *)v52 + *((_DWORD *)this + 13)) <= 0xFFFE )
      {
        v48 = *((_DWORD *)this + 13);
        v49 = *(GRefCountNTSImpl_vtbl **)v52;
        v46 = idxa;
        if ( **((_DWORD **)this + 16) == 0 )
          GFxVertexArray::SetFormat(
            this: (GFxMeshSet *)((char *)this + 52),
            a2: *(enum GRenderer::VertexFormat *)v7[116].RefCount);
        GFxVertexArray::AppendVertices(this: (GFxMeshSet *)((char *)this + 52), a2: v52);
        *((_BYTE *)this + 21) = 1;
      }
      else
      {
        GArrayData<GFxMesh,GAllocatorLH<GFxMesh,131>,GArrayDefaultPolicy>::Resize(
          this: v20,
          a2: *((_DWORD *)this + 8) - idxa);
      }
    }
  }
LABEL_48:
  if ( *((_BYTE *)this + 21) == 0 )
  {
    v23 = *((_DWORD *)this + 13);
    v48 = v23;
    v49 = v53[57].__vftable;
    if ( **((_DWORD **)this + 16) == 0 )
      GFxVertexArray::SetFormat(this: (GFxMeshSet *)((char *)this + 52), a2: Vertex_XY16i);
    GFxVertexArray::Resize(this: (GFxMeshSet *)((char *)this + 52), a2: (unsigned int)v49 + v23);
    if ( *((GRefCountNTSImpl_vtbl **)this + 13) != (GRefCountNTSImpl_vtbl *)((char *)v49 + v23) )
      goto LABEL_106;
    v24 = 0;
    if ( v49 != nullptr )
    {
      while ( 1 )
      {
        v25 = (float *)(*(_DWORD *)(v53[58].RefCount + 4 * (v24 >> 10)) + 8 * (v24 & 0x3FF));
        idxd = v25[1] * *((float *)this + 3);
        v45 = idxd;
        idxe = *((float *)this + 3) * *v25;
        (*(void (__thiscall **)(_DWORD, unsigned int, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(*((_DWORD *)this + 16) + 8)
                                                                             + 4))(
          a1: *(_DWORD *)(*((_DWORD *)this + 16) + 8),
          a2: *((_DWORD *)this + 15) + *(_DWORD *)(*((_DWORD *)this + 16) + 4) * (v23 + v24++),
          a3: LODWORD(idxe),
          a4: LODWORD(v45),
          a5: 0);
        if ( v24 >= (unsigned int)v49 )
          break;
        v23 = v48;
      }
    }
    idxb = 0;
    if ( v53[67].__vftable != nullptr )
    {
      v26 = (_DWORD *)((char *)this + 28);
      do
      {
        v27 = *(_DWORD *)(*(_DWORD *)(v53[68].RefCount + 4 * (idxb >> 6)) + 24 * (idxb & 0x3F) + 16) - 1;
        v63 = (const struct GFxRenderConfig *)v27;
        GTessellator::TriangulateMonotone(this: (GTessellator *)&v53[24].RefCount, idx: idxb);
        if ( idxb == 0 || *(_DWORD *)(*((_DWORD *)this + 7) + 40 * *((_DWORD *)this + 8) - 36) != v27 )
        {
          v28 = *((_DWORD *)this + 8);
          v29 = v28 + 1;
          v55 = v28;
          if ( v28 + 1 >= v28 )
          {
            if ( v29 >= *((_DWORD *)this + 9) )
              GArrayDataBase<GFxMesh,GAllocatorLH<GFxMesh,131>,GArrayDefaultPolicy>::Reserve(
                this: (void **)this + 7,
                a2: (char *)this + 28,
                a3: v29 + (v29 >> 2));
          }
          else
          {
            GConstructorMov<GFxMesh>::DestructArray(a1: *v26 + 40 * (v28 + 1), a2: -1);
            if ( v29 < *((_DWORD *)this + 9) >> 1 )
              GArrayDataBase<GFxMesh,GAllocatorLH<GFxMesh,131>,GArrayDefaultPolicy>::Reserve(
                this: (void **)this + 7,
                a2: (char *)this + 28,
                a3: v29);
          }
          *((_DWORD *)this + 8) = v29;
          if ( v29 > v55 )
            GConstructorMov<GFxMesh>::ConstructArray(a1: *v26 + 40 * v55, a2: v29 - v55);
          ++v46;
          v27 = (unsigned int)v63;
        }
        GFxMesh::AddTriangles(
          this: (GFxMesh *)(*v26 + 40 * *((_DWORD *)this + 8) - 40),
          a2: v27,
          a3: (const struct GTessellator *)&v53[24].RefCount);
        if ( a5 != nullptr )
        {
          v30 = *((_DWORD *)a5 + 19);
          if ( v30 != 0 )
            *(_DWORD *)(v30 + 12) += v53[73].__vftable;
        }
        ++idxb;
      }
      while ( (GRefCountNTSImpl_vtbl *)idxb < v53[67].__vftable );
    }
  }
  v31 = *((_DWORD *)a2 + 6);
  v32 = nullptr;
  v50 = nullptr;
  if ( v31 + (v31 >> 2) != 0 )
  {
    v52 = (struct GFxVertexArray *)2;
    v32 = GMemory::pGlobalHeap->Alloc_2(this: GMemory::pGlobalHeap, a2: 4 * ((v31 + (v31 >> 2) + 3) >> 2), a3: &v52);
    v50 = v32;
  }
  for ( j = 0; j < *((_DWORD *)a2 + 6); ++j )
    v32[j] = 0;
  idxc = 0;
  if ( *((_DWORD *)a2 + 6) != 0 )
  {
    do
    {
      v56 = (const struct GFxFillStyle *)(idxc + 1);
      if ( v50[idxc] == 0 )
      {
        v34 = *(_DWORD *)(*((_DWORD *)a2 + 9) + 4 * (idxc >> 6));
        v35 = *(int *)(v34 + 24 * (idxc & 0x3F) + 20) < 0;
        v51 = v34 + 24 * (idxc & 0x3F);
        if ( !v35 && *(_DWORD *)(v34 + 24 * (idxc & 0x3F) + 4) > 1u )
        {
          v36 = *((struct GFxVertexArray **)this + 11);
          v37 = (_DWORD *)((char *)this + 40);
          v38 = (unsigned int)v36 + 1;
          v52 = v36;
          if ( (struct GFxVertexArray *)((char *)v36 + 1) >= v36 )
          {
            if ( v38 >= *((_DWORD *)this + 12) )
              GArrayDataBase<GFxCachedStroke,GAllocatorLH<GFxCachedStroke,132>,GArrayDefaultPolicy>::Reserve(
                this: (void **)this + 10,
                a2: (char *)this + 40,
                a3: v38 + (v38 >> 2));
          }
          else
          {
            v62 = (GFxCachedStroke *)(88 * (_DWORD)v36 + *v37 - 88);
            for ( k = -1; k != 0; --k )
            {
              GFxCachedStroke::~GFxCachedStroke(this: v62);
              v62 = (GFxCachedStroke *)((char *)v62 - 88);
            }
            if ( v38 < *((_DWORD *)this + 12) >> 1 )
              GArrayDataBase<GFxCachedStroke,GAllocatorLH<GFxCachedStroke,132>,GArrayDefaultPolicy>::Reserve(
                this: (void **)this + 10,
                a2: (char *)this + 40,
                a3: v38);
          }
          *((_DWORD *)this + 11) = v38;
          if ( v38 > (unsigned int)v52 )
            GConstructorMov<GFxCachedStroke>::ConstructArray(a1: *v37 + 88 * (_DWORD)v52, a2: v38 - (_DWORD)v52);
          ++v47;
          *(_BYTE *)(88 * *((_DWORD *)this + 11) + *v37 - 44) = *((_BYTE *)this + 20);
          GFxCachedStroke::AddShapePathVertices(
            this: (GFxCachedStroke *)(88 * *((_DWORD *)this + 11) + *v37 - 88),
            a2,
            a3: idxc,
            a4: *((float *)this + 3));
          v39 = idxc + 1;
          v40 = a2;
          if ( (unsigned int)v56 < *((_DWORD *)a2 + 6) )
          {
            do
            {
              v41 = *(_DWORD *)(*((_DWORD *)v40 + 9) + 4 * (v39 >> 6)) + 24 * (v39 & 0x3F);
              if ( *(_DWORD *)(v41 + 20) == *(_DWORD *)(v51 + 20) )
              {
                v50[v39] = 1;
                if ( *(int *)(v41 + 20) >= 0 && *(_DWORD *)(v41 + 4) > 1u )
                  GFxCachedStroke::AddShapePathVertices(
                    this: (GFxCachedStroke *)(88 * *((_DWORD *)this + 11) + *v37 - 88),
                    a2,
                    a3: v39,
                    a4: *((float *)this + 3));
              }
              v40 = a2;
              ++v39;
            }
            while ( v39 < *((_DWORD *)a2 + 6) );
          }
        }
      }
      ++idxc;
    }
    while ( (unsigned int)v56 < *((_DWORD *)a2 + 6) );
  }
  v42 = (void **)((char *)this + 80);
  v43 = *((_DWORD *)this + 21) + 1;
  if ( v43 >= *((_DWORD *)this + 21) )
  {
    if ( v43 >= *((_DWORD *)this + 22) )
      GArrayDataBase<GFxMeshSet::MeshSubShape,GAllocatorLH<GFxMeshSet::MeshSubShape,2>,GArrayDefaultPolicy>::Reserve(
        this: v42,
        a2: v42,
        a3: v43 + (v43 >> 2));
  }
  else if ( v43 < *((_DWORD *)this + 22) >> 1 )
  {
    GArrayDataBase<GFxMeshSet::MeshSubShape,GAllocatorLH<GFxMeshSet::MeshSubShape,2>,GArrayDefaultPolicy>::Reserve(
      this: v42,
      a2: v42,
      a3: *((_DWORD *)this + 21) + 1);
  }
  v44 = (unsigned int *)((char *)*v42 + 20 * v43 - 20);
  *((_DWORD *)this + 21) = v43;
  if ( v44 != nullptr )
  {
    *v44 = v46;
    v44[1] = v47;
    v44[2] = v48;
    v44[3] = (unsigned int)v49;
    v44[4] = -1;
  }
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: v50);
LABEL_106:
  GRefCountNTSImpl::Release(this: v53);
}
