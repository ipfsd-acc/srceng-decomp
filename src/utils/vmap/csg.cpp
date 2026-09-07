// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vmap/csg.cpp
// Functions: 12
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004163E0
// Name: struct bspbrush_t __near * SubtractBrush(struct bspbrush_t __near *,struct bspbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
bspbrush_t *__cdecl SubtractBrush(bspbrush_t *a, bspbrush_t *b)
{
  bspbrush_t *v2; // esi
  int v3; // edi
  side_t *sides; // ebx
  bspbrush_t *back; // [esp+Ch] [ebp-Ch] BYREF
  bspbrush_t *front; // [esp+10h] [ebp-8h] BYREF
  bspbrush_t *out; // [esp+14h] [ebp-4h]

  v2 = a;
  v3 = 0;
  out = nullptr;
  if ( b->numsides <= 0 )
  {
LABEL_9:
    if ( v2 != nullptr )
    {
      FreeBrush(brushes: v2);
      return out;
    }
  }
  else
  {
    sides = b->sides;
    while ( v2 != nullptr )
    {
      SplitBrush(brush: v2, planenum: sides->planenum, &front, &back);
      if ( v2 != a )
        FreeBrush(brushes: v2);
      if ( front != nullptr )
      {
        front->next = out;
        out = front;
      }
      v2 = back;
      ++v3;
      ++sides;
      if ( v3 >= b->numsides )
        goto LABEL_9;
    }
  }
  FreeBrushList(brushes: out);
  return a;
}

//------------------------------------------------------------------------------
// Address: 0x00416480
// Name: struct bspbrush_t __near * IntersectBrush(struct bspbrush_t __near *,struct bspbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
bspbrush_t *__cdecl IntersectBrush(bspbrush_t *a, bspbrush_t *b)
{
  bspbrush_t *v2; // esi
  int v3; // edi
  side_t *sides; // ebx
  bspbrush_t *back; // [esp+Ch] [ebp-8h] BYREF
  bspbrush_t *front; // [esp+10h] [ebp-4h] BYREF

  v2 = a;
  v3 = 0;
  if ( b->numsides <= 0 )
    return nullptr;
  sides = b->sides;
  do
  {
    if ( v2 == nullptr )
      break;
    SplitBrush(brush: v2, planenum: sides->planenum, &front, &back);
    if ( v2 != a )
      FreeBrush(brushes: v2);
    if ( front != nullptr )
      FreeBrush(brushes: front);
    v2 = back;
    ++v3;
    ++sides;
  }
  while ( v3 < b->numsides );
  if ( v2 == a || v2 == nullptr )
    return nullptr;
  v2->next = nullptr;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00416510
// Name: int BrushesDisjoint(struct bspbrush_t __near *,struct bspbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl BrushesDisjoint(bspbrush_t *a, bspbrush_t *b)
{
  bspbrush_t *v2; // ebx
  int v3; // ecx
  Vector *p_mins; // edx
  Vector *p_maxs; // eax
  int numsides; // eax
  int v7; // edx
  side_t *j; // edi
  int v9; // ecx
  side_t *sides; // eax
  int v12; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v2 = b;
  v3 = 0;
  p_mins = &b->mins;
  p_maxs = &a->maxs;
  while ( p_maxs[-1].x < *(float *)((char *)&p_maxs->x + (char *)b - (char *)a) && p_mins->x < p_maxs->x )
  {
    ++v3;
    p_maxs = (Vector *)((char *)p_maxs + 4);
    p_mins = (Vector *)((char *)p_mins + 4);
    if ( v3 >= 3 )
    {
      numsides = a->numsides;
      i = 0;
      v12 = numsides;
      if ( numsides <= 0 )
        return 0;
      v7 = b->numsides;
      for ( j = a->sides; ; ++j )
      {
        v9 = 0;
        if ( v7 > 0 )
          break;
LABEL_12:
        if ( ++i >= numsides )
          return 0;
      }
      sides = v2->sides;
      while ( j->planenum != (sides->planenum ^ 1) )
      {
        ++v9;
        ++sides;
        if ( v9 >= v7 )
        {
          v2 = b;
          numsides = v12;
          goto LABEL_12;
        }
      }
      return 1;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004165B0
// Name: struct bspbrush_t __near * ClipBrushToBox(struct bspbrush_t __near *,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bspbrush_t *__cdecl ClipBrushToBox(bspbrush_t *brush, const Vector *clipmins, const Vector *clipmaxs)
{
  const Vector *v3; // esi
  int v4; // ecx
  int v5; // edi
  bspbrush_t *result; // eax
  int v7; // esi
  int *p_texinfo; // edx
  unsigned int v9; // ecx
  bspbrush_t *front; // [esp+1Ch] [ebp-8h] BYREF
  bspbrush_t *back; // [esp+20h] [ebp-4h] BYREF

  v3 = clipmaxs;
  v4 = 20 - (_DWORD)clipmaxs;
  v5 = 0;
  result = brush;
  while ( 1 )
  {
    if ( *(float *)((char *)&result->id + (_DWORD)v3 + v4) > v3->x )
    {
      SplitBrush(
        brush: result,
        planenum: *(_DWORD *)((char *)&v3->x + (char *)maxplanenums - (char *)clipmaxs),
        &front,
        &back);
      if ( front != nullptr )
        FreeBrush(brushes: front);
      result = back;
      if ( back == nullptr )
        return nullptr;
    }
    if ( *(float *)((char *)&v3->x + (char *)clipmins - (char *)clipmaxs) > *(float *)((char *)&result->id
                                                                                     + (_DWORD)v3
                                                                                     + 8
                                                                                     - (_DWORD)clipmaxs) )
    {
      SplitBrush(
        brush: result,
        planenum: *(_DWORD *)((char *)&v3->x + (char *)minplanenums - (char *)clipmaxs),
        &front,
        &back);
      if ( back != nullptr )
        FreeBrush(brushes: back);
      result = front;
      if ( front == nullptr )
        return nullptr;
    }
    ++v5;
    v3 = (const Vector *)((char *)v3 + 4);
    if ( v5 >= 2 )
      break;
    v4 = 20 - (_DWORD)clipmaxs;
  }
  v7 = 0;
  if ( result->numsides > 0 )
  {
    p_texinfo = &result->sides[0].texinfo;
    do
    {
      v9 = *(p_texinfo - 1) & 0xFFFFFFFE;
      if ( v9 == maxplanenums[0] || v9 == dword_7867C8 || v9 == minplanenums[0] || v9 == dword_7867BC )
      {
        *p_texinfo = -1;
        p_texinfo[6] = 0;
      }
      ++v7;
      p_texinfo += 25;
    }
    while ( v7 < result->numsides );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004166E0
// Name: CreateClippedBrush
// Source: json
//------------------------------------------------------------------------------
bspbrush_t *__cdecl CreateClippedBrush(mapbrush_t *mb, const Vector *clipmins, const Vector *clipmaxs)
{
  mapbrush_t *v3; // edi
  int numsides; // ebx
  const Vector *v6; // ecx
  Vector *p_maxs; // eax
  int i; // edx
  bspbrush_t *v9; // esi
  winding_t **p_winding; // edi

  v3 = mb;
  numsides = mb->numsides;
  if ( numsides == 0 )
    return nullptr;
  v6 = clipmins;
  p_maxs = &mb->maxs;
  for ( i = 0; i < 3; ++i )
  {
    if ( p_maxs[-1].x >= *(float *)((char *)&v6->x + (char *)clipmaxs - (char *)clipmins) || v6->x >= p_maxs->x )
      return nullptr;
    p_maxs = (Vector *)((char *)p_maxs + 4);
    v6 = (const Vector *)((char *)v6 + 4);
  }
  v9 = AllocBrush(numsides);
  v9->original = mb;
  v9->numsides = numsides;
  memcpy(dst: (unsigned __int8 *)v9->sides, src: (unsigned __int8 *)mb->original_sides, count: 100 * numsides);
  if ( numsides > 0 )
  {
    p_winding = &v9->sides[0].winding;
    do
    {
      if ( *p_winding != nullptr )
        *p_winding = CopyWinding(w: *p_winding);
      if ( ((unsigned int)p_winding[3] & 0x100) != 0 )
        p_winding[4] = (winding_t *)1;
      p_winding += 25;
      --numsides;
    }
    while ( numsides != 0 );
    v3 = mb;
  }
  v9->mins.x = v3->mins.x;
  v9->mins.y = v3->mins.y;
  v9->mins.z = v3->mins.z;
  v9->maxs = mb->maxs;
  return ClipBrushToBox(brush: v9, clipmins, clipmaxs);
}

//------------------------------------------------------------------------------
// Address: 0x004167E0
// Name: ComputeBoundingPlanes
// Source: json
//------------------------------------------------------------------------------
void __usercall ComputeBoundingPlanes(const Vector *clipmins@<eax>, const Vector *clipmaxs@<ecx>)
{
  const Vector *v2; // esi
  int v3; // edi
  int v4; // ebx
  int FloatPlane; // eax
  int v6; // ecx
  int v7; // eax
  Vector normal; // [esp+10h] [ebp-18h] BYREF
  int v9; // [esp+1Ch] [ebp-Ch]
  int v10; // [esp+20h] [ebp-8h]
  int i; // [esp+24h] [ebp-4h]

  v2 = clipmaxs;
  v10 = (char *)clipmins - (char *)clipmaxs;
  v3 = (char *)&normal - (char *)clipmaxs;
  v4 = (char *)maxplanenums - (char *)clipmaxs;
  v9 = (char *)minplanenums - (char *)clipmaxs;
  for ( i = 2; i != 0; --i )
  {
    memset(&normal, 0, sizeof(normal));
    *(float *)((char *)&v2->x + v3) = 1.0;
    FloatPlane = FindFloatPlane(&normal, dist: v2->x);
    v6 = v10;
    *(_DWORD *)((char *)&v2->x + v4) = FloatPlane;
    v7 = FindFloatPlane(&normal, dist: *(float *)((char *)&v2->x + v6));
    *(_DWORD *)((char *)&v2->x + v9) = v7;
    v2 = (const Vector *)((char *)v2 + 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416880
// Name: struct bspbrush_t __near * MakeBspBrushList(int,int,class Vector const __near &,class Vector const __near &,int)
// Source: json
//------------------------------------------------------------------------------
bspbrush_t *__cdecl MakeBspBrushList(
        int startbrush,
        int endbrush,
        const Vector *clipmins,
        const Vector *clipmaxs,
        int detailScreen)
{
  mapbrush_t *v5; // esi
  bspbrush_t *ClippedBrush; // eax
  bspbrush_t *pBrushList; // [esp+8h] [ebp-4h]
  int startbrusha; // [esp+14h] [ebp+8h]

  ComputeBoundingPlanes(clipmins, clipmaxs);
  pBrushList = nullptr;
  if ( startbrush >= endbrush )
    return nullptr;
  v5 = &mapbrushes[startbrush];
  startbrusha = endbrush - startbrush;
  do
  {
    if ( detailScreen == 0 || (detailScreen == 1) == ((v5->contents & 0x8000000) != 0) )
    {
      ClippedBrush = CreateClippedBrush(mb: v5, clipmins, clipmaxs);
      if ( ClippedBrush != nullptr )
      {
        ClippedBrush->next = pBrushList;
        pBrushList = ClippedBrush;
      }
    }
    ++v5;
    --startbrusha;
  }
  while ( startbrusha != 0 );
  return pBrushList;
}

//------------------------------------------------------------------------------
// Address: 0x00416910
// Name: struct bspbrush_t __near * MakeBspBrushList(struct mapbrush_t __near * __near *,int,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bspbrush_t *__cdecl MakeBspBrushList(
        mapbrush_t **pBrushes,
        int nBrushCount,
        const Vector *clipmins,
        const Vector *clipmaxs)
{
  bspbrush_t *result; // eax
  int v5; // esi
  bspbrush_t *ClippedBrush; // eax
  bspbrush_t *pBrushList; // [esp+Ch] [ebp-4h]

  ComputeBoundingPlanes(clipmins, clipmaxs);
  result = nullptr;
  v5 = 0;
  pBrushList = nullptr;
  if ( nBrushCount > 0 )
  {
    do
    {
      ClippedBrush = CreateClippedBrush(mb: pBrushes[v5], clipmins, clipmaxs);
      if ( ClippedBrush != nullptr )
      {
        ClippedBrush->next = pBrushList;
        pBrushList = ClippedBrush;
      }
      ++v5;
    }
    while ( v5 < nBrushCount );
    return pBrushList;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00416960
// Name: void PrintBrushContentsToString(int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrintBrushContentsToString(int contents, char *pOut, unsigned int nMaxChars)
{
  *pOut = 0;
  if ( (contents & 1) != 0 )
    V_strncat(pDest: pOut, pSrc: "CONTENTS_SOLID ", destBufferSize: nMaxChars, max_chars_to_copy: -1);
  if ( (contents & 2) != 0 )
    V_strncat(pDest: pOut, pSrc: "CONTENTS_WINDOW ", destBufferSize: nMaxChars, max_chars_to_copy: -1);
  if ( (contents & 4) != 0 )
    V_strncat(pDest: pOut, pSrc: "CONTENTS_AUX ", destBufferSize: nMaxChars, max_chars_to_copy: -1);
  if ( (contents & 8) != 0 )
    V_strncat(pDest: pOut, pSrc: "CONTENTS_GRATE ", destBufferSize: nMaxChars, max_chars_to_copy: -1);
  if ( (contents & 0x10) != 0 )
    V_strncat(pDest: pOut, pSrc: "CONTENTS_SLIME ", destBufferSize: nMaxChars, max_chars_to_copy: -1);
  if ( (contents & 0x20) != 0 )
    V_strncat(pDest: pOut, pSrc: "CONTENTS_WATER ", destBufferSize: nMaxChars, max_chars_to_copy: -1);
  if ( (contents & 0x40) != 0 )
    V_strncat(pDest: pOut, pSrc: "CONTENTS_BLOCKLOS ", destBufferSize: nMaxChars, max_chars_to_copy: -1);
  if ( (contents & 0x80u) != 0 )
    V_strncat(pDest: pOut, pSrc: "CONTENTS_OPAQUE ", destBufferSize: nMaxChars, max_chars_to_copy: -1);
  if ( (contents & 0x100) != 0 )
    V_strncat(pDest: pOut, pSrc: "CONTENTS_TESTFOGVOLUME ", destBufferSize: nMaxChars, max_chars_to_copy: -1);
  if ( (contents & 0x4000) != 0 )
    V_strncat(pDest: pOut, pSrc: "CONTENTS_MOVEABLE ", destBufferSize: nMaxChars, max_chars_to_copy: -1);
  if ( (contents & 0x8000) != 0 )
    V_strncat(pDest: pOut, pSrc: "CONTENTS_AREAPORTAL ", destBufferSize: nMaxChars, max_chars_to_copy: -1);
  if ( (contents & 0x10000) != 0 )
    V_strncat(pDest: pOut, pSrc: "CONTENTS_PLAYERCLIP ", destBufferSize: nMaxChars, max_chars_to_copy: -1);
  if ( (contents & 0x20000) != 0 )
    V_strncat(pDest: pOut, pSrc: "CONTENTS_MONSTERCLIP ", destBufferSize: nMaxChars, max_chars_to_copy: -1);
  if ( ((unsigned int)&unk_1000000 & contents) != 0 )
    V_strncat(pDest: pOut, pSrc: "CONTENTS_ORIGIN ", destBufferSize: nMaxChars, max_chars_to_copy: -1);
  if ( ((unsigned int)&unk_2000000 & contents) != 0 )
    V_strncat(pDest: pOut, pSrc: "CONTENTS_MONSTER ", destBufferSize: nMaxChars, max_chars_to_copy: -1);
  if ( ((unsigned int)&dfaces_hdr[54421].m_NumPrims & contents) != 0 )
    V_strncat(pDest: pOut, pSrc: "CONTENTS_DEBRIS ", destBufferSize: nMaxChars, max_chars_to_copy: -1);
  if ( (contents & 0x8000000) != 0 )
    V_strncat(pDest: pOut, pSrc: "CONTENTS_DETAIL ", destBufferSize: nMaxChars, max_chars_to_copy: -1);
  if ( (contents & 0x10000000) != 0 )
    V_strncat(pDest: pOut, pSrc: "CONTENTS_TRANSLUCENT ", destBufferSize: nMaxChars, max_chars_to_copy: -1);
  if ( (contents & 0x20000000) != 0 )
    V_strncat(pDest: pOut, pSrc: "CONTENTS_LADDER ", destBufferSize: nMaxChars, max_chars_to_copy: -1);
  if ( (contents & 0x40000000) != 0 )
    V_strncat(pDest: pOut, pSrc: "CONTENTS_HITBOX ", destBufferSize: nMaxChars, max_chars_to_copy: -1);
}

//------------------------------------------------------------------------------
// Address: 0x00416B60
// Name: struct bspbrush_t __near * ChopBrushes(struct bspbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
bspbrush_t *__cdecl ChopBrushes(bspbrush_t *head)
{
  bspbrush_t *v1; // esi
  int v2; // eax
  bspbrush_t *next; // eax
  bspbrush_t *v4; // ebx
  int contents; // eax
  bspbrush_t *v6; // edi
  int v7; // ecx
  bspbrush_t *v8; // eax
  int v9; // ecx
  int v10; // eax
  bspbrush_t *v11; // eax
  int v12; // ecx
  bspbrush_t *v13; // eax
  bspbrush_t *v14; // ebx
  bspbrush_t *v15; // edi
  bspbrush_t *v16; // edi
  bspbrush_t *v17; // eax
  bspbrush_t *v18; // edx
  bspbrush_t *v19; // ecx
  bspbrush_t *v20; // ebx
  bspbrush_t *v21; // eax
  bspbrush_t *v22; // edi
  bspbrush_t *v23; // edx
  bspbrush_t *v24; // eax
  bspbrush_t *v25; // ecx
  bspbrush_t *v26; // edi
  bspbrush_t *v27; // eax
  bspbrush_t *v28; // esi
  int v30; // eax
  bspbrush_t *v31; // [esp+Ch] [ebp-14h]
  bspbrush_t *keep; // [esp+10h] [ebp-10h]
  bspbrush_t *tail; // [esp+14h] [ebp-Ch]
  int c1; // [esp+18h] [ebp-8h]
  int c2; // [esp+1Ch] [ebp-4h]
  bspbrush_t *sub; // [esp+28h] [ebp+8h]
  bspbrush_t *suba; // [esp+28h] [ebp+8h]

  qprintf(format: "---- ChopBrushes ----\n");
  v1 = head;
  v2 = CountBrushList(brushes: head);
  qprintf(format: "original brushes: %i\n", v2);
  keep = nullptr;
  if ( head == nullptr )
    return nullptr;
newlist:
  next = v1->next;
  for ( tail = v1; next != nullptr; next = next->next )
    tail = next;
  while ( v1 != nullptr )
  {
    v4 = v1->next;
    v31 = v4;
    if ( v4 != nullptr )
    {
      while ( 1 )
      {
        if ( BrushesDisjoint(a: v1, b: v4) == 0 )
        {
          sub = nullptr;
          c1 = 999999;
          c2 = 999999;
          contents = v1->original->contents;
          v6 = nullptr;
          if ( (contents & 0x30) != 0 && (v4->original->contents & 0x8000) != 0
            || (((v7 = v4->original->contents) & 0x8000000) == 0 || (contents & 0x8000000) != 0)
            && ((v7 & 1) != 0 || (v7 & 0xA) != 0 && (contents & 0xA) != 0) )
          {
            v8 = SubtractBrush(a: v1, b: v4);
            sub = v8;
            if ( v8 == v1 )
              goto LABEL_37;
            if ( v8 == nullptr )
            {
              v13 = v1;
              v14 = nullptr;
              do
              {
                v15 = v13->next;
                if ( v13 == v1 )
                {
                  FreeBrush(brushes: v13);
                }
                else
                {
                  v13->next = v14;
                  v14 = v13;
                }
                v13 = v15;
              }
              while ( v15 != nullptr );
              v1 = v14;
              goto LABEL_73;
            }
            c1 = CountBrushList(brushes: v8);
          }
          v9 = v4->original->contents;
          if ( (v9 & 0x30) != 0 && (v1->original->contents & 0x8000) != 0
            || (((v10 = v1->original->contents) & 0x8000000) == 0 || (v9 & 0x8000000) != 0)
            && ((v10 & 1) != 0 || (v10 & 0xA) != 0 && (v9 & 0xA) != 0) )
          {
            v11 = SubtractBrush(a: v4, b: v1);
            v6 = v11;
            if ( v11 == v4 )
              goto LABEL_37;
            if ( v11 == nullptr )
            {
              FreeBrushList(brushes: sub);
              suba = nullptr;
              do
              {
                v16 = v1->next;
                if ( v1 == v4 )
                {
                  FreeBrush(brushes: v1);
                }
                else
                {
                  v1->next = suba;
                  suba = v1;
                }
                v1 = v16;
              }
              while ( v16 != nullptr );
              v1 = suba;
              goto LABEL_73;
            }
            c2 = CountBrushList(brushes: v11);
          }
          if ( sub != nullptr || v6 != nullptr )
          {
            if ( c1 <= 1
              || c2 <= 1
              || ((v12 = v1->original->contents) & v4->original->contents & 0x8000000) != 0
              || ((v12 | v4->original->contents) & 0x8000) != 0 )
            {
              if ( c1 >= c2 )
              {
                if ( sub != nullptr )
                  FreeBrushList(brushes: sub);
                v23 = tail;
                v24 = v6;
                if ( v6 != nullptr )
                {
                  do
                  {
                    v25 = v24->next;
                    v24->next = nullptr;
                    v23->next = v24;
                    v23 = v24;
                    v24 = v25;
                  }
                  while ( v25 != nullptr );
                }
                v26 = nullptr;
                v27 = v1;
                do
                {
                  v28 = v27->next;
                  if ( v27 == v4 )
                  {
                    FreeBrush(brushes: v27);
                  }
                  else
                  {
                    v27->next = v26;
                    v26 = v27;
                  }
                  v27 = v28;
                }
                while ( v28 != nullptr );
                v1 = v26;
              }
              else
              {
                if ( v6 != nullptr )
                  FreeBrushList(brushes: v6);
                v17 = sub;
                v18 = tail;
                if ( sub != nullptr )
                {
                  do
                  {
                    v19 = v17->next;
                    v17->next = nullptr;
                    v18->next = v17;
                    v18 = v17;
                    v17 = v19;
                  }
                  while ( v19 != nullptr );
                }
                v20 = nullptr;
                v21 = v1;
                do
                {
                  v22 = v21->next;
                  if ( v21 == v1 )
                  {
                    FreeBrush(brushes: v21);
                  }
                  else
                  {
                    v21->next = v20;
                    v20 = v21;
                  }
                  v21 = v22;
                }
                while ( v22 != nullptr );
                v1 = v20;
              }
LABEL_73:
              if ( v1 == nullptr )
                return nullptr;
              goto newlist;
            }
            if ( v6 != nullptr )
              FreeBrushList(brushes: v6);
            if ( sub != nullptr )
              FreeBrushList(brushes: sub);
          }
        }
LABEL_37:
        v4 = v4->next;
        if ( v4 == nullptr )
        {
          v4 = v31;
          break;
        }
      }
    }
    v1->next = keep;
    keep = v1;
    v1 = v4;
  }
  v30 = CountBrushList(brushes: keep);
  qprintf(format: "output brushes: %i\n", v30);
  return keep;
}

//------------------------------------------------------------------------------
// Address: 0x00416E90
// Name: void CopyMatchingTexinfos(struct side_t __near *,int,struct bspbrush_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CopyMatchingTexinfos(side_t *pDestSides, int numDestSides, const bspbrush_t *pSource)
{
  mapbrush_t *original; // eax
  const side_t *original_sides; // ecx
  float v6; // xmm1_4
  int v7; // ebx
  float v8; // xmm0_4
  int texinfo; // eax
  side_t *v10; // ecx
  dtexdata_t *TexData; // eax
  const char *String; // eax
  int numsides; // [esp+0h] [ebp-Ch]
  int v14; // [esp+4h] [ebp-8h]
  const side_t *pBestSide; // [esp+8h] [ebp-4h]

  if ( numDestSides <= 0 )
    return;
  v14 = numDestSides;
  do
  {
    original = pSource->original;
    original_sides = original->original_sides;
    v6 = -1.0;
    v7 = 0;
    pBestSide = nullptr;
    numsides = original->numsides;
    if ( numsides <= 0 )
    {
LABEL_15:
      TexData = GetTexData(index: ::texinfo.m_Memory.m_pMemory[pDestSides->texinfo].texdata);
      String = TexDataStringTable_GetString(stringID: TexData->nameStringTableID);
      _Msg(a1: "Found no matching plane for %s\n", String);
      goto LABEL_16;
    }
    while ( original_sides->texinfo == -1 )
    {
LABEL_9:
      ++v7;
      ++original_sides;
      if ( v7 >= numsides )
        goto LABEL_12;
    }
    v8 = (float)((float)(*(&mapplanes.y + 6 * original_sides->planenum) * *(&mapplanes.y + 6 * pDestSides->planenum))
               + (float)(*(&mapplanes.x + 6 * pDestSides->planenum) * *(&mapplanes.x + 6 * original_sides->planenum)))
       + (float)(*(&mapplanes.z + 6 * original_sides->planenum) * *(&mapplanes.z + 6 * pDestSides->planenum));
    if ( v8 != 1.0 && pDestSides->planenum != original_sides->planenum )
    {
      if ( v8 > v6 )
      {
        pBestSide = original_sides;
        v6 = (float)((float)(*(&mapplanes.y + 6 * original_sides->planenum) * *(&mapplanes.y + 6 * pDestSides->planenum))
                   + (float)(*(&mapplanes.x + 6 * pDestSides->planenum) * *(&mapplanes.x + 6 * original_sides->planenum)))
           + (float)(*(&mapplanes.z + 6 * original_sides->planenum) * *(&mapplanes.z + 6 * pDestSides->planenum));
      }
      goto LABEL_9;
    }
    pBestSide = original_sides;
LABEL_12:
    if ( pBestSide == nullptr )
      goto LABEL_15;
    texinfo = pBestSide->texinfo;
    pDestSides->texinfo = texinfo;
    v10 = pDestSides->original;
    if ( v10 != nullptr )
      v10->texinfo = texinfo;
LABEL_16:
    ++pDestSides;
    --v14;
  }
  while ( v14 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x00416FC0
// Name: void FixupAreaportalWaterBrushes(struct bspbrush_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FixupAreaportalWaterBrushes(bspbrush_t *pList)
{
  bspbrush_t *i; // edi
  bspbrush_t *j; // esi
  int contents; // eax
  bspbrush_t *v4; // eax

  for ( i = pList; i != nullptr; i = i->next )
  {
    if ( (i->original->contents & 0x8000) != 0 )
    {
      for ( j = pList; j != nullptr; j = j->next )
      {
        contents = j->original->contents;
        if ( (contents & 0x8000) == 0 && (contents & 0x30) != 0 && BrushesDisjoint(a: i, b: j) == 0 )
        {
          v4 = IntersectBrush(a: i, b: j);
          if ( v4 != nullptr )
          {
            FreeBrush(brushes: v4);
            i->original->contents |= j->original->contents;
            CopyMatchingTexinfos(pDestSides: i->sides, numDestSides: i->numsides, pSource: j);
            CopyMatchingTexinfos(
              pDestSides: i->original->original_sides,
              numDestSides: i->original->numsides,
              pSource: j);
          }
        }
      }
    }
  }
}
