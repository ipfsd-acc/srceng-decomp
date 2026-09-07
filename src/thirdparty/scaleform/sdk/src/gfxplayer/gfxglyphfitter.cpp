// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxglyphfitter.cpp
// Functions: 362
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxglyphfitter.h"

//------------------------------------------------------------------------------
// Address: 0x1019BEE0
// Name: private: void GFxGlyphFitter::removeDuplicateClosures(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphFitter::removeDuplicateClosures(GFxGlyphFitter *this)
{
  unsigned int v1; // eax
  _DWORD *v2; // esi
  unsigned int v3; // edi
  int v4; // edx
  _WORD *v5; // ecx
  _WORD *v6; // eax
  GFxGlyphFitter *v7; // [esp+0h] [ebp-8h]
  unsigned int i; // [esp+4h] [ebp-4h]

  v1 = 0;
  v7 = this;
  for ( i = 0; v1 < *((_DWORD *)this + 1); i = v1 )
  {
    v2 = (_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 4) + 4 * (v1 >> 4)) + 8 * (v1 & 0xF));
    v3 = v2[1];
    if ( v3 > 2 )
    {
      v4 = *((_DWORD *)this + 8);
      v5 = (_WORD *)(*(_DWORD *)(v4 + 4 * (*v2 >> 6)) + 4 * (*v2 & 0x3F));
      v6 = (_WORD *)(*(_DWORD *)(v4 + 4 * ((*v2 + v3 - 1) >> 6)) + 4 * ((*v2 + v3 - 1) & 0x3F));
      if ( *v5 == *v6 && v5[1] == v6[1] )
        v2[1] = v3 - 1;
      this = v7;
      v1 = i;
    }
    ++v1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019BF70
// Name: private: void GFxGlyphFitter::computeBounds(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphFitter::computeBounds(GFxGlyphFitter *this)
{
  unsigned int v1; // esi
  int v2; // eax
  int v3; // edi
  unsigned int v4; // edx
  unsigned int *v5; // eax
  unsigned int v6; // esi
  int v7; // eax
  __int16 *v8; // edi
  __int16 v9; // dx
  __int16 v10; // si
  int v11; // ebx
  int v12; // edx
  bool v13; // zf
  unsigned int v14; // [esp+4h] [ebp-20h]
  unsigned int v15; // [esp+8h] [ebp-1Ch]
  unsigned int i; // [esp+Ch] [ebp-18h]
  int v17; // [esp+10h] [ebp-14h]
  __int16 v18; // [esp+14h] [ebp-10h]
  __int16 v19; // [esp+18h] [ebp-Ch]
  __int16 v20; // [esp+1Ch] [ebp-8h]
  __int16 v21; // [esp+20h] [ebp-4h]

  *((_WORD *)this + 44) = 0x7FFF;
  v1 = 0;
  v18 = 0x7FFF;
  v21 = 0x7FFF;
  *((_WORD *)this + 45) = 0x7FFF;
  v20 = -32767;
  v19 = -32767;
  *((_WORD *)this + 46) = -32767;
  *((_WORD *)this + 47) = -32767;
  for ( i = 0; v1 < *((_DWORD *)this + 1); i = v1 )
  {
    v2 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * (v1 >> 4));
    v3 = v1 & 0xF;
    v4 = *(_DWORD *)(v2 + 8 * v3 + 4);
    v5 = (unsigned int *)(v2 + 8 * v3);
    if ( v4 > 2 )
    {
      v6 = *v5;
      v7 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 8) + 4 * ((*v5 + v4 - 1) >> 6)) + 4 * ((*v5 + v4 - 1) & 0x3F));
      v17 = 0;
      v15 = v6;
      v14 = v4;
      do
      {
        v8 = (__int16 *)(*(_DWORD *)(*((_DWORD *)this + 8) + 4 * (v6 >> 6)) + 4 * (v6 & 0x3F));
        v9 = *v8;
        if ( *v8 < v18 )
          v18 = *v8;
        v10 = v8[1];
        if ( v10 < v21 )
          v21 = v8[1];
        if ( v9 > v20 )
          v20 = *v8;
        if ( v10 > v19 )
          v19 = v8[1];
        v11 = v9 * SHIWORD(v7);
        v12 = (__int16)v7 * v10;
        v7 = *(_DWORD *)v8;
        v17 += v12 - v11;
        v6 = v15 + 1;
        v13 = v14-- == 1;
        ++v15;
      }
      while ( !v13 );
      v1 = i;
      if ( v18 < *((__int16 *)this + 44)
        || v21 < *((__int16 *)this + 45)
        || v20 > *((__int16 *)this + 46)
        || v19 > *((__int16 *)this + 47) )
      {
        *((_WORD *)this + 46) = v20;
        *((_WORD *)this + 44) = v18;
        *((_WORD *)this + 45) = v21;
        *((_WORD *)this + 47) = v19;
        *((_DWORD *)this + 24) = (v17 > 0) + 1;
      }
    }
    ++v1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019C160
// Name: public: void GFxGlyphFitter::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphFitter::Clear(GFxGlyphFitter *this)
{
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 20) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1019C170
// Name: private: void GFxGlyphFitter::detectEvents(enum GFxGlyphFitter::FitDir)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxGlyphFitter::detectEvents(int this, int a2)
{
  _DWORD *v2; // esi
  __int16 v3; // ax
  int v4; // edi
  unsigned int v5; // edi
  void **v6; // ebx
  void *v7; // eax
  unsigned int result; // eax
  int v9; // edx
  int v10; // edi
  _DWORD *v11; // edx
  int v12; // ebx
  int v13; // ecx
  int v14; // esi
  unsigned int v15; // edi
  unsigned int v16; // ebx
  int v17; // edx
  __int16 v18; // bx
  int v19; // edx
  __int16 v20; // cx
  __int16 v21; // ax
  __int16 v22; // di
  __int16 v23; // si
  char v24; // dl
  int v25; // ecx
  _DWORD *v26; // eax
  bool v27; // cc
  signed __int16 v28; // di
  int v29; // [esp+Ch] [ebp-20h] BYREF
  _DWORD *v30; // [esp+10h] [ebp-1Ch]
  int v31; // [esp+14h] [ebp-18h]
  int v32; // [esp+18h] [ebp-14h]
  int v33; // [esp+1Ch] [ebp-10h]
  int v34; // [esp+20h] [ebp-Ch]
  _DWORD *v35; // [esp+24h] [ebp-8h]
  int v36; // [esp+28h] [ebp-4h]

  v2 = (_DWORD *)this;
  v35 = (_DWORD *)this;
  if ( a2 == 1 )
    v3 = *(_WORD *)(this + 88);
  else
    v3 = *(_WORD *)(this + 90);
  v31 = v3;
  if ( a2 == 1 )
    v4 = *(__int16 *)(this + 92) - *(__int16 *)(this + 88);
  else
    v4 = *(__int16 *)(this + 94) - *(__int16 *)(this + 90);
  v5 = v4 + 1;
  v6 = (void **)(this + 36);
  if ( v5 > *(_DWORD *)(this + 44) )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *v6);
    v2[11] = v5;
    if ( v5 != 0 )
    {
      v29 = 2;
      v7 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v2 + 9, a3: v5, a4: &v29);
    }
    else
    {
      v7 = nullptr;
    }
    *v6 = v7;
  }
  v2[10] = v5;
  memset(dst: (unsigned __int8 *)*v6, value: 0, count: v5);
  result = 0;
  v29 = 0;
  if ( v2[1] != 0 )
  {
    while ( 1 )
    {
      v9 = *(_DWORD *)(v2[4] + 4 * (result >> 4));
      v10 = result & 0xF;
      v27 = *(_DWORD *)(v9 + 8 * v10 + 4) <= 2u;
      v11 = (_DWORD *)(v9 + 8 * v10);
      v30 = v11;
      if ( !v27 )
      {
        v12 = 0;
        *(_BYTE *)v2[9] = 3;
        v33 = 0;
        if ( v11[1] != 0 )
          break;
      }
LABEL_39:
      v29 = ++result;
      if ( result >= v2[1] )
        return result;
    }
    while ( 1 )
    {
      v13 = *v11;
      v14 = v2[8];
      v15 = v11[1];
      v36 = *(_DWORD *)(*(_DWORD *)(v14 + 4 * ((unsigned int)(*v11 + v12) >> 6)) + 4 * ((*v11 + v12) & 0x3F));
      v16 = v12 + 2;
      v32 = *(_DWORD *)(*(_DWORD *)(v14 + 4 * ((v13 + (v16 - 1) % v15) >> 6)) + 4 * ((v13 + (v16 - 1) % v15) & 0x3F));
      v17 = v16 % v15;
      v18 = v32;
      v19 = *(_DWORD *)(*(_DWORD *)(v14 + 4 * ((unsigned int)(v13 + v17) >> 6)) + 4 * ((v13 + v17) & 0x3F));
      v34 = v19;
      if ( a2 == 1 )
      {
        v20 = v36;
        v21 = v34;
        v22 = -HIWORD(v19);
        HIWORD(v36) = v36;
        v23 = v32;
        LOWORD(v36) = -HIWORD(v19);
      }
      else
      {
        v22 = v36;
        v23 = HIWORD(v32);
        v21 = HIWORD(v34);
        v20 = HIWORD(v36);
      }
      v24 = 0;
      if ( v20 >= v23 )
      {
        if ( v21 >= v23 )
          goto LABEL_24;
        if ( v20 > v23 )
          goto LABEL_41;
      }
      if ( v21 > v23 )
      {
LABEL_41:
        v26 = v35;
        goto LABEL_32;
      }
LABEL_24:
      v25 = v23 - v31;
      if ( v22 > (__int16)v32 || (__int16)v32 > (__int16)v34 )
      {
        v26 = v35;
      }
      else
      {
        v26 = v35;
        *(_BYTE *)(v35[9] + v25) |= (v35[24] == 1) + 1;
        v22 = v36;
        v24 = 1;
      }
      if ( v22 >= v18 && v18 >= (__int16)v34 )
      {
LABEL_36:
        *(_BYTE *)(v25 + v26[9]) |= (v26[24] != 1) + 1;
        goto LABEL_37;
      }
      if ( v24 == 0 )
      {
        v20 = HIWORD(v36);
LABEL_32:
        if ( v20 == v23 )
        {
          v25 = v23 - v31;
          v27 = v22 <= v18;
          if ( v22 < v18 )
          {
            v28 = v36;
            *(_BYTE *)(v26[9] + v25) |= (v26[24] == 1) + 1;
            v27 = v28 <= v18;
          }
          if ( !v27 )
            goto LABEL_36;
        }
      }
LABEL_37:
      v2 = v35;
      if ( (unsigned int)++v33 >= v30[1] )
      {
        result = v29;
        goto LABEL_39;
      }
      v11 = v30;
      v12 = v33;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019C3F0
// Name: public: void GFxGlyphFitter::MoveTo(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphFitter::MoveTo(GFxGlyphFitter *this, int a2, __int16 a3)
{
  _DWORD *v3; // esi
  unsigned int *v4; // edi
  unsigned int v5; // ebx
  int v6; // ebx
  int v7; // eax
  unsigned int v8; // esi
  int v9; // [esp+Ch] [ebp-8h]

  v3 = (_DWORD *)((char *)this + 4);
  v4 = (unsigned int *)((char *)this + 20);
  v9 = *((_DWORD *)this + 5);
  v5 = *((_DWORD *)this + 1) >> 4;
  HIWORD(a2) = a3;
  if ( v5 >= *((_DWORD *)this + 2) )
    GArrayPagedBase<GRectPacker::PackType,4,16,GAllocatorPagedLH_POD<GRectPacker::PackType,2>>::allocatePage(
      this: (unsigned int *)this + 1,
      a2: v5);
  v6 = *(_DWORD *)(v3[3] + 4 * v5);
  v7 = *v3 & 0xF;
  *(_DWORD *)(v6 + 8 * v7) = v9;
  *(_DWORD *)(v6 + 8 * v7 + 4) = 1;
  ++*v3;
  v8 = *v4 >> 6;
  if ( v8 >= v4[1] )
    GArrayPagedBase<GFxGlyphFitter::VertexType,6,16,GAllocatorPagedLH_POD<GFxGlyphFitter::VertexType,2>>::allocatePage(
      this: v4,
      a2: *v4 >> 6);
  *(_DWORD *)(*(_DWORD *)(v4[3] + 4 * v8) + 4 * ((*v4)++ & 0x3F)) = a2;
}

//------------------------------------------------------------------------------
// Address: 0x1019C480
// Name: public: void GFxGlyphFitter::LineTo(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphFitter::LineTo(GFxGlyphFitter *this, int a2, __int16 a3)
{
  _WORD *v4; // eax
  unsigned int v5; // ebx
  int v6; // ecx

  v4 = (_WORD *)(*(_DWORD *)(*((_DWORD *)this + 8) + 4 * ((unsigned int)(*((_DWORD *)this + 5) - 1) >> 6))
               + 4 * ((*((_DWORD *)this + 5) - 1) & 0x3F));
  HIWORD(a2) = a3;
  if ( (_WORD)a2 != *v4 || a3 != v4[1] )
  {
    v5 = *((_DWORD *)this + 5) >> 6;
    if ( v5 >= *((_DWORD *)this + 6) )
      GArrayPagedBase<GFxGlyphFitter::VertexType,6,16,GAllocatorPagedLH_POD<GFxGlyphFitter::VertexType,2>>::allocatePage(
        this: (unsigned int *)this + 5,
        a2: *((_DWORD *)this + 5) >> 6);
    *(_DWORD *)(*(_DWORD *)(*((_DWORD *)this + 8) + 4 * v5) + 4 * ((*((_DWORD *)this + 5))++ & 0x3F)) = a2;
    v6 = *(_DWORD *)(*((_DWORD *)this + 4) + 4 * ((unsigned int)(*((_DWORD *)this + 1) - 1) >> 4));
    ++*(_DWORD *)(v6 + 8 * ((*((_DWORD *)this + 1) - 1) & 0xF) + 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019C500
// Name: private: void GFxGlyphFitter::computeLerpRamp(enum GFxGlyphFitter::FitDir,int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxGlyphFitter::computeLerpRamp(int this, int a2, int a3, int a4, int a5, unsigned int a6)
{
  int v6; // ebx
  unsigned int *v7; // esi
  __int16 v8; // ax
  unsigned int v9; // edi
  int v10; // edx
  int v12; // ecx
  __int16 v13; // ax
  int v14; // ecx
  unsigned int v15; // eax
  int v16; // ebx
  char v17; // al
  int v18; // eax
  unsigned int v19; // eax
  int v20; // eax
  unsigned int v21; // eax
  unsigned int v22; // edi
  int v23; // edi
  unsigned int v24; // eax
  void *v25; // eax
  bool v26; // zf
  int *v27; // eax
  unsigned int v28; // edx
  unsigned int result; // eax
  int v30; // eax
  int v31; // [esp+Ch] [ebp-1Ch]
  int v32; // [esp+10h] [ebp-18h]
  int v33; // [esp+14h] [ebp-14h]
  int v35; // [esp+1Ch] [ebp-Ch]
  unsigned int v36; // [esp+1Ch] [ebp-Ch]
  unsigned int v37; // [esp+1Ch] [ebp-Ch]
  int v38; // [esp+20h] [ebp-8h]
  int v39; // [esp+24h] [ebp-4h] BYREF
  unsigned int v40; // [esp+30h] [ebp+8h]
  int v41; // [esp+30h] [ebp+8h]
  unsigned int v42; // [esp+34h] [ebp+Ch]
  unsigned int v43; // [esp+34h] [ebp+Ch]
  unsigned int v44; // [esp+38h] [ebp+10h]
  unsigned int v45; // [esp+3Ch] [ebp+14h]

  v6 = this;
  v7 = (unsigned int *)(this + 48);
  v8 = -*(_WORD *)(this + 108);
  *(_DWORD *)(this + 48) = 0;
  v9 = *(_DWORD *)(this + 48) >> 6;
  LOWORD(v39) = 4 * v8;
  HIWORD(v39) = 4 * v8;
  if ( v9 >= *(_DWORD *)(this + 52) )
    GArrayPagedBase<GFxGlyphFitter::VertexType,6,16,GAllocatorPagedLH_POD<GFxGlyphFitter::VertexType,2>>::allocatePage(
      this: (unsigned int *)(this + 48),
      a2: v9);
  v10 = *(_DWORD *)(v7[3] + 4 * v9);
  *(_DWORD *)(v10 + 4 * ((*v7)++ & 0x3F)) = v39;
  v12 = *(_DWORD *)(v6 + 108);
  v38 = -32767;
  v32 = a3 * ((a5 + v12 + a3) / a3) - v12;
  v33 = a3 * ((int)(a6 + v12 + a3) / a3) - v12;
  if ( a2 == 1 )
    v13 = *(_WORD *)(v6 + 88);
  else
    v13 = *(_WORD *)(v6 + 90);
  v14 = v13;
  v15 = 0;
  v31 = v14;
  v42 = 0;
  if ( *(_DWORD *)(v6 + 40) != 0 )
  {
    v16 = v14;
    v35 = v14;
    while ( 1 )
    {
      v17 = *(_BYTE *)(v15 + *(_DWORD *)(this + 36));
      if ( v16 <= a4 || a2 == 1 )
        break;
      if ( (v17 & 2) != 0 )
      {
        if ( a6 != 0 )
        {
          if ( v16 >= (int)a6 && v16 < (int)(a3 + a6 + 1) )
          {
            if ( (v16 <= a3 + v38 + 1
               || a3 + *(__int16 *)(*(_DWORD *)(v7[3] + 4 * ((*v7 - 1) >> 6)) + 4 * ((*v7 - 1) & 0x3F) + 2) >= v33)
              && *v7 != 0 )
            {
              --*v7;
            }
            LOWORD(v39) = v16;
            HIWORD(v39) = v33;
            GArrayPagedBase<GFxGlyphFitter::VertexType,6,16,GAllocatorPagedLH_POD<GFxGlyphFitter::VertexType,2>>::PushBack(
              this: v7,
              a2: &v39);
            goto LABEL_40;
          }
          if ( v16 >= a5 && v16 < a3 + a5 + 1 )
          {
            if ( (v16 <= a3 + v38 + 1
               || a3 + *(__int16 *)(*(_DWORD *)(v7[3] + 4 * ((*v7 - 1) >> 6)) + 4 * ((*v7 - 1) & 0x3F) + 2) >= v32)
              && *v7 != 0 )
            {
              --*v7;
            }
            HIWORD(v39) = v32;
            LOWORD(v39) = v16;
            GArrayPagedBase<GFxGlyphFitter::VertexType,6,16,GAllocatorPagedLH_POD<GFxGlyphFitter::VertexType,2>>::PushBack(
              this: v7,
              a2: &v39);
            goto LABEL_40;
          }
        }
        v18 = a3 * ((a3 + *(_DWORD *)(this + 108) + v16) / a3) - *(_DWORD *)(this + 108);
        if ( v16 <= a3 + v38 + 1
          || (LOWORD(v18) = a3 * ((a3 + *(_DWORD *)(this + 108) + v16) / a3) - *(_WORD *)(this + 108),
              a3 + *(__int16 *)(*(_DWORD *)(v7[3] + 4 * ((*v7 - 1) >> 6)) + 4 * ((*v7 - 1) & 0x3F) + 2) >= a3 * ((a3 + *(_DWORD *)(this + 108) + v16) / a3) - *(_DWORD *)(this + 108)) )
        {
          if ( *v7 != 0 )
            --*v7;
        }
        HIWORD(v39) = v18;
        v19 = *v7 >> 6;
        LOWORD(v39) = v16;
        v36 = v19;
        if ( v19 >= v7[1] )
        {
          GArrayPagedBase<GFxGlyphFitter::VertexType,6,16,GAllocatorPagedLH_POD<GFxGlyphFitter::VertexType,2>>::allocatePage(
            this: v7,
            a2: v19);
          v19 = v36;
        }
        *(_DWORD *)(*(_DWORD *)(v7[3] + 4 * v19) + 4 * (*v7 & 0x3F)) = v39;
LABEL_39:
        ++*v7;
LABEL_40:
        v38 = v16;
      }
LABEL_41:
      v15 = v42 + 1;
      ++v16;
      v42 = v15;
      v35 = v16;
      if ( v15 >= *(_DWORD *)(this + 40) )
      {
        v6 = this;
        goto LABEL_43;
      }
    }
    if ( (v17 & 1) == 0 || v16 <= a3 + v38 + 1 )
      goto LABEL_41;
    v20 = a3 * ((*(_DWORD *)(this + 108) + a3 / 2 + v16 + 1) / a3) - *(_DWORD *)(this + 108);
    v16 = v35;
    if ( *(__int16 *)(*(_DWORD *)(v7[3] + 4 * ((*v7 - 1) >> 6)) + 4 * ((*v7 - 1) & 0x3F) + 2) == v20 )
      goto LABEL_40;
    HIWORD(v39) = v20;
    v21 = *v7 >> 6;
    LOWORD(v39) = v35;
    v37 = v21;
    if ( v21 >= v7[1] )
    {
      GArrayPagedBase<GFxGlyphFitter::VertexType,6,16,GAllocatorPagedLH_POD<GFxGlyphFitter::VertexType,2>>::allocatePage(
        this: v7,
        a2: v21);
      v21 = v37;
    }
    *(_DWORD *)(*(_DWORD *)(v7[3] + 4 * v21) + 4 * (*v7 & 0x3F)) = v39;
    goto LABEL_39;
  }
LABEL_43:
  v22 = *v7 >> 6;
  LOWORD(v39) = 4 * *(_WORD *)(v6 + 108);
  HIWORD(v39) = v39;
  if ( v22 >= v7[1] )
    GArrayPagedBase<GFxGlyphFitter::VertexType,6,16,GAllocatorPagedLH_POD<GFxGlyphFitter::VertexType,2>>::allocatePage(
      this: v7,
      a2: v22);
  *(_DWORD *)(*(_DWORD *)(v7[3] + 4 * v22) + 4 * ((*v7)++ & 0x3F)) = v39;
  v23 = v6 + 64;
  if ( a2 != 1 )
    v23 = v6 + 76;
  v24 = *(_DWORD *)(v6 + 40);
  v40 = v24;
  if ( v24 > *(_DWORD *)(v23 + 8) )
  {
    GMemory::pGlobalHeap->Free(this: GMemory::pGlobalHeap, a2: *(void **)v23);
    *(_DWORD *)(v23 + 8) = v40;
    if ( v40 != 0 )
    {
      a6 = 2;
      v25 = GMemory::pGlobalHeap->AllocAutoHeap_2(this: GMemory::pGlobalHeap, a2: v23, a3: 2 * v40, a4: &a6);
    }
    else
    {
      v25 = nullptr;
    }
    *(_DWORD *)v23 = v25;
    v24 = v40;
  }
  *(_DWORD *)(v23 + 4) = v24;
  v26 = *(_DWORD *)(v6 + 40) == 0;
  v27 = **(int ***)(v6 + 60);
  v28 = *v27;
  result = v27[1];
  v44 = v28;
  v45 = result;
  a6 = 2;
  v43 = 0;
  if ( !v26 )
  {
    v41 = v31;
    while ( 1 )
    {
      if ( v41 >= (__int16)result && a6 < *v7 )
      {
        v28 = result;
        result = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v6 + 60) + 4 * (a6 >> 6)) + 4 * (a6 & 0x3F));
        ++a6;
        v44 = v28;
        v45 = result;
      }
      v30 = (v41 - (__int16)v28) * (SHIWORD(result) - SHIWORD(v28)) / ((__int16)v45 - (__int16)v28);
      ++v41;
      *(_WORD *)(*(_DWORD *)v23 + 2 * v43) = HIWORD(v28) + v30 - v31;
      result = v43 + 1;
      v43 = result;
      if ( result >= *(_DWORD *)(v6 + 40) )
        break;
      result = v45;
      v28 = v44;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019C8E0
// Name: public: void GFxGlyphFitter::FitGlyph(int,int,int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GFxGlyphFitter::FitGlyph(GFxGlyphFitter *this, int a2, int a3, int a4, unsigned int a5)
{
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ecx

  if ( a3 != 0 )
    v6 = *(_DWORD *)this / a3;
  else
    v6 = 1;
  *((_DWORD *)this + 25) = v6;
  if ( a2 != 0 )
    v7 = *(_DWORD *)this / a2;
  else
    v7 = 1;
  v8 = *(_DWORD *)this / v7;
  *((_DWORD *)this + 26) = v7;
  *((_DWORD *)this + 27) = v7 * v8;
  if ( a2 != 0 || a3 != 0 )
  {
    GFxGlyphFitter::removeDuplicateClosures(this);
    GFxGlyphFitter::computeBounds(this);
    if ( a2 != 0 && *((_WORD *)this + 47) > *((_WORD *)this + 45) )
    {
      GFxGlyphFitter::detectEvents(this: v9, a2: 2);
      GFxGlyphFitter::computeLerpRamp(
        (int)this,
        a2: 2,
        a3: *((_DWORD *)this + 26),
        a4: *((__int16 *)this + 45) + (*((__int16 *)this + 47) - *((__int16 *)this + 45)) / 3,
        a5: a4,
        a6: a5);
    }
    if ( a3 != 0 && *((_WORD *)this + 47) > *((_WORD *)this + 45) )
    {
      GFxGlyphFitter::detectEvents((int)this, a2: 1);
      GFxGlyphFitter::computeLerpRamp(
        (int)this,
        a2: 1,
        a3: *((_DWORD *)this + 25),
        a4: *((__int16 *)this + 44) + (*((__int16 *)this + 46) - *((__int16 *)this + 44)) / 3,
        a5: 0,
        a6: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019C9D0
// Name: void jpeg_CreateDecompress(struct jpeg_decompress_struct __near *,int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_CreateDecompress(struct jpeg_decompress_struct *dst, int a2, unsigned int a3)
{
  int v3; // ebx
  int v4; // ebp

  *((_DWORD *)dst + 1) = 0;
  if ( a2 != 62 )
  {
    *(_DWORD *)(*(_DWORD *)dst + 20) = 12;
    *(_DWORD *)(*(_DWORD *)dst + 24) = 62;
    *(_DWORD *)(*(_DWORD *)dst + 28) = a2;
    (**(void (__cdecl ***)(struct jpeg_decompress_struct *))dst)(a1: dst);
  }
  if ( a3 != 432 )
  {
    *(_DWORD *)(*(_DWORD *)dst + 20) = 21;
    *(_DWORD *)(*(_DWORD *)dst + 24) = 432;
    *(_DWORD *)(*(_DWORD *)dst + 28) = a3;
    (**(void (__cdecl ***)(struct jpeg_decompress_struct *))dst)(a1: dst);
  }
  v3 = *(_DWORD *)dst;
  v4 = *((_DWORD *)dst + 3);
  memset((unsigned __int8 *)dst, value: 0, count: 0x1B0u);
  *(_DWORD *)dst = v3;
  *((_DWORD *)dst + 3) = v4;
  *((_BYTE *)dst + 16) = 1;
  jinit_memory_mgr(a1: dst);
  *((_DWORD *)dst + 2) = 0;
  *((_DWORD *)dst + 6) = 0;
  *((_DWORD *)dst + 36) = 0;
  *((_DWORD *)dst + 37) = 0;
  *((_DWORD *)dst + 38) = 0;
  *((_DWORD *)dst + 39) = 0;
  *((_DWORD *)dst + 40) = 0;
  *((_DWORD *)dst + 44) = 0;
  *((_DWORD *)dst + 41) = 0;
  *((_DWORD *)dst + 45) = 0;
  *((_DWORD *)dst + 42) = 0;
  *((_DWORD *)dst + 46) = 0;
  *((_DWORD *)dst + 43) = 0;
  *((_DWORD *)dst + 47) = 0;
  *((_DWORD *)dst + 67) = 0;
  jinit_marker_reader(a1: dst);
  jinit_input_controller(a1: dst);
  *((_DWORD *)dst + 5) = 200;
}

//------------------------------------------------------------------------------
// Address: 0x1019CAD0
// Name: void jpeg_destroy_compress(struct jpeg_compress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl jpeg_destroy_compress(struct jpeg_compress_struct *a1)
{
  jpeg_destroy(a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019CAE0
// Name: sub_1019CAE0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_1019CAE0@<eax>(int a1@<esi>)
{
  int result; // eax
  int v2; // ecx
  int v3; // edx
  int v4; // edi
  _DWORD *v5; // eax

  result = *(_DWORD *)(a1 + 36) - 1;
  if ( *(_DWORD *)(a1 + 36) == 1 )
  {
    *(_DWORD *)(a1 + 40) = 1;
    *(_DWORD *)(a1 + 44) = 1;
    goto LABEL_27;
  }
  result = *(_DWORD *)(a1 + 36) - 3;
  if ( *(_DWORD *)(a1 + 36) == 3 )
  {
    if ( *(_BYTE *)(a1 + 256) != 0 )
    {
LABEL_12:
      *(_DWORD *)(a1 + 40) = 3;
      *(_DWORD *)(a1 + 44) = 2;
      goto LABEL_27;
    }
    if ( *(_BYTE *)(a1 + 264) != 0 )
    {
      result = *(unsigned __int8 *)(a1 + 265);
      if ( *(_BYTE *)(a1 + 265) != 0 )
      {
        if ( --result != 0 )
        {
          *(_DWORD *)(*(_DWORD *)a1 + 20) = 114;
          *(_DWORD *)(*(_DWORD *)a1 + 24) = *(unsigned __int8 *)(a1 + 265);
          result = (*(int (__cdecl **)(int, int))(*(_DWORD *)a1 + 4))(a1, a2: -1);
          *(_DWORD *)(a1 + 40) = 3;
          *(_DWORD *)(a1 + 44) = 2;
          goto LABEL_27;
        }
        goto LABEL_12;
      }
LABEL_24:
      *(_DWORD *)(a1 + 40) = 2;
      *(_DWORD *)(a1 + 44) = 2;
      goto LABEL_27;
    }
    result = *(_DWORD *)(a1 + 196);
    v2 = *(_DWORD *)result;
    v3 = *(_DWORD *)(result + 84);
    v4 = *(_DWORD *)(result + 168);
    if ( *(_DWORD *)result == 1 )
    {
      if ( v3 == 2 && v4 == 3 )
      {
        *(_DWORD *)(a1 + 40) = 3;
        *(_DWORD *)(a1 + 44) = 2;
        goto LABEL_27;
      }
    }
    else if ( v2 == 82 && v3 == 71 && v4 == 66 )
    {
      goto LABEL_24;
    }
    v5 = (_DWORD *)(*(_DWORD *)a1 + 24);
    *v5 = v2;
    v5[1] = v3;
    v5[2] = v4;
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 111;
    result = (*(int (__cdecl **)(int, int))(*(_DWORD *)a1 + 4))(a1, a2: 1);
    *(_DWORD *)(a1 + 40) = 3;
    *(_DWORD *)(a1 + 44) = 2;
    goto LABEL_27;
  }
  result = *(_DWORD *)(a1 + 36) - 4;
  if ( *(_DWORD *)(a1 + 36) == 4 )
  {
    if ( *(_BYTE *)(a1 + 264) != 0 && (result = *(unsigned __int8 *)(a1 + 265), *(_BYTE *)(a1 + 265) != 0) )
    {
      result -= 2;
      if ( result != 0 )
      {
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 114;
        *(_DWORD *)(*(_DWORD *)a1 + 24) = *(unsigned __int8 *)(a1 + 265);
        result = (*(int (__cdecl **)(int, int))(*(_DWORD *)a1 + 4))(a1, a2: -1);
      }
      *(_DWORD *)(a1 + 40) = 5;
      *(_DWORD *)(a1 + 44) = 4;
    }
    else
    {
      *(_DWORD *)(a1 + 40) = 4;
      *(_DWORD *)(a1 + 44) = 4;
    }
  }
  else
  {
    *(_DWORD *)(a1 + 40) = 0;
    *(_DWORD *)(a1 + 44) = 0;
  }
LABEL_27:
  *(_DWORD *)(a1 + 48) = 1;
  *(double *)(a1 + 56) = 1.0;
  *(_DWORD *)(a1 + 52) = 1;
  *(_BYTE *)(a1 + 64) = 0;
  *(_BYTE *)(a1 + 65) = 0;
  *(_DWORD *)(a1 + 68) = 0;
  *(_BYTE *)(a1 + 74) = 0;
  *(_DWORD *)(a1 + 116) = 0;
  *(_BYTE *)(a1 + 88) = 0;
  *(_BYTE *)(a1 + 89) = 0;
  *(_BYTE *)(a1 + 90) = 0;
  *(_BYTE *)(a1 + 72) = 1;
  *(_BYTE *)(a1 + 73) = 1;
  *(_DWORD *)(a1 + 76) = 2;
  *(_BYTE *)(a1 + 80) = 1;
  *(_DWORD *)(a1 + 84) = 256;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019CCB0
// Name: int jpeg_consume_input(struct jpeg_decompress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl jpeg_consume_input(struct jpeg_decompress_struct *a1)
{
  int v1; // edi
  int result; // eax

  v1 = 0;
  switch ( *((_DWORD *)a1 + 5) )
  {
    case 0xC8:
      (*(void (__cdecl **)(struct jpeg_decompress_struct *))(*((_DWORD *)a1 + 100) + 4))(a1);
      (*(void (__cdecl **)(struct jpeg_decompress_struct *))(*((_DWORD *)a1 + 6) + 8))(a1);
      *((_DWORD *)a1 + 5) = 201;
      goto LABEL_3;
    case 0xC9:
LABEL_3:
      v1 = (**((int (__cdecl ***)(struct jpeg_decompress_struct *))a1 + 100))(a1);
      if ( v1 != 1 )
        goto LABEL_8;
      sub_1019CAE0((int)a1);
      *((_DWORD *)a1 + 5) = 202;
      result = 1;
      break;
    case 0xCA:
      return 1;
    case 0xCB:
    case 0xCC:
    case 0xCD:
    case 0xCE:
    case 0xCF:
    case 0xD0:
    case 0xD2:
      return (**((int (__cdecl ***)(struct jpeg_decompress_struct *))a1 + 100))(a1);
    default:
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 20;
      *(_DWORD *)(*(_DWORD *)a1 + 24) = *((_DWORD *)a1 + 5);
      (**(void (__cdecl ***)(struct jpeg_decompress_struct *))a1)(a1);
LABEL_8:
      result = v1;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019CD80
// Name: unsigned char jpeg_finish_decompress(struct jpeg_decompress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 __cdecl jpeg_finish_decompress(struct jpeg_decompress_struct *a1)
{
  int v1; // eax

  v1 = *((_DWORD *)a1 + 5);
  if ( (v1 == 205 || v1 == 206) && *((_BYTE *)a1 + 64) == 0 )
  {
    if ( *((_DWORD *)a1 + 30) < *((_DWORD *)a1 + 24) )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 67;
      (**(void (__cdecl ***)(struct jpeg_decompress_struct *))a1)(a1);
    }
    (*(void (__cdecl **)(struct jpeg_decompress_struct *))(*((_DWORD *)a1 + 96) + 4))(a1);
    *((_DWORD *)a1 + 5) = 210;
  }
  else if ( v1 == 207 )
  {
    *((_DWORD *)a1 + 5) = 210;
  }
  else if ( v1 != 210 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 20;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = *((_DWORD *)a1 + 5);
    (**(void (__cdecl ***)(struct jpeg_decompress_struct *))a1)(a1);
  }
  if ( *(_BYTE *)(*((_DWORD *)a1 + 100) + 17) != 0 )
  {
LABEL_14:
    (*(void (__cdecl **)(struct jpeg_decompress_struct *))(*((_DWORD *)a1 + 6) + 24))(a1);
    jpeg_abort(a1);
    return 1;
  }
  else
  {
    while ( (**((int (__cdecl ***)(struct jpeg_decompress_struct *))a1 + 100))(a1) != 0 )
    {
      if ( *(_BYTE *)(*((_DWORD *)a1 + 100) + 17) != 0 )
        goto LABEL_14;
    }
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019CE50
// Name: int jpeg_read_header(struct jpeg_decompress_struct __near *,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl jpeg_read_header(struct jpeg_decompress_struct *a1, char a2)
{
  int v2; // eax
  int result; // eax

  v2 = *((_DWORD *)a1 + 5);
  if ( v2 != 200 && v2 != 201 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 20;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = *((_DWORD *)a1 + 5);
    (**(void (__cdecl ***)(struct jpeg_decompress_struct *))a1)(a1);
  }
  result = jpeg_consume_input(a1);
  if ( result == 1 )
    return 1;
  if ( result == 2 )
  {
    if ( a2 != 0 )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 51;
      (**(void (__cdecl ***)(struct jpeg_decompress_struct *))a1)(a1);
    }
    jpeg_abort(a1);
    return 2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019CED0
// Name: sub_1019CED0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall sub_1019CED0@<al>(int a1@<esi>)
{
  _BYTE *v1; // eax
  int i; // ecx
  int v3; // ecx

  *(_DWORD *)(*(_DWORD *)a1 + 20) = 102;
  (*(void (__cdecl **)(int, int))(*(_DWORD *)a1 + 4))(a1, a2: 1);
  if ( *(_BYTE *)(*(_DWORD *)(a1 + 404) + 12) != 0 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 61;
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  v1 = (_BYTE *)(a1 + 218);
  for ( i = 16; i != 0; --i )
  {
    *(v1 - 16) = 0;
    *v1 = 1;
    v1[16] = 5;
    ++v1;
  }
  v3 = *(_DWORD *)(a1 + 404);
  *(_DWORD *)(a1 + 252) = 0;
  *(_DWORD *)(a1 + 40) = 0;
  *(_BYTE *)(a1 + 266) = 0;
  *(_BYTE *)(a1 + 256) = 0;
  *(_BYTE *)(a1 + 259) = 0;
  *(_BYTE *)(a1 + 264) = 0;
  *(_BYTE *)(a1 + 265) = 0;
  *(_BYTE *)(a1 + 257) = 1;
  *(_BYTE *)(a1 + 258) = 1;
  *(_WORD *)(a1 + 260) = 1;
  *(_WORD *)(a1 + 262) = 1;
  *(_BYTE *)(v3 + 12) = 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1019CF80
// Name: sub_1019CF80
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall sub_1019CF80@<al>(char a1@<al>, char a2@<cl>, int a3@<esi>)
{
  unsigned __int8 **v3; // ebp
  unsigned __int8 *v4; // ebx
  unsigned __int8 *v5; // edi
  unsigned __int16 v7; // ax
  unsigned __int8 *v8; // ebx
  unsigned __int8 *v9; // edi
  unsigned __int8 *v10; // ebx
  unsigned __int8 *v11; // edi
  int v12; // ecx
  unsigned __int8 *v13; // ebx
  unsigned __int8 *v14; // edi
  unsigned __int16 v15; // ax
  unsigned __int8 *v16; // ebx
  unsigned __int8 *v17; // edi
  unsigned __int8 *v18; // ebx
  unsigned __int8 *v19; // edi
  unsigned __int16 v20; // cx
  unsigned __int8 *v21; // ebx
  unsigned __int8 *v22; // edi
  unsigned __int8 *v23; // ebx
  unsigned __int8 *v24; // edi
  _DWORD *v25; // eax
  int v26; // ecx
  unsigned __int8 *v27; // ebx
  unsigned __int8 *v28; // edi
  int *v29; // ebp
  int v30; // ecx
  unsigned __int8 *v31; // ebx
  unsigned __int8 *v32; // edi
  unsigned __int8 *v33; // ebx
  int v34; // ecx
  int v35; // eax
  unsigned __int8 *v36; // edi
  int v37; // ecx
  _DWORD *v38; // eax
  int v39; // [esp+Ch] [ebp-8h]
  int v40; // [esp+Ch] [ebp-8h]
  int v41; // [esp+Ch] [ebp-8h]
  int i; // [esp+Ch] [ebp-8h]
  unsigned __int8 **v43; // [esp+10h] [ebp-4h]

  v3 = *(unsigned __int8 ***)(a3 + 24);
  v4 = v3[1];
  v5 = *v3;
  v43 = v3;
  *(_BYTE *)(a3 + 200) = a1;
  *(_BYTE *)(a3 + 201) = a2;
  if ( v4 == nullptr )
  {
    if ( ((unsigned __int8 (__cdecl *)(int))v3[3])(a1: a3) == 0 )
      return 0;
    v5 = *v3;
    v4 = v3[1];
  }
  LOBYTE(v7) = 0;
  HIBYTE(v7) = *v5;
  v8 = v4 - 1;
  v9 = v5 + 1;
  v39 = v7;
  if ( v8 == nullptr )
  {
    if ( ((unsigned __int8 (__cdecl *)(int))v3[3])(a1: a3) == 0 )
      return 0;
    v9 = *v3;
    v8 = v3[1];
  }
  v40 = *v9 + v39;
  v10 = v8 - 1;
  v11 = v9 + 1;
  if ( v10 == nullptr )
  {
    if ( ((unsigned __int8 (__cdecl *)(int))v3[3])(a1: a3) == 0 )
      return 0;
    v11 = *v3;
    v10 = v3[1];
  }
  v12 = *v11;
  v13 = v10 - 1;
  v14 = v11 + 1;
  *(_DWORD *)(a3 + 192) = v12;
  if ( v13 == nullptr )
  {
    if ( ((unsigned __int8 (__cdecl *)(int))v3[3])(a1: a3) == 0 )
      return 0;
    v14 = *v3;
    v13 = v3[1];
  }
  LOBYTE(v15) = 0;
  HIBYTE(v15) = *v14;
  v16 = v13 - 1;
  v17 = v14 + 1;
  *(_DWORD *)(a3 + 32) = v15;
  if ( v16 == nullptr )
  {
    if ( ((unsigned __int8 (__cdecl *)(int))v3[3])(a1: a3) == 0 )
      return 0;
    v17 = *v3;
    v16 = v3[1];
  }
  *(_DWORD *)(a3 + 32) += *v17;
  v18 = v16 - 1;
  v19 = v17 + 1;
  if ( v18 == nullptr )
  {
    if ( ((unsigned __int8 (__cdecl *)(int))v3[3])(a1: a3) == 0 )
      return 0;
    v19 = *v3;
    v18 = v3[1];
  }
  LOBYTE(v20) = 0;
  HIBYTE(v20) = *v19;
  v21 = v18 - 1;
  v22 = v19 + 1;
  *(_DWORD *)(a3 + 28) = v20;
  if ( v21 == nullptr )
  {
    if ( ((unsigned __int8 (__cdecl *)(int))v3[3])(a1: a3) == 0 )
      return 0;
    v22 = *v3;
    v21 = v3[1];
  }
  *(_DWORD *)(a3 + 28) += *v22;
  v23 = v21 - 1;
  v24 = v22 + 1;
  if ( v23 == nullptr )
  {
    if ( ((unsigned __int8 (__cdecl *)(int))v3[3])(a1: a3) == 0 )
      return 0;
    v24 = *v3;
    v23 = v3[1];
  }
  v25 = *(_DWORD **)a3;
  v26 = *(_DWORD *)(a3 + 380);
  v41 = v40 - 8;
  *(_DWORD *)(a3 + 36) = *v24;
  v25 += 6;
  *v25 = v26;
  v25[1] = *(_DWORD *)(a3 + 28);
  v25[2] = *(_DWORD *)(a3 + 32);
  v25[3] = *(_DWORD *)(a3 + 36);
  *(_DWORD *)(*(_DWORD *)a3 + 20) = 100;
  v27 = v23 - 1;
  v28 = v24 + 1;
  (*(void (__cdecl **)(int, int))(*(_DWORD *)a3 + 4))(a1: a3, a2: 1);
  if ( *(_BYTE *)(*(_DWORD *)(a3 + 404) + 13) != 0 )
  {
    *(_DWORD *)(*(_DWORD *)a3 + 20) = 58;
    (**(void (__cdecl ***)(int))a3)(a1: a3);
  }
  if ( *(_DWORD *)(a3 + 32) == 0 || *(_DWORD *)(a3 + 28) == 0 || *(int *)(a3 + 36) <= 0 )
  {
    *(_DWORD *)(*(_DWORD *)a3 + 20) = 32;
    (**(void (__cdecl ***)(int))a3)(a1: a3);
  }
  if ( v41 != 3 * *(_DWORD *)(a3 + 36) )
  {
    *(_DWORD *)(*(_DWORD *)a3 + 20) = 11;
    (**(void (__cdecl ***)(int))a3)(a1: a3);
  }
  if ( *(_DWORD *)(a3 + 196) == 0 )
    *(_DWORD *)(a3 + 196) = (**(int (__cdecl ***)(int, int, int))(a3 + 4))(a1: a3, a2: 1, a3: 84 * *(_DWORD *)(a3 + 36));
  v29 = *(int **)(a3 + 196);
  for ( i = 0; i < *(_DWORD *)(a3 + 36); ++i )
  {
    v29[1] = i;
    if ( v27 == nullptr )
    {
      if ( ((unsigned __int8 (__cdecl *)(int))v43[3])(a1: a3) == 0 )
        return 0;
      v28 = *v43;
      v27 = v43[1];
    }
    v30 = *v28;
    v31 = v27 - 1;
    v32 = v28 + 1;
    *v29 = v30;
    if ( v31 == nullptr )
    {
      if ( ((unsigned __int8 (__cdecl *)(int))v43[3])(a1: a3) == 0 )
        return 0;
      v32 = *v43;
      v31 = v43[1];
    }
    v33 = v31 - 1;
    v34 = (int)*v32 >> 4;
    v35 = *v32 & 0xF;
    v36 = v32 + 1;
    v29[2] = v34;
    v29[3] = v35;
    if ( v33 == nullptr )
    {
      if ( ((unsigned __int8 (__cdecl *)(int))v43[3])(a1: a3) == 0 )
        return 0;
      v36 = *v43;
      v33 = v43[1];
    }
    v37 = *v29;
    v29[4] = *v36;
    v38 = (_DWORD *)(*(_DWORD *)a3 + 24);
    *v38 = v37;
    v38[1] = v29[2];
    v38[2] = v29[3];
    v38[3] = v29[4];
    *(_DWORD *)(*(_DWORD *)a3 + 20) = 101;
    v27 = v33 - 1;
    v28 = v36 + 1;
    (*(void (__cdecl **)(int, int))(*(_DWORD *)a3 + 4))(a1: a3, a2: 1);
    v29 += 21;
  }
  *(_BYTE *)(*(_DWORD *)(a3 + 404) + 13) = 1;
  *v43 = v28;
  v43[1] = v27;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1019D2B0
// Name: sub_1019D2B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall sub_1019D2B0@<al>(_DWORD *a1@<esi>)
{
  unsigned __int8 **v1; // ebp
  unsigned __int8 *v2; // ebx
  unsigned __int8 *v3; // edi
  unsigned __int16 v5; // ax
  unsigned __int8 *v6; // edi
  unsigned __int8 *v7; // ebx
  unsigned __int8 *v8; // edi
  unsigned __int8 *v9; // ebx
  int v10; // eax
  unsigned __int8 *v11; // edi
  unsigned __int8 *v12; // ebx
  int v13; // eax
  int v14; // eax
  unsigned __int8 *v15; // edi
  unsigned __int8 *v16; // ebx
  int v17; // ebp
  int v18; // eax
  _DWORD *v19; // edi
  _DWORD *v20; // eax
  int v21; // eax
  unsigned __int8 *v22; // edi
  unsigned __int8 *v23; // ebx
  int v24; // eax
  unsigned __int8 *v25; // edi
  unsigned __int8 *v26; // ebx
  int v27; // ecx
  int v28; // edx
  _DWORD *v29; // eax
  unsigned __int8 *v30; // [esp+Ch] [ebp-18h]
  int v31; // [esp+10h] [ebp-14h]
  int v32; // [esp+10h] [ebp-14h]
  int v33; // [esp+10h] [ebp-14h]
  _DWORD *v34; // [esp+14h] [ebp-10h]
  int v35; // [esp+18h] [ebp-Ch]
  int v36; // [esp+1Ch] [ebp-8h]
  unsigned __int8 **v37; // [esp+20h] [ebp-4h]

  v1 = (unsigned __int8 **)a1[6];
  v2 = *v1;
  v3 = v1[1];
  v37 = v1;
  if ( *(_BYTE *)(a1[101] + 13) == 0 )
  {
    *(_DWORD *)(*a1 + 20) = 62;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  if ( v3 == nullptr )
  {
    if ( ((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) == 0 )
      return 0;
    v2 = *v1;
    v3 = v1[1];
  }
  LOBYTE(v5) = 0;
  HIBYTE(v5) = *v2;
  v6 = v3 - 1;
  v7 = v2 + 1;
  v31 = v5;
  if ( v6 == nullptr )
  {
    if ( ((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) == 0 )
      return 0;
    v7 = *v1;
    v6 = v1[1];
  }
  v32 = *v7 + v31;
  v8 = v6 - 1;
  v9 = v7 + 1;
  if ( v8 == nullptr )
  {
    if ( ((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) == 0 )
      return 0;
    v9 = *v1;
    v8 = v1[1];
  }
  v10 = *v9;
  *(_DWORD *)(*a1 + 20) = 103;
  *(_DWORD *)(*a1 + 24) = v10;
  v35 = v10;
  v11 = v8 - 1;
  v12 = v9 + 1;
  (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, a2: 1);
  v13 = v35;
  if ( v32 != 2 * v35 + 6 || v35 < 1 || v35 > 4 )
  {
    *(_DWORD *)(*a1 + 20) = 11;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
    v13 = v35;
  }
  a1[73] = v13;
  v36 = 0;
  if ( v13 > 0 )
  {
    v34 = a1 + 74;
    do
    {
      if ( v11 == nullptr )
      {
        if ( ((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) == 0 )
          return 0;
        v12 = *v1;
        v11 = v1[1];
      }
      v14 = *v12;
      v15 = v11 - 1;
      v16 = v12 + 1;
      v33 = v14;
      if ( v15 == nullptr )
      {
        if ( ((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) == 0 )
          return 0;
        v16 = *v1;
        v15 = v1[1];
      }
      v17 = *v16;
      v18 = 0;
      v12 = v16 + 1;
      v30 = v15 - 1;
      v19 = (_DWORD *)a1[49];
      if ( (int)a1[9] <= 0 )
      {
LABEL_28:
        *(_DWORD *)(*a1 + 20) = 5;
        *(_DWORD *)(*a1 + 24) = v33;
        (*(void (__cdecl **)(_DWORD *))*a1)(a1);
      }
      else
      {
        while ( v33 != *v19 )
        {
          ++v18;
          v19 += 21;
          if ( v18 >= a1[9] )
            goto LABEL_28;
        }
      }
      *v34 = v19;
      v19[5] = (v17 >> 4) & 0xF;
      v19[6] = v17 & 0xF;
      v20 = (_DWORD *)(*a1 + 24);
      *v20 = v33;
      v20[1] = v19[5];
      v20[2] = v19[6];
      *(_DWORD *)(*a1 + 20) = 104;
      (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, a2: 1);
      ++v34;
      v11 = v30;
      v1 = v37;
      ++v36;
    }
    while ( v36 < v35 );
  }
  if ( v11 == nullptr )
  {
    if ( ((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) == 0 )
      return 0;
    v12 = *v1;
    v11 = v1[1];
  }
  v21 = *v12;
  v22 = v11 - 1;
  v23 = v12 + 1;
  a1[91] = v21;
  if ( v22 == nullptr )
  {
    if ( ((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) == 0 )
      return 0;
    v23 = *v1;
    v22 = v1[1];
  }
  v24 = *v23;
  v25 = v22 - 1;
  v26 = v23 + 1;
  a1[92] = v24;
  if ( v25 == nullptr )
  {
    if ( ((unsigned __int8 (__cdecl *)(_DWORD *))v1[3])(a1) == 0 )
      return 0;
    v26 = *v1;
    v25 = v1[1];
  }
  v27 = a1[91];
  v28 = *v26;
  a1[94] = v28 & 0xF;
  v29 = (_DWORD *)*a1;
  a1[93] = v28 >> 4;
  v29 += 6;
  *v29 = v27;
  v29[1] = a1[92];
  v29[2] = a1[93];
  v29[3] = a1[94];
  *(_DWORD *)(*a1 + 20) = 105;
  (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, a2: 1);
  *(_DWORD *)(a1[101] + 16) = 0;
  ++a1[31];
  v1[1] = v25 - 1;
  *v1 = v26 + 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1019D5D0
// Name: sub_1019D5D0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl sub_1019D5D0(struct jpeg_common_struct *a1)
{
  unsigned __int8 **v1; // edi
  unsigned __int8 *v2; // esi
  unsigned __int8 *v3; // ebx
  int v5; // eax
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // ebx
  int v8; // eax
  unsigned __int8 *v9; // esi
  unsigned __int8 *v10; // ebx
  unsigned int v11; // eax
  unsigned __int8 *v12; // esi
  int i; // edi
  int v14; // edx
  _DWORD *v15; // eax
  int v16; // ecx
  int v17; // edx
  int v18; // ecx
  int v19; // edx
  int v20; // ecx
  int v21; // edx
  int v22; // edx
  _DWORD *v23; // eax
  int v24; // ecx
  int v25; // edx
  int v26; // ecx
  int v27; // edx
  int v28; // ecx
  int v29; // edx
  int v30; // eax
  int j; // edi
  unsigned int v32; // eax
  char *v33; // esi
  int v34; // eax
  int v35; // ecx
  int v36; // edx
  int v37; // ecx
  unsigned __int8 *v38; // [esp+10h] [ebp-12Ch]
  int v39; // [esp+14h] [ebp-128h]
  int v40; // [esp+14h] [ebp-128h]
  int v41; // [esp+14h] [ebp-128h]
  int v42; // [esp+18h] [ebp-124h]
  unsigned __int8 **v43; // [esp+1Ch] [ebp-120h]
  unsigned int v44; // [esp+20h] [ebp-11Ch]
  int v45; // [esp+24h] [ebp-118h]
  int v46; // [esp+28h] [ebp-114h]
  int v47; // [esp+2Ch] [ebp-110h]
  int v48; // [esp+30h] [ebp-10Ch]
  unsigned __int8 v49; // [esp+34h] [ebp-108h]
  _BYTE v50[256]; // [esp+38h] [ebp-104h]

  v1 = *((unsigned __int8 ***)a1 + 6);
  v2 = v1[1];
  v3 = *v1;
  v43 = v1;
  if ( v2 == nullptr )
  {
    if ( ((unsigned __int8 (__cdecl *)(struct jpeg_common_struct *))v1[3])(a1) == 0 )
      return 0;
    v3 = *v1;
    v2 = v1[1];
  }
  v5 = 0;
  BYTE1(v5) = *v3;
  v6 = v2 - 1;
  v7 = v3 + 1;
  v39 = (unsigned __int16)v5;
  if ( v6 == nullptr )
  {
    if ( ((unsigned __int8 (__cdecl *)(struct jpeg_common_struct *))v1[3])(a1) == 0 )
      return 0;
    v7 = *v1;
    v6 = v1[1];
    v5 = v39;
  }
  v8 = *v7 + v5 - 2;
  v9 = v6 - 1;
  v10 = v7 + 1;
  v40 = v8;
  if ( v8 > 16 )
  {
    do
    {
      if ( v9 == nullptr )
      {
        if ( ((unsigned __int8 (__cdecl *)(struct jpeg_common_struct *))v1[3])(a1) == 0 )
          return 0;
        v10 = *v1;
        v9 = v1[1];
      }
      v11 = *v10;
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 80;
      *(_DWORD *)(*(_DWORD *)a1 + 24) = v11;
      v44 = v11;
      v12 = v9 - 1;
      ++v10;
      (*(void (__cdecl **)(struct jpeg_common_struct *, int))(*(_DWORD *)a1 + 4))(a1, a2: 1);
      LOBYTE(v45) = 0;
      v42 = 0;
      for ( i = 1; i <= 16; ++i )
      {
        if ( v12 == nullptr )
        {
          if ( ((unsigned __int8 (__cdecl *)(struct jpeg_common_struct *))v43[3])(a1) == 0 )
            return 0;
          v10 = *v43;
          v12 = v43[1];
        }
        v42 += *v10;
        *((_BYTE *)&v45 + i) = *v10;
        --v12;
        ++v10;
        v38 = v12;
      }
      v14 = BYTE2(v45);
      v15 = (_DWORD *)(*(_DWORD *)a1 + 24);
      v41 = v40 - 17;
      *v15 = BYTE1(v45);
      v16 = HIBYTE(v45);
      v15[1] = v14;
      v17 = (unsigned __int8)v46;
      v15[2] = v16;
      v18 = BYTE1(v46);
      v15[3] = v17;
      v19 = BYTE2(v46);
      v15[4] = v18;
      v20 = HIBYTE(v46);
      v15[5] = v19;
      v21 = (unsigned __int8)v47;
      v15[6] = v20;
      v15[7] = v21;
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 86;
      (*(void (__cdecl **)(struct jpeg_common_struct *, int))(*(_DWORD *)a1 + 4))(a1, a2: 2);
      v22 = BYTE2(v47);
      v23 = (_DWORD *)(*(_DWORD *)a1 + 24);
      *v23 = BYTE1(v47);
      v24 = HIBYTE(v47);
      v23[1] = v22;
      v25 = (unsigned __int8)v48;
      v23[2] = v24;
      v26 = BYTE1(v48);
      v23[3] = v25;
      v27 = BYTE2(v48);
      v23[4] = v26;
      v28 = HIBYTE(v48);
      v23[5] = v27;
      v29 = v49;
      v23[6] = v28;
      v23[7] = v29;
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 86;
      (*(void (__cdecl **)(struct jpeg_common_struct *, int))(*(_DWORD *)a1 + 4))(a1, a2: 2);
      if ( v42 > 256 || v42 > v41 )
      {
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 8;
        (**(void (__cdecl ***)(struct jpeg_common_struct *))a1)(a1);
      }
      v30 = v42;
      for ( j = 0; j < v30; v38 = v12 )
      {
        if ( v12 == nullptr )
        {
          if ( ((unsigned __int8 (__cdecl *)(struct jpeg_common_struct *))v43[3])(a1) == 0 )
            return 0;
          v10 = *v43;
          v30 = v42;
          v12 = v43[1];
        }
        v50[j] = *v10;
        --v12;
        ++j;
        ++v10;
      }
      v40 = v41 - v30;
      v32 = v44;
      if ( (v44 & 0x10) != 0 )
      {
        v32 = v44 - 16;
        v33 = (char *)a1 + 4 * v44 + 112;
      }
      else
      {
        v33 = (char *)a1 + 4 * v44 + 160;
      }
      if ( v32 >= 4 )
      {
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 30;
        *(_DWORD *)(*(_DWORD *)a1 + 24) = v32;
        (**(void (__cdecl ***)(struct jpeg_common_struct *))a1)(a1);
      }
      if ( *(_DWORD *)v33 == 0 )
        *(_DWORD *)v33 = jpeg_alloc_huff_table(a1);
      v34 = *(_DWORD *)v33;
      v35 = v46;
      *(_DWORD *)v34 = v45;
      v36 = v47;
      *(_DWORD *)(v34 + 4) = v35;
      v37 = v48;
      *(_DWORD *)(v34 + 8) = v36;
      LOBYTE(v36) = v49;
      *(_DWORD *)(v34 + 12) = v37;
      *(_BYTE *)(v34 + 16) = v36;
      qmemcpy((void *)(*(_DWORD *)v33 + 17), v50, 256);
      v9 = v38;
      v1 = v43;
    }
    while ( v40 > 16 );
    v8 = v40;
  }
  if ( v8 != 0 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 11;
    (**(void (__cdecl ***)(struct jpeg_common_struct *))a1)(a1);
  }
  *v1 = v10;
  v1[1] = v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1019D900
// Name: sub_1019D900
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall sub_1019D900@<al>(struct jpeg_common_struct *a1@<edi>)
{
  unsigned __int8 **v1; // esi
  unsigned __int8 *v2; // ebp
  unsigned __int8 *v3; // ebx
  int v5; // eax
  unsigned __int8 *v6; // ebp
  unsigned __int8 *v7; // ebx
  int v8; // eax
  unsigned __int8 *v9; // ebp
  unsigned __int8 *v10; // ebx
  bool v11; // zf
  int v12; // esi
  int v13; // eax
  int v14; // esi
  int v15; // edx
  const int *const *v16; // esi
  __int16 v17; // cx
  int v18; // ecx
  unsigned __int16 *v19; // esi
  _DWORD *v20; // eax
  int v21; // [esp+Ch] [ebp-18h]
  int v22; // [esp+Ch] [ebp-18h]
  unsigned __int8 **v23; // [esp+10h] [ebp-14h]
  __int16 v24; // [esp+14h] [ebp-10h]
  __int16 v25; // [esp+14h] [ebp-10h]
  const int *const *v26; // [esp+18h] [ebp-Ch]
  int i; // [esp+18h] [ebp-Ch]
  int v28; // [esp+1Ch] [ebp-8h]
  int v29; // [esp+20h] [ebp-4h]

  v1 = *((unsigned __int8 ***)a1 + 6);
  v2 = v1[1];
  v3 = *v1;
  v23 = v1;
  if ( v2 == nullptr )
  {
    if ( ((unsigned __int8 (__cdecl *)(struct jpeg_common_struct *))v1[3])(a1) == 0 )
      return 0;
    v3 = *v1;
    v2 = v1[1];
  }
  v5 = 0;
  BYTE1(v5) = *v3;
  v6 = v2 - 1;
  v7 = v3 + 1;
  v21 = (unsigned __int16)v5;
  if ( v6 == nullptr )
  {
    if ( ((unsigned __int8 (__cdecl *)(struct jpeg_common_struct *))v1[3])(a1) == 0 )
      return 0;
    v7 = *v1;
    v6 = v1[1];
    v5 = v21;
  }
  v8 = *v7 + v5 - 2;
  v9 = v6 - 1;
  v10 = v7 + 1;
  v11 = v8 == 0;
  v22 = v8;
  if ( v8 > 0 )
  {
    do
    {
      if ( v9 == nullptr )
      {
        if ( ((unsigned __int8 (__cdecl *)(struct jpeg_common_struct *))v1[3])(a1) == 0 )
          return 0;
        v10 = *v1;
        v9 = v1[1];
      }
      v12 = *v10;
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 81;
      v13 = v12 >> 4;
      v14 = v12 & 0xF;
      *(_DWORD *)(*(_DWORD *)a1 + 24) = v14;
      *(_DWORD *)(*(_DWORD *)a1 + 28) = v13;
      v28 = v13;
      --v9;
      ++v10;
      (*(void (__cdecl **)(struct jpeg_common_struct *, int))(*(_DWORD *)a1 + 4))(a1, a2: 1);
      if ( v14 >= 4 )
      {
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 31;
        *(_DWORD *)(*(_DWORD *)a1 + 24) = v14;
        (**(void (__cdecl ***)(struct jpeg_common_struct *))a1)(a1);
      }
      if ( *((_DWORD *)a1 + v14 + 36) == 0 )
        *((_DWORD *)a1 + v14 + 36) = jpeg_alloc_quant_table(a1);
      v15 = *((_DWORD *)a1 + v14 + 36);
      v16 = &jpeg_natural_order;
      v29 = v15;
      v26 = &jpeg_natural_order;
      do
      {
        if ( v28 != 0 )
        {
          if ( v9 == nullptr )
          {
            if ( ((unsigned __int8 (__cdecl *)(struct jpeg_common_struct *))v23[3])(a1) == 0 )
              return 0;
            v10 = *v23;
            v9 = v23[1];
          }
          LOBYTE(v17) = 0;
          HIBYTE(v17) = *v10;
          --v9;
          ++v10;
          v24 = v17;
          if ( v9 == nullptr )
          {
            if ( ((unsigned __int8 (__cdecl *)(struct jpeg_common_struct *))v23[3])(a1) == 0 )
              return 0;
            v10 = *v23;
            v9 = v23[1];
          }
          v25 = *v10 + v24;
          v16 = v26;
        }
        else
        {
          if ( v9 == nullptr )
          {
            if ( ((unsigned __int8 (__cdecl *)(struct jpeg_common_struct *))v23[3])(a1) == 0 )
              return 0;
            v10 = *v23;
            v9 = v23[1];
          }
          v25 = *v10;
        }
        v18 = (int)*v16++;
        --v9;
        ++v10;
        *(_WORD *)(v29 + 2 * v18) = v25;
        v26 = v16;
      }
      while ( (int)v16 < (int)&unk_102ACA58 );
      if ( *(int *)(*(_DWORD *)a1 + 104) >= 2 )
      {
        v19 = (unsigned __int16 *)(v29 + 4);
        for ( i = 8; i != 0; --i )
        {
          v20 = (_DWORD *)(*(_DWORD *)a1 + 24);
          *v20 = *(v19 - 2);
          v20[1] = *(v19 - 1);
          v20[2] = *v19;
          v20[3] = v19[1];
          v20[4] = v19[2];
          v20[5] = v19[3];
          v20[6] = v19[4];
          v20[7] = v19[5];
          *(_DWORD *)(*(_DWORD *)a1 + 20) = 93;
          (*(void (__cdecl **)(struct jpeg_common_struct *, int))(*(_DWORD *)a1 + 4))(a1, a2: 2);
          v19 += 8;
        }
      }
      v22 -= 65;
      if ( v28 != 0 )
        v22 -= 64;
      v1 = v23;
    }
    while ( v22 > 0 );
    v11 = v22 == 0;
  }
  if ( !v11 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 11;
    (**(void (__cdecl ***)(struct jpeg_common_struct *))a1)(a1);
  }
  *v1 = v10;
  v1[1] = v9;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1019DB80
// Name: sub_1019DB80
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl sub_1019DB80(_DWORD *a1)
{
  unsigned __int8 **v2; // ebx
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // edi
  int v6; // eax
  unsigned __int8 *v7; // edi
  unsigned __int8 *v8; // esi
  int v9; // eax
  unsigned __int8 *v10; // edi
  unsigned __int8 *v11; // esi
  unsigned __int16 v12; // cx
  unsigned __int8 *v13; // edi
  unsigned __int8 *v14; // esi
  int v15; // eax
  int v16; // [esp+14h] [ebp+4h]
  int v17; // [esp+14h] [ebp+4h]
  int v18; // [esp+14h] [ebp+4h]

  v2 = (unsigned __int8 **)a1[6];
  v3 = *v2;
  v4 = v2[1];
  if ( v4 == nullptr )
  {
    if ( ((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(a1) == 0 )
      return 0;
    v3 = *v2;
    v4 = v2[1];
  }
  v6 = 0;
  BYTE1(v6) = *v3;
  v7 = v4 - 1;
  v8 = v3 + 1;
  v16 = (unsigned __int16)v6;
  if ( v7 == nullptr )
  {
    if ( ((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(a1) == 0 )
      return 0;
    v8 = *v2;
    v7 = v2[1];
    v6 = v16;
  }
  v9 = *v8 + v6;
  v10 = v7 - 1;
  v11 = v8 + 1;
  if ( v9 != 4 )
  {
    *(_DWORD *)(*a1 + 20) = 11;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  if ( v10 == nullptr )
  {
    if ( ((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(a1) == 0 )
      return 0;
    v11 = *v2;
    v10 = v2[1];
  }
  LOBYTE(v12) = 0;
  HIBYTE(v12) = *v11;
  v13 = v10 - 1;
  v14 = v11 + 1;
  v17 = v12;
  if ( v13 == nullptr )
  {
    if ( ((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(a1) == 0 )
      return 0;
    v14 = *v2;
    v13 = v2[1];
  }
  v15 = *v14 + v17;
  *(_DWORD *)(*a1 + 20) = 82;
  *(_DWORD *)(*a1 + 24) = v15;
  v18 = v15;
  (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, a2: 1);
  a1[63] = v18;
  v2[1] = v13 - 1;
  *v2 = v14 + 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1019DC80
// Name: sub_1019DC80
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_1019DC80@<eax>(unsigned int a1@<eax>, int a2@<ecx>, _BYTE *a3@<edi>, int *a4@<esi>)
{
  int v4; // ebx
  bool v5; // zf
  _DWORD *v6; // eax
  int result; // eax
  int v8; // ebx
  int v9; // ecx

  v4 = a1 + a2;
  if ( a1 >= 0xE && *a3 == 74 && a3[1] == 70 && a3[2] == 73 && a3[3] == 70 && a3[4] == 0 )
  {
    *((_BYTE *)a4 + 256) = 1;
    *((_BYTE *)a4 + 257) = a3[5];
    *((_BYTE *)a4 + 258) = a3[6];
    *((_BYTE *)a4 + 259) = a3[7];
    *((_WORD *)a4 + 130) = (unsigned __int8)a3[9] + ((unsigned __int8)a3[8] << 8);
    v5 = *((_BYTE *)a4 + 257) == 1;
    *((_WORD *)a4 + 131) = (unsigned __int8)a3[11] + ((unsigned __int8)a3[10] << 8);
    if ( !v5 )
    {
      *(_DWORD *)(*a4 + 20) = 119;
      *(_DWORD *)(*a4 + 24) = *((unsigned __int8 *)a4 + 257);
      *(_DWORD *)(*a4 + 28) = *((unsigned __int8 *)a4 + 258);
      (*(void (__cdecl **)(int *, int))(*a4 + 4))(a1: a4, a2: -1);
    }
    v6 = (_DWORD *)(*a4 + 24);
    *v6 = *((unsigned __int8 *)a4 + 257);
    v6[1] = *((unsigned __int8 *)a4 + 258);
    v6[2] = *((unsigned __int16 *)a4 + 130);
    v6[3] = *((unsigned __int16 *)a4 + 131);
    v6[4] = *((unsigned __int8 *)a4 + 259);
    *(_DWORD *)(*a4 + 20) = 87;
    (*(void (__cdecl **)(int *, int))(*a4 + 4))(a1: a4, a2: 1);
    if ( *((_WORD *)a3 + 6) != 0 )
    {
      *(_DWORD *)(*a4 + 20) = 90;
      *(_DWORD *)(*a4 + 24) = (unsigned __int8)a3[12];
      *(_DWORD *)(*a4 + 28) = (unsigned __int8)a3[13];
      (*(void (__cdecl **)(int *, int))(*a4 + 4))(a1: a4, a2: 1);
    }
    result = (unsigned __int8)a3[13] * (unsigned __int8)a3[12];
    v8 = v4 - 14;
    if ( v8 != 3 * result )
    {
      *(_DWORD *)(*a4 + 20) = 88;
      *(_DWORD *)(*a4 + 24) = v8;
      return (*(int (__cdecl **)(int *, int))(*a4 + 4))(a1: a4, a2: 1);
    }
  }
  else if ( a1 >= 6 && *a3 == 74 && a3[1] == 70 && a3[2] == 88 && a3[3] == 88 && a3[4] == 0 )
  {
    if ( a3[5] == 16 )
    {
      *(_DWORD *)(*a4 + 20) = 108;
      *(_DWORD *)(*a4 + 24) = v4;
      return (*(int (__cdecl **)(int *, int))(*a4 + 4))(a1: a4, a2: 1);
    }
    else if ( a3[5] == 17 )
    {
      *(_DWORD *)(*a4 + 20) = 109;
      *(_DWORD *)(*a4 + 24) = v4;
      return (*(int (__cdecl **)(int *, int))(*a4 + 4))(a1: a4, a2: 1);
    }
    else
    {
      v9 = *a4;
      if ( a3[5] == 19 )
      {
        *(_DWORD *)(v9 + 20) = 110;
        *(_DWORD *)(*a4 + 24) = v4;
      }
      else
      {
        *(_DWORD *)(v9 + 20) = 89;
        *(_DWORD *)(*a4 + 24) = (unsigned __int8)a3[5];
        *(_DWORD *)(*a4 + 28) = v4;
      }
      return (*(int (__cdecl **)(int *, int))(*a4 + 4))(a1: a4, a2: 1);
    }
  }
  else
  {
    *(_DWORD *)(*a4 + 20) = 77;
    *(_DWORD *)(*a4 + 24) = v4;
    return (*(int (__cdecl **)(int *, int))(*a4 + 4))(a1: a4, a2: 1);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019DEE0
// Name: sub_1019DEE0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_1019DEE0@<eax>(_BYTE *a1@<eax>, unsigned int a2@<ecx>, _BYTE *a3@<esi>, int a4)
{
  int v4; // ebx
  int v5; // edx
  int v6; // edi
  _DWORD *v7; // ecx
  int result; // eax

  if ( a2 >= 0xC && *a1 == 65 && a1[1] == 100 && a1[2] == 111 && a1[3] == 98 && a1[4] == 101 )
  {
    v4 = (unsigned __int8)a1[11];
    v5 = (unsigned __int8)a1[8] + ((unsigned __int8)a1[7] << 8);
    v6 = (unsigned __int8)a1[10] + ((unsigned __int8)a1[9] << 8);
    v7 = (_DWORD *)(*(_DWORD *)a3 + 24);
    *v7 = (unsigned __int8)a1[6] + ((unsigned __int8)a1[5] << 8);
    v7[1] = v5;
    v7[2] = v6;
    v7[3] = v4;
    *(_DWORD *)(*(_DWORD *)a3 + 20) = 76;
    result = (*(int (__cdecl **)(_BYTE *, int))(*(_DWORD *)a3 + 4))(a1: a3, a2: 1);
    a3[265] = v4;
    a3[264] = 1;
  }
  else
  {
    *(_DWORD *)(*(_DWORD *)a3 + 20) = 78;
    *(_DWORD *)(*(_DWORD *)a3 + 24) = a4 + a2;
    return (*(int (__cdecl **)(_BYTE *, int))(*(_DWORD *)a3 + 4))(a1: a3, a2: 1);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019DF90
// Name: sub_1019DF90
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl sub_1019DF90(int *a1)
{
  unsigned __int8 **v1; // edi
  unsigned __int8 *v2; // ebp
  unsigned __int8 *v3; // ebx
  char result; // al
  unsigned __int16 v5; // cx
  unsigned __int8 *v6; // ebp
  unsigned __int8 *v7; // ebx
  int v8; // esi
  int v9; // esi
  unsigned __int8 *v10; // ebp
  unsigned __int8 *v11; // ebx
  unsigned int v12; // eax
  unsigned int v13; // ecx
  int v14; // esi
  unsigned int i; // [esp+Ch] [ebp-24h]
  int v16; // [esp+14h] [ebp-1Ch]
  _BYTE v17[16]; // [esp+1Ch] [ebp-14h] BYREF

  v1 = (unsigned __int8 **)a1[6];
  v2 = v1[1];
  v3 = *v1;
  if ( v2 == nullptr )
  {
    result = ((int (__cdecl *)(int *))v1[3])(a1);
    if ( result == 0 )
      return result;
    v3 = *v1;
    v2 = v1[1];
  }
  LOBYTE(v5) = 0;
  HIBYTE(v5) = *v3;
  v6 = v2 - 1;
  v7 = v3 + 1;
  v8 = v5;
  if ( v6 == nullptr )
  {
    if ( ((unsigned __int8 (__cdecl *)(int *))v1[3])(a1) == 0 )
      return 0;
    v7 = *v1;
    v6 = v1[1];
  }
  v9 = *v7 + v8 - 2;
  v10 = v6 - 1;
  v11 = v7 + 1;
  if ( v9 < 14 )
  {
    v16 = v9 <= 0 ? 0 : v9;
    v12 = v16;
  }
  else
  {
    v12 = 14;
    v16 = 14;
  }
  v13 = 0;
  for ( i = 0; v13 < v12; i = v13 )
  {
    if ( v10 == nullptr )
    {
      if ( ((unsigned __int8 (__cdecl *)(int *))v1[3])(a1) == 0 )
        return 0;
      v11 = *v1;
      v10 = v1[1];
      v12 = v16;
      v13 = i;
    }
    v17[v13++] = *v11;
    --v10;
    ++v11;
  }
  v14 = v9 - v12;
  if ( a1[95] == 224 )
  {
    sub_1019DC80(a1: v12, a2: v14, a3: v17, a4: a1);
  }
  else if ( a1[95] == 238 )
  {
    sub_1019DEE0(a1: v17, a2: v12, a3: a1, a4: v14);
  }
  else
  {
    *(_DWORD *)(*a1 + 20) = 68;
    *(_DWORD *)(*a1 + 24) = a1[95];
    (*(void (__cdecl **)(int *))*a1)(a1);
  }
  *v1 = v11;
  v1[1] = v10;
  if ( v14 > 0 )
    (*(void (__cdecl **)(int *, int))(a1[6] + 16))(a1, a2: v14);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1019E130
// Name: sub_1019E130
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl sub_1019E130(_DWORD *a1)
{
  unsigned __int8 **v2; // edi
  unsigned __int8 *v3; // ebp
  unsigned __int8 *v4; // ebx
  unsigned __int16 v6; // cx
  unsigned __int8 *v7; // ebp
  unsigned __int8 *v8; // ebx
  int v9; // eax
  int v10; // eax
  int v11; // [esp+14h] [ebp+4h]
  int v12; // [esp+14h] [ebp+4h]

  v2 = (unsigned __int8 **)a1[6];
  v3 = v2[1];
  v4 = *v2;
  if ( v3 == nullptr )
  {
    if ( ((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(a1) == 0 )
      return 0;
    v4 = *v2;
    v3 = v2[1];
  }
  LOBYTE(v6) = 0;
  HIBYTE(v6) = *v4;
  v7 = v3 - 1;
  v8 = v4 + 1;
  v11 = v6;
  if ( v7 == nullptr )
  {
    if ( ((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(a1) == 0 )
      return 0;
    v8 = *v2;
    v7 = v2[1];
  }
  v9 = *v8;
  *(_DWORD *)(*a1 + 20) = 91;
  v10 = v11 + v9 - 2;
  *(_DWORD *)(*a1 + 24) = a1[95];
  *(_DWORD *)(*a1 + 28) = v10;
  v12 = v10;
  (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, a2: 1);
  *v2 = v8 + 1;
  v2[1] = v7 - 1;
  if ( v12 > 0 )
    (*(void (__cdecl **)(_DWORD *, int))(a1[6] + 16))(a1, a2: v12);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1019E1E0
// Name: sub_1019E1E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl sub_1019E1E0(_DWORD *a1)
{
  _DWORD *v1; // ebx
  unsigned __int8 **v2; // ebp
  unsigned __int8 *v3; // esi
  unsigned __int8 *i; // edi
  int v5; // eax
  int v6; // eax
  int v7; // ebx
  _DWORD *v8; // eax

  v1 = a1;
  v2 = (unsigned __int8 **)a1[6];
  v3 = *v2;
  for ( i = v2[1]; ; v2[1] = i )
  {
    if ( i == nullptr )
    {
      if ( ((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(a1: v1) == 0 )
        return 0;
      v3 = *v2;
      i = v2[1];
    }
    v5 = *v3;
    --i;
    ++v3;
    if ( v5 == 255 )
      goto LABEL_12;
    do
    {
      ++*(_DWORD *)(v1[101] + 20);
      *v2 = v3;
      v2[1] = i;
      if ( i == nullptr )
      {
        if ( ((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(a1: v1) == 0 )
          return 0;
        v3 = *v2;
        i = v2[1];
      }
      v6 = *v3;
      --i;
      ++v3;
    }
    while ( v6 != 255 );
    while ( 1 )
    {
LABEL_12:
      if ( i == nullptr )
      {
        if ( ((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(a1: v1) == 0 )
          return 0;
        v3 = *v2;
        i = v2[1];
      }
      v7 = *v3;
      --i;
      ++v3;
      if ( v7 != 255 )
        break;
      v1 = a1;
    }
    v8 = a1;
    if ( v7 != 0 )
      break;
    *(_DWORD *)(a1[101] + 20) += 2;
    v1 = a1;
    *v2 = v3;
  }
  if ( *(_DWORD *)(a1[101] + 20) != 0 )
  {
    *(_DWORD *)(*a1 + 20) = 116;
    *(_DWORD *)(*a1 + 24) = *(_DWORD *)(a1[101] + 20);
    *(_DWORD *)(*a1 + 28) = v7;
    (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, a2: -1);
    v8 = a1;
    *(_DWORD *)(a1[101] + 20) = 0;
  }
  v8[95] = v7;
  v2[1] = i;
  *v2 = v3;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1019E310
// Name: sub_1019E310
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl sub_1019E310(_DWORD *a1)
{
  unsigned __int8 **v2; // esi
  unsigned __int8 *v3; // ebx
  unsigned __int8 *v4; // edi
  int v6; // ecx
  unsigned __int8 *v7; // edi
  unsigned __int8 *v8; // ebx
  int v9; // eax
  unsigned __int8 *v10; // edi
  unsigned __int8 *v11; // ebx
  int v12; // [esp+14h] [ebp+4h]
  int v13; // [esp+14h] [ebp+4h]

  v2 = (unsigned __int8 **)a1[6];
  v3 = *v2;
  v4 = v2[1];
  if ( v4 == nullptr )
  {
    if ( ((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(a1) == 0 )
      return 0;
    v3 = *v2;
    v4 = v2[1];
  }
  v6 = *v3;
  v7 = v4 - 1;
  v8 = v3 + 1;
  v12 = v6;
  if ( v7 == nullptr )
  {
    if ( ((unsigned __int8 (__cdecl *)(_DWORD *))v2[3])(a1) == 0 )
      return 0;
    v8 = *v2;
    v7 = v2[1];
    v6 = v12;
  }
  v9 = *v8;
  v10 = v7 - 1;
  v11 = v8 + 1;
  v13 = v9;
  if ( v6 != 255 || v9 != 216 )
  {
    *(_DWORD *)(*a1 + 20) = 53;
    *(_DWORD *)(*a1 + 24) = v6;
    *(_DWORD *)(*a1 + 28) = v9;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
    v9 = v13;
  }
  a1[95] = v9;
  v2[1] = v10;
  *v2 = v11;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1019E3C0
// Name: sub_1019E3C0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1019E3C0(struct jpeg_common_struct *a1)
{
  char v1; // al
  int v2; // eax

  while ( 1 )
  {
    if ( *((_DWORD *)a1 + 95) == 0 )
    {
      v1 = *(_BYTE *)(*((_DWORD *)a1 + 101) + 12) != 0 ? sub_1019E1E0(a1) : sub_1019E310(a1);
      if ( v1 == 0 )
        return 0;
    }
    v2 = *((_DWORD *)a1 + 95);
    switch ( v2 )
    {
      case 1:
      case 208:
      case 209:
      case 210:
      case 211:
      case 212:
      case 213:
      case 214:
      case 215:
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 92;
        *(_DWORD *)(*(_DWORD *)a1 + 24) = *((_DWORD *)a1 + 95);
        (*(void (__cdecl **)(struct jpeg_common_struct *, int))(*(_DWORD *)a1 + 4))(a1, a2: 1);
        *((_DWORD *)a1 + 95) = 0;
        continue;
      case 192:
      case 193:
        if ( sub_1019CF80(a1: 0, a2: 0, a3: (int)a1) == 0 )
          return 0;
        *((_DWORD *)a1 + 95) = 0;
        continue;
      case 194:
        if ( sub_1019CF80(a1: 1, a2: 0, a3: (int)a1) == 0 )
          return 0;
        *((_DWORD *)a1 + 95) = 0;
        continue;
      case 195:
      case 197:
      case 198:
      case 199:
      case 200:
      case 203:
      case 205:
      case 206:
      case 207:
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 60;
        *(_DWORD *)(*(_DWORD *)a1 + 24) = *((_DWORD *)a1 + 95);
        (**(void (__cdecl ***)(struct jpeg_common_struct *))a1)(a1);
        *((_DWORD *)a1 + 95) = 0;
        continue;
      case 196:
        if ( sub_1019D5D0(a1) == 0 )
          return 0;
        *((_DWORD *)a1 + 95) = 0;
        continue;
      case 201:
        if ( sub_1019CF80(a1: 0, a2: 1, a3: (int)a1) == 0 )
          return 0;
        *((_DWORD *)a1 + 95) = 0;
        continue;
      case 202:
        if ( sub_1019CF80(a1: 1, a2: 1, a3: (int)a1) == 0 )
          return 0;
        *((_DWORD *)a1 + 95) = 0;
        continue;
      case 204:
      case 220:
        if ( sub_1019E130(a1) == 0 )
          return 0;
        *((_DWORD *)a1 + 95) = 0;
        continue;
      case 216:
        if ( sub_1019CED0((int)a1) == 0 )
          return 0;
        goto LABEL_32;
      case 217:
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 85;
        (*(void (__cdecl **)(struct jpeg_common_struct *, int))(*(_DWORD *)a1 + 4))(a1, a2: 1);
        *((_DWORD *)a1 + 95) = 0;
        return 2;
      case 218:
        if ( sub_1019D2B0(a1) == 0 )
          return 0;
        *((_DWORD *)a1 + 95) = 0;
        return 1;
      case 219:
        if ( sub_1019D900(a1) == 0 )
          return 0;
        *((_DWORD *)a1 + 95) = 0;
        continue;
      case 221:
        if ( sub_1019DB80(a1) == 0 )
          return 0;
        *((_DWORD *)a1 + 95) = 0;
        continue;
      case 224:
      case 225:
      case 226:
      case 227:
      case 228:
      case 229:
      case 230:
      case 231:
      case 232:
      case 233:
      case 234:
      case 235:
      case 236:
      case 237:
      case 238:
      case 239:
        if ( (*(unsigned __int8 (__cdecl **)(struct jpeg_common_struct *))(*((_DWORD *)a1 + 101) + 4 * v2 - 868))(a1) == 0 )
          return 0;
        *((_DWORD *)a1 + 95) = 0;
        continue;
      case 254:
        if ( (*(unsigned __int8 (__cdecl **)(struct jpeg_common_struct *))(*((_DWORD *)a1 + 101) + 24))(a1) == 0 )
          return 0;
        *((_DWORD *)a1 + 95) = 0;
        continue;
      default:
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 68;
        *(_DWORD *)(*(_DWORD *)a1 + 24) = *((_DWORD *)a1 + 95);
        (**(void (__cdecl ***)(struct jpeg_common_struct *))a1)(a1);
LABEL_32:
        *((_DWORD *)a1 + 95) = 0;
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019E7D0
// Name: unsigned char jpeg_resync_to_restart(struct jpeg_decompress_struct __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 __cdecl jpeg_resync_to_restart(struct jpeg_decompress_struct *a1, int a2)
{
  int v2; // ebx
  int v3; // edi
  int v4; // edi
  int v5; // edi

  v2 = *((_DWORD *)a1 + 95);
  *(_DWORD *)(*(_DWORD *)a1 + 20) = 121;
  *(_DWORD *)(*(_DWORD *)a1 + 24) = v2;
  *(_DWORD *)(*(_DWORD *)a1 + 28) = a2;
  (*(void (__cdecl **)(struct jpeg_decompress_struct *, int))(*(_DWORD *)a1 + 4))(a1, a2: -1);
  while ( 1 )
  {
    if ( v2 < 192 )
    {
LABEL_3:
      v3 = 2;
      goto LABEL_11;
    }
    if ( (unsigned int)(v2 - 208) > 7 || v2 == (((_BYTE)a2 + 1) & 7) + 208 || v2 == (((_BYTE)a2 + 2) & 7) + 208 )
    {
      v3 = 3;
    }
    else
    {
      if ( v2 == (((_BYTE)a2 - 1) & 7) + 208 || v2 == (((_BYTE)a2 - 2) & 7) + 208 )
        goto LABEL_3;
      v3 = 1;
    }
LABEL_11:
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 97;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = v2;
    *(_DWORD *)(*(_DWORD *)a1 + 28) = v3;
    (*(void (__cdecl **)(struct jpeg_decompress_struct *, int))(*(_DWORD *)a1 + 4))(a1, a2: 4);
    v4 = v3 - 1;
    if ( v4 == 0 )
      break;
    v5 = v4 - 1;
    if ( v5 != 0 )
    {
      if ( v5 == 1 )
        return 1;
    }
    else
    {
      if ( sub_1019E1E0(a1) == 0 )
        return 0;
      v2 = *((_DWORD *)a1 + 95);
    }
  }
  *((_DWORD *)a1 + 95) = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1019E8D0
// Name: sub_1019E8D0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1019E8D0(_DWORD *a1)
{
  int result; // eax

  result = a1[101];
  a1[49] = 0;
  a1[31] = 0;
  a1[95] = 0;
  *(_BYTE *)(result + 12) = 0;
  *(_BYTE *)(result + 13) = 0;
  *(_DWORD *)(result + 20) = 0;
  *(_DWORD *)(result + 160) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019E900
// Name: void jinit_marker_reader(struct jpeg_decompress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jinit_marker_reader(struct jpeg_decompress_struct *a1)
{
  _DWORD *v1; // eax
  _DWORD *v2; // ecx
  int i; // edx

  v1 = (_DWORD *)(**((int (__cdecl ***)(struct jpeg_decompress_struct *, _DWORD, int))a1 + 1))(a1, a2: 0, a3: 168);
  *((_DWORD *)a1 + 101) = v1;
  *v1 = sub_1019E8D0;
  v1[1] = sub_1019E3C0;
  v1[2] = sub_1019E740;
  v1[6] = sub_1019E130;
  v1[23] = 0;
  v2 = v1 + 24;
  for ( i = 16; i != 0; --i )
  {
    *(v2 - 17) = sub_1019E130;
    *v2++ = 0;
  }
  v1[7] = sub_1019DF90;
  v1[21] = sub_1019DF90;
  sub_1019E8D0(a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019E980
// Name: sub_1019E980
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn sub_1019E980(struct jpeg_common_struct *a1)
{
  (*(void (__cdecl **)(struct jpeg_common_struct *))(*(_DWORD *)a1 + 8))(a1);
  jpeg_destroy(a1);
  exit(code: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1019E9A0
// Name: sub_1019E9A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1019E9A0(int a1)
{
  _iobuf *v1; // eax
  char v3[200]; // [esp+0h] [ebp-CCh] BYREF

  (*(void (__cdecl **)(int, char *))(*(_DWORD *)a1 + 12))(a1, a2: v3);
  v1 = __iob_func();
  return fprintf(str: v1 + 2, format: "%s\n", v3);
}

//------------------------------------------------------------------------------
// Address: 0x1019EA00
// Name: sub_1019EA00
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1019EA00(int *a1, int a2)
{
  int result; // eax
  int v3; // esi

  result = a2;
  v3 = *a1;
  if ( a2 >= 0 )
  {
    if ( *(_DWORD *)(v3 + 104) >= a2 )
      return (*(int (__cdecl **)(int *))(v3 + 8))(a1);
  }
  else
  {
    if ( *(_DWORD *)(v3 + 108) == 0 || *(int *)(v3 + 104) >= 3 )
      result = (*(int (__cdecl **)(int *))(v3 + 8))(a1);
    ++*(_DWORD *)(v3 + 108);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019EA40
// Name: sub_1019EA40
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1019EA40(int a1, char *string)
{
  _DWORD *v2; // eax
  int v3; // ecx
  const char *v4; // esi
  int v5; // esi
  int v6; // edx
  char v7; // cl
  char *v8; // edx

  v2 = *(_DWORD **)a1;
  v3 = *(_DWORD *)(*(_DWORD *)a1 + 20);
  if ( v3 <= 0 || v3 > v2[29] )
  {
    v5 = v2[30];
    if ( v5 == 0 )
      goto LABEL_9;
    v6 = v2[31];
    if ( v3 < v6 || v3 > v2[32] )
      goto LABEL_9;
    v4 = *(const char **)(v5 + 4 * (v3 - v6));
  }
  else
  {
    v4 = *(const char **)(v2[28] + 4 * v3);
  }
  if ( v4 == nullptr )
  {
LABEL_9:
    v2[6] = v3;
    v4 = *(const char **)v2[28];
  }
  v7 = *v4;
  v8 = (char *)v4;
  if ( *v4 == 0 )
    return sprintf(string, format: v4, v2[6], v2[7], v2[8], v2[9], v2[10], v2[11], v2[12], v2[13]);
  while ( 1 )
  {
    ++v8;
    if ( v7 == 37 )
      break;
    v7 = *v8;
    if ( *v8 == 0 )
      return sprintf(string, format: v4, v2[6], v2[7], v2[8], v2[9], v2[10], v2[11], v2[12], v2[13]);
  }
  if ( *v8 == 115 )
    return sprintf(string, format: v4, v2 + 6);
  else
    return sprintf(string, format: v4, v2[6], v2[7], v2[8], v2[9], v2[10], v2[11], v2[12], v2[13]);
}

//------------------------------------------------------------------------------
// Address: 0x1019EAF0
// Name: sub_1019EAF0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_1019EAF0(int *a1)
{
  int result; // eax

  *(_DWORD *)(*a1 + 108) = 0;
  result = *a1;
  *(_DWORD *)(*a1 + 20) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019EB10
// Name: struct jpeg_error_mgr __near * jpeg_std_error(struct jpeg_error_mgr __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct jpeg_error_mgr *__cdecl jpeg_std_error(struct jpeg_error_mgr *a1)
{
  *(_DWORD *)a1 = sub_1019E980;
  *((_DWORD *)a1 + 1) = sub_1019EA00;
  *((_DWORD *)a1 + 2) = sub_1019E9A0;
  *((_DWORD *)a1 + 3) = sub_1019EA40;
  *((_DWORD *)a1 + 4) = sub_1019EAF0;
  *((_DWORD *)a1 + 26) = 0;
  *((_DWORD *)a1 + 27) = 0;
  *((_DWORD *)a1 + 5) = 0;
  *((_DWORD *)a1 + 28) = off_102AC390;
  *((_DWORD *)a1 + 29) = 123;
  *((_DWORD *)a1 + 30) = 0;
  *((_DWORD *)a1 + 31) = 0;
  *((_DWORD *)a1 + 32) = 0;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x1019EB60
// Name: sub_1019EB60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall sub_1019EB60@<al>(int a1@<esi>)
{
  unsigned int *v1; // edi
  unsigned int v2; // eax
  int v3; // ecx
  unsigned int v4; // ebx

  if ( *(_DWORD *)(a1 + 20) != 204 )
  {
    (**(void (__cdecl ***)(int))(a1 + 384))(a1);
    *(_DWORD *)(a1 + 120) = 0;
    *(_DWORD *)(a1 + 20) = 204;
  }
  if ( *(_BYTE *)(*(_DWORD *)(a1 + 384) + 8) != 0 )
  {
    v1 = (unsigned int *)(a1 + 120);
    while ( 1 )
    {
      v2 = *v1;
      if ( *v1 < *(_DWORD *)(a1 + 96) )
        break;
LABEL_10:
      (*(void (__cdecl **)(int))(*(_DWORD *)(a1 + 384) + 4))(a1);
      (**(void (__cdecl ***)(int))(a1 + 384))(a1);
      *v1 = 0;
      if ( *(_BYTE *)(*(_DWORD *)(a1 + 384) + 8) == 0 )
        goto LABEL_11;
    }
    while ( 1 )
    {
      v3 = *(_DWORD *)(a1 + 8);
      if ( v3 != 0 )
      {
        *(_DWORD *)(v3 + 4) = v2;
        *(_DWORD *)(*(_DWORD *)(a1 + 8) + 8) = *(_DWORD *)(a1 + 96);
        (**(void (__cdecl ***)(int))(a1 + 8))(a1);
      }
      v4 = *v1;
      (*(void (__cdecl **)(int, _DWORD, int, _DWORD))(*(_DWORD *)(a1 + 388) + 4))(a1, a2: 0, a3: a1 + 120, a4: 0);
      v2 = *v1;
      if ( *v1 == v4 )
        return 0;
      if ( v2 >= *(_DWORD *)(a1 + 96) )
        goto LABEL_10;
    }
  }
  else
  {
LABEL_11:
    *(_DWORD *)(a1 + 20) = (*(_BYTE *)(a1 + 65) != 0) + 205;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019EC30
// Name: unsigned int jpeg_read_scanlines(struct jpeg_decompress_struct __near *,unsigned char __near * __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct jpeg_decompress_struct *__cdecl jpeg_read_scanlines(
        struct jpeg_decompress_struct *a1,
        unsigned __int8 **a2,
        unsigned int a3)
{
  struct jpeg_decompress_struct *v3; // esi
  unsigned int v4; // ecx
  struct jpeg_decompress_struct *result; // eax
  int v6; // eax
  int v7; // eax

  v3 = a1;
  if ( *((_DWORD *)a1 + 5) != 205 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 20;
    *(_DWORD *)(*(_DWORD *)v3 + 24) = *((_DWORD *)v3 + 5);
    (**(void (__cdecl ***)(struct jpeg_decompress_struct *))v3)(a1: v3);
  }
  v4 = *((_DWORD *)v3 + 30);
  if ( v4 < *((_DWORD *)v3 + 24) )
  {
    v6 = *((_DWORD *)v3 + 2);
    if ( v6 != 0 )
    {
      *(_DWORD *)(v6 + 4) = v4;
      *(_DWORD *)(*((_DWORD *)v3 + 2) + 8) = *((_DWORD *)v3 + 24);
      (**((void (__cdecl ***)(struct jpeg_decompress_struct *))v3 + 2))(a1: v3);
    }
    v7 = *((_DWORD *)v3 + 97);
    a1 = nullptr;
    (*(void (__cdecl **)(struct jpeg_decompress_struct *, unsigned __int8 **, struct jpeg_decompress_struct **, unsigned int))(v7 + 4))(
      a1: v3,
      a2,
      a3: &a1,
      a4: a3);
    result = a1;
    *((_DWORD *)v3 + 30) += a1;
  }
  else
  {
    *(_DWORD *)(*(_DWORD *)v3 + 20) = 123;
    (*(void (__cdecl **)(struct jpeg_decompress_struct *, int))(*(_DWORD *)v3 + 4))(a1: v3, a2: -1);
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019ECD0
// Name: unsigned char jpeg_start_decompress(struct jpeg_decompress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 __cdecl jpeg_start_decompress(struct jpeg_decompress_struct *a1)
{
  int v2; // eax
  void (__cdecl **v3)(struct jpeg_decompress_struct *); // eax
  int v4; // eax
  int v5; // ecx
  int v6; // eax

  if ( *((_DWORD *)a1 + 5) == 202 )
  {
    jinit_master_decompress(a1);
    if ( *((_BYTE *)a1 + 64) != 0 )
    {
      *((_DWORD *)a1 + 5) = 207;
      return 1;
    }
    *((_DWORD *)a1 + 5) = 203;
  }
  v2 = *((_DWORD *)a1 + 5);
  if ( v2 == 203 )
  {
    if ( *(_BYTE *)(*((_DWORD *)a1 + 100) + 16) != 0 )
    {
      while ( 1 )
      {
        v3 = *((void (__cdecl ***)(struct jpeg_decompress_struct *))a1 + 2);
        if ( v3 != nullptr )
          (*v3)(a1);
        v4 = (**((int (__cdecl ***)(struct jpeg_decompress_struct *))a1 + 100))(a1);
        if ( v4 == 0 )
          return 0;
        if ( v4 == 2 )
          goto LABEL_17;
        v5 = *((_DWORD *)a1 + 2);
        if ( v5 != 0 && (v4 == 3 || v4 == 1) )
        {
          ++*(_DWORD *)(v5 + 4);
          v6 = *((_DWORD *)a1 + 2);
          if ( *(_DWORD *)(v6 + 4) >= *(_DWORD *)(v6 + 8) )
            *(_DWORD *)(v6 + 8) += *((_DWORD *)a1 + 71);
        }
      }
    }
    else
    {
LABEL_17:
      *((_DWORD *)a1 + 33) = *((_DWORD *)a1 + 31);
      return sub_1019EB60((int)a1);
    }
  }
  else
  {
    if ( v2 != 204 )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 20;
      *(_DWORD *)(*(_DWORD *)a1 + 24) = *((_DWORD *)a1 + 5);
      (**(void (__cdecl ***)(struct jpeg_decompress_struct *))a1)(a1);
    }
    return sub_1019EB60((int)a1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019EDB0
// Name: sub_1019EDB0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_1019EDB0@<eax>(_BYTE *a1@<esi>)
{
  bool v1; // zf
  int result; // eax
  int v3; // ecx
  int v4; // eax
  struct jpeg_decompress_struct *v5; // [esp+0h] [ebp-4h]

  v1 = a1[201] == 0;
  a1[64] = 1;
  if ( v1 )
  {
    if ( a1[200] != 0 )
      jinit_phuff_decoder(a1: v5);
    else
      jinit_huff_decoder(a1: v5);
  }
  else
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 1;
    (**(void (***)(void))a1)();
  }
  jinit_d_coef_controller((struct jpeg_decompress_struct *)a1, a2: 1u);
  (*(void (__cdecl **)(_BYTE *))(*((_DWORD *)a1 + 1) + 24))(a1);
  result = (*(int (__cdecl **)(_BYTE *))(*((_DWORD *)a1 + 100) + 8))(a1);
  v3 = *((_DWORD *)a1 + 2);
  if ( v3 != 0 )
  {
    if ( a1[200] != 0 )
    {
      v4 = 3 * *((_DWORD *)a1 + 9) + 2;
    }
    else if ( *(_BYTE *)(*((_DWORD *)a1 + 100) + 16) != 0 )
    {
      v4 = *((_DWORD *)a1 + 9);
    }
    else
    {
      v4 = 1;
    }
    *(_DWORD *)(v3 + 4) = 0;
    *(_DWORD *)(*((_DWORD *)a1 + 2) + 8) = v4 * *((_DWORD *)a1 + 71);
    result = *((_DWORD *)a1 + 2);
    *(_DWORD *)(result + 12) = 0;
    *(_DWORD *)(*((_DWORD *)a1 + 2) + 16) = 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019EE70
// Name: struct jvirt_barray_control __near * __near * jpeg_read_coefficients(struct jpeg_decompress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct jvirt_barray_control **__cdecl jpeg_read_coefficients(struct jpeg_decompress_struct *a1)
{
  void (__cdecl **v1)(struct jpeg_decompress_struct *); // eax
  int v2; // eax
  int v3; // ecx
  int v4; // eax
  int v5; // eax

  if ( *((_DWORD *)a1 + 5) == 202 )
  {
    sub_1019EDB0(a1);
    *((_DWORD *)a1 + 5) = 209;
  }
  if ( *((_DWORD *)a1 + 5) == 209 )
  {
    while ( 1 )
    {
      v1 = *((void (__cdecl ***)(struct jpeg_decompress_struct *))a1 + 2);
      if ( v1 != nullptr )
        (*v1)(a1);
      v2 = (**((int (__cdecl ***)(struct jpeg_decompress_struct *))a1 + 100))(a1);
      if ( v2 == 0 )
        break;
      if ( v2 == 2 )
      {
        *((_DWORD *)a1 + 5) = 210;
        goto LABEL_14;
      }
      v3 = *((_DWORD *)a1 + 2);
      if ( v3 != 0 && (v2 == 3 || v2 == 1) )
      {
        ++*(_DWORD *)(v3 + 4);
        v4 = *((_DWORD *)a1 + 2);
        if ( *(_DWORD *)(v4 + 4) >= *(_DWORD *)(v4 + 8) )
          *(_DWORD *)(v4 + 8) += *((_DWORD *)a1 + 71);
      }
    }
  }
  else
  {
LABEL_14:
    v5 = *((_DWORD *)a1 + 5);
    if ( (v5 == 210 || v5 == 207) && *((_BYTE *)a1 + 64) != 0 )
      return *(struct jvirt_barray_control ***)(*((_DWORD *)a1 + 98) + 16);
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 20;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = *((_DWORD *)a1 + 5);
    (**(void (__cdecl ***)(struct jpeg_decompress_struct *))a1)(a1);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1019EF30
// Name: void jpeg_start_compress(struct jpeg_compress_struct __near *,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_start_compress(struct jpeg_compress_struct *a1, char a2)
{
  bool v2; // zf

  if ( *((_DWORD *)a1 + 5) != 100 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 20;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = *((_DWORD *)a1 + 5);
    (**(void (__cdecl ***)(struct jpeg_compress_struct *))a1)(a1);
  }
  if ( a2 != 0 )
    jpeg_suppress_tables(a1, a2: 0);
  (*(void (__cdecl **)(struct jpeg_compress_struct *))(*(_DWORD *)a1 + 16))(a1);
  (*(void (__cdecl **)(struct jpeg_compress_struct *))(*((_DWORD *)a1 + 6) + 8))(a1);
  jinit_compress_master(a1);
  (**((void (__cdecl ***)(struct jpeg_compress_struct *))a1 + 79))(a1);
  v2 = *((_BYTE *)a1 + 176) == 0;
  *((_DWORD *)a1 + 52) = 0;
  *((_DWORD *)a1 + 5) = !v2 + 101;
}

//------------------------------------------------------------------------------
// Address: 0x1019EFB0
// Name: unsigned int jpeg_write_scanlines(struct jpeg_compress_struct __near *,unsigned char __near * __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct jpeg_compress_struct *__cdecl jpeg_write_scanlines(
        struct jpeg_compress_struct *a1,
        unsigned __int8 **a2,
        unsigned int a3)
{
  struct jpeg_compress_struct *v3; // esi
  int v4; // eax
  int v5; // eax
  int v6; // ecx
  int v7; // edx
  struct jpeg_compress_struct *result; // eax

  v3 = a1;
  if ( *((_DWORD *)a1 + 5) != 101 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 20;
    *(_DWORD *)(*(_DWORD *)v3 + 24) = *((_DWORD *)v3 + 5);
    (**(void (__cdecl ***)(struct jpeg_compress_struct *))v3)(a1: v3);
  }
  if ( *((_DWORD *)v3 + 52) >= *((_DWORD *)v3 + 8) )
  {
    *(_DWORD *)(*(_DWORD *)v3 + 20) = 123;
    (*(void (__cdecl **)(struct jpeg_compress_struct *, int))(*(_DWORD *)v3 + 4))(a1: v3, a2: -1);
  }
  v4 = *((_DWORD *)v3 + 2);
  if ( v4 != 0 )
  {
    *(_DWORD *)(v4 + 4) = *((_DWORD *)v3 + 52);
    *(_DWORD *)(*((_DWORD *)v3 + 2) + 8) = *((_DWORD *)v3 + 8);
    (**((void (__cdecl ***)(struct jpeg_compress_struct *))v3 + 2))(a1: v3);
  }
  v5 = *((_DWORD *)v3 + 79);
  if ( *(_BYTE *)(v5 + 12) != 0 )
    (*(void (__cdecl **)(struct jpeg_compress_struct *))(v5 + 4))(a1: v3);
  v6 = a3;
  if ( a3 > *((_DWORD *)v3 + 8) - *((_DWORD *)v3 + 52) )
    v6 = *((_DWORD *)v3 + 8) - *((_DWORD *)v3 + 52);
  v7 = *((_DWORD *)v3 + 80);
  a1 = nullptr;
  (*(void (__cdecl **)(struct jpeg_compress_struct *, unsigned __int8 **, struct jpeg_compress_struct **, int))(v7 + 4))(
    a1: v3,
    a2,
    a3: &a1,
    a4: v6);
  result = a1;
  *((_DWORD *)v3 + 52) += a1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019F080
// Name: void jpeg_add_quant_table(struct jpeg_compress_struct __near *,int,unsigned int const __near *,int,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_add_quant_table(
        struct jpeg_compress_struct *a1,
        unsigned int a2,
        const unsigned int *a3,
        int a4,
        char a5)
{
  int v5; // esi
  const unsigned int *v6; // edi
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax

  if ( *((_DWORD *)a1 + 5) != 100 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 20;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = *((_DWORD *)a1 + 5);
    (**(void (__cdecl ***)(struct jpeg_compress_struct *))a1)(a1);
  }
  if ( a2 >= 4 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 31;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = a2;
    (**(void (__cdecl ***)(struct jpeg_compress_struct *))a1)(a1);
  }
  if ( *((_DWORD *)a1 + a2 + 18) == 0 )
    *((_DWORD *)a1 + a2 + 18) = jpeg_alloc_quant_table(a1);
  v5 = 0;
  v6 = a3 + 2;
  do
  {
    v7 = (signed int)(a4 * *(v6 - 2) + 50) / 100;
    if ( v7 > 0 )
    {
      if ( v7 > 0x7FFF )
        v7 = 0x7FFF;
    }
    else
    {
      v7 = 1;
    }
    if ( a5 != 0 && v7 > 255 )
      LOWORD(v7) = 255;
    *(_WORD *)(v5 + *((_DWORD *)a1 + a2 + 18)) = v7;
    v8 = (signed int)(a4 * *(v6 - 1) + 50) / 100;
    if ( v8 > 0 )
    {
      if ( v8 > 0x7FFF )
        v8 = 0x7FFF;
    }
    else
    {
      v8 = 1;
    }
    if ( a5 != 0 && v8 > 255 )
      LOWORD(v8) = 255;
    *(_WORD *)(*((_DWORD *)a1 + a2 + 18) + v5 + 2) = v8;
    v9 = (signed int)(a4 * *v6 + 50) / 100;
    if ( v9 > 0 )
    {
      if ( v9 > 0x7FFF )
        v9 = 0x7FFF;
    }
    else
    {
      v9 = 1;
    }
    if ( a5 != 0 && v9 > 255 )
      LOWORD(v9) = 255;
    *(_WORD *)(*((_DWORD *)a1 + a2 + 18) + v5 + 4) = v9;
    v10 = (signed int)(a4 * v6[1] + 50) / 100;
    if ( v10 > 0 )
    {
      if ( v10 > 0x7FFF )
        v10 = 0x7FFF;
    }
    else
    {
      v10 = 1;
    }
    if ( a5 != 0 && v10 > 255 )
      LOWORD(v10) = 255;
    *(_WORD *)(v5 + *((_DWORD *)a1 + a2 + 18) + 6) = v10;
    v5 += 8;
    v6 += 4;
  }
  while ( v5 < 128 );
  *(_BYTE *)(*((_DWORD *)a1 + a2 + 18) + 128) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1019F250
// Name: void jpeg_set_linear_quality(struct jpeg_compress_struct __near *,int,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_set_linear_quality(struct jpeg_compress_struct *a1, int a2, char a3)
{
  jpeg_add_quant_table(a1, a2: 0, a3: &dword_102AC688, a4: a2, a5: a3);
  jpeg_add_quant_table(a1, a2: 1u, a3: &dword_102AC588, a4: a2, a5: a3);
}

//------------------------------------------------------------------------------
// Address: 0x1019F290
// Name: int jpeg_quality_scaling(int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl jpeg_quality_scaling(int a1)
{
  int v1; // ecx

  v1 = a1;
  if ( a1 <= 0 )
    return 5000;
  if ( a1 > 100 )
  {
    v1 = 100;
    return 2 * (100 - v1);
  }
  if ( a1 >= 50 )
    return 2 * (100 - v1);
  return 5000 / a1;
}

//------------------------------------------------------------------------------
// Address: 0x1019F2D0
// Name: void jpeg_set_quality(struct jpeg_compress_struct __near *,int,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_set_quality(struct jpeg_compress_struct *a1, int a2, char a3)
{
  int v3; // eax

  v3 = jpeg_quality_scaling(a1: a2);
  jpeg_set_linear_quality(a1, a2: v3, a3);
}

//------------------------------------------------------------------------------
// Address: 0x1019F300
// Name: sub_1019F300
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_1019F300(int a1@<eax>, int *a2@<ebx>, struct jpeg_common_struct *a3, unsigned __int8 *src)
{
  int v5; // eax
  signed int v6; // edi
  unsigned __int8 *v7; // eax
  int i; // ecx
  int v9; // edx
  int v10; // esi

  if ( *a2 == 0 )
    *a2 = (int)jpeg_alloc_huff_table(a1: a3);
  v5 = *a2;
  *(_DWORD *)v5 = *(_DWORD *)a1;
  *(_DWORD *)(v5 + 4) = *(_DWORD *)(a1 + 4);
  *(_DWORD *)(v5 + 8) = *(_DWORD *)(a1 + 8);
  *(_DWORD *)(v5 + 12) = *(_DWORD *)(a1 + 12);
  *(_BYTE *)(v5 + 16) = *(_BYTE *)(a1 + 16);
  v6 = 0;
  v7 = (unsigned __int8 *)(a1 + 3);
  for ( i = 4; i != 0; --i )
  {
    v9 = v7[1] + *(v7 - 1) + *(v7 - 2);
    v10 = v6 + *v7;
    v7 += 4;
    v6 = v10 + v9;
  }
  if ( v6 < 1 || v6 > 256 )
  {
    *(_DWORD *)(*(_DWORD *)a3 + 20) = 8;
    (**(void (__cdecl ***)(struct jpeg_common_struct *))a3)(a1: a3);
  }
  memcpy(dst: (unsigned __int8 *)(*a2 + 17), src, count: v6);
  *(_BYTE *)(*a2 + 273) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1019F3B0
// Name: sub_1019F3B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_1019F3B0(int a1@<esi>)
{
  sub_1019F300(
    a1: (int)&unk_102AC914,
    a2: (int *)(a1 + 88),
    a3: (struct jpeg_common_struct *)a1,
    src: (unsigned __int8 *)&byte_102AC928);
  sub_1019F300(
    a1: (int)&unk_102AC858,
    a2: (int *)(a1 + 104),
    a3: (struct jpeg_common_struct *)a1,
    src: (unsigned __int8 *)&byte_102AC870);
  sub_1019F300(
    a1: (int)&unk_102AC844,
    a2: (int *)(a1 + 92),
    a3: (struct jpeg_common_struct *)a1,
    src: (unsigned __int8 *)&byte_102AC928);
  sub_1019F300(
    a1: (int)&unk_102AC788,
    a2: (int *)(a1 + 108),
    a3: (struct jpeg_common_struct *)a1,
    src: (unsigned __int8 *)&byte_102AC7A0);
}

//------------------------------------------------------------------------------
// Address: 0x1019F410
// Name: void jpeg_set_colorspace(struct jpeg_compress_struct __near *,enum J_COLOR_SPACE)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl jpeg_set_colorspace(int a1, int a2)
{
  _DWORD *v2; // esi
  int result; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // esi
  _DWORD *v6; // eax
  _DWORD *v7; // esi
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  _DWORD *v10; // esi
  _DWORD *v11; // eax
  _DWORD *v12; // eax
  _DWORD *v13; // esi
  int v14; // ecx
  int v15; // edx

  if ( *(_DWORD *)(a1 + 20) != 100 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 20;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = *(_DWORD *)(a1 + 20);
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  *(_DWORD *)(a1 + 64) = a2;
  *(_BYTE *)(a1 + 196) = 0;
  *(_BYTE *)(a1 + 204) = 0;
  switch ( a2 )
  {
    case 0:
      result = *(_DWORD *)(a1 + 36);
      *(_DWORD *)(a1 + 60) = result;
      if ( result < 1 || result > 10 )
      {
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 26;
        *(_DWORD *)(*(_DWORD *)a1 + 24) = *(_DWORD *)(a1 + 60);
        *(_DWORD *)(*(_DWORD *)a1 + 28) = 10;
        result = (**(int (__cdecl ***)(int))a1)(a1);
      }
      v14 = 0;
      if ( *(int *)(a1 + 60) > 0 )
      {
        v15 = 0;
        do
        {
          result = v15 + *(_DWORD *)(a1 + 68);
          *(_DWORD *)result = v14++;
          *(_DWORD *)(result + 8) = 1;
          *(_DWORD *)(result + 12) = 1;
          *(_DWORD *)(result + 16) = 0;
          *(_DWORD *)(result + 20) = 0;
          *(_DWORD *)(result + 24) = 0;
          v15 += 84;
        }
        while ( v14 < *(_DWORD *)(a1 + 60) );
      }
      break;
    case 1:
      *(_BYTE *)(a1 + 196) = 1;
      *(_DWORD *)(a1 + 60) = 1;
      v2 = *(_DWORD **)(a1 + 68);
      *v2 = 1;
      v2[2] = 1;
      v2[3] = 1;
      v2[4] = 0;
      v2[5] = 0;
      v2[6] = 0;
      result = 0;
      break;
    case 2:
      v4 = *(_DWORD **)(a1 + 68);
      *(_DWORD *)(a1 + 60) = 3;
      *(_BYTE *)(a1 + 204) = 1;
      v4[2] = 1;
      v4[3] = 1;
      *v4 = 82;
      v4[4] = 0;
      v4[5] = 0;
      v4[6] = 0;
      result = *(_DWORD *)(a1 + 68) + 84;
      *(_DWORD *)(result + 8) = 1;
      *(_DWORD *)(result + 12) = 1;
      *(_DWORD *)result = 71;
      *(_DWORD *)(result + 16) = 0;
      *(_DWORD *)(result + 20) = 0;
      *(_DWORD *)(result + 24) = 0;
      v5 = (_DWORD *)(*(_DWORD *)(a1 + 68) + 168);
      v5[2] = 1;
      v5[3] = 1;
      *v5 = 66;
      v5[4] = 0;
      v5[5] = 0;
      v5[6] = 0;
      break;
    case 3:
      v6 = *(_DWORD **)(a1 + 68);
      *(_DWORD *)(a1 + 60) = 3;
      *(_BYTE *)(a1 + 196) = 1;
      *v6 = 1;
      v6[4] = 0;
      v6[5] = 0;
      v6[6] = 0;
      v6[2] = 2;
      v6[3] = 2;
      result = *(_DWORD *)(a1 + 68) + 84;
      *(_DWORD *)(result + 8) = 1;
      *(_DWORD *)(result + 12) = 1;
      *(_DWORD *)(result + 16) = 1;
      *(_DWORD *)(result + 20) = 1;
      *(_DWORD *)(result + 24) = 1;
      *(_DWORD *)result = 2;
      v7 = (_DWORD *)(*(_DWORD *)(a1 + 68) + 168);
      v7[2] = 1;
      v7[3] = 1;
      v7[4] = 1;
      v7[5] = 1;
      v7[6] = 1;
      *v7 = 3;
      break;
    case 4:
      v8 = *(_DWORD **)(a1 + 68);
      *(_DWORD *)(a1 + 60) = 4;
      *(_BYTE *)(a1 + 204) = 1;
      v8[2] = 1;
      v8[3] = 1;
      *v8 = 67;
      v8[4] = 0;
      v8[5] = 0;
      v8[6] = 0;
      v9 = *(_DWORD **)(a1 + 68);
      v9[23] = 1;
      v9[24] = 1;
      v9[21] = 77;
      v9[25] = 0;
      v9[26] = 0;
      v9[27] = 0;
      result = *(_DWORD *)(a1 + 68) + 168;
      *(_DWORD *)(result + 8) = 1;
      *(_DWORD *)(result + 12) = 1;
      *(_DWORD *)result = 89;
      *(_DWORD *)(result + 16) = 0;
      *(_DWORD *)(result + 20) = 0;
      *(_DWORD *)(result + 24) = 0;
      v10 = (_DWORD *)(*(_DWORD *)(a1 + 68) + 252);
      v10[2] = 1;
      v10[3] = 1;
      *v10 = 75;
      v10[4] = 0;
      v10[5] = 0;
      v10[6] = 0;
      break;
    case 5:
      v11 = *(_DWORD **)(a1 + 68);
      *(_DWORD *)(a1 + 60) = 4;
      *(_BYTE *)(a1 + 204) = 1;
      *v11 = 1;
      v11[4] = 0;
      v11[5] = 0;
      v11[6] = 0;
      v11[2] = 2;
      v11[3] = 2;
      v12 = *(_DWORD **)(a1 + 68);
      v12[23] = 1;
      v12[24] = 1;
      v12[25] = 1;
      v12[26] = 1;
      v12[27] = 1;
      v12[21] = 2;
      result = *(_DWORD *)(a1 + 68) + 168;
      *(_DWORD *)(result + 8) = 1;
      *(_DWORD *)(result + 12) = 1;
      *(_DWORD *)(result + 16) = 1;
      *(_DWORD *)(result + 20) = 1;
      *(_DWORD *)(result + 24) = 1;
      *(_DWORD *)result = 3;
      v13 = (_DWORD *)(*(_DWORD *)(a1 + 68) + 252);
      *v13 = 4;
      v13[2] = 2;
      v13[3] = 2;
      v13[4] = 0;
      v13[5] = 0;
      v13[6] = 0;
      break;
    default:
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 10;
      result = (**(int (__cdecl ***)(int))a1)(a1);
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019F700
// Name: void jpeg_default_colorspace(struct jpeg_compress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_default_colorspace(struct jpeg_compress_struct *a1)
{
  switch ( *((_DWORD *)a1 + 10) )
  {
    case 0:
      jpeg_set_colorspace((int)a1, a2: 0);
      break;
    case 1:
      jpeg_set_colorspace((int)a1, a2: 1);
      break;
    case 2:
    case 3:
      jpeg_set_colorspace((int)a1, a2: 3);
      break;
    case 4:
      jpeg_set_colorspace((int)a1, a2: 4);
      break;
    case 5:
      jpeg_set_colorspace((int)a1, a2: 5);
      break;
    default:
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 9;
      (**(void (__cdecl ***)(struct jpeg_compress_struct *))a1)(a1);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019F780
// Name: void jpeg_set_defaults(struct jpeg_compress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_set_defaults(struct jpeg_compress_struct *a1)
{
  char *v1; // eax
  int i; // ecx
  bool v3; // cc

  if ( *((_DWORD *)a1 + 5) != 100 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 20;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = *((_DWORD *)a1 + 5);
    (**(void (__cdecl ***)(struct jpeg_compress_struct *))a1)(a1);
  }
  if ( *((_DWORD *)a1 + 17) == 0 )
    *((_DWORD *)a1 + 17) = (**((int (__cdecl ***)(struct jpeg_compress_struct *, _DWORD, int))a1 + 1))(
                             a1,
                             a2: 0,
                             a3: 840);
  *((_DWORD *)a1 + 14) = 8;
  jpeg_set_quality(a1, a2: 75, a3: 1);
  sub_1019F3B0((int)a1);
  v1 = (char *)a1 + 136;
  for ( i = 16; i != 0; --i )
  {
    *(v1 - 16) = 0;
    *v1 = 1;
    v1[16] = 5;
    ++v1;
  }
  v3 = *((_DWORD *)a1 + 14) <= 8;
  *((_DWORD *)a1 + 43) = 0;
  *((_DWORD *)a1 + 42) = 0;
  *((_BYTE *)a1 + 176) = 0;
  *((_BYTE *)a1 + 177) = 0;
  *((_BYTE *)a1 + 178) = 0;
  if ( !v3 )
    *((_BYTE *)a1 + 178) = 1;
  *((_BYTE *)a1 + 179) = 0;
  *((_DWORD *)a1 + 45) = 0;
  *((_DWORD *)a1 + 46) = 0;
  *((_DWORD *)a1 + 47) = 0;
  *((_DWORD *)a1 + 48) = 0;
  *((_BYTE *)a1 + 197) = 1;
  *((_BYTE *)a1 + 198) = 1;
  *((_BYTE *)a1 + 199) = 0;
  *((_WORD *)a1 + 100) = 1;
  *((_WORD *)a1 + 101) = 1;
  jpeg_default_colorspace(a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019F880
// Name: void jpeg_CreateCompress(struct jpeg_compress_struct __near *,int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_CreateCompress(struct jpeg_compress_struct *dst, int a2, unsigned int a3)
{
  int v3; // edi
  int v4; // ebp

  *((_DWORD *)dst + 1) = 0;
  if ( a2 != 62 )
  {
    *(_DWORD *)(*(_DWORD *)dst + 20) = 12;
    *(_DWORD *)(*(_DWORD *)dst + 24) = 62;
    *(_DWORD *)(*(_DWORD *)dst + 28) = a2;
    (**(void (__cdecl ***)(struct jpeg_compress_struct *))dst)(a1: dst);
  }
  if ( a3 != 360 )
  {
    *(_DWORD *)(*(_DWORD *)dst + 20) = 21;
    *(_DWORD *)(*(_DWORD *)dst + 24) = 360;
    *(_DWORD *)(*(_DWORD *)dst + 28) = a3;
    (**(void (__cdecl ***)(struct jpeg_compress_struct *))dst)(a1: dst);
  }
  v3 = *(_DWORD *)dst;
  v4 = *((_DWORD *)dst + 3);
  memset((unsigned __int8 *)dst, value: 0, count: 0x168u);
  *(_DWORD *)dst = v3;
  *((_DWORD *)dst + 3) = v4;
  *((_BYTE *)dst + 16) = 0;
  jinit_memory_mgr(a1: dst);
  *((_DWORD *)dst + 2) = 0;
  *((_DWORD *)dst + 6) = 0;
  *((_DWORD *)dst + 17) = 0;
  *((_DWORD *)dst + 18) = 0;
  *((_DWORD *)dst + 19) = 0;
  *((_DWORD *)dst + 20) = 0;
  *((_DWORD *)dst + 21) = 0;
  *((_DWORD *)dst + 22) = 0;
  *((_DWORD *)dst + 26) = 0;
  *((_DWORD *)dst + 23) = 0;
  *((_DWORD *)dst + 27) = 0;
  *((_DWORD *)dst + 24) = 0;
  *((_DWORD *)dst + 28) = 0;
  *((_DWORD *)dst + 25) = 0;
  *((_DWORD *)dst + 29) = 0;
  *((double *)dst + 6) = 1.0;
  *((_DWORD *)dst + 88) = 0;
  *((_DWORD *)dst + 5) = 100;
}

//------------------------------------------------------------------------------
// Address: 0x1019F950
// Name: void jpeg_suppress_tables(struct jpeg_compress_struct __near *,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_suppress_tables(struct jpeg_compress_struct *a1, char a2)
{
  int v2; // ecx
  int v3; // ecx
  int v4; // ecx
  int v5; // ecx
  char *v6; // eax
  int i; // esi
  int v8; // ecx

  v2 = *((_DWORD *)a1 + 18);
  if ( v2 != 0 )
    *(_BYTE *)(v2 + 128) = a2;
  v3 = *((_DWORD *)a1 + 19);
  if ( v3 != 0 )
    *(_BYTE *)(v3 + 128) = a2;
  v4 = *((_DWORD *)a1 + 20);
  if ( v4 != 0 )
    *(_BYTE *)(v4 + 128) = a2;
  v5 = *((_DWORD *)a1 + 21);
  if ( v5 != 0 )
    *(_BYTE *)(v5 + 128) = a2;
  v6 = (char *)a1 + 104;
  for ( i = 4; i != 0; --i )
  {
    v8 = *((_DWORD *)v6 - 4);
    if ( v8 != 0 )
      *(_BYTE *)(v8 + 273) = a2;
    if ( *(_DWORD *)v6 != 0 )
      *(_BYTE *)(*(_DWORD *)v6 + 273) = a2;
    v6 += 4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019F9C0
// Name: void jpeg_finish_compress(struct jpeg_compress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_finish_compress(struct jpeg_compress_struct *a1)
{
  int v1; // eax
  int i; // eax
  unsigned int j; // edi

  v1 = *((_DWORD *)a1 + 5);
  if ( v1 == 101 || v1 == 102 )
  {
    if ( *((_DWORD *)a1 + 52) < *((_DWORD *)a1 + 8) )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 67;
      (**(void (__cdecl ***)(struct jpeg_compress_struct *))a1)(a1);
    }
    (*(void (__cdecl **)(struct jpeg_compress_struct *))(*((_DWORD *)a1 + 79) + 8))(a1);
  }
  else if ( v1 != 103 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 20;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = *((_DWORD *)a1 + 5);
    (**(void (__cdecl ***)(struct jpeg_compress_struct *))a1)(a1);
  }
  for ( i = *((_DWORD *)a1 + 79); *(_BYTE *)(i + 13) == 0; i = *((_DWORD *)a1 + 79) )
  {
    (*(void (__cdecl **)(struct jpeg_compress_struct *))i)(a1);
    for ( j = 0; j < *((_DWORD *)a1 + 56); ++j )
    {
      if ( *((_DWORD *)a1 + 2) != 0 )
      {
        *(_DWORD *)(*((_DWORD *)a1 + 2) + 4) = j;
        *(_DWORD *)(*((_DWORD *)a1 + 2) + 8) = *((_DWORD *)a1 + 56);
        (**((void (__cdecl ***)(struct jpeg_compress_struct *))a1 + 2))(a1);
      }
      if ( (*(unsigned __int8 (__cdecl **)(struct jpeg_compress_struct *, _DWORD))(*((_DWORD *)a1 + 82) + 4))(a1, a2: 0) == 0 )
      {
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 24;
        (**(void (__cdecl ***)(struct jpeg_compress_struct *))a1)(a1);
      }
    }
    (*(void (__cdecl **)(struct jpeg_compress_struct *))(*((_DWORD *)a1 + 79) + 8))(a1);
  }
  (*(void (__cdecl **)(struct jpeg_compress_struct *))(*((_DWORD *)a1 + 83) + 12))(a1);
  (*(void (__cdecl **)(struct jpeg_compress_struct *))(*((_DWORD *)a1 + 6) + 16))(a1);
  jpeg_abort(a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019FAE0
// Name: void jpeg_copy_critical_parameters(struct jpeg_decompress_struct __near *,struct jpeg_compress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_copy_critical_parameters(struct jpeg_decompress_struct *a1, struct jpeg_compress_struct *a2)
{
  struct jpeg_decompress_struct *v3; // edi
  const void **v4; // esi
  void **v5; // ebx
  bool v6; // zf
  int v7; // eax
  struct jpeg_common_struct *v8; // edx
  _DWORD *v9; // ebx
  unsigned int v10; // esi
  int v11; // ecx
  int v12; // ecx
  _WORD *v13; // edi
  bool v14; // cc
  int v15; // [esp+8h] [ebp-Ch]
  int i; // [esp+8h] [ebp-Ch]
  int v17; // [esp+Ch] [ebp-8h]
  int v18; // [esp+10h] [ebp-4h]
  struct jpeg_common_struct *v19; // [esp+1Ch] [ebp+8h]
  struct jpeg_common_struct *v20; // [esp+1Ch] [ebp+8h]

  if ( *((_DWORD *)a2 + 5) != 100 )
  {
    *(_DWORD *)(*(_DWORD *)a2 + 20) = 20;
    *(_DWORD *)(*(_DWORD *)a2 + 24) = *((_DWORD *)a2 + 5);
    (**(void (__cdecl ***)(struct jpeg_compress_struct *))a2)(a1: a2);
  }
  v3 = a1;
  *((_DWORD *)a2 + 7) = *((_DWORD *)a1 + 7);
  *((_DWORD *)a2 + 8) = *((_DWORD *)a1 + 8);
  *((_DWORD *)a2 + 9) = *((_DWORD *)a1 + 9);
  *((_DWORD *)a2 + 10) = *((_DWORD *)a1 + 10);
  jpeg_set_defaults(a1: a2);
  jpeg_set_colorspace(a1: (int)a2, a2: *((_DWORD *)a1 + 10));
  *((_DWORD *)a2 + 14) = *((_DWORD *)a1 + 48);
  v4 = (const void **)((char *)a1 + 144);
  *((_BYTE *)a2 + 179) = *((_BYTE *)a1 + 266);
  v19 = (struct jpeg_decompress_struct *)((char *)a1 + 144);
  v5 = (void **)((char *)a2 + 72);
  v15 = 4;
  do
  {
    if ( *v4 != nullptr )
    {
      if ( *v5 == nullptr )
        *v5 = jpeg_alloc_quant_table(a1: a2);
      qmemcpy(*v5, *v4, 0x80u);
      v3 = a1;
      v4 = (const void **)v19;
      *((_BYTE *)*v5 + 128) = 0;
    }
    ++v4;
    ++v5;
    v6 = v15-- == 1;
    v19 = (struct jpeg_common_struct *)v4;
  }
  while ( !v6 );
  v7 = *((_DWORD *)v3 + 9);
  *((_DWORD *)a2 + 15) = v7;
  if ( v7 < 1 || v7 > 10 )
  {
    *(_DWORD *)(*(_DWORD *)a2 + 20) = 26;
    *(_DWORD *)(*(_DWORD *)a2 + 24) = *((_DWORD *)a2 + 15);
    *(_DWORD *)(*(_DWORD *)a2 + 28) = 10;
    (**(void (__cdecl ***)(struct jpeg_compress_struct *))a2)(a1: a2);
  }
  v8 = *((struct jpeg_common_struct **)a2 + 17);
  v9 = *((_DWORD **)v3 + 49);
  v17 = 0;
  v20 = v8;
  if ( *((int *)a2 + 15) > 0 )
  {
    do
    {
      *(_DWORD *)v8 = *v9;
      *((_DWORD *)v8 + 2) = v9[2];
      *((_DWORD *)v8 + 3) = v9[3];
      v10 = v9[4];
      *((_DWORD *)v8 + 4) = v10;
      if ( v10 > 3 || *((_DWORD *)v3 + v10 + 36) == 0 )
      {
        *(_DWORD *)(*(_DWORD *)a2 + 20) = 52;
        *(_DWORD *)(*(_DWORD *)a2 + 24) = v10;
        (**(void (__cdecl ***)(struct jpeg_compress_struct *))a2)(a1: a2);
        v8 = v20;
      }
      v11 = v9[19];
      if ( v11 != 0 )
      {
        v12 = v11 - *((_DWORD *)v3 + v10 + 36);
        v13 = *((_WORD **)v3 + v10 + 36);
        v18 = v12;
        for ( i = 64; i != 0; --i )
        {
          if ( *(_WORD *)((char *)v13 + v12) != *v13 )
          {
            *(_DWORD *)(*(_DWORD *)a2 + 20) = 44;
            *(_DWORD *)(*(_DWORD *)a2 + 24) = v10;
            (**(void (__cdecl ***)(struct jpeg_compress_struct *))a2)(a1: a2);
            v12 = v18;
            v8 = v20;
          }
          ++v13;
        }
        v3 = a1;
      }
      v8 = (struct jpeg_common_struct *)((char *)v8 + 84);
      v9 += 21;
      v14 = ++v17 < *((_DWORD *)a2 + 15);
      v20 = v8;
    }
    while ( v14 );
  }
  if ( *((_BYTE *)v3 + 256) != 0 )
  {
    if ( *((_BYTE *)v3 + 257) == 1 )
    {
      *((_BYTE *)a2 + 197) = 1;
      *((_BYTE *)a2 + 198) = *((_BYTE *)v3 + 258);
    }
    *((_BYTE *)a2 + 199) = *((_BYTE *)v3 + 259);
    *((_WORD *)a2 + 100) = *((_WORD *)v3 + 130);
    *((_WORD *)a2 + 101) = *((_WORD *)v3 + 131);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019FD10
// Name: sub_1019FD10
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall sub_1019FD10(_DWORD *this)
{
  _DWORD *result; // eax
  int v2; // edx
  int v3; // esi
  int v4; // ecx

  result = (_DWORD *)*(this + 82);
  v2 = 1;
  if ( (int)*(this + 57) <= 1 )
  {
    v3 = *(this + 56);
    v4 = *(this + 58);
    if ( result[2] < (unsigned int)(v3 - 1) )
    {
      result[5] = *(_DWORD *)(v4 + 12);
      result[3] = 0;
      result[4] = 0;
      return result;
    }
    v2 = *(_DWORD *)(v4 + 72);
  }
  result[5] = v2;
  result[3] = 0;
  result[4] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1019FD60
// Name: sub_1019FD60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__cdecl sub_1019FD60(_DWORD *a1, int a2)
{
  int v2; // edi

  v2 = a1[82];
  if ( a2 != 2 )
  {
    *(_DWORD *)(*a1 + 20) = 4;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  *(_DWORD *)(v2 + 8) = 0;
  return sub_1019FD10(this: a1);
}

//------------------------------------------------------------------------------
// Address: 0x1019FDA0
// Name: sub_1019FDA0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl sub_1019FDA0(_DWORD *a1)
{
  _DWORD *v1; // ebx
  _DWORD *v2; // ebp
  int v3; // esi
  _DWORD *v4; // edi
  int v5; // eax
  int v6; // eax
  unsigned int v7; // esi
  int v8; // eax
  _DWORD *v9; // edi
  int v10; // edx
  int v11; // ebp
  int v12; // ebx
  int v13; // edx
  int v14; // ecx
  int v15; // esi
  _WORD **v16; // esi
  _WORD *v17; // ecx
  _WORD *v18; // ebp
  _DWORD *v20; // [esp+10h] [ebp-60h]
  int v21; // [esp+14h] [ebp-5Ch]
  int v22; // [esp+18h] [ebp-58h]
  int v23; // [esp+1Ch] [ebp-54h]
  _DWORD *v24; // [esp+20h] [ebp-50h]
  int v25; // [esp+24h] [ebp-4Ch]
  unsigned int v26; // [esp+28h] [ebp-48h]
  unsigned int v27; // [esp+2Ch] [ebp-44h]
  int v28; // [esp+30h] [ebp-40h]
  unsigned int v29; // [esp+34h] [ebp-3Ch]
  _DWORD v30[4]; // [esp+38h] [ebp-38h]
  _DWORD v31[10]; // [esp+48h] [ebp-28h] BYREF

  v1 = a1;
  v2 = (_DWORD *)a1[82];
  v27 = a1[62] - 1;
  v3 = 0;
  v20 = v2;
  v29 = a1[56] - 1;
  if ( (int)a1[57] > 0 )
  {
    v4 = a1 + 58;
    do
    {
      v5 = (*(int (__cdecl **)(_DWORD *, _DWORD, int, _DWORD, _DWORD))(a1[1] + 32))(
             a1,
             a2: *(_DWORD *)(v20[6] + 4 * *(_DWORD *)(*v4 + 4)),
             a3: *(_DWORD *)(*v4 + 12) * v2[2],
             a4: *(_DWORD *)(*v4 + 12),
             a5: 0);
      v2 = v20;
      v30[v3++] = v5;
      ++v4;
    }
    while ( v3 < a1[57] );
  }
  v6 = v2[4];
  v21 = v6;
  if ( v6 >= v2[5] )
  {
LABEL_32:
    ++v2[2];
    sub_1019FD10(this: v1);
    return 1;
  }
  else
  {
    while ( 1 )
    {
      v7 = v2[3];
      v26 = v7;
      if ( v7 < v1[62] )
        break;
LABEL_31:
      ++v6;
      v2[3] = 0;
      v21 = v6;
      if ( v6 >= v2[5] )
        goto LABEL_32;
    }
    while ( 1 )
    {
      v8 = 0;
      v23 = 0;
      if ( (int)v1[57] > 0 )
      {
        v24 = v1 + 58;
        do
        {
          v9 = (_DWORD *)*v24;
          v10 = v7 * *(_DWORD *)(*v24 + 52);
          v28 = v10;
          if ( v7 >= v27 )
            v11 = v9[17];
          else
            v11 = *(_DWORD *)(*v24 + 52);
          v25 = v11;
          v22 = 0;
          if ( (int)v9[14] > 0 )
          {
            v12 = 4 * v21;
            while ( 1 )
            {
              if ( v20[2] < v29 || v21 + v22 < v9[18] )
              {
                v14 = *(_DWORD *)(v30[v23] + v12) + (v10 << 7);
                v13 = 0;
                if ( v11 > 0 )
                {
                  v15 = v11;
                  v13 = v11;
                  do
                  {
                    v31[v8++] = v14;
                    v14 += 128;
                    --v15;
                  }
                  while ( v15 != 0 );
                }
              }
              else
              {
                v13 = 0;
              }
              if ( v13 < v9[13] )
              {
                v16 = (_WORD **)&v20[v8 + 7];
                do
                {
                  v17 = *v16;
                  v18 = (_WORD *)v30[v8 + 3];
                  v31[v8] = *v16;
                  ++v13;
                  *v17 = *v18;
                  ++v8;
                  ++v16;
                }
                while ( v13 < v9[13] );
                v11 = v25;
              }
              v12 += 4;
              if ( ++v22 >= v9[14] )
                break;
              v10 = v28;
            }
            v1 = a1;
            v7 = v26;
          }
          ++v24;
          ++v23;
        }
        while ( v23 < v1[57] );
        v2 = v20;
      }
      if ( (*(unsigned __int8 (__cdecl **)(_DWORD *, _DWORD *))(v1[87] + 4))(a1: v1, a2: v31) == 0 )
        break;
      v26 = ++v7;
      if ( v7 >= v1[62] )
      {
        v6 = v21;
        goto LABEL_31;
      }
    }
    v2[3] = v7;
    v2[4] = v21;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1019FFF0
// Name: sub_1019FFF0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__usercall sub_1019FFF0@<eax>(int a1@<eax>, int a2)
{
  _DWORD *v3; // esi
  unsigned __int8 *v4; // edi

  v3 = (_DWORD *)(**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, a2: 1, a3: 68);
  *(_DWORD *)(a1 + 328) = v3;
  *v3 = sub_1019FD60;
  v3[1] = sub_1019FDA0;
  v3[6] = a2;
  v4 = (unsigned __int8 *)(*(int (__cdecl **)(int, int, int))(*(_DWORD *)(a1 + 4) + 4))(a1, a2: 1, a3: 1280);
  jzero_far(dst: v4, count: 0x500u);
  v3[8] = v4 + 128;
  v3[9] = v4 + 256;
  v3[7] = v4;
  v3[10] = v4 + 384;
  v3[11] = v4 + 512;
  v3[12] = v4 + 640;
  v3[16] = v4 + 1152;
  v3[13] = v4 + 768;
  v3[14] = v4 + 896;
  v3[15] = v4 + 1024;
  return v4 + 1024;
}

//------------------------------------------------------------------------------
// Address: 0x101A00A0
// Name: sub_101A00A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A00A0@<eax>(int a1@<esi>, int a2)
{
  *(_DWORD *)(a1 + 36) = 1;
  jinit_c_master_control((struct jpeg_compress_struct *)a1, a2: 1);
  if ( *(_BYTE *)(a1 + 177) != 0 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 1;
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  else if ( *(_BYTE *)(a1 + 212) != 0 )
  {
    jinit_phuff_encoder((struct jpeg_compress_struct *)a1);
  }
  else
  {
    jinit_huff_encoder((struct jpeg_compress_struct *)a1);
  }
  sub_1019FFF0(a1, a2);
  jinit_marker_writer((struct jpeg_compress_struct *)a1);
  (*(void (__cdecl **)(int))(*(_DWORD *)(a1 + 4) + 24))(a1);
  return (**(int (__cdecl ***)(int))(a1 + 332))(a1);
}

//------------------------------------------------------------------------------
// Address: 0x101A0120
// Name: void jpeg_write_coefficients(struct jpeg_compress_struct __near *,struct jvirt_barray_control __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_write_coefficients(struct jpeg_compress_struct *a1, struct jvirt_barray_control **a2)
{
  if ( *((_DWORD *)a1 + 5) != 100 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 20;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = *((_DWORD *)a1 + 5);
    (**(void (__cdecl ***)(struct jpeg_compress_struct *))a1)(a1);
  }
  jpeg_suppress_tables(a1, a2: 0);
  (*(void (__cdecl **)(struct jpeg_compress_struct *))(*(_DWORD *)a1 + 16))(a1);
  (*(void (__cdecl **)(struct jpeg_compress_struct *))(*((_DWORD *)a1 + 6) + 8))(a1);
  sub_101A00A0((int)a1, (int)a2);
  *((_DWORD *)a1 + 52) = 0;
  *((_DWORD *)a1 + 5) = 103;
}

//------------------------------------------------------------------------------
// Address: 0x101A0180
// Name: sub_101A0180
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A0180@<eax>(int a1@<esi>)
{
  int v1; // eax
  int v2; // ebp
  bool v3; // cc
  int *v4; // edi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // ebp
  int v10; // edi
  int v11; // eax
  int v12; // eax
  int v13; // edx
  int v14; // eax
  int v15; // ecx
  int result; // eax

  if ( *(int *)(a1 + 32) > 65500 || *(int *)(a1 + 28) > 65500 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 41;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = 65500;
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  if ( *(_DWORD *)(a1 + 192) != 8 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 15;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = *(_DWORD *)(a1 + 192);
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  if ( *(int *)(a1 + 36) > 10 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 26;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = *(_DWORD *)(a1 + 36);
    *(_DWORD *)(*(_DWORD *)a1 + 28) = 10;
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  v1 = *(_DWORD *)(a1 + 196);
  v2 = 0;
  v3 = *(_DWORD *)(a1 + 36) <= 0;
  *(_DWORD *)(a1 + 272) = 1;
  *(_DWORD *)(a1 + 276) = 1;
  if ( !v3 )
  {
    v4 = (int *)(v1 + 12);
    do
    {
      v5 = *(v4 - 1);
      if ( v5 <= 0 || v5 > 4 || *v4 <= 0 || *v4 > 4 )
      {
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 18;
        (**(void (__cdecl ***)(int))a1)(a1);
      }
      v6 = *(_DWORD *)(a1 + 272);
      if ( v6 <= *(v4 - 1) )
        v6 = *(v4 - 1);
      *(_DWORD *)(a1 + 272) = v6;
      v7 = *(_DWORD *)(a1 + 276);
      if ( v7 <= *v4 )
        v7 = *v4;
      ++v2;
      *(_DWORD *)(a1 + 276) = v7;
      v4 += 21;
    }
    while ( v2 < *(_DWORD *)(a1 + 36) );
  }
  v8 = *(_DWORD *)(a1 + 196);
  v9 = 0;
  v3 = *(_DWORD *)(a1 + 36) <= 0;
  *(_DWORD *)(a1 + 280) = 8;
  if ( !v3 )
  {
    v10 = v8 + 28;
    do
    {
      v11 = *(_DWORD *)(v10 - 20);
      *(_DWORD *)(v10 + 8) = 8;
      v12 = jdiv_round_up(a1: *(_DWORD *)(a1 + 28) * v11, a2: 8 * *(_DWORD *)(a1 + 272));
      v13 = *(_DWORD *)(v10 - 16);
      *(_DWORD *)v10 = v12;
      v14 = jdiv_round_up(a1: *(_DWORD *)(a1 + 32) * v13, a2: 8 * *(_DWORD *)(a1 + 276));
      v15 = *(_DWORD *)(v10 - 20);
      *(_DWORD *)(v10 + 4) = v14;
      *(_DWORD *)(v10 + 12) = jdiv_round_up(a1: *(_DWORD *)(a1 + 28) * v15, a2: *(_DWORD *)(a1 + 272));
      *(_DWORD *)(v10 + 16) = jdiv_round_up(a1: *(_DWORD *)(a1 + 32) * *(_DWORD *)(v10 - 16), a2: *(_DWORD *)(a1 + 276));
      *(_BYTE *)(v10 + 20) = 1;
      *(_DWORD *)(v10 + 48) = 0;
      ++v9;
      v10 += 84;
    }
    while ( v9 < *(_DWORD *)(a1 + 36) );
  }
  *(_DWORD *)(a1 + 284) = jdiv_round_up(a1: *(_DWORD *)(a1 + 32), a2: 8 * *(_DWORD *)(a1 + 276));
  result = *(_DWORD *)(a1 + 292);
  *(_BYTE *)(*(_DWORD *)(a1 + 400) + 16) = result < *(_DWORD *)(a1 + 36) || *(_BYTE *)(a1 + 200) != 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A0380
// Name: sub_101A0380
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A0380@<eax>(int *a1@<esi>)
{
  int v1; // eax
  _DWORD *v2; // ecx
  unsigned int v3; // edi
  int result; // eax
  int v5; // edx
  int v6; // eax
  int v7; // ecx
  bool v8; // cc
  _DWORD *v9; // ecx
  unsigned int v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // ebp
  int v13; // edx
  int v14; // ebx
  unsigned int v15; // eax
  int v16; // edx
  int v17; // edi
  int v18; // [esp+8h] [ebp-8h]
  int *v19; // [esp+Ch] [ebp-4h]

  v1 = a1[73];
  if ( v1 == 1 )
  {
    v2 = (_DWORD *)a1[74];
    a1[78] = v2[7];
    a1[79] = v2[8];
    v3 = v2[3];
    v2[16] = v2[9];
    result = v2[8] / v3;
    v5 = v2[8] % v3;
    v2[13] = 1;
    v2[14] = 1;
    v2[15] = 1;
    v2[17] = 1;
    if ( v5 == 0 )
      v5 = v3;
    v2[18] = v5;
    a1[80] = 1;
    a1[81] = 0;
  }
  else
  {
    if ( v1 <= 0 || v1 > 4 )
    {
      *(_DWORD *)(*a1 + 20) = 26;
      *(_DWORD *)(*a1 + 24) = a1[73];
      *(_DWORD *)(*a1 + 28) = 4;
      (*(void (__cdecl **)(int *))*a1)(a1);
    }
    v6 = jdiv_round_up(a1: a1[7], a2: 8 * a1[68]);
    v7 = a1[8];
    a1[78] = v6;
    result = jdiv_round_up(a1: v7, a2: 8 * a1[69]);
    v8 = a1[73] <= 0;
    a1[79] = result;
    a1[80] = 0;
    v18 = 0;
    if ( !v8 )
    {
      v19 = a1 + 74;
      do
      {
        v9 = (_DWORD *)*v19;
        v10 = *(_DWORD *)(*v19 + 8);
        v11 = *(_DWORD *)(*v19 + 28);
        v12 = *(_DWORD *)(*v19 + 12);
        v9[16] = v10 * *(_DWORD *)(*v19 + 36);
        v13 = v11 % v10;
        v14 = v10 * v12;
        v9[13] = v10;
        v9[14] = v12;
        v9[15] = v10 * v12;
        if ( v11 % v10 == 0 )
          v13 = v10;
        v15 = v9[8];
        v9[17] = v13;
        v16 = v15 % v12;
        if ( v15 % v12 == 0 )
          v16 = v12;
        v9[18] = v16;
        v17 = v10 * v12;
        if ( v14 + a1[80] > 10 )
        {
          *(_DWORD *)(*a1 + 20) = 13;
          (*(void (__cdecl **)(int *))*a1)(a1);
        }
        if ( v14 > 0 )
        {
          do
          {
            --v17;
            a1[a1[80]++ + 81] = v18;
          }
          while ( v17 > 0 );
        }
        ++v19;
        result = ++v18;
      }
      while ( v18 < a1[73] );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A0530
// Name: sub_101A0530
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_101A0530(int a1@<ebx>)
{
  int v1; // ebp
  unsigned int v2; // esi
  void *v3; // eax
  int *v4; // [esp+0h] [ebp-8h]
  int v5; // [esp+4h] [ebp-4h]

  v5 = 0;
  if ( *(int *)(a1 + 292) > 0 )
  {
    v4 = (int *)(a1 + 296);
    do
    {
      v1 = *v4;
      if ( *(_DWORD *)(*v4 + 76) == 0 )
      {
        v2 = *(_DWORD *)(v1 + 16);
        if ( v2 > 3 || *(_DWORD *)(a1 + 4 * v2 + 144) == 0 )
        {
          *(_DWORD *)(*(_DWORD *)a1 + 20) = 52;
          *(_DWORD *)(*(_DWORD *)a1 + 24) = v2;
          (**(void (__cdecl ***)(int))a1)(a1);
        }
        v3 = (void *)(**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, a2: 1, a3: 130);
        qmemcpy(v3, *(const void **)(a1 + 4 * v2 + 144), 0x82u);
        *(_DWORD *)(v1 + 76) = v3;
      }
      ++v4;
      ++v5;
    }
    while ( v5 < *(_DWORD *)(a1 + 292) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A05E0
// Name: sub_101A05E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A05E0(int a1)
{
  int result; // eax

  sub_101A0380((int *)a1);
  sub_101A0530(a1);
  (**(void (__cdecl ***)(int))(a1 + 408))(a1);
  (**(void (__cdecl ***)(int))(a1 + 392))(a1);
  result = *(_DWORD *)(*(_DWORD *)(a1 + 392) + 4);
  **(_DWORD **)(a1 + 400) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A0620
// Name: sub_101A0620
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A0620(_DWORD *a1)
{
  _BYTE *v1; // edi
  int v3; // ebx
  bool v4; // zf
  int v5; // eax

  v1 = (_BYTE *)a1[100];
  if ( v1[17] != 0 )
    return 2;
  v3 = (*(int (__cdecl **)(_DWORD *))(a1[101] + 4))(a1);
  if ( v3 == 1 )
  {
    if ( v1[20] != 0 )
    {
      sub_101A0180((int)a1);
      v1[20] = 0;
      return 1;
    }
    if ( v1[16] == 0 )
    {
      *(_DWORD *)(*a1 + 20) = 35;
      (*(void (__cdecl **)(_DWORD *))*a1)(a1);
    }
    sub_101A05E0((int)a1);
  }
  else if ( v3 == 2 )
  {
    v4 = v1[20] == 0;
    v1[17] = 1;
    if ( v4 )
    {
      v5 = a1[31];
      if ( a1[33] > v5 )
      {
        a1[33] = v5;
        return v3;
      }
    }
    else if ( *(_BYTE *)(a1[101] + 13) != 0 )
    {
      *(_DWORD *)(*a1 + 20) = 59;
      (*(void (__cdecl **)(_DWORD *))*a1)(a1);
      return v3;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101A06E0
// Name: sub_101A06E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A06E0(int a1)
{
  int v1; // eax
  int result; // eax

  v1 = *(_DWORD *)(a1 + 400);
  *(_DWORD *)v1 = sub_101A0620;
  *(_BYTE *)(v1 + 16) = 0;
  *(_BYTE *)(v1 + 17) = 0;
  *(_BYTE *)(v1 + 20) = 1;
  (*(void (__cdecl **)(int))(*(_DWORD *)a1 + 16))(a1);
  result = (**(int (__cdecl ***)(int))(a1 + 404))(a1);
  *(_DWORD *)(a1 + 140) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A0720
// Name: sub_101A0720
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A0720(int a1)
{
  **(_DWORD **)(a1 + 400) = sub_101A0620;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x101A0740
// Name: void jinit_input_controller(struct jpeg_decompress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jinit_input_controller(struct jpeg_decompress_struct *a1)
{
  int v1; // eax

  v1 = (**((int (__cdecl ***)(struct jpeg_decompress_struct *, _DWORD, int))a1 + 1))(a1, a2: 0, a3: 24);
  *((_DWORD *)a1 + 100) = v1;
  *(_DWORD *)v1 = sub_101A0620;
  *(_DWORD *)(v1 + 4) = sub_101A06E0;
  *(_DWORD *)(v1 + 8) = sub_101A05E0;
  *(_DWORD *)(v1 + 12) = sub_101A0720;
  *(_BYTE *)(v1 + 16) = 0;
  *(_BYTE *)(v1 + 17) = 0;
  *(_BYTE *)(v1 + 20) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x101A0790
// Name: sub_101A0790
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A0790@<eax>(int a1@<eax>, int a2)
{
  *(_DWORD *)(*(_DWORD *)a1 + 20) = 54;
  *(_DWORD *)(*(_DWORD *)a1 + 24) = a2;
  return (**(int (__cdecl ***)(int))a1)(a1);
}

//------------------------------------------------------------------------------
// Address: 0x101A07B0
// Name: sub_101A07B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A07B0(struct jpeg_common_struct *a1, unsigned int a2, unsigned int a3)
{
  unsigned int v4; // edi
  _DWORD *i; // eax
  _DWORD *v6; // ebp
  unsigned int v7; // edi
  unsigned int v8; // esi
  int v9; // ecx
  struct jpeg_common_struct *v11; // [esp+14h] [ebp+4h]

  v4 = a3;
  v11 = *((struct jpeg_common_struct **)a1 + 1);
  if ( a3 > 0x3B9AC9F0 )
    sub_101A0790((int)a1, a2: 1);
  if ( (a3 & 7) != 0 )
  {
    v4 = 8 - (a3 & 7) + a3;
    a3 = v4;
  }
  if ( a2 >= 2 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 14;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = a2;
    (**(void (__cdecl ***)(struct jpeg_common_struct *))a1)(a1);
  }
  i = *((_DWORD **)v11 + a2 + 13);
  v6 = nullptr;
  if ( i != nullptr )
  {
    while ( i[2] < v4 )
    {
      v6 = i;
      i = (_DWORD *)*i;
      if ( i == nullptr )
        goto LABEL_10;
    }
  }
  else
  {
LABEL_10:
    v7 = v4 + 16;
    if ( v6 != nullptr )
      v8 = dword_102AC93C[a2];
    else
      v8 = dword_102AC934[a2];
    if ( v8 > 1000000000 - v7 )
      v8 = 1000000000 - v7;
    for ( i = jpeg_get_large(a1, nSize: v8 + v7); i == nullptr; i = jpeg_get_large(a1, nSize: v8 + v7) )
    {
      v8 >>= 1;
      if ( v8 < 0x32 )
        sub_101A0790((int)a1, a2: 2);
    }
    *((_DWORD *)v11 + 19) += v8 + v7;
    *i = 0;
    i[1] = 0;
    i[2] = a3 + v8;
    v4 = a3;
    if ( v6 != nullptr )
      *v6 = i;
    else
      *((_DWORD *)v11 + a2 + 13) = i;
  }
  v9 = i[1];
  i[2] -= v4;
  i[1] = v4 + v9;
  return (int)i + v9 + 16;
}

//------------------------------------------------------------------------------
// Address: 0x101A08E0
// Name: sub_101A08E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__cdecl sub_101A08E0(struct jpeg_common_struct *a1, unsigned int a2, unsigned int a3)
{
  int v3; // ebx
  unsigned int v4; // edi
  _DWORD *large; // esi
  int v6; // ecx

  v3 = *((_DWORD *)a1 + 1);
  v4 = a3;
  if ( a3 > 0x3B9AC9F0 )
    sub_101A0790((int)a1, a2: 3);
  if ( (a3 & 7) != 0 )
    v4 = 8 - (a3 & 7) + a3;
  if ( a2 >= 2 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 14;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = a2;
    (**(void (__cdecl ***)(struct jpeg_common_struct *))a1)(a1);
  }
  large = jpeg_get_large(a1, nSize: v4 + 16);
  if ( large == nullptr )
    sub_101A0790((int)a1, a2: 4);
  *(_DWORD *)(v3 + 76) += v4 + 16;
  v6 = *(_DWORD *)(v3 + 4 * a2 + 60);
  large[1] = v4;
  *large = v6;
  large[2] = 0;
  *(_DWORD *)(v3 + 4 * a2 + 60) = large;
  return large + 4;
}

//------------------------------------------------------------------------------
// Address: 0x101A0980
// Name: sub_101A0980
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A0980(struct jpeg_common_struct *a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  int v4; // ebp
  unsigned int v5; // edi
  unsigned int v6; // esi
  int v7; // ebp
  _DWORD *v8; // eax
  unsigned int i; // ecx

  v4 = *((_DWORD *)a1 + 1);
  v5 = 0x3B9AC9F0 / a3;
  if ( 0x3B9AC9F0 / a3 == 0 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 70;
    (**(void (__cdecl ***)(struct jpeg_common_struct *))a1)(a1);
  }
  if ( (int)v5 >= (int)a4 )
    v5 = a4;
  *(_DWORD *)(v4 + 80) = v5;
  v6 = 0;
  v7 = sub_101A07B0(a1, a2, a3: 4 * a4);
  while ( v6 < a4 )
  {
    if ( v5 >= a4 - v6 )
      v5 = a4 - v6;
    v8 = sub_101A08E0(a1, a2, a3: a3 * v5);
    for ( i = v5; i != 0; --i )
    {
      *(_DWORD *)(v7 + 4 * v6++) = v8;
      v8 = (_DWORD *)((char *)v8 + a3);
    }
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x101A0A30
// Name: sub_101A0A30
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A0A30(struct jpeg_common_struct *a1, unsigned int a2, int a3, unsigned int a4)
{
  int v4; // ebp
  unsigned int v5; // edi
  unsigned int v6; // esi
  int v7; // ebp
  _DWORD *v8; // eax
  unsigned int i; // ecx

  v4 = *((_DWORD *)a1 + 1);
  v5 = 0x3B9AC9F0u / (a3 << 7);
  if ( v5 == 0 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 70;
    (**(void (__cdecl ***)(struct jpeg_common_struct *))a1)(a1);
  }
  if ( (int)v5 >= (int)a4 )
    v5 = a4;
  *(_DWORD *)(v4 + 80) = v5;
  v6 = 0;
  v7 = sub_101A07B0(a1, a2, a3: 4 * a4);
  while ( v6 < a4 )
  {
    if ( v5 >= a4 - v6 )
      v5 = a4 - v6;
    v8 = sub_101A08E0(a1, a2, a3: (a3 * v5) << 7);
    for ( i = v5; i != 0; --i )
    {
      *(_DWORD *)(v7 + 4 * v6++) = v8;
      v8 += 32 * a3;
    }
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x101A0AE0
// Name: sub_101A0AE0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A0AE0(struct jpeg_common_struct *a1, unsigned int a2, char a3, int a4, int a5, int a6)
{
  int v6; // edi
  int result; // eax

  v6 = *((_DWORD *)a1 + 1);
  if ( a2 != 1 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 14;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = a2;
    (**(void (__cdecl ***)(struct jpeg_common_struct *))a1)(a1);
  }
  result = sub_101A07B0(a1, a2, a3: 0x78u);
  *(_DWORD *)(result + 4) = a5;
  *(_DWORD *)(result + 8) = a4;
  *(_DWORD *)result = 0;
  *(_DWORD *)(result + 12) = a6;
  *(_BYTE *)(result + 32) = a3;
  *(_BYTE *)(result + 34) = 0;
  *(_DWORD *)(result + 36) = *(_DWORD *)(v6 + 68);
  *(_DWORD *)(v6 + 68) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A0B50
// Name: sub_101A0B50
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A0B50(struct jpeg_common_struct *a1, unsigned int a2, char a3, int a4, int a5, int a6)
{
  int v6; // edi
  int result; // eax

  v6 = *((_DWORD *)a1 + 1);
  if ( a2 != 1 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 14;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = a2;
    (**(void (__cdecl ***)(struct jpeg_common_struct *))a1)(a1);
  }
  result = sub_101A07B0(a1, a2, a3: 0x78u);
  *(_DWORD *)(result + 4) = a5;
  *(_DWORD *)(result + 8) = a4;
  *(_DWORD *)result = 0;
  *(_DWORD *)(result + 12) = a6;
  *(_BYTE *)(result + 32) = a3;
  *(_BYTE *)(result + 34) = 0;
  *(_DWORD *)(result + 36) = *(_DWORD *)(v6 + 72);
  *(_DWORD *)(v6 + 72) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A0BC0
// Name: sub_101A0BC0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A0BC0(struct jpeg_common_struct *a1)
{
  struct jpeg_common_struct *v2; // edx
  _DWORD *v3; // eax
  int v4; // esi
  int v5; // edi
  int v6; // ecx
  int result; // eax
  int v8; // ecx
  signed int v9; // ebp
  int j; // esi
  int v11; // edi
  unsigned int v12; // ecx
  int k; // esi
  int v14; // edi
  unsigned int v15; // ecx
  int v16; // eax
  int v17; // [esp-4h] [ebp-14h]
  struct jpeg_common_struct *i; // [esp+14h] [ebp+4h]

  v2 = *((struct jpeg_common_struct **)a1 + 1);
  v3 = *((_DWORD **)v2 + 17);
  v4 = 0;
  v5 = 0;
  for ( i = v2; v3 != nullptr; v3 = (_DWORD *)v3[9] )
  {
    if ( *v3 == 0 )
    {
      v6 = v3[2];
      v4 += v6 * v3[3];
      v5 += v6 * v3[1];
    }
  }
  for ( result = *((_DWORD *)v2 + 18); result != 0; result = *(_DWORD *)(result + 36) )
  {
    if ( *(_DWORD *)result == 0 )
    {
      v8 = *(_DWORD *)(result + 8);
      v4 += (v8 * *(_DWORD *)(result + 12)) << 7;
      v5 += (v8 * *(_DWORD *)(result + 4)) << 7;
    }
  }
  if ( v4 > 0 )
  {
    result = jpeg_mem_available(a1, a2: v4, a3: v5, a4: *((_DWORD *)v2 + 19));
    if ( result < v5 )
    {
      result /= v4;
      v9 = result;
      if ( result <= 0 )
        v9 = 1;
    }
    else
    {
      v9 = 1000000000;
    }
    for ( j = *((_DWORD *)i + 17); j != 0; j = *(_DWORD *)(j + 36) )
    {
      if ( *(_DWORD *)j == 0 )
      {
        v11 = *(_DWORD *)(j + 4);
        v12 = *(_DWORD *)(j + 12);
        if ( (int)((v11 - 1) / v12 + 1) > v9 )
        {
          v17 = v11 * *(_DWORD *)(j + 8);
          *(_DWORD *)(j + 16) = v9 * v12;
          jpeg_open_backing_store(a1, a2: (struct backing_store_struct *)(j + 40), a3: v17);
          *(_BYTE *)(j + 34) = 1;
        }
        else
        {
          *(_DWORD *)(j + 16) = v11;
        }
        *(_DWORD *)j = sub_101A0980(a1, a2: 1u, a3: *(_DWORD *)(j + 8), a4: *(_DWORD *)(j + 16));
        result = 0;
        *(_DWORD *)(j + 20) = *((_DWORD *)i + 20);
        *(_DWORD *)(j + 24) = 0;
        *(_DWORD *)(j + 28) = 0;
        *(_BYTE *)(j + 33) = 0;
      }
    }
    for ( k = *((_DWORD *)i + 18); k != 0; k = *(_DWORD *)(k + 36) )
    {
      if ( *(_DWORD *)k == 0 )
      {
        v14 = *(_DWORD *)(k + 4);
        v15 = *(_DWORD *)(k + 12);
        if ( (int)((v14 - 1) / v15 + 1) > v9 )
        {
          v16 = (v14 * *(_DWORD *)(k + 8)) << 7;
          *(_DWORD *)(k + 16) = v9 * v15;
          jpeg_open_backing_store(a1, a2: (struct backing_store_struct *)(k + 40), a3: v16);
          *(_BYTE *)(k + 34) = 1;
        }
        else
        {
          *(_DWORD *)(k + 16) = v14;
        }
        *(_DWORD *)k = sub_101A0A30(a1, a2: 1u, a3: *(_DWORD *)(k + 8), a4: *(_DWORD *)(k + 16));
        result = 0;
        *(_DWORD *)(k + 20) = *((_DWORD *)i + 20);
        *(_DWORD *)(k + 24) = 0;
        *(_DWORD *)(k + 28) = 0;
        *(_BYTE *)(k + 33) = 0;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A0D60
// Name: sub_101A0D60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A0D60@<eax>(int a1@<esi>, int a2, char a3)
{
  int result; // eax
  int v4; // ebp
  int v5; // ebx
  int v6; // edi
  int v7; // ecx
  int v8; // ebp
  int v9; // [esp+Ch] [ebp-4h]

  result = *(_DWORD *)(a1 + 16);
  v4 = *(_DWORD *)(a1 + 8);
  v5 = v4 * *(_DWORD *)(a1 + 24);
  v6 = 0;
  v9 = v4;
  if ( result > 0 )
  {
    while ( 1 )
    {
      result -= v6;
      if ( *(_DWORD *)(a1 + 20) < result )
        result = *(_DWORD *)(a1 + 20);
      v7 = v6 + *(_DWORD *)(a1 + 24);
      if ( result >= *(_DWORD *)(a1 + 28) - v7 )
        result = *(_DWORD *)(a1 + 28) - v7;
      if ( result >= *(_DWORD *)(a1 + 4) - v7 )
        result = *(_DWORD *)(a1 + 4) - v7;
      if ( result <= 0 )
        break;
      v8 = v4 * result;
      if ( a3 != 0 )
        (*(void (__cdecl **)(int, int, _DWORD, int, int))(a1 + 44))(
          a1: a2,
          a2: a1 + 40,
          a3: *(_DWORD *)(*(_DWORD *)a1 + 4 * v6),
          a4: v5,
          a5: v8);
      else
        (*(void (__cdecl **)(int, int, _DWORD, int, int))(a1 + 40))(
          a1: a2,
          a2: a1 + 40,
          a3: *(_DWORD *)(*(_DWORD *)a1 + 4 * v6),
          a4: v5,
          a5: v8);
      v6 += *(_DWORD *)(a1 + 20);
      result = *(_DWORD *)(a1 + 16);
      v5 += v8;
      if ( v6 >= result )
        break;
      v4 = v9;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A0E00
// Name: sub_101A0E00
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A0E00@<eax>(int a1@<esi>, int a2, char a3)
{
  int result; // eax
  int v4; // ebp
  int v5; // ebx
  int v6; // edi
  int v7; // ecx
  int v8; // ebp
  int v9; // [esp+Ch] [ebp-4h]

  result = *(_DWORD *)(a1 + 16);
  v4 = *(_DWORD *)(a1 + 8) << 7;
  v5 = v4 * *(_DWORD *)(a1 + 24);
  v6 = 0;
  v9 = v4;
  if ( result > 0 )
  {
    while ( 1 )
    {
      result -= v6;
      if ( *(_DWORD *)(a1 + 20) < result )
        result = *(_DWORD *)(a1 + 20);
      v7 = v6 + *(_DWORD *)(a1 + 24);
      if ( result >= *(_DWORD *)(a1 + 28) - v7 )
        result = *(_DWORD *)(a1 + 28) - v7;
      if ( result >= *(_DWORD *)(a1 + 4) - v7 )
        result = *(_DWORD *)(a1 + 4) - v7;
      if ( result <= 0 )
        break;
      v8 = v4 * result;
      if ( a3 != 0 )
        (*(void (__cdecl **)(int, int, _DWORD, int, int))(a1 + 44))(
          a1: a2,
          a2: a1 + 40,
          a3: *(_DWORD *)(*(_DWORD *)a1 + 4 * v6),
          a4: v5,
          a5: v8);
      else
        (*(void (__cdecl **)(int, int, _DWORD, int, int))(a1 + 40))(
          a1: a2,
          a2: a1 + 40,
          a3: *(_DWORD *)(*(_DWORD *)a1 + 4 * v6),
          a4: v5,
          a5: v8);
      v6 += *(_DWORD *)(a1 + 20);
      result = *(_DWORD *)(a1 + 16);
      v5 += v8;
      if ( v6 >= result )
        break;
      v4 = v9;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A0EA0
// Name: sub_101A0EA0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A0EA0(int a1, int a2, unsigned int a3, unsigned int a4, char a5)
{
  unsigned int v5; // ebp
  unsigned int v6; // eax
  int v7; // eax
  unsigned int v8; // edi
  int v9; // eax
  unsigned int v10; // ebx
  unsigned int v11; // edi
  unsigned int i; // ebp

  v5 = a3 + a4;
  if ( a3 + a4 > *(_DWORD *)(a2 + 4) || a4 > *(_DWORD *)(a2 + 12) || *(_DWORD *)a2 == 0 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 22;
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  v6 = *(_DWORD *)(a2 + 24);
  if ( a3 < v6 || v5 > v6 + *(_DWORD *)(a2 + 16) )
  {
    if ( *(_BYTE *)(a2 + 34) == 0 )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 69;
      (**(void (__cdecl ***)(int))a1)(a1);
    }
    if ( *(_BYTE *)(a2 + 33) != 0 )
    {
      sub_101A0D60(a1: a2, a2: a1, a3: 1);
      *(_BYTE *)(a2 + 33) = 0;
    }
    if ( a3 <= *(_DWORD *)(a2 + 24) )
    {
      v7 = v5 - *(_DWORD *)(a2 + 16);
      if ( v7 < 0 )
        v7 = 0;
      *(_DWORD *)(a2 + 24) = v7;
    }
    else
    {
      *(_DWORD *)(a2 + 24) = a3;
    }
    sub_101A0D60(a1: a2, a2: a1, a3: 0);
  }
  v8 = *(_DWORD *)(a2 + 28);
  if ( v8 >= v5 )
  {
LABEL_27:
    if ( a5 == 0 )
      return *(_DWORD *)a2 + 4 * (a3 - *(_DWORD *)(a2 + 24));
LABEL_28:
    *(_BYTE *)(a2 + 33) = 1;
    return *(_DWORD *)a2 + 4 * (a3 - *(_DWORD *)(a2 + 24));
  }
  if ( v8 < a3 )
  {
    if ( a5 != 0 )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 22;
      (**(void (__cdecl ***)(int))a1)(a1);
    }
    v8 = a3;
  }
  if ( a5 != 0 )
    *(_DWORD *)(a2 + 28) = v5;
  if ( *(_BYTE *)(a2 + 32) != 0 )
  {
    v9 = *(_DWORD *)(a2 + 24);
    v10 = *(_DWORD *)(a2 + 8);
    v11 = v8 - v9;
    for ( i = v5 - v9; v11 < i; ++v11 )
      jzero_far(dst: *(unsigned __int8 **)(*(_DWORD *)a2 + 4 * v11), count: v10);
    goto LABEL_27;
  }
  if ( a5 != 0 )
    goto LABEL_28;
  *(_DWORD *)(*(_DWORD *)a1 + 20) = 22;
  (**(void (__cdecl ***)(int))a1)(a1);
  return *(_DWORD *)a2 + 4 * (a3 - *(_DWORD *)(a2 + 24));
}

//------------------------------------------------------------------------------
// Address: 0x101A0FE0
// Name: sub_101A0FE0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A0FE0(int a1, int a2, unsigned int a3, unsigned int a4, char a5)
{
  unsigned int v5; // ebx
  unsigned int v6; // eax
  int v7; // eax
  unsigned int v8; // edi
  int v9; // eax
  unsigned int v10; // edi
  unsigned int v11; // ebx
  unsigned int i; // ebp

  v5 = a3 + a4;
  if ( a3 + a4 > *(_DWORD *)(a2 + 4) || a4 > *(_DWORD *)(a2 + 12) || *(_DWORD *)a2 == 0 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 22;
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  v6 = *(_DWORD *)(a2 + 24);
  if ( a3 < v6 || v5 > v6 + *(_DWORD *)(a2 + 16) )
  {
    if ( *(_BYTE *)(a2 + 34) == 0 )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 69;
      (**(void (__cdecl ***)(int))a1)(a1);
    }
    if ( *(_BYTE *)(a2 + 33) != 0 )
    {
      sub_101A0E00(a1: a2, a2: a1, a3: 1);
      *(_BYTE *)(a2 + 33) = 0;
    }
    if ( a3 <= *(_DWORD *)(a2 + 24) )
    {
      v7 = v5 - *(_DWORD *)(a2 + 16);
      if ( v7 < 0 )
        v7 = 0;
      *(_DWORD *)(a2 + 24) = v7;
    }
    else
    {
      *(_DWORD *)(a2 + 24) = a3;
    }
    sub_101A0E00(a1: a2, a2: a1, a3: 0);
  }
  v8 = *(_DWORD *)(a2 + 28);
  if ( v8 >= v5 )
  {
LABEL_27:
    if ( a5 == 0 )
      return *(_DWORD *)a2 + 4 * (a3 - *(_DWORD *)(a2 + 24));
LABEL_28:
    *(_BYTE *)(a2 + 33) = 1;
    return *(_DWORD *)a2 + 4 * (a3 - *(_DWORD *)(a2 + 24));
  }
  if ( v8 < a3 )
  {
    if ( a5 != 0 )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 22;
      (**(void (__cdecl ***)(int))a1)(a1);
    }
    v8 = a3;
  }
  if ( a5 != 0 )
    *(_DWORD *)(a2 + 28) = v5;
  if ( *(_BYTE *)(a2 + 32) != 0 )
  {
    v9 = *(_DWORD *)(a2 + 24);
    v10 = v8 - v9;
    v11 = v5 - v9;
    for ( i = *(_DWORD *)(a2 + 8) << 7; v10 < v11; ++v10 )
      jzero_far(dst: *(unsigned __int8 **)(*(_DWORD *)a2 + 4 * v10), count: i);
    goto LABEL_27;
  }
  if ( a5 != 0 )
    goto LABEL_28;
  *(_DWORD *)(*(_DWORD *)a1 + 20) = 22;
  (**(void (__cdecl ***)(int))a1)(a1);
  return *(_DWORD *)a2 + 4 * (a3 - *(_DWORD *)(a2 + 24));
}

//------------------------------------------------------------------------------
// Address: 0x101A1130
// Name: sub_101A1130
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__cdecl sub_101A1130(struct jpeg_common_struct *a1, unsigned int a2)
{
  unsigned int v2; // ebp
  _DWORD *v3; // esi
  int i; // edi
  void (__cdecl *v5)(struct jpeg_common_struct *, int); // edx
  int v6; // edi
  void (__cdecl *v7)(struct jpeg_common_struct *, int); // ecx
  _DWORD *v8; // eax
  _DWORD *v9; // edi
  unsigned int v10; // ebp
  _DWORD *result; // eax
  _DWORD *v12; // edi
  unsigned int v13; // ebp

  v2 = a2;
  v3 = *((_DWORD **)a1 + 1);
  if ( a2 >= 2 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 14;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = a2;
    (**(void (__cdecl ***)(struct jpeg_common_struct *))a1)(a1);
  }
  if ( a2 == 1 )
  {
    for ( i = v3[17]; i != 0; i = *(_DWORD *)(i + 36) )
    {
      if ( *(_BYTE *)(i + 34) != 0 )
      {
        v5 = *(void (__cdecl **)(struct jpeg_common_struct *, int))(i + 48);
        *(_BYTE *)(i + 34) = 0;
        v5(a1, a2: i + 40);
      }
    }
    v6 = v3[18];
    for ( v3[17] = 0; v6 != 0; v6 = *(_DWORD *)(v6 + 36) )
    {
      if ( *(_BYTE *)(v6 + 34) != 0 )
      {
        v7 = *(void (__cdecl **)(struct jpeg_common_struct *, int))(v6 + 48);
        *(_BYTE *)(v6 + 34) = 0;
        v7(a1, a2: v6 + 40);
      }
    }
    v3[18] = 0;
  }
  v8 = (_DWORD *)v3[a2 + 15];
  v3[a2 + 15] = 0;
  if ( v8 != nullptr )
  {
    do
    {
      v9 = (_DWORD *)*v8;
      v10 = v8[2] + v8[1] + 16;
      jpeg_free_small(a1, pMem: v8, a3: v10);
      v3[19] -= v10;
      v8 = v9;
    }
    while ( v9 != nullptr );
    v2 = a2;
  }
  result = (_DWORD *)v3[v2 + 13];
  v3[v2 + 13] = 0;
  if ( result != nullptr )
  {
    do
    {
      v12 = (_DWORD *)*result;
      v13 = result[2] + result[1] + 16;
      jpeg_free_small(a1, pMem: result, a3: v13);
      v3[19] -= v13;
      result = v12;
    }
    while ( v12 != nullptr );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A1240
// Name: sub_101A1240
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_101A1240(void *(__cdecl **pFactoryList)(const char *, int *))
{
  signed int i; // esi

  for ( i = 1; i >= 0; --i )
    sub_101A1130(a1: (struct jpeg_common_struct *)pFactoryList, a2: i);
  jpeg_free_small(a1: (struct jpeg_common_struct *)pFactoryList, pMem: pFactoryList[1], a3: 0x54u);
  pFactoryList[1] = nullptr;
  CDummyMaterialSystem::EndBatch();
}

//------------------------------------------------------------------------------
// Address: 0x101A1280
// Name: void jinit_memory_mgr(struct jpeg_common_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jinit_memory_mgr(void *(__cdecl **pFactoryList)(const char *, int *))
{
  ConVar *v1; // ecx
  void *(__cdecl **v2)(const char *, int *); // edi
  int (__cdecl **large)(struct jpeg_common_struct *, unsigned int, unsigned int); // esi
  const char *v4; // eax
  int v5; // [esp+Ch] [ebp-4h] BYREF

  v2 = pFactoryList;
  pFactoryList[1] = nullptr;
  v5 = CDummyHardwareConfig::MaxTextureHeight(this: v1);
  large = (int (__cdecl **)(struct jpeg_common_struct *, unsigned int, unsigned int))jpeg_get_large(
                                                                                       a1: (struct jpeg_common_struct *)v2,
                                                                                       nSize: 0x54u);
  if ( large == nullptr )
  {
    CDummyMaterialSystem::EndBatch();
    *((_DWORD *)*v2 + 5) = 54;
    *((_DWORD *)*v2 + 6) = 0;
    (*(void (__cdecl **)(void *(__cdecl **)(const char *, int *), void *(__cdecl **)(const char *, int *)))*v2)(
      a1: v2,
      a2: v2);
  }
  *large = sub_101A07B0;
  large[1] = (int (__cdecl *)(struct jpeg_common_struct *, unsigned int, unsigned int))sub_101A08E0;
  large[2] = (int (__cdecl *)(struct jpeg_common_struct *, unsigned int, unsigned int))sub_101A0980;
  large[3] = (int (__cdecl *)(struct jpeg_common_struct *, unsigned int, unsigned int))sub_101A0A30;
  large[4] = (int (__cdecl *)(struct jpeg_common_struct *, unsigned int, unsigned int))sub_101A0AE0;
  large[5] = (int (__cdecl *)(struct jpeg_common_struct *, unsigned int, unsigned int))sub_101A0B50;
  large[6] = (int (__cdecl *)(struct jpeg_common_struct *, unsigned int, unsigned int))sub_101A0BC0;
  large[7] = (int (__cdecl *)(struct jpeg_common_struct *, unsigned int, unsigned int))sub_101A0EA0;
  large[8] = (int (__cdecl *)(struct jpeg_common_struct *, unsigned int, unsigned int))sub_101A0FE0;
  large[9] = (int (__cdecl *)(struct jpeg_common_struct *, unsigned int, unsigned int))sub_101A1130;
  large[10] = (int (__cdecl *)(struct jpeg_common_struct *, unsigned int, unsigned int))sub_101A1240;
  large[12] = (int (__cdecl *)(struct jpeg_common_struct *, unsigned int, unsigned int))1000000000;
  large[11] = (int (__cdecl *)(struct jpeg_common_struct *, unsigned int, unsigned int))v5;
  large[14] = nullptr;
  large[16] = nullptr;
  large[13] = nullptr;
  large[15] = nullptr;
  large[17] = nullptr;
  large[18] = nullptr;
  large[19] = (int (__cdecl *)(struct jpeg_common_struct *, unsigned int, unsigned int))84;
  v2[1] = (void *(__cdecl *)(const char *, int *))large;
  v4 = getenv(option: "JPEGMEM");
  if ( v4 != nullptr )
  {
    LOBYTE(pFactoryList) = 120;
    if ( sscanf(string: v4, format: "%ld%c", &v5, &pFactoryList) > 0 )
    {
      if ( (_BYTE)pFactoryList == 109 || (_BYTE)pFactoryList == 77 )
        large[11] = (int (__cdecl *)(struct jpeg_common_struct *, unsigned int, unsigned int))(1000000 * v5);
      else
        large[11] = (int (__cdecl *)(struct jpeg_common_struct *, unsigned int, unsigned int))(1000 * v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A13B0
// Name: void jpeg_abort(struct jpeg_common_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_abort(struct jpeg_common_struct *a1)
{
  int v1; // eax

  v1 = *((_DWORD *)a1 + 1);
  if ( v1 != 0 )
  {
    (*(void (__cdecl **)(struct jpeg_common_struct *, int))(v1 + 36))(a1, a2: 1);
    if ( *((_BYTE *)a1 + 16) != 0 )
    {
      *((_DWORD *)a1 + 5) = 200;
      *((_DWORD *)a1 + 67) = 0;
    }
    else
    {
      *((_DWORD *)a1 + 5) = 100;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A13F0
// Name: void jpeg_destroy(struct jpeg_common_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_destroy(struct jpeg_common_struct *a1)
{
  int v1; // eax

  v1 = *((_DWORD *)a1 + 1);
  if ( v1 != 0 )
    (*(void (__cdecl **)(struct jpeg_common_struct *))(v1 + 40))(a1);
  *((_DWORD *)a1 + 5) = 0;
  *((_DWORD *)a1 + 1) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A1420
// Name: struct JQUANT_TBL __near * jpeg_alloc_quant_table(struct jpeg_common_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct JQUANT_TBL *__cdecl jpeg_alloc_quant_table(struct jpeg_common_struct *a1)
{
  struct JQUANT_TBL *result; // eax

  result = (struct JQUANT_TBL *)(**((int (__cdecl ***)(struct jpeg_common_struct *, _DWORD, int))a1 + 1))(
                                  a1,
                                  a2: 0,
                                  a3: 130);
  *((_BYTE *)result + 128) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A1440
// Name: struct JHUFF_TBL __near * jpeg_alloc_huff_table(struct jpeg_common_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
struct JHUFF_TBL *__cdecl jpeg_alloc_huff_table(struct jpeg_common_struct *a1)
{
  struct JHUFF_TBL *result; // eax

  result = (struct JHUFF_TBL *)(**((int (__cdecl ***)(struct jpeg_common_struct *, _DWORD, int))a1 + 1))(
                                 a1,
                                 a2: 0,
                                 a3: 274);
  *((_BYTE *)result + 273) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A1460
// Name: long jdiv_round_up(long,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl jdiv_round_up(int a1, int a2)
{
  return (a1 + a2 - 1) / a2;
}

//------------------------------------------------------------------------------
// Address: 0x101A1470
// Name: long jround_up(long,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl jround_up(int a1, int a2)
{
  return a1 + a2 - 1 - (a1 + a2 - 1) % a2;
}

//------------------------------------------------------------------------------
// Address: 0x101A1490
// Name: void jcopy_sample_rows(unsigned char __near * __near *,int,unsigned char __near * __near *,int,int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jcopy_sample_rows(unsigned __int8 **a1, int a2, unsigned __int8 **a3, int a4, int a5, unsigned int count)
{
  int v6; // ebx
  unsigned __int8 **v7; // esi
  unsigned __int8 **i; // edi
  unsigned __int8 *v9; // [esp-10h] [ebp-1Ch]
  unsigned __int8 *v10; // [esp-Ch] [ebp-18h]

  v6 = a5;
  v7 = &a1[a2];
  for ( i = &a3[a4]; v6 > 0; --v6 )
  {
    v10 = *v7;
    v9 = *i;
    ++v7;
    ++i;
    memcpy(dst: v9, src: v10, count);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A14E0
// Name: void jcopy_block_row(short (__near *)[64],short (__near *)[64],unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jcopy_block_row(__int16 (*src)[64], __int16 (*dst)[64], unsigned int a3)
{
  memcpy((unsigned __int8 *)dst, (unsigned __int8 *)src, count: a3 << 7);
}

//------------------------------------------------------------------------------
// Address: 0x101A1500
// Name: void jzero_far(void __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jzero_far(unsigned __int8 *dst, unsigned int count)
{
  memset(dst, value: 0, count);
}

//------------------------------------------------------------------------------
// Address: 0x101A1520
// Name: sub_101A1520
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __fastcall sub_101A1520(int a1, int a2)
{
  _DWORD *v2; // ecx
  char result; // al
  int v4; // edx

  if ( *(_BYTE *)(a2 + 72) != 0 )
    return 0;
  if ( *(_BYTE *)(a2 + 266) != 0 )
    return 0;
  if ( *(_DWORD *)(a2 + 40) != 3 )
    return 0;
  if ( *(_DWORD *)(a2 + 36) != 3 )
    return 0;
  if ( *(_DWORD *)(a2 + 44) != 2 )
    return 0;
  if ( *(_DWORD *)(a2 + 100) != 3 )
    return 0;
  v2 = *(_DWORD **)(a2 + 196);
  if ( v2[2] != 2 )
    return 0;
  result = 1;
  if ( v2[23] != 1 )
    return 0;
  if ( v2[44] != 1 )
    return 0;
  if ( (int)v2[3] > 2 )
    return 0;
  if ( v2[24] != 1 )
    return 0;
  if ( v2[45] != 1 )
    return 0;
  v4 = *(_DWORD *)(a2 + 280);
  if ( v2[9] != v4 || v2[30] != v4 || v2[51] != v4 )
    return 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A15A0
// Name: void jpeg_calc_output_dimensions(struct jpeg_decompress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_calc_output_dimensions(struct jpeg_decompress_struct *a1)
{
  int v2; // eax
  unsigned int v3; // ecx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  bool v8; // cc
  _DWORD *v9; // ecx
  int v10; // edx
  int i; // eax
  int v12; // ebx
  _DWORD *v13; // edi
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // [esp-10h] [ebp-14h]
  int v18; // [esp-10h] [ebp-14h]
  int v19; // [esp-10h] [ebp-14h]
  struct jpeg_decompress_struct *v20; // [esp+8h] [ebp+4h]

  if ( *((_DWORD *)a1 + 5) != 202 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 20;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = *((_DWORD *)a1 + 5);
    (**(void (__cdecl ***)(struct jpeg_decompress_struct *))a1)(a1);
  }
  v2 = *((_DWORD *)a1 + 12);
  v3 = *((_DWORD *)a1 + 13);
  if ( 8 * v2 > v3 )
  {
    if ( 4 * v2 > v3 )
    {
      if ( 2 * v2 > v3 )
      {
        v5 = *((_DWORD *)a1 + 8);
        *((_DWORD *)a1 + 23) = *((_DWORD *)a1 + 7);
        *((_DWORD *)a1 + 70) = 8;
      }
      else
      {
        v7 = jdiv_round_up(a1: *((_DWORD *)a1 + 7), a2: 2);
        v19 = *((_DWORD *)a1 + 8);
        *((_DWORD *)a1 + 23) = v7;
        v5 = jdiv_round_up(a1: v19, a2: 2);
        *((_DWORD *)a1 + 70) = 4;
      }
    }
    else
    {
      v6 = jdiv_round_up(a1: *((_DWORD *)a1 + 7), a2: 4);
      v18 = *((_DWORD *)a1 + 8);
      *((_DWORD *)a1 + 23) = v6;
      v5 = jdiv_round_up(a1: v18, a2: 4);
      *((_DWORD *)a1 + 70) = 2;
    }
  }
  else
  {
    v4 = jdiv_round_up(a1: *((_DWORD *)a1 + 7), a2: 8);
    v17 = *((_DWORD *)a1 + 8);
    *((_DWORD *)a1 + 23) = v4;
    v5 = jdiv_round_up(a1: v17, a2: 8);
    *((_DWORD *)a1 + 70) = 1;
  }
  v8 = *((_DWORD *)a1 + 9) <= 0;
  v9 = *((_DWORD **)a1 + 49);
  *((_DWORD *)a1 + 24) = v5;
  v20 = nullptr;
  if ( !v8 )
  {
    v9 += 3;
    do
    {
      v10 = *((_DWORD *)a1 + 70);
      for ( i = v10; i < 8; i *= 2 )
      {
        if ( 2 * i * *(v9 - 1) > v10 * *((_DWORD *)a1 + 68) )
          break;
        if ( 2 * i * *v9 > v10 * *((_DWORD *)a1 + 69) )
          break;
      }
      v9[6] = i;
      v9 += 21;
      v20 = (struct jpeg_decompress_struct *)((char *)v20 + 1);
    }
    while ( (int)v20 < *((_DWORD *)a1 + 9) );
  }
  v12 = 0;
  if ( *((int *)a1 + 9) > 0 )
  {
    v13 = (_DWORD *)(*((_DWORD *)a1 + 49) + 36);
    do
    {
      v14 = jdiv_round_up(a1: *((_DWORD *)a1 + 7) * *v13 * *(v13 - 7), a2: 8 * *((_DWORD *)a1 + 68));
      v15 = *(v13 - 6);
      v13[1] = v14;
      v13[2] = jdiv_round_up(a1: *v13 * *((_DWORD *)a1 + 8) * v15, a2: 8 * *((_DWORD *)a1 + 69));
      ++v12;
      v13 += 21;
    }
    while ( v12 < *((_DWORD *)a1 + 9) );
  }
  switch ( *((_DWORD *)a1 + 11) )
  {
    case 1:
      *((_DWORD *)a1 + 25) = 1;
      break;
    case 2:
    case 3:
      *((_DWORD *)a1 + 25) = 3;
      break;
    case 4:
    case 5:
      *((_DWORD *)a1 + 25) = 4;
      break;
    default:
      *((_DWORD *)a1 + 25) = *((_DWORD *)a1 + 9);
      break;
  }
  v16 = 1;
  if ( *((_BYTE *)a1 + 74) == 0 )
    v16 = *((_DWORD *)a1 + 25);
  *((_DWORD *)a1 + 26) = v16;
  if ( sub_101A1520(a1: (int)v9, a2: (int)a1) != 0 )
    *((_DWORD *)a1 + 27) = *((_DWORD *)a1 + 69);
  else
    *((_DWORD *)a1 + 27) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x101A17D0
// Name: sub_101A17D0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_101A17D0(int a1@<ebx>)
{
  unsigned __int8 *v1; // eax
  unsigned __int8 *v2; // esi
  int i; // eax
  unsigned __int8 *v4; // esi

  v1 = (unsigned __int8 *)(**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, a2: 1, a3: 1408);
  v2 = v1 + 256;
  *(_DWORD *)(a1 + 288) = v1 + 256;
  memset(dst: v1, value: 0, count: 0x100u);
  for ( i = 0; i <= 255; ++i )
    v2[i] = i;
  v4 = v2 + 128;
  memset(dst: v4 + 128, value: 0xFFu, count: 0x180u);
  memset(dst: v4 + 512, value: 0, count: 0x180u);
  qmemcpy(v4 + 896, *(const void **)(a1 + 288), 0x80u);
}

//------------------------------------------------------------------------------
// Address: 0x101A1870
// Name: sub_101A1870
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A1870@<eax>(int a1@<esi>)
{
  int v1; // edi
  int v2; // ecx
  char v3; // al
  int result; // eax
  int v5; // ecx
  int v6; // eax
  struct jpeg_decompress_struct *v7; // [esp+0h] [ebp-10h]
  unsigned __int8 v8; // [esp+Ch] [ebp-4h]

  v1 = *(_DWORD *)(a1 + 384);
  jpeg_calc_output_dimensions(a1: v7);
  sub_101A17D0(a1);
  *(_DWORD *)(v1 + 12) = 0;
  *(_BYTE *)(v1 + 16) = sub_101A1520(a1: v2, a2: a1);
  *(_DWORD *)(v1 + 20) = 0;
  *(_DWORD *)(v1 + 24) = 0;
  v3 = *(_BYTE *)(a1 + 74);
  if ( v3 == 0 || *(_BYTE *)(a1 + 64) == 0 )
  {
    *(_BYTE *)(a1 + 88) = 0;
    *(_BYTE *)(a1 + 89) = 0;
    *(_BYTE *)(a1 + 90) = 0;
  }
  if ( v3 != 0 )
  {
    if ( *(_BYTE *)(a1 + 65) != 0 )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 47;
      (**(void (__cdecl ***)(int))a1)(a1);
    }
    if ( *(_DWORD *)(a1 + 100) == 3 )
    {
      if ( *(_DWORD *)(a1 + 116) != 0 )
      {
        *(_BYTE *)(a1 + 89) = 1;
        goto LABEL_10;
      }
      if ( *(_BYTE *)(a1 + 80) != 0 )
      {
        *(_BYTE *)(a1 + 90) = 1;
        goto LABEL_10;
      }
    }
    else
    {
      *(_BYTE *)(a1 + 89) = 0;
      *(_BYTE *)(a1 + 90) = 0;
      *(_DWORD *)(a1 + 116) = 0;
    }
    *(_BYTE *)(a1 + 88) = 1;
LABEL_10:
    if ( *(_BYTE *)(a1 + 88) != 0 )
    {
      jinit_1pass_quantizer((struct jpeg_decompress_struct *)a1);
      *(_DWORD *)(v1 + 20) = *(_DWORD *)(a1 + 424);
    }
    if ( *(_BYTE *)(a1 + 90) != 0 || *(_BYTE *)(a1 + 89) != 0 )
    {
      jinit_2pass_quantizer((struct jpeg_decompress_struct *)a1);
      *(_DWORD *)(v1 + 24) = *(_DWORD *)(a1 + 424);
    }
  }
  if ( *(_BYTE *)(a1 + 65) == 0 )
  {
    if ( *(_BYTE *)(v1 + 16) != 0 )
    {
      jinit_merged_upsampler((struct jpeg_decompress_struct *)a1);
    }
    else
    {
      jinit_color_deconverter((struct jpeg_decompress_struct *)a1);
      jinit_upsampler((struct jpeg_decompress_struct *)a1);
    }
    jinit_d_post_controller((struct jpeg_decompress_struct *)a1, a2: *(_BYTE *)(a1 + 90));
  }
  jinit_inverse_dct((struct jpeg_decompress_struct *)a1);
  if ( *(_BYTE *)(a1 + 201) != 0 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 1;
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  else if ( *(_BYTE *)(a1 + 200) != 0 )
  {
    jinit_phuff_decoder((struct jpeg_decompress_struct *)a1);
  }
  else
  {
    jinit_huff_decoder((struct jpeg_decompress_struct *)a1);
  }
  if ( *(_BYTE *)(*(_DWORD *)(a1 + 400) + 16) != 0 || (v8 = 0, *(_BYTE *)(a1 + 64) != 0) )
    v8 = 1;
  jinit_d_coef_controller((struct jpeg_decompress_struct *)a1, a2: v8);
  if ( *(_BYTE *)(a1 + 65) == 0 )
    jinit_d_main_controller((struct jpeg_decompress_struct *)a1, a2: 0);
  (*(void (__cdecl **)(int))(*(_DWORD *)(a1 + 4) + 24))(a1);
  result = (*(int (__cdecl **)(int))(*(_DWORD *)(a1 + 400) + 8))(a1);
  v5 = *(_DWORD *)(a1 + 8);
  if ( v5 != 0 && *(_BYTE *)(a1 + 64) == 0 )
  {
    result = *(_DWORD *)(a1 + 400);
    if ( *(_BYTE *)(result + 16) != 0 )
    {
      v6 = *(_DWORD *)(a1 + 36);
      if ( *(_BYTE *)(a1 + 200) != 0 )
        v6 = 3 * v6 + 2;
      *(_DWORD *)(v5 + 4) = 0;
      *(_DWORD *)(*(_DWORD *)(a1 + 8) + 8) = v6 * *(_DWORD *)(a1 + 284);
      result = *(_DWORD *)(a1 + 8);
      *(_DWORD *)(result + 12) = 0;
      *(_DWORD *)(*(_DWORD *)(a1 + 8) + 16) = (*(_BYTE *)(a1 + 90) != 0) + 2;
      ++*(_DWORD *)(v1 + 12);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A1A40
// Name: sub_101A1A40
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A1A40(int a1)
{
  int v1; // edi
  int result; // eax

  v1 = *(_DWORD *)(a1 + 384);
  if ( *(_BYTE *)(v1 + 8) != 0 )
  {
    *(_BYTE *)(v1 + 8) = 0;
    (**(void (__cdecl ***)(int, _DWORD))(a1 + 424))(a1, a2: 0);
    (**(void (__cdecl ***)(int, int))(a1 + 396))(a1, a2: 2);
    (**(void (__cdecl ***)(int, int))(a1 + 388))(a1, a2: 2);
  }
  else
  {
    if ( *(_BYTE *)(a1 + 74) != 0 && *(_DWORD *)(a1 + 116) == 0 )
    {
      if ( *(_BYTE *)(a1 + 80) != 0 && *(_BYTE *)(a1 + 90) != 0 )
      {
        *(_DWORD *)(a1 + 424) = *(_DWORD *)(v1 + 24);
        *(_BYTE *)(v1 + 8) = 1;
      }
      else if ( *(_BYTE *)(a1 + 88) != 0 )
      {
        *(_DWORD *)(a1 + 424) = *(_DWORD *)(v1 + 20);
      }
      else
      {
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 46;
        (**(void (__cdecl ***)(int))a1)(a1);
      }
    }
    (**(void (__cdecl ***)(int))(a1 + 412))(a1);
    (*(void (__cdecl **)(int))(*(_DWORD *)(a1 + 392) + 8))(a1);
    if ( *(_BYTE *)(a1 + 65) == 0 )
    {
      if ( *(_BYTE *)(v1 + 16) == 0 )
        (**(void (__cdecl ***)(int))(a1 + 420))(a1);
      (**(void (__cdecl ***)(int))(a1 + 416))(a1);
      if ( *(_BYTE *)(a1 + 74) != 0 )
        (**(void (__cdecl ***)(int, _DWORD))(a1 + 424))(a1, a2: *(unsigned __int8 *)(v1 + 8));
      (**(void (__cdecl ***)(int, int))(a1 + 396))(a1, a2: *(_BYTE *)(v1 + 8) != 0 ? 3 : 0);
      (**(void (__cdecl ***)(int, _DWORD))(a1 + 388))(a1, a2: 0);
    }
  }
  result = *(_DWORD *)(a1 + 8);
  if ( result != 0 )
  {
    *(_DWORD *)(result + 12) = *(_DWORD *)(v1 + 12);
    result = *(_DWORD *)(a1 + 8);
    *(_DWORD *)(result + 16) = *(_DWORD *)(v1 + 12) + (*(_BYTE *)(v1 + 8) != 0) + 1;
    if ( *(_BYTE *)(a1 + 64) != 0 && *(_BYTE *)(*(_DWORD *)(a1 + 400) + 17) == 0 )
    {
      result = *(_DWORD *)(a1 + 8);
      *(_DWORD *)(result + 16) += (*(_BYTE *)(a1 + 90) != 0) + 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A1BA0
// Name: sub_101A1BA0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A1BA0(int a1)
{
  int result; // eax
  int v2; // esi

  result = a1;
  v2 = *(_DWORD *)(a1 + 384);
  if ( *(_BYTE *)(a1 + 74) != 0 )
    result = (*(int (__cdecl **)(int))(*(_DWORD *)(a1 + 424) + 8))(a1);
  ++*(_DWORD *)(v2 + 12);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A1BD0
// Name: void jinit_master_decompress(struct jpeg_decompress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jinit_master_decompress(int (__cdecl ***a1)(struct jpeg_decompress_struct *, int, int))
{
  int v1; // eax

  v1 = (*a1[1])((struct jpeg_decompress_struct *)a1, a2: 1, a3: 28);
  a1[96] = (int (__cdecl **)(struct jpeg_decompress_struct *, int, int))v1;
  *(_DWORD *)v1 = sub_101A1A40;
  *(_DWORD *)(v1 + 4) = sub_101A1BA0;
  *(_BYTE *)(v1 + 8) = 0;
  sub_101A1870((int)a1);
}

//------------------------------------------------------------------------------
// Address: 0x101A1C10
// Name: sub_101A1C10
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__thiscall sub_101A1C10(_DWORD *this)
{
  _DWORD *result; // eax
  int v2; // edx
  bool v3; // cf
  int v4; // ecx

  result = (_DWORD *)*(this + 98);
  v2 = 1;
  if ( (int)*(this + 73) <= 1 )
  {
    v3 = *(this + 32) < (unsigned int)(*(this + 71) - 1);
    v4 = *(this + 74);
    if ( v3 )
    {
      result[7] = *(_DWORD *)(v4 + 12);
      result[5] = 0;
      result[6] = 0;
      return result;
    }
    v2 = *(_DWORD *)(v4 + 72);
  }
  result[7] = v2;
  result[5] = 0;
  result[6] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A1C60
// Name: sub_101A1C60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__cdecl sub_101A1C60(_DWORD *a1)
{
  a1[32] = 0;
  return sub_101A1C10(this: a1);
}

//------------------------------------------------------------------------------
// Address: 0x101A1C80
// Name: sub_101A1C80
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A1C80(_DWORD *a1, int a2)
{
  _DWORD *v2; // ebp
  int v3; // esi
  int v4; // eax
  unsigned int v5; // ebx
  unsigned int v6; // edi
  int v7; // ecx
  _DWORD *v8; // esi
  int v9; // eax
  int v10; // edx
  int v11; // edi
  int v12; // ebx
  int v13; // eax
  _DWORD *v14; // ebp
  unsigned int v15; // eax
  int v17; // [esp+10h] [ebp-34h]
  unsigned int v18; // [esp+14h] [ebp-30h]
  int v19; // [esp+18h] [ebp-2Ch]
  int v20; // [esp+1Ch] [ebp-28h]
  _DWORD *v21; // [esp+20h] [ebp-24h]
  int v22; // [esp+24h] [ebp-20h]
  int j; // [esp+28h] [ebp-1Ch]
  int i; // [esp+2Ch] [ebp-18h]
  int v25; // [esp+30h] [ebp-14h]
  unsigned int v26; // [esp+34h] [ebp-10h]
  unsigned int v27; // [esp+38h] [ebp-Ch]
  void (__cdecl *v28)(_DWORD *, _DWORD *, _DWORD, int, int); // [esp+3Ch] [ebp-8h]
  int v29; // [esp+40h] [ebp-4h]

  v2 = a1;
  v3 = a1[98];
  v27 = a1[71] - 1;
  v4 = *(_DWORD *)(v3 + 24);
  v5 = a1[78] - 1;
  v19 = v3;
  v26 = v5;
  v17 = v4;
  if ( v4 >= *(_DWORD *)(v3 + 28) )
  {
LABEL_23:
    v15 = ++v2[32];
    ++v2[34];
    if ( v15 >= v2[71] )
    {
      (*(void (__cdecl **)(_DWORD *))(v2[100] + 12))(a1: v2);
      return 4;
    }
    else
    {
      sub_101A1C10(this: v2);
      return 3;
    }
  }
  else
  {
    while ( 1 )
    {
      v6 = *(_DWORD *)(v3 + 20);
      v18 = v6;
      if ( v6 <= v5 )
        break;
LABEL_22:
      ++v4;
      *(_DWORD *)(v3 + 20) = 0;
      v17 = v4;
      if ( v4 >= *(_DWORD *)(v3 + 28) )
        goto LABEL_23;
    }
    while ( 1 )
    {
      jzero_far(dst: *(unsigned __int8 **)(v3 + 32), count: v2[80] << 7);
      if ( (*(unsigned __int8 (__cdecl **)(_DWORD *, int))(v2[102] + 4))(a1: v2, a2: v3 + 32) == 0 )
        break;
      v7 = 0;
      v20 = 0;
      v25 = 0;
      if ( (int)v2[73] > 0 )
      {
        v21 = v2 + 74;
        do
        {
          v8 = (_DWORD *)*v21;
          if ( *(_BYTE *)(*v21 + 48) != 0 )
          {
            v9 = 4 * v8[1];
            v28 = *(void (__cdecl **)(_DWORD *, _DWORD *, _DWORD, int, int))(v2[103] + v9 + 4);
            if ( v6 >= v5 )
              v10 = v8[17];
            else
              v10 = v8[13];
            v11 = v18 * v8[16];
            v22 = v10;
            v12 = *(_DWORD *)(v9 + a2) + 4 * v17 * v8[9];
            v13 = 0;
            v29 = v11;
            for ( i = 0; v13 < v8[14]; i = v13 )
            {
              if ( (v2[32] < v27 || v13 + v17 < v8[18]) && v22 > 0 )
              {
                v14 = (_DWORD *)(v19 + 4 * v7 + 32);
                for ( j = v22; j != 0; --j )
                {
                  v28(a1, a2: v8, a3: *v14, a4: v12, a5: v11);
                  v11 += v8[9];
                  ++v14;
                }
                v11 = v29;
                v7 = v20;
                v2 = a1;
                v13 = i;
              }
              v7 += v8[13];
              ++v13;
              v20 = v7;
              v12 += 4 * v8[9];
            }
          }
          else
          {
            v7 += v8[15];
            v20 = v7;
          }
          ++v21;
          v5 = v26;
          v6 = v18;
          ++v25;
        }
        while ( v25 < v2[73] );
      }
      v3 = v19;
      v18 = ++v6;
      if ( v6 > v5 )
      {
        v4 = v17;
        goto LABEL_22;
      }
    }
    *(_DWORD *)(v19 + 20) = v6;
    *(_DWORD *)(v19 + 24) = v17;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A1EC0
// Name: sub_101A1EC0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A1EC0(_DWORD *a1)
{
  _DWORD *v1; // ebp
  _DWORD *v2; // edi
  int v3; // esi
  int v4; // eax
  int v5; // esi
  int v6; // edx
  int v7; // ebx
  int v8; // edi
  int v9; // ecx
  _DWORD *v10; // ebp
  int v11; // eax
  int v12; // edx
  int *v13; // esi
  _DWORD *v15; // [esp+10h] [ebp-2Ch]
  unsigned int v16; // [esp+10h] [ebp-2Ch]
  _DWORD *v17; // [esp+14h] [ebp-28h]
  int v18; // [esp+18h] [ebp-24h]
  int v19; // [esp+1Ch] [ebp-20h]
  _DWORD *v20; // [esp+20h] [ebp-1Ch]
  int v21; // [esp+24h] [ebp-18h]
  int v22; // [esp+28h] [ebp-14h]
  _DWORD v23[4]; // [esp+2Ch] [ebp-10h]

  v1 = a1;
  v2 = (_DWORD *)a1[98];
  v3 = 0;
  v20 = v2;
  if ( (int)a1[73] > 0 )
  {
    v15 = a1 + 74;
    do
    {
      v4 = (*(int (__cdecl **)(_DWORD *, _DWORD, int, _DWORD, int))(a1[1] + 32))(
             a1,
             a2: v2[*(_DWORD *)(*v15 + 4) + 18],
             a3: *(_DWORD *)(*v15 + 12) * a1[32],
             a4: *(_DWORD *)(*v15 + 12),
             a5: 1);
      ++v15;
      v23[v3++] = v4;
    }
    while ( v3 < a1[73] );
  }
  v5 = v2[6];
  v21 = v5;
  if ( v5 >= v2[7] )
  {
LABEL_20:
    if ( ++v1[32] >= v1[71] )
    {
      (*(void (__cdecl **)(_DWORD *))(v1[100] + 12))(a1: v1);
      return 4;
    }
    else
    {
      sub_101A1C10(this: v1);
      return 3;
    }
  }
  else
  {
    while ( 1 )
    {
      v16 = v2[5];
      if ( v16 < v1[78] )
        break;
LABEL_19:
      ++v5;
      v2[5] = 0;
      v21 = v5;
      if ( v5 >= v2[7] )
        goto LABEL_20;
    }
    while ( 1 )
    {
      v6 = 0;
      v7 = 0;
      v19 = 0;
      if ( (int)v1[73] > 0 )
      {
        v17 = v1 + 74;
        do
        {
          v8 = *v17;
          v9 = *(_DWORD *)(*v17 + 52);
          v18 = 0;
          if ( *(int *)(*v17 + 56) > 0 )
          {
            v22 = (v16 * *(_DWORD *)(*v17 + 52)) << 7;
            v10 = (_DWORD *)(v23[v6] + 4 * v5);
            do
            {
              v11 = v22 + *v10;
              v12 = 0;
              if ( v9 > 0 )
              {
                v13 = &v20[v7 + 8];
                do
                {
                  *v13 = v11;
                  v9 = *(_DWORD *)(v8 + 52);
                  ++v12;
                  ++v7;
                  ++v13;
                  v11 += 128;
                }
                while ( v12 < v9 );
              }
              ++v10;
              ++v18;
            }
            while ( v18 < *(_DWORD *)(v8 + 56) );
            v1 = a1;
            v6 = v19;
            v5 = v21;
          }
          ++v17;
          v19 = ++v6;
        }
        while ( v6 < v1[73] );
        v2 = v20;
      }
      if ( (*(unsigned __int8 (__cdecl **)(_DWORD *, _DWORD *))(v1[102] + 4))(a1: v1, a2: v2 + 8) == 0 )
        break;
      if ( ++v16 >= v1[78] )
        goto LABEL_19;
    }
    v2[6] = v5;
    v2[5] = v16;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A20B0
// Name: sub_101A20B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A20B0(int a1, int a2)
{
  _DWORD *v2; // edi
  int v3; // ebp
  int v4; // eax
  int v5; // ecx
  int result; // eax
  int v7; // ebx
  int v8; // esi
  _DWORD *v9; // ebp
  int v10; // ecx
  unsigned int v11; // eax
  int v12; // ebx
  int v13; // edi
  unsigned int v14; // ebp
  int v15; // [esp+8h] [ebp-20h]
  int v16; // [esp+Ch] [ebp-1Ch]
  int v17; // [esp+10h] [ebp-18h]
  int v18; // [esp+14h] [ebp-14h]
  _DWORD *v19; // [esp+18h] [ebp-10h]
  unsigned int v20; // [esp+1Ch] [ebp-Ch]
  int v21; // [esp+20h] [ebp-8h]
  void (__cdecl *v22)(int, int, int, int, int); // [esp+24h] [ebp-4h]

  v2 = (_DWORD *)a1;
  v3 = *(_DWORD *)(a1 + 392);
  v20 = *(_DWORD *)(a1 + 284) - 1;
  while ( 1 )
  {
    v4 = *(_DWORD *)(a1 + 124);
    v5 = *(_DWORD *)(a1 + 132);
    if ( v4 >= v5 && (v4 != v5 || *(_DWORD *)(a1 + 128) > *(_DWORD *)(a1 + 136)) )
      break;
    result = (**(int (__cdecl ***)(int))(a1 + 400))(a1);
    if ( result == 0 )
      return result;
  }
  v7 = 0;
  v8 = *(_DWORD *)(a1 + 196);
  v18 = 0;
  if ( *(int *)(a1 + 36) > 0 )
  {
    v9 = (_DWORD *)(v3 + 72);
    v19 = v9;
    do
    {
      if ( *(_BYTE *)(v8 + 48) != 0 )
      {
        v21 = (*(int (__cdecl **)(_DWORD *, _DWORD, int, _DWORD, _DWORD))(v2[1] + 32))(
                a1: v2,
                a2: *v9,
                a3: *(_DWORD *)(v8 + 12) * v2[34],
                a4: *(_DWORD *)(v8 + 12),
                a5: 0);
        if ( v2[34] >= v20 )
        {
          v15 = *(_DWORD *)(v8 + 32) % *(_DWORD *)(v8 + 12);
          if ( v15 == 0 )
            v15 = *(_DWORD *)(v8 + 12);
        }
        else
        {
          v15 = *(_DWORD *)(v8 + 12);
        }
        v16 = *(_DWORD *)(a2 + 4 * v7);
        v10 = 0;
        v22 = *(void (__cdecl **)(int, int, int, int, int))(v2[103] + 4 * v7 + 4);
        v17 = 0;
        if ( v15 > 0 )
        {
          v11 = *(_DWORD *)(v8 + 28);
          do
          {
            v12 = *(_DWORD *)(v21 + 4 * v10);
            v13 = 0;
            v14 = 0;
            if ( v11 != 0 )
            {
              do
              {
                v22(a1, a2: v8, a3: v12, a4: v16, a5: v13);
                v11 = *(_DWORD *)(v8 + 28);
                v13 += *(_DWORD *)(v8 + 36);
                ++v14;
                v12 += 128;
              }
              while ( v14 < v11 );
              v10 = v17;
            }
            ++v10;
            v16 += 4 * *(_DWORD *)(v8 + 36);
            v17 = v10;
          }
          while ( v10 < v15 );
          v7 = v18;
          v2 = (_DWORD *)a1;
        }
      }
      ++v7;
      v9 = v19 + 1;
      v8 += 84;
      v18 = v7;
      ++v19;
    }
    while ( v7 < v2[9] );
  }
  return 4 - (++v2[34] < v2[71]);
}

//------------------------------------------------------------------------------
// Address: 0x101A2240
// Name: sub_101A2240
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall sub_101A2240@<al>(int a1@<edi>)
{
  int v1; // esi
  _DWORD *v2; // edx
  int v3; // esi
  int v4; // ebp
  _WORD **v5; // eax
  _WORD *v6; // eax
  int *v7; // eax
  char v9; // [esp+7h] [ebp-5h]
  _WORD **i; // [esp+8h] [ebp-4h]

  v1 = *(_DWORD *)(a1 + 392);
  v9 = 0;
  if ( *(_BYTE *)(a1 + 200) == 0 || *(_DWORD *)(a1 + 140) == 0 )
    return 0;
  if ( *(_DWORD *)(v1 + 112) == 0 )
    *(_DWORD *)(v1 + 112) = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, a2: 1, a3: 24 * *(_DWORD *)(a1 + 36));
  v2 = *(_DWORD **)(v1 + 112);
  v3 = 0;
  if ( *(int *)(a1 + 36) <= 0 )
    return v9;
  v4 = 0;
  v5 = (_WORD **)(*(_DWORD *)(a1 + 196) + 76);
  for ( i = v5; ; i += 21 )
  {
    v6 = *v5;
    if ( v6 == nullptr )
      break;
    if ( *v6 == 0 )
      break;
    if ( v6[1] == 0 )
      break;
    if ( v6[8] == 0 )
      break;
    if ( v6[16] == 0 )
      break;
    if ( v6[9] == 0 )
      break;
    if ( v6[2] == 0 )
      break;
    v7 = (int *)(v4 + *(_DWORD *)(a1 + 140));
    if ( *v7 < 0 )
      break;
    v2[1] = v7[1];
    if ( v7[1] != 0 )
      v9 = 1;
    v2[2] = v7[2];
    if ( v7[2] != 0 )
      v9 = 1;
    v2[3] = v7[3];
    if ( v7[3] != 0 )
      v9 = 1;
    v2[4] = v7[4];
    if ( v7[4] != 0 )
      v9 = 1;
    v2[5] = v7[5];
    if ( v7[5] != 0 )
      v9 = 1;
    ++v3;
    v5 = i + 21;
    v2 += 6;
    v4 += 256;
    if ( v3 >= *(_DWORD *)(a1 + 36) )
      return v9;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A23A0
// Name: sub_101A23A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A23A0(_DWORD *a1, int a2)
{
  int v2; // eax
  int v3; // ebx
  unsigned int v4; // esi
  unsigned int v5; // ecx
  int v6; // eax
  _DWORD *v8; // esi
  int v9; // eax
  unsigned __int16 *v10; // eax
  __int16 *v11; // ecx
  __int16 *v12; // eax
  int v13; // esi
  int v14; // edi
  int v15; // ebp
  int v16; // ecx
  int v17; // eax
  int v18; // ebx
  int v19; // edx
  int v20; // eax
  int v21; // eax
  int v22; // ecx
  int v23; // eax
  int v24; // ebx
  int v25; // edx
  int v26; // eax
  int v27; // eax
  int v28; // ecx
  int v29; // edx
  int v30; // eax
  int v31; // ebx
  int v32; // eax
  int v33; // eax
  int v34; // ecx
  int v35; // edx
  int v36; // eax
  int v37; // edi
  int v38; // eax
  int v39; // eax
  int v40; // ecx
  int v41; // edx
  int v42; // eax
  int v43; // edi
  int v44; // eax
  int v45; // eax
  int v46; // ecx
  bool v47; // cc
  int v48; // [esp-18h] [ebp-128h]
  char v49; // [esp+6h] [ebp-10Ah]
  char v50; // [esp+7h] [ebp-109h]
  __int16 *src; // [esp+Ch] [ebp-104h]
  _DWORD *v52; // [esp+10h] [ebp-100h]
  int v53; // [esp+14h] [ebp-FCh]
  int v54; // [esp+18h] [ebp-F8h]
  int v55; // [esp+1Ch] [ebp-F4h]
  int v56; // [esp+20h] [ebp-F0h]
  _DWORD *v57; // [esp+24h] [ebp-ECh]
  int v58; // [esp+28h] [ebp-E8h]
  int v59; // [esp+2Ch] [ebp-E4h]
  int v60; // [esp+30h] [ebp-E0h]
  int v61; // [esp+34h] [ebp-DCh]
  unsigned int v62; // [esp+38h] [ebp-D8h]
  int v63; // [esp+3Ch] [ebp-D4h]
  int v64; // [esp+40h] [ebp-D0h]
  __int16 *v65; // [esp+44h] [ebp-CCh]
  int v66; // [esp+48h] [ebp-C8h]
  __int16 *v67; // [esp+4Ch] [ebp-C4h]
  int v68; // [esp+50h] [ebp-C0h]
  int v69; // [esp+54h] [ebp-BCh]
  int v70; // [esp+58h] [ebp-B8h]
  int v71; // [esp+5Ch] [ebp-B4h]
  int v72; // [esp+60h] [ebp-B0h]
  unsigned int v73; // [esp+64h] [ebp-ACh]
  int v74; // [esp+68h] [ebp-A8h]
  int v75; // [esp+6Ch] [ebp-A4h]
  int v76; // [esp+70h] [ebp-A0h]
  int v77; // [esp+74h] [ebp-9Ch]
  int v78; // [esp+78h] [ebp-98h]
  unsigned int v79; // [esp+7Ch] [ebp-94h]
  void (__cdecl *v80)(_DWORD *, int, __int16 *, int, int); // [esp+84h] [ebp-8Ch]
  __int16 dst[64]; // [esp+8Ch] [ebp-84h] BYREF

  v76 = a1[98];
  v79 = a1[71] - 1;
  while ( a1[31] <= a1[33] )
  {
    v2 = a1[100];
    if ( *(_BYTE *)(v2 + 17) != 0
      || a1[31] == a1[33] && __PAIR64__(a1[32], a1[91]) >= __PAIR64__(a1[34], 1) && a1[32] != a1[34] + (a1[91] == 0) )
    {
      break;
    }
    if ( (*(int (__cdecl **)(_DWORD *))v2)(a1) == 0 )
      return 0;
  }
  v3 = a1[49];
  v68 = 0;
  v59 = v3;
  if ( (int)a1[9] > 0 )
  {
    v70 = 0;
    v57 = (_DWORD *)(v76 + 72);
    do
    {
      if ( *(_BYTE *)(v3 + 48) != 0 )
      {
        v4 = a1[34];
        v5 = *(_DWORD *)(v3 + 12);
        if ( v4 >= v79 )
        {
          v6 = *(_DWORD *)(v3 + 32) % v5;
          v54 = v6;
          if ( v6 == 0 )
          {
            v6 = *(_DWORD *)(v3 + 12);
            v54 = v6;
          }
          v49 = 1;
        }
        else
        {
          v54 = *(_DWORD *)(v3 + 12);
          v6 = 2 * v5;
          v49 = 0;
        }
        if ( v4 != 0 )
        {
          v48 = v5 * (v4 - 1);
          v8 = v57;
          v9 = (*(int (__cdecl **)(_DWORD *, _DWORD, int, unsigned int, _DWORD))(a1[1] + 32))(
                 a1,
                 a2: *v57,
                 a3: v48,
                 a4: v5 + v6,
                 a5: 0)
             + 4 * *(_DWORD *)(v3 + 12);
          v50 = 0;
        }
        else
        {
          v8 = v57;
          v9 = (*(int (__cdecl **)(_DWORD *, _DWORD, _DWORD, int, _DWORD))(a1[1] + 32))(
                 a1,
                 a2: *v57,
                 a3: 0,
                 a4: v6,
                 a5: 0);
          v50 = 1;
        }
        v71 = v9;
        v52 = (_DWORD *)(v70 + *(_DWORD *)(v76 + 112));
        v10 = *(unsigned __int16 **)(v3 + 76);
        v53 = *v10;
        v74 = v10[1];
        v78 = v10[8];
        v77 = v10[16];
        v75 = v10[9];
        v72 = v10[2];
        v80 = *(void (__cdecl **)(_DWORD *, int, __int16 *, int, int))((char *)v8 + -72 - v76 + a1[103] + 4);
        v64 = *(_DWORD *)(a2 + 4 * v68);
        v66 = 0;
        if ( v54 > 0 )
        {
          do
          {
            src = *(__int16 **)(v71 + 4 * v66);
            if ( v50 == 0 || (v11 = *(__int16 **)(v71 + 4 * v66), v66 != 0) )
              v11 = *(__int16 **)(v71 + 4 * v66 - 4);
            if ( v49 == 0 || (v12 = *(__int16 **)(v71 + 4 * v66), v66 != v54 - 1) )
              v12 = *(__int16 **)(v71 + 4 * v66 + 4);
            v13 = *src;
            v14 = *v11;
            v15 = *v12;
            v61 = v14;
            v55 = v14;
            v58 = v13;
            v69 = v13;
            v63 = v15;
            v56 = v15;
            v60 = 0;
            v73 = *(_DWORD *)(v3 + 28) - 1;
            v62 = 0;
            v65 = v12 + 64;
            v67 = v11 + 64;
            do
            {
              jcopy_block_row((__int16 (*)[64])src, (__int16 (*)[64])dst, a3: 1u);
              if ( v62 < v73 )
              {
                v13 = src[64];
                v61 = *v67;
                v63 = *v65;
              }
              v16 = v52[1];
              if ( v16 != 0 && dst[1] == 0 )
              {
                v17 = v74 << 7;
                v18 = v74 << 8;
                v19 = 36 * v53 * (v69 - v13);
                if ( ((18 * v53 * (v69 - v13)) & 0x40000000) != 0 )
                {
                  v21 = (v17 - v19) / v18;
                  if ( v16 > 0 && v21 >= 1 << v16 )
                    v21 = (1 << v16) - 1;
                  v20 = -v21;
                }
                else
                {
                  v20 = (v19 + v17) / v18;
                  if ( v16 > 0 && v20 >= 1 << v16 )
                    v20 = (1 << v16) - 1;
                }
                v3 = v59;
                dst[1] = v20;
              }
              v22 = v52[2];
              if ( v22 != 0 && dst[8] == 0 )
              {
                v23 = v78 << 7;
                v24 = v78 << 8;
                v25 = 36 * v53 * (v55 - v56);
                if ( ((18 * v53 * (v55 - v56)) & 0x40000000) != 0 )
                {
                  v27 = (v23 - v25) / v24;
                  if ( v22 > 0 && v27 >= 1 << v22 )
                    v27 = (1 << v22) - 1;
                  v26 = -v27;
                }
                else
                {
                  v26 = (v25 + v23) / v24;
                  if ( v22 > 0 && v26 >= 1 << v22 )
                    v26 = (1 << v22) - 1;
                }
                v3 = v59;
                dst[8] = v26;
              }
              v28 = v52[3];
              if ( v28 != 0 && dst[16] == 0 )
              {
                v29 = 9 * v53 * (v55 + v56 - 2 * v58);
                v30 = v77 << 7;
                v31 = v77 << 8;
                if ( v29 < 0 )
                {
                  v33 = (v30 - v29) / v31;
                  if ( v28 > 0 && v33 >= 1 << v28 )
                    v33 = (1 << v28) - 1;
                  v32 = -v33;
                }
                else
                {
                  v32 = (v29 + v30) / v31;
                  if ( v28 > 0 && v32 >= 1 << v28 )
                    v32 = (1 << v28) - 1;
                }
                v3 = v59;
                dst[16] = v32;
              }
              v34 = v52[4];
              if ( v34 != 0 && dst[9] == 0 )
              {
                v35 = 5 * v53 * (v14 + v63 - v15 - v61);
                v36 = v75 << 7;
                v37 = v75 << 8;
                if ( v35 < 0 )
                {
                  v39 = (v36 - v35) / v37;
                  if ( v34 > 0 && v39 >= 1 << v34 )
                    v39 = (1 << v34) - 1;
                  v38 = -v39;
                }
                else
                {
                  v38 = (v35 + v36) / v37;
                  if ( v34 > 0 && v38 >= 1 << v34 )
                    v38 = (1 << v34) - 1;
                }
                dst[9] = v38;
              }
              v40 = v52[5];
              if ( v40 != 0 && dst[2] == 0 )
              {
                v41 = 9 * v53 * (v69 + v13 - 2 * v58);
                v42 = v72 << 7;
                v43 = v72 << 8;
                if ( v41 < 0 )
                {
                  v45 = (v42 - v41) / v43;
                  if ( v40 > 0 && v45 >= 1 << v40 )
                    v45 = (1 << v40) - 1;
                  v44 = -v45;
                }
                else
                {
                  v44 = (v41 + v42) / v43;
                  if ( v40 > 0 && v44 >= 1 << v40 )
                    v44 = (1 << v40) - 1;
                }
                dst[2] = v44;
              }
              v80(a1, a2: v3, a3: dst, a4: v64, a5: v60);
              v15 = v56;
              v14 = v55;
              v56 = v63;
              src += 64;
              v67 += 64;
              v65 += 64;
              v55 = v61;
              v46 = *(_DWORD *)(v3 + 36);
              v60 += v46;
              v47 = v62 + 1 <= v73;
              v69 = v58;
              v58 = v13;
              ++v62;
            }
            while ( v47 );
            v47 = v66 + 1 < v54;
            v64 += 4 * v46;
            ++v66;
          }
          while ( v47 );
        }
      }
      v70 += 24;
      ++v57;
      v3 += 84;
      v47 = ++v68 < a1[9];
      v59 = v3;
    }
    while ( v47 );
  }
  return 4 - (++a1[34] < a1[71]);
}

//------------------------------------------------------------------------------
// Address: 0x101A29F0
// Name: sub_101A29F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_101A29F0(int a1)
{
  int v1; // esi

  v1 = *(_DWORD *)(a1 + 392);
  if ( *(_DWORD *)(v1 + 16) != 0 )
  {
    if ( *(_BYTE *)(a1 + 73) != 0 && sub_101A2240(a1) != 0 )
    {
      *(_DWORD *)(v1 + 12) = sub_101A23A0;
      *(_DWORD *)(a1 + 136) = 0;
      return;
    }
    *(_DWORD *)(v1 + 12) = sub_101A20B0;
  }
  *(_DWORD *)(a1 + 136) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A2A40
// Name: void jinit_d_coef_controller(struct jpeg_decompress_struct __near *,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jinit_d_coef_controller(struct jpeg_decompress_struct *a1, unsigned __int8 a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // ebp
  int *v5; // edi
  int v6; // ecx
  int v7; // ebx
  int v8; // eax
  bool v9; // cc
  int v10; // eax
  int v11; // [esp-Ch] [ebp-18h]
  int v12; // [esp-8h] [ebp-14h]
  struct jpeg_decompress_struct *v13; // [esp+10h] [ebp+4h]
  int v14; // [esp+14h] [ebp+8h]

  v3 = (_DWORD *)(**((int (__cdecl ***)(struct jpeg_decompress_struct *, int, int))a1 + 1))(a1, a2: 1, a3: 116);
  v4 = v3;
  *((_DWORD *)a1 + 98) = v3;
  *v3 = sub_101A1C60;
  v3[2] = sub_101A29F0;
  v3[28] = 0;
  if ( a2 != 0 )
  {
    v14 = 0;
    if ( *((int *)a1 + 9) > 0 )
    {
      v5 = (int *)(*((_DWORD *)a1 + 49) + 12);
      v13 = (struct jpeg_decompress_struct *)(v3 + 18);
      do
      {
        v6 = *v5;
        if ( *((_BYTE *)a1 + 200) != 0 )
          v6 *= 3;
        v7 = *((_DWORD *)a1 + 1);
        v12 = v6;
        v11 = jround_up(a1: v5[5], a2: *v5);
        v8 = jround_up(a1: v5[4], a2: *(v5 - 1));
        *(_DWORD *)v13 = (*(int (__cdecl **)(struct jpeg_decompress_struct *, int, int, int, int, int))(v7 + 20))(
                           a1,
                           a2: 1,
                           a3: 1,
                           a4: v8,
                           a5: v11,
                           a6: v12);
        v5 += 21;
        v9 = ++v14 < *((_DWORD *)a1 + 9);
        v13 = (struct jpeg_decompress_struct *)((char *)v13 + 4);
      }
      while ( v9 );
    }
    v4[1] = sub_101A1EC0;
    v4[3] = sub_101A20B0;
    v4[4] = v4 + 18;
  }
  else
  {
    v10 = (*(int (__cdecl **)(struct jpeg_decompress_struct *, int, int))(*((_DWORD *)a1 + 1) + 4))(a1, a2: 1, a3: 1280);
    v4[9] = v10 + 128;
    v4[10] = v10 + 256;
    v4[11] = v10 + 384;
    v4[12] = v10 + 512;
    v4[13] = v10 + 640;
    v4[14] = v10 + 768;
    v4[8] = v10;
    v4[15] = v10 + 896;
    v4[16] = v10 + 1024;
    v4[17] = v10 + 1152;
    v4[4] = 0;
    v4[1] = CDummyHardwareConfig::MaxTextureHeight;
    v4[3] = sub_101A1C80;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A2B90
// Name: void jpeg_make_d_derived_tbl(struct jpeg_decompress_struct __near *,unsigned char,int,struct d_derived_tbl __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_make_d_derived_tbl(
        struct jpeg_decompress_struct *a1,
        char a2,
        unsigned int a3,
        struct d_derived_tbl **a4)
{
  int v4; // ebp
  int v5; // edx
  int v6; // edi
  int i; // ebp
  unsigned int v8; // esi
  int v9; // edi
  int v10; // esi
  int v11; // ebp
  unsigned __int8 *v12; // eax
  int v13; // ecx
  int v14; // ecx
  int j; // eax
  int v16; // ebx
  char v17; // cl
  int v18; // edi
  int v19; // esi
  int v20; // eax
  _BYTE *v21; // ebp
  int v22; // edx
  _BYTE *v23; // esi
  int *v24; // edx
  int v25; // ebx
  int m; // edi
  int v27; // [esp+Ch] [ebp-528h]
  int v28; // [esp+10h] [ebp-524h]
  int k; // [esp+14h] [ebp-520h]
  int v30; // [esp+18h] [ebp-51Ch]
  _DWORD v31[258]; // [esp+24h] [ebp-510h]
  unsigned __int8 dst[260]; // [esp+42Ch] [ebp-108h] BYREF

  if ( a3 >= 4 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 50;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = a3;
    (**(void (__cdecl ***)(struct jpeg_decompress_struct *))a1)(a1);
  }
  if ( a2 != 0 )
  {
    v4 = *((_DWORD *)a1 + a3 + 40);
    v27 = v4;
  }
  else
  {
    v27 = *((_DWORD *)a1 + a3 + 44);
    v4 = v27;
  }
  if ( v4 == 0 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 50;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = a3;
    (**(void (__cdecl ***)(struct jpeg_decompress_struct *))a1)(a1);
  }
  if ( *a4 == nullptr )
    *a4 = (struct d_derived_tbl *)(**((int (__cdecl ***)(struct jpeg_decompress_struct *, int, int))a1 + 1))(
                                    a1,
                                    a2: 1,
                                    a3: 1424);
  v5 = (int)*a4;
  *(_DWORD *)(v5 + 140) = v4;
  v28 = v5;
  v6 = 0;
  for ( i = 1; i <= 16; ++i )
  {
    v8 = *(unsigned __int8 *)(v27 + i);
    if ( (int)(v8 + v6) > 256 )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 8;
      (**(void (__cdecl ***)(struct jpeg_decompress_struct *))a1)(a1);
      v5 = v28;
    }
    if ( v8 != 0 )
    {
      memset(dst: &dst[v6], value: i, count: v8);
      v5 = v28;
      v6 += v8;
    }
  }
  dst[v6] = 0;
  v31[0] = v6;
  v9 = 0;
  v10 = 0;
  v11 = (char)dst[0];
  if ( dst[0] != 0 )
  {
    v12 = dst;
    do
    {
      if ( (char)*v12 == v11 )
      {
        do
        {
          v13 = (char)dst[v10 + 1];
          v31[++v10] = v9++;
        }
        while ( v13 == v11 );
      }
      if ( v9 >= 1 << v11 )
      {
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 8;
        (**(void (__cdecl ***)(struct jpeg_decompress_struct *))a1)(a1);
        v5 = v28;
      }
      v12 = &dst[v10];
      v9 *= 2;
      ++v11;
    }
    while ( dst[v10] != 0 );
  }
  v14 = 0;
  for ( j = 1; j <= 16; ++j )
  {
    if ( *(_BYTE *)(j + v27) != 0 )
    {
      *(_DWORD *)(v5 + 4 * j + 72) = v14 - v31[v14 + 1];
      v14 += *(unsigned __int8 *)(j + v27);
      *(_DWORD *)(v5 + 4 * j) = v31[v14];
    }
    else
    {
      *(_DWORD *)(v5 + 4 * j) = -1;
    }
  }
  *(_DWORD *)(v5 + 68) = 0xFFFFF;
  memset(dst: (unsigned __int8 *)(v5 + 144), value: 0, count: 0x400u);
  v16 = 0;
  v17 = 7;
  v18 = 1;
  for ( k = 7; k >= 0; --k )
  {
    v19 = v27;
    v30 = 1;
    if ( *(_BYTE *)(v18 + v27) != 0 )
    {
      v20 = 1 << v17;
      v21 = (_BYTE *)(v16 + v27 + 17);
      do
      {
        v22 = v31[v16 + 1] << k;
        if ( v20 > 0 )
        {
          v23 = (_BYTE *)(v22 + v28 + 1168);
          v24 = (int *)(v28 + 4 * v22 + 144);
          do
          {
            *v24 = v18;
            *v23 = *v21;
            --v20;
            ++v24;
            ++v23;
          }
          while ( v20 > 0 );
          v19 = v27;
          v20 = 1 << v17;
        }
        ++v16;
        ++v21;
        ++v30;
      }
      while ( v30 <= *(unsigned __int8 *)(v18 + v19) );
    }
    ++v18;
    v17 = k - 1;
  }
  if ( a2 != 0 )
  {
    v25 = v31[0];
    for ( m = 0; m < v25; ++m )
    {
      if ( *(unsigned __int8 *)(v19 + m + 17) > 0xFu )
      {
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 8;
        (**(void (__cdecl ***)(struct jpeg_decompress_struct *))a1)(a1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A2E70
// Name: unsigned char jpeg_fill_bit_buffer(struct bitread_working_state __near *,long,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 __cdecl jpeg_fill_bit_buffer(struct bitread_working_state *a1, int a2, int a3, int a4)
{
  _DWORD *v4; // ebx
  unsigned __int8 *v5; // esi
  unsigned __int8 *v6; // edi
  unsigned __int8 **v7; // eax
  int v8; // eax
  unsigned __int8 **v9; // eax
  int v10; // eax
  bool v11; // cc
  char v13; // cl

  v4 = *((_DWORD **)a1 + 4);
  v5 = *(unsigned __int8 **)a1;
  v6 = *((unsigned __int8 **)a1 + 1);
  if ( v4[95] != 0 )
    goto LABEL_17;
  if ( a3 < 25 )
  {
    do
    {
      if ( v6 == nullptr )
      {
        if ( (*(unsigned __int8 (__cdecl **)(_DWORD *))(v4[6] + 12))(a1: v4) == 0 )
          return 0;
        v7 = (unsigned __int8 **)v4[6];
        v5 = *v7;
        v6 = v7[1];
      }
      v8 = *v5;
      --v6;
      ++v5;
      if ( v8 == 255 )
      {
        do
        {
          if ( v6 == nullptr )
          {
            if ( (*(unsigned __int8 (__cdecl **)(_DWORD *))(v4[6] + 12))(a1: v4) == 0 )
              return 0;
            v9 = (unsigned __int8 **)v4[6];
            v5 = *v9;
            v6 = v9[1];
          }
          v10 = *v5;
          --v6;
          ++v5;
        }
        while ( v10 == 255 );
        if ( v10 != 0 )
        {
          v4[95] = v10;
LABEL_17:
          if ( a4 > a3 )
          {
            if ( *(_BYTE *)(v4[102] + 8) == 0 )
            {
              *(_DWORD *)(*v4 + 20) = 117;
              (*(void (__cdecl **)(_DWORD *, int))(*v4 + 4))(a1: v4, a2: -1);
              *(_BYTE *)(v4[102] + 8) = 1;
            }
            v13 = 25 - a3;
            a3 = 25;
            a2 <<= v13;
          }
          break;
        }
        v8 = 255;
      }
      v11 = a3 + 8 < 25;
      a2 = v8 | (a2 << 8);
      a3 += 8;
    }
    while ( v11 );
  }
  *((_DWORD *)a1 + 1) = v6;
  *(_DWORD *)a1 = v5;
  *((_DWORD *)a1 + 3) = a3;
  *((_DWORD *)a1 + 2) = a2;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101A2FA0
// Name: int jpeg_huff_decode(struct bitread_working_state __near *,long,int,struct d_derived_tbl __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl jpeg_huff_decode(struct bitread_working_state *a1, int a2, int a3, struct d_derived_tbl *a4, int a5)
{
  int v5; // eax
  int v6; // ebx
  int v8; // edx
  int v9; // eax
  struct d_derived_tbl *v10; // ecx
  int v11; // esi
  int v12; // esi

  v5 = a3;
  v6 = a5;
  if ( a3 >= a5 )
  {
    v8 = a2;
  }
  else
  {
    if ( jpeg_fill_bit_buffer(a1, a2, a3, a4: a5) == 0 )
      return -1;
    v8 = *((_DWORD *)a1 + 2);
    v5 = *((_DWORD *)a1 + 3);
  }
  v9 = v5 - a5;
  v10 = a4;
  v11 = ((1 << a5) - 1) & (v8 >> v9);
  if ( v11 > *((_DWORD *)a4 + a5) )
  {
    do
    {
      v12 = 2 * v11;
      if ( v9 < 1 )
      {
        if ( jpeg_fill_bit_buffer(a1, a2: v8, a3: v9, a4: 1) == 0 )
          return -1;
        v8 = *((_DWORD *)a1 + 2);
        v9 = *((_DWORD *)a1 + 3);
      }
      --v9;
      v10 = a4;
      ++v6;
      v11 = (v8 >> v9) & 1 | v12;
    }
    while ( v11 > *((_DWORD *)a4 + v6) );
  }
  *((_DWORD *)a1 + 2) = v8;
  *((_DWORD *)a1 + 3) = v9;
  if ( v6 <= 16 )
    return *(unsigned __int8 *)(*((_DWORD *)v10 + 35) + *((_DWORD *)v10 + v6 + 18) + v11 + 17);
  *(_DWORD *)(**((_DWORD **)a1 + 4) + 20) = 118;
  (*(void (__cdecl **)(_DWORD, int))(**((_DWORD **)a1 + 4) + 4))(a1: *((_DWORD *)a1 + 4), a2: -1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A3090
// Name: sub_101A3090
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall sub_101A3090@<al>(_DWORD *a1@<esi>)
{
  int v1; // edi
  char result; // al
  int v3; // eax
  _DWORD *v4; // ecx

  v1 = a1[102];
  *(_DWORD *)(a1[101] + 20) += *(_DWORD *)(v1 + 16) / 8;
  *(_DWORD *)(v1 + 16) = 0;
  result = (*(int (**)(void))(a1[101] + 8))();
  if ( result != 0 )
  {
    v3 = 0;
    if ( (int)a1[73] > 0 )
    {
      v4 = (_DWORD *)(v1 + 20);
      do
      {
        *v4 = 0;
        ++v3;
        ++v4;
      }
      while ( v3 < a1[73] );
    }
    *(_DWORD *)(v1 + 36) = a1[63];
    if ( a1[95] == 0 )
      *(_BYTE *)(v1 + 8) = 0;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A3110
// Name: sub_101A3110
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl sub_101A3110(_DWORD *a1, int a2)
{
  _DWORD *v2; // esi
  int v3; // edi
  char result; // al
  bool v5; // cc
  int *v6; // eax
  int v7; // ecx
  int v8; // edx
  int v9; // ebx
  int v10; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // ecx
  int v14; // edx
  struct d_derived_tbl **v15; // ecx
  _WORD *v16; // esi
  struct d_derived_tbl *v17; // ebp
  struct d_derived_tbl *v18; // edi
  int v19; // ecx
  int v20; // edx
  int v21; // ecx
  int v22; // edi
  int v23; // edx
  int v24; // ecx
  int v25; // esi
  int v26; // ecx
  int v27; // edx
  int v28; // ecx
  int v29; // edi
  int v30; // ecx
  int v31; // edi
  int v32; // esi
  int v33; // edx
  int v34; // ecx
  int v35; // edx
  int v36; // ecx
  int v37; // edi
  int v38; // ecx
  int v39; // edi
  int v40; // esi
  int v41; // ecx
  int v42; // edx
  int v43; // eax
  int v44; // [esp+8h] [ebp-3Ch]
  struct d_derived_tbl *v45; // [esp+Ch] [ebp-38h]
  struct d_derived_tbl **v46; // [esp+10h] [ebp-34h]
  int *v47; // [esp+14h] [ebp-30h]
  int v48; // [esp+18h] [ebp-2Ch]
  _WORD *v49; // [esp+1Ch] [ebp-28h]
  int v50; // [esp+20h] [ebp-24h]
  int v51; // [esp+24h] [ebp-20h]
  int v52; // [esp+28h] [ebp-1Ch]
  int v53; // [esp+2Ch] [ebp-18h]
  int v54; // [esp+30h] [ebp-14h] BYREF
  int v55; // [esp+34h] [ebp-10h]
  int v56; // [esp+38h] [ebp-Ch]
  int v57; // [esp+3Ch] [ebp-8h]
  _DWORD *v58; // [esp+40h] [ebp-4h]

  v2 = a1;
  v3 = a1[102];
  v48 = v3;
  if ( a1[63] != 0 && *(_DWORD *)(v3 + 36) == 0 )
  {
    result = sub_101A3090(a1);
    if ( result == 0 )
      return result;
  }
  if ( *(_BYTE *)(v3 + 8) != 0 )
    goto LABEL_68;
  v5 = a1[80] <= 0;
  v6 = (int *)a1[6];
  v7 = *v6;
  v8 = v6[1];
  v9 = *(_DWORD *)(v3 + 12);
  v10 = *(_DWORD *)(v3 + 16);
  v54 = v7;
  v11 = *(_DWORD *)(v3 + 20);
  v55 = v8;
  v12 = *(_DWORD *)(v3 + 24);
  v50 = v11;
  v13 = *(_DWORD *)(v3 + 28);
  v51 = v12;
  v14 = *(_DWORD *)(v3 + 32);
  v58 = a1;
  v52 = v13;
  v53 = v14;
  v44 = 0;
  if ( v5 )
    goto LABEL_67;
  v15 = (struct d_derived_tbl **)(v3 + 112);
  v47 = a1 + 81;
  v46 = (struct d_derived_tbl **)(v3 + 112);
  while ( 2 )
  {
    v16 = *(_WORD **)(a2 + 4 * v44);
    v17 = *v15;
    v18 = *(v15 - 10);
    v49 = v16;
    v45 = *v15;
    if ( v10 >= 8 )
      goto LABEL_12;
    if ( jpeg_fill_bit_buffer(a1: (struct bitread_working_state *)&v54, a2: v9, a3: v10, a4: 0) == 0 )
      return 0;
    v10 = v57;
    v9 = v56;
    if ( v57 >= 8 )
    {
LABEL_12:
      v20 = (unsigned __int8)(v9 >> (v10 - 8));
      v21 = *((_DWORD *)v18 + v20 + 36);
      if ( v21 != 0 )
      {
        v22 = *((unsigned __int8 *)v18 + v20 + 1168);
        v10 -= v21;
        goto LABEL_17;
      }
      v19 = 9;
    }
    else
    {
      v19 = 1;
    }
    v22 = jpeg_huff_decode(a1: (struct bitread_working_state *)&v54, a2: v9, a3: v10, a4: v18, a5: v19);
    if ( v22 < 0 )
      return 0;
    v9 = v56;
    v10 = v57;
LABEL_17:
    if ( v22 != 0 )
    {
      if ( v10 < v22 )
      {
        if ( jpeg_fill_bit_buffer(a1: (struct bitread_working_state *)&v54, a2: v9, a3: v10, a4: v22) == 0 )
          return 0;
        v9 = v56;
        v10 = v57;
      }
      v10 -= v22;
      v23 = (v9 >> v10) & ((1 << v22) - 1);
      v17 = v45;
      if ( v23 >= dword_102ACA98[v22] )
        v22 = (v9 >> v10) & ((1 << v22) - 1);
      else
        v22 = v23 + dword_102ACAD8[v22];
    }
    if ( *(_BYTE *)(v44 + v48 + 152) != 0 )
    {
      v24 = *v47;
      *(&v50 + v24) += v22;
      *v16 = *(&v50 + v24);
    }
    v25 = 1;
    if ( *(_BYTE *)(v44 + v48 + 162) != 0 )
    {
      while ( 1 )
      {
        if ( v10 < 8 )
        {
          if ( jpeg_fill_bit_buffer(a1: (struct bitread_working_state *)&v54, a2: v9, a3: v10, a4: 0) == 0 )
            return 0;
          v10 = v57;
          v9 = v56;
          if ( v57 < 8 )
            break;
        }
        v27 = (unsigned __int8)(v9 >> (v10 - 8));
        v28 = *((_DWORD *)v17 + v27 + 36);
        if ( v28 == 0 )
        {
          v26 = 9;
          goto LABEL_34;
        }
        v29 = *((unsigned __int8 *)v17 + v27 + 1168);
        v10 -= v28;
LABEL_36:
        v30 = v29 >> 4;
        v31 = v29 & 0xF;
        if ( v31 != 0 )
        {
          v32 = v30 + v25;
          if ( v10 < v31 )
          {
            if ( jpeg_fill_bit_buffer(a1: (struct bitread_working_state *)&v54, a2: v9, a3: v10, a4: v31) == 0 )
              return 0;
            v9 = v56;
            v10 = v57;
          }
          v10 -= v31;
          v33 = (v9 >> v10) & ((1 << v31) - 1);
          if ( v33 >= dword_102ACA98[v31] )
            v31 = (v9 >> v10) & ((1 << v31) - 1);
          else
            LOWORD(v31) = v33 + dword_102ACAD8[v31];
          v17 = v45;
          v49[(int)(&jpeg_natural_order)[v32]] = v31;
        }
        else
        {
          if ( v30 != 15 )
            goto LABEL_65;
          v32 = v25 + 15;
        }
        v25 = v32 + 1;
        if ( v25 >= 64 )
          goto LABEL_65;
      }
      v26 = 1;
LABEL_34:
      v29 = jpeg_huff_decode(a1: (struct bitread_working_state *)&v54, a2: v9, a3: v10, a4: v17, a5: v26);
      if ( v29 < 0 )
        return 0;
      v9 = v56;
      v10 = v57;
      goto LABEL_36;
    }
    do
    {
      if ( v10 >= 8 )
        goto LABEL_52;
      if ( jpeg_fill_bit_buffer(a1: (struct bitread_working_state *)&v54, a2: v9, a3: v10, a4: 0) == 0 )
        return 0;
      v10 = v57;
      v9 = v56;
      if ( v57 >= 8 )
      {
LABEL_52:
        v35 = (unsigned __int8)(v9 >> (v10 - 8));
        v36 = *((_DWORD *)v17 + v35 + 36);
        if ( v36 != 0 )
        {
          v37 = *((unsigned __int8 *)v17 + v35 + 1168);
          v10 -= v36;
          goto LABEL_57;
        }
        v34 = 9;
      }
      else
      {
        v34 = 1;
      }
      v37 = jpeg_huff_decode(a1: (struct bitread_working_state *)&v54, a2: v9, a3: v10, a4: v17, a5: v34);
      if ( v37 < 0 )
        return 0;
      v9 = v56;
      v10 = v57;
LABEL_57:
      v38 = v37 >> 4;
      v39 = v37 & 0xF;
      if ( v39 != 0 )
      {
        v40 = v38 + v25;
        if ( v10 < v39 )
        {
          if ( jpeg_fill_bit_buffer(a1: (struct bitread_working_state *)&v54, a2: v9, a3: v10, a4: v39) == 0 )
            return 0;
          v9 = v56;
          v10 = v57;
        }
        v10 -= v39;
      }
      else
      {
        if ( v38 != 15 )
          break;
        v40 = v25 + 15;
      }
      v25 = v40 + 1;
    }
    while ( v25 < 64 );
LABEL_65:
    ++v46;
    ++v47;
    if ( ++v44 < a1[80] )
    {
      v15 = v46;
      continue;
    }
    break;
  }
  v3 = v48;
  v2 = a1;
LABEL_67:
  *(_DWORD *)v2[6] = v54;
  *(_DWORD *)(v2[6] + 4) = v55;
  v41 = v51;
  v42 = v52;
  *(_DWORD *)(v3 + 16) = v10;
  *(_DWORD *)(v3 + 20) = v50;
  v43 = v53;
  *(_DWORD *)(v3 + 24) = v41;
  *(_DWORD *)(v3 + 28) = v42;
  *(_DWORD *)(v3 + 12) = v9;
  *(_DWORD *)(v3 + 32) = v43;
LABEL_68:
  --*(_DWORD *)(v3 + 36);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101A3530
// Name: sub_101A3530
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A3530(struct jpeg_decompress_struct *a1)
{
  int v2; // edi
  char *v3; // ebx
  unsigned int v4; // ebp
  bool v5; // cc
  _BYTE *v6; // ecx
  _DWORD *v7; // edx
  _DWORD *v8; // ebp
  int v9; // eax
  _DWORD *v11; // [esp+10h] [ebp-4h]
  struct jpeg_decompress_struct *v12; // [esp+18h] [ebp+4h]

  v2 = *((_DWORD *)a1 + 102);
  if ( *((_DWORD *)a1 + 91) != 0 || *((_DWORD *)a1 + 92) != 63 || *((_DWORD *)a1 + 93) != 0 || *((_DWORD *)a1 + 94) != 0 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 122;
    (*(void (__cdecl **)(struct jpeg_decompress_struct *, int))(*(_DWORD *)a1 + 4))(a1, a2: -1);
  }
  v12 = nullptr;
  if ( *((int *)a1 + 73) > 0 )
  {
    v11 = (_DWORD *)(v2 + 20);
    v3 = (char *)a1 + 296;
    do
    {
      v4 = *(_DWORD *)(*(_DWORD *)v3 + 24);
      jpeg_make_d_derived_tbl(
        a1,
        a2: 1,
        a3: *(_DWORD *)(*(_DWORD *)v3 + 20),
        a4: (struct d_derived_tbl **)(v2 + 4 * *(_DWORD *)(*(_DWORD *)v3 + 20) + 40));
      jpeg_make_d_derived_tbl(a1, a2: 0, a3: v4, a4: (struct d_derived_tbl **)(v2 + 4 * v4 + 56));
      *v11 = 0;
      v3 += 4;
      v5 = (int)v12 + 1 < *((_DWORD *)a1 + 73);
      v12 = (struct jpeg_decompress_struct *)((char *)v12 + 1);
      ++v11;
    }
    while ( v5 );
  }
  if ( *((int *)a1 + 80) > 0 )
  {
    v6 = (_BYTE *)(v2 + 152);
    v7 = (_DWORD *)(v2 + 112);
    v8 = (_DWORD *)((char *)a1 + 324);
    do
    {
      v9 = *((_DWORD *)a1 + *v8 + 74);
      *(v7 - 10) = *(_DWORD *)(v2 + 4 * *(_DWORD *)(v9 + 20) + 40);
      *v7 = *(_DWORD *)(v2 + 4 * *(_DWORD *)(v9 + 24) + 56);
      if ( *(_BYTE *)(v9 + 48) != 0 )
      {
        *v6 = 1;
        v6[10] = *(_DWORD *)(v9 + 36) > 1;
      }
      else
      {
        v6[10] = 0;
        *v6 = 0;
      }
      ++v6;
      ++v8;
      ++v7;
    }
    while ( (int)&v6[-152 - v2] < *((_DWORD *)a1 + 80) );
  }
  *(_DWORD *)(v2 + 16) = 0;
  *(_DWORD *)(v2 + 12) = 0;
  *(_BYTE *)(v2 + 8) = 0;
  *(_DWORD *)(v2 + 36) = *((_DWORD *)a1 + 63);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A3680
// Name: void jinit_huff_decoder(struct jpeg_decompress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jinit_huff_decoder(int (__cdecl ***a1)(struct jpeg_decompress_struct *, int, int))
{
  int (__cdecl **v1)(struct jpeg_decompress_struct *, int, int); // eax

  v1 = (int (__cdecl **)(struct jpeg_decompress_struct *, int, int))(*a1[1])(
                                                                      (struct jpeg_decompress_struct *)a1,
                                                                      a2: 1,
                                                                      a3: 172);
  a1[102] = v1;
  *v1 = (int (__cdecl *)(struct jpeg_decompress_struct *, int, int))sub_101A3530;
  v1[1] = (int (__cdecl *)(struct jpeg_decompress_struct *, int, int))sub_101A3110;
  v1[14] = nullptr;
  v1[10] = nullptr;
  v1[15] = nullptr;
  v1[11] = nullptr;
  v1[16] = nullptr;
  v1[12] = nullptr;
  v1[17] = nullptr;
  v1[13] = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101A36D0
// Name: sub_101A36D0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall sub_101A36D0@<al>(_DWORD *a1@<esi>)
{
  int v1; // edi
  char result; // al
  int v3; // eax
  _DWORD *v4; // ecx

  v1 = a1[102];
  *(_DWORD *)(a1[101] + 20) += *(_DWORD *)(v1 + 16) / 8;
  *(_DWORD *)(v1 + 16) = 0;
  result = (*(int (**)(void))(a1[101] + 8))();
  if ( result != 0 )
  {
    v3 = 0;
    if ( (int)a1[73] > 0 )
    {
      v4 = (_DWORD *)(v1 + 24);
      do
      {
        *v4 = 0;
        ++v3;
        ++v4;
      }
      while ( v3 < a1[73] );
    }
    *(_DWORD *)(v1 + 20) = 0;
    *(_DWORD *)(v1 + 40) = a1[63];
    if ( a1[95] == 0 )
      *(_BYTE *)(v1 + 8) = 0;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A3760
// Name: sub_101A3760
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl sub_101A3760(_DWORD *a1, int a2)
{
  int v3; // edi
  char result; // al
  bool v5; // cc
  int *v6; // eax
  int v7; // edx
  int v8; // ebp
  int v9; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // ecx
  struct d_derived_tbl *v13; // ebx
  int v14; // ecx
  int v15; // edx
  int v16; // ecx
  int v17; // ebx
  int v18; // edx
  int v19; // ecx
  int v20; // edx
  int v21; // eax
  int v22; // [esp+8h] [ebp-3Ch]
  int *v23; // [esp+Ch] [ebp-38h]
  int v24; // [esp+10h] [ebp-34h]
  int v25; // [esp+14h] [ebp-30h]
  _WORD *v26; // [esp+18h] [ebp-2Ch]
  int v27; // [esp+1Ch] [ebp-28h] BYREF
  int v28; // [esp+20h] [ebp-24h]
  int v29; // [esp+24h] [ebp-20h]
  int v30; // [esp+28h] [ebp-1Ch]
  _DWORD *v31; // [esp+2Ch] [ebp-18h]
  int v32; // [esp+30h] [ebp-14h]
  int v33; // [esp+34h] [ebp-10h]
  int v34; // [esp+38h] [ebp-Ch]
  int v35; // [esp+3Ch] [ebp-8h]
  int v36; // [esp+40h] [ebp-4h]
  int v37; // [esp+48h] [ebp+4h]

  v3 = a1[102];
  v25 = a1[94];
  if ( a1[63] == 0 || *(_DWORD *)(v3 + 40) != 0 || (result = sub_101A36D0(a1)) != 0 )
  {
    if ( *(_BYTE *)(v3 + 8) == 0 )
    {
      v5 = a1[80] <= 0;
      v6 = (int *)a1[6];
      v31 = a1;
      v27 = *v6;
      v28 = v6[1];
      v7 = *(_DWORD *)(v3 + 24);
      v8 = *(_DWORD *)(v3 + 12);
      v9 = *(_DWORD *)(v3 + 16);
      v32 = *(_DWORD *)(v3 + 20);
      v10 = *(_DWORD *)(v3 + 28);
      v33 = v7;
      v11 = *(_DWORD *)(v3 + 32);
      v34 = v10;
      v12 = *(_DWORD *)(v3 + 36);
      v37 = v8;
      v35 = v11;
      v36 = v12;
      v22 = 0;
      if ( !v5 )
      {
        v23 = a1 + 81;
        do
        {
          v26 = *(_WORD **)(a2 + 4 * v22);
          v24 = *v23;
          v13 = *(struct d_derived_tbl **)(v3 + 4 * *(_DWORD *)(a1[*v23 + 74] + 20) + 44);
          if ( v9 >= 8 )
            goto LABEL_11;
          if ( jpeg_fill_bit_buffer(a1: (struct bitread_working_state *)&v27, a2: v8, a3: v9, a4: 0) == 0 )
            return 0;
          v9 = v30;
          v8 = v29;
          v37 = v29;
          if ( v30 >= 8 )
          {
LABEL_11:
            v15 = (unsigned __int8)(v8 >> (v9 - 8));
            v16 = *((_DWORD *)v13 + v15 + 36);
            if ( v16 != 0 )
            {
              v17 = *((unsigned __int8 *)v13 + v15 + 1168);
              v9 -= v16;
              goto LABEL_16;
            }
            v14 = 9;
          }
          else
          {
            v14 = 1;
          }
          v17 = jpeg_huff_decode(a1: (struct bitread_working_state *)&v27, a2: v8, a3: v9, a4: v13, a5: v14);
          if ( v17 < 0 )
            return 0;
          v8 = v29;
          v9 = v30;
          v37 = v29;
LABEL_16:
          if ( v17 != 0 )
          {
            if ( v9 < v17 )
            {
              if ( jpeg_fill_bit_buffer(a1: (struct bitread_working_state *)&v27, a2: v8, a3: v9, a4: v17) == 0 )
                return 0;
              v8 = v29;
              v9 = v30;
              v37 = v29;
            }
            v9 -= v17;
            v18 = (v8 >> v9) & ((1 << v17) - 1);
            v8 = v37;
            if ( v18 >= dword_102ACB18[v17] )
              v17 = v18;
            else
              v17 = v18 + dword_102ACB58[v17];
          }
          *(&v33 + v24) += v17;
          ++v23;
          *v26 = *(&v33 + v24) << v25;
          ++v22;
        }
        while ( v22 < a1[80] );
      }
      *(_DWORD *)a1[6] = v27;
      *(_DWORD *)(a1[6] + 4) = v28;
      v19 = v34;
      *(_DWORD *)(v3 + 20) = v32;
      v20 = v35;
      *(_DWORD *)(v3 + 16) = v9;
      *(_DWORD *)(v3 + 24) = v33;
      v21 = v36;
      *(_DWORD *)(v3 + 28) = v19;
      *(_DWORD *)(v3 + 32) = v20;
      *(_DWORD *)(v3 + 12) = v8;
      *(_DWORD *)(v3 + 36) = v21;
    }
    --*(_DWORD *)(v3 + 40);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A39A0
// Name: sub_101A39A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl sub_101A39A0(_DWORD *a1, int *a2)
{
  _DWORD *v2; // edi
  int v3; // ebx
  char result; // al
  int v5; // ecx
  int *v6; // eax
  int v7; // ebp
  int v8; // edx
  int v9; // esi
  int v10; // eax
  struct d_derived_tbl *v11; // edi
  int v12; // ecx
  int v13; // edx
  int v14; // ecx
  int v15; // edi
  int v16; // ebx
  int v17; // edi
  int v18; // ebp
  int v19; // edx
  int v20; // edi
  int v21; // ebp
  int v22; // [esp+Ch] [ebp-2Ch]
  struct d_derived_tbl *v23; // [esp+10h] [ebp-28h]
  int v24; // [esp+14h] [ebp-24h]
  int v25; // [esp+18h] [ebp-20h]
  int v26; // [esp+1Ch] [ebp-1Ch]
  int v27; // [esp+20h] [ebp-18h]
  int v28; // [esp+24h] [ebp-14h] BYREF
  int v29; // [esp+28h] [ebp-10h]
  int v30; // [esp+2Ch] [ebp-Ch]
  int v31; // [esp+30h] [ebp-8h]
  _DWORD *v32; // [esp+34h] [ebp-4h]

  v2 = a1;
  v3 = a1[102];
  v25 = v3;
  v24 = a1[92];
  v26 = a1[94];
  if ( a1[63] != 0 && *(_DWORD *)(v3 + 40) == 0 )
  {
    result = sub_101A36D0(a1);
    if ( result == 0 )
      return result;
  }
  if ( *(_BYTE *)(v3 + 8) != 0 )
    goto LABEL_38;
  v5 = *(_DWORD *)(v3 + 20);
  v22 = v5;
  if ( v5 != 0 )
  {
    --*(_DWORD *)(v3 + 40);
    *(_DWORD *)(v3 + 20) = v5 - 1;
    return 1;
  }
  v6 = (int *)a1[6];
  v7 = a1[91];
  v32 = a1;
  v28 = *v6;
  v8 = *a2;
  v29 = v6[1];
  v9 = *(_DWORD *)(v3 + 12);
  v10 = *(_DWORD *)(v3 + 16);
  v27 = v8;
  v23 = *(struct d_derived_tbl **)(v3 + 60);
  if ( v7 > v24 )
    goto LABEL_37;
  while ( 1 )
  {
    if ( v10 >= 8 )
      goto LABEL_12;
    if ( jpeg_fill_bit_buffer(a1: (struct bitread_working_state *)&v28, a2: v9, a3: v10, a4: 0) == 0 )
      return 0;
    v10 = v31;
    v9 = v30;
    if ( v31 >= 8 )
    {
LABEL_12:
      v11 = v23;
      v13 = (unsigned __int8)(v9 >> (v10 - 8));
      v14 = *((_DWORD *)v23 + v13 + 36);
      if ( v14 != 0 )
      {
        v15 = *((unsigned __int8 *)v23 + v13 + 1168);
        v10 -= v14;
        goto LABEL_17;
      }
      v12 = 9;
    }
    else
    {
      v11 = v23;
      v12 = 1;
    }
    v15 = jpeg_huff_decode(a1: (struct bitread_working_state *)&v28, a2: v9, a3: v10, a4: v11, a5: v12);
    if ( v15 < 0 )
      return 0;
    v9 = v30;
    v10 = v31;
LABEL_17:
    v16 = v15 >> 4;
    v17 = v15 & 0xF;
    if ( v17 != 0 )
    {
      v18 = v16 + v7;
      if ( v10 < v17 )
      {
        if ( jpeg_fill_bit_buffer(a1: (struct bitread_working_state *)&v28, a2: v9, a3: v10, a4: v17) == 0 )
          return 0;
        v9 = v30;
        v10 = v31;
      }
      v10 -= v17;
      v19 = (v9 >> v10) & ((1 << v17) - 1);
      if ( v19 >= dword_102ACB18[v17] )
        v20 = (v9 >> v10) & ((1 << v17) - 1);
      else
        v20 = v19 + dword_102ACB58[v17];
      *(_WORD *)(v27 + 2 * (int)(&jpeg_natural_order)[v18]) = v20 << v26;
      goto LABEL_27;
    }
    if ( v16 != 15 )
      break;
    v18 = v7 + 15;
LABEL_27:
    v7 = v18 + 1;
    if ( v7 > v24 )
      goto LABEL_36;
  }
  v21 = 1 << v16;
  if ( v16 != 0 )
  {
    if ( v10 < v16 )
    {
      if ( jpeg_fill_bit_buffer(a1: (struct bitread_working_state *)&v28, a2: v9, a3: v10, a4: v16) == 0 )
        return 0;
      v9 = v30;
      v10 = v31;
    }
    v10 -= v16;
    v21 += ((1 << v16) - 1) & (v9 >> v10);
  }
  v22 = v21 - 1;
LABEL_36:
  v5 = v22;
  v2 = a1;
  v3 = v25;
LABEL_37:
  *(_DWORD *)v2[6] = v28;
  *(_DWORD *)(v2[6] + 4) = v29;
  *(_DWORD *)(v3 + 12) = v9;
  *(_DWORD *)(v3 + 16) = v10;
  *(_DWORD *)(v3 + 20) = v5;
LABEL_38:
  --*(_DWORD *)(v3 + 40);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101A3BF0
// Name: sub_101A3BF0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl sub_101A3BF0(_DWORD *a1, int a2)
{
  _DWORD *v3; // edi
  char result; // al
  int *v5; // eax
  int v6; // ebx
  bool v7; // cc
  int v8; // ecx
  int v9; // ebp
  _WORD *v10; // eax
  int v11; // [esp+8h] [ebp-18h]
  int v12; // [esp+Ch] [ebp-14h] BYREF
  int v13; // [esp+10h] [ebp-10h]
  int v14; // [esp+14h] [ebp-Ch]
  int v15; // [esp+18h] [ebp-8h]
  _DWORD *v16; // [esp+1Ch] [ebp-4h]
  _WORD *v17; // [esp+24h] [ebp+4h]

  v3 = (_DWORD *)a1[102];
  v11 = 1 << a1[94];
  if ( a1[63] == 0 || v3[10] != 0 || (result = sub_101A36D0(a1)) != 0 )
  {
    v5 = (int *)a1[6];
    v16 = a1;
    v12 = *v5;
    v6 = 0;
    v7 = a1[80] <= 0;
    v13 = v5[1];
    v8 = v3[4];
    v9 = v3[3];
    if ( v7 )
    {
LABEL_11:
      *(_DWORD *)a1[6] = v12;
      *(_DWORD *)(a1[6] + 4) = v13;
      --v3[10];
      v3[3] = v9;
      v3[4] = v8;
      return 1;
    }
    while ( 1 )
    {
      v10 = *(_WORD **)(a2 + 4 * v6);
      v17 = v10;
      if ( v8 < 1 )
      {
        if ( jpeg_fill_bit_buffer(a1: (struct bitread_working_state *)&v12, a2: v9, a3: v8, a4: 1) == 0 )
          return 0;
        v9 = v14;
        v8 = v15;
        v10 = v17;
      }
      if ( ((v9 >> --v8) & 1) != 0 )
        *v10 |= v11;
      if ( ++v6 >= a1[80] )
        goto LABEL_11;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A3CE0
// Name: sub_101A3CE0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl sub_101A3CE0(_DWORD *a1, int *a2)
{
  _DWORD *v2; // ebp
  int v3; // ecx
  int v4; // ebx
  bool v5; // zf
  char result; // al
  int *v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // esi
  int v11; // edi
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  int v15; // ecx
  int v16; // ebp
  int v17; // ecx
  int v18; // ebp
  int v19; // ebx
  int v20; // eax
  __int16 *v21; // ebx
  __int16 v22; // ax
  __int16 v23; // cx
  int v24; // edx
  __int16 *v25; // ebx
  __int16 v26; // ax
  __int16 v27; // ax
  struct d_derived_tbl *v28; // eax
  int v29; // ecx
  int i; // eax
  struct d_derived_tbl *v31; // edx
  int v32; // [esp+Ch] [ebp-13Ch]
  int v33; // [esp+10h] [ebp-138h]
  int v34; // [esp+14h] [ebp-134h]
  int v35; // [esp+18h] [ebp-130h]
  int v36; // [esp+1Ch] [ebp-12Ch]
  int v37; // [esp+20h] [ebp-128h]
  int v38; // [esp+24h] [ebp-124h] BYREF
  int v39; // [esp+28h] [ebp-120h]
  int v40; // [esp+2Ch] [ebp-11Ch]
  int v41; // [esp+30h] [ebp-118h]
  _DWORD *v42; // [esp+34h] [ebp-114h]
  int v43; // [esp+38h] [ebp-110h]
  int v44; // [esp+3Ch] [ebp-10Ch]
  int v45; // [esp+40h] [ebp-108h]
  struct d_derived_tbl *v46[65]; // [esp+44h] [ebp-104h]

  v2 = a1;
  v3 = a1[94];
  v4 = a1[102];
  v35 = a1[92];
  v37 = v4;
  v45 = 1 << v3;
  v5 = a1[63] == 0;
  v44 = -1 << v3;
  if ( !v5 && *(_DWORD *)(v4 + 40) == 0 )
  {
    result = sub_101A36D0(a1);
    if ( result == 0 )
      return result;
  }
  if ( *(_BYTE *)(v4 + 8) != 0 )
  {
LABEL_47:
    --*(_DWORD *)(v4 + 40);
    return 1;
  }
  v7 = (int *)a1[6];
  v42 = a1;
  v38 = *v7;
  v39 = v7[1];
  v8 = *a2;
  v9 = *(_DWORD *)(v4 + 20);
  v10 = *(_DWORD *)(v4 + 12);
  v11 = *(_DWORD *)(v4 + 16);
  v46[0] = *(struct d_derived_tbl **)(v4 + 60);
  v12 = a1[91];
  v32 = v9;
  v36 = v8;
  v43 = 0;
  v33 = v12;
  if ( v9 != 0 )
  {
LABEL_32:
    if ( v32 != 0 )
    {
      v20 = v33;
      if ( v33 <= v35 )
      {
        do
        {
          v21 = (__int16 *)(v36 + 2 * (int)(&jpeg_natural_order)[v20]);
          if ( *v21 != 0 )
          {
            if ( v11 < 1 )
            {
              if ( jpeg_fill_bit_buffer(a1: (struct bitread_working_state *)&v38, a2: v10, a3: v11, a4: 1) == 0 )
                goto LABEL_65;
              v10 = v40;
              v11 = v41;
            }
            if ( ((v10 >> --v11) & 1) != 0 )
            {
              v22 = *v21;
              v23 = v45;
              if ( (*v21 & v45) == 0 )
              {
                if ( v22 < 0 )
                  v23 = v44;
                *v21 = v23 + v22;
              }
            }
          }
          v20 = ++v33;
        }
        while ( v33 <= v35 );
        v4 = v37;
      }
      --v32;
    }
LABEL_46:
    *(_DWORD *)v2[6] = v38;
    *(_DWORD *)(v2[6] + 4) = v39;
    *(_DWORD *)(v4 + 12) = v10;
    *(_DWORD *)(v4 + 16) = v11;
    *(_DWORD *)(v4 + 20) = v32;
    goto LABEL_47;
  }
  if ( v12 > v35 )
    goto LABEL_46;
  while ( 1 )
  {
    if ( v11 >= 8 )
      goto LABEL_11;
    if ( jpeg_fill_bit_buffer(a1: (struct bitread_working_state *)&v38, a2: v10, a3: v11, a4: 0) == 0 )
      goto LABEL_65;
    v11 = v41;
    v10 = v40;
    if ( v41 >= 8 )
    {
LABEL_11:
      v14 = (unsigned __int8)(v10 >> (v11 - 8));
      v15 = *((_DWORD *)v46[0] + v14 + 36);
      if ( v15 != 0 )
      {
        v16 = *((unsigned __int8 *)v46[0] + v14 + 1168);
        v11 -= v15;
        goto LABEL_16;
      }
      v13 = 9;
    }
    else
    {
      v13 = 1;
    }
    v16 = jpeg_huff_decode(a1: (struct bitread_working_state *)&v38, a2: v10, a3: v11, a4: v46[0], a5: v13);
    if ( v16 < 0 )
      goto LABEL_65;
    v10 = v40;
    v11 = v41;
LABEL_16:
    v17 = v16 >> 4;
    v18 = v16 & 0xF;
    v34 = v17;
    if ( v18 == 0 )
      break;
    if ( v18 != 1 )
    {
      *(_DWORD *)(*a1 + 20) = 118;
      (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, a2: -1);
    }
    if ( v11 < 1 )
    {
      if ( jpeg_fill_bit_buffer(a1: (struct bitread_working_state *)&v38, a2: v10, a3: v11, a4: 1) == 0 )
        goto LABEL_65;
      v10 = v40;
      v11 = v41;
    }
    --v11;
    v17 = v34;
    if ( ((v10 >> v11) & 1) != 0 )
      v18 = v45;
    else
      v18 = v44;
    while ( 1 )
    {
LABEL_49:
      v24 = v33;
      v25 = (__int16 *)(v36 + 2 * (int)(&jpeg_natural_order)[v33]);
      if ( *v25 != 0 )
      {
        if ( v11 < 1 )
        {
          if ( jpeg_fill_bit_buffer(a1: (struct bitread_working_state *)&v38, a2: v10, a3: v11, a4: 1) == 0 )
            goto LABEL_65;
          v10 = v40;
          v11 = v41;
        }
        if ( ((v10 >> --v11) & 1) != 0 )
        {
          v26 = *v25;
          if ( (*v25 & v45) == 0 )
          {
            if ( v26 < 0 )
              v27 = v44 + v26;
            else
              v27 = v45 + v26;
            *v25 = v27;
          }
        }
      }
      else
      {
        v34 = v17 - 1;
        if ( v17 - 1 < 0 )
          break;
      }
      v24 = ++v33;
      if ( v33 > v35 )
        break;
      v17 = v34;
    }
    if ( v18 != 0 )
    {
      v28 = (struct d_derived_tbl *)(&jpeg_natural_order)[v24];
      *(_WORD *)(v36 + 2 * (_DWORD)v28) = v18;
      v29 = v43;
      v46[v43 + 1] = v28;
      v43 = v29 + 1;
    }
    v33 = v24 + 1;
    if ( v24 + 1 > v35 )
    {
      v2 = a1;
      v4 = v37;
      goto LABEL_46;
    }
  }
  if ( v17 == 15 )
    goto LABEL_49;
  v19 = 1 << v17;
  v32 = 1 << v17;
  if ( v17 == 0 )
    goto LABEL_31;
  if ( v11 >= v17 )
    goto LABEL_30;
  if ( jpeg_fill_bit_buffer(a1: (struct bitread_working_state *)&v38, a2: v10, a3: v11, a4: v17) != 0 )
  {
    v10 = v40;
    v11 = v41;
LABEL_30:
    v11 -= v34;
    v32 += (v19 - 1) & (v10 >> v11);
LABEL_31:
    v4 = v37;
    v2 = a1;
    goto LABEL_32;
  }
LABEL_65:
  for ( i = v43; i > 0; *(_WORD *)(v36 + 2 * (_DWORD)v31) = 0 )
    v31 = v46[i--];
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A40E0
// Name: sub_101A40E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A40E0(struct jpeg_decompress_struct *a1)
{
  int v2; // eax
  bool v3; // bl
  int v4; // edi
  char v5; // cl
  bool v6; // zf
  int v7; // edx
  int result; // eax
  int v9; // ebx
  int *v10; // ebp
  int i; // edi
  _DWORD *v12; // ebp
  int *v13; // ebx
  int v14; // eax
  unsigned int v15; // eax
  struct d_derived_tbl **v16; // edi
  int v17; // [esp+10h] [ebp-Ch]
  int v18; // [esp+10h] [ebp-Ch]
  char *v19; // [esp+14h] [ebp-8h]
  int v20; // [esp+18h] [ebp-4h]
  bool v21; // [esp+20h] [ebp+4h]

  v2 = *((_DWORD *)a1 + 91);
  v3 = v2 == 0;
  v4 = *((_DWORD *)a1 + 102);
  v5 = 0;
  v20 = v4;
  v21 = v2 == 0;
  if ( v2 != 0 )
  {
    v7 = *((_DWORD *)a1 + 92);
    if ( v2 > v7 || v7 >= 64 )
      v5 = 1;
    v6 = *((_DWORD *)a1 + 73) == 1;
  }
  else
  {
    v6 = *((_DWORD *)a1 + 92) == 0;
  }
  if ( !v6 )
    v5 = 1;
  result = *((_DWORD *)a1 + 93);
  if ( result != 0 && *((_DWORD *)a1 + 94) != --result )
    v5 = 1;
  if ( *((int *)a1 + 94) > 13 || v5 != 0 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 16;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = *((_DWORD *)a1 + 91);
    *(_DWORD *)(*(_DWORD *)a1 + 28) = *((_DWORD *)a1 + 92);
    *(_DWORD *)(*(_DWORD *)a1 + 32) = *((_DWORD *)a1 + 93);
    *(_DWORD *)(*(_DWORD *)a1 + 36) = *((_DWORD *)a1 + 94);
    result = (**(int (__cdecl ***)(struct jpeg_decompress_struct *))a1)(a1);
  }
  v17 = 0;
  if ( *((int *)a1 + 73) > 0 )
  {
    v19 = (char *)a1 + 296;
    do
    {
      v9 = *(_DWORD *)(*(_DWORD *)v19 + 4);
      v10 = (int *)(*((_DWORD *)a1 + 35) + (v9 << 8));
      if ( !v21 && *v10 < 0 )
      {
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 115;
        *(_DWORD *)(*(_DWORD *)a1 + 24) = v9;
        *(_DWORD *)(*(_DWORD *)a1 + 28) = 0;
        (*(void (__cdecl **)(struct jpeg_decompress_struct *, int))(*(_DWORD *)a1 + 4))(a1, a2: -1);
      }
      for ( i = *((_DWORD *)a1 + 91); i <= *((_DWORD *)a1 + 92); ++i )
      {
        if ( *((_DWORD *)a1 + 93) != (v10[i] < 0 ? 0 : v10[i]) )
        {
          *(_DWORD *)(*(_DWORD *)a1 + 20) = 115;
          *(_DWORD *)(*(_DWORD *)a1 + 24) = v9;
          *(_DWORD *)(*(_DWORD *)a1 + 28) = i;
          (*(void (__cdecl **)(struct jpeg_decompress_struct *, int))(*(_DWORD *)a1 + 4))(a1, a2: -1);
        }
        v10[i] = *((_DWORD *)a1 + 94);
      }
      v19 += 4;
      result = ++v17;
    }
    while ( v17 < *((_DWORD *)a1 + 73) );
    v4 = v20;
    v3 = v21;
  }
  if ( *((_DWORD *)a1 + 93) != 0 )
  {
    if ( v3 )
      *(_DWORD *)(v4 + 4) = sub_101A3BF0;
    else
      *(_DWORD *)(v4 + 4) = sub_101A3CE0;
  }
  else if ( v3 )
  {
    *(_DWORD *)(v4 + 4) = sub_101A3760;
  }
  else
  {
    *(_DWORD *)(v4 + 4) = sub_101A39A0;
  }
  v18 = 0;
  if ( *((int *)a1 + 73) > 0 )
  {
    v12 = (_DWORD *)(v4 + 24);
    v13 = (int *)((char *)a1 + 296);
    do
    {
      v14 = *v13;
      if ( v21 )
      {
        if ( *((_DWORD *)a1 + 93) == 0 )
          jpeg_make_d_derived_tbl(
            a1,
            a2: 1,
            a3: *(_DWORD *)(v14 + 20),
            a4: (struct d_derived_tbl **)(v4 + 4 * *(_DWORD *)(v14 + 20) + 44));
      }
      else
      {
        v15 = *(_DWORD *)(v14 + 24);
        v16 = (struct d_derived_tbl **)(v4 + 4 * v15 + 44);
        jpeg_make_d_derived_tbl(a1, a2: 0, a3: v15, a4: v16);
        *(_DWORD *)(v20 + 60) = *v16;
        v4 = v20;
      }
      *v12 = 0;
      result = v18 + 1;
      ++v13;
      ++v12;
      ++v18;
    }
    while ( v18 < *((_DWORD *)a1 + 73) );
  }
  *(_DWORD *)(v4 + 16) = 0;
  *(_DWORD *)(v4 + 12) = 0;
  *(_DWORD *)(v4 + 20) = 0;
  *(_BYTE *)(v4 + 8) = 0;
  *(_DWORD *)(v4 + 40) = *((_DWORD *)a1 + 63);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A4350
// Name: void jinit_phuff_decoder(struct jpeg_decompress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jinit_phuff_decoder(int (__cdecl ***a1)(struct jpeg_decompress_struct *, int, int))
{
  int (__cdecl **v1)(struct jpeg_decompress_struct *, int, int); // eax
  int v2; // ebx
  int v3; // eax
  bool v4; // cc
  char *v5; // edx

  v1 = (int (__cdecl **)(struct jpeg_decompress_struct *, int, int))(*a1[1])(
                                                                      (struct jpeg_decompress_struct *)a1,
                                                                      a2: 1,
                                                                      a3: 64);
  a1[102] = v1;
  *v1 = (int (__cdecl *)(struct jpeg_decompress_struct *, int, int))sub_101A40E0;
  v2 = 0;
  v1[11] = nullptr;
  v1[12] = nullptr;
  v1[13] = nullptr;
  v1[14] = nullptr;
  v3 = (*a1[1])((struct jpeg_decompress_struct *)a1, a2: 1, a3: (_DWORD)a1[9] << 8);
  v4 = (int)a1[9] <= 0;
  a1[35] = (int (__cdecl **)(struct jpeg_decompress_struct *, int, int))v3;
  v5 = (char *)v3;
  if ( !v4 )
  {
    do
    {
      ++v2;
      memset(v5, 0xFFu, 0x100u);
      v5 += 256;
    }
    while ( v2 < (int)a1[9] );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A43C0
// Name: void jinit_compress_master(struct jpeg_compress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jinit_compress_master(struct jpeg_compress_struct *a1)
{
  unsigned __int8 v1; // al

  jinit_c_master_control(a1, a2: 0);
  if ( *((_BYTE *)a1 + 176) == 0 )
  {
    jinit_color_converter(a1);
    jinit_downsampler(a1);
    jinit_c_prep_controller(a1, a2: 0);
  }
  jinit_forward_dct(a1);
  if ( *((_BYTE *)a1 + 177) != 0 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 1;
    (**(void (__cdecl ***)(struct jpeg_compress_struct *))a1)(a1);
  }
  else if ( *((_BYTE *)a1 + 212) != 0 )
  {
    jinit_phuff_encoder(a1);
  }
  else
  {
    jinit_huff_encoder(a1);
  }
  v1 = *((int *)a1 + 42) > 1 || *((_BYTE *)a1 + 178) != 0;
  jinit_c_coef_controller(a1, a2: v1);
  jinit_c_main_controller(a1, a2: 0);
  jinit_marker_writer(a1);
  (*(void (__cdecl **)(struct jpeg_compress_struct *))(*((_DWORD *)a1 + 1) + 24))(a1);
  (**((void (__cdecl ***)(struct jpeg_compress_struct *))a1 + 83))(a1);
}

//------------------------------------------------------------------------------
// Address: 0x101A4480
// Name: sub_101A4480
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A4480@<eax>(_DWORD *a1@<esi>, char a2)
{
  int result; // eax

  result = a1[6];
  *(_BYTE *)(*(_DWORD *)result)++ = a2;
  if ( (*(_DWORD *)(result + 4))-- == 1 )
  {
    result = (*(int (__cdecl **)(_DWORD *))(result + 12))(a1);
    if ( (_BYTE)result == 0 )
    {
      *(_DWORD *)(*a1 + 20) = 24;
      return (*(int (__cdecl **)(_DWORD *))*a1)(a1);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A44C0
// Name: sub_101A44C0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A44C0@<eax>(_DWORD *a1@<eax>, char a2)
{
  sub_101A4480(a1, a2: 255);
  return sub_101A4480(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x101A44E0
// Name: sub_101A44E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A44E0@<eax>(__int16 a1@<ax>, _DWORD *a2@<ecx>)
{
  char v2; // bl

  v2 = a1;
  sub_101A4480(a1: a2, a2: SHIBYTE(a1));
  return sub_101A4480(a1: a2, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x101A4510
// Name: sub_101A4510
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A4510@<eax>(int a1@<eax>, _DWORD *a2@<ecx>)
{
  char v2; // bl
  int v4; // edi
  int v5; // ebp
  _WORD *v6; // eax
  int i; // edx
  const int *const *v8; // ebx
  __int16 v9; // di
  int v11; // [esp+10h] [ebp-4h]

  v2 = a1;
  v4 = a2[a1 + 18];
  v11 = v4;
  if ( v4 == 0 )
  {
    *(_DWORD *)(*a2 + 20) = 52;
    *(_DWORD *)(*a2 + 24) = a1;
    (*(void (__cdecl **)(_DWORD *))*a2)(a1: a2);
  }
  v5 = 0;
  v6 = (_WORD *)(v4 + 4);
  for ( i = 16; i != 0; --i )
  {
    if ( *(v6 - 2) > 0xFFu )
      v5 = 1;
    if ( *(v6 - 1) > 0xFFu )
      v5 = 1;
    if ( *v6 > 0xFFu )
      v5 = 1;
    if ( v6[1] > 0xFFu )
      v5 = 1;
    v6 += 4;
  }
  if ( *(_BYTE *)(v4 + 128) == 0 )
  {
    sub_101A44C0(a1: a2, a2: 219);
    sub_101A44E0(a1: v5 != 0 ? 131 : 67, a2);
    sub_101A4480(a1: a2, a2: v2 + 16 * v5);
    v8 = &jpeg_natural_order;
    while ( 1 )
    {
      v9 = *(_WORD *)(v4 + 2 * (int)*v8);
      if ( v5 != 0 )
        sub_101A4480(a1: a2, a2: SHIBYTE(v9));
      sub_101A4480(a1: a2, a2: v9);
      if ( (int)++v8 >= (int)&unk_102ACA58 )
        break;
      v4 = v11;
    }
    *(_BYTE *)(v11 + 128) = 1;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x101A4610
// Name: sub_101A4610
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A4610(int a1, char a2)
{
  _DWORD *v2; // ecx
  int result; // eax
  _DWORD *v4; // esi
  int v5; // ebp
  int v6; // edi
  unsigned __int8 *v7; // eax
  int i; // ecx
  int v9; // edx
  int v10; // ebx
  int j; // ebx
  int k; // ebx

  result = a1;
  v4 = v2;
  if ( a2 != 0 )
  {
    v5 = v2[a1 + 26];
    result = a1 + 16;
    LOBYTE(a1) = a1 + 16;
  }
  else
  {
    v5 = v2[a1 + 22];
  }
  if ( v5 == 0 )
  {
    *(_DWORD *)(*v2 + 20) = 50;
    *(_DWORD *)(*v2 + 24) = result;
    result = (*(int (__cdecl **)(_DWORD *))*v2)(a1: v2);
  }
  if ( *(_BYTE *)(v5 + 273) == 0 )
  {
    sub_101A44C0(a1: v4, a2: 196);
    v6 = 0;
    v7 = (unsigned __int8 *)(v5 + 3);
    for ( i = 4; i != 0; --i )
    {
      v9 = v7[1] + *(v7 - 1) + *(v7 - 2);
      v10 = v6 + *v7;
      v7 += 4;
      v6 = v10 + v9;
    }
    sub_101A44E0(a1: v6 + 19, a2: v4);
    sub_101A4480(a1: v4, a2: a1);
    for ( j = 1; j <= 16; ++j )
      result = sub_101A4480(a1: v4, a2: *(_BYTE *)(j + v5));
    for ( k = 0; k < v6; ++k )
      result = sub_101A4480(a1: v4, a2: *(_BYTE *)(k + v5 + 17));
    *(_BYTE *)(v5 + 273) = 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A4700
// Name: sub_101A4700
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A4700@<eax>(_DWORD *a1@<esi>)
{
  sub_101A44C0(a1, a2: 221);
  sub_101A44E0(a1: 4, a2: a1);
  return sub_101A44E0(a1: a1[47], a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x101A4730
// Name: sub_101A4730
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A4730@<eax>(char a1@<al>, int a2@<ecx>)
{
  int result; // eax
  int v4; // edi
  int i; // ebx

  sub_101A44C0(a1: (_DWORD *)a2, a2: a1);
  sub_101A44E0(a1: 3 * *(_WORD *)(a2 + 60) + 8, (_DWORD *)a2);
  if ( *(int *)(a2 + 32) > 0xFFFF || *(int *)(a2 + 28) > 0xFFFF )
  {
    *(_DWORD *)(*(_DWORD *)a2 + 20) = 41;
    *(_DWORD *)(*(_DWORD *)a2 + 24) = 0xFFFF;
    (**(void (__cdecl ***)(int))a2)(a1: a2);
  }
  sub_101A4480(a1: (_DWORD *)a2, a2: *(_DWORD *)(a2 + 56));
  sub_101A44E0(a1: *(_DWORD *)(a2 + 32), (_DWORD *)a2);
  sub_101A44E0(a1: *(_DWORD *)(a2 + 28), (_DWORD *)a2);
  result = sub_101A4480(a1: (_DWORD *)a2, a2: *(_DWORD *)(a2 + 60));
  v4 = *(_DWORD *)(a2 + 68);
  for ( i = 0; i < *(_DWORD *)(a2 + 60); v4 += 84 )
  {
    sub_101A4480(a1: (_DWORD *)a2, a2: *(_DWORD *)v4);
    sub_101A4480(a1: (_DWORD *)a2, a2: *(_BYTE *)(v4 + 12) + 16 * *(_BYTE *)(v4 + 8));
    result = sub_101A4480(a1: (_DWORD *)a2, a2: *(_DWORD *)(v4 + 16));
    ++i;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A48B0
// Name: sub_101A48B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A48B0@<eax>(int a1@<eax>)
{
  sub_101A44C0((_DWORD *)a1, a2: 224);
  sub_101A44E0(a1: 16, a2: (_DWORD *)a1);
  sub_101A4480((_DWORD *)a1, a2: 74);
  sub_101A4480((_DWORD *)a1, a2: 70);
  sub_101A4480((_DWORD *)a1, a2: 73);
  sub_101A4480((_DWORD *)a1, a2: 70);
  sub_101A4480((_DWORD *)a1, a2: 0);
  sub_101A4480((_DWORD *)a1, a2: *(_BYTE *)(a1 + 197));
  sub_101A4480((_DWORD *)a1, a2: *(_BYTE *)(a1 + 198));
  sub_101A4480((_DWORD *)a1, a2: *(_BYTE *)(a1 + 199));
  sub_101A44E0(a1: *(_WORD *)(a1 + 200), a2: (_DWORD *)a1);
  sub_101A44E0(a1: *(_WORD *)(a1 + 202), a2: (_DWORD *)a1);
  sub_101A4480((_DWORD *)a1, a2: 0);
  return sub_101A4480((_DWORD *)a1, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101A49E0
// Name: sub_101A49E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A49E0(_DWORD *a1, char a2, unsigned int a3)
{
  if ( a3 > 0xFFFD )
  {
    *(_DWORD *)(*a1 + 20) = 11;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  sub_101A44C0(a1, a2);
  return sub_101A44E0(a1: a3 + 2, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x101A4A20
// Name: sub_101A4A20
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A4A20(_DWORD *a1, char a2)
{
  return sub_101A4480(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x101A4A40
// Name: sub_101A4A40
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A4A40(int a1)
{
  int v1; // edi
  int result; // eax

  v1 = *(_DWORD *)(a1 + 332);
  result = sub_101A44C0((_DWORD *)a1, a2: 216);
  *(_DWORD *)(v1 + 28) = 0;
  if ( *(_BYTE *)(a1 + 196) != 0 )
    result = sub_101A48B0(a1);
  if ( *(_BYTE *)(a1 + 204) != 0 )
  {
    sub_101A44C0((_DWORD *)a1, a2: 238);
    sub_101A44E0(a1: 14, a2: (_DWORD *)a1);
    sub_101A4480((_DWORD *)a1, a2: 65);
    sub_101A4480((_DWORD *)a1, a2: 100);
    sub_101A4480((_DWORD *)a1, a2: 111);
    sub_101A4480((_DWORD *)a1, a2: 98);
    sub_101A4480((_DWORD *)a1, a2: 101);
    sub_101A44E0(a1: 100, a2: (_DWORD *)a1);
    sub_101A44E0(a1: 0, a2: (_DWORD *)a1);
    sub_101A44E0(a1: 0, a2: (_DWORD *)a1);
    if ( *(_DWORD *)(a1 + 64) == 3 )
    {
      return sub_101A4480((_DWORD *)a1, a2: 1);
    }
    else if ( *(_DWORD *)(a1 + 64) == 5 )
    {
      return sub_101A4480((_DWORD *)a1, a2: 2);
    }
    else
    {
      return sub_101A4480((_DWORD *)a1, a2: 0);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A4A90
// Name: sub_101A4A90
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A4A90(int a1)
{
  int v1; // ebx
  int v2; // edi
  int *v3; // ebp
  int v4; // ecx
  char v5; // bl
  int *v6; // eax
  int v8; // [esp+Ch] [ebp-4h]

  v1 = 0;
  v2 = 0;
  v8 = 0;
  if ( *(int *)(a1 + 60) > 0 )
  {
    v3 = (int *)(*(_DWORD *)(a1 + 68) + 16);
    do
    {
      ++v2;
      v1 += sub_101A4510(a1: *v3, a2: (_DWORD *)a1);
      v3 += 21;
    }
    while ( v2 < *(_DWORD *)(a1 + 60) );
    v8 = v1;
  }
  if ( *(_BYTE *)(a1 + 177) != 0 || *(_BYTE *)(a1 + 212) != 0 || *(_DWORD *)(a1 + 56) != 8 )
  {
    v5 = 0;
  }
  else
  {
    v4 = *(_DWORD *)(a1 + 60);
    v5 = 1;
    if ( v4 > 0 )
    {
      v6 = (int *)(*(_DWORD *)(a1 + 68) + 24);
      do
      {
        if ( *(v6 - 1) > 1 || *v6 > 1 )
          v5 = 0;
        v6 += 21;
        --v4;
      }
      while ( v4 != 0 );
    }
    if ( v8 != 0 && v5 != 0 )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 75;
      v5 = 0;
      (*(void (__cdecl **)(int, _DWORD))(*(_DWORD *)a1 + 4))(a1, a2: 0);
    }
  }
  if ( *(_BYTE *)(a1 + 177) != 0 )
    return sub_101A4730(a1: 201, a2: a1);
  if ( *(_BYTE *)(a1 + 212) != 0 )
    return sub_101A4730(a1: 194, a2: a1);
  if ( v5 != 0 )
    return sub_101A4730(a1: 192, a2: a1);
  return sub_101A4730(a1: 193, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x101A4B90
// Name: sub_101A4B90
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A4B90(int a1)
{
  int v1; // ebp
  _DWORD *v2; // ebx
  _DWORD *v3; // edi
  int v4; // eax
  int v5; // edi
  bool v8; // zf
  int v9; // edi
  int v10; // ebp
  int *v11; // ebx
  int v12; // edi
  int v13; // [esp+Ch] [ebp+4h]

  v8 = *(_BYTE *)(a1 + 177) == 0;
  v9 = *(_DWORD *)(a1 + 332);
  v13 = v9;
  if ( v8 )
  {
    v10 = 0;
    if ( *(int *)(a1 + 228) > 0 )
    {
      v11 = (int *)(a1 + 232);
      do
      {
        v12 = *v11;
        if ( *(_BYTE *)(a1 + 212) != 0 )
        {
          if ( *(_DWORD *)(a1 + 300) != 0 )
          {
            sub_101A4610(a1: *(_DWORD *)(v12 + 24), a2: 1);
          }
          else if ( *(_DWORD *)(a1 + 308) == 0 )
          {
            sub_101A4610(a1: *(_DWORD *)(v12 + 20), a2: 0);
          }
        }
        else
        {
          sub_101A4610(a1: *(_DWORD *)(v12 + 20), a2: 0);
          sub_101A4610(a1: *(_DWORD *)(v12 + 24), a2: 1);
        }
        ++v10;
        ++v11;
      }
      while ( v10 < *(_DWORD *)(a1 + 228) );
      v9 = v13;
    }
  }
  if ( *(_DWORD *)(a1 + 188) != *(_DWORD *)(v9 + 28) )
  {
    sub_101A4700((_DWORD *)a1);
    *(_DWORD *)(v9 + 28) = *(_DWORD *)(a1 + 188);
  }
  sub_101A44C0((_DWORD *)a1, a2: 218);
  sub_101A44E0(a1: 2 * *(_WORD *)(a1 + 228) + 6, a2: (_DWORD *)a1);
  sub_101A4480((_DWORD *)a1, a2: *(_DWORD *)(a1 + 228));
  v1 = 0;
  if ( *(int *)(a1 + 228) > 0 )
  {
    v2 = (_DWORD *)(a1 + 232);
    do
    {
      v3 = (_DWORD *)*v2;
      sub_101A4480((_DWORD *)a1, a2: *(_DWORD *)*v2);
      v4 = v3[5];
      v5 = v3[6];
      if ( *(_BYTE *)(a1 + 212) != 0 )
      {
        if ( *(_DWORD *)(a1 + 300) != 0 || (LOBYTE(v5) = 0, *(_DWORD *)(a1 + 308) != 0) && *(_BYTE *)(a1 + 177) == 0 )
          LOBYTE(v4) = 0;
      }
      sub_101A4480((_DWORD *)a1, a2: v5 + 16 * v4);
      ++v1;
      ++v2;
    }
    while ( v1 < *(_DWORD *)(a1 + 228) );
  }
  sub_101A4480((_DWORD *)a1, a2: *(_DWORD *)(a1 + 300));
  sub_101A4480((_DWORD *)a1, a2: *(_DWORD *)(a1 + 304));
  return sub_101A4480((_DWORD *)a1, a2: *(_BYTE *)(a1 + 312) + 16 * *(_BYTE *)(a1 + 308));
}

//------------------------------------------------------------------------------
// Address: 0x101A4C60
// Name: sub_101A4C60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A4C60(_DWORD *a1)
{
  return sub_101A44C0(a1, a2: 217);
}

//------------------------------------------------------------------------------
// Address: 0x101A4C70
// Name: sub_101A4C70
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A4C70(int a1)
{
  int v1; // esi
  _DWORD *v2; // ebx
  int v3; // esi
  _DWORD *v4; // ebx

  sub_101A44C0((_DWORD *)a1, a2: 216);
  v1 = 0;
  v2 = (_DWORD *)(a1 + 72);
  do
  {
    if ( *v2 != 0 )
      sub_101A4510(a1: v1, a2: (_DWORD *)a1);
    ++v1;
    ++v2;
  }
  while ( v1 < 4 );
  if ( *(_BYTE *)(a1 + 177) == 0 )
  {
    v3 = 0;
    v4 = (_DWORD *)(a1 + 104);
    do
    {
      if ( *(v4 - 4) != 0 )
        sub_101A4610(a1: v3, a2: 0);
      if ( *v4 != 0 )
        sub_101A4610(a1: v3, a2: 1);
      ++v3;
      ++v4;
    }
    while ( v3 < 4 );
  }
  return sub_101A44C0((_DWORD *)a1, a2: 217);
}

//------------------------------------------------------------------------------
// Address: 0x101A4D00
// Name: void jinit_marker_writer(struct jpeg_compress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jinit_marker_writer(int (__cdecl ***a1)(struct jpeg_compress_struct *, int, int))
{
  int (__cdecl **v1)(int); // eax

  v1 = (int (__cdecl **)(int))(*a1[1])((struct jpeg_compress_struct *)a1, a2: 1, a3: 32);
  a1[83] = (int (__cdecl **)(struct jpeg_compress_struct *, int, int))v1;
  *v1 = sub_101A4A40;
  v1[1] = sub_101A4A90;
  v1[2] = sub_101A4B90;
  v1[3] = (int (__cdecl *)(int))sub_101A4C60;
  v1[4] = sub_101A4C70;
  v1[5] = (int (__cdecl *)(int))sub_101A49E0;
  v1[6] = (int (__cdecl *)(int))sub_101A4A20;
  v1[7] = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101A4D60
// Name: void jpeg_make_c_derived_tbl(struct jpeg_compress_struct __near *,unsigned char,int,struct c_derived_tbl __near * __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_make_c_derived_tbl(
        struct jpeg_compress_struct *a1,
        char a2,
        unsigned int a3,
        struct c_derived_tbl **a4)
{
  int v4; // edi
  int i; // ebp
  unsigned int v6; // esi
  int v7; // edi
  int v8; // esi
  int v9; // ebp
  unsigned __int8 *v10; // eax
  int v11; // ecx
  int v12; // ebp
  int j; // esi
  int v14; // edi
  int v15; // ecx
  unsigned __int8 v16; // al
  int v17; // [esp+10h] [ebp-51Ch]
  int v18; // [esp+14h] [ebp-518h]
  int v19; // [esp+18h] [ebp-514h]
  _DWORD v20[257]; // [esp+20h] [ebp-50Ch]
  unsigned __int8 dst[260]; // [esp+424h] [ebp-108h] BYREF

  if ( a3 >= 4 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 50;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = a3;
    (**(void (__cdecl ***)(struct jpeg_compress_struct *))a1)(a1);
  }
  if ( a2 != 0 )
    v17 = *((_DWORD *)a1 + a3 + 22);
  else
    v17 = *((_DWORD *)a1 + a3 + 26);
  if ( v17 == 0 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 50;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = a3;
    (**(void (__cdecl ***)(struct jpeg_compress_struct *))a1)(a1);
  }
  if ( *a4 == nullptr )
    *a4 = (struct c_derived_tbl *)(**((int (__cdecl ***)(struct jpeg_compress_struct *, int, int))a1 + 1))(
                                    a1,
                                    a2: 1,
                                    a3: 1280);
  v19 = (int)*a4;
  v4 = 0;
  for ( i = 1; i <= 16; ++i )
  {
    v6 = *(unsigned __int8 *)(v17 + i);
    if ( (int)(v6 + v4) > 256 )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 8;
      (**(void (__cdecl ***)(struct jpeg_compress_struct *))a1)(a1);
    }
    if ( v6 != 0 )
    {
      memset(dst: &dst[v4], value: i, count: v6);
      v4 += v6;
    }
  }
  dst[v4] = 0;
  v18 = v4;
  v7 = 0;
  v8 = 0;
  v9 = (char)dst[0];
  if ( dst[0] != 0 )
  {
    v10 = dst;
    do
    {
      if ( (char)*v10 == v9 )
      {
        do
        {
          v11 = (char)dst[v8 + 1];
          v20[v8++] = v7++;
        }
        while ( v11 == v9 );
      }
      if ( v7 >= 1 << v9 )
      {
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 8;
        (**(void (__cdecl ***)(struct jpeg_compress_struct *))a1)(a1);
      }
      v10 = &dst[v8];
      v7 *= 2;
      ++v9;
    }
    while ( dst[v8] != 0 );
  }
  v12 = v19 + 1024;
  memset(dst: (unsigned __int8 *)(v19 + 1024), value: 0, count: 0x100u);
  for ( j = 0; j < v18; *(_BYTE *)(v14 + v12) = v16 )
  {
    v14 = *(unsigned __int8 *)(v17 + j + 17);
    if ( v14 > (a2 != 0 ? 15 : 255) || *(_BYTE *)(v14 + v12) != 0 )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 8;
      (**(void (__cdecl ***)(struct jpeg_compress_struct *))a1)(a1);
    }
    v15 = v20[j];
    v16 = dst[j++];
    *(_DWORD *)(v19 + 4 * v14) = v15;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A4F80
// Name: sub_101A4F80
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall sub_101A4F80@<al>(_DWORD *a1@<edi>)
{
  int v1; // esi
  char result; // al

  v1 = *(_DWORD *)(a1[8] + 24);
  result = (*(int (__cdecl **)(_DWORD))(v1 + 12))(a1: a1[8]);
  if ( result != 0 )
  {
    *a1 = *(_DWORD *)v1;
    a1[1] = *(_DWORD *)(v1 + 4);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A4FB0
// Name: sub_101A4FB0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall sub_101A4FB0@<al>(int a1@<eax>, int a2@<ecx>, int a3)
{
  int v5; // ebp
  int v6; // ebp
  int v7; // esi
  bool v8; // zf

  v5 = *(_DWORD *)(a2 + 12);
  if ( a1 == 0 )
  {
    *(_DWORD *)(**(_DWORD **)(a2 + 32) + 20) = 40;
    (***(void (__cdecl ****)(_DWORD))(a2 + 32))(a1: *(_DWORD *)(a2 + 32));
  }
  v6 = a1 + v5;
  v7 = *(_DWORD *)(a2 + 8) | ((a3 & ((1 << a1) - 1)) << (24 - v6));
  if ( v6 < 8 )
  {
LABEL_10:
    *(_DWORD *)(a2 + 8) = v7;
    *(_DWORD *)(a2 + 12) = v6;
    return 1;
  }
  else
  {
    while ( 1 )
    {
      *(_BYTE *)(*(_DWORD *)a2)++ = BYTE2(v7);
      v8 = (*(_DWORD *)(a2 + 4))-- == 1;
      if ( v8 && sub_101A4F80(a1: (_DWORD *)a2) == 0 )
        return 0;
      if ( BYTE2(v7) == 255 )
      {
        *(_BYTE *)(*(_DWORD *)a2)++ = 0;
        v8 = (*(_DWORD *)(a2 + 4))-- == 1;
        if ( v8 && sub_101A4F80(a1: (_DWORD *)a2) == 0 )
          return 0;
      }
      v6 -= 8;
      v7 <<= 8;
      if ( v6 < 8 )
        goto LABEL_10;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A5060
// Name: sub_101A5060
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall sub_101A5060@<al>(int a1@<esi>)
{
  char result; // al

  result = sub_101A4FB0(a1: 7, a2: a1, a3: 127);
  if ( result != 0 )
  {
    *(_DWORD *)(a1 + 8) = 0;
    *(_DWORD *)(a1 + 12) = 0;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A5090
// Name: sub_101A5090
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall sub_101A5090@<al>(int a1@<eax>, int a2, __int16 *a3, int a4, int a5)
{
  int v6; // esi
  int v7; // eax
  int v8; // edi
  _DWORD *v10; // eax
  int v11; // esi
  int v12; // edi
  int v13; // edi
  int v14; // ebx
  _DWORD *v15; // [esp+10h] [ebp-4h]
  int v16; // [esp+20h] [ebp+Ch]

  v6 = *a3 - a4;
  v7 = v6;
  if ( v6 < 0 )
  {
    v7 = a4 - *a3;
    --v6;
  }
  v8 = 0;
  if ( v7 != 0 )
  {
    do
    {
      ++v8;
      v7 >>= 1;
    }
    while ( v7 != 0 );
    if ( v8 > 11 )
    {
      *(_DWORD *)(**(_DWORD **)(a2 + 32) + 20) = 6;
      (***(void (__cdecl ****)(_DWORD))(a2 + 32))(a1: *(_DWORD *)(a2 + 32));
    }
  }
  if ( sub_101A4FB0(a1: *(char *)(v8 + a1 + 1024), a2, a3: *(_DWORD *)(a1 + 4 * v8)) != 0
    && (v8 == 0 || sub_101A4FB0(a1: v8, a2, a3: v6) != 0) )
  {
    v10 = &unk_102AC95C;
    v11 = 0;
    v15 = &unk_102AC95C;
    do
    {
      v12 = a3[*v10];
      if ( a3[*v10] != 0 )
      {
        if ( v11 > 15 )
        {
          while ( sub_101A4FB0(a1: *(char *)(a5 + 1264), a2, a3: *(_DWORD *)(a5 + 960)) != 0 )
          {
            v11 -= 16;
            if ( v11 <= 15 )
              goto LABEL_17;
          }
          return 0;
        }
LABEL_17:
        v16 = v12;
        if ( v12 < 0 )
        {
          v12 = -v12;
          --v16;
        }
        v13 = v12 >> 1;
        v14 = 1;
        if ( v13 != 0 )
        {
          do
          {
            ++v14;
            v13 >>= 1;
          }
          while ( v13 != 0 );
          if ( v14 > 10 )
          {
            *(_DWORD *)(**(_DWORD **)(a2 + 32) + 20) = 6;
            (***(void (__cdecl ****)(_DWORD))(a2 + 32))(a1: *(_DWORD *)(a2 + 32));
          }
        }
        if ( sub_101A4FB0(a1: *(char *)(v14 + 16 * v11 + a5 + 1024), a2, a3: *(_DWORD *)(a5 + 4 * (v14 + 16 * v11))) == 0
          || sub_101A4FB0(a1: v14, a2, a3: v16) == 0 )
        {
          return 0;
        }
        v10 = v15;
        v11 = 0;
      }
      else
      {
        ++v11;
      }
      v15 = ++v10;
    }
    while ( (int)v10 < (int)dword_102ACA58 );
    if ( v11 <= 0 || sub_101A4FB0(a1: *(char *)(a5 + 1024), a2, a3: *(_DWORD *)a5) != 0 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A5230
// Name: sub_101A5230
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall sub_101A5230@<al>(_DWORD *a1@<eax>, char a2)
{
  bool v4; // zf
  int v5; // eax
  _DWORD *v6; // ecx

  if ( sub_101A5060((int)a1) == 0 )
    return 0;
  *(_BYTE *)(*a1)++ = -1;
  v4 = a1[1]-- == 1;
  if ( v4 && sub_101A4F80(a1) == 0 )
    return 0;
  *(_BYTE *)(*a1)++ = a2 - 48;
  v4 = a1[1]-- == 1;
  if ( v4 && sub_101A4F80(a1) == 0 )
    return 0;
  v5 = 0;
  if ( *(int *)(a1[8] + 228) > 0 )
  {
    v6 = a1 + 4;
    do
    {
      *v6 = 0;
      ++v5;
      ++v6;
    }
    while ( v5 < *(_DWORD *)(a1[8] + 228) );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101A52B0
// Name: sub_101A52B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl sub_101A52B0(_DWORD *a1, int a2)
{
  bool v3; // zf
  _DWORD *v4; // esi
  int *v5; // eax
  int v6; // ecx
  int v7; // edx
  int v8; // eax
  int v9; // ecx
  int v10; // edx
  int v11; // eax
  int v12; // ecx
  int v13; // edx
  char result; // al
  int v15; // ebx
  int v16; // ecx
  int *v17; // ebp
  int v18; // edx
  bool v19; // cc
  int v20; // ecx
  int v21; // edx
  int v22; // eax
  int v23; // ecx
  int v24; // edx
  int v25; // eax
  int v26; // edi
  int v27; // ecx
  int v28; // [esp+8h] [ebp-24h] BYREF
  int v29; // [esp+Ch] [ebp-20h]
  int v30; // [esp+10h] [ebp-1Ch]
  int v31; // [esp+14h] [ebp-18h]
  int v32; // [esp+18h] [ebp-14h] BYREF
  int v33; // [esp+1Ch] [ebp-10h]
  int v34; // [esp+20h] [ebp-Ch]
  int v35; // [esp+24h] [ebp-8h]
  _DWORD *v36; // [esp+28h] [ebp-4h]
  _DWORD *v37; // [esp+30h] [ebp+4h]

  v3 = a1[47] == 0;
  v4 = (_DWORD *)a1[87];
  v5 = (int *)a1[6];
  v6 = *v5;
  v7 = v5[1];
  v8 = v4[3];
  v28 = v6;
  v9 = v4[4];
  v29 = v7;
  v10 = v4[5];
  v30 = v8;
  v11 = v4[6];
  v31 = v9;
  v12 = v4[7];
  v32 = v10;
  v13 = v4[8];
  v33 = v11;
  v34 = v12;
  v35 = v13;
  v36 = a1;
  if ( v3 || v4[9] != 0 || (result = sub_101A5230(a1: &v28, a2: v4[10])) != 0 )
  {
    v15 = 0;
    if ( (int)a1[64] <= 0 )
    {
LABEL_8:
      *(_DWORD *)a1[6] = v28;
      v20 = v30;
      *(_DWORD *)(a1[6] + 4) = v29;
      v21 = v31;
      v22 = v32;
      v4[3] = v20;
      v23 = v33;
      v4[4] = v21;
      v24 = v34;
      v4[5] = v22;
      v25 = v35;
      v4[6] = v23;
      v4[7] = v24;
      v4[8] = v25;
      v26 = a1[47];
      if ( v26 != 0 )
      {
        if ( v4[9] == 0 )
        {
          v27 = ((unsigned __int8)v4[10] + 1) & 7;
          v4[9] = v26;
          v4[10] = v27;
        }
        --v4[9];
      }
      return 1;
    }
    else
    {
      v37 = a1 + 65;
      while ( 1 )
      {
        v16 = a1[*v37 + 58];
        v17 = &v32 + *v37;
        if ( sub_101A5090(
               a1: v4[*(_DWORD *)(v16 + 20) + 11],
               a2: (int)&v28,
               a3: *(__int16 **)(a2 + 4 * v15),
               a4: *v17,
               a5: v4[*(_DWORD *)(v16 + 24) + 15]) == 0 )
          return 0;
        v18 = **(__int16 **)(a2 + 4 * v15);
        ++v37;
        v19 = ++v15 < a1[64];
        *v17 = v18;
        if ( !v19 )
          goto LABEL_8;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A5420
// Name: sub_101A5420
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A5420(_DWORD *a1)
{
  int *v1; // eax
  int v2; // ecx
  int v3; // edx
  _DWORD *v4; // edi
  int v5; // eax
  int v6; // ecx
  int v7; // edx
  int v8; // eax
  int v9; // ecx
  int v10; // edx
  int v11; // ecx
  int v12; // edx
  int v13; // eax
  int v14; // ecx
  int v15; // edx
  int result; // eax
  int v17; // [esp+Ch] [ebp-24h] BYREF
  int v18; // [esp+10h] [ebp-20h]
  int v19; // [esp+14h] [ebp-1Ch]
  int v20; // [esp+18h] [ebp-18h]
  int v21; // [esp+1Ch] [ebp-14h]
  int v22; // [esp+20h] [ebp-10h]
  int v23; // [esp+24h] [ebp-Ch]
  int v24; // [esp+28h] [ebp-8h]
  _DWORD *v25; // [esp+2Ch] [ebp-4h]

  v1 = (int *)a1[6];
  v2 = *v1;
  v3 = v1[1];
  v4 = (_DWORD *)a1[87];
  v5 = v4[3];
  v17 = v2;
  v6 = v4[4];
  v18 = v3;
  v7 = v4[5];
  v19 = v5;
  v8 = v4[6];
  v20 = v6;
  v9 = v4[7];
  v21 = v7;
  v10 = v4[8];
  v22 = v8;
  v23 = v9;
  v24 = v10;
  v25 = a1;
  if ( sub_101A5060(a1: (int)&v17) == 0 )
  {
    *(_DWORD *)(*a1 + 20) = 24;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  *(_DWORD *)a1[6] = v17;
  v11 = v19;
  *(_DWORD *)(a1[6] + 4) = v18;
  v12 = v20;
  v13 = v21;
  v4[3] = v11;
  v14 = v22;
  v4[4] = v12;
  v15 = v23;
  v4[5] = v13;
  result = v24;
  v4[6] = v14;
  v4[7] = v15;
  v4[8] = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A54E0
// Name: sub_101A54E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A54E0@<eax>(int a1@<eax>, _DWORD *a2@<ebx>, int a3, __int16 *a4, int a5)
{
  int result; // eax
  int v7; // esi
  int v8; // esi
  _DWORD *v9; // ebp
  int v10; // ecx
  unsigned int v11; // eax
  int v12; // ecx
  int v13; // edi
  int v14; // esi

  result = *a4 - a5;
  if ( result < 0 )
    result = a5 - *a4;
  v7 = 0;
  if ( result != 0 )
  {
    do
    {
      ++v7;
      result >>= 1;
    }
    while ( result != 0 );
    if ( v7 > 11 )
    {
      *(_DWORD *)(*(_DWORD *)a3 + 20) = 6;
      result = (**(int (__cdecl ***)(int))a3)(a1: a3);
    }
  }
  ++*(_DWORD *)(a1 + 4 * v7);
  v8 = 0;
  v9 = &unk_102AC95C;
  do
  {
    v10 = a4[*v9];
    if ( a4[*v9] != 0 )
    {
      if ( v8 > 15 )
      {
        v11 = ((unsigned int)(v8 - 16) >> 4) + 1;
        v8 += -16 * v11;
        a2[240] += v11;
      }
      if ( v10 < 0 )
        v10 = -v10;
      v12 = v10 >> 1;
      v13 = 1;
      if ( v12 != 0 )
      {
        do
        {
          ++v13;
          v12 >>= 1;
        }
        while ( v12 != 0 );
        if ( v13 > 10 )
        {
          *(_DWORD *)(*(_DWORD *)a3 + 20) = 6;
          (**(void (__cdecl ***)(int))a3)(a1: a3);
        }
      }
      v14 = v13 + 16 * v8;
      ++a2[v14];
      result = (int)&a2[v14];
      v8 = 0;
    }
    else
    {
      ++v8;
    }
    ++v9;
  }
  while ( (int)v9 < (int)dword_102ACA58 );
  if ( v8 > 0 )
    ++*a2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A55D0
// Name: sub_101A55D0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl sub_101A55D0(_DWORD *a1, int a2)
{
  int v3; // edi
  int v4; // eax
  _DWORD *v5; // ecx
  int v6; // ebp
  int v7; // eax
  __int16 *v8; // eax
  int v10; // [esp+Ch] [ebp-4h]
  int *v11; // [esp+14h] [ebp+4h]

  v3 = a1[87];
  if ( a1[47] != 0 )
  {
    if ( *(_DWORD *)(v3 + 36) == 0 )
    {
      v4 = 0;
      if ( (int)a1[57] > 0 )
      {
        v5 = (_DWORD *)(v3 + 20);
        do
        {
          *v5 = 0;
          ++v4;
          ++v5;
        }
        while ( v4 < a1[57] );
      }
      *(_DWORD *)(v3 + 36) = a1[47];
    }
    --*(_DWORD *)(v3 + 36);
  }
  v6 = 0;
  if ( (int)a1[64] > 0 )
  {
    v11 = a1 + 65;
    do
    {
      v7 = a1[*v11 + 58];
      v10 = *v11;
      sub_101A54E0(
        a1: *(_DWORD *)(v3 + 4 * *(_DWORD *)(v7 + 20) + 76),
        a2: *(_DWORD **)(v3 + 4 * *(_DWORD *)(v7 + 24) + 92),
        a3: (int)a1,
        a4: *(__int16 **)(a2 + 4 * v6),
        a5: *(_DWORD *)(v3 + 4 * *v11 + 20));
      v8 = *(__int16 **)(a2 + 4 * v6);
      ++v11;
      ++v6;
      *(_DWORD *)(v3 + 4 * v10 + 20) = *v8;
    }
    while ( v6 < a1[64] );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101A56A0
// Name: void jpeg_gen_optimal_table(struct jpeg_compress_struct __near *,struct JHUFF_TBL __near *,long __near * const)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_gen_optimal_table(struct jpeg_compress_struct *a1, struct JHUFF_TBL *a2, int *const a3)
{
  int v3; // eax
  int v4; // esi
  int i; // ecx
  int v6; // edx
  int v7; // edx
  int v8; // edi
  int j; // ecx
  int v10; // esi
  bool v11; // sf
  int *v12; // ecx
  int *v13; // eax
  int v14; // eax
  int k; // edi
  int v16; // esi
  int v17; // esi
  int v18; // ecx
  int v19; // edx
  int m; // eax
  int v21; // ecx
  int v22; // edx
  int v23; // eax
  int v24; // ecx
  int n; // edx
  int ii; // eax
  _DWORD dst[257]; // [esp+18h] [ebp-830h] BYREF
  _DWORD v28[257]; // [esp+41Ch] [ebp-42Ch] BYREF
  int v29; // [esp+820h] [ebp-28h]
  int v30; // [esp+824h] [ebp-24h]
  int v31; // [esp+828h] [ebp-20h]
  int v32; // [esp+82Ch] [ebp-1Ch]
  int v33; // [esp+830h] [ebp-18h]
  int v34; // [esp+834h] [ebp-14h]
  int v35; // [esp+838h] [ebp-10h]
  int v36; // [esp+83Ch] [ebp-Ch]
  char v37; // [esp+840h] [ebp-8h]

  v29 = 0;
  v30 = 0;
  v31 = 0;
  v32 = 0;
  v33 = 0;
  v34 = 0;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  memset((unsigned __int8 *)dst, value: 0, count: sizeof(dst));
  memset(v28, 0xFFu, sizeof(v28));
  a3[256] = 1;
  while ( 1 )
  {
    v3 = -1;
    v4 = 1000000000;
    for ( i = 0; i <= 256; ++i )
    {
      v6 = a3[i];
      if ( v6 != 0 && v6 <= v4 )
      {
        v4 = a3[i];
        v3 = i;
      }
    }
    v7 = -1;
    v8 = 1000000000;
    for ( j = 0; j <= 256; ++j )
    {
      v10 = a3[j];
      if ( v10 != 0 && v10 <= v8 && j != v3 )
      {
        v8 = a3[j];
        v7 = j;
      }
    }
    if ( v7 < 0 )
      break;
    a3[v3] += a3[v7];
    ++dst[v3];
    v11 = (int)v28[v3] < 0;
    v12 = &v28[v3];
    a3[v7] = 0;
    if ( !v11 )
    {
      do
      {
        v3 = *v12;
        ++dst[v3];
        v12 = &v28[v3];
      }
      while ( *v12 >= 0 );
    }
    ++dst[v7];
    v28[v3] = v7;
    v13 = &v28[v7];
    if ( *v13 >= 0 )
    {
      do
      {
        v14 = *v13;
        ++dst[v14];
        v11 = (int)v28[v14] < 0;
        v13 = &v28[v14];
      }
      while ( !v11 );
    }
  }
  for ( k = 0; k <= 256; ++k )
  {
    v16 = dst[k];
    if ( v16 != 0 )
    {
      if ( v16 > 32 )
      {
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 39;
        (**(void (__cdecl ***)(struct jpeg_compress_struct *))a1)(a1);
      }
      ++*((_BYTE *)&v29 + v16);
    }
  }
  v17 = 16;
  v18 = 30;
  v19 = 16;
  do
  {
    for ( ; *((_BYTE *)&v29 + v18 + 2) != 0; --*((_BYTE *)&v29 + m) )
    {
      for ( m = v18; *((_BYTE *)&v29 + m) == 0; --m )
        ;
      *((_BYTE *)&v29 + v18 + 2) -= 2;
      ++*((_BYTE *)&v29 + v18 + 1);
      *((_BYTE *)&v29 + m + 1) += 2;
    }
    --v18;
    --v17;
  }
  while ( v17 != 0 );
  if ( (_BYTE)v33 == 0 )
  {
    do
      --v19;
    while ( *((_BYTE *)&v29 + v19) == 0 );
  }
  --*((_BYTE *)&v29 + v19);
  v21 = v30;
  v22 = v31;
  *(_DWORD *)a2 = v29;
  v23 = v32;
  *((_DWORD *)a2 + 1) = v21;
  LOBYTE(v21) = v33;
  *((_DWORD *)a2 + 2) = v22;
  *((_DWORD *)a2 + 3) = v23;
  *((_BYTE *)a2 + 16) = v21;
  v24 = 0;
  for ( n = 1; n <= 32; ++n )
  {
    for ( ii = 0; ii <= 255; ++ii )
    {
      if ( dst[ii] == n )
        *((_BYTE *)a2 + v24++ + 17) = ii;
    }
  }
  *((_BYTE *)a2 + 273) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A5970
// Name: sub_101A5970
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A5970(struct jpeg_common_struct *a1)
{
  int result; // eax
  bool v3; // cc
  int v4; // edi
  int v5; // ebp
  int v6; // [esp+4h] [ebp-10h]
  int v7; // [esp+8h] [ebp-Ch]
  int v8; // [esp+Ch] [ebp-8h]
  int v9; // [esp+10h] [ebp-4h]
  struct jpeg_common_struct *v10; // [esp+18h] [ebp+4h]

  v6 = *((_DWORD *)a1 + 87);
  result = 0;
  v3 = *((_DWORD *)a1 + 57) <= 0;
  v8 = 0;
  v9 = 0;
  v7 = 0;
  if ( !v3 )
  {
    v10 = (struct jpeg_common_struct *)((char *)a1 + 232);
    do
    {
      v4 = *(_DWORD *)(*(_DWORD *)v10 + 20);
      v5 = *(_DWORD *)(*(_DWORD *)v10 + 24);
      if ( *((_BYTE *)&v8 + v4) == 0 )
      {
        if ( *((_DWORD *)a1 + v4 + 22) == 0 )
          *((_DWORD *)a1 + v4 + 22) = jpeg_alloc_huff_table(a1);
        jpeg_gen_optimal_table(a1, a2: *((struct JHUFF_TBL **)a1 + v4 + 22), a3: *(int *const *)(v6 + 4 * v4 + 76));
        *((_BYTE *)&v8 + v4) = 1;
      }
      if ( *((_BYTE *)&v9 + v5) == 0 )
      {
        if ( *((_DWORD *)a1 + v5 + 26) == 0 )
          *((_DWORD *)a1 + v5 + 26) = jpeg_alloc_huff_table(a1);
        jpeg_gen_optimal_table(a1, a2: *((struct JHUFF_TBL **)a1 + v5 + 26), a3: *(int *const *)(v6 + 4 * v5 + 92));
        *((_BYTE *)&v9 + v5) = 1;
      }
      v10 = (struct jpeg_common_struct *)((char *)v10 + 4);
      result = ++v7;
    }
    while ( v7 < *((_DWORD *)a1 + 57) );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A5A60
// Name: sub_101A5A60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A5A60(struct jpeg_compress_struct *a1, char a2)
{
  _DWORD *v3; // edi
  unsigned int v4; // ebp
  unsigned int v5; // ebx
  bool v6; // cc
  int v8; // [esp+8h] [ebp-8h]
  _DWORD *v9; // [esp+Ch] [ebp-4h]
  struct jpeg_compress_struct *v10; // [esp+14h] [ebp+4h]

  v3 = *((_DWORD **)a1 + 87);
  if ( a2 != 0 )
  {
    v3[1] = sub_101A55D0;
    v3[2] = sub_101A5970;
  }
  else
  {
    v3[1] = sub_101A52B0;
    v3[2] = sub_101A5420;
  }
  v8 = 0;
  if ( *((int *)a1 + 57) > 0 )
  {
    v9 = v3 + 5;
    v10 = (struct jpeg_compress_struct *)((char *)a1 + 232);
    do
    {
      v4 = *(_DWORD *)(*(_DWORD *)v10 + 20);
      v5 = *(_DWORD *)(*(_DWORD *)v10 + 24);
      if ( a2 != 0 )
      {
        if ( v4 >= 4 )
        {
          *(_DWORD *)(*(_DWORD *)a1 + 20) = 50;
          *(_DWORD *)(*(_DWORD *)a1 + 24) = v4;
          (**(void (__cdecl ***)(struct jpeg_compress_struct *))a1)(a1);
        }
        if ( v5 >= 4 )
        {
          *(_DWORD *)(*(_DWORD *)a1 + 20) = 50;
          *(_DWORD *)(*(_DWORD *)a1 + 24) = v5;
          (**(void (__cdecl ***)(struct jpeg_compress_struct *))a1)(a1);
        }
        if ( v3[v4 + 19] == 0 )
          v3[v4 + 19] = (**((int (__cdecl ***)(struct jpeg_compress_struct *, int, int))a1 + 1))(a1, a2: 1, a3: 1028);
        memset(dst: (unsigned __int8 *)v3[v4 + 19], value: 0, count: 0x404u);
        if ( v3[v5 + 23] == 0 )
          v3[v5 + 23] = (**((int (__cdecl ***)(struct jpeg_compress_struct *, int, int))a1 + 1))(a1, a2: 1, a3: 1028);
        memset(dst: (unsigned __int8 *)v3[v5 + 23], value: 0, count: 0x404u);
      }
      else
      {
        jpeg_make_c_derived_tbl(a1, a2: 1, a3: v4, a4: (struct c_derived_tbl **)&v3[v4 + 11]);
        jpeg_make_c_derived_tbl(a1, a2: 0, a3: v5, a4: (struct c_derived_tbl **)&v3[v5 + 15]);
      }
      v10 = (struct jpeg_compress_struct *)((char *)v10 + 4);
      *v9 = 0;
      v6 = ++v8 < *((_DWORD *)a1 + 57);
      ++v9;
    }
    while ( v6 );
  }
  v3[3] = 0;
  v3[4] = 0;
  v3[9] = *((_DWORD *)a1 + 47);
  v3[10] = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A5BF0
// Name: void jinit_huff_encoder(struct jpeg_compress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jinit_huff_encoder(int (__cdecl ***a1)(struct jpeg_compress_struct *, int, int))
{
  int (__cdecl **v1)(struct jpeg_compress_struct *, int, int); // eax

  v1 = (int (__cdecl **)(struct jpeg_compress_struct *, int, int))(*a1[1])(
                                                                    (struct jpeg_compress_struct *)a1,
                                                                    a2: 1,
                                                                    a3: 108);
  a1[87] = v1;
  *v1 = (int (__cdecl *)(struct jpeg_compress_struct *, int, int))sub_101A5A60;
  v1[15] = nullptr;
  v1[11] = nullptr;
  v1[23] = nullptr;
  v1[19] = nullptr;
  v1[16] = nullptr;
  v1[12] = nullptr;
  v1[24] = nullptr;
  v1[20] = nullptr;
  v1[17] = nullptr;
  v1[13] = nullptr;
  v1[25] = nullptr;
  v1[21] = nullptr;
  v1[18] = nullptr;
  v1[14] = nullptr;
  v1[26] = nullptr;
  v1[22] = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101A5C50
// Name: sub_101A5C50
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A5C50@<eax>(_DWORD *a1@<esi>)
{
  int *v1; // edi
  int result; // eax

  v1 = *(int **)(a1[8] + 24);
  if ( ((unsigned __int8 (__cdecl *)(_DWORD))v1[3])(a1: a1[8]) == 0 )
  {
    *(_DWORD *)(*(_DWORD *)a1[8] + 20) = 24;
    (**(void (__cdecl ***)(_DWORD))a1[8])(a1: a1[8]);
  }
  result = *v1;
  a1[4] = *v1;
  a1[5] = v1[1];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A5C90
// Name: sub_101A5C90
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A5C90@<eax>(int result@<eax>, int a2@<ecx>, int a3)
{
  int v3; // ebx
  int v5; // ebp
  unsigned int v6; // ebp
  int v7; // edi
  bool v8; // zf
  unsigned int v9; // [esp+10h] [ebp+4h]

  v3 = result;
  v5 = *(_DWORD *)(a2 + 28);
  if ( result == 0 )
  {
    *(_DWORD *)(**(_DWORD **)(a2 + 32) + 20) = 40;
    result = (***(int (__cdecl ****)(_DWORD))(a2 + 32))(a1: *(_DWORD *)(a2 + 32));
  }
  if ( *(_BYTE *)(a2 + 12) == 0 )
  {
    v6 = v3 + v5;
    v7 = *(_DWORD *)(a2 + 24) | ((a3 & ((1 << v3) - 1)) << (24 - v6));
    if ( (int)v6 >= 8 )
    {
      v9 = v6 >> 3;
      result = -(v6 >> 3);
      v6 -= 8 * (v6 >> 3);
      do
      {
        *(_BYTE *)(*(_DWORD *)(a2 + 16))++ = BYTE2(v7);
        v8 = (*(_DWORD *)(a2 + 20))-- == 1;
        if ( v8 )
          result = sub_101A5C50(a1: (_DWORD *)a2);
        if ( BYTE2(v7) == 255 )
        {
          result = *(_DWORD *)(a2 + 16);
          *(_BYTE *)result = 0;
          ++*(_DWORD *)(a2 + 16);
          v8 = (*(_DWORD *)(a2 + 20))-- == 1;
          if ( v8 )
            result = sub_101A5C50(a1: (_DWORD *)a2);
        }
        v7 <<= 8;
        --v9;
      }
      while ( v9 != 0 );
    }
    *(_DWORD *)(a2 + 24) = v7;
    *(_DWORD *)(a2 + 28) = v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A5D50
// Name: sub_101A5D50
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A5D50@<eax>(int a1@<esi>)
{
  sub_101A5C90(result: 7, a2: a1, a3: 127);
  *(_DWORD *)(a1 + 24) = 0;
  *(_DWORD *)(a1 + 28) = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101A5D70
// Name: sub_101A5D70
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A5D70@<eax>(int a1@<eax>, int a2@<ecx>, int a3@<esi>)
{
  int v3; // eax

  if ( *(_BYTE *)(a2 + 12) == 0 )
    return sub_101A5C90(
             result: *(char *)(*(_DWORD *)(a2 + 4 * a1 + 76) + a3 + 1024),
             a2,
             a3: *(_DWORD *)(*(_DWORD *)(a2 + 4 * a1 + 76) + 4 * a3));
  v3 = *(_DWORD *)(a2 + 4 * a1 + 92);
  ++*(_DWORD *)(v3 + 4 * a3);
  return v3 + 4 * a3;
}

//------------------------------------------------------------------------------
// Address: 0x101A5DA0
// Name: sub_101A5DA0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A5DA0@<eax>(int result@<eax>, char *a2@<ecx>, int a3@<edi>)
{
  int v3; // ebx

  v3 = result;
  if ( *(_BYTE *)(a3 + 12) == 0 && result != 0 )
  {
    do
    {
      result = sub_101A5C90(result: 1, a2: a3, a3: *a2++);
      --v3;
    }
    while ( v3 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A5DD0
// Name: sub_101A5DD0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A5DD0@<eax>(int a1@<eax>)
{
  int result; // eax
  int v3; // ebx
  int v4; // eax
  int v5; // eax
  char *v6; // ecx

  result = *(_DWORD *)(a1 + 56);
  if ( result != 0 )
  {
    v3 = 0;
    v4 = result >> 1;
    if ( v4 != 0 )
    {
      do
      {
        ++v3;
        v4 >>= 1;
      }
      while ( v4 != 0 );
      if ( v3 > 14 )
      {
        *(_DWORD *)(**(_DWORD **)(a1 + 32) + 20) = 40;
        (***(void (__cdecl ****)(_DWORD))(a1 + 32))(a1: *(_DWORD *)(a1 + 32));
      }
    }
    sub_101A5D70(a1: *(_DWORD *)(a1 + 52), a2: a1, a3: 16 * v3);
    if ( v3 != 0 )
      sub_101A5C90(result: v3, a2: a1, a3: *(_DWORD *)(a1 + 56));
    v5 = *(_DWORD *)(a1 + 60);
    v6 = *(char **)(a1 + 64);
    *(_DWORD *)(a1 + 56) = 0;
    result = sub_101A5DA0(result: v5, a2: v6, a3: a1);
    *(_DWORD *)(a1 + 60) = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A5E50
// Name: sub_101A5E50
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_BYTE *__usercall sub_101A5E50@<eax>(int a1@<eax>, char a2)
{
  _BYTE *result; // eax
  bool v4; // zf
  int v5; // ecx
  _DWORD *v6; // ecx

  result = (_BYTE *)sub_101A5DD0(a1);
  if ( *(_BYTE *)(a1 + 12) == 0 )
  {
    sub_101A5D50(a1);
    result = *(_BYTE **)(a1 + 16);
    *result = -1;
    ++*(_DWORD *)(a1 + 16);
    v4 = (*(_DWORD *)(a1 + 20))-- == 1;
    if ( v4 )
      result = (_BYTE *)sub_101A5C50((_DWORD *)a1);
    *(_BYTE *)(*(_DWORD *)(a1 + 16))++ = a2 - 48;
    v4 = (*(_DWORD *)(a1 + 20))-- == 1;
    if ( v4 )
      result = (_BYTE *)sub_101A5C50((_DWORD *)a1);
  }
  v5 = *(_DWORD *)(a1 + 32);
  if ( *(_DWORD *)(v5 + 300) != 0 )
  {
    *(_DWORD *)(a1 + 56) = 0;
    *(_DWORD *)(a1 + 60) = 0;
  }
  else
  {
    result = nullptr;
    if ( *(int *)(v5 + 228) > 0 )
    {
      v6 = (_DWORD *)(a1 + 36);
      do
      {
        *v6 = 0;
        ++result;
        ++v6;
      }
      while ( (int)result < *(_DWORD *)(*(_DWORD *)(a1 + 32) + 228) );
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A5EE0
// Name: sub_101A5EE0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl sub_101A5EE0(int a1, int a2)
{
  int v3; // esi
  _DWORD *v4; // edi
  int v5; // ebx
  int v6; // edx
  int v7; // eax
  int v8; // esi
  int v9; // ebp
  int v10; // edx
  _DWORD *v12; // [esp+Ch] [ebp-Ch]
  char v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+14h] [ebp-4h]
  int v15; // [esp+1Ch] [ebp+4h]

  v3 = *(_DWORD *)(a1 + 312);
  v4 = *(_DWORD **)(a1 + 348);
  v4[4] = **(_DWORD **)(a1 + 24);
  v4[5] = *(_DWORD *)(*(_DWORD *)(a1 + 24) + 4);
  if ( *(_DWORD *)(a1 + 188) != 0 && v4[17] == 0 )
    sub_101A5E50(a1: (int)v4, a2: v4[18]);
  v5 = 0;
  if ( *(int *)(a1 + 256) > 0 )
  {
    v13 = v3;
    v12 = (_DWORD *)(a1 + 260);
    do
    {
      v14 = *(_DWORD *)(a1 + 4 * *v12 + 232);
      v6 = **(__int16 **)(a2 + 4 * v5) >> v13;
      v7 = v6 - v4[*v12 + 9];
      v4[*v12 + 9] = v6;
      v15 = v7;
      if ( v7 < 0 )
      {
        v7 = -v7;
        --v15;
      }
      v8 = 0;
      if ( v7 != 0 )
      {
        do
        {
          ++v8;
          v7 >>= 1;
        }
        while ( v7 != 0 );
        if ( v8 > 11 )
        {
          *(_DWORD *)(*(_DWORD *)a1 + 20) = 6;
          (**(void (__cdecl ***)(int))a1)(a1);
        }
      }
      sub_101A5D70(a1: *(_DWORD *)(v14 + 20), a2: (int)v4, a3: v8);
      if ( v8 != 0 )
        sub_101A5C90(result: v8, a2: (int)v4, a3: v15);
      ++v12;
      ++v5;
    }
    while ( v5 < *(_DWORD *)(a1 + 256) );
  }
  **(_DWORD **)(a1 + 24) = v4[4];
  *(_DWORD *)(*(_DWORD *)(a1 + 24) + 4) = v4[5];
  v9 = *(_DWORD *)(a1 + 188);
  if ( v9 != 0 )
  {
    if ( v4[17] == 0 )
    {
      v10 = ((unsigned __int8)v4[18] + 1) & 7;
      v4[17] = v9;
      v4[18] = v10;
    }
    --v4[17];
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101A6030
// Name: sub_101A6030
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl sub_101A6030(int a1, int *a2)
{
  int v2; // ebp
  int v3; // eax
  int v4; // ebx
  _DWORD *v5; // edi
  int v6; // eax
  int v7; // esi
  const int *v8; // edx
  int v9; // ebx
  int v10; // ebx
  unsigned int v11; // ebp
  int v12; // ebx
  int v13; // ebp
  int v14; // ebp
  int v15; // eax
  char v17; // [esp+10h] [ebp-14h]
  int v18; // [esp+14h] [ebp-10h]
  int v19; // [esp+18h] [ebp-Ch]
  int v20; // [esp+1Ch] [ebp-8h]
  int v21; // [esp+20h] [ebp-4h]

  v2 = a1;
  v3 = *(_DWORD *)(a1 + 312);
  v4 = *(_DWORD *)(a1 + 304);
  v5 = *(_DWORD **)(a1 + 348);
  v5[4] = **(_DWORD **)(a1 + 24);
  v17 = v3;
  v5[5] = *(_DWORD *)(*(_DWORD *)(a1 + 24) + 4);
  v21 = v4;
  if ( *(_DWORD *)(a1 + 188) != 0 && v5[17] == 0 )
    sub_101A5E50(a1: (int)v5, a2: v5[18]);
  v6 = *(_DWORD *)(a1 + 300);
  v7 = 0;
  v20 = *a2;
  v19 = v6;
  if ( v6 <= v4 )
  {
    do
    {
      v8 = (&jpeg_natural_order)[v6];
      v9 = *(__int16 *)(v20 + 2 * (_DWORD)v8);
      if ( *(_WORD *)(v20 + 2 * (_DWORD)v8) != 0 )
      {
        if ( v9 >= 0 )
        {
          v10 = v9 >> v17;
          v18 = v10;
        }
        else
        {
          v10 = -v9 >> v17;
          v18 = ~v10;
        }
        if ( v10 != 0 )
        {
          if ( v5[14] != 0 )
            sub_101A5DD0(a1: (int)v5);
          if ( v7 > 15 )
          {
            v11 = ((unsigned int)(v7 - 16) >> 4) + 1;
            do
            {
              sub_101A5D70(a1: v5[13], a2: (int)v5, a3: 240);
              --v11;
            }
            while ( v11 != 0 );
            v7 += -16 * (((unsigned int)(v7 - 16) >> 4) + 1);
          }
          v12 = v10 >> 1;
          v13 = 1;
          if ( v12 != 0 )
          {
            do
            {
              ++v13;
              v12 >>= 1;
            }
            while ( v12 != 0 );
            if ( v13 > 10 )
            {
              *(_DWORD *)(*(_DWORD *)a1 + 20) = 6;
              (**(void (__cdecl ***)(int))a1)(a1);
            }
          }
          sub_101A5D70(a1: v5[13], a2: (int)v5, a3: v13 + 16 * v7);
          sub_101A5C90(result: v13, a2: (int)v5, a3: v18);
          v6 = v19;
          v2 = a1;
          v7 = 0;
        }
        else
        {
          ++v7;
        }
      }
      else
      {
        ++v7;
      }
      v19 = ++v6;
    }
    while ( v6 <= v21 );
    if ( v7 > 0 && ++v5[14] == 0x7FFF )
      sub_101A5DD0(a1: (int)v5);
  }
  **(_DWORD **)(v2 + 24) = v5[4];
  *(_DWORD *)(*(_DWORD *)(v2 + 24) + 4) = v5[5];
  v14 = *(_DWORD *)(v2 + 188);
  if ( v14 != 0 )
  {
    if ( v5[17] == 0 )
    {
      v15 = ((unsigned __int8)v5[18] + 1) & 7;
      v5[17] = v14;
      v5[18] = v15;
    }
    --v5[17];
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101A61F0
// Name: sub_101A61F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl sub_101A61F0(int a1, int a2)
{
  int v3; // eax
  _DWORD *v4; // esi
  int i; // ebx
  int v6; // edi
  int v7; // edx
  char v9; // [esp+Ch] [ebp+4h]

  v3 = *(_DWORD *)(a1 + 312);
  v4 = *(_DWORD **)(a1 + 348);
  v4[4] = **(_DWORD **)(a1 + 24);
  v9 = v3;
  v4[5] = *(_DWORD *)(*(_DWORD *)(a1 + 24) + 4);
  if ( *(_DWORD *)(a1 + 188) != 0 && v4[17] == 0 )
    sub_101A5E50(a1: (int)v4, a2: v4[18]);
  for ( i = 0; i < *(_DWORD *)(a1 + 256); ++i )
    sub_101A5C90(result: 1, a2: (int)v4, a3: **(__int16 **)(a2 + 4 * i) >> v9);
  **(_DWORD **)(a1 + 24) = v4[4];
  *(_DWORD *)(*(_DWORD *)(a1 + 24) + 4) = v4[5];
  v6 = *(_DWORD *)(a1 + 188);
  if ( v6 != 0 )
  {
    if ( v4[17] == 0 )
    {
      v7 = ((unsigned __int8)v4[18] + 1) & 7;
      v4[17] = v6;
      v4[18] = v7;
    }
    --v4[17];
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101A62B0
// Name: sub_101A62B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl sub_101A62B0(int a1, int *a2)
{
  int v2; // ebp
  _DWORD *v3; // edi
  int v4; // ebx
  int v5; // esi
  int v6; // eax
  int v7; // edx
  int v8; // edx
  char *v9; // ebp
  int v10; // ebx
  int v11; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v16; // [esp+10h] [ebp-118h]
  int v17; // [esp+14h] [ebp-114h]
  int v18; // [esp+18h] [ebp-110h]
  int i; // [esp+1Ch] [ebp-10Ch]
  int v20; // [esp+20h] [ebp-108h]
  int v21; // [esp+24h] [ebp-104h]
  _DWORD v22[64]; // [esp+28h] [ebp-100h]

  v2 = *(_DWORD *)(a1 + 312);
  v18 = *(_DWORD *)(a1 + 304);
  v3 = *(_DWORD **)(a1 + 348);
  v3[4] = **(_DWORD **)(a1 + 24);
  v3[5] = *(_DWORD *)(*(_DWORD *)(a1 + 24) + 4);
  if ( *(_DWORD *)(a1 + 188) != 0 && v3[17] == 0 )
    sub_101A5E50(a1: (int)v3, a2: v3[18]);
  v4 = *a2;
  v5 = *(_DWORD *)(a1 + 300);
  v6 = v5;
  v21 = *a2;
  for ( i = 0; v6 <= v18; ++v6 )
  {
    v7 = *(__int16 *)(v4 + 2 * (int)(&jpeg_natural_order)[v6]);
    if ( v7 < 0 )
      v7 = -v7;
    v8 = v7 >> v2;
    v22[v6] = v8;
    if ( v8 == 1 )
      i = v6;
  }
  v9 = (char *)(v3[15] + v3[16]);
  v10 = 0;
  v11 = v5;
  v16 = 0;
  v17 = v5;
  if ( v5 <= v18 )
  {
    do
    {
      v12 = v22[v11];
      v20 = v12;
      if ( v12 != 0 )
      {
        for ( ; v16 > 15; v10 = 0 )
        {
          if ( v11 > i )
            break;
          sub_101A5DD0(a1: (int)v3);
          sub_101A5D70(a1: v3[13], a2: (int)v3, a3: 240);
          v16 -= 16;
          sub_101A5DA0(result: v10, a2: v9, a3: (int)v3);
          v9 = (char *)v3[16];
          v12 = v20;
          v11 = v17;
        }
        if ( v12 <= 1 )
        {
          sub_101A5DD0(a1: (int)v3);
          sub_101A5D70(a1: v3[13], a2: (int)v3, a3: 16 * v16 + 1);
          sub_101A5C90(result: 1, a2: (int)v3, a3: *(_WORD *)(v21 + 2 * (int)(&jpeg_natural_order)[v17]) >= 0);
          sub_101A5DA0(result: v10, a2: v9, a3: (int)v3);
          v9 = (char *)v3[16];
          v11 = v17;
          v10 = 0;
          v16 = 0;
        }
        else
        {
          v9[v10++] = v12 & 1;
        }
      }
      else
      {
        ++v16;
      }
      v17 = ++v11;
    }
    while ( v11 <= v18 );
    if ( v16 > 0 || v10 != 0 )
    {
      v13 = ++v3[14];
      v3[15] += v10;
      if ( v13 == 0x7FFF || v3[15] > 0x3A9u )
        sub_101A5DD0(a1: (int)v3);
    }
  }
  **(_DWORD **)(a1 + 24) = v3[4];
  *(_DWORD *)(*(_DWORD *)(a1 + 24) + 4) = v3[5];
  v14 = *(_DWORD *)(a1 + 188);
  if ( v14 != 0 )
  {
    if ( v3[17] == 0 )
    {
      v3[17] = v14;
      v3[18] = ((unsigned __int8)v3[18] + 1) & 7;
    }
    --v3[17];
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101A64E0
// Name: sub_101A64E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A64E0(int a1)
{
  int v1; // esi
  int result; // eax

  v1 = *(_DWORD *)(a1 + 348);
  *(_DWORD *)(v1 + 16) = **(_DWORD **)(a1 + 24);
  *(_DWORD *)(v1 + 20) = *(_DWORD *)(*(_DWORD *)(a1 + 24) + 4);
  sub_101A5DD0(a1: v1);
  sub_101A5D50(a1: v1);
  **(_DWORD **)(a1 + 24) = *(_DWORD *)(v1 + 16);
  result = *(_DWORD *)(a1 + 24);
  *(_DWORD *)(result + 4) = *(_DWORD *)(v1 + 20);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A6520
// Name: sub_101A6520
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A6520(struct jpeg_common_struct *a1)
{
  int result; // eax
  bool v3; // zf
  bool v4; // cl
  int v5; // eax
  int v6; // ebp
  struct JHUFF_TBL **v7; // edi
  int *i; // [esp+4h] [ebp-10h]
  int v9; // [esp+8h] [ebp-Ch]
  int v10; // [esp+Ch] [ebp-8h]
  int v11; // [esp+10h] [ebp-4h]
  bool v12; // [esp+18h] [ebp+4h]

  v11 = *((_DWORD *)a1 + 87);
  sub_101A5DD0(a1: v11);
  result = 0;
  v3 = *((_DWORD *)a1 + 75) == 0;
  v10 = 0;
  v4 = v3;
  v12 = v3;
  v9 = 0;
  if ( *((int *)a1 + 57) > 0 )
  {
    for ( i = (int *)((char *)a1 + 232); ; ++i )
    {
      v5 = *i;
      if ( !v4 )
        break;
      if ( *((_DWORD *)a1 + 77) == 0 )
      {
        v6 = *(_DWORD *)(v5 + 20);
        goto LABEL_7;
      }
LABEL_13:
      result = ++v9;
      if ( v9 >= *((_DWORD *)a1 + 57) )
        return result;
    }
    v6 = *(_DWORD *)(v5 + 24);
LABEL_7:
    if ( *((_BYTE *)&v10 + v6) == 0 )
    {
      v7 = (struct JHUFF_TBL **)((char *)a1 + 4 * v6 + 88);
      if ( !v4 )
        v7 = (struct JHUFF_TBL **)((char *)a1 + 4 * v6 + 104);
      if ( *v7 == nullptr )
        *v7 = jpeg_alloc_huff_table(a1);
      jpeg_gen_optimal_table(a1, a2: *v7, a3: *(int *const *)(v11 + 4 * v6 + 92));
      v4 = v12;
      *((_BYTE *)&v10 + v6) = 1;
    }
    goto LABEL_13;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A65F0
// Name: sub_101A65F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl sub_101A65F0(struct jpeg_compress_struct *a1, char a2)
{
  int v3; // ebp
  int v4; // eax
  bool v5; // zf
  int *v6; // ebx
  int v7; // eax
  unsigned int v8; // edi
  int v9; // edx
  char v11; // [esp+10h] [ebp-8h]
  int v12; // [esp+14h] [ebp-4h]
  struct jpeg_compress_struct *v13; // [esp+1Ch] [ebp+4h]

  v3 = *((_DWORD *)a1 + 87);
  *(_DWORD *)(v3 + 32) = a1;
  *(_BYTE *)(v3 + 12) = a2;
  LOBYTE(v4) = *((_DWORD *)a1 + 75) == 0;
  v11 = v4;
  if ( *((_DWORD *)a1 + 77) != 0 )
  {
    if ( *((_DWORD *)a1 + 75) != 0 )
    {
      v5 = *(_DWORD *)(v3 + 64) == 0;
      *(_DWORD *)(v3 + 4) = sub_101A62B0;
      if ( v5 )
      {
        v4 = (**((int (__cdecl ***)(struct jpeg_compress_struct *, int, int))a1 + 1))(a1, a2: 1, a3: 1000);
        *(_DWORD *)(v3 + 64) = v4;
      }
    }
    else
    {
      *(_DWORD *)(v3 + 4) = sub_101A61F0;
    }
  }
  else if ( *((_DWORD *)a1 + 75) != 0 )
  {
    *(_DWORD *)(v3 + 4) = sub_101A6030;
  }
  else
  {
    *(_DWORD *)(v3 + 4) = sub_101A5EE0;
  }
  if ( a2 != 0 )
    *(_DWORD *)(v3 + 8) = sub_101A6520;
  else
    *(_DWORD *)(v3 + 8) = sub_101A64E0;
  v12 = 0;
  if ( *((int *)a1 + 57) > 0 )
  {
    v13 = (struct jpeg_compress_struct *)(v3 + 36);
    v6 = (int *)((char *)a1 + 232);
    while ( 1 )
    {
      v7 = *v6;
      *(_DWORD *)v13 = 0;
      if ( v11 == 0 )
        break;
      if ( *((_DWORD *)a1 + 77) == 0 )
      {
        v8 = *(_DWORD *)(v7 + 20);
        goto LABEL_18;
      }
LABEL_25:
      v13 = (struct jpeg_compress_struct *)((char *)v13 + 4);
      LOBYTE(v4) = v12 + 1;
      ++v6;
      if ( ++v12 >= *((_DWORD *)a1 + 57) )
        goto LABEL_26;
    }
    v8 = *(_DWORD *)(v7 + 24);
    *(_DWORD *)(v3 + 52) = v8;
LABEL_18:
    if ( a2 != 0 )
    {
      if ( v8 >= 4 )
      {
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 50;
        *(_DWORD *)(*(_DWORD *)a1 + 24) = v8;
        (**(void (__cdecl ***)(struct jpeg_compress_struct *))a1)(a1);
      }
      if ( *(_DWORD *)(v3 + 4 * v8 + 92) == 0 )
        *(_DWORD *)(v3 + 4 * v8 + 92) = (**((int (__cdecl ***)(struct jpeg_compress_struct *, int, int))a1 + 1))(
                                          a1,
                                          a2: 1,
                                          a3: 1028);
      memset(dst: *(unsigned __int8 **)(v3 + 4 * v8 + 92), value: 0, count: 0x404u);
    }
    else
    {
      jpeg_make_c_derived_tbl(a1, a2: v11, a3: v8, a4: (struct c_derived_tbl **)(v3 + 4 * v8 + 76));
    }
    goto LABEL_25;
  }
LABEL_26:
  *(_DWORD *)(v3 + 56) = 0;
  *(_DWORD *)(v3 + 60) = 0;
  *(_DWORD *)(v3 + 24) = 0;
  *(_DWORD *)(v3 + 28) = 0;
  v9 = *((_DWORD *)a1 + 47);
  *(_DWORD *)(v3 + 72) = 0;
  *(_DWORD *)(v3 + 68) = v9;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101A6780
// Name: void jinit_phuff_encoder(struct jpeg_compress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jinit_phuff_encoder(int (__cdecl ***a1)(struct jpeg_compress_struct *, int, int))
{
  char (__cdecl **v1)(struct jpeg_compress_struct *, char); // eax

  v1 = (char (__cdecl **)(struct jpeg_compress_struct *, char))(*a1[1])(
                                                                 (struct jpeg_compress_struct *)a1,
                                                                 a2: 1,
                                                                 a3: 108);
  a1[87] = (int (__cdecl **)(struct jpeg_compress_struct *, int, int))v1;
  *v1 = sub_101A65F0;
  v1[19] = nullptr;
  v1[23] = nullptr;
  v1[20] = nullptr;
  v1[24] = nullptr;
  v1[21] = nullptr;
  v1[25] = nullptr;
  v1[22] = nullptr;
  v1[26] = nullptr;
  v1[16] = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101A67C0
// Name: sub_101A67C0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A67C0@<eax>(_DWORD *a1@<esi>)
{
  int v1; // eax
  int v2; // ebp
  bool v3; // cc
  int *v4; // edi
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // ebp
  int v9; // edi
  int v10; // eax
  int v11; // eax
  int v12; // edx
  int v13; // eax
  int v14; // ecx
  int result; // eax

  if ( a1[8] == 0 || a1[7] == 0 || (int)a1[15] <= 0 || (int)a1[9] <= 0 )
  {
    *(_DWORD *)(*a1 + 20) = 32;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  if ( (int)a1[8] > 65500 || (int)a1[7] > 65500 )
  {
    *(_DWORD *)(*a1 + 20) = 41;
    *(_DWORD *)(*a1 + 24) = 65500;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  if ( a1[14] != 8 )
  {
    *(_DWORD *)(*a1 + 20) = 15;
    *(_DWORD *)(*a1 + 24) = a1[14];
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  if ( (int)a1[15] > 10 )
  {
    *(_DWORD *)(*a1 + 20) = 26;
    *(_DWORD *)(*a1 + 24) = a1[15];
    *(_DWORD *)(*a1 + 28) = 10;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  v1 = a1[17];
  v2 = 0;
  v3 = a1[15] <= 0;
  a1[54] = 1;
  a1[55] = 1;
  if ( !v3 )
  {
    v4 = (int *)(v1 + 12);
    do
    {
      v5 = *(v4 - 1);
      if ( v5 <= 0 || v5 > 4 || *v4 <= 0 || *v4 > 4 )
      {
        *(_DWORD *)(*a1 + 20) = 18;
        (*(void (__cdecl **)(_DWORD *))*a1)(a1);
      }
      v6 = a1[54];
      if ( v6 <= *(v4 - 1) )
        v6 = *(v4 - 1);
      a1[54] = v6;
      v7 = a1[55];
      if ( v7 <= *v4 )
        v7 = *v4;
      ++v2;
      a1[55] = v7;
      v4 += 21;
    }
    while ( v2 < a1[15] );
  }
  v8 = 0;
  if ( (int)a1[15] > 0 )
  {
    v9 = a1[17] + 36;
    do
    {
      v10 = *(_DWORD *)(v9 - 28);
      *(_DWORD *)(v9 - 32) = v8;
      *(_DWORD *)v9 = 8;
      v11 = jdiv_round_up(a1: a1[7] * v10, a2: 8 * a1[54]);
      v12 = *(_DWORD *)(v9 - 24);
      *(_DWORD *)(v9 - 8) = v11;
      v13 = jdiv_round_up(a1: a1[8] * v12, a2: 8 * a1[55]);
      v14 = *(_DWORD *)(v9 - 28);
      *(_DWORD *)(v9 - 4) = v13;
      *(_DWORD *)(v9 + 4) = jdiv_round_up(a1: a1[7] * v14, a2: a1[54]);
      *(_DWORD *)(v9 + 8) = jdiv_round_up(a1: a1[8] * *(_DWORD *)(v9 - 24), a2: a1[55]);
      *(_BYTE *)(v9 + 12) = 1;
      ++v8;
      v9 += 84;
    }
    while ( v8 < a1[15] );
  }
  result = jdiv_round_up(a1: a1[8], a2: 8 * a1[55]);
  a1[56] = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A69A0
// Name: sub_101A69A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A69A0@<eax>(int a1@<esi>)
{
  int *v1; // ebx
  bool v2; // cc
  int result; // eax
  int v4; // eax
  int i; // edi
  int v6; // ebx
  signed int v7; // edi
  int v8; // eax
  unsigned int v9; // ecx
  unsigned int v10; // edx
  int v11; // eax
  _DWORD *v12; // ebx
  int *v13; // ebx
  int v14; // eax
  bool v15; // zf
  _DWORD *v16; // ebx
  unsigned __int8 *v17; // edi
  int v18; // edi
  unsigned __int8 *v19; // ebx
  int v20; // [esp+8h] [ebp-A30h]
  int v21; // [esp+Ch] [ebp-A2Ch]
  _DWORD *v22; // [esp+Ch] [ebp-A2Ch]
  int *v23; // [esp+10h] [ebp-A28h]
  int v24; // [esp+14h] [ebp-A24h]
  int v25; // [esp+14h] [ebp-A24h]
  signed int v26; // [esp+18h] [ebp-A20h]
  signed int v27; // [esp+1Ch] [ebp-A1Ch]
  unsigned int v28; // [esp+20h] [ebp-A18h]
  unsigned int v29; // [esp+24h] [ebp-A14h]
  unsigned __int8 v30[2560]; // [esp+28h] [ebp-A10h] BYREF
  unsigned __int8 dst[12]; // [esp+A28h] [ebp-10h] BYREF

  if ( *(int *)(a1 + 168) <= 0 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 19;
    *(_DWORD *)(*(_DWORD *)a1 + 24) = 0;
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  v1 = *(int **)(a1 + 172);
  v23 = v1;
  if ( v1[5] != 0 || v1[6] != 63 )
  {
    v2 = *(_DWORD *)(a1 + 60) <= 0;
    *(_BYTE *)(a1 + 212) = 1;
    if ( !v2 )
      memset(v30, 0xFFu, *(_DWORD *)(a1 + 60) << 8);
  }
  else
  {
    v2 = *(_DWORD *)(a1 + 60) <= 0;
    *(_BYTE *)(a1 + 212) = 0;
    if ( !v2 )
      memset(dst, value: 0, count: *(_DWORD *)(a1 + 60));
  }
  result = 1;
  v20 = 1;
  if ( *(int *)(a1 + 168) >= 1 )
  {
    do
    {
      v4 = *v1;
      v21 = *v1;
      if ( *v1 <= 0 || v4 > 4 )
      {
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 26;
        *(_DWORD *)(*(_DWORD *)a1 + 24) = v4;
        *(_DWORD *)(*(_DWORD *)a1 + 28) = 4;
        (**(void (__cdecl ***)(int))a1)(a1);
      }
      for ( i = 0; i < v21; ++i )
      {
        v6 = v1[i + 1];
        if ( v6 < 0 || v6 >= *(_DWORD *)(a1 + 60) )
        {
          *(_DWORD *)(*(_DWORD *)a1 + 20) = 19;
          *(_DWORD *)(*(_DWORD *)a1 + 24) = v20;
          (**(void (__cdecl ***)(int))a1)(a1);
        }
        if ( i > 0 && v6 <= v23[i] )
        {
          *(_DWORD *)(*(_DWORD *)a1 + 20) = 19;
          *(_DWORD *)(*(_DWORD *)a1 + 24) = v20;
          (**(void (__cdecl ***)(int))a1)(a1);
        }
        v1 = v23;
      }
      v7 = v1[5];
      v8 = v1[6];
      v9 = v1[7];
      v10 = v1[8];
      v27 = v7;
      v26 = v8;
      v28 = v9;
      v29 = v10;
      if ( *(_BYTE *)(a1 + 212) == 0 )
      {
        if ( v7 != 0 || v8 != 63 || v9 != 0 || v10 != 0 )
        {
          *(_DWORD *)(*(_DWORD *)a1 + 20) = 17;
          *(_DWORD *)(*(_DWORD *)a1 + 24) = v20;
          (**(void (__cdecl ***)(int))a1)(a1);
        }
        if ( v21 > 0 )
        {
          v16 = v1 + 1;
          v25 = v21;
          do
          {
            v17 = &dst[*v16];
            if ( *v17 != 0 )
            {
              *(_DWORD *)(*(_DWORD *)a1 + 20) = 19;
              *(_DWORD *)(*(_DWORD *)a1 + 24) = v20;
              (**(void (__cdecl ***)(int))a1)(a1);
            }
            ++v16;
            v15 = v25-- == 1;
            *v17 = 1;
          }
          while ( !v15 );
LABEL_59:
          v1 = v23;
        }
        goto LABEL_60;
      }
      if ( (unsigned int)v7 > 0x3F || v8 < v7 || v8 >= 64 || v9 > 0xA || v10 > 0xA )
      {
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 17;
        *(_DWORD *)(*(_DWORD *)a1 + 24) = v20;
        (**(void (__cdecl ***)(int))a1)(a1);
        v8 = v26;
      }
      if ( v7 != 0 )
      {
        if ( v21 == 1 )
          goto LABEL_33;
      }
      else if ( v8 == 0 )
      {
        goto LABEL_33;
      }
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 17;
      *(_DWORD *)(*(_DWORD *)a1 + 24) = v20;
      (**(void (__cdecl ***)(int))a1)(a1);
LABEL_33:
      v11 = v21;
      if ( v21 > 0 )
      {
        v12 = v1 + 1;
        v22 = v12;
        v24 = v11;
        while ( 1 )
        {
          v13 = (int *)&v30[256 * *v12];
          if ( v7 != 0 && *v13 < 0 )
          {
            *(_DWORD *)(*(_DWORD *)a1 + 20) = 17;
            *(_DWORD *)(*(_DWORD *)a1 + 24) = v20;
            (**(void (__cdecl ***)(int))a1)(a1);
          }
          if ( v27 <= v26 )
            break;
LABEL_47:
          v12 = v22 + 1;
          v15 = v24-- == 1;
          ++v22;
          if ( v15 )
            goto LABEL_59;
          v7 = v27;
        }
        while ( 2 )
        {
          v14 = v13[v7];
          if ( v14 >= 0 )
          {
            if ( v28 != v14 || v29 != v28 - 1 )
            {
LABEL_45:
              *(_DWORD *)(*(_DWORD *)a1 + 20) = 17;
              *(_DWORD *)(*(_DWORD *)a1 + 24) = v20;
              (**(void (__cdecl ***)(int))a1)(a1);
            }
          }
          else if ( v28 != 0 )
          {
            goto LABEL_45;
          }
          v13[v7++] = v29;
          if ( v7 > v26 )
            goto LABEL_47;
          continue;
        }
      }
LABEL_60:
      result = v20 + 1;
      v1 += 9;
      v2 = v20 + 1 <= *(_DWORD *)(a1 + 168);
      v23 = v1;
      ++v20;
    }
    while ( v2 );
  }
  v18 = 0;
  if ( *(_BYTE *)(a1 + 212) != 0 )
  {
    if ( *(int *)(a1 + 60) > 0 )
    {
      v19 = v30;
      do
      {
        if ( *(int *)v19 < 0 )
        {
          *(_DWORD *)(*(_DWORD *)a1 + 20) = 45;
          result = (**(int (__cdecl ***)(int))a1)(a1);
        }
        ++v18;
        v19 += 256;
      }
      while ( v18 < *(_DWORD *)(a1 + 60) );
    }
  }
  else if ( *(int *)(a1 + 60) > 0 )
  {
    do
    {
      if ( dst[v18] == 0 )
      {
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 45;
        result = (**(int (__cdecl ***)(int))a1)(a1);
      }
      ++v18;
    }
    while ( v18 < *(_DWORD *)(a1 + 60) );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A6DA0
// Name: sub_101A6DA0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A6DA0@<eax>(_DWORD *a1@<esi>)
{
  int v1; // ecx
  _DWORD *v2; // eax
  int v3; // ecx
  _DWORD *v4; // edi
  _DWORD *v5; // edx
  __int64 v6; // rax
  int v7; // ecx

  v1 = a1[43];
  if ( v1 != 0 )
  {
    v2 = (_DWORD *)(v1 + 36 * *(_DWORD *)(a1[79] + 28));
    a1[57] = *v2;
    v3 = 0;
    if ( (int)*v2 > 0 )
    {
      v4 = a1 + 58;
      v5 = v2 + 1;
      do
      {
        ++v3;
        *v4++ = a1[17] + 84 * *v5++;
      }
      while ( v3 < *v2 );
    }
    a1[75] = v2[5];
    a1[76] = v2[6];
    a1[77] = v2[7];
    LODWORD(v6) = v2[8];
    a1[78] = v6;
  }
  else
  {
    if ( (int)a1[15] > 4 )
    {
      *(_DWORD *)(*a1 + 20) = 26;
      *(_DWORD *)(*a1 + 24) = a1[15];
      *(_DWORD *)(*a1 + 28) = 4;
      (*(void (__cdecl **)(_DWORD *))*a1)(a1);
    }
    v6 = (unsigned int)a1[15];
    a1[57] = v6;
    if ( (int)v6 > 0 )
    {
      v7 = 0;
      LODWORD(v6) = a1 + 58;
      do
      {
        *(_DWORD *)v6 = v7 + a1[17];
        ++HIDWORD(v6);
        LODWORD(v6) = v6 + 4;
        v7 += 84;
      }
      while ( SHIDWORD(v6) < a1[15] );
    }
    a1[75] = 0;
    a1[77] = 0;
    a1[78] = 0;
    a1[76] = 63;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101A6E90
// Name: sub_101A6E90
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A6E90@<eax>(int *a1@<esi>)
{
  int v1; // eax
  _DWORD *v2; // ecx
  unsigned int v3; // edi
  int result; // eax
  int v5; // edx
  int v6; // eax
  int v7; // edx
  bool v8; // cc
  _DWORD *v9; // ecx
  unsigned int v10; // edi
  unsigned int v11; // ebp
  int v12; // edx
  int v13; // ebx
  unsigned int v14; // eax
  int v15; // edx
  int v16; // edi
  int v17; // ecx
  int v18; // [esp+8h] [ebp-8h]
  int *v19; // [esp+Ch] [ebp-4h]

  v1 = a1[57];
  if ( v1 == 1 )
  {
    v2 = (_DWORD *)a1[58];
    a1[62] = v2[7];
    a1[63] = v2[8];
    v3 = v2[3];
    result = v2[8] / v3;
    v5 = v2[8] % v3;
    v2[13] = 1;
    v2[14] = 1;
    v2[15] = 1;
    v2[16] = 8;
    v2[17] = 1;
    if ( v5 == 0 )
      v5 = v3;
    v2[18] = v5;
    a1[64] = 1;
    a1[65] = 0;
  }
  else
  {
    if ( v1 <= 0 || v1 > 4 )
    {
      *(_DWORD *)(*a1 + 20) = 26;
      *(_DWORD *)(*a1 + 24) = a1[57];
      *(_DWORD *)(*a1 + 28) = 4;
      (*(void (__cdecl **)(int *))*a1)(a1);
    }
    v6 = jdiv_round_up(a1: a1[7], a2: 8 * a1[54]);
    v7 = 8 * a1[55];
    a1[62] = v6;
    result = jdiv_round_up(a1: a1[8], a2: v7);
    v8 = a1[57] <= 0;
    a1[63] = result;
    a1[64] = 0;
    v18 = 0;
    if ( !v8 )
    {
      v19 = a1 + 58;
      do
      {
        v9 = (_DWORD *)*v19;
        v10 = *(_DWORD *)(*v19 + 8);
        v11 = *(_DWORD *)(*v19 + 12);
        v9[16] = 8 * v10;
        v12 = v9[7] % v10;
        v13 = v10 * v11;
        v9[13] = v10;
        v9[14] = v11;
        v9[15] = v10 * v11;
        if ( v12 == 0 )
          v12 = v10;
        v14 = v9[8];
        v9[17] = v12;
        v15 = v14 % v11;
        if ( v14 % v11 == 0 )
          v15 = v11;
        v9[18] = v15;
        v16 = v10 * v11;
        if ( v13 + a1[64] > 10 )
        {
          *(_DWORD *)(*a1 + 20) = 13;
          (*(void (__cdecl **)(int *))*a1)(a1);
        }
        if ( v13 > 0 )
        {
          do
          {
            --v16;
            a1[a1[64]++ + 65] = v18;
          }
          while ( v16 > 0 );
        }
        ++v19;
        result = ++v18;
      }
      while ( v18 < a1[57] );
    }
  }
  v17 = a1[48];
  if ( v17 > 0 )
  {
    result = v17 * a1[62];
    if ( result >= 0xFFFF )
      result = 0xFFFF;
    a1[47] = result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A7060
// Name: sub_101A7060
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A7060(int *a1)
{
  int v1; // edi
  int v2; // eax
  int v3; // eax
  int result; // eax

  v1 = a1[79];
  v2 = *(_DWORD *)(v1 + 16);
  if ( v2 != 0 )
  {
    v3 = v2 - 1;
    if ( v3 != 0 )
    {
      if ( v3 != 1 )
      {
        *(_DWORD *)(*a1 + 20) = 48;
        (*(void (__cdecl **)(int *))*a1)(a1);
        goto LABEL_18;
      }
    }
    else
    {
      sub_101A6DA0(a1);
      sub_101A6E90(a1);
      if ( a1[75] != 0 || a1[77] == 0 || *((_BYTE *)a1 + 177) != 0 )
      {
        (*(void (__cdecl **)(int *, int))a1[87])(a1, a2: 1);
        (*(void (__cdecl **)(int *, int))a1[82])(a1, a2: 2);
        *(_BYTE *)(v1 + 12) = 0;
        goto LABEL_18;
      }
      ++*(_DWORD *)(v1 + 20);
      *(_DWORD *)(v1 + 16) = 2;
    }
    if ( *((_BYTE *)a1 + 178) == 0 )
    {
      sub_101A6DA0(a1);
      sub_101A6E90(a1);
    }
    (*(void (__cdecl **)(int *, _DWORD))a1[87])(a1, a2: 0);
    (*(void (__cdecl **)(int *, int))a1[82])(a1, a2: 2);
    if ( *(_DWORD *)(v1 + 28) == 0 )
      (*(void (__cdecl **)(int *))(a1[83] + 4))(a1);
    (*(void (__cdecl **)(int *))(a1[83] + 8))(a1);
    *(_BYTE *)(v1 + 12) = 0;
  }
  else
  {
    sub_101A6DA0(a1);
    sub_101A6E90(a1);
    if ( *((_BYTE *)a1 + 176) == 0 )
    {
      (*(void (__cdecl **)(int *))a1[84])(a1);
      (*(void (__cdecl **)(int *))a1[85])(a1);
      (*(void (__cdecl **)(int *, _DWORD))a1[81])(a1, a2: 0);
    }
    (*(void (__cdecl **)(int *))a1[86])(a1);
    (*(void (__cdecl **)(int *, _DWORD))a1[87])(a1, a2: *((unsigned __int8 *)a1 + 178));
    (*(void (__cdecl **)(int *, int))a1[82])(a1, a2: *(_DWORD *)(v1 + 24) <= 1 ? 0 : 3);
    (*(void (__cdecl **)(int *, _DWORD))a1[80])(a1, a2: 0);
    *(_BYTE *)(v1 + 12) = *((_BYTE *)a1 + 178) == 0;
  }
LABEL_18:
  result = *(_DWORD *)(v1 + 20);
  *(_BYTE *)(v1 + 13) = result == *(_DWORD *)(v1 + 24) - 1;
  if ( a1[2] != 0 )
  {
    *(_DWORD *)(a1[2] + 12) = result;
    result = a1[2];
    *(_DWORD *)(result + 16) = *(_DWORD *)(v1 + 24);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A7210
// Name: sub_101A7210
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A7210(int a1)
{
  *(_BYTE *)(*(_DWORD *)(a1 + 316) + 12) = 0;
  (*(void (__cdecl **)(int))(*(_DWORD *)(a1 + 332) + 4))(a1);
  return (*(int (__cdecl **)(int))(*(_DWORD *)(a1 + 332) + 8))(a1);
}

//------------------------------------------------------------------------------
// Address: 0x101A7240
// Name: sub_101A7240
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A7240(int a1)
{
  _DWORD *v1; // esi
  int result; // eax

  v1 = *(_DWORD **)(a1 + 316);
  (*(void (__cdecl **)(int))(*(_DWORD *)(a1 + 348) + 8))(a1);
  result = v1[4];
  if ( result != 0 )
  {
    if ( --result == 0 )
    {
      ++v1[5];
      v1[4] = 2;
      return result;
    }
    if ( --result == 0 )
    {
      if ( *(_BYTE *)(a1 + 178) != 0 )
      {
        ++v1[7];
        ++v1[5];
        v1[4] = 1;
        return result;
      }
      goto LABEL_8;
    }
  }
  else
  {
    v1[4] = 2;
    if ( *(_BYTE *)(a1 + 178) == 0 )
LABEL_8:
      ++v1[7];
  }
  ++v1[5];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A72B0
// Name: void jinit_c_master_control(struct jpeg_compress_struct __near *,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jinit_c_master_control(int (__cdecl ***a1)(struct jpeg_compress_struct *, int, int), char a2)
{
  int v2; // edi

  v2 = (*a1[1])((struct jpeg_compress_struct *)a1, a2: 1, a3: 32);
  a1[79] = (int (__cdecl **)(struct jpeg_compress_struct *, int, int))v2;
  *(_DWORD *)v2 = sub_101A7060;
  *(_DWORD *)(v2 + 4) = sub_101A7210;
  *(_DWORD *)(v2 + 8) = sub_101A7240;
  *(_BYTE *)(v2 + 13) = 0;
  sub_101A67C0(a1);
  if ( a1[43] != nullptr )
  {
    sub_101A69A0((int)a1);
  }
  else
  {
    *((_BYTE *)a1 + 212) = 0;
    a1[42] = (int (__cdecl **)(struct jpeg_compress_struct *, int, int))1;
  }
  if ( *((_BYTE *)a1 + 212) != 0 )
    *((_BYTE *)a1 + 178) = 1;
  if ( a2 != 0 )
    *(_DWORD *)(v2 + 16) = 2 - (*((_BYTE *)a1 + 178) != 0);
  else
    *(_DWORD *)(v2 + 16) = 0;
  *(_DWORD *)(v2 + 28) = 0;
  *(_DWORD *)(v2 + 20) = 0;
  if ( *((_BYTE *)a1 + 178) != 0 )
    *(_DWORD *)(v2 + 24) = 2 * (_DWORD)a1[42];
  else
    *(_DWORD *)(v2 + 24) = a1[42];
}

//------------------------------------------------------------------------------
// Address: 0x101A7360
// Name: void __near * jpeg_get_large(struct jpeg_common_struct __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl jpeg_get_large(struct jpeg_common_struct *a1, unsigned int nSize)
{
  return MemAlloc_Alloc(nSize);
}

//------------------------------------------------------------------------------
// Address: 0x101A7370
// Name: void jpeg_free_small(struct jpeg_common_struct __near *,void __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_free_small(struct jpeg_common_struct *a1, void *pMem)
{
  free(pMem);
}

//------------------------------------------------------------------------------
// Address: 0x101A7380
// Name: long jpeg_mem_available(struct jpeg_common_struct __near *,long,long,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl jpeg_mem_available(struct jpeg_common_struct *a1, int a2, int a3)
{
  return a3;
}

//------------------------------------------------------------------------------
// Address: 0x101A7390
// Name: void jpeg_open_backing_store(struct jpeg_common_struct __near *,struct backing_store_struct __near *,long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_open_backing_store(struct jpeg_common_struct *a1)
{
  *(_DWORD *)(*(_DWORD *)a1 + 20) = 49;
  (**(void (__cdecl ***)(struct jpeg_common_struct *))a1)(a1);
}

//------------------------------------------------------------------------------
// Address: 0x101A73B0
// Name: sub_101A73B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A73B0@<eax>(int a1@<esi>)
{
  int v1; // ebp
  int v2; // edi
  int v3; // eax
  int result; // eax
  int v5; // ebx
  _DWORD *v6; // ebp
  int v7; // edi
  int v8; // eax
  int v9; // [esp+Ch] [ebp-Ch]
  int v10; // [esp+10h] [ebp-8h]
  int v11; // [esp+14h] [ebp-4h]

  v1 = *(_DWORD *)(a1 + 280);
  v2 = *(_DWORD *)(a1 + 388);
  v11 = v2;
  v3 = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, a2: 1, a3: 8 * *(_DWORD *)(a1 + 36));
  *(_DWORD *)(v2 + 56) = v3;
  *(_DWORD *)(v2 + 60) = v3 + 4 * *(_DWORD *)(a1 + 36);
  result = *(_DWORD *)(a1 + 196);
  v5 = 0;
  if ( *(int *)(a1 + 36) > 0 )
  {
    v9 = v1 + 4;
    v6 = (_DWORD *)(result + 12);
    do
    {
      v7 = *v6 * v6[6] / *(_DWORD *)(a1 + 280) * v9;
      v10 = *v6 * v6[6] / *(_DWORD *)(a1 + 280);
      v8 = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, a2: 1, a3: 8 * v7) + 4 * v10;
      *(_DWORD *)(*(_DWORD *)(v11 + 56) + 4 * v5) = v8;
      result = v8 + 4 * v7;
      *(_DWORD *)(*(_DWORD *)(v11 + 60) + 4 * v5++) = result;
      v6 += 21;
    }
    while ( v5 < *(_DWORD *)(a1 + 36) );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A7460
// Name: sub_101A7460
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A7460(int *a1)
{
  int *v1; // ecx
  int v2; // ebp
  _DWORD *v3; // esi
  int result; // eax
  _DWORD *v5; // edx
  _DWORD *v6; // edi
  int v7; // ebx
  int v8; // edx
  _DWORD *v9; // ecx
  int v10; // edi
  _DWORD *v11; // esi
  int v12; // edi
  _DWORD *v13; // ecx
  int v14; // edx
  int v15; // ebx
  _DWORD *v16; // ecx
  int v17; // [esp+8h] [ebp-20h]
  int *v18; // [esp+Ch] [ebp-1Ch]
  _DWORD *v19; // [esp+10h] [ebp-18h]
  int v20; // [esp+14h] [ebp-14h]
  int v21; // [esp+18h] [ebp-10h]
  _DWORD *v22; // [esp+1Ch] [ebp-Ch]
  _DWORD *v23; // [esp+20h] [ebp-8h]
  char *v24; // [esp+24h] [ebp-4h]

  v1 = a1;
  v2 = 0;
  v3 = (_DWORD *)a1[97];
  v21 = a1[70];
  result = a1[49];
  v23 = v3;
  v17 = 0;
  if ( a1[9] > 0 )
  {
    v5 = (_DWORD *)(result + 12);
    v19 = (_DWORD *)(result + 12);
    v18 = v3 + 2;
    while ( 1 )
    {
      result = *v5 * v5[6] / v1[70];
      v6 = *(_DWORD **)(v3[14] + 4 * v2);
      v7 = *v18;
      v8 = *(_DWORD *)(v3[15] + 4 * v2);
      v22 = v6;
      if ( result * (v21 + 2) > 0 )
      {
        v9 = *(_DWORD **)(v3[15] + 4 * v2);
        v24 = (char *)v6 - v8;
        v20 = result * (v21 + 2);
        do
        {
          v10 = *(_DWORD *)((char *)v9 + v7 - v8);
          *v9 = v10;
          *(_DWORD *)((char *)v9++ + (_DWORD)v24) = v10;
          --v20;
        }
        while ( v20 != 0 );
        v6 = v22;
        v2 = v17;
        v1 = a1;
      }
      if ( 2 * result > 0 )
      {
        v11 = (_DWORD *)(v8 + 4 * v21 * result);
        v12 = v7 - v8;
        v13 = (_DWORD *)(v7 + 4 * result * (v21 - 2));
        v14 = v8 - v7;
        v15 = 2 * result;
        do
        {
          *(_DWORD *)((char *)v13 + v14) = *(_DWORD *)((char *)v11 + v12);
          *v11++ = *v13++;
          --v15;
        }
        while ( v15 != 0 );
        v6 = v22;
        v2 = v17;
        v1 = a1;
      }
      if ( result > 0 )
      {
        v16 = &v6[-result];
        do
        {
          *v16++ = *v6;
          --result;
        }
        while ( result != 0 );
        v1 = a1;
      }
      ++v18;
      v19 += 21;
      v17 = ++v2;
      if ( v2 >= v1[9] )
        break;
      v5 = v19;
      v3 = v23;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A75B0
// Name: sub_101A75B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A75B0(int *a1)
{
  int *v1; // ebx
  int result; // eax
  int v3; // esi
  int v4; // edi
  _DWORD *v5; // ebp
  int v6; // ecx
  _DWORD *v7; // edi
  _DWORD *v8; // ebx
  _DWORD *v9; // edx
  _DWORD *v10; // esi
  int v11; // ecx
  int v12; // [esp+10h] [ebp-10h]
  _DWORD *v13; // [esp+14h] [ebp-Ch]
  int v14; // [esp+18h] [ebp-8h]
  int v15; // [esp+1Ch] [ebp-4h]

  v1 = a1;
  result = a1[70];
  v3 = 0;
  v4 = a1[97];
  v14 = v4;
  v15 = result;
  v12 = 0;
  if ( a1[9] > 0 )
  {
    v5 = (_DWORD *)(a1[49] + 12);
    v13 = v5;
    while ( 1 )
    {
      result = *v5 * v5[6] / v1[70];
      v6 = *(_DWORD *)(*(_DWORD *)(v4 + 56) + 4 * v3);
      v7 = *(_DWORD **)(*(_DWORD *)(v4 + 60) + 4 * v3);
      if ( result > 0 )
      {
        v8 = &v7[result * (v15 + 2)];
        v9 = &v7[-result];
        v10 = &v7[result * (v15 + 1)];
        v11 = v6 - (_DWORD)v7;
        do
        {
          *(_DWORD *)((char *)v9 + v11) = *(_DWORD *)((char *)v10 + v11);
          *v9 = *v10;
          *(_DWORD *)((char *)v8 + v11) = *(_DWORD *)((char *)v7 + v11);
          *v8 = *v7;
          ++v10;
          ++v9;
          ++v7;
          ++v8;
          --result;
        }
        while ( result != 0 );
        v3 = v12;
        v1 = a1;
        v5 = v13;
      }
      ++v3;
      v5 += 21;
      v12 = v3;
      v13 = v5;
      if ( v3 >= v1[9] )
        break;
      v4 = v14;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A7690
// Name: sub_101A7690
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__cdecl sub_101A7690(_DWORD *a1)
{
  _DWORD *v1; // esi
  _DWORD *result; // eax
  int v3; // ebp
  _DWORD *v4; // ebx
  int v5; // edi
  unsigned int v6; // esi
  int v7; // edx
  _DWORD *v8; // ecx
  _DWORD *v9; // [esp+Ch] [ebp-4h]

  v1 = a1;
  result = (_DWORD *)a1[97];
  v3 = 0;
  v9 = result;
  if ( (int)a1[9] > 0 )
  {
    v4 = (_DWORD *)(a1[49] + 12);
    while ( 1 )
    {
      v5 = *v4 * v4[6] / v1[70];
      v6 = v4[8] % (unsigned int)(*v4 * v4[6]);
      if ( v6 == 0 )
        v6 = *v4 * v4[6];
      if ( v3 == 0 )
        v9[18] = (int)(v6 - 1) / v5 + 1;
      result = *(_DWORD **)(v9[v9[16] + 14] + 4 * v3);
      v7 = 2 * v5;
      if ( 2 * v5 > 0 )
      {
        v8 = &result[v6];
        result = v8;
        do
        {
          *result++ = *(v8 - 1);
          --v7;
        }
        while ( v7 != 0 );
      }
      ++v3;
      v4 += 21;
      if ( v3 >= a1[9] )
        break;
      v1 = a1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A7740
// Name: sub_101A7740
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A7740(_DWORD *a1, int a2, int a3, int a4)
{
  int v4; // esi
  int result; // eax
  unsigned int v6; // ebp

  v4 = a1[97];
  if ( *(_BYTE *)(v4 + 48) == 0 )
  {
    result = (*(int (__cdecl **)(_DWORD *, int))(a1[98] + 12))(a1, a2: v4 + 8);
    if ( result == 0 )
      return result;
    *(_BYTE *)(v4 + 48) = 1;
  }
  v6 = a1[70];
  result = (*(int (__cdecl **)(_DWORD *, int, int, unsigned int, int, int, int))(a1[99] + 4))(
             a1,
             a2: v4 + 8,
             a3: v4 + 52,
             a4: v6,
             a5: a2,
             a6: a3,
             a7: a4);
  if ( *(_DWORD *)(v4 + 52) >= v6 )
  {
    *(_BYTE *)(v4 + 48) = 0;
    *(_DWORD *)(v4 + 52) = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A77B0
// Name: sub_101A77B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A77B0(int *a1, int a2, unsigned int *a3, unsigned int a4)
{
  int v4; // esi
  int result; // eax
  int v6; // eax
  int v7; // eax
  int v8; // ecx

  v4 = a1[97];
  if ( *(_BYTE *)(v4 + 48) == 0 )
  {
    result = (*(int (__cdecl **)(int *, _DWORD))(a1[98] + 12))(a1, a2: *(_DWORD *)(v4 + 4 * *(_DWORD *)(v4 + 64) + 56));
    if ( result == 0 )
      return result;
    ++*(_DWORD *)(v4 + 76);
    *(_BYTE *)(v4 + 48) = 1;
  }
  v6 = *(_DWORD *)(v4 + 68);
  if ( v6 == 0 )
  {
LABEL_9:
    v8 = *(_DWORD *)(v4 + 76);
    *(_DWORD *)(v4 + 52) = 0;
    *(_DWORD *)(v4 + 72) = a1[70] - 1;
    if ( v8 == a1[71] )
      sub_101A7690(a1);
    *(_DWORD *)(v4 + 68) = 1;
    goto LABEL_12;
  }
  v7 = v6 - 1;
  if ( v7 != 0 )
  {
    result = v7 - 1;
    if ( result != 0 )
      return result;
    result = (*(int (__cdecl **)(int *, _DWORD, int, _DWORD, int, unsigned int *, unsigned int))(a1[99] + 4))(
               a1,
               a2: *(_DWORD *)(v4 + 4 * *(_DWORD *)(v4 + 64) + 56),
               a3: v4 + 52,
               a4: *(_DWORD *)(v4 + 72),
               a5: a2,
               a6: a3,
               a7: a4);
    if ( *(_DWORD *)(v4 + 52) < *(_DWORD *)(v4 + 72) )
      return result;
    *(_DWORD *)(v4 + 68) = 0;
    if ( *a3 >= a4 )
      return result;
    goto LABEL_9;
  }
LABEL_12:
  result = (*(int (__cdecl **)(int *, _DWORD, int, _DWORD, int, unsigned int *, unsigned int))(a1[99] + 4))(
             a1,
             a2: *(_DWORD *)(v4 + 4 * *(_DWORD *)(v4 + 64) + 56),
             a3: v4 + 52,
             a4: *(_DWORD *)(v4 + 72),
             a5: a2,
             a6: a3,
             a7: a4);
  if ( *(_DWORD *)(v4 + 52) >= *(_DWORD *)(v4 + 72) )
  {
    if ( *(_DWORD *)(v4 + 76) == 1 )
      sub_101A75B0(a1);
    *(_DWORD *)(v4 + 64) ^= 1u;
    *(_BYTE *)(v4 + 48) = 0;
    result = a1[70] + 1;
    *(_DWORD *)(v4 + 52) = result;
    *(_DWORD *)(v4 + 72) = a1[70] + 2;
    *(_DWORD *)(v4 + 68) = 2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A7920
// Name: sub_101A7920
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A7920(int *a1, int a2)
{
  int result; // eax
  int v3; // esi

  result = (int)a1;
  v3 = a1[97];
  if ( a2 != 0 )
  {
    if ( a2 == 2 )
    {
      *(_DWORD *)(v3 + 4) = sub_101A78F0;
    }
    else
    {
      *(_DWORD *)(*a1 + 20) = 4;
      return (*(int (__cdecl **)(int *))*a1)(a1);
    }
  }
  else if ( *(_BYTE *)(a1[104] + 8) != 0 )
  {
    *(_DWORD *)(v3 + 4) = sub_101A77B0;
    result = sub_101A7460(a1);
    *(_DWORD *)(v3 + 64) = 0;
    *(_DWORD *)(v3 + 68) = 0;
    *(_DWORD *)(v3 + 76) = 0;
    *(_BYTE *)(v3 + 48) = 0;
    *(_DWORD *)(v3 + 52) = 0;
  }
  else
  {
    *(_BYTE *)(v3 + 48) = 0;
    *(_DWORD *)(v3 + 52) = 0;
    *(_DWORD *)(v3 + 4) = sub_101A7740;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A79A0
// Name: void jinit_d_main_controller(struct jpeg_decompress_struct __near *,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jinit_d_main_controller(struct jpeg_decompress_struct *a1, unsigned __int8 a2)
{
  int (__cdecl **v2)(int *, int); // ebx
  int v3; // eax
  int v4; // ebp
  _DWORD *v5; // edi
  _DWORD *v6; // ebx
  int v7; // [esp+14h] [ebp+8h]

  v2 = (int (__cdecl **)(int *, int))(**((int (__cdecl ***)(struct jpeg_decompress_struct *, int, int))a1 + 1))(
                                       a1,
                                       a2: 1,
                                       a3: 80);
  *((_DWORD *)a1 + 97) = v2;
  *v2 = sub_101A7920;
  if ( a2 != 0 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 4;
    (**(void (__cdecl ***)(struct jpeg_decompress_struct *))a1)(a1);
  }
  if ( *(_BYTE *)(*((_DWORD *)a1 + 104) + 8) != 0 )
  {
    if ( *((int *)a1 + 70) < 2 )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 47;
      (**(void (__cdecl ***)(struct jpeg_decompress_struct *))a1)(a1);
    }
    sub_101A73B0((int)a1);
    v3 = *((_DWORD *)a1 + 70) + 2;
  }
  else
  {
    v3 = *((_DWORD *)a1 + 70);
  }
  v4 = 0;
  v7 = v3;
  if ( *((int *)a1 + 9) > 0 )
  {
    v5 = (_DWORD *)(*((_DWORD *)a1 + 49) + 36);
    v6 = v2 + 2;
    do
    {
      *v6 = (*(int (__cdecl **)(struct jpeg_decompress_struct *, int, int, int))(*((_DWORD *)a1 + 1) + 8))(
              a1,
              a2: 1,
              a3: *v5 * *(v5 - 2),
              a4: v7 * (*v5 * *(v5 - 6) / *((_DWORD *)a1 + 70)));
      ++v4;
      ++v6;
      v5 += 21;
    }
    while ( v4 < *((_DWORD *)a1 + 9) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A7A80
// Name: sub_101A7A80
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A7A80(int *a1)
{
  int *v1; // ebx
  int result; // eax
  int v3; // ebp
  _DWORD *v4; // esi
  int v5; // edi
  int v6; // eax
  int v7; // eax
  int v8; // esi
  int v9; // edx
  double *v10; // eax
  int v11; // ecx
  int *v12; // ecx
  unsigned __int16 *v13; // eax
  __int16 *v14; // edx
  int v15; // esi
  int v16; // ecx
  int i; // eax
  bool v18; // cc
  void (__cdecl *v19)(struct jpeg_decompress_struct *, struct jpeg_component_info *, __int16 *, unsigned __int8 **, unsigned int); // [esp+8h] [ebp-14h]
  int v20; // [esp+Ch] [ebp-10h]
  int *v21; // [esp+10h] [ebp-Ch]
  int v22; // [esp+14h] [ebp-8h]
  int v23; // [esp+18h] [ebp-4h]

  v1 = a1;
  result = a1[103];
  v3 = 0;
  v20 = 0;
  v19 = nullptr;
  v22 = 0;
  if ( a1[9] > 0 )
  {
    v4 = (_DWORD *)(result + 44);
    v5 = a1[49] + 36;
    v21 = (int *)(result + 44);
    do
    {
      switch ( *(_DWORD *)v5 )
      {
        case 1:
          v3 = 0;
          v19 = jpeg_idct_1x1;
          v20 = 0;
          break;
        case 2:
          v3 = 0;
          v19 = jpeg_idct_2x2;
          v20 = 0;
          break;
        case 4:
          v3 = 0;
          v19 = jpeg_idct_4x4;
          v20 = 0;
          break;
        case 8:
          v6 = v1[17];
          if ( v6 != 0 )
          {
            v7 = v6 - 1;
            if ( v7 != 0 )
            {
              if ( v7 == 1 )
              {
                v3 = 2;
                v19 = jpeg_idct_float;
                v20 = 2;
              }
              else
              {
                *(_DWORD *)(*v1 + 20) = 48;
                (*(void (__cdecl **)(int *))*v1)(a1: v1);
              }
            }
            else
            {
              v3 = 1;
              v19 = jpeg_idct_ifast;
              v20 = 1;
            }
          }
          else
          {
            v3 = 0;
            v19 = jpeg_idct_islow;
            v20 = 0;
          }
          break;
        default:
          *(_DWORD *)(*v1 + 20) = 7;
          *(_DWORD *)(*v1 + 24) = *(_DWORD *)v5;
          (*(void (__cdecl **)(int *))*v1)(a1: v1);
          break;
      }
      *(v4 - 10) = v19;
      if ( *(_BYTE *)(v5 + 12) != 0 && *v4 != v3 )
      {
        v8 = *(_DWORD *)(v5 + 40);
        if ( v8 != 0 )
        {
          *v21 = v3;
          if ( v3 != 0 )
          {
            if ( v3 == 1 )
            {
              v12 = (int *)(*(_DWORD *)(v5 + 44) + 8);
              v13 = (unsigned __int16 *)(v8 + 4);
              v14 = &word_102ACCEA;
              v15 = -v8;
              do
              {
                *(v12 - 2) = (*(v13 - 2) * *(v14 - 1) + 2048) >> 12;
                *(v12 - 1) = (*v14 * *(v13 - 1) + 2048) >> 12;
                *v12 = (*v13 * *(__int16 *)((char *)&word_102ACCE8 + (_DWORD)v13 + v15) + 2048) >> 12;
                v12[1] = (v13[1] * *(__int16 *)((char *)&word_102ACCEA + (_DWORD)v13 + v15) + 2048) >> 12;
                v14 += 4;
                v12 += 4;
                v13 += 4;
              }
              while ( (int)v14 < (int)((__int16 *)&DOUBLE_16384_5 + 1) );
              v3 = v20;
              v1 = a1;
            }
            else
            {
              v9 = *(_DWORD *)(v5 + 44) + 8;
              v10 = &dbl_102ACB98;
              v11 = v8 + 4;
              do
              {
                v23 = *(unsigned __int16 *)(v11 - 4);
                ++v10;
                v11 += 16;
                v9 += 32;
                *(float *)(v9 - 40) = (double)v23 * *(v10 - 1);
                *(float *)(v9 - 36) = (double)*(unsigned __int16 *)(v11 - 18) * *(v10 - 1) * 1.387039845;
                *(float *)(v9 - 32) = (double)*(unsigned __int16 *)(v11 - 16) * *(v10 - 1) * 1.306562965;
                *(float *)(v9 - 28) = (double)*(unsigned __int16 *)(v11 - 14) * *(v10 - 1) * 1.175875602;
                *(float *)(v9 - 24) = (double)*(unsigned __int16 *)(v11 - 12) * *(v10 - 1);
                *(float *)(v9 - 20) = (double)*(unsigned __int16 *)(v11 - 10) * *(v10 - 1) * 0.785694958;
                *(float *)(v9 - 16) = (double)*(unsigned __int16 *)(v11 - 8) * *(v10 - 1) * 0.5411961;
                *(float *)(v9 - 12) = (double)*(unsigned __int16 *)(v11 - 6) * *(v10 - 1) * 0.275899379;
              }
              while ( (int)v10 < (int)dbl_102ACBD8 );
            }
          }
          else
          {
            v16 = *(_DWORD *)(v5 + 44);
            for ( i = 0; i < 64; ++i )
              *(_DWORD *)(v16 + 4 * i) = *(unsigned __int16 *)(v8 + 2 * i);
          }
        }
      }
      result = v22 + 1;
      v4 = v21 + 1;
      v5 += 84;
      v18 = ++v22 < v1[9];
      ++v21;
    }
    while ( v18 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A7DA0
// Name: void jinit_inverse_dct(struct jpeg_decompress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jinit_inverse_dct(int (__cdecl ***a1)(struct jpeg_decompress_struct *, int, int))
{
  int (__cdecl **v1)(int *); // eax
  int v2; // edi
  unsigned __int8 **v3; // ebp
  _DWORD *v4; // ebx
  unsigned __int8 *v5; // eax

  v1 = (int (__cdecl **)(int *))(*a1[1])((struct jpeg_decompress_struct *)a1, a2: 1, a3: 84);
  a1[103] = (int (__cdecl **)(struct jpeg_decompress_struct *, int, int))v1;
  *v1 = sub_101A7A80;
  v2 = 0;
  if ( (int)a1[9] > 0 )
  {
    v3 = (unsigned __int8 **)(a1[49] + 20);
    v4 = v1 + 11;
    do
    {
      v5 = (unsigned __int8 *)(*a1[1])((struct jpeg_decompress_struct *)a1, a2: 1, a3: 256);
      *v3 = v5;
      memset(dst: v5, value: 0, count: 0x100u);
      *v4 = -1;
      ++v2;
      ++v4;
      v3 += 21;
    }
    while ( v2 < (int)a1[9] );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A7E20
// Name: sub_101A7E20
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A7E20(int a1, int a2, int a3, int a4, int a5, _DWORD *a6, int a7)
{
  _DWORD *v7; // ebx
  unsigned int v8; // eax
  int v9; // esi
  int v10; // edi
  int v11; // ecx
  int result; // eax

  v7 = a6;
  v8 = a7 - *a6;
  v9 = a1;
  v10 = *(_DWORD *)(a1 + 396);
  if ( v8 > *(_DWORD *)(v10 + 16) )
    v8 = *(_DWORD *)(v10 + 16);
  v11 = *(_DWORD *)(a1 + 416);
  a1 = 0;
  (*(void (__cdecl **)(int, int, int, int, _DWORD, int *, unsigned int))(v11 + 4))(
    a1: v9,
    a2,
    a3,
    a4,
    a5: *(_DWORD *)(v10 + 12),
    a6: &a1,
    a7: v8);
  result = (*(int (__cdecl **)(int, _DWORD, int, int))(*(_DWORD *)(v9 + 424) + 4))(
             a1: v9,
             a2: *(_DWORD *)(v10 + 12),
             a3: a5 + 4 * *v7,
             a4: a1);
  *v7 += a1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A7EA0
// Name: sub_101A7EA0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl sub_101A7EA0(_DWORD *a1, int a2, int a3, int a4, int a5, _DWORD *a6)
{
  _DWORD *v7; // esi
  unsigned int *v8; // ebx
  unsigned int v9; // ebp
  unsigned int v10; // eax
  unsigned int result; // eax
  unsigned int v12; // [esp+10h] [ebp+4h]

  v7 = (_DWORD *)a1[99];
  v8 = v7 + 6;
  if ( v7[6] == 0 )
    v7[3] = (*(int (__cdecl **)(_DWORD *, _DWORD, _DWORD, _DWORD, int))(a1[1] + 28))(
              a1,
              a2: v7[2],
              a3: v7[5],
              a4: v7[4],
              a5: 1);
  v9 = *v8;
  (*(void (__cdecl **)(_DWORD *, int, int, int, _DWORD, _DWORD *, _DWORD))(a1[104] + 4))(
    a1,
    a2,
    a3,
    a4,
    a5: v7[3],
    a6: v7 + 6,
    a7: v7[4]);
  v10 = *v8;
  if ( *v8 > v9 )
  {
    v12 = v10 - v9;
    (*(void (__cdecl **)(_DWORD *, unsigned int, _DWORD, unsigned int))(a1[106] + 4))(
      a1,
      a2: v7[3] + 4 * v9,
      a3: 0,
      a4: v10 - v9);
    *a6 += v12;
  }
  result = v7[4];
  if ( *v8 >= result )
  {
    v7[5] += result;
    *v8 = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A7F50
// Name: sub_101A7F50
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl sub_101A7F50(_DWORD *a1, int a2, int a3, int a4, int a5, _DWORD *a6, int a7)
{
  _DWORD *v7; // esi
  unsigned int v8; // edi
  unsigned int result; // eax

  v7 = (_DWORD *)a1[99];
  if ( v7[6] == 0 )
    v7[3] = (*(int (__cdecl **)(_DWORD *, _DWORD, _DWORD, _DWORD, _DWORD))(a1[1] + 28))(
              a1,
              a2: v7[2],
              a3: v7[5],
              a4: v7[4],
              a5: 0);
  v8 = v7[4] - v7[6];
  if ( v8 > a7 - *a6 )
    v8 = a7 - *a6;
  if ( v8 > a1[24] - v7[5] )
    v8 = a1[24] - v7[5];
  (*(void (__cdecl **)(_DWORD *, int, int, unsigned int))(a1[106] + 4))(
    a1,
    a2: v7[3] + 4 * v7[6],
    a3: a5 + 4 * *a6,
    a4: v8);
  *a6 += v8;
  v7[6] += v8;
  result = v7[4];
  if ( v7[6] >= result )
  {
    v7[5] += result;
    v7[6] = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A7FF0
// Name: sub_101A7FF0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A7FF0(int a1, int a2)
{
  int result; // eax
  _DWORD *v3; // esi
  bool v4; // zf

  result = a1;
  v3 = *(_DWORD **)(a1 + 396);
  if ( a2 != 0 )
  {
    if ( a2 == 2 )
    {
      if ( v3[2] == 0 )
      {
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 4;
        result = (**(int (__cdecl ***)(int))a1)(a1);
      }
      v3[1] = sub_101A7F50;
      v3[6] = 0;
      v3[5] = 0;
    }
    else if ( a2 == 3 )
    {
      if ( v3[2] == 0 )
      {
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 4;
        result = (**(int (__cdecl ***)(int))a1)(a1);
      }
      v3[1] = sub_101A7EA0;
      v3[6] = 0;
      v3[5] = 0;
    }
    else
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 4;
      result = (**(int (__cdecl ***)(int))a1)(a1);
      v3[6] = 0;
      v3[5] = 0;
    }
  }
  else
  {
    if ( *(_BYTE *)(a1 + 74) != 0 )
    {
      v4 = v3[3] == 0;
      v3[1] = sub_101A7E20;
      if ( v4 )
      {
        result = (*(int (__cdecl **)(int, _DWORD, _DWORD, _DWORD, int))(*(_DWORD *)(a1 + 4) + 28))(
                   a1,
                   a2: v3[2],
                   a3: 0,
                   a4: v3[4],
                   a5: 1);
        v3[3] = result;
        v3[6] = 0;
        v3[5] = 0;
        return result;
      }
    }
    else
    {
      v3[1] = *(_DWORD *)(*(_DWORD *)(a1 + 416) + 4);
    }
    v3[6] = 0;
    v3[5] = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A80F0
// Name: void jinit_d_post_controller(struct jpeg_decompress_struct __near *,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jinit_d_post_controller(struct jpeg_decompress_struct *a1, char a2)
{
  int (__cdecl **v2)(int, int); // edi
  int v3; // eax
  int v4; // ebp
  int v5; // eax
  int v6; // [esp-8h] [ebp-10h]

  v2 = (int (__cdecl **)(int, int))(**((int (__cdecl ***)(struct jpeg_decompress_struct *, int, int))a1 + 1))(
                                     a1,
                                     a2: 1,
                                     a3: 28);
  *((_DWORD *)a1 + 99) = v2;
  *v2 = sub_101A7FF0;
  v2[2] = nullptr;
  v2[3] = nullptr;
  if ( *((_BYTE *)a1 + 74) != 0 )
  {
    v3 = *((_DWORD *)a1 + 69);
    v2[4] = (int (__cdecl *)(int, int))v3;
    if ( a2 != 0 )
    {
      v4 = *((_DWORD *)a1 + 1);
      v6 = v3;
      v5 = jround_up(a1: *((_DWORD *)a1 + 24), a2: v3);
      v2[2] = (int (__cdecl *)(int, int))(*(int (__cdecl **)(struct jpeg_decompress_struct *, int, _DWORD, int, int, int))(v4 + 16))(
                                           a1,
                                           a2: 1,
                                           a3: 0,
                                           a4: *((_DWORD *)a1 + 23) * *((_DWORD *)a1 + 25),
                                           a5: v5,
                                           a6: v6);
    }
    else
    {
      v2[3] = (int (__cdecl *)(int, int))(*(int (__cdecl **)(struct jpeg_decompress_struct *, int, int, int))(*((_DWORD *)a1 + 1) + 8))(
                                           a1,
                                           a2: 1,
                                           a3: *((_DWORD *)a1 + 23) * *((_DWORD *)a1 + 25),
                                           a4: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A8190
// Name: sub_101A8190
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A8190(_DWORD *a1)
{
  int v1; // ecx
  int result; // eax

  v1 = a1[104];
  *(_DWORD *)(v1 + 92) = a1[69];
  result = a1[24];
  *(_DWORD *)(v1 + 96) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A81B0
// Name: sub_101A81B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A81B0(_DWORD *a1, int a2, _DWORD *a3, int a4, int a5, _DWORD *a6, int a7)
{
  int v8; // ebp
  int v9; // ebx
  bool v10; // cc
  int v11; // esi
  unsigned int v12; // esi
  int result; // eax
  int v14; // [esp+14h] [ebp+4h]

  v8 = a1[104];
  if ( *(_DWORD *)(v8 + 92) >= a1[69] )
  {
    v9 = 0;
    v10 = a1[9] <= 0;
    v14 = a1[49];
    if ( !v10 )
    {
      v11 = v8 + 12;
      do
      {
        (*(void (__cdecl **)(_DWORD *, int, int, int))(v11 + 40))(
          a1,
          a2: v14,
          a3: *(_DWORD *)(a2 + 4 * v9) + 4 * *a3 * *(_DWORD *)(v11 + 88),
          a4: v11);
        v14 += 84;
        ++v9;
        v11 += 4;
      }
      while ( v9 < a1[9] );
    }
    *(_DWORD *)(v8 + 92) = 0;
  }
  v12 = a1[69] - *(_DWORD *)(v8 + 92);
  if ( v12 > *(_DWORD *)(v8 + 96) )
    v12 = *(_DWORD *)(v8 + 96);
  if ( v12 > a7 - *a6 )
    v12 = a7 - *a6;
  result = (*(int (__cdecl **)(_DWORD *, int, _DWORD, int, unsigned int))(a1[105] + 4))(
             a1,
             a2: v8 + 12,
             a3: *(_DWORD *)(v8 + 92),
             a4: a5 + 4 * *a6,
             a5: v12);
  *a6 += v12;
  *(_DWORD *)(v8 + 96) -= v12;
  *(_DWORD *)(v8 + 92) += v12;
  if ( *(_DWORD *)(v8 + 92) >= a1[69] )
  {
    ++*a3;
    return (int)a3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A8284
// Name: sub_101A8284
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__usercall sub_101A8284@<eax>(_DWORD *result@<eax>, int a2, int a3, int a4)
{
  *result = a4;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A8290
// Name: sub_101A8290
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__cdecl sub_101A8290(int a1, int a2, int a3, _DWORD *a4)
{
  *a4 = 0;
  return a4;
}

//------------------------------------------------------------------------------
// Address: 0x101A82A0
// Name: sub_101A82A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
signed int __cdecl sub_101A82A0(int a1, int a2, unsigned __int8 **a3, unsigned __int8 ***a4)
{
  int v4; // ecx
  int v5; // edx
  signed int result; // eax
  int v7; // edx
  int v8; // ebx
  unsigned __int8 *v9; // ebp
  unsigned __int8 *v10; // esi
  unsigned __int8 *v11; // edi
  unsigned __int8 v12; // dl
  unsigned __int8 **v13; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  signed int v16; // [esp+20h] [ebp+10h]

  v4 = a1;
  v13 = *a4;
  v5 = *(_DWORD *)(a1 + 416) + *(_DWORD *)(a2 + 4);
  result = *(unsigned __int8 *)(v5 + 140);
  v7 = *(unsigned __int8 *)(v5 + 150);
  v8 = 0;
  v16 = result;
  for ( i = v7; v8 < *(_DWORD *)(v4 + 276); v8 += i )
  {
    v9 = *a3;
    v10 = v13[v8];
    v11 = &v10[*(_DWORD *)(v4 + 92)];
    if ( v10 < v11 )
    {
      do
      {
        v12 = *v9++;
        if ( result > 0 )
        {
          memset(dst: v10, value: v12, count: result);
          v4 = a1;
          result = v16;
          v10 += v16;
        }
      }
      while ( v10 < v11 );
      v7 = i;
    }
    if ( v7 > 1 )
    {
      jcopy_sample_rows(a1: v13, a2: v8, a3: v13, a4: v8 + 1, a5: v7 - 1, count: *(_DWORD *)(v4 + 92));
      v4 = a1;
      result = v16;
    }
    v7 = i;
    ++a3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A8380
// Name: sub_101A8380
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl sub_101A8380(int a1, int a2, int a3, char *a4)
{
  char *result; // eax
  int v5; // ebp
  char **v6; // edi
  int v7; // edx
  char *v8; // esi
  unsigned int v9; // ecx
  char v10; // dl
  _BYTE *v11; // eax
  int v12; // [esp+1Ch] [ebp+10h]

  result = a4;
  v5 = 0;
  v6 = *(char ***)a4;
  if ( *(int *)(a1 + 276) > 0 )
  {
    v7 = a3 - (_DWORD)v6;
    v12 = a3 - (_DWORD)v6;
    do
    {
      result = *v6;
      v8 = *(char **)((char *)v6 + v7);
      v9 = (unsigned int)&(*v6)[*(_DWORD *)(a1 + 92)];
      if ( (unsigned int)*v6 < v9 )
      {
        do
        {
          v10 = *v8;
          *result = *v8;
          v11 = result + 1;
          *v11 = v10;
          result = v11 + 1;
          ++v8;
        }
        while ( (unsigned int)result < v9 );
        v7 = v12;
      }
      ++v5;
      ++v6;
    }
    while ( v5 < *(_DWORD *)(a1 + 276) );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A83E0
// Name: sub_101A83E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_101A83E0(int a1, int a2, unsigned __int8 **a3, unsigned __int8 ***a4)
{
  unsigned __int8 **v4; // ebx
  int i; // esi
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // edi
  unsigned __int8 *j; // ecx
  unsigned __int8 v9; // dl
  unsigned __int8 *v10; // eax

  v4 = *a4;
  for ( i = 0; i < *(_DWORD *)(a1 + 276); i += 2 )
  {
    v6 = v4[i];
    v7 = *a3;
    for ( j = &v6[*(_DWORD *)(a1 + 92)]; v6 < j; ++v7 )
    {
      v9 = *v7;
      *v6 = *v7;
      v10 = v6 + 1;
      *v10 = v9;
      v6 = v10 + 1;
    }
    jcopy_sample_rows(a1: v4, a2: i, a3: v4, a4: i + 1, a5: 1, count: *(_DWORD *)(a1 + 92));
    ++a3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A8520
// Name: sub_101A8520
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A8520(int a1, int a2, unsigned __int8 **a3, int *a4)
{
  int result; // eax
  unsigned __int8 **v5; // esi
  int v6; // ecx
  unsigned __int8 *v7; // ebp
  unsigned __int8 *v8; // edi
  int v9; // esi
  _BYTE *v10; // ecx
  unsigned __int8 *v11; // ebp
  int v12; // esi
  int v13; // eax
  unsigned __int8 *v14; // edi
  unsigned __int8 *v15; // ebp
  _BYTE *v16; // ecx
  int v17; // edx
  int v18; // esi
  _BYTE *v19; // ecx
  bool v20; // zf
  int v21; // [esp+0h] [ebp-10h]
  int i; // [esp+4h] [ebp-Ch]
  int v23; // [esp+8h] [ebp-8h]
  int v24; // [esp+Ch] [ebp-4h]
  unsigned __int8 **v25; // [esp+20h] [ebp+10h]

  result = 0;
  v24 = *a4;
  if ( *(int *)(a1 + 276) > 0 )
  {
    v5 = a3;
    v25 = a3;
    do
    {
      v6 = 0;
      for ( i = 0; i < 2; ++i )
      {
        v7 = *v5;
        if ( v6 != 0 )
          v8 = v5[1];
        else
          v8 = *(v5 - 1);
        v9 = *v7;
        v10 = *(_BYTE **)(v24 + 4 * result);
        v11 = v7 + 1;
        v23 = result + 1;
        v12 = *v8 + 3 * v9;
        v13 = v8[1] + 3 * *v11;
        *v10++ = (4 * v12 + 8) >> 4;
        *v10 = (v12 + v13 + 2 * v12 + 7) >> 4;
        v14 = v8 + 2;
        v15 = v11 + 1;
        v16 = v10 + 1;
        v17 = v12;
        v18 = v13;
        v21 = *(_DWORD *)(a2 + 40) - 2;
        if ( *(_DWORD *)(a2 + 40) != 2 )
        {
          do
          {
            v13 = *v14 + 3 * *v15;
            *v16 = (3 * v18 + v17 + 8) >> 4;
            v19 = v16 + 1;
            *v19 = (3 * v18 + v13 + 7) >> 4;
            ++v14;
            ++v15;
            v16 = v19 + 1;
            v20 = v21-- == 1;
            v17 = v18;
            v18 = v13;
          }
          while ( !v20 );
        }
        v5 = v25;
        *v16 = (v13 + v17 + 2 * v13 + 8) >> 4;
        v16[1] = (4 * v13 + 7) >> 4;
        result = v23;
        v6 = i + 1;
      }
      v5 = ++v25;
    }
    while ( v23 < *(_DWORD *)(a1 + 276) );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A8660
// Name: void jinit_upsampler(struct jpeg_decompress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jinit_upsampler(struct jpeg_decompress_struct *a1)
{
  int v2; // ebp
  int v3; // ebx
  _DWORD *v4; // ebp
  int v5; // edi
  int v6; // edx
  int v7; // ecx
  int v8; // eax
  int v9; // edx
  int (__cdecl **v10)(struct jpeg_decompress_struct *, int, int, int); // edi
  int v11; // eax
  int v12; // [esp-8h] [ebp-24h]
  int v13; // [esp+Ch] [ebp-10h]
  int v14; // [esp+10h] [ebp-Ch]
  int v15; // [esp+10h] [ebp-Ch]
  int v16; // [esp+14h] [ebp-8h]
  int v17; // [esp+18h] [ebp-4h]
  char v18; // [esp+20h] [ebp+4h]

  v2 = (**((int (__cdecl ***)(struct jpeg_decompress_struct *, int, int))a1 + 1))(a1, a2: 1, a3: 160);
  *((_DWORD *)a1 + 104) = v2;
  *(_DWORD *)v2 = sub_101A8190;
  *(_DWORD *)(v2 + 4) = sub_101A81B0;
  *(_BYTE *)(v2 + 8) = 0;
  v17 = v2;
  if ( *((_BYTE *)a1 + 266) != 0 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 25;
    (**(void (__cdecl ***)(struct jpeg_decompress_struct *))a1)(a1);
  }
  if ( *((_BYTE *)a1 + 72) == 0 || (v18 = 1, *((int *)a1 + 70) <= 1) )
    v18 = 0;
  v13 = 0;
  if ( *((int *)a1 + 9) > 0 )
  {
    v3 = *((_DWORD *)a1 + 49) + 36;
    v4 = (_DWORD *)(v2 + 52);
    do
    {
      v5 = *((_DWORD *)a1 + 70);
      v14 = *(_DWORD *)v3 * *(_DWORD *)(v3 - 28) / v5;
      v6 = *((_DWORD *)a1 + 69);
      v16 = v6;
      v7 = *(_DWORD *)v3 * *(_DWORD *)(v3 - 24) / v5;
      v8 = *((_DWORD *)a1 + 68);
      v4[12] = v7;
      if ( *(_BYTE *)(v3 + 12) != 0 )
      {
        if ( v14 != v8 || v7 != v6 )
        {
          if ( 2 * v14 == v8 )
          {
            if ( v7 == v6 )
            {
              if ( v18 != 0 && *(_DWORD *)(v3 + 4) > 2u )
                *v4 = sub_101A8450;
              else
                *v4 = sub_101A8380;
LABEL_29:
              v12 = *((_DWORD *)a1 + 69);
              v10 = (int (__cdecl **)(struct jpeg_decompress_struct *, int, int, int))(*((_DWORD *)a1 + 1) + 8);
              v11 = jround_up(a1: *((_DWORD *)a1 + 23), a2: *((_DWORD *)a1 + 68));
              *(v4 - 10) = (*v10)(a1, a2: 1, a3: v11, a4: v12);
              goto LABEL_30;
            }
            if ( 2 * v14 == v8 && 2 * v7 == v6 )
            {
              if ( v18 != 0 && *(_DWORD *)(v3 + 4) > 2u )
              {
                *v4 = sub_101A8520;
                *(_BYTE *)(v17 + 8) = 1;
              }
              else
              {
                *v4 = sub_101A83E0;
              }
              goto LABEL_29;
            }
          }
          v9 = v8 % v14;
          v15 = v8 / v14;
          if ( v9 != 0 || v16 % v7 != 0 )
          {
            *(_DWORD *)(*(_DWORD *)a1 + 20) = 38;
            (**(void (__cdecl ***)(struct jpeg_decompress_struct *))a1)(a1);
          }
          else
          {
            *v4 = sub_101A82A0;
            *(_BYTE *)(v13 + v17 + 140) = v15;
            *(_BYTE *)(v13 + v17 + 150) = v16 / v7;
          }
          goto LABEL_29;
        }
        *v4 = &off_101A8280;
      }
      else
      {
        *v4 = sub_101A8290;
      }
LABEL_30:
      ++v4;
      v3 += 84;
      ++v13;
    }
    while ( v13 < *((_DWORD *)a1 + 9) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101A8850
// Name: sub_101A8850
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A8850@<eax>(int a1@<eax>)
{
  _DWORD *v2; // esi
  int result; // eax
  int v4; // edi
  int v5; // edx
  int v6; // ecx
  int v7; // [esp+10h] [ebp-4h]

  v2 = *(_DWORD **)(a1 + 420);
  v2[2] = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, a2: 1, a3: 1024);
  v2[3] = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, a2: 1, a3: 1024);
  v2[4] = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, a2: 1, a3: 1024);
  v2[5] = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, a2: 1, a3: 1024);
  result = 0;
  v7 = 5990656;
  v4 = -14831872;
  v5 = -11728000;
  v6 = 2919680;
  do
  {
    *(_DWORD *)(result + v2[2]) = v5 >> 16;
    *(_DWORD *)(result + v2[3]) = v4 >> 16;
    *(_DWORD *)(result + v2[4]) = v7;
    *(_DWORD *)(result + v2[5]) = v6;
    v6 -= 22554;
    v5 += 91881;
    v4 += 116130;
    result += 4;
    v7 -= 46802;
  }
  while ( v6 >= -2831590 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A8920
// Name: sub_101A8920
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl sub_101A8920(_DWORD *a1, _DWORD *a2, int a3, _BYTE **a4, int a5)
{
  bool v5; // sf
  _DWORD *v6; // eax
  int v7; // edx
  int v8; // ebp
  int v9; // ecx
  unsigned __int8 *result; // eax
  _DWORD *v11; // esi
  int v12; // edi
  _BYTE *v13; // ecx
  int v14; // esi
  int v15; // ebx
  int v16; // ebp
  int v17; // esi
  int v18; // edi
  int v19; // [esp+4h] [ebp-24h]
  int v20; // [esp+4h] [ebp-24h]
  int v21; // [esp+8h] [ebp-20h]
  int v22; // [esp+Ch] [ebp-1Ch]
  unsigned __int8 *v23; // [esp+10h] [ebp-18h]
  int v24; // [esp+14h] [ebp-14h]
  int v25; // [esp+18h] [ebp-10h]
  int v26; // [esp+1Ch] [ebp-Ch]
  int v27; // [esp+20h] [ebp-8h]
  int v28; // [esp+24h] [ebp-4h]
  int v29; // [esp+2Ch] [ebp+4h]
  int v30; // [esp+2Ch] [ebp+4h]
  int v31; // [esp+3Ch] [ebp+14h]

  v5 = a5 - 1 < 0;
  v31 = a5 - 1;
  v6 = (_DWORD *)a1[105];
  v7 = a1[72];
  v8 = a1[23];
  v22 = v6[2];
  v26 = v6[3];
  v9 = v6[4];
  result = (unsigned __int8 *)v6[5];
  v27 = v8;
  v25 = v7;
  v24 = v9;
  v23 = result;
  if ( !v5 )
  {
    v11 = a2;
    v12 = 4 * a3;
    do
    {
      v29 = *(_DWORD *)(v12 + *v11);
      result = *(unsigned __int8 **)(v12 + v11[1]);
      v19 = *(_DWORD *)(v12 + v11[2]);
      v13 = *a4;
      v12 += 4;
      v28 = v12;
      ++a4;
      if ( v8 != 0 )
      {
        v14 = v29 - (_DWORD)result;
        v15 = v19 - (_DWORD)result;
        v21 = v29 - (_DWORD)result;
        v20 = v19 - (_DWORD)result;
        v30 = v8;
        while ( 1 )
        {
          v16 = result[v15];
          v17 = result[v14];
          v18 = *result;
          *v13 = *(_BYTE *)(v17 + *(_DWORD *)(v22 + 4 * v16) + v7);
          v7 = v25;
          v13[1] = *(_BYTE *)(v17 + ((*(_DWORD *)(v24 + 4 * v16) + *(_DWORD *)&v23[4 * v18]) >> 16) + v25);
          v13[2] = *(_BYTE *)(v17 + *(_DWORD *)(v26 + 4 * v18) + v25);
          v13 += 3;
          ++result;
          if ( --v30 == 0 )
            break;
          v14 = v21;
          v15 = v20;
        }
        v8 = v27;
        v11 = a2;
        v12 = v28;
      }
      --v31;
    }
    while ( v31 >= 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A8B00
// Name: sub_101A8B00
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_BYTE *__cdecl sub_101A8B00(int a1, _DWORD *a2, int a3, _BYTE **a4, int a5)
{
  bool v5; // sf
  _BYTE *result; // eax
  unsigned int v7; // edi
  int v9; // ebp
  int v10; // esi
  unsigned int i; // edx
  char v12; // cl
  int v13; // [esp+18h] [ebp+14h]

  v5 = a5 - 1 < 0;
  v13 = a5 - 1;
  result = (_BYTE *)a1;
  v7 = *(_DWORD *)(a1 + 92);
  if ( !v5 )
  {
    v9 = 4 * a3;
    do
    {
      v10 = *(_DWORD *)(*a2 + v9);
      result = *a4;
      v9 += 4;
      ++a4;
      for ( i = 0; i < v7; result += 3 )
      {
        v12 = *(_BYTE *)(i + v10);
        result[2] = v12;
        result[1] = v12;
        *result = v12;
        ++i;
      }
      --v13;
    }
    while ( v13 >= 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A8B60
// Name: sub_101A8B60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl sub_101A8B60(_DWORD *a1, _DWORD *a2, int a3, _BYTE **a4, int a5)
{
  bool v5; // sf
  _DWORD *v6; // eax
  int v7; // edx
  int v8; // ecx
  unsigned __int8 *result; // eax
  _DWORD *v10; // edi
  int v11; // esi
  int v12; // ebx
  _BYTE *v13; // ecx
  int v14; // esi
  int v15; // ebx
  int v16; // ebp
  int v17; // esi
  int v18; // edi
  int v19; // [esp+0h] [ebp-28h]
  int v20; // [esp+4h] [ebp-24h]
  int v21; // [esp+4h] [ebp-24h]
  int v22; // [esp+8h] [ebp-20h]
  int v23; // [esp+Ch] [ebp-1Ch]
  int v24; // [esp+10h] [ebp-18h]
  unsigned __int8 *v25; // [esp+14h] [ebp-14h]
  int v26; // [esp+18h] [ebp-10h]
  int v27; // [esp+1Ch] [ebp-Ch]
  int v28; // [esp+20h] [ebp-8h]
  int v29; // [esp+24h] [ebp-4h]
  int v30; // [esp+2Ch] [ebp+4h]
  int v31; // [esp+2Ch] [ebp+4h]
  int v32; // [esp+3Ch] [ebp+14h]

  v5 = a5 - 1 < 0;
  v32 = a5 - 1;
  v6 = (_DWORD *)a1[105];
  v19 = a1[23];
  v7 = a1[72];
  v24 = v6[2];
  v28 = v6[3];
  v8 = v6[4];
  result = (unsigned __int8 *)v6[5];
  v27 = v7;
  v26 = v8;
  v25 = result;
  if ( !v5 )
  {
    v10 = a2;
    v11 = 4 * a3;
    do
    {
      v12 = *(_DWORD *)(v11 + *v10);
      result = *(unsigned __int8 **)(v11 + v10[1]);
      v30 = *(_DWORD *)(v11 + v10[2]);
      v20 = *(_DWORD *)(v11 + v10[3]);
      v13 = *a4++;
      v11 += 4;
      v29 = v11;
      if ( v19 != 0 )
      {
        v14 = v12 - (_DWORD)result;
        v15 = v30 - (_DWORD)result;
        v22 = v14;
        v23 = v30 - (_DWORD)result;
        v21 = v20 - (_DWORD)result;
        v31 = v19;
        while ( 1 )
        {
          v16 = result[v15];
          v17 = result[v14];
          v18 = *result;
          *v13 = *(_BYTE *)(v7 - *(_DWORD *)(v24 + 4 * v16) - v17 + 255);
          v7 = v27;
          v13[1] = *(_BYTE *)(v27 - ((*(_DWORD *)(v26 + 4 * v16) + *(_DWORD *)&v25[4 * v18]) >> 16) - v17 + 255);
          v13 += 4;
          *(v13 - 2) = *(_BYTE *)(v27 - *(_DWORD *)(v28 + 4 * v18) - v17 + 255);
          *(v13 - 1) = (result++)[v21];
          if ( --v31 == 0 )
            break;
          v14 = v22;
          v15 = v23;
        }
        v10 = a2;
        v11 = v29;
      }
      --v32;
    }
    while ( v32 >= 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A8CC0
// Name: void jinit_color_deconverter(struct jpeg_decompress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jinit_color_deconverter(int (__cdecl ***a1)(struct jpeg_decompress_struct *, int, int))
{
  void (__cdecl **v1)(); // edi
  int (__cdecl **v2)(struct jpeg_decompress_struct *, int, int); // eax
  int (__cdecl **v3)(struct jpeg_decompress_struct *, int, int); // eax
  int (__cdecl **v4)(struct jpeg_decompress_struct *, int, int); // eax
  int v5; // eax
  int v6; // ecx

  v1 = (void (__cdecl **)())(*a1[1])((struct jpeg_decompress_struct *)a1, a2: 1, a3: 24);
  a1[105] = (int (__cdecl **)(struct jpeg_decompress_struct *, int, int))v1;
  *v1 = CDummyMaterialSystem::EndBatch;
  switch ( (unsigned int)a1[10] )
  {
    case 1u:
      if ( a1[9] != (int (__cdecl **)(struct jpeg_decompress_struct *, int, int))1 )
        goto LABEL_9;
      break;
    case 2u:
    case 3u:
      if ( a1[9] != (int (__cdecl **)(struct jpeg_decompress_struct *, int, int))3 )
        goto LABEL_9;
      break;
    case 4u:
    case 5u:
      if ( a1[9] != (int (__cdecl **)(struct jpeg_decompress_struct *, int, int))4 )
        goto LABEL_9;
      break;
    default:
      if ( (int)a1[9] < 1 )
      {
LABEL_9:
        (*a1)[5] = (int (__cdecl *)(struct jpeg_decompress_struct *, int, int))10;
        ((void (__cdecl *)(int (__cdecl ***)(struct jpeg_decompress_struct *, int, int)))**a1)(a1);
      }
      break;
  }
  if ( a1[11] != (int (__cdecl **)(struct jpeg_decompress_struct *, int, int))1 )
  {
    if ( a1[11] == (int (__cdecl **)(struct jpeg_decompress_struct *, int, int))2 )
    {
      v3 = a1[10];
      a1[25] = (int (__cdecl **)(struct jpeg_decompress_struct *, int, int))3;
      if ( v3 == (int (__cdecl **)(struct jpeg_decompress_struct *, int, int))3 )
      {
        v1[1] = (void (__cdecl *)())sub_101A8920;
        sub_101A8850((int)a1);
        goto LABEL_31;
      }
      if ( v3 == (int (__cdecl **)(struct jpeg_decompress_struct *, int, int))1 )
      {
        v1[1] = (void (__cdecl *)())sub_101A8B00;
        goto LABEL_31;
      }
      if ( v3 == (int (__cdecl **)(struct jpeg_decompress_struct *, int, int))2 )
      {
        v1[1] = (void (__cdecl *)())sub_101A8A40;
        goto LABEL_31;
      }
    }
    else if ( a1[11] == (int (__cdecl **)(struct jpeg_decompress_struct *, int, int))4 )
    {
      v2 = a1[10];
      a1[25] = (int (__cdecl **)(struct jpeg_decompress_struct *, int, int))4;
      if ( v2 == (int (__cdecl **)(struct jpeg_decompress_struct *, int, int))5 )
      {
        v1[1] = (void (__cdecl *)())sub_101A8B60;
        sub_101A8850((int)a1);
        goto LABEL_31;
      }
      if ( v2 == (int (__cdecl **)(struct jpeg_decompress_struct *, int, int))4 )
      {
        v1[1] = (void (__cdecl *)())sub_101A8A40;
        goto LABEL_31;
      }
    }
    else if ( a1[11] == a1[10] )
    {
      a1[25] = a1[9];
      v1[1] = (void (__cdecl *)())sub_101A8A40;
      goto LABEL_31;
    }
    goto LABEL_27;
  }
  v4 = a1[10];
  a1[25] = (int (__cdecl **)(struct jpeg_decompress_struct *, int, int))1;
  if ( v4 != (int (__cdecl **)(struct jpeg_decompress_struct *, int, int))1
    && v4 != (int (__cdecl **)(struct jpeg_decompress_struct *, int, int))3 )
  {
LABEL_27:
    (*a1)[5] = (int (__cdecl *)(struct jpeg_decompress_struct *, int, int))27;
    ((void (__cdecl *)(int (__cdecl ***)(struct jpeg_decompress_struct *, int, int)))**a1)(a1);
    goto LABEL_31;
  }
  v1[1] = (void (__cdecl *)())sub_101A8AD0;
  v5 = 1;
  if ( (int)a1[9] > 1 )
  {
    v6 = 21;
    do
    {
      LOBYTE(a1[49][v6 + 12]) = 0;
      ++v5;
      v6 += 21;
    }
    while ( v5 < (int)a1[9] );
  }
LABEL_31:
  if ( *((_BYTE *)a1 + 74) != 0 )
    a1[26] = (int (__cdecl **)(struct jpeg_decompress_struct *, int, int))1;
  else
    a1[26] = a1[25];
}

//------------------------------------------------------------------------------
// Address: 0x101A8E50
// Name: sub_101A8E50
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A8E50@<eax>(int a1@<eax>)
{
  _DWORD *v2; // esi
  int result; // eax
  int v4; // edi
  int v5; // edx
  int v6; // ecx
  int v7; // [esp+10h] [ebp-4h]

  v2 = *(_DWORD **)(a1 + 416);
  v2[4] = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, a2: 1, a3: 1024);
  v2[5] = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, a2: 1, a3: 1024);
  v2[6] = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, a2: 1, a3: 1024);
  v2[7] = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, a2: 1, a3: 1024);
  result = 0;
  v7 = 5990656;
  v4 = -14831872;
  v5 = -11728000;
  v6 = 2919680;
  do
  {
    *(_DWORD *)(result + v2[4]) = v5 >> 16;
    *(_DWORD *)(result + v2[5]) = v4 >> 16;
    *(_DWORD *)(result + v2[6]) = v7;
    *(_DWORD *)(result + v2[7]) = v6;
    v6 -= 22554;
    v5 += 91881;
    v4 += 116130;
    result += 4;
    v7 -= 46802;
  }
  while ( v6 >= -2831590 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A8F20
// Name: sub_101A8F20
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A8F20(int a1)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 416);
  *(_BYTE *)(result + 36) = 0;
  *(_DWORD *)(result + 44) = *(_DWORD *)(a1 + 96);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A8F40
// Name: sub_101A8F40
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_101A8F40(int a1, int a2, _DWORD *a3, int a4, int a5, _DWORD *a6, int a7)
{
  _DWORD *v7; // ebp
  int v8; // esi
  _DWORD *v9; // ebx
  unsigned int v10; // edi
  int v11; // eax
  int v12; // [esp+10h] [ebp-8h] BYREF
  int v13; // [esp+14h] [ebp-4h]

  v7 = a3;
  v8 = *(_DWORD *)(a1 + 416);
  if ( *(_BYTE *)(v8 + 36) != 0 )
  {
    v9 = a6;
    jcopy_sample_rows(
      a1: (unsigned __int8 **)(v8 + 32),
      a2: 0,
      a3: (unsigned __int8 **)(a5 + 4 * *a6),
      a4: 0,
      a5: 1,
      count: *(_DWORD *)(v8 + 40));
    v10 = 1;
    *(_BYTE *)(v8 + 36) = 0;
  }
  else
  {
    v10 = 2;
    if ( *(_DWORD *)(v8 + 44) < 2u )
      v10 = *(_DWORD *)(v8 + 44);
    v9 = a6;
    v11 = *a6;
    if ( v10 > a7 - *a6 )
      v10 = a7 - *a6;
    v12 = *(_DWORD *)(a5 + 4 * v11);
    if ( v10 <= 1 )
    {
      v13 = *(_DWORD *)(v8 + 32);
      *(_BYTE *)(v8 + 36) = 1;
    }
    else
    {
      v13 = *(_DWORD *)(a5 + 4 * v11 + 4);
    }
    v7 = a3;
    (*(void (__cdecl **)(int, int, _DWORD, int *))(v8 + 12))(a1, a2, a3: *a3, a4: &v12);
  }
  *v9 += v10;
  *(_DWORD *)(v8 + 44) -= v10;
  if ( *(_BYTE *)(v8 + 36) == 0 )
    ++*v7;
}

//------------------------------------------------------------------------------
// Address: 0x101A9010
// Name: sub_101A9010
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A9010(int a1, int a2, _DWORD *a3, int a4, int a5, _DWORD *a6)
{
  int result; // eax

  result = (*(int (__cdecl **)(int, int, _DWORD, int))(*(_DWORD *)(a1 + 416) + 12))(a1, a2, a3: *a3, a4: a5 + 4 * *a6);
  ++*a6;
  ++*a3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A9050
// Name: sub_101A9050
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_BYTE *__cdecl sub_101A9050(_DWORD *a1, _DWORD *a2, int a3, _BYTE **a4)
{
  _DWORD *v4; // edx
  _DWORD *v5; // eax
  int v6; // ecx
  unsigned __int8 *v7; // edi
  unsigned __int8 *v8; // esi
  unsigned __int8 *v9; // ebx
  _BYTE *result; // eax
  int v11; // ebp
  int v12; // edx
  int v13; // esi
  int v14; // ebp
  int v15; // edx
  int v16; // ebp
  _BYTE *v17; // eax
  char v18; // bl
  int v19; // edx
  int v20; // ebx
  int v21; // edi
  int v22; // ebp
  int v23; // esi
  unsigned __int8 *v24; // [esp+10h] [ebp-14h]
  int v25; // [esp+14h] [ebp-10h]
  int v26; // [esp+18h] [ebp-Ch]
  int v27; // [esp+1Ch] [ebp-8h]
  int v28; // [esp+20h] [ebp-4h]
  int v29; // [esp+2Ch] [ebp+8h]
  int v30; // [esp+30h] [ebp+Ch]
  unsigned __int8 *v31; // [esp+34h] [ebp+10h]

  v4 = a1;
  v5 = (_DWORD *)a1[104];
  v6 = a1[72];
  v28 = v5[4];
  v27 = v5[5];
  v26 = v5[6];
  v25 = v5[7];
  v7 = *(unsigned __int8 **)(*a2 + 4 * a3);
  v8 = *(unsigned __int8 **)(a2[1] + 4 * a3);
  v9 = *(unsigned __int8 **)(a2[2] + 4 * a3);
  result = *a4;
  v29 = a1[23] >> 1;
  if ( v29 != 0 )
  {
    do
    {
      v11 = *v9;
      v12 = *v8;
      v31 = v8 + 1;
      v24 = v9 + 1;
      v30 = *(_DWORD *)(v28 + 4 * v11);
      v13 = *(_DWORD *)(v26 + 4 * v11) + *(_DWORD *)(v25 + 4 * v12);
      v14 = *v7;
      v15 = *(_DWORD *)(v27 + 4 * v12);
      *result = *(_BYTE *)(v14 + v30 + v6);
      v13 >>= 16;
      result[1] = *(_BYTE *)(v13 + v14 + v6);
      result[2] = *(_BYTE *)(v6 + v15 + v14);
      v16 = v7[1];
      v17 = result + 3;
      *v17 = *(_BYTE *)(v16 + v30 + v6);
      v18 = *(_BYTE *)(v16 + v13 + v6);
      v8 = v31;
      v17[1] = v18;
      v9 = v24;
      v17[2] = *(_BYTE *)(v6 + v15 + v16);
      v7 += 2;
      result = v17 + 3;
      --v29;
    }
    while ( v29 != 0 );
    v4 = a1;
  }
  if ( (v4[23] & 1) != 0 )
  {
    v19 = *v8;
    v20 = *v9;
    v21 = *v7;
    v22 = *(_DWORD *)(v27 + 4 * v19);
    v23 = (*(_DWORD *)(v26 + 4 * v20) + *(_DWORD *)(v25 + 4 * v19)) >> 16;
    *result = *(_BYTE *)(v21 + *(_DWORD *)(v28 + 4 * v20) + v6);
    result[1] = *(_BYTE *)(v21 + v23 + v6);
    result[2] = *(_BYTE *)(v22 + v21 + v6);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A91A0
// Name: sub_101A91A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A91A0(_DWORD *a1, _DWORD *a2, int a3, int a4)
{
  _DWORD *v4; // ebx
  _DWORD *v5; // ecx
  int result; // eax
  unsigned __int8 **v8; // edx
  unsigned __int8 *v9; // edi
  unsigned __int8 *v10; // edx
  unsigned __int8 *v11; // edi
  _BYTE *v12; // ecx
  _BYTE *v13; // esi
  unsigned __int8 *v14; // edi
  int v15; // edx
  int v16; // ebp
  int v17; // edi
  int v18; // edx
  _BYTE *v19; // ecx
  int v20; // ebx
  _BYTE *v21; // esi
  bool v22; // zf
  int v23; // ebx
  int v24; // edx
  int v25; // edi
  int v26; // edx
  int v27; // ebp
  int v28; // ecx
  unsigned __int8 *v29; // [esp+10h] [ebp-1Ch]
  unsigned __int8 *v30; // [esp+10h] [ebp-1Ch]
  unsigned __int8 *v31; // [esp+14h] [ebp-18h]
  unsigned __int8 *v32; // [esp+18h] [ebp-14h]
  int v33; // [esp+1Ch] [ebp-10h]
  int v34; // [esp+20h] [ebp-Ch]
  int v35; // [esp+24h] [ebp-8h]
  int v36; // [esp+28h] [ebp-4h]
  int v37; // [esp+30h] [ebp+4h]
  int v38; // [esp+34h] [ebp+8h]
  int v39; // [esp+34h] [ebp+8h]
  int v40; // [esp+34h] [ebp+8h]
  int v41; // [esp+34h] [ebp+8h]
  unsigned __int8 *v42; // [esp+38h] [ebp+Ch]
  unsigned __int8 *v43; // [esp+38h] [ebp+Ch]
  int v44; // [esp+3Ch] [ebp+10h]

  v4 = a1;
  v5 = (_DWORD *)a1[104];
  result = a1[72];
  v33 = v5[4];
  v36 = v5[5];
  v35 = v5[6];
  v34 = v5[7];
  v8 = (unsigned __int8 **)(*a2 + 8 * a3);
  v9 = *v8;
  v29 = v8[1];
  v10 = *(unsigned __int8 **)(a2[1] + 4 * a3);
  v42 = v9;
  v11 = *(unsigned __int8 **)(a2[2] + 4 * a3);
  v12 = *(_BYTE **)a4;
  v13 = *(_BYTE **)(a4 + 4);
  v44 = a1[23] >> 1;
  if ( v44 != 0 )
  {
    do
    {
      v38 = *v10;
      v14 = v11 + 1;
      v31 = v10 + 1;
      v15 = *(v14 - 1);
      v32 = v14;
      v16 = *(_DWORD *)(v33 + 4 * v15);
      v17 = *(_DWORD *)(v35 + 4 * v15) + *(_DWORD *)(v34 + 4 * v38);
      v18 = *(_DWORD *)(v36 + 4 * v38);
      v39 = *v42;
      *v12 = *(_BYTE *)(v16 + v39 + result);
      v43 = v42 + 1;
      v17 >>= 16;
      v12[1] = *(_BYTE *)(v17 + v39 + result);
      v12[2] = *(_BYTE *)(v18 + v39 + result);
      v40 = *v43;
      v12[3] = *(_BYTE *)(v16 + v40 + result);
      v12[4] = *(_BYTE *)(v17 + v40 + result);
      v19 = v12 + 3;
      v19[2] = *(_BYTE *)(v18 + v40 + result);
      v41 = *v29;
      *v13 = *(_BYTE *)(v16 + v41 + result);
      v30 = v29 + 1;
      v13[1] = *(_BYTE *)(v17 + v41 + result);
      v13[2] = *(_BYTE *)(v18 + v41 + result);
      v20 = *v30;
      v42 = v43 + 1;
      v29 = v30 + 1;
      v21 = v13 + 3;
      *v21 = *(_BYTE *)(v16 + v20 + result);
      v21[1] = *(_BYTE *)(v17 + v20 + result);
      v12 = v19 + 3;
      v21[2] = *(_BYTE *)(v18 + v20 + result);
      v13 = v21 + 3;
      v22 = v44-- == 1;
      v10 = v31;
      v11 = v32;
    }
    while ( !v22 );
    v4 = a1;
  }
  if ( (v4[23] & 1) != 0 )
  {
    v23 = *v11;
    v24 = *v10;
    v37 = *(_DWORD *)(v33 + 4 * v23);
    v25 = *(_DWORD *)(v35 + 4 * v23) + *(_DWORD *)(v34 + 4 * v24);
    v26 = *(_DWORD *)(v36 + 4 * v24);
    v27 = *v42;
    *v12 = *(_BYTE *)(v27 + v37 + result);
    v25 >>= 16;
    v12[1] = *(_BYTE *)(v25 + v27 + result);
    v12[2] = *(_BYTE *)(result + v26 + v27);
    v28 = *v29;
    *v13 = *(_BYTE *)(v28 + v37 + result);
    v13[1] = *(_BYTE *)(v28 + v25 + result);
    v13[2] = *(_BYTE *)(v26 + v28 + result);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A93C0
// Name: void jinit_merged_upsampler(struct jpeg_decompress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jinit_merged_upsampler(struct jpeg_decompress_struct *a1)
{
  int v1; // esi
  int v2; // edx

  v1 = (**((int (__cdecl ***)(struct jpeg_decompress_struct *, int, int))a1 + 1))(a1, a2: 1, a3: 48);
  *((_DWORD *)a1 + 104) = v1;
  *(_DWORD *)v1 = sub_101A8F20;
  *(_BYTE *)(v1 + 8) = 0;
  v2 = *((_DWORD *)a1 + 23) * *((_DWORD *)a1 + 25);
  *(_DWORD *)(v1 + 40) = v2;
  if ( *((_DWORD *)a1 + 69) == 2 )
  {
    *(_DWORD *)(v1 + 4) = sub_101A8F40;
    *(_DWORD *)(v1 + 12) = sub_101A91A0;
    *(_DWORD *)(v1 + 32) = (*(int (__cdecl **)(struct jpeg_decompress_struct *, int, int))(*((_DWORD *)a1 + 1) + 4))(
                             a1,
                             a2: 1,
                             a3: v2);
  }
  else
  {
    *(_DWORD *)(v1 + 32) = 0;
    *(_DWORD *)(v1 + 4) = sub_101A9010;
    *(_DWORD *)(v1 + 12) = sub_101A9050;
  }
  sub_101A8E50((int)a1);
}

//------------------------------------------------------------------------------
// Address: 0x101A9440
// Name: sub_101A9440
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_WORD *__cdecl sub_101A9440(int a1, int a2, int a3, int a4)
{
  _WORD *result; // eax
  int v5; // ebp
  int v6; // ebx
  int i; // edi
  unsigned __int8 *v8; // ecx
  int j; // esi
  int v10; // eax
  int v11; // edx

  result = (_WORD *)a1;
  v5 = *(_DWORD *)(a1 + 92);
  v6 = 0;
  for ( i = *(_DWORD *)(*(_DWORD *)(a1 + 424) + 24); v6 < a4; ++v6 )
  {
    v8 = *(unsigned __int8 **)(a2 + 4 * v6);
    for ( j = v5; j != 0; --j )
    {
      v10 = (v8[2] >> 3) + 32 * (v8[1] >> 2);
      v11 = *(_DWORD *)(i + 4 * (*v8 >> 3));
      ++*(_WORD *)(v11 + 2 * v10);
      result = (_WORD *)(v11 + 2 * v10);
      if ( *result == 0 )
        *result = -1;
      v8 += 3;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A94C0
// Name: sub_101A94C0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__fastcall sub_101A94C0(int a1, int a2)
{
  int v2; // esi
  int *result; // eax
  int *v4; // ecx
  int i; // edi

  v2 = 0;
  result = nullptr;
  if ( a2 > 0 )
  {
    v4 = (int *)(a1 + 28);
    for ( i = a2; i != 0; --i )
    {
      if ( *v4 > v2 && *(v4 - 1) > 0 )
      {
        result = v4 - 7;
        v2 = *v4;
      }
      v4 += 8;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A94F0
// Name: sub_101A94F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__fastcall sub_101A94F0(int a1, int a2)
{
  int v2; // esi
  int *result; // eax
  int *v4; // ecx
  int i; // edi

  v2 = 0;
  result = nullptr;
  if ( a2 > 0 )
  {
    v4 = (int *)(a1 + 24);
    for ( i = a2; i != 0; --i )
    {
      if ( *v4 > v2 )
      {
        result = v4 - 6;
        v2 = *v4;
      }
      v4 += 8;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A9520
// Name: sub_101A9520
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A9520(int *a1)
{
  int v1; // ecx
  int v2; // ebx
  int v3; // ebp
  int v4; // ecx
  int v5; // edi
  int v6; // esi
  int v7; // edx
  __int16 *v8; // ecx
  int v9; // eax
  __int16 v10; // bx
  int v11; // eax
  int v12; // esi
  int v13; // edx
  __int16 *v14; // ecx
  int v15; // eax
  __int16 v16; // di
  int v17; // esi
  int v18; // edx
  __int16 *v19; // eax
  int v20; // ecx
  __int16 v21; // di
  int v22; // eax
  int v23; // esi
  int v24; // edx
  __int16 *v25; // eax
  int v26; // ecx
  __int16 v27; // di
  int v28; // eax
  int v29; // edx
  int v30; // esi
  _WORD *v31; // eax
  int v32; // ecx
  int v33; // eax
  int v34; // edx
  int v35; // esi
  _WORD *v36; // eax
  int v37; // ecx
  int v38; // edi
  int result; // eax
  int v40; // ebp
  int v41; // edx
  _WORD *v42; // eax
  int v43; // ecx
  int v44; // [esp+10h] [ebp-1Ch]
  int v45; // [esp+14h] [ebp-18h]
  int v46; // [esp+18h] [ebp-14h]
  int v47; // [esp+1Ch] [ebp-10h]
  int v48; // [esp+1Ch] [ebp-10h]
  int v49; // [esp+20h] [ebp-Ch]
  int v50; // [esp+20h] [ebp-Ch]
  int v51; // [esp+20h] [ebp-Ch]
  int v52; // [esp+20h] [ebp-Ch]
  int v53; // [esp+20h] [ebp-Ch]
  int v54; // [esp+20h] [ebp-Ch]
  int v55; // [esp+24h] [ebp-8h]
  int v56; // [esp+28h] [ebp-4h]

  v2 = a1[4];
  v3 = a1[5];
  v55 = *(_DWORD *)(*(_DWORD *)(v1 + 424) + 24);
  v4 = a1[1];
  v44 = a1[2];
  v47 = *a1;
  v45 = v4;
  v46 = a1[3];
  v56 = v3;
  if ( v4 > *a1 )
  {
    v5 = *a1;
    if ( *a1 <= v4 )
    {
      while ( 1 )
      {
        v6 = a1[2];
        if ( v44 <= v46 )
          break;
LABEL_9:
        if ( ++v5 > v45 )
          goto LABEL_12;
      }
      v7 = *(_DWORD *)(v55 + 4 * v5) + 2 * (v2 + 32 * v44);
      while ( 1 )
      {
        v8 = (__int16 *)v7;
        v9 = v2;
        if ( a1[4] <= v3 )
          break;
LABEL_8:
        v2 = a1[4];
        ++v6;
        v7 += 64;
        if ( v6 > v46 )
          goto LABEL_9;
      }
      while ( 1 )
      {
        v10 = *v8++;
        if ( v10 != 0 )
          break;
        if ( ++v9 > v3 )
          goto LABEL_8;
      }
      v2 = a1[4];
      v47 = v5;
      *a1 = v5;
    }
LABEL_12:
    v11 = v45;
    if ( v45 > v47 )
    {
      v49 = v45;
      while ( 1 )
      {
        v12 = v44;
        if ( v44 <= v46 )
          break;
LABEL_21:
        v49 = --v11;
        if ( v11 < v47 )
          goto LABEL_24;
      }
      v13 = *(_DWORD *)(v55 + 4 * v11) + 2 * (v2 + 32 * v44);
      while ( 1 )
      {
        v14 = (__int16 *)v13;
        v15 = v2;
        if ( v2 <= v3 )
          break;
LABEL_19:
        ++v12;
        v13 += 64;
        if ( v12 > v46 )
        {
          v11 = v49;
          goto LABEL_21;
        }
      }
      while ( 1 )
      {
        v16 = *v14++;
        if ( v16 != 0 )
          break;
        if ( ++v15 > v3 )
          goto LABEL_19;
      }
      v45 = v49;
      a1[1] = v49;
    }
  }
LABEL_24:
  if ( v44 < v46 )
  {
    v50 = v44;
    v17 = 2 * (v2 + 32 * v44);
    while ( 1 )
    {
      v18 = v47;
      if ( v47 <= v45 )
        break;
LABEL_31:
      v22 = v46;
      v17 += 64;
      if ( ++v50 > v46 )
        goto LABEL_34;
    }
    while ( 1 )
    {
      v19 = (__int16 *)(v17 + *(_DWORD *)(v55 + 4 * v18));
      v20 = v2;
      if ( v2 <= v3 )
        break;
LABEL_30:
      if ( ++v18 > v45 )
        goto LABEL_31;
    }
    while ( 1 )
    {
      v21 = *v19++;
      if ( v21 != 0 )
        break;
      if ( ++v20 > v3 )
        goto LABEL_30;
    }
    v44 = v50;
    a1[2] = v50;
    v22 = v46;
LABEL_34:
    if ( v22 > v44 )
    {
      v51 = v22;
      v23 = 2 * (v2 + 32 * v22);
      while ( 1 )
      {
        v24 = v47;
        if ( v47 <= v45 )
          break;
LABEL_41:
        v23 -= 64;
        if ( --v51 < v44 )
          goto LABEL_44;
      }
      while ( 1 )
      {
        v25 = (__int16 *)(v23 + *(_DWORD *)(v55 + 4 * v24));
        v26 = v2;
        if ( v2 <= v3 )
          break;
LABEL_40:
        if ( ++v24 > v45 )
          goto LABEL_41;
      }
      while ( 1 )
      {
        v27 = *v25++;
        if ( v27 != 0 )
          break;
        if ( ++v26 > v3 )
          goto LABEL_40;
      }
      v46 = v51;
      a1[3] = v51;
    }
  }
LABEL_44:
  if ( v2 < v3 )
  {
    v28 = v2;
    v52 = v2;
    while ( 1 )
    {
      v29 = v47;
      if ( v47 <= v45 )
        break;
LABEL_53:
      v52 = ++v28;
      if ( v28 > v3 )
        goto LABEL_56;
    }
    v30 = 2 * (v28 + 32 * v44);
    while ( 1 )
    {
      v31 = (_WORD *)(v30 + *(_DWORD *)(v55 + 4 * v29));
      v32 = v44;
      if ( v44 <= v46 )
        break;
LABEL_51:
      if ( ++v29 > v45 )
      {
        v3 = v56;
        v28 = v52;
        goto LABEL_53;
      }
    }
    while ( *v31 == 0 )
    {
      ++v32;
      v31 += 32;
      if ( v32 > v46 )
        goto LABEL_51;
    }
    v2 = v52;
    v3 = v56;
    a1[4] = v52;
LABEL_56:
    if ( v3 > v2 )
    {
      v33 = v3;
      v53 = v3;
      while ( 1 )
      {
        v34 = v47;
        if ( v47 <= v45 )
          break;
LABEL_65:
        v53 = --v33;
        if ( v33 < v2 )
          goto LABEL_68;
      }
      v35 = 2 * (v33 + 32 * v44);
      while ( 1 )
      {
        v36 = (_WORD *)(v35 + *(_DWORD *)(v55 + 4 * v34));
        v37 = v44;
        if ( v44 <= v46 )
          break;
LABEL_63:
        if ( ++v34 > v45 )
        {
          v3 = v56;
          v33 = v53;
          goto LABEL_65;
        }
      }
      while ( *v36 == 0 )
      {
        ++v37;
        v36 += 32;
        if ( v37 > v46 )
          goto LABEL_63;
      }
      v3 = v53;
      v56 = v53;
      a1[5] = v53;
    }
  }
LABEL_68:
  v38 = v3 - v2;
  result = v47;
  a1[6] = 16 * (v45 - v47) * 16 * (v45 - v47) + 12 * (v46 - v44) * 12 * (v46 - v44) + 8 * (v3 - v2) * 8 * (v3 - v2);
  v40 = 0;
  v54 = v47;
  if ( v47 > v45 )
  {
    a1[7] = 0;
  }
  else
  {
    do
    {
      if ( v44 <= v46 )
      {
        v41 = *(_DWORD *)(v55 + 4 * v54) + 2 * (v2 + 32 * v44);
        v48 = v46 - v44 + 1;
        do
        {
          v42 = (_WORD *)v41;
          if ( v2 <= v56 )
          {
            v43 = v38 + 1;
            do
            {
              if ( *v42 != 0 )
                ++v40;
              ++v42;
              --v43;
            }
            while ( v43 != 0 );
          }
          v41 += 64;
          --v48;
        }
        while ( v48 != 0 );
      }
      result = ++v54;
    }
    while ( v54 <= v45 );
    a1[7] = v40;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A9930
// Name: sub_101A9930
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A9930(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  int v5; // ecx
  int v6; // edi
  _DWORD *v7; // esi
  int *v8; // eax
  int v9; // edx
  int v10; // ebp
  int v11; // ebp
  int v12; // kr00_4
  int v13; // kr04_4
  int v14; // kr08_4
  int v16; // [esp+0h] [ebp-4h]

  v4 = a4;
  v5 = a2;
  v6 = a3;
  if ( a3 >= a4 )
    return a3;
  v16 = 2 * a3;
  v7 = (_DWORD *)(32 * a3 + a2 + 12);
  while ( 1 )
  {
    v8 = v16 > v4 ? sub_101A94F0(a1: v5, a2: v6) : sub_101A94C0(a1: v5, a2: v6);
    if ( v8 == nullptr )
      break;
    *(v7 - 2) = v8[1];
    *v7 = v8[3];
    v7[2] = v8[5];
    *(v7 - 3) = *v8;
    *(v7 - 1) = v8[2];
    v7[1] = v8[4];
    v9 = 12 * (v8[3] - v8[2]);
    v10 = 1;
    if ( 16 * (v8[1] - *v8) > v9 )
    {
      v9 = 16 * (v8[1] - *v8);
      v10 = 0;
    }
    if ( 8 * (v8[5] - v8[4]) > v9 )
      v10 = 2;
    if ( v10 != 0 )
    {
      v11 = v10 - 1;
      if ( v11 != 0 )
      {
        if ( v11 == 1 )
        {
          v12 = v8[4] + v8[5];
          v8[5] = v12 / 2;
          v7[1] = v12 / 2 + 1;
        }
      }
      else
      {
        v13 = v8[2] + v8[3];
        v8[3] = v13 / 2;
        *(v7 - 1) = v13 / 2 + 1;
      }
    }
    else
    {
      v14 = *v8 + v8[1];
      v8[1] = v14 / 2;
      *(v7 - 3) = v14 / 2 + 1;
    }
    sub_101A9520(a1: v8);
    sub_101A9520(a1: v7 - 3);
    v4 = a4;
    v16 += 2;
    v6 = a3 + 1;
    v7 += 8;
    if ( ++a3 >= a4 )
      break;
    v5 = a2;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101A9A80
// Name: sub_101A9A80
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A9A80@<eax>(int *a1@<eax>, int a2, int a3)
{
  int v3; // ebp
  int v4; // esi
  int v5; // ecx
  int v6; // edx
  int v7; // ebx
  int v8; // eax
  int v9; // edi
  unsigned __int16 *v10; // ebp
  int v11; // edx
  int v12; // eax
  int v13; // esi
  int v14; // ecx
  int v15; // edx
  int v16; // eax
  int result; // eax
  int v18; // [esp+10h] [ebp-38h]
  int v19; // [esp+14h] [ebp-34h]
  int v20; // [esp+18h] [ebp-30h]
  int v21; // [esp+1Ch] [ebp-2Ch]
  int v22; // [esp+20h] [ebp-28h]
  int v23; // [esp+24h] [ebp-24h]
  unsigned __int16 *v24; // [esp+28h] [ebp-20h]
  int v25; // [esp+2Ch] [ebp-1Ch]
  int v26; // [esp+30h] [ebp-18h]
  int v27; // [esp+38h] [ebp-10h]
  int v28; // [esp+40h] [ebp-8h]
  int v29; // [esp+44h] [ebp-4h]

  v3 = a1[5];
  v4 = a2;
  v5 = a1[2];
  v6 = a1[1];
  v22 = a1[3];
  v7 = a1[4];
  v8 = *a1;
  v9 = 0;
  v19 = 0;
  v20 = 0;
  v21 = 0;
  v29 = v6;
  v28 = v5;
  v27 = v7;
  v23 = v3;
  v26 = v8;
  if ( v8 <= v6 )
  {
    v18 = 8 * v8 + 4;
    do
    {
      if ( v5 <= v22 )
      {
        v10 = (unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2 + 424) + 24) + 4 * v8) + 2 * (v7 + 32 * v5));
        v11 = v23;
        v12 = v22 - v5 + 1;
        v13 = 4 * v5 + 2;
        v24 = v10;
        v25 = v12;
        do
        {
          if ( v7 <= v11 )
          {
            v14 = 8 * v7 + 4;
            v15 = v11 - v7 + 1;
            do
            {
              v16 = *v10++;
              if ( v16 != 0 )
              {
                v19 += v16 * v18;
                v20 += v16 * v13;
                v9 += v16;
                v21 += v16 * v14;
                v7 = v27;
              }
              v14 += 8;
              --v15;
            }
            while ( v15 != 0 );
            v5 = v28;
            v11 = v23;
            v12 = v25;
          }
          v10 = v24 + 32;
          v13 += 4;
          --v12;
          v24 += 32;
          v25 = v12;
        }
        while ( v12 != 0 );
        v4 = a2;
        v6 = v29;
        v8 = v26;
      }
      v18 += 8;
      v26 = ++v8;
    }
    while ( v8 <= v6 );
  }
  *(_BYTE *)(a3 + **(_DWORD **)(v4 + 116)) = ((v9 >> 1) + v19) / v9;
  *(_BYTE *)(a3 + *(_DWORD *)(*(_DWORD *)(v4 + 116) + 4)) = ((v9 >> 1) + v20) / v9;
  result = ((v9 >> 1) + v21) / v9;
  *(_BYTE *)(a3 + *(_DWORD *)(*(_DWORD *)(v4 + 116) + 8)) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A9C00
// Name: sub_101A9C00
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A9C00@<eax>(int a1@<edi>, int a2)
{
  int *v2; // esi
  int v3; // ebx
  int v4; // ebp
  int v5; // eax

  v2 = (int *)(**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, a2: 1, a3: 32 * a2);
  v3 = 0;
  *v2 = 0;
  v2[1] = 31;
  v2[2] = 0;
  v2[3] = 63;
  v2[4] = 0;
  v2[5] = 31;
  sub_101A9520(a1: v2);
  v4 = sub_101A9930(a1, a2: (int)v2, a3: 1, a4: a2);
  if ( v4 > 0 )
  {
    do
    {
      sub_101A9A80(a1: v2, a2: a1, a3: v3++);
      v2 += 8;
    }
    while ( v3 < v4 );
  }
  v5 = *(_DWORD *)a1;
  *(_DWORD *)(a1 + 112) = v4;
  *(_DWORD *)(v5 + 20) = 96;
  *(_DWORD *)(*(_DWORD *)a1 + 24) = v4;
  return (*(int (__cdecl **)(int, int))(*(_DWORD *)a1 + 4))(a1, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x101A9C90
// Name: sub_101A9C90
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101A9C90@<eax>(int a1@<eax>, int a2@<ecx>, int a3, int a4, int a5)
{
  int v5; // ebp
  int v6; // esi
  int v8; // ecx
  int v9; // ebx
  int *v10; // eax
  int v11; // eax
  int v12; // edx
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  int v17; // esi
  int v18; // eax
  int v19; // ecx
  int v20; // ecx
  int v21; // esi
  int v22; // eax
  int v23; // edx
  int result; // eax
  int i; // ecx
  int v26; // [esp+10h] [ebp-428h]
  int v27; // [esp+14h] [ebp-424h]
  int v28; // [esp+1Ch] [ebp-41Ch]
  int v29; // [esp+24h] [ebp-414h]
  int v30; // [esp+30h] [ebp-408h]
  int v31; // [esp+34h] [ebp-404h]
  _DWORD v32[256]; // [esp+38h] [ebp-400h]

  v5 = a4;
  v6 = *(_DWORD *)(a1 + 112);
  v8 = a3;
  v9 = a2 + 28;
  v30 = v6;
  v27 = 0x7FFFFFFF;
  v26 = 0;
  if ( v6 > 0 )
  {
    v10 = *(int **)(a1 + 116);
    v31 = *v10;
    v29 = v10[1];
    v28 = v10[2];
    while ( 1 )
    {
      v11 = *(unsigned __int8 *)(v31 + v26);
      if ( v11 < v8 )
        break;
      v17 = v8 + 24;
      if ( v11 > v8 + 24 )
      {
        v12 = 2 * (v11 - v17) * 2 * (v11 - v17);
        goto LABEL_5;
      }
      v12 = 0;
      if ( v11 > (2 * a3 + 24) >> 1 )
        goto LABEL_5;
      v13 = v11 - v17;
LABEL_6:
      v14 = *(unsigned __int8 *)(v29 + v26);
      v15 = 2 * v13 * 2 * v13;
      if ( v14 < a2 )
      {
        v12 += 3 * (v14 - a2) * 3 * (v14 - a2);
        v5 = a4;
        v16 = v14 - v9;
        goto LABEL_15;
      }
      if ( v14 > v9 )
      {
        v12 += 3 * (v14 - v9) * 3 * (v14 - v9);
        v5 = a4;
LABEL_14:
        v16 = v14 - a2;
        goto LABEL_15;
      }
      if ( v14 > (a2 + 28 + a2) >> 1 )
        goto LABEL_14;
      v16 = v14 - v9;
LABEL_15:
      v18 = 3 * v16 * 3 * v16 + v15;
      v19 = *(unsigned __int8 *)(v28 + v26);
      if ( v19 >= v5 )
      {
        if ( v19 <= v5 + 24 )
        {
          if ( v19 <= (2 * a4 + 24) >> 1 )
          {
            v20 = v19 - (v5 + 24);
            goto LABEL_22;
          }
        }
        else
        {
          v12 += (v19 - (v5 + 24)) * (v19 - (v5 + 24));
          v5 = a4;
        }
        v20 = v19 - v5;
      }
      else
      {
        v12 += (v19 - v5) * (v19 - v5);
        v5 = a4;
        v20 = v19 - (a4 + 24);
      }
LABEL_22:
      v21 = v20 * v20;
      v8 = a3;
      v22 = v21 + v18;
      v32[v26] = v12;
      v23 = v27;
      if ( v22 < v27 )
      {
        v23 = v22;
        v27 = v22;
      }
      ++v26;
      v6 = v30;
      if ( v26 >= v30 )
        goto LABEL_29;
    }
    v12 = 2 * (v11 - v8) * 2 * (v11 - v8);
    v8 += 24;
LABEL_5:
    v13 = v11 - v8;
    goto LABEL_6;
  }
  v23 = 0x7FFFFFFF;
LABEL_29:
  result = 0;
  for ( i = 0; i < v6; ++i )
  {
    if ( v32[i] <= v23 )
    {
      *(_BYTE *)(result + a5) = i;
      ++result;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A9E60
// Name: sub_101A9E60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101A9E60(int a1, int a2, int a3, int a4, int a5, int a6, _BYTE *a7)
{
  int result; // eax
  int v8; // ebx
  _DWORD *v9; // esi
  int v10; // eax
  int v11; // edx
  int v12; // ecx
  int v13; // esi
  int v14; // ebp
  _BYTE *v15; // edx
  int v16; // esi
  int v17; // ebp
  int v18; // edi
  int *v19; // ecx
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  bool v24; // sf
  int v25; // [esp+4h] [ebp-21Ch]
  int v26; // [esp+8h] [ebp-218h]
  int v27; // [esp+Ch] [ebp-214h]
  int i; // [esp+10h] [ebp-210h]
  int v29; // [esp+14h] [ebp-20Ch]
  int v30; // [esp+18h] [ebp-208h]
  int v31; // [esp+1Ch] [ebp-204h]
  _DWORD v32[128]; // [esp+20h] [ebp-200h] BYREF

  memset32(v32, 0x7FFFFFFF, 0x80u);
  result = 0;
  for ( i = 0; i < a5; ++i )
  {
    v8 = *(unsigned __int8 *)(result + a6);
    v9 = *(_DWORD **)(a1 + 116);
    v10 = a2 - *(unsigned __int8 *)(v8 + *v9);
    v11 = 3 * (a3 - *(unsigned __int8 *)(v9[1] + v8));
    v12 = a4 - *(unsigned __int8 *)(v9[2] + v8);
    v13 = v11 * v11 + v12 * v12;
    v10 *= 2;
    v14 = 3 * v11 + 18;
    v15 = a7;
    v16 = v10 * v10 + v13;
    v17 = 8 * v14;
    v18 = 16 * (v12 + 4);
    v31 = v17;
    v19 = v32;
    v25 = 32 * (v10 + 8);
    v26 = 3;
    while ( 1 )
    {
      v20 = v16;
      v29 = v16;
      v27 = v17;
      v30 = 7;
      do
      {
        if ( v20 < *v19 )
        {
          *v19 = v20;
          *v15 = v8;
        }
        v21 = v18 + v20;
        if ( v21 < v19[1] )
        {
          v19[1] = v21;
          v15[1] = v8;
        }
        v22 = v18 + 128 + v21;
        if ( v22 < v19[2] )
        {
          v19[2] = v22;
          v15[2] = v8;
        }
        v23 = v18 + 256 + v22;
        if ( v23 < v19[3] )
        {
          v19[3] = v23;
          v15[3] = v8;
        }
        v20 = v27 + v29;
        v19 += 4;
        v15 += 4;
        v24 = --v30 < 0;
        v29 += v27;
        v27 += 288;
      }
      while ( !v24 );
      v16 += v25;
      v24 = --v26 < 0;
      v25 += 512;
      if ( v24 )
        break;
      v17 = v31;
    }
    result = i + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101A9FE0
// Name: sub_101A9FE0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_WORD *__cdecl sub_101A9FE0(int a1, int a2, int a3)
{
  int v3; // ecx
  int v4; // esi
  int v5; // ebx
  int v6; // eax
  unsigned __int8 *v7; // ecx
  _DWORD *v8; // edi
  int i; // ebp
  int v10; // edx
  int j; // ebx
  _WORD *result; // eax
  __int16 v13; // si
  int v14; // [esp+10h] [ebp-18Ch]
  int v15; // [esp+14h] [ebp-188h]
  _BYTE v16[128]; // [esp+18h] [ebp-184h] BYREF
  _BYTE v17[256]; // [esp+98h] [ebp-104h] BYREF
  int v18; // [esp+1A4h] [ebp+8h]
  int v19; // [esp+1A8h] [ebp+Ch]

  v4 = v3 >> 3;
  v19 = a3 >> 2;
  v18 = a2 >> 2;
  v5 = 32 * (v3 >> 3) + 2;
  v15 = *(_DWORD *)(*(_DWORD *)(a1 + 424) + 24);
  v6 = sub_101A9C90(a1, a2: v5, a3: 32 * v18 + 4, a4: 32 * v19 + 4, a5: (int)v17);
  sub_101A9E60(a1, a2: 32 * v18 + 4, a3: v5, a4: 32 * v19 + 4, a5: v6, a6: (int)v17, a7: v16);
  v7 = v16;
  v14 = 2 * (4 * v19 + (v4 << 8));
  v8 = (_DWORD *)(v15 + 16 * v18);
  for ( i = 4; i != 0; --i )
  {
    v10 = v14;
    for ( j = 8; j != 0; --j )
    {
      result = (_WORD *)(v10 + *v8);
      *result = *v7 + 1;
      result[1] = v7[1] + 1;
      result[2] = v7[2] + 1;
      v13 = v7[3] + 1;
      v7 += 4;
      v10 += 64;
      result[3] = v13;
    }
    ++v8;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AA120
// Name: sub_101AA120
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__cdecl sub_101AA120(int a1, int a2, _DWORD *a3, int a4)
{
  _DWORD *result; // eax
  int v5; // ecx
  int v6; // edx
  unsigned __int8 *v7; // esi
  _BYTE *v8; // ebx
  unsigned int v9; // eax
  unsigned int v10; // ecx
  unsigned __int8 *v11; // esi
  int v12; // eax
  int v13; // edx
  _WORD *v14; // edi
  bool v15; // zf
  _DWORD *v16; // [esp+4h] [ebp-14h]
  int v17; // [esp+8h] [ebp-10h]
  int v18; // [esp+Ch] [ebp-Ch]
  int v19; // [esp+10h] [ebp-8h]
  int v20; // [esp+28h] [ebp+10h]

  result = (_DWORD *)a1;
  v5 = *(_DWORD *)(a1 + 92);
  v18 = *(_DWORD *)(*(_DWORD *)(a1 + 424) + 24);
  v19 = v5;
  if ( a4 > 0 )
  {
    result = a3;
    v6 = a2 - (_DWORD)a3;
    v16 = a3;
    v17 = a4;
    do
    {
      v7 = *(unsigned __int8 **)((char *)result + v6);
      v8 = (_BYTE *)*result;
      v20 = v5;
      if ( v5 != 0 )
      {
        do
        {
          v9 = *v7;
          v10 = v7[1];
          v11 = v7 + 1;
          v12 = v9 >> 3;
          v13 = v11[1] >> 3;
          v14 = (_WORD *)(*(_DWORD *)(v18 + 4 * v12) + 2 * (v13 + 32 * (v10 >> 2)));
          v7 = v11 + 2;
          if ( *v14 == 0 )
            sub_101A9FE0(a1, a2: v12, a3: v13);
          *v8++ = *(_BYTE *)v14 - 1;
          --v20;
        }
        while ( v20 != 0 );
        v5 = v19;
        result = v16;
        v6 = a2 - (_DWORD)a3;
      }
      ++result;
      v15 = v17-- == 1;
      v16 = result;
    }
    while ( !v15 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AA1F0
// Name: sub_101AA1F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101AA1F0(_DWORD *a1, int a2, _BYTE **a3, int a4)
{
  int v4; // edx
  int v5; // esi
  int *v6; // eax
  int result; // eax
  int v8; // ecx
  int v9; // edi
  int v10; // ebp
  unsigned __int8 *v11; // eax
  _WORD *v12; // ebx
  int v13; // esi
  int v14; // ebp
  int v15; // esi
  int v16; // edi
  int v17; // ebp
  int v18; // ecx
  int v19; // edx
  bool v20; // zf
  unsigned __int16 *v21; // ecx
  int v22; // eax
  int v23; // edi
  int v24; // ebp
  int v25; // ecx
  int v26; // eax
  int v27; // edi
  __int16 v28; // dx
  int v29; // eax
  int v30; // ebp
  unsigned __int16 v31; // dx
  int v32; // [esp+8h] [ebp-60h]
  _BYTE *v33; // [esp+Ch] [ebp-5Ch]
  int v34; // [esp+10h] [ebp-58h]
  __int16 v35; // [esp+14h] [ebp-54h]
  __int16 v36; // [esp+18h] [ebp-50h]
  unsigned __int16 v37; // [esp+1Ch] [ebp-4Ch]
  _BYTE **v38; // [esp+20h] [ebp-48h]
  __int16 v39; // [esp+24h] [ebp-44h]
  __int16 v40; // [esp+28h] [ebp-40h]
  __int16 v41; // [esp+2Ch] [ebp-3Ch]
  int v42; // [esp+30h] [ebp-38h]
  int v43; // [esp+34h] [ebp-34h]
  int v44; // [esp+38h] [ebp-30h]
  int v45; // [esp+3Ch] [ebp-2Ch]
  int v46; // [esp+40h] [ebp-28h]
  int v47; // [esp+44h] [ebp-24h]
  int v48; // [esp+4Ch] [ebp-1Ch]
  unsigned __int16 *v49; // [esp+58h] [ebp-10h]
  int v50; // [esp+5Ch] [ebp-Ch]
  int v51; // [esp+60h] [ebp-8h]
  int v52; // [esp+64h] [ebp-4h]
  int v53; // [esp+78h] [ebp+10h]

  v4 = a1[23];
  v5 = a1[106];
  v48 = *(_DWORD *)(v5 + 24);
  v6 = (int *)a1[29];
  v50 = *v6;
  v51 = v6[1];
  v52 = v6[2];
  result = a4;
  v34 = a1[72];
  v8 = *(_DWORD *)(v5 + 40);
  v9 = 0;
  v46 = v5;
  v44 = v4;
  v45 = v8;
  if ( a4 > 0 )
  {
    v10 = a2 - (_DWORD)a3;
    v38 = a3;
    v47 = a4;
    while ( 1 )
    {
      v11 = *(_BYTE **)((char *)v38 + v10);
      v32 = (int)v11;
      v33 = *v38;
      if ( *(_BYTE *)(v5 + 36) != 0 )
      {
        v32 = (int)&v11[2 * v4 - 3 + v4];
        v33 = &(*v38)[v4 - 1];
        v12 = (_WORD *)(*(_DWORD *)(v5 + 32) + 2 * (3 * v4 + 3));
        v11 = (unsigned __int8 *)v32;
        v42 = -1;
        v53 = -3;
        *(_BYTE *)(v5 + 36) = 0;
      }
      else
      {
        v12 = *(_WORD **)(v5 + 32);
        v42 = 1;
        v53 = 3;
        *(_BYTE *)(v5 + 36) = 1;
      }
      v4 = v44;
      v13 = 0;
      v14 = 0;
      v41 = 0;
      v40 = 0;
      v39 = 0;
      v37 = 0;
      v36 = 0;
      v35 = 0;
      v43 = v44;
      if ( v44 != 0 )
      {
        while ( 1 )
        {
          v15 = *(unsigned __int8 *)(*v11 + *(_DWORD *)(v8 + 4 * (((__int16)v12[v53] + v13 + 8) >> 4)) + v34);
          v16 = *(unsigned __int8 *)(v11[1] + *(_DWORD *)(v8 + 4 * (((__int16)v12[v53 + 1] + v9 + 8) >> 4)) + v34);
          v17 = *(unsigned __int8 *)(v11[2] + *(_DWORD *)(v8 + 4 * (((__int16)v12[v53 + 2] + v14 + 8) >> 4)) + v34);
          v18 = (v17 >> 3) + 32 * (v16 >> 2);
          v19 = *(_DWORD *)(v48 + 4 * (v15 >> 3));
          v20 = *(_WORD *)(v19 + 2 * v18) == 0;
          v21 = (unsigned __int16 *)(v19 + 2 * v18);
          v49 = v21;
          if ( v20 )
          {
            sub_101A9FE0((int)a1, a2: v15 >> 3, a3: v17 >> 3);
            v21 = v49;
          }
          v22 = *v21 - 1;
          *v33 = v22;
          v23 = v16 - *(unsigned __int8 *)(v22 + v51);
          v24 = v17 - *(unsigned __int8 *)(v22 + v52);
          v25 = v15 - *(unsigned __int8 *)(v22 + v50);
          *v12 = 3 * v25 + v35;
          v35 = 5 * v25 + v39;
          v13 = 7 * v25;
          v39 = v25;
          LOWORD(v25) = v23;
          v26 = 2 * v23;
          v23 *= 3;
          v12[1] = v23 + v36;
          v27 = v26 + v23;
          v28 = v27 + v40;
          v9 = v26 + v27;
          v29 = 2 * v24;
          v36 = v28;
          v40 = v25;
          LOWORD(v25) = v24;
          v24 *= 3;
          v12[2] = v24 + v37;
          v30 = v29 + v24;
          v31 = v30 + v41;
          v41 = v25;
          v33 += v42;
          v8 = v45;
          v14 = v29 + v30;
          v32 += v53;
          v20 = v43-- == 1;
          v37 = v31;
          v12 += v53;
          if ( v20 )
            break;
          v11 = (unsigned __int8 *)v32;
        }
        v4 = v44;
      }
      ++v38;
      v5 = v46;
      *v12 = v35;
      v12[1] = v36;
      result = v37;
      v9 = 0;
      v20 = v47-- == 1;
      v12[2] = v37;
      if ( v20 )
        break;
      v10 = a2 - (_DWORD)a3;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AA4B0
// Name: sub_101AA4B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101AA4B0@<eax>(int a1@<eax>)
{
  int v1; // esi
  int result; // eax
  int v3; // edx
  int v4; // ecx
  int v5; // edi
  _DWORD *v6; // esi
  _DWORD *v7; // esi
  _DWORD *v8; // esi

  v1 = *(_DWORD *)(a1 + 424);
  result = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, a2: 1, a3: 2044) + 1020;
  *(_DWORD *)(v1 + 40) = result;
  v3 = 0;
  v4 = 0;
  v5 = 0;
  v6 = (_DWORD *)result;
  do
  {
    *(_DWORD *)(result + 4 * v4) = v3;
    *v6 = v5;
    ++v4;
    --v6;
    ++v3;
    --v5;
  }
  while ( v4 < 16 );
  if ( v4 < 48 )
  {
    v7 = (_DWORD *)(result - 4 * v4);
    do
    {
      *(_DWORD *)(result + 4 * v4) = v3;
      *v7 = -v3;
      ++v4;
      --v7;
      v3 += (v4 & 1) == 0;
    }
    while ( v4 < 48 );
  }
  if ( v4 <= 255 )
  {
    v8 = (_DWORD *)(result - 4 * v4);
    do
    {
      *(_DWORD *)(result + 4 * v4) = v3;
      *v8 = -v3;
      ++v4;
      --v8;
    }
    while ( v4 <= 255 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AA560
// Name: sub_101AA560
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101AA560(int a1)
{
  int v1; // esi
  int result; // eax

  v1 = *(_DWORD *)(a1 + 424);
  *(_DWORD *)(a1 + 116) = *(_DWORD *)(v1 + 16);
  result = sub_101A9C00(a1, a2: *(_DWORD *)(v1 + 20));
  *(_BYTE *)(v1 + 28) = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AA590
// Name: sub_101AA590
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_101AA590(_DWORD *a1, char a2)
{
  bool v3; // zf
  int v4; // edi
  int v5; // ebp
  unsigned int v6; // ebp
  int i; // esi
  int v8; // [esp+Ch] [ebp+4h]

  v3 = a1[19] == 0;
  v4 = a1[106];
  v8 = *(_DWORD *)(v4 + 24);
  if ( !v3 )
    a1[19] = 2;
  if ( a2 != 0 )
  {
    *(_DWORD *)(v4 + 4) = sub_101A9440;
    *(_DWORD *)(v4 + 8) = sub_101AA560;
    *(_BYTE *)(v4 + 28) = 1;
  }
  else
  {
    if ( a1[19] == 2 )
      *(_DWORD *)(v4 + 4) = sub_101AA1F0;
    else
      *(_DWORD *)(v4 + 4) = sub_101AA120;
    *(_DWORD *)(v4 + 8) = CDummyMaterialSystem::EndBatch;
    v5 = a1[28];
    if ( v5 < 1 )
    {
      *(_DWORD *)(*a1 + 20) = 56;
      *(_DWORD *)(*a1 + 24) = 1;
      (*(void (__cdecl **)(_DWORD *))*a1)(a1);
    }
    if ( v5 > 256 )
    {
      *(_DWORD *)(*a1 + 20) = 57;
      *(_DWORD *)(*a1 + 24) = 256;
      (*(void (__cdecl **)(_DWORD *))*a1)(a1);
    }
    if ( a1[19] == 2 )
    {
      v6 = 6 * (a1[23] + 2);
      if ( *(_DWORD *)(v4 + 32) == 0 )
        *(_DWORD *)(v4 + 32) = (*(int (__cdecl **)(_DWORD *, int, unsigned int))(a1[1] + 4))(a1, a2: 1, a3: v6);
      jzero_far(dst: *(unsigned __int8 **)(v4 + 32), count: v6);
      if ( *(_DWORD *)(v4 + 40) == 0 )
        sub_101AA4B0((int)a1);
      *(_BYTE *)(v4 + 36) = 0;
    }
  }
  if ( *(_BYTE *)(v4 + 28) != 0 )
  {
    for ( i = 0; i < 32; ++i )
      jzero_far(dst: *(unsigned __int8 **)(v8 + 4 * i), count: 0x1000u);
    *(_BYTE *)(v4 + 28) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AA6B0
// Name: sub_101AA6B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101AA6B0(int a1)
{
  *(_BYTE *)(*(_DWORD *)(a1 + 424) + 28) = 1;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x101AA6C0
// Name: void jinit_2pass_quantizer(struct jpeg_decompress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jinit_2pass_quantizer(struct jpeg_decompress_struct *a1)
{
  int v1; // edi
  int i; // ebp
  int v3; // ebp

  v1 = (**((int (__cdecl ***)(struct jpeg_decompress_struct *, int, int))a1 + 1))(a1, a2: 1, a3: 44);
  *((_DWORD *)a1 + 106) = v1;
  *(_DWORD *)v1 = sub_101AA590;
  *(_DWORD *)(v1 + 12) = sub_101AA6B0;
  *(_DWORD *)(v1 + 32) = 0;
  *(_DWORD *)(v1 + 40) = 0;
  if ( *((_DWORD *)a1 + 25) != 3 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 47;
    (**(void (__cdecl ***)(struct jpeg_decompress_struct *))a1)(a1);
  }
  *(_DWORD *)(v1 + 24) = (**((int (__cdecl ***)(struct jpeg_decompress_struct *, int, int))a1 + 1))(a1, a2: 1, a3: 128);
  for ( i = 0; i < 128; i += 4 )
    *(_DWORD *)(*(_DWORD *)(v1 + 24) + i) = (*(int (__cdecl **)(struct jpeg_decompress_struct *, int, int))(*((_DWORD *)a1 + 1) + 4))(
                                              a1,
                                              a2: 1,
                                              a3: 4096);
  *(_BYTE *)(v1 + 28) = 1;
  if ( *((_BYTE *)a1 + 90) != 0 )
  {
    v3 = *((_DWORD *)a1 + 21);
    if ( v3 < 8 )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 56;
      *(_DWORD *)(*(_DWORD *)a1 + 24) = 8;
      (**(void (__cdecl ***)(struct jpeg_decompress_struct *))a1)(a1);
    }
    if ( v3 > 256 )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 57;
      *(_DWORD *)(*(_DWORD *)a1 + 24) = 256;
      (**(void (__cdecl ***)(struct jpeg_decompress_struct *))a1)(a1);
    }
    *(_DWORD *)(v1 + 16) = (*(int (__cdecl **)(struct jpeg_decompress_struct *, int, int, int))(*((_DWORD *)a1 + 1) + 8))(
                             a1,
                             a2: 1,
                             a3: v3,
                             a4: 3);
    *(_DWORD *)(v1 + 20) = v3;
  }
  else
  {
    *(_DWORD *)(v1 + 16) = 0;
  }
  if ( *((_DWORD *)a1 + 19) != 0 )
    *((_DWORD *)a1 + 19) = 2;
  if ( *((_DWORD *)a1 + 19) == 2 )
  {
    *(_DWORD *)(v1 + 32) = (*(int (__cdecl **)(struct jpeg_decompress_struct *, int, int))(*((_DWORD *)a1 + 1) + 4))(
                             a1,
                             a2: 1,
                             a3: 6 * (*((_DWORD *)a1 + 23) + 2));
    sub_101AA4B0((int)a1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AA810
// Name: sub_101AA810
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101AA810(_DWORD *a1, void *a2)
{
  signed int v2; // esi
  int v3; // ebp
  int v4; // eax
  int v5; // ecx
  int v6; // ebp
  int v7; // ebx
  signed int v8; // edx
  int v9; // ebp
  int v10; // edi
  int v11; // esi
  char v13; // [esp+13h] [ebp-9h]
  int v14; // [esp+14h] [ebp-8h]
  int v15; // [esp+18h] [ebp-4h]

  v2 = a1[25];
  v14 = v2;
  v15 = a1[21];
  v3 = 1;
  do
  {
    v4 = ++v3;
    if ( v2 > 1 )
    {
      v5 = v2 - 1;
      do
      {
        v4 *= v3;
        --v5;
      }
      while ( v5 != 0 );
    }
  }
  while ( v4 <= a1[21] );
  v6 = v3 - 1;
  if ( v6 < 2 )
  {
    *(_DWORD *)(*a1 + 20) = 56;
    *(_DWORD *)(*a1 + 24) = v4;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  v7 = 1;
  if ( v2 > 0 )
  {
    v8 = v2;
    memset32(a2, v6, v2);
    do
    {
      v7 *= v6;
      --v8;
    }
    while ( v8 != 0 );
  }
  while ( 2 )
  {
    v9 = 0;
    v13 = 0;
    if ( v2 > 0 )
    {
      while ( 1 )
      {
        v10 = a1[11] == 2 ? dword_102ACCD8[v9] : v9;
        v11 = *((_DWORD *)a2 + v10);
        if ( (v11 + 1) * (v7 / v11) > v15 )
          break;
        ++v9;
        *((_DWORD *)a2 + v10) = v11 + 1;
        v7 = (v11 + 1) * (v7 / v11);
        v13 = 1;
        if ( v9 >= v14 )
          goto LABEL_12;
      }
      if ( v13 != 0 )
      {
LABEL_12:
        v2 = v14;
        continue;
      }
    }
    return v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AA900
// Name: sub_101AA900
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101AA900@<eax>(int a1@<ecx>, int a2@<esi>)
{
  return (a2 / 2 + 255 * a1) / a2;
}

//------------------------------------------------------------------------------
// Address: 0x101AA920
// Name: sub_101AA920
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101AA920@<eax>(int a1@<eax>, int a2@<ecx>)
{
  return (510 * a1 + a2 + 255) / (2 * a2);
}

//------------------------------------------------------------------------------
// Address: 0x101AA940
// Name: sub_101AA940
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101AA940(_DWORD *a1)
{
  _DWORD *v1; // ebp
  _DWORD *v2; // ebx
  int *v3; // esi
  int v4; // edi
  int *v5; // eax
  int result; // eax
  int v7; // ecx
  _DWORD *v8; // ebx
  int v9; // esi
  int v10; // edi
  int v11; // ebp
  char v12; // al
  int i; // edx
  int j; // ecx
  int v15; // esi
  bool v16; // cc
  int v17; // [esp+10h] [ebp-20h]
  int v18; // [esp+14h] [ebp-1Ch]
  int *v19; // [esp+18h] [ebp-18h]
  int v20; // [esp+1Ch] [ebp-14h]
  int v21; // [esp+20h] [ebp-10h]
  int v22; // [esp+24h] [ebp-Ch]
  int v23; // [esp+28h] [ebp-8h]
  _DWORD *v24; // [esp+2Ch] [ebp-4h]

  v1 = a1;
  v2 = (_DWORD *)a1[106];
  v3 = v2 + 8;
  v24 = v2;
  v4 = sub_101AA810(a1, a2: v2 + 8);
  v20 = v4;
  if ( a1[25] == 3 )
  {
    v5 = (int *)(*a1 + 24);
    *v5 = v4;
    v5[1] = *v3;
    v5[2] = v2[9];
    v5[3] = v2[10];
    *(_DWORD *)(*a1 + 20) = 94;
  }
  else
  {
    *(_DWORD *)(*a1 + 20) = 95;
    *(_DWORD *)(*a1 + 24) = v4;
  }
  (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, a2: 1);
  result = (*(int (__cdecl **)(_DWORD *, int, int, _DWORD))(a1[1] + 8))(a1, a2: 1, a3: v4, a4: a1[25]);
  v7 = result;
  v23 = result;
  v18 = v4;
  v22 = 0;
  if ( (int)a1[25] <= 0 )
  {
    v2[5] = v4;
    v2[4] = result;
  }
  else
  {
    v8 = (_DWORD *)result;
    v19 = v3;
    do
    {
      v9 = *v19;
      v21 = *v19;
      v17 = 0;
      v10 = v18 / *v19;
      if ( *v19 > 0 )
      {
        v11 = 0;
        while ( 1 )
        {
          v12 = sub_101AA900(a1: v17, a2: v9 - 1);
          for ( i = v11; i < v20; i += v18 )
          {
            for ( j = 0; j < v10; *(_BYTE *)(v15 + i) = v12 )
            {
              v15 = j + *v8;
              ++j;
            }
          }
          v11 += v10;
          if ( ++v17 >= v21 )
            break;
          v9 = v21;
        }
        v1 = a1;
        v7 = v23;
      }
      ++v19;
      ++v8;
      v16 = v22 + 1 < v1[25];
      v18 = v10;
      ++v22;
    }
    while ( v16 );
    v24[4] = v7;
    v24[5] = v20;
    return (int)v24;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AAAB0
// Name: sub_101AAAB0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101AAAB0(_DWORD *a1)
{
  int v1; // esi
  int v2; // eax
  int v3; // ecx
  int result; // eax
  int v5; // ebp
  _BYTE *v6; // edi
  int v7; // ebp
  int v8; // ebx
  int v9; // ecx
  int i; // esi
  int v11; // eax
  _BYTE *v12; // ecx
  int v13; // [esp+8h] [ebp-14h]
  int v14; // [esp+Ch] [ebp-10h]
  int *v15; // [esp+10h] [ebp-Ch]
  int v16; // [esp+14h] [ebp-8h]
  int v17; // [esp+18h] [ebp-4h]

  v1 = a1[106];
  v17 = v1;
  if ( a1[19] == 1 )
  {
    v13 = 510;
    *(_BYTE *)(v1 + 28) = 1;
  }
  else
  {
    v13 = 0;
    *(_BYTE *)(v1 + 28) = 0;
  }
  v2 = (*(int (__cdecl **)(_DWORD *, int, int, _DWORD))(a1[1] + 8))(a1, a2: 1, a3: v13 + 256, a4: a1[25]);
  v3 = 0;
  *(_DWORD *)(v1 + 24) = v2;
  result = *(_DWORD *)(v1 + 20);
  v14 = 0;
  if ( (int)a1[25] > 0 )
  {
    v15 = (int *)(v1 + 32);
    while ( 1 )
    {
      v5 = *v15;
      v16 = result / *v15;
      if ( v13 != 0 )
        *(_DWORD *)(*(_DWORD *)(v1 + 24) + 4 * v3) += 255;
      v6 = *(_BYTE **)(*(_DWORD *)(v1 + 24) + 4 * v3);
      v7 = v5 - 1;
      v8 = 0;
      v9 = sub_101AA920(a1: 0, a2: v7);
      for ( i = 0; i <= 255; ++i )
      {
        for ( ; i > v9; v9 = sub_101AA920(a1: v8, a2: v7) )
          ++v8;
        v6[i] = v8 * v16;
      }
      if ( v13 != 0 )
      {
        v11 = 1;
        v12 = v6 - 1;
        do
        {
          *v12 = *v6;
          v6[v11++ + 255] = v6[255];
          --v12;
        }
        while ( v11 <= 255 );
      }
      ++v15;
      result = ++v14;
      if ( v14 >= a1[25] )
        break;
      result = v16;
      v1 = v17;
      v3 = v14;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AAC00
// Name: sub_101AAC00
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101AAC00@<eax>(int a1@<eax>, int a2@<ecx>)
{
  int v3; // ebp
  int v4; // ebx
  double *v5; // edi
  int v6; // esi
  int i; // ecx
  int v8; // eax

  v3 = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, a2: 1, a3: 1024);
  v4 = (a2 << 9) - 512;
  v5 = dbl_102ACBD8;
  v6 = v3;
  do
  {
    for ( i = 0; i < 16; ++i )
    {
      v8 = (65025 - 510 * *((unsigned __int8 *)v5 + i)) / v4;
      v6 += 4;
      *(_DWORD *)(v6 - 4) = v8;
    }
    v5 += 2;
  }
  while ( (int)v5 < (int)dword_102ACCD8 );
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101AAC80
// Name: sub_101AAC80
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_101AAC80(int a1@<ebx>)
{
  int v1; // ebp
  int v2; // esi
  int *v3; // edi
  int v4; // ecx
  int v5; // eax
  _DWORD *v6; // edx
  int v7; // eax

  v1 = *(_DWORD *)(a1 + 424);
  v2 = 0;
  if ( *(int *)(a1 + 100) > 0 )
  {
    v3 = (int *)(v1 + 52);
    do
    {
      v4 = *(v3 - 5);
      v5 = 0;
      if ( v2 <= 0 )
        goto LABEL_9;
      v6 = (_DWORD *)(v1 + 32);
      while ( v4 != *v6 )
      {
        ++v5;
        ++v6;
        if ( v5 >= v2 )
          goto LABEL_9;
      }
      v7 = *(_DWORD *)(v1 + 4 * v5 + 52);
      if ( v7 == 0 )
LABEL_9:
        v7 = sub_101AAC00(a1, a2: v4);
      *v3 = v7;
      ++v2;
      ++v3;
    }
    while ( v2 < *(_DWORD *)(a1 + 100) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AACD0
// Name: sub_101AACD0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_BYTE *__cdecl sub_101AACD0(_DWORD *a1, int a2, _DWORD *a3, int a4)
{
  int v4; // ebx
  int v5; // esi
  _BYTE *result; // eax
  int v7; // edi
  _DWORD *v8; // edx
  int v9; // ebp
  unsigned __int8 *v10; // ecx
  char v11; // dl
  int i; // eax
  char v13; // bl
  bool v14; // zf
  _DWORD *v15; // [esp+Ch] [ebp-10h]
  int v16; // [esp+10h] [ebp-Ch]
  int v17; // [esp+18h] [ebp-4h]
  _BYTE *v18; // [esp+20h] [ebp+4h]
  int v19; // [esp+2Ch] [ebp+10h]

  v4 = a1[23];
  v5 = a1[25];
  result = (_BYTE *)a4;
  v7 = *(_DWORD *)(a1[106] + 24);
  v17 = v4;
  if ( a4 > 0 )
  {
    v8 = a3;
    v9 = a2 - (_DWORD)a3;
    v15 = a3;
    v16 = a4;
    do
    {
      result = (_BYTE *)*v8;
      v10 = *(unsigned __int8 **)((char *)v8 + v9);
      v18 = (_BYTE *)*v8;
      v19 = v4;
      if ( v4 != 0 )
      {
        do
        {
          v11 = 0;
          for ( i = 0; i < v5; ++v10 )
          {
            v13 = *(_BYTE *)(*v10 + *(_DWORD *)(v7 + 4 * i++));
            v11 += v13;
          }
          *v18 = v11;
          result = v18 + 1;
          v14 = v19-- == 1;
          ++v18;
        }
        while ( !v14 );
        v9 = a2 - (_DWORD)a3;
        v8 = v15;
        v4 = v17;
      }
      ++v8;
      v14 = v16-- == 1;
      v15 = v8;
    }
    while ( !v14 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AAD80
// Name: sub_101AAD80
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl sub_101AAD80(int a1, int a2, _BYTE **a3, int a4)
{
  int *v4; // eax
  int v5; // edx
  int v6; // esi
  int v7; // edi
  unsigned __int8 *result; // eax
  _BYTE **v9; // ecx
  int v10; // ebx
  _BYTE *v11; // edx
  char v12; // bl
  char v13; // cl
  unsigned __int8 *v14; // eax
  bool v15; // zf
  int v16; // [esp+8h] [ebp-10h]
  int v17; // [esp+Ch] [ebp-Ch]
  int v18; // [esp+10h] [ebp-8h]
  _BYTE **v19; // [esp+1Ch] [ebp+4h]

  v4 = *(int **)(*(_DWORD *)(a1 + 424) + 24);
  v5 = v4[1];
  v6 = *(_DWORD *)(a1 + 92);
  v7 = *v4;
  v17 = v4[2];
  result = (unsigned __int8 *)a4;
  v16 = v5;
  v18 = v6;
  if ( a4 > 0 )
  {
    v9 = a3;
    v10 = a2 - (_DWORD)a3;
    v19 = a3;
    do
    {
      result = *(_BYTE **)((char *)v9 + v10);
      v11 = *v9;
      if ( v6 != 0 )
      {
        do
        {
          v12 = *(_BYTE *)(result[1] + v16);
          v13 = *(_BYTE *)(*result + v7);
          v14 = result + 1;
          *v11 = *(_BYTE *)(v14[1] + v17) + v12 + v13;
          result = v14 + 2;
          ++v11;
          --v6;
        }
        while ( v6 != 0 );
        v6 = v18;
        v9 = v19;
        v10 = a2 - (_DWORD)a3;
      }
      ++v9;
      v15 = a4-- == 1;
      v19 = v9;
    }
    while ( !v15 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AAE40
// Name: sub_101AAE40
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl sub_101AAE40(_DWORD *count, int a2, unsigned __int8 **a3, unsigned __int8 *a4)
{
  _DWORD *v4; // esi
  unsigned __int8 *result; // eax
  unsigned __int8 **v6; // ebx
  int v7; // ebp
  int v8; // edx
  int v9; // ebp
  unsigned __int8 *v10; // ecx
  int v11; // edi
  unsigned int v12; // ebp
  int v13; // esi
  int v14; // edx
  bool v15; // zf
  int v16; // [esp+4h] [ebp-24h]
  int v17; // [esp+8h] [ebp-20h]
  _DWORD *v18; // [esp+Ch] [ebp-1Ch]
  int v19; // [esp+10h] [ebp-18h]
  unsigned __int8 *v20; // [esp+14h] [ebp-14h]
  int v21; // [esp+18h] [ebp-10h]
  int v22; // [esp+20h] [ebp-8h]
  char v23; // [esp+24h] [ebp-4h]
  unsigned int counta; // [esp+2Ch] [ebp+4h]
  _DWORD *v25; // [esp+38h] [ebp+10h]

  v4 = (_DWORD *)count[106];
  result = a4;
  v18 = v4;
  v16 = count[25];
  counta = count[23];
  if ( (int)a4 > 0 )
  {
    v6 = a3;
    v19 = (int)a3;
    v20 = a4;
    do
    {
      jzero_far(dst: *v6, count: counta);
      v7 = v4[12];
      v8 = 0;
      v23 = v7;
      v17 = 0;
      if ( v16 > 0 )
      {
        v9 = v7 << 6;
        v21 = v9;
        v25 = v4 + 13;
        while ( 1 )
        {
          v10 = *v6;
          v22 = *(_DWORD *)(v4[6] + 4 * v8);
          v11 = v9 + *v25;
          v12 = counta;
          result = &(*(unsigned __int8 **)((char *)v6 + a2 - (_DWORD)a3))[v8];
          v13 = 0;
          if ( counta != 0 )
          {
            do
            {
              v14 = *result;
              result += v16;
              *v10++ += *(_BYTE *)(v14 + *(_DWORD *)(v11 + 4 * v13) + v22);
              v13 = ((_BYTE)v13 + 1) & 0xF;
              --v12;
            }
            while ( v12 != 0 );
            v8 = v17;
            v6 = (unsigned __int8 **)v19;
          }
          ++v25;
          v4 = v18;
          v17 = ++v8;
          if ( v8 >= v16 )
            break;
          v9 = v21;
        }
        LOBYTE(v7) = v23;
      }
      ++v6;
      v15 = v20-- == (unsigned __int8 *)1;
      v4[12] = ((_BYTE)v7 + 1) & 0xF;
      v19 = (int)v6;
    }
    while ( !v15 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AAF60
// Name: sub_101AAF60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101AAF60(int a1, int a2, _BYTE **a3, int a4)
{
  _DWORD *v4; // edx
  int *v5; // eax
  int v6; // esi
  int result; // eax
  _BYTE **v8; // ebp
  int v9; // eax
  unsigned __int8 *v10; // eax
  int v11; // esi
  int v12; // edi
  int v13; // ecx
  char v14; // dl
  char v15; // bl
  unsigned __int8 *v16; // eax
  bool v17; // zf
  _BYTE **v18; // [esp+4h] [ebp-28h]
  int v19; // [esp+8h] [ebp-24h]
  int v20; // [esp+10h] [ebp-1Ch]
  int v21; // [esp+14h] [ebp-18h]
  int v22; // [esp+18h] [ebp-14h]
  int v23; // [esp+1Ch] [ebp-10h]
  int v24; // [esp+20h] [ebp-Ch]
  _DWORD *v25; // [esp+24h] [ebp-8h]
  int v26; // [esp+28h] [ebp-4h]
  _BYTE *v27; // [esp+30h] [ebp+4h]
  int v28; // [esp+3Ch] [ebp+10h]

  v4 = *(_DWORD **)(a1 + 424);
  v5 = (int *)v4[6];
  v21 = *v5;
  v6 = v5[1];
  result = v5[2];
  v20 = *(_DWORD *)(a1 + 92);
  v25 = v4;
  v22 = v6;
  v24 = result;
  if ( a4 > 0 )
  {
    v8 = a3;
    v9 = a2 - (_DWORD)a3;
    v18 = a3;
    v19 = a4;
    while ( 1 )
    {
      v10 = *(_BYTE **)((char *)v8 + v9);
      v26 = v4[12];
      v27 = *v8;
      v11 = (v26 << 6) + v4[13];
      v12 = (v26 << 6) + v4[14];
      v23 = (v26 << 6) + v4[15];
      v13 = 0;
      v28 = v20;
      if ( v20 != 0 )
      {
        do
        {
          v14 = *(_BYTE *)(*v10 + *(_DWORD *)(v11 + 4 * v13) + v21);
          v15 = *(_BYTE *)(v22 + v10[1] + *(_DWORD *)(v12 + 4 * v13));
          v16 = v10 + 1;
          *v27 = *(_BYTE *)(v24 + v16[1] + *(_DWORD *)(v23 + 4 * v13)) + v15 + v14;
          v10 = v16 + 2;
          v13 = ((_BYTE)v13 + 1) & 0xF;
          v17 = v28-- == 1;
          ++v27;
        }
        while ( !v17 );
        v4 = v25;
        v8 = v18;
      }
      result = ((_BYTE)v26 + 1) & 0xF;
      ++v8;
      v17 = v19-- == 1;
      v4[12] = result;
      v18 = v8;
      if ( v17 )
        break;
      v9 = a2 - (_DWORD)a3;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AB090
// Name: sub_101AB090
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 __cdecl sub_101AB090(_DWORD *count, int a2, unsigned __int8 **a3, int a4)
{
  int v4; // edx
  int v5; // ebp
  int v6; // esi
  __int16 result; // ax
  unsigned __int8 **v8; // edi
  int v9; // edx
  _WORD **v10; // ecx
  int v11; // ebx
  unsigned __int8 *v12; // edi
  _WORD *v13; // ecx
  unsigned __int8 *v14; // ebx
  int v15; // esi
  int v16; // eax
  int v17; // edx
  int v18; // eax
  int v19; // edx
  bool v20; // zf
  _WORD **i; // [esp+8h] [ebp-38h]
  int v22; // [esp+Ch] [ebp-34h]
  int v23; // [esp+10h] [ebp-30h]
  __int16 v24; // [esp+14h] [ebp-2Ch]
  unsigned int v25; // [esp+1Ch] [ebp-24h]
  int v26; // [esp+20h] [ebp-20h]
  int v27; // [esp+24h] [ebp-1Ch]
  int v28; // [esp+28h] [ebp-18h]
  int v29; // [esp+30h] [ebp-10h]
  int v30; // [esp+34h] [ebp-Ch]
  int v31; // [esp+38h] [ebp-8h]
  int v32; // [esp+3Ch] [ebp-4h]
  unsigned int counta; // [esp+44h] [ebp+4h]
  __int16 v34; // [esp+50h] [ebp+10h]

  v4 = count[72];
  v5 = count[25];
  v6 = count[106];
  result = a4;
  v22 = v6;
  v26 = v5;
  counta = count[23];
  v29 = v4;
  if ( a4 > 0 )
  {
    v8 = a3;
    v23 = (int)a3;
    v28 = a4;
    do
    {
      jzero_far(dst: *v8, count: counta);
      v9 = 0;
      v27 = 0;
      if ( v5 > 0 )
      {
        v10 = (_WORD **)(v6 + 68);
        for ( i = (_WORD **)(v6 + 68); ; v10 = i )
        {
          v11 = *(int *)((char *)v8 + a2 - (_DWORD)a3);
          v12 = *v8;
          v13 = *v10;
          v14 = (unsigned __int8 *)(v9 + v11);
          if ( *(_BYTE *)(v6 + 84) != 0 )
          {
            v12 += counta - 1;
            v14 += v5 * (counta - 1);
            v15 = -1;
            v5 = -v5;
            v13 += counta + 1;
          }
          else
          {
            v15 = 1;
          }
          v30 = *(_DWORD *)(*(_DWORD *)(v22 + 24) + 4 * v9);
          v31 = *(_DWORD *)(*(_DWORD *)(v22 + 16) + 4 * v9);
          v16 = 0;
          v34 = 0;
          v24 = 0;
          v25 = counta;
          if ( counta != 0 )
          {
            do
            {
              v17 = *v14;
              v14 += v5;
              v18 = *(unsigned __int8 *)(v17 + v29 + (((__int16)v13[v15] + v16 + 8) >> 4));
              v19 = *(unsigned __int8 *)(v18 + v30);
              *v12 += v19;
              v32 = v18 - *(unsigned __int8 *)(v19 + v31);
              *v13 = 3 * v32 + v34;
              v34 = 5 * v32 + v24;
              v16 = 7 * v32;
              v12 += v15;
              v20 = v25-- == 1;
              v24 = v32;
              v13 += v15;
            }
            while ( !v20 );
            v9 = v27;
          }
          v5 = v26;
          result = v34;
          ++i;
          v8 = (unsigned __int8 **)v23;
          v6 = v22;
          ++v9;
          *v13 = v34;
          v27 = v9;
          if ( v9 >= v26 )
            break;
        }
      }
      ++v8;
      v20 = v28-- == 1;
      *(_BYTE *)(v6 + 84) = *(_BYTE *)(v6 + 84) == 0;
      v23 = (int)v8;
    }
    while ( !v20 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AB240
// Name: sub_101AB240
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101AB240@<eax>(_DWORD *a1@<esi>)
{
  int result; // eax
  int v2; // edi
  int v3; // ebp
  int *v4; // ebx

  result = a1[106];
  v2 = 0;
  v3 = 2 * a1[23] + 4;
  if ( (int)a1[25] > 0 )
  {
    v4 = (int *)(result + 68);
    do
    {
      result = (*(int (__cdecl **)(_DWORD *, int, int))(a1[1] + 4))(a1, a2: 1, a3: v3);
      *v4 = result;
      ++v2;
      ++v4;
    }
    while ( v2 < a1[25] );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AB280
// Name: sub_101AB280
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_101AB280(_DWORD *a1)
{
  int v1; // edi
  int v2; // eax
  int v3; // eax
  bool v4; // zf
  unsigned __int8 **v5; // ebx
  int v6; // edi
  unsigned int i; // ebp

  v1 = a1[106];
  a1[29] = *(_DWORD *)(v1 + 16);
  v2 = a1[19];
  a1[28] = *(_DWORD *)(v1 + 20);
  if ( v2 != 0 )
  {
    v3 = v2 - 1;
    if ( v3 != 0 )
    {
      if ( v3 == 1 )
      {
        v4 = *(_DWORD *)(v1 + 68) == 0;
        v5 = (unsigned __int8 **)(v1 + 68);
        *(_DWORD *)(v1 + 4) = sub_101AB090;
        *(_BYTE *)(v1 + 84) = 0;
        if ( v4 )
          sub_101AB240(a1);
        v6 = 0;
        for ( i = 2 * a1[23] + 4; v6 < a1[25]; ++v5 )
        {
          jzero_far(dst: *v5, count: i);
          ++v6;
        }
      }
      else
      {
        *(_DWORD *)(*a1 + 20) = 48;
        (*(void (__cdecl **)(_DWORD *))*a1)(a1);
      }
    }
    else
    {
      if ( a1[25] == 3 )
        *(_DWORD *)(v1 + 4) = sub_101AAF60;
      else
        *(_DWORD *)(v1 + 4) = sub_101AAE40;
      v4 = *(_BYTE *)(v1 + 28) == 0;
      *(_DWORD *)(v1 + 48) = 0;
      if ( v4 )
        sub_101AAAB0(a1);
      if ( *(_DWORD *)(v1 + 52) == 0 )
        sub_101AAC80((int)a1);
    }
  }
  else if ( a1[25] == 3 )
  {
    *(_DWORD *)(v1 + 4) = sub_101AAD80;
  }
  else
  {
    *(_DWORD *)(v1 + 4) = sub_101AACD0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AB370
// Name: sub_101AB370
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101AB370(int a1)
{
  *(_DWORD *)(*(_DWORD *)a1 + 20) = 46;
  return (**(int (***)(void))a1)();
}

//------------------------------------------------------------------------------
// Address: 0x101AB390
// Name: void jinit_1pass_quantizer(struct jpeg_decompress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jinit_1pass_quantizer(int (__cdecl ***a1)(struct jpeg_decompress_struct *, int, int))
{
  int (__cdecl **v1)(struct jpeg_decompress_struct *, int, int); // eax

  v1 = (int (__cdecl **)(struct jpeg_decompress_struct *, int, int))(*a1[1])(
                                                                      (struct jpeg_decompress_struct *)a1,
                                                                      a2: 1,
                                                                      a3: 88);
  a1[106] = v1;
  *v1 = (int (__cdecl *)(struct jpeg_decompress_struct *, int, int))sub_101AB280;
  v1[2] = (int (__cdecl *)(struct jpeg_decompress_struct *, int, int))CDummyMaterialSystem::EndBatch;
  v1[3] = (int (__cdecl *)(struct jpeg_decompress_struct *, int, int))sub_101AB370;
  v1[17] = nullptr;
  v1[13] = nullptr;
  if ( (int)a1[25] > 4 )
  {
    (*a1)[5] = (int (__cdecl *)(struct jpeg_decompress_struct *, int, int))55;
    (*a1)[6] = (int (__cdecl *)(struct jpeg_decompress_struct *, int, int))4;
    ((void (__cdecl *)(int (__cdecl ***)(struct jpeg_decompress_struct *, int, int)))**a1)(a1);
  }
  if ( (int)a1[21] > 256 )
  {
    (*a1)[5] = (int (__cdecl *)(struct jpeg_decompress_struct *, int, int))57;
    (*a1)[6] = (int (__cdecl *)(struct jpeg_decompress_struct *, int, int))256;
    ((void (__cdecl *)(int (__cdecl ***)(struct jpeg_decompress_struct *, int, int)))**a1)(a1);
  }
  sub_101AA940(a1);
  sub_101AAAB0(a1);
  if ( a1[19] == (int (__cdecl **)(struct jpeg_decompress_struct *, int, int))2 )
    sub_101AB240(a1);
}

//------------------------------------------------------------------------------
// Address: 0x101AB430
// Name: sub_101AB430
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl sub_101AB430(_DWORD *a1, int a2, _DWORD *a3, int a4)
{
  int v4; // esi
  unsigned int result; // eax
  _DWORD *v6; // ebp
  bool v7; // zf

  v4 = a1[80];
  result = *(_DWORD *)(v4 + 8);
  if ( result < a1[56] )
  {
    v6 = (_DWORD *)(v4 + 12);
    do
    {
      v7 = *v6 == 8;
      if ( *v6 < 8u )
      {
        result = (*(int (__cdecl **)(_DWORD *, int, _DWORD *, int, int, int, int))(a1[81] + 4))(
                   a1,
                   a2,
                   a3,
                   a4,
                   a5: v4 + 24,
                   a6: v4 + 12,
                   a7: 8);
        v7 = *v6 == 8;
      }
      if ( !v7 )
        break;
      result = (*(int (__cdecl **)(_DWORD *, int))(a1[82] + 4))(a1, a2: v4 + 24);
      if ( (_BYTE)result == 0 )
      {
        if ( *(_BYTE *)(v4 + 16) == 0 )
        {
          --*a3;
          *(_BYTE *)(v4 + 16) = 1;
        }
        return result;
      }
      if ( *(_BYTE *)(v4 + 16) != 0 )
      {
        ++*a3;
        *(_BYTE *)(v4 + 16) = 0;
      }
      ++*(_DWORD *)(v4 + 8);
      *v6 = 0;
    }
    while ( *(_DWORD *)(v4 + 8) < a1[56] );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AB4E0
// Name: sub_101AB4E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101AB4E0(int a1, int a2)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 320);
  if ( *(_BYTE *)(a1 + 176) == 0 )
  {
    *(_DWORD *)(result + 8) = 0;
    *(_DWORD *)(result + 12) = 0;
    *(_BYTE *)(result + 16) = 0;
    *(_DWORD *)(result + 20) = a2;
    if ( a2 != 0 )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 4;
      return (**(int (__cdecl ***)(int))a1)(a1);
    }
    else
    {
      *(_DWORD *)(result + 4) = sub_101AB430;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AB530
// Name: void jinit_c_main_controller(struct jpeg_compress_struct __near *,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jinit_c_main_controller(struct jpeg_compress_struct *a1, char a2)
{
  int (__cdecl **v2)(int, int); // eax
  int v3; // ebp
  _DWORD *v4; // edi
  _DWORD *v5; // ebx

  v2 = (int (__cdecl **)(int, int))(**((int (__cdecl ***)(struct jpeg_compress_struct *, int, int))a1 + 1))(
                                     a1,
                                     a2: 1,
                                     a3: 64);
  *((_DWORD *)a1 + 80) = v2;
  *v2 = sub_101AB4E0;
  if ( *((_BYTE *)a1 + 176) == 0 )
  {
    if ( a2 != 0 )
    {
      *(_DWORD *)(*(_DWORD *)a1 + 20) = 4;
      (**(void (__cdecl ***)(struct jpeg_compress_struct *))a1)(a1);
    }
    else
    {
      v3 = 0;
      if ( *((int *)a1 + 15) > 0 )
      {
        v4 = (_DWORD *)(*((_DWORD *)a1 + 17) + 28);
        v5 = v2 + 6;
        do
        {
          *v5 = (*(int (__cdecl **)(struct jpeg_compress_struct *, int, int, int))(*((_DWORD *)a1 + 1) + 8))(
                  a1,
                  a2: 1,
                  a3: 8 * *v4,
                  a4: 8 * *(v4 - 4));
          ++v3;
          ++v5;
          v4 += 21;
        }
        while ( v3 < *((_DWORD *)a1 + 15) );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AB5C0
// Name: sub_101AB5C0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl sub_101AB5C0(_DWORD *a1, int a2)
{
  _DWORD *v2; // esi
  _DWORD *v3; // ebx
  int v4; // eax
  unsigned int v5; // ecx
  unsigned int v7; // ebp
  int v8; // edi
  _DWORD *v9; // esi
  _DWORD *v10; // esi
  int v11; // ebp
  int v12; // eax
  int v13; // eax
  _WORD **v14; // ecx
  int v15; // eax
  _WORD **v16; // eax
  bool v17; // cc
  int v18; // [esp+10h] [ebp-2Ch]
  unsigned int v19; // [esp+14h] [ebp-28h]
  int v20; // [esp+18h] [ebp-24h]
  int v21; // [esp+1Ch] [ebp-20h]
  unsigned int v22; // [esp+20h] [ebp-1Ch]
  int v23; // [esp+24h] [ebp-18h]
  int v24; // [esp+28h] [ebp-14h]
  int v25; // [esp+2Ch] [ebp-10h]
  _DWORD *v26; // [esp+30h] [ebp-Ch]
  unsigned int v27; // [esp+34h] [ebp-8h]
  int v28; // [esp+38h] [ebp-4h]

  v2 = a1;
  v3 = (_DWORD *)a1[82];
  v27 = a1[56] - 1;
  v4 = v3[4];
  v5 = a1[62] - 1;
  v22 = v5;
  v18 = v4;
  if ( v4 < v3[5] )
  {
    while ( 1 )
    {
      v7 = v3[3];
      v19 = v7;
      if ( v7 <= v5 )
        break;
LABEL_28:
      ++v4;
      v3[3] = 0;
      v18 = v4;
      if ( v4 >= v3[5] )
        goto LABEL_2;
      v5 = v22;
    }
    while ( 1 )
    {
      v8 = 0;
      v25 = 0;
      if ( (int)v2[57] > 0 )
      {
        v9 = v2 + 58;
        v26 = v9;
        do
        {
          v10 = (_DWORD *)*v9;
          if ( v7 >= v22 )
            v11 = v10[17];
          else
            v11 = v10[13];
          v28 = v19 * v10[16];
          v23 = v11;
          v20 = 8 * v18;
          v21 = 0;
          if ( (int)v10[14] > 0 )
          {
            v12 = v10[13];
            do
            {
              if ( v3[2] < v27 || v18 + v21 < v10[18] )
              {
                (*(void (__cdecl **)(_DWORD *, _DWORD *, _DWORD, _DWORD, int, int, int))(a1[86] + 4))(
                  a1,
                  a2: v10,
                  a3: *(_DWORD *)(a2 + 4 * v10[1]),
                  a4: v3[v8 + 6],
                  a5: v20,
                  a6: v28,
                  a7: v11);
                v15 = v10[13];
                if ( v11 < v15 )
                {
                  jzero_far(dst: (unsigned __int8 *)v3[v8 + 6 + v11], count: (v15 - v11) << 7);
                  v24 = v11;
                  if ( v11 < v10[13] )
                  {
                    v16 = (_WORD **)&v3[v8 + 6 + v11];
                    do
                    {
                      **v16 = **(v16 - 1);
                      ++v16;
                      ++v24;
                    }
                    while ( v24 < v10[13] );
                  }
                }
              }
              else
              {
                jzero_far(dst: (unsigned __int8 *)v3[v8 + 6], count: v12 << 7);
                v13 = 0;
                if ( (int)v10[13] > 0 )
                {
                  v14 = (_WORD **)&v3[v8 + 6];
                  do
                  {
                    ++v13;
                    **v14++ = *(_WORD *)v3[v8 + 5];
                  }
                  while ( v13 < v10[13] );
                  v11 = v23;
                }
              }
              v12 = v10[13];
              v20 += 8;
              v8 += v12;
              ++v21;
            }
            while ( v21 < v10[14] );
          }
          v7 = v19;
          v9 = v26 + 1;
          v17 = ++v25 < a1[57];
          ++v26;
        }
        while ( v17 );
        v2 = a1;
      }
      if ( (*(unsigned __int8 (__cdecl **)(_DWORD *, _DWORD *))(v2[87] + 4))(a1: v2, a2: v3 + 6) == 0 )
        break;
      v19 = ++v7;
      if ( v7 > v22 )
      {
        v4 = v18;
        goto LABEL_28;
      }
    }
    v3[3] = v7;
    v3[4] = v18;
    return 0;
  }
  else
  {
LABEL_2:
    ++v3[2];
    sub_1019FD10(this: v2);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AB810
// Name: sub_101AB810
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl sub_101AB810(_DWORD *a1)
{
  _DWORD *v1; // ebp
  _DWORD *v2; // edi
  int v3; // esi
  int v4; // eax
  int v5; // esi
  int v6; // edx
  int v7; // ebx
  int v8; // edi
  int v9; // ecx
  _DWORD *v10; // ebp
  int v11; // eax
  int v12; // edx
  int *v13; // esi
  _DWORD *v15; // [esp+10h] [ebp-2Ch]
  unsigned int v16; // [esp+10h] [ebp-2Ch]
  _DWORD *v17; // [esp+14h] [ebp-28h]
  int v18; // [esp+18h] [ebp-24h]
  int v19; // [esp+1Ch] [ebp-20h]
  _DWORD *v20; // [esp+20h] [ebp-1Ch]
  int v21; // [esp+24h] [ebp-18h]
  int v22; // [esp+28h] [ebp-14h]
  _DWORD v23[4]; // [esp+2Ch] [ebp-10h]

  v1 = a1;
  v2 = (_DWORD *)a1[82];
  v3 = 0;
  v20 = v2;
  if ( (int)a1[57] > 0 )
  {
    v15 = a1 + 58;
    do
    {
      v4 = (*(int (__cdecl **)(_DWORD *, _DWORD, int, _DWORD, _DWORD))(a1[1] + 32))(
             a1,
             a2: v2[*(_DWORD *)(*v15 + 4) + 16],
             a3: *(_DWORD *)(*v15 + 12) * v2[2],
             a4: *(_DWORD *)(*v15 + 12),
             a5: 0);
      ++v15;
      v23[v3++] = v4;
    }
    while ( v3 < a1[57] );
  }
  v5 = v2[4];
  v21 = v5;
  if ( v5 >= v2[5] )
  {
LABEL_20:
    ++v2[2];
    sub_1019FD10(this: v1);
    return 1;
  }
  else
  {
    while ( 1 )
    {
      v16 = v2[3];
      if ( v16 < v1[62] )
        break;
LABEL_19:
      ++v5;
      v2[3] = 0;
      v21 = v5;
      if ( v5 >= v2[5] )
        goto LABEL_20;
    }
    while ( 1 )
    {
      v6 = 0;
      v7 = 0;
      v19 = 0;
      if ( (int)v1[57] > 0 )
      {
        v17 = v1 + 58;
        do
        {
          v8 = *v17;
          v9 = *(_DWORD *)(*v17 + 52);
          v18 = 0;
          if ( *(int *)(*v17 + 56) > 0 )
          {
            v22 = (v16 * *(_DWORD *)(*v17 + 52)) << 7;
            v10 = (_DWORD *)(v23[v6] + 4 * v5);
            do
            {
              v11 = v22 + *v10;
              v12 = 0;
              if ( v9 > 0 )
              {
                v13 = &v20[v7 + 6];
                do
                {
                  *v13 = v11;
                  v9 = *(_DWORD *)(v8 + 52);
                  ++v12;
                  ++v7;
                  ++v13;
                  v11 += 128;
                }
                while ( v12 < v9 );
              }
              ++v10;
              ++v18;
            }
            while ( v18 < *(_DWORD *)(v8 + 56) );
            v1 = a1;
            v6 = v19;
            v5 = v21;
          }
          ++v17;
          v19 = ++v6;
        }
        while ( v6 < v1[57] );
        v2 = v20;
      }
      if ( (*(unsigned __int8 (__cdecl **)(_DWORD *, _DWORD *))(v1[87] + 4))(a1: v1, a2: v2 + 6) == 0 )
        break;
      if ( ++v16 >= v1[62] )
        goto LABEL_19;
    }
    v2[4] = v5;
    v2[3] = v16;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AB9D0
// Name: sub_101AB9D0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl sub_101AB9D0(_DWORD *a1, _DWORD *a2)
{
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  int v4; // edi
  unsigned int v5; // ebx
  int v6; // ecx
  unsigned int v7; // ebx
  unsigned int v8; // ebp
  int v9; // edi
  int v10; // ebp
  int v11; // esi
  unsigned __int8 *v12; // esi
  __int16 v13; // cx
  int i; // eax
  unsigned int v15; // ebx
  int v16; // ebp
  unsigned __int8 *v17; // edi
  int v18; // ebx
  int v19; // edx
  int v20; // ecx
  __int16 v21; // si
  unsigned __int8 *v22; // eax
  bool v23; // cc
  int v25; // [esp+Ch] [ebp-2Ch]
  int j; // [esp+Ch] [ebp-2Ch]
  _DWORD *v27; // [esp+10h] [ebp-28h]
  int v28; // [esp+14h] [ebp-24h]
  int v29; // [esp+18h] [ebp-20h]
  _DWORD *v30; // [esp+1Ch] [ebp-1Ch]
  unsigned int v32; // [esp+24h] [ebp-14h]
  int v33; // [esp+28h] [ebp-10h]
  int v34; // [esp+2Ch] [ebp-Ch]
  unsigned int count; // [esp+30h] [ebp-8h]
  int v36; // [esp+34h] [ebp-4h]

  v2 = a1;
  v3 = (_DWORD *)a1[17];
  v4 = a1[82];
  v5 = a1[56] - 1;
  v33 = v4;
  v32 = v5;
  v34 = 0;
  v27 = v3;
  if ( (int)a1[15] > 0 )
  {
    v30 = (_DWORD *)(v4 + 64);
    while ( 1 )
    {
      v6 = (*(int (__cdecl **)(_DWORD *, _DWORD, int, _DWORD, int))(v2[1] + 32))(
             a1: v2,
             a2: *v30,
             a3: v3[3] * *(_DWORD *)(v4 + 8),
             a4: v3[3],
             a5: 1);
      v28 = v6;
      if ( *(_DWORD *)(v4 + 8) >= v5 )
      {
        v25 = v3[8] % v3[3];
        if ( v25 == 0 )
          v25 = v3[3];
      }
      else
      {
        v25 = v3[3];
      }
      v7 = v3[7];
      v8 = v3[2];
      v29 = v8;
      v9 = v7 % v8;
      if ( (int)(v7 % v8) > 0 )
        v9 = v8 - v7 % v8;
      v10 = 0;
      if ( v25 > 0 )
      {
        do
        {
          v11 = *(_DWORD *)(v6 + 4 * v10);
          (*(void (__cdecl **)(_DWORD *, _DWORD *, _DWORD, int, int, _DWORD, unsigned int))(a1[86] + 4))(
            a1,
            a2: v27,
            a3: *a2,
            a4: v11,
            a5: 8 * v10,
            a6: 0,
            a7: v7);
          if ( v9 > 0 )
          {
            v12 = (unsigned __int8 *)((v7 << 7) + v11);
            jzero_far(dst: v12, count: v9 << 7);
            v13 = *((_WORD *)v12 - 64);
            for ( i = v9; i != 0; --i )
            {
              *(_WORD *)v12 = v13;
              v12 += 128;
            }
          }
          v6 = v28;
          ++v10;
        }
        while ( v10 < v25 );
        v3 = v27;
      }
      if ( *(_DWORD *)(v33 + 8) == v32 )
      {
        v15 = v9 + v7;
        v36 = v15 / v29;
        v16 = v25;
        if ( v25 < v3[3] )
        {
          count = v15 << 7;
          while ( 1 )
          {
            v17 = *(unsigned __int8 **)(v6 + 4 * v16);
            v18 = *(_DWORD *)(v6 + 4 * v16 - 4);
            jzero_far(dst: v17, count);
            if ( v36 != 0 )
            {
              v19 = v29 << 7;
              for ( j = v36; j != 0; --j )
              {
                v20 = v29;
                v21 = *(_WORD *)(v19 + v18 - 128);
                if ( v29 > 0 )
                {
                  v22 = v17;
                  do
                  {
                    *(_WORD *)v22 = v21;
                    v22 += 128;
                    --v20;
                  }
                  while ( v20 != 0 );
                }
                v17 += v19;
                v18 += v19;
              }
              v3 = v27;
            }
            if ( ++v16 >= v3[3] )
              break;
            v6 = v28;
          }
        }
      }
      ++v30;
      ++a2;
      v3 += 21;
      v23 = ++v34 < a1[15];
      v27 = v3;
      v2 = a1;
      if ( !v23 )
        break;
      v4 = v33;
      v5 = v32;
    }
  }
  return sub_101AB810(a1: v2);
}

//------------------------------------------------------------------------------
// Address: 0x101ABBF0
// Name: sub_101ABBF0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101ABBF0(_DWORD *a1, int a2)
{
  _DWORD *v2; // edi
  int result; // eax

  v2 = (_DWORD *)a1[82];
  v2[2] = 0;
  sub_1019FD10(this: a1);
  result = a2;
  if ( a2 != 0 )
  {
    result = a2 - 2;
    if ( a2 == 2 )
    {
      if ( v2[16] == 0 )
      {
        *(_DWORD *)(*a1 + 20) = 4;
        result = (*(int (__cdecl **)(_DWORD *))*a1)(a1);
      }
      v2[1] = sub_101AB810;
    }
    else
    {
      result = a2 - 3;
      if ( a2 == 3 )
      {
        if ( v2[16] == 0 )
        {
          *(_DWORD *)(*a1 + 20) = 4;
          result = (*(int (__cdecl **)(_DWORD *))*a1)(a1);
        }
        v2[1] = sub_101AB9D0;
      }
      else
      {
        *(_DWORD *)(*a1 + 20) = 4;
        return (*(int (__cdecl **)(_DWORD *))*a1)(a1);
      }
    }
  }
  else
  {
    if ( v2[16] != 0 )
    {
      *(_DWORD *)(*a1 + 20) = 4;
      result = (*(int (__cdecl **)(_DWORD *))*a1)(a1);
    }
    v2[1] = sub_101AB5C0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101ABCA0
// Name: void jinit_c_coef_controller(struct jpeg_compress_struct __near *,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jinit_c_coef_controller(struct jpeg_compress_struct *a1, unsigned __int8 a2)
{
  _DWORD *v2; // eax
  _DWORD *v3; // ebx
  int *v4; // esi
  _DWORD *v5; // ebx
  int v6; // ebp
  int v7; // eax
  int v8; // eax
  int v9; // [esp-10h] [ebp-18h]
  int v10; // [esp+10h] [ebp+8h]

  v2 = (_DWORD *)(**((int (__cdecl ***)(struct jpeg_compress_struct *, int, int))a1 + 1))(a1, a2: 1, a3: 104);
  v3 = v2;
  *((_DWORD *)a1 + 82) = v2;
  *v2 = sub_101ABBF0;
  if ( a2 != 0 )
  {
    v10 = 0;
    if ( *((int *)a1 + 15) > 0 )
    {
      v4 = (int *)(*((_DWORD *)a1 + 17) + 12);
      v5 = v2 + 16;
      do
      {
        v6 = *((_DWORD *)a1 + 1);
        v9 = jround_up(a1: v4[5], a2: *v4);
        v7 = jround_up(a1: v4[4], a2: *(v4 - 1));
        *v5++ = (*(int (__cdecl **)(struct jpeg_compress_struct *, int, _DWORD, int, int))(v6 + 20))(
                  a1,
                  a2: 1,
                  a3: 0,
                  a4: v7,
                  a5: v9);
        v4 += 21;
        ++v10;
      }
      while ( v10 < *((_DWORD *)a1 + 15) );
    }
  }
  else
  {
    v8 = (*(int (__cdecl **)(struct jpeg_compress_struct *, int, int))(*((_DWORD *)a1 + 1) + 4))(a1, a2: 1, a3: 1280);
    v3[7] = v8 + 128;
    v3[8] = v8 + 256;
    v3[9] = v8 + 384;
    v3[10] = v8 + 512;
    v3[11] = v8 + 640;
    v3[12] = v8 + 768;
    v3[6] = v8;
    v3[13] = v8 + 896;
    v3[14] = v8 + 1024;
    v3[15] = v8 + 1152;
    v3[16] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ABDB0
// Name: sub_101ABDB0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101ABDB0(int a1)
{
  int v2; // ebp
  int result; // eax
  double v4; // st7
  int v5; // esi
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  double *v9; // eax
  int v10; // edx
  int v11; // ecx
  int *v12; // ecx
  __int16 *v13; // edx
  unsigned __int16 *v14; // eax
  int v15; // esi
  int i; // eax
  int v17; // [esp+8h] [ebp-Ch]
  int v18; // [esp+Ch] [ebp-8h]
  int v19; // [esp+10h] [ebp-4h]
  int *v20; // [esp+18h] [ebp+4h]

  v2 = *(_DWORD *)(a1 + 344);
  result = *(_DWORD *)(a1 + 68);
  v19 = v2;
  v17 = 0;
  if ( *(int *)(a1 + 60) > 0 )
  {
    v4 = 8.0;
    v20 = (int *)(result + 16);
    do
    {
      v5 = *v20;
      if ( (unsigned int)*v20 > 3 || *(_DWORD *)(a1 + 4 * v5 + 72) == 0 )
      {
        *(_DWORD *)(*(_DWORD *)a1 + 20) = 52;
        *(_DWORD *)(*(_DWORD *)a1 + 24) = v5;
        (**(void (__cdecl ***)(int))a1)(a1);
        v4 = 8.0;
      }
      v6 = *(_DWORD *)(a1 + 184);
      v7 = *(_DWORD *)(a1 + 4 * v5 + 72);
      if ( v6 != 0 )
      {
        v8 = v6 - 1;
        if ( v8 != 0 )
        {
          if ( v8 == 1 )
          {
            if ( *(_DWORD *)(v2 + 4 * v5 + 32) == 0 )
            {
              v4 = 8.0;
              *(_DWORD *)(v2 + 4 * v5 + 32) = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, a2: 1, a3: 256);
            }
            v9 = &dbl_102ACB98;
            v10 = *(_DWORD *)(v2 + 4 * v5 + 32) + 8;
            v11 = v7 + 4;
            do
            {
              v18 = *(unsigned __int16 *)(v11 - 4);
              ++v9;
              v11 += 16;
              v10 += 32;
              *(float *)(v10 - 40) = 1.0 / ((double)v18 * *(v9 - 1) * v4);
              *(float *)(v10 - 36) = 1.0 / ((double)*(unsigned __int16 *)(v11 - 18) * *(v9 - 1) * 1.387039845 * v4);
              *(float *)(v10 - 32) = 1.0 / ((double)*(unsigned __int16 *)(v11 - 16) * *(v9 - 1) * 1.306562965 * v4);
              *(float *)(v10 - 28) = 1.0 / ((double)*(unsigned __int16 *)(v11 - 14) * *(v9 - 1) * 1.175875602 * v4);
              *(float *)(v10 - 24) = 1.0 / ((double)*(unsigned __int16 *)(v11 - 12) * *(v9 - 1) * v4);
              *(float *)(v10 - 20) = 1.0 / ((double)*(unsigned __int16 *)(v11 - 10) * *(v9 - 1) * 0.785694958 * v4);
              *(float *)(v10 - 16) = 1.0 / ((double)*(unsigned __int16 *)(v11 - 8) * *(v9 - 1) * 0.5411961 * v4);
              *(float *)(v10 - 12) = 1.0 / ((double)*(unsigned __int16 *)(v11 - 6) * *(v9 - 1) * 0.275899379 * v4);
            }
            while ( (int)v9 < (int)dbl_102ACBD8 );
          }
          else
          {
            *(_DWORD *)(*(_DWORD *)a1 + 20) = 48;
            (**(void (__cdecl ***)(int))a1)(a1);
            v4 = 8.0;
          }
        }
        else
        {
          if ( *(_DWORD *)(v2 + 4 * v5 + 12) == 0 )
          {
            v4 = 8.0;
            *(_DWORD *)(v2 + 4 * v5 + 12) = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, a2: 1, a3: 256);
          }
          v12 = (int *)(*(_DWORD *)(v2 + 4 * v5 + 12) + 8);
          v13 = &word_102ACCEA;
          v14 = (unsigned __int16 *)(v7 + 4);
          do
          {
            *(v12 - 2) = (*(v13 - 1) * *(v14 - 2) + 1024) >> 11;
            *(v12 - 1) = (*v13 * *(v14 - 1) + 1024) >> 11;
            *v12 = (*v14 * *(__int16 *)((char *)&word_102ACCE8 + (_DWORD)v14 - v7) + 1024) >> 11;
            v12[1] = (v14[1] * *(__int16 *)((char *)&word_102ACCEA + (_DWORD)v14 - v7) + 1024) >> 11;
            v13 += 4;
            v12 += 4;
            v14 += 4;
          }
          while ( (int)v13 < (int)((__int16 *)&DOUBLE_16384_5 + 1) );
          v2 = v19;
        }
      }
      else
      {
        if ( *(_DWORD *)(v2 + 4 * v5 + 12) == 0 )
        {
          v4 = 8.0;
          *(_DWORD *)(v2 + 4 * v5 + 12) = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, a2: 1, a3: 256);
        }
        v15 = *(_DWORD *)(v2 + 4 * v5 + 12);
        for ( i = 0; i < 64; ++i )
          *(_DWORD *)(v15 + 4 * i) = 8 * *(unsigned __int16 *)(v7 + 2 * i);
      }
      v20 += 21;
      result = ++v17;
    }
    while ( v17 < *(_DWORD *)(a1 + 60) );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AC0B0
// Name: sub_101AC0B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101AC0B0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // eax
  int result; // eax
  _WORD *v10; // edi
  int *v11; // edx
  int *v12; // eax
  int j; // esi
  int v14; // ecx
  int v15; // ecx
  int v16; // ebp
  int v17; // ebp
  _DWORD *v18; // eax
  int v19; // ebp
  int v20; // ebp
  int v21; // ebp
  int v22; // ecx
  int v23; // ebp
  int v24; // ecx
  int v25; // ebp
  int v26; // ebp
  int v27; // ebp
  int v28; // ebp
  int v29; // ebp
  int v30; // ecx
  int v31; // ecx
  int v32; // ebp
  int v33; // ebp
  int v34; // ebp
  int v35; // ebp
  int v36; // ecx
  int v37; // ebp
  int v38; // ecx
  int v39; // ebp
  int v40; // ebp
  int v41; // ebp
  int v42; // ebp
  int v43; // ebp
  int *v44; // esi
  int k; // ebp
  int v46; // ecx
  int v47; // eax
  int v48; // edx
  int v49; // edx
  int v50; // eax
  int v51; // eax
  int v52; // ecx
  int v53; // eax
  int v54; // edx
  int v55; // edx
  int v56; // eax
  int v57; // eax
  int v58; // ecx
  int v59; // eax
  int v60; // edx
  int v61; // edx
  int v62; // eax
  int v63; // eax
  int v64; // ecx
  int v65; // eax
  int v66; // edx
  int v67; // edx
  int v68; // eax
  int i; // [esp+0h] [ebp-118h]
  int *v70; // [esp+4h] [ebp-114h]
  char *v71; // [esp+8h] [ebp-110h]
  void (__cdecl *v72)(int *); // [esp+Ch] [ebp-10Ch]
  char *v73; // [esp+10h] [ebp-108h]
  int v74; // [esp+18h] [ebp-100h] BYREF
  _DWORD v75[63]; // [esp+1Ch] [ebp-FCh] BYREF

  v7 = *(_DWORD *)(a1 + 344);
  v72 = *(void (__cdecl **)(int *))(v7 + 8);
  result = *(_DWORD *)(v7 + 4 * *(_DWORD *)(a2 + 16) + 12);
  if ( a7 != 0 )
  {
    v70 = (int *)(result + 8);
    v71 = (char *)&v75[-1] - result;
    v73 = (char *)v75 - result;
    v10 = (_WORD *)(a4 + 4);
    for ( i = a7; i != 0; --i )
    {
      v11 = (int *)(a3 + 4 * a5 + 8);
      v12 = &v74;
      for ( j = 2; j != 0; --j )
      {
        v14 = *(v11 - 2);
        *v12 = *(unsigned __int8 *)(v14 + a6) - 128;
        v15 = a6 + v14;
        v16 = *(unsigned __int8 *)++v15;
        v12[1] = v16 - 128;
        v17 = *(unsigned __int8 *)++v15;
        v18 = v12 + 1;
        v18[1] = v17 - 128;
        v19 = *(unsigned __int8 *)++v15;
        ++v18;
        v18[1] = v19 - 128;
        v20 = *(unsigned __int8 *)++v15;
        ++v18;
        v18[1] = v20 - 128;
        v21 = *(unsigned __int8 *)++v15;
        ++v18;
        v18[1] = v21 - 128;
        ++v18;
        v18[1] = *(unsigned __int8 *)(v15 + 1) - 128;
        ++v18;
        v18[1] = *(unsigned __int8 *)(v15 + 2) - 128;
        v22 = *(v11 - 1);
        v23 = *(unsigned __int8 *)(v22 + a6);
        ++v18;
        v24 = a6 + v22;
        v18[1] = v23 - 128;
        v25 = *(unsigned __int8 *)(v24 + 1);
        ++v18;
        ++v24;
        v18[1] = v25 - 128;
        v26 = *(unsigned __int8 *)(v24 + 1);
        ++v18;
        ++v24;
        v18[1] = v26 - 128;
        v27 = *(unsigned __int8 *)(v24 + 1);
        ++v18;
        ++v24;
        v18[1] = v27 - 128;
        v28 = *(unsigned __int8 *)(v24 + 1);
        ++v18;
        ++v24;
        v18[1] = v28 - 128;
        v29 = *(unsigned __int8 *)++v24;
        v18 += 2;
        *v18++ = v29 - 128;
        *v18++ = *(unsigned __int8 *)(v24 + 1) - 128;
        *v18 = *(unsigned __int8 *)(v24 + 2) - 128;
        v30 = *v11;
        *++v18 = *(unsigned __int8 *)(*v11 + a6) - 128;
        v31 = a6 + v30;
        v18[1] = *(unsigned __int8 *)++v31 - 128;
        v32 = *(unsigned __int8 *)(v31 + 1);
        ++v18;
        ++v31;
        v18[1] = v32 - 128;
        v33 = *(unsigned __int8 *)(v31 + 1);
        ++v18;
        ++v31;
        v18[1] = v33 - 128;
        v34 = *(unsigned __int8 *)(v31 + 1);
        ++v18;
        ++v31;
        v18[1] = v34 - 128;
        v35 = *(unsigned __int8 *)(v31 + 1);
        ++v18;
        ++v31;
        v18[1] = v35 - 128;
        ++v18;
        v18[1] = *(unsigned __int8 *)(v31 + 1) - 128;
        ++v18;
        v18[1] = *(unsigned __int8 *)(v31 + 2) - 128;
        v36 = v11[1];
        v37 = *(unsigned __int8 *)(v36 + a6);
        ++v18;
        v38 = a6 + v36;
        v18[1] = v37 - 128;
        v39 = *(unsigned __int8 *)(v38 + 1);
        ++v18;
        ++v38;
        v18[1] = v39 - 128;
        v40 = *(unsigned __int8 *)(v38 + 1);
        ++v18;
        ++v38;
        v18[1] = v40 - 128;
        v41 = *(unsigned __int8 *)(v38 + 1);
        ++v18;
        ++v38;
        v18[1] = v41 - 128;
        v42 = *(unsigned __int8 *)++v38;
        v18 += 2;
        *v18 = v42 - 128;
        v43 = *(unsigned __int8 *)++v38;
        *++v18 = v43 - 128;
        *++v18 = *(unsigned __int8 *)(v38 + 1) - 128;
        *++v18 = *(unsigned __int8 *)(v38 + 2) - 128;
        v12 = v18 + 1;
        v11 += 4;
      }
      v72(a1: &v74);
      v44 = v70;
      for ( k = 0; k < 64; k += 4 )
      {
        v46 = *(v44 - 2);
        v47 = v75[k - 1];
        v48 = v46 >> 1;
        if ( v47 >= 0 )
        {
          v51 = v48 + v47;
          if ( v51 < v46 )
            LOWORD(v50) = 0;
          else
            v50 = v51 / v46;
        }
        else
        {
          v49 = v48 - v47;
          if ( v49 < v46 )
            LOWORD(v50) = 0;
          else
            v50 = -(v49 / v46);
        }
        *(v10 - 2) = v50;
        v52 = *(v44 - 1);
        v53 = v75[k];
        v54 = v52 >> 1;
        if ( v53 >= 0 )
        {
          v57 = v54 + v53;
          if ( v57 < v52 )
            LOWORD(v56) = 0;
          else
            v56 = v57 / v52;
        }
        else
        {
          v55 = v54 - v53;
          if ( v55 < v52 )
            LOWORD(v56) = 0;
          else
            v56 = -(v55 / v52);
        }
        *(v10 - 1) = v56;
        v58 = *v44;
        v59 = *(_DWORD *)&v71[(_DWORD)v44];
        v60 = *v44 >> 1;
        if ( v59 >= 0 )
        {
          v63 = v60 + v59;
          if ( v63 < v58 )
            LOWORD(v62) = 0;
          else
            v62 = v63 / v58;
        }
        else
        {
          v61 = v60 - v59;
          if ( v61 < v58 )
            LOWORD(v62) = 0;
          else
            v62 = -(v61 / v58);
        }
        *v10 = v62;
        v64 = v44[1];
        v65 = *(_DWORD *)&v73[(_DWORD)v44];
        v66 = v64 >> 1;
        if ( v65 >= 0 )
        {
          v68 = v66 + v65;
          if ( v68 < v64 )
            result = 0;
          else
            result = v68 / v64;
        }
        else
        {
          v67 = v66 - v65;
          if ( v67 < v64 )
            result = 0;
          else
            result = -(v67 / v64);
        }
        v10[1] = result;
        v10 += 4;
        v44 += 4;
      }
      a6 += 8;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AC4C0
// Name: sub_101AC4C0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 __cdecl sub_101AC4C0(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v7; // eax
  int v8; // edx
  __int16 result; // ax
  int v11; // eax
  unsigned __int8 *v12; // eax
  unsigned __int8 *v13; // eax
  int v14; // edx
  unsigned __int8 *v15; // eax
  int v16; // edx
  unsigned __int8 *v17; // eax
  int v18; // edx
  unsigned __int8 *v19; // eax
  int v20; // edx
  unsigned __int8 *v21; // eax
  int v22; // edx
  unsigned __int8 *v23; // eax
  int v24; // edx
  unsigned __int8 *v25; // eax
  int j; // edi
  int v27; // [esp+8h] [ebp-114h]
  int v28; // [esp+8h] [ebp-114h]
  int v29; // [esp+8h] [ebp-114h]
  int v30; // [esp+8h] [ebp-114h]
  int v31; // [esp+8h] [ebp-114h]
  int v32; // [esp+8h] [ebp-114h]
  int v33; // [esp+8h] [ebp-114h]
  int v34; // [esp+8h] [ebp-114h]
  int v35; // [esp+8h] [ebp-114h]
  int v36; // [esp+8h] [ebp-114h]
  int v37; // [esp+8h] [ebp-114h]
  int v38; // [esp+8h] [ebp-114h]
  int v39; // [esp+8h] [ebp-114h]
  float v40; // [esp+8h] [ebp-114h]
  int i; // [esp+10h] [ebp-10Ch]
  void (__cdecl *v43)(float *); // [esp+14h] [ebp-108h]
  int v44; // [esp+18h] [ebp-104h]
  float v45[64]; // [esp+1Ch] [ebp-100h] BYREF

  v7 = *(_DWORD *)(a1 + 344);
  v43 = *(void (__cdecl **)(float *))(v7 + 28);
  v8 = *(_DWORD *)(v7 + 4 * *(_DWORD *)(a2 + 16) + 32);
  result = a7;
  v44 = v8;
  if ( a7 != 0 )
  {
    for ( i = a7; i != 0; --i )
    {
      v11 = *(_DWORD *)(a3 + 4 * a5);
      v27 = *(unsigned __int8 *)(v11 + a6) - 128;
      v12 = (unsigned __int8 *)(a6 + v11 + 5);
      v45[0] = (float)v27;
      v28 = *(v12 - 4) - 128;
      ++v12;
      v45[1] = (float)v28;
      v45[2] = (float)(*(v12 - 4) - 128);
      v45[3] = (float)(*(v12 - 3) - 128);
      v45[4] = (float)(*(v12 - 2) - 128);
      v45[5] = (float)(*(v12 - 1) - 128);
      v45[6] = (float)(*v12 - 128);
      v29 = v12[1] - 128;
      v13 = (unsigned __int8 *)(a6 + *(_DWORD *)(a3 + 4 * a5 + 4) + 3);
      v45[7] = (float)v29;
      v30 = *(v13 - 3) - 128;
      ++v13;
      v45[8] = (float)v30;
      v45[9] = (float)(*(v13 - 3) - 128);
      v45[10] = (float)(*(v13 - 2) - 128);
      v45[11] = (float)(*(v13 - 1) - 128);
      v31 = *v13++ - 128;
      v45[12] = (float)v31;
      v32 = *v13++ - 128;
      v45[13] = (float)v32;
      v45[14] = (float)(*v13 - 128);
      v14 = v13[1];
      v15 = (unsigned __int8 *)(a6 + *(_DWORD *)(a3 + 4 * a5 + 8) + 4);
      v45[15] = (float)(v14 - 128);
      v33 = *(v15 - 4) - 128;
      v15 += 2;
      v45[16] = (float)v33;
      v45[17] = (float)(*(v15 - 5) - 128);
      v45[18] = (float)(*(v15 - 4) - 128);
      v45[19] = (float)(*(v15 - 3) - 128);
      v45[20] = (float)(*(v15 - 2) - 128);
      v45[21] = (float)(*(v15 - 1) - 128);
      v45[22] = (float)(*v15 - 128);
      v16 = v15[1];
      v17 = (unsigned __int8 *)(a6 + *(_DWORD *)(a3 + 4 * a5 + 12) + 2);
      v45[23] = (float)(v16 - 128);
      v45[24] = (float)(*(v17 - 2) - 128);
      v45[25] = (float)(*(v17 - 1) - 128);
      v45[26] = (float)(*v17 - 128);
      v34 = v17[1] - 128;
      v17 += 4;
      v45[27] = (float)v34;
      v45[28] = (float)(*(v17 - 2) - 128);
      v45[29] = (float)(*(v17 - 1) - 128);
      v45[30] = (float)(*v17 - 128);
      v18 = v17[1];
      v19 = (unsigned __int8 *)(a6 + *(_DWORD *)(a3 + 4 * a5 + 16) + 4);
      v45[31] = (float)(v18 - 128);
      v35 = *(v19 - 4) - 128;
      v19 += 2;
      v45[32] = (float)v35;
      v45[33] = (float)(*(v19 - 5) - 128);
      v45[34] = (float)(*(v19 - 4) - 128);
      v45[35] = (float)(*(v19 - 3) - 128);
      v45[36] = (float)(*(v19 - 2) - 128);
      v45[37] = (float)(*(v19 - 1) - 128);
      v45[38] = (float)(*v19 - 128);
      v20 = v19[1];
      v21 = (unsigned __int8 *)(a6 + *(_DWORD *)(a3 + 4 * a5 + 20));
      v45[39] = (float)(v20 - 128);
      v36 = *v21 - 128;
      v21 += 3;
      v45[40] = (float)v36;
      v37 = *(v21 - 2) - 128;
      v21 += 3;
      v45[41] = (float)v37;
      v45[42] = (float)(*(v21 - 4) - 128);
      v45[43] = (float)(*(v21 - 3) - 128);
      v45[44] = (float)(*(v21 - 2) - 128);
      v45[45] = (float)(*(v21 - 1) - 128);
      v45[46] = (float)(*v21 - 128);
      v22 = v21[1];
      v23 = (unsigned __int8 *)(a6 + *(_DWORD *)(a3 + 4 * a5 + 24) + 4);
      v45[47] = (float)(v22 - 128);
      v38 = *(v23 - 4) - 128;
      ++v23;
      v45[48] = (float)v38;
      v45[49] = (float)(*(v23 - 4) - 128);
      v45[50] = (float)(*(v23 - 3) - 128);
      v45[51] = (float)(*(v23 - 2) - 128);
      v45[52] = (float)(*(v23 - 1) - 128);
      v45[53] = (float)(*v23 - 128);
      v45[54] = (float)(v23[1] - 128);
      v24 = v23[2];
      v25 = (unsigned __int8 *)(a6 + *(_DWORD *)(a3 + 4 * a5 + 28) + 4);
      v45[55] = (float)(v24 - 128);
      v39 = *(v25 - 4) - 128;
      v25 += 2;
      v45[56] = (float)v39;
      v45[57] = (float)(*(v25 - 5) - 128);
      v45[58] = (float)(*(v25 - 4) - 128);
      v45[59] = (float)(*(v25 - 3) - 128);
      v45[60] = (float)(*(v25 - 2) - 128);
      v45[61] = (float)(*(v25 - 1) - 128);
      v45[62] = (float)(*v25 - 128);
      v45[63] = (float)(v25[1] - 128);
      v43(a1: v45);
      for ( j = 0; j < 64; ++j )
      {
        v40 = *(float *)(v44 + 4 * j) * v45[j];
        result = (int)(v40 + 16384.5) - 0x4000;
        *(_WORD *)(a4 + 2 * j) = result;
      }
      a4 += 128;
      a6 += 8;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101ACC40
// Name: void jinit_forward_dct(struct jpeg_compress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jinit_forward_dct(int (__cdecl ***a1)(struct jpeg_compress_struct *, int, int))
{
  int (__cdecl **v1)(int); // esi
  int (__cdecl **v2)(struct jpeg_compress_struct *, int, int); // eax
  int v3; // eax

  v1 = (int (__cdecl **)(int))(*a1[1])((struct jpeg_compress_struct *)a1, a2: 1, a3: 48);
  a1[86] = (int (__cdecl **)(struct jpeg_compress_struct *, int, int))v1;
  *v1 = sub_101ABDB0;
  v2 = a1[46];
  if ( v2 == nullptr )
  {
    v1[2] = (int (__cdecl *)(int))jpeg_fdct_islow;
    goto LABEL_8;
  }
  v3 = (int)v2 - 1;
  if ( v3 == 0 )
  {
    v1[2] = (int (__cdecl *)(int))jpeg_fdct_ifast;
LABEL_8:
    v1[1] = (int (__cdecl *)(int))sub_101AC0B0;
    goto LABEL_9;
  }
  if ( v3 == 1 )
  {
    v1[1] = (int (__cdecl *)(int))sub_101AC4C0;
    v1[7] = (int (__cdecl *)(int))jpeg_fdct_float;
  }
  else
  {
    (*a1)[5] = (int (__cdecl *)(struct jpeg_compress_struct *, int, int))48;
    ((void (__cdecl *)(int (__cdecl ***)(struct jpeg_compress_struct *, int, int)))**a1)(a1);
  }
LABEL_9:
  v1[3] = nullptr;
  v1[8] = nullptr;
  v1[4] = nullptr;
  v1[9] = nullptr;
  v1[5] = nullptr;
  v1[10] = nullptr;
  v1[6] = nullptr;
  v1[11] = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101ACCE0
// Name: sub_101ACCE0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101ACCE0(_DWORD *a1, int a2)
{
  _DWORD *v2; // esi
  int result; // eax

  v2 = (_DWORD *)a1[81];
  if ( a2 != 0 )
  {
    *(_DWORD *)(*a1 + 20) = 4;
    (*(void (__cdecl **)(_DWORD *))*a1)(a1);
  }
  result = a1[8];
  v2[12] = result;
  v2[13] = 0;
  v2[14] = 0;
  v2[15] = 2 * a1[55];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101ACD30
// Name: sub_101ACD30
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_101ACD30(int a1@<eax>, int a2@<ebx>, unsigned __int8 **a3@<edi>, unsigned int count)
{
  int v4; // esi
  int v5; // ebp

  v4 = a1;
  if ( a1 < a2 )
  {
    v5 = a1 - 1;
    do
      jcopy_sample_rows(a1: a3, a2: v5, a3, a4: v4++, a5: 1, count);
    while ( v4 < a2 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ACD60
// Name: sub_101ACD60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_101ACD60(
        _DWORD *a1,
        int a2,
        unsigned int *a3,
        unsigned int a4,
        int a5,
        unsigned int *a6,
        unsigned int a7)
{
  int v8; // ebp
  unsigned int *v9; // edi
  unsigned int v10; // ebx
  int v11; // eax
  bool v12; // zf
  int v13; // ebp
  _DWORD *v14; // edx
  int v15; // [esp+8h] [ebp-4h]
  unsigned __int8 ***v16; // [esp+10h] [ebp+4h]
  _DWORD *i; // [esp+18h] [ebp+Ch]

  v8 = a1[81];
  while ( *a3 < a4 )
  {
    v9 = a6;
    if ( *a6 >= a7 )
      break;
    v10 = a1[55] - *(_DWORD *)(v8 + 52);
    if ( v10 >= a4 - *a3 )
      v10 = a4 - *a3;
    (*(void (__cdecl **)(_DWORD *, unsigned int, int, _DWORD, unsigned int))(a1[84] + 4))(
      a1,
      a2: a2 + 4 * *a3,
      a3: v8 + 8,
      a4: *(_DWORD *)(v8 + 52),
      a5: v10);
    *a3 += v10;
    *(_DWORD *)(v8 + 52) += v10;
    v11 = *(_DWORD *)(v8 + 52);
    v12 = *(_DWORD *)(v8 + 48) == v10;
    *(_DWORD *)(v8 + 48) -= v10;
    if ( v12 && v11 < a1[55] )
    {
      v15 = 0;
      if ( (int)a1[15] > 0 )
      {
        v16 = (unsigned __int8 ***)(v8 + 8);
        do
        {
          sub_101ACD30(a1: *(_DWORD *)(v8 + 52), a2: a1[55], a3: *v16++, count: a1[7]);
          ++v15;
        }
        while ( v15 < a1[15] );
        v9 = a6;
      }
      *(_DWORD *)(v8 + 52) = a1[55];
    }
    if ( *(_DWORD *)(v8 + 52) == a1[55] )
    {
      (*(void (__cdecl **)(_DWORD *, int, _DWORD, int, unsigned int))(a1[85] + 4))(
        a1,
        a2: v8 + 8,
        a3: 0,
        a4: a5,
        a5: *v9);
      *(_DWORD *)(v8 + 52) = 0;
      ++*v9;
    }
    if ( *(_DWORD *)(v8 + 48) == 0 && *v9 < a7 )
    {
      v13 = 0;
      if ( (int)a1[15] > 0 )
      {
        v14 = (_DWORD *)(a1[17] + 12);
        for ( i = v14; ; v14 = i )
        {
          sub_101ACD30(a1: *v14 * *v9, a2: a7 * *v14, a3: *(unsigned __int8 ***)(a5 + 4 * v13), count: 8 * v14[4]);
          i += 21;
          v9 = a6;
          if ( ++v13 >= a1[15] )
            break;
        }
      }
      *v9 = a7;
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ACEF0
// Name: sub_101ACEF0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101ACEF0(
        unsigned int *a1,
        int a2,
        unsigned int *a3,
        unsigned int a4,
        int a5,
        unsigned int *a6,
        unsigned int a7)
{
  _DWORD *v8; // ebp
  unsigned int *v9; // edi
  int result; // eax
  unsigned int v11; // edx
  int v12; // ecx
  unsigned int v13; // ebx
  int v14; // eax
  int v15; // edi
  int v16; // ebx
  unsigned int v17; // [esp+Ch] [ebp-Ch]
  unsigned __int8 ***v18; // [esp+10h] [ebp-8h]
  unsigned __int8 ***v19; // [esp+10h] [ebp-8h]
  int v20; // [esp+14h] [ebp-4h]
  signed int v21; // [esp+1Ch] [ebp+4h]
  signed int v22; // [esp+1Ch] [ebp+4h]

  v8 = (_DWORD *)a1[81];
  v9 = a6;
  result = 3 * a1[55];
  v20 = result;
  while ( *v9 < a7 )
  {
    v11 = *a3;
    result = a4;
    if ( *a3 >= a4 )
    {
      if ( v8[12] != 0 )
        return result;
      if ( v8[13] < v8[15] )
      {
        v22 = 0;
        if ( (int)a1[15] > 0 )
        {
          v19 = (unsigned __int8 ***)(v8 + 2);
          do
          {
            sub_101ACD30(a1: v8[13], a2: v8[15], a3: *v19++, count: a1[7]);
            ++v22;
          }
          while ( v22 < (int)a1[15] );
          v9 = a6;
        }
        result = v8[15];
        v8[13] = result;
      }
    }
    else
    {
      v12 = v8[13];
      v13 = v8[15] - v12;
      v17 = v13;
      if ( v13 >= a4 - v11 )
      {
        v17 = a4 - v11;
        v13 = a4 - v11;
      }
      (*(void (__cdecl **)(unsigned int *, unsigned int, _DWORD *, int, unsigned int))(a1[84] + 4))(
        a1,
        a2: a2 + 4 * v11,
        a3: v8 + 2,
        a4: v12,
        a5: v13);
      if ( v8[12] == a1[8] )
      {
        v21 = 0;
        if ( (int)a1[15] > 0 )
        {
          v14 = a1[55];
          v18 = (unsigned __int8 ***)(v8 + 2);
          do
          {
            v15 = 1;
            if ( v14 >= 1 )
            {
              v16 = -1;
              do
              {
                jcopy_sample_rows(a1: *v18, a2: 0, a3: *v18, a4: v16, a5: 1, count: a1[7]);
                v14 = a1[55];
                ++v15;
                --v16;
              }
              while ( v15 <= v14 );
              v13 = v17;
            }
            ++v18;
            ++v21;
          }
          while ( v21 < (int)a1[15] );
        }
      }
      result = (int)a3;
      *a3 += v13;
      v8[13] += v13;
      v8[12] -= v13;
      v9 = a6;
    }
    if ( v8[13] == v8[15] )
    {
      (*(void (__cdecl **)(unsigned int *, _DWORD *, _DWORD, int, unsigned int))(a1[85] + 4))(
        a1,
        a2: v8 + 2,
        a3: v8[14],
        a4: a5,
        a5: *v9);
      ++*v9;
      v8[14] += a1[55];
      result = v20;
      if ( v8[14] >= v20 )
        v8[14] = 0;
      if ( v8[13] >= v20 )
        v8[13] = 0;
      v8[15] = v8[13] + a1[55];
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AD0C0
// Name: sub_101AD0C0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101AD0C0@<eax>(int a1@<edi>)
{
  int v1; // ebx
  int v2; // esi
  int result; // eax
  int v4; // edx
  _DWORD *v5; // ecx
  unsigned __int8 *v6; // ebp
  unsigned __int8 *v7; // ebx
  _DWORD *v8; // eax
  unsigned __int8 *v9; // ecx
  unsigned __int8 *v10; // edx
  bool v11; // cc
  int v12; // [esp+8h] [ebp-20h]
  _DWORD *v13; // [esp+Ch] [ebp-1Ch]
  int i; // [esp+10h] [ebp-18h]
  unsigned __int8 *v15; // [esp+14h] [ebp-14h]
  int v16; // [esp+18h] [ebp-10h]
  unsigned __int8 **v17; // [esp+1Ch] [ebp-Ch]
  int v18; // [esp+24h] [ebp-4h]

  v1 = *(_DWORD *)(a1 + 324);
  v2 = *(_DWORD *)(a1 + 220);
  result = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, a2: 1, a3: 20 * v2 * *(_DWORD *)(a1 + 60));
  v4 = *(_DWORD *)(a1 + 68);
  v12 = result;
  v16 = 0;
  if ( *(int *)(a1 + 60) > 0 )
  {
    v18 = 20 * v2;
    v5 = (_DWORD *)(v4 + 8);
    v6 = (unsigned __int8 *)(result + 4 * v2);
    v13 = (_DWORD *)(v4 + 8);
    v15 = v6;
    v17 = (unsigned __int8 **)(v1 + 8);
    while ( 1 )
    {
      v7 = (unsigned __int8 *)(*(int (__cdecl **)(int, int, int, int))(*(_DWORD *)(a1 + 4) + 8))(
                                a1,
                                a2: 1,
                                a3: 8 * *(_DWORD *)(a1 + 216) * v5[5] / *v5,
                                a4: 3 * v2);
      memcpy(dst: v6, src: v7, count: 12 * v2);
      if ( v2 > 0 )
      {
        v8 = (_DWORD *)(v12 + 16 * v2);
        v9 = v7;
        v10 = &v7[8 * v2];
        for ( i = v2; i != 0; --i )
        {
          *(_DWORD *)&v9[v12 - (_DWORD)v7] = *(_DWORD *)v10;
          *v8 = *(_DWORD *)v9;
          v10 += 4;
          v9 += 4;
          ++v8;
        }
        v6 = v15;
      }
      v12 += v18;
      v13 += 21;
      *v17 = v6;
      v6 += v18;
      result = v16 + 1;
      v11 = v16 + 1 < *(_DWORD *)(a1 + 60);
      v15 = v6;
      ++v16;
      ++v17;
      if ( !v11 )
        break;
      v5 = v13;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AD1E0
// Name: void jinit_c_prep_controller(struct jpeg_compress_struct __near *,unsigned char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jinit_c_prep_controller(struct jpeg_compress_struct *a1, char a2)
{
  _DWORD *v2; // eax
  int v3; // ebp
  _DWORD *v4; // esi
  _DWORD *v5; // ebx

  if ( a2 != 0 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 4;
    (**(void (__cdecl ***)(struct jpeg_compress_struct *))a1)(a1);
  }
  v2 = (_DWORD *)(**((int (__cdecl ***)(struct jpeg_compress_struct *, int, int))a1 + 1))(a1, a2: 1, a3: 64);
  *((_DWORD *)a1 + 81) = v2;
  *v2 = sub_101ACCE0;
  if ( *(_BYTE *)(*((_DWORD *)a1 + 85) + 8) != 0 )
  {
    v2[1] = sub_101ACEF0;
    sub_101AD0C0((int)a1);
  }
  else
  {
    v2[1] = sub_101ACD60;
    v3 = 0;
    if ( *((int *)a1 + 15) > 0 )
    {
      v4 = (_DWORD *)(*((_DWORD *)a1 + 17) + 8);
      v5 = v2 + 2;
      do
      {
        *v5 = (*(int (__cdecl **)(struct jpeg_compress_struct *, int, int, _DWORD))(*((_DWORD *)a1 + 1) + 8))(
                a1,
                a2: 1,
                a3: 8 * *((_DWORD *)a1 + 54) * v4[5] / *v4,
                a4: *((_DWORD *)a1 + 55));
        ++v3;
        ++v5;
        v4 += 21;
      }
      while ( v3 < *((_DWORD *)a1 + 15) );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AD290
// Name: sub_101AD290
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_101AD290(int a1@<eax>, int a2@<ebx>, int a3, int a4)
{
  unsigned int v4; // edi
  int i; // esi

  v4 = a1 - a2;
  if ( a1 - a2 > 0 )
  {
    for ( i = 0; i < a4; ++i )
      memset(
        dst: (unsigned __int8 *)(a2 + *(_DWORD *)(a3 + 4 * i)),
        value: *(_BYTE *)(*(_DWORD *)(a3 + 4 * i) + a2 - 1),
        count: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AD2E0
// Name: sub_101AD2E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_101AD2E0(_DWORD *a1, _DWORD *a2, int a3, int a4, int a5)
{
  bool v6; // cc
  int v7; // ebp
  int v8; // edi
  _DWORD *v9; // esi
  void (__cdecl **v10)(_DWORD *, int, int, int); // ebp
  int i; // eax
  int v12; // [esp+18h] [ebp+4h]

  v6 = a1[15] <= 0;
  v7 = a1[85];
  v8 = a1[17];
  v12 = 0;
  if ( !v6 )
  {
    v9 = a2;
    v10 = (void (__cdecl **)(_DWORD *, int, int, int))(v7 + 12);
    for ( i = a4 - (_DWORD)a2; ; i = a4 - (_DWORD)a2 )
    {
      (*v10)(a1, a2: v8, a3: 4 * a3 + *v9, a4: *(_DWORD *)((char *)v9 + i) + 4 * a5 * *(_DWORD *)(v8 + 12));
      ++v9;
      ++v10;
      v8 += 84;
      if ( ++v12 >= a1[15] )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AD370
// Name: sub_101AD370
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101AD370(int *a1, _DWORD *a2, int a3, int a4)
{
  int v4; // edi
  int v5; // ebp
  int result; // eax
  int v7; // ecx
  int v8; // ebx
  int v9; // edx
  _DWORD *v10; // esi
  unsigned __int8 *v11; // eax
  int j; // ecx
  bool v13; // zf
  int v14; // [esp-4h] [ebp-34h]
  int i; // [esp+10h] [ebp-20h]
  _BYTE *v16; // [esp+14h] [ebp-1Ch]
  int v17; // [esp+18h] [ebp-18h]
  int v18; // [esp+1Ch] [ebp-14h]
  int v19; // [esp+20h] [ebp-10h]
  int v20; // [esp+24h] [ebp-Ch]
  int v21; // [esp+28h] [ebp-8h]
  int v22; // [esp+2Ch] [ebp-4h]
  _DWORD *v23; // [esp+34h] [ebp+4h]

  v14 = a1[55];
  v19 = 8 * a2[7];
  v4 = a1[54] / a2[2];
  v5 = v14 / a2[3];
  v22 = v4 * v5;
  v21 = v4 * v5 / 2;
  v20 = v5;
  sub_101AD290(a1: v19 * v4, a2: a1[7], a3, a4: v14);
  result = (int)a2;
  v7 = 0;
  v18 = 0;
  if ( (int)a2[3] > 0 )
  {
    v23 = (_DWORD *)a3;
    do
    {
      v16 = *(_BYTE **)(a4 + 4 * v7);
      v8 = 0;
      if ( v19 != 0 )
      {
        v17 = v19;
        do
        {
          v9 = 0;
          if ( v5 > 0 )
          {
            v10 = v23;
            for ( i = v5; i != 0; --i )
            {
              v11 = (unsigned __int8 *)(v8 + *v10);
              if ( v4 > 0 )
              {
                for ( j = v4; j != 0; --j )
                  v9 += *v11++;
                v5 = v20;
              }
              ++v10;
            }
          }
          v8 += v4;
          v13 = v17-- == 1;
          *v16++ = (v9 + v21) / v22;
        }
        while ( !v13 );
        v7 = v18;
      }
      result = 4 * v5;
      v23 += v5;
      v18 = ++v7;
    }
    while ( v7 < a2[3] );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AD4A0
// Name: sub_101AD4A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_101AD4A0(int a1, int a2, unsigned __int8 **a3, unsigned __int8 **a4)
{
  jcopy_sample_rows(a1: a3, a2: 0, a3: a4, a4: 0, a5: *(_DWORD *)(a1 + 220), count: *(_DWORD *)(a1 + 28));
  sub_101AD290(a1: 8 * *(_DWORD *)(a2 + 28), a2: *(_DWORD *)(a1 + 28), a3: (int)a4, a4: *(_DWORD *)(a1 + 220));
}

//------------------------------------------------------------------------------
// Address: 0x101AD4F0
// Name: sub_101AD4F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_101AD4F0(int a1, int a2, int a3, int a4)
{
  unsigned __int8 **v4; // ebp
  int v5; // edi
  int v6; // edx
  _BYTE *v7; // ecx
  unsigned __int8 *v8; // eax
  int v9; // esi
  int v10; // [esp+10h] [ebp-8h]
  int v11; // [esp+1Ch] [ebp+4h]

  v4 = (unsigned __int8 **)a3;
  v5 = 8 * *(_DWORD *)(a2 + 28);
  v10 = v5;
  sub_101AD290(a1: 16 * *(_DWORD *)(a2 + 28), a2: *(_DWORD *)(a1 + 28), a3, a4: *(_DWORD *)(a1 + 220));
  v11 = 0;
  if ( *(int *)(a2 + 12) > 0 )
  {
    v6 = a4 - a3;
    do
    {
      v7 = *(unsigned __int8 **)((char *)v4 + v6);
      v8 = *v4;
      v9 = 0;
      if ( v5 != 0 )
      {
        do
        {
          *v7++ = (v9 + v8[1] + *v8) >> 1;
          v9 ^= 1u;
          v8 += 2;
          --v5;
        }
        while ( v5 != 0 );
        v5 = v10;
        v6 = a4 - a3;
      }
      ++v4;
      ++v11;
    }
    while ( v11 < *(_DWORD *)(a2 + 12) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AD5A0
// Name: sub_101AD5A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl sub_101AD5A0(int a1, int a2, int a3, int a4)
{
  int v4; // ebp
  int v5; // ebx
  unsigned __int8 **v6; // edx
  _BYTE *v7; // esi
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // ecx
  int v10; // edi
  int v11; // [esp+Ch] [ebp-10h]
  int v12; // [esp+10h] [ebp-Ch]
  int v13; // [esp+14h] [ebp-8h]
  int i; // [esp+20h] [ebp+4h]

  v4 = a2;
  v11 = 8 * *(_DWORD *)(a2 + 28);
  sub_101AD290(a1: 16 * *(_DWORD *)(a2 + 28), a2: *(_DWORD *)(a1 + 28), a3, a4: *(_DWORD *)(a1 + 220));
  v5 = 0;
  v13 = 0;
  if ( *(int *)(a2 + 12) > 0 )
  {
    v6 = (unsigned __int8 **)a3;
    v12 = a3;
    do
    {
      v7 = *(_BYTE **)(a4 + 4 * v5);
      v8 = *v6;
      v9 = v6[1];
      v10 = 1;
      if ( v11 != 0 )
      {
        for ( i = v11; i != 0; --i )
        {
          *v7++ = (v8[1] + v9[1] + v10 + *v9 + *v8) >> 2;
          v10 ^= 3u;
          v8 += 2;
          v9 += 2;
        }
        v4 = a2;
        v5 = v13;
        v6 = (unsigned __int8 **)v12;
      }
      ++v5;
      v6 += 2;
      v12 = (int)v6;
      v13 = v5;
    }
    while ( v5 < *(_DWORD *)(v4 + 12) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AD670
// Name: sub_101AD670
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 **__cdecl sub_101AD670(int *a1, unsigned __int8 **a2, int a3, int a4)
{
  int v4; // esi
  unsigned __int8 **v5; // ebp
  int v6; // eax
  unsigned __int8 **result; // eax
  int v8; // ecx
  unsigned __int8 *v9; // ebx
  _BYTE *v10; // esi
  unsigned __int8 *v11; // edx
  unsigned __int8 *v12; // ecx
  unsigned __int8 *v13; // eax
  unsigned __int8 *v14; // ebp
  unsigned __int8 *v15; // eax
  unsigned __int8 *v16; // ecx
  unsigned __int8 *v17; // edi
  unsigned __int8 *v18; // esi
  bool v19; // zf
  bool v20; // cc
  _BYTE *v21; // [esp+10h] [ebp-28h]
  int v22; // [esp+20h] [ebp-18h]
  unsigned __int8 *v23; // [esp+24h] [ebp-14h]
  int v24; // [esp+24h] [ebp-14h]
  unsigned __int8 **v25; // [esp+28h] [ebp-10h]
  int v26; // [esp+2Ch] [ebp-Ch]
  int v27; // [esp+34h] [ebp-4h]
  int v28; // [esp+3Ch] [ebp+4h]
  int v29; // [esp+44h] [ebp+Ch]

  v4 = 8 * (_DWORD)a2[7];
  v5 = (unsigned __int8 **)(a3 - 4);
  sub_101AD290(a1: 16 * (_DWORD)a2[7], a2: a1[7], a3: a3 - 4, a4: a1[55] + 2);
  v6 = a1[45];
  v28 = 0x4000 - 80 * v6;
  v29 = 16 * v6;
  result = a2;
  v8 = 0;
  v26 = 0;
  if ( (int)a2[3] > 0 )
  {
    v27 = v4 - 2;
    result = v5;
    v25 = v5;
    do
    {
      v9 = result[2];
      v10 = *(_BYTE **)(a4 + 4 * v8);
      v11 = result[1];
      v12 = *result;
      v13 = result[3];
      v23 = v13 + 2;
      v14 = v12 + 2;
      *v10 = (v29 * (*v13 + *v12 + v12[2] + 2 * (*v13 + *v12 + *v9 + v12[1] + v13[1] + *v11 + v9[2] + v11[2]) + v13[2])
            + v28 * (*v9 + *v11 + v9[1] + (unsigned int)v11[1])
            + 0x8000) >> 16;
      v15 = v11 + 2;
      v16 = v9 + 2;
      v17 = v23;
      v21 = v10 + 1;
      v18 = v14;
      v24 = v27;
      if ( v27 != 0 )
      {
        do
        {
          *v21 = (v29
                * (v17[2]
                 + v18[2]
                 + *(v18 - 1)
                 + *(v17 - 1)
                 + 2 * (v15[2] + *v18 + v16[2] + *v17 + *(v15 - 1) + *(v16 - 1) + v18[1] + v17[1]))
                + v28 * (*v15 + *v16 + v15[1] + (unsigned int)v16[1])
                + 0x8000) >> 16;
          v15 += 2;
          v16 += 2;
          v18 += 2;
          v17 += 2;
          v19 = v24-- == 1;
          ++v21;
        }
        while ( !v19 );
      }
      v22 = v16[1];
      *v21 = (v29
            * (v17[1]
             + v18[1]
             + *(v17 - 1)
             + 2 * (v17[1] + v18[1] + v22 + *(v15 - 1) + *(v16 - 1) + v15[1] + *v17 + *v18)
             + *(v18 - 1))
            + v28 * (v22 + v15[1] + *v16 + (unsigned int)*v15)
            + 0x8000) >> 16;
      v8 = v26 + 1;
      result = v25 + 2;
      v20 = v26 + 1 < (int)a2[3];
      v25 += 2;
      ++v26;
    }
    while ( v20 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AD8F0
// Name: sub_101AD8F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__cdecl sub_101AD8F0(int *a1, int a2, int a3, int a4)
{
  int v4; // esi
  int v5; // eax
  int v6; // ecx
  _DWORD *result; // eax
  unsigned __int8 *v8; // edi
  int v9; // ebx
  unsigned __int8 *v10; // ecx
  int v11; // esi
  int v12; // edx
  unsigned __int8 *v13; // ebp
  unsigned __int8 *v14; // edi
  int v15; // eax
  int v16; // ebx
  unsigned __int8 *v17; // ecx
  int v18; // eax
  _BYTE *v19; // esi
  int v20; // ebx
  int v21; // esi
  int v22; // eax
  bool v23; // zf
  bool v24; // cc
  _DWORD *v25; // [esp+10h] [ebp-18h]
  int v26; // [esp+14h] [ebp-14h]
  int v27; // [esp+18h] [ebp-10h]
  int v28; // [esp+1Ch] [ebp-Ch]
  int v29; // [esp+20h] [ebp-8h]
  int v30; // [esp+24h] [ebp-4h]
  _BYTE *v31; // [esp+2Ch] [ebp+4h]
  _BYTE *v32; // [esp+2Ch] [ebp+4h]
  int v33; // [esp+34h] [ebp+Ch]

  v4 = 8 * *(_DWORD *)(a2 + 28);
  sub_101AD290(a1: v4, a2: a1[7], a3: a3 - 4, a4: a1[55] + 2);
  v5 = a1[45];
  v26 = (128 - v5) << 9;
  v6 = 0;
  result = (_DWORD *)(v5 << 6);
  v25 = result;
  v28 = 0;
  if ( *(int *)(a2 + 12) > 0 )
  {
    result = (_DWORD *)(a3 + 4);
    v30 = v4 - 2;
    v29 = a3 + 4;
    do
    {
      v8 = (unsigned __int8 *)*(result - 2);
      v9 = v8[1];
      v31 = *(_BYTE **)(a4 + 4 * v6);
      v10 = (unsigned __int8 *)*(result - 1);
      v11 = *v10;
      v12 = v11 + *(unsigned __int8 *)*result + *v8;
      v13 = (unsigned __int8 *)(*result + 1);
      v14 = v8 + 1;
      v15 = v9 + *v13;
      v16 = v10[1];
      v17 = v10 + 1;
      v18 = v16 + v15;
      *v31 = (unsigned int)((_DWORD)v25 * (v18 + 2 * v12 - v11) + v26 * v11 + 0x8000) >> 16;
      v19 = v31 + 1;
      v32 = v31 + 1;
      v33 = v18;
      v27 = v30;
      if ( v30 != 0 )
      {
        do
        {
          v20 = v14[1];
          v21 = *v17;
          v22 = v13[1];
          ++v14;
          ++v13;
          v18 = *++v17 + v20 + v22;
          *v32 = (unsigned int)((_DWORD)v25 * (v33 + v18 + v12 - v21) + v26 * v21 + 0x8000) >> 16;
          v12 = v33;
          v19 = v32 + 1;
          v23 = v27-- == 1;
          ++v32;
          v33 = v18;
        }
        while ( !v23 );
      }
      *v19 = ((_DWORD)v25 * (v12 + 2 * v18 - *v17) + v26 * (unsigned int)*v17 + 0x8000) >> 16;
      v6 = v28 + 1;
      result = (_DWORD *)(v29 + 4);
      v24 = ++v28 < *(_DWORD *)(a2 + 12);
      v29 += 4;
    }
    while ( v24 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101ADA80
// Name: void jinit_downsampler(struct jpeg_compress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jinit_downsampler(struct jpeg_compress_struct *a1)
{
  int v2; // ebx
  _DWORD *v3; // ebp
  _DWORD *v4; // edi
  int v5; // ecx
  int v6; // eax
  char v7; // [esp+Bh] [ebp-5h]
  int v8; // [esp+Ch] [ebp-4h]
  struct jpeg_compress_struct *v9; // [esp+14h] [ebp+4h]

  v7 = 1;
  v2 = (**((int (__cdecl ***)(struct jpeg_compress_struct *, int, int))a1 + 1))(a1, a2: 1, a3: 52);
  *((_DWORD *)a1 + 85) = v2;
  *(_DWORD *)v2 = CDummyMaterialSystem::EndBatch;
  *(_DWORD *)(v2 + 4) = sub_101AD2E0;
  *(_BYTE *)(v2 + 8) = 0;
  v9 = (struct jpeg_compress_struct *)v2;
  if ( *((_BYTE *)a1 + 179) != 0 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 25;
    (**(void (__cdecl ***)(struct jpeg_compress_struct *))a1)(a1);
  }
  v8 = 0;
  if ( *((int *)a1 + 15) > 0 )
  {
    v3 = (_DWORD *)(*((_DWORD *)a1 + 17) + 12);
    v4 = (_DWORD *)(v2 + 12);
    do
    {
      v5 = *(v3 - 1);
      v6 = *((_DWORD *)a1 + 54);
      if ( v5 == v6 && *v3 == *((_DWORD *)a1 + 55) )
      {
        if ( *((_DWORD *)a1 + 45) != 0 )
        {
          *v4 = sub_101AD8F0;
          *(_BYTE *)(v2 + 8) = 1;
        }
        else
        {
          *v4 = sub_101AD4A0;
        }
      }
      else
      {
        if ( 2 * v5 != v6 )
          goto LABEL_18;
        v2 = (int)v9;
        if ( *v3 == *((_DWORD *)a1 + 55) )
        {
          v7 = 0;
          *v4 = sub_101AD4F0;
        }
        else
        {
          if ( 2 * v5 != v6 || 2 * *v3 != *((_DWORD *)a1 + 55) )
          {
LABEL_18:
            if ( v6 % v5 != 0 || *((_DWORD *)a1 + 55) % *v3 != 0 )
            {
              *(_DWORD *)(*(_DWORD *)a1 + 20) = 38;
              (**(void (__cdecl ***)(struct jpeg_compress_struct *))a1)(a1);
            }
            else
            {
              v7 = 0;
              *v4 = sub_101AD370;
            }
            goto LABEL_22;
          }
          if ( *((_DWORD *)a1 + 45) != 0 )
          {
            *v4 = sub_101AD670;
            *((_BYTE *)v9 + 8) = 1;
          }
          else
          {
            *v4 = sub_101AD5A0;
          }
        }
      }
LABEL_22:
      ++v4;
      v3 += 21;
      ++v8;
    }
    while ( v8 < *((_DWORD *)a1 + 15) );
  }
  if ( *((_DWORD *)a1 + 45) != 0 && v7 == 0 )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 99;
    (*(void (__cdecl **)(struct jpeg_compress_struct *, _DWORD))(*(_DWORD *)a1 + 4))(a1, a2: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101ADC00
// Name: sub_101ADC00
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl sub_101ADC00(int a1)
{
  int v1; // esi
  int v2; // eax
  int v3; // edx
  int v4; // ebx
  int v5; // edi
  int v6; // esi
  int v7; // ecx
  int *result; // eax
  int v9; // ebp
  int v10; // ebp
  int v11; // ebp
  int v12; // [esp+10h] [ebp-8h]
  int v13; // [esp+14h] [ebp-4h]
  int v14; // [esp+1Ch] [ebp+4h]

  v1 = *(_DWORD *)(a1 + 336);
  v2 = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, a2: 1, a3: 0x2000);
  v3 = 0;
  *(_DWORD *)(v1 + 8) = v2;
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v13 = 0;
  v12 = 0;
  v14 = 8421375;
  v7 = 0x8000;
  result = (int *)(v2 + 2048);
  do
  {
    v9 = v14;
    v14 += 0x8000;
    result[768] = v9;
    v10 = v12;
    v12 -= 27439;
    result[1024] = v10;
    v11 = v13;
    v13 -= 5329;
    *result = v7;
    *(result - 512) = v3;
    *(result - 256) = v6;
    result[256] = v5;
    result[512] = v4;
    result[1280] = v11;
    v7 += 7471;
    v3 += 19595;
    ++result;
    v6 += 38470;
    v5 -= 11059;
    v4 -= 21709;
  }
  while ( v7 <= 1937873 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101ADCE0
// Name: sub_101ADCE0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101ADCE0(int a1, unsigned __int8 **a2, _DWORD *a3, int a4, int a5)
{
  bool v5; // sf
  int result; // eax
  _DWORD *v7; // edi
  int v8; // edx
  unsigned __int8 *v9; // esi
  int v10; // ebx
  int v11; // ecx
  int v12; // ebp
  int v13; // edi
  bool v14; // zf
  int v15; // [esp+0h] [ebp-14h]
  int v16; // [esp+4h] [ebp-10h]
  int v17; // [esp+8h] [ebp-Ch]
  int v18; // [esp+Ch] [ebp-8h]
  int v19; // [esp+18h] [ebp+4h]
  int v20; // [esp+18h] [ebp+4h]
  int v21; // [esp+28h] [ebp+14h]

  v5 = a5 - 1 < 0;
  v21 = a5 - 1;
  result = *(_DWORD *)(*(_DWORD *)(a1 + 336) + 8);
  v15 = *(_DWORD *)(a1 + 28);
  if ( !v5 )
  {
    v7 = a3;
    v8 = 4 * a4;
    do
    {
      v9 = *a2++;
      v10 = *(_DWORD *)(v8 + *v7);
      v11 = *(_DWORD *)(v8 + v7[1]);
      v19 = *(_DWORD *)(v8 + v7[2]);
      v8 += 4;
      if ( v15 != 0 )
      {
        v16 = v10 - v11;
        v18 = v19 - v11;
        v20 = v15;
        do
        {
          v12 = v9[1];
          v13 = *v9;
          v17 = v9[2];
          v9 += 3;
          ++v11;
          *(_BYTE *)(v16 + v11 - 1) = (unsigned int)(*(_DWORD *)(result + 4 * v13)
                                                   + *(_DWORD *)(result + 4 * v12 + 1024)
                                                   + *(_DWORD *)(result + 4 * v17 + 2048)) >> 16;
          *(_BYTE *)(v11 - 1) = (unsigned int)(*(_DWORD *)(result + 4 * v13 + 3072)
                                             + *(_DWORD *)(result + 4 * v12 + 4096)
                                             + *(_DWORD *)(result + 4 * v17 + 5120)) >> 16;
          v14 = v20-- == 1;
          *(_BYTE *)(v18 + v11 - 1) = (unsigned int)(*(_DWORD *)(result + 4 * v13 + 5120)
                                                   + *(_DWORD *)(result + 4 * v12 + 6144)
                                                   + *(_DWORD *)(result + 4 * v17 + 7168)) >> 16;
        }
        while ( !v14 );
        v7 = a3;
      }
      --v21;
    }
    while ( v21 >= 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101ADE00
// Name: sub_101ADE00
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl sub_101ADE00(unsigned __int8 *a1, unsigned __int8 **a2, _DWORD *a3, int a4, int a5)
{
  bool v5; // sf
  unsigned __int8 *result; // eax
  unsigned int v7; // edx
  int v8; // esi
  int v9; // edi
  unsigned int v10; // ecx
  unsigned int v11; // [esp+4h] [ebp-8h]
  int v12; // [esp+10h] [ebp+4h]
  int v13; // [esp+20h] [ebp+14h]

  v5 = a5 - 1 < 0;
  v13 = a5 - 1;
  result = a1;
  v7 = *((_DWORD *)a1 + 7);
  v8 = *(_DWORD *)(*((_DWORD *)a1 + 84) + 8);
  v11 = v7;
  if ( !v5 )
  {
    v9 = 4 * a4;
    do
    {
      result = *a2++;
      v12 = *(_DWORD *)(v9 + *a3);
      v9 += 4;
      v10 = 0;
      if ( v7 != 0 )
      {
        do
        {
          *(_BYTE *)(++v10 + v12 - 1) = (unsigned int)(*(_DWORD *)(v8 + 4 * *result)
                                                     + *(_DWORD *)(v8 + 4 * result[1] + 1024)
                                                     + *(_DWORD *)(v8 + 4 * result[2] + 2048)) >> 16;
          v7 = v11;
          result += 3;
        }
        while ( v10 < v11 );
      }
      --v13;
    }
    while ( v13 >= 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101ADEB0
// Name: sub_101ADEB0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101ADEB0(int a1, unsigned __int8 **a2, _DWORD *a3, int a4, int a5)
{
  bool v5; // sf
  int result; // eax
  _DWORD *v7; // esi
  int v8; // ecx
  unsigned __int8 *v9; // edx
  _BYTE *v10; // ebp
  int v11; // edi
  int v12; // ecx
  int v13; // esi
  int v14; // edi
  bool v15; // zf
  int v16; // [esp+0h] [ebp-18h]
  int v17; // [esp+0h] [ebp-18h]
  int v18; // [esp+4h] [ebp-14h]
  int v19; // [esp+8h] [ebp-10h]
  int v20; // [esp+8h] [ebp-10h]
  int v21; // [esp+Ch] [ebp-Ch]
  int v22; // [esp+10h] [ebp-8h]
  int v23; // [esp+14h] [ebp-4h]
  unsigned __int8 *v24; // [esp+1Ch] [ebp+4h]
  int v25; // [esp+2Ch] [ebp+14h]

  v5 = a5 - 1 < 0;
  v25 = a5 - 1;
  result = *(_DWORD *)(*(_DWORD *)(a1 + 336) + 8);
  v18 = *(_DWORD *)(a1 + 28);
  if ( !v5 )
  {
    v7 = a3;
    v8 = 4 * a4;
    do
    {
      v9 = *a2++;
      v10 = *(_BYTE **)(v8 + *v7);
      v11 = *(_DWORD *)(v8 + v7[1]);
      v19 = *(_DWORD *)(v8 + v7[2]);
      v16 = *(_DWORD *)(v8 + v7[3]);
      v8 += 4;
      v24 = v9;
      v23 = v8;
      if ( v18 != 0 )
      {
        v21 = v16 - (_DWORD)v10;
        v22 = v11 - (_DWORD)v10;
        v20 = v19 - (_DWORD)v10;
        v17 = v18;
        while ( 1 )
        {
          v12 = 255 - *v9;
          v13 = 255 - v9[1];
          v14 = 255 - v9[2];
          v10[v21] = v9[3];
          v24 += 4;
          *v10++ = (unsigned int)(*(_DWORD *)(result + 4 * v12)
                                + *(_DWORD *)(result + 4 * v13 + 1024)
                                + *(_DWORD *)(result + 4 * v14 + 2048)) >> 16;
          v10[v22 - 1] = (unsigned int)(*(_DWORD *)(result + 4 * v12 + 3072)
                                      + *(_DWORD *)(result + 4 * v13 + 4096)
                                      + *(_DWORD *)(result + 4 * v14 + 5120)) >> 16;
          v15 = v17-- == 1;
          v10[v20 - 1] = (unsigned int)(*(_DWORD *)(result + 4 * v12 + 5120)
                                      + *(_DWORD *)(result + 4 * v13 + 6144)
                                      + *(_DWORD *)(result + 4 * v14 + 7168)) >> 16;
          if ( v15 )
            break;
          v9 = v24;
        }
        v7 = a3;
        v8 = v23;
      }
      --v25;
    }
    while ( v25 >= 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AE000
// Name: sub_101AE000
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl sub_101AE000(int a1, char **a2, _DWORD *a3, int a4, int a5)
{
  bool v5; // sf
  unsigned int v6; // edi
  unsigned int result; // eax
  int v9; // edx
  int v10; // esi
  char *v11; // ecx
  char v12; // bl
  unsigned int v13; // [esp+8h] [ebp+4h]
  int v14; // [esp+18h] [ebp+14h]

  v5 = a5 - 1 < 0;
  v14 = a5 - 1;
  v6 = *(_DWORD *)(a1 + 28);
  result = *(_DWORD *)(a1 + 36);
  v13 = result;
  if ( !v5 )
  {
    v9 = 4 * a4;
    do
    {
      v10 = *(_DWORD *)(v9 + *a3);
      v11 = *a2++;
      v9 += 4;
      for ( result = 0; result < v6; ++result )
      {
        v12 = *v11;
        v11 += v13;
        *(_BYTE *)(result + v10) = v12;
      }
      --v14;
    }
    while ( v14 >= 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AE0E0
// Name: void jinit_color_converter(struct jpeg_compress_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jinit_color_converter(int (__cdecl ***a1)(struct jpeg_compress_struct *, int, int))
{
  int (__cdecl **v1)(struct jpeg_compress_struct *, int, int); // edi
  int (__cdecl **v2)(struct jpeg_compress_struct *, int, int); // eax
  int (__cdecl **v3)(struct jpeg_compress_struct *, int, int); // eax
  int (__cdecl **v4)(struct jpeg_compress_struct *, int, int); // eax
  int (__cdecl **v5)(struct jpeg_compress_struct *, int, int); // eax

  v1 = (int (__cdecl **)(struct jpeg_compress_struct *, int, int))(*a1[1])(
                                                                    (struct jpeg_compress_struct *)a1,
                                                                    a2: 1,
                                                                    a3: 12);
  a1[84] = v1;
  *v1 = (int (__cdecl *)(struct jpeg_compress_struct *, int, int))CDummyMaterialSystem::EndBatch;
  switch ( (unsigned int)a1[10] )
  {
    case 1u:
      if ( a1[9] != (int (__cdecl **)(struct jpeg_compress_struct *, int, int))1 )
        goto LABEL_9;
      break;
    case 2u:
    case 3u:
      if ( a1[9] != (int (__cdecl **)(struct jpeg_compress_struct *, int, int))3 )
        goto LABEL_9;
      break;
    case 4u:
    case 5u:
      if ( a1[9] != (int (__cdecl **)(struct jpeg_compress_struct *, int, int))4 )
        goto LABEL_9;
      break;
    default:
      if ( (int)a1[9] < 1 )
      {
LABEL_9:
        (*a1)[5] = (int (__cdecl *)(struct jpeg_compress_struct *, int, int))9;
        ((void (__cdecl *)(int (__cdecl ***)(struct jpeg_compress_struct *, int, int)))**a1)(a1);
      }
      break;
  }
  v2 = a1[16];
  switch ( (unsigned int)v2 )
  {
    case 1u:
      if ( a1[15] != (int (__cdecl **)(struct jpeg_compress_struct *, int, int))1 )
      {
        (*a1)[5] = (int (__cdecl *)(struct jpeg_compress_struct *, int, int))10;
        ((void (__cdecl *)(int (__cdecl ***)(struct jpeg_compress_struct *, int, int)))**a1)(a1);
      }
      v3 = a1[10];
      if ( v3 == (int (__cdecl **)(struct jpeg_compress_struct *, int, int))1 )
        goto LABEL_17;
      if ( v3 == (int (__cdecl **)(struct jpeg_compress_struct *, int, int))2 )
      {
        *v1 = (int (__cdecl *)(struct jpeg_compress_struct *, int, int))sub_101ADC00;
        v1[1] = (int (__cdecl *)(struct jpeg_compress_struct *, int, int))sub_101ADE00;
      }
      else
      {
        if ( v3 != (int (__cdecl **)(struct jpeg_compress_struct *, int, int))3 )
          goto LABEL_37;
LABEL_17:
        v1[1] = (int (__cdecl *)(struct jpeg_compress_struct *, int, int))sub_101AE000;
      }
      return;
    case 2u:
      if ( a1[15] != (int (__cdecl **)(struct jpeg_compress_struct *, int, int))3 )
      {
        (*a1)[5] = (int (__cdecl *)(struct jpeg_compress_struct *, int, int))10;
        ((void (__cdecl *)(int (__cdecl ***)(struct jpeg_compress_struct *, int, int)))**a1)(a1);
      }
      if ( a1[10] == (int (__cdecl **)(struct jpeg_compress_struct *, int, int))2 )
        goto LABEL_41;
      goto LABEL_37;
    case 3u:
      if ( a1[15] != (int (__cdecl **)(struct jpeg_compress_struct *, int, int))3 )
      {
        (*a1)[5] = (int (__cdecl *)(struct jpeg_compress_struct *, int, int))10;
        ((void (__cdecl *)(int (__cdecl ***)(struct jpeg_compress_struct *, int, int)))**a1)(a1);
      }
      v4 = a1[10];
      if ( v4 == (int (__cdecl **)(struct jpeg_compress_struct *, int, int))2 )
      {
        *v1 = (int (__cdecl *)(struct jpeg_compress_struct *, int, int))sub_101ADC00;
        v1[1] = (int (__cdecl *)(struct jpeg_compress_struct *, int, int))sub_101ADCE0;
        return;
      }
      if ( v4 != (int (__cdecl **)(struct jpeg_compress_struct *, int, int))3 )
        goto LABEL_37;
      goto LABEL_41;
    case 4u:
      if ( a1[15] != (int (__cdecl **)(struct jpeg_compress_struct *, int, int))4 )
      {
        (*a1)[5] = (int (__cdecl *)(struct jpeg_compress_struct *, int, int))10;
        ((void (__cdecl *)(int (__cdecl ***)(struct jpeg_compress_struct *, int, int)))**a1)(a1);
      }
      if ( a1[10] != (int (__cdecl **)(struct jpeg_compress_struct *, int, int))4 )
        goto LABEL_37;
      goto LABEL_41;
    case 5u:
      if ( a1[15] != (int (__cdecl **)(struct jpeg_compress_struct *, int, int))4 )
      {
        (*a1)[5] = (int (__cdecl *)(struct jpeg_compress_struct *, int, int))10;
        ((void (__cdecl *)(int (__cdecl ***)(struct jpeg_compress_struct *, int, int)))**a1)(a1);
      }
      v5 = a1[10];
      if ( v5 == (int (__cdecl **)(struct jpeg_compress_struct *, int, int))4 )
      {
        *v1 = (int (__cdecl *)(struct jpeg_compress_struct *, int, int))sub_101ADC00;
        v1[1] = (int (__cdecl *)(struct jpeg_compress_struct *, int, int))sub_101ADEB0;
      }
      else if ( v5 == (int (__cdecl **)(struct jpeg_compress_struct *, int, int))5 )
      {
LABEL_41:
        v1[1] = (int (__cdecl *)(struct jpeg_compress_struct *, int, int))sub_101AE060;
      }
      else
      {
LABEL_37:
        (*a1)[5] = (int (__cdecl *)(struct jpeg_compress_struct *, int, int))27;
        ((void (__cdecl *)(int (__cdecl ***)(struct jpeg_compress_struct *, int, int)))**a1)(a1);
      }
      return;
    default:
      if ( v2 != a1[10] || a1[15] != a1[9] )
      {
        (*a1)[5] = (int (__cdecl *)(struct jpeg_compress_struct *, int, int))27;
        ((void (__cdecl *)(int (__cdecl ***)(struct jpeg_compress_struct *, int, int)))**a1)(a1);
      }
      goto LABEL_41;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AE310
// Name: void jpeg_idct_islow(struct jpeg_decompress_struct __near *,struct jpeg_component_info __near *,short __near *,unsigned char __near * __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_idct_islow(
        struct jpeg_decompress_struct *a1,
        struct jpeg_component_info *a2,
        __int16 *a3,
        unsigned __int8 **a4,
        unsigned int a5)
{
  _DWORD *v5; // ebx
  __int16 *v6; // esi
  int v7; // edx
  int *v8; // eax
  int v9; // ecx
  int v10; // ecx
  int v11; // edx
  int v12; // edi
  int v13; // ebp
  int v14; // edx
  int v15; // edi
  int v16; // edx
  int v17; // edi
  int v18; // ecx
  int v19; // edx
  int v20; // esi
  int v21; // ebp
  int v22; // esi
  int v23; // ecx
  int v24; // edi
  int v25; // edx
  int v26; // edi
  bool v27; // cc
  int v28; // edi
  _DWORD *v29; // ecx
  unsigned __int8 *v30; // eax
  unsigned __int8 v31; // bl
  int v32; // edx
  int v33; // esi
  int v34; // edi
  int v35; // ebp
  int v36; // edx
  int v37; // ebx
  int v38; // edi
  int v39; // edx
  int v40; // esi
  int v41; // edi
  int v42; // ebp
  int v43; // edx
  int v44; // esi
  int v45; // ebp
  int v46; // [esp+10h] [ebp-138h]
  int v47; // [esp+10h] [ebp-138h]
  int v48; // [esp+14h] [ebp-134h]
  int v49; // [esp+14h] [ebp-134h]
  int v50; // [esp+14h] [ebp-134h]
  int v51; // [esp+18h] [ebp-130h]
  int v52; // [esp+18h] [ebp-130h]
  int v53; // [esp+18h] [ebp-130h]
  _DWORD *v54; // [esp+1Ch] [ebp-12Ch]
  int v55; // [esp+1Ch] [ebp-12Ch]
  int v56; // [esp+20h] [ebp-128h]
  int v57; // [esp+20h] [ebp-128h]
  __int16 *v58; // [esp+24h] [ebp-124h]
  int v59; // [esp+24h] [ebp-124h]
  int v60; // [esp+28h] [ebp-120h]
  int v61; // [esp+2Ch] [ebp-11Ch]
  int v62; // [esp+2Ch] [ebp-11Ch]
  int v63; // [esp+30h] [ebp-118h]
  int v64; // [esp+34h] [ebp-114h]
  int v65; // [esp+34h] [ebp-114h]
  int v66; // [esp+38h] [ebp-110h]
  int v67; // [esp+38h] [ebp-110h]
  int v68; // [esp+3Ch] [ebp-10Ch]
  int v69; // [esp+40h] [ebp-108h]
  int v70; // [esp+44h] [ebp-104h]
  _BYTE v71[256]; // [esp+48h] [ebp-100h] BYREF

  v5 = *((_DWORD **)a2 + 20);
  v6 = a3;
  v7 = *((_DWORD *)a1 + 72) + 128;
  v68 = v7;
  v58 = a3;
  v54 = v5;
  v8 = (int *)v71;
  v64 = 8;
  do
  {
    if ( v6[8] != 0 || v6[16] != 0 || v6[24] != 0 || v6[32] != 0 || v6[40] != 0 || v6[48] != 0 || v6[56] != 0 )
    {
      v10 = v5[16] * v6[16];
      v11 = v5[48] * v6[48];
      v12 = 4433 * (v11 + v10);
      v13 = v12 - 15137 * v11;
      v14 = *v5 * *v6;
      v51 = v5[32] * v6[32];
      v48 = v12 + 6270 * v10;
      v15 = (v14 + v51) << 13;
      v16 = (v14 - v51) << 13;
      v70 = v15 + v48;
      v69 = v15 - v48;
      v17 = v5[8] * v6[8];
      v49 = v16 + v13;
      v18 = v5[56] * v6[56];
      v66 = v16 - v13;
      v19 = v5[40] * v6[40];
      v20 = v5[24] * v6[24];
      v63 = 9633 * (v18 + v20 + v19 + v17);
      v56 = -7373 * (v18 + v17);
      v46 = -20995 * (v19 + v20);
      v52 = v63 - 16069 * (v18 + v20);
      v21 = v63 - 3196 * (v19 + v17);
      v22 = v46 + v52 + 25172 * v20;
      v23 = v52 + v56 + 2446 * v18;
      v24 = v56 + v21 + 12299 * v17;
      v25 = v46 + v21 + 16819 * v19;
      *v8 = (v70 + v24 + 1024) >> 11;
      v8[56] = (v70 - v24 + 1024) >> 11;
      v8[48] = (v49 - v22 + 1024) >> 11;
      v26 = v66 + v25 + 1024;
      v8[40] = (v66 - v25 + 1024) >> 11;
      v8[8] = (v49 + v22 + 1024) >> 11;
      v5 = v54;
      v8[24] = (v69 + v23 + 1024) >> 11;
      v6 = v58;
      v8[32] = (v69 - v23 + 1024) >> 11;
      v7 = v68;
      v8[16] = v26 >> 11;
    }
    else
    {
      v9 = 4 * *v5 * *v6;
      *v8 = v9;
      v8[8] = v9;
      v8[16] = v9;
      v8[24] = v9;
      v8[32] = v9;
      v8[40] = v9;
      v8[48] = v9;
      v8[56] = v9;
    }
    ++v6;
    ++v5;
    ++v8;
    v27 = v64 - 1 <= 0;
    v54 = v5;
    v58 = v6;
    --v64;
  }
  while ( !v27 );
  v28 = 0;
  v29 = v71;
  v65 = 0;
  do
  {
    v30 = &a4[v28][a5];
    if ( v29[1] != 0 || v29[2] != 0 || v29[3] != 0 || v29[4] != 0 || v29[5] != 0 || v29[6] != 0 || v29[7] != 0 )
    {
      v32 = v29[2];
      v33 = v29[6];
      v34 = 4433 * (v33 + v32);
      v35 = v34 + 6270 * v32;
      v36 = v29[4];
      v37 = v34 - 15137 * v33;
      v38 = (*v29 + v36) << 13;
      v39 = (*v29 - v36) << 13;
      v40 = v38 + v35;
      v41 = v38 - v35;
      v42 = v39 + v37;
      v67 = v39 - v37;
      v43 = v29[7];
      v60 = v29[5];
      v55 = v29[3];
      v61 = v60 + v29[1];
      v57 = -7373 * (v29[1] + v43);
      v47 = -20995 * (v55 + v60);
      v53 = 9633 * (v55 + v43 + v61) - 16069 * (v55 + v43);
      v62 = 9633 * (v55 + v43 + v61) - 3196 * v61;
      v59 = v53 + v57 + 2446 * v43;
      v50 = v57 + v62 + 12299 * v29[1];
      v7 = v68;
      *v30 = *(_BYTE *)((((v40 + v50 + 0x20000) >> 18) & 0x3FF) + v68);
      LOBYTE(v37) = *(_BYTE *)((((v40 - v50 + 0x20000) >> 18) & 0x3FF) + v68);
      v44 = v47 + v53 + 25172 * v55;
      v30[7] = v37;
      v30[1] = *(_BYTE *)((((v44 + v42 + 0x20000) >> 18) & 0x3FF) + v68);
      LOBYTE(v37) = *(_BYTE *)(v68 + (((v42 - v44 + 0x20000) >> 18) & 0x3FF));
      v45 = v47 + v62 + 16819 * v60;
      v30[6] = v37;
      v30[2] = *(_BYTE *)((((v67 + v45 + 0x20000) >> 18) & 0x3FF) + v68);
      v30[5] = *(_BYTE *)((((v67 - v45 + 0x20000) >> 18) & 0x3FF) + v68);
      v30[3] = *(_BYTE *)((((v41 + v59 + 0x20000) >> 18) & 0x3FF) + v68);
      v31 = *(_BYTE *)((((v41 - v59 + 0x20000) >> 18) & 0x3FF) + v68);
      v28 = v65;
    }
    else
    {
      v31 = *(_BYTE *)((((*v29 + 16) >> 5) & 0x3FF) + v7);
      *v30 = v31;
      v30[1] = v31;
      v30[2] = v31;
      v30[3] = v31;
      v30[5] = v31;
      v30[6] = v31;
      v30[7] = v31;
    }
    ++v28;
    v29 += 8;
    v30[4] = v31;
    v65 = v28;
  }
  while ( v28 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x101AE830
// Name: void jpeg_idct_ifast(struct jpeg_decompress_struct __near *,struct jpeg_component_info __near *,short __near *,unsigned char __near * __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_idct_ifast(
        struct jpeg_decompress_struct *a1,
        struct jpeg_component_info *a2,
        __int16 *a3,
        unsigned __int8 **a4,
        unsigned int a5)
{
  _DWORD *v5; // edx
  int v7; // ebp
  int *v8; // ecx
  int v9; // eax
  int v10; // edi
  int v11; // ebp
  int v12; // eax
  int v13; // ebx
  int v14; // edi
  int v15; // edi
  int v16; // ebx
  int v17; // eax
  int v18; // ebp
  int v19; // edi
  int v20; // eax
  int v21; // ebx
  int v22; // ebp
  int v23; // edi
  int v24; // eax
  int v25; // esi
  int *v26; // edx
  unsigned __int8 *v27; // eax
  unsigned __int8 v28; // cl
  int v29; // edi
  int v30; // esi
  int v31; // ebx
  int v32; // ecx
  int v33; // edi
  int v34; // ecx
  int v35; // esi
  int v36; // edi
  int v37; // esi
  int v38; // ebx
  int v39; // edi
  int v40; // ecx
  int v41; // edi
  int v42; // ebx
  int v43; // edi
  int v44; // [esp+Ch] [ebp-124h]
  int v45; // [esp+Ch] [ebp-124h]
  int v46; // [esp+Ch] [ebp-124h]
  int v47; // [esp+Ch] [ebp-124h]
  int v48; // [esp+10h] [ebp-120h]
  int v49; // [esp+10h] [ebp-120h]
  int v50; // [esp+14h] [ebp-11Ch]
  int v51; // [esp+14h] [ebp-11Ch]
  int v52; // [esp+14h] [ebp-11Ch]
  int i; // [esp+18h] [ebp-118h]
  int v54; // [esp+18h] [ebp-118h]
  int v55; // [esp+1Ch] [ebp-114h]
  int v56; // [esp+1Ch] [ebp-114h]
  int v57; // [esp+20h] [ebp-110h]
  int v58; // [esp+20h] [ebp-110h]
  int v59; // [esp+24h] [ebp-10Ch]
  int v60; // [esp+24h] [ebp-10Ch]
  int v61; // [esp+28h] [ebp-108h]
  int v62; // [esp+28h] [ebp-108h]
  int v63; // [esp+2Ch] [ebp-104h]
  int v64; // [esp+2Ch] [ebp-104h]
  _BYTE v65[256]; // [esp+30h] [ebp-100h] BYREF

  v5 = *((_DWORD **)a2 + 20);
  v7 = *((_DWORD *)a1 + 72) + 128;
  v55 = v7;
  v8 = (int *)v65;
  for ( i = 8; i > 0; --i )
  {
    if ( a3[8] != 0 || a3[16] != 0 || a3[24] != 0 || a3[32] != 0 || a3[40] != 0 || a3[48] != 0 || a3[56] != 0 )
    {
      v10 = *v5 * *a3;
      v11 = v5[32] * a3[32];
      v12 = v5[16] * a3[16];
      v50 = v5[48] * a3[48];
      v13 = v10 + v11;
      v14 = v10 - v11;
      v44 = ((362 * (v12 - v50)) >> 8) - (v12 + v50);
      v59 = v13 + v12 + v50;
      v51 = v13 - (v12 + v50);
      v61 = v44 + v14;
      v63 = v14 - v44;
      v15 = v5[40] * a3[40];
      v16 = v5[8] * a3[8];
      v17 = v5[24] * a3[24];
      v48 = v5[56] * a3[56];
      v18 = v15 + v17;
      v19 = v15 - v17;
      v20 = v16 + v48;
      v21 = v16 - v48;
      v57 = v18;
      v49 = v20 + v18;
      v22 = (473 * (v21 + v19)) >> 8;
      v23 = v22 + ((-669 * v19) >> 8) - v49;
      v24 = ((362 * (v20 - v57)) >> 8) - v23;
      v45 = v24 + ((277 * v21) >> 8) - v22;
      *v8 = v59 + v49;
      v8[56] = v59 - v49;
      v8[8] = v23 + v61;
      v8[40] = v63 - v24;
      v8[48] = v61 - v23;
      v8[16] = v24 + v63;
      v7 = v55;
      v8[32] = v45 + v51;
      v9 = v51 - v45;
    }
    else
    {
      v9 = *v5 * *a3;
      *v8 = v9;
      v8[8] = v9;
      v8[16] = v9;
      v8[32] = v9;
      v8[40] = v9;
      v8[48] = v9;
      v8[56] = v9;
    }
    v8[24] = v9;
    ++a3;
    ++v5;
    ++v8;
  }
  v25 = 0;
  v26 = (int *)v65;
  v54 = 0;
  do
  {
    v27 = &a4[v25][a5];
    if ( v26[1] != 0 || v26[2] != 0 || v26[3] != 0 || v26[4] != 0 || v26[5] != 0 || v26[6] != 0 || v26[7] != 0 )
    {
      v29 = v26[4];
      v30 = *v26 + v29;
      v31 = *v26 - v29;
      v32 = v26[2];
      v33 = v32 + v26[6];
      v46 = ((362 * (v32 - v26[6])) >> 8) - v33;
      v60 = v33 + v30;
      v52 = v30 - v33;
      v34 = v26[3];
      v62 = v46 + v31;
      v35 = v26[5];
      v36 = v35 + v34;
      v37 = v35 - v34;
      v64 = v31 - v46;
      v38 = v26[7];
      v58 = v36;
      v39 = v26[1];
      v40 = v38 + v39;
      v41 = v39 - v38;
      v47 = (473 * (v41 + v37)) >> 8;
      v42 = v47 + ((-669 * v37) >> 8) - (v40 + v58);
      v56 = ((362 * (v40 - v58)) >> 8) - v42;
      v43 = v56 + ((277 * v41) >> 8) - v47;
      *v27 = *(_BYTE *)((((v60 + v40 + v58) >> 5) & 0x3FF) + v7);
      v27[7] = *(_BYTE *)((((v60 - (v40 + v58)) >> 5) & 0x3FF) + v7);
      v27[1] = *(_BYTE *)((((v42 + v62) >> 5) & 0x3FF) + v7);
      v27[6] = *(_BYTE *)((((v62 - v42) >> 5) & 0x3FF) + v7);
      v27[2] = *(_BYTE *)((((v56 + v64) >> 5) & 0x3FF) + v7);
      v27[5] = *(_BYTE *)((((v64 - v56) >> 5) & 0x3FF) + v7);
      v27[4] = *(_BYTE *)((((v43 + v52) >> 5) & 0x3FF) + v7);
      v28 = *(_BYTE *)((((v52 - v43) >> 5) & 0x3FF) + v7);
      v25 = v54;
    }
    else
    {
      v28 = *(_BYTE *)(((*v26 >> 5) & 0x3FF) + v7);
      *v27 = v28;
      v27[1] = v28;
      v27[2] = v28;
      v27[4] = v28;
      v27[5] = v28;
      v27[6] = v28;
      v27[7] = v28;
    }
    ++v25;
    v26 += 8;
    v27[3] = v28;
    v54 = v25;
  }
  while ( v25 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x101AEC10
// Name: void jpeg_idct_float(struct jpeg_decompress_struct __near *,struct jpeg_component_info __near *,short __near *,unsigned char __near * __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_idct_float(
        struct jpeg_decompress_struct *a1,
        struct jpeg_component_info *a2,
        __int16 *a3,
        unsigned __int8 **a4,
        unsigned int a5)
{
  double v5; // st6
  double v7; // st5
  float *v8; // edx
  int v9; // ebx
  float *v10; // eax
  int v11; // edi
  __int16 v12; // si
  double v13; // st5
  double v14; // st4
  double v15; // st5
  double v16; // st6
  int v17; // ebp
  float *v18; // esi
  unsigned __int8 *v19; // edi
  double v20; // st4
  double v21; // st4
  double v22; // st3
  float v23; // [esp+10h] [ebp-124h]
  float v24; // [esp+10h] [ebp-124h]
  float v25; // [esp+10h] [ebp-124h]
  float v26; // [esp+10h] [ebp-124h]
  float v27; // [esp+10h] [ebp-124h]
  float v28; // [esp+10h] [ebp-124h]
  float v29; // [esp+10h] [ebp-124h]
  float v30; // [esp+10h] [ebp-124h]
  float v31; // [esp+10h] [ebp-124h]
  float v32; // [esp+10h] [ebp-124h]
  float v33; // [esp+10h] [ebp-124h]
  float v34; // [esp+10h] [ebp-124h]
  float v35; // [esp+10h] [ebp-124h]
  float v36; // [esp+14h] [ebp-120h]
  float v37; // [esp+14h] [ebp-120h]
  float v38; // [esp+14h] [ebp-120h]
  float v39; // [esp+14h] [ebp-120h]
  float v40; // [esp+14h] [ebp-120h]
  float v41; // [esp+14h] [ebp-120h]
  float v42; // [esp+14h] [ebp-120h]
  float v43; // [esp+18h] [ebp-11Ch]
  float v44; // [esp+18h] [ebp-11Ch]
  float v45; // [esp+18h] [ebp-11Ch]
  float v46; // [esp+18h] [ebp-11Ch]
  float v47; // [esp+18h] [ebp-11Ch]
  float v48; // [esp+18h] [ebp-11Ch]
  float v49; // [esp+18h] [ebp-11Ch]
  float v50; // [esp+1Ch] [ebp-118h]
  float v51; // [esp+1Ch] [ebp-118h]
  float v52; // [esp+1Ch] [ebp-118h]
  float v53; // [esp+1Ch] [ebp-118h]
  float v54; // [esp+1Ch] [ebp-118h]
  float v55; // [esp+20h] [ebp-114h]
  float v56; // [esp+20h] [ebp-114h]
  float v57; // [esp+20h] [ebp-114h]
  float v58; // [esp+20h] [ebp-114h]
  float v59; // [esp+20h] [ebp-114h]
  float v60; // [esp+24h] [ebp-110h]
  float v61; // [esp+24h] [ebp-110h]
  float v62; // [esp+24h] [ebp-110h]
  float v63; // [esp+28h] [ebp-10Ch]
  float v64; // [esp+28h] [ebp-10Ch]
  float v65; // [esp+28h] [ebp-10Ch]
  float v66; // [esp+2Ch] [ebp-108h]
  float v67; // [esp+2Ch] [ebp-108h]
  float v68; // [esp+2Ch] [ebp-108h]
  float v69; // [esp+30h] [ebp-104h]
  float v70; // [esp+30h] [ebp-104h]
  float v71; // [esp+30h] [ebp-104h]
  char v72; // [esp+34h] [ebp-100h] BYREF
  char v73; // [esp+3Ch] [ebp-F8h] BYREF

  v5 = 1.847759008407593;
  v7 = 1.08239221572876;
  v8 = *((float **)a2 + 20);
  v9 = *((_DWORD *)a1 + 72) + 128;
  v10 = (float *)&v72;
  v11 = 8;
  do
  {
    v12 = a3[8];
    if ( v12 != 0 || a3[16] != 0 || a3[24] != 0 || a3[32] != 0 || a3[40] != 0 || a3[48] != 0 || a3[56] != 0 )
    {
      v60 = (double)*a3 * *v8;
      v63 = (double)a3[16] * v8[16];
      v50 = (double)a3[32] * v8[32];
      v69 = (double)a3[48] * v8[48];
      v36 = v50 + v60;
      v51 = v60 - v50;
      v24 = v69 + v63;
      v13 = v24;
      v25 = (v63 - v69) * 1.414213538169861 - v24;
      v61 = v13 + v36;
      v70 = v36 - v13;
      v64 = v25 + v51;
      v52 = v51 - v25;
      v37 = v8[8] * (double)v12;
      v43 = (double)a3[24] * v8[24];
      v55 = (double)a3[40] * v8[40];
      v66 = (double)a3[56] * v8[56];
      v14 = v43;
      v44 = v55 + v43;
      v56 = v55 - v14;
      v26 = v66 + v37;
      v38 = v37 - v66;
      v15 = v26;
      v67 = v26 + v44;
      v27 = v5 * (v38 + v56);
      v16 = v27;
      v28 = v27 - v56 * 2.613126039505005;
      v57 = v28 - v67;
      v29 = (v15 - v44) * 1.414213538169861;
      v45 = v29 - v57;
      v30 = v38 * 1.08239221572876 - v16;
      v39 = v30 + v45;
      *v10 = v67 + v61;
      v10[56] = v61 - v67;
      v10[8] = v57 + v64;
      v10[48] = v64 - v57;
      v10[16] = v45 + v52;
      v10[40] = v52 - v45;
      v10[32] = v39 + v70;
      v10[24] = v70 - v39;
      v7 = 1.08239221572876;
      v5 = 1.847759008407593;
    }
    else
    {
      v23 = (double)*a3 * *v8;
      *v10 = v23;
      v10[8] = v23;
      v10[16] = v23;
      v10[24] = v23;
      v10[32] = v23;
      v10[40] = v23;
      v10[48] = v23;
      v10[56] = v23;
    }
    --v11;
    ++a3;
    ++v8;
    ++v10;
  }
  while ( v11 > 0 );
  v17 = 0;
  v18 = (float *)&v73;
  do
  {
    v19 = &a4[v17][a5];
    v40 = v18[2] + *(v18 - 2);
    v53 = *(v18 - 2) - v18[2];
    v31 = v18[4] + *v18;
    v20 = v31;
    v32 = (*v18 - v18[4]) * 1.414213538169861 - v31;
    v62 = v20 + v40;
    v71 = v40 - v20;
    v65 = v32 + v53;
    v54 = v53 - v32;
    v46 = v18[3] + v18[1];
    v58 = v18[3] - v18[1];
    v33 = v18[5] + *(v18 - 1);
    v41 = *(v18 - 1) - v18[5];
    v21 = v33;
    v22 = v46;
    v68 = v33 + v46;
    v34 = (v41 + v58) * v5;
    v47 = v34 - v58 * 2.613126039505005;
    v59 = v47 - v68;
    v48 = (v21 - v22) * 1.414213538169861;
    v49 = v48 - v59;
    v35 = v41 * v7 - v34;
    v42 = v35 + v49;
    *v19 = *(_BYTE *)(((((int)(v68 + v62) + 4) >> 3) & 0x3FF) + v9);
    v19[7] = *(_BYTE *)(((((int)(v62 - v68) + 4) >> 3) & 0x3FF) + v9);
    v19[1] = *(_BYTE *)(((((int)(v59 + v65) + 4) >> 3) & 0x3FF) + v9);
    v19[6] = *(_BYTE *)(((((int)(v65 - v59) + 4) >> 3) & 0x3FF) + v9);
    v19[2] = *(_BYTE *)(((((int)(v49 + v54) + 4) >> 3) & 0x3FF) + v9);
    v19[5] = *(_BYTE *)(((((int)(v54 - v49) + 4) >> 3) & 0x3FF) + v9);
    v19[4] = *(_BYTE *)(((((int)(v42 + v71) + 4) >> 3) & 0x3FF) + v9);
    ++v17;
    v18 += 8;
    v19[3] = *(_BYTE *)(((((int)(v71 - v42) + 4) >> 3) & 0x3FF) + v9);
  }
  while ( v17 < 8 );
}

//------------------------------------------------------------------------------
// Address: 0x101AF160
// Name: void jpeg_idct_4x4(struct jpeg_decompress_struct __near *,struct jpeg_component_info __near *,short __near *,unsigned char __near * __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_idct_4x4(
        struct jpeg_decompress_struct *a1,
        struct jpeg_component_info *a2,
        __int16 *a3,
        unsigned __int8 **a4,
        unsigned int a5)
{
  _DWORD *v5; // edx
  int v6; // ebx
  __int16 *v7; // esi
  int v8; // edi
  int *v9; // eax
  int v10; // ecx
  int v11; // ecx
  int v12; // eax
  int v13; // edi
  int v14; // ebp
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  int v18; // ebx
  int v19; // edi
  int v20; // esi
  char *v21; // ecx
  int v22; // edx
  unsigned __int8 *v23; // ebp
  unsigned __int8 v24; // al
  int v25; // eax
  int v26; // edi
  int v27; // esi
  int v28; // edi
  int v29; // eax
  unsigned __int8 v30; // dl
  int v31; // [esp+10h] [ebp-98h]
  int v32; // [esp+10h] [ebp-98h]
  int v33; // [esp+10h] [ebp-98h]
  int v34; // [esp+14h] [ebp-94h]
  int v35; // [esp+14h] [ebp-94h]
  int v36; // [esp+18h] [ebp-90h]
  int v37; // [esp+18h] [ebp-90h]
  int v38; // [esp+1Ch] [ebp-8Ch]
  int v39; // [esp+1Ch] [ebp-8Ch]
  int *v40; // [esp+20h] [ebp-88h]
  int v41; // [esp+24h] [ebp-84h]
  char v42; // [esp+28h] [ebp-80h] BYREF
  _BYTE v43[96]; // [esp+48h] [ebp-60h] BYREF

  v5 = *((_DWORD **)a2 + 20);
  v6 = *((_DWORD *)a1 + 72) + 128;
  v7 = a3 + 48;
  v8 = 8;
  v9 = (int *)v43;
  v41 = v6;
  v36 = 8;
  v40 = (int *)v43;
  do
  {
    if ( v8 != 4 )
    {
      if ( *(v7 - 40) != 0 || *(v7 - 32) != 0 || *(v7 - 24) != 0 || *(v7 - 8) != 0 || *v7 != 0 || v7[8] != 0 )
      {
        v11 = 15137 * v5[16] * *(v7 - 32) - 6270 * v5[48] * *v7;
        v12 = (*v5 * *(v7 - 48)) << 14;
        v13 = v11 + v12;
        v14 = v12 - v11;
        v34 = v5[56] * v7[8];
        v38 = v5[24] * *(v7 - 24);
        v15 = v5[8] * *(v7 - 40);
        v31 = v5[40] * *(v7 - 8);
        v16 = 8697 * v15 + 11893 * v31 - 17799 * v38 - 1730 * v34;
        v17 = 7373 * v38 + 20995 * v15 - 4926 * v31 - 4176 * v34;
        v18 = v13 + v17 + 2048;
        v19 = v13 - v17;
        v9 = v40;
        v40[16] = (v19 + 2048) >> 12;
        *(v40 - 8) = v18 >> 12;
        v6 = v41;
        *v40 = (v16 + v14 + 2048) >> 12;
        v8 = v36;
        v40[8] = (v14 - v16 + 2048) >> 12;
      }
      else
      {
        v10 = 4 * *v5 * *(v7 - 48);
        *(v9 - 8) = v10;
        *v9 = v10;
        v9[8] = v10;
        v9[16] = v10;
      }
    }
    --v8;
    ++v9;
    ++v7;
    ++v5;
    v40 = v9;
    v36 = v8;
  }
  while ( v8 > 0 );
  v20 = 0;
  v21 = &v42;
  v37 = 0;
  do
  {
    v22 = *((_DWORD *)v21 + 1);
    v23 = &a4[v20][a5];
    if ( v22 != 0
      || *((_DWORD *)v21 + 2) != 0
      || *((_DWORD *)v21 + 3) != 0
      || *((_DWORD *)v21 + 5) != 0
      || *((_DWORD *)v21 + 6) != 0
      || *((_DWORD *)v21 + 7) != 0 )
    {
      v25 = 15137 * *((_DWORD *)v21 + 2) - 6270 * *((_DWORD *)v21 + 6);
      v26 = *(_DWORD *)v21 << 14;
      v27 = v25 + v26;
      v28 = v26 - v25;
      v39 = *((_DWORD *)v21 + 3);
      v35 = *((_DWORD *)v21 + 7);
      v32 = *((_DWORD *)v21 + 5);
      v29 = 8697 * v22 + 11893 * v32 - 17799 * v39 - 1730 * v35;
      v6 = v41;
      v33 = 7373 * v39 + 20995 * v22 - 4926 * v32 - 4176 * v35;
      *v23 = *(_BYTE *)((((v27 + v33 + 0x40000) >> 19) & 0x3FF) + v41);
      v30 = *(_BYTE *)((((v27 - v33 + 0x40000) >> 19) & 0x3FF) + v41);
      v20 = v37;
      v23[3] = v30;
      v23[1] = *(_BYTE *)((((v28 + v29 + 0x40000) >> 19) & 0x3FF) + v41);
      v24 = *(_BYTE *)((((v28 - v29 + 0x40000) >> 19) & 0x3FF) + v41);
    }
    else
    {
      v24 = *(_BYTE *)((((*(_DWORD *)v21 + 16) >> 5) & 0x3FF) + v6);
      *v23 = v24;
      v23[1] = v24;
      v23[3] = v24;
    }
    ++v20;
    v21 += 32;
    v23[2] = v24;
    v37 = v20;
  }
  while ( v20 < 4 );
}

//------------------------------------------------------------------------------
// Address: 0x101AF480
// Name: void jpeg_idct_2x2(struct jpeg_decompress_struct __near *,struct jpeg_component_info __near *,short __near *,unsigned char __near * __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_idct_2x2(
        struct jpeg_decompress_struct *a1,
        struct jpeg_component_info *a2,
        __int16 *a3,
        unsigned __int8 **a4,
        unsigned int a5)
{
  _DWORD *v5; // ecx
  __int16 *v6; // eax
  int v7; // esi
  int *v8; // edi
  __int16 v9; // bx
  int v10; // edx
  int v11; // esi
  int v12; // edx
  int v13; // ebx
  int v14; // edx
  __int16 v15; // bx
  int v16; // edx
  int v17; // esi
  int v18; // edx
  int v19; // ebx
  int v20; // edx
  __int16 v21; // bx
  int v22; // edx
  int v23; // esi
  int v24; // edx
  int v25; // ebx
  int v26; // edx
  __int16 v27; // bx
  int v28; // edx
  int v29; // esi
  int v30; // edx
  int v31; // ebx
  int v32; // edx
  unsigned __int8 *v33; // edx
  unsigned __int8 v34; // al
  int v35; // esi
  int v36; // eax
  int v37; // ecx
  int v38; // esi
  int v39; // edi
  int v40; // ebx
  unsigned __int8 *v41; // edx
  unsigned __int8 v42; // al
  int v43; // esi
  int v44; // eax
  int v45; // [esp+10h] [ebp-44h]
  int v46; // [esp+14h] [ebp-40h]
  int v47; // [esp+18h] [ebp-3Ch] BYREF
  int v48; // [esp+20h] [ebp-34h]
  int v49; // [esp+28h] [ebp-2Ch]
  int v50; // [esp+30h] [ebp-24h]
  int v51; // [esp+34h] [ebp-20h]
  int v52; // [esp+38h] [ebp-1Ch]
  int v53; // [esp+40h] [ebp-14h]
  int v54; // [esp+48h] [ebp-Ch]
  int v55; // [esp+50h] [ebp-4h]
  int v56; // [esp+58h] [ebp+4h]

  v5 = *((_DWORD **)a2 + 20);
  v45 = *((_DWORD *)a1 + 72) + 128;
  v6 = a3 + 24;
  v7 = 6;
  v56 = 6;
  v8 = &v47;
  do
  {
    if ( v7 != 4 && v7 != 2 && v7 != 0 )
    {
      v9 = *(v6 - 16);
      if ( v9 != 0 || *v6 != 0 || v6[16] != 0 || v6[32] != 0 )
      {
        v11 = 29692 * v5[8] * v9 + 6967 * v5[40] * v6[16] - 5906 * v5[56] * v6[32] - 10426 * v5[24] * *v6;
        v12 = (*v5 * *(v6 - 24)) << 15;
        v13 = v11 + v12 + 4096;
        v14 = v12 - v11;
        v7 = v56;
        *(v8 - 1) = v13 >> 13;
        v10 = (v14 + 4096) >> 13;
      }
      else
      {
        v10 = 4 * *v5 * *(v6 - 24);
        *(v8 - 1) = v10;
      }
      v8[7] = v10;
    }
    if ( v7 != 5 && v7 != 3 && v7 != 1 )
    {
      v15 = *(v6 - 15);
      if ( v15 != 0 || v6[1] != 0 || v6[17] != 0 || v6[33] != 0 )
      {
        v17 = 29692 * v5[9] * v15 + 6967 * v5[41] * v6[17] - 5906 * v5[57] * v6[33] - 10426 * v5[25] * v6[1];
        v18 = (v5[1] * *(v6 - 23)) << 15;
        v19 = v17 + v18 + 4096;
        v20 = v18 - v17;
        v7 = v56;
        *v8 = v19 >> 13;
        v16 = (v20 + 4096) >> 13;
      }
      else
      {
        v16 = 4 * v5[1] * *(v6 - 23);
        *v8 = v16;
      }
      v8[8] = v16;
    }
    if ( v7 != 6 && v7 != 4 && v7 != 2 )
    {
      v21 = *(v6 - 14);
      if ( v21 != 0 || v6[2] != 0 || v6[18] != 0 || v6[34] != 0 )
      {
        v23 = 29692 * v5[10] * v21 + 6967 * v5[42] * v6[18] - 5906 * v5[58] * v6[34] - 10426 * v5[26] * v6[2];
        v24 = (v5[2] * *(v6 - 22)) << 15;
        v25 = v23 + v24 + 4096;
        v26 = v24 - v23;
        v7 = v56;
        v8[1] = v25 >> 13;
        v22 = (v26 + 4096) >> 13;
      }
      else
      {
        v22 = 4 * v5[2] * *(v6 - 22);
        v8[1] = v22;
      }
      v8[9] = v22;
    }
    if ( v7 != 7 && v7 != 5 && v7 != 3 )
    {
      v27 = *(v6 - 13);
      if ( v27 != 0 || v6[3] != 0 || v6[19] != 0 || v6[35] != 0 )
      {
        v29 = 29692 * v5[11] * v27 + 6967 * v5[43] * v6[19] - 5906 * v5[59] * v6[35] - 10426 * v5[27] * v6[3];
        v30 = (v5[3] * *(v6 - 21)) << 15;
        v31 = v29 + v30 + 4096;
        v32 = v30 - v29;
        v7 = v56;
        v8[2] = v31 >> 13;
        v28 = (v32 + 4096) >> 13;
      }
      else
      {
        v28 = 4 * v5[3] * *(v6 - 21);
        v8[2] = v28;
      }
      v8[10] = v28;
    }
    v7 -= 4;
    v6 += 4;
    v5 += 4;
    v8 += 4;
    v56 = v7;
  }
  while ( v7 + 2 > 0 );
  v33 = &(*a4)[a5];
  if ( v47 != 0 || v48 != 0 || v49 != 0 || v50 != 0 )
  {
    v35 = 6967 * v49 + 29692 * v47 - 10426 * v48 - 5906 * v50;
    v36 = (((v46 << 15) - v35 + 0x80000) >> 20) & 0x3FF;
    *v33 = *(_BYTE *)((((v35 + (v46 << 15) + 0x80000) >> 20) & 0x3FF) + v45);
    v34 = *(_BYTE *)(v36 + v45);
  }
  else
  {
    v34 = *(_BYTE *)((((v46 + 16) >> 5) & 0x3FF) + v45);
    *v33 = v34;
  }
  v37 = v52;
  v38 = v55;
  v39 = v54;
  v40 = v53;
  v33[1] = v34;
  v41 = &a4[1][a5];
  if ( v37 != 0 || v40 != 0 || v39 != 0 || v38 != 0 )
  {
    v43 = 6967 * v39 + 29692 * v37 - 5906 * v38 - 10426 * v40;
    v44 = ((v51 << 15) - v43 + 0x80000) >> 20;
    *v41 = *(_BYTE *)((((v43 + (v51 << 15) + 0x80000) >> 20) & 0x3FF) + v45);
    v41[1] = *(_BYTE *)((v44 & 0x3FF) + v45);
  }
  else
  {
    v42 = *(_BYTE *)((((v51 + 16) >> 5) & 0x3FF) + v45);
    *v41 = v42;
    v41[1] = v42;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AF8F0
// Name: void jpeg_idct_1x1(struct jpeg_decompress_struct __near *,struct jpeg_component_info __near *,short __near *,unsigned char __near * __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_idct_1x1(
        struct jpeg_decompress_struct *a1,
        struct jpeg_component_info *a2,
        __int16 *a3,
        unsigned __int8 **a4,
        unsigned int a5)
{
  (*a4)[a5] = *(_BYTE *)((((**((_DWORD **)a2 + 20) * (unsigned __int16)*a3 + 4) >> 3) & 0x3FF)
                       + *((_DWORD *)a1 + 72)
                       + 128);
}

//------------------------------------------------------------------------------
// Address: 0x101AF930
// Name: void jpeg_fdct_islow(int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_fdct_islow(int *a1)
{
  int *v1; // eax
  int v2; // esi
  int v3; // edx
  int v4; // edi
  int v5; // ecx
  int v6; // edx
  int v7; // esi
  int v8; // ebx
  int v9; // esi
  int v10; // edi
  int v11; // ebx
  int v12; // ebp
  int v13; // ebx
  int v14; // ecx
  int v15; // ebp
  int *v16; // eax
  int v17; // esi
  int v18; // edx
  int v19; // edi
  int v20; // ecx
  int v21; // edx
  int v22; // esi
  int v23; // ebx
  int v24; // esi
  int v25; // edi
  int v26; // ebx
  int v27; // ebp
  int v28; // ebx
  int v29; // ecx
  int v30; // ecx
  int v31; // [esp+10h] [ebp-18h]
  int v32; // [esp+10h] [ebp-18h]
  int v33; // [esp+10h] [ebp-18h]
  int v34; // [esp+10h] [ebp-18h]
  int v35; // [esp+10h] [ebp-18h]
  int v36; // [esp+10h] [ebp-18h]
  int v37; // [esp+14h] [ebp-14h]
  int v38; // [esp+14h] [ebp-14h]
  int v39; // [esp+14h] [ebp-14h]
  int v40; // [esp+14h] [ebp-14h]
  int v41; // [esp+14h] [ebp-14h]
  int v42; // [esp+14h] [ebp-14h]
  int v43; // [esp+18h] [ebp-10h]
  int v44; // [esp+18h] [ebp-10h]
  int v45; // [esp+1Ch] [ebp-Ch]
  int v46; // [esp+1Ch] [ebp-Ch]
  int v47; // [esp+24h] [ebp-4h]
  int v48; // [esp+24h] [ebp-4h]

  v43 = 7;
  v1 = a1 + 2;
  do
  {
    v2 = v1[5];
    v3 = *(v1 - 2);
    v4 = v1[4];
    v5 = v3 + v2;
    v6 = v3 - v2;
    v7 = *(v1 - 1);
    v45 = v7 + v4;
    v8 = v1[3];
    v9 = v7 - v4;
    v37 = v8 + *v1;
    v10 = *v1 - v8;
    v11 = v1[1];
    v31 = v11 + v1[2];
    v12 = v5 + v31;
    v13 = v11 - v1[2];
    v47 = v5 - v31;
    v32 = v45 + v37;
    v38 = v45 - v37;
    *(v1 - 2) = 4 * (v12 + v32);
    v1[2] = 4 * (v12 - v32);
    v14 = 4433 * (v47 + v38);
    *v1 = (v14 + 6270 * v47 + 1024) >> 11;
    v1[4] = (v14 - 15137 * v38 + 1024) >> 11;
    v39 = 9633 * (v13 + v9 + v10 + v6);
    v33 = v39 - 16069 * (v13 + v9);
    v15 = v39 - 3196 * (v10 + v6);
    v1[5] = (v33 + 2446 * v13 - 7373 * (v13 + v6) + 1024) >> 11;
    v1[3] = (v15 + 16819 * v10 - 20995 * (v10 + v9) + 1024) >> 11;
    v1[1] = (v33 + 25172 * v9 - 20995 * (v10 + v9) + 1024) >> 11;
    *(v1 - 1) = (v15 + 12299 * v6 - 7373 * (v13 + v6) + 1024) >> 11;
    v1 += 8;
    --v43;
  }
  while ( v43 >= 0 );
  v44 = 7;
  v16 = a1 + 16;
  do
  {
    v17 = v16[40];
    v18 = *(v16 - 16);
    v19 = v16[32];
    v20 = v18 + v17;
    v21 = v18 - v17;
    v22 = *(v16 - 8);
    v46 = v22 + v19;
    v23 = v16[24];
    v24 = v22 - v19;
    v40 = v23 + *v16;
    v25 = *v16 - v23;
    v26 = v16[8];
    v34 = v26 + v16[16];
    v27 = v20 + v34;
    v28 = v26 - v16[16];
    v48 = v20 - v34;
    v35 = v46 + v40;
    v41 = v46 - v40;
    *(v16 - 16) = (v27 + v35 + 2) >> 2;
    v16[16] = (v27 - v35 + 2) >> 2;
    v29 = 4433 * (v48 + v41);
    *v16 = (v29 + 6270 * v48 + 0x4000) >> 15;
    v16[32] = (v29 - 15137 * v41 + 0x4000) >> 15;
    v42 = 9633 * (v28 + v24 + v25 + v21);
    v36 = v42 - 16069 * (v28 + v24);
    v30 = v42 - 3196 * (v25 + v21);
    v16[40] = (v36 + 2446 * v28 - 7373 * (v28 + v21) + 0x4000) >> 15;
    v16[24] = (v30 + 16819 * v25 - 20995 * (v25 + v24) + 0x4000) >> 15;
    v16[8] = (v36 + 25172 * v24 - 20995 * (v25 + v24) + 0x4000) >> 15;
    *(v16 - 8) = (v30 + 12299 * v21 - 7373 * (v28 + v21) + 0x4000) >> 15;
    ++v16;
    --v44;
  }
  while ( v44 >= 0 );
}

//------------------------------------------------------------------------------
// Address: 0x101AFC50
// Name: void jpeg_fdct_ifast(int __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_fdct_ifast(int *a1)
{
  int *v1; // eax
  int v2; // ecx
  int v3; // edi
  int v4; // esi
  int v5; // edx
  int v6; // edi
  int v7; // ecx
  int v8; // ebx
  int v9; // ebp
  int v10; // ecx
  int v11; // esi
  int v12; // ecx
  int v13; // edx
  int v14; // ecx
  int v15; // ecx
  int v16; // esi
  int v17; // edx
  int v18; // ecx
  int v19; // ebx
  int v20; // edi
  int v21; // ecx
  int v22; // edi
  int v23; // edx
  int v24; // ecx
  int v25; // edi
  int v26; // ebx
  int v27; // esi
  int v28; // edx
  int v29; // edi
  int v30; // ecx
  int v31; // ebx
  int v32; // ebp
  int v33; // ecx
  int v34; // ecx
  int v35; // esi
  int v36; // ecx
  int v37; // edx
  int v38; // ecx
  int v39; // ecx
  int v40; // esi
  int v41; // edx
  int v42; // ecx
  int v43; // ebx
  int v44; // edi
  int v45; // ecx
  int v46; // edi
  int v47; // edx
  int v48; // ecx
  int v49; // ebx
  int v50; // esi
  int v51; // edi
  int v52; // edx
  int v53; // edi
  int v54; // ecx
  int v55; // ebx
  int v56; // ebp
  int v57; // ecx
  int v58; // ecx
  int v59; // esi
  int v60; // ecx
  int v61; // edx
  int v62; // ecx
  int v63; // ecx
  int v64; // esi
  int v65; // edx
  int v66; // ecx
  int v67; // ebx
  int v68; // edi
  int v69; // ecx
  int v70; // edi
  int v71; // edx
  int v72; // ebx
  int v73; // esi
  int v74; // edi
  int v75; // edx
  int v76; // edi
  int v77; // ecx
  int v78; // ebx
  int v79; // ebp
  int v80; // ecx
  int v81; // ecx
  int v82; // ecx
  int v83; // edx
  int v84; // ecx
  int v85; // ecx
  int v86; // edx
  int v87; // esi
  int v88; // ecx
  int v89; // ebx
  int v90; // edi
  int *v91; // eax
  int v92; // ecx
  int v93; // edi
  int v94; // esi
  int v95; // edx
  int v96; // edi
  int v97; // ecx
  int v98; // ebx
  int v99; // ebp
  int v100; // ecx
  int v101; // esi
  int v102; // ecx
  int v103; // edx
  int v104; // ecx
  int v105; // ecx
  int v106; // esi
  int v107; // edx
  int v108; // ecx
  int v109; // ebx
  int v110; // edi
  int v111; // ecx
  int v112; // edi
  int v113; // edx
  int v114; // ecx
  int v115; // edi
  int v116; // ebx
  int v117; // esi
  int v118; // edx
  int v119; // edi
  int v120; // ecx
  int v121; // ebx
  int v122; // ebp
  int v123; // ecx
  int v124; // ecx
  int v125; // esi
  int v126; // ecx
  int v127; // edx
  int v128; // ecx
  int v129; // ecx
  int v130; // esi
  int v131; // edx
  int v132; // ecx
  int v133; // ebx
  int v134; // edi
  int v135; // ecx
  int v136; // edi
  int v137; // edx
  int v138; // ecx
  int v139; // ebx
  int v140; // esi
  int v141; // edi
  int v142; // edx
  int v143; // edi
  int v144; // ecx
  int v145; // ebx
  int v146; // ebp
  int v147; // ecx
  int v148; // ecx
  int v149; // esi
  int v150; // ecx
  int v151; // edx
  int v152; // ecx
  int v153; // ecx
  int v154; // esi
  int v155; // edx
  int v156; // ecx
  int v157; // ebx
  int v158; // edi
  int v159; // ecx
  int v160; // edi
  int v161; // edx
  int v162; // ebx
  int v163; // esi
  int v164; // edi
  int v165; // edx
  int v166; // edi
  int v167; // ecx
  int v168; // ebx
  int v169; // ebp
  int v170; // ecx
  int v171; // ecx
  int v172; // ecx
  int v173; // edx
  int v174; // ecx
  int v175; // ecx
  int v176; // edx
  int v177; // esi
  int v178; // ecx
  int v179; // ebx
  int v180; // edi
  int v181; // [esp+10h] [ebp-14h]
  int v182; // [esp+10h] [ebp-14h]
  int v183; // [esp+10h] [ebp-14h]
  int v184; // [esp+10h] [ebp-14h]
  int v185; // [esp+10h] [ebp-14h]
  int v186; // [esp+10h] [ebp-14h]
  int v187; // [esp+10h] [ebp-14h]
  int v188; // [esp+10h] [ebp-14h]
  int v189; // [esp+14h] [ebp-10h]
  int v190; // [esp+14h] [ebp-10h]
  int v191; // [esp+18h] [ebp-Ch]
  int v192; // [esp+18h] [ebp-Ch]
  int v193; // [esp+18h] [ebp-Ch]
  int v194; // [esp+18h] [ebp-Ch]
  int v195; // [esp+18h] [ebp-Ch]
  int v196; // [esp+18h] [ebp-Ch]
  int v197; // [esp+18h] [ebp-Ch]
  int v198; // [esp+18h] [ebp-Ch]
  int v199; // [esp+1Ch] [ebp-8h]
  int v200; // [esp+1Ch] [ebp-8h]
  int v201; // [esp+1Ch] [ebp-8h]
  int v202; // [esp+1Ch] [ebp-8h]
  int v203; // [esp+1Ch] [ebp-8h]
  int v204; // [esp+1Ch] [ebp-8h]
  int v205; // [esp+1Ch] [ebp-8h]
  int v206; // [esp+1Ch] [ebp-8h]
  int i; // [esp+20h] [ebp-4h]
  int j; // [esp+28h] [ebp+4h]

  v1 = a1 + 2;
  for ( i = 2; i != 0; --i )
  {
    v2 = v1[5];
    v3 = *(v1 - 2);
    v4 = v1[4];
    v5 = v2 + v3;
    v6 = v3 - v2;
    v7 = *(v1 - 1);
    v8 = v7 + v4;
    v9 = v7 - v4;
    v181 = *v1 + v1[3];
    v199 = *v1 - v1[3];
    v10 = v1[1];
    v11 = v10 + v1[2];
    v191 = v10 - v1[2];
    v12 = v11 + v5;
    v13 = v5 - v11;
    *(v1 - 2) = v12 + v8 + v181;
    v1[2] = v12 - (v8 + v181);
    v14 = (181 * (v8 + v13 - v181)) >> 8;
    v1[4] = v13 - v14;
    *v1 = v14 + v13;
    v15 = (98 * (v191 + v199 - (v6 + v9))) >> 8;
    v16 = v15 + ((334 * (v6 + v9)) >> 8);
    v17 = v15 + ((139 * (v191 + v199)) >> 8);
    v18 = (181 * (v199 + v9)) >> 8;
    v19 = v18 + v6;
    v20 = v6 - v18;
    v21 = v20 + v17;
    v22 = v20 - v17;
    v23 = v19 + v16;
    v1[3] = v21;
    v24 = v1[13];
    v1[1] = v22;
    v25 = v1[6];
    v26 = v19 - v16;
    v27 = v1[12];
    *(v1 - 1) = v23;
    v28 = v24 + v25;
    v29 = v25 - v24;
    v30 = v1[7];
    v1[5] = v26;
    v31 = v30 + v27;
    v32 = v30 - v27;
    v33 = v1[8];
    v182 = v33 + v1[11];
    v200 = v33 - v1[11];
    v34 = v1[9];
    v35 = v34 + v1[10];
    v192 = v34 - v1[10];
    v36 = v35 + v28;
    v37 = v28 - v35;
    v1[6] = v36 + v31 + v182;
    v1[10] = v36 - (v31 + v182);
    v38 = (181 * (v31 + v37 - v182)) >> 8;
    v1[8] = v38 + v37;
    v1[12] = v37 - v38;
    v39 = (98 * (v192 + v200 - (v29 + v32))) >> 8;
    v40 = v39 + ((334 * (v29 + v32)) >> 8);
    v41 = v39 + ((139 * (v192 + v200)) >> 8);
    v42 = (181 * (v200 + v32)) >> 8;
    v43 = v42 + v29;
    v44 = v29 - v42;
    v45 = v44 + v41;
    v46 = v44 - v41;
    v47 = v43 + v40;
    v1[11] = v45;
    v48 = v1[21];
    v49 = v43 - v40;
    v50 = v1[20];
    v1[9] = v46;
    v51 = v1[14];
    v1[7] = v47;
    v52 = v48 + v51;
    v53 = v51 - v48;
    v54 = v1[15];
    v1[13] = v49;
    v55 = v54 + v50;
    v56 = v54 - v50;
    v57 = v1[16];
    v183 = v57 + v1[19];
    v201 = v57 - v1[19];
    v58 = v1[17];
    v59 = v58 + v1[18];
    v193 = v58 - v1[18];
    v60 = v59 + v52;
    v61 = v52 - v59;
    v1[14] = v60 + v55 + v183;
    v1[18] = v60 - (v55 + v183);
    v62 = (181 * (v55 + v61 - v183)) >> 8;
    v1[16] = v62 + v61;
    v1[20] = v61 - v62;
    v63 = (98 * (v193 + v201 - (v53 + v56))) >> 8;
    v64 = v63 + ((334 * (v53 + v56)) >> 8);
    v65 = v63 + ((139 * (v193 + v201)) >> 8);
    v66 = (181 * (v201 + v56)) >> 8;
    v67 = v66 + v53;
    v68 = v53 - v66;
    v1[19] = v68 + v65;
    v69 = v1[29];
    v70 = v68 - v65;
    v71 = v67 + v64;
    v72 = v67 - v64;
    v73 = v1[28];
    v1[17] = v70;
    v74 = v1[22];
    v1[15] = v71;
    v75 = v74 + v69;
    v76 = v74 - v69;
    v77 = v1[23];
    v1[21] = v72;
    v78 = v73 + v77;
    v79 = v77 - v73;
    v80 = v1[24];
    v184 = v80 + v1[27];
    v202 = v80 - v1[27];
    v81 = v1[25];
    v189 = v81 + v1[26];
    v194 = v81 - v1[26];
    v82 = v189 + v75;
    v83 = v75 - v189;
    v1[22] = v82 + v78 + v184;
    v1[26] = v82 - (v78 + v184);
    v84 = (181 * (v78 + v83 - v184)) >> 8;
    v1[24] = v84 + v83;
    v1[28] = v83 - v84;
    v85 = (98 * (v194 + v202 - (v76 + v79))) >> 8;
    v86 = v85 + ((139 * (v194 + v202)) >> 8);
    v87 = v85 + ((334 * (v76 + v79)) >> 8);
    v88 = (181 * (v202 + v79)) >> 8;
    v89 = v88 + v76;
    v90 = v76 - v88;
    v1[27] = v90 + v86;
    v1[25] = v90 - v86;
    v1[23] = v89 + v87;
    v1[29] = v89 - v87;
    v1 += 32;
  }
  v91 = a1 + 16;
  for ( j = 2; j != 0; --j )
  {
    v92 = v91[40];
    v93 = *(v91 - 16);
    v94 = v91[32];
    v95 = v92 + v93;
    v96 = v93 - v92;
    v97 = *(v91 - 8);
    v98 = v97 + v94;
    v99 = v97 - v94;
    v185 = *v91 + v91[24];
    v203 = *v91 - v91[24];
    v100 = v91[8];
    v101 = v100 + v91[16];
    v195 = v100 - v91[16];
    v102 = v101 + v95;
    v103 = v95 - v101;
    *(v91 - 16) = v102 + v98 + v185;
    v91[16] = v102 - (v98 + v185);
    v104 = (181 * (v98 + v103 - v185)) >> 8;
    v91[32] = v103 - v104;
    *v91 = v104 + v103;
    v105 = (98 * (v195 + v203 - (v96 + v99))) >> 8;
    v106 = v105 + ((334 * (v96 + v99)) >> 8);
    v107 = v105 + ((139 * (v195 + v203)) >> 8);
    v108 = (181 * (v203 + v99)) >> 8;
    v109 = v108 + v96;
    v110 = v96 - v108;
    v111 = v110 + v107;
    v112 = v110 - v107;
    v113 = v109 + v106;
    v91[24] = v111;
    v114 = v91[41];
    v91[8] = v112;
    v115 = *(v91 - 15);
    v116 = v109 - v106;
    v117 = v91[33];
    *(v91 - 8) = v113;
    v118 = v114 + v115;
    v119 = v115 - v114;
    v120 = *(v91 - 7);
    v91[40] = v116;
    v121 = v120 + v117;
    v122 = v120 - v117;
    v123 = v91[1];
    v186 = v123 + v91[25];
    v204 = v123 - v91[25];
    v124 = v91[9];
    v125 = v124 + v91[17];
    v196 = v124 - v91[17];
    v126 = v125 + v118;
    v127 = v118 - v125;
    *(v91 - 15) = v126 + v121 + v186;
    v91[17] = v126 - (v121 + v186);
    v128 = (181 * (v121 + v127 - v186)) >> 8;
    v91[1] = v128 + v127;
    v91[33] = v127 - v128;
    v129 = (98 * (v196 + v204 - (v119 + v122))) >> 8;
    v130 = v129 + ((334 * (v119 + v122)) >> 8);
    v131 = v129 + ((139 * (v196 + v204)) >> 8);
    v132 = (181 * (v204 + v122)) >> 8;
    v133 = v132 + v119;
    v134 = v119 - v132;
    v135 = v134 + v131;
    v136 = v134 - v131;
    v137 = v133 + v130;
    v91[25] = v135;
    v138 = v91[42];
    v139 = v133 - v130;
    v140 = v91[34];
    v91[9] = v136;
    v141 = *(v91 - 14);
    *(v91 - 7) = v137;
    v142 = v138 + v141;
    v143 = v141 - v138;
    v144 = *(v91 - 6);
    v91[41] = v139;
    v145 = v144 + v140;
    v146 = v144 - v140;
    v147 = v91[2];
    v187 = v147 + v91[26];
    v205 = v147 - v91[26];
    v148 = v91[10];
    v149 = v148 + v91[18];
    v197 = v148 - v91[18];
    v150 = v149 + v142;
    v151 = v142 - v149;
    *(v91 - 14) = v150 + v145 + v187;
    v91[18] = v150 - (v145 + v187);
    v152 = (181 * (v145 + v151 - v187)) >> 8;
    v91[2] = v152 + v151;
    v91[34] = v151 - v152;
    v153 = (98 * (v197 + v205 - (v143 + v146))) >> 8;
    v154 = v153 + ((334 * (v143 + v146)) >> 8);
    v155 = v153 + ((139 * (v197 + v205)) >> 8);
    v156 = (181 * (v205 + v146)) >> 8;
    v157 = v156 + v143;
    v158 = v143 - v156;
    v91[26] = v158 + v155;
    v159 = v91[43];
    v160 = v158 - v155;
    v161 = v157 + v154;
    v162 = v157 - v154;
    v163 = v91[35];
    v91[10] = v160;
    v164 = *(v91 - 13);
    *(v91 - 6) = v161;
    v165 = v164 + v159;
    v166 = v164 - v159;
    v167 = *(v91 - 5);
    v91[42] = v162;
    v168 = v163 + v167;
    v169 = v167 - v163;
    v170 = v91[3];
    v188 = v170 + v91[27];
    v206 = v170 - v91[27];
    v171 = v91[11];
    v190 = v171 + v91[19];
    v198 = v171 - v91[19];
    v172 = v190 + v165;
    v173 = v165 - v190;
    *(v91 - 13) = v172 + v168 + v188;
    v91[19] = v172 - (v168 + v188);
    v174 = (181 * (v168 + v173 - v188)) >> 8;
    v91[3] = v174 + v173;
    v91[35] = v173 - v174;
    v175 = (98 * (v198 + v206 - (v166 + v169))) >> 8;
    v176 = v175 + ((139 * (v198 + v206)) >> 8);
    v177 = v175 + ((334 * (v166 + v169)) >> 8);
    v178 = (181 * (v206 + v169)) >> 8;
    v179 = v178 + v166;
    v180 = v166 - v178;
    v91[27] = v180 + v176;
    v91[11] = v180 - v176;
    *(v91 - 5) = v179 + v177;
    v91[43] = v179 - v177;
    v91 += 4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B0320
// Name: void jpeg_fdct_float(float __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl jpeg_fdct_float(float *a1)
{
  int v2; // ecx
  float *v3; // eax
  double v4; // st6
  double v5; // st5
  double v6; // st6
  double v7; // st4
  double v8; // st3
  double v9; // st2
  double v10; // st3
  int v11; // ecx
  float *v12; // eax
  double v13; // st6
  double v14; // st5
  double v15; // st6
  double v16; // st4
  double v17; // st3
  double v18; // st2
  double v19; // st3
  float v20; // [esp+0h] [ebp-1Ch]
  float v21; // [esp+0h] [ebp-1Ch]
  float v22; // [esp+0h] [ebp-1Ch]
  float v23; // [esp+0h] [ebp-1Ch]
  float v24; // [esp+4h] [ebp-18h]
  float v25; // [esp+4h] [ebp-18h]
  float v26; // [esp+8h] [ebp-14h]
  float v27; // [esp+8h] [ebp-14h]
  float v28; // [esp+8h] [ebp-14h]
  float v29; // [esp+8h] [ebp-14h]
  float v30; // [esp+Ch] [ebp-10h]
  float v31; // [esp+Ch] [ebp-10h]
  float v32; // [esp+10h] [ebp-Ch]
  float v33; // [esp+10h] [ebp-Ch]
  float v34; // [esp+10h] [ebp-Ch]
  float v35; // [esp+10h] [ebp-Ch]
  float v36; // [esp+14h] [ebp-8h]
  float v37; // [esp+14h] [ebp-8h]
  float v38; // [esp+14h] [ebp-8h]
  float v39; // [esp+14h] [ebp-8h]
  float v40; // [esp+18h] [ebp-4h]
  float v41; // [esp+18h] [ebp-4h]
  float v42; // [esp+18h] [ebp-4h]
  float v43; // [esp+18h] [ebp-4h]
  float v44; // [esp+18h] [ebp-4h]
  float v45; // [esp+18h] [ebp-4h]
  float v46; // [esp+20h] [ebp+4h]
  float v47; // [esp+20h] [ebp+4h]
  float v48; // [esp+20h] [ebp+4h]
  float v49; // [esp+20h] [ebp+4h]
  float v50; // [esp+20h] [ebp+4h]
  float v51; // [esp+20h] [ebp+4h]
  float v52; // [esp+20h] [ebp+4h]
  float v53; // [esp+20h] [ebp+4h]
  float v54; // [esp+20h] [ebp+4h]
  float v55; // [esp+20h] [ebp+4h]
  float v56; // [esp+20h] [ebp+4h]
  float v57; // [esp+20h] [ebp+4h]
  float v58; // [esp+20h] [ebp+4h]
  float v59; // [esp+20h] [ebp+4h]
  float v60; // [esp+20h] [ebp+4h]
  float v61; // [esp+20h] [ebp+4h]
  float v62; // [esp+20h] [ebp+4h]
  float v63; // [esp+20h] [ebp+4h]

  v2 = 7;
  v3 = a1 + 2;
  do
  {
    v20 = *(v3 - 2) + v3[5];
    v40 = *(v3 - 2) - v3[5];
    v26 = v3[4] + *(v3 - 1);
    v36 = *(v3 - 1) - v3[4];
    v24 = v3[3] + *v3;
    v32 = *v3 - v3[3];
    v46 = v3[1] + v3[2];
    v30 = v3[1] - v3[2];
    v4 = v46;
    v47 = v46 + v20;
    v21 = v20 - v4;
    v5 = v26;
    v27 = v24 + v26;
    *(v3 - 2) = v27 + v47;
    v3[2] = v47 - v27;
    v48 = v5 - v24;
    v49 = (v48 + v21) * 0.7071067690849304;
    *v3 = v49 + v21;
    v3[4] = v21 - v49;
    v6 = v32;
    v50 = v30 + v32;
    v7 = v40;
    v41 = v36 + v40;
    v8 = v50;
    v3 += 8;
    --v2;
    v51 = (v50 - v41) * 0.3826834261417389;
    v9 = v8;
    v10 = v41;
    v42 = v9 * 0.5411961078643799 + v51;
    v33 = v51 + v10 * 1.306563019752502;
    v52 = v36 + v6;
    v53 = v52 * 0.7071067690849304;
    v37 = v53 + v7;
    v54 = v7 - v53;
    *(v3 - 5) = v54 + v42;
    *(v3 - 7) = v54 - v42;
    *(v3 - 9) = v37 + v33;
    *(v3 - 3) = v37 - v33;
  }
  while ( v2 >= 0 );
  v11 = 7;
  v12 = a1 + 16;
  do
  {
    v22 = *(v12 - 16) + v12[40];
    v43 = *(v12 - 16) - v12[40];
    v28 = v12[32] + *(v12 - 8);
    v38 = *(v12 - 8) - v12[32];
    v25 = v12[24] + *v12;
    v34 = *v12 - v12[24];
    v55 = v12[16] + v12[8];
    v31 = v12[8] - v12[16];
    v13 = v55;
    v56 = v55 + v22;
    v23 = v22 - v13;
    v14 = v28;
    v29 = v25 + v28;
    *(v12 - 16) = v29 + v56;
    v12[16] = v56 - v29;
    v57 = v14 - v25;
    v58 = (v57 + v23) * 0.7071067690849304;
    *v12 = v58 + v23;
    v12[32] = v23 - v58;
    v15 = v34;
    v59 = v31 + v34;
    v16 = v43;
    v44 = v38 + v43;
    v17 = v59;
    ++v12;
    --v11;
    v60 = (v59 - v44) * 0.3826834261417389;
    v18 = v17;
    v19 = v44;
    v45 = v18 * 0.5411961078643799 + v60;
    v35 = v60 + v19 * 1.306563019752502;
    v61 = v38 + v15;
    v62 = v61 * 0.7071067690849304;
    v39 = v62 + v16;
    v63 = v16 - v62;
    v12[23] = v63 + v45;
    v12[7] = v63 - v45;
    *(v12 - 9) = v39 + v35;
    v12[39] = v39 - v35;
  }
  while ( v11 >= 0 );
}

//------------------------------------------------------------------------------
// Address: 0x101B0650
// Name: _inflateReset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflateReset(_DWORD *a1)
{
  _DWORD *v1; // eax

  if ( a1 == nullptr )
    return -2;
  v1 = (_DWORD *)a1[7];
  if ( v1 == nullptr )
    return -2;
  v1[7] = 0;
  a1[5] = 0;
  a1[2] = 0;
  a1[6] = 0;
  a1[12] = 1;
  *v1 = 0;
  v1[1] = 0;
  v1[3] = 0;
  v1[8] = 0;
  v1[10] = 0;
  v1[11] = 0;
  v1[12] = 0;
  v1[14] = 0;
  v1[15] = 0;
  v1[5] = 0x8000;
  v1[27] = v1 + 332;
  v1[20] = v1 + 332;
  v1[19] = v1 + 332;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B06B0
// Name: _inflateInit2_
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflateInit2_(_DWORD *a1, int a2, _BYTE *a3, int a4)
{
  bool v4; // zf
  _DWORD *v5; // eax
  int v7; // ecx

  if ( a3 == nullptr || *a3 != 49 || a4 != 56 )
    return -6;
  if ( a1 != nullptr )
  {
    v4 = a1[8] == 0;
    a1[6] = 0;
    if ( v4 )
    {
      a1[8] = zcalloc;
      a1[10] = 0;
    }
    if ( a1[9] == 0 )
      a1[9] = jpeg_free_small;
    v5 = (_DWORD *)((int (__cdecl *)(_DWORD, int, int))a1[8])(a1: a1[10], a2: 1, a3: 9520);
    if ( v5 == nullptr )
      return -4;
    v7 = a2;
    a1[7] = v5;
    if ( a2 >= 0 )
    {
      v5[2] = (a2 >> 4) + 1;
      if ( a2 < 48 )
        v7 = a2 & 0xF;
    }
    else
    {
      v5[2] = 0;
      v7 = -a2;
    }
    if ( (unsigned int)(v7 - 8) <= 7 )
    {
      v5[9] = v7;
      v5[13] = 0;
      return inflateReset(a1);
    }
    ((void (__cdecl *)(_DWORD, _DWORD *))a1[9])(a1: a1[10], a2: v5);
    a1[7] = 0;
  }
  return -2;
}

//------------------------------------------------------------------------------
// Address: 0x101B0780
// Name: _inflateInit_
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflateInit_(_DWORD *a1, _BYTE *a2, int a3)
{
  return inflateInit2_(a1, a2: 15, a3: a2, a4: a3);
}

//------------------------------------------------------------------------------
// Address: 0x101B07A0
// Name: sub_101B07A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__usercall sub_101B07A0@<eax>(_DWORD *result@<eax>)
{
  result[19] = &unk_102ACDA0;
  result[21] = 9;
  result[20] = &unk_102AD5A0;
  result[22] = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B07C0
// Name: sub_101B07C0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_101B07C0@<eax>(int a1@<eax>, int a2@<ebx>)
{
  int v2; // esi
  int v4; // eax
  int v6; // ecx
  unsigned int v7; // edi
  unsigned int v8; // eax
  int v9; // eax
  unsigned int v10; // ebp
  unsigned int v11; // edi
  int v12; // edx
  unsigned int v13; // eax
  unsigned int v14; // ecx

  v2 = *(_DWORD *)(a2 + 28);
  if ( *(_DWORD *)(v2 + 52) == 0 )
  {
    v4 = (*(int (__cdecl **)(_DWORD, int, int))(a2 + 32))(
           a1: *(_DWORD *)(a2 + 40),
           a2: 1 << *(_DWORD *)(v2 + 36),
           a3: 1);
    *(_DWORD *)(v2 + 52) = v4;
    if ( v4 == 0 )
      return 1;
  }
  if ( *(_DWORD *)(v2 + 40) == 0 )
  {
    v6 = *(_DWORD *)(v2 + 36);
    *(_DWORD *)(v2 + 48) = 0;
    *(_DWORD *)(v2 + 44) = 0;
    *(_DWORD *)(v2 + 40) = 1 << v6;
  }
  v7 = a1 - *(_DWORD *)(a2 + 16);
  v8 = *(_DWORD *)(v2 + 40);
  if ( v7 < v8 )
  {
    v10 = v8 - *(_DWORD *)(v2 + 48);
    if ( v10 > v7 )
      v10 = v7;
    memcpy(
      dst: (unsigned __int8 *)(*(_DWORD *)(v2 + 48) + *(_DWORD *)(v2 + 52)),
      src: (unsigned __int8 *)(*(_DWORD *)(a2 + 12) - v7),
      count: v10);
    v11 = v7 - v10;
    if ( v11 != 0 )
    {
      memcpy(dst: *(unsigned __int8 **)(v2 + 52), src: (unsigned __int8 *)(*(_DWORD *)(a2 + 12) - v11), count: v11);
      v12 = *(_DWORD *)(v2 + 40);
      *(_DWORD *)(v2 + 48) = v11;
      *(_DWORD *)(v2 + 44) = v12;
      return 0;
    }
    else
    {
      *(_DWORD *)(v2 + 48) += v10;
      v13 = *(_DWORD *)(v2 + 40);
      if ( *(_DWORD *)(v2 + 48) == v13 )
        *(_DWORD *)(v2 + 48) = 0;
      v14 = *(_DWORD *)(v2 + 44);
      if ( v14 < v13 )
        *(_DWORD *)(v2 + 44) = v10 + v14;
      return 0;
    }
  }
  else
  {
    memcpy(
      dst: *(unsigned __int8 **)(v2 + 52),
      src: (unsigned __int8 *)(*(_DWORD *)(a2 + 12) - v8),
      count: *(_DWORD *)(v2 + 40));
    v9 = *(_DWORD *)(v2 + 40);
    *(_DWORD *)(v2 + 48) = 0;
    *(_DWORD *)(v2 + 44) = v9;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B08B0
// Name: _inflate
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate(int a1, int a2)
{
  int *v2; // edi
  unsigned int v3; // edx
  unsigned int v4; // ebx
  unsigned __int8 *v5; // ebp
  int v6; // eax
  unsigned int v7; // esi
  int v8; // eax
  int v9; // eax
  int v10; // eax
  unsigned int v11; // ecx
  int v12; // eax
  int v13; // eax
  _DWORD *v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  unsigned int v26; // eax
  int v27; // ecx
  unsigned int v28; // edx
  int v29; // eax
  unsigned int v30; // eax
  int v31; // ecx
  int v32; // eax
  unsigned int v33; // ecx
  int v34; // eax
  int v35; // eax
  unsigned int v36; // eax
  int v37; // ecx
  int v38; // eax
  unsigned int v39; // ecx
  int v40; // eax
  int v41; // eax
  int v42; // eax
  int v43; // eax
  int v44; // eax
  int v45; // eax
  unsigned __int16 v46; // ax
  int v47; // eax
  int v48; // eax
  int v49; // ecx
  int v50; // eax
  char v51; // cl
  unsigned int v52; // ebx
  unsigned int v53; // esi
  int v54; // ecx
  int v55; // eax
  int v56; // eax
  unsigned int v57; // eax
  int v58; // eax
  int v59; // ecx
  unsigned int v60; // ebx
  char v61; // al
  unsigned int v62; // eax
  int v63; // ecx
  bool v64; // cc
  int v65; // eax
  int v66; // eax
  unsigned int v67; // eax
  int v68; // eax
  int v69; // ecx
  int v70; // eax
  int v71; // eax
  int v72; // ecx
  int v73; // eax
  int v74; // ecx
  int v75; // eax
  unsigned int v76; // ebx
  int v77; // eax
  int v78; // eax
  unsigned int v79; // ebx
  __int16 v80; // ax
  int v81; // ecx
  int v82; // eax
  unsigned __int8 *v83; // ecx
  int v84; // edx
  unsigned int v85; // eax
  unsigned int v86; // eax
  int v87; // eax
  int v88; // eax
  unsigned int v89; // eax
  int v90; // eax
  int v91; // ecx
  unsigned int v92; // eax
  int v93; // eax
  int v94; // eax
  unsigned int v95; // eax
  int v96; // eax
  int v97; // ecx
  unsigned int v98; // eax
  unsigned int v99; // eax
  unsigned int v100; // ecx
  int v101; // ecx
  unsigned __int8 *v102; // ecx
  unsigned int v103; // ecx
  unsigned __int8 *v104; // eax
  unsigned __int8 v105; // cl
  bool v106; // zf
  unsigned __int8 *v107; // eax
  int v108; // eax
  int v109; // eax
  int v110; // eax
  int v111; // eax
  unsigned __int16 v112; // cx
  int v113; // eax
  int result; // eax
  unsigned int v115; // ebp
  int v116; // ebx
  int v117; // eax
  int v118; // [esp-1Ch] [ebp-4Ch]
  int v119; // [esp-18h] [ebp-48h]
  unsigned __int8 *v120; // [esp-14h] [ebp-44h]
  unsigned int v121; // [esp+4h] [ebp-2Ch]
  unsigned int count; // [esp+8h] [ebp-28h]
  unsigned int counta; // [esp+8h] [ebp-28h]
  unsigned int countb; // [esp+8h] [ebp-28h]
  unsigned int countc; // [esp+8h] [ebp-28h]
  unsigned int countd; // [esp+8h] [ebp-28h]
  unsigned int counte; // [esp+8h] [ebp-28h]
  unsigned int countf; // [esp+8h] [ebp-28h]
  unsigned int countg; // [esp+8h] [ebp-28h]
  unsigned int counth; // [esp+8h] [ebp-28h]
  unsigned int counti; // [esp+8h] [ebp-28h]
  unsigned int countj; // [esp+8h] [ebp-28h]
  unsigned int v133; // [esp+Ch] [ebp-24h]
  unsigned int v134; // [esp+Ch] [ebp-24h]
  char i; // [esp+Eh] [ebp-22h]
  unsigned int v136; // [esp+10h] [ebp-20h]
  unsigned int v137; // [esp+14h] [ebp-1Ch] BYREF
  int v138; // [esp+18h] [ebp-18h]
  unsigned __int8 *dst; // [esp+1Ch] [ebp-14h]
  int v140; // [esp+20h] [ebp-10h]
  int v141; // [esp+24h] [ebp-Ch]
  unsigned int v142; // [esp+28h] [ebp-8h]
  unsigned int v143; // [esp+2Ch] [ebp-4h]

  if ( a1 == 0 )
    return -2;
  v2 = *(int **)(a1 + 28);
  if ( v2 == nullptr || *(_DWORD *)(a1 + 12) == 0 || *(_DWORD *)a1 == 0 && *(_DWORD *)(a1 + 4) != 0 )
    return -2;
  if ( *v2 == 11 )
    *v2 = 12;
  v3 = *(_DWORD *)(a1 + 4);
  v4 = v2[14];
  v5 = *(unsigned __int8 **)a1;
  dst = *(unsigned __int8 **)(a1 + 12);
  v6 = *v2;
  v7 = v2[15];
  v136 = *(_DWORD *)(a1 + 16);
  v121 = v3;
  i = BYTE2(v4);
  v143 = v3;
  v140 = v136;
  v141 = 0;
  while ( 2 )
  {
    switch ( v6 )
    {
      case 0:
        if ( v2[2] == 0 )
        {
          *v2 = 12;
          goto LABEL_293;
        }
        for ( ; v7 < 0x10; i = BYTE2(v4) )
        {
          if ( v3 == 0 )
            goto LABEL_301;
          v8 = *v5 << v7;
          --v3;
          v7 += 8;
          ++v5;
          v4 += v8;
          v121 = v3;
        }
        if ( (v2[2] & 2) != 0 && v4 == 35615 )
        {
          v2[6] = crc32(a1: 0, a2: 0, a3: 0);
          LOWORD(v137) = -29921;
          v9 = crc32(a1: v2[6], a2: &v137, a3: 2);
          v3 = v121;
          v4 = 0;
          v2[6] = v9;
          i = 0;
          v7 = 0;
          *v2 = 1;
          goto LABEL_293;
        }
        v10 = v2[8];
        v2[4] = 0;
        if ( v10 != 0 )
          *(_DWORD *)(v10 + 48) = -1;
        if ( (v2[2] & 1) == 0 || ((v4 >> 8) + ((unsigned __int8)v4 << 8)) % 0x1F != 0 )
        {
          *(_DWORD *)(a1 + 24) = "incorrect header check";
          v3 = v121;
          goto LABEL_292;
        }
        if ( (v4 & 0xF) != 8 )
        {
          v3 = v121;
          *(_DWORD *)(a1 + 24) = "unknown compression method";
          goto LABEL_292;
        }
        v4 >>= 4;
        v11 = (v4 & 0xF) + 8;
        v7 -= 4;
        i = BYTE2(v4);
        if ( v11 > v2[9] )
        {
          v3 = v121;
          *(_DWORD *)(a1 + 24) = "invalid window size";
          goto LABEL_292;
        }
        v2[5] = 1 << v11;
        v12 = adler32(a1: 0, a2: 0, a3: 0);
        v3 = v121;
        v2[6] = v12;
        *(_DWORD *)(a1 + 48) = v12;
        *v2 = ~BYTE1(v4) & 2 | 9;
        v4 = 0;
        i = 0;
        v7 = 0;
        goto LABEL_293;
      case 1:
        for ( ; v7 < 0x10; i = BYTE2(v4) )
        {
          if ( v3 == 0 )
            goto LABEL_301;
          v13 = *v5 << v7;
          --v3;
          v7 += 8;
          ++v5;
          v4 += v13;
          v121 = v3;
        }
        v2[4] = v4;
        if ( (_BYTE)v4 != 8 )
        {
          *(_DWORD *)(a1 + 24) = "unknown compression method";
          goto LABEL_292;
        }
        if ( (v4 & 0xE000) != 0 )
        {
          *(_DWORD *)(a1 + 24) = "unknown header flags set";
          goto LABEL_292;
        }
        v14 = (_DWORD *)v2[8];
        if ( v14 != nullptr )
          *v14 = (v4 & 0x100) != 0;
        if ( (v2[4] & 0x200) != 0 )
        {
          LOBYTE(v137) = 8;
          BYTE1(v137) = BYTE1(v4);
          v15 = crc32(a1: v2[6], a2: &v137, a3: 2);
          v3 = v121;
          v2[6] = v15;
        }
        v4 = 0;
        v7 = 0;
        *v2 = 2;
        do
        {
LABEL_41:
          if ( v3 == 0 )
            goto LABEL_301;
          v16 = *v5 << v7;
          --v3;
          v7 += 8;
          ++v5;
          v4 += v16;
          v121 = v3;
        }
        while ( v7 < 0x20 );
LABEL_43:
        v17 = v2[8];
        if ( v17 != 0 )
          *(_DWORD *)(v17 + 4) = v4;
        if ( (v2[4] & 0x200) != 0 )
        {
          v137 = v4;
          v18 = crc32(a1: v2[6], a2: &v137, a3: 4);
          v3 = v121;
          v2[6] = v18;
        }
        v4 = 0;
        v7 = 0;
        *v2 = 3;
        do
        {
LABEL_49:
          if ( v3 == 0 )
            goto LABEL_301;
          v19 = *v5 << v7;
          --v3;
          v7 += 8;
          ++v5;
          v4 += v19;
          v121 = v3;
        }
        while ( v7 < 0x10 );
LABEL_51:
        v20 = v2[8];
        if ( v20 != 0 )
        {
          *(_DWORD *)(v20 + 8) = (unsigned __int8)v4;
          *(_DWORD *)(v2[8] + 12) = v4 >> 8;
        }
        if ( (v2[4] & 0x200) != 0 )
        {
          LOWORD(v137) = v4;
          v21 = crc32(a1: v2[6], a2: &v137, a3: 2);
          v3 = v121;
          v2[6] = v21;
        }
        v4 = 0;
        i = 0;
        v7 = 0;
        *v2 = 4;
LABEL_56:
        if ( (v2[4] & 0x400) != 0 )
        {
          if ( v7 < 0x10 )
          {
            while ( v3 != 0 )
            {
              v22 = *v5 << v7;
              --v3;
              v7 += 8;
              ++v5;
              v4 += v22;
              v121 = v3;
              if ( v7 >= 0x10 )
                goto LABEL_60;
            }
            goto LABEL_301;
          }
LABEL_60:
          v23 = v2[8];
          v2[16] = v4;
          if ( v23 != 0 )
            *(_DWORD *)(v23 + 20) = v4;
          if ( (v2[4] & 0x200) != 0 )
          {
            LOWORD(v137) = v4;
            v24 = crc32(a1: v2[6], a2: &v137, a3: 2);
            v3 = v121;
            v2[6] = v24;
          }
          v4 = 0;
          i = 0;
          v7 = 0;
        }
        else
        {
          v25 = v2[8];
          if ( v25 != 0 )
            *(_DWORD *)(v25 + 16) = 0;
        }
        *v2 = 5;
LABEL_68:
        if ( (v2[4] & 0x400) != 0 )
        {
          v26 = v2[16];
          count = v26;
          if ( v26 > v3 )
          {
            v26 = v3;
            count = v3;
          }
          if ( v26 != 0 )
          {
            v27 = v2[8];
            if ( v27 != 0 )
            {
              v142 = *(_DWORD *)(v27 + 16);
              if ( v142 != 0 )
              {
                v28 = *(_DWORD *)(v2[8] + 24);
                v138 = *(_DWORD *)(v2[8] + 20) - v2[16];
                if ( v26 + v138 > v28 )
                  v26 = v28 - v138;
                memcpy(dst: (unsigned __int8 *)(v138 + v142), src: v5, count: v26);
                v26 = count;
                v3 = v121;
              }
            }
            if ( (v2[4] & 0x200) != 0 )
            {
              v29 = crc32(a1: v2[6], a2: v5, a3: count);
              v3 = v121;
              v2[6] = v29;
              v26 = count;
            }
            v3 -= v26;
            v5 += v26;
            v2[16] -= v26;
            v121 = v3;
          }
          if ( v2[16] != 0 )
            goto LABEL_301;
        }
        v2[16] = 0;
        *v2 = 6;
LABEL_82:
        if ( (v2[4] & 0x800) != 0 )
        {
          if ( v3 == 0 )
            goto LABEL_301;
          v30 = 0;
          do
          {
            v31 = v5[v30];
            counta = v30 + 1;
            v32 = v2[8];
            v138 = v31;
            if ( v32 != 0 )
            {
              v142 = *(_DWORD *)(v32 + 28);
              if ( v142 != 0 )
              {
                v33 = v2[16];
                if ( v33 < *(_DWORD *)(v32 + 32) )
                {
                  *(_BYTE *)(v142 + v33) = v138;
                  ++v2[16];
                  v3 = v121;
                }
              }
            }
            if ( v138 == 0 )
              break;
            v30 = counta;
          }
          while ( counta < v3 );
          if ( (v2[4] & 0x200) != 0 )
          {
            v34 = crc32(a1: v2[6], a2: v5, a3: counta);
            v3 = v121;
            v2[6] = v34;
          }
          v3 -= counta;
          v5 += counta;
          v121 = v3;
          if ( v138 != 0 )
            goto LABEL_301;
        }
        else
        {
          v35 = v2[8];
          if ( v35 != 0 )
            *(_DWORD *)(v35 + 28) = 0;
        }
        v2[16] = 0;
        *v2 = 7;
LABEL_98:
        if ( (v2[4] & 0x1000) != 0 )
        {
          if ( v3 == 0 )
            goto LABEL_301;
          v36 = 0;
          do
          {
            v37 = v5[v36];
            countb = v36 + 1;
            v38 = v2[8];
            v138 = v37;
            if ( v38 != 0 )
            {
              v142 = *(_DWORD *)(v38 + 36);
              if ( v142 != 0 )
              {
                v39 = v2[16];
                if ( v39 < *(_DWORD *)(v38 + 40) )
                {
                  *(_BYTE *)(v142 + v39) = v138;
                  ++v2[16];
                  v3 = v121;
                }
              }
            }
            if ( v138 == 0 )
              break;
            v36 = countb;
          }
          while ( countb < v3 );
          if ( (v2[4] & 0x200) != 0 )
          {
            v40 = crc32(a1: v2[6], a2: v5, a3: countb);
            v3 = v121;
            v2[6] = v40;
          }
          v3 -= countb;
          v5 += countb;
          v121 = v3;
          if ( v138 != 0 )
            goto LABEL_301;
        }
        else
        {
          v41 = v2[8];
          if ( v41 != 0 )
            *(_DWORD *)(v41 + 36) = 0;
        }
        *v2 = 8;
LABEL_114:
        if ( (v2[4] & 0x200) != 0 )
        {
          if ( v7 < 0x10 )
          {
            while ( v3 != 0 )
            {
              v42 = *v5 << v7;
              --v3;
              v7 += 8;
              ++v5;
              v4 += v42;
              v121 = v3;
              i = BYTE2(v4);
              if ( v7 >= 0x10 )
                goto LABEL_118;
            }
            goto LABEL_301;
          }
LABEL_118:
          if ( v4 != *((unsigned __int16 *)v2 + 12) )
          {
            *(_DWORD *)(a1 + 24) = "header crc mismatch";
            goto LABEL_292;
          }
          v4 = 0;
          i = 0;
          v7 = 0;
        }
        v43 = v2[8];
        if ( v43 != 0 )
        {
          *(_DWORD *)(v43 + 44) = (v2[4] >> 9) & 1;
          *(_DWORD *)(v2[8] + 48) = 1;
        }
        v44 = crc32(a1: 0, a2: 0, a3: 0);
        v3 = v121;
        v2[6] = v44;
        *(_DWORD *)(a1 + 48) = v44;
        *v2 = 11;
        goto LABEL_293;
      case 2:
        if ( v7 < 0x20 )
          goto LABEL_41;
        goto LABEL_43;
      case 3:
        if ( v7 < 0x10 )
          goto LABEL_49;
        goto LABEL_51;
      case 4:
        goto LABEL_56;
      case 5:
        goto LABEL_68;
      case 6:
        goto LABEL_82;
      case 7:
        goto LABEL_98;
      case 8:
        goto LABEL_114;
      case 9:
        for ( ; v7 < 0x20; i = BYTE2(v4) )
        {
          if ( v3 == 0 )
            goto LABEL_301;
          v45 = *v5 << v7;
          --v3;
          v7 += 8;
          ++v5;
          v4 += v45;
          v121 = v3;
        }
        LOBYTE(v46) = 0;
        HIBYTE(v46) = i;
        v47 = v46 + (((v4 << 16) + (v4 & 0xFF00)) << 8) + HIBYTE(v4);
        v2[6] = v47;
        *(_DWORD *)(a1 + 48) = v47;
        v4 = 0;
        v7 = 0;
        *v2 = 10;
LABEL_128:
        if ( v2[3] == 0 )
        {
          *(_DWORD *)(a1 + 12) = dst;
          *(_DWORD *)a1 = v5;
          *(_DWORD *)(a1 + 16) = v136;
          *(_DWORD *)(a1 + 4) = v3;
          v2[15] = v7;
          v2[14] = v4;
          return 2;
        }
        v48 = adler32(a1: 0, a2: 0, a3: 0);
        v2[6] = v48;
        *(_DWORD *)(a1 + 48) = v48;
        v3 = v121;
        *v2 = 11;
LABEL_130:
        if ( a2 == 5 )
          goto LABEL_301;
LABEL_131:
        if ( v2[1] != 0 )
        {
          v49 = v7 & 7;
          v4 >>= v49;
          v7 -= v49;
          *v2 = 24;
          i = BYTE2(v4);
        }
        else
        {
          if ( v7 < 3 )
          {
            while ( v3 != 0 )
            {
              v50 = *v5 << v7;
              --v3;
              v7 += 8;
              ++v5;
              v4 += v50;
              v121 = v3;
              if ( v7 >= 3 )
                goto LABEL_136;
            }
            goto LABEL_301;
          }
LABEL_136:
          v51 = v4;
          v52 = v4 >> 1;
          v53 = v7 - 1;
          v2[1] = v51 & 1;
          switch ( v52 & 3 )
          {
            case 0u:
              v4 = v52 >> 2;
              *v2 = 13;
              i = BYTE2(v4);
              v7 = v53 - 2;
              break;
            case 1u:
              sub_101B07A0(result: v2);
              v4 = v52 >> 2;
              *v2 = 18;
              i = BYTE2(v4);
              v7 = v53 - 2;
              break;
            case 2u:
              v4 = v52 >> 2;
              *v2 = 15;
              i = BYTE2(v4);
              v7 = v53 - 2;
              break;
            case 3u:
              *(_DWORD *)(a1 + 24) = "invalid block type";
              *v2 = 27;
              v4 = v52 >> 2;
              i = BYTE2(v4);
              v7 = v53 - 2;
              break;
          }
        }
        goto LABEL_293;
      case 10:
        goto LABEL_128;
      case 11:
        goto LABEL_130;
      case 12:
        goto LABEL_131;
      case 13:
        v54 = v7 & 7;
        v4 >>= v54;
        v7 -= v54;
        for ( i = BYTE2(v4); v7 < 0x20; i = BYTE2(v4) )
        {
          if ( v3 == 0 )
            goto LABEL_301;
          v55 = *v5 << v7;
          --v3;
          v7 += 8;
          ++v5;
          v4 += v55;
          v121 = v3;
        }
        v56 = (unsigned __int16)v4;
        if ( (unsigned __int16)v4 != ~v4 >> 16 )
        {
          *(_DWORD *)(a1 + 24) = "invalid stored block lengths";
          goto LABEL_292;
        }
        v4 = 0;
        v2[16] = v56;
        i = 0;
        v7 = 0;
        *v2 = 14;
LABEL_147:
        v57 = v2[16];
        countc = v57;
        if ( v57 == 0 )
          goto LABEL_224;
        if ( v57 > v3 )
        {
          v57 = v3;
          countc = v3;
        }
        if ( v57 > v136 )
        {
          v57 = v136;
          countc = v136;
        }
        if ( v57 == 0 )
          goto LABEL_301;
        memcpy(dst, src: v5, count: countc);
        v121 -= countc;
        v136 -= countc;
        dst += countc;
        v3 = v121;
        v5 += countc;
        v2[16] -= countc;
        goto LABEL_293;
      case 14:
        goto LABEL_147;
      case 15:
        for ( ; v7 < 0xE; v121 = v3 )
        {
          if ( v3 == 0 )
            goto LABEL_301;
          v58 = *v5 << v7;
          --v3;
          v7 += 8;
          ++v5;
          v4 += v58;
        }
        v59 = v4 & 0x1F;
        v60 = v4 >> 5;
        v61 = v60;
        v2[24] = v59 + 257;
        v60 >>= 5;
        v62 = (v61 & 0x1F) + 1;
        v63 = (v60 & 0xF) + 4;
        v4 = v60 >> 4;
        v7 -= 14;
        v64 = (unsigned int)v2[24] <= 0x11E;
        v2[25] = v62;
        v2[23] = v63;
        i = BYTE2(v4);
        if ( !v64 || v62 > 0x1E )
        {
          *(_DWORD *)(a1 + 24) = "too many length or distance symbols";
          goto LABEL_292;
        }
        v2[26] = 0;
        *v2 = 16;
LABEL_160:
        if ( v2[26] < (unsigned int)v2[23] )
        {
          while ( v7 >= 3 )
          {
LABEL_164:
            *((_WORD *)v2 + (unsigned __int16)word_102AD620[v2[26]++] + 56) = v4 & 7;
            v4 >>= 3;
            v7 -= 3;
            i = BYTE2(v4);
            if ( v2[26] >= (unsigned int)v2[23] )
              goto LABEL_165;
          }
          while ( v3 != 0 )
          {
            v65 = *v5 << v7;
            --v3;
            v7 += 8;
            ++v5;
            v4 += v65;
            v121 = v3;
            if ( v7 >= 3 )
              goto LABEL_164;
          }
          goto LABEL_301;
        }
LABEL_165:
        while ( (unsigned int)v2[26] < 0x13 )
          *((_WORD *)v2 + (unsigned __int16)word_102AD620[v2[26]++] + 56) = 0;
        v2[27] = (int)(v2 + 332);
        v2[19] = (int)(v2 + 332);
        v2[21] = 7;
        v66 = inflate_table(a1: 0, a2: v2 + 28, a3: 19, a4: v2 + 27, a5: v2 + 21, a6: v2 + 188);
        v3 = v121;
        v141 = v66;
        if ( v66 != 0 )
        {
          *(_DWORD *)(a1 + 24) = "invalid code lengths set";
          goto LABEL_292;
        }
        v2[26] = 0;
        *v2 = 17;
LABEL_171:
        if ( v2[26] < (unsigned int)(v2[24] + v2[25]) )
        {
          while ( 1 )
          {
            v67 = *(_DWORD *)(v2[19] + 4 * (v4 & ((1 << v2[21]) - 1)));
            countd = v67;
            if ( BYTE1(v67) > v7 )
              break;
LABEL_175:
            if ( HIWORD(v67) >= 0x10u )
            {
              if ( HIWORD(countd) == 16 )
              {
                v69 = BYTE1(v67);
                v138 = BYTE1(v67);
                if ( v7 < (unsigned int)BYTE1(v67) + 2 )
                {
                  while ( v3 != 0 )
                  {
                    v70 = *v5 << v7;
                    v69 = v138;
                    --v3;
                    v7 += 8;
                    v4 += v70;
                    ++v5;
                    v121 = v3;
                    if ( v7 >= v138 + 2 )
                      goto LABEL_184;
                  }
                  goto LABEL_301;
                }
LABEL_184:
                v71 = v2[26];
                v4 >>= v69;
                v7 -= v69;
                i = BYTE2(v4);
                if ( v71 == 0 )
                {
                  *(_DWORD *)(a1 + 24) = "invalid bit length repeat";
                  goto LABEL_292;
                }
                v72 = *((unsigned __int16 *)v2 + v71 + 55);
                v73 = (v4 & 3) + 3;
                v4 >>= 2;
                v138 = v72;
                counte = v73;
                v7 -= 2;
              }
              else
              {
                v74 = BYTE1(v67);
                v138 = BYTE1(v67);
                if ( HIWORD(countd) == 17 )
                {
                  if ( v7 < (unsigned int)BYTE1(v67) + 3 )
                  {
                    while ( v3 != 0 )
                    {
                      v75 = *v5 << v7;
                      v74 = v138;
                      --v3;
                      v7 += 8;
                      v4 += v75;
                      ++v5;
                      v121 = v3;
                      if ( v7 >= v138 + 3 )
                        goto LABEL_190;
                    }
                    goto LABEL_301;
                  }
LABEL_190:
                  v76 = v4 >> v74;
                  counte = (v76 & 7) + 3;
                  v4 = v76 >> 3;
                  v77 = -3;
                }
                else
                {
                  if ( v7 < (unsigned int)BYTE1(v67) + 7 )
                  {
                    while ( v3 != 0 )
                    {
                      v78 = *v5 << v7;
                      v74 = v138;
                      --v3;
                      v7 += 8;
                      v4 += v78;
                      ++v5;
                      v121 = v3;
                      if ( v7 >= v138 + 7 )
                        goto LABEL_194;
                    }
                    goto LABEL_301;
                  }
LABEL_194:
                  v79 = v4 >> v74;
                  counte = (v79 & 0x7F) + 11;
                  v4 = v79 >> 7;
                  v77 = -7;
                }
                v7 += v77 - v74;
                v73 = counte;
                v138 = 0;
              }
              i = BYTE2(v4);
              if ( v73 + v2[26] > (unsigned int)(v2[24] + v2[25]) )
              {
                *(_DWORD *)(a1 + 24) = "invalid bit length repeat";
                goto LABEL_292;
              }
              if ( counte != 0 )
              {
                v80 = v138;
                do
                {
                  --counte;
                  *((_WORD *)v2 + v2[26]++ + 56) = v80;
                }
                while ( counte != 0 );
              }
            }
            else
            {
              if ( v7 < BYTE1(v67) )
              {
                while ( v3 != 0 )
                {
                  v67 = *v5 << v7;
                  --v3;
                  v7 += 8;
                  ++v5;
                  v4 += v67;
                  BYTE1(v67) = BYTE1(countd);
                  v121 = v3;
                  if ( v7 >= BYTE1(countd) )
                    goto LABEL_179;
                }
                goto LABEL_301;
              }
LABEL_179:
              v4 >>= SBYTE1(v67);
              v7 -= BYTE1(v67);
              *((_WORD *)v2 + v2[26]++ + 56) = HIWORD(countd);
              i = BYTE2(v4);
            }
            if ( v2[26] >= (unsigned int)(v2[24] + v2[25]) )
              goto LABEL_201;
          }
          while ( v3 != 0 )
          {
            v68 = *v5 << v7;
            --v3;
            v7 += 8;
            v4 += v68;
            ++v5;
            v121 = v3;
            v67 = *(_DWORD *)(v2[19] + 4 * (v4 & ((1 << v2[21]) - 1)));
            countd = v67;
            if ( BYTE1(v67) <= v7 )
              goto LABEL_175;
          }
          goto LABEL_301;
        }
LABEL_201:
        if ( *v2 == 27 )
          goto LABEL_293;
        v2[27] = (int)(v2 + 332);
        v2[19] = (int)(v2 + 332);
        v118 = v2[24];
        v2[21] = 9;
        v141 = inflate_table(a1: 1, a2: v2 + 28, a3: v118, a4: v2 + 27, a5: v2 + 21, a6: v2 + 188);
        if ( v141 != 0 )
        {
          v3 = v121;
          *(_DWORD *)(a1 + 24) = "invalid literal/lengths set";
          goto LABEL_292;
        }
        v2[20] = v2[27];
        v81 = v2[24];
        v2[22] = 6;
        v82 = inflate_table(a1: 2, a2: (char *)v2 + 2 * v81 + 112, a3: v2[25], a4: v2 + 27, a5: v2 + 22, a6: v2 + 188);
        v3 = v121;
        v141 = v82;
        if ( v82 != 0 )
        {
          *(_DWORD *)(a1 + 24) = "invalid distances set";
          goto LABEL_292;
        }
        *v2 = 18;
LABEL_209:
        if ( v3 >= 6 && v136 >= 0x102 )
        {
          v83 = dst;
          *(_DWORD *)(a1 + 16) = v136;
          v84 = v140;
          *(_DWORD *)(a1 + 12) = v83;
          *(_DWORD *)a1 = v5;
          *(_DWORD *)(a1 + 4) = v121;
          v2[14] = v4;
          v2[15] = v7;
          inflate_fast(a1, a2: v84);
          v5 = *(unsigned __int8 **)a1;
          v85 = *(_DWORD *)(a1 + 4);
          v4 = v2[14];
          v7 = v2[15];
          v136 = *(_DWORD *)(a1 + 16);
          dst = *(unsigned __int8 **)(a1 + 12);
          v121 = v85;
          i = BYTE2(v4);
          v3 = v85;
          goto LABEL_293;
        }
        v86 = *(_DWORD *)(v2[19] + 4 * (v4 & ((1 << v2[21]) - 1)));
        countf = v86;
        if ( BYTE1(v86) > v7 )
        {
          while ( v3 != 0 )
          {
            v87 = *v5 << v7;
            --v3;
            v7 += 8;
            v4 += v87;
            ++v5;
            v121 = v3;
            v86 = *(_DWORD *)(v2[19] + 4 * (v4 & ((1 << v2[21]) - 1)));
            countf = v86;
            if ( BYTE1(v86) <= v7 )
              goto LABEL_215;
          }
          goto LABEL_301;
        }
LABEL_215:
        if ( (_BYTE)v86 != 0 && (v86 & 0xF0) == 0 )
        {
          v142 = v86 >> 8;
          v138 = BYTE1(v86);
          v133 = v86;
          countg = *(_DWORD *)(v2[19] + 4 * (HIWORD(countf) + ((v4 & ((1 << (BYTE1(v86) + v86)) - 1)) >> SBYTE1(v86))));
          if ( BYTE1(v86) + (unsigned int)BYTE1(countg) > v7 )
          {
            while ( v3 != 0 )
            {
              v88 = *v5 << v7;
              --v3;
              v7 += 8;
              v4 += v88;
              v138 = BYTE1(v133);
              ++v5;
              v121 = v3;
              countg = *(_DWORD *)(v2[19]
                                 + 4 * (HIWORD(v133) + ((v4 & ((1 << (BYTE1(v133) + v133)) - 1)) >> SBYTE1(v133))));
              if ( BYTE1(v133) + (unsigned int)BYTE1(countg) <= v7 )
                goto LABEL_220;
            }
            goto LABEL_301;
          }
LABEL_220:
          v86 = countg;
          v4 >>= SBYTE1(v133);
          v7 -= BYTE1(v133);
        }
        v4 >>= SBYTE1(v86);
        v7 -= BYTE1(v86);
        v138 = BYTE1(v86);
        i = BYTE2(v4);
        v2[16] = HIWORD(v86);
        if ( (_BYTE)v86 == 0 )
        {
          *v2 = 23;
          goto LABEL_293;
        }
        if ( (v86 & 0x20) != 0 )
        {
LABEL_224:
          *v2 = 11;
          goto LABEL_293;
        }
        if ( (v86 & 0x40) != 0 )
        {
          *(_DWORD *)(a1 + 24) = "invalid literal/length code";
          goto LABEL_292;
        }
        v2[18] = v86 & 0xF;
        *v2 = 19;
LABEL_228:
        v89 = v2[18];
        if ( v89 != 0 )
        {
          if ( v7 < v89 )
          {
            while ( v3 != 0 )
            {
              v90 = *v5 << v7;
              --v3;
              v7 += 8;
              ++v5;
              v4 += v90;
              v121 = v3;
              if ( v7 >= v2[18] )
                goto LABEL_232;
            }
            goto LABEL_301;
          }
LABEL_232:
          v91 = v2[18];
          v2[16] += v4 & ((1 << v91) - 1);
          v4 >>= v91;
          v7 -= v91;
        }
        *v2 = 20;
LABEL_234:
        v92 = *(_DWORD *)(v2[20] + 4 * (v4 & ((1 << v2[22]) - 1)));
        counth = v92;
        if ( BYTE1(v92) > v7 )
        {
          while ( v3 != 0 )
          {
            v93 = *v5 << v7;
            --v3;
            v7 += 8;
            v4 += v93;
            ++v5;
            v121 = v3;
            v92 = *(_DWORD *)(v2[20] + 4 * (v4 & ((1 << v2[22]) - 1)));
            counth = v92;
            if ( BYTE1(v92) <= v7 )
              goto LABEL_237;
          }
          goto LABEL_301;
        }
LABEL_237:
        if ( (v92 & 0xF0) == 0 )
        {
          v142 = v92 >> 8;
          v138 = BYTE1(v92);
          v134 = v92;
          counti = *(_DWORD *)(v2[20] + 4 * (HIWORD(counth) + ((v4 & ((1 << (BYTE1(v92) + v92)) - 1)) >> SBYTE1(v92))));
          if ( BYTE1(v92) + (unsigned int)BYTE1(counti) > v7 )
          {
            while ( v3 != 0 )
            {
              v94 = *v5 << v7;
              --v3;
              v7 += 8;
              v4 += v94;
              v138 = BYTE1(v134);
              ++v5;
              v121 = v3;
              counti = *(_DWORD *)(v2[20]
                                 + 4 * (HIWORD(v134) + ((v4 & ((1 << (BYTE1(v134) + v134)) - 1)) >> SBYTE1(v134))));
              if ( BYTE1(v134) + (unsigned int)BYTE1(counti) <= v7 )
                goto LABEL_241;
            }
            goto LABEL_301;
          }
LABEL_241:
          v92 = counti;
          v4 >>= SBYTE1(v134);
          v7 -= BYTE1(v134);
        }
        v4 >>= SBYTE1(v92);
        v7 -= BYTE1(v92);
        v138 = BYTE1(v92);
        i = BYTE2(v4);
        if ( (v92 & 0x40) != 0 )
        {
          *(_DWORD *)(a1 + 24) = "invalid distance code";
          goto LABEL_292;
        }
        v2[17] = HIWORD(v92);
        v2[18] = v92 & 0xF;
        *v2 = 21;
LABEL_245:
        v95 = v2[18];
        if ( v95 != 0 )
        {
          if ( v7 < v95 )
          {
            while ( v3 != 0 )
            {
              v96 = *v5 << v7;
              --v3;
              v7 += 8;
              ++v5;
              v4 += v96;
              v121 = v3;
              if ( v7 >= v2[18] )
                goto LABEL_249;
            }
            goto LABEL_301;
          }
LABEL_249:
          v97 = v2[18];
          v2[17] += v4 & ((1 << v97) - 1);
          v4 >>= v97;
          v7 -= v97;
          i = BYTE2(v4);
        }
        if ( v2[17] > v140 + v2[11] - v136 )
        {
          *(_DWORD *)(a1 + 24) = "invalid distance too far back";
          goto LABEL_292;
        }
        *v2 = 22;
LABEL_253:
        if ( v136 == 0 )
          goto LABEL_301;
        v98 = v2[17];
        if ( v98 <= v140 - v136 )
        {
          v102 = &dst[-v98];
          v99 = v2[16];
          v138 = (int)v102;
          v142 = v99;
          goto LABEL_261;
        }
        v99 = v98 - (v140 - v136);
        v100 = v2[12];
        countj = v99;
        if ( v99 <= v100 )
        {
          v101 = v2[12] + v2[13] - v99;
        }
        else
        {
          v99 -= v100;
          countj = v99;
          v101 = v2[10] + v2[13] - v99;
        }
        v138 = v101;
        v142 = v2[16];
        if ( v99 > v142 )
        {
          v99 = v142;
LABEL_261:
          countj = v99;
        }
        if ( v99 > v136 )
        {
          v99 = v136;
          countj = v136;
        }
        v136 -= v99;
        v103 = v142 - v99;
        v104 = dst;
        v2[16] = v103;
        do
        {
          v105 = *(_BYTE *)v138++;
          *v104++ = v105;
          --countj;
        }
        while ( countj != 0 );
        v106 = v2[16] == 0;
        dst = v104;
        if ( v106 )
          *v2 = 18;
        goto LABEL_293;
      case 16:
        goto LABEL_160;
      case 17:
        goto LABEL_171;
      case 18:
        goto LABEL_209;
      case 19:
        goto LABEL_228;
      case 20:
        goto LABEL_234;
      case 21:
        goto LABEL_245;
      case 22:
        goto LABEL_253;
      case 23:
        if ( v136 == 0 )
          goto LABEL_301;
        v107 = dst;
        *dst = *((_BYTE *)v2 + 64);
        --v136;
        dst = v107 + 1;
        *v2 = 18;
        goto LABEL_293;
      case 24:
        if ( v2[2] == 0 )
          goto LABEL_284;
        for ( ; v7 < 0x20; i = BYTE2(v4) )
        {
          if ( v3 == 0 )
            goto LABEL_301;
          v108 = *v5 << v7;
          --v3;
          v7 += 8;
          ++v5;
          v4 += v108;
          v121 = v3;
        }
        v109 = v140 - v136;
        *(_DWORD *)(a1 + 20) += v140 - v136;
        v2[7] += v109;
        v140 = v109;
        if ( v109 != 0 )
        {
          v120 = &dst[-v109];
          v119 = v2[6];
          if ( v2[4] != 0 )
            v110 = crc32(a1: v119, a2: v120, a3: v109);
          else
            v110 = adler32(a1: v119, a2: v120, a3: v109);
          v3 = v121;
          v2[6] = v110;
          *(_DWORD *)(a1 + 48) = v110;
        }
        v106 = v2[4] == 0;
        v140 = v136;
        v111 = v4;
        if ( v106 )
        {
          LOBYTE(v112) = 0;
          HIBYTE(v112) = i;
          v111 = HIBYTE(v4) + v112 + (((v4 << 16) + (v4 & 0xFF00)) << 8);
        }
        if ( v111 != v2[6] )
        {
          *(_DWORD *)(a1 + 24) = "incorrect data check";
          goto LABEL_292;
        }
        v4 = 0;
        i = 0;
        v7 = 0;
LABEL_284:
        *v2 = 25;
LABEL_285:
        if ( v2[2] == 0 || v2[4] == 0 )
          goto LABEL_298;
        if ( v7 < 0x20 )
        {
          while ( v3 != 0 )
          {
            v113 = *v5 << v7;
            --v3;
            v7 += 8;
            ++v5;
            v4 += v113;
            v121 = v3;
            i = BYTE2(v4);
            if ( v7 >= 0x20 )
              goto LABEL_290;
          }
          goto LABEL_301;
        }
LABEL_290:
        if ( v4 != v2[7] )
        {
          *(_DWORD *)(a1 + 24) = "incorrect length check";
LABEL_292:
          *v2 = 27;
LABEL_293:
          v6 = *v2;
          if ( (unsigned int)*v2 > 0x1C )
            return -2;
          continue;
        }
        v4 = 0;
        v7 = 0;
LABEL_298:
        *v2 = 26;
LABEL_299:
        v141 = 1;
LABEL_301:
        *(_DWORD *)(a1 + 12) = dst;
        *(_DWORD *)(a1 + 16) = v136;
        *(_DWORD *)a1 = v5;
        *(_DWORD *)(a1 + 4) = v3;
        v106 = v2[10] == 0;
        v2[14] = v4;
        v2[15] = v7;
        if ( v106 && (*v2 >= 24 || v140 == *(_DWORD *)(a1 + 16)) || sub_101B07C0(a1: v140, a2: a1) == 0 )
        {
          v115 = v143 - *(_DWORD *)(a1 + 4);
          v116 = v140 - *(_DWORD *)(a1 + 16);
          *(_DWORD *)(a1 + 8) += v115;
          *(_DWORD *)(a1 + 20) += v116;
          v2[7] += v116;
          if ( v2[2] != 0 && v116 != 0 )
          {
            if ( v2[4] != 0 )
              v117 = crc32(a1: v2[6], a2: *(_DWORD *)(a1 + 12) - v116, a3: v116);
            else
              v117 = adler32(a1: v2[6], a2: *(_DWORD *)(a1 + 12) - v116, a3: v116);
            v2[6] = v117;
            *(_DWORD *)(a1 + 48) = v117;
          }
          *(_DWORD *)(a1 + 44) = v2[15] + (*v2 != 11 ? 0 : 0x80) + (v2[1] != 0 ? 0x40 : 0);
          if ( (v115 != 0 || v116 != 0) && a2 != 4 )
          {
            return v141;
          }
          else
          {
            result = v141;
            if ( v141 == 0 )
              return -5;
          }
        }
        else
        {
          *v2 = 28;
          return -4;
        }
        return result;
      case 25:
        goto LABEL_285;
      case 26:
        goto LABEL_299;
      case 27:
        v141 = -3;
        goto LABEL_301;
      case 28:
        return -4;
      default:
        return -2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B1EA0
// Name: _inflateEnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflateEnd(_DWORD *a1)
{
  int v1; // eax
  void (__cdecl *v2)(_DWORD, int); // ecx
  int v3; // eax

  if ( a1 == nullptr )
    return -2;
  v1 = a1[7];
  if ( v1 == 0 )
    return -2;
  v2 = (void (__cdecl *)(_DWORD, int))a1[9];
  if ( v2 == nullptr )
    return -2;
  v3 = *(_DWORD *)(v1 + 52);
  if ( v3 != 0 )
    v2(a1: a1[10], a2: v3);
  ((void (__cdecl *)(_DWORD, _DWORD))a1[9])(a1: a1[10], a2: a1[7]);
  a1[7] = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B1EF0
// Name: _zcalloc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl zcalloc(int a1, int a2, int a3)
{
  return MemAlloc_Alloc(nSize: a3 * a2);
}

//------------------------------------------------------------------------------
// Address: 0x101B1F10
// Name: _inflate_fast
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__cdecl inflate_fast(_DWORD *a1, int a2)
{
  _DWORD *v2; // eax
  unsigned int v3; // ebx
  unsigned __int8 *v4; // ebp
  _BYTE *v5; // esi
  unsigned int v6; // edi
  int v7; // edx
  int v8; // eax
  unsigned int v9; // eax
  char v10; // dl
  unsigned int v11; // edx
  int v12; // eax
  int v13; // edx
  unsigned __int8 *v14; // ebp
  int v15; // eax
  unsigned int v16; // edx
  char v17; // al
  unsigned int v18; // eax
  int v19; // edx
  int v20; // edx
  int v21; // edx
  unsigned int v22; // edx
  char v23; // cl
  _BYTE *v24; // eax
  unsigned int v25; // ebp
  int v26; // ecx
  _BYTE *v27; // ecx
  char v28; // al
  int v29; // edx
  unsigned int v30; // ebp
  char v31; // dl
  unsigned int i; // ebp
  char v33; // al
  char v34; // al
  unsigned int v35; // ebp
  char v36; // al
  _BYTE *v37; // ecx
  _BYTE *v38; // esi
  char v39; // dl
  char v40; // al
  char v41; // dl
  _BYTE *v42; // ecx
  unsigned int v43; // edx
  _BYTE *v44; // eax
  char v45; // cl
  _BYTE *v46; // eax
  char v47; // dl
  _BYTE *v48; // esi
  char v49; // cl
  unsigned int v50; // ecx
  char v51; // dl
  _BYTE *v52; // eax
  unsigned __int8 *v53; // ebp
  unsigned int v54; // edi
  unsigned __int8 *v56; // [esp+10h] [ebp-3Ch]
  unsigned int v57; // [esp+14h] [ebp-38h]
  _DWORD *v58; // [esp+18h] [ebp-34h]
  unsigned int v59; // [esp+1Ch] [ebp-30h]
  unsigned int v60; // [esp+1Ch] [ebp-30h]
  unsigned __int16 v61; // [esp+1Eh] [ebp-2Eh]
  int v62; // [esp+20h] [ebp-2Ch]
  int v63; // [esp+24h] [ebp-28h]
  int v64; // [esp+28h] [ebp-24h]
  unsigned int v65; // [esp+2Ch] [ebp-20h]
  int v66; // [esp+30h] [ebp-1Ch]
  _BYTE *v67; // [esp+38h] [ebp-14h]
  unsigned int v68; // [esp+3Ch] [ebp-10h]
  int v69; // [esp+40h] [ebp-Ch]
  unsigned int v70; // [esp+44h] [ebp-8h]
  int v71; // [esp+48h] [ebp-4h]
  unsigned int v72; // [esp+54h] [ebp+8h]

  v2 = (_DWORD *)a1[7];
  v3 = v2[14];
  v4 = (unsigned __int8 *)(*a1 - 1);
  v57 = (unsigned int)&v4[a1[1] - 5];
  v5 = (_BYTE *)(a1[3] - 1);
  v67 = &v5[a1[4] - a2];
  v65 = (unsigned int)&v5[a1[4] - 257];
  v64 = v2[10];
  v68 = v2[11];
  v70 = v2[12];
  v69 = v2[13];
  v62 = v2[19];
  v63 = v2[20];
  v58 = v2;
  v6 = v2[15];
  v7 = (1 << v2[21]) - 1;
  v56 = v4;
  v71 = v7;
  v66 = (1 << v2[22]) - 1;
  while ( 1 )
  {
    if ( v6 < 0xF )
    {
      v8 = v4[1];
      v4 += 2;
      v56 = v4;
      v3 += (*v4 << (v6 + 8)) + (v8 << v6);
      v6 += 16;
    }
    v9 = *(_DWORD *)(v62 + 4 * (v3 & v7));
    v10 = v9;
    v3 >>= SBYTE1(v9);
    v6 -= BYTE1(v9);
    if ( (_BYTE)v9 == 0 )
    {
LABEL_8:
      *++v5 = BYTE2(v9);
      goto LABEL_47;
    }
    while ( (v10 & 0x10) == 0 )
    {
      if ( (v10 & 0x40) != 0 )
      {
        if ( (v10 & 0x20) != 0 )
        {
          *v58 = 11;
          goto LABEL_61;
        }
        a1[6] = "invalid literal/length code";
LABEL_60:
        *v58 = 27;
        goto LABEL_61;
      }
      v9 = *(_DWORD *)(v62 + 4 * (HIWORD(v9) + (v3 & ((1 << v10) - 1))));
      v10 = v9;
      v3 >>= SBYTE1(v9);
      v6 -= BYTE1(v9);
      if ( (_BYTE)v9 == 0 )
        goto LABEL_8;
    }
    v11 = v10 & 0xF;
    v72 = HIWORD(v9);
    if ( v11 != 0 )
    {
      if ( v6 < v11 )
      {
        v12 = *++v4;
        v56 = v4;
        v3 += v12 << v6;
        v6 += 8;
      }
      v72 += v3 & ((1 << v11) - 1);
      v3 >>= v11;
      v6 -= v11;
    }
    if ( v6 < 0xF )
    {
      v13 = v4[1];
      v14 = v4 + 1;
      v15 = v14[1];
      v4 = v14 + 1;
      v56 = v4;
      v3 += (v15 << (v6 + 8)) + (v13 << v6);
      v6 += 16;
    }
    v16 = *(_DWORD *)(v63 + 4 * (v3 & v66));
    v17 = v16;
    v3 >>= SBYTE1(v16);
    v6 -= BYTE1(v16);
    v61 = HIWORD(v16);
    if ( (v16 & 0x10) == 0 )
    {
      while ( (v17 & 0x40) == 0 )
      {
        v16 = *(_DWORD *)(v63 + 4 * (v61 + (v3 & ((1 << v17) - 1))));
        v17 = v16;
        v3 >>= SBYTE1(v16);
        v6 -= BYTE1(v16);
        v61 = HIWORD(v16);
        if ( (v16 & 0x10) != 0 )
          goto LABEL_18;
      }
      a1[6] = "invalid distance code";
      goto LABEL_60;
    }
LABEL_18:
    v18 = v17 & 0xF;
    v59 = HIWORD(v16);
    if ( v6 < v18 )
    {
      v19 = *++v4;
      v20 = v19 << v6;
      v6 += 8;
      v56 = v4;
      v3 += v20;
      if ( v6 < v18 )
      {
        v21 = *++v4;
        v56 = v4;
        v3 += v21 << v6;
        v6 += 8;
      }
    }
    v6 -= v18;
    v22 = (v3 & ((1 << v18) - 1)) + v59;
    v23 = v18;
    v24 = (_BYTE *)(v5 - v67);
    v3 >>= v23;
    v60 = v22;
    if ( v22 > v5 - v67 )
    {
      v25 = v22 - (_DWORD)v24;
      if ( v22 - (unsigned int)v24 > v68 )
      {
        v4 = v56;
        a1[6] = "invalid distance too far back";
        *v58 = 27;
LABEL_61:
        v43 = v57;
        break;
      }
      v26 = v69 - 1;
      if ( v70 != 0 )
      {
        if ( v70 < v25 )
        {
          v29 = v64 + v70 - v25;
          v30 = v25 - v70;
          v27 = (_BYTE *)(v29 + v26);
          if ( v30 < v72 )
          {
            v72 -= v30;
            do
            {
              v31 = *++v27;
              ++v5;
              --v30;
              *v5 = v31;
            }
            while ( v30 != 0 );
            v27 = (_BYTE *)(v69 - 1);
            if ( v70 < v72 )
            {
              v72 -= v70;
              for ( i = v70; i != 0; --i )
              {
                v33 = *++v27;
                *++v5 = v33;
              }
              v27 = &v5[-v60];
            }
          }
          goto LABEL_40;
        }
        v27 = (_BYTE *)(v70 - v25 + v26);
        if ( v25 < v72 )
        {
          v72 -= v25;
          do
          {
            v34 = *++v27;
            ++v5;
            --v25;
            *v5 = v34;
          }
          while ( v25 != 0 );
          goto LABEL_39;
        }
      }
      else
      {
        v27 = (_BYTE *)(v64 - v25 + v26);
        if ( v25 < v72 )
        {
          v72 -= v25;
          do
          {
            v28 = *++v27;
            ++v5;
            --v25;
            *v5 = v28;
          }
          while ( v25 != 0 );
LABEL_39:
          v27 = &v5[-v22];
        }
      }
LABEL_40:
      if ( v72 > 2 )
      {
        v35 = (v72 - 3) / 3 + 1;
        do
        {
          v36 = v27[1];
          v72 -= 3;
          v37 = v27 + 1;
          v38 = v5 + 1;
          *v38 = v36;
          v39 = *++v37;
          *++v38 = v39;
          v40 = v37[1];
          v27 = v37 + 1;
          v5 = v38 + 1;
          --v35;
          *v5 = v40;
        }
        while ( v35 != 0 );
      }
      if ( v72 != 0 )
      {
        v41 = v27[1];
        v42 = v27 + 1;
        *++v5 = v41;
        if ( v72 > 1 )
          *++v5 = v42[1];
      }
      v4 = v56;
      goto LABEL_47;
    }
    v44 = &v5[-v22];
    do
    {
      v45 = v44[1];
      v46 = v44 + 1;
      v5[1] = v45;
      v47 = *++v46;
      v48 = v5 + 2;
      *v48 = v47;
      v49 = v46[1];
      v44 = v46 + 1;
      v5 = v48 + 1;
      *v5 = v49;
      v50 = v72 - 3;
      v72 -= 3;
    }
    while ( v72 > 2 );
    if ( v50 != 0 )
    {
      v51 = v44[1];
      v52 = v44 + 1;
      *++v5 = v51;
      if ( v50 > 1 )
        *++v5 = v52[1];
    }
LABEL_47:
    v43 = v57;
    if ( (unsigned int)v4 >= v57 || (unsigned int)v5 >= v65 )
      break;
    v7 = v71;
  }
  v53 = &v4[-(v6 >> 3)];
  v54 = v6 - 8 * (v6 >> 3);
  *a1 = v53 + 1;
  a1[3] = v5 + 1;
  a1[4] = v65 - (_DWORD)v5 + 257;
  a1[1] = v43 - (_DWORD)v53 + 5;
  v58[15] = v54;
  v58[14] = ((1 << v54) - 1) & v3;
  return v58;
}

//------------------------------------------------------------------------------
// Address: 0x101B23D0
// Name: _inflate_table
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl inflate_table(int a1, int a2, unsigned int a3, _DWORD **a4, unsigned int *a5, _WORD *a6)
{
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int i; // ecx
  unsigned int v10; // esi
  int v11; // edx
  unsigned int j; // eax
  unsigned int k; // eax
  __int16 v14; // cx
  unsigned int m; // eax
  unsigned int v16; // ebp
  unsigned int v17; // ebx
  int v18; // eax
  int v19; // eax
  int v20; // edx
  _DWORD *v21; // ecx
  unsigned int v22; // edx
  unsigned int n; // eax
  int v24; // esi
  char v25; // cl
  unsigned int v26; // edx
  int v27; // eax
  unsigned __int16 *v28; // esi
  int v29; // eax
  _DWORD *v30; // esi
  unsigned int ii; // eax
  int v32; // [esp+Ch] [ebp-8Ch]
  int v33; // [esp+Ch] [ebp-8Ch]
  unsigned int v34; // [esp+10h] [ebp-88h]
  unsigned int v35; // [esp+14h] [ebp-84h]
  _WORD *v36; // [esp+18h] [ebp-80h]
  unsigned int v37; // [esp+1Ch] [ebp-7Ch]
  _DWORD *v38; // [esp+20h] [ebp-78h]
  unsigned int v39; // [esp+24h] [ebp-74h]
  char *v40; // [esp+28h] [ebp-70h]
  int v41; // [esp+2Ch] [ebp-6Ch]
  int v42; // [esp+30h] [ebp-68h]
  char *v43; // [esp+34h] [ebp-64h]
  int v44; // [esp+3Ch] [ebp-5Ch]
  int v45; // [esp+40h] [ebp-58h]
  int v46; // [esp+54h] [ebp-44h] BYREF
  int v47; // [esp+58h] [ebp-40h]
  _WORD v48[28]; // [esp+5Ch] [ebp-3Ch] BYREF

  v36 = a6;
  v6 = 0;
  v46 = 0;
  v47 = 0;
  memset(v48, 0, 24);
  if ( a3 != 0 )
  {
    do
      ++*((_WORD *)&v46 + *(unsigned __int16 *)(a2 + 2 * v6++));
    while ( v6 < a3 );
  }
  v7 = *a5;
  v34 = *a5;
  for ( i = 15; i != 0; --i )
  {
    if ( *((_WORD *)&v46 + i) != 0 )
      break;
  }
  v37 = i;
  if ( v7 > i )
  {
    v34 = i;
    v7 = i;
  }
  if ( i == 0 )
  {
    *(*a4)++ = 320;
    *(*a4)++ = 320;
    *a5 = 1;
    return 0;
  }
  v10 = 1;
  while ( *((_WORD *)&v46 + v10) == 0 )
  {
    if ( *((_WORD *)&v46 + v10 + 1) != 0 )
    {
      ++v10;
      break;
    }
    if ( v48[v10 - 2] != 0 )
    {
      v10 += 2;
      break;
    }
    if ( v48[v10 - 1] != 0 )
    {
      v10 += 3;
      break;
    }
    if ( v48[v10] != 0 )
    {
      v10 += 4;
      break;
    }
    v10 += 5;
    if ( v10 > 0xF )
      break;
  }
  if ( v7 < v10 )
    v34 = v10;
  v11 = 1;
  for ( j = 1; j <= 0xF; ++j )
  {
    v11 = 2 * v11 - *((unsigned __int16 *)&v46 + j);
    if ( v11 < 0 )
      return -1;
  }
  if ( v11 > 0 && (a1 == 0 || i != 1) )
    return -1;
  v48[13] = 0;
  for ( k = 1; k < 15; v48[k + 12] = v14 )
  {
    v14 = *(_WORD *)((char *)&v46 + k * 2) + v48[k + 12];
    ++k;
  }
  for ( m = 0; m < a3; ++m )
  {
    if ( *(_WORD *)(a2 + 2 * m) != 0 )
      a6[(unsigned __int16)v48[*(unsigned __int16 *)(a2 + 2 * m) + 12]++] = m;
  }
  if ( a1 != 0 )
  {
    if ( a1 == 1 )
    {
      v40 = (char *)&unk_102AD8E0 - 514;
      v43 = (char *)&unk_102AD920 - 514;
      v41 = 256;
    }
    else
    {
      v40 = (char *)&unk_102AD960;
      v43 = (char *)&unk_102AD9A0;
      v41 = -1;
    }
  }
  else
  {
    v43 = (char *)a6;
    v40 = (char *)a6;
    v41 = 19;
  }
  v38 = *a4;
  v16 = 0;
  v17 = 0;
  v35 = v10;
  v42 = -1;
  v45 = 1 << v34;
  v39 = 1 << v34;
  v44 = (1 << v34) - 1;
  if ( a1 == 1 && (unsigned int)(1 << v34) >= 0x5B0 )
    return 1;
  while ( 1 )
  {
    if ( (unsigned __int16)*v36 >= v41 )
    {
      if ( (unsigned __int16)*v36 <= v41 )
      {
        LOBYTE(v32) = 96;
        HIWORD(v32) = 0;
      }
      else
      {
        v18 = 2 * (unsigned __int16)*v36;
        LOBYTE(v32) = v43[v18];
        HIWORD(v32) = *(_WORD *)&v40[v18];
      }
    }
    else
    {
      LOBYTE(v32) = 0;
      HIWORD(v32) = *v36;
    }
    v19 = v45;
    v20 = 1 << (v35 - v17);
    v21 = &v38[v45 + (v16 >> v17)];
    do
    {
      v19 -= v20;
      v21 -= v20;
      BYTE1(v32) = v35 - v17;
      *v21 = v32;
    }
    while ( v19 != 0 );
    v22 = v35;
    for ( n = 1 << (v35 - 1); (n & v16) != 0; n >>= 1 )
      ;
    if ( n != 0 )
      v16 = n + (v16 & (n - 1));
    else
      v16 = 0;
    --*((_WORD *)&v46 + v35);
    ++v36;
    if ( *((_WORD *)&v46 + v35) == 0 )
    {
      if ( v35 == v37 )
        break;
      v22 = *(unsigned __int16 *)(a2 + 2 * (unsigned __int16)*v36);
      v35 = v22;
    }
    if ( v22 > v34 )
    {
      v24 = v16 & v44;
      if ( (v16 & v44) != v42 )
      {
        if ( v17 == 0 )
          v17 = v34;
        v25 = v35 - v17;
        v38 += v45;
        v26 = v35;
        v27 = 1 << (v35 - v17);
        if ( v35 < v37 )
        {
          v28 = (unsigned __int16 *)&v46 + v35;
          do
          {
            v29 = v27 - *v28;
            if ( v29 <= 0 )
              break;
            ++v26;
            ++v25;
            ++v28;
            v27 = 2 * v29;
          }
          while ( v26 < v37 );
          v24 = v16 & v44;
        }
        v39 += 1 << v25;
        v45 = 1 << v25;
        if ( a1 == 1 && v39 >= 0x5B0 )
          return 1;
        LOBYTE((*a4)[v24]) = v25;
        BYTE1((*a4)[v24]) = v34;
        v42 = v24;
        HIWORD((*a4)[v24]) = v38 - *a4;
      }
    }
  }
  LOBYTE(v33) = 64;
  BYTE1(v33) = v35 - v17;
  HIWORD(v33) = 0;
  if ( v16 != 0 )
  {
    v30 = v38;
    do
    {
      if ( v17 != 0 && (v16 & v44) != v42 )
      {
        v30 = *a4;
        v17 = 0;
        BYTE1(v33) = v34;
        LOBYTE(v22) = v34;
      }
      v30[v16 >> v17] = v33;
      for ( ii = 1 << (v22 - 1); (ii & v16) != 0; ii >>= 1 )
        ;
      if ( ii == 0 )
        break;
      v16 = ii + (v16 & (ii - 1));
    }
    while ( v16 != 0 );
  }
  *a4 += v39;
  *a5 = v34;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B28C0
// Name: _adler32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl adler32(unsigned int a1, unsigned __int8 *a2, unsigned int a3)
{
  unsigned int v3; // ebx
  unsigned int v4; // edi
  unsigned int v5; // ecx
  unsigned int v6; // ecx
  unsigned int v7; // edi
  unsigned __int8 *v9; // esi
  unsigned int v10; // ebp
  int i; // eax
  unsigned int v12; // ecx
  unsigned int v13; // edi
  unsigned int v14; // ecx
  unsigned int v15; // edi
  unsigned int v16; // ecx
  unsigned int v17; // edi
  unsigned int v18; // ecx
  unsigned int v19; // edi
  unsigned int v20; // ecx
  unsigned int v21; // edi
  unsigned int v22; // ecx
  unsigned int v23; // edi
  unsigned int v24; // ecx
  int v25; // edi
  unsigned int v26; // ecx
  int v27; // edi
  unsigned int v28; // ecx
  int v29; // edi
  int v30; // ecx
  int v31; // edi
  int v32; // ecx
  int v33; // edi
  int v34; // ecx
  int v35; // edi
  int v36; // ecx
  int v37; // edi
  int v38; // ecx
  int v39; // edi
  int v40; // ecx
  int v41; // edi
  unsigned int v42; // eax
  unsigned int v43; // ecx
  unsigned int v44; // edi
  unsigned int v45; // ecx
  unsigned int v46; // edi
  unsigned int v47; // ecx
  unsigned int v48; // edi
  unsigned int v49; // ecx
  unsigned int v50; // edi
  unsigned int v51; // ecx
  unsigned int v52; // edi
  unsigned int v53; // ecx
  unsigned int v54; // edi
  unsigned int v55; // ecx
  int v56; // edi
  unsigned int v57; // ecx
  int v58; // edi
  unsigned int v59; // ecx
  int v60; // edi
  int v61; // ecx
  int v62; // edi
  int v63; // ecx
  int v64; // edi
  int v65; // ecx
  int v66; // edi
  int v67; // ecx
  int v68; // edi
  int v69; // ecx
  int v70; // edi
  int v71; // ecx
  int v72; // edi

  v3 = a3;
  v4 = HIWORD(a1);
  v5 = (unsigned __int16)a1;
  if ( a3 == 1 )
  {
    v6 = *a2 + (unsigned __int16)a1;
    if ( v6 >= 0xFFF1 )
      v6 -= 65521;
    v7 = v6 + v4;
    if ( v7 >= 0xFFF1 )
      v7 -= 65521;
    return v6 | (v7 << 16);
  }
  else
  {
    v9 = a2;
    if ( a2 != nullptr )
    {
      if ( a3 >= 0x10 )
      {
        if ( a3 >= 0x15B0 )
        {
          v10 = a3 / 0x15B0;
          do
          {
            v3 -= 5552;
            for ( i = 347; i != 0; --i )
            {
              v12 = *v9 + v5;
              v13 = v12 + v4;
              v14 = v9[1] + v12;
              v15 = v14 + v13;
              v16 = v9[2] + v14;
              v17 = v16 + v15;
              v18 = v9[3] + v16;
              v19 = v18 + v17;
              v20 = v9[4] + v18;
              v21 = v20 + v19;
              v22 = v9[5] + v20;
              v23 = v22 + v21;
              v24 = v9[6] + v22;
              v25 = v24 + v23;
              v26 = v9[7] + v24;
              v27 = v26 + v25;
              v28 = v9[8] + v26;
              v29 = v28 + v27;
              v30 = v9[9] + v28;
              v31 = v30 + v29;
              v32 = v9[10] + v30;
              v33 = v32 + v31;
              v34 = v9[11] + v32;
              v35 = v34 + v33;
              v36 = v9[12] + v34;
              v37 = v36 + v35;
              v38 = v9[13] + v36;
              v39 = v38 + v37;
              v40 = v9[14] + v38;
              v41 = v40 + v39;
              v5 = v9[15] + v40;
              v4 = v5 + v41;
              v9 += 16;
            }
            v5 %= 0xFFF1u;
            v4 %= 0xFFF1u;
            --v10;
          }
          while ( v10 != 0 );
        }
        if ( v3 != 0 )
        {
          if ( v3 >= 0x10 )
          {
            v42 = v3 >> 4;
            do
            {
              v43 = *v9 + v5;
              v44 = v43 + v4;
              v45 = v9[1] + v43;
              v46 = v45 + v44;
              v47 = v9[2] + v45;
              v48 = v47 + v46;
              v49 = v9[3] + v47;
              v50 = v49 + v48;
              v51 = v9[4] + v49;
              v52 = v51 + v50;
              v53 = v9[5] + v51;
              v54 = v53 + v52;
              v55 = v9[6] + v53;
              v56 = v55 + v54;
              v57 = v9[7] + v55;
              v58 = v57 + v56;
              v59 = v9[8] + v57;
              v60 = v59 + v58;
              v61 = v9[9] + v59;
              v62 = v61 + v60;
              v63 = v9[10] + v61;
              v64 = v63 + v62;
              v65 = v9[11] + v63;
              v66 = v65 + v64;
              v67 = v9[12] + v65;
              v68 = v67 + v66;
              v69 = v9[13] + v67;
              v70 = v69 + v68;
              v71 = v9[14] + v69;
              v72 = v71 + v70;
              v5 = v9[15] + v71;
              v3 -= 16;
              v4 = v5 + v72;
              v9 += 16;
              --v42;
            }
            while ( v42 != 0 );
          }
          for ( ; v3 != 0; v4 += v5 )
          {
            v5 += *v9;
            --v3;
            ++v9;
          }
          v5 %= 0xFFF1u;
          v4 %= 0xFFF1u;
        }
        return v5 | (v4 << 16);
      }
      else
      {
        if ( a3 != 0 )
        {
          do
          {
            v5 += *v9;
            --v3;
            ++v9;
            v4 += v5;
          }
          while ( v3 != 0 );
        }
        if ( v5 >= 0xFFF1 )
          v5 -= 65521;
        return v5 | ((v4 + 15 * (v4 / 0xFFF1)) << 16);
      }
    }
    else
    {
      return 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B2DE0
// Name: _crc32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl crc32(int a1, _BYTE *a2, unsigned int a3)
{
  unsigned int v3; // esi
  unsigned int i; // eax
  unsigned int v5; // edi
  unsigned int v6; // eax
  _DWORD *v7; // ecx
  unsigned int v8; // edx
  unsigned int v9; // eax
  unsigned int v10; // edx
  unsigned int v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // eax
  unsigned int v14; // edx
  unsigned int v15; // edx
  unsigned int v16; // eax
  _BYTE *v17; // ecx

  v17 = a2;
  if ( a2 == nullptr )
    return 0;
  v3 = a3;
  for ( i = ~a1; v3 != 0; --v3 )
  {
    if ( ((unsigned __int8)v17 & 3) == 0 )
      break;
    i = dword_102AD9E0[(unsigned __int8)(i ^ *v17++)] ^ (i >> 8);
  }
  if ( v3 >= 0x20 )
  {
    v5 = v3 >> 5;
    do
    {
      v6 = *(_DWORD *)v17 ^ i;
      v7 = v17 + 12;
      v8 = *(v7 - 2)
         ^ dword_102AE5E0[(unsigned __int8)v6]
         ^ dword_102AD9E0[HIBYTE(v6)]
         ^ dword_102AE1E0[BYTE1(v6)]
         ^ dword_102ADDE0[BYTE2(v6)];
      v7 += 3;
      v9 = *(v7 - 4)
         ^ dword_102AE5E0[(unsigned __int8)v8]
         ^ dword_102AD9E0[HIBYTE(v8)]
         ^ dword_102AE1E0[BYTE1(v8)]
         ^ dword_102ADDE0[BYTE2(v8)];
      v10 = *(v7 - 3)
          ^ dword_102AE5E0[(unsigned __int8)v9]
          ^ dword_102AD9E0[HIBYTE(v9)]
          ^ dword_102AE1E0[BYTE1(v9)]
          ^ dword_102ADDE0[BYTE2(v9)];
      v11 = *(v7 - 2)
          ^ dword_102AE5E0[(unsigned __int8)v10]
          ^ dword_102AD9E0[HIBYTE(v10)]
          ^ dword_102AE1E0[BYTE1(v10)]
          ^ dword_102ADDE0[BYTE2(v10)];
      v12 = *(v7 - 1)
          ^ dword_102AE5E0[(unsigned __int8)v11]
          ^ dword_102AD9E0[HIBYTE(v11)]
          ^ dword_102AE1E0[BYTE1(v11)]
          ^ dword_102ADDE0[BYTE2(v11)];
      v13 = *v7
          ^ dword_102AE5E0[(unsigned __int8)v12]
          ^ dword_102AD9E0[HIBYTE(v12)]
          ^ dword_102AE1E0[BYTE1(v12)]
          ^ dword_102ADDE0[BYTE2(v12)];
      v17 = v7 + 2;
      v3 -= 32;
      v14 = *((_DWORD *)v17 - 1)
          ^ dword_102AE5E0[(unsigned __int8)v13]
          ^ dword_102AD9E0[HIBYTE(v13)]
          ^ dword_102AE1E0[BYTE1(v13)]
          ^ dword_102ADDE0[BYTE2(v13)];
      i = dword_102AE5E0[(unsigned __int8)v14]
        ^ dword_102AD9E0[HIBYTE(v14)]
        ^ dword_102AE1E0[BYTE1(v14)]
        ^ dword_102ADDE0[BYTE2(v14)];
      --v5;
    }
    while ( v5 != 0 );
  }
  if ( v3 >= 4 )
  {
    v15 = v3 >> 2;
    do
    {
      v16 = *(_DWORD *)v17 ^ i;
      v17 += 4;
      v3 -= 4;
      --v15;
      i = dword_102AE5E0[(unsigned __int8)v16]
        ^ dword_102AD9E0[HIBYTE(v16)]
        ^ dword_102AE1E0[BYTE1(v16)]
        ^ dword_102ADDE0[BYTE2(v16)];
    }
    while ( v15 != 0 );
  }
  for ( ; v3 != 0; --v3 )
    i = dword_102AD9E0[(unsigned __int8)(i ^ *v17++)] ^ (i >> 8);
  return ~i;
}

//------------------------------------------------------------------------------
// Address: 0x101B2E00
// Name: sub_101B2E00
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_101B2E00(int a1@<eax>, unsigned __int8 *a2@<edx>, int a3)
{
  int v4; // eax
  int i; // edi
  int v6; // ecx
  int v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // esi

  v4 = 0;
  for ( i = 0; i < 4; ++i )
  {
    v6 = *(unsigned __int8 *)(i + a3 + 284);
    if ( (unsigned int)(v6 - 65) > 0x39 || v6 > 90 && v6 < 97 )
    {
      *(_BYTE *)(v4 + a1) = 91;
      v7 = v4 + 1;
      *(_BYTE *)(v7 + a1) = byte_102AF9E0[(v6 >> 4) & 0xF];
      *(_BYTE *)(++v7 + a1) = byte_102AF9E0[v6 & 0xF];
      v4 = v7 + 1;
      *(_BYTE *)(v4 + a1) = 93;
    }
    else
    {
      *(_BYTE *)(v4 + a1) = v6;
    }
    ++v4;
  }
  if ( a2 != nullptr )
  {
    *(_BYTE *)(v4 + a1) = 58;
    v8 = v4 + 1;
    *(_BYTE *)(v8 + a1) = 32;
    v9 = (unsigned __int8 *)(v8 + 1 + a1);
    strncpy(dest: v9, source: a2, count: 0x3Fu);
    v9[63] = 0;
  }
  else
  {
    *(_BYTE *)(v4 + a1) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B2EA0
// Name: sub_101B2EA0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl sub_101B2EA0(int *a1, const char *a2)
{
  _BYTE *v2; // ebx
  _BYTE *v3; // ebp
  int v4; // esi
  bool v5; // zf
  char v6; // dl
  char v7; // bl
  char v8; // dl
  char v9; // bl
  _iobuf *v10; // eax
  _iobuf *v11; // eax
  int *result; // eax
  const char *v13; // [esp-Ch] [ebp-38h]
  _BYTE *v14; // [esp-8h] [ebp-34h]
  const char *v15; // [esp-4h] [ebp-30h]
  _BYTE *v16; // [esp+14h] [ebp-18h]
  _BYTE v17[2]; // [esp+18h] [ebp-14h] BYREF
  _BYTE v18[14]; // [esp+1Ah] [ebp-12h] BYREF

  if ( *a2 == 35 )
  {
    v2 = (_BYTE *)(v17 - a2);
    v3 = (_BYTE *)(v18 - a2);
    v4 = 0;
    v16 = (_BYTE *)(v18 - a2);
    while ( 1 )
    {
      v5 = a2[v4] == 32;
      v6 = a2[v4 + 1];
      a2[v4 + (_DWORD)v2] = v6;
      if ( v5 )
        break;
      v7 = a2[v4 + 2];
      v17[v4 + 1] = v7;
      if ( v6 == 32 )
      {
        ++v4;
        break;
      }
      v8 = a2[v4 + 3];
      a2[v4 + (_DWORD)v3] = v8;
      if ( v7 == 32 )
      {
        v4 += 2;
        break;
      }
      v9 = a2[v4 + 4];
      v18[v4 + 1] = v9;
      if ( v8 == 32 )
      {
        v4 += 3;
        break;
      }
      v18[v4 + 2] = a2[v4 + 5];
      if ( v9 == 32 )
      {
        v4 += 4;
        break;
      }
      v4 += 5;
      if ( v4 >= 15 )
        break;
      v3 = v16;
      v2 = (_BYTE *)(v17 - a2);
    }
    if ( (unsigned int)(v4 - 2) > 0xC )
    {
      v15 = (const char *)v4;
      v14 = a2;
      v13 = "libpng error: %s, offset=%d\n";
    }
    else
    {
      v15 = &a2[v4];
      v14 = v17;
      v17[v4 - 1] = 0;
      v13 = "libpng error no. %s: %s\n";
    }
    v10 = __iob_func();
    fprintf(str: v10 + 2, format: v13, v14, v15);
  }
  else
  {
    v11 = __iob_func();
    fprintf(str: v11 + 2, format: "libpng error: %s\n", a2);
  }
  result = a1;
  if ( a1 != nullptr )
    longjmp(Buf: a1, Value: 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B2FE0
// Name: sub_101B2FE0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_101B2FE0(const char *a1)
{
  char *v1; // ebx
  _BYTE *v2; // ebp
  int v3; // esi
  bool v4; // zf
  char v5; // dl
  char v6; // bl
  char v7; // dl
  char v8; // bl
  _iobuf *v9; // eax
  _iobuf *v11; // eax
  _iobuf *v12; // eax
  char *i; // [esp+Ch] [ebp-18h]
  char v14[2]; // [esp+10h] [ebp-14h] BYREF
  _BYTE v15[14]; // [esp+12h] [ebp-12h] BYREF

  if ( *a1 == 35 )
  {
    v1 = (char *)(v14 - a1);
    v2 = (_BYTE *)(v15 - a1);
    v3 = 0;
    for ( i = (char *)(v14 - a1); ; v1 = i )
    {
      v4 = a1[v3] == 32;
      v5 = a1[v3 + 1];
      a1[v3 + (_DWORD)v1] = v5;
      if ( v4 )
        break;
      v6 = a1[v3 + 2];
      v14[v3 + 1] = v6;
      if ( v5 == 32 )
      {
        ++v3;
        break;
      }
      v7 = a1[v3 + 3];
      a1[v3 + (_DWORD)v2] = v7;
      if ( v6 == 32 )
      {
        v3 += 2;
        break;
      }
      v8 = a1[v3 + 4];
      v15[v3 + 1] = v8;
      if ( v7 == 32 )
      {
        v3 += 3;
        break;
      }
      v15[v3 + 2] = a1[v3 + 5];
      if ( v8 == 32 )
      {
        v3 += 4;
        break;
      }
      v3 += 5;
      if ( v3 >= 15 )
        break;
      v2 = (_BYTE *)(v15 - a1);
    }
    if ( (unsigned int)(v3 - 2) > 0xC )
    {
      v11 = __iob_func();
      return fprintf(str: v11 + 2, format: "libpng warning: %s\n", a1);
    }
    else
    {
      v14[v3 - 1] = 0;
      v9 = __iob_func();
      return fprintf(str: v9 + 2, format: "libpng warning no. %s: %s\n", v14, &a1[v3]);
    }
  }
  else
  {
    v12 = __iob_func();
    return fprintf(str: v12 + 2, format: "libpng warning: %s\n", a1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B3130
// Name: _png_set_error_fn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__cdecl png_set_error_fn(_DWORD *a1, int a2, int a3, int a4)
{
  _DWORD *result; // eax

  result = a1;
  if ( a1 != nullptr )
  {
    a1[18] = a2;
    a1[16] = a3;
    a1[17] = a4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B3150
// Name: _png_get_error_ptr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl png_get_error_ptr(int a1)
{
  int result; // eax

  result = a1;
  if ( a1 != 0 )
    return *(_DWORD *)(a1 + 72);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B3160
// Name: _png_error
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl png_error(int *a1, unsigned __int8 *a2)
{
  unsigned __int8 *v2; // esi
  int v3; // edx
  int v4; // eax
  int v5; // edi
  int v6; // ecx
  void (__cdecl *v7)(int *, unsigned __int8 *); // eax
  unsigned __int8 dst[16]; // [esp+8h] [ebp-14h] BYREF

  v2 = a2;
  if ( a1 == nullptr )
    return sub_101B2EA0(a1, a2: (const char *)v2);
  v3 = a1[27];
  if ( (v3 & 0xC0000) != 0 )
  {
    if ( *a2 == 35 )
    {
      v4 = 1;
      while ( a2[v4] != 32 )
      {
        if ( a2[v4 + 1] == 32 )
        {
          ++v4;
          break;
        }
        v4 += 2;
        if ( v4 >= 15 )
          break;
      }
      if ( (v3 & 0x80000) == 0 )
      {
        v2 = &a2[v4];
        goto LABEL_18;
      }
      v5 = v4 - 1;
      v6 = 0;
      if ( v4 - 1 > 0 )
      {
        memcpy(dst, src: a2 + 1, count: v4 - 1);
        v6 = v5;
      }
      dst[v6] = 0;
    }
    else
    {
      if ( (v3 & 0x80000) == 0 )
        goto LABEL_18;
      strcpy((char *)dst, "0");
    }
    v2 = dst;
  }
LABEL_18:
  v7 = (void (__cdecl *)(int *, unsigned __int8 *))a1[16];
  if ( v7 != nullptr )
    v7(a1, a2: v2);
  return sub_101B2EA0(a1, a2: (const char *)v2);
}

//------------------------------------------------------------------------------
// Address: 0x101B3220
// Name: _png_warning
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl png_warning(int a1, const char *a2)
{
  int result; // eax
  int (__cdecl *v3)(int, const char *); // ecx

  result = 0;
  if ( a1 == 0 )
    return sub_101B2FE0(a1: a2);
  if ( (*(_DWORD *)(a1 + 108) & 0xC0000) != 0 && *a2 == 35 )
  {
    result = 1;
    while ( a2[result] != 32 )
    {
      if ( a2[result + 1] == 32 )
      {
        ++result;
        break;
      }
      result += 2;
      if ( result >= 15 )
        break;
    }
  }
  v3 = *(int (__cdecl **)(int, const char *))(a1 + 68);
  if ( v3 != nullptr )
    return v3(a1, a2: &a2[result]);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B3280
// Name: _png_chunk_error
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl png_chunk_error(int *a1, unsigned __int8 *a2)
{
  unsigned __int8 v3[84]; // [esp+4h] [ebp-58h] BYREF

  if ( a1 == nullptr )
    return png_error(a1: nullptr, a2);
  sub_101B2E00(a1: (int)v3, a2, a3: (int)a1);
  return png_error(a1, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x101B32E0
// Name: _png_chunk_warning
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl png_chunk_warning(int a1, char *a2)
{
  char v3[84]; // [esp+4h] [ebp-58h] BYREF

  if ( a1 == 0 )
    return png_warning(a1: 0, a2);
  sub_101B2E00(a1: (int)v3, (unsigned __int8 *)a2, a3: a1);
  return png_warning(a1, a2: v3);
}

//------------------------------------------------------------------------------
// Address: 0x101B3340
// Name: _png_get_valid
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl png_get_valid(int a1, int a2, int a3)
{
  if ( a1 != 0 && a2 != 0 )
    return a3 & *(_DWORD *)(a2 + 8);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B3360
// Name: _png_get_rowbytes
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl png_get_rowbytes(int a1, int a2)
{
  if ( a1 != 0 && a2 != 0 )
    return *(_DWORD *)(a2 + 12);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B3380
// Name: _png_get_gAMA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl png_get_gAMA(int a1, int a2, double *a3)
{
  if ( a1 == 0 || a2 == 0 || (*(_BYTE *)(a2 + 8) & 1) == 0 || a3 == nullptr )
    return 0;
  *a3 = *(float *)(a2 + 40);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101B33B0
// Name: _png_get_IHDR
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl png_get_IHDR(int *a1, int a2, int *a3, int *a4, _DWORD *a5, _DWORD *a6, _DWORD *a7, _DWORD *a8, _DWORD *a9)
{
  int *v9; // ecx

  v9 = a1;
  if ( a1 == nullptr || a2 == 0 || a3 == nullptr || a4 == nullptr || a5 == nullptr || a6 == nullptr )
    return 0;
  *a3 = *(_DWORD *)a2;
  *a4 = *(_DWORD *)(a2 + 4);
  *a5 = *(unsigned __int8 *)(a2 + 24);
  if ( *(_BYTE *)(a2 + 24) == 0 || *(_BYTE *)(a2 + 24) > 0x10u )
  {
    png_error(a1, a2: "Invalid bit depth");
    v9 = a1;
  }
  *a6 = *(unsigned __int8 *)(a2 + 25);
  if ( *(_BYTE *)(a2 + 25) > 6u )
  {
    png_error(a1: v9, a2: "Invalid color type");
    v9 = a1;
  }
  if ( a8 != nullptr )
    *a8 = *(unsigned __int8 *)(a2 + 26);
  if ( a9 != nullptr )
    *a9 = *(unsigned __int8 *)(a2 + 27);
  if ( a7 != nullptr )
    *a7 = *(unsigned __int8 *)(a2 + 28);
  if ( *a3 <= 0 )
  {
    png_error(a1: v9, a2: "Invalid image width");
    v9 = a1;
  }
  if ( *a4 <= 0 )
  {
    png_error(a1: v9, a2: "Invalid image height");
    v9 = a1;
  }
  if ( *(_DWORD *)a2 > 0x1FFFFF7Eu )
    png_warning(a1: (int)v9, a2: "Width too large for libpng to process image data.");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101B34E0
// Name: _png_create_read_struct_2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void **__cdecl png_create_read_struct_2(
        char *a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int (__cdecl *a6)(char *, unsigned int),
        void (__cdecl *a7)(_BYTE *, void *))
{
  unsigned __int8 *struct_2; // eax
  const char *v9; // eax
  char v10; // bl
  char v11; // al
  void **pMem; // [esp+28h] [ebp-58h]
  char string[80]; // [esp+2Ch] [ebp-54h] BYREF

  struct_2 = png_create_struct_2(a1: 1, a2: a6, a3: a5);
  pMem = (void **)struct_2;
  if ( struct_2 == nullptr )
    return nullptr;
  *((_DWORD *)struct_2 + 152) = 1000000;
  *((_DWORD *)struct_2 + 153) = 1000000;
  if ( _setjmp3(a1: struct_2, a2: 0) != 0 )
  {
    png_free(a1: (int)pMem, pMem: pMem[43]);
    pMem[43] = nullptr;
    png_destroy_struct_2(pMem, a2: a7, a3: a5);
    return nullptr;
  }
  png_set_mem_fn(a1: pMem, a2: a5, a3: (int)a6, a4: (int)a7);
  png_set_error_fn(a1: pMem, a2, a3, a4);
  v9 = "1.2.18";
  do
  {
    if ( v9[a1 - "1.2.18"] != *v9 )
      pMem[27] = (void *)((unsigned int)pMem[27] | 0x20000);
    v10 = *v9++;
  }
  while ( v10 != 0 );
  if ( ((unsigned int)pMem[27] & 0x20000) != 0 )
  {
    if ( a1 != nullptr )
    {
      v11 = *a1;
      if ( *a1 == png_libpng_ver[0] && (v11 != 49 || a1[2] == png_libpng_ver[2]) && (v11 != 48 || a1[2] >= 57) )
        goto LABEL_18;
      sprintf(string, format: "Application was compiled with png.h from libpng-%.20s", a1);
      png_warning(a1: (int)pMem, a2: string);
    }
    sprintf(string, format: "Application  is  running with png.c from libpng-%.20s", "1.2.18");
    png_warning(a1: (int)pMem, a2: string);
    pMem[27] = nullptr;
    png_error(a1: (int *)pMem, a2: "Incompatible libpng version in application and library");
  }
LABEL_18:
  pMem[44] = (void *)0x2000;
  pMem[43] = png_malloc(a1: (int)pMem, nSize: 0x2000u);
  pMem[37] = png_zalloc;
  pMem[38] = png_zfree;
  pMem[39] = pMem;
  switch ( inflateInit_(a1: pMem + 29, a2: "1.2.3", a3: 56) )
  {
    case -6:
      png_error(a1: (int *)pMem, a2: "zlib version error");
      break;
    case -4:
    case -2:
      png_error(a1: (int *)pMem, a2: "zlib memory error");
      break;
    case 0:
      break;
    default:
      png_error(a1: (int *)pMem, a2: "Unknown zlib error");
      break;
  }
  pMem[32] = pMem[43];
  pMem[33] = pMem[44];
  png_set_read_fn(a1: pMem, a2: 0, a3: 0);
  if ( _setjmp3(a1: pMem, a2: 0) != 0 )
    abort();
  return pMem;
}

//------------------------------------------------------------------------------
// Address: 0x101B3730
// Name: _png_read_info
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_read_info(unsigned int nSize, _DWORD *a2)
{
  unsigned __int8 v3; // al
  unsigned int v4; // edi
  int v5; // esi
  int v6; // eax
  bool v7; // zf
  const void *v8; // edx
  int v9; // eax
  int v10; // eax
  unsigned __int8 v11[4]; // [esp+4h] [ebp-4h] BYREF
  unsigned int nSizea; // [esp+Ch] [ebp+4h]

  if ( nSize != 0 )
  {
    v3 = *(_BYTE *)(nSize + 300);
    if ( v3 < 8u )
    {
      v4 = v3;
      v5 = 8 - v3;
      png_read_data(a1: nSize);
      *(_BYTE *)(nSize + 300) = 8;
      if ( png_sig_cmp(a1: a2 + 8, a2: v4, a3: v5) != 0 )
      {
        if ( v4 < 4 && png_sig_cmp(a1: a2 + 8, a2: v4, a3: v5 - 4) != 0 )
          png_error(a1: (int *)nSize, a2: "Not a PNG file");
        else
          png_error(a1: (int *)nSize, a2: "PNG file corrupted by ASCII conversion");
      }
      if ( v4 < 3 )
        *(_DWORD *)(nSize + 104) |= 0x1000u;
    }
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          while ( 1 )
          {
            while ( 1 )
            {
              png_read_data(a1: nSize);
              nSizea = png_get_uint_31(a1: nSize, a2: v11);
              png_reset_crc(a1: nSize);
              png_crc_read(a1: nSize, a2: nSize + 284, a3: 4);
              if ( memcmp((const void *)(nSize + 284), "IDAT", 4u) == 0 )
              {
                v6 = *(_DWORD *)(nSize + 104);
                if ( (v6 & 8) != 0 )
                  *(_DWORD *)(nSize + 104) = v6 | 0x2000;
              }
              if ( memcmp((const void *)(nSize + 284), "IHDR", 4u) != 0 )
                break;
              png_handle_IHDR(a1: nSize, (int)a2, a3: nSizea);
            }
            if ( memcmp((const void *)(nSize + 284), "IEND", 4u) != 0 )
              break;
            png_handle_IEND(a1: nSize, (int)a2, a3: nSizea);
          }
          v7 = png_handle_as_unknown(a1: nSize, a2: nSize + 284) == 0;
          v8 = (const void *)(nSize + 284);
          if ( v7 )
            break;
          if ( memcmp(v8, "IDAT", 4u) == 0 )
            *(_DWORD *)(nSize + 104) |= 4u;
          png_handle_unknown(a1: nSize, (int)a2, nSize: nSizea);
          if ( memcmp((const void *)(nSize + 284), "PLTE", 4u) == 0 )
          {
            *(_DWORD *)(nSize + 104) |= 2u;
          }
          else if ( memcmp((const void *)(nSize + 284), "IDAT", 4u) == 0 )
          {
            v9 = *(_DWORD *)(nSize + 104);
            if ( (v9 & 1) != 0 )
            {
              if ( *(_BYTE *)(nSize + 294) == 3 && (v9 & 2) == 0 )
                png_error(a1: (int *)nSize, a2: "Missing PLTE before IDAT");
            }
            else
            {
              png_error(a1: (int *)nSize, a2: "Missing IHDR before IDAT");
            }
            return;
          }
        }
        if ( memcmp(v8, "PLTE", 4u) != 0 )
          break;
        png_handle_PLTE(a1: nSize, (int)a2, a3: nSizea);
      }
      if ( memcmp((const void *)(nSize + 284), "IDAT", 4u) == 0 )
        break;
      if ( memcmp((const void *)(nSize + 284), "bKGD", 4u) == 0 )
      {
        png_handle_bKGD(a1: nSize, (int)a2, a3: nSizea);
      }
      else if ( memcmp((const void *)(nSize + 284), "cHRM", 4u) == 0 )
      {
        png_handle_cHRM(a1: nSize, (int)a2, a3: nSizea);
      }
      else if ( memcmp((const void *)(nSize + 284), "gAMA", 4u) == 0 )
      {
        png_handle_gAMA(a1: nSize, (int)a2, a3: nSizea);
      }
      else if ( memcmp((const void *)(nSize + 284), "hIST", 4u) == 0 )
      {
        png_handle_hIST(a1: nSize, (int)a2, a3: nSizea);
      }
      else if ( memcmp((const void *)(nSize + 284), "oFFs", 4u) == 0 )
      {
        png_handle_oFFs(a1: nSize, (int)a2, a3: nSizea);
      }
      else if ( memcmp((const void *)(nSize + 284), "pCAL", 4u) == 0 )
      {
        png_handle_pCAL(a1: nSize, (int)a2, a3: nSizea);
      }
      else if ( memcmp((const void *)(nSize + 284), "sCAL", 4u) == 0 )
      {
        png_handle_sCAL(endptr: (char *)nSize, (int)a2, a3: nSizea);
      }
      else if ( memcmp((const void *)(nSize + 284), "pHYs", 4u) == 0 )
      {
        png_handle_pHYs(a1: nSize, (int)a2, a3: nSizea);
      }
      else if ( memcmp((const void *)(nSize + 284), "sBIT", 4u) == 0 )
      {
        png_handle_sBIT(a1: nSize, (int)a2, a3: nSizea);
      }
      else if ( memcmp((const void *)(nSize + 284), "sRGB", 4u) == 0 )
      {
        png_handle_sRGB(a1: nSize, (int)a2, a3: nSizea);
      }
      else if ( memcmp((const void *)(nSize + 284), "iCCP", 4u) == 0 )
      {
        png_handle_iCCP(a1: nSize, (int)a2, a3: nSizea);
      }
      else if ( memcmp((const void *)(nSize + 284), "sPLT", 4u) == 0 )
      {
        png_handle_sPLT(a1: nSize, (int)a2, a3: nSizea);
      }
      else if ( memcmp((const void *)(nSize + 284), "tEXt", 4u) == 0 )
      {
        png_handle_tEXt(a1: nSize, a2, a3: nSizea);
      }
      else if ( memcmp((const void *)(nSize + 284), "tIME", 4u) == 0 )
      {
        png_handle_tIME(a1: nSize, a2, a3: nSizea);
      }
      else if ( memcmp((const void *)(nSize + 284), "tRNS", 4u) == 0 )
      {
        png_handle_tRNS(a1: nSize, (int)a2, a3: nSizea);
      }
      else if ( memcmp((const void *)(nSize + 284), "zTXt", 4u) == 0 )
      {
        png_handle_zTXt(a1: nSize, a2, a3: nSizea);
      }
      else
      {
        png_handle_unknown(a1: nSize, (int)a2, nSize: nSizea);
      }
    }
    v10 = *(_DWORD *)(nSize + 104);
    if ( (v10 & 1) != 0 )
    {
      if ( *(_BYTE *)(nSize + 294) == 3 && (v10 & 2) == 0 )
        png_error(a1: (int *)nSize, a2: "Missing PLTE before IDAT");
    }
    else
    {
      png_error(a1: (int *)nSize, a2: "Missing IHDR before IDAT");
    }
    *(_DWORD *)(nSize + 104) |= 4u;
    *(_DWORD *)(nSize + 268) = nSizea;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B4760
// Name: _png_read_update_info
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl png_read_update_info(int a1, int a2)
{
  int result; // eax

  if ( a1 != 0 )
  {
    if ( (*(_BYTE *)(a1 + 108) & 0x40) != 0 )
      png_warning(a1, a2: "Ignoring extra png_read_update_info() call; row buffer not reallocated");
    else
      png_read_start_row(a1);
    return png_read_transform_info(a1, a2);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B47B0
// Name: _png_read_row
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_read_row(int a1, unsigned __int8 *a2, unsigned __int8 *dst)
{
  int v3; // esi
  unsigned __int8 *v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // edi
  unsigned int v10; // eax
  unsigned int v11; // ecx
  int v12; // edx
  int v13; // eax
  unsigned __int8 *v14; // eax
  int v15; // ecx
  char v16; // dl
  unsigned __int8 v17; // al
  unsigned int v18; // eax
  unsigned __int8 *v19; // eax
  void (__cdecl *v20)(int, _DWORD, _DWORD); // eax

  v3 = a1;
  if ( a1 != 0 )
  {
    if ( (*(_BYTE *)(a1 + 108) & 0x40) == 0 )
      png_read_start_row(a1);
    if ( *(_BYTE *)(v3 + 291) != 0 && (*(_BYTE *)(v3 + 112) & 2) != 0 )
    {
      switch ( *(_BYTE *)(v3 + 292) )
      {
        case 0:
          if ( (*(_BYTE *)(v3 + 228) & 7) == 0 )
            goto LABEL_33;
          v4 = dst;
          if ( dst == nullptr )
            goto LABEL_11;
          v5 = 255;
          goto LABEL_10;
        case 1:
          if ( (*(_BYTE *)(v3 + 228) & 7) == 0 && *(_DWORD *)(v3 + 200) >= 5u )
            goto LABEL_33;
          if ( dst != nullptr )
            png_combine_row(a1: v3, dst, a3: 15);
          goto LABEL_11;
        case 2:
          v6 = *(_DWORD *)(v3 + 228);
          if ( (v6 & 7) == 4 )
            goto LABEL_33;
          if ( dst != nullptr && (v6 & 4) != 0 )
            goto LABEL_19;
          goto LABEL_11;
        case 3:
          if ( (*(_BYTE *)(v3 + 228) & 3) == 0 && *(_DWORD *)(v3 + 200) >= 3u )
            goto LABEL_33;
          v4 = dst;
          if ( dst == nullptr )
            goto LABEL_11;
          v5 = 51;
          goto LABEL_10;
        case 4:
          v7 = *(_DWORD *)(v3 + 228);
          if ( (v7 & 3) == 2 )
            goto LABEL_33;
          if ( dst == nullptr || (v7 & 2) == 0 )
            goto LABEL_11;
LABEL_19:
          png_combine_row(a1: v3, dst, a3: 255);
          png_read_finish_row(a1: v3);
          break;
        case 5:
          if ( (*(_BYTE *)(v3 + 228) & 1) == 0 && *(_DWORD *)(v3 + 200) >= 2u )
            goto LABEL_33;
          v4 = dst;
          if ( dst != nullptr )
          {
            v5 = 85;
LABEL_10:
            png_combine_row(a1: v3, dst: v4, a3: v5);
          }
LABEL_11:
          png_read_finish_row(a1: v3);
          break;
        case 6:
          if ( (*(_BYTE *)(v3 + 228) & 1) != 0 )
            goto LABEL_33;
          goto LABEL_11;
        default:
          goto LABEL_33;
      }
    }
    else
    {
LABEL_33:
      if ( (*(_BYTE *)(v3 + 104) & 4) == 0 )
        png_error(a1: (int *)v3, a2: "Invalid attempt to read row data");
      v8 = *(_DWORD *)(v3 + 220);
      *(_DWORD *)(v3 + 128) = *(_DWORD *)(v3 + 236);
      *(_DWORD *)(v3 + 132) = v8;
      v9 = v3 + 116;
      while ( 1 )
      {
        if ( *(_DWORD *)(v3 + 120) == 0 )
        {
          while ( *(_DWORD *)(v3 + 268) == 0 )
          {
            png_crc_finish(a1: v3, a2: 0);
            png_read_data(a1: v3);
            *(_DWORD *)(v3 + 268) = png_get_uint_31(a1: v3, a2: (unsigned __int8 *)&a1);
            png_reset_crc(a1: v3);
            png_crc_read(a1: v3, a2: v3 + 284, a3: 4);
            if ( memcmp((const void *)(v3 + 284), "IDAT", 4u) != 0 )
              png_error(a1: (int *)v3, a2: "Not enough image data");
          }
          v10 = *(_DWORD *)(v3 + 176);
          v11 = *(_DWORD *)(v3 + 268);
          v12 = *(_DWORD *)(v3 + 172);
          v9 = v3 + 116;
          *(_DWORD *)(v3 + 120) = v10;
          *(_DWORD *)(v3 + 116) = v12;
          if ( v10 > v11 )
            *(_DWORD *)(v3 + 120) = v11;
          png_crc_read(a1: v3, a2: v12, a3: *(_DWORD *)(v3 + 120));
          *(_DWORD *)(v3 + 268) -= *(_DWORD *)(v3 + 120);
        }
        v13 = inflate(a1: v9, a2: 1);
        if ( v13 == 1 )
          break;
        if ( v13 != 0 )
        {
          v14 = *(unsigned __int8 **)(v3 + 140);
          if ( v14 == nullptr )
            v14 = "Decompression error";
          png_error(a1: (int *)v3, a2: v14);
        }
        if ( *(_DWORD *)(v3 + 132) == 0 )
          goto LABEL_56;
      }
      if ( *(_DWORD *)(v3 + 132) != 0 || *(_DWORD *)(v3 + 120) != 0 || *(_DWORD *)(v3 + 268) != 0 )
        png_error(a1: (int *)v3, a2: "Extra compressed data");
      *(_DWORD *)(v3 + 104) |= 8u;
      *(_DWORD *)(v3 + 108) |= 0x20u;
LABEL_56:
      v15 = *(_DWORD *)(v3 + 224);
      v16 = *(_BYTE *)(v3 + 298);
      *(_BYTE *)(v3 + 264) = *(_BYTE *)(v3 + 294);
      *(_BYTE *)(v3 + 265) = *(_BYTE *)(v3 + 295);
      v17 = *(_BYTE *)(v3 + 297);
      *(_BYTE *)(v3 + 267) = v17;
      *(_DWORD *)(v3 + 256) = v15;
      *(_BYTE *)(v3 + 266) = v16;
      if ( v17 < 8u )
        v18 = (v15 * (unsigned int)v17 + 7) >> 3;
      else
        v18 = v15 * (v17 >> 3);
      *(_DWORD *)(v3 + 260) = v18;
      v19 = *(unsigned __int8 **)(v3 + 236);
      if ( *v19 != 0 )
        png_read_filter_row(a1: v3, a2: v3 + 256, a3: v19 + 1, a4: (_BYTE *)(*(_DWORD *)(v3 + 232) + 1), a5: *v19);
      png_memcpy_check(
        a1: v3,
        dst: *(unsigned __int8 **)(v3 + 232),
        src: *(unsigned __int8 **)(v3 + 236),
        count: *(_DWORD *)(v3 + 216) + 1);
      if ( (*(_BYTE *)(v3 + 560) & 4) != 0 && *(_BYTE *)(v3 + 568) == 64 )
        png_do_read_intrapixel(a1: v3 + 256, a2: *(_DWORD *)(v3 + 236) + 1);
      if ( *(_DWORD *)(v3 + 112) != 0 || (*(_DWORD *)(v3 + 108) & 0x400000) != 0 )
        png_do_read_transformations(a1: v3);
      if ( *(_BYTE *)(v3 + 291) != 0 && (*(_BYTE *)(v3 + 112) & 2) != 0 )
      {
        if ( *(_BYTE *)(v3 + 292) < 6u )
          png_do_read_interlace(a1: v3);
        if ( dst != nullptr )
          png_combine_row(a1: v3, dst, a3: *(&png_pass_dsp_mask + *(unsigned __int8 *)(v3 + 292)));
        if ( a2 != nullptr )
          png_combine_row(a1: v3, dst: a2, a3: png_pass_mask[*(unsigned __int8 *)(v3 + 292)]);
      }
      else
      {
        if ( a2 != nullptr )
          png_combine_row(a1: v3, dst: a2, a3: 255);
        if ( dst != nullptr )
          png_combine_row(a1: v3, dst, a3: 255);
      }
      png_read_finish_row(a1: v3);
      v20 = *(void (__cdecl **)(int, _DWORD, _DWORD))(v3 + 408);
      if ( v20 != nullptr )
        v20(a1: v3, a2: *(_DWORD *)(v3 + 228), a3: *(unsigned __int8 *)(v3 + 292));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B4CC0
// Name: _png_read_image
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_read_image(int a1, unsigned __int8 **a2)
{
  int v3; // eax
  int v4; // ebp
  unsigned __int8 **v5; // esi
  int j; // edi
  int i; // [esp+8h] [ebp+4h]

  if ( a1 != 0 )
  {
    v3 = png_set_interlace_handling(a1);
    v4 = *(_DWORD *)(a1 + 204);
    *(_DWORD *)(a1 + 208) = v4;
    if ( v3 > 0 )
    {
      for ( i = v3; i != 0; --i )
      {
        v5 = a2;
        if ( v4 != 0 )
        {
          for ( j = v4; j != 0; --j )
            png_read_row(a1, a2: *v5++, dst: nullptr);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B4D30
// Name: _png_read_end
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_read_end(char *endptr, _DWORD *a2)
{
  bool v3; // zf
  char *v4; // edx
  unsigned __int8 v5[4]; // [esp+4h] [ebp-4h] BYREF
  char *endptra; // [esp+Ch] [ebp+4h]

  if ( endptr != nullptr )
  {
    png_crc_finish(a1: (int)endptr, a2: 0);
    do
    {
      png_read_data(a1: (int)endptr);
      endptra = (char *)png_get_uint_31(a1: (int)endptr, a2: v5);
      png_reset_crc(a1: endptr);
      png_crc_read(a1: (int)endptr, a2: (int)(endptr + 284), a3: 4);
      if ( memcmp(endptr + 284, "IHDR", 4u) == 0 )
      {
        png_handle_IHDR(a1: (int)endptr, (int)a2, a3: (int)endptra);
      }
      else if ( memcmp(endptr + 284, "IEND", 4u) == 0 )
      {
        png_handle_IEND(a1: (int)endptr, (int)a2, a3: (unsigned int)endptra);
      }
      else
      {
        v3 = png_handle_as_unknown(a1: endptr, a2: endptr + 284) == 0;
        v4 = endptr + 284;
        if ( v3 )
        {
          if ( memcmp(v4, "IDAT", 4u) == 0 )
          {
            if ( endptra != nullptr || (*((_DWORD *)endptr + 26) & 0x2000) != 0 )
              png_error(a1: (int *)endptr, a2: "Too many IDAT's found");
            png_crc_finish(a1: (int)endptr, a2: (unsigned int)endptra);
          }
          else if ( memcmp(endptr + 284, "PLTE", 4u) == 0 )
          {
            png_handle_PLTE(a1: (int)endptr, (int)a2, a3: (signed int)endptra);
          }
          else if ( memcmp(endptr + 284, "bKGD", 4u) == 0 )
          {
            png_handle_bKGD(a1: (int)endptr, (int)a2, a3: (unsigned int)endptra);
          }
          else if ( memcmp(endptr + 284, "cHRM", 4u) == 0 )
          {
            png_handle_cHRM(a1: (int)endptr, (int)a2, a3: (unsigned int)endptra);
          }
          else if ( memcmp(endptr + 284, "gAMA", 4u) == 0 )
          {
            png_handle_gAMA(a1: (int)endptr, (int)a2, a3: (unsigned int)endptra);
          }
          else if ( memcmp(endptr + 284, "hIST", 4u) == 0 )
          {
            png_handle_hIST(a1: (int)endptr, (int)a2, a3: (unsigned int)endptra);
          }
          else if ( memcmp(endptr + 284, "oFFs", 4u) == 0 )
          {
            png_handle_oFFs(a1: (int)endptr, (int)a2, a3: (unsigned int)endptra);
          }
          else if ( memcmp(endptr + 284, "pCAL", 4u) == 0 )
          {
            png_handle_pCAL(a1: (int)endptr, (int)a2, a3: (unsigned int)endptra);
          }
          else if ( memcmp(endptr + 284, "sCAL", 4u) == 0 )
          {
            png_handle_sCAL(endptr, (int)a2, a3: (unsigned int)endptra);
          }
          else if ( memcmp(endptr + 284, "pHYs", 4u) == 0 )
          {
            png_handle_pHYs(a1: (int)endptr, (int)a2, a3: (unsigned int)endptra);
          }
          else if ( memcmp(endptr + 284, "sBIT", 4u) == 0 )
          {
            png_handle_sBIT(a1: (int)endptr, (int)a2, a3: (unsigned int)endptra);
          }
          else if ( memcmp(endptr + 284, "sRGB", 4u) == 0 )
          {
            png_handle_sRGB(a1: (int)endptr, (int)a2, a3: (unsigned int)endptra);
          }
          else if ( memcmp(endptr + 284, "iCCP", 4u) == 0 )
          {
            png_handle_iCCP(a1: (unsigned int)endptr, (int)a2, a3: (unsigned int)endptra);
          }
          else if ( memcmp(endptr + 284, "sPLT", 4u) == 0 )
          {
            png_handle_sPLT(a1: (int)endptr, (int)a2, a3: (unsigned int)endptra);
          }
          else if ( memcmp(endptr + 284, "tEXt", 4u) == 0 )
          {
            png_handle_tEXt(a1: (int)endptr, a2, a3: (int)endptra);
          }
          else if ( memcmp(endptr + 284, "tIME", 4u) == 0 )
          {
            png_handle_tIME(a1: (int)endptr, a2, a3: (unsigned int)endptra);
          }
          else if ( memcmp(endptr + 284, "tRNS", 4u) == 0 )
          {
            png_handle_tRNS(a1: (int)endptr, (int)a2, a3: (unsigned int)endptra);
          }
          else if ( memcmp(endptr + 284, "zTXt", 4u) == 0 )
          {
            png_handle_zTXt(a1: (int)endptr, a2, a3: (int)endptra);
          }
          else
          {
            png_handle_unknown(a1: (int)endptr, (int)a2, nSize: (unsigned int)endptra);
          }
        }
        else
        {
          if ( memcmp(v4, "IDAT", 4u) == 0 && (endptra != nullptr || (*((_DWORD *)endptr + 26) & 0x2000) != 0) )
            png_error(a1: (int *)endptr, a2: "Too many IDAT's found");
          png_handle_unknown(a1: (int)endptr, (int)a2, nSize: (unsigned int)endptra);
          if ( memcmp(endptr + 284, "PLTE", 4u) == 0 )
            *((_DWORD *)endptr + 26) |= 2u;
        }
      }
    }
    while ( (endptr[104] & 0x10) == 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B5BB0
// Name: _png_read_destroy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_read_destroy(void **dst, int a2, int a3)
{
  int v3; // esi
  int i; // edi
  int v5; // esi
  int j; // edi
  int v7; // esi
  int k; // edi
  void *v9; // eax
  void *v10; // ebp
  void *v11; // esi
  void *v12; // edi
  _BYTE v13[64]; // [esp+10h] [ebp-40h] BYREF
  int v14; // [esp+58h] [ebp+8h]

  if ( a2 != 0 )
    png_info_destroy(a1: dst, a2);
  if ( a3 != 0 )
    png_info_destroy(a1: dst, a2: a3);
  png_free(a1: (int)dst, pMem: dst[43]);
  png_free(a1: (int)dst, pMem: dst[147]);
  png_free(a1: (int)dst, pMem: dst[58]);
  png_free(a1: (int)dst, pMem: dst[123]);
  png_free(a1: (int)dst, pMem: dst[124]);
  png_free(a1: (int)dst, pMem: dst[89]);
  png_free(a1: (int)dst, pMem: dst[90]);
  png_free(a1: (int)dst, pMem: dst[91]);
  if ( ((unsigned int)dst[133] & 0x1000) != 0 )
    png_zfree(a1: dst, a2: dst[69]);
  dst[133] = (void *)((unsigned int)dst[133] & 0xFFFFEFFF);
  if ( ((unsigned int)dst[133] & 0x2000) != 0 )
    png_free(a1: (int)dst, pMem: dst[98]);
  dst[133] = (void *)((unsigned int)dst[133] & 0xFFFFDFFF);
  if ( ((unsigned __int8)dst[133] & 8) != 0 )
    png_free(a1: (int)dst, pMem: dst[125]);
  dst[133] = (void *)((unsigned int)dst[133] & 0xFFFFFFF7);
  if ( dst[92] != nullptr )
  {
    v3 = 1 << (8 - *((_BYTE *)dst + 344));
    for ( i = 0; i < v3; ++i )
      png_free(a1: (int)dst, pMem: *((void **)dst[92] + i));
    png_free(a1: (int)dst, pMem: dst[92]);
  }
  if ( dst[93] != nullptr )
  {
    v5 = 1 << (8 - *((_BYTE *)dst + 344));
    for ( j = 0; j < v5; ++j )
      png_free(a1: (int)dst, pMem: *((void **)dst[93] + j));
    png_free(a1: (int)dst, pMem: dst[93]);
  }
  if ( dst[94] != nullptr )
  {
    v7 = 1 << (8 - *((_BYTE *)dst + 344));
    for ( k = 0; k < v7; ++k )
      png_free(a1: (int)dst, pMem: *((void **)dst[94] + k));
    png_free(a1: (int)dst, pMem: dst[94]);
  }
  png_free(a1: (int)dst, pMem: dst[132]);
  inflateEnd(a1: dst + 29);
  png_free(a1: (int)dst, pMem: dst[108]);
  png_free(a1: (int)dst, pMem: dst[121]);
  v9 = dst[146];
  v10 = dst[18];
  qmemcpy(v13, dst, sizeof(v13));
  v11 = dst[16];
  v12 = dst[17];
  v14 = (int)v9;
  memset((unsigned __int8 *)dst, value: 0, count: 0x27Cu);
  dst[16] = v11;
  dst[17] = v12;
  dst[146] = (void *)v14;
  qmemcpy(dst, v13, 64);
  dst[18] = v10;
}

//------------------------------------------------------------------------------
// Address: 0x101B5E40
// Name: _png_create_read_struct
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void **__cdecl png_create_read_struct(char *a1, int a2, int a3, int a4)
{
  return png_create_read_struct_2(a1, a2, a3, a4, a5: 0, a6: nullptr, a7: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101B5E70
// Name: _png_destroy_read_struct
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_destroy_read_struct(int *a1, void **a2, void **a3)
{
  int v3; // esi
  void *v4; // edi
  void (__cdecl *v5)(_BYTE *, void *); // ebx
  int v6; // ebp
  void *pMem; // [esp+10h] [ebp-4h]

  v3 = 0;
  v4 = nullptr;
  pMem = nullptr;
  if ( a1 != nullptr )
    v3 = *a1;
  if ( a2 != nullptr )
    v4 = *a2;
  if ( a3 != nullptr )
    pMem = *a3;
  v5 = *(void (__cdecl **)(_BYTE *, void *))(v3 + 584);
  v6 = *(_DWORD *)(v3 + 576);
  png_read_destroy(dst: (void **)v3, a2: (int)v4, a3: (int)pMem);
  if ( v4 != nullptr )
  {
    png_free_data(a1: v3, a2: v4, a3: 0x4000, a4: -1);
    png_destroy_struct_2(pMem: v4, a2: v5, a3: v6);
    *a2 = nullptr;
  }
  if ( pMem != nullptr )
  {
    png_free_data(a1: v3, a2: pMem, a3: 0x4000, a4: -1);
    png_destroy_struct_2(pMem, a2: v5, a3: v6);
    *a3 = nullptr;
  }
  png_destroy_struct_2(pMem: (void *)v3, a2: v5, a3: v6);
  *a1 = 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B5F30
// Name: _png_set_strip_16
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl png_set_strip_16(int a1)
{
  int result; // eax

  result = a1;
  if ( a1 != 0 )
    *(_DWORD *)(a1 + 112) |= 0x400u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B5F40
// Name: _png_set_gamma
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_set_gamma(int a1, double a2, double a3)
{
  char v3; // al

  if ( a1 != 0 )
  {
    if ( fabs(a2 * a3 - 1.0) > 0.05 || ((v3 = *(_BYTE *)(a1 + 294)) & 4) != 0 || v3 == 3 )
      *(_DWORD *)(a1 + 112) |= 0x2000u;
    *(float *)(a1 + 348) = a3;
    *(float *)(a1 + 352) = a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B5F90
// Name: _png_set_palette_to_rgb
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl png_set_palette_to_rgb(int a1)
{
  int result; // eax

  result = a1;
  if ( a1 != 0 )
    *(_DWORD *)(a1 + 112) |= 0x2001000u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B5FA0
// Name: _png_set_tRNS_to_alpha
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl png_set_tRNS_to_alpha(int a1)
{
  *(_DWORD *)(a1 + 112) |= 0x2001000u;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x101B5FB0
// Name: _png_set_gray_to_rgb
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl png_set_gray_to_rgb(int a1)
{
  *(_DWORD *)(a1 + 112) |= 0x4000u;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x101B5FC0
// Name: _png_read_transform_info
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl png_read_transform_info(int a1, int a2)
{
  int v2; // edx
  char v3; // al
  char v4; // al
  char v5; // al
  char v6; // al
  char v7; // al
  unsigned __int8 v8; // al
  unsigned __int8 v9; // al
  unsigned __int8 v10; // al
  unsigned int result; // eax

  v2 = *(_DWORD *)(a1 + 112);
  if ( (v2 & 0x1000) != 0 )
  {
    v3 = *(_BYTE *)(a2 + 25);
    if ( v3 == 3 )
    {
      if ( *(_WORD *)(a1 + 282) != 0 && (v2 & 0x2000000) != 0 )
        *(_BYTE *)(a2 + 25) = 6;
      else
        *(_BYTE *)(a2 + 25) = 2;
    }
    else
    {
      if ( *(_WORD *)(a1 + 282) != 0 )
      {
        if ( (v2 & 0x2000000) != 0 )
          v4 = v3 | 4;
        else
          v4 = v3 | 2;
        *(_BYTE *)(a2 + 25) = v4;
      }
      if ( *(_BYTE *)(a2 + 24) >= 8u )
        goto LABEL_14;
    }
    *(_BYTE *)(a2 + 24) = 8;
LABEL_14:
    *(_WORD *)(a2 + 22) = 0;
  }
  if ( *(char *)(a1 + 112) < 0 )
  {
    *(_BYTE *)(a2 + 25) &= ~4u;
    *(_WORD *)(a2 + 22) = 0;
    *(_DWORD *)(a2 + 90) = *(_DWORD *)(a1 + 312);
    *(_DWORD *)(a2 + 94) = *(_DWORD *)(a1 + 316);
    *(_WORD *)(a2 + 98) = *(_WORD *)(a1 + 320);
  }
  if ( (*(_DWORD *)(a1 + 112) & 0x2000) != 0 )
  {
    *(float *)(a2 + 40) = *(float *)(a1 + 348);
    *(_DWORD *)(a2 + 252) = *(_DWORD *)(a1 + 564);
  }
  if ( (*(_DWORD *)(a1 + 112) & 0x400) != 0 && *(_BYTE *)(a2 + 24) == 16 )
    *(_BYTE *)(a2 + 24) = 8;
  if ( (*(_DWORD *)(a1 + 112) & 0x4000) != 0 )
    *(_BYTE *)(a2 + 25) |= 2u;
  if ( (*(_DWORD *)(a1 + 112) & 0x600000) != 0 )
    *(_BYTE *)(a2 + 25) &= ~2u;
  if ( (*(_BYTE *)(a1 + 112) & 0x40) != 0 )
  {
    v5 = *(_BYTE *)(a2 + 25);
    if ( (v5 == 2 || v5 == 6) && *(_DWORD *)(a1 + 492) != 0 && *(_BYTE *)(a2 + 24) == 8 )
      *(_BYTE *)(a2 + 25) = 3;
  }
  if ( (*(_BYTE *)(a1 + 112) & 4) != 0 && *(_BYTE *)(a2 + 24) < 8u )
    *(_BYTE *)(a2 + 24) = 8;
  v6 = *(_BYTE *)(a2 + 25);
  if ( v6 == 3 || (v6 & 2) == 0 )
    *(_BYTE *)(a2 + 29) = 1;
  else
    *(_BYTE *)(a2 + 29) = 3;
  if ( (*(_DWORD *)(a1 + 108) & 0x400000) != 0 )
    *(_BYTE *)(a2 + 25) = v6 & 0xFB;
  v7 = *(_BYTE *)(a2 + 25);
  if ( (v7 & 4) != 0 )
    ++*(_BYTE *)(a2 + 29);
  if ( (*(_DWORD *)(a1 + 112) & 0x8000) != 0 && (v7 == 2 || v7 == 0) )
  {
    ++*(_BYTE *)(a2 + 29);
    if ( (*(_DWORD *)(a1 + 112) & 0x1000000) != 0 )
      *(_BYTE *)(a2 + 25) = v7 | 4;
  }
  if ( (*(_DWORD *)(a1 + 112) & 0x100000) != 0 )
  {
    v8 = *(_BYTE *)(a1 + 100);
    if ( *(_BYTE *)(a2 + 24) < v8 )
      *(_BYTE *)(a2 + 24) = v8;
    v9 = *(_BYTE *)(a1 + 101);
    if ( *(_BYTE *)(a2 + 29) < v9 )
      *(_BYTE *)(a2 + 29) = v9;
  }
  v10 = *(_BYTE *)(a2 + 29) * *(_BYTE *)(a2 + 24);
  *(_BYTE *)(a2 + 30) = v10;
  if ( v10 < 8u )
    result = (*(_DWORD *)a2 * (unsigned int)v10 + 7) >> 3;
  else
    result = *(_DWORD *)a2 * (v10 >> 3);
  *(_DWORD *)(a2 + 12) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B6170
// Name: _png_do_unpack
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl png_do_unpack(int *a1, int a2)
{
  int *v2; // edx
  int v3; // eax
  int v4; // eax
  int v5; // edi
  int v6; // eax
  _BYTE *v7; // esi
  _BYTE *v8; // ebp
  int v9; // eax
  _BYTE *v10; // esi
  _BYTE *v11; // ebp
  int v12; // eax
  int v13; // edx
  _BYTE *v14; // esi
  _BYTE *v15; // ebp
  int v16; // eax
  int v17; // edx
  char v18; // cl
  int v20; // [esp+4h] [ebp+4h]

  v2 = a1;
  LOBYTE(v3) = *((_BYTE *)a1 + 9);
  if ( (unsigned __int8)v3 < 8u )
  {
    v4 = (unsigned __int8)v3 - 1;
    v5 = *a1;
    if ( v4 != 0 )
    {
      v6 = v4 - 1;
      if ( v6 != 0 )
      {
        if ( v6 == 2 )
        {
          v7 = (_BYTE *)(a2 + ((unsigned int)(v5 - 1) >> 1));
          v8 = (_BYTE *)(v5 + a2 - 1);
          v9 = 4 * (1 - ((v5 - 1) & 1));
          if ( v5 != 0 )
          {
            v20 = *a1;
            do
            {
              *v8 = (*v7 >> v9) & 0xF;
              if ( v9 == 4 )
              {
                v9 = 0;
                --v7;
              }
              else
              {
                v9 = 4;
              }
              --v8;
              --v20;
            }
            while ( v20 != 0 );
          }
        }
        goto LABEL_26;
      }
      v10 = (_BYTE *)(a2 + ((unsigned int)(v5 - 1) >> 2));
      v11 = (_BYTE *)(v5 + a2 - 1);
      v12 = 2 * (3 - ((v5 - 1) & 3));
      if ( v5 != 0 )
      {
        v13 = *a1;
        do
        {
          *v11 = (*v10 >> v12) & 3;
          if ( v12 == 6 )
          {
            v12 = 0;
            --v10;
          }
          else
          {
            v12 += 2;
          }
          --v11;
          --v13;
        }
        while ( v13 != 0 );
LABEL_25:
        v2 = a1;
      }
    }
    else
    {
      v14 = (_BYTE *)(a2 + ((unsigned int)(v5 - 1) >> 3));
      v15 = (_BYTE *)(v5 + a2 - 1);
      v16 = 7 - ((v5 - 1) & 7);
      if ( v5 != 0 )
      {
        v17 = *a1;
        do
        {
          *v15 = (*v14 >> v16) & 1;
          if ( v16 == 7 )
          {
            v16 = 0;
            --v14;
          }
          else
          {
            ++v16;
          }
          --v15;
          --v17;
        }
        while ( v17 != 0 );
        goto LABEL_25;
      }
    }
LABEL_26:
    v18 = 8 * *((_BYTE *)v2 + 10);
    v3 = v5 * *((unsigned __int8 *)v2 + 10);
    *((_BYTE *)v2 + 9) = 8;
    *((_BYTE *)v2 + 11) = v18;
    v2[1] = v3;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101B62B0
// Name: _png_do_unshift
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_do_unshift(int *a1, _BYTE *a2, unsigned __int8 *a3)
{
  char v3; // bl
  int v4; // ebp
  __int16 v5; // si
  int v6; // eax
  int v7; // esi
  int v8; // edi
  int v9; // eax
  int v10; // edi
  int v11; // eax
  int v12; // edx
  _BYTE *i; // eax
  int v14; // edi
  char v15; // dl
  _BYTE *v16; // esi
  char j; // al
  char v18; // bl
  _BYTE *v19; // esi
  unsigned int v20; // ebp
  unsigned int k; // ebx
  int v22; // edx
  unsigned __int8 *v23; // esi
  unsigned int v24; // ebp
  unsigned int m; // ebx
  int v26; // edx
  unsigned __int16 v27; // ax
  __int16 v28; // ax
  _DWORD v29[4]; // [esp+4h] [ebp-10h]

  v3 = *((_BYTE *)a1 + 8);
  if ( v3 != 3 )
  {
    v4 = *a1;
    v5 = 0;
    if ( (v3 & 2) != 0 )
    {
      v6 = *((unsigned __int8 *)a1 + 9);
      v7 = a3[1];
      v29[0] = v6 - *a3;
      v8 = v6 - v7;
      v9 = v6 - a3[2];
      v5 = 0;
      v29[1] = v8;
      v29[2] = v9;
      v10 = 3;
    }
    else
    {
      v29[0] = *((unsigned __int8 *)a1 + 9) - a3[3];
      v10 = 1;
    }
    if ( (v3 & 4) != 0 )
      v29[v10++] = *((unsigned __int8 *)a1 + 9) - a3[4];
    v11 = 0;
    if ( v10 > 0 )
    {
      do
      {
        if ( (int)v29[v11] > 0 )
          v5 = 1;
        else
          v29[v11] = 0;
        ++v11;
      }
      while ( v11 < v10 );
      if ( v5 != 0 )
      {
        switch ( *((_BYTE *)a1 + 9) )
        {
          case 2:
            v12 = a1[1];
            for ( i = a2; v12 != 0; --v12 )
            {
              *i = (*i >> 1) & 0x55;
              ++i;
            }
            break;
          case 4:
            v14 = a1[1];
            v15 = v29[0];
            v16 = a2;
            for ( j = (15 >> SLOBYTE(v29[0])) | (240 >> SLOBYTE(v29[0])) & 0xF0; v14 != 0; *(v16 - 1) = j & v18 )
            {
              v18 = *v16++ >> v15;
              --v14;
            }
            break;
          case 8:
            v19 = a2;
            v20 = v10 * v4;
            for ( k = 0; k < v20; *(v19 - 1) >>= LOBYTE(v29[v22]) )
            {
              v22 = k % v10;
              ++k;
              ++v19;
            }
            break;
          case 0x10:
            v23 = a2;
            v24 = v10 * v4;
            for ( m = 0; m < v24; *(v23 - 1) = v28 )
            {
              v26 = m % v10;
              v27 = v23[1] + (*v23 << 8);
              ++m;
              v23 += 2;
              v28 = v27 >> LOWORD(v29[v26]);
              *(v23 - 2) = HIBYTE(v28);
            }
            break;
          default:
            return;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B6490
// Name: _png_do_chop
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_do_chop(int a1, _BYTE *a2)
{
  _BYTE *v2; // eax
  _BYTE *v3; // ecx
  int v4; // edi
  char v5; // cl
  int v6; // edx

  if ( *(_BYTE *)(a1 + 9) == 16 )
  {
    v2 = a2;
    v3 = a2;
    if ( *(_DWORD *)a1 * *(unsigned __int8 *)(a1 + 10) != 0 )
    {
      v4 = *(_DWORD *)a1 * *(unsigned __int8 *)(a1 + 10);
      do
      {
        *v3 = *v2;
        v2 += 2;
        ++v3;
        --v4;
      }
      while ( v4 != 0 );
    }
    v5 = 8 * *(_BYTE *)(a1 + 10);
    v6 = *(_DWORD *)a1 * *(unsigned __int8 *)(a1 + 10);
    *(_BYTE *)(a1 + 9) = 8;
    *(_BYTE *)(a1 + 11) = v5;
    *(_DWORD *)(a1 + 4) = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B64E0
// Name: _png_do_read_swap_alpha
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_BYTE *__cdecl png_do_read_swap_alpha(int *a1, int a2)
{
  _BYTE *result; // eax
  char v3; // cl
  int v4; // edx
  int v5; // eax
  _BYTE *v6; // ecx
  int v7; // esi
  char v8; // dl
  _BYTE *v9; // eax
  char v10; // bl
  char v11; // bl
  _BYTE *v12; // ecx
  char v13; // bl
  _BYTE *v14; // ecx
  int v15; // esi
  char v16; // dl
  _BYTE *v17; // eax
  char v18; // bl
  _BYTE *v19; // ecx
  char v20; // bl
  char v21; // bl
  char v22; // bl
  int v23; // eax
  _BYTE *v24; // ecx
  int v25; // esi
  char v26; // dl
  _BYTE *v27; // eax
  char v28; // bl
  _BYTE *v29; // ecx
  _BYTE *v30; // ecx
  int v31; // esi
  char v32; // dl
  _BYTE *v33; // eax
  char v34; // bl
  _BYTE *v35; // ecx
  char v36; // bl
  char v37; // [esp+Dh] [ebp+5h]
  char v38; // [esp+Dh] [ebp+5h]

  result = a1;
  v3 = *((_BYTE *)a1 + 8);
  v4 = *a1;
  if ( v3 == 6 )
  {
    v5 = a1[1];
    if ( *((_BYTE *)a1 + 9) == 8 )
    {
      result = (_BYTE *)(a2 + v5);
      v6 = result;
      if ( v4 != 0 )
      {
        v7 = *a1;
        do
        {
          v8 = *(result - 1);
          v9 = result - 1;
          v10 = *--v9;
          *(v6 - 1) = v10;
          v11 = *--v9;
          v12 = v6 - 2;
          *v12 = v11;
          v13 = *(v9 - 1);
          result = v9 - 1;
          *--v12 = v13;
          v6 = v12 - 1;
          --v7;
          *v6 = v8;
        }
        while ( v7 != 0 );
      }
    }
    else
    {
      result = (_BYTE *)(a2 + v5);
      v14 = result;
      if ( v4 != 0 )
      {
        v15 = *a1;
        do
        {
          v16 = *(result - 1);
          v17 = result - 1;
          v18 = *(v17 - 1);
          v17 -= 2;
          v37 = v18;
          *(v14 - 1) = *v17;
          v19 = v14 - 1;
          *(v19 - 1) = *--v17;
          *(--v19 - 1) = *(v17 - 1);
          v20 = *(--v17 - 1);
          --v19;
          --v17;
          *(v19 - 1) = v20;
          v21 = *--v17;
          v19 -= 2;
          *v19 = v21;
          v22 = *(v17 - 1);
          result = v17 - 1;
          *--v19 = v22;
          *--v19 = v16;
          v14 = v19 - 1;
          --v15;
          *v14 = v37;
        }
        while ( v15 != 0 );
      }
    }
  }
  else if ( v3 == 4 )
  {
    v23 = a1[1];
    if ( *((_BYTE *)a1 + 9) == 8 )
    {
      result = (_BYTE *)(a2 + v23);
      v24 = result;
      if ( v4 != 0 )
      {
        v25 = *a1;
        do
        {
          v26 = *(result - 1);
          v27 = result - 1;
          v28 = *(v27 - 1);
          result = v27 - 1;
          v29 = v24 - 1;
          *v29 = v28;
          v24 = v29 - 1;
          --v25;
          *v24 = v26;
        }
        while ( v25 != 0 );
      }
    }
    else
    {
      result = (_BYTE *)(a2 + v23);
      v30 = result;
      if ( v4 != 0 )
      {
        v31 = *a1;
        do
        {
          v32 = *(result - 1);
          v33 = result - 1;
          v34 = *(v33 - 1);
          v33 -= 2;
          v38 = v34;
          v35 = v30 - 1;
          *v35 = *v33;
          v36 = *(v33 - 1);
          result = v33 - 1;
          *--v35 = v36;
          *--v35 = v32;
          v30 = v35 - 1;
          --v31;
          *v30 = v38;
        }
        while ( v31 != 0 );
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B6660
// Name: _png_do_read_invert_alpha
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_BYTE *__cdecl png_do_read_invert_alpha(int *a1, int a2)
{
  _BYTE *result; // eax
  char v3; // cl
  int v4; // edx
  int v5; // eax
  _BYTE *v6; // eax
  char v7; // cl
  int v8; // esi
  _BYTE *v9; // ecx
  _BYTE *v10; // eax
  char v11; // dl
  int v12; // eax
  _BYTE *v13; // ecx
  int v14; // esi
  _BYTE *v15; // eax
  _BYTE *v16; // ecx
  char v17; // dl
  int v18; // esi
  _BYTE *v19; // ecx
  _BYTE *v20; // eax
  char v21; // dl

  result = a1;
  v3 = *((_BYTE *)a1 + 8);
  v4 = *a1;
  if ( v3 == 6 )
  {
    v5 = a1[1];
    if ( *((_BYTE *)a1 + 9) == 8 )
    {
      for ( result = (_BYTE *)(a2 + v5); v4 != 0; result[3] = v7 )
      {
        v6 = result - 1;
        v7 = -1 - *v6;
        result = v6 - 3;
        --v4;
      }
    }
    else
    {
      result = (_BYTE *)(a2 + v5);
      if ( v4 != 0 )
      {
        v8 = *a1;
        do
        {
          v9 = result - 1;
          *v9 = -1 - *v9;
          v10 = result - 2;
          v11 = -1 - *v10;
          result = v10 - 6;
          --v8;
          *(v9 - 1) = v11;
        }
        while ( v8 != 0 );
      }
    }
  }
  else if ( v3 == 4 )
  {
    v12 = a1[1];
    if ( *((_BYTE *)a1 + 9) == 8 )
    {
      result = (_BYTE *)(a2 + v12);
      v13 = result;
      if ( v4 != 0 )
      {
        v14 = *a1;
        do
        {
          v15 = result - 1;
          v16 = v13 - 1;
          *v16 = -1 - *v15;
          v17 = *(v15 - 1);
          result = v15 - 1;
          v13 = v16 - 1;
          --v14;
          *v13 = v17;
        }
        while ( v14 != 0 );
      }
    }
    else
    {
      result = (_BYTE *)(a2 + v12);
      if ( v4 != 0 )
      {
        v18 = *a1;
        do
        {
          v19 = result - 1;
          *v19 = -1 - *v19;
          v20 = result - 2;
          v21 = -1 - *v20;
          result = v20 - 2;
          --v18;
          *(v19 - 1) = v21;
        }
        while ( v18 != 0 );
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B6740
// Name: _png_do_read_filler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl png_do_read_filler(int a1, int a2, unsigned int a3, char a4)
{
  _BYTE *v5; // eax
  unsigned int v6; // esi
  unsigned int v7; // ebx
  int v8; // edi
  unsigned int v9; // ecx
  _BYTE *v10; // eax
  char v11; // bl
  unsigned int v12; // ecx
  char v13; // bl
  _BYTE *v14; // eax
  int v15; // edi
  _BYTE *v16; // eax
  char v17; // cl
  int v18; // edi
  char v19; // cl
  bool v20; // zf
  char v21; // cl
  int v22; // edi
  _BYTE *v23; // eax
  char v24; // cl
  unsigned int v25; // edi
  unsigned int v26; // ecx
  char v27; // bl
  unsigned int v28; // edi
  _BYTE *v29; // eax
  char v30; // bl
  char v31; // bl
  unsigned int v32; // ecx
  char v33; // bl
  unsigned int v34; // edi
  char v35; // bl
  _BYTE *v36; // eax
  char v37; // bl
  int v38; // ecx
  unsigned int v39; // edi
  _BYTE *v40; // eax
  int v41; // ecx
  char v42; // bl
  char v43; // bl
  char v44; // bl
  char v45; // bl
  unsigned int v46; // edi
  int v47; // ecx
  _BYTE *v48; // eax
  char v49; // bl
  char v50; // bl
  unsigned int v52; // [esp+14h] [ebp+4h]
  unsigned int v53; // [esp+14h] [ebp+4h]

  LOBYTE(v5) = *(_BYTE *)(a1 + 8);
  v6 = *(_DWORD *)a1;
  v7 = a3 >> 8;
  if ( (_BYTE)v5 != 0 )
  {
    if ( (_BYTE)v5 == 2 )
    {
      LOBYTE(v5) = *(_BYTE *)(a1 + 9);
      if ( (_BYTE)v5 == 8 )
      {
        v25 = v6 + a2 + 2 * v6;
        v5 = (_BYTE *)(v25 + v6);
        if ( a4 >= 0 )
        {
          if ( v6 != 0 )
          {
            v32 = *(_DWORD *)a1;
            do
            {
              v33 = *(_BYTE *)(v25 - 1);
              v34 = v25 - 1;
              *(v5 - 1) = v33;
              v35 = *(_BYTE *)--v34;
              v36 = v5 - 2;
              *v36 = v35;
              v37 = *(_BYTE *)(v34 - 1);
              v25 = v34 - 1;
              *--v36 = v37;
              v5 = v36 - 1;
              --v32;
              *v5 = a3;
            }
            while ( v32 != 0 );
          }
        }
        else
        {
          if ( v6 > 1 )
          {
            v26 = v6 - 1;
            do
            {
              *(v5 - 1) = a3;
              v27 = *(_BYTE *)(v25 - 1);
              v28 = v25 - 1;
              v29 = v5 - 2;
              *v29 = v27;
              v30 = *(_BYTE *)--v28;
              *--v29 = v30;
              v31 = *(_BYTE *)(v28 - 1);
              v25 = v28 - 1;
              v5 = v29 - 1;
              --v26;
              *v5 = v31;
            }
            while ( v26 != 0 );
          }
          *(v5 - 1) = a3;
        }
        *(_BYTE *)(a1 + 10) = 4;
        *(_BYTE *)(a1 + 11) = 32;
        *(_DWORD *)(a1 + 4) = 4 * v6;
      }
      else if ( (_BYTE)v5 == 16 )
      {
        v38 = a2 + 6 * v6;
        v5 = (_BYTE *)(v38 + 2 * v6);
        if ( a4 >= 0 )
        {
          if ( v6 != 0 )
          {
            v46 = *(_DWORD *)a1;
            do
            {
              *(v5 - 1) = *(_BYTE *)(v38 - 1);
              v47 = v38 - 1;
              v48 = v5 - 1;
              *(v48 - 1) = *(_BYTE *)--v47;
              *(--v48 - 1) = *(_BYTE *)--v47;
              *(--v48 - 1) = *(_BYTE *)(v47 - 1);
              v49 = *(_BYTE *)(--v47 - 1);
              --v48;
              --v47;
              *(v48 - 1) = v49;
              v50 = *(_BYTE *)(v47 - 1);
              v38 = v47 - 1;
              v48 -= 2;
              *v48-- = v50;
              *v48 = BYTE1(a3);
              v5 = v48 - 1;
              --v46;
              *v5 = a3;
            }
            while ( v46 != 0 );
          }
        }
        else
        {
          if ( v6 > 1 )
          {
            v39 = v6 - 1;
            do
            {
              *(v5 - 1) = v7;
              v40 = v5 - 1;
              *--v40 = a3;
              *(v40 - 1) = *(_BYTE *)(v38 - 1);
              v41 = v38 - 1;
              *(--v40 - 1) = *(_BYTE *)(v41 - 1);
              v42 = *(_BYTE *)(--v41 - 1);
              --v40;
              --v41;
              *(v40 - 1) = v42;
              v43 = *(_BYTE *)(v41 - 1);
              --v40;
              --v41;
              *(v40 - 1) = v43;
              v44 = *(_BYTE *)--v41;
              v40 -= 2;
              *v40 = v44;
              v45 = *(_BYTE *)(v41 - 1);
              v38 = v41 - 1;
              v5 = v40 - 1;
              --v39;
              *v5 = v45;
              LOBYTE(v7) = BYTE1(a3);
            }
            while ( v39 != 0 );
          }
          *--v5 = v7;
          *(v5 - 1) = a3;
        }
        *(_BYTE *)(a1 + 11) = 64;
        *(_BYTE *)(a1 + 10) = 4;
        *(_DWORD *)(a1 + 4) = 8 * v6;
      }
    }
  }
  else
  {
    LOBYTE(v5) = *(_BYTE *)(a1 + 9);
    if ( (_BYTE)v5 == 8 )
    {
      v8 = v6 + a2;
      v5 = (_BYTE *)(v6 + a2 + v6);
      if ( a4 >= 0 )
      {
        if ( v6 != 0 )
        {
          v12 = *(_DWORD *)a1;
          do
          {
            v13 = *(_BYTE *)--v8;
            v14 = v5 - 1;
            *v14 = v13;
            v5 = v14 - 1;
            --v12;
            *v5 = a3;
          }
          while ( v12 != 0 );
        }
        *(_BYTE *)(a1 + 10) = 2;
        *(_BYTE *)(a1 + 11) = 16;
        *(_DWORD *)(a1 + 4) = 2 * v6;
      }
      else
      {
        if ( v6 > 1 )
        {
          v9 = v6 - 1;
          do
          {
            v10 = v5 - 1;
            *v10 = a3;
            v11 = *(_BYTE *)--v8;
            v5 = v10 - 1;
            --v9;
            *v5 = v11;
          }
          while ( v9 != 0 );
        }
        *(v5 - 1) = a3;
        *(_BYTE *)(a1 + 10) = 2;
        *(_BYTE *)(a1 + 11) = 16;
        *(_DWORD *)(a1 + 4) = 2 * v6;
      }
    }
    else if ( (_BYTE)v5 == 16 )
    {
      v15 = a2 + 2 * v6;
      v5 = (_BYTE *)(v15 + 2 * v6);
      if ( a4 >= 0 )
      {
        if ( v6 != 0 )
        {
          v53 = *(_DWORD *)a1;
          do
          {
            v21 = *(_BYTE *)(v15 - 1);
            v22 = v15 - 1;
            v23 = v5 - 1;
            *v23 = v21;
            v24 = *(_BYTE *)(v22 - 1);
            v15 = v22 - 1;
            *--v23 = v24;
            *--v23 = BYTE1(a3);
            v5 = v23 - 1;
            v20 = v53-- == 1;
            *v5 = a3;
          }
          while ( !v20 );
        }
        *(_BYTE *)(a1 + 10) = 2;
        *(_BYTE *)(a1 + 11) = 32;
        *(_DWORD *)(a1 + 4) = 4 * v6;
      }
      else
      {
        if ( v6 > 1 )
        {
          v52 = v6 - 1;
          do
          {
            *(v5 - 1) = BYTE1(a3);
            v16 = v5 - 2;
            *v16 = a3;
            v17 = *(_BYTE *)(v15 - 1);
            v18 = v15 - 1;
            *--v16 = v17;
            v19 = *(_BYTE *)(v18 - 1);
            v15 = v18 - 1;
            v5 = v16 - 1;
            v20 = v52-- == 1;
            *v5 = v19;
          }
          while ( !v20 );
        }
        *--v5 = BYTE1(a3);
        *(v5 - 1) = a3;
        *(_BYTE *)(a1 + 10) = 2;
        *(_BYTE *)(a1 + 11) = 32;
        *(_DWORD *)(a1 + 4) = 4 * v6;
      }
    }
  }
  return (char)v5;
}

//------------------------------------------------------------------------------
// Address: 0x101B6A60
// Name: _png_do_gray_to_rgb
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_do_gray_to_rgb(int *a1, int a2)
{
  unsigned __int8 v2; // cl
  int v3; // esi
  char v4; // al
  _BYTE *v5; // ecx
  _BYTE *v6; // eax
  int v7; // edi
  _BYTE *v8; // eax
  _BYTE *v9; // ecx
  _BYTE *v10; // eax
  int v11; // edi
  _BYTE *v12; // eax
  _BYTE *v13; // ecx
  _BYTE *v14; // eax
  int v15; // edi
  char v16; // bl
  _BYTE *v17; // ecx
  _BYTE *v18; // eax
  _BYTE *v19; // ecx
  _BYTE *v20; // eax
  int v21; // edi
  _BYTE *v22; // eax
  _BYTE *v23; // ecx
  char v24; // bl
  char v25; // al
  char v26; // cl
  unsigned __int8 v27; // al

  v2 = *((_BYTE *)a1 + 9);
  v3 = *a1;
  if ( v2 >= 8u )
  {
    v4 = *((_BYTE *)a1 + 8);
    if ( (v4 & 2) == 0 )
    {
      if ( v4 != 0 )
      {
        if ( v4 == 4 )
        {
          if ( v2 == 8 )
          {
            v13 = (_BYTE *)(a2 + 2 * v3 - 1);
            v14 = &v13[2 * v3];
            if ( v3 != 0 )
            {
              v15 = *a1;
              do
              {
                *v14 = *v13;
                v16 = *(v13 - 1);
                v17 = v13 - 1;
                v18 = v14 - 1;
                *v18-- = v16;
                *v18-- = *v17;
                *v18 = *v17;
                v14 = v18 - 1;
                v13 = v17 - 1;
                --v15;
              }
              while ( v15 != 0 );
            }
          }
          else
          {
            v19 = (_BYTE *)(a2 + 4 * v3 - 1);
            v20 = &v19[4 * v3];
            if ( v3 != 0 )
            {
              v21 = *a1;
              do
              {
                *v20 = *v19;
                *(v20 - 1) = *(v19 - 1);
                v22 = v20 - 1;
                v23 = v19 - 1;
                *(v22 - 1) = *(v23 - 1);
                v24 = *(v23 - 2);
                --v23;
                *(--v22 - 1) = v24;
                *(--v22 - 1) = *v23;
                v22 -= 2;
                *v22-- = *(v23 - 1);
                *v22-- = *v23;
                *v22 = *(v23 - 1);
                v20 = v22 - 1;
                v19 = v23 - 2;
                --v21;
              }
              while ( v21 != 0 );
            }
          }
        }
      }
      else if ( v2 == 8 )
      {
        v5 = (_BYTE *)(v3 + a2 - 1);
        v6 = &v5[2 * v3];
        if ( v3 != 0 )
        {
          v7 = *a1;
          do
          {
            *v6 = *v5;
            v8 = v6 - 1;
            *v8-- = *v5;
            *v8 = *v5;
            v6 = v8 - 1;
            --v5;
            --v7;
          }
          while ( v7 != 0 );
        }
      }
      else
      {
        v9 = (_BYTE *)(a2 + 2 * v3 - 1);
        v10 = &v9[4 * v3];
        if ( v3 != 0 )
        {
          v11 = *a1;
          do
          {
            *v10 = *v9;
            *(v10 - 1) = *(v9 - 1);
            v12 = v10 - 1;
            *(v12 - 1) = *v9;
            v12 -= 2;
            *v12-- = *(v9 - 1);
            *v12-- = *v9;
            *v12 = *(v9 - 1);
            v10 = v12 - 1;
            v9 -= 2;
            --v11;
          }
          while ( v11 != 0 );
        }
      }
      *((_BYTE *)a1 + 10) += 2;
      v25 = *((_BYTE *)a1 + 9);
      v26 = *((_BYTE *)a1 + 10);
      *((_BYTE *)a1 + 8) |= 2u;
      v27 = v26 * v25;
      *((_BYTE *)a1 + 11) = v27;
      if ( v27 < 8u )
        a1[1] = (v3 * (unsigned int)v27 + 7) >> 3;
      else
        a1[1] = v3 * (v27 >> 3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B6C20
// Name: _png_do_rgb_to_gray
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl png_do_rgb_to_gray(int a1, int *a2, unsigned __int8 *a3)
{
  int v3; // ecx
  char v4; // dl
  int result; // eax
  int v6; // ebx
  int v7; // edi
  unsigned __int8 *v8; // esi
  int v9; // ebp
  unsigned __int8 v10; // dl
  unsigned __int8 v11; // cl
  unsigned __int8 *v12; // esi
  unsigned __int8 *v13; // ebp
  bool v14; // zf
  unsigned __int8 *v15; // esi
  unsigned __int8 *v16; // ebp
  unsigned __int8 v17; // cl
  unsigned __int8 *v18; // esi
  unsigned __int8 v19; // cl
  unsigned __int8 *v20; // edx
  unsigned __int16 v21; // cx
  unsigned __int16 v22; // bp
  unsigned __int16 v23; // cx
  unsigned __int16 v24; // si
  unsigned __int16 v25; // cx
  __int16 v26; // cx
  unsigned int v27; // edx
  int v28; // esi
  int v29; // ebp
  unsigned int v30; // ebp
  unsigned __int8 *v31; // edx
  unsigned __int8 *v32; // esi
  unsigned __int16 v33; // cx
  unsigned __int16 v34; // bp
  unsigned __int16 v35; // cx
  _BYTE *v36; // esi
  _BYTE *v37; // ebp
  int v38; // ecx
  unsigned __int8 v39; // dl
  unsigned __int8 *v40; // esi
  unsigned __int8 v41; // dl
  _BYTE *v42; // esi
  _BYTE *v43; // ebp
  unsigned __int8 *v44; // eax
  unsigned __int8 v45; // cl
  unsigned __int8 v46; // dl
  unsigned __int8 *v47; // eax
  unsigned __int8 v48; // dl
  _BYTE *v49; // eax
  _BYTE *v50; // esi
  _BYTE *v51; // ecx
  unsigned __int16 v52; // dx
  _BYTE *v53; // ecx
  unsigned __int16 v54; // bp
  unsigned __int16 v55; // bx
  unsigned __int16 v56; // dx
  unsigned __int16 v57; // dx
  __int16 v58; // cx
  int v59; // esi
  int v60; // ebp
  unsigned int v61; // ebp
  _BYTE *v62; // esi
  _BYTE *v63; // eax
  _BYTE *v64; // ecx
  unsigned __int16 v65; // dx
  _BYTE *v66; // eax
  unsigned __int16 v67; // bp
  unsigned __int16 v68; // si
  unsigned __int16 v69; // dx
  unsigned int v70; // edx
  _BYTE *v71; // ecx
  char v72; // al
  char v73; // dl
  unsigned __int8 v74; // al
  unsigned __int8 v75; // [esp+1h] [ebp-27h]
  unsigned __int8 v76; // [esp+1h] [ebp-27h]
  unsigned __int8 v77; // [esp+2h] [ebp-26h]
  unsigned __int8 v78; // [esp+2h] [ebp-26h]
  unsigned __int8 v79; // [esp+2h] [ebp-26h]
  unsigned __int8 v80; // [esp+3h] [ebp-25h]
  int v81; // [esp+4h] [ebp-24h]
  int v82; // [esp+8h] [ebp-20h]
  int v83; // [esp+Ch] [ebp-1Ch]
  unsigned __int8 *v84; // [esp+10h] [ebp-18h]
  unsigned __int8 *v85; // [esp+10h] [ebp-18h]
  int v86; // [esp+10h] [ebp-18h]
  _BYTE *v87; // [esp+10h] [ebp-18h]
  int v88; // [esp+14h] [ebp-14h]
  int v89; // [esp+14h] [ebp-14h]
  unsigned __int16 v90; // [esp+14h] [ebp-14h]
  unsigned __int16 v91; // [esp+14h] [ebp-14h]
  int v92; // [esp+14h] [ebp-14h]
  int v93; // [esp+18h] [ebp-10h]
  int j; // [esp+18h] [ebp-10h]
  int k; // [esp+18h] [ebp-10h]
  unsigned __int8 *v96; // [esp+18h] [ebp-10h]
  int v97; // [esp+1Ch] [ebp-Ch]
  int v98; // [esp+20h] [ebp-8h]
  int i; // [esp+20h] [ebp-8h]
  unsigned __int8 *v100; // [esp+24h] [ebp-4h]

  v3 = *a2;
  v4 = *((_BYTE *)a2 + 8);
  result = 0;
  v82 = *a2;
  v81 = 0;
  if ( (v4 & 2) == 0 )
    return result;
  v6 = *(unsigned __int16 *)(a1 + 558);
  v7 = *(unsigned __int16 *)(a1 + 554);
  v98 = v7;
  v83 = *(unsigned __int16 *)(a1 + 556);
  v97 = v6;
  if ( v4 != 2 )
    goto LABEL_39;
  if ( *((_BYTE *)a2 + 9) == 8 )
  {
    if ( *(_DWORD *)(a1 + 360) != 0 && *(_DWORD *)(a1 + 364) != 0 )
    {
      v8 = a3;
      v84 = a3;
      if ( v3 == 0 )
        goto LABEL_40;
      v88 = *a2;
      do
      {
        v9 = *(_DWORD *)(a1 + 364);
        v10 = *(_BYTE *)(*v8 + v9);
        v11 = *(_BYTE *)(v8[1] + v9);
        v12 = v8 + 2;
        v75 = *(_BYTE *)(*v12 + v9);
        v8 = v12 + 1;
        if ( v10 == v11 && v10 == v75 )
        {
          v13 = v84;
          *v84 = *(v8 - 1);
        }
        else
        {
          v81 |= 1u;
          v13 = v84;
          *v84 = *(_BYTE *)(((v7 * v10 + v83 * v11 + v6 * (unsigned int)v75) >> 15) + *(_DWORD *)(a1 + 360));
        }
        v14 = v88-- == 1;
        v84 = v13 + 1;
      }
      while ( !v14 );
      goto LABEL_38;
    }
    v15 = a3;
    v16 = a3;
    if ( v3 != 0 )
    {
      v89 = *a2;
      do
      {
        v17 = *v15;
        v18 = v15 + 1;
        v76 = v17;
        v19 = *v18;
        v77 = v18[1];
        v15 = v18 + 2;
        if ( v76 == v19 && v76 == v77 )
        {
          *v16 = *(v15 - 1);
        }
        else
        {
          v81 |= 1u;
          *v16 = (v7 * v76 + v83 * v19 + v6 * (unsigned int)v77) >> 15;
        }
        ++v16;
        --v89;
      }
      while ( v89 != 0 );
LABEL_38:
      v3 = v82;
    }
  }
  else if ( *(_DWORD *)(a1 + 376) != 0 && *(_DWORD *)(a1 + 372) != 0 )
  {
    v20 = a3;
    v85 = a3;
    if ( v3 != 0 )
    {
      v93 = *a2;
      do
      {
        HIBYTE(v21) = *v20;
        v20 += 6;
        v100 = v20;
        LOBYTE(v21) = *(v20 - 5);
        v22 = v21;
        HIBYTE(v21) = *(v20 - 4);
        LOBYTE(v21) = *(v20 - 3);
        v90 = v21;
        v14 = v22 == v21;
        HIBYTE(v23) = *(v20 - 2);
        LOBYTE(v23) = *(v20 - 1);
        v24 = v23;
        if ( v14 && v22 == v23 )
        {
          v25 = v22;
        }
        else
        {
          v26 = *(_WORD *)(a1 + 344);
          v27 = v24;
          v28 = *(_DWORD *)(a1 + 376);
          v6 = v97;
          v29 = v83 * *(unsigned __int16 *)(*(_DWORD *)(v28 + 4 * ((unsigned __int8)v90 >> v26)) + 2 * HIBYTE(v90))
              + v7 * *(unsigned __int16 *)(*(_DWORD *)(v28 + 4 * ((unsigned __int8)v22 >> v26)) + 2 * HIBYTE(v22));
          v7 = v98;
          v30 = (v97
               * (unsigned int)*(unsigned __int16 *)(*(_DWORD *)(v28 + 4 * ((unsigned __int8)v27 >> v26))
                                                   + 2 * (v27 >> 8))
               + v29) >> 15;
          v81 |= 1u;
          v25 = *(_WORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 372) + 4 * ((unsigned __int8)v30 >> v26)) + 2 * BYTE1(v30));
          v20 = v100;
        }
        *v85 = HIBYTE(v25);
        v85[1] = v25;
        v85 += 2;
        --v93;
      }
      while ( v93 != 0 );
      goto LABEL_38;
    }
  }
  else
  {
    v31 = a3;
    v32 = a3;
    if ( v3 != 0 )
    {
      v86 = *a2;
      do
      {
        HIBYTE(v33) = *v31;
        v31 += 6;
        LOBYTE(v33) = *(v31 - 5);
        v34 = v33;
        HIBYTE(v33) = *(v31 - 4);
        LOBYTE(v33) = *(v31 - 3);
        v91 = v33;
        v14 = v34 == v33;
        HIBYTE(v35) = *(v31 - 2);
        LOBYTE(v35) = *(v31 - 1);
        if ( !v14 || v34 != v35 )
          v81 |= 1u;
        *v32 = (unsigned __int16)((v7 * v34 + v83 * v91 + v6 * (unsigned int)v35) >> 15) >> 8;
        v36 = v32 + 1;
        *v36 = (v7 * v34 + v83 * v91 + v6 * (unsigned int)v35) >> 15;
        v32 = v36 + 1;
        --v86;
      }
      while ( v86 != 0 );
      goto LABEL_38;
    }
  }
LABEL_39:
  v8 = a3;
LABEL_40:
  if ( *((_BYTE *)a2 + 8) == 6 )
  {
    if ( *((_BYTE *)a2 + 9) != 8 )
    {
      if ( *(_DWORD *)(a1 + 376) != 0 && *(_DWORD *)(a1 + 372) != 0 )
      {
        v51 = v8;
        v96 = v8;
        if ( v82 != 0 )
        {
          v92 = v82;
          do
          {
            HIBYTE(v52) = *v51;
            v53 = v51 + 6;
            v87 = v53;
            LOBYTE(v52) = *(v53 - 5);
            v54 = v52;
            HIBYTE(v52) = *(v53 - 4);
            LOBYTE(v52) = *(v53 - 3);
            v55 = v52;
            v14 = v54 == v52;
            HIBYTE(v56) = *(v53 - 2);
            LOBYTE(v56) = *(v53 - 1);
            if ( v14 && v54 == v56 )
            {
              v57 = v54;
            }
            else
            {
              v58 = *(_WORD *)(a1 + 344);
              v59 = *(_DWORD *)(a1 + 376);
              v60 = v83 * *(unsigned __int16 *)(*(_DWORD *)(v59 + 4 * ((unsigned __int8)v55 >> v58)) + 2 * HIBYTE(v55))
                  + v7 * *(unsigned __int16 *)(*(_DWORD *)(v59 + 4 * ((unsigned __int8)v54 >> v58)) + 2 * HIBYTE(v54));
              v7 = v98;
              v61 = (v97
                   * (unsigned int)*(unsigned __int16 *)(*(_DWORD *)(v59 + 4 * ((unsigned __int8)v56 >> v58))
                                                       + 2 * HIBYTE(v56))
                   + v60) >> 15;
              v81 |= 1u;
              v57 = *(_WORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 372) + 4 * ((unsigned __int8)v61 >> v58)) + 2 * BYTE1(v61));
              v8 = v96;
              v53 = v87;
            }
            *v8 = HIBYTE(v57);
            v62 = v8 + 1;
            *v62++ = v57;
            *v62++ = *v53;
            *v62 = v53[1];
            v8 = v62 + 1;
            v51 = v53 + 2;
            v14 = v92-- == 1;
            v96 = v8;
          }
          while ( !v14 );
        }
      }
      else
      {
        v63 = v8;
        v64 = v8;
        if ( v82 != 0 )
        {
          for ( i = v82; i != 0; --i )
          {
            LOBYTE(v65) = v63[1];
            HIBYTE(v65) = *v63;
            v66 = v63 + 6;
            v67 = v65;
            LOBYTE(v65) = *(v66 - 3);
            HIBYTE(v65) = *(v66 - 4);
            v68 = v65;
            v14 = v67 == v65;
            LOBYTE(v69) = *(v66 - 1);
            HIBYTE(v69) = *(v66 - 2);
            if ( !v14 || v67 != v69 )
              v81 |= 1u;
            v70 = (v7 * v67 + v83 * v68 + v6 * (unsigned int)v69) >> 15;
            *v64 = BYTE1(v70);
            v71 = v64 + 1;
            *v71++ = v70;
            *v71++ = *v66;
            *v71 = v66[1];
            v64 = v71 + 1;
            v63 = v66 + 2;
          }
        }
      }
      goto LABEL_74;
    }
    if ( *(_DWORD *)(a1 + 360) != 0 && *(_DWORD *)(a1 + 364) != 0 )
    {
      v37 = v8;
      if ( v82 != 0 )
      {
        for ( j = v82; j != 0; --j )
        {
          v38 = *(_DWORD *)(a1 + 364);
          v39 = *(_BYTE *)(*v8 + v38);
          v40 = v8 + 1;
          v80 = v39;
          v41 = *(_BYTE *)(*v40++ + v38);
          v78 = *(_BYTE *)(*v40 + v38);
          v42 = v40 + 1;
          if ( v80 != v41 || v80 != v78 )
            v81 |= 1u;
          *v37 = *(_BYTE *)(((v7 * v80 + v83 * v41 + v6 * (unsigned int)v78) >> 15) + *(_DWORD *)(a1 + 360));
          v43 = v37 + 1;
          *v43 = *v42;
          v37 = v43 + 1;
          v8 = v42 + 1;
        }
      }
LABEL_74:
      v3 = v82;
      goto LABEL_75;
    }
    v44 = v8;
    if ( v3 != 0 )
    {
      for ( k = v3; k != 0; --k )
      {
        v45 = *v44;
        v46 = v44[1];
        v47 = v44 + 2;
        v79 = v46;
        v48 = *v47;
        v49 = v47 + 1;
        if ( v45 != v79 || v45 != v48 )
          v81 |= 1u;
        *v8 = (v7 * v45 + v83 * v79 + v6 * (unsigned int)v48) >> 15;
        v50 = v8 + 1;
        *v50 = *v49;
        v8 = v50 + 1;
        v44 = v49 + 1;
      }
      goto LABEL_74;
    }
  }
LABEL_75:
  *((_BYTE *)a2 + 10) -= 2;
  v72 = *((_BYTE *)a2 + 9);
  v73 = *((_BYTE *)a2 + 10);
  *((_BYTE *)a2 + 8) &= ~2u;
  v74 = v73 * v72;
  *((_BYTE *)a2 + 11) = v74;
  if ( v74 < 8u )
    a2[1] = (v3 * (unsigned int)v74 + 7) >> 3;
  else
    a2[1] = v3 * (v74 >> 3);
  return v81;
}

//------------------------------------------------------------------------------
// Address: 0x101B7320
// Name: _png_do_background
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl png_do_background(
        int *a1,
        unsigned __int8 *a2,
        _WORD *a3,
        _BYTE *a4,
        _WORD *a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        __int16 a12)
{
  unsigned int v12; // eax
  int v13; // ecx
  _WORD *v14; // ebp
  _BYTE *v15; // esi
  int v16; // edx
  int v17; // ebp
  char v18; // al
  _BYTE *v19; // esi
  int v20; // edx
  unsigned __int8 v21; // al
  char v22; // al
  char v23; // bl
  int v24; // ebp
  char v25; // al
  _BYTE *v26; // esi
  int v27; // edx
  unsigned __int8 v28; // al
  char v29; // al
  char v30; // bl
  int v31; // ebp
  char v32; // al
  _BYTE *v33; // eax
  int v34; // edx
  char v35; // cl
  unsigned __int8 *v36; // eax
  unsigned __int8 v37; // cl
  __int16 v38; // cx
  _BYTE *v39; // eax
  int v40; // edi
  unsigned __int8 v41; // cl
  char v42; // cl
  _BYTE *v43; // eax
  unsigned __int8 *v44; // eax
  unsigned __int8 v45; // bl
  unsigned __int8 v46; // cl
  __int16 v47; // cx
  unsigned int v48; // ebx
  __int16 v49; // cx
  unsigned int v50; // ebx
  int v51; // edx
  __int16 v52; // cx
  unsigned __int8 *v53; // eax
  unsigned __int8 *v54; // ecx
  _BYTE *v55; // esi
  __int16 v56; // ax
  unsigned int v57; // eax
  unsigned __int8 *v58; // ecx
  _BYTE *v59; // esi
  int v60; // edi
  unsigned __int8 v61; // al
  int v62; // edx
  unsigned int v63; // eax
  _BYTE *v64; // esi
  _BYTE *v65; // edi
  unsigned __int8 *v66; // edx
  unsigned __int16 v67; // ax
  __int16 v68; // ax
  unsigned int v69; // eax
  unsigned __int8 *v70; // edx
  _BYTE *v71; // esi
  unsigned __int8 *v72; // ecx
  unsigned __int16 v73; // ax
  unsigned int v74; // eax
  int v75; // edi
  int v76; // ebp
  int v77; // ecx
  _BYTE *v78; // ebx
  _BYTE *v79; // esi
  unsigned __int8 *v80; // edi
  unsigned __int8 v81; // al
  char v82; // al
  __int16 v83; // cx
  unsigned int v84; // ebp
  unsigned int v85; // ebp
  char v86; // bl
  unsigned int v87; // eax
  _BYTE *v88; // esi
  unsigned __int8 *v89; // edi
  unsigned __int8 v90; // al
  int v91; // ecx
  __int16 v92; // cx
  unsigned int v93; // eax
  int v94; // ebp
  char v95; // bl
  _BYTE *v96; // eax
  unsigned __int8 *v97; // edx
  unsigned __int16 v98; // si
  __int16 v99; // cx
  __int16 v100; // cx
  __int16 v101; // cx
  int v102; // edi
  unsigned int v103; // ebx
  __int16 v104; // cx
  unsigned int v105; // ebx
  __int16 v106; // cx
  unsigned int v107; // ebx
  _BYTE *v108; // esi
  unsigned __int8 *v109; // eax
  unsigned __int8 *v110; // ecx
  unsigned __int16 v111; // dx
  unsigned int v112; // edx
  int v113; // esi
  unsigned __int16 v114; // dx
  unsigned int v115; // edx
  int v116; // ebp
  unsigned int v117; // ebp
  unsigned int v118; // edx
  unsigned int v119; // esi
  char v120; // cl
  unsigned __int8 v121; // al
  int v123; // [esp+0h] [ebp-10h]
  int v124; // [esp+4h] [ebp-Ch]
  int v125; // [esp+4h] [ebp-Ch]
  int v126; // [esp+4h] [ebp-Ch]
  int v127; // [esp+4h] [ebp-Ch]
  int v128; // [esp+4h] [ebp-Ch]
  int v129; // [esp+4h] [ebp-Ch]
  int v130; // [esp+4h] [ebp-Ch]
  int v131; // [esp+4h] [ebp-Ch]
  int v132; // [esp+4h] [ebp-Ch]
  char v133; // [esp+4h] [ebp-Ch]
  unsigned __int16 v134; // [esp+4h] [ebp-Ch]
  int v135; // [esp+Ch] [ebp-4h]
  int v136; // [esp+Ch] [ebp-4h]

  LOBYTE(v12) = (_BYTE)a1;
  v13 = *a1;
  v123 = *a1;
  if ( a4 == nullptr )
    return v12;
  LOBYTE(v12) = *((_BYTE *)a1 + 8);
  if ( (v12 & 4) != 0 )
  {
    if ( (_BYTE)v12 == 3 )
      return v12;
    v14 = a3;
    if ( a3 == nullptr )
      return v12;
  }
  else
  {
    v14 = a3;
  }
  switch ( (char)v12 )
  {
    case 0:
      switch ( *((_BYTE *)a1 + 9) )
      {
        case 1:
          v15 = a2;
          v16 = 7;
          if ( v13 != 0 )
          {
            v17 = *a1;
            do
            {
              if ( ((*v15 >> v16) & 1) == a3[4] )
              {
                v18 = *v15 & (32639 >> (7 - v16));
                *v15 = v18;
                *v15 = v18 | (a4[8] << v16);
              }
              if ( v16 != 0 )
              {
                --v16;
              }
              else
              {
                v16 = 7;
                ++v15;
              }
              --v17;
            }
            while ( v17 != 0 );
          }
          break;
        case 2:
          v19 = a2;
          v20 = 6;
          if ( a6 != 0 )
          {
            if ( v13 != 0 )
            {
              v124 = *a1;
              do
              {
                v21 = (*v19 >> v20) & 3;
                if ( v21 == a3[4] )
                {
                  v22 = *v19 & (16191 >> (6 - v20));
                  *v19 = v22;
                  v23 = a4[8] << v20;
                }
                else
                {
                  v23 = *v19 & (16191 >> (6 - v20));
                  v22 = *(_BYTE *)((v21 | (4 * (v21 | (4 * (v21 | (4 * v21)))))) + a6) >> 6 << v20;
                }
                *v19 = v22 | v23;
                if ( v20 != 0 )
                {
                  v20 -= 2;
                }
                else
                {
                  v20 = 6;
                  ++v19;
                }
                --v124;
              }
              while ( v124 != 0 );
            }
          }
          else if ( v13 != 0 )
          {
            v24 = *a1;
            do
            {
              if ( ((*v19 >> v20) & 3) == a3[4] )
              {
                v25 = *v19 & (16191 >> (6 - v20));
                *v19 = v25;
                *v19 = v25 | (a4[8] << v20);
              }
              if ( v20 != 0 )
              {
                v20 -= 2;
              }
              else
              {
                v20 = 6;
                ++v19;
              }
              --v24;
            }
            while ( v24 != 0 );
          }
          break;
        case 4:
          v26 = a2;
          v27 = 4;
          if ( a6 != 0 )
          {
            if ( v13 != 0 )
            {
              v125 = *a1;
              do
              {
                v28 = (*v26 >> v27) & 0xF;
                if ( v28 == a3[4] )
                {
                  v29 = *v26 & (3855 >> (4 - v27));
                  *v26 = v29;
                  v30 = a4[8] << v27;
                }
                else
                {
                  v30 = *v26 & (3855 >> (4 - v27));
                  v29 = *(_BYTE *)((v28 | (16 * v28)) + a6) >> 4 << v27;
                }
                *v26 = v29 | v30;
                if ( v27 != 0 )
                {
                  v27 -= 4;
                }
                else
                {
                  v27 = 4;
                  ++v26;
                }
                --v125;
              }
              while ( v125 != 0 );
            }
          }
          else if ( v13 != 0 )
          {
            v31 = *a1;
            do
            {
              if ( ((*v26 >> v27) & 0xF) == a3[4] )
              {
                v32 = *v26 & (3855 >> (4 - v27));
                *v26 = v32;
                *v26 = v32 | (a4[8] << v27);
              }
              if ( v27 != 0 )
              {
                v27 -= 4;
              }
              else
              {
                v27 = 4;
                ++v26;
              }
              --v31;
            }
            while ( v31 != 0 );
          }
          break;
        case 8:
          v33 = a2;
          if ( a6 != 0 )
          {
            if ( v13 != 0 )
            {
              v34 = *a1;
              do
              {
                if ( (unsigned __int8)*v33 == v14[4] )
                  v35 = a4[8];
                else
                  v35 = *(_BYTE *)((unsigned __int8)*v33 + a6);
                *v33++ = v35;
                --v34;
              }
              while ( v34 != 0 );
            }
          }
          else
          {
            for ( ; v13 != 0; --v13 )
            {
              if ( (unsigned __int8)*v33 == v14[4] )
                *v33 = a4[8];
              ++v33;
            }
          }
          break;
        case 0x10:
          v36 = a2;
          if ( a9 != 0 )
          {
            if ( v13 != 0 )
            {
              v126 = *a1;
              do
              {
                v37 = v36[1];
                if ( v37 + (*v36 << 8) == a3[4] )
                {
                  *v36 = a4[9];
                  LOBYTE(v38) = a4[8];
                }
                else
                {
                  v38 = *(_WORD *)(*(_DWORD *)(a9 + 4 * (v37 >> a12)) + 2 * *v36);
                  *v36 = HIBYTE(v38);
                }
                v36[1] = v38;
                v36 += 2;
                --v126;
              }
              while ( v126 != 0 );
            }
          }
          else
          {
            for ( ; v13 != 0; --v13 )
            {
              if ( v36[1] + (*v36 << 8) == v14[4] )
              {
                *v36 = a4[9];
                v36[1] = a4[8];
              }
              v36 += 2;
            }
          }
          break;
        default:
          goto LABEL_211;
      }
      goto LABEL_211;
    case 2:
      if ( *((_BYTE *)a1 + 9) == 8 )
      {
        if ( a6 != 0 )
        {
          if ( v13 != 0 )
          {
            v39 = a2 + 2;
            v40 = *a1;
            do
            {
              v41 = *(v39 - 2);
              if ( v41 == v14[1] && (unsigned __int8)*(v39 - 1) == v14[2] && (unsigned __int8)*v39 == v14[3] )
              {
                *(v39 - 2) = a4[2];
                *(v39 - 1) = a4[4];
                v42 = a4[6];
              }
              else
              {
                *(v39 - 2) = *(_BYTE *)(v41 + a6);
                *(v39 - 1) = *(_BYTE *)((unsigned __int8)*(v39 - 1) + a6);
                v42 = *(_BYTE *)((unsigned __int8)*v39 + a6);
              }
              *v39 = v42;
              v39 += 3;
              --v40;
            }
            while ( v40 != 0 );
          }
        }
        else if ( v13 != 0 )
        {
          v43 = a2 + 2;
          do
          {
            if ( (unsigned __int8)*(v43 - 2) == v14[1]
              && (unsigned __int8)*(v43 - 1) == v14[2]
              && (unsigned __int8)*v43 == v14[3] )
            {
              *(v43 - 2) = a4[2];
              *(v43 - 1) = a4[4];
              *v43 = a4[6];
            }
            v43 += 3;
            --v13;
          }
          while ( v13 != 0 );
        }
      }
      else if ( a9 != 0 )
      {
        if ( v13 != 0 )
        {
          v44 = a2 + 2;
          v127 = *a1;
          do
          {
            v45 = *(v44 - 2);
            v46 = *(v44 - 1);
            if ( v46 + (v45 << 8) == a3[1] && v44[1] + (*v44 << 8) == a3[2] && v44[3] + (v44[2] << 8) == a3[3] )
            {
              *(v44 - 2) = a4[3];
              *(v44 - 1) = a4[2];
              *v44 = a4[5];
              v44[1] = a4[4];
              v44[2] = a4[7];
              v44[3] = a4[6];
            }
            else
            {
              v47 = *(_WORD *)(*(_DWORD *)(a9 + 4 * (v46 >> a12)) + 2 * v45);
              v48 = v44[1];
              *(v44 - 1) = v47;
              *(v44 - 2) = HIBYTE(v47);
              v49 = *(_WORD *)(*(_DWORD *)(a9 + 4 * (v48 >> a12)) + 2 * *v44);
              v50 = v44[3];
              v44[1] = v49;
              v51 = v44[2];
              *v44 = HIBYTE(v49);
              v52 = *(_WORD *)(*(_DWORD *)(a9 + 4 * (v50 >> a12)) + 2 * v51);
              v44[2] = HIBYTE(v52);
              v44[3] = v52;
            }
            v44 += 6;
            --v127;
          }
          while ( v127 != 0 );
        }
      }
      else if ( v13 != 0 )
      {
        v53 = a2 + 2;
        do
        {
          if ( *(v53 - 1) + (*(v53 - 2) << 8) == v14[1]
            && v53[1] + (*v53 << 8) == v14[2]
            && v53[3] + (v53[2] << 8) == v14[3] )
          {
            *(v53 - 2) = a4[3];
            *(v53 - 1) = a4[2];
            *v53 = a4[5];
            v53[1] = a4[4];
            v53[2] = a4[7];
            v53[3] = a4[6];
          }
          v53 += 6;
          --v13;
        }
        while ( v13 != 0 );
      }
      goto LABEL_211;
    case 4:
      if ( *((_BYTE *)a1 + 9) == 8 )
      {
        if ( a8 != 0 && a7 != 0 && a6 != 0 )
        {
          v54 = a2;
          v55 = a2;
          if ( v123 != 0 )
          {
            v128 = *a1;
            do
            {
              v56 = v54[1];
              if ( v56 == 255 )
              {
                *v55 = *(_BYTE *)(*v54 + a6);
              }
              else if ( v54[1] != 0 )
              {
                v57 = (unsigned __int16)(v56 * *(unsigned __int8 *)(*v54 + a8) + a5[4] * (255 - v56) + 128);
                *v55 = *(_BYTE *)((unsigned __int8)((unsigned __int16)(v57 + (v57 >> 8)) >> 8) + a7);
              }
              else
              {
                *v55 = a4[8];
              }
              v54 += 2;
              ++v55;
              --v128;
            }
            while ( v128 != 0 );
          }
        }
        else
        {
          v58 = a2;
          v59 = a2;
          if ( v123 != 0 )
          {
            v60 = *a1;
            do
            {
              v61 = v58[1];
              if ( v61 == 0xFF )
              {
                LOBYTE(v62) = *v58;
              }
              else if ( v61 != 0 )
              {
                v63 = (unsigned __int16)(v61 * *v58 + a5[4] * (255 - v61) + 128);
                v62 = (int)(v63 + (v63 >> 8)) >> 8;
              }
              else
              {
                LOBYTE(v62) = a4[8];
              }
              *v59 = v62;
              v58 += 2;
              ++v59;
              --v60;
            }
            while ( v60 != 0 );
          }
        }
        goto LABEL_211;
      }
      if ( a9 == 0 || a10 == 0 || a11 == 0 )
      {
        v70 = a2;
        if ( v123 != 0 )
        {
          v71 = a4;
          v72 = a2 + 3;
          v130 = *a1;
          do
          {
            v73 = *v72 + (*(v72 - 1) << 8);
            if ( v73 == 0xFFFF )
            {
              *(_WORD *)v70 = *(_WORD *)(v72 - 3);
            }
            else
            {
              if ( v73 != 0 )
              {
                v75 = (0xFFFF - v73) * (unsigned __int16)a5[4];
                v71 = a4;
                v74 = (v73 * (unsigned __int16)(*(v72 - 2) + (*(v72 - 3) << 8))
                     + v75
                     + 0x8000
                     + ((v73 * (unsigned int)(unsigned __int16)(*(v72 - 2) + (*(v72 - 3) << 8)) + v75 + 0x8000) >> 16)) >> 16;
                *v70 = BYTE1(v74);
              }
              else
              {
                *v70 = v71[9];
                LOBYTE(v74) = v71[8];
              }
              v70[1] = v74;
            }
            v72 += 4;
            v70 += 2;
            --v130;
          }
          while ( v130 != 0 );
        }
        goto LABEL_211;
      }
      v64 = a2;
      if ( v13 != 0 )
      {
        v65 = a4;
        v66 = a2 + 1;
        v129 = *a1;
        while ( 1 )
        {
          v67 = v66[2] + (v66[1] << 8);
          if ( v67 == 0xFFFF )
            break;
          if ( v67 != 0 )
          {
            v69 = (v67 * *(unsigned __int16 *)(*(_DWORD *)(a11 + 4 * (*v66 >> a12)) + 2 * *(v66 - 1))
                 + (0xFFFF - v67) * (unsigned __int16)a5[4]
                 + 0x8000
                 + ((v67 * *(unsigned __int16 *)(*(_DWORD *)(a11 + 4 * (*v66 >> a12)) + 2 * *(v66 - 1))
                   + (0xFFFF - v67) * (unsigned int)(unsigned __int16)a5[4]
                   + 0x8000) >> 16)) >> 16;
            v68 = *(_WORD *)(*(_DWORD *)(a10 + 4 * ((unsigned __int8)v69 >> a12)) + 2 * (v69 >> 8));
            v65 = a4;
            goto LABEL_153;
          }
          *v64 = v65[9];
          LOBYTE(v68) = v65[8];
LABEL_154:
          v64[1] = v68;
          v66 += 4;
          v64 += 2;
          if ( --v129 == 0 )
            goto LABEL_211;
        }
        v68 = *(_WORD *)(*(_DWORD *)(a9 + 4 * (*v66 >> a12)) + 2 * *(v66 - 1));
LABEL_153:
        *v64 = HIBYTE(v68);
        goto LABEL_154;
      }
LABEL_211:
      LOBYTE(v12) = *((_BYTE *)a1 + 8);
      if ( (v12 & 4) != 0 )
      {
        v120 = --*((_BYTE *)a1 + 10);
        *((_BYTE *)a1 + 8) = v12 & 0xFB;
        v121 = v120 * *((_BYTE *)a1 + 9);
        *((_BYTE *)a1 + 11) = v121;
        if ( v121 < 8u )
          v12 = (v123 * (unsigned int)v121 + 7) >> 3;
        else
          v12 = v123 * (v121 >> 3);
        a1[1] = v12;
      }
      return v12;
    case 6:
      if ( *((_BYTE *)a1 + 9) == 8 )
      {
        v76 = a8;
        if ( a8 != 0 && a7 != 0 && (v77 = a6, a6 != 0) )
        {
          if ( v123 != 0 )
          {
            v78 = a4;
            v79 = a2 + 2;
            v131 = *a1;
            v80 = a2 + 1;
            do
            {
              v81 = v80[2];
              if ( v81 == 0xFF )
              {
                *(v79 - 2) = *(_BYTE *)(*(v80 - 1) + v77);
                *(v79 - 1) = *(_BYTE *)(*v80 + v77);
                v82 = *(_BYTE *)(v80[1] + v77);
              }
              else if ( v81 != 0 )
              {
                v83 = 255 - v81;
                v84 = (unsigned __int16)(v83 * a5[1] + v81 * *(unsigned __int8 *)(*(v80 - 1) + v76) + 128);
                *(v79 - 2) = *(_BYTE *)((unsigned __int8)((unsigned __int16)(v84 + (v84 >> 8)) >> 8) + a7);
                v85 = (unsigned __int16)(v83 * a5[2] + v81 * *(unsigned __int8 *)(*v80 + a8) + 128);
                v86 = *(_BYTE *)((unsigned __int8)((unsigned __int16)(v85 + (v85 >> 8)) >> 8) + a7);
                v76 = a8;
                *(v79 - 1) = v86;
                v78 = a4;
                v87 = (unsigned __int16)(v83 * a5[3] + v81 * *(unsigned __int8 *)(v80[1] + a8) + 128);
                v82 = *(_BYTE *)((unsigned __int8)((unsigned __int16)(v87 + (v87 >> 8)) >> 8) + a7);
                v77 = a6;
              }
              else
              {
                *(v79 - 2) = v78[2];
                *(v79 - 1) = v78[4];
                v82 = v78[6];
              }
              *v79 = v82;
              v80 += 4;
              v79 += 3;
              --v131;
            }
            while ( v131 != 0 );
          }
        }
        else if ( v123 != 0 )
        {
          v88 = a2 + 2;
          v89 = a2 + 1;
          v132 = *a1;
          do
          {
            v90 = v89[2];
            if ( v90 == 0xFF )
            {
              *(v88 - 2) = *(v89 - 1);
              *(v88 - 1) = *v89;
              *v88 = v89[1];
            }
            else
            {
              if ( v90 != 0 )
              {
                v92 = 255 - v90;
                *(v88 - 2) = (unsigned __int16)(v92 * *((_WORD *)a4 + 1)
                                              + v90 * *(v89 - 1)
                                              + 128
                                              + ((unsigned __int16)(v92 * *((_WORD *)a4 + 1) + v90 * *(v89 - 1) + 128) >> 8)) >> 8;
                *(v88 - 1) = (unsigned __int16)(v90 * *v89
                                              + v92 * *((_WORD *)a4 + 2)
                                              + 128
                                              + ((unsigned __int16)(v90 * *v89 + v92 * *((_WORD *)a4 + 2) + 128) >> 8)) >> 8;
                v93 = (unsigned __int16)(v92 * *((_WORD *)a4 + 3) + v90 * v89[1] + 128);
                v91 = (int)(v93 + (v93 >> 8)) >> 8;
              }
              else
              {
                *(v88 - 2) = a4[2];
                *(v88 - 1) = a4[4];
                LOBYTE(v91) = a4[6];
              }
              *v88 = v91;
            }
            v89 += 4;
            v88 += 3;
            --v132;
          }
          while ( v132 != 0 );
        }
        goto LABEL_211;
      }
      v94 = a9;
      if ( a9 == 0 || a10 == 0 || a11 == 0 )
      {
        if ( v123 != 0 )
        {
          v108 = a4;
          v109 = a2 + 2;
          v110 = a2 + 7;
          v136 = *a1;
          do
          {
            v111 = *v110 + (*(v110 - 1) << 8);
            if ( v111 == 0xFFFF )
            {
              *(_DWORD *)(v109 - 2) = *(_DWORD *)(v110 - 7);
              *((_WORD *)v109 + 1) = *(_WORD *)(v110 - 3);
            }
            else
            {
              if ( v111 != 0 )
              {
                v134 = *(v110 - 2) + (*(v110 - 3) << 8);
                v113 = v111;
                v114 = *(v110 - 6) + (*(v110 - 7) << 8);
                v115 = (v113 * v114
                      + (0xFFFF - v113) * *((unsigned __int16 *)a4 + 1)
                      + 0x8000
                      + ((v113 * v114 + (0xFFFF - v113) * (unsigned int)*((unsigned __int16 *)a4 + 1) + 0x8000) >> 16)) >> 16;
                v116 = v113 * (unsigned __int16)(*(v110 - 4) + (*(v110 - 5) << 8));
                *(v109 - 2) = BYTE1(v115);
                *(v109 - 1) = v115;
                v117 = (0xFFFF - v113) * *((unsigned __int16 *)a4 + 2) + v116 + 0x8000;
                v118 = (v117 + HIWORD(v117)) >> 16;
                *v109 = BYTE1(v118);
                v109[1] = v118;
                v119 = (0xFFFF - v113) * *((unsigned __int16 *)a4 + 3) + v113 * v134 + 0x8000;
                v112 = (v119 + HIWORD(v119)) >> 16;
                v109[2] = BYTE1(v112);
                v108 = a4;
              }
              else
              {
                *(v109 - 2) = v108[3];
                *(v109 - 1) = v108[2];
                *v109 = v108[5];
                v109[1] = v108[4];
                v109[2] = v108[7];
                LOBYTE(v112) = v108[6];
              }
              v109[3] = v112;
            }
            v110 += 8;
            v109 += 6;
            --v136;
          }
          while ( v136 != 0 );
        }
        goto LABEL_211;
      }
      if ( v123 == 0 )
        goto LABEL_211;
      v95 = a12;
      v96 = a2 + 2;
      v97 = a2 + 1;
      v135 = *a1;
      break;
    default:
      goto LABEL_211;
  }
  while ( 1 )
  {
    v98 = v97[6] + (v97[5] << 8);
    if ( v98 == 0xFFFF )
      break;
    if ( v98 != 0 )
    {
      v102 = v98;
      v133 = v95;
      v103 = (v102 * *(unsigned __int16 *)(*(_DWORD *)(a11 + 4 * (*v97 >> v95)) + 2 * *(v97 - 1))
            + (0xFFFF - v102) * (unsigned __int16)a5[1]
            + 0x8000
            + ((v102 * *(unsigned __int16 *)(*(_DWORD *)(a11 + 4 * (*v97 >> v95)) + 2 * *(v97 - 1))
              + (0xFFFF - v102) * (unsigned int)(unsigned __int16)a5[1]
              + 0x8000) >> 16)) >> 16;
      v104 = *(_WORD *)(*(_DWORD *)(a10 + 4 * ((unsigned __int8)v103 >> a12)) + 2 * (v103 >> 8));
      *(v96 - 2) = HIBYTE(v104);
      *(v96 - 1) = v104;
      v105 = (v102 * *(unsigned __int16 *)(*(_DWORD *)(a11 + 4 * (v97[2] >> v133)) + 2 * v97[1])
            + (0xFFFF - v102) * (unsigned __int16)a5[2]
            + 0x8000
            + ((v102 * *(unsigned __int16 *)(*(_DWORD *)(a11 + 4 * (v97[2] >> v133)) + 2 * v97[1])
              + (0xFFFF - v102) * (unsigned int)(unsigned __int16)a5[2]
              + 0x8000) >> 16)) >> 16;
      v106 = *(_WORD *)(*(_DWORD *)(a10 + 4 * ((unsigned __int8)v105 >> a12)) + 2 * (v105 >> 8));
      *v96 = HIBYTE(v106);
      v96[1] = v106;
      v107 = (v102 * *(unsigned __int16 *)(*(_DWORD *)(a11 + 4 * (v97[4] >> v133)) + 2 * v97[3])
            + (0xFFFF - v102) * (unsigned __int16)a5[3]
            + 0x8000
            + ((v102 * *(unsigned __int16 *)(*(_DWORD *)(a11 + 4 * (v97[4] >> v133)) + 2 * v97[3])
              + (0xFFFF - v102) * (unsigned int)(unsigned __int16)a5[3]
              + 0x8000) >> 16)) >> 16;
      v101 = *(_WORD *)(*(_DWORD *)(a10 + 4 * ((unsigned __int8)v107 >> a12)) + 2 * (v107 >> 8));
      v94 = a9;
      v95 = a12;
      goto LABEL_199;
    }
    *(v96 - 2) = a4[3];
    *(v96 - 1) = a4[2];
    *v96 = a4[5];
    v96[1] = a4[4];
    v96[2] = a4[7];
    LOBYTE(v101) = a4[6];
LABEL_200:
    v96[3] = v101;
    v97 += 8;
    v96 += 6;
    if ( --v135 == 0 )
      goto LABEL_211;
  }
  v99 = *(_WORD *)(*(_DWORD *)(v94 + 4 * (*v97 >> v95)) + 2 * *(v97 - 1));
  *(v96 - 2) = HIBYTE(v99);
  *(v96 - 1) = v99;
  v100 = *(_WORD *)(*(_DWORD *)(v94 + 4 * (v97[2] >> v95)) + 2 * v97[1]);
  *v96 = HIBYTE(v100);
  v96[1] = v100;
  v101 = *(_WORD *)(*(_DWORD *)(v94 + 4 * (v97[4] >> v95)) + 2 * v97[3]);
LABEL_199:
  v96[2] = HIBYTE(v101);
  goto LABEL_200;
}

//------------------------------------------------------------------------------
// Address: 0x101B8320
// Name: _png_do_gamma
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl png_do_gamma(int *a1, unsigned __int8 *a2, int a3, int a4, char a5)
{
  int v5; // edx
  int *v6; // ebp
  unsigned __int8 *v7; // eax
  int v8; // esi
  bool v9; // zf
  char v10; // dl
  _BYTE *v11; // eax
  char v12; // dl
  __int16 v13; // cx
  unsigned int v14; // edi
  unsigned __int8 *v15; // eax
  __int16 v16; // cx
  unsigned int v17; // edi
  __int16 v18; // cx
  char v19; // cl
  _BYTE *v20; // eax
  int v21; // edx
  __int16 v22; // cx
  unsigned int v23; // edi
  unsigned __int8 *v24; // eax
  __int16 v25; // cx
  unsigned int v26; // edi
  __int16 v27; // cx
  __int16 v28; // cx
  char v29; // al
  int v30; // edx
  int v31; // esi
  int v32; // ecx
  char v33; // cl
  _BYTE *v34; // edx
  unsigned int v35; // esi
  __int16 v36; // cx
  unsigned __int8 *v38; // [esp+Ch] [ebp-Ch]
  unsigned int v39; // [esp+10h] [ebp-8h]
  int v40; // [esp+14h] [ebp-4h]

  v5 = a4;
  v6 = a1;
  LOBYTE(v7) = *((_BYTE *)a1 + 9);
  v8 = *a1;
  v40 = *a1;
  if ( (unsigned __int8)v7 <= 8u && a3 != 0 || (_BYTE)v7 == 16 && a4 != 0 )
  {
    switch ( *((_BYTE *)a1 + 8) )
    {
      case 0:
        v9 = (_BYTE)v7 == 2;
        v7 = a2;
        if ( v9 )
        {
          v38 = a2;
          if ( v8 != 0 )
          {
            v39 = ((unsigned int)(v8 - 1) >> 2) + 1;
            do
            {
              v29 = *v7;
              v30 = v29 & 0xC;
              v31 = v29 & 0x30;
              v32 = v29 & 0xC0;
              *v38 = *(_BYTE *)((v32 | ((v32 | ((v32 | (v32 >> 2)) >> 2)) >> 2)) + a3) & 0xC0
                   | ((unsigned __int8)(*(_BYTE *)((v31 | (4 * v31) | ((v31 | (v31 >> 2)) >> 2)) + a3) & 0xC3
                                      | ((unsigned __int8)((*(_BYTE *)((v29 & 3
                                                                      | (4
                                                                       * (v29 & 3 | (4 * (v29 & 3 | (4 * (v29 & 3)))))))
                                                                     + a3) >> 2)
                                                         | *(_BYTE *)((v30 | (v30 >> 2) | (4 * (v30 | (4 * v30)))) + a3)
                                                         & 0xCF) >> 2)) >> 2);
              v7 = v38 + 1;
              v9 = v39-- == 1;
              ++v38;
            }
            while ( !v9 );
            v5 = a4;
            v7 = a2;
            v6 = a1;
            v8 = v40;
          }
        }
        v33 = *((_BYTE *)v6 + 9);
        if ( v33 == 4 )
        {
          v34 = v7;
          if ( v8 != 0 )
          {
            v35 = ((unsigned int)(v8 - 1) >> 1) + 1;
            do
            {
              LOBYTE(v7) = *(_BYTE *)((*v34 & 0xF | (16 * (*v34 & 0xF))) + a3) >> 4;
              *v34 = (unsigned __int8)v7 | *(_BYTE *)((*v34 & 0xF0 | ((*v34 & 0xF0) >> 4)) + a3) & 0xF0;
              ++v34;
              --v35;
            }
            while ( v35 != 0 );
          }
        }
        else if ( v33 == 8 )
        {
          for ( ; v8 != 0; --v8 )
          {
            *v7 = *(_BYTE *)(*v7 + a3);
            ++v7;
          }
        }
        else if ( v33 == 16 && v8 != 0 )
        {
          do
          {
            v36 = *(_WORD *)(*(_DWORD *)(v5 + 4 * (v7[1] >> a5)) + 2 * *v7);
            *v7 = HIBYTE(v36);
            v7[1] = v36;
            v7 += 2;
            --v8;
          }
          while ( v8 != 0 );
        }
        break;
      case 2:
        v9 = (_BYTE)v7 == 8;
        v7 = a2;
        if ( v9 )
        {
          for ( ; v8 != 0; --v8 )
          {
            *v7 = *(_BYTE *)(*v7 + a3);
            v10 = *(_BYTE *)(v7[1] + a3);
            v11 = v7 + 1;
            *v11 = v10;
            v12 = *(_BYTE *)((unsigned __int8)*++v11 + a3);
            *v11 = v12;
            v7 = v11 + 1;
          }
        }
        else
        {
          for ( ; v8 != 0; --v8 )
          {
            v13 = *(_WORD *)(*(_DWORD *)(a4 + 4 * (v7[1] >> a5)) + 2 * *v7);
            v7[1] = v13;
            *v7 = HIBYTE(v13);
            v14 = v7[3];
            v15 = v7 + 2;
            v16 = *(_WORD *)(*(_DWORD *)(a4 + 4 * (v14 >> a5)) + 2 * *v15);
            v15[1] = v16;
            *v15 = HIBYTE(v16);
            v17 = v15[3];
            v15 += 2;
            v18 = *(_WORD *)(*(_DWORD *)(a4 + 4 * (v17 >> a5)) + 2 * *v15);
            *v15 = HIBYTE(v18);
            v15[1] = v18;
            v7 = v15 + 2;
          }
        }
        break;
      case 4:
        v9 = (_BYTE)v7 == 8;
        v7 = a2;
        if ( v9 )
        {
          for ( ; v8 != 0; --v8 )
          {
            *v7 = *(_BYTE *)(*v7 + a3);
            v7 += 2;
          }
        }
        else
        {
          for ( ; v8 != 0; --v8 )
          {
            v28 = *(_WORD *)(*(_DWORD *)(a4 + 4 * (v7[1] >> a5)) + 2 * *v7);
            *v7 = HIBYTE(v28);
            v7[1] = v28;
            v7 += 4;
          }
        }
        break;
      case 6:
        v9 = (_BYTE)v7 == 8;
        v7 = a2;
        if ( v9 )
        {
          for ( ; v8 != 0; --v8 )
          {
            *v7 = *(_BYTE *)(*v7 + a3);
            v19 = *(_BYTE *)(v7[1] + a3);
            v20 = v7 + 1;
            *v20 = v19;
            v21 = (unsigned __int8)*++v20;
            *v20 = *(_BYTE *)(v21 + a3);
            v7 = v20 + 2;
          }
        }
        else
        {
          for ( ; v8 != 0; --v8 )
          {
            v22 = *(_WORD *)(*(_DWORD *)(a4 + 4 * (v7[1] >> a5)) + 2 * *v7);
            v7[1] = v22;
            *v7 = HIBYTE(v22);
            v23 = v7[3];
            v24 = v7 + 2;
            v25 = *(_WORD *)(*(_DWORD *)(a4 + 4 * (v23 >> a5)) + 2 * *v24);
            v24[1] = v25;
            *v24 = HIBYTE(v25);
            v26 = v24[3];
            v24 += 2;
            v27 = *(_WORD *)(*(_DWORD *)(a4 + 4 * (v26 >> a5)) + 2 * *v24);
            *v24 = HIBYTE(v27);
            v24[1] = v27;
            v7 = v24 + 4;
          }
        }
        break;
      default:
        return (char)v7;
    }
  }
  return (char)v7;
}

//------------------------------------------------------------------------------
// Address: 0x101B86E0
// Name: _png_do_expand_palette
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_do_expand_palette(int *a1, int a2, int a3, int a4, int a5)
{
  int *v5; // ebx
  int v6; // edx
  unsigned __int8 v7; // al
  int v8; // eax
  int v9; // eax
  _BYTE *v10; // esi
  int v11; // eax
  _BYTE *v12; // edi
  _BYTE *v13; // esi
  int v14; // eax
  _BYTE *v15; // edi
  _BYTE *v16; // esi
  int v17; // eax
  _BYTE *v18; // edi
  unsigned __int8 *v19; // ecx
  int v20; // esi
  _BYTE *v21; // eax
  int i; // ebp
  int v23; // esi
  _BYTE *v24; // eax
  int v25; // esi
  _BYTE *v26; // eax
  int j; // ebp
  _BYTE *v28; // eax
  int v29; // [esp+4h] [ebp-4h]
  int v30; // [esp+4h] [ebp-4h]
  int v31; // [esp+4h] [ebp-4h]

  v5 = a1;
  v6 = *a1;
  if ( *((_BYTE *)a1 + 8) != 3 )
    return;
  v7 = *((_BYTE *)a1 + 9);
  if ( v7 < 8u )
  {
    v8 = v7 - 1;
    if ( v8 != 0 )
    {
      v9 = v8 - 1;
      if ( v9 != 0 )
      {
        if ( v9 != 2 )
          goto LABEL_27;
        v10 = (_BYTE *)(a2 + ((unsigned int)(v6 - 1) >> 1));
        v11 = 4 * (*a1 & 1);
        v12 = (_BYTE *)(v6 + a2 - 1);
        if ( v6 == 0 )
          goto LABEL_27;
        v29 = *a1;
        do
        {
          *v12 = (*v10 >> v11) & 0xF;
          if ( v11 == 4 )
          {
            v11 = 0;
            --v10;
          }
          else
          {
            v11 += 4;
          }
          --v12;
          --v29;
        }
        while ( v29 != 0 );
        goto LABEL_26;
      }
      v13 = (_BYTE *)(a2 + ((unsigned int)(v6 - 1) >> 2));
      v14 = 2 * (3 - (((_BYTE)v6 - 1) & 3));
      v15 = (_BYTE *)(v6 + a2 - 1);
      if ( v6 != 0 )
      {
        v30 = *a1;
        do
        {
          *v15 = (*v13 >> v14) & 3;
          if ( v14 == 6 )
          {
            v14 = 0;
            --v13;
          }
          else
          {
            v14 += 2;
          }
          --v15;
          --v30;
        }
        while ( v30 != 0 );
LABEL_26:
        v5 = a1;
      }
    }
    else
    {
      v16 = (_BYTE *)(a2 + ((unsigned int)(v6 - 1) >> 3));
      v17 = 7 - (((_BYTE)v6 - 1) & 7);
      v18 = (_BYTE *)(v6 + a2 - 1);
      if ( v6 != 0 )
      {
        v31 = *a1;
        do
        {
          *v18 = (*v16 >> v17) & 1;
          if ( v17 == 7 )
          {
            v17 = 0;
            --v16;
          }
          else
          {
            ++v17;
          }
          --v18;
          --v31;
        }
        while ( v31 != 0 );
        goto LABEL_26;
      }
    }
LABEL_27:
    *((_BYTE *)v5 + 9) = 8;
    *((_BYTE *)v5 + 11) = 8;
    v5[1] = v6;
  }
  if ( *((_BYTE *)v5 + 9) == 8 )
  {
    v19 = (unsigned __int8 *)(v6 + a2 - 1);
    if ( a4 != 0 )
    {
      v20 = 4 * v6;
      v21 = (_BYTE *)(4 * v6 + a2 - 1);
      if ( v6 != 0 )
      {
        for ( i = v6; i != 0; --i )
        {
          v23 = *v19;
          if ( v23 < a5 )
            *v21 = *(_BYTE *)(v23 + a4);
          else
            *v21 = -1;
          *(v21 - 1) = *(_BYTE *)(*v19 + a3 + 2 * *v19 + 2);
          v24 = v21 - 2;
          *v24-- = *(_BYTE *)(*v19 + a3 + 2 * *v19 + 1);
          *v24 = *(_BYTE *)(*v19 + a3 + 2 * *v19);
          v21 = v24 - 1;
          --v19;
        }
        v5 = a1;
        v20 = 4 * v6;
      }
      v5[1] = v20;
      *((_BYTE *)v5 + 11) = 32;
      *((_BYTE *)v5 + 8) = 6;
      *((_BYTE *)v5 + 10) = 4;
      *((_BYTE *)v5 + 9) = 8;
    }
    else
    {
      v25 = 3 * v6;
      v26 = (_BYTE *)(3 * v6 + a2 - 1);
      if ( v6 != 0 )
      {
        for ( j = v6; j != 0; --j )
        {
          *v26 = *(_BYTE *)(*v19 + a3 + 2 * *v19 + 2);
          v28 = v26 - 1;
          *v28-- = *(_BYTE *)(*v19 + a3 + 2 * *v19 + 1);
          *v28 = *(_BYTE *)(*v19 + a3 + 2 * *v19);
          v26 = v28 - 1;
          --v19;
        }
        v5 = a1;
        v25 = 3 * v6;
      }
      *((_BYTE *)v5 + 11) = 24;
      *((_BYTE *)v5 + 8) = 2;
      *((_BYTE *)v5 + 10) = 3;
      v5[1] = v25;
      *((_BYTE *)v5 + 9) = 8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B8930
// Name: _png_do_expand
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl png_do_expand(int *a1, int a2, _WORD *a3)
{
  int *v3; // edx
  int v4; // eax
  int v5; // esi
  _WORD *v6; // ecx
  unsigned __int16 v7; // di
  int v8; // eax
  int v9; // eax
  unsigned __int16 v10; // cx
  unsigned __int8 *v11; // edi
  int v12; // edx
  _BYTE *v13; // ebp
  unsigned __int8 *v14; // edi
  int v15; // edx
  _BYTE *v16; // ebp
  _BYTE *v17; // edi
  _BYTE *v18; // ebp
  char v19; // al
  _BYTE *v20; // ecx
  _BYTE *v21; // eax
  int i; // ebp
  _BYTE *v23; // eax
  char v24; // al
  int v25; // eax
  _BYTE *v26; // ecx
  _BYTE *v27; // eax
  int v28; // ebp
  int j; // edi
  unsigned __int16 v30; // bx
  _BYTE *v31; // eax
  _BYTE *v32; // eax
  char v33; // al
  _BYTE *v34; // ecx
  _BYTE *v35; // eax
  int v36; // edi
  _BYTE *v37; // eax
  char v38; // bl
  _BYTE *v39; // ecx
  _BYTE *v40; // ecx
  _BYTE *v41; // eax
  int v42; // edi
  __int16 v43; // dx
  __int16 v44; // dx
  __int16 v45; // dx
  _BYTE *v46; // eax
  char v47; // dl
  _BYTE *v48; // eax
  _BYTE *v49; // ecx
  char v50; // dl
  char v51; // dl
  char v52; // dl
  char v53; // al
  unsigned __int8 v54; // al
  unsigned __int16 v56; // [esp+10h] [ebp-8h]
  int v57; // [esp+14h] [ebp-4h]
  int v58; // [esp+14h] [ebp-4h]
  int v59; // [esp+14h] [ebp-4h]

  v3 = a1;
  LOBYTE(v4) = *((_BYTE *)a1 + 8);
  v5 = *a1;
  if ( (_BYTE)v4 != 0 )
  {
    if ( (_BYTE)v4 != 2 || a3 == nullptr )
      return v4;
    v33 = *((_BYTE *)a1 + 9);
    if ( v33 == 8 )
    {
      v34 = (_BYTE *)(a1[1] + a2 - 1);
      v35 = (_BYTE *)(a2 + 4 * v5 - 1);
      if ( v5 != 0 )
      {
        v36 = *a1;
        do
        {
          if ( (unsigned __int8)*(v34 - 2) == a3[1]
            && (unsigned __int8)*(v34 - 1) == a3[2]
            && (unsigned __int8)*v34 == a3[3] )
          {
            *v35 = 0;
          }
          else
          {
            *v35 = -1;
          }
          v37 = v35 - 1;
          *v37 = *v34;
          v38 = *(v34 - 1);
          v39 = v34 - 1;
          *--v37 = v38;
          *--v37 = *(v39 - 1);
          v35 = v37 - 1;
          v34 = v39 - 2;
          --v36;
        }
        while ( v36 != 0 );
      }
    }
    else if ( v33 == 16 )
    {
      v40 = (_BYTE *)(a1[1] + a2 - 1);
      v41 = (_BYTE *)(a2 + 8 * v5 - 1);
      if ( v5 != 0 )
      {
        v42 = *a1;
        do
        {
          HIBYTE(v43) = *(v40 - 5);
          LOBYTE(v43) = *(v40 - 4);
          if ( v43 == a3[1]
            && (HIBYTE(v44) = *(v40 - 3), LOBYTE(v44) = *(v40 - 2), v44 == a3[2])
            && (HIBYTE(v45) = *(v40 - 1), LOBYTE(v45) = *v40, v45 == a3[3]) )
          {
            *v41 = 0;
            v46 = v41 - 1;
            *v46 = 0;
          }
          else
          {
            *v41 = -1;
            v46 = v41 - 1;
            *v46 = -1;
          }
          *(v46 - 1) = *v40;
          v47 = *(v40 - 1);
          v48 = v46 - 1;
          v49 = v40 - 1;
          *(v48 - 1) = v47;
          v50 = *(v49 - 1);
          --v48;
          --v49;
          *(v48 - 1) = v50;
          v51 = *--v49;
          v48 -= 2;
          *v48 = v51;
          v52 = *--v49;
          *--v48 = v52;
          *--v48 = *(v49 - 1);
          v41 = v48 - 1;
          v40 = v49 - 2;
          --v42;
        }
        while ( v42 != 0 );
        v3 = a1;
      }
    }
    v53 = *((_BYTE *)v3 + 9);
    *((_BYTE *)v3 + 8) = 6;
    *((_BYTE *)v3 + 10) = 4;
    v24 = 2 * v53;
    goto LABEL_72;
  }
  v6 = a3;
  if ( a3 != nullptr )
    v7 = a3[4];
  else
    v7 = 0;
  LOBYTE(v4) = *((_BYTE *)a1 + 9);
  if ( (unsigned __int8)v4 < 8u )
  {
    v8 = (unsigned __int8)v4 - 1;
    if ( v8 != 0 )
    {
      v9 = v8 - 1;
      if ( v9 != 0 )
      {
        v4 = v9 - 2;
        if ( v4 != 0 )
        {
LABEL_31:
          v6 = a3;
          *((_BYTE *)v3 + 9) = 8;
          *((_BYTE *)v3 + 11) = 8;
          v3[1] = v5;
          goto LABEL_32;
        }
        v10 = 17 * v7;
        v4 = 4 * (((_BYTE)v5 - 1) & 1);
        v11 = (unsigned __int8 *)(a2 + ((unsigned int)(v5 - 1) >> 1));
        v12 = 4 - v4;
        v56 = v10;
        v13 = (_BYTE *)(v5 + a2 - 1);
        if ( v5 != 0 )
        {
          v57 = *a1;
          do
          {
            v4 = (*v11 >> v12) & 0xF;
            *v13 = v4 | (16 * ((*v11 >> v12) & 0xF));
            if ( v12 == 4 )
            {
              v12 = 0;
              --v11;
            }
            else
            {
              v12 = 4;
            }
            --v13;
            --v57;
          }
          while ( v57 != 0 );
        }
      }
      else
      {
        v56 = 85 * v7;
        v4 = ((_BYTE)v5 - 1) & 3;
        v14 = (unsigned __int8 *)(a2 + ((unsigned int)(v5 - 1) >> 2));
        v15 = 2 * (3 - v4);
        v16 = (_BYTE *)(v5 + a2 - 1);
        if ( v5 != 0 )
        {
          v58 = *a1;
          do
          {
            v4 = (*v14 >> v15) & 3;
            *v16 = v4 | (4 * (v4 | (4 * (v4 | (4 * ((*v14 >> v15) & 3))))));
            if ( v15 == 6 )
            {
              v15 = 0;
              --v14;
            }
            else
            {
              v15 += 2;
            }
            --v16;
            --v58;
          }
          while ( v58 != 0 );
        }
      }
    }
    else
    {
      v56 = 255 * v7;
      v17 = (_BYTE *)(a2 + ((unsigned int)(v5 - 1) >> 3));
      v4 = 7 - (((_BYTE)v5 - 1) & 7);
      v18 = (_BYTE *)(v5 + a2 - 1);
      if ( v5 == 0 )
      {
LABEL_30:
        v7 = v56;
        goto LABEL_31;
      }
      v59 = *a1;
      do
      {
        *v18 = -(((*v17 >> v4) & 1) != 0);
        if ( v4 == 7 )
        {
          v4 = 0;
          --v17;
        }
        else
        {
          ++v4;
        }
        --v18;
        --v59;
      }
      while ( v59 != 0 );
    }
    v3 = a1;
    goto LABEL_30;
  }
LABEL_32:
  if ( v6 == nullptr )
    return v4;
  v19 = *((_BYTE *)v3 + 9);
  if ( v19 == 8 )
  {
    v20 = (_BYTE *)(v5 + a2 - 1);
    v21 = (_BYTE *)(a2 + 2 * v5 - 1);
    if ( v5 != 0 )
    {
      for ( i = v5; i != 0; --i )
      {
        if ( (unsigned __int8)*v20 == v7 )
          *v21 = 0;
        else
          *v21 = -1;
        v23 = v21 - 1;
        *v23 = *v20;
        v21 = v23 - 1;
        --v20;
      }
      v24 = *((_BYTE *)v3 + 9);
      *((_BYTE *)v3 + 8) = 4;
      *((_BYTE *)v3 + 10) = 2;
      goto LABEL_72;
    }
  }
  else if ( v19 == 16 )
  {
    v25 = v3[1];
    v26 = (_BYTE *)(v25 + a2 - 1);
    v27 = (_BYTE *)(a2 + 2 * v25 - 1);
    if ( v5 != 0 )
    {
      v28 = v7;
      for ( j = v5; j != 0; --j )
      {
        HIBYTE(v30) = *(v26 - 1);
        LOBYTE(v30) = *v26;
        if ( v30 == v28 )
        {
          *v27 = 0;
          v31 = v27 - 1;
          *v31 = 0;
        }
        else
        {
          *v27 = -1;
          v31 = v27 - 1;
          *v31 = -1;
        }
        v32 = v31 - 1;
        *v32-- = *v26;
        *v32 = *(v26 - 1);
        v27 = v32 - 1;
        v26 -= 2;
      }
    }
  }
  v24 = *((_BYTE *)v3 + 9);
  *((_BYTE *)v3 + 8) = 4;
  *((_BYTE *)v3 + 10) = 2;
LABEL_72:
  v54 = 2 * v24;
  *((_BYTE *)v3 + 11) = v54;
  if ( v54 < 8u )
    v4 = (v5 * (unsigned int)v54 + 7) >> 3;
  else
    v4 = v5 * (v54 >> 3);
  v3[1] = v4;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101B8D30
// Name: _png_do_dither
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl png_do_dither(int *a1, char *a2, int a3, int a4)
{
  int *v4; // edx
  unsigned int i; // eax
  int v6; // ebx
  char *v7; // ecx
  char *v8; // edi
  char v9; // al
  char v10; // si
  _BYTE *v11; // ecx
  int v12; // eax
  char *v13; // ecx
  char *v14; // edi
  char v15; // al
  char v16; // si
  _BYTE *v17; // ecx
  int v19; // [esp+10h] [ebp-4h]

  v4 = a1;
  LOBYTE(i) = *((_BYTE *)a1 + 8);
  v6 = *a1;
  v19 = *a1;
  if ( (_BYTE)i == 2 && a3 != 0 && *((_BYTE *)a1 + 9) == 8 )
  {
    v7 = a2;
    v8 = a2;
    if ( v6 != 0 )
    {
      do
      {
        v9 = *v7;
        v10 = v7[1];
        v11 = v7 + 1;
        *v8 = *(_BYTE *)((((int)(unsigned __int8)v11[1] >> 3) | (4 * (v10 & 0xF8 | (32 * (v9 & 0xF8))))) + a3);
        v7 = v11 + 2;
        ++v8;
        --v6;
      }
      while ( v6 != 0 );
      v6 = v19;
      v4 = a1;
    }
    LOBYTE(v12) = *((_BYTE *)v4 + 9);
    *((_BYTE *)v4 + 11) = v12;
    *((_BYTE *)v4 + 8) = 3;
    *((_BYTE *)v4 + 10) = 1;
    v12 = (unsigned __int8)v12;
    if ( (unsigned __int8)v12 >= 8u )
    {
      i = v6 * ((unsigned __int8)v12 >> 3);
      v4[1] = i;
      return i;
    }
LABEL_17:
    i = (unsigned int)(v6 * v12 + 7) >> 3;
    v4[1] = i;
    return i;
  }
  if ( (_BYTE)i == 6 && a3 != 0 && *((_BYTE *)a1 + 9) == 8 )
  {
    v13 = a2;
    v14 = a2;
    if ( v6 != 0 )
    {
      do
      {
        v15 = *v13;
        v16 = v13[1];
        v17 = v13 + 1;
        *v14 = *(_BYTE *)((((int)(unsigned __int8)v17[1] >> 3) | (4 * (v16 & 0xF8 | (32 * (v15 & 0xF8))))) + a3);
        v13 = v17 + 3;
        ++v14;
        --v6;
      }
      while ( v6 != 0 );
      v6 = v19;
      v4 = a1;
    }
    LOBYTE(v12) = *((_BYTE *)v4 + 9);
    *((_BYTE *)v4 + 11) = v12;
    *((_BYTE *)v4 + 8) = 3;
    *((_BYTE *)v4 + 10) = 1;
    v12 = (unsigned __int8)v12;
    if ( (unsigned __int8)v12 >= 8u )
    {
      i = v6 * ((unsigned __int8)v12 >> 3);
      v4[1] = i;
      return i;
    }
    goto LABEL_17;
  }
  if ( (_BYTE)i == 3 && a4 != 0 && *((_BYTE *)a1 + 9) == 8 )
  {
    for ( i = (unsigned int)a2; v6 != 0; --v6 )
    {
      *(_BYTE *)i = *(_BYTE *)(*(unsigned __int8 *)i + a4);
      ++i;
    }
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x101B8EA0
// Name: _png_build_gamma_table
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl png_build_gamma_table(int a1)
{
  double v1; // st7
  double v2; // st7
  int v3; // edi
  long double v4; // st6
  _WORD *v5; // eax
  double v6; // st7
  int v7; // edi
  long double v8; // st6
  void *v9; // eax
  double v10; // st7
  double v11; // st7
  int v12; // edi
  double v13; // st7
  long double v14; // st6
  int v15; // ecx
  int v16; // edi
  int v17; // eax
  double v18; // st7
  int v19; // ebx
  double v20; // st7
  bool v21; // zf
  unsigned int v22; // edi
  double v23; // st7
  long double v24; // st7
  __int16 v25; // cx
  int i; // eax
  unsigned int v27; // ebx
  int v28; // eax
  int j; // eax
  unsigned int v30; // ebx
  double v31; // st7
  unsigned int v32; // eax
  int v33; // edi
  unsigned int v34; // ebx
  long double v35; // st6
  void *v36; // eax
  int v37; // ebx
  double v38; // st7
  int v39; // edi
  long double v40; // st7
  long double v41; // st6
  double v42; // st7
  int v43; // ebx
  double v44; // st7
  int v45; // edi
  long double v46; // st7
  long double v47; // st6
  char v49; // [esp+Ch] [ebp-34h]
  int v50; // [esp+10h] [ebp-30h]
  int v51; // [esp+14h] [ebp-2Ch]
  _WORD *v52; // [esp+14h] [ebp-2Ch]
  unsigned int v53; // [esp+14h] [ebp-2Ch]
  unsigned int v54; // [esp+14h] [ebp-2Ch]
  int v55; // [esp+18h] [ebp-28h]
  int v56; // [esp+18h] [ebp-28h]
  int v57; // [esp+18h] [ebp-28h]
  int v58; // [esp+18h] [ebp-28h]
  char v59; // [esp+1Ch] [ebp-24h]
  unsigned int v60; // [esp+20h] [ebp-20h]
  double v61; // [esp+30h] [ebp-10h]
  double v62; // [esp+30h] [ebp-10h]
  double v63; // [esp+30h] [ebp-10h]
  double v64; // [esp+30h] [ebp-10h]
  double v65; // [esp+30h] [ebp-10h]
  double v66; // [esp+30h] [ebp-10h]
  double v67; // [esp+30h] [ebp-10h]
  double v68; // [esp+38h] [ebp-8h]

  if ( *(_BYTE *)(a1 + 295) <= 8u )
  {
    if ( *(float *)(a1 + 352) <= 0.000001 )
      v1 = 1.0;
    else
      v1 = 1.0 / (*(float *)(a1 + 348) * *(float *)(a1 + 352));
    v61 = v1;
    v2 = 255.0;
    v3 = 0;
    *(_DWORD *)(a1 + 356) = png_malloc(a1, nSize: 0x100u);
    v55 = 0;
    do
    {
      v4 = pow((double)v55 / v2, v61) * 255.0;
      v2 = 255.0;
      v55 = ++v3;
      LOBYTE(v5) = (int)(v4 + 0.5);
      *(_BYTE *)(v3 + *(_DWORD *)(a1 + 356) - 1) = (_BYTE)v5;
    }
    while ( v3 < 256 );
    if ( (*(_DWORD *)(a1 + 112) & 0x600080) != 0 )
    {
      v62 = 1.0 / *(float *)(a1 + 348);
      v6 = 255.0;
      v7 = 0;
      *(_DWORD *)(a1 + 364) = png_malloc(a1, nSize: 0x100u);
      v56 = 0;
      do
      {
        ++v7;
        v8 = pow((double)v56 / v6, v62) * 255.0;
        v6 = 255.0;
        v56 = v7;
        *(_BYTE *)(v7 + *(_DWORD *)(a1 + 364) - 1) = (int)(v8 + 0.5);
      }
      while ( v7 < 256 );
      v9 = png_malloc(a1, nSize: 0x100u);
      v10 = *(float *)(a1 + 352);
      *(_DWORD *)(a1 + 360) = v9;
      if ( v10 <= 0.000001 )
        v11 = *(float *)(a1 + 348);
      else
        v11 = 1.0 / *(float *)(a1 + 352);
      v12 = 0;
      v63 = v11;
      v13 = 255.0;
      v57 = 0;
      do
      {
        v14 = pow((double)v57 / v13, v63) * 255.0;
        v13 = 255.0;
        LOBYTE(v5) = v49;
        v57 = ++v12;
        *(_BYTE *)(v12 + *(_DWORD *)(a1 + 360) - 1) = (int)(v14 + 0.5);
      }
      while ( v12 < 256 );
    }
    return (char)v5;
  }
  if ( (*(_BYTE *)(a1 + 294) & 2) != 0 )
  {
    v15 = *(unsigned __int8 *)(a1 + 380);
    if ( *(unsigned __int8 *)(a1 + 381) > (unsigned int)v15 )
      v15 = *(unsigned __int8 *)(a1 + 381);
    if ( *(unsigned __int8 *)(a1 + 382) > v15 )
      v15 = *(unsigned __int8 *)(a1 + 382);
  }
  else
  {
    v15 = *(unsigned __int8 *)(a1 + 383);
  }
  v16 = 0;
  if ( v15 <= 0 )
  {
    v50 = 0;
    v17 = 0;
  }
  else
  {
    v17 = 16 - v15;
    v50 = 16 - v15;
  }
  if ( (*(_DWORD *)(a1 + 112) & 0x400) != 0 && v17 < 5 )
  {
    v50 = 5;
  }
  else if ( v17 <= 8 )
  {
    if ( v17 >= 0 )
      goto LABEL_33;
    v50 = 0;
  }
  else
  {
    v50 = 8;
  }
  LOBYTE(v17) = v50;
LABEL_33:
  v18 = *(float *)(a1 + 352);
  *(_DWORD *)(a1 + 344) = (unsigned __int8)v17;
  v19 = 1 << (8 - v17);
  v59 = 8 - v17;
  v58 = v19;
  if ( v18 <= 0.000001 )
    v20 = 1.0;
  else
    v20 = 1.0 / (*(float *)(a1 + 348) * *(float *)(a1 + 352));
  v64 = v20;
  v5 = png_malloc(a1, nSize: 4 * v19);
  v21 = (*(_DWORD *)(a1 + 112) & 0x480) == 0;
  *(_DWORD *)(a1 + 368) = v5;
  if ( v21 )
  {
    v52 = nullptr;
    if ( v19 <= 0 )
      goto LABEL_60;
    while ( 1 )
    {
      v31 = 65535.0;
      *(_DWORD *)(*(_DWORD *)(a1 + 368) + 4 * v16) = png_malloc(a1, nSize: 0x200u);
      v32 = (unsigned int)(v16 * dword_102AFD18[v50]) >> 4;
      v33 = 0;
      v34 = v32;
      do
      {
        v35 = pow((double)v34 / v31, v64) * 65535.0;
        v31 = 65535.0;
        v33 += 2;
        v34 += 256;
        *(_WORD *)(v33 + *(_DWORD *)(*(_DWORD *)(a1 + 368) + 4 * (_DWORD)v52) - 2) = (int)(v35 + 0.5);
      }
      while ( v33 < 512 );
      v5 = (_WORD *)((char *)v52 + 1);
      v52 = v5;
      if ( (int)v5 >= v58 )
        break;
      v16 = (int)v5;
    }
  }
  else
  {
    if ( v19 > 0 )
    {
      do
        *(_DWORD *)(*(_DWORD *)(a1 + 368) + 4 * v16++) = png_malloc(a1, nSize: 0x200u);
      while ( v16 < v19 );
    }
    v22 = 0;
    v51 = 0;
    v60 = v19 << 8;
    v65 = 1.0 / v20;
    v23 = (double)(v19 << 8);
    if ( (v19 & 0x800000) != 0 )
      v23 = v23 + 4294967296.0;
    v68 = v23;
    do
    {
      v24 = pow(((double)v51 + 0.5) * 0.00390625, v65) * v68;
      if ( v22 <= (unsigned int)(__int64)v24 )
      {
        LOBYTE(v25) = 0;
        HIBYTE(v25) = v51;
        for ( i = 255 >> v50; ; i = 255 >> v50 )
        {
          v27 = v22 >> v59;
          v28 = *(_DWORD *)(*(_DWORD *)(a1 + 368) + 4 * (v22++ & i));
          *(_WORD *)(v28 + 2 * v27) = v51 | v25;
          if ( v22 > (unsigned int)(__int64)v24 )
            break;
        }
        v19 = v58;
      }
      LOBYTE(v5) = ++v51;
    }
    while ( v51 < 256 );
    if ( v22 >= v60 )
      goto LABEL_60;
    for ( j = 255 >> v50; ; j = 255 >> v50 )
    {
      v5 = *(_WORD **)(*(_DWORD *)(a1 + 368) + 4 * (v22 & j));
      v30 = v22++ >> v59;
      v5[v30] = -1;
      if ( v22 >= v60 )
        break;
    }
  }
  v19 = v58;
LABEL_60:
  if ( (*(_DWORD *)(a1 + 112) & 0x600080) != 0 )
  {
    v66 = 1.0 / *(float *)(a1 + 348);
    v36 = png_malloc(a1, nSize: 4 * v19);
    v37 = 0;
    for ( *(_DWORD *)(a1 + 376) = v36; v37 < v58; ++v37 )
    {
      v38 = 65535.0;
      *(_DWORD *)(*(_DWORD *)(a1 + 376) + 4 * v37) = png_malloc(a1, nSize: 0x200u);
      v39 = 0;
      v53 = (unsigned int)(v37 * dword_102AFD18[v50]) >> 4;
      do
      {
        v40 = pow((double)v53 / v38, v66);
        v53 += 256;
        v41 = v40 * 65535.0;
        v38 = 65535.0;
        v39 += 2;
        *(_WORD *)(v39 + *(_DWORD *)(*(_DWORD *)(a1 + 376) + 4 * v37) - 2) = (int)(v41 + 0.5);
      }
      while ( v39 < 512 );
    }
    if ( *(float *)(a1 + 352) <= 0.000001 )
      v42 = *(float *)(a1 + 348);
    else
      v42 = 1.0 / *(float *)(a1 + 352);
    v67 = v42;
    v5 = png_malloc(a1, nSize: 4 * v58);
    v43 = 0;
    for ( *(_DWORD *)(a1 + 372) = v5; v43 < v58; ++v43 )
    {
      v44 = 65535.0;
      *(_DWORD *)(*(_DWORD *)(a1 + 372) + 4 * v43) = png_malloc(a1, nSize: 0x200u);
      v45 = 0;
      v54 = (unsigned int)(v43 * dword_102AFD18[v50]) >> 4;
      do
      {
        v46 = pow((double)v54 / v44, v67);
        v54 += 256;
        v47 = v46 * 65535.0;
        v44 = 65535.0;
        v5 = *(_WORD **)(*(_DWORD *)(a1 + 372) + 4 * v43);
        v5[v45++] = (int)(v47 + 0.5);
      }
      while ( v45 < 256 );
    }
  }
  return (char)v5;
}

//------------------------------------------------------------------------------
// Address: 0x101B95B0
// Name: _png_do_read_intrapixel
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl png_do_read_intrapixel(int *a1, int a2)
{
  _BYTE *v2; // eax
  char v3; // cl
  int v4; // edx
  int v5; // edi
  char v6; // cl
  int v7; // edi
  int v8; // esi
  __int16 v9; // bx
  __int16 v10; // cx
  __int16 v11; // dx
  __int16 v12; // dx
  __int16 v13; // cx

  LOBYTE(v2) = (_BYTE)a1;
  v3 = *((_BYTE *)a1 + 8);
  if ( (v3 & 2) != 0 )
  {
    v4 = *a1;
    LOBYTE(v2) = *((_BYTE *)a1 + 9);
    if ( (_BYTE)v2 == 8 )
    {
      if ( v3 == 2 )
      {
        v5 = 3;
      }
      else
      {
        if ( v3 != 6 )
          return (char)v2;
        v5 = 4;
      }
      if ( v4 != 0 )
      {
        v2 = (_BYTE *)(a2 + 2);
        do
        {
          v6 = *(v2 - 1);
          *(v2 - 2) += v6;
          *v2 += v6;
          v2 += v5;
          --v4;
        }
        while ( v4 != 0 );
      }
    }
    else if ( (_BYTE)v2 == 16 )
    {
      if ( v3 == 2 )
      {
        v7 = 6;
      }
      else
      {
        if ( v3 != 6 )
          return (char)v2;
        v7 = 8;
      }
      if ( v4 != 0 )
      {
        v2 = (_BYTE *)(a2 + 1);
        v8 = *a1;
        do
        {
          HIBYTE(v9) = v2[3];
          HIBYTE(v10) = v2[1];
          HIBYTE(v11) = *(v2 - 1);
          LOBYTE(v9) = v2[4];
          LOBYTE(v10) = v2[2];
          LOBYTE(v11) = *v2;
          v12 = v10 + v11;
          v13 = v10 + v9;
          *v2 = v12;
          *(v2 - 1) = HIBYTE(v12);
          v2[3] = HIBYTE(v13);
          v2[4] = v13;
          v2 += v7;
          --v8;
        }
        while ( v8 != 0 );
      }
    }
  }
  return (char)v2;
}

//------------------------------------------------------------------------------
// Address: 0x101B9680
// Name: _png_init_read_transformations
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_init_read_transformations(int a1)
{
  int v2; // ecx
  int v3; // ebx
  __int16 v4; // dx
  __int16 v5; // ax
  __int16 v6; // ax
  __int16 v7; // ax
  __int16 v8; // ax
  __int16 v9; // ax
  unsigned __int8 *v10; // eax
  int v11; // edi
  int v12; // eax
  _BYTE *v13; // ecx
  int v14; // ecx
  __int16 v15; // dx
  int v16; // ebp
  int v17; // ecx
  char v18; // al
  int v19; // ecx
  int v20; // ebp
  unsigned __int8 v21; // al
  int v22; // ecx
  int v23; // eax
  int v24; // edi
  int v25; // edx
  int v26; // eax
  unsigned __int8 v27; // bl
  int v28; // eax
  int v29; // eax
  double v30; // st7
  double v31; // st6
  long double v32; // rt2
  long double v33; // st6
  long double v34; // st7
  double v35; // st7
  char v36; // dl
  int v37; // edi
  _BYTE *v38; // eax
  int v39; // ecx
  char v40; // dl
  unsigned __int8 *v41; // ecx
  char v42; // cl
  unsigned int v43; // ecx
  unsigned int v44; // ecx
  unsigned int v45; // ecx
  int v46; // ecx
  int v47; // edx
  double v48; // st7
  long double v49; // st6
  unsigned __int16 v50; // di
  unsigned __int16 v51; // cx
  __int16 v52; // ax
  __int16 v53; // cx
  int v54; // ecx
  int v55; // ecx
  _BYTE *v56; // eax
  int v57; // ebp
  int v58; // eax
  int v59; // edi
  unsigned __int8 v60; // dl
  unsigned __int8 *v61; // eax
  int v62; // ecx
  char v63; // bl
  unsigned __int8 *v64; // ecx
  unsigned int v65; // ecx
  unsigned int v66; // ecx
  unsigned int v67; // ecx
  unsigned __int16 v68; // dx
  int v69; // ebx
  int v70; // eax
  int i; // edi
  __int16 v72; // [esp+Ch] [ebp-3Ch]
  char v73; // [esp+Eh] [ebp-3Ah]
  double v74; // [esp+10h] [ebp-38h]
  unsigned __int8 v75; // [esp+11h] [ebp-37h]
  unsigned __int8 v76; // [esp+12h] [ebp-36h]
  int v77; // [esp+18h] [ebp-30h]
  char v78; // [esp+18h] [ebp-30h]
  double v79; // [esp+1Ch] [ebp-2Ch]
  int v80; // [esp+24h] [ebp-24h]
  int v81; // [esp+24h] [ebp-24h]
  double v82; // [esp+28h] [ebp-20h]
  double v83; // [esp+28h] [ebp-20h]
  long double v84; // [esp+30h] [ebp-18h]
  long double v85; // [esp+30h] [ebp-18h]
  long double v86; // [esp+38h] [ebp-10h]
  long double v87; // [esp+40h] [ebp-8h]
  __int16 v88; // [esp+4Ch] [ebp+4h]
  char v89; // [esp+4Ch] [ebp+4h]

  v2 = *(_DWORD *)(a1 + 112);
  v3 = *(unsigned __int8 *)(a1 + 294);
  v77 = (unsigned __int8)v3;
  if ( (v2 & 0x100) != 0 && (v3 & 2) == 0 )
    goto LABEL_9;
  if ( (v2 & 0x80u) == 0 )
    goto LABEL_10;
  if ( (v2 & 0x100) == 0 )
  {
    if ( (v2 & 0x4000) == 0 || (v4 = *(_WORD *)(a1 + 314)) != *(_WORD *)(a1 + 316) || v4 != *(_WORD *)(a1 + 318) )
    {
LABEL_10:
      if ( (v2 & 0x100) == 0 )
        goto LABEL_27;
      goto LABEL_11;
    }
    *(_WORD *)(a1 + 320) = v4;
LABEL_9:
    *(_DWORD *)(a1 + 104) |= 0x800u;
    goto LABEL_10;
  }
LABEL_11:
  if ( (v2 & 0x1000) != 0 )
  {
    if ( (v3 & 2) != 0 )
    {
      if ( v3 == 3 )
      {
        v10 = (unsigned __int8 *)(3 * *(unsigned __int8 *)(a1 + 312) + *(_DWORD *)(a1 + 276));
        *(_WORD *)(a1 + 314) = *v10;
        *(_WORD *)(a1 + 316) = v10[1];
        *(_WORD *)(a1 + 318) = v10[2];
        if ( (v2 & 0x80000) != 0 && (v2 & 0x2000000) == 0 )
        {
          v11 = *(unsigned __int16 *)(a1 + 282);
          v12 = 0;
          if ( *(_WORD *)(a1 + 282) != 0 )
          {
            do
            {
              v13 = (_BYTE *)(v12 + *(_DWORD *)(a1 + 392));
              ++v12;
              *v13 = -1 - *v13;
            }
            while ( v12 < v11 );
          }
        }
      }
    }
    else
    {
      switch ( *(_BYTE *)(a1 + 295) )
      {
        case 1:
          v5 = 255 * *(_WORD *)(a1 + 320);
          *(_WORD *)(a1 + 320) = v5;
          *(_WORD *)(a1 + 318) = v5;
          *(_WORD *)(a1 + 316) = v5;
          *(_WORD *)(a1 + 314) = v5;
          if ( (v2 & 0x2000000) == 0 )
          {
            v6 = 255 * *(_WORD *)(a1 + 404);
            goto LABEL_16;
          }
          break;
        case 2:
          v7 = 85 * *(_WORD *)(a1 + 320);
          *(_WORD *)(a1 + 320) = v7;
          *(_WORD *)(a1 + 318) = v7;
          *(_WORD *)(a1 + 316) = v7;
          *(_WORD *)(a1 + 314) = v7;
          if ( (v2 & 0x2000000) == 0 )
          {
            v6 = 85 * *(_WORD *)(a1 + 404);
            goto LABEL_16;
          }
          break;
        case 4:
          v8 = 17 * *(_WORD *)(a1 + 320);
          *(_WORD *)(a1 + 320) = v8;
          *(_WORD *)(a1 + 318) = v8;
          *(_WORD *)(a1 + 316) = v8;
          *(_WORD *)(a1 + 314) = v8;
          if ( (v2 & 0x2000000) == 0 )
          {
            v6 = 17 * *(_WORD *)(a1 + 404);
LABEL_16:
            *(_WORD *)(a1 + 404) = v6;
            *(_WORD *)(a1 + 402) = v6;
            *(_WORD *)(a1 + 400) = v6;
            *(_WORD *)(a1 + 398) = v6;
          }
          break;
        case 8:
        case 0x10:
          v9 = *(_WORD *)(a1 + 320);
          *(_WORD *)(a1 + 318) = v9;
          *(_WORD *)(a1 + 316) = v9;
          *(_WORD *)(a1 + 314) = v9;
          break;
        default:
          break;
      }
    }
  }
LABEL_27:
  v14 = *(_DWORD *)(a1 + 316);
  v15 = *(_WORD *)(a1 + 320);
  *(_DWORD *)(a1 + 322) = *(_DWORD *)(a1 + 312);
  *(_DWORD *)(a1 + 326) = v14;
  *(_WORD *)(a1 + 330) = v15;
  if ( v3 == 3 && *(_WORD *)(a1 + 282) != 0 && fabs(*(float *)(a1 + 352) * *(float *)(a1 + 348) - 1.0) < 0.05 )
  {
    v16 = 0;
    v17 = 0;
    do
    {
      v18 = *(_BYTE *)(*(_DWORD *)(a1 + 392) + v17);
      if ( v18 != 0 && v18 != -1 )
        v16 = 1;
      ++v17;
    }
    while ( v17 < *(unsigned __int16 *)(a1 + 282) );
    if ( v16 == 0 )
      *(_DWORD *)(a1 + 112) &= ~0x2000u;
  }
  v19 = *(_DWORD *)(a1 + 112);
  if ( (v19 & 0x602000) == 0 || 0.0 == *(float *)(a1 + 348) )
  {
    if ( (v19 & 0x80u) != 0 && (unsigned __int8)v3 == 3 )
    {
      v57 = *(unsigned __int16 *)(a1 + 282);
      v58 = *(_DWORD *)(a1 + 276);
      v59 = 0;
      HIBYTE(v88) = *(_BYTE *)(a1 + 316);
      v60 = *(_BYTE *)(a1 + 318);
      v81 = *(unsigned __int16 *)(a1 + 282);
      LOBYTE(v88) = *(_BYTE *)(a1 + 314);
      if ( *(_WORD *)(a1 + 282) != 0 )
      {
        v61 = (unsigned __int8 *)(v58 + 2);
        do
        {
          v62 = *(_DWORD *)(a1 + 392);
          v63 = *(_BYTE *)(v62 + v59);
          v64 = (unsigned __int8 *)(v59 + v62);
          if ( v63 != 0 )
          {
            if ( v63 != -1 )
            {
              v65 = (unsigned __int16)(*v64 * *(v61 - 2) + (unsigned __int8)v88 * (255 - *v64) + 128);
              *(v61 - 2) = (unsigned __int16)(v65 + (v65 >> 8)) >> 8;
              LOWORD(v65) = *(unsigned __int8 *)(v59 + *(_DWORD *)(a1 + 392));
              v66 = (unsigned __int16)(v65 * *(v61 - 1) + HIBYTE(v88) * (255 - v65) + 128);
              *(v61 - 1) = (unsigned __int16)(v66 + (v66 >> 8)) >> 8;
              LOWORD(v66) = *(unsigned __int8 *)(v59 + *(_DWORD *)(a1 + 392));
              v57 = v81;
              v67 = (unsigned __int16)(v66 * *v61 + v60 * (255 - v66) + 128);
              *v61 = (unsigned __int16)(v67 + (v67 >> 8)) >> 8;
            }
          }
          else
          {
            *((_WORD *)v61 - 1) = v88;
            *v61 = v60;
          }
          ++v59;
          v61 += 3;
        }
        while ( v59 < v57 );
      }
    }
  }
  else
  {
    png_build_gamma_table(a1);
    if ( *(char *)(a1 + 112) >= 0 )
    {
      if ( v3 == 3 )
      {
        v55 = *(unsigned __int16 *)(a1 + 280);
        if ( *(_WORD *)(a1 + 280) != 0 )
        {
          v56 = (_BYTE *)(*(_DWORD *)(a1 + 276) + 2);
          do
          {
            *(v56 - 2) = *(_BYTE *)((unsigned __int8)*(v56 - 2) + *(_DWORD *)(a1 + 356));
            *(v56 - 1) = *(_BYTE *)((unsigned __int8)*(v56 - 1) + *(_DWORD *)(a1 + 356));
            *v56 = *(_BYTE *)((unsigned __int8)*v56 + *(_DWORD *)(a1 + 356));
            v56 += 3;
            --v55;
          }
          while ( v55 != 0 );
        }
      }
    }
    else
    {
      if ( v3 == 3 )
      {
        v20 = *(unsigned __int16 *)(a1 + 280);
        v21 = *(_BYTE *)(a1 + 304);
        v80 = v20;
        if ( v21 == 2 )
        {
          v22 = *(unsigned __int16 *)(a1 + 314);
          v23 = *(_DWORD *)(a1 + 356);
          v24 = *(unsigned __int16 *)(a1 + 316);
          LOBYTE(v72) = *(_BYTE *)(v23 + v22);
          HIBYTE(v72) = *(_BYTE *)(v24 + v23);
          v25 = *(unsigned __int16 *)(a1 + 318);
          v73 = *(_BYTE *)(v25 + v23);
          v26 = *(_DWORD *)(a1 + 364);
          v27 = *(_BYTE *)(v26 + v22);
          v75 = *(_BYTE *)(v26 + v24);
          v76 = *(_BYTE *)(v26 + v25);
          goto LABEL_55;
        }
        v28 = v21 - 1;
        if ( v28 != 0 )
        {
          v29 = v28 - 1;
          if ( v29 != 0 )
          {
            if ( v29 != 1 )
            {
              v30 = 1.0;
              v79 = 1.0;
LABEL_50:
              v31 = v30;
              goto LABEL_51;
            }
            v30 = 1.0;
            v79 = 1.0 / *(float *)(a1 + 308);
            v31 = 1.0 / (*(float *)(a1 + 352) * *(float *)(a1 + 308));
          }
          else
          {
            v30 = 1.0;
            v79 = 1.0 / *(float *)(a1 + 348);
            v31 = 1.0 / (*(float *)(a1 + 352) * *(float *)(a1 + 348));
          }
LABEL_51:
          v82 = v31;
          v32 = v31;
          v33 = v31 - v30;
          v34 = v32;
          if ( fabs(v33) >= 0.05 )
          {
            LOBYTE(v72) = (int)(pow((double)*(unsigned __int16 *)(a1 + 314) / 255.0, v34) * 255.0 + 0.5);
            HIBYTE(v72) = (int)(pow((double)*(unsigned __int16 *)(a1 + 316) / 255.0, v82) * 255.0 + 0.5);
            v35 = 255.0;
            v36 = (int)(pow((double)*(unsigned __int16 *)(a1 + 318) / 255.0, v82) * 255.0 + 0.5);
          }
          else
          {
            v35 = 255.0;
            v36 = *(_BYTE *)(a1 + 318);
            LOBYTE(v72) = *(_BYTE *)(a1 + 314);
            HIBYTE(v72) = *(_BYTE *)(a1 + 316);
          }
          v73 = v36;
          v27 = (int)(pow((double)*(unsigned __int16 *)(a1 + 314) / v35, v79) * 255.0 + 0.5);
          v75 = (int)(pow((double)*(unsigned __int16 *)(a1 + 316) / 255.0, v79) * 255.0 + 0.5);
          v76 = (int)(pow((double)*(unsigned __int16 *)(a1 + 318) / 255.0, v79) * 255.0 + 0.5);
LABEL_55:
          v37 = 0;
          if ( *(_WORD *)(a1 + 280) != 0 )
          {
            v38 = (_BYTE *)(*(_DWORD *)(a1 + 276) + 2);
            do
            {
              if ( v37 >= *(unsigned __int16 *)(a1 + 282)
                || (v39 = *(_DWORD *)(a1 + 392),
                    v40 = *(_BYTE *)(v39 + v37),
                    v41 = (unsigned __int8 *)(v37 + v39),
                    v40 == -1) )
              {
                v46 = (unsigned __int8)*(v38 - 1);
                *(v38 - 2) = *(_BYTE *)((unsigned __int8)*(v38 - 2) + *(_DWORD *)(a1 + 356));
                v47 = (unsigned __int8)*v38;
                *(v38 - 1) = *(_BYTE *)(v46 + *(_DWORD *)(a1 + 356));
                *v38 = *(_BYTE *)(v47 + *(_DWORD *)(a1 + 356));
              }
              else
              {
                if ( v40 != 0 )
                {
                  v43 = (unsigned __int16)(v27 * (255 - *v41)
                                         + *v41
                                         * *(unsigned __int8 *)((unsigned __int8)*(v38 - 2) + *(_DWORD *)(a1 + 364))
                                         + 128);
                  *(v38 - 2) = *(_BYTE *)((unsigned __int8)((unsigned __int16)(v43 + (v43 >> 8)) >> 8)
                                        + *(_DWORD *)(a1 + 360));
                  LOWORD(v43) = *(unsigned __int8 *)(*(_DWORD *)(a1 + 392) + v37);
                  v44 = (unsigned __int16)(v75 * (255 - v43)
                                         + v43
                                         * *(unsigned __int8 *)((unsigned __int8)*(v38 - 1) + *(_DWORD *)(a1 + 364))
                                         + 128);
                  *(v38 - 1) = *(_BYTE *)((unsigned __int8)((unsigned __int16)(v44 + (v44 >> 8)) >> 8)
                                        + *(_DWORD *)(a1 + 360));
                  LOWORD(v44) = *(unsigned __int8 *)(*(_DWORD *)(a1 + 392) + v37);
                  v20 = v80;
                  v45 = (unsigned __int16)(v76 * (255 - v44)
                                         + v44 * *(unsigned __int8 *)((unsigned __int8)*v38 + *(_DWORD *)(a1 + 364))
                                         + 128);
                  v42 = *(_BYTE *)((unsigned __int8)((unsigned __int16)(v45 + (v45 >> 8)) >> 8) + *(_DWORD *)(a1 + 360));
                }
                else
                {
                  v42 = v73;
                  *((_WORD *)v38 - 1) = v72;
                }
                *v38 = v42;
              }
              ++v37;
              v38 += 3;
            }
            while ( v37 < v20 );
          }
          goto LABEL_91;
        }
        v79 = *(float *)(a1 + 352);
        v30 = 1.0;
        goto LABEL_50;
      }
      v48 = (double)(unsigned int)((1 << *(_BYTE *)(a1 + 295)) - 1);
      v83 = 1.0;
      v49 = 1.0;
      v74 = 1.0;
      switch ( *(_BYTE *)(a1 + 304) )
      {
        case 1:
          v83 = *(float *)(a1 + 352);
          v49 = v83;
          v74 = 1.0;
          break;
        case 2:
          v83 = 1.0 / *(float *)(a1 + 348);
          v49 = v83;
          v74 = 1.0 / (*(float *)(a1 + 352) * *(float *)(a1 + 348));
          break;
        case 3:
          v83 = 1.0 / *(float *)(a1 + 308);
          v49 = v83;
          v74 = 1.0 / (*(float *)(a1 + 352) * *(float *)(a1 + 308));
          break;
        default:
          break;
      }
      v84 = (double)*(unsigned __int16 *)(a1 + 320) / v48;
      *(_WORD *)(a1 + 330) = (int)(pow(v84, v49) * v48 + 0.5);
      v50 = *(_WORD *)(a1 + 316);
      v51 = *(_WORD *)(a1 + 314);
      v52 = (int)(pow(v84, v74) * v48 + 0.5);
      *(_WORD *)(a1 + 320) = v52;
      if ( v51 == v50 && v51 == *(_WORD *)(a1 + 318) && v51 == v52 )
      {
        v53 = *(_WORD *)(a1 + 330);
        *(_WORD *)(a1 + 328) = v53;
        *(_WORD *)(a1 + 326) = v53;
        *(_WORD *)(a1 + 324) = v53;
        *(_WORD *)(a1 + 318) = v52;
        *(_WORD *)(a1 + 316) = v52;
        *(_WORD *)(a1 + 314) = v52;
      }
      else
      {
        v85 = (double)v51 / v48;
        *(_WORD *)(a1 + 324) = (int)(pow(v85, v83) * v48 + 0.5);
        v86 = (double)v50 / v48;
        v54 = *(unsigned __int16 *)(a1 + 318);
        *(_WORD *)(a1 + 326) = (int)(pow(v86, v83) * v48 + 0.5);
        v87 = (double)v54 / v48;
        *(_WORD *)(a1 + 328) = (int)(pow(v87, v83) * v48 + 0.5);
        *(_WORD *)(a1 + 314) = (int)(pow(v85, v74) * v48 + 0.5);
        *(_WORD *)(a1 + 316) = (int)(pow(v86, v74) * v48 + 0.5);
        *(_WORD *)(a1 + 318) = (int)(pow(v87, v74) * v48 + 0.5);
      }
    }
  }
LABEL_91:
  if ( (*(_BYTE *)(a1 + 112) & 8) != 0 && v77 == 3 )
  {
    v68 = *(_WORD *)(a1 + 280);
    v69 = 8 - *(unsigned __int8 *)(a1 + 380);
    v89 = 8 - *(_BYTE *)(a1 + 381);
    v78 = 8 - *(_BYTE *)(a1 + 382);
    if ( *(unsigned __int8 *)(a1 + 380) > 8u || v69 > 8 )
      LOBYTE(v69) = 0;
    if ( 8 - (unsigned int)*(unsigned __int8 *)(a1 + 381) > 8 )
      v89 = 0;
    if ( 8 - (unsigned int)*(unsigned __int8 *)(a1 + 382) > 8 )
      v78 = 0;
    if ( v68 != 0 )
    {
      v70 = 0;
      for ( i = v68; i != 0; --i )
      {
        *(_BYTE *)(v70 + *(_DWORD *)(a1 + 276)) >>= v69;
        *(_BYTE *)(v70 + *(_DWORD *)(a1 + 276) + 1) >>= v89;
        *(_BYTE *)(v70 + *(_DWORD *)(a1 + 276) + 2) >>= v78;
        v70 += 3;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BA3B0
// Name: _png_do_read_transformations
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_do_read_transformations(int a1)
{
  int v1; // eax
  bool v2; // zf
  int v3; // eax
  void (__cdecl *v4)(int, int, int); // eax
  char v5; // al
  char v6; // al
  unsigned __int8 v7; // al
  unsigned int v8; // eax
  char string[52]; // [esp+4h] [ebp-38h] BYREF

  if ( *(_DWORD *)(a1 + 236) == 0 )
  {
    sprintf(
      string,
      format: "NULL row buffer for row %ld, pass %d",
      *(_DWORD *)(a1 + 228),
      *(unsigned __int8 *)(a1 + 292));
    png_error((int *)a1, a2: (unsigned __int8 *)string);
  }
  v1 = *(_DWORD *)(a1 + 112);
  if ( (v1 & 0x1000) != 0 )
  {
    if ( *(_BYTE *)(a1 + 264) == 3 )
    {
      png_do_expand_palette(
        a1: (int *)(a1 + 256),
        a2: *(_DWORD *)(a1 + 236) + 1,
        a3: *(_DWORD *)(a1 + 276),
        a4: *(_DWORD *)(a1 + 392),
        a5: *(unsigned __int16 *)(a1 + 282));
    }
    else if ( *(_WORD *)(a1 + 282) != 0 && (v1 & 0x2000000) != 0 )
    {
      png_do_expand(a1: (int *)(a1 + 256), a2: *(_DWORD *)(a1 + 236) + 1, a3: (_WORD *)(a1 + 396));
    }
    else
    {
      png_do_expand(a1: (int *)(a1 + 256), a2: *(_DWORD *)(a1 + 236) + 1, a3: nullptr);
    }
  }
  if ( (*(_DWORD *)(a1 + 108) & 0x400000) != 0 )
    png_do_strip_filler(
      a1: a1 + 256,
      a2: (_BYTE *)(*(_DWORD *)(a1 + 236) + 1),
      a3: *(_DWORD *)(a1 + 108) & 0x400000 | 0x80);
  if ( (*(_DWORD *)(a1 + 112) & 0x600000) != 0
    && png_do_rgb_to_gray(a1, a2: (int *)(a1 + 256), a3: (unsigned __int8 *)(*(_DWORD *)(a1 + 236) + 1)) != 0 )
  {
    v2 = (*(_DWORD *)(a1 + 112) & 0x400000) == 0;
    *(_BYTE *)(a1 + 552) = 1;
    if ( !v2 )
      png_warning(a1, a2: "png_do_rgb_to_gray found nongray pixel");
    if ( (*(_DWORD *)(a1 + 112) & 0x200000) != 0 )
      png_error((int *)a1, a2: "png_do_rgb_to_gray found nongray pixel");
  }
  if ( (*(_DWORD *)(a1 + 112) & 0x4000) != 0 && (*(_DWORD *)(a1 + 104) & 0x800) == 0 )
    png_do_gray_to_rgb(a1: (int *)(a1 + 256), a2: *(_DWORD *)(a1 + 236) + 1);
  if ( *(char *)(a1 + 112) < 0 && (*(_WORD *)(a1 + 282) != 0 || (*(_BYTE *)(a1 + 294) & 4) != 0) )
    png_do_background(
      a1: (int *)(a1 + 256),
      a2: (unsigned __int8 *)(*(_DWORD *)(a1 + 236) + 1),
      a3: (_WORD *)(a1 + 396),
      a4: (_BYTE *)(a1 + 312),
      a5: (_WORD *)(a1 + 322),
      a6: *(_DWORD *)(a1 + 356),
      a7: *(_DWORD *)(a1 + 360),
      a8: *(_DWORD *)(a1 + 364),
      a9: *(_DWORD *)(a1 + 368),
      a10: *(_DWORD *)(a1 + 372),
      a11: *(_DWORD *)(a1 + 376),
      a12: *(_DWORD *)(a1 + 344));
  v3 = *(_DWORD *)(a1 + 112);
  if ( (v3 & 0x2000) != 0
    && ((v3 & 0x80u) == 0 || *(_WORD *)(a1 + 282) == 0 && (*(_BYTE *)(a1 + 294) & 4) == 0)
    && *(_BYTE *)(a1 + 294) != 3 )
  {
    png_do_gamma(
      a1: (int *)(a1 + 256),
      a2: (unsigned __int8 *)(*(_DWORD *)(a1 + 236) + 1),
      a3: *(_DWORD *)(a1 + 356),
      a4: *(_DWORD *)(a1 + 368),
      a5: *(_DWORD *)(a1 + 344));
  }
  if ( (*(_DWORD *)(a1 + 112) & 0x400) != 0 )
    png_do_chop(a1: a1 + 256, a2: (_BYTE *)(*(_DWORD *)(a1 + 236) + 1));
  if ( (*(_BYTE *)(a1 + 112) & 0x40) != 0 )
  {
    png_do_dither(
      a1: (int *)(a1 + 256),
      a2: (char *)(*(_DWORD *)(a1 + 236) + 1),
      a3: *(_DWORD *)(a1 + 492),
      a4: *(_DWORD *)(a1 + 496));
    if ( *(_DWORD *)(a1 + 260) == 0 )
      png_error((int *)a1, a2: "png_do_dither returned rowbytes=0");
  }
  if ( (*(_BYTE *)(a1 + 112) & 0x20) != 0 )
    png_do_invert(a1: a1 + 256, a2: (_BYTE *)(*(_DWORD *)(a1 + 236) + 1));
  if ( (*(_BYTE *)(a1 + 112) & 8) != 0 )
    png_do_unshift(a1: (int *)(a1 + 256), a2: (_BYTE *)(*(_DWORD *)(a1 + 236) + 1), a3: (unsigned __int8 *)(a1 + 385));
  if ( (*(_BYTE *)(a1 + 112) & 4) != 0 )
    png_do_unpack(a1: (int *)(a1 + 256), a2: *(_DWORD *)(a1 + 236) + 1);
  if ( (*(_BYTE *)(a1 + 112) & 1) != 0 )
    png_do_bgr(a1: (int *)(a1 + 256), a2: (char *)(*(_DWORD *)(a1 + 236) + 1));
  if ( (*(_DWORD *)(a1 + 112) & 0x10000) != 0 )
    png_do_packswap(a1: a1 + 256, a2: (_BYTE *)(*(_DWORD *)(a1 + 236) + 1));
  if ( (*(_DWORD *)(a1 + 112) & 0x4000) != 0 && (*(_DWORD *)(a1 + 104) & 0x800) != 0 )
    png_do_gray_to_rgb(a1: (int *)(a1 + 256), a2: *(_DWORD *)(a1 + 236) + 1);
  if ( (*(_DWORD *)(a1 + 112) & 0x8000) != 0 )
    png_do_read_filler(
      a1: a1 + 256,
      a2: *(_DWORD *)(a1 + 236) + 1,
      a3: *(unsigned __int16 *)(a1 + 302),
      a4: *(_DWORD *)(a1 + 108));
  if ( (*(_DWORD *)(a1 + 112) & 0x80000) != 0 )
    png_do_read_invert_alpha(a1: (int *)(a1 + 256), a2: *(_DWORD *)(a1 + 236) + 1);
  if ( (*(_DWORD *)(a1 + 112) & 0x20000) != 0 )
    png_do_read_swap_alpha(a1: (int *)(a1 + 256), a2: *(_DWORD *)(a1 + 236) + 1);
  if ( (*(_BYTE *)(a1 + 112) & 0x10) != 0 )
    png_do_swap(a1: a1 + 256, a2: (char *)(*(_DWORD *)(a1 + 236) + 1));
  if ( (*(_DWORD *)(a1 + 112) & 0x100000) != 0 )
  {
    v4 = *(void (__cdecl **)(int, int, int))(a1 + 88);
    if ( v4 != nullptr )
      v4(a1, a2: a1 + 256, a3: *(_DWORD *)(a1 + 236) + 1);
    v5 = *(_BYTE *)(a1 + 100);
    if ( v5 != 0 )
      *(_BYTE *)(a1 + 265) = v5;
    v6 = *(_BYTE *)(a1 + 101);
    if ( v6 != 0 )
      *(_BYTE *)(a1 + 266) = v6;
    v7 = *(_BYTE *)(a1 + 265) * *(_BYTE *)(a1 + 266);
    *(_BYTE *)(a1 + 267) = v7;
    if ( v7 < 8u )
      v8 = (*(_DWORD *)(a1 + 256) * (unsigned int)v7 + 7) >> 3;
    else
      v8 = *(_DWORD *)(a1 + 256) * (v7 >> 3);
    *(_DWORD *)(a1 + 260) = v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BA860
// Name: _png_set_sig_bytes
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__usercall png_set_sig_bytes@<eax>(int *result@<eax>, int a2, int a3)
{
  if ( a2 != 0 )
  {
    if ( a3 > 8 )
      result = png_error(a1: (int *)a2, a2: "Too many bytes for PNG signature.");
    LOBYTE(result) = (a3 < 0) - 1;
    result = (int *)(a3 & (unsigned int)result);
    *(_BYTE *)(a2 + 300) = (_BYTE)result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BA8A0
// Name: _png_sig_cmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl png_sig_cmp(int a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // eax
  unsigned __int8 *v4; // ecx
  _DWORD *v5; // edx
  int v6; // esi
  unsigned int v7; // eax
  unsigned __int8 *v8; // ecx
  unsigned __int8 *v9; // edx
  unsigned int v10; // eax
  unsigned __int8 *v11; // ecx
  unsigned __int8 *v12; // edx
  unsigned __int8 *v13; // ecx
  unsigned __int8 *v14; // edx
  int result; // eax
  _BYTE v16[8]; // [esp+0h] [ebp-Ch] BYREF

  v16[5] = 10;
  v16[7] = 10;
  v3 = a3;
  v16[0] = -119;
  v16[1] = 80;
  v16[2] = 78;
  v16[3] = 71;
  v16[4] = 13;
  v16[6] = 26;
  if ( a3 <= 8 )
  {
    if ( a3 == 0 )
      return -1;
  }
  else
  {
    v3 = 8;
  }
  if ( a2 > 7 )
    return -1;
  if ( a2 + v3 > 8 )
    v3 = 8 - a2;
  v4 = &v16[a2];
  v5 = (_DWORD *)(a1 + a2);
  if ( v3 < 4 )
  {
LABEL_9:
    if ( v3 == 0 )
      return 0;
  }
  else
  {
    while ( *v5 == *(_DWORD *)v4 )
    {
      v3 -= 4;
      v4 += 4;
      ++v5;
      if ( v3 < 4 )
        goto LABEL_9;
    }
  }
  v6 = *(unsigned __int8 *)v5 - *v4;
  if ( v6 == 0 )
  {
    v7 = v3 - 1;
    v8 = v4 + 1;
    v9 = (unsigned __int8 *)v5 + 1;
    if ( v7 == 0 )
      return 0;
    v6 = *v9 - *v8;
    if ( v6 == 0 )
    {
      v10 = v7 - 1;
      v11 = v8 + 1;
      v12 = v9 + 1;
      if ( v10 == 0 )
        return 0;
      v6 = *v12 - *v11;
      if ( v6 == 0 )
      {
        v13 = v11 + 1;
        v14 = v12 + 1;
        if ( v10 == 1 )
          return 0;
        v6 = *v14 - *v13;
        if ( v6 == 0 )
          return 0;
      }
    }
  }
  result = 1;
  if ( v6 <= 0 )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BA9D0
// Name: _png_check_sig
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl png_check_sig(int a1, unsigned int a2)
{
  return png_sig_cmp(a1, a2: 0, a3: a2) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x101BA9F0
// Name: _png_zalloc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl png_zalloc(int a1, unsigned int a2, unsigned int a3)
{
  int v3; // edi
  void *result; // eax

  v3 = *(_DWORD *)(a1 + 108);
  if ( a2 <= 0xFFFFFFFF / a3 )
  {
    *(_DWORD *)(a1 + 108) = v3 | 0x100000;
    result = png_malloc(a1, nSize: a3 * a2);
    *(_DWORD *)(a1 + 108) = v3;
  }
  else
  {
    png_warning(a1, a2: "Potential overflow in png_zalloc()");
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BAA40
// Name: _png_zfree
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl png_zfree(int a1, void *pMem)
{
  png_free(a1, pMem);
}

//------------------------------------------------------------------------------
// Address: 0x101BAA50
// Name: _png_reset_crc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl png_reset_crc(int a1)
{
  int result; // eax

  result = crc32(a1: 0, a2: nullptr, a3: 0);
  *(_DWORD *)(a1 + 272) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101BAA70
// Name: _png_calculate_crc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_calculate_crc(int a1, _BYTE *a2, unsigned int a3)
{
  if ( (*(_BYTE *)(a1 + 284) & 0x20) == 0 )
  {
    if ( (*(_DWORD *)(a1 + 108) & 0x800) != 0 )
      return;
    goto LABEL_5;
  }
  if ( (*(_DWORD *)(a1 + 108) & 0x300) != 0x300 )
LABEL_5:
    *(_DWORD *)(a1 + 272) = crc32(a1: *(_DWORD *)(a1 + 272), a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x101BAAC0
// Name: _png_info_init_3
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_info_init_3(void **a1, unsigned int a2)
{
  if ( *a1 != nullptr )
  {
    if ( a2 < 0x120 )
      png_destroy_struct(pMem: *a1);
    memset(dst: (unsigned __int8 *)*a1, value: 0, count: 0x120u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101BAB00
// Name: _png_free_data
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_free_data(int a1, int a2, int a3, int a4)
{
  int v4; // ebp
  int v5; // eax
  void *v6; // eax
  int i; // ebp
  int v8; // eax
  bool v9; // zf
  int v10; // ebp
  int v11; // eax
  int v12; // ebp
  int v13; // eax
  int v14; // ebp
  int v15; // eax
  int v16; // eax
  int v17; // ebp
  int j; // ebp

  if ( a1 == 0 || a2 == 0 )
    return;
  v4 = a3;
  if ( ((unsigned __int16)a3 & (unsigned __int16)*(_DWORD *)(a2 + 184) & 0x4000) != 0 )
  {
    if ( a4 == -1 )
    {
      for ( i = 0; i < *(_DWORD *)(a2 + 48); ++i )
        png_free_data(a1, a2, a3: 0x4000, a4: i);
      png_free(a1, pMem: *(void **)(a2 + 56));
      *(_DWORD *)(a2 + 56) = 0;
      *(_DWORD *)(a2 + 48) = 0;
    }
    else
    {
      v5 = *(_DWORD *)(a2 + 56);
      if ( v5 == 0 )
        goto LABEL_12;
      v6 = *(void **)(v5 + 16 * a4 + 4);
      if ( v6 != nullptr )
      {
        png_free(a1, pMem: v6);
        *(_DWORD *)(*(_DWORD *)(a2 + 56) + 16 * a4 + 4) = 0;
      }
    }
    v4 = a3;
  }
LABEL_12:
  if ( (v4 & *(_DWORD *)(a2 + 184) & 0x2000) != 0 )
  {
    png_free(a1, pMem: *(void **)(a2 + 76));
    *(_DWORD *)(a2 + 8) &= ~0x10u;
    *(_DWORD *)(a2 + 76) = 0;
  }
  v8 = v4 & *(_DWORD *)(a2 + 184);
  if ( (v8 & 0x100) != 0 )
    *(_DWORD *)(a2 + 8) &= ~0x4000u;
  if ( (v8 & 0x80u) != 0 )
  {
    png_free(a1, pMem: *(void **)(a2 + 160));
    png_free(a1, pMem: *(void **)(a2 + 172));
    v9 = *(_DWORD *)(a2 + 176) == 0;
    *(_DWORD *)(a2 + 160) = 0;
    *(_DWORD *)(a2 + 172) = 0;
    if ( !v9 )
    {
      v10 = 0;
      if ( *(_BYTE *)(a2 + 181) != 0 )
      {
        do
        {
          png_free(a1, pMem: *(void **)(*(_DWORD *)(a2 + 176) + 4 * v10));
          *(_DWORD *)(*(_DWORD *)(a2 + 176) + 4 * v10++) = 0;
        }
        while ( v10 < *(unsigned __int8 *)(a2 + 181) );
      }
      png_free(a1, pMem: *(void **)(a2 + 176));
      v4 = a3;
      *(_DWORD *)(a2 + 176) = 0;
    }
    *(_DWORD *)(a2 + 8) &= ~0x400u;
  }
  if ( ((unsigned __int8)v4 & *(_BYTE *)(a2 + 184) & 0x10) != 0 )
  {
    png_free(a1, pMem: *(void **)(a2 + 196));
    png_free(a1, pMem: *(void **)(a2 + 200));
    *(_DWORD *)(a2 + 8) &= ~0x1000u;
    *(_DWORD *)(a2 + 196) = 0;
    *(_DWORD *)(a2 + 200) = 0;
  }
  if ( ((unsigned __int8)v4 & *(_BYTE *)(a2 + 184) & 0x20) != 0 )
  {
    if ( a4 == -1 )
    {
      v13 = *(_DWORD *)(a2 + 216);
      if ( v13 != 0 )
      {
        v14 = 0;
        if ( v13 > 0 )
        {
          do
            png_free_data(a1, a2, a3: 32, a4: v14++);
          while ( v14 < *(_DWORD *)(a2 + 216) );
        }
        png_free(a1, pMem: *(void **)(a2 + 212));
        v4 = a3;
        *(_DWORD *)(a2 + 212) = 0;
        *(_DWORD *)(a2 + 216) = 0;
      }
      *(_DWORD *)(a2 + 8) &= ~0x2000u;
    }
    else
    {
      v11 = *(_DWORD *)(a2 + 212);
      if ( v11 != 0 )
      {
        v12 = 16 * a4;
        png_free(a1, pMem: *(void **)(v11 + 16 * a4));
        png_free(a1, pMem: *(void **)(*(_DWORD *)(a2 + 212) + 16 * a4 + 8));
        *(_DWORD *)(*(_DWORD *)(a2 + 212) + v12) = 0;
        *(_DWORD *)(*(_DWORD *)(a2 + 212) + v12 + 8) = 0;
        v4 = a3;
      }
    }
  }
  if ( *(_DWORD *)(a1 + 624) != 0 )
  {
    png_free(a1, pMem: *(void **)(a1 + 624));
    *(_DWORD *)(a1 + 624) = 0;
  }
  if ( (v4 & *(_DWORD *)(a2 + 184) & 0x200) == 0 )
    goto LABEL_44;
  if ( a4 == -1 )
  {
    v16 = *(_DWORD *)(a2 + 192);
    if ( v16 != 0 )
    {
      v17 = 0;
      if ( v16 > 0 )
      {
        do
          png_free_data(a1, a2, a3: 512, a4: v17++);
        while ( v17 < *(_DWORD *)(a2 + 192) );
      }
      png_free(a1, pMem: *(void **)(a2 + 188));
      *(_DWORD *)(a2 + 188) = 0;
      *(_DWORD *)(a2 + 192) = 0;
      goto LABEL_43;
    }
  }
  else
  {
    v15 = *(_DWORD *)(a2 + 188);
    if ( v15 != 0 )
    {
      png_free(a1, pMem: *(void **)(v15 + 20 * a4 + 8));
      *(_DWORD *)(*(_DWORD *)(a2 + 188) + 20 * a4 + 8) = 0;
LABEL_43:
      v4 = a3;
    }
  }
LABEL_44:
  if ( ((unsigned __int8)v4 & *(_BYTE *)(a2 + 184) & 8) != 0 )
  {
    png_free(a1, pMem: *(void **)(a2 + 124));
    *(_DWORD *)(a2 + 8) &= ~0x40u;
    *(_DWORD *)(a2 + 124) = 0;
  }
  if ( (v4 & *(_DWORD *)(a2 + 184) & 0x1000) != 0 )
  {
    png_zfree(a1, pMem: *(void **)(a2 + 16));
    *(_DWORD *)(a2 + 8) &= ~8u;
    *(_DWORD *)(a2 + 16) = 0;
    *(_WORD *)(a2 + 20) = 0;
  }
  if ( ((unsigned __int8)v4 & *(_BYTE *)(a2 + 184) & 0x40) != 0 )
  {
    if ( *(_DWORD *)(a2 + 248) != 0 )
    {
      for ( j = 0; j < *(_DWORD *)(a2 + 4); ++j )
      {
        png_free(a1, pMem: *(void **)(*(_DWORD *)(a2 + 248) + 4 * j));
        *(_DWORD *)(*(_DWORD *)(a2 + 248) + 4 * j) = 0;
      }
      png_free(a1, pMem: *(void **)(a2 + 248));
      v4 = a3;
      *(_DWORD *)(a2 + 248) = 0;
    }
    *(_DWORD *)(a2 + 8) &= ~0x8000u;
  }
  if ( a4 != -1 )
    v4 &= 0xFFFFBDDF;
  *(_DWORD *)(a2 + 184) &= ~v4;
}

//------------------------------------------------------------------------------
// Address: 0x101BAEC0
// Name: _png_info_destroy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl png_info_destroy(int a1, int a2)
{
  png_free_data(a1, a2, a3: 0x7FFF, a4: -1);
  if ( *(_DWORD *)(a1 + 544) != 0 )
  {
    png_free(a1, pMem: *(void **)(a1 + 548));
    *(_DWORD *)(a1 + 548) = 0;
    *(_DWORD *)(a1 + 544) = 0;
  }
  png_info_init_3(a1: (void **)&a2, a2: 0x120u);
}

//------------------------------------------------------------------------------
// Address: 0x101BAF20
// Name: _png_handle_as_unknown
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl png_handle_as_unknown(int a1, const void *a2)
{
  int v3; // ebx
  unsigned __int8 *v4; // edi

  if ( a1 == 0 && a2 == nullptr || *(int *)(a1 + 544) <= 0 )
    return 0;
  v3 = *(_DWORD *)(a1 + 544);
  v4 = (unsigned __int8 *)(5 * v3 + *(_DWORD *)(a1 + 548) - 5);
  if ( v3 == 0 )
    return 0;
  while ( memcmp(a2, v4, 4u) != 0 )
  {
    --v3;
    v4 -= 5;
    if ( v3 == 0 )
      return 0;
  }
  return v4[4];
}

//------------------------------------------------------------------------------
// Address: 0x101BB010
// Name: _png_create_info_struct
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl png_create_info_struct(unsigned __int8 *a1)
{
  unsigned __int8 *result; // eax

  result = a1;
  if ( a1 != nullptr )
  {
    result = png_create_struct_2(
               a1: 2,
               a2: *((int (__cdecl **)(char *, unsigned int))a1 + 145),
               a3: *((_DWORD *)a1 + 144));
    a1 = result;
    if ( result != nullptr )
    {
      png_info_init_3((void **)&a1, a2: 0x120u);
      return a1;
    }
  }
  return result;
}
