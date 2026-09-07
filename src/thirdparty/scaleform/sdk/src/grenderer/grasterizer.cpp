// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/grenderer/grasterizer.cpp
// Functions: 13
// ============================================================

#include "thirdparty\scaleform\sdk\src\grenderer\grasterizer.h"

//------------------------------------------------------------------------------
// Address: 0x10188F40
// Name: private: static bool GRasterizer::cellXLess(struct GRasterizer::Cell const __near *,struct GRasterizer::Cell const __near *)
// Source: json
//------------------------------------------------------------------------------
static BOOL __cdecl GRasterizer::cellXLess(const struct Cell *a1, const struct Cell *a2)
{
  return (int)a1->lpVtbl < (int)a2->lpVtbl;
}

//------------------------------------------------------------------------------
// Address: 0x10188F60
// Name: public: void GRasterizer::MoveTo(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRasterizer::MoveTo(GRasterizer *this, float a2, float a3)
{
  int v3; // eax
  int v4; // eax

  v3 = (int)(a2 * 256.0);
  *((_DWORD *)this + 25) = v3;
  *((_DWORD *)this + 23) = v3;
  v4 = (int)(256.0 * a3);
  *((_DWORD *)this + 26) = v4;
  *((_DWORD *)this + 24) = v4;
}

//------------------------------------------------------------------------------
// Address: 0x10188FA0
// Name: public: void GRasterizer::SweepScanline(unsigned int,unsigned char __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRasterizer::SweepScanline(GRasterizer *this, unsigned int a2, unsigned __int8 *a3, unsigned int count)
{
  GRasterizer *v4; // edx
  _DWORD *v5; // eax
  int v6; // ebx
  int *v7; // esi
  int v8; // edi
  int v9; // ecx
  unsigned int v10; // eax
  int v11; // eax
  int v12; // esi
  int v13; // eax
  int **v15; // [esp+8h] [ebp-4h]
  unsigned int v16; // [esp+14h] [ebp+8h]

  v4 = this;
  if ( a2 < *((_DWORD *)this + 13) )
  {
    v5 = (_DWORD *)(*((_DWORD *)this + 12) + 8 * a2);
    v6 = 0;
    v16 = v5[1];
    v15 = (int **)(*((_DWORD *)this + 9) + 4 * *v5);
    if ( v16 != 0 )
    {
      while ( 1 )
      {
        v7 = *v15;
        v6 += (*v15)[2];
        v8 = **v15;
        v9 = (*v15)[3];
        v10 = --v16;
        if ( v16 != 0 )
        {
          do
          {
            v7 = *++v15;
            if ( **v15 != v8 )
              break;
            v9 += v7[3];
            v6 += v7[2];
            --v10;
          }
          while ( v10 != 0 );
          v16 = v10;
        }
        if ( v9 != 0 )
        {
          v11 = ((v6 << 9) - v9) >> 9;
          if ( v11 < 0 )
            v11 = -v11;
          if ( *(_DWORD *)v4 == 1 )
          {
            v11 &= 0x1FFu;
            if ( (unsigned int)v11 > 0x100 )
              v11 = 512 - v11;
          }
          if ( v11 > 255 )
            v11 = 255;
          if ( *((_DWORD *)v4 + 3) != 0 )
            v11 = *(_DWORD *)(*((_DWORD *)v4 + 2) + 4 * v11);
          if ( count != 0 )
          {
            memset(dst: &a3[count * (v8 - *((_DWORD *)v4 + 19))], value: v11, count);
            v4 = this;
          }
          v10 = v16;
          ++v8;
        }
        if ( v10 == 0 )
          break;
        v12 = *v7;
        if ( v12 > v8 )
        {
          v13 = v6 << 9 >> 9;
          if ( v13 < 0 )
            v13 = -v13;
          if ( *(_DWORD *)v4 == 1 )
          {
            v13 &= 0x1FFu;
            if ( (unsigned int)v13 > 0x100 )
              v13 = 512 - v13;
          }
          if ( v13 > 255 )
            v13 = 255;
          if ( *((_DWORD *)v4 + 3) != 0 )
            v13 = *(_DWORD *)(*((_DWORD *)v4 + 2) + 4 * v13);
          if ( v13 != 0 )
          {
            memset(dst: &a3[count * (v8 - *((_DWORD *)v4 + 19))], value: v13, count: count * (v12 - v8));
            v4 = this;
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10189520
// Name: public: void GRasterizer::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRasterizer::Clear(GRasterizer *this)
{
  *((_DWORD *)this + 15) = 0x7FFFFFFF;
  *((_DWORD *)this + 16) = 0x7FFFFFFF;
  *((_DWORD *)this + 19) = 0x7FFFFFFF;
  *((_DWORD *)this + 20) = 0x7FFFFFFF;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 21) = -2147483647;
  *((_DWORD *)this + 22) = -2147483647;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 24) = 0;
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 26) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10189560
// Name: public: void GRasterizer::SetGamma(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRasterizer::SetGamma(GRasterizer *this, float a2)
{
  char *v2; // esi
  double v3; // st7
  int v4; // edi
  int v6; // [esp+Ch] [ebp-4h] BYREF

  if ( 1.0 == a2 )
  {
    *((_DWORD *)this + 3) = 0;
    *((float *)this + 1) = a2;
  }
  else
  {
    v2 = (char *)this + 8;
    if ( *((_DWORD *)this + 4) < 0x100u )
    {
      GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)v2);
      *((_DWORD *)v2 + 2) = 256;
      v6 = 134;
      *(_DWORD *)v2 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v2, a3: 1024, a4: &v6);
    }
    v3 = 255.0;
    v4 = 0;
    *((_DWORD *)v2 + 1) = 256;
    *(float *)&v6 = 0.0;
    do
    {
      *(float *)&v6 = (double)v6 / v3;
      *(float *)&v6 = pow(*(float *)&v6, a2);
      ++v4;
      v3 = 255.0;
      *(_DWORD *)(*(_DWORD *)v2 + 4 * v4 - 4) = (__int64)(*(float *)&v6 * 255.0 + 0.5);
      v6 = v4;
    }
    while ( v4 < 256 );
    *((float *)this + 1) = a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101896A0
// Name: public: GRasterizer::GRasterizer(void)
// Source: json
//------------------------------------------------------------------------------
GRasterizer *__thiscall GRasterizer::GRasterizer(GRasterizer *this)
{
  *((float *)this + 1) = 1.0;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 19) = 0x7FFFFFFF;
  *((_DWORD *)this + 20) = 0x7FFFFFFF;
  *((_DWORD *)this + 21) = -2147483647;
  *((_DWORD *)this + 22) = -2147483647;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 24) = 0;
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 15) = 0x7FFFFFFF;
  *((_DWORD *)this + 16) = 0x7FFFFFFF;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10189710
// Name: private: void GRasterizer::horLine(int,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRasterizer::horLine(GRasterizer *this, int a2, int a3, int a4, int a5, int a6)
{
  int v7; // edi
  int v8; // ecx
  int v9; // edx
  int v10; // eax
  int v11; // ebx
  int v12; // edx
  int v13; // ebx
  int v14; // edi
  int v15; // edx
  int v16; // ecx
  int v17; // eax
  int v18; // ebx
  int v19; // eax
  int v20; // et2
  int v21; // ecx
  int v22; // ebx
  int v23; // [esp+Ch] [ebp-18h]
  int v24; // [esp+10h] [ebp-14h]
  int v25; // [esp+14h] [ebp-10h]
  int v26; // [esp+18h] [ebp-Ch]
  int v27; // [esp+1Ch] [ebp-8h]
  int v28; // [esp+20h] [ebp-4h]
  int v29; // [esp+30h] [ebp+Ch]
  int v30; // [esp+30h] [ebp+Ch]
  int v31; // [esp+34h] [ebp+10h]
  int v32; // [esp+38h] [ebp+14h]

  v28 = a5 >> 8;
  v23 = (unsigned __int8)a5;
  v7 = a3 >> 8;
  v8 = (unsigned __int8)a3;
  if ( a4 == a6 )
  {
    if ( ((*((_DWORD *)this + 16) - a2) | (*((_DWORD *)this + 15) - v28)) != 0 )
    {
      if ( *(_QWORD *)((char *)this + 68) != 0 )
        GArrayPagedBase<GRasterizer::Cell,8,64,GAllocatorPagedLH_POD<GRasterizer::Cell,134>>::PushBack(
          this: (unsigned int *)this + 5,
          a2: (_DWORD *)this + 15);
      *((_DWORD *)this + 15) = v28;
      *((_DWORD *)this + 16) = a2;
      *((_DWORD *)this + 17) = 0;
      *((_DWORD *)this + 18) = 0;
    }
  }
  else
  {
    v9 = a6 - a4;
    if ( v7 == v28 )
    {
      *((_DWORD *)this + 17) += v9;
      *((_DWORD *)this + 18) += v9 * ((unsigned __int8)a3 + (unsigned __int8)a5);
    }
    else
    {
      v10 = v9 * (256 - (unsigned __int8)a3);
      v11 = a5 - a3;
      v26 = 256;
      v27 = 1;
      v32 = v11;
      if ( v11 < 0 )
      {
        v11 = -v11;
        v10 = (unsigned __int8)a3 * v9;
        v26 = 0;
        v27 = -1;
        v32 = v11;
      }
      v12 = v10 % v11;
      v13 = v10 / v11;
      v29 = v12;
      if ( v12 < 0 )
      {
        --v13;
        v29 = v32 + v12;
      }
      v14 = v27 + v7;
      *((_DWORD *)this + 17) += v13;
      v15 = v8 + v26;
      v16 = *((_DWORD *)this + 15);
      *((_DWORD *)this + 18) += v13 * v15;
      if ( ((*((_DWORD *)this + 16) - a2) | (v16 - v14)) != 0 )
      {
        if ( *(_QWORD *)((char *)this + 68) != 0 )
          GArrayPagedBase<GRasterizer::Cell,8,64,GAllocatorPagedLH_POD<GRasterizer::Cell,134>>::PushBack(
            this: (unsigned int *)this + 5,
            a2: (_DWORD *)this + 15);
        *((_DWORD *)this + 16) = a2;
        *((_DWORD *)this + 15) = v14;
        *((_DWORD *)this + 17) = 0;
        *((_DWORD *)this + 18) = 0;
      }
      v31 = v13 + a4;
      if ( v14 != v28 )
      {
        v17 = (a6 + v13 - v31) << 8;
        v18 = v32;
        v20 = v17 % v32;
        v19 = v17 / v32;
        v21 = v20;
        v25 = v19;
        v24 = v20;
        if ( v20 < 0 )
        {
          v25 = --v19;
          v24 = v32 + v21;
        }
        v30 = v29 - v32;
        while ( 1 )
        {
          v30 += v24;
          if ( v30 >= 0 )
          {
            v30 -= v18;
            ++v19;
          }
          *((_DWORD *)this + 17) += v19;
          v31 += v19;
          v14 += v27;
          v22 = *((_DWORD *)this + 16) - a2;
          *((_DWORD *)this + 18) += v19 << 8;
          if ( (v22 | (*((_DWORD *)this + 15) - v14)) != 0 )
          {
            if ( *(_QWORD *)((char *)this + 68) != 0 )
              GArrayPagedBase<GRasterizer::Cell,8,64,GAllocatorPagedLH_POD<GRasterizer::Cell,134>>::PushBack(
                this: (unsigned int *)this + 5,
                a2: (_DWORD *)this + 15);
            *((_DWORD *)this + 16) = a2;
            *((_DWORD *)this + 15) = v14;
            *((_DWORD *)this + 17) = 0;
            *((_DWORD *)this + 18) = 0;
          }
          if ( v14 == v28 )
            break;
          v18 = v32;
          v19 = v25;
        }
      }
      *((_DWORD *)this + 17) += a6 - v31;
      *((_DWORD *)this + 18) += (a6 - v31) * (v23 - v26 + 256);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10189900
// Name: private: void GRasterizer::line(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRasterizer::line(GRasterizer *this, int a2, int a3, int a4, int a5)
{
  int v7; // ecx
  int v8; // ebx
  int v9; // edx
  int v10; // edi
  int *v11; // ebx
  int v12; // edi
  int v13; // edx
  int v14; // edx
  unsigned int v15; // eax
  int *v16; // eax
  int v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // eax
  int v21; // edx
  int v22; // et2
  int v24; // edi
  int v25; // eax
  int v26; // ebx
  int v27; // eax
  int v28; // edx
  int v29; // ecx
  int v30; // ebx
  int v31; // eax
  int v32; // [esp+14h] [ebp-18h]
  unsigned int v33; // [esp+14h] [ebp-18h]
  int v34; // [esp+14h] [ebp-18h]
  int v35; // [esp+18h] [ebp-14h]
  int v36; // [esp+1Ch] [ebp-10h]
  int v37; // [esp+20h] [ebp-Ch]
  int v38; // [esp+20h] [ebp-Ch]
  int v39; // [esp+24h] [ebp-8h]
  int v40; // [esp+28h] [ebp-4h]
  int v41; // [esp+34h] [ebp+8h]
  int v42; // [esp+34h] [ebp+8h]
  int v43; // [esp+38h] [ebp+Ch]
  int v44; // [esp+38h] [ebp+Ch]
  int v45; // [esp+38h] [ebp+Ch]
  int v46; // [esp+40h] [ebp+14h]
  int v47; // [esp+40h] [ebp+14h]

  v32 = a4 - a2;
  v40 = a5 - a3;
  v46 = a4 >> 8;
  v7 = a2 >> 8;
  v8 = a5 >> 8;
  v9 = (unsigned __int8)a3;
  v10 = a3 >> 8;
  v43 = a2 >> 8;
  v36 = a5 >> 8;
  v37 = v9;
  v35 = (unsigned __int8)a5;
  if ( a2 >> 8 < *((_DWORD *)this + 19) )
    *((_DWORD *)this + 19) = v7;
  if ( v7 > *((_DWORD *)this + 21) )
    *((_DWORD *)this + 21) = v7;
  if ( v10 < *((_DWORD *)this + 20) )
    *((_DWORD *)this + 20) = v10;
  if ( v10 > *((_DWORD *)this + 22) )
    *((_DWORD *)this + 22) = v10;
  if ( v46 < *((_DWORD *)this + 19) )
    *((_DWORD *)this + 19) = v46;
  if ( v46 > *((_DWORD *)this + 21) )
    *((_DWORD *)this + 21) = v46;
  if ( v8 < *((_DWORD *)this + 20) )
    *((_DWORD *)this + 20) = v8;
  if ( v8 > *((_DWORD *)this + 22) )
    *((_DWORD *)this + 22) = v8;
  v11 = (int *)((char *)this + 60);
  if ( ((*((_DWORD *)this + 15) - v7) | (*((_DWORD *)this + 16) - v10)) != 0 )
  {
    if ( *(_QWORD *)((char *)this + 68) != 0 )
    {
      GArrayPagedBase<GRasterizer::Cell,8,64,GAllocatorPagedLH_POD<GRasterizer::Cell,134>>::PushBack(
        this: (unsigned int *)this + 5,
        a2: (_DWORD *)this + 15);
      v7 = a2 >> 8;
    }
    *v11 = v7;
    *((_DWORD *)this + 16) = v10;
    *((_DWORD *)this + 17) = 0;
    *((_DWORD *)this + 18) = 0;
  }
  if ( v10 == v36 )
  {
    GRasterizer::horLine(this, a2: v10, a3: a2, a4: v37, a5: a4, a6: v35);
  }
  else
  {
    v39 = 1;
    v47 = 256;
    if ( v32 != 0 )
    {
      v18 = v40;
      v19 = v32 * (256 - v37);
      if ( v40 < 0 )
      {
        v19 = v32 * v37;
        v18 = -v40;
        v47 = 0;
        v39 = -1;
        v40 = -v40;
      }
      v22 = v19 % v18;
      v20 = v19 / v18;
      v21 = v22;
      v44 = v22;
      if ( v22 < 0 )
      {
        --v20;
        v44 = v18 + v21;
      }
      v42 = a2 + v20;
      GRasterizer::horLine(this, a2: v10, a3: a2, a4: v37, a5: v42, a6: v47);
      v24 = v39 + v10;
      v25 = v42 >> 8;
      if ( ((*((_DWORD *)this + 16) - v24) | (*v11 - (v42 >> 8))) != 0 )
      {
        if ( *(_QWORD *)((char *)this + 68) != 0 )
        {
          GArrayPagedBase<GRasterizer::Cell,8,64,GAllocatorPagedLH_POD<GRasterizer::Cell,134>>::PushBack(
            this: (unsigned int *)this + 5,
            a2: (_DWORD *)this + 15);
          v25 = v42 >> 8;
        }
        *v11 = v25;
        *((_DWORD *)this + 16) = v24;
        *((_DWORD *)this + 17) = 0;
        *((_DWORD *)this + 18) = 0;
      }
      if ( v24 != v36 )
      {
        v26 = v40;
        v27 = (v32 << 8) / v40;
        v28 = (v32 << 8) % v40;
        v34 = v27;
        v38 = v28;
        if ( v28 < 0 )
        {
          v34 = --v27;
          v38 = v40 + v28;
        }
        v45 = v44 - v40;
        v29 = 256 - v47;
        while ( 1 )
        {
          v45 += v38;
          if ( v45 >= 0 )
          {
            v45 -= v26;
            ++v27;
          }
          v30 = v27 + v42;
          GRasterizer::horLine(this, a2: v24, a3: v42, a4: v29, a5: v27 + v42, a6: v47);
          v24 += v39;
          v42 = v30;
          v31 = v30 >> 8;
          if ( ((*((_DWORD *)this + 16) - v24) | (*((_DWORD *)this + 15) - (v30 >> 8))) != 0 )
          {
            if ( *(_QWORD *)((char *)this + 68) != 0 )
            {
              GArrayPagedBase<GRasterizer::Cell,8,64,GAllocatorPagedLH_POD<GRasterizer::Cell,134>>::PushBack(
                this: (unsigned int *)this + 5,
                a2: (_DWORD *)this + 15);
              v31 = v30 >> 8;
            }
            *((_DWORD *)this + 15) = v31;
            *((_DWORD *)this + 16) = v24;
            *((_DWORD *)this + 17) = 0;
            *((_DWORD *)this + 18) = 0;
          }
          if ( v24 == v36 )
            break;
          v29 = 256 - v47;
          v27 = v34;
          v26 = v40;
        }
      }
      GRasterizer::horLine(this, a2: v24, a3: v42, a4: 256 - v47, a5: a4, a6: v35);
    }
    else
    {
      v41 = 2 * (a2 - (v7 << 8));
      if ( v40 < 0 )
      {
        v47 = 0;
        v39 = -1;
      }
      v12 = v39 + v10;
      *((_DWORD *)this + 17) += v47 - v37;
      *((_DWORD *)this + 18) += v41 * (v47 - v37);
      if ( ((*((_DWORD *)this + 16) - v12) | (*v11 - v7)) != 0 )
      {
        if ( *(_QWORD *)((char *)this + 68) != 0 )
        {
          GArrayPagedBase<GRasterizer::Cell,8,64,GAllocatorPagedLH_POD<GRasterizer::Cell,134>>::PushBack(
            this: (unsigned int *)this + 5,
            a2: (_DWORD *)this + 15);
          v7 = v43;
        }
        *v11 = v7;
        *((_DWORD *)this + 16) = v12;
        *((_DWORD *)this + 17) = 0;
        *((_DWORD *)this + 18) = 0;
      }
      v13 = v41 * (2 * v47 - 256);
      if ( v12 != v36 )
      {
        while ( 1 )
        {
          v12 += v39;
          *((_DWORD *)this + 18) = v13;
          v14 = *v11;
          *((_DWORD *)this + 17) = 2 * v47 - 256;
          if ( ((*((_DWORD *)this + 16) - v12) | (v14 - v7)) != 0 )
          {
            if ( ((2 * v47 - 256) | (v41 * (2 * v47 - 256))) != 0 )
            {
              v15 = *((_DWORD *)this + 5) >> 8;
              v33 = v15;
              if ( v15 >= *((_DWORD *)this + 6) )
              {
                GArrayPagedBase<GRasterizer::Cell,8,64,GAllocatorPagedLH_POD<GRasterizer::Cell,134>>::allocatePage(
                  this: (unsigned int *)this + 5,
                  a2: v15);
                v15 = v33;
              }
              v16 = (int *)(16 * (unsigned __int8)*((_DWORD *)this + 5) + *(_DWORD *)(*((_DWORD *)this + 8) + 4 * v15));
              *v16 = *v11;
              v16[1] = *((_DWORD *)this + 16);
              v16[2] = *((_DWORD *)this + 17);
              v7 = v43;
              v16[3] = *((_DWORD *)this + 18);
              ++*((_DWORD *)this + 5);
            }
            *v11 = v7;
            *((_DWORD *)this + 16) = v12;
            *((_DWORD *)this + 17) = 0;
            *((_DWORD *)this + 18) = 0;
          }
          if ( v12 == v36 )
            break;
          v13 = v41 * (2 * v47 - 256);
        }
      }
      v17 = v47 + v35 - 256;
      *((_DWORD *)this + 17) += v17;
      *((_DWORD *)this + 18) += v41 * v17;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10189CA0
// Name: public: bool GRasterizer::SortCells(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GRasterizer::SortCells(GRasterizer *this)
{
  unsigned int v2; // ebx
  _DWORD *v3; // eax
  unsigned int v4; // ebx
  unsigned int v6; // ebx
  unsigned int i; // eax
  int v8; // ecx
  unsigned int v9; // eax
  int j; // edx
  int v11; // ecx
  int v12; // ebx
  unsigned int v13; // eax
  int v14; // eax
  _DWORD *v15; // ecx
  _BYTE *v16; // eax
  unsigned int m; // ebx
  int v18; // eax
  _BYTE *v19; // ecx
  _DWORD *v20; // eax
  int v21; // [esp+Ch] [ebp-8h] BYREF
  _BYTE *k; // [esp+10h] [ebp-4h]

  if ( *(_QWORD *)((char *)this + 68) != 0 )
  {
    v2 = *((_DWORD *)this + 5) >> 8;
    if ( v2 >= *((_DWORD *)this + 6) )
      GArrayPagedBase<GRasterizer::Cell,8,64,GAllocatorPagedLH_POD<GRasterizer::Cell,134>>::allocatePage(
        this: (unsigned int *)this + 5,
        a2: *((_DWORD *)this + 5) >> 8);
    v3 = (_DWORD *)(16 * (unsigned __int8)*((_DWORD *)this + 5) + *(_DWORD *)(*((_DWORD *)this + 8) + 4 * v2));
    *v3 = *((_DWORD *)this + 15);
    v3[1] = *((_DWORD *)this + 16);
    v3[2] = *((_DWORD *)this + 17);
    v3[3] = *((_DWORD *)this + 18);
    ++*((_DWORD *)this + 5);
  }
  v4 = *((_DWORD *)this + 5);
  *((_DWORD *)this + 15) = 0x7FFFFFFF;
  *((_DWORD *)this + 16) = 0x7FFFFFFF;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  if ( v4 == 0 )
    return 0;
  if ( *((_DWORD *)this + 13) == 0 )
  {
    GArrayUnsafeBase<GRasterizer::Cell *,GAllocatorLH_POD<GRasterizer::Cell *,134>>::Reserve(
      this: (int)this + 36,
      a2: v4,
      a3: 256);
    *((_DWORD *)this + 10) = v4;
    v6 = *((_DWORD *)this + 22) - *((_DWORD *)this + 20) + 1;
    GArrayUnsafeBase<GRasterizer::SortedY,GAllocatorLH_POD<GRasterizer::SortedY,134>>::Reserve(
      this: (int)this + 48,
      a2: v6,
      a3: 16);
    *((_DWORD *)this + 13) = v6;
    memset(dst: *((unsigned __int8 **)this + 12), value: 0, count: 8 * v6);
    for ( i = 0; i < *((_DWORD *)this + 5); ++i )
    {
      v8 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 8) + 4 * (i >> 8)) + 16 * (unsigned __int8)i + 4)
         - *((_DWORD *)this + 20);
      ++*(_DWORD *)(*((_DWORD *)this + 12) + 8 * v8);
    }
    v9 = 0;
    for ( j = 0; v9 < *((_DWORD *)this + 13); j += v12 )
    {
      v11 = *((_DWORD *)this + 12);
      v12 = *(_DWORD *)(v11 + 8 * v9);
      *(_DWORD *)(v11 + 8 * v9++) = j;
    }
    v13 = 0;
    for ( k = nullptr; v13 < *((_DWORD *)this + 5); k = (_BYTE *)v13 )
    {
      v14 = *(_DWORD *)(*((_DWORD *)this + 8) + 4 * (v13 >> 8)) + 16 * (unsigned __int8)v13;
      v15 = (_DWORD *)(*((_DWORD *)this + 12) + 8 * (*(_DWORD *)(v14 + 4) - *((_DWORD *)this + 20)));
      *(_DWORD *)(*((_DWORD *)this + 9) + 4 * (v15[1] + *v15)) = v14;
      v16 = k;
      ++v15[1];
      v13 = (unsigned int)(v16 + 1);
    }
    for ( m = 0; m < *((_DWORD *)this + 13); ++m )
    {
      v18 = *((_DWORD *)this + 12);
      v19 = *(_BYTE **)(v18 + 8 * m + 4);
      v20 = (_DWORD *)(v18 + 8 * m);
      if ( v19 != nullptr )
      {
        v21 = *((_DWORD *)this + 9) + 4 * *v20;
        k = v19;
        G_QuickSortSliced<GArrayUnsafeLH_POD<GTessellator::MonoChainType *,133>,bool (__cdecl *)(GTessellator::MonoChainType const *,GTessellator::MonoChainType const *)>(
          a1: &v21,
          a2: 0,
          a3: v19,
          a4: (unsigned __int8 (__cdecl *)(int, int))GRasterizer::cellXLess);
      }
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10189E40
// Name: public: void GRasterizer::LineTo(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRasterizer::LineTo(GRasterizer *this, float a2, float a3)
{
  int v4; // edi
  int v5; // ebx

  v4 = (int)(a2 * 256.0);
  v5 = (int)(256.0 * a3);
  GRasterizer::line(this, a2: *((_DWORD *)this + 25), a3: *((_DWORD *)this + 26), a4: v4, a5: v5);
  *((_DWORD *)this + 25) = v4;
  *((_DWORD *)this + 26) = v5;
}

//------------------------------------------------------------------------------
// Address: 0x10189E90
// Name: public: void GRasterizer::ClosePolygon(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRasterizer::ClosePolygon(GRasterizer *this)
{
  int v2; // edx

  GRasterizer::line(
    this,
    a2: *((_DWORD *)this + 25),
    a3: *((_DWORD *)this + 26),
    a4: *((_DWORD *)this + 23),
    a5: *((_DWORD *)this + 24));
  v2 = *((_DWORD *)this + 24);
  *((_DWORD *)this + 25) = *((_DWORD *)this + 23);
  *((_DWORD *)this + 26) = v2;
}

//------------------------------------------------------------------------------
// Address: 0x10189EC0
// Name: public: void GRasterizer::AddShapeScaled(class GCompoundShape const __near &,float,float,float,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRasterizer::AddShapeScaled(
        GRasterizer *this,
        const struct GCompoundShape *a2,
        float a3,
        float a4,
        float a5,
        float a6,
        int a7)
{
  const struct GCompoundShape *v8; // ecx
  unsigned int v9; // eax
  double v10; // st7
  _DWORD *v11; // edi
  int v12; // eax
  int v13; // ecx
  int v14; // ecx
  int v15; // eax
  int v16; // eax
  int v17; // ebx
  int v18; // ecx
  int v19; // eax
  int v20; // eax
  unsigned int v21; // eax
  int v22; // ebx
  int v23; // [esp+4h] [ebp-14h]
  float v24; // [esp+4h] [ebp-14h]
  float v25; // [esp+8h] [ebp-10h]
  float v26; // [esp+8h] [ebp-10h]
  float v27; // [esp+8h] [ebp-10h]
  unsigned int v28; // [esp+Ch] [ebp-Ch]
  float v29; // [esp+10h] [ebp-8h]
  float v30; // [esp+10h] [ebp-8h]
  int v31; // [esp+10h] [ebp-8h]
  float v32; // [esp+10h] [ebp-8h]
  int v33; // [esp+10h] [ebp-8h]
  float v34; // [esp+14h] [ebp-4h]
  unsigned int i; // [esp+14h] [ebp-4h]
  unsigned int v36; // [esp+14h] [ebp-4h]

  v8 = a2;
  v9 = 0;
  v28 = 0;
  if ( *((_DWORD *)a2 + 6) != 0 )
  {
    v10 = 256.0;
    do
    {
      v11 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)v8 + 9) + 4 * (v9 >> 6)) + 24 * (v9 & 0x3F));
      v12 = v11[3];
      if ( v12 == v11[4] )
        goto LABEL_19;
      v13 = a7;
      if ( a7 < 0 )
      {
        if ( v12 < 0 )
          goto LABEL_11;
      }
      else if ( v12 != a7 )
      {
        goto LABEL_12;
      }
      v14 = *(_DWORD *)(*v11 + 20);
      v34 = *(float *)(*(_DWORD *)(v14 + 4 * (v11[2] >> 8)) + 8 * (unsigned __int8)v11[2] + 4) * a4 + a6;
      v29 = *(float *)(*(_DWORD *)(v14 + 4 * (v11[2] >> 8)) + 8 * (unsigned __int8)v11[2]) * a3 + a5;
      v15 = (int)(v29 * v10);
      *((_DWORD *)this + 25) = v15;
      *((_DWORD *)this + 23) = v15;
      v16 = (int)(v34 * v10);
      *((_DWORD *)this + 26) = v16;
      *((_DWORD *)this + 24) = v16;
      for ( i = 1; i < v11[1]; ++i )
      {
        v30 = *(float *)(*(_DWORD *)(*(_DWORD *)(*v11 + 20) + 4 * ((i + v11[2]) >> 8))
                       + 8 * (unsigned __int8)(i + *((_BYTE *)v11 + 8)))
            * a3
            + a5;
        v31 = (int)(v30 * v10);
        v25 = *(float *)(*(_DWORD *)(*(_DWORD *)(*v11 + 20) + 4 * ((i + v11[2]) >> 8))
                       + 8 * (unsigned __int8)(i + *((_BYTE *)v11 + 8))
                       + 4)
            * a4
            + a6;
        v17 = (int)(v10 * v25);
        GRasterizer::line(this, a2: *((_DWORD *)this + 25), a3: *((_DWORD *)this + 26), a4: v31, a5: v17);
        v10 = 256.0;
        *((_DWORD *)this + 25) = v31;
        *((_DWORD *)this + 26) = v17;
      }
      v13 = a7;
LABEL_11:
      if ( v13 < 0 )
        goto LABEL_14;
LABEL_12:
      if ( v11[4] == v13 )
        goto LABEL_15;
      if ( v13 < 0 )
      {
LABEL_14:
        if ( (int)v11[4] >= 0 )
        {
LABEL_15:
          v18 = *(_DWORD *)(*v11 + 20);
          v32 = *(float *)(*(_DWORD *)(v18 + 4 * ((unsigned int)(v11[2] + v11[1] - 1) >> 8))
                         + 8 * (unsigned __int8)(*((_BYTE *)v11 + 8) + *((_BYTE *)v11 + 4) - 1)
                         + 4)
              * a4
              + a6;
          v26 = *(float *)(*(_DWORD *)(v18 + 4 * ((unsigned int)(v11[2] + v11[1] - 1) >> 8))
                         + 8 * (unsigned __int8)(*((_BYTE *)v11 + 8) + *((_BYTE *)v11 + 4) - 1))
              * a3
              + a5;
          v19 = (int)(v26 * v10);
          *((_DWORD *)this + 25) = v19;
          *((_DWORD *)this + 23) = v19;
          v20 = (int)(v32 * v10);
          *((_DWORD *)this + 26) = v20;
          *((_DWORD *)this + 24) = v20;
          v21 = v11[1];
          v36 = v21;
          if ( v21 > 1 )
          {
            while ( 1 )
            {
              v23 = *(_DWORD *)(*v11 + 20);
              v27 = *(float *)(*(_DWORD *)(v23 + 4 * ((v11[2] + v21 - 2) >> 8))
                             + 8 * (unsigned __int8)(*((_BYTE *)v11 + 8) + v21 - 2))
                  * a3
                  + a5;
              v33 = (int)(v27 * v10);
              v24 = *(float *)(*(_DWORD *)(v23 + 4 * ((v11[2] + v21 - 2) >> 8))
                             + 8 * (unsigned __int8)(*((_BYTE *)v11 + 8) + v21 - 2)
                             + 4)
                  * a4
                  + a6;
              v22 = (int)(v10 * v24);
              GRasterizer::line(this, a2: *((_DWORD *)this + 25), a3: *((_DWORD *)this + 26), a4: v33, a5: v22);
              v10 = 256.0;
              *((_DWORD *)this + 25) = v33;
              *((_DWORD *)this + 26) = v22;
              if ( --v36 <= 1 )
                break;
              v21 = v36;
            }
          }
        }
      }
LABEL_19:
      v8 = a2;
      v9 = v28 + 1;
      v28 = v9;
    }
    while ( v9 < *((_DWORD *)a2 + 6) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1018A170
// Name: public: void GRasterizer::AddShape(class GCompoundShape const __near &,float,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GRasterizer::AddShape(GRasterizer *this, const struct GCompoundShape *a2, float a3, int a4)
{
  GRasterizer::AddShapeScaled(this, a2, a3, a4: a3, a5: 0.0, a6: 0.0, a7: a4);
}
