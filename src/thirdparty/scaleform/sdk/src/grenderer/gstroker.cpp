// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/grenderer/gstroker.cpp
// Functions: 9
// ============================================================

#include "thirdparty\scaleform\sdk\src\grenderer\gstroker.h"

//------------------------------------------------------------------------------
// Address: 0x1017C680
// Name: public: bool GStrokeVertexType::CalcDistance(struct GStrokeVertexType const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GStrokeVertexType::CalcDistance(GStrokeVertexType *this, const struct GStrokeVertexType *a2)
{
  float v3; // [esp+4h] [ebp-4h]
  float v4; // [esp+10h] [ebp+8h]
  float v5; // [esp+10h] [ebp+8h]
  float v6; // [esp+10h] [ebp+8h]

  v3 = *(float *)a2 - *(float *)this;
  v4 = *((float *)a2 + 1) - *((float *)this + 1);
  v5 = v4 * v4 + v3 * v3;
  v6 = sqrt(v5);
  *((float *)this + 2) = v6;
  return v6 > 0.00009999999747378752;
}

//------------------------------------------------------------------------------
// Address: 0x1017C770
// Name: public: void GStrokePath::ClosePath(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStrokePath::ClosePath(GStrokePath *this, bool a2)
{
  unsigned int v3; // ecx
  _DWORD **v4; // edx
  _DWORD *v5; // ebx
  unsigned int v6; // edi
  _DWORD *v7; // eax
  bool v8; // dl
  bool v9; // cc
  unsigned int v10; // edx
  unsigned int v11; // edi
  int v12; // eax
  int v13; // edi
  double v14; // st7
  int v15; // ebx
  float *v16; // edi
  unsigned int v17; // ecx
  int v18; // edi
  int v19; // ebx
  int v20; // eax
  unsigned int v21; // edi
  _DWORD *v22; // eax
  unsigned int v23; // ecx
  float *v24; // edi
  int v25; // [esp+10h] [ebp-Ch]
  int v26; // [esp+14h] [ebp-8h]
  float v27; // [esp+18h] [ebp-4h]
  float v28; // [esp+18h] [ebp-4h]
  float v29; // [esp+24h] [ebp+8h]
  float v30; // [esp+24h] [ebp+8h]
  float v31; // [esp+24h] [ebp+8h]
  float v32; // [esp+24h] [ebp+8h]
  float v33; // [esp+24h] [ebp+8h]
  float v34; // [esp+24h] [ebp+8h]

  LOBYTE(((unsigned int *)*this)[4]) = 0;
  if ( a2 )
  {
    v3 = ((unsigned int *)*this)[0];
    if ( ((unsigned int *)*this)[0] != 0 )
    {
      v4 = (_DWORD **)((unsigned int *)*this)[3];
      v5 = *v4;
      if ( v3 > 1
        && !GStrokeVertexType::CalcDistance(
              this: (GStrokeVertexType *)&v4[(v3 - 2) >> 6][3 * (((_BYTE)v3 - 2) & 0x3F)],
              a2: (const struct GStrokeVertexType *)&v4[(v3 - 1) >> 6][3 * ((v3 - 1) & 0x3F)])
        && ((unsigned int *)*this)[0] != 0 )
      {
        --((unsigned int *)*this)[0];
      }
      v6 = ((unsigned int *)*this)[0] >> 6;
      if ( v6 >= ((unsigned int *)*this)[1] )
        GArrayPagedBase<GStrokeVertexType,6,16,GAllocatorPagedLH_POD<GStrokeVertexType,135>>::allocatePage(
          (unsigned int *)this,
          nb: ((unsigned int *)*this)[0] >> 6);
      v7 = (_DWORD *)(*(_DWORD *)(((unsigned int *)*this)[3] + 4 * v6) + 12 * (((unsigned int *)*this)[0] & 0x3F));
      *v7 = *v5;
      v7[1] = v5[1];
      v7[2] = v5[2];
      ++((unsigned int *)*this)[0];
    }
  }
  if ( ((unsigned int *)*this)[0] > 1 )
  {
    v8 = !GStrokeVertexType::CalcDistance(
            this: (GStrokeVertexType *)(*(_DWORD *)(((unsigned int *)*this)[3] + 4 * ((((unsigned int *)*this)[0] - 1) >> 6))
                                + 12 * ((((unsigned int *)*this)[0] - 1) & 0x3F)),
            a2: *(const struct GStrokeVertexType **)((unsigned int *)*this)[3]);
    v9 = ((unsigned int *)*this)[0] <= 1;
    LOBYTE(((unsigned int *)*this)[4]) = v8;
    if ( !v9 )
    {
      do
      {
        v10 = ((unsigned int *)*this)[3];
        v11 = ((unsigned int *)*this)[0] - 1;
        v12 = 3 * (v11 & 0x3F);
        v13 = *(_DWORD *)(v10 + 4 * (v11 >> 6));
        v14 = *(float *)(v13 + 4 * v12);
        v15 = v13 + 4 * v12;
        v16 = (float *)(*(_DWORD *)(v10 + 4 * ((((unsigned int *)*this)[0] - 2) >> 6))
                      + 12 * ((((unsigned int *)*this)[0] - 2) & 0x3F));
        v27 = v14 - *v16;
        v29 = *(float *)(v15 + 4) - v16[1];
        v30 = v29 * v29 + v27 * v27;
        v31 = sqrt(v30);
        v16[2] = v31;
        if ( v31 > 0.00009999999747378752 )
          break;
        v17 = ((unsigned int *)*this)[0] - 1;
        v18 = *(_DWORD *)(((unsigned int *)*this)[3] + 4 * (v17 >> 6));
        v19 = *(_DWORD *)(v18 + 12 * ((((unsigned int *)*this)[0] - 1) & 0x3F));
        v20 = v18 + 12 * ((((unsigned int *)*this)[0] - 1) & 0x3F);
        v25 = *(_DWORD *)(v20 + 4);
        v26 = *(_DWORD *)(v20 + 8);
        if ( ((unsigned int *)*this)[0] != 0 )
        {
          ((unsigned int *)*this)[0] = v17;
          if ( v17 != 0 )
            ((unsigned int *)*this)[0] = v17 - 1;
        }
        v21 = ((unsigned int *)*this)[0] >> 6;
        if ( v21 >= ((unsigned int *)*this)[1] )
          GArrayPagedBase<GStrokeVertexType,6,16,GAllocatorPagedLH_POD<GStrokeVertexType,135>>::allocatePage(
            (unsigned int *)this,
            nb: ((unsigned int *)*this)[0] >> 6);
        v22 = (_DWORD *)(*(_DWORD *)(((unsigned int *)*this)[3] + 4 * v21) + 12 * (((unsigned int *)*this)[0] & 0x3F));
        *v22 = v19;
        v22[1] = v25;
        v22[2] = v26;
        ++((unsigned int *)*this)[0];
      }
      while ( ((unsigned int *)*this)[0] > 1 );
    }
  }
  if ( LOBYTE(((unsigned int *)*this)[4]) != 0 )
  {
    while ( ((unsigned int *)*this)[0] > 2 )
    {
      v23 = ((unsigned int *)*this)[3];
      v24 = (float *)(*(_DWORD *)(v23 + 4 * ((((unsigned int *)*this)[0] - 1) >> 6))
                    + 12 * ((((unsigned int *)*this)[0] - 1) & 0x3F));
      v28 = **(float **)v23 - *v24;
      v32 = *(float *)(*(_DWORD *)v23 + 4) - v24[1];
      v33 = v32 * v32 + v28 * v28;
      v34 = sqrt(v33);
      v24[2] = v34;
      if ( v34 > 0.00009999999747378752 )
        break;
      if ( ((unsigned int *)*this)[0] != 0 )
        --((unsigned int *)*this)[0];
    }
    if ( ((unsigned int *)*this)[0] < 3 )
      LOBYTE(((unsigned int *)*this)[4]) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017C9B0
// Name: private: void GStroker::calcArc(class GCompoundShape __near &,float,float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStroker::calcArc(
        GStroker *this,
        struct GCompoundShape *da,
        float a3,
        float y,
        float dx1,
        float dy1,
        float dx2,
        float dy2)
{
  unsigned int v10; // edi
  double v11; // st7
  double v12; // st6
  int v13; // edi
  int v14; // eax
  double v15; // st6
  double v16; // st5
  unsigned int v17; // edi
  int v18; // ecx
  int v19; // eax
  unsigned int v20; // edi
  int v21; // ecx
  int v22; // eax
  float v23; // [esp+0h] [ebp-14h]
  float v24; // [esp+0h] [ebp-14h]
  float v25; // [esp+0h] [ebp-14h]
  float v26; // [esp+4h] [ebp-10h]
  float v27; // [esp+4h] [ebp-10h]
  float v28; // [esp+4h] [ebp-10h]
  float a2a; // [esp+Ch] [ebp-8h]
  float a2; // [esp+Ch] [ebp-8h]
  float a2b; // [esp+Ch] [ebp-8h]
  float a1; // [esp+10h] [ebp-4h]
  float a1a; // [esp+10h] [ebp-4h]
  float dac; // [esp+1Ch] [ebp+8h]
  float dad; // [esp+1Ch] [ebp+8h]
  float daa; // [esp+1Ch] [ebp+8h]
  float dab; // [esp+1Ch] [ebp+8h]
  int dx1a; // [esp+28h] [ebp+14h]
  float dy1a; // [esp+2Ch] [ebp+18h]
  float dy1b; // [esp+2Ch] [ebp+18h]

  a2a = atan2(dy1, dx1);
  a1 = a2a;
  a2 = atan2(dy2, dx2);
  dac = *((float *)this + 1) / (*(float *)da * 0.25 + *((float *)this + 1));
  dad = acos(dac);
  v10 = *((_DWORD *)da + 2) >> 8;
  daa = dad + dad;
  if ( v10 >= *((_DWORD *)da + 3) )
    GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(
      this: (unsigned int *)da + 2,
      a2: v10);
  v11 = a1;
  v12 = a2;
  v13 = *(_DWORD *)(*((_DWORD *)da + 5) + 4 * v10);
  v14 = (unsigned __int8)*((_DWORD *)da + 2);
  v23 = a3 + dx1;
  *(float *)(v13 + 8 * v14) = v23;
  v26 = y + dy1;
  *(float *)(v13 + 8 * v14 + 4) = v26;
  ++*((_DWORD *)da + 2);
  ++*(_DWORD *)(*((_DWORD *)da + 10) + 4);
  if ( a2 < (double)a1 )
  {
    a2b = v12 + 6.283185482025146;
    v12 = a2b;
  }
  v15 = v12 - v11;
  v16 = v15 / daa;
  dab = v15 / (double)((int)v16 + 1);
  a1a = v11 + dab;
  if ( (int)v16 > 0 )
  {
    dx1a = (int)v16;
    do
    {
      dy1a = cos(a1a);
      v24 = dy1a * *((float *)this + 1) + a3;
      dy1b = sin(a1a);
      v17 = *((_DWORD *)da + 2) >> 8;
      v27 = dy1b * *((float *)this + 1) + y;
      if ( v17 >= *((_DWORD *)da + 3) )
        GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(
          this: (unsigned int *)da + 2,
          a2: v17);
      v18 = *(_DWORD *)(*((_DWORD *)da + 5) + 4 * v17);
      v19 = (unsigned __int8)*((_DWORD *)da + 2);
      a1a = dab + a1a;
      *(float *)(v18 + 8 * v19) = v24;
      *(float *)(v18 + 8 * v19 + 4) = v27;
      ++*((_DWORD *)da + 2);
      ++*(_DWORD *)(*((_DWORD *)da + 10) + 4);
      --dx1a;
    }
    while ( dx1a != 0 );
  }
  v20 = *((_DWORD *)da + 2) >> 8;
  if ( v20 >= *((_DWORD *)da + 3) )
    GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(
      this: (unsigned int *)da + 2,
      a2: v20);
  v21 = *(_DWORD *)(*((_DWORD *)da + 5) + 4 * v20);
  v22 = (unsigned __int8)*((_DWORD *)da + 2);
  v25 = a3 + dx2;
  *(float *)(v21 + 8 * v22) = v25;
  v28 = y + dy2;
  *(float *)(v21 + 8 * v22 + 4) = v28;
  ++*((_DWORD *)da + 2);
  ++*(_DWORD *)(*((_DWORD *)da + 10) + 4);
}

//------------------------------------------------------------------------------
// Address: 0x1017CB70
// Name: private: void GStroker::calcMiter(class GCompoundShape __near &,struct GStrokeVertexType const __near &,struct GStrokeVertexType const __near &,struct GStrokeVertexType const __near &,float,float,float,float,enum GStrokerTypes::LineJoinType,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStroker::calcMiter(
        GStroker *this,
        struct GCompoundShape *da,
        float *a3,
        float *a4,
        float *a5,
        float a6,
        float a7,
        float a8,
        float a9,
        int a10,
        float a11,
        float a12,
        float a13)
{
  double v17; // st7
  double v18; // st6
  double v19; // st4
  double v20; // st5
  double v21; // st2
  double v22; // st3
  unsigned int v24; // ecx
  int v25; // ecx
  int v26; // eax
  char v27; // al
  char v28; // cl
  double v29; // st4
  double v30; // st3
  double v31; // st5
  unsigned int v32; // ecx
  double v33; // rt2
  double v34; // st3
  double v35; // st6
  double v36; // rtt
  double v37; // st4
  double v38; // st7
  int v39; // ecx
  int v40; // eax
  double v41; // st7
  unsigned int v42; // edi
  int v43; // ecx
  int v44; // eax
  double v45; // st7
  unsigned int v46; // edi
  double v47; // st7
  int v48; // ecx
  int v49; // eax
  unsigned int v50; // ecx
  double v51; // rt0
  double v52; // st4
  double v53; // st7
  double v54; // st5
  double v55; // st6
  int v56; // ecx
  int v57; // eax
  unsigned int v58; // edi
  int v59; // edi
  int v60; // eax
  float dx1; // [esp+8h] [ebp-5Ch]
  float dy1; // [esp+Ch] [ebp-58h]
  float dx2; // [esp+10h] [ebp-54h]
  float v64; // [esp+14h] [ebp-50h]
  double v65; // [esp+24h] [ebp-40h]
  double v66; // [esp+2Ch] [ebp-38h]
  float v67; // [esp+34h] [ebp-30h]
  float v68; // [esp+34h] [ebp-30h]
  float v69; // [esp+34h] [ebp-30h]
  float v70; // [esp+34h] [ebp-30h]
  GStroker *v71; // [esp+38h] [ebp-2Ch]
  float v72; // [esp+38h] [ebp-2Ch]
  float v73; // [esp+38h] [ebp-2Ch]
  float v74; // [esp+38h] [ebp-2Ch]
  float v75; // [esp+38h] [ebp-2Ch]
  float v76; // [esp+40h] [ebp-24h]
  float v77; // [esp+40h] [ebp-24h]
  float v78; // [esp+44h] [ebp-20h]
  float v79; // [esp+48h] [ebp-1Ch]
  float v80; // [esp+48h] [ebp-1Ch]
  float v81; // [esp+4Ch] [ebp-18h]
  float v82; // [esp+50h] [ebp-14h]
  float v83; // [esp+58h] [ebp-Ch]
  float v84; // [esp+5Ch] [ebp-8h]
  float v85; // [esp+5Ch] [ebp-8h]
  float dad; // [esp+6Ch] [ebp+8h]
  float dae; // [esp+6Ch] [ebp+8h]
  float daf; // [esp+6Ch] [ebp+8h]
  float dag; // [esp+6Ch] [ebp+8h]
  float dah; // [esp+6Ch] [ebp+8h]
  struct GCompoundShape *daa; // [esp+6Ch] [ebp+8h]
  struct GCompoundShape *dab; // [esp+6Ch] [ebp+8h]
  float dac; // [esp+6Ch] [ebp+8h]
  float v94; // [esp+70h] [ebp+Ch]
  float v95; // [esp+70h] [ebp+Ch]
  float v96; // [esp+74h] [ebp+10h]
  float v97; // [esp+74h] [ebp+10h]
  float v98; // [esp+78h] [ebp+14h]
  float v99; // [esp+78h] [ebp+14h]
  float v100; // [esp+7Ch] [ebp+18h]
  float v101; // [esp+84h] [ebp+20h]
  float v102; // [esp+88h] [ebp+24h]
  float v103; // [esp+90h] [ebp+2Ch]
  unsigned int v104; // [esp+90h] [ebp+2Ch]

  v84 = 1.0;
  v78 = *((float *)this + 1) * a11;
  v71 = this;
  v17 = a6;
  v79 = *a3 + a6;
  v18 = a7;
  v76 = a3[1] + a7;
  v83 = *a4 + a6;
  v82 = a4[1] + a7;
  v94 = *a4 + a8;
  v96 = a4[1] + a9;
  v98 = a8 + *a5;
  v81 = a9 + a5[1];
  v19 = v79;
  v20 = v83 - v79;
  v66 = v81 - v96;
  v21 = v76;
  v22 = v82 - v76;
  v65 = v98 - v94;
  v80 = v66 * v20 - v65 * v22;
  v77 = fabs(v80);
  if ( a12 <= (double)v77 )
  {
    dad = (v21 - v96) * v65 - (v19 - v94) * v66;
    dae = dad / v80;
    v95 = v19 + v20 * dae;
    v97 = v22 * dae + v21;
    v99 = v95 - *a4;
    daf = v97 - a4[1];
    dag = daf * daf + v99 * v99;
    dah = sqrt(dag);
    v84 = dah;
    if ( v78 < (double)dah )
    {
      v27 = 1;
    }
    else
    {
      v24 = *((_DWORD *)da + 2) >> 8;
      daa = (struct GCompoundShape *)v24;
      if ( v24 >= *((_DWORD *)da + 3) )
      {
        GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(
          this: (unsigned int *)da + 2,
          a2: v24);
        v24 = (unsigned int)daa;
      }
      v25 = *(_DWORD *)(*((_DWORD *)da + 5) + 4 * v24);
      v26 = (unsigned __int8)*((_DWORD *)da + 2);
      *(float *)(v25 + 8 * v26) = v95;
      *(float *)(v25 + 8 * v26 + 4) = v97;
      ++*((_DWORD *)da + 2);
      ++*(_DWORD *)(*((_DWORD *)da + 10) + 4);
      v27 = 0;
    }
    v28 = 0;
    if ( v27 == 0 )
      return;
    v17 = a6;
    this = v71;
    v18 = a7;
    v29 = a9;
    v30 = a8;
    v31 = a11;
  }
  else
  {
    v95 = v19 * 0.25 + v83 * 0.25 + v94 * 0.25 + v98 * 0.25;
    v97 = v21 * 0.25 + v82 * 0.25 + v96 * 0.25 + 0.25 * v81;
    v100 = a4[1] + v18;
    if ( (*a3 - v83) * v18 - (a3[1] - v100) * v17 < 0.0 != (*a5 - v83) * v18 - (a5[1] - v100) * v17 < 0.0 )
    {
      v42 = *((_DWORD *)da + 2) >> 8;
      if ( v42 >= *((_DWORD *)da + 3) )
        GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(
          this: (unsigned int *)da + 2,
          a2: v42);
      v43 = *(_DWORD *)(*((_DWORD *)da + 5) + 4 * v42);
      v44 = (unsigned __int8)*((_DWORD *)da + 2);
      *(float *)(v43 + 8 * v44) = v83;
      *(float *)(v43 + 8 * v44 + 4) = v100;
      ++*((_DWORD *)da + 2);
      ++*(_DWORD *)(*((_DWORD *)da + 10) + 4);
      return;
    }
    v28 = 1;
    v31 = a11;
    v29 = a9;
    v30 = a8;
  }
  if ( a10 == 1 )
  {
    v50 = *((_DWORD *)da + 2) >> 8;
    v104 = v50;
    v51 = v29;
    v52 = v17 + *a4;
    v53 = v51;
    v54 = v18 + a4[1];
    v55 = v30;
    if ( v50 >= *((_DWORD *)da + 3) )
    {
      GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(
        this: (unsigned int *)da + 2,
        a2: v50);
      v50 = v104;
      v55 = a8;
      v53 = a9;
    }
    v56 = *(_DWORD *)(*((_DWORD *)da + 5) + 4 * v50);
    v57 = (unsigned __int8)*((_DWORD *)da + 2);
    v70 = v52;
    *(float *)(v56 + 8 * v57) = v70;
    v74 = v54;
    *(float *)(v56 + 8 * v57 + 4) = v74;
    ++*((_DWORD *)da + 2);
    ++*(_DWORD *)(*((_DWORD *)da + 10) + 4);
    v68 = v55 + *a4;
    v41 = v53 + a4[1];
  }
  else
  {
    if ( a10 == 2 )
    {
      v64 = v29;
      dx2 = v30;
      dy1 = v18;
      dx1 = v17;
      GStroker::calcArc(this, da, a3: *a4, y: a4[1], dx1, dy1, dx2, dy2: v64);
      return;
    }
    if ( v28 != 0 )
    {
      v32 = *((_DWORD *)da + 2) >> 8;
      dab = (struct GCompoundShape *)v32;
      v67 = *a4 + v17 - v18 * v31;
      v33 = v30;
      v34 = v18 + a4[1];
      v35 = v33;
      v36 = v29;
      v37 = v17 * v31 + v34;
      v38 = v36;
      if ( v32 >= *((_DWORD *)da + 3) )
      {
        GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(
          this: (unsigned int *)da + 2,
          a2: v32);
        v32 = (unsigned int)dab;
        v38 = a9;
        v31 = a11;
        v35 = a8;
      }
      v39 = *(_DWORD *)(*((_DWORD *)da + 5) + 4 * v32);
      v40 = (unsigned __int8)*((_DWORD *)da + 2);
      *(float *)(v39 + 8 * v40) = v67;
      v72 = v37;
      *(float *)(v39 + 8 * v40 + 4) = v72;
      ++*((_DWORD *)da + 2);
      ++*(_DWORD *)(*((_DWORD *)da + 10) + 4);
      v68 = *a4 + v35 + v38 * v31;
      v41 = v38 + a4[1] - v35 * v31;
    }
    else
    {
      v101 = v17 + *a4;
      v102 = v18 + a4[1];
      v103 = v30 + *a4;
      v45 = v29 + a4[1];
      v46 = *((_DWORD *)da + 2) >> 8;
      dac = v45;
      v85 = (v78 - a13) / (v84 - a13);
      v47 = v85;
      if ( v46 >= *((_DWORD *)da + 3) )
      {
        GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(
          this: (unsigned int *)da + 2,
          a2: v46);
        v47 = v85;
      }
      v48 = *(_DWORD *)(*((_DWORD *)da + 5) + 4 * v46);
      v49 = (unsigned __int8)*((_DWORD *)da + 2);
      v69 = v101 + (v95 - v101) * v85;
      *(float *)(v48 + 8 * v49) = v69;
      v73 = (v97 - v102) * v85 + v102;
      *(float *)(v48 + 8 * v49 + 4) = v73;
      ++*((_DWORD *)da + 2);
      ++*(_DWORD *)(*((_DWORD *)da + 10) + 4);
      v68 = (v95 - v103) * v47 + v103;
      v41 = v47 * (v97 - dac) + dac;
    }
  }
  v58 = *((_DWORD *)da + 2) >> 8;
  if ( v58 >= *((_DWORD *)da + 3) )
    GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(
      this: (unsigned int *)da + 2,
      a2: v58);
  v59 = *(_DWORD *)(*((_DWORD *)da + 5) + 4 * v58);
  v60 = (unsigned __int8)*((_DWORD *)da + 2);
  *(float *)(v59 + 8 * v60) = v68;
  v75 = v41;
  *(float *)(v59 + 8 * v60 + 4) = v75;
  ++*((_DWORD *)da + 2);
  ++*(_DWORD *)(*((_DWORD *)da + 10) + 4);
}

//------------------------------------------------------------------------------
// Address: 0x1017D0A0
// Name: private: void GStroker::calcCap(class GCompoundShape __near &,struct GStrokeVertexType const __near &,struct GStrokeVertexType const __near &,float,enum GStrokerTypes::LineCapType)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GStroker::calcCap(float *this, int a2, float *a3, float *a4, float a5, int a6)
{
  double v8; // st7
  double v9; // st6
  unsigned int v10; // edi
  int v11; // ecx
  int v12; // eax
  double v13; // st7
  unsigned int v14; // ebx
  int v15; // ebx
  int v16; // eax
  int result; // eax
  int v18; // ecx
  unsigned int *v19; // esi
  unsigned int v20; // edi
  int v21; // edi
  int v22; // eax
  unsigned int v23; // edi
  int v24; // ecx
  int v25; // eax
  unsigned int v26; // edi
  int v27; // ecx
  int v28; // eax
  double v29; // [esp+0h] [ebp-1Ch]
  float v30; // [esp+0h] [ebp-1Ch]
  float v31; // [esp+0h] [ebp-1Ch]
  float v32; // [esp+4h] [ebp-18h]
  float v33; // [esp+4h] [ebp-18h]
  float v34; // [esp+8h] [ebp-14h]
  float v35; // [esp+8h] [ebp-14h]
  float v37; // [esp+Ch] [ebp-10h]
  float v38; // [esp+Ch] [ebp-10h]
  float v39; // [esp+10h] [ebp-Ch]
  int v40; // [esp+10h] [ebp-Ch]
  int i; // [esp+10h] [ebp-Ch]
  float v42; // [esp+14h] [ebp-8h]
  float v43; // [esp+18h] [ebp-4h]
  float v44; // [esp+18h] [ebp-4h]
  float v45; // [esp+18h] [ebp-4h]
  float v46; // [esp+18h] [ebp-4h]
  float v47; // [esp+28h] [ebp+Ch]
  float v48; // [esp+28h] [ebp+Ch]
  float v49; // [esp+28h] [ebp+Ch]
  float v50; // [esp+28h] [ebp+Ch]
  float v51; // [esp+2Ch] [ebp+10h]
  float v52; // [esp+30h] [ebp+14h]
  float v53; // [esp+34h] [ebp+18h]
  float v54; // [esp+34h] [ebp+18h]
  float v55; // [esp+34h] [ebp+18h]
  float v56; // [esp+34h] [ebp+18h]
  float v57; // [esp+34h] [ebp+18h]

  v43 = 0.0;
  v39 = 0.0;
  v47 = (a4[1] - a3[1]) / a5;
  v51 = v47 * *(this + 1);
  v48 = (*a3 - *a4) / a5;
  v52 = v48 * *(this + 1);
  if ( a6 == 2 )
  {
    v49 = atan2(-v52, -v51);
    v53 = v49 + 3.141592741012573;
    v29 = v53 - v49;
    v54 = *(this + 1) / (*(float *)a2 * 0.25 + *(this + 1));
    v55 = acos(v54);
    v56 = v55 + v55;
    v18 = (int)(v29 / v56);
    v19 = (unsigned int *)(a2 + 8);
    v20 = *(_DWORD *)(a2 + 8) >> 8;
    v40 = v18;
    v57 = v29 / (double)(v18 + 1);
    v50 = v57 + v49;
    v42 = *a3 - v51;
    v44 = a3[1] - v52;
    if ( v20 >= *(_DWORD *)(a2 + 12) )
    {
      GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(this: v19, a2: v20);
      v18 = v40;
    }
    v21 = *(_DWORD *)(*(_DWORD *)(a2 + 20) + 4 * v20);
    v22 = (unsigned __int8)*v19;
    *(float *)(v21 + 8 * v22) = v42;
    *(float *)(v21 + 8 * v22 + 4) = v44;
    ++*v19;
    ++*(_DWORD *)(*(_DWORD *)(a2 + 40) + 4);
    if ( v18 > 0 )
    {
      for ( i = v18; i != 0; --i )
      {
        v45 = cos(v50);
        v30 = v45 * *(this + 1) + *a3;
        v46 = sin(v50);
        v23 = *v19 >> 8;
        v32 = v46 * *(this + 1) + a3[1];
        if ( v23 >= *(_DWORD *)(a2 + 12) )
          GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(this: v19, a2: v23);
        v24 = *(_DWORD *)(*(_DWORD *)(a2 + 20) + 4 * v23);
        v25 = (unsigned __int8)*v19;
        v50 = v57 + v50;
        *(float *)(v24 + 8 * v25) = v30;
        *(float *)(v24 + 8 * v25 + 4) = v32;
        ++*v19;
        ++*(_DWORD *)(*(_DWORD *)(a2 + 40) + 4);
      }
    }
    v26 = *v19 >> 8;
    v31 = *a3 + v51;
    v33 = v52 + a3[1];
    if ( v26 >= *(_DWORD *)(a2 + 12) )
      GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(this: v19, a2: v26);
    v27 = *(_DWORD *)(*(_DWORD *)(a2 + 20) + 4 * v26);
    v28 = (unsigned __int8)*v19;
    *(float *)(v27 + 8 * v28) = v31;
    *(float *)(v27 + 8 * v28 + 4) = v33;
    ++*v19;
    result = *(_DWORD *)(a2 + 40);
    ++*(_DWORD *)(result + 4);
  }
  else
  {
    v8 = v51;
    v9 = v52;
    if ( a6 == 1 )
    {
      v43 = v48 * *(this + 1);
      v39 = v51;
    }
    v10 = *(_DWORD *)(a2 + 8) >> 8;
    v34 = *a3 - v8 + v43;
    v37 = a3[1] - v9 - v39;
    if ( v10 >= *(_DWORD *)(a2 + 12) )
    {
      GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(
        this: (unsigned int *)(a2 + 8),
        a2: v10);
      v8 = v51;
      v9 = v52;
    }
    v11 = *(_DWORD *)(*(_DWORD *)(a2 + 20) + 4 * v10);
    v12 = (unsigned __int8)*(_DWORD *)(a2 + 8);
    *(float *)(v11 + 8 * v12) = v34;
    *(float *)(v11 + 8 * v12 + 4) = v37;
    ++*(_DWORD *)(a2 + 8);
    ++*(_DWORD *)(*(_DWORD *)(a2 + 40) + 4);
    v35 = v8 + *a3 + v43;
    v13 = v9 + a3[1];
    v14 = *(_DWORD *)(a2 + 8) >> 8;
    if ( v14 >= *(_DWORD *)(a2 + 12) )
      GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(
        this: (unsigned int *)(a2 + 8),
        a2: v14);
    v15 = *(_DWORD *)(*(_DWORD *)(a2 + 20) + 4 * v14);
    v16 = (unsigned __int8)*(_DWORD *)(a2 + 8);
    *(float *)(v15 + 8 * v16) = v35;
    v38 = v13 - v39;
    *(float *)(v15 + 8 * v16 + 4) = v38;
    ++*(_DWORD *)(a2 + 8);
    result = *(_DWORD *)(a2 + 40);
    ++*(_DWORD *)(result + 4);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017D360
// Name: private: void GStroker::calcJoin(class GCompoundShape __near &,struct GStrokeVertexType const __near &,struct GStrokeVertexType const __near &,struct GStrokeVertexType const __near &,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStroker::calcJoin(
        GStroker *this,
        struct GCompoundShape *dstShape,
        const struct GStrokeVertexType *dstShape_4,
        const struct GStrokeVertexType *dx2,
        const struct GStrokeVertexType *minLen,
        float dy1,
        float dx1)
{
  double v7; // st7
  double v10; // st6
  double v12; // st5
  double v13; // st4
  int v14; // ecx
  double v16; // st6
  double v17; // st7
  double v18; // st5
  double v19; // st4
  double v20; // st2
  unsigned int v21; // edi
  int v22; // ecx
  int v23; // eax
  double v24; // st7
  unsigned int v25; // ecx
  int v26; // ecx
  int v27; // eax
  unsigned int v28; // edi
  int v29; // edi
  int v30; // eax
  float v31; // [esp+2Ch] [ebp-1Ch]
  float v32; // [esp+2Ch] [ebp-1Ch]
  float v33; // [esp+30h] [ebp-18h]
  float v34; // [esp+30h] [ebp-18h]
  float v35; // [esp+30h] [ebp-18h]
  float v36; // [esp+34h] [ebp-14h]
  float epsilon; // [esp+38h] [ebp-10h]
  float dya; // [esp+3Ch] [ebp-Ch]
  float dyb; // [esp+3Ch] [ebp-Ch]
  float dyc; // [esp+3Ch] [ebp-Ch]
  float dy; // [esp+3Ch] [ebp-Ch]
  float dyd; // [esp+3Ch] [ebp-Ch]
  float v43; // [esp+40h] [ebp-8h]
  float v44; // [esp+40h] [ebp-8h]
  float v45; // [esp+40h] [ebp-8h]
  float dy2; // [esp+44h] [ebp-4h]
  float dstShapea; // [esp+50h] [ebp+8h]
  float dstShape_4a; // [esp+54h] [ebp+Ch]
  float dstShape_4b; // [esp+54h] [ebp+Ch]
  float dx2a; // [esp+58h] [ebp+10h]
  float dx2b; // [esp+58h] [ebp+10h]
  float dx2c; // [esp+58h] [ebp+10h]
  float minLend; // [esp+5Ch] [ebp+14h]
  float minLene; // [esp+5Ch] [ebp+14h]
  float minLenf; // [esp+5Ch] [ebp+14h]
  float minLena; // [esp+5Ch] [ebp+14h]
  float minLenb; // [esp+5Ch] [ebp+14h]
  unsigned int minLenc; // [esp+5Ch] [ebp+14h]
  float dy1a; // [esp+60h] [ebp+18h]
  float dx1a; // [esp+64h] [ebp+1Ch]
  float dx1b; // [esp+64h] [ebp+1Ch]

  v7 = dy1;
  v10 = dx1;
  epsilon = (dy1 + dx1) * 0.009999999776482582;
  v12 = *((float *)dx2 + 1) - *((float *)dstShape_4 + 1);
  dx1a = *((float *)this + 1) * v12 / dy1;
  dy1a = (*(float *)dstShape_4 - *(float *)dx2) * *((float *)this + 1) / dy1;
  v13 = *((float *)minLen + 1) - *((float *)dx2 + 1);
  dx2a = *((float *)this + 1) * v13 / v10;
  dy2 = (*(float *)dx2 - *(float *)minLen) * *((float *)this + 1) / v10;
  dya = v12 * (*(float *)minLen - *(float *)dx2) - v13 * (*(float *)dx2 - *(float *)dstShape_4);
  if ( dya > 0.0 )
  {
    if ( v7 < v10 )
      v10 = v7;
    minLend = v10;
    minLene = minLend / *((float *)this + 1);
    GStroker::calcMiter(
      this,
      da: dstShape,
      a3: (float *)dstShape_4,
      a4: (float *)dx2,
      a5: (float *)minLen,
      a6: dx1a,
      a7: dy1a,
      a8: dx2a,
      a9: dy2,
      a10: 1,
      a11: minLene,
      a12: epsilon,
      a13: 0.0);
    return;
  }
  v43 = (dx2a + dx1a) * 0.5;
  dyb = 0.5 * (dy2 + dy1a);
  dyc = dyb * dyb + v43 * v43;
  dy = sqrt(dyc);
  v14 = *((_DWORD *)this + 2);
  if ( (v14 == 3 || v14 == 4) && *(float *)dstShape * 0.25 * 0.5 > *((float *)this + 1) - dy )
  {
    v44 = *(float *)dstShape_4 + dx1a;
    v33 = *((float *)dstShape_4 + 1) + dy1a;
    dx1b = dx1a + *(float *)dx2;
    v36 = dy1a + *((float *)dx2 + 1);
    dstShapea = *(float *)dx2 + dx2a;
    dstShape_4a = *((float *)dx2 + 1) + dy2;
    dx2b = dx2a + *(float *)minLen;
    minLenf = dy2 + *((float *)minLen + 1);
    v16 = v44;
    v17 = dx1b - v44;
    v18 = minLenf - dstShape_4a;
    v19 = v36 - v33;
    v20 = dx2b - dstShapea;
    minLena = v18 * v17 - v20 * v19;
    dx2c = fabs(minLena);
    if ( epsilon <= (double)dx2c )
    {
      v21 = *((_DWORD *)dstShape + 2) >> 8;
      dstShape_4b = v20 * (v33 - dstShape_4a) - v18 * (v16 - dstShapea);
      minLenb = dstShape_4b / minLena;
      if ( v21 >= *((_DWORD *)dstShape + 3) )
        GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(
          this: (unsigned int *)dstShape + 2,
          a2: v21);
      v22 = *(_DWORD *)(*((_DWORD *)dstShape + 5) + 4 * v21);
      v23 = (unsigned __int8)*((_DWORD *)dstShape + 2);
      v45 = v16 + v17 * minLenb;
      *(float *)(v22 + 8 * v23) = v45;
      dyd = v33 + v19 * minLenb;
      *(float *)(v22 + 8 * v23 + 4) = dyd;
      ++*((_DWORD *)dstShape + 2);
      ++*(_DWORD *)(*((_DWORD *)dstShape + 10) + 4);
      return;
    }
    v31 = dx1b;
    v24 = *((float *)dx2 + 1) + dy1a;
  }
  else
  {
    if ( v14 >= 0 )
    {
      if ( v14 <= 2 )
      {
        GStroker::calcMiter(
          this,
          da: dstShape,
          a3: (float *)dstShape_4,
          a4: (float *)dx2,
          a5: (float *)minLen,
          a6: dx1a,
          a7: dy1a,
          a8: dx2a,
          a9: dy2,
          a10: v14,
          a11: *((float *)this + 5),
          a12: epsilon,
          a13: dy);
        return;
      }
      if ( v14 == 3 )
      {
        GStroker::calcArc(
          this,
          da: dstShape,
          a3: *(float *)dx2,
          y: *((float *)dx2 + 1),
          dx1: dx1a,
          dy1: dy1a,
          dx2: dx2a,
          dy2);
        return;
      }
    }
    v25 = *((_DWORD *)dstShape + 2) >> 8;
    minLenc = v25;
    v32 = *(float *)dx2 + dx1a;
    v34 = *((float *)dx2 + 1) + dy1a;
    if ( v25 >= *((_DWORD *)dstShape + 3) )
    {
      GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(
        this: (unsigned int *)dstShape + 2,
        a2: v25);
      v25 = minLenc;
    }
    v26 = *(_DWORD *)(*((_DWORD *)dstShape + 5) + 4 * v25);
    v27 = (unsigned __int8)*((_DWORD *)dstShape + 2);
    *(float *)(v26 + 8 * v27) = v32;
    *(float *)(v26 + 8 * v27 + 4) = v34;
    ++*((_DWORD *)dstShape + 2);
    ++*(_DWORD *)(*((_DWORD *)dstShape + 10) + 4);
    v31 = *(float *)dx2 + dx2a;
    v24 = *((float *)dx2 + 1) + dy2;
  }
  v28 = *((_DWORD *)dstShape + 2) >> 8;
  if ( v28 >= *((_DWORD *)dstShape + 3) )
    GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(
      this: (unsigned int *)dstShape + 2,
      a2: v28);
  v29 = *(_DWORD *)(*((_DWORD *)dstShape + 5) + 4 * v28);
  v30 = (unsigned __int8)*((_DWORD *)dstShape + 2);
  v35 = v24;
  *(float *)(v29 + 8 * v30 + 4) = v35;
  *(float *)(v29 + 8 * v30) = v31;
  ++*((_DWORD *)dstShape + 2);
  ++*(_DWORD *)(*((_DWORD *)dstShape + 10) + 4);
}

//------------------------------------------------------------------------------
// Address: 0x1017D760
// Name: private: void GStroker::generateEquidistant(class GCompoundShape __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GStroker::generateEquidistant(int this@<ecx>, GCompoundShape *dstShape, long double bothSides)
{
  GCompoundShape *v4; // ebx
  unsigned int v5; // edi
  unsigned int v6; // eax
  unsigned int v7; // ecx
  unsigned int v8; // edx
  unsigned int v9; // ecx
  int v10; // ebx
  int v11; // edi
  int v12; // edx
  int i; // edi
  int v14; // eax
  int v15; // eax
  unsigned int v16; // ecx
  unsigned int v17; // eax
  int v18; // ebx
  int v19; // ecx
  unsigned int v20; // edi
  unsigned int v21; // eax
  unsigned int v22; // ecx
  unsigned int v23; // edx
  unsigned int v24; // ecx
  int v25; // ebx
  int v26; // edi
  int v27; // edx
  int v28; // ecx
  unsigned int v29; // edi
  unsigned int v30; // eax
  unsigned int v31; // eax
  unsigned int v32; // ecx
  unsigned int v33; // eax
  int v34; // ebx
  int v35; // ecx
  const struct GStrokeVertexType *v36; // [esp-4h] [ebp-24h]
  const struct GStrokeVertexType *v37; // [esp-4h] [ebp-24h]
  const struct GStrokeVertexType *v38; // [esp-4h] [ebp-24h]
  const struct GStrokeVertexType *v39; // [esp-4h] [ebp-24h]
  float v40; // [esp+4h] [ebp-1Ch]
  float v41; // [esp+4h] [ebp-1Ch]
  float *v42; // [esp+14h] [ebp-Ch]
  unsigned int v43; // [esp+14h] [ebp-Ch]
  float *v44; // [esp+14h] [ebp-Ch]
  unsigned int v45; // [esp+14h] [ebp-Ch]
  unsigned int v46; // [esp+18h] [ebp-8h]
  unsigned int v47; // [esp+18h] [ebp-8h]
  unsigned int v48; // [esp+18h] [ebp-8h]
  unsigned int v49; // [esp+1Ch] [ebp-4h]
  unsigned int v50; // [esp+1Ch] [ebp-4h]
  float *v51; // [esp+2Ch] [ebp+Ch]
  unsigned int v52; // [esp+2Ch] [ebp+Ch]
  float *v53; // [esp+2Ch] [ebp+Ch]

  if ( *(_DWORD *)(this + 24) >= 2u )
  {
    v4 = dstShape;
    if ( *(_BYTE *)(this + 40) == 0 )
    {
      GCompoundShape::BeginPath(this: dstShape, lStyle: 0, rStyle: -1, a4: -1);
      GStroker::calcCap(
        (float *)this,
        a2: (int)dstShape,
        a3: **(float ***)(this + 36),
        a4: (float *)(**(_DWORD **)(this + 36) + 12),
        a5: *(float *)(**(_DWORD **)(this + 36) + 8),
        a6: *(_DWORD *)(this + 12));
      v20 = *(_DWORD *)(this + 24);
      v21 = 1;
      if ( v20 - 1 > 1 )
      {
        do
        {
          v22 = v21;
          if ( v21 == 0 )
            v22 = v20;
          v23 = v21 + 1;
          v52 = v22 - 1;
          v50 = v21 + 1;
          if ( v21 + 1 >= v20 )
            v23 -= v20;
          v24 = v21;
          if ( v21 == 0 )
            v24 = v20;
          v25 = *(_DWORD *)(this + 36);
          v44 = (float *)(*(_DWORD *)(v25 + 4 * (v21 >> 6)) + 12 * (v21 & 0x3F));
          v26 = *(_DWORD *)(v25 + 4 * (v52 >> 6));
          v38 = (const struct GStrokeVertexType *)(*(_DWORD *)(v25 + 4 * (v23 >> 6)) + 12 * (v23 & 0x3F));
          v27 = *(_DWORD *)(v25 + 4 * ((v24 - 1) >> 6));
          v4 = dstShape;
          GStroker::calcJoin(
            (GStroker *)this,
            (struct GCompoundShape *)dstShape,
            dstShape_4: (const struct GStrokeVertexType *)(v27 + 12 * ((v24 - 1) & 0x3F)),
            dx2: (const struct GStrokeVertexType *)v44,
            minLen: v38,
            dy1: *(float *)(v26 + 12 * (v52 & 0x3F) + 8),
            dx1: v44[2]);
          v20 = *(_DWORD *)(this + 24);
          v21 = v50;
        }
        while ( v50 < v20 - 1 );
      }
      v28 = *(_DWORD *)(this + 24);
      GStroker::calcCap(
        (float *)this,
        a2: (int)v4,
        a3: (float *)(*(_DWORD *)(*(_DWORD *)(this + 36) + 4 * ((unsigned int)(v28 - 1) >> 6))
                + 12 * (((_BYTE)v28 - 1) & 0x3F)),
        a4: (float *)(*(_DWORD *)(*(_DWORD *)(this + 36) + 4 * ((unsigned int)(v28 - 2) >> 6)) + 12 * ((v28 - 2) & 0x3F)),
        a5: *(float *)(*(_DWORD *)(*(_DWORD *)(this + 36) + 4 * ((unsigned int)(v28 - 2) >> 6))
                 + 12 * (((_BYTE)v28 - 2) & 0x3F)
                 + 8),
        a6: *(_DWORD *)(this + 16));
      v29 = *(_DWORD *)(this + 24) - 2;
      if ( *(_DWORD *)(this + 24) != 2 )
      {
        do
        {
          v30 = v29;
          if ( v29 == 0 )
            v30 = *(_DWORD *)(this + 24);
          v45 = v30 - 1;
          v31 = v29;
          if ( v29 == 0 )
            v31 = *(_DWORD *)(this + 24);
          v32 = *(_DWORD *)(this + 24);
          v48 = v31 - 1;
          v33 = v29 + 1;
          if ( v29 + 1 >= v32 )
            v33 -= v32;
          v34 = *(_DWORD *)(this + 36);
          v53 = (float *)(*(_DWORD *)(v34 + 4 * (v29 >> 6)) + 12 * (v29 & 0x3F));
          v41 = *(float *)(*(_DWORD *)(v34 + 4 * (v45 >> 6)) + 12 * (v45 & 0x3F) + 8);
          v39 = (const struct GStrokeVertexType *)(*(_DWORD *)(v34 + 4 * (v48 >> 6)) + 12 * (v48 & 0x3F));
          v35 = *(_DWORD *)(v34 + 4 * (v33 >> 6));
          v4 = dstShape;
          GStroker::calcJoin(
            (GStroker *)this,
            (struct GCompoundShape *)dstShape,
            dstShape_4: (const struct GStrokeVertexType *)(v35 + 12 * (v33 & 0x3F)),
            dx2: (const struct GStrokeVertexType *)v53,
            minLen: v39,
            dy1: v53[2],
            dx1: v41);
          --v29;
        }
        while ( v29 != 0 );
      }
      goto LABEL_40;
    }
    if ( LOBYTE(bothSides) != 0 || *(float *)this > 0.0 )
    {
      GCompoundShape::BeginPath(this: dstShape, lStyle: 0, rStyle: -1, a4: -1);
      v5 = *(_DWORD *)(this + 24);
      v6 = 0;
      if ( v5 != 0 )
      {
        do
        {
          v7 = v6;
          if ( v6 == 0 )
            v7 = v5;
          v8 = v6 + 1;
          v46 = v7 - 1;
          v49 = v6 + 1;
          if ( v6 + 1 >= v5 )
            v8 -= v5;
          v9 = v6;
          if ( v6 == 0 )
            v9 = v5;
          v10 = *(_DWORD *)(this + 36);
          v42 = (float *)(*(_DWORD *)(v10 + 4 * (v6 >> 6)) + 12 * (v6 & 0x3F));
          v11 = *(_DWORD *)(v10 + 4 * (v46 >> 6));
          v36 = (const struct GStrokeVertexType *)(*(_DWORD *)(v10 + 4 * (v8 >> 6)) + 12 * (v8 & 0x3F));
          v12 = *(_DWORD *)(v10 + 4 * ((v9 - 1) >> 6));
          v4 = dstShape;
          GStroker::calcJoin(
            (GStroker *)this,
            (struct GCompoundShape *)dstShape,
            dstShape_4: (const struct GStrokeVertexType *)(v12 + 12 * ((v9 - 1) & 0x3F)),
            dx2: (const struct GStrokeVertexType *)v42,
            minLen: v36,
            dy1: *(float *)(v11 + 12 * (v46 & 0x3F) + 8),
            dx1: v42[2]);
          v6 = v49;
          v5 = *(_DWORD *)(this + 24);
        }
        while ( v49 < v5 );
      }
      GCompoundShape::ClosePath(this: v4);
      if ( LOBYTE(bothSides) != 0 )
        goto LABEL_15;
    }
    if ( *(float *)this < 0.0 )
    {
LABEL_15:
      GCompoundShape::BeginPath(this: v4, lStyle: 0, rStyle: -1, a4: -1);
      for ( i = *(_DWORD *)(this + 24) - 1; i >= 0; --i )
      {
        v14 = i;
        if ( i == 0 )
          v14 = *(_DWORD *)(this + 24);
        v43 = v14 - 1;
        v15 = i;
        if ( i == 0 )
          v15 = *(_DWORD *)(this + 24);
        v16 = *(_DWORD *)(this + 24);
        v47 = v15 - 1;
        v17 = i + 1;
        if ( i + 1 >= v16 )
          v17 -= v16;
        v18 = *(_DWORD *)(this + 36);
        v51 = (float *)(*(_DWORD *)(v18 + 4 * ((unsigned int)i >> 6)) + 12 * (i & 0x3F));
        v40 = *(float *)(*(_DWORD *)(v18 + 4 * (v43 >> 6)) + 12 * (v43 & 0x3F) + 8);
        v37 = (const struct GStrokeVertexType *)(*(_DWORD *)(v18 + 4 * (v47 >> 6)) + 12 * (v47 & 0x3F));
        v19 = *(_DWORD *)(v18 + 4 * (v17 >> 6));
        v4 = dstShape;
        GStroker::calcJoin(
          (GStroker *)this,
          (struct GCompoundShape *)dstShape,
          dstShape_4: (const struct GStrokeVertexType *)(v19 + 12 * (v17 & 0x3F)),
          dx2: (const struct GStrokeVertexType *)v51,
          minLen: v37,
          dy1: v51[2],
          dx1: v40);
      }
LABEL_40:
      GCompoundShape::ClosePath(this: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1017DB30
// Name: private: void GStroker::generateEquidistant(class GCompoundShape::SPath const __near &,class GCompoundShape __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GStroker::generateEquidistant(
        char *this,
        long double *srcPath,
        GCompoundShape *dstShape,
        int bothSides)
{
  int v4; // ebx
  char *v5; // esi
  long double *v6; // edi
  unsigned int v7; // ecx
  unsigned int v8; // eax
  int v9; // ecx
  double v10; // st7
  int v11; // eax
  int v12; // ecx
  int v13; // edx
  int v14; // edi
  double v15; // st7
  int v16; // ebx
  float *v17; // edi
  unsigned int v18; // ebx
  float *v19; // eax
  long double v20; // [esp-4h] [ebp-2Ch]
  float v21; // [esp+Ch] [ebp-1Ch]
  float v22; // [esp+10h] [ebp-18h]
  int v23; // [esp+18h] [ebp-10h]
  float v24; // [esp+1Ch] [ebp-Ch]
  float v25; // [esp+1Ch] [ebp-Ch]
  float v26; // [esp+1Ch] [ebp-Ch]
  float v27; // [esp+20h] [ebp-8h]
  unsigned int i; // [esp+24h] [ebp-4h]

  v4 = (int)this;
  v5 = this + 24;
  v6 = srcPath;
  v7 = 0;
  *(_DWORD *)v5 = 0;
  v5[16] = 0;
  v23 = v4;
  i = 0;
  if ( *((_DWORD *)srcPath + 1) != 0 )
  {
    do
    {
      v8 = v7 + *((_DWORD *)v6 + 2);
      v9 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v6 + 20) + 4 * (v8 >> 8));
      v10 = *(float *)(v9 + 8 * (unsigned __int8)v8);
      v11 = v9 + 8 * (unsigned __int8)v8;
      v12 = *(_DWORD *)v5;
      v21 = v10;
      v22 = *(float *)(v11 + 4);
      if ( *(_DWORD *)v5 > 1u )
      {
        v13 = *((_DWORD *)v5 + 3);
        v14 = *(_DWORD *)(v13 + 4 * ((unsigned int)(v12 - 1) >> 6));
        v15 = *(float *)(v14 + 12 * ((v12 - 1) & 0x3F));
        v16 = v14 + 12 * ((v12 - 1) & 0x3F);
        v17 = (float *)(*(_DWORD *)(v13 + 4 * ((unsigned int)(v12 - 2) >> 6)) + 12 * (((_BYTE)v12 - 2) & 0x3F));
        v24 = v15 - *v17;
        v27 = *(float *)(v16 + 4) - v17[1];
        v25 = v27 * v27 + v24 * v24;
        v26 = sqrt(v25);
        v17[2] = v26;
        if ( v26 <= 0.00009999999747378752 && *(_DWORD *)v5 != 0 )
          --*(_DWORD *)v5;
        v6 = srcPath;
      }
      v18 = *(_DWORD *)v5 >> 6;
      if ( v18 >= *((_DWORD *)v5 + 1) )
        GArrayPagedBase<GStrokeVertexType,6,16,GAllocatorPagedLH_POD<GStrokeVertexType,135>>::allocatePage(
          this: (unsigned int *)v5,
          nb: *(_DWORD *)v5 >> 6);
      v19 = (float *)(*(_DWORD *)(*((_DWORD *)v5 + 3) + 4 * v18) + 12 * (*(_DWORD *)v5 & 0x3F));
      *v19 = v21;
      v19[1] = v22;
      v19[2] = 0.0;
      ++*(_DWORD *)v5;
      v7 = i + 1;
      i = v7;
    }
    while ( v7 < *((_DWORD *)v6 + 1) );
    v4 = v23;
  }
  GStrokePath::ClosePath(this: (GStrokePath *)v5, a2: (_BYTE)bothSides == 0);
  LODWORD(v20) = bothSides;
  GStroker::generateEquidistant(this: v4, dstShape, bothSides: v20);
}

//------------------------------------------------------------------------------
// Address: 0x1017DC80
// Name: private: void GStroker::generateEquidistant(class GCompoundShape const __near &,int,class GCompoundShape __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GStroker::generateEquidistant(
        _FPIEEE_RECORD *this@<ecx>,
        unsigned int *srcShape,
        int srcStyle,
        GCompoundShape *dstShape,
        long double *bothSides,
        long double *j)
{
  unsigned int *v7; // ecx
  unsigned int *v8; // esi
  unsigned int v9; // eax
  _DWORD *v10; // edi
  float *v11; // ecx
  int v12; // edx
  int v13; // eax
  unsigned int v14; // ecx
  unsigned int v15; // eax
  int v16; // ecx
  double v17; // st7
  int v18; // eax
  unsigned int v19; // ecx
  unsigned int v20; // ebx
  int v21; // edx
  float *v22; // ebx
  unsigned int v23; // ebx
  float *v24; // eax
  unsigned int v25; // ecx
  unsigned int v26; // eax
  int v27; // ecx
  double v28; // st7
  int v29; // eax
  unsigned int v30; // ecx
  unsigned int v31; // ebx
  int v32; // edx
  float *v33; // ebx
  unsigned int v34; // ebx
  float *v35; // eax
  long double v36; // [esp-4h] [ebp-44h]
  float v37; // [esp+Ch] [ebp-34h]
  float v38; // [esp+10h] [ebp-30h]
  float v39; // [esp+18h] [ebp-28h]
  float v40; // [esp+1Ch] [ebp-24h]
  float v41; // [esp+2Ch] [ebp-14h]
  float v42; // [esp+2Ch] [ebp-14h]
  float v43; // [esp+2Ch] [ebp-14h]
  float v44; // [esp+2Ch] [ebp-14h]
  float v45; // [esp+2Ch] [ebp-14h]
  float v46; // [esp+2Ch] [ebp-14h]
  float v47; // [esp+30h] [ebp-10h]
  float v48; // [esp+30h] [ebp-10h]
  float v49; // [esp+30h] [ebp-10h]
  float v50; // [esp+30h] [ebp-10h]
  float v51; // [esp+30h] [ebp-10h]
  unsigned int i; // [esp+34h] [ebp-Ch]
  _FPIEEE_RECORD *v53; // [esp+38h] [ebp-8h]
  float jc; // [esp+3Ch] [ebp-4h]
  unsigned int ja; // [esp+3Ch] [ebp-4h]
  unsigned int jb; // [esp+3Ch] [ebp-4h]

  v7 = srcShape;
  v8 = &this->Operand1.Value.Fp128Value.W[2];
  v9 = 0;
  this->Operand1.Value.Fp128Value.W[2] = 0;
  *((_BYTE *)&this->Operand1 + 24) = 0;
  v53 = this;
  i = 0;
  if ( srcShape[6] == 0 )
    goto LABEL_27;
  do
  {
    v10 = (_DWORD *)(*(_DWORD *)(v7[9] + 4 * (v9 >> 6)) + 24 * (v9 & 0x3F));
    if ( srcStyle >= 0 && v10[5] != srcStyle || v10[1] == 0 )
      goto LABEL_25;
    if ( *v8 != 0 )
    {
      v11 = (float *)(*(_DWORD *)(*((_DWORD *)&v53->Operand1 + 5) + 4 * ((*v8 - 1) >> 6)) + 12 * ((*v8 - 1) & 0x3F));
      v12 = *(_DWORD *)(*(_DWORD *)(*v10 + 20) + 4 * (v10[2] >> 8));
      v13 = (unsigned __int8)v10[2];
      v47 = *(float *)(v12 + 8 * v13) - *v11;
      jc = *(float *)(v12 + 8 * v13 + 4) - v11[1];
      v48 = jc * jc + v47 * v47;
      v49 = sqrt(v48);
      if ( v49 <= 0.00009999999747378752 )
      {
        v14 = 1;
        for ( ja = 1; v14 < v10[1]; ja = v14 )
        {
          v15 = v14 + v10[2];
          v16 = *(_DWORD *)(*(_DWORD *)(*v10 + 20) + 4 * (v15 >> 8));
          v17 = *(float *)(v16 + 8 * (unsigned __int8)v15);
          v18 = v16 + 8 * (unsigned __int8)v15;
          v19 = *v8;
          v40 = *(float *)(v18 + 4);
          if ( *v8 > 1 )
          {
            v20 = v8[3];
            v21 = *(_DWORD *)(v20 + 4 * ((v19 - 1) >> 6));
            v22 = (float *)(*(_DWORD *)(v20 + 4 * ((v19 - 2) >> 6)) + 12 * (((_BYTE)v19 - 2) & 0x3F));
            v41 = *(float *)(v21 + 12 * ((v19 - 1) & 0x3F)) - *v22;
            v50 = *(float *)(v21 + 12 * ((v19 - 1) & 0x3F) + 4) - v22[1];
            v42 = v50 * v50 + v41 * v41;
            v43 = sqrt(v42);
            v22[2] = v43;
            if ( v43 <= 0.00009999999747378752 && *v8 != 0 )
              --*v8;
          }
          v23 = *v8 >> 6;
          if ( v23 >= v8[1] )
            GArrayPagedBase<GStrokeVertexType,6,16,GAllocatorPagedLH_POD<GStrokeVertexType,135>>::allocatePage(
              this: v8,
              nb: *v8 >> 6);
          v24 = (float *)(*(_DWORD *)(v8[3] + 4 * v23) + 12 * (*v8 & 0x3F));
          v39 = v17;
          *v24 = v39;
          v24[1] = v40;
          v24[2] = 0.0;
          ++*v8;
          v14 = ja + 1;
        }
        goto LABEL_25;
      }
      GStrokePath::ClosePath(this: (GStrokePath *)v8, a2: (_BYTE)bothSides == 0);
      LODWORD(v36) = bothSides;
      GStroker::generateEquidistant(this: (int)v53, dstShape, bothSides: v36);
      *v8 = 0;
      *((_BYTE *)v8 + 16) = 0;
    }
    v25 = 0;
    for ( jb = 0; v25 < v10[1]; jb = v25 )
    {
      v26 = v25 + v10[2];
      v27 = *(_DWORD *)(*(_DWORD *)(*v10 + 20) + 4 * (v26 >> 8));
      v28 = *(float *)(v27 + 8 * (unsigned __int8)v26);
      v29 = v27 + 8 * (unsigned __int8)v26;
      v30 = *v8;
      v38 = *(float *)(v29 + 4);
      if ( *v8 > 1 )
      {
        v31 = v8[3];
        v32 = *(_DWORD *)(v31 + 4 * ((v30 - 1) >> 6));
        v33 = (float *)(*(_DWORD *)(v31 + 4 * ((v30 - 2) >> 6)) + 12 * (((_BYTE)v30 - 2) & 0x3F));
        v51 = *(float *)(v32 + 12 * ((v30 - 1) & 0x3F)) - *v33;
        v44 = *(float *)(v32 + 12 * ((v30 - 1) & 0x3F) + 4) - v33[1];
        v45 = v44 * v44 + v51 * v51;
        v46 = sqrt(v45);
        v33[2] = v46;
        if ( v46 <= 0.00009999999747378752 && *v8 != 0 )
          --*v8;
      }
      v34 = *v8 >> 6;
      if ( v34 >= v8[1] )
        GArrayPagedBase<GStrokeVertexType,6,16,GAllocatorPagedLH_POD<GStrokeVertexType,135>>::allocatePage(
          this: v8,
          nb: *v8 >> 6);
      v35 = (float *)(*(_DWORD *)(v8[3] + 4 * v34) + 12 * (*v8 & 0x3F));
      v37 = v28;
      *v35 = v37;
      v35[1] = v38;
      v35[2] = 0.0;
      ++*v8;
      v25 = jb + 1;
    }
LABEL_25:
    v7 = srcShape;
    v9 = i + 1;
    i = v9;
  }
  while ( v9 < srcShape[6] );
  this = v53;
LABEL_27:
  if ( *v8 > 1 )
  {
    GStrokePath::ClosePath(this: (GStrokePath *)v8, a2: (_BYTE)bothSides == 0);
    LODWORD(v36) = bothSides;
    GStroker::generateEquidistant((int)this, dstShape, bothSides: v36);
  }
}
