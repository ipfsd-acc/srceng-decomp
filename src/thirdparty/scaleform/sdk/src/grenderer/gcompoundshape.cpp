// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/grenderer/gcompoundshape.cpp
// Functions: 14
// ============================================================

#include "thirdparty\scaleform\sdk\src\grenderer\gcompoundshape.h"

//------------------------------------------------------------------------------
// Address: 0x10182850
// Name: public: void GCompoundShape::SetCurveTolerance(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCompoundShape::SetCurveTolerance(long double *this, char *t)
{
  float ta; // [esp+8h] [ebp+8h]

  *(float *)this = *(float *)&t;
  ta = *(float *)&t * 0.25;
  *((float *)this + 1) = ta * ta;
}

//------------------------------------------------------------------------------
// Address: 0x10182870
// Name: public: void GCompoundShape::PerceiveBounds(float __near *,float __near *,float __near *,float __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCompoundShape::PerceiveBounds(int *this, _iobuf *x1, float *y1, float *x2, float *y2)
{
  unsigned int v6; // esi
  int v7; // edx
  char *x1a; // [esp+10h] [ebp+8h]
  float x1b; // [esp+10h] [ebp+8h]

  *(float *)&x1->_ptr = 1.0;
  *y1 = 1.0;
  *x2 = 0.0;
  *y2 = 0.0;
  if ( *(this + 2) != 0 )
  {
    x1a = **(char ***)*(this + 5);
    *x2 = *(float *)&x1a;
    x1->_ptr = x1a;
    x1b = *(float *)(*(_DWORD *)*(this + 5) + 4);
    *y2 = x1b;
    v6 = 1;
    for ( *y1 = x1b; v6 < *(this + 2); ++v6 )
    {
      v7 = *(_DWORD *)(*(this + 5) + 4 * (v6 >> 8)) + 8 * (unsigned __int8)v6;
      if ( *(float *)&x1->_ptr > (double)*(float *)v7 )
        x1->_ptr = *(char **)v7;
      if ( *y1 > (double)*(float *)(v7 + 4) )
        *y1 = *(float *)(v7 + 4);
      if ( *x2 < (double)*(float *)v7 )
        *x2 = *(float *)v7;
      if ( *y2 < (double)*(float *)(v7 + 4) )
        *y2 = *(float *)(v7 + 4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10182940
// Name: public: void GCompoundShape::ScaleAndTranslate(float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCompoundShape::ScaleAndTranslate(GCompoundShape *this, float a2, float a3, float a4, float a5)
{
  unsigned int v5; // edx
  double v6; // st7
  int v7; // eax
  double v8; // st3
  float *v9; // eax
  float v10; // [esp+14h] [ebp+14h]
  float v11; // [esp+14h] [ebp+14h]

  v5 = 0;
  if ( *((_DWORD *)this + 2) != 0 )
  {
    v6 = a5;
    do
    {
      v7 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * (v5 >> 8));
      v8 = *(float *)(v7 + 8 * (unsigned __int8)v5);
      v9 = (float *)(v7 + 8 * (unsigned __int8)v5++);
      v10 = v8 * a2;
      *v9 = v10 + a4;
      v11 = v9[1] * a3;
      v9[1] = v11 + v6;
    }
    while ( v5 < *((_DWORD *)this + 2) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101829B0
// Name: public: void GCompoundShape::RemoveShortSegments(float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge GCompoundShape::RemoveShortSegments(
        long double *this@<ecx>,
        char *maxLen,
        unsigned int j,
        int i,
        int start,
        int num,
        localeinfo_struct *v1)
{
  long double *v7; // edx
  unsigned int v8; // esi
  double v9; // st7
  int v10; // eax
  unsigned int v11; // ecx
  unsigned int v12; // esi
  int v13; // edx
  float v14; // edi
  float v15; // ebx
  unsigned int v16; // ecx
  unsigned int v17; // eax
  unsigned int v18; // esi
  int v19; // eax
  int v20; // edx
  double v21; // st6
  float *v22; // edx
  double v23; // st6
  float *v24; // edx
  double v25; // st6
  float *v26; // edx
  double v27; // st6
  int v28; // edx
  int v29; // eax
  double v30; // st6
  float *v31; // edx
  double v32; // st6
  unsigned int v33; // edx
  int v34; // eax
  double v35; // st6
  float *v36; // edx
  double v37; // st6
  bool v38; // zf
  unsigned int v39; // edx
  int v40; // esi
  int v41; // edi
  float v42; // ecx
  float v43; // edi
  unsigned __int8 v44; // al
  int v45; // edx
  double v46; // st6
  float *v47; // edx
  double v48; // st6
  float v49; // [esp+4h] [ebp-20h]
  float v50; // [esp+8h] [ebp-1Ch]
  unsigned int starta; // [esp+Ch] [ebp-18h]
  float startb; // [esp+Ch] [ebp-18h]
  float startc; // [esp+Ch] [ebp-18h]
  float startd; // [esp+Ch] [ebp-18h]
  float starte; // [esp+Ch] [ebp-18h]
  unsigned int ja; // [esp+10h] [ebp-14h]
  float v57; // [esp+18h] [ebp-Ch]
  float v58; // [esp+18h] [ebp-Ch]
  float v59; // [esp+18h] [ebp-Ch]
  float v60; // [esp+18h] [ebp-Ch]
  float v61; // [esp+18h] [ebp-Ch]
  float v62; // [esp+18h] [ebp-Ch]
  float v63; // [esp+18h] [ebp-Ch]
  float v64; // [esp+18h] [ebp-Ch]
  float v65; // [esp+18h] [ebp-Ch]
  float v66; // [esp+18h] [ebp-Ch]
  float v67; // [esp+18h] [ebp-Ch]
  float v68; // [esp+18h] [ebp-Ch]
  float v69; // [esp+18h] [ebp-Ch]
  float v70; // [esp+18h] [ebp-Ch]
  float v71; // [esp+18h] [ebp-Ch]
  float v72; // [esp+18h] [ebp-Ch]
  unsigned int v73; // [esp+18h] [ebp-Ch]
  unsigned int ia; // [esp+1Ch] [ebp-8h]
  char *maxLena; // [esp+2Ch] [ebp+8h]
  char *maxLenb; // [esp+2Ch] [ebp+8h]
  float maxLenc; // [esp+2Ch] [ebp+8h]
  float maxLend; // [esp+2Ch] [ebp+8h]
  float maxLene; // [esp+2Ch] [ebp+8h]
  float maxLenf; // [esp+2Ch] [ebp+8h]

  v7 = this;
  v8 = 0;
  ia = 0;
  if ( *((_DWORD *)this + 6) != 0 )
  {
    v9 = *(float *)&maxLen;
    do
    {
      v10 = *(_DWORD *)(*((_DWORD *)v7 + 9) + 4 * (v8 >> 6)) + 24 * (v8 & 0x3F);
      v11 = *(_DWORD *)(v10 + 4);
      if ( v11 > 2 )
      {
        v12 = *(_DWORD *)(v10 + 8);
        v13 = *(_DWORD *)(*((_DWORD *)v7 + 5) + 4 * (v12 >> 8));
        v14 = *(float *)(v13 + 8 * (unsigned __int8)v12);
        v15 = *(float *)(v13 + 8 * (unsigned __int8)v12 + 4);
        v16 = v11 - 1;
        v17 = 1;
        starta = v12;
        v49 = v14;
        v50 = v15;
        if ( v16 > 1 )
        {
          if ( (int)(v16 - 1) >= 4 )
          {
            v18 = v12 + 2;
            maxLena = (char *)(((v16 - 5) >> 2) + 1);
            ja = 4 * (_DWORD)maxLena + 1;
            do
            {
              v19 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * ((v18 - 1) >> 8));
              v20 = (unsigned __int8)(v18 - 1);
              v21 = *(float *)(v19 + 8 * v20);
              v22 = (float *)(v19 + 8 * v20);
              v57 = v21 - v49;
              v58 = fabs(v57);
              v23 = v58;
              v59 = v22[1] - v50;
              v60 = fabs(v59);
              if ( v23 + v60 < v9 )
              {
                *v22 = v14;
                v22[1] = v15;
              }
              else
              {
                v14 = *v22;
                v15 = v22[1];
                v49 = *v22;
                v50 = v15;
              }
              v24 = (float *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * (v18 >> 8)) + 8 * (unsigned __int8)v18);
              v61 = *v24 - v49;
              v62 = fabs(v61);
              v25 = v62;
              v63 = v24[1] - v50;
              v64 = fabs(v63);
              if ( v25 + v64 < v9 )
              {
                *v24 = v14;
                v24[1] = v15;
              }
              else
              {
                v14 = *v24;
                v15 = v24[1];
                v49 = *v24;
                v50 = v15;
              }
              v26 = (float *)(*(_DWORD *)(*((_DWORD *)this + 5) + 4 * ((v18 + 1) >> 8)) + 8 * (unsigned __int8)(v18 + 1));
              v65 = *v26 - v49;
              v66 = fabs(v65);
              v27 = v66;
              v67 = v26[1] - v50;
              v68 = fabs(v67);
              if ( v27 + v68 < v9 )
              {
                *v26 = v14;
                v26[1] = v15;
              }
              else
              {
                v14 = *v26;
                v15 = v26[1];
                v49 = *v26;
                v50 = v15;
              }
              v28 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * ((v18 + 2) >> 8));
              v29 = (unsigned __int8)(v18 + 2);
              v30 = *(float *)(v28 + 8 * v29);
              v31 = (float *)(v28 + 8 * v29);
              v69 = v30 - v49;
              v70 = fabs(v69);
              v32 = v70;
              v71 = v31[1] - v50;
              v72 = fabs(v71);
              if ( v32 + v72 < v9 )
              {
                *v31 = v14;
                v31[1] = v15;
              }
              else
              {
                v14 = *v31;
                v15 = v31[1];
                v49 = *v31;
                v50 = v15;
              }
              v18 += 4;
              --maxLena;
            }
            while ( maxLena != nullptr );
            v17 = ja;
            v12 = starta;
          }
          if ( v17 < v16 )
          {
            v33 = v17 + v12;
            maxLenb = (char *)(v17 + v12);
            v73 = v16 - v17;
            do
            {
              v34 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * (v33 >> 8));
              v35 = *(float *)(v34 + 8 * (unsigned __int8)v33);
              v36 = (float *)(v34 + 8 * (unsigned __int8)v33);
              startb = v35 - v49;
              startc = fabs(startb);
              v37 = startc;
              startd = v36[1] - v50;
              starte = fabs(startd);
              if ( v37 + starte < v9 )
              {
                *v36 = v14;
                v36[1] = v15;
              }
              else
              {
                v14 = *v36;
                v15 = v36[1];
                v49 = *v36;
                v50 = v15;
              }
              v33 = (unsigned int)(maxLenb + 1);
              v38 = v73-- == 1;
              ++maxLenb;
            }
            while ( !v38 );
          }
        }
        v39 = v16 + v12;
        v40 = *((_DWORD *)this + 5);
        v41 = *(_DWORD *)(v40 + 4 * (v39 >> 8));
        v42 = *(float *)(v41 + 8 * (unsigned __int8)v39);
        v43 = *(float *)(v41 + 8 * (unsigned __int8)v39 + 4);
        v44 = v39 - 1;
        v45 = *(_DWORD *)(v40 + 4 * ((v39 - 1) >> 8));
        v46 = *(float *)(v45 + 8 * v44);
        v47 = (float *)(v45 + 8 * v44);
        v8 = ia;
        maxLenc = v46 - v42;
        maxLend = fabs(maxLenc);
        v48 = maxLend;
        maxLene = v47[1] - v43;
        maxLenf = fabs(maxLene);
        if ( v48 + maxLenf < v9 )
        {
          *v47 = v42;
          v47[1] = v43;
        }
        v7 = this;
      }
      ia = ++v8;
    }
    while ( v8 < *((_DWORD *)v7 + 6) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10182D60
// Name: public: void GCompoundShape::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCompoundShape::Clear(GCompoundShape *this)
{
  *((float *)this + 13) = 1.0;
  *((_DWORD *)this + 2) = 0;
  *((float *)this + 14) = 1.0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 10) = 0;
  *((float *)this + 15) = 0.0;
  *((_DWORD *)this + 11) = 0x7FFFFFFF;
  *((float *)this + 16) = 0.0;
  *((_DWORD *)this + 12) = -2147483647;
}

//------------------------------------------------------------------------------
// Address: 0x10182D90
// Name: public: void GCompoundShape::ClearAndRelease(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCompoundShape::ClearAndRelease(GCompoundShape *this)
{
  int *v2; // ecx
  int *v3; // esi

  *((float *)this + 13) = 1.0;
  *((float *)this + 14) = 1.0;
  v2 = (int *)(this + 2);
  v3 = (int *)(this + 6);
  *((float *)this + 15) = 0.0;
  *v2 = 0;
  *((float *)this + 16) = 0.0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0x7FFFFFFF;
  *((_DWORD *)this + 12) = -2147483647;
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: v2);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x10182DE0
// Name: public: unsigned int GCompoundShape::GetNumBytes(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GCompoundShape::GetNumBytes(GCompoundShape *this)
{
  return 4
       * (*((_DWORD *)this + 4) + *((_DWORD *)this + 8) + 384 * *((_DWORD *)this + 7) + (*((_DWORD *)this + 3) << 9));
}

//------------------------------------------------------------------------------
// Address: 0x10182E00
// Name: public: static void GCompoundShape::ExpandPathBounds(class GCompoundShape::SPath const __near &,float __near *,float __near *,float __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl GCompoundShape::ExpandPathBounds(
        const struct GCompoundShape::SPath *a1,
        float *a2,
        float *a3,
        float *a4,
        float *a5)
{
  unsigned int i; // esi
  int v6; // ecx
  int v7; // eax
  double v8; // st7
  float *v9; // ecx

  for ( i = 0; i < *((_DWORD *)a1 + 1); ++i )
  {
    v6 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)a1 + 20) + 4 * ((i + *((_DWORD *)a1 + 2)) >> 8));
    v7 = (unsigned __int8)(i + *((_BYTE *)a1 + 8));
    v8 = *(float *)(v6 + 8 * v7);
    v9 = (float *)(v6 + 8 * v7);
    if ( *a2 > v8 )
      *a2 = *v9;
    if ( *a3 > (double)v9[1] )
      *a3 = v9[1];
    if ( *a4 < (double)*v9 )
      *a4 = *v9;
    if ( *a5 < (double)v9[1] )
      *a5 = v9[1];
  }
}

//------------------------------------------------------------------------------
// Address: 0x10182E90
// Name: public: bool GCompoundShape::PointInShape(float,float,bool)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCompoundShape::PointInShape(unsigned int *this, _iobuf *x, int *y, bool nonZero)
{
  unsigned int v4; // esi
  unsigned int v5; // edi
  double v6; // st7
  double v7; // st6
  _DWORD *v8; // eax
  unsigned int v9; // ecx
  int v10; // ebx
  unsigned int v11; // esi
  int v12; // edx
  int v13; // ecx
  float v14; // eax
  float *v15; // ecx
  double v16; // st4
  float *v17; // edx
  double v18; // st3
  int v19; // edi
  double v20; // rt0
  double v21; // st3
  double v22; // st7
  double v23; // st4
  float v24; // [esp+8h] [ebp-28h]
  float v25; // [esp+10h] [ebp-20h]
  unsigned int v26; // [esp+18h] [ebp-18h]
  float v27; // [esp+1Ch] [ebp-14h]
  int v28; // [esp+20h] [ebp-10h]
  unsigned int i; // [esp+24h] [ebp-Ch]
  unsigned int v30; // [esp+28h] [ebp-8h]
  int styleCount; // [esp+2Ch] [ebp-4h]
  int ls; // [esp+38h] [ebp+8h]
  int rs; // [esp+3Ch] [ebp+Ch]

  v4 = 0;
  v5 = *(this + 6);
  styleCount = 0;
  i = 0;
  v26 = v5;
  if ( v5 != 0 )
  {
    v6 = *(float *)&y;
    v7 = *(float *)&x;
    v28 = *(this + 9);
    do
    {
      v8 = (_DWORD *)(*(_DWORD *)(v28 + 4 * (v4 >> 6)) + 24 * (v4 & 0x3F));
      ls = v8[3];
      rs = v8[4];
      if ( ls != rs )
      {
        v9 = v8[1];
        if ( v9 > 1 )
        {
          v10 = *(_DWORD *)(*v8 + 20);
          v11 = v8[2] + 1;
          v30 = v9 - 1;
          do
          {
            v12 = *(_DWORD *)(v10 + 4 * ((v11 - 1) >> 8));
            v13 = (unsigned __int8)(v11 - 1);
            v14 = *(float *)(v12 + 8 * v13);
            v15 = (float *)(v12 + 8 * v13);
            v24 = v14;
            v16 = v15[1];
            v17 = (float *)(*(_DWORD *)(v10 + 4 * (v11 >> 8)) + 8 * (unsigned __int8)v11);
            v25 = *v17;
            v18 = v17[1];
            if ( v18 != v16 )
            {
              v19 = 1;
              if ( v18 < v16 )
              {
                v24 = *v17;
                v16 = v17[1];
                v18 = v15[1];
                v25 = *v15;
                v19 = -1;
              }
              v20 = v18;
              v21 = v6;
              v22 = v20;
              if ( v21 < v16 || v21 >= v22 )
              {
                v6 = v21;
              }
              else
              {
                v23 = (v22 - v16) * (v7 - v25) - (v21 - v22) * (v25 - v24);
                v6 = v21;
                v27 = v23;
                if ( v27 > 0.0 )
                {
                  if ( nonZero )
                  {
                    if ( ls >= 0 )
                      styleCount += v19 * (ls + 1);
                    if ( rs >= 0 )
                      styleCount -= v19 * (rs + 1);
                  }
                  else
                  {
                    if ( ls >= 0 )
                      styleCount ^= 1u;
                    if ( rs >= 0 )
                      styleCount ^= 1u;
                  }
                }
              }
            }
            ++v11;
            --v30;
          }
          while ( v30 != 0 );
          v5 = v26;
          v4 = i;
        }
      }
      i = ++v4;
    }
    while ( v4 < v5 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10183050
// Name: public: void GCompoundShape::BeginPath(int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GCompoundShape::BeginPath(GCompoundShape *this, int lStyle, int rStyle, int lineStyle)
{
  unsigned int v5; // ebx
  _DWORD *v6; // eax
  int result; // eax
  int v8; // [esp+14h] [ebp-10h]

  v5 = *((_DWORD *)this + 6) >> 6;
  v8 = *((_DWORD *)this + 2);
  if ( v5 >= *((_DWORD *)this + 7) )
    GArrayPagedBase<GCompoundShape::SPath,6,16,GAllocatorPagedLH_POD<GCompoundShape::SPath,138>>::allocatePage(
      this: (unsigned int *)this + 6,
      a2: v5);
  v6 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 9) + 4 * v5) + 24 * (*(this + 6) & 0x3F));
  *v6 = this;
  v6[1] = 0;
  v6[2] = v8;
  v6[3] = lStyle;
  v6[4] = rStyle;
  v6[5] = lineStyle;
  ++*((_DWORD *)this + 6);
  result = *(_DWORD *)(*((_DWORD *)this + 9) + 4 * ((unsigned int)(*((_DWORD *)this + 6) - 1) >> 6))
         + 24 * ((*((_DWORD *)this + 6) - 1) & 0x3F);
  *((_DWORD *)this + 10) = result;
  if ( lStyle >= 0 )
  {
    if ( lStyle < *((_DWORD *)this + 11) )
      *((_DWORD *)this + 11) = lStyle;
    if ( lStyle > *((_DWORD *)this + 12) )
      *((_DWORD *)this + 12) = lStyle;
  }
  if ( rStyle >= 0 )
  {
    if ( rStyle < *((_DWORD *)this + 11) )
      *((_DWORD *)this + 11) = rStyle;
    if ( rStyle > *((_DWORD *)this + 12) )
      *((_DWORD *)this + 12) = rStyle;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10183100
// Name: public: void GCompoundShape::BeginPath(int,int,int,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCompoundShape::BeginPath(
        char *this,
        localeinfo_struct *lStyle,
        int rStyle,
        int lineStyle,
        int x,
        int y)
{
  unsigned int v7; // edi
  int v8; // ecx
  int v9; // eax

  GCompoundShape::BeginPath((GCompoundShape *)this, (int)lStyle, rStyle, lineStyle);
  v7 = *((_DWORD *)this + 2) >> 8;
  if ( v7 >= *((_DWORD *)this + 3) )
    GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(
      this: (unsigned int *)this + 2,
      a2: v7);
  v8 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v7);
  v9 = (unsigned __int8)*((_DWORD *)this + 2);
  *(_DWORD *)(v8 + 8 * v9) = x;
  *(_DWORD *)(v8 + 8 * v9 + 4) = y;
  ++*((_DWORD *)this + 2);
  ++*(_DWORD *)(*((_DWORD *)this + 10) + 4);
}

//------------------------------------------------------------------------------
// Address: 0x10183170
// Name: public: void GCompoundShape::ClosePath(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCompoundShape::ClosePath(GCompoundShape *this)
{
  _DWORD *v2; // ecx
  int v3; // edx
  int v4; // eax
  unsigned int v5; // edi
  int v6; // edi
  int v7; // eax
  float v8; // [esp+4h] [ebp-8h]
  float v9; // [esp+8h] [ebp-4h]

  v2 = *((_DWORD **)this + 10);
  if ( v2 != nullptr && v2[1] > 1u )
  {
    v3 = *(_DWORD *)(*(_DWORD *)(*v2 + 20) + 4 * (v2[2] >> 8));
    v4 = (unsigned __int8)v2[2];
    v8 = *(float *)(v3 + 8 * v4);
    v9 = *(float *)(v3 + 8 * v4 + 4);
    v5 = *((_DWORD *)this + 2) >> 8;
    if ( v5 >= *((_DWORD *)this + 3) )
      GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(
        this: (unsigned int *)this + 2,
        a2: v5);
    v6 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v5);
    v7 = (unsigned __int8)*((_DWORD *)this + 2);
    *(float *)(v6 + 8 * v7) = v8;
    *(float *)(v6 + 8 * v7 + 4) = v9;
    ++*((_DWORD *)this + 2);
    ++*(_DWORD *)(*((_DWORD *)this + 10) + 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101831F0
// Name: private: void GCompoundShape::flattenQuadraticCurve(float,float,float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GCompoundShape::flattenQuadraticCurve(
        int this,
        float x1,
        float y1,
        float d,
        float y2,
        float x3,
        float y3)
{
  double v8; // st7
  double v9; // st3
  double v10; // st5
  double v11; // st6
  double v12; // st4
  double v13; // st2
  double v14; // st7
  double v15; // st6
  double v16; // st4
  double v17; // st6
  double v18; // st5
  double v19; // rt1
  double v20; // st7
  unsigned int v21; // ebx
  int v22; // ecx
  int result; // eax
  float v24; // [esp+24h] [ebp-1Ch]
  float y12; // [esp+28h] [ebp-18h]
  float y12a; // [esp+28h] [ebp-18h]
  float x12; // [esp+2Ch] [ebp-14h]
  float y123a; // [esp+30h] [ebp-10h]
  float y123b; // [esp+30h] [ebp-10h]
  float y123; // [esp+30h] [ebp-10h]
  float dya; // [esp+34h] [ebp-Ch]
  float dyb; // [esp+34h] [ebp-Ch]
  float dy; // [esp+34h] [ebp-Ch]
  float y23; // [esp+38h] [ebp-8h]
  float x23; // [esp+3Ch] [ebp-4h]
  float db; // [esp+50h] [ebp+10h]
  float dc; // [esp+50h] [ebp+10h]
  float dd; // [esp+50h] [ebp+10h]
  float de; // [esp+50h] [ebp+10h]
  float da; // [esp+50h] [ebp+10h]
  float y2a; // [esp+54h] [ebp+14h]

  v8 = 0.5;
  x12 = (x1 + d) * 0.5;
  y12 = (y1 + y2) * 0.5;
  v9 = x3;
  x23 = (d + x3) * 0.5;
  y23 = (y2 + y3) * 0.5;
  y123a = x3 - x1;
  v10 = y3;
  dya = y3 - y1;
  v11 = y123a;
  v12 = dya;
  db = (d - x3) * dya - (y2 - y3) * y123a;
  dc = fabs(db);
  v13 = dc;
  if ( dc > 0.00009999999747378752 )
  {
    while ( 1 )
    {
      v16 = (v12 * v12 + v11 * v11) * *(float *)(this + 4);
      v17 = v9;
      if ( v13 * v13 <= v16 )
        break;
      dyb = (x23 + x12) * v8;
      y123b = v8 * (y23 + y12);
      GCompoundShape::flattenQuadraticCurve();
      y2a = y23;
      dd = x23;
      v18 = y123b;
      x12 = (dyb + x23) * 0.5;
      y12 = (y123b + y23) * 0.5;
      x23 = (x23 + x3) * 0.5;
      y23 = (y23 + y3) * 0.5;
      y123 = x3 - dyb;
      dy = y3 - v18;
      de = (dd - x3) * dy - (y2a - y3) * y123;
      da = fabs(de);
      if ( da <= 0.00009999999747378752 )
      {
        v15 = y3;
        v14 = x3;
        goto LABEL_7;
      }
      v8 = 0.5;
      v11 = y123;
      v13 = da;
      v10 = y3;
      v12 = dy;
      v9 = x3;
    }
    v20 = v10;
  }
  else
  {
    v14 = x3;
    v15 = y3;
LABEL_7:
    v19 = v15;
    v17 = v14;
    v20 = v19;
  }
  v21 = *(_DWORD *)(this + 8) >> 8;
  if ( v21 >= *(_DWORD *)(this + 12) )
    GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(
      this: (unsigned int *)(this + 8),
      a2: v21);
  v22 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * v21);
  result = (unsigned __int8)*(_DWORD *)(this + 8);
  v24 = v17;
  *(float *)(v22 + 8 * result) = v24;
  y12a = v20;
  *(float *)(v22 + 8 * result + 4) = y12a;
  ++*(_DWORD *)(this + 8);
  ++*(_DWORD *)(*(_DWORD *)(this + 40) + 4);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10183430
// Name: public: void GCompoundShape::AddCurve(float,float,float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GCompoundShape::AddCurve(GCompoundShape *this, float a2, float a3, float a4, float a5)
{
  double v5; // st7
  unsigned int v7; // eax
  int v8; // ecx
  double v9; // st3
  float *v10; // ecx
  double v11; // st3
  unsigned int v12; // ebx
  int v13; // ecx
  int v14; // eax
  float v15; // [esp+10h] [ebp-18h]
  float v16; // [esp+20h] [ebp-8h]
  float v17; // [esp+38h] [ebp+10h]
  float v18; // [esp+38h] [ebp+10h]

  v5 = a4;
  v7 = *((_DWORD *)this + 2) - 1;
  v8 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * (v7 >> 8));
  v9 = a3 - *(float *)(v8 + 8 * (unsigned __int8)v7 + 4);
  v10 = (float *)(v8 + 8 * (unsigned __int8)v7);
  v17 = (a4 - a2) * v9 - (a2 - *v10) * (a5 - a3);
  v11 = v17;
  if ( v17 < 0.0 )
    v11 = -v11;
  v18 = v11;
  if ( v18 >= 0.00009999999747378752 )
  {
    v15 = v5;
    GCompoundShape::flattenQuadraticCurve((int)this, x1: *v10, y1: v10[1], d: a2, y2: a3, x3: v15, y3: a5);
  }
  else
  {
    v12 = *((_DWORD *)this + 2) >> 8;
    if ( v12 >= *((_DWORD *)this + 3) )
      GArrayPagedBase<GPointType,8,64,GAllocatorPagedLH_POD<GPointType,138>>::allocatePage(
        this: (unsigned int *)this + 2,
        a2: v12);
    v13 = *(_DWORD *)(*((_DWORD *)this + 5) + 4 * v12);
    v14 = (unsigned __int8)*((_DWORD *)this + 2);
    v16 = v5;
    *(float *)(v13 + 8 * v14) = v16;
    *(float *)(v13 + 8 * v14 + 4) = a5;
    ++*((_DWORD *)this + 2);
    ++*(_DWORD *)(*((_DWORD *)this + 10) + 4);
  }
}
