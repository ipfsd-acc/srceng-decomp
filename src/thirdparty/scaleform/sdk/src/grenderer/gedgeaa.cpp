// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/grenderer/gedgeaa.cpp
// Functions: 15
// ============================================================

#include "thirdparty\scaleform\sdk\src\grenderer\gedgeaa.h"

//------------------------------------------------------------------------------
// Address: 0x101993F0
// Name: public: bool GEdgeAA::TriangleLess::operator()(struct GEdgeAA::TriangleType const __near &,struct GEdgeAA::TriangleType const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GEdgeAA::TriangleLess::operator()(int *this, _DWORD *a2, _DWORD *a3)
{
  int v4; // esi
  int v5; // ecx
  int v7; // eax
  int v9; // [esp+Ch] [ebp-4h]
  int v10; // [esp+18h] [ebp+8h]
  int v11; // [esp+1Ch] [ebp+Ch]

  v4 = *this;
  v5 = *(_DWORD *)(*this + 12);
  v10 = *(_DWORD *)(*(_DWORD *)(v5 + 4 * (*a2 >> 8)) + 12 * (unsigned __int8)*a2 + 8);
  v9 = *(_DWORD *)(*(_DWORD *)(v5 + 4 * (a2[1] >> 8)) + 12 * (unsigned __int8)a2[1] + 8);
  v11 = *(_DWORD *)(*(_DWORD *)(v5 + 4 * (*a3 >> 8)) + 12 * (unsigned __int8)*a3 + 8);
  v7 = *(_DWORD *)(*(_DWORD *)(v5 + 4 * (a3[1] >> 8)) + 12 * (unsigned __int8)a3[1] + 8);
  if ( v10 != v11 )
    return v10 < v11;
  if ( v9 == v7 )
    return *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v4 + 12) + 4 * (a2[2] >> 8)) + 12 * (unsigned __int8)a2[2] + 8) < *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v4 + 12) + 4 * (a3[2] >> 8)) + 12 * (unsigned __int8)a3[2] + 8);
  return v9 < v7;
}

//------------------------------------------------------------------------------
// Address: 0x101994E0
// Name: private: void GEdgeAA::calcIntersectionPoint(float,float,unsigned int,unsigned int,float __near *,float __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GEdgeAA::calcIntersectionPoint(
        GEdgeAA *this,
        float a2,
        float a3,
        unsigned int a4,
        unsigned int a5,
        float *a6,
        float *a7)
{
  unsigned int v7; // eax
  int v8; // esi
  int v9; // edi
  float *v10; // ecx
  int v11; // edx
  int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // ecx
  float *v15; // ecx
  int v16; // ebx
  int v17; // edx
  int v18; // eax
  float v19; // ecx
  double v20; // st7
  double v21; // st5
  double v22; // st3
  double v23; // st4
  double v24; // st3
  double v25; // st2
  double v27; // st5
  double v29; // st4
  double v30; // st7
  float v31; // [esp+10h] [ebp-68h]
  float v32; // [esp+18h] [ebp-60h]
  float v33; // [esp+1Ch] [ebp-5Ch]
  float v34; // [esp+24h] [ebp-54h]
  float v35; // [esp+28h] [ebp-50h]
  double v36; // [esp+28h] [ebp-50h]
  float v37; // [esp+30h] [ebp-48h]
  float v38; // [esp+34h] [ebp-44h]
  double v39; // [esp+34h] [ebp-44h]
  double v40; // [esp+3Ch] [ebp-3Ch]
  float v41; // [esp+44h] [ebp-34h]
  float v42; // [esp+44h] [ebp-34h]
  float v43; // [esp+44h] [ebp-34h]
  double v44; // [esp+48h] [ebp-30h]
  int v45; // [esp+4Ch] [ebp-2Ch]
  float v46; // [esp+4Ch] [ebp-2Ch]
  float v47; // [esp+50h] [ebp-28h]
  float v48; // [esp+54h] [ebp-24h]
  float v49; // [esp+58h] [ebp-20h]
  float v50; // [esp+5Ch] [ebp-1Ch]
  float v51; // [esp+5Ch] [ebp-1Ch]
  float v52; // [esp+60h] [ebp-18h]
  float v53; // [esp+68h] [ebp-10h]
  float v54; // [esp+74h] [ebp-4h]
  float v55; // [esp+80h] [ebp+8h]
  float v56; // [esp+84h] [ebp+Ch]
  float v57; // [esp+88h] [ebp+10h]
  float v58; // [esp+88h] [ebp+10h]
  float v59; // [esp+88h] [ebp+10h]
  float v60; // [esp+8Ch] [ebp+14h]
  float v61; // [esp+8Ch] [ebp+14h]
  float v62; // [esp+8Ch] [ebp+14h]
  float v63; // [esp+8Ch] [ebp+14h]
  float v64; // [esp+8Ch] [ebp+14h]
  float v65; // [esp+8Ch] [ebp+14h]
  float v66; // [esp+8Ch] [ebp+14h]
  float v67; // [esp+8Ch] [ebp+14h]
  float v68; // [esp+90h] [ebp+18h]
  float v69; // [esp+90h] [ebp+18h]
  float v70; // [esp+90h] [ebp+18h]
  float v71; // [esp+90h] [ebp+18h]
  float v72; // [esp+94h] [ebp+1Ch]

  v45 = *((_DWORD *)this + 18);
  v7 = *(_DWORD *)(*(_DWORD *)(v45 + 4 * (a4 >> 6)) + 4 * (a4 & 0x3F));
  v8 = *((_DWORD *)this + 11);
  v9 = *((_DWORD *)this + 3);
  v10 = (float *)(*(_DWORD *)(v9
                            + 4
                            * (*(_DWORD *)(*(_DWORD *)(v8 + 4 * (v7 >> 10))
                                         + 4 * ((int)(&GEdgeAA::VertexIdx)[v7 & 3] + 15 * (unsigned __int8)(v7 >> 2))) >> 8))
                + 12
                * (unsigned __int8)*(_DWORD *)(*(_DWORD *)(v8 + 4 * (v7 >> 10))
                                             + 4
                                             * ((int)(&GEdgeAA::VertexIdx)[v7 & 3] + 15 * (unsigned __int8)(v7 >> 2))));
  v37 = *v10;
  v38 = v10[1];
  v11 = 3
      * (unsigned __int8)*(_DWORD *)(*(_DWORD *)(v8 + 4 * (v7 >> 10))
                                   + 4 * (dword_102AAAE4[v7 & 3] + 15 * (unsigned __int8)(v7 >> 2)));
  v12 = *(_DWORD *)(v9
                  + 4
                  * (*(_DWORD *)(*(_DWORD *)(v8 + 4 * (v7 >> 10))
                               + 4 * (dword_102AAAE4[v7 & 3] + 15 * (unsigned __int8)(v7 >> 2))) >> 8));
  v32 = *(float *)(v12 + 4 * v11);
  v33 = *(float *)(v12 + 4 * v11 + 4);
  v13 = *(_DWORD *)(*(_DWORD *)(v45 + 4 * (a5 >> 6)) + 4 * (a5 & 0x3F));
  v14 = *(_DWORD *)(*(_DWORD *)(v8 + 4 * (v13 >> 10))
                  + 4 * ((int)(&GEdgeAA::VertexIdx)[v13 & 3] + 15 * (unsigned __int8)(v13 >> 2)));
  v60 = v32 - v37;
  v40 = v33 - v38;
  v15 = (float *)(*(_DWORD *)(v9 + 4 * (v14 >> 8)) + 12 * (unsigned __int8)v14);
  v57 = v40;
  v34 = *v15;
  v35 = v15[1];
  v58 = v57 * v57 + v60 * v60;
  v16 = dword_102AAAE4[v13 & 3] + 15 * (unsigned __int8)(v13 >> 2);
  v17 = 3 * (unsigned __int8)*(_DWORD *)(*(_DWORD *)(v8 + 4 * (v13 >> 10)) + 4 * v16);
  v18 = *(_DWORD *)(v9 + 4 * (*(_DWORD *)(*(_DWORD *)(v8 + 4 * (v13 >> 10)) + 4 * v16) >> 8));
  v19 = *(float *)(v18 + 4 * v17);
  v31 = *(float *)(v18 + 4 * v17 + 4);
  v59 = sqrt(v58);
  v41 = v19 - v34;
  v44 = v31 - v35;
  v61 = v44;
  v62 = v61 * v61 + v41 * v41;
  v63 = sqrt(v62);
  v49 = v63;
  v20 = a2;
  v64 = v40 * a2 / v59;
  v55 = (v37 - v32) * a2 / v59;
  v42 = v20 * v44 / v49;
  v50 = v20 * (v34 - v19) / v49;
  v21 = v64;
  v54 = v37 + v64;
  v65 = v55 + v38;
  v48 = v21 + v32;
  v47 = v55 + v33;
  v22 = v42;
  v46 = v34 + v42;
  v43 = v50 + v35;
  v53 = v22 + v19;
  v52 = v50 + v31;
  v23 = v48 - v54;
  v24 = v52 - v43;
  v36 = v47 - v65;
  v39 = v53 - v46;
  v51 = v24 * v23 - v36 * v39;
  *((float *)&v40 + 1) = fabs(v51);
  v25 = *((float *)&v40 + 1);
  *((float *)&v40 + 1) = (v49 + v59) * 0.009999999776482582;
  if ( *((float *)&v40 + 1) <= v25 )
  {
    v27 = v23;
    v29 = v65;
    v66 = (v65 - v43) * v39 - v24 * (v54 - v46);
    v67 = v66 / v51;
    *a6 = v54 + v27 * v67;
    v68 = v29 + v67 * v36;
    *a7 = v68;
    v72 = v32 - *a6;
    v69 = v33 - v68;
    v70 = v69 * v69 + v72 * v72;
    v71 = sqrt(v70);
    v30 = v59;
    if ( v49 > (double)v59 )
      v30 = v49;
    if ( a3 > v30 )
      a3 = v30;
    if ( v71 > (double)a3 )
    {
      v56 = a3 / v71;
      *a6 = v32 + (*a6 - v32) * v56;
      *a7 = v56 * (*a7 - v33) + v33;
    }
  }
  else
  {
    *a6 = v54 * 0.25 + v48 * 0.25 + v46 * 0.25 + v53 * 0.25;
    *a7 = 0.25 * v52 + v65 * 0.25 + v47 * 0.25 + v43 * 0.25;
    if ( v59 <= (double)v49 )
    {
      *a6 = v46;
      *a7 = v43;
    }
    else
    {
      *a6 = v48;
      *a7 = v47;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10199960
// Name: private: void GEdgeAA::correctCrossIntersection(struct GEdgeAA::VertexType const __near &,struct GEdgeAA::MeshTriType const __near &,unsigned int,struct GEdgeAA::VertexType __near *,float)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GEdgeAA::correctCrossIntersection(
        GEdgeAA *this,
        const struct GEdgeAA::VertexType *a2,
        const struct GEdgeAA::MeshTriType *a3,
        unsigned int a4,
        struct GEdgeAA::VertexType *a5,
        float a6)
{
  int v6; // edx
  float *v7; // ecx
  int v8; // edx
  double v10; // st7
  float *v11; // edx
  double v13; // st6
  double v14; // st7
  double v15; // st5
  double v16; // st4
  double v17; // st3
  double v18; // st2
  double v19; // st2
  double v20; // st2
  double v21; // [esp+8h] [ebp-18h]
  double v22; // [esp+10h] [ebp-10h]
  float v23; // [esp+28h] [ebp+8h]
  float v24; // [esp+28h] [ebp+8h]
  float v25; // [esp+28h] [ebp+8h]
  float v26; // [esp+28h] [ebp+8h]
  float v27; // [esp+28h] [ebp+8h]
  float v28; // [esp+28h] [ebp+8h]
  float v29; // [esp+28h] [ebp+8h]
  float v30; // [esp+28h] [ebp+8h]
  float v31; // [esp+28h] [ebp+8h]
  float v32; // [esp+28h] [ebp+8h]
  float v33; // [esp+2Ch] [ebp+Ch]
  float v34; // [esp+2Ch] [ebp+Ch]
  float v35; // [esp+30h] [ebp+10h]
  float v36; // [esp+30h] [ebp+10h]
  float v37; // [esp+30h] [ebp+10h]
  float v38; // [esp+30h] [ebp+10h]
  float v39; // [esp+30h] [ebp+10h]
  float v40; // [esp+30h] [ebp+10h]
  float v41; // [esp+34h] [ebp+14h]

  v6 = *((_DWORD *)this + 3);
  v7 = (float *)(*(_DWORD *)(v6 + 4 * (*((_DWORD *)a3 + dword_102AAAE4[a4] + 3) >> 8))
               + 12 * (unsigned __int8)*((_DWORD *)a3 + dword_102AAAE4[a4] + 3));
  v8 = *(_DWORD *)(v6 + 4 * (*((_DWORD *)a3 + dword_102AAAE8[a4] + 3) >> 8));
  v10 = *(float *)(v8 + 12 * (unsigned __int8)*((_DWORD *)a3 + dword_102AAAE8[a4] + 3));
  v11 = (float *)(v8 + 12 * (unsigned __int8)*((_DWORD *)a3 + dword_102AAAE8[a4] + 3));
  v35 = (v10 - *v7) * (v7[1] - *((float *)a5 + 1)) - (v11[1] - v7[1]) * (*v7 - *(float *)a5);
  if ( v35 >= -0.1 )
  {
    v33 = *v7;
    v36 = v7[1];
    v13 = *(float *)a2;
    v14 = *(float *)a5 - v13;
    v15 = v11[1] - v36;
    v16 = *((float *)a2 + 1);
    v22 = *((float *)a5 + 1) - v16;
    v21 = *v11 - v33;
    v41 = v15 * v14 - v22 * v21;
    v23 = fabs(v41);
    v17 = v23;
    v24 = *(float *)a2 - *(float *)a5;
    v25 = fabs(v24);
    v18 = v25;
    v26 = *((float *)a2 + 1) - *((float *)a5 + 1);
    v27 = fabs(v26);
    v19 = v18 + v27;
    v28 = v33 - *v11;
    v29 = fabs(v28);
    v20 = v19 + v29;
    v30 = v36 - v11[1];
    v31 = fabs(v30);
    v32 = (v20 + v31) * 0.009999999776482582;
    if ( v32 <= v17 )
    {
      v37 = (v16 - v36) * v21 - v15 * (v13 - v33);
      v38 = v37 / v41;
      v34 = v13 + v14 * v38;
      v39 = v16 + v38 * v22;
      v40 = v39 + (*((float *)a2 + 1) - v39) * 0.25;
      *(float *)a5 = 0.25 * (*(float *)a2 - v34) + v34;
      *((float *)a5 + 1) = v40;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10199B40
// Name: private: int GEdgeAA::findSameVertex(int,float,float)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GEdgeAA::findSameVertex(GEdgeAA *this, int a2, float a3, float a4)
{
  unsigned int v4; // ebx
  int v5; // esi
  int v6; // edi
  unsigned int i; // ecx
  int v8; // edx

  v4 = *((_DWORD *)this + 30);
  v5 = *(_DWORD *)this;
  if ( *(_DWORD *)this <= v4 )
    return -1;
  v6 = *((_DWORD *)this + 3);
  for ( i = v5 - 1; ; --i )
  {
    v8 = *(_DWORD *)(v6 + 4 * (i >> 8)) + 12 * (unsigned __int8)i;
    if ( (*(_DWORD *)(v8 + 8) & 0xFFFFFF) == a2 && a3 == *(float *)v8 && a4 == *(float *)(v8 + 4) )
      break;
    if ( --v5 <= v4 )
      return -1;
  }
  return v5 - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1019A910
// Name: public: unsigned int GEdgeAA::GetNumBytes(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GEdgeAA::GetNumBytes(GEdgeAA *this)
{
  return 4
       * (*((_DWORD *)this + 10)
        + *((_DWORD *)this + 17)
        + *((_DWORD *)this + 14)
        + *((_DWORD *)this + 21)
        + *((_DWORD *)this + 25)
        + *((_DWORD *)this + 29)
        + ((*((_DWORD *)this + 16) + *((_DWORD *)this + 20) + 12 * (*((_DWORD *)this + 24) + 5 * *((_DWORD *)this + 9))) << 6));
}

//------------------------------------------------------------------------------
// Address: 0x1019A940
// Name: public: void GEdgeAA::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GEdgeAA::Clear(GEdgeAA *this)
{
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 8) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1019A950
// Name: public: void GEdgeAA::ClearAndRelease(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GEdgeAA::ClearAndRelease(GEdgeAA *this)
{
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease((int *)this);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 4);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 8);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 12));
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 12) = 0;
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 15);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 19);
  GArrayPagedBase<unsigned int,6,64,GAllocatorPagedLH_POD<unsigned int,2>>::ClearAndRelease(this: (int *)this + 23);
  GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *((void **)this + 27));
  *((_DWORD *)this + 29) = 0;
  *((_DWORD *)this + 28) = 0;
  *((_DWORD *)this + 27) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1019A9C0
// Name: private: int GEdgeAA::findAdjacentTriangle(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall GEdgeAA::findAdjacentTriangle(GEdgeAA *this, unsigned int a2)
{
  int v3; // ecx
  unsigned int v4; // ebx
  int v5; // edx
  unsigned int v6; // eax
  int v7; // ecx
  int v8; // eax
  bool v9; // zf
  int v10; // eax
  int v12; // [esp-10h] [ebp-28h]
  unsigned int v13; // [esp+Ch] [ebp-Ch] BYREF
  int v14; // [esp+10h] [ebp-8h]

  v3 = *(_DWORD *)(*((_DWORD *)this + 7) + 4 * (a2 >> 10));
  v4 = *(_DWORD *)(v3 + 12 * (a2 & 0x3FF) + 4);
  v5 = *(_DWORD *)(v3 + 12 * (a2 & 0x3FF));
  v12 = *((_DWORD *)this + 13);
  v13 = v4;
  v14 = v5;
  v6 = G_LowerBoundSliced<GArrayUnsafeLH_POD<unsigned int,136>,GEdgeAA::EdgeType,GEdgeAA::EdgeLess>(
         a1: (int *)this + 12,
         a2: 0,
         a3: v12,
         a4: &v13,
         a5: (int)this,
         a6: (int)this + 16);
  if ( v6 < *((_DWORD *)this + 13)
    && (v7 = *(_DWORD *)(*((_DWORD *)this + 7) + 4 * (*(_DWORD *)(*((_DWORD *)this + 12) + 4 * v6) >> 10)),
        v8 = 3 * (*(_DWORD *)(*((_DWORD *)this + 12) + 4 * v6) & 0x3FF),
        v9 = *(_DWORD *)(v7 + 4 * v8) == v4,
        v10 = v7 + 4 * v8,
        v9)
    && *(_DWORD *)(v10 + 4) == v14 )
  {
    return *(_DWORD *)(v10 + 8);
  }
  else
  {
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019AA60
// Name: public: void GEdgeAA::SortTrianglesByStyle(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GEdgeAA::SortTrianglesByStyle(GEdgeAA *this)
{
  GEdgeAA *v1; // esi
  unsigned int v2; // eax
  _DWORD **v3; // ecx
  int v4; // ecx
  int v5; // eax
  unsigned int v6; // edx
  _DWORD *v7; // eax
  int v8; // ecx
  int v9; // ecx
  int v10; // ecx
  unsigned int v11; // [esp+4h] [ebp-8h]
  GEdgeAA *v12; // [esp+8h] [ebp-4h]

  v1 = this;
  v2 = 0;
  v3 = (_DWORD **)((char *)this + 92);
  v12 = v1;
  v11 = 0;
  if ( *v3 != nullptr )
  {
    do
    {
      v4 = *(_DWORD *)(*((_DWORD *)v1 + 26) + 4 * (v2 >> 8));
      v5 = 3 * (unsigned __int8)v2;
      v6 = *(_DWORD *)(v4 + 4 * v5 + 4);
      v7 = (_DWORD *)(v4 + 4 * v5);
      if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v1 + 3) + 4 * (v6 >> 8)) + 12 * (unsigned __int8)v6 + 8) < *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v1 + 3) + 4 * (*v7 >> 8)) + 12 * (unsigned __int8)*v7 + 8) )
      {
        v8 = v7[1];
        v7[1] = *v7;
        *v7 = v8;
      }
      if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v12 + 3) + 4 * (v7[2] >> 8)) + 12 * (unsigned __int8)v7[2] + 8) < *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v12 + 3) + 4 * (v7[1] >> 8)) + 12 * (unsigned __int8)v7[1] + 8) )
      {
        v9 = v7[2];
        v7[2] = v7[1];
        v7[1] = v9;
      }
      if ( *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v12 + 3) + 4 * (v7[1] >> 8)) + 12 * (unsigned __int8)v7[1] + 8) < *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v12 + 3) + 4 * (*v7 >> 8)) + 12 * (unsigned __int8)*v7 + 8) )
      {
        v10 = v7[1];
        v7[1] = *v7;
        *v7 = v10;
      }
      v1 = v12;
      v2 = v11 + 1;
      v3 = (_DWORD **)((char *)v12 + 92);
      v11 = v2;
    }
    while ( v2 < *((_DWORD *)v12 + 23) );
  }
  G_QuickSortSliced<GArrayPagedLH_POD<GEdgeAA::TriangleType,8,64,136>,GEdgeAA::TriangleLess>(
    a1: (int)v3,
    a2: nullptr,
    a3: *v3);
}

//------------------------------------------------------------------------------
// Address: 0x1019ABE0
// Name: public: void GEdgeAA::AddVertex(struct GPointType const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GEdgeAA::AddVertex(GEdgeAA *this, const struct GPointType *a2)
{
  unsigned int v3; // edi
  int v4; // eax
  float v5; // [esp+8h] [ebp-Ch]
  float v6; // [esp+Ch] [ebp-8h]

  v5 = *(float *)a2;
  v6 = *((float *)a2 + 1);
  v3 = *(_DWORD *)this >> 8;
  if ( v3 >= *((_DWORD *)this + 1) )
    GArrayPagedBase<GEdgeAA::TriangleType,8,64,GAllocatorPagedLH_POD<GEdgeAA::TriangleType,136>>::allocatePage(
      (unsigned int *)this,
      a2: *(_DWORD *)this >> 8);
  v4 = *(_DWORD *)(*((_DWORD *)this + 3) + 4 * v3) + 12 * (unsigned __int8)*(_DWORD *)this;
  *(float *)v4 = v5;
  *(float *)(v4 + 4) = v6;
  *(_DWORD *)(v4 + 8) = -2130706433;
  ++*(_DWORD *)this;
}

//------------------------------------------------------------------------------
// Address: 0x1019AC40
// Name: public: void GEdgeAA::AddTriangle(unsigned int,unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GEdgeAA::AddTriangle(GEdgeAA *this, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5)
{
  int v5; // eax
  unsigned int *v6; // esi
  unsigned int *v7; // ebx
  int v8; // edi
  unsigned int v9; // ecx
  int v10; // edi
  _DWORD *v11; // eax
  unsigned int v12; // ecx
  int v13; // edi
  _DWORD *v14; // eax
  unsigned int v15; // ecx
  int v16; // edi
  _DWORD *v17; // eax
  unsigned int v18; // esi
  _DWORD v19[15]; // [esp+Ch] [ebp-44h] BYREF
  GEdgeAA *v20; // [esp+48h] [ebp-8h]
  unsigned int v21; // [esp+4Ch] [ebp-4h]
  unsigned int v22; // [esp+5Ch] [ebp+Ch]

  v19[0] = a2;
  v19[2] = a4;
  v19[3] = a2;
  v5 = *((_DWORD *)this + 4);
  v19[5] = a4;
  v6 = (unsigned int *)((char *)this + 16);
  v7 = (unsigned int *)((char *)this + 32);
  v8 = *((_DWORD *)this + 8);
  v20 = this;
  v19[6] = v5;
  v9 = *((_DWORD *)this + 4) >> 10;
  v19[1] = a3;
  v19[4] = a3;
  memset(&v19[7], 255, 24);
  v10 = 4 * v8;
  *(_WORD *)((char *)&v19[13] + 1) = 0;
  LOBYTE(v19[13]) = 0;
  v19[14] = a5;
  v21 = v9;
  if ( v9 >= v6[1] )
  {
    GArrayPagedBase<GEdgeAA::EdgeType,10,64,GAllocatorPagedLH_POD<GEdgeAA::EdgeType,136>>::allocatePage(
      this: v6,
      a2: v9);
    v9 = v21;
  }
  v11 = (_DWORD *)(*(_DWORD *)(v6[3] + 4 * v9) + 12 * (*v6 & 0x3FF));
  *v11 = a2;
  v11[1] = a3;
  v11[2] = v10;
  v12 = ++*v6 >> 10;
  v13 = v10 + 1;
  v21 = v12;
  if ( v12 >= v6[1] )
  {
    GArrayPagedBase<GEdgeAA::EdgeType,10,64,GAllocatorPagedLH_POD<GEdgeAA::EdgeType,136>>::allocatePage(
      this: v6,
      a2: v12);
    v12 = v21;
  }
  v14 = (_DWORD *)(*(_DWORD *)(v6[3] + 4 * v12) + 12 * (*v6 & 0x3FF));
  *v14 = a3;
  v14[1] = a4;
  v14[2] = v13;
  v15 = ++*v6 >> 10;
  v16 = v13 + 1;
  v22 = v15;
  if ( v15 >= v6[1] )
  {
    GArrayPagedBase<GEdgeAA::EdgeType,10,64,GAllocatorPagedLH_POD<GEdgeAA::EdgeType,136>>::allocatePage(
      this: v6,
      a2: v15);
    v15 = v22;
  }
  v17 = (_DWORD *)(*(_DWORD *)(v6[3] + 4 * v15) + 12 * (*v6 & 0x3FF));
  *v17 = a4;
  v17[1] = a2;
  v17[2] = v16;
  ++*v6;
  v18 = *v7 >> 8;
  if ( v18 >= v7[1] )
    GArrayPagedBase<GEdgeAA::MeshTriType,8,64,GAllocatorPagedLH_POD<GEdgeAA::MeshTriType,136>>::allocatePage(
      this: v7,
      a2: *v7 >> 8);
  qmemcpy((void *)(*(_DWORD *)(v7[3] + 4 * v18) + 60 * (unsigned __int8)(*v7)++), v19, 60);
  *((_DWORD *)v20 + 31) = a5;
}

//------------------------------------------------------------------------------
// Address: 0x1019ADA0
// Name: private: void GEdgeAA::buildAdjacencyTable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GEdgeAA::buildAdjacencyTable(GEdgeAA *this)
{
  unsigned int *v2; // ebx
  int *v3; // edi
  unsigned int i; // eax
  unsigned int j; // ebx
  unsigned int *v6; // edi
  unsigned int v7; // [esp+Ch] [ebp-4h]

  v2 = (unsigned int *)((char *)this + 16);
  v3 = (int *)((char *)this + 48);
  v7 = *((_DWORD *)this + 4);
  GArrayUnsafeBase<unsigned int,GAllocatorLH_POD<unsigned int,136>>::Reserve(this: (int)this + 48, a2: v7, a3: 0);
  v3[1] = v7;
  for ( i = 0; i < *v2; ++i )
    *(_DWORD *)(*v3 + 4 * i) = i;
  G_QuickSortSliced<GArrayUnsafeLH_POD<unsigned int,136>,GEdgeAA::EdgeIdxLess>(
    a1: v3,
    a2: nullptr,
    a3: v3[1],
    a4: (int)this,
    a5: (int)v2);
  for ( j = 0; j < *((_DWORD *)this + 8); v6[9] = GEdgeAA::findAdjacentTriangle(this, a2: v6[6] + 2) )
  {
    v6 = (unsigned int *)(*(_DWORD *)(*((_DWORD *)this + 11) + 4 * (j >> 8)) + 60 * (unsigned __int8)j);
    v6[7] = GEdgeAA::findAdjacentTriangle(this, a2: v6[6]);
    v6[8] = GEdgeAA::findAdjacentTriangle(this, a2: v6[6] + 1);
    ++j;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019AE50
// Name: private: bool GEdgeAA::buildEdgesFan(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GEdgeAA::buildEdgesFan(GEdgeAA *this, signed int a2)
{
  GEdgeAA *v2; // edx
  _DWORD *v3; // esi
  int v4; // edi
  unsigned int v5; // ebx
  unsigned int v6; // ecx
  void *v7; // eax
  void *v8; // eax
  void *v9; // eax
  signed int v10; // ebx
  unsigned int v11; // edi
  unsigned int v12; // ecx
  void *v13; // eax
  void *v14; // eax
  void *v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // edi
  unsigned int v19; // ebx
  signed int v20; // edi
  unsigned int v21; // ebx
  int v22; // eax
  char v23; // bl
  int v24; // edx
  int v26; // [esp+Ch] [ebp-24h] BYREF
  unsigned int v27; // [esp+10h] [ebp-20h] BYREF
  int v28; // [esp+14h] [ebp-1Ch] BYREF
  unsigned int v29; // [esp+18h] [ebp-18h] BYREF
  int v30; // [esp+1Ch] [ebp-14h]
  int v31; // [esp+20h] [ebp-10h]
  GEdgeAA *v32; // [esp+24h] [ebp-Ch]
  unsigned int v33; // [esp+28h] [ebp-8h]
  char v34; // [esp+2Fh] [ebp-1h]

  v2 = this;
  v3 = (_DWORD *)((char *)this + 60);
  v4 = a2;
  v32 = this;
  v34 = 0;
  v31 = 0x7FFFFFFF;
  v33 = 0;
  *((_DWORD *)this + 15) = 0;
  while ( 1 )
  {
    v5 = *v3 >> 6;
    v30 = v4;
    if ( v5 >= v3[1] )
    {
      v6 = v3[2];
      if ( v5 >= v6 )
      {
        v7 = (void *)v3[3];
        if ( v7 != nullptr )
        {
          v29 = 4 * v6 + 64;
          v8 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v7, a3: v29);
        }
        else
        {
          v28 = 136;
          v8 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v3, a3: 64, a4: &v28);
        }
        v3[2] += 16;
        v3[3] = v8;
      }
      v29 = 136;
      v9 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v3, a3: 256, a4: &v29);
      v2 = v32;
      *(_DWORD *)(v3[3] + 4 * v5) = v9;
      ++v3[1];
    }
    *(_DWORD *)(*(_DWORD *)(v3[3] + 4 * v5) + 4 * ((*v3)++ & 0x3F)) = v4;
    v10 = dword_102AAAE8[v4 & 3] | v4 & 0xFFFFFFFC;
    v11 = *v3 >> 6;
    if ( v11 >= v3[1] )
    {
      v12 = v3[2];
      if ( v11 >= v12 )
      {
        v13 = (void *)v3[3];
        if ( v13 != nullptr )
        {
          v27 = 4 * v12 + 64;
          v14 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v13, a3: v27);
        }
        else
        {
          v26 = 136;
          v14 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v3, a3: 64, a4: &v26);
        }
        v3[2] += 16;
        v3[3] = v14;
      }
      v27 = 136;
      v15 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v3, a3: 256, a4: &v27);
      v2 = v32;
      *(_DWORD *)(v3[3] + 4 * v11) = v15;
      ++v3[1];
    }
    *(_DWORD *)(*(_DWORD *)(v3[3] + 4 * v11) + 4 * (*v3 & 0x3F)) = v10;
    v16 = v31;
    ++*v3;
    if ( v30 == v16 || v10 == v16 )
      break;
    v4 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v2 + 11) + 4 * ((unsigned int)(v10 >> 2) >> 8))
                   + 4 * ((v10 & 3) + 15 * (unsigned __int8)(v10 >> 2))
                   + 28);
    if ( v4 == a2 )
    {
      v34 = 1;
LABEL_22:
      G_ReverseArray<GArrayPagedLH_POD<int,6,16,136>>(a1: v3);
      if ( v34 != 0 )
        return 1;
      v18 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v32 + 11) + 4 * ((unsigned int)(a2 >> 2) >> 8))
                      + 4 * ((a2 & 3) + 15 * (unsigned __int8)(a2 >> 2))
                      + 28);
      if ( v18 < 0 )
        return 0;
      while ( 1 )
      {
        v19 = *v3 >> 6;
        v30 = v18;
        if ( v19 >= v3[1] )
          GArrayPagedBase<unsigned int,6,16,GAllocatorPagedLH_POD<unsigned int,136>>::allocatePage(this: v3, a2: v19);
        *(_DWORD *)(*(_DWORD *)(v3[3] + 4 * v19) + 4 * ((*v3)++ & 0x3F)) = v18;
        v20 = dword_102AAAE4[v18 & 3] | v18 & 0xFFFFFFFC;
        v21 = *v3 >> 6;
        if ( v21 >= v3[1] )
          GArrayPagedBase<unsigned int,6,16,GAllocatorPagedLH_POD<unsigned int,136>>::allocatePage(
            this: v3,
            a2: *v3 >> 6);
        *(_DWORD *)(*(_DWORD *)(v3[3] + 4 * v21) + 4 * (*v3 & 0x3F)) = v20;
        v22 = v31;
        ++*v3;
        if ( v30 == v22 || v20 == v22 )
          break;
        v23 = v33;
        v24 = *(_DWORD *)(*((_DWORD *)v32 + 18) + 4 * (v33++ >> 6));
        v31 = *(_DWORD *)(v24 + 4 * (v23 & 0x3F));
        v18 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v32 + 11) + 4 * ((unsigned int)(v20 >> 2) >> 8))
                        + 4 * ((v20 & 3) + 15 * (unsigned __int8)(v20 >> 2))
                        + 28);
        if ( v18 < 0 )
          return 0;
      }
      break;
    }
    if ( v4 < 0 )
      goto LABEL_22;
    v17 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)v2 + 18) + 4 * (v33 >> 6)) + 4 * (v33 & 0x3F));
    ++v33;
    v31 = v17;
  }
  *v3 = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1019B140
// Name: private: unsigned int GEdgeAA::assignStyle(unsigned int,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GEdgeAA::assignStyle(GEdgeAA *this, unsigned int a2, unsigned int a3, unsigned int a4)
{
  int v5; // eax
  int v6; // esi
  float *v7; // eax
  int v8; // edx
  int v9; // edi
  int v10; // edi
  float v11; // edx
  int result; // eax
  int v13; // esi
  float v14; // [esp+14h] [ebp-Ch] BYREF
  float v15; // [esp+18h] [ebp-8h]
  unsigned int v16; // [esp+1Ch] [ebp-4h]

  v5 = *(_DWORD *)(*((_DWORD *)this + 3) + 4 * (a2 >> 8));
  v6 = *(_DWORD *)(v5 + 12 * (unsigned __int8)a2 + 8);
  v7 = (float *)(v5 + 12 * (unsigned __int8)a2);
  if ( v6 >= 0 )
    return a2;
  v8 = *((_DWORD *)this + 3);
  v9 = *(_DWORD *)(*(_DWORD *)(v8 + 4 * (a3 >> 8)) + 12 * (unsigned __int8)a3 + 8);
  if ( v9 < 0 )
    v9 = *(_DWORD *)(*(_DWORD *)(v8 + 4 * (a4 >> 8)) + 12 * (unsigned __int8)a4 + 8);
  v10 = v9 & 0xFFFFFF;
  if ( (v6 & 0xFFFFFF) == v10 )
    return a2;
  if ( (v6 & 0x8000000) == 0 )
  {
    *((_DWORD *)v7 + 2) = v10 | v6 & 0xFF000000 | 0x18000000;
    return a2;
  }
  v11 = *v7;
  v15 = v7[1];
  v14 = v11;
  v16 = v6;
  result = GEdgeAA::findSameVertex(this, a2: v10, a3: v11, a4: v15);
  if ( result < 0 )
  {
    v16 = v10 | v6 & 0xFF000000 | 0x10000000;
    v13 = *(_DWORD *)this;
    GArrayPagedBase<GEdgeAA::VertexType,8,64,GAllocatorPagedLH_POD<GEdgeAA::VertexType,136>>::PushBack(
      (unsigned int *)this,
      a2: &v14);
    return v13;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019B240
// Name: public: void GEdgeAA::ProcessEdges(float,enum GEdgeAA::AA_Method)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GEdgeAA::ProcessEdges(unsigned int *this, float a2, int a3)
{
  long double v4; // st7
  unsigned int v5; // ebx
  unsigned int v6; // edi
  char v7; // al
  bool v8; // zf
  _DWORD *v9; // ecx
  int v10; // ebx
  unsigned int v11; // ebx
  int v12; // eax
  signed int v13; // ecx
  unsigned int v14; // ebx
  unsigned int v15; // edi
  unsigned int v16; // edi
  int v17; // edx
  float v18; // ecx
  int v19; // eax
  unsigned int v20; // edi
  unsigned int v21; // ecx
  void *v22; // eax
  void *v23; // eax
  int v24; // eax
  signed int v25; // edx
  unsigned int v26; // ebx
  unsigned int v27; // ecx
  void *v28; // eax
  void *v29; // eax
  const struct GEdgeAA::MeshTriType *v30; // ebx
  unsigned int v31; // edi
  float v32; // eax
  float v33; // eax
  unsigned int v34; // edi
  unsigned int v35; // ebx
  float *v36; // eax
  int v37; // eax
  unsigned int v38; // ebx
  unsigned int v39; // ecx
  void *v40; // eax
  void *v41; // eax
  unsigned int *v42; // eax
  unsigned int v43; // ecx
  float v44; // eax
  unsigned int v45; // ecx
  int v46; // ecx
  unsigned int v47; // eax
  int v48; // edx
  int v49; // edi
  int v50; // ecx
  int v51; // eax
  float v52; // edi
  float *v53; // edx
  float v54; // ecx
  int *v55; // eax
  int v56; // ecx
  float *v57; // edx
  unsigned int v58; // eax
  int v59; // ebx
  float v60; // edx
  int v61; // edi
  int v62; // edx
  unsigned int v63; // ebx
  float *v64; // eax
  float v65; // edx
  float v66; // ecx
  unsigned int v67; // ebx
  int v68; // eax
  float v69; // ecx
  signed int v70; // edx
  int v71; // eax
  int v72; // ecx
  int v73; // edi
  int v74; // ecx
  int v75; // edx
  int v76; // ecx
  int v77; // ebx
  float v78; // eax
  int v79; // edx
  int v80; // eax
  float v81; // ecx
  int v82; // eax
  float v83; // ecx
  int v84; // eax
  float v85; // ecx
  signed int v86; // edx
  int v87; // eax
  unsigned int v88; // ebx
  void **v89; // edi
  void *v90; // eax
  unsigned int v91; // ecx
  unsigned int v92; // edx
  int v93; // edi
  _DWORD *v94; // eax
  _DWORD *v95; // ecx
  int v96; // edi
  int v97; // eax
  int v98; // ebx
  int v99; // ecx
  int v100; // eax
  int v101; // edi
  float v102; // [esp+1Ch] [ebp-9Ch]
  float v103; // [esp+40h] [ebp-78h]
  int v104; // [esp+40h] [ebp-78h]
  int v105; // [esp+40h] [ebp-78h]
  float v106; // [esp+44h] [ebp-74h]
  int v107; // [esp+44h] [ebp-74h]
  float v108; // [esp+4Ch] [ebp-6Ch]
  int v109; // [esp+4Ch] [ebp-6Ch]
  float v110; // [esp+50h] [ebp-68h]
  unsigned int v111; // [esp+58h] [ebp-60h]
  unsigned int v112; // [esp+58h] [ebp-60h]
  unsigned int v113; // [esp+5Ch] [ebp-5Ch]
  unsigned int v114; // [esp+5Ch] [ebp-5Ch]
  unsigned int v115; // [esp+60h] [ebp-58h]
  unsigned int v116; // [esp+60h] [ebp-58h]
  int v117; // [esp+64h] [ebp-54h] BYREF
  int v118; // [esp+68h] [ebp-50h] BYREF
  float *v119; // [esp+6Ch] [ebp-4Ch]
  struct GEdgeAA::VertexType *v120; // [esp+70h] [ebp-48h]
  float v121; // [esp+74h] [ebp-44h]
  int v122; // [esp+78h] [ebp-40h] BYREF
  unsigned int v123; // [esp+7Ch] [ebp-3Ch] BYREF
  int v124; // [esp+80h] [ebp-38h] BYREF
  int v125; // [esp+84h] [ebp-34h] BYREF
  int v126; // [esp+88h] [ebp-30h]
  float i; // [esp+8Ch] [ebp-2Ch]
  signed int v128; // [esp+90h] [ebp-28h]
  float v129; // [esp+94h] [ebp-24h] BYREF
  float v130; // [esp+98h] [ebp-20h] BYREF
  float v131; // [esp+9Ch] [ebp-1Ch]
  float v132; // [esp+A0h] [ebp-18h]
  unsigned int v133; // [esp+A4h] [ebp-14h]
  _DWORD *v134; // [esp+A8h] [ebp-10h]
  unsigned int v135; // [esp+ACh] [ebp-Ch]
  unsigned int j; // [esp+B0h] [ebp-8h]
  char v137; // [esp+B7h] [ebp-1h]

  *(this + 23) = 0;
  GEdgeAA::buildAdjacencyTable((GEdgeAA *)this);
  v4 = a2;
  if ( a2 < 0.0 )
  {
    v128 = -1862270977;
    if ( a3 == 0 )
    {
      v128 = *(this + 31) | 0x90000000;
      a2 = v4 + v4;
      v4 = a2;
    }
    i = fabs(v4);
    v5 = 0;
    j = 0;
    for ( i = i * 10.0; v5 < *(this + 8); j = ++v5 )
    {
      v6 = 0;
      v126 = *(_DWORD *)(*(this + 11) + 4 * (v5 >> 8)) + 60 * (unsigned __int8)v5;
      v135 = 0;
      v134 = (_DWORD *)v126;
      do
      {
        if ( (*(_BYTE *)(v126 + v6 + 52) & 1) == 0
          && (*(_DWORD *)(*(_DWORD *)(*(this + 3) + 4 * (*v134 >> 8)) + 12 * (unsigned __int8)*v134 + 8) & 0x20000000) == 0 )
        {
          v7 = GEdgeAA::buildEdgesFan((GEdgeAA *)this, a2: v6 + 4 * v5);
          v8 = *(this + 15) == 0;
          v137 = v7;
          if ( !v8 )
          {
            if ( v7 == 0 )
              goto LABEL_12;
            if ( *(_DWORD *)(*(_DWORD *)(*(this + 11) + 4 * ((unsigned int)(**(int **)*(this + 18) >> 2) >> 8))
                           + 60 * (unsigned __int8)(**(int **)*(this + 18) >> 2)
                           + 56) != *(_DWORD *)(*(_DWORD *)(*(this + 11)
                                                          + 4
                                                          * ((unsigned int)(*(int *)(*(_DWORD *)(*(this + 18)
                                                                                               + 4
                                                                                               * ((*(this + 15) - 1) >> 6))
                                                                                   + 4 * ((*(this + 15) - 1) & 0x3F)) >> 2) >> 8))
                                              + 60
                                              * (unsigned __int8)(*(int *)(*(_DWORD *)(*(this + 18)
                                                                                     + 4 * ((*(this + 15) - 1) >> 6))
                                                                         + 4 * ((*(this + 15) - 1) & 0x3F)) >> 2)
                                              + 56) )
            {
              v7 = v137;
LABEL_12:
              v9 = v134;
              v10 = *(this + 3);
              *(this + 19) = 0;
              v119 = (float *)(*(_DWORD *)(v10 + 4 * (*v9 >> 8)) + 12 * (unsigned __int8)*v9);
              if ( v7 == 0 )
              {
                v102 = -a2;
                GEdgeAA::calcIntersectionPoint(
                  (GEdgeAA *)this,
                  a2: v102,
                  a3: i,
                  a4: 0,
                  a5: *(this + 15) - 1,
                  a6: &v130,
                  a7: &v129);
                v108 = v130;
                v133 = *this;
                v11 = v133 >> 8;
                v110 = v129;
                if ( v133 >> 8 >= *(this + 1) )
                  GArrayPagedBase<GEdgeAA::TriangleType,8,64,GAllocatorPagedLH_POD<GEdgeAA::TriangleType,136>>::allocatePage(
                    this,
                    a2: v11);
                v12 = *(_DWORD *)(*(this + 3) + 4 * v11) + 12 * (unsigned __int8)*this;
                *(float *)v12 = v108;
                v13 = v128;
                *(float *)(v12 + 4) = v110;
                *(_DWORD *)(v12 + 8) = v13;
                ++*this;
                v14 = *(this + 19) >> 6;
                if ( v14 >= *(this + 20) )
                  GArrayPagedBase<unsigned int,6,16,GAllocatorPagedLH_POD<unsigned int,136>>::allocatePage(
                    this: this + 19,
                    a2: *(this + 19) >> 6);
                *(_DWORD *)(*(_DWORD *)(*(this + 22) + 4 * v14) + 4 * ((*(this + 19))++ & 0x3F)) = v133;
                v15 = v133;
                *(_DWORD *)(*(_DWORD *)(*(this + 11) + 4 * (**(_DWORD **)*(this + 18) >> 10))
                          + 4
                          * (dword_102AAAE4[**(_DWORD **)*(this + 18) & 3]
                           + 15 * (unsigned __int8)(**(_DWORD **)*(this + 18) >> 2))
                          + 40) = v133;
                *(_DWORD *)(*(_DWORD *)(*(this + 11)
                                      + 4
                                      * (*(_DWORD *)(*(_DWORD *)(*(this + 18) + 4 * ((*(this + 15) - 1) >> 6))
                                                   + 4 * ((*(this + 15) - 1) & 0x3F)) >> 10))
                          + 4
                          * ((*(_DWORD *)(*(_DWORD *)(*(this + 18) + 4 * ((*(this + 15) - 1) >> 6))
                                        + 4 * ((*(this + 15) - 1) & 0x3F))
                            & 3)
                           + 15
                           * (unsigned __int8)(*(_DWORD *)(*(_DWORD *)(*(this + 18) + 4 * ((*(this + 15) - 1) >> 6))
                                                         + 4 * ((*(this + 15) - 1) & 0x3F)) >> 2))
                          + 40) = v15;
              }
              if ( a3 == 1 )
              {
                v16 = 0;
                v131 = 0.0;
                if ( *(this + 15) != 0 )
                {
                  while ( 1 )
                  {
                    v17 = *(this + 18);
                    LODWORD(v18) = v16 + 1;
                    v19 = *(_DWORD *)(*(this + 11)
                                    + 4
                                    * ((unsigned int)(*(int *)(*(_DWORD *)(v17 + 4 * (v16 >> 6)) + 4 * (v16 & 0x3F)) >> 2) >> 8))
                        + 60 * (unsigned __int8)(*(int *)(*(_DWORD *)(v17 + 4 * (v16 >> 6)) + 4 * (v16 & 0x3F)) >> 2);
                    LODWORD(v132) = v16 + 1;
                    if ( v16 + 1 < *(this + 15) )
                    {
                      v132 = *(float *)(v19 + 56);
                      do
                      {
                        if ( LODWORD(v132) != *(_DWORD *)(*(_DWORD *)(*(this + 11)
                                                                    + 4
                                                                    * ((unsigned int)(*(int *)(*(_DWORD *)(v17 + 4 * (LODWORD(v18) >> 6))
                                                                                             + 4 * (LOBYTE(v18) & 0x3F)) >> 2) >> 8))
                                                        + 60
                                                        * (unsigned __int8)(*(int *)(*(_DWORD *)(v17
                                                                                               + 4 * (LODWORD(v18) >> 6))
                                                                                   + 4 * (LOBYTE(v18) & 0x3F)) >> 2)
                                                        + 56) )
                          break;
                        ++LODWORD(v18);
                      }
                      while ( LODWORD(v18) < *(this + 15) );
                      v16 = LODWORD(v131);
                      v132 = v18;
                    }
                    GEdgeAA::calcIntersectionPoint(
                      (GEdgeAA *)this,
                      a2,
                      a3: i,
                      a4: v16,
                      a5: LODWORD(v18) - 1,
                      a6: &v130,
                      a7: &v129);
                    v103 = v130;
                    v133 = *this;
                    v20 = v133 >> 8;
                    v106 = v129;
                    if ( v133 >> 8 >= *(this + 1) )
                    {
                      v21 = *(this + 2);
                      if ( v20 >= v21 )
                      {
                        v22 = (void *)*(this + 3);
                        if ( v22 != nullptr )
                        {
                          v23 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v22, a3: 4 * v21 + 256);
                        }
                        else
                        {
                          v125 = 136;
                          v23 = GMemory::pGlobalHeap->AllocAutoHeap_2(
                                  this: GMemory::pGlobalHeap,
                                  a2: this,
                                  a3: 256,
                                  a4: &v125);
                        }
                        *(this + 2) += 64;
                        *(this + 3) = (unsigned int)v23;
                      }
                      v124 = 136;
                      *(_DWORD *)(*(this + 3) + 4 * v20) = GMemory::pGlobalHeap->AllocAutoHeap_2(
                                                             this: GMemory::pGlobalHeap,
                                                             a2: this,
                                                             a3: 3072,
                                                             a4: &v124);
                      ++*(this + 1);
                    }
                    v24 = *(_DWORD *)(*(this + 3) + 4 * v20) + 12 * (unsigned __int8)*this;
                    *(float *)v24 = v103;
                    v25 = v128;
                    *(float *)(v24 + 4) = v106;
                    *(_DWORD *)(v24 + 8) = v25;
                    ++*this;
                    v26 = *(this + 19) >> 6;
                    if ( v26 >= *(this + 20) )
                    {
                      v27 = *(this + 21);
                      if ( v26 >= v27 )
                      {
                        v28 = (void *)*(this + 22);
                        if ( v28 != nullptr )
                        {
                          v123 = 4 * v27 + 64;
                          v29 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v28, a3: v123);
                        }
                        else
                        {
                          v122 = 136;
                          v29 = GMemory::pGlobalHeap->AllocAutoHeap_2(
                                  this: GMemory::pGlobalHeap,
                                  a2: this + 19,
                                  a3: 64,
                                  a4: &v122);
                        }
                        *(this + 21) += 16;
                        *(this + 22) = (unsigned int)v29;
                      }
                      v123 = 136;
                      *(_DWORD *)(*(this + 22) + 4 * v26) = GMemory::pGlobalHeap->AllocAutoHeap_2(
                                                              this: GMemory::pGlobalHeap,
                                                              a2: this + 19,
                                                              a3: 256,
                                                              a4: &v123);
                      ++*(this + 20);
                    }
                    *(_DWORD *)(*(_DWORD *)(*(this + 22) + 4 * v26) + 4 * ((*(this + 19))++ & 0x3F)) = v133;
                    v120 = (struct GEdgeAA::VertexType *)(*(_DWORD *)(*(this + 3) + 4 * ((*this - 1) >> 8))
                                                        + 12 * (unsigned __int8)(*(_BYTE *)this - 1));
                    if ( LODWORD(v131) < LODWORD(v132) )
                    {
                      v121 = -a2;
                      do
                      {
                        v30 = (const struct GEdgeAA::MeshTriType *)(*(_DWORD *)(*(this + 11)
                                                                              + 4
                                                                              * ((dword_102AAAE4[*(_DWORD *)(*(_DWORD *)(*(this + 18) + 4 * (LODWORD(v131) >> 6)) + 4 * (LOBYTE(v131) & 0x3F))
                                                                                               & 3]
                                                                                | *(_DWORD *)(*(_DWORD *)(*(this + 18) + 4 * (LODWORD(v131) >> 6))
                                                                                            + 4 * (LOBYTE(v131) & 0x3F))
                                                                                & 0xFFFFFFFC) >> 10))
                                                                  + 60
                                                                  * (unsigned __int8)((dword_102AAAE4[*(_DWORD *)(*(_DWORD *)(*(this + 18) + 4 * (LODWORD(v131) >> 6)) + 4 * (LOBYTE(v131) & 0x3F)) & 3]
                                                                                     | *(_DWORD *)(*(_DWORD *)(*(this + 18) + 4 * (LODWORD(v131) >> 6))
                                                                                                 + 4
                                                                                                 * (LOBYTE(v131) & 0x3F))
                                                                                     & 0xFFFFFFFC) >> 2));
                        v31 = dword_102AAAE4[*(_DWORD *)(*(_DWORD *)(*(this + 18) + 4 * (LODWORD(v131) >> 6))
                                                       + 4 * (LOBYTE(v131) & 0x3F))
                                           & 3]
                            & 3;
                        GEdgeAA::correctCrossIntersection(
                          (GEdgeAA *)this,
                          a2: (const struct GEdgeAA::VertexType *)(*(_DWORD *)(*(this + 3) + 4 * (*v134 >> 8))
                                                             + 12 * (unsigned __int8)*v134),
                          a3: v30,
                          a4: v31,
                          a5: v120,
                          a6: v121);
                        LODWORD(v32) = LODWORD(v131) + 2;
                        *((_DWORD *)v30 + v31 + 3) = v133;
                        *((_BYTE *)v30 + v31 + 52) |= 1u;
                        v131 = v32;
                      }
                      while ( LODWORD(v32) < LODWORD(v132) );
                    }
                    v131 = v132;
                    if ( LODWORD(v132) >= *(this + 15) )
                      break;
                    v16 = LODWORD(v131);
                  }
                }
                while ( *(this + 19) > 2 )
                {
                  v33 = *((float *)this + 19);
                  v34 = 0;
                  v132 = 0.0;
                  v35 = 0;
                  v131 = v33;
                  if ( v33 != 0.0 )
                  {
                    do
                    {
                      v36 = (float *)(*(_DWORD *)(*(this + 3)
                                                + 4
                                                * (*(_DWORD *)(*(_DWORD *)(*(this + 22) + 4 * (v35 >> 6))
                                                             + 4 * (v35 & 0x3F)) >> 8))
                                    + 12
                                    * (unsigned __int8)*(_DWORD *)(*(_DWORD *)(*(this + 22) + 4 * (v35 >> 6))
                                                                 + 4 * (v35 & 0x3F)));
                      *(float *)&v120 = *v119 - *v36;
                      v121 = v119[1] - v36[1];
                      *(float *)&v120 = *(float *)&v120 * *(float *)&v120 + v121 * v121;
                      *(float *)&v120 = sqrt(*(float *)&v120);
                      if ( v132 < (double)*(float *)&v120 )
                      {
                        v132 = *(float *)&v120;
                        v34 = v35;
                      }
                      ++v35;
                    }
                    while ( v35 < LODWORD(v131) );
                  }
                  LODWORD(v121) = v34 + 1;
                  v37 = *(this + 22);
                  v111 = *(_DWORD *)(*(_DWORD *)(v37 + 4 * (((LODWORD(v131) + v34 - 1) % LODWORD(v131)) >> 6))
                                   + 4 * (((LODWORD(v131) + v34 - 1) % LODWORD(v131)) & 0x3F));
                  v113 = *(_DWORD *)(*(_DWORD *)(v37 + 4 * (v34 >> 6)) + 4 * (v34 & 0x3F));
                  v38 = *(this + 23) >> 8;
                  v115 = *(_DWORD *)(*(_DWORD *)(v37 + 4 * (((v34 + 1) % LODWORD(v131)) >> 6))
                                   + 4 * (((v34 + 1) % LODWORD(v131)) & 0x3F));
                  if ( v38 >= *(this + 24) )
                  {
                    v39 = *(this + 25);
                    if ( v38 >= v39 )
                    {
                      v40 = (void *)*(this + 26);
                      if ( v40 != nullptr )
                      {
                        v120 = (struct GEdgeAA::VertexType *)(4 * v39 + 256);
                        v41 = GMemory::pGlobalHeap->Realloc(this: GMemory::pGlobalHeap, a2: v40, a3: v120);
                      }
                      else
                      {
                        v118 = 136;
                        v41 = GMemory::pGlobalHeap->AllocAutoHeap_2(
                                this: GMemory::pGlobalHeap,
                                a2: this + 23,
                                a3: 256,
                                a4: &v118);
                      }
                      *(this + 25) += 64;
                      *(this + 26) = (unsigned int)v41;
                    }
                    v117 = 136;
                    *(_DWORD *)(*(this + 26) + 4 * v38) = GMemory::pGlobalHeap->AllocAutoHeap_2(
                                                            this: GMemory::pGlobalHeap,
                                                            a2: this + 23,
                                                            a3: 3072,
                                                            a4: &v117);
                    ++*(this + 24);
                  }
                  v42 = (unsigned int *)(*(_DWORD *)(*(this + 26) + 4 * v38) + 12 * (unsigned __int8)*(this + 23));
                  *v42 = v111;
                  v42[1] = v113;
                  v42[2] = v115;
                  ++*(this + 23);
                  v43 = *(this + 19);
                  if ( v43 != 0 )
                  {
                    v44 = v121;
                    v131 = v121;
                    if ( LODWORD(v121) < v43 )
                    {
                      v45 = LODWORD(v121) - 1;
                      LODWORD(v132) = LODWORD(v121) - 1;
                      do
                      {
                        *(_DWORD *)(*(_DWORD *)(*(this + 22) + 4 * (v45 >> 6)) + 4 * (v45 & 0x3F)) = *(_DWORD *)(*(_DWORD *)(*(this + 22) + 4 * (LODWORD(v44) >> 6)) + 4 * (LOBYTE(v44) & 0x3F));
                        LODWORD(v44) = LODWORD(v131) + 1;
                        v45 = LODWORD(v132) + 1;
                        v131 = v44;
                        ++LODWORD(v132);
                      }
                      while ( LODWORD(v44) < *(this + 19) );
                    }
                    --*(this + 19);
                  }
                }
              }
              v46 = *(_DWORD *)(*(this + 3) + 4 * (*v134 >> 8));
              *(_DWORD *)(v46 + 12 * (unsigned __int8)*v134 + 8) |= 0x20000000u;
            }
            v5 = j;
            v6 = v135;
          }
        }
        ++v134;
        v135 = ++v6;
      }
      while ( v6 < 3 );
    }
    v47 = 0;
    j = 0;
    if ( *(this + 8) != 0 )
    {
LABEL_68:
      v48 = *(_DWORD *)(*(this + 11) + 4 * (v47 >> 8));
      v49 = 15 * (unsigned __int8)v47;
      v50 = *(_DWORD *)(v48 + 60 * (unsigned __int8)v47 + 12);
      v51 = *(_DWORD *)(v48 + 60 * (unsigned __int8)v47 + 16);
      LODWORD(v52) = v48 + 4 * v49;
      v129 = v52;
      v117 = v50;
      v118 = v51;
      if ( v50 != v51 )
      {
        v53 = *(float **)(LODWORD(v52) + 20);
        v119 = v53;
        if ( (float *)v51 != v53 && v53 != (float *)v50 )
        {
          LODWORD(v54) = *(this + 23) >> 8;
          a2 = v54;
          if ( LODWORD(v54) >= *(this + 24) )
          {
            GArrayPagedBase<GEdgeAA::TriangleType,8,64,GAllocatorPagedLH_POD<GEdgeAA::TriangleType,136>>::allocatePage(
              this: this + 23,
              a2: LODWORD(v54));
            v54 = a2;
          }
          v55 = (int *)(*(_DWORD *)(*(this + 26) + 4 * LODWORD(v54)) + 12 * (unsigned __int8)*(this + 23));
          v56 = v118;
          *v55 = v117;
          v57 = v119;
          v55[1] = v56;
          v55[2] = (int)v57;
          ++*(this + 23);
        }
      }
      v135 = 0;
      LODWORD(v132) = LODWORD(v52) + 28;
      while ( 1 )
      {
        *(_DWORD *)(*(_DWORD *)(*(this + 3) + 4 * (*(_DWORD *)(LODWORD(v132) - 16) >> 8))
                  + 12 * (unsigned __int8)*(_DWORD *)(LODWORD(v132) - 16)
                  + 8) = *(_DWORD *)(LODWORD(v52) + 56) | 0x10000000;
        v58 = v135;
        if ( (*(_BYTE *)(LODWORD(v52) + v135 + 52) & 2) == 0 )
          break;
LABEL_93:
        LODWORD(v132) += 4;
        v135 = v58 + 1;
        if ( v58 + 1 >= 3 )
        {
          v47 = j + 1;
          j = v47;
          if ( v47 >= *(this + 8) )
            goto LABEL_95;
          goto LABEL_68;
        }
      }
      v59 = *(_DWORD *)LODWORD(v132);
      if ( (int)*(_DWORD *)LODWORD(v132) >= 0 )
      {
        v71 = *(_DWORD *)(*(this + 11) + 4 * ((unsigned int)(v59 >> 2) >> 8));
        v72 = *(_DWORD *)(v71 + 60 * (unsigned __int8)(v59 >> 2) + 56);
        v118 = v71 + 60 * (unsigned __int8)(v59 >> 2);
        if ( v72 == *(_DWORD *)(LODWORD(v52) + 56) )
        {
LABEL_91:
          v58 = v135;
LABEL_92:
          *(_BYTE *)(LODWORD(v52) + v58 + 52) |= 2u;
          goto LABEL_93;
        }
        v73 = dword_102AAAE4[v135 & 3] + 15 * (unsigned __int8)((v135 | (4 * j)) >> 2);
        v74 = *(this + 11);
        v117 = v135 & 3;
        v131 = *(float *)(*(_DWORD *)(v74 + 4 * ((v135 | (4 * j)) >> 10)) + 4 * v73 + 12);
        v75 = 15 * (unsigned __int8)((unsigned int)v59 >> 2);
        v76 = *(_DWORD *)(*(this + 11) + 4 * ((unsigned int)v59 >> 10));
        v77 = v59 & 3;
        v128 = *(_DWORD *)(v76 + 4 * (v77 + v75) + 12);
        a2 = *(float *)(v76 + 4 * (v75 + dword_102AAAE4[v77]) + 12);
        v109 = *(_DWORD *)(*(_DWORD *)(*(this + 11) + 4 * ((v135 | (4 * j)) >> 10))
                         + 4 * (v117 + 15 * (unsigned __int8)((v135 | (4 * j)) >> 2))
                         + 12);
        LODWORD(v78) = *(this + 23) >> 8;
        i = v78;
        if ( LODWORD(v78) >= *(this + 24) )
          GArrayPagedBase<GEdgeAA::TriangleType,8,64,GAllocatorPagedLH_POD<GEdgeAA::TriangleType,136>>::allocatePage(
            this: this + 23,
            a2: LODWORD(v78));
        v79 = *(_DWORD *)(*(this + 26) + 4 * LODWORD(i));
        v80 = 3 * (unsigned __int8)*(this + 23);
        *(_DWORD *)(v79 + 4 * v80) = v109;
        v81 = a2;
        v82 = v79 + 4 * v80;
        *(float *)(v82 + 4) = v131;
        *(float *)(v82 + 8) = v81;
        LODWORD(v83) = ++*(this + 23) >> 8;
        i = v83;
        if ( LODWORD(v83) >= *(this + 24) )
        {
          GArrayPagedBase<GEdgeAA::TriangleType,8,64,GAllocatorPagedLH_POD<GEdgeAA::TriangleType,136>>::allocatePage(
            this: this + 23,
            a2: LODWORD(v83));
          v83 = i;
        }
        v84 = *(_DWORD *)(*(this + 26) + 4 * LODWORD(v83)) + 12 * (unsigned __int8)*(this + 23);
        v85 = v131;
        *(float *)v84 = a2;
        v86 = v128;
        *(float *)(v84 + 4) = v85;
        *(_DWORD *)(v84 + 8) = v86;
        v87 = v118;
        ++*(this + 23);
        *(_BYTE *)(v77 + v87 + 52) |= 2u;
      }
      else
      {
        v60 = *(float *)(LODWORD(v132) + 12);
        v128 = *(_DWORD *)(LODWORD(v52) + 4 * dword_102AAAE4[v135] + 40);
        a2 = v60;
        if ( v128 < 0 || v60 < 0.0 )
          goto LABEL_92;
        v61 = *(this + 11);
        v62 = v135 & 3;
        v131 = *(float *)(*(_DWORD *)(v61 + 4 * ((v135 | (4 * j)) >> 10))
                        + 4 * (dword_102AAAE4[v62] + 15 * (unsigned __int8)((v135 | (4 * j)) >> 2))
                        + 12);
        v63 = *(this + 23) >> 8;
        v104 = *(_DWORD *)(*(_DWORD *)(v61 + 4 * ((v135 | (4 * j)) >> 10))
                         + 4 * (v62 + 15 * (unsigned __int8)((v135 | (4 * j)) >> 2))
                         + 12);
        if ( v63 >= *(this + 24) )
          GArrayPagedBase<GEdgeAA::TriangleType,8,64,GAllocatorPagedLH_POD<GEdgeAA::TriangleType,136>>::allocatePage(
            this: this + 23,
            a2: v63);
        v64 = (float *)(*(_DWORD *)(*(this + 26) + 4 * v63) + 12 * (unsigned __int8)*(this + 23));
        v65 = v131;
        *(_DWORD *)v64 = v104;
        v66 = a2;
        v64[1] = v65;
        v64[2] = v66;
        v67 = ++*(this + 23) >> 8;
        if ( v67 >= *(this + 24) )
          GArrayPagedBase<GEdgeAA::TriangleType,8,64,GAllocatorPagedLH_POD<GEdgeAA::TriangleType,136>>::allocatePage(
            this: this + 23,
            a2: *(this + 23) >> 8);
        v68 = *(_DWORD *)(*(this + 26) + 4 * v67) + 12 * (unsigned __int8)*(this + 23);
        v69 = v131;
        *(float *)v68 = a2;
        v70 = v128;
        *(float *)(v68 + 4) = v69;
        *(_DWORD *)(v68 + 8) = v70;
        ++*(this + 23);
      }
      v52 = v129;
      goto LABEL_91;
    }
LABEL_95:
    if ( a3 == 1 )
    {
      v88 = *this;
      v89 = (void **)(this + 27);
      if ( *this > *(this + 29) )
      {
        GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v89);
        *(this + 29) = v88;
        if ( v88 != 0 )
        {
          LODWORD(a2) = 2;
          v90 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: this + 27, a3: 4 * v88, a4: &a2);
        }
        else
        {
          v90 = nullptr;
        }
        *v89 = v90;
      }
      v91 = 0;
      *(this + 28) = v88;
      v92 = 0;
      for ( j = 0; v91 < *this; j = v91 )
      {
        *(_DWORD *)(*(this + 27) + 4 * v91) = v92;
        v93 = *(this + 3);
        v94 = (_DWORD *)(*(_DWORD *)(v93 + 4 * (v91 >> 8)) + 12 * (unsigned __int8)v91);
        if ( (v94[2] & 0x10000000) != 0 )
        {
          v95 = (_DWORD *)(*(_DWORD *)(v93 + 4 * (v92 >> 8)) + 12 * (unsigned __int8)v92);
          *v95 = *v94;
          v95[1] = v94[1];
          v95[2] = v94[2];
          v91 = j;
          ++v92;
        }
        ++v91;
      }
      *(this + 30) = v92;
      if ( v92 < *this )
        *this = v92;
      v8 = *(this + 23) == 0;
      j = 0;
      if ( !v8 )
      {
        do
        {
          v96 = 4 * (j >> 8);
          v97 = *(_DWORD *)(v96 + *(this + 26));
          v98 = 12 * (unsigned __int8)j;
          v99 = *(this + 27);
          v112 = *(_DWORD *)(v99 + 4 * *(_DWORD *)(v97 + v98));
          v116 = *(_DWORD *)(v99 + 4 * *(_DWORD *)(v97 + v98 + 8));
          v114 = *(_DWORD *)(v99 + 4 * *(_DWORD *)(v97 + v98 + 4));
          v105 = GEdgeAA::assignStyle((GEdgeAA *)this, a2: v112, a3: v114, a4: v116);
          v107 = GEdgeAA::assignStyle((GEdgeAA *)this, a2: v114, a3: v116, a4: v112);
          v100 = GEdgeAA::assignStyle((GEdgeAA *)this, a2: v116, a3: v112, a4: v114);
          v101 = *(_DWORD *)(v96 + *(this + 26));
          *(_DWORD *)(v101 + v98) = v105;
          *(_DWORD *)(v101 + v98 + 4) = v107;
          *(_DWORD *)(v101 + v98 + 8) = v100;
          ++j;
        }
        while ( j < *(this + 23) );
      }
    }
  }
}
