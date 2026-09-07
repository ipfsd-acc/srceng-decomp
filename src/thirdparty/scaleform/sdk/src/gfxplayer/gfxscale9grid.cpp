// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxscale9grid.cpp
// Functions: 9
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxscale9grid.h"

//------------------------------------------------------------------------------
// Address: 0x10104980
// Name: public: void GFxScale9GridInfo::Transform(float __near *,float __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxScale9GridInfo::Transform(GFxScale9GridInfo *this, float *x, float *y)
{
  double v4; // st6
  double v5; // st7
  float *v6; // eax
  double v7; // st7
  double v8; // st7
  float xa; // [esp+10h] [ebp+8h]
  float xb; // [esp+10h] [ebp+8h]

  v4 = *y;
  v5 = *x;
  *x = *((float *)this + 12) * v5 + *((float *)this + 13) * v4 + *((float *)this + 14);
  xa = v5 * *((float *)this + 15) + v4 * *((float *)this + 16) + *((float *)this + 17);
  *y = xa;
  v6 = (float *)(this
               + 6
               * (unsigned __int8)codeToMtx[(*((float *)this + 26) < (double)*x)
                                          | (2
                                           * ((*((float *)this + 27) < (double)xa)
                                            | (2
                                             * ((*((float *)this + 24) > (double)*x)
                                              | (2 * (*((float *)this + 25) > (double)xa))))))]
               + 34);
  v7 = *x;
  *x = *v6 * v7 + v6[1] * xa + v6[2];
  xb = v7 * v6[3] + xa * v6[4] + v6[5];
  *y = xb;
  v8 = *x;
  *x = *((float *)this + 28) * v8 + *((float *)this + 29) * xb + *((float *)this + 30);
  *y = v8 * *((float *)this + 31) + xb * *((float *)this + 32) + *((float *)this + 33);
}

//------------------------------------------------------------------------------
// Address: 0x10104AC0
// Name: public: void GFxScale9GridInfo::Compute(void)
// Source: json
//------------------------------------------------------------------------------
CMaterialDict::MissingMaterial_t *__usercall GFxScale9GridInfo::Compute@<eax>(
        CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),Vector,CFuncMemPolicyNone> *this@<ecx>,
        const CMaterialDict::MaterialLookup_t *a2@<edi>)
{
  bool v3; // al
  CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),Vector,CFuncMemPolicyNone> *v4; // ebx
  double v5; // st7
  double v6; // st6
  double v7; // st4
  double v8; // st3
  double v9; // st6
  double v10; // st3
  double v11; // st2
  double v12; // st4
  double v13; // st7
  double v14; // rt2
  double v15; // st6
  double v16; // rt0
  double v17; // st5
  double v18; // st6
  double v19; // st7
  double v20; // st7
  double v21; // st4
  double v22; // st5
  double v23; // st2
  double v24; // st1
  double v25; // st7
  double v26; // st2
  double v27; // st1
  double v28; // st3
  double v29; // st5
  double v30; // st6
  CMaterialDict::MissingMaterial_t *result; // eax
  const CMaterialDict::MaterialLookup_t *v32; // [esp+Ch] [ebp-100h]
  double v33; // [esp+18h] [ebp-F4h]
  double v34; // [esp+20h] [ebp-ECh]
  double v35; // [esp+28h] [ebp-E4h]
  double v36; // [esp+30h] [ebp-DCh]
  double v37; // [esp+30h] [ebp-DCh]
  float ox2; // [esp+38h] [ebp-D4h]
  double v39; // [esp+3Ch] [ebp-D0h]
  float oy1; // [esp+44h] [ebp-C8h]
  float ox1; // [esp+48h] [ebp-C4h]
  float ox8; // [esp+4Ch] [ebp-C0h]
  double v43; // [esp+50h] [ebp-BCh]
  float tx4; // [esp+58h] [ebp-B4h]
  float oy2; // [esp+5Ch] [ebp-B0h]
  float ty4; // [esp+60h] [ebp-ACh]
  double v47; // [esp+64h] [ebp-A8h]
  double v48; // [esp+6Ch] [ebp-A0h]
  float w; // [esp+70h] [ebp-9Ch]
  float ox3; // [esp+74h] [ebp-98h]
  float oy3; // [esp+78h] [ebp-94h]
  float tx2; // [esp+7Ch] [ebp-90h]
  float ty2; // [esp+80h] [ebp-8Ch]
  float tx3; // [esp+84h] [ebp-88h]
  float ty3; // [esp+88h] [ebp-84h]
  double v56; // [esp+8Ch] [ebp-80h]
  float ix2; // [esp+90h] [ebp-7Ch]
  float ix2b; // [esp+90h] [ebp-7Ch]
  float ix2a; // [esp+90h] [ebp-7Ch]
  float ix2c; // [esp+90h] [ebp-7Ch]
  float tx1; // [esp+94h] [ebp-78h]
  float tx1a; // [esp+94h] [ebp-78h]
  float ox7; // [esp+98h] [ebp-74h]
  float ox7a; // [esp+98h] [ebp-74h]
  float ox7b; // [esp+98h] [ebp-74h]
  float ox4; // [esp+9Ch] [ebp-70h]
  float ox4a; // [esp+9Ch] [ebp-70h]
  float bx1; // [esp+A0h] [ebp-6Ch]
  float bx2; // [esp+A4h] [ebp-68h]
  float by1; // [esp+A8h] [ebp-64h]
  float by2; // [esp+ACh] [ebp-60h]
  float ix4; // [esp+B0h] [ebp-5Ch]
  float ix4a; // [esp+B0h] [ebp-5Ch]
  float iy4; // [esp+B4h] [ebp-58h]
  float iy4a; // [esp+B4h] [ebp-58h]
  float h; // [esp+BCh] [ebp-50h]
  float ha; // [esp+BCh] [ebp-50h]
  float hb; // [esp+BCh] [ebp-50h]
  float hc; // [esp+BCh] [ebp-50h]
  float hd; // [esp+BCh] [ebp-50h]
  float he; // [esp+BCh] [ebp-50h]
  float hf; // [esp+BCh] [ebp-50h]
  float gy2; // [esp+C0h] [ebp-4Ch]
  float gx1; // [esp+C4h] [ebp-48h]
  float gy1a; // [esp+C8h] [ebp-44h]
  float gx2; // [esp+CCh] [ebp-40h]
  float ix1; // [esp+D0h] [ebp-3Ch]
  float ix1a; // [esp+D0h] [ebp-3Ch]
  float ky2; // [esp+D4h] [ebp-38h]
  float ky2a; // [esp+D4h] [ebp-38h]
  struct GMatrix2D v91; // [esp+D8h] [ebp-34h] BYREF
  float v92; // [esp+F0h] [ebp-1Ch] BYREF
  float v93; // [esp+F4h] [ebp-18h]
  float v94; // [esp+F8h] [ebp-14h]
  float v95; // [esp+FCh] [ebp-10h]
  float v96; // [esp+100h] [ebp-Ch]
  float v97; // [esp+104h] [ebp-8h]

  v3 = 1.0 == *((float *)this + 12)
    && 0.0 == *((float *)this + 13)
    && *((float *)this + 15) == 0.0
    && *((float *)this + 16) == 1.0;
  *((_BYTE *)this + 92) = v3;
  GMatrix2D::SetIdentity(this: (float *)&v91);
  v4 = this + 1;
  GMatrix2D::SetInverse(a1: (float *)&v91, m: (const CMaterialDict::MaterialLookup_t *)this + 3, a3: a2);
  *(struct GMatrix2D *)((char *)this + 112) = v91;
  GMatrix2D::SetIdentity(this: (float *)&v91);
  GMatrix2D::SetInverse(a1: (float *)&v91, m: (const CMaterialDict::MaterialLookup_t *)this + 6, a3: v32);
  GMatrix2D::Append(this: (GMatrix2D *)((char *)this + 112), a2: &v91);
  gx1 = *((float *)&this->m_pfnProxied + 2);
  gy1a = *((float *)&this->m_pfnProxied + 3);
  gx2 = *(float *)&this->m_pObject + gx1;
  gy2 = *((float *)&this->m_pObject + 1) + gy1a;
  bx1 = *((float *)this + 19);
  by1 = *((float *)this + 20);
  bx2 = *((float *)this + 21);
  by2 = *((float *)this + 22);
  v5 = bx1;
  v6 = gx1;
  if ( gx1 <= (double)bx1 )
  {
    bx1 = v6 - 0.1000000014901161;
    v5 = bx1;
  }
  v7 = by1;
  v8 = gy1a;
  if ( gy1a <= (double)by1 )
  {
    by1 = v8 - 0.1000000014901161;
    v7 = by1;
  }
  if ( gx2 >= (double)bx2 )
    bx2 = v6 + 0.1000000014901161;
  v9 = bx2;
  if ( gy2 >= (double)by2 )
    by2 = v8 + 0.1000000014901161;
  v10 = *((float *)this + 7) * v7;
  v11 = *(float *)&v4->m_pfnProxied * v5;
  tx1 = v11 + v10 + *((float *)this + 8);
  v12 = v7 * *((float *)this + 10);
  v13 = v5 * *((float *)this + 9);
  ox4 = v13 + v12 + *((float *)this + 11);
  v14 = *(float *)&v4->m_pfnProxied * v9;
  tx2 = v10 + *((float *)this + 6) * v9 + *((float *)this + 8);
  v15 = v9 * *((float *)this + 9);
  ty2 = v12 + v15 + *((float *)this + 11);
  v16 = *((float *)this + 7) * by2;
  tx3 = v14 + v16 + *((float *)this + 8);
  v17 = by2 * *((float *)this + 10);
  ty3 = v15 + v17 + *((float *)this + 11);
  tx4 = v16 + v11 + *((float *)this + 8);
  ty4 = v13 + v17 + *((float *)this + 11);
  ox7 = tx2 - tx1;
  h = ty2 - ox4;
  ha = h * h + ox7 * ox7;
  hb = sqrt(ha);
  w = hb;
  ox7a = tx3 - tx2;
  hc = ty3 - ty2;
  hd = hc * hc + ox7a * ox7a;
  he = sqrt(hd);
  ix4 = (gx1 - bx1) / w;
  ix1 = (gy1a - by1) / he;
  iy4 = (bx2 - gx2) / w;
  ky2 = (by2 - gy2) / he;
  v18 = ix4;
  ix2 = iy4 + ix4;
  if ( ix2 <= 1.0 )
  {
    v19 = 0.05000000074505806;
  }
  else
  {
    ix2b = ix2 + 0.05000000074505806;
    ix4 = v18 / ix2b;
    v19 = 0.05000000074505806;
    iy4 = iy4 / ix2b;
    v18 = ix4;
  }
  ix2a = ky2 + ix1;
  if ( ix2a <= 1.0 )
  {
    v20 = v18;
  }
  else
  {
    ix2c = v19 + ix2a;
    ix1 = ix1 / ix2c;
    v20 = v18;
    ky2 = ky2 / ix2c;
  }
  v21 = tx1;
  v22 = tx2 - tx1;
  v39 = v20 * v22;
  ox1 = v39 + tx1;
  v23 = ty2 - ox4;
  v24 = v20;
  v25 = ox4;
  v43 = v24 * v23;
  oy1 = v43 + ox4;
  v56 = v22 * iy4;
  ox2 = tx2 - v56;
  v36 = iy4 * v23;
  oy2 = ty2 - v36;
  v26 = tx3 - tx2;
  ox3 = tx2 + ix1 * v26;
  v27 = ty3 - ty2;
  oy3 = ty2 + ix1 * v27;
  ox4a = tx3 - v26 * ky2;
  tx1a = ty3 - v27 * ky2;
  v48 = tx4 - v21;
  ox7b = tx4 - v48 * ky2;
  v47 = ty4 - v25;
  hf = ty4 - v47 * ky2;
  ox8 = ix1 * v48 + v21;
  *((float *)&v48 + 1) = ix1 * v47 + v25;
  ix1a = ox8 + v39;
  ky2a = *((float *)&v48 + 1) + v43;
  *((float *)&v56 + 1) = ox3 - v56;
  *((float *)&v43 + 1) = oy3 - v36;
  v28 = tx3 - tx4;
  v33 = iy4 * v28;
  *((float *)&v39 + 1) = ox4a - v33;
  v29 = ty3 - ty4;
  v34 = iy4 * v29;
  *((float *)&v47 + 1) = tx1a - v34;
  v30 = ix4;
  v37 = v28 * ix4;
  ix4a = v37 + ox7b;
  v35 = v29 * v30;
  iy4a = v35 + hf;
  v92 = v21;
  v93 = v25;
  v94 = ox1;
  v95 = oy1;
  v96 = ix1a;
  v97 = ky2a;
  GMatrix2D::SetRectToParl(this: (GMatrix2D *)((char *)this + 136), a2: bx1, a3: by1, a4: gx1, a5: gy1a, a6: &v92);
  v92 = ox1;
  v93 = oy1;
  v94 = ox2;
  v95 = oy2;
  v96 = *((float *)&v56 + 1);
  v97 = *((float *)&v43 + 1);
  GMatrix2D::SetRectToParl(this: (GMatrix2D *)((char *)this + 160), a2: gx1, a3: by1, a4: gx2, a5: gy1a, a6: &v92);
  v92 = ox2;
  v93 = oy2;
  v94 = tx2;
  v95 = ty2;
  v96 = ox3;
  v97 = oy3;
  GMatrix2D::SetRectToParl(this: (GMatrix2D *)((char *)this + 184), a2: gx2, a3: by1, a4: bx2, a5: gy1a, a6: &v92);
  v92 = ox8;
  v93 = *((float *)&v48 + 1);
  v94 = ix1a;
  v95 = ky2a;
  v96 = ix4a;
  v97 = iy4a;
  GMatrix2D::SetRectToParl(this: (GMatrix2D *)((char *)this + 208), a2: bx1, a3: gy1a, a4: gx1, a5: gy2, a6: &v92);
  v92 = ix1a;
  v93 = ky2a;
  v94 = *((float *)&v56 + 1);
  v95 = *((float *)&v43 + 1);
  v96 = *((float *)&v39 + 1);
  v97 = *((float *)&v47 + 1);
  GMatrix2D::SetRectToParl(this: (GMatrix2D *)((char *)this + 232), a2: gx1, a3: gy1a, a4: gx2, a5: gy2, a6: &v92);
  v92 = *((float *)&v56 + 1);
  v93 = *((float *)&v43 + 1);
  v94 = ox3;
  v95 = oy3;
  v96 = ox4a;
  v97 = tx1a;
  GMatrix2D::SetRectToParl(this: (GMatrix2D *)((char *)this + 256), a2: gx2, a3: gy1a, a4: bx2, a5: gy2, a6: &v92);
  v92 = ox7b;
  v93 = hf;
  v94 = ix4a;
  v95 = iy4a;
  v96 = tx4 + v37;
  v97 = ty4 + v35;
  GMatrix2D::SetRectToParl(this: (GMatrix2D *)((char *)this + 280), a2: bx1, a3: gy2, a4: gx1, a5: by2, a6: &v92);
  v92 = ix4a;
  v93 = iy4a;
  v94 = *((float *)&v39 + 1);
  v95 = *((float *)&v47 + 1);
  v96 = tx3 - v33;
  v97 = ty3 - v34;
  GMatrix2D::SetRectToParl(this: (GMatrix2D *)((char *)this + 304), a2: gx1, a3: gy2, a4: gx2, a5: by2, a6: &v92);
  v92 = *((float *)&v39 + 1);
  v93 = *((float *)&v47 + 1);
  v94 = ox4a;
  v95 = tx1a;
  v96 = tx3;
  v97 = ty3;
  result = GMatrix2D::SetRectToParl(
             this: (GMatrix2D *)((char *)this + 328),
             a2: gx2,
             a3: gy2,
             a4: bx2,
             a5: by2,
             a6: &v92);
  *((float *)this + 24) = gx1;
  *((float *)this + 25) = gy1a;
  *((float *)this + 26) = gx2;
  *((float *)this + 27) = gy2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10105340
// Name: public: void GFxScale9GridInfo::ComputeImgAdjustMatrices(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxScale9GridInfo::ComputeImgAdjustMatrices(
        CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),Vector,CFuncMemPolicyNone> *this)
{
  unsigned int v2; // ebx
  int v3; // esi
  GFxScale9GridInfo *v4; // ecx
  int v5; // [esp+20h] [ebp-20h]
  float x; // [esp+24h] [ebp-1Ch] BYREF
  float v7; // [esp+28h] [ebp-18h] BYREF
  float v8; // [esp+2Ch] [ebp-14h] BYREF
  float v9; // [esp+30h] [ebp-10h] BYREF
  float v10; // [esp+34h] [ebp-Ch] BYREF
  float v11; // [esp+38h] [ebp-8h] BYREF

  v2 = 0;
  if ( *((_DWORD *)this + 89) != 0 )
  {
    v5 = 0;
    do
    {
      v3 = v5 + *((_DWORD *)this + 88);
      if ( *(float *)(v3 + 8) > (double)*(float *)v3 && *(float *)(v3 + 12) > (double)*(float *)(v3 + 4) )
      {
        x = *(float *)v3;
        v7 = *(float *)(v3 + 4);
        v8 = *(float *)(v3 + 8);
        v9 = *(float *)(v3 + 4);
        v10 = *(float *)(v3 + 8);
        v11 = *(float *)(v3 + 12);
        GFxScale9GridInfo::Transform((GFxScale9GridInfo *)this, &x, y: &v7);
        GFxScale9GridInfo::Transform(this: v4, x: &v8, y: &v9);
        GFxScale9GridInfo::Transform((GFxScale9GridInfo *)this, x: &v10, y: &v11);
        GMatrix2D::SetRectToParl(
          this: (GMatrix2D *)(v3 + 16),
          a2: *(float *)v3,
          a3: *(float *)(v3 + 4),
          a4: *(float *)(v3 + 8),
          a5: *(float *)(v3 + 12),
          a6: &x);
      }
      v5 += 40;
      ++v2;
    }
    while ( v2 < *((_DWORD *)this + 89) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10105440
// Name: public: void GFxTexture9Grid::Display(class GFxDisplayContext __near &,class GFxFillStyle const __near &,class GMatrix2D const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxTexture9Grid::Display(
        GFxTexture9Grid *this,
        struct GFxDisplayContext *a2,
        GFxFillStyle *a3,
        const struct GMatrix2D *a4)
{
  GFxAmpViewStats *v4; // ebx
  int v5; // eax
  void *v7; // ecx
  int v8; // edx
  struct GImageInfoBase *ImageInfo; // eax
  struct GImageInfoBase *v10; // esi
  int v11; // ebx
  unsigned int (__thiscall *GetHeight)(GImageInfoBase *); // eax
  unsigned int (__thiscall *GetWidth)(GImageInfoBase *); // eax
  unsigned int (__thiscall *v14)(GImageInfoBase *); // eax
  unsigned int v15; // eax
  unsigned int v16; // ecx
  double v17; // st7
  float *v18; // eax
  double v19; // st6
  double v20; // st5
  double v21; // st4
  double v22; // st3
  __int64 v23; // rax
  __int64 v24; // [esp+Ch] [ebp-40h]
  GFxAmpViewStats *v25; // [esp+14h] [ebp-38h]
  int v26; // [esp+24h] [ebp-28h] BYREF
  int v27; // [esp+28h] [ebp-24h]
  int v28; // [esp+2Ch] [ebp-20h]
  int v29; // [esp+30h] [ebp-1Ch]
  double v30; // [esp+34h] [ebp-18h]
  float v31; // [esp+3Ch] [ebp-10h]
  double v32; // [esp+40h] [ebp-Ch]
  float v33; // [esp+48h] [ebp-4h]
  float v34; // [esp+58h] [ebp+Ch]
  float v35; // [esp+58h] [ebp+Ch]
  float v36; // [esp+58h] [ebp+Ch]

  v4 = *((GFxAmpViewStats **)a2 + 36);
  v5 = 0;
  v25 = v4;
  if ( v4 != nullptr )
  {
    GFxAmpViewStats::PushCallstack(this: v4, swdHandle: 1u, swfOffset: 6u);
    GTimer::GetRawTicks(li: v7);
    HIDWORD(v24) = v8;
  }
  else
  {
    HIDWORD(v24) = 0;
  }
  LODWORD(v24) = v5;
  if ( *((_DWORD *)this + 82) != 0 )
  {
    ImageInfo = GFxFillStyle::GetImageInfo(this: a3, a2);
    v10 = ImageInfo;
    if ( ImageInfo != nullptr )
    {
      v11 = (int)ImageInfo->GetTexture(this: ImageInfo, a2: *(GRenderer **)(*((_DWORD *)a2 + 18) + 12));
      v10->GetRect(this: v10, result: (GRect<int> *)&v26);
      if ( (v28 - v26) * (v29 - v27) != 0 && *((_DWORD *)this + 84) != v11 )
      {
        v34 = (float)(v28 - v26);
        v31 = COERCE_FLOAT(v10->GetWidth(this: v10));
        GetHeight = v10->GetHeight;
        v33 = v34 / (double)LODWORD(v31);
        v35 = (float)(v29 - v27);
        v31 = COERCE_FLOAT(GetHeight(this: v10));
        GetWidth = v10->GetWidth;
        v36 = v35 / (double)LODWORD(v31);
        v32 = (double)v26;
        v31 = COERCE_FLOAT(GetWidth(this: v10));
        v14 = v10->GetHeight;
        *((float *)&v32 + 1) = v32 / (double)LODWORD(v31);
        v30 = (double)v27;
        v15 = v14(this: v10);
        v16 = 0;
        v31 = v30 / (double)v15;
        if ( *((_DWORD *)this + 82) != 0 )
        {
          v17 = v33;
          v18 = (float *)((char *)this + 24);
          v19 = v36;
          v20 = *((float *)&v32 + 1);
          v21 = v31;
          do
          {
            ++v16;
            v22 = *(v18 - 1) * v17;
            v18 += 9;
            *(v18 - 10) = v22 + v20;
            *(v18 - 9) = *(v18 - 9) * v19 + v21;
            *(v18 - 8) = *(v18 - 8) * v17 + v20;
            *(v18 - 7) = *(v18 - 7) * v19 + v21;
          }
          while ( v16 < *((_DWORD *)this + 82) );
        }
        *((_DWORD *)this + 84) = v11;
      }
      (*(void (__thiscall **)(_DWORD, char *, _DWORD, _DWORD, _DWORD, int, const struct GMatrix2D *, _DWORD))(**(_DWORD **)(*((_DWORD *)a2 + 18) + 12) + 148))(
        a1: *(_DWORD *)(*((_DWORD *)a2 + 18) + 12),
        a2: (char *)this + 4,
        a3: *((_DWORD *)this + 82),
        a4: 0,
        a5: *((_DWORD *)this + 82),
        a6: v11,
        a7: a4,
        a8: 0);
      v4 = v25;
    }
  }
  if ( v4 != nullptr )
  {
    GTimer::GetRawTicks(li: this);
    GFxAmpViewStats::PopCallstack(this: (int)v4, result: (GImageInfo *)1, swfOffset: 6u, funcTime: v23 - v24);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10105630
// Name: public: static void GConstructorMov<struct GFxScale9GridInfo::ImgAdjust>::ConstructArray(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GConstructorMov<GFxScale9GridInfo::ImgAdjust>::ConstructArray(char *p, unsigned int count)
{
  unsigned int v2; // edi
  double v3; // st7
  double v4; // st6
  float *v5; // esi

  v2 = count;
  if ( count != 0 )
  {
    v3 = 1.0e30;
    v4 = -1.0e30;
    v5 = (float *)(p + 8);
    do
    {
      if ( v5 != (float *)8 )
      {
        *(v5 - 2) = v3;
        *(v5 - 1) = v3;
        *v5 = v4;
        v5[1] = v4;
        GMatrix2D::SetIdentity(this: v5 + 2);
        v3 = 1.0e30;
        v4 = -1.0e30;
      }
      v5 += 10;
      --v2;
    }
    while ( v2 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10105690
// Name: public: class GRect<float> GFxScale9GridInfo::AdjustBounds(class GRect<float> const __near &)const
// Source: json
//------------------------------------------------------------------------------
float *__thiscall GFxScale9GridInfo::AdjustBounds(GFxScale9GridInfo *this, float *a2, float xb1)
{
  float *v3; // eax
  GFxScale9GridInfo *v4; // ecx
  GFxScale9GridInfo *v5; // ecx
  GFxScale9GridInfo *v6; // ecx
  double v7; // st6
  double v8; // st7
  float y4; // [esp+0h] [ebp-24h] BYREF
  float x4; // [esp+4h] [ebp-20h] BYREF
  float y3; // [esp+8h] [ebp-1Ch] BYREF
  float x3; // [esp+Ch] [ebp-18h] BYREF
  float y2; // [esp+10h] [ebp-14h] BYREF
  float x2; // [esp+14h] [ebp-10h] BYREF
  float yb2; // [esp+18h] [ebp-Ch] BYREF
  float xb2; // [esp+1Ch] [ebp-8h]
  float yb1; // [esp+20h] [ebp-4h]

  v3 = (float *)LODWORD(xb1);
  xb1 = *(float *)LODWORD(xb1);
  yb2 = v3[1];
  x2 = v3[2];
  y2 = v3[1];
  x3 = v3[2];
  y3 = v3[3];
  x4 = *v3;
  y4 = v3[3];
  GFxScale9GridInfo::Transform(this, x: &xb1, y: &yb2);
  GFxScale9GridInfo::Transform(this: v4, x: &x2, y: &y2);
  GFxScale9GridInfo::Transform(this: v5, x: &x3, y: &y3);
  GFxScale9GridInfo::Transform(this: v6, x: &x4, y: &y4);
  yb1 = yb2;
  v7 = xb1;
  v8 = yb2;
  xb2 = xb1;
  if ( x2 < (double)xb1 )
    xb1 = x2;
  if ( y2 < v8 )
    yb1 = y2;
  if ( v7 < x2 )
    xb2 = x2;
  if ( y2 > v8 )
    yb2 = y2;
  if ( xb1 > (double)x3 )
    xb1 = x3;
  if ( yb1 > (double)y3 )
    yb1 = y3;
  if ( xb2 < (double)x3 )
    xb2 = x3;
  if ( yb2 < (double)y3 )
    yb2 = y3;
  if ( xb1 > (double)x4 )
    xb1 = x4;
  if ( yb1 > (double)y4 )
    yb1 = y4;
  if ( xb2 < (double)x4 )
    xb2 = x4;
  if ( yb2 < (double)y4 )
    yb2 = y4;
  *a2 = xb1;
  a2[1] = yb1;
  a2[2] = xb2;
  a2[3] = yb2;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x101058A0
// Name: public: GFxScale9GridInfo::GFxScale9GridInfo(struct GFxScale9Grid const __near *,class GMatrix2D const __near &,class GMatrix2D const __near &,float,class GRect<float> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxScale9GridInfo::GFxScale9GridInfo(
        CMemberFuncProxy1<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(Vector),Vector,CFuncMemPolicyNone> *this,
        CMatRenderContextBase *gr,
        __int128 s9gMtx)
{
  int i; // [esp+Ch] [ebp-8h]
  float *v5; // [esp+10h] [ebp-4h]
  float gra; // [esp+1Ch] [ebp+8h]

  LODWORD(this->m_pfnProxied) = &GRefCountImplCore::`vftable';
  DWORD1(this->m_pfnProxied) = 1;
  LODWORD(this->m_pfnProxied) = &GFxScale9GridInfo::`vftable';
  GMatrix2D::SetIdentity(this: (float *)this + 6);
  GMatrix2D::SetIdentity(this: (float *)this + 12);
  *((float *)this + 19) = 0.0;
  *((float *)this + 20) = 0.0;
  *((float *)this + 21) = 0.0;
  *((float *)this + 22) = 0.0;
  *((float *)this + 24) = 0.0;
  *((float *)this + 25) = 0.0;
  *((float *)this + 26) = 0.0;
  *((float *)this + 27) = 0.0;
  GMatrix2D::SetIdentity(this: (float *)this + 28);
  v5 = (float *)((char *)this + 136);
  for ( i = 8; i >= 0; --i )
  {
    GMatrix2D::SetIdentity(this: v5);
    v5 += 6;
  }
  *((_DWORD *)this + 88) = 0;
  *((_DWORD *)this + 89) = 0;
  *((_DWORD *)this + 90) = 0;
  *(CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> > *)((char *)&this->m_pfnProxied + 8) = gr->CRefCounted1<IMatRenderContextInternal,CRefCountServiceBase<1,CRefMT> >;
  *((_DWORD *)&this->m_pObject + 1) = gr->m_pCurrentMaterial;
  *((float *)this + 6) = *(float *)s9gMtx;
  *((float *)this + 7) = *(float *)(s9gMtx + 4);
  *((float *)this + 8) = *(float *)(s9gMtx + 8);
  *((float *)this + 9) = *(float *)(s9gMtx + 12);
  *((float *)this + 10) = *(float *)(s9gMtx + 16);
  *((float *)this + 11) = *(float *)(s9gMtx + 20);
  *((float *)this + 12) = *(float *)DWORD1(s9gMtx);
  *((float *)this + 13) = *(float *)(DWORD1(s9gMtx) + 4);
  *((float *)this + 14) = *(float *)(DWORD1(s9gMtx) + 8);
  *((float *)this + 15) = *(float *)(DWORD1(s9gMtx) + 12);
  *((float *)this + 16) = *(float *)(DWORD1(s9gMtx) + 16);
  *((float *)this + 17) = *(float *)(DWORD1(s9gMtx) + 20);
  *((float *)this + 18) = *((float *)&s9gMtx + 2);
  gra = *(float *)(HIDWORD(s9gMtx) + 4);
  *(float *)&s9gMtx = *(float *)(HIDWORD(s9gMtx) + 8);
  *((float *)&s9gMtx + 1) = *(float *)(HIDWORD(s9gMtx) + 12);
  *((float *)this + 19) = *(float *)HIDWORD(s9gMtx);
  *((float *)this + 20) = gra;
  *((float *)this + 21) = *(float *)&s9gMtx;
  *((float *)this + 22) = *((float *)&s9gMtx + 1);
  *((_BYTE *)this + 92) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10105A10
// Name: public: void GFxTexture9Grid::Compute(struct GFxScale9GridInfo const __near &,class GRect<float> const __near &,float,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GFxTexture9Grid::Compute(
        int a1@<ecx>,
        const CMaterialDict::MaterialLookup_t *a2@<edi>,
        GFxScale9GridInfo *a3,
        float *a4,
        float a5,
        int a6)
{
  int v6; // edi
  double v8; // st6
  double v9; // st7
  double v10; // st6
  float *v11; // ebx
  double v12; // st5
  double v13; // st3
  double v14; // st4
  double v15; // st4
  bool v16; // c0
  bool v17; // c3
  double v18; // st4
  double v19; // st3
  double v20; // st2
  bool v21; // c0
  bool v22; // c3
  double v23; // st2
  double v24; // st4
  double v25; // st4
  int v26; // edi
  GFxScale9GridInfo *v27; // ecx
  float v29; // [esp+0h] [ebp-E0h]
  float v30; // [esp+4h] [ebp-DCh]
  float v31; // [esp+8h] [ebp-D8h]
  float v32; // [esp+10h] [ebp-D0h]
  float v33; // [esp+14h] [ebp-CCh]
  float v34; // [esp+18h] [ebp-C8h]
  float v35; // [esp+1Ch] [ebp-C4h]
  float v36; // [esp+20h] [ebp-C0h]
  float v38; // [esp+28h] [ebp-B8h]
  float v39; // [esp+28h] [ebp-B8h]
  float v40; // [esp+2Ch] [ebp-B4h]
  float v41; // [esp+2Ch] [ebp-B4h]
  int i; // [esp+2Ch] [ebp-B4h]
  float v43; // [esp+30h] [ebp-B0h]
  float v44; // [esp+30h] [ebp-B0h]
  float v45; // [esp+30h] [ebp-B0h]
  float v46; // [esp+30h] [ebp-B0h]
  float v47; // [esp+30h] [ebp-B0h]
  float v48; // [esp+34h] [ebp-ACh] BYREF
  float v49; // [esp+38h] [ebp-A8h]
  float v50; // [esp+3Ch] [ebp-A4h]
  float v51; // [esp+40h] [ebp-A0h]
  float v52; // [esp+44h] [ebp-9Ch]
  float v53; // [esp+48h] [ebp-98h]
  float v54; // [esp+4Ch] [ebp-94h]
  float v55; // [esp+50h] [ebp-90h]
  float v56[34]; // [esp+54h] [ebp-8Ch] BYREF

  v6 = a1;
  *(_DWORD *)(a1 + 332) = a6;
  *(_DWORD *)(a1 + 336) = 0;
  *(float *)a1 = 1.0 / a5;
  v54 = *((float *)a3 + 19);
  v55 = *((float *)a3 + 20);
  v56[0] = *((float *)a3 + 24);
  v56[1] = *((float *)a3 + 25);
  v56[2] = *((float *)a3 + 24);
  v56[3] = *((float *)a3 + 20);
  v56[4] = *((float *)a3 + 26);
  v56[5] = *((float *)a3 + 25);
  v56[6] = *((float *)a3 + 26);
  v56[7] = *((float *)a3 + 20);
  v56[8] = *((float *)a3 + 21);
  v56[9] = *((float *)a3 + 25);
  v56[10] = *((float *)a3 + 19);
  v56[11] = *((float *)a3 + 25);
  v56[12] = *((float *)a3 + 24);
  v56[13] = *((float *)a3 + 27);
  v56[14] = *((float *)a3 + 24);
  v56[15] = *((float *)a3 + 25);
  v56[16] = *((float *)a3 + 26);
  v56[17] = *((float *)a3 + 27);
  v56[18] = *((float *)a3 + 26);
  v56[19] = *((float *)a3 + 25);
  v56[20] = *((float *)a3 + 21);
  v56[21] = *((float *)a3 + 27);
  v56[22] = *((float *)a3 + 19);
  v56[23] = *((float *)a3 + 27);
  v56[24] = *((float *)a3 + 24);
  v56[25] = *((float *)a3 + 22);
  v56[26] = *((float *)a3 + 24);
  v56[27] = *((float *)a3 + 27);
  v56[28] = *((float *)a3 + 26);
  v56[29] = *((float *)a3 + 22);
  v56[30] = *((float *)a3 + 26);
  v56[31] = *((float *)a3 + 27);
  v56[32] = *((float *)a3 + 21);
  v8 = *((float *)a3 + 22);
  *(_DWORD *)(a1 + 328) = 0;
  v56[33] = v8;
  v32 = *a4;
  v29 = a4[1];
  v40 = a4[2] - *a4;
  v31 = 1.0 / v40;
  v41 = a4[3] - a4[1];
  v30 = 1.0 / v41;
  GMatrix2D::SetIdentity(this: &v48);
  GMatrix2D::SetInverse(a1: &v48, m: (const CMaterialDict::MaterialLookup_t *)a3 + 6, a3: a2);
  v9 = v53;
  v10 = v52;
  v11 = v56;
  v12 = v51;
  for ( i = 9; i != 0; --i )
  {
    v13 = *(v11 - 1);
    v14 = *(v11 - 2);
    *(v11 - 2) = v48 * v14 + v49 * v13 + v50;
    *(v11 - 1) = v14 * v12 + v13 * v10 + v9;
    v43 = *v11;
    v38 = v11[1];
    *v11 = v49 * v38 + v43 * v48 + v50;
    v11[1] = v43 * v12 + v38 * v10 + v9;
    v33 = *a4;
    v34 = a4[1];
    v35 = a4[2];
    v36 = a4[3];
    v15 = v11[1];
    v16 = v34 < v15;
    v17 = v34 == v15;
    v18 = v34;
    if ( (v16 || v17)
      && *(v11 - 1) <= (double)v36
      && (v19 = v35, *(v11 - 2) <= (double)v35)
      && (v20 = *v11, v21 = v33 < v20, v22 = v33 == v20, v23 = v33, v21 || v22) )
    {
      if ( *(v11 - 2) > v23 )
        v23 = *(v11 - 2);
      v44 = v23;
      *(v11 - 2) = v44;
      if ( *v11 <= v19 )
        v19 = *v11;
      v45 = v19;
      *v11 = v45;
      if ( *(v11 - 1) > v18 )
        v18 = *(v11 - 1);
      v46 = v18;
      *(v11 - 1) = v46;
      v25 = v36;
      if ( v36 >= (double)v11[1] )
        v25 = v11[1];
      v47 = v25;
      v24 = v47;
    }
    else
    {
      *(v11 - 2) = 0.0;
      *(v11 - 1) = 0.0;
      v39 = 0.0 + 0.0;
      v24 = v39;
      *v11 = v39;
    }
    v11[1] = v24;
    if ( *v11 > (double)*(v11 - 2) && v11[1] > (double)*(v11 - 1) )
    {
      v26 = v6 + 36 * *(_DWORD *)(v6 + 328) + 4;
      *(float *)v26 = *(v11 - 2);
      *(float *)(v26 + 4) = *(v11 - 1);
      *(float *)(v26 + 8) = *v11;
      *(float *)(v26 + 12) = v11[1];
      GFxScale9GridInfo::Transform(this: a3, x: (float *)v26, y: (float *)(v26 + 4));
      GFxScale9GridInfo::Transform(this: v27, x: (float *)(v26 + 8), y: (float *)(v26 + 12));
      *(float *)v26 = *(float *)v26 * a5;
      *(float *)(v26 + 4) = *(float *)(v26 + 4) * a5;
      *(float *)(v26 + 8) = *(float *)(v26 + 8) * a5;
      *(float *)(v26 + 12) = a5 * *(float *)(v26 + 12);
      *(float *)(v26 + 16) = (*(v11 - 2) - v32) * v31;
      *(float *)(v26 + 20) = (*(v11 - 1) - v29) * v30;
      *(float *)(v26 + 24) = v31 * (*v11 - v32);
      *(float *)(v26 + 28) = v30 * (v11[1] - v29);
      *(_DWORD *)(v26 + 32) = -1;
      v9 = v53;
      ++*(_DWORD *)(a1 + 328);
      v10 = v52;
      v6 = a1;
      v12 = v51;
    }
    v11 += 4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10105EA0
// Name: public: void GFxScale9GridInfo::ComputeImgAdjustRects(class GCompoundShape const __near &,class GFxFillStyle const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxScale9GridInfo::ComputeImgAdjustRects(
        CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,LightDesc_t const *),int,LightDesc_t const *,CFuncMemPolicyNone> *this,
        int a2,
        int a3,
        unsigned int fillStylesNum)
{
  int v4; // eax
  unsigned int v6; // ecx
  int v8; // ebx
  int v9; // eax
  unsigned int v10; // eax
  char *v11; // edi
  float *v12; // eax
  int v13; // eax
  unsigned int v14; // ebx
  void **p_m_pObject; // edi
  float *v16; // eax
  int v17; // [esp+4h] [ebp-Ch]
  unsigned int i; // [esp+8h] [ebp-8h]
  CMemberFuncProxy2<CMatRenderContextBase *,void (__thiscall IMatRenderContext::*)(int,LightDesc_t const *),int,LightDesc_t const *,CFuncMemPolicyNone> *v19; // [esp+Ch] [ebp-4h]
  unsigned int fillStylesNuma; // [esp+20h] [ebp+10h]

  v4 = a2;
  v6 = 0;
  v19 = this;
  i = 0;
  if ( *(_DWORD *)(a2 + 24) != 0 )
  {
    while ( 1 )
    {
      v8 = *(_DWORD *)(*(_DWORD *)(v4 + 36) + 4 * (v6 >> 6)) + 24 * (v6 & 0x3F);
      v9 = *(_DWORD *)(v8 + 12);
      v17 = v8;
      if ( v9 >= 0 && (*(_BYTE *)(a3 + 40 * v9) & 0x50) != 0 )
        break;
LABEL_16:
      v13 = *(_DWORD *)(v8 + 16);
      if ( v13 >= 0 && (*(_BYTE *)(a3 + 40 * v13) & 0x50) != 0 )
      {
        if ( *((_DWORD *)&v19[14].m_pObject + 1) == 0 )
        {
          v14 = *((_DWORD *)&v19[14].m_pObject + 1);
          p_m_pObject = (void **)&v19[14].m_pObject;
          if ( fillStylesNum >= v14 )
          {
            if ( fillStylesNum >= LODWORD(v19[15].m_pfnProxied) )
              GArrayDataBase<GFxScale9GridInfo::ImgAdjust,GAllocatorGH<GFxScale9GridInfo::ImgAdjust,2>,GArrayDefaultPolicy>::Reserve(
                this: p_m_pObject,
                pheapAddr: (ButtonCode_t)p_m_pObject,
                newCapacity: fillStylesNum + (fillStylesNum >> 2));
          }
          else if ( fillStylesNum < LODWORD(v19[15].m_pfnProxied) >> 1 )
          {
            GArrayDataBase<GFxScale9GridInfo::ImgAdjust,GAllocatorGH<GFxScale9GridInfo::ImgAdjust,2>,GArrayDefaultPolicy>::Reserve(
              this: p_m_pObject,
              pheapAddr: (ButtonCode_t)p_m_pObject,
              newCapacity: fillStylesNum);
          }
          *((_DWORD *)&v19[14].m_pObject + 1) = fillStylesNum;
          if ( fillStylesNum > v14 )
            GConstructorMov<GFxScale9GridInfo::ImgAdjust>::ConstructArray(
              p: (char *)*p_m_pObject + 40 * v14,
              count: fillStylesNum - v14);
          v8 = v17;
        }
        v16 = (float *)((char *)v19[14].m_pObject + 40 * *(_DWORD *)(v8 + 16));
        GCompoundShape::ExpandPathBounds(
          a1: (const struct GCompoundShape::SPath *)v8,
          a2: v16,
          a3: v16 + 1,
          a4: v16 + 2,
          a5: v16 + 3);
        v6 = i;
      }
      v4 = a2;
      i = ++v6;
      if ( v6 >= *(_DWORD *)(a2 + 24) )
        return;
      this = v19;
    }
    if ( *((_DWORD *)this + 89) != 0 )
    {
LABEL_15:
      v12 = (float *)((char *)v19[14].m_pObject + 40 * *(_DWORD *)(v8 + 12));
      GCompoundShape::ExpandPathBounds(
        a1: (const struct GCompoundShape::SPath *)v8,
        a2: v12,
        a3: v12 + 1,
        a4: v12 + 2,
        a5: v12 + 3);
      v6 = i;
      goto LABEL_16;
    }
    v10 = *((_DWORD *)this + 89);
    v11 = (char *)this + 352;
    fillStylesNuma = v10;
    if ( fillStylesNum >= v10 )
    {
      if ( fillStylesNum < *((_DWORD *)v11 + 2) )
        goto LABEL_13;
      GArrayDataBase<GFxScale9GridInfo::ImgAdjust,GAllocatorGH<GFxScale9GridInfo::ImgAdjust,2>,GArrayDefaultPolicy>::Reserve(
        this: (void **)v11,
        pheapAddr: (ButtonCode_t)v11,
        newCapacity: fillStylesNum + (fillStylesNum >> 2));
    }
    else
    {
      if ( fillStylesNum >= *((_DWORD *)v11 + 2) >> 1 )
        goto LABEL_13;
      GArrayDataBase<GFxScale9GridInfo::ImgAdjust,GAllocatorGH<GFxScale9GridInfo::ImgAdjust,2>,GArrayDefaultPolicy>::Reserve(
        this: (void **)v11,
        pheapAddr: (ButtonCode_t)v11,
        newCapacity: fillStylesNum);
    }
    v10 = fillStylesNuma;
LABEL_13:
    *((_DWORD *)v11 + 1) = fillStylesNum;
    if ( fillStylesNum > v10 )
      GConstructorMov<GFxScale9GridInfo::ImgAdjust>::ConstructArray(
        p: (char *)(*(_DWORD *)v11 + 40 * v10),
        count: fillStylesNum - v10);
    goto LABEL_15;
  }
}
